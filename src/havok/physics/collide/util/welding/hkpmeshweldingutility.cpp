#include "f3_common.h"
// src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/welding/hkpmeshweldingutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ComparisonResult
{
    bool value;
    ComparisonResult(bool result) : value(result)
    {}
    operator bool() const
    {
        return value;
    }
};

struct S_00ddecf0_Heap;
struct S_00ddecf0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddecf0_Heap* m_pStreamAllocator;
    S_00ddecf0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddecf0_Router* FUN_00c85750();

extern double DAT_010cd5a8;
extern double DAT_0101ff40;

float FUN_00ddd7e0(int a1, int* pOut, float* pF);

// @fnv 0x00dddc40
// pdb: hkpMeshWeldingUtility::calcEdgeAngleBitcode | hkpMeshWeldingUtility.obj | tesv_win, call_gap, low
int GetIndexForValue(int aiArg)
{
    int n;
    float tmp;
    tmp = FUN_00ddd7e0(aiArg, &n, &tmp);
    float r = tmp;

    for (n = 0; n < 31; n++)
    {
        tmp = (float)((double)n * DAT_010cd5a8 - DAT_0101ff40);
        if (r <= tmp)
            goto done;
    }
    return n;
done:
    if (r > 0.0f)
    {
        if (tmp != r)
            n--;
    }
    return n;
}

struct Iface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual Iface* GetSub();
    virtual void* Query(void* key, void* out);
};

struct FlagTag
{
    bool m_bValue;
    FlagTag(bool value) : m_bValue(value)
    {}
    FlagTag(const FlagTag& other) : m_bValue(other.m_bValue)
    {}
};

struct Mgr
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Write(unsigned int hash, FlagTag value);
    virtual void Read(bool* out, unsigned int hash);
};

extern Mgr* DAT_01268360;

__declspec(align(16)) struct QueryBuffer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
};

int FUN_00dde4c0(Iface* self, void* a, void* b, int idx, int zero, int* out);

// Reads a flag, clears it, runs up to three sub-queries via FUN_00dde4c0, sets result false if any returns 1, then restores the flag.
// @f3 0x00a56160 (community match, verified in this file)
struct SubIface
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void* Query(void* key, void* out);
};
struct TopIface
{
    virtual void t00();
    virtual void t04();
    virtual void t08();
    virtual void t0C();
    virtual void t10();
    virtual SubIface* GetSub();
};
extern "C" void FUN_00a55e90_opaque();
// pdb: hkpMeshWeldingUtility::calcBitcodeForTriangleEdge | hkpMeshWeldingUtility.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
__declspec(noinline) char* hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(char* out, Iface* self, void* sub, void* key, int index, int* n, int one)
{
    FUN_00a55e90_opaque();
    *n = *n;
    *out = out != 0;
    return out;
}

// pdb: hkpMeshWeldingUtility::isTriangleWindingValid | hkpMeshWeldingUtility.obj | fnv360_0822_retail, uconst, high
// pdb params: shapeKey, bvTreeShape
// pdb: hkpMeshWeldingUtility::isTriangleWindingValid | hkpMeshWeldingUtility.obj | fnv360_0822_retail, uconst, high (was: CheckSubQueries)
bool* hkpMeshWeldingUtility_isTriangleWindingValid(bool* result, void* key, Iface* self)
{
    QueryBuffer queryBuf;
    TopIface* top = (TopIface*)self;
    void* sub = top->GetSub()->Query(key, &queryBuf);
    bool flag;
    int n = 0;
    DAT_01268360->Read(&flag, 0xfe98751e);
    if (flag)
    {
        Mgr* mgr = DAT_01268360;
        mgr->Write(0xfe98751e, FlagTag(false));
    }
    for (int i = 0; i < 3; i++)
    {
        char out;
        if (!*hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(&out, self, sub, key, i, &n, 1))
        {
            *result = false;
            return result;
        }
    }
    if (flag)
    {
        Mgr* mgr = DAT_01268360;
        mgr->Write(0xfe98751e, FlagTag(true));
    }
    *result = true;
    return result;
}


void* FUN_00c908c0(void* alloc, void* arr, int numElems, int elemSize);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00ddeab0_Elem
{
    int a, b, c;
    S_00ddeab0_Elem()
    {}
};

struct S_00ddeab0
{
    S_00ddeab0_Elem* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void GrowArrayCapacity(void* alloc, int numElems)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < numElems)
        {
            int cap2 = cap + cap;
            int newcap = (numElems < cap2) ? cap2 : numElems;
            FUN_00c908c0(alloc, this, newcap, 12);
        }
    }

    void SpliceElements(void* alloc, int index, int numdel, const S_00ddeab0_Elem* p, int numtoinsert);
};

struct FourFloatVector
{
    float x, y, z, w;
};

struct Transform
{
    int pad[8];
    FourFloatVector v0;
    FourFloatVector v1;
    FourFloatVector v2;
};

struct ObjInner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Transform* GetTransform(void* p1, void* buffer);
};

struct ObjOuter
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ObjInner* GetInner();
};

int FUN_00dde4c0(ObjOuter* p2, Transform* trans, void* p1, int i, void* p3, int* outLocal);

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmple_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" int _mm_movemask_ps(__m128 a);

extern const float DAT_01017d00;
extern const __m128 DAT_01017d10;

class hkBoolDDCE
{
  public:
    hkBoolDDCE(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

struct hkVector4DDCE
{
    __m128 m_vComponents;

    bool equals3(const hkVector4DDCE& v) const
    {
        __m128 t = _mm_sub_ps(m_vComponents, v.m_vComponents);
        t = _mm_and_ps(t, DAT_01017d10);
        const __m128 eps = _mm_load_ps1(&DAT_01017d00);
        return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) == 7;
    }
};

namespace fnv_00ddd940 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
}

typedef float hkReal;

extern __m128 DAT_010c4c00;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        hkReal r;
        _mm_store_ss(&r, s);
        return r;
    }
    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

}  // namespace fnv_00ddd940

struct FUN_00ddea00_src
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
};

__declspec(align(16)) struct FUN_00ddea00_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};

__declspec(align(16)) struct FUN_00ddea00_cls
{
    __m128 m_v00;
    __m128 m_v10;
    __m128 m_v20;
    __m128 m_v30;
    unsigned int m_i40;

    FUN_00ddea00_cls* CopyFromSource(const FUN_00ddea00_src* src);
};

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);

extern "C"
{

    __m128 _mm_set_ss(float);

    __m128 _mm_sub_ps(__m128, __m128);

    __m128 _mm_mul_ps(__m128, __m128);

    __m128 _mm_mul_ss(__m128, __m128);

    __m128 _mm_add_ss(__m128, __m128);

    __m128 _mm_sub_ss(__m128, __m128);

    __m128 _mm_shuffle_ps(__m128, __m128, int);

    __m128 _mm_rsqrt_ss(__m128);

    __m128 _mm_cmpeq_ss(__m128, __m128);

    __m128 _mm_andnot_ps(__m128, __m128);
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

struct ScalarNormal
{
    __m128 q;
    ScalarNormal(__m128 value) : q(value)
    {}
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct NormalVector
{
    __m128 q;
    __forceinline void difference(const NormalVector& a, const NormalVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const NormalVector& a, const NormalVector& b)
    {
        __m128 pos = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 201), _mm_shuffle_ps(b.q, b.q, 210));
        __m128 neg = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 210), _mm_shuffle_ps(b.q, b.q, 201));
        q = _mm_sub_ps(pos, neg);
    }
    __forceinline ScalarNormal dot(const NormalVector& v) const
    {
        __m128 square = _mm_mul_ps(q, v.q);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 85), square);
        return ScalarNormal(_mm_add_ss(_mm_shuffle_ps(square, square, 170), sum));
    }
    __forceinline ScalarNormal inverseLength() const
    {
        __m128 half = _mm_set_ss(DAT_01016248);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 len = dot(*this).q;
        __m128 mask = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, approx), approx));
        return ScalarNormal(_mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, approx), correction)));
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().broadcast(), q);
    }
};

struct S_00ddecf0_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};

__declspec(nothrow) S_00ddecf0_Router* FUN_00c85750();
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize) throw();

struct ArrayAllocator
{
    __forceinline S_00ddecf0_Heap& get(const void*) const
    {
        return FUN_00c85750()->heap();
    }
};
template <typename T> struct SpanStorage
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline SpanStorage() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void dispose(S_00ddecf0_Heap& alloc)
    {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            alloc._bufFree<T>(m_data, capacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void append(S_00ddecf0_Heap& alloc, const T& value)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        T* dest = m_data + m_iElementCount;
        new (dest) T(value);
        ++m_iElementCount;
    }
};
template <typename T, typename A = ArrayAllocator> struct hkArray : SpanStorage<T>
{
    __forceinline hkArray()
    {}
    __forceinline ~hkArray()
    {
        dispose(A().get(this));
    }
    __forceinline void AddBack(const T& value)
    {
        append(A().get(this), value);
    }
};

// FUN_00ddcf60 - "point A is close to one of the three points of the shape
// AND point B is close to one of them as well" test.
//
// The shape object holds three 4-float points at +0x20 / +0x30 / +0x40.
// A point counts as a hit when the x/y/z components of the difference are not
// (movmskps + "and 7" + "cmp 7").
//
// The result byte is written through the first argument; the argument pointer
// is handed back to the caller.

struct Vec4
{
    __m128 v;
};

extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
    float __cdecl Atan2(float y, float x);
}

struct hkVector4q
{
    __m128 m_vComponents;

    hkVector4q()
    {}
    hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }

    __forceinline void setCross(const hkVector4q& a, const hkVector4q& b)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline float dot3(const hkVector4q& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};

static __forceinline float hkAtan2(float y, float x)
{
    return Atan2(y, x);
}
void __cdecl FUN_00ddd620_triNormal(const hkVector4q& a, const hkVector4q& b, const hkVector4q& c,
                                    hkVector4q& normalOut);

// Computes the dihedral angle between two adjacent triangles via their normals and edge cross product, storing sin and cos outputs.
// @fnv 0x00ddd7e0
float FUN_00ddd7e0(const hkVector4q* apVertices, float* sinOut, float* cosOut)
{
    hkVector4q nA;
    hkVector4q nB;
    FUN_00ddd620_triNormal(apVertices[0], apVertices[1], apVertices[2], nA);
    FUN_00ddd620_triNormal(apVertices[1], apVertices[0], apVertices[3], nB);

    hkVector4q edge;
    edge.setSub4(apVertices[1], apVertices[0]);
    edge.normalize3();

    hkVector4q c;
    c.setCross(edge, nA);

    *sinOut = c.dot3(nB);
    *cosOut = nB.dot3(nA);
    return hkAtan2(*sinOut, *cosOut);
}

struct __declspec(align(16)) Row
{
    float x, y, z, w;
};
struct __declspec(align(16)) Matrix44
{
    Row row0, row1, row2, row3;
};

struct __declspec(align(16)) Item
{
    Matrix44 transform;
    int payload;
};

// @f3 0x00a560b0 (community match, verified in this file)
extern float DAT_01065384;
namespace f3m_00a560b0 {
namespace c_00a560b0 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct __declspec(align(16)) ShapeBuffer { int data[0x80]; };
struct Triangle { int unk00[8]; Vec4 v0; Vec4 v1; Vec4 v2; };
struct Container {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual Triangle* GetChildShape(void* key, ShapeBuffer* buf);
};
struct Outer {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual Container* GetContainer();
};
char* __cdecl FUN_00a564b0(char* out, const Vec4* a, const Vec4* b, const Vec4* c, float tol);
char* __cdecl hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(char* out, Outer* outer, Triangle* tri, void* key, int i, int* result, void* p3);
// pdb: hkpMeshWeldingUtility::calcWeldingInfoForTriangle | hkpMeshWeldingUtility.obj | tesv_win, caller_sim, low
short __cdecl FUN_00a560b0(void* key, Outer* outer, void* p3)
{
    ShapeBuffer buffer;
    char tmp;
    Triangle* tri = outer->GetContainer()->GetChildShape(key, &buffer);
    if (*FUN_00a564b0(&tmp, &tri->v0, &tri->v1, &tri->v2, DAT_01065384))
        return 0;
    int result = 0;
    for (int i = 0; i < 3; i++)
        hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(&tmp, outer, tri, key, i, &result, p3);
    return (short)result;
}
}
}   // namespace f3m_00a560b0
