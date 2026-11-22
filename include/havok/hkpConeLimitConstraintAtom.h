// include/havok/hkpConeLimitConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPCONELIMITCONSTRAINTATOM_H
#define FNV_HAVOK_HKPCONELIMITCONSTRAINTATOM_H
#include "f3_common.h"
#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpConeLimitConstraintAtom : public hkpConstraintAtom
{
  public:
    enum MeasurementMode
    {
        ZERO_WHEN_VECTORS_ALIGNED = 0,
        ZERO_WHEN_VECTORS_PERPENDICULAR = 1
    };
    hkUint8 m_isEnabled;               // +0x2 src: FNV360_PDB +0x2 (old: m_bLimitEnabled)
    hkUint8 m_twistAxisInA;            // +0x3 src: FNV360_PDB +0x3 (old: m_ucMemOffsetToAngleOffset)
    hkUint8 m_refAxisInB;              // +0x4 src: FNV360_PDB +0x4 (old: m_ucMemOffsetToOldAngleOffset)
    hkUint8 m_angleMeasurementMode;    // +0x5 (MeasurementMode) src: FNV360_PDB +0x5 (old: m_ucMemOffsetToFirstConstrainedDof)
    hkUint8 m_memOffsetToAngleOffset;  // +0x6 src: FNV360_PDB +0x6 (old: m_ucAngleMeasurementMode)
    char pad7[0x1];
    hkReal m_fMinAngle;                // +0x8
    hkReal m_fMaxAngle;                // +0xC
    hkReal m_fAngularLimitsTauFactor;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConeLimitConstraintAtom[(sizeof(hkpConeLimitConstraintAtom) == 0x14) ? 1 : -1];
#endif
