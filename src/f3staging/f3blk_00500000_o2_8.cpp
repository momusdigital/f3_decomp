// src/f3staging/f3blk_00500000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0051a140 (community match, verified in this file)
extern char DAT_00dd41f8[],DAT_00dd41dc[],DAT_00dd41a4[];
namespace f3m_0051a140 {
struct Entry51a140 { void* token; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0; int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240; int unk244; int unk248; int unk24C; int unk250; int unk254; int unk258; int unk25C; int unk260; int unk264; int unk268; int unk26C; int unk270; int unk274; int unk278; int unk27C; int unk280; int unk284; int unk288; int unk28C; int unk290; int unk294; int unk298; int unk29C; int unk2A0; int unk2A4; int unk2A8; int unk2AC; int unk2B0; int unk2B4; int unk2B8; int unk2BC; int unk2C0; int unk2C4; int unk2C8; int unk2CC; int unk2D0; int unk2D4; int unk2D8; int unk2DC; int unk2E0; int unk2E4; int unk2E8; int unk2EC; int unk2F0; int unk2F4; int unk2F8; int unk2FC; int unk300; int unk304; int unk308; int unk30C; int unk310; int unk314; int unk318; int unk31C; int unk320; int unk324; int unk328; int unk32C; int unk330; int unk334; int unk338; int unk33C; int unk340; int unk344; int unk348; int unk34C; int unk350; int unk354; int unk358; int unk35C; int unk360; int unk364; int unk368; int unk36C; int unk370; int unk374; int unk378; int unk37C; int unk380; int unk384; int unk388; int unk38C; int unk390; int unk394; int unk398; int unk39C; int unk3A0; int unk3A4; int unk3A8; int unk3AC; int unk3B0; int unk3B4; int unk3B8; int unk3BC; int unk3C0; int unk3C4; int unk3C8; int unk3CC; int unk3D0; int unk3D4; int unk3D8; int unk3DC; int unk3E0; int unk3E4; int unk3E8; int unk3EC; int unk3F0; int unk3F4; int unk3F8; int unk3FC; int unk400; int unk404; int unk408; int unk40C; unsigned kind; };
struct Node51a140 { Entry51a140* item; Node51a140* next; };
struct Context51a140 { int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; void* current; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; Node51a140 head; Node51a140* Head() { return &head; } };
extern void __cdecl ScriptCompiler_ScriptError(Context51a140*,const char*);
__forceinline void Advance51a140(Node51a140*& node,Node51a140* next) { node=next; }
// pdb: ScriptCompiler::VerifyBlocks | TESScriptCompiler.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
bool __stdcall ScriptCompiler_VerifyBlocks(Context51a140* ctx) {
 bool active=false;
 for(Node51a140* node=ctx->Head();node;node=node->next) {
  Node51a140* next=node->next; if(!next && !node->item) break;
  Entry51a140* item=node->item;
  switch(item->kind) {
  case 16: if(active) { ctx->current=item->token; ScriptCompiler_ScriptError(ctx,DAT_00dd41f8); return false; } active=true; break;
  case 17: if(!active) { ctx->current=item->token; ScriptCompiler_ScriptError(ctx,DAT_00dd41dc); return false; } active=false; break;
  case 18:case 19:case 20:case 29:case 31: break;
  default: if(!active) { ctx->current=item->token; ScriptCompiler_ScriptError(ctx,DAT_00dd41a4); return false; } break;
  }

 }
 return true;
}
}   // namespace f3m_0051a140
