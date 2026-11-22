#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpRagdollConstraintData.h"

// @fnv 0x00cde9d0
// pdb: hkpRagdollConstraintData::getRuntimeInfo | hkpRagdollConstraintData.obj | tesv_win, objrun_open, low
void __stdcall FUN_00cde9d0(int* apUnused, int* apiOut)
{
    apiOut[1] = 0xc;
    apiOut[0] = 0x80;
}

struct DDCC60World
{
    void __thiscall removeReference(void);
};

struct FUN_00cdf1f0
{
    void* m_ppVirtualMethodTable;          // +0x00
    char pad[0xdc];          // +0x04 .. +0xdf
    DDCC60World* m_refs[3];  // +0xe0
    ~FUN_00cdf1f0();
};

// @f3 0x0095a640 (community match, verified in this file)
extern int DAT_00e7c094;
extern int DAT_00dcc494;
struct Ref403 {
    virtual void Destroy(unsigned int deleting);
    unsigned short sizeFlags;
    short references;
    void RemoveReference() {
        if (sizeFlags) {
            --references;
            if (references == 0)
                Destroy(1);
        }
    }
};
// pdb: hkpRagdollConstraintData::~hkpRagdollConstraintData | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_seq, medium
FUN_00cdf1f0::~FUN_00cdf1f0() {
    m_ppVirtualMethodTable = &DAT_00e7c094;
    for (int i = 0; i < 3; ++i) {
        Ref403* ref = reinterpret_cast<Ref403*>(m_refs[i]);
        if (ref)
            ref->RemoveReference();
    }
    m_ppVirtualMethodTable = &DAT_00dcc494;
}


// @fnv 0x00cdead0
// pdb: CombatProcedureBeInCover::GetType | CombatProcedureBeInCover.obj | fnv360_0822_retail, vtable, high
int __cdecl FUN_00cdead0()
{
    return 7;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
struct __declspec(align(16)) FUN_00cdf190_Vec
{
    float x;
    float y;
    float z;
    float w;
};

extern "C" __m128 _mm_setzero_ps(void);

struct hkVector4B90
{
    __m128 m_vComponents;

    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkRotationB90
{
    hkVector4B90 m_kColumn0, m_kColumn1, m_kColumn2;

    __forceinline void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransformB90
{
    hkRotationB90 m_rotation;
    hkVector4B90 m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct hkBoolB90
{
    char m_cBooleanValue;
    __forceinline hkBoolB90& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct hkpConstraintAtomB90
{
    unsigned short m_type;
};

struct hkpSetLocalTransformsConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned short unk02;
    int unk04, unk08, unk0C;
    hkTransformB90 m_kBodyALocalFrame;
    hkTransformB90 m_kBodyBLocalFrame;
};

struct hkpAngMotorConstraintAtomB90 : public hkpConstraintAtomB90
{
    hkBoolB90 m_bLimitEnabled;
    unsigned char m_ucMotorAxis;
    short m_iInitializedOffset;
    short m_iPreviousTargetAngleOffset;
    short m_iCorrespondingAngLimitSolverResultOffset;
    float m_fTargetAngle;
    void* m_pMotor;
};

struct hkpAngFrictionConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_bLimitEnabled;
    unsigned char m_ucFirstFrictionAxis;
    unsigned char m_ucNumFrictionAxes;
    float m_fMaxFrictionTorque;
};

struct hkpAngLimitConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_bLimitEnabled;
    unsigned char m_ucLimitAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};

struct hkp2dAngConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_ucFreeRotationAxis;
};

struct hkpBallSocketConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_ucBodiesToNotify;
    unsigned char unk03;
    float m_usFlags;
};

class __declspec(align(16)) FUN_00cb9170
{
  public:
    FUN_00cb9170() throw();

    hkpSetLocalTransformsConstraintAtomB90 m_kTransforms;
    hkpAngMotorConstraintAtomB90 m_kAngularMotor;
    hkpAngFrictionConstraintAtomB90 m_kFriction;
    hkpAngLimitConstraintAtomB90 m_kAngularLimit;
    hkp2dAngConstraintAtomB90 m_kTwoDimensionalAngular;
    hkpBallSocketConstraintAtomB90 m_kBallSocket;
};

class hkReferencedObjectB90
{
  public:
    hkReferencedObjectB90() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectB90() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpConstraintDataB90 : public hkReferencedObjectB90
{
  public:
    hkpConstraintDataB90() throw()
    {
        m_ulUserData = 0;
    }
    virtual ~hkpConstraintDataB90() throw()
    {}

    unsigned long m_ulUserData;
};

extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkMatrix3q
{
    hkVector4q m_col[3];

    __forceinline void operator=(const hkMatrix3q& m)
    {
        m_col[0].m_vComponents = m.m_col[0].m_vComponents;
        m_col[1].m_vComponents = m.m_col[1].m_vComponents;
        m_col[2].m_vComponents = m.m_col[2].m_vComponents;
    }
};

extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);

extern const __m128 DAT_010c71e0;

struct Quat
{
    __m128 m_vec;
    void hkQuaternion_setAxisAngle(const __m128* axis, float angle);
};

struct Vec4
{
    __m128 m_vComponents;
    __forceinline void setCross(const Vec4& a, const Vec4& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline void setBroadcast3(const Vec4& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void setMul4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const Vec4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void addMul4(__m128 s, const Vec4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void addMul4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline __m128 dot3(const Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
    __forceinline void SetRotatedDirection(const Quat& quat, const Vec4& direction)
    {
        const Vec4& imag = *(const Vec4*)&quat.m_vec;
        Vec4 qreal;
        qreal.setBroadcast3(imag);
        Vec4 q2minus1;
        q2minus1.setMul4(qreal, qreal);
        q2minus1.add4(*(const Vec4*)&DAT_010c71e0);
        Vec4 ret;
        ret.setMul4(direction, q2minus1);
        __m128 imagDotDir = imag.dot3(direction);
        ret.addMul4(imagDotDir, imag);
        Vec4 imagCrossDir;
        imagCrossDir.setCross(imag, direction);
        ret.addMul4(imagCrossDir, qreal);
        setAdd4(ret, ret);
    }
};

namespace fnv_00cb9170 {
struct FUN_00ca9360_sub
{
    void FUN_00ca9360(float*);
};

struct FUN_00cb9170
{
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    unsigned short m_10;
    unsigned short m_12;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
    unsigned short m_1a;
    unsigned short m_1c;
    unsigned short m_1e;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    unsigned short m_26;
    unsigned short m_28;
    unsigned short m_2a;
    unsigned short m_2c;
    unsigned short m_2e;
    unsigned short m_30;
    unsigned short m_32;
    unsigned short m_34;
    unsigned short m_36;
    unsigned short m_38;
    unsigned short m_3a;
    unsigned short m_3c;
    unsigned short m_3e;
    unsigned short m_40;
    unsigned short m_42;
    unsigned short m_44;
    unsigned short m_46;
    unsigned short m_48;
    unsigned short m_4a;
    unsigned short m_4c;
    unsigned short m_4e;
    unsigned short m_50;
    unsigned short m_52;
    unsigned short m_54;
    unsigned short m_56;
    unsigned short m_58;
    unsigned short m_5a;
    unsigned short m_5c;
    unsigned short m_5e;
    unsigned short m_60;
    unsigned short m_62;
    unsigned short m_64;
    unsigned short m_66;
    unsigned short m_68;
    unsigned short m_6a;
    unsigned short m_6c;
    unsigned short m_6e;
    unsigned short m_70;
    unsigned short m_72;
    unsigned short m_74;
    unsigned short m_76;
    unsigned short m_78;
    unsigned short m_7a;
    unsigned short m_7c;
    unsigned short m_7e;
    unsigned short m_80;
    unsigned short m_82;
    unsigned short m_84;
    unsigned short m_86;
    unsigned short m_88;
    unsigned short m_8a;
    unsigned short m_8c;
    unsigned short m_8e;
    volatile unsigned short m_90;
    volatile unsigned char m_92;
    unsigned char m_93;
    volatile unsigned short m_94;
    volatile unsigned short m_96;
    unsigned char m_98;
    unsigned char m_99;
    unsigned char m_9a;
    unsigned char m_9b;
    unsigned char m_9c;
    unsigned char m_9d;
    unsigned char m_9e;
    unsigned char m_9f;
    unsigned char m_a0;
    unsigned char m_a1;
    unsigned char m_a2;
    unsigned char m_a3;
    volatile unsigned short m_a4;
    volatile unsigned char m_a6;
    unsigned char m_a7;
    volatile unsigned char m_a8;
    unsigned char m_a9;
    unsigned char m_aa;
    unsigned char m_ab;
    unsigned char m_ac;
    unsigned char m_ad;
    unsigned char m_ae;
    unsigned char m_af;
    volatile unsigned short m_b0;
    volatile unsigned char m_b2;
    unsigned char m_b3;
    unsigned char m_b4;
    unsigned char m_b5;
    unsigned char m_b6;
    unsigned char m_b7;
    unsigned char m_b8;
    unsigned char m_b9;
    unsigned char m_ba;
    unsigned char m_bb;
    unsigned char m_bc;
    unsigned char m_bd;
    unsigned char m_be;
    unsigned char m_bf;
    volatile unsigned short m_c0;
    unsigned char m_c2;
    unsigned char m_c3;
    volatile unsigned short m_c4;
    unsigned char m_c6;
    FUN_00ca9360_sub m_c7;
    float m_fC8;
    FUN_00cb9170();
};
}  // namespace fnv_00cb9170

// @f3twin 0x0095a050 of 0x004a0640
// pdb: hkpRagdollConstraintData::getMotorsActive | hkpRagdollConstraintData.obj | fnv360_0822_retail, objrun_sim, low
int __cdecl F3_FUN_0095a050()
{
    return 7;
}
