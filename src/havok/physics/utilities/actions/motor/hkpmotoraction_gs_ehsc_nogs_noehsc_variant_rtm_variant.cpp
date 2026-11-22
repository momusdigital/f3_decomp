#include "f3_common.h"
// src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpMotorAction.h"

#include <xmmintrin.h>

struct SimdReal
{
    __m128 m_vValue;
    SimdReal(const __m128& x) : m_vValue(x)
    {}
    SimdReal(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct Vec4
{
    __m128 m_vComponents;
    SimdReal dot3(const Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xAA), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        return res;
    }
    void setMul4(const SimdReal& r, const Vec4& a)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents);
    }
    void setRotatedInverseDir(const void* rot, const void* v);
    void FUN_00c7f750(const void* m, const Vec4& v);    // FUN_00c7f750
    void FUN_00c7f700(const void* rot, const Vec4& v);  // FUN_00c7f700
};

struct __declspec(align(16)) Mat3
{
    Vec4 c0, c1, c2;
};

struct TimeInterval
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
};

struct Motion
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void GetInertiaLocal(Mat3& m) const;
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void StepMotion(float dt, const Vec4& t);
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3 m_rotation;  // +0xf0 in body
};

struct RigidBody
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
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    Motion m_pMotionState;
    void FUN_00c9c1d0();  // FUN_00c9c1d0

    inline void StepMotion(float dt, const Vec4& t)
    {
        FUN_00c9c1d0();
        m_pMotionState.StepMotion(dt, t);
    }
};

struct MotorAction : hkpMotorAction
{
    void FUN_00d4d860(const TimeInterval& stepInfo);
};

// @f3 0x009da470 (community match, verified in this file)
struct Matrix496;
struct __declspec(align(16)) Vector496 {
    float x,y,z,w;
    void FUN_00477880(const void*,const void*);
    void FUN_008d2a80(const Matrix496*,const Vector496&);
    void hkVector4_setRotatedDir(const void*,const Vector496&);
    __forceinline float Dot(const Vector496& a) const {return x*a.x+y*a.y+z*a.z;}
    __forceinline void Scale(float scale,const Vector496& a) {x=scale*a.x;y=scale*a.y;z=scale*a.z;w=scale*a.w;}
};
struct __declspec(align(16)) Matrix496 {Vector496 first,second,third;};
struct Rotation496 {float components[12];};
struct Motion496 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Inertia(void*);
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void Step(float,const Vector496&);
    unsigned int unk04,unk08,unk0c;Rotation496 rotation;
};
struct Body496 {
    unsigned int unk0,unk4,unk8,unkc,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    unsigned int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    unsigned int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    unsigned int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    unsigned int unkc0,unkc4,unkc8,unkcc;
    Motion496 motion;
    void FUN_0090b500();
    __forceinline void Step(float time,const Vector496& value) {FUN_0090b500();motion.Step(time,value);}
};
struct Layout496 {
    unsigned int unk0,unk4,unk8,unkc,unk10,unk14;
    Body496* body;unsigned int unk1c;Vector496 axis;float rate,gain;bool enabled;
};
void MotorAction::FUN_00d4d860(const TimeInterval& interval) {
    Layout496* action=reinterpret_cast<Layout496*>(this);
    if(!action->enabled) return;
    Body496* body=action->body;
    Vector496 current;
    current.FUN_00477880(&body->motion.rotation,reinterpret_cast<char*>(body)+0x1b0);
    float rate=current.Dot(action->axis);
    float delta=action->rate-rate;
    Vector496 angular;
    angular.Scale(delta*action->gain,action->axis);
    Matrix496 inertia;
    body->motion.Inertia(&inertia);
    angular.FUN_008d2a80(&inertia,angular);
    angular.hkVector4_setRotatedDir(&body->motion.rotation,angular);
    body->Step(interval.m_fTimeStep,angular);
}

