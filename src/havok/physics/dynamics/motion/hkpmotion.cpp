#include "f3_common.h"
// src/havok/physics/dynamics/motion/hkpmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/hkpmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMotion.h"

extern "C" void __cdecl SetMotionState(void*, void*);

struct FUN_00c86400_Class : public hkpMotion
{
    void __thiscall FUN_00c86400(void* a);
};

// @fnv 0x00c86400
// pdb: hkpMotion::setTransform | hkpMotion.obj | tesv_win, objrun, medium
void __thiscall FUN_00c86400_Class::FUN_00c86400(void* a)
{
    SetMotionState(a, &m_kMotionState);
}

struct FUN_00c86420_Class : public hkpMotion
{
    void __thiscall FUN_00c86420(char a);
};
// @fnv 0x00c86420
// pdb: hkpMotion::setDeactivationClass | hkpMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: deactivationClass
void __thiscall FUN_00c86420_Class::FUN_00c86420(char a)
{
    m_kMotionState.m_uiDeactivationClass = a;
}

struct FUN_00c86480_Class : public hkpMotion
{
    void __thiscall FUN_00c86480(float v);
};
// @fnv 0x00c86480
void __thiscall FUN_00c86480_Class::FUN_00c86480(float v)
{
    m_kInertiaAndMassInv.w = v;
}

struct FUN_00c86330_Class
{
    void __thiscall FUN_00c86330(float mass);
};

// Computes the inverse of mass (0 if mass is 0) and passes it to the virtual function at vtable slot 4.
// @fnv 0x00c86330
// pdb: hkpMotion::setMass | hkpMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: mass
void __thiscall FUN_00c86330_Class::FUN_00c86330(float mass)
{
    float invMass;
    if (mass == 0.0f)
    {
        invMass = 0.0f;
    }
    else
    {
        invMass = 1.0f / mass;
    }
    void** vtbl = *(void***)this;
    void(__thiscall * fn)(void*, float) = (void(__thiscall*)(void*, float))vtbl[4];
    fn(this, invMass);
}

extern "C" void __cdecl FUN_00cf20d0(void*, void*);
struct FUN_00c863a0_Class : public hkpMotion
{
    void __thiscall FUN_00c863a0(void* a);
};
// @fnv 0x00c863a0
// pdb: hkpMotion::setPosition | hkpMotion.obj | tesv_win, objrun, medium
void __thiscall FUN_00c863a0_Class::FUN_00c863a0(void* a)
{
    FUN_00cf20d0(a, &m_kMotionState);
}

extern "C" void __cdecl FUN_00cf2160(void*, void*);

struct FUN_00c863c0_Class : public hkpMotion
{
    void __thiscall FUN_00c863c0(void* a);
};

// @fnv 0x00c863c0
// pdb: hkpMotion::setRotation | hkpMotion.obj | tesv_win, caller_sim, low
void __thiscall FUN_00c863c0_Class::FUN_00c863c0(void* a)
{
    FUN_00cf2160(a, &m_kMotionState);
}

extern void __cdecl FUN_00cf1f80(void*, void*, void*);

struct FUN_00c863e0_Class : public hkpMotion
{
    void __thiscall FUN_00c863e0(void* param1, void* param2);
};

// @fnv 0x00c863e0
// pdb: hkpMotion::setPositionAndRotation | hkpMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: position, rotation
void FUN_00c863e0_Class::FUN_00c863e0(void* pFirst, void* pSecond)
{
    FUN_00cf1f80(pFirst, pSecond, &m_kMotionState);
}

struct FUN_00cf22d0_Class
{
    void __thiscall Evaluate(float value, void* result);
};

struct FUN_00c86490_Class
{
    char pad[0x50];
    FUN_00cf22d0_Class sweptTransform;

    void __thiscall SweepTransform(float value, void* result);
};

// @fnv 0x00c86490
// pdb: hkpMotion::approxTransformAt | hkpMotion.obj | fnv360_0822_retail, call_seq, medium
// pdb params: time, transformOut
void FUN_00c86490_Class::SweepTransform(float value, void* result)
{
    sweptTransform.Evaluate(value, result);
}

int __cdecl ApplyDelta(int, int);
// @fnv 0x00c86380
// pdb: hkpMotion::setCenterOfMassInLocal | hkpMotion.obj | tesv_win, objrun, medium
int __fastcall FUN_00c86380(unsigned int registerArg0, unsigned int registerArg1, unsigned int arg0)
{
    unsigned int callResult0 = (unsigned int)ApplyDelta((int)arg0, (int)(registerArg0 + 16u));
    return (int)callResult0;
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

struct hkVector4C864F
{
    __m128 m_vComponents;

    __m128 getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    void setMul4(const __m128& s, const hkVector4C864F& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents);
    }
    void setMul4(const hkVector4C864F& a, const hkVector4C864F& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4C864F& a, const hkVector4C864F& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4C864F& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void setCross(const hkVector4C864F& a, const hkVector4C864F& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

class hkBaseObjectC864F
{
  public:
    virtual ~hkBaseObjectC864F() throw();
};

class hkReferencedObjectC864F : public hkBaseObjectC864F
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpMotionC864F : public hkReferencedObjectC864F
{
  public:
    void ApplyImpulse(const hkVector4C864F& kImpulse);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4C864F m_motionState0[5];
    hkVector4C864F m_kCenterOfMass1;
    hkVector4C864F m_motionState1[5];
    hkVector4C864F m_kInertiaAndMassInv;
    hkVector4C864F m_kTranslationalVelocity;
    hkVector4C864F m_kAngularVelocity;
};

namespace fnv_00c86530 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4C865
{
    __m128 m_vComponents;

    hkVector4C865()
    {}
    hkVector4C865(const hkVector4C865& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4C865& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

class hkHalfC865
{
  public:
    hkHalfC865& operator=(const float& f)
    {
        int t = reinterpret_cast<const int*>(&f)[0];
        m_uiFilterValue = static_cast<short>(t >> 16);
        return *this;
    }

    short m_uiFilterValue;
};

class hkBaseObjectC865
{
  public:
    virtual ~hkBaseObjectC865() throw();
};

class hkReferencedObjectC865 : public hkBaseObjectC865
{
  public:
    hkReferencedObjectC865() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectC865() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

}  // namespace fnv_00c86530

namespace fnv_00c86610 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
}  // namespace fnv_00c86610

struct MotionMassView : hkpMotionC864F
{
    float hkpMotion_getMass();
};

// Reads the inverse-mass component from m_kInertiaAndMassInv, returns 0.0f if it is zero, otherwise returns its reciprocal as the mass.
// @f3 0x008f8410 (community match, verified in this file)
// pdb: hkpMotion::getMass | hkpMotion.obj | fnv360_0822_retail, call_seq + bridge(call_dedup|call_seq) + skyrim(call_seq), high
float MotionMassView::hkpMotion_getMass()
{
    float invMass = m_kInertiaAndMassInv.m_vComponents.m128_f32[3];
    if (invMass == 0.0f)
        return 0.0f;
    float mass = 1.0f / invMass;
    return mass;
}

