// TESFullName: the component that holds a form's display name.
// Names: FNV360_PDB (TESFullName). Vtable: 4 slots, the BaseFormComponent ones, as F3_EXE's TESFullName vtable.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H
#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> cFullName;  // +0x4

    // BaseFormComponent
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent* apCopyFC);
    virtual bool CompareComponent(BaseFormComponent* apCompareFC);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, cFullName) == 0x4);
#endif
