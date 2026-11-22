// fallout_shared/bgsidlecollection_types_BGSIdleCollection.h: declares BGSIdleCollection
#ifndef F3_BGSIDLECOLLECTION_H
#define F3_BGSIDLECOLLECTION_H
#include "layout_support.h"
#include "BaseFormComponent.h"
class TESIdleForm;
#pragma pack(push, 4)
// Layout and member names: FNV360_PDB (BGSIdleCollection, 16 bytes, base BaseFormComponent). Vtable: F3_EXE RTTI
// .?AVBGSIdleCollection@@, 4 slots at 0x00dbb62c, the BaseFormComponent slots overridden.
class BGSIdleCollection : public BaseFormComponent
{
  public:
    unsigned char cIdleFlags;     // +0x4
    unsigned char cIdleCount;     // +0x5
    TESIdleForm** pIdleArray;     // +0x8, cIdleCount entries
    float fTimerCheckForIdle;     // +0xC
    ~BGSIdleCollection();
    // BaseFormComponent overrides
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSIdleCollection) == 0x10);
FNV_STATIC_ASSERT(offsetof(BGSIdleCollection, pIdleArray) == 0x8);
#endif
