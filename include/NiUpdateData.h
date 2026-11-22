// NiUpdateData: the arguments of a scene graph update pass.
// Names: FNV360_PDB (NiUpdateData).
#ifndef FNV_NIUPDATEDATA_H
#define FNV_NIUPDATEDATA_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiUpdateData
{
  public:
    float fTime;                  // +0x0
    bool bUpdateControllers;      // +0x4
    bool bParallelUpdate;         // +0x5
    bool bFoundParticles;         // +0x6
    bool bFoundMorphController;   // +0x7
    bool bSceneGraphChange;       // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 0xC);
#endif
