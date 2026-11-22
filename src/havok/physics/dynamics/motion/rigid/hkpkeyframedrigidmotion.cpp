#include "f3_common.h"
// src/havok/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpKeyframedRigidMotion.h"

// @fnv 0x00d1dec0
// pdb: hkpKeyframedRigidMotion::setInertiaInvLocal | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: inertiaInv
void __stdcall FUN_00d1dec0(int)
{}

// @fnv 0x00d1ded0
// pdb: hkpKeyframedRigidMotion::applyLinearImpulse | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: imp
void __stdcall FUN_00d1ded0(int)
{}

// @fnv 0x00d1dee0
// pdb: hkpKeyframedRigidMotion::applyAngularImpulse | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: imp
void __stdcall FUN_00d1dee0(int)
{}

// @fnv 0x00d1def0
void __stdcall FUN_00d1def0(int)
{}

// @fnv 0x00d1df00
void __stdcall FUN_00d1df00(int)
{}

// @fnv 0x00d1df10
// pdb: hkpKeyframedRigidMotion::applyPointImpulse | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: imp, p
void __stdcall FUN_00d1df10(int, int)
{}

// @fnv 0x00d1df20
// pdb: hkDisplayCapsule::getWireframeGeometry | hkDisplayCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void __stdcall FUN_00d1df20(int)
{}

// @fnv 0x00d1df30
// pdb: hkpKeyframedRigidMotion::applyForce | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: deltaTime, force
void __stdcall FUN_00d1df30(int, int)
{}

// @fnv 0x00d1df40
// pdb: hkpMultiThreadedSimulation::assertThereIsNoCollisionInformationForEntities | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_open), high
void __stdcall hkpMultiThreadedSimulation_assertThereIsNoCollisionInformationForEntities(int a, int b, int c)
{}

// @fnv 0x00d1df50
// pdb: hkpKeyframedRigidMotion::applyTorque | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: deltaTime, torque
void __stdcall FUN_00d1df50(int, int)
{}

// @fnv 0x00d1df60
// pdb: hkpKeyframedRigidMotion::setStepPosition | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: position, timestep
void __stdcall FUN_00d1df60(int, int)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D1DF
{
    __m128 m_vComponents;

    hkVector4D1DF()
    {}
    hkVector4D1DF(const hkVector4D1DF& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4D1DF& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

namespace fnv_00d1e090 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
}

}  // namespace fnv_00d1e090
