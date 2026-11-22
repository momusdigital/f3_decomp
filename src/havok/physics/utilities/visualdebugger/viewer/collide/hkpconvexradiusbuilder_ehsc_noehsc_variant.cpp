#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

NineIntegerRecord* __cdecl FUN_00c85750();

void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int newCapacity, int elemSize);

struct hkTransform;

struct hkVector4
{
    float x;
    float y;
    float z;
    float w;

    void FUN_00c7f640(const hkTransform& t, const hkVector4& v);
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArray()
    {
        ClearAndRelease();
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    T* begin()
    {
        return m_data;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkGeometry
{
    hkArray<hkVector4> m_kVertices;
    hkArray<hkVector4> m_uiTriangleCount;

    static void* operator new(unsigned int nbytes)
    {
        return FUN_00c85750()->heap().AllocateMemoryBlock(nbytes);
    }
};

struct FloatArrayDescriptor
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};

struct hkReferencedObject
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
};

struct hkpShape : hkReferencedObject
{
};

struct FUN_00de1d20_Shape : hkpShape
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    FUN_00de1d20_Shape(hkGeometry* geom);
};

struct VertexSource;

void __cdecl FUN_00d5a6a0(const VertexSource* src, hkArray<hkVector4>* verticesOut);
void __cdecl InitAndSetB(const FloatArrayDescriptor& vertices, hkGeometry& geometryOut);

// @f3 0x00a692e0 (community match, verified in this file)
#include <xmmintrin.h>
// 0x00a692e0 - Havok _createConvexDisplayFromPlanes (FNV 0x00de3360): vertices from plane
// equations, transform them, build a convex hkGeometry and wrap it in a display shape.
// xmmintrin.h is part of the real Havok math headers; without it this TU gives the static function a
// different private calling convention (transform in eax instead of on the stack).
struct ArrayA692
{
    hkVector4* m_data;
    int m_size;
    int m_capacityAndFlags;
};
struct FreeElemA692
{
    FreeElemA692* m_next;
};
struct ThreadMemoryA692
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    FreeElemA692* m_freeList50;
    int m_numFree54;
    void FUN_008f6d90(void* p, int nbytes, int cls);
    void* FUN_008f6d30(int nbytes, int cls);
    void* FUN_008f6800(int row, int cls);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long idx);
extern "C" unsigned long DAT_010f3170;
extern void __cdecl FUN_009e8bb0(const VertexSource* planes, ArrayA692* verticesOut);
extern void __cdecl FUN_00901e90(ArrayA692* array, int numElems, int elemSize);
extern void __cdecl FUN_009ec800(void* stridedVerts, hkGeometry* geometry, int mode);
struct VectorA692
{
    float x, y, z, w;
    void hkVector4_setTransformedPos(const hkTransform& t, const VectorA692& v);
};
struct DisplayConvexA692 : hkpShape
{
    DisplayConvexA692* FUN_00a67b10(hkGeometry* geometry);
};
static void FreeArrayA692(hkVector4* data, int n, ThreadMemoryA692* mem)
{
    mem->FUN_008f6d90(data, n * 16, 0x17);
}
static int CapacityA692(const ArrayA692& a)
{
    return a.m_capacityAndFlags & 0x3fffffff;
}
// pdb: hkpConvexRadiusBuilder::getCurrentRawGeometry | hkpConvexRadiusBuilder.obj | fnv360_0822_debug, objrun, low, conflict (bridge: _createConvexDisplayFromPlanes)
// pdb params: displayGeometries
static hkpShape* FUN_00de3360(const VertexSource* src, const hkTransform& transform)
{
    ArrayA692 input = {0, 0, 0x80000000};
    FUN_009e8bb0(src, &input);
    if (input.m_size < 1)
    {
        if ((input.m_capacityAndFlags & 0x80000000) == 0)
            FreeArrayA692(input.m_data, CapacityA692(input), (ThreadMemoryA692*)TlsGetValue(DAT_010f3170));
        return 0;
    }
    ArrayA692 output = {0, 0, 0x80000000};
    int count = input.m_size;
    int capacity = output.m_capacityAndFlags & 0x3fffffff;
    if (capacity < count)
    {
        int cap2 = 2 * capacity;
        int newSize = (count < cap2) ? cap2 : count;
        FUN_00901e90(&output, newSize, 16);
    }
    output.m_size = count;
    for (int i = 0; i < count; ++i)
        ((VectorA692*)output.m_data)[i].hkVector4_setTransformedPos(transform, ((VectorA692*)input.m_data)[i]);

    ThreadMemoryA692* pool = (ThreadMemoryA692*)TlsGetValue(DAT_010f3170);
    hkGeometry* raw;
    if (pool->m_freeList50)
    {
        raw = (hkGeometry*)pool->m_freeList50;
        pool->m_numFree54 -= 1;
        pool->m_freeList50 = pool->m_freeList50->m_next;
    }
    else
    {
        raw = (hkGeometry*)pool->FUN_008f6800(3, 0x27);
    }
    hkGeometry* geometry;
    if (raw)
    {
        raw->m_kVertices.m_data = 0;
        raw->m_kVertices.m_iElementCount = 0;
        raw->m_kVertices.m_iCapacityState = 0x80000000;
        raw->m_uiTriangleCount.m_data = 0;
        raw->m_uiTriangleCount.m_iElementCount = 0;
        raw->m_uiTriangleCount.m_iCapacityState = 0x80000000;
        geometry = raw;
    }
    else
        geometry = 0;

    struct StridedA692
    {
        hkVector4* m_vertices;
        int m_numVertices;
        int m_striding;
    } strided;
    strided.m_numVertices = output.m_size;
    strided.m_striding = 16;
    strided.m_vertices = output.m_data;
    FUN_009ec800(&strided, geometry, 1);

    ThreadMemoryA692* shapePool = (ThreadMemoryA692*)TlsGetValue(DAT_010f3170);
    DisplayConvexA692* shape = (DisplayConvexA692*)shapePool->FUN_008f6d30(0x60, 8);
    shape->m_usMemSizeAndFlags = 0x60;
    shape = shape->FUN_00a67b10(geometry);

    if ((output.m_capacityAndFlags & 0x80000000) == 0)
    {
        int n = CapacityA692(output);
        FreeArrayA692(output.m_data, n, (ThreadMemoryA692*)TlsGetValue(DAT_010f3170));
    }
    if ((input.m_capacityAndFlags & 0x80000000) == 0)
        FreeArrayA692(input.m_data, CapacityA692(input), (ThreadMemoryA692*)TlsGetValue(DAT_010f3170));
    return shape;
}


hkpShape* BuildConvexShapeEntry(const VertexSource* src, const hkTransform& transform)
{
    return FUN_00de3360(src, transform);
}
