#include "f3_common.h"
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_00dedf10(void*, void*, void*, void*, int, int);
// Forwards the four pointers to FUN_00dedf10 with two trailing int arguments set to 0.
// @fnv 0x00dee5f0
// pdb: ScriptCompiler::MessageCompile | TESScriptCompiler.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkGeometryProcessing::generateRandomDistribution)
// pdb params: asParamCount, apParameters, apScriptLine, apCompileData
void __cdecl FUN_00dee5f0(void* first, void* second, void* third, void* fourth)
{
    FUN_00dedf10(first, second, third, fourth, 0, 0);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_sub_ss(__m128 a, __m128 b);
    __m128 _mm_div_ss(__m128 a, __m128 b);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    void _mm_store_ss(float* p, __m128 a);
}

struct VectorComponentValue
{
    __m128 m_vValue;

    VectorComponentValue()
    {}
    VectorComponentValue(const __m128& r) : m_vValue(r)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

__forceinline VectorComponentValue operator/(const VectorComponentValue& a, const VectorComponentValue& b)
{
    return _mm_div_ss(a.m_vValue, b.m_vValue);
}

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void sub4(const hkVector4& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& r)
    {
        m_vComponents =
            _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return _mm_add_ss(z, xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return dot3(*this);
    }
};

extern const hkVector4 DAT_010c7160;

namespace fnv_00dea810 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_or_ps(__m128, __m128);

struct hkVector4Comparisonq
{
    __m128 m_uiMask;
};
struct hkVector4q
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline hkVector4Comparisonq compareLessThan4(const hkVector4q& a) const
    {
        hkVector4Comparisonq c;
        c.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
        return c;
    }
    __forceinline void setSelect4(const hkVector4Comparisonq& comp, const hkVector4q& trueValue,
                                  const hkVector4q& falseValue)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(comp.m_uiMask, trueValue.m_vComponents),
                                  _mm_andnot_ps(comp.m_uiMask, falseValue.m_vComponents));
    }
    template <int I> __forceinline void setBroadcast(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (I << 6) | (I << 4) | (I << 2) | I);
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

}  // namespace fnv_00dea810

extern __m128 DAT_010c71d0;

struct Vertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    __m128 m_vHitNormal;
};

struct Triangle
{
    unsigned int unk00;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    unsigned int unk20;
};

struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    Edge(unsigned int uid)
    {
        m_uiEdgeIndex = uid & 3;
        m_pkTriangle = (Triangle*)(uid & ~3u);
    }
    unsigned int uid() const
    {
        return (unsigned int)m_pkTriangle + m_uiEdgeIndex;
    }
    Edge link() const
    {
        return Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);
    }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
    void bindSafe(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        if (other.m_pkTriangle)
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};

namespace fnv_00dea6b0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

struct S00dea6b0_Vec
{
    __m128 m_vComponents;

    void setSub4(const S00dea6b0_Vec& a, const S00dea6b0_Vec& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const S00dea6b0_Vec& v1, const S00dea6b0_Vec& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    float dot3(const S00dea6b0_Vec& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        float r;
        _mm_store_ss(&r, res);
        return r;
    }
};

}  // namespace fnv_00dea6b0

extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_setr_ps(float, float, float, float);
}
extern __m128 DAT_01017d10;

struct CubeVector
{
    __m128 lanes;
    __forceinline void sum(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_add_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void difference(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_sub_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void scale(const __m128& k)
    {
        lanes = _mm_mul_ps(k, lanes);
    }
    __forceinline int longestAxis() const
    {
        CubeVector magnitude;
        magnitude.lanes = _mm_and_ps(lanes, DAT_01017d10);
        const float* p = (const float*)&magnitude.lanes;
        if (p[0] < p[1])
            return p[1] < p[2] ? 2 : 1;
        return p[0] < p[2] ? 2 : 0;
    }
    __forceinline float component(int i) const
    {
        return ((const float*)&lanes)[i];
    }
};
struct CubeBox
{
    CubeVector lower;
    CubeVector upper;
    __forceinline void center(CubeVector& dst) const
    {
        dst.sum(lower, upper);
        dst.scale(DAT_010c71d0);
    }
    __forceinline void extent(CubeVector& dst) const
    {
        dst.difference(upper, lower);
        dst.scale(DAT_010c71d0);
    }
};

#include <math.h>
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_load_ss(const float*);

extern "C"
{
    __m128 _mm_set_ss(float);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}
extern const float DAT_01012054, DAT_01012068, DAT_0106c2e0;

class ScalarValue
{
    __m128 value;

  public:
    ScalarValue()
    {}
    ScalarValue(const __m128& x) : value(x)
    {}
    ScalarValue(float x) : value(_mm_load_ss(&x))
    {}
    operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline const __m128& lanes() const
    {
        return value;
    }
    __forceinline __m128 spread() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
inline ScalarValue operator+(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_add_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator/(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_div_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator-(const ScalarValue& x)
{
    return _mm_sub_ss(DAT_010c7160.m_vComponents, x.lanes());
}

class GeomVector
{
  public:
    __m128 data;
    GeomVector()
    {}
    GeomVector(const __m128& x) : data(x)
    {}
    __forceinline GeomVector(const GeomVector& x) : data(x.data)
    {}
    __forceinline void operator=(const GeomVector& x)
    {
        data = x.data;
    }
    __forceinline void difference(const GeomVector& x, const GeomVector& y)
    {
        data = _mm_sub_ps(x.data, y.data);
    }
    __forceinline void cross(const GeomVector& x, const GeomVector& y)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xc9), _mm_shuffle_ps(y.data, y.data, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xd2), _mm_shuffle_ps(y.data, y.data, 0xc9));
        data = _mm_sub_ps(first, second);
    }
    __forceinline ScalarValue dot(const GeomVector& x) const
    {
        __m128 product = _mm_mul_ps(data, x.data);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline ScalarValue magnitude() const
    {
        return _mm_sqrt_ss(dot(*this).lanes());
    }
    __forceinline ScalarValue inverseMagnitude() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot(*this).lanes();
        const __m128 empty = _mm_cmpeq_ss(squared, zero);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(empty, refined);
    }
    __forceinline void normalize()
    {
        __m128 scale = inverseMagnitude().spread();
        data = _mm_mul_ps(scale, data);
    }
    __forceinline float& component(int i)
    {
        return ((float*)&data)[i];
    }
    __forceinline ScalarValue selected(int i) const
    {
        switch (i)
        {
        case 0:
            return data;
        case 1:
            return _mm_shuffle_ps(data, data, 0x55);
        case 2:
            return _mm_shuffle_ps(data, data, 0xaa);
        default:
            return _mm_shuffle_ps(data, data, 0xff);
        }
    }
    __forceinline void addScaled(const GeomVector& base, const GeomVector& direction, const ScalarValue& scale)
    {
        data = _mm_add_ps(base.data, _mm_mul_ps(scale.spread(), direction.data));
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        data = _mm_setr_ps(x, y, z, w);
    }
    __forceinline ScalarValue sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(data, data, 0x55), data);
        return _mm_add_ss(_mm_shuffle_ps(data, data, 0xaa), xy);
    }
    __forceinline void scale(const ScalarValue& x)
    {
        data = _mm_mul_ps(x.spread(), data);
    }
};

#include <float.h>
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
    __m128 _mm_setr_ps(float, float, float, float);
    void _mm_store_ss(float*, __m128);
}

extern const float DAT_0106c2e0;
