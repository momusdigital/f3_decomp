// NiCloningProcess: the state of one NiObject::Clone call: the originals already cloned and their clones.
// Names: FNV360_PDB (NiCloningProcess, 0822 retail).
#ifndef FNV_NICLONINGPROCESS_H
#define FNV_NICLONINGPROCESS_H
#include "layout_support.h"
#include "NiObjectNET.h"
#pragma pack(push, 4)
class NiCloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pkCloneMap;  // +0x0
    NiTPointerMap<NiObject*, bool>* m_pkProcessMap;     // +0x4
    NiObjectNET::CopyType m_eCopyType;                  // +0x8
    char m_cAppendChar;                                 // +0xC
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiCloningProcess) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiCloningProcess, m_eCopyType) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiCloningProcess, m_cAppendChar) == 0xC);
#endif
