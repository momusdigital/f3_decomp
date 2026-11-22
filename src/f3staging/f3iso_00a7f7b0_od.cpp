#include <new>
// src/f3staging/f3iso_00a7f7b0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a7f7b0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a7f7b0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a7f7b0 {
template <class T> struct A7PadSpu
{
    T storage;
    void operator=(T value) { storage = value; }
};

enum A7Status { A7Ok, A7HeuristicSampling, A7OutOfMemory, A7Unsolvable, A7Penetrating };
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct A7ThreadMemory
{
    virtual void* alignedAllocate(int alignment, int bytes, int memoryClass);
    virtual void alignedDeallocate(void* block);
    virtual void setStackArea(void* block, int bytes);
    virtual void releaseCachedMemory();
    virtual ~A7ThreadMemory();
    virtual void* onStackOverflow(int bytes);
    virtual void onStackUnderflow(void* block);

    __declspec(align(16)) void* memory;
    int referenceCount;
    __declspec(align(16)) char* current;
    void* previousStack;
    char* base;
    char* end;

    static A7ThreadMemory* getInstance()
    {
        return static_cast<A7ThreadMemory*>(TlsGetValue(DAT_010f3170));
    }

    void* allocateStack(int bytes)
    {
        const int actualBytes = (bytes + 16) & ~15;
        char* block = current;
        char* next = block + actualBytes;
        if (next <= end)
        {
            current = next;
            return block;
        }
        return onStackOverflow(actualBytes);
    }

    void deallocateStack(void* block)
    {
        current = static_cast<char*>(block);
        if (block == base)
            onStackUnderflow(block);
    }
};

struct A7Transform;
struct A7Vector
{
    __declspec(align(16)) float x;
    float y, z, w;

    void operator=(const A7Vector& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    void setAll(float v)
    {
        x = v;
        y = v;
        z = v;
        w = v;
    }

    void setNeg4(const A7Vector& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }

    void rotate(const A7Transform& t, const A7Vector& v);
    void transformPosition(const A7Transform& t, const A7Vector& v);
};

struct A7Transform
{
    A7Vector col0, col1, col2, translation;

    A7Transform& operator=(const A7Transform& other)
    {
        col0 = other.col0;
        col1 = other.col1;
        col2 = other.col2;
        translation = other.translation;
        return *this;
    }
};

inline void A7Vector::rotate(const A7Transform& t, const A7Vector& v)
{
    float vx = v.x, vy = v.y, vz = v.z;
    x = t.col0.x * vx + t.col1.x * vy + t.col2.x * vz;
    y = t.col0.y * vx + t.col1.y * vy + t.col2.y * vz;
    z = t.col0.z * vx + t.col1.z * vy + t.col2.z * vz;
    w = 0;
}

__forceinline void A7Vector::transformPosition(const A7Transform& t, const A7Vector& v)
{
    float vx = v.x, vy = v.y, vz = v.z;
    x = t.col0.x * vx + t.col1.x * vy + t.col2.x * vz + t.translation.x;
    y = t.col0.y * vx + t.col1.y * vy + t.col2.y * vz + t.translation.y;
    z = t.col0.z * vx + t.col1.z * vy + t.col2.z * vz + t.translation.z;
    w = 0;
}

struct A7Shape
{
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    unsigned long userData;
    unsigned int type;
    float radius;
};

struct A7CdVertex : A7Vector {};
struct A7Contact { A7Vector position, normal; };
struct A7GskOut { A7Vector normalInA, pointAinA; float distance; };
struct A7Edge;
struct A7Triangle;
struct A7Vertex { A7Vector position; A7CdVertex pointAinA, pointBinB; A7Edge* referee; };
struct A7Edge { A7Vertex* vertex; A7Edge* next; A7Edge* neighbour; A7Triangle* triangle; };
struct A7Triangle { A7Vector normal; A7Edge edges[3]; float distanceToOrigin; int state; };

struct A7WingedEdge
{
    float toleranceBorder, previousMinimumDistance;
    int numVertices, numFreeTriangles, numTriangles;
    A7Vertex vertices[55];
    A7Triangle* freeTriangles[100];
    A7Triangle triangles[100];

    void FUN_00a7fc60(const A7CdVertex* pointsA, const A7CdVertex* pointsB, const A7Vector* simplex);

    A7Vertex* allocateVertex()
    {
        A7Vertex* v = &vertices[numVertices++];
        v->referee = 0;
        return v;
    }
};

struct A7Penetration
{
    A7Transform aTb;
    A7Vector epsTol;
    A7PadSpu<float> epsTolSquared;
    A7PadSpu<const A7Shape*> shapeA;
    A7PadSpu<const A7Shape*> shapeB;
    A7PadSpu<int> backupTries;
    A7PadSpu<A7CdVertex*> pointsAinA;
    A7PadSpu<A7CdVertex*> pointsBinB;
    A7PadSpu<A7Vector*> simplex;
    A7PadSpu<int> simplexSize;

    void init(const A7Shape* a, const A7Shape* b, const A7Transform& t, float eps,
              A7CdVertex* ptsA, A7CdVertex* ptsB, A7Vector* pts, int size)
    {
        aTb = t;
        shapeA = a;
        shapeB = b;
        epsTol.setAll(eps);
        epsTolSquared = eps * eps;
        pointsAinA = ptsA;
        pointsBinB = ptsB;
        backupTries = 0;
        simplex = pts;
        simplexSize = size;
    }

    int FUN_00a7e7f0(A7GskOut& result, A7Status& status);
    void FUN_00a7e0c0(const A7Vector& normal, A7Vertex& v);
    int FUN_00a7e290(A7WingedEdge& hull, A7Triangle* triangle, A7Vertex* v, A7Status& status);
    void FUN_00a7e460(A7WingedEdge& hull, A7Triangle* triangle, A7GskOut& result);
};

struct A7Work
{
    A7Penetration util;
    A7CdVertex pointsAinA[4], pointsBinB[4];
    A7Vector simplex[4];
    const A7Shape* shapeB;
    A7Contact* pointOut;
    A7WingedEdge wingedEdge;
    A7Triangle* nearestTriangle;
};

void __cdecl FUN_00a99740(A7WingedEdge& first, A7WingedEdge& second, A7Vector& direction,
                          A7Triangle*& nearestFirst, A7Triangle*& nearestSecond);

// pdb: hkCalcMultiPenetrationDepth | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int __cdecl hkCalcMultiPenetrationDepth(const A7Transform& transformA, const A7Shape* shapeA,
                         const A7Shape** shapeBs, int count, const A7Transform& aTb,
                         A7Contact** pointsOut)
{
    A7Work* data = static_cast<A7Work*>(A7ThreadMemory::getInstance()->allocateStack(count * sizeof(A7Work)));
    A7Vector direction;
    {
        A7Status gjkStatii[2];
        int workId = 0;
        for (int i = 0; i < count; ++i)
        {
            A7Work& work = data[workId];
            work.shapeB = shapeBs[i];
            work.pointOut = pointsOut[i];
            work.util.init(shapeA, shapeBs[i], aTb, 0.0001f, work.pointsAinA, work.pointsBinB, work.simplex, 0);
            A7GskOut gjkOut;
            if (work.util.FUN_00a7e7f0(gjkOut, gjkStatii[0]) == 1)
            {
                --count;
                continue;
            }
            ++workId;
            work.wingedEdge.FUN_00a7fc60(work.pointsAinA, work.pointsBinB, work.simplex);
        }

        if (count > 2)
            count = 2;
        else if (count < 2)
        {
            A7ThreadMemory::getInstance()->deallocateStack(data);
            return 1;
        }

        gjkStatii[0] = A7Ok;
        gjkStatii[1] = A7Ok;
        bool canExpandAny;
        do
        {
            FUN_00a99740(data[0].wingedEdge, data[1].wingedEdge, direction,
                         data[0].nearestTriangle, data[1].nearestTriangle);
            canExpandAny = false;
            for (int w = 0; w < count; ++w)
            {
                A7Work& work = data[w];
                // The game skips expansion when the hull has fewer than 55 vertices.
                if (gjkStatii[w] == A7OutOfMemory || work.wingedEdge.numVertices < 55)
                    continue;
                A7Vertex* v = work.wingedEdge.allocateVertex();
                work.util.FUN_00a7e0c0(work.nearestTriangle->normal, *v);
                if (work.util.FUN_00a7e290(work.wingedEdge, work.nearestTriangle, v, gjkStatii[w]) == 1)
                {
                    if (gjkStatii[w] == A7Unsolvable)
                    {
                        A7ThreadMemory::getInstance()->deallocateStack(data);
                        return 1;
                    }
                }
                else
                    canExpandAny = true;
            }
        } while (canExpandAny);
    }

    A7Vector separatingNormal;
    separatingNormal.setNeg4(direction);
    float distance = separatingNormal.w;
    const float radiusA = shapeA->radius;
    for (int w = 0; w < count; ++w)
    {
        A7Work& work = data[w];
        A7GskOut output;
        work.util.FUN_00a7e460(work.wingedEdge, work.nearestTriangle, output);
        work.pointOut->normal.rotate(transformA, separatingNormal);
        A7Vector position;
        position.transformPosition(transformA, output.pointAinA);
        const float radiusB = work.shapeB->radius;
        work.pointOut->position = position;
        work.pointOut->normal.w = distance - radiusA - radiusB;
    }
    A7ThreadMemory::getInstance()->deallocateStack(data);
    return 0;
}
}   // namespace f3m_00a7f7b0
