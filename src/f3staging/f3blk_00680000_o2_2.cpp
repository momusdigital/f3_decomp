// src/f3staging/f3blk_00680000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006891d0 (community match, verified in this file)
namespace f3m_006891d0 {
// pdb: SurgeryMenu::GetIndexFromActorValue | SurgeryMenu.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aeLimb
int __stdcall FUN_006891d0(int type) {
 switch(type) {
 case 26: return 0;
 case 27: return 1;
 case 29: return 2;
 case 28: return 3;
 case 30: return 4;
 case 25: return 5;
 case -1: return 6;
 default: return 0;
 }
}
}   // namespace f3m_006891d0

// @f3 0x00684fb0 (community match, verified in this file)
namespace f3m_00684fb0 {
struct FUN_0059acd0 {
    int unk00;
    int unk04;
    FUN_0059acd0();
    ~FUN_0059acd0();
};
class QSlotTable684 {
  public:
    int unk00;
    FUN_0059acd0 entries[6];
    int ids[6];
    QSlotTable684();
};
// pdb: StatsMenu::BodyPartController::BodyPartController | StatsMenu.obj | fnv360_0822_debug, call_seq, medium
QSlotTable684::QSlotTable684()
{
    unk00 = 0;
    for (int i = 0; i < 6; i++)
        ids[i] = -1;
}
}   // namespace f3m_00684fb0
