#include "f3_common.h"
// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCapsuleShape.h"

// @fnv 0x00d22350
// pdb: hkpRigidBody::setFriction | hkpRigidBody.obj | fnv360_0822_retail, objrun_open, low
// pdb params: newFriction, newRollingFriction
int __cdecl FUN_00d22350()
{
    return 2;
}

// @fnv 0x00d22d60
// pdb: hkpCapsuleShape::calcSizeForSpu | hkpCapsuleShape.obj | fnv360_0721_beta, objrun_open, low
// pdb params: input, spuBufferSizeLeft
int __stdcall FUN_00d22d60(int a, int b)
{
    return 0x40;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" void _mm_store_ps(float* p, __m128 v);

struct __declspec(align(16)) hkVector4D224
{
    __m128 m_vComponents;

    hkVector4D224()
    {}
    hkVector4D224(const hkVector4D224& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

union __declspec(align(16)) AlignedHKVector4
{
    __m128 simd;
    struct
    {
        float x, y, z, w;
    };
};

struct __declspec(align(16)) Point4
{
    float x, y, z, w;
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ps(float*, __m128);

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);

struct hkSimdRealD223
{
    __m128 m_vValue;

    hkSimdRealD223(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4D223
{
    __m128 m_vComponents;

    hkVector4D223()
    {}
    hkVector4D223(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4D223& a, const hkVector4D223& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD223 dot3(const hkVector4D223& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void setInt24W(int i)
    {
        reinterpret_cast<int*>(&m_vComponents)[3] = i | 0x3f000000;
    }
};

extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps1(float);

struct hkTransformq;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(hkReal x)
    {
        m_vComponents = _mm_set_ps1(x);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn);
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

union hkVector4U
{
    hkVector4 m_vec;
    __m128 m_vComponents;
};

struct hkTransformU
{
    hkVector4U m_kColumn0;
    hkVector4U m_kColumn1;
    hkVector4U m_kColumn2;
    hkVector4U m_vTranslation;

    __forceinline void set(const hkTransform& t)
    {
        m_kColumn0.m_vec = t.m_rotation.m_kColumn0;
        m_kColumn1.m_vec = t.m_rotation.m_kColumn1;
        m_kColumn2.m_vec = t.m_rotation.m_kColumn2;
        m_vTranslation.m_vec = t.m_vTranslation;
    }
};

__forceinline void hkVector4q::SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn)
{
    const __m128 b = bIn.m_vComponents;
    const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const __m128 r0 = _mm_mul_ps(a.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const __m128 r1 = _mm_mul_ps(a.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, a.m_vTranslation.m_vComponents));
}
