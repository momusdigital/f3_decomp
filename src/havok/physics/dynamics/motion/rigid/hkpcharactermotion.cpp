#include "f3_common.h"
// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpcharactermotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCharacterMotion.h"

struct hkVector4D1E
{
    float x, y, z, w;
};

struct hkMatrix3D1E
{
    hkVector4D1E m_kColumn0;
    hkVector4D1E m_kColumn1;
    hkVector4D1E m_kColumn2;
};

template <class T> inline T hkMax2D1E(T x, T y)
{
    return x > y ? x : y;
}

class hkpCharacterMotionD1E
{
  public:
    virtual ~hkpCharacterMotionD1E();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E m_kMotionState[11];
    hkVector4D1E m_kInertiaAndMassInv;

    void SetInertiaAndMassInv(const hkMatrix3D1E& inertia);
};

// Computes the reciprocal of the largest diagonal element of the inertia matrix and stores it in all three components of m_kInertiaAndMassInv.
// @fnv 0x00d1ed40
void hkpCharacterMotionD1E::SetInertiaAndMassInv(const hkMatrix3D1E& inertia)
{
    float a = hkMax2D1E(hkMax2D1E(inertia.m_kColumn0.x, inertia.m_kColumn1.y), inertia.m_kColumn2.z);
    float fInvMaxDiag;
    if (a > 0.0f)
        fInvMaxDiag = 1.0f / a;
    else
        fInvMaxDiag = 0.0f;
    m_kInertiaAndMassInv.x = fInvMaxDiag;
    m_kInertiaAndMassInv.y = fInvMaxDiag;
    m_kInertiaAndMassInv.z = fInvMaxDiag;
}

struct FUN_00d1edd0_stub : public hkpMotion
{
    void SetMinOfThree(const float* src);
};

// Stores the smallest diagonal element of the 4x4 src (src[0], src[5], src[10]) as all three inverse inertias.
// @fnv 0x00d1edd0
void FUN_00d1edd0_stub::SetMinOfThree(const float* src)
{
    float a = src[0];
    float b = src[5];
    float c = a < b ? a : b;
    float fThird = src[10];
    float fMinAll = c < fThird ? c : fThird;
    m_kInertiaAndMassInv.x = fMinAll;
    m_kInertiaAndMassInv.y = fMinAll;
    m_kInertiaAndMassInv.z = fMinAll;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D1EE
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3D1EE
{
    hkVector4D1EE m_kColumn0;
    hkVector4D1EE m_kColumn1;
    hkVector4D1EE m_kColumn2;

    float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setDiagonal(float m00, float m11, float m22)
    {
        setZero();
        (*this)(0, 0) = m00;
        (*this)(1, 1) = m11;
        (*this)(2, 2) = m22;
    }
};

namespace fnv_00d1ee80 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D1E8x
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3D1E8x
{
    hkVector4D1E8x m_kColumn0;
    hkVector4D1E8x m_kColumn1;
    hkVector4D1E8x m_kColumn2;

    float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setDiagonal(float m00, float m11, float m22)
    {
        setZero();
        (*this)(0, 0) = m00;
        (*this)(1, 1) = m11;
        (*this)(2, 2) = m22;
    }
};

}  // namespace fnv_00d1ee80

namespace fnv_00d1ef50 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct hkVector4D1EF
{
    __m128 m_vComponents;

    void setMul4(const hkVector4D1EF& a, const hkVector4D1EF& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1EF& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

}  // namespace fnv_00d1ef50

struct __declspec(align(16)) FUN_00d1ecc0_Matrix
{
    float m_Values[12];
};

struct FUN_00d1ecc0_Class
{
    unsigned char m_Padding[0xc0];
    float m_InertiaLocal;

    void FUN_00d1ecc0(FUN_00d1ecc0_Matrix& inertia) const;
};

// Writes to inertia three rows of four floats with 1/m_InertiaLocal at indices 0, 5 and 10 and zeros elsewhere.
// @f3 0x0099d440 (community match, verified in this file)
void FUN_00d1ecc0_Class::FUN_00d1ecc0(FUN_00d1ecc0_Matrix& inertia) const
{
    const float value = 1.0f / m_InertiaLocal;
    const __m128 zero = _mm_setzero_ps();

    *(volatile float*)&inertia.m_Values[0] = 0.0f;
    *(volatile float*)&inertia.m_Values[1] = 0.0f;
    *(volatile float*)&inertia.m_Values[2] = 0.0f;
    *(volatile float*)&inertia.m_Values[3] = 0.0f;
    *(volatile float*)&inertia.m_Values[4] = 0.0f;
    *(volatile float*)&inertia.m_Values[5] = 0.0f;
    *(volatile float*)&inertia.m_Values[6] = 0.0f;
    *(volatile float*)&inertia.m_Values[7] = 0.0f;
    *(volatile float*)&inertia.m_Values[8] = 0.0f;
    *(volatile float*)&inertia.m_Values[9] = 0.0f;
    *(volatile float*)&inertia.m_Values[10] = 0.0f;
    *(volatile float*)&inertia.m_Values[11] = 0.0f;

    inertia.m_Values[0] = value;
    inertia.m_Values[5] = value;
    inertia.m_Values[10] = value;
}


extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);

struct hkSimdRealX
{
    __m128 m_vValue;
    hkSimdRealX(__m128 r) : m_vValue(r)
    {}
};

struct hkVector4X
{
    __m128 m_vComponents;

    hkSimdRealX getW() const
    {
        return hkSimdRealX(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
    }
    void addMul4(const hkSimdRealX& s, const hkVector4X& v)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), v.m_vComponents));
    }
    void setSub4(const hkVector4X& a, const hkVector4X& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4X& v1, const hkVector4X& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    void setMul4(const hkVector4X& a, const hkVector4X& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4X& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
struct Simd
{
    __m128 quad;
};
union Vec
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };

    __forceinline void mulFloat(float s)
    {
        quad = _mm_mul_ps(_mm_set_ps1(s), quad);
    }
    __forceinline void setFloat(float s, const Vec& v)
    {
        quad = _mm_mul_ps(_mm_set_ps1(s), v.quad);
    }
    __forceinline void mulSimd(const Simd& s)
    {
        quad = _mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), quad);
    }
    __forceinline void setSimd(const Simd& s, const Vec& v)
    {
        quad = _mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), v.quad);
    }
    __forceinline void add(const Vec& v)
    {
        quad = _mm_add_ps(v.quad, quad);
    }
    __forceinline void addMul(const Simd& s, const Vec& v)
    {
        quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), v.quad), quad);
    }
    __forceinline Simd getW() const
    {
        Simd r;
        r.quad = _mm_shuffle_ps(quad, quad, 255);
        return r;
    }
};
