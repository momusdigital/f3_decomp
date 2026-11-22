#include "f3_common.h"
// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @f3 0x006f5500 (community match, verified in this file)
struct GlobalStub { float FUN_006e2a90(); };
extern GlobalStub DAT_01079f68;
struct X { void FUN_006f5500(int a, float b); };
extern void __cdecl FUN_00450ba0(X* self, int a, float b, float c);
// pdb: Actor::GetMissedPacks | Actor.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apPacks, afStartdate
void X::FUN_006f5500(int a, float b)
{
    float c = DAT_01079f68.FUN_006e2a90();
    FUN_00450ba0(this, a, b, c);
}


#include <xmmintrin.h>

struct __declspec(align(16)) VertexRecord
{
    __m128 m_kPathOffset;
    int m_ai10;
    int m_ai14;
    int m_ai18;
    int m_ai1c;
    int m_ai20;
    int m_ai24;
    int m_ai28;
    int m_ai2c;
};

namespace fnv_00ce55d0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

typedef float hkReal;

extern __m128 DAT_010c71b0;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline hkReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        hkReal r;
        _mm_store_ss(&r, _mm_sqrt_ss(len2));
        return r;
    }
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;

    __forceinline void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.m_vComponents = DAT_010c71b0;
        m_vScale.SetAllComponents(1.0f);
    }
};

}  // namespace fnv_00ce55d0

#include <math.h>

typedef float(__thiscall* ReadValue)(void*);

namespace fnv_00ce5e60 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    void _mm_store_ss(float*, __m128);
}

typedef float hkReal;
typedef short hkInt16;

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

union hkVector4q
{
    hkVector4f m_vec;
    __m128 m_vComponents;
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;
};

}  // namespace fnv_00ce5e60

namespace fnv_00ce5fe0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
}

typedef float hkReal;
typedef short hkInt16;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
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

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void operator=(const hkQuaternion& q)
    {
        m_vec.m_vComponents = q.m_vec.m_vComponents;
    }
    void FUN_00cd9d10(const hkVector4& from, const hkVector4& to);
    void FUN_00c74b70(const hkQuaternion& a, const hkQuaternion& b);
};

}  // namespace fnv_00ce5fe0

typedef unsigned int size_t;

inline void* operator new(size_t, void* p)
{
    return p;
}

struct hkMemoryAllocator;

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocator* m_pStreamAllocator;
};

hkMemoryRouterStub* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* array, int numElems, int elemSize);

template <typename T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dst[i] = src[i];
        }
    }

    __forceinline void constructWithCopy(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }

    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newCap = n < cap2 ? cap2 : n;
            FUN_00c908c0(&alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void copyFromArray(hkMemoryAllocator& alloc, const HkArray& a)
    {
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        copy(m_data, a.m_data, copiedSize);
        constructWithCopy(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline HkArray& operator=(const HkArray& other)
    {
        copyFromArray(FUN_00c85750()->heap(), other);
        return *this;
    }
};
