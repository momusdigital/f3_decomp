#include <windows.h>
// src/f3staging/f3blk_00a40000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a564b0 (community match, verified in this file)
namespace f3m_00a564b0 {
struct hkBool
{
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
};

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;

    __forceinline void SetSub3(const Vec4& a, const Vec4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
    }

    __forceinline void SetCross(const Vec4& a, const Vec4& b)
    {
        x = a.y * b.z - a.z * b.y;
        y = a.z * b.x - a.x * b.z;
        z = a.x * b.y - a.y * b.x;
    }

    __forceinline float LengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline float Dot3(const Vec4& o) const { return x * o.x + y * o.y + z * o.z; }
};

// pdb: hkpTriangleUtil::isDegenerate | hkpTriangleUtil.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: a, b, c, tolerance
hkBool __cdecl FUN_00a564b0(const Vec4& a, const Vec4& b, const Vec4& c, float tolerance)
{
    Vec4 e1;
    e1.SetSub3(a, b);
    Vec4 e2;
    e2.SetSub3(a, c);
    Vec4 n;
    n.x = e1.y * e2.z - e1.z * e2.y;
    n.y = e1.z * e2.x - e1.x * e2.z;
    n.z = e1.x * e2.y - e1.y * e2.x;
    Vec4 f1;
    f1.SetSub3(b, a);
    Vec4 f2;
    f2.SetSub3(b, c);
    Vec4 m;
    m.SetCross(f1, f2);
    if (n.LengthSquared3() < tolerance || m.LengthSquared3() < tolerance)
        return true;
    Vec4 g1;
    g1.SetSub3(a, b);
    Vec4 g2;
    g2.SetSub3(c, b);
    float d = g2.Dot3(g1);
    float l1 = g1.LengthSquared3();
    float l2 = g2.LengthSquared3();
    float prod = l1 * l2;
    float dd = d * d;
    float diff = prod - dd;
    if (diff == 0.0f)
        return true;
    return false;
}
}   // namespace f3m_00a564b0

// @f3 0x00a50370 (community match, verified in this file)
#include <math.h>
namespace f3m_00a50370 {

namespace cru_a50370 {

typedef float Real;

struct __declspec(align(16)) Vec4
{
    Real x;
    Real y;
    Real z;
    Real w;

    inline Real& operator()(int i) { return (&x)[i]; }
    inline const Real& operator()(int i) const { return (&x)[i]; }

    inline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    inline void set(Real a, Real b, Real c, Real d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    inline void setAdd4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    inline void mul4(Real rs)
    {
        Real s = Real(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    inline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const Real nx = v1(1) * v2(2) - v1(2) * v2(1);
        const Real ny = v1(2) * v2(0) - v1(0) * v2(2);
        const Real nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    inline Real dot3(const Vec4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

    inline Real length3() const;
};

inline Real mathSqrt(Real r) { return sqrtf(r); }

inline Real Vec4::length3() const
{
    return mathSqrt((x * x) + (y * y) + (z * z));
}

struct Rotation
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;

    inline Vec4& getColumn(int i) { return (&m_col0)[i]; }
    inline const Vec4& getColumn(int i) const { return (&m_col0)[i]; }
};

template <class T> class PadSpu
{
public:
    __forceinline PadSpu() {}
    __forceinline void operator=(T e) { m_storage = e; }
    __forceinline T val() const { return m_storage; }

private:
    T m_storage;
};

}

float FUN_00954db0(float sina, float cosa);

namespace cru_a50370 {

__forceinline void inlineCalcRelativeAngle(const Vec4& twistAinWorld, const Vec4& twistBinWorld,
                                           const Vec4& planeAinWorld, const Vec4& planeBinWorld,
                                           Vec4& axisOut, PadSpu<Real>& angleOut, PadSpu<Real>& tauMaxOut)
{
    Vec4 twistWs;
    twistWs.setAdd4(twistBinWorld, twistAinWorld);
    const Real twistLength = twistWs.length3();
    if (twistLength > 1e-16f)
    {
        tauMaxOut = twistLength * 0.5f;
        twistWs.mul4(1.0f / twistLength);
    }
    else
    {
        tauMaxOut = 0.0f;
        twistWs = twistBinWorld;
    }

    Rotation frame;
    {
        Vec4& c0 = frame.getColumn(0);
        Vec4& c1 = frame.getColumn(1);
        Vec4& c2 = frame.getColumn(2);
        c0 = twistWs;
        c1.setCross(twistWs, planeBinWorld);
        c2.setCross(c1, c0);
    }

    Real d1 = frame.getColumn(1).dot3(planeAinWorld);
    Real d2 = frame.getColumn(2).dot3(planeAinWorld);
    Real currentAngle = FUN_00954db0(d1, d2);
    angleOut = currentAngle;
    axisOut = twistWs;
}

}

// pdb: hkInternalConstraintUtils_calcRelativeAngle | hkpInternalConstraintUtils.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: twistAxisAinWorld, twistAxisBinWorld, planeAxisAinWorld, planeAxisBinWorld, axisOut, angleOut
void __cdecl FUN_00a50370(const cru_a50370::Vec4& twistAinWorld, const cru_a50370::Vec4& twistBinWorld,
                          const cru_a50370::Vec4& planeAinWorld, const cru_a50370::Vec4& planeBinWorld,
                          cru_a50370::Vec4& axisOut, cru_a50370::PadSpu<float>& angleOut)
{
    cru_a50370::PadSpu<float> tauMax;
    cru_a50370::inlineCalcRelativeAngle(twistAinWorld, twistBinWorld, planeAinWorld, planeBinWorld, axisOut,
                                        angleOut, tauMax);
}
}   // namespace f3m_00a50370

// @f3 0x00a54420 (community match, verified in this file)
extern double DAT_00dfc230;
namespace f3m_00a54420 {
// hkpMoppLongRayVirtualMachine::queryLongRay (Havok 5.5): store the query context, then start the ray query on the
// MOPP tree: reset the hit state, take the early-out fraction from the collector, convert the ray end points into the
// code's integer space (offset removed, scaled by the code's float-to-int scale), keep the original ray input, and walk
// the tree from its root (chunk id -1 when the code starts with the chunk opcode).
namespace f3o_a54420 {

struct Vector4
{
    float x, y, z, w;
    Vector4& operator=(const Vector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
    void setZero4() { x = y = z = w = 0.0f; }
    void setSub4(const Vector4& a, const Vector4& b) { for (int i = 0; i < 4; i++) (&x)[i] = (&a.x)[i] - (&b.x)[i]; }
    void mul4(float s) { for (int i = 0; i < 4; i++) (&x)[i] *= s; }
};

struct MoppCode
{
    int m_memSizeAndFlags, m_pad04, m_pad08, m_pad0c;
    Vector4 m_offset;
    const unsigned char* m_data;
    int m_size;
};

struct ShapeRayCastInput
{
    Vector4 m_from;
    Vector4 m_to;
    unsigned int m_filterInfo;
    const void* m_rayShapeCollectionFilter;
};

struct RayHitCollector
{
    void* m_vtable;
    float m_earlyOutHitFraction;
};

struct __declspec(align(16)) QueryInt
{
    Vector4 m_offset;
    int m_level;
    float m_FtoBoxScale;
    unsigned int m_propertyCount;
    unsigned int m_properties0;
};

struct QueryFloat
{
    Vector4 m_rayStart;
    Vector4 m_rayEnd;
};


struct LongRayVirtualMachine
{
    int m_pad00, m_pad04, m_pad08, m_pad0c;
    const MoppCode* m_code;
    float m_ItoFScale;
    int m_pad18, m_pad1c;
    ShapeRayCastInput m_input;
    int m_pad48, m_pad4c;
    bool m_hitFound;
    float m_earlyOutHitFraction;
    int m_hits;
    const RayHitCollector* m_collector;
    const void* m_body;
    const void* m_collection;
    int m_reindexingChunk;

    void queryRayOnTree(const QueryInt* query, const unsigned char* PC, QueryFloat* fq, int level);
    __forceinline void startQuery(const MoppCode* code, const ShapeRayCastInput& input, const RayHitCollector* collector);
    void FUN_00a54420(const void* collection, const MoppCode* code, const ShapeRayCastInput& input, const void* body, const RayHitCollector* collector);
};

__forceinline void LongRayVirtualMachine::startQuery(const MoppCode* code, const ShapeRayCastInput& input, const RayHitCollector* collector)
{
    m_hits = 0;
    m_earlyOutHitFraction = collector->m_earlyOutHitFraction;
    m_code = code;
    const unsigned char* PC = m_code->m_data;

    QueryInt query;
    query.m_offset.setZero4();
    m_ItoFScale = 1.0f / code->m_offset.w;
    query.m_FtoBoxScale = (float)(code->m_offset.w * DAT_00dfc230);

    QueryFloat fq;
    fq.m_rayStart.setSub4(input.m_from, code->m_offset);
    fq.m_rayEnd.setSub4(input.m_to, code->m_offset);
    fq.m_rayStart.mul4(query.m_FtoBoxScale);
    fq.m_rayEnd.mul4(query.m_FtoBoxScale);

    m_input = input;
    m_hitFound = false;
    query.m_propertyCount = 0;
    query.m_level = 0;
    query.m_properties0 = 0;
    m_reindexingChunk = (*PC == 0xd) ? -1 : 0;
    queryRayOnTree(&query, PC, &fq, 0);
}

}

// pdb: hkpMoppLongRayVirtualMachine::queryLongRay | hkpMoppLongRayVirtualMachine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: collection, code, input, body, collector
void f3o_a54420::LongRayVirtualMachine::FUN_00a54420(const void* collection, const MoppCode* code, const ShapeRayCastInput& input, const void* body, const RayHitCollector* collector)
{
    m_collection = collection;

    m_body = body;
    m_collector = collector;

    startQuery(code, input, collector);
}
}   // namespace f3m_00a54420

// @f3 0x00a5b5d0 (community match, verified in this file)
#include <math.h>
namespace f3m_00a5b5d0 {
// FLAGS: /MT /O2 /GS- /EHs-c- /Gy
namespace f3m_00a5b5d0 {
__forceinline float root(float value) { return (float)sqrt(value); }
__forceinline float inverseRoot(float value) { return 1.0f / root(value); }
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void setSub4(const Vec4& a, const Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline float lengthSquared3() const { return dot3(*this); }
    __forceinline float lengthInverse3() const { float length = x * x + y * y + z * z; return length ? inverseRoot(length) : 0.0f; }
    __forceinline void mul4(float value) { float scale = value; x *= scale; y *= scale; z *= scale; w *= scale; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setNeg4(const Vec4& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
    __forceinline void set(float first, float second, float third, float fourth) { x = first; y = second; z = third; w = fourth; }
    __forceinline void setCross(const Vec4& a, const Vec4& b) {
        const float outX = a.y * b.z - a.z * b.y;
        const float outY = a.z * b.x - a.x * b.z;
        const float outZ = a.x * b.y - a.y * b.x;
        set(outX, outY, outZ, 0.0f);
    }
    __forceinline float dot3(const Vec4& b) const { return x * b.x + y * b.y + z * b.z; }
};
struct VecArray {
    Vec4* data; int size; int capacity;
    __forceinline int getSize() const { return size; }
    __forceinline Vec4& operator[](int index) { return data[index]; }
    __forceinline const Vec4& operator[](int index) const { return data[index]; }
};
void __cdecl FUN_00a59d00(VecArray* points);
}

// pdb: hkGeomConvexHullBuilder::removeCollinearVertices | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a5b5d0(f3m_00a5b5d0::VecArray* points, float tolerance)
{
    using namespace f3m_00a5b5d0;
    for (int i = 0; i < points->getSize(); i++)
        points->data[i].w = 0.0f;
    for (int i = 0; i < points->getSize(); i++) {
        for (int j = i + 1; j < points->getSize(); j++) {
            for (int k = j + 1; k < points->getSize(); k++) {
                if (points->data[i].w != 1.0f && points->data[j].w != 1.0f && points->data[k].w != 1.0f) {
                    Vec4 ab; ab.setSub4(points->data[i], points->data[j]); ab.normalize3();
                    Vec4 ba; ba.setNeg4(ab);
                    Vec4 ac; ac.setSub4(points->data[i], points->data[k]); ac.normalize3();
                    Vec4 ca; ca.setNeg4(ac);
                    Vec4 cb; cb.setSub4(points->data[k], points->data[j]); cb.normalize3();
                    Vec4 bc; bc.setNeg4(cb);
                    Vec4 normal;
                    normal.setCross(ab, ac);
                    float length = normal.lengthSquared3();
                    if (length < tolerance && ab.dot3(ac) < 0.0f) {
                        points->data[i].w = 1.0f;
                        continue;
                    }
                    normal.setCross(cb, ca);
                    length = normal.lengthSquared3();
                    if (length < tolerance && cb.dot3(ca) < 0.0f) {
                        points->data[k].w = 1.0f;
                        continue;
                    }
                    normal.setCross(ba, bc);
                    length = normal.lengthSquared3();
                    if (length < tolerance && ba.dot3(bc) < 0.0f) {
                        points->data[j].w = 1.0f;
                    }
                }
            }
        }
    }
    FUN_00a59d00(points);
}
}   // namespace f3m_00a5b5d0

// @f3 0x00a55e90 (community match, verified in this file)
#include <windows.h>
extern unsigned long DAT_010f3170;
namespace f3m_00a55e90 {


namespace weld_a55e90 {

struct hkBool
{
    char m_bool;
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = (char)b; }
};

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    __forceinline Vec4& operator=(const Vec4& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
    __forceinline void setAll3(float v)
    {
        x = v;
        y = v;
        z = v;
        w = 0.0f;
    }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
};

struct Aabb
{
    Vec4 m_min;
    Vec4 m_max;
};

struct ThreadMemory
{
    void FUN_008f6d90(void* p, int numBytes, int memoryClass);
};

__forceinline ThreadMemory* getThreadMemory()
{
    return static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
}

template <class T> __forceinline void deallocateChunk(T*& p, int n, int memoryClass)
{
    getThreadMemory()->FUN_008f6d90(p, n * sizeof(T), memoryClass);
}

struct KeyArray
{
    unsigned int* m_data;
    int m_size;
    int m_capacityAndFlags;
    unsigned int m_storage[128];

    __forceinline KeyArray()
    {
        m_data = m_storage;
        m_size = 0;
        m_capacityAndFlags = 0x80000080;
    }
    __forceinline ~KeyArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            deallocateChunk(m_data, m_capacityAndFlags & 0x3fffffff, 0x17);
    }
    __forceinline int getSize() const { return m_size; }
    __forceinline unsigned int& operator[](int i) { return m_data[i]; }
};

struct Shape
{
    void* vtbl;
    int m_memSizeAndFlags;
    int m_userData;
    int m_type;
};

struct TriShape : Shape
{
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 m_vertices[3];
};

struct ChildBuffer
{
    char data[512];
};

struct Container
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual const Shape* getChildShape(unsigned int key, ChildBuffer& buffer) const;
};

struct BvTree
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual const Container* getContainer() const;
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void queryAabb(const Aabb& aabb, KeyArray& hits) const;
};

}

int __cdecl FUN_00a559f0(const weld_a55e90::Vec4* triangle, const weld_a55e90::Vec4* other, int edgeIndex,
                         weld_a55e90::Vec4* vertices, int* ordered);
unsigned int __cdecl FUN_00ddcdd0(unsigned int bitcode, unsigned int edgeIndex, unsigned int value);
int __cdecl GetIndexForValue(int value);

// pdb: hkpMeshWeldingUtility::calcBitcodeForTriangleEdge | hkpMeshWeldingUtility.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
weld_a55e90::hkBool __cdecl hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(const weld_a55e90::BvTree* bvTree, const weld_a55e90::TriShape* triangle,
                                          unsigned int key, int edgeIndex, unsigned short& bitcode,
                                          bool testConsistency)
{
    using namespace weld_a55e90;
    KeyArray hits;
    Aabb aabb;
    const Vec4* verts = triangle->m_vertices;
    {
        Vec4 center = verts[edgeIndex % 3];
        float eps = 1e-4f;
        Vec4 lo;
        lo.setAll3(-eps);
        Vec4 hi;
        hi.setAll3(eps);
        lo.setAdd4(lo, center);
        hi.setAdd4(hi, center);
        aabb.m_min = lo;
        aabb.m_max = hi;
        bvTree->queryAabb(aabb, hits);
    }
    hkBool result = true;
    for (int i = hits.getSize() - 1; i >= 0; i--)
    {
        unsigned int other = hits[i];
        if (other == key)
            continue;
        ChildBuffer buffer;
        const Shape* shape = bvTree->getContainer()->getChildShape(other, buffer);
        if (shape->m_type != 4)
            continue;
        int ordered[2];
        Vec4 vertices[6];
        if (FUN_00a559f0(verts, static_cast<const TriShape*>(shape)->m_vertices, edgeIndex, vertices, ordered) != 4)
            continue;
        if (testConsistency)
            result = false;
        bitcode = (unsigned short)FUN_00ddcdd0(bitcode, edgeIndex, GetIndexForValue((int)vertices));
    }
    return result;
}
}   // namespace f3m_00a55e90

// @f3 0x00a57ba0 (community match, verified in this file)
#include <windows.h>
extern unsigned long DAT_010f3170;
extern unsigned long DAT_0116913c;
namespace f3m_00a57ba0 {
// FLAGS: /MT /O2 /GS- /EHs-c- /Gy

namespace f3m_00a57ba0 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void operator=(const Vec4& v) {
        x=v.x; y=v.y; z=v.z; w=v.w;
    }
};
void __cdecl FUN_00901f10(void* array, int elemSize);
void __cdecl FUN_00901e90(void* array, int capacity, int elemSize);

struct Vec4Array {
    Vec4* data;
    int size, capFlags;
    __forceinline void PushBack(const Vec4& v) {
        if (size == (capFlags & 0x3fffffff)) FUN_00901f10(this,16);
        data[size++] = v;
    }
    __forceinline void SetSize(int n) {
        int capacity = capFlags & 0x3fffffff;
        if (capacity < n) {
            int grown = capacity * 2;
            if (n >= grown) grown=n;
            FUN_00901e90(this,grown,16);
        }
        size=n;
    }
};

struct Router {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c(); virtual void s10();
    virtual void* allocateStack(int bytes);
    virtual void releaseStack(void* p);
    int r04, r08, r0c, r10, r14, r18, r1c;
    char* top;
    int r24;
    char* boundary;
    char* limit;
    void FUN_008f6d90(void* p, int bytes, int tag);
};

__forceinline Router* Memory() {
    return (Router*)TlsGetValue(DAT_010f3170);
}

struct Stream { int start; int* cur; int unused; int* end; };
__forceinline void TimerMark(const char* name) {
    Stream* s=(Stream*)TlsGetValue(DAT_0116913c);
    int* c=s->cur;
    if (c < s->end) {
        c[0]=(int)name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        c[1]=ticks;
        s->cur=c+3;
    }
}

struct LocalVec4Array {
    Vec4* data;
    int size;
    int capFlags;
    void* saved;
    __forceinline LocalVec4Array(int n) {
        data=0; size=0; capFlags=(int)0x80000000;
        Router* r=Memory();
        int bytes=((n+1)*16)&~15;
        char* p=r->top;
        char* end=p+bytes;
        void* result;
        if (end <= r->limit) { r->top=end; result=p; }
        else result=r->allocateStack(bytes);
        data=(Vec4*)result;
        saved=result;
        capFlags=n|0x80000000;
    }
    __forceinline ~LocalVec4Array() {
        char* p=(char*)saved;
        Router* r=Memory();
        r->top=p;
        if (p==r->boundary) r->releaseStack(p);
        if (!(capFlags&0x80000000)) {
            int capacity=capFlags&0x3fffffff;
            Memory()->FUN_008f6d90(data,capacity*16,0x17);
        }
    }
};

struct Seed { Vec4 point; int a,b,c; };
struct Pair { int i0,i1; };
struct Edge { int a,b; Seed* seed; Vec4 plane; };
struct EdgeArray {
    Edge* data;
    int size,capFlags;
};
struct LocalEdges : EdgeArray {
    Edge buffer[128];
    __forceinline LocalEdges() { data=buffer; size=0; capFlags=(int)0x80000080; }
    __forceinline ~LocalEdges() {
        if (!(capFlags&0x80000000)) {
            int capacity=capFlags&0x3fffffff;
            Memory()->FUN_008f6d90(data,capacity*sizeof(Edge),0x17);
        }
    }
    __forceinline void PushBack(const Edge& e) {
        data[size++]=e;
    }
};

void __cdecl FUN_00a56e20(Vec4* data,int lo,int hi,int (__cdecl* compare)(const void*,const void*));
int __cdecl FUN_00a58a60(const void* a,const void* b);
int __cdecl FUN_00a578b0(LocalVec4Array* planes,int* i0,int* i1,Seed* a,Seed* b);
void __cdecl FUN_00a56fa0(LocalVec4Array* planes,int a,int b,int c,Vec4* out);
void __cdecl FUN_00a57690(Edge* edge,LocalVec4Array* planes,EdgeArray* edges,Vec4Array* verts);
void __cdecl FUN_00a59780(float tolerance,Vec4Array* verts,int* count);

// Fake match: expose the side-effect contract of this geometric query so
// that its input and result pointers do not escape the reconstructed unit.
__declspec(noalias) int __cdecl FUN_00a57240(const Vec4* direction,LocalVec4Array* planes,int a,int b,Seed* upper,Seed* lower);

struct PairArray {
    Pair* data;
    int size,capFlags;
    Pair buffer[32];
    PairArray() { data=buffer;size=0;capFlags=(int)0x80000020; }
    ~PairArray() {
        if (!(capFlags&0x80000000)) {
            int cap=capFlags&0x3fffffff;
            Memory()->FUN_008f6d90(data,cap*sizeof(Pair),0x17);
        }
    }
    bool Contains(int a,int b) const {
        for (int i=0;i<size;++i) if (data[i].i0==a && data[i].i1==b) return true;
        return false;
    }
    void Add(int a,int b) {
        if (size==(capFlags&0x3fffffff)) FUN_00901f10(this,sizeof(Pair));
        data[size].i0=a; data[size].i1=b; ++size;
    }
};

// Fake match: preserve the original out-of-line call to the real initial-search helper.
__declspec(noinline) int __cdecl FUN_00a578b0(LocalVec4Array* planes,int* i0,int* i1,Seed* lower,Seed* upper)
{
    PairArray used;
    for (;;) {
        float best=-3.402820018375656e38f;
        int first=-1,second=-1;
        for (int i=0;i<planes->size;++i) {
            for (int j=i+1;j<planes->size;++j) {
                const Vec4& p=planes->data[i];
                const Vec4& q=planes->data[j];
                float dot=p.x*q.x+p.y*q.y+p.z*q.z;
                if (dot>best && dot<0.9f && !used.Contains(i,j)) {
                    best=dot;first=i;second=j;
                    *i0=i;*i1=j;
                }
            }
        }
        if (first==-1) return 1;
        used.Add(first,second);
        const Vec4& p=planes->data[*i0];
        const Vec4& q=planes->data[*i1];
        Vec4 direction;
        direction.x=p.y*q.z-p.z*q.y;
        direction.y=p.z*q.x-p.x*q.z;
        direction.z=p.x*q.y-p.y*q.x;
        direction.w=0.0f;
        if (FUN_00a57240(&direction,planes,*i0,*i1,upper,lower)==1) return 1;
        float dx=upper->point.x-lower->point.x;
        float dy=upper->point.y-lower->point.y;
        float dz=upper->point.z-lower->point.z;
        float length=direction.x*dx+direction.y*dy+direction.z*dz;
        if (length>-1.1920928955078125e-7f) return 0;
    }
}
}

int __cdecl FUN_00a57ba0(const f3m_00a57ba0::Vec4Array& planesIn,f3m_00a57ba0::Vec4Array& verts)
{
    using namespace f3m_00a57ba0;
    TimerMark("TtplanesToVerts");
    LocalVec4Array planes(planesIn.size);
    planes.size=planesIn.size;
    for (int i=0;i<planes.size;++i) planes.data[i]=planesIn.data[i];
    if (planes.size>1) FUN_00a56e20(planes.data,0,planes.size-1,FUN_00a58a60);

    Seed a,b;
    int indices[2];
    if (FUN_00a578b0(&planes,&indices[0],&indices[1],&a,&b)==1) {
        TimerMark("Et");
        return 1;
    }
    {
        LocalEdges edges;
        verts.PushBack(b.point);
        verts.PushBack(a.point);
        Edge start;
        start.a=b.a;
        start.b=b.b;
        edges.PushBack(start);
        {
            Edge e;
            e.a=a.a; e.b=a.c; e.seed=&a;
            FUN_00a56fa0(&planes,e.a,e.b,a.b,&e.plane);
            FUN_00a57690(&e,&planes,&edges,&verts);
        }
        {
            Edge e;
            e.a=a.b; e.b=a.c; e.seed=&a;
            FUN_00a56fa0(&planes,e.a,e.b,a.a,&e.plane);
            FUN_00a57690(&e,&planes,&edges,&verts);
        }
        {
            Edge e;
            e.a=b.a; e.b=b.c; e.seed=&b;
            FUN_00a56fa0(&planes,e.a,e.b,b.b,&e.plane);
            FUN_00a57690(&e,&planes,&edges,&verts);
        }
        {
            Edge e;
            e.a=b.b; e.b=b.c; e.seed=&b;
            FUN_00a56fa0(&planes,e.a,e.b,b.a,&e.plane);
            FUN_00a57690(&e,&planes,&edges,&verts);
        }
    }
    {
        Vec4* src=verts.data;
        Vec4* dst=verts.data;
        float eps=1e-5f;
        for (int i=verts.size-1;i>=0;--i) {
            bool inside=true;
            for (int j=0;j<planes.size;++j) {
                const Vec4& p=planes.data[j]; float distance=p.x*src->x+p.y*src->y+p.z*src->z+p.w;
                if (distance>eps) { inside=false; break; }
            }
            if (inside) *dst++=*src;
            ++src;
        }
        verts.SetSize((int)(dst-verts.data));
    }
    if (verts.size>1) FUN_00a56e20(verts.data,0,verts.size-1,FUN_00a58a60);
    {
        int count;
        FUN_00a59780(2e-5f,&verts,&count);
    }
    TimerMark("Et");
    return 0;
}
}   // namespace f3m_00a57ba0

// @f3 0x00a51540 (community match, verified in this file)
namespace f3m_00a51540 {
// FUN_00a51540 = Havok 5.5.0 hkBallSocketChainBuildJacobian (hkpConstraintSolver.lib, hkpChainBuildJacobian.obj).
// Written from the Havok 5.5.0 SDK headers and the library objects' debug records;
// cut to one file with hktrim.py. Reconstructed (headers not shipped): hkpJacobianSchema::setType,
// hkp1Lin2AngJacobian::getNonDiag*, hkpVelocityAccumulatorOffset, hkpConstraintChainMatrixTriple,
// hkpJacobianBallSocketChainSchema, buildConstraintMatrixLuDecompositionForBallAndSocketChain.
namespace f3m_00a51540 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

class hkBool
{
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

typedef hkReal hkSimdReal;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

namespace hkMath
{
	template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
}

class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setZero();
		__forceinline void _setTranspose( const hkMatrix3& s );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _sub( const hkMatrix3& a );
		inline void operator= ( const hkMatrix3& a );
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

extern "C"
{
	void hkMatrix3_setMulMat3Mat3( hkMatrix3* thisMatrix, const hkMatrix3& aTb, const hkMatrix3& bTc );
	void hkMatrix3_invertSymmetric( hkMatrix3& thisMatrix );
}

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}

inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}

inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}

inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}

inline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}

inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

inline void hkMatrix3::operator= ( const hkMatrix3& a )
{
	m_col0 = a.getColumn(0);
	m_col1 = a.getColumn(1);
	m_col2 = a.getColumn(2);
}

inline void hkMatrix3::_setTranspose( const hkMatrix3& s )
{
	hkMatrix3& d = *this;
	d(0,0) = s(0,0);
	d(1,1) = s(1,1);
	d(2,2) = s(2,2);
	d(3,0) = 0.0f;
	d(3,1) = 0.0f;
	d(3,2) = 0.0f;
	d(1,0) = s(0,1);
	d(0,1) = s(1,0);
	d(2,0) = s(0,2);
	d(0,2) = s(2,0);
	d(2,1) = s(1,2);
	d(1,2) = s(2,1);
}

inline void hkMatrix3::_setMul( const hkMatrix3& aTb, const hkMatrix3& bTc )
{
	hkMatrix3_setMulMat3Mat3( this, aTb, bTc );
}

inline void hkMatrix3::_sub( const hkMatrix3& a )
{
	getColumn(0).sub4( a.getColumn(0) );
	getColumn(1).sub4( a.getColumn(1) );
	getColumn(2).sub4( a.getColumn(2) );
}

inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}

class hkpVelocityAccumulator
{
	public:
		                class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
};

class hkpConstraintQueryStepInfo
{
	public:
		                class MustEndWithSemiColon;
		__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
		hkPadSpu<float>		m_microStepDeltaTime;
		hkPadSpu<float>		m_substepInvDeltaTime;
		hkPadSpu<float>		m_frameDeltaTime;
		hkPadSpu<float>		m_frameInvDeltaTime;
		hkPadSpu<float>		m_invNumSteps;
		hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
		hkPadSpu<float>		m_rhsFactor;
		hkPadSpu<float>		m_virtMassFactor;
		hkPadSpu<float> m_frictionRhsFactor;
};

class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		                class MustEndWithSemiColon;
		__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
		hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
		hkPadSpu<const hkTransform*>	m_transformA;
		hkPadSpu<const hkTransform*>	m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
		hkPadSpu<void*>	m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
};

class hkpJacobianSchema;

class  hkpConstraintQueryOut
{
	public:
		                class MustEndWithSemiColon;
		hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};

class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO,
			SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
			SCHEMA_TYPE_SIMPLE_BEGIN,
			SCHEMA_TYPE_1D_BILATERAL,
			SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
			SCHEMA_TYPE_1D_LINEAR_LIMITS,
			SCHEMA_TYPE_1D_FRICTION,
			SCHEMA_TYPE_1D_LINEAR_MOTOR,
			SCHEMA_TYPE_1D_PULLEY,
			SCHEMA_TYPE_1D_ANGULAR,
			SCHEMA_TYPE_1D_ANGULAR_LIMITS,
			SCHEMA_TYPE_1D_ANGULAR_FRICTION,
			SCHEMA_TYPE_1D_ANGULAR_MOTOR,
			SCHEMA_TYPE_SINGLE_CONTACT,
			SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_PAIR_CONTACT,
			SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_2D_FRICTION,
			SCHEMA_TYPE_3D_FRICTION,
			SCHEMA_TYPE_SET_MASS,
			SCHEMA_TYPE_ADD_VELOCITY,
			SCHEMA_TYPE_SIMPLE_END,
			SCHEMA_TYPE_STIFF_SPRING_CHAIN,
			SCHEMA_TYPE_BALL_SOCKET_CHAIN,
			SCHEMA_TYPE_POWERED_CHAIN,
			SCHEMA_TYPE_MAX
		};
		typedef hkEnum<SchemaType, hkInt8> JointSchemaType;
		static __forceinline void __cdecl setType( hkpJacobianSchema* schema, JointSchemaType type )
		{
			*reinterpret_cast<hkReal*>( schema ) = *reinterpret_cast<hkReal*>( schema ) + 1.192092896e-07F;
			*reinterpret_cast<JointSchemaType*>( schema ) = type;
		}
};

class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* accumulatorsBase )
		{
			return *hkAddByteOffsetConst( accumulatorsBase, m_offset );
		}
		hkUint32 m_offset;
};

class hkp1Lin2AngJacobian
{
	public:
		__forceinline hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		__forceinline hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		__forceinline hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
};

__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const
{
	const hkp1Lin2AngJacobian& jacA = *this;
	hkVector4 lin;  lin.setMul4( jacA.m_linear0, jacB.m_linear0 );
	hkVector4 ang0; ang0.setMul4( jacA.m_angular[0], jacB.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jacA.m_angular[1], jacB.m_angular[1] );
	hkVector4 massA; massA.setBroadcast3clobberW( mA.m_invMasses, 3 );
	hkVector4 massB; massB.setBroadcast3clobberW( mB.m_invMasses, 3 );
	hkVector4 lin0; lin0.setMul4( massA, lin );
	hkVector4 lin1; lin1.setMul4( massB, lin );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	lin0.add4( lin1 );
	ang0.add4( ang1 );
	ang0.add4( lin0 );
	hkReal result = ang0.horizontalAdd3();
	return result;
}

__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const
{
	return getNonDiagOptimized( mA, mB, jacB );
}

__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const
{
	const hkp1Lin2AngJacobian& jacA = *this;
	hkVector4 lin;  lin.setMul4( jacA.m_linear0, jacB.m_linear0 );
	hkVector4 ang0; ang0.setMul4( jacA.m_angular[1], jacB.m_angular[0] );
	hkVector4 massA; massA.setBroadcast( mA.m_invMasses, 3 );
	hkVector4 lin0; lin0.setMul4( massA, lin );
	ang0.mul4( mA.m_invMasses );
	ang0.sub4( lin0 );
	hkReal result = ang0.horizontalAdd3();
	return result;
}

struct hkpConstraintChainMatrixTriple
{
	hkMatrix3 m_lower;
	hkMatrix3 m_diagonalInv;
	hkMatrix3 m_upper;
};

class hkpJacobianBallSocketChainSchema
{
	public:
		static inline hkp1Lin2AngJacobian* __cdecl getJacobians( hkpJacobianSchema* schema )
		{
			return reinterpret_cast<hkp1Lin2AngJacobian*>( reinterpret_cast<hkpJacobianBallSocketChainSchema*>(schema) + 1 );
		}
		__forceinline hkpConstraintChainMatrixTriple* getMatrixBuffer() { return reinterpret_cast<hkpConstraintChainMatrixTriple*>( hkAddByteOffset( getJacobians( reinterpret_cast<hkpJacobianSchema*>(this) ), 3 * m_numConstraints * sizeof(hkp1Lin2AngJacobian) ) ); }
		inline hkVector4* getTempBuffer() { return reinterpret_cast<hkVector4*>( getMatrixBuffer() + m_numConstraints ); }
		__forceinline hkpVelocityAccumulatorOffset* getAccumulatorOffsetsBase() { return reinterpret_cast<hkpVelocityAccumulatorOffset*>( hkAddByteOffset( getTempBuffer(), (m_numConstraints + 1) * sizeof(hkVector4) ) ); }
		inline void* getEnd() { return getAccumulatorOffsetsBase() + m_numConstraints + 1; }
		__forceinline void initBallSocketChainSchema( int numConstraints, hkpVelocityAccumulatorOffset* accumulatorsIn, hkReal tau, hkReal damping )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>(this), hkpJacobianSchema::SCHEMA_TYPE_BALL_SOCKET_CHAIN );
			m_numConstraints = hkUint16( numConstraints );
			m_tau = tau;
			m_damping = damping;
			int size = int( hkUlong(getEnd()) - hkUlong(this) );
			m_size = ( ((size) + ((16)-1)) & (~((16)-1)) );
			hkpVelocityAccumulatorOffset* accumulators = getAccumulatorOffsetsBase();
			int numAccumulators = numConstraints + 1;
			for ( int i = 0; i < numAccumulators; i++ )
			{
				*(accumulators++) = *(accumulatorsIn++);
			}
		}
	public:
		hkUint16 m_padding;
		hkUint16 m_numConstraints;
		hkUint32 m_size;
		hkReal m_tau;
		hkReal m_damping;
};

static __forceinline void buildConstraintMatrixLuDecompositionForBallAndSocketChain( int numConstraints, hkReal cfm, hkp1Lin2AngJacobian* j, hkpVelocityAccumulatorOffset* va, const hkpVelocityAccumulator* accumBase, hkpConstraintChainMatrixTriple* triple, int bufferSize )
{
	hkMatrix3 mtxPrevOffdiag; mtxPrevOffdiag.setZero();
	hkMatrix3 triplePrevUpper; triplePrevUpper.setZero();
	for ( int row = 0; row < numConstraints; row++ )
	{
		int jacobiansPerRow = 3;
		const int jacIdx = row * jacobiansPerRow;
		hkMatrix3 mtxDiag;
		for ( int r = 0; r < 3; r++ )
		{
			for ( int c = r; c < 3; c++ )
			{
				mtxDiag(c,r) = mtxDiag(r,c) = j[jacIdx + r].getNonDiagSameObjects( va[row].getAccumulator(accumBase), va[row+1].getAccumulator(accumBase), j[jacIdx + c] );
			}
			mtxDiag(r,r) += cfm;
		}
		hkMatrix3 mtxNextOffdiag; mtxNextOffdiag.setZero();
		if ( row < numConstraints - 1 )
		{
			for ( int r = 0; r < 3; r++ )
			{
				for ( int c = 0; c < 3; c++ )
				{
					mtxNextOffdiag(r,c) = j[jacIdx + r].getNonDiagDifferentObjects_With2ndBodyFromFirstObject( va[row+1].getAccumulator(accumBase), j[jacIdx + jacobiansPerRow + c] );
				}
			}
		}
		else
		{
			mtxNextOffdiag.getColumn(0).setZero4();
			mtxNextOffdiag.getColumn(1).setZero4();
			mtxNextOffdiag.getColumn(2).setZero4();
		}
		triple[row].m_lower._setTranspose( mtxPrevOffdiag );
		hkMatrix3 tmp;
		tmp._setMul( triple[row].m_lower, triplePrevUpper );
		triple[row].m_diagonalInv = mtxDiag;
		triple[row].m_diagonalInv._sub( tmp );
		for ( int r = 0; r < 3; r++ )
		{
			hkReal& d = triple[row].m_diagonalInv(r,r);
			d = hkMath::max2( d, 1.192092896e-07F );
		}
		hkMatrix3_invertSymmetric( triple[row].m_diagonalInv );
		triple[row].m_upper._setMul( triple[row].m_diagonalInv, mtxNextOffdiag );
		mtxPrevOffdiag = mtxNextOffdiag;
		triplePrevUpper = triple[row].m_upper;
	}
}

// pdb: hkBallSocketChainBuildJacobian | hkpChainBuildJacobian.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: numConstraints, tau, damping, cfm, accumulators, accumBase, jacobiansEnd, in, out
void __cdecl FUN_00a51540( int numConstraints, hkReal tau, hkReal damping, hkReal cfm, hkpVelocityAccumulatorOffset* accumulators, const hkpVelocityAccumulator* accumBase, hkp1Lin2AngJacobian* jacobiansEnd, const hkpConstraintQueryIn& in, hkpConstraintQueryOut& out )
{
	hkpJacobianBallSocketChainSchema* chainSchema = reinterpret_cast<hkpJacobianBallSocketChainSchema*>( out.m_jacobianSchemas.val() );
	chainSchema->initBallSocketChainSchema( numConstraints, accumulators, tau, damping );
	hkp1Lin2AngJacobian* j = hkpJacobianBallSocketChainSchema::getJacobians( out.m_jacobianSchemas );
	hkpVelocityAccumulatorOffset* va = chainSchema->getAccumulatorOffsetsBase();
	hkpConstraintChainMatrixTriple* triples = chainSchema->getMatrixBuffer();
	const int triplesSize = sizeof(hkpConstraintChainMatrixTriple) * numConstraints;
	buildConstraintMatrixLuDecompositionForBallAndSocketChain( numConstraints, cfm, j, va, accumBase, triples, triplesSize );
	out.m_jacobianSchemas = hkAddByteOffset( out.m_jacobianSchemas.val(), chainSchema->m_size );
}
}
}   // namespace f3m_00a51540

// @f3 0x00a5bbb0 (community match, verified in this file)
// FUN_00a5bbb0 = Havok 5.5.0 hkpGeomConvexHullBuilder::postFilterVertices (hkpInternal.lib, hkpGeomConvexHullBuilder.obj).
// Written from the Havok 5.5.0 SDK headers, the pdb type records and the hybrid library object's debug records
// (lines 858-1055); cut to one file with hktrim.py.
extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}
namespace f3m_00a5bbb0 {
typedef float  hkReal;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
	private:
		char m_bool;
};


		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray();
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void clear();
		__forceinline void pushBack(const T& e);
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		__forceinline T* expandBy( int n );
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}

template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::_reserve(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T>
__forceinline T* hkArray<T>::expandBy( int n )
{
	int oldsize = m_size;
	setSize( oldsize + n );
	return m_data+oldsize;
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

extern "C" {
        double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}

class hkpGeomEdge
{
	public:
		                class MustEndWithSemiColon;
		inline const hkVector4* getVertex( const hkVector4* vertexBase ) const { return vertexBase + m_vertex; }
		inline hkpGeomEdge* getMirror( hkpGeomEdge* edgeBase ) const { return edgeBase + m_mirror; }
		inline hkpGeomEdge* getNext( hkpGeomEdge* edgeBase ) const { return edgeBase + m_next; }
		hkUint16 m_vertex;
		hkUint16 m_mirror;
		hkUint16 m_next;
		hkUint16 m_info : 16;
};

class hkpGeomHull
{
	public:
		                class MustEndWithSemiColon;
		struct WrappingEdge;
		hkVector4* m_vertexBase;
		hkInplaceArray<hkpGeomEdge,128> m_edges;
};

struct hkpGeomConvexHullTolerances
{
	                class MustEndWithSemiColon;
	hkBool m_postFilter;
	hkBool m_runConvertToUnitCube;
	hkBool m_accurateButSlow;
	hkReal m_weld_tolerance;
	hkReal m_degenerate_tolerance;
	hkReal m_coplanar_vertices_tolerance;
	hkReal m_coplanar_plane_tolerance;
	hkReal m_coplanar_tolerance;
	hkReal m_oppositeNormal_tolerance;
	hkReal m__min_proj;
	hkReal m__maxAngle;
	hkReal m__planeEqnMinLength;
	hkReal m__tol;
	hkReal m__tol2;
	hkReal m__tol3;
};

class hkpGeomConvexHullBuilder
{
	public:
		enum VisitedEdgeInfo
		{
			NOT_VISITED = 0,
			VISITED_VISIBLE = 1,
			VISITED_BOUNDARY = 2,
			VISITED_HIDDEN = 3
		};
		struct WeightedLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			WeightedLine* m_source;
			hkUint32 m_lastVertex;
			hkReal m_weight;
		};
		struct WrappingLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			hkUint16 m_leftVertex;
			hkUint16 m_rightVertex;
			hkUint16 m_leftNextEdgeVertex;
			hkUint16 m_rightNextEdgeVertex;
		};
		struct WeightedNeighbour
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_edge;
			hkReal m_weight;
		};
		class PlaneAndPoints;
};

// pdb: hkGeomConvexHullBuilder::postFilterVertices | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a5bbb0( hkpGeomHull& hull, int startVertex, int endVertex, const hkpGeomConvexHullTolerances& tolerances, hkBool& vertsHaveChanged )
{
	vertsHaveChanged = false;
	if ( tolerances.m_postFilter == false )
	{
		return;
	}
	{
		hkpGeomEdge* edgeBase = hull.m_edges.begin();
		hkVector4* vertexBase = hull.m_vertexBase;
		for ( int jn = 0; jn < hull.m_edges.getSize(); jn++ )
		{
			hull.m_edges[jn].m_info = hkpGeomConvexHullBuilder::NOT_VISITED;
		}
		for ( int ie = 0; ie < hull.m_edges.getSize(); ie++ )
		{
			if ( hull.m_edges[ie].m_info != hkpGeomConvexHullBuilder::VISITED_VISIBLE )
			{
			hkpGeomEdge& edge = hull.m_edges[ie];
			hkpGeomEdge& mirror = *edge.getMirror( edgeBase );
			edge.m_info = hkpGeomConvexHullBuilder::VISITED_VISIBLE;
			mirror.m_info = hkpGeomConvexHullBuilder::VISITED_VISIBLE;
			int v0 = edge.m_vertex;
			int v1 = mirror.m_vertex;
			hkVector4& vv0 = vertexBase[v0];
			hkVector4& vv1 = vertexBase[v1];
			hkVector4 d1; d1.setSub4( vv1, vv0 );
			hkArray<int> possibles;
			possibles.clear();
			int min_index = v0;
			int max_index = v1;
			hkReal min_proj = 1e-6f;
			hkReal max_proj = d1.lengthSquared3();
			if ( v1 != v0 && vv0(3) == 0.0f && vv1(3) == 0.0f )
			{
				for ( int v2 = startVertex; v2 < endVertex + 1; v2++ )
				{
					hkVector4& vv2 = vertexBase[v2];
					if ( v0 != v2 && v1 != v2 && vv2(3) == 0.0f )
					{
						hkVector4 tangentPlaneEquation;
						{
							hkVector4 d2; d2.setSub4( vv2, vv0 );
							hkReal proj = d1.dot3( d2 );
							tangentPlaneEquation.setCross( d1, d2 );
							if ( tangentPlaneEquation.lengthSquared3() < tolerances.m_degenerate_tolerance )
							{
								if ( proj < min_proj )
								{
									possibles.pushBack( min_index );
									min_index = v2;
									min_proj = proj;
								}
								else if ( proj > max_proj )
								{
									possibles.pushBack( max_index );
									max_index = v2;
									max_proj = proj;
								}
								else
								{
									possibles.pushBack( v2 );
								}
							}
						}
					}
				}
			}
			for ( int ip = 0; ip < possibles.getSize(); ip++ )
			{
				if ( possibles[ip] != min_index && possibles[ip] != max_index )
				{
					vertexBase[ possibles[ip] ](3) = 1.0f;
					vertsHaveChanged = true;
				}
			}
			}
		}
		for ( int jn = 0; jn < hull.m_edges.getSize(); jn++ )
		{
			hull.m_edges[jn].m_info = hkpGeomConvexHullBuilder::NOT_VISITED;
		}
		if ( endVertex - startVertex > 2 && hull.m_edges.getSize() > 2 )
		{
			for ( int iv = startVertex; iv < endVertex + 1; iv++ )
			{
				if ( vertexBase[iv](3) == 0.0f )
				{
					hkArray<hkVector4> normals;
					for ( int ie = 0; ie < hull.m_edges.getSize(); ie++ )
					{
						if ( hull.m_edges[ie].m_info != hkpGeomConvexHullBuilder::VISITED_VISIBLE && hull.m_edges[ie].m_vertex == iv )
						{
							hull.m_edges[ie].m_info = hkpGeomConvexHullBuilder::VISITED_VISIBLE;
							hkpGeomEdge* startNeighbour = hull.m_edges[ie].getMirror( edgeBase );
							hkpGeomEdge* currentNeighbour = startNeighbour;
							do
							{	currentNeighbour->getNext( edgeBase )->m_info = hkpGeomConvexHullBuilder::VISITED_VISIBLE;
								const hkVector4& u0 = *currentNeighbour->getVertex( vertexBase );
								const hkVector4& u1 = *currentNeighbour->getNext( edgeBase )->getVertex( vertexBase );
								const hkVector4& u2 = *currentNeighbour->getNext( edgeBase )->getNext( edgeBase )->getVertex( vertexBase );
								{
									hkVector4 tangentDir; tangentDir.setSub4( u0, u1 );
									hkVector4 other; other.setSub4( u2, u1 );
									hkVector4& n = *normals.expandBy(1);
									n.setCross( tangentDir, other );
									n.normalize3();
								}
								currentNeighbour = currentNeighbour->getNext( edgeBase )->getMirror( edgeBase );
							} while ( currentNeighbour != startNeighbour );
						}
					}
					if ( normals.getSize() > 0 )
					{
						int k;
						hkVector4 normal; normal.setZero4();
						for ( k = 0; k < normals.getSize(); k++ )
						{
							normal.add4( normals[k] );
						}
						if ( normal.lengthSquared3() > tolerances.m_coplanar_vertices_tolerance )
						{
							normal.normalize3();
							hkBool valid = false;
							for ( k = 0; k < normals.getSize(); k++ )
							{
								hkReal dot = normals[k].dot3( normal );
								if ( dot < hkReal( 1.0f - tolerances.m_coplanar_vertices_tolerance ) )
								{
									valid = true;
									break;
								}
							}
							if ( !valid )
							{
								vertexBase[iv](3) = 1.0f;
								vertsHaveChanged = true;
							}
						}
					}
				}
			}
		}
	}
}
}

// @f3 0x00a5c3d0 (community match, verified in this file)
// FUN_00a5c3d0 = Havok 5.5.0 hkpGeomConvexHullBuilder::buildPlaneEquations (hkpInternal.lib, hkpGeomConvexHullBuilder.obj).
// Written from the Havok 5.5.0 SDK headers, the pdb type records and the hybrid library object's debug records,
// cut to one file with hktrim.py. Called helpers of the same object are written out
// in record-line order: createBevelPlane 1326, PlaneAndPoints::sort 3118, PlaneAndPoints::findPair 3125.
extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}
namespace f3m_00a5c3d0 {
typedef float  hkReal;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
};


		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray();
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void clear();
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		__forceinline T* expandBy( int n );
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline const_iterator begin() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}

template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::_reserve(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T>
__forceinline T* hkArray<T>::expandBy( int n )
{
	int oldsize = m_size;
	setSize( oldsize + n );
	return m_data+oldsize;
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

extern "C" {
 double  __cdecl fabs(     double _X);
        double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w * a.w );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

inline hkSimdReal hkVector4::lengthSquared4() const
{
	return this->dot4(*this);
}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
	}

namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
	template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}

namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}

class hkpGeomEdge
{
	public:
		                class MustEndWithSemiColon;
		inline const hkVector4* getVertex( const hkVector4* vertexBase ) const { return vertexBase + m_vertex; }
		inline hkpGeomEdge* getMirror( hkpGeomEdge* edgeBase ) const { return edgeBase + m_mirror; }
		hkUint16 m_vertex;
		hkUint16 m_mirror;
		hkUint16 m_next;
		hkUint16 m_info : 16;
};

class hkpGeomHull
{
	public:
		                class MustEndWithSemiColon;
		struct WrappingEdge;
		hkVector4* m_vertexBase;
		hkInplaceArray<hkpGeomEdge,128> m_edges;
};

struct hkpGeomConvexHullTolerances
{
	                class MustEndWithSemiColon;
	hkBool m_postFilter;
	hkBool m_runConvertToUnitCube;
	hkBool m_accurateButSlow;
	hkReal m_weld_tolerance;
	hkReal m_degenerate_tolerance;
	hkReal m_coplanar_vertices_tolerance;
	hkReal m_coplanar_plane_tolerance;
	hkReal m_coplanar_tolerance;
	hkReal m_oppositeNormal_tolerance;
	hkReal m__min_proj;
	hkReal m__maxAngle;
	hkReal m__planeEqnMinLength;
	hkReal m__tol;
	hkReal m__tol2;
	hkReal m__tol3;
};

class hkpGeomConvexHullBuilder
{
	public:
		enum VisitedEdgeInfo
		{
			NOT_VISITED = 0,
			VISITED_VISIBLE = 1,
			VISITED_BOUNDARY = 2,
			VISITED_HIDDEN = 3
		};
		struct WeightedLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			WeightedLine* m_source;
			hkUint32 m_lastVertex;
			hkReal m_weight;
		};
		struct WrappingLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			hkUint16 m_leftVertex;
			hkUint16 m_rightVertex;
			hkUint16 m_leftNextEdgeVertex;
			hkUint16 m_rightNextEdgeVertex;
		};
		struct WeightedNeighbour
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_edge;
			hkReal m_weight;
		};
		class PlaneAndPoints
		{
			public:
				                class MustEndWithSemiColon;
				void sort();
				static hkBool __cdecl findPair( hkpGeomEdge* edgeBase, hkpGeomEdge* a0, hkpGeomEdge* b0, hkpGeomEdge* a1, hkpGeomEdge* b1, PlaneAndPoints& pp1, PlaneAndPoints& pp2 );
				hkVector4 m_planeEquation;
				hkpGeomEdge* m_v0;
				hkpGeomEdge* m_v1;
				hkpGeomEdge* m_v2;
				hkUint16 m_info : 16;
		};
		static void __cdecl weldXsortedVertices( hkReal tolerance, hkArray<hkVector4>& vertices, int& numVerticesOut );
		static hkBool __cdecl vectorLessAndMergeCoordinates( hkVector4& a, hkVector4& b );
		static void __cdecl createBevelPlane( const hkVector4& planeEquation, const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkArray<hkVector4>& planeEquationsOut );
		static void __cdecl generateHullFromPlanarPoints( const hkVector4& planeEquation, const hkVector4* vertices, int numVertices, hkArray<hkVector4>& hullVerticesOut, hkArray<hkVector4>& planeEquationsOut );
};

// pdb: hkGeomConvexHullBuilder::buildPlaneEquations | hkGeomConvexHullBuilder.obj | tesv_win, call_gap, low
hkBool __cdecl FUN_00a5c3d0( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& hull, const hkArray<hkVector4>& usedVertices, hkVector4& planarPlaneEquationOut, hkBool& isPlanarOut, hkArray<hkVector4>& planeEquationsOut, hkArray<hkpGeomConvexHullBuilder::PlaneAndPoints>& tangentPlanesOut )
{
	hkpGeomEdge* edgeBase = hull.m_edges.begin();
	hkVector4* vertexBase = hull.m_vertexBase;
	for ( int ie = 0; ie < hull.m_edges.getSize(); ie++ )
	{
		hkpGeomEdge edge0 = hull.m_edges[ie];
		int edge1Index = edge0.m_next;
		int edge2Index = edgeBase[ edge0.m_next ].m_next;
		if ( ie < edge1Index && ie < edge2Index )
		{
			hkVector4& tangentPlaneEquation = *planeEquationsOut.expandBy(1);
			{
				hkVector4 v0 = *edge0.getVertex( hull.m_vertexBase );
				hkVector4 v1 = *edgeBase[edge1Index].getVertex( hull.m_vertexBase );
				hkVector4 v2 = *edgeBase[edge2Index].getVertex( hull.m_vertexBase );
				hkVector4 tangentDir; tangentDir.setSub4( v0, v1 );
				tangentDir.normalize3();
				hkVector4 other; other.setSub4( v2, v1 ); other.normalize3();
				tangentPlaneEquation.setCross( tangentDir, other );
				if ( tangentPlaneEquation.lengthSquared3() < tolerances.m_degenerate_tolerance )
				{
					planeEquationsOut.setSize( planeEquationsOut.getSize() - 1 );
				}
				else
				{
					tangentPlaneEquation.normalize3();
					tangentPlaneEquation(3) = -tangentPlaneEquation.dot3( v0 );
					hkVector4 centre;
					{
						hkVector4 e1; e1.setSub4( v1, v0 ); e1.setMul4( 0.5f, e1 );
						hkVector4 e2; e2.setSub4( v2, v0 ); e2.setMul4( 0.5f, e2 );
						centre.setAdd4( e1, e2 );
						centre.add4( v0 );
					}
					hkpGeomConvexHullBuilder::PlaneAndPoints& tp = *tangentPlanesOut.expandBy(1);
					tp.m_planeEquation = tangentPlaneEquation;
					tp.m_v0 = &hull.m_edges[ie];
					tp.m_v1 = &edgeBase[edge1Index];
					tp.m_v2 = &edgeBase[edge2Index];
					tp.sort();
				}
			}
		}
	}
	isPlanarOut = false;
	for ( int i = 0; i < tangentPlanesOut.getSize(); i++ )
	{
		for ( int j = i + 1; j < tangentPlanesOut.getSize(); j++ )
		{
			hkpGeomConvexHullBuilder::PlaneAndPoints pp1 = tangentPlanesOut[i];
			hkpGeomConvexHullBuilder::PlaneAndPoints pp2 = tangentPlanesOut[j];
			hkVector4 diff; diff.setAdd4( pp1.m_planeEquation, pp2.m_planeEquation );
			if ( diff.lengthSquared4() < tolerances.m_oppositeNormal_tolerance )
			{
				isPlanarOut = true;
				pp1.m_planeEquation(0) = -pp2.m_planeEquation(0);
				pp1.m_planeEquation(1) = -pp2.m_planeEquation(1);
				pp1.m_planeEquation(2) = -pp2.m_planeEquation(2);
				if ( hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v0, pp2.m_v0, pp1.m_v1, pp2.m_v1, pp1, pp2 ) || hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v0, pp2.m_v0, pp1.m_v1, pp2.m_v2, pp1, pp2 ) )
				{
					isPlanarOut = true;
					hkpGeomConvexHullBuilder::createBevelPlane( pp1.m_planeEquation, vertexBase[ pp1.m_v0->m_vertex ], vertexBase[ pp1.m_v1->m_vertex ], vertexBase[ pp1.m_v2->m_vertex ], planeEquationsOut );
				}
				if ( hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v0, pp2.m_v0, pp1.m_v2, pp2.m_v1, pp1, pp2 ) || hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v0, pp2.m_v0, pp1.m_v2, pp2.m_v2, pp1, pp2 ) )
				{
					isPlanarOut = true;
					hkpGeomConvexHullBuilder::createBevelPlane( pp1.m_planeEquation, vertexBase[ pp1.m_v0->m_vertex ], vertexBase[ pp1.m_v2->m_vertex ], vertexBase[ pp1.m_v1->m_vertex ], planeEquationsOut );
				}
				if ( hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v1, pp2.m_v0, pp1.m_v2, pp2.m_v1, pp1, pp2 ) || hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v1, pp2.m_v0, pp1.m_v2, pp2.m_v2, pp1, pp2 ) || hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( edgeBase, pp1.m_v1, pp2.m_v1, pp1.m_v2, pp2.m_v2, pp1, pp2 ) )
				{
					isPlanarOut = true;
					hkpGeomConvexHullBuilder::createBevelPlane( pp1.m_planeEquation, vertexBase[ pp1.m_v1->m_vertex ], vertexBase[ pp1.m_v2->m_vertex ], vertexBase[ pp1.m_v0->m_vertex ], planeEquationsOut );
				}
			}
		}
	}
	if ( isPlanarOut )
	{
		hkVector4 edge1; edge1.setSub4( usedVertices[0], usedVertices[1] );
		hkVector4 edge2; edge2.setSub4( usedVertices[0], usedVertices[2] );
		planarPlaneEquationOut.setCross( edge1, edge2 );
		planarPlaneEquationOut.normalize3();
		planarPlaneEquationOut(3) = -planarPlaneEquationOut.dot3( usedVertices[0] );
	}
	{
		hkAlgorithm::quickSort( planeEquationsOut.begin(), planeEquationsOut.getSize(), hkpGeomConvexHullBuilder::vectorLessAndMergeCoordinates );
		int newNumPlanes;
		hkpGeomConvexHullBuilder::weldXsortedVertices( tolerances.m_coplanar_plane_tolerance, planeEquationsOut, newNumPlanes );
	}
	if ( planeEquationsOut.getSize() < 2 )
	{
		hkVector4 v0;
		hkVector4 v1;
		if ( hull.m_edges.getSize() == 1 )
		{
			v0 = *hull.m_edges[0].getVertex( hull.m_vertexBase );
			hkVector4 xDir; xDir.set( 1.0f, 0.0f, 0.0f, 0.0f );
			v1.setAdd4( v0, xDir );
		}
		else
		{
			v0 = *hull.m_edges[0].getVertex( hull.m_vertexBase );
			v1 = *hull.m_edges[0].getMirror( hull.m_edges.begin() )->getVertex( hull.m_vertexBase );
		}
		hkVector4 v0v1; v0v1.setSub4( v0, v1 );
		hkVector4 minDir;
		hkReal minDot = 3.40282e+38f;
		for ( int i = 0; i < 3; i++ )
		{
			hkVector4 axis; axis.set( 0.0f, 0.0f, 0.0f, 0.0f ); axis(i) = 1.0f;
			hkReal dot = hkMath::fabs( v0v1.dot3( axis ) );
			if ( dot < minDot )
			{
				minDot = dot;
				minDir = axis;
			}
		}
		int startSize = planeEquationsOut.getSize();
		planeEquationsOut.setSize( startSize + 6 );
		hkVector4& p0 = planeEquationsOut[ startSize ];
		p0.setCross( v0v1, minDir );
		p0.normalize3();
		p0(3) = -p0.dot3( v0 );
		hkVector4& p1 = planeEquationsOut[ startSize + 1 ];
		p1.setCross( v0v1, p0 );
		p1.normalize3();
		p1(3) = -p1.dot3( v0 );
		hkVector4& p2 = planeEquationsOut[ startSize + 2 ];
		p2.setNeg4( p0 );
		p2(3) = -p2.dot3( v0 );
		hkVector4& p3 = planeEquationsOut[ startSize + 3 ];
		p3.setNeg4( p1 );
		p3(3) = -p3.dot3( v0 );
		hkVector4& p4 = planeEquationsOut[ startSize + 4 ];
		p4 = v0v1;
		p4.normalize3();
		p4(3) = -p4.dot3( v0 );
		hkVector4& p5 = planeEquationsOut[ startSize + 5 ];
		p5.setNeg4( p4 );
		p5.normalize3();
		p5(3) = ( hull.m_edges.getSize() == 1 ) ? -p5.dot3( v0 ) : -p5.dot3( v1 );
	}
	if ( isPlanarOut && tolerances.m_accurateButSlow )
	{
		planeEquationsOut.clear();
		hkArray<hkVector4> planarHullVertices;
		hkpGeomConvexHullBuilder::generateHullFromPlanarPoints( planarPlaneEquationOut, usedVertices.begin(), usedVertices.getSize(), planarHullVertices, planeEquationsOut );
	}
	{
		hkAlgorithm::quickSort( planeEquationsOut.begin(), planeEquationsOut.getSize(), hkpGeomConvexHullBuilder::vectorLessAndMergeCoordinates );
		int newNumPlanes;
		hkpGeomConvexHullBuilder::weldXsortedVertices( tolerances.m_coplanar_plane_tolerance, planeEquationsOut, newNumPlanes );
	}
	return true;
}

void hkpGeomConvexHullBuilder::createBevelPlane( const hkVector4& planeNormal, const hkVector4& vertex0, const hkVector4& vertex1, const hkVector4& vertex2, hkArray<hkVector4>& planeEquationsOut )
{
	hkVector4& bevelPlaneEqn = *planeEquationsOut.expandBy(1);
	{
		hkVector4 lineDir; lineDir.setSub4( vertex0, vertex1 );
		bevelPlaneEqn.setCross( planeNormal, lineDir );
		hkVector4 awayDir; awayDir.setSub4( vertex2, vertex1 );
		hkReal awayValue = bevelPlaneEqn.dot3( awayDir );
		if ( awayValue > 1e-6f )
		{
			bevelPlaneEqn.setNeg4( bevelPlaneEqn );
		}
		if ( bevelPlaneEqn.lengthSquared3() > 1e-4f )
		{
			bevelPlaneEqn.normalize3();
			bevelPlaneEqn(3) = -bevelPlaneEqn.dot3( vertex0 );
			hkVector4 centre;
			centre.setSub4( vertex0, vertex1 ); centre.setMul4( 0.5f, centre ); centre.add4( vertex1 );
		}
		else
		{
			planeEquationsOut.setSize( planeEquationsOut.getSize() - 1 );
		}
	}
}

void hkpGeomConvexHullBuilder::PlaneAndPoints::sort()
{
	if ( m_v0->m_vertex > m_v1->m_vertex ) hkAlgorithm::swap( m_v0, m_v1 );
	if ( m_v1->m_vertex > m_v2->m_vertex ) hkAlgorithm::swap( m_v1, m_v2 );
	if ( m_v0->m_vertex > m_v1->m_vertex ) hkAlgorithm::swap( m_v0, m_v1 );
}

hkBool hkpGeomConvexHullBuilder::PlaneAndPoints::findPair( hkpGeomEdge* edgeBase, hkpGeomEdge* p11, hkpGeomEdge* p21, hkpGeomEdge* p12, hkpGeomEdge* p22, PlaneAndPoints& p1, PlaneAndPoints& p2 )
{
	hkBool firstPairOk = p11 != p21 && p11->m_vertex == p21->m_vertex && p11->getMirror( edgeBase )->m_vertex != p21->getMirror( edgeBase )->m_vertex;
	hkBool secondPairOk = p12 != p22 && p12->m_vertex == p22->m_vertex && p12->getMirror( edgeBase )->m_vertex != p22->getMirror( edgeBase )->m_vertex;
	hkBool isOk = firstPairOk && secondPairOk;
	if ( isOk )
	{
		hkBool p22ok = true;
		p22ok = ( p22ok && p11 != p22 && p11->m_vertex == p22->m_vertex ) ? p11->getMirror( edgeBase )->m_vertex != p22->getMirror( edgeBase )->m_vertex : true;
		p22ok = ( p22ok && p12 != p22 && p12->m_vertex == p22->m_vertex ) ? p12->getMirror( edgeBase )->m_vertex != p22->getMirror( edgeBase )->m_vertex : true;
		p22ok = ( p22ok && p11->getMirror( edgeBase )->m_vertex == p22->m_vertex && p22->getMirror( edgeBase )->m_vertex == p11->m_vertex ) ? p11->getMirror( edgeBase ) == p22 : true;
		p22ok = ( p22ok && p12->getMirror( edgeBase )->m_vertex == p22->m_vertex && p22->getMirror( edgeBase )->m_vertex == p12->m_vertex ) ? p12->getMirror( edgeBase ) == p22 : true;
		hkBool p21ok = true;
		p21ok = ( p21ok && p11 != p21 && p11->m_vertex == p21->m_vertex ) ? p11->getMirror( edgeBase )->m_vertex != p21->getMirror( edgeBase )->m_vertex : true;
		p21ok = ( p21ok && p12 != p21 && p12->m_vertex == p21->m_vertex ) ? p12->getMirror( edgeBase )->m_vertex != p21->getMirror( edgeBase )->m_vertex : true;
		p21ok = ( p21ok && p11->getMirror( edgeBase )->m_vertex == p21->m_vertex && p21->getMirror( edgeBase )->m_vertex == p11->m_vertex ) ? p11->getMirror( edgeBase ) == p21 : true;
		p21ok = ( p21ok && p12->getMirror( edgeBase )->m_vertex == p21->m_vertex && p21->getMirror( edgeBase )->m_vertex == p12->m_vertex ) ? p12->getMirror( edgeBase ) == p21 : true;
		isOk = p22ok && p21ok;
	}
	return isOk;
}
}

// @f3 0x00a5a490 (community match, verified in this file)
// FUN_00a5a490 = Havok 5.5.0 hkpGeomConvexHullBuilder::generateHullFromPlanarPoints (hkpInternal.lib, hkpGeomConvexHullBuilder.obj).
// Written from the Havok 5.5.0 SDK headers, the pdb type records and the hybrid library object's debug records,
// cut to one file with hktrim.py. The one same-object callee, getPseudoAngle (line 229),
// is declared only: its body (exact against the library, see note.txt) is not needed and would make the call internal.
extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}
namespace f3m_00a5a490 {
typedef float  hkReal;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
};


		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray(int size, const T& fill);
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getCapacity() const;
		__forceinline void clear();
		__forceinline void pushBack(const T& e);
		__forceinline T& expandOne( );
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}

template <typename T>
__forceinline hkArray<T>::hkArray(int n, const T& t)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().allocateChunk(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
		m_size(n),
		m_capacityAndFlags(n)
{
	for(int i = 0; i < n; ++i)
	{
		m_data[i] = t;
	}
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline T& hkArray<T>::expandOne( )
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	return m_data[m_size++];
}

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

extern "C" {
 double  __cdecl fabs(     double _X);
        double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
	}

class hkpGeomEdge
{
	public:
		                class MustEndWithSemiColon;
		hkUint16 m_vertex;
		hkUint16 m_mirror;
		hkUint16 m_next;
		hkUint16 m_info : 16;
};

class hkpGeomConvexHullBuilder
{
	public:
		enum VisitedEdgeInfo
		{
			NOT_VISITED = 0,
			VISITED_VISIBLE = 1,
			VISITED_BOUNDARY = 2,
			VISITED_HIDDEN = 3
		};
		struct WeightedLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			WeightedLine* m_source;
			hkUint32 m_lastVertex;
			hkReal m_weight;
		};
		struct WrappingLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			hkUint16 m_leftVertex;
			hkUint16 m_rightVertex;
			hkUint16 m_leftNextEdgeVertex;
			hkUint16 m_rightNextEdgeVertex;
		};
		struct WeightedNeighbour
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_edge;
			hkReal m_weight;
		};
		class PlaneAndPoints
		{
			public:
				                class MustEndWithSemiColon;
				hkVector4 m_planeEquation;
				hkpGeomEdge* m_v0;
				hkpGeomEdge* m_v1;
				hkpGeomEdge* m_v2;
				hkUint16 m_info : 16;
		};
		static hkReal __cdecl getPseudoAngle( hkReal cosTheta, hkReal sinTheta );
};

void __cdecl FUN_00a5a490( const hkVector4& planeEqn, const hkVector4* verticesin, int numverts, hkArray<hkVector4>& usedVertices, hkArray<hkVector4>& planeEquationsOut )
{
	{
		planeEquationsOut.clear();
		hkVector4 reversePlaneEqn; reversePlaneEqn.setNeg4( planeEqn );
		planeEquationsOut.pushBack( planeEqn );
		planeEquationsOut.pushBack( reversePlaneEqn );
	}
	hkArray<hkBool> alreadyVisited( numverts, false );
	int startVertexIndex = -1;
	hkVector4 supportDir;
	if ( hkMath::fabs( 1.0f - hkMath::fabs( planeEqn(2) ) ) < 1e-6f )
	{
		hkVector4 crossWithDir; crossWithDir.set( 1.0f, 0.0f, 0.0f, 0.0f );
		supportDir.setCross( crossWithDir, planeEqn );
	}
	else
	{
		hkVector4 crossWithDir; crossWithDir.set( 0.0f, 0.0f, 1.0f, 0.0f );
		supportDir.setCross( planeEqn, crossWithDir );
	}
	{
		hkReal maxDot = -3.40282e+38f;
		for ( int i = 0; i < numverts; i++ )
		{
			hkReal curDot = verticesin[i].dot3( supportDir );
			if ( curDot > maxDot )
			{
				maxDot = curDot;
				startVertexIndex = i;
			}
		}
	}
	alreadyVisited[startVertexIndex] = true;
	usedVertices.pushBack( verticesin[startVertexIndex] );
	hkVector4 currentDir;
	currentDir.setCross( supportDir, planeEqn ); currentDir.add4( supportDir );
	int currentVertexIndex = startVertexIndex;
	int previousVertexIndex = startVertexIndex;
	int firstVertexIndex = -1; int closestVertexIndex = -1;
	hkBool finished = false;
	while ( !finished )
	{	hkReal currentSine = -2.0f;
		{
			currentDir.normalize3();
			hkVector4 endPoint; endPoint.setAdd4( verticesin[currentVertexIndex], currentDir );
			endPoint(3) = 1.0f;
		}
		hkVector4 toVertexV;
		hkVector4 crossToVertexV;
		hkReal dotToVertexV;
		hkReal minAngle = 3.40282e+38f;
		for ( int v = 0; v < numverts; v++ )
		{
			if ( v != currentVertexIndex )
			{
				toVertexV.setSub4( verticesin[v], verticesin[currentVertexIndex] );
				crossToVertexV.setCross( currentDir, toVertexV );
				dotToVertexV = currentDir.dot3( toVertexV );
				hkReal sinTheta;
				hkReal cosTheta;
				{
					hkReal lenToV = toVertexV.length3();
					hkReal lenCrossToV = crossToVertexV.length3();
					sinTheta = lenCrossToV / lenToV;
					cosTheta = dotToVertexV / lenToV;
					if ( crossToVertexV.dot3( planeEqn ) > 0.0f )
					{
						sinTheta *= -1.0f;
					}
				}
				hkReal angleToV = hkpGeomConvexHullBuilder::getPseudoAngle( cosTheta, sinTheta );
				if ( angleToV < minAngle )
				{
					minAngle = angleToV;
					closestVertexIndex = v;
					currentSine = sinTheta;
				}
			}
		}
		if ( currentVertexIndex != startVertexIndex )
		{
			hkVector4 edge; edge.setSub4( verticesin[currentVertexIndex], verticesin[previousVertexIndex] );
			hkVector4 awayDir; awayDir.setSub4( verticesin[currentVertexIndex], verticesin[closestVertexIndex] );
			hkVector4& newBevelPlane = planeEquationsOut.expandOne();
			{	hkVector4 planarPlane;
				if ( previousVertexIndex != closestVertexIndex )
				{
					planarPlane.setCross( edge, awayDir );
				}
				else
				{
					planarPlane = planeEqn;
				}
				newBevelPlane.setCross( edge, planarPlane );
				hkReal planeDir = ( newBevelPlane.dot3( awayDir ) < 1e-6f ) ? -1.0f : 1.0f;
				newBevelPlane.mul4( planeDir );
				newBevelPlane.normalize3();
				newBevelPlane(3) = -newBevelPlane.dot3( verticesin[currentVertexIndex] );
			}
		}
		else
		{
			firstVertexIndex = closestVertexIndex;
		}
		if ( alreadyVisited[closestVertexIndex] )
		{
			finished = true;
		}
		else
		{
			hkVector4 toClosest;
			alreadyVisited[closestVertexIndex] = true;
			usedVertices.pushBack( verticesin[closestVertexIndex] );
			toClosest.setSub4( verticesin[closestVertexIndex], verticesin[currentVertexIndex] );
			toClosest.normalize3();
			if ( currentSine < 1e-4f )
			{
				currentDir = toClosest;
			}
			else
			{
				currentDir.setAdd4( toClosest, currentDir );
			}
			previousVertexIndex = currentVertexIndex;
			currentVertexIndex = closestVertexIndex;
		}
	}
	{
		hkVector4 edge; edge.setSub4( verticesin[closestVertexIndex], verticesin[currentVertexIndex] );
		hkVector4 awayDir; awayDir.setSub4( verticesin[closestVertexIndex], verticesin[firstVertexIndex] );
		hkVector4& newBevelPlane = planeEquationsOut.expandOne();
		{
			newBevelPlane.setCross( edge, planeEquationsOut[0] );
			hkReal planeDir = ( newBevelPlane.dot3( awayDir ) < 1e-6f ) ? -1.0f : 1.0f;
			newBevelPlane.mul4( planeDir );
			newBevelPlane.normalize3();
			newBevelPlane(3) = -newBevelPlane.dot3( verticesin[closestVertexIndex] );
		}
	}
}
}

// @f3 0x00a5e880 (community match, verified in this file)
// FUN_00a5e880 = Havok 5.5.0 hkpGeomConvexHullBuilder::mergeHulls (hkpInternal.lib, hkpGeomConvexHullBuilder.obj).
// Written from the Havok 5.5.0 SDK headers, the pdb type records and the hybrid library object's debug records,
// cut to one file with hktrim.py. Called helpers of the same object are written
// out after it in record-line order (findWeightedNeighbours 2390, removeCoPlanarNeighbours 2443,
// calculateNewNeighbours 2481, validateNeighbours 2548, addWrappingLines 2615, getAngleBetweenVertexAndPlane 3029).
extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}
namespace f3m_00a5e880 {
typedef float  hkReal;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

			typedef unsigned __w64 hk_size_t;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
};


		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		  __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); }     __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; }       class MustEndWithSemiColon;
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void clear();
		__forceinline void pushBack(const T& e);
		__forceinline void reserve(int size);
		__forceinline void setSize(int size);
		__forceinline void setSizeUnchecked(int size);
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline ~hkInplaceArray(){}
	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::_reserve(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T>
__forceinline T* hkArray<T>::expandBy( int n )
{
	int oldsize = m_size;
	setSize( oldsize + n );
	return m_data+oldsize;
}

template <typename T>
__forceinline void hkArray<T>::setSizeUnchecked(int n)
{
	;
	m_size = n;
}

template <typename T>
__forceinline T* hkArray<T>::expandByUnchecked( int n )
{
	int oldsize = m_size;
	setSizeUnchecked( oldsize + n );
	return m_data+oldsize;
}

template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

extern "C" {
 double  __cdecl fabs(     double _X);
        double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
	}
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline const hkReal& hkVector4::operator() (int i) const
{
	;
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}

void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}

void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}

template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}

template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}

namespace hkAlgorithm
{
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
	template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}

namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}

class hkpGeomEdge
{
	public:
		                class MustEndWithSemiColon;
		inline const hkVector4* getVertex( const hkVector4* vertexBase ) const { return vertexBase + m_vertex; }
		inline hkpGeomEdge* getMirror( hkpGeomEdge* edgeBase ) const { return edgeBase + m_mirror; }
		inline hkpGeomEdge* getNext( hkpGeomEdge* edgeBase ) const { return edgeBase + m_next; }
		hkUint16 m_vertex;
		hkUint16 m_mirror;
		hkUint16 m_next;
		hkUint16 m_info : 16;
};

class hkpGeomHull
{
	public:
		                class MustEndWithSemiColon;
		struct WrappingEdge;
		hkVector4* m_vertexBase;
		hkInplaceArray<hkpGeomEdge,128> m_edges;
};

struct hkpGeomConvexHullTolerances
{
	                class MustEndWithSemiColon;
	hkBool m_postFilter;
	hkBool m_runConvertToUnitCube;
	hkBool m_accurateButSlow;
	hkReal m_weld_tolerance;
	hkReal m_degenerate_tolerance;
	hkReal m_coplanar_vertices_tolerance;
	hkReal m_coplanar_plane_tolerance;
	hkReal m_coplanar_tolerance;
	hkReal m_oppositeNormal_tolerance;
	hkReal m__min_proj;
	hkReal m__maxAngle;
	hkReal m__planeEqnMinLength;
	hkReal m__tol;
	hkReal m__tol2;
	hkReal m__tol3;
};

struct hkpGeomConvexHullConfig
{
	                class MustEndWithSemiColon;
	hkReal m_maxAngle;
	hkReal m_lineLengthImportance;
	int m_maxIterations;
};

class hkpGeomConvexHullBuilder
{
	public:
		struct WeightedLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			WeightedLine* m_source;
			hkUint32 m_lastVertex;
			hkReal m_weight;
			inline hkBool vertsAndVertexEqual( const WeightedLine& other )
			{
				return m_leftEdge->m_vertex == other.m_leftEdge->m_vertex && m_rightEdge->m_vertex == other.m_rightEdge->m_vertex && m_lastVertex == other.m_lastVertex;
			}
		};
		struct WrappingLine
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_leftEdge;
			hkpGeomEdge* m_rightEdge;
			hkUint16 m_leftVertex;
			hkUint16 m_rightVertex;
			hkUint16 m_leftNextEdgeVertex;
			hkUint16 m_rightNextEdgeVertex;
		};
		struct WeightedNeighbour
		{
			                class MustEndWithSemiColon;
			hkpGeomEdge* m_edge;
			hkReal m_weight;
		};
		class PlaneAndPoints;
		static hkBool __cdecl isSingleLine( hkReal tolerance, hkpGeomHull& lhull, hkpGeomHull& rhull, hkpGeomHull& hullOut );
		static void __cdecl getCommonTangent( hkpGeomHull& lhull, hkpGeomHull& rhull, WeightedLine& line, hkVector4& planeEquation );
		static void __cdecl findWeightedNeighbours( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& hull, const hkVector4& planeEquation, const hkUint16 lastVertex, const hkpGeomEdge* edge, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& neighbours );
		static void __cdecl removeCoPlanarNeighbours( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& hull, const hkVector4& planeEquation, const hkpGeomEdge* startPoint, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& neighbours );
		static void __cdecl calculateNewNeighbours( const hkVector4* vertexBase, const hkpGeomConvexHullTolerances& tolerances, hkReal lowestWeight, const hkVector4& planeEquation, const hkpGeomEdge* startPoint, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& neighbours );
		static hkReal __cdecl getAngleBetweenVertexAndPlane( const hkpGeomConvexHullTolerances& tolerances, const hkVector4& vertex, const hkVector4& planeEquation, const hkVector4& tangentStart, const hkVector4& tangentEnd );
		static void __cdecl validateNeighbours( const hkpGeomConvexHullTolerances& tolerances, const hkVector4* vertexBase, const hkVector4& planeEquation, const hkUint16 lastVertex, WeightedLine* sourceLine, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& leftNeighbours, hkArray<WeightedNeighbour>& rightNeighbours );
		static void __cdecl addWrappingLines( const hkpGeomConvexHullConfig& config, WeightedLine* sourceLine, hkArray<WeightedNeighbour>& leftNeighbours, hkArray<WeightedNeighbour>& rightNeighbours, hkArray<WeightedLine>& newLines );
		static void __cdecl findWrapping( hkpGeomHull& lhull, hkpGeomHull& rhull, const hkArray<WeightedLine>& lines, hkArray<WrappingLine>& wrapping );
		static void __cdecl stitchHulls( hkpGeomHull& lhull, hkpGeomHull& rhull, hkArray<WrappingLine>& wrapping, hkpGeomHull& hullOut );
};

hkBool weightedNeighbourLess( const hkpGeomConvexHullBuilder::WeightedNeighbour& a, const hkpGeomConvexHullBuilder::WeightedNeighbour& b );
hkBool weightedLineLess( const hkpGeomConvexHullBuilder::WeightedLine& a, const hkpGeomConvexHullBuilder::WeightedLine& b );

// pdb: hkGeomConvexHullBuilder::mergeHulls | hkGeomConvexHullBuilder.obj | tesv_win, call_gap_sim, low
hkResult __cdecl FUN_00a5e880( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& lhull, hkpGeomHull& rhull, hkpGeomHull& hullOut )
{
	hullOut.m_vertexBase = lhull.m_vertexBase;
	if ( hkpGeomConvexHullBuilder::isSingleLine( tolerances.m_degenerate_tolerance, lhull, rhull, hullOut ) )
	{
		return HK_SUCCESS;
	}
	const hkVector4* vertexBase = lhull.m_vertexBase;
	typedef hkInplaceArray<hkpGeomConvexHullBuilder::WeightedLine,16> TangentArray;
	hkVector4 startPlaneEquation;
	hkInplaceArray<hkpGeomConvexHullBuilder::WeightedLine,1> firstTangentLines;
	{
		hkpGeomConvexHullBuilder::WeightedLine& startLine = *firstTangentLines.expandByUnchecked(1);
		hkpGeomConvexHullBuilder::getCommonTangent( lhull, rhull, startLine, startPlaneEquation );
	}
	hkVector4 previousPlaneEquation = startPlaneEquation;
	hkInplaceArray<TangentArray*,64> allTangentArrays;
	int maximumExpectedWrappingLength = lhull.m_edges.getSize() + rhull.m_edges.getSize() + 2;
	hkpGeomConvexHullConfig config;
	config.m_maxAngle = tolerances.m__maxAngle;
	config.m_maxIterations = maximumExpectedWrappingLength * 3;
	hkInplaceArray<hkpGeomConvexHullBuilder::WrappingLine,128> wrapping;
	hkArray<hkpGeomConvexHullBuilder::WeightedLine>* currentTangentLines = &firstTangentLines;
	int wrappingLengthWithHighAngle = 0;
	for ( int wrappingLength = 0; wrappingLengthWithHighAngle < config.m_maxIterations; wrappingLength++ )
	{
		if ( wrappingLength > maximumExpectedWrappingLength )
		{
			config.m_maxAngle *= 1.1f;
			if ( config.m_maxAngle > 1.0f )
			{
				maximumExpectedWrappingLength++;
			}
		}
		{
			TangentArray* nextTangentLines = hkAllocateStack<TangentArray>(1);
			new (nextTangentLines) TangentArray();
			allTangentArrays.pushBack( nextTangentLines );
			for ( int tanIter = 0; tanIter < currentTangentLines->getSize(); tanIter++ )
			{
				hkpGeomConvexHullBuilder::WeightedLine* sourceLine = &(*currentTangentLines)[tanIter];
				hkInplaceArray<hkpGeomConvexHullBuilder::WeightedNeighbour,64> leftNeighbours;
				hkInplaceArray<hkpGeomConvexHullBuilder::WeightedNeighbour,64> rightNeighbours;
				const hkVector4* tangentStart = sourceLine->m_leftEdge->getVertex( vertexBase );
				const hkVector4* tangentEnd = sourceLine->m_rightEdge->getVertex( vertexBase );
				hkVector4 tangentPlaneEquation;
				if ( sourceLine->m_source )
				{
					const hkVector4* a = sourceLine->m_source->m_leftEdge->getVertex( vertexBase );
					const hkVector4* b = sourceLine->m_source->m_rightEdge->getVertex( vertexBase );
					const hkVector4* c = ( a == tangentStart ) ? tangentEnd : tangentStart;
					hkVector4 tangentDir; tangentDir.setSub4( *b, *a ); tangentDir.normalize3();
					hkVector4 other; other.setSub4( *c, *a ); other.normalize3();
					tangentPlaneEquation.setCross( tangentDir, other );
					const hkReal planeEqnMinLength = 1e-6f;
					if ( tangentPlaneEquation.lengthSquared3() < planeEqnMinLength )
					{
						other.setSub4( *c, *b ); other.normalize3();
						tangentPlaneEquation.setCross( tangentDir, other );
						if ( tangentPlaneEquation.lengthSquared3() < planeEqnMinLength )
						{
							hkVector4 newTangentDir;
							hkVector4 newOther; newOther.setAdd4( tangentDir, other );
							newTangentDir.setSub4( tangentDir, other );
							if ( newTangentDir.lengthSquared3() < planeEqnMinLength || newOther.lengthSquared3() < planeEqnMinLength )
							{
								tangentPlaneEquation = previousPlaneEquation;
							}
							else
							{
								newOther.normalize3();
								newTangentDir.normalize3();
								tangentPlaneEquation.setCross( newTangentDir, newOther );
							}
						}
					}
					tangentPlaneEquation.normalize3();
				}
				else
				{
					tangentPlaneEquation = startPlaneEquation;
				}
				previousPlaneEquation = tangentPlaneEquation;
				hkpGeomConvexHullBuilder::findWeightedNeighbours( tolerances, lhull, tangentPlaneEquation, sourceLine->m_lastVertex, sourceLine->m_leftEdge, tangentStart, tangentEnd, leftNeighbours );
				hkpGeomConvexHullBuilder::findWeightedNeighbours( tolerances, rhull, tangentPlaneEquation, sourceLine->m_lastVertex, sourceLine->m_rightEdge, tangentStart, tangentEnd, rightNeighbours );
				hkpGeomConvexHullBuilder::validateNeighbours( tolerances, rhull.m_vertexBase, tangentPlaneEquation, sourceLine->m_lastVertex, sourceLine, tangentStart, tangentEnd, leftNeighbours, rightNeighbours );
				hkpGeomConvexHullBuilder::addWrappingLines( config, sourceLine, leftNeighbours, rightNeighbours, *nextTangentLines );
			}
			currentTangentLines = nextTangentLines;
		}
		hkAlgorithm::quickSort( currentTangentLines->begin(), currentTangentLines->getSize(), weightedLineLess );
		hkpGeomConvexHullBuilder::findWrapping( lhull, rhull, *currentTangentLines, wrapping );
		if ( wrapping.getSize() )
		{
			break;
		}
	}
	for ( int i = allTangentArrays.getSize() - 1; i >= 0; i-- )
	{
		allTangentArrays[i]->~TangentArray();
		hkDeallocateStack( allTangentArrays[i] );
	}
	allTangentArrays.clear();
	if ( wrapping.getSize() )
	{
		hkpGeomConvexHullBuilder::stitchHulls( lhull, rhull, wrapping, hullOut );
		return HK_SUCCESS;
	}
	return HK_FAILURE;
}

void hkpGeomConvexHullBuilder::findWeightedNeighbours( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& hull, const hkVector4& tangentPlaneEquation, const hkUint16 lastVertex, const hkpGeomEdge* startPoint, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& neighboursOut )
{
	if ( hull.m_edges.getSize() == 1 ) return;
	hkpGeomEdge* edgeBase = hull.m_edges.begin();
	const hkVector4* vertexBase = hull.m_vertexBase;
	hkpGeomEdge* startNeighbour = startPoint->getMirror( edgeBase );
	hkpGeomEdge* currentNeighbour = startNeighbour;
	do
	{
		const hkVector4& vertex = *currentNeighbour->getVertex( vertexBase );
		hkReal angleI;
		if ( currentNeighbour->m_vertex == lastVertex )
		{
			angleI = 4.0f;
		}
		else
		{
			angleI = getAngleBetweenVertexAndPlane( tolerances, vertex, tangentPlaneEquation, *tangentStart, *tangentEnd );
		}
		WeightedNeighbour& wn = *neighboursOut.expandBy(1);
		wn.m_edge = currentNeighbour;
		wn.m_weight = angleI;
		currentNeighbour = currentNeighbour->getNext( edgeBase )->getMirror( edgeBase );
	} while ( currentNeighbour != startNeighbour );
	hkAlgorithm::quickSort( neighboursOut.begin(), neighboursOut.getSize(), weightedNeighbourLess );
	removeCoPlanarNeighbours( tolerances, hull, tangentPlaneEquation, startPoint, tangentStart, tangentEnd, neighboursOut );
}

void hkpGeomConvexHullBuilder::removeCoPlanarNeighbours( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& hull, const hkVector4& tangentPlaneEquation, const hkpGeomEdge* startPoint, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& neighboursOut )
{	hkVector4* vertexBase = hull.m_vertexBase;
	hkReal epsilon = tolerances.m_coplanar_vertices_tolerance;
	if ( neighboursOut.getSize() > 1 && neighboursOut[1].m_weight - neighboursOut[0].m_weight < epsilon )
	{
		hkInplaceArray<WeightedNeighbour,64> coplanarNeighbours;
		hkReal lowestWeight = neighboursOut[0].m_weight;
		for ( int i = 0; i < neighboursOut.getSize(); i++ )
		{
			if ( neighboursOut[i].m_weight - lowestWeight > epsilon ) break;
			coplanarNeighbours.pushBack( neighboursOut[i] );
		}
		calculateNewNeighbours( vertexBase, tolerances, lowestWeight, tangentPlaneEquation, startPoint, tangentStart, tangentEnd, coplanarNeighbours );
		neighboursOut[0] = coplanarNeighbours[0];
		neighboursOut[0].m_weight = lowestWeight;
		neighboursOut.setSize(1);
	}
}

void hkpGeomConvexHullBuilder::calculateNewNeighbours( const hkVector4* vertexBase, const hkpGeomConvexHullTolerances& tolerances, hkReal lowestWeight, const hkVector4& tangentPlaneEquation, const hkpGeomEdge* startPoint, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& neighboursOut )
{
	hkReal epsilon = tolerances.m_coplanar_vertices_tolerance;
	{
		const hkVector4* startVertex = startPoint->getVertex( vertexBase );
		hkVector4 tangentEquation = tangentPlaneEquation;
		hkVector4 newTangentStart;
		hkVector4 newTangentEnd;
		{
			hkVector4 newOtherTangentPoint; newOtherTangentPoint.setSub4( *tangentStart, *tangentEnd );
			if ( lowestWeight < epsilon || lowestWeight > 8.0f - epsilon )
			{
				tangentEquation.setCross( tangentEquation, newOtherTangentPoint );
				tangentEquation.normalize3();
			}
			else if ( hkMath::fabs( lowestWeight - 4.0f ) < epsilon )
			{
				tangentEquation.setCross( newOtherTangentPoint, tangentEquation );
				tangentEquation.normalize3();
			}
			newOtherTangentPoint.setCross( tangentEquation, newOtherTangentPoint );
			newOtherTangentPoint.add4( *startVertex );
			if ( startVertex == tangentStart )
			{
				newTangentStart = newOtherTangentPoint;
			}
			else
			{
				newTangentStart = *startVertex;
			}
			if ( startVertex == tangentStart )
			{
				newTangentEnd = *startVertex;
			}
			else
			{
				newTangentEnd = newOtherTangentPoint;
			}
		}
		for ( int j = 0; j < neighboursOut.getSize(); j++ )
		{
			const hkVector4& vertex = *neighboursOut[j].m_edge->getVertex( vertexBase );
			hkReal angleI = getAngleBetweenVertexAndPlane( tolerances, vertex, tangentEquation, newTangentStart, newTangentEnd );
			neighboursOut[j].m_weight = angleI;
		}
	}
	hkAlgorithm::quickSort( neighboursOut.begin(), neighboursOut.getSize(), weightedNeighbourLess );
}

void hkpGeomConvexHullBuilder::validateNeighbours( const hkpGeomConvexHullTolerances& tolerances, const hkVector4* vertexBase, const hkVector4& tangentPlaneEquation, const hkUint16 lastVertex, WeightedLine* sourceLine, const hkVector4* tangentStart, const hkVector4* tangentEnd, hkArray<WeightedNeighbour>& leftNeighboursOut, hkArray<WeightedNeighbour>& rightNeighboursOut )
{
	if ( leftNeighboursOut.getSize() == 1 && rightNeighboursOut.getSize() == 1 )
	{
		hkpGeomEdge* startPoint = sourceLine->m_leftEdge;
		if ( sourceLine->m_source )
		{
			if ( lastVertex != 0xffff && sourceLine->m_source->m_rightEdge->m_vertex == lastVertex )
			{
				startPoint = sourceLine->m_rightEdge;
			}
		}
		hkReal epsilon = tolerances.m_coplanar_vertices_tolerance;
		if ( hkMath::fabs( leftNeighboursOut[0].m_weight - rightNeighboursOut[0].m_weight ) < epsilon )
		{
			hkInplaceArray<WeightedNeighbour,2> coplanarNeighbours;
			hkReal lowestWeight = rightNeighboursOut[0].m_weight;
			coplanarNeighbours.pushBack( leftNeighboursOut[0] );
			coplanarNeighbours.pushBack( rightNeighboursOut[0] );
			calculateNewNeighbours( vertexBase, tolerances, lowestWeight, tangentPlaneEquation, startPoint, tangentStart, tangentEnd, coplanarNeighbours );
			if ( coplanarNeighbours[0].m_edge == leftNeighboursOut[0].m_edge )
			{
				leftNeighboursOut[0].m_weight *= 0.5f;
			}
			else
			{
				rightNeighboursOut[0].m_weight *= 0.5f;
			}
		}
	}
}

void hkpGeomConvexHullBuilder::addWrappingLines( const hkpGeomConvexHullConfig& config, WeightedLine* sourceLine, hkArray<WeightedNeighbour>& leftN, hkArray<WeightedNeighbour>& rightN, hkArray<WeightedLine>& wrappingLinesOut )
{
	hkReal minAngle;
	if ( leftN.getSize() == 0 )
	{
		minAngle = rightN[0].m_weight;
	}
	else if ( rightN.getSize() == 0 )
	{
		minAngle = leftN[0].m_weight;
	}
	else
	{
		minAngle = hkMath::min2( leftN[0].m_weight, rightN[0].m_weight );
	}
	{
		hkpGeomEdge* rightEdge = sourceLine->m_rightEdge;
		for ( int il = 0; il < leftN.getSize(); il++ )
		{
			hkReal diffAngle = leftN[il].m_weight - minAngle;
			if ( diffAngle > config.m_maxAngle )
			{
				break;
			}
			WeightedLine wrappingLine;
			wrappingLine.m_weight = diffAngle + sourceLine->m_weight;
			wrappingLine.m_leftEdge = leftN[il].m_edge;
			wrappingLine.m_rightEdge = rightEdge;
			wrappingLine.m_source = sourceLine;
			wrappingLine.m_lastVertex = sourceLine->m_leftEdge->m_vertex;
			hkBool foundWrappingLine = false;
			for ( int iw = 0; iw < wrappingLinesOut.getSize(); iw++ )
			{
				if ( wrappingLinesOut[iw].vertsAndVertexEqual( wrappingLine ) )
				{
					if ( wrappingLinesOut[iw].m_weight < wrappingLine.m_weight )
					{
						wrappingLinesOut[iw] = wrappingLine;
					}
					foundWrappingLine = true;
					break;
				}
			}
			if ( !foundWrappingLine )
			{
				wrappingLinesOut.pushBack( wrappingLine );
			}
		}
	}
	{
		hkpGeomEdge* leftEdge = sourceLine->m_leftEdge;
		for ( int ir = 0; ir < rightN.getSize(); ir++ )
		{
			hkReal diffAngle = rightN[ir].m_weight - minAngle;
			if ( diffAngle > config.m_maxAngle )
			{
				break;
			}
			WeightedLine wrappingLine;
			wrappingLine.m_weight = diffAngle + sourceLine->m_weight;
			wrappingLine.m_leftEdge = leftEdge;
			wrappingLine.m_rightEdge = rightN[ir].m_edge;
			wrappingLine.m_source = sourceLine;
			wrappingLine.m_lastVertex = sourceLine->m_rightEdge->m_vertex;
			hkBool foundWrappingLine = false;
			for ( int iw = 0; iw < wrappingLinesOut.getSize(); iw++ )
			{
				if ( wrappingLinesOut[iw].vertsAndVertexEqual( wrappingLine ) )
				{
					if ( wrappingLinesOut[iw].m_weight < wrappingLine.m_weight )
					{
						wrappingLinesOut[iw] = wrappingLine;
					}
					foundWrappingLine = true;
					break;
				}
			}
			if ( !foundWrappingLine )
			{
				wrappingLinesOut.pushBack( wrappingLine );
			}
		}
	}
}

hkReal hkpGeomConvexHullBuilder::getAngleBetweenVertexAndPlane( const hkpGeomConvexHullTolerances& tolerances, const hkVector4& vertex, const hkVector4& planeEquation, const hkVector4& tangentStart, const hkVector4& tangentEnd )
{
	hkVector4 relP; relP.setSub4( vertex, tangentStart );
	if ( relP.lengthSquared3() < tolerances.m_degenerate_tolerance )
	{
		return 0.0f;
	}
	relP.normalize3();
	hkReal sinTheta = -planeEquation.dot3( relP );
	hkVector4 edge; edge.setSub4( tangentStart, tangentEnd );
	hkVector4 vInPlane; vInPlane.setCross( edge, planeEquation );
	vInPlane.normalize3();
	hkReal cosTheta = vInPlane.dot3( relP );
	const hkReal DEGENERATE_TRIANGLE_EPS = tolerances.m_degenerate_tolerance;
	if ( sinTheta * sinTheta + cosTheta * cosTheta < DEGENERATE_TRIANGLE_EPS )
	{
		return 3.40282e+38f * 0.5f;
	}
	hkReal tol = 1e-6f;
	hkReal tol2 = 1e-7f;
	hkReal tol3 = tolerances.m__tol3;
	hkReal angle;
	if ( hkMath::fabs( sinTheta ) < tol && hkMath::fabs( cosTheta ) < tol2 )
	{
		angle = ( cosTheta < 0.0f ) ? 4.0f : 0.0f;
	}
	else if ( hkMath::fabs( sinTheta ) > hkMath::fabs( cosTheta ) )
	{
		angle = 2.0f - cosTheta / sinTheta;
		angle += ( sinTheta < -tol ) ? 4.0f : 0.0f;
	}
	else
	{
		angle = sinTheta / cosTheta;
		if ( cosTheta < tol - 1.0f && hkMath::fabs( sinTheta ) < tol )
		{
			angle = 4.0f;
		}
		else
		{
			angle += ( cosTheta < -tol ) ? 4.0f : 0.0f;
		}
		if ( hkMath::fabs( angle ) < tol3 )
		{
			angle = 0.0f;
		}
		else
		{
			angle += ( cosTheta > tol && hkMath::fabs( sinTheta ) < tol2 ) ? 8.0f : 0.0f;
		}
	}
	if ( angle < -tol3 )
	{
		angle += 8.0f;
	}
	if ( angle > 8.0f )
	{
		angle = 0.0f;
	}
	return angle;
}
}

// @f3 0x00a419b0 (community match, verified in this file)
namespace f3m_00a419b0 {
// FUN_00a419b0 = Havok 5.5.0 hk4dGskCollidePointsWithPlane (hkpInternal.lib, hkpContinuousGsk.obj; C linkage in the
// library: _hk4dGskCollidePointsWithPlane). Written from the SDK headers, the library objects' debug records (line
// records 183-353, locals, blocks, call targets) and the type records of hkpInternal.pdb; the .cpp and the header
// that declares the hkp4dGsk structs are not shipped. Reduced from sdk.cpp with hktrim.py. See note.txt.
namespace f3m_00a419b0 {
typedef float  hkReal;

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

typedef hkReal hkSimdReal;

extern "C" {
        double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
	template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
	}
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w  );
}

class hkMotionState;
class hkStepInfo;

namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
}

struct hkp4dGskVertexCollidePointsInput
{
	                class MustEndWithSemiColon;
	hkPadSpu<const hkMotionState*> m_motionA;
	hkPadSpu<const hkMotionState*> m_motionB;
	hkPadSpu<hkVector4*> m_verticesA;
	hkPadSpu<int> m_numVertices;
	hkPadSpu<int> m_allocatedNumVertices;
	hkPadSpu<hkReal> m_radiusSum;
	hkPadSpu<hkReal> m_maxAccel;
	hkPadSpu<hkReal> m_invMaxAccel;
	hkVector4 m_planeB;
	hkVector4 m_pointOnPlaneB;
	hkPadSpu<const hkStepInfo*> m_stepInfo;
	hkPadSpu<hkReal> m_worstCaseApproachingDelta;
	hkVector4 m_linearTimInfo;
	hkVector4 m_deltaAngles[2];
	hkPadSpu<hkReal> m_startRt;
};

struct hkp4dGskTolerances
{
	                class MustEndWithSemiColon;
	hkPadSpu<hkReal> m_toiSeparation;
	hkPadSpu<hkReal> m_minSeparation;
	hkPadSpu<hkReal> m_minSafeDeltaRt;
	hkPadSpu<hkReal> m_minToiDeltaTime;
	hkPadSpu<hkReal> m_toiAccuracy;
};

struct hkp4dGskVertexCollidePointsOutput
{
	                class MustEndWithSemiColon;
	hkPadSpu<hkReal> m_Rtoi;
	hkVector4 m_collidingPoint;
};

struct hk4dGskCollideMatrices
{
	hkTransform m_wTa;
	hkTransform m_wTb;
	hkTransform m_aTb;
	hkVector4 m_plane;
	hkVector4 m_pointOnPlane;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel[2];
	hkVector4 m_massCenterAinA;
	hkVector4 m_massCenterBinA;
};

void hk4dGskCollideInitMatrices( const hkp4dGskVertexCollidePointsInput& input, hkReal Rt, hk4dGskCollideMatrices& mat );
hkReal hk4dGskCollidePointWithPlaneFinal( const hkp4dGskVertexCollidePointsInput& input, const hkp4dGskTolerances& tol, const hkVector4& vertex, hkReal lastT, hkReal Rt, hkReal oldDistance, hkReal distance, hkReal velocity, hkp4dGskVertexCollidePointsOutput& out );

// pdb: hk4dGskCollidePointsWithPlane | hkpContinuousGsk.obj | tesv_win, call_gap, low
void FUN_00a419b0( const hkp4dGskVertexCollidePointsInput& input, const hkp4dGskTolerances& tol, hkp4dGskVertexCollidePointsOutput& out )
{
	hkReal endRt = 1.0f;
	hkReal Rt = input.m_startRt;
	hkReal lastT = Rt;
	int numVerticesA = input.m_numVertices;
	while ( numVerticesA )
	{
		hk4dGskCollideMatrices mat;
		hk4dGskCollideInitMatrices( input, Rt, mat );
		hkVector4* s = input.m_verticesA;
		hkVector4* d = s;
		hkReal timeRemaining = endRt - Rt;
		hkReal worstCaseDelta = timeRemaining * input.m_worstCaseApproachingDelta;
		hkReal nextT = endRt;
		int i = numVerticesA;
		numVerticesA = 0;
		for ( i--; i >= 0; s++, i-- )
		{
			hkReal distance;
			{
				hkVector4 r; r.setSub4( *s, mat.m_pointOnPlane );
				distance = mat.m_plane.dot4xyz1( r );
			}
			if ( distance > worstCaseDelta + tol.m_toiSeparation )
			{
				continue;
			}
			hkReal velocity;
			{
				hkVector4 mrA; mrA.setSub4( *s, mat.m_massCenterAinA );
				hkVector4 mrB; mrB.setSub4( *s, mat.m_massCenterBinA );
				hkVector4 armA; armA.setCross( mat.m_angularVel[0], mrA );
				hkVector4 armB; armB.setCross( mat.m_angularVel[1], mrB );
				hkVector4 vel4; vel4.setSub4( armA, mat.m_linearVel );
				vel4.sub4( armB );
				velocity = vel4.dot3( mat.m_plane );
			}
			const hkReal hitDistance = distance - tol.m_toiSeparation;
			const hkReal hitDistanceAtT1UsingLinearProjection = hitDistance + velocity * timeRemaining;
			const hkReal maxSecondOrderError = timeRemaining * 0.5 * timeRemaining * input.m_maxAccel;
			if ( hitDistanceAtT1UsingLinearProjection > maxSecondOrderError )
			{
				continue;
			}
			if ( distance < tol.m_toiSeparation )
			{
				if ( Rt == input.m_startRt )
				{
					out.m_Rtoi = Rt;
					out.m_collidingPoint = *s;
					endRt = Rt;
				}
				else
				{
					hkReal oldDistance = (*s)(3);
					endRt = hk4dGskCollidePointWithPlaneFinal( input, tol, *s, lastT, Rt, oldDistance, distance, velocity, out );
				}
				continue;
			}
			hkAlgorithm::swap( *s, *d );
			(*d)(3) = distance;
			d++;
			numVerticesA++;
			hkReal timeStep;
			{
				hkReal d0 = distance - tol.m_minSeparation;
				hkReal d1 = tol.m_toiSeparation - tol.m_minSeparation;
				hkReal t0sq = 2.0 * d0 * input.m_invMaxAccel;
				if ( t0sq > timeRemaining * timeRemaining )
				{
					continue;
				}
				hkReal t1sq = 2.0 * d1 * input.m_invMaxAccel;
				hkReal t0 = hkMath::sqrt( t0sq );
				if ( velocity >= 0.0 )
				{
					t0 += velocity * input.m_invMaxAccel * 2.0f;
				}
				else
				{
					hkReal t0x = -velocity * input.m_invMaxAccel;
					t0 = hkMath::max2( t0x, t0 );
				}
				if ( t0 > timeRemaining )
				{
					continue;
				}
				hkReal t1 = hkMath::sqrt( t1sq );
				timeStep = t0 + t1;
				timeStep = hkMath::max2<hkReal>( timeStep, tol.m_minSafeDeltaRt );
			}
			nextT = hkMath::min2( nextT, Rt + timeStep );
		}
		if ( Rt > endRt )
		{
			break;
		}
		if ( Rt == nextT && Rt >= endRt )
		{
			break;
		}
		lastT = Rt;
		Rt = nextT;
		nextT = endRt;
	}
}

} // namespace f3m_00a419b0
}   // namespace f3m_00a419b0

// @f3 0x00a5fae0 (community match, verified in this file)
// FUN_00a5fae0 = Havok 5.5.0 hkpGeomConvexHullBuilder::generateConvexHull (hkpInternal.lib, hkpGeomConvexHullBuilder.obj).
// Written from the SDK headers and the library objects' debug records (the .cpp and the hkpGeomConvexHull* headers
// are not shipped); reduced from sdk.cpp with hktrim.py. Inline bodies are SDK text. See note.txt.
namespace f3m_00a5fae0 {
typedef float  hkReal;
typedef unsigned short	hkUint16;
	typedef unsigned long __w64 hkUlong;

class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		__forceinline ~hkArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void clear();
		__forceinline void pushBack(const T& e);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline ~hkInplaceArray(){}
	public:
		T m_storage[N];
};

template <typename T, unsigned N>
class hkInplaceArrayAligned16 : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline hkInplaceArrayAligned16(int size = 0);
	protected:
		int m_padding;
		__declspec(align(16)) hkReal m_storage[sizeof(T)/sizeof(hkReal) * N];
};

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T, unsigned N>
__forceinline hkInplaceArrayAligned16<T,N>::hkInplaceArrayAligned16(int size)
	: hkArray<T>( (T*)&m_storage[0], size, N)
{
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}


class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

namespace hkAlgorithm
{
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
}

namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess)
{
	int i,j;
	__declspec(align(16)) T str;
begin:
	i = h;
	j = d;
	str = pArr[(d+h)>>1];
	do {
		while ( cmpLess( pArr[j], str) ){ j++; }
		while ( cmpLess( str, pArr[i]) ){ i--; }
		if ( i >= j )
		{
			if ( i != j )
			{
				__declspec(align(16)) T zal;
				T& pi = pArr[i];
				T& pj = pArr[j];
				zal = pi; pi = pj, pj = zal;
			}
			i--;
			j++;
		}
	} while (j <= i);
	if (d < i)
	{
		quickSortRecursive(pArr,d,i, cmpLess);
	}
	if (j < h)
	{
		d = j;
		goto begin;
	}
}
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}

enum hkpGeomConvexHullMode
{
	HK_GEOM_CONVEXHULL_MODE_INVALID,
	HK_GEOM_CONVEXHULL_MODE_FAST,
	HK_GEOM_CONVEXHULL_MODE_ACCURATE_BUT_SLOW,
	HK_GEOM_CONVEXHULL_MODE_MAX_ID
};

class hkpGeomHull;

struct hkpGeomConvexHullTolerances
{
	                class MustEndWithSemiColon;
	hkBool m_postFilter;
	hkBool m_runConvertToUnitCube;
	hkBool m_accurateButSlow;
	hkReal m_weld_tolerance;
	hkReal m_degenerate_tolerance;
	hkReal m_coplanar_vertices_tolerance;
	hkReal m_coplanar_plane_tolerance;
	hkReal m_coplanar_tolerance;
	hkReal m_oppositeNormal_tolerance;
	hkReal m__min_proj;
	hkReal m__maxAngle;
	hkReal m__planeEqnMinLength;
	hkReal m__tol;
	hkReal m__tol2;
	hkReal m__tol3;
	hkpGeomConvexHullTolerances() : m_postFilter( true ), m_weld_tolerance( 2e-5f ), m_degenerate_tolerance( 4e-6f ), m_coplanar_vertices_tolerance( 1e-6f ), m_coplanar_plane_tolerance( 1e-5f ), m_coplanar_tolerance( 0.05f ), m_oppositeNormal_tolerance( 1e-6f ), m__min_proj( 1e-6f ), m__maxAngle( 1e-8f ), m__planeEqnMinLength( 1e-6f ), m__tol( 1e-4f ), m__tol2( 1e-5f ), m__tol3( 2e-5f )
	{
	}
};

class hkpGeomConvexHullTester
{
	public:
		static hkBool __cdecl isValidHull( const hkpGeomConvexHullTolerances& tolerances, const hkVector4* verts, int numVertices, hkpGeomHull& hull, hkArray<hkVector4>& usedVertices );
};

class hkpGeomConvexHullBuilder
{
	public:
		class PlaneAndPoints;
		static void __cdecl FUN_00a5fae0( const hkVector4* verts, int numVertices, hkpGeomHull& hullOut, hkArray<hkVector4>& usedVerticesOut, hkpGeomConvexHullMode mode );
		static void __cdecl buildConvexHull( const hkpGeomConvexHullTolerances& tolerances, const hkVector4* verts, int numVertices, hkpGeomHull& hullOut, hkArray<hkVector4>& usedVerticesOut );
		static hkBool __cdecl buildPlaneEquations( const hkpGeomConvexHullTolerances& tolerances, hkpGeomHull& hull, const hkArray<hkVector4>& usedVertices, hkVector4& planarPlaneEquationOut, hkBool& isPlanarOut, hkArray<hkVector4>& planeEquationsOut, hkArray<PlaneAndPoints>& tangentPlanesOut );
		static void __cdecl weldXsortedVertices( hkReal weldTolerance, hkArray<hkVector4>& verts, int& numVertsOut );
		static hkBool __cdecl vectorLessAndMergeCoordinates( hkVector4& v1, hkVector4& v2 );
		static void __cdecl removeCollinearVertices( hkArray<hkVector4>& verts, hkReal tolerance );
		static void __cdecl generateHullFromPlanarPoints( const hkVector4& planeEquation, const hkVector4* verts, int numVertices, hkArray<hkVector4>& usedVerticesOut, hkArray<hkVector4>& planeEquationsOut );
};

class hkpGeomEdge;

class hkpGeomConvexHullBuilder::PlaneAndPoints
{
	public:
		                class MustEndWithSemiColon;
		hkVector4 m_planeEquation;
		hkpGeomEdge* m_v0;
		hkpGeomEdge* m_v1;
		hkpGeomEdge* m_v2;
		hkUint16 m_info : 16;
};

// pdb: hkGeomConvexHullBuilder::generateConvexHull | hkGeomConvexHullBuilder.obj | tesv_win, uconst, low
void __cdecl hkpGeomConvexHullBuilder::FUN_00a5fae0( const hkVector4* verts, int numVertices, hkpGeomHull& hullOut, hkArray<hkVector4>& usedVerticesOut, hkpGeomConvexHullMode mode )
{
	hkpGeomConvexHullTolerances tolerances;
	tolerances.m_postFilter = false;
	tolerances.m_degenerate_tolerance = 4e-6f;
	tolerances.m_accurateButSlow = ( mode == HK_GEOM_CONVEXHULL_MODE_ACCURATE_BUT_SLOW );
	tolerances.m_runConvertToUnitCube = false;
	hkInplaceArrayAligned16<hkVector4,64> filteredVertices;
	{
		int newNumVertices;
		for ( int iter = 0; iter < numVertices; iter++ )
		{
			filteredVertices.pushBack( verts[iter] );
		}
		hkAlgorithm::quickSort( filteredVertices.begin(), filteredVertices.getSize(), vectorLessAndMergeCoordinates );
		weldXsortedVertices( tolerances.m_weld_tolerance, filteredVertices, newNumVertices );
	}
	hkInplaceArrayAligned16<hkVector4,64> planeEquations;
	hkBool isValidHull = false;
	if ( !isValidHull )
	{
		usedVerticesOut.clear();
		buildConvexHull( tolerances, filteredVertices.begin(), filteredVertices.getSize(), hullOut, usedVerticesOut );
		isValidHull = hkpGeomConvexHullTester::isValidHull( tolerances, filteredVertices.begin(), filteredVertices.getSize(), hullOut, usedVerticesOut );
	}
	if ( !isValidHull && tolerances.m_accurateButSlow )
	{
		planeEquations.clear();
		hkBool isPlanar = false;
		hkInplaceArrayAligned16<PlaneAndPoints,64> tangentPlanes;
		hkVector4 planarPlaneEquation;
		buildPlaneEquations( tolerances, hullOut, usedVerticesOut, planarPlaneEquation, isPlanar, planeEquations, tangentPlanes );
		if ( isPlanar )
		{
			usedVerticesOut.clear();
			removeCollinearVertices( filteredVertices, 0.001f );
			hkInplaceArrayAligned16<hkVector4,64> unusedPlaneEquations;
			generateHullFromPlanarPoints( planarPlaneEquation, filteredVertices.begin(), filteredVertices.getSize(), usedVerticesOut, unusedPlaneEquations );
			isValidHull = hkpGeomConvexHullTester::isValidHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
		}
	}
	if ( tolerances.m_accurateButSlow )
	{
		return;
	}
	tolerances.m_runConvertToUnitCube = true;
	if ( !isValidHull )
	{
		tolerances.m_postFilter = true;
		buildConvexHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
		isValidHull = hkpGeomConvexHullTester::isValidHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
		if ( !isValidHull )
		{
			tolerances.m_degenerate_tolerance = 2e-7f;
			buildConvexHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
			isValidHull = hkpGeomConvexHullTester::isValidHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
			if ( !isValidHull )
			{
				tolerances.m__tol3 = 1e-6f;
				buildConvexHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
				isValidHull = hkpGeomConvexHullTester::isValidHull( tolerances, verts, numVertices, hullOut, usedVerticesOut );
			}
		}
	}
}

} // namespace f3m_00a5fae0
