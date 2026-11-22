#include <string.h>
#include <intrin.h>
// src/f3staging/f3blk_006c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d1c50 (community match, verified in this file)
namespace f3m_006d1c50 {
namespace task1849 {
struct Buffer;
struct World {void FUN_00436420(Buffer*);};extern World* DAT_0107a0d8;
struct Manager {void FUN_0078da50(Buffer*);void FUN_0078c030(Buffer*);};extern Manager DAT_0107c0a0;
struct Spaces {void FUN_007a7a50(Buffer*);};extern Spaces* DAT_0108c988;
struct Sky {void FUN_0057aeb0(Buffer*);};Sky* __cdecl Sky_GetInstance();
void __cdecl FUN_006d13c0(Buffer*);void __cdecl FUN_006d1a30(Buffer*);void __cdecl FUN_0061a210(Buffer*);
void __cdecl BGSSaveLoadGlobalData_SaveEffects(Buffer*);void __cdecl FUN_0048c4b0(Buffer*);void __cdecl FUN_005a1d10(Buffer*);
void __cdecl FalloutRadio_SaveGame(Buffer*);void __cdecl FUN_006bd7b0(Buffer*);void __cdecl FUN_006cd570(const char*,...);
// pdb: BGSSaveLoadGlobalData::SaveGlobalData | BGSSaveLoadGlobalData.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiGlobalDataType, apSaveGameBuffer
bool __cdecl FUN_006d1c50(unsigned type,Buffer* buffer){
switch(type){
case 1:FUN_006d13c0(buffer);return true;
case 2:DAT_0107a0d8->FUN_00436420(buffer);return true;
case 3:FUN_006d1a30(buffer);return true;
case 4:DAT_0107c0a0.FUN_0078da50(buffer);return true;
case 5:DAT_0108c988->FUN_007a7a50(buffer);return true;
case 6:FUN_0061a210(buffer);return true;
case 7:BGSSaveLoadGlobalData_SaveEffects(buffer);return true;
case 0:FUN_0048c4b0(buffer);return true;
case 8:Sky_GetInstance()->FUN_0057aeb0(buffer);return true;
case 9:FUN_005a1d10(buffer);return true;
case 10:FalloutRadio_SaveGame(buffer);return true;
case 11:FUN_006bd7b0(buffer);return true;
case 1000:DAT_0107c0a0.FUN_0078c030(buffer);return true;
default:FUN_006cd570("SAVELOAD: Unknown global data type %i in SaveGlobalData()",type);return false;
}}
}
}   // namespace f3m_006d1c50
