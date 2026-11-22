#include <math.h>
#include <intrin.h>
// src/f3staging/f3blk_007a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007ab5e0 (community match, verified in this file)
namespace f3m_007ab5e0 {
namespace task1956 {
struct Heap {void* FUN_0086b930(unsigned int);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct Weapon; struct BoundObject;
struct Allocated {static void* operator new(unsigned int n){return DAT_01090a78.FUN_0086b930(n);} static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}};
struct FUN_007d6500:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 FUN_007d6500();
};
struct FUN_007d30f0:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 unsigned int unk07c;
 unsigned int unk080;
 unsigned int unk084;
 FUN_007d30f0();
};
struct FUN_007d1d70:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 FUN_007d1d70();
};
struct FUN_007d2670:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 FUN_007d2670();
};
struct FUN_007d9eb0:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 FUN_007d9eb0(int);
};
struct FUN_007dd5b0:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 FUN_007dd5b0(Weapon*);
};
struct FUN_007daa40:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 FUN_007daa40(int,float,int);
};
struct FUN_007d7a10:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 FUN_007d7a10(int);
};
struct FUN_007d1800:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 FUN_007d1800(int,int);
};
struct FUN_007da220:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 FUN_007da220(int,float,int,int);
};
struct FUN_007dc270:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 FUN_007dc270();
};
struct FUN_007dd790:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 FUN_007dd790(BoundObject*);
};
struct FUN_007d87e0:Allocated {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 FUN_007d87e0();
};
// pdb: CombatProcedure::CreateProcedure | CombatProcedure.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiType
void* __cdecl FUN_007ab5e0(int kind){
 switch(kind){
 case 0: return new FUN_007d6500();
 case 1: return new FUN_007d30f0();
 case 2: return new FUN_007d1d70();
 case 3: return new FUN_007d2670();
 case 4: return new FUN_007d9eb0(0);
 case 5: return new FUN_007dd5b0(0);
 case 6: return new FUN_007daa40(0,0.0f,0);
 case 7: return new FUN_007d7a10(0);
 case 8: return new FUN_007d1800(0,0);
 case 9: return new FUN_007da220(0,0.0f,0,0);
 case 10: return new FUN_007dc270();
 case 11: return new FUN_007dd790(0);
 case 12: return new FUN_007d87e0();
 default: return 0;
 }
}
}
}   // namespace f3m_007ab5e0
