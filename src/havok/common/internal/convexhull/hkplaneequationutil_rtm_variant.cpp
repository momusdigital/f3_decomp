// src/havok/common/internal/convexhull/hkplaneequationutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkplaneequationutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const float*);
}
#include <math.h>
extern "C"
{
}
typedef __m128 hkQuadReal;
extern const hkQuadReal DAT_010c44d0;
struct VectorComponentValue
{
    hkQuadReal m_vValue;
    VectorComponentValue()
    {}
    VectorComponentValue(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    VectorComponentValue(const hkQuadReal& r) : m_vValue(r)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
};
struct hkVector4
{
    hkQuadReal m_vComponents;
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAddMul4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& r)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.broadcast(), b.m_vComponents), a.m_vComponents);
    }
    void setCross(const hkVector4& av, const hkVector4& bv)
    {
        hkQuadReal a = _mm_load_ps(av.m_vComponents.m128_f32);
        hkQuadReal b = _mm_load_ps(bv.m_vComponents.m128_f32);
        hkQuadReal c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
        hkQuadReal c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    void set(float x, float y, float z, float w)
    {
        hkQuadReal xz = _mm_unpacklo_ps(_mm_set_ss(x), _mm_set_ss(z));
        hkQuadReal yw = _mm_unpacklo_ps(_mm_set_ss(y), _mm_set_ss(w));
        m_vComponents = _mm_unpacklo_ps(xz, yw);
    }
    void setMul4(const VectorComponentValue& r, const hkVector4& a)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), a.m_vComponents);
    }
    void mul4(const VectorComponentValue& r)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    float getW() const
    {
        return m_vComponents.m128_f32[3];
    }
    VectorComponentValue getComponent(int i) const
    {
        return i == 0   ? VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0))
               : i == 1 ? VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55))
                        : VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa));
    }
    void setNeg4(const hkVector4& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
};
struct PointResult
{
    hkVector4 m_kPoint;
    int m_kPointA, m_kPointB, m_iThirdValue;
};
struct PlaneSet
{
    hkVector4* m_kPlaneArray;
    int m_iValue;
};
// @f3 0x00a57240 (community match, verified in this file)
int FUN_00a57050(PlaneSet* set, int first, int second, int third, PointResult* point);

struct __declspec(align(16)) EndpointDelta {
    float x, y, z;
};

__forceinline EndpointDelta MakeEndpointDelta(const float* endpoint, float x, float y, float z)
{
    EndpointDelta delta = { endpoint[0] - x, endpoint[1] - y, endpoint[2] - z };
    return delta;
}

__forceinline float DotPlane(const hkVector4& vector, const EndpointDelta& delta)
{
    const float* plane = vector.m_vComponents.m128_f32;
    return plane[1] * delta.y + plane[0] * delta.x + plane[2] * delta.z;
}

__forceinline bool FillMissingEndpoint(PointResult* destination, const PointResult* source)
{
    if (destination->m_kPointA == -1) {
        const int first = source->m_kPointA;
        if (first == -1)
            return false;
        destination->m_kPointA = first;
        destination->m_kPointB = source->m_kPointB;
        destination->m_iThirdValue = source->m_iThirdValue;
    }
    return true;
}

int FUN_00dd6510(const hkVector4* direction, PlaneSet* set, int first, int second,
                PointResult* neg, PointResult* pos)
{
    neg->m_kPointA = -1;
    neg->m_kPointB = -1;
    neg->m_iThirdValue = -1;
    pos->m_kPointA = -1;
    pos->m_kPointB = -1;
    pos->m_iThirdValue = -1;
    bool initialized = false;
    for (int i = 0; i < set->m_iValue; ++i) {
        if (i == first || i == second)
            continue;
        PointResult point;
        if (FUN_00a57050(set, first, second, i, &point) != 0)
            continue;

        const float x = point.m_kPoint.m_vComponents.m128_f32[0];
        const float y = point.m_kPoint.m_vComponents.m128_f32[1];
        const float z = point.m_kPoint.m_vComponents.m128_f32[2];
        const float w = point.m_kPoint.m_vComponents.m128_f32[3];
        float* positive = pos->m_kPoint.m_vComponents.m128_f32;
        float* negative = neg->m_kPoint.m_vComponents.m128_f32;
        if (!initialized) {
            initialized = true;
            const float* axis = direction->m_vComponents.m128_f32;
            positive[0] = static_cast<float>(x - axis[0] * 100000.0);
            positive[1] = static_cast<float>(y - axis[1] * 100000.0);
            positive[2] = static_cast<float>(z - axis[2] * 100000.0);
            positive[3] = static_cast<float>(w - axis[3] * 100000.0);
            negative[0] = -positive[0];
            negative[1] = -positive[1];
            negative[2] = -positive[2];
            negative[3] = -positive[3];
        }

        const EndpointDelta positiveDelta = MakeEndpointDelta(positive, x, y, z);
        const hkVector4& positivePlane = set->m_kPlaneArray[i];
        const float tolerance = -1.1920928955078125e-7f;
        const float* coefficients = positivePlane.m_vComponents.m128_f32;
        const float positiveDot = coefficients[0] * positiveDelta.x +
                                  positiveDelta.y * coefficients[1] +
                                  coefficients[2] * positiveDelta.z;
        if (positiveDot > tolerance) {
            positive[0] = x;
            positive[1] = y;
            positive[2] = z;
            positive[3] = w;
            pos->m_kPointA = point.m_kPointA;
            pos->m_kPointB = point.m_kPointB;
            pos->m_iThirdValue = point.m_iThirdValue;
        }

        const EndpointDelta negativeDelta = MakeEndpointDelta(negative, x, y, z);
        const hkVector4& negativePlane = set->m_kPlaneArray[i];
        const float negativeDot = DotPlane(negativePlane, negativeDelta);
        if (negativeDot > tolerance) {
            negative[0] = x;
            negative[1] = y;
            negative[2] = z;
            negative[3] = w;
            neg->m_kPointA = point.m_kPointA;
            neg->m_kPointB = point.m_kPointB;
            neg->m_iThirdValue = point.m_iThirdValue;
        }
    }

    if (FillMissingEndpoint(neg, pos) && FillMissingEndpoint(pos, neg))
        return 0;
    return 1;
}

