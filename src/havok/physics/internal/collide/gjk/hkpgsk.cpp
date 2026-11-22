#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// SSE_DECLARATIONS_DEFER_TO_SDK
// src/havok/physics/internal/collide/gjk/hkpgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Entry
{
    char pad[12];
    unsigned short val;
    char pad2[2];
};

struct Dest
{
    unsigned short words[4];
    unsigned char count1;
    unsigned char count2;
};

struct ThisClass
{
    int count1;
    int count2;
    char pad[0x18];
    Entry entries1[3];
    char pad2[0x90];
    Entry entries2[3];

    void FUN_00da9790(Dest* out);
};

// @fnv 0x00da9790
// pdb: hkpGskBaseAgent::calcSeparatingNormal | hkpGskBaseAgent.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpGsk::exitAndExportCacheImpl)
// pdb params: bodyA, bodyB, earlyOutTolerance, gsk, separatingNormalOut
void ThisClass::FUN_00da9790(Dest* pDest)
{
    pDest->count1 = (unsigned char)this->count1;
    pDest->count2 = (unsigned char)this->count2;

    int iCount1 = this->count1;
    unsigned short v0 = this->entries1[0].val;
    if (iCount1 >= 2)
    {
        unsigned short v1 = this->entries1[1].val;
        int iSwaps1 = 0;
        if (v1 > v0)
        {
            unsigned short tmp = v1;
            v1 = v0;
            v0 = tmp;
            iSwaps1 = 1;
        }
        if (iCount1 > 2)
        {
            unsigned short v2 = this->entries1[2].val;
            if (v2 > v0)
            {
                unsigned short tmp = v2;
                v2 = v0;
                v0 = tmp;
                iSwaps1++;
            }
            if (iSwaps1 == 1)
            {
                unsigned short tmp = v2;
                v2 = v1;
                v1 = tmp;
            }
            pDest->words[2] = v2;
        }
        pDest->words[1] = v1;
    }
    pDest->words[0] = v0;

    int iCount2 = this->count2;
    unsigned short u0 = this->entries2[0].val;
    if (iCount2 >= 2)
    {
        unsigned short u1 = this->entries2[1].val;
        int iSwaps2 = 0;
        if (u1 > u0)
        {
            unsigned short tmp = u1;
            u1 = u0;
            u0 = tmp;
            iSwaps2 = 1;
        }
        if (iCount2 > 2)
        {
            unsigned short u2 = this->entries2[2].val;
            if (u2 > u0)
            {
                unsigned short tmp = u2;
                u2 = u0;
                u0 = tmp;
                iSwaps2++;
            }
            if (iSwaps2 == 1)
            {
                unsigned short tmp = u2;
                u2 = u1;
                u1 = tmp;
            }
            pDest->words[this->count1 + 2] = u2;
        }
        pDest->words[this->count1 + 1] = u1;
    }
    pDest->words[this->count1] = u0;
}

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
#endif
#ifndef _INCLUDED_MM2
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_setzero_ps();
    int _mm_movemask_ps(__m128);
}
#endif

struct Vector
{
    __m128 quad;
    Vector()
    {}
    Vector& operator=(const Vector& v)
    {
        quad = v.quad;
        return *this;
    }
};

namespace fnv_00da8700 {
#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif
#ifndef _INCLUDED_MM2
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
}
#endif

extern const __m128 g_signMask;

struct VectorComponentValue
{
    __m128 m_vValue;
};

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9)));
    }

    __forceinline VectorComponentValue dot3(const hkVector4& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        VectorComponentValue r;
        r.m_vValue = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        return r;
    }

    __forceinline VectorComponentValue lengthInverse3() const
    {
        __m128 len2 = dot3(*this).m_vValue;
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        VectorComponentValue res;
        res.m_vValue = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        return res;
    }

    __forceinline void setFlipSign(const hkVector4& v, const VectorComponentValue& s)
    {
        m_vComponents = _mm_xor_ps(_mm_and_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), g_signMask), v.m_vComponents);
    }

    __forceinline void mul4(const VectorComponentValue& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, _mm_shuffle_ps(s.m_vValue, s.m_vValue, 0));
    }
};

}  // namespace fnv_00da8700

struct SpawnedSrc
{
    __m128 m_v;
};

struct SpawnedDst
{
    __m128 m_v00;
    __m128 m_v10;
    float m_f20;
};

struct __declspec(align(16)) FUN_00da9880_cls
{
    int m_i00;
    int m_i04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_v20;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    __m128 m_va0;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    __m128 m_v130;

    void FUN_00da9880(const SpawnedSrc* apSrc, SpawnedDst* apDst);
};

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" int _mm_movemask_ps(__m128);

extern const signed char DAT_010cb440[];

struct S00da8390_Real
{
    __m128 r;
    S00da8390_Real operator*(const S00da8390_Real& o) const
    {
        S00da8390_Real t;
        t.r = _mm_mul_ss(r, o.r);
        return t;
    }
    S00da8390_Real operator-(const S00da8390_Real& o) const
    {
        S00da8390_Real t;
        t.r = _mm_sub_ss(r, o.r);
        return t;
    }
};

struct S00da8390_Vec
{
    __m128 q;
    void setSub4(const S00da8390_Vec& a, const S00da8390_Vec& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    void setMul4(const S00da8390_Vec& a, const S00da8390_Vec& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    S00da8390_Real horizontalAdd3() const
    {
        S00da8390_Real t;
        __m128 y = _mm_shuffle_ps(q, q, 0x55);
        y = _mm_add_ss(y, q);
        __m128 z = _mm_shuffle_ps(q, q, 0xaa);
        t.r = _mm_add_ss(z, y);
        return t;
    }
};

extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
}

extern const __m128 DAT_010c44d0;

class S00da8820_Simd
{
  public:
    S00da8820_Simd(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

class S00da8820_Vec4
{
  public:
    void operator=(const S00da8820_Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const S00da8820_Vec4& v0, const S00da8820_Vec4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    void setAdd4(const S00da8820_Vec4& v0, const S00da8820_Vec4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    void setMul4(const S00da8820_Vec4& a, const S00da8820_Vec4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const S00da8820_Vec4& v0, const S00da8820_Vec4& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    S00da8820_Simd dot3(const S00da8820_Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    S00da8820_Simd horizontalAdd3() const
    {
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    S00da8820_Simd lengthSquared3() const
    {
        return this->dot3(*this);
    }
    __forceinline S00da8820_Simd lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    void SetAllComponents(const S00da8820_Simd& a)
    {
        m_vComponents = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
    }
    void setW(const S00da8820_Vec4& w)
    {
        m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, w.m_vComponents), 0xc4);
    }
    void setFlipSign4(const S00da8820_Vec4& v, const S00da8820_Simd& s)
    {
        m_vComponents = _mm_xor_ps(_mm_and_ps(s.broadcast(), DAT_010c44d0), v.m_vComponents);
    }

    __m128 m_vComponents;
};

struct S00da8820_Result
{
    S00da8820_Vec4 m_kFirstVector;
    S00da8820_Vec4 m_kClosestPointOnSecond;
    float m_fValue;
};

int __cdecl FUN_00d22e40(const S00da8820_Vec4& A, const S00da8820_Vec4& dA, const S00da8820_Vec4& B,
                         const S00da8820_Vec4& dB, S00da8820_Result& result);

#include <math.h>
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_setzero_ps();
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    void _mm_store_ss(float*, __m128);
}

struct __declspec(align(16)) Collision_vector
{
    float x, y, z, w;
    __forceinline __m128& simd()
    {
        return (__m128&)*this;
    }
    __forceinline const __m128& simd() const
    {
        return (const __m128&)*this;
    }
    __forceinline void normalize3(const __m128&, const __m128&, const __m128&);
    __forceinline Collision_vector& operator=(const Collision_vector& v)
    {
        simd() = v.simd();
        return *this;
    }
};
struct Collision_vcls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void support(Collision_vector* direction, Collision_vector* out);
    virtual void vertices(void* indices, int count, Collision_vector* out);
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
    __forceinline float radius() const
    {
        return m_10;
    }
};
struct Collision_mat
{
    __m128 m_00, m_10, m_20, m_30;
};
struct Collision_hit
{
    Collision_vector normal;
    float fraction;
};
extern const float DAT_01017718, DAT_01016248, DAT_01011d78;
extern const __m128 DAT_010c44d0;
extern const signed char DAT_010cb438[], DAT_010cb440[], DAT_010cb442[];
extern int FUN_00d22e40(Collision_vector*, Collision_vector*, Collision_vector*, Collision_vector*, Collision_vector*);
struct SmallBool
{
    char value;
    __forceinline SmallBool(bool v) : value(v)
    {}
    __forceinline SmallBool(const SmallBool& v) : value(v.value)
    {}
};
struct Collision_workspace
{
    int countA, countB, low, high, unk10, changed, unk18, unk1c;
    __forceinline void append(Collision_vector& value, int index)
    {
        a[index] = value;
        int next = countA;
        next++;
        countA = next;
    }
    Collision_vector a[4];
    Collision_vector sourceA[4];
    Collision_vector b[4];
    Collision_vector sourceB[4];
    Collision_vector axis;
    Collision_vector witnesses[4];
    int oldCountB, unk174, unk178, unk17c;
    int FUN_00da8500(Collision_vector*, Collision_vector*, int);
    int FUN_00da9340(Collision_vector*, Collision_vector*, int*, int*, SmallBool, int);
    __forceinline int updateSimplex(Collision_vector& edgeB);
    SmallBool FUN_00da9b30(Collision_vcls*, Collision_vcls*, Collision_mat*, Collision_vector*, Collision_hit*);
};
static __forceinline __m128 broadcast(const float* value)
{
    __m128 scalar = _mm_load_ss(value);
    return _mm_shuffle_ps(scalar, scalar, 0);
}
static __forceinline __m128 sum3(__m128 v)
{
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    __m128 s = _mm_add_ss(y, v);
    __m128 z = _mm_shuffle_ps(v, v, 0xaa);
    return _mm_add_ss(z, s);
}
static __forceinline __m128 dot(__m128 a, __m128 b)
{
    return sum3(_mm_mul_ps(a, b));
}
static __forceinline void flipSignC(Collision_vector& v, const Collision_vector& d)
{
    v.simd() = _mm_xor_ps(_mm_and_ps(_mm_shuffle_ps(d.simd(), d.simd(), 0), DAT_010c44d0), v.simd());
}
extern const __m128 DAT_01017d10;
extern const float DAT_0104da48, DAT_010c6090;

extern const __m128 DAT_010c7160;

class ContactScalar
{
  public:
    ContactScalar()
    {}
    ContactScalar(const __m128& input) : value(input)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }

  private:
    __m128 value;
};
__forceinline ContactScalar operator-(const ContactScalar& scalar)
{
    return _mm_sub_ss(DAT_010c7160, scalar.getQuad());
}

class ContactVector
{
  public:
    __forceinline void operator=(const ContactVector& source)
    {
        value = source.value;
    }
    __forceinline __m128& getQuad()
    {
        return value;
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int index)
    {
        return value.m128_f32[index];
    }
    __forceinline void setSub4(const ContactVector& lhs, const ContactVector& rhs)
    {
        value = _mm_sub_ps(lhs.value, rhs.value);
    }
    __forceinline void setAdd4(const ContactVector& lhs, const ContactVector& rhs)
    {
        value = _mm_add_ps(lhs.value, rhs.value);
    }
    __forceinline void setMul4(const ContactVector& lhs, const ContactVector& rhs)
    {
        value = _mm_mul_ps(lhs.value, rhs.value);
    }
    __forceinline void mul4(const ContactScalar& scale)
    {
        value = _mm_mul_ps(scale.broadcast(), value);
    }
    __forceinline void subMul4(const ContactScalar& scale, const ContactVector& rhs)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(scale.broadcast(), rhs.value));
    }
    __forceinline void SetAllComponents(const ContactScalar& scalar)
    {
        value = scalar.broadcast();
    }
    __forceinline void setW(const ContactVector& rhs)
    {
        value = _mm_shuffle_ps(value, _mm_unpackhi_ps(value, rhs.value), 0xc4);
    }
    __forceinline void setCross(const ContactVector& lhs, const ContactVector& rhs)
    {
        __m128 positive =
            _mm_mul_ps(_mm_shuffle_ps(lhs.value, lhs.value, 0xc9), _mm_shuffle_ps(rhs.value, rhs.value, 0xd2));
        __m128 negative =
            _mm_mul_ps(_mm_shuffle_ps(lhs.value, lhs.value, 0xd2), _mm_shuffle_ps(rhs.value, rhs.value, 0xc9));
        value = _mm_sub_ps(positive, negative);
    }
    __forceinline ContactScalar dot3(const ContactVector& rhs) const
    {
        __m128 products = _mm_mul_ps(value, rhs.value);
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), partial);
    }
    __forceinline ContactScalar horizontalAdd3() const
    {
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(value, value, 0x55), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 0xaa), partial);
    }
    __forceinline ContactScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline ContactScalar lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot3(*this).getQuad();
        const __m128 mask = _mm_cmpeq_ss(squared, zero);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate));
        const __m128 inverse = _mm_mul_ss(_mm_mul_ss(half, estimate), correction);
        return _mm_andnot_ps(mask, inverse);
    }
    __forceinline void normalize3()
    {
        __m128 scale = lengthInverse3().broadcast();
        value = _mm_mul_ps(scale, value);
    }
    __forceinline ContactScalar normalizeWithLength3()
    {
        __m128 squared = dot3(*this).getQuad();
        __m128 scale = lengthInverse3().broadcast();
        value = _mm_mul_ps(scale, value);
        return _mm_mul_ss(squared, scale);
    }

  private:
    __m128 value;
};

class StoredDistance
{
  public:
    StoredDistance()
    {}
    operator float() const
    {
        return value;
    }
    void operator=(float input)
    {
        value = input;
    }

  private:
    float value;
};
struct ContactClosest
{
    ContactVector point;
    ContactVector delta;
    StoredDistance distanceSquared;
};
int FUN_00d22e40(const ContactVector&, const ContactVector&, const ContactVector&, const ContactVector&,
                 ContactClosest&);

extern const __m128 DAT_01017d10;
extern const float DAT_010c6090;
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

hkVector4* g_v;
hkVector4* g_p;
float g_f;
int g_out;

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);

class GapScalar
{
    __m128 data;

  public:
    GapScalar(const __m128& v) : data(v)
    {}
    GapScalar(float f) : data(_mm_load_ss(&f))
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, data);
        return f;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(data, data, 0);
    }
    __forceinline const __m128& bits() const
    {
        return data;
    }
};
class GapVector;
class GapRotation;
class GapTransform;
class GapVector
{
    __m128 data;

  public:
    __forceinline void operator=(const GapVector& v)
    {
        data = v.data;
    }
    __forceinline __m128& bits()
    {
        return data;
    }
    __forceinline const __m128& bits() const
    {
        return data;
    }
    operator __m128() const
    {
        return data;
    }
    __forceinline void edgeSubtract(const GapVector& a, const GapVector& b)
    {
        __m128 anchor = b.data;
        __m128& root = anchor;
        data = _mm_sub_ps(a.data, root);
    }
    __forceinline void fill(const GapScalar& f)
    {
        data = f.splat();
    }
    __forceinline void subtract(const GapVector& a, const GapVector& b)
    {
        data = _mm_sub_ps(a.data, b.data);
    }
    __forceinline void scale(const GapScalar& f)
    {
        data = _mm_mul_ps(data, f.splat());
    }
    __forceinline void cross(const GapVector& a, const GapVector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 0xc9), _mm_shuffle_ps(b.data, b.data, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 0xd2), _mm_shuffle_ps(b.data, b.data, 0xc9));
        data = _mm_sub_ps(first, second);
    }
    __forceinline void negate(const GapVector& v)
    {
        static __declspec(align(16)) const unsigned mask[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
        data = _mm_xor_ps(v.data, *reinterpret_cast<const __m128*>(mask));
    }
    __forceinline void inverseDirection(const GapRotation&, const GapVector&);
    __forceinline void transformPosition(const GapTransform&, const GapVector&);
    __forceinline GapScalar dot(const GapVector& b) const
    {
        __m128 p = _mm_mul_ps(data, b.data);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), sum);
    }
    __forceinline GapScalar squaredLength() const
    {
        return dot(*this);
    }
    __forceinline GapScalar inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        __m128 len = dot(*this).bits();
        __m128 eq = _mm_cmpeq_ss(len, zero), inv = _mm_rsqrt_ss(len);
        __m128 refined = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, inv), inv)));
        return _mm_andnot_ps(eq, refined);
    }
    __forceinline void normalize()
    {
        __m128 factor = inverseLength().splat();
        data = _mm_mul_ps(factor, data);
    }
    __forceinline void fastNormalize()
    {
        __m128 len = dot(*this).bits();
        GapScalar inv = _mm_rsqrt_ss(len);
        data = _mm_mul_ps(data, inv.splat());
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&data)[i];
    }
};
class GapRotation
{
    GapVector x, y, z;

  public:
    __forceinline GapVector& column(int i)
    {
        return (&x)[i];
    }
    __forceinline const GapVector& column(int i) const
    {
        return (&x)[i];
    }
};
class GapTransform
{
    GapRotation rotation;
    GapVector translation;

  public:
    __forceinline GapTransform(const GapTransform& t)
    {
        const GapVector a = t.rotation.column(0), b = t.rotation.column(1), c = t.rotation.column(2),
                        d = t.rotation.column(3);
        rotation.column(0) = a;
        rotation.column(1) = b;
        rotation.column(2) = c;
        rotation.column(3) = d;
    }
    __forceinline const GapRotation& orientation() const
    {
        return rotation;
    }
    __forceinline const GapVector& offset() const
    {
        return translation;
    }
};
template <class T> class GapValue
{
    T value;

  public:
    __forceinline GapValue()
    {}
    __forceinline void operator=(T v)
    {
        value = v;
    }
    __forceinline T val() const
    {
        return value;
    }
    __forceinline operator T() const
    {
        return val();
    }
};
struct GapBool
{
    char value;
    GapBool(bool b) : value(static_cast<char>(b))
    {}
};
class GapVertex : public GapVector
{
};
struct GapShape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void support(const GapVector&, GapVertex&) const;
};
struct GapLineResult
{
    GapVector point, difference;
    GapValue<float> distance;
};
int __cdecl FUN_00d22e40(const GapVector&, const GapVector&, const GapVector&, const GapVector&, GapLineResult&);
namespace GapMath {
inline int negative(const GapScalar& v)
{
    return _mm_movemask_ps(v.bits()) & 1;
}
}
extern const signed char DAT_010cb438[], DAT_010cb440[];
namespace GapUtil {
}
enum GapStatus
{
    GAP_OK,
    GAP_SAMPLED,
    GAP_NO_MEMORY,
    GAP_UNSOLVABLE,
    GAP_PENETRATING
};
class GapSolver
{
  public:
    enum
    {
        GSK_NONE_NONE = 0,
        GSK_POINT_POINT = 9,
        GSK_POINT_EDGE = 10,
        GSK_POINT_TRIANGLE = 11,
        GSK_POINT_TETRA = 12,
        GSK_EDGE_POINT = 17,
        GSK_EDGE_EDGE = 18,
        GSK_EDGE_TRIANGLE = 19,
        GSK_TRIANGLE_POINT = 25,
        GSK_TRIANGLE_EDGE = 26,
        GSK_TETRA_POINT = 33
    };
    enum NextCase
    {
        NEXT_IS_BREAK,
        NEXT_IS_PENETRATION,
        NEXT_IS_EDGE_EDGE
    };
    enum SupportTypes
    {
        BUILD_NEG_SUPPORT = -1,
        BUILD_NO_SUPPORT = 0,
        BUILD_POS_SUPPORT = 1
    };
    enum SupportState
    {
        SUPPORT_CHANGED = 0,
        DONT_CALL_GET_SUPPORTING_VERTEX_A = 1,
        DONT_CALL_GET_SUPPORTING_VERTEX_B = -1
    };
    enum ReduceDimensionResult
    {
        REDUCE_DIMENSION_OK,
        REDUCE_DIMENSION_PENETRATION
    };
    GapValue<int> countA, countB, limitA, limitB;
    GapValue<unsigned> skipPenetration;
    GapValue<int> changed;
    GapVertex verticesA[4];
    GapVector sourceA[4], verticesB[4];
    GapVertex sourceB[4];
    GapVector axis;
    GapLineResult closest;
    GapVector dots;
    GapValue<int> previousB;
    SupportState supportState;
    __forceinline ReduceDimensionResult reduce();
    __forceinline void mark(int f)
    {
        changed = f;
    }
    void FUN_00daa7e0(const GapShape*, const GapShape*, const GapTransform&);
    int FUN_00da8500(const GapVector&, GapVector*, SupportTypes);
    NextCase FUN_00da9340(GapVector*, GapVector*, GapValue<int>&, GapValue<int>&, GapBool, SupportTypes);
    GapStatus FUN_00daad40(const GapShape*, const GapShape*, const GapTransform&, GapVector&);
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_rsqrt_ss(__m128 a);
extern "C" int _mm_movemask_ps(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int imm);

struct VectorDA
{
    __m128 quad;
    VectorDA()
    {}
    VectorDA(const VectorDA& v) : quad(v.quad)
    {}
    VectorDA& operator=(const VectorDA& v)
    {
        quad = v.quad;
        return *this;
    }
};
struct SimplexDA
{
    VectorDA m_kPointA[4];
    VectorDA m_kPointB[4];
};

static SimplexDA g_sxDA;
static int g_numDA;
static VectorDA g_outDA;
static VectorDA g_ppDA;

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_set_ps1(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
}

struct AlignedPoint
{
    __m128 quad;
    AlignedPoint()
    {}
    AlignedPoint& operator=(const AlignedPoint& v)
    {
        quad = v.quad;
        return *this;
    }
};
struct SolverOutput
{
    AlignedPoint normal, point;
    float distance;
};
extern void __cdecl FUN_00d22e40(const AlignedPoint* polygon, const AlignedPoint* direction, const AlignedPoint* vertex,
                                 const AlignedPoint* edge, SolverOutput* result);

template <class T> struct S00daac40_RayArgument
{
    T value;
    __forceinline operator T() const
    {
        return value;
    }
};
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;

extern "C" unsigned __int64 __rdtsc(void);

struct S00daac40_ProfRec
{
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};

struct S00daac40_ProfBuf
{
    unsigned long unk00;
    S00daac40_ProfRec* m_pCur;
    unsigned long unk08;
    S00daac40_ProfRec* m_pRecordEnd;
};

struct S00daac40_Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct S00daac40_Mat3
{
    S00daac40_Vec4 r0;
    S00daac40_Vec4 r1;
    S00daac40_Vec4 r2;
};

struct S00daac40_RayParams
{
    unsigned long unk00;
    unsigned long unk04;
    S00daac40_Vec4 m_v08;
    unsigned long unk18;
    unsigned long unk1C;
    unsigned long unk20;
    unsigned long unk24;
    unsigned long unk28;
    unsigned long unk2C;
    unsigned long unk30;
    unsigned long unk34;
    unsigned long unk38;
    unsigned long unk3C;
    unsigned long unk40;
    unsigned long unk44;
    unsigned long unk48;
    unsigned long unk4C;
};

class S00daac40_FUN_00daac40_cls
{
  public:
    bool* hkpGsk_castRay(S00daac40_RayArgument<bool*> out, int p2, int p3,
                       S00daac40_RayArgument<S00daac40_RayParams*> p4);
    void FUN_00da9b30(bool* hit, int p2, int zero, S00daac40_Mat3* m, int p3, S00daac40_RayParams* p);
};

// Records a GJK ray-cast profile tick, runs FUN_00da9b30 with an identity matrix, and sets out true when hit and local.m_v08.z is non-zero.
// @f3 0x00a32c80 (community match, verified in this file)
struct F3MirrorTarget
{
    void FUN_00a30fb0(bool* hit, int p2, int zero, S00daac40_Mat3* m, int p3, S00daac40_RayParams* p);
};
struct F3MirrorCast
{
    void FUN_007c8a50(S00daac40_RayParams* p);
};

// pdb: hkpGsk::castRay | hkpGsk.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
bool* S00daac40_FUN_00daac40_cls::hkpGsk_castRay(S00daac40_RayArgument<bool*> out, int p2, int p3,
                                               S00daac40_RayArgument<S00daac40_RayParams*> apRayParams)
{
    __declspec(align(16)) S00daac40_Mat3 m;
    S00daac40_RayParams rayParams;
    bool hit;

    HK_TIMER_BEGIN("GJK Ray Cast", HK_NULL);

    rayParams = *apRayParams;

    m.r0.y = 0.0f;
    m.r0.z = 0.0f;
    m.r0.w = 0.0f;
    m.r1.x = 0.0f;
    m.r1.z = 0.0f;
    m.r1.w = 0.0f;
    m.r2.x = 0.0f;
    m.r2.y = 0.0f;
    m.r2.w = 0.0f;
    m.r0.x = 1.0f;
    m.r1.y = 1.0f;
    m.r2.z = 1.0f;

    ((F3MirrorTarget*)this)->FUN_00a30fb0(&hit, p2, 0, &m, p3, &rayParams);

    HK_TIMER_END();

    if (hit && rayParams.m_v08.z != 0.0f)
    {
        ((F3MirrorCast*)(S00daac40_RayParams*)apRayParams)->FUN_007c8a50(&rayParams);
        bool* destination = out;
        *destination = true;
        return destination;
    }
    bool* destination = out;
    *destination = false;
    return destination;
}

