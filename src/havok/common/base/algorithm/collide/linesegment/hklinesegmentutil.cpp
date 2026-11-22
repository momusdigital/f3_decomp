#include "f3_common.h"
// src/havok/common/base/algorithm/collide/linesegment/hklinesegmentutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/algorithm/collide/linesegment/hklinesegmentutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkSimdRealD230
{
    __m128 m_vValue;

    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct hkVector4D230
{
    __m128 m_vComponents;

    hkVector4D230()
    {}
    hkVector4D230(const hkVector4D230& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D230& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4D230& a, const hkVector4D230& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAddMul4(const hkVector4D230& a, const hkVector4D230& b, float t)
    {
        const __m128 s = _mm_load_ss(&t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents), a.m_vComponents);
    }
    hkSimdRealD230 dot3(const hkVector4D230& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        hkSimdRealD230 r;
        r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
        return r;
    }
};

#include <math.h>

typedef float hkReal;

struct VectorComponentValue
{
    __m128 m_vValue;
    VectorComponentValue(__m128 x) : m_vValue(x)
    {}
    VectorComponentValue(const hkReal& x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    operator hkReal() const
    {
        hkReal r;
        _mm_store_ss(&r, m_vValue);
        return r;
    }
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
};

class hkVector4
{
  public:
    __m128 m_vComponents;

    inline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void setAddMul4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    inline void setAddMul4b(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        __m128 rr = _mm_load_ss(&r);
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(rr, rr, 0), b.m_vComponents));
    }
    inline void setAddMul4a(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents,
                                   _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), b.m_vComponents));
    }
    inline VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 m = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 y = _mm_shuffle_ps(m, m, 0x55);
        __m128 xy = _mm_add_ss(y, m);
        __m128 z = _mm_shuffle_ps(m, m, 0xaa);
        __m128 xyz = _mm_add_ss(z, xy);
        return VectorComponentValue(xyz);
    }
    inline hkReal dot3scalar(const hkVector4& a) const
    {
        return dot3(a);
    }
    inline VectorComponentValue lengthSquared3() const
    {
        return dot3(*this);
    }
};

static inline hkReal hkFabs(hkReal r)
{
    return (hkReal)::fabs(r);
}

struct VectorPairResult
{
    hkVector4 m_kFirstVector;
    hkVector4 m_kClosestPointOnSecond;
    hkReal m_fValue;
};

// Computes the closest points on two line segments defined by A/dA and B/dB, storing them and the squared distance in result.
// @f3 0x0096f780 (community match, verified in this file)
#include <math.h>

typedef float hkReal;

class hkVector4Scalar
{
public:
    __declspec(align(16)) float x;
    float y, z, w;

    void setSub4(const hkVector4Scalar& a, const hkVector4Scalar& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float dot3(const hkVector4Scalar& a) const
    {
        return x * a.x + y * a.y + z * a.z;
    }
    float dot3scalar(const hkVector4Scalar& a) const
    {
        return dot3(a);
    }
    void setAddMul4a(const hkVector4Scalar& a, const hkVector4Scalar& b, float t)
    {
        x = a.x + b.x * t;
        y = a.y + b.y * t;
        z = a.z + b.z * t;
        w = a.w + b.w * t;
    }
    void setAddMul4b(const hkVector4Scalar& a, const hkVector4Scalar& b, float t)
    {
        setAddMul4a(a, b, t);
    }
    float lengthSquared3() const
    {
        return dot3(*this);
    }
};

struct VectorPairResultScalar
{
    hkVector4Scalar m_kFirstVector;
    hkVector4Scalar m_kClosestPointOnSecond;
    hkReal m_fValue;
};

inline float scalarFabs(float r)
{
    return (float)fabs(r);
}

// pdb: findClosestTriangleBackup | hkpGsk.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkLineSegmentUtil::closestLineSegLineSeg)
int FUN_00d22e40(const hkVector4& A, const hkVector4& dA, const hkVector4& B, const hkVector4& dB,
                 VectorPairResult& result)
{
    hkVector4Scalar kDelta;
    kDelta.setSub4((const hkVector4Scalar&)B, (const hkVector4Scalar&)A);
    hkReal fDotDir = ((const hkVector4Scalar&)dA).dot3((const hkVector4Scalar&)dB);
    hkReal fDotADelta = ((const hkVector4Scalar&)dA).dot3(kDelta);
    hkReal fDotBDelta = ((const hkVector4Scalar&)dB).dot3(kDelta);
    hkReal fLenSqA = ((const hkVector4Scalar&)dA).dot3scalar((const hkVector4Scalar&)dA);
    hkReal fLenSqB;
    fLenSqB = ((const hkVector4Scalar&)dB).dot3((const hkVector4Scalar&)dB);

    hkReal denom = scalarFabs(fLenSqA * fLenSqB - fDotDir * fDotDir);
    hkReal s = fDotADelta * fLenSqB - fDotBDelta * fDotDir;

    int code;
    if (denom * s >= denom * denom)
    {
        code = 1;
        s = 1.0f;
    }
    else if (s <= 0.0f)
    {
        code = 2;
        s = 0.0f;
    }
    else
    {
        hkReal fEpsilon = (fLenSqA * fLenSqB + fDotDir * fDotDir) * (1.0 / 1048576.0);
        if (fEpsilon < denom)
        {
            code = 0;
            s = s / denom;
        }
        else
        {
            code = 1;
            s = 1.0f;
        }
    }

    hkReal t = fDotDir * s - fDotBDelta;
    if (t >= fLenSqB)
    {
        code = 4;
        t = 1.0f;
    }
    else if (t <= 0.0f)
    {
        code = 8;
        t = 0.0f;
    }
    else
    {
        t = t / fLenSqB;
        goto done;
    }

    s = fDotDir * t + fDotADelta;
    if (s <= 0.0f)
    {
        code |= 2;
        s = 0.0f;
    }
    else if (s >= fLenSqA)
    {
        code |= 1;
        s = 1.0f;
    }
    else
    {
        s = s / fLenSqA;
    }

done:
    VectorPairResultScalar& r = (VectorPairResultScalar&)result;
    r.m_kFirstVector.setAddMul4a((const hkVector4Scalar&)A, (const hkVector4Scalar&)dA, s);
    hkVector4Scalar closestB;
    closestB.setAddMul4b((const hkVector4Scalar&)B, (const hkVector4Scalar&)dB, t);
    r.m_kClosestPointOnSecond.setSub4(r.m_kFirstVector, closestB);
    r.m_fValue = r.m_kClosestPointOnSecond.lengthSquared3();
    return code;
}

