#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/limitedhinge/hkplimitedhingeconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/limitedhinge/hkplimitedhingeconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpLimitedHingeConstraintData.h"

struct FUN_00cb8af0_cls
{
    void* __thiscall FUN_00cb8af0(int arg);
};

// @f3 0x0043bce0 (community match, verified in this file)
extern void* __cdecl FUN_00564400(int arg, void* member, int mode);

// pdb: TESDataHandler::AddTopic | TESDataHandler.obj | fnv360_0822_retail, objrun, medium
// pdb params: pNewTopic
void* FUN_00cb8af0_cls::FUN_00cb8af0(int arg)
{
    return FUN_00564400(arg, (char*)this + 0xcc, 1);
}


struct FUN_00cb8b10Class
{
    void __thiscall FUN_00cb8b10(int* a1, int* a2);
};

// @fnv 0x00cb8b10
// pdb: hkpLimitedHingeConstraintData::getInertiaStabilizationFactor | hkpLimitedHingeConstraintData.obj | tesv_win, objrun_open, low
void __thiscall FUN_00cb8b10Class::FUN_00cb8b10(int* apUnused, int* a2)
{
    a2[1] = 8;
    a2[0] = 80;
}

// Stores b at self+0xa2 and its negation at self+0xb6; if a is non-null, zeroes four floats at a->0x30->0x1c.
// @f3 0x0092b6d0 (community match, verified in this file)
// pdb: hkpLimitedHingeConstraintData::setMotorActive | hkpLimitedHingeConstraintData.obj | fnv360_0822_retail, call_seq, medium
// pdb params: instance, toBeEnabled
void __fastcall FUN_00cb8fe0(char* self, int, int a, bool b)
{
    self[0xa2] = b;
    self[0xb6] = !b;
    if (a)
    {
        int* p = *(int**)((char*)a + 0x28);
        if (p)
        {
            float* f = *(float**)((char*)p + 0x1c);
            if (f)
            {
                f[0] = 0.0f;
                f[1] = 0.0f;
                f[2] = 0.0f;
                f[3] = 0.0f;
            }
        }
    }
}


// @fnv 0x00cb8b30
// pdb: hkpLimitedHingeConstraintData::getNotifiedBodyIndex | hkpLimitedHingeConstraintData.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00cb8b30()
{
    return 2;
}

struct hkBoolCB90
{
    char m_cBooleanValue;
    hkBoolCB90()
    {}
    hkBoolCB90(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkTransformCB90
{
    float m_data[16];
    hkBoolCB90 IsOrthonormal(float eps) const;
};

class hkObjCB90
{
  public:
    int unk00[8];
    hkTransformCB90 m_kPointA;
    hkTransformCB90 m_kPointB;
    char unkA0[2];
    bool m_hasC;
    char unkA3[0x1f];
    bool m_cValid;

    hkBoolCB90 FUN_00cb9020() const;
};

// @fnv 0x00cb9020
// pdb: hkpLimitedHingeConstraintData::isValid | hkpLimitedHingeConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkpHingeConstraintData::isValid)
hkBoolCB90 hkObjCB90::FUN_00cb9020() const
{
    return m_kPointA.IsOrthonormal(1e-3f) && m_kPointB.IsOrthonormal(1e-3f) && (!m_hasC || m_cValid);
}

struct FUN_00b5aea0_self
{
    void FUN_00cb9930(int* a, int* b, unsigned int c);
};

struct FUN_00cb9ce0_cls
{
    virtual void v0();
    virtual void* v1(int a);
    virtual void v2(int a);
    virtual int v3(int a, int b);
    virtual void v4(int a, int b);
    int m_004;
    int m_008;
    int m_00c;
    void FUN_00cb9ce0(int a, int b);
};

// @fnv 0x00cb9ce0
// pdb: BSSimpleArray<unsigned short,1024>::AddUninitialized | NavMesh.obj | fnv360_0721_beta, call_seq, low, conflict (bridge: BSSimpleArray<unsigned short,1024>::SetSize)
void FUN_00cb9ce0_cls::FUN_00cb9ce0(int a, int b)
{
    if (m_004)
    {
        if (b == m_00c)
        {
            m_004 = v3(m_004, a);
        }
        else
        {
            int r = reinterpret_cast<int>(v1(a));
            reinterpret_cast<FUN_00b5aea0_self*>(this)->FUN_00cb9930(reinterpret_cast<int*>(r),
                                                                     reinterpret_cast<int*>(m_004), b);
            v2(m_004);
            m_004 = r;
        }
    }
    else
    {
        int r = reinterpret_cast<int>(v1(a));
        m_00c = a;
        m_004 = r;
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);

struct hkVector4D4FE
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

struct hkRotationD4FE
{
    hkVector4D4FE m_kColumn0, m_kColumn1, m_kColumn2;

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

struct hkTransformD4FE
{
    hkRotationD4FE m_rotation;
    hkVector4D4FE m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

class __declspec(align(16)) FUN_00d4ff60
{
  public:
    FUN_00d4ff60() throw();

    unsigned short m_transformsType;
    unsigned short unk02;
    int unk04, unk08, unk0C;
    hkTransformD4FE m_kBodyALocalFrame;
    hkTransformD4FE m_kBodyBLocalFrame;
    unsigned short m_stabilizationType;
    volatile unsigned char m_stabilizationEnabled;
    volatile unsigned char m_motorEnabled;
    volatile short m_iInitializedOffset;
    volatile short m_iPreviousTargetAngleOffset;
    volatile float m_fTargetAngle;
    volatile unsigned long m_pMotor;
    unsigned short m_frictionType;
    unsigned char unkA2;
    volatile unsigned char m_frictionEnabled;
    volatile float m_fMaxFrictionTorque;
    unsigned short m_ang2dType;
    volatile unsigned char m_ang2dEnabled;
    volatile unsigned char m_ang2dFreeAxis;
    unsigned short m_angTypeB;
    volatile unsigned char m_angAxisB;
    unsigned char unkAF;
    unsigned short m_angTypeC;
    volatile unsigned char m_angAxisC;
    unsigned char unkB3;
    unsigned short m_limitType;
    volatile unsigned char m_limitEnabled;
    unsigned char unkB7;
    volatile float m_fMinAngle;
    volatile float m_fMaxAngle;
    int unkC0, unkC4, unkC8, unkCC;
};

class hkReferencedObjectD4FE
{
  public:
    hkReferencedObjectD4FE() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD4FE() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpConstraintDataD4FE : public hkReferencedObjectD4FE
{
  public:
    hkpConstraintDataD4FE() throw()
    {
        m_ulUserData = 0;
    }
    virtual ~hkpConstraintDataD4FE() throw()
    {}

    unsigned long m_ulUserData;
};

#include <math.h>
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
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

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct hkVector4_Havok
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4_Havok& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void normalize3()
    {
        __m128 mul = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 xy = _mm_add_ss(y, mul);
        __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
        __m128 lenSq = _mm_add_ss(z, xy);
        __m128 r = _mm_rsqrt_ss(lenSq);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 half = _mm_set_ss(0.5f);
        __m128 r_sq = _mm_mul_ss(_mm_mul_ss(lenSq, r), r);
        __m128 diff = _mm_sub_ss(three, r_sq);
        __m128 half_r = _mm_mul_ss(half, r);
        __m128 nr = _mm_mul_ss(half_r, diff);
        __m128 mask = _mm_cmpeq_ss(lenSq, zero);
        __m128 inv = _mm_andnot_ps(mask, nr);
        __m128 inv4 = _mm_shuffle_ps(inv, inv, 0);
        m_vComponents = _mm_mul_ps(inv4, m_vComponents);
    }

    __forceinline void setCross(const hkVector4_Havok& a, const hkVector4_Havok& b)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
    }
};
