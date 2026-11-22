// src/f3staging/f3blk_00560000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00565d50 (community match, verified in this file)
extern unsigned DAT_00f5d200,DAT_00f5d20c,DAT_00f5d218,DAT_00f5d224,DAT_00f5d230;
namespace f3m_00565d50 {
struct TypedRecord {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0C;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1C;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2C;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3C;
 unsigned unk40;
 unsigned type;unsigned FUN_00565d50();};
// pdb: TESTopicInfo::GetDifficulty | TESTopicInfo.obj | fnv360_0721_retail, objrun, low, conflict (skyrim: BGSCameraPath::GetIndexForChild)
unsigned TypedRecord::FUN_00565d50() {switch(type){case 1:return DAT_00f5d200;case 2:return DAT_00f5d20c;case 3:return DAT_00f5d218;case 4:return DAT_00f5d224;case 5:return DAT_00f5d230;default:return -1;}}
}   // namespace f3m_00565d50
