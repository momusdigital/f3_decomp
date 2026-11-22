#include "f3_common.h"
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSphereMotion.h"

struct hkVector4D12
{
    float x, y, z, w;
};

struct hkMatrix3D12
{
    hkVector4D12 m_kColumn0;
    hkVector4D12 m_kColumn1;
    hkVector4D12 m_kColumn2;
};

template <class T> inline T hkMax2D12(T x, T y)
{
    return x > y ? x : y;
}

class hkpSphereMotionD12
{
  public:
    virtual ~hkpSphereMotionD12();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D12 m_kMotionState[11];
    hkVector4D12 m_kInertiaAndMassInv;

    void FUN_00d1e290(const hkMatrix3D12& inertia);
};

// Stores the reciprocal of the largest diagonal inertia component into m_kInertiaAndMassInv for the sphere motion.
// @fnv 0x00d1e290
void hkpSphereMotionD12::FUN_00d1e290(const hkMatrix3D12& inertia)
{
    float a = hkMax2D12(hkMax2D12(inertia.m_kColumn0.x, inertia.m_kColumn1.y), inertia.m_kColumn2.z);
    float fInvMaxDiag;
    if (a > 0.0f)
        fInvMaxDiag = 1.0f / a;
    else
        fInvMaxDiag = 0.0f;
    m_kInertiaAndMassInv.x = fInvMaxDiag;
    m_kInertiaAndMassInv.y = fInvMaxDiag;
    m_kInertiaAndMassInv.z = fInvMaxDiag;
}

class hkpSphereMotion_L : public hkpMotion
{
  public:
    void SetInertiaAndMassInv(const float* param_2);
};

// Computes the minimum of param_2[0], param_2[5] and param_2[10] and stores it in m_kInertiaAndMassInv x, y and z.
// @fnv 0x00d1e320
void hkpSphereMotion_L::SetInertiaAndMassInv(const float* param_2)
{
    float v0 = param_2[0];
    float v5 = param_2[5];

    float minVal;
    if (v0 < v5)
    {
        minVal = v0;
    }
    else
    {
        minVal = v5;
    }

    float v10 = param_2[10];

    float result;
    if (minVal < v10)
    {
        result = minVal;
    }
    else
    {
        result = v10;
    }

    this->m_kInertiaAndMassInv.x = result;
    this->m_kInertiaAndMassInv.y = result;
    this->m_kInertiaAndMassInv.z = result;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkVector4D1E41
{
    __m128 m_vComponents;

    __m128 getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    void setMul4(const __m128& s, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents);
    }
    void setMul4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E41& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void setCross(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

class hkVector4D1E4
{
  public:
    __m128 m_vComponents;
    void setMul4(const hkVector4D1E4& a, const hkVector4D1E4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

namespace fnv_00d1e5a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkSimdRealD1E5A
{
    __m128 m_vValue;

    hkSimdRealD1E5A(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    hkSimdRealD1E5A operator+(const hkSimdRealD1E5A& r) const
    {
        return _mm_add_ss(m_vValue, r.m_vValue);
    }
};

struct hkVector4D1E5A
{
    __m128 m_vComponents;

    void setSub4(const hkVector4D1E5A& a, const hkVector4D1E5A& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4D1E5A& a, const hkVector4D1E5A& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    hkSimdRealD1E5A dot3(const hkVector4D1E5A& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    hkSimdRealD1E5A lengthSquared3() const
    {
        return dot3(*this);
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

}  // namespace fnv_00d1e5a0

extern "C" __m128 _mm_setzero_ps();

extern "C" __m128 _mm_setzero_ps();

extern "C" __m128 _mm_setzero_ps();

struct TestMotion : public hkpSphereMotion
{
    void FUN_00d1e390(hkMatrix3& inertiaInvOut);
};

// Zeroes the 3x3 matrix and sets its diagonal entries to the scalar m_kInertiaAndMassInv.x value.
// @f3 0x0099d600 (community match, verified in this file)
struct __declspec(align(16)) Saved407 { float x, y, z, w; Saved407(float value) : w(value) {} };
void TestMotion::FUN_00d1e390(hkMatrix3& output) {
    Saved407 saved(m_kInertiaAndMassInv.x);

    volatile float* values = reinterpret_cast<volatile float*>(&output);
    values[0] = 0.0f;
    values[1] = 0.0f;
    values[2] = 0.0f;
    values[3] = 0.0f;
    values[4] = 0.0f;
    values[5] = 0.0f;
    values[6] = 0.0f;
    values[7] = 0.0f;
    values[8] = 0.0f;
    values[9] = 0.0f;
    values[10] = 0.0f;
    values[11] = 0.0f;
    output.m_kColumn0.x = saved.w;
    output.m_kColumn1.y = saved.w;
    output.m_kColumn2.z = saved.w;
}

