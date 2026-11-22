#include <stdio.h>
#include <windows.h>
// src/f3staging/f3blk_00740000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0074bd90 (community match, verified in this file)
extern int* DAT_00f6ee80[];
namespace f3m_0074bd90 {
namespace task1801 {
struct Count { unsigned FUN_004a0890(); };
struct Proc { int unk00,unk04,unk08,unk0c,unk10,unk14; int type; int unk1c,unk20; unsigned char flags; int unk28; void* item; Count* count;
float FUN_005a6440(int,int); unsigned TESPackage_GetLocationRadius(int); float FUN_005a6550(int,int);
bool IsFlag4Clear(){return ((flags>>2)&1)==0;}
};
struct Actor {
virtual void v000();
virtual void v004();
virtual void v008();
virtual void v00c();
virtual void v010();
virtual void v014();
virtual void v018();
virtual void v01c();
virtual void v020();
virtual void v024();
virtual void v028();
virtual void v02c();
virtual void v030();
virtual void v034();
virtual void v038();
virtual void v03c();
virtual void v040();
virtual void v044();
virtual void v048();
virtual void v04c();
virtual void v050();
virtual void v054();
virtual void v058();
virtual void v05c();
virtual void v060();
virtual void v064();
virtual void v068();
virtual void v06c();
virtual void v070();
virtual void v074();
virtual void v078();
virtual void v07c();
virtual void v080();
virtual void v084();
virtual void v088();
virtual void v08c();
virtual void v090();
virtual void v094();
virtual void v098();
virtual void v09c();
virtual void v0a0();
virtual void v0a4();
virtual void v0a8();
virtual void v0ac();
virtual void v0b0();
virtual void v0b4();
virtual void v0b8();
virtual void v0bc();
virtual void v0c0();
virtual void v0c4();
virtual void v0c8();
virtual void v0cc();
virtual void v0d0();
virtual void v0d4();
virtual void v0d8();
virtual void v0dc();
virtual void v0e0();
virtual void v0e4();
virtual void v0e8();
virtual void v0ec();
virtual void v0f0();
virtual void v0f4();
virtual void v0f8();
virtual void v0fc();
virtual void v100();
virtual void v104();
virtual void v108();
virtual void v10c();
virtual void v110();
virtual void v114();
virtual void v118();
virtual void v11c();
virtual void v120();
virtual void v124();
virtual void v128();
virtual void v12c();
virtual void v130();
virtual void v134();
virtual void v138();
virtual void v13c();
virtual void v140();
virtual void v144();
virtual void v148();
virtual void v14c();
virtual void v150();
virtual void v154();
virtual void v158();
virtual void v15c();
virtual void v160();
virtual void v164();
virtual void v168();
virtual void v16c();
virtual void v170();
virtual void v174();
virtual void v178();
virtual void v17c();
virtual void v180();
virtual void v184();
virtual void v188();
virtual void v18c();
virtual void v190();
virtual void v194();
virtual void v198();
virtual void v19c();
virtual void v1a0();
virtual void v1a4();
virtual void v1a8();
virtual void v1ac();
virtual void v1b0();
virtual void v1b4();
virtual void v1b8();
virtual void v1bc();
virtual void v1c0();
virtual void v1c4();
virtual void v1c8();
virtual void v1cc();
virtual void v1d0();
virtual void v1d4();
virtual void v1d8();
virtual void v1dc();
virtual void v1e0();
virtual void v1e4();
virtual void v1e8();
virtual void v1ec();
virtual void v1f0();
virtual void v1f4();
virtual void v1f8();
virtual void v1fc();
virtual void v200();
virtual void v204();
virtual void v208();
virtual void v20c();
virtual void v210();
virtual void v214();
virtual void v218();
virtual void v21c();
virtual void v220();
virtual void v224();
virtual Proc* GetProc();
virtual void v22c();
virtual void v230();
virtual void v234();
virtual void v238();
virtual void v23c();
virtual void v240();
virtual void v244();
virtual void v248();
virtual void v24c();
virtual void v250();
virtual void v254();
virtual void v258();
virtual void v25c();
virtual void v260();
virtual void v264();
virtual void v268();
virtual void v26c();
virtual void v270();
virtual void v274();
virtual void v278();
virtual int GetIndex();
float FUN_0074bd90(int);
};
// pdb: LowProcess::GetCurrentDestinationRadius | LowProcess.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apActor
float Actor::FUN_0074bd90(int arg) {
 float result=128.0f;
 if(!GetProc()) return result;
 switch(DAT_00f6ee80[GetProc()->type][GetIndex()]) {
 case 0: case 50:
 if(GetProc()->item) result=GetProc()->FUN_005a6440(arg,0); break;
 case 47: {
 Count* count=GetProc()->count;
 float unused=(GetProc()->IsFlag4Clear() && GetProc()->item) ? (float)GetProc()->TESPackage_GetLocationRadius(arg) : (count ? (float)count->FUN_004a0890() : 30.0f); break;
 }
 case 1:case 2:case 3:case 8:case 14:case 15:
 if(GetProc()->count) result=GetProc()->FUN_005a6550(arg,0);break;
 case 6:case 7:case 13:case 30:
 if(GetProc()->count) result=GetProc()->FUN_005a6550(arg,0);break;
 }
 return result;
}
}
}   // namespace f3m_0074bd90

// @f3 0x00750eb0 (community match, verified in this file)
namespace f3m_00750eb0 {

namespace task1891 {
struct Actor; struct LowProcess; struct TESPackage; struct Date;
struct NiPoint3 {float x,y,z;};
struct Cell {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20; unsigned char flags; bool IsCellInterior(){return (flags&1)!=0;}};
struct Heap {void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct Date {static void operator delete(void*p){DAT_01090a78.FUN_0086ba60(p);}};
struct List {Date* item;List* next;bool FUN_00645c20();void FUN_00421610(Date*const&);bool IsEmpty(){return FUN_00645c20();} Date* GetItem(){return item;}void Remove(Date*const&p){FUN_00421610(p);}};
struct PackageTargetRecord {int FUN_005ad6b0();unsigned FUN_004a0890();int GetTargetKind(){return FUN_005ad6b0();}unsigned GetSize(){return FUN_004a0890();}};
struct LocationDescriptor {int FUN_005acce0();int GetLocType(){return FUN_005acce0();}};
struct HighProcess {
virtual void unknown_000();
virtual void unknown_004();
virtual void unknown_008();
virtual void unknown_00c();
virtual void unknown_010();
virtual void unknown_014();
virtual void unknown_018();
virtual void unknown_01c();
virtual void unknown_020();
virtual void unknown_024();
virtual void Update();
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
unsigned int unk24;
int level; int GetProcessLevel(){return level;} };
struct Value {union {int i;float f;};};
struct Setting {Value* FUN_004241e0();Value* FUN_00401eb0();Value* Int(){return FUN_004241e0();}Value* Float(){return FUN_00401eb0();}};
extern Setting DAT_00f5e838,DAT_00f5e868,DAT_00f5e85c;
struct Calendar {float FUN_006e2a90();unsigned char FUN_006e2a60();float GetGameTime(){return FUN_006e2a90();}unsigned char GetGameHour(){return FUN_006e2a60();}};
extern Calendar DAT_01079f68;
extern Actor* DAT_0107a104;
extern void* DAT_01071664;
extern int* DAT_00f6ee80[];
extern const char* DAT_00f66798[];
extern float DAT_00e12730;
Actor* FUN_006193c0();void FUN_006195d0(const char*);
bool FUN_0074b090(Actor*,long);bool FUN_0074b130(Actor*,long);
struct DataHandler {void TESDataHandler_EnumReferencesCloseToPoint(Cell*,const NiPoint3&,float,const NiPoint3&,float,bool(*)(Actor*,long),long);};extern DataHandler* DAT_0106cdcc;
struct Actor {
virtual void unknown_000();
virtual void unknown_004();
virtual void unknown_008();
virtual void unknown_00c();
virtual void unknown_010();
virtual void unknown_014();
virtual void unknown_018();
virtual void unknown_01c();
virtual void unknown_020();
virtual void unknown_024();
virtual void unknown_028();
virtual void unknown_02c();
virtual void unknown_030();
virtual void unknown_034();
virtual void unknown_038();
virtual void unknown_03c();
virtual void unknown_040();
virtual void unknown_044();
virtual void unknown_048();
virtual void unknown_04c();
virtual void unknown_050();
virtual void unknown_054();
virtual void unknown_058();
virtual void unknown_05c();
virtual void unknown_060();
virtual void unknown_064();
virtual void unknown_068();
virtual void unknown_06c();
virtual void unknown_070();
virtual void unknown_074();
virtual void unknown_078();
virtual void unknown_07c();
virtual void unknown_080();
virtual void unknown_084();
virtual void unknown_088();
virtual void unknown_08c();
virtual void unknown_090();
virtual void unknown_094();
virtual void unknown_098();
virtual void unknown_09c();
virtual void unknown_0a0();
virtual void unknown_0a4();
virtual void unknown_0a8();
virtual void unknown_0ac();
virtual void unknown_0b0();
virtual void unknown_0b4();
virtual void unknown_0b8();
virtual void unknown_0bc();
virtual void unknown_0c0();
virtual void unknown_0c4();
virtual void unknown_0c8();
virtual void unknown_0cc();
virtual void unknown_0d0();
virtual void unknown_0d4();
virtual void unknown_0d8();
virtual void unknown_0dc();
virtual void unknown_0e0();
virtual void unknown_0e4();
virtual void unknown_0e8();
virtual void unknown_0ec();
virtual void unknown_0f0();
virtual void unknown_0f4();
virtual void unknown_0f8();
virtual void unknown_0fc();
virtual bool IsActor();
virtual void unknown_104();
virtual void unknown_108();
virtual void unknown_10c();
virtual void unknown_110();
virtual void unknown_114();
virtual void unknown_118();
virtual void unknown_11c();
virtual void unknown_120();
virtual void unknown_124();
virtual void unknown_128();
virtual void unknown_12c();
virtual void unknown_130();
virtual void unknown_134();
virtual void unknown_138();
virtual void unknown_13c();
virtual void unknown_140();
virtual void unknown_144();
virtual void unknown_148();
virtual void unknown_14c();
virtual void unknown_150();
virtual void unknown_154();
virtual void unknown_158();
virtual void unknown_15c();
virtual void unknown_160();
virtual void unknown_164();
virtual void unknown_168();
virtual NiPoint3 vfn_16c();
virtual void unknown_170();
virtual void unknown_174();
virtual void unknown_178();
virtual void unknown_17c();
virtual void unknown_180();
virtual void unknown_184();
virtual void unknown_188();
virtual void unknown_18c();
virtual void unknown_190();
virtual void unknown_194();
virtual void unknown_198();
virtual void unknown_19c();
virtual void unknown_1a0();
virtual void unknown_1a4();
virtual void unknown_1a8();
virtual void unknown_1ac();
virtual void unknown_1b0();
virtual void unknown_1b4();
virtual void unknown_1b8();
virtual void unknown_1bc();
virtual void unknown_1c0();
virtual void unknown_1c4();
virtual void unknown_1c8();
virtual void unknown_1cc();
virtual void unknown_1d0();
virtual void unknown_1d4();
virtual void unknown_1d8();
virtual void unknown_1dc();
virtual void unknown_1e0();
virtual void unknown_1e4();
virtual void unknown_1e8();
virtual void unknown_1ec();
virtual void unknown_1f0();
virtual NiPoint3* GetPos();
virtual void unknown_1f8();
virtual void unknown_1fc();
virtual void unknown_200();
virtual void unknown_204();
virtual void unknown_208();
virtual void unknown_20c();
virtual void unknown_210();
virtual void unknown_214();
virtual void unknown_218();
virtual void unknown_21c();
virtual void unknown_220();
virtual void unknown_224();
virtual void unknown_228();
virtual void unknown_22c();
virtual void unknown_230();
virtual void unknown_234();
virtual void unknown_238();
virtual void unknown_23c();
virtual void unknown_240();
virtual void unknown_244();
virtual void unknown_248();
virtual void unknown_24c();
virtual void unknown_250();
virtual void unknown_254();
virtual void unknown_258();
virtual void unknown_25c();
virtual void unknown_260();
virtual void unknown_264();
virtual void unknown_268();
virtual void unknown_26c();
virtual void unknown_270();
virtual bool vfn_274(bool);
virtual void unknown_278();
virtual void unknown_27c();
virtual void unknown_280();
virtual void unknown_284();
virtual void unknown_288();
virtual void vfn_28c(TESPackage*,unsigned char);
virtual void unknown_290();
virtual void unknown_294();
virtual void unknown_298();
virtual void unknown_29c();
virtual void unknown_2a0();
virtual void unknown_2a4();
virtual void unknown_2a8();
virtual void unknown_2ac();
virtual void unknown_2b0();
virtual void unknown_2b4();
virtual void unknown_2b8();
virtual void unknown_2bc();
virtual void unknown_2c0();
virtual void vfn_2c4(float);
virtual void unknown_2c8();
virtual void unknown_2cc();
virtual void unknown_2d0();
virtual void unknown_2d4();
virtual void unknown_2d8();
virtual void unknown_2dc();
virtual void unknown_2e0();
virtual void unknown_2e4();
virtual void unknown_2e8();
virtual void unknown_2ec();
virtual void unknown_2f0();
virtual void unknown_2f4();
virtual void unknown_2f8();
virtual void unknown_2fc();
virtual void unknown_300();
virtual void unknown_304();
virtual void unknown_308();
virtual void unknown_30c();
virtual void unknown_310();
virtual void unknown_314();
virtual void unknown_318();
virtual void unknown_31c();
virtual void unknown_320();
virtual void unknown_324();
virtual void unknown_328();
virtual void unknown_32c();
virtual void unknown_330();
virtual void unknown_334();
virtual void unknown_338();
virtual void unknown_33c();
virtual void unknown_340();
virtual void unknown_344();
virtual void unknown_348();
virtual void unknown_34c();
virtual void unknown_350();
virtual void unknown_354();
virtual void unknown_358();
virtual void unknown_35c();
virtual void unknown_360();
virtual void unknown_364();
virtual void unknown_368();
virtual void unknown_36c();
virtual void unknown_370();
virtual void unknown_374();
virtual void unknown_378();
virtual void unknown_37c();
virtual void unknown_380();
virtual void unknown_384();
virtual void unknown_388();
virtual void unknown_38c();
virtual void unknown_390();
virtual void unknown_394();
virtual void unknown_398();
virtual void unknown_39c();
virtual void unknown_3a0();
virtual void unknown_3a4();
virtual void unknown_3a8();
virtual void unknown_3ac();
virtual void unknown_3b0();
virtual void unknown_3b4();
virtual void unknown_3b8();
virtual void unknown_3bc();
virtual void unknown_3c0();
virtual void unknown_3c4();
virtual void unknown_3c8();
virtual void unknown_3cc();
virtual void unknown_3d0();
virtual void unknown_3d4();
virtual void unknown_3d8();
virtual void unknown_3dc();
virtual void unknown_3e0();
virtual void unknown_3e4();
virtual void unknown_3e8();
virtual void unknown_3ec();
virtual void unknown_3f0();
virtual void unknown_3f4();
virtual void unknown_3f8();
virtual void unknown_3fc();
virtual void unknown_400();
virtual void unknown_404();
virtual void unknown_408();
virtual void unknown_40c();
virtual void unknown_410();
virtual void unknown_414();
virtual void unknown_418();
virtual void unknown_41c();
virtual void unknown_420();
virtual void unknown_424();
virtual void vfn_434(bool);
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
void* base;
NiPoint3 rotation;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
Cell* cell;
unsigned int unk40;
unsigned int unk44;
unsigned int unk48;
unsigned int unk4c;
unsigned int unk50;
unsigned int unk54;
unsigned int unk58;
unsigned int unk5c;
HighProcess* process;
Cell* GetParentCell(){return cell;} void* GetObjectReference(){return base;}HighProcess* GetProcess(){return process;}void* GetExtraData(){return &unk40;}bool IsDeleted(){return (unk08>>5)&1;}
void FUN_007001e0();bool FUN_006f8d60();bool FUN_006f8d70();bool Actor_SetPathfindingGoal(const NiPoint3&,Cell*,void*,float,int);void Actor_EndInterruptPackage(bool);bool FUN_0076c8e0();bool FUN_00772c00(Actor*);int FUN_00780df0();float FUN_004edbf0(Actor*,bool,bool);int FUN_007650b0();bool FUN_006f8d90();const char* FUN_004e9a10();
void RefreshCurrentPackage(){FUN_007001e0();}bool IsActorEssential(){return FUN_006f8d60();}bool FUN_008b3bb0(){return FUN_006f8d70();}bool IsAtPosition(const NiPoint3&p,Cell*c,void*w,float f,int i){return Actor_SetPathfindingGoal(p,c,w,f,i);}void SetSpeakingState(bool b){Actor_EndInterruptPackage(b);}bool IsSleepingOrResting(){return FUN_0076c8e0();}bool IsActorInCombatWithPlayer(Actor*a){return FUN_00772c00(a);}int GetCharacterLevel(){return FUN_00780df0();}float GetDistanceToReference(Actor*a,bool b,bool c){return FUN_004edbf0(a,b,c);}int GetCurrentProcessLevel(){return FUN_007650b0();}bool HasBoundObject(){return FUN_006f8d90();}const char* GetFullName(){return FUN_004e9a10();}
};
struct TESPackage {
virtual void unknown_000();
virtual void unknown_004();
virtual void unknown_008();
virtual void unknown_00c();
virtual void unknown_010();
virtual void unknown_014();
virtual void unknown_018();
virtual void unknown_01c();
virtual void unknown_020();
virtual void unknown_024();
virtual void unknown_028();
virtual void unknown_02c();
virtual void unknown_030();
virtual void unknown_034();
virtual void unknown_038();
virtual void unknown_03c();
virtual void unknown_040();
virtual void unknown_044();
virtual void unknown_048();
virtual void unknown_04c();
virtual void unknown_050();
virtual void unknown_054();
virtual void unknown_058();
virtual void unknown_05c();
virtual void unknown_060();
virtual void unknown_064();
virtual void unknown_068();
virtual void unknown_06c();
virtual void unknown_070();
virtual void unknown_074();
virtual void unknown_078();
virtual void unknown_07c();
virtual void unknown_080();
virtual void unknown_084();
virtual void unknown_088();
virtual void unknown_08c();
virtual void unknown_090();
virtual void unknown_094();
virtual void unknown_098();
virtual void unknown_09c();
virtual void unknown_0a0();
virtual void unknown_0a4();
virtual void unknown_0a8();
virtual void unknown_0ac();
virtual void unknown_0b0();
virtual void unknown_0b4();
virtual void unknown_0b8();
virtual void unknown_0bc();
virtual void unknown_0c0();
virtual void unknown_0c4();
virtual void unknown_0c8();
virtual void unknown_0cc();
virtual void unknown_0d0();
virtual void unknown_0d4();
virtual void unknown_0d8();
virtual void unknown_0dc();
virtual void unknown_0e0();
virtual void unknown_0e4();
virtual void unknown_0e8();
virtual void unknown_0ec();
virtual void unknown_0f0();
virtual void unknown_0f4();
virtual void unknown_0f8();
virtual void unknown_0fc();
virtual void unknown_100();
virtual void unknown_104();
virtual void unknown_108();
virtual void unknown_10c();
virtual void unknown_110();
virtual void unknown_114();
virtual void unknown_118();
virtual void unknown_11c();
virtual void unknown_120();
virtual void unknown_124();
virtual void unknown_128();
virtual void unknown_12c();
virtual void unknown_130();
virtual void unknown_134();
virtual void unknown_138();
virtual bool IsPackageRunningForActor(Actor*,int,float,bool);
virtual bool IsSecondLocationDone(Actor*,Actor*,int,float,bool);
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
int procedure;
unsigned int unk1c;
signed char type;unsigned char unk21,unk22,unk23;
unsigned int unk24;
unsigned int unk28;
LocationDescriptor* location;
PackageTargetRecord* target;
unsigned int unk34;
unsigned int unk38;
void* next;
PackageTargetRecord* GetTarget(){return target;}int GetProcedureType(){return procedure;}bool HasEssentialStatus(){return (unk1c>>16)&1;}int GetPackType(){return type;}
int FUN_005a3d30();bool FUN_005a3b90();bool FUN_005a3ba0();bool FUN_005a3bb0();bool FUN_005a49a0();void FUN_005a4aa0(bool);void* TESPackage_GetLocationWorld(Actor*);Cell* FUN_005a52a0(Actor*);NiPoint3 TESPackage_GetLocationCoord(Actor*);void* FUN_005a4020();
int GetPackageTargetType(){return FUN_005a3d30();}bool FUN_00670f40(){return FUN_005a3b90();}bool FUN_00670f60(){return FUN_005a3ba0();}bool IsMustReachLocation(){return FUN_005a3bb0();}bool IsMustComplete(){return FUN_005a49a0();}void SetWaiting(bool b){FUN_005a4aa0(b);}void* GetPackageWorldSpace(Actor*a){return TESPackage_GetLocationWorld(a);}Cell* GetPackageLocationCell(Actor*a){return FUN_005a52a0(a);}NiPoint3 GetPackageLocationPosition(Actor*a){return TESPackage_GetLocationCoord(a);}void* GetPackageSecondLocation(){return FUN_005a4020();}
};
struct LowProcess {
virtual void unknown_000();
virtual void unknown_004();
virtual void unknown_008();
virtual void unknown_00c();
virtual void unknown_010();
virtual void unknown_014();
virtual void unknown_018();
virtual void unknown_01c();
virtual void unknown_020();
virtual bool CanProcessActor(Actor*,bool);
virtual void unknown_028();
virtual void unknown_02c();
virtual void unknown_030();
virtual void unknown_034();
virtual void unknown_038();
virtual void unknown_03c();
virtual void unknown_040();
virtual void unknown_044();
virtual void unknown_048();
virtual void unknown_04c();
virtual void unknown_050();
virtual void unknown_054();
virtual void unknown_058();
virtual void unknown_05c();
virtual void unknown_060();
virtual void unknown_064();
virtual void unknown_068();
virtual void unknown_06c();
virtual void unknown_070();
virtual void unknown_074();
virtual void unknown_078();
virtual void unknown_07c();
virtual void unknown_080();
virtual void unknown_084();
virtual void unknown_088();
virtual bool FindPackageTarget(Actor*);
virtual void SetGenericLocationsForPackage(Actor*,bool);
virtual void unknown_094();
virtual void unknown_098();
virtual void unknown_09c();
virtual void unknown_0a0();
virtual void unknown_0a4();
virtual void unknown_0a8();
virtual void unknown_0ac();
virtual void unknown_0b0();
virtual void unknown_0b4();
virtual void unknown_0b8();
virtual void unknown_0bc();
virtual void unknown_0c0();
virtual void vfn_c4(Actor*,bool);
virtual void vfn_c8(Actor*,TESPackage*,bool);
virtual void unknown_0cc();
virtual void unknown_0d0();
virtual void unknown_0d4();
virtual void unknown_0d8();
virtual void unknown_0dc();
virtual void unknown_0e0();
virtual void unknown_0e4();
virtual void unknown_0e8();
virtual void unknown_0ec();
virtual void unknown_0f0();
virtual void unknown_0f4();
virtual void unknown_0f8();
virtual void unknown_0fc();
virtual void unknown_100();
virtual void unknown_104();
virtual void unknown_108();
virtual void unknown_10c();
virtual void unknown_110();
virtual void unknown_114();
virtual void unknown_118();
virtual void unknown_11c();
virtual void unknown_120();
virtual void unknown_124();
virtual void unknown_128();
virtual void unknown_12c();
virtual void unknown_130();
virtual void unknown_134();
virtual void unknown_138();
virtual void unknown_13c();
virtual void unknown_140();
virtual void unknown_144();
virtual void unknown_148();
virtual void unknown_14c();
virtual void unknown_150();
virtual void unknown_154();
virtual void unknown_158();
virtual void unknown_15c();
virtual void unknown_160();
virtual void unknown_164();
virtual void unknown_168();
virtual void unknown_16c();
virtual void unknown_170();
virtual void unknown_174();
virtual void unknown_178();
virtual void unknown_17c();
virtual void unknown_180();
virtual void unknown_184();
virtual void unknown_188();
virtual void unknown_18c();
virtual void unknown_190();
virtual void unknown_194();
virtual void unknown_198();
virtual void unknown_19c();
virtual void unknown_1a0();
virtual void unknown_1a4();
virtual void unknown_1a8();
virtual void unknown_1ac();
virtual void unknown_1b0();
virtual void unknown_1b4();
virtual bool vfn_1bc();
virtual void vfn_1c0(bool);
virtual void unknown_1c0();
virtual void vfn_1c8(bool);
virtual void unknown_1c8();
virtual void unknown_1cc();
virtual void unknown_1d0();
virtual void unknown_1d4();
virtual void unknown_1d8();
virtual void unknown_1dc();
virtual void unknown_1e0();
virtual void unknown_1e4();
virtual void unknown_1e8();
virtual void unknown_1ec();
virtual void unknown_1f0();
virtual void unknown_1f4();
virtual void unknown_1f8();
virtual void unknown_1fc();
virtual void unknown_200();
virtual void unknown_204();
virtual void unknown_208();
virtual void unknown_20c();
virtual void unknown_210();
virtual void unknown_214();
virtual void unknown_218();
virtual void unknown_21c();
virtual void unknown_220();
virtual void unknown_224();
virtual TESPackage* GetCurrentPackage();
virtual void unknown_22c();
virtual void unknown_230();
virtual void unknown_234();
virtual void unknown_238();
virtual void unknown_23c();
virtual void unknown_240();
virtual void unknown_244();
virtual void unknown_248();
virtual void unknown_24c();
virtual void unknown_250();
virtual void unknown_254();
virtual void unknown_258();
virtual void unknown_25c();
virtual void unknown_260();
virtual void unknown_264();
virtual void unknown_268();
virtual void unknown_26c();
virtual void unknown_270();
virtual void unknown_274();
virtual void unknown_278();
virtual int GetProcedureIndex();
virtual void SetProcedureIndex(int);
virtual void SetProcessTarget(Actor*,int);
virtual void unknown_288();
virtual void unknown_28c();
virtual void unknown_290();
virtual void vfn_298(Actor*,bool,int,bool);
virtual void vfn_29c(Actor*,bool,bool,int);
virtual void vfn_2a0(Actor*);
virtual void unknown_2a0();
virtual void unknown_2a4();
virtual void unknown_2a8();
virtual void unknown_2ac();
virtual void unknown_2b0();
virtual void unknown_2b4();
virtual void unknown_2b8();
virtual void unknown_2bc();
virtual void unknown_2c0();
virtual void unknown_2c4();
virtual void unknown_2c8();
virtual void unknown_2cc();
virtual void unknown_2d0();
virtual void unknown_2d4();
virtual void unknown_2d8();
virtual void unknown_2dc();
virtual void unknown_2e0();
virtual void unknown_2e4();
virtual void unknown_2e8();
virtual void unknown_2ec();
virtual void unknown_2f0();
virtual void unknown_2f4();
virtual void unknown_2f8();
virtual void unknown_2fc();
virtual void unknown_300();
virtual void unknown_304();
virtual void unknown_308();
virtual void unknown_30c();
virtual void unknown_310();
virtual void unknown_314();
virtual void unknown_318();
virtual void unknown_31c();
virtual void unknown_320();
virtual void unknown_324();
virtual void unknown_328();
virtual void unknown_32c();
virtual void unknown_330();
virtual void unknown_334();
virtual void unknown_338();
virtual void unknown_33c();
virtual void unknown_340();
virtual void unknown_344();
virtual void unknown_348();
virtual void unknown_34c();
virtual void unknown_350();
virtual void unknown_354();
virtual void unknown_358();
virtual void unknown_35c();
virtual void unknown_360();
virtual void unknown_364();
virtual void unknown_368();
virtual void unknown_36c();
virtual void unknown_370();
virtual void unknown_374();
virtual void unknown_378();
virtual void unknown_37c();
virtual void unknown_380();
virtual void unknown_384();
virtual void unknown_388();
virtual void unknown_38c();
virtual void unknown_390();
virtual void unknown_394();
virtual void unknown_398();
virtual void unknown_39c();
virtual void unknown_3a0();
virtual void unknown_3a4();
virtual void unknown_3a8();
virtual void unknown_3ac();
virtual void unknown_3b0();
virtual void unknown_3b4();
virtual void unknown_3b8();
virtual void unknown_3bc();
virtual void unknown_3c0();
virtual void unknown_3c4();
virtual void unknown_3c8();
virtual void unknown_3cc();
virtual void unknown_3d0();
virtual void unknown_3d4();
virtual void unknown_3d8();
virtual void unknown_3dc();
virtual void unknown_3e0();
virtual void unknown_3e4();
virtual void unknown_3e8();
virtual void unknown_3ec();
virtual void unknown_3f0();
virtual void unknown_3f4();
virtual void unknown_3f8();
virtual void unknown_3fc();
virtual void unknown_400();
virtual void unknown_404();
virtual void unknown_408();
virtual void unknown_40c();
virtual void unknown_410();
virtual void unknown_414();
virtual void unknown_418();
virtual void unknown_41c();
virtual void unknown_420();
virtual void unknown_424();
virtual void unknown_428();
virtual void unknown_42c();
virtual void unknown_430();
virtual void unknown_434();
virtual void unknown_438();
virtual void unknown_43c();
virtual void unknown_440();
virtual void unknown_444();
virtual void unknown_448();
virtual void unknown_44c();
virtual void unknown_450();
virtual void unknown_454();
virtual void unknown_458();
virtual void unknown_45c();
virtual void unknown_460();
virtual void unknown_464();
virtual void unknown_468();
virtual void unknown_46c();
virtual void unknown_470();
virtual void unknown_474();
virtual void unknown_478();
virtual void unknown_47c();
virtual void unknown_480();
virtual void unknown_484();
virtual void unknown_488();
virtual void unknown_48c();
virtual void unknown_490();
virtual void unknown_494();
virtual void unknown_498();
virtual void unknown_49c();
virtual void unknown_4a0();
virtual void unknown_4a4();
virtual void unknown_4a8();
virtual void unknown_4ac();
virtual void unknown_4b0();
virtual void unknown_4b4();
virtual void unknown_4b8();
virtual void unknown_4bc();
virtual void unknown_4c0();
virtual void unknown_4c4();
virtual void unknown_4c8();
virtual void unknown_4cc();
virtual void unknown_4d0();
virtual void unknown_4d4();
virtual void unknown_4d8();
virtual void unknown_4dc();
virtual void unknown_4e0();
virtual void unknown_4e4();
virtual void unknown_4e8();
virtual void unknown_4ec();
virtual void unknown_4f0();
virtual void unknown_4f4();
virtual void unknown_4f8();
virtual void unknown_4fc();
virtual void unknown_500();
virtual void unknown_504();
virtual void unknown_508();
virtual void unknown_50c();
virtual void unknown_510();
virtual void unknown_514();
virtual void unknown_518();
virtual void UpdateCurrentPackage(Actor*);
virtual void unknown_520();
virtual void unknown_524();
virtual void unknown_528();
virtual void unknown_52c();
virtual void unknown_530();
virtual void unknown_534();
virtual void unknown_538();
virtual void unknown_53c();
virtual void unknown_540();
virtual void unknown_544();
virtual void unknown_548();
virtual void unknown_54c();
virtual void unknown_550();
virtual void unknown_554();
virtual void unknown_558();
virtual void unknown_55c();
virtual void unknown_560();
virtual void unknown_564();
virtual void unknown_568();
virtual void unknown_56c();
virtual void unknown_570();
virtual void unknown_574();
virtual void unknown_578();
virtual void unknown_57c();
virtual void unknown_580();
virtual void unknown_584();
virtual void unknown_588();
virtual void unknown_58c();
virtual void unknown_590();
virtual void unknown_594();
virtual void OnPackageEnd(Actor*,TESPackage*);
virtual bool vfn_5a4();
virtual void vfn_5a8(bool);
virtual void unknown_5a4();
virtual void unknown_5a8();
virtual void unknown_5ac();
virtual void unknown_5b0();
virtual void unknown_5b4();
virtual void unknown_5b8();
virtual void unknown_5bc();
virtual void unknown_5c0();
virtual void unknown_5c4();
virtual void unknown_5c8();
virtual void unknown_5cc();
virtual void unknown_5d0();
virtual void unknown_5d4();
virtual void unknown_5d8();
virtual void unknown_5dc();
virtual void unknown_5e0();
virtual void unknown_5e4();
virtual void unknown_5e8();
virtual void unknown_5ec();
virtual void unknown_5f0();
virtual void unknown_5f4();
virtual void unknown_5f8();
virtual void unknown_5fc();
virtual void unknown_600();
virtual void unknown_604();
virtual void unknown_608();
virtual void unknown_60c();
virtual void unknown_610();
virtual void unknown_614();
virtual void unknown_618();
virtual void unknown_61c();
virtual void unknown_620();
virtual void unknown_624();
virtual void unknown_628();
virtual void unknown_62c();
virtual void unknown_630();
virtual void unknown_634();
virtual void unknown_638();
virtual void unknown_63c();
virtual void unknown_640();
virtual void unknown_644();
virtual void unknown_648();
virtual void unknown_64c();
virtual void unknown_650();
virtual void unknown_654();
virtual void unknown_658();
virtual void unknown_65c();
virtual void unknown_660();
virtual void unknown_664();
virtual void unknown_668();
virtual void unknown_66c();
virtual void unknown_670();
virtual void unknown_674();
virtual void unknown_678();
virtual void unknown_67c();
virtual void unknown_680();
virtual void unknown_684();
virtual void unknown_688();
virtual void unknown_68c();
virtual void unknown_690();
virtual void unknown_694();
virtual void unknown_698();
virtual void unknown_69c();
virtual void unknown_6a0();
virtual void unknown_6a4();
virtual void unknown_6a8();
virtual void unknown_6ac();
virtual void unknown_6b0();
virtual void unknown_6b4();
virtual void unknown_6b8();
virtual void unknown_6bc();
virtual void unknown_6c0();
virtual void unknown_6c4();
virtual void unknown_6c8();
virtual void unknown_6cc();
virtual void unknown_6d0();
virtual void unknown_6d4();
virtual void unknown_6d8();
virtual void unknown_6dc();
virtual void unknown_6e0();
virtual void unknown_6e4();
virtual void unknown_6e8();
virtual void unknown_6ec();
virtual void unknown_6f0();
virtual void unknown_6f4();
virtual void unknown_6f8();
virtual void unknown_6fc();
virtual void unknown_700();
virtual void unknown_704();
virtual void unknown_708();
virtual void unknown_70c();
virtual void unknown_710();
virtual void unknown_714();
virtual void unknown_718();
virtual void unknown_71c();
virtual void unknown_720();
virtual void unknown_724();
virtual void unknown_728();
virtual void unknown_72c();
virtual void unknown_730();
virtual void unknown_734();
virtual void unknown_738();
virtual void unknown_73c();
virtual void unknown_740();
virtual void unknown_744();
virtual void unknown_748();
virtual void unknown_74c();
virtual void unknown_750();
virtual void unknown_754();
virtual void unknown_758();
virtual void unknown_75c();
virtual void unknown_760();
virtual void unknown_764();
virtual void unknown_768();
virtual void unknown_76c();
virtual void unknown_770();
virtual void unknown_774();
virtual void unknown_778();
virtual void unknown_77c();
virtual void unknown_780();
virtual void unknown_784();
virtual void unknown_788();
virtual void unknown_78c();
virtual void unknown_790();
virtual void unknown_794();
virtual void unknown_798();
virtual void vfn_7b4(Actor*);
virtual void unknown_7a0();
virtual void unknown_7a4();
virtual void unknown_7a8();
virtual void ProcessAlarm(Actor*);
virtual bool ProcessActivate(Actor*,bool);
virtual void ProcessAccompany(Actor*);
virtual void ProcessAcquire(Actor*);
virtual void ProcessAmbushWait(Actor*);
virtual void ProcessUseItemAt(Actor*);
virtual bool ProcessUseWeapon(Actor*);
virtual void vfn_7e0(Actor*);
virtual void ProcessFleeNonCombat(Actor*);
virtual void unknown_7d0();
virtual void ProcessSandbox(Actor*);
virtual void ProcessMovementBlocked(Actor*);
virtual void ProcessGuard(Actor*);
virtual void unknown_7e0();
virtual void ProcessPatrol(Actor*);
virtual void vfn_800(Actor*);
virtual void unknown_7ec();
virtual void ProcessNotify(Actor*);
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
unsigned int unk24;
unsigned int unk28;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
unsigned int unk3c;
Actor* pTarget;
Actor* m_pReference40;
unsigned int unk48;
unsigned int unk4c;
unsigned int unk50;
unsigned int unk54;
int m_iValue58;
List ReferenceListNode;
Date* m_pDetectionData60;
unsigned int unk68;
unsigned int unk6c;
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;
unsigned int unka8;
unsigned int unkac;
bool m_bHasBoundObject;unsigned char unkb1,unkb2,unkb3;
void FUN_0074acb0();float FUN_00749cc0(Actor*);bool FUN_0074a030(Actor*);void UpdateTargetFromPackage(){FUN_0074acb0();}float GetActorTimeDelta(Actor*a){return FUN_00749cc0(a);}bool SelectNextPackage(Actor*a){return FUN_0074a030(a);}void FUN_00750eb0(Actor*);
};
void Script_SetActionFlag(TESPackage*,void*,int);
struct Script {static void GetLocalData(TESPackage*p,void*d,int f){Script_SetActionFlag(p,d,f);}};
inline const char* PackageName(TESPackage*p){return DAT_00f66798[p->GetPackType()];}
// pdb: LowProcess::Update | LowProcess.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apRef
void LowProcess::FUN_00750eb0(Actor* mobile)
{
    if (!mobile)
        return;
    struct UpdateContext
    {
        Actor* actor;
        float hour;
    } update;
    DAT_01079f68.GetGameTime();
    update.actor = 0;
    if (mobile->IsActor())
        update.actor = static_cast<Actor*>(mobile);
    if (update.actor)
    {
        if (update.actor->vfn_274(true) && DAT_0107a104->FUN_0076c8e0())
            update.actor->vfn_434(false);
        struct PackageState
        {
            Actor* location;
            PackageTargetRecord* target;
            TESPackage* current;
        } state;
        TESPackage* package = GetCurrentPackage();
        if (CanProcessActor(update.actor, false))
        {
            UpdateCurrentPackage(update.actor);
            package = GetCurrentPackage();
            update.actor->FUN_007001e0();
            SetGenericLocationsForPackage(update.actor, false);
            state.current = GetCurrentPackage();
            if (state.current)
            {
                state.target = state.current->GetTarget();
                if (state.target && state.target->FUN_005ad6b0() != 0 && state.target->FUN_005ad6b0() != 3)
                    m_iValue58 = state.current->FUN_005a3d30();
            }
        }
        bool bPathingFailed = false;
        if (m_bHasBoundObject && update.actor->FUN_006f8d60())
            bPathingFailed = true;
        if (GetCurrentPackage() && GetCurrentPackage()->GetProcedureType() != -1 &&
            !GetCurrentPackage()->HasEssentialStatus())
        {
            char message[300];
            FUN_0074acb0();
            state.location = 0;
            switch (DAT_00f6ee80[GetCurrentPackage()->GetProcedureType()][GetProcedureIndex()])
            {
            case 0: {
                state.location = m_pReference40;
                if (!GetCurrentPackage()->IsPackageRunningForActor(update.actor, 0, -1.0f, false))
                {
                    if (update.actor->FUN_006f8d70())
                    {
                        if (!update.actor->Actor_SetPathfindingGoal(GetCurrentPackage()->TESPackage_GetLocationCoord(update.actor),
                                                        GetCurrentPackage()->FUN_005a52a0(update.actor),
                                                        GetCurrentPackage()->TESPackage_GetLocationWorld(update.actor), -1.0f,
                                                        0))
                            return;
                    }
                    float delta = FUN_00749cc0(update.actor);
                    if (update.actor->GetProcess()
                                ->GetProcessLevel() == 3 &&
                        GetCurrentPackage()->IsPackageRunningForActor(update.actor, 0, -1.0f, false))
                    {
                        if (!vfn_1bc())
                        {
                            if (GetCurrentPackage()->FUN_005a3b90())
                                DAT_0106cdcc->TESDataHandler_EnumReferencesCloseToPoint(
                                    update.actor->GetParentCell(), *update.actor->GetPos(),
                                    DAT_00e12730, *update.actor->GetPos(),
                                    DAT_00e12730, FUN_0074b090,
                                    reinterpret_cast<long>(update.actor));
                            vfn_1c0(true);
                        }
                        if (GetCurrentPackage()->FUN_005a3ba0())
                            DAT_0106cdcc->TESDataHandler_EnumReferencesCloseToPoint(update.actor->GetParentCell(), *update.actor->GetPos(),
                                                               DAT_00e12730, *update.actor->GetPos(),
                                                               DAT_00e12730, FUN_0074b130,
                                                               reinterpret_cast<long>(update.actor));
                        SetProcessTarget(update.actor, 1);
                        if ((state.location && state.location->GetObjectReference() == DAT_01071664) ||
                            (GetCurrentPackage()->location &&
                             GetCurrentPackage()->location
                                     ->FUN_005acce0() == 3))
                        {
                            float rotation = 0.0f;
                            if (state.location)
                                rotation = state.location->rotation.z;
                            else
                                rotation = update.actor->vfn_16c().z;
                            update.actor->vfn_2c4(rotation);
                        }
                    }
                }
                else
                {
                    if (!vfn_1bc())
                    {
                        if (GetCurrentPackage()->FUN_005a3b90())
                            DAT_0106cdcc->TESDataHandler_EnumReferencesCloseToPoint(
                                update.actor->GetParentCell(), *update.actor->GetPos(), DAT_00e12730,
                                *update.actor->GetPos(), DAT_00e12730, FUN_0074b090,
                                reinterpret_cast<long>(update.actor));
                        vfn_1c0(true);
                    }
                    if (GetCurrentPackage()->FUN_005a3ba0())
                        DAT_0106cdcc->TESDataHandler_EnumReferencesCloseToPoint(update.actor->GetParentCell(), *update.actor->GetPos(),
                                                           DAT_00e12730, *update.actor->GetPos(),
                                                           DAT_00e12730, FUN_0074b130,
                                                           reinterpret_cast<long>(update.actor));
                    if ((state.location && state.location->GetObjectReference() == DAT_01071664) ||
                        (GetCurrentPackage()->location &&
                         GetCurrentPackage()->location
                                 ->FUN_005acce0() == 3))
                    {
                        float completedRotation = 0.0f;
                        if (state.location)
                            completedRotation = state.location->rotation.z;
                        else
                            completedRotation = update.actor->vfn_16c().z;
                        update.actor->vfn_2c4(completedRotation);
                    }
                    SetProcessTarget(update.actor, 1);
                }
                break;
            }
            case 9:
                break;
            case 33:
                vfn_7e0(update.actor);
                break;
            case 41:
                SetProcessTarget(update.actor, 2);
                break;
            case 10:
                vfn_2a0(update.actor);
                break;
            case 34:
                ProcessFleeNonCombat(update.actor);
                break;
            case 35:
                vfn_c4(update.actor, true);
                break;
            case 26:
                ProcessNotify(update.actor);
                break;
            case 47:
                ProcessGuard(update.actor);
                break;
            case 38:
                vfn_800(update.actor);
                break;
            case 27:
                ProcessAccompany(update.actor);
                break;
            case 28:
                ProcessUseItemAt(update.actor);
                break;
            case 50:
                ProcessUseWeapon(update.actor);
                break;
            case 17:
                if (!pTarget)
                    FindPackageTarget(update.actor);
                if (pTarget && pTarget != DAT_0107a104 && pTarget->IsActor())
                    vfn_c8(update.actor, GetCurrentPackage(), true);
                SetProcessTarget(update.actor, 1);
                break;
            case 14:
                ProcessActivate(update.actor, false);
                break;
            case 3:
                ProcessAcquire(update.actor);
                break;
            case 12:
                update.actor->Actor_EndInterruptPackage(false);
                break;
            case 49: {
                Actor* target = 0;
                if (pTarget && pTarget->IsActor())
                    target = static_cast<Actor*>(pTarget);
                if (target && (!GetCurrentPackage()->FUN_005a4020() ||
                               GetCurrentPackage()->IsSecondLocationDone(target, update.actor, 0, -1.0f, true)))
                    ProcessActivate(update.actor, true);
                break;
            }
            case 8:
                ProcessAlarm(update.actor);
                break;
            case 15:
                vfn_29c(update.actor, false, true, 0x101);
                break;
            case 2:
                ProcessActivate(update.actor, true);
                break;
            case 1:
                if (GetCurrentPackage()->GetProcedureType() == 26)
                    SetProcessTarget(update.actor, -1);
                break;
            case 4:
                if (FUN_006193c0() == update.actor)
                {
                    sprintf(message, "%s is sleeping with %s", update.actor->FUN_004e9a10(),
                            PackageName(GetCurrentPackage()));
                    FUN_006195d0(message);
                }
                break;
            case 5:
                if (FUN_006193c0() == update.actor)
                {
                    sprintf(message, "%s is eating with %s", update.actor->FUN_004e9a10(),
                            PackageName(GetCurrentPackage()));
                    FUN_006195d0(message);
                }
                break;
            case 6:
                vfn_298(update.actor, true, 0x101, false);
                break;
            case 42:
                ProcessSandbox(update.actor);
                break;
            case 51:
                ProcessMovementBlocked(update.actor);
                break;
            case 30:
                ProcessAmbushWait(update.actor);
                break;
            case 13:
                if (!pTarget)
                    FindPackageTarget(update.actor);
                if (!pTarget || pTarget->IsDeleted())
                    SetProcessTarget(update.actor, 1);
                else if (package->HasEssentialStatus())
                {
                    if (!DAT_0107a104->FUN_00772c00(update.actor) &&
                        DAT_0107a104->FUN_00780df0() < DAT_00f5e838.Int()->i)
                        GetCurrentPackage()->FUN_005a4aa0(false);
                }
                else if (package->GetPackType() != 28 && !package->HasEssentialStatus())
                {
                    if (package->GetPackType() == 1)
                    {
                        float distance = static_cast<float>(static_cast<int>(package->GetTarget()->FUN_004a0890()));
                        if (update.actor->FUN_004edbf0(pTarget, false, false) <= distance)
                            SetProcessTarget(update.actor, 1);
                    }
                    else
                    {
                        struct FollowDistance
                        {
                            int targetCount;
                            float distanceLimit;
                        } follow;
                        follow.distanceLimit = 0.0f;
                        follow.targetCount = static_cast<int>(package->GetTarget()->FUN_004a0890());
                        if (follow.targetCount <= 0)
                            follow.targetCount = 200;
                        if (follow.distanceLimit == 0.0 && update.actor->GetParentCell() &&
                            update.actor->GetParentCell()->IsCellInterior())
                            follow.distanceLimit =
                                DAT_00f5e868.Float()->f;
                        else if (follow.distanceLimit == 0.0)
                            follow.distanceLimit =
                                follow.targetCount *
                                DAT_00f5e85c.Float()->f;
                        SetProcessTarget(update.actor, 1);
                    }
                }
                break;
            case 7:
                switch (GetCurrentPackage()->GetPackType())
                {
                case 1:
                case 2:
                case 7:
                case 22:
                    vfn_7b4(update.actor);
                    break;
                }
                break;
            case 11:
                break;
            case 44:
                ProcessPatrol(update.actor);
                break;
            default:
                break;
            }
            if (update.actor->FUN_007650b0() == 3 && GetCurrentPackage() &&
                DAT_00f6ee80[GetCurrentPackage()->GetProcedureType()][GetProcedureIndex()] == 53)
            {
                if (!vfn_5a4())
                {
                    Script_SetActionFlag(GetCurrentPackage(), update.actor->GetExtraData(), 0x400);
                    OnPackageEnd(update.actor, GetCurrentPackage());
                    vfn_5a8(true);
                }
                vfn_1c8(false);
                if (GetCurrentPackage() && GetCurrentPackage()->GetProcedureType() == 0 &&
                    !GetCurrentPackage()->IsPackageRunningForActor(update.actor, 0, -1.0f, false))
                {
                    SetProcessTarget(update.actor, -1);
                    return;
                }
                if (GetCurrentPackage() && GetCurrentPackage()->FUN_005a3bb0())
                    update.actor->vfn_28c(GetCurrentPackage(), DAT_01079f68.FUN_006e2a60());
                if (GetCurrentPackage() && GetCurrentPackage()->FUN_005a49a0())
                    update.actor->Actor_EndInterruptPackage(false);
                if (FUN_006193c0() == update.actor)
                {
                    sprintf(message, "%s is done with %s", update.actor->FUN_004e9a10(),
                            PackageName(GetCurrentPackage()));
                    FUN_006195d0(message);
                }
                if (m_pDetectionData60) DAT_01090a78.FUN_0086ba60(m_pDetectionData60);
                m_pDetectionData60 = 0;
                while (!ReferenceListNode.IsEmpty())
                {
                    Date* item = ReferenceListNode.GetItem();
                    if (item) DAT_01090a78.FUN_0086ba60(item);
                    ReferenceListNode
                        .Remove(item);
                }
                if (GetCurrentPackage() &&
                    !GetCurrentPackage()->next)
                {
                    TESPackage* previous = GetCurrentPackage();
                    FUN_0074a030(update.actor);
                    package = GetCurrentPackage();
                    if (previous != GetCurrentPackage())
                        SetProcedureIndex(0);
                }
            }
        }
        if (!update.actor->FUN_006f8d90() || bPathingFailed)
        {
            mobile->GetProcess()->Update();
            m_bHasBoundObject = false;
        }
        else
            m_bHasBoundObject = true;
    }
    else
        mobile->GetProcess()->Update();
}


}
}   // namespace f3m_00750eb0
