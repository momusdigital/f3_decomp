#include <windows.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00500000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00511510 (community match, verified in this file)
extern float g_values[7], g_types[4];
extern int* g_categories[];
extern __declspec(thread) bool g_consoleMode;
namespace f3m_00511510 {
struct Setting { int unk00, kind, value; };
struct Record { int unk00,unk04,unk08,unk0c,unk10,unk14; int group; int unk1c; unsigned char type; bool FUN_007995e0(); };
struct Ref {
virtual int v0();
virtual int v1();
virtual int v2();
virtual int v3();
virtual int v4();
virtual int v5();
virtual int v6();
virtual int v7();
virtual int v8();
virtual int v9();
virtual int v10();
virtual int v11();
virtual int v12();
virtual int v13();
virtual int v14();
virtual int v15();
virtual int v16();
virtual int v17();
virtual int v18();
virtual int v19();
virtual int v20();
virtual int v21();
virtual int v22();
virtual int v23();
virtual int v24();
virtual int v25();
virtual int v26();
virtual int v27();
virtual int v28();
virtual int v29();
virtual int v30();
virtual int v31();
virtual int v32();
virtual int v33();
virtual int v34();
virtual int v35();
virtual int v36();
virtual int v37();
virtual int v38();
virtual int v39();
virtual int v40();
virtual int v41();
virtual int v42();
virtual int v43();
virtual int v44();
virtual int v45();
virtual int v46();
virtual int v47();
virtual int v48();
virtual int v49();
virtual int v50();
virtual int v51();
virtual int v52();
virtual int v53();
virtual int v54();
virtual int v55();
virtual int v56();
virtual int v57();
virtual int v58();
virtual int v59();
virtual int v60();
virtual int v61();
virtual int v62();
virtual int v63();
virtual bool v64();
virtual int v65();
virtual int v66();
virtual int v67();
virtual int v68();
virtual int v69();
virtual int v70();
virtual int v71();
virtual int v72();
virtual int v73();
virtual int v74();
virtual int v75();
virtual int v76();
virtual int v77();
virtual int v78();
virtual int v79();
virtual int v80();
virtual int v81();
virtual int v82();
virtual int v83();
virtual int v84();
virtual int v85();
virtual int v86();
virtual int v87();
virtual int v88();
virtual int v89();
virtual int v90();
virtual int v91();
virtual int v92();
virtual int v93();
virtual int v94();
virtual int v95();
virtual int v96();
virtual int v97();
virtual int v98();
virtual int v99();
virtual int v100();
virtual int v101();
virtual int v102();
virtual int v103();
virtual int v104();
virtual int v105();
virtual int v106();
virtual int v107();
virtual int v108();
virtual int v109();
virtual int v110();
virtual int v111();
virtual int v112();
virtual int v113();
virtual int v114();
virtual int v115();
virtual int v116();
virtual int v117();
virtual int v118();
virtual int v119();
virtual int v120();
virtual int v121();
virtual int v122();
virtual int v123();
virtual int v124();
virtual int v125();
virtual int v126();
virtual int v127();
virtual int v128();
virtual int v129();
virtual int v130();
virtual int v131();
virtual int v132();
virtual int v133();
virtual int v134();
virtual int v135();
virtual int v136();
virtual int v137();
virtual int v138();
virtual int v139();
virtual int v140();
virtual int v141();
virtual int v142();
virtual int v143();
virtual int v144();
virtual int v145();
virtual int v146();
virtual int v147();
virtual int v148();
virtual int v149();
virtual int v150();
virtual int v151();
virtual int v152();
virtual int v153();
virtual int v154();
virtual int v155();
virtual Setting* v156();
virtual int v157();
virtual int v158();
virtual int v159();
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
int unk58;
int unk5c;
Ref* base; Record* MobileObject_GetCurrentPackage(); };
void FUN_006195d0(const char*, ...);
// pdb: Script::GetCurrentAIProcedureConditionFunction | TESConditionFunctions.obj | fnv360_0822_retail, caller_sim + skyrim(objrun), high
bool __cdecl Script_GetCurrentAIProcedureConditionFunction(Ref* ref, int arg2, int arg3, double* result) {
*result=0.0;
if(ref && ref->v64() && ref->base && ref->MobileObject_GetCurrentPackage()) {
Record* record=ref->MobileObject_GetCurrentPackage();
Ref* base=ref->base;
int group=record->group;
int kind=g_categories[group][base->v159()];
if(record->type==18 && record->FUN_007995e0()) kind=10;
switch(kind) {
case 0: *result=0.0; break;
case 2: *result=1.0; break;
case 3: *result=2.0; break;
case 13: *result=3.0; break;
case 12: *result=4.0; break;
case 16: *result=5.0; break;
case 20: *result=6.0; break;
case 1: *result=7.0; break;
case 4: *result=8.0; break;
case 18: *result=9.0; break;
case 5: *result=10.0; break;
case 6: *result=11.0; break;
case 7: *result=12.0; break;
case 9: *result=13.0; break;
case 8: *result=14.0; break;
case 15: *result=15.0; break;
case 10: *result=16.0; break;
case 53: *result=17.0; break;
case 11: *result=18.0; break;
case 14: *result=19.0; break;
case 17: *result=20.0; break;
case 22: *result=21.0; break;
case 23: *result=22.0; break;
case 24: *result=23.0; break;
case 25: *result=24.0; break;
case 27: *result=27.0; break;
case 28: *result=28.0; break;
case 29: *result=29.0; break;
case 30: *result=30.0; break;
case 31: *result=31.0; break;
case 32: *result=32.0; break;
case 33: *result=33.0; break;
case 34: *result=34.0; break;
case 35: *result=35.0; break;
case 36: *result=36.0; break;
case 37: *result=37.0; break;
case 38: *result=38.0; break;
case 39: *result=39.0; break;
case 40: *result=40.0; break;
case 44: *result=41.0; break;
case 50: *result=42.0; break;
case 49: *result=43.0; break;
case 47: *result=44.0; break;
case 42: { Setting* s=base->v156(); *result=45.0; if(s) { if(s->kind==3) { unsigned int index=s->value+1; if(index<7) *result=g_values[index]; } else if(s->kind>=0 && (unsigned)s->kind<4) *result=g_types[s->kind]; } break; }
case 43: *result=46.0; break;
case 41: *result=47.0; break;
case 51: *result=49.0; break;
case 52: *result=50.0; break;
default: *result=-1.0; break;
}
}
if(g_consoleMode) FUN_006195d0("Procedure >> %0.2f", *result);
return true;
}
}   // namespace f3m_00511510

// @f3 0x00507cd0 (community match, verified in this file)
namespace f3m_00507cd0 {


struct Vec { float x,y,z; bool operator==(const Vec& v) const {return x==v.x && y==v.y && z==v.z;} };
struct Frustum { float left,right,top,bottom,nearPlane,farPlane; int ortho; };
struct Update { float time; bool controllers,a,b,c,d; Update(float t):time(t),controllers(true),a(false),b(false),c(false),d(false){} };
struct Model { virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10(); virtual const char* Get(); const char* text; unsigned short length; unsigned short cap; };
struct Scene;
struct Interpolator { int vptr,ref,unk8; unsigned short flags; bool Animated()const{return (flags>>5)&1;} void* FUN_00507b30(unsigned*,int*,unsigned char*); };
struct Controller { virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void v60();virtual void v64();virtual void v68();virtual void v6c();virtual void v70();virtual void v74();virtual void v78();virtual void v7c();virtual void v80();virtual void v84();virtual void v88();virtual void v8c();virtual void v90();virtual void v94();virtual void v98();virtual void v9c();virtual void va0();virtual void va4();virtual void va8();virtual void vac();virtual void vb0();virtual void vb4();virtual void vb8();virtual void vbc();virtual void vc0();virtual Interpolator* Get(int); };
struct Scene { virtual void v0(); virtual void Destroy(); long ref;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;Vec position;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;Scene** children; unsigned short capacity,count;int unka8;int unkac;int unkb0;int unkb4;int unkb8;int unkbc;int unkc0;int unkc4;int unkc8;int unkcc;int unkd0;int unkd4;int unkd8;Frustum frustum;
Scene* Child(){if(count<=0u)return 0; return children[0];}
void IncRefCount(){InterlockedIncrement(&ref);} void DecRefCount(){if(!InterlockedDecrement(&ref))Destroy();}
void FUN_008264c0(const Update&); Controller* FUN_00825200(const void*);
};
struct Loader { Scene* FUN_00429eb0(const char*,int,int,int,int,int); void FUN_00429640(const char*,int,int); void Release(const char* n){FUN_00429640(n,1,1);} }; extern Loader* DAT_0106ca70;
extern void* __cdecl FUN_00424d50(const void*,void*);
extern void __cdecl FUN_00478ce0(Scene*,float);
extern void __cdecl FUN_00887da0(const char*,...);
extern char DAT_0108f40c, DAT_01091f5c, DAT_010926a0, DAT_01092698;
extern char DAT_00dd0b20,DAT_00dd0ae0,DAT_00dd0a80,DAT_00dd0a6c,DAT_00dd0a5c;
extern float DAT_0108d01c, DAT_00f50854; extern double DAT_00dd0ad8;
extern Vec DAT_0108ec68,DAT_010719cc,DAT_010719a0;
extern float DAT_0107197c,DAT_01071974,DAT_01071978;
extern bool DAT_0107ba89,DAT_01071970,DAT_01071971;
struct StateInner {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;unsigned flags; bool Bit2(){return (flags>>2)&1;} bool Bit3(){return (flags>>3)&1;} bool Bit4(){return (flags>>4)&1;} }; struct State { int u0,u4,u8,uc,u10; StateInner* inner; };
struct StateManager { State* FUN_007cf350(); }; extern StateManager DAT_0108d098;
struct Event { int value,id; bool valid; void FUN_00bd00c0(int); }; struct EventManager { void FUN_00bcfcd0(Event*,const char*,int); }; extern EventManager* DAT_011790c8;
struct FinalManager { void FUN_007785d0(); }; extern FinalManager* DAT_0107a104;
struct Target {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;Model model;int unk24;int unk28;int unk2c;int unk30;int unk34;int mode; int unk3c,unk40; unsigned flags; int unk48,unk4c,unk50,unk54; float blend; int unk5c,unk60,unk64; int input; NiPointer<Scene> scene; int unk70; char animated;
bool Bit5(){return (flags>>5)&1;}
void FUN_00507cd0(int,int);
};
// pdb: BGSCameraShot::InitCamera | BGSCameraShot.obj | fnv360_0822_retail, ustr, medium
// pdb params: apTargetRef, aeZoom
void Target::FUN_00507cd0(int arg,int type){
 if ((model.length==0xffff?strlen(model.text):model.length)!=0) scene=DAT_0106ca70->FUN_00429eb0(model.Get(),0,1,1,0,0);
 Scene* camera;
 if(scene.m_pObject) camera=(Scene*)FUN_00424d50(&DAT_0108f40c,scene->Child()); else camera=0;
 if(!camera){
 FUN_00887da0(&DAT_00dd0b20,model.Get());
 scene=0;
 DAT_0106ca70->Release(model.Get());
 }
 if(scene.m_pObject){
 Update update(DAT_0108d01c);
 if(Bit5()) FUN_00478ce0(scene.m_pObject,-DAT_0108d01c);
 scene->FUN_008264c0(update);
 if(animated==-1){ Controller* ctrl=scene->FUN_00825200(&DAT_01091f5c);
 if(ctrl){ Interpolator* interp=ctrl->Get(0); Interpolator* rot=(Interpolator*)FUN_00424d50(&DAT_010926a0,interp);
 if(rot){unsigned count; int keyType; unsigned char keyFlags; rot->FUN_00507b30(&count,&keyType,&keyFlags); if(count) animated=1;}
 else { rot=(Interpolator*)FUN_00424d50(&DAT_01092698,interp); if(rot && rot->Animated()) animated=1; }
 if(animated==-1)animated=0;
 }}
 if(scene->position==DAT_0108ec68) FUN_00887da0(&DAT_00dd0ae0,model.Get());
 Frustum frustum=camera->frustum;
 if(frustum.top/frustum.right<DAT_00dd0ad8) FUN_00887da0(&DAT_00dd0a80,model.Get());
 }
 input=arg;
 DAT_0107ba89=true;
 switch(type){case 0:DAT_01071970=true; DAT_0107197c=DAT_00f50854;break;case 1:DAT_01071970=false;break;case 2:if(mode==3){DAT_01071970=true; DAT_0107197c=blend>0.0f?blend:DAT_00f50854;}break;}
 DAT_01071974=0.0f; DAT_01071978=0.0f;
 DAT_010719cc=DAT_0108ec68; DAT_010719a0=DAT_0108ec68;
 State* state=DAT_0108d098.FUN_007cf350();
 if(state && !DAT_01071971){if( (state->inner->Bit2() || state->inner->Bit3() || state->inner->Bit4()) && mode==2){ Event event; DAT_01071971=true; DAT_011790c8->FUN_00bcfcd0(&event,&DAT_00dd0a6c,0x121);event.FUN_00bd00c0(0);}}
 else if(DAT_01071971 && mode!=2){Event event;DAT_01071971=false;DAT_011790c8->FUN_00bcfcd0(&event,&DAT_00dd0a5c,0x121);event.FUN_00bd00c0(0);}
 DAT_0107a104->FUN_007785d0();
}
}   // namespace f3m_00507cd0

// @f3 0x00504f60 (community match, verified in this file)
#include <windows.h>
namespace f3m_00504f60 {
// pdb: TESWorldSpace::InitializeData | TESWorldSpace.obj | fnv360_0822_retail, vtable, medium
namespace G1365{extern float DAT_00dcfc60;}struct Reference1365{virtual void v0();virtual void Destroy();long references04;};struct Ref1365{Reference1365* object;void Clear(){Reference1365* previous=object;if(previous){if(!InterlockedDecrement(&previous->references04))previous->Destroy();object=0;}}};struct Map1365{virtual void Clear();unsigned int count04;void* buckets08;};struct World1365{unsigned int value00;unsigned int value04;unsigned int value08;unsigned int value0C;unsigned int value10;unsigned int value14;unsigned int value18;unsigned int value1C;unsigned int value20;unsigned int value24;unsigned int value28;unsigned int value2C;unsigned int value30;unsigned int value34;unsigned int value38;unsigned int value3C;unsigned int value40;unsigned int value44;unsigned int value48;unsigned char flags4C,unk4D;unsigned short parentFlags4E;unsigned int value50;unsigned int value54;unsigned int value58;unsigned int value5C;unsigned int value60;unsigned int value64;unsigned int value68;Ref1365 reference6C;unsigned int value70;unsigned int value74;unsigned int value78;float value7C;unsigned int value80;unsigned int value84;unsigned int value88;unsigned int value8C;float value90;float value94;float value98;unsigned int value9C;unsigned int valueA0;unsigned int valueA4;unsigned int valueA8;unsigned int valueAC;unsigned int valueB0;unsigned int valueB4;unsigned int valueB8;unsigned int valueBC;unsigned int valueC0;unsigned int valueC4;float valueC8;float valueCC;unsigned int valueD0;Map1365 mapD4;Map1365 mapE0;bool FUN_004543f0();void FUN_005042a0();void FUN_00504f60();};void World1365::FUN_00504f60(){value70=0;valueD0=0;flags4C=0;parentFlags4E=0;if(!FUN_004543f0())flags4C|=1;value7C=0.f;value40=0;value44=0;value90=1.f;value74=0;value78=0;value94=0.f;value98=0.f;FUN_005042a0();valueC8=G1365::DAT_00dcfc60;value9C=0;value48=0;valueCC=0.f;reference6C.Clear();mapD4.Clear();mapE0.Clear();}
}   // namespace f3m_00504f60

// @f3 0x00519040 (community match, verified in this file)
namespace f3m_00519040 {

namespace Remove173{
extern CRITICAL_SECTION DAT_01071c00;
struct List173{void FUN_00421610(void**);};
extern List173 DAT_01071bbc,DAT_01071bac,DAT_01071bf0,DAT_01071bc8;
// pdb: Script::RemoveDelayedScriptActionReference | TESScript.obj | fnv360_0721_retail, call_seq, medium
// pdb params: apRef
void __cdecl FUN_00519040(void* item){if(item){EnterCriticalSection(&DAT_01071c00);DAT_01071bbc.FUN_00421610(&item);DAT_01071bac.FUN_00421610(&item);DAT_01071bf0.FUN_00421610(&item);DAT_01071bc8.FUN_00421610(&item);LeaveCriticalSection(&DAT_01071c00);}}
}
}   // namespace f3m_00519040

// @f3 0x00518e30 (community match, verified in this file)
namespace f3m_00518e30 {
class BStr {
public:
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BStr() { pString = 0; sLen = 0; sMaxLen = 0; }
    ~BStr();
    void operator=(const BStr& src);
};

class CopyTarget {
public:
    BStr text;
    unsigned int unk08;
    unsigned int unk0c;
    CopyTarget(const CopyTarget& other);
};

CopyTarget::CopyTarget(const CopyTarget& other)
{
    text = other.text;
    unk08 = other.unk08;
    unk0c = other.unk0c;
}
}   // namespace f3m_00518e30
