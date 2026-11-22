// src/f3staging/f3blk_00500000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0050f9d0 (community match, verified in this file)
extern char DAT_00dd2274[];
namespace f3m_0050f9d0 {
__declspec(thread) bool DAT_0117c250=false;
extern void __cdecl FUN_006195d0(const char*,...);
struct Ref50F9 { void** table; bool IsActor(){ return ((bool(__thiscall*)(Ref50F9*))table[64])(this); } int State(){ return ((int(__thiscall*)(Ref50F9*))table[133])(this); } };
// pdb: Script::GetSittingConditionFunction | TESConditionFunctions.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
bool __cdecl Script_GetSittingConditionFunction(Ref50F9* reference,void* second,void* third,double* result) {
 *result=0.0;
 if(reference && reference->IsActor()) {
  switch(reference->State()) {
  case 5: *result+=1.0;
  case 4: *result+=1.0;
  case 3:
  case 2: *result+=1.0;
  case 1: *result+=1.0;
  }
 }
 if(DAT_0117c250) FUN_006195d0(DAT_00dd2274,*result);
 return true;
}
}   // namespace f3m_0050f9d0
