// NiObjectNET: an NiObject with a name, time controllers and extra data.
// Names: FNV360_PDB (NiObjectNET, 0822 retail). Vtable: NiObject's 35 slots, checked against F3_EXE's NiObjectNET
// vtable 0x00e207cc (35 slots).
#ifndef FNV_NIOBJECTNET_H
#define FNV_NIOBJECTNET_H
#include "f3_common.h"
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
class NiExtraData;
class NiTimeController;
#pragma pack(push, 4)
class NiObjectNET : public NiObject
{
  public:
    enum CopyType
    {
        COPY_NONE = 0,
        COPY_EXACT = 1,
        COPY_UNIQUE = 2
    };

    virtual ~NiObjectNET();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    virtual void PostLinkObject(NiStream& kStream);

    void SetName(const NiFixedString& kName);
    NiTimeController* GetController(const NiRTTI* pkRTTI) const;
    void PrependController(NiTimeController* pkControl);
    void SetControllers(NiTimeController* pkControl);
    void RemoveController(NiTimeController* pkControl);
    void RemoveAllControllers();
    NiExtraData* GetExtraData(const NiFixedString& kKey) const;
    bool AddExtraData(const NiFixedString& kKey, NiExtraData* pkExtra);
    bool AddExtraData(NiExtraData* pkExtra);
    bool InsertExtraData(NiExtraData* pkExtra);
    bool RemoveExtraData(const NiFixedString& kKey);
    bool RemoveExtraDataAt(unsigned short usExtraDataIndex);
    void RemoveAllExtraData();
    void DeleteExtraData(unsigned short usExtraDataIndex);
    bool SetExtraDataSize(unsigned short usSize);
    void CopyMembers(NiObjectNET* pkDest, NiCloningProcess& kCloning);

    NiFixedString m_kName;                        // +0x8
    NiPointer<NiTimeController> m_spControllers;  // +0xC
    NiExtraData** m_ppkExtra;                     // +0x10
    unsigned short m_usExtraDataSize;             // +0x14
    unsigned short m_usMaxSize;                   // +0x16

    static const NiRTTI ms_RTTI;
    static CopyType ms_eCopyType;
    static char ms_cAppendCharacter;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiObjectNET) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_kName) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_spControllers) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_ppkExtra) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_usExtraDataSize) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_usMaxSize) == 0x16);
#endif
