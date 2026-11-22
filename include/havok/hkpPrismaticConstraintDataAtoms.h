// include/havok/hkpPrismaticConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC0.
#ifndef FNV_HAVOK_HKPPRISMATICCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPPRISMATICCONSTRAINTDATAATOMS_H
#include "f3_common.h"
#include "hkBase.h"
#include "hkpAngConstraintAtom.h"
#include "hkpLinConstraintAtom.h"
#include "hkpLinFrictionConstraintAtom.h"
#include "hkpLinLimitConstraintAtom.h"
#include "hkpLinMotorConstraintAtom.h"
#include "hkpSetLocalTransformsConstraintAtom.h"
#pragma pack(push, 1)
class hkpPrismaticConstraintDataAtoms
{
  public:
    // The bytes up to the end of the last atom (Havok's hkGetByteOffsetInt(this, &m_kShaftLinearLimit + 1)).
    int getSizeOfAllAtoms() const { return (int)((const char*)(&m_kShaftLinearLimit + 1) - (const char*)this); }
    enum Axis
    {
        AXIS_SHAFT = 0,
        AXIS_PERP_TO_SHAFT = 1
    };
    hkpSetLocalTransformsConstraintAtom m_kTransforms;       // +0x0
    hkpLinMotorConstraintAtom m_pMotor;                      // +0x90
    hkpLinFrictionConstraintAtom m_fSlipAngle;               // +0xA0
    hkpAngConstraintAtom m_vAngularConstraint;               // +0xA8
    hkpLinConstraintAtom m_kPerpendicularLinearConstraintA;  // +0xAC
    hkpLinConstraintAtom m_kPerpendicularLinearConstraintB;  // +0xB0
    hkpLinLimitConstraintAtom m_kShaftLinearLimit;           // +0xB4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPrismaticConstraintDataAtoms[(sizeof(hkpPrismaticConstraintDataAtoms) == 0xC0) ? 1 : -1];
#endif
