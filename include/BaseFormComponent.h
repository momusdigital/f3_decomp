// BaseFormComponent: the base of every form and of each component a form is built from.
// Names: FNV360_PDB (BaseFormComponent, 0822 retail). Vtable: 4 slots, as every F3_EXE component vtable starts.
#ifndef FNV_BASEFORMCOMPONENT_H
#define FNV_BASEFORMCOMPONENT_H
#include "layout_support.h"
#pragma pack(push, 4)
class BaseFormComponent
{
  public:
    virtual void InitializeDataComponent();                           // 0
    virtual void ClearDataComponent();                                // 1
    virtual void CopyComponent(BaseFormComponent* apCopyFC);          // 2
    virtual bool CompareComponent(BaseFormComponent* apCompareFC);    // 3
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);
#endif
