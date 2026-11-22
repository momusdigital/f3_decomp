// NiRTTI: Gamebryo's run-time type record; every NiObject class has one (ms_RTTI) naming it and its base.
// Names: FNV360_PDB (NiRTTI).
#ifndef FNV_NIRTTI_H
#define FNV_NIRTTI_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiRTTI
{
  public:
    NiRTTI(const char* pcName, const NiRTTI* pkBaseRTTI);
    const char* GetName() const
    {
        return m_pcName;
    }
    const NiRTTI* GetBaseRTTI() const
    {
        return m_pkBaseRTTI;
    }

    const char* m_pcName;        // +0x0
    const NiRTTI* m_pkBaseRTTI;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiRTTI) == 0x8);
#endif
