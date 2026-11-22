// TESScriptableForm: the component that attaches a script to a form.
// Names: FNV360_PDB (TESScriptableForm). Vtable: 4 slots, the BaseFormComponent ones, as F3_EXE's.
#ifndef FNV_TESSCRIPTABLEFORM_H
#define FNV_TESSCRIPTABLEFORM_H
#include "f3_common.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* pFormScript;     // +0x4
    bool bIsInitialized;     // +0x8

    // BaseFormComponent
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent* apCopyFC);
    virtual bool CompareComponent(BaseFormComponent* apCompareFC);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESScriptableForm) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, pFormScript) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, bIsInitialized) == 0x8);
#endif
