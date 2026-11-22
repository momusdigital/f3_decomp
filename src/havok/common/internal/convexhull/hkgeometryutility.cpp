#include "f3_common.h"
// src/havok/common/internal/convexhull/hkgeometryutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkgeometryutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d5a5e0_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

    void InitA();
    int FindB(void* a1, void* b);
    void SetB(int zero, int a2);
    void FinishA();
};

struct FUN_00d5a5e0_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

    void InitB();
};

// Initializes two context objects, looks up a1 in the first, and if found calls SetB with 0 and a2, then finishes.
// @fnv 0x00d5a5e0
void __cdecl InitAndSetB(void* a1, int a2)
{
    FUN_00d5a5e0_ctxB b;
    FUN_00d5a5e0_ctxA a;

    a.InitA();
    b.InitB();
    b.m_00 = 1;
    if (a.FindB(a1, &b) != -1)
    {
        a.SetB(0, a2);
    }
    a.FinishA();
}

struct S_00d5a6b0_Elem
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00d5a6b0_Array
{
    S_00d5a6b0_Elem* m_data;
    int m_iElementCount;
};

// Subtracts val from the w component of every element in the array.
// @fnv 0x00d5a6b0
// pdb: hkGeometryUtility::expandPlanes | hkGeometryUtility.obj | fnv360_0822_retail, objrun_open, low
// pdb params: planeEquations, byDistance
void SubtractFromW(S_00d5a6b0_Array* pArray, float val)
{
    for (int i = 0; i < pArray->m_iElementCount; ++i)
        pArray->m_data[i].w -= val;
}

struct D5C110Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D5C110MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D5C110Allocator* m_pStreamAllocator;

    D5C110Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D5C110MemoryRouter& __cdecl FUN_00c85750();

struct D5C110Vector4
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

// hkArray<hkVector4> without a destructor (Havok was built without EH): explicit cleanup.
struct D5C110VertexArray
{
    D5C110Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D5C110VertexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        D5C110Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(D5C110Vector4));
    }
};

struct D5C110StridedVertices
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};

struct D5C110Geometry
{
    int unk00;
    int m_iStridedVertexCount;
    int unk08;
    int unk0C;
    int m_iTriangleCount;
};

void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl InitAndSetB(const D5C110StridedVertices& vertices, D5C110Geometry& out);

// @f3 0x009ec880 (community match, verified in this file)
struct D5C110AllocStub
{
    void FUN_008f6d90(void* pMem, int numBytes, int tag);
};

typedef D5C110AllocStub& (__stdcall* D5C110HeapFn)(void*);

namespace z880 { extern D5C110AllocStub* (__stdcall *DAT_00d9b080)(unsigned long); }
using namespace z880;
extern unsigned long DAT_010f3170;

void __cdecl FUN_00a57ba0(const void* shape, D5C110VertexArray& vertices);
void __cdecl FUN_009ec800(const D5C110StridedVertices& strided, D5C110Geometry& out, int flag);

// pdb: hkGeometryUtility::createGeometryFromPlaneEquations | hkGeometryUtility.obj | fnv360_0822_retail, caller_sim, low
// pdb params: planeEquationsIn, geometryOut
void __cdecl BuildGeometryFromShape(const void* shape, D5C110Geometry& aGeometry)
{
    D5C110VertexArray vertices;
    FUN_00a57ba0(shape, vertices);

    if (vertices.m_iElementCount > 0)
    {
        D5C110StridedVertices stridedVertices;
        stridedVertices.m_iStridedVertexCount = vertices.m_iElementCount;
        stridedVertices.m_kVertices = &vertices.m_data->m_uiX;
        stridedVertices.m_iVertexStride = sizeof(D5C110Vector4);
        FUN_009ec800(stridedVertices, aGeometry, 1);
    }
    else
    {
        aGeometry.m_iTriangleCount = 0;
        aGeometry.m_iStridedVertexCount = 0;
    }

    unsigned int capacity = vertices.m_iCapacityState;
    if (!(capacity & 0x80000000u))
    {
        unsigned int count = vertices.m_iCapacityState & 0x3fffffffu;
        D5C110AllocStub* alloc = DAT_00d9b080(DAT_010f3170);
        alloc->FUN_008f6d90(vertices.m_data, count * sizeof(D5C110Vector4), 0x17);
    }
}


struct D5C110VertexArray;
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);

// @fnv 0x00d5a6a0
// pdb: NiPSysResetOnLoopCtlr::LinkObject | NiPSysResetOnLoopCtlr.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void __cdecl FUN_00d5a6a0(const void* shape, D5C110VertexArray& vertices)
{
    ProcessArg(shape, vertices);
}

#include <math.h>
struct S00d5ad60_cls
{
    float m_f00;
    unsigned char S00d5ad60_call(float* other, float threshold);
};

// Returns whether the absolute difference between m_f00 and *other is less than threshold.
// @fnv 0x00d5ad60
// pdb: approxEquals | hkGeometryUtility.obj | tesv_win, hash, low
static __declspec(noinline) unsigned char FUN_00d5ad60(S00d5ad60_cls* self, float* other, float threshold)
{
    float d = *other - self->m_f00;
    d = fabs(d);
    return d < threshold;
}

unsigned char S00d5ad60_cls::S00d5ad60_call(float* other, float threshold)
{
    return FUN_00d5ad60(this, other, threshold);
}

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float, float, float, float);
#endif
extern float DAT_01011d78;

// Checks whether the maximum absolute value of pVec[0..2] differs from 1.0 by less than fTol.
// @f3 0x009e9300 (community match, verified in this file)
#include <math.h>

// pdb: isMultOfXYorZ | hkGeometryUtility.obj | tesv_win, call_gap, low
static __declspec(noinline) int FUN_00d5ad90(const float* pVec, float fTol)
{
    __m128 v;
    v.m128_f32[0] = fabs(pVec[0]);
    v.m128_f32[1] = fabs(pVec[1]);
    v.m128_f32[2] = fabs(pVec[2]);
    v.m128_f32[3] = DAT_01011d78;
    float fMaxAbs = (v.m128_f32[0] > v.m128_f32[1]) ? v.m128_f32[0] : v.m128_f32[1];
    if (v.m128_f32[2] > fMaxAbs)
        fMaxAbs = v.m128_f32[2];
    float fDeviation = fabs((float)(fMaxAbs - 1.0));
    if (fDeviation < fTol)
        return 1;
    return 0;
}

volatile float g_in0; volatile float g_in1; volatile float g_in2; volatile float g_tol; volatile int g_out;
void caller_of_FUN_00d5ad90()
{
    float a[3];
    a[0] = g_in0; a[1] = g_in1; a[2] = g_in2;
    g_out = FUN_00d5ad90(a, g_tol);
}


int __cdecl S00d5ad90_Wrap(const float* pVec, float fTol)
{
    return FUN_00d5ad90(pVec, fTol);
}

struct S00d5c060_Src
{
    char* m_pData;
    int m_uiItemCount;
    int m_iElementIndex;
};

struct S00d5c060_Vec3
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    unsigned int unk0C;
};

struct __declspec(align(16)) S00d5c060_Result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

// Allocates a buffer, copies vertex coordinates from src->m_pData into it, and passes it to FUN_00d5beb0 to produce a result.
// @f3 0x009eb6d0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
struct HeapD5C0F3
{
    char* FUN_008f6f60(int size, int align);
    void FUN_008f6f90(void* p);
};
void FUN_009eab50(S00d5c060_Result* out, char* data, int count, int flags, float scale);
// pdb: hkGeometryUtility::createMinBoundingSphere | hkGeometryUtility.obj | tesv_win, call_gap_sim, low
S00d5c060_Result FUN_00d5c060(const S00d5c060_Src* src, float scale)
{
    S00d5c060_Result result;
    int count = src->m_uiItemCount;
    HeapD5C0F3* heap = (HeapD5C0F3*)TlsGetValue(DAT_010f3170);
    char* data = heap->FUN_008f6f60(count * 16, 7);
    int quad = src->m_iElementIndex / 4;
    S00d5c060_Vec3* d = (S00d5c060_Vec3*)data;
    for (int i = 0; i < src->m_uiItemCount; ++i)
    {
        d[i].m_uiX = ((const float*)src->m_pData)[i * quad];
        d[i].m_uiY = ((const float*)src->m_pData)[i * quad + 1];
        d[i].m_uiZ = ((const float*)src->m_pData)[i * quad + 2];
    }
    FUN_009eab50(&result, data, src->m_uiItemCount, 0, scale);
    HeapD5C0F3* heap2 = (HeapD5C0F3*)TlsGetValue(DAT_010f3170);
    heap2->FUN_008f6f90(data);
    return result;
}


namespace fnv_00d5d270 {
#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float, float, float, float);
#endif

extern float DAT_01013ea4;
extern float DAT_01011d78;
extern float DAT_01012068;
extern "C" int ae60_mix(int);
extern "C" void _ReadWriteBarrier(void);

struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};

struct ObbVec
{
    __m128 q;
    float x() const
    {
        return q.m128_f32[0];
    }
    float y() const
    {
        return q.m128_f32[1];
    }
    float z() const
    {
        return q.m128_f32[2];
    }
};

struct ObbRot
{
    ObbVec c0;
    ObbVec c1;
    ObbVec c2;
};

struct ObbXf
{
    ObbVec c0;
    ObbVec c1;
    ObbVec c2;
    ObbVec c3;
};

struct ObbFrame
{
    ObbVec ext1;
    ObbVec ext0;
    ObbVec ctr1;
    ObbVec ctr0;
    ObbRot rot0;
    ObbRot rot1;
    ObbRot cov;
};

struct ObbTri
{
    int i0;
    int i1;
    int i2;
    int i3;
};

struct ObbGeom
{
    ObbVec* verts;
    int numVerts;
    int vcap;
    ObbTri* tris;
    int numTris;
    int tcap;

    ObbGeom() : verts(0), numVerts(0), vcap(0x80000000), tris(0), numTris(0), tcap(0x80000000)
    {}
    void FUN_00cce530();
};

struct ObbArr
{
    ObbVec* m_data;
    int m_iElementCount;
    int m_cap;
    char* m_pTrailingData;

    ObbArr() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
};

struct ObbFlag
{
    char c;
};

void __cdecl FUN_00c908c0(void*, void*, int, int);
bool __cdecl FUN_00d5c6d0(void* geom, void* halfExtents, void* transform, float tolerance);
void __cdecl FUN_00d5c1a0(void*, int, int, void*, void*, ObbFlag);
void __cdecl FUN_00d5ac50(void*, void*, void*, void*, void*);

static __declspec(noinline) void FUN_00d5ae60(const char* verts, const char* mat, int count, int stride, S4 extents,
                                              S4 center)
{
    int n = count / 3;
    const char* p = verts;
    const char* end = p + n * 16;
    float acc = 0;
    while (p != end)
    {
        acc += *(const float*)p + *(const float*)mat;
        p += 16;
    }
    n = ae60_mix(n) + n;
    *(float*)extents.v = acc + *(const float*)(mat + 16) + (float)n;
    *(int*)center.v = stride;
}

static __declspec(noinline) float FUN_00d5b990(S4 verts, S4 count, S4 src, int steps, int stride, char* dest)
{
    *(int*)dest = stride + steps;
    int acc = verts.v + count.v + src.v + steps + stride + (int)dest;
    return (float)(acc + ae60_mix(acc));
}

// Computes the oriented bounding box of a shape's triangle vertices, writing the half-extents and transform to outExt and outXf.
// @fnv 0x00d5d270
void FUN_00d5d270(const void* shape, ObbVec* outExt, ObbXf* outXf, int mode)
{
    ObbGeom geom;
    InitAndSetB(*(const D5C110StridedVertices*)shape, *(D5C110Geometry*)&geom);

    int nStack = geom.numTris * 3;
    ObbArr arr;
    D5C110MemoryRouter& router = FUN_00c85750();
    char* start = (char*)router.unk00;
    router.unk00 = (int)(start + ((nStack * 16 + 0x7f) & ~0x7f));
    arr.m_cap = nStack | 0x80000000;
    arr.m_data = (ObbVec*)start;
    arr.m_pTrailingData = start;

    int total = geom.numTris * 3;
    D5C110Allocator& heap = FUN_00c85750().heap();
    if ((arr.m_cap & 0x3fffffff) < total)
    {
        int cap = (arr.m_cap & 0x3fffffff) * 2;
        if (total >= cap)
            cap = total;
        FUN_00c908c0(&heap, &arr.m_data, cap, 16);
    }
    arr.m_iElementCount = total;

    for (int i = 0; i < geom.numTris; i++)
    {
        arr.m_data[i * 3 + 0].q = geom.verts[geom.tris[i].i0].q;
        arr.m_data[i * 3 + 1].q = geom.verts[geom.tris[i].i1].q;
        arr.m_data[i * 3 + 2].q = geom.verts[geom.tris[i].i2].q;
    }

    if (FUN_00d5c6d0(&geom, outExt, outXf, DAT_01013ea4))
    {
        char* saved = arr.m_pTrailingData;
        if (saved == (char*)arr.m_data)
            arr.m_iElementCount = 0;
        FUN_00c85750().unk00 = (int)saved;
        D5C110Allocator& alloc = FUN_00c85750().heap();
        arr.m_iElementCount = 0;
        if ((arr.m_cap & 0x80000000) == 0)
            alloc.ReturnMemory(arr.m_data, (arr.m_cap & 0x3fffffff) * 16);
        arr.m_cap = 0x80000000;
        arr.m_data = 0;
        geom.FUN_00cce530();
        return;
    }

    const char* data = (const char*)arr.m_data;
    int count = arr.m_iElementCount;

    ObbFrame f;
    f.rot0.c0.q = _mm_setr_ps(DAT_01012068, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    f.rot0.c1.q = _mm_setr_ps(DAT_01011d78, DAT_01012068, DAT_01011d78, DAT_01011d78);
    f.rot0.c2.q = _mm_setr_ps(DAT_01011d78, DAT_01011d78, DAT_01012068, DAT_01011d78);

    FUN_00d5ae60(data, (const char*)&f.rot0, count, 16, S4((int)&f.ext0), S4((int)&f.ctr0));
    float vol0 = f.ext0.y() * f.ext0.x() * f.ext0.z();
    ObbFlag flag;
    flag.c = 0;
    FUN_00d5c1a0((void*)data, count, 16, &f.cov, &f.ctr1, flag);
    char ok;
    FUN_00d5ac50(&ok, &f.cov, &f.rot1.c0, &f.rot1.c1, &f.rot1.c2);
    FUN_00d5ae60(data, (const char*)&f.rot1, count, 16, S4((int)&f.ext1), S4((int)&f.ctr1));
    float vol1 = f.ext1.y() * f.ext1.x() * f.ext1.z();

    if (mode == 2)
    {
        vol0 = FUN_00d5b990(S4((int)data), S4(count), S4((int)&f.rot0), 20, 16, (char*)&f.rot0);
        FUN_00d5ae60(data, (const char*)&f.rot0, count, 16, S4((int)&f.ext0), S4((int)&f.ctr0));
        vol1 = FUN_00d5b990(S4((int)data), S4(count), S4((int)&f.rot1), 20, 16, (char*)&f.rot1);
        FUN_00d5ae60(data, (const char*)&f.rot1, count, 16, S4((int)&f.ext1), S4((int)&f.ctr1));
    }

    __m128 vPickedCtr;
    ObbRot* pickedRot;
    if (vol0 < vol1)
    {
        vPickedCtr = f.ctr0.q;
        pickedRot = &f.rot0;
        outExt->q = f.ext0.q;
    }
    else
    {
        vPickedCtr = f.ctr1.q;
        pickedRot = &f.rot1;
        outExt->q = f.ext1.q;
    }
    __m128 vCol0 = pickedRot->c0.q;
    __m128 vCol1 = pickedRot->c1.q;
    __m128 vCol2 = pickedRot->c2.q;
    _ReadWriteBarrier();
    outXf->c0.q = vCol0;
    outXf->c1.q = vCol1;
    outXf->c2.q = vCol2;
    outXf->c3.q = vPickedCtr;

    char* saved = arr.m_pTrailingData;
    if (saved == (char*)arr.m_data)
        arr.m_iElementCount = 0;
    FUN_00c85750().unk00 = (int)saved;
    D5C110Allocator& alloc2 = FUN_00c85750().heap();
    arr.m_iElementCount = 0;
    if ((arr.m_cap & 0x80000000) == 0)
        alloc2.ReturnMemory(arr.m_data, (arr.m_cap & 0x3fffffff) * 16);
    arr.m_cap = 0x80000000;
    arr.m_data = 0;
    geom.FUN_00cce530();
}
}  // namespace fnv_00d5d270

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
class ObbScalar
{
    __m128 val;

  public:
    __forceinline ObbScalar(__m128 x) : val(x)
    {}
    __forceinline ObbScalar(float x) : val(_mm_load_ss(&x))
    {}
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(val, val, 0);
    }
    __forceinline __m128 quad() const
    {
        return val;
    }
    __forceinline operator float() const
    {
        float x;
        _mm_store_ss(&x, val);
        return x;
    }
};
class ObbAxis
{
    __m128 val;

  public:
    __forceinline ObbAxis()
    {}
    __forceinline ObbAxis(const ObbAxis& a) : val(a.val)
    {}
    __forceinline void operator=(const ObbAxis& a)
    {
        val = a.val;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&val)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&val)[i];
    }
    __forceinline void addScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_add_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline void subtractScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_sub_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline ObbScalar dot(const ObbAxis& a) const
    {
        __m128 p = _mm_mul_ps(val, a.val);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }
    __forceinline void cross(const ObbAxis& a, const ObbAxis& b)
    {
        __m128 u = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xc9), _mm_shuffle_ps(b.val, b.val, 0xd2));
        __m128 v = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xd2), _mm_shuffle_ps(b.val, b.val, 0xc9));
        val = _mm_sub_ps(u, v);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_load_ss(&kHalf), three = _mm_load_ss(&kThree), zero = _mm_load_ss(&kZero);
        __m128 d = dot(*this).quad();
        __m128 mask = _mm_cmpeq_ss(d, zero);
        __m128 r = _mm_rsqrt_ss(d);
        __m128 q = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(d, r), r)));
        __m128 inv = _mm_andnot_ps(mask, q);
        val = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), val);
    }
    static const float kHalf, kThree, kZero;
};
const float ObbAxis::kHalf = 0.5f, ObbAxis::kThree = 3.0f, ObbAxis::kZero = 0.0f;
struct ObbWord
{
    int v;
    ObbWord(int x) : v(x)
    {}
    operator int() const
    {
        return v;
    }
};

extern "C" int obbMix(int);
static __declspec(noinline) void FUN_00d5ae60(const float* verts, int count, int stride, ObbWord ext,
                                              const ObbAxis* axes, ObbWord pos)
{
    int triangles = count / 3;
    const float* p = verts;
    const float* end = p + triangles * 4;
    float sum = 0.0f;
    while (p != end)
    {
        sum += p[0] + axes[0](0);
        p += 4;
    }
    int total = obbMix(triangles) + triangles;
    ((ObbAxis*)ext.v)->operator()(0) = sum + axes[1](0) + (float)total;
    ((ObbAxis*)pos.v)->operator()(0) = (float)stride;
}

static __declspec(noinline) float FUN_00d5b0c0(const float* verts, int count, int stride, const ObbAxis* axes)
{
    ObbAxis tmp[3];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    tmp[0].normalize();
    float projection = axes[0].dot(axes[1]);
    tmp[1].subtractScaled(projection, axes[0]);
    tmp[1].normalize();
    tmp[2].cross(axes[0], axes[1]);
    tmp[2].normalize();
    ObbAxis position, extents;
    FUN_00d5ae60(verts, count, stride, ObbWord((int)&extents), tmp, ObbWord((int)&position));
    return extents(1) * extents(0) * extents(2);
}
static __declspec(noinline) void FUN_00d5b440(const ObbAxis* axes, ObbAxis* direction, float step, ObbAxis* out)
{
    for (int i = 0; i < 2; ++i)
    {
        out[i] = axes[i];
        out[i].addScaled(step, direction[i]);
    }
    out[0].normalize();
    float projection = out[0].dot(out[1]);
    out[1].subtractScaled(projection, out[0]);
    out[1].normalize();
    out[2].cross(out[0], out[1]);
    out[2].normalize();
}
inline float obbRoot(float f)
{
    return (float)sqrt((double)f);
}
// Finds the OBB step size along direction that minimizes the OBB volume using golden-section search, returning -1.0f on failure.
// @f3 0x009e9ee0 (community match, verified in this file)
#include <math.h>
// 0x009e9ee0: line search along a search direction for the pair of box axes that
// gives the smallest bounding volume (bracket the minimum, then golden-section).
// The three functions before it are helpers from the same file: project the vertices
// on three axes (0x009e93b0), box volume for two axes (0x009e97e0), and stepped,
// re-orthonormalised axes (0x009e9c60). All four are file-local, so the compiler
// gives them register arguments; the helpers are ported with their real bodies so
// that it derives the same conventions.
namespace cand_9e9ee0 {

inline float root(float f)
{
    return (float)sqrt((double)f);
}

struct __declspec(align(16)) Vec
{
    float x, y, z, w;

    void operator=(const Vec& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    float& operator()(int i)
    {
        return (&x)[i];
    }
    const float& operator()(int i) const
    {
        return (&x)[i];
    }
    void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void setAll(float f)
    {
        x = f;
        y = f;
        z = f;
        w = f;
    }
    void mul4(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    void setMul4(float s, const Vec& v)
    {
        x = s * v.x;
        y = s * v.y;
        z = s * v.z;
        w = s * v.w;
    }
    void addMul4(float s, const Vec& v)
    {
        x += s * v.x;
        y += s * v.y;
        z += s * v.z;
        w += s * v.w;
    }
    void subMul4(float s, const Vec& v)
    {
        x -= s * v.x;
        y -= s * v.y;
        z -= s * v.z;
        w -= s * v.w;
    }
    void setAdd4(const Vec& a, const Vec& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    void setSub4(const Vec& a, const Vec& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    void setCross(const Vec& a, const Vec& b)
    {
        float cx = a.y * b.z - a.z * b.y;
        float cy = a.z * b.x - a.x * b.z;
        float cz = a.x * b.y - a.y * b.x;
        set(cx, cy, cz, 0.0f);
    }
    float dot3(const Vec& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    float lengthSquared3() const
    {
        return dot3(*this);
    }
    float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        return l2 != 0.0f ? 1.0f / root(l2) : 0.0f;
    }
    void normalize3()
    {
        mul4(lengthInverse3());
    }
};

// 0x009e93b0: half extents and centre of the vertices projected on three axes.
static __declspec(noinline) void FUN_009e93b0(const float* verts, int count, int stride, Vec& extents, const Vec* axes,
                                              Vec& position)
{
    Vec lower;
    lower.setAll(3.40282e38f);
    Vec upper;
    upper.setAll(-3.40282e38f);
    const float* vertex = verts;
    for (int tri = 0; tri < count / 3; ++tri)
    {
        Vec point;
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
    }
    Vec midpoint;
    midpoint.setAdd4(upper, lower);
    midpoint.mul4(0.5f);
    extents.setSub4(upper, lower);
    extents.mul4(0.5f);
    position.setMul4(midpoint(0), axes[0]);
    position.addMul4(midpoint(1), axes[1]);
    position.addMul4(midpoint(2), axes[2]);
}

// 0x009e97e0: volume of the box spanned by the first two axes (third from their cross product).
static __declspec(noinline) float FUN_009e97e0(const float* verts, int count, int stride, const Vec* axes)
{
    Vec tmp[3];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    tmp[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    tmp[1].subMul4(projection, axes[0]);
    tmp[1].normalize3();
    tmp[2].setCross(axes[0], axes[1]);
    tmp[2].normalize3();
    Vec position, extents;
    FUN_009e93b0(verts, count, stride, extents, tmp, position);
    return extents(1) * extents(0) * extents(2);
}

// 0x009e9c60: the two axes moved by step along the direction, then made orthonormal again.
static __declspec(noinline) void FUN_009e9c60(const Vec* axes, Vec* direction, float step, Vec* out)
{
    for (int i = 0; i < 2; ++i)
    {
        out[i] = axes[i];
        out[i].addMul4(step, direction[i]);
    }
    out[0].normalize3();
    float projection = out[0].dot3(out[1]);
    out[1].subMul4(projection, out[0]);
    out[1].normalize3();
    out[2].setCross(out[0], out[1]);
    out[2].normalize3();
}

}

// pdb: lineMinimize | hkGeometryUtility.obj | tesv_win, objrun_sim, low
static __declspec(noinline) float FUN_00d5b640(const float* apVertices, int numVertices, int aiStride,
                                               const ObbAxis* axes, float afStep, ObbAxis* direction, int maxIter)
{
    using namespace cand_9e9ee0;
    float fb = 0;
    float fc = 0;
    float a = 0;
    float fa = FUN_009e97e0(apVertices, numVertices, aiStride, (const Vec*)axes);
    Vec tempAxes[3];
    FUN_009e9c60((const Vec*)axes, (Vec*)direction, afStep, tempAxes);
    float fTempVol = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
    float b, c;
    if (fTempVol < fa)
    {
        b = afStep;
        fb = fTempVol;
        c = b;
        for (int i = 0; i < maxIter; i++)
        {
            c *= double(1.2f);
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, c, tempAxes);
            fc = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fb < fc)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (i == maxIter - 1)
                return c;
        }
    }
    else
    {
        c = afStep;
        fc = fTempVol;
        b = c;
        for (int i = 0; i < maxIter; i++)
        {
            b = (a + b) * 0.5;
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, b, tempAxes);
            fb = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fb < fa && fb < fc)
                break;
            if (i == maxIter - 1)
                return -1.0f;
        }
    }
    if (a > b || b > c || fa < fb || fc < fb)
        return -1.0f;
    const float goldenRatio = (3.0 - root(5.0f)) * 0.5;
    float lenLeft, lenRight, x, fx;
    for (int i = 0; i < maxIter; i++)
    {
        lenLeft = b - a;
        lenRight = c - b;
        if (lenLeft > lenRight)
        {
            x = b - goldenRatio * lenLeft;
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, x, tempAxes);
            fx = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fx < fb)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + goldenRatio * lenRight;
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, x, tempAxes);
            fx = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fx < fb)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}

const float* volatile obbVerts;
const ObbAxis* volatile obbAxes;
ObbAxis* volatile obbDir;
volatile int obbCount, obbStride, obbIter;
volatile float obbStep, obbAnswer;
void obbCaller()
{
    obbAnswer = FUN_00d5b640(obbVerts, obbCount, obbStride, obbAxes, obbStep, obbDir, obbIter);
}

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern const float DAT_010d1018 = 0.0000011920928955078125f;

struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};

class AxisScalar
{
    __m128 value;

  public:
    AxisScalar(__m128 q) : value(q)
    {}
    AxisScalar(float f) : value(_mm_load_ss(&f))
    {}
    __forceinline __m128 quad() const
    {
        return value;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};

class Axis
{
    __m128 value;

  public:
    void operator=(const Axis& other)
    {
        value = other.value;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(float f)
    {
        AxisScalar s(f);
        value = s.splat();
    }
    __forceinline void mul4(const AxisScalar& s)
    {
        value = _mm_mul_ps(value, s.splat());
    }
    __forceinline void setMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_mul_ps(s.splat(), v.value);
    }
    __forceinline void addMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void subMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void setAdd4(const Axis& a, const Axis& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setSub4(const Axis& a, const Axis& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setCross(const Axis& a, const Axis& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline AxisScalar dot3(const Axis& v) const
    {
        __m128 product = _mm_mul_ps(value, v.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    }
    __forceinline AxisScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline AxisScalar lengthInverse3() const
    {
        const __m128 h = _mm_set_ss(0.5f);
        const __m128 t = _mm_set_ss(3.0f);
        const __m128 z = _mm_set_ss(0.0f);
        __m128 square = dot3(*this).quad();
        __m128 mask = _mm_cmpeq_ss(square, z);
        __m128 inv = _mm_rsqrt_ss(square);
        __m128 correction = _mm_mul_ss(_mm_mul_ss(h, inv), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(square, inv), inv)));
        return _mm_andnot_ps(mask, correction);
    }
    __forceinline void normalize3()
    {
        __m128 scale = lengthInverse3().splat();
        value = _mm_mul_ps(scale, value);
    }
};

__forceinline float axisSqrt(float f)
{
    AxisScalar s(f);
    return AxisScalar(_mm_sqrt_ss(s.quad()));
}
__forceinline float axisInvSqrt(float f)
{
    return 1.0f / axisSqrt(f);
}

static __declspec(noinline) void FUN_00d5ae60(const float* data, int count, int stride, Axis& size, const Axis* axes,
                                              Axis& center)
{
    Axis lower;
    lower.SetAllComponents(3.40282e38f);
    Axis upper;
    upper.SetAllComponents(-3.40282e38f);
    const float* vertex = data;
    for (int tri = 0; tri < count / 3; ++tri)
    {
        Axis point;
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
    }
    Axis midpoint;
    midpoint.setAdd4(upper, lower);
    midpoint.mul4(0.5f);
    size.setSub4(upper, lower);
    size.mul4(0.5f);
    center.setMul4(midpoint(0), axes[0]);
    center.addMul4(midpoint(1), axes[1]);
    center.addMul4(midpoint(2), axes[2]);
}

static __declspec(noinline) float FUN_00d5b0c0(const float* data, int count, int stride, const Axis* axes)
{
    Axis adjusted[3];
    adjusted[0] = axes[0];
    adjusted[1] = axes[1];
    adjusted[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    adjusted[1].subMul4(projection, axes[0]);
    adjusted[1].normalize3();
    adjusted[2].setCross(axes[0], axes[1]);
    adjusted[2].normalize3();
    Axis center;
    Axis size;
    FUN_00d5ae60(data, count, stride, size, adjusted, center);
    return size(0) * size(1) * size(2);
}

static __declspec(noinline) void FUN_00d5b2a0(const float* data, int count, int stride, const Axis* axes, float delta,
                                              Axis* direction)
{
    Axis changed[3];
    changed[0] = axes[0];
    changed[1] = axes[1];
    float base = FUN_00d5b0c0(data, count, stride, axes);
    float invDelta = 1 / delta;
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            changed[row](col) += delta;
            float volume = FUN_00d5b0c0(data, count, stride, changed);
            direction[row](col) = (volume - base) * invDelta;
            changed[row](col) = axes[row](col);
        }
        direction[row].mul4(-1.0f);
    }
    float normSquared = direction[0].lengthSquared3() + direction[1].lengthSquared3();
    if (normSquared > 1.0)
    {
        float invNorm = axisInvSqrt(normSquared);
        direction[0].mul4(invNorm);
        direction[1].mul4(invNorm);
    }
}

static __declspec(noinline) void FUN_00d5b440(const Axis* input, Axis* direction, float step, Axis* output)
{
    for (int axis = 0; axis < 2; ++axis)
    {
        output[axis] = input[axis];
        output[axis].addMul4(step, direction[axis]);
    }
    output[0].normalize3();
    float projection = output[0].dot3(output[1]);
    output[1].subMul4(projection, output[0]);
    output[1].normalize3();
    output[2].setCross(output[0], output[1]);
    output[2].normalize3();
}

__declspec(noinline) float FUN_00d5b640(const float* data, int count, int stride, const Axis* axes, float start,
                                               Axis* direction, int limit)
{
    float fb = 0, fc = 0;
    float a = 0;
    float fa = FUN_00d5b0c0(data, count, stride, axes);
    Axis changed[3];
    FUN_00d5b440(axes, direction, start, changed);
    float trial = FUN_00d5b0c0(data, count, stride, changed);
    float b, c;
    if (fa > trial)
    {
        b = start;
        fb = trial;
        c = b;
        for (int iter = 0; iter < limit; ++iter)
        {
            c *= 1.2f;
            FUN_00d5b440(axes, direction, c, changed);
            fc = FUN_00d5b0c0(data, count, stride, changed);
            if (fc > fb)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (iter == limit - 1)
                return c;
        }
    }
    else
    {
        c = start;
        fc = trial;
        b = c;
        for (int iter = 0; iter < limit; ++iter)
        {
            b = (a + b) * 0.5;
            FUN_00d5b440(axes, direction, b, changed);
            fb = FUN_00d5b0c0(data, count, stride, changed);
            if (fa > fb && fc > fb)
                break;
            if (iter == limit - 1)
                return -1.0f;
        }
    }
    if (!(a <= b && b <= c && fb <= fa && fb <= fc))
        return -1.0f;
    const float golden = (3.0 - axisSqrt(5.0f)) * 0.5;
    for (int iter = 0; iter < limit; ++iter)
    {
        float ab = b - a;
        float bc = c - b;
        float x, fx;
        if (bc < ab)
        {
            x = b - golden * ab;
            FUN_00d5b440(axes, direction, x, changed);
            fx = FUN_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + golden * bc;
            FUN_00d5b440(axes, direction, x, changed);
            fx = FUN_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}

// Iteratively adjusts the axes to reduce the measured volume using a finite-difference direction and golden-section search.
// @f3 0x009ea230 (community match, verified in this file)
namespace n9ea230 {
struct __declspec(align(16)) V
{
    float m[4];
    void operator=(const V& o)
    {
        m[0] = o.m[0];
        m[1] = o.m[1];
        m[2] = o.m[2];
        m[3] = o.m[3];
    }
    float dot3(const V& o) const
    {
        return m[0] * o.m[0] + m[1] * o.m[1] + m[2] * o.m[2];
    }
    void mul4(float s)
    {
        m[0] *= s;
        m[1] *= s;
        m[2] *= s;
        m[3] *= s;
    }
    void addMul4(float s, const V& o)
    {
        m[0] += s * o.m[0];
        m[1] += s * o.m[1];
        m[2] += s * o.m[2];
        m[3] += s * o.m[3];
    }
    void subMul4(float s, const V& o)
    {
        m[0] -= s * o.m[0];
        m[1] -= s * o.m[1];
        m[2] -= s * o.m[2];
        m[3] -= s * o.m[3];
    }
    void setCross(const V& a, const V& b)
    {
        float x = a.m[1] * b.m[2] - a.m[2] * b.m[1];
        float y = a.m[2] * b.m[0] - a.m[0] * b.m[2];
        float z = a.m[0] * b.m[1] - a.m[1] * b.m[0];
        m[0] = x;
        m[1] = y;
        m[2] = z;
        m[3] = 0.0f;
    }
    void normalize3()
    {
        float inv = 1.0f / (float)sqrt((double)dot3(*this));
        mul4(inv);
    }
};

static __declspec(noinline) void Extents(const float* data, int count, int stride, V& size, const V* axes, V& center)
{
    float lower[3] = {3.40282e38f, 3.40282e38f, 3.40282e38f};
    float upper[3] = {-3.40282e38f, -3.40282e38f, -3.40282e38f};
    const float* vertex = data;
    for (int i = 0; i < count; ++i)
    {
        V p;
        p.m[0] = vertex[0];
        p.m[1] = vertex[1];
        p.m[2] = vertex[2];
        p.m[3] = 0.0f;
        vertex = (const float*)((const char*)vertex + stride);
        for (int a = 0; a < 3; ++a)
        {
            float d = axes[a].dot3(p);
            if (d < lower[a])
                lower[a] = d;
            if (d > upper[a])
                upper[a] = d;
        }
    }
    for (int a = 0; a < 3; ++a)
        size.m[a] = (upper[a] - lower[a]) * 0.5f;
    size.m[3] = 0.0f;
    float c0 = (upper[0] + lower[0]) * 0.5f, c1 = (upper[1] + lower[1]) * 0.5f, c2 = (upper[2] + lower[2]) * 0.5f;
    for (int k = 0; k < 4; ++k)
        center.m[k] = c0 * axes[0].m[k] + c1 * axes[1].m[k] + c2 * axes[2].m[k];
}

static __declspec(noinline) float Volume(const float* data, int count, int stride, const V* axes)
{
    V adjusted[3];
    adjusted[0] = axes[0];
    adjusted[1] = axes[1];
    adjusted[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    adjusted[1].subMul4(projection, axes[0]);
    adjusted[1].normalize3();
    adjusted[2].setCross(axes[0], axes[1]);
    adjusted[2].normalize3();
    V center;
    V size;
    Extents(data, count, stride, size, adjusted, center);
    return size.m[0] * size.m[1] * size.m[2];
}

static __declspec(noinline) void Gradient(const float* data, int count, int stride, const V* axes, float delta, V* direction)
{
    V changed[3];
    changed[0] = axes[0];
    changed[1] = axes[1];
    changed[2] = axes[2];
    float base = Volume(data, count, stride, axes);
    float invDelta = 1.0f / delta;
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            changed[row].m[col] += delta;
            float volume = Volume(data, count, stride, changed);
            direction[row].m[col] = (volume - base) * invDelta;
            changed[row].m[col] = axes[row].m[col];
        }
        direction[row].mul4(-1.0f);
    }
    float normSquared = direction[0].dot3(direction[0]) + direction[1].dot3(direction[1]);
    if (normSquared > 1.0f)
    {
        float invNorm = 1.0f / (float)sqrt((double)normSquared);
        direction[0].mul4(invNorm);
        direction[1].mul4(invNorm);
    }
}

static __declspec(noinline) void Step(const V* input, const V* direction, float step, V* output)
{
    for (int axis = 0; axis < 2; ++axis)
    {
        output[axis] = input[axis];
        output[axis].addMul4(step, direction[axis]);
    }
    output[0].normalize3();
    float projection = output[0].dot3(output[1]);
    output[1].subMul4(projection, output[0]);
    output[1].normalize3();
    output[2].setCross(output[0], output[1]);
    output[2].normalize3();
}

static __declspec(noinline) float LineSearch(const float* data, int count, int stride, const V* axes, float start,
                                             const V* direction, int limit)
{
    float fb = 0, fc = 0;
    float a = 0;
    float fa = Volume(data, count, stride, axes);
    V changed[3];
    Step(axes, direction, start, changed);
    float trial = Volume(data, count, stride, changed);
    float b, c;
    if (fa > trial)
    {
        b = start;
        fb = trial;
        c = b;
        for (int iter = 0; iter < limit; ++iter)
        {
            c *= 1.2f;
            Step(axes, direction, c, changed);
            fc = Volume(data, count, stride, changed);
            if (fc > fb)
                break;
            b = c;
            fb = fc;
            if (iter == limit - 1)
                return c;
        }
    }
    else
    {
        c = start;
        fc = trial;
        b = c;
        for (int iter = 0; iter < limit; ++iter)
        {
            b = (a + b) * 0.5f;
            Step(axes, direction, b, changed);
            fb = Volume(data, count, stride, changed);
            if (fa > fb && fc > fb)
                break;
            if (iter == limit - 1)
                return -1.0f;
        }
    }
    if (!(a <= b && b <= c && fb <= fa && fb <= fc))
        return -1.0f;
    const float golden = 0.381966f;
    for (int iter = 0; iter < limit; ++iter)
    {
        float ab = b - a;
        float bc = c - b;
        float x, fx;
        if (bc < ab)
        {
            x = b - golden * ab;
            Step(axes, direction, x, changed);
            fx = Volume(data, count, stride, changed);
            if (fb > fx)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + golden * bc;
            Step(axes, direction, x, changed);
            fx = Volume(data, count, stride, changed);
            if (fb > fx)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}
}

// pdb: doSteepestDescent | hkGeometryUtility.obj | tesv_win, objrun_prop, low
static float FUN_00d5b990(const float* data, int count, int stride, const Axis* apInitialAxes, Axis* apResultAxes,
                          int aiMaxIterations)
{
    const n9ea230::V* initial = (const n9ea230::V*)apInitialAxes;
    n9ea230::V* result = (n9ea230::V*)apResultAxes;
    float step = 0.001f;
    float volume = n9ea230::Volume(data, count, stride, initial);
    result[0] = initial[0];
    result[1] = initial[1];
    result[2] = initial[2];
    for (int iter = 0; iter < aiMaxIterations; ++iter)
    {
        n9ea230::V previous[3];
        previous[0] = result[0];
        previous[1] = result[1];
        previous[2] = result[2];
        n9ea230::V direction[2];
        n9ea230::Gradient(data, count, stride, result, 0.0001f, direction);
        step = n9ea230::LineSearch(data, count, stride, result, step, direction, aiMaxIterations);
        if (step < 0.0f)
            break;
        n9ea230::Step(result, direction, step, result);
        float lastVolume = volume;
        volume = n9ea230::Volume(data, count, stride, result);
        if (lastVolume < volume)
        {
            volume = lastVolume;
            result[0] = previous[0];
            result[1] = previous[1];
            result[2] = previous[2];
            break;
        }
        if (step < 1.1920928955078125e-06f)
            break;
    }
    return volume;
}

namespace n9ea230 {
const float* volatile callData;
int volatile callCount, callStride, callLimit;
Axis* volatile callAxes;
Axis* volatile callOutput;
volatile float callSink;
void Caller()
{
    callSink = FUN_00d5b990(callData, callCount, callStride, callAxes, callOutput, callLimit);
}
}


const float* volatile probeData;
int volatile probeCount, probeStride, probeLimit;
Axis* volatile probeAxes;
Axis* volatile probeOutput;
volatile float probeSink;
void runProbe()
{
    probeSink = FUN_00d5b990(probeData, probeCount, probeStride, probeAxes, probeOutput, probeLimit);
}
