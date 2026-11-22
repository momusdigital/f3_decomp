#include "f3_common.h"
// src/havok/physics/dynamics/motion/rigid/hkpboxmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpboxmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBoxMotion.h"

struct FUN_00d1e670_StandIn
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4(float) = 0;

    void FUN_00d1e670(float);
};

// @fnv 0x00d1e670
// pdb: hkpBoxMotion::setMass | hkpBoxMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: mass
void FUN_00d1e670_StandIn::FUN_00d1e670(float value)
{
    f4(1.0f / value);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);

struct Cls_00d1e7b0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float m_c0;
    float m_c4;
    float m_c8;
    void WriteDiagonal(float* pOut);
};

struct StubVirt
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual __m128* FUN_00d1e7b0_get(__m128* pOut);
};

// pdb: bhkRigidBody::GetRotation | TESObjectREFR.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arRot
void Cls_00d1e7b0::WriteDiagonal(float* pOut)
{
    __m128 buf;
    __m128* p = ((StubVirt*)this)->FUN_00d1e7b0_get(&buf);
    pOut[1] = p->m128_f32[0];
    pOut[2] = p->m128_f32[1];
    pOut[3] = p->m128_f32[2];
    pOut[0] = p->m128_f32[3];
}


namespace fnv_00d1e810 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);

struct hkVector4D1E8
{
    __m128 m_vComponents;

    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
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

struct hkMatrix3D1E8
{
    hkVector4D1E8 m_kColumn0;
    hkVector4D1E8 m_kColumn1;
    hkVector4D1E8 m_kColumn2;

    const float& operator()(int r, int c) const
    {
        return (&m_kColumn0)[c](r);
    }
};

}  // namespace fnv_00d1e810

namespace fnv_00d1eba0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

class VectorComponentValue
{
  public:
    __m128 m_vValue;
    __forceinline VectorComponentValue()
    {}
    __forceinline VectorComponentValue(__m128 v) : m_vValue(v)
    {}
    __forceinline VectorComponentValue operator+(const VectorComponentValue& r) const
    {
        return VectorComponentValue(_mm_add_ss(m_vValue, r.m_vValue));
    }
    __forceinline operator hkReal() const
    {
        hkReal f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

class hkVector4A
{
  public:
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4A& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4A& a, const hkVector4A& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4A& a, const hkVector4A& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void setCross(const hkVector4A& v1, const hkVector4A& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline VectorComponentValue dot3(const hkVector4A& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return VectorComponentValue(_mm_add_ss(z, xySum));
    }

    __forceinline void _setRotatedInverseDir(const hkRotation& rotIn, const hkVector4A& b)
    {
        const hkVector4A* r = reinterpret_cast<const hkVector4A*>(&rotIn);
        __m128 c0 = r[0].m_vComponents;
        __m128 c1 = r[1].m_vComponents;
        __m128 c2 = r[2].m_vComponents;
        {
            __m128 tmp = _mm_unpacklo_ps(c0, c1);
            __m128 ctmp = _mm_unpackhi_ps(c0, c1);
            c0 = _mm_movelh_ps(tmp, c2);
            tmp = _mm_movehl_ps(c0, tmp);
            c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
            c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
        }
        const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        const __m128 r1 = _mm_mul_ps(b1, c1);
        const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        const __m128 r0 = _mm_mul_ps(b0, c0);
        const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        const __m128 r2 = _mm_mul_ps(c2, b2);
        m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
    }
};

__forceinline const hkVector4A& V(const hkVector4& v)
{
    return *reinterpret_cast<const hkVector4A*>(&v);
}

struct Cls_00d1eba0 : public hkpBoxMotion
{
    void GetVelocityAndInvVirtualMass(const hkVector4& p, const hkVector4& normal, hkReal& velOut,
                                      hkReal& invVirtMassOut) const;
};

// Computes the contact velocity and inverse virtual mass at point p with normal for a box motion body.
// @fnv 0x00d1eba0
void Cls_00d1eba0::GetVelocityAndInvVirtualMass(const hkVector4& p, const hkVector4& normal, hkReal& velOut,
                                                hkReal& invVirtMassOut) const
{
    hkVector4A arm;
    {
        hkVector4A relPos;
        relPos.setSub4(V(p), V(m_kMotionState.m_kSweptTransform.m_vCenterOfMass1));
        arm.setCross(relPos, V(normal));
    }
    velOut = V(m_kAngularVelocity).dot3(arm) + V(m_kTranslationalVelocity).dot3(V(normal));

    hkVector4A armLocal;
    armLocal._setRotatedInverseDir(m_kMotionState.m_kMotionTransform.m_rotation, arm);
    hkVector4A r;
    r.setMul4(V(m_kInertiaAndMassInv), armLocal);
    invVirtMassOut = m_kInertiaAndMassInv.w + r.dot3(armLocal);
}
}  // namespace fnv_00d1eba0

extern "C" __m128 _mm_max_ps(__m128, __m128);
extern __m128 DAT_010c7200;
struct V4
{
    __m128 q;
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
};
struct Mat3
{
    V4 c0, c1, c2;
    void FUN_00cd5880(const void* rot);
    float& operator()(int r, int c)
    {
        return (&c0)[c].q.m128_f32[r];
    }
    void setZero()
    {
        V4 z;
        z.setZero4();
        c0.q = z.q;
        c1.q = z.q;
        c2.q = z.q;
    }
    void setDiagonal(float a, float b, float c)
    {
        setZero();
        (*this)(0, 0) = a;
        (*this)(1, 1) = b;
        (*this)(2, 2) = c;
    }
};
struct BoxMotion
{
    int unk00, unk04, unk08, unk0C;
    hkTransform m_kMotionTransform;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    V4 m_kInertiaAndMassInv;
    void FUN_00d1e8c0(Mat3& out);
    void GetInverseScaleMatrix(Mat3& out)
    {
        V4 inv;
        inv.q = _mm_max_ps(m_kInertiaAndMassInv.q, DAT_010c7200);
        out.setDiagonal(1.0f / inv(0), 1.0f / inv(1), 1.0f / inv(2));
    }
};

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
}

typedef __m128 hkSimd;

struct hkVec4Q
{
    __m128 m_vComponents;

    __forceinline hkSimd getSimdAt(int) const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void addMul4(hkSimd r, const hkVec4Q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents));
    }
    __forceinline void setSub4(const hkVec4Q& a, const hkVec4Q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setCross(const hkVec4Q& v1, const hkVec4Q& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setMul4(const hkVec4Q& a, const hkVec4Q& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVec4Q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void _setRotatedDir(const struct hkMat3Q& r, const hkVec4Q& b);
    void _setRotatedInverseDir(const struct hkMat3Q& r, const hkVec4Q& b);
};

struct hkMat3Q
{
    hkVec4Q m_kColumn0, m_kColumn1, m_kColumn2;
};

extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" void _ReadWriteBarrier(void);

extern "C" __m128 _mm_setr_ps(float, float, float, float);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

extern "C" void _ReadWriteBarrier(void);

extern "C" __m128 _mm_load_ps1(const float* p);

struct hkVector4D1E6F
{
    __m128 m_vComponents;

    hkVector4D1E6F()
    {}
    hkVector4D1E6F(const hkVector4D1E6F& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D1E6F& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setMax4(const hkVector4D1E6F& a, const hkVector4D1E6F& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    void SetAllComponents(const float& f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }
    static hkVector4D1E6F all(const float& f)
    {
        hkVector4D1E6F v;
        v.SetAllComponents(f);
        return v;
    }
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

struct hkMatrix3D1E6F
{
    hkVector4D1E6F m_kColumn0;
    hkVector4D1E6F m_kColumn1;
    hkVector4D1E6F m_kColumn2;

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
