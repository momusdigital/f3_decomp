// NiExtraData: named user data attached to an NiObjectNET.
// Names: FNV360_PDB (NiExtraData, 0822 retail). Vtable: 37 slots, checked against F3_EXE's NiExtraData vtable 0x00e23324 (37 slots).
#ifndef FNV_NIEXTRADATA_H
#define FNV_NIEXTRADATA_H
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
#pragma pack(push, 4)
class NiExtraData : public NiObject
{
  public:
    virtual ~NiExtraData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);

    virtual bool IsStreamable() const;                                                       // 35
    virtual bool IsCloneable() const;                                                        // 36

    NiFixedString m_kName;                         // +0x8

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiExtraData) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiExtraData, m_kName) == 0x8);
#endif
