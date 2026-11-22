#include <new>
// src/f3staging/f3iso_00931ad0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00931ad0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00931ad0 (community match, verified in this file)
namespace f3m_00931ad0 {
class hkpBroadPhaseHandleCD2D
{
  public:
    hkpBroadPhaseHandleCD2D()
    {
        m_iOwnerObjectOffset = 0;
    }
    unsigned int m_iOwnerObjectOffset;
};
class hkpTypedBroadPhaseHandleCD2D : public hkpBroadPhaseHandleCD2D
{
  public:
    hkpTypedBroadPhaseHandleCD2D(int type)
    {
        m_type = (signed char)type;
        m_uiCollisionFilterData = 0;
        m_usObjectQualityType = 0;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* owner)
    {
        int offset = (int)((char*)owner - (char*)this);
        m_iOwnerOffset = (signed char)offset;
    }
    signed char m_type;
    signed char m_iOwnerOffset;
    unsigned short m_usObjectQualityType;
    unsigned int m_uiCollisionFilterData;
};
class FUN_009afea0
{
  public:
    FUN_009afea0();
    int unk00[10];
};
class hkpCdBodyCD2D
{
  public:
    hkpCdBodyCD2D(const void* shape, const void* motionState)
    {
        m_pCollisionShape = shape;
        m_pMotionState = motionState;
        m_parent = 0;
        m_uiCollisionShapeKey = 0xffffffff;
    }
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyCD2D* m_parent;
};
class FUN_00931ad0 : public hkpCdBodyCD2D
{
  public:
    FUN_00931ad0(const void* shape, const void* motionState, int type);

    signed char m_iOwnerOffset;
    signed char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleCD2D m_kBroadPhaseHandle;
    FUN_009afea0 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};


// pdb: hkpCollidable::hkpCollidable | hkpMouseSpringAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: shape, shape, t, ms, type, type
FUN_00931ad0::FUN_00931ad0(const void* apCollisionShape, const void* motionState, int aiBroadPhaseType)
    : hkpCdBodyCD2D(apCollisionShape, motionState), m_iOwnerOffset(0), m_kBroadPhaseHandle(aiBroadPhaseType),
      m_fAllowedPenetrationDepth(-1.0f)
{
    m_kBroadPhaseHandle.SetOwnerPointer(this);
    m_uiForceCollideOntoPpu = 0;
    m_uiShapeSizeOnSpu = 0;
}

}   // namespace f3m_00931ad0
