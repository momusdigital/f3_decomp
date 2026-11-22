// TESChildCell: the interface of an object that lives in a cell (a reference's second base, at +0x18).
// Names: FNV360_PDB (TESChildCell). Vtable: 1 slot, F3_EXE's TESChildCell vtable 0x00dcc4ac (pure) and
// TESObjectREFR's at +0x18 (0x00dcee70).
#ifndef FNV_TESCHILDCELL_H
#define FNV_TESCHILDCELL_H
#include "layout_support.h"
class TESObjectCELL;
#pragma pack(push, 4)
class TESChildCell
{
  public:
    virtual TESObjectCELL* GetSaveParentCell() = 0;   // 0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESChildCell) == 0x4);
#endif
