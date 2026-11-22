// src/f3staging/f3blk_00500000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0050d090 (community match, verified in this file)
namespace f3m_0050d090 {
struct String50d090 {int unk00;int unk04;int unk08;void FUN_004019c0(const char*,unsigned int);};
struct Owner50d090 {
 int unk00;int unk04;int unk08;String50d090 unk0C;String50d090 unk18;String50d090 unk24;String50d090 unk30;String50d090 unk3C;String50d090 unk48;
 void FUN_0050d090(unsigned int,const char*);
};
// pdb: BGSTextureSet::SetTextureFilename | BGSTextureSet.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiType, aFilename
void Owner50d090::FUN_0050d090(unsigned int selector,const char* text) {
 switch(selector) {
 case 0:unk0C.FUN_004019c0(text,0);break;
 case 1:unk18.FUN_004019c0(text,0);break;
 case 2:unk30.FUN_004019c0(text,0);break;
 case 3:unk3C.FUN_004019c0(text,0);break;
 case 4:unk48.FUN_004019c0(text,0);break;
 case 5:unk24.FUN_004019c0(text,0);break;
 }
}
}   // namespace f3m_0050d090
