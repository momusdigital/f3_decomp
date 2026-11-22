#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00453bd0 (community match, verified in this file)
namespace f3m_00453bd0 {
struct Owner1285;
struct Temp1285{int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38,unk3C,unk40,unk44,unk48,unk4C,unk50,unk54,unk58,unk5C,unk60,unk64,unk68,unk6C,unk70,unk74,unk78,unk7C,unk80,unk84,unk88,unk8C,unk90,unk94; Temp1285();~Temp1285();void FUN_0044ed20(Owner1285*);void FUN_0044ec20();};
struct Member1285{void FUN_00456530();};
struct Owner1285{int unk00;unsigned char type04;unsigned char unk05,unk06,unk07;int unk08,unk0C,unk10,unk14;Member1285 member18;};
// pdb: TESForm::InitializeDataAllComponents | TESForm.obj | fnv360_0822_retail, call_gap, medium
void __fastcall FUN_00453bd0(Owner1285* owner,void* unused){switch(owner->type04){case 0x11:case 0x3a:case 0x3b:case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x42:case 0x43:case 0x49:return;case 0x39:owner->member18.FUN_00456530();return;default:{Temp1285 temporary;temporary.FUN_0044ed20(owner);temporary.FUN_0044ec20();}}}
}   // namespace f3m_00453bd0
