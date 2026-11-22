// NiBound: a bounding sphere.
// Names: FNV360_PDB (NiBound; m_fRadius shares its storage with m_iRadiusAsInt).
#ifndef FNV_NIBOUND_H
#define FNV_NIBOUND_H
#include "layout_support.h"
#include "NiPoint3.h"
#pragma pack(push, 4)
class NiBound
{
  public:
    NiPoint3 m_kCenter;  // +0x0
    union
    {
        float m_fRadius;      // +0xC
        int m_iRadiusAsInt;  // +0xC
    };

    static float ms_fFuzzFactor;
    static float ms_fTolerance;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBound) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiBound, m_fRadius) == 0xC);
#endif
