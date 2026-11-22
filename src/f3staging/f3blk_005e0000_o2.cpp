#include <math.h>
#include <string.h>
#include <windows.h>
// src/f3staging/f3blk_005e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005ecde0 (community match, verified in this file)
struct FUN_005ecde0_Elem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void FUN_005fc480(int value);
};

struct FUN_005ecde0_Owner {
    int unk00;
    FUN_005ecde0_Elem* unk04;
    int FUN_005ebec0();
    void FUN_005eaa60(FUN_005ecde0_Elem* elem, int flag);
    int FUN_005ecde0(int value);
};

// pdb: BSSimpleArray<PathingLocation,1024>::Add | PathBuilder.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aValue
int FUN_005ecde0_Owner::FUN_005ecde0(int value) {
    int index = FUN_005ebec0();
    FUN_005eaa60(unk04 + index, 1);
    (unk04 + index)->FUN_005fc480(value);
    return index;
}

// @f3 0x005ffc00 (community match, verified in this file)
struct Owner303 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    float value18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    float value44;
    void FUN_005ff580();
    void FUN_005ffb40(unsigned int* state, float value);
    void FUN_005ffc00();
};
// pdb: PathingLOSGridMap::ClearSeen | PathingLOSGridMap.obj | fnv360_0822_retail, objrun, medium
void Owner303::FUN_005ffc00() {
    value18 = 0.0f;
    FUN_005ff580();
    FUN_005ffb40(&unk1C, value44);
}

// @f3 0x005fd540 (community match, verified in this file)
class FUN_005fd540 {
public:
    virtual ~FUN_005fd540();
    void PathingLocation_SetupData(unsigned int first, unsigned int second, unsigned int third);
    FUN_005fd540(unsigned int first, unsigned int second, unsigned int third);
};
// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSTSmartPointer<class CraftingSubMenus::EnchantConstructMenu::ItemChangeEntry,struct BSTSmartPointerIntrusiveRefCount>::operator!=)
// pdb params: aLocation, apCell, apWorldSpace
FUN_005fd540::FUN_005fd540(unsigned int first, unsigned int second, unsigned int third) {
    PathingLocation_SetupData(first, second, third);
}

// @f3 0x005f14e0 (community match, verified in this file)
namespace f3m_005f14e0 {

struct PointM { float x, y, z; };
extern PointM DAT_0108ec68;

struct BaseM
{
    BaseM();
    virtual ~BaseM();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20;
    int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40;
    int unk44; int unk48; int unk4C; int unk50;
};

struct MemberM : BaseM
{
    MemberM() {}
    virtual ~MemberM();
};

struct FUN_005f14e0
{
    unsigned char b00, b01, b02;
    int unk04;
    PointM pos08;
    MemberM m14;
    struct PairM { int a; int b; PairM() : a(0), b(-1) {} } p68;
    unsigned char b70, b71, b72, b73, b74, b75;
    FUN_005f14e0();
};

// pdb: CombatCoverLocation::CombatCoverLocation | Pathfind.obj | fnv360_0822_retail, call_gap_sim, low
FUN_005f14e0::FUN_005f14e0()
    : b00(0), b01(0), b02(0), unk04(0), pos08(DAT_0108ec68), 
      b70(0), b71(0), b72(0), b73(0), b74(0), b75(0)
{
}
}

// @f3 0x005f4110 (community match, verified in this file)
#include <float.h>
namespace f3m_005f4110 {

struct Scratch {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Scratch();
    ~Scratch();
    float Value();
};

bool FUN_005f3f90(int a1, int a2, Scratch* out, int zero, float f, int a4, int a5);

// pdb: Pathing::ComputeTeleportDoorPathLength | Pathfind.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aOrigin, aDestination, aMaxDist, apActorLockData, aeDoorLockDisp
float FUN_005f4110(int a1, int a2, float f, int a4, int a5)
{
    Scratch s;
    if (FUN_005f3f90(a1, a2, &s, 0, f, a4, a5)) {
        float r = s.Value();
        return r;
    }
    return FLT_MAX;
}
}   // namespace f3m_005f4110

// @f3 0x005e9a60 (community match, verified in this file)
namespace f3m_005e9a60 {
namespace f3m_005e9a60 {
struct Deletable { virtual void Delete(int flag); };
struct Mgr {
    void FUN_00bce350(void* p);
    void FUN_00bce370(void* p);
};
Mgr* FUN_00bce1f0();
struct Obj {
    char unk00[0xbc];
    Deletable* unkBC;
    Deletable* unkC0;
    char unkC4[4];
    void FUN_005e8d50();
    void FUN_005e9a60();
};
// pdb: NavMeshObstacleManager::Release | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
void Obj::FUN_005e9a60() {
    FUN_005e8d50();
    if (unkBC) { unkBC->Delete(1); unkBC = 0; }
    if (unkC0) { unkC0->Delete(1); unkC0 = 0; }
    FUN_00bce1f0()->FUN_00bce350(unkC4);
    FUN_00bce1f0()->FUN_00bce370(unkC4);
}
}
}   // namespace f3m_005e9a60

// @f3 0x005f3610 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005f3610 {
struct Entry1176 { void* vtable; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; void Reset(){vtable=&DAT_00dc4dc0;} };
inline void DestroyEntries1176(Entry1176* first,unsigned int count) {
 while(count>0) { first->Reset(); ++first; --count; }
}
struct Array1176 { int unk00; Entry1176* data04; unsigned int size08,last0C; void FUN_005f24e0(unsigned int,unsigned int); void FUN_005f3610(unsigned int); };
// pdb: BSSimpleArray<PathingCoverLocation,1024>::SetReservedSize | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiReserveSize
void Array1176::FUN_005f3610(unsigned int index) {
 if(index!=last0C) {
  if(index<size08) { DestroyEntries1176(data04+index,size08-index); size08=index; }
  FUN_005f24e0(index,size08);
  last0C=index;
 }
}
}   // namespace f3m_005f3610

// @f3 0x005f54e0 (community match, verified in this file)
namespace f3m_005f54e0 {
// Stand-in for the pathing object: 0x38 bytes, constructed/destroyed by
// external functions; only its size and member-function calls matter here.
class PathBuildObj
{
public:
    PathBuildObj();
    ~PathBuildObj();
    float GetPathLength();

    int unk00;
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
};

bool BuildPathWithDoors(void* apFirst, void* apSecond, PathBuildObj* apPath, int aiFlag, int aiMode);

// pdb: Pathing::ComputeLowPathDistance | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: aStartLocation, aGoalLocation, apReturnDistance
bool FUN_005f54e0(void* apFirst, void* apSecond, float* pfResult)
{
    PathBuildObj o;
    if (BuildPathWithDoors(apFirst, apSecond, &o, 0, 1))
    {
        *pfResult = o.GetPathLength();
        return true;
    }
    else
    {
        *pfResult = 0.0f;
        return false;
    }
}
}   // namespace f3m_005f54e0

// @f3 0x005fd450 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005fd450 {
// FUN_005fd450 -- F3 ctor (thiscall, 1 stack param). Sets vptr, resolves a provider pointer,
// calls the object's vtable slot 0x1f4 and passes the result to this->PathingLocation_SetupData.


extern void* DAT_0107a0d8;   // global object pointer
extern void* DAT_0107a104;   // global object pointer

struct PV;
struct Mgr { int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30; void* m_34;int FUN_00b35640(); };

struct PV {
    virtual void u000();
    virtual void u001();
    virtual void u002();
    virtual void u003();
    virtual void u004();
    virtual void u005();
    virtual void u006();
    virtual void u007();
    virtual void u008();
    virtual void u009();
    virtual void u010();
    virtual void u011();
    virtual void u012();
    virtual void u013();
    virtual void u014();
    virtual void u015();
    virtual void u016();
    virtual void u017();
    virtual void u018();
    virtual void u019();
    virtual void u020();
    virtual void u021();
    virtual void u022();
    virtual void u023();
    virtual void u024();
    virtual void u025();
    virtual void u026();
    virtual void u027();
    virtual void u028();
    virtual void u029();
    virtual void u030();
    virtual void u031();
    virtual void u032();
    virtual void u033();
    virtual void u034();
    virtual void u035();
    virtual void u036();
    virtual void u037();
    virtual void u038();
    virtual void u039();
    virtual void u040();
    virtual void u041();
    virtual void u042();
    virtual void u043();
    virtual void u044();
    virtual void u045();
    virtual void u046();
    virtual void u047();
    virtual void u048();
    virtual void u049();
    virtual void u050();
    virtual void u051();
    virtual void u052();
    virtual void u053();
    virtual void u054();
    virtual void u055();
    virtual void u056();
    virtual void u057();
    virtual void u058();
    virtual void u059();
    virtual void u060();
    virtual void u061();
    virtual void u062();
    virtual void u063();
    virtual void u064();
    virtual void u065();
    virtual void u066();
    virtual void u067();
    virtual void u068();
    virtual void u069();
    virtual void u070();
    virtual void u071();
    virtual void u072();
    virtual void u073();
    virtual void u074();
    virtual void u075();
    virtual void u076();
    virtual void u077();
    virtual void u078();
    virtual void u079();
    virtual void u080();
    virtual void u081();
    virtual void u082();
    virtual void u083();
    virtual void u084();
    virtual void u085();
    virtual void u086();
    virtual void u087();
    virtual void u088();
    virtual void u089();
    virtual void u090();
    virtual void u091();
    virtual void u092();
    virtual void u093();
    virtual void u094();
    virtual void u095();
    virtual void u096();
    virtual void u097();
    virtual void u098();
    virtual void u099();
    virtual void u100();
    virtual void u101();
    virtual void u102();
    virtual void u103();
    virtual void u104();
    virtual void u105();
    virtual void u106();
    virtual void u107();
    virtual void u108();
    virtual void u109();
    virtual void u110();
    virtual void u111();
    virtual void u112();
    virtual void u113();
    virtual void u114();
    virtual void u115();
    virtual void u116();
    virtual void u117();
    virtual void u118();
    virtual void u119();
    virtual void u120();
    virtual void u121();
    virtual void u122();
    virtual void u123();
    virtual void u124();
    virtual void* v125(void* apArg);
    int unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38;
    void* m_3c;                       // 0x3c
    int FUN_004e8880();               // thiscall, no stack args
};

class FUN_005fd450_cls
{
public:
    virtual void unk00();
    FUN_005fd450_cls(PV* apObj);
    void PathingLocation_SetupData(void* apArg,int k);   // thiscall, 1 stack arg
};

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0721_retail, call_seq, low
// pdb params: apRef
FUN_005fd450_cls::FUN_005fd450_cls(PV* apObj)
{
    *(void**)this=&DAT_00dc4dc0;
    void* v = apObj->m_3c;
    int   k = apObj->FUN_004e8880();
    if (v == 0)
    {
        if (k == 0)
        {
            if ((void*)apObj == DAT_0107a104)
            {
                v = ((Mgr*)DAT_0107a0d8)->m_34;
                if (v == 0)
                    k=((Mgr*)DAT_0107a0d8)->FUN_00b35640();
            }
        }
    }
    PathingLocation_SetupData(apObj->v125(v),k);
}
}   // namespace f3m_005fd450

// @f3 0x005fc770 (community match, verified in this file)
namespace f3m_005fc770 {
struct Routine_005fc770{unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned short value024;void FUN_005fc770();};
// pdb: PathingLocation::ClearTriangleData | PathingLocation.obj | fnv360_0822_retail, call_gap, medium
void Routine_005fc770::FUN_005fc770(){value024=65535;}
}   // namespace f3m_005fc770

// @f3 0x005e9570 (community match, verified in this file)
struct FUN_005e9570_Mgr {
    void FUN_0086ba60(void* p);
};
extern FUN_005e9570_Mgr DAT_01090a78;

struct FUN_005e9570_Base {
    virtual ~FUN_005e9570_Base() {}
};

struct FUN_005e9570 : FUN_005e9570_Base {
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
    void FUN_005e8c20(int flag);
    virtual ~FUN_005e9570();
};

// pdb: LockFreeQueue<bhkRigidBody *>::~LockFreeQueue<bhkRigidBody *> | NavMeshObstacleManager.obj | fnv360_0822_debug, call_seq, low, conflict (bridge: LockFreeQueue<bhkRigidBody *>::RemoveAll)
FUN_005e9570::~FUN_005e9570()
{
    FUN_005e8c20(1);
    void* volatile p = unk10;
    void* q = p;
    DAT_01090a78.FUN_0086ba60(q);
}

// @f3 0x005e5500 (community match, verified in this file)
namespace f3m_005e5500 {
struct Sub120 {
    int unk00;
    int unk04;
    void FUN_0049fac0(const unsigned int& value);
};

struct Owner5500 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC;
    int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; int unkE4; int unkE8; int unkEC;
    int unkF0; int unkF4; int unkF8; int unkFC;
    int unk100; int unk104; int unk108; int unk10C;
    int unk110; int unk114; int unk118; int unk11C;
    Sub120 sub120;
    Sub120 sub128;
    void FUN_005e5500(unsigned int value);
};

// pdb: NavMeshObstacleManager::EnableNavMesh | NavMeshObstacleManager.obj | fnv360_0721_beta, objrun, medium
// pdb params: aiNavMeshID
void Owner5500::FUN_005e5500(unsigned int value)
{
    sub120.FUN_0049fac0(value);
}
}   // namespace f3m_005e5500

// @f3 0x005e4c80 (community match, verified in this file)
namespace f3m_005e4c80 {
struct Ref4C80
{
    virtual void d000();
    virtual void DeleteThis();
    long refCount04;
};

struct Mgr4C80
{
    virtual void u000();
    virtual void u001();
    virtual void u002();
    virtual void u003();
    virtual void u004();
    virtual void u005();
    virtual void u006();
    virtual void u007();
    virtual void u008();
    virtual void u009();
    virtual void u010();
    virtual void u011();
    virtual void u012();
    virtual void u013();
    virtual void u014();
    virtual void u015();
    virtual void u016();
    virtual void u017();
    virtual void u018();
    virtual void u019();
    virtual void u020();
    virtual void u021();
    virtual void u022();
    virtual void u023();
    virtual void u024();
    virtual void u025();
    virtual void u026();
    virtual void u027();
    virtual void u028();
    virtual void u029();
    virtual void u030();
    virtual void u031();
    virtual void u032();
    virtual void u033();
    virtual void u034();
    virtual void u035();
    virtual void u036();
    virtual void u037();
    virtual void u038();
    virtual void u039();
    virtual void u040();
    virtual void u041();
    virtual void u042();
    virtual void u043();
    virtual void u044();
    virtual void u045();
    virtual void u046();
    virtual void u047();
    virtual void u048();
    virtual void u049();
    virtual void u050();
    virtual void u051();
    virtual void u052();
    virtual void u053();
    virtual void u054();
    virtual void u055();
    virtual void u056();
    virtual void u057();
    virtual void u058(void* arg);
};

struct Obj4C80
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84;
    Ref4C80* unk88;
};

struct Arg4C80
{
    Obj4C80* unk00;
};

struct Owner4C80
{
int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    Mgr4C80* unk13C;
    void FUN_005e4c80(Arg4C80* arg);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

void Owner4C80::FUN_005e4c80(Arg4C80* arg)
{
    Mgr4C80* mgr = unk13C;
    if (!mgr)
        return;
    Ref4C80* ref = arg->unk00->unk88;
    if (!ref)
        return;
    mgr->u058(ref);
    Ref4C80*& slot = arg->unk00->unk88;
    Ref4C80* cur = slot;
    if (cur)
    {
        if (InterlockedDecrement(&cur->refCount04) == 0)
            cur->DeleteThis();
        slot = 0;
    }
}
}   // namespace f3m_005e4c80

// @f3 0x005fd6d0 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005fd6d0 {

namespace f3m_005fd6d0 {

struct PVRef {
    int unk00;
    int unk04;
    int unk08;
    int m_0C;
    bool FUN_004c0d50(void** apArg0, void** apArg1);
};

class FUN_005fd6d0 {
public:
    virtual ~FUN_005fd6d0();
    void PathingLocation_SetupData(void* apKey, unsigned int first, unsigned int second);
    FUN_005fd6d0(PVRef* apObj);
};

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, low
// pdb params: aWorldLocation
FUN_005fd6d0::FUN_005fd6d0(PVRef* apObj)
{
    unsigned int first = 0;
    unsigned int second = 0;
    apObj->FUN_004c0d50((void**)&first, (void**)&second);
    PathingLocation_SetupData(apObj, first, second);
}

}
}   // namespace f3m_005fd6d0

// @f3 0x005ebf90 (community match, verified in this file)
inline void* operator new(unsigned int, void* where) { return where; }
inline void operator delete(void*, void*) {}

class FUN_00610140
{
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    FUN_00610140(int arg);
};

struct Arr005ebf90
{
    void* vptr;
    FUN_00610140* data;
    unsigned int size;
    unsigned int capacity;
    int FUN_005eb230();
};

struct Owner005ebf90
{
    int unk00;
    int unk04;
    Arr005ebf90 arr08;
    int FUN_005ebf90(int arg);
};

int Owner005ebf90::FUN_005ebf90(int arg)
{
    int index = arr08.FUN_005eb230();
    FUN_00610140* elem = &arr08.data[index];
    new (elem) FUN_00610140(arg);
    return index;
}

// @f3 0x005e47c0 (community match, verified in this file)
namespace f3m_005e47c0 {

struct FUN_005e47c0_Elem {
    bool FUN_005ea710();
};

struct FUN_005e47c0_Owner {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; int unkE4; int unkE8;
    FUN_005e47c0_Elem** unkEC;
    unsigned int unkF0;
    bool FUN_005e47c0();
};

// pdb: NavMeshObstacleManager::SwapNavmeshes | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool FUN_005e47c0_Owner::FUN_005e47c0() {
    bool result = false;
    unsigned int count = unkF0;
    for (unsigned int i = 0; i < count; i++) {
        FUN_005e47c0_Elem* e = unkEC[i];
        if (e->FUN_005ea710())
            result = true;
    }
    return result;
}
}   // namespace f3m_005e47c0

// @f3 0x005e7750 (community match, verified in this file)
class MemoryManager
{
public:
    void Deallocate(void* pointer);
};

extern MemoryManager g_memoryManager;

extern int (__stdcall* const DAT_00d9b07c)(unsigned long dwTlsIndex);

struct EntryNode
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int count0C;
    void FUN_005e53b0();
};

struct Entry
{
    int unk00;
    EntryNode* unk04;
};

struct Slot
{
    EntryNode* p;
};

class Owner
{
public:
    void FUN_005e7750();
    unsigned int count00;
    unsigned int tlsIndex04;
    Entry* data08;
};

// pdb: ThreadSpecificInterfaceManager<LockFreeQueue<bhkRigidBody *>::LockFreeQueueInterface>::~ThreadSpecificInterfaceManager<LockFreeQueue<bhkRigidBody *>::LockFreeQueueInterface> | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_005e7750()
{
    for (unsigned int i = 0; i < count00; ++i)
    {
        volatile Slot a;
        a.p = data08[i].unk04;
        volatile Slot b;
        b.p = a.p;
        if (b.p)
        {
            EntryNode* node = b.p;
            while (node->count0C)
                node->FUN_005e53b0();
            g_memoryManager.Deallocate(node);
        }
    }
    g_memoryManager.Deallocate(data08);
    DAT_00d9b07c(tlsIndex04);
}

// @f3 0x005eb230 (community match, verified in this file)
namespace f3m_005eb230 {
struct Elem30 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
};

struct Arr30 {
    virtual void unk00();
    virtual void* unk04(unsigned int n);
    Elem30* data;
    unsigned int count;
    unsigned int cap;
    int FUN_005eb230();
    int FUN_005eb040(unsigned int ncap, unsigned int count);
};

// pdb: BSSimpleArray<VirtualPathingNode,1024>::AddUninitialized | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
int Arr30::FUN_005eb230()
{
    if (count == cap) {
        if (cap == 0) {
            data = (Elem30*)unk04(4);
            cap = 4;
            count++;
            return count - 1;
        }
        unsigned int ncap = cap > 0x400 ? cap + 0x400 : cap * 2;
        FUN_005eb040(ncap, count);
        cap = ncap;
    }
    count++;
    return count - 1;
}
}   // namespace f3m_005eb230

// @f3 0x005ebdf0 (community match, verified in this file)
namespace f3m_005ebdf0 {
// FUN_005ebdf0 -- resizing a dynamic array of 0x28-byte elements
// (this in ecx: unk04 = data, unk08 = size, unk0C = capacity,
//  the vtable's slot 1 allocates a new buffer).

struct Elem40 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct ArrayCls {
    virtual ~ArrayCls();                                    // vtable +0
    virtual Elem40* Alloc(unsigned int count);              // vtable +4
    virtual void Free(Elem40* data);                        // vtable +8
    virtual Elem40* Realloc(unsigned int count, Elem40* data); // vtable +0xC

    Elem40* unk04;
    unsigned int unk08;
    unsigned int unk0C;

    void FUN_005d0d10(Elem40* first, unsigned int count);
    void FUN_005d0d40(bool flag);
    void FUN_005eb0e0(unsigned int count, unsigned int size);
    void FUN_005ebdf0(unsigned int index, bool flag);
};

// pdb: BSSimpleArray<PathingLocation,1024>::SetSize | PathBuilder.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiNewSize, abFreeMemory
void ArrayCls::FUN_005ebdf0(unsigned int index, bool flag)
{
    if (index == 0)
    {
        FUN_005d0d40(flag);
        return;
    }

    if (index > unk0C)
    {
        if (unk0C == 0)
            unk04 = Alloc(index);
        else
            FUN_005eb0e0(index, unk08);

        unk0C = index;
        ((FUN_005ecde0_Owner*)this)->FUN_005eaa60((FUN_005ecde0_Elem*)(unk04 + unk08), index - unk08);
        unk08 = index;
    }
    else if (index < unk08)
    {
        FUN_005d0d10(unk04 + index, unk08 - index);
        unk08 = index;
        if (flag)
        {
            if (index <= (unk0C >> 2))
            {
                FUN_005eb0e0(index, index);
                unk0C = index;
            }
        }
    }
    else
    {
        ((FUN_005ecde0_Owner*)this)->FUN_005eaa60((FUN_005ecde0_Elem*)(unk04 + unk08), index - unk08);
        unk08 = index;
    }
}
}   // namespace f3m_005ebdf0

// @f3 0x005eb150 (community match, verified in this file)
namespace f3m_005eb150 {

struct Elem18 { int d00, d04, d08, d0C, d10, d14; };

struct Container {
    virtual void vfn00();
    virtual Elem18* vfn04(int a1);
    virtual void vfn08(Elem18* p);
    virtual Elem18* vfn0C(Elem18* p, int a1);
    void FUN_005eabd0(Elem18* dst, Elem18* src, int count);
    Elem18* m04;
    int m08;
    int m0C;
    void FUN_005eb150(int a1, int a2);
};

// pdb: BSSimpleArray<NavMeshEdgeLocation,1024>::_ReallocateBuffer | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiNewSize, aiCopyCount
void Container::FUN_005eb150(int a1, int a2)
{
    if (m04 != 0) {
        if (a2 == m0C) {
            m04 = vfn0C(m04, a1);
        } else {
            Elem18* p = vfn04(a1);
            FUN_005eabd0(p, m04, a2);
            vfn08(m04);
            m04 = p;
        }
    } else {
        m04 = vfn04(a1);
        m0C = a1;
    }
}
}   // namespace f3m_005eb150

// @f3 0x005f7ae0 (community match, verified in this file)
namespace f3m_005f7ae0 {

extern int FUN_005f69c0(int a1, int a2, int a3, int a4, int a5);

// pdb: Pathing::CanCreatePath | Pathfind.obj | fnv360_0721_retail, call_seq, medium
// pdb params: aStartLocation, aGoalLocation, apAvoidNodeArray
void FUN_005f7ae0(int a1, int a2, int a3)
{
    FUN_005f69c0(a1, a2, a3, 0, 0);
}
}   // namespace f3m_005f7ae0

// @f3 0x005fcba0 (community match, verified in this file)
namespace f3m_005fcba0 {
struct Point5fcba0 { float x,y,z; };
int __cdecl FUN_00501250(Point5fcba0*);
struct Owner5fcba0 {
 int unk00; Point5fcba0 position; int unk10; int unk14; int unk18; void* unk1C; int unk20; unsigned short unk24;
 void PathingLocation_SetupData(const Point5fcba0*, int, void*);
 void FUN_005fcba0(const Point5fcba0*);
};
// pdb: PathingLocation::SetLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation
void Owner5fcba0::FUN_005fcba0(const Point5fcba0* point) {
 position=*point;
 unk24=0xffff;
 if(unk1C && FUN_00501250(&position)!=unk20)
  PathingLocation_SetupData(point,0,unk1C);
}
}   // namespace f3m_005fcba0

// @f3 0x005fc780 (community match, verified in this file)
namespace f3m_005fc780 {
namespace match5fc780 {
struct Vector5fc780 {
 float x,y,z;
 Vector5fc780(float a,float b,float c):x(a),y(b),z(c) {}
 Vector5fc780 operator-(const Vector5fc780& b) const {return Vector5fc780(x-b.x,y-b.y,z-b.z);}
 float squared() const {return x*x+y*y+z*z;}
};
struct Location5fc780 {
 int unk00; Vector5fc780 position; int unk10; int unk14; int unk18; int unk1C; int unk20;
 bool FUN_005fc780(Location5fc780*,float);
};
// pdb: PathingLocation::IsCloseTo | PathingLocation.obj | fnv360_0822_retail, call_gap, low
// pdb params: aOtherLoc, afTolerance
bool Location5fc780::FUN_005fc780(Location5fc780* other,float radius) {
 if(other->unk1C!=unk1C) return false;
 if(unk1C) { if(other->unk20!=unk20) return false; }
 else {if(other->unk18!=unk18) return false;}
 Vector5fc780 delta=other->position-position;
 float distance=delta.squared();
 if(distance>radius*radius) return false;
 return true;
}
}
}   // namespace f3m_005fc780

// @f3 0x005eb0e0 (community match, verified in this file)
namespace f3m_005eb0e0 {
namespace match5eb0e0 {
struct Buffer5eb0e0;
struct VTable5eb0e0 {
 void* unk00;
 void* (__thiscall *allocate)(Buffer5eb0e0*,unsigned);
 void (__thiscall *free)(Buffer5eb0e0*,void*);
 void* (__thiscall *resize)(Buffer5eb0e0*,void*,unsigned);
};
struct Buffer5eb0e0 {
 VTable5eb0e0* vtable; void* data; unsigned unk08; unsigned count;
 void FUN_005eab60(void*,void*,unsigned);
 void FUN_005eb0e0(unsigned,unsigned);
};
// pdb: BSSimpleArray<PathingLocation,1024>::AddUninitialized | PathBuilder.obj | fnv360_0822_retail, call_seq, low
void Buffer5eb0e0::FUN_005eb0e0(unsigned size,unsigned oldCount) {
 if(data) {
  if(oldCount==count) data=vtable->resize(this,data,size);
  else {
   void* replacement=vtable->allocate(this,size);
   FUN_005eab60(replacement,data,oldCount);
   vtable->free(this,data);
   data=replacement;
  }
 } else {
  data=vtable->allocate(this,size);
  count=size;
 }
}
}
}   // namespace f3m_005eb0e0

// @f3 0x005fc720 (community match, verified in this file)
namespace f3m_005fc720 {
// pdb: PathingLocation::SetTriangleIndex | PathingLocation.obj | fnv360_0822_retail, callee_sim, low
// pdb params: aiTriIndex
struct Owner1429{unsigned int unk00;unsigned int unk04;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C;unsigned int unk20;unsigned short value24;void FUN_005fc720(unsigned short);};void Owner1429::FUN_005fc720(unsigned short value){value24=value;}
}   // namespace f3m_005fc720

// @f3 0x005f39f0 (community match, verified in this file)
extern void* DAT_00e020b0[];
namespace f3m_005f39f0 {
extern void (__stdcall* DAT_00e020b8)(void*);
struct CodexDeleteHeap { void FUN_0086ba60(void*); };
struct CodexDeleteArray {
    void** vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    CodexDeleteArray* FUN_005f39f0(unsigned);
};
// pdb: BSSimpleArray<FastNavMeshEdgeLocationProxy,1024>::`scalar deleting destructor' | Pathfind.obj | fnv360_0822_retail, vtable, medium
CodexDeleteArray* CodexDeleteArray::FUN_005f39f0(unsigned flags) {
    vtable = DAT_00e020b0;
    if (data) {
        DAT_00e020b8(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
    if (flags & 1) DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}   // namespace f3m_005f39f0

// @f3 0x005e0000 (community match, verified in this file)
extern int DAT_00e01ad8;
namespace f3m_005e0000 {
extern void (__stdcall *DAT_00e01ae0)(void*);
struct Cleanup5e0000 {
 void* unk00; void* unk04; int unk08; int unk0C;
 void FUN_005e0000();
};
void Cleanup5e0000::FUN_005e0000() {
 unk00=&DAT_00e01ad8;
 if(unk04) { DAT_00e01ae0(unk04); unk04=0; unk0C=0; unk08=0; }
}

}   // namespace f3m_005e0000

// @f3 0x005ec150 (community match, verified in this file)
namespace f3m_005ec150 {
struct Target1450 { void FUN_005ec100(); };
struct Owner1450
{
    unsigned int unk00;
    Target1450* target04;
    int FUN_005ec150();
};
// pdb: PathBuilder::UpdatePathMoveToLow | PathBuilder.obj | fnv360_0721_beta, call_gap, low
int Owner1450::FUN_005ec150()
{
    target04->FUN_005ec100();
    return 1;
}
}   // namespace f3m_005ec150

// @f3 0x005ffb40 (community match, verified in this file)
namespace f3m_005ffb40 {
struct Loc14
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Loc14();
    ~Loc14();
};

struct Sub1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    void FUN_005fc480(unsigned int aArg);
};

struct Sub4c
{
    int unk00;
    void FUN_0086cc50();
    void FUN_0086cde0();
};

unsigned char __cdecl FUN_005f7cc0(void* aP, float aF, Loc14* aOut);

struct FUN_005ffb40_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Sub1c m_1c;
    float m_44;
    int unk48;
    Sub4c m_4c;
    void FUN_005ff620(Loc14* aOut);
    void FUN_005ffb40(unsigned int aArg, float aF);
};

// pdb: PathingLOSGridMap::Initialize | PathingLOSGridMap.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCenter, afRadius
void FUN_005ffb40_cls::FUN_005ffb40(unsigned int aArg, float aF)
{
    m_4c.FUN_0086cc50();
    m_1c.FUN_005fc480(aArg);
    m_44 = aF;
    Loc14 locResult;
    if (FUN_005f7cc0(&m_1c, aF, &locResult) != 0)
    {
        FUN_005ff620(&locResult);
    }
    else
    {
        m_44 = 0.0f;
    }
    m_4c.FUN_0086cde0();
}

}   // namespace f3m_005ffb40

// @f3 0x005fcbf0 (community match, verified in this file)
namespace f3m_005fcbf0 {
struct Link5f {int unk00; void** unk04;};
struct Owner5f {int unk00,unk04,unk08,unk0C; void* unk10; Link5f* unk14; int unk18,unk1C,unk20; unsigned short unk24; unsigned char unk26; void* FUN_005fcbf0();};
// pdb: PathingLocation::GetBestNavMeshInfo | PathingLocation.obj | fnv360_0822_retail, call_gap, medium
void* Owner5f::FUN_005fcbf0(){if(unk10)return unk10;if(unk14 && (unk26&1))return *unk14->unk04;return 0;}
}   // namespace f3m_005fcbf0

// @f3 0x005e4850 (community match, verified in this file)
namespace f3m_005e4850 {
extern void __cdecl FUN_005bb300(void*,int);
struct Node4850 { void* value; Node4850* next; };
struct List4850 { Node4850 head; Node4850* Head() { return &head; } void FUN_006c8220(); };
struct Owner4850 {
int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124;
List4850 list; bool FUN_005e4850(); };
// pdb: NavMeshObstacleManager::ProcessDisabledNavMeshes | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool Owner4850::FUN_005e4850() { for(Node4850* node=list.Head(); node; node=node->next) { if(!node->next && !node->value) break; FUN_005bb300(node->value,1); } list.FUN_006c8220(); return true; }
}   // namespace f3m_005e4850

// @f3 0x005e5520 (community match, verified in this file)
namespace f3m_005e5520 {
struct Component1476 { void FUN_0049fac0(const unsigned int*); };
struct Owner1476
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    Component1476 component;
    void FUN_005e5520(unsigned int value);
};
// pdb: NavMeshObstacleManager::DisableNavMesh | NavMeshObstacleManager.obj | fnv360_0721_beta, objrun, medium
// pdb params: aiNavMeshID
void Owner1476::FUN_005e5520(unsigned int value)
{
    component.FUN_0049fac0(&value);
}
}   // namespace f3m_005e5520

// @f3 0x005f2450 (community match, verified in this file)
namespace Allocation1492
{
    struct Heap { void* FUN_0086b930(unsigned int); };
    extern Heap DAT_01090a78;
}
struct Allocator1492 { void* FUN_005f2450(unsigned int); };
// pdb: BSSimpleArray<PathingCoverLocation,1024>::_Allocate | Pathfind.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiSizeInItem
void* Allocator1492::FUN_005f2450(unsigned int count)
{
    return Allocation1492::DAT_01090a78.FUN_0086b930(count*84);
}

// @f3 0x005f2470 (community match, verified in this file)
namespace Allocation1493
{
    struct Heap { void* FUN_0086bae0(void*,unsigned int); };
    extern Heap DAT_01090a78;
}
struct Allocator1493 { void* FUN_005f2470(void*,unsigned int); };
// pdb: BSSimpleArray<PathingCoverLocation,1024>::_Reallocate | Pathfind.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* Allocator1493::FUN_005f2470(void* memory,unsigned int count)
{
    return Allocation1493::DAT_01090a78.FUN_0086bae0(memory,count*84);
}

// @f3 0x005f2490 (community match, verified in this file)
namespace Allocation1494
{
    struct Heap { void* FUN_0086bae0(void*,unsigned int); };
    extern Heap DAT_01090a78;
}
struct Allocator1494 { void* FUN_005f2490(void*,unsigned int); };
// pdb: BSSimpleArray<BGSDistantTreeBlock::InstanceData,1024>::_Reallocate | BGSDistantTreeBlock.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* Allocator1494::FUN_005f2490(void* memory,unsigned int count)
{
    return Allocation1494::DAT_01090a78.FUN_0086bae0(memory,count*32);
}

// @f3 0x005fff60 (community match, verified in this file)
namespace f3m_005fff60 {
struct Map1495 { bool FUN_00bea7b0(unsigned int,unsigned int&); };
struct Owner1495
{
    unsigned int unk00,unk04;
    Map1495 map08;
    bool FUN_005fff60(unsigned int);
};
// pdb: PathingLOSMap::IsNavMeshInMap | PathingLOSMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiNavMeshID
bool Owner1495::FUN_005fff60(unsigned int key)
{
    return map08.FUN_00bea7b0(key,key);
}
}   // namespace f3m_005fff60

// @f3 0x005fc040 (community match, verified in this file)
namespace f3m_005fc040 {
struct Stream5fc040 { void FUN_006e1830(void*,unsigned,int); };
struct State5fc040 {
 int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20;
 void FUN_005fc040(Stream5fc040*);
};
// pdb: PathingAvoidNode::SaveGame | PathingAvoidNode.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apSaveGameBuffer
void State5fc040::FUN_005fc040(Stream5fc040* stream) {
 unsigned char kind=(unsigned char)unk20;
 stream->FUN_006e1830(&kind,1,0);
 stream->FUN_006e1830(&unk18,4,0);
 stream->FUN_006e1830(&unk1C,4,0);
 stream->FUN_006e1830(this,12,0);
 if(unk20==1) stream->FUN_006e1830(&unk0C,12,0);
}
}   // namespace f3m_005fc040

// @f3 0x005ec420 (community match, verified in this file)
extern void* DAT_00e01ec4[];
namespace f3m_005ec420 {
struct Entry5EC {
 int unk00; float unk04; float unk08; float unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; short unk24; char unk26; char unk27;
 void FUN_005fc3f0();
 Entry5EC() { FUN_005fc3f0(); }
 ~Entry5EC();
};
struct FUN_005ec420 {
 int unk00; int unk04; Entry5EC first; Entry5EC second; void** vtable58; int unk5C; int unk60; int unk64;
 FUN_005ec420();
};
// pdb: RayCastPathRequest::RayCastPathRequest | PathBuilder.obj | fnv360_0822_retail, call_gap, low
FUN_005ec420::FUN_005ec420() { vtable58=DAT_00e01ec4; unk5C=0; unk60=0; unk64=0; }
}   // namespace f3m_005ec420

// @f3 0x005e0250 (community match, verified in this file)
extern void* DAT_00e01ac4[];
namespace f3m_005e0250 {
extern void (__stdcall *DAT_00e01acc)(void*);
struct Heap5E02 { void FUN_0086ba60(void*); };
struct Array5E02 { void** vtable; void* buffer; unsigned size; unsigned capacity; void* FUN_005e0250(unsigned); };
// pdb: BSSimpleArray<NavMeshObstacleVertex *,1024>::`scalar deleting destructor' | NavMeshObstacleCutter.obj | fnv360_0822_retail, vtable, medium
void* Array5E02::FUN_005e0250(unsigned flags) {
 vtable=DAT_00e01ac4;
 if(buffer) { DAT_00e01acc(buffer); buffer=0; capacity=0; size=0; }
 if(flags&1) DAT_01090a78.FUN_0086ba60(this);
 return this;
}
}   // namespace f3m_005e0250

// @f3 0x005eb2f0 (community match, verified in this file)
namespace f3m_005eb2f0 {
struct Element5eb2 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; void FUN_00600960();};
struct Array5eb2;typedef Element5eb2* (__thiscall *Allocate5eb2)(Array5eb2*,unsigned);typedef void (__thiscall *Free5eb2)(Array5eb2*,Element5eb2*);struct Table5eb2 {int unk00;Allocate5eb2 unk04;Free5eb2 unk08;};
struct Array5eb2 {Table5eb2* unk00;Element5eb2* unk04;unsigned unk08,unk0C;void FUN_005c44f0(Element5eb2*,Element5eb2*,unsigned);void FUN_005eb2f0(unsigned,bool);};
// pdb: BSSimpleArray<PathingNode,1024>::Remove | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiIndex, abShrink
void Array5eb2::FUN_005eb2f0(unsigned index,bool shrink){if(shrink){if(unk0C>0x400){if(unk08<=unk0C-0x800)goto resize;}else if(unk08<=unk0C/4)goto resize;} {unk04[index].FUN_00600960();FUN_005c44f0(unk04+index,unk04+index+1,unk08-index-1);--unk08;return;}resize: unsigned capacity=unk0C>0x800?unk0C-0x400:unk0C/2;Element5eb2* storage=unk00->unk04(this,capacity);FUN_005c44f0(storage,unk04,index);unk04[index].FUN_00600960();FUN_005c44f0(storage+index,unk04+index+1,unk08-1);unk00->unk08(this,unk04);--unk08;unk04=storage;unk0C=capacity;}
}   // namespace f3m_005eb2f0

// @f3 0x005eb7e0 (community match, verified in this file)
extern unsigned int DAT_00e27ed4;
namespace f3m_005eb7e0 {
struct Heap1500 { void* ScrapHeap_Allocate(unsigned int,unsigned int); };
struct Owner1500
{
    unsigned int unk00,unk04,unk08,unk0C;
    Heap1500* heap10;
    void* FUN_005eb7e0(unsigned int);
};
// pdb: BSScrapArray<bool,1024>::_Allocate | PathBuilder.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiSizeInItem
void* Owner1500::FUN_005eb7e0(unsigned int bytes)
{
    return heap10->ScrapHeap_Allocate(bytes,DAT_00e27ed4);
}
}   // namespace f3m_005eb7e0

// @f3 0x005eb0b0 (community match, verified in this file)
namespace f3m_005eb0b0 {
namespace match5eb0b0 {
struct Item5eb0b0 {
 int unk00;
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
 int unk28;
 int unk2C;
 int unk30;
 int unk34;
 int unk38;
 void FUN_00600960();
};
// pdb: BSSimpleArray<PathingNode,1024>::_DestructItems | PathBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apFirstAddr, aiCount
void __stdcall FUN_005eb0b0(Item5eb0b0* items,unsigned count) {
 while(count>0) {items->FUN_00600960();++items;--count;}
}
}
}   // namespace f3m_005eb0b0

// @f3 0x005fc4d0 (community match, verified in this file)
namespace match5fc4d0 {
extern void* DAT_00dc4dc0;extern void* DAT_00f47a58;extern void* DAT_00f47a3c;extern void* DAT_00f46078;
void* TESForm_GetFormByNumericID(unsigned);
void* FUN_00c0050a(void*,int,void*,void*,int);
struct Vector5fc4d0 {float x,y,z;};
struct Source5fc4d0 {int unk00;unsigned lookupID;int unk08;unsigned id;int unk10;int unk14;int unk18;void* form;void* Get(){return form?form:TESForm_GetFormByNumericID(lookupID);}};
struct Owner5fc4d0 {
 void* vtable;Vector5fc4d0 position;Source5fc4d0* source;unsigned unk14;void* first;void* second;unsigned id;unsigned short index;unsigned char flags;
 Owner5fc4d0* FUN_005fc4d0(Vector5fc4d0*,Source5fc4d0*);
};
// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation, apNavMeshInfo
Owner5fc4d0* Owner5fc4d0::FUN_005fc4d0(Vector5fc4d0* point,Source5fc4d0* value) {
 vtable=&DAT_00dc4dc0;position=*point;flags=0;source=value;unk14=0;
 second=FUN_00c0050a(value->Get(),0,&DAT_00f46078,&DAT_00f47a58,0);
 if(second) {first=0;id=value->id;}
 else {first=FUN_00c0050a(value->Get(),0,&DAT_00f46078,&DAT_00f47a3c,0);id=0xdeaddead;}
 flags|=1;index=0xffff;
 return this;
}
}

// @f3 0x005fc8f0 (community match, verified in this file)
namespace f3m_005fc8f0 {
// 0x005fc8f0 - __thiscall, two stack arguments (ret 8).
// Guards on this->unk10, this->unk24 and bit 4 of unk10->unk08, then hands
// unk10->unk54 to the unnamed reference-assigner and reports whether the
// caller's slot ended up non-null, copying this->unk24 out through arg 2.

struct Entry5fc8f0
{
    int unk00;
    int unk04;
    unsigned int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    void* unk54;
};

void FUN_005b87d0(void** apDest, void* apSource);

struct Holder5fc8f0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Entry5fc8f0* unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short unk24;
    bool FUN_005fc8f0(void** apOut, unsigned short* apIndex);
};

// pdb: PathingLocation::GetNavMeshAndTriangle | PathingLocation.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aRetNavMesh, aRetTriangle
bool Holder5fc8f0::FUN_005fc8f0(void** apOut, unsigned short* apIndex)
{
    if (!unk10)
        return false;
    if (unk24 == 0xffff)
        return false;
    bool busy = (unk10->unk08 >> 4) & 1;
    if (busy)
        return false;
    FUN_005b87d0(apOut, unk10->unk54);
    bool ok = *apOut != 0;
    if (ok)
    {
        *apIndex = unk24;
        return true;
    }
    return ok;
}
}   // namespace f3m_005fc8f0

// @f3 0x005f2190 (community match, verified in this file)
namespace f3m_005f2190 {
struct Vec5f2190 { int unk00; int unk04; int unk08; };
struct Counter5f2190 { void** table; long refs; void Release() { if(!InterlockedDecrement(&refs)) ((void (__thiscall *)(Counter5f2190*))table[1])(this); } };
struct Resource5f2190 {
 int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; Counter5f2190 counter;
 void IncRefCount() { InterlockedIncrement(&counter.refs); }
 void DecRefCount() { counter.Release(); }
 Vec5f2190 FUN_005bd630(int);
};
struct Subject5f2190 { bool FUN_005fda30(int); bool FUN_005fc8f0(NiPointer<Resource5f2190>*,int*); };
// pdb: Pathing::GetNavmeshNormalForLocation | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: aLocation, aRetNormal
bool __cdecl FUN_005f2190(Subject5f2190* subject,Vec5f2190* out) {
 if(!subject->FUN_005fda30(0)) return false;
 NiPointer<Resource5f2190> resource; int index;
 if(!subject->FUN_005fc8f0(&resource,&index)) return false;
 *out=resource->FUN_005bd630(index);
 return true;
}
}   // namespace f3m_005f2190

// @f3 0x005fc670 (community match, verified in this file)
namespace match5fc670 {
extern void* DAT_00dc4dc0;extern void* DAT_00f47a58;extern void* DAT_00f47a3c;extern void* DAT_00f46078;
void* TESForm_GetFormByNumericID(unsigned);
void* FUN_00c0050a(void*,int,void*,void*,int);
struct Vector5fc670 {float x,y,z;};
struct Source5fc670 {int unk00;unsigned lookupID;int unk08;unsigned id;int unk10;int unk14;int unk18;void* form;void* Get(){return form?form:TESForm_GetFormByNumericID(lookupID);}};
struct Owner5fc670 {
 void* vtable;Vector5fc670 position;Source5fc670* source;unsigned unk14;void* first;void* second;unsigned id;unsigned short index;unsigned char flags;
 void FUN_005fc670(Source5fc670*);
};
// pdb: PathingLocation::SetNavMeshInfo | PathingLocation.obj | fnv360_0822_retail, callee_sim, low
// pdb params: apNavMeshInfo
void Owner5fc670::FUN_005fc670(Source5fc670* value) {
 unk14=0;source=value;
 second=FUN_00c0050a(value->Get(),0,&DAT_00f46078,&DAT_00f47a58,0);
 if(second) {first=0;id=value->id;}
 else {first=FUN_00c0050a(value->Get(),0,&DAT_00f46078,&DAT_00f47a3c,0);id=0xdeaddead;}
 flags|=1;index=0xffff;

}
}

// @f3 0x005f4240 (community match, verified in this file)
namespace f3m_005f4240 {
namespace Destroy4240 {
class PathingLocation { public: virtual void FUN_005fc810(void*); __forceinline ~PathingLocation() {} int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; };
class PathingCoverLocation: public PathingLocation { public: __forceinline ~PathingCoverLocation() {} };
class CoverArray { public: __forceinline virtual ~CoverArray() { Clear(); } virtual PathingCoverLocation* Allocate(unsigned); virtual void Free(PathingCoverLocation*); PathingCoverLocation* data; unsigned count,capacity; __forceinline void Clear() { if(data) { PathingCoverLocation* p=data; for(unsigned remaining=count;remaining>0;++p,--remaining) p->PathingCoverLocation::~PathingCoverLocation(); Free(data); data=0; capacity=0; count=0; } } void FUN_005f4240(); };
// pdb: BSSimpleArray<PathingCoverLocation,1024>::~BSSimpleArray<PathingCoverLocation,1024> | Pathfind.obj | fnv360_0822_debug, call_seq, medium
void CoverArray::FUN_005f4240() { this->CoverArray::~CoverArray(); }
}
}   // namespace f3m_005f4240

// @f3 0x005eb9c0 (community match, verified in this file)
class PathBuilder {public:struct VirtualNodeSegment;};
typedef PathBuilder::VirtualNodeSegment Segment5eb9c0;
extern void (__stdcall* DAT_00e01f1c)(void*);
template<> class BSSimpleArray<Segment5eb9c0,1024>;
typedef BSSimpleArray<Segment5eb9c0,1024> Base5eb9c0;
extern void (__thiscall* DAT_00e01ea4)(Base5eb9c0*,void*);
template<> class BSSimpleArray<Segment5eb9c0,1024> {
public:
 virtual __forceinline ~BSSimpleArray() {if(pBuffer) {DAT_00e01ea4(this,pBuffer);pBuffer=0;capacity=0;size=0;}}
 Segment5eb9c0* pBuffer;unsigned int size;unsigned int capacity;
};
template<class T,unsigned int G> class BSScrapArray;
template<> class BSScrapArray<Segment5eb9c0,1024>:public Base5eb9c0 {
public:
 virtual __forceinline ~BSScrapArray() {if(pBuffer) {DAT_00e01f1c(pBuffer);pBuffer=0;capacity=0;size=0;}}
 void FUN_005eb9c0();
};
// pdb: BSScrapArray<PathBuilder::VirtualNodeSegment,1024>::~BSScrapArray<PathBuilder::VirtualNodeSegment,1024> | PathBuilder.obj | fnv360_0822_debug, call_seq, medium
void BSScrapArray<Segment5eb9c0,1024>::FUN_005eb9c0() {
 this->BSScrapArray::~BSScrapArray();
}

// @f3 0x005e6280 (community match, verified in this file)
extern int DAT_00e01ce4;
namespace f3m_005e6280 {
extern void (__stdcall *DAT_00e01cec)(void*);
struct Heap5e6280 { void FUN_0086ba60(void*); };
struct Owner5e6280 { void* unk00; void* unk04; int unk08; int unk0C; Owner5e6280* FUN_005e6280(unsigned); };
// pdb: BSSimpleArray<TESObjectCELL *,1024>::`scalar deleting destructor' | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable, medium
Owner5e6280* Owner5e6280::FUN_005e6280(unsigned flags) {
 unk00=&DAT_00e01ce4;
 if(unk04) { DAT_00e01cec(unk04); unk04=0; unk0C=0; unk08=0; }
 if(flags&1) ((Heap5e6280*)&DAT_01090a78)->FUN_0086ba60(this);
 return this;
}


}   // namespace f3m_005e6280

// @f3 0x005eb440 (community match, verified in this file)
namespace f3m_005eb440 {
namespace match5eb440 {
struct Heap5eb440 {void* FUN_0086b930(unsigned);};extern Heap5eb440 DAT_01090a78;
// pdb: BSSimpleArray<NavMeshEdgeLocation,1024>::_Allocate | PathBuilder.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiSizeInItem
void* __stdcall FUN_005eb440(unsigned count) {return DAT_01090a78.FUN_0086b930(count*24);}
}
}   // namespace f3m_005eb440

// @f3 0x005eb840 (community match, verified in this file)
typedef bool Segment5eb840;
extern void (__stdcall* DAT_00e01f08)(void*);
template<> class BSSimpleArray<Segment5eb840,1024>;
typedef BSSimpleArray<Segment5eb840,1024> Base5eb840;
extern void (__thiscall* DAT_00e00d98)(Base5eb840*,void*);
template<> class BSSimpleArray<Segment5eb840,1024> {
public:
 virtual __forceinline ~BSSimpleArray() {if(pBuffer) {DAT_00e00d98(this,pBuffer);pBuffer=0;capacity=0;size=0;}}
 Segment5eb840* pBuffer;unsigned int size;unsigned int capacity;
};
template<class T,unsigned int G> class BSScrapArray;
template<> class BSScrapArray<Segment5eb840,1024>:public Base5eb840 {
public:
 virtual __forceinline ~BSScrapArray() {if(pBuffer) {DAT_00e01f08(pBuffer);pBuffer=0;capacity=0;size=0;}}
 void FUN_005eb840();
};
// pdb: BSScrapArray<bool,1024>::~BSScrapArray<bool,1024> | PathBuilder.obj | fnv360_0822_debug, call_seq, low
void BSScrapArray<Segment5eb840,1024>::FUN_005eb840() {
 this->BSScrapArray::~BSScrapArray();
}

// @f3 0x005ffe10 (community match, verified in this file)
namespace f3m_005ffe10 {
struct Map5FFE { int unk00; int unk04; int unk08; int unk0C; bool FUN_00bea7b0(unsigned,unsigned*); };
struct Owner5FFE { int unk00; int unk04; Map5FFE map; char* data; char* FUN_005ffe10(unsigned); };
// pdb: PathingLOSMap::GetArrayForNavMesh | PathingLOSMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: aNavMeshID
char* Owner5FFE::FUN_005ffe10(unsigned key) {
 if(map.FUN_00bea7b0(key,&key)) return data+key;
 return 0;
}
}   // namespace f3m_005ffe10

// @f3 0x005eb970 (community match, verified in this file)
#include <string.h>
extern unsigned int DAT_00e27ed4;
namespace f3m_005eb970 {
struct Alloc5eb970 {void* ScrapHeap_Allocate(unsigned int,unsigned int);void ScrapHeap_Deallocate(void*);};
struct Point5eb970 {float x;float y;float z;};
struct Array5eb970 {int unk00;Point5eb970* buffer;unsigned int size;unsigned int capacity;Alloc5eb970* allocator;Point5eb970* FUN_005eb970(Point5eb970*,unsigned int);};
// pdb: BSScrapArray<EffectTaskData,1024>::_Reallocate | ProcessLists.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
Point5eb970* Array5eb970::FUN_005eb970(Point5eb970* old,unsigned int count) {
 Point5eb970* replacement=(Point5eb970*)allocator->ScrapHeap_Allocate(count*sizeof(Point5eb970),DAT_00e27ed4);
 memmove(replacement,old,size*sizeof(Point5eb970));
 allocator->ScrapHeap_Deallocate(old);
 return replacement;
}
}   // namespace f3m_005eb970

// @f3 0x005ffdf0 (community match, verified in this file)
namespace f3m_005ffdf0 {
struct Owner5ffd {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; signed char* unk18;int unk1C,unk20,unk24,unk28;unsigned unk2C;unsigned FUN_005ffdf0();};
// pdb: PathingLOSMap::ClearUnseenTriangles | PathingLOSMap.obj | fnv360_0822_retail, call_gap_sim, low
unsigned Owner5ffd::FUN_005ffdf0(){unsigned i;for(i=0;i<unk2C;++i){signed char* value=unk18+i;if(*value<=0)*value=127;}return i;}
}   // namespace f3m_005ffdf0

// @f3 0x005ebbb0 (community match, verified in this file)
extern int DAT_00e01f3c,DAT_00e00a3c;
namespace f3m_005ebbb0 {
struct Owner5ebbb0;
extern void (__stdcall *DAT_00e01f44)(void*);
extern void (__thiscall *DAT_00e00a44)(Owner5ebbb0*,void*);
struct Owner5ebbb0 { void* table; void* buffer; int count; int capacity; void FUN_005ebbb0(); };
struct BaseGuard5ebbb0 {
 Owner5ebbb0* p; __forceinline BaseGuard5ebbb0(Owner5ebbb0* owner):p(owner) { p->table=&DAT_00e01f3c; }
 __forceinline ~BaseGuard5ebbb0() { void* buffer=p->buffer; p->table=&DAT_00e00a3c; if(buffer) { DAT_00e00a44(p,buffer); p->buffer=0; p->capacity=0; p->count=0; } }
};
// pdb: BSScrapArray<int,1024>::~BSScrapArray<int,1024> | PathBuilder.obj | fnv360_0822_debug, call_seq, medium
void Owner5ebbb0::FUN_005ebbb0() {
 
 BaseGuard5ebbb0 guard(this);
 if(buffer) { DAT_00e01f44(buffer); buffer=0; capacity=0; count=0; }
}



}   // namespace f3m_005ebbb0

// @f3 0x005f1240 (community match, verified in this file)
// 0x005f1240 -- take the shared object out of the global manager and hand it the argument.

struct Child_5f1240
{
    char unk00[0x24];
    int  flags24;
    void FUN_005d9f10(void* arg);
};

struct Mgr_5f1240
{
    char unk00[0xbc];
    Child_5f1240* m_bc;
    Child_5f1240* FUN_00433ff0();
};

extern Mgr_5f1240* DAT_0107a0d8;

// pdb: Pathing::GetPotentialNavMeshInfoForLocation | Pathfind.obj | fnv360_0822_retail, call_seq, high
// pdb params: apCell
void FUN_005f1240(void* arg)
{
    DAT_0107a0d8->FUN_00433ff0()->FUN_005d9f10(arg);
}

// @f3 0x005eabd0 (community match, verified in this file)
namespace f3m_005eabd0 {
extern void* __cdecl FUN_00c01530(void*,const void*,unsigned);
struct Entry5eabd0 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; };
// pdb: BSSimpleArray<NavMeshEdgeLocation,1024>::_MoveItems | PathBuilder.obj | fnv360_0822_retail, call_seq, low
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_005eabd0(Entry5eabd0* dest,Entry5eabd0* source,unsigned count) {
 if(count>0) {
  if(dest<source) { for(unsigned i=0;i<count;++i) FUN_00c01530(dest+i,source+i,24); }
  else if(dest>source) { for(int i=count-1;i>=0;--i) FUN_00c01530(dest+i,source+i,24); }
 }
}
}   // namespace f3m_005eabd0

// @f3 0x005ecef0 (community match, verified in this file)
namespace f3m_005ecef0 {
struct CodexFortyCopyElement {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void FUN_005fc480(const CodexFortyCopyElement*);
};
struct CodexFortyArray {
    int unk00;
    CodexFortyCopyElement* data;
    unsigned size;
    void FUN_005ebdf0(unsigned,bool);
    void FUN_005ecef0(CodexFortyArray*);
};
// pdb: BSSimpleArray<PathingLocation,1024>::CopyTo<1024> | PathBuilder.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: aDestArray
void CodexFortyArray::FUN_005ecef0(CodexFortyArray* destination) {
    destination->FUN_005ebdf0(size,true);
    for (unsigned i=0;i<size;++i) destination->data[i].FUN_005fc480(&data[i]);
}
}   // namespace f3m_005ecef0

// @f3 0x005e4ce0 (community match, verified in this file)
namespace f3m_005e4ce0 {
namespace match5e4ce0 {
struct Input5e4ce0 {unsigned key;};
struct Item5e4ce0 {Item5e4ce0* FUN_005ea8e0(Input5e4ce0*);};
struct Map5e4ce0 {bool FUN_00bea7b0(unsigned,Item5e4ce0**);void FUN_00880f70(unsigned,Item5e4ce0*);};
struct Heap5e4ce0 {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};extern Heap5e4ce0 DAT_01090a78;
struct Allocation5e4ce0 {void* memory;Allocation5e4ce0():memory(DAT_01090a78.FUN_0086b930(88)){}~Allocation5e4ce0(){if(memory)DAT_01090a78.FUN_0086ba60(memory);}};
struct Owner5e4ce0 {
 int unk00;
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
 int unk28;
 int unk2C;
 int unk30;
 int unk34;
 int unk38;
 int unk3C;
 int unk40;
 int unk44;
 int unk48;
 int unk4C;
 int unk50;
 int unk54;
 int unk58;
 int unk5C;
 int unk60;
 int unk64;
 int unk68;
 int unk6C;
 int unk70;
 int unk74;
 int unk78;
 int unk7C;
 int unk80;
 int unk84;
 int unk88;
 int unk8C;
 int unk90;
 int unk94;
 int unk98;
 int unk9C;
 int unkA0;
 int unkA4;
 int unkA8;
 int unkAC;
 int unkB0;
 int unkB4;
 int unkB8;
 int unkBC;
 int unkC0;
 int unkC4;
 Map5e4ce0 map;Item5e4ce0* FUN_005e4ce0(Input5e4ce0*);
};
Item5e4ce0* Owner5e4ce0::FUN_005e4ce0(Input5e4ce0* input) {
 Item5e4ce0* found=0;Item5e4ce0* result=0;
 unsigned key=input->key;Map5e4ce0* table=&map;
 if(!table->FUN_00bea7b0(key,&found)) {
 {Allocation5e4ce0 allocation;if(allocation.memory)result=((Item5e4ce0*)allocation.memory)->FUN_005ea8e0(input);allocation.memory=0;}
 table->FUN_00880f70(input->key,result);return result;
 }
 return found;
}
}
}   // namespace f3m_005e4ce0

// @f3 0x005f2730 (community match, verified in this file)
namespace f3m_005f2730 {
namespace Forward2730 {
extern void __cdecl FUN_005f1970(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// pdb: Pathing::CheckLineOfSight | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aStartLocation, aGoalLocation, apReturnIntersectionLocation, apFilter
void FUN_005f2730(unsigned a,unsigned b,unsigned c,unsigned d) { FUN_005f1970(a,b,0,65535,c,d); }
}
}   // namespace f3m_005f2730

// @f3 0x005f3660 (community match, verified in this file)
extern void* DAT_00e02118[];
namespace f3m_005f3660 {
extern void (__stdcall *DAT_00e02120)(void*);
struct Array5F36 { void** table; void* data; unsigned size; unsigned capacity; void FUN_005f3660(); };
void Array5F36::FUN_005f3660(){ table=DAT_00e02118; if(data){DAT_00e02120(data);data=0;capacity=0;size=0;} }
}   // namespace f3m_005f3660

// @f3 0x005eb740 (community match, verified in this file)
struct Allocator5eb740;
namespace Heap5eb740 {
struct Heap { Allocator5eb740* FUN_0086bcb0(); };
extern Heap DAT_01090a78;
}

struct Array5eb740 {
    void* data;
    unsigned int size;
    unsigned int capacity;
    Array5eb740() : data(0), size(0), capacity(0) {}
    virtual ~Array5eb740();
    virtual void* Allocate(unsigned int count);
};

struct FUN_005eb740 : Array5eb740 {
    Allocator5eb740* allocator;
    FUN_005eb740(unsigned int reserve, unsigned int count, Allocator5eb740* alloc);
    virtual ~FUN_005eb740();
};

// pdb: BSScrapArray<bool,1024>::BSScrapArray<bool,1024> | PathBuilder.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: aiReserveSize, aiInitialSize, apHeap
FUN_005eb740::FUN_005eb740(unsigned int reserve, unsigned int count, Allocator5eb740* alloc) {
    if (!alloc) alloc = Heap5eb740::DAT_01090a78.FUN_0086bcb0();
    allocator = alloc;
    data = 0;
    size = 0;
    capacity = 0;
    unsigned int n = reserve;
    if (count > reserve) n = count;
    if (n > 0) {
        Array5eb740* self = this;
        data = self->Allocate(n);
        capacity = n;
    }
    if (count > 0) size = count;
}

// @f3 0x005fe8f0 (community match, verified in this file)
namespace heap5fe8f0 {struct Heap {void FUN_0086ba60(void*);};extern Heap DAT_01090a78;}
class PathingLOSGridCell;
template<> class BSSimpleArray<PathingLOSGridCell*,1024>;
typedef BSSimpleArray<PathingLOSGridCell*,1024> Array5fe8f0;
extern void (__thiscall* DAT_00e022ac)(Array5fe8f0*,void*);
template<> class BSSimpleArray<PathingLOSGridCell*,1024> {
public:
 virtual __forceinline ~BSSimpleArray() {if(buffer) {DAT_00e022ac(this,buffer);buffer=0;capacity=0;size=0;}}
 PathingLOSGridCell** buffer;unsigned int size;unsigned int capacity;
 Array5fe8f0* FUN_005fe8f0(unsigned int);
};
// pdb: BSSimpleArray<PathingLOSGridCell *,1024>::`scalar deleting destructor' | PathingLOSGridMap.obj | fnv360_0822_retail, vtable, medium
Array5fe8f0* Array5fe8f0::FUN_005fe8f0(unsigned int flags) {
 this->BSSimpleArray::~BSSimpleArray();
 if(flags&1) heap5fe8f0::DAT_01090a78.FUN_0086ba60(this);
 return this;
}

// @f3 0x005f3840 (community match, verified in this file)
extern void* DAT_00e02100[];
namespace f3m_005f3840 {
struct Array5F38;
extern void (__thiscall *DAT_00e02108)(Array5F38*,void*);
struct Array5F38 { void** table; void* data; unsigned size; unsigned capacity; void FUN_005f3840(); };
void Array5F38::FUN_005f3840(){table=DAT_00e02100;if(data){DAT_00e02108(this,data);data=0;capacity=0;size=0;}}
}   // namespace f3m_005f3840

// @f3 0x005e6780 (community match, verified in this file)
namespace f3m_005e6780 {
struct Form5e67 {int unk00;unsigned char unk04;bool TESObjectDOOR_IsSlidingDoor();};struct Input5e67 {int unk00,unk04,unk08;void* unk0C;int unk10,unk14,unk18;Form5e67* unk1C;};struct Node5e67 {void* unk00;Node5e67* unk04;};struct List5e67 {Node5e67 head;Node5e67* Head(){return &head;}bool Contains(void* item){for(Node5e67* p=Head();p;p=p->unk04)if(p->unk00==item)return true;return false;}void FUN_00421610(void**);void FUN_0049fac0(void**);};struct Owner5e67 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; List5e67 unk2C;int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; List5e67 unk8C,unk94;void FUN_005e6430(Input5e67*);void FUN_005e6780(Input5e67*);};
// pdb: NavMeshObstacleManager::OnDoorRemove | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apDoorRef
void Owner5e67::FUN_005e6780(Input5e67* input){Input5e67* original=input;Form5e67* form=original->unk1C;if(form->unk04==0x1c&&!form->TESObjectDOOR_IsSlidingDoor())FUN_005e6430(original);unk2C.FUN_00421610((void**)&input);if(unk8C.Contains(original)){unk8C.FUN_00421610((void**)&input);return;}void* id=original->unk0C;if(!unk94.Contains(id)){input=(Input5e67*)id;unk94.FUN_0049fac0((void**)&input);}}
}   // namespace f3m_005e6780

// @f3 0x005f3a90 (community match, verified in this file)
extern void* DAT_00e020ec[];
namespace f3m_005f3a90 {
extern void (__stdcall* DAT_00e020f4)(void*);
struct CodexDeleteHeap { void FUN_0086ba60(void*); };
struct CodexDeleteArrayE {
    void** vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    CodexDeleteArrayE* FUN_005f3a90(unsigned);
};
// pdb: BSSimpleArray<float,1024>::`scalar deleting destructor' | Pathfind.obj | fnv360_0822_retail, vtable, medium
CodexDeleteArrayE* CodexDeleteArrayE::FUN_005f3a90(unsigned flags) {
    vtable = DAT_00e020ec;
    if (data) {
        DAT_00e020f4(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
    if (flags & 1) DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}   // namespace f3m_005f3a90

// @f3 0x005e6170 (community match, verified in this file)
extern void* DAT_00e01cec;
namespace f3m_005e6170 {

struct Obj {
    void* vtable;    // +0
    void* m_p;       // +4
    int   m_8;       // +8
    int   m_c;       // +c
    void FUN_005e6170();
};

void Obj::FUN_005e6170() {
    void* p = m_p;
    vtable = (void*)0xe01ce4;
    if (p) {
        ((void(__stdcall*)(void*))DAT_00e01cec)(p);
        m_p = 0;
        m_c = 0;
        m_8 = 0;
    }
}
}   // namespace f3m_005e6170

// @f3 0x005f8210 (community match, verified in this file)
namespace f3m_005f8210 {
namespace match5f8210 {
struct Temporary5f8210 {
 int unk00;
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
 int unk28;
 int unk2C;
 int unk30;
 void FUN_005ee830(void*,void*);bool FUN_005f0e10();void FUN_005f6660();
 Temporary5f8210(void* a,void* b){FUN_005ee830(a,b);}
 ~Temporary5f8210(){FUN_005f6660();}
};
bool FUN_005f8210(void* a,void* b) {Temporary5f8210 temporary(a,b);return temporary.FUN_005f0e10();}
}
}   // namespace f3m_005f8210

// @f3 0x005e00d0 (community match, verified in this file)
extern unsigned DAT_00e27ed4;
namespace f3m_005e00d0 {
extern void* __cdecl FUN_00bffa60(void*,const void*,unsigned);
struct Allocator5E00 {void* ScrapHeap_Allocate(unsigned,unsigned);void ScrapHeap_Deallocate(void*);};
struct Array5E00 {int unk00;void* data;unsigned size;unsigned capacity;Allocator5E00* allocator;void* FUN_005e00d0(void*,unsigned);};
// pdb: BSScrapArray<CombatPlanNode *,1024>::_Reallocate | CombatPlanner.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* Array5E00::FUN_005e00d0(void* old,unsigned count){
 void* result=allocator->ScrapHeap_Allocate(count*4,DAT_00e27ed4);
 FUN_00bffa60(result,old,size*4);
 allocator->ScrapHeap_Deallocate(old);
 return result;
}
}   // namespace f3m_005e00d0

// @f3 0x005f6660 (community match, verified in this file)
namespace f3m_005f6660 {
struct ArrayBase5f6660 {
    virtual void Unk00();
    virtual void Unk01();
    virtual void FreeData(void* data);
};

struct ArrayA5f6660 : ArrayBase5f6660 {
    void* data;
    int capacity;
    int count;
    ArrayA5f6660();
    void FUN_00415f50(void* data, int capacity);
    ~ArrayA5f6660() {
        if (data) {
            FUN_00415f50(data, capacity);
            ArrayBase5f6660* self = this;
            self->FreeData(data);
            data = 0;
            count = 0;
            capacity = 0;
        }
    }
};

struct ArrayB5f6660 : ArrayBase5f6660 {
    void* data;
    int capacity;
    int count;
    ArrayB5f6660();
    ~ArrayB5f6660() {
        if (data) {
            ArrayBase5f6660* self = this;
            self->FreeData(data);
            data = 0;
            count = 0;
            capacity = 0;
        }
    }
};

struct FUN_005f6660 {
    char pad00[0x14];
    ArrayB5f6660 arr14;
    ArrayA5f6660 arr24;
    ~FUN_005f6660();
};

FUN_005f6660::~FUN_005f6660() {
}
}   // namespace f3m_005f6660

// @f3 0x005e0200 (community match, verified in this file)
namespace f3m_005e0200 {
namespace match5e0200 {
struct Owner5e0200;extern void* DAT_00e01ab0;extern void (__thiscall *DAT_00e01ab8)(Owner5e0200*,void*);
struct Heap5e0200 {void FUN_0086ba60(void*);};extern Heap5e0200 DAT_01090a78;
struct Owner5e0200 {void* vtable;void* data;unsigned count,capacity;Owner5e0200* FUN_005e0200(unsigned);};
// pdb: BSSimpleArray<PortalEdgeSwap,1024>::`scalar deleting destructor' | NavMeshObstacleCutter.obj | fnv360_0822_retail, vtable, medium
Owner5e0200* Owner5e0200::FUN_005e0200(unsigned flags) {vtable=&DAT_00e01ab0;if(data){DAT_00e01ab8(this,data);data=0;capacity=0;count=0;}if(flags&1)DAT_01090a78.FUN_0086ba60(this);return this;}
}
}   // namespace f3m_005e0200

// @f3 0x005e45a0 (community match, verified in this file)
namespace f3m_005e45a0 {
struct Vector5E45 {float x,y,z;Vector5E45(){}Vector5E45(float a,float b,float c):x(a),y(b),z(c){}Vector5E45 operator-(const Vector5E45& v)const{return Vector5E45(x-v.x,y-v.y,z-v.z);}};struct Bounds5E45 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; Vector5E45 minimum;Vector5E45 maximum;int unk70;bool flag;};struct Node5E45 {Bounds5E45* bounds;};void __cdecl FUN_005e45a0(Node5E45* node){Bounds5E45* box=node->bounds;Vector5E45 extent=box->maximum-box->minimum;if(extent.z<48.0f){box->flag=false;return;}if(extent.z<96.0f && extent.x<16.0f && extent.y<16.0f){box->flag=false;return;}box->flag=true;}



}   // namespace f3m_005e45a0

// @f3 0x005f3780 (community match, verified in this file)
extern void* DAT_00e020ec[];
namespace f3m_005f3780 {
struct Array5F37;
extern void (__thiscall *DAT_00e020f4)(Array5F37*,void*);
struct Array5F37 {void** table;void* data;unsigned size;unsigned capacity;void FUN_005f3780();};
void Array5F37::FUN_005f3780(){table=DAT_00e020ec;if(data){DAT_00e020f4(this,data);data=0;capacity=0;size=0;}}
}   // namespace f3m_005f3780

// @f3 0x005ebec0 (community match, verified in this file)
namespace f3m_005ebec0 {
struct Array5ebec0 { void** table; void* buffer; unsigned count; unsigned capacity; void FUN_005eb0e0(unsigned,unsigned); unsigned FUN_005ebec0(); };
// pdb: BSSimpleArray<NavMeshStaticAvoidNode,1024>::Add | NavMesh.obj | fnv360_0822_retail, call_seq, low
// pdb params: aValue
unsigned Array5ebec0::FUN_005ebec0() {
 if(count==capacity) {
  if(!capacity) { buffer=((void* (__thiscall *)(Array5ebec0*,unsigned))table[1])(this,4); capacity=4; ++count; return count-1; }
  unsigned size=capacity>1024 ? capacity+1024 : capacity*2;
  FUN_005eb0e0(size,count); capacity=size;
 }
 ++count; return count-1;
}
}   // namespace f3m_005ebec0

// @f3 0x005f1460 (community match, verified in this file)
namespace f3m_005f1460 {
struct FUN_005f1460_Cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;

    char __thiscall FUN_005f1460(unsigned short param_2) const;
};

// pdb: PathingLOSMap::SetAt | Pathfind.obj | fnv360_0721_beta, call_gap, low
// pdb params: aiOffset, acValue
char __thiscall FUN_005f1460_Cls::FUN_005f1460(unsigned short param_2) const {
    char result = 0;
    unsigned short* ptr = (unsigned short*)(unk3C + (param_2 * 16) + 6);
    int i = 3;
    do {
        if (*ptr != 0xFFFF) {
            result++;
        }
        ptr++;
        i--;
    } while (i);
    return result;
}
}   // namespace f3m_005f1460

// @f3 0x005e0650 (community match, verified in this file)
namespace f3m_005e0650 {

struct F3RefObj
{
    virtual void unk00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

struct F3Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    F3RefObj* m_p1C;
};

struct FUN_005e0120
{
    ~FUN_005e0120();
    int unk00;
    F3Elem** m_ppBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiStorage;
    unsigned int GetSize() { return m_uiSize; }
};

struct FUN_005dff70
{
    ~FUN_005dff70();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_0086caa0
{
    ~FUN_0086caa0();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

inline void F3Release(F3RefObj* p)
{
    if (p && InterlockedDecrement(&p->m_uiRefCount) == 0)
        p->DeleteThis();
}

struct F3SmartRef
{
    F3RefObj* m_pObject;
    ~F3SmartRef()
    {
        F3Release(m_pObject);
    }
};

struct FUN_005e0650
{
    int unk00;
    F3SmartRef m04;
    int unk08;
    FUN_0086caa0 m0C;
    FUN_005dff70 m1C;
    FUN_005e0120 m30;
    ~FUN_005e0650();
};

// pdb: NavMeshObstacleCutter::~NavMeshObstacleCutter | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: NavMeshObstacleCutter::ResetNavMeshFromObstacleUndoData)
FUN_005e0650::~FUN_005e0650()
{
    for (unsigned int i = 0; i < m30.GetSize(); i++)
    {
        F3Release(m30.m_ppBuffer[i]->m_p1C);
    }
}
}   // namespace f3m_005e0650

// @f3 0x005fc120 (community match, verified in this file)
extern const float DAT_00e02188;
namespace f3m_005fc120 {
namespace SumC120 {
struct Point { float x,y,z; Point operator-(const Point& rhs) const { Point p={x-rhs.x,y-rhs.y,z-rhs.z}; return p; } float Squared() const { return x*x+y*y+z*z; } float Dot(const Point& rhs) const { return x*rhs.x+y*rhs.y+z*rhs.z; } };
struct Record { Point start,end; float radius,strength; int kind; __declspec(noinline) float FUN_005fbea0(Point* point) const; };
__declspec(noinline) float Record::FUN_005fbea0(Point* point) const { float radiusSquared=radius*radius; float distance=DAT_00e02188; float result=0; switch(kind) { case 0: case 2: { Point offset=start-*point; distance=offset.Squared(); break; } case 1: { Point direction=end-start; Point offset=*point-start; float length=direction.Squared(); float projection=direction.Dot(offset); if(projection<0 || length<projection) distance=DAT_00e02188; else distance=offset.Squared()-projection*projection/length; break; } } if(radiusSquared>distance) result=(1-distance/radiusSquared)*strength; return result; }
struct Array { void* table; Record* data; unsigned count; float FUN_005fc120(Point*); };
// pdb: PathingAvoidNodeArray::GetCostForPoint | PathingAvoidNode.obj | fnv360_0822_retail, call_seq, low
// pdb params: arPoint
float Array::FUN_005fc120(Point* point) { float total=0; unsigned remaining=count; if(remaining>0) { Record* current=data; do { total+=current->FUN_005fbea0(point); ++current; } while(--remaining); } return total; }
}
}   // namespace f3m_005fc120

// @f3 0x005fece0 (community match, verified in this file)
namespace f3m_005fece0 {
struct Stream5fece0 {void FUN_006e0750(void*,unsigned int);unsigned int BGSLoadGameBuffer_LoadVariableSizedValue();};
struct Array5fece0 {int unk00;char* buffer;unsigned int size;unsigned int capacity;void FUN_005fe850(unsigned int,int);};
struct Owner5fece0 {unsigned char kind;unsigned char unk01;unsigned short unk02;Array5fece0 data;int unk14;int unk18;void FUN_005fece0(Stream5fece0*);};
// pdb: PathingLOSGridCell::LoadGame | PathingLOSGridMap.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apLoadGameBuffer
void Owner5fece0::FUN_005fece0(Stream5fece0* stream) {
 stream->FUN_006e0750(&kind,1);
 stream->FUN_006e0750(&unk18,4);
 if(kind==0) {
 unsigned int count=stream->BGSLoadGameBuffer_LoadVariableSizedValue();
 data.FUN_005fe850(count,1);
 for(unsigned int i=0;i<count;++i) stream->FUN_006e0750(data.buffer+i,1);
 }
}
}   // namespace f3m_005fece0

// @f3 0x005f3690 (community match, verified in this file)
namespace f3m_005f3690 {
namespace match5f3690 {
struct Base5f3690;extern void* DAT_00e0212c;extern void* DAT_00e02118;
extern void (__thiscall *DAT_00e02134)(Base5f3690*,void*);extern void (__thiscall *DAT_00e02120)(Base5f3690*,void*);
struct Base5f3690 {void* vtable;void* data;unsigned count,capacity;~Base5f3690(){vtable=&DAT_00e02118;if(data){DAT_00e02120(this,data);data=0;capacity=0;count=0;}}};
struct Owner5f3690:Base5f3690 {void FUN_005f3690();};
struct Cleanup5f3690 {Base5f3690* object;Cleanup5f3690(Base5f3690* p):object(p){object->vtable=&DAT_00e0212c;}~Cleanup5f3690(){object->~Base5f3690();}};
// pdb: BSScrapArray<PathingNode *,1024>::~BSScrapArray<PathingNode *,1024> | Pathfind.obj | fnv360_0822_debug, call_seq, medium
void Owner5f3690::FUN_005f3690() {Cleanup5f3690 cleanup(this);if(data){DAT_00e02134(this,data);data=0;capacity=0;count=0;}}
}
}   // namespace f3m_005f3690

// @f3 0x005e4810 (community match, verified in this file)
namespace f3m_005e4810 {
void __cdecl FUN_005bb300(void*,int);
struct Node5e4810 {void* data;Node5e4810* next;void FUN_006c8220();};
struct Owner5e4810 {
 int unk00;
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
 int unk28;
 int unk2C;
 int unk30;
 int unk34;
 int unk38;
 int unk3C;
 int unk40;
 int unk44;
 int unk48;
 int unk4C;
 int unk50;
 int unk54;
 int unk58;
 int unk5C;
 int unk60;
 int unk64;
 int unk68;
 int unk6C;
 int unk70;
 int unk74;
 int unk78;
 int unk7C;
 int unk80;
 int unk84;
 int unk88;
 int unk8C;
 int unk90;
 int unk94;
 int unk98;
 int unk9C;
 int unkA0;
 int unkA4;
 int unkA8;
 int unkAC;
 int unkB0;
 int unkB4;
 int unkB8;
 int unkBC;
 int unkC0;
 int unkC4;
 int unkC8;
 int unkCC;
 int unkD0;
 int unkD4;
 int unkD8;
 int unkDC;
 int unkE0;
 int unkE4;
 int unkE8;
 int unkEC;
 int unkF0;
 int unkF4;
 int unkF8;
 int unkFC;
 int unk100;
 int unk104;
 int unk108;
 int unk10C;
 int unk110;
 int unk114;
 int unk118;
 int unk11C;
 Node5e4810 head;Node5e4810* Head(){return &head;}bool FUN_005e4810();
};
// pdb: NavMeshObstacleManager::ProcessEnabledNavMeshes | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool Owner5e4810::FUN_005e4810() {
 Node5e4810* node=Head();
 while(node && (node->next || node->data)) {FUN_005bb300(node->data,0);node=node->next;}
 head.FUN_006c8220();
 return true;
}

}   // namespace f3m_005e4810

// @f3 0x005eba50 (community match, verified in this file)
extern int DAT_00e01eb0;
namespace f3m_005eba50 {
extern void (__stdcall *DAT_00e01eb8)(void*);
struct Owner5eba50 { void* table; void* buffer; int count; int capacity; void FUN_005eba50(); };
void Owner5eba50::FUN_005eba50() { table=&DAT_00e01eb0; if(buffer) { DAT_00e01eb8(buffer); buffer=0; capacity=0; count=0; } }
}   // namespace f3m_005eba50

// @f3 0x005eb710 (community match, verified in this file)
namespace f3m_005eb710 {
struct ArrayBase5eb710 {
    virtual void Unk00();
    virtual void Unk01();
    virtual void FreeData(void* data);
};

struct FUN_005eb710 : ArrayBase5eb710 {
    void* data;
    int capacity;
    int count;
    FUN_005eb710();
    ~FUN_005eb710();
};

FUN_005eb710::~FUN_005eb710() {
    if (data) {
        ArrayBase5eb710* self = this;
        self->FreeData(data);
        data = 0;
        count = 0;
        capacity = 0;
    }
}
}   // namespace f3m_005eb710

// @f3 0x005f13e0 (community match, verified in this file)
namespace f3m_005f13e0 {
namespace fo3_5f13e0 {
void* __cdecl FUN_00c01530(void*,const void*,unsigned int);
struct CopyRecords {void FUN_005f13e0(char*,char*,unsigned int);};
// @fnv 0x006dbf20
// pdb: BSSimpleArray<PathingCoverLocation,1024>::_MoveItems | Pathfind.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apDestAddr, apSrcAddr, aiCount
void __thiscall CopyRecords::FUN_005f13e0(char* dst, char* src, unsigned int count)
{
    if (!(count > 0))
    {
    }
    else
    {
        if ((unsigned int)dst < (unsigned int)src)
        {
            for (unsigned int i = 0; i < count; ++i)
                FUN_00c01530(dst + i * 0x54, src + i * 0x54, 0x54);
        }
        else if ((unsigned int)dst > (unsigned int)src)
        {
            for (int i = (int)count - 1; i >= 0; --i)
                FUN_00c01530(dst + i * 0x54, src + i * 0x54, 0x54);
        }
    }
}

}
}   // namespace f3m_005f13e0

// @f3 0x005ea3b0 (community match, verified in this file)
namespace f3m_005ea3b0 {
struct FUN_005e9d60 {
    int values[4];
    ~FUN_005e9d60();
};

struct FUN_005ea3b0_cls {
    virtual void Unk00();
    virtual FUN_005e9d60* Allocate(unsigned int count);
    virtual void Free(FUN_005e9d60* data);
    FUN_005e9d60* data;
    unsigned int count;
    unsigned int capacity;
    void FUN_005b8560(FUN_005e9d60* dst, FUN_005e9d60* src, unsigned int n);
    void FUN_005ea3b0(unsigned int index, bool shrink);
};

// pdb: BSSimpleArray<ObstacleTaskNavMeshOperation,1024>::Remove | NavMeshObstacleTask.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiIndex, abShrink
void FUN_005ea3b0_cls::FUN_005ea3b0(unsigned int index, bool shrink) {
    if (shrink) {
        if (capacity > 0x400) {
            if (count <= capacity - 0x800) {
                goto shrinkArray;
            }
        } else if (count <= capacity >> 2) {
            goto shrinkArray;
        }
    }
    data[index].~FUN_005e9d60();
    FUN_005b8560(&data[index], &data[index + 1], count - index - 1);
    --count;
    return;

shrinkArray:
    unsigned int newCapacity = capacity > 0x800 ? capacity - 0x400 : capacity >> 1;
    FUN_005e9d60* newData = Allocate(newCapacity);
    FUN_005b8560(newData, data, index);
    data[index].~FUN_005e9d60();
    FUN_005b8560(newData + index, &data[index + 1], count - 1);
    Free(data);
    --count;
    capacity = newCapacity;
    data = newData;
}
}   // namespace f3m_005ea3b0

// @f3 0x005e9d60 (community match, verified in this file)
namespace f3m_005e9d60 {
struct Counter5e9d60 { void** table; long refs; void IncRefCount() { InterlockedIncrement(&refs); } void DecRefCount() { if(!InterlockedDecrement(&refs)) ((void (__thiscall *)(Counter5e9d60*))table[1])(this); } };
struct Resource5e9d60 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; Counter5e9d60 counter; void IncRefCount() { counter.IncRefCount(); } void DecRefCount() { counter.DecRefCount(); } };
struct Owner5e9d60 { NiPointer<Counter5e9d60> first; int unk04; int unk08; NiPointer<Resource5e9d60> last; void FUN_005e9d60(); };
struct Guard5e9d60 { Owner5e9d60* p; __forceinline ~Guard5e9d60() { p->first.~NiPointer(); } };
// pdb: BSSimpleArray<ObstacleTaskNavMeshOperation,1024>::_DestructItems | NavMeshObstacleTask.obj | fnv360_0822_retail, call_seq, low
// pdb params: apFirstAddr, aiCount
void Owner5e9d60::FUN_005e9d60() { Guard5e9d60 guard={this}; Resource5e9d60* object=last; if(object) object->DecRefCount(); }
}   // namespace f3m_005e9d60

// @f3 0x005f37b0 (community match, verified in this file)
extern void* DAT_00e02140[];
extern void* DAT_00e020ec[];
namespace f3m_005f37b0 {
extern void (__stdcall* DAT_00e02148)(void*);
struct SmallArray;
extern void (__thiscall* DAT_00e020f4)(SmallArray*,void*);
struct SmallArray { void** table; void* data; unsigned size; unsigned capacity; void FUN_005f37b0(); };
struct ArrayBaseCleanup {
 SmallArray* owner;
 ArrayBaseCleanup(SmallArray* p):owner(p) { p->table=DAT_00e02140; }
 ~ArrayBaseCleanup() {
  void* storage=owner->data;
  owner->table=DAT_00e020ec;
  if(storage) { DAT_00e020f4(owner,storage);owner->data=0;owner->capacity=0;owner->size=0; }
 }
};
// pdb: BSScrapArray<float,1024>::~BSScrapArray<float,1024> | Pathfind.obj | fnv360_0822_debug, call_seq, low
void SmallArray::FUN_005f37b0() {
 ArrayBaseCleanup cleanup(this);
 if(data) {DAT_00e02148(data);data=0;capacity=0;size=0;}
}

}   // namespace f3m_005f37b0

// @f3 0x005f6850 (community match, verified in this file)
namespace f3m_005f6850 {
struct Temporary6850 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30;
void FUN_005ee830(unsigned,unsigned); int FUN_005f0eb0(unsigned,unsigned); void FUN_005f6660();
__forceinline Temporary6850(unsigned a,unsigned b) { FUN_005ee830(a,b); } __forceinline ~Temporary6850() { FUN_005f6660(); }
};
// pdb: Pathing::UpdateSolution | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRequest, apSolution, aiCurrentVirtualNodeIndex, aCurrentActorLocation
int FUN_005f6850(unsigned a,unsigned b,unsigned c,unsigned d) { Temporary6850 temporary(a,b); return temporary.FUN_005f0eb0(c,d); }
}   // namespace f3m_005f6850

// @f3 0x005e6140 (community match, verified in this file)
extern void* DAT_00e01cd0[];
namespace f3m_005e6140 {
extern void (__stdcall* DAT_00e01cd8)(void*);
struct ReleasableArray {
 void** table;
 void* data;
 unsigned size;
 unsigned capacity;
 void FUN_005e6140();
};
void ReleasableArray::FUN_005e6140() {
 void* storage=data;
 table=DAT_00e01cd0;
 if(storage) {DAT_00e01cd8(storage);data=0;capacity=0;size=0;}
}
}   // namespace f3m_005e6140

// @f3 0x005e9c10 (community match, verified in this file)
namespace f3m_005e9c10 {
struct Input5e9 {int unk00;int unk04;int unk08;void*data;};
struct Result5e9 {void FUN_005e69b0();};
struct Owner5e9 {Result5e9* FUN_005e9ad0(void*);void FUN_005e9c10(Input5e9*);};
// pdb: bhkObstacleRemovalListener::entityRemovedCallback | NavMeshObstacleManager.obj | fnv360_0822_retail, caller_sim, low
// pdb params: entity
void Owner5e9::FUN_005e9c10(Input5e9*input){if(input&&input->data)FUN_005e9ad0(input->data)->FUN_005e69b0();}
}   // namespace f3m_005e9c10

// @f3 0x005f3720 (community match, verified in this file)
namespace f3m_005f3720 {
namespace match5f3720 {
struct Owner;extern void* DAT_00e020b0;extern void (__thiscall* DAT_00e020b8)(Owner*,void*);
struct Owner {void* vtable;void* data;unsigned count,capacity;void FUN_005f3720();};
void Owner::FUN_005f3720(){vtable=&DAT_00e020b0;if(data){DAT_00e020b8(this,data);data=0;capacity=0;count=0;}}
}
}   // namespace f3m_005f3720

// @f3 0x005eb1c0 (community match, verified in this file)
namespace f3m_005eb1c0 {
struct Array5eb1c0 { void** table; void* buffer; unsigned count,capacity; void FUN_005eac40(void*,void*,unsigned); void FUN_005eb1c0(unsigned,unsigned); };
// pdb: BSSimpleArray<char,1024>::_ReallocateBuffer | PathingLOSGridMap.obj | fnv360_0822_retail, callee_sim, low
// pdb params: aiNewSize, aiCopyCount
void Array5eb1c0::FUN_005eb1c0(unsigned size,unsigned copyCount) {
 if(buffer) { if(copyCount==capacity) { buffer=((void* (__thiscall *)(Array5eb1c0*,void*,unsigned))table[3])(this,buffer,size); return; }
 void* replacement=((void* (__thiscall *)(Array5eb1c0*,unsigned))table[1])(this,size);
 FUN_005eac40(replacement,buffer,copyCount); ((void (__thiscall *)(Array5eb1c0*,void*))table[2])(this,buffer); buffer=replacement;
 } else { buffer=((void* (__thiscall *)(Array5eb1c0*,unsigned))table[1])(this,size); capacity=size; }
}
}   // namespace f3m_005eb1c0

// @f3 0x005eb3e0 (community match, verified in this file)
namespace f3m_005eb3e0 {
namespace MatchEB3 {
struct Element {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;void FUN_00600960();};
struct Owner;struct Table {void* unk00;void* unk04;void (__thiscall* free)(Owner*,void*);};
struct Owner {Table* table;Element* data;unsigned count;unsigned capacity;void FUN_005eb3e0(bool);};
// pdb: BSSimpleArray<PathingNode,1024>::Clear | PathBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: abFreeMemory
void Owner::FUN_005eb3e0(bool release){Element* p=data;if(p){unsigned n=count;while(n>0){p->FUN_00600960();++p;--n;}if(release){table->free(this,data);data=0;capacity=0;}count=0;}}
}
}   // namespace f3m_005eb3e0

// @f3 0x005f68d0 (community match, verified in this file)
namespace f3m_005f68d0 {
struct Temporary5f68 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; void FUN_005ee830(int,int);unsigned FUN_005ec150();void FUN_005f6660();Temporary5f68(int a,int b){FUN_005ee830(a,b);}~Temporary5f68(){FUN_005f6660();}};
// pdb: Pathing::UpdateSolutionMoveToLow | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRequest, apSolution
unsigned FUN_005f68d0(int first,int second){Temporary5f68 temporary(first,second);return temporary.FUN_005ec150();}
}   // namespace f3m_005f68d0

// @f3 0x005e7680 (community match, verified in this file)
extern void* DAT_00e01d68; extern void* DAT_00db5c04;
namespace f3m_005e7680 {
struct Owner5e7680 {void** table;void* data;unsigned count;unsigned capacity;void FUN_00415f50(void*,unsigned);void Clear(){if(data){FUN_00415f50(data,count);((void(__thiscall*)(Owner5e7680*,void*))table[2])(this,data);data=0;capacity=0;count=0;}} ~Owner5e7680(){table=&DAT_00db5c04;Clear();} void FUN_005e7680();};
struct Cleanup5e7680 {Owner5e7680* p;Cleanup5e7680(Owner5e7680* value):p(value){p->table=&DAT_00e01d68;}~Cleanup5e7680(){p->~Owner5e7680();}};
// pdb: BSScrapArray<NavMeshPtr,1024>::~BSScrapArray<NavMeshPtr,1024> | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, medium
void Owner5e7680::FUN_005e7680(){Cleanup5e7680 guard(this);Clear();}
}   // namespace f3m_005e7680

// @f3 0x005fc430 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005fc430 {
// 0x005fc430 - __thiscall, one stack argument (ret 4).
// Copy constructor of the object whose default constructor is 0x005fc3f0:
// install the class vtable at +0 and copy every member (+4..+0x26) from the
// source object. 0x005fc480 is the same copy without the vtable store, i.e.
// the assignment operator.


struct Object5fc430
{
    void* vtable;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    short m24;
    char m26;
    Object5fc430* FUN_005fc430(const Object5fc430& other);
};

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aLoc
Object5fc430* Object5fc430::FUN_005fc430(const Object5fc430& other)
{
    vtable = &DAT_00dc4dc0;
    m04 = other.m04;
    m08 = other.m08;
    m0C = other.m0C;
    m10 = other.m10;
    m14 = other.m14;
    m18 = other.m18;
    m1C = other.m1C;
    m20 = other.m20;
    m24 = other.m24;
    m26 = other.m26;
    return this;
}
}   // namespace f3m_005fc430

// @f3 0x005e3120 (community match, verified in this file)
namespace f3m_005e3120 {
// pdb: NavMeshObstacleManager::GetProcessedTaskCount | NavMeshObstacleManager.obj | fnv360_1110_retail, ustr_rel, medium
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long*,long,long);extern char DAT_00e01be0[];struct Lock5E31 {long owner;long count;void FUN_00409a80(const char*);__forceinline void Unlock(){if(--count==0)InterlockedCompareExchange(&owner,0,owner);}};struct Owner5E31 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4; int unkE8; int unkEC; void* value;int unkF4;int unkF8;int unkFC;Lock5E31 lock;void* FUN_005e3120();};void* Owner5E31::FUN_005e3120(){lock.FUN_00409a80(DAT_00e01be0);void* result=value;lock.Unlock();return result;}
}   // namespace f3m_005e3120

// @f3 0x005e4e20 (community match, verified in this file)
namespace f3m_005e4e20 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
class RefObject5e4e20 {
public:
    virtual void Unk00();
    virtual void DeleteThis();
    long refCount; // +0x04
};
struct RefPtr5e4e20 {
    RefObject5e4e20* object;
    ~RefPtr5e4e20() {
        RefObject5e4e20* current = object;
        if (current && InterlockedDecrement(&current->refCount) == 0) {
            current->DeleteThis();
        }
    }
};
class FUN_005e4e20 {
public:
    RefPtr5e4e20 object;
    FUN_005e4e20();
    ~FUN_005e4e20();
    void FUN_005e3010();
};
// pdb: BSSimpleList<NiPointer<BSTempEffect> >::~BSSimpleList<NiPointer<BSTempEffect> > | BGSDecalNode.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: BSTArray<class NiPointer<class NiNode>,class BSTArrayHeapAllocator>::~BSTArray<class NiPointer<class NiNode>,class BSTArrayHeapAllocator>)
FUN_005e4e20::~FUN_005e4e20() {
    FUN_005e3010();
}
}   // namespace f3m_005e4e20

// @f3 0x005ebd60 (community match, verified in this file)
extern int DAT_00e01eb0;
namespace f3m_005ebd60 {
extern void (__stdcall *DAT_00e01eb8)(void*);
struct Pool85{void FUN_0086ba60(void*);};
namespace Heap85{extern Pool85 DAT_01090a78;}
struct Owner85{
 void* vtable;void* data;unsigned int capacity,length;
 void* FUN_005ebd60(unsigned int flags);
};
// pdb: BSSimpleArray<FastNavMeshTriHandle,1024>::`scalar deleting destructor' | PathBuilder.obj | fnv360_0822_retail, vtable, medium
void* Owner85::FUN_005ebd60(unsigned int flags){
 vtable=&DAT_00e01eb0;
 if(data){DAT_00e01eb8(data);data=0;length=0;capacity=0;}
 if(flags&1)Heap85::DAT_01090a78.FUN_0086ba60(this);
 return this;
}
}   // namespace f3m_005ebd60

// @f3 0x005fc0b0 (community match, verified in this file)
namespace f3m_005fc0b0 {
struct Reader103{void FUN_006e0750(void*,unsigned int);};
struct Vec103{float x,y,z;};
struct Owner103{
 Vec103 position,direction;
 unsigned int first,second,type;
 void FUN_005fc0b0(Reader103*);
};
// pdb: PathingAvoidNode::LoadGame | PathingAvoidNode.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apLoadGameBuffer
void Owner103::FUN_005fc0b0(Reader103* reader){
 unsigned char value=0;reader->FUN_006e0750(&value,1);type=value;
 reader->FUN_006e0750(&first,4);reader->FUN_006e0750(&second,4);reader->FUN_006e0750(&position,12);
 if(type==1)reader->FUN_006e0750(&direction,12);
}
}   // namespace f3m_005fc0b0

// @f3 0x005e54d0 (community match, verified in this file)
extern bool DAT_01074864;
namespace f3m_005e54d0 {
struct Node122{void* item;Node122* next;void FUN_0049fac0(void**);};
struct Owner122{
 unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
 Node122 entries;
 void FUN_005e54d0(void*);
};
// pdb: NavMeshObstacleManager::AddObstacleForReference | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRef
void Owner122::FUN_005e54d0(void* item){
 if(DAT_01074864){Node122* node=&entries;while(node){if(node->item==item)return;node=node->next;}entries.FUN_0049fac0(&item);}
}
}   // namespace f3m_005e54d0

// @f3 0x005f1140 (community match, verified in this file)
#include <math.h>
extern float DAT_0108d81c,DAT_0108d780,DAT_0108d78c,DAT_00f70e64,DAT_00f70e68,DAT_00f70e6c;
extern const double DAT_00dc2df0=0.01745329238474369;
namespace f3m_005f1140 {
// pdb: Pathing::Init | Pathfind.obj | fnv360_0822_retail, call_gap, medium
bool __cdecl FUN_005f1140(){
 DAT_00f70e64=cosf(static_cast<float>(DAT_0108d81c*DAT_00dc2df0));
 DAT_00f70e68=cosf(static_cast<float>(DAT_0108d780*DAT_00dc2df0));
 DAT_00f70e6c=cosf(static_cast<float>(DAT_0108d78c*DAT_00dc2df0));
 return true;
}
}   // namespace f3m_005f1140

// @f3 0x005fc810 (community match, verified in this file)
namespace f3m_005fc810 {
namespace Serialize132{
struct Writer132{void FUN_006e1830(const void*,unsigned int,int);void BGSSaveGameBuffer_SaveFormID(unsigned int,int);void FUN_006e17e0(void*,int);};
struct Vec132{float x,y,z;};
struct Descriptor132{unsigned int id;};
struct Owner132{
 unsigned int unk00;Vec132 position;Descriptor132* descriptor;void* primary;void* first;void* second;unsigned int value;unsigned short index;unsigned char flags;
 void FUN_005fc810(Writer132*);
};
// pdb: PathingLocation::SaveGame | PathingLocation.obj | fnv360_0822_retail, vtable, medium
// pdb params: apSaveGameBuffer
void Owner132::FUN_005fc810(Writer132* writer){
 writer->FUN_006e1830(&position,12,0);
 writer->BGSSaveGameBuffer_SaveFormID(descriptor?descriptor->id:0,0);
 writer->FUN_006e17e0(first,0);writer->FUN_006e17e0(second,0);
 writer->FUN_006e1830(&value,4,0);writer->FUN_006e1830(&index,2,0);writer->FUN_006e1830(&flags,1,0);
 bool present=primary!=0;writer->FUN_006e1830(&present,1,0);
}
}
}   // namespace f3m_005fc810

// @f3 0x005f3a40 (community match, verified in this file)
extern int DAT_00e020c4;
namespace f3m_005f3a40 {
extern void (__stdcall *DAT_00e020cc)(void*);
struct Pool147{void FUN_0086ba60(void*);};
namespace Heap147{extern Pool147 DAT_01090a78;}
struct Owner147{
 void* vtable;void* data;unsigned int capacity,length;
 void* FUN_005f3a40(unsigned int flags);
};
// pdb: BSSimpleArray<NavmeshTriFan,1024>::`scalar deleting destructor' | Pathfind.obj | fnv360_0822_retail, vtable, medium
void* Owner147::FUN_005f3a40(unsigned int flags){
 vtable=&DAT_00e020c4;
 if(data){DAT_00e020cc(data);data=0;length=0;capacity=0;}
 if(flags&1)Heap147::DAT_01090a78.FUN_0086ba60(this);
 return this;
}

}   // namespace f3m_005f3a40

// @f3 0x005eb010 (community match, verified in this file)
namespace f3m_005eb010 {
struct Entry153{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;void FUN_00600960();};
// pdb: BSSimpleArray<VirtualPathingNode,1024>::_DestructItems | PathBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apFirstAddr, aiCount
void __stdcall FUN_005eb010(Entry153* entry,unsigned int count){if(count>0){do{entry->FUN_00600960();++entry;}while(--count);}}
}   // namespace f3m_005eb010

// @f3 0x005e6df0 (community match, verified in this file)
namespace Delete167{
struct Owner167;
struct Vtable167{void* slot00;void* slot04;void (__thiscall *Free)(Owner167*,void*);};
extern Vtable167 DAT_00e01c5c;
struct Heap167{void FUN_0086ba60(void*);};extern Heap167 DAT_01090a78;
struct Owner167{
 Vtable167* vtable;void* data;unsigned int count,capacity;
 void FUN_005e5240(void*,unsigned int);
 void* FUN_005e6df0(unsigned int);
};
// pdb: BSSimpleArray<NiPointer<ObstacleData>,1024>::`scalar deleting destructor' | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable, medium
void* Owner167::FUN_005e6df0(unsigned int flags){
 vtable=&DAT_00e01c5c;if(data){FUN_005e5240(data,count);vtable->Free(this,data);data=0;capacity=0;count=0;}
 if(flags&1)DAT_01090a78.FUN_0086ba60(this);return this;
}
}

// @f3 0x005fc730 (community match, verified in this file)
namespace f3m_005fc730 {
struct Alternative182{void* FUN_00501d90(unsigned int);};
struct Owner182{
 unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;void* first;Alternative182* second;unsigned int value;
 void* PathingLocation_GetCell();
};
// pdb: PathingLocation::GetCell | PathingLocation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim), high
void* Owner182::PathingLocation_GetCell(){if(first)return first;if(second){void* result=second->FUN_00501d90(value);if(result)return result;}return 0;}
}   // namespace f3m_005fc730

// @f3 0x005e5de0 (community match, verified in this file)
namespace f3m_005e5de0 {
struct Object5e5d{void**table;};struct Array5e5d{void**table;Object5e5d**data;unsigned size;unsigned capacity;__forceinline void Clear(){if(data){((void(__thiscall*)(Array5e5d*,void*))table[2])(this,data);data=0;capacity=0;size=0;}}};
struct Owner5e5d{
int unk00;
int unk04;
int unk08;
int unk0C;
int unk10;
int unk14;
int unk18;
int unk1C;
int unk20;
int unk24;
int unk28;
int unk2C;
int unk30;
int unk34;
int unk38;
int unk3C;
int unk40;
int unk44;
int unk48;
int unk4C;
int unk50;
int unk54;
int unk58;
int unk5C;
int unk60;
int unk64;
int unk68;
int unk6C;
int unk70;
int unk74;
int unk78;
int unk7C;
int unk80;
int unk84;
int unk88;
int unk8C;
int unk90;
int unk94;
int unk98;
int unk9C;
int unkA0;
int unkA4;
int unkA8;
int unkAC;
int unkB0;
int unkB4;
int unkB8;
int unkBC;
int unkC0;
int unkC4;
int unkC8;
int unkCC;
int unkD0;
int unkD4;
Array5e5d first;Array5e5d second;bool FUN_005e5de0();};
// pdb: NavMeshObstacleManager::DeleteCurrentTasks | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool Owner5e5d::FUN_005e5de0(){unsigned count=second.size;for(unsigned i=0;i<count;++i){Object5e5d*object=second.data[i];if(object)((void*(__thiscall*)(Object5e5d*,unsigned))object->table[0])(object,1);}second.Clear();first.Clear();return true;}
}   // namespace f3m_005e5de0

// @f3 0x005f11b0 (community match, verified in this file)
namespace f3m_005f11b0 {
namespace f3_005f11b0 {
struct CoverSortItem { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14; float score, angle; };
// @fnv 0x006d4020
// pdb: EdgeSortFunction | Pathfind.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apEdge1, apEdge2
int __cdecl FUN_005f11b0(const CoverSortItem* first, const CoverSortItem* second)
{
    bool firstInRange;
    bool rightInRange;
    const CoverSortItem* other;
    const CoverSortItem* a;
    a = first;
    other = second;
    firstInRange = a->angle > -64.0 && a->angle < 180.0;
    rightInRange = other->angle > -64.0 && other->angle < 180.0;
    if (firstInRange && !rightInRange)
        return -1;
    else if (!firstInRange && rightInRange)
        return 1;
    else if (a->score < other->score)
        return -1;
    else if (a->score > other->score)
        return 1;
    else
        return 0;
}

}
}   // namespace f3m_005f11b0

// @f3 0x005e3160 (community match, verified in this file)
namespace f3m_005e3160 {
// pdb: NavMeshObstacleManager::GetBackgroundTaskCount | NavMeshObstacleManager.obj | fnv360_1110_retail, ustr_rel, medium
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long*,long,long);extern char DAT_00e01c10[];struct Lock5E316 {long owner;long count;void FUN_00409a80(const char*);__forceinline void Unlock(){if(--count==0)InterlockedCompareExchange(&owner,0,owner);}};struct Owner5E316 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; void* value; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC; Lock5E316 lock;void* FUN_005e3160();};void* Owner5E316::FUN_005e3160(){lock.FUN_00409a80(DAT_00e01c10);void* result=value;lock.Unlock();return result;}
}   // namespace f3m_005e3160

// @f3 0x005fc750 (community match, verified in this file)
namespace f3m_005fc750 {
namespace match5fc750 {
struct Data {
int unk00;
int unk04;
int unk08;
int unk0C;
int unk10;
int unk14;
int unk18;
int unk1C;
int unk20;
int unk24;
int unk28;
int unk2C;
int unk30;
int unk34;
int unk38;
int unk3C;
int unk40;
int unk44;
int unk48;
int unk4C;
int unk50;
void* member;
};
struct Owner {int unk00;int unk04;int unk08;int unk0C;Data* data;int unk14;int unk18;int unk1C;int unk20;unsigned short index;bool FUN_005fc750();};
// pdb: PathingLocation::HasNavMeshData | PathingLocation.obj | fnv360_0822_retail, call_dedup, low
bool Owner::FUN_005fc750(){if(!data)return false;if(!data->member)return false;if(index!=0xffff)return true;return false;}
}
}   // namespace f3m_005fc750

// @f3 0x005fe150 (community match, verified in this file)
namespace f3m_005fe150 {
namespace MatchFE1 {
struct Stream {void FUN_006e1830(void*,unsigned,int);void BGSSaveGameBuffer_SaveVariableSizedValue(unsigned);};
struct Array {void* table;char* data;unsigned count;unsigned capacity;unsigned Size(){return this?count:0;} char& Get(unsigned i){return data[i];}};
struct Owner {bool skip;unsigned char unk01;unsigned short unk02;Array array;int unk14;unsigned value;Array* GetArray(){return &array;} void FUN_005fe150(Stream*);};
// pdb: PathingLOSGridCell::SaveGame | PathingLOSGridMap.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apSaveGameBuffer
void Owner::FUN_005fe150(Stream* stream){stream->FUN_006e1830(this,1,0);stream->FUN_006e1830(&value,4,0);if(!skip){unsigned n=GetArray()?array.count:0;stream->BGSSaveGameBuffer_SaveVariableSizedValue(n);for(unsigned i=0;i<n;++i)stream->FUN_006e1830(&array.Get(i),1,0);}}
}
}   // namespace f3m_005fe150

// @f3 0x005ebf20 (community match, verified in this file)
namespace f3m_005ebf20 {
typedef unsigned size_t;
inline void* operator new(size_t,void* destination){return destination;}
inline void operator delete(void*,void*){}
struct Element5ebf {int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C;Element5ebf(int value){FUN_00610040(value);}void FUN_00610040(int);};
struct Array5ebf {unsigned FUN_005eb230();};
struct Owner5ebf {int unk00,unk04;Array5ebf unk08;Element5ebf* unk0C;unsigned FUN_005ebf20(int);};
unsigned Owner5ebf::FUN_005ebf20(int value){unsigned index=unk08.FUN_005eb230();Element5ebf* destination=unk0C+index;new(destination)Element5ebf(value);return index;}
}   // namespace f3m_005ebf20

// @f3 0x005ea970 (community match, verified in this file)
namespace f3m_005ea970 {
namespace DestroyA970 {
struct RefBase; struct RefOps { void* unk00; void (__thiscall* Destroy)(RefBase*); };
struct RefBase { RefOps* ops; long refs; };
struct Resource { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18; RefBase ref; };
struct RefHolder { Resource* object; ~RefHolder() { if(object) { RefBase* base=&object->ref; if(InterlockedDecrement(&base->refs)==0) base->ops->Destroy(base); } } };
struct FUN_00bce490 { virtual ~FUN_00bce490(); unsigned unk04,unk08,unk0c,unk10,unk14,unk18; };
struct FUN_005ea860 { unsigned unk00,unk04,unk08,unk0c; ~FUN_005ea860(); };
struct FUN_005c0ff0 { unsigned unk00; ~FUN_005c0ff0(); };
struct FUN_005ea970 : FUN_00bce490 { RefHolder first,second; FUN_005ea860 collection; FUN_005c0ff0 auxiliary; virtual ~FUN_005ea970(); };
// pdb: ObstacleTaskData::~ObstacleTaskData | NavMeshObstacleTask.obj | fnv360_0822_retail, call_seq, high
FUN_005ea970::~FUN_005ea970() {}
}
}   // namespace f3m_005ea970

// @f3 0x005e0330 (community match, verified in this file)
namespace f3m_005e0330 {
struct Owner5e03;
struct Table5e03 {int unk00;void* (__thiscall *allocate)(Owner5e03*,unsigned);};
struct Owner5e03 {Table5e03* unk00;void* unk04;unsigned unk08,unk0C;void FUN_005df930(unsigned,unsigned);unsigned FUN_005e0330();};
// pdb: BSSimpleArray<CombatSearchLocation,1024>::AddUninitialized | CombatGroup.obj | fnv360_0721_beta, call_seq, low
unsigned Owner5e03::FUN_005e0330(){if(unk08==unk0C){if(!unk0C){unk04=unk00->allocate(this,4);unk0C=4;}else{unsigned capacity=unk0C>0x400?unk0C+0x400:unk0C*2;FUN_005df930(capacity,unk08);unk0C=capacity;}}++unk08;return unk08-1;}
}   // namespace f3m_005e0330

// @f3 0x005f3b70 (community match, verified in this file)
namespace heap5f3b70 {struct Heap {void FUN_0086ba60(void*);};extern Heap DAT_01090a78;}
struct NavMeshTriHandle;
template<> class BSSimpleArray<NavMeshTriHandle,1024>;
typedef BSSimpleArray<NavMeshTriHandle,1024> Array5f3b70;
extern void (__thiscall* DAT_00e020e0)(Array5f3b70*,void*);
template<> class BSSimpleArray<NavMeshTriHandle,1024> {
public:
 virtual __forceinline ~BSSimpleArray() {if(buffer) {DAT_00e020e0(this,buffer);buffer=0;capacity=0;size=0;}}
 NavMeshTriHandle* buffer;unsigned int size;unsigned int capacity;
 Array5f3b70* FUN_005f3b70(unsigned int);
};
Array5f3b70* Array5f3b70::FUN_005f3b70(unsigned int flags) {
 this->BSSimpleArray::~BSSimpleArray();
 if(flags&1) heap5f3b70::DAT_01090a78.FUN_0086ba60(this);
 return this;
}

// @f3 0x005eaa60 (community match, verified in this file)
namespace f3m_005eaa60 {
namespace ConstructAa60 {
struct FUN_005fc3f0 { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24; FUN_005fc3f0(); static void* operator new(unsigned,void* p){return p;} static void operator delete(void*,void*); };
// pdb: BSSimpleArray<PathingLocation,1024>::AddUninitialized | PathBuilder.obj | fnv360_0721_beta, objrun_prop, low
void __stdcall FUN_005eaa60(FUN_005fc3f0* buffer,unsigned count) { for(unsigned i=0;i<count;++i) new (buffer+i) FUN_005fc3f0; }
}
}   // namespace f3m_005eaa60

// @f3 0x005eaae0 (community match, verified in this file)
namespace f3m_005eaae0 {
void* __cdecl FUN_00c01530(void*,const void*,unsigned);
struct Value5EAA {int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;int unk18;int unk1C;int unk20;int unk24;int unk28;int unk2C;};
// pdb: BSSimpleArray<VirtualPathingNode,1024>::_MoveItems | PathBuilder.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_005eaae0(Value5EAA* destination,const Value5EAA* source,unsigned count){if(count>0){if(destination<source){for(unsigned i=0;i<count;++i)FUN_00c01530(destination+i,source+i,sizeof(Value5EAA));}else if(destination>source){for(int i=count-1;i>=0;--i)FUN_00c01530(destination+i,source+i,sizeof(Value5EAA));}}}

}   // namespace f3m_005eaae0

// @f3 0x005fc8b0 (community match, verified in this file)
namespace f3m_005fc8b0 {
namespace match5fc8b0 {
struct Data {int unk00;int unk04;unsigned flags;
int unk0C;
int unk10;
int unk14;
int unk18;
int unk1C;
int unk20;
int unk24;
int unk28;
int unk2C;
int unk30;
int unk34;
int unk38;
int unk3C;
int unk40;
int unk44;
int unk48;
int unk4C;
int unk50;
void* member;bool Disabled(){return (flags>>4)&1;}
};
void FUN_005b87d0(void**,void*);
struct Owner {int unk00;int unk04;int unk08;int unk0C;Data* data;bool FUN_005fc8b0(void**);};
// pdb: PathingLocation::GetNavMesh | PathingLocation.obj | fnv360_0721_beta, caller, low, conflict (bridge: PathingLocation::HasNavMeshData)
// pdb params: aRetNavMesh
bool Owner::FUN_005fc8b0(void** result){if(data&&!data->Disabled()){FUN_005b87d0(result,data->member);if(*result)return true;return false;}return false;}
}
}   // namespace f3m_005fc8b0

// @f3 0x005f3870 (community match, verified in this file)
extern unsigned DAT_00e27ed4;
namespace f3m_005f3870 {
struct Alloc5f38 {void* ScrapHeap_Allocate(unsigned,unsigned);void ScrapHeap_Deallocate(void*);};
void* __cdecl FUN_00bffa60(void*,const void*,unsigned);
struct Array5f38 {void**table;void*data;unsigned size;unsigned capacity;Alloc5f38*allocator;void* FUN_005f3870(void*,unsigned);};
// pdb: BSScrapArray<OffsetData,1024>::_Reallocate | BGSReconstructFormsInAllFilesMap.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* Array5f38::FUN_005f3870(void*old,unsigned nextCapacity){void*next=allocator->ScrapHeap_Allocate(nextCapacity*8,DAT_00e27ed4);FUN_00bffa60(next,old,size*8);allocator->ScrapHeap_Deallocate(old);return next;}
}   // namespace f3m_005f3870

// @f3 0x005eb680 (community match, verified in this file)
namespace f3m_005eb680 {
namespace MatchEB6 {
struct Base;extern void* DAT_00e01eec;extern void* DAT_00dd8fd0;extern void (__stdcall* DAT_00e01ef4)(void*);extern void (__thiscall* DAT_00dd8fd8)(Base*,void*);
struct Base {void* table;void* data;unsigned count;unsigned capacity;~Base(){table=&DAT_00dd8fd0;if(data){DAT_00dd8fd8(this,data);data=0;capacity=0;count=0;}}};
struct Owner:Base {void FUN_005eb680();};
struct Cleanup {Base* object;Cleanup(Base* p):object(p){object->table=&DAT_00e01eec;}~Cleanup(){object->~Base();}};
// pdb: BSScrapArray<TESObjectREFR *,1024>::~BSScrapArray<TESObjectREFR *,1024> | PathBuilder.obj | fnv360_0822_debug, call_seq, medium
void Owner::FUN_005eb680(){Cleanup cleanup(this);if(data){DAT_00e01ef4(data);data=0;capacity=0;count=0;}}
}
}   // namespace f3m_005eb680

// @f3 0x005eab60 (community match, verified in this file)
namespace f3m_005eab60 {
struct Entry5eab60 {int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;int unk18;int unk1C;int unk20;int unk24;};
void* __cdecl FUN_00c01530(void*,const void*,unsigned);
// pdb: BSSimpleArray<PathingLocation,1024>::_ReallocateBuffer | PathBuilder.obj | fnv360_0822_retail, call_seq, low
// pdb params: aiNewSize, aiCopyCount
void __stdcall FUN_005eab60(Entry5eab60* dest,Entry5eab60* src,unsigned count){if(count>0){if(dest<src){for(unsigned i=0;i<count;++i)FUN_00c01530(&dest[i],&src[i],40);}else if(dest>src){for(int i=count-1;i>=0;--i)FUN_00c01530(&dest[i],&src[i],40);}}}
}   // namespace f3m_005eab60

// @f3 0x005eac40 (community match, verified in this file)
namespace f3m_005eac40 {
void* __cdecl FUN_00c01530(void*,const void*,unsigned);
// pdb: BSSimpleArray<char,1024>::_MoveItems | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_005eac40(unsigned char* destination,const unsigned char* source,unsigned count){if(count>0){if(destination<source){for(unsigned i=0;i<count;++i)FUN_00c01530(destination+i,source+i,1);}else if(destination>source){for(int i=count-1;i>=0;--i)FUN_00c01530(destination+i,source+i,1);}}}
}   // namespace f3m_005eac40

// @f3 0x005f24e0 (community match, verified in this file)
namespace f3m_005f24e0 {
class Array5f24e0 {
public:
    virtual void Unk00();
    virtual void* Allocate(unsigned int capacity);
    virtual void Free(void* data);
    virtual void* Reallocate(void* data, unsigned int capacity);
    void* data;            // +0x04
    unsigned int count;    // +0x08
    unsigned int capacity; // +0x0c
    void FUN_005f13e0(void* destination, void* source, unsigned int count);
    void FUN_005f24e0(unsigned int newCapacity, unsigned int oldCount);
};
// pdb: BSSimpleArray<PathingCoverLocation,1024>::_ReallocateBuffer | Pathfind.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiNewSize, aiCopyCount
void Array5f24e0::FUN_005f24e0(unsigned int newCapacity, unsigned int oldCount) {
    if (data) {
        if (oldCount == capacity) {
            data = Reallocate(data, newCapacity);
        } else {
            void* newData = Allocate(newCapacity);
            FUN_005f13e0(newData, data, oldCount);
            Free(data);
            data = newData;
        }
    } else {
        data = Allocate(newCapacity);
        capacity = newCapacity;
    }
}
}   // namespace f3m_005f24e0

// @f3 0x005ebb20 (community match, verified in this file)
namespace f3m_005ebb20 {
// pdb: BSScrapArray<FastNavMeshTriHandle,1024>::~BSScrapArray<FastNavMeshTriHandle,1024> | PathBuilder.obj | fnv360_0822_debug, call_seq, medium
namespace N5EBB {struct Owner;extern int DAT_00e01f28,DAT_00e01eb0;extern void (__stdcall *DAT_00e01f30)(void*);extern void (__thiscall *DAT_00e01eb8)(Owner*,void*);struct Owner{void* vtable;void* data;unsigned size,capacity;__forceinline void ClearBase(){vtable=&DAT_00e01eb0;if(data){DAT_00e01eb8(this,data);data=0;capacity=0;size=0;}}void FUN_005ebb20();};struct Guard{Owner* owner;Guard(Owner* p):owner(p){p->vtable=&DAT_00e01f28;}~Guard(){owner->ClearBase();}};void Owner::FUN_005ebb20(){Guard cleanup(this);if(data){DAT_00e01f30(data);data=0;capacity=0;size=0;}}}
}   // namespace f3m_005ebb20

// @f3 0x005f2550 (community match, verified in this file)
namespace f3m_005f2550 {
struct Array5f255 {void**table;void*data;unsigned size;unsigned capacity;void FUN_005f24e0(unsigned,unsigned);unsigned FUN_005f2550();};
// pdb: BSSimpleArray<PathingCoverLocation,1024>::AddUninitialized | Pathfind.obj | fnv360_0822_retail, call_gap, low
unsigned Array5f255::FUN_005f2550(){if(size==capacity){if(!capacity){data=((void*(__thiscall*)(Array5f255*,unsigned))table[1])(this,4);capacity=4;}else{unsigned next=capacity>1024?capacity+1024:capacity*2;FUN_005f24e0(next,size);capacity=next;}}++size;return size-1;}
}   // namespace f3m_005f2550

// @f3 0x005f1100 (community match, verified in this file)
namespace f3m_005f1100 {
namespace match5f1100 {
struct Vector {int x,y,z;Vector(const Vector& other):x(other.x),y(other.y),z(other.z){}};
struct Owner {
int unk0000; int unk0004; int unk0008; int unk000C;
int unk0010; int unk0014; int unk0018; int unk001C;
int unk0020; int unk0024; int unk0028; int unk002C;
int unk0030; int unk0034; int unk0038; int unk003C;
int unk0040; int unk0044; int unk0048; int unk004C;
int unk0050; int unk0054; int unk0058; int unk005C;
int unk0060; int unk0064; int unk0068; int unk006C;
int unk0070; int unk0074; int unk0078; int unk007C;
int unk0080; int unk0084; int unk0088; int unk008C;
int unk0090; int unk0094; int unk0098; int unk009C;
int unk00A0; int unk00A4; int unk00A8; int unk00AC;
int unk00B0; int unk00B4; int unk00B8; int unk00BC;
int unk00C0; int unk00C4; int unk00C8; int unk00CC;
int unk00D0; int unk00D4; int unk00D8; int unk00DC;
int unk00E0; int unk00E4; int unk00E8; int unk00EC;
int unk00F0; int unk00F4; int unk00F8; int unk00FC;
int unk0100; int unk0104; int unk0108; int unk010C;
int unk0110; int unk0114; int unk0118; int unk011C;
int unk0120; int unk0124; int unk0128; int unk012C;
int unk0130; int unk0134; int unk0138; int unk013C;
int unk0140; int unk0144; int unk0148; int unk014C;
int unk0150; int unk0154; int unk0158; int unk015C;
int unk0160; int unk0164; int unk0168; int unk016C;
int unk0170; int unk0174; int unk0178; int unk017C;
int unk0180; int unk0184; int unk0188; int unk018C;
int unk0190; int unk0194; int unk0198; int unk019C;
int unk01A0; int unk01A4; int unk01A8; int unk01AC;
int unk01B0; int unk01B4; int unk01B8; int unk01BC;
int unk01C0; int unk01C4; int unk01C8; int unk01CC;
int unk01D0; int unk01D4; int unk01D8; int unk01DC;
int unk01E0; int unk01E4; int unk01E8; int unk01EC;
int unk01F0; int unk01F4; int unk01F8; int unk01FC;
int unk0200; int unk0204; int unk0208; int unk020C;
int unk0210; int unk0214; int unk0218; int unk021C;
int unk0220; int unk0224; int unk0228; int unk022C;
int unk0230; int unk0234; int unk0238; int unk023C;
int unk0240; int unk0244; int unk0248; int unk024C;
int unk0250; int unk0254; int unk0258; int unk025C;
int unk0260; int unk0264; int unk0268; int unk026C;
int unk0270; int unk0274; int unk0278; int unk027C;
int unk0280; int unk0284; int unk0288; int unk028C;
int unk0290; int unk0294; int unk0298; int unk029C;
int unk02A0; int unk02A4; int unk02A8; int unk02AC;
int unk02B0; int unk02B4; int unk02B8; int unk02BC;
int unk02C0; int unk02C4; int unk02C8; int unk02CC;
int unk02D0; int unk02D4; int unk02D8; int unk02DC;
int unk02E0; int unk02E4; int unk02E8; int unk02EC;
int unk02F0; int unk02F4; int unk02F8; int unk02FC;
int unk0300; int unk0304; int unk0308; int unk030C;
int unk0310; int unk0314; int unk0318; int unk031C;
int unk0320; int unk0324; int unk0328; int unk032C;
int unk0330; int unk0334; int unk0338; int unk033C;
int unk0340; int unk0344; int unk0348; int unk034C;
int unk0350; int unk0354; int unk0358; int unk035C;
int unk0360; int unk0364; int unk0368; int unk036C;
int unk0370; int unk0374; int unk0378; int unk037C;
int unk0380; int unk0384; int unk0388; int unk038C;
int unk0390; int unk0394; int unk0398; int unk039C;
int unk03A0; int unk03A4; int unk03A8; int unk03AC;
int unk03B0; int unk03B4; int unk03B8; int unk03BC;
int unk03C0; int unk03C4; int unk03C8; int unk03CC;
int unk03D0; int unk03D4; int unk03D8; int unk03DC;
int unk03E0; int unk03E4; int unk03E8; int unk03EC;
int unk03F0; int unk03F4; int unk03F8; int unk03FC;
int unk0400; int unk0404; int unk0408; int unk040C;
int unk0410; int unk0414; int unk0418; int unk041C;
int unk0420; int unk0424; int unk0428; int unk042C;
int unk0430; int unk0434; int unk0438; int unk043C;
int unk0440; int unk0444; int unk0448; int unk044C;
int unk0450; int unk0454; int unk0458; int unk045C;
int unk0460; int unk0464; int unk0468; int unk046C;
int unk0470; int unk0474; int unk0478; int unk047C;
int unk0480; int unk0484; int unk0488; int unk048C;
int unk0490; int unk0494; int unk0498; int unk049C;
int unk04A0; int unk04A4; int unk04A8; int unk04AC;
int unk04B0; int unk04B4; int unk04B8; int unk04BC;
int unk04C0; int unk04C4; int unk04C8; int unk04CC;
int unk04D0; int unk04D4; int unk04D8; int unk04DC;
int unk04E0; int unk04E4; int unk04E8; int unk04EC;
int unk04F0; int unk04F4; int unk04F8; int unk04FC;
int unk0500; int unk0504; int unk0508; int unk050C;
int unk0510; int unk0514; int unk0518; int unk051C;
int unk0520; int unk0524; int unk0528; int unk052C;
int unk0530; int unk0534; int unk0538; int unk053C;
int unk0540; int unk0544; int unk0548; int unk054C;
int unk0550; int unk0554; int unk0558; int unk055C;
int unk0560; int unk0564; int unk0568; int unk056C;
int unk0570; int unk0574; int unk0578; int unk057C;
int unk0580; int unk0584; int unk0588; int unk058C;
int unk0590; int unk0594; int unk0598; int unk059C;
int unk05A0; int unk05A4; int unk05A8; int unk05AC;
int unk05B0; int unk05B4; int unk05B8; int unk05BC;
int unk05C0; int unk05C4; int unk05C8; int unk05CC;
int unk05D0; int unk05D4; int unk05D8; int unk05DC;
int unk05E0; int unk05E4; int unk05E8; int unk05EC;
int unk05F0; int unk05F4; int unk05F8; int unk05FC;
int unk0600; int unk0604; int unk0608; int unk060C;
int unk0610; int unk0614; int unk0618; int unk061C;
int unk0620; int unk0624; int unk0628; int unk062C;
int unk0630; int unk0634; int unk0638; int unk063C;
int unk0640; int unk0644; int unk0648; int unk064C;
int unk0650; int unk0654; int unk0658; int unk065C;
int unk0660; int unk0664; int unk0668; int unk066C;
int unk0670; int unk0674; int unk0678; int unk067C;
int unk0680; int unk0684; int unk0688; int unk068C;
int unk0690; int unk0694; int unk0698; int unk069C;
int unk06A0; int unk06A4; int unk06A8; int unk06AC;
int unk06B0; int unk06B4; int unk06B8; int unk06BC;
int unk06C0; int unk06C4; int unk06C8; int unk06CC;
int unk06D0; int unk06D4; int unk06D8; int unk06DC;
int unk06E0; int unk06E4; int unk06E8; int unk06EC;
int unk06F0; int unk06F4; int unk06F8; int unk06FC;
int unk0700; int unk0704; int unk0708; int unk070C;
int unk0710; int unk0714; int unk0718; int unk071C;
int unk0720; int unk0724; int unk0728; int unk072C;
int unk0730; int unk0734; int unk0738; int unk073C;
int unk0740; int unk0744; int unk0748; int unk074C;
int unk0750; int unk0754; int unk0758; int unk075C;
int unk0760; int unk0764; int unk0768; int unk076C;
int unk0770; int unk0774; int unk0778; int unk077C;
int unk0780; int unk0784; int unk0788; int unk078C;
int unk0790; int unk0794; int unk0798; int unk079C;
int unk07A0; int unk07A4; int unk07A8; int unk07AC;
int unk07B0; int unk07B4; int unk07B8; int unk07BC;
int unk07C0; int unk07C4; int unk07C8; int unk07CC;
int unk07D0; int unk07D4; int unk07D8; int unk07DC;
int unk07E0; int unk07E4; int unk07E8; int unk07EC;
int unk07F0; int unk07F4; int unk07F8; int unk07FC;
int unk0800; int unk0804; int unk0808; int unk080C;
int unk0810; int unk0814; int unk0818; int unk081C;
int unk0820; int unk0824; int unk0828; int unk082C;
int unk0830; int unk0834; int unk0838; int unk083C;
int unk0840; int unk0844; int unk0848; int unk084C;
int unk0850; int unk0854; int unk0858; int unk085C;
int unk0860; int unk0864; int unk0868; int unk086C;
int unk0870; int unk0874; int unk0878; int unk087C;
int unk0880; int unk0884; int unk0888; int unk088C;
int unk0890; int unk0894; int unk0898; int unk089C;
int unk08A0; int unk08A4; int unk08A8; int unk08AC;
int unk08B0; int unk08B4; int unk08B8; int unk08BC;
int unk08C0; int unk08C4; int unk08C8; int unk08CC;
int unk08D0; int unk08D4; int unk08D8; int unk08DC;
int unk08E0; int unk08E4; int unk08E8; int unk08EC;
int unk08F0; int unk08F4; int unk08F8; int unk08FC;
int unk0900; int unk0904; int unk0908; int unk090C;
int unk0910; int unk0914; int unk0918; int unk091C;
int unk0920; int unk0924; int unk0928; int unk092C;
int unk0930; int unk0934; int unk0938; int unk093C;
int unk0940; int unk0944; int unk0948; int unk094C;
int unk0950; int unk0954; int unk0958; int unk095C;
int unk0960; int unk0964; int unk0968; int unk096C;
int unk0970; int unk0974; int unk0978; int unk097C;
int unk0980; int unk0984; int unk0988; int unk098C;
int unk0990; int unk0994; int unk0998; int unk099C;
int unk09A0; int unk09A4; int unk09A8; int unk09AC;
int unk09B0; int unk09B4; int unk09B8; int unk09BC;
int unk09C0; int unk09C4; int unk09C8; int unk09CC;
int unk09D0; int unk09D4; int unk09D8; int unk09DC;
int unk09E0; int unk09E4; int unk09E8; int unk09EC;
int unk09F0; int unk09F4; int unk09F8; int unk09FC;
int unk0A00; int unk0A04; int unk0A08; int unk0A0C;
int unk0A10; int unk0A14; int unk0A18; int unk0A1C;
int unk0A20; int unk0A24; int unk0A28; int unk0A2C;
int unk0A30; int unk0A34; int unk0A38; int unk0A3C;
int unk0A40; int unk0A44; int unk0A48; int unk0A4C;
int unk0A50; int unk0A54; int unk0A58; int unk0A5C;
int unk0A60; int unk0A64; int unk0A68; int unk0A6C;
int unk0A70; int unk0A74; int unk0A78; int unk0A7C;
int unk0A80; int unk0A84; int unk0A88; int unk0A8C;
int unk0A90; int unk0A94; int unk0A98; int unk0A9C;
int unk0AA0; int unk0AA4; int unk0AA8; int unk0AAC;
int unk0AB0; int unk0AB4; int unk0AB8; int unk0ABC;
int unk0AC0; int unk0AC4; int unk0AC8; int unk0ACC;
int unk0AD0; int unk0AD4; int unk0AD8; int unk0ADC;
int unk0AE0; int unk0AE4; int unk0AE8; int unk0AEC;
int unk0AF0; int unk0AF4; int unk0AF8; int unk0AFC;
int unk0B00; int unk0B04; int unk0B08; int unk0B0C;
int unk0B10; int unk0B14; int unk0B18; int unk0B1C;
int unk0B20; int unk0B24; int unk0B28; int unk0B2C;
int unk0B30; int unk0B34; int unk0B38; int unk0B3C;
int unk0B40; int unk0B44; int unk0B48; int unk0B4C;
int unk0B50; int unk0B54; int unk0B58; int unk0B5C;
int unk0B60; int unk0B64; int unk0B68; int unk0B6C;
int unk0B70; int unk0B74; int unk0B78; int unk0B7C;
int unk0B80; int unk0B84; int unk0B88; int unk0B8C;
int unk0B90; int unk0B94; int unk0B98; int unk0B9C;
int unk0BA0; int unk0BA4; int unk0BA8; int unk0BAC;
int unk0BB0; int unk0BB4; int unk0BB8; int unk0BBC;
int unk0BC0; int unk0BC4; int unk0BC8; int unk0BCC;
int unk0BD0; int unk0BD4; int unk0BD8; int unk0BDC;
int unk0BE0; int unk0BE4; int unk0BE8; int unk0BEC;
int unk0BF0; int unk0BF4; int unk0BF8; int unk0BFC;
int unk0C00; int unk0C04; int unk0C08; int unk0C0C;
int unk0C10; int unk0C14; int unk0C18; int unk0C1C;
int unk0C20; int unk0C24; int unk0C28; int unk0C2C;
int unk0C30; int unk0C34; int unk0C38; int unk0C3C;
int unk0C40; int unk0C44; int unk0C48; int unk0C4C;
int unk0C50; int unk0C54; int unk0C58; int unk0C5C;
int unk0C60; int unk0C64; int unk0C68; int unk0C6C;
int unk0C70; int unk0C74; int unk0C78; int unk0C7C;
int unk0C80; int unk0C84; int unk0C88; int unk0C8C;
int unk0C90; int unk0C94; int unk0C98; int unk0C9C;
int unk0CA0; int unk0CA4; int unk0CA8; int unk0CAC;
int unk0CB0; int unk0CB4; int unk0CB8; int unk0CBC;
int unk0CC0; int unk0CC4; int unk0CC8; int unk0CCC;
int unk0CD0; int unk0CD4; int unk0CD8; int unk0CDC;
int unk0CE0; int unk0CE4; int unk0CE8; int unk0CEC;
int unk0CF0; int unk0CF4; int unk0CF8; int unk0CFC;
int unk0D00; int unk0D04; int unk0D08; int unk0D0C;
int unk0D10; int unk0D14; int unk0D18; int unk0D1C;
int unk0D20; int unk0D24; int unk0D28; int unk0D2C;
int unk0D30; int unk0D34; int unk0D38; int unk0D3C;
int unk0D40; int unk0D44; int unk0D48; int unk0D4C;
int unk0D50; int unk0D54; int unk0D58; int unk0D5C;
int unk0D60; int unk0D64; int unk0D68; int unk0D6C;
int unk0D70; int unk0D74; int unk0D78; int unk0D7C;
int unk0D80; int unk0D84; int unk0D88; int unk0D8C;
int unk0D90; int unk0D94; int unk0D98; int unk0D9C;
int unk0DA0; int unk0DA4; int unk0DA8; int unk0DAC;
int unk0DB0; int unk0DB4; int unk0DB8; int unk0DBC;
int unk0DC0; int unk0DC4; int unk0DC8; int unk0DCC;
int unk0DD0; int unk0DD4; int unk0DD8; int unk0DDC;
int unk0DE0; int unk0DE4; int unk0DE8; int unk0DEC;
int unk0DF0; int unk0DF4; int unk0DF8; int unk0DFC;
int unk0E00; int unk0E04; int unk0E08; int unk0E0C;
int unk0E10; int unk0E14; int unk0E18; int unk0E1C;
int unk0E20; int unk0E24; int unk0E28; int unk0E2C;
int unk0E30; int unk0E34; int unk0E38; int unk0E3C;
int unk0E40; int unk0E44; int unk0E48; int unk0E4C;
int unk0E50; int unk0E54; int unk0E58; int unk0E5C;
int unk0E60; int unk0E64; int unk0E68; int unk0E6C;
int unk0E70; int unk0E74; int unk0E78; int unk0E7C;
int unk0E80; int unk0E84; int unk0E88; int unk0E8C;
int unk0E90; int unk0E94; int unk0E98; int unk0E9C;
int unk0EA0; int unk0EA4; int unk0EA8; int unk0EAC;
int unk0EB0; int unk0EB4; int unk0EB8; int unk0EBC;
int unk0EC0; int unk0EC4; int unk0EC8; int unk0ECC;
int unk0ED0; int unk0ED4; int unk0ED8; int unk0EDC;
int unk0EE0; int unk0EE4; int unk0EE8; int unk0EEC;
int unk0EF0; int unk0EF4; int unk0EF8; int unk0EFC;
int unk0F00; int unk0F04; int unk0F08; int unk0F0C;
int unk0F10; int unk0F14; int unk0F18; int unk0F1C;
int unk0F20; int unk0F24; int unk0F28; int unk0F2C;
int unk0F30; int unk0F34; int unk0F38; int unk0F3C;
int unk0F40; int unk0F44; int unk0F48; int unk0F4C;
int unk0F50; int unk0F54; int unk0F58; int unk0F5C;
int unk0F60; int unk0F64; int unk0F68; int unk0F6C;
int unk0F70; int unk0F74; int unk0F78; int unk0F7C;
int unk0F80; int unk0F84; int unk0F88; int unk0F8C;
int unk0F90; int unk0F94; int unk0F98; int unk0F9C;
int unk0FA0; int unk0FA4; int unk0FA8; int unk0FAC;
int unk0FB0; int unk0FB4; int unk0FB8; int unk0FBC;
int unk0FC0; int unk0FC4; int unk0FC8; int unk0FCC;
int unk0FD0; int unk0FD4; int unk0FD8; int unk0FDC;
int unk0FE0; int unk0FE4; int unk0FE8; int unk0FEC;
int unk0FF0; int unk0FF4; int unk0FF8; int unk0FFC;
int unk1000; int unk1004; int unk1008; int unk100C;
int unk1010; int unk1014; int unk1018; int unk101C;
int unk1020; int unk1024; int unk1028; int unk102C;
int unk1030; int unk1034; int unk1038; int unk103C;
int unk1040; int unk1044; int unk1048; int unk104C;
int unk1050; int unk1054; int unk1058; int unk105C;
int unk1060; int unk1064; int unk1068; int unk106C;
int unk1070; int unk1074; int unk1078; int unk107C;
int unk1080; int unk1084; int unk1088; int unk108C;
int unk1090; int unk1094; int unk1098; int unk109C;
int unk10A0; int unk10A4; int unk10A8; int unk10AC;
int unk10B0; int unk10B4; int unk10B8; int unk10BC;
int unk10C0; int unk10C4; int unk10C8; int unk10CC;
int unk10D0; int unk10D4; int unk10D8; int unk10DC;
int unk10E0; int unk10E4; int unk10E8; int unk10EC;
int unk10F0; int unk10F4; int unk10F8; int unk10FC;
int unk1100; int unk1104; int unk1108; int unk110C;
int unk1110; int unk1114; int unk1118; int unk111C;
int unk1120; int unk1124; int unk1128; int unk112C;
int unk1130; int unk1134; int unk1138; int unk113C;
int unk1140; int unk1144; int unk1148; int unk114C;
int unk1150; int unk1154; int unk1158; int unk115C;
int unk1160; int unk1164; int unk1168; int unk116C;
int unk1170; int unk1174; int unk1178; int unk117C;
int unk1180; int unk1184; int unk1188; int unk118C;
int unk1190; int unk1194; int unk1198; int unk119C;
int unk11A0; int unk11A4; int unk11A8; int unk11AC;
int unk11B0; int unk11B4; int unk11B8; int unk11BC;
int unk11C0; int unk11C4; int unk11C8; int unk11CC;
int unk11D0; int unk11D4; int unk11D8; int unk11DC;
int unk11E0; int unk11E4; int unk11E8; int unk11EC;
int unk11F0; int unk11F4; int unk11F8; int unk11FC;
int unk1200; int unk1204; int unk1208; int unk120C;
int unk1210; int unk1214; int unk1218; int unk121C;
int unk1220; int unk1224; int unk1228; int unk122C;
int unk1230; int unk1234; int unk1238; int unk123C;
int unk1240; int unk1244; int unk1248; int unk124C;
int unk1250; int unk1254; int unk1258; int unk125C;
int unk1260; int unk1264; int unk1268; int unk126C;
int unk1270; int unk1274; int unk1278; int unk127C;
int unk1280; int unk1284; int unk1288; int unk128C;
int unk1290; int unk1294; int unk1298; int unk129C;
int unk12A0; int unk12A4; int unk12A8; int unk12AC;
int unk12B0; int unk12B4; int unk12B8; int unk12BC;
int unk12C0; int unk12C4; int unk12C8; int unk12CC;
int unk12D0; int unk12D4; int unk12D8; int unk12DC;
int unk12E0; int unk12E4; int unk12E8; int unk12EC;
int unk12F0; int unk12F4; int unk12F8; int unk12FC;
int unk1300; int unk1304; int unk1308; int unk130C;
int unk1310; int unk1314; int unk1318; int unk131C;
int unk1320; int unk1324; int unk1328; int unk132C;
int unk1330; int unk1334; int unk1338; int unk133C;
int unk1340; int unk1344; int unk1348; int unk134C;
int unk1350; int unk1354; int unk1358; int unk135C;
int unk1360; int unk1364; int unk1368; int unk136C;
int unk1370; int unk1374; int unk1378; int unk137C;
int unk1380; int unk1384; int unk1388; int unk138C;
int unk1390; int unk1394; int unk1398; int unk139C;
int unk13A0; int unk13A4; int unk13A8; int unk13AC;
int unk13B0; int unk13B4; int unk13B8; int unk13BC;
int unk13C0; int unk13C4; int unk13C8; int unk13CC;
int unk13D0; int unk13D4; int unk13D8; int unk13DC;
int unk13E0; int unk13E4; int unk13E8; int unk13EC;
int unk13F0; int unk13F4; int unk13F8; int unk13FC;
int unk1400; int unk1404; int unk1408; int unk140C;
int unk1410; int unk1414; int unk1418; int unk141C;
int unk1420; int unk1424; int unk1428; int unk142C;
int unk1430; int unk1434; int unk1438; int unk143C;
int unk1440; int unk1444; int unk1448; int unk144C;
int unk1450; int unk1454; int unk1458; int unk145C;
int unk1460; int unk1464; int unk1468; int unk146C;
int unk1470; int unk1474; int unk1478; int unk147C;
int unk1480; int unk1484; int unk1488; int unk148C;
int unk1490; int unk1494; int unk1498; int unk149C;
int unk14A0; int unk14A4; int unk14A8; int unk14AC;
int unk14B0; int unk14B4; int unk14B8; int unk14BC;
int unk14C0; int unk14C4; int unk14C8; int unk14CC;
int unk14D0; int unk14D4; int unk14D8; int unk14DC;
int unk14E0; int unk14E4; int unk14E8; int unk14EC;
int unk14F0; int unk14F4; int unk14F8; int unk14FC;
int unk1500; int unk1504; int unk1508; int unk150C;
int unk1510; int unk1514; int unk1518; int unk151C;
int unk1520; int unk1524; int unk1528; int unk152C;
int unk1530; int unk1534; int unk1538; int unk153C;
int unk1540; int unk1544; int unk1548; int unk154C;
int unk1550; int unk1554; int unk1558; int unk155C;
int unk1560; int unk1564; int unk1568; int unk156C;
int unk1570; int unk1574; int unk1578; int unk157C;
int unk1580; int unk1584; int unk1588; int unk158C;
int unk1590; int unk1594; int unk1598; int unk159C;
int unk15A0; int unk15A4; int unk15A8; int unk15AC;
int unk15B0; int unk15B4; int unk15B8; int unk15BC;
int unk15C0; int unk15C4; int unk15C8; int unk15CC;
int unk15D0; int unk15D4; int unk15D8; int unk15DC;
int unk15E0; int unk15E4; int unk15E8; int unk15EC;
int unk15F0; int unk15F4; int unk15F8; int unk15FC;
int unk1600; int unk1604; int unk1608; int unk160C;
int unk1610; int unk1614; int unk1618; int unk161C;
int unk1620; int unk1624; int unk1628; int unk162C;
int unk1630; int unk1634; int unk1638; int unk163C;
int unk1640; int unk1644; int unk1648; int unk164C;
int unk1650; int unk1654; int unk1658; int unk165C;
int unk1660; int unk1664; int unk1668; int unk166C;
int unk1670; int unk1674; int unk1678; int unk167C;
int unk1680; int unk1684; int unk1688; int unk168C;
int unk1690; int unk1694; int unk1698; int unk169C;
int unk16A0; int unk16A4; int unk16A8; int unk16AC;
int unk16B0; int unk16B4; int unk16B8; int unk16BC;
int unk16C0; int unk16C4; int unk16C8; int unk16CC;
int unk16D0; int unk16D4; int unk16D8; int unk16DC;
int unk16E0; int unk16E4; int unk16E8; int unk16EC;
int unk16F0; int unk16F4; int unk16F8; int unk16FC;
int unk1700; int unk1704; int unk1708; int unk170C;
int unk1710; int unk1714; int unk1718; int unk171C;
int unk1720; int unk1724; int unk1728; int unk172C;
int unk1730; int unk1734; int unk1738; int unk173C;
int unk1740; int unk1744; int unk1748; int unk174C;
int unk1750; int unk1754; int unk1758; int unk175C;
int unk1760; int unk1764; int unk1768; int unk176C;
int unk1770; int unk1774; int unk1778; int unk177C;
int unk1780; int unk1784; int unk1788; int unk178C;
int unk1790; int unk1794; int unk1798; int unk179C;
int unk17A0; int unk17A4; int unk17A8; int unk17AC;
int unk17B0; int unk17B4; int unk17B8; int unk17BC;
int unk17C0; int unk17C4; int unk17C8; int unk17CC;
int unk17D0; int unk17D4; int unk17D8; int unk17DC;
int unk17E0; int unk17E4; int unk17E8; int unk17EC;
int unk17F0; int unk17F4; int unk17F8; int unk17FC;
int unk1800; int unk1804; int unk1808; int unk180C;
int unk1810; int unk1814; int unk1818; int unk181C;
int unk1820; int unk1824; int unk1828; int unk182C;
int unk1830; int unk1834; int unk1838; int unk183C;
int unk1840; int unk1844; int unk1848; int unk184C;
int unk1850; int unk1854; int unk1858; int unk185C;
int unk1860; int unk1864; int unk1868; int unk186C;
int unk1870; int unk1874; int unk1878; int unk187C;
int unk1880; int unk1884; int unk1888; int unk188C;
int unk1890; int unk1894; int unk1898; int unk189C;
int unk18A0; int unk18A4; int unk18A8; int unk18AC;
int unk18B0; int unk18B4; int unk18B8; int unk18BC;
int unk18C0; int unk18C4; int unk18C8; int unk18CC;
int unk18D0; int unk18D4; int unk18D8; int unk18DC;
int unk18E0; int unk18E4; int unk18E8; int unk18EC;
int unk18F0; int unk18F4; int unk18F8; int unk18FC;
int unk1900; int unk1904; int unk1908; int unk190C;
int unk1910; int unk1914; int unk1918; int unk191C;
int unk1920; int unk1924; int unk1928; int unk192C;
int unk1930; int unk1934; int unk1938; int unk193C;
int unk1940; int unk1944; int unk1948; int unk194C;
int unk1950; int unk1954; int unk1958; int unk195C;
int unk1960; int unk1964; int unk1968; int unk196C;
int unk1970; int unk1974; int unk1978; int unk197C;
int unk1980; int unk1984; int unk1988; int unk198C;
int unk1990; int unk1994; int unk1998; int unk199C;
int unk19A0; int unk19A4; int unk19A8; int unk19AC;
int unk19B0; int unk19B4; int unk19B8; int unk19BC;
int unk19C0; int unk19C4; int unk19C8; int unk19CC;
int unk19D0; int unk19D4; int unk19D8; int unk19DC;
int unk19E0; int unk19E4; int unk19E8; int unk19EC;
int unk19F0; int unk19F4; int unk19F8; int unk19FC;
int unk1A00; int unk1A04; int unk1A08; int unk1A0C;
int unk1A10; int unk1A14; int unk1A18; int unk1A1C;
int unk1A20; int unk1A24; int unk1A28; int unk1A2C;
int unk1A30; int unk1A34; int unk1A38; int unk1A3C;
int unk1A40; int unk1A44; int unk1A48; int unk1A4C;
int unk1A50; int unk1A54; int unk1A58; int unk1A5C;
int unk1A60; int unk1A64; int unk1A68; int unk1A6C;
int unk1A70; int unk1A74; int unk1A78; int unk1A7C;
int unk1A80; int unk1A84; int unk1A88; int unk1A8C;
int unk1A90; int unk1A94; int unk1A98; int unk1A9C;
int unk1AA0; int unk1AA4; int unk1AA8; int unk1AAC;
int unk1AB0; int unk1AB4; int unk1AB8; int unk1ABC;
int unk1AC0; int unk1AC4; int unk1AC8; int unk1ACC;
int unk1AD0; int unk1AD4; int unk1AD8; int unk1ADC;
int unk1AE0; int unk1AE4; int unk1AE8; int unk1AEC;
int unk1AF0; int unk1AF4; int unk1AF8; int unk1AFC;
int unk1B00; int unk1B04; int unk1B08; int unk1B0C;
int unk1B10; int unk1B14; int unk1B18; int unk1B1C;
int unk1B20; int unk1B24; int unk1B28; int unk1B2C;
int unk1B30; int unk1B34; int unk1B38; int unk1B3C;
int unk1B40; int unk1B44; int unk1B48; int unk1B4C;
int unk1B50; int unk1B54; int unk1B58; int unk1B5C;
int unk1B60; int unk1B64; int unk1B68; int unk1B6C;
int unk1B70; int unk1B74; int unk1B78; int unk1B7C;
int unk1B80; int unk1B84; int unk1B88; int unk1B8C;
int unk1B90; int unk1B94; int unk1B98; int unk1B9C;
int unk1BA0; int unk1BA4; int unk1BA8; int unk1BAC;
int unk1BB0; int unk1BB4; int unk1BB8; int unk1BBC;
int unk1BC0; int unk1BC4; int unk1BC8; int unk1BCC;
int unk1BD0; int unk1BD4; int unk1BD8; int unk1BDC;
int unk1BE0; int unk1BE4; int unk1BE8; int unk1BEC;
int unk1BF0; int unk1BF4; int unk1BF8; int unk1BFC;
int unk1C00; int unk1C04; int unk1C08; int unk1C0C;
int unk1C10; int unk1C14; int unk1C18; int unk1C1C;
int unk1C20; int unk1C24; int unk1C28; int unk1C2C;
int unk1C30; int unk1C34; int unk1C38; int unk1C3C;
int unk1C40; int unk1C44; int unk1C48; int unk1C4C;
int unk1C50; int unk1C54; int unk1C58; int unk1C5C;
int unk1C60; int unk1C64; int unk1C68; int unk1C6C;
int unk1C70; int unk1C74; int unk1C78; int unk1C7C;
int unk1C80; int unk1C84; int unk1C88; int unk1C8C;
int unk1C90; int unk1C94; int unk1C98; int unk1C9C;
int unk1CA0; int unk1CA4; int unk1CA8; int unk1CAC;
int unk1CB0; int unk1CB4; int unk1CB8; int unk1CBC;
int unk1CC0; int unk1CC4; int unk1CC8; int unk1CCC;
int unk1CD0; int unk1CD4; int unk1CD8; int unk1CDC;
int unk1CE0; int unk1CE4; int unk1CE8; int unk1CEC;
int unk1CF0; int unk1CF4; int unk1CF8; int unk1CFC;
int unk1D00; int unk1D04; int unk1D08; int unk1D0C;
int unk1D10; int unk1D14; int unk1D18; int unk1D1C;
int unk1D20; int unk1D24; int unk1D28; int unk1D2C;
int unk1D30; int unk1D34; int unk1D38; int unk1D3C;
int unk1D40; int unk1D44; int unk1D48; int unk1D4C;
int unk1D50; int unk1D54; int unk1D58; int unk1D5C;
int unk1D60; int unk1D64; int unk1D68; int unk1D6C;
int unk1D70; int unk1D74; int unk1D78; int unk1D7C;
int unk1D80; int unk1D84; int unk1D88; int unk1D8C;
int unk1D90; int unk1D94; int unk1D98; int unk1D9C;
int unk1DA0; int unk1DA4; int unk1DA8; int unk1DAC;
int unk1DB0; int unk1DB4; int unk1DB8; int unk1DBC;
int unk1DC0; int unk1DC4; int unk1DC8; int unk1DCC;
int unk1DD0; int unk1DD4; int unk1DD8; int unk1DDC;
int unk1DE0; int unk1DE4; int unk1DE8; int unk1DEC;
int unk1DF0; int unk1DF4; int unk1DF8; int unk1DFC;
int unk1E00; int unk1E04; int unk1E08; int unk1E0C;
int unk1E10; int unk1E14; int unk1E18; int unk1E1C;
int unk1E20; int unk1E24; int unk1E28; int unk1E2C;
int unk1E30; int unk1E34; int unk1E38; int unk1E3C;
int unk1E40; int unk1E44; int unk1E48; int unk1E4C;
int unk1E50; int unk1E54; int unk1E58; int unk1E5C;
int unk1E60; int unk1E64; int unk1E68; int unk1E6C;
int unk1E70; int unk1E74; int unk1E78; int unk1E7C;
int unk1E80; int unk1E84; int unk1E88; int unk1E8C;
int unk1E90; int unk1E94; int unk1E98; int unk1E9C;
int unk1EA0; int unk1EA4; int unk1EA8; int unk1EAC;
int unk1EB0; int unk1EB4; int unk1EB8; int unk1EBC;
int unk1EC0; int unk1EC4; int unk1EC8; int unk1ECC;
int unk1ED0; int unk1ED4; int unk1ED8; int unk1EDC;
int unk1EE0; int unk1EE4; int unk1EE8; int unk1EEC;
int unk1EF0; int unk1EF4; int unk1EF8; int unk1EFC;
int unk1F00; int unk1F04; int unk1F08; int unk1F0C;
int unk1F10; int unk1F14; int unk1F18; int unk1F1C;
int unk1F20; int unk1F24; int unk1F28; int unk1F2C;
int unk1F30; int unk1F34; int unk1F38; int unk1F3C;
int unk1F40; int unk1F44; int unk1F48; int unk1F4C;
int unk1F50; int unk1F54; int unk1F58; int unk1F5C;
int unk1F60; int unk1F64; int unk1F68; int unk1F6C;
int unk1F70; int unk1F74; int unk1F78; int unk1F7C;
int unk1F80; int unk1F84; int unk1F88; int unk1F8C;
int unk1F90; int unk1F94; int unk1F98; int unk1F9C;
int unk1FA0; int unk1FA4; int unk1FA8; int unk1FAC;
int unk1FB0; int unk1FB4; int unk1FB8; int unk1FBC;
int unk1FC0; int unk1FC4; int unk1FC8; int unk1FCC;
int unk1FD0; int unk1FD4; int unk1FD8; int unk1FDC;
int unk1FE0; int unk1FE4; int unk1FE8; int unk1FEC;
int unk1FF0; int unk1FF4; int unk1FF8; int unk1FFC;
int unk2000; int unk2004; int unk2008; int unk200C;
int unk2010; int unk2014; int unk2018; int unk201C;
int unk2020; int unk2024; int unk2028; int unk202C;
int unk2030; int unk2034; int unk2038; int unk203C;
int unk2040; int unk2044; int unk2048; int unk204C;
int unk2050; int unk2054; int unk2058; int unk205C;
int unk2060; int unk2064; int unk2068; int unk206C;
int unk2070; int unk2074; int unk2078; int unk207C;
int unk2080; int unk2084; int unk2088; int unk208C;
int unk2090; int unk2094; int unk2098; int unk209C;
int unk20A0; int unk20A4; int unk20A8; int unk20AC;
int unk20B0; int unk20B4; int unk20B8; int unk20BC;
int unk20C0; int unk20C4; int unk20C8;
Vector position;Vector* FUN_005f1100(Vector*);
};
Vector* Owner::FUN_005f1100(Vector* result){result->x=position.x;result->y=position.y;result->z=position.z;return result;}
}

}   // namespace f3m_005f1100

// @f3 0x005f1020 (community match, verified in this file)
namespace f3m_005f1020 {
namespace MatchF10 {
struct Sub {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;void FUN_005fc770();};struct Element {int unk00;Sub sub;void FUN_006102c0();};
struct Storage {int unk00;int unk04;int unk08;Element* data;unsigned count;};
struct Owner {void* table;Storage* storage;bool FUN_005eacb0(void*,int*,int*);bool PathBuilder_BuildDetailedPath(void*);int FUN_005f1020(void*);};
// pdb: PathBuilder::UpdatePathMoveToHigh | PathBuilder.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: aiCurrentVirtualNodeIndex
int Owner::FUN_005f1020(void* value){int last,first;first=-1;last=-1;if(!FUN_005eacb0(value,&first,&last))return 0;for(unsigned i=0;i<storage->count;++i)storage->data[i].sub.FUN_005fc770();if(first<=last){unsigned offset=(unsigned)first*sizeof(Element);unsigned remaining=(unsigned)(last-first+1);do{((Element*)((char*)storage->data+offset))->FUN_006102c0();offset+=sizeof(Element);}while(--remaining); }return PathBuilder_BuildDetailedPath(value)?2:-1;}
}
}   // namespace f3m_005f1020

// @f3 0x005ea320 (community match, verified in this file)
namespace f3m_005ea320 {
namespace N5EA3{struct Ref;struct VT{void* unk00;void (__thiscall *Destroy)(Ref*);};struct Ref{VT* vtable;long count;};struct Target{int unk00,unk04,unk08,unk0C,unk10,unk14,unk18;Ref ref;};extern long (__stdcall *DAT_00d9b064)(long*);extern long (__stdcall *DAT_00d9b068)(long*);struct Tail{Target* value;__forceinline void Assign(const Tail& other,long (__stdcall *decrement)(long*)){if(value!=other.value){Target* old=value;if(old){Ref* ref=&old->ref;if(!decrement(&ref->count))ref->vtable->Destroy(ref);}value=other.value;if(value)DAT_00d9b068(&value->ref.count);}}};struct Value{Ref* first;int second,third;Tail last;Value& FUN_005ea320(const Value&);};Value& Value::FUN_005ea320(const Value& other){long (__stdcall *decrement)(long*)=DAT_00d9b064;if(first!=other.first){Ref* old=first;if(old && !decrement(&old->count))old->vtable->Destroy(old);first=other.first;if(first)DAT_00d9b068(&first->count);}second=other.second;third=other.third;last.Assign(other.last,decrement);return *this;}}
}   // namespace f3m_005ea320

// @f3 0x005e6ef0 (community match, verified in this file)
namespace f3m_005e6ef0 {
class CBB3B10RefObject {
public:
    virtual ~CBB3B10RefObject() { InterlockedDecrement(&ms_lObjects); }
    virtual void GetType();
    static long ms_lObjects;
    int unk04;
};

class CBADDynamicArray {
public:
    virtual ~CBADDynamicArray() { Clear(); }
    virtual void v1();
    virtual void FreeItem(void* p);
    virtual void v3();
    void ReleaseItems(void** apItems, unsigned int auiSize);
    void Clear() {
        if (m_pItems) {
            ReleaseItems((void**)m_pItems, m_uiSize);
            FreeItem(m_pItems);
            m_pItems = 0;
            m_uiCapacity = 0;
            m_uiSize = 0;
        }
    }
    void* m_pItems;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
};

class FUN_005e6ef0 : public CBB3B10RefObject {
public:
    virtual ~FUN_005e6ef0();
    int unk08;
    CBADDynamicArray m_array;
};

// pdb: ReferenceObstacleArray::~ReferenceObstacleArray | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, medium
FUN_005e6ef0::~FUN_005e6ef0()
{
    unk08 = 0;
}
}   // namespace f3m_005e6ef0

// @f3 0x005f3bc0 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005f3bc0 {


struct Entry3bc0 {
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    void Reset() { vtable = &DAT_00dc4dc0; }
};

class Array3bc0 {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void Release(void* apData);
    void FUN_005f3bc0(bool abFree);

    void* data04;
    unsigned int size08;
    unsigned int last0C;
};

void Array3bc0::FUN_005f3bc0(bool abFree) {
    if (data04) {
        Entry3bc0* pEntry = (Entry3bc0*)data04;
        unsigned int uiCount = size08;
        while (uiCount > 0) {
            pEntry->Reset();
            ++pEntry;
            --uiCount;
        }
        if (abFree) {
            Release(data04);
            data04 = 0;
            last0C = 0;
        }
        size08 = 0;
    }
}
}   // namespace f3m_005f3bc0

// @f3 0x005e69b0 (community match, verified in this file)
namespace f3m_005e69b0 {

// ---- stand-ins for the reference-counted object that the string map returns ----

struct RefObjBase
{
    virtual ~RefObjBase();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

struct NamedThing
{
    int unk00;
    int unk04;
    const char* unk08;
};

struct RefCountedNamedObject : RefObjBase
{
    NamedThing* unk08;
};

struct MapItem
{
    MapItem* m_pkNext;
    const char* m_key;
    RefCountedNamedObject* m_val;
};

struct NameMap
{
    void* m_pkVtbl;
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    unsigned int m_uiItemCount;

    unsigned int KeyToHashIndex(const char* key) const;
    static bool IsKeysEqual(const char* first, const char* second);
    bool GetAt(const char* key, NiPointer<RefCountedNamedObject>& result) const
    {
        unsigned int index = KeyToHashIndex(key);
        MapItem* item = m_ppkHashTable[index % m_uiHashSize];
        while (item)
        {
            if (IsKeysEqual(item->m_key, key))
            {
                result = item->m_val;
                return true;
            }
            item = item->m_pkNext;
        }
        return false;
    }
};

void* TESForm_GetFormByNumericID(const char* name);

struct Owner
{
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78;
    NameMap map7C;
    void FUN_005e6430(void* obj);
    void FUN_005e69b0(const char* name);
};

// pdb: NavMeshObstacleManager::OnObstacleLost3D | NavMeshObstacleManager.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apRigidBody
void Owner::FUN_005e69b0(const char* name)
{
    NiPointer<RefCountedNamedObject> obj;
    if (map7C.GetAt(name, obj))
    {
        void* found = TESForm_GetFormByNumericID(obj->unk08->unk08);
        if (found)
            FUN_005e6430(found);
    }
}
}   // namespace f3m_005e69b0

// @f3 0x005f3950 (community match, verified in this file)
extern int DAT_00e020d8;
namespace f3m_005f3950 {
extern void (__stdcall *DAT_00e020e0)(void*);

struct Obj_005f3950 {
    int* unk00;
    void* unk04;
    int unk08;
    int unk0C;
    void FUN_005f3950();
};

void Obj_005f3950::FUN_005f3950()
{
    unk00 = &DAT_00e020d8;
    if (unk04) {
        DAT_00e020e0(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
}
}   // namespace f3m_005f3950

// @f3 0x005eb040 (community match, verified in this file)
namespace f3m_005eb040 {
struct Array5eb0 {void**table;void*data;unsigned size;unsigned capacity;void FUN_005eaae0(void*,void*,unsigned);void FUN_005eb040(unsigned,unsigned);};
// pdb: BSSimpleArray<VirtualPathingNode,1024>::_ReallocateBuffer | PathBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiNewSize, aiCopyCount
void Array5eb0::FUN_005eb040(unsigned nextCapacity,unsigned copyCount){if(data){if(copyCount==capacity)data=((void*(__thiscall*)(Array5eb0*,void*,unsigned))table[3])(this,data,nextCapacity);else{void*next=((void*(__thiscall*)(Array5eb0*,unsigned))table[1])(this,nextCapacity);FUN_005eaae0(next,data,copyCount);((void(__thiscall*)(Array5eb0*,void*))table[2])(this,data);data=next;}}else{void*next=((void*(__thiscall*)(Array5eb0*,unsigned))table[1])(this,nextCapacity);capacity=nextCapacity;data=next;}}
}   // namespace f3m_005eb040

// @f3 0x005e5350 (community match, verified in this file)
namespace f3m_005e5350 {
namespace Match5e53 {
struct Owner5e53;struct Table5e53 {int unk00;void* (__thiscall *unk04)(Owner5e53*,unsigned);};
struct Owner5e53 {Table5e53* unk00;void* unk04;unsigned unk08,unk0C;void FUN_00799ae0(unsigned,unsigned);unsigned FUN_005e5350();};
// pdb: BSSimpleArray<BGSBodyPart *,1024>::AddUninitialized | HitData.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSTArray<struct EditorNavMeshBoundsVertex *,class BSScrapArrayAllocator>::Add)
unsigned Owner5e53::FUN_005e5350(){if(unk08==unk0C){if(!unk0C){unk04=unk00->unk04(this,4);unk0C=4;}else{unsigned capacity=unk0C>0x400?unk0C+0x400:unk0C*2;FUN_00799ae0(capacity,unk08);unk0C=capacity;}}++unk08;return unk08-1;}
}
}   // namespace f3m_005e5350

// @f3 0x005f10d0 (community match, verified in this file)
namespace f3m_005f10d0 {
struct ObjectPosition {
    float x;
    float y;
    float z;
};
class FUN_005f10d0_owner {
public:
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    ObjectPosition position;
    void FUN_005f10d0(const ObjectPosition& value);
};

void FUN_005f10d0_owner::FUN_005f10d0(const ObjectPosition& value)
{
    position = value;
}
}   // namespace f3m_005f10d0

// @f3 0x005eb290 (community match, verified in this file)
namespace f3m_005eb290 {
struct CleanupElement { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; void FUN_00600960(); };
struct CleanupContainer;
struct CleanupVtable { void* unk00; void* unk04; void (__thiscall *release)(CleanupContainer*, CleanupElement*); };
struct CleanupContainer { CleanupVtable* vtable; CleanupElement* data; unsigned int count; unsigned int capacity; void FUN_005eb290(bool release); };
// pdb: BSSimpleArray<VirtualPathingNode,1024>::Clear | PathBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: abFreeMemory
void CleanupContainer::FUN_005eb290(bool release) { CleanupElement* p=data; if(p) { unsigned int n=count; while(n>0) { p->FUN_00600960(); ++p; --n; } if(release) { vtable->release(this,data); data=0; capacity=0; } count=0; } }
}   // namespace f3m_005eb290

// @f3 0x005ec490 (community match, verified in this file)
struct NavMeshEdgeLocation;

class PathingLocation {
public:
    virtual ~PathingLocation() {}
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int unk04[9];
};

template <>
class BSSimpleArray<NavMeshEdgeLocation, 1024> {
public:
    typedef NavMeshEdgeLocation T;
    T* data;
    unsigned capacity;
    unsigned count;

    virtual ~BSSimpleArray()
    {
        if (data) {
            BSSimpleArray* self = this;
            self->Free(data);
            data = 0;
            count = 0;
            capacity = 0;
        }
    }
    virtual T* Allocate(unsigned n);
    virtual void Free(T* p);
    virtual void Resize(unsigned n);
};

struct FUN_005ec490 {
    int unk00;
    int unk04;
    PathingLocation start;
    PathingLocation end;
    BSSimpleArray<NavMeshEdgeLocation, 1024> edges;
    ~FUN_005ec490();
};

// pdb: RayCastPathRequest::~RayCastPathRequest | PathBuilder.obj | fnv360_0721_beta, call_gap, low
FUN_005ec490::~FUN_005ec490()
{
}

// @f3 0x005eb460 (community match, verified in this file)
namespace f3m_005eb460 {
struct Heap5eb460 {
    void* FUN_0086bae0(void* p, unsigned int bytes);
};
namespace n5eb460 { extern Heap5eb460 DAT_01090a78; }

struct Elem5eb460 { char data[24]; };

struct Arr5eb460 {
    void* FUN_005eb460(void* p, unsigned int count);
};

// pdb: BSSimpleArray<NavMeshEdgeLocation,1024>::_Reallocate | PathBuilder.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* Arr5eb460::FUN_005eb460(void* p, unsigned int count)
{
    return n5eb460::DAT_01090a78.FUN_0086bae0(p, count * sizeof(Elem5eb460));
}
}   // namespace f3m_005eb460

// @f3 0x005f6940 (community match, verified in this file)
namespace f3m_005f6940 {
namespace fo3_5f6940 {
struct FUN_005ee830 {
unsigned int unk00;
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
FUN_005ee830(void*,void*);
void FUN_005f6660();
~FUN_005ee830() { FUN_005f6660(); }
int FUN_005f1020(void*);
};
// pdb: Pathing::UpdateSolutionMoveToHigh | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRequest, apSolution, aiCurrentVirtualNodeIndex
int __cdecl FUN_005f6940(void* start,void* goal,void* arg) { FUN_005ee830 scope(start,goal); return scope.FUN_005f1020(arg); }
}
}   // namespace f3m_005f6940

// @f3 0x005fd510 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005fd510 {

class FUN_005fd510
{
public:
    virtual ~FUN_005fd510();
    void PathingLocation_SetupData(unsigned int first, unsigned int second, unsigned int third);
    FUN_005fd510(unsigned int first, unsigned int second);
};

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_seq, high
// pdb params: aLocation, apWorldSpace
FUN_005fd510::FUN_005fd510(unsigned int first, unsigned int second)
{
    *(void**)this = &DAT_00dc4dc0;
    PathingLocation_SetupData(first, 0, second);
}
}   // namespace f3m_005fd510

// @f3 0x005ebc40 (community match, verified in this file)
namespace task0340 {
extern void (__stdcall *DAT_00e01ecc)(void*);
struct MemoryManager {
    void FUN_0086ba60(void*);
};
extern MemoryManager DAT_01090a78;
struct Array {
    virtual ~Array() {
        if (data) {
            DAT_00e01ecc(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    void* data;
    int size;
    int capacity;
};
// pdb: BSSimpleArray<NavMeshEdgeLocation,1024>::`scalar deleting destructor' | PathBuilder.obj | fnv360_0822_retail, vtable, medium
Array* __fastcall FUN_005ebc40(Array* object, int, unsigned int flags) {
    object->Array::~Array();
    if (flags & 1)
        DAT_01090a78.FUN_0086ba60(object);
    return object;
}
}

// @f3 0x005e01b0 (community match, verified in this file)
namespace f3_005e01b0 {
extern void (__stdcall *DAT_00e01aa4)(void*);
struct Heap {
    void FUN_0086ba60(void*);
};
extern Heap DAT_01090a78;
struct ArrayStorage {
    virtual ~ArrayStorage() {
        if (data) {
            DAT_00e01aa4(data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
    void* data;
    unsigned int count;
    unsigned int capacity;
};
// pdb: BSSimpleArray<BoundsTriangleInfo,1024>::`scalar deleting destructor' | NavMeshObstacleCutter.obj | fnv360_0822_retail, vtable, medium
ArrayStorage* __fastcall FUN_005e01b0(ArrayStorage* object, int, unsigned int flags) {
    object->ArrayStorage::~ArrayStorage();
    if (flags & 1)
        DAT_01090a78.FUN_0086ba60(object);
    return object;
}
}

// @f3 0x005f1260 (community match, verified in this file)
namespace PathForward0356 {
struct Path { void FUN_005d9b20(void*,void*); };
struct Manager { Path* FUN_00433ff0(); };
extern Manager* DAT_0107a0d8;
// pdb: Pathing::GetPotentialNavMeshInfoForLocation | Pathfind.obj | fnv360_0822_retail, call_seq, high
// pdb params: apWorldSpace, aiCellKey
void __cdecl FUN_005f1260(void* first,void* second) {
 DAT_0107a0d8->FUN_00433ff0()->FUN_005d9b20(first,second);
}
}

// @f3 0x005fc480 (community match, verified in this file)
namespace f3m_005fc480 {
namespace f3_005fc480 {
struct Point3 { float x, y, z; };
struct NavMeshInfo;
struct NavMeshInfoArray;
struct Cell;
struct WorldSpace;
struct PathingLocation {
    void** vtable;
    Point3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const NavMeshInfoArray* pNavMeshInfoArray;
    Cell* pCell;
    WorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    PathingLocation& FUN_005fc480(const PathingLocation&);
};
// @fnv 0x006dcce0
// pdb: PathingLocation::operator= | PathingLocation.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aLoc
PathingLocation& PathingLocation::FUN_005fc480(const PathingLocation& other)
{
    Location = other.Location;
    m_pLocationNavMesh = other.m_pLocationNavMesh;
    pNavMeshInfoArray = other.pNavMeshInfoArray;
    pCell = other.pCell;
    m_pContainingWorldspace = other.m_pContainingWorldspace;
    m_uiPathingFlags = other.m_uiPathingFlags;
    m_usTriangleID = other.m_usTriangleID;
    uiFlags = other.uiFlags;
    return *this;
}

}
}   // namespace f3m_005fc480

// @f3 0x005fe7b0 (community match, verified in this file)
namespace f3m_005fe7b0 {
struct Key5fe7 {
    int unk00;
};

struct Input5fe7 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Key5fe7* unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short unk24;
};

struct Found5fe7 {
    bool __thiscall FUN_005fe6a0(Input5fe7* input);
};

struct Map5fe7 {
    bool __thiscall FUN_00bea7b0(int key, Found5fe7** result);
};

struct Owner5fe7 {
    int unk00;
    int unk04;
    Map5fe7 unk08;
    bool __thiscall FUN_005fe7b0(Input5fe7* input);
};

// pdb: PathingLOSGridMap::IsLocationSeen | PathingLOSGridMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: arLocation
bool Owner5fe7::FUN_005fe7b0(Input5fe7* input) {
    Input5fe7* original = input;
    Key5fe7* keyObject = original->unk10;

    if (keyObject != 0 && original->unk24 != 0xffff) {
        int key = keyObject->unk00;
        Found5fe7* result = 0;

        if (unk08.FUN_00bea7b0(key, &result)) {
            return result->FUN_005fe6a0(original);
        }
    }

    return false;
}
}   // namespace f3m_005fe7b0

// @f3 0x005f41d0 (community match, verified in this file)
namespace f3m_005f41d0 {
// FUN_005f41d0 - 0x005f41d0, 109 bytes, __cdecl

struct CA0E60Array {
    void* m_vt00;            // +0x00
    void* m_data04;          // +0x04
    unsigned int m_08;       // +0x08
    volatile unsigned int m_0C;  // +0x0C
    void FUN_00cb9ce0(unsigned int a, unsigned int b);
};

struct Target {
    char pad00[4];
    unsigned char b04;       // +0x04
    char pad05[0x34 - 5];
    Target* m_34;            // +0x34
    Target* FUN_00d5e2d0();
    int FUN_004e1bc0(int a, float f, CA0E60Array* arr);
};

// pdb: Pathing::FindTeleportDoorsForLocation | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apSpace, arLocation, afRadius, apRetDoors
int FUN_005f41d0(Target* a1, int a2, float f, CA0E60Array* a4)
{
    if (!a1 || !a4)
        return 0;

    unsigned int cap = a4->m_0C;
    if (cap < 0x20) {
        if (a4->m_08 > 0x20)
            a4->m_08 = 0x20;
        a4->FUN_00cb9ce0(0x20, a4->m_08);
        a4->m_0C = 0x20;
    }

    Target* p = a1->b04 == 0x41 ? a1->FUN_00d5e2d0() : a1;
    if (!p)
        return 0;

    return p->FUN_004e1bc0(a2, f, a4);
}
}   // namespace f3m_005f41d0

// @f3 0x005ecf40 (community match, verified in this file)
namespace n5ecf40 {
struct Heap { void* FUN_0086bcb0(); };
extern Heap DAT_01090a78;
struct ArrayBase {
    ArrayBase() : data(0), size(0), capacity(0) {}
    virtual ~ArrayBase();
    virtual void* Allocate(unsigned int n);
    void* data;
    unsigned int size;
    unsigned int capacity;
};
}

struct FUN_005ecf40 : n5ecf40::ArrayBase {
    FUN_005ecf40(unsigned int cap, unsigned int count, void* pool);
    virtual ~FUN_005ecf40();
    void* pool;
};

// pdb: BSScrapArray<int,1024>::BSScrapArray<int,1024> | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiReserveSize, aiInitialSize, apHeap
FUN_005ecf40::FUN_005ecf40(unsigned int cap, unsigned int count, void* p)
{
    if (!p)
        p = n5ecf40::DAT_01090a78.FUN_0086bcb0();
    pool = p;
    data = 0;
    size = 0;
    capacity = 0;
    unsigned int n = cap;
    if (count > cap)
        n = count;
    if (n > 0) {
        FUN_005ecf40* self = this;
        data = self->Allocate(n);
        capacity = n;
    }
    if (count > 0)
        size = count;
}

// @f3 0x005ead50 (community match, verified in this file)
namespace f3m_005ead50 {

struct Entry005ead50 {
    int unk00;
    int unk04;
    int unk08;
    unsigned int flags;
};

struct PV005ead50 {
    char unk00[0x3c];
    void* entries;
};

class Cls005ead50 {
public:
    char unk00[4];
    unsigned char unk04;
    bool FUN_005ead50(int a1, int a2, int a3, PV005ead50* pv, unsigned short index, int a6);
};

// pdb: CheckLineOfSightFilterWater::CanCrossEdge | PathBuilder.obj | fnv360_0822_retail, vtable, medium
// pdb params: hEdge, hMatchingEdge
bool Cls005ead50::FUN_005ead50(int a1, int a2, int a3, PV005ead50* pv, unsigned short index, int a6)
{
    volatile unsigned int* p = (volatile unsigned int*)((char*)pv->entries + (index << 4));
    unsigned int v = p[3];
    bool b9 = (v >> 9) & 1;
    if (b9)
        return false;
    bool b4 = (v >> 4) & 1;
    if (b4 && unk04)
        return false;
    bool b31 = (v >> 31) & 1;
    if (b31)
        return false;
    bool ok = ((v >> 12) & 1) == 0;
    return ok;
}
}   // namespace f3m_005ead50

// @f3 0x005f24b0 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005f24b0 {
void __stdcall FUN_005f24b0(void* apFirst, unsigned int aiCount) {
    while (aiCount > 0) {
        *(void**)apFirst = &DAT_00dc4dc0;
        apFirst = (unsigned char*)apFirst + 0x54;
        --aiCount;
    }
}
}   // namespace f3m_005f24b0

// @f3 0x005ff580 (community match, verified in this file)
namespace q44a {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Item { void FUN_005ff110(); };
struct Map {
    void* vtbl;
    unsigned int m_size;
    Item** m_buckets;
    void FUN_0089a5d0(void** pos, unsigned int* key, Item** val);
    void FUN_006bd950();
    void* GetFirstPos() {
        for (unsigned int i = 0; i < m_size; i++) {
            if (m_buckets[i]) return m_buckets[i];
        }
        return 0;
    }
};
struct Lock {
    int unk00;
    void FUN_0086cc50();
    void FUN_0086cde0();
};
struct Owner303 {
    int unk00;
    int unk04;
    Map m_map;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    Lock m_lock;
    void FUN_005ff580();
};
// pdb: PathingLOSGridMap::Clear | PathingLOSGridMap.obj | fnv360_0822_retail, callee_sim, low
void Owner303::FUN_005ff580() {
    m_lock.FUN_0086cc50();
    {
        void* pos = m_map.GetFirstPos();
        while (pos) {
            unsigned int key;
            Item* val = 0;
            m_map.FUN_0089a5d0(&pos, &key, &val);
            Item* v = *(Item* volatile*)&val;
            if (v) {
                v->FUN_005ff110();
                DAT_01090a78.FUN_0086ba60(v);
            }
        }
    }
    m_map.FUN_006bd950();
    m_lock.FUN_0086cde0();
}
}

// @f3 0x005e6370 (community match, verified in this file)
extern long DAT_0108ed80;
extern void* DAT_00db7764[];
extern void* DAT_00e00d68[];
namespace f3m_005e6370 {
namespace destroy5e6370 {
struct RefArray;
extern void (__thiscall* DAT_00e00d70)(RefArray*, void*);

struct ManagedRef;
struct ManagedOperations { void* unk00; void (__thiscall* destroy)(ManagedRef*); };
struct ManagedRef {
    ManagedOperations* operations;
    long references;
    void Release() { if (!InterlockedDecrement(&references)) operations->destroy(this); }
};
struct ManagedRefPtr {
    ManagedRef* p;
    ~ManagedRefPtr() { if (p) p->Release(); }
};

struct RefArray {
    void** table;
    void* data;
    unsigned size;
    unsigned capacity;
    ~RefArray() {
        void* storage = data;
        table = DAT_00e00d68;
        if (storage) {
            DAT_00e00d70(this, storage);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
};

struct CompositeBase {
    void** table;
    ~CompositeBase() { table = DAT_00db7764; InterlockedDecrement(&DAT_0108ed80); }
};

struct FUN_005e6370 : CompositeBase {
    unsigned unk04;
    unsigned unk08;
    ManagedRefPtr first;
    unsigned unk10; unsigned unk14; unsigned unk18; unsigned unk1C; unsigned unk20;
    unsigned unk24; unsigned unk28; unsigned unk2C; unsigned unk30; unsigned unk34;
    unsigned unk38; unsigned unk3C; unsigned unk40; unsigned unk44; unsigned unk48;
    unsigned unk4C; unsigned unk50; unsigned unk54; unsigned unk58; unsigned unk5C;
    unsigned unk60; unsigned unk64; unsigned unk68; unsigned unk6C; unsigned unk70;
    unsigned unk74;
    RefArray array;
    ManagedRefPtr last;
    ~FUN_005e6370();
};

// pdb: ObstacleData::~ObstacleData | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, medium
FUN_005e6370::~FUN_005e6370() {}
}
}   // namespace f3m_005e6370

// @f3 0x005f6700 (community match, verified in this file)
#include <math.h>
namespace f3m_005f6700 {
namespace f3m_005f6700 {
struct QPt3 {
    float x, y, z;
    QPt3() {}
    QPt3(float a, float b, float c) : x(a), y(b), z(c) {}
    QPt3 operator+(const QPt3& o) const { return QPt3(x + o.x, y + o.y, z + o.z); }
};
struct QRng { unsigned int FUN_0086c4b0(unsigned int range); };
QRng* FUN_0044a2d0();
struct QGround { bool FUN_004d7380(QPt3* pos, float* z); };
struct QFinder { int unk00; void* PathingLocation_GetCell(); };
struct QSpawn {
    int unk00, unk04, unk08;
    QFinder finder;
    QPt3 pos;
};
struct QSpawnData {
    int unk00;
};
bool FUN_005f4d90(QSpawn* obj, QPt3* out);
// pdb: Pathing::FindClosePoint | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRequest, apRetPt
void FUN_005f6700(QSpawn* obj, QPt3* out)
{
    if (FUN_005f4d90(obj, out))
        return;
    QRng* rng = FUN_0044a2d0();
    float angle = (float)rng->FUN_0086c4b0(0xffffffff) * 1.462918119976564e-09;
    float maxR = *(float*)((char*)obj + 0xb4);
    float minR = *(float*)((char*)obj + 0xb0);
    float r = minR + (maxR - minR) * (float)(rng = FUN_0044a2d0())->FUN_0086c4b0(0xffffffff) * 2.3283064365386963e-10;
    QPt3 off;
    off.x = (float)cos(angle) * r;
    off.y = (float)sin(angle) * r;
    off.z = 0.0f;
    QPt3 p = obj->pos;
    *out = p + off;
    QGround* g = (QGround*)obj->finder.PathingLocation_GetCell();
    float z;
    if (g && g->FUN_004d7380(out, &z))
        out->z = z;
}
}
}   // namespace f3m_005f6700

// @f3 0x005ea860 (community match, verified in this file)
namespace f3m_005ea860 {
namespace f3m_005ea860 {
struct FUN_005e9d60 { int values[4]; ~FUN_005e9d60(); };
class Array5ea860 { public: __forceinline virtual ~Array5ea860() { Clear(); } virtual FUN_005e9d60* Allocate(unsigned); virtual void Free(FUN_005e9d60*); FUN_005e9d60* data; unsigned count,capacity; __forceinline void Clear() { FUN_005e9d60* p=data; if(p) { for(unsigned remaining=count;remaining>0;++p,--remaining) p->~FUN_005e9d60(); Free(data); data=0; capacity=0; count=0; } } void FUN_005ea860(); };
// pdb: BSSimpleArray<ObstacleTaskNavMeshOperation,1024>::~BSSimpleArray<ObstacleTaskNavMeshOperation,1024> | NavMeshObstacleTask.obj | fnv360_0822_retail, call_seq, medium
void Array5ea860::FUN_005ea860() { this->Array5ea860::~Array5ea860(); }
}
}   // namespace f3m_005ea860

// @f3 0x005efc20 (community match, verified in this file)
namespace f3m_005efc20 {
extern void* DAT_00dc4dc0[];

struct PathPoint
{
    void** m_vtable;
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;

    PathPoint() { FUN_005fc3f0(); }
    ~PathPoint() { m_vtable = DAT_00dc4dc0; }
    void FUN_005fc3f0();
    bool FUN_005fda30(int flag);
    bool FUN_005fc750();
};

struct PathEntry
{
    unsigned char flags;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    PathPoint point;
    int unk2C;
};

struct PathTable
{
    int unk00; int unk04; int unk08;
    PathEntry* entries;
    int unk10; int unk14;
    int count;
};

struct PathOutput
{
    int FUN_005ecde0(PathPoint* point);
};

int __cdecl FUN_005f90b0(PathPoint* point, int mode, void* context);

struct PathBuilder
{
    int unk00;
    PathTable* table;
    int unk08; int unk0C;
    bool busy;

    bool FUN_005edc00(PathEntry* previous, PathEntry* entry, PathPoint* out);
    int FUN_005eebe0(PathPoint* point, PathOutput* output, bool flag, void* context);
    int FUN_005efc20(int index, PathOutput* output, void* context);
};

// pdb: PathBuilder::BuildPathToNavMeshSearchStart | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiFirstVirtualNodeIndex, aRetPath, aRetEdges
int PathBuilder::FUN_005efc20(int index, PathOutput* output, void* context)
{
    PathEntry* entry = &table->entries[index];
    if (index && !busy) {
        PathEntry* previous = &table->entries[index - 1];
        if (index > table->count) {
            if (previous->flags & 2) {
                PathPoint merged;
                if (FUN_005edc00(previous, entry, &merged)) {
                    output->FUN_005ecde0(&merged);
                    return 1;
                }
            }
        } else if (!(entry->flags & 2)) {
            PathPoint merged;
            if (FUN_005edc00(previous, entry, &merged)) {
                output->FUN_005ecde0(&merged);
                return 1;
            }
        }
    }
    if (entry->flags & 2) {
        PathPoint* point = &entry->point;
        if (point->FUN_005fda30(0)) {
            if (!point->FUN_005fc750()) {
                switch (FUN_005f90b0(point, 10, context)) {
                case 1:
                    break;
                case 2:
                    return FUN_005eebe0(point, output, true, context);
                default:
                    return 2;
                }
            }
            output->FUN_005ecde0(point);
            return 1;
        }
    }
    return 2;
}
}

// @f3 0x005fe020 (community match, verified in this file)
namespace f3m_005fe020 {
namespace f3m_005fe020 {
struct QVec { float x, y, z; };
struct QOwner { int unk00[21]; int unk54; };
struct QShape;
extern unsigned char __cdecl FUN_005f2730(QShape* shape, QVec* pos, int a, int b);
struct QShape {
    int unk00;
    QVec pos;
    QOwner* owner;
    int unk14, unk18, unk1c, unk20;
    unsigned short unk24;
    bool FUN_005fda30(int);
    bool PathingLocation_IsValidLocation(float r);
};
// pdb: PathingLocation::IsValidLocation | PathingLocation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim), high
bool QShape::PathingLocation_IsValidLocation(float r)
{
    FUN_005fda30(0);
    if (!owner || !owner->unk54)
        return false;
    if (unk24 == 0xFFFF)
        return false;
    if (r <= 0)
        return true;
    QVec p = pos;
    QVec v1 = p; v1.x -= r;
    if (!FUN_005f2730(this, &v1, 0, 0)) return false;
    QVec v2 = p; v2.x = p.x + r;
    if (!FUN_005f2730(this, &v2, 0, 0)) return false;
    QVec v3 = p; v3.y = p.y - r;
    if (!FUN_005f2730(this, &v3, 0, 0)) return false;
    QVec v4 = p; v4.y = p.y + r;
    return FUN_005f2730(this, &v4, 0, 0) ? true : false;
}
}
}   // namespace f3m_005fe020

// @f3 0x005ff330 (community match, verified in this file)
namespace f3m_005ff330 {

struct QHeap { void* FUN_0086b930(unsigned n); void FUN_0086ba60(void* p); };
extern QHeap DAT_01090a78;

struct QStream {
    unsigned BGSLoadGameBuffer_LoadVariableSizedValue();
    void FUN_006e06d0(unsigned* out);
    void FUN_006e0750(void* dst, unsigned size);
};

void QProbe();
struct FUN_005ff110 {
    virtual void v00();
    int unk04; int unk08; int unk0c; int unk10;
    FUN_005ff110() : unk04(0), unk08(0), unk0c(0), unk10(0) { if (unk04) QProbe(); }
    ~FUN_005ff110();
    void FUN_005feea0(QStream* s);
    static void* operator new(unsigned n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct QMap { int unk00; int unk04; int unk08; int unk0c; void FUN_00880f70(unsigned key, FUN_005ff110* r); };

struct QMember { virtual void v00(); virtual void Load(QStream* s); };

struct QOwner {
    int unk00; int unk04;
    QMap map;
    unsigned unk18;
    QMember member;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    unsigned unk44; unsigned unk48;
    void FUN_005ff330(QStream* stream);
};

// pdb: PathingLOSGridMap::LoadGame | PathingLOSGridMap.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apLoadGameBuffer
void QOwner::FUN_005ff330(QStream* stream)
{
    unsigned count = stream->BGSLoadGameBuffer_LoadVariableSizedValue();
    for (unsigned i = 0; i < count; i++) {
        FUN_005ff110* entry = new FUN_005ff110;
        unsigned key;
        stream->FUN_006e06d0(&key);
        entry->FUN_005feea0(stream);
        if (key)
            map.FUN_00880f70(key, entry);
        else
            delete entry;
    }
    stream->FUN_006e0750(&unk18, 4);
    stream->FUN_006e0750(&unk44, 4);
    stream->FUN_006e0750(&unk48, 4);
    member.Load(stream);
}

}

// @f3 0x005e7310 (community match, verified in this file)
namespace f3m_005e7310 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*) throw();
void* __cdecl FUN_0089eb90(unsigned int size);
class FUN_005e62f0;
typedef FUN_005e62f0 QRec;
void __cdecl FUN_005e3250(QRec* rec);
struct QMember0C { void FUN_008e9650(void* item); };
class FUN_005e62f0 {
public:
    virtual void V00();
    virtual void DeleteThis();
    long refCount;
    void* owner;
    QMember0C m0c;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p);
    FUN_005e62f0();
};
struct QRecPtr {
    QRec* p;
    QRecPtr(QRec* r) : p(r) { if (p) InterlockedIncrement(&p->refCount); }
    ~QRecPtr() { if (!InterlockedDecrement(&p->refCount)) p->DeleteThis(); }
    QRec* operator->() const { return p; }
    operator QRec*() const { return p; }
};
struct QRecPtr;
struct QRecList { int unk00; __declspec(noinline) void FUN_006b5880(const QRecPtr& item) { unk00 = (int)item.p; } };
struct QOwner { int unk00; int unk04; int unk08; QRecList list0c; };
struct QTypeBase { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; unsigned int flags1c; };
struct QTypePad { virtual void V00(); int unk04; int unk08; int unk0c; };
struct QTyped : QTypePad, QTypeBase {};
struct QItem { int unk00; int unk04; QTyped* typed; };
struct QExtra { int unk00; int unk04; int unk08; int unk0c; QItem* item; };
struct QNode;
struct QAV {
    virtual void V00(); virtual void V04(); virtual void V08();
    virtual QNode* GetAsNode();
};
struct QNode : QAV {
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    QAV** children;
    unsigned short unka4;
    unsigned short count;
};
QExtra* __cdecl FUN_00424fe0(QAV* obj);

// pdb: NavMeshObstacleManager::AddObstaclesFor3DRecursive | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: ap3D, apRetObstacleArray
bool __cdecl FUN_005e7310(QAV* obj, QOwner** owner) {
    QExtra* extra = FUN_00424fe0(obj);
    if (extra) {
        QItem* item = extra->item;
        if (item) {
            QTypeBase* tb = item->typed;
            unsigned int type;
            if (tb) type = tb->flags1c; else type = 0;
            type &= 0x7f;
            if (type == 2 || type == 4 || type == 10 || type == 20 || type == 28) {
                QRecPtr sp(new QRec);
                QOwner* o = *owner;
                sp->owner = o;
                sp->m0c.FUN_008e9650(item);
                FUN_005e3250(sp);
                QOwner* o2 = *owner;
                o2->list0c.FUN_006b5880(sp);
            }
        }
    }
    QNode* node = obj->GetAsNode();
    if (node) {
        for (unsigned int i = 0; i < node->count; i++) {
            QAV* child = node->children[i];
            if (child) FUN_005e7310(child, owner);
        }
    }
    return true;
}
}   // namespace f3m_005e7310

// @f3 0x005f25b0 (community match, verified in this file)
namespace f3m_005f25b0 {
namespace attempt5f25b0 {
struct Vec { int x, y, z; };
struct Counter { void** table; long refs; void Release() { if (!InterlockedDecrement(&refs)) ((void (__thiscall *)(Counter*))table[1])(this); } };
struct Resource { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18; Counter counter; void IncRefCount() { InterlockedIncrement(&counter.refs); } void DecRefCount() { counter.Release(); } };
struct Subject { int unk00; Vec vec; unsigned char FUN_005fda30(int); bool FUN_005fc8f0(NiPointer<Resource>*, int*); };
struct Copy { void FUN_005fc480(Subject*); };
bool __cdecl FUN_005f1970(Subject*, Vec*, Resource*, int, Copy*, int);
// pdb: Pathing::CheckLineOfSight | Pathfind.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSPathingLocation::BSPathingLocation)
// pdb params: aStartLocation, aGoalLocation, apReturnIntersectionLocation, apFilter
unsigned char __cdecl FUN_005f25b0(Subject* first, Subject* second, Copy* dest, int arg) {
    if (dest) dest->FUN_005fc480(first);
    if (!second->FUN_005fda30(0)) return !first->FUN_005fda30(0);
    NiPointer<Resource> resource;
    int index;
    if (!second->FUN_005fc8f0(&resource, &index)) {
        Vec v = second->vec;
        return FUN_005f1970(first, &v, 0, 65535, dest, arg);
    } else {
        Vec v = second->vec;
        return FUN_005f1970(first, &v, resource, index, dest, arg);
    }
}
}
}   // namespace f3m_005f25b0

// @f3 0x005f1490 (community match, verified in this file)
namespace f3m_005f1490 {


struct FNVRefBase
{
    virtual void vf00();
    virtual void vf04();
    LONG unk04;
};

struct FNVStandin
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;

    void FUN_005f1490(int newValue);
};

void FNVStandin::FUN_005f1490(int newValue)
{
    FNVStandin* self = this;
    int oldValue = self->unk94;

    if (oldValue != newValue) {
        if (oldValue != 0) {
            FNVRefBase* oldRef = (FNVRefBase*)((char*)oldValue + 0x10);

            if (InterlockedDecrement(&oldRef->unk04) == 0) {
                oldRef->vf04();
            }
        }

        self->unk94 = newValue;

        if (newValue != 0) {
            FNVRefBase* newRef = (FNVRefBase*)((char*)newValue + 0x10);
            InterlockedIncrement(&newRef->unk04);
        }
    }
}
}   // namespace f3m_005f1490

// @f3 0x005f1300 (community match, verified in this file)
#include <windows.h>
namespace f3m_005f1300 {

struct Cls {
    void* m_p;
    Cls* FUN_005f1300(void* p);
};

Cls* Cls::FUN_005f1300(void* p) {
    void* old = m_p;
    if (old != p) {
        if (old != 0) {
            void* sub = (char*)old + 0x10;
            if (InterlockedDecrement((LONG*)((char*)sub + 4)) == 0) {
                typedef void (__thiscall *Fn)(void*);
                ((Fn*)*(void**)sub)[1](sub);
            }
        }
        m_p = p;
        if (p != 0) {
            InterlockedIncrement((LONG*)((char*)p + 0x14));
        }
    }
    return this;
}
}   // namespace f3m_005f1300

// @f3 0x005e02c0 (community match, verified in this file)
namespace f3m_005e02c0 {
extern int DAT_00e01ad8;
extern void (__stdcall* DAT_00e01ae0)(void*);

struct MemMgr005e02c0 {
    void Deallocate(void* p);
};
extern MemMgr005e02c0 DAT_01090a78;

struct Obj005e02c0 {
    int* vtable;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Obj005e02c0* FUN_005e02c0(unsigned int flag);
};

// pdb: BSSimpleArray<NavMeshObstacleEdge *,1024>::`scalar deleting destructor' | NavMeshObstacleCutter.obj | fnv360_0822_retail, vtable, medium
Obj005e02c0* Obj005e02c0::FUN_005e02c0(unsigned int flag)
{
    vtable = &DAT_00e01ad8;
    if (unk04)
    {
        DAT_00e01ae0(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
    if (flag & 1)
        DAT_01090a78.Deallocate(this);
    return this;
}
}   // namespace f3m_005e02c0

// @f3 0x005e61a0 (community match, verified in this file)
namespace f3m_005e61a0 {
struct Allocator {
    void Free(void* p);
};

struct Base {
    virtual ~Base() { Clear(); }
    virtual void* Allocate(int count);
    virtual void Free(void* p);
    void Clear() {
        if (m_pData) {
            Free(m_pData);
            m_pData = 0;
            m_nCapacity = 0;
            m_nSize = 0;
        }
    }
    void* m_pData;
    int m_nSize;
    int m_nCapacity;
};

struct Derived : Base {
    virtual ~Derived();
    virtual void Free(void* p);
    Allocator* m_pAlloc;
};

// pdb: BSScrapArray<TESObjectCELL *,1024>::~BSScrapArray<TESObjectCELL *,1024> | NavMeshObstacleManager.obj | fnv360_0822_debug, call_seq, low
Derived::~Derived() {
    Clear();
}
}   // namespace f3m_005e61a0

// @f3 0x005ebcd0 (community match, verified in this file)
namespace f3m_005ebcd0 {
struct MemoryManager {
    void _DeallocateAlias(void* block);
};
extern MemoryManager _g_memoryManager;
extern "C" __declspec(dllimport) void __stdcall FUN_005bb6e0(void* p);
struct FUN_005ebcd0 {
    virtual ~FUN_005ebcd0();
    virtual void* Allocate(unsigned int count);
    virtual void Deallocate(void* p);
    virtual void* Reallocate(void* p, unsigned int count);
    void* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    // pdb: BSSimpleArray<PathBuilder::VirtualNodeSegment,1024>::`scalar deleting destructor' | PathBuilder.obj | fnv360_0822_retail, vtable, medium
    static void operator delete(void* p) { _g_memoryManager._DeallocateAlias(p); }
};
FUN_005ebcd0::~FUN_005ebcd0() {
    if (pBuffer) {
        FUN_005bb6e0(pBuffer);
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
}   // namespace f3m_005ebcd0

// @f3 0x005e6230 (community match, verified in this file)
namespace f3m_005e6230 {
// FUN_005e6230 — __thiscall scalar-deleting dtor of the obstacle-task array.
// Installs the dispatch table (DAT_00e01cd0), and when the array data is
// non-null frees it through the DAT_00e01cd8 entry and clears the three
// fields; deletes this through g_memoryManager when (a2 & 1).

class a43840_Mem {
public:
    void _DeallocateAlias(void* block);
};
extern a43840_Mem g_memoryManager;

extern void* DAT_00e01cd0;                          // dispatch table base
extern void* (__stdcall* DAT_00e01cd8)(void* block); // free entry

class FUN_005e6230_owner {
public:
    void* unk00;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void* FUN_005e6230(char a2);
};

// pdb: BSSimpleArray<ObstacleTaskData *,1024>::`scalar deleting destructor' | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable, medium
void* FUN_005e6230_owner::FUN_005e6230(char a2)
{
    unk00 = &DAT_00e01cd0;
    if (unk04 != 0) {
        DAT_00e01cd8(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
    if (a2 & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}   // namespace f3m_005e6230

// @f3 0x005e9ad0 (community match, verified in this file)
namespace f3m_005e9ad0 {
struct LocalTls9AD0 {
int unk00;
int unk04;
int unk08;
int unk0C;
int unk10;
int unk14;
int unk18;
int unk1C;
int unk20;
int unk24;
int unk28;
int unk2C;
int unk30;
int unk34;
int unk38;
int unk3C;
int unk40;
int unk44;
int unk48;
int unk4C;
int unk50;
int unk54;
int unk58;
int unk5C;
int unk60;
int unk64;
int unk68;
int unk6C;
int unk70;
int unk74;
int unk78;
int unk7C;
int unk80;
int unk84;
int unk88;
int unk8C;
int unk90;
int unk94;
int unk98;
int unk9C;
int unkA0;
int unkA4;
int unkA8;
int unkAC;
int unkB0;
int unkB4;
int unkB8;
int unkBC;
int unkC0;
int unkC4;
int unkC8;
int unkCC;
int unkD0;
int unkD4;
int unkD8;
int unkDC;
int unkE0;
int unkE4;
int unkE8;
int unkEC;
int unkF0;
int unkF4;
int unkF8;
int unkFC;
int unk100;
int unk104;
int unk108;
int unk10C;
int unk110;
int unk114;
int unk118;
int unk11C;
int unk120;
int unk124;
int unk128;
int unk12C;
int unk130;
int unk134;
int unk138;
int unk13C;
int unk140;
int unk144;
int unk148;
int unk14C;
int unk150;
int unk154;
int unk158;
int unk15C;
int unk160;
int unk164;
int unk168;
int unk16C;
int unk170;
int unk174;
int unk178;
int unk17C;
int unk180;
int unk184;
int unk188;
int unk18C;
int unk190;
int unk194;
int unk198;
int unk19C;
int unk1A0;
int unk1A4;
int unk1A8;
int unk1AC;
int unk1B0;
int unk1B4;
int unk1B8;
int unk1BC;
int unk1C0;
int unk1C4;
int unk1C8;
int unk1CC;
int unk1D0;
int unk1D4;
int unk1D8;
int unk1DC;
int unk1E0;
int unk1E4;
int unk1E8;
int unk1EC;
int unk1F0;
int unk1F4;
int unk1F8;
int unk1FC;
int unk200;
int unk204;
int unk208;
int unk20C;
int unk210;
int unk214;
int unk218;
int unk21C;
int unk220;
int unk224;
int unk228;
int unk22C;
int unk230;
int unk234;
int unk238;
int unk23C;
int unk240;
int unk244;
int unk248;
int unk24C;
int unk250;
int unk254;
int unk258;
int unk25C;
int unk260;
int unk264;
int unk268;
int unk26C;
int unk270;
int unk274;
int unk278;
int unk27C;
int unk280;
int unk284;
int unk288;
int unk28C;
int unk290;
int unk294;
int unk298;
};
__declspec(thread) LocalTls9AD0 tls9AD0 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59};
struct Scope9AD0 { int old; Scope9AD0() { old=tls9AD0.unk298; tls9AD0.unk298=46; } ~Scope9AD0() { tls9AD0.unk298=old; } };
struct Singleton9AD0 {
int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; 
void FUN_005e9600(); void FUN_005e9890();
Singleton9AD0() { FUN_005e9600(); } ~Singleton9AD0() { FUN_005e9890(); }
};
// pdb: NavMeshObstacleManager::GetInstance | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
Singleton9AD0* FUN_005e9ad0() { Scope9AD0 scope; static Singleton9AD0 instance; return &instance; }
}   // namespace f3m_005e9ad0

// @f3 0x005ff430 (community match, verified in this file)
extern int DAT_00e022a4;
namespace f3m_005ff430 {
struct Storage5ff {int unk00,unk04,unk08; Storage5ff():unk00(0),unk04(0),unk08(0){} ~Storage5ff();};
struct Owner5ff {int* unk00; Storage5ff unk04; int unk10; void FUN_005ff1d0(int); Owner5ff(int);};
Owner5ff::Owner5ff(int arg):unk00(&DAT_00e022a4),unk10(0){FUN_005ff1d0(arg);}
}   // namespace f3m_005ff430

// @f3 0x005e0030 (community match, verified in this file)
namespace f3m_005e0030 {
struct Heap5E00 { void* FUN_0086bcb0(); };
extern Heap5E00 DAT_01090a78;
extern void* DAT_00e01b08[];
struct SimpleBase5E00 { void** table; void* buffer; unsigned size; unsigned capacity; SimpleBase5E00(){ buffer=0; size=0; capacity=0; } ~SimpleBase5E00(); };
struct FUN_005e0030 : SimpleBase5E00 {
 void* allocator;
 FUN_005e0030(unsigned,unsigned,void*);
};
// pdb: BSScrapArray<NavMeshObstacleEdge *,1024>::BSScrapArray<NavMeshObstacleEdge *,1024> | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiReserveSize, aiInitialSize, apHeap
FUN_005e0030::FUN_005e0030(unsigned capacityRequested,unsigned sizeRequested,void* owner) {
 table=DAT_00e01b08;
 if(!owner) owner=DAT_01090a78.FUN_0086bcb0();
 unsigned requestedCapacity=capacityRequested; unsigned requestedSize=sizeRequested; allocator=owner;
 buffer=0; size=0; capacity=0;
 if(requestedSize>requestedCapacity) requestedCapacity=requestedSize;
 if(requestedCapacity>0) {
  buffer=((void*(__thiscall*)(FUN_005e0030*,unsigned))table[1])(this,requestedCapacity);
  capacity=requestedCapacity;
 }
 if(requestedSize>0) size=requestedSize;
}


}   // namespace f3m_005e0030

// @f3 0x005eb800 (community match, verified in this file)
namespace f3m_005eb800 {


struct Allocator5eb800 {
    void* ScrapHeap_Allocate(unsigned int key, int arg);
    void ScrapHeap_Deallocate(void* block);
};
extern int DAT_00e27ed4;

class FUN_005eb800_owner {
public:
    int unk00;
    int unk04;
    unsigned int size;
    int unk0c;
    Allocator5eb800* allocator;
    void* FUN_005eb800(void* block, unsigned int key);
};

// pdb: BSScrapArray<bool,1024>::_Reallocate | PathBuilder.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* FUN_005eb800_owner::FUN_005eb800(void* block, unsigned int key) {
    void* moved = allocator->ScrapHeap_Allocate(key, DAT_00e27ed4);
    memcpy(moved, block, size);
    allocator->ScrapHeap_Deallocate(block);
    return moved;
}
}   // namespace f3m_005eb800

// @f3 0x005f3980 (community match, verified in this file)
namespace f3m_005f3980 {
// 0x005f3980 - scalar deleting destructor.
// Stores the class vtable, releases the heap block in +4 through the imported
// deallocator slot, clears the three members, then frees the object itself
// through the global memory manager when the delete flag is set.

extern void (__stdcall *DAT_00e02120)(void*);
extern int DAT_00e02118;

struct MM_005f3980 {
    void Deallocate(void* p);
};
extern MM_005f3980 DAT_01090a78;

struct Obj_005f3980 {
    void* vtable;
    void* unk04;
    int unk08;
    int unk0C;
    void* FUN_005f3980(int flags);
};

// pdb: BSSimpleArray<PathingNode *,1024>::`scalar deleting destructor' | Pathfind.obj | fnv360_0822_retail, vtable, medium
void* Obj_005f3980::FUN_005f3980(int flags)
{
    *(void**)this = &DAT_00e02118;
    if (unk04) {
        DAT_00e02120(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
    if (flags & 1)
        DAT_01090a78.Deallocate(this);
    return this;
}
}   // namespace f3m_005f3980

// @f3 0x005f3b00 (community match, verified in this file)
extern MemoryManager DAT_011f6238;
extern void* DAT_00e02100[];
namespace f3m_005f3b00 {
// BSSimpleArray<CrossedTriangle, 0x4000>::~BSSimpleArray -- the scalar deleting destructor the
// compiler emits for the (virtual) destructor: set the vptr, free the buffer through the array's
// own deallocate entry, zero the bookkeeping fields, then release the object to the memory manager
// when the delete flag is set.

class MemoryManager
{
public:
    void Deallocate(void* pointer);
};


// the array class's method table (slot 2 is its "deallocate one buffer" entry)

class FUN_005f3b00
{
public:
    virtual ~FUN_005f3b00();
    virtual void FUN_005f3b00_01(int index);
    virtual void FUN_005f3b00_02(void* pointer);
    virtual void FUN_005f3b00_03(int index);
    // pdb: BSSimpleArray<CrossedTriangle,1024>::`scalar deleting destructor' | Pathfind.obj | fnv360_0822_retail, vtable, medium
    static void operator delete(void* pointer) { DAT_011f6238.Deallocate(pointer); }

    void* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};

FUN_005f3b00::~FUN_005f3b00()
{
    if (pBuffer)
    {
        ((void (__stdcall*)(void*))DAT_00e02100[2])(pBuffer);
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
}   // namespace f3m_005f3b00

// @f3 0x005eb5e0 (community match, verified in this file)
namespace match5eb5e0 {
struct Base;
struct Table {void* unk00;void* (__thiscall* allocate)(Base*,unsigned);void (__thiscall* release)(Base*,void*);};
extern Table DAT_00dd8fd0,DAT_00e01eec;
struct Heap {void* FUN_0086bcb0();};extern Heap DAT_01090a78;
struct Base {Table* vtable;void* data;unsigned count,capacity;
 Base():data(0),count(0),capacity(0){}
 ~Base(){vtable=&DAT_00dd8fd0;if(data){vtable->release(this,data);data=0;capacity=0;count=0;}}
};
struct Array:Base {void* allocator;Array(unsigned,unsigned,void*);};
// pdb: BSScrapArray<TESObjectREFR *,1024>::BSScrapArray<TESObjectREFR *,1024> | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiReserveSize, aiInitialSize, apHeap
Array::Array(unsigned initialCapacity,unsigned initialCount,void* memory){
 vtable=&DAT_00e01eec;
 allocator=memory?memory:DAT_01090a78.FUN_0086bcb0();
 data=0;count=0;capacity=0;
 unsigned allocationCount=initialCapacity;
 if(initialCount>allocationCount)allocationCount=initialCount;
 if(allocationCount>0){data=vtable->allocate(this,allocationCount);capacity=allocationCount;}
 if(initialCount>0)count=initialCount;
}
}

// @f3 0x005fc5a0 (community match, verified in this file)
extern int DAT_00dc4dc0,DAT_00f47a58,DAT_00f46078,DAT_00f47a3c;
namespace f3m_005fc5a0 {
extern void* __cdecl TESForm_GetFormByNumericID(unsigned int);
extern void* __cdecl FUN_00c0050a(void*,int,const void*,const void*,int);
struct Vec89{float x,y,z;};
struct Descriptor89{
 unsigned int unk00,id,unk08,value,unk10,unk14,unk18;
 void* object;
 void* GetObject(){return object?object:TESForm_GetFormByNumericID(id);}
};
struct Owner89{
 void* vtable;Vec89 position;Descriptor89* descriptor;unsigned int unk14;
 void* secondary;void* primary;unsigned int value;unsigned short index;unsigned char flags;
 Owner89(const Vec89&,Descriptor89*,unsigned short);
};
// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation, apNavMeshInfo, ausTriangleIndex
Owner89::Owner89(const Vec89& point,Descriptor89* desc,unsigned short number){
 vtable=&DAT_00dc4dc0;position=point;flags=0;descriptor=desc;unk14=0;
 primary=FUN_00c0050a(desc->GetObject(),0,&DAT_00f46078,&DAT_00f47a58,0);
 if(primary){secondary=0;value=desc->value;}
 else{secondary=FUN_00c0050a(desc->GetObject(),0,&DAT_00f46078,&DAT_00f47a3c,0);value=0xdeaddead;}
 flags|=1;index=number;
}
}   // namespace f3m_005fc5a0

// @f3 0x005eb480 (community match, verified in this file)
namespace f3m_005eb480 {
extern int DAT_00e01ec4;
extern void (__stdcall *DAT_00e01ecc)(void*);
struct Buffer150 {
 void* vtable;
 void* data;
 unsigned int capacity;
 unsigned int length;
 void FUN_005eb480();
};
void Buffer150::FUN_005eb480(){
 vtable=&DAT_00e01ec4;
 if(data){DAT_00e01ecc(data);data=0;length=0;capacity=0;}
}


}   // namespace f3m_005eb480

// @f3 0x005e9c80 (community match, verified in this file)
namespace f3m_005e9c80 {
struct Block5e9c{void**table;long refs;};
struct Object5e9c{int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;int unk18;Block5e9c ref;};
__forceinline Block5e9c*RefBlock5e9c(Block5e9c*p){return p;}__forceinline Block5e9c*RefBlock5e9c(Object5e9c*p){return &p->ref;}
template<class T>struct Ref5e9c{T*p;Ref5e9c():p(0){}__forceinline static void Release(T*value){if(value){Block5e9c*block=RefBlock5e9c(value);if(!InterlockedDecrement(&block->refs))((void(__thiscall*)(Block5e9c*))block->table[1])(block);}}~Ref5e9c(){Release(p);}__forceinline Ref5e9c&operator=(const Ref5e9c&other){T*old=p;if(old!=other.p){Release(old);p=other.p;if(p)InterlockedIncrement(&RefBlock5e9c(p)->refs);}return *this;}};
struct Owner5e9c{Ref5e9c<Block5e9c>first;int index;int unk08;Ref5e9c<Object5e9c>last;Owner5e9c(const Ref5e9c<Block5e9c>&,int,const Ref5e9c<Object5e9c>&);};
// pdb: ObstacleTaskNavMeshOperation::PrintDebugText | NavMeshObstacleTask.obj | fnv360_0721_beta, objrun_open, low
// pdb params: aLoc, apText
Owner5e9c::Owner5e9c(const Ref5e9c<Block5e9c>&a,int value,const Ref5e9c<Object5e9c>&b){first=a;index=value;last=b;}
}   // namespace f3m_005e9c80

// @f3 0x005f3750 (community match, verified in this file)
namespace f3m_005f3750 {
extern void* DAT_00e020c4[];
extern void (__stdcall* DAT_00e020cc)(void*);
struct ReleasableArray {
 void** table;
 void* data;
 unsigned size;
 unsigned capacity;
 void FUN_005f3750();
};
void ReleasableArray::FUN_005f3750() {
 void* storage=data;
 table=DAT_00e020c4;
 if(storage) {DAT_00e020cc(storage);data=0;capacity=0;size=0;}
}

}   // namespace f3m_005f3750

// @f3 0x005fe940 (community match, verified in this file)
namespace f3m_005fe940 {
// 0x005fe940 - FUN_005fe940
// Scalar deleting destructor: stores the class vtable, releases the buffer at
// +4 through the global deallocation pointer, clears +4/+0C/+08, and frees the
// object through the memory manager when the flag argument has bit 0 set.

struct MemoryManager {
    void* Allocate(unsigned int size);
    void Deallocate(void* memory);
};
extern MemoryManager g_memoryManager;

typedef void (__thiscall *DeallocateFn)(void* self, void* memory);
extern DeallocateFn g_deallocateFn;

struct FUN_005fe940 {
    virtual ~FUN_005fe940();
    // pdb: BSSimpleArray<char,1024>::`scalar deleting destructor' | PathingLOSGridMap.obj | fnv360_0822_retail, vtable, medium
    void operator delete(void* memory) { g_memoryManager.Deallocate(memory); }
    void* unk04;
    int unk08;
    int unk0C;
};

FUN_005fe940::~FUN_005fe940()
{
    if (unk04) {
        g_deallocateFn(this, unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
}
}   // namespace f3m_005fe940

// @f3 0x005f4550 (community match, verified in this file)
struct InitialVector { float x, y, z; };
extern InitialVector DAT_0108ec68;
extern const float DAT_00db7260;
extern void* DAT_00e0209c[];

struct InitialState {
    InitialVector first, second;
    float distance, scale;
    void** table;
    unsigned unk24, unk28, unk2C, unk30, unk34;
    bool active;
    InitialState();
};

// pdb: CombatCoverSearchInfo::CombatCoverSearchInfo | Pathfind.obj | fnv360_0822_retail, objrun, medium
InitialState::InitialState()
{
    first = DAT_0108ec68;
    second = DAT_0108ec68;
    distance = 0.0f;
    *(volatile float*)&scale = -3.4028234663852886e+38f;
    table = DAT_00e0209c;
    unk24 = 0;
    unk28 = 0;
    unk2C = 0;
    unk30 = 0;
    unk34 = 0;
    active = false;
}

// @f3 0x005e05d0 (community match, verified in this file)
namespace f3m_005e05d0 {
namespace f3m_005e05d0 {
struct QLock05d0 {
    int unk00;
    int unk04;
    int unk08;
    QLock05d0() { unk04 = 0; }
    ~QLock05d0();
};
class FUN_0086cb70 {
public:
    int unk00, unk04, unk08, unk0c;
    FUN_0086cb70();
    ~FUN_0086cb70();
};
class FUN_005dfed0 {
public:
    int unk00, unk04, unk08, unk0c, unk10;
    FUN_005dfed0(int size, int flags, FUN_0086cb70* owner);
    ~FUN_005dfed0();
};
class FUN_005e0030 {
public:
    int unk00, unk04, unk08, unk0c, unk10;
    FUN_005e0030(int size, int flags, FUN_0086cb70* owner);
    ~FUN_005e0030();
};
struct Q05d0 {
    QLock05d0 lock;
    FUN_0086cb70 list;
    FUN_005dfed0 first;
    FUN_005e0030 second;
    Q05d0();
};
// pdb: NavMeshObstacleCutter::NavMeshObstacleCutter | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_seq, medium
Q05d0::Q05d0() : first(0x100, 0, &list), second(0x100, 0, &list)
{
}
}
}   // namespace f3m_005e05d0

// @f3 0x005ea8e0 (community match, verified in this file)
namespace f3m_005ea8e0 {
namespace f3m_005ea8e0 {
struct QInput8e0 { unsigned key; };
void QRelease8e0(void*);
struct QRefHolder8e0 { void* object; QRefHolder8e0() : object(0) {} ~QRefHolder8e0() { if (object) QRelease8e0(object); } };
struct QColl8e0 { int unk04; int unk08; int unk0C; QColl8e0() : unk04(0), unk08(0), unk0C(0) {} virtual ~QColl8e0(); };
struct QList8e0 { int unk04; int unk08; int unk0C; QList8e0() : unk04(0), unk08(0), unk0C(0) {} explicit QList8e0(int) {} virtual ~QList8e0(); };
struct QBase8e0 {
    unsigned char unk04; int unk08; unsigned char unk0C; int unk10; int unk14;
    QBase8e0() : unk04(0), unk08(0), unk0C(1), unk10(0) {}
    virtual ~QBase8e0();
};
struct QItem8e0 : QBase8e0 {
    QInput8e0* input;
    QRefHolder8e0 first;
    QRefHolder8e0 second;
    QColl8e0 collection;
    QList8e0 listA;
    QList8e0 listB;
    unsigned char unk54;
    QItem8e0(QInput8e0* in);
    virtual ~QItem8e0();
};
// pdb: ObstacleTaskData::ObstacleTaskData | NavMeshObstacleTask.obj | fnv360_0822_retail, objrun, medium
// pdb params: apNavMesh
QItem8e0::QItem8e0(QInput8e0* in) : listB(0)
{
    QRefHolder8e0 t1;
    QRefHolder8e0 t2;
    QInput8e0* p = in;
    listB.unk04 = 0;
    listB.unk08 = 0;
    listB.unk0C = 0;
    input = p;
    unk54 = 0;
}
}
}   // namespace f3m_005ea8e0

// @f3 0x005e0390 (community match, verified in this file)
namespace obstacle_undo_constructor {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern volatile long DAT_0108ed80;
void* __cdecl FUN_0089e810(unsigned int bytes);
extern "C" void* __cdecl FUN_00c00610(void* destination,int value,unsigned int bytes);
struct NiMemObject {};
struct NiRefObject : NiMemObject {
 virtual ~NiRefObject();unsigned int referenceCount;
 __forceinline NiRefObject() : referenceCount(0) { InterlockedIncrement(&DAT_0108ed80); }
};
struct BoundsTriangleInfo;struct PortalEdgeSwap;
template<class T,unsigned int Growth> struct BSSimpleArray;
extern unsigned short* (__thiscall* DAT_00dffe54)(BSSimpleArray<unsigned short,1024>*,unsigned int);
extern BoundsTriangleInfo* (__thiscall* DAT_00e01aa0)(BSSimpleArray<BoundsTriangleInfo,1024>*,unsigned int);
template<class T> struct ArrayAllocator { static T* Allocate(BSSimpleArray<T,1024>*,unsigned int); };
template<> struct ArrayAllocator<unsigned short> { static __forceinline unsigned short* Allocate(BSSimpleArray<unsigned short,1024>* self,unsigned int count) { return DAT_00dffe54(self,count); } };
template<> struct ArrayAllocator<BoundsTriangleInfo> { static __forceinline BoundsTriangleInfo* Allocate(BSSimpleArray<BoundsTriangleInfo,1024>* self,unsigned int count) { return DAT_00e01aa0(self,count); } };
template<class T,unsigned int Growth> struct BSSimpleArray {
 virtual ~BSSimpleArray();
 T* data;unsigned int size,capacity;
 __forceinline BSSimpleArray(unsigned int initial=0) : data(0),size(0),capacity(0) { if(initial) { data=ArrayAllocator<T>::Allocate(this,initial);capacity=initial; } }
};
struct ObstacleData;
template<class T> struct NiPointer { T* object;__forceinline NiPointer():object(0){} ~NiPointer(); };
template<class K,class V> struct NiTMapItem;
template<class T> struct DFALL {};
template<class A,class K,class V> struct NiTMapBase {
 virtual ~NiTMapBase();
 unsigned int hashSize;NiTMapItem<K,V>** buckets;unsigned int size;
 __forceinline NiTMapBase() : hashSize(37),size(0) { buckets=static_cast<NiTMapItem<K,V>**>(FUN_0089e810(hashSize*sizeof(void*)));FUN_00c00610(buckets,0,hashSize*sizeof(void*)); }
};
template<class K,class V> struct NiTMap : NiTMapBase<DFALL<NiTMapItem<K,V> >,K,V> { __forceinline NiTMap() {} };
struct BoundsTriangleInfo;struct PortalEdgeSwap;
struct ObstacleUndoData : NiRefObject {
 unsigned int unk08;NiPointer<NiRefObject> owner;unsigned int unk10,unk14,unk18,unk1C;
 BSSimpleArray<unsigned short,1024> triangleIds;
 BSSimpleArray<BoundsTriangleInfo,1024> triangleInfo;
 NiTMap<unsigned short,NiPointer<ObstacleData> > obstacles;
 BSSimpleArray<PortalEdgeSwap,1024> portalSwaps;
 BSSimpleArray<unsigned short,1024> extraTriangles;
 ObstacleUndoData();virtual ~ObstacleUndoData();
};
// pdb: ObstacleUndoData::ObstacleUndoData | NavMeshObstacleCutter.obj | fnv360_0822_retail, uvref, medium
ObstacleUndoData::ObstacleUndoData() : triangleIds(32),triangleInfo(32) { unk08=0; }
}

// @f3 0x005ffa60 (community match, verified in this file)
namespace f3m_005ffa60 {
namespace task1279 {
struct State {
    int unk04, unk08, unk0c;
    State(): unk04(0), unk08(0), unk0c(0) {}
    ~State();
};
struct FUN_005ffa60 {
    virtual ~FUN_005ffa60();
    State state;
    int unk10;
    FUN_005ffa60(int value);
    void FUN_005ff490(int value);
};
// pdb: PathingLOSGrid::Setup | PathingLOSGridMap.obj | fnv360_0721_beta, call_dedup, low
// pdb params: apNavMeshInfo
FUN_005ffa60::FUN_005ffa60(int value): unk10(0) {
    FUN_005ff490(value);
}
}
}   // namespace f3m_005ffa60

// @f3 0x005f43c0 (community match, verified in this file)
namespace f3m_005f43c0 {
namespace Scrap43C0 {
struct Heap { void* FUN_0086bcb0(); }; extern Heap DAT_01090a78;
class Simple { public: virtual ~Simple(); virtual void* Allocate(unsigned); virtual void Free(void*);
  void* data; unsigned size,capacity;
  __forceinline Simple():data(0),size(0),capacity(0) {} };
class FUN_005f43c0 : public Simple { public:
  void* allocator;
  virtual ~FUN_005f43c0();
  __forceinline void Init(unsigned initial,unsigned cap) { data=0; size=0; capacity=0; if(initial>cap) cap=initial; if(cap>0) { data=Allocate(cap); capacity=cap; } if(initial>0) size=initial; }
  FUN_005f43c0(unsigned cap,unsigned initial,void* alloc);
};
FUN_005f43c0::FUN_005f43c0(unsigned cap,unsigned initial,void* alloc) : Simple()
{
  if(!alloc) alloc=DAT_01090a78.FUN_0086bcb0();
  allocator=alloc;
  Init(initial,cap);
}
}
}   // namespace f3m_005f43c0

// @f3 0x005f38c0 (community match, verified in this file)
extern void* DAT_00e02154[]; extern void* DAT_00e02100[];
namespace f3m_005f38c0 {
extern void (__stdcall *DAT_00e0215c)(void*);
struct Base5F38;
extern void (__thiscall *DAT_00e02108)(Base5F38*,void*);
struct Base5F38 {
 void* data; unsigned size; unsigned capacity;
 virtual ~Base5F38() { if(data){ DAT_00e02108(this,data); data=0;capacity=0;size=0; } }
};
struct FUN_005f38c0 : Base5F38 { virtual ~FUN_005f38c0(); };
// pdb: BSScrapArray<CrossedTriangle,1024>::~BSScrapArray<CrossedTriangle,1024> | Pathfind.obj | fnv360_0822_debug, call_seq, low
FUN_005f38c0::~FUN_005f38c0(){ if(data){ DAT_00e0215c(data); data=0;capacity=0;size=0; } }
}   // namespace f3m_005f38c0

// @f3 0x005fe6a0 (community match, verified in this file)
namespace f3m_005fe6a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
namespace f3m_005fe6a0 {
class NiRefObject {
public:
    virtual void v00();
    virtual void DeleteThis();
    volatile long refCount;
    void DecRefCount() {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};
struct Key { int a; int b; int c; };
class Base1C { public: virtual void b00(); int unk[6]; };
class Finder : public Base1C, public NiRefObject {
public:
    unsigned int FUN_005b8df0(const Key& key);
};
template <class T> class NiPointer {
public:
    T* obj;
    NiPointer() : obj(0) {}
    ~NiPointer() {
        if (obj)
            obj->DecRefCount();
    }
    T* operator->() const { return obj; }
};
struct Request {
    int unk00;
    Key key;
    bool FUN_005fc8b0(NiPointer<Finder>* out);
};
struct Handler { bool FUN_005fe560(Request* req); };

class Dispatcher {
public:
    int unk00;
    Handler** handlers;
    unsigned int count;
    bool FUN_005fe6a0(Request* req);
};

// pdb: PathingLOSGrid::IsLocationSeen | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arLocation
bool Dispatcher::FUN_005fe6a0(Request* req)
{
    NiPointer<Finder> finder;
    if (req->FUN_005fc8b0(&finder)) {
        Key key = req->key;
        unsigned int index = finder->FUN_005b8df0(key);
        if (index < count) {
            Handler*& handler = handlers[index];
            return handler->FUN_005fe560(req);
        }
    }
    return false;
}
}
}   // namespace f3m_005fe6a0

// @f3 0x005f64f0 (community match, verified in this file)
#include <windows.h>
namespace Collect5f64f0 {
struct Ref;
struct RefTable { void* unk00; void (__thiscall* destroy)(Ref*); };
struct Ref { RefTable* table; long refs; };
struct Resource { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18; Ref ref; };
struct Smart {
    Resource* object;
    ~Smart() { if(object) { Ref* base=&object->ref; if(!InterlockedDecrement(&base->refs)) base->table->destroy(base); } }
};
struct Registry { unsigned unk00,unk04; unsigned size; Smart FUN_0043c300(unsigned); };
struct Group { Registry* FUN_007e55b0(); };
struct Manager {
    unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    Group* active;
    unsigned unk38;
    Group** groups;
    unsigned FUN_00433530();
};
extern Manager* DAT_0107a0d8;
struct Sink { void FUN_0041a4b0(const Smart&); };
// pdb: Pathing::GetAllLoadedNavmeshes | Pathfind.obj | fnv360_0721_beta, caller_sim, low
// pdb params: apRetNavMeshes
bool __cdecl FUN_005f64f0(Sink* out) {
    Group* active=DAT_0107a0d8->active;
    if(active) {
        Registry* list=active->FUN_007e55b0();
        if(list) for(unsigned i=0;i<list->size;++i) out->FUN_0041a4b0(list->FUN_0043c300(i));
    } else {
        unsigned n=DAT_0107a0d8->FUN_00433530();
        for(unsigned j=0;j<n;++j) {
            Group* group=DAT_0107a0d8->groups[j];
            if(group) {
                Registry* list=group->FUN_007e55b0();
                if(list) for(unsigned i=0;i<list->size;++i) out->FUN_0041a4b0(list->FUN_0043c300(i));
            }
        }
    }
    return true;
}
}

// @f3 0x005fe850 (community match, verified in this file)
namespace f3m_005fe850 {

namespace task1535 {
typedef void* Element;
struct Array {
 virtual ~Array();virtual Element* Allocate(unsigned);virtual void Free(Element*);
 Element* data;unsigned size,capacity;
 void FUN_005eb1c0(unsigned,unsigned);
 void Construct(Element* p,unsigned n){for(unsigned i=0;i<n;++i)new(p+i)Element;}
 void Destroy(Element* p,unsigned n){for(unsigned i=0;i<n;++i)p[i].~Element();}
 void FUN_005fe850(unsigned n,bool trim);
};
// pdb: BSSimpleArray<char,1024>::SetSize | PathingLOSGridMap.obj | fnv360_0721_beta, call_seq, low
// pdb params: aiNewSize, abFreeMemory
void Array::FUN_005fe850(unsigned n,bool trim){
 if(!n){if(data){if(trim){Free(data);data=0;capacity=0;}size=0;}return;}
 if(n>capacity){if(!capacity){data=Allocate(n);capacity=n;}else{FUN_005eb1c0(n,size);capacity=n;}Construct(data+size,n-size);size=n;}
 else if(n<size){Destroy(data+n,size-n);size=n;if(trim&&n<=(capacity>>2)){FUN_005eb1c0(n,n);capacity=n;}}
 else {Construct(data+size,n-size);size=n;}
}
}
}   // namespace f3m_005fe850

// @f3 0x005f2290 (community match, verified in this file)
extern float DAT_00de7c24;
namespace f3m_005f2290 {

namespace f3m_005f2290 {

struct Vec
{
    float x;
    float y;
    float z;
};

typedef f3m_005f2190::Resource5f2190 Resource;
typedef NiPointer<Resource> ResourcePtr;

struct ResourceQuery
{
    bool FUN_005bdc10(int index, Vec* point, float range1, float range2, float* out);
};

struct Subject
{
    int unk00;
    Vec position;

    bool FUN_005fda30(int flag);
    bool FUN_005fc750();
    bool FUN_005fc8f0(ResourcePtr* resource, int* index);
};

// pdb: Pathing::GetNavMeshZForLocation | Pathfind.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aLocation, aRetHeight
bool __cdecl FUN_005f2290(Subject* subject, float* out)
{
    Vec point;
    if (!subject->FUN_005fda30(0)) {
        point = subject->position;
        *out = point.z;
        return false;
    }
    if (!subject->FUN_005fc750()) {
        point = subject->position;
        *out = point.z;
        return false;
    }

    ResourcePtr resource;
    int index;
    if (!subject->FUN_005fc8f0(&resource, &index)) {
        point = subject->position;
        *out = point.z;
        return false;
    }

    point = subject->position;
    ResourceQuery* query = (ResourceQuery*)resource.m_pObject;
    if (!query->FUN_005bdc10(index, &point, ::DAT_00de7c24, ::DAT_00de7c24, out)) {
        Vec fallback = subject->position;
        *out = fallback.z;
        return false;
    }
    return true;
}

}
}   // namespace f3m_005f2290

// @f3 0x005fc950 (community match, verified in this file)
namespace f3m_005fc950 {
class TESForm {public: virtual ~TESForm();};
class TESWorldSpace : public TESForm {};
namespace Task1542 {
struct Stream {void FUN_006e0750(void*,unsigned);void FUN_006e06d0(unsigned*);unsigned FUN_006e0670();};
struct Map {bool FUN_00bea7b0(unsigned,void**);};
struct Pathing {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18;Map map;
 void* Find(unsigned id){void* found;return map.FUN_00bea7b0(id,&found)?found:0;}
};
struct Manager {Pathing* FUN_00433ff0();};extern Manager* DAT_0107a0d8;
TESForm* TESForm_GetFormByNumericID(unsigned);
void* FUN_005f1260(TESWorldSpace*,unsigned);
void* FUN_005f1240(TESObjectCELL*);
struct Point {float x,y,z;};
struct Location {unsigned unk00;Point position;void* navmesh;void* meshes;TESObjectCELL* cell;TESWorldSpace* world;unsigned flags;unsigned short triangle;unsigned char state;unsigned char unk27;void FUN_005fc950(Stream*);};
// pdb: PathingLocation::LoadGame | PathingLocation.obj | fnv360_0822_retail, vtable, medium
// pdb params: apLoadGameBuffer
void Location::FUN_005fc950(Stream* stream) {
 stream->FUN_006e0750(&position,12);
 unsigned id=0;
 stream->FUN_006e06d0(&id);
 navmesh=DAT_0107a0d8->FUN_00433ff0()->Find(id);
 cell=dynamic_cast<TESObjectCELL*>(TESForm_GetFormByNumericID(stream->FUN_006e0670()));
 world=dynamic_cast<TESWorldSpace*>(TESForm_GetFormByNumericID(stream->FUN_006e0670()));
 stream->FUN_006e0750(&flags,4);
 stream->FUN_006e0750(&triangle,2);
 triangle=65535;
 stream->FUN_006e0750(&state,1);
 bool hasMeshes=false;
 stream->FUN_006e0750(&hasMeshes,1);
 if(hasMeshes) {if(world) meshes=FUN_005f1260(world,flags);else if(cell) meshes=FUN_005f1240(cell);}
}
}
}   // namespace f3m_005fc950

// @f3 0x005e7610 (community match, verified in this file)
namespace task1583 {
struct Heap { void* FUN_0086bcb0(); };
extern Heap DAT_01090a78;
struct ArrayBase {
 ArrayBase() : data(0), size(0), capacity(0) {}
 virtual ~ArrayBase();
 void* data;
 unsigned int size, capacity;
};
struct FUN_005e7610 : ArrayBase {
 FUN_005e7610();
 virtual ~FUN_005e7610();
 void* allocator;
};
// pdb: NavMeshObstacleManager::AddBoundingBox3DNode | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: aBox
FUN_005e7610::FUN_005e7610() {
 allocator=DAT_01090a78.FUN_0086bcb0();
 data=0; size=0; capacity=0;
}
}

// @f3 0x005fd3e0 (community match, verified in this file)
namespace f3m_005fd3e0 {
namespace Task1584 {
struct Heap {void* FUN_0086bcb0();};extern Heap DAT_01090a78;
struct FUN_0053a0e0 {
 virtual ~FUN_0053a0e0();
 void* data;unsigned size,capacity;
 FUN_0053a0e0():data(0),size(0),capacity(0){}
};
struct FUN_005fd3e0:FUN_0053a0e0 {
 void* allocator;
 FUN_005fd3e0();
 virtual ~FUN_005fd3e0();
};
FUN_005fd3e0::FUN_005fd3e0() {
 allocator=DAT_01090a78.FUN_0086bcb0();
 data=0;size=0;capacity=0;
}
}
}   // namespace f3m_005fd3e0

// @f3 0x005ffac0 (community match, verified in this file)
#include <windows.h>
extern long DAT_0108ed80;
namespace f3m_005ffac0 {
namespace n5ffac0 {
struct Base {
    virtual ~Base() { InterlockedDecrement(&DAT_0108ed80); }
    int unk04;
};
struct FUN_005fe310 { int unk00,unk04,unk08,unk0c,unk10; ~FUN_005fe310(); };
struct Entry { virtual ~Entry() {} };
struct FUN_005ffac0 : Base {
    FUN_005fe310 member;
    Entry entry;
    void FUN_005ff580();
    virtual ~FUN_005ffac0();
};
// pdb: PathingLOSGridMap::~PathingLOSGridMap | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
FUN_005ffac0::~FUN_005ffac0() { FUN_005ff580(); }
}
}   // namespace f3m_005ffac0

// @f3 0x005f2760 (community match, verified in this file)
namespace f3m_005f2760 {
namespace Query1686 {
struct Point { float x,y,z; }; struct Cell; struct World;
struct FUN_005fd540 {
 virtual ~FUN_005fd540() {}
 unsigned unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24;
 FUN_005fd540(const Point&,Cell*,World*);
};
bool __cdecl FUN_005f2290(FUN_005fd540*,void*);
// pdb: Pathing::GetNavMeshZForLocation | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation, apCell, apWorldSpace, aRetHeight
bool __cdecl FUN_005f2760(const Point& p,Cell* c,World* w,void* arg) {
 FUN_005fd540 loc(p,c,w);return FUN_005f2290(&loc,arg);
}
}
}   // namespace f3m_005f2760

// @f3 0x005e6e80 (community match, verified in this file)
extern long DAT_0108ed80;
namespace f3m_005e6e80 {
namespace task1759 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefBase {virtual ~RefBase();long refs;RefBase();};
inline RefBase::RefBase():refs(0){InterlockedIncrement(&DAT_0108ed80);}
struct List {virtual ~List();virtual void* Allocate(unsigned);virtual void Deallocate(void*);virtual void* Reallocate(void*,unsigned);void* buffer;unsigned size,capacity;List(unsigned reserve=0){buffer=0;size=0;capacity=0;if(reserve){buffer=Allocate(reserve);capacity=reserve;}}};
struct FUN_005e6e80:RefBase {void* value;List list;FUN_005e6e80();virtual ~FUN_005e6e80();};
// pdb: NiPointer<ReferenceObstacleArray>::operator= | NavMeshObstacleManager.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: pObject
FUN_005e6e80::FUN_005e6e80(){value=0;}
}
}   // namespace f3m_005e6e80

// @f3 0x005f1540 (community match, verified in this file)
namespace match5f1540 {
extern __declspec(thread) int allocationContext;
struct ContextGuard {
 int saved;
 ContextGuard():saved(allocationContext) {allocationContext=45;}
 ~ContextGuard(){allocationContext=saved;}
};
struct Vec3 {float x,y,z;};
struct Counter { void** table; long refs; void Release(){if(!InterlockedDecrement(&refs)) ((void (__thiscall*)(Counter*))table[1])(this);} };
struct Triangle {unsigned short a,b,c,unk06,unk08,unk0a,unk0c,unk0e;};
extern const double DAT_00dcd290;
struct Resource {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18; Counter counter;
 int unk24,unk28;Vec3* vertices;int unk30,unk34,unk38;Triangle* triangles;
 void IncRefCount(){InterlockedIncrement(&counter.refs);}
 void DecRefCount(){counter.Release();}
 __declspec(noinline) Vec3 FUN_004d45e0(unsigned short index) {
 Triangle* triangle=&triangles[index];
 Vec3 result=vertices[triangle->a];
 const Vec3& second=vertices[triangle->b]; const Vec3& third=vertices[triangle->c];
 result.x=(float)((float)(result.x+second.x)+third.x)*DAT_00dcd290;
 result.y=(float)((float)(result.y+second.y)+third.y)*DAT_00dcd290;
 result.z=(float)((float)(result.z+second.z)+third.z)*DAT_00dcd290;
 return result;
 }
};
extern void* DAT_00dc4dc0[];
struct Point {
 void** table; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
 Point(Vec3* pos,void* second,void* first){FUN_005fd540(pos,second,first);}
 ~Point(){table=DAT_00dc4dc0;}
 void FUN_005fd540(Vec3*,void*,void*);
 bool FUN_005fda30(int);
 bool FUN_005fc750();
 bool FUN_005fcc10();
 bool FUN_005fc8f0(NiPointer<Resource>*,int*);
};
// pdb: Pathing::FindClosestPointOnNavmesh | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apWorldSpace, apCell, aLocation, apRetPt
bool __cdecl FUN_005f1540(void* first,void* second,Vec3* input,Vec3* out){
 ContextGuard guard;
 Point point(input,second,first);
 if(point.FUN_005fda30(0)&&point.FUN_005fc750()) {*out=*input;return true;}
 if(point.FUN_005fcc10()) {
  NiPointer<Resource> resource; int index;
  if(point.FUN_005fc8f0(&resource,&index)){Resource* value=resource; *out=value->FUN_004d45e0(index);return true;}
 }
 return false;
}
}

// @f3 0x005ed500 (community match, verified in this file)
extern unsigned char DAT_01074880;
extern int DAT_00e01240;
namespace f3m_005ed500 {
namespace task1795 {
extern unsigned long (__stdcall *DAT_00d9b070)();
struct TaskManager { virtual void v00(); virtual void v04(); virtual void v08(); virtual bool IsTaskletThread(unsigned long); };
TaskManager* FUN_00bce1f0();
struct Location { void* vt; float x,y,z; void* nav; void* array; void* cell; void* world; unsigned flags; unsigned short triangle; unsigned char state; Location& FUN_005fc480(const Location&); };
struct Request { int type; void* owner; Location start,goal; void* vt58; void* data; unsigned size,capacity; Request(){FUN_005ec420();} ~Request(){FUN_005ec490();} void FUN_005ec420(); void FUN_005ec490(); };
struct Path { void* vt; void* data; unsigned size,capacity; Path():vt(&DAT_00e01240),data(0),size(0),capacity(0){} ~Path(){FUN_005d0d90();} void FUN_005d0d90(); void FUN_005ecef0(void*); };
struct Result { int a,b; Path path; };
struct Search { Search(){FUN_00603770();} ~Search(){FUN_00603800();} void FUN_00603770(); void FUN_00603800(); int FUN_00604430(Request*,Result*);
int unk00;
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
int unk60;
int unk64;
int unk68;
int unk6c;
int unk70;
int unk74;
int unk78;
int unk7c;
int unk80;
int unk84;
int unk88;
int unk8c;
int unk90;
};
struct Manager { int FUN_00608b80(void*,Location*,Location*,void*); };
Manager* FUN_0044f4b0();
struct Builder { void* request; int FUN_005ed500(Location&,Location&,void*); };
// pdb: PathBuilder::BuildStraightPathUsingRayCasts | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aStartLocation, aGoalLocation, aRetPath
int Builder::FUN_005ed500(Location& start,Location& goal,void* output) {
 if(DAT_01074880) {
  TaskManager* manager=FUN_00bce1f0();
  unsigned long thread=DAT_00d9b070();
  if(manager->IsTaskletThread(thread)) return FUN_0044f4b0()->FUN_00608b80(request,&start,&goal,output);
  Request r;
  r.start.FUN_005fc480(start); r.goal.FUN_005fc480(goal); r.type=2; r.owner=request;
  Result result;
  Search search;
  if(search.FUN_00604430(&r,&result)==1) { result.path.FUN_005ecef0(output); return 1; }
  else return 2;
 }
 return 2;
}
}
}   // namespace f3m_005ed500

// @f3 0x005e2a10 (community match, verified in this file)
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_005e2a10 {
extern "C" void _ReadWriteBarrier();
void* __cdecl FUN_0089eb90(unsigned int size);

class NiPoint3
{
public:
    float x;
    float y;
    float z;

    NiPoint3() {}
    NiPoint3(float a_x, float a_y, float a_z)
    {
        x = a_x;
        y = a_y;
        z = a_z;
    }
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }

    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class ObstacleData : public NiRefObject
{
};

struct NavMeshVertex
{
    NiPoint3 Location;
};

struct NavMeshTriangle
{
    unsigned short sVertex0;
    unsigned short sVertex1;
    unsigned short sVertex2;
    unsigned short sTriangle0;
    unsigned short sTriangle1;
    unsigned short sTriangle2;
    unsigned int TriangleFlags;

    void SetFlag(unsigned int a_uiFlag)
    {
        TriangleFlags |= a_uiFlag;
    }
};

struct BoundsTriangleInfo
{
    int unk00;
    int unk04;
};

struct PortalEdgeSwap
{
    int unk00;
    int unk04;
    int unk08;
};

struct TaskPortalSwap
{
    int unk00;
};

struct NavMeshObstacleVertex
{
    unsigned short usVertexIndex;
    bool bOnObstacle;
    bool bOnBounds;
    bool bOnOpenEdge;
    bool bInOverlappedArea;
    bool bInObstacleArea;
};

struct NavMeshObstacleEdge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiPointer<ObstacleData> spObstacle;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

template <class T>
class SimpleArray
{
public:
    virtual ~SimpleArray();
    virtual T* _Allocate(unsigned int a_iCount);
    virtual void _Deallocate(T* a_pData);
    virtual T* _Reallocate(T* a_pData, unsigned int a_iCount);

    T* pBuffer;
    unsigned int iSize;
    unsigned int iReservedSize;

    unsigned int GetSize() const
    {
        return iSize;
    }

    bool IsEmpty() const
    {
        return iSize == 0;
    }

    T& operator[](unsigned int a_iIndex)
    {
        return pBuffer[a_iIndex];
    }

    const T& operator[](unsigned int a_iIndex) const
    {
        return pBuffer[a_iIndex];
    }

    void Clear(bool a_bFreeMemory)
    {
        if (pBuffer)
        {
            if (a_bFreeMemory)
            {
                _Deallocate(pBuffer);
                pBuffer = 0;
                iReservedSize = 0;
            }
            iSize = 0;
        }
    }
};

template <class T>
class ScrapArray : public SimpleArray<T>
{
public:
    void* pScrapHeap;
};

class VertexArray : public SimpleArray<NavMeshVertex>
{
public:
    void FUN_0079e680(NavMeshVertex* a_pDest, NavMeshVertex* a_pSrc, unsigned int a_iCount);
    void FUN_0079ecc0(unsigned int a_iNewSize, unsigned int a_iMoveCount);

    void _ReallocateBufferInline(unsigned int a_iNewSize, unsigned int a_iMoveCount)
    {
        if (pBuffer)
        {
            if (a_iMoveCount == iReservedSize)
            {
                pBuffer = _Reallocate(pBuffer, a_iNewSize);
            }
            else
            {
                NavMeshVertex* pNewBuffer = _Allocate(a_iNewSize);
                FUN_0079e680(pNewBuffer, pBuffer, a_iMoveCount);
                _Deallocate(pBuffer);
                pBuffer = pNewBuffer;
            }
        }
        else
        {
            pBuffer = _Allocate(a_iNewSize);
            iReservedSize = a_iNewSize;
        }
    }

    void SetSize(unsigned int a_iSize, bool a_bFreeMemory)
    {
        if (a_iSize == 0)
        {
            Clear(a_bFreeMemory);
        }
        else if (a_iSize > iReservedSize)
        {
            if (iReservedSize == 0)
            {
                pBuffer = _Allocate(a_iSize);
                iReservedSize = a_iSize;
            }
            else
            {
                _ReallocateBufferInline(a_iSize, iSize);
                iReservedSize = a_iSize;
            }
            iSize = a_iSize;
        }
        else if (a_iSize < iSize)
        {
            iSize = a_iSize;
            if (a_bFreeMemory && a_iSize <= (iReservedSize >> 2))
            {
                FUN_0079ecc0(a_iSize, a_iSize);
                iReservedSize = a_iSize;
            }
        }
        else
        {
            iSize = a_iSize;
        }
    }
};

class TriangleArray : public SimpleArray<NavMeshTriangle>
{
public:
    void FUN_005b8560(NavMeshTriangle* a_pDest, NavMeshTriangle* a_pSrc, unsigned int a_iCount);
    void FUN_005b8620(unsigned int a_iNewSize, unsigned int a_iMoveCount);

    void _ReallocateBufferInline(unsigned int a_iNewSize, unsigned int a_iMoveCount)
    {
        if (pBuffer)
        {
            if (a_iMoveCount == iReservedSize)
            {
                pBuffer = _Reallocate(pBuffer, a_iNewSize);
            }
            else
            {
                NavMeshTriangle* pNewBuffer = _Allocate(a_iNewSize);
                FUN_005b8560(pNewBuffer, pBuffer, a_iMoveCount);
                _Deallocate(pBuffer);
                pBuffer = pNewBuffer;
            }
        }
        else
        {
            pBuffer = _Allocate(a_iNewSize);
            iReservedSize = a_iNewSize;
        }
    }

    void SetSize(unsigned int a_iSize, bool a_bFreeMemory)
    {
        if (a_iSize == 0)
        {
            Clear(a_bFreeMemory);
        }
        else if (a_iSize > iReservedSize)
        {
            if (iReservedSize == 0)
            {
                pBuffer = _Allocate(a_iSize);
                iReservedSize = a_iSize;
            }
            else
            {
                _ReallocateBufferInline(a_iSize, iSize);
                iReservedSize = a_iSize;
            }
            iSize = a_iSize;
        }
        else if (a_iSize < iSize)
        {
            iSize = a_iSize;
            if (a_bFreeMemory && a_iSize <= (iReservedSize >> 2))
            {
                FUN_005b8620(a_iSize, a_iSize);
                iReservedSize = a_iSize;
            }
        }
        else
        {
            iSize = a_iSize;
        }
    }
};

struct MapItem
{
    MapItem* m_pkNext;
    unsigned short m_key;
    NiPointer<ObstacleData> m_val;
};

class TriangleObstacleMap
{
public:
    virtual ~TriangleObstacleMap();
    virtual unsigned int KeyToHashIndex(unsigned short a_usKey) const;
    virtual bool IsKeysEqual(unsigned short a_usKey1, unsigned short a_usKey2) const;
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    __declspec(noinline) bool FUN_005bcd40(unsigned short a_usKey, NiPointer<ObstacleData>& a_spVal) const
    {
        unsigned int uiIndex = KeyToHashIndex(a_usKey);
        MapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(a_usKey, pkItem->m_key))
            {
                a_spVal = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    void FUN_005bb420(unsigned short a_usKey, NiPointer<ObstacleData> a_spVal);
    bool FUN_005df1f0(unsigned short a_usKey);
};

class FUN_005e0390 : public NiRefObject
{
public:
    int eState;
    NiPointer<ObstacleData> spObstacle;
    unsigned int iFirstAddedVertexIndex;
    unsigned int iAddedVertexCount;
    unsigned int iFirstAddedTriangleIndex;
    unsigned int iAddedTriangleCount;
    SimpleArray<unsigned short> OverlappedTriangles;
    SimpleArray<BoundsTriangleInfo> BoundsTriangles;
    TriangleObstacleMap RemovedTriangleToObstacleMap;
    SimpleArray<PortalEdgeSwap> EdgeSwap;
    SimpleArray<unsigned short> AddedPOVs;

    static void* operator new(unsigned int a_uiSize)
    {
        return FUN_0089eb90(a_uiSize);
    }
    static void operator delete(void* a_pMem);

    FUN_005e0390();
};

class NavMesh
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    VertexArray Vertices;
    TriangleArray Triangles;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    TriangleObstacleMap* pTriangleToObstacleMap;

    unsigned int GetVertexCount() const
    {
        return Vertices.GetSize();
    }

    unsigned int GetTriangleCount() const
    {
        return Triangles.GetSize();
    }

    NavMeshVertex* GetVertex(unsigned short a_usIndex)
    {
        return &Vertices[a_usIndex];
    }

    NavMeshTriangle* GetTriangle(unsigned short a_usIndex)
    {
        return &Triangles[a_usIndex];
    }

    void FUN_005c08a0(const NiPointer<ObstacleData>& a_spObstacle, const NiPoint3& a_rSlop, SimpleArray<unsigned short>* a_pTriangles);
    bool FUN_005c03c0(unsigned short a_usFirst, unsigned short a_usLast);
    void FUN_005ba4e0();
    unsigned int FUN_005c16b0(FUN_005e0390* a_pUndoData);
};

class NavMeshObstacleCutter
{
public:
    NavMesh* pNavMesh;
    NiPointer<ObstacleData> spObstacle;
    FUN_005e0390* pUndoData;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ScrapArray<NavMeshObstacleVertex*> Vertices;
    ScrapArray<NavMeshObstacleEdge*> Edges;
    unsigned int iMaxObstacleCount;

    unsigned int FUN_005df3b0();
    void FUN_005e0860(SimpleArray<BoundsTriangleInfo>& a_rBoundsTriangles);
    void FUN_005e1810();
    void FUN_005e1c70();
    void FUN_005e2110();
    bool FUN_005df790(const NiPoint3& a_rPt);
    void FUN_005df9a0();
    void FUN_005e0a60();
    bool FUN_005e0da0();
    void FUN_005e0bc0();
    void FUN_005df4f0();
    void FUN_005e27a0(TaskPortalSwap& a_rPortalSwap);
    void FUN_005df430();
    void FUN_005e2690();

    bool IsVertInObstacleArea(NavMeshObstacleVertex* a_pVertex)
    {
        return FUN_005df790(pNavMesh->GetVertex(a_pVertex->usVertexIndex)->Location);
    }

    void AddNewTrianglesToNavMeshGrid()
    {
        if (pUndoData->iAddedTriangleCount != 0)
        {
            pNavMesh->FUN_005c03c0(
                (unsigned short)pUndoData->iFirstAddedTriangleIndex,
                (unsigned short)(pUndoData->iFirstAddedTriangleIndex + pUndoData->iAddedTriangleCount - 1));
        }
    }

    void UpdateCoverArray()
    {
        pNavMesh->FUN_005ba4e0();
    }

    bool FUN_005e2a10(NavMesh* a_pNavMesh, const NiPointer<ObstacleData>& a_spObstacle, TaskPortalSwap& a_rPortalSwap);
};

// pdb: NavMeshObstacleCutter::SplitNavMeshFromObstacle | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apNavMesh, aBox, aPortalSwaps
bool NavMeshObstacleCutter::FUN_005e2a10(NavMesh* a_pNavMesh, const NiPointer<ObstacleData>& a_spObstacle, TaskPortalSwap& a_rPortalSwap)
{
    pNavMesh = a_pNavMesh;
    spObstacle = a_spObstacle;

    Vertices.Clear(false);

    for (unsigned int i = 0; i < Edges.GetSize(); i++)
    {
        if (Edges[i]->spObstacle)
            Edges[i]->spObstacle->DecRefCount();
    }
    Edges.Clear(false);

    pUndoData = new FUN_005e0390();

    pNavMesh->FUN_005c08a0(a_spObstacle, NiPoint3(5.0f, 5.0f, 5.0f), &pUndoData->OverlappedTriangles);

    if (pUndoData->OverlappedTriangles.IsEmpty())
    {
        delete pUndoData;
        return false;
    }

    pUndoData->eState = 1;
    pUndoData->spObstacle = a_spObstacle;
    pUndoData->iFirstAddedVertexIndex = pNavMesh->GetVertexCount();
    unsigned int uiTriCount = pNavMesh->GetTriangleCount();
    _ReadWriteBarrier();
    pUndoData->iFirstAddedTriangleIndex = uiTriCount;

    iMaxObstacleCount = FUN_005df3b0();

    FUN_005e0860(pUndoData->BoundsTriangles);

    for (unsigned int i = 0; i < pUndoData->OverlappedTriangles.GetSize(); i++)
    {
        pNavMesh->GetTriangle(pUndoData->OverlappedTriangles[i])->SetFlag(0x20);
    }

    FUN_005e1810();

    for (unsigned int i = 0; i < pUndoData->OverlappedTriangles.GetSize(); i++)
    {
        unsigned short usTri = pUndoData->OverlappedTriangles[i];
        NiPointer<ObstacleData> spOldObstacle(0);
        if (pNavMesh->pTriangleToObstacleMap->FUN_005bcd40(usTri, spOldObstacle))
        {
            pUndoData->RemovedTriangleToObstacleMap.FUN_005bb420(usTri, spOldObstacle);
            pNavMesh->pTriangleToObstacleMap->FUN_005df1f0(usTri);
        }
    }

    FUN_005e1c70();
    FUN_005e2110();

    for (unsigned int i = 0; i < Vertices.GetSize(); i++)
    {
        if (IsVertInObstacleArea(Vertices[i]))
            Vertices[i]->bInObstacleArea = true;
    }

    FUN_005df9a0();
    FUN_005e0a60();

    if (!FUN_005e0da0())
    {
        pNavMesh->Vertices.SetSize(pUndoData->iFirstAddedVertexIndex, true);
        pNavMesh->Triangles.SetSize(pUndoData->iFirstAddedTriangleIndex, true);
        delete pUndoData;
        return false;
    }

    FUN_005e0bc0();
    FUN_005e0da0();
    FUN_005df4f0();
    FUN_005e27a0(a_rPortalSwap);

    pUndoData->iAddedVertexCount = pNavMesh->GetVertexCount() - pUndoData->iFirstAddedVertexIndex;
    pUndoData->iAddedTriangleCount = pNavMesh->GetTriangleCount() - pUndoData->iFirstAddedTriangleIndex;

    FUN_005df430();

    for (unsigned int i = pUndoData->iFirstAddedTriangleIndex; i < pUndoData->iFirstAddedTriangleIndex + pUndoData->iAddedTriangleCount; i++)
    {
        pNavMesh->pTriangleToObstacleMap->FUN_005bb420(i, spObstacle);
    }

    AddNewTrianglesToNavMeshGrid();
    UpdateCoverArray();
    FUN_005e2690();

    pNavMesh->FUN_005c16b0(pUndoData);
    return true;
}
}   // namespace f3m_005e2a10

// @f3 0x005e6030 (community match, verified in this file)
class bhkRigidBody;
#include <stddef.h>
namespace QueueMemory2024 {struct Heap{void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;}
void* __cdecl operator new(size_t bytes){return QueueMemory2024::DAT_01090a78.FUN_0086b930(bytes);}
void* __cdecl operator new[](size_t bytes){return QueueMemory2024::DAT_01090a78.FUN_0086b930(bytes);}
extern __declspec(thread) int DAT_0117c298;
namespace QueueConstruct2024 {
struct InterfacedClass{virtual ~InterfacedClass();};
struct MemoryContext{int saved;MemoryContext(){saved=DAT_0117c298;DAT_0117c298=6;}~MemoryContext(){DAT_0117c298=saved;}};
struct Entry{Entry* next;bhkRigidBody* data;Entry() throw():next(0),data(0){}};
struct FUN_005e5280{unsigned int unk00,unk04,unk08,unk0C;FUN_005e5280(unsigned int);};
struct Queue:InterfacedClass{Entry* head;Entry* tail;unsigned int deleteBatchSize;Entry** deletedBuffers;FUN_005e5280* manager;volatile int count;Queue(unsigned int,unsigned int);virtual ~Queue();};
// pdb: LockFreeQueue<bhkRigidBody *>::LockFreeQueue<bhkRigidBody *> | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiMaxThreads, aiDeleteBatchSize
Queue::Queue(unsigned int threads,unsigned int batch){MemoryContext context;count=0;head=new Entry;tail=head;deleteBatchSize=batch;deletedBuffers=new Entry*[threads*2];manager=new FUN_005e5280(threads);}
}

// @f3 0x005ec900 (community match, verified in this file)
#include <float.h>

extern void* DAT_00dd8fe4[];

namespace f3m_005ec900 {

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator-(const NiPoint3& pt) const {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3 operator*(float fScalar) const {
        return NiPoint3(fScalar * x, fScalar * y, fScalar * z);
    }
    NiPoint3& operator+=(const NiPoint3& pt) {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
    float SqrLength() const {
        return x * x + y * y + z * z;
    }
};

extern NiPoint3 DAT_0108ec68;

struct BSRefObject {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(BSRefObject*))vtable[1])(this);
    }
};

struct NavMeshEdgeVertices {
    const NiPoint3* pVertex0;
    const NiPoint3* pVertex1;
};

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BSRefObject ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    bool FUN_005bd410(const NiPoint3& ar_Location, float af_Radius, unsigned short* ap_usTriangle, int* ap_iEdgeIndex, bool ab_AllowWater);
    NavMeshEdgeVertices FUN_005b8900(unsigned short a_usTriangle, int a_iEdgeIndex);
    __declspec(noinline) NiPoint3 FUN_004d45e0(unsigned short a_usTriangle) const {
        return NiPoint3(a_usTriangle, a_usTriangle, a_usTriangle);
    }
};

__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<NavMesh>* ap_spNavMesh, NavMesh* ap_NavMesh) {
    ap_spNavMesh->m_pObject = ap_NavMesh;
}
bool __cdecl FUN_005dd580(const NiPoint3& ar_P1, const NiPoint3& ar_P2, const NiPoint3& ar_P3, const NiPoint3& ar_P4, NiPoint3* ap_Result);

struct NavMeshInfo {
    int unk00;
    int unk04;
    unsigned int uiFlags;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    NavMesh* pNavMesh;
    bool GetDisabled() const { return (uiFlags >> 4) & 1; }
    bool GetNavMesh(NiPointer<NavMesh>& ar_spNavMesh) const {
        if (GetDisabled())
            return false;
        FUN_005b87d0(&ar_spNavMesh, pNavMesh);
        return ar_spNavMesh.m_pObject != 0;
    }
};

struct NavMeshInfoArray;
extern void (__thiscall* DAT_00dd8fec)(NavMeshInfoArray*, void*);

struct NavMeshInfoArray {
    void** table;
    const NavMeshInfo** data;
    unsigned int size;
    unsigned int capacity;
    NavMeshInfoArray() : table(DAT_00dd8fe4), data(0), size(0), capacity(0) {}
    ~NavMeshInfoArray() {
        void* storage = data;
        table = DAT_00dd8fe4;
        if (storage) {
            DAT_00dd8fec(this, storage);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    unsigned int GetSize() const { return size; }
    const NavMeshInfo*& operator[](unsigned int i) { return data[i]; }
};

struct FUN_005fc5a0 {
    void* m_vtable;
    NiPoint3 Location;
    const NavMeshInfo* pNavMesh;
    const NavMeshInfoArray* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;

    FUN_005fc5a0(const NiPoint3& ar_Location, const NavMeshInfo* ap_NavMesh, unsigned short a_usTriangle);
    ~FUN_005fc5a0() { m_vtable = &DAT_00dc4dc0; }
    FUN_005fc5a0& FUN_005fc480(const FUN_005fc5a0& ar_Other);
    bool FUN_005fd720(NavMeshInfoArray* ap_Array) const;
    NiPoint3 GetLocation() const { return Location; }
};

typedef FUN_005fc5a0 PathingLocation;

struct PathingRequest {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70;
    float fTargetRadius;
    float GetTargetRadius() const { return fTargetRadius; }
};

struct PathBuilder {
    PathingRequest* pRequest;
    bool FUN_005ec900(PathingLocation a_Location, PathingLocation& ar_Result, bool ab_AllowWater);
};

// pdb: PathBuilder::FindClosestOpenEdge | PathBuilder.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: aStartLocation, aRetLocation, abStart
bool PathBuilder::FUN_005ec900(PathingLocation a_Location, PathingLocation& ar_Result, bool ab_AllowWater)
{
    float fClosestDistSqr = FLT_MAX;
    int iClosestNavMesh = -1;
    unsigned short usClosestTriangle = 0xFFFF;
    NiPoint3 kClosestPoint = DAT_0108ec68;

    NavMeshInfoArray kNavMeshInfos;
    a_Location.FUN_005fd720(&kNavMeshInfos);

    unsigned int uiCount = kNavMeshInfos.GetSize();
    for (unsigned int i = 0; i < uiCount; ++i) {
        NiPointer<NavMesh> spNavMesh;
        if (kNavMeshInfos[i]->GetNavMesh(spNavMesh)) {
            unsigned short usTriangle;
            int iEdgeIndex;
            if (spNavMesh->FUN_005bd410(a_Location.GetLocation(), pRequest->GetTargetRadius(), &usTriangle, &iEdgeIndex, ab_AllowWater)) {
                NavMeshEdgeVertices kVertices = spNavMesh->FUN_005b8900(usTriangle, iEdgeIndex);
                NiPoint3 kCenter = spNavMesh->FUN_004d45e0(usTriangle);
                NiPoint3 kIntersection = kCenter;
                if (FUN_005dd580(a_Location.GetLocation(), spNavMesh->FUN_004d45e0(usTriangle), *kVertices.pVertex0, *kVertices.pVertex1, &kIntersection)) {
                    kIntersection += (kCenter - kIntersection) * 0.1f;
                }
                float fDistSqr = (kIntersection - a_Location.GetLocation()).SqrLength();
                if (fDistSqr < fClosestDistSqr) {
                    fClosestDistSqr = fDistSqr;
                    iClosestNavMesh = i;
                    usClosestTriangle = usTriangle;
                    kClosestPoint = kIntersection;
                }
            }
        }
    }

    if (iClosestNavMesh == -1) {
        return false;
    }

    ar_Result.FUN_005fc480(PathingLocation(kClosestPoint, kNavMeshInfos[iClosestNavMesh], usClosestTriangle));
    return true;
}

}

// @f3 0x005ec080 (community match, verified in this file)
namespace f3m_005ec080 {
namespace f3m_005ec080 {
struct FUN_006101c0 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    FUN_006101c0(int a, int b, int c);
};
struct Array5ec080 {
    int unk00;
    FUN_006101c0* data;
    int FUN_005eb230();
};
struct Owner5ec080 {
    int unk00;
    int unk04;
    Array5ec080 array;
    int FUN_005ec080(int a, int b, int c);
};
// pdb: PathingSolution::AddVirtualPathingNode | PathBuilder.obj | fnv360_0822_retail, objrun, medium
// pdb params: apNavMeshInfo, aLocation, apDoor
int Owner5ec080::FUN_005ec080(int a, int b, int c)
{
    int index = array.FUN_005eb230();
    void* slot = &array.data[index];
    new (slot) FUN_006101c0(a, b, c);
    return index;
}
}
}   // namespace f3m_005ec080

// @f3 0x005e9b70 (community match, verified in this file)
namespace f3m_005e9b70 {
namespace ThreadQueue2061 {
struct Input {unsigned int unk00,unk04,unk08;void* data;};
struct Buffer;
struct List {void FUN_005e5070(void**);};
struct Owner {unsigned int count;unsigned long tlsIndex;List* FUN_0042ba10(Buffer*);};
extern List* (__stdcall* DAT_00d9b080)(unsigned long);
struct Buffer {
    unsigned int unk00,unk04,unk08,unk0C,unk10;
    Owner* owner;
    List* Get(){Owner* factory=owner;List* list=DAT_00d9b080(factory->tlsIndex);if(!list)list=factory->FUN_0042ba10(this);return list;}
};
struct State {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    Buffer buffer;
};
extern State* __cdecl FUN_005e9ad0();
// pdb: bhkObstacleDeactivationListener::entityDeactivatedCallback | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall bhkObstacleDeactivationListener_entityDeactivatedCallback(void* input) {
    if(input) {
        void* data=((Input*)input)->data;
        if(data) {
            input=data;
            State* state=FUN_005e9ad0();
            List* list=state->buffer.Get();
            list->FUN_005e5070(&input);
        }
    }
}
}
}   // namespace f3m_005e9b70

// @f3 0x005e4710 (community match, verified in this file)
namespace f3m_005e4710 {
namespace f3w_5e47 {
struct Entry5e47 { int unk00; unsigned short unk04; unsigned short slots[3]; unsigned int mask; };
struct Key5e47 { int unk00; void* root; unsigned short word; };
struct Root5e47 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    Entry5e47* entries;
    unsigned short FUN_005ba390(Key5e47* key);
};
struct Ref5e47 { Root5e47* root; unsigned short word04; unsigned int index08; };

static __forceinline void Set5e47(Root5e47* root, Ref5e47* slot, unsigned short value) {
    unsigned int index = slot->index08;
    Entry5e47* e = &root->entries[slot->word04];
    e->mask |= 1 << index;
    e->slots[index] = value;
}
// pdb: NavMeshObstacleManager::CreatePortal | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: bhkRigidBody::SetHavokAssertState)
// pdb params: aspNavMesh1, aEdge1, aspNavMesh2, aEdge2
bool __stdcall FUN_005e4710(Ref5e47* a, Ref5e47* b, Ref5e47* c, Ref5e47* d) {
    Key5e47 key1;
    key1.unk00 = -1;
    key1.root = d->root;
    key1.word = d->word04;
    Set5e47(a->root, b, a->root->FUN_005ba390(&key1));
    Key5e47 key2;
    key2.unk00 = -1;
    key2.root = b->root;
    key2.word = b->word04;
    Set5e47(c->root, d, c->root->FUN_005ba390(&key2));
    return true;
}
}
}   // namespace f3m_005e4710

// @f3 0x005fed40 (community match, verified in this file)
extern int DAT_00db72c8;
namespace f3m_005fed40 {
namespace Match5fed40 {
struct IndexArray;
extern void (__thiscall* DAT_00db72d0)(IndexArray*,unsigned*);
struct IndexArray {
 void* table; unsigned* data; unsigned count; unsigned capacity;
 unsigned& At(unsigned index){unsigned* element = &data[index]; return *element;}
 IndexArray():table(&DAT_00db72c8),data(0),count(0),capacity(0) {}
 ~IndexArray(){table=&DAT_00db72c8;if(data){DAT_00db72d0(this,data);data=0;capacity=0;count=0;}}
};
struct Retained;
struct Shared;
struct RefPart;
struct RefMethods {void* unk00;void(__thiscall* destroy)(RefPart*);};
struct RefPart {RefMethods* table;long refs;void Release(){if(InterlockedDecrement(&refs)==0)table->destroy(this);}};
struct Shared {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18; RefPart reference;
 void FUN_005ba540(unsigned,IndexArray&);
};
struct Retained {Shared* value;Retained():value(0){}~Retained(){if(value)value->reference.Release();}};
struct Request {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;unsigned short id; const unsigned short& GetId()const{return id;} bool FUN_005fc8b0(Retained&);};
struct Entry {bool FUN_005feb30(Request*,void*);};
struct Owner {int unk00;Entry** entries;unsigned count;bool FUN_005fed40(Request*,void*);};
// pdb: PathingLOSGrid::SetLocationSeen | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arLocation, abSeen
bool Owner::FUN_005fed40(Request* request,void* context){
 Retained retained;
 if(request->FUN_005fc8b0(retained)) {
  IndexArray indices;
  unsigned id = request->GetId();
  retained.value->FUN_005ba540(id,indices);
  bool result=false;
  for(unsigned i=0;i<indices.count;++i){const unsigned& index=indices.At(i);if(index<count){Entry** slot = &entries[index]; if((*slot)->FUN_005feb30(request,context))result=true;}}
  return result;
 }
 return false;
}
}
}   // namespace f3m_005fed40

// @f3 0x005fe1c0 (community match, verified in this file)
namespace f3m_005fe1c0 {
struct Stream;
struct Val;
struct Item { void FUN_005fe150(Stream*); };

struct Stream {
    unsigned BGSSaveGameBuffer_StartVariableSizedValue();
    void BGSSaveGameBuffer_SaveFormID(unsigned value, int pad);
    void BGSSaveGameBuffer_SaveVariableSizedValue(unsigned count);
    void FUN_006e16e0(unsigned count, unsigned start);
    void FUN_006e1830(void* dst, unsigned size, int flag);
};

struct Map {
    void* vtbl;
    unsigned int m_size;
    Val** m_buckets;
    void FUN_0089a5d0(Val** pos, unsigned int* key, Val** val);
    Val* GetFirstPos() {
        for (unsigned int i = 0; i < m_size; i++) {
            if (m_buckets[i]) return m_buckets[i];
        }
        return 0;
    }
};

struct Val {
    int unk00;
    Item** data;
    unsigned count;
    int unk0c;
    unsigned* id;
};

struct Sub { virtual void FUN_005fe1c0_ser(Stream*); };

struct Self {
    int unk00;
    int unk04;
    Map m_map;
    int unk14;
    int unk18;
    Sub member;
    char pad[0x44 - 0x20];
    int unk44;
    int unk48;
    void FUN_005fe1c0(Stream* stream);
};

// pdb: PathingLOSGridMap::SaveGame | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apSaveGameBuffer
void Self::FUN_005fe1c0(Stream* stream)
{
    unsigned count = 0;
    unsigned start = stream->BGSSaveGameBuffer_StartVariableSizedValue();
    Val* pos = m_map.GetFirstPos();
    if (pos) {
        do {
            unsigned int key;
            Val* val = 0;
            m_map.FUN_0089a5d0(&pos, &key, &val);
            Val* v = *(Val* volatile*)&val;
            if (v) {
                stream->BGSSaveGameBuffer_SaveFormID(key, 0);
                stream->BGSSaveGameBuffer_SaveFormID(v->id ? *v->id : 0, 0);
                unsigned n = v->count;
                stream->BGSSaveGameBuffer_SaveVariableSizedValue(n);
                for (unsigned i = 0; i < n; ++i) {
                    v->data[i]->FUN_005fe150(stream);
                }
                ++count;
            }
        } while (pos);
    }
    stream->FUN_006e16e0(count, start);
    stream->FUN_006e1830(&unk18, 4, 0);
    stream->FUN_006e1830(&unk44, 4, 0);
    stream->FUN_006e1830(&unk48, 4, 0);
    member.FUN_005fe1c0_ser(stream);
}
}   // namespace f3m_005fe1c0

// @f3 0x005e04b0 (community match, verified in this file)
#include <windows.h>
namespace Bounds2087 {
extern volatile long DAT_0108ed80;
struct RefBase {
    virtual ~RefBase(){::InterlockedDecrement(&DAT_0108ed80);}
    virtual void DeleteThis();
    volatile long references;
};
struct Ref {
    RefBase* object;
    ~Ref(){RefBase* old=object;if(old && ::InterlockedDecrement(&old->references)==0)old->DeleteThis();}
};
extern void (__thiscall* const DAT_00dffe58)(void*,void*);
extern void (__thiscall* const DAT_00e01aa4)(void*,void*);
extern void (__thiscall* const DAT_00e01ab8)(void*,void*);
struct TriangleInfo;struct PortalSwap;
template<class T>struct Release;
template<>struct Release<unsigned short>{static void Run(void* owner,void* p){DAT_00dffe58(owner,p);}};
template<>struct Release<TriangleInfo>{static void Run(void* owner,void* p){DAT_00e01aa4(owner,p);}};
template<>struct Release<PortalSwap>{static void Run(void* owner,void* p){DAT_00e01ab8(owner,p);}};
template<class T>struct Array {
    virtual ~Array(){if(data){Release<T>::Run(this,data);data=0;capacity=0;size=0;}}
    T* data;unsigned int size,capacity;
};
struct ObstacleMap {virtual void v0();unsigned int capacity;void* buckets;unsigned int count;~ObstacleMap();};
struct __declspec(novtable) Bounds:RefBase {
    unsigned int state;Ref obstacle;
    unsigned int firstVertex,vertexCount,firstTriangle,triangleCount;
    Array<unsigned short> overlaps;
    Array<TriangleInfo> triangles;
    ObstacleMap removed;
    Array<PortalSwap> swaps;
    Array<unsigned short> added;
    virtual ~Bounds();
};
// pdb: ObstacleUndoData::~ObstacleUndoData | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_seq, medium
Bounds::~Bounds(){}
}

// @f3 0x005feff0 (community match, verified in this file)
extern void* DAT_00e022cc[];
extern void* DAT_00e02264[];
extern void* DAT_00e02284[];
namespace f3m_005feff0 {
extern "C" void* __cdecl FUN_00c00610(void* dst, int value, unsigned int size);
namespace f3m_005feff0 {
void* __cdecl FUN_0089e810(unsigned int size);
struct RefBase {
    void** table;
    long refs;
    RefBase() { table = ::DAT_00db7764; refs = 0; InterlockedIncrement(&::DAT_0108ed80); }
    ~RefBase();
};
struct MapBase {
    void** table;
    unsigned int hashSize;
    void** buckets;
    unsigned int count;
    MapBase()
    {
        table = DAT_00e02264;
        hashSize = 0x25;
        count = 0;
        buckets = (void**)FUN_0089e810(0x94);
        FUN_00c00610(buckets, 0, hashSize * 4);
    }
    ~MapBase();
};
struct Map : MapBase {
    Map() { table = DAT_00e02284; }
};
}
namespace f3m_005feff0 {
struct Grid1c {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    void FUN_005fc3f0();
    Grid1c() { FUN_005fc3f0(); }
    ~Grid1c();
};
struct Grid4c {
    int unk00;
    void FUN_0059acd0();
    Grid4c() { FUN_0059acd0(); }
    ~Grid4c();
};
struct Mid : RefBase {
    Mid() { table = DAT_00e022cc; }
};
}
class FUN_005feff0 : public f3m_005feff0::Mid {
public:
    f3m_005feff0::Map m_map;
    float m_18;
    f3m_005feff0::Grid1c m_1c;
    float m_44;
    float m_48;
    f3m_005feff0::Grid4c m_4c;
    FUN_005feff0();
};
// pdb: PathingLOSGridMap::PathingLOSGridMap | PathingLOSGridMap.obj | fnv360_0822_retail, objrun, medium
FUN_005feff0::FUN_005feff0() : m_18(0.0f), m_44(0.0f), m_48(0.0f)
{
}
}   // namespace f3m_005feff0

// @f3 0x005e0a60 (community match, verified in this file)
namespace f3m_005e2a10 {
struct ScrapHeap5e0a {
    void* ScrapHeap_Allocate(unsigned int a_uiSize, unsigned int a_uiAlign);
};

struct EdgeArray5e0a : public ScrapArray<NavMeshObstacleEdge*> {
    void FUN_00799ae0(unsigned int a_uiNewSize, unsigned int a_uiMoveCount);

    void Add(NavMeshObstacleEdge* a_pEdge) {
        if (iSize == iReservedSize) {
            if (!iReservedSize) {
                pBuffer = _Allocate(4);
                iReservedSize = 4;
            } else {
                unsigned int uiNewSize = iReservedSize > 0x400 ? iReservedSize + 0x400 : iReservedSize * 2;
                FUN_00799ae0(uiNewSize, iSize);
                iReservedSize = uiNewSize;
            }
        }
        ++iSize;
        pBuffer[iSize - 1] = a_pEdge;
    }
};

struct Ptr5e0a {
    void* m_pObject;
    Ptr5e0a() : m_pObject(0) {}
};

struct EdgeInit5e0a {
    static void* operator new(unsigned int, void* a_pWhere) { return a_pWhere; }
    EdgeInit5e0a(NavMeshObstacleVertex* a_pStart, NavMeshObstacleVertex* a_pEnd) {
        pStart = a_pStart;
        pEnd = a_pEnd;
        us08 = 0xFFFF;
        us0a = 0xFFFF;
        us0c = 0xFFFF;
        us0e = 0xFFFF;
        i10 = 0;
        us16 = 0;
        b18 = false;
        b19 = false;
        us14 = 0xFFFF;
        i20 = 0;
        us24 = 0xFFFF;
        i28 = -1;
        us2c = 0xFFFF;
        b2e = false;
    }
    NavMeshObstacleVertex* pStart;
    NavMeshObstacleVertex* pEnd;
    unsigned short us08;
    unsigned short us0a;
    unsigned short us0c;
    unsigned short us0e;
    int i10;
    unsigned short us14;
    unsigned short us16;
    bool b18;
    bool b19;
    Ptr5e0a sp1c;
    int i20;
    unsigned short us24;
    int i28;
    unsigned short us2c;
    bool b2e;
};

struct CutterHelper5e0a {
    bool FUN_005dfc00(NavMeshObstacleVertex* a_pFirst, NavMeshObstacleVertex* a_pSecond);
};

// pdb: NavMeshObstacleCutter::CreateNewEdges | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
void NavMeshObstacleCutter::FUN_005e0a60() {
    for (unsigned int i = 0; i < Vertices.GetSize(); i++) {
        NavMeshObstacleVertex* pFirst = Vertices[i];
        if (!pFirst->bOnObstacle)
            continue;
        for (unsigned int j = 0; j < Vertices.GetSize(); j++) {
            NavMeshObstacleVertex* pSecond = Vertices[j];
            if (pSecond->bInObstacleArea)
                continue;
            if (!pSecond->bOnBounds && !pSecond->bOnOpenEdge)
                continue;
            if (!((CutterHelper5e0a*)this)->FUN_005dfc00(pFirst, pSecond))
                continue;
            EdgeInit5e0a* pEdge = (EdgeInit5e0a*)((ScrapHeap5e0a*)&unk0c)->ScrapHeap_Allocate(0x30, DAT_00e27ed4);
            if (pEdge)
                new (pEdge) EdgeInit5e0a(pFirst, pSecond);
            ((EdgeArray5e0a*)&Edges)->Add((NavMeshObstacleEdge*)pEdge);
        }
    }
}
}

// @f3 0x005e62f0 (community match, verified in this file)
extern void* DAT_00db7764[];
extern void* DAT_00e01d24[];
extern void* DAT_00e00d68[];
extern long DAT_0108ed80;
namespace f3m_005e62f0 {
namespace Obstacle2151 {

struct RefBase {
    void** table;
    long references;
    RefBase() : table(DAT_00db7764), references(0) {
        ::InterlockedIncrement(&DAT_0108ed80);
    }
    ~RefBase();
};

struct Payload;
struct PayloadPointer {
    Payload* pointer;
    PayloadPointer(RefBase& owner) {
        owner.table = DAT_00e01d24;
        pointer = 0;
    }
    ~PayloadPointer();
};

struct NavMeshInfoArray {
    void** table;
    NavMeshInfo** buffer;
    unsigned size;
    unsigned storage;
    __forceinline NavMeshInfoArray(unsigned reserve) {
        table = DAT_00e00d68;
        buffer = reserve ? new NavMeshInfo*[reserve] : 0;
        size = 0;
        storage = reserve;
    }
};

struct FUN_005e62f0 : RefBase {
    unsigned unk08;
    PayloadPointer payload;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    bool enabled;
    unsigned char unk75, unk76, unk77;
    NavMeshInfoArray array;
    unsigned unk88;
    FUN_005e62f0();
};

// pdb: ObstacleData::ObstacleData | NavMeshObstacleManager.obj | fnv360_0822_debug, uvref, medium
FUN_005e62f0::FUN_005e62f0()
    : payload(*this), enabled(true), array(0), unk88(0)
{}
}
}   // namespace f3m_005e62f0

// @f3 0x005e4b90 (community match, verified in this file)
namespace f3m_005e4b90 {
struct HeldNode;
struct HeldOperations {void* unk00;void (__thiscall* destroy)(HeldNode*);};
struct HeldNode {HeldOperations* operations;long references;
 void IncRefCount(){InterlockedIncrement(&references);}
 void DecRefCount(){if(!InterlockedDecrement(&references))operations->destroy(this);}
};
struct NodeUpdate {float time;bool a,b,c,d,e;NodeUpdate(){time=0.0f;a=false;b=false;c=false;d=false;e=false;}};
struct AttachedNode {
 virtual void V00();
 virtual void V01();
 virtual void V02();
 virtual void V03();
 virtual void V04();
 virtual void V05();
 virtual void V06();
 virtual void V07();
 virtual void V08();
 virtual void V09();
 virtual void V0A();
 virtual void V0B();
 virtual void V0C();
 virtual void V0D();
 virtual void V0E();
 virtual void V0F();
 virtual void V10();
 virtual void V11();
 virtual void V12();
 virtual void V13();
 virtual void V14();
 virtual void V15();
 virtual void V16();
 virtual void V17();
 virtual void V18();
 virtual void V19();
 virtual void V1A();
 virtual void V1B();
 virtual void V1C();
 virtual void V1D();
 virtual void V1E();
 virtual void V1F();
 virtual void V20();
 virtual void V21();
 virtual void V22();
 virtual void V23();
 virtual void V24();
 virtual void V25();
 virtual void V26();
 virtual void V27();
 virtual void V28();
 virtual void V29();
 virtual void V2A();
 virtual void V2B();
 virtual void V2C();
 virtual void V2D();
 virtual void V2E();
 virtual void V2F();
 virtual void V30();
 virtual void V31();
 virtual void V32();
 virtual void V33();
 virtual void V34();
 virtual void V35();
 virtual void V36();
 virtual void Attach(HeldNode*,int);
 virtual void V38();
 virtual void V39();
 virtual void Property(void*);
 void FUN_008268a0();
 void FUN_008264c0(const NodeUpdate&);
};
struct Ptr {void* p;operator void*() const {return p;}};
struct AttachmentData {
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
 unsigned unk44;
 unsigned unk48;
 unsigned unk4C;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5C;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6C;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7C;
 unsigned unk80;
 unsigned unk84;
 Ptr extra;
};
struct AttachmentOwner {
 unsigned unk000;
 unsigned unk004;
 unsigned unk008;
 unsigned unk00C;
 unsigned unk010;
 unsigned unk014;
 unsigned unk018;
 unsigned unk01C;
 unsigned unk020;
 unsigned unk024;
 unsigned unk028;
 unsigned unk02C;
 unsigned unk030;
 unsigned unk034;
 unsigned unk038;
 unsigned unk03C;
 unsigned unk040;
 unsigned unk044;
 unsigned unk048;
 unsigned unk04C;
 unsigned unk050;
 unsigned unk054;
 unsigned unk058;
 unsigned unk05C;
 unsigned unk060;
 unsigned unk064;
 unsigned unk068;
 unsigned unk06C;
 unsigned unk070;
 unsigned unk074;
 unsigned unk078;
 unsigned unk07C;
 unsigned unk080;
 unsigned unk084;
 unsigned unk088;
 unsigned unk08C;
 unsigned unk090;
 unsigned unk094;
 unsigned unk098;
 unsigned unk09C;
 unsigned unk0A0;
 unsigned unk0A4;
 unsigned unk0A8;
 unsigned unk0AC;
 unsigned unk0B0;
 unsigned unk0B4;
 unsigned unk0B8;
 unsigned unk0BC;
 unsigned unk0C0;
 unsigned unk0C4;
 unsigned unk0C8;
 unsigned unk0CC;
 unsigned unk0D0;
 unsigned unk0D4;
 unsigned unk0D8;
 unsigned unk0DC;
 unsigned unk0E0;
 unsigned unk0E4;
 unsigned unk0E8;
 unsigned unk0EC;
 unsigned unk0F0;
 unsigned unk0F4;
 unsigned unk0F8;
 unsigned unk0FC;
 unsigned unk100;
 unsigned unk104;
 unsigned unk108;
 unsigned unk10C;
 unsigned unk110;
 unsigned unk114;
 unsigned unk118;
 unsigned unk11C;
 unsigned unk120;
 unsigned unk124;
 unsigned unk128;
 unsigned unk12C;
 unsigned unk130;
 unsigned unk134;
 unsigned unk138;
 AttachedNode* node;
 __declspec(noalias) void FUN_005e4890(AttachmentData**,NiPointer<HeldNode>*);
 void FUN_005e4b90(AttachmentData**);
};
void AttachmentOwner::FUN_005e4b90(AttachmentData** input) {
 AttachmentData* d=*input;
 void* e=*(void* const volatile*)&d->extra.p;
 if(e){AttachedNode* m=node;m->Property(d->extra);};
 NiPointer<HeldNode> held;
 FUN_005e4890(input,&held);
 node->Attach(held,1);
 node->FUN_008268a0();
 AttachedNode* n=node;
 n->FUN_008264c0(NodeUpdate());
}
}   // namespace f3m_005e4b90

// @f3 0x005eba80 (community match, verified in this file)
namespace f3m_005eba80 {
struct Allocator;
struct Heap { Allocator* FUN_0086bcb0(); };
extern Heap DAT_01090a78;
struct ArrayBase {
    void* data;
    unsigned int size;
    unsigned int capacity;
    ArrayBase() : data(0), size(0), capacity(0) {}
    virtual ~ArrayBase();
    virtual void* Allocate(unsigned int count);
};
struct ScrapArray : ArrayBase {
    Allocator* allocator;
    ScrapArray(unsigned int reserve, unsigned int count, Allocator* alloc);
    virtual ~ScrapArray();
};
// pdb: BSScrapArray<FastNavMeshTriHandle,1024>::BSScrapArray<FastNavMeshTriHandle,1024> | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiReserveSize, aiInitialSize, apHeap
ScrapArray::ScrapArray(unsigned int reserve, unsigned int count, Allocator* alloc) {
    if (!alloc) alloc = DAT_01090a78.FUN_0086bcb0();
    allocator = alloc;
    data = 0;
    size = 0;
    capacity = 0;
    unsigned int n = reserve;
    if (count > reserve) n = count;
    if (n > 0) {
        ArrayBase* self = this;
        data = self->Allocate(n);
        capacity = n;
    }
    if (count > 0) size = count;
}
}

// @f3 0x005eebe0 (community match, verified in this file)
extern int DAT_00e01240;
extern int DAT_00dc4dc0;
namespace f3m_005eebe0 {

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct Loc {
 int* vtable; float x,y,z; void *info,*infos,*cell,*world; unsigned int flags; unsigned short tri; unsigned char bits,pad;
 void FUN_005fc3f0(); void FUN_005fc430(const Loc&); Loc& FUN_005fc480(const Loc&);
 Loc(){FUN_005fc3f0();} Loc(const Loc& other); ~Loc(){vtable=&DAT_00dc4dc0;}
};
struct LocArray {
 int vtable; Loc* data;
 unsigned int FUN_005ecde0(const Loc&); unsigned int FUN_005ebec0(); void FUN_005eaa60(Loc*,int);
 void AppendGoal(const Loc& p){unsigned int n=FUN_005ebec0();FUN_005eaa60(&data[n],1);data[n].FUN_005fc480(p);}
};
struct Doors {void FUN_005ece20(void*);};
struct Query {
 int type; void* request;
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
 int unk60;
 int unk64;
 void FUN_005ec420(); void FUN_005ec490();
 Query(){FUN_005ec420();} ~Query(){FUN_005ec490();}
 Loc& Goal(){return *reinterpret_cast<Loc*>(&unk30);} void* DoorData(){return &unk58;}
};
struct PathMap {
 int* vtable; void* data; unsigned int size,capacity;
 PathMap(){vtable=&DAT_00e01240; data=0;size=0;capacity=0;}
 void FUN_005d0d90(); ~PathMap(){FUN_005d0d90();}
};
struct PathData {void FUN_005ecef0(LocArray*);};
struct Result {int unknown00,unknown04;PathMap map;PathData& Path(){return *reinterpret_cast<PathData*>(&map);}};
struct Search {
 int unk00;
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
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 void FUN_00603770();void FUN_00603800();int FUN_00604430(Query*,Result*);
 Search(){FUN_00603770();}~Search(){FUN_00603800();}
};
struct Tasklet {virtual void v0();virtual void v4();virtual void v8();virtual bool IsThread(unsigned long);};
Tasklet& __cdecl FUN_00bce1f0();
struct Manager {int FUN_00608b20(void*,Doors*,Loc*,LocArray*,bool);};
Manager* __cdecl FUN_0044f4b0();
int __cdecl FUN_005f90b0(Loc*,int,Doors*);
struct Builder {
 void* request;
 bool FUN_005ec900(Loc,Loc*,bool);
 int FUN_005eebe0(Loc*,LocArray*,int,Doors*);
};
// pdb: PathBuilder::BuildPathToValidNavMeshTriangle | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aStartLocation, aRetPath, abStart, aRetEdges
int Builder::FUN_005eebe0(Loc* start,LocArray* output,int allowPartial,Doors* doors) {
 if(*reinterpret_cast<const bool*>(&DAT_01074880)){
  switch(FUN_005f90b0(start,10,doors)) {
   case 0:return 2;
   case 1:output->FUN_005ecde0(*start);return 1;
   case 2:
    Tasklet& manager=FUN_00bce1f0();
    unsigned long thread=GetCurrentThreadId();
    if(manager.IsThread(thread)) {
      return FUN_0044f4b0()->FUN_00608b20(request,doors,start,output,*reinterpret_cast<bool*>(&allowPartial));
    } else {
      Query query;
      query.Goal().FUN_005fc480(*start);
      query.type=!*reinterpret_cast<bool*>(&allowPartial);
      query.request=request;
      doors->FUN_005ece20(query.DoorData());
      Result result;
      Search search;
      int status=search.FUN_00604430(&query,&result);
      while(status==0) status=search.FUN_00604430(&query,&result);
      if(status==1){result.Path().FUN_005ecef0(output);return 1;}else{return 2;}
    }
  }
  return 2;
 }else{
  Loc goal;
  if(FUN_005ec900(*start,&goal,*reinterpret_cast<bool*>(&allowPartial))) {
   output->FUN_005ecde0(*start);output->AppendGoal(goal);return 1;
  }else{return 2;}
 }
}
}   // namespace f3m_005eebe0

// @f3 0x005e9bc0 (community match, verified in this file)
namespace f3m_005e9bc0 {
namespace ThreadQueue2183 {
struct Input {unsigned int unk00,unk04,unk08;void* data;};
struct Buffer;
struct List {void FUN_005e5070(void**);};
struct Owner {unsigned int count;unsigned long tlsIndex;List* FUN_0042ba10(Buffer*);};
extern List* (__stdcall* DAT_00d9b080)(unsigned long);
struct Buffer {
    unsigned int unk00,unk04,unk08,unk0C,unk10;
    Owner* owner;
    List* Get(){Owner* factory=owner;List* list=DAT_00d9b080(factory->tlsIndex);if(!list)list=factory->FUN_0042ba10(this);return list;}
};
struct State {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    Buffer buffer;
};
extern State* __cdecl FUN_005e9ad0();
// pdb: bhkObstacleDeactivationListener::entityActivatedCallback | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall bhkObstacleDeactivationListener_entityActivatedCallback(void* input) {
    if(input) {
        void* data=((Input*)input)->data;
        if(data) {
            input=data;
            State* state=FUN_005e9ad0();
            List* list=state->buffer.Get();
            list->FUN_005e5070(&input);
        }
    }
}
}
}   // namespace f3m_005e9bc0

// @f3 0x005ec100 (community match, verified in this file)
namespace f3m_005ec100 {
struct Element5ec100 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; void FUN_00600960(); };
struct Array5ec100 { void** table; Element5ec100* data; unsigned count; unsigned capacity;
 __forceinline void Clear() { if(data) { Element5ec100* p=data; unsigned remaining=count; while(remaining>0) { p->FUN_00600960(); ++p; --remaining; } ((void (__thiscall *)(Array5ec100*,Element5ec100*))table[2])(this,data); data=0; capacity=0; count=0; } }
};
struct Owner5ec100 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; Array5ec100 array; void FUN_005ec100(); };
// pdb: PathingSolution::ClearCurrentDetailedPath | PathBuilder.obj | fnv360_0721_beta, call_seq, medium
void Owner5ec100::FUN_005ec100() {
    Array5ec100& storage=array;
    Element5ec100* element=storage.data;
    if(element) {
        unsigned remaining=storage.count;
        if(remaining>0) {
            do { element->FUN_00600960(); ++element; } while(--remaining);
        }
        ((void (__thiscall *)(Array5ec100*,Element5ec100*))storage.table[2])(&storage,storage.data);
        storage.data=0;
        storage.capacity=0;
        storage.count=0;
    }
    unk18=-1;
    unk1C=-1;
}
}   // namespace f3m_005ec100

// @f3 0x005e6fa0 (community match, verified in this file)
#include <float.h>
namespace n5e6fa0 {
struct NiPoint3 {
    float x, y, z;
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
struct Cell { char pad[0x26]; unsigned char m26; };
struct Grid { Cell* TESWorldSpace_GetCellFromCellCoord(); };
struct World {
    char pad[0x24];
    unsigned char m24;
    Grid* FUN_004d3780(int x, int y);
};
struct WorldMgr { World* FUN_00435750(); };
extern WorldMgr* DAT_0107a0d8;
struct Ref {
    char pad0[0x10];
    float m10;
    float m14;
    char pad18[0x40];
    NiPoint3 m58;
    NiPoint3 m64;
};
struct Ctx { Ref* m0; };
struct Array {
    int m0;
    void** m4;
    unsigned int m8;
    unsigned int FUN_005e5350();
    void Clear() { if (m4) m8 = 0; }
    void Add(void* p) { m4[FUN_005e5350()] = p; }
};
bool __cdecl FUN_005f1280(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
// pdb: NavMeshObstacleManager::GetCellListForObstacle | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apData, apReturnCellArray
bool __cdecl FUN_005e6fa0(Ctx* ctx, Array* out)
{
    out->Clear();
    World* w = DAT_0107a0d8->FUN_00435750();
    if (!w)
        return false;
    if (w->m24 & 1) {
        out->Add(w);
        return true;
    }
    Ref* r = ctx->m0;
    int cx = (int)r->m10 >> 12;
    int cy = (int)r->m14 >> 12;
    for (int x = cx - 1; x <= cx + 1; x++) {
        for (int y = cy - 1; y <= cy + 1; y++) {
            Cell* c = w->FUN_004d3780(x, y)->TESWorldSpace_GetCellFromCellCoord();
            if (c && c->m26 == 6) {
                NiPoint3 a((float)(x << 12), (float)(y << 12), -FLT_MAX);
                if (FUN_005f1280(a, NiPoint3(a.x + 4096.0, a.y + 4096.0, FLT_MAX), ctx->m0->m58, ctx->m0->m64))
                    out->Add(c);
            }
        }
    }
    return true;
}
}

// @f3 0x005e8fd0 (community match, verified in this file)
#include <windows.h>
namespace task2167 {
extern __declspec(thread) int DAT_0117c298;
struct MemoryContext {
    int saved;
    MemoryContext() : saved(DAT_0117c298) { DAT_0117c298 = 0x2e; }
    ~MemoryContext() { DAT_0117c298 = saved; }
};
extern bool DAT_01074864;
extern float DAT_01090bac;
struct PathManager { bool FUN_00606e30(); void FUN_00607520(); void FUN_00607510(); };
PathManager* __cdecl FUN_0044f4b0();
struct World {
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
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
bool ready;
void FUN_005cbe40();
};
extern World* DAT_01074570;
struct StateMachine {
    CRITICAL_SECTION lock;
bool rebuild;
unsigned char unk019;
unsigned char unk01a;
unsigned char unk01b;
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
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned pending;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
int state;
float time;
    void FUN_005e8fd0();
    unsigned FUN_005e3120(); unsigned FUN_005e3160();
    void FUN_005e5610(); bool FUN_005e47c0(); void FUN_005e5de0(); void FUN_005e74f0();
    void FUN_005e6a60(); void FUN_005e8a10(); void FUN_005e5e60(); void FUN_005e8390();
    void FUN_005e4850(); void FUN_005e4810(); void FUN_005e80b0(); void FUN_005e7ed0();
    void FUN_005e7d90(); void FUN_005e81f0();
};
// pdb: NavMeshObstacleManager::Update | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
void StateMachine::FUN_005e8fd0()
{
    MemoryContext context;
    if (!DAT_01074864) return;
    EnterCriticalSection(&lock);
    bool changed = false;
    time -= DAT_01090bac;
    switch (state) {
    case 0: {
        FUN_005e6a60(); FUN_005e8a10(); FUN_005e5e60(); FUN_005e8390(); FUN_005e4850(); FUN_005e4810();
        if (rebuild) { FUN_005e80b0(); rebuild = false; }
        else { FUN_005e7ed0(); FUN_005e7d90(); }
        FUN_005e81f0();
        unsigned completed = FUN_005e3120();
        unsigned background = FUN_005e3160();
        bool advance = false;
        if (pending > 0) {
            if (background > 0) {
                if (background == completed && time <= 0.0) advance = true;
            } else if (time <= 0.0) advance = true;
        } else if (background > 0 && background == completed && time <= 0.0) advance = true;
        if (advance) { FUN_0044f4b0()->FUN_00607510(); state = 1; }
        break;
    }
    case 1:
        if (FUN_0044f4b0()->FUN_00606e30()) {
            FUN_005e3120();
            if (FUN_005e3160() > 0) { FUN_005e5610(); changed = FUN_005e47c0(); FUN_005e5de0(); }
            FUN_005e74f0();
            FUN_0044f4b0()->FUN_00607520();
            time = 0.5f;
            state = 0;
            if (changed && DAT_01074570->ready) DAT_01074570->FUN_005cbe40();
        }
        break;
    }
    LeaveCriticalSection(&lock);
}
}

// @f3 0x005e7120 (community match, verified in this file)
#include <windows.h>
namespace n5e7120 {
struct Heap { void* FUN_0086bcb0(); };
extern Heap DAT_01090a78;
extern double dbl_00dcc598;
struct Allocator { void Free(void* p); };
struct Base {
    Base() : m_pData(0), m_nSize(0), m_nCapacity(0) {}
    virtual ~Base() { Clear(); }
    virtual void* Allocate(int count);
    virtual void Free(void* p);
    void Init(int n) {
        m_pData = 0;
        m_nSize = 0;
        m_nCapacity = 0;
        m_pData = Allocate(n);
        m_nCapacity = n;
    }
    void Clear() {
        if (m_pData) {
            Free(m_pData);
            m_pData = 0;
            m_nCapacity = 0;
            m_nSize = 0;
        }
    }
    void* m_pData;
    unsigned int m_nSize;
    int m_nCapacity;
};
struct Group;
struct Derived : Base {
    __forceinline Derived(int n) {
        m_pAlloc = DAT_01090a78.FUN_0086bcb0();
        Init(n);
    }
    virtual ~Derived();
    virtual void Free(void* p);
    Group*& operator[](unsigned i) { return ((Group**)m_pData)[i]; }
    void* m_pAlloc;
};
struct Vec3 { float x, y, z; };
struct Ref;
struct RefTable { void* unk00; void (__thiscall* destroy)(Ref*); };
struct Ref { RefTable* table; long refs; };
struct Resource {
    unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18; Ref ref;
    bool FUN_005bcc40(Vec3* a, Vec3* b);
};
struct Smart {
    Resource* object;
    ~Smart() { if(object) { Ref* base=&object->ref; if(!InterlockedDecrement(&base->refs)) base->table->destroy(base); } }
    Resource* operator->() const { return object; }
};
struct Registry { unsigned unk00,unk04; unsigned size; unsigned GetSize() const { return size; } Smart FUN_0043c300(unsigned); };
struct Group { Registry* FUN_007e55b0(); };
struct Obj { unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54; Vec3 p58; Vec3 p64; };
struct Data { Obj* m0; };
struct Sink { void FUN_0041a4b0(const Smart&); };
bool __cdecl FUN_005e6fa0(Data* d, Derived* arr);
bool __cdecl FUN_005f1280(Vec3* a, Vec3* b, Vec3* c, Vec3* d);
// pdb: NavMeshObstacleManager::GetNavMeshListForObstacle | NavMeshObstacleManager.obj | fnv360_0721_beta, objrun, medium
// pdb params: apData, apReturnNavMeshArray
bool __cdecl FUN_005e7120(Data* d, Sink* s)
{
    Derived arr(32);
    if (FUN_005e6fa0(d, &arr))
    {
        for (unsigned i = 0; i < arr.m_nSize; i++)
        {
            Registry* list = arr[i]->FUN_007e55b0();
            if (list)
            {
                for (unsigned j = 0; j < list->GetSize(); j++)
                {
                    Vec3 a, b;
                    bool ok = list->FUN_0043c300(j)->FUN_005bcc40(&a, &b);
                    if (ok)
                    {
                        b.z = (float)(b.z + dbl_00dcc598);
                        if (FUN_005f1280(&a, &b, &d->m0->p58, &d->m0->p64))
                            s->FUN_0041a4b0(list->FUN_0043c300(j));
                    }
                }
            }
        }
    }
    return true;
}
}

// @f3 0x005eb4b0 (community match, verified in this file)
namespace NativeScrapCtor005eb4b0 {
struct Base;
struct Table {void* unk00;void* (__thiscall* allocate)(Base*,unsigned);void (__thiscall* release)(Base*,void*);};
extern Table DAT_00dd8fe4,DAT_00e01ed8;
struct Heap {void* FUN_0086bcb0();};extern Heap DAT_01090a78;
struct Base {Table* vtable;void* data;unsigned count,capacity;
 Base():data(0),count(0),capacity(0){}
 ~Base(){vtable=&DAT_00dd8fe4;if(data){vtable->release(this,data);data=0;capacity=0;count=0;}}
};
struct FUN_005eb4b0:Base {void* allocator;FUN_005eb4b0(unsigned,unsigned,void*);};
// pdb: BSScrapArray<NavMeshInfo const *,1024>::BSScrapArray<NavMeshInfo const *,1024> | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiReserveSize, aiInitialSize, apHeap
FUN_005eb4b0::FUN_005eb4b0(unsigned initialCapacity,unsigned initialCount,void* memory){
 vtable=&DAT_00e01ed8;
 allocator=memory?memory:DAT_01090a78.FUN_0086bcb0();
 data=0;count=0;capacity=0;
 unsigned allocationCount=initialCapacity;
 if(initialCount>allocationCount)allocationCount=initialCount;
 if(allocationCount>0){data=vtable->allocate(this,allocationCount);capacity=allocationCount;}
 if(initialCount>0)count=initialCount;
}
}

// @f3 0x005eb8d0 (community match, verified in this file)
namespace NativeScrapCtor005eb8d0 {
struct Base;
struct Table {void* unk00;void* (__thiscall* allocate)(Base*,unsigned);void (__thiscall* release)(Base*,void*);};
extern Table DAT_00e01e9c,DAT_00e01f14;
struct Heap {void* FUN_0086bcb0();};extern Heap DAT_01090a78;
struct Base {Table* vtable;void* data;unsigned count,capacity;
 Base():data(0),count(0),capacity(0){}
 ~Base(){vtable=&DAT_00e01e9c;if(data){vtable->release(this,data);data=0;capacity=0;count=0;}}
};
struct FUN_005eb8d0:Base {void* allocator;FUN_005eb8d0(unsigned,unsigned,void*);};
// pdb: BSScrapArray<PathBuilder::VirtualNodeSegment,1024>::BSScrapArray<PathBuilder::VirtualNodeSegment,1024> | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiReserveSize, aiInitialSize, apHeap
FUN_005eb8d0::FUN_005eb8d0(unsigned initialCapacity,unsigned initialCount,void* memory){
 vtable=&DAT_00e01f14;
 allocator=memory?memory:DAT_01090a78.FUN_0086bcb0();
 data=0;count=0;capacity=0;
 unsigned allocationCount=initialCapacity;
 if(initialCount>allocationCount)allocationCount=initialCount;
 if(allocationCount>0){data=vtable->allocate(this,allocationCount);capacity=allocationCount;}
 if(initialCount>0)count=initialCount;
}
}

// @f3 0x005f3f90 (community match, verified in this file)
namespace f3m_005f3f90 {
struct Vector3 { float x, y, z; };
struct TlsBlock {
    int u000; int u004; int u008; int u00C; int u010; int u014; int u018; int u01C; int u020; int u024; int u028; int u02C; int u030; int u034; int u038; int u03C; int u040; int u044; int u048; int u04C; int u050; int u054; int u058; int u05C;
    int u060; int u064; int u068; int u06C; int u070; int u074; int u078; int u07C; int u080; int u084; int u088; int u08C; int u090; int u094; int u098; int u09C; int u0A0; int u0A4; int u0A8; int u0AC; int u0B0; int u0B4; int u0B8; int u0BC;
    int u0C0; int u0C4; int u0C8; int u0CC; int u0D0; int u0D4; int u0D8; int u0DC; int u0E0; int u0E4; int u0E8; int u0EC; int u0F0; int u0F4; int u0F8; int u0FC; int u100; int u104; int u108; int u10C; int u110; int u114; int u118; int u11C;
    int u120; int u124; int u128; int u12C; int u130; int u134; int u138; int u13C; int u140; int u144; int u148; int u14C; int u150; int u154; int u158; int u15C; int u160; int u164; int u168; int u16C; int u170; int u174; int u178; int u17C;
    int u180; int u184; int u188; int u18C; int u190; int u194; int u198; int u19C; int u1A0; int u1A4; int u1A8; int u1AC; int u1B0; int u1B4; int u1B8; int u1BC; int u1C0; int u1C4; int u1C8; int u1CC; int u1D0; int u1D4; int u1D8; int u1DC;
    int u1E0; int u1E4; int u1E8; int u1EC; int u1F0; int u1F4; int u1F8; int u1FC; int u200; int u204; int u208; int u20C; int u210; int u214; int u218; int u21C; int u220; int u224; int u228; int u22C; int u230; int u234; int u238; int u23C;
    int u240; int u244; int u248; int u24C; int u250; int u254; int u258; int u25C; int u260; int u264; int u268; int u26C; int u270; int u274; int u278; int u27C; int u280; int u284; int u288; int u28C; int u290; int u294; int u298;
};
__declspec(thread) TlsBlock g_tls = {0};
struct TlsScope {
    int old;
    TlsScope() { old = g_tls.u298; g_tls.u298 = 0x2d; }
    ~TlsScope() { g_tls.u298 = old; }
};
struct PathBuildObj;
struct Loc { void* vtable; Vector3 pos; };
struct VertexArray {
    void** vtable; void* pBuffer; unsigned int iSize; unsigned int iReservedSize;
    void FUN_0079ecc0(unsigned int a_iNewSize, unsigned int a_iMoveCount);
    void SetCapacity(unsigned int n) {
        if (iReservedSize != n) { if (iSize > n) iSize = n; FUN_0079ecc0(n, iSize); iReservedSize = n; }
    }
};
struct TriangleArray {
    void** vtable; void* pBuffer; unsigned int iSize; unsigned int iReservedSize;
    void FUN_005b8620(unsigned int a_iNewSize, unsigned int a_iMoveCount);
    void SetCapacity(unsigned int n) {
        if (iReservedSize != n) { if (iSize > n) iSize = n; FUN_005b8620(n, iSize); iReservedSize = n; }
    }
};
struct PathBuildObj {
    VertexArray Vertices; TriangleArray Triangles; Vector3 start; Vector3 end;
    void FUN_0060fe20();
};
struct Big {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0; int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C; int unk250; int unk254; int unk258; int unk25C; int unk260; int unk264; int unk268; int unk26C; int unk270; int unk274; int unk278; int unk27C; int unk280; int unk284; int unk288; int unk28C; int unk290; int unk294; int unk298; int unk29C;
    int unk2A0; int unk2A4; int unk2A8; int unk2AC; int unk2B0; int unk2B4; int unk2B8; int unk2BC; int unk2C0; int unk2C4; int unk2C8; int unk2CC; int unk2D0; int unk2D4; int unk2D8; int unk2DC; int unk2E0; int unk2E4; int unk2E8; int unk2EC; int unk2F0; int unk2F4; int unk2F8; int unk2FC;
    int unk300; int unk304; int unk308; int unk30C; int unk310; int unk314; int unk318; int unk31C; int unk320; int unk324; int unk328; int unk32C; int unk330; int unk334; int unk338; int unk33C; int unk340; int unk344; int unk348; int unk34C; int unk350; int unk354; int unk358; int unk35C;
    int unk360; int unk364; int unk368; int unk36C; int unk370; int unk374; int unk378; int unk37C; int unk380; int unk384; int unk388; int unk38C; int unk390; int unk394; int unk398; int unk39C; int unk3A0; int unk3A4; int unk3A8; int unk3AC; int unk3B0; int unk3B4; int unk3B8; int unk3BC;
    int unk3C0; int unk3C4; int unk3C8; int unk3CC; int unk3D0; int unk3D4; int unk3D8; int unk3DC; int unk3E0; int unk3E4; int unk3E8; int unk3EC; int unk3F0; int unk3F4; int unk3F8; int unk3FC; int unk400; int unk404; int unk408; int unk40C; int unk410; int unk414; int unk418; int unk41C;
    int unk420; int unk424; int unk428; int unk42C; int unk430; int unk434; int unk438; int unk43C; int unk440; int unk444; int unk448; int unk44C; int unk450; int unk454; int unk458; int unk45C; int unk460; int unk464; int unk468; int unk46C; int unk470; int unk474; int unk478; int unk47C;
    int unk480; int unk484; int unk488; int unk48C; int unk490; int unk494; int unk498; int unk49C; int unk4A0; int unk4A4; int unk4A8; int unk4AC; int unk4B0; int unk4B4; int unk4B8; int unk4BC; int unk4C0; int unk4C4; int unk4C8; int unk4CC; int unk4D0; int unk4D4; int unk4D8; int unk4DC;
    int unk4E0; int unk4E4; int unk4E8; int unk4EC; int unk4F0; int unk4F4; int unk4F8; int unk4FC; int unk500; int unk504; int unk508; int unk50C; int unk510; int unk514; int unk518; int unk51C; int unk520; int unk524; int unk528; int unk52C; int unk530; int unk534; int unk538; int unk53C;
    int unk540; int unk544; int unk548; int unk54C; int unk550; int unk554; int unk558; int unk55C; int unk560; int unk564; int unk568; int unk56C; int unk570; int unk574; int unk578; int unk57C; int unk580; int unk584; int unk588; int unk58C; int unk590; int unk594; int unk598; int unk59C;
    int unk5A0; int unk5A4; int unk5A8; int unk5AC; int unk5B0; int unk5B4; int unk5B8; int unk5BC; int unk5C0; int unk5C4; int unk5C8; int unk5CC; int unk5D0; int unk5D4; int unk5D8; int unk5DC; int unk5E0; int unk5E4; int unk5E8; int unk5EC; int unk5F0; int unk5F4; int unk5F8; int unk5FC;
    int unk600; int unk604; int unk608; int unk60C; int unk610; int unk614; int unk618; int unk61C; int unk620; int unk624; int unk628; int unk62C; int unk630; int unk634; int unk638; int unk63C; int unk640; int unk644; int unk648; int unk64C; int unk650; int unk654; int unk658; int unk65C;
    int unk660; int unk664; int unk668; int unk66C; int unk670; int unk674; int unk678; int unk67C; int unk680; int unk684; int unk688; int unk68C; int unk690; int unk694; int unk698; int unk69C; int unk6A0; int unk6A4; int unk6A8; int unk6AC; int unk6B0; int unk6B4; int unk6B8; int unk6BC;
    int unk6C0; int unk6C4; int unk6C8; int unk6CC; int unk6D0; int unk6D4; int unk6D8; int unk6DC; int unk6E0; int unk6E4; int unk6E8; int unk6EC; int unk6F0; int unk6F4; int unk6F8; int unk6FC; int unk700; int unk704; int unk708; int unk70C; int unk710; int unk714; int unk718; int unk71C;
    int unk720; int unk724; int unk728; int unk72C; int unk730; int unk734; int unk738; int unk73C; int unk740; int unk744; int unk748; int unk74C; int unk750; int unk754; int unk758; int unk75C; int unk760; int unk764; int unk768; int unk76C; int unk770; int unk774; int unk778; int unk77C;
    int unk780; int unk784; int unk788; int unk78C; int unk790; int unk794; int unk798; int unk79C; int unk7A0; int unk7A4; int unk7A8; int unk7AC; int unk7B0; int unk7B4; int unk7B8; int unk7BC; int unk7C0; int unk7C4; int unk7C8; int unk7CC; int unk7D0; int unk7D4; int unk7D8; int unk7DC;
    int unk7E0; int unk7E4; int unk7E8; int unk7EC; int unk7F0; int unk7F4; int unk7F8; int unk7FC; int unk800; int unk804; int unk808; int unk80C; int unk810; int unk814; int unk818; int unk81C; int unk820; int unk824; int unk828; int unk82C; int unk830; int unk834; int unk838; int unk83C;
    int unk840; int unk844; int unk848; int unk84C; int unk850; int unk854; int unk858; int unk85C; int unk860; int unk864; int unk868; int unk86C; int unk870; int unk874; int unk878; int unk87C; int unk880; int unk884; int unk888; int unk88C; int unk890; int unk894; int unk898; int unk89C;
    int unk8A0; int unk8A4; int unk8A8; int unk8AC; int unk8B0; int unk8B4; int unk8B8; int unk8BC; int unk8C0; int unk8C4; int unk8C8; int unk8CC; int unk8D0; int unk8D4; int unk8D8; int unk8DC; int unk8E0; int unk8E4; int unk8E8; int unk8EC; int unk8F0; int unk8F4; int unk8F8; int unk8FC;
    int unk900; int unk904; int unk908; int unk90C; int unk910; int unk914; int unk918; int unk91C; int unk920; int unk924; int unk928; int unk92C; int unk930; int unk934; int unk938; int unk93C; int unk940; int unk944; int unk948; int unk94C; int unk950; int unk954; int unk958; int unk95C;
    int unk960; int unk964; int unk968; int unk96C; int unk970; int unk974; int unk978; int unk97C; int unk980; int unk984; int unk988; int unk98C; int unk990; int unk994; int unk998; int unk99C; int unk9A0; int unk9A4; int unk9A8; int unk9AC; int unk9B0; int unk9B4; int unk9B8; int unk9BC;
    int unk9C0; int unk9C4; int unk9C8; int unk9CC; int unk9D0; int unk9D4; int unk9D8; int unk9DC; int unk9E0; int unk9E4; int unk9E8; int unk9EC; int unk9F0; int unk9F4; int unk9F8; int unk9FC; int unkA00; int unkA04; int unkA08; int unkA0C; int unkA10; int unkA14; int unkA18; int unkA1C;
    int unkA20; int unkA24; int unkA28; int unkA2C; int unkA30; int unkA34; int unkA38; int unkA3C; int unkA40; int unkA44; int unkA48; int unkA4C; int unkA50; int unkA54; int unkA58; int unkA5C; int unkA60; int unkA64; int unkA68; int unkA6C; int unkA70; int unkA74; int unkA78; int unkA7C;
    int unkA80; int unkA84; int unkA88; int unkA8C; int unkA90; int unkA94; int unkA98; int unkA9C; int unkAA0; int unkAA4; int unkAA8; int unkAAC; int unkAB0; int unkAB4; int unkAB8; int unkABC; int unkAC0; int unkAC4; int unkAC8; int unkACC; int unkAD0; int unkAD4; int unkAD8; int unkADC;
    int unkAE0; int unkAE4; int unkAE8; int unkAEC; int unkAF0; int unkAF4; int unkAF8; int unkAFC; int unkB00; int unkB04; int unkB08; int unkB0C; int unkB10; int unkB14; int unkB18; int unkB1C; int unkB20; int unkB24; int unkB28; int unkB2C; int unkB30; int unkB34; int unkB38; int unkB3C;
    int unkB40; int unkB44; int unkB48; int unkB4C; int unkB50; int unkB54; int unkB58; int unkB5C; int unkB60; int unkB64; int unkB68; int unkB6C; int unkB70; int unkB74; int unkB78; int unkB7C; int unkB80; int unkB84; int unkB88; int unkB8C; int unkB90; int unkB94; int unkB98; int unkB9C;
    int unkBA0; int unkBA4; int unkBA8; int unkBAC; int unkBB0; int unkBB4; int unkBB8; int unkBBC; int unkBC0; int unkBC4; int unkBC8; int unkBCC; int unkBD0; int unkBD4; int unkBD8; int unkBDC; int unkBE0; int unkBE4; int unkBE8; int unkBEC; int unkBF0; int unkBF4; int unkBF8; int unkBFC;
    int unkC00; int unkC04; int unkC08; int unkC0C; int unkC10; int unkC14; int unkC18; int unkC1C; int unkC20; int unkC24; int unkC28; int unkC2C; int unkC30; int unkC34; int unkC38; int unkC3C; int unkC40; int unkC44; int unkC48; int unkC4C; int unkC50; int unkC54; int unkC58; int unkC5C;
    int unkC60; int unkC64; int unkC68; int unkC6C; int unkC70; int unkC74; int unkC78; int unkC7C; int unkC80; int unkC84; int unkC88; int unkC8C; int unkC90; int unkC94; int unkC98; int unkC9C; int unkCA0; int unkCA4; int unkCA8; int unkCAC; int unkCB0; int unkCB4; int unkCB8; int unkCBC;
    int unkCC0; int unkCC4; int unkCC8; int unkCCC; int unkCD0; int unkCD4; int unkCD8; int unkCDC; int unkCE0; int unkCE4; int unkCE8; int unkCEC; int unkCF0; int unkCF4; int unkCF8; int unkCFC; int unkD00; int unkD04; int unkD08; int unkD0C; int unkD10; int unkD14; int unkD18; int unkD1C;
    int unkD20; int unkD24; int unkD28; int unkD2C; int unkD30; int unkD34; int unkD38; int unkD3C; int unkD40; int unkD44; int unkD48; int unkD4C; int unkD50; int unkD54; int unkD58; int unkD5C; int unkD60; int unkD64; int unkD68; int unkD6C; int unkD70; int unkD74; int unkD78; int unkD7C;
    int unkD80; int unkD84; int unkD88; int unkD8C; int unkD90; int unkD94; int unkD98; int unkD9C; int unkDA0; int unkDA4; int unkDA8; int unkDAC; int unkDB0; int unkDB4; int unkDB8; int unkDBC; int unkDC0; int unkDC4; int unkDC8; int unkDCC; int unkDD0; int unkDD4; int unkDD8; int unkDDC;
    int unkDE0; int unkDE4; int unkDE8; int unkDEC; int unkDF0; int unkDF4; int unkDF8; int unkDFC; int unkE00; int unkE04; int unkE08; int unkE0C; int unkE10; int unkE14; int unkE18; int unkE1C; int unkE20; int unkE24; int unkE28; int unkE2C; int unkE30; int unkE34; int unkE38; int unkE3C;
    int unkE40; int unkE44; int unkE48; int unkE4C; int unkE50; int unkE54; int unkE58; int unkE5C; int unkE60; int unkE64; int unkE68; int unkE6C; int unkE70; int unkE74; int unkE78; int unkE7C; int unkE80; int unkE84; int unkE88; int unkE8C; int unkE90; int unkE94; int unkE98; int unkE9C;
    int unkEA0; int unkEA4; int unkEA8; int unkEAC; int unkEB0; int unkEB4; int unkEB8; int unkEBC; int unkEC0; int unkEC4; int unkEC8; int unkECC; int unkED0; int unkED4; int unkED8; int unkEDC; int unkEE0; int unkEE4; int unkEE8; int unkEEC; int unkEF0; int unkEF4; int unkEF8; int unkEFC;
    int unkF00; int unkF04; int unkF08; int unkF0C; int unkF10; int unkF14; int unkF18; int unkF1C; int unkF20; int unkF24; int unkF28; int unkF2C; int unkF30; int unkF34; int unkF38; int unkF3C; int unkF40; int unkF44; int unkF48; int unkF4C; int unkF50; int unkF54; int unkF58; int unkF5C;
    int unkF60; int unkF64; int unkF68; int unkF6C; int unkF70; int unkF74; int unkF78; int unkF7C; int unkF80; int unkF84; int unkF88; int unkF8C; int unkF90; int unkF94; int unkF98; int unkF9C; int unkFA0; int unkFA4; int unkFA8; int unkFAC; int unkFB0; int unkFB4; int unkFB8; int unkFBC;
    int unkFC0; int unkFC4; int unkFC8; int unkFCC; int unkFD0; int unkFD4; int unkFD8; int unkFDC; int unkFE0; int unkFE4; int unkFE8; int unkFEC; int unkFF0; int unkFF4; int unkFF8; int unkFFC; int unk1000; int unk1004; int unk1008; int unk100C; int unk1010; int unk1014; int unk1018; int unk101C;
    int unk1020; int unk1024; int unk1028; int unk102C; int unk1030; int unk1034; int unk1038; int unk103C; int unk1040; int unk1044; int unk1048; int unk104C; int unk1050; int unk1054; int unk1058; int unk105C; int unk1060; int unk1064; int unk1068; int unk106C; int unk1070; int unk1074; int unk1078; int unk107C;
    int unk1080; int unk1084; int unk1088; int unk108C; int unk1090; int unk1094; int unk1098; int unk109C; int unk10A0; int unk10A4; int unk10A8; int unk10AC; int unk10B0; int unk10B4; int unk10B8; int unk10BC; int unk10C0; int unk10C4; int unk10C8; int unk10CC; int unk10D0; int unk10D4; int unk10D8; int unk10DC;
    int unk10E0; int unk10E4; int unk10E8; int unk10EC; int unk10F0; int unk10F4; int unk10F8; int unk10FC; int unk1100; int unk1104; int unk1108; int unk110C; int unk1110; int unk1114; int unk1118; int unk111C; int unk1120; int unk1124; int unk1128; int unk112C; int unk1130; int unk1134; int unk1138; int unk113C;
    int unk1140; int unk1144; int unk1148; int unk114C; int unk1150; int unk1154; int unk1158; int unk115C; int unk1160; int unk1164; int unk1168; int unk116C; int unk1170; int unk1174; int unk1178; int unk117C; int unk1180; int unk1184; int unk1188; int unk118C; int unk1190; int unk1194; int unk1198; int unk119C;
    int unk11A0; int unk11A4; int unk11A8; int unk11AC; int unk11B0; int unk11B4; int unk11B8; int unk11BC; int unk11C0; int unk11C4; int unk11C8; int unk11CC; int unk11D0; int unk11D4; int unk11D8; int unk11DC; int unk11E0; int unk11E4; int unk11E8; int unk11EC; int unk11F0; int unk11F4; int unk11F8; int unk11FC;
    int unk1200; int unk1204; int unk1208; int unk120C; int unk1210; int unk1214; int unk1218; int unk121C; int unk1220; int unk1224; int unk1228; int unk122C; int unk1230; int unk1234; int unk1238; int unk123C; int unk1240; int unk1244; int unk1248; int unk124C; int unk1250; int unk1254; int unk1258; int unk125C;
    int unk1260; int unk1264; int unk1268; int unk126C; int unk1270; int unk1274; int unk1278; int unk127C; int unk1280; int unk1284; int unk1288; int unk128C; int unk1290; int unk1294; int unk1298; int unk129C; int unk12A0; int unk12A4; int unk12A8; int unk12AC; int unk12B0; int unk12B4; int unk12B8; int unk12BC;
    int unk12C0; int unk12C4; int unk12C8; int unk12CC; int unk12D0; int unk12D4; int unk12D8; int unk12DC; int unk12E0; int unk12E4; int unk12E8; int unk12EC; int unk12F0; int unk12F4; int unk12F8; int unk12FC; int unk1300; int unk1304; int unk1308; int unk130C; int unk1310; int unk1314; int unk1318; int unk131C;
    int unk1320; int unk1324; int unk1328; int unk132C; int unk1330; int unk1334; int unk1338; int unk133C; int unk1340; int unk1344; int unk1348; int unk134C; int unk1350; int unk1354; int unk1358; int unk135C; int unk1360; int unk1364; int unk1368; int unk136C; int unk1370; int unk1374; int unk1378; int unk137C;
    int unk1380; int unk1384; int unk1388; int unk138C; int unk1390; int unk1394; int unk1398; int unk139C; int unk13A0; int unk13A4; int unk13A8; int unk13AC; int unk13B0; int unk13B4; int unk13B8; int unk13BC; int unk13C0; int unk13C4; int unk13C8; int unk13CC; int unk13D0; int unk13D4; int unk13D8; int unk13DC;
    int unk13E0; int unk13E4; int unk13E8; int unk13EC; int unk13F0; int unk13F4; int unk13F8; int unk13FC; int unk1400; int unk1404; int unk1408; int unk140C; int unk1410; int unk1414; int unk1418; int unk141C; int unk1420; int unk1424; int unk1428; int unk142C; int unk1430; int unk1434; int unk1438; int unk143C;
    int unk1440; int unk1444; int unk1448; int unk144C; int unk1450; int unk1454; int unk1458; int unk145C; int unk1460; int unk1464; int unk1468; int unk146C; int unk1470; int unk1474; int unk1478; int unk147C; int unk1480; int unk1484; int unk1488; int unk148C; int unk1490; int unk1494; int unk1498; int unk149C;
    int unk14A0; int unk14A4; int unk14A8; int unk14AC; int unk14B0; int unk14B4; int unk14B8; int unk14BC; int unk14C0; int unk14C4; int unk14C8; int unk14CC; int unk14D0; int unk14D4; int unk14D8; int unk14DC; int unk14E0; int unk14E4; int unk14E8; int unk14EC; int unk14F0; int unk14F4; int unk14F8; int unk14FC;
    int unk1500; int unk1504; int unk1508; int unk150C; int unk1510; int unk1514; int unk1518; int unk151C; int unk1520; int unk1524; int unk1528; int unk152C; int unk1530; int unk1534; int unk1538; int unk153C; int unk1540; int unk1544; int unk1548; int unk154C; int unk1550; int unk1554; int unk1558; int unk155C;
    int unk1560; int unk1564; int unk1568; int unk156C; int unk1570; int unk1574; int unk1578; int unk157C; int unk1580; int unk1584; int unk1588; int unk158C; int unk1590; int unk1594; int unk1598; int unk159C; int unk15A0; int unk15A4; int unk15A8; int unk15AC; int unk15B0; int unk15B4; int unk15B8; int unk15BC;
    int unk15C0; int unk15C4; int unk15C8; int unk15CC; int unk15D0; int unk15D4; int unk15D8; int unk15DC; int unk15E0; int unk15E4; int unk15E8; int unk15EC; int unk15F0; int unk15F4; int unk15F8; int unk15FC; int unk1600; int unk1604; int unk1608; int unk160C; int unk1610; int unk1614; int unk1618; int unk161C;
    int unk1620; int unk1624; int unk1628; int unk162C; int unk1630; int unk1634; int unk1638; int unk163C; int unk1640; int unk1644; int unk1648; int unk164C; int unk1650; int unk1654; int unk1658; int unk165C; int unk1660; int unk1664; int unk1668; int unk166C; int unk1670; int unk1674; int unk1678; int unk167C;
    int unk1680; int unk1684; int unk1688; int unk168C; int unk1690; int unk1694; int unk1698; int unk169C; int unk16A0; int unk16A4; int unk16A8; int unk16AC; int unk16B0; int unk16B4; int unk16B8; int unk16BC; int unk16C0; int unk16C4; int unk16C8; int unk16CC; int unk16D0; int unk16D4; int unk16D8; int unk16DC;
    int unk16E0; int unk16E4; int unk16E8; int unk16EC; int unk16F0; int unk16F4; int unk16F8; int unk16FC; int unk1700; int unk1704; int unk1708; int unk170C; int unk1710; int unk1714; int unk1718; int unk171C; int unk1720; int unk1724; int unk1728; int unk172C; int unk1730; int unk1734; int unk1738; int unk173C;
    int unk1740; int unk1744; int unk1748; int unk174C; int unk1750; int unk1754; int unk1758; int unk175C; int unk1760; int unk1764; int unk1768; int unk176C; int unk1770; int unk1774; int unk1778; int unk177C; int unk1780; int unk1784; int unk1788; int unk178C; int unk1790; int unk1794; int unk1798; int unk179C;
    int unk17A0; int unk17A4; int unk17A8; int unk17AC; int unk17B0; int unk17B4; int unk17B8; int unk17BC; int unk17C0; int unk17C4; int unk17C8; int unk17CC; int unk17D0; int unk17D4; int unk17D8; int unk17DC; int unk17E0; int unk17E4; int unk17E8; int unk17EC; int unk17F0; int unk17F4; int unk17F8; int unk17FC;
    int unk1800; int unk1804; int unk1808; int unk180C; int unk1810; int unk1814; int unk1818; int unk181C; int unk1820; int unk1824; int unk1828; int unk182C; int unk1830; int unk1834; int unk1838; int unk183C; int unk1840; int unk1844; int unk1848; int unk184C; int unk1850; int unk1854; int unk1858; int unk185C;
    int unk1860; int unk1864; int unk1868; int unk186C; int unk1870; int unk1874; int unk1878; int unk187C; int unk1880; int unk1884; int unk1888; int unk188C; int unk1890; int unk1894; int unk1898; int unk189C; int unk18A0; int unk18A4; int unk18A8; int unk18AC; int unk18B0; int unk18B4; int unk18B8; int unk18BC;
    int unk18C0; int unk18C4; int unk18C8; int unk18CC; int unk18D0; int unk18D4; int unk18D8; int unk18DC; int unk18E0; int unk18E4; int unk18E8; int unk18EC; int unk18F0; int unk18F4; int unk18F8; int unk18FC; int unk1900; int unk1904; int unk1908; int unk190C; int unk1910; int unk1914; int unk1918; int unk191C;
    int unk1920; int unk1924; int unk1928; int unk192C; int unk1930; int unk1934; int unk1938; int unk193C; int unk1940; int unk1944; int unk1948; int unk194C; int unk1950; int unk1954; int unk1958; int unk195C; int unk1960; int unk1964; int unk1968; int unk196C; int unk1970; int unk1974; int unk1978; int unk197C;
    int unk1980; int unk1984; int unk1988; int unk198C; int unk1990; int unk1994; int unk1998; int unk199C; int unk19A0; int unk19A4; int unk19A8; int unk19AC; int unk19B0; int unk19B4; int unk19B8; int unk19BC; int unk19C0; int unk19C4; int unk19C8; int unk19CC; int unk19D0; int unk19D4; int unk19D8; int unk19DC;
    int unk19E0; int unk19E4; int unk19E8; int unk19EC; int unk19F0; int unk19F4; int unk19F8; int unk19FC; int unk1A00; int unk1A04; int unk1A08; int unk1A0C; int unk1A10; int unk1A14; int unk1A18; int unk1A1C; int unk1A20; int unk1A24; int unk1A28; int unk1A2C; int unk1A30; int unk1A34; int unk1A38; int unk1A3C;
    int unk1A40; int unk1A44; int unk1A48; int unk1A4C; int unk1A50; int unk1A54; int unk1A58; int unk1A5C; int unk1A60; int unk1A64; int unk1A68; int unk1A6C; int unk1A70; int unk1A74; int unk1A78; int unk1A7C; int unk1A80; int unk1A84; int unk1A88; int unk1A8C; int unk1A90; int unk1A94; int unk1A98; int unk1A9C;
    int unk1AA0; int unk1AA4; int unk1AA8; int unk1AAC; int unk1AB0; int unk1AB4; int unk1AB8; int unk1ABC; int unk1AC0; int unk1AC4; int unk1AC8; int unk1ACC; int unk1AD0; int unk1AD4; int unk1AD8; int unk1ADC; int unk1AE0; int unk1AE4; int unk1AE8; int unk1AEC; int unk1AF0; int unk1AF4; int unk1AF8; int unk1AFC;
    int unk1B00; int unk1B04; int unk1B08; int unk1B0C; int unk1B10; int unk1B14; int unk1B18; int unk1B1C; int unk1B20; int unk1B24; int unk1B28; int unk1B2C; int unk1B30; int unk1B34; int unk1B38; int unk1B3C; int unk1B40; int unk1B44; int unk1B48; int unk1B4C; int unk1B50; int unk1B54; int unk1B58; int unk1B5C;
    int unk1B60; int unk1B64; int unk1B68; int unk1B6C; int unk1B70; int unk1B74; int unk1B78; int unk1B7C; int unk1B80; int unk1B84; int unk1B88; int unk1B8C; int unk1B90; int unk1B94; int unk1B98; int unk1B9C; int unk1BA0; int unk1BA4; int unk1BA8; int unk1BAC; int unk1BB0; int unk1BB4; int unk1BB8; int unk1BBC;
    int unk1BC0; int unk1BC4; int unk1BC8; int unk1BCC; int unk1BD0; int unk1BD4; int unk1BD8; int unk1BDC; int unk1BE0; int unk1BE4; int unk1BE8; int unk1BEC; int unk1BF0; int unk1BF4; int unk1BF8; int unk1BFC; int unk1C00; int unk1C04; int unk1C08; int unk1C0C; int unk1C10; int unk1C14; int unk1C18; int unk1C1C;
    int unk1C20; int unk1C24; int unk1C28; int unk1C2C; int unk1C30; int unk1C34; int unk1C38; int unk1C3C; int unk1C40; int unk1C44; int unk1C48; int unk1C4C; int unk1C50; int unk1C54; int unk1C58; int unk1C5C; int unk1C60; int unk1C64; int unk1C68; int unk1C6C; int unk1C70; int unk1C74; int unk1C78; int unk1C7C;
    int unk1C80; int unk1C84; int unk1C88; int unk1C8C; int unk1C90; int unk1C94; int unk1C98; int unk1C9C; int unk1CA0; int unk1CA4; int unk1CA8; int unk1CAC; int unk1CB0; int unk1CB4; int unk1CB8; int unk1CBC; int unk1CC0; int unk1CC4; int unk1CC8; int unk1CCC; int unk1CD0; int unk1CD4; int unk1CD8; int unk1CDC;
    int unk1CE0; int unk1CE4; int unk1CE8; int unk1CEC; int unk1CF0; int unk1CF4; int unk1CF8; int unk1CFC; int unk1D00; int unk1D04; int unk1D08; int unk1D0C; int unk1D10; int unk1D14; int unk1D18; int unk1D1C; int unk1D20; int unk1D24; int unk1D28; int unk1D2C; int unk1D30; int unk1D34; int unk1D38; int unk1D3C;
    int unk1D40; int unk1D44; int unk1D48; int unk1D4C; int unk1D50; int unk1D54; int unk1D58; int unk1D5C; int unk1D60; int unk1D64; int unk1D68; int unk1D6C; int unk1D70; int unk1D74; int unk1D78; int unk1D7C; int unk1D80; int unk1D84; int unk1D88; int unk1D8C; int unk1D90; int unk1D94; int unk1D98; int unk1D9C;
    int unk1DA0; int unk1DA4; int unk1DA8; int unk1DAC; int unk1DB0; int unk1DB4; int unk1DB8; int unk1DBC; int unk1DC0; int unk1DC4; int unk1DC8; int unk1DCC; int unk1DD0; int unk1DD4; int unk1DD8; int unk1DDC; int unk1DE0; int unk1DE4; int unk1DE8; int unk1DEC; int unk1DF0; int unk1DF4; int unk1DF8; int unk1DFC;
    int unk1E00; int unk1E04; int unk1E08; int unk1E0C; int unk1E10; int unk1E14; int unk1E18; int unk1E1C; int unk1E20; int unk1E24; int unk1E28; int unk1E2C; int unk1E30; int unk1E34; int unk1E38; int unk1E3C; int unk1E40; int unk1E44; int unk1E48; int unk1E4C; int unk1E50; int unk1E54; int unk1E58; int unk1E5C;
    int unk1E60; int unk1E64; int unk1E68; int unk1E6C; int unk1E70; int unk1E74; int unk1E78; int unk1E7C; int unk1E80; int unk1E84; int unk1E88; int unk1E8C; int unk1E90; int unk1E94; int unk1E98; int unk1E9C; int unk1EA0; int unk1EA4; int unk1EA8; int unk1EAC; int unk1EB0; int unk1EB4; int unk1EB8; int unk1EBC;
    int unk1EC0; int unk1EC4; int unk1EC8; int unk1ECC; int unk1ED0; int unk1ED4; int unk1ED8; int unk1EDC; int unk1EE0; int unk1EE4; int unk1EE8; int unk1EEC; int unk1EF0; int unk1EF4; int unk1EF8; int unk1EFC; int unk1F00; int unk1F04; int unk1F08; int unk1F0C; int unk1F10; int unk1F14; int unk1F18; int unk1F1C;
    int unk1F20; int unk1F24; int unk1F28; int unk1F2C; int unk1F30; int unk1F34; int unk1F38; int unk1F3C; int unk1F40; int unk1F44; int unk1F48; int unk1F4C; int unk1F50; int unk1F54; int unk1F58; int unk1F5C; int unk1F60; int unk1F64; int unk1F68; int unk1F6C; int unk1F70; int unk1F74; int unk1F78; int unk1F7C;
    int unk1F80; int unk1F84; int unk1F88; int unk1F8C; int unk1F90; int unk1F94; int unk1F98; int unk1F9C; int unk1FA0; int unk1FA4; int unk1FA8; int unk1FAC; int unk1FB0; int unk1FB4; int unk1FB8; int unk1FBC; int unk1FC0; int unk1FC4; int unk1FC8; int unk1FCC; int unk1FD0; int unk1FD4; int unk1FD8; int unk1FDC;
    int unk1FE0; int unk1FE4; int unk1FE8; int unk1FEC; int unk1FF0; int unk1FF4; int unk1FF8; int unk1FFC; int unk2000; int unk2004; int unk2008; int unk200C; int unk2010; int unk2014; int unk2018; int unk201C; int unk2020; int unk2024; int unk2028; int unk202C; int unk2030; int unk2034; int unk2038; int unk203C;
    int unk2040; int unk2044; int unk2048; int unk204C; int unk2050; int unk2054; int unk2058; int unk205C; int unk2060; int unk2064; int unk2068; int unk206C; int unk2070; int unk2074; int unk2078; int unk207C; int unk2080; int unk2084; int unk2088; int unk208C; int unk2090; int unk2094; int unk2098; int unk209C;
    int unk20A0; int unk20A4; int unk20A8; int unk20AC; int unk20B0; int unk20B4;
    void FUN_0060f170(); void FUN_0060f1f0();
    bool FUN_0060fa90(Loc* a1, Loc* a2, PathBuildObj* out, int a4, float f, int a6, int a7);
    Big() { FUN_0060f170(); }
    ~Big() { FUN_0060f1f0(); }
};
// pdb: Pathing::BuildTeleportDoorPath | Pathfind.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aOrigin, aDestination, apRetPath, aRestrictions, afMaxDist, apActorLockData, aeDoorLockDisp
bool FUN_005f3f90(Loc* a1, Loc* a2, PathBuildObj* out, int a4, float f, int a6, int a7)
{
    TlsScope scope;
    Big big;
    out->FUN_0060fe20();
    out->Vertices.SetCapacity(10);
    out->Triangles.SetCapacity(10);
    bool ok = big.FUN_0060fa90(a1, a2, out, a4, f, a6, a7);
    if (ok) {
        Vector3 tmp1 = a1->pos;
        out->start = tmp1;
        Vector3 tmp2 = a2->pos;
        out->end = tmp2;
        return true;
    }
    return false;
}
}   // namespace f3m_005f3f90

// @f3 0x005fc160 (community match, verified in this file)
struct NormalProxy {
    float FUN_00457910();
};

namespace f3m_005fc160 {

struct NiPoint3 : NormalProxy {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator+(const NiPoint3& pt) const { return NiPoint3(x + pt.x, y + pt.y, z + pt.z); }
    NiPoint3 operator-(const NiPoint3& pt) const { return NiPoint3(x - pt.x, y - pt.y, z - pt.z); }
    NiPoint3 operator*(float s) const { return NiPoint3(x * s, y * s, z * s); }
    NiPoint3 operator/(float s) const { float inv = 1.0f / s; return NiPoint3(x * inv, y * inv, z * inv); }
    NiPoint3& operator+=(const NiPoint3& pt) { x += pt.x; y += pt.y; z += pt.z; return *this; }
    NiPoint3& operator/=(float s) { float inv = 1.0f / s; x *= inv; y *= inv; z *= inv; return *this; }
    float Dot(const NiPoint3& pt) const { return x * pt.x + y * pt.y + z * pt.z; }
    float SqrLength() const { return x * x + y * y + z * z; }
    float Unitize() { return FUN_00457910(); }
};

extern NiPoint3 DAT_0108ec68;

enum AVOID_NODE_TYPE {
    AVOID_NODE_SPHERE = 0,
    AVOID_NODE_CYLINDER = 1,
    AVOID_NODE_SPHERE_ACTOR = 2
};

struct PathingAvoidNode {
    NiPoint3 kPoint;
    NiPoint3 kPoint2;
    float fRadius;
    float fCost;
    AVOID_NODE_TYPE eType;
};

struct PathingAvoidNodeArray {
    void** vtable;
    PathingAvoidNode* pBuffer;
    unsigned int uiSize;
    unsigned int uiCapacity;
    float FUN_005fc160(const NiPoint3& arPoint, NiPoint3& arCenter);
};


float PathingAvoidNodeArray::FUN_005fc160(const NiPoint3& arPoint, NiPoint3& arCenter)
{
    float fTotalRadius = 0.0f;
    arCenter = DAT_0108ec68;
    float fTotalCost = 0.0f;
    unsigned int uiCount = uiSize;
    if (uiCount > 0) {
        for (unsigned int i = 0; i < uiCount; ++i) {
            PathingAvoidNode& node = pBuffer[i];
            float fCost = node.fCost;
            NiPoint3 kPoint = node.kPoint;
            if (node.eType == AVOID_NODE_CYLINDER) {
                NiPoint3 kDir = node.kPoint2 - node.kPoint;
                NiPoint3 kDelta = arPoint - node.kPoint;
                float fDot = kDelta.Dot(kDir);
                if (fDot < 0.0f) {
                    kPoint = node.kPoint;
                } else {
                    float fLengthSqr = kDir.SqrLength();
                    if (fLengthSqr < fDot) {
                        kPoint = node.kPoint2;
                    } else {
                        float fLength = kDir.Unitize();
                        kPoint = kDir * fDot / fLength + node.kPoint;
                    }
                }
            }
            arCenter += kPoint * fCost;
            fTotalRadius += node.fRadius;
            fTotalCost += fCost;
        }
        arCenter /= fTotalCost;
    }
    return fTotalRadius;
}

}

// @f3 0x005ee080 (community match, verified in this file)
#include <math.h>
#include <float.h>

namespace n5ee080 {

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator+(const NiPoint3& pt) const {
        return NiPoint3(x + pt.x, y + pt.y, z + pt.z);
    }
    NiPoint3 operator-(const NiPoint3& pt) const {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3 operator*(float fScalar) const {
        return NiPoint3(fScalar * x, fScalar * y, fScalar * z);
    }
    float Length() const {
        return NiSqrt(x * x + y * y + z * z);
    }
    static float NiSqrt(float f) { return (float)sqrt(f); }
};

struct BSRefObject {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(BSRefObject*))vtable[1])(this);
    }
};

struct NavMeshTriangle {
    unsigned short vertices[3];
    unsigned short unk06;
    unsigned int unk08;
    unsigned int uiFlags;
    bool IsFlag4() const { return (uiFlags >> 4) & 1; }
};

struct NavMeshInfo;
struct TriArr;

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BSRefObject ref1C;
    void* pParentCell;
    int unk28;
    NiPoint3* pVertices;
    int unk30, unk34, unk38;
    NavMeshTriangle* pTriangles;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    bool FUN_005bd410(const NiPoint3& ar_Location, float af_Radius, unsigned short* ap_usTriangle, int* ap_iEdgeIndex, bool ab_AllowWater);
    void FUN_005b8960(unsigned short a_usTriangle, int a_iEdgeIndex, NiPoint3& ar_Vertex0, NiPoint3& ar_Vertex1);
    void* FUN_005b8480();
    NavMeshInfo* FUN_005b84c0();
    void FUN_005c1280(NavMeshInfo* ap_Info, TriArr* ap_Triangles);
    NavMeshTriangle* GetTriangle(unsigned short a_usTriangle) { return &pTriangles[a_usTriangle]; }
    __declspec(noinline) NiPoint3 FUN_004d45e0(unsigned short a_usTriangle) const {
        const NavMeshTriangle& kTri = pTriangles[a_usTriangle];
        NiPoint3 kCenter = pVertices[kTri.vertices[0]];
        const NiPoint3& kV1 = pVertices[kTri.vertices[1]];
        const NiPoint3& kV2 = pVertices[kTri.vertices[2]];
        kCenter.x = (kCenter.x + kV1.x + kV2.x) * 0.333333f;
        kCenter.y = (kCenter.y + kV1.y + kV2.y) * 0.333333f;
        kCenter.z = (kCenter.z + kV1.z + kV2.z) * 0.333333f;
        return kCenter;
    }
};

__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<NavMesh>* ap_spNavMesh, NavMesh* ap_NavMesh) {
    NiPointer<NavMesh> spNavMesh(ap_NavMesh);
    *ap_spNavMesh = spNavMesh;
}

struct NavMeshInfo {
    int unk00;
    int unk04;
    unsigned int uiFlags;
    int unk0C;
    NiPoint3 m_10;
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    NavMesh* pNavMesh;
    bool GetDisabled() const { return (uiFlags >> 4) & 1; }
    bool GetNavMesh(NiPointer<NavMesh>& ar_spNavMesh) const {
        if (GetDisabled())
            return false;
        FUN_005b87d0(&ar_spNavMesh, pNavMesh);
        return ar_spNavMesh.m_pObject != 0;
    }
};

extern int DAT_00dc4dc0;

struct PathingLocation {
    void* m_vtable;
    NiPoint3 Location;
    NavMeshInfo* pNavMeshInfo;
    void* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;

    PathingLocation(const NiPoint3& ar_Location, const NavMeshInfo* ap_NavMesh, unsigned short a_usTriangle);
    ~PathingLocation() { m_vtable = &DAT_00dc4dc0; }
    PathingLocation& FUN_005fc480(const PathingLocation& ar_Other);
    void FUN_005fdde0();
    NavMeshInfo* FUN_005fcbf0();
    NiPoint3 GetLocation() const { return Location; }
};

struct TriArr {
    void* table;
    int* data;
    unsigned int count;
    unsigned int capacity;
    int unk10;
    TriArr(int a, int b, int c);
    ~TriArr();
    unsigned int GetSize() { return count; }
    int* GetAt(unsigned int i) { return &data[i]; }
};

struct TESshell {
    float TES_GetWaterHeight(NiPoint3* ap_Point, void* ap_Cell);
};
extern TESshell* DAT_0107a0d8;

struct ArgObj {
    int iFlags;
    PathingLocation kLocation;
    PathingLocation* FUN_00717e50() { return &kLocation; }
};

inline bool IsFlag2(const int* pFlags) { return (*pFlags & 2) == 2; }

struct Request {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    PathingLocation kLocation;
    int unk5C, unk60, unk64;
    float f68;
    float GetFloatAtOffset68() { return f68; }
    PathingLocation* FUN_006a9540() { return &kLocation; }
};

struct ThisCls {
    Request* m_00;
    int m_04;
    int m_08;
    bool FUN_005ee080(ArgObj* a0, ArgObj* a1, PathingLocation* apOutLocation);
};

bool ThisCls::FUN_005ee080(ArgObj* a0, ArgObj* a1, PathingLocation* apOutLocation)
{
    a0->FUN_00717e50()->FUN_005fdde0();
    NiPointer<NavMesh> navPtr;
    if (!a0->FUN_00717e50()->FUN_005fcbf0()->GetNavMesh(navPtr))
        return false;
    if (IsFlag2((const int*)a0))
    {
        unsigned short wIdxW;
        int iIdxT;
        float zlen;
        zlen = (a1->FUN_00717e50()->GetLocation() - a0->FUN_00717e50()->FUN_005fcbf0()->m_10).Length();
        wIdxW = 0xffff;
        iIdxT = -1;
        if (navPtr->FUN_005bd410(a1->FUN_00717e50()->GetLocation(), zlen * 2.0, &wIdxW, &iIdxT, 0))
        {
            NiPoint3 upt4c;
            NiPoint3 pt34G;
            navPtr->FUN_005b8960(wIdxW, iIdxT, upt4c, pt34G);
            NiPoint3 wpt28 = navPtr->FUN_004d45e0(wIdxW);
            NiPoint3 xtmp40 = (upt4c + pt34G) * 0.45f + wpt28 * 0.1f;
            float vf50;
            vf50 = DAT_0107a0d8->TES_GetWaterHeight(&xtmp40, navPtr->FUN_005b8480());
            if (vf50 + 25.0 > xtmp40.z)
                xtmp40.z = vf50;
            apOutLocation->FUN_005fc480(PathingLocation(xtmp40, navPtr->FUN_005b84c0(), wIdxW));
            return true;
        }
    }
    else
    {
        float ubest;
        TriArr zarr(0, 0, m_08);
        int bestIdxz;
        unsigned int ui;
        float tlen2;
        NavMeshTriangle* ttri;
        float rf94;
        navPtr->FUN_005c1280(a1->FUN_00717e50()->FUN_005fcbf0(), &zarr);
        bestIdxz = 0xffff;
        ubest = FLT_MAX;
        ui = 0;
        for (; ui < zarr.GetSize(); ui++)
        {
            ttri = navPtr->GetTriangle(*(unsigned short*)zarr.GetAt(ui));
            if (m_00->GetFloatAtOffset68() > 150.0f && ttri->IsFlag4())
                continue;
            NiPoint3 pt84S = navPtr->FUN_004d45e0(*(unsigned short*)zarr.GetAt(ui));
            tlen2 = (pt84S - m_00->FUN_006a9540()->GetLocation()).Length();
            if (tlen2 < ubest)
            {
                tlen2 = ubest;
                bestIdxz = *zarr.GetAt(ui);
            }
        }
        if (bestIdxz != 0xffff)
        {
            NiPoint3 pt90N = navPtr->FUN_004d45e0((unsigned short)bestIdxz);
            rf94 = DAT_0107a0d8->TES_GetWaterHeight(&pt90N, navPtr->FUN_005b8480());
            if (rf94 + 25.0 > pt90N.z)
                pt90N.z = rf94;
            apOutLocation->FUN_005fc480(PathingLocation(pt90N, a0->FUN_00717e50()->FUN_005fcbf0(), (unsigned short)bestIdxz));
            return true;
        }
    }
    return false;
}

}

// @f3 0x005e4890 (community match, verified in this file)
namespace f3m_005e4890 {
namespace f3m_005e4890 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiPoint3
{
public:
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};

class NiMatrix3
{
public:
    float m_pEntry[3][3];
};

class NiColorA
{
public:
    float r, g, b, a;
    NiColorA(float fR, float fG, float fB, float fA)
    {
        r = fR;
        g = fG;
        b = fB;
        a = fA;
    }
};

class NiTransform
{
public:
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer
{
public:
    T* m_pObject;
    NiPointer(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer& operator=(const NiPointer& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const { return m_pObject; }
    T* operator->() const { return m_pObject; }
};

class NiAVObject : public NiRefObject
{
public:
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    NiTransform m_kLocal;

    void SetTranslate(const NiPoint3& kTrn) { m_kLocal.m_Translate = kTrn; }
    void SetRotate(const NiMatrix3& kRot) { m_kLocal.m_Rotate = kRot; }
};

class ObstacleData : public NiRefObject
{
public:
    int unk08, unk0c;
    NiPoint3 kTranslate;
    NiMatrix3 kRotate;
    NiPoint3 kMinBounds;
    NiPoint3 kMaxBounds;
    int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    NiPointer<NiAVObject> spGeometry;
};

NiAVObject* __cdecl FUN_00479f20(NiPoint3& a, NiPoint3& b, NiPoint3& c, NiPoint3& d, NiPoint3& e, NiPoint3& f,
                                 NiPoint3& g, NiPoint3& h, NiColorA& kColor, bool bFlag);

class NavMeshObstacleManager
{
public:
    void FUN_005e4890(NiPointer<ObstacleData>& aspObstacleData, NiPointer<NiAVObject>& spResult);
};

// FNV twin: NavMeshObstacleManager::CreateObstacleBox (fnv 0x006c5840).
void NavMeshObstacleManager::FUN_005e4890(NiPointer<ObstacleData>& aspObstacleData, NiPointer<NiAVObject>& spResult)
{
    NiColorA kBoxColor(1.0f, 0.0f, 1.0f, 0.5f);
    NiPoint3 kCorner0(aspObstacleData->kMinBounds.x, aspObstacleData->kMinBounds.y, aspObstacleData->kMinBounds.z);
    NiPoint3 kCorner1(aspObstacleData->kMaxBounds.x, aspObstacleData->kMinBounds.y, aspObstacleData->kMinBounds.z);
    NiPoint3 kCorner2(aspObstacleData->kMaxBounds.x, aspObstacleData->kMinBounds.y, aspObstacleData->kMaxBounds.z);
    NiPoint3 kCorner3(aspObstacleData->kMinBounds.x, aspObstacleData->kMinBounds.y, aspObstacleData->kMaxBounds.z);
    NiPoint3 kCorner4(aspObstacleData->kMinBounds.x, aspObstacleData->kMaxBounds.y, aspObstacleData->kMinBounds.z);
    NiPoint3 kCorner5(aspObstacleData->kMaxBounds.x, aspObstacleData->kMaxBounds.y, aspObstacleData->kMinBounds.z);
    NiPoint3 kCorner6(aspObstacleData->kMaxBounds.x, aspObstacleData->kMaxBounds.y, aspObstacleData->kMaxBounds.z);
    NiPoint3 kCorner7(aspObstacleData->kMinBounds.x, aspObstacleData->kMaxBounds.y, aspObstacleData->kMaxBounds.z);
    NiPointer<NiAVObject> spBoxGeom(FUN_00479f20(kCorner7, kCorner6, kCorner2, kCorner3, kCorner4, kCorner5, kCorner1,
                                                 kCorner0, kBoxColor, true));
    spBoxGeom->SetTranslate(aspObstacleData->kTranslate);
    spBoxGeom->SetRotate(aspObstacleData->kRotate);
    aspObstacleData->spGeometry = spBoxGeom;
    spResult = spBoxGeom;
}
}
}   // namespace f3m_005e4890

// @f3 0x005f4990 (community match, verified in this file)
extern __declspec(thread) int allocContext;
namespace f3m_005f4990 {
namespace f3m_005f4990 {
struct AllocTagScope {
    int saved;
    AllocTagScope() : saved(allocContext) { allocContext = 45; }
    ~AllocTagScope() { allocContext = saved; }
};
struct Vec3 { float x, y, z; };
struct RefCounted {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(RefCounted*))vtable[1])(this);
    }
};
struct NavMeshInfo;
struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounted ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    Vec3 FUN_004d45e0(unsigned short triangle) const;
    NavMeshInfo* FUN_005b84c0();
};
struct PathingLocation {
    void* vtable;
    Vec3 location;
    NavMeshInfo* navMeshInfo;
    void* navMeshes;
    void* cell;
    void* worldSpace;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    bool FUN_005fcc10();
    bool FUN_005fc8f0(NiPointer<NavMesh>& mesh, unsigned short& triangle);
    Vec3 GetLocation() const { return location; }
};
struct PathingRequest {
    int unk00, unk04, unk08;
    PathingLocation start;
    PathingLocation goal;
    PathingLocation* GetStart() { return &start; }
    PathingLocation* GetGoal() { return &goal; }
};
struct RouteRecord {
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    int unk08, unk0c, unk10;
};
typedef RouteRecord MeshTriangle;
struct MeshRoute {
    void* vtable;
    RouteRecord* data;
    unsigned int size, capacity;
    void* allocator;
    MeshRoute(unsigned int capacity, unsigned int initial, void* allocator);
    ~MeshRoute();
    unsigned int GetSize() const { return size; }
    __forceinline RouteRecord GetAt(unsigned int index) const { return data[index]; }
};
struct TransitionRoute {
    void* vtable;
    void* data;
    unsigned int size, capacity;
    void* allocator;
    TransitionRoute(unsigned int capacity, unsigned int initial, void* allocator);
    ~TransitionRoute();
};
struct SmoothRoute {
    void* vtable;
    void* data;
    unsigned int size, capacity;
    void* allocator;
    SmoothRoute(unsigned int capacity, unsigned int initial, void* allocator);
    ~SmoothRoute();
};
struct SearchState {
    unsigned int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    unsigned int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    unsigned int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    unsigned int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    unsigned int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    unsigned int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    unsigned int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    unsigned int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    unsigned int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    unsigned int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    unsigned int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    unsigned int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    unsigned int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    unsigned int unk01a0, unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc;
    unsigned int unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    unsigned int unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc;
    unsigned int unk0200, unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c;
    unsigned int unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    unsigned int unk0240, unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c;
    unsigned int unk0260, unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c;
    unsigned int unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    unsigned int unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc;
    unsigned int unk02c0, unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc;
    unsigned int unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    unsigned int unk0300, unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c;
    unsigned int unk0320, unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c;
    unsigned int unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    unsigned int unk0360, unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c;
    unsigned int unk0380, unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c;
    unsigned int unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    unsigned int unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc;
    unsigned int unk03e0, unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc;
    unsigned int unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    unsigned int unk0420, unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c;
    unsigned int unk0440, unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c;
    unsigned int unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    unsigned int unk0480, unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c;
    unsigned int unk04a0, unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc;
    unsigned int unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    unsigned int unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc;
    unsigned int unk0500, unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c;
    unsigned int unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    unsigned int unk0540, unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c;
    unsigned int unk0560, unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c;
    unsigned int unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    unsigned int unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc;
    unsigned int unk05c0, unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc;
    unsigned int unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    unsigned int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    unsigned int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    unsigned int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    unsigned int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    unsigned int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    unsigned int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    unsigned int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    unsigned int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    unsigned int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    unsigned int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    unsigned int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    unsigned int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    unsigned int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    unsigned int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    unsigned int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    unsigned int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    unsigned int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    unsigned int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    unsigned int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    unsigned int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    unsigned int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    unsigned int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    unsigned int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    unsigned int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    unsigned int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    unsigned int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    unsigned int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    unsigned int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    unsigned int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    unsigned int unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    unsigned int unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc;
    unsigned int unk09e0, unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc;
    unsigned int unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    unsigned int unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c;
    unsigned int unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c;
    unsigned int unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    unsigned int unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c;
    unsigned int unk0aa0, unk0aa4, unk0aa8, unk0aac, unk0ab0, unk0ab4, unk0ab8, unk0abc;
    unsigned int unk0ac0, unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc;
    unsigned int unk0ae0, unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc;
    unsigned int unk0b00, unk0b04, unk0b08, unk0b0c, unk0b10, unk0b14, unk0b18, unk0b1c;
    unsigned int unk0b20, unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c;
    unsigned int unk0b40, unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c;
    unsigned int unk0b60, unk0b64, unk0b68, unk0b6c, unk0b70, unk0b74, unk0b78, unk0b7c;
    unsigned int unk0b80, unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c;
    unsigned int unk0ba0, unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc;
    unsigned int unk0bc0, unk0bc4, unk0bc8, unk0bcc, unk0bd0, unk0bd4, unk0bd8, unk0bdc;
    unsigned int unk0be0, unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    unsigned int unk0c00, unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c;
    unsigned int unk0c20, unk0c24, unk0c28, unk0c2c, unk0c30, unk0c34, unk0c38, unk0c3c;
    unsigned int unk0c40, unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c;
    unsigned int unk0c60, unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c;
    unsigned int unk0c80, unk0c84, unk0c88, unk0c8c, unk0c90, unk0c94, unk0c98, unk0c9c;
    unsigned int unk0ca0, unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    unsigned int unk0cc0, unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc;
    unsigned int unk0ce0, unk0ce4, unk0ce8, unk0cec, unk0cf0, unk0cf4, unk0cf8, unk0cfc;
    unsigned int unk0d00, unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c;
    unsigned int unk0d20, unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c;
    unsigned int unk0d40, unk0d44, unk0d48, unk0d4c, unk0d50, unk0d54, unk0d58, unk0d5c;
    unsigned int unk0d60, unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c;
    unsigned int unk0d80, unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c;
    unsigned int unk0da0, unk0da4, unk0da8, unk0dac, unk0db0, unk0db4, unk0db8, unk0dbc;
    unsigned int unk0dc0, unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    unsigned int unk0de0, unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc;
    unsigned int unk0e00, unk0e04, unk0e08, unk0e0c, unk0e10, unk0e14, unk0e18, unk0e1c;
    unsigned int unk0e20, unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c;
    unsigned int unk0e40, unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c;
    unsigned int unk0e60, unk0e64, unk0e68, unk0e6c, unk0e70, unk0e74, unk0e78, unk0e7c;
    unsigned int unk0e80, unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c;
    unsigned int unk0ea0, unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc;
    unsigned int unk0ec0, unk0ec4, unk0ec8, unk0ecc, unk0ed0, unk0ed4, unk0ed8, unk0edc;
    unsigned int unk0ee0, unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc;
    unsigned int unk0f00, unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c;
    unsigned int unk0f20, unk0f24, unk0f28, unk0f2c, unk0f30, unk0f34, unk0f38, unk0f3c;
    unsigned int unk0f40, unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c;
    unsigned int unk0f60, unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c;
    unsigned int unk0f80, unk0f84, unk0f88, unk0f8c, unk0f90, unk0f94, unk0f98, unk0f9c;
    unsigned int unk0fa0, unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    unsigned int unk0fc0, unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc;
    unsigned int unk0fe0, unk0fe4, unk0fe8, unk0fec, unk0ff0, unk0ff4, unk0ff8, unk0ffc;
    unsigned int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    unsigned int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    unsigned int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    unsigned int unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    unsigned int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    unsigned int unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    unsigned int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    unsigned int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    unsigned int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c;
    unsigned int unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    unsigned int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c;
    unsigned int unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    unsigned int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    unsigned int unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    unsigned int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc;
    unsigned int unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    unsigned int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c;
    unsigned int unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    unsigned int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    unsigned int unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    unsigned int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c;
    unsigned int unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    unsigned int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc;
    unsigned int unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    unsigned int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    unsigned int unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    unsigned int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c;
    unsigned int unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    unsigned int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c;
    unsigned int unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    unsigned int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    unsigned int unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    unsigned int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c;
    unsigned int unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    unsigned int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c;
    unsigned int unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    unsigned int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    unsigned int unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    unsigned int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc;
    unsigned int unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    unsigned int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c;
    unsigned int unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    unsigned int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    unsigned int unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    unsigned int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c;
    unsigned int unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    unsigned int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc;
    unsigned int unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    unsigned int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    unsigned int unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    unsigned int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c;
    unsigned int unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    unsigned int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c;
    unsigned int unk16a0, unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc;
    unsigned int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc;
    unsigned int unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc;
    unsigned int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c;
    unsigned int unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    unsigned int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c;
    unsigned int unk1760, unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c;
    unsigned int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c;
    unsigned int unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc;
    unsigned int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc;
    unsigned int unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    unsigned int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c;
    unsigned int unk1820, unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c;
    unsigned int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c;
    unsigned int unk1860, unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c;
    unsigned int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c;
    unsigned int unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    unsigned int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc;
    unsigned int unk18e0, unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc;
    unsigned int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c;
    unsigned int unk1920, unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c;
    unsigned int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c;
    unsigned int unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    unsigned int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c;
    unsigned int unk19a0, unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc;
    unsigned int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc;
    unsigned int unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc;
    unsigned int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c;
    unsigned int unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    unsigned int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c;
    unsigned int unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c;
    unsigned int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c;
    unsigned int unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc;
    unsigned int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc;
    unsigned int unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    unsigned int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c;
    unsigned int unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c;
    unsigned int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c;
    unsigned int unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c;
    unsigned int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c;
    unsigned int unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    unsigned int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    unsigned int unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    unsigned int unk1c00, unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c;
    unsigned int unk1c20, unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34, unk1c38, unk1c3c;
    unsigned int unk1c40, unk1c44, unk1c48, unk1c4c, unk1c50, unk1c54, unk1c58, unk1c5c;
    unsigned int unk1c60, unk1c64, unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c;
    unsigned int unk1c80, unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c;
    unsigned int unk1ca0, unk1ca4, unk1ca8, unk1cac, unk1cb0, unk1cb4, unk1cb8, unk1cbc;
    unsigned int unk1cc0, unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc;
    unsigned int unk1ce0, unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4, unk1cf8, unk1cfc;
    unsigned int unk1d00, unk1d04, unk1d08, unk1d0c, unk1d10, unk1d14, unk1d18, unk1d1c;
    unsigned int unk1d20, unk1d24, unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c;
    unsigned int unk1d40, unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c;
    unsigned int unk1d60, unk1d64, unk1d68, unk1d6c, unk1d70, unk1d74, unk1d78, unk1d7c;
    unsigned int unk1d80, unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c;
    unsigned int unk1da0, unk1da4, unk1da8, unk1dac, unk1db0, unk1db4, unk1db8, unk1dbc;
    unsigned int unk1dc0, unk1dc4, unk1dc8, unk1dcc, unk1dd0, unk1dd4, unk1dd8, unk1ddc;
    unsigned int unk1de0, unk1de4, unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc;
    unsigned int unk1e00, unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c;
    unsigned int unk1e20, unk1e24, unk1e28, unk1e2c, unk1e30, unk1e34, unk1e38, unk1e3c;
    unsigned int unk1e40, unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c;
    unsigned int unk1e60, unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74, unk1e78, unk1e7c;
    unsigned int unk1e80, unk1e84, unk1e88, unk1e8c, unk1e90, unk1e94, unk1e98, unk1e9c;
    unsigned int unk1ea0, unk1ea4, unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    unsigned int unk1ec0, unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc;
    unsigned int unk1ee0, unk1ee4, unk1ee8, unk1eec, unk1ef0, unk1ef4, unk1ef8, unk1efc;
    unsigned int unk1f00, unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c;
    unsigned int unk1f20, unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34, unk1f38, unk1f3c;
    unsigned int unk1f40, unk1f44, unk1f48, unk1f4c, unk1f50, unk1f54, unk1f58, unk1f5c;
    unsigned int unk1f60, unk1f64, unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c;
    unsigned int unk1f80, unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c;
    unsigned int unk1fa0, unk1fa4, unk1fa8, unk1fac, unk1fb0, unk1fb4, unk1fb8, unk1fbc;
    unsigned int unk1fc0, unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc;
    unsigned int unk1fe0, unk1fe4, unk1fe8, unk1fec, unk1ff0, unk1ff4, unk1ff8, unk1ffc;
    unsigned int unk2000, unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c;
    unsigned int unk2020, unk2024, unk2028, unk202c, unk2030, unk2034, unk2038, unk203c;
    unsigned int unk2040, unk2044, unk2048, unk204c, unk2050, unk2054, unk2058, unk205c;
    unsigned int unk2060, unk2064, unk2068, unk206c, unk2070, unk2074, unk2078, unk207c;
    unsigned int unk2080, unk2084, unk2088, unk208c, unk2090, unk2094, unk2098, unk209c;
    unsigned int unk20a0, unk20a4, unk20a8, unk20ac, unk20b0, unk20b4, unk20b8, unk20bc;
    unsigned int unk20c0, unk20c4, unk20c8, unk20cc, unk20d0, unk20d4, unk20d8, unk20dc;
    unsigned int unk20e0, unk20e4, unk20e8, unk20ec, unk20f0, unk20f4, unk20f8, unk20fc;
    unsigned int unk2100;
    SearchState();
    ~SearchState();
    bool FUN_005d0e90(PathingRequest* request, MeshTriangle& start, MeshTriangle& goal, MeshRoute& route, TransitionRoute& transitions);
};
struct PathingSolution {
    int unk00, unk04, unk08, unk0c;
    unsigned int count;
    int unk14;
    unsigned int beginIndex, endIndex;
    void FUN_005ec000(const Vec3& point, NavMeshInfo* info);
    unsigned int GetCount() const { return count; }
};
struct DetailedBuilder {
    unsigned int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    unsigned int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    unsigned int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    unsigned int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    unsigned int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    unsigned int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4;
    DetailedBuilder();
    ~DetailedBuilder();
    void FUN_0060ebd0(PathingRequest* request, MeshRoute& route, TransitionRoute& transitions, const Vec3& start, const Vec3& end, PathingSolution* solution, unsigned int flags, bool smooth);
};

// pdb: Pathing::BuildPathToSafeStraightLine | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRequest, apSolution
bool __cdecl FUN_005f4990(PathingRequest* request, PathingSolution* result)
{
    AllocTagScope scope;
    if (!request->GetStart()->FUN_005fcc10())
        return false;
    NiPointer<NavMesh> startMesh;
    unsigned short startTriangle = 0xffff;
    if (!request->GetStart()->FUN_005fc8f0(startMesh, startTriangle))
        return false;
    MeshTriangle s;
    s.mesh = startMesh;
    s.triangle = startTriangle;
    Vec3 p = request->GetStart()->GetLocation();
    if (!request->GetGoal()->FUN_005fcc10())
        return false;
    NiPointer<NavMesh> goalMesh;
    unsigned short goalTriangle = 0xffff;
    if (!request->GetGoal()->FUN_005fc8f0(goalMesh, goalTriangle))
        return false;
    MeshTriangle b;
    b.mesh = goalMesh;
    b.triangle = goalTriangle;
    SearchState search;
    MeshRoute route(32, 0, 0);
    TransitionRoute transitions(32, 0, 0);
    if (!search.FUN_005d0e90(request, s, b, route, transitions))
        return false;
    RouteRecord h = route.GetAt(route.GetSize() - 1);
    Vec3 e = h.mesh->FUN_004d45e0(h.triangle);
    result->FUN_005ec000(p, s.mesh->FUN_005b84c0());
    result->FUN_005ec000(e, h.mesh->FUN_005b84c0());
    result->beginIndex = 0;
    result->endIndex = 1;
    DetailedBuilder builder;
    SmoothRoute smooth(32, 0, 0);
    builder.FUN_0060ebd0(request, route, transitions, p, e, result, 0, true);
    result->beginIndex = 0;
    result->endIndex = result->GetCount() - 1;
    return true;
}
}
}   // namespace f3m_005f4990

// @f3 0x005fe990 (community match, verified in this file)
namespace f3m_005fe990 {
namespace n5fe990 {
struct Counter {
    virtual void v0();
    virtual void DeleteThis();
    long refs;
    void Release()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct Indices {
    int unk00;
    unsigned short* index;
    unsigned int count;
};
struct Resource {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    Counter counter;
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
    Indices* FUN_005b84f0(int key);
};
__declspec(noalias) void FUN_005b87d0(NiPointer<Resource>* out, void* source);
struct Source {
    int unk00;
    int unk04;
    unsigned int flags;
    int pad[0x12];
    void* unk54;
};
struct Lookup {
    unsigned char* FUN_005ffe10(int key);
};
struct ByteArray {
    virtual void v0();
    virtual void v4();
    virtual void Free(void* p);
    char* data;
    unsigned int count;
    unsigned int capacity;
    void FUN_005fe850(unsigned int count, int keep);
    void Reset()
    {
        if (data)
            count = 0;
    }
    void Clear()
    {
        if (data)
        {
            Free(data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
};
struct Owner {
    unsigned char valid;
    ByteArray array;
    Source* source;
    int key;
    bool Load(NiPointer<Resource>* out)
    {
        if ((char)(source->flags >> 4) & 1)
            return false;
        FUN_005b87d0(out, source->unk54);
        bool ok = out->m_pObject != 0;
        return ok;
    }
    bool FUN_005fe990(Lookup** lookup);
};
}
// pdb: PathingLOSGridCell::SetSeenTrianglesFromLOSMap | PathingLOSGridMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: aspLOSMap
bool n5fe990::Owner::FUN_005fe990(Lookup** lookup)
{
    int k = source->unk00;
    unsigned char* table = (*lookup)->FUN_005ffe10(k);
    if (!table)
        return false;
    NiPointer<Resource> resource;
    if (!Load(&resource))
        return false;
    Indices* indices = resource->FUN_005b84f0(key);
    if (!indices)
        return false;
    array.Reset();
    unsigned int n = indices->count;
    array.FUN_005fe850(n, 1);
    valid = 1;
    for (unsigned int i = 0; i < indices->count; i++)
    {
        array.data[i] = table[indices->index[i]];
        char c = array.data[i];
        if (c <= 0 || c == 0x7f)
            valid = 0;
    }
    if (valid)
    {
        array.Clear();
    }
    return true;
}
}   // namespace f3m_005fe990

// @f3 0x005e2110 (community match, verified in this file)
namespace f3m_005e2a10 {
extern unsigned int DAT_00e27ed4;

bool __cdecl FUN_005dd580(const NiPoint3& ar_P1, const NiPoint3& ar_P2, const NiPoint3& ar_P3, const NiPoint3& ar_P4, NiPoint3* ap_Result);

struct ScrapHeap2110 {
    void* ScrapHeap_Allocate(unsigned int a_uiSize, unsigned int a_uiAlign);
};

struct RefObject2110 {
    void FUN_00401e70();
};

struct RefPtr2110 {
    RefObject2110* m_pObject;
    RefObject2110* Get() { return m_pObject; }
    void FUN_008e9600(const RefPtr2110& a_rOther);
};

struct EdgeData2110 {
    int i00;
    unsigned short us04;
    int i08;
    void CopyFromNavMeshEdge(const EdgeData2110& a_rOther) {
        i00 = a_rOther.i00;
        us04 = a_rOther.us04;
        i08 = a_rOther.i08;
    }
};

struct Edge2110 {
    NavMeshObstacleVertex* pStart;
    NavMeshObstacleVertex* pEnd;
    unsigned short us08;
    unsigned short us0a;
    unsigned short us0c;
    unsigned short us0e;
    int iType;
    unsigned short us14;
    unsigned short usFlags;
    bool bStartFlag;
    bool bEndFlag;
    RefPtr2110 spReference;
    EdgeData2110 kData;
    unsigned short usTag;
    bool bSplit;

    void FUN_005df350(NavMeshObstacleVertex* a_pStart, NavMeshObstacleVertex* a_pEnd, int a_iType);
};

struct EdgeArray2110 : public ScrapArray<NavMeshObstacleEdge*> {
    unsigned int FUN_005e5350();
    void FUN_005e4fb0(unsigned int a_uiIndex, bool a_bShrink);
    Edge2110*& GetEdge(unsigned int a_uiIndex) { return (Edge2110*&)pBuffer[a_uiIndex]; }
    void Add(Edge2110* const& a_pEdge) { pBuffer[FUN_005e5350()] = (NavMeshObstacleEdge*)a_pEdge; }
};

struct VertexArray2110 : public ScrapArray<NavMeshObstacleVertex*> {
    void FUN_005d4860(NavMeshObstacleVertex* const& a_pVertex);
};

struct Mesh2110 : public NavMesh {
    unsigned short FUN_005ba320(NavMeshVertex& a_rVertex);
};

struct Cutter2110 {
    NavMesh* pNavMesh;
    int unk04;
    int unk08;
    ScrapHeap2110 kHeap;
    NavMeshObstacleVertex* FUN_005dfdc0(unsigned short a_usIndex, bool a_b1, bool a_b2, bool a_b3);
    Edge2110* FUN_005df800(NavMeshObstacleVertex* a_pStart, NavMeshObstacleVertex* a_pEnd, int a_iType);
    Edge2110* CreateEdge(NavMeshObstacleVertex* a_pStart, NavMeshObstacleVertex* a_pEnd, int a_iType) {
        Edge2110* pNew = (Edge2110*)kHeap.ScrapHeap_Allocate(0x30, DAT_00e27ed4);
        if (pNew)
            pNew->FUN_005df350(a_pStart, a_pEnd, a_iType);
        return pNew;
    }
};

inline NiPoint3 Sub2110(const NiPoint3& a, const NiPoint3& b) {
    return NiPoint3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline float GetSquaredXYLength2110(const NiPoint3& a) {
    return a.x * a.x + a.y * a.y;
}

// pdb: NavMeshObstacleCutter::SplitEdges | NavMeshObstacleCutter.obj | fnv360_0721_beta, objrun, medium
void NavMeshObstacleCutter::FUN_005e2110() {


    for (unsigned int i = 0; i < Edges.GetSize(); ++i) {
        Edge2110* pFirst = ((EdgeArray2110*)&Edges)->GetEdge(i);
        if (pFirst->iType != 1)
            continue;
        NavMeshObstacleVertex* pA = pFirst->pStart;
        NavMeshObstacleVertex* pB = pFirst->pEnd;
        NiPoint3* pPosA = &pNavMesh->GetVertex(pA->usVertexIndex)->Location;
        NiPoint3* pPosB = &pNavMesh->GetVertex(pB->usVertexIndex)->Location;
        for (unsigned int j = 0; j < Edges.GetSize(); ++j) {
            Edge2110* pSecond = ((EdgeArray2110*)&Edges)->GetEdge(j);
            if (pSecond->iType != 3 && pSecond->iType != 4)
                continue;
            NavMeshObstacleVertex* pC = pSecond->pStart;
            NavMeshObstacleVertex* pD = pSecond->pEnd;
            NiPoint3* pPosC = &pNavMesh->GetVertex(pC->usVertexIndex)->Location;
            NiPoint3* pPosD = &pNavMesh->GetVertex(pD->usVertexIndex)->Location;
            if (pC == pA || pD == pA || pC == pB || pD == pB)
                continue;
            NiPoint3 kCrossing;
            if (FUN_005dd580(*pPosC, *pPosD, *pPosA, *pPosB, &kCrossing)) {
                double fTolerance = 0.0001f;
                bool bSplitFirst = false;
                bool bSplitSecond = false;
                NavMeshObstacleVertex* pIntersection;
                if (GetSquaredXYLength2110(Sub2110(*pPosC, kCrossing)) < fTolerance) {
                    pIntersection = pC;
                    bSplitFirst = true;
                    bSplitSecond = false;
                } else if (GetSquaredXYLength2110(Sub2110(*pPosD, kCrossing)) < fTolerance) {
                    pIntersection = pD;
                    bSplitFirst = true;
                    bSplitSecond = false;
                } else if (GetSquaredXYLength2110(Sub2110(*pPosA, kCrossing)) < fTolerance) {
                    pIntersection = pA;
                    bSplitFirst = false;
                    bSplitSecond = true;
                } else if (GetSquaredXYLength2110(Sub2110(*pPosB, kCrossing)) < fTolerance) {
                    pIntersection = pB;
                    bSplitFirst = false;
                    bSplitSecond = true;
                } else {
                    NavMeshVertex kVertex;
                    kVertex.Location = kCrossing;
                    unsigned short usIndex = ((Mesh2110*)pNavMesh)->FUN_005ba320(kVertex);
                    pIntersection = ((Cutter2110*)this)->FUN_005dfdc0(usIndex, true, false, true);
                    {
                        NavMeshObstacleVertex* pNewVertex = pIntersection;
                        ((VertexArray2110*)&Vertices)->FUN_005d4860(pNewVertex);
                    }
                    bSplitFirst = true;
                    bSplitSecond = true;
                }
                Edge2110* pFirstA = 0;
                Edge2110* pFirstB = 0;
                Edge2110* pSecondA = 0;
                Edge2110* pSecondB = 0;
                if (bSplitFirst) {
                    pFirstA = ((Cutter2110*)this)->CreateEdge(pA, pIntersection, 1);
                    pFirstB = ((Cutter2110*)this)->CreateEdge(pIntersection, pB, 1);
                    pFirstA->bSplit = true;
                    pFirstB->bSplit = true;
                    pFirstA->usFlags = pFirst->usFlags;
                    pFirstB->usFlags = pFirst->usFlags;
                    if (pFirst->bStartFlag)
                        pFirstA->bStartFlag = true;
                    if (pFirst->bEndFlag)
                        pFirstB->bEndFlag = true;
                    pFirstA->spReference.FUN_008e9600(pFirst->spReference);
                    pFirstB->spReference.FUN_008e9600(pFirst->spReference);
                }
                if (bSplitSecond) {
                    pSecondA = ((Cutter2110*)this)->FUN_005df800(pC, pIntersection, pSecond->iType);
                    pSecondB = ((Cutter2110*)this)->FUN_005df800(pIntersection, pD, pSecond->iType);
                    pSecondA->bSplit = true;
                    pSecondA->kData.CopyFromNavMeshEdge(pSecond->kData);
                    pSecondA->usTag = pSecond->usTag;
                    pSecondB->bSplit = true;
                    pSecondB->kData.CopyFromNavMeshEdge(pSecond->kData);
                    pSecondB->usTag = pSecond->usTag;
                    pSecondA->usFlags = pSecond->usFlags;
                    pSecondB->usFlags = pSecond->usFlags;
                    if (pSecond->bStartFlag)
                        pSecondA->bStartFlag = true;
                    if (pSecond->bEndFlag)
                        pSecondB->bEndFlag = true;
                    pSecondA->spReference.FUN_008e9600(pSecond->spReference);
                    pSecondB->spReference.FUN_008e9600(pSecond->spReference);
                }
                if (bSplitFirst && bSplitSecond) {
                    if (i > j) {
                        if (((EdgeArray2110*)&Edges)->GetEdge(i)->spReference.Get())
                            ((EdgeArray2110*)&Edges)->GetEdge(i)->spReference.Get()->FUN_00401e70();
                        if (((EdgeArray2110*)&Edges)->GetEdge(j)->spReference.Get())
                            ((EdgeArray2110*)&Edges)->GetEdge(j)->spReference.Get()->FUN_00401e70();
                        ((EdgeArray2110*)&Edges)->FUN_005e4fb0(i, true);
                        ((EdgeArray2110*)&Edges)->FUN_005e4fb0(j, true);
                        i -= 2;
                    } else {
                        if (((EdgeArray2110*)&Edges)->GetEdge(i)->spReference.Get())
                            ((EdgeArray2110*)&Edges)->GetEdge(i)->spReference.Get()->FUN_00401e70();
                        if (((EdgeArray2110*)&Edges)->GetEdge(j)->spReference.Get())
                            ((EdgeArray2110*)&Edges)->GetEdge(j)->spReference.Get()->FUN_00401e70();
                        ((EdgeArray2110*)&Edges)->FUN_005e4fb0(j, true);
                        ((EdgeArray2110*)&Edges)->FUN_005e4fb0(i, true);
                        i -= 1;
                    }
                } else {
                    if (bSplitFirst) {
                        if (((EdgeArray2110*)&Edges)->GetEdge(i)->spReference.Get())
                            ((EdgeArray2110*)&Edges)->GetEdge(i)->spReference.Get()->FUN_00401e70();
                        ((EdgeArray2110*)&Edges)->FUN_005e4fb0(i, true);
                        i -= 1;
                    }
                    if (bSplitSecond) {
                        if (((EdgeArray2110*)&Edges)->GetEdge(j)->spReference.Get())
                            ((EdgeArray2110*)&Edges)->GetEdge(j)->spReference.Get()->FUN_00401e70();
                        ((EdgeArray2110*)&Edges)->FUN_005e4fb0(j, true);
                        if (i > j)
                            i -= 1;
                    }
                }
                if (bSplitFirst) {
                    ((EdgeArray2110*)&Edges)->Add(pFirstA);
                    ((EdgeArray2110*)&Edges)->Add(pFirstB);
                }
                if (bSplitSecond) {
                    ((EdgeArray2110*)&Edges)->Add(pSecondA);
                    ((EdgeArray2110*)&Edges)->Add(pSecondB);
                }
                break;
            }
        }
    }
}
}

// @f3 0x005ff1d0 (community match, verified in this file)
namespace n5ff1d0 {
struct Node { void* FUN_005b84c0(); unsigned int FUN_005b84e0(); };
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct List {
    virtual ~List() {}
    void* data;
    unsigned int size;
    unsigned int cap;
    List() : data(0), size(0), cap(0) {}
};
struct Elem {
    char f0;
    List list;
    void* val;
    unsigned int idx;
    Elem(void* v, unsigned int i) { f0 = 0; val = v; idx = i; }
    static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct Arr {
    virtual void v0(); virtual Elem** Allocate(unsigned int n);
    Elem** data;
    unsigned int size;
    unsigned int cap;
    Node* cached;
    void FUN_00799ae0(unsigned int capacity, unsigned int size);
    void SetCap(unsigned int n) {
        if (n != cap) {
            if (n < size) size = n;
            FUN_00799ae0(n, size);
            cap = n;
        }
    }
    void Add(Elem* e) {
        if (size == cap) {
            if (!cap) {
                data = Allocate(4);
                cap = 4;
            } else {
                unsigned int c = cap > 0x400 ? cap + 0x400 : cap * 2;
                FUN_00799ae0(c, size);
                cap = c;
            }
        }
        size++;
        data[size - 1] = e;
    }
    void FUN_005ff1d0(Node** src);
};
// pdb: PathingLOSGrid::Setup | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aspNavMesh
void Arr::FUN_005ff1d0(Node** src)
{
    unsigned int n = (*src)->FUN_005b84e0();
    if (cached && size == n)
        return;
    if (data)
        size = 0;
    SetCap(n);
    for (unsigned int i = 0; i < n; i++)
        Add(new Elem((*src)->FUN_005b84c0(), i));
    cached = (Node*)(*src)->FUN_005b84c0();
}
}

// @f3 0x005e0720 (community match, verified in this file)
namespace f3m_005e0720 {
namespace f3m_005e0720 {
using f3m_005e2a10::FUN_005e0390;
using f3m_005e2a10::VertexArray;
using f3m_005e2a10::TriangleArray;

struct NavMesh5e0720 : f3m_005e2a10::NavMesh {
    void FUN_005be830(unsigned short a_usFirst, unsigned short a_usLast);
};

__forceinline void Grow(VertexArray& a, unsigned int n, unsigned int m) { a.FUN_0079ecc0(n, m); }
__forceinline void Grow(TriangleArray& a, unsigned int n, unsigned int m) { a.FUN_005b8620(n, m); }

template <class A>
__forceinline void SetSize(A& a, unsigned int n)
{
    if (n == 0) {
        if (a.pBuffer) {
            a._Deallocate(a.pBuffer);
            a.pBuffer = 0;
            a.iReservedSize = 0;
            a.iSize = 0;
        }
    } else if (n > a.iReservedSize) {
        if (a.iReservedSize == 0)
            a.pBuffer = a._Allocate(n);
        else
            Grow(a, n, a.iSize);
        a.iReservedSize = n;
        a.iSize = n;
    } else if (n < a.iSize) {
        a.iSize = n;
        if (n <= (a.iReservedSize >> 2)) {
            Grow(a, n, n);
            a.iReservedSize = n;
        }
    } else {
        a.iSize = n;
    }
}

class Cutter5e0720 {
public:
    NavMesh5e0720* pNavMesh;
    int unk04;
    FUN_005e0390* pUndoData;
    bool FUN_005e0720(NavMesh5e0720* a_pNavMesh, FUN_005e0390* a_pUndoData);
};

// pdb: NavMeshObstacleCutter::ResetNavMeshFromObstacleUndoData | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
// pdb params: apNavMesh, apUndoData
bool Cutter5e0720::FUN_005e0720(NavMesh5e0720* a_pNavMesh, FUN_005e0390* a_pUndoData)
{
    pNavMesh = a_pNavMesh;
    pUndoData = a_pUndoData;
    if (a_pUndoData->iAddedTriangleCount != 0) {
        a_pNavMesh->FUN_005be830(
            (unsigned short)a_pUndoData->iFirstAddedTriangleIndex,
            (unsigned short)(a_pUndoData->iFirstAddedTriangleIndex + a_pUndoData->iAddedTriangleCount - 1));
    }
    SetSize(pNavMesh->Vertices, pUndoData->iFirstAddedVertexIndex);
    SetSize(pNavMesh->Triangles, pUndoData->iFirstAddedTriangleIndex);
    return true;
}
}
}   // namespace f3m_005e0720

// @f3 0x005f42a0 (community match, verified in this file)
namespace f3m_005f42a0 {
namespace f3m_005f42a0 {

struct Elem5f42a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    void FUN_00601fa0(const Elem5f42a0& other);
};

class Array5f42a0
{
public:
    virtual void Unk00();
    virtual void* Allocate(unsigned int capacity);
    virtual void Free(void* data);
    Elem5f42a0* data;
    unsigned int count;
    unsigned int capacity;
    void FUN_005f1350(Elem5f42a0* elements, unsigned int number);
    void FUN_005f13e0(Elem5f42a0* destination, Elem5f42a0* source, unsigned int number);
    unsigned int FUN_005f2550();
    void FUN_005f42a0(unsigned int index, const Elem5f42a0& item);
};

// pdb: BSSimpleArray<PathingCoverLocation,1024>::Insert | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiIndex, aValue
void Array5f42a0::FUN_005f42a0(unsigned int index, const Elem5f42a0& item)
{
    if (index == count)
    {
        unsigned int slot = FUN_005f2550();
        FUN_005f1350(&data[slot], 1);
        data[slot].FUN_00601fa0(item);
        return;
    }
    if (count == capacity)
    {
        unsigned int newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
        Elem5f42a0* newData = (Elem5f42a0*)Allocate(newCapacity);
        FUN_005f13e0(newData, data, index);
        Elem5f42a0* slot = &newData[index];
        FUN_005f1350(slot, 1);
        FUN_005f13e0(slot + 1, &data[index], count - index);
        Free(data);
        data = newData;
        capacity = newCapacity;
    }
    else
    {
        FUN_005f13e0(&data[index] + 1, &data[index], count - index);
        FUN_005f1350(&data[index], 1);
    }
    ++count;
    data[index].FUN_00601fa0(item);
}

}
}   // namespace f3m_005f42a0

// @f3 0x005fb8c0 (community match, verified in this file)
extern __declspec(thread) int DAT_0117c298;
namespace f3m_005fb8c0 {

namespace f3m_005fb8c0 {

struct MemoryContext5fb8c0
{
    int saved;
    MemoryContext5fb8c0() { saved = DAT_0117c298; DAT_0117c298 = 45; }
    ~MemoryContext5fb8c0() { DAT_0117c298 = saved; }
};

struct Object5fb8c0
{
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual unsigned int GetType();
};

bool __cdecl FUN_005f8210(Object5fb8c0* object, void* context);
bool __cdecl FUN_005fb040(Object5fb8c0* object, void* context);
bool __cdecl FUN_005f45c0(Object5fb8c0* object, void* context);
bool __cdecl FUN_005fb9e0(Object5fb8c0* object, void* context);
bool __cdecl FUN_005f4990(Object5fb8c0* object, void* context);
bool __cdecl FUN_005f8280(Object5fb8c0* object, void* context);
bool __cdecl FUN_005f89d0(Object5fb8c0* object, void* context);

// pdb: PathingSolution::PathingSolution | PathingSolution.obj | fnv360_0822_retail, call_dedup, low, conflict (bridge: Pathing::BuildPath)
bool __cdecl FUN_005fb8c0(Object5fb8c0* object, void* context)
{
    MemoryContext5fb8c0 memoryContext;
    switch (object->GetType())
    {
    case 0: return FUN_005f8210(object, context);
    case 3: return FUN_005fb040(object, context);
    case 4: return FUN_005f45c0(object, context);
    case 5: return FUN_005fb9e0(object, context);
    case 6: return FUN_005f4990(object, context);
    case 7: return FUN_005f8280(object, context);
    case 8: return FUN_005f89d0(object, context);
    }
    return false;
}

}
}   // namespace f3m_005fb8c0

// @f3 0x005e80b0 (community match, verified in this file)
namespace f3m_005e80b0 {
namespace n5e80b0 {
class RefObj {
public:
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};
template <class T> class Ptr {
public:
    T* m_pObject;
    Ptr() : m_pObject(0) {}
    Ptr(T* o) { m_pObject = o; if (m_pObject) m_pObject->IncRefCount(); }
    ~Ptr() { if (m_pObject) m_pObject->DecRefCount(); }
    T* operator->() const { return m_pObject; }
};
class Item : public RefObj {};
class Group : public RefObj {
public:
    int unk08, unk0C;
    Item** data;
    unsigned int count;
    Item*& GetAt(unsigned int i) { return data[i]; }
};
template <class T> class OwnedPtr {
public:
    T* m_pObject;
    OwnedPtr() : m_pObject(0) {}
    ~OwnedPtr() { m_pObject->DecRefCount(); }
    T* operator->() const { return m_pObject; }
};
struct MapItem;
class Map {
public:
    void** vtbl;
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    MapItem* GetFirstPos() const {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    __declspec(noalias) void FUN_00ad3cc0(MapItem*& pos, unsigned int& key, OwnedPtr<Group>& val);
};
class Owner5e80b0 {
public:
    char pad[0x1c];
    Map map;
    void FUN_005e77d0(Ptr<Item>& item);
    void FUN_005e80b0();
};
}
using n5e80b0::Owner5e80b0;

// pdb: NavMeshObstacleManager::ProcessAllObstacles | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
void Owner5e80b0::FUN_005e80b0()
{
    using namespace n5e80b0;
    MapItem* pos = map.GetFirstPos();
    while (pos) {
        unsigned int key;
        OwnedPtr<Group> val;
        map.FUN_00ad3cc0(pos, key, val);
        for (unsigned int i = 0; i < val->count; i++) {
            Ptr<Item> item(val->GetAt(i));
            FUN_005e77d0(item);
        }
    }
}
}   // namespace f3m_005e80b0

// @f3 0x005e0bc0 (community match, verified in this file)
namespace f3m_005e2a10 {
namespace n5e0bc0 {
__forceinline bool IsCandidate(EdgeInit5e0a* a_pEdge)
{
    if (a_pEdge->us08 == 0xFFFF)
        return true;
    if (a_pEdge->us0a != 0xFFFF)
        return false;
    if (a_pEdge->i10 == 1 || a_pEdge->i10 == 3 || a_pEdge->i10 == 4)
        return false;
    return true;
}
}

// pdb: NavMeshObstacleCutter::CreateRemainingEdges | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
void NavMeshObstacleCutter::FUN_005e0bc0()
{
    for (unsigned int i = 0; i < Edges.GetSize(); i++) {
        EdgeInit5e0a* pFirst = (EdgeInit5e0a*)Edges[i];
        if (!n5e0bc0::IsCandidate(pFirst))
            continue;
        for (unsigned int j = i + 1; j < Edges.GetSize(); j++) {
            EdgeInit5e0a* pSecond = (EdgeInit5e0a*)Edges[j];
            if (!n5e0bc0::IsCandidate(pSecond))
                continue;
            NavMeshObstacleVertex* pStart;
            NavMeshObstacleVertex* pEnd;
            if (pFirst->pStart == pSecond->pStart) {
                pStart = pFirst->pEnd;
                pEnd = pSecond->pEnd;
            } else if (pFirst->pStart == pSecond->pEnd) {
                pStart = pFirst->pEnd;
                pEnd = pSecond->pStart;
            } else if (pFirst->pEnd == pSecond->pStart) {
                pStart = pFirst->pStart;
                pEnd = pSecond->pEnd;
            } else if (pFirst->pEnd == pSecond->pEnd) {
                pStart = pFirst->pStart;
                pEnd = pSecond->pStart;
            } else
                continue;
            if (!((CutterHelper5e0a*)this)->FUN_005dfc00(pStart, pEnd))
                continue;
            EdgeInit5e0a* pEdge = (EdgeInit5e0a*)((ScrapHeap5e0a*)&unk0c)->ScrapHeap_Allocate(0x30, DAT_00e27ed4);
            if (pEdge)
                new (pEdge) EdgeInit5e0a(pStart, pEnd);
            ((EdgeArray5e0a*)&Edges)->Add((NavMeshObstacleEdge*)pEdge);
        }
    }
}
}

// @f3 0x005e2690 (community match, verified in this file)
namespace f3m_005e2a10 {
struct ObstacleIndexBuffer {
    virtual ~ObstacleIndexBuffer();
    virtual unsigned short* Allocate(unsigned int count);
    unsigned short* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_00548790(unsigned int capacity, unsigned int used);
    __forceinline void Append(const unsigned short& index)
    {
        const unsigned int oldSize = size;
        unsigned int oldCapacity = capacity;
        if (oldSize == oldCapacity) {
            if (oldCapacity == 0) {
                data = Allocate(4);
                capacity = 4;
            } else {
                unsigned int grown = oldCapacity + 1024;
                if (oldCapacity <= 1024)
                    grown = oldCapacity * 2;
                FUN_00548790(grown, oldSize);
                capacity = grown;
            }
        }
        ++size;
        data[size - 1] = index;
    }
};
struct NavMeshIndexView {
    NavMesh prefix;
    ObstacleIndexBuffer obstaclePOVs;
};
// pdb: NavMeshObstacleCutter::AddNewPOVs | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
void NavMeshObstacleCutter::FUN_005e2690()
{
    for (unsigned int i = 0; i < Vertices.iSize; ++i) {
        if (Vertices.pBuffer[i]->bOnObstacle) {
            NavMeshIndexView* mesh = reinterpret_cast<NavMeshIndexView*>(pNavMesh);
            mesh->obstaclePOVs.Append(Vertices.pBuffer[i]->usVertexIndex);
            reinterpret_cast<ObstacleIndexBuffer&>(pUndoData->AddedPOVs).Append(Vertices.pBuffer[i]->usVertexIndex);
        }
    }
}
}

// @f3 0x005f45c0 (community match, verified in this file)
// FUN_005f45c0 (0x005f45c0) - PathingRequest route builder (start only).
// Sibling of the matched FUN_005f4990; the same local set, but only the start
// location is resolved and the search is FUN_005cf370(request, start, route, transitions).
namespace f3m_005f45c0 {

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern __declspec(thread) int allocContext;

struct Heap { void* FUN_0086bcb0(); };
extern Heap DAT_01090a78;

struct AllocTagScope {
    int saved;
    AllocTagScope() : saved(allocContext) { allocContext = 45; }
    ~AllocTagScope() { allocContext = saved; }
};

struct Vec3 { float x, y, z; };
struct NavMeshInfo;

struct RefCounted {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(RefCounted*))vtable[1])(this);
    }
};

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounted ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    Vec3 FUN_004d45e0(unsigned short triangle) const;
    NavMeshInfo* FUN_005b84c0();
};

template <class T>
struct NiPointer {
    T* ptr;
    NiPointer() : ptr(0) {}
    ~NiPointer() { T* p = ptr; if (p) p->DecRefCount(); }
    operator T*() const { return ptr; }
};

struct PathingLocation {
    void* vtable;
    Vec3 location;
    NavMeshInfo* navMeshInfo;
    void* navMeshes;
    void* cell;
    void* worldSpace;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    bool FUN_005fda30(int flag);
    bool FUN_005fc8f0(NiPointer<NavMesh>& mesh, unsigned short& triangle);
    Vec3 GetLocation() const { return location; }
};

struct PathingRequest {
    int unk00, unk04, unk08;
    PathingLocation start;
    PathingLocation goal;
    PathingLocation* GetStart() { return &start; }
    PathingLocation* GetGoal() { return &goal; }
};

struct RouteRecord {
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    int unk08, unk0c, unk10;
};
typedef RouteRecord MeshTriangle;

struct PathingSolution {
    int unk00, unk04, unk08, unk0c;
    unsigned int count;
    int unk14;
    unsigned int beginIndex, endIndex;
    void FUN_005ec000(const Vec3& point, NavMeshInfo* info);
    unsigned int GetCount() const { return count; }
};

class Simple {
public:
    virtual ~Simple();
    virtual void* Allocate(unsigned int count);
    virtual void Free(void* p);
    void* data;
    unsigned int size, capacity;
    __forceinline Simple() : data(0), size(0), capacity(0) {}
};

class MeshRoute : public Simple {
public:
    void* allocator;
    virtual ~MeshRoute();
    __forceinline void Init(unsigned int initial, unsigned int cap) {
        data = 0; size = 0; capacity = 0;
        if (initial > cap) cap = initial;
        if (cap > 0) { data = Allocate(cap); capacity = cap; }
        if (initial > 0) size = initial;
    }
    __forceinline MeshRoute(unsigned int cap, unsigned int initial, void* alloc) : Simple() {
        if (!alloc) alloc = DAT_01090a78.FUN_0086bcb0();
        allocator = alloc;
        Init(initial, cap);
    }
    unsigned int GetSize() const { return size; }
    RouteRecord GetAt(unsigned int index) const { return ((RouteRecord*)data)[index]; }
};

class TransitionRoute : public Simple {
public:
    void* allocator;
    virtual ~TransitionRoute();
    __forceinline void Init(unsigned int initial, unsigned int cap) {
        data = 0; size = 0; capacity = 0;
        if (initial > cap) cap = initial;
        if (cap > 0) { data = Allocate(cap); capacity = cap; }
        if (initial > 0) size = initial;
    }
    __forceinline TransitionRoute(unsigned int cap, unsigned int initial, void* alloc) : Simple() {
        if (!alloc) alloc = DAT_01090a78.FUN_0086bcb0();
        allocator = alloc;
        Init(initial, cap);
    }
};

struct SmoothRoute {
    void* vtable;
    void* data;
    unsigned int size, capacity;
    void* allocator;
    SmoothRoute(unsigned int cap, unsigned int initial, void* alloc);
    ~SmoothRoute();
};

struct DetailedBuilder {
    unsigned unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    unsigned unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    unsigned unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    unsigned unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    unsigned unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    unsigned unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4;
    DetailedBuilder();
    ~DetailedBuilder();
    void FUN_0060ebd0(PathingRequest* request, MeshRoute& route, TransitionRoute& transitions,
                      const Vec3& start, const Vec3& end, PathingSolution* solution,
                      unsigned int flags, bool smooth);
};

struct SearchState {
    unsigned unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    unsigned unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    unsigned unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    unsigned unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    unsigned unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    unsigned unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    unsigned unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    unsigned unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    unsigned unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    unsigned unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    unsigned unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    unsigned unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    unsigned unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    unsigned unk01a0, unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc;
    unsigned unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    unsigned unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc;
    unsigned unk0200, unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c;
    unsigned unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    unsigned unk0240, unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c;
    unsigned unk0260, unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c;
    unsigned unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    unsigned unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc;
    unsigned unk02c0, unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc;
    unsigned unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    unsigned unk0300, unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c;
    unsigned unk0320, unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c;
    unsigned unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    unsigned unk0360, unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c;
    unsigned unk0380, unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c;
    unsigned unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    unsigned unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc;
    unsigned unk03e0, unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc;
    unsigned unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    unsigned unk0420, unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c;
    unsigned unk0440, unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c;
    unsigned unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    unsigned unk0480, unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c;
    unsigned unk04a0, unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc;
    unsigned unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    unsigned unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc;
    unsigned unk0500, unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c;
    unsigned unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    unsigned unk0540, unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c;
    unsigned unk0560, unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c;
    unsigned unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    unsigned unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc;
    unsigned unk05c0, unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc;
    unsigned unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    unsigned unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    unsigned unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    unsigned unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    unsigned unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    unsigned unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    unsigned unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    unsigned unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    unsigned unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    unsigned unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    unsigned unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    unsigned unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    unsigned unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    unsigned unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    unsigned unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    unsigned unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    unsigned unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    unsigned unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    unsigned unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    unsigned unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    unsigned unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    unsigned unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    unsigned unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    unsigned unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    unsigned unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    unsigned unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    unsigned unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    unsigned unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    unsigned unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    unsigned unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    unsigned unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    unsigned unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc;
    unsigned unk09e0, unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc;
    unsigned unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    unsigned unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c;
    unsigned unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c;
    unsigned unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    unsigned unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c;
    unsigned unk0aa0, unk0aa4, unk0aa8, unk0aac, unk0ab0, unk0ab4, unk0ab8, unk0abc;
    unsigned unk0ac0, unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc;
    unsigned unk0ae0, unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc;
    unsigned unk0b00, unk0b04, unk0b08, unk0b0c, unk0b10, unk0b14, unk0b18, unk0b1c;
    unsigned unk0b20, unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c;
    unsigned unk0b40, unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c;
    unsigned unk0b60, unk0b64, unk0b68, unk0b6c, unk0b70, unk0b74, unk0b78, unk0b7c;
    unsigned unk0b80, unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c;
    unsigned unk0ba0, unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc;
    unsigned unk0bc0, unk0bc4, unk0bc8, unk0bcc, unk0bd0, unk0bd4, unk0bd8, unk0bdc;
    unsigned unk0be0, unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    unsigned unk0c00, unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c;
    unsigned unk0c20, unk0c24, unk0c28, unk0c2c, unk0c30, unk0c34, unk0c38, unk0c3c;
    unsigned unk0c40, unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c;
    unsigned unk0c60, unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c;
    unsigned unk0c80, unk0c84, unk0c88, unk0c8c, unk0c90, unk0c94, unk0c98, unk0c9c;
    unsigned unk0ca0, unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    unsigned unk0cc0, unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc;
    unsigned unk0ce0, unk0ce4, unk0ce8, unk0cec, unk0cf0, unk0cf4, unk0cf8, unk0cfc;
    unsigned unk0d00, unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c;
    unsigned unk0d20, unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c;
    unsigned unk0d40, unk0d44, unk0d48, unk0d4c, unk0d50, unk0d54, unk0d58, unk0d5c;
    unsigned unk0d60, unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c;
    unsigned unk0d80, unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c;
    unsigned unk0da0, unk0da4, unk0da8, unk0dac, unk0db0, unk0db4, unk0db8, unk0dbc;
    unsigned unk0dc0, unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    unsigned unk0de0, unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc;
    unsigned unk0e00, unk0e04, unk0e08, unk0e0c, unk0e10, unk0e14, unk0e18, unk0e1c;
    unsigned unk0e20, unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c;
    unsigned unk0e40, unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c;
    unsigned unk0e60, unk0e64, unk0e68, unk0e6c, unk0e70, unk0e74, unk0e78, unk0e7c;
    unsigned unk0e80, unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c;
    unsigned unk0ea0, unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc;
    unsigned unk0ec0, unk0ec4, unk0ec8, unk0ecc, unk0ed0, unk0ed4, unk0ed8, unk0edc;
    unsigned unk0ee0, unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc;
    unsigned unk0f00, unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c;
    unsigned unk0f20, unk0f24, unk0f28, unk0f2c, unk0f30, unk0f34, unk0f38, unk0f3c;
    unsigned unk0f40, unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c;
    unsigned unk0f60, unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c;
    unsigned unk0f80, unk0f84, unk0f88, unk0f8c, unk0f90, unk0f94, unk0f98, unk0f9c;
    unsigned unk0fa0, unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    unsigned unk0fc0, unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc;
    unsigned unk0fe0, unk0fe4, unk0fe8, unk0fec, unk0ff0, unk0ff4, unk0ff8, unk0ffc;
    unsigned unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    unsigned unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    unsigned unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    unsigned unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    unsigned unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    unsigned unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    unsigned unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    unsigned unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    unsigned unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c;
    unsigned unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    unsigned unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c;
    unsigned unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    unsigned unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    unsigned unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    unsigned unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc;
    unsigned unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    unsigned unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c;
    unsigned unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    unsigned unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    unsigned unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    unsigned unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c;
    unsigned unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    unsigned unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc;
    unsigned unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    unsigned unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    unsigned unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    unsigned unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c;
    unsigned unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    unsigned unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c;
    unsigned unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    unsigned unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    unsigned unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    unsigned unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c;
    unsigned unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    unsigned unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c;
    unsigned unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    unsigned unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    unsigned unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    unsigned unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc;
    unsigned unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    unsigned unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c;
    unsigned unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    unsigned unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    unsigned unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    unsigned unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c;
    unsigned unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    unsigned unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc;
    unsigned unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    unsigned unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    unsigned unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    unsigned unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c;
    unsigned unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    unsigned unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c;
    unsigned unk16a0, unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc;
    unsigned unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc;
    unsigned unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc;
    unsigned unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c;
    unsigned unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    unsigned unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c;
    unsigned unk1760, unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c;
    unsigned unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c;
    unsigned unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc;
    unsigned unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc;
    unsigned unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    unsigned unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c;
    unsigned unk1820, unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c;
    unsigned unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c;
    unsigned unk1860, unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c;
    unsigned unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c;
    unsigned unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    unsigned unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc;
    unsigned unk18e0, unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc;
    unsigned unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c;
    unsigned unk1920, unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c;
    unsigned unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c;
    unsigned unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    unsigned unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c;
    unsigned unk19a0, unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc;
    unsigned unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc;
    unsigned unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc;
    unsigned unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c;
    unsigned unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    unsigned unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c;
    unsigned unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c;
    unsigned unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c;
    unsigned unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc;
    unsigned unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc;
    unsigned unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    unsigned unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c;
    unsigned unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c;
    unsigned unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c;
    unsigned unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c;
    unsigned unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c;
    unsigned unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    unsigned unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    unsigned unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    unsigned unk1c00, unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c;
    unsigned unk1c20, unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34, unk1c38, unk1c3c;
    unsigned unk1c40, unk1c44, unk1c48, unk1c4c, unk1c50, unk1c54, unk1c58, unk1c5c;
    unsigned unk1c60, unk1c64, unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c;
    unsigned unk1c80, unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c;
    unsigned unk1ca0, unk1ca4, unk1ca8, unk1cac, unk1cb0, unk1cb4, unk1cb8, unk1cbc;
    unsigned unk1cc0, unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc;
    unsigned unk1ce0, unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4, unk1cf8, unk1cfc;
    unsigned unk1d00, unk1d04, unk1d08, unk1d0c, unk1d10, unk1d14, unk1d18, unk1d1c;
    unsigned unk1d20, unk1d24, unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c;
    unsigned unk1d40, unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c;
    unsigned unk1d60, unk1d64, unk1d68, unk1d6c, unk1d70, unk1d74, unk1d78, unk1d7c;
    unsigned unk1d80, unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c;
    unsigned unk1da0, unk1da4, unk1da8, unk1dac, unk1db0, unk1db4, unk1db8, unk1dbc;
    unsigned unk1dc0, unk1dc4, unk1dc8, unk1dcc, unk1dd0, unk1dd4, unk1dd8, unk1ddc;
    unsigned unk1de0, unk1de4, unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc;
    unsigned unk1e00, unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c;
    unsigned unk1e20, unk1e24, unk1e28, unk1e2c, unk1e30, unk1e34, unk1e38, unk1e3c;
    unsigned unk1e40, unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c;
    unsigned unk1e60, unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74, unk1e78, unk1e7c;
    unsigned unk1e80, unk1e84, unk1e88, unk1e8c, unk1e90, unk1e94, unk1e98, unk1e9c;
    unsigned unk1ea0, unk1ea4, unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    unsigned unk1ec0, unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc;
    unsigned unk1ee0, unk1ee4, unk1ee8, unk1eec, unk1ef0, unk1ef4, unk1ef8, unk1efc;
    unsigned unk1f00, unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c;
    unsigned unk1f20, unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34, unk1f38, unk1f3c;
    unsigned unk1f40, unk1f44, unk1f48, unk1f4c, unk1f50, unk1f54, unk1f58, unk1f5c;
    unsigned unk1f60, unk1f64, unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c;
    unsigned unk1f80, unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c;
    unsigned unk1fa0, unk1fa4, unk1fa8, unk1fac, unk1fb0, unk1fb4, unk1fb8, unk1fbc;
    unsigned unk1fc0, unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc;
    unsigned unk1fe0, unk1fe4, unk1fe8, unk1fec, unk1ff0, unk1ff4, unk1ff8, unk1ffc;
    unsigned unk2000, unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c;
    unsigned unk2020, unk2024, unk2028, unk202c, unk2030, unk2034, unk2038, unk203c;
    unsigned unk2040, unk2044, unk2048, unk204c, unk2050, unk2054, unk2058, unk205c;
    unsigned unk2060, unk2064, unk2068, unk206c, unk2070, unk2074, unk2078, unk207c;
    unsigned unk2080, unk2084, unk2088, unk208c, unk2090, unk2094, unk2098, unk209c;
    unsigned unk20a0, unk20a4, unk20a8, unk20ac, unk20b0, unk20b4, unk20b8, unk20bc;
    unsigned unk20c0, unk20c4, unk20c8, unk20cc, unk20d0, unk20d4;
    SearchState();
    ~SearchState();
    bool FUN_005cf370(PathingRequest* request, MeshTriangle& start, MeshRoute& route,
                      TransitionRoute& transitions);
};

// pdb: Pathing::BuildHidePath | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRequest, apSolution
bool __cdecl FUN_005f45c0(PathingRequest* request, PathingSolution* result)
{
    AllocTagScope scope;
    if (!request->GetStart()->FUN_005fda30(0))
        return false;
    NiPointer<NavMesh> startMesh;
    unsigned short startTriangle = 0xffff;
    if (!request->GetStart()->FUN_005fc8f0(startMesh, startTriangle))
        return false;
    MeshTriangle s;
    s.mesh = startMesh;
    s.triangle = startTriangle;
    Vec3 p = request->GetStart()->GetLocation();
    SearchState search;
    MeshRoute route(32, 0, 0);
    TransitionRoute transitions(32, 0, 0);
    if (!search.FUN_005cf370(request, s, route, transitions))
        return false;
    RouteRecord h = route.GetAt(route.GetSize() - 1);
    Vec3 e = h.mesh->FUN_004d45e0(h.triangle);
    result->FUN_005ec000(p, s.mesh->FUN_005b84c0());
    result->FUN_005ec000(e, h.mesh->FUN_005b84c0());
    result->beginIndex = 0;
    result->endIndex = 1;
    DetailedBuilder builder;
    SmoothRoute smooth(32, 0, 0);
    builder.FUN_0060ebd0(request, route, transitions, p, e, result, 0, true);
    result->beginIndex = 0;
    result->endIndex = result->GetCount() - 1;
    return true;
}

}

// @f3 0x005fd1e0 (community match, verified in this file)
namespace f3m_005fd1e0 {
namespace q173 {
struct QForm {
  virtual void v00();
  virtual void v01();
  virtual void v02();
  virtual void v03();
  virtual void v04();
  virtual void v05();
  virtual void v06();
  virtual void v07();
  virtual void v08();
  virtual void v09();
  virtual void v0a();
  virtual void v0b();
  virtual void v0c();
  virtual void v0d();
  virtual void v0e();
  virtual void v0f();
  virtual void v10();
  virtual void v11();
  virtual void v12();
  virtual void v13();
  virtual void v14();
  virtual void v15();
  virtual void v16();
  virtual void v17();
  virtual void v18();
  virtual void v19();
  virtual void v1a();
  virtual void v1b();
  virtual void v1c();
  virtual void v1d();
  virtual void v1e();
  virtual void v1f();
  virtual void v20();
  virtual void v21();
  virtual void v22();
  virtual void v23();
  virtual void v24();
  virtual void v25();
  virtual void v26();
  virtual void v27();
  virtual void v28();
  virtual void v29();
  virtual void v2a();
  virtual void v2b();
  virtual void v2c();
  virtual void v2d();
  virtual void v2e();
  virtual void v2f();
  virtual void v30();
  virtual void v31();
  virtual void v32();
  virtual void v33();
  virtual void v34();
  virtual void v35();
  virtual void v36();
  virtual void v37();
  virtual void v38();
  virtual void v39();
  virtual void v3a();
  virtual void v3b();
  virtual void v3c();
  virtual void v3d();
  virtual void v3e();
  virtual void v3f();
  virtual void v40();
  virtual void v41();
  virtual void v42();
  virtual void v43();
  virtual void v44();
  virtual void v45();
  virtual void v46();
  virtual void v47();
  virtual void v48();
  virtual void v49();
  virtual void v4a();
  virtual void v4b();
  virtual const char* GetName();
};
struct QWorld : QForm {
  QForm* FUN_005048f0(void* pos);
};
struct QTri { int unk00; int unk04; int unk08; };
struct QPos { float x; float y; float z; };
}

int sprintf_s(char* dst, unsigned int size, const char* fmt, ...);

struct QPick {
  int unk00;
  q173::QPos pos;
  void* unk10;
  q173::QTri* unk14;
  q173::QForm* unk18;
  q173::QWorld* unk1c;
  int unk20;
  unsigned short unk24;
  void FUN_005fd1e0(char* out, unsigned int size);
};

// pdb: PathingLocation::PrintDebugText | PathingLocation.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: BSPathingLocation::PrintDebugText)
// pdb params: apBuffer, aiMaxSize
void QPick::FUN_005fd1e0(char* out, unsigned int size)
{
  char buf[256];
  if (unk10 && (!unk14 || unk14->unk08)) {
    if (unk24 != 0xffff)
      sprintf_s(out, size, "%s, Tri %d, %.2f %.2f %.2f", buf, unk24, pos.x, pos.y, pos.z);
    else
      sprintf_s(out, size, "%s, %.2f %.2f %.2f", buf, pos.x, pos.y, pos.z);
  } else if (!unk1c) {
    sprintf_s(out, size, "Cell %s, %.2f %.2f %.2f", unk18 ? unk18->GetName() : "NONE", pos.x, pos.y, pos.z);
  } else {
    int cx = (int)pos.x >> 12;
    int cy = (int)pos.y >> 12;
    q173::QForm* cell = unk1c->FUN_005048f0(&pos);
    if (cell) {
      q173::QWorld* ws = unk1c;
      sprintf_s(out, size, "Cell %s[%d,%d] %s,  %.2f %.2f %.2f", ws->GetName(), cx, cy, cell->GetName(), pos.x, pos.y, pos.z);
    } else
      sprintf_s(out, size, "Cell %s[%d,%d], %.2f %.2f %.2f", unk1c->GetName(), cx, cy, pos.x, pos.y, pos.z);
  }
}
}   // namespace f3m_005fd1e0

// @f3 0x005faa80 (community match, verified in this file)
extern int DAT_00dc4dc0;
namespace f3m_005faa80 {
// FO3 pathfinding self-test bench (FNV twin fnv_006da7c0::FUN_006da7c0, pathfind.cpp):
// sample `count` points in the cell, then run one of three pathing queries on each.

struct FUN_00aa5140
{
    static FUN_00aa5140& Get();
    int FUN_00aa5230(int);
};

namespace n5faa80 {

struct NiPoint3
{
    float x, y, z;
};

struct BSRefObject
{
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            ((void(__thiscall*)(BSRefObject*))vtable[1])(this);
    }
};

struct NavMesh
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BSRefObject ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
};

struct NavMeshInfo;

struct CellOps
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned char cCellFlags;
    bool IsInterior() { return cCellFlags & 1; }
    int TESObjectCELL_GetDataX();
    int TESObjectCELL_GetDataY();
};


struct BenchLocation
{
    void* m_vtable;
    NiPoint3 Location;
    NavMeshInfo* pNavMeshInfo;
    void* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;

    BenchLocation(const NiPoint3& ar_Location, CellOps* ap_Cell);
    BenchLocation(const NiPoint3& ar_Location, NavMeshInfo* ap_NavMeshInfo);
    ~BenchLocation() { m_vtable = &DAT_00dc4dc0; }
    bool FUN_005fda30(int);
    void FUN_005fc8b0(NiPointer<NavMesh>& ar_spNavMesh);
    NavMeshInfo* FUN_004c0120();
    BenchLocation& FUN_005fc480(const BenchLocation& ar_Other);
};

struct PointArrayBench
{
    NiPoint3* data;
    unsigned int size;
    unsigned int capacity;
    PointArrayBench(unsigned int n) : data(0), size(0), capacity(0) { InitialSize(n); }
    void InitialSize(unsigned int n)
    {
        if (n > 0)
        {
            data = Allocate(n);
            capacity = n;
            size = n;
        }
    }
    virtual ~PointArrayBench() { Clear(); }
    virtual NiPoint3* Allocate(unsigned int n);
    virtual void Free(NiPoint3* p);
    void Clear()
    {
        if (data)
        {
            Free(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    NiPoint3& GetAt(unsigned int i) { return data[i]; }
};

struct Point2Bench
{
    float x, y;
    Point2Bench() {}
    Point2Bench(float ax, float ay) : x(ax), y(ay) {}
};

struct CloseResult
{
    BenchLocation location;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
};

struct RequestBench
{
    void* vtable;
    long refs;
    int unk08;
    BenchLocation start;
    BenchLocation goal;
    int unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94;
    int unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    RequestBench();
    ~RequestBench();
    void AssignPathingLocation(const BenchLocation& loc) { start.FUN_005fc480(loc); }
    void SetGoal(const BenchLocation& loc) { goal.FUN_005fc480(loc); }
};

struct CloseRequestBench : RequestBench
{
    NiPoint3 kTarget;
    int unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    CloseRequestBench();
    ~CloseRequestBench();
    void SetTarget(const NiPoint3& pt) { kTarget = pt; }
};

struct CloseSolutionBench
{
    CloseResult* data;
    unsigned int size;
    unsigned int capacity;
    CloseSolutionBench() : data(0), size(0), capacity(0) {}
    virtual ~CloseSolutionBench() { Clear(); }
    virtual CloseResult* Allocate(unsigned int n);
    virtual void Free(CloseResult* p);
    static void ReleaseElements(CloseResult* items, unsigned int n)
    {
        for (unsigned int i = 0; i < n; i++)
            items[i].~CloseResult();
    }
    void Clear()
    {
        if (data)
        {
            ReleaseElements(data, size);
            Free(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
};

struct SolutionBench
{
    void* vtable;
    long refs;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    SolutionBench();
    ~SolutionBench();
};

inline float RandomFloat(float lo, float hi)
{
    FUN_00aa5140& generator = FUN_00aa5140::Get();
    unsigned int r = generator.FUN_00aa5230(-1);
    return lo + (hi - lo) * r * 2.3283064365386963e-10;
}

bool __cdecl FUN_005f16b0(NavMeshInfo*, int, const NiPoint3&, float, NiPoint3&);
bool __cdecl FUN_005dd320(const Point2Bench&, const Point2Bench&, const Point2Bench&, const Point2Bench&, Point2Bench&);
bool __cdecl FUN_005dd4c0(const Point2Bench&, const Point2Bench&, const Point2Bench&, const Point2Bench&);
bool __cdecl FUN_005f9e70(CloseRequestBench*, CloseSolutionBench*);
bool __cdecl FUN_005f8210(RequestBench*, SolutionBench*);

}  // namespace n5faa80

using namespace n5faa80;

// pdb: Pathing::ProfilePathing | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCell, aLoc, aiTestType, aiNum
float __cdecl FUN_005faa80(CellOps* cell, const n5faa80::NiPoint3& pos, int mode, unsigned int count)
{
    float eType;
    int kPosition;
    NiPointer<NavMesh> m_fGridOriginX;
    float kRange = 500.0f;
    kPosition = mode;
    bool bInterior = cell->IsInterior();
    float kPoints, kNavMesh, kTargetPoint;
    if (bInterior)
    {
        kPoints = -kRange;
        eType = -kRange;
        kNavMesh = kRange;
        kTargetPoint = kRange;
    }
    else
    {
        kPoints = float(cell->TESObjectCELL_GetDataX() << 12);
        eType = float(cell->TESObjectCELL_GetDataY() << 12);
        kNavMesh = kPoints + 4096.0;
        kTargetPoint = eType + 4096.0;
    }
    BenchLocation afWorldOriginY(pos, cell);
    if (!afWorldOriginY.FUN_005fda30(0))
        return 0.0f;
    afWorldOriginY.FUN_005fc8b0(m_fGridOriginX);
    PointArrayBench kPointArrayBench(count);
    if (kPosition == 2)
    {
        for (unsigned int i = 0; i < count; i++)
        {
            if (!FUN_005f16b0(afWorldOriginY.FUN_004c0120(), 0, pos, 2000.0f, kPointArrayBench.GetAt(i)))
                i--;
        }
    }
    else
    {
        for (unsigned int j = 0; j < count; j++)
        {
            kPointArrayBench.GetAt(j).x = RandomFloat(kPoints, kNavMesh);
            kPointArrayBench.GetAt(j).y = RandomFloat(eType, kTargetPoint);
            kPointArrayBench.GetAt(j).z = pos.z;
        }
    }
    for (unsigned int k = 0; k < count; k++)
    {
        switch (kPosition)
        {
        case 0: {
            Point2Bench bFirst;
            Point2Bench kPoint1(kPointArrayBench.GetAt(k).x, kPointArrayBench.GetAt(k).y);
            Point2Bench bSecond(kPointArrayBench.GetAt((k + 1) % count).x, kPointArrayBench.GetAt((k + 1) % count).y);
            Point2Bench kPoint2(kPointArrayBench.GetAt((k + 2) % count).x, kPointArrayBench.GetAt((k + 2) % count).y);
            Point2Bench kPoint0(kPointArrayBench.GetAt((k + 3) % count).x, kPointArrayBench.GetAt((k + 3) % count).y);
            FUN_005dd320(kPoint1, bSecond, kPoint2, kPoint0, bFirst);
            FUN_005dd4c0(kPoint1, bSecond, kPoint2, kPoint0);
            break;
        }
        case 1: {
            CloseRequestBench request;
            request.AssignPathingLocation(afWorldOriginY);
            request.SetTarget(kPointArrayBench.GetAt(k));
            CloseSolutionBench solution;
            FUN_005f9e70(&request, &solution);
            break;
        }
        case 2: {
            BenchLocation goal(kPointArrayBench.GetAt(k), afWorldOriginY.FUN_004c0120());
            RequestBench request;
            request.AssignPathingLocation(afWorldOriginY);
            request.SetGoal(goal);
            SolutionBench solution;
            FUN_005f8210(&request, &solution);
            break;
        }
        }
    }
    return 0.0f;
}
}   // namespace f3m_005faa80

// @f3 0x005e6560 (community match, verified in this file)
namespace f3m_005e6560 {
namespace c5e6560 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
using f3m_005e6780::Form5e67;
using f3m_005e6780::Input5e67;
using f3m_005e6780::List5e67;

struct RefObj
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

struct Map
{
    __declspec(noalias) bool FUN_005c8b00(void* key, NiPointer<RefObj>& out);
};

struct Owner
{
    int unk00[0x8c / 4];
    List5e67 unk8C;
    List5e67 unk94;
    Map unk9C;
    int unkA0[3];
    Map unkAC;
    void FUN_005e54d0(Input5e67* input);
    void NavMeshObstacleManager_OnDoorOpen(Input5e67* input);
};

// pdb: NavMeshObstacleManager::OnDoorOpen | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void Owner::NavMeshObstacleManager_OnDoorOpen(Input5e67* input)
{
    Input5e67* original = input;
    Form5e67* form = original->unk1C;
    if (form->unk04 == 0x1c && !form->TESObjectDOOR_IsSlidingDoor())
        FUN_005e54d0(original);
    NiPointer<RefObj> ref;
    void* key = original->unk0C;
    if (!unkAC.FUN_005c8b00(key, ref))
    {
        if (unk8C.Contains(original))
            unk8C.FUN_00421610((void**)&input);
    }
    void* key2 = original->unk0C;
    if (!unk9C.FUN_005c8b00(key2, ref))
    {
        void* id = original->unk0C;
        if (!unk94.Contains(id))
        {
            input = (Input5e67*)id;
            unk94.FUN_0049fac0((void**)&input);
        }
    }
}
}
}   // namespace f3m_005e6560

// @f3 0x005e6810 (community match, verified in this file)
namespace f3m_005e6810 {
namespace c5e6810 {

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObj
{
    virtual void v00();
    virtual void* DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T> struct SimpleArray
{
    virtual void v00();
    virtual void v04();
    virtual void* Free(void* p);
    T* data;
    unsigned int size;
    unsigned int capacity;
    T& GetAt(unsigned int i) { return data[i]; }
    void Clear()
    {
        if (data)
        {
            Free(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
};

struct Entry
{
    void FUN_005ea490();
};

struct Item : RefObj
{
    int unk08;
    const char* key;
    int unk10[(0x78 - 0x10) / 4];
    SimpleArray<void*> list;
};

struct Group : RefObj
{
    int unk08;
    SimpleArray<Item*> items;
};

struct GroupMap
{
    __declspec(noalias) bool FUN_005c8b00(const char* key, NiPointer<Group>& out);
};

struct NameMap
{
    void FUN_00899cf0(const char* key);
};

struct ItemList
{
    void FUN_004c25a0(NiPointer<Item>* item);
};

struct Owner
{
    int unk00[0x1c / 4];
    GroupMap groups;
    int unk20[(0x3c - 0x20) / 4];
    ItemList list3C;
    int unk40[(0x7c - 0x40) / 4];
    NameMap names;
    int unk80[(0x138 - 0x80) / 4];
    bool unk138;

    void FUN_005e4c80(NiPointer<Item>* item);
    Entry* FUN_005e4ce0(void* element, NiPointer<Item>* item, int flags);
    void FUN_005e6810(const char* name);
};

// pdb: NavMeshObstacleManager::ReallyRemoveObstaclesForReference | NavMeshObstacleManager.obj | fnv360_0822_retail, objrun, medium
// pdb params: aiFormID
void Owner::FUN_005e6810(const char* name)
{
    NiPointer<Group> group;
    if (!groups.FUN_005c8b00(name, group)) return;
    {
        ((NameMap*)&groups)->FUN_00899cf0(name);
        for (unsigned int i = 0; i < group->items.size; ++i)
        {
            NiPointer<Item> item = group->items.GetAt(i);
            const char* key = item->key; names.FUN_00899cf0(key);
            list3C.FUN_004c25a0(&item);
            if (unk138)
                FUN_005e4c80(&item);
            if (item->list.size)
            {
                for (unsigned int j = 0; j < item->list.size; ++j)
                    FUN_005e4ce0(item->list.GetAt(j), &item, 0x20)->FUN_005ea490();
                item->list.Clear();
            }
        }
    }
}

}
}   // namespace f3m_005e6810

// @f3 0x005eb550 (community match, verified in this file)
namespace MatchEB5Native {
struct BaseBuffer;
extern void* DAT_00e01ed8;
extern void* DAT_00dd8fe4;
extern void (__stdcall* DAT_00e01ee0)(void*);
extern void (__thiscall* DAT_00dd8fec)(BaseBuffer*, void*);

struct BaseBuffer {
    void* table;
    void* data;
    unsigned count;
    unsigned capacity;

    ~BaseBuffer() {
        table = &DAT_00dd8fe4;
        if (data) {
            DAT_00dd8fec(this, data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
};

struct Buffer : BaseBuffer {
    void FUN_005eb550();
};

struct DerivedCleanup {
    BaseBuffer* object;
    DerivedCleanup(BaseBuffer* p) : object(p) { object->table = &DAT_00e01ed8; }
    ~DerivedCleanup() { object->~BaseBuffer(); }
};

// pdb: BSScrapArray<NavMeshInfo const *,1024>::~BSScrapArray<NavMeshInfo const *,1024> | PathBuilder.obj | fnv360_0822_debug, call_seq, medium
void Buffer::FUN_005eb550()
{
    DerivedCleanup cleanup(this);
    if (data) {
        DAT_00e01ee0(data);
        data = 0;
        capacity = 0;
        count = 0;
    }
}
}

// @f3 0x005e8c20 (community match, verified in this file)
namespace n5e8c20 {
struct Heap {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
struct TlsBlock { char unk000[0x298]; int allocTag; };
extern __declspec(thread) TlsBlock g_tls;
struct TlsTagGuard {
    int saved;
    TlsTagGuard(int tag) { saved = g_tls.allocTag; g_tls.allocTag = tag; }
    ~TlsTagGuard() { g_tls.allocTag = saved; }
};
struct Node {
    Node* next;
    void* item;
    Node() { next = 0; item = 0; }
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct FUN_005e5280 {
    unsigned int count00;
    unsigned int tlsIndex04;
    void* data08;
    int unk0C;
    FUN_005e5280(unsigned int count);
    ~FUN_005e5280() { FUN_005e7750(); }
    void FUN_005e7750();
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct Owner {
    int unk00;
    Node* head;
    Node* tail;
    int unk0C;
    int unk10;
    FUN_005e5280* table;
    int unk18;
    void FUN_005e8c20(bool keep);
};
// pdb: LockFreeQueue<bhkRigidBody *>::RemoveAll | NavMeshObstacleManager.obj | fnv360_0822_debug, caller, medium
// pdb params: abCalledByDestructor
void Owner::FUN_005e8c20(bool keep)
{
    TlsTagGuard guard(6);
    unsigned int* raw = (unsigned int*)table;
    unsigned int count = *raw;
    FUN_005e5280* old = table;
    delete old;
    table = 0;
    unk18 = 0;
    while (head) {
        Node* next = head->next;
        head->item = 0;
        delete head;
        head = next;
    }
    if (!keep) {
        Node* node = new Node;
        head = node;
        tail = node;
        table = new FUN_005e5280(count);
    }
}
}

// @f3 0x005e5e60 (community match, verified in this file)
namespace f3m_005e5e60 {
namespace w5e5e60 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObj
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T> struct SimpleArray
{
    virtual void v00();
    T* data;
    unsigned int size;
    unsigned int capacity;
    T& GetAt(unsigned int i) { return data[i]; }
};

struct Entry { void FUN_005ea490(); };

struct Item : RefObj
{
    int unk08;
    const char* key;
    int unk10[(0x78 - 0x10) / 4];
    SimpleArray<void*> list;
};

struct Group : RefObj
{
    int unk08;
    SimpleArray<NiPointer<Item> > items;
};

struct GroupMap
{
    __declspec(noalias) bool FUN_005c8b00(const char* key, NiPointer<Group>& out);
    void FUN_00899cf0(const char* key);
};

struct GroupStore
{
    void FUN_00ad3b80(const char* key, NiPointer<Group> group);
};

struct Node
{
    const char* data;
    Node* next;
    bool IsEmpty() const { return next == 0 && data == 0; }
    void FUN_006c8220();
};

struct Owner
{
    int unk00[0x94 / 4];
    Node unk94;
    GroupStore unk9C;
    int unkA0[3];
    GroupMap unkAC;

    Entry* FUN_005e4ce0(void* element, NiPointer<Item>* item, int flags);
    bool FUN_005e5e60();
};

// pdb: NavMeshObstacleManager::ProcessRemovedDoors | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool Owner::FUN_005e5e60()
{
    Node* list = &unk94;
    if (list->IsEmpty())
        return false;
    Node* node = &unk94;
    while (node) {
        const char* key = node->data;
        node = node->next;
        NiPointer<Group> group;
        if (unkAC.FUN_005c8b00(key, group)) {
            for (unsigned int i = 0; i < group->items.size; ++i) {
                for (unsigned int j = 0; j < group->items.GetAt(i)->list.size; ++j)
                    FUN_005e4ce0(group->items.GetAt(i)->list.GetAt(j), &group->items.GetAt(i), 0x40)->FUN_005ea490();
            }
            unkAC.FUN_00899cf0(key);
            unk9C.FUN_00ad3b80(key, group);
        }
    }
    list->FUN_006c8220();
    return true;
}
}
}   // namespace f3m_005e5e60

// @f3 0x005ee5a0 (community match, verified in this file)
namespace f3m_005ee5a0 {
namespace Task2282 {
struct NiPoint3{int x,y,z;};struct TESWorldSpace;struct TESObjectCELL;
struct PathingContext
{
    int unk00;
    TESWorldSpace* worldSpace;
    TESObjectCELL* cell;
};
struct FUN_005fd540
{
    virtual void Loc_006dcee0_Vfn();
    NiPoint3 m_kPoint;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;

    FUN_005fd540(const NiPoint3&,TESObjectCELL*,TESWorldSpace*);
 ~FUN_005fd540(){}
    bool FUN_005fdde0();
    void* FUN_005fcbf0();
    NiPoint3 FUN_005c3420() const {return m_kPoint;}
};
struct Search_006b8340_Pool
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct Search_006b8340_OpenList
{
    void* m_items[2039];
    int m_uiItemCount;
};
struct Search_006b8340_Bins
{
    float m_vScale;
    int m_bins[20];
};
struct Search_006b8340_Base
{
    void* vtable;
    Search_006b8340_Pool m_kNodePool;
    Search_006b8340_OpenList m_openList;
    Search_006b8340_Bins m_bins;
    int unk2048;
    int unk204c;
    int unk2050;
    bool unk2054;
};
struct Search_006b8340_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct FUN_005eb4b0;
struct FUN_005eb5e0;
struct FUN_005dbb40 : public Search_006b8340_Base
{
    NiPoint3 m_kRayStart;
    int unk2064;
    NiPoint3 m_goal;
    int unk2074;
    int unk2078;
    int unk207c;
    int unk2080;
    Search_006b8340_Result m_result;

    void FUN_005dbbb0(); FUN_005dbb40();
 __forceinline ~FUN_005dbb40(){FUN_005dbbb0();}
    bool FUN_005dc8d0(int a1, const NiPoint3& a2, void* a3, const NiPoint3& a4, void* a5, FUN_005eb4b0* a6,
                            FUN_005eb5e0* a7, int a8);
};
struct FUN_005eb4b0
{
    void* vtable; void FUN_005eb550(); __forceinline ~FUN_005eb4b0(){FUN_005eb550();}
    void** data;
    unsigned size;
    int unk0c;
    int unk10;

    FUN_005eb4b0(int,int,void*);
    bool FUN_0076b610(){return size==0;}
    unsigned FUN_0044ddc0(){return size;}
    void** FUN_00877a30(unsigned index){return data+index;}
    void** FUN_006f2270(){return data+size-1;}
};
struct FUN_005eb5e0
{
    void* vtable; void FUN_005eb680(); __forceinline ~FUN_005eb5e0(){FUN_005eb680();}
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    FUN_005eb5e0(int,int,void*);
};
struct RequestHelper
{
    unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
unsigned unk040;
unsigned unk044;
unsigned unk048;
unsigned unk04c;
unsigned unk050;
unsigned unk054;
unsigned unk058;
unsigned unk05c;
unsigned unk060;
unsigned unk064;
unsigned unk068;
unsigned unk06c;
unsigned unk070;
unsigned unk074;
unsigned unk078;
unsigned unk07c;
unsigned unk080;
unsigned unk084;
unsigned unk088;
unsigned unk08c;
unsigned unk090;
unsigned unk094;
unsigned char unk98,unk99,unk9a; bool partial; bool GetByteAtOffset9B(){return partial;}
};
struct PathingSolution
{
    unsigned unk00;
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned char partial; void SetByteAtOffset40(int b){partial=(unsigned char)b;}
    void* FUN_005ebf20(const FUN_005fd540&);
    void FUN_005ebf90(void*);
    void FUN_005ecfe0(const FUN_005fd540&, int);
    void FUN_005ec000(void*, void*);
};
class PathHandler
{
  public:
    RequestHelper* m_request;
    PathingSolution* m_pPathingSolution;
    void* m_unk08;

    bool FUN_005ee5a0(const NiPoint3& pt1, const NiPoint3& pt2, PathingContext* ctx, int flag);
};

// @fnv 0x006ce8b0
// pdb: PathBuilder::BuildNavMeshInfoPathInSpace | PathBuilder.obj | fnv360_0822_debug, caller_sim, low
// pdb params: aStartLocation, aGoalLocation, pSpace, apTeleportDoor
bool PathHandler::FUN_005ee5a0(const NiPoint3& pt1, const NiPoint3& pt2, PathingContext* ctx, int flag)
{
    FUN_005fd540 loc1(pt1, ctx->cell, ctx->worldSpace);
    FUN_005fd540 loc4(pt2, ctx->cell, ctx->worldSpace);

    if (!loc1.FUN_005fdde0())
        return false;

    if (!loc4.FUN_005fdde0())
        return false;

    FUN_005dbb40 var20cc;
    FUN_005eb4b0 var5(0x14, 0, m_unk08);
    FUN_005eb5e0 var4(0x14, 0, m_unk08);
    int var14 = 0;

    bool retVal = var20cc.FUN_005dc8d0(var14, loc1.FUN_005c3420(), loc1.FUN_005fcbf0(), loc4.FUN_005c3420(),
                                             loc4.FUN_005fcbf0(), &var5, &var4, 0);

    if (!retVal)
    {
        if (var5.FUN_0076b610() || !reinterpret_cast<RequestHelper*>(m_request)->GetByteAtOffset9B())
        {
            return false;
        }
        else
        {
            m_pPathingSolution->SetByteAtOffset40(1);
        }
    }

    m_pPathingSolution->FUN_005ebf20(loc1);

    for (unsigned int i2 = 1; i2 < var5.FUN_0044ddc0() - 1; ++i2)
    {
        m_pPathingSolution->FUN_005ebf90(*var5.FUN_00877a30(i2));
    }

    if (retVal)
    {
        if (flag != 0)
        {
            m_pPathingSolution->FUN_005ecfe0(loc4, flag);
        }
        else
        {
            m_pPathingSolution->FUN_005ebf20(loc4);
        }
    }
    else
    {
        m_pPathingSolution->FUN_005ec000((char*)(*var5.FUN_006f2270()) + 0x10, *var5.FUN_006f2270());
    }

    return retVal;
}

}
}   // namespace f3m_005ee5a0

// @f3 0x005fb660 (community match, verified in this file)
extern const float DAT_00dbeb38;
extern int DAT_00dc4dc0;
namespace f3m_005fb660 {
namespace f3m_005fb660 {
struct NiPoint3 { float x, y, z; };
template <class T> inline T Max(T a, T b) { return a > b ? a : b; }
struct Actor;
struct PathingLocation {
    void* m_vtable;
    NiPoint3 Location;
    void* pNavMesh;
    void* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;
    unsigned char unk27;
    PathingLocation(Actor* apActor);
    ~PathingLocation() { m_vtable = &DAT_00dc4dc0; }
    PathingLocation& FUN_005fc480(const PathingLocation& ar_Other);
};
struct Actor {
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual NiPoint3 GetBoundMin();
    virtual NiPoint3 GetBoundMax();
    float FUN_004e6d80();
};
struct PathingRequest {
    void* m_vtable;
    int unk04;
    int unk08;
    PathingLocation kStart;
    PathingLocation kDest;
    int unk5C;
    int unk60;
    int unk64;
    float fGoalRadius;
    int unk6C;
    int unk70;
    float fTargetRadius;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    float fMinDistance;
    float fMaxDistance;
    int unkB8;
    PathingRequest();
    void FUN_00600ff0();
    ~PathingRequest() { FUN_00600ff0(); }
};
bool __cdecl FUN_005f8d20(PathingRequest* apRequest, void* apResult, bool abFlag);

// pdb: VATS::GetLineOfSight | VATS.obj | fnv360_1110_retail, call_gap, low
// pdb params: apCommand
bool __cdecl FUN_005fb660(Actor* apActor, Actor* apTarget, float afDistance, void* apResult)
{
    PathingRequest kRequest;
    kRequest.kStart.FUN_005fc480(PathingLocation(apActor));
    kRequest.kDest.FUN_005fc480(PathingLocation(apTarget));

    NiPoint3 kMax = apActor->GetBoundMax();
    NiPoint3 kMin = apActor->GetBoundMin();
    float fX = kMax.x - kMin.x;
    float fY = kMax.y - kMin.y;
    float fRadius = Max(fX, fY);
    fRadius = fRadius * apActor->FUN_004e6d80();
    fRadius = Max(fRadius, 32.0f);
    float fActorRadius = fRadius * 0.5f;
    kRequest.fGoalRadius = fActorRadius;

    kMax = apTarget->GetBoundMax();
    kMin = apTarget->GetBoundMin();
    fX = kMax.x - kMin.x;
    fY = kMax.y - kMin.y;
    fRadius = Max(fX, fY);
    fRadius = fRadius * apTarget->FUN_004e6d80();
    fRadius = Max(fRadius, 32.0f);
    kRequest.fTargetRadius = fRadius * 0.5f;

    kRequest.fMinDistance = static_cast<double>(0.9f) * afDistance + fActorRadius;
    kRequest.fMaxDistance = afDistance + fActorRadius;
    return FUN_005f8d20(&kRequest, apResult, false);
}
}
}   // namespace f3m_005fb660

// @f3 0x005f3cb0 (community match, verified in this file)
#include <math.h>
namespace q5f3cb0 {
struct TlsBlock { char unk000[0x298]; int allocTag; };
extern __declspec(thread) TlsBlock g_tls;
struct TlsTagGuard {
    int saved;
    TlsTagGuard(int tag) { saved = g_tls.allocTag; g_tls.allocTag = tag; }
    ~TlsTagGuard() { g_tls.allocTag = saved; }
};
struct P3 {
    float x, y, z;
    P3() {}
    P3(float a, float b, float c) : x(a), y(b), z(c) {}
    P3 operator+(const P3& o) const { return P3(x + o.x, y + o.y, z + o.z); }
    P3 operator-(const P3& o) const { return P3(x - o.x, y - o.y, z - o.z); }
    P3 operator*(float s) const { return P3(x * s, y * s, z * s); }
    friend P3 operator*(float s, const P3& v) { return P3(s * v.x, s * v.y, s * v.z); }
    void FUN_00468d00();
};
extern P3 DAT_00f72598;
extern P3 DAT_00f725a4;
struct QRng { unsigned int FUN_0086c4b0(unsigned int range); };
QRng* FUN_0044a2d0();
struct QGround { bool FUN_004d7380(P3* pos, float* z); };
struct QFinder {
    int unk00;
    QGround* PathingLocation_GetCell();
    int FUN_004c0120();
};
struct QAvoid {
    int unk00; int unk04; unsigned int count;
    float FUN_005fc160(const P3& point, P3& center);
};
struct QSpawn {
    int unk00, unk04, unk08;
    QFinder finder;
    P3 pos;
    char pad1C[0x94 - 0x1c];
    QAvoid* avoid;
    char pad98[0xb0 - 0x98];
    float radius;
};
struct QOut {
    char pad[0x18];
    int unk18;
    int unk1C;
    void FUN_005f3c10(P3* pos, QGround* ground, int a);
};

int FUN_005f3cb0(QSpawn* obj, QOut* out)
{
    TlsTagGuard guard(0x2d);
    P3 start = obj->pos;
    QGround* ground = obj->finder.PathingLocation_GetCell();
    int cell = obj->finder.FUN_004c0120();
    P3 result;
    P3 center;
    if (obj->avoid && obj->avoid->count) {
        obj->avoid->FUN_005fc160(start, center);
        result = start - center;
        result.FUN_00468d00();
        float r = obj->radius;
        result.x *= r;
        result.y *= r;
        result.z *= r;
        result.x = start.x + result.x;
        result.y = start.y + result.y;
        result.z = start.z + result.z;
    } else {
        center = start;
        QRng* rng = FUN_0044a2d0();
        float a = (float)rng->FUN_0086c4b0(0xffffffff) * 1.462918119976564e-09 - 3.1415927410125732;
        P3 ys;
        ys = ((float)sin(a) * obj->radius) * DAT_00f725a4;
        P3 xc;
        xc = ((float)cos(a) * obj->radius) * DAT_00f72598;
        P3 sum = xc + center;
        result = sum + ys;
    }
    {
    float z;
    if (ground && ground->FUN_004d7380(&result, &z))
        result.z = z;
    }
    out->FUN_005f3c10(&start, ground, cell);
    out->FUN_005f3c10(&result, ground, cell);
    out->unk18 = 0;
    out->unk1C = 1;
    return 1;
}
}

// @f3 0x005e81f0 (community match, verified in this file)
extern float DAT_010746d0;
extern unsigned int DAT_01090bb0;
namespace f3m_005e81f0 {
namespace f3_timed_item {
struct __declspec(align(16)) Point {
    float x, y, z;
};
struct Point3 { float x, y, z; };
struct ModelNode {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c;
    float x, y, z;
};
struct ModelRef { int unk00, unk04; ModelNode* node; };
struct TrackedItem {
    virtual void unk00();
    virtual void DeleteThis();
    volatile long referenceCount;
    int unk008;
    ModelRef* model;
    float x, y, z;
    int unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038;
    int unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058;
    int unk05c, unk060, unk064, unk068, unk06c;
    unsigned int updatedAt;
};

extern long (__stdcall* NativeRetain)(volatile long*);
extern long (__stdcall* NativeRelease)(volatile long*);

struct ItemLease {
    TrackedItem* item;
    explicit ItemLease(TrackedItem* entry) : item(entry) {
        if (item)
            NativeRetain(&item->referenceCount);
    }
    ~ItemLease() {
        if (item) {
            TrackedItem* old = item;
            if (NativeRelease(&old->referenceCount) == 0)
                old->DeleteThis();
        }
    }
};
struct Link { TrackedItem* item; Link* next; };
struct Tracker {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038;
    Link head;
    void FUN_005e77d0(ItemLease*);
    void FUN_005e81f0();
};

// pdb: NavMeshObstacleManager::ProcessMovingReferences | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
void Tracker::FUN_005e81f0()
{
    Link* cursor = &head;
    const unsigned int delay = static_cast<unsigned int>(DAT_010746d0 * 1000.0);
    while (cursor) {
        if (!cursor->next && !cursor->item)
            break;
        ItemLease retained(cursor->item);
        TrackedItem* entry = retained.item;
        cursor = cursor->next;
        const ModelRef* modelRef = entry->model;
        const ModelNode* model = modelRef->node;
        const Point original = {model->x, model->y, model->z};
        const double gameUnits = static_cast<double>(6.999040126800537f);
        const Point3 scaled = {static_cast<float>(original.x * gameUnits),
                              static_cast<float>(original.y * gameUnits),
                              static_cast<float>(original.z * gameUnits)};
        const float dx = scaled.x - entry->x;
        const float dy = scaled.y - entry->y;
        const float dz = scaled.z - entry->z;
        const float squaredDistance = dy * dy + dx * dx + dz * dz;
        if (squaredDistance > 25.0 && DAT_01090bb0 - entry->updatedAt >= delay)
            FUN_005e77d0(&retained);
    }
}
}
}   // namespace f3m_005e81f0

// @f3 0x005f0eb0 (community match, verified in this file)
namespace f3m_005f0eb0 {
namespace n5f0eb0 {
struct FUN_005fd570 {
    FUN_005fd570(int a, void* p);
    virtual ~FUN_005fd570() {}
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct Elem {
    int m0;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void FUN_006102e0(FUN_005fd570* t);
};
struct List { void FUN_005eb2f0(int i, int f); int a, b; };
struct State {
    int unk00, unk04, unk08;
    Elem* mc;
    int unk10, unk14;
    int m18;
    int m1c;
    List m20;
    unsigned int m28;
    int unk2c, unk30, unk34, unk38, unk3c;
    bool b40;
    void FUN_005ec100();
    unsigned int Count() const { return m28; }
    void ResetNodes() {m20.FUN_005eb2f0(Count()-1,1);}
    Elem* At(int i) { return &mc[i]; }
    int Last() const { return m1c; }
};
struct Ctl {
    int m0;
    State* m4;
    int m8, mc;
    bool m10;
    bool FUN_005eacb0(int idx, int* a, int* b);
    bool PathBuilder_BuildDetailedPath(int idx);
    bool FUN_005f09e0();
    int FUN_005f0eb0(int idx, int a2);
};
// pdb: PathBuilder::UpdateDetailedPath | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiCurrentVirtualNodeIndex, aCurrentActorLocation
int Ctl::FUN_005f0eb0(int idx, int a2)
{
    int l14 = -1;
    int l10 = -1;
    if (!FUN_005eacb0(idx, &l14, &l10))
    {
        if (!m4->m28)
            return 0;
        m4->FUN_005ec100();
        return 1;
    }
    if (m4->Count() > 0)
    {
        int cur = m4->m1c;
        int last = l10;
        if (cur >= last)
            return 0;
        m4->m18 = idx;
        FUN_005fd570 t(a2, &m4->At(idx)->unk04);
        m4->At(idx)->FUN_006102e0(&t);
        unsigned int n = m4->Count();
        m4->ResetNodes();
        m4->m1c = last;
        m10 = true;
        if (!FUN_005f09e0())
            return -1;
        if (m4->b40)
            return -1;
        m4->m20.FUN_005eb2f0(n - 1, 1);
    }
    else if (!PathBuilder_BuildDetailedPath(idx))
        return -1;
    return 2;
}
}
}   // namespace f3m_005f0eb0

// @f3 0x005fd770 (community match, verified in this file)
namespace f3m_005fd770 {
namespace w5fd770 {

struct Node;

struct List {
    virtual ~List();
    Node** data;
    unsigned size;
    unsigned cap;
    int Find(Node* item) const {
        for (unsigned i = 0; i < size; ++i)
            if (data && data[i] == item)
                return i;
        return -1;
    }
};

struct Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;

    List first;
    List second;
    unsigned Count() const { return first.size + second.size; }
};

struct Array {
    virtual ~Array();
    virtual Node** Allocate(unsigned count);
    Node** data;
    unsigned size;
    unsigned cap;
    unsigned FUN_005e5350();
    void FUN_00799ae0(unsigned capacity, unsigned count);
    void Add(Node* const& item) { data[FUN_005e5350()] = item; }
    int Find(Node* item) const {
        for (unsigned i = 0; i < size; ++i)
            if (data && data[i] == item)
                return i;
        return -1;
    }
    void Append(Node* item) {
        if (size == cap) {
            if (!cap) {
                Array* self = this;
                data = self->Allocate(4);
                cap = 4;
            } else {
                unsigned c = cap > 0x400 ? cap + 0x400 : cap * 2;
                FUN_00799ae0(c, size);
                cap = c;
            }
        }
        size++;
        data[size - 1] = item;
    }
};

struct FUN_005eb550 : Array {
    void* allocator;
    ~FUN_005eb550();
};

struct FUN_005fd3e0 : FUN_005eb550 {
    FUN_005fd3e0();
};

struct Graph {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    int done;
    List* nodes;
    bool FUN_005fd770();
};

// pdb: PathingLocation::AreAllMeshesReachable | PathingLocation.obj | fnv360_0822_retail, call_gap, low
bool Graph::FUN_005fd770()
{
    FUN_005fd3e0 found;
    unsigned i = 0;
    if (done)
        return true;
    if (!nodes || !nodes->size)
        return false;
    found.Add(nodes->data[0]);
    unsigned split = nodes->data[0]->first.size;
    unsigned second = nodes->data[0]->second.size;
    unsigned total = second + split;
    for (; i < total; ++i) {
        Node* item;
        if (i < split) item = nodes->data[0]->first.data[i]; else item = nodes->data[0]->second.data[i - split];
        if (nodes->Find(item) != -1)
            found.Add(item);
    }
    unsigned want = nodes->size;
    if (found.size == want)
        goto done_true;
    bool changed;
    do {
        changed = false;
        for (unsigned j = 1; j < found.size; ++j) {
            Node* node = found.data[j];
            unsigned count = node->first.size;
            for (unsigned k = 0; k < node->first.size; ++k) {
                Node* item = k < count ? node->first.data[k] : node->second.data[k - count];
                if (nodes->Find(item) != -1 && found.Find(item) == -1) {
                    found.Append(item);
                    changed = true;
                }
            }
        }
    } while (changed);
    if (found.size == nodes->size)
        goto done_true;
    return false;
done_true:
    return true;
}

}
}   // namespace f3m_005fd770

// @f3 0x005ec510 (community match, verified in this file)
extern float FUN_00f67ae0;
namespace f3m_005ec510 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    __declspec(noalias) Vec3 UnitCross(const Vec3& o) const;
};

extern const Vec3 FUN_00f725b0;   // unit Z


struct PathCell;

struct PathNode {
    int unk00;
    Vec3 pos;                     // +04
    Vec3 GetPos() const { return pos; }
    PathCell* PathingLocation_GetCell();
};

struct PathFilter {
    virtual void v00();
    bool m_bSmall;                // +04
    PathFilter() {}
    void Set(float r) { m_bSmall = r > FUN_00f67ae0; }
};

struct PathProbe {
    PathProbe(const Vec3& pt, PathNode* node);
    ~PathProbe() {}
    virtual void v00();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};

unsigned char __cdecl FUN_005f25b0(void* first, void* second, void* dest, PathFilter* filter);

struct HeightMgr {
    float TES_GetWaterHeight(Vec3* pt, PathCell* cell);
};


struct PathActor {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    float m_fRadius;              // +68
};

struct PathSink {
    void FUN_005c5cf0(PathNode* node, Vec3* v);
};

struct PathCheck {
    PathActor* m_pActor;          // +00
    PathSink* m_pSink;            // +04
    bool FUN_005ec510(PathNode* a1, PathNode* a2);
};

// pdb: PathBuilder::TryBuildStraightPath | PathBuilder.obj | fnv360_0822_retail, uvref, medium
// pdb params: aStartLocation, aGoalLocation
bool PathCheck::FUN_005ec510(PathNode* a1, PathNode* a2)
{
    PathFilter filter;
    filter.Set(m_pActor->m_fRadius);
    if (!FUN_005f25b0(a1, a2, 0, &filter))
        return false;

    {
        Vec3 q1 = a1->GetPos();
        Vec3 p1 = q1;
        if (((HeightMgr*)DAT_0107a0d8)->TES_GetWaterHeight(&q1, a1->PathingLocation_GetCell()) + 25.0 > p1.z)
            { m_pSink->FUN_005c5cf0(a1, (Vec3*)&DAT_0108ec68); return true; }
    }
    {
        Vec3 q2 = a2->GetPos();
        Vec3 p2 = q2;
        if (((HeightMgr*)DAT_0107a0d8)->TES_GetWaterHeight(&q2, a2->PathingLocation_GetCell()) + 25.0 > p2.z)
            { m_pSink->FUN_005c5cf0(a1, (Vec3*)&DAT_0108ec68); return true; }
    }
    {
        Vec3 off = (a2->GetPos() - a1->GetPos()).UnitCross(FUN_00f725b0) * m_pActor->m_fRadius;
        PathProbe o1(a1->GetPos() - off, a1);
        PathProbe o2(a2->GetPos() - off, a2);
        if (!FUN_005f25b0(&o1, &o2, 0, 0))
            return false;
        PathProbe o3(a1->GetPos() + off, a1);
        PathProbe o4(a2->GetPos() + off, a2);
        if (!FUN_005f25b0(&o3, &o4, 0, 0))
            return false;
        m_pSink->FUN_005c5cf0(a1, (Vec3*)&DAT_0108ec68);
        return true;
    }
}
}   // namespace f3m_005ec510

// @f3 0x005e6670 (community match, verified in this file)
namespace f3m_005e6670 {
namespace fast6_5e6670 {
using namespace f3m_005e6780;
struct RefObject5e {
    virtual void v00();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
template<class T> struct Ptr5e {
    T* m_pObject;
    Ptr5e() : m_pObject(0) {}
    ~Ptr5e() { T* p = *(T* volatile*)&m_pObject; if (p) p->DecRefCount(); }
};
struct Map5e {
    int unk00; int unk04; int unk08; int unk0c;
    bool FUN_005c8b00(void* key, Ptr5e<RefObject5e>& out);
};
struct OwnerView5e {
    Owner5e67 native;
    Map5e first;
    Map5e second;
    void NavMeshObstacleManager_OnDoorClose(Input5e67* input);
};
// pdb: NavMeshObstacleManager::OnDoorClose | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void OwnerView5e::NavMeshObstacleManager_OnDoorClose(Input5e67* input) {
    Input5e67* original = input;
    Form5e67* form = original->unk1C;
    if (form->unk04 == 0x1c && !form->TESObjectDOOR_IsSlidingDoor())
        native.FUN_005e6430(original);
    Ptr5e<RefObject5e> result;
    void* firstKey = original->unk0C;
    if (!first.FUN_005c8b00(firstKey, result)) {
        void* id = original->unk0C;
        if (native.unk94.Contains(id)) { void* key = id; native.unk94.FUN_00421610(&key); }
    }
    void* secondKey = original->unk0C;
    if (!second.FUN_005c8b00(secondKey, result)) {
        if (!native.unk8C.Contains(original))
            native.unk8C.FUN_0049fac0((void**)&input);
    }
}
}
}   // namespace f3m_005e6670

// @f3 0x005e74f0 (community match, verified in this file)
extern char DAT_010746c4;
namespace f3m_005e74f0 {
// 0x005e74f0 -- iterate a map at this+0xc8, push each value into the array at
// this+0xd8 under the lock at this+0x100 (or hand it to FUN_005e6bb0), then
// clear the map.
namespace f3m_005e74f0 {

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);


struct Lock74 {
    volatile long owner;
    long count;
    void FUN_00409a80(const char* name);
    __forceinline void Unlock() {
        if (--count == 0)
            { long o = owner; InterlockedCompareExchange(&owner, 0, o); }
    }
};

struct Val74 {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Release();
};

struct Item74 {
    Item74* m_pkNext;
    unsigned int m_key;
    Val74* m_val;
};

struct Map74 {
    virtual void Unk00();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    unsigned int m_uiHashSize;
    Item74** m_ppkHashTable;
    unsigned int m_uiItemCount;

    Item74* GetFirstItem() const {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    __declspec(noinline) void GetNext(Item74*& apCur, unsigned int& arKey, Val74*& apVal) const {
        Item74* pItem = apCur;
        arKey = pItem->m_key;
        apVal = pItem->m_val;
        if (pItem->m_pkNext) {
            apCur = pItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pItem->m_key);
        for (++i; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i]) {
                apCur = m_ppkHashTable[i];
                return;
            }
        }
        apCur = 0;
    }
    void RemoveAll();
};

struct Arr74 {
    void** m_pkVtbl;
    Val74** m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    void FUN_00799ae0(unsigned int capacity, unsigned int size);

    __forceinline unsigned int Add(Val74* const& val) {
        if (m_uiSize == m_uiCapacity) {
            if (!m_uiCapacity) {
                m_pData = (Val74**)((void* (__thiscall*)(Arr74*, unsigned int))m_pkVtbl[1])(this, 4);
                m_uiCapacity = 4;
            } else {
                unsigned int capacity = m_uiCapacity > 0x400 ? m_uiCapacity + 0x400 : m_uiCapacity * 2;
                FUN_00799ae0(capacity, m_uiSize);
                m_uiCapacity = capacity;
            }
        }
        ++m_uiSize;
        m_pData[m_uiSize - 1] = val;
        return m_uiSize - 1;
    }
};

class Owner74 {
public:
    int unk000; int unk004; int unk008; int unk00C;
    int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C;
    int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C;
    int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C;
    int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C;
    int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC;
    int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4;
    Map74 m_map;
    Arr74 m_arr;
    int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    Lock74 m_lock;

    void FUN_005e74f0();
    void FUN_005e6bb0(Val74* val);
};

// pdb: NavMeshObstacleManager::QueueTasks | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
void Owner74::FUN_005e74f0()
{
    {
        Item74* pCur = m_map.GetFirstItem();
        while (pCur)
        {
            unsigned int key;
            Val74* pVal;
            m_map.GetNext(pCur, key, pVal);
            if (DAT_010746c4)
            {
                FUN_005e6bb0(pVal);
            }
            else
            {
                m_lock.FUN_00409a80(0);
                m_arr.Add(pVal);
                m_lock.Unlock();
                pVal->Release();
            }
        }
    }
    m_map.RemoveAll();
}

}
}   // namespace f3m_005e74f0

// @f3 0x005ee8c0 (community match, verified in this file)
namespace f3m_005ee8c0 {
struct Vec3 { float x, y, z; };
struct Loc { int unk00; Vec3 pos; };
struct PosObj { Vec3* GetPos(); };
struct Elem { PosObj* obj; Vec3 pos; };

struct Arr12 {
    int unk00;
    Vec3* data;
    unsigned cnt;
    unsigned cap;
    void Resize(unsigned newCap, unsigned keep);
    Vec3& operator[](unsigned i) { return data[i]; }
};
struct Arr16 {
    int unk00;
    Elem* data;
    unsigned cnt;
    unsigned cap;
    void Resize(unsigned newCap, unsigned keep);
    Elem& operator[](unsigned i) { return data[i]; }
};
struct WP {
    Arr12 a;
    Arr16 b;
    Vec3 unk20;
    Vec3 unk2c;
    WP();
    ~WP();
};
struct Dest {
    int unk00;
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
    char flag40;
};

struct Buf {
    Loc nodes[0x20b];
    int unk;
    int unk2;
    Buf();
    ~Buf();
    bool Run(Loc* a, Loc* b, WP* w, int z, float f, void* e, int z2);
};

struct Ex5c { int unk00; };
struct Info2 {
    int unk00;
    int unk04;
    int unk08;
    Loc start;           // 0x0c
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    Loc end;             // 0x34
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    Ex5c unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    char flag98;
};

struct Pather {
    Info2* info;
    Dest* dest;
    bool Check(Vec3* from, Vec3* to, Vec3* pts, void* o);
    bool FUN_005ee8c0();
};

// pdb: PathBuilder::BuildTeleportDoorPath | PathBuilder.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bool Pather::FUN_005ee8c0()
{
    Vec3 X, Y;
    Buf buf;
    WP wp;
    if (wp.a.cap != 10) {
        if (wp.a.cnt > 10) wp.a.cnt = 10;
        wp.a.Resize(10, wp.a.cnt);
        wp.a.cap = 10;
    }
    if (wp.b.cap != 10) {
        if (wp.b.cnt > 10) wp.b.cnt = 10;
        wp.b.Resize(10, wp.b.cnt);
        wp.b.cap = 10;
    }
    void* ex = 0;
    if (info->flag98 == 0) ex = &info->unk5c;
    Loc* en = &info->end;
    Loc* st = &info->start;
    bool ok = buf.Run(st, en, &wp, 0, 0.0f, ex, 0);
    if (wp.a.cnt <= 1) {
        if (!ok) goto done;
        Y = info->end.pos;
        X = info->start.pos;
        if (!Check(&X, &Y, wp.a.data, 0)) return false;
        goto done;
    }
    Loc* l0 = &info->start;
    Y = l0->pos;
    X = *wp.b.data[0].obj->GetPos();
    if (!Check(&Y, &X, wp.a.data, wp.b.data[0].obj)) return false;
    Vec3 e, r2;
    for (unsigned i = 0; i < wp.b.cnt - 1; i++) {
        e = wp.b.data[i].pos;
        r2 = *wp.b.data[i + 1].obj->GetPos();
        if (!Check(&e, &r2, &wp.a[i + 1], wp.b[i + 1].obj))
            { Dest* d = dest; d->flag40 = 1; return false; }
    }
    Y = wp.b.data[wp.b.cnt - 1].pos;
    Loc* l1 = &info->end;
    X = l1->pos;
    Vec3* pl = wp.a.data + (wp.a.cnt - 1);
    Vec3* py = &Y;
    if (!Check(py, &X, pl, 0)) {
        Dest* d = dest; d->flag40 = 1;
        return false;
    }
done:
    return ok;
}
}   // namespace f3m_005ee8c0

// @f3 0x005ea060 (community match, verified in this file)
extern __declspec(thread) int DAT_0117c298;
namespace f3m_005ea060 {
// ObstacleTaskData_Process at 0x005ea060 (this in ecx, no stack arguments)
// Scene/task update: builds a 0x108 object into the smart pointer at this+0x20,
// then dispatches every entry of the this+0x28 array through one of four
// per-type calls, marking each entry handled (0) or not (1).


struct MemCtx5ea060 {
    int saved;
    MemCtx5ea060() : saved(DAT_0117c298) { DAT_0117c298 = 0x2e; }
    ~MemCtx5ea060() { DAT_0117c298 = saved; }
};

void* __cdecl FUN_0089eb90(unsigned int size);
int __cdecl FUN_005e9df0(const void* a, const void* b);
void __cdecl FUN_00c011c0(void* base, unsigned int count, unsigned int elemSize,
                          int (__cdecl* compare)(const void*, const void*));

struct Sp5ea060Ref;
struct Sp5ea060Table {
    void* unk00;
    void (__thiscall* Destroy)(Sp5ea060Ref* self);
};
struct Sp5ea060Ref {
    Sp5ea060Table* table;
    long count;
    long Dec() { return InterlockedDecrement(&count); }
    void DeleteThis() { table->Destroy(this); }
};

struct Entry5ea060;
struct Inner5ea060 { int unk00; int unk04; int m08; int unk0c; };
struct Ptr5ea060 { int unk00; int unk04; Inner5ea060* m08; };
struct Entry5ea060 { Ptr5ea060* ptr; int type; int flag; int unk0c; };
struct Elem5ea060 { void* value; int unk04; int unk08; };

struct Obj5ea060 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    Sp5ea060Ref ref;
    int unk24; int unk28; int unk2c; int unk30;
    int unk34; int unk38; int unk3c; int unk40;
    int unk44; int unk48; int unk4c; int unk50;
    int unk54; int unk58; int unk5c; int unk60;
    int unk64; int unk68; int unk6c; int unk70;
    int unk74; int unk78; int unk7c; int unk80;
    int unk84; int unk88; int unk8c; int unk90;
    int unk94; int unk98; int unk9c; int unka0;
    int unka4; int unka8; int unkac; int unkb0;
    int unkb4; int unkb8; int unkbc; int unkc0;
    int unkc4; int unkc8; int unkcc; int unkd0;
    int unkd4; int unkd8; int unkdc; int unke0;
    int unke4; int unke8; int unkec; int unkf0;
    int unkf4; int unkf8; int unkfc; int unk100;
    int unk104;
    Obj5ea060();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p);
    bool FUN_005bcca0(Entry5ea060* entry, int* context);
    bool FUN_005c19f0(Entry5ea060* entry, int* context);
    bool FUN_005c1740(int value, Ptr5ea060* entry);
    bool FUN_005bf390(int value);
};

struct Smart5ea060 {
    Obj5ea060* object;
    void FUN_0040eb40(const Smart5ea060& other);
    ~Smart5ea060() {
        if (object) {
            Sp5ea060Ref* ref = &object->ref;
            if (InterlockedDecrement(&ref->count) == 0)
                ref->table->Destroy(ref);
        }
    }
};

struct Owner5ea060 {
    void FUN_005bc9c0(Smart5ea060* pointer);
};

struct World5ea060 {
    int unk00; int unk04;
    unsigned int flags;
    int unk0c; int unk10; int unk14; int unk18;
    int unk1c; int unk20; int unk24; int unk28;
    int unk2c; int unk30; int unk34; int unk38;
    int unk3c; int unk40; int unk44; int unk48;
    int unk4c; int unk50;
    int m54;
    bool Get() const { return (flags >> 4) & 1; }
};

struct State5ea060 {
    void NavMeshObstacleManager_AddProcessedTask(void* item);
};

State5ea060* __cdecl FUN_005e9ad0();
void __cdecl FUN_005b87d0(Owner5ea060** out, int value);
Smart5ea060 __cdecl FUN_0043c2d0(Obj5ea060* object) throw();

struct C5ea060 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    World5ea060* m18;
    Owner5ea060* m1c;
    Smart5ea060 m20;
    int unk24;
    Entry5ea060* m28;
    unsigned int m2c;
    int m30;
    int m34;
    Elem5ea060* m38;
    unsigned int m3c;
    int m40; int m44;
    Elem5ea060* m48;
    unsigned int m4c;
    void ObstacleTaskData_Process();
};

// pdb: ObstacleTaskData::Process | NavMeshObstacleTask.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void C5ea060::ObstacleTaskData_Process()
{
    MemCtx5ea060 context;
    FUN_005e9ad0();
    bool found = false;
    Owner5ea060** pm = &m1c;
    if (!m18->Get()) {
        FUN_005b87d0(pm, m18->m54);
        found = *pm != 0;
    }
    if (found) {
        m20.FUN_0040eb40(FUN_0043c2d0(new Obj5ea060));
        (*pm)->FUN_005bc9c0(&m20);
        FUN_00c011c0(m28, m2c, 0x10, FUN_005e9df0);
        for (unsigned int i = 0; i < m2c; i++) {
            Entry5ea060* e = &m28[i];
switch (e->type) {
case 0x10:
case 0x11:
if (m20.object->FUN_005bcca0(e, &m34))
m28[i].flag = 0;
 else
 m28[i].flag = 1;
break;
case 0x20:
case 0x21:
if (m20.object->FUN_005c19f0(e, &m34))
m28[i].flag = 0;
 else
 m28[i].flag = 1;
break;
case 0x40:
{Ptr5ea060* p = e->ptr;
if (m20.object->FUN_005bf390(p->m08->m08))
m28[i].flag = 0;
 else
 m28[i].flag = 1;}
break;
case 0x30:
{Entry5ea060* arr = *(Entry5ea060* volatile*)&m28;
Ptr5ea060* p = arr[i].ptr;
Obj5ea060* o = m20.object;
Inner5ea060* in = p->m08;
if (o->FUN_005c1740(in->m08, p))
m28[i].flag = 0;
 else
 m28[i].flag = 1;}
break;
}
}
        for (unsigned int i = 0; i < m4c; i++)
            m48[i].value = m18;
        for (unsigned int i = 0; i < m3c; i++)
            m38[i].value = m18;
    } else {
        for (unsigned int i = 0; i < m2c; i++)
            m28[i].flag = 1;
    }
    FUN_005e9ad0()->NavMeshObstacleManager_AddProcessedTask(this);
    FUN_005e9ad0();
}
}   // namespace f3m_005ea060

// @f3 0x005f8d20 (community match, verified in this file)
extern void* DAT_00db5c04;
namespace f3m_005f8d20 {
struct PathRefObject {
    virtual ~PathRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount() {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct PathNavMesh {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    PathRefObject kRef;
};

struct PathNavMeshPtr {
    PathNavMesh* m_pObject;
    PathNavMeshPtr() : m_pObject(0) {}
    ~PathNavMeshPtr() {
        if (m_pObject)
            m_pObject->kRef.DecRefCount();
    }
    operator PathNavMesh*() const { return m_pObject; }
};

struct PathNavTriangle {
    PathNavMesh* pNavMesh;
    unsigned short usTriangle;
    int unk08;
    int unk0C;
    int unk10;
};

struct PathLocation {
    void* m_vtable;
    float x, y, z;
    void* pNavMesh;
    void* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;
    unsigned char unk27;
    bool FUN_005fcc10();
    bool FUN_005fc8f0(PathNavMeshPtr* apMesh, unsigned short* apTriangle);
    PathLocation& FUN_005fc480(const PathLocation& arOther);
};

struct PathRequestBase {
    void* m_vtable;
    int unk04;
    int unk08;
    PathLocation kStart;
    PathLocation kDest;
    int unk5C;
    int unk60;
    int unk64;
    float fGoalRadius;
    int unk6C;
    int unk70;
    float fTargetRadius;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
};

struct PathRequest : PathRequestBase {
    float fMinDistance;
    float fMaxDistance;
    void FUN_00601080(PathRequestBase* apOut);
};

struct PathRequestA : PathRequestBase {
    PathRequestA();
    ~PathRequestA();
};

struct PathRequestB : PathRequest {
    PathRequestB();
    ~PathRequestB();
};


struct PathArray {
    void* m_vtable;
    void* pData;
    unsigned int uiCount;
    unsigned int uiCapacity;
    PathArray() { m_vtable = &DAT_00db5c04; pData = 0; uiCount = 0; uiCapacity = 0; }
    ~PathArray();
};

struct PathSearchBlock40 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct PathSearchBlock400 {
    PathSearchBlock40 unk000;
    PathSearchBlock40 unk040;
    PathSearchBlock40 unk080;
    PathSearchBlock40 unk0C0;
    PathSearchBlock40 unk100;
    PathSearchBlock40 unk140;
    PathSearchBlock40 unk180;
    PathSearchBlock40 unk1C0;
    PathSearchBlock40 unk200;
    PathSearchBlock40 unk240;
    PathSearchBlock40 unk280;
    PathSearchBlock40 unk2C0;
    PathSearchBlock40 unk300;
    PathSearchBlock40 unk340;
    PathSearchBlock40 unk380;
    PathSearchBlock40 unk3C0;
};

struct PathSearch {
    int unk0000;
    PathSearchBlock400 unk0004;
    PathSearchBlock400 unk0404;
    PathSearchBlock400 unk0804;
    PathSearchBlock400 unk0C04;
    PathSearchBlock400 unk1004;
    PathSearchBlock400 unk1404;
    PathSearchBlock400 unk1804;
    PathSearchBlock400 unk1C04;
    PathSearchBlock40 unk2004;
    PathSearchBlock40 unk2044;
    PathSearchBlock40 unk2084;
    PathSearchBlock40 unk20C4;
    PathSearch();
    ~PathSearch();
    bool FUN_005d1d10(PathRequest* apRequest, PathNavTriangle* apStart, PathNavTriangle* apDest);
    void FUN_005f1100(void* apResult);
};

struct PathOut { float f; PathOut() {} };
struct PathOut2 { float f; };
struct PathSolver {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned int uiCount;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    PathSolver();
    ~PathSolver();
    bool FUN_00604f70(float afA, float afB, int aiC, const PathOut& arOut, void* apResult);
};

void __cdecl FUN_005f64f0(PathArray* apArray);
bool __cdecl FUN_005f8210(PathRequestBase* apRequest, PathSolver* apSolver);
bool __cdecl FUN_005f4d90(PathRequest* apRequest, void* apResult);

bool __cdecl FUN_005f8d20(PathRequest* apRequest, void* apResult, bool abFlag)
{
    if (!apRequest->kStart.FUN_005fcc10())
        return false;
    PathNavMeshPtr spStartMesh;
    unsigned short usStartTri = 0xffff;
    if (!apRequest->kStart.FUN_005fc8f0(&spStartMesh, &usStartTri))
        return false;
    PathNavTriangle kStartTri;
    kStartTri.pNavMesh = spStartMesh;
    kStartTri.usTriangle = usStartTri;
    if (!apRequest->kDest.FUN_005fcc10())
        return false;
    PathNavMeshPtr spDestMesh;
    unsigned short usDestTri = 0xffff;
    if (!apRequest->kDest.FUN_005fc8f0(&spDestMesh, &usDestTri))
        return false;
    PathNavTriangle kDestTri;
    kDestTri.pNavMesh = spDestMesh;
    kDestTri.usTriangle = usDestTri;

    PathSearch kSearch;
    PathArray kArray;
    FUN_005f64f0(&kArray);
    if (!kSearch.FUN_005d1d10(apRequest, &kStartTri, &kDestTri)) {
        PathRequestA kRequest;
        apRequest->FUN_00601080(&kRequest);
        PathSolver kSolver;
        if (!FUN_005f8210(&kRequest, &kSolver))
            return false;
        float fDist = apRequest->fMinDistance;
        if (!kSolver.FUN_00604f70((float)(kSolver.uiCount - 1), fDist, 0, PathOut(), apResult)) {
            PathRequestB kRequest2;
            apRequest->FUN_00601080(&kRequest2);
            kRequest2.kStart.FUN_005fc480(apRequest->kDest);
            kRequest2.fMinDistance = apRequest->fMinDistance;
            kRequest2.fMaxDistance = apRequest->fMaxDistance;
            if (FUN_005f4d90(&kRequest2, apResult))
                return true;
            return false;
        }
    } else {
        kSearch.FUN_005f1100(apResult);
    }
    return true;
}
}   // namespace f3m_005f8d20

// @f3 0x005ece20 (community match, verified in this file)
namespace f3m_005ece20 {
namespace f3m_005ece20 {
struct Point5ece20
{
    unsigned int x, y, z;
};
struct Elem5ece20
{
    unsigned int a;
    unsigned short b;
    unsigned int d;
    Point5ece20 p;
    Elem5ece20& operator=(const Elem5ece20& o) { a = o.a; b = o.b; d = o.d; p = o.p; return *this; }
};
struct Array5ece20
{
    virtual void vfn00();
    virtual Elem5ece20* Allocate(unsigned int n);
    virtual void Free(Elem5ece20* p);
    Elem5ece20* data;
    unsigned int size;
    unsigned int capacity;
    __forceinline void SetSize(unsigned int n)
    {
        if (n == 0) {
            if (data) {
                Free(data);
                data = 0;
                capacity = 0;
                size = 0;
            }
        } else if (n > capacity) {
            if (capacity == 0)
                data = Allocate(n);
            else
                ((f3m_005eb150::Container*)this)->FUN_005eb150(n, size);
            capacity = n;
            size = n;
        } else if (n < size) {
            size = n;
            if (n <= capacity >> 2) {
                ((f3m_005eb150::Container*)this)->FUN_005eb150(n, n);
                capacity = n;
            }
        } else {
            size = n;
        }
    }
    void FUN_005ece20(Array5ece20* out);
};
// pdb: BSSimpleArray<NavMeshEdgeLocation,1024>::CopyTo<1024> | PathBuilder.obj | fnv360_0822_retail, call_gap, low
// pdb params: aDestArray
void Array5ece20::FUN_005ece20(Array5ece20* out)
{
    out->SetSize(this->size);
    for (unsigned int i = 0; i < this->size; ++i)
        out->data[i] = data[i];
}
}
}   // namespace f3m_005ece20

// @f3 0x005f09e0 (community match, verified in this file)
namespace f3m_005f09e0 {
struct Entry5f09e0 {
    int unk00;
    int unk04;
    bool unk08;
};
struct List5f09e0 {
    int unk00;
    Entry5f09e0* data;
    unsigned int count;
    int unk0c;
    int unk10;
    List5f09e0(int a, int b, int c);
    ~List5f09e0();
};
struct Owner5f09e0 { char pad[0xa1]; bool unka1; };
struct Flag5f09e0 { char pad[0x40]; bool unk40; void Set() { unk40 = true; } };
class Proc5f09e0 {
public:
    Owner5f09e0* unk00;
    Flag5f09e0* unk04;
    int unk08;
    bool FUN_005ed080(List5f09e0* list);
    bool FUN_005f0070(int a, int b);
    bool FUN_005eccd0(int a, int b);
    bool FUN_005f09e0();
};
// pdb: PathBuilder::BuildDetailedPathForLoadedVirtualNodes | PathBuilder.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pActor
bool Proc5f09e0::FUN_005f09e0()
{
    List5f09e0 list(0, 0, unk08);
    if (!FUN_005ed080(&list))
        return false;
    bool flag = unk00->unka1;
    for (unsigned int i = 0; i < list.count; i++) {
        Entry5f09e0* e = &list.data[i];
        bool ok;
        if (e->unk08) {
            if (i > 0 && e[-1].unk08 && !flag) { unk04->Set(); return false; }
            ok = FUN_005f0070(e->unk00, e->unk04);
            if (ok) continue;
            if (!flag) return false;
        }
        ok = FUN_005eccd0(e->unk00, e->unk04);
        if (!ok) return false;
    }
    return true;
}
}   // namespace f3m_005f09e0

// @f3 0x005f3c10 (community match, verified in this file)
namespace f3m_005f3c10 {
namespace f3m_005f3c10 {
struct Local
{
    int m00; int m04; int m08; int m0C; int m10; int m14; int m18; int m1C; int m20;
    Local(unsigned int a, unsigned int b, unsigned int c);
    bool FUN_005fda30(int flag);
    virtual ~Local() {}
};
struct Elem
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    Elem(const Local& src);
};
struct Arr { int FUN_005eb230(); };
struct Owner
{
    int unk00;
    int unk04;
    Arr m_arr;
    Elem* m_data;
    int FUN_005f3c10(unsigned int a, unsigned int b, unsigned int c);
};

int Owner::FUN_005f3c10(unsigned int a, unsigned int b, unsigned int c)
{
    Local local(a, b, c);
    local.FUN_005fda30(0);
    int index = m_arr.FUN_005eb230();
    Elem* slot = &m_data[index];
    new (slot) Elem(local);
    return index;
}
}
}   // namespace f3m_005f3c10

// @f3 0x005e1810 (community match, verified in this file)
extern unsigned int DAT_00e27ed4;
namespace f3m_005e1810 {
struct Pointer {void* p; Pointer() : p(0) {} };
struct Vertex { unsigned short unk00; bool unk02,unk03,unk04,unk05,unk06; };
struct Edge {
 Vertex* unk00; Vertex* unk04; unsigned short unk08,unk0a,unk0c,unk0e;
 int unk10; unsigned short unk14,unk16; bool unk18,unk19; unsigned short unk1a;
 Pointer unk1c; int unk20; unsigned short unk24,unk26; int unk28; unsigned short unk2c; bool unk2e;
 Edge(Vertex* a,Vertex* b,int kind) {unk00=a;unk04=b;unk08=0xffff;unk0a=0xffff;unk0c=0xffff;unk0e=0xffff;unk10=kind;unk16=0;unk18=false;unk19=false;unk14=0xffff;unk20=0;unk24=0xffff;unk28=-1;unk2c=0xffff;unk2e=false;}
};
template<class T> struct Array {
 virtual void destroy(); virtual T* alloc(unsigned n); virtual void free(T* p); virtual T* realloc(T* p,unsigned n);
 T* unk04; unsigned unk08,unk0c;
 void Add(T value) {
  if(unk08==unk0c) {
   if(!unk0c) { unk04=alloc(4); unk0c=4; }
   else {unsigned n=unk0c>1024 ? unk0c+1024:unk0c*2;
    T* p;if(unk04) p=realloc(unk04,n);else {p=alloc(n);unk0c=n;}
    unk0c=n;unk04=p;
   }
  }
  ++unk08;unk04[unk08-1]=value;
 }
};
struct Triangle {unsigned short vertexIndices[3];unsigned short adjacentTriangles[3];unsigned unk0c;
 unsigned GetEdgeFlags(unsigned char edge) const {return (unk0c>>(edge*6+16));}
};
struct Vec3 {float x,y,z;};
struct Mesh {
 Vec3* GetVertex(unsigned short i){return &unk2c[i];}
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
 Vec3* unk2c;int unk30,unk34,unk38;Triangle* unk3c;
 bool NavMesh_GetMatchingEdge(unsigned short,int,void**,unsigned short*,unsigned int*);
 void FUN_005be400(unsigned short,void**);
};
struct ShortArr {void* vt;unsigned short* unk04;unsigned unk08,unk0c;
 const unsigned short& operator[](unsigned i) const {return unk04[i];}
 unsigned Find(const unsigned short& v) const {for(unsigned i=0;i<unk08;++i) if(unk04 && unk04[i]==v) return i; return (unsigned)-1;}
};
struct Input {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;ShortArr unk20;};
struct Arena {int unk00,unk04,unk08,unk0c;void* ScrapHeap_Allocate(unsigned,unsigned);};
struct Builder {
 Mesh* unk00;int unk04;Input* unk08;Arena unk0c;Array<Vertex*> unk1c;int unk2c;Array<Edge*> unk30;
 bool FUN_005df730(Vec3*);
 bool InArea(Vertex* v){return FUN_005df730(unk00->GetVertex(v->unk00));}
 unsigned FindVertex(unsigned short id) {for(unsigned i=0;i<unk1c.unk08;++i) if(unk1c.unk04[i]->unk00==id) return i; return (unsigned)-1;}
 void FUN_005e1810();
};
// pdb: NavMeshObstacleCutter::GenerateOutsideVertsAndEdges | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
void Builder::FUN_005e1810() {
 for(unsigned t=0;t<unk08->unk20.unk08;++t) {
  Triangle* tri=&unk00->unk3c[unk08->unk20[t]];
  int e;unsigned short* adj;
  for(e=0,adj=tri->adjacentTriangles;e<3;++e,++adj) {
   bool exterior=false,boundary=false;int kind;
   if(tri->unk0c & (1<<e)) {kind=4;boundary=true;}
   else if(*adj==65535) {kind=3;boundary=true;}
   else {
    unsigned short neighbor=*adj;
    if(unk08->unk20.Find(neighbor)!=(unsigned)-1) continue;
    kind=2;exterior=true;
   }
   unsigned short ids[2];ids[0]=adj[-3];ids[1]=tri->vertexIndices[(e+1)%3];
   Vertex* ends[2];
   for(unsigned k=0;k<2;++k) {
    unsigned i=FindVertex(ids[k]);
    if(i==(unsigned)-1) {
     Vertex* v=(Vertex*)unk0c.ScrapHeap_Allocate(8,DAT_00e27ed4);
     if(v) {v->unk00=ids[k];v->unk02=false;v->unk03=exterior;v->unk04=boundary;v->unk05=false;v->unk06=false;}
     v->unk05=(!v->unk03&&!v->unk04)?InArea(v):true;
     unk1c.Add(v);ends[k]=v;
    } else {
     unk1c.unk04[i]->unk03=unk1c.unk04[i]->unk03||exterior;
     unk1c.unk04[i]->unk04=unk1c.unk04[i]->unk04||boundary;
     ends[k]=unk1c.unk04[i];
    }
   }
   Edge* edge=(Edge*)unk0c.ScrapHeap_Allocate(48,DAT_00e27ed4);
   if(edge) new(edge) Edge(ends[0],ends[1],kind);
   if(kind==2) {
    unsigned short linkedTri;unsigned int linkedEdge;void* linkedMesh;
    if(unk00->NavMesh_GetMatchingEdge(unk08->unk20[t],e,&linkedMesh,&linkedTri,&linkedEdge)) {
     if(edge->unk08==65535) {edge->unk08=linkedTri;edge->unk0c=linkedEdge;}
     else if(edge->unk0a==65535) {edge->unk0a=linkedTri;edge->unk0e=linkedEdge;}
    }
   }else if(kind==3) unk00->FUN_005be400(unk08->unk20[t],&edge->unk1c.p);
   else if(kind==4) {edge->unk20=0;edge->unk24=unk08->unk20[t];edge->unk28=e;edge->unk2c=*adj;}
   unk30.Add(edge);
   if((unsigned)e<2) {unsigned f=tri->GetEdgeFlags((unsigned char)e);edge->unk16=f&15;*(volatile bool*)&edge->unk18=(f&16)>0;edge->unk19=(f&32)>0;}
  }
 }
}
}   // namespace f3m_005e1810

// @f3 0x005fb040 (community match, verified in this file)
namespace f3m_005fb040 {
namespace path3108 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern __declspec(thread) int DAT_0117c298;struct AutoMemHelper {int previous;AutoMemHelper(int v):previous(DAT_0117c298){DAT_0117c298=v;}~AutoMemHelper(){DAT_0117c298=previous;}};
struct NiPoint3 {float x,y,z;NiPoint3(){}NiPoint3(float a,float b,float c):x(a),y(b),z(c){}NiPoint3 operator-(const NiPoint3&r)const{return NiPoint3(x-r.x,y-r.y,z-r.z);}NiPoint3 operator+(const NiPoint3&r)const{return NiPoint3(x+r.x,y+r.y,z+r.z);}NiPoint3 operator*(float f)const{return NiPoint3(x*f,y*f,z*f);}float NiPoint3_UnitizeGetLength();};struct ClosePointAccess:NiPoint3 {};
struct NavMeshInfo;
struct RefBase {virtual void v0();virtual void Destroy();long refs;void Release(){if(InterlockedDecrement(&refs)==0)Destroy();}};struct NavMesh {int unk0;int unk4;int unk8;int unkC;int unk10;int unk14;int unk18;RefBase ref;};struct CloseMeshAccess:NavMesh {const NavMeshInfo* FUN_005b84c0();NiPoint3 FUN_004d45e0(unsigned short);};struct NavMeshPtr {NavMesh* mesh;NavMeshPtr():mesh(0){}~NavMeshPtr(){if(mesh)mesh->ref.Release();}};struct CloseMeshPointerAccess:NavMeshPtr {NavMesh* FUN_00458b50(){return mesh;}};
struct PathingLocation {virtual ~PathingLocation(){} NiPoint3 position;int unk10;int unk14;int unk18;int unk1C;int unk20;unsigned short unk24;unsigned char locationFlags,unk27;PathingLocation(const PathingLocation&);PathingLocation(const NiPoint3&,const NavMeshInfo*);bool FUN_005fcc10();bool FUN_005fc8f0(NavMeshPtr&,unsigned short&);bool FUN_005fda30(int);NiPoint3& GetLocation(){return position;}};struct CloseLocationAccess:PathingLocation {bool FUN_006a9520(){return (locationFlags&2u)>0;}};
struct PathingRequestClosePoint {int unk0;int unk4;int unk8;PathingLocation origin,target;int unk5C;int unk60;int unk64;float radius;int unk6C;int unk70;int unk74;int unk78;int unk7C;int unk80;int unk84;int unk88;int unk8C;float extra;int unk94;int unk98;int unk9C;bool adjust;};struct CloseRequestAccess:PathingRequestClosePoint {PathingLocation& GetOffsetC(){return origin;}PathingLocation* FUN_006a9540(){return &target;}float GetFloatAtOffset68(){return radius;}bool FUN_006ca4c0(){return adjust;}float GetField90Float(){return extra;}};
struct CloseNodeAccess {int flags;PathingLocation location;NiPoint3 point;int unk38;NiPoint3* FUN_00717e50(){return (NiPoint3*)&location;}void FUN_006b0570(const NiPoint3*p){point=*p;}};
struct PathingSolution {int unk0;int unk4;int unk8;int unkC;int unk10;int unk14;unsigned currentNode,nextNode;int unk20;CloseNodeAccess* nodes;unsigned nodeCount;int unk2C;int unk30;int unk34;int unk38;int unk3C;unsigned char failed;void FUN_005ec000(const NiPoint3&,const NavMeshInfo*);};struct CloseSolutionAccess:PathingSolution {unsigned GetNodeCount(){return nodeCount;}CloseNodeAccess* FUN_006e7970(unsigned i){return nodes+i;}void SetByteAtOffset40(int b){failed=b;}};
struct CloseTriangle
{
    CloseMeshAccess* mesh;
    unsigned short triangle;
    unsigned short flags;
    float cost;
    unsigned int parent;
    unsigned int state;
};
template <class T> struct CloseArray
{
    void* table;
    T* buffer;
    unsigned int size;
    unsigned int capacity;
};
struct CloseTriangleArray : CloseArray<CloseTriangle>
{
    void* allocator;
    CloseTriangleArray(int, int, void*);
    ~CloseTriangleArray();
    unsigned int GetFlags(){return size;}
    CloseTriangle& FUN_006b3160(unsigned int n){return buffer[n];}
};
struct CloseLinkArray : CloseArray<unsigned int>
{
    void* allocator;
    CloseLinkArray(int, int, void*);
    ~CloseLinkArray();
};
struct ClosePointArray : CloseArray<NiPoint3>
{
    void* allocator;
    ClosePointArray(int, int, void*);
    ~ClosePointArray();
};
struct CloseSearchBase
{
    void* table;
    void* poolBegin;
    void* poolEnd;
    void* poolCursor;
    unsigned int poolCapacity;
    void* buckets[2039];
    unsigned int bucketCount;
    float heapScale;
    void* heapBuckets[20];
    void* current;
    void* goal;
    unsigned int iterations;
    bool completed;
};
struct ClosePointSearch : CloseSearchBase
{
    PathingRequestClosePoint* request;
    NiPoint3 target;
    float radius;
    unsigned int flags;
    NiPoint3 origin;
    float bestDistance;
    bool found;
    NiPoint3 nearest;
    ClosePointSearch();
    ~ClosePointSearch();
    bool StartFleeSearch(PathingRequestClosePoint*, CloseTriangle*, CloseTriangleArray*, CloseLinkArray*);
};
struct ClosePathSmoother : CloseSearchBase
{
    PathingRequestClosePoint* request;
    PathingSolution* solution;
    NiPoint3 origin;
    NiPoint3 goalPoint;
    bool hasGoal;
    unsigned int segment;
    unsigned int node;
    CloseArray<NiPoint3> points;
    CloseArray<NiPoint3> normals;
    CloseArray<NiPoint3> edges;
    CloseArray<NiPoint3> corners;
    unsigned int startIndex;
    unsigned int endIndex;
    CloseArray<unsigned int> links;
    CloseArray<float> costs;
    CloseArray<void*> incoming;
    CloseArray<void*> outgoing;
    unsigned int result;
    ClosePathSmoother();
    ~ClosePathSmoother();
    bool FUN_006ad770(PathingRequestClosePoint*, CloseTriangleArray*, CloseLinkArray*, const NiPoint3&, const NiPoint3&,
                      PathingSolution*, int, int);
};

typedef PathingLocation CloseEndLocation;struct ClosePointPair {NiPoint3 first,second;};bool FUN_005f3cb0(PathingRequestClosePoint*,PathingSolution*);bool FUN_005f9620(PathingLocation*,float,ClosePointPair*);void FUN_005f27d0(NiPoint3*,float,PathingLocation*,PathingLocation*,float);
bool FUN_005fb040(PathingRequestClosePoint* request, PathingSolution* solution)
{
    AutoMemHelper eb(45);
    if (!((CloseLocationAccess*)&((CloseRequestAccess*)request)->GetOffsetC())->FUN_005fcc10())
        return FUN_005f3cb0(request, solution);
    NavMeshPtr h;
    unsigned short q = 0xffff;
    if (!((CloseRequestAccess*)request)->GetOffsetC().FUN_005fc8f0(h, q))
        return FUN_005f3cb0(request, solution);
    if (!((CloseLocationAccess*)((CloseRequestAccess*)request)->FUN_006a9540())->FUN_006a9520())
    {
        if (!((CloseLocationAccess*)((CloseRequestAccess*)request)->FUN_006a9540())->FUN_005fda30(0))
            return FUN_005f3cb0(request, solution);
        NavMeshPtr targetMesh;
        unsigned short targetTriangle = 0xffff;
        if (!((CloseRequestAccess*)request)->FUN_006a9540()->FUN_005fc8f0(targetMesh, targetTriangle))
            return FUN_005f3cb0(request, solution);
    }
    CloseTriangle f;
    f.mesh = (CloseMeshAccess*)((CloseMeshPointerAccess*)&h)->FUN_00458b50();
    f.triangle = q;
    NiPoint3 a = ((CloseRequestAccess*)request)->GetOffsetC().GetLocation();
    ClosePointSearch p;
    CloseTriangleArray ba(32, 0, 0);
    CloseLinkArray s(32, 0, 0);
    if (!p.StartFleeSearch(request, &f, &ba, &s))
        return false;
    CloseTriangle i = ba.FUN_006b3160(ba.GetFlags() - 1);
    NiPoint3 e = i.mesh->FUN_004d45e0(i.triangle);
    CloseEndLocation b(e, i.mesh->FUN_005b84c0());
    { ClosePointPair k;
    if (FUN_005f9620((PathingLocation*)&b, ((CloseRequestAccess*)request)->GetFloatAtOffset68(), &k))
    {
        NiPoint3 j = e - k.second;
        float p = ((ClosePointAccess*)&j)->NiPoint3_UnitizeGetLength();
        if (p < ((CloseRequestAccess*)request)->GetFloatAtOffset68())
            e = k.second + j * ((CloseRequestAccess*)request)->GetFloatAtOffset68();
    }
    }
    ((CloseSolutionAccess*)solution)->FUN_005ec000(a, f.mesh->FUN_005b84c0());
    ((CloseSolutionAccess*)solution)->FUN_005ec000(e, i.mesh->FUN_005b84c0());
    ((CloseSolutionAccess*)solution)->currentNode = 0;
    ((CloseSolutionAccess*)solution)->nextNode = 1;
    ClosePathSmoother l;
    ClosePointArray c(32, 0, 0);
    bool cf = l.FUN_006ad770(request, &ba, &s, a, e, solution, 0, 0);
    if (cf)
    {
        if (((CloseRequestAccess*)request)->FUN_006ca4c0() && ((CloseSolutionAccess*)solution)->GetNodeCount() > 2)
        {
            CloseNodeAccess* j = ((CloseSolutionAccess*)solution)->FUN_006e7970(0);
            CloseNodeAccess* h = ((CloseSolutionAccess*)solution)->FUN_006e7970(1);
            if (j && h)
            {
                PathingLocation e(j->location);
                PathingLocation p(h->location);
                NiPoint3 i;
                FUN_005f27d0(&i, ((CloseRequestAccess*)request)->GetField90Float(), &e, &p,
                             ((CloseRequestAccess*)request)->GetFloatAtOffset68());
                j->FUN_006b0570(&i);
            }
        }
    }
    else
    {
        ((CloseSolutionAccess*)solution)->SetByteAtOffset40(1);
    }
    return cf;
}

}
}   // namespace f3m_005fb040

// @f3 0x005e5070 (community match, verified in this file)
namespace QueueInsert2263 {
extern __declspec(thread) int DAT_0117c298;
struct Tag {
    int previous;
    Tag(int value):previous(DAT_0117c298){DAT_0117c298=value;}
    ~Tag(){DAT_0117c298=previous;}
};
struct Heap {void* FUN_0086b930(unsigned);};
extern Heap DAT_01090a78;
struct Node {
    Node* volatile next;
    void* data;
    Node() throw():next(0),data(0){}
    static void* operator new(unsigned size) throw(){return DAT_01090a78.FUN_0086b930(size);}
};
typedef Node* (__stdcall* CompareExchange)(Node* volatile*,Node*,Node*);
extern CompareExchange DAT_00d9b06c;
struct Queue {
    virtual void Slot0();
    virtual void Slot1();
    virtual void OnEnqueue();
    Node* head;
    Node* tail;
};
inline void finish(CompareExchange ex, Queue* q, Node* n, Node* prev) { ex(&q->tail,n,prev); }
struct Owner {
    Queue* queue;
    Node* volatile* hazard;
    void FUN_005e5070(void* const*);
};
// pdb: LockFreeQueue<bhkRigidBody *>::LockFreeQueueInterface::Push | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: arData
void Owner::FUN_005e5070(void* const* data) {
    Tag tag(6);
    Node* volatile observed=0;
    Node* node=new Node;
    void* payload=*data;
    CompareExchange exchange=DAT_00d9b06c;
    node->data=payload;
    for(;;) {
        observed=queue->tail;
        *hazard=observed;
        if(observed!=queue->tail)
            continue;
        Node** tail=&queue->tail;
        Node* next=observed->next;
        if(observed!=*tail)
            continue;
        Node* last=observed;
        if(next) {
            exchange(&queue->tail,next,last);
            continue;
        }
        if(exchange(&last->next,node,0))
            continue;
        queue->OnEnqueue();
        finish(exchange,queue,node,observed);
        break;
    }
    *hazard=0;
}
}

// @f3 0x005ea710 (community match, verified in this file)
#include <windows.h>
namespace f3m_005ea710 {

namespace f3m_005ea710 {

struct S5ea710_Ref;
struct S5ea710_VT { void* unk00; void (__thiscall *Destroy)(S5ea710_Ref*); };
struct S5ea710_Ref { S5ea710_VT* vtable; long count; };


struct S5ea710_Group;

struct S5ea710_Target {
    int unk00; int unk04; int unk08; void* unk0C; int unk10; int unk14; int unk18;
    S5ea710_Ref ref;
    S5ea710_Group* FUN_005b8480();
    void FUN_005bb120(void* a);
    void FUN_005b84d0(void* a);
};

struct S5ea710_Ptr {
    S5ea710_Target* value;
    S5ea710_Ptr(S5ea710_Target* p) {
        value = p;
        if (p) InterlockedIncrement(&p->ref.count);
    }
    ~S5ea710_Ptr();
};

struct S5ea710_List {
    void NavMeshArray_AddNavMesh(S5ea710_Ptr p);
    void FUN_005c2740(S5ea710_Ptr p);
};

struct S5ea710_Group {
    S5ea710_List* FUN_007e55b0();
};

struct S5ea710_Node {
    void FUN_005d89b0(S5ea710_Target* t);
};

struct S5ea710_Entry {
    int unk00; int unk04; int unk08; int unk0C;
};

struct S5ea710_Elem {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    S5ea710_Node* unk18;
    S5ea710_Target* unk1C;
    S5ea710_Target* unk20;
    int unk24;
    S5ea710_Entry* unk28;
    unsigned int unk2C;
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50;
    bool unk54;
    bool FUN_005ea710();
};

// pdb: ObstacleTaskData::ReplaceNavMesh | NavMeshObstacleTask.obj | fnv360_0822_retail, call_seq, medium
bool S5ea710_Elem::FUN_005ea710() {
    S5ea710_Target* first = unk1C;
    if (!first || !unk20)
        return false;
    if (!unk54) {
        for (unsigned int i = 0; i < unk2C; i++) {
            if (unk28[i].unk08 == 0)
                goto found;
        }
        return false;
    }
found:
    void* saved = unk1C->unk0C;
    S5ea710_Group* group = unk1C->FUN_005b8480();
    if (group) {
        group->FUN_007e55b0()->NavMeshArray_AddNavMesh(unk20);
        group->FUN_007e55b0()->FUN_005c2740(unk1C);
    }
    unk1C->FUN_005bb120(0);
    unk1C->FUN_005b84d0(0);
    unk20->FUN_005bb120(saved);
    unk20->FUN_005b84d0(unk18);
    unk18->FUN_005d89b0(unk20);
    return true;
}

}
}   // namespace f3m_005ea710

// @f3 0x005e8d50 (community match, verified in this file)
namespace f3m_005e8d50 {
namespace mf5e8d50 {

struct MapItem;
struct Group;
struct Item;
struct Resource;

struct RefObj {
    virtual void v00();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (InterlockedDecrement(&refs) == 0) DeleteThis(); }
};

template <class T> class Ptr {
public:
    T* m_pObject;
    Ptr(T* o) { m_pObject = o; if (m_pObject) m_pObject->IncRefCount(); }
    ~Ptr() { if (m_pObject) m_pObject->DecRefCount(); }
    T* operator->() const { return m_pObject; }
};

template <class T> class OwnedPtr {
public:
    T* m_pObject;
    OwnedPtr() : m_pObject(0) {}
    ~OwnedPtr() { if (m_pObject) m_pObject->DecRefCount(); }
    T* operator->() const { return m_pObject; }
};

template <class T> class NiPtr {
public:
    T* m_pObject;
    NiPtr() { m_pObject = 0; }
    ~NiPtr() { if (m_pObject) m_pObject->DecRefCount(); }
    T* operator->() const { return m_pObject; }
};

struct Map {
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    MapItem* GetFirstPos() const {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        return 0;
    }
    __declspec(noalias) void FUN_00ad3cc0(MapItem*& pos, unsigned int& key, OwnedPtr<Group>& val);
    void FUN_006bd950();
};

struct Group : RefObj {
    int unk08;
    int unk0C;
    Item** data;
    unsigned int count;
    Item*& GetAt(unsigned int i) { return data[i]; }
};

struct Listener {
    void hkpEntity_removeEntityActivationListener(void* p);
    void FUN_0090b960(void* p);
};

struct ItemSrc {
    int unk00;
    int unk04;
    Listener* unk08;
};

inline void AttachA(ItemSrc* src, void* arg)
{
    if (src && src->unk08)
        src->unk08->hkpEntity_removeEntityActivationListener(arg);
}

inline void AttachB(ItemSrc* src, void* arg)
{
    if (src && src->unk08)
        src->unk08->FUN_0090b960(arg);
}

template <class T> class NiPtr;
struct Entry {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    Resource* unk54;
    bool Load(NiPtr<Resource>* out);
};

struct Array {
    void* unk00;
    Entry** data;
    unsigned int size;
    unsigned int capacity;
    Entry*& GetAt(unsigned int i) { return data[i]; }
};

struct Item : RefObj {
    int unk08;
    ItemSrc* src;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    Array list;
};

struct Counter {
    virtual void v00();
    virtual void DeleteThis();
    long refs;
    void Release() { if (InterlockedDecrement(&refs) == 0) DeleteThis(); }
};

struct Resource {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Counter counter;
    void DecRefCount() { counter.Release(); }
    void FUN_005c1610();
};

struct Node {
    unsigned int key;
    Node* next;
    void FUN_006c8220();
};

struct Obj3C {
    int unk00;
    int unk04;
    void FUN_005e3010();
};

struct Obj8C20 {
    int unk00;
    void* head;
    void* tail;
    int unk0C;
    int unk10;
    void* table;
    int unk18;
    void FUN_005e8c20(bool keep);
};

struct Obj13CSub {
    void FUN_00aaab30();
};

struct Obj13C {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    Obj13CSub sub9C;
};

__declspec(noalias) void __cdecl FUN_005b87d0(NiPtr<Resource>* out, void* source);

inline bool Entry::Load(NiPtr<Resource>* out)
{
    FUN_005b87d0(out, unk54);
    return unk54 != 0;
}

struct Cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Map map1C;
    Node node2C;
    Node node34;
    Obj3C obj3C;
    Obj8C20 obj44;
    Obj8C20 obj60;
    Map map7C;
    Node node8C;
    Node node94;
    Map map9C;
    Map mapAC;
    void* unkBC;
    void* unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    unsigned char valid138;
    char unk139;
    short unk13A;
    Obj13C* ptr13C;
    void FUN_005e8d50();
};

// pdb: NavMeshObstacleManager::ClearAllObstacles | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
void Cls::FUN_005e8d50()
{
    OwnedPtr<Group> val;
    MapItem* pos = map1C.GetFirstPos();
    unsigned int key;
    while (pos) {
        map1C.FUN_00ad3cc0(pos, key, val);
        for (unsigned int i = 0; i < val->count; i++) {
            Ptr<Item> item(val->GetAt(i));
            Node* node = &node34;
            while (node && node->key != key)
                node = node->next;
            if (!node) {
                ItemSrc* src = item->src;
                AttachA(src, unkBC);
                AttachB(src, unkC0);
            }
            for (unsigned int j = 0; j < item->list.size; j++) {
                NiPtr<Resource> res;
                if (item->list.GetAt(j)->Load(&res))
                    res->FUN_005c1610();
            }
        }
    }
    map1C.FUN_006bd950();
    map9C.FUN_006bd950();
    mapAC.FUN_006bd950();
    map7C.FUN_006bd950();
    node8C.FUN_006c8220();
    node94.FUN_006c8220();
    node2C.FUN_006c8220();
    node34.FUN_006c8220();
    obj3C.FUN_005e3010();
    obj44.FUN_005e8c20(false);
    obj60.FUN_005e8c20(false);
    if (valid138) {
        if (ptr13C)
            ptr13C->sub9C.FUN_00aaab30();
        valid138 = 0;
    }
}

}
}   // namespace f3m_005e8d50

// @f3 0x005f16b0 (community match, verified in this file)
#include <math.h>

namespace S5f16b0_ns {

extern void* DAT_00dc4dc0[];

struct S5f16b0_Point3
{
    float x, y, z;
    S5f16b0_Point3() {}
    S5f16b0_Point3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

struct S5f16b0_Rng { unsigned int FUN_0086c4b0(unsigned int range); };
S5f16b0_Rng* FUN_0044a2d0();

inline float S5f16b0_RandomRange(float lo, float hi)
{
    S5f16b0_Rng* rng = FUN_0044a2d0();
    unsigned int uiRand = rng->FUN_0086c4b0(0xffffffff);
    return lo + (hi - lo) * (float)uiRand * 2.3283064365386963e-10;
}

struct S5f16b0_RefObject {
    void** vtable;
    long refs;
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(S5f16b0_RefObject*))vtable[1])(this);
    }
};

struct S5f16b0_NavMesh
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    S5f16b0_RefObject ref1C;

    void DecRefCount() { ref1C.DecRefCount(); }
    bool FUN_005c0690(const S5f16b0_Point3* pos, float range, S5f16b0_Point3* out);
    bool FUN_005bf000(S5f16b0_Point3* out, int flag);
    bool FUN_005becd0(const S5f16b0_Point3* pos, unsigned int* triangle, bool* flag);
    __declspec(noinline) S5f16b0_Point3 FUN_004d45e0(unsigned int triangle) const {
        return S5f16b0_Point3((float)triangle, (float)triangle, (float)triangle);
    }
};

struct S5f16b0_NavPtr
{
    S5f16b0_NavMesh* m_pObject;
    S5f16b0_NavPtr() : m_pObject(0) {}
    ~S5f16b0_NavPtr() { if (m_pObject) m_pObject->DecRefCount(); }
    S5f16b0_NavMesh* operator->() const { return m_pObject; }
};

struct S5f16b0_Locator
{
    void** vtable;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;

    S5f16b0_Locator(const S5f16b0_Point3* pos, void* second, void* first) { FUN_005fd540(pos, second, first); }
    ~S5f16b0_Locator() { vtable = DAT_00dc4dc0; }
    void FUN_005fd540(const S5f16b0_Point3*, void*, void*);
    bool FUN_005fda30(int flag);
    bool FUN_005fc8b0(S5f16b0_NavPtr& nav);
};

}

using namespace S5f16b0_ns;

// pdb: Pathing::FindPointOnNavMesh | Pathfind.obj | fnv360_0721_retail, call_seq, medium
// pdb params: apWorldSpace, apCell, aLocation, aRadius, apRetPt
bool __cdecl FUN_005f16b0(void* apInfo, void* apCell, const S5f16b0_Point3& arPos, float afRange, S5f16b0_Point3& arOut)
{
    S5f16b0_Locator kLocator(&arPos, apCell, apInfo);
    bool bValid = true;
    if (!kLocator.FUN_005fda30(0))
        bValid = false;
    S5f16b0_NavPtr spNav;
    bool bUseNav = kLocator.FUN_005fc8b0(spNav) && bValid;
    if (!bUseNav)
    {
        float fX = S5f16b0_RandomRange(-afRange, afRange);
        float fHalf = (float)sqrt(afRange * afRange - fX * fX);
        fHalf = S5f16b0_RandomRange(-fHalf, fHalf);
        arOut = S5f16b0_Point3(arPos.x + fX, arPos.y + fHalf, arPos.z + 0.0);
        return true;
    }
    if (!spNav->FUN_005c0690(&arPos, afRange, &arOut) || !spNav->FUN_005bf000(&arOut, 0))
    {
        unsigned int uiTriangle = 0xffff;
        bValid = false;
        if (!spNav->FUN_005becd0(&arPos, &uiTriangle, &bValid))
            return false;
        arOut = spNav->FUN_004d45e0(uiTriangle);
    }
    return true;
}

// @f3 0x005ec160 (community match, verified in this file)
namespace f3m_005ee5a0 {
namespace Task2282 {

struct S005ec160_Node
{
    NiPoint3* FUN_004e7580();
    void* TESObjectREFR_GetTeleport();
};

struct S005ec160_Mesh
{
    NiPoint3* FUN_00bd8090();
};

struct S005ec160_Request
{
    int unk00;
    int unk04;
    int unk08;
    FUN_005fd540 start;
    FUN_005fd540 goal;
    FUN_005fd540 third;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    unsigned char unk98;
    unsigned char unk99;
    unsigned char unk9a;
    unsigned char unk9b;
    int unk9c;
    int unka0;
    unsigned char unka4;
};

struct S005ec160_Solution
{
    void* FUN_005ebf20(const FUN_005fd540&);
    void FUN_005ebf90(void*);
    int FUN_005ec080(void* info, NiPoint3* point, S005ec160_Node* node);
    void FUN_005ec000(const NiPoint3& point, void* info);
};

struct S005ec160_Handler
{
    S005ec160_Request* m_request;
    S005ec160_Solution* m_pPathingSolution;
    void* m_unk08;

    bool FUN_005ec160(void* a1, void* a2);
};

bool S005ec160_Handler::FUN_005ec160(void* a1, void* a2)
{
    FUN_005dbb40 search;
    FUN_005eb4b0 route(20, 0, m_unk08);
    FUN_005eb5e0 transitions(20, 0, m_unk08);

    FUN_005fd540* third = 0;
    if (!m_request->unk98)
        third = &m_request->third;
    unsigned char flag = m_request->unka4;
    int smooth = flag != 0;
    bool ok;
    {
        NiPoint3 goal = m_request->goal.FUN_005c3420();
        NiPoint3 start = m_request->start.FUN_005c3420();
        ok = search.FUN_005dc8d0((int)third, start, a1, goal, a2, &route, &transitions, smooth);
    }

    if (route.FUN_0044ddc0() <= 1)
    {
        m_pPathingSolution->FUN_005ebf20(m_request->start);
        m_pPathingSolution->FUN_005ebf20(m_request->goal);
    }
    else
    {
        m_pPathingSolution->FUN_005ebf20(m_request->start);
        if (((void**)transitions.unk04)[0])
        {
            S005ec160_Node* node = (S005ec160_Node*)((void**)transitions.unk04)[0];
            NiPoint3 pos = *node->FUN_004e7580();
            m_pPathingSolution->FUN_005ec080(route.data[0], &pos, node);
            NiPoint3 dest = *((S005ec160_Mesh*)node->TESObjectREFR_GetTeleport())->FUN_00bd8090();
            m_pPathingSolution->FUN_005ec000(dest, route.data[1]);
        }
        for (unsigned int i = 1; i < route.FUN_0044ddc0() - 1; ++i)
        {
            if (((void**)transitions.unk04)[i])
            {
                S005ec160_Node* node = (S005ec160_Node*)((void**)transitions.unk04)[i];
                if (node)
                {
                    NiPoint3 pos = *node->FUN_004e7580();
                    m_pPathingSolution->FUN_005ec080(route.data[i], &pos, node);
                    NiPoint3 dest = *((S005ec160_Mesh*)node->TESObjectREFR_GetTeleport())->FUN_00bd8090();
                    m_pPathingSolution->FUN_005ec000(dest, route.data[i + 1]);
                }
            }
            else
            {
                m_pPathingSolution->FUN_005ebf90(route.data[i]);
            }
        }
        m_pPathingSolution->FUN_005ebf20(m_request->goal);
    }
    return ok;
}

}
}

// @f3 0x005e6bb0 (community match, verified in this file)
extern void* DAT_00e01b54;
namespace f3m_005e6bb0 {

extern void (__stdcall* const FUN_00d9b06c)(long*, long, long);
extern void (__stdcall* const FUN_00d9b074)(unsigned long);

struct BSTasklet {
    void* vptr;
    int value;
    BSTasklet() { vptr = &DAT_00e01b54; }
    ~BSTasklet() { vptr = &DAT_00e01b54; }
};
namespace f3m_005e6bb0 {
struct Lock {
    volatile long owner; long count;
    void FUN_00409a80(const char*);
    __forceinline void Unlock() { if (--count == 0) { long o = owner; FUN_00d9b06c((long*)&owner, 0L, o); } }
};
struct Mgr { bool FUN_00bce310(); };
Mgr* __stdcall FUN_00bce1f0(void* queue, BSTasklet* job, int flags);
int __cdecl FUN_00ae13c0(const void*, const void*);
struct List {
    void* unk00; int* data; unsigned count, capacity;
    unsigned FUN_005e5350();
    int FUN_00ae1370(void* key, int start, int (__cdecl* cmp)(const void*, const void*));
    void FUN_005e4fb0(int index, bool shrink);
};
struct Owner {
    char pad[0xc4];
    int unkC4;
    char pad2[0xd8 - 0xc8];
    List list;
    char pad3[0x100 - 0xe8];
    Lock lock;
    bool FUN_005e6bb0(int value);
};
// pdb: NavMeshObstacleManager::PushTask | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apTaskData
bool Owner::FUN_005e6bb0(int value)
{
    BSTasklet job;
    job.value = value;
    unsigned tries = 0;
    lock.FUN_00409a80(0);
    List* l = &list;
    l->data[l->FUN_005e5350()] = value;
    lock.Unlock();
    while (!FUN_00bce1f0(&unkC4, &job, 0)->FUN_00bce310()) {
        if (++tries >= 100) {
            lock.FUN_00409a80(0);
            int i = l->FUN_00ae1370(&value, 0, FUN_00ae13c0);
            if (i != -1)
                l->FUN_005e4fb0(i, true);
            lock.Unlock();
            return false;
        }
        FUN_00d9b074(0);
    }
    return true;
}
}
}   // namespace f3m_005e6bb0

// @f3 0x005ed080 (community match, verified in this file)
namespace f3m_005ed080 {
namespace S5ed080_ns {

struct S5ed080_Alloc;
struct S5ed080_NavInfo;

template <class T> struct S5ed080_Array
{
    virtual ~S5ed080_Array();
    virtual T* Allocate(unsigned int count);

    T* pBuffer;
    unsigned int iSize;
    unsigned int iCapacity;

    void Resize(unsigned int newCapacity, unsigned int count);

    void Clear()
    {
        if (pBuffer)
            iSize = 0;
    }

    __forceinline unsigned int GetNextIndex()
    {
        if (iSize == iCapacity)
        {
            if (!iCapacity)
            {
                pBuffer = Allocate(4);
                iCapacity = 4;
            }
            else
            {
                unsigned int newCapacity = iCapacity > 1024 ? iCapacity + 1024 : iCapacity * 2;
                Resize(newCapacity, iSize);
                iCapacity = newCapacity;
            }
        }
        ++iSize;
        return iSize - 1;
    }

    __forceinline unsigned int Add(const T& item)
    {
        unsigned int index = GetNextIndex();
        pBuffer[index] = item;
        return index;
    }

    int Find(const T& item, unsigned int start) const
    {
        for (unsigned int i = start; i < iSize; ++i)
        {
            if (pBuffer && pBuffer[i] == item)
                return i;
        }
        return -1;
    }
};

struct S5ed080_ScrapBools : S5ed080_Array<bool>
{
    S5ed080_Alloc* pAllocator;
    S5ed080_ScrapBools(unsigned int reserve, unsigned int count, S5ed080_Alloc* allocator);
    ~S5ed080_ScrapBools();
};

struct S5ed080_Location
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    void FUN_005fdde0();
    S5ed080_NavInfo* FUN_005fcbf0();
};

struct S5ed080_Node
{
    unsigned int uiFlags;
    S5ed080_Location kLocation;
    bool IsNew() const { return (uiFlags & 1) == 1; }
};

struct S5ed080_NavInfo
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    S5ed080_Array<S5ed080_NavInfo*> kLinked;
    S5ed080_Array<S5ed080_NavInfo*> kOverlaps;
};

struct S5ed080_Solution
{
    int unk00, unk04, unk08;
    S5ed080_Node* pNodes;
    int unk10, unk14;
    int iFirst;
    int iLast;
    S5ed080_Node* GetNode(int i) { return &pNodes[i]; }
};

struct S5ed080_Span
{
    int iStart;
    int iEnd;
    bool bNew;
    S5ed080_Span(int start, int end, bool isNew) : iStart(start), iEnd(end), bNew(isNew) {}
};

struct S5ed080_Builder
{
    void* pRequest;
    S5ed080_Solution* pSolution;
    S5ed080_Alloc* pAllocator;

    bool FUN_005ed080(S5ed080_Array<S5ed080_Span>& arSpans);
};

bool S5ed080_Builder::FUN_005ed080(S5ed080_Array<S5ed080_Span>& arSpans)
{
    arSpans.Clear();

    int iFirst = pSolution->iFirst;
    int iLast = pSolution->iLast;

    S5ed080_ScrapBools kNew(iLast - iFirst + 1, 0, pAllocator);

    for (int n = iFirst; n <= iLast; ++n)
    {
        S5ed080_Node* pNode = pSolution->GetNode(n);
        bool bNew = pNode->IsNew();
        kNew.Add(bNew);
    }

    int i = iFirst;
    while (i <= iLast)
    {
        int iOpen = kNew.Find(true, i - iFirst);
        if (iOpen != -1)
        {
            int iClose = kNew.Find(false, iOpen) - 1;
            if (iClose == -2)
                iClose = kNew.iSize - 1;

            iOpen += iFirst;
            iClose += iFirst;

            if (iOpen > i)
                arSpans.Add(S5ed080_Span(i, iOpen - 1, false));

            int iStart = iOpen;
            for (int m = iOpen; m + 1 <= iClose; ++m)
            {
                S5ed080_Node* pNode1 = pSolution->GetNode(m);
                S5ed080_Node* pNode2 = pSolution->GetNode(m + 1);
                pNode1->kLocation.FUN_005fdde0();
                pNode2->kLocation.FUN_005fdde0();
                S5ed080_NavInfo* pInfo1 = pNode1->kLocation.FUN_005fcbf0();
                S5ed080_NavInfo* pInfo2 = pNode2->kLocation.FUN_005fcbf0();
                if (!pInfo1 || !pInfo2)
                    return false;

                if (pInfo1 != pInfo2 && pInfo1->kLinked.Find(pInfo2, 0) == -1 && pInfo1->kOverlaps.Find(pInfo2, 0) == -1)
                {
                    arSpans.Add(S5ed080_Span(iStart, m, true));
                    iStart = m + 1;
                }
            }

            arSpans.Add(S5ed080_Span(iStart, iClose, true));
            i = iClose + 1;
        }
        else
        {
            arSpans.Add(S5ed080_Span(i, iLast, false));
            i = iLast + 1;
        }
    }
    return true;
}

}
}   // namespace f3m_005ed080

// @f3 0x005edc00 (community match, verified in this file)
namespace n5ee080 {

struct S005edc00_Owner {
    int unk00, unk04, unk08;
    PathingLocation kLocation;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    float f68;
    float GetFloatAtOffset68() { return f68; }
    PathingLocation* GetPathingLocation() { return &kLocation; }
};

// NiPoint3::operator= of Gamebryo (member-wise float copy)
inline void S005edc00_Assign(NiPoint3& ar_Dest, const NiPoint3& ar_Src)
{
    ar_Dest.x = ar_Src.x;
    ar_Dest.y = ar_Src.y;
    ar_Dest.z = ar_Src.z;
}

struct S005edc00_Builder {
    S005edc00_Owner* m_00;
    int m_04;
    int m_08;
    bool FUN_005edc00(ArgObj* a1, ArgObj* a0, PathingLocation* apOutLocation);
};

// pdb: PathBuilder::FindEntryPoint | PathBuilder.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPrevNode, apCurrentNode, aRetLocation
bool S005edc00_Builder::FUN_005edc00(ArgObj* a1, ArgObj* a0, PathingLocation* apOutLocation)
{
    a0->FUN_00717e50()->FUN_005fdde0();
    NiPointer<NavMesh> navPtr;
    if (!a0->FUN_00717e50()->FUN_005fcbf0()->GetNavMesh(navPtr))
        return false;
    if (IsFlag2((const int*)a0))
    {
        unsigned short wIdxW;
        int iIdxT;
        float zlen;
        zlen = (a1->FUN_00717e50()->GetLocation() - a0->FUN_00717e50()->FUN_005fcbf0()->m_10).Length();
        wIdxW = 0xffff;
        iIdxT = -1;
        if (navPtr->FUN_005bd410(a1->FUN_00717e50()->GetLocation(), zlen * 2.0, &wIdxW, &iIdxT, 1))
        {
            NiPoint3 upt4c;
            NiPoint3 pt34G;
            navPtr->FUN_005b8960(wIdxW, iIdxT, upt4c, pt34G);
            {
                NiPoint3 kPoint = navPtr->FUN_004d45e0(wIdxW);
                S005edc00_Assign(kPoint, (upt4c + pt34G) * 0.45f + kPoint * 0.1f);
                apOutLocation->FUN_005fc480(PathingLocation(kPoint, navPtr->FUN_005b84c0(), wIdxW));
            }
            return true;
        }
    }
    else
    {
        float ubest;
        TriArr zarr(0, 0, m_08);
        int bestIdxz;
        unsigned int ui;
        float tlen2;
        NavMeshTriangle* ttri;
        navPtr->FUN_005c1280(a1->FUN_00717e50()->FUN_005fcbf0(), &zarr);
        bestIdxz = 0xffff;
        ubest = FLT_MAX;
        ui = 0;
        for (; ui < zarr.GetSize(); ui++)
        {
            ttri = navPtr->GetTriangle(*(unsigned short*)zarr.GetAt(ui));
            if (m_00->GetFloatAtOffset68() > 150.0f && ttri->IsFlag4())
                continue;
            NiPoint3 pt84S = navPtr->FUN_004d45e0(*(unsigned short*)zarr.GetAt(ui));
            tlen2 = (pt84S - m_00->GetPathingLocation()->GetLocation()).Length();
            if (tlen2 < ubest)
            {
                tlen2 = ubest;
                bestIdxz = *zarr.GetAt(ui);
            }
        }
        if (bestIdxz != 0xffff)
        {
            apOutLocation->FUN_005fc480(PathingLocation(navPtr->FUN_004d45e0((unsigned short)bestIdxz), a0->FUN_00717e50()->FUN_005fcbf0(), (unsigned short)bestIdxz));
            return true;
        }
    }
    return false;
}

}

// @f3 0x005e1c70 (community match, verified in this file)
namespace f3m_005e2a10 {

unsigned short __cdecl FUN_005d1f20(float a_fHeight, bool a_b1, bool a_b2);

struct S5e1c70_Matrix {
    float m_pEntry[3][3];
};

inline NiPoint3 operator*(const S5e1c70_Matrix& m, const NiPoint3& p) {
    return NiPoint3(
        m.m_pEntry[0][0] * p.x + m.m_pEntry[0][1] * p.y + m.m_pEntry[0][2] * p.z,
        m.m_pEntry[1][0] * p.x + m.m_pEntry[1][1] * p.y + m.m_pEntry[1][2] * p.z,
        m.m_pEntry[2][0] * p.x + m.m_pEntry[2][1] * p.y + m.m_pEntry[2][2] * p.z);
}

inline NiPoint3 operator+(const NiPoint3& a, const NiPoint3& b) {
    return NiPoint3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline NiPoint3 operator-(const NiPoint3& a, const NiPoint3& b) {
    return NiPoint3(a.x - b.x, a.y - b.y, a.z - b.z);
}

struct S5e1c70_Obstacle : public NiRefObject {
    int unk08;
    int unk0c;
    NiPoint3 kTranslate;
    S5e1c70_Matrix kRotate;
    NiPoint3 kMinBounds;
    NiPoint3 kMaxBounds;
    NiPoint3 kWorldMin;
    NiPoint3 kWorldMax;
};

struct S5e1c70_Mesh : public NavMesh {
    bool FUN_005bdde0(NiPoint3* a_pPoint, float a_fRadius, float a_fHeight, float* a_pZ);
    unsigned short FUN_005ba320(NavMeshVertex& a_rVertex);
};

struct S5e1c70_Heap {
    void* ScrapHeap_Allocate(unsigned int a_uiSize, unsigned int a_uiAlign);
};

struct S5e1c70_Edge {
    S5e1c70_Edge(NavMeshObstacleVertex* a_pStart, NavMeshObstacleVertex* a_pEnd) : spObstacle(0) {
        pStart = a_pStart;
        pEnd = a_pEnd;
        us08 = 0xFFFF;
        us0a = 0xFFFF;
        us0c = 0xFFFF;
        us0e = 0xFFFF;
        i10 = 1;
        usFlags = 0;
        bStartFlag = false;
        bEndFlag = false;
        us14 = 0xFFFF;
        i20 = 0;
        us24 = 0xFFFF;
        i28 = -1;
        us2c = 0xFFFF;
        b2e = false;
    }
    NavMeshObstacleVertex* pStart;
    NavMeshObstacleVertex* pEnd;
    unsigned short us08;
    unsigned short us0a;
    unsigned short us0c;
    unsigned short us0e;
    int i10;
    unsigned short us14;
    unsigned short usFlags;
    bool bStartFlag;
    bool bEndFlag;
    NiPointer<ObstacleData> spObstacle;
    int i20;
    unsigned short us24;
    int i28;
    unsigned short us2c;
    bool b2e;
};

struct S5e1c70_VertexArray : public ScrapArray<NavMeshObstacleVertex*> {
    void FUN_00799ae0(unsigned int a_uiNewSize, unsigned int a_uiMoveCount);

    void Add(NavMeshObstacleVertex* a_pVertex) {
        if (iSize == iReservedSize) {
            if (!iReservedSize) {
                pBuffer = _Allocate(4);
                iReservedSize = 4;
            } else {
                unsigned int uiNewSize = iReservedSize > 0x400 ? iReservedSize + 0x400 : iReservedSize * 2;
                FUN_00799ae0(uiNewSize, iSize);
                iReservedSize = uiNewSize;
            }
        }
        ++iSize;
        pBuffer[iSize - 1] = a_pVertex;
    }
};

struct S5e1c70_EdgeArray : public ScrapArray<NavMeshObstacleEdge*> {
    NavMeshObstacleEdge** Resize(NavMeshObstacleEdge** a_pData, unsigned int a_uiNewSize) {
        if (a_pData)
            return _Reallocate(a_pData, a_uiNewSize);
        NavMeshObstacleEdge** pNew = _Allocate(a_uiNewSize);
        iReservedSize = a_uiNewSize;
        return pNew;
    }

    void Add(NavMeshObstacleEdge* a_pEdge) {
        if (iSize == iReservedSize) {
            if (!iReservedSize) {
                NavMeshObstacleEdge** pNew = _Allocate(4);
                iReservedSize = 4;
                pBuffer = pNew;
            } else {
                unsigned int uiNewSize = iReservedSize > 0x400 ? iReservedSize + 0x400 : iReservedSize * 2;
                NavMeshObstacleEdge** pNew = Resize(pBuffer, uiNewSize);
                iReservedSize = uiNewSize;
                pBuffer = pNew;
            }
        }
        ++iSize;
        pBuffer[iSize - 1] = a_pEdge;
    }
};

inline S5e1c70_Obstacle* S5e1c70_GetObstacle(const NiPointer<ObstacleData>& sp) {
    return (S5e1c70_Obstacle*)(ObstacleData*)sp;
}

inline S5e1c70_Edge* S5e1c70_CreateEdge(S5e1c70_Heap& a_rHeap, NavMeshObstacleVertex* const& a_pStart, NavMeshObstacleVertex* a_pEnd) {
    S5e1c70_Edge* pEdge = (S5e1c70_Edge*)a_rHeap.ScrapHeap_Allocate(0x30, DAT_00e27ed4);
    if (pEdge)
        new (pEdge) S5e1c70_Edge(a_pStart, a_pEnd);
    return pEdge;
}

inline float S5e1c70_GetSquaredXYLength(const NiPoint3& a) {
    return a.x * a.x + a.y * a.y;
}

struct S5e1c70_Cutter {
    bool FUN_005df730(const NiPoint3& a_rPoint);
};

// pdb: NavMeshObstacleCutter::GenerateBoxVertsAndEdges | NavMeshObstacleCutter.obj | fnv360_0721_beta, objrun, medium
void NavMeshObstacleCutter::FUN_005e1c70() {
    S5e1c70_Obstacle* pObs;
    NiPoint3 kCorners[4];
    kCorners[0] = NiPoint3(S5e1c70_GetObstacle(spObstacle)->kMinBounds.x, S5e1c70_GetObstacle(spObstacle)->kMinBounds.y, S5e1c70_GetObstacle(spObstacle)->kMinBounds.z);
    kCorners[1] = NiPoint3(S5e1c70_GetObstacle(spObstacle)->kMinBounds.x, S5e1c70_GetObstacle(spObstacle)->kMaxBounds.y, S5e1c70_GetObstacle(spObstacle)->kMinBounds.z);
    kCorners[2] = NiPoint3(S5e1c70_GetObstacle(spObstacle)->kMaxBounds.x, S5e1c70_GetObstacle(spObstacle)->kMaxBounds.y, S5e1c70_GetObstacle(spObstacle)->kMinBounds.z);
    kCorners[3] = NiPoint3(S5e1c70_GetObstacle(spObstacle)->kMaxBounds.x, S5e1c70_GetObstacle(spObstacle)->kMinBounds.y, S5e1c70_GetObstacle(spObstacle)->kMinBounds.z);

    pObs = (S5e1c70_Obstacle*)(ObstacleData*)spObstacle;
    float fHeight = pObs->kWorldMax.z - pObs->kWorldMin.z;
    unsigned int uiFlags = FUN_005d1f20(fHeight, true, false);

    NiPoint3 kPoints[4];
    for (unsigned int i = 0; i < 4; i++) {
        pObs = (S5e1c70_Obstacle*)(ObstacleData*)spObstacle;
        NiPoint3 kRotated = pObs->kRotate * kCorners[i];
        kPoints[i] = kRotated + pObs->kTranslate;
        float fZ = kPoints[i].z;
        if (((S5e1c70_Mesh*)pNavMesh)->FUN_005bdde0(&kPoints[i], 128.0f, fHeight, &fZ))
            kPoints[i].z = fZ;
    }

    NavMeshObstacleVertex* apVertices[4];
    for (unsigned int i = 0; i < 4; i++) {
        NavMeshVertex kVertex;
        kVertex.Location = kPoints[i];
        unsigned int uiIndex = ((S5e1c70_Mesh*)pNavMesh)->FUN_005ba320(kVertex);
        NavMeshObstacleVertex* pVertex = (NavMeshObstacleVertex*)((S5e1c70_Heap*)&unk0c)->ScrapHeap_Allocate(8, DAT_00e27ed4);
        if (pVertex) {
            pVertex->usVertexIndex = (unsigned short)uiIndex;
            pVertex->bOnObstacle = true;
            pVertex->bOnBounds = false;
            pVertex->bOnOpenEdge = false;
            pVertex->bInOverlappedArea = false;
            pVertex->bInObstacleArea = false;
        }
        bool bOverlapped;
        if (!pVertex->bOnBounds && !pVertex->bOnOpenEdge)
            bOverlapped = ((S5e1c70_Cutter*)this)->FUN_005df730(pNavMesh->GetVertex(pVertex->usVertexIndex)->Location);
        else
            bOverlapped = true;
        pVertex->bInOverlappedArea = bOverlapped;
        apVertices[i] = pVertex;
        ((S5e1c70_VertexArray*)&Vertices)->Add(pVertex);
    }

    S5e1c70_Edge* apEdges[4];
    for (unsigned int i = 0; i < 4; i++) {
        S5e1c70_Edge* pEdge = S5e1c70_CreateEdge(*(S5e1c70_Heap*)&unk0c, apVertices[i], apVertices[(i + 1) % 4]);
        apEdges[i] = pEdge;
        ((S5e1c70_EdgeArray*)&Edges)->Add((NavMeshObstacleEdge*)pEdge);
    }

    for (unsigned int i = 0; i < 4; i++) {
        S5e1c70_Edge* pEdge = apEdges[i];
        NiPoint3& kStart = pNavMesh->GetVertex(pEdge->pStart->usVertexIndex)->Location;
        NiPoint3& kEnd = pNavMesh->GetVertex(pEdge->pEnd->usVertexIndex)->Location;
        NiPoint3 kDiff = kEnd - kStart;
        float fLenSq = S5e1c70_GetSquaredXYLength(kDiff);
        if (fLenSq > 64.0f) {
            pEdge->usFlags = (unsigned short)uiFlags;
            pEdge->bStartFlag = true;
            pEdge->bEndFlag = true;
            pEdge->spObstacle = spObstacle;
        }
    }
}
}

// @f3 0x005f0070 (community match, verified in this file)
#include <math.h>

namespace N5f0070 {

struct Pt
{
    float x, y, z;
    Pt() {}
    Pt(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
    Pt operator-(const Pt& o) const { return Pt(x - o.x, y - o.y, z - o.z); }
    float GetLengthXY() const { return (float)sqrt(x * x + y * y); }
};

inline float S5f0070_LenXY(Pt v) { return (float)sqrt(v.x * v.x + v.y * v.y); }

extern Pt DAT_0108ec68;
extern float DAT_00f67ae0;
extern void* DAT_00dc4dc0[];

struct Ref
{
    const Pt* FUN_004e7580();
};

struct PathingLocation
{
    void** m_vtable;
    Pt position;
    const void* mesh;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short triangle;
    unsigned short unk26;

    PathingLocation(const Pt& pos, const void* navMesh, unsigned short tri);
    ~PathingLocation() { m_vtable = DAT_00dc4dc0; }
    Pt GetPosition() const { return position; }
    int FUN_004c0120();
    void FUN_005fcba0(const Pt* pos);
};

struct PathEntry
{
    unsigned char flags;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    PathingLocation point;
    Ref* ref;

    bool IsRef() const { return (flags & 4) != 0; }
    PathingLocation* GetPoint() { return &point; }
    Ref* GetRef() const { return ref; }
};

struct Segment
{
    unsigned int flags;
    PathingLocation location;
    int unk2C;
    int unk30;
    int unk34;
    Ref* ref;

    void SetRef(Ref* r)
    {
        ref = r;
        location.FUN_005fcba0(r->FUN_004e7580());
        flags |= 3;
    }
    void SetFlag4() { flags |= 4; }
};

inline unsigned int S5f0070_Count(const volatile unsigned int& n) { return n; }

struct Solution
{
    int unk00;
    int unk04;
    int unk08;
    PathEntry* entries;
    unsigned int count;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    Segment* segments;
    unsigned int segmentCount;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    bool failed;

    PathEntry* GetEntry(unsigned int i) { return &entries[i]; }
    unsigned int GetCount() const { return count; }
    Segment* GetLastSegment()
    {
        if (segmentCount == 0)
            return 0;
        return &segments[S5f0070_Count(segmentCount) - 1];
    }
    Segment* FUN_005d20a0();
    bool IsFailed() const { return failed; }
    void SetFailed(bool b) { failed = b; }
    void FUN_005c5cf0(PathingLocation* loc, const Pt& offset);
};

struct DoorHandle
{
    const void* mesh;
    unsigned short triangle;
    unsigned short flags;
    int edge;
    Pt position;
};

extern void* DAT_00e01ec4[];

struct DoorArray
{
    void** m_vtable;
    DoorHandle* data;
    unsigned int count;
    unsigned int capacity;

    DoorArray() : m_vtable(DAT_00e01ec4), data(0), count(0), capacity(0) {}
    ~DoorArray() { FUN_005eb480(); }
    void FUN_005eb480();
    bool IsEmpty() const { return count == 0; }
    DoorHandle* GetAt(unsigned int i) { return &data[i]; }
};

extern void (DoorArray::*DAT_00e01ecc)(DoorHandle* p);

inline void DoorArray::FUN_005eb480()
{
    m_vtable = DAT_00e01ec4;
    if (data)
    {
        (this->*DAT_00e01ecc)(data);
        data = 0;
        capacity = 0;
        count = 0;
    }
}

struct PathArray
{
    void** m_vtable;
    PathingLocation* data;
    unsigned int count;
    unsigned int capacity;

    PathArray();
    ~PathArray() { FUN_005d0d90(); }
    void FUN_005d0d90();
    int FUN_005ecde0(const PathingLocation& loc);
    unsigned int GetCount() const { return count; }
    bool IsEmpty() const { return count == 0; }
    PathingLocation* GetAt(unsigned int i) { return &data[i]; }
    PathingLocation* GetLast() { return &data[count - 1]; }
};

extern void* DAT_00e01240[];
inline PathArray::PathArray() : m_vtable(DAT_00e01240), data(0), count(0), capacity(0) {}

struct Request
{
    int unk00;
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
    int unk60;
    int unk64;
    float unk68;
    float GetFloat68() const { return unk68; }
};

unsigned char __cdecl FUN_005f25b0(PathingLocation* a, PathingLocation* b, void* c, void* d);

struct PathBuilder
{
    Request* request;
    Solution* solution;

    int FUN_005efc20(unsigned int index, PathArray* path, DoorArray* doors);
    int FUN_005efdd0(unsigned int index, PathArray* path, DoorArray* doors);
    int FUN_005ed500(PathingLocation& start, PathingLocation& goal, PathArray* path);
    bool FUN_005ed6c0(unsigned int index, DoorArray* doors, PathArray* path);
    int FUN_005eee90(PathingLocation* start, PathingLocation* goal, unsigned int a, unsigned int b);
    bool FUN_005f0070(unsigned int a, unsigned int b);
};

bool PathBuilder::FUN_005f0070(unsigned int a, unsigned int b)
{
    DoorArray startDoors;
    PathArray startPath;
    int startResult = FUN_005efc20(a, &startPath, &startDoors);
    DoorArray goalDoors;
    PathArray goalPath;
    int goalResult = FUN_005efdd0(b, &goalPath, &goalDoors);
    if (startResult == 0 || goalResult == 0)
        return false;

    float startDist = 0.0f;
    if (!startDoors.IsEmpty())
    {
        Pt doorPos = startDoors.GetAt(0)->position;
        startDist = S5f0070_LenXY(doorPos - solution->GetEntry(a)->GetPoint()->GetPosition());
    }
    float goalDist = 0.0f;
    if (!goalDoors.IsEmpty())
    {
        Pt doorPos = goalDoors.GetAt(0)->position;
        goalDist = S5f0070_LenXY(doorPos - solution->GetEntry(b)->GetPoint()->GetPosition());
    }
    float direct = (solution->GetEntry(a)->GetPoint()->GetPosition() -
                    solution->GetEntry(b)->GetPoint()->GetPosition()).GetLengthXY();

    bool tryDirect = false;
    if (direct < (startDist + goalDist) * 2.0)
        tryDirect = true;
    if (startResult == 2 || goalResult == 2)
    {
        if (direct < 512.0)
            tryDirect = true;
    }
    if (tryDirect)
    {
        PathArray detailed;
        switch (FUN_005ed500(*solution->GetEntry(a)->GetPoint(), *solution->GetEntry(b)->GetPoint(), &detailed))
        {
        case 1:
        {
            unsigned int i;
            for (i = 0; i < detailed.GetCount(); i++)
                solution->FUN_005c5cf0(detailed.GetAt(i), DAT_0108ec68);
            PathEntry* node = solution->GetEntry(b);
            if (node->IsRef())
            {
                solution->GetLastSegment()->SetRef(node->GetRef());
            }
            else if (node->GetPoint()->FUN_004c0120() != 0)
            {
                if (solution->GetCount() > b + 1)
                {
                    if (solution->GetEntry(b + 1)->GetPoint()->FUN_004c0120() == node->GetPoint()->FUN_004c0120())
                    {
                        solution->FUN_005c5cf0(solution->GetEntry(b + 1)->GetPoint(), DAT_0108ec68);
                        solution->FUN_005d20a0()->SetFlag4();
                    }
                }
            }
            return true;
        }
        case 0:
            return false;
        }
    }
    if (startResult == 2)
        return false;
    if (goalResult == 2)
    {
        if (goalDoors.IsEmpty())
            return false;
        if (!FUN_005ed6c0(b, &goalDoors, &goalPath))
            solution->SetFailed(true);
        {
            PathingLocation loc(goalDoors.GetAt(0)->position, goalDoors.GetAt(0)->mesh, goalDoors.GetAt(0)->triangle);
            goalPath.FUN_005ecde0(loc);
        }
    }
    {
        unsigned int i;
        for (i = 0; i < startPath.GetCount() - 1; i++)
            solution->FUN_005c5cf0(startPath.GetAt(i), DAT_0108ec68);
    }
    switch (FUN_005eee90(startPath.GetLast(), goalPath.GetLast(), a, b))
    {
    case 2:
    {
        if (direct < 512.0 && request->GetFloat68() < DAT_00f67ae0)
        {
            if (FUN_005f25b0(solution->GetEntry(a)->GetPoint(), solution->GetEntry(b)->GetPoint(), 0, 0))
                return false;
            PathArray retry;
            if (FUN_005ed500(*solution->GetEntry(a)->GetPoint(), *solution->GetEntry(b)->GetPoint(), &retry) != 1)
                return false;
            solution->SetFailed(false);
            unsigned int i;
            for (i = 0; i < retry.GetCount(); i++)
                solution->FUN_005c5cf0(retry.GetAt(i), DAT_0108ec68);
            return !solution->IsFailed();
        }
        return false;
    }
    case 0:
    {
        if (!goalPath.IsEmpty())
        {
            int i;
            for (i = (int)goalPath.GetCount() - 1; i >= 0; i--)
                solution->FUN_005c5cf0(goalPath.GetAt(i), DAT_0108ec68);
        }
        PathEntry* node = solution->GetEntry(b);
        if (node->IsRef())
        {
            solution->GetLastSegment()->SetRef(node->GetRef());
        }
        else if (node->GetPoint()->FUN_004c0120() != 0)
        {
            if (solution->GetCount() > b + 1)
            {
                if (solution->GetEntry(b + 1)->GetPoint()->FUN_004c0120() == node->GetPoint()->FUN_004c0120())
                {
                    solution->FUN_005c5cf0(solution->GetEntry(b + 1)->GetPoint(), DAT_0108ec68);
                    solution->FUN_005d20a0()->SetFlag4();
                }
            }
        }
        return !solution->IsFailed();
    }
    case 1:
        solution->SetFailed(true);
        return false;
    }
    return false;
}

}

// @f3 0x005fe560 (community match, verified in this file)
#include <windows.h>
namespace f3m_005fe560 {

namespace f3m_005fe560 {

struct Counter {
    virtual void v0();
    long refs;
    virtual void DeleteThis();
    void DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};

struct Indices {
    int unk00;
    unsigned short* index;
    unsigned int count;
};

struct Resource {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    Counter counter;
    Indices* FUN_005b84f0(int key);
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.DecRefCount(); }
};

void __cdecl FUN_005b87d0(NiPointer<Resource>* out, void* source);

__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<Resource>* out, void* source)
{
    *out = (Resource*)source;
}

struct Source {
    int unk00;
    int unk04;
    unsigned int flags;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    void* unk54;
    bool GetDisabled() const { return (flags >> 4) & 1; }
    bool Load(NiPointer<Resource>& out) const
    {
        if (GetDisabled())
            return false;
        FUN_005b87d0(&out, unk54);
        return out.m_pObject != 0;
    }
};

struct Arg {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned short id;
};

struct Owner {
    char enabled;
    int unk04;
    signed char* values;
    unsigned int count;
    int unk10;
    Source* data;
    int key;
    bool FUN_005fe560(Arg* arg);
};

// pdb: PathingLOSGridCell::IsLocationSeen | PathingLOSGridMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: arLocation
bool Owner::FUN_005fe560(Arg* arg)
{
    if (enabled)
        return true;
    NiPointer<Resource> ptr;
    if (data->Load(ptr))
    {
        Indices* r = ptr->FUN_005b84f0(key);
        if (r->count != count)
            return false;
        for (unsigned int i = 0; i < r->count; ++i)
        {
            unsigned short v = r->index[i];
            if (v == arg->id)
                return values[i] > 0;
        }
    }
    return false;
}

}
}   // namespace f3m_005fe560

// @f3 0x005efb00 (community match, verified in this file)
namespace f3m_005efb00 {
namespace S005efb00_ns {

struct S005efb00_Point
{
    int unk00;
    void* FUN_004c0120();
    void* FUN_005fcbf0();
    void* PathingLocation_GetCell();
    bool SameA(S005efb00_Point& other) { void* o = FUN_004c0120(); return other.FUN_004c0120() == o; }
    bool SameB(S005efb00_Point& other) { void* o = PathingLocation_GetCell(); return other.PathingLocation_GetCell() == o; }
};

struct S005efb00_Pair
{
    int unk00, unk04, unk08;
    S005efb00_Point first;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    S005efb00_Point second;
};

struct S005efb00_Element
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void FUN_00600960();
};

struct S005efb00_Array;
struct S005efb00_Table
{
    void* unk00;
    void* unk04;
    void (__thiscall* free)(S005efb00_Array*, void*);
};

struct S005efb00_Array
{
    S005efb00_Table* table;
    S005efb00_Element* data;
    unsigned count;
    unsigned capacity;
    void Clear(bool release)
    {
        S005efb00_Element* p = data;
        if (p)
        {
            unsigned n = count;
            while (n > 0)
            {
                p->FUN_00600960();
                ++p;
                --n;
            }
            if (release)
            {
                table->free(this, data);
                data = 0;
                capacity = 0;
            }
            count = 0;
        }
    }
};

struct S005efb00_List
{
    int unk00, unk04;
    S005efb00_Array items;
    unsigned FUN_005ebf20(int value);
};

struct S005efb00_Path
{
    S005efb00_Pair* pair;
    S005efb00_List* list;

    bool FUN_005ec160(void* a, void* b);
    bool FUN_005ee8c0();
    bool FUN_005efb00(void* a0, void* a1);
};

// pdb: PathBuilder::BuildHighLevelPath | PathBuilder.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apStartMesh, apGoalMesh
bool S005efb00_Path::FUN_005efb00(void* a0, void* a1)
{
    if (a0 && a1 && a0 == a1)
    {
        list->FUN_005ebf20((int)&pair->first);
        list->FUN_005ebf20((int)&pair->second);
        return true;
    }
    if (!a0 || !a1 || !FUN_005ec160(a0, a1))
    {
        if (pair->first.FUN_004c0120())
        {
            if (pair->second.SameA(pair->first)
                && pair->first.FUN_005fcbf0() && pair->second.FUN_005fcbf0())
                return false;
        }
        else
        {
            if (pair->second.SameB(pair->first)
                && pair->first.FUN_005fcbf0() && pair->second.FUN_005fcbf0())
                return false;
        }
        list->items.Clear(false);
        if (!FUN_005ee8c0())
            return false;
    }
    return true;
}

}
}   // namespace f3m_005efb00

// @f3 0x005feb30 (community match, verified in this file)
namespace f3m_005feb30 {
namespace c5feb30 {

struct IdList { int unk00; unsigned short* ids; unsigned int count; };
struct Counter { void** table; long refs; void Release() { if (!InterlockedDecrement(&refs)) ((void (__thiscall *)(Counter*))table[1])(this); } };
struct Resource {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; Counter counter;
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
    __declspec(noalias) IdList* FUN_005b84f0(int index);
};
struct ResPtr {
    Resource* m_pObject;
    ResPtr() : m_pObject(0) {}
    __forceinline ~ResPtr() { if (m_pObject) m_pObject->DecRefCount(); }
    Resource* operator->() const { return m_pObject; }
};
__declspec(noalias) void FUN_005b87d0(ResPtr* __restrict dest, void* source);
struct Entry { int unk00; int unk04; unsigned int flags; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; void* unk54; };
struct Array { int unk00; signed char* buffer; unsigned int size; unsigned int capacity; __declspec(noalias) void FUN_005fe850(unsigned int, int); };
struct Form { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; unsigned short id; };

struct FormOwner {
    unsigned char kind;
    unsigned char unk01;
    unsigned short unk02;
    Array data;
    Entry* entry;
    int index;
    bool FUN_005feb30(Form* form, bool enable);
};

// pdb: PathingLOSGridCell::SetLocationSeen | PathingLOSGridMap.obj | fnv360_0822_retail, objrun, medium
// pdb params: arLocation, abSeen
bool FormOwner::FUN_005feb30(Form* form, bool enable)
{
    ResPtr resource;
    if (!((unsigned char)(entry->flags >> 4) & 1)) {
        FUN_005b87d0(&resource, entry->unk54);
        bool ok = resource.m_pObject != 0;
        if (ok) {
            IdList* list = resource->FUN_005b84f0(index);
            if (kind) {
                if (enable)
                    return true;
                {
                    kind = 0;
                    data.FUN_005fe850(list->count, 1);
                    unsigned int n = list->count;
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            unsigned short a = list->ids[i];
                            unsigned short b = form->id;
                            if (a == b)
                                data.buffer[i] = -1;
                            else
                                data.buffer[i] = 1;
                            ++i;
                        } while (i < list->count);
                    }
                }
                return true;
            }
            if (list->count != data.size)
                return false;
            for (unsigned int i = 0; i < list->count; ++i) {
                unsigned short a = list->ids[i];
                unsigned short b = form->id;
                if (a == b) {
                    data.buffer[i] = enable ? 1 : -1;
                    return true;
                }
            }
        }
    }
    return false;
}

}
}   // namespace f3m_005feb30

// @f3 0x005ff750 (community match, verified in this file)
namespace f3m_005ff750 {
// FUN_005ff750: navmesh collection pass for a pathing request.
namespace m5ff750 {

struct NavMeshInfo;
struct Item;
struct NavMesh;

// Refcounted object head shared by the navmesh classes (vtable at +0x1C, refs at +0x20).
struct BSRefObject {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(BSRefObject*))vtable[1])(this);
    }
};

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BSRefObject ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
};

__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<NavMesh>& arDest, NavMesh* apSource) {
    arDest = apSource;
}

struct NavMeshInfo {
    int unk00, unk04;
    unsigned int uiFlags;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    NavMesh* pNavMesh;
    bool GetDisabled() const { return (uiFlags >> 4) & 1; }
    bool GetNavMesh(NiPointer<NavMesh>& ar_spNavMesh) const {
        if (GetDisabled())
            return false;
        FUN_005b87d0(ar_spNavMesh, pNavMesh);
        return ar_spNavMesh.m_pObject != 0;
    }
};

// One obstacle group stored in the map: an array of items and the navmesh they belong to.
struct MapValue {
    int unk00;
    Item** data;
    unsigned int count;
    int unk0C;
    NavMeshInfo* info;
};

struct Item {
    void FUN_005fe3c0(void* apContext);
};

struct MapItem {
    MapItem* m_pNext;
    unsigned int m_key;
    MapValue* m_val;
};

struct Map {
    void* vtbl;
    unsigned int m_size;
    MapValue** m_buckets;
    __declspec(noinline) void AdvanceToNextEntry(void** pos, unsigned int* key, MapValue** val) {
        MapItem* item = (MapItem*)*pos;
        *key = item->m_key;
        *val = item->m_val;
        *pos = item->m_pNext;
    }
    MapValue* GetFirstPos() {
        for (unsigned int i = 0; i < m_size; i++) {
            if (m_buckets[i])
                return m_buckets[i];
        }
        return 0;
    }
};

struct Lock {
    int unk00, unk04;
    void FUN_0086cbf0();
    void FUN_0086cdd0();
};

// BSSimpleArray<NiPointer<NavMesh> >: manual vtable, 0x400 growth step.
struct MeshArray {
    void** table;
    NiPointer<NavMesh>* data;
    unsigned int count;
    unsigned int capacity;

    void FUN_00415f50(void* apData, unsigned int aiCount);
    void FUN_00799ae0(unsigned int aiNewSize, unsigned int aiMoveCount);

    MeshArray() : table(&DAT_00db5c04), data(0), count(0), capacity(0) {}
    ~MeshArray() {
        table = &DAT_00db5c04;
        if (data) {
            FUN_00415f50(data, count);
            ((void (__thiscall*)(MeshArray*, void*))table[2])(this, data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }

    __forceinline unsigned int Add(NiPointer<NavMesh>& item) {
        if (count == capacity) {
            if (!capacity) {
                data = (NiPointer<NavMesh>*)((void* (__thiscall*)(MeshArray*, unsigned int))table[1])(this, 4);
                capacity = 4;
            } else {
                unsigned int newSize = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_00799ae0(newSize, count);
                capacity = newSize;
            }
        }
        ++count;
        unsigned int index = count - 1;
        new (&data[index]) NiPointer<NavMesh>;
        data[index] = item;
        return index;
    }
};

struct Ctx {
    void FUN_006006b0(MeshArray* apArray);
};

struct Owner {
    int unk00;
    int unk04;
    Map map;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48;
    Lock lock;
    bool FUN_005ff750(void* apParam);
};

// pdb: PathingLOSGridMap::SetLOSMapFromSeenTriangles | PathingLOSGridMap.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aspLOSMap
bool Owner::FUN_005ff750(void* apParam) {
    lock.FUN_0086cbf0();
    MeshArray meshes;
    void* pos;
    {
        pos = map.GetFirstPos();
        while (pos) {
            unsigned int key;
            MapValue* val;
            map.AdvanceToNextEntry(&pos, &key, &val);
            NiPointer<NavMesh> mesh;
            NavMeshInfo* info = val->info;
            if (info && info->GetNavMesh(mesh))
                meshes.Add(mesh);
        }
    }
    Ctx* ctx = (Ctx*)*(void**)apParam;
    ctx->FUN_006006b0(&meshes);
    {
        pos = map.GetFirstPos();
        while (pos) {
            unsigned int key;
            MapValue* val;
            map.AdvanceToNextEntry(&pos, &key, &val);
            NiPointer<NavMesh> mesh;
            NavMeshInfo* info = val->info;
            if (info && info->GetNavMesh(mesh)) {
                for (unsigned int i = 0; i < val->count; ++i)
                    val->data[i]->FUN_005fe3c0(apParam);
            }
        }
    }
    lock.FUN_0086cdd0();
    return true;
}

}
}   // namespace f3m_005ff750

// @f3 0x005e6b60 (community match, verified in this file)
namespace f3m_005e6b60 {
// Model of NavMeshObstacleManager_AddProcessedTask (68 bytes), third revision - v2 compiled at 72 vs 68 / 21 lines and the whole residue turned out to be addressing FORM ✓✓
// Their build keeps two derived pointers rather than re-discounting from 'this':
//     mov edi,ecx ; lea esi,[edi+100h]        - ESI = &this->monitor, taken once at entry and reused for the enter call AND for the release pair ([esi+4], [esi]) ✓✓
//     add edi,0E8h ; mov ecx,edi              - EDI is RE-BASED onto &this->slots (an 'add', not another lea) and used as ECX plus later [edi+4] ✓✓
// Mine folded everything through one base register: 'lea edi,[esi+100h]' and a direct '[esi+0xEC]', which costs extra bytes and swaps the registers ✓✓
// Taking local pointers to both members should reproduce both forms, in their declaration order (monitor first, then slots).

namespace f3m_005e6b60c {

extern char DAT_00e01d2c;                                 // "NavMeshObstacleManager::AddProcessedTask()" at 0xe01d2c ✓✓

struct MonitorC5E {                                       // embedded at this+0x100 ✓✓
    long lockWord;                                        // +0x00: ORIG 'mov eax,[esi]' is the CAS comparand ✓✓
    long holdCount;                                       // +0x04: ORIG 'add dword ptr [esi+4],0FFFFFFFFh' then jnz ✓✓

    void FUN_00409a80(char const* name);                  // ORIG: push offset ... ; mov ecx,esi ; call sub_409A80 - the enter helper from 0x40a2d0 ✓✓
};

struct SlotArrayC5E {                                     // embedded at this+0xE8, i.e. BEFORE the monitor ✓✓
    void* pad0;                                           // +0x00: becomes ECX for the helper call ✓✓
    int* items;                                           // +0x04: ORIG 'mov ecx,[edi+4]' - the dword array written ✓✓

    int FUN_005e5350();                                   // ORIG: 'add edi,0E8h ; mov ecx,edi ; call sub_5E5350' → slot index in EAX ✓✓
};

struct OwnerC5E {                                         // the NavMeshObstacleManager ✓✓
    char padE8[0xE8];
    SlotArrayC5E slots;                                   // +0xE8 ✓✓
    char pad100[0x100 - 0xF0];
    MonitorC5E monitor;                                   // +0x100 ✓✓

    void NavMeshObstacleManager_AddProcessedTask(int value);                         // thiscall with one stack parameter (retn 4) ✓✓
};

extern long (__stdcall *DAT_00d9b06c)(long*, long, long);   // InterlockedCompareExchange through its import slot: 'call ds:InterlockedCompareExchange' ✓✓

// pdb: NavMeshObstacleManager::AddProcessedTask | NavMeshObstacleManager.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void OwnerC5E::NavMeshObstacleManager_AddProcessedTask(int value) {
    MonitorC5E* monitor = &this->monitor;                 // ORIG: lea esi,[edi+100h] taken before the enter call and still live at the release ✓✓
    monitor->FUN_00409a80(&DAT_00e01d2c);                 // ORIG: push offset 0xe01d2c ; mov ecx,esi ; call sub_409A80 ✓✓

    SlotArrayC5E* slots = &this->slots;                   // ORIG: add edi,0E8h - the base register is re-based rather than re-discounted ✓✓
    int slot = slots->FUN_005e5350();                     // ORIG: mov ecx,edi ; call sub_5E5350 → index in EAX ✓✓
    slots->items[slot] = value;                           // ORIG: mov ecx,[edi+4] ; mov edx,[esp+8+arg_0] ; mov [ecx+eax*4],edx ✓✓

    if (--monitor->holdCount == 0) {                      // ORIG: add dword ptr [esi+4],0FFFFFFFFh ; jnz end ✓✓
        long observed = monitor->lockWord;                // ORIG: mov eax,[esi] ✓✓
        DAT_00d9b06c((long*)monitor, 0, observed);         // ORIG: push eax ; push 0 ; push esi ; call ds:InterlockedCompareExchange ✓✓
    }
}

}
}   // namespace f3m_005e6b60

// @f3 0x005fff00 (community match, verified in this file)
namespace f3m_005fff00 {
// Model of FUN_005fff00 (82 bytes) - fresh claim, give_ups=0 ✓✓ thiscall with two stack parameters ('retn 8') returning a bool in AL. The pack declares 13 thread-locals and the body touches none ✓✓ 
//   push edi ; mov edi,ecx ; cmp dword ptr [edi+24h],0 ; jnz 0x5FFF0F      - 'this' to EDI; when the flag at +0x24 is zero it returns false IMMEDIATELY with its own short epilogue (xor al,al ; pop
//                                                                              edi ; retn 8) ✓✓ so this guard really is written first and its cold result stays inline here - unlike 0xbe1310 where the
//                                                                              same kind of check jumped forward to a tail; measuring will show which shape VC8 prefers ✓✗ 
//   push ebx/ebp/esi ; xor esi,esi ; cmp [edi+2Ch],esi ; jbe 0x5FFF40       - the count at +0x2C is compared UNSIGNED against index zero ('jbe'), so declare it unsigned ✓✓ ESI is the loop index ✓✓ 
//   mov ebx,[esp+10h+arg_4] ; mov ebp,[esp+10h+arg_0]                      - both parameters are cached in callee-saved registers before the loop, because they must survive the calls inside it ✓✓ 
//   loop @0x5FFF21: mov eax,[edi+18h] ; cmp byte ptr [esi+eax],0 ; jg 0x5FFF38
//                                                                          - a BYTE array at +0x18 indexed by ESI; the branch is 'jg' (signed), so the element type must be SIGNED char ✓✓ values greater than
//                                                                            zero skip the call; only non-positive ones take it ✓✓ 
//      push ebx ; push ebp ; push esi ; mov ecx,edi ; call sub_5FFE50       - a member of 'this' taking (index, parameter one, parameter two): pushes run right-to-left so the index is leftmost ✓✓
//                                                                            ECX is re-set to EDI each pass; nothing follows but the test, so that member cleaned its own three arguments ✓✓ 
//      test al,al ; jnz 0x5FFF49                                            - a true result returns true from the loop ✓✓ 
//   0x5FFF38: add esi,1 ; cmp esi,[edi+2Ch] ; jb loop                       - bottom-tested, UNSIGNED back-edge ('jb'), and the count is RE-READ from memory here rather than cached in a register ✓✓
//                                                                            (so write this->count2C again instead of hoisting it into a local) ✓✓ 
//   0x5FFF40 false tail: pop esi/ebp/ebx ; xor al,al ; pop edi ; retn 8 ✓✓ 
//   0x5FFF49 true  tail: pop esi/ebp/ebx ; mov al,1  ; pop edi ; retn 8     - 'mov al,1', not a setcc/xor trick ✓✓ so returning the literal true is right ✓✓ 

namespace f3m_005fff00 {

struct Holder5FF {                                   // 'this' (EDI) ✓✓
    char pad18[0x18];
    signed char* flags;                              // +0x18: a BYTE array; ORIG compares each element against zero with a SIGNED branch ('jg'), hence signed char ✓✓ 
    char pad24[0x24 - 0x1C];                         // v1 put the next two fields at +0x1C/+0x20 because I forgot that the flags pointer itself occupies four bytes ✓✗ (measured: only those three
                                                     //     accesses differed, everything else matched at equal extents) ✓✓ 
    unsigned long enabled24;                         // +0x24: compared against 0 with 'jnz' - an early false return when it is clear ✓✓ 
    char pad2C[0x2C - 0x28];                         // the count sits one dword further along than the flag, so another opaque field lives between them ✓✗ (v2 measured +0x28 for the count) ✓✓ 
    unsigned int count2C;                            // +0x2C: read twice (pre-test 'jbe', back-edge 'jb'), both UNSIGNED ✓✓ 

    bool __thiscall FUN_005ffe50(unsigned int index, void* firstArgument, void* secondArgument);   // ORIG: push ebx ; push ebp ; push esi ; mov ecx,edi ; call sub_5FFE50 - callee-cleaned with ECX set per pass ✓✓ 

    bool FUN_005fff00(void* firstArgument, void* secondArgument);   // thiscall with two stack parameters ('retn 8'), returning a bool in AL ✓✓
};

// pdb: PathingLOSMap::GetUnseenNavMeshAndTriangle | PathingLOSMap.obj | fnv360_0721_beta, caller_sim, low
// pdb params: aRetNavMesh, aRetTriangle
bool Holder5FF::FUN_005fff00(void* firstArgument, void* secondArgument) {
    if (this->enabled24 == 0)                         // ORIG: cmp dword ptr [edi+24h],0 ; jnz past - the zero case falls straight into its own epilogue copy ✓✓ 
        return false;

    for (unsigned int index = 0; index < this->count2C; ++index) {          // ORIG: pre-test 'cmp [edi+2Ch],esi ; jbe' then bottom 'add esi,1 ; cmp esi,[edi+2Ch] ; jb' - the count is read again at
                                                                           //         the back edge, so it must not be cached in a local ✓✓ 
        if (this->flags[index] <= 0) {                // ORIG: mov eax,[edi+18h] ; cmp byte ptr [esi+eax],0 ; jg next - signed element compare, greater-than-zero skips the call ✓✓ 
            if (this->FUN_005ffe50(index, firstArgument, secondArgument))    // ORIG: push ebx(arg_4) ; push ebp(arg_0) ; push esi ; mov ecx,edi ; call sub_5FFE50 ✓✓ 
                return true;                          // ORIG: test al,al ; jnz 0x5FFF49 - the true tail with 'mov al,1' ✓✓ 
        }
    }

    return false;                                     // ORIG 0x5FFF40: xor al,al after unwinding esi/ebp/ebx and edi ✓✓ 
}

}
}   // namespace f3m_005fff00

// @f3 0x005f7cc0 (community match, verified in this file)
namespace f3m_005f7cc0 {
struct Loc14;

int __cdecl FUN_005f5eb0(void* aP, float aF, Loc14* aOut, int aFlag);

unsigned char __cdecl FUN_005f7cc0(void* aP, float aF, Loc14* aOut)
{
    return (unsigned char)FUN_005f5eb0(aP, aF, aOut, 1);
}
}   // namespace f3m_005f7cc0

// @f3 0x005eccd0 (community match, verified in this file)
namespace f3m_005eccd0 {

extern int DAT_00dc4dc0;

struct Point5eccd0 { float x, y, z; };

struct Source5eccd0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Point5eccd0 position;
};

struct FUN_005fc430
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    FUN_005fc430(const FUN_005fc430& other);
    ~FUN_005fc430() { vtable = &DAT_00dc4dc0; }
    Source5eccd0* FUN_005fcbf0();
    void FUN_005fcba0(const Point5eccd0* point);
};

extern Point5eccd0 DAT_0108ec68;

struct Ref5eccd0
{
    const Point5eccd0* FUN_004e7580();
};

struct Entry5eccd0
{
    unsigned char flags;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    FUN_005fc430 point;
    Ref5eccd0* unk2C;
};

struct Node5eccd0
{
    unsigned int flags;
    FUN_005fc430 point;
    int unk2C;
    int unk30;
    int unk34;
    Ref5eccd0* unk38;
};

struct Table5eccd0
{
    int unk00;
    int unk04;
    int unk08;
    Entry5eccd0* entries;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    Node5eccd0* nodes;
    unsigned int nodeCount;
    Entry5eccd0* GetEntry(unsigned int i) { return &entries[i]; }
    Entry5eccd0* Entries() volatile { return entries; }
    unsigned int Count() volatile { return nodeCount; }
    Node5eccd0* Last() { if (!nodeCount) return 0; return &nodes[Count() - 1]; }
    int FUN_005c5cf0(FUN_005fc430* point, const Point5eccd0* offset);
    void AttachDoor(Ref5eccd0* ref)
    {
        Node5eccd0* node = Last();
        node->unk38 = ref;
        node->point.FUN_005fcba0(ref->FUN_004e7580());
        node->flags |= 3;
    }
};


struct Owner5eccd0
{
    int unk00;
    Table5eccd0* table;
    bool FUN_005eccd0(unsigned int first, unsigned int last);
};

// pdb: PathBuilder::BuildStraightPathForVirtualNodes | PathBuilder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiFirstVirtualNodeIndex, aiLastVirtualNodeIndex
bool Owner5eccd0::FUN_005eccd0(unsigned int first, unsigned int last)
{
    for (unsigned int i = first; i <= last; ++i)
    {
        Entry5eccd0* entry = &table->entries[i];
        FUN_005fc430 point(entry->point);
        if (!(table->entries[i].flags & 2))
            point.FUN_005fcba0(&point.FUN_005fcbf0()->position);
        table->FUN_005c5cf0(&point, &DAT_0108ec68);
    }
    if (table->entries[last].flags & 4)
        table->AttachDoor(table->entries[last].unk2C);
    return true;
}

}

// @f3 0x005eacb0 (community match, verified in this file)
namespace f3m_005eacb0 {
namespace f3m_005eacb0 {
struct Info {
    int m00, m04, m08, m0c, m10, m14, m18, m1c, m20;
    unsigned short m24;
    unsigned char kind;
};
struct Sub {
    int m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28;
    Info* PathingLocation_GetCell();
};
struct Element {
    int flags;
    Sub sub;
};
struct Storage {
    int m00, m04, m08;
    Element* data;
    int count;
    __forceinline Element* At(int i) {
        return (Element*)((char*)data + i * sizeof(Element));
    }
};
struct Owner {
    void* vtable;
    Storage* storage;
    bool FUN_005eacb0(int index, int* outStart, int* outEnd);
};
// pdb: PathBuilder::FindLoadedNodeIndices | PathBuilder.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aiFirstHighLevelNode, apFirstLoadedNodeIndex, apLastLoadedNodeIndex
bool Owner::FUN_005eacb0(int index, int* outStart, int* outEnd) {
    Info* info = storage->At(index)->sub.PathingLocation_GetCell();
    if (!info || info->kind != 6)
        return false;
    *outStart = index;
    *outEnd = index + 1;
    while (*outEnd < storage->count) {
        Info* next = storage->At(*outEnd)->sub.PathingLocation_GetCell();
        if (!next || next->kind != 6)
            break;
        if (storage->data[*outEnd].flags & 4) {
            ++*outEnd;
            break;
        }
        *outEnd = *outEnd + 1;
    }
    --*outEnd;
    return true;
}
}
}   // namespace f3m_005eacb0

// @f3 0x005ff0c0 (community match, verified in this file)
namespace f3m_005ff0c0 {
namespace Dispatch5ff0c0 {
struct Item {int unk00,unk04,unk08,unk0c;unsigned* key;int unk14,unk18,unk1c,unk20;unsigned short index;};
struct Target {bool FUN_005fed40(Item*,void*);};
struct Map {bool FUN_00bea7b0(unsigned,Target**);};
struct Object {int unk00,unk04;Map map;bool FUN_005ff0c0(Item*,void*);};
// pdb: PathingLOSGridMap::SetLocationSeen | PathingLOSGridMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: arLocation, abSeen
bool Object::FUN_005ff0c0(Item* item,void* context) {
 if(item->key && item->index!=0xffff){
  unsigned key=*item->key;
  Target* target=0;
  if(map.FUN_00bea7b0(key,&target))return target->FUN_005fed40(item,context);
 }
 return false;
}
}

}   // namespace f3m_005ff0c0

// @f3 0x005e7470 (community match, verified in this file)
namespace f3m_005e7470 {
namespace Clean5e7470 {
struct Array {virtual void slot0();virtual void slot1();virtual void release(void*);void* data;unsigned count,capacity;void FUN_005e5240(void*,unsigned);};
struct Holder {int unk00,unk04,unk08;Array array;};
struct Object {virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
virtual void slot99();
virtual void slot100();
virtual void slot101();
virtual void slot102();
virtual void slot103();
virtual void slot104();
virtual void slot105();
virtual void slot106();
virtual void slot107();
virtual void slot108();
virtual void slot109();
virtual void slot110();
virtual void slot111();
virtual void slot112();
virtual void slot113();
virtual void slot114();
virtual void slot115();
virtual void* get();};
bool FUN_005e7310(void*,Holder**);
// pdb: NavMeshObstacleManager::UpdateObstacleDataForReference | NavMeshObstacleManager.obj | fnv360_0721_beta, objrun, medium
// pdb params: apRef, apRetObstacleArray
bool FUN_005e7470(Object* object,Holder** holder){Array* array=&(*holder)->array;if(array->data){array->FUN_005e5240(array->data,array->count);array->release(array->data);array->data=0;array->capacity=0;array->count=0;}if(object->get())return FUN_005e7310(object->get(),holder);return false;}
}
}   // namespace f3m_005e7470

// @f3 0x005ee830 (community match, verified in this file)
class NavMeshPtr;
template <> class BSSimpleArray<const NavMeshInfo*, 1024> {
public:
    virtual ~BSSimpleArray();
    virtual void* FUN_005d2de0(unsigned int count);
    virtual void FUN_005bb6e0(void* data);
    const NavMeshInfo** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    BSSimpleArray() : pBuffer(0), iSize(0), SimpleArrayStorage(0) {}
};
template <> class BSSimpleArray<NavMeshPtr, 1024> {
public:
    virtual ~BSSimpleArray();
    virtual void* FUN_005d2de0(unsigned int count);
    virtual void FUN_005bb6e0(void* data);
    NavMeshPtr* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    BSSimpleArray() : pBuffer(0), iSize(0), SimpleArrayStorage(0) {}
};
class PathBuilder100 {
public:
    struct FindTriangleForLocationWaterFilter {
        virtual bool FUN_005eaa50(void*, void*, void*, void*);
        bool unk04;
    };
};
namespace target_005ee830 {
struct Heap5ee830 { unsigned int FUN_0086bcb0(); };
extern Heap5ee830 DAT_01090a78;
}
namespace target_005ee830 {
struct FUN_005ee830 {
    void* unk00;
    void* unk04;
    unsigned int unk08;
    PathBuilder100::FindTriangleForLocationWaterFilter unk0C;
    BSSimpleArray<const NavMeshInfo*, 1024> unk14;
    BSSimpleArray<NavMeshPtr, 1024> unk24;
    FUN_005ee830(void* first, void* second);
};
// pdb: PathBuilder::PathBuilder | PathBuilder.obj | fnv360_0822_retail, uvref, low
// pdb params: apRequest, apSolution
FUN_005ee830::FUN_005ee830(void* first, void* second) {
    unk08 = DAT_01090a78.FUN_0086bcb0();
    unk00 = first;
    unk04 = second;
    unk0C.unk04 = false;
}

}

// @f3 0x005e3010 (community match, verified in this file)
namespace f3m_005e3010 {
namespace f3m_5e3010 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

class RefObject {
public:
    virtual void Unk00();
    virtual void DeleteThis();
    long refCount;
};

struct RefPtr {
    RefObject* object;
    RefPtr(RefObject* p = 0) : object(p) {}
    ~RefPtr() {
        RefObject* cur = object;
        if (cur && InterlockedDecrement(&cur->refCount) == 0) {
            cur->DeleteThis();
        }
    }
    RefPtr& operator=(const RefPtr& rhs) {
        if (object != rhs.object) {
            if (rhs.object) {
                InterlockedDecrement(&rhs.object->refCount);
            }
            RefObject* cur = object;
            if (cur && InterlockedDecrement(&cur->refCount) == 0) {
                cur->DeleteThis();
            }
            object = rhs.object;
        }
        return *this;
    }
};

struct ListNode {
    RefPtr m_item;
    ListNode* m_next;
    void FUN_005e4e20();
    void FUN_005e3010();
};

// pdb: BSSimpleList<NiPointer<ObstacleData> >::RemoveAll | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkRigidBody::Kill)
void ListNode::FUN_005e3010()
{
    while (m_next) {
        ListNode* next = m_next->m_next;
        m_next->m_next = 0;
        ListNode* cur = m_next;
        if (cur) {
            cur->FUN_005e4e20();
            DAT_01090a78.FUN_0086ba60(cur);
        }
        m_next = next;
    }
    m_item = 0;
}
}
}   // namespace f3m_005e3010

// @f3 0x005f1280 (community match, verified in this file)
namespace f3m_005f1280 {
namespace c5f1280 {
struct Point3 { float x, y, z; };
}
// pdb: Pathing::DoAABBsOverlap | Pathfind.obj | fnv360_0822_retail, call_seq, medium
// pdb params: bound1Min, bound1Max, bound2Min, bound2Max
bool FUN_005f1280(const c5f1280::Point3& minA, const c5f1280::Point3& maxA, const c5f1280::Point3& minB, const c5f1280::Point3& maxB)
{
    if (minB.x >= maxA.x)
        return false;
    if (maxB.x <= minA.x)
        return false;
    if (minB.y >= maxA.y)
        return false;
    if (maxB.y <= minA.y)
        return false;
    if (minB.z >= maxA.z)
        return false;
    if (maxB.z <= minA.z)
        return false;
    return true;
}
}   // namespace f3m_005f1280

// @f3 0x005e31d0 (community match, verified in this file)
namespace f3m_005e31d0 {
namespace Init5e31d0 {
struct Resource {void* p;};struct Manager {bool FUN_00bce2c0(Resource*);bool FUN_00bce2f0(Resource*);};Manager* FUN_00bce1f0();
struct Heap {void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;extern char DAT_00e01c48,DAT_00e01b6c;
struct A {void* table;A(){table=&DAT_00e01c48;}static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}};
struct B {void* table;B(){table=&DAT_00e01b6c;}static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}};
struct Object {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; A* a;B* b;Resource resource;bool FUN_005e31d0();};
// pdb: NavMeshObstacleManager::Initialize | NavMeshObstacleManager.obj | fnv360_0822_retail, uvref, low
bool Object::FUN_005e31d0(){Resource* r=&resource;if(!FUN_00bce1f0()->FUN_00bce2c0(r))return false;if(!FUN_00bce1f0()->FUN_00bce2f0(r))return false;a=new A;b=new B;return true;}
}
}   // namespace f3m_005e31d0

// @f3 0x005f4460 (community match, verified in this file)
namespace f3m_005f4460 {
namespace f3m_005f4460 {

class FloatArray {
public:
    virtual ~FloatArray();
    virtual float* Allocate(unsigned int count);
    virtual void Deallocate(float* p);
    virtual float* Reallocate(float* p, unsigned int count);

    float* data;
    unsigned int size;
    unsigned int capacity;

    unsigned int FUN_005e5350();
    void FUN_00cb9930(float* dst, float* src, unsigned int count);
    void FUN_005f4460(unsigned int index, const float& item);
};

// pdb: BSSimpleArray<float,1024>::Insert | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiIndex, aValue
void FloatArray::FUN_005f4460(unsigned int index, const float& item)
{
    if (index == size) {
        data[FUN_005e5350()] = item;
        return;
    }
    if (size == capacity) {
        unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
        float* newData = Allocate(newCap);
        FUN_00cb9930(newData, data, index);
        FUN_00cb9930(&newData[index + 1], &data[index], size - index);
        Deallocate(data);
        data = newData;
        capacity = newCap;
    } else {
        FUN_00cb9930(&data[index + 1], &data[index], size - index);
    }
    ++size;
    data[index] = item;
}

}
}   // namespace f3m_005f4460

// @f3 0x005f0e10 (community match, verified in this file)
namespace f3m_005f0e10 {
namespace f3m_005f0e10 {
struct PathPoint {
    unsigned int unk00, unk04, unk08;
};
struct PathElement {
    unsigned int unk00, unk04, unk08;
    void FUN_005fc770();
    bool FUN_005fda30(PathPoint* point);
    int FUN_005fcbf0();
};
struct PathStorage {
    unsigned int unk00, unk04, unk08;
    PathElement first;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    PathElement second;
};
struct PathParams {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int flags;
};
struct PathStorage2 : PathStorage {};
struct PathQuery {
    PathStorage* storage;
    PathParams* params;
    unsigned int unk08;
    PathPoint point;
    bool FUN_005efb00(int a, int b);
    bool PathBuilder_BuildDetailedPath(int index);
    bool FUN_005f0e10();
    PathElement* GetSecond() { return &storage->second; }
};
// pdb: PathBuilder::BuildPath | PathBuilder.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bool PathQuery::FUN_005f0e10() {
    storage->first.FUN_005fc770();
    storage->second.FUN_005fc770();
    if (params->flags == 0) {
        int a = 0;
        int b = 0;
        if (storage->first.FUN_005fda30(&point))
            a = storage->first.FUN_005fcbf0();
        if (GetSecond()->FUN_005fda30(&point))
            b = GetSecond()->FUN_005fcbf0();
        if (!FUN_005efb00(a, b) && params->flags == 0)
            return false;
    } else {
        storage->first.FUN_005fda30(&point);
        storage->second.FUN_005fda30(&point);
    }
    return PathBuilder_BuildDetailedPath(0) ? true : false;
}
}
}   // namespace f3m_005f0e10

// @f3 0x005fcac0 (community match, verified in this file)
namespace f3m_005fcac0 {
namespace f3m_005fcac0 {
struct Point { float x,y,z; };
struct World;
struct Cell {
    unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    unsigned char flags;
    World* FUN_004d3780();
    int TESObjectCELL_GetDataY();
    int TESObjectCELL_GetDataX();
};
struct Mesh;
struct Meshes { unsigned unk00; Mesh** data; unsigned count; };
unsigned __cdecl FUN_00501250(const Point*);
unsigned __cdecl FUN_00501240(int,int);
Meshes* __cdecl FUN_005f1260(World*,unsigned);
Meshes* __cdecl FUN_005f1240(Cell*);
struct Location {
    unsigned unk00; Point position; Mesh* mesh; Meshes* meshes;
    Cell* cell; World* world; unsigned key; unsigned short triangle;unsigned char state;
    void PathingLocation_SetupData(const Point*,Cell*,World*);
};
// pdb: PathingLocation::SetupData | PathingLocation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Location::PathingLocation_SetupData(const Point* point,Cell* inputCell,World* inputWorld) {
    position=*point;
    state=0;
    if(inputWorld) {
        world=inputWorld;
        key=FUN_00501250(&position);
        cell=0;
        meshes=FUN_005f1260(world,key);
    } else {
        meshes=FUN_005f1240(inputCell);
        if(inputCell && !(inputCell->flags&1)) {
            world=inputCell->FUN_004d3780();
            key=FUN_00501240(inputCell->TESObjectCELL_GetDataX(),inputCell->TESObjectCELL_GetDataY());
            cell=0;
        } else {
            cell=inputCell;
            world=0;
            key=0xdeaddead;
        }
    }
    if(meshes && meshes->count==1) {
        state|=1;
        mesh=meshes->data[0];
        meshes=0;
    } else {
        state&=~1;
        mesh=0;
    }
    triangle=0xffff;
}
}
}   // namespace f3m_005fcac0

// @f3 0x005e7d90 (community match, verified in this file)
namespace f3m_005e7d90 {
namespace n5e7d90 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern int (__stdcall* DAT_00d9b084)(unsigned long, void*);

struct RefObj {
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};
template <class T>
struct NiPointer {
    T* m_pObject;
    NiPointer() { m_pObject = 0; }
    ~NiPointer() {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer& operator=(T* p) {
        if (m_pObject != p) {
            if (p) p->IncRefCount();
            if (m_pObject) m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
    operator T*() const { return m_pObject; }
};
struct Worker {
    void FUN_005e6cd0(int* out);
};
struct Slot {
    DWORD tid;
    Worker* obj;
};
struct TlsInfo {
    unsigned int max;
    DWORD index;
    Slot* slots;
    long counter;
};
struct Pool {
    virtual void v00();
    virtual Worker* Create(unsigned int i);
    virtual void v08();
    virtual void v0c();
    virtual unsigned int Count();
    int unk04, unk08, unk0c, unk10;
    TlsInfo* tls;
    Worker* GetLocal() {
        TlsInfo* t = tls;
        Worker* w = (Worker*)DAT_00d9b080(t->index);
        if (w)
            return w;
        Worker* r = 0;
        long* pCounter = &t->counter;
        unsigned int i = InterlockedIncrement(pCounter) - 1;
        if (i < t->max) {
            r = Create(i);
            t->slots[i].obj = r;
            t->slots[i].tid = GetCurrentThreadId();
            DWORD index = t->index;
            DAT_00d9b084(index, r);
        }
        return r;
    }
};
struct Node {
    RefObj* item;
    Node* next;
};
struct List {
    Node head;
    Node* Find(const NiPointer<RefObj>& o) {
        for (Node* n = &head; n != 0; n = n->next)
            if (n->item == o.m_pObject)
                return n;
        return 0;
    }
    __declspec(noinline) void FUN_008f2610(const NiPointer<RefObj>& p) {
        if (!head.item)
            head.item = p.m_pObject;
    }
};
struct MapItem {
    MapItem* next;
    int key;
    RefObj* val;
};
struct Map {
    void** vtbl;
    unsigned int hashSize;
    MapItem** table;
    unsigned int count;
    __declspec(noinline) bool FUN_005c8b00(int key, NiPointer<RefObj>& out) {
        for (MapItem* it = table[(unsigned int)key % hashSize]; it; it = it->next) {
            if (it->key == key) {
                out = it->val;
                return true;
            }
        }
        return false;
    }
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    List unk3c;
    Pool unk44;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
    Map unk7c;
    void FUN_005e7d90();
};
// pdb: NavMeshObstacleManager::ProcessActivatedObstacles | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
void Owner::FUN_005e7d90()
{
    int key;
    unsigned int n = unk44.Count();
    for (unsigned int i = 0; i < n; i++) {
        unk44.GetLocal()->FUN_005e6cd0(&key);
        NiPointer<RefObj> ref;
        if (unk7c.FUN_005c8b00(key, ref)) {
            if (unk3c.Find(ref))
                continue;
            unk3c.FUN_008f2610(ref);
        }
    }
}
}
}   // namespace f3m_005e7d90

// @f3 0x005feea0 (community match, verified in this file)
namespace f3m_005feea0 {
struct Heap5fee {
    void* FUN_0086b930(unsigned int a_uiSize);
    void FUN_0086ba60(void* a_pMemory);
};
extern Heap5fee DAT_01090a78;

struct Stream5fee {
    unsigned int BGSLoadGameBuffer_LoadVariableSizedValue();
    void FUN_006e06d0(unsigned int* a_puiOut);
};

struct FormMap5fee {
    bool FUN_00bea7b0(unsigned int a_uiFormID, void*& a_rpForm);
};

struct DataHandler5fee {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FormMap5fee kForms;
};

struct Manager5fee {
    DataHandler5fee* FUN_00433ff0();
};
extern Manager5fee* DAT_0107a0d8;

inline void* LookupForm5fee(unsigned int a_uiFormID) {
    DataHandler5fee* pHandler = DAT_0107a0d8->FUN_00433ff0();
    void* pFound;
    return pHandler->kForms.FUN_00bea7b0(a_uiFormID, pFound) ? pFound : 0;
}

template <class T>
class Array5fee {
public:
    Array5fee(unsigned int a_iReserve = 0) : pBuffer(0), iSize(0), iReservedSize(0) {
        if (a_iReserve) {
            pBuffer = _Allocate(a_iReserve);
            iReservedSize = a_iReserve;
        }
    }
    virtual ~Array5fee();
    virtual T* _Allocate(unsigned int a_iCount);
    virtual void _Deallocate(T* a_pData);
    virtual T* _Reallocate(T* a_pData, unsigned int a_iCount);

    T* pBuffer;
    unsigned int iSize;
    unsigned int iReservedSize;
};

struct Element5fee {
    static void* operator new(unsigned int a_uiSize) { return DAT_01090a78.FUN_0086b930(a_uiSize); }
    static void operator delete(void* a_pMemory);

    Element5fee() {
        bFlag = false;
        pForm = 0;
        iIndex = -1;
    }
    void FUN_005fece0(Stream5fee* a_pStream);

    bool bFlag;
    Array5fee<int> kData;
    void* pForm;
    int iIndex;
};

class FUN_005ff110 : public Array5fee<Element5fee*> {
public:
    void* pForm;

    void FUN_00799ae0(unsigned int a_iNewSize, unsigned int a_iMoveCount);

    __forceinline void SetSize(unsigned int a_iSize) {
        if (a_iSize == 0) {
            if (pBuffer) {
                _Deallocate(pBuffer);
                pBuffer = 0;
                iReservedSize = 0;
                iSize = 0;
            }
        } else if (a_iSize > iReservedSize) {
            if (iReservedSize == 0)
                { Element5fee** pNew = _Allocate(a_iSize); pBuffer = pNew; }
            else
                FUN_00799ae0(a_iSize, iSize);
            iReservedSize = a_iSize;
            iSize = a_iSize;
        } else if (a_iSize < iSize) {
            iSize = a_iSize;
            if (a_iSize <= (iReservedSize >> 2)) {
                FUN_00799ae0(a_iSize, a_iSize);
                iReservedSize = a_iSize;
            }
        } else {
            iSize = a_iSize;
        }
    }

    void FUN_005feea0(Stream5fee* a_pStream);
};

// pdb: PathingLOSGrid::LoadGame | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apLoadGameBuffer
void FUN_005ff110::FUN_005feea0(Stream5fee* a_pStream) {
    unsigned int uiFormID = 0;
    a_pStream->FUN_006e06d0(&uiFormID);
    pForm = LookupForm5fee(uiFormID);

    unsigned int uiCount = a_pStream->BGSLoadGameBuffer_LoadVariableSizedValue();
    SetSize(uiCount);
    for (unsigned int i = 0; i < uiCount; i++) {
        Element5fee*& rpElement = pBuffer[i];
        (rpElement = new Element5fee)->FUN_005fece0(*(Stream5fee* volatile*)&a_pStream);
        rpElement->pForm = pForm;
    }
}
}

// @f3 0x005ffc30 (community match, verified in this file)
namespace f3m_005ffc30 {

struct Heap5ffc { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap5ffc DAT_01090a78;

struct RefObj5ffc
{
    virtual ~RefObj5ffc();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

struct Item5ffc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    RefObj5ffc ref;
    int FUN_005b84c0();
};

struct ItemRef5ffc
{
    Item5ffc* item;
    ItemRef5ffc(Item5ffc* const& p) : item(p) { if (item) item->ref.IncRefCount(); }
    ~ItemRef5ffc() { item->ref.DecRefCount(); }
};

struct Input5ffc;

struct Handler5ffc { void FUN_005fe990(Input5ffc* input); };

struct State5ffc { Handler5ffc** data; unsigned int count; int unk0C; ~State5ffc(); };

struct FUN_005ffa60
{
    virtual ~FUN_005ffa60();
    State5ffc state;
    int unk10;
    FUN_005ffa60(int value);
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Source5ffc
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    Item5ffc** items;
    unsigned int count;
    int unk28;
    int unk2C;
    unsigned int done;
    unsigned int remaining;
};

struct Input5ffc { Source5ffc* source; };

struct Map5ffc
{
    int unk00; int unk04; int unk08; int unk0C;
    __declspec(noinline) bool FUN_00bea7b0(int key, FUN_005ffa60** out) { if (!unk04) return false; *out = (FUN_005ffa60*)unk08; return key != unk00; }
    void FUN_00880f70(int key, FUN_005ffa60* value);
    void Set(int key, FUN_005ffa60* value) { FUN_00880f70(key, value); }
    bool Get(int key, FUN_005ffa60** out)
    {
        return FUN_00bea7b0(key, out);
    }
};

struct Lock5ffc
{
    void FUN_0086cc50();
    void FUN_0086cde0();
};

inline float Ratio(unsigned int done, unsigned int remaining)
{
    unsigned int total = done + remaining;
    if (total)
        return (float)done / (float)total;
    return 1.0f;
}

struct Owner5ffc
{
    int unk00;
    int unk04;
    Map5ffc map;
    float fraction;
    int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    int unk3C; int unk40; int unk44; int unk48;
    Lock5ffc lock;
    bool FUN_005ffc30(Input5ffc* input);
};

// pdb: PathingLOSGridMap::SetSeenTrianglesFromLOSMap | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aspLOSMap
bool Owner5ffc::FUN_005ffc30(Input5ffc* input)
{
    Lock5ffc* guard = &lock;
    guard->FUN_0086cc50();
    unsigned int i = 0;
    unsigned int n = input->source->count;
    if (n > i)
    {
        do
        {
        ItemRef5ffc item(input->source->items[i]);
        FUN_005ffa60* list;
        FUN_005ffa60* found = 0;
        if (!map.Get(item.item->unk0C, &found))
        {
            list = new FUN_005ffa60(item.item->FUN_005b84c0());
            map.Set(item.item->unk0C, list);
        }
        else
        {
            list = found;
        }
        for (unsigned int j = 0; j < list->state.count; ++j)
            list->state.data[j]->FUN_005fe990(input);
        } while (++i < input->source->count);
    }
    fraction = Ratio(input->source->done, input->source->remaining);
    guard->FUN_0086cde0();
    return true;
}

}

// @f3 0x005ea490 (community match, verified in this file)
namespace f3m_005ea490 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
namespace n5ea490 {
struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    long refCount;
    void IncRefCount() { ::InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!::InterlockedDecrement(&refCount)) DeleteThis(); }
};
struct Target {
    int u00, u04, u08, u0c, u10, u14, u18;
    RefObj ref;
};
struct Ptr {
    Target* p;
    Ptr(Target* obj = 0) : p(obj) { if (p) p->ref.IncRefCount(); }
    ~Ptr() { if (p) p->ref.DecRefCount(); }
    Ptr& operator=(const Ptr& o) {
        if (p != o.p) {
            if (p) p->ref.DecRefCount();
            p = o.p;
            if (p) p->ref.IncRefCount();
        }
        return *this;
    }
};
__declspec(noinline) void __cdecl FUN_005b87d0(Ptr* out, Target* src) {
    Ptr tmp(src);
    *out = tmp;
}
extern void __cdecl MayThrow5ea();
struct Entry {
    int key; int flags; int m8; Ptr mc;
    Entry() : key(0), mc(0) {}
    __declspec(noinline) Entry(const int* k, int type, const Ptr& ptr) : key(*k), flags(type), m8(0), mc(ptr) { MayThrow5ea(); }
    __declspec(noinline) ~Entry() { MayThrow5ea(); }
    __declspec(noinline) Entry& operator=(const Entry& o) { MayThrow5ea(); key = o.key; flags = o.flags; m8 = o.m8; mc = o.mc; return *this; }
};
struct Array {
    void* vt; Entry* data; unsigned int count;
    __declspec(noinline) unsigned int FUN_005b90b0() { return count++; }
    void FUN_005ea3b0(unsigned int index, unsigned int n);
    void Add(const Entry& e) { unsigned int i = FUN_005b90b0(); new (&data[i]) Entry; data[i] = e; }
};
struct Info {
    int u00, u04;
    unsigned int flags;
    int u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50;
    Target* m54;
    bool IsDeleted() const { return (flags >> 4) & 1; }
    bool GetNavMesh(Ptr& out) const {
        if (IsDeleted())
            return false;
        FUN_005b87d0(&out, m54);
        return out.p != 0;
    }
};
struct Owner {
    int u00, u04, u08, u0c, u10, u14;
    Info* info;
    int u1c, u20;
    Array list;
    bool FUN_005ea490(const int* key, int type);
};
}
// pdb: ObstacleTaskData::AddOperation | NavMeshObstacleTask.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apObstacle, aeType
bool n5ea490::Owner::FUN_005ea490(const int* key, int type)
{
    switch (type) {
    case 0x20:
    case 0x21: {
        bool ok = true;
        for (unsigned int i = 0; i < list.count; i++) {
            if (list.data[i].key == *key) {
                if ((list.data[i].flags & 0x30) == 0x10) {
                    list.FUN_005ea3b0(i, 1);
                    i--;
                } else
                    ok = false;
            }
        }
        if (!ok)
            return false;
        break;
    }
    case 0x10:
    case 0x11:
        for (unsigned int i = 0; i < list.count; i++)
            if (list.data[i].key == *key && (list.data[i].flags & 0x30) == 0x10)
                return false;
        break;
    case 0x30:
        for (unsigned int i = 0; i < list.count; i++)
            if (list.data[i].key == *key && list.data[i].flags == 0x30)
                return false;
        break;
    case 0x40:
        for (unsigned int i = 0; i < list.count; i++)
            if (list.data[i].key == *key && list.data[i].flags == 0x40)
                return false;
        break;
    default:
        return false;
    }
    Ptr ptr;
    if (info->GetNavMesh(ptr)) {
        list.Add(Entry(key, type, ptr));
        return true;
    }
    return false;
}
}   // namespace f3m_005ea490

// @f3 0x005ed6c0 (community match, verified in this file)
namespace f3m_005ed6c0 {

extern void* DAT_00dc4dc0;
extern const float DAT_00e01370 = -64.0f;
extern const float DAT_00de7c24 = 180.0f;

struct Point
{
    float x, y, z;
    Point() {}
    Point(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Point operator-(const Point& other) const { return Point(x - other.x, y - other.y, z - other.z); }
    Point operator*(float scale) const { return Point(x * scale, y * scale, z * scale); }
    Point& operator+=(const Point& other) { x += other.x; y += other.y; z += other.z; return *this; }
    float GetSquaredXYLength() const { return x * x + y * y; }
};

struct RefCounter
{
    void** table;
    long refs;
    void Release()
    {
        if (!InterlockedDecrement(&refs))
            ((void(__thiscall*)(RefCounter*))table[1])(this);
    }
};

struct NavMesh
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    RefCounter counter;
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
    void FUN_005b8960(unsigned short triangle, int edge, Point& first, Point& second);
    void FUN_004d45e0(Point& center, unsigned short triangle);
};

__declspec(noalias) void __cdecl FUN_005b87d0(NiPointer<NavMesh>* apDest, void* apSource);

struct NavMeshInfo
{
    int unk00; int unk04;
    unsigned int flags;
    int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50;
    void* unk54;
    bool IsBusy() { return (flags >> 4) & 1; }
    bool GetNavMesh(NiPointer<NavMesh>* apOut)
    {
        if (IsBusy())
            return false;
        FUN_005b87d0(apOut, unk54);
        return apOut->m_pObject != 0;
    }
};

struct Edge
{
    NavMeshInfo* info;
    unsigned short triangle;
    unsigned short flags;
    int edge;
    Point position;
    Edge& Copy(const Edge* other)
    {
        info = other->info;
        triangle = other->triangle;
        edge = other->edge;
        return *this;
    }
};

struct EdgeInput
{
    int unk00;
    Edge* first;
    Edge* GetFirstEntry() { return first; }
};

struct Location
{
    void* vtable;
    Point position;
    Point GetPosition() const { return position; }
};

struct Node
{
    int unk00;
    Location location;
    int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    Location* GetLocation() { return &location; }
};

struct Solution
{
    int unk00; int unk04; int unk08;
    Node* nodes;
    Node* GetNode(unsigned int index) { return &nodes[index]; }
};

struct Request
{
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c; int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c; int u60; int u64; int u68; int u6c; int u70;
    float radius;
    float GetCenterRadius() { return radius; }
};

struct PathLoc
{
    void* vtable;
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;
    PathLoc(const Point& point, NavMeshInfo* info, unsigned short triangle) { FUN_005fc5a0(point, info, triangle); }
    ~PathLoc() { vtable = &DAT_00dc4dc0; }
    void FUN_005fc5a0(const Point& point, NavMeshInfo* info, unsigned short triangle);
};

struct PathArray
{
    void FUN_005d0d40(bool flag);
    int FUN_005ecde0(PathLoc* location);
};

void __cdecl FUN_005dd040(Point* out, const Point& point, const Point& first, const Point& second);

struct Builder
{
    Request* request;
    Request* GetRequest() { return request; }
    Solution* solution;
    bool FUN_005ed6c0(unsigned int index, EdgeInput* input, PathArray* output);
};

// pdb: PathBuilder::CheckClosestEdgeToGoal | PathBuilder.obj | fnv360_0822_retail, objrun, medium
// pdb params: aiLastVirtualNodeIndex, aEndEdges, aEndNodes
bool Builder::FUN_005ed6c0(unsigned int index, EdgeInput* input, PathArray* output)
{
    Edge edge;
    edge.Copy(input->GetFirstEntry());
    Point first;
    Point second;
    NiPointer<NavMesh> mesh;
    if (edge.info->GetNavMesh(&mesh))
    {
        NavMesh* navMesh = mesh;
        navMesh->FUN_005b8960(edge.triangle, edge.edge, first, second);
        Point position = solution->GetNode(index)->GetLocation()->GetPosition();
        Point closest;
        FUN_005dd040(&closest, position, first, second);
        if ((closest - position).GetSquaredXYLength() < GetRequest()->GetCenterRadius() * request->GetCenterRadius() &&
            (closest - position).z > DAT_00e01370 && (closest - position).z < DAT_00de7c24)
        {
            Point center;
            navMesh->FUN_004d45e0(center, edge.triangle);
            closest += (center - closest) * 0.1f;
            output->FUN_005d0d40(false);
            PathLoc location(closest, edge.info, edge.triangle);
            output->FUN_005ecde0(&location);
            return true;
        }
    }
    return false;
}

}

// @f3 0x005e6a60 (community match, verified in this file)
namespace f3m_005e6a60 {
namespace c4_005e6a60 {

struct RefObj
{
    virtual void v00();
    virtual void* DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (::InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct SimpleArray
{
    virtual void v00();
    T* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int GetSize() const { return size; }
    T* GetPtr(unsigned int i) { return &data[i]; }
    T& GetAt(unsigned int i) { return data[i]; }
    T* GetData() { return data; }
};

struct Item : RefObj
{
};

struct Group : RefObj
{
    int unk08;
    SimpleArray<Item*> items;
};

template <class T> struct Pointer
{
    T* object;
    Pointer() : object(0) {}
    ~Pointer()
    {
        if (object)
            object->DecRefCount();
    }
    T* operator->() const { return object; }
};

struct GroupMap
{
    __declspec(noalias) bool FUN_005c8b00(const char* key, Pointer<Group>& out);
};

struct ItemList
{
    void FUN_004c25a0(Item** item);
};

struct NameNode
{
    const char* item;
    NameNode* next;
    void FUN_006c8220();
};

struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    GroupMap groups;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NameNode names;
    ItemList list3C;
    void FUN_005e6810(const char* name);
    void FUN_005e6a60();
};

// pdb: NavMeshObstacleManager::ProcessRemovedReferences | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
void Owner::FUN_005e6a60()
{
    for (NameNode* node = &names; node; )
    {
        if (!node->next && !node->item)
            break;
        const char* name = node->item;
        node = node->next;
        Pointer<Group> group;
        if (groups.FUN_005c8b00(name, group))
        {
            for (unsigned int i = 0; i < group->items.GetSize(); i++) list3C.FUN_004c25a0(group->items.GetPtr(i));
        }
        FUN_005e6810(name);
    }
    names.FUN_006c8220();
}

}
}   // namespace f3m_005e6a60

// @f3 0x005f0af0 (community match, verified in this file)
namespace F3Curve2274 {
extern void* DAT_00dc4dc0;
struct Point {
    float x, y, z;
    Point() {}
    Point(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y, z - o.z); }
    float FUN_0046c090() const;
};
struct FUN_005fc430 {
    void** table;
    Point position;
    unsigned unk10, unk14, unk18, unk1c, unk20;
    unsigned short unk24;
    unsigned char unk26;
    FUN_005fc430(const FUN_005fc430&);
    ~FUN_005fc430() { table = &DAT_00dc4dc0; }
};
struct PathEntry {
    unsigned unk00;
    FUN_005fc430 sample;
    Point tangent;
    unsigned unk38;
    void SetTangent(const Point* p) { tangent = *p; }
    const FUN_005fc430& GetSample() const { return sample; }
};
struct PathData {
    unsigned unk00, unk04, unk08, unk0c;
    int total;
    unsigned unk14;
    int first, last;
    unsigned unk20;
    PathEntry* entries;
    unsigned count;
    void FUN_005ec100();
    int GetLast() const { return last; }
    int GetTotal() const { return total; }
    PathEntry* GetNode(unsigned i) { return entries + i; }
    unsigned GetNodeCount() const { return count; }
};
struct Settings {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64;
    float scale;
    unsigned unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    float endAngle, startAngle;
    unsigned unk94;
    unsigned char unk98;
    bool endCurve;
    unsigned short unk9a;
    unsigned unk9c;
    bool startCurve;
    float GetScale() const { return scale; }
    float GetStartAngle() const { return startAngle; }
    float GetEndAngle() const { return endAngle; }
    bool HasStartCurve() const { return startCurve; }
    bool HasEndCurve() const { return endCurve; }
};
extern void __cdecl FUN_005f27d0(Point*, float, const FUN_005fc430&, const FUN_005fc430&, float);
extern void __cdecl FUN_005f30c0(Point*, float, const FUN_005fc430&, float);
struct Owner {
    Settings* settings;
    PathData* data;
    bool FUN_005eacb0(void*, int*, int*);
    bool FUN_005f09e0();
    bool PathBuilder_BuildDetailedPath(void*);
};
// pdb: PathBuilder::BuildDetailedPath | PathBuilder.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
bool Owner::PathBuilder_BuildDetailedPath(void* request)
{
    data->FUN_005ec100();
    {
        int last, first;
        first = -1;
        last = -1;
        if (!FUN_005eacb0(request, &first, &last))
            return true;
        data->first = first;
        data->last = last;
    }
    const bool valid = FUN_005f09e0();
    if (!valid && data->count == 0)
        return valid;
    const bool startCurve = settings->startCurve;
    if (startCurve && data->first == 0 && data->count >= 2) {
        PathEntry* start = data->GetNode(0);
        PathEntry* next = data->GetNode(1);
        if (start && next) {
            FUN_005fc430 a(start->sample);
            FUN_005fc430 b(next->sample);
            if ((b.position - a.position).FUN_0046c090() > 4096.0f) {
                Point tangent;
                FUN_005f27d0(&tangent, settings->GetStartAngle(), a, b, settings->GetScale());
                start->SetTangent(&tangent);
            }
        }
    }
    if (valid && settings->endCurve && data->GetLast() == data->GetTotal() - 1) {
        unsigned count = data->GetNodeCount();
        PathEntry* end = data->GetNode(count - 1);
        PathEntry* before = data->GetNode(count - 2);
        if (end && before) {
            FUN_005fc430 a(end->sample);
            FUN_005fc430 b(before->sample);
            if ((a.position - b.position).FUN_0046c090() > 4096.0f) {
                FUN_005fc430 endpoint(end->sample);
                Point tangent;
                FUN_005f30c0(&tangent, settings->endAngle, endpoint, settings->scale);
                end->SetTangent(&tangent);
            }
        }
    }
    return valid;
}
}

// @f3 0x005e6cd0 (community match, verified in this file)
namespace f3m_005e6cd0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);

namespace S005e6cd0_q {

struct Node;

inline Node* CompareExchange(Node** destination, Node* exchange, Node* comparand)
{
    return (Node*)InterlockedCompareExchange((long volatile*)destination, (long)exchange, (long)comparand);
}

struct Node {
    Node* next;
    void* data;
};

struct Queue {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void OnDequeue();
    Node* head;
    Node* tail;
    unsigned int threshold;
};

struct Owner {
    Queue* queue;
    Node** hazard0;
    Node** hazard1;
    unsigned int retiredCount;
    Node* retiredHead;
    void FUN_005e53b0();
    void Retire(Node* node)
    {
        node->data = 0;
        node->data = retiredHead;
        retiredHead = node;
        ++retiredCount;
        if (retiredCount == queue->threshold)
            FUN_005e53b0();
    }
    bool FUN_005e6cd0(void** out);
};

// pdb: LockFreeQueue<bhkRigidBody *>::LockFreeQueueInterface::Pop | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: arData
bool Owner::FUN_005e6cd0(void** out)
{
    Node* volatile head = 0;
    Node* volatile next;
    for (;;) {
        head = queue->head;
        *hazard0 = head;
        if (head != queue->head)
            continue;
        Node* tail = queue->tail;
        next = head->next;
        *hazard1 = next;
        if (head != queue->head)
            continue;
        if (next == 0) {
            *hazard0 = 0;
            *out = 0;
            return false;
        }
        if (head == tail) {
            CompareExchange(&queue->tail, next, tail);
            continue;
        }
        *out = next->data;
        Node* expected = head;
        if (CompareExchange(&queue->head, next, expected) == expected)
            break;
    }
    queue->OnDequeue();
    next->data = 0;
    *hazard0 = 0;
    *hazard1 = 0;
    Retire(head);
    return true;
}

}
}   // namespace f3m_005e6cd0

// @f3 0x005e53b0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
#include <string.h>
#include <stddef.h>
extern __declspec(thread) int DAT_0117c298;
namespace Q5e53b0 {
struct Heap { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct MemoryContext {
    int saved;
    MemoryContext() { saved = DAT_0117c298; DAT_0117c298 = 6; }
    ~MemoryContext() { DAT_0117c298 = saved; }
};
struct Node { int unk00; Node* next; };
struct Manager { unsigned int threads; };
struct Queue {
    void* vtbl;
    void* head;
    void* tail;
    unsigned int deleteBatchSize;
    Node** deletedBuffers;
    Manager* manager;
};
struct EntryNode {
    Queue* queue;
    int unk04;
    int unk08;
    unsigned int count0C;
    Node* head;
    void FUN_005e53b0();
};
}
namespace Q5e53b0 {
// pdb: LockFreeQueue<bhkRigidBody *>::LockFreeQueueInterface::ScanForDeletedNodes | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, low
void EntryNode::FUN_005e53b0()
{
    MemoryContext context;
    unsigned int limit = queue->manager->threads * 2;
    Node** keep = new Node*[limit];
    _ReadWriteBarrier();
    Node** src = queue->deletedBuffers;
    _ReadWriteBarrier();
    memcpy(keep, src, limit * sizeof(Node*));
    Node* retained = 0;
    unsigned int count = 0;
    while (head) {
        Node* node = head;
        bool found = false;
        unsigned int i = 0;
        head = node->next;
        for (; i < limit; ++i) {
            if (node == keep[i]) {
                found = true;
                break;
            }
        }
        if (found) {
            ++count;
            node->next = retained;
            retained = node;
        } else {
            node->next = 0;
            Q5e53b0::DAT_01090a78.FUN_0086ba60(node);
        }
    }
    Q5e53b0::DAT_01090a78.FUN_0086ba60(keep);
    head = retained;
    count0C = count;
}
}

// @f3 0x005e9df0 (community match, verified in this file)
namespace f3m_005e9df0 {
namespace f3m_005e9df0 {

struct Entry;
struct OrderingContext {
    int FUN_005be340(const Entry*);
};
struct ContextRef {
    OrderingContext* volatile value;
    void FUN_0040eaf0(OrderingContext* const&);
    void FUN_0040eb10();
    ContextRef(OrderingContext* const& source) { FUN_0040eaf0(source); }
    ~ContextRef() { FUN_0040eb10(); }
};
struct Record {
    int unk00, unk04;
    int order;
};
struct RecordLink {
    int unk00, unk04;
    Record* record;
};
struct Entry {
    RecordLink* link;
    int type;
    int unk08;
    OrderingContext* context;
};

int __cdecl FUN_005e9df0(const void* a, const void* b)
{
    const Entry* first = *(const Entry**)&a;
    const Entry* second = (const Entry*)b;
    switch (first->type) {
        case 0x40:
            return second->type == 0x40 ? 0 : -1;
        case 0x30:
            return second->type != 0x30;
        case 0x10:
        case 0x11:
            switch (second->type) {
                case 0x20:
                case 0x21:
                case 0x40:
                    return 1;
                case 0x10:
                case 0x11:
                    return first->link->record->order - second->link->record->order;
                case 0x30:
                    return -1;
            }
            break;
        case 0x20:
        case 0x21:
            switch (second->type) {
                case 0x10:
                case 0x11:
                case 0x30:
                    return -1;
                case 0x40:
                    return 1;
                case 0x20:
                case 0x21: {
                    ContextRef context(first->context);
                    OrderingContext* ordering = context.value;
                    if (ordering) {
                        int firstIndex = ordering->FUN_005be340(first);
                        int secondIndex = ordering->FUN_005be340(second);
                        return secondIndex - firstIndex;
                    }
                    return 0;
                }
            }
            break;
    }
    return 0;
}

}
}   // namespace f3m_005e9df0

// @f3 0x005e27a0 (community match, verified in this file)
extern int DAT_00db72c8;
namespace f3m_005e27a0 {
namespace f3m_005e27a0 {

struct Word16 { unsigned short v; __forceinline Word16(unsigned short x) : v(x) {} };
struct Key {
    int id;
    unsigned short index;
    int extra;
    __forceinline void Set(int a_id, int a_extra, Word16 a_index)
    {
        id = a_id;
        index = a_index.v;
        extra = a_extra;
    }
};

int __cdecl FUN_005df2a0(const Key* left, const Key* right);
int __cdecl FUN_0079e5b0(const void* left, const void* right);
void __cdecl FUN_00c011c0(void* base, int count, int width, int (__cdecl* compare)(const void*, const void*));

struct KeyArray {
    void** vtbl;
    Key* data;
    unsigned size;
    unsigned cap;
    int FUN_004650c0(const Key* key, unsigned start, int (__cdecl* pred)(const Key*, const Key*));
    unsigned FUN_007a1650();
    void FUN_005df840(unsigned index, bool shrink);
};

struct Lists {
    KeyArray primary;
    KeyArray secondary;
};

struct Rec {
    Key k1;
    Key k2;
    bool flag;
};

struct VarEntry {
    int unk00;
    int unk04;
    unsigned short index08;
    unsigned short unk0A;
    unsigned short word0C;
    unsigned short unk0E;
    unsigned type10;
    int unk14;
    int unk18;
    int unk1C;
    Key ref20;
};

struct Holder {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    ::f3m_005e0330::Owner5e03 refs50;
};

struct IdArray {
    void* vtbl;
    int* data;
    unsigned size;
    unsigned cap;
    __forceinline IdArray() : vtbl(&::DAT_00db72c8), data(0), size(0), cap(0) {}
    int Find(const int& item) const
    {
        for (unsigned i = 0; i < size; ++i) {
            if (data && data[i] == item)
                return i;
        }
        return -1;
    }
    __forceinline ~IdArray()
    {
        vtbl = &::DAT_00db72c8;
        if (data) {
            ((void (__thiscall* const*)(IdArray*, int*))&::DAT_00db72c8)[2](this, data);
        }
    }
};

struct VarArray {
    void* vtbl;
    VarEntry** data;
    unsigned size;
    unsigned cap;
    __forceinline VarEntry*& operator[](unsigned index) { return data[index]; }
};

struct ScriptHost {
    int unk00;
    int unk04;
    Holder* unk08;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    VarArray vars30;

    void FUN_005e27a0(Lists* lists);
};

__forceinline void AssignKey(Key& dst, const Key& src)
{
    dst.id = src.id;
    dst.index = src.index;
    dst.extra = src.extra;
}

// pdb: NavMeshObstacleCutter::CreateSwappedEdgeList | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
// pdb params: aPortalSwaps
void ScriptHost::FUN_005e27a0(Lists* lists)
{
    IdArray ids;
    unsigned count = vars30.size;
    unsigned index = 0;
    if (count > 0) {
        do {
            if (vars30[index]->type10 == 4 && vars30[index]->index08 != 0xFFFF) {
                Rec rec;
                rec.k2.Set(0, vars30.data[index]->word0C, vars30.data[index]->index08);
                AssignKey(rec.k1, vars30[index]->ref20);
                rec.flag = true;

                ::f3m_005e0330::Owner5e03* grown = &unk08->refs50;
                unsigned slot = grown->FUN_005e0330();
                Rec* dest = ((Rec*)grown->unk04) + slot;
                AssignKey(dest->k1, rec.k1);
                AssignKey(dest->k2, rec.k2);
                dest->flag = rec.flag;

                int found = lists->primary.FUN_004650c0(&rec.k1, 0, FUN_005df2a0);
                if (found != -1) {
                    if (ids.Find(found) == -1) {
                        unsigned added = ((::f3m_005e5350::Match5e53::Owner5e53*)&ids)->FUN_005e5350();
                        ids.data[added] = found;
                    }
                } else {
                    KeyArray* secondary = &lists->secondary;
                    int foundSecondary = secondary->FUN_004650c0(&rec.k1, 0, FUN_005df2a0);
                    if (foundSecondary == -1) {
                        unsigned added = secondary->FUN_007a1650();
                        Key* keyDest = secondary->data + added;
                        AssignKey(*keyDest, rec.k1);
                    }
                }

                int foundKey = lists->primary.FUN_004650c0(&rec.k2, 0, FUN_005df2a0);
                if (foundKey == -1) {
                    unsigned added = lists->primary.FUN_007a1650();
                    AssignKey(lists->primary.data[added], rec.k2);
                }
            }
            ++index;
        } while (index < vars30.size);

        if (ids.size != 0) {
            FUN_00c011c0(ids.data, (int)ids.size, 4, FUN_0079e5b0);
            for (int back = (int)ids.size - 1; back >= 0; --back)
                lists->primary.FUN_005df840((unsigned)ids.data[back], true);
        }
    }
}

}
}   // namespace f3m_005e27a0

// @f3 0x005f7b00 (community match, verified in this file)
extern const float DAT_00db38b8;
namespace f3m_005f7b00 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
namespace n5f7b00 {
void* __cdecl FUN_0089eb90(unsigned int n);
void __cdecl FUN_0089eba0(void* p);
struct NiPoint3 { float x, y, z; };
struct NiRefObject {
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m4;
    void IncRef() { InterlockedIncrement(&m4); }
    void DecRef() { if (!InterlockedDecrement(&m4)) DeleteThis(); }
};
template <class T> struct NiPointer {
    T* p;
    NiPointer(T* o) : p(o) { if (p) p->IncRef(); }
    ~NiPointer() { if (p) p->DecRef(); }
    T* operator->() const { return p; }
    operator T*() const { return p; }
};
struct Obj : NiRefObject {
    int u08, u0c, u10, u14;
    signed char* m18;
    int u1c, u20, u24, u28;
    unsigned int m2c;
    int m30;
    int m34;
    int u38, u3c, u40, u44, u48, u4c;
    Obj(NiPoint3 pos, float r);
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089eba0(p); }
    unsigned int GetCount() const { return m2c; }
    signed char GetValue(unsigned int i) const { return m18[i]; }
    void SetPositive(int n) { m30 = n; }
    void SetNegative(int n) { m34 = n; }
};
struct Src {
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    NiPoint3 m20;
    int u2c, u30, u34, u38, u3c, u40;
    float m44;
    float m48;
    bool IsValid() const { return m44 > 0.0f; }
    float GetRadius() const { return m44; }
    const NiPoint3& GetPosition() const { return m20; }
    float GetScale() const { return m48; }
    void FUN_005ff750(NiPointer<Obj>& p);
    void FUN_005ffc30(NiPointer<Obj>& p);
};
struct Elem { int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24; };
struct Data {
    int m0; Elem* m4; int m8;
    int GetCount() const { return m8; }
    Elem* GetAt(int i) { return &m4[i]; }
};
struct Weights {
    int m0; float* m4;
    float& GetAt(int i) { return m4[i]; }
};
void __cdecl FUN_005f5590(Elem* e, NiPointer<Obj>& p, int a, float r, float w);
// pdb: Pathing::ComputeLineOfSightMap | Pathfind.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aspGridMap, aLocations, apHeadings
bool __cdecl FUN_005f7b00(NiPointer<Src>& pSource, Data* entries, Weights* weights)
{
    if (!((Src*)pSource)->IsValid())
        return false;
    NiPointer<Obj> holder = new Obj(((Src*)pSource)->GetPosition(), ((Src*)pSource)->GetRadius());
    ((Src*)pSource)->FUN_005ff750(holder);
    int count = entries->GetCount();
    for (int i = 0; i < count; i++)
    {
        Elem* entry = entries->GetAt(i);
        float weight = weights ? weights->GetAt(i) : DAT_00db38b8;
        FUN_005f5590(entry, holder, 1, ((Src*)pSource)->GetScale(), weight);
    }
    int pos = 0;
    int neg = 0;
    for (unsigned int j = 0; j < ((Obj*)holder)->GetCount(); j++)
    {
        signed char v = ((Obj*)holder)->GetValue(j);
        if (v != 0x7f)
        {
            if (v > 0)
                pos++;
            else
                neg++;
        }
    }
    ((Obj*)holder)->SetPositive(pos);
    ((Obj*)holder)->SetNegative(neg);
    ((Src*)pSource)->FUN_005ffc30(holder);
    return true;
}
}
}   // namespace f3m_005f7b00

// @f3 0x005e0da0 (community match, verified in this file)
namespace f3m_005e0da0 {
struct NavVec {
 float x,y,z;
 NavVec() {}
 NavVec(float a,float b,float c):x(a),y(b),z(c) {}
 NavVec operator-(const NavVec& r) const {return NavVec(x-r.x,y-r.y,z-r.z);}
 NavVec Cross(const NavVec& r) const {return NavVec(y*r.z-z*r.y,z*r.x-x*r.z,x*r.y-y*r.x);}
 float SqrLength() const {return x*x+y*y+z*z;}
};
struct NavVertex { unsigned short index; };
struct NavEdge {
 NavVertex* first; NavVertex* second;
 unsigned short triangle0,triangle1,edge0,edge1;
 int kind;
 unsigned short unk14,property;
 unsigned char flag0,flag1;
 int unk1c,unk20,unk24,unk28;
 unsigned short metadata;
 bool FUN_005df1b0() const {return triangle0==0xffff || (triangle1==0xffff && kind!=1 && kind!=3 && kind!=4);}
 void Assign(unsigned short tri,unsigned short slot) {
  if(triangle0==0xffff) {triangle0=tri;edge0=slot;}
  else if(triangle1==0xffff) {triangle1=tri;edge1=slot;}
 }
};
struct NavTriangle {
 unsigned short vertices[3];
 unsigned short adjacent[3];
 unsigned int flags;
 NavTriangle() {adjacent[0]=0xffff;adjacent[1]=0xffff;adjacent[2]=0xffff;flags=0;}
 void SetValues(unsigned short a,unsigned short b,unsigned short c) {vertices[0]=a;vertices[1]=b;vertices[2]=c;}
 void SetPackedField(int slot,unsigned short property,unsigned char flag0,unsigned char flag1);
 void SetSlotValue(int slot,unsigned short value) {flags|=1u<<slot;adjacent[slot]=value;}
};
struct NavMeshData {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
 NavVec* vertices;
 const NavVec& GetVertexPos(unsigned short i) {return vertices[i];}
 unsigned short FUN_005ba350(const NavTriangle*);
};
struct NavBuilder {
 NavMeshData* mesh;
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
 NavEdge** edges;
 unsigned int count;
 bool FUN_005df580(NavVertex*,NavVertex*,NavVertex*);
 bool FUN_005dfb10(NavVertex*,NavVertex*,NavVertex*);
 bool FUN_005e0da0();
};
// pdb: NavMeshObstacleCutter::CreateNewTriangles | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
bool NavBuilder::FUN_005e0da0() {
 bool changed=false;
 for(unsigned int i=0;i<count;++i) {
  NavEdge* a=edges[i];
  if(!a->FUN_005df1b0()) continue;
  NavVertex *common,*left,*right;
  for(unsigned int j=i+1;j<count;++j) {
   NavEdge* b=edges[j];
   if(!b->FUN_005df1b0()) continue;
   if(a->triangle0!=0xffff && a->triangle0==b->triangle0) continue;
   if(a->first==b->first) {common=a->first;left=a->second;right=b->second;}
   else if(a->first==b->second) {common=a->first;left=a->second;right=b->first;}
   else if(a->second==b->first) {common=a->second;left=a->first;right=b->second;}
   else if(a->second==b->second) {common=a->second;left=a->first;right=b->first;}
   else continue;
   bool done=false;
   for(unsigned int k=j+1;k<count;++k) {
    NavEdge* c=edges[k];
    if(!c->FUN_005df1b0()) continue;
    if((c->first==left && c->second==right) || (c->first==right && c->second==left)) {
     if(!FUN_005df580(common,left,right)) continue;
     if(!FUN_005dfb10(common,left,right)) continue;
     NavVec dl=mesh->GetVertexPos(left->index)-mesh->GetVertexPos(common->index);
     NavVec dr=mesh->GetVertexPos(right->index)-mesh->GetVertexPos(common->index);
     NavVec normal=dl.Cross(dr);
     if(normal.SqrLength()<0.1f) break;
     NavTriangle t;
     if(normal.z<0.0f) {
      t.SetValues(common->index,right->index,left->index);
      t.SetPackedField(0,b->property,b->flag0,b->flag1);
      t.SetPackedField(1,c->property,c->flag0,c->flag1);
      if(a->kind==4) t.SetSlotValue(2,a->metadata);
      if(b->kind==4) t.SetSlotValue(0,b->metadata);
      if(c->kind==4) t.SetSlotValue(1,c->metadata);
     } else {
      t.SetValues(common->index,left->index,right->index);
      t.SetPackedField(0,a->property,a->flag0,a->flag1);
      t.SetPackedField(1,c->property,c->flag0,c->flag1);
      if(a->kind==4) t.SetSlotValue(0,a->metadata);
      if(b->kind==4) t.SetSlotValue(2,b->metadata);
      if(c->kind==4) t.SetSlotValue(1,c->metadata);
     }
     unsigned short tri=mesh->FUN_005ba350(&t);
     changed=true;
     if(normal.z<0.0f) {
      a->Assign(tri,2);
      b->Assign(tri,0);
      c->Assign(tri,1);
     } else {
      a->Assign(tri,0);
      b->Assign(tri,2);
      c->Assign(tri,1);
     }
     if(!a->FUN_005df1b0()) done=true;
     break;
    }
   }
   if(done) break;
  }
 }
 return changed;
}
}   // namespace f3m_005e0da0

// @f3 0x005e3250 (community match, verified in this file)
namespace f3m_005e3250 {


namespace N5e3250 {

struct Pt3
{
    float x, y, z;
    Pt3() {}
    Pt3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    Pt3 operator+(const Pt3& kPt) const { return Pt3(x + kPt.x, y + kPt.y, z + kPt.z); }
    Pt3 operator-(const Pt3& kPt) const { return Pt3(x - kPt.x, y - kPt.y, z - kPt.z); }
    Pt3 operator-() const { return Pt3(-x, -y, -z); }
    Pt3 Cross(const Pt3& kPt) const
    {
        return Pt3(y * kPt.z - z * kPt.y, z * kPt.x - x * kPt.z, x * kPt.y - y * kPt.x);
    }
    Pt3 NiPoint3_UnitCross(const Pt3& kPt) const;
};

struct Mat3
{
    float m_pEntry[3][3];
    Mat3() {}
    void GetCol(unsigned int uiCol, Pt3& kCol) const
    {
        kCol.x = m_pEntry[0][uiCol];
        kCol.y = m_pEntry[1][uiCol];
        kCol.z = m_pEntry[2][uiCol];
    }
    void SetCol(unsigned int uiCol, const Pt3& kCol)
    {
        m_pEntry[0][uiCol] = kCol.x;
        m_pEntry[1][uiCol] = kCol.y;
        m_pEntry[2][uiCol] = kCol.z;
    }
    Pt3 operator*(const Pt3& kV) const
    {
        return Pt3(m_pEntry[0][0] * kV.x + m_pEntry[0][1] * kV.y + m_pEntry[0][2] * kV.z,
                   m_pEntry[1][0] * kV.x + m_pEntry[1][1] * kV.y + m_pEntry[1][2] * kV.z,
                   m_pEntry[2][0] * kV.x + m_pEntry[2][1] * kV.y + m_pEntry[2][2] * kV.z);
    }
    Mat3 FUN_0044af40() const;
    Mat3 FUN_00424020(const Mat3& kMat) const;
    bool FUN_00823590(float& fX, float& fY, float& fZ) const;
};

struct Xform
{
    Mat3 m_Rotate;
    Pt3 m_Translate;
    float m_fScale;
    Xform() {}
};

struct __declspec(align(16)) HkVec4
{
    float x, y, z, w;
    HkVec4() {}
    __forceinline HkVec4(const HkVec4& kV)
    {
        x = kV.x;
        y = kV.y;
        z = kV.z;
        w = kV.w;
    }
    __forceinline void operator=(const HkVec4& kV)
    {
        x = kV.x;
        y = kV.y;
        z = kV.z;
        w = kV.w;
    }
};

struct HkRot
{
    HkVec4 m_col0;
    HkVec4 m_col1;
    HkVec4 m_col2;
    HkRot() {}
    __forceinline HkRot(const HkRot& kR) : m_col0(kR.m_col0), m_col1(kR.m_col1), m_col2(kR.m_col2) {}
};

struct HkXform
{
    HkRot m_rotation;
    HkVec4 m_translation;
    HkXform() {}
    __forceinline HkXform(const HkXform& kT)
    {
        const HkVec4 kCol0 = kT.m_rotation.m_col0;
        const HkVec4 kCol1 = kT.m_rotation.m_col1;
        const HkVec4 kCol2 = kT.m_rotation.m_col2;
        const HkVec4 kCol3 = kT.m_translation;
        m_rotation.m_col0 = kCol0;
        m_rotation.m_col1 = kCol1;
        m_rotation.m_col2 = kCol2;
        m_translation = kCol3;
    }
};

struct HkBounds
{
    HkVec4 m_min;
    HkVec4 m_max;
};

struct Body
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    HkXform m_transform;
};

struct CollObj
{
    int unk00;
    int unk04;
    Body* m_pBody;
    void FUN_008febc0(HkBounds& kBounds);
};

struct Obstacle
{
    int unk00;
    int unk04;
    int unk08;
    CollObj* m_pCollision;
    Pt3 m_kPosition;
    Mat3 m_kOrientation;
    Pt3 m_kLocalMin;
    Pt3 m_kLocalMax;
    Pt3 m_kWorldMin;
    Pt3 m_kWorldMax;
    unsigned int m_uiTime;
};

struct Timer
{
    unsigned int m_uiTime;
    unsigned int GetTime() const { return m_uiTime; }
};

void __cdecl FUN_0056ac90(Xform& kOut, const HkXform& kIn);

extern const Pt3 DAT_00f725b0;
extern Timer DAT_01090bb0;

inline float Abs(float fValue) { return (float)fabs(fValue); }
inline float Fmod(float fA, float fB) { return (float)fmod(fA, fB); }
inline float Min(float fA, float fB) { return fA < fB ? fA : fB; }
inline float Max(float fA, float fB) { return fA > fB ? fA : fB; }

inline void ToPt3(Pt3& kOut, const HkVec4& kIn)
{
    kOut.x = kIn.x * 6.999040126800537;
    kOut.y = kIn.y * 6.999040126800537;
    kOut.z = kIn.z * 6.999040126800537;
}

}  // namespace N5e3250

using namespace N5e3250;

// pdb: NavMeshObstacleManager::UpdateObstacleData | NavMeshObstacleManager.obj | fnv360_0822_retail, caller, medium
// pdb params: apObstacle
bool __cdecl FUN_005e3250(Obstacle* pObstacle)
{
    CollObj* pCollision = pObstacle->m_pCollision;
    if (!pCollision)
        return false;
    Body* pBody = pCollision->m_pBody;
    if (!pBody)
        return false;

    Xform kTransform;
    // Fake match: bare block. It ends the Havok transform's lifetime so its stack slot is shared with the
    // transpose temporary and the world corner array, as in the original frame.
    {
        HkXform kHkTransform(pBody->m_transform);
        kTransform.m_fScale = 1.0f;
        FUN_0056ac90(kTransform, kHkTransform);
        ToPt3(kTransform.m_Translate, kHkTransform.m_translation);
    }

    HkBounds kBounds;
    pCollision->FUN_008febc0(kBounds);

    float fX, fY, fZ;
    kTransform.m_Rotate.FUN_00823590(fX, fY, fZ);

    pObstacle->m_kPosition = kTransform.m_Translate;

    Pt3 kMin, kMax;
    ToPt3(kMin, kBounds.m_min);
    ToPt3(kMax, kBounds.m_max);

    // Fake match: bare block. The column array must die here so the two matrices below reuse its slot, and the
    // up/forward vectors must die so the world corner temporaries reuse theirs.
    {
    Pt3 kCols[3];
    for (unsigned int i = 0; i < 3; i++)
        kTransform.m_Rotate.GetCol(i, kCols[i]);

    Pt3 kUp, kRight, kForward;
    if (Abs(kCols[0].z) > Abs(kCols[1].z))
    {
        if (Abs(kCols[0].z) > Abs(kCols[2].z))
        {
            kUp = kCols[0];
            kForward = kCols[1];
            kRight = kCols[2];
        }
        else
        {
            kUp = kCols[2];
            kForward = kCols[0];
            kRight = kCols[1];
        }
    }
    else
    {
        if (Abs(kCols[1].z) > Abs(kCols[2].z))
        {
            kUp = kCols[1];
            kForward = kCols[2];
            kRight = kCols[0];
        }
        else
        {
            kUp = kCols[2];
            kForward = kCols[0];
            kRight = kCols[1];
        }
    }
    if (kUp.z < 0.0f)
    {
        kUp = -kUp;
        kForward = -kForward;
    }
    kUp = DAT_00f725b0;
    kRight = kUp.NiPoint3_UnitCross(kForward);
    pObstacle->m_kOrientation.SetCol(0, -kRight.Cross(kUp));
    pObstacle->m_kOrientation.SetCol(1, kRight);
    pObstacle->m_kOrientation.SetCol(2, kUp);
    }

    Pt3 kLocal[8];
    // Fake match: bare block, so the relative rotation shares the column array's slot with the inverse below.
    {
    Mat3 kRelRot = pObstacle->m_kOrientation.FUN_0044af40().FUN_00424020(kTransform.m_Rotate);

    kLocal[0] = kRelRot * Pt3(kMin.x, kMin.y, kMin.z);
    kLocal[1] = kRelRot * Pt3(kMax.x, kMin.y, kMin.z);
    kLocal[2] = kRelRot * Pt3(kMin.x, kMax.y, kMin.z);
    kLocal[3] = kRelRot * Pt3(kMax.x, kMax.y, kMin.z);
    kLocal[4] = kRelRot * Pt3(kMin.x, kMin.y, kMax.z);
    kLocal[5] = kRelRot * Pt3(kMax.x, kMin.y, kMax.z);
    kLocal[6] = kRelRot * Pt3(kMin.x, kMax.y, kMax.z);
    kLocal[7] = kRelRot * Pt3(kMax.x, kMax.y, kMax.z);
    }

    // Fake match: bare block, so the world corners and the inverse orientation start their lifetimes here.
    {
    Pt3 kWorld[8];
    for (unsigned int j = 0; j < 8; j++)
        kWorld[j] = pObstacle->m_kOrientation * kLocal[j] + pObstacle->m_kPosition;

    Mat3 kInverse = pObstacle->m_kOrientation.FUN_0044af40();
    for (unsigned int k = 0; k < 8; k++)
    {
        if (Abs(Fmod(kWorld[k].x, 4096.0f)) < 15.0)
        {
            kWorld[k].x += 30.0;
            kLocal[k] = kInverse * (kWorld[k] - pObstacle->m_kPosition);
        }
        if (Abs(Fmod(kWorld[k].y, 4096.0f)) < 15.0)
        {
            kWorld[k].y += 30.0;
            kLocal[k] = kInverse * (kWorld[k] - pObstacle->m_kPosition);
        }
    }

    pObstacle->m_kLocalMin = Pt3(3.402823466e+38f, 3.402823466e+38f, 3.402823466e+38f);
    pObstacle->m_kLocalMax = Pt3(-3.402823466e+38f, -3.402823466e+38f, -3.402823466e+38f);
    for (unsigned int l = 0; l < 8; l++)
    {
        pObstacle->m_kLocalMin.x = Min(pObstacle->m_kLocalMin.x, kLocal[l].x);
        pObstacle->m_kLocalMin.y = Min(pObstacle->m_kLocalMin.y, kLocal[l].y);
        pObstacle->m_kLocalMin.z = Min(pObstacle->m_kLocalMin.z, kLocal[l].z);
        pObstacle->m_kLocalMax.x = Max(pObstacle->m_kLocalMax.x, kLocal[l].x);
        pObstacle->m_kLocalMax.y = Max(pObstacle->m_kLocalMax.y, kLocal[l].y);
        pObstacle->m_kLocalMax.z = Max(pObstacle->m_kLocalMax.z, kLocal[l].z);
    }

    pObstacle->m_kWorldMin = Pt3(3.402823466e+38f, 3.402823466e+38f, 3.402823466e+38f);
    pObstacle->m_kWorldMax = Pt3(-3.402823466e+38f, -3.402823466e+38f, -3.402823466e+38f);
    for (unsigned int n = 0; n < 8; n++)
    {
        pObstacle->m_kWorldMin.x = Min(pObstacle->m_kWorldMin.x, kWorld[n].x);
        pObstacle->m_kWorldMin.y = Min(pObstacle->m_kWorldMin.y, kWorld[n].y);
        pObstacle->m_kWorldMin.z = Min(pObstacle->m_kWorldMin.z, kWorld[n].z);
        pObstacle->m_kWorldMax.x = Max(pObstacle->m_kWorldMax.x, kWorld[n].x);
        pObstacle->m_kWorldMax.y = Max(pObstacle->m_kWorldMax.y, kWorld[n].y);
        pObstacle->m_kWorldMax.z = Max(pObstacle->m_kWorldMax.z, kWorld[n].z);
    }

    }
    pObstacle->m_uiTime = DAT_01090bb0.GetTime();
    return true;
}
}   // namespace f3m_005e3250

// @f3 0x005ff620 (community match, verified in this file)
namespace f3m_005ff620 {
extern long (__stdcall* const DAT_00d9b068)(long volatile* addend);
extern long (__stdcall* const DAT_00d9b064)(long volatile* addend);

struct Heap5ff620
{
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap5ff620 DAT_01090a78;

struct RefCounted5ff620
{
    virtual void v00();
    virtual void DeleteThis();
    long m_refCount;
    void IncRefCount() { DAT_00d9b068(&m_refCount); }
    void DecRefCount()
    {
        if (!DAT_00d9b064(&m_refCount))
            DeleteThis();
    }
};

struct ObjectHead5ff620
{
    virtual void h00();
    int unk04;
    int unk08;
    unsigned int m_key;
    int unk10;
    int unk14;
    int unk18;
    unsigned int GetKey() const { return m_key; }
    void* FUN_005b84c0();
    unsigned int FUN_005b84e0();
};

struct Object5ff620 : ObjectHead5ff620, RefCounted5ff620
{
};

struct ObjectPtr5ff620
{
    Object5ff620* m_object;
    ObjectPtr5ff620(const ObjectPtr5ff620& other) : m_object(other.m_object)
    {
        if (m_object)
            m_object->IncRefCount();
    }
    ~ObjectPtr5ff620()
    {
        m_object->DecRefCount();
    }
    Object5ff620* operator->() const { return m_object; }
};

struct List5ff620
{
    virtual ~List5ff620() {}
    void* data;
    unsigned int size;
    unsigned int cap;
    List5ff620() : data(0), size(0), cap(0) {}
};

struct Elem5ff620
{
    char f0;
    List5ff620 list;
    void* val;
    unsigned int idx;
    Elem5ff620(void* v, unsigned int i)
    {
        f0 = 0;
        val = v;
        idx = i;
    }
    static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct ElemArray5ff620
{
    virtual void v0();
    virtual Elem5ff620** Allocate(unsigned int n);
    Elem5ff620** data;
    unsigned int size;
    unsigned int cap;
    ElemArray5ff620() : data(0), size(0), cap(0) {}
    ~ElemArray5ff620();
    void FUN_00799ae0(unsigned int capacity, unsigned int count);
    void SetCap(unsigned int n)
    {
        if (n != cap) {
            if (n < size)
                size = n;
            FUN_00799ae0(n, size);
            cap = n;
        }
    }
    void Add(Elem5ff620* e)
    {
        if (size == cap) {
            if (!cap) {
                data = Allocate(4);
                cap = 4;
            } else {
                unsigned int c = cap > 0x400 ? cap + 0x400 : cap * 2;
                FUN_00799ae0(c, size);
                cap = c;
            }
        }
        size++;
        data[size - 1] = e;
    }
};

struct Entry5ff620
{
    ElemArray5ff620 items;
    void* cached;
    Entry5ff620(const ObjectPtr5ff620& object);
    void FUN_005ff1d0(const ObjectPtr5ff620& object);
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* p);
};

__declspec(noinline) void Entry5ff620::FUN_005ff1d0(const ObjectPtr5ff620& object)
{
    unsigned int n = object->FUN_005b84e0();
    if (cached && items.size == n)
        return;
    if (items.data)
        items.size = 0;
    items.SetCap(n);
    for (unsigned int i = 0; i < n; i++)
        items.Add(new Elem5ff620(object->FUN_005b84c0(), i));
    cached = object->FUN_005b84c0();
}

__declspec(noinline) Entry5ff620::Entry5ff620(const ObjectPtr5ff620& object) : cached(0)
{
    FUN_005ff1d0(object);
}

struct MapItem5ff620
{
    MapItem5ff620* m_pkNext;
    unsigned int m_key;
    Entry5ff620* m_val;
};

struct EntryMap5ff620
{
    virtual void v00();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2) const;
    unsigned int m_uiHashSize;
    MapItem5ff620** m_ppkHashTable;
    unsigned int m_uiCount;
    bool FUN_00bea7b0(unsigned int key, Entry5ff620*& val) const;
    void FUN_00880f70(unsigned int key, Entry5ff620* entry);
};

__declspec(noinline) bool EntryMap5ff620::FUN_00bea7b0(unsigned int key, Entry5ff620*& val) const
{
    unsigned int index = KeyToHashIndex(key);
    MapItem5ff620* item = m_ppkHashTable[index];
    while (item) {
        if (IsKeysEqual(key, item->m_key)) {
            val = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

struct Lock5ff620
{
    void FUN_0086cc50();
    void FUN_0086cde0();
};

struct ObjectArray5ff620
{
    int unk00;
    ObjectPtr5ff620* m_data;
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
    ObjectPtr5ff620& GetAt(unsigned int i) { return m_data[i]; }
};

struct Owner5ff620
{
    int unk00;
    int unk04;
    EntryMap5ff620 m_map;
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
    Lock5ff620 m_lock;
    bool FUN_005ff620(ObjectArray5ff620* objects);
};

// pdb: PathingLOSGridMap::Setup | PathingLOSGridMap.obj | fnv360_0822_retail, objrun, medium
// pdb params: aNavMeshes
bool Owner5ff620::FUN_005ff620(ObjectArray5ff620* objects)
{
    m_lock.FUN_0086cc50();
    for (unsigned int i = 0; i < objects->GetSize(); ++i) {
        ObjectPtr5ff620 holder(objects->GetAt(i));
        Entry5ff620* entry = 0;
        if (!m_map.FUN_00bea7b0(holder->GetKey(), entry)) {
            entry = new Entry5ff620(holder);
            m_map.FUN_00880f70(holder->GetKey(), entry);
        } else {
            entry->FUN_005ff1d0(holder);
        }
    }
    m_lock.FUN_0086cde0();
    return true;
}
}

// @f3 0x005e6430 (community match, verified in this file)
extern bool DAT_01074864;
namespace f3m_005e6430 {

namespace f3m_005e6430 {

struct Ref5e64 {
    int unk00, unk04, unk08; unsigned int unk0C;
    unsigned int GetID() const { return unk0C; }
};

struct RefList5e64 { Ref5e64* item; RefList5e64* next; void FUN_00421610(Ref5e64** item); };

struct IdList5e64
{
    unsigned int item;
    IdList5e64* next;
    bool IsInList(const unsigned int& id)
    {
        for (IdList5e64* p = this; p; p = p->next)
            if (p->item == id)
                return true;
        return false;
    }
    void FUN_0061c430(const unsigned int& id);
};

struct Target5e64
{
    void hkpEntity_removeEntityActivationListener(int value);
    void FUN_0090b960(int value);
};

struct Holder5e64
{
    int unk00; int unk04; Target5e64* unk08;
    Target5e64* Get() { return this ? unk08 : 0; }
    void Apply1(int value) { Target5e64* t = Get(); if (t) t->hkpEntity_removeEntityActivationListener(value); }
    void Apply2(int value) { Target5e64* t = Get(); if (t) t->FUN_0090b960(value); }
};

struct Elem5e64 { int unk00; int unk04; int unk08; Holder5e64* unk0C; Holder5e64* GetHolder() { return unk0C; } };

struct RefObj5e64
{
    virtual ~RefObj5e64();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

struct Array5e64
{
    int unk00;
    void* unk04;
    Elem5e64** data;
    unsigned int count;
    unsigned int GetSize() const { return count; }
    Elem5e64* GetAt(unsigned int i) { return data[i]; }
};

struct Set5e64 : RefObj5e64
{
    Array5e64 arr;
};

struct MapItem5e64
{
    MapItem5e64* m_pkNext;
    unsigned int m_key;
    Set5e64* m_val;
};

struct Map5e64
{
    virtual ~Map5e64();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    virtual bool IsKeysEqual(unsigned int first, unsigned int second) const;
    unsigned int m_uiHashSize;
    MapItem5e64** m_ppkHashTable;
    unsigned int m_uiItemCount;
    __declspec(noinline) bool FUN_005c8b00(unsigned int key, NiPointer<Set5e64>& value)
    {
        unsigned int index = KeyToHashIndex(key);
        MapItem5e64* item = m_ppkHashTable[index];
        while (item)
        {
            if (IsKeysEqual(key, item->m_key))
            {
                value = item->m_val;
                return true;
            }
            item = item->m_pkNext;
        }
        return false;
    }
};

inline void FreeApply1(Holder5e64* holder, int value) { if (holder && holder->unk08) holder->unk08->hkpEntity_removeEntityActivationListener(value); }
inline void FreeApply2(Holder5e64* holder, int value) { if (holder && holder->unk08) holder->unk08->FUN_0090b960(value); }

struct Owner5e64
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    Map5e64 unk1C;
    RefList5e64 unk2C;
    IdList5e64 unk34;
    int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8;
    int unkBC;
    int unkC0;
    void Process(Holder5e64* holder) { holder->Apply1(unkBC); holder->Apply2(unkC0); }
    void FUN_005e6430(Ref5e64* input);
};

// pdb: NavMeshObstacleManager::RemoveObstacleForReference | NavMeshObstacleManager.obj | fnv360_0822_debug, caller, medium
// pdb params: apRef
void Owner5e64::FUN_005e6430(Ref5e64* input)
{
    if (!DAT_01074864)
        return;
    unk2C.FUN_00421610(&input);
    if (!unk34.IsInList(input->GetID()))
    {
        NiPointer<Set5e64> set(0);
        unsigned int i;
        if (unk1C.FUN_005c8b00(input->GetID(), set))
        {
            for (i = 0; i < set->arr.GetSize(); i++)
                Process(set->arr.GetAt(i)->GetHolder());
            // Fake match: the id is stored into the parameter itself and the list add takes its address
            // there; a plain temporary gets its own stack slot.
            input = (Ref5e64*)input->unk0C;
            unk34.FUN_0061c430(*(unsigned int*)&input);
        }
    }
}

}
}   // namespace f3m_005e6430

// @f3 0x005f7ce0 (community match, verified in this file)
namespace n5f7ce0 {
extern int DAT_00e020d8;
extern int DAT_00db5c04;
extern int DAT_00dffe50;
extern int DAT_00e00d7c;

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator+(const NiPoint3& pt) const { return NiPoint3(x + pt.x, y + pt.y, z + pt.z); }
    NiPoint3 operator-(const NiPoint3& pt) const { return NiPoint3(x - pt.x, y - pt.y, z - pt.z); }
};

struct BSRefObject {
    virtual ~BSRefObject();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};

struct NavMeshTriangle {
    unsigned short vertices[3];
    unsigned short edges[3];
    unsigned int flags;
    bool HasEdge(int index) const { return edges[index] != 0xFFFF; }
};

struct NavMeshEdgeVertices {
    const NiPoint3* first;
    const NiPoint3* second;
};

struct NavMeshInfo;

struct TriangleIndices;

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BSRefObject ref;
    int unk24;
    void* vertexTable;
    NiPoint3* vertices;
    unsigned int vertexCount, vertexCapacity;
    void* triangleTable;
    NavMeshTriangle* triangles;
    unsigned int triangleCount, triangleCapacity;
    void IncRefCount() { ref.IncRefCount(); }
    void DecRefCount() { ref.DecRefCount(); }
    NavMeshTriangle* GetTriangle(unsigned short index) { return &triangles[index]; }
    const NavMeshInfo* FUN_005b84c0();
    void FUN_005bcc90(const NiPoint3& minimum, const NiPoint3& maximum, TriangleIndices& result);
    NavMeshEdgeVertices FUN_005b8900(unsigned short triangle, int edge);
};

__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<NavMesh>& result, NavMesh* source) {
    NiPointer<NavMesh> holder(source);
    result = holder;
}

struct NavMeshInfo {
    int unk00, unk04;
    unsigned int flags;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    NavMesh* navMesh;
    bool IsDisabled() const { return (flags >> 4) & 1; }
    bool GetNavMesh(NiPointer<NavMesh>& result) const {
        if (IsDisabled())
            return false;
        FUN_005b87d0(result, navMesh);
        return (NavMesh*)result != 0;
    }
};

struct PathingLocation {
    void* table;
    NiPoint3 location;
    NiPoint3 GetLocation() const { return location; }
};

struct TriangleReference {
    const NavMeshInfo* mesh;
    unsigned short triangle;
    TriangleReference() {}
    TriangleReference(const NavMeshInfo* apMesh, unsigned short ausTriangle) : mesh(apMesh), triangle(ausTriangle) {}
    TriangleReference& operator=(const TriangleReference& other) {
        mesh = other.mesh;
        triangle = other.triangle;
        return *this;
    }
};

template <class T, int* TABLE> struct SimpleArray {
    void** table;
    T* data;
    unsigned int size;
    unsigned int capacity;

    T* Allocate(unsigned int count) { return ((T* (__thiscall*)(SimpleArray*, unsigned int))table[1])(this, count); }
    void Deallocate(T* buffer) { ((void (__thiscall*)(SimpleArray*, T*))table[2])(this, buffer); }
    T* Reallocate(T* buffer, unsigned int count) { return ((T* (__thiscall*)(SimpleArray*, T*, unsigned int))table[3])(this, buffer, count); }

    SimpleArray() {
        table = (void**)TABLE;
        data = 0;
        size = 0;
        capacity = 0;
    }
    ~SimpleArray() {
        table = (void**)TABLE;
        Clear();
    }
    void Clear() {
        if (data) {
            Deallocate(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    unsigned int GetSize() const { return size; }
    T& GetAt(unsigned int index) { return data[index]; }
    void SetAllocSize(unsigned int count) {
        if (data)
            data = Reallocate(data, count);
        else
            data = Allocate(count);
    }
    __forceinline unsigned int AddUninitialized() {
        if (size == capacity) {
            if (!capacity) {
                data = Allocate(4);
                capacity = 4;
            } else {
                unsigned int newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                SetAllocSize(newCapacity);
                capacity = newCapacity;
            }
        }
        ++size;
        return size - 1;
    }
    unsigned int Append(const T& item) {
        unsigned int index = AddUninitialized();
        data[index] = item;
        return index;
    }
};

struct NearbyMeshes {
    void** table;
    NiPointer<NavMesh>* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_00415f50(NiPointer<NavMesh>* items, unsigned int count);
    void Deallocate(NiPointer<NavMesh>* buffer) { ((void (__thiscall*)(NearbyMeshes*, NiPointer<NavMesh>*))table[2])(this, buffer); }
    NearbyMeshes() {
        table = (void**)&DAT_00db5c04;
        data = 0;
        size = 0;
        capacity = 0;
    }
    ~NearbyMeshes() {
        table = (void**)&DAT_00db5c04;
        if (data) {
            FUN_00415f50(data, size);
            Deallocate(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    unsigned int GetSize() const { return size; }
    NiPointer<NavMesh>& GetAt(unsigned int index) { return data[index]; }
};

struct TriangleReferences : SimpleArray<TriangleReference, &DAT_00e020d8> {};
struct TriangleIndices : SimpleArray<unsigned short, &DAT_00dffe50> {};
struct TriangleScratch : SimpleArray<void*, &DAT_00e00d7c> {};

void __cdecl FUN_005f5eb0(PathingLocation* location, float radius, NearbyMeshes* result, int existingOnly);
bool __cdecl FUN_005de000(const NiPoint3* first, const NiPoint3* second, const NiPoint3& point, float radius);
}

// pdb: Pathing::CheckSphere | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aSphereCenter, afRadius
bool __cdecl FUN_005f7ce0(n5f7ce0::PathingLocation* location, float radius)
{
    using namespace n5f7ce0;
    TriangleReferences scratch;
    NearbyMeshes meshes;
    FUN_005f5eb0(location, radius, &meshes, 1);
    for (unsigned int i = 0; i < meshes.GetSize(); ++i)
    {
        TriangleIndices indices;
        ((NavMesh*)meshes.GetAt(i))
            ->FUN_005bcc90(location->GetLocation() - n5f7ce0::NiPoint3(radius, radius, 0.0f),
                           location->GetLocation() + n5f7ce0::NiPoint3(radius, radius, 0.0f), indices);
        for (unsigned int j = 0; j < indices.GetSize(); ++j)
        {
            scratch.Append(TriangleReference(((NavMesh*)meshes.GetAt(i))->FUN_005b84c0(), indices.GetAt(j)));
        }
    }
    TriangleScratch triangles;
    for (unsigned int k = 0; k < scratch.GetSize(); ++k)
    {
        NiPointer<NavMesh> mesh;
        if (scratch.GetAt(k).mesh->GetNavMesh(mesh))
        {
            for (int edge = 0; edge < 3; ++edge)
            {
                if (!((NavMesh*)mesh)->GetTriangle(scratch.GetAt(k).triangle)->HasEdge(edge))
                {
                    NavMeshEdgeVertices vertices = ((NavMesh*)mesh)->FUN_005b8900(scratch.GetAt(k).triangle, edge);
                    if (FUN_005de000(vertices.first, vertices.second, location->GetLocation(), radius))
                        return false;
                }
            }
        }
    }
    return true;
}

// @f3 0x005f1f30 (community match, verified in this file)
namespace f3m_005f1f30 {
namespace n5f1f30 {
struct RefCounter {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (InterlockedDecrement(&refs) == 0)
            ((void (__thiscall*)(RefCounter*))vtable[1])(this);
    }
};
struct Mesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounter ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
};
struct Point { float x, y, z; };
struct Triangle {
    Mesh* mesh;
    unsigned short index;
    Point center;
};
struct Location {
    Point position;
    void* info;
    void* infos;
    void* cell;
    void* world;
    unsigned int key;
    unsigned short triangle;
    unsigned char state;
    unsigned char pad27;
    Location(const Location& other);
    virtual ~Location() {}
    bool FUN_005fda30(int flag);
    bool FUN_005fc8f0(NiPointer<Mesh>& mesh, unsigned short& triangle);
    void FUN_005fcba0(const Point* point);
    Point GetPosition() const { return position; }
};
struct Search {
    int unk0000;
    int unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C, unk0040;
    int unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C, unk0080;
    int unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC, unk00C0;
    int unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC, unk0100;
    int unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C, unk0140;
    int unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C, unk0180;
    int unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC, unk01C0;
    int unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC, unk0200;
    int unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C, unk0240;
    int unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C, unk0280;
    int unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC, unk02C0;
    int unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC, unk0300;
    int unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C, unk0340;
    int unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C, unk0380;
    int unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC, unk03C0;
    int unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC, unk0400;
    int unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C, unk0440;
    int unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C, unk0480;
    int unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC, unk04C0;
    int unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC, unk0500;
    int unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C, unk0540;
    int unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C, unk0580;
    int unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC, unk05C0;
    int unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC, unk0600;
    int unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C, unk0640;
    int unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C, unk0680;
    int unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC, unk06C0;
    int unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC, unk0700;
    int unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C, unk0740;
    int unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C, unk0780;
    int unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC, unk07C0;
    int unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC, unk0800;
    int unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C, unk0840;
    int unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C, unk0880;
    int unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC, unk08C0;
    int unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC, unk0900;
    int unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C, unk0940;
    int unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C, unk0980;
    int unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC, unk09C0;
    int unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC, unk0A00;
    int unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C, unk0A40;
    int unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C, unk0A80;
    int unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC, unk0AC0;
    int unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC, unk0B00;
    int unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C, unk0B40;
    int unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C, unk0B80;
    int unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC, unk0BC0;
    int unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC, unk0C00;
    int unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C, unk0C40;
    int unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C, unk0C80;
    int unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC, unk0CC0;
    int unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC, unk0D00;
    int unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C, unk0D40;
    int unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C, unk0D80;
    int unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC, unk0DC0;
    int unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC, unk0E00;
    int unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C, unk0E40;
    int unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C, unk0E80;
    int unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC, unk0EC0;
    int unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC, unk0F00;
    int unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C, unk0F40;
    int unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C, unk0F80;
    int unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC, unk0FC0;
    int unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC, unk1000;
    int unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C, unk1040;
    int unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C, unk1080;
    int unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC, unk10C0;
    int unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC, unk1100;
    int unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C, unk1140;
    int unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C, unk1180;
    int unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC, unk11C0;
    int unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC, unk1200;
    int unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C, unk1240;
    int unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C, unk1280;
    int unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC, unk12C0;
    int unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC, unk1300;
    int unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C, unk1340;
    int unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C, unk1380;
    int unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC, unk13C0;
    int unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC, unk1400;
    int unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C, unk1440;
    int unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C, unk1480;
    int unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC, unk14C0;
    int unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC, unk1500;
    int unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C, unk1540;
    int unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C, unk1580;
    int unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC, unk15C0;
    int unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC, unk1600;
    int unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C, unk1640;
    int unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C, unk1680;
    int unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC, unk16C0;
    int unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC, unk1700;
    int unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C, unk1740;
    int unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C, unk1780;
    int unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC, unk17C0;
    int unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC, unk1800;
    int unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C, unk1840;
    int unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C, unk1880;
    int unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC, unk18C0;
    int unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC, unk1900;
    int unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C, unk1940;
    int unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C, unk1980;
    int unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC, unk19C0;
    int unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC, unk1A00;
    int unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C, unk1A40;
    int unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C, unk1A80;
    int unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC, unk1AC0;
    int unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC, unk1B00;
    int unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C, unk1B40;
    int unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C, unk1B80;
    int unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC, unk1BC0;
    int unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC, unk1C00;
    int unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C, unk1C40;
    int unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C, unk1C60, unk1C64, unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C, unk1C80;
    int unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94, unk1C98, unk1C9C, unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC, unk1CC0;
    int unk1CC4, unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC, unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC, unk1D00;
    int unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C, unk1D20, unk1D24, unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C, unk1D40;
    int unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54, unk1D58, unk1D5C, unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C, unk1D80;
    int unk1D84, unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C, unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC, unk1DC0;
    int unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC, unk1DE0, unk1DE4, unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC, unk1E00;
    int unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14, unk1E18, unk1E1C, unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C, unk1E40;
    int unk1E44, unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C, unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C, unk1E80;
    int unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C, unk1EA0, unk1EA4, unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC, unk1EC0;
    int unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4, unk1ED8, unk1EDC, unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC, unk1F00;
    int unk1F04, unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C, unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C, unk1F40;
    int unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C, unk1F60, unk1F64, unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C, unk1F80;
    int unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94, unk1F98, unk1F9C, unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC, unk1FC0;
    int unk1FC4, unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC, unk1FE0, unk1FE4, unk1FE8, unk1FEC, unk1FF0, unk1FF4, unk1FF8, unk1FFC, unk2000;
    int unk2004, unk2008, unk200C, unk2010, unk2014, unk2018, unk201C, unk2020, unk2024, unk2028, unk202C, unk2030, unk2034, unk2038, unk203C, unk2040;
    int unk2044, unk2048, unk204C, unk2050, unk2054, unk2058, unk205C, unk2060, unk2064, unk2068, unk206C, unk2070, unk2074, unk2078, unk207C, unk2080;
    int unk2084, unk2088, unk208C, unk2090, unk2094, unk2098, unk209C, unk20A0, unk20A4, unk20A8;
    Search();
    ~Search();
    void FUN_005d0a80(Point& result, const Point& from, const Triangle& fromTriangle, const Point& to, const Triangle& toTriangle, float cost);
};

}
using namespace n5f1f30;
// pdb: Pathing::FindClosestReachableLocation | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aStartLocation, aGoalLocation, afMaxPathingDistance
Location __cdecl FUN_005f1f30(Location& start, Location& end, float cost)
{
    Triangle from;
    if (start.FUN_005fda30(0))
    {
        unsigned short triangleIndex;
        NiPointer<Mesh> meshHandle;
        if (start.FUN_005fc8f0(meshHandle, triangleIndex))
        {
            from.mesh = meshHandle;
            from.index = triangleIndex;
        }
        else
            return start;
    }
    else
        return start;
    Triangle to;
    to.mesh = 0;
    to.index = 0xffff;
    if (end.FUN_005fda30(0))
    {
        unsigned short triangleIndex;
        NiPointer<Mesh> meshHandle;
        if (end.FUN_005fc8f0(meshHandle, triangleIndex))
        {
            to.mesh = meshHandle;
            to.index = triangleIndex;
        }
    }
    Search search;
    Point position;
    search.FUN_005d0a80(position, start.GetPosition(), from, end.GetPosition(), to, cost);
    Location result(start);
    result.FUN_005fcba0(&position);
    return result;
}
}   // namespace f3m_005f1f30

// @f3 0x005fdde0 (community match, verified in this file)
extern void* DAT_00dd8fe4[];
namespace f3m_005fdde0 {
namespace f3m_005fdde0 {

struct NiPoint3 {
    float x, y, z;
};

struct BSRefObject {
    void** vtable;
    long refs;
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(BSRefObject*))vtable[1])(this);
    }
};

struct NavMesh {
    int unk00, unk04;
    unsigned int uiFlags;
    int unk0C, unk10, unk14, unk18;
    BSRefObject ref1C;
    void IncRefCount() { InterlockedIncrement(&ref1C.refs); }
    void DecRefCount() { ref1C.DecRefCount(); }
    bool IsDeleted() const { return (uiFlags >> 5) & 1; }
};

// Faithful port of the smart pointer assignment helper at 0x005b87d0 (a temporary reference on the source, then
// assignment). Its body is visible so the compiler knows the caller's smart pointer does not escape.
__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<NavMesh>* ap_spNavMesh, NavMesh* ap_NavMesh) {
    NiPointer<NavMesh> spNavMesh(ap_NavMesh);
    *ap_spNavMesh = spNavMesh;
}

struct Bounds {
    bool FUN_005c2870(const NiPoint3* ap_Location);
};

struct NavMeshInfo {
    int unk00;
    int unk04;
    unsigned int uiFlags;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    NavMesh* pNavMesh;
    Bounds* pBounds;
    bool GetDisabled() const { return (uiFlags >> 4) & 1; }
    // pdb: NiGeometryData::GetNormalsIterator | NiGeometryData.obj | fnv360_0822_retail, objrun, high (was: GetBounds)
    Bounds* NiGeometryData_GetNormalsIterator() const { return pBounds; }
    bool GetNavMesh(NiPointer<NavMesh>& ar_spNavMesh) const {
        if (GetDisabled())
            return false;
        FUN_005b87d0(&ar_spNavMesh, pNavMesh);
        return ar_spNavMesh.m_pObject != 0;
    }
};

struct NavMeshInfoArray;
extern void (__thiscall* DAT_00dd8fec)(NavMeshInfoArray*, void*);

struct NavMeshInfoArray {
    void** table;
    const NavMeshInfo** data;
    unsigned int size;
    unsigned int capacity;
    NavMeshInfoArray() : table(DAT_00dd8fe4), data(0), size(0), capacity(0) {}
    ~NavMeshInfoArray() {
        void* storage = data;
        table = DAT_00dd8fe4;
        if (storage) {
            DAT_00dd8fec(this, storage);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    void FUN_005e30b0(const NavMeshInfo** dest, const NavMeshInfo** source, unsigned int count);
    unsigned int FUN_005e5350();
    static void Destruct(const NavMeshInfo** item) {}
    void FUN_005fca80(unsigned int index, unsigned int count) {
        unsigned int tail = size - index - count;
        unsigned int moved = tail < count ? tail : count;
        // Fake match: the removed items are destructed before the tail is moved over them. For pointer items
        // the loop is empty and emits nothing, but it leaves the 16-byte aligned label at +e0 in the inlined copy.
        for (unsigned int k = 0; k < count; ++k)
            Destruct(&data[index + k]);
        FUN_005e30b0(&data[index], &data[size - moved], moved);
        size -= count;
    }
    unsigned int GetSize() const { return size; }
    const NavMeshInfo* GetAt(unsigned int index) const { return data[index]; }
    void Clear() {
        if (data)
            size = 0;
    }
    void Add(const NavMeshInfo* info) {
        data[FUN_005e5350()] = info;
    }
};

struct NavMeshInfoSource {
    void FUN_00602700(NavMeshInfoArray* ap_Array);
};

struct FUN_005fc5a0 {
    void* m_vtable;
    NiPoint3 Location;
    const NavMeshInfo* pNavMesh;
    NavMeshInfoSource* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;
    bool IsInvalid() const { return (uiFlags & 2u) > 0; }
    bool GetValid() const { return uiFlags & 1; }
    void SetValid(unsigned int ab_Valid) { uiFlags = (uiFlags & ~1) | ab_Valid; }
    bool FUN_005fd770();
    bool FUN_005fdde0();
};

// pdb: PathingLocation::ResolveNavMeshInfoOnly | PathingLocation.obj | fnv360_0822_retail, call_seq, medium
bool FUN_005fc5a0::FUN_005fdde0()
{
    if (IsInvalid())
        return false;
    if (!pNavMesh && !pNavMeshes)
        return false;
    else if (pNavMesh) {
        if (pNavMesh->GetDisabled())
            return false;
        else
            return true;
    } else {
        NavMeshInfoArray kInfos;
        pNavMeshes->FUN_00602700(&kInfos);
        for (unsigned int i = 0; i < kInfos.GetSize(); ++i) {
            const NavMeshInfo* pInfo = kInfos.GetAt(i);
            Bounds* pBounds = pInfo->NiGeometryData_GetNormalsIterator();
            if (pBounds) {
                if (pBounds->FUN_005c2870(&Location)) {
                    kInfos.Clear();
                    kInfos.Add(pInfo);
                    break;
                } else {
                    kInfos.FUN_005fca80(i, 1);
                    --i;
                }
            } else {
                NiPointer<NavMesh> spNavMesh;
                if (pInfo->GetNavMesh(spNavMesh) && spNavMesh->IsDeleted()) {
                    kInfos.FUN_005fca80(i, 1);
                    --i;
                }
            }
        }
        if (kInfos.GetSize() == 1) {
            pNavMesh = kInfos.GetAt(0);
            pNavMeshes = 0;
            SetValid(true);
            return true;
        } else {
            SetValid(FUN_005fd770());
            return GetValid();
        }
    }
}
}
}   // namespace f3m_005fdde0

// @f3 0x005f1970 (community match, verified in this file)
namespace f3m_005f1970 {
// Traces a 2D ray from start to end across navmesh triangles, applying an edge filter, and writes the
// resulting location to output. Port of the New Vegas function of the same shape.
namespace pf_005f1970 {
struct Point3
{
    float x, y, z;
    Point3() {}
    Point3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};
struct Point2
{
    float x, y;
    Point2() {}
    Point2(float fX, float fY)
    {
        x = fX;
        y = fY;
    }
};
struct RefObject
{
    virtual ~RefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct MeshInfo;
struct Triangle
{
    unsigned short vertices[3];
    unsigned short edges[3];
    unsigned int flags;
    bool IsEdgeFlagSet(int edge)
    {
        return (flags & (1 << edge)) != 0;
    }
    unsigned short GetEdge(int edge)
    {
        return edges[edge];
    }
};
struct EdgeInfo
{
    int type;
    int unk04;
    int unk08;
};
struct FormBase
{
    virtual ~FormBase();
    int unk04;
    int unk08;
    unsigned int formID;
    int unk10;
    int unk14;
};
struct ChildCell
{
    virtual void* GetCell();
};
struct Mesh;
typedef NiPointer<Mesh> MeshPtr;
struct Mesh : FormBase, ChildCell, RefObject
{
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    void* trianglesVtbl;
    Triangle* triangles;
    unsigned int triangleCount;
    unsigned int triangleCapacity;
    void* edgeInfosVtbl;
    EdgeInfo* edgeInfos;

    Triangle* GetTriangle(unsigned short i)
    {
        return &triangles[i];
    }
    EdgeInfo* GetEdgeInfoAt(unsigned short i)
    {
        return &edgeInfos[i];
    }
    EdgeInfo* GetEdgeInfo(unsigned short triangle, int edge)
    {
        if (GetTriangle(triangle)->IsEdgeFlagSet(edge) && GetTriangle(triangle)->GetEdge(edge) != 0xFFFF)
            return GetEdgeInfoAt(GetTriangle(triangle)->GetEdge(edge));
        else
            return 0;
    }
    int FUN_005bde60(unsigned short triangle, int edge, const Point2& start, const Point2& end, Point2& reached);
    bool FUN_005b91b0(unsigned short triangle, int edge, MeshPtr& next, unsigned short& nextTriangle, int& nextEdge);
    void FUN_005b8900(Point3** endpoints, unsigned short triangle, int edge);
    const MeshInfo* FUN_005b84c0();
    Point3 FUN_004d45e0(unsigned short triangle);
};
struct Location
{
    virtual void SaveGame(void*);
    virtual void LoadGame(void*);
    Point3 location;
    const MeshInfo* meshInfo;
    void* meshInfoArray;
    void* cell;
    void* worldspace;
    unsigned int pathingFlags;
    unsigned short triangle;
    unsigned char flags;
    unsigned char unk27;

    Location(const Point3& point, const MeshInfo* info, unsigned short tri);
    ~Location() {}
    Location& operator=(const Location& other);
    bool FUN_005fda30(int mode);
    bool FUN_005fc8f0(MeshPtr& mesh, unsigned short& tri);
    Point3 GetLocation() const
    {
        return location;
    }
    void FUN_005fc670(const MeshInfo* info);
    void FUN_005fc720(unsigned short tri);
    void FUN_005fcba0(const Point3& point);
};
struct EdgeRef
{
    Mesh* mesh;
    unsigned short triangle;
    int edge;
    EdgeRef(Mesh* m, unsigned short t, int e)
    {
        mesh = m;
        triangle = t;
        edge = e;
    }
    EdgeRef(const EdgeRef& o)
    {
        mesh = o.mesh;
        triangle = o.triangle;
        edge = o.edge;
    }
};
struct EdgeFilter
{
    virtual bool Test(EdgeRef from, EdgeRef to);
};
Point2 __cdecl FUN_005dd850(const Point2& a, const Point2& b, const Point2& c, const Point2& d);

// pdb: Pathing::CheckLineOfSight | Pathfind.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aStartLocation, aGoalLocation, apGoalNavMesh, ausGoalTriangle, apReturnIntersectionLocation, apFilter
bool __cdecl FUN_005f1970(Location& start, const Point3& end, Mesh* desiredMesh, unsigned short desiredTriangle,
                          Location* output, EdgeFilter* filter)
{
    if (output)
        *output = start;
    if (!start.FUN_005fda30(0))
    {
        if (!desiredMesh)
            return true;
        return false;
    }
    MeshPtr initialMesh;
    unsigned short initialTriangle;
    if (!start.FUN_005fc8f0(initialMesh, initialTriangle))
        return false;
    Point2 origin(start.GetLocation().x, start.GetLocation().y);
    Point2 destination(end.x, end.y);
    Point2 crossing;
    MeshPtr currentMesh(initialMesh);
    unsigned short triangle = initialTriangle;
    int edge = initialMesh->FUN_005bde60(triangle, -1, origin, destination, crossing);
    while (edge != -1)
    {
        MeshPtr nextMesh;
        unsigned short nextTriangle;
        int nextEdge;
        bool canCross = currentMesh->FUN_005b91b0(triangle, edge, nextMesh, nextTriangle, nextEdge);
        if (canCross && filter)
        {
            EdgeRef fromEdge(currentMesh, triangle, edge);
            EdgeRef toEdge(nextMesh, nextTriangle, nextEdge);
            canCross = filter->Test(fromEdge, toEdge);
        }
        if (canCross)
        {
            EdgeInfo* edgeInfo = currentMesh->GetEdgeInfo(triangle, edge);
            if (edgeInfo && edgeInfo->type == 1)
                canCross = false;
        }
        if (canCross)
        {
            if (nextMesh != currentMesh)
            {
                Point3* endpoints[2];
                nextMesh->FUN_005b8900(endpoints, nextTriangle, nextEdge);
                Point2 edgeStart(endpoints[0]->x, endpoints[0]->y);
                Point2 edgeEnd(endpoints[1]->x, endpoints[1]->y);
                crossing = FUN_005dd850(edgeStart, edgeEnd, crossing, destination);
            }
            triangle = nextTriangle;
            currentMesh = nextMesh;
            Point2 nextCrossing;
            edge = nextMesh->FUN_005bde60(nextTriangle, nextEdge, crossing, destination, nextCrossing);
            crossing = nextCrossing;
        }
        else
        {
            if (output)
            {
                output->FUN_005fc670(currentMesh->FUN_005b84c0());
                output->FUN_005fc720(triangle);
                output->FUN_005fcba0(Point3(crossing.x, crossing.y, currentMesh->FUN_004d45e0(triangle).z));
            }
            return false;
        }
    }
    if (desiredMesh && desiredTriangle != 0xffff)
    {
        if ((Mesh*)currentMesh == desiredMesh && triangle == desiredTriangle)
        {
            if (output)
                *output = Location(end, desiredMesh->FUN_005b84c0(), desiredTriangle);
            return true;
        }
        else
            return false;
    }
    else
    {
        if (output)
        {
            output->FUN_005fc670(currentMesh->FUN_005b84c0());
            output->FUN_005fc720(triangle);
            output->FUN_005fcba0(end);
        }
        return true;
    }
}
}  // namespace pf_005f1970
}   // namespace f3m_005f1970

// @f3 0x005fe3c0 (community match, verified in this file)
namespace f3m_005fe3c0 {
namespace w5fe3c0 {
struct Counter {
    virtual void v0();
    virtual void DeleteThis();
    long refs;
    void Release()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct TriList {
    int unk00;
    unsigned short* index;
    unsigned int count;
    unsigned int GetSize() const { return count; }
    const unsigned short* GetAt(unsigned int i) const { return &index[i]; }
};
struct Mesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    Counter counter;
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
    TriList* FUN_005b84f0(int key);
};
__declspec(noalias) void FUN_005b87d0(NiPointer<Mesh>* out, void* source);
struct Location {
    int key;
    int unk04;
    unsigned int flags;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44,
        unk48, unk4C, unk50;
    void* mesh;
    int GetKey() const { return key; }
    bool IsDisabled() const { return (flags >> 4) & 1; }
    bool Load(NiPointer<Mesh>& out)
    {
        if (IsDisabled())
            return false;
        FUN_005b87d0(&out, mesh);
        bool ok = out.m_pObject != 0;
        return ok;
    }
};
struct Grid {
    unsigned char* FUN_005ffe10(int key);
};
struct GridOwner {
    Grid* grid;
    Grid* GetGrid() const { return grid; }
};
struct ByteArray {
    virtual void v0();
    virtual void v4();
    virtual void Free(void* p);
    char* data;
    unsigned int count;
    unsigned int capacity;
    unsigned int GetSize() const { return count; }
    bool IsEmpty() const { return count == 0; }
    char* GetAt(unsigned int i) { return &data[i]; }
};
inline unsigned int Minimum(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}
struct Owner {
    unsigned char valid;
    ByteArray array;
    Location* source;
    int key;
    bool FUN_005fe3c0(GridOwner* owner);
};
// pdb: PathingLOSGridCell::SetLOSMapFromSeenTriangles | PathingLOSGridMap.obj | fnv360_0721_beta, call_gap, low
// pdb params: aspLOSMap
bool Owner::FUN_005fe3c0(GridOwner* owner)
{
    unsigned char* table = owner->GetGrid()->FUN_005ffe10(source->GetKey());
    if (!table)
        return false;
    NiPointer<Mesh> mesh;
    if (!source->Load(mesh))
        return false;
    TriList* list = mesh->FUN_005b84f0(key);
    if (!list)
        return false;
    if (!array.IsEmpty())
    {
        unsigned int n = Minimum(array.GetSize(), list->GetSize());
        for (unsigned int i = 0; i < n; i++)
            table[*list->GetAt(i)] = *array.GetAt(i);
    }
    else if (valid)
    {
        for (unsigned int j = 0; j < list->GetSize(); j++)
            table[*list->GetAt(j)] = 3;
    }
    else
    {
        for (unsigned int k = 0; k < list->GetSize(); k++)
            if (table[*list->GetAt(k)] == 0x7f)
                table[*list->GetAt(k)] = 0;
    }
    return true;
}
}
}   // namespace f3m_005fe3c0

// @f3 0x005eada0 (community match, verified in this file)
namespace f3m_005eada0 {
namespace nav5eada0 {
struct RefCounted {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(RefCounted*))vtable[1])(this);
    }
};
struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounted ref1C;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
};
struct PathingLocation {
    bool FUN_005fc8f0(NiPointer<NavMesh>& mesh, unsigned short& triangle);
};
struct MeshTriangle {
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    int unk08, unk0c, unk10;
};
struct TriangleRoute;
struct EdgeRoute;
struct NavMeshInfoArray;
struct PathingRequest;
// A* search over nav mesh triangles (0x20a4 bytes).
struct NavMeshSearch {
    void** vtable;
    unsigned int unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c, unk0020;
    unsigned int unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c, unk0040;
    unsigned int unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c, unk0060;
    unsigned int unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c, unk0080;
    unsigned int unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c, unk00a0;
    unsigned int unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc, unk00c0;
    unsigned int unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc, unk00e0;
    unsigned int unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc, unk0100;
    unsigned int unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c, unk0120;
    unsigned int unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c, unk0140;
    unsigned int unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c, unk0160;
    unsigned int unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c, unk0180;
    unsigned int unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c, unk01a0;
    unsigned int unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc, unk01c0;
    unsigned int unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc, unk01e0;
    unsigned int unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc, unk0200;
    unsigned int unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c, unk0220;
    unsigned int unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c, unk0240;
    unsigned int unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c, unk0260;
    unsigned int unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c, unk0280;
    unsigned int unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c, unk02a0;
    unsigned int unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc, unk02c0;
    unsigned int unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc, unk02e0;
    unsigned int unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc, unk0300;
    unsigned int unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c, unk0320;
    unsigned int unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c, unk0340;
    unsigned int unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c, unk0360;
    unsigned int unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c, unk0380;
    unsigned int unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c, unk03a0;
    unsigned int unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc, unk03c0;
    unsigned int unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc, unk03e0;
    unsigned int unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc, unk0400;
    unsigned int unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c, unk0420;
    unsigned int unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c, unk0440;
    unsigned int unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c, unk0460;
    unsigned int unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c, unk0480;
    unsigned int unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c, unk04a0;
    unsigned int unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc, unk04c0;
    unsigned int unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc, unk04e0;
    unsigned int unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc, unk0500;
    unsigned int unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c, unk0520;
    unsigned int unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c, unk0540;
    unsigned int unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c, unk0560;
    unsigned int unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c, unk0580;
    unsigned int unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c, unk05a0;
    unsigned int unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc, unk05c0;
    unsigned int unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc, unk05e0;
    unsigned int unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc, unk0600;
    unsigned int unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c, unk0620;
    unsigned int unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c, unk0640;
    unsigned int unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c, unk0660;
    unsigned int unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c, unk0680;
    unsigned int unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c, unk06a0;
    unsigned int unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc, unk06c0;
    unsigned int unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc, unk06e0;
    unsigned int unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc, unk0700;
    unsigned int unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c, unk0720;
    unsigned int unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c, unk0740;
    unsigned int unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c, unk0760;
    unsigned int unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c, unk0780;
    unsigned int unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c, unk07a0;
    unsigned int unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc, unk07c0;
    unsigned int unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc, unk07e0;
    unsigned int unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc, unk0800;
    unsigned int unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c, unk0820;
    unsigned int unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c, unk0840;
    unsigned int unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c, unk0860;
    unsigned int unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c, unk0880;
    unsigned int unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c, unk08a0;
    unsigned int unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc, unk08c0;
    unsigned int unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc, unk08e0;
    unsigned int unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc, unk0900;
    unsigned int unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c, unk0920;
    unsigned int unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c, unk0940;
    unsigned int unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c, unk0960;
    unsigned int unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c, unk0980;
    unsigned int unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c, unk09a0;
    unsigned int unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc, unk09c0;
    unsigned int unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc, unk09e0;
    unsigned int unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc, unk0a00;
    unsigned int unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c, unk0a20;
    unsigned int unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c, unk0a40;
    unsigned int unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c, unk0a60;
    unsigned int unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c, unk0a80;
    unsigned int unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c, unk0aa0;
    unsigned int unk0aa4, unk0aa8, unk0aac, unk0ab0, unk0ab4, unk0ab8, unk0abc, unk0ac0;
    unsigned int unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc, unk0ae0;
    unsigned int unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc, unk0b00;
    unsigned int unk0b04, unk0b08, unk0b0c, unk0b10, unk0b14, unk0b18, unk0b1c, unk0b20;
    unsigned int unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c, unk0b40;
    unsigned int unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c, unk0b60;
    unsigned int unk0b64, unk0b68, unk0b6c, unk0b70, unk0b74, unk0b78, unk0b7c, unk0b80;
    unsigned int unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c, unk0ba0;
    unsigned int unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc, unk0bc0;
    unsigned int unk0bc4, unk0bc8, unk0bcc, unk0bd0, unk0bd4, unk0bd8, unk0bdc, unk0be0;
    unsigned int unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc, unk0c00;
    unsigned int unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c, unk0c20;
    unsigned int unk0c24, unk0c28, unk0c2c, unk0c30, unk0c34, unk0c38, unk0c3c, unk0c40;
    unsigned int unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c, unk0c60;
    unsigned int unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c, unk0c80;
    unsigned int unk0c84, unk0c88, unk0c8c, unk0c90, unk0c94, unk0c98, unk0c9c, unk0ca0;
    unsigned int unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc, unk0cc0;
    unsigned int unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc, unk0ce0;
    unsigned int unk0ce4, unk0ce8, unk0cec, unk0cf0, unk0cf4, unk0cf8, unk0cfc, unk0d00;
    unsigned int unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c, unk0d20;
    unsigned int unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c, unk0d40;
    unsigned int unk0d44, unk0d48, unk0d4c, unk0d50, unk0d54, unk0d58, unk0d5c, unk0d60;
    unsigned int unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c, unk0d80;
    unsigned int unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c, unk0da0;
    unsigned int unk0da4, unk0da8, unk0dac, unk0db0, unk0db4, unk0db8, unk0dbc, unk0dc0;
    unsigned int unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc, unk0de0;
    unsigned int unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc, unk0e00;
    unsigned int unk0e04, unk0e08, unk0e0c, unk0e10, unk0e14, unk0e18, unk0e1c, unk0e20;
    unsigned int unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c, unk0e40;
    unsigned int unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c, unk0e60;
    unsigned int unk0e64, unk0e68, unk0e6c, unk0e70, unk0e74, unk0e78, unk0e7c, unk0e80;
    unsigned int unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c, unk0ea0;
    unsigned int unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc, unk0ec0;
    unsigned int unk0ec4, unk0ec8, unk0ecc, unk0ed0, unk0ed4, unk0ed8, unk0edc, unk0ee0;
    unsigned int unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc, unk0f00;
    unsigned int unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c, unk0f20;
    unsigned int unk0f24, unk0f28, unk0f2c, unk0f30, unk0f34, unk0f38, unk0f3c, unk0f40;
    unsigned int unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c, unk0f60;
    unsigned int unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c, unk0f80;
    unsigned int unk0f84, unk0f88, unk0f8c, unk0f90, unk0f94, unk0f98, unk0f9c, unk0fa0;
    unsigned int unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc, unk0fc0;
    unsigned int unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc, unk0fe0;
    unsigned int unk0fe4, unk0fe8, unk0fec, unk0ff0, unk0ff4, unk0ff8, unk0ffc, unk1000;
    unsigned int unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020;
    unsigned int unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c, unk1040;
    unsigned int unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c, unk1060;
    unsigned int unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c, unk1080;
    unsigned int unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0;
    unsigned int unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc, unk10c0;
    unsigned int unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0;
    unsigned int unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc, unk1100;
    unsigned int unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c, unk1120;
    unsigned int unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c, unk1140;
    unsigned int unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160;
    unsigned int unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c, unk1180;
    unsigned int unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0;
    unsigned int unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc, unk11c0;
    unsigned int unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc, unk11e0;
    unsigned int unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc, unk1200;
    unsigned int unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220;
    unsigned int unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c, unk1240;
    unsigned int unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260;
    unsigned int unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c, unk1280;
    unsigned int unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c, unk12a0;
    unsigned int unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc, unk12c0;
    unsigned int unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0;
    unsigned int unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc, unk1300;
    unsigned int unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320;
    unsigned int unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c, unk1340;
    unsigned int unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c, unk1360;
    unsigned int unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c, unk1380;
    unsigned int unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0;
    unsigned int unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc, unk13c0;
    unsigned int unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0;
    unsigned int unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc, unk1400;
    unsigned int unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c, unk1420;
    unsigned int unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c, unk1440;
    unsigned int unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460;
    unsigned int unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c, unk1480;
    unsigned int unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0;
    unsigned int unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc, unk14c0;
    unsigned int unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc, unk14e0;
    unsigned int unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc, unk1500;
    unsigned int unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520;
    unsigned int unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c, unk1540;
    unsigned int unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560;
    unsigned int unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c, unk1580;
    unsigned int unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c, unk15a0;
    unsigned int unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc, unk15c0;
    unsigned int unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0;
    unsigned int unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc, unk1600;
    unsigned int unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620;
    unsigned int unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c, unk1640;
    unsigned int unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c, unk1660;
    unsigned int unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c, unk1680;
    unsigned int unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0;
    unsigned int unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc, unk16c0;
    unsigned int unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0;
    unsigned int unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc, unk1700;
    unsigned int unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c, unk1720;
    unsigned int unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c, unk1740;
    unsigned int unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760;
    unsigned int unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c, unk1780;
    unsigned int unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0;
    unsigned int unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc, unk17c0;
    unsigned int unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc, unk17e0;
    unsigned int unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc, unk1800;
    unsigned int unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820;
    unsigned int unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c, unk1840;
    unsigned int unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860;
    unsigned int unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c, unk1880;
    unsigned int unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c, unk18a0;
    unsigned int unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc, unk18c0;
    unsigned int unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0;
    unsigned int unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc, unk1900;
    unsigned int unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920;
    unsigned int unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c, unk1940;
    unsigned int unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c, unk1960;
    unsigned int unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c, unk1980;
    unsigned int unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0;
    unsigned int unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc, unk19c0;
    unsigned int unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0;
    unsigned int unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc, unk1a00;
    unsigned int unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c, unk1a20;
    unsigned int unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c, unk1a40;
    unsigned int unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60;
    unsigned int unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c, unk1a80;
    unsigned int unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0;
    unsigned int unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc, unk1ac0;
    unsigned int unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc, unk1ae0;
    unsigned int unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc, unk1b00;
    unsigned int unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20;
    unsigned int unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c, unk1b40;
    unsigned int unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60;
    unsigned int unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c, unk1b80;
    unsigned int unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c, unk1ba0;
    unsigned int unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc, unk1bc0;
    unsigned int unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc, unk1be0;
    unsigned int unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc, unk1c00;
    unsigned int unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c, unk1c20;
    unsigned int unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34, unk1c38, unk1c3c, unk1c40;
    unsigned int unk1c44, unk1c48, unk1c4c, unk1c50, unk1c54, unk1c58, unk1c5c, unk1c60;
    unsigned int unk1c64, unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c, unk1c80;
    unsigned int unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c, unk1ca0;
    unsigned int unk1ca4, unk1ca8, unk1cac, unk1cb0, unk1cb4, unk1cb8, unk1cbc, unk1cc0;
    unsigned int unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc, unk1ce0;
    unsigned int unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4, unk1cf8, unk1cfc, unk1d00;
    unsigned int unk1d04, unk1d08, unk1d0c, unk1d10, unk1d14, unk1d18, unk1d1c, unk1d20;
    unsigned int unk1d24, unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c, unk1d40;
    unsigned int unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c, unk1d60;
    unsigned int unk1d64, unk1d68, unk1d6c, unk1d70, unk1d74, unk1d78, unk1d7c, unk1d80;
    unsigned int unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c, unk1da0;
    unsigned int unk1da4, unk1da8, unk1dac, unk1db0, unk1db4, unk1db8, unk1dbc, unk1dc0;
    unsigned int unk1dc4, unk1dc8, unk1dcc, unk1dd0, unk1dd4, unk1dd8, unk1ddc, unk1de0;
    unsigned int unk1de4, unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc, unk1e00;
    unsigned int unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c, unk1e20;
    unsigned int unk1e24, unk1e28, unk1e2c, unk1e30, unk1e34, unk1e38, unk1e3c, unk1e40;
    unsigned int unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c, unk1e60;
    unsigned int unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74, unk1e78, unk1e7c, unk1e80;
    unsigned int unk1e84, unk1e88, unk1e8c, unk1e90, unk1e94, unk1e98, unk1e9c, unk1ea0;
    unsigned int unk1ea4, unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc, unk1ec0;
    unsigned int unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc, unk1ee0;
    unsigned int unk1ee4, unk1ee8, unk1eec, unk1ef0, unk1ef4, unk1ef8, unk1efc, unk1f00;
    unsigned int unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c, unk1f20;
    unsigned int unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34, unk1f38, unk1f3c, unk1f40;
    unsigned int unk1f44, unk1f48, unk1f4c, unk1f50, unk1f54, unk1f58, unk1f5c, unk1f60;
    unsigned int unk1f64, unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c, unk1f80;
    unsigned int unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c, unk1fa0;
    unsigned int unk1fa4, unk1fa8, unk1fac, unk1fb0, unk1fb4, unk1fb8, unk1fbc, unk1fc0;
    unsigned int unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc, unk1fe0;
    unsigned int unk1fe4, unk1fe8, unk1fec, unk1ff0, unk1ff4, unk1ff8, unk1ffc, unk2000;
    unsigned int unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c, unk2020;
    unsigned int unk2024, unk2028, unk202c, unk2030, unk2034, unk2038, unk203c, unk2040;
    unsigned int unk2044, unk2048, unk204c, unk2050, unk2054, unk2058, unk205c, unk2060;
    unsigned int unk2064, unk2068, unk206c, unk2070, unk2074, unk2078, unk207c, unk2080;
    unsigned int unk2084, unk2088, unk208c, unk2090, unk2094, unk2098, unk209c, unk20a0;
    NavMeshSearch();
    ~NavMeshSearch();
    void SetTriangleEdges(EdgeRoute* route) { unk2084 = (unsigned int)route; }
    bool FUN_005cd600(PathingRequest* request, MeshTriangle& start, MeshTriangle& goal, TriangleRoute* nodes, EdgeRoute* links, NavMeshInfoArray* infos);
};
struct PathBuilder {
    PathingRequest* request;
    int unk04, unk08, unk0c, unk10;
    int infos14;
    bool FUN_005eada0(PathingLocation* start, PathingLocation* goal, EdgeRoute* edges, TriangleRoute* nodes, EdgeRoute* links, int unused6, int unused7);
};
// Finds the nav mesh triangles under the two locations and runs a triangle search between them.
bool PathBuilder::FUN_005eada0(PathingLocation* start, PathingLocation* goal, EdgeRoute* edges, TriangleRoute* nodes, EdgeRoute* links, int unused6, int unused7)
{
    NiPointer<NavMesh> startMesh;
    unsigned short startTriangle;
    if (!start->FUN_005fc8f0(startMesh, startTriangle))
        return false;
    MeshTriangle s;
    s.mesh = startMesh;
    s.triangle = startTriangle;
    NiPointer<NavMesh> goalMesh;
    unsigned short goalTriangle;
    if (!goal->FUN_005fc8f0(goalMesh, goalTriangle))
        return false;
    MeshTriangle g;
    g.mesh = goalMesh;
    g.triangle = goalTriangle;
    NavMeshSearch search;
    search.SetTriangleEdges(edges);
    bool ok = search.FUN_005cd600(request, s, g, nodes, links, (NavMeshInfoArray*)&infos14);
    if (!ok)
        return false;
    return true;
}
}
}   // namespace f3m_005eada0

// @f3 0x005e8a10 (community match, verified in this file)
// FUN_005e8a10: navmesh obstacle manager, pending-reference sweep.
// Walks the pending list; an item whose key already has a map entry is handed to the member at 0x005e7990,
// otherwise an item that has its virtual object is checked through a temporary obstacle record and handed to
// the member at 0x005e8650. Every handled item is collected in a local array and removed from the list at the end.
namespace f3m_005e8a10 {

struct RefObject {
    virtual void V00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};
typedef NiPointer<RefObject> RefPtr;

struct Item;
struct ItemArray;
struct ArrayTable {
    void* unk00;
    Item** (__thiscall* allocate)(ItemArray*, unsigned int);
};
extern ArrayTable DAT_00dd8fd0;
extern void (__thiscall* DAT_00dd8fd8)(ItemArray*, void*);

struct ItemArray {
    ArrayTable* table;
    Item** data;
    unsigned int count;
    unsigned int capacity;
    ItemArray() : table(&DAT_00dd8fd0), data(0), count(0), capacity(0) {}
    ~ItemArray() {
        table = &DAT_00dd8fd0;
        if (data) {
            DAT_00dd8fd8(this, data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
    void FUN_00799ae0(unsigned int newCapacity, unsigned int oldCount);
    unsigned int FUN_005e5350();
    void Add(Item* item) {
        if (count == capacity) {
            if (!capacity) {
                data = table->allocate(this, 4);
                capacity = 4;
            } else {
                unsigned int newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_00799ae0(newCapacity, count);
                capacity = newCapacity;
            }
        }
        ++count;
        data[count - 1] = item;
    }
};

struct Process {
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V0a(); virtual void V0b();
    virtual void V0c(); virtual void V0d(); virtual void V0e(); virtual void V0f();
    virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13();
    virtual void V14(); virtual void V15(); virtual void V16(); virtual void V17();
    virtual void V18(); virtual void V19(); virtual void V1a(); virtual void V1b();
    virtual void V1c(); virtual void V1d(); virtual void V1e(); virtual void V1f();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25();
    virtual void* IsActive();
};

struct Record {
    void* table;
    long refs;
    int unk08;
    Process* process;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    int unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
    Record();
    ~Record();
};

struct Item {
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V0a(); virtual void V0b();
    virtual void V0c(); virtual void V0d(); virtual void V0e(); virtual void V0f();
    virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13();
    virtual void V14(); virtual void V15(); virtual void V16(); virtual void V17();
    virtual void V18(); virtual void V19(); virtual void V1a(); virtual void V1b();
    virtual void V1c(); virtual void V1d(); virtual void V1e(); virtual void V1f();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V2a(); virtual void V2b();
    virtual void V2c(); virtual void V2d(); virtual void V2e(); virtual void V2f();
    virtual void V30(); virtual void V31(); virtual void V32(); virtual void V33();
    virtual void V34(); virtual void V35(); virtual void V36(); virtual void V37();
    virtual void V38(); virtual void V39(); virtual void V3a(); virtual void V3b();
    virtual void V3c(); virtual void V3d(); virtual void V3e(); virtual void V3f();
    virtual void V40(); virtual void V41(); virtual void V42(); virtual void V43();
    virtual void V44(); virtual void V45(); virtual void V46(); virtual void V47();
    virtual void V48(); virtual void V49(); virtual void V4a(); virtual void V4b();
    virtual void V4c(); virtual void V4d(); virtual void V4e(); virtual void V4f();
    virtual void V50(); virtual void V51(); virtual void V52(); virtual void V53();
    virtual void V54(); virtual void V55(); virtual void V56(); virtual void V57();
    virtual void V58(); virtual void V59(); virtual void V5a(); virtual void V5b();
    virtual void V5c(); virtual void V5d(); virtual void V5e(); virtual void V5f();
    virtual void V60(); virtual void V61(); virtual void V62(); virtual void V63();
    virtual void V64(); virtual void V65(); virtual void V66(); virtual void V67();
    virtual void V68(); virtual void V69(); virtual void V6a(); virtual void V6b();
    virtual void V6c(); virtual void V6d(); virtual void V6e(); virtual void V6f();
    virtual void V70(); virtual void V71(); virtual void V72(); virtual void V73();
    virtual void* GetProcess();
    int unk04, unk08;
    void* key;
    void* GetKey() const { return key; }
};

bool __cdecl FUN_005e5540(void* process, Record* record);

struct Node {
    Item* item;
    Node* next;
    bool IsEmpty() const { return next == 0 && item == 0; }
};
struct ItemList {
    Node head;
    Node* Head() { return &head; }
    void FUN_00421610(Item** item);
};
struct Map {
    __declspec(noalias) bool FUN_005c8b00(void* key, RefPtr& result);
};

struct Manager {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    Map map;
    int unk20, unk24, unk28;
    ItemList list;
    void FUN_005e7990(void* key, Item* item);
    void FUN_005e8650(Item* item);
    void FUN_005e8a10();
};

// pdb: NavMeshObstacleManager::ProcessNewReferences | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
void Manager::FUN_005e8a10()
{
    ItemArray kRemove;
    Node* node = list.Head();
    while (node) {
        if (node->IsEmpty())
            break;
        Item* item = node->item;
        node = node->next;
        RefPtr spEntry;
        if (map.FUN_005c8b00(item->GetKey(), spEntry)) {
            FUN_005e7990(item->GetKey(), item);
            kRemove.Add(item);
        } else if (item->GetProcess()) {
            Record kRecord;
            if (FUN_005e5540(item->GetProcess(), &kRecord) && kRecord.process->IsActive()) {
                FUN_005e8650(item);
                kRemove.data[kRemove.FUN_005e5350()] = item;
            }
        }
    }
    for (unsigned int i = 0; i < kRemove.count; ++i)
        list.FUN_00421610(&kRemove.data[i]);
}
}

// @f3 0x005e77d0 (community match, verified in this file)
namespace f3m_005e77d0 {
namespace f3w_5e77d0 {

struct Item;
struct Owner;

struct PtrArray {
    virtual void v00();
    virtual void* Allocate(unsigned int size);
    virtual void Free(void* p);
    void** data;
    unsigned int size;
    unsigned int capacity;
    void FUN_00799ae0(unsigned int newCapacity, unsigned int count);
    void*& GetAt(unsigned int i) { return data[i]; }
    unsigned int GetSize() const { return size; }
    void Clear() {
        if (data) {
            Free(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    void Add(void* const& item) {
        if (size == capacity) {
            if (!capacity) {
                data = (void**)Allocate(4);
                capacity = 4;
            } else {
                unsigned int newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_00799ae0(newCapacity, size);
                capacity = newCapacity;
            }
        }
        ++size;
        data[size - 1] = item;
    }
};

struct Obj {
    int u_00;
    int u_04;
    int u_08;
    int u_0c;
    int u_10;
    int u_14;
    int u_18;
    int u_1c;
    int u_20;
    int u_24;
    int u_28;
    int u_2c;
    int u_30;
    int u_34;
    int u_38;
    int u_3c;
    int u_40;
    int u_44;
    int u_48;
    int u_4c;
    int u_50;
    int u_54;
    int u_58;
    int u_5c;
    int u_60;
    int u_64;
    int u_68;
    int u_6c;
    int u_70;
    bool flag74;
    char b75, b76, b77;
    PtrArray arr;
};

struct Param {
    Obj* obj;
    Obj* operator->() const { return obj; }
    operator Obj*() const { return obj; }
};

struct Node {
    void* FUN_005b84c0();
};

// Smart pointer element of the local scrap array; the inline arrow is needed (a raw pointer element
// compiles the first clear with an in-place add instead of the address computation).
struct NodePtr {
    Node* ptr;
    Node* operator->() const { return ptr; }
    operator Node*() const { return ptr; }
};

struct Handler {
    void FUN_005ea490(Param& p, int type);
};

struct LocalArray {
    void* vtbl;
    NodePtr* data;
    unsigned int size;
    unsigned int capacity;
    void* allocator;
    unsigned int GetSize() const { return size; }
    NodePtr& GetAt(unsigned int i) { return data[i]; }
    void FUN_005e7610();
    void FUN_005e7680();
    LocalArray() { FUN_005e7610(); }
    ~LocalArray() { FUN_005e7680(); }
};

void __cdecl FUN_005e3250(Obj* obj);
void __cdecl FUN_005e45a0(Param& p);
bool __cdecl FUN_005e7120(Param& p, LocalArray& out);

struct Owner {
    int u_000;
    int u_004;
    int u_008;
    int u_00c;
    int u_010;
    int u_014;
    int u_018;
    int u_01c;
    int u_020;
    int u_024;
    int u_028;
    int u_02c;
    int u_030;
    int u_034;
    int u_038;
    int u_03c;
    int u_040;
    int u_044;
    int u_048;
    int u_04c;
    int u_050;
    int u_054;
    int u_058;
    int u_05c;
    int u_060;
    int u_064;
    int u_068;
    int u_06c;
    int u_070;
    int u_074;
    int u_078;
    int u_07c;
    int u_080;
    int u_084;
    int u_088;
    int u_08c;
    int u_090;
    int u_094;
    int u_098;
    int u_09c;
    int u_0a0;
    int u_0a4;
    int u_0a8;
    int u_0ac;
    int u_0b0;
    int u_0b4;
    int u_0b8;
    int u_0bc;
    int u_0c0;
    int u_0c4;
    int u_0c8;
    int u_0cc;
    int u_0d0;
    int u_0d4;
    int u_0d8;
    int u_0dc;
    int u_0e0;
    int u_0e4;
    int u_0e8;
    int u_0ec;
    int u_0f0;
    int u_0f4;
    int u_0f8;
    int u_0fc;
    int u_100;
    int u_104;
    int u_108;
    int u_10c;
    int u_110;
    int u_114;
    int u_118;
    int u_11c;
    int u_120;
    int u_124;
    int u_128;
    int u_12c;
    int u_130;
    int u_134;
    bool flag138;
    Handler* FUN_005e4ce0(void* key);
    void FUN_005e4b90(Param& p);
    void FUN_005e77d0(Param& p);
};

// pdb: NavMeshObstacleManager::UpdateObstacle | NavMeshObstacleManager.obj | fnv360_1110_retail, call_seq, medium
// pdb params: spObstacle
void Owner::FUN_005e77d0(Param& p) {
    if (p->flag74) {
        for (unsigned int i = 0; i < p->arr.GetSize(); i++)
            FUN_005e4ce0(p->arr.GetAt(i))->FUN_005ea490(p, 0x21);
        p->arr.Clear();
    }
    FUN_005e3250(p);
    FUN_005e45a0(p);
    if (flag138)
        FUN_005e4b90(p);
    if (p->flag74) {
        LocalArray list;
        if (FUN_005e7120(p, list)) {
            for (unsigned int j = 0; j < list.GetSize(); j++) {
                FUN_005e4ce0(list.GetAt(j)->FUN_005b84c0())->FUN_005ea490(p, 0x11);
                p->arr.Add(list.GetAt(j)->FUN_005b84c0());
            }
        }
    }
}

}
}   // namespace f3m_005e77d0

// @f3 0x005f4d90 (community match, verified in this file)
namespace b1261 {
struct Pt3 { float x, y, z; };

struct RefCounter {
    virtual void v00();
    virtual void DeleteThis();
    long refs;
    void Release() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
struct Resource {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounter counter;
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
};

struct Tri { unsigned short v[3]; unsigned short unk06; int unk08, unk0C; };
struct Geom {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    Pt3* verts;
    int unk30, unk34, unk38;
    Tri* tris;
    Tri* GetTri(unsigned short i) { return &tris[i]; }
    Pt3 GetVertex(unsigned short i) { return verts[i]; }
};

struct Heap { void* FUN_0086bcb0(); };
extern Heap DAT_01090a78;

class Simple { public:
    virtual ~Simple();
    virtual void* Allocate(unsigned);
    virtual void Free(void*);
    void* data; unsigned size, capacity;
    __forceinline Simple() : data(0), size(0), capacity(0) {}
};
}
struct NavMeshSearchNode { b1261::Geom* geom; unsigned int tri; b1261::Pt3 pos; };
struct NavMeshSearchLink { int unk00, unk04; };
template <class T, unsigned int G> class BSScrapArray : public b1261::Simple { public:
    void* allocator;
    virtual ~BSScrapArray();
    __forceinline BSScrapArray(unsigned cap, unsigned initial, void* alloc) : Simple() {
        if (!alloc) alloc = b1261::DAT_01090a78.FUN_0086bcb0();
        allocator = alloc;
        Init(initial, cap);
    }
    __forceinline void Init(unsigned initial, unsigned cap) {
        data = 0; size = 0; capacity = 0;
        if (initial > cap) cap = initial;
        if (cap > 0) { data = Allocate(cap); capacity = cap; }
        if (initial > 0) size = initial;
    }
    T& Last() { return ((T*)data)[size - 1]; }
};
namespace b1261 {
typedef NavMeshSearchNode Hit;
typedef NavMeshSearchLink Edge;

struct Key { Resource* res; unsigned short index; unsigned short unk06; int unk08, unk0C, unk10; };

struct Finder {
    bool FUN_005fcc10();
    bool FUN_005fc8f0(NiPointer<Resource>* out, int* index);
};
struct Spawn { int unk00, unk04, unk08; Finder finder; };

struct SearchBlock40 {
    int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, aa, ab, ac, ad, ae, af;
};
struct SearchBlock400 {
    SearchBlock40 b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, ba, bb, bc, bd, be, bf;
};
struct Search {
    Search();
    ~Search();
    bool FUN_005cdf00(Spawn* spawn, Key* key, BSScrapArray<Hit, 1024>* hits, BSScrapArray<Edge, 1024>* edges);
    SearchBlock400 s0, s1, s2, s3, s4, s5, s6, s7;
    SearchBlock40 t0, t1;
    int unk2080, unk2084, unk2088, unk208c, unk2090, unk2094, unk2098;
};

__declspec(noinline) const Pt3* FUN_005def10(Hit* hit, Pt3* a, Pt3* b, Pt3* c)
{
    if (hit->pos.x + hit->pos.y + hit->pos.z + a->x + a->y + a->z + b->x + b->y + b->z + c->x + c->y + c->z > 0.0f)
        return a;
    return c;
}
}
using namespace b1261;

// pdb: Pathing::FindClosePointViaNavMesh | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRequest, apRetPt
bool FUN_005f4d90(Spawn* spawn, Pt3* out)
{
    Finder* finder = &spawn->finder;
    if (!finder->FUN_005fcc10())
        return false;
    NiPointer<Resource> resource;
    int index = 0xffff;
    if (!finder->FUN_005fc8f0(&resource, &index))
        return false;
    Key key;
    key.res = resource;
    key.index = (unsigned short)index;
    Search search;
    BSScrapArray<Hit, 1024> hits(0x20, 0, 0);
    BSScrapArray<Edge, 1024> edges(0x20, 0, 0);
    if (!search.FUN_005cdf00(spawn, &key, &hits, &edges))
        return false;
    Hit& last = hits.Last();
    Geom* geom = last.geom;
    unsigned int t = last.tri;
    Hit hit;
    hit.pos = last.pos;
    Tri* tri = geom->GetTri((unsigned short)t);
    Pt3 v[3];
    v[0] = geom->GetVertex(tri->v[0]);
    v[1] = geom->GetVertex(tri->v[1]);
    v[2] = geom->GetVertex(tri->v[2]);
    *out = *FUN_005def10(&hit, &v[0], &v[1], &v[2]);
    return true;
}

// @f3 0x005f90b0 (community match, verified in this file)
extern float DAT_01074920;
namespace f3m_005f90b0 {
namespace f3m_005f90b0 {

extern void (__thiscall* DAT_00e020b8)(void*, void*);

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator+(const NiPoint3& pt) const { return NiPoint3(x + pt.x, y + pt.y, z + pt.z); }
    NiPoint3 operator-(const NiPoint3& pt) const { return NiPoint3(x - pt.x, y - pt.y, z - pt.z); }
    NiPoint3 operator*(float fScalar) const { return NiPoint3(fScalar * x, fScalar * y, fScalar * z); }
};

NiPoint3 __cdecl FUN_005dd040(const NiPoint3& pos, const NiPoint3& a, const NiPoint3& b);

struct BSRefObject {
    virtual ~BSRefObject();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};

struct NavTriangle {
    unsigned short vertex[3];
    unsigned short edge[3];
    int unk0C;
    unsigned short GetVertex(int i) const { return vertex[i]; }
    unsigned short GetEdge(int i) const { return edge[i]; }
};

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BSRefObject ref1C;
    int unk24;
    int unk28;
    NiPoint3* pVertices;          // +0x2c
    int unk30, unk34, unk38;
    NavTriangle* pTriangles;      // +0x3c
    unsigned int uiTriangleCount; // +0x40
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    unsigned int GetTriangleCount() const { return uiTriangleCount; }
    NavTriangle* GetTriangle(unsigned short i) const { return &pTriangles[i]; }
    NiPoint3* GetVertex(unsigned short i) const { return &pVertices[i]; }
    NiPoint3 FUN_004d45e0(unsigned short a_usTriangle) const;
};

struct CoverItem {
    NavMesh* pNavMesh;
    unsigned short usTriangle;
    int iEdge;
    NiPoint3 kPoint;
    float fDistSq;
    float fHeight;
    CoverItem() {}
    CoverItem& operator=(const CoverItem& o) {
        pNavMesh = o.pNavMesh;
        usTriangle = o.usTriangle;
        iEdge = o.iEdge;
        kPoint = o.kPoint;
        fDistSq = o.fDistSq;
        fHeight = o.fHeight;
        return *this;
    }
};

struct CoverEntry {
    NavMesh* pNavMesh;
    unsigned short usTriangle;
    int iEdge;
    NiPoint3 kPoint;
    CoverEntry() {}
    CoverEntry(const CoverItem& item);
    CoverEntry& operator=(const CoverEntry& o) {
        pNavMesh = o.pNavMesh;
        usTriangle = o.usTriangle;
        iEdge = o.iEdge;
        kPoint = o.kPoint;
        return *this;
    }
};

inline unsigned int MinCount(unsigned int a, unsigned int b) { return a < b ? a : b; }

int __cdecl FUN_005f11b0(const void* first, const void* second);
void __cdecl FUN_00c011c0(void* base, unsigned int count, unsigned int elemSize,
                          int (__cdecl* compare)(const void*, const void*));

struct CoverItemArray {
    void** vtable;
    CoverItem* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    CoverItemArray() { vtable = DAT_00e020b0; InitialSetup(0, 0); }
    void InitialSetup(unsigned int capacity, unsigned int initialSize) {
        pData = 0;
        uiSize = 0;
        uiCapacity = 0;
        if (initialSize > capacity)
            capacity = initialSize;
        if (capacity > 0) {
            pData = Allocate(capacity);
            uiCapacity = capacity;
        }
        if (initialSize > 0) {
            InitializeItems(pData, initialSize);
            uiSize = initialSize;
        }
    }

    ~CoverItemArray() {
        vtable = DAT_00e020b0;
        Clear(true);
    }
    void ReleaseElements(CoverItem* items, unsigned int count) {
        for (unsigned int i = 0; i < count; i = i + 1) {
            CoverItem* item = items + i;
            item->~CoverItem();
        }
    }
    void Clear(bool freeStorage) {
        if (pData) {
            ReleaseElements(pData, uiSize);
            if (freeStorage) {
                DAT_00e020b8(this, pData);
                pData = 0;
                uiCapacity = 0;
            }
            uiSize = 0;
        }
    }
    void FUN_00bf4bf0(unsigned int newCapacity, unsigned int count);
    unsigned int GetSize() const { return uiSize; }
    bool IsEmpty() const { return uiSize == 0; }
    CoverItem* GetAt(unsigned int i) const { return &pData[i]; }
    bool IsFull() const { return uiSize == uiCapacity; }
    unsigned int GetNextCapacity() const { return uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2; }
    CoverItem* Allocate(unsigned int count) { return ((CoverItem* (__thiscall*)(CoverItemArray*, unsigned int))vtable[1])(this, count); }
    void InitializeItems(CoverItem* items, unsigned int count) {
        for (unsigned int i = 0; i < count; i = i + 1) {
            // Fake match: the element pointer is named and the in-place construction of the (empty) element
            // constructor is left out. This dead local only sets the compiler's count of expression temporaries,
            // which decides base and index of the element address in the copy loop at the end of the function.
            CoverItem* dst = items + i;
        }
    }
    unsigned int ReserveIndex() {
        if (IsFull()) {
            if (uiCapacity == 0) {
                unsigned int initial = 4;
                pData = Allocate(initial);
                uiCapacity = initial;
            } else {
                unsigned int newCapacity = GetNextCapacity();
                FUN_00bf4bf0(newCapacity, uiSize);
                uiCapacity = newCapacity;
            }
        }
        uiSize = uiSize + 1;
        return uiSize - 1;
    }
    __forceinline unsigned int Add(const CoverItem& item) {
        unsigned int index = ReserveIndex();
        InitializeItems(pData + index, 1);
        pData[index] = item;
        return index;
    }
    void SetAt(unsigned int i, const CoverItem& item) { pData[i] = item; }
};

struct CoverEntryArray {
    void** vtable;
    CoverEntry* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    void FUN_005eb150(unsigned int newCapacity, unsigned int count);
    bool IsFull() const { return uiSize == uiCapacity; }
    unsigned int GetNextCapacity() const { return uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2; }
    CoverEntry* Allocate(unsigned int count) { return ((CoverEntry* (__thiscall*)(CoverEntryArray*, unsigned int))vtable[1])(this, count); }
    void InitializeItems(CoverEntry* items, unsigned int count) {
        for (unsigned int i = 0; i < count; i = i + 1) {
            new (items + i) CoverEntry;
        }
    }
    unsigned int ReserveIndex() {
        if (IsFull()) {
            if (uiCapacity == 0) {
                unsigned int initial = 4;
                pData = Allocate(initial);
                uiCapacity = initial;
            } else {
                unsigned int newCapacity = GetNextCapacity();
                FUN_005eb150(newCapacity, uiSize);
                uiCapacity = newCapacity;
            }
        }
        uiSize = uiSize + 1;
        return uiSize - 1;
    }
    __forceinline unsigned int Add(const CoverEntry& item) {
        unsigned int index = ReserveIndex();
        InitializeItems(pData + index, 1);
        pData[index] = item;
        return index;
    }
    void SetAt(unsigned int i, const CoverEntry& item) { pData[i] = item; }
};

struct NavMeshArray {
    void** vtable;
    NavMesh** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    NavMeshArray() { vtable = (void**)&DAT_00db5c04; InitialSetup(0, 0); }
    NavMesh** Allocate(unsigned int count) { return ((NavMesh** (__thiscall*)(NavMeshArray*, unsigned int))vtable[1])(this, count); }
    void InitializeItems(NavMesh** items, unsigned int count) {
        for (unsigned int i = 0; i < count; i = i + 1) {
            new (items + i) NavMesh*;
        }
    }
    void InitialSetup(unsigned int capacity, unsigned int initialSize) {
        pData = 0;
        uiSize = 0;
        uiCapacity = 0;
        if (initialSize > capacity)
            capacity = initialSize;
        if (capacity > 0) {
            pData = Allocate(capacity);
            uiCapacity = capacity;
        }
        if (initialSize > 0) {
            InitializeItems(pData, initialSize);
            uiSize = initialSize;
        }
    }

    ~NavMeshArray() {
        vtable = (void**)&DAT_00db5c04;
        Clear(true);
    }
    void Deallocate(NavMesh** items) { ((void (__thiscall*)(NavMeshArray*, void*))vtable[2])(this, items); }
    void Clear(bool freeStorage) {
        if (pData) {
            FUN_00415f50(pData, uiSize);
            if (freeStorage) {
                Deallocate(pData);
                pData = 0;
                uiCapacity = 0;
            }
            uiSize = 0;
        }
    }
    void FUN_00415f50(void* data, unsigned int count);
    unsigned int GetSize() const { return uiSize; }
    NavMesh* GetAt(unsigned int i) const { return pData[i]; }
};

struct Location {
    int unk00;
    NiPoint3 kPos;
    NiPoint3 GetPos() const { return kPos; }
    bool FUN_005fda30(int);
    bool FUN_005fc750();
};

void __cdecl FUN_005f5eb0(Location* loc, float radius, NavMeshArray* out, int flags);

// pdb: Pathing::FindClosestEdges | Pathfind.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aLocation, aiMaxCount, aRetEdges
int __cdecl FUN_005f90b0(Location* loc, unsigned int limit, CoverEntryArray* out)
{
    loc->FUN_005fda30(0);
    if (loc->FUN_005fc750())
        return 1;

    float fRadius = DAT_01074920;
    float fRadiusSq = fRadius * fRadius;
    NavMeshArray kNavMeshes;
    FUN_005f5eb0(loc, fRadius, &kNavMeshes, 0);

    CoverItemArray kItems;
    for (unsigned int i = 0; i < kNavMeshes.GetSize(); ++i) {
        NiPointer<NavMesh> spNavMesh = kNavMeshes.GetAt(i);
        for (unsigned int uiTri = 0; uiTri < spNavMesh->GetTriangleCount(); ++uiTri) {
            NavTriangle* pTri = spNavMesh->GetTriangle((unsigned short)uiTri);
            for (int iEdge = 0; iEdge < 3; ++iEdge) {
                if (pTri->GetEdge(iEdge) == 0xFFFF) {
                    NiPoint3* pA = spNavMesh->GetVertex(pTri->GetVertex(iEdge));
                    int iNext = iEdge + 1;
                    if (iNext == 3)
                        iNext = 0;
                    NiPoint3* pB = spNavMesh->GetVertex(pTri->GetVertex(iNext));
                    NiPoint3 kClosest = FUN_005dd040(loc->GetPos(), *pA, *pB);
                    NiPoint3 kDelta = loc->GetPos() - kClosest;
                    float fDistSq = kDelta.x * kDelta.x + kDelta.y * kDelta.y;
                    if (fDistSq < fRadiusSq) {
                        CoverItem kItem;
                        kItem.pNavMesh = spNavMesh;
                        kItem.usTriangle = (unsigned short)uiTri;
                        kItem.iEdge = iEdge;
                        kItem.kPoint = kClosest + (spNavMesh->FUN_004d45e0((unsigned short)uiTri) - kClosest) * 0.1f;
                        kItem.fHeight = kDelta.z;
                        kItem.fDistSq = fDistSq;
                        kItems.Add(kItem);
                    }
                }
            }
        }
    }

    if (kItems.IsEmpty())
        return 0;
    FUN_00c011c0(kItems.GetAt(0), kItems.GetSize(), sizeof(CoverItem), FUN_005f11b0);
    unsigned int uiCount = MinCount(limit, kItems.GetSize());
    for (unsigned int j = 0; j < uiCount; ++j) {
        out->Add(CoverEntry(*kItems.GetAt(j)));
    }
    if (uiCount > 0)
        return 2;
    else
        return 0;
}

}
}   // namespace f3m_005f90b0

// @f3 0x005fda30 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
extern const float DAT_00e02248;
const float DAT_00e02248 = 16384.0f;
#include <windows.h>
namespace f3_5fda30 {
typedef f3m_005ec900::NiPoint3 Point;
struct RefCounter {
    virtual void Slot0();
    virtual void ReleaseLast();
    LONG refs;
    void Release() { if (!InterlockedDecrement(&refs)) ReleaseLast(); }
};
struct Loaded {
    unsigned int unk00,unk04,flags,unk0c,unk10,unk14,unk18;
    RefCounter counter;
    unsigned short FUN_005beb00(Point* location, int parameter);
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
    bool IsDisabled() const { return (flags >> 11) & 1; }
};
typedef NiPointer<Loaded> ResourcePtr;
__declspec(noinline) void FUN_005b87d0(ResourcePtr* dest, void* token) {
    ResourcePtr incoming(static_cast<Loaded*>(token));
    *dest=incoming;
}
struct Candidate {
    bool FUN_005c2870(Point*);
    Point FUN_005c29f0(const Point&);
};
struct Entry {
    unsigned int unk00,unk04,flags;
    unsigned int unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50;
    void* token54;
    Candidate* candidate58;
    bool FUN_005bd090(ResourcePtr* out);
    bool IsDisabled() const { return (flags >> 4) & 1; }
    __forceinline bool GetResource(ResourcePtr& out) const {
        if (IsDisabled()) return false;
        FUN_005b87d0(&out, token54);
        return out.m_pObject != 0;
    }
};
struct EntryArray {
    unsigned int unk00;
    Entry** data;
    unsigned int count;
    unsigned int capacity;
    Entry*& GetAt(unsigned int i) { return data[i]; }
};
struct Type6 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    unsigned short unk24;
    unsigned char type26;
    unsigned char unk27;
};
struct Provider { Type6* FUN_00501d90(unsigned int); };
struct StateBits {
    unsigned char selected : 1;
    unsigned char blocked : 1;
    unsigned char unk26_high : 6;
};
union State { unsigned char raw; StateBits bits; };
struct Owner {
    void* vtable;
    Point origin;
    Entry* current;
    EntryArray* array;
    Type6* cached;
    Provider* provider;
    unsigned int id;
    unsigned short index;
    State state;
    unsigned char unk27;
    bool FUN_005fcc10();
    bool FUN_005fd770();
    Type6* GetType() {
        if (cached) return cached;
        if (provider) { Type6* result=provider->FUN_00501d90(id); if (result) return result; }
        return 0;
    }
    bool GetSelected() const { return (state.raw & 1) != 0; }
    void SetSelected(unsigned int value) { state.raw = (state.raw & 0xfe) | (unsigned char)value; }
    void Select(Entry* entry, unsigned int triangle) {
        current=entry;
        array=0;
        index=(unsigned short)triangle;
        state.raw|=1;
    }
};
}
namespace f3m_005f2190 {
// pdb: PathingLocation::ResolveNavMeshInfo | PathingLocation.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apFilter
bool Subject5f2190::FUN_005fda30(int parameter) {
    using namespace f3_5fda30;
    f3_5fda30::Owner* self=reinterpret_cast<f3_5fda30::Owner*>(this);
    if ((self->state.raw & 2u) > 0u) return false;
    if (!self->current && !self->array) return false;
    if (self->current) {
        if (self->current->IsDisabled()) return false;
        if (self->index==0xffff) {
            f3_5fda30::ResourcePtr selected;
            if (self->current->FUN_005bd090(&selected))
                self->index=selected->FUN_005beb00(&self->origin,parameter);
        }
        return true;
    }
    if (self->GetType() && self->GetType()->type26==6) {
        int savedParameter=parameter;
        if (self->array->count>0) for (unsigned int i=0;i<self->array->count;++i) {
            f3_5fda30::ResourcePtr resource;
            if (self->array->GetAt(i)->GetResource(resource) && !resource->IsDisabled()) {
                unsigned int triangle=resource->FUN_005beb00(&self->origin,savedParameter);
                if ((unsigned short)triangle!=0xffff) {
                    self->Select(self->array->GetAt(i),triangle);
                    return true;
                }
            }
        }
        f3_5fda30::Point original=self->origin;
        bool done=self->FUN_005fcc10();
        self->index=0xffff;
        self->origin=original;
        if (done) { self->state.raw |= 1; } else { self->SetSelected(done || (self->state.raw & 1)); }
        return done;
    }
    {
        unsigned int n = self->array->count;
        unsigned int i = 0;
        if (n > 0) {
            do {
                _ReadWriteBarrier();
                f3_5fda30::Entry* entry=self->array->GetAt(i);
                if (!entry->IsDisabled() && entry->candidate58 && entry->candidate58->FUN_005c2870(&self->origin)) {
                    self->current=self->array->GetAt(i);
                    self->array=0;
                    f3_5fda30::ResourcePtr out;
                    if (self->current->FUN_005bd090(&out))
                        self->index=out->FUN_005beb00(&self->origin,parameter);
                    self->state.raw|=1;
                    return true;
                }
                ++i;
            } while (i < self->array->count);
        }
    }
    float bestDistance=3.402823466e+38f;
    unsigned int fallbackIndex=0xffffffff;
    unsigned int bestIndex=0xffffffff;
    for (unsigned int i=0;i<self->array->count;++i) {
        f3_5fda30::Entry* entry=self->array->GetAt(i);
        if (entry->IsDisabled()) continue;
        f3_5fda30::Candidate* candidate=entry->candidate58;
        if (candidate) {
            f3_5fda30::Point delta=candidate->FUN_005c29f0(self->origin);
            float squared=delta.SqrLength();
            if (squared<bestDistance) {
                bestDistance=squared;
                bestIndex=i;
            }
        } else {
            fallbackIndex=i;
        }
    }
    if (bestDistance < DAT_00e02248) {
        self->Select(self->array->GetAt(bestIndex),0xffff);
        return true;
    }
    self->current=self->array->GetAt(fallbackIndex);
    self->array=0;
    self->SetSelected(self->FUN_005fd770());
    return self->GetSelected();
}
}

// @f3 0x005ed960 (community match, verified in this file)
extern char DAT_010748a8;
extern char DAT_0107489c;
namespace f3m_005ed960 {
namespace f3m_005ed960 {

struct Words16F3 { int u00, u04, u08, u0c; };
struct Words64F3 { Words16F3 q00, q10, q20, q30; };
struct Words256F3 { Words64F3 b000, b040, b080, b0c0; };
struct Words1KF3 { Words256F3 k000, k100, k200, k300; };
struct Words4KF3 { Words1KF3 p0000, p0400, p0800, p0c00; };

struct PointF3 { float x, y, z; };

struct LocationF3 {
    int u00;
    PointF3 position;
    PointF3 GetLocation() const { return position; }
};

struct PathEntryF3 {
    void* node;
    unsigned short index;
    unsigned short u06;
    int u08, u0c, u10;
    void* GetNode() const { return node; }
    unsigned short GetIndex() const { return index; }
};

struct PathEntriesF3 {
    int u00;
    PathEntryF3* data;
    unsigned int count;
    unsigned int GetCount() const { return count; }
    PathEntryF3& GetAt(unsigned int i) { return data[i]; }
};

struct ListEntryF3 {
    void* node;
    unsigned short index;
    ListEntryF3() {}
    ListEntryF3(void* n, unsigned short idx) : node(n), index(idx) {}
};

// sizeof == 0x14 (20 bytes: ScrapArray!)
struct ListF3 {
    int vtbl;
    ListEntryF3* data;
    unsigned int size;
    unsigned int capacity;
    void* allocator;

    ListF3(unsigned int count, int flags, void* allocator);
    ~ListF3();
    int FUN_006cb090();
    void Add(const ListEntryF3& item) { ListEntryF3& dst = data[FUN_006cb090()]; dst.node = item.node; dst.index = item.index; }
};

// sizeof == 0x20f8 (8440 bytes)
struct SearchAF3 {
    Words4KF3 s0000, s1000;
    Words64F3 s2000, s2040, s2080;
    Words16F3 s20c0, s20d0, s20e0;
    int s20f0, s20f4;

    SearchAF3();
    ~SearchAF3();
    bool FUN_005c7ee0(LocationF3* start, LocationF3* goal, ListF3* list, void* actor, void* owner);
};

// sizeof == 0x00b8 (184 bytes: DetailedBuilder!)
struct SearchBF3 {
    Words64F3 b00, b40;
    Words16F3 b80, b90, ba0;
    int bb0, bb4;

    SearchBF3();
    ~SearchBF3();
    bool FUN_0060ebd0(void* actor, PathEntriesF3* entries, int mode, const PointF3& start, const PointF3& goal, void* owner,
                      int flags, int one);
};

// sizeof == 0x210c (8460 bytes)
struct SearchCF3 {
    Words4KF3 s0000, s1000;
    Words256F3 s2000;
    int s2100, s2104, s2108, s210c;

    SearchCF3();
    ~SearchCF3();
    bool FUN_005d81b0(void* actor, PathEntriesF3* entries, int mode, const PointF3& start, const PointF3& goal, void* owner,
                      int flags, void* output);
};

struct ActorF3 {
    Words64F3 a00;
    Words16F3 a40, a50;
    int u60, u64;
    float radius;

    __forceinline float GetRadius() const {
        return radius;
    }
};


struct PathRequestF3 {
    ActorF3* actor;
    void* owner;
    void* allocator;
    int u0c, u10;
    int output;

    bool FUN_005ed960(LocationF3* start, LocationF3* goal, int flags, PathEntriesF3* entries, int mode);
};

// pdb: PathBuilder::RunPathSmoother | PathBuilder.obj | fnv360_0822_retail, objrun, medium
// pdb params: aStartLocation, aGoalLocation, aBadNodes, aNodes, aLinks
bool PathRequestF3::FUN_005ed960(LocationF3* start, LocationF3* goal, int flags, PathEntriesF3* entries, int mode)
{
    bool result;
    if (DAT_010748a8 && actor->GetRadius() > 150.0f)
    {
        ListF3 list(entries->GetCount(), 0, allocator);
        for (unsigned int i = 0; i < entries->GetCount(); ++i)
        {
            list.Add(ListEntryF3(entries->GetAt(i).GetNode(), entries->GetAt(i).GetIndex()));
        }
        SearchAF3 search;
        result = search.FUN_005c7ee0(start, goal, &list, actor, owner);
    }
    else if (DAT_0107489c)
    {
        SearchBF3 search;
        result = search.FUN_0060ebd0(actor, entries, mode, start->GetLocation(), goal->GetLocation(), owner, flags, 1);
    }
    else
    {
        SearchCF3 search;
        result = search.FUN_005d81b0(actor, entries, mode, start->GetLocation(), goal->GetLocation(), owner, flags, &output);
    }
    return result;
}

}
}   // namespace f3m_005ed960

// @f3 0x005e8390 (community match, verified in this file)
namespace f3m_005e8390 {
namespace f3m_005e8390 {

void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ec10(void* p, unsigned int size);

struct RefObj
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T> struct SimpleArray
{
    void** m_pkVtbl;
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    T& GetAt(unsigned int i) { return m_pData[i]; }
};

struct ElemRef
{
    void* FUN_005b84c0();
};

struct PtrArray
{
    void** m_pkVtbl;
    void** m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    void FUN_00799ae0(unsigned int capacity, unsigned int size);

    __forceinline unsigned int Add(void* const& val)
    {
        if (m_uiSize == m_uiCapacity)
        {
            if (!m_uiCapacity)
            {
                m_pData = (void**)((void* (__thiscall*)(PtrArray*, unsigned int))m_pkVtbl[1])(this, 4);
                m_uiCapacity = 4;
            }
            else
            {
                unsigned int capacity;
                if (m_uiCapacity > 0x400)
                    capacity = m_uiCapacity + 0x400;
                else
                    capacity = m_uiCapacity * 2;
                FUN_00799ae0(capacity, m_uiSize);
                m_uiCapacity = capacity;
            }
        }
        ++m_uiSize;
        m_pData[m_uiSize - 1] = val;
        return m_uiSize - 1;
    }
};

struct Item : RefObj
{
    int u08, u0c, u10, u14, u18, u1c;
    int u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c;
    int u60, u64, u68, u6c, u70, u74;
    PtrArray list;
};

struct FUN_005e6e80 : RefObj
{
    const char* key;
    SimpleArray<NiPointer<Item> > items;

    FUN_005e6e80();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p, unsigned int size) { FUN_0089ec10(p, size); }
};

struct Sink
{
    void** m_pkVtbl;
    ElemRef** m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void* m_pAllocator;

    Sink() { FUN_005e7610(); }
    ~Sink() { FUN_005e7680(); }
    void FUN_005e7610();
    void FUN_005e7680();
    unsigned int GetSize() const { return m_uiSize; }
    ElemRef*& GetAt(unsigned int j) { return m_pData[j]; }
};

struct Target
{
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
    virtual void* v1d0();
    int u04;
    int u08;
    const char* key;
    const char* GetKey() const { return key; }
};

struct Entry
{
    void FUN_005ea490(NiPointer<Item>* item, int flags);
};

struct Node
{
    Target* data;
    Node* next;
    bool IsEmpty() const { return next == 0 && data == 0; }
    __declspec(noalias) void FUN_00421610(Target** item);
};

struct NameMap
{
    void FUN_00899cf0(const char* key);
};

struct GroupStore
{
    void FUN_00ad3b80(const char* key, NiPointer<FUN_005e6e80> group);
};

bool __cdecl FUN_005e7470(Target* target, NiPointer<FUN_005e6e80>* group);
bool __cdecl FUN_005e7120(NiPointer<Item>* item, Sink* sink);

struct Owner
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    int u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c;
    int u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88;
    Node unk8C;
    int u94, u98;
    NameMap unk9C;
    int ua0, ua4, ua8;
    GroupStore unkAC;

    Entry* FUN_005e4ce0(void* element);
    bool FUN_005e8390();
};

// pdb: NavMeshObstacleManager::ProcessNewDoors | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool Owner::FUN_005e8390()
{
    Node* list = &unk8C;
    if (list->IsEmpty())
        return false;
    bool result = false;
    Node* node = &unk8C;
    while (node && !node->IsEmpty())
    {
        Target* target = node->data;
        if (target->v1d0())
        {
            NiPointer<FUN_005e6e80> group = new FUN_005e6e80();
            group->key = target->GetKey();
            if (FUN_005e7470(target, &group))
            {
                for (unsigned int i = 0; i < group->items.m_uiSize; ++i)
                {
                    Sink sink;
                    if (FUN_005e7120(&group->items.GetAt(i), &sink))
                    {
                        for (unsigned int j = 0; j < sink.GetSize(); ++j)
                        {
                            FUN_005e4ce0(sink.GetAt(j)->FUN_005b84c0())->FUN_005ea490(&group->items.GetAt(i), 0x30);
                            group->items.GetAt(i)->list.Add(sink.GetAt(j)->FUN_005b84c0());
                        }
                    }
                }
                unk9C.FUN_00899cf0(target->GetKey());
                unkAC.FUN_00ad3b80(target->GetKey(), group);
                result = true;
            }
            node = &unk8C;
            node->FUN_00421610(&target);
        }
        else
        {
            node = node->next;
        }
    }
    return result;
}

}
}   // namespace f3m_005e8390

// @f3 0x005ff490 (community match, verified in this file)
namespace f3m_005ff490 {
namespace n5ff490 {
using f3m_005ff620::Object5ff620;
using f3m_005ff620::ObjectPtr5ff620;
using f3m_005ff620::Entry5ff620;

struct Ptr490
{
    Object5ff620* m_object;
    Ptr490() : m_object(0) {}
    ~Ptr490()
    {
        if (m_object)
            m_object->DecRefCount();
    }
};
__declspec(noalias) void __cdecl FUN_005b87d0(Ptr490* __restrict out, void* source);

struct Source490
{
    int unk00;
    int unk04;
    unsigned int flags;
    int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50;
    void* unk54;
};

struct Entry490 : Entry5ff620
{
    void FUN_005ff490(Source490* source);
};

// pdb: PathingLOSGrid::Setup | PathingLOSGridMap.obj | fnv360_0721_beta, caller, medium
// pdb params: aspNavMesh
void Entry490::FUN_005ff490(Source490* source)
{
    cached = source;
    Ptr490 object;
    bool ok = false;
    if (!((unsigned char)(source->flags >> 4) & 1))
    {
        FUN_005b87d0(&object, source->unk54);
        ok = object.m_object != 0;
    }
    if (!ok)
    {
        cached = 0;
        return;
    }
    FUN_005ff1d0(*reinterpret_cast<const ObjectPtr5ff620*>(&object));
}
}
}   // namespace f3m_005ff490

// @f3 0x005e4620 (community match, verified in this file)
namespace f3m_005e4620 {
namespace f3m_005e4620 {
struct Pt4620 {
    float x, y, z;
    Pt4620() {}
    Pt4620(float a, float b, float c) : x(a), y(b), z(c) {}
    Pt4620 operator-(const Pt4620& o) const { return Pt4620(x - o.x, y - o.y, z - o.z); }
};
struct Mat4620 {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    Pt4620 InverseRotate(const float* v) const
    {
        Pt4620 r;
        r.x = v[1] * m10 + m00 * v[0] + m20 * v[2];
        r.y = v[0] * m01 + v[1] * m11 + m21 * v[2];
        r.z = m02 * v[0] + m12 * v[1] + v[2] * m22;
        return r;
    }
};
struct Box4620 {
    int unk00, unk04, unk08, unk0C;
    Pt4620 kTranslate;
    Mat4620 kRotate;
    Pt4620 kMinBounds;
    Pt4620 kMaxBounds;
};
// pdb: NavMesh::IsPointInsideTriangle | NavMesh_Util.obj | fnv360_0822_retail, call_seq, low
// pdb params: asTriangleIndex, aLocation, afZDiff, afMaxZdistAbove, afMaxZdistBelow
bool __cdecl FUN_005e4620(Pt4620* pnt, Box4620** ppB, float c, float fz)
{
    Box4620* b = *ppB;
    float d[3];
    d[0] = pnt->x - b->kTranslate.x;
    d[1] = pnt->y - b->kTranslate.y;
    d[2] = pnt->z - b->kTranslate.z;
    Pt4620 r = b->kRotate.InverseRotate(d);
    if (r.z < -c || r.z > fz) return false;
    if (r.x < b->kMinBounds.x || r.x > b->kMaxBounds.x) return false;
    if (r.y < b->kMinBounds.y || r.y > b->kMaxBounds.y) return false;
    return true;
}
}
}   // namespace f3m_005e4620

// @f3 0x005fcc10 (community match, verified in this file)
namespace S005fcc10_ns {

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
};

struct RefCounted {
    void** vtable;
    long refs;
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(RefCounted*))vtable[1])(this);
    }
};

struct EdgeHit {
    void* pNavMesh;
    int iEdge;
    Vec3 kPoint;
};

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounted ref1C;
    void IncRefCount() { InterlockedIncrement(&ref1C.refs); }
    void DecRefCount() { ref1C.DecRefCount(); }
    bool FUN_005becd0(const Vec3& location, unsigned short* triangle, bool* exact);
    Vec3 FUN_004d45e0(unsigned short triangle) const;
    EdgeHit FUN_005bdf70(unsigned short triangle, int edge, const Vec3& center, const Vec3& location);
};

__declspec(noinline) void __cdecl FUN_005b87d0(NiPointer<NavMesh>* ap_spNavMesh, NavMesh* ap_NavMesh) {
    *ap_spNavMesh = ap_NavMesh;
}

struct NavMeshInfo {
    int unk00;
    int unk04;
    unsigned int uiFlags;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    NavMesh* pNavMesh;
    bool GetDisabled() const { return (uiFlags >> 4) & 1; }
    bool GetNavMesh(NiPointer<NavMesh>& ar_spNavMesh) const {
        if (GetDisabled())
            return false;
        FUN_005b87d0(&ar_spNavMesh, pNavMesh);
        return ar_spNavMesh.m_pObject != 0;
    }
};

struct NavMeshInfoArray {
    void** table;
    NavMeshInfo** data;
    unsigned int size;
    unsigned int capacity;
};

struct Mgr {
    float TES_GetWaterHeight(const Vec3* location, void* cell);
};
extern Mgr* DAT_0107a0d8;
extern const double DAT_00de8060;

struct PathingLocation {
    void* vtable;
    Vec3 location;
    NavMeshInfo* navMeshInfo;
    NavMeshInfoArray* navMeshes;
    void* cell;
    void* worldSpace;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    void PathingLocation_SetupData(Vec3* location, void* cell, void* worldSpace);
    bool FUN_005fcc10();
};

// pdb: PathingLocation::ResolveToClosestNavmeshAndTriangle | PathingLocation.obj | fnv360_0822_retail, call_gap, low
bool PathingLocation::FUN_005fcc10() {
    PathingLocation_SetupData(&location, cell, worldSpace);
    if (!navMeshInfo && !navMeshes)
        return false;
    if (navMeshInfo && triangle != 0xFFFF)
        return true;
    if (navMeshInfo) {
        bool exact = false;
        NiPointer<NavMesh> spNavMesh;
        if (navMeshInfo->GetNavMesh(spNavMesh)) {
            if (spNavMesh->FUN_005becd0(location, &triangle, &exact)) {
                if (!exact) {
                    unsigned short tri = triangle;
                    Vec3 center = spNavMesh->FUN_004d45e0(tri);
                    EdgeHit hit = spNavMesh->FUN_005bdf70(tri, -1, center, location);
                    if (hit.pNavMesh)
                        location = hit.kPoint * 0.9f + center * 0.1f;
                }
                return true;
            }
            return false;
        }
    } else {
        float bestDist = 3.4028234663852886e+38f;
        int bestIndex = -1;
        unsigned int bestTri = 0xFFFF;
        bool found = false;
        unsigned int count = navMeshes->size;
        bool below = false;
        if (DAT_0107a0d8->TES_GetWaterHeight(&location, cell) + DAT_00de8060 > location.z)
            below = true;
        for (unsigned int i = 0; i < count; ++i) {
            unsigned int tri = 0xFFFF;
            bool exact = false;
            NiPointer<NavMesh> spNavMesh;
            if (navMeshes->data[i]->GetNavMesh(spNavMesh) && !spNavMesh->FUN_005becd0(location, reinterpret_cast<unsigned short*>(&tri), &exact))
                continue;
            if (exact) {
                navMeshInfo = navMeshes->data[i];
                navMeshes = 0;
                triangle = tri;
                return true;
            }
            if (spNavMesh) {
                unsigned int usTri = tri;
                Vec3 delta = location - spNavMesh->FUN_004d45e0(usTri);
                float dist = delta.x * delta.x + delta.y * delta.y;
                bool inRange = false;
                if ((below || delta.z < 180.0f) && delta.z > -64.0f)
                    inRange = true;
                if (found) {
                    if (inRange && dist < bestDist) {
                        bestDist = dist;
                        bestTri = (unsigned short)usTri;
                        bestIndex = i;
                    }
                } else if (inRange) {
                    bestDist = dist;
                    bestTri = (unsigned short)usTri;
                    bestIndex = i;
                    found = true;
                } else if (dist < bestDist) {
                    bestDist = dist;
                    bestTri = (unsigned short)usTri;
                    bestIndex = i;
                }
            }
        }
        if (bestIndex != -1) {
            navMeshInfo = navMeshes->data[bestIndex];
            navMeshes = 0;
            triangle = bestTri;
            NiPointer<NavMesh> spNavMesh;
            if (navMeshInfo->GetNavMesh(spNavMesh)) {
                Vec3 center = spNavMesh->FUN_004d45e0(bestTri);
                EdgeHit hit = spNavMesh->FUN_005bdf70(bestTri, -1, center, location);
                if (hit.pNavMesh)
                    location = center * 0.1f + hit.kPoint * 0.9f;
                return true;
            }
        }
    }
    return false;
}

}

// @f3 0x005e0860 (community match, verified in this file)
namespace f3m_005e0860 {
namespace f3m_005e0860 {
struct NavVert_5e0860
{
    float x, y, z;
};

struct NavTri_5e0860
{
    unsigned short sVertex0, sVertex1, sVertex2;
    unsigned short sTriangle[3];
    unsigned int TriangleFlags;
};

struct BoundsTri_5e0860
{
    unsigned short usTriangle;
    bool bEdge[3];
    unsigned short usNext[3];
};

template <class T>
class SimpleArray_5e0860
{
public:
    virtual ~SimpleArray_5e0860();
    virtual T* _Allocate(unsigned int a_iCount);
    virtual void _Deallocate(T* a_pData);
    virtual T* _Reallocate(T* a_pData,unsigned int a_iCount);
    void FUN_0079ecc0(unsigned int a_iNewSize,unsigned int a_iMoveCount);

    T* pBuffer;
    unsigned int iSize;
    unsigned int iReservedSize;
};

class NavMesh_5e0860
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    SimpleArray_5e0860<NavVert_5e0860> Vertices;
    SimpleArray_5e0860<NavTri_5e0860> Triangles;
    __forceinline NavTri_5e0860* GetTriangle(unsigned short index) { return &Triangles.pBuffer[index]; }
};

class Undo_5e0390
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SimpleArray_5e0860<unsigned short> OverlappedTriangles;
};

inline int IndexOfUShort(const SimpleArray_5e0860<unsigned short>& a_rArray, unsigned int a_usValue)
{
    for (unsigned int i = 0; i < a_rArray.iSize; i++)
        if (a_rArray.pBuffer && a_rArray.pBuffer[i] == a_usValue)
            return (int)i;
    return -1;
}

inline bool BoundsContains(const SimpleArray_5e0860<BoundsTri_5e0860>& a_rArray, unsigned int a_usValue)
{
    for (unsigned int i = 0; i < a_rArray.iSize; i++)
    {
        const BoundsTri_5e0860* pData = &a_rArray.pBuffer[i];
        if (pData->usTriangle == a_usValue)
            return true;
    }
    return false;
}

template <class T>
__forceinline void SetSize_5e0860(SimpleArray_5e0860<T>& a_rArray, unsigned int a_iNewSize)
{
    if (a_iNewSize == 0)
    {
        if (a_rArray.pBuffer)
        {
            a_rArray._Deallocate(a_rArray.pBuffer);
            a_rArray.pBuffer = 0;
            a_rArray.iReservedSize = 0;
            a_rArray.iSize = 0;
        }
    }
    else if (a_iNewSize > a_rArray.iReservedSize)
    {
        if (a_rArray.iReservedSize == 0)
            a_rArray.pBuffer = a_rArray._Allocate(a_iNewSize);
        else
            a_rArray.FUN_0079ecc0(a_iNewSize, a_rArray.iSize);
        a_rArray.iReservedSize = a_iNewSize;
        a_rArray.iSize = a_iNewSize;
    }
    else if (a_iNewSize < a_rArray.iSize)
    {
        a_rArray.iSize = a_iNewSize;
        if (a_iNewSize <= a_rArray.iReservedSize / 4)
        {
            a_rArray.FUN_0079ecc0(a_iNewSize, a_iNewSize);
            a_rArray.iReservedSize = a_iNewSize;
        }
    }
    else
    {
        a_rArray.iSize = a_iNewSize;
    }
}

class NavMeshObstacleCutter_5e0860
{
public:
    NavMesh_5e0860* pNavMesh;
    void* spObstacle;
    Undo_5e0390* pUndoData;

    void FUN_005e0860(SimpleArray_5e0860<BoundsTri_5e0860>& a_rBoundsTriangles);
};

// pdb: NavMeshObstacleCutter::GetModifiedTriangleList | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
// pdb params: aBoundsTriangle
void NavMeshObstacleCutter_5e0860::FUN_005e0860(SimpleArray_5e0860<BoundsTri_5e0860>& a_rBoundsTriangles)
{
    for (unsigned int i = 0; i < pUndoData->OverlappedTriangles.iSize; i++)
    {
        NavTri_5e0860* pTriangle = pNavMesh->GetTriangle(pUndoData->OverlappedTriangles.pBuffer[i]);
        pTriangle->TriangleFlags &= ~0x100u;
        int e = 0;
        unsigned short* pNextIndex = pTriangle->sTriangle;
        for (; e < 3; e++, pNextIndex++)
        {
            if (pTriangle->TriangleFlags & (1u << e))
                continue;
            unsigned short usAdjacent = *pNextIndex;
            if (usAdjacent == 0xffff)
                continue;
            unsigned int usNext = usAdjacent;
            NavMesh_5e0860* pMesh = pNavMesh;
            if (usNext >= pMesh->Triangles.iSize)
                continue;
            NavTri_5e0860* pNeighbor = pMesh->GetTriangle((unsigned short)usNext);
            if (IndexOfUShort(pUndoData->OverlappedTriangles, usNext) != -1)
                continue;
            if (BoundsContains(a_rBoundsTriangles, usNext))
                continue;
            unsigned int iIndex = a_rBoundsTriangles.iSize;
            SetSize_5e0860(a_rBoundsTriangles, iIndex + 1);

            a_rBoundsTriangles.pBuffer[iIndex].usTriangle = (unsigned short)usNext;
            pNeighbor->TriangleFlags |= 0x100u;
            unsigned int k = 0;
            do
            {
                if (pNeighbor->TriangleFlags & (1u << k))
                {
                    a_rBoundsTriangles.pBuffer[iIndex].bEdge[k] = true;
                    a_rBoundsTriangles.pBuffer[iIndex].usNext[k] = pNeighbor->sTriangle[k];
                }
                else
                {
                    a_rBoundsTriangles.pBuffer[iIndex].bEdge[k] = false;
                    a_rBoundsTriangles.pBuffer[iIndex].usNext[k] = pNeighbor->sTriangle[k];
                }
            } while (++k < 3);
        }
    }
}


} // namespace f3m_005e0860
}   // namespace f3m_005e0860

// @f3 0x005e3000 (community match, verified in this file)
namespace f3m_005e3000 {
struct S_005e3000 {
    char pad[24];
    unsigned char m;
    void FUN_005e3000();
};
// pdb: NavMeshObstacleManager::QueueUpdateAllObstacle | NavMeshObstacleManager.obj | fnv360_0721_beta, call_seq, medium
void S_005e3000::FUN_005e3000()
{
    m = 1;
}
}   // namespace f3m_005e3000

// @f3 0x005eaa50 (community match, verified in this file)
namespace f3m_005eaa50 {
// pdb: PathBuilder::FindTriangleForLocationWaterFilter::IsValidTri | PathBuilder.obj | fnv360_0721_beta, vtable, medium
// pdb params: aLocation, apNavMesh, aiTri, aPointOnTri
bool __stdcall FUN_005eaa50(int p0, int p1, int p2, int p3)
{
    return true;
}
}   // namespace f3m_005eaa50

// @f3 0x005fd720 (community match, verified in this file)
namespace f3m_005fd720 {
namespace f3m_005fd720 {

struct NavMeshInfo;
struct NavMeshInfoArray {
    void* table;
    const NavMeshInfo** data;
    unsigned int size;
    unsigned int capacity;
    unsigned int FUN_005e5350();
    void FUN_00602700(NavMeshInfoArray* output) const;
};

struct NavMeshSelection {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    const NavMeshInfo* pNavMesh;
    const NavMeshInfoArray* pNavMeshes;
    bool FUN_005fd720(NavMeshInfoArray* output) const;
};

// pdb: PathingLocation::GetNavMeshInfos | PathingLocation.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apRetInfos
bool NavMeshSelection::FUN_005fd720(NavMeshInfoArray* output) const
{
    if (pNavMesh != 0) {
        output->data[output->FUN_005e5350()] = pNavMesh;
        return true;
    }
    if (pNavMeshes != 0) {
        pNavMeshes->FUN_00602700(output);
        return true;
    }
    return false;
}

}
}   // namespace f3m_005fd720

// @f3 0x005e5280 (community match, verified in this file)
namespace n5e8c20 {

struct Slot {
    void* unk00;
    void* unk04;
    void FUN_0059acd0();
    Slot() { FUN_0059acd0(); }
    static void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

// pdb: ThreadSpecificInterfaceManager<LockFreeMap<MobileObject *,NiPointer<LipTask> >::LockFreeMapInterface>::ThreadSpecificInterfaceManager<LockFreeMap<MobileObject *,NiPointer<LipTask> >::LockFreeMapInterface> | LipSyncBackgroundManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiMaxThreads
FUN_005e5280::FUN_005e5280(unsigned int count)
{
    TlsTagGuard guard(6);
    unk0C = 0;
    count00 = count;
    data08 = new Slot[count];
    tlsIndex04 = TlsAlloc();
}
}

// @f3 0x005f89d0 (community match, verified in this file)
extern __declspec(thread) int DAT_0117c298;
namespace f3m_005f89d0 {

struct Heap {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* ptr);
};
extern Heap DAT_01090a78;
extern void* DAT_00dc4dc0;
extern void* DAT_00dc4dc4;
extern float FUN_00dc31b4;

struct TlsGuard {
    int saved;
    TlsGuard(int v) : saved(DAT_0117c298) { DAT_0117c298 = v; }
    ~TlsGuard() { DAT_0117c298 = saved; }
};

struct Point3 {
    float x, y, z;
};

struct Object5fc430;

struct Object5fc430Pod {
    void* vtable;
    int m04, m08, m0c, m10, m14, m18, m1c, m20;
    short m24;
    char m26;
    void FUN_005fc480(const Object5fc430& other);
};

struct Object5fc430 {
    void* vtable;
    int m04, m08, m0c, m10, m14, m18, m1c, m20;
    short m24;
    char m26;

    void FUN_005fc430(const Object5fc430Pod& other);
    void FUN_005fd570(const Point3* pos, const Object5fc430& other);
    void FUN_005fc480(const Object5fc430& other);

    __forceinline Object5fc430(const Object5fc430Pod& other) { FUN_005fc430(other); }
    __forceinline Object5fc430(const Point3* pos, const Object5fc430& other) { FUN_005fd570(pos, other); }
    __forceinline ~Object5fc430() { vtable = &DAT_00dc4dc0; }
    __forceinline Object5fc430& operator=(const Object5fc430& other) {
        FUN_005fc480(other);
        return *this;
    }
};

struct SubBase14 {
    void* vtable;
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c, m50;
    __forceinline ~SubBase14() { vtable = &DAT_00dc4dc0; }
};

struct FUN_005f14e0 {
    int u00, u04, u08, u0c, u10;
    SubBase14 m14;
    int u68, u6c, u70, u74;

    FUN_005f14e0();
    __forceinline ~FUN_005f14e0() {}
    static void* operator new(unsigned int sz) { return DAT_01090a78.FUN_0086b930(sz); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct FUN_005f4550 {
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38;

    FUN_005f4550();
    static void* operator new(unsigned int sz) { return DAT_01090a78.FUN_0086b930(sz); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Elem3c {
    int u00;
    Object5fc430Pod m04;
    int u2c, u30, u34, u38;
};

struct Arg1 {
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20;
    Elem3c* arr24;
    unsigned int count28;
    unsigned int GetSize() const { return count28; }
    __forceinline Elem3c& GetAt(unsigned int idx) { return arr24[idx]; }
};

struct Sub74 {
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40;
    void FUN_006062f0();
    void FUN_00606380();
    void FUN_00606430(Arg1* a1);

    __forceinline Sub74() { FUN_006062f0(); }
    ~Sub74();
};

struct PathObj {
    int u00, u04, u08;
    Object5fc430Pod m0c;
    Object5fc430Pod m34;
    int u5c, u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c;
    int ua0, ua4, ua8, uac, ub0, ub4, ub8, ubc, uc0, uc4;
    Point3 posC8;
    int ud4, ud8, udc;
    unsigned char be0;
    bool be1;
    unsigned char be2, be3;
    int ue4, ue8, uec, uf0, uf4, uf8, ufc, u100;
    FUN_005f14e0* m104;
    FUN_005f4550* m108;

    void FUN_00602bb0(PathObj* other);
    void FUN_00602c50();

    __forceinline PathObj(PathObj* other) { FUN_00602bb0(other); }
    ~PathObj();
};

bool __cdecl FUN_005f8210(PathObj* a, void* b);
bool __cdecl FUN_007af7b0(PathObj* a, float f, bool flag);

bool __cdecl FUN_005f89d0(PathObj* a0, Arg1* a1)
{
    TlsGuard guard(0x2d);
    if (!FUN_005f8210(a0, a1))
        return false;

    Object5fc430 savedRef(a0->m0c);
    FUN_005f14e0* p78 = new FUN_005f14e0();
    FUN_005f4550* p3c = new FUN_005f4550();
    PathObj tempObj(a0);

    a0->m108 = p3c;
    tempObj.m108 = p3c;
    a0->m104 = p78;
    tempObj.m104 = p78;

    unsigned int i = 1;
    while (a1->GetSize() > i) {
        Object5fc430 curRef(a1->GetAt(i).m04);
        tempObj.m34.FUN_005fc480(curRef);
        if (FUN_007af7b0(&tempObj, FUN_00dc31b4, true)) {
            Object5fc430 stepRef(&tempObj.posC8, curRef);
            tempObj.m34.FUN_005fc480(stepRef);
            Sub74 sub;
            bool ok = FUN_005f8210(&tempObj, &sub);
            if (ok) {
                a0->posC8 = tempObj.posC8;
                a0->m34.FUN_005fc480(stepRef);
                tempObj.m104 = 0;
                tempObj.m108 = 0;
                sub.FUN_00606430(a1);
                a0->be1 = true;
                return ok;
            }
        }
        ++i;
        savedRef = curRef;
    }

    tempObj.m104 = 0;
    tempObj.m108 = 0;
    delete p78;
    a0->m104 = 0;
    a0->be1 = true;
    return true;
}

}

// @f3 0x005fd570 (community match, verified in this file)
extern int DAT_00dc4dc0;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

namespace pathing_location_native {
namespace pathing_005fd570 {
struct Point { float x, y, z; };
struct Cell;
struct World {
    Cell* FUN_00501d90(unsigned int id);
};
struct RefObject {
    virtual void Slot0();
    virtual void DeleteThis();
    long volatile refCount;

    __forceinline void Release()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};
struct MeshForm {
    virtual void Slot0();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
};
struct Mesh : MeshForm, RefObject {
    unsigned short FUN_005beb00(const Point* point, int flags);
};
struct MeshRef {
    Mesh* pointer;
    MeshRef() : pointer(0) {}
    MeshRef(Mesh* p) : pointer(p) {}
    __forceinline ~MeshRef()
    {
        if (pointer)
            pointer->Release();
    }
    operator Mesh*() const { return pointer; }
    Mesh* operator->() const { return pointer; }
};
struct MeshInfo {
    unsigned int unk00, unk04, flags, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50;
    void* meshSource;
    bool Disabled() const { return (flags >> 4) & 1; }
};
__declspec(noalias) void __cdecl FUN_005b87d0(MeshRef* result, void* source);
}

class PathLoc5fd {
public:
    virtual void Slot0();
    pathing_005fd570::Point point;
    pathing_005fd570::MeshInfo* meshInfo;
    void* meshInfoArray;
    pathing_005fd570::Cell* cell;
    pathing_005fd570::World* world;
    unsigned int pathingFlags;
    unsigned short triangle;
    unsigned char flags;
    unsigned char unk27;

    __forceinline bool ResolveMesh(pathing_005fd570::MeshRef& result) const
    {
        if (meshInfo && !meshInfo->Disabled()) {
            pathing_005fd570::FUN_005b87d0(&result, meshInfo->meshSource);
            return result.pointer != 0;
        }
        return false;
    }
    void PathingLocation_SetupData(const pathing_005fd570::Point* p, pathing_005fd570::Cell* cell, pathing_005fd570::World* world);
};
}

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation, aHintLoc
f3m_005f0eb0::n5f0eb0::FUN_005fd570::FUN_005fd570(int pointArg, void* hintArg)
{
    using namespace pathing_location_native;
    using namespace pathing_005fd570;
    *reinterpret_cast<void**>(this) = &::DAT_00dc4dc0;
    PathLoc5fd* self = reinterpret_cast<PathLoc5fd*>(this);
    const Point* position = reinterpret_cast<const Point*>(pointArg);
    const PathLoc5fd* hint = static_cast<const PathLoc5fd*>(hintArg);
    self->point = *position;
    self->flags = 0;
    self->triangle = 0xffff;
    MeshRef mesh;
    if (hint->ResolveMesh(mesh)) {
        self->triangle = mesh.pointer->FUN_005beb00(position, 0);
        if (self->triangle != 0xffff) {
            self->meshInfo = hint->meshInfo;
            self->meshInfoArray = 0;
            self->cell = hint->cell;
            self->world = hint->world;
            self->pathingFlags = hint->pathingFlags;
            return;
        }
    }
    Cell* existingCell = hint->cell;
    World* existingWorld = hint->world;
    if (!existingCell) {
        if (!existingWorld || !(existingCell = existingWorld->FUN_00501d90(hint->pathingFlags)))
            existingCell = 0;
    }
    self->PathingLocation_SetupData(position, existingCell, existingWorld);
}

// @f3 0x005e8650 (community match, verified in this file)
namespace f3m_005e8650 {
extern long (__stdcall *DAT_00d9b064)(volatile long*);
extern long (__stdcall *DAT_00d9b068)(volatile long*);
extern unsigned long (__stdcall *DAT_00d9b070)();
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
extern int (__stdcall *DAT_00d9b084)(unsigned long, void*);

void* __cdecl FUN_0089eb90(unsigned int size);


namespace f3m_005e8650 {

struct RefObj {
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { DAT_00d9b068(&m_uiRefCount); }
    void DecRefCount() { if (DAT_00d9b064(&m_uiRefCount) == 0) DeleteThis(); }
};

struct hkBool {
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};

struct PhysObject {
    void FUN_0090ba10(int value);
    void FUN_0090b880(int value);
    hkBool FUN_0090b0e0();
};

struct PhysWrap {
    int unk00;
    int unk04;
    PhysObject* object;
};

struct Element {
    void* FUN_005b84c0();
};

struct Table5e53;
struct PtrArray;
struct Table5e53 { int unk00; void* (__thiscall *Allocate)(PtrArray*, unsigned); };
struct PtrArray {
    Table5e53* table;
    void** data;
    unsigned count;
    unsigned capacity;
    void FUN_00799ae0(unsigned newCapacity, unsigned oldCount);
    unsigned Add() {
        if (count == capacity) {
            if (!capacity) {
                data = (void**)table->Allocate(this, 4);
                capacity = 4;
            } else {
                unsigned grown = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_00799ae0(grown, count);
                capacity = grown;
            }
        }
        ++count;
        return count - 1;
    }
    void Append(void* const& value) { data[Add()] = value; }
};

struct Item : RefObj {
    int unk08;
    PhysWrap* wrap;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54;
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
    int unk70;
    bool split;
    PtrArray children;
    PhysWrap* GetWrap() { return wrap; }
};

struct ItemList {
    void* vtbl;
    Item** data;
    unsigned count;
    unsigned capacity;
    Item*& GetAt(unsigned index) { return data[index]; }
};

struct Entry : RefObj {
    const char* name;
    ItemList list;
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    Entry();
};

struct Record {
    int unk00;
    int unk04;
    int unk08;
    const char* name;
    const char* GetName() { return name; }
};

struct NameMap {
    void* vtbl;
    unsigned hashSize;
    void* table;
    unsigned itemCount;
    bool GetAt(const char* key, NiPointer<Entry>& result);
    void SetAt(const char* key, NiPointer<Entry> value);
};

struct ItemMap {
    void* vtbl;
    unsigned hashSize;
    void* table;
    unsigned itemCount;
    void SetAt(PhysWrap* key, NiPointer<Item> value);
};

struct WrapRef { PhysWrap* p; WrapRef(PhysWrap* x) : p(x) {} };
struct Worker {
    PhysWrap* last;
    __declspec(noinline) void FUN_005e5070(const WrapRef& wrap) { last = wrap.p; }
};

struct ThreadSlot {
    unsigned long threadId;
    Worker* worker;
};

struct ThreadPool {
    unsigned maxCount;
    unsigned long tlsIndex;
    ThreadSlot* slots;
    long used;
    unsigned long GetIndex() { return tlsIndex; }
};

struct WorkerFactory {
    virtual void V00();
    virtual Worker* Create(unsigned index);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ThreadPool* pool;
    __forceinline Worker* Get() {
        ThreadPool* p = pool;
        Worker* worker = (Worker*)DAT_00d9b080(p->tlsIndex);
        if (!worker) {
            Worker* created = 0;
            unsigned index = DAT_00d9b068(&p->used) - 1;
            if (index < p->maxCount) {
                created = Create(index);
                p->slots[index].worker = created;
                p->slots[index].threadId = DAT_00d9b070();
                DAT_00d9b084(p->GetIndex(), created);
            }
            worker = created;
        }
        return worker;
    }
    __forceinline void SubmitItem(NiPointer<Item>& item) {
        unsigned long idx;
        WrapRef r(*(PhysWrap* volatile*)&item->wrap);
        ThreadPool* p = pool;
        idx = p->tlsIndex;
        Worker* worker = (Worker*)DAT_00d9b080(idx);
        if (!worker) {
            Worker* created = 0;
            unsigned index = DAT_00d9b068(&p->used) - 1;
            if (index < p->maxCount) {
                created = Create(index);
                p->slots[index].worker = created;
                p->slots[index].threadId = DAT_00d9b070();
                DAT_00d9b084(p->GetIndex(), created);
            }
            worker = created;
        }
        worker->FUN_005e5070(r);
    }
};

struct Target {
    void FUN_005ea490(NiPointer<Item>* item, int flags);
};

struct LocalArray {
    void* vtbl;
    Element** data;
    unsigned count;
    unsigned capacity;
    void* allocator;
    LocalArray();
    Element* GetAt(unsigned index) { return data[index]; }
    ~LocalArray();
};

void __cdecl FUN_005e7470(Record* record, NiPointer<Entry>& entry);
void __cdecl FUN_005e45a0(NiPointer<Item>* item);
bool __cdecl FUN_005e7120(NiPointer<Item>* item, LocalArray* out);

inline void ApplyA(PhysWrap* wrap, int value) {
    if (wrap && wrap->object)
        wrap->object->FUN_0090ba10(value);
}

inline void ApplyB(PhysWrap* wrap, int value) {
    if (wrap && wrap->object)
        wrap->object->FUN_0090b880(value);
}

inline bool IsActive(PhysWrap* wrap) {
    if (!wrap || !wrap->object)
        return false;
    return wrap->object->FUN_0090b0e0();
}

struct Owner {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18;
    NameMap entries;
    int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40;
    WorkerFactory workers;
    int unk5C; int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78;
    ItemMap items;
    int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8;
    int unkBC;
    int unkC0;
    int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134;
    bool unk138;
    void FUN_005e4b90(NiPointer<Item>* item);
    Target* FUN_005e4ce0(void* key);
    void FUN_005e8650(Record* record);
};

// pdb: NavMeshObstacleManager::ReallyAddObstaclesForReference | NavMeshObstacleManager.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRef
void Owner::FUN_005e8650(Record* record)
{
    NiPointer<Entry> entry;
    if (!entries.GetAt(record->GetName(), entry)) {
        entry = new Entry;
        entry->name = record->GetName();
        FUN_005e7470(record, entry);
        entries.SetAt(record->GetName(), entry);
    }
    for (unsigned i = 0; i < entry->list.count; i++) {
        NiPointer<Item> item = entry->list.GetAt(i);
        items.SetAt(item->GetWrap(), item);
        PhysWrap* wrap = item->wrap;
        ApplyA(wrap, unkBC);
        ApplyB(wrap, unkC0);
        if (IsActive(item->wrap))
            workers.SubmitItem(item);
        FUN_005e45a0(&item);
        if (unk138)
            FUN_005e4b90(&item);
        if (item->split) {
            LocalArray parts;
            if (FUN_005e7120(&item, &parts)) {
                for (unsigned j = 0; j < parts.count; j++) {
                    FUN_005e4ce0(parts.GetAt(j)->FUN_005b84c0())->FUN_005ea490(&item, 0x10);
                    item->children.Append(parts.GetAt(j)->FUN_005b84c0());
                }
            }
        }
    }
}

}

}   // namespace f3m_005e8650

// @f3 0x005f5eb0 (community match, verified in this file)
#include <windows.h>
#include <float.h>
template<> class BSSimpleArray<TESObjectCELL*,1024>;
namespace S005f5eb0_ns {
extern void (__thiscall* const DAT_00e01cec)(::BSSimpleArray<TESObjectCELL*,1024>*,void*);
}
template<> class BSSimpleArray<TESObjectCELL*,1024> {
public:
    virtual ~BSSimpleArray(){if(data){S005f5eb0_ns::DAT_00e01cec(this,data);data=0;capacity=0;count=0;}}
    TESObjectCELL** data;
    unsigned count,capacity;
    BSSimpleArray():data(0),count(0),capacity(0){}
    unsigned FUN_005e5350();
    void Add(void* p){data[FUN_005e5350()]=(TESObjectCELL*)p;}
};

namespace S005f5eb0_ns {
extern const double DAT_00db8d70;
struct Vec3 { float x, y, z; Vec3() {} Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {} };
struct Ref { virtual void v00(); virtual void destroy(); long refs; void IncRefCount(){InterlockedIncrement(&refs);} void DecRefCount(){if(!InterlockedDecrement(&refs))destroy();} };
struct Cell;
struct FormBase {virtual void form00();unsigned unk04,unk08,unk0c,unk10,unk14,unk18;};
struct NavMesh : FormBase, Ref {
    // Fake match: noalias exposes the verified read-only getter's effect without exposing its body to register analysis.
    __declspec(noalias) struct Info* FUN_005b84c0();
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    Info* unk104;
    Cell* FUN_005b8480();
    bool FUN_005bcc40(Vec3* a, Vec3* b);
};
typedef ::NiPointer<NavMesh> NavPtr;
// Fake match: this ABI-compatible owner stand-in keeps the existing out-of-line destructor call.
struct NavPtrOut {
    NavMesh* m_pObject;
    NavPtrOut() : m_pObject(0) {}
    ~NavPtrOut() { FUN_0040eb10(); }
    void FUN_0040eb10();
    const NavPtr& Get() const { return *reinterpret_cast<const NavPtr*>(this); }
};
// Fake match: noinline retains the real assignment helper as a call while exposing its ownership behavior.
__declspec(noinline) void __cdecl FUN_005b87d0(NavPtr* out, NavMesh* mesh){NavPtr temporary(mesh);*out=temporary;}
struct Entry {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c,
        unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    NavMesh* unk54;
    bool IsBusy() const { return (unk08 >> 4) & 1; }
    bool GetNavMesh(NavPtr& out) const {
        if (IsBusy()) return false;
        FUN_005b87d0(&out, unk54);
        return out.m_pObject != 0;
    }
};
struct EntryArray {
    void* vtable; Entry** data; unsigned count; unsigned capacity;
    unsigned GetSize() const { return count; }
    Entry*& GetAt(unsigned i) { return data[i]; }
};
struct Info {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    EntryArray a;
    EntryArray b;
};
struct Registry { unsigned unk00, unk04; unsigned size; unsigned GetSize() const {return size;} NavPtr FUN_0043c300(unsigned); };
struct World;
struct Cell {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char flags;
    int TESObjectCELL_GetDataX();
    int TESObjectCELL_GetDataY();
    World* FUN_004d3780();
    Registry* FUN_007e55b0();
    bool SameWorld(Cell* other) {
        if (other->flags & 1)
            return this == other;
        return FUN_004d3780() == other->FUN_004d3780();
    }
};
struct World { Cell* TESWorldSpace_GetCellFromCellCoord(int x, int y); };
struct Sink {
    void* vtable;
    NavPtr* data;
    unsigned count;
    unsigned FUN_005e5350();
    // Fake match: noinline preserves the append call; its complete owning-pointer implementation enables escape analysis.
    __declspec(noinline) unsigned FUN_0041a4b0(const NavPtr& p) {unsigned i=FUN_005e5350();new (data+i) NavPtr;data[i]=p;return i;}
    int Find(const NavPtr& p) {
        for (unsigned i = 0; i < count; i++)
            if (data && data[i].m_pObject == p.m_pObject) return i;
        return -1;
    }
};
struct Location {
    void* vtable;
    Vec3 pos;
    Cell* PathingLocation_GetCell();
    bool FUN_005fda30(int);
    bool FUN_005fc8b0(NavPtrOut* out);
    bool AddNavMesh(struct Sink* sink);
};
// Fake match: forceinline retains the connected-location branch inside the target function.
__forceinline bool Location::AddNavMesh(Sink* sink) {
    NavPtrOut tmp;
    if (!FUN_005fc8b0(&tmp))
        return false;
    sink->FUN_0041a4b0(tmp.Get());
    return true;
}
typedef ::BSSimpleArray<TESObjectCELL*,1024> CellArray;
bool __cdecl FUN_005f1280(Vec3* a, Vec3* b, Vec3* c, Vec3* d);

// pdb: Pathing::FindNavmeshesForLocation | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation, afRadius, apRetNavMeshes, abConnected
bool __cdecl FUN_005f5eb0(Location* loc, float radius, Sink* sink, bool useLoc)
{
    Vec3 pos = loc->pos;
    Cell* cell = loc->PathingLocation_GetCell();
    if (!cell)
        return false;
    float minX = pos.x - radius;
    float minY = pos.y - radius;
    Vec3 lo(minX, minY, -FLT_MAX);
    float maxX = pos.x + radius;
    float maxY = pos.y + radius;
    Vec3 hi(maxX, maxY, FLT_MAX);
    Vec3 cmin;
    if (!useLoc) {
        CellArray cells;
        if (!(cell->flags & 1)) {
            for (int x = cell->TESObjectCELL_GetDataX() - 1; x < cell->TESObjectCELL_GetDataX() + 2; x++) {
                for (int y = cell->TESObjectCELL_GetDataY() - 1; y < cell->TESObjectCELL_GetDataY() + 2; y++) {
                    cmin.x = (float)(x << 12);
                    cmin.y = (float)(y << 12);
                    pos.x = (float)(x << 12) + 4096.0;
                    pos.y = (float)(y << 12) + 4096.0;
                    if (!(minX >= pos.x || maxX <= cmin.x || minY >= pos.y || maxY <= cmin.y))
                        cells.Add(cell->FUN_004d3780()->TESWorldSpace_GetCellFromCellCoord(x, y));
                }
            }
        } else {
            cells.Add(loc->PathingLocation_GetCell());
        }
        if (cells.count == 0)
            return false;
        for (unsigned i = 0; i < cells.count; i++) {
            Cell* c = (Cell*)cells.data[i];
            if (c && c->FUN_007e55b0()) {
                for (unsigned j = 0; j < c->FUN_007e55b0()->GetSize(); j++)
                    sink->FUN_0041a4b0(c->FUN_007e55b0()->FUN_0043c300(j));
            }
        }
    } else {
        if (!loc->FUN_005fda30(0) || !loc->AddNavMesh(sink))
            return false;
    }
    if (sink->count == 0)
        return false;
    for (unsigned i = 0; i < sink->count; i++) {
        NavPtr mesh = sink->data[i];
        unsigned n1 = mesh->FUN_005b84c0()->a.GetSize();
        unsigned bsz = mesh->FUN_005b84c0()->b.GetSize();
        unsigned k = 0;
        unsigned total = bsz + n1;
        if (total) { do {
            Entry* e = k < n1 ? mesh->FUN_005b84c0()->a.GetAt(k) : mesh->FUN_005b84c0()->b.GetAt(k - n1);
            if (e) {
                NavPtr nm;
                if (e->GetNavMesh(nm)) {
                    if (sink->Find(nm) != -1)
                        continue;
                    Cell* nc = nm->FUN_005b8480();
                    if (!nc)
                        continue;
                    if (cell->flags & 1) {
                        if (nc != cell)
                            continue;
                    } else if (cell->FUN_004d3780() != nc->FUN_004d3780()) {
                        continue;
                    }
                    {
                        Vec3 a;
                        if (nm->FUN_005bcc40(&a, &cmin) && FUN_005f1280(&a, &cmin, &lo, &hi))
                            sink->FUN_0041a4b0(nm);
                    }
                }
            }
        } while (++k < total); }
    }
    return true;
}
}

// @f3 0x005f9620 (community match, verified in this file)
#include <windows.h>
#include <float.h>

namespace match_005f9620 {

struct Point {
    float x, y, z;
    Point() {}
    Point(float a, float b, float c) : x(a), y(b), z(c) {}
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    // The components are copied to float locals first: the squares then keep the source order
    // (x, y, z) and the three differences get the original's stack slots.
    float SqrLength() const {
        float fx = x;
        float fy = y;
        float fz = z;
        return fx * fx + fy * fy + fz * fz;
    }
};

struct EdgeLocation {
    void* info;
    unsigned short triangle;
    unsigned short unk06;
    int edge;
    Point point;
};

struct NavMesh;

struct RefBlock {
    void** table;
    long refs;
    void Release() {
        if (InterlockedDecrement(&refs) == 0)
            ((void (__thiscall*)(RefBlock*))table[1])(this);
    }
};

struct NavTriangle {
    unsigned short vertices[3];
    unsigned short neighbours[3];
    unsigned int flags;
};

struct MeshEdge {
    NavMesh* mesh;
    unsigned short triangle;
    int edge;
    MeshEdge() {}
    MeshEdge(NavMesh* m, unsigned short t, int e) : mesh(m), triangle(t), edge(e) {}
    MeshEdge& operator=(const MeshEdge& o) { mesh = o.mesh; triangle = o.triangle; edge = o.edge; return *this; }
};

struct MeshTriangle {
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short unk06;
};

struct NavMesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    RefBlock ref1c;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
    NavTriangle* triangles;
    void FUN_005b8960(unsigned short triangle, int edge, Point& first, Point& second);
    bool FUN_005b8b80(const MeshEdge* edge, MeshEdge* adjacent);
    void* FUN_005b84c0();
};

struct NavPtr {
    NavMesh* mesh;
    NavPtr() : mesh(0) {}
    ~NavPtr() { if (mesh) mesh->ref1c.Release(); }
};

struct PathingLocation {
    void* table;
    Point position;
    Point GetPosition() const { return position; }
    void FUN_005fda30(int);
    bool FUN_005fc750();
    bool FUN_005fc8f0(NavPtr& mesh, unsigned short& triangle);
};

extern void* DAT_00e01ec4;
extern void* DAT_00e020c4;
extern void* DAT_00e00d2c;
struct ResultArray;
struct CandidateArray;
struct BoundaryArray;
extern void (__thiscall* DAT_00e01ecc)(ResultArray*, void*);
extern void (__thiscall* DAT_00e020cc)(CandidateArray*, void*);
extern void (__thiscall* DAT_00e00d34)(BoundaryArray*, void*);

struct ResultArray {
    void* table;
    EdgeLocation* data;
    unsigned int size;
    unsigned int capacity;
    ResultArray() : table(&DAT_00e01ec4), data(0), size(0), capacity(0) {}
    ~ResultArray() {
        table = &DAT_00e01ec4;
        if (data) {
            DAT_00e01ecc(this, data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
};

struct CrossFlags {
    bool e[3];
    bool& operator[](int i) { return e[i]; }
};

struct TriangleCandidate {
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short unk06;
    CrossFlags crossed;
    TriangleCandidate() {}
    TriangleCandidate(const TriangleCandidate& o) : mesh(o.mesh), triangle(o.triangle), crossed(o.crossed) {}
    TriangleCandidate& operator=(const TriangleCandidate& o) { mesh = o.mesh; triangle = o.triangle; crossed = o.crossed; return *this; }
};

struct CandidateArray {
    void** table;
    TriangleCandidate* data;
    unsigned int size;
    unsigned int capacity;
    CandidateArray() : table((void**)&DAT_00e020c4), data(0), size(0), capacity(0) {}
    ~CandidateArray() {
        table = (void**)&DAT_00e020c4;
        if (data) {
            DAT_00e020cc(this, data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    unsigned int FUN_007a1650();
    void Set(unsigned int i, const TriangleCandidate& v) { data[i] = v; }
    __forceinline void Add(const TriangleCandidate& value) {
        if (size == capacity) {
            unsigned int newCapacity;
            if (capacity == 0) {
                data = ((TriangleCandidate* (__thiscall*)(CandidateArray*, unsigned int))table[1])(this, 4);
                capacity = 4;
            } else {
                newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                    data = ((TriangleCandidate* (__thiscall*)(CandidateArray*, TriangleCandidate*, unsigned int))table[3])(this, data, newCapacity);
                else
                    data = ((TriangleCandidate* (__thiscall*)(CandidateArray*, unsigned int))table[1])(this, newCapacity);
                capacity = newCapacity;
            }
        }
        ++size;
        Set(size - 1, value);
    }
};

struct BoundaryArray {
    void** table;
    MeshEdge* data;
    unsigned int size;
    unsigned int capacity;
    BoundaryArray() : table((void**)&DAT_00e00d2c), data(0), size(0), capacity(0) {}
    ~BoundaryArray() {
        table = (void**)&DAT_00e00d2c;
        if (data) {
            DAT_00e00d34(this, data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    void FUN_0079ecc0(unsigned int newCapacity, unsigned int moveCount);
    void Set(unsigned int i, const MeshEdge& v) { data[i] = v; }
    __forceinline void Add(const MeshEdge& value) {
        if (size == capacity) {
            if (capacity == 0) {
                data = ((MeshEdge* (__thiscall*)(BoundaryArray*, unsigned int))table[1])(this, 4);
                capacity = 4;
            } else {
                unsigned int newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_0079ecc0(newCapacity, size);
                capacity = newCapacity;
            }
        }
        ++size;
        Set(size - 1, value);
    }
};

void __cdecl FUN_005f90b0(PathingLocation*, int, ResultArray*);
float __cdecl FUN_005dce20(const Point&, const Point&, const Point&, bool);
void __cdecl FUN_005dd040(Point*, const Point&, const Point&, const Point&);

// pdb: Pathing::FindClosestOpenEdge | Pathfind.obj | fnv360_0822_retail, objrun, medium
// pdb params: aLocation, afMaxRadius, aRetEdge
bool __cdecl FUN_005f9620(PathingLocation* location, float radius, EdgeLocation* result)
{
    location->FUN_005fda30(0);
    if (!location->FUN_005fc750()) {
        ResultArray locations;
        FUN_005f90b0(location, 1, &locations);
        if (locations.size) {
            EdgeLocation* first = locations.data;
            result->info = first->info;
            result->triangle = first->triangle;
            result->edge = first->edge;
            result->point = first->point;
            return true;
        }
        return false;
    }

    BoundaryArray boundaries;
    CandidateArray candidates;
    NavPtr navMesh;
    unsigned short triangle;
    if (!location->FUN_005fc8f0(navMesh, triangle))
        return false;

    TriangleCandidate first;
    first.mesh = navMesh.mesh;
    first.triangle = triangle;
    for (int edge = 0; edge < 3; ++edge) {
        Point begin, end;
        navMesh.mesh->FUN_005b8960(triangle, edge, begin, end);
        first.crossed[edge] = FUN_005dce20(location->GetPosition(), begin, end, false) < radius;
    }
    candidates.data[candidates.FUN_007a1650()] = first;

    for (unsigned int candidateIndex = 0; candidateIndex < candidates.size; ++candidateIndex) {
        TriangleCandidate candidate = candidates.data[candidateIndex];
        for (int edge = 0; edge < 3; ++edge) {
            if (!candidate.crossed[edge])
                continue;
            NavTriangle& tri = candidate.mesh->triangles[candidate.triangle];
            MeshEdge edgeSource(candidate.mesh, candidate.triangle, edge);
            unsigned short neighbour = tri.neighbours[edge];
            if (neighbour == 0xffff) {
                boundaries.Add(edgeSource);
                continue;
            }
            MeshEdge adjacent;
            if (!candidate.mesh->FUN_005b8b80(&edgeSource, &adjacent))
                continue;
            bool found = false;
            for (unsigned int i = 0; i < candidates.size; ++i) {
                if (candidates.data[i].mesh == adjacent.mesh &&
                    candidates.data[i].triangle == adjacent.triangle) {
                    found = true;
                    break;
                }
            }
            if (found)
                continue;
            TriangleCandidate next;
            next.mesh = adjacent.mesh;
            next.triangle = adjacent.triangle;
            for (int nextEdge = 0; nextEdge < 3; ++nextEdge) {
                Point begin, end;
                adjacent.mesh->FUN_005b8960(adjacent.triangle, nextEdge, begin, end);
                next.crossed[nextEdge] = FUN_005dce20(location->GetPosition(), begin, end, false) < radius;
            }
            candidates.Add(next);
        }
    }

    if (boundaries.size) {

        float closestDistance = FLT_MAX;
        MeshEdge closest;
        Point closestPoint;
        for (unsigned int i = 0; i < boundaries.size; ++i) {
            Point begin, end, point;
            // The array base is read once into a local: it decides the base/index order of the element addresses.
            MeshEdge* data = boundaries.data;
            data[i].mesh->FUN_005b8960(data[i].triangle, data[i].edge, begin, end);
            FUN_005dd040(&point, location->GetPosition(), begin, end);
            float distance = (point - location->GetPosition()).SqrLength();
            if (distance < closestDistance) {
                closestDistance = distance;
                closest = boundaries.data[i];
                closestPoint = point;
            }
        }

        result->info = closest.mesh->FUN_005b84c0();
        result->triangle = closest.triangle;
        result->edge = closest.edge;
        result->point = closestPoint;
        return true;
    }
    return false;
}

}

// @f3 0x005ffe50 (community match, verified in this file)
namespace f3m_005ffe50 {
namespace ns_5ffe50 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct Counter {
    void** table;
    long refs;
    void Release() { if (!InterlockedDecrement(&refs)) ((void (__thiscall*)(Counter*))table[1])(this); }
};
struct Key {
    int unk00, unk04, unk08;
    unsigned int id;
    int unk10, unk14, unk18;
    Counter counter;
    unsigned int GetID() const { return id; }
    void IncRefCount() { InterlockedIncrement(&counter.refs); }
    void DecRefCount() { counter.Release(); }
};
struct Map {
    int unk00, unk04, unk08, unk0c;
    bool FUN_00bea7b0(unsigned int key, unsigned int* value);
};
struct Track {
    int unk00, unk04;
    Map map;
    int unk18, unk1c;
    NiPointer<Key>* keys;
    unsigned int count;
    bool FUN_005ffe50(unsigned int time, NiPointer<Key>* out, unsigned short* offset);
};

// pdb: PathingLOSMap::GetNavMeshAndTriangleForIndex | PathingLOSMap.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aiIndex, aRetNavMesh, aRetTriangle
bool Track::FUN_005ffe50(unsigned int time, NiPointer<Key>* out, unsigned short* offset)
{
    if (!count)
        return false;
    unsigned int previous = 0;
    unsigned int i = 0;
    unsigned int start;
    for (; i < count; i++) {
        if (!map.FUN_00bea7b0(keys[i]->GetID(), &start))
            return false;
        if (start > time) {
            *offset = (unsigned short)(time - previous);
            *out = keys[i - 1];
            return true;
        }
        previous = start;
    }
    *offset = (unsigned short)(time - previous);
    *out = keys[i - 1];
    return true;
}
}
}   // namespace f3m_005ffe50

// @f3 0x005e12c0 (community match, verified in this file)
extern int DAT_00db72c8;
namespace f3m_005e12c0 {
namespace f3m_005e12c0 {
using f3m_005e2a10::NiRefObject;
using f3m_005e2a10::ObstacleData;
using f3m_005e2a10::SimpleArray;
using f3m_005e2a10::TriangleObstacleMap;
using f3m_005e2a10::NavMesh;

struct S5e12c0_IndexArray;
extern void (__thiscall* DAT_00db72d0)(S5e12c0_IndexArray*, unsigned*);
struct S5e12c0_IndexArray {
    void* table; unsigned* data; unsigned count; unsigned capacity;
    S5e12c0_IndexArray() : table(&DAT_00db72c8), data(0), count(0), capacity(0) {}
    ~S5e12c0_IndexArray() { table = &DAT_00db72c8; if (data) { DAT_00db72d0(this, data); data = 0; capacity = 0; count = 0; } }
    unsigned FUN_005e5350();
    __forceinline unsigned Find(unsigned v) { for (unsigned i = 0; i < count; i++) { if (data && data[i] == v) return i; } return (unsigned)-1; }
    __forceinline void AddUnique(unsigned v) { if (Find(v) == (unsigned)-1) { unsigned n = ((::f3m_005e5350::Match5e53::Owner5e53*)this)->FUN_005e5350(); data[n] = v; } }
};

struct NavMeshTriangle {
    unsigned short sVertex0;
    unsigned short sVertex1;
    unsigned short sVertex2;
    unsigned short sTriangle[3];
    unsigned int TriangleFlags;
    void SetFlag(unsigned int a_uiFlag) { TriangleFlags |= a_uiFlag; }
    void ClearFlag(unsigned int a_uiFlag) { TriangleFlags &= ~a_uiFlag; }
    void SetEdgeFlag(int a_iEdge, bool a_bSet) { if (a_bSet) TriangleFlags |= 1 << a_iEdge; else TriangleFlags &= ~(1 << a_iEdge); }
};

struct S5e12c0_PortalKey {
    void* pNavMesh;
    unsigned short usTriangle;
    unsigned int uiEdge;
    S5e12c0_PortalKey() {}
    S5e12c0_PortalKey(const S5e12c0_PortalKey& o) : pNavMesh(o.pNavMesh), usTriangle(o.usTriangle), uiEdge(o.uiEdge) {}
    S5e12c0_PortalKey& operator=(const S5e12c0_PortalKey& o) { pNavMesh = o.pNavMesh; usTriangle = o.usTriangle; uiEdge = o.uiEdge; return *this; }
    bool operator==(const S5e12c0_PortalKey& o) const { return pNavMesh == o.pNavMesh && usTriangle == o.usTriangle && uiEdge == o.uiEdge; }
};

struct S5e12c0_PortalEdgeSwap {
    S5e12c0_PortalKey Old;
    S5e12c0_PortalKey New;
    int unk18;
};

class S5e12c0_KeyArray : public SimpleArray<S5e12c0_PortalKey> {
public:
    void FUN_0079ecc0(unsigned int a_iNewSize, unsigned int a_iMoveCount);
    unsigned FUN_007a1650() {
        if (iSize == iReservedSize) {
            if (!iReservedSize) { pBuffer = _Allocate(4); iReservedSize = 4; }
            else { unsigned n = iReservedSize > 0x400 ? iReservedSize + 0x400 : iReservedSize * 2; FUN_0079ecc0(n, iSize); iReservedSize = n; }
        }
        ++iSize;
        return iSize - 1;
    }
    __forceinline unsigned Find(const S5e12c0_PortalKey& k) {
        for (unsigned i = 0; i < iSize; i++) { if (pBuffer && pBuffer[i] == k) return i; }
        return (unsigned)-1;
    }
    __forceinline void AddUnique(const S5e12c0_PortalKey& k) {
        if (Find(k) == (unsigned)-1) { unsigned n = FUN_007a1650(); pBuffer[n] = k; }
    }
};

struct S5e12c0_TaskPortalSwap {
    S5e12c0_KeyArray Removed;
    S5e12c0_KeyArray Added;
    void FUN_005df840(unsigned int a_uiIndex, bool a_bFlag);
};

struct S5e12c0_BoundsTriangleInfo {
    unsigned short usTriangle;
    unsigned char bEdge[3];
    unsigned char unk05;
    unsigned short usLink[3];
};

class S5e12c0_RemovedMap : public TriangleObstacleMap {
public:
    __forceinline void* GetFirstPos() const {
        for (unsigned int i = 0; i < m_uiHashSize; i++) { if (m_ppkHashTable[i]) return m_ppkHashTable[i]; }
        return 0;
    }
    __declspec(noinline) void FUN_005bb560(void** a_pPos, unsigned short* a_pKey, NiPointer<ObstacleData>* a_pVal) const
    {
        f3m_005e2a10::MapItem* pkItem = (f3m_005e2a10::MapItem*)*a_pPos;
        *a_pKey = pkItem->m_key;
        *a_pVal = pkItem->m_val;
        f3m_005e2a10::MapItem* pkNext = pkItem->m_pkNext;
        if (pkNext)
        {
            *a_pPos = pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkNext = m_ppkHashTable[i];
            if (pkNext)
            {
                *a_pPos = pkNext;
                return;
            }
        }
        *a_pPos = 0;
    }
};

class S5e12c0_UndoData : public NiRefObject {
public:
    int eState;
    NiPointer<ObstacleData> spObstacle;
    unsigned int iFirstAddedVertexIndex;
    unsigned int iAddedVertexCount;
    unsigned int iFirstAddedTriangleIndex;
    unsigned int iAddedTriangleCount;
    SimpleArray<unsigned short> OverlappedTriangles;
    SimpleArray<S5e12c0_BoundsTriangleInfo> BoundsTriangles;
    S5e12c0_RemovedMap RemovedTriangleToObstacleMap;
    SimpleArray<S5e12c0_PortalEdgeSwap> EdgeSwap;
};

__forceinline NavMeshTriangle* GetTri(NavMesh* a_pNavMesh, unsigned short a_usIndex) { return (NavMeshTriangle*)a_pNavMesh->GetTriangle(a_usIndex); }

int __cdecl FUN_0079e5b0(const void*, const void*);
void __cdecl FUN_00c011c0(void* base, unsigned int count, unsigned int elemSize, int (__cdecl* compare)(const void*, const void*));

class S5e12c0_Cutter {
public:
    NavMesh* pNavMesh;
    NiPointer<ObstacleData> spObstacle;
    S5e12c0_UndoData* pUndoData;
    void FUN_005dfa80();
    bool FUN_005e12c0(NavMesh* a_pNavMesh, S5e12c0_UndoData* a_pUndoData, S5e12c0_TaskPortalSwap& a_rPortalSwap);
};

// pdb: NavMeshObstacleCutter::UndoNavMeshFromObstacleUndoData | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
// pdb params: apNavMesh, apUndoData, aPortalSwaps
bool S5e12c0_Cutter::FUN_005e12c0(NavMesh* a_pNavMesh, S5e12c0_UndoData* a_pUndoData, S5e12c0_TaskPortalSwap& a_rPortalSwap)
{
    pNavMesh = a_pNavMesh;
    pUndoData = a_pUndoData;
    S5e12c0_IndexArray removed;

    for (unsigned int i = 0; i < pUndoData->EdgeSwap.GetSize(); i++)
    {
        S5e12c0_PortalEdgeSwap reverse;
        reverse.New = pUndoData->EdgeSwap[i].Old;
        reverse.Old = pUndoData->EdgeSwap[i].New;
        unsigned int idx = a_rPortalSwap.Removed.Find(reverse.Old);
        if (idx != (unsigned)-1)
            removed.AddUnique(idx);
        else
            a_rPortalSwap.Added.AddUnique(reverse.Old);
        a_rPortalSwap.Removed.AddUnique(reverse.New);
    }

    if (removed.count)
    {
        FUN_00c011c0(removed.data, removed.count, 4, FUN_0079e5b0);
        for (int i = removed.count - 1; i >= 0; i--)
            a_rPortalSwap.FUN_005df840(removed.data[i], true);
    }

    for (unsigned int i = 0; i < pUndoData->OverlappedTriangles.GetSize(); i++)
        GetTri(pNavMesh, pUndoData->OverlappedTriangles[i])->ClearFlag(0x20);

    for (unsigned int i = 0; i < pUndoData->BoundsTriangles.GetSize(); i++)
    {
        NavMeshTriangle* pTri = GetTri(pNavMesh, pUndoData->BoundsTriangles[i].usTriangle);
        pTri->ClearFlag(0x100);
        int j = 0;
        do
        {
            if (pUndoData->BoundsTriangles[i].bEdge[j]) {
                unsigned short link = pUndoData->BoundsTriangles[i].usLink[j];
                pTri->TriangleFlags |= 1 << j;
                pTri->sTriangle[j] = link;
            } else {
                unsigned short link = pUndoData->BoundsTriangles[i].usLink[j];
                pTri->TriangleFlags &= ~(1 << j);
                pTri->sTriangle[j] = link;
            }
        } while (++j < 3);
    }

    for (unsigned int i = pUndoData->iFirstAddedTriangleIndex; i < pUndoData->iFirstAddedTriangleIndex + pUndoData->iAddedTriangleCount; i++)
        GetTri(pNavMesh, (unsigned short)i)->SetFlag(0x20);

    for (unsigned int i = 0; i < pUndoData->BoundsTriangles.GetSize(); i++)
    {
        NavMeshTriangle* pTri = GetTri(pNavMesh, pUndoData->BoundsTriangles[i].usTriangle);
        unsigned short usCount = (unsigned short)(((pTri->TriangleFlags >> 13) & 7) - 1);
        if (usCount > 7)
            usCount = 7;
        pTri->TriangleFlags = (pTri->TriangleFlags & ~0xE000) | (usCount << 13);
    }

    for (unsigned int i = pUndoData->iFirstAddedTriangleIndex; i < pUndoData->iFirstAddedTriangleIndex + pUndoData->iAddedTriangleCount; i++)
        pNavMesh->pTriangleToObstacleMap->FUN_005df1f0(i);

    void* pos = pUndoData->RemovedTriangleToObstacleMap.GetFirstPos();
    while (pos)
    {
        unsigned short usTri;
        NiPointer<ObstacleData> spOld;
        pUndoData->RemovedTriangleToObstacleMap.FUN_005bb560(&pos, &usTri, &spOld);
        pNavMesh->pTriangleToObstacleMap->FUN_005bb420(usTri, spOld);
    }

    pNavMesh->FUN_005ba4e0();
    FUN_005dfa80();
    pUndoData->eState = 3;
    return true;
}
}
}   // namespace f3m_005e12c0

// @f3 0x005e7990 (community match, verified in this file)
namespace f3m_005e7990 {

struct S005e7990_Ref
{
    virtual ~S005e7990_Ref();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};

struct S005e7990_Item;

struct S005e7990_Array
{
    virtual ~S005e7990_Array();
    virtual S005e7990_Item** Allocate(unsigned count);
    virtual void Free(void* memory);
    S005e7990_Item** data;
    unsigned count;
    unsigned capacity;
    void FUN_00799ae0(unsigned newCapacity, unsigned oldCount);
    S005e7990_Item*& GetAt(unsigned index) { return data[index]; }
    void Clear()
    {
        if (data)
        {
            Free(data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
    void Add(S005e7990_Item* const& item)
    {
        if (count == capacity)
        {
            if (!capacity)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned newCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_00799ae0(newCapacity, count);
                capacity = newCapacity;
            }
        }
        ++count;
        data[count - 1] = item;
    }
};

struct S005e7990_Sub
{
    void hkpEntity_removeEntityActivationListener(int value);
    void FUN_0090b960(int value);
    void FUN_0090ba10(int value);
    void FUN_0090b880(int value);
};

struct S005e7990_Comp
{
    int unk00;
    int unk04;
    S005e7990_Sub* sub;
    S005e7990_Sub* Get() { return this ? sub : 0; }
    void Apply1(int value) { S005e7990_Sub* t = Get(); if (t) t->hkpEntity_removeEntityActivationListener(value); }
    void Apply2(int value) { S005e7990_Sub* t = Get(); if (t) t->FUN_0090b960(value); }
    void Remove1(int value) { S005e7990_Sub* t = Get(); if (t) t->FUN_0090ba10(value); }
    void Remove2(int value) { S005e7990_Sub* t = Get(); if (t) t->FUN_0090b880(value); }
};

struct S005e7990_Entry : S005e7990_Ref
{
    int unk08;
    S005e7990_Comp* comp;
    S005e7990_Comp* GetComp() { return comp; }
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    bool active;
    S005e7990_Array items;
    NiPointer<S005e7990_Ref> handle;
};

template <class T> struct SimpleArray
{
    virtual void v00();
    virtual void v04();
    virtual void* Free(void* p);
    T* data;
    unsigned int size;
    unsigned int capacity;
    T& GetAt(unsigned int i) { return data[i]; }
    unsigned int GetSize() const { return size; }
};

struct S005e7990_List : S005e7990_Ref
{
    int unk08;
    SimpleArray<NiPointer<S005e7990_Entry> > items;
};

struct S005e7990_Entry;
struct S005e7990_Result
{
    void FUN_005ea490(NiPointer<S005e7990_Entry>& entry, int type);
};

struct S005e7990_Source
{
    S005e7990_Item* FUN_005b84c0();
};

struct S005e7990_Allocator;
struct S005e7990_Heap
{
    S005e7990_Allocator* FUN_0086bcb0();
};
extern S005e7990_Heap DAT_01090a78;

struct S005e7990_NodePtr
{
    S005e7990_Source* ptr;
    S005e7990_Source* operator->() const { return ptr; }
    operator S005e7990_Source*() const { return ptr; }
};
struct S005e7990_ArrayBase
{
    void** table;
    S005e7990_NodePtr* data;
    unsigned count;
    unsigned capacity;
    S005e7990_ArrayBase() { data = 0; count = 0; capacity = 0; }
    ~S005e7990_ArrayBase();
    unsigned GetSize() const { return count; }
    S005e7990_NodePtr& GetAt(unsigned i) { return data[i]; }
};

struct FUN_005e7680 : S005e7990_ArrayBase
{
    S005e7990_Allocator* allocator;
    FUN_005e7680()
    {
        table = (void**)&DAT_00e01d68;
        allocator = DAT_01090a78.FUN_0086bcb0();
        data = 0;
        count = 0;
        capacity = 0;
    }
    ~FUN_005e7680();
};
typedef FUN_005e7680 S005e7990_TempArray;

struct S005e7990_Map
{
    __declspec(noalias) bool FUN_005c8b00(int key, NiPointer<S005e7990_List>& result);
};

struct S005e7990_Set
{
    void FUN_004c25a0(NiPointer<S005e7990_Entry>* entry);
};

struct S005e7990_Owner
{
    void FUN_00899cf0(S005e7990_Comp* comp);
};

struct S005e7990_Target
{
    void** table;
};

void __cdecl FUN_005e7470(int key, NiPointer<S005e7990_List>* list);
void __cdecl FUN_005e45a0(NiPointer<S005e7990_Entry>* entry);
bool __cdecl FUN_005e7120(NiPointer<S005e7990_Entry>* entry, S005e7990_TempArray* items);

struct S005e7990_Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    S005e7990_Map map;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    S005e7990_Set set;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    S005e7990_Owner owner;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    bool enabled;
    S005e7990_Target* target;
    S005e7990_Result* FUN_005e4ce0(S005e7990_Item* item);
    void Process(S005e7990_Comp* comp) { comp->Apply1(unkBC); comp->Apply2(unkC0); }
    void Unprocess(S005e7990_Comp* comp) { comp->Remove1(unkBC); comp->Remove2(unkC0); }
    void FUN_005e4b90(NiPointer<S005e7990_Entry>* entry);
    bool IsEnabled() const { return enabled; }
    S005e7990_Target* GetTarget() const { return target; }
    void FUN_005e7990(int key, int other);
};

// pdb: NavMeshObstacleManager::UpdateObstaclesForReference | NavMeshObstacleManager.obj | fnv360_0822_retail, objrun, medium
// pdb params: aiRefID, apRef
void S005e7990_Manager::FUN_005e7990(int key, int other)
{
    NiPointer<S005e7990_List> list;
    if (!map.FUN_005c8b00(key, list))
        return;
    for (unsigned i = 0; i < list->items.GetSize(); i++)
    {
        NiPointer<S005e7990_Entry> entry = list->items.GetAt(i);
        if (entry->active)
        {
            for (unsigned k = 0; k < entry->items.count; k++)
                FUN_005e4ce0(entry->items.GetAt(k))->FUN_005ea490(entry, 0x21);
            entry->items.Clear();
        }
        if (IsEnabled())
        {
            S005e7990_Target* t = target;
            if (t && entry->handle)
            {
                ((void(__thiscall*)(S005e7990_Target*, S005e7990_Ref*))t->table[58])(t, entry->handle);
                entry->handle = 0;
            }
        }
        Process(entry->GetComp());
        owner.FUN_00899cf0(entry->GetComp());
        set.FUN_004c25a0(&entry);
    }
    FUN_005e7470(other, &list);
    for (unsigned j = 0; j < list->items.GetSize(); j++)
    {
        NiPointer<S005e7990_Entry> entry = list->items.GetAt(j);
        FUN_005e45a0(&entry);
        if (entry->active)
        {
            S005e7990_TempArray sources;
            if (FUN_005e7120(&entry, &sources))
            {
                for (unsigned k = 0; k < sources.GetSize(); k++)
                {
                    FUN_005e4ce0(sources.GetAt(k)->FUN_005b84c0())->FUN_005ea490(entry, 0x11);
                    entry->items.Add(sources.GetAt(k)->FUN_005b84c0());
                }
            }
        }
        if (IsEnabled())
            FUN_005e4b90(&entry);
        Unprocess(entry->GetComp());
    }
}

}

// @f3 0x005f30c0 (community match, verified in this file)
extern int DAT_00dc4dc0;
extern const float DAT_00f725a4[3];
extern const float DAT_00f725b0[3];
extern const double DAT_00dcf570;
namespace f3m_005f30c0 {

namespace n_005f30c0 {

struct Point5f30 {
    float x, y, z;
    Point5f30() {}
    Point5f30(float a, float b, float c) : x(a), y(b), z(c) {}
    Point5f30(const Point5f30& other) : x(other.x), y(other.y), z(other.z) {}
    Point5f30 operator+(const Point5f30& other) const { return Point5f30(x + other.x, y + other.y, z + other.z); }
    Point5f30 operator-(const Point5f30& other) const { return Point5f30(x - other.x, y - other.y, z - other.z); }
    Point5f30 operator*(float scale) const { return Point5f30(x * scale, y * scale, z * scale); }
    float SquaredLength() const { return x * x + y * y + z * z; }
    __declspec(noalias) Point5f30 NiPoint3_UnitCross(const Point5f30& other) const;
};


struct Matrix5f30 {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void Z(float angle)
    {
        float sn, cs;
        fnv_SinCos(angle, sn, cs);
        m00 = cs;
        m01 = sn;
        m02 = 0;
        m10 = -sn;
        m11 = cs;
        m12 = 0;
        m20 = 0;
        m21 = 0;
        m22 = 1;
    }
    Point5f30 operator*(const Point5f30& p) const
    {
        return Point5f30(
            m00 * p.x + m01 * p.y + m02 * p.z,
            m10 * p.x + m11 * p.y + m12 * p.z,
            m20 * p.x + m21 * p.y + m22 * p.z);
    }
};

struct Location5f30 {
    void* table;
    Point5f30 position;
    void* info;
    void* infos;
    void* cell;
    void* world;
    unsigned int flags;
    unsigned short triangle;
    unsigned char bits;
    unsigned char flags2;
    void FUN_005fc3f0();
    Location5f30* FUN_005fc430(const Location5f30& other);
    void FUN_005fd570(const Point5f30& p, const Location5f30& context);
    Location5f30() { FUN_005fc3f0(); }
    Location5f30(const Location5f30& other) { FUN_005fc430(other); }
    Location5f30(const Point5f30& p, const Location5f30& context) { FUN_005fd570(p, context); }
    ~Location5f30() { table = &::DAT_00dc4dc0; }
};

bool __cdecl FUN_005f1970(Location5f30* from, Point5f30* to, void* resource, int index, Location5f30* result, void* filter);
unsigned char __cdecl FUN_005f25b0(Location5f30* from, Location5f30* to, Location5f30* result, void* filter);

} // namespace n_005f30c0

using namespace n_005f30c0;

// pdb: Pathing::ComputeFinalTangentForActor | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: afHeading, aLocation, afRadius
Point5f30 FUN_005f30c0(float angle, const Location5f30& context, float radius)
{
    Matrix5f30 rotation;
    rotation.Z(angle);
    Point5f30 direction = rotation * (*(const Point5f30*)DAT_00f725a4);
    Location5f30 base(context);
    Point5f30 origin;
    origin = base.position;
    direction = Point5f30((float)(direction.x * DAT_00dcf570), (float)(direction.y * DAT_00dcf570), (float)(direction.z * DAT_00dcf570));
    direction = base.position - direction;
    Point5f30 endpoint = direction;
    Location5f30 result;
    if (!FUN_005f1970(&base, &endpoint, 0, 65535, &result, 0))
        endpoint = result.position;
    Point5f30 displacement = endpoint - origin;
    Point5f30 offset = Point5f30(displacement).NiPoint3_UnitCross(*(const Point5f30*)DAT_00f725b0) * radius;
    Location5f30 minusStart(origin - offset, base);
    Location5f30 minusEnd(endpoint - offset, base);
    if (!FUN_005f25b0(&minusStart, &minusEnd, &result, 0)) {
        Point5f30 hit = result.position - minusStart.position;
        if (hit.SquaredLength() < displacement.SquaredLength())
            endpoint = result.position;
    }
    Location5f30 plusStart(origin + offset, base);
    Location5f30 plusEnd(endpoint + offset, base);
    if (!FUN_005f25b0(&plusStart, &plusEnd, &result, 0)) {
        Point5f30 hit = result.position - plusStart.position;
        if (hit.SquaredLength() < displacement.SquaredLength())
            endpoint = result.position;
    }
    return origin - endpoint;
}
}   // namespace f3m_005f30c0

// @f3 0x005f27d0 (community match, verified in this file)
extern const float DAT_00f725a4[3];
extern const float DAT_00f725b0[3];
extern const double DAT_00dcf570;
extern const double DAT_00dc8080;
extern const float DAT_00e02110;
namespace f3m_005f27d0 {
namespace f3m_005f27d0 {

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3 operator+(const Vec3& b) const { return Vec3(x + b.x, y + b.y, z + b.z); }
    Vec3 operator-(const Vec3& b) const { return Vec3(x - b.x, y - b.y, z - b.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator*(double s) const { return Vec3(float(x * s), float(y * s), float(z * s)); }
    Vec3& operator+=(const Vec3& b) { x += b.x; y += b.y; z += b.z; return *this; }
    Vec3& operator-=(const Vec3& b) { x -= b.x; y -= b.y; z -= b.z; return *this; }
    float SquareLength() const { return x * x + y * y + z * z; }
    Vec3 NiPoint3_UnitCross(const Vec3& b) const;
    float NiPoint3_UnitizeGetLength();
    float Dot(const Vec3& b) const { return x * b.x + y * b.y + z * b.z; }
};

struct PathPoint {
    virtual ~PathPoint() {}
    Vec3 position;
    const Vec3& GetLocation() const { return position; }
    unsigned unk10, unk14, unk18, unk1c, unk20;
    unsigned short unk24;
    unsigned char unk26, unk27;
    PathPoint();
    PathPoint(const PathPoint&);
    PathPoint(const Vec3&, const PathPoint&);
};

bool __cdecl FUN_005f1970(const PathPoint*, Vec3*, unsigned, unsigned, PathPoint*, unsigned);
bool __cdecl FUN_005f25b0(const PathPoint*, const PathPoint*, PathPoint*, unsigned);

struct Matrix3 {
    float m_pEntry[3][3];
    Matrix3() {}
    void MakeZRotation(float angle) {
        float s, c;
        fnv_SinCos(angle, s, c);
        m_pEntry[0][0] = c;  m_pEntry[0][1] = s; m_pEntry[0][2] = 0.0f;
        m_pEntry[1][0] = -s; m_pEntry[1][1] = c; m_pEntry[1][2] = 0.0f;
        m_pEntry[2][0] = 0.0f; m_pEntry[2][1] = 0.0f; m_pEntry[2][2] = 1.0f;
    }
    static Matrix3 FromZ(float angle) { Matrix3 m; m.MakeZRotation(angle); return m; }
    Matrix3(float angle) { MakeZRotation(angle); }
    Vec3 operator*(const Vec3& v) const {
        return Vec3(
            m_pEntry[0][0] * v.x + m_pEntry[0][1] * v.y + m_pEntry[0][2] * v.z,
            m_pEntry[1][0] * v.x + m_pEntry[1][1] * v.y + m_pEntry[1][2] * v.z,
            m_pEntry[2][0] * v.x + m_pEntry[2][1] * v.y + m_pEntry[2][2] * v.z);
    }
};
}

// pdb: Pathing::ComputeInitialTangentForActor | Pathfind.obj | fnv360_0822_retail, uconst, low, conflict (skyrim: BSPathing::ComputeInitialTangentForActor)
// pdb params: afHeading, aLocation, aNextLocation, afRadius
f3m_005f27d0::Vec3 __cdecl FUN_005f27d0(float angle, const f3m_005f27d0::PathPoint& first, const f3m_005f27d0::PathPoint& second, float radius)
{
    using namespace f3m_005f27d0;
    Matrix3 rotation; rotation.MakeZRotation(angle);
    Vec3 forward = rotation * (*(const Vec3*)DAT_00f725a4);
    PathPoint start(first);
    Vec3 origin = start.GetLocation();
    Vec3 destination = start.GetLocation() + forward * DAT_00dcf570;
    PathPoint hit;
    if (!FUN_005f1970(&start, &destination, 0, 65535, &hit, 0))
        destination = hit.GetLocation();
    Vec3 delta = destination - origin;
    Vec3 side = Vec3(delta.x, delta.y, delta.z).NiPoint3_UnitCross(*(const Vec3*)DAT_00f725b0) * radius;
    PathPoint minusStart(origin - side, start);
    PathPoint minusEnd(destination - side, start);
    if (!FUN_005f25b0(&minusStart, &minusEnd, &hit, 0)) {
        if ((hit.GetLocation() - minusStart.GetLocation()).SquareLength() < delta.SquareLength())
            destination = hit.GetLocation();
    }
    PathPoint plusStart(origin + side, start);
    PathPoint plusEnd(destination + side, start);
    if (!FUN_005f25b0(&plusStart, &plusEnd, &hit, 0)) {
        if ((hit.GetLocation() - plusStart.GetLocation()).SquareLength() < delta.SquareLength())
            destination = hit.GetLocation();
    }
    Vec3 retreat = forward * radius;
    retreat = retreat * DAT_00dc8080;
    destination -= retreat;
    PathPoint end(second);
    Vec3 endPosition = end.GetLocation();
    PathPoint endHit;
    if (!FUN_005f1970(&end, &destination, 0, 65535, &endHit, 0)) {
        return *(const Vec3*)&::DAT_0108ec68;
    }
    PathPoint endMinusStart(endPosition - side, end);
    PathPoint endMinusEnd(destination - side, end);
    if (!FUN_005f25b0(&endMinusStart, &endMinusEnd, &endHit, 0)) {
        return *(const Vec3*)&::DAT_0108ec68;
    }
    PathPoint endPlusStart(endPosition + side, end);
    PathPoint endPlusEnd(destination + side, end);
    if (!FUN_005f25b0(&endPlusStart, &endPlusEnd, &endHit, 0)) {
        return *(const Vec3*)&::DAT_0108ec68;
    } else {
        Vec3 direction = endPosition - origin;
        float length = direction.NiPoint3_UnitizeGetLength();
        float dot = direction.Dot(forward);
        if (DAT_00e02110 > dot) {
            return *(const Vec3*)&::DAT_0108ec68;
        }
        if (dot < 0.0f && length < 64.0f) {
            return *(const Vec3*)&::DAT_0108ec68;
        }
        return destination - origin;
    }
}
}   // namespace f3m_005f27d0

// @f3 0x005efdd0 (community match, verified in this file)
namespace f3m_005efdd0 {
extern void* DAT_00dc4dc0[];
extern const float DAT_00e01370 = -64.0f;
extern const float DAT_00de7c24 = 180.0f;

struct Vec3
{
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
    float GetSquaredXYLength() const { return x * x + y * y; }
};

struct PathPoint
{
    void** m_vtable;
    Vec3 position;
    int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;

    PathPoint() { FUN_005fc3f0(); }
    PathPoint(const Vec3* point, int item, int flags) { FUN_005fc5a0(point, item, flags); }
    ~PathPoint() { m_vtable = DAT_00dc4dc0; }
    void FUN_005fc3f0();
    void FUN_005fc5a0(const Vec3* point, int item, int flags);
    void FUN_005fc480(const PathPoint* other);
    bool FUN_005fda30(int flag);
    bool FUN_005fc750();
};

struct PathEntry
{
    unsigned char flags;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    PathPoint point;
    int unk2C;
};

struct PathTable
{
    int unk00; int unk04; int unk08;
    PathEntry* entries;
    int unk10; int unk14; int unk18;
    int unk1C;
};

struct PathItem
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    Vec3 position;
};

struct PathContext
{
    int unk00;
    PathItem* items;
    unsigned int count;
};

struct PathOwner
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70;
    float radius;
    float GetCenterRadius() { return radius; }
};

struct PathOutput
{
    int FUN_005ecde0(PathPoint* point);
};

int __cdecl FUN_005f90b0(PathPoint* point, int mode, PathContext* context);

struct PathBuilder
{
    PathOwner* owner;
    PathOwner* GetRequest() { return owner; }
    PathTable* table;
    int unk08; int unk0C;
    bool busy;

    bool FUN_005ee080(PathEntry* entry, PathEntry* next, PathPoint* out);
    int FUN_005eebe0(PathPoint* point, PathOutput* output, bool flag, PathContext* context);
    int FUN_005efdd0(int index, PathOutput* output, PathContext* context);
};

static inline int f3m_005efdd0_count(PathTable* t) { return t->unk10; }
int PathBuilder::FUN_005efdd0(int index, PathOutput* output, PathContext* context)
{
    PathEntry* next;
    next = &table->entries[index];
    if (index != f3m_005efdd0_count(table) - 1) {
        PathEntry* dy = &table->entries[index + 1];
        if (index < table->unk1C) {
            if (dy->flags & 2) {
                PathPoint radius;
                if (FUN_005ee080(next, dy, &radius)) {
                    next->point.FUN_005fc480(&radius);
                    output->FUN_005ecde0(&radius);
                    return 1;
                }
            }
        } else if (!(4 & next->flags)) {
            PathPoint radius;
            if (FUN_005ee080(next, dy, &radius)) {
                next->point.FUN_005fc480(&radius);
                output->FUN_005ecde0(&radius);
                return 1;
            }
        }
    }
    if (next->flags & 2) {
        PathPoint* point = &next->point;
        if (point->FUN_005fda30(0)) {
            if (!point->FUN_005fc750()) {
                switch (FUN_005f90b0(point, 10, context)) {
                case 1:
                    break;
                case 2: {
                    for (unsigned int i = 0; i < context->count; i++) {
                        Vec3 position = point->position;
                        const Vec3& merged = context->items[i].position;
                        Vec3 diff = position - merged;
                        if (diff.GetSquaredXYLength() < GetRequest()->GetCenterRadius() * owner->GetCenterRadius() &&
                            diff.z > DAT_00e01370 && diff.z < DAT_00de7c24) {
                            PathPoint found(&context->items[i].position, ((context->items)[i]).unk00, ((((context->items))[i])).unk04);
                            output->FUN_005ecde0(&found);
                            return 1;
                        }
                    }
                    return FUN_005eebe0(point, output, false, context);
                }
                default:
                    return 2;
                }
            }
            output->FUN_005ecde0(point);
            return 1;
        }
    }
    return 2;
}
}

// @f3 0x005e91d0 (community match, verified in this file)
#include <windows.h>

namespace f3m_005e91d0 {


extern char DAT_00e01be0[];
extern char DAT_00e01c10[];
extern float flt_00dbe1e0;

struct PMgr {
    PMgr();
    ~PMgr();
    void FUN_00608bd0();
    static PMgr* GetSingleton() { static PMgr instance; return &instance; }
    bool FUN_00606e30();
    void FUN_00607510();
    void FUN_00607520();
};

struct WorldState {
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    bool ready;
    void FUN_005cbe40();
};

extern WorldState* DAT_01074570;

struct RefLock {
    volatile long owner;
    long count;
    void FUN_00409a80(const char*);
    inline void Unlock() { if (--count == 0) { long o = owner; InterlockedCompareExchange(&owner, 0, o); } }
};

struct RefState {
    CRITICAL_SECTION cs;
    bool rebuild;
    char f019;
    char f01a;
    char f01b;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    void* background;
    int f0e4;
    int f0e8;
    int f0ec;
    void* completed;
    int f0f4;
    int f0f8;
    int f0fc;
    RefLock reflock;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int state;
    float time;

    void* FUN_005e3120();
    void* FUN_005e3160();

    void FUN_005e5610();
    void FUN_005e47c0();
    void FUN_005e5de0();
    void FUN_005e74f0();
    void FUN_005e6a60();
    void FUN_005e8a10();
    void FUN_005e80b0();
    void FUN_005e81f0();
    void FUN_005e5e60();
    void FUN_005e8390();
    void FUN_005e91d0();
};

void* RefState::FUN_005e3120() { reflock.FUN_00409a80(DAT_00e01be0); void* result = completed; reflock.Unlock(); return result; }
void* RefState::FUN_005e3160() { reflock.FUN_00409a80(DAT_00e01c10); void* result = background; reflock.Unlock(); return result; }

PMgr* __cdecl FUN_0044f4b0();

// pdb: NavMeshObstacleManager::ForceUpdateAllObstacles | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
void RefState::FUN_005e91d0()
{
    EnterCriticalSection(&cs);

    {
        void* a;
        void* b;
        for (a = FUN_005e3120(), b = FUN_005e3160(); a != b; a = FUN_005e3120(), b = FUN_005e3160())
            Sleep(0);
    }

    FUN_0044f4b0()->FUN_00607510();
    while (!PMgr::GetSingleton()->FUN_00606e30()) {
        PMgr::GetSingleton()->FUN_00608bd0();
    }

    FUN_005e5610();
    FUN_005e47c0();
    FUN_005e5de0();
    FUN_005e74f0();

    {
        void* a;
        void* b;
        for (a = FUN_005e3120(), b = FUN_005e3160(); a != b; a = FUN_005e3120(), b = FUN_005e3160())
            Sleep(0);
    }

    FUN_005e5610();
    FUN_005e47c0();
    FUN_005e5de0();
    FUN_005e6a60();
    FUN_005e8a10();
    FUN_005e80b0();
    FUN_005e81f0();
    FUN_005e5e60();
    FUN_005e8390();
    FUN_005e74f0();

    {
        void* a;
        void* b;
        for (a = FUN_005e3120(), b = FUN_005e3160(); a != b; a = FUN_005e3120(), b = FUN_005e3160())
            Sleep(0);
    }

    FUN_005e5610();
    FUN_005e47c0();
    FUN_005e5de0();

    time = flt_00dbe1e0;
    state = 0;
    if (DAT_01074570->ready) DAT_01074570->FUN_005cbe40();
    FUN_0044f4b0()->FUN_00607520();

    LeaveCriticalSection(&cs);
}

}  // namespace f3m_005e91d0

// @f3 0x005f5590 (community match, verified in this file)
namespace f3m_005f5590 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float SqrLength() const { return x * x + y * y + z * z; }
    float Dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float ax, float ay) : x(ax), y(ay) {}
};
extern const Vec3 DAT_0108ec68;  // default heading
// Reference-counted base of a navmesh (vtable at +0x1c, count at +0x20); slot 1 deletes the object.
struct RefCounted {
    virtual void Slot00();
    virtual void Destroy();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
struct NavMeshTriangle {
    unsigned short vertices[3];
    unsigned short edges[3];
    unsigned int flags;
    bool IsFlagSet(int flag) { return (flag & flags) != 0; }
    bool IsEdgeFlagSet(int edge) { return (flags & (1 << edge)) != 0; }
    unsigned short GetEdge(int edge) { return edges[edge]; }
    bool HasEdge(int edge) { return edges[edge] != 0xffff; }
};
struct EdgeExtraInfo {
    int type;
    int unk04;
    int unk08;
};
struct VertexPair {
    const Vec3* first;
    const Vec3* second;
    VertexPair() {}
};
struct NavMesh {
    void* vtable;
    int unk04, unk08;
    unsigned int formID;
    int unk10, unk14, unk18;
    RefCounted ref1C;
    int unk24, unk28;
    Vec3* vertices;
    int unk30, unk34;
    void* trianglesVtbl;
    NavMeshTriangle* triangles;
    unsigned int triangleCount;
    unsigned int triangleCapacity;
    void* edgeInfosVtbl;
    EdgeExtraInfo* edgeInfos;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    unsigned int GetFormID() { return formID; }
    unsigned int GetTriangleCount() { return triangleCount; }
    NavMeshTriangle* GetTriangle(unsigned short i) { return &triangles[i]; }
    EdgeExtraInfo* GetEdgeInfoAt(unsigned short i) { return &edgeInfos[i]; }
    Vec3 FUN_004d45e0(unsigned short triangle) const;           // triangle centre
    unsigned char FUN_005f1460(unsigned short triangle) const;  // number of neighbouring edges
    unsigned char CountEdges(unsigned short triangle) {
        unsigned char count = 0;
        for (char i = 0; i < 3; ++i) {
            if (GetTriangle(triangle)->HasEdge(i))
                ++count;
        }
        return count;
    }
    EdgeExtraInfo* GetEdgeInfo(unsigned short triangle, int edge) {
        if (GetTriangle(triangle)->IsEdgeFlagSet(edge) && GetTriangle(triangle)->GetEdge(edge) != 0xFFFF)
            return GetEdgeInfoAt(GetTriangle(triangle)->GetEdge(edge));
        else
            return 0;
    }
    // exit edge of the 2D segment start-end from the triangle (-1: none), reached = the crossing point
    int FUN_005bde60(unsigned short triangle, int edge, const Vec2& start, const Vec2& end, Vec2& reached);
    // neighbour across an edge: its mesh, triangle and entry edge
    bool NavMesh_GetMatchingEdge(unsigned short triangle, int edge, NavMesh*& adjMesh, unsigned short& adjTriangle, int& adjEdge);
    VertexPair FUN_005b8900(unsigned short triangle, int edge);  // the two vertices of an edge
};
// FUN_004d45e0 and FUN_005f1460 are leaf functions whose bodies the original compiler saw (header inlines left as
// calls in this large function): with them visible the score base stays in esi across both calls, as in the target.
__declspec(noinline) Vec3 NavMesh::FUN_004d45e0(unsigned short triangle) const {
    const NavMeshTriangle& t = triangles[triangle];
    Vec3 center = vertices[t.vertices[0]];
    const Vec3& b = vertices[t.vertices[1]];
    const Vec3& c = vertices[t.vertices[2]];
    center.x = (center.x + b.x + c.x) * 0.333333f;
    center.y = (center.y + b.y + c.y) * 0.333333f;
    center.z = (center.z + b.z + c.z) * 0.333333f;
    return center;
}
__declspec(noinline) unsigned char NavMesh::FUN_005f1460(unsigned short triangle) const {
    unsigned char count = 0;
    for (int i = 0; i < 3; ++i)
        if (triangles[triangle].edges[i] != 0xffff)
            ++count;
    return count;
}
Vec2 __cdecl FUN_005dd850(const Vec2& a, const Vec2& b, const Vec2& c, const Vec2& d);  // 2D segment intersection
struct PathingLocation {
    void* vtable;
    Vec3 location;
    bool FUN_005fda30(int mode);
    bool FUN_005fc8f0(NiPointer<NavMesh>& mesh, unsigned short& triangle);  // navmesh and triangle of the location
    Vec3 GetLocation() const { return location; }
};
// Line-of-sight scores per navmesh triangle: 127 unknown, > 0 visible, < 0 hidden.
struct LOSMap {
    void* vtable;
    int unk04;
    int unk08, unk0c, unk10, unk14;  // form ID -> score offset map (FUN_005ffe40)
    char* scores;
    void* meshesVtbl;
    NiPointer<NavMesh>* meshes;
    unsigned int meshCount;
    unsigned int meshCapacity;
    unsigned int totalTriangles;
    int unk30, unk34;
    char best;
    char worst;
    Vec3 center;
    float radius;
    unsigned int GetMeshCount() { return meshCount; }
    const NiPointer<NavMesh>& GetMesh(unsigned int i) { return meshes[i]; }
    void FUN_005ffdf0();                                             // reset hidden scores to unknown
    bool FUN_005ffe40(unsigned int navMeshID, unsigned int& offset);  // score offset of a navmesh
    Vec3 GetCenter() { return center; }
    float GetRadius() { return radius; }
    char GetScore(int i) { return scores[i]; }
    void SetScore(int i, char value) { scores[i] = value; }
    char GetBest() { return best; }
    char GetWorst() { return worst; }
    void SetBest(char value) { best = value; }
    void SetWorst(char value) { worst = value; }
};
struct MemMgr5 {
    void* FUN_0086bcb0();
};
extern MemMgr5 DAT_01090a78;
struct PathEntry {
    int index;
    unsigned char value;
    PathEntry(int i, char v) : index(i), value(v) {}
};
struct PathArrayBase {
    virtual ~PathArrayBase() {
        if (buffer) {
            Free(buffer);
            buffer = 0;
            capacity = 0;
            count = 0;
        }
    }
    virtual PathEntry* Allocate(unsigned int n);
    virtual void Free(void* p);
    PathEntry* buffer;
    unsigned int count;
    unsigned int capacity;
    PathArrayBase() : buffer(0), count(0), capacity(0) {}
    void SetCapacity(unsigned int n) {
        buffer = Allocate(n);
        capacity = n;
    }
};
struct PathArray : PathArrayBase {
    void* heap;
    __forceinline PathArray(unsigned int n, unsigned int, unsigned int) {
        heap = DAT_01090a78.FUN_0086bcb0();
        buffer = 0;
        count = 0;
        capacity = 0;
        if (n)
            SetCapacity(n);
    }
    ~PathArray();
    unsigned int FUN_006cb090();  // append a slot, return its index
    void FUN_005bb6f0(unsigned int newCapacity, unsigned int keep);
    unsigned int AppendSlotInline() {
        if (count == capacity) {
            if (!capacity) {
                buffer = Allocate(4);
                capacity = 4;
            } else {
                unsigned int n = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                FUN_005bb6f0(n, count);
                capacity = n;
            }
        }
        ++count;
        return count - 1;
    }
    void Add(const PathEntry& e) {
        unsigned int i = FUN_006cb090();
        buffer[i] = e;
    }
    void AddInline(const PathEntry& e) {
        unsigned int i = AppendSlotInline();
        buffer[i] = e;
    }
    unsigned int GetSize() { return count; }
    PathEntry& GetAt(unsigned int i) { return buffer[i]; }
};

// Marks the line of sight from location to every unknown navmesh triangle around the map's centre: walks the
// triangles along the 2D segment from the triangle's centre to the location; reaching the location's triangle makes
// every triangle on the way visible (score = its edge count), otherwise hidden (score = -edge count).
// The named constants, the named results and the working variables declared with initialisers at the top of the
// mesh loop produce no code; they stand in for the original's declarations before the first FUN_005ffe40 call,
// whose number decides the base/index order of the lea at +0x4c6 (a guess at the source).
// pdb: Pathing::ComputeLineOfSightMapForLocation | Pathfind.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aLocation, aspRetMap, abClearUnseen, afSightRadius, afHeading
bool __cdecl FUN_005f5590(PathingLocation* location, NiPointer<LOSMap>& data, bool reset, float maxDistance,
                          float angle)
{
    const char kUnknown = 127;
    const char kMaxVisible = 3;
    const char kMinVisible = -3;
    if (!data->GetMeshCount())
        return false;
    float radiusSqr;
    bool valid = location->FUN_005fda30(0);
    if (!valid)
        return false;
    NiPointer<NavMesh> startMesh;
    unsigned short startTriangle = 0xffff;
    bool located = location->FUN_005fc8f0(startMesh, startTriangle);
    if (!located)
        return false;
    if (reset)
        data->FUN_005ffdf0();
    Vec3 position = location->GetLocation();
    Vec3 mapCenter = data->GetCenter();
    float mapRadius = data->GetRadius();
    radiusSqr = mapRadius * mapRadius;
    Vec3 heading = DAT_0108ec68;
    if (angle >= 0.0) {
        float s, c;
        fnv_SinCos(angle, s, c);
        heading.x = s;
        heading.y = c;
    }
    for (unsigned int meshIndex = 0; meshIndex < data->GetMeshCount(); ++meshIndex) {
        NiPointer<NavMesh> mesh = data->GetMesh(meshIndex);
        NavMesh* meshPtr = mesh;
        NavMesh* walkMesh = 0;
        unsigned short walkTriangle = 0;
        bool visible = false;
        int exitEdge = -1;
        EdgeExtraInfo* edgeInfo = 0;
        Vec2 nextPoint;
        Vec3 toTriangle;
        unsigned int scoreBase = 0;
        if (!data->FUN_005ffe40(mesh->GetFormID(), scoreBase))
            continue;
        unsigned int tri = 0;
        while (tri < mesh->GetTriangleCount()) {
            // skip triangles already scored and those flagged 0x20
            while (data->GetScore(tri + scoreBase) != kUnknown || mesh->GetTriangle((unsigned short)tri)->IsFlagSet(0x20)) {
                ++tri;
                if (tri >= mesh->GetTriangleCount())
                    break;
            }
            if (tri >= mesh->GetTriangleCount())
                break;
            Vec3 triCenter = meshPtr->FUN_004d45e0((unsigned short)tri);
            if (mapRadius != 0.0) {
                Vec3 fromCenter = triCenter - mapCenter;
                fromCenter.z *= 3.0;
                if (fromCenter.SqrLength() > radiusSqr) {
                    ++tri;
                    continue;
                }
            }
            if (maxDistance > 0.0 || angle >= 0.0) {
                bool rejected = false;
                toTriangle = triCenter - location->GetLocation();
                if (maxDistance > 0.0 && toTriangle.SqrLength() > maxDistance * maxDistance)
                    rejected = true;
                if (!rejected && angle >= 0.0 && heading.Dot(toTriangle) < 0.0)
                    rejected = true;
                if (rejected) {
                    if (data->GetScore(tri + scoreBase) == kUnknown)
                        data->SetScore(tri + scoreBase, -(char)meshPtr->FUN_005f1460((unsigned short)tri));
                    ++tri;
                    continue;
                }
            }
            Vec2 start(triCenter.x, triCenter.y);
            Vec2 end(position.x, position.y);
            Vec2 reached;
            walkTriangle = (unsigned short)tri;
            walkMesh = mesh;
            unsigned int walkScoreBase = scoreBase;
            visible = false;
            PathArray path(64, 0, 0);
            path.Add(PathEntry(walkTriangle + walkScoreBase, walkMesh->CountEdges(walkTriangle)));
            if (walkTriangle == startTriangle && walkMesh == (NavMesh*)startMesh)
                visible = true;
            else {
                exitEdge = walkMesh->FUN_005bde60(walkTriangle, -1, start, end, reached);
                while (exitEdge != -1) {
                    NavMesh* adjMesh;
                    unsigned short adjTriangle;
                    int adjEdge;
                    if (walkMesh->NavMesh_GetMatchingEdge(walkTriangle, exitEdge, adjMesh, adjTriangle, adjEdge)) {
                        edgeInfo = walkMesh->GetEdgeInfo(walkTriangle, exitEdge);
                        if (edgeInfo && edgeInfo->type == 1)
                            break;
                        if (adjMesh != walkMesh) {
                            if (!data->FUN_005ffe40(adjMesh->GetFormID(), walkScoreBase))
                                break;
                            VertexPair ends = adjMesh->FUN_005b8900(adjTriangle, adjEdge);
                            Vec2 p0(ends.first->x, ends.first->y);
                            Vec2 p1(ends.second->x, ends.second->y);
                            reached = FUN_005dd850(p0, p1, reached, end);
                        }
                        walkMesh = adjMesh;
                        walkTriangle = adjTriangle;
                        path.AddInline(PathEntry(walkTriangle + walkScoreBase, walkMesh->CountEdges(walkTriangle)));
                        exitEdge = adjMesh->FUN_005bde60(adjTriangle, adjEdge, reached, end, nextPoint);
                        reached = nextPoint;
                        if (walkTriangle == startTriangle && walkMesh == (NavMesh*)startMesh) {
                            visible = true;
                            break;
                        }
                    } else
                        break;
                }
            }
            if (visible) {
                for (unsigned int a = 0; a < path.GetSize(); ++a)
                    data->SetScore(path.GetAt(a).index, path.GetAt(a).value);
                for (unsigned int b = 0; b < path.GetSize(); ++b) {
                    if (data->GetBest() == kMaxVisible)
                        break;
                    if ((char)path.GetAt(b).value > data->GetBest())
                        data->SetBest(path.GetAt(b).value);
                }
            } else {
                for (unsigned int c = 0; c < path.GetSize(); ++c)
                    if (data->GetScore(path.GetAt(c).index) == kUnknown)
                        data->SetScore(path.GetAt(c).index, -(char)path.GetAt(c).value);
                for (unsigned int d = 0; d < path.GetSize(); ++d) {
                    if (data->GetWorst() == kMinVisible)
                        break;
                    if (-(char)path.GetAt(d).value < data->GetWorst())
                        data->SetWorst(-(char)path.GetAt(d).value);
                }
            }
            ++tri;
        }
    }
    return true;
}
}

// @f3 0x005e5610 (community match, verified in this file)
namespace f3m_005e5610 {
namespace PortalMatch5610 {
struct NavMesh;
struct Info;
struct Obstacle;
struct Cell;

struct Point3 {
 float x,y,z;
};
struct EdgeRef {
 unsigned short triangle;
 int edge;
 EdgeRef() {}
 EdgeRef(unsigned short t,int e) : triangle(t),edge(e) {}
 EdgeRef(const EdgeRef& other) : triangle(other.triangle),edge(other.edge) {}
 EdgeRef& operator=(const EdgeRef& other) { triangle=other.triangle;edge=other.edge;return *this; }
};
struct Portal { Info* info;unsigned int unk04;int edge; };
struct PortalInfo {
 Info* info;
 EdgeRef edge;
 PortalInfo() {}
 PortalInfo(const Portal* source) { info=source->info;edge.triangle=static_cast<unsigned short>(source->unk04);edge.edge=source->edge; }
 PortalInfo(const PortalInfo& other) : info(other.info),edge(other.edge) {}
 PortalInfo& operator=(const PortalInfo& other) { info=other.info;edge=other.edge;return *this; }
};
struct EdgePair {
 const Point3* p1;
 const Point3* p2;
 EdgePair() {}

};
struct LinkRecord {
 int unk00;
 Info* id;
 unsigned short triangle;
 LinkRecord() : unk00(-1),id(0),triangle(0xffff) {}
 LinkRecord(Info* linkID,unsigned short t) : unk00(-1),id(linkID),triangle(t) {}
 LinkRecord& operator=(const LinkRecord& other) { unk00=other.unk00;id=other.id;triangle=other.triangle;return *this; }
};
struct Triangle {
 unsigned short vertices[3];
 unsigned short links[3];
 unsigned int flags;
 bool IsEdgeFlagSet(int edge) { return (flags&(1<<edge))!=0; }
 unsigned short GetEdge(int edge) { return links[edge]; }
 // pdb: hkClassMember::isNotOwner | hkClassMember.obj | fnv360_0822_retail, objrun, high (was: HasFlag)
 bool hkClassMember_isNotOwner(unsigned int flag) const { return (flags&flag)!=0; }
 void Connect(int edge,unsigned short link) { flags|=1u<<edge;links[edge]=link; }
};

template<class T> class Array {
public:
 virtual ~Array();
 virtual T* Allocate(unsigned int count);
 virtual void Deallocate(T* values);
 virtual T* Reallocate(T* values,unsigned int count);
 T* data;
 unsigned int count;
 unsigned int capacity;
 unsigned int GetSize() const { return count; }
 T& GetAt(unsigned int index) { return data[index]; }
 T& GetAt(int index) { return data[index]; }
 const T& GetAt(unsigned int index) const { return data[index]; }
};
class PortalArray : public Array<Portal> {
public:
 void FUN_0079e680(Portal* destination,const Portal* source,unsigned int count);
 Portal* GetRecord(unsigned int index) { return data+index; }
 void RemoveFast(unsigned int index,unsigned int n=1) {
  unsigned int remaining=count-index-n;
  unsigned int copied=remaining<n?remaining:n;
  // EMITS NOTHING: Portal has no destructor, so this loop compiles to no instructions. The match depends on
  // it all the same: the block after it is laid out as a loop head (aligned to 16 bytes where the padding is
  // short) and what the compiler knows about `target` is dropped there, exactly as in the original.
  for(unsigned int k=0;k<n;++k) data[index+k].~Portal();
  FUN_0079e680(data+index,data+count-copied,copied);
  count-=n;
 }
};
struct PortalSet { PortalArray portals;PortalArray open; };

class FormPrefix {
public:
 virtual ~FormPrefix();
 unsigned int unk04,unk08,unk0c,unk10,unk14;
};
class ChildCell {
public:
 virtual Cell* GetSaveParentCell();
};
class RefObject {
public:
 virtual ~RefObject();
 virtual void DeleteThis();
 long refCount;
 void IncRefCount() { ::InterlockedIncrement(&refCount); }
 void DecRefCount() { if(::InterlockedDecrement(&refCount)==0) DeleteThis(); }
};

struct NavMesh : public FormPrefix,public ChildCell,public RefObject {
 Cell* owningCell;
 Array<Point3> vertices;
 Array<Triangle> triangles;
 Array<LinkRecord> links;
 EdgePair FUN_005b8900(unsigned short triangle,int edge);
 bool FUN_005b9140(const PortalInfo& source,PortalInfo& result);
 unsigned int FUN_005ba390(const LinkRecord& record);
 unsigned int GetTriangleCount() const { return triangles.count; }
 Triangle* GetTriangle(unsigned short index) { return &triangles.GetAt(static_cast<unsigned int>(index)); }
 LinkRecord* GetEdgeInfoAt(unsigned short i) { return &links.data[i]; }
 LinkRecord* GetEdgeExtraInfo(unsigned short triangle,int edge) {
  if(GetTriangle(triangle)->IsEdgeFlagSet(edge) && GetTriangle(triangle)->GetEdge(edge)!=0xFFFF)
   return GetEdgeInfoAt(GetTriangle(triangle)->GetEdge(edge));
  else
   return 0;
 }
};

template<class T> class NiPointer {
 T* value;
public:
 NiPointer() : value(0) {}
 NiPointer(T* object) : value(object) { if(value) value->IncRefCount(); }
 NiPointer(const NiPointer& other) : value(other.value) { if(value) value->IncRefCount(); }
 ~NiPointer() { if(value) value->DecRefCount(); }
 NiPointer& operator=(const NiPointer& other) {
  if(value!=other.value) {
   if(value) value->DecRefCount();
   value=other.value;
   if(value) value->IncRefCount();
  }
  return *this;
 }
 NiPointer& operator=(T* object) {
  if(value!=object) {
   if(value) value->DecRefCount();
   value=object;
   if(value) value->IncRefCount();
  }
  return *this;
 }
 operator T*() const { return value; }
 T* operator->() const { return value; }
 T& operator*() const { return *value; }
};
typedef NiPointer<NavMesh> MeshPtr;
void __cdecl FUN_005b87d0(MeshPtr& result,NavMesh* mesh);

struct Info {
 unsigned int unk00,unk04,flags;
 unsigned int unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50;
 NavMesh* mesh;
 bool IsDisabled() const { return (flags>>4)&1; }
 bool Resolve(MeshPtr& result) {
  if(IsDisabled()) return false;
  FUN_005b87d0(result,mesh);
  return static_cast<NavMesh*>(result)!=0;
 }
};
struct Obstacle {
 unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;
 Info* info;
 MeshPtr source;
 MeshPtr mesh;
 unsigned int unk24,unk28,unk2c,unk30;
 PortalSet portalSet;
 bool dirty;
};
struct Manager {
 unsigned int unk00;
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
 unsigned int unk40;
 unsigned int unk44;
 unsigned int unk48;
 unsigned int unk4c;
 unsigned int unk50;
 unsigned int unk54;
 unsigned int unk58;
 unsigned int unk5c;
 unsigned int unk60;
 unsigned int unk64;
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
 unsigned int unkb0;
 unsigned int unkb4;
 unsigned int unkb8;
 unsigned int unkbc;
 unsigned int unkc0;
 unsigned int unkc4;
 unsigned int unkc8;
 unsigned int unkcc;
 unsigned int unkd0;
 unsigned int unkd4;
 unsigned int unkd8;
 unsigned int unkdc;
 unsigned int unke0;
 unsigned int unke4;
 Array<Obstacle*> obstacles;
 bool FUN_005e4710(MeshPtr& first,const PortalInfo& firstPortal,MeshPtr& second,const PortalInfo& secondPortal);
 bool FUN_005e5610();
};
}
namespace PortalMatch5610 {
// FUN_005b87d0 is a small callee the target calls out of line. Its real body is given here (read from the
// game: wrap the raw pointer, assign) because the compiler uses what a visible callee does: with it visible
// `target` stays in esi across the later calls, as in the original. It emits its own code and is not part of
// the compared function. FUN_005e4710 below is the same case and was already in the stored draft.
__declspec(noinline) void __cdecl FUN_005b87d0(MeshPtr& result,NavMesh* mesh)
{
    MeshPtr temp(mesh);
    result=temp;
}
struct Point2 {
 float x,y;
 Point2(float ax,float ay) : x(ax),y(ay) {}
 Point2(const Point3& p) : x(p.x),y(p.y) {}
 Point2 operator-(const Point2& o) const { return Point2(x-o.x,y-o.y); }
 float SquaredLength() const { return x*x+y*y; }
};
__forceinline float SquaredDistanceXY(const Point3& a,const Point3& b)
{
    Point2 d=Point2(a)-Point2(b);
    return d.SquaredLength();
}
}
namespace PortalMatch5610 {
__declspec(noinline) bool Manager::FUN_005e4710(MeshPtr& first,const PortalInfo& firstPortal,
                                              MeshPtr& second,const PortalInfo& secondPortal)
{
    LinkRecord firstConnection(secondPortal.info,secondPortal.edge.triangle);
    unsigned short firstIndex=static_cast<unsigned short>(first->FUN_005ba390(firstConnection));
    first->GetTriangle(firstPortal.edge.triangle)->Connect(firstPortal.edge.edge,firstIndex);

    LinkRecord secondConnection(firstPortal.info,firstPortal.edge.triangle);
    unsigned short secondIndex=static_cast<unsigned short>(second->FUN_005ba390(secondConnection));
    second->GetTriangle(secondPortal.edge.triangle)->Connect(secondPortal.edge.edge,secondIndex);
    return true;
}
}
// pdb: NavMeshObstacleManager::ReconnectPortals | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
bool PortalMatch5610::Manager::FUN_005e5610()
{
    const unsigned int obstacleCount=obstacles.GetSize();
    for(unsigned int i=0;i<obstacleCount;++i) {
        Obstacle* owner=obstacles.GetAt(i);
        if(!owner->mesh) continue;
        PortalSet* portals=&owner->portalSet;
        for(unsigned int j=0;j<portals->portals.GetSize();++j) {
            PortalInfo first(portals->portals.GetRecord(j));
            if(first.edge.triangle>=owner->mesh->GetTriangleCount()) continue;
            Point3 a=*owner->mesh->FUN_005b8900(first.edge.triangle,first.edge.edge).p1;
            Point3 b=*owner->mesh->FUN_005b8900(first.edge.triangle,first.edge.edge).p2;
            bool matched=false;
            for(unsigned int k=0;k<obstacleCount;++k) {
                if(k==i) continue;
                Obstacle* other=obstacles.GetAt(k);
                if(!other->mesh) continue;
                PortalSet* otherPortals=&other->portalSet;
                for(unsigned int l=0;l<otherPortals->portals.GetSize();++l) {
                    PortalInfo second(otherPortals->portals.GetRecord(l));
                    if(second.edge.triangle>=other->mesh->GetTriangleCount()) continue;
                    Point3 qa=*other->mesh->FUN_005b8900(second.edge.triangle,second.edge.edge).p1;
                    Point3 qb=*other->mesh->FUN_005b8900(second.edge.triangle,second.edge.edge).p2;
                    if(SquaredDistanceXY(b,qa)<2500.0f && SquaredDistanceXY(a,qb)<2500.0f) {
                        FUN_005e4710(owner->mesh,first,other->mesh,second);
                        owner->dirty=true;
                        other->dirty=true;
                        portals->portals.RemoveFast(j);
                        --j;
                        otherPortals->portals.RemoveFast(l);
                        --l;
                        matched=true;
                        break;
                    }
                }
                if(matched) break;
            }
            if(!matched) {
                for(unsigned int m=0;m<portals->open.GetSize();++m) {
                    PortalInfo open(portals->open.GetRecord(m));
                    PortalInfo linked;
                    if(owner->source->FUN_005b9140(open,linked)) {
                        if(open.info==linked.info) continue;
                        MeshPtr target;
                        Obstacle* matchedObstacle=0;
                        for(unsigned int n=0;n<obstacleCount;++n) {
                            if(obstacles.GetAt(n)->info==linked.info) {
                                target=obstacles.GetAt(n)->mesh;
                                matchedObstacle=obstacles.GetAt(n);
                                break;
                            }
                        }
                        if(!target) {
                            linked.info->Resolve(target);
                            matchedObstacle=0;
                        }
                        if(!target) {
                            PortalInfo currentOpen(portals->open.GetRecord(m));
                            LinkRecord* extra=owner->source->GetEdgeExtraInfo(currentOpen.edge.triangle,currentOpen.edge.edge);
                            if(extra) {
                                LinkRecord newLink(extra->id,extra->triangle);
                                unsigned short newIndex=static_cast<unsigned short>(owner->mesh->FUN_005ba390(newLink));
                                owner->mesh->GetTriangle(first.edge.triangle)->Connect(first.edge.edge,newIndex);
                                portals->portals.RemoveFast(j);
                                --j;
                                matched=true;
                                break;
                            }
                        } else {
                            if(linked.edge.triangle>=target->GetTriangleCount()) continue;
                            if(target->GetTriangle(linked.edge.triangle)->hkClassMember_isNotOwner(0x20)) continue;
                            Point3 qa=*target->FUN_005b8900(linked.edge.triangle,linked.edge.edge).p1;
                            Point3 qb=*target->FUN_005b8900(linked.edge.triangle,linked.edge.edge).p2;
                            if(SquaredDistanceXY(b,qa)<2500.0f && SquaredDistanceXY(a,qb)<2500.0f) {
                                FUN_005e4710(owner->mesh,first,target,linked);
                                owner->dirty=true;
                                if(matchedObstacle) matchedObstacle->dirty=true;
                                portals->portals.RemoveFast(j);
                                --j;
                                matched=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

}   // namespace f3m_005e5610

// @f3 0x005f9e70 (community match, verified in this file)
#include <math.h>
namespace N5f9e70 {

struct S5f9_Pt3
{
    float x;
    float y;
    float z;
    S5f9_Pt3() {}
    S5f9_Pt3(float a, float b, float c) : x(a), y(b), z(c) {}
    S5f9_Pt3 operator-(const S5f9_Pt3& o) const { return S5f9_Pt3(x - o.x, y - o.y, z - o.z); }
    S5f9_Pt3 operator+(const S5f9_Pt3& o) const { return S5f9_Pt3(x + o.x, y + o.y, z + o.z); }
    S5f9_Pt3 operator*(float s) const { return S5f9_Pt3(x * s, y * s, z * s); }
    bool operator==(const S5f9_Pt3& o) const { return x == o.x && y == o.y && z == o.z; }
    bool operator!=(const S5f9_Pt3& o) const { return !(*this == o); }
    float SqrLength() const { return x * x + y * y + z * z; }
    float Dot(const S5f9_Pt3& o) const { return x * o.x + y * o.y + z * o.z; }
    S5f9_Pt3 Cross(const S5f9_Pt3& o) const { return S5f9_Pt3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x); }
    void FUN_00468d00();
};

struct S5f9_Pt2
{
    float x;
    float y;
    S5f9_Pt2() {}
    S5f9_Pt2(float a, float b) : x(a), y(b) {}
};

extern const S5f9_Pt3 DAT_0108ec68;
// FUN_00468d00 (normalise in place) is a small callee the original calls out of line. Its real body is given
// here (read from the game) because the compiler uses what a visible callee does: with it visible the two
// vertex pointers of the edge stay in esi/ebx across the call and are not re-read, and the whole register
// map of the function comes out as in the original. It emits its own code and is not part of the compared
// function.
__declspec(noinline) void S5f9_Pt3::FUN_00468d00()
{
    float len = (float)sqrt(SqrLength());
    if (len > 1e-6f)
    {
        float inv = 1.0f / len;
        x *= inv;
        y *= inv;
        z *= inv;
    }
    else
    {
        x = 0;
        y = 0;
        z = 0;
    }
}


struct S5f9_Location
{
    void* vtable;
    S5f9_Pt3 location;
};

struct S5f9_Params
{
    int unk00;
    int unk04;
    int unk08;
    S5f9_Location start;
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
    int unk60;
    int unk64;
    float scale68;
    float f6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    S5f9_Pt3 v;
    float radius;
    float fc0;
    float fc4;
    unsigned int maxCount;
    bool bcc;
    bool bcd;
    bool bce;
    bool bcf;
    bool bd0;
    bool bd1;
    char unkd2;
    char unkd3;
    S5f9_Pt3 n;
    S5f9_Pt3 dir;
    float GetRadius() const { return radius; }
    float GetC0() const { return fc0; }
    float Get6C() const { return f6c; }
    float GetC4() const { return fc4; }
    float GetScale() const { return scale68; }
    unsigned int GetMaxCount() const { return maxCount; }
};

struct S5f9_MemCtx;
struct S5f9_RefCounted
{
    virtual void Slot00();
    virtual void Destroy();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};

struct S5f9_Triangle
{
    unsigned short vertices[3];
    unsigned short edges[3];
    unsigned int flags;
};

struct S5f9_VertexPair
{
    const S5f9_Pt3* first;
    const S5f9_Pt3* second;
};

struct S5f9_NavMesh
{
    void* vtable;
    int unk04;
    int unk08;
    unsigned int formID;
    int unk10;
    int unk14;
    int unk18;
    S5f9_RefCounted ref1C;
    int unk24;
    int unk28;
    S5f9_Pt3* vertices;
    int unk30;
    int unk34;
    void* trianglesVtbl;
    S5f9_Triangle* triangles;
    unsigned int triangleCount;
    unsigned int triangleCapacity;
    void* edgeInfosVtbl;
    void* edgeInfos;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    void* indicesVtbl;
    unsigned short* indices;
    unsigned int indexCount;
    unsigned int GetIndexCount() { return indexCount; }
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    S5f9_Pt3 FUN_004d45e0(unsigned short triangle) const;
    S5f9_Pt3 FUN_005bd630(unsigned short triangle) const;
    S5f9_VertexPair FUN_005b8900(unsigned short triangle, int edge);
    void* FUN_005b84c0();
};

struct MemMgr5
{
    S5f9_MemCtx* FUN_0086bcb0();
};
extern MemMgr5 DAT_01090a78;
struct S5f9_ArrBase
{
    virtual ~S5f9_ArrBase();
    virtual void* Allocate(unsigned int n);
    virtual void Free(void* p);
    void* buffer;
    unsigned int count;
    unsigned int capacity;
    S5f9_ArrBase() : buffer(0), count(0), capacity(0) {}
};

// Both arrays use the constructor of the sibling function 0x005f5590 of this file: base constructor, heap from
// DAT_01090a78 when no allocator is passed, then Init, which zeroes the fields again and calls Allocate through
// the vtable.
struct S5f9_FloatArr : S5f9_ArrBase
{
    S5f9_MemCtx* heap;
    __forceinline S5f9_FloatArr(unsigned int cap, unsigned int initial, S5f9_MemCtx* allocator) : S5f9_ArrBase()
    {
        if (!allocator)
            allocator = DAT_01090a78.FUN_0086bcb0();
        heap = allocator;
        Init(initial, cap);
    }
    __forceinline void Init(unsigned int initial, unsigned int cap)
    {
        buffer = 0;
        count = 0;
        capacity = 0;
        if (initial > cap)
            cap = initial;
        if (cap > 0)
        {
            buffer = Allocate(cap);
            capacity = cap;
        }
        if (initial > 0)
            count = initial;
    }
    ~S5f9_FloatArr();
    void FUN_005f4460(unsigned int index, const float& value);
    float& GetAt(unsigned int i) { return ((float*)buffer)[i]; }
};

struct S5f9_PtrArr : S5f9_ArrBase
{
    S5f9_MemCtx* heap;
    __forceinline S5f9_PtrArr(unsigned int cap, unsigned int initial, S5f9_MemCtx* allocator) : S5f9_ArrBase()
    {
        if (!allocator)
            allocator = DAT_01090a78.FUN_0086bcb0();
        heap = allocator;
        Init(initial, cap);
    }
    __forceinline void Init(unsigned int initial, unsigned int cap)
    {
        buffer = 0;
        count = 0;
        capacity = 0;
        if (initial > cap)
            cap = initial;
        if (cap > 0)
        {
            buffer = Allocate(cap);
            capacity = cap;
        }
        if (initial > 0)
            count = initial;
    }
    ~S5f9_PtrArr();
    unsigned int GetSize() { return count; }
    NiPointer<S5f9_NavMesh>& GetAt(unsigned int i) { return ((NiPointer<S5f9_NavMesh>*)buffer)[i]; }
};

struct S5f9_PathLoc
{
    virtual void Slot00();
    S5f9_Pt3 location;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S5f9_PathLoc(const S5f9_Pt3& pos, void* cell, unsigned short triangle);
    ~S5f9_PathLoc() {}
};

struct S5f9_Portal : S5f9_PathLoc
{
    S5f9_Pt3 b;
    S5f9_Pt3 a;
    S5f9_Pt3 perp;
    int unk4c;
    int unk50;
    S5f9_Portal(const S5f9_Pt3& pos, void* cell, unsigned short triangle) : S5f9_PathLoc(pos, cell, triangle) {}
    // The edge data is assigned after construction, not in the constructor: only then are the copies
    // interleaved with the argument pushes of FUN_00602020 as in the original.
    void Set(S5f9_VertexPair e, const S5f9_Pt3& pp)
    {
        b = *e.second;
        a = *e.first;
        perp = pp;
    }
    virtual void Slot00();
    void FUN_00602020(unsigned short type, unsigned short r2, unsigned short r1, bool b1, bool b2, unsigned short edge);
};

struct S5f9_Out
{
    void FUN_005f3610(unsigned int n);
    void FUN_005f42a0(unsigned int index, const S5f9_PathLoc& portal);
};

unsigned short FUN_005d1f20(float value, int a, int b);
void FUN_005f5eb0(S5f9_Location* origin, float radius, S5f9_PtrArr* out, int flag);
bool FUN_005dd4c0(const S5f9_Pt2& p0, const S5f9_Pt2& p1, const S5f9_Pt2& q0, const S5f9_Pt2& q1);

// pdb: Pathing::GetCoverPoints | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRequest, apReturnArray
unsigned int FUN_005f9e70(S5f9_Params* p, S5f9_Out* q)
{
    unsigned int result = 0;
    // maxCount is read through the inline accessor (a direct read rotates the scratch registers once more).
    q->FUN_005f3610(p->GetMaxCount());
    S5f9_FloatArr dists(0x20, 0, 0);
    S5f9_Pt3 dir = p->dir;
    S5f9_Pt3 pos = p->start.location;
    bool useDir = true;
    if (dir == DAT_0108ec68)
    {
        dir = p->start.location;
        useDir = false;
    }
    S5f9_Pt3 v = p->v;
    S5f9_Pt2 v2(v.x, v.y);
    S5f9_Pt2 delta2(dir.x - v.x, dir.y - v.y);
    unsigned short r1 = FUN_005d1f20(p->GetC0(), 0, 1);
    unsigned short r2 = FUN_005d1f20(p->Get6C(), 0, 1);
    float radius = p->radius;
    float radiusSq = p->GetRadius() * radius;
    S5f9_PtrArr cands(8, 0, 0);
    FUN_005f5eb0(&p->start, p->GetRadius(), &cands, 1);
    NiPointer<S5f9_NavMesh> mesh;
    bool bcc = p->bcc;
    bool bd1 = p->bd1;
    for (unsigned int i = 0; i < cands.GetSize(); i++)
    {
        mesh = cands.GetAt(i);
        unsigned short count = mesh->GetIndexCount();
        for (unsigned short j = 0; j < count; j++)
        {
            unsigned short idx = mesh->indices[j];
            S5f9_Triangle* tri = &mesh->triangles[idx];
            if (!((tri->flags & 0xfbe0000) > 0))
                continue;
            S5f9_Pt3 c;
            c = mesh->FUN_004d45e0(idx);
            S5f9_Pt3 d;
            d = dir - c;
            float lenSq = d.x * d.x + d.y * d.y + d.z * d.z;
            if (useDir)
            {
                if ((pos - c).SqrLength() > radiusSq)
                    continue;
            }
            else if (radiusSq < lenSq)
                continue;
            S5f9_Pt3 n = p->n;
            if (p->bd0)
            {
                S5f9_Pt3 e = v - c;
                lenSq = e.x * e.x + e.y * e.y + e.z * e.z;
                if (n != DAT_0108ec68)
                {
                    float dot = e.Dot(n);
                    lenSq = lenSq + dot * dot / lenSq * 2;
                }
            }
            else
            {
                if (n != DAT_0108ec68)
                {
                    float dot = d.Dot(n);
                    lenSq = lenSq + dot * dot / lenSq * 2;
                }
            }
            if (fabs(d.z) > p->GetC4())
                continue;
            // Written y term first: this gives the original's x87 order (x product computed first).
            float side = (c.y - v2.y) * delta2.y + (c.x - v2.x) * delta2.x;
            if (p->bce)
                side = -side;
            if (!p->bcd && !(side > 0))
                continue;
            S5f9_Pt3 nrm;
            nrm = mesh->FUN_005bd630(idx);
            for (unsigned short k = 0; k < 2; k++)
            {
                unsigned char bits = (unsigned char)(tri->flags >> (k * 6 + 0x10));
                // A 32-bit intermediate keeps the and 32-bit (movzx ecx,al; and ecx,0xf); every byte-typed spelling
                // narrows it to and cl,15 + movzx cx,cl.
                unsigned int t = bits & 0xf;
                unsigned short type = t;
                bool b1 = (bits & 0x10) > 0;
                bool b2 = (bits & 0x20) > 0;
                if (type < 4)
                {
                    switch (type)
                    {
                    case 2:
                        if (bd1)
                            continue;
                        break;
                    default:
                        continue;
                    }
                }
                else if (type < (bcc ? r1 : r2))
                    continue;
                if (!b1 && !b2 && type > r1 && !bd1)
                    continue;
                S5f9_VertexPair edge = mesh->FUN_005b8900(idx, k);
                S5f9_Pt3 edgeDir = *edge.second - *edge.first;
                S5f9_Pt3 half(edgeDir.x * 0.5, edgeDir.y * 0.5, edgeDir.z * 0.5);
                S5f9_Pt3 mid = *edge.first + half;
                S5f9_Pt3 perp;
                perp = edgeDir.Cross(nrm);
                perp.z = 0;
                perp.FUN_00468d00();
                mid = mid - perp * p->GetScale();
                S5f9_Pt3 mid3 = mid;
                S5f9_Pt2 mid2(mid.x, mid.y);
                S5f9_Pt2 a2;
                a2.x = edge.first->x;
                a2.y = edge.first->y;
                S5f9_Pt2 b2v;
                b2v.x = edge.second->x;
                b2v.y = edge.second->y;
                if (!FUN_005dd4c0(mid2, v2, a2, b2v))
                    continue;
                S5f9_Portal portal(mid3, mesh->FUN_005b84c0(), idx);
                portal.Set(edge, perp);
                portal.FUN_00602020(type, r2, r1, b1, b2, k);
                unsigned int at = 0;
                if (result > 0)
                {
                    do
                    {
                        if (p->bcf)
                        {
                            if (dists.GetAt(at) < lenSq)
                                break;
                        }
                        else if (dists.GetAt(at) > lenSq)
                            break;
                    } while (++at < result);
                }
                dists.FUN_005f4460(at, lenSq);
                q->FUN_005f42a0(at, portal);
                if (++result >= p->maxCount)
                    return result;
            }
        }
    }
    return result;
}


}

// @f3 0x005f8280 (community match, verified in this file)
#include <windows.h>
#include <math.h>
extern __declspec(thread) int DAT_0117c298;
namespace f3m_005f8280 {
extern const char DAT_00db5c04, DAT_00dc4dc0;
extern const double DAT_00db7de8;
struct Vec {float x,y,z; Vec(){} Vec(float a,float b,float c):x(a),y(b),z(c){} float NiPoint3_UnitizeGetLength(); Vec operator*(float f) const {return Vec(x*f,y*f,z*f);} Vec operator-(const Vec& b) const {return Vec(x-b.x,y-b.y,z-b.z);} void Set(const Vec& o){x=o.x;y=o.y;z=o.z;} float LengthSquared() const {return x*x+y*y+z*z;} };
struct ContextScope {int previous; ContextScope(int v):previous(::DAT_0117c298){::DAT_0117c298=v;} ~ContextScope(){::DAT_0117c298=previous;} };
struct RefPart {virtual void v000(); virtual void Destroy(); long references; void Release(){if(!InterlockedDecrement(&references))Destroy();}};
struct Resource {int unk00,unk04,unk08,unk0C,unk10,unk14,unk18; RefPart ref; void IncRefCount(){InterlockedIncrement(&ref.references);} void DecRefCount(){ref.Release();} void* FUN_005b84c0(); void FUN_004d45e0(Vec&, unsigned short); Vec GetPoint(unsigned short i){Vec r;FUN_004d45e0(r,i);return r;}};
typedef NiPointer<Resource> ResourcePtr;
struct Reader {int unk00; Vec start; int unk10,unk14,unk18,unk1C,unk20,unk24,unk28;Vec end; bool FUN_005fcc10(); bool FUN_005fc8f0(ResourcePtr&,unsigned short&); void* PathingLocation_GetCell(); void* FUN_004c0120();};
struct Request {int unk00,unk04,unk08; Reader reader;};
struct Output {int unk00,unk04,unk08,unk0C,unk10,unk14; int unk18,unk1C; void FUN_005ec000(const Vec&,void*);};
struct Record {Resource* resource;unsigned short flags;unsigned short unk06;Vec position; void SetPosition(const Vec& c){position.x=c.x;position.y=c.y;position.z=c.z;} Vec GetPosition() const {Vec r;r.x=position.x;r.y=position.y;r.z=position.z;return r;}};
struct RecordArray {void* vtable; Record* data;unsigned size,capacity;void* allocator; RecordArray(int a,int b,int c){FUN_005d1bd0(a,b,c);} ~RecordArray(){FUN_005d0260();} void FUN_005d1bd0(int,int,int); void FUN_005d0260();};
struct ResultArray {void* vtable;void* data;unsigned size,capacity;void* allocator; ResultArray(int a,int b,int c){FUN_005d1c70(a,b,c);} ~ResultArray(){FUN_005d0360();} void FUN_005d1c70(int,int,int); void FUN_005d0360(); };
struct FinalArray {void* vtable;void* data;unsigned size,capacity;void* allocator;FinalArray(int a,int b,int c){FUN_005f43c0(a,b,c);} ~FinalArray(){FUN_005f3690();} void FUN_005f43c0(int,int,int);void FUN_005f3690();};
struct SearchSource {const void* table; Vec position;Vec direction;Resource* resource;int unk20;unsigned short index;unsigned char flags;unsigned char unk27; SearchSource(const Vec& p,Reader* r){FUN_005fd570(p,r);} ~SearchSource(){table=&DAT_00dc4dc0;} void FUN_005fd570(const Vec&,Reader*);bool FUN_005fda30(int);};
struct Filter {const void* table; void* data;int size,capacity; Filter():table(&DAT_00db5c04),data(0),size(0),capacity(0){} ~Filter(){FUN_0041ca00();} void FUN_0041ca00();};
struct SearchA {
void* vtable;
int unk004,unk008,unk00C,unk010;
void* buckets[2039];
int usedBuckets;
float lastCost;
void* unk1FF8;
void* unk1FFC;
void* unk2000;
void* unk2004;
void* unk2008;
void* unk200C;
void* unk2010;
void* unk2014;
void* unk2018;
void* unk201C;
void* unk2020;
void* unk2024;
void* unk2028;
void* unk202C;
void* unk2030;
void* unk2034;
void* unk2038;
void* unk203C;
void* unk2040;
void* unk2044;
int unk2048;
int unk204C;
int unk2050;
int unk2054;
int unk2058;
int unk205C;
int unk2060;
int unk2064;
int unk2068;
int unk206C;
int unk2070;
int unk2074;
int unk2078;
int unk207C;
int unk2080;
int unk2084;
int unk2088;
int unk208C;
int unk2090;
int unk2094;
int unk2098;
int unk209C;
int unk20A0;
int unk20A4;
int unk20A8;
SearchA(){FUN_005d0170();} ~SearchA(){FUN_005d01a0();} void FUN_005d0170();void FUN_005d01a0();
bool FUN_005d0840(Request*,const Record&,SearchSource*,RecordArray*,ResultArray*); };
struct SearchB {
void* vtable;
int unk004,unk008,unk00C,unk010;
void* buckets[2039];
int usedBuckets;
float lastCost;
void* unk1FF8;
void* unk1FFC;
void* unk2000;
void* unk2004;
void* unk2008;
void* unk200C;
void* unk2010;
void* unk2014;
void* unk2018;
void* unk201C;
void* unk2020;
void* unk2024;
void* unk2028;
void* unk202C;
void* unk2030;
void* unk2034;
void* unk2038;
void* unk203C;
void* unk2040;
void* unk2044;
int unk2048;
int unk204C;
int unk2050;
int unk2054;
int unk2058;
int unk205C;
int unk2060;
int unk2064;
int unk2068;
int unk206C;
int unk2070;
int unk2074;
int unk2078;
int unk207C;
int unk2080;
int unk2084;
int unk2088;
int unk208C;
int unk2090;
int unk2094;
int unk2098;
int unk209C;
int unk20A0;
int unk20A4;
int unk20A8;
int unk20AC;
int unk20B0;
int unk20B4;
int unk20B8;
int unk20BC;
int unk20C0;
int unk20C4;
int unk20C8;
int unk20CC;
int unk20D0;
int unk20D4;
int unk20D8;
int unk20DC;
int unk20E0;
int unk20E4;
int unk20E8;
int unk20EC;
int unk20F0;
int unk20F4;
int unk20F8;
int unk20FC;
int unk2100;
int unk2104;
int unk2108;
int unk210C;
SearchB(){FUN_005d3f30();} ~SearchB(){FUN_005d4080();} void FUN_005d3f30();void FUN_005d4080();
bool FUN_005d81b0(Request*,RecordArray*,ResultArray*,const Vec&,const Vec&,Output*,int,int); };
extern void __cdecl FUN_005f64f0(Filter*);
extern bool __cdecl FUN_005f1540(void*,void*,const Vec&,Vec&);
extern bool __cdecl FUN_005f8210(Request*,Output*);
struct Geometry {int flags; Vec start; int unk10,unk14,unk18,unk1C,unk20,unk24,unk28; Vec end;};
struct FullRequest {int unk000,unk004,unk008;Reader reader;int unk044;int unk048;int unk04C;int unk050;int unk054;int unk058;int unk05C;int unk060;int unk064;int unk068;int unk06C;int unk070;int unk074;int unk078;int unk07C;int unk080;int unk084;int unk088;int unk08C;int unk090;int unk094;int unk098;int unk09C;int unk0A0;int unk0A4;int unk0A8;int unk0AC;float radiusA,radiusB,minDistance,maxDistance; float GetRadiusA() const {return radiusA;} float GetRadiusB() const {return radiusB;} float GetMinDistance() const {return minDistance;} float GetMaxDistance() const {return maxDistance;}
};
bool FUN_005f8280(FullRequest* request,Output* output) {
 ContextScope context(45);
 Reader* reader=&request->reader;
 if(!reader->FUN_005fcc10())return false;
 ResourcePtr resource;
 unsigned short marker=0xffff;
 if(!reader->FUN_005fc8f0(resource,marker))return false;
 Vec start=request->reader.start;
 Vec destination=request->reader.end;
 float middle=(float)((request->GetRadiusA()+request->GetRadiusB())*DAT_00db7de8);
 float width;
 float distance;
 Vec projected;
 Vec adjusted;
 {
  // Scope block: the braces emit no code, but the match depends on them. They end the lifetime of
  // "direction" here, so the compiler packs it into the dead "start" copy's stack slot.
  Vec direction=destination-start;
  distance=direction.NiPoint3_UnitizeGetLength();
  adjusted.Set(destination-direction*middle);
  width=(float)fabs(middle-distance);
 }
 if(!FUN_005f1540(reader->FUN_004c0120(),reader->PathingLocation_GetCell(),adjusted,projected))return false;
 Vec delta=projected-adjusted;
 if(delta.LengthSquared()>width*width)return false;
 SearchSource source(projected,reader);
 Record selected;
 Record originRecord;
 originRecord.resource=resource;
 originRecord.flags=marker;
 originRecord.SetPosition(resource->GetPoint(marker));
 Vec origin=request->reader.start;
 if(!source.FUN_005fda30(0))source.flags|=2;
 SearchA search;
 RecordArray records(32,0,0);
 ResultArray results(32,0,0);
 *(float*)&search.unk20A4=width+width;
 Filter filter;
 FUN_005f64f0(&filter);
 Vec resultPosition;
 if(search.FUN_005d0840((Request*)request,originRecord,&source,&records,&results)) {
  selected=records.data[records.size-1];
  if(!((source.flags&2u)>0))resultPosition=projected;
  else resultPosition=selected.GetPosition();
 } else if(records.size) {
  selected=*(Record*)((char*)(void*)search.unk2048+8);
  resultPosition=selected.GetPosition();
 } else {
  if(request->GetMaxDistance()<distance)return FUN_005f8210((Request*)request,output);
  return false;
 }
 float maxDistance=request->maxDistance;
 float minDistance=request->minDistance;
 Vec deviation=resultPosition-destination;
 float squared=deviation.LengthSquared();
 if(squared<minDistance*minDistance || squared>maxDistance*maxDistance)return false;
 output->FUN_005ec000(origin,originRecord.resource->FUN_005b84c0());
 output->FUN_005ec000(resultPosition,selected.resource->FUN_005b84c0());
 output->unk18=0;output->unk1C=1;
 SearchB second;
 FinalArray finalRecords(32,0,0);
 return second.FUN_005d81b0((Request*)request,&records,&results,origin,resultPosition,output,0,0);
}
}

// @f3 0x005eee90 (community match, verified in this file)
namespace f3m_005eee90 {

extern bool DAT_01074858;
extern void* DAT_00e011f0;
extern void* DAT_00e011dc;
extern void* DAT_00db5c04;
extern void* DAT_00dc4dc0;

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    NiPoint3 operator-(const NiPoint3& pt) const { return NiPoint3(x - pt.x, y - pt.y, z - pt.z); }
    float SqrLength2D() const { float fX = x; float fY = y; return fX * fX + fY * fY; }
};
extern const NiPoint3 DAT_0108ec68;

struct NiRefObject {
    void** m_vtable;
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement(&m_uiRefCount)) ((void (__thiscall*)(NiRefObject*))m_vtable[1])(this); }
};

struct NavMeshInfo;

struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    NiRefObject kRef;
    void IncRefCount() { kRef.IncRefCount(); }
    void DecRefCount() { kRef.DecRefCount(); }
    NavMeshInfo* FUN_005b84c0();
};

struct PathingLocation {
    void* m_vtable;
    NiPoint3 Location;
    NavMeshInfo* pNavMeshInfo;
    void* pNavMeshes;
    void* pCell;
    void* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;
    PathingLocation(const PathingLocation& ar_Other);
    PathingLocation(const NiPoint3& ar_Location, NavMeshInfo* ap_NavMeshInfo, unsigned short a_usTriangle);
    PathingLocation(const NiPoint3& ar_Location, NavMeshInfo* ap_NavMeshInfo);
    ~PathingLocation() { m_vtable = &DAT_00dc4dc0; }
    PathingLocation& FUN_005fc480(const PathingLocation& ar_Other);
    bool FUN_005fc8b0(NiPointer<NavMesh>& ar_spNavMesh) const;
    NiPoint3 GetLocation() const { return Location; }
};

struct PathNode {
    unsigned int uiFlags;
    PathingLocation kLocation;
    int unk2C;
    bool IsFlagSet(unsigned int a_uiFlag) const { return (uiFlags & a_uiFlag) == a_uiFlag; }
};

struct PathPoint {
    int unk00;
    PathingLocation kLocation;
    NiPoint3 kDirection;
    int unk38;
    PathPoint(const PathingLocation& ar_Location, const NiPoint3& ar_Direction);
    NiPoint3 GetLocation() const { return kLocation.Location; }
};

struct PathRecord {
    NavMesh* pNavMesh;
    unsigned short usTriangle;
    NiPoint3 kPoint;
};

template <class T> struct SimpleArray {
    void** m_vtable;
    T* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    T* Allocate(unsigned int a_uiCount) { return ((T* (__thiscall*)(SimpleArray*, unsigned int))m_vtable[1])(this, a_uiCount); }
    void Deallocate(T* ap_Data) { ((void (__thiscall*)(SimpleArray*, T*))m_vtable[2])(this, ap_Data); }
    unsigned int GetSize() const { return uiSize; }
    T& operator[](unsigned int a_uiIndex) { return pBuffer[a_uiIndex]; }
    void FUN_00799ae0(unsigned int a_uiNewSize, unsigned int a_uiCount);
    unsigned int GetNextIndex() {
        if (uiSize == uiAllocSize) {
            if (!uiAllocSize) {
                pBuffer = Allocate(4);
                uiAllocSize = 4;
            } else {
                unsigned int uiNewSize = uiAllocSize > 0x400 ? uiAllocSize + 0x400 : uiAllocSize * 2;
                FUN_00799ae0(uiNewSize, uiSize);
                uiAllocSize = uiNewSize;
            }
        }
        ++uiSize;
        return uiSize - 1;
    }
};

struct NavMeshInfoArray : SimpleArray<NavMeshInfo*> {
    void RemoveAll() { if (pBuffer) uiSize = 0; }
    void Add(NavMeshInfo* ap_Info) { pBuffer[GetNextIndex()] = ap_Info; }
};

struct NavMeshArray : SimpleArray<NiPointer<NavMesh> > {
    NavMeshArray() { m_vtable = (void**)&DAT_00db5c04; pBuffer = 0; uiSize = 0; uiAllocSize = 0; }
    __forceinline ~NavMeshArray() {
        m_vtable = (void**)&DAT_00db5c04;
        if (pBuffer) {
            DestroyItems(pBuffer, uiSize);
            Deallocate(pBuffer);
            pBuffer = 0;
            uiAllocSize = 0;
            uiSize = 0;
        }
    }
    static __forceinline void DestroyItems(NiPointer<NavMesh>* ap_Data, unsigned int a_uiCount) {
        for (unsigned int i = 0; i < a_uiCount; ++i)
            ap_Data[i].~NiPointer<NavMesh>();
    }
    void FUN_00415f50(NiPointer<NavMesh>* ap_Data, unsigned int a_uiCount);
    void FUN_0041a4b0(const NiPointer<NavMesh>& ar_spNavMesh);
    void RemoveAll() {
        if (pBuffer) {
            FUN_00415f50(pBuffer, uiSize);
            uiSize = 0;
        }
    }
    int Find(const NiPointer<NavMesh>& ar_spNavMesh) {
        for (unsigned int i = 0; i < uiSize; ++i) {
            if (pBuffer && pBuffer[i] == ar_spNavMesh)
                return i;
        }
        return -1;
    }
    void Add(const NiPointer<NavMesh>& ar_spNavMesh) {
        unsigned int uiIndex = GetNextIndex();
        new (&pBuffer[uiIndex]) NiPointer<NavMesh>;
        pBuffer[uiIndex] = ar_spNavMesh;
    }
};

struct IndexArray : SimpleArray<unsigned int> {
    IndexArray(unsigned int a_uiCount) {
        m_vtable = (void**)&DAT_00e011f0;
        pBuffer = 0;
        uiSize = 0;
        uiAllocSize = 0;
        pBuffer = Allocate(a_uiCount);
        uiAllocSize = a_uiCount;
    }
    ~IndexArray() {
        m_vtable = (void**)&DAT_00e011f0;
        if (pBuffer) {
            Deallocate(pBuffer);
            pBuffer = 0;
            uiAllocSize = 0;
            uiSize = 0;
        }
    }
};

struct RecordArray : SimpleArray<PathRecord> {
    RecordArray(unsigned int a_uiCount) {
        m_vtable = (void**)&DAT_00e011dc;
        pBuffer = 0;
        uiSize = 0;
        uiAllocSize = 0;
        pBuffer = Allocate(a_uiCount);
        uiAllocSize = a_uiCount;
    }
    ~RecordArray() {
        m_vtable = (void**)&DAT_00e011dc;
        if (pBuffer) {
            Deallocate(pBuffer);
            pBuffer = 0;
            uiAllocSize = 0;
            uiSize = 0;
        }
    }
};

struct PathPointArray : SimpleArray<PathPoint> {
    void FUN_005c4fa0(unsigned int a_uiNewSize, unsigned int a_uiCount);
    void FUN_005eb2f0(unsigned int a_uiIndex, bool a_bShrink);
    PathPoint* GetLast() { return &pBuffer[uiSize - 1]; }
    unsigned int GetNextIndex() {
        if (uiSize == uiAllocSize) {
            if (!uiAllocSize) {
                pBuffer = Allocate(4);
                uiAllocSize = 4;
            } else {
                unsigned int uiNewSize = uiAllocSize > 0x400 ? uiAllocSize + 0x400 : uiAllocSize * 2;
                FUN_005c4fa0(uiNewSize, uiSize);
                uiAllocSize = uiNewSize;
            }
        }
        unsigned int uiIndex = ++uiSize - 1;
        return uiIndex;
    }
};

struct PathingSolution {
    void* unk00;
    void* unk04;
    void* unk08;
    PathNode* pNodes;
    unsigned int uiNodeCount;
    unsigned int unk14;
    int unk18;
    unsigned int uiGoalNode;
    PathPointArray kPoints;
    int unk30, unk34, unk38, unk3C;
    bool bPartial;
    unsigned int GetNodeCount() const { return uiNodeCount; }
    void SetPartial() { bPartial = true; }
    PathPoint* GetLastPoint() { return !kPoints.GetSize() ? 0 : kPoints.GetLast(); }
    // appending, the last point and the partial flag go through members of PathingSolution: the copied this keeps
    // pSolution in a register the way the target does
    void AddPoint(const PathingLocation& ar_Location) { new (&kPoints[kPoints.GetNextIndex()]) PathPoint(ar_Location, DAT_0108ec68); }
};

struct PathingRequest {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70;
    float fTargetRadius;
    int unk78, unk7C, unk80, unk84, unk88, unk8C, unk90;
    int unk94;
    bool unk98, unk99, unk9A, bAllowPartial;
    int unk9C;
    bool unkA0, unkA1, unkA2, unkA3;
    int unkA4;
    int iMaxAttempts;
};

bool __cdecl FUN_005f64f0(NavMeshArray* ap_Array);

struct PathBuilder {
    PathingRequest* pRequest;
    PathingSolution* pSolution;
    int unk08, unk0C, unk10;
    NavMeshInfoArray kNavMeshInfos;
    NavMeshArray kNavMeshes;

    bool FUN_005ec510(const PathingLocation& ar_Start, const PathingLocation& ar_Goal);
    bool FUN_005eada0(const PathingLocation& ar_Start, const PathingLocation& ar_Goal, IndexArray* ap_Indices,
                      RecordArray* ap_Records, IndexArray* ap_Triangles, int a_iStartNode, int a_iGoalNode);
    bool FUN_005ed960(PathingLocation* ap_Start, PathingLocation* ap_Goal, IndexArray* ap_Indices,
                      RecordArray* ap_Records, IndexArray* ap_Triangles);
    int FUN_005eee90(const PathingLocation& ar_Start, const PathingLocation& ar_Goal, int a_iStartNode, int a_iGoalNode);
};

int PathBuilder::FUN_005eee90(const PathingLocation& ar_Start, const PathingLocation& ar_Goal, int a_iStartNode, int a_iGoalNode)
{
    if (DAT_01074858 && !pRequest->unk94 && !pRequest->unk99 && !pRequest->unkA2 && FUN_005ec510(ar_Start, ar_Goal))
        return 0;

    IndexArray kIndices(0x20);
    bool bPartial = false;
    int iMaxAttempts = pRequest->iMaxAttempts;
    if (iMaxAttempts > 10)
        iMaxAttempts = 10;
    else if (iMaxAttempts < 1)
        iMaxAttempts = 1;

    kNavMeshInfos.RemoveAll();
    kNavMeshes.RemoveAll();
    for (unsigned int i = 0; i < pSolution->GetNodeCount(); ++i) {
        NiPointer<NavMesh> spNavMesh;
        PathNode& rNode = pSolution->pNodes[i];
        if (rNode.kLocation.FUN_005fc8b0(spNavMesh)) {
            kNavMeshes.FUN_0041a4b0(spNavMesh);
            kNavMeshInfos.Add(spNavMesh->FUN_005b84c0());
        }
    }

    for (int iAttempt = 0; iAttempt < iMaxAttempts; ++iAttempt) {
        if (iAttempt == 1) {
            NavMeshArray kExtra;
            FUN_005f64f0(&kExtra);
            for (unsigned int k = 0; k < kExtra.GetSize(); ++k) {
                NiPointer<NavMesh>& rMesh = kExtra[k];
                if (kNavMeshes.Find(rMesh) == -1) {
                    kNavMeshes.Add(rMesh);
                    kNavMeshInfos.Add(kExtra[k]->FUN_005b84c0());
                }
            }
        }

        RecordArray kRecords(0x20);
        IndexArray kTriangles(0x20);
        PathingLocation kStart(ar_Start);
        PathingLocation kGoal(ar_Goal);
        if (!FUN_005eada0(ar_Start, ar_Goal, &kIndices, &kRecords, &kTriangles, a_iStartNode, a_iGoalNode)) {
            if (!kRecords.GetSize()) {
                if (iAttempt >= 1)
                    return 2;
                continue;
            }
            PathRecord& rLast = kRecords[kRecords.GetSize() - 1];
            PathingLocation kLast(NiPoint3(rLast.kPoint.x, rLast.kPoint.y, rLast.kPoint.z), rLast.pNavMesh->FUN_005b84c0(), rLast.usTriangle);
            if (pSolution->uiGoalNode == (unsigned int)a_iGoalNode) {
                PathNode& rGoal = pSolution->pNodes[a_iGoalNode];
                NiPoint3 kDelta = kLast.Location - rGoal.kLocation.GetLocation();
                unsigned int uiLoose = rGoal.uiFlags & 4;
                float fRadius = uiLoose ? 80.0f : pRequest->fTargetRadius;
                if (kDelta.SqrLength2D() < fRadius * fRadius && (float)fabs(kDelta.z) < 180.0f) {
                    if (!pRequest->bAllowPartial)
                        return 2;
                    if (uiLoose != 4) {
                        bPartial = true;
                        pSolution->bPartial = true;
                    }
                } else {
                    if (iAttempt == 0)
                        continue;
                    bPartial = true;
                    pSolution->bPartial = true;
                }
            } else {
                bPartial = true;
                pSolution->bPartial = true;
            }
            if (!pRequest->bAllowPartial)
                return 2;
            kGoal.FUN_005fc480(kLast);
        }

        {
            unsigned int uiSaved = pSolution->kPoints.GetSize();
            if (!FUN_005ed960(&kStart, &kGoal, &kIndices, &kRecords, &kTriangles)) {
                if (iAttempt == iMaxAttempts - 1 && pRequest->unkA3) {
                    pSolution->SetPartial();
                    bPartial = true;
                    for (unsigned int k = 0; k < kRecords.GetSize(); ++k) {
                        PathingLocation kLocation(NiPoint3(kRecords.pBuffer[k].kPoint.x, kRecords.pBuffer[k].kPoint.y, kRecords.pBuffer[k].kPoint.z), kRecords.pBuffer[k].pNavMesh->FUN_005b84c0());
                        pSolution->AddPoint(kLocation);
                    }
                } else {
                    PathPoint* pLast = pSolution->GetLastPoint();
                    if (pLast && pSolution->uiGoalNode == (unsigned int)a_iGoalNode) {
                        PathNode& rGoal = pSolution->pNodes[a_iGoalNode];
                        NiPoint3 kDelta = pLast->GetLocation() - rGoal.kLocation.GetLocation();
                        float fRadius = rGoal.IsFlagSet(4) ? 80.0f : pRequest->fTargetRadius;
                        if (kDelta.SqrLength2D() < fRadius * fRadius && (float)fabs(kDelta.z) < 180.0f)
                            break;
                    }

                    if (!kIndices.GetSize() || iAttempt == iMaxAttempts - 1) {
                        if (pLast) {
                            pSolution->SetPartial();
                            if (pRequest->bAllowPartial)
                                return 1;
                            while (pSolution->kPoints.GetSize() != uiSaved) {
                                PathingSolution* pSol = pSolution;
                                pSol->kPoints.FUN_005eb2f0(pSol->kPoints.GetSize() - 1, true);
                            }
                            return 2;
                        }
                        return 2;
                    } else {
                        if (iAttempt < iMaxAttempts - 1) {
                            while (pSolution->kPoints.GetSize() != uiSaved) {
                                PathingSolution* pSol = pSolution;
                                pSol->kPoints.FUN_005eb2f0(pSol->kPoints.GetSize() - 1, true);
                            }
                        }
                        continue;
                    }
                }
            }
        }
        break;
    }

    if (bPartial)
        return 1;
    return 0;
}

}

// @f3 0x005fb9e0 (community match, verified in this file)
namespace w5fb9e0 {
extern __declspec(thread) int DAT_0117c298;
struct AllocTagScope {
    int saved;
    AllocTagScope() : saved(DAT_0117c298) { DAT_0117c298 = 45; }
    ~AllocTagScope() { DAT_0117c298 = saved; }
};
struct Vec3 {
    float x, y, z;
    Vec3& operator+=(const Vec3& o) { x = x + o.x; y = y + o.y; z = z + o.z; return *this; }
    Vec3& operator*=(double s) { x = (float)(x * s); y = (float)(y * s); z = (float)(z * s); return *this; }
};
struct RefCounted {
    void** vtable;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() {
        if (!InterlockedDecrement(&refs))
            ((void (__thiscall*)(RefCounted*))vtable[1])(this);
    }
};
struct NavMeshInfo;
struct NavMeshTriangle {
    unsigned short vertices[3];
    unsigned short edges[3];
    unsigned int flags;
};
struct NavMesh {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefCounted ref1C;
    int unk24, unk28;
    Vec3* vertices;
    int unk30, unk34;
    void* trianglesVtbl;
    NavMeshTriangle* triangles;
    void IncRefCount() { ref1C.IncRefCount(); }
    void DecRefCount() { ref1C.DecRefCount(); }
    Vec3 FUN_004d45e0(unsigned short triangle) const;
    NavMeshInfo* FUN_005b84c0();
};
// NavMesh::FUN_004d45e0 (the centre of a triangle: the mean of its three vertices) is a small leaf function that
// the target calls out of line. Its real body is given here, as in the matched sibling 0x005f5590 of this unit,
// because the compiler uses what a visible callee does: knowing that this call writes only its result, it keeps
// `triangle` and `mesh` (both passed by address to FUN_005fff00 earlier) in esi/ebp across it instead of reading
// them from the stack again. The body emits its own code and is not part of the compared function.
Vec3 NavMesh::FUN_004d45e0(unsigned short triangle) const {
    const NavMeshTriangle* t = &triangles[triangle];
    Vec3 center = vertices[t->vertices[0]];
    center += vertices[t->vertices[1]];
    center += vertices[t->vertices[2]];
    center *= 1.0 / 3.0;
    return center;
}
extern int DAT_00dc4dc0;
struct PathingLocation {
    void* vtable;
    Vec3 location;
    NavMeshInfo* navMeshInfo;
    void* navMeshes;
    void* cell;
    void* worldSpace;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    PathingLocation(const Vec3& location, const NavMeshInfo* info, unsigned short triangle);
    ~PathingLocation() { vtable = &DAT_00dc4dc0; }
    PathingLocation& FUN_005fc480(const PathingLocation& other);
    bool FUN_005fcc10();
    bool FUN_005fc8f0(NiPointer<NavMesh>* mesh, int* triangle);
    Vec3 GetLocation() const { return location; }
};
struct Request {
    int unk00, unk04, unk08;
    PathingLocation start;
    PathingLocation goal;
    PathingLocation* GetStart() { return &start; }
};
struct RequestCopy {
    void* vtable;
    int unk04, unk08;
    PathingLocation start;
    PathingLocation goal;
    int unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    RequestCopy(Request* source);
    ~RequestCopy();
};
struct SolutionEntry {
    int flags;
    PathingLocation location;
    int unk2C;
    void FUN_006102e0(const PathingLocation& location);
};
struct PathingSolution {
    int unk00, unk04, unk08;
    SolutionEntry* data;
    unsigned int count;
    int unk14;
    unsigned int beginIndex, endIndex;
    void FUN_005ec000(const Vec3& point, NavMeshInfo* info);
    void FUN_00605ed0();
};
struct MeshTriangle {
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    int unk08, unk0C, unk10;
};
typedef ::BSScrapArray<NavMeshSearchNode, 1024> NodeArray;
typedef ::BSScrapArray<NavMeshSearchLink, 1024> LinkArray;
struct SearchLocation {
    bool FUN_005fff00(NiPointer<NavMesh>* mesh, int* triangle);
};
struct Pad10 { int a, b, c, d; };
struct Pad100 { Pad10 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p; };
struct Pad1000 { Pad100 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p; };
struct NavMeshSearchLOS {
    void* vtable;
    Pad1000 unk0004, unk1004;
    Pad10 unk2004, unk2014, unk2024, unk2034, unk2044, unk2054;
    int unk2064, unk2068;
    int unk206C;
    SearchLocation* unk2070;
    int unk2074, unk2078, unk207C, unk2080, unk2084, unk2088;
    char unk208C;
    void* unk2090;
    void* unk2094;
    void* unk2098;
    float unk209C;
    NavMeshSearchLOS();
    ~NavMeshSearchLOS();
    bool FUN_005cfe10(Request* request, MeshTriangle& start, NodeArray& nodes, LinkArray& links);
    bool FUN_005ccbc0(void* target, NodeArray& nodes, LinkArray& links);
};
bool __cdecl FUN_005fb8c0(RequestCopy* request, PathingSolution* solution);

bool __cdecl FUN_005fb9e0(Request* request, PathingSolution* solution)
{
    AllocTagScope scope;
    if (!request->GetStart()->FUN_005fcc10())
        return false;
    NiPointer<NavMesh> startMesh;
    int startTriangle = 0xffff;
    if (!request->GetStart()->FUN_005fc8f0(&startMesh, &startTriangle))
        return false;
    MeshTriangle s;
    s.mesh = startMesh;
    s.triangle = (unsigned short)startTriangle;
    Vec3 p = request->GetStart()->GetLocation();
    bool partial1 = false;
    bool partial2 = false;
    bool result;
    NavMeshSearchLOS search;
    NodeArray nodes(0x20, 0, 0);
    LinkArray links(0x20, 0, 0);
    bool found;
    if (search.FUN_005cfe10(request, s, nodes, links)
        || (search.unk2090 && (partial1 = search.FUN_005ccbc0(search.unk2090, nodes, links)) != false)
        || (search.unk2094 && (partial2 = search.FUN_005ccbc0(search.unk2094, nodes, links)) != false)
        || (search.unk2098 && (partial2 = search.FUN_005ccbc0(search.unk2098, nodes, links)) != false)) {
        found = true;
        NavMeshSearchNode h = nodes.Last();
        NavMesh* m = (NavMesh*)h.geom;
        Vec3 e = m->FUN_004d45e0(h.tri);
        solution->FUN_00605ed0();
        RequestCopy copy(request);
        PathingLocation goal(e, m->FUN_005b84c0(), h.tri);
        copy.goal.FUN_005fc480(goal);
        result = FUN_005fb8c0(&copy, solution);
    }
    else {
        found = false;
        result = false;
    }
    if (!found || (!result && (partial1 || partial2))) {
        NiPointer<NavMesh> mesh;
        int triangle = 0;
        if (search.unk2070->FUN_005fff00(&mesh, &triangle)) {
            unsigned int index = solution->endIndex;
            if (index == 0xffffffff || !solution->count) {
                solution->FUN_005ec000(p, s.mesh->FUN_005b84c0());
                solution->endIndex = 0;
            }
            SolutionEntry* entry = &solution->data[index];
            if (entry) {
                Vec3 q = mesh->FUN_004d45e0(triangle);
                PathingLocation loc(q, mesh->FUN_005b84c0(), triangle);
                entry->FUN_006102e0(loc);
            }
        }
    }
    return result;
}
}

// @f3 0x005e7ed0 (community match, verified in this file)
namespace f3m_005e7ed0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long index, void* value);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
namespace f3m_005e7ed0 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float SquaredLength() const { return x * x + y * y + z * z; }
};
struct __declspec(align(16)) Vec4 { float x,y,z,w; Vec4() {} };
struct Target {
    virtual void Destroy();
    virtual void DeleteThis();
    volatile long refCount;
    unsigned int unk08; unsigned int unk0C;
    Vec3 position;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
};
struct ItemData {
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00C; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01C; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02C; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03C; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04C; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05C; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06C; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07C; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08C; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09C; unsigned int unk0A0; unsigned int unk0A4; unsigned int unk0A8; unsigned int unk0AC; unsigned int unk0B0; unsigned int unk0B4; unsigned int unk0B8; unsigned int unk0BC; unsigned int unk0C0; unsigned int unk0C4; unsigned int unk0C8; unsigned int unk0CC; unsigned int unk0D0; unsigned int unk0D4; unsigned int unk0D8; unsigned int unk0DC; unsigned int unk0E0; unsigned int unk0E4; unsigned int unk0E8; unsigned int unk0EC; unsigned int unk0F0; unsigned int unk0F4; unsigned int unk0F8; unsigned int unk0FC; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10C;
    Vec4 bound;
};
struct Item { unsigned int unk00; unsigned int unk04; ItemData* data; };
struct Worker { void FUN_005e6cd0(Item** out); };
struct Factory {
    virtual void f00();
    virtual Worker* Create(unsigned int index);
    virtual void f08();
    virtual void f0C();
    virtual unsigned int Count();
};
struct ThreadSlot { unsigned long threadId; Worker* worker; };
struct ThreadCache {
    unsigned int capacity; unsigned long tlsIndex; ThreadSlot* slots; volatile long used;
    Worker* Get(Factory* factory) {
        Worker* worker = (Worker*)TlsGetValue(tlsIndex);
        if (!worker) {
            Worker* created=0;
            volatile long* ref=&used; unsigned int index = InterlockedIncrement(ref) - 1;
            if (index < capacity) {
                created = factory->Create(index);
                slots[index].worker = created;
                slots[index].threadId = GetCurrentThreadId();
                unsigned long tls = *(volatile unsigned long*)&tlsIndex; TlsSetValue(tls, created);

            }
            return created;
        }
        return worker;
    }
};
struct TargetMap { bool FUN_005c8b00(Item* item, NiPointer<Target>* out); };
struct TargetList { void FUN_004c25a0(NiPointer<Target>* target); };
const double kScale = 6.999040126800537;
const double kMinDistSq = 25.0;
struct Owner {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C; unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C; unsigned int unk30; unsigned int unk34; unsigned int unk38;
    TargetList targets; unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
    Factory factory; unsigned int unk64; unsigned int unk68; unsigned int unk6C; unsigned int unk70;
    ThreadCache* cache; unsigned int unk78;
    TargetMap map;
    void FUN_005e77d0(NiPointer<Target>* target);
    void FUN_005e7ed0();
};
__declspec(noinline) void Worker::FUN_005e6cd0(Item** out) { *out = (Item*)this; }
// pdb: NavMeshObstacleManager::ProcessDeactivatedObstacles | NavMeshObstacleManager.obj | fnv360_0822_retail, call_dedup, low
__declspec(noinline) void Owner::FUN_005e7ed0()
{
    unsigned int count = factory.Count();
    for (unsigned int i = 0; i < count; ++i) {
        Worker* worker = cache->Get(&factory);
        Item* result;
        worker->FUN_005e6cd0(&result);
        NiPointer<Target> target;
        Item* item=result;
        if (map.FUN_005c8b00(item, &target)) {
            Vec4 bound;
            bound.x=item->data->bound.x;
            bound.y=item->data->bound.y;
            bound.z=item->data->bound.z;
            *(volatile float*)&bound.w = item->data->bound.w;
            Vec3 center;
            center.x=(float)(bound.x*kScale);
            center.y=(float)(bound.y*kScale);
            center.z=(float)(bound.z*kScale);
            Vec3 diff = center - target->position;
            if (diff.SquaredLength() > kMinDistSq)
                FUN_005e77d0(&target);
            targets.FUN_004c25a0(&target);
        }
    }
}
}
}   // namespace f3m_005e7ed0

// @f3 0x005f50d0 (community match, verified in this file)
namespace f3m_005f50d0 {
// 0x005f50d0 Pathing::BuildLowPath: New Vegas twin @fnv 0x006d4f70, fnv_decomp src\fallout_shared\doorlock.cpp
// ("pdb: Pathing::BuildLowPath | Pathfind.obj"; params aOrigin, aDestination, apRetPath, apActorLockData,
// aeDoorLockDisp; locals teleSearch, infos, doors, infoSearch, space, i, link, nextSpace). Written fresh from the twin.
// Searches the navmesh-info graph from origin to destination; on success fills the path with the parent spaces
// (world space or interior cell of each navmesh info) and the teleport doors between them, else falls back to the
// teleport-door search.
class TESForm
{
public:
    virtual ~TESForm();
};
class TESWorldSpace : public TESForm
{
};
class TESObjectREFR;

namespace w5f50d0 {

// Gamebryo NiPoint3 (12 bytes) with its constructors.
struct NiPoint3
{
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
};

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormID);   // LookupFormByID

// NavMeshInfo (twin include\NavMeshInfo.h; only the members this function reaches)
class NavMeshInfo
{
public:
    unsigned int NavMeshID;
    unsigned int ParentSpaceID;
    unsigned int uiFlags;
    int iCellKey;
    NiPoint3 ApproxLocation;
    TESForm* pParentSpace;

    TESForm* GetParentSpace() const { return pParentSpace ? pParentSpace : TESForm_GetFormByNumericID(ParentSpaceID); }
    TESWorldSpace* FUN_005b8450() const;   // GetParentWorldSpace
    TESObjectCELL* FUN_005d96e0() const;   // GetInteriorCell
};
TESWorldSpace* NavMeshInfo::FUN_005b8450() const
{
    return dynamic_cast<TESWorldSpace*>(GetParentSpace());
}
TESObjectCELL* NavMeshInfo::FUN_005d96e0() const
{
    return dynamic_cast<TESObjectCELL*>(GetParentSpace());
}

// BSSimpleArray<T,1024>: vtable pointer, buffer, size, allocated size (16 bytes).
template <class T, unsigned int RESIZE_SIZE = 1024>
class BSSimpleArray
{
public:
    void** m_ppVTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;

    unsigned int AddUninitialized();
    unsigned int Add(const T& aItem)
    {
        unsigned int uiIndex = AddUninitialized();
        pBuffer[uiIndex] = aItem;
        return uiIndex;
    }
};
class NavMeshInfoArray;
class RefrArray;
}

// The two arrays this function owns are written the way this unit's matched siblings write them
// (f3m_005ec900::NavMeshInfoArray, match5eb5e0::Base): the vtable stored by hand, its _Deallocate slot called through
// the slot.
extern void* DAT_00dd8fe4[];   // BSSimpleArray<const NavMeshInfo*,1024> vftable
extern void* DAT_00dd8fd0[];   // BSSimpleArray<TESObjectREFR*,1024> vftable
extern void (__thiscall* DAT_00dd8fec)(w5f50d0::NavMeshInfoArray*, void*);   // its _Deallocate slot
extern void (__thiscall* DAT_00dd8fd8)(w5f50d0::RefrArray*, void*);          // its _Deallocate slot

namespace w5f50d0 {

// BSSimpleArray<const NavMeshInfo*,1024>
class NavMeshInfoArray
{
public:
    void** m_ppVTable;
    const NavMeshInfo** pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    NavMeshInfoArray() : m_ppVTable(DAT_00dd8fe4), pBuffer(0), iSize(0), iAllocSize(0) {}
    ~NavMeshInfoArray()   // 0x0053a0e0
    {
        void* pData = pBuffer;
        m_ppVTable = DAT_00dd8fe4;
        if (pData)
        {
            DAT_00dd8fec(this, pData);
            pBuffer = 0;
            iAllocSize = 0;
            iSize = 0;
        }
    }
    const NavMeshInfo*& operator[](unsigned int auiIndex) { return pBuffer[auiIndex]; }
};

// BSSimpleArray<TESObjectREFR*,1024>
class RefrArray
{
public:
    void** m_ppVTable;
    TESObjectREFR** pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    RefrArray() : m_ppVTable(DAT_00dd8fd0), pBuffer(0), iSize(0), iAllocSize(0) {}
    ~RefrArray()   // 0x0053a0b0
    {
        void* pData = pBuffer;
        m_ppVTable = DAT_00dd8fd0;
        if (pData)
        {
            DAT_00dd8fd8(this, pData);
            pBuffer = 0;
            iAllocSize = 0;
            iSize = 0;
        }
    }
    unsigned int GetSize() const { return iSize; }
    TESObjectREFR*& operator[](unsigned int auiIndex) { return pBuffer[auiIndex]; }
};

struct TeleportData
{
    const NiPoint3& FUN_00bd8090();   // position of the linked door
};
}

class TESObjectREFR
{
public:
    w5f50d0::TeleportData* TESObjectREFR_GetTeleport();   // GetTeleport
};

namespace w5f50d0 {

// pdb: structure ParentSpaceNode, size 0xc
struct ParentSpaceNode
{
    bool bWorldSpace;
    TESWorldSpace* pWorldSpace;
    TESObjectCELL* pInteriorCell;
};

struct TeleportLink
{
    TESObjectREFR* pDoor;
    NiPoint3 kLocation;
};

// twin include\PathingPath.h
class PathingPath
{
public:
    BSSimpleArray<ParentSpaceNode> Spaces;
    BSSimpleArray<TeleportLink> Doors;
    NiPoint3 Start;
    NiPoint3 End;
};

class FindTriangleForLocationFilter;
class PathingActorData;

// pdb: class PathingLocation, size 0x28 (twin include\PathingLocation.h)
class PathingLocation
{
public:
    virtual void SaveGame(void* apBuffer);
    virtual void LoadGame(void* apBuffer);

    NiPoint3 Location;
    const NavMeshInfo* pNavMesh;
    const NavMeshInfoArray* pNavMeshes;
    TESObjectCELL* pCell;
    TESWorldSpace* pWorldSpace;
    unsigned int iCellKey;
    unsigned short usTriangle;
    unsigned char uiFlags;
    unsigned char unk27;

    NiPoint3 GetLocation() const { return Location; }
    const NavMeshInfo* GetNavMeshInfo() const { return pNavMesh; }
    bool FUN_005fda30(FindTriangleForLocationFilter* apFilter);   // FindContainingTriangle
};

// AStarSearch<NodeData, LinkData> storage (twin astarsearch_decls.h / include\AStarSearch.h), 0x2058 bytes.
struct AStarNodeAllocator
{
    unsigned int unk00, unk04, unk08, unk0C;
};
struct AStarNodeHashTable
{
    void* m_ppNodes[2039];
    unsigned int iCount;
};
struct AStarOpenList
{
    float m_fValue;
    void* m_ppNodes[20];
};
class AStarSearch
{
public:
    virtual ~AStarSearch();
    AStarNodeAllocator m_kNodeAllocator;
    AStarNodeHashTable m_kNodeHashTable;
    AStarOpenList m_kOpenList;
    void* m_pFirstNode;
    void* m_pCurrentNode;
    void* m_pLastCreatedNode;
    bool m_bUseBestNode;
};

// pdb: class NavMeshInfoSearch, size 0x209c (twin include\NavMeshInfoSearch.h)
class NavMeshInfoSearch : public AStarSearch
{
public:
    NavMeshInfoSearch();    // 0x005dbb40
    ~NavMeshInfoSearch();   // 0x005dbbb0
    bool FUN_005dc8d0(PathingActorData* apActorLockData, const NiPoint3& aStartLocation, const NavMeshInfo* apStartMesh,
                      const NiPoint3& aGoalLocation, const NavMeshInfo* apGoalMesh, NavMeshInfoArray& arReturnNodes,
                      RefrArray& arReturnLinks, int aeDoorLockDisposition);   // Pathfind

    NiPoint3 m_kPathStartPosition;
    const NavMeshInfo* m_pStartNavMeshInfo;
    NiPoint3 m_kGoalPosition;
    const NavMeshInfo* m_pGoalNavMeshInfo;
    PathingActorData* m_pPathingActorData;
    int m_eDoorLockDisposition;
    bool m_bUseGoalDistanceHeuristic;
    unsigned int unk2084, unk2088, unk208C, unk2090, unk2094, unk2098;
};

// pdb: class TeleportDoorSearch, size 0x20b8 (twin include\TeleportDoorSearch.h)
class TeleportDoorSearch : public AStarSearch
{
public:
    TeleportDoorSearch();    // 0x0060f170
    ~TeleportDoorSearch();   // 0x0060f1f0
    bool FUN_0060fa90(PathingLocation* aStartLocation, PathingLocation* aGoalLocation, PathingPath* apRetPath,
                      int aRestrictions, float afMaxDist, PathingActorData* apLockData, int aDisposition);   // BuildNodePath

    unsigned int unk2058;
    TESWorldSpace* startWorld;
    unsigned int unk2060;
    PathingLocation StartLocation;
    bool GoalNode;
    TESWorldSpace* world;
    TESObjectCELL* cell;
    int Restrictions;
    float fMaxDist;
    const PathingActorData* pLockData;
    RefrArray DoorList;
    int DoorLockDisposition;
};

bool __cdecl FUN_005f50d0(PathingLocation* aOrigin, PathingLocation* aDestination, PathingPath* apRetPath,
                          PathingActorData* apActorLockData, int aeDoorLockDisp);
}

// pdb: Pathing::BuildLowPath | Pathfind.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aOrigin, aDestination, apRetPath, apActorLockData, aeDoorLockDisp
bool __cdecl w5f50d0::FUN_005f50d0(PathingLocation* aOrigin, PathingLocation* aDestination, PathingPath* apRetPath,
                                   PathingActorData* apActorLockData, int aeDoorLockDisp)
{
    if (aOrigin->FUN_005fda30(0) && aDestination->FUN_005fda30(0))
    {
        NavMeshInfoSearch infoSearch;
        NavMeshInfoArray infos;
        RefrArray doors;
        if (infoSearch.FUN_005dc8d0(apActorLockData, aOrigin->GetLocation(), aOrigin->GetNavMeshInfo(),
                                    aDestination->GetLocation(), aDestination->GetNavMeshInfo(), infos, doors,
                                    aeDoorLockDisp))
        {
            ParentSpaceNode space;
            space.pWorldSpace = infos[0]->FUN_005b8450();
            space.pInteriorCell = infos[0]->FUN_005d96e0();
            space.bWorldSpace = infos[0]->FUN_005b8450() != 0;
            apRetPath->Spaces.Add(space);
            for (unsigned int i = 0; i < doors.GetSize(); ++i)
            {
                if (doors[i])
                {
                    TeleportLink link;
                    link.pDoor = doors[i];
                    link.kLocation = doors[i]->TESObjectREFR_GetTeleport()->FUN_00bd8090();
                    apRetPath->Doors.Add(link);
                    ParentSpaceNode nextSpace;
                    nextSpace.pWorldSpace = infos[i + 1]->FUN_005b8450();
                    nextSpace.pInteriorCell = infos[i + 1]->FUN_005d96e0();
                    nextSpace.bWorldSpace = infos[i + 1]->FUN_005b8450() != 0;
                    apRetPath->Spaces.Add(nextSpace);
                }
            }
            apRetPath->Start = aOrigin->GetLocation();
            apRetPath->End = aDestination->GetLocation();
            return true;
        }
    }
    TeleportDoorSearch teleSearch;
    return teleSearch.FUN_0060fa90(aOrigin, aDestination, apRetPath, 0, 0.0f, apActorLockData, aeDoorLockDisp);
}
}   // namespace f3m_005f50d0

// @f3 0x005fe820 (community match, verified in this file)
extern int DAT_00e022a4;
namespace f3m_005fe820 {
namespace f3m_005fe820 {
extern void (__stdcall* DAT_00e022ac)(void*);
struct SimpleArray {
    void* vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    void FUN_005fe820();
};
void SimpleArray::FUN_005fe820() {
    vtable = &DAT_00e022a4;
    if (data) {
        DAT_00e022ac(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}
}
}   // namespace f3m_005fe820

// @f3 0x005fe800 (community match, verified in this file)
extern void* g_heap_005fe800;
namespace f3m_005fe800 {
namespace fn_005fe800 {
struct MemoryHeap {
    void Free(void* ptr);
};
struct Target {
    ~Target();
    void* FUN_005fe800(unsigned int flags);
};
// pdb: NiTMap<unsigned int,PathingLOSGrid *>::`scalar deleting destructor' | PathingLOSGridMap.obj | fnv360_0822_debug, vtable, medium
void* Target::FUN_005fe800(unsigned int flags) {
    this->~Target();
    if (flags & 1) {
        reinterpret_cast<MemoryHeap&>(g_heap_005fe800).Free(this);
    }
    return this;
}
}
}   // namespace f3m_005fe800

// @f3 0x005e9600 (community match, verified in this file)
#include <windows.h>
extern __declspec(thread) int DAT_0117c298;
namespace f3m_005e9600 {


namespace navmesh_obstacle_init {

void* __cdecl FUN_0089e810(unsigned int bytes);
extern "C" void* __cdecl FUN_00c00610(void* destination, int value, unsigned int bytes);

class bhkRigidBody;
class ObstacleTaskData;
class TESObjectREFR;
class NiRefObject {
public:
    void IncRefCount();
};
class ReferenceObstacleArray : public NiRefObject {};
class ObstacleData : public NiRefObject {};
class NiNode : public NiRefObject {};
class ObstacleListener;

struct AutoMemContext {
    int saved;
    AutoMemContext(int context) : saved(DAT_0117c298) { DAT_0117c298 = context; }
    ~AutoMemContext() { DAT_0117c298 = saved; }
};

struct CriticalSection {
    CRITICAL_SECTION lock;
    CriticalSection() { InitializeCriticalSection(&lock); }
    ~CriticalSection();
};

template<class T> struct NiPointer {
    T* object;
    NiPointer() : object(0) {}
    NiPointer(T* value) : object(value) {
        if (object)
            object->IncRefCount();
    }
    ~NiPointer();
};

template<class T> struct BSSimpleList {
    T item;
    BSSimpleList* next;
    BSSimpleList() : item(), next(0) {}
    ~BSSimpleList();
};

template<class K, class V> class NiTMapItem;
template<class T> class DFALL {};

template<class Allocator, class K, class V> struct NiTMapBase {
    typedef NiTMapItem<K, V> Entry;
    virtual ~NiTMapBase();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeysEqual(K first, K second) const;
    virtual void SetValue(Entry* entry, K key, V value);
    virtual void ClearValue(Entry* entry);
    virtual Entry* NewItem() = 0;
    virtual void DeleteItem(Entry* entry) = 0;

    unsigned int hashSize;
    Entry** buckets;
    struct MapEntryCount : Allocator { unsigned int value; } count;

    NiTMapBase(unsigned int size) {
        hashSize = size;
        count.value = 0;
        unsigned int bytes = hashSize * sizeof(Entry*);
        buckets = static_cast<Entry**>(FUN_0089e810(bytes));
        unsigned int tableBytes = hashSize * sizeof(Entry*);
        FUN_00c00610(buckets, 0, tableBytes);
    }
};

template<class K, class V> struct NiTMap : NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V> {
    typedef NiTMapItem<K, V> Entry;
    NiTMap(unsigned int size) : NiTMapBase<DFALL<Entry>, K, V>(size) {}
    virtual ~NiTMap();
    virtual Entry* NewItem();
    virtual void DeleteItem(Entry* entry);
};

template<class T> struct FUN_005e6030 {
    struct Entry;
    virtual ~FUN_005e6030();
    Entry* head;
    Entry* tail;
    unsigned int deleteBatchSize;
    Entry** deletedNodeBuffers;
    void* interfaceManager;
    int count;

    FUN_005e6030(unsigned int maxThreads, unsigned int batchSize);
};

template<class T, unsigned int Growth> struct BSSimpleArray {
    virtual ~BSSimpleArray();
    virtual T* Allocate(unsigned int count);
    virtual void Deallocate(T* items);
    virtual T* Reallocate(T* items, unsigned int count);
    T* data;
    unsigned int size;
    unsigned int capacity;
    BSSimpleArray(unsigned int reserved = 0) : data(0), size(0), capacity(0) {
        if (reserved) {
            data = Allocate(reserved);
            capacity = reserved;
        }
    }
};

struct __declspec(align(32)) RecursiveSpinLock {
    unsigned int owningThread;
    unsigned int recursionCount;
    RecursiveSpinLock() : owningThread(0), recursionCount(0) {}
};

struct BSTaskletGroup {
    unsigned int handle;
    BSTaskletGroup() : handle(0) {}
};

// NavMeshObstacleManager, Fallout 3 PC.
struct FUN_005e9600 : CriticalSection {
    typedef NiTMap<unsigned int, NiPointer<ReferenceObstacleArray> > ReferenceMap;
    bool modifierActive;
    ReferenceMap references;
    BSSimpleList<TESObjectREFR*> added;
    BSSimpleList<unsigned int> removed;
    BSSimpleList<NiPointer<ObstacleData> > moving;
    typedef FUN_005e6030<bhkRigidBody*> RigidBodyQueue;
    RigidBodyQueue addQueue;
    RigidBodyQueue removeQueue;
    NiTMap<bhkRigidBody*, NiPointer<ObstacleData> > obstacles;
    BSSimpleList<TESObjectREFR*> pending;
    BSSimpleList<TESObjectREFR*> processed;
    ReferenceMap active;
    ReferenceMap queued;
    ObstacleListener* activationListener;
    ObstacleListener* entityListener;
    BSTaskletGroup taskGroup;
    NiTMap<unsigned int, ObstacleTaskData*> tasks;
    BSSimpleArray<ObstacleTaskData*, 1024> processedTasks;
    BSSimpleArray<ObstacleTaskData*, 1024> backgroundTasks;
    RecursiveSpinLock taskLock;
    BSSimpleList<unsigned int> enabledMeshes;
    BSSimpleList<unsigned int> disabledMeshes;
    unsigned int taskCount;
    float interval;
    bool paused;
    NiPointer<NiNode> obstacleRoot;

    FUN_005e9600();
};

// pdb: NavMeshObstacleManager::NavMeshObstacleManager | NavMeshObstacleManager.obj | fnv360_0822_retail, call_gap, low
FUN_005e9600::FUN_005e9600()
    : references(37), addQueue(7, 8), removeQueue(7, 8), obstacles(37),
      active(37), queued(37), tasks(37), obstacleRoot()
{
    enum { NavMeshMemoryContext = 46 };
    AutoMemContext context(NavMeshMemoryContext);
    activationListener = 0;
    entityListener = 0;
    paused = false;
    taskCount = 0;
    interval = 0.5f;
    modifierActive = false;
}

}
}   // namespace f3m_005e9600

// @f3 0x005e9890 (community match, verified in this file)
extern void* DAT_00e01cd0[];
namespace f3m_005e9890 {
namespace n5e9890 {
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};
struct Deletable { virtual void Delete(int flag); };
struct List { void* value; List* next; void FUN_006c8220(); ~List() { FUN_006c8220(); } };
struct MapA { int unk00; int unk04; int unk08; int unk0c; void FUN_005e4db0(); ~MapA() { FUN_005e4db0(); } };
struct MapB { int unk00; int unk04; void FUN_005e4e20(); ~MapB() { FUN_005e4e20(); } };
struct MapC { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; void FUN_005e9570(); ~MapC() { FUN_005e9570(); } };
struct MapD { int unk00; int unk04; int unk08; int unk0c; void FUN_005e4eb0(); ~MapD() { FUN_005e4eb0(); } };
struct MapE { int unk00; int unk04; int unk08; int unk0c; void FUN_005e4f40(); ~MapE() { FUN_005e4f40(); } };
struct ReleasableArray;
extern void (__thiscall* DAT_00e01cd8)(ReleasableArray*, void*);
struct ReleasableArray
{
    void** table;
    void* data;
    unsigned size;
    unsigned capacity;
    ~ReleasableArray()
    {
        void* storage = data;
        table = DAT_00e01cd0;
        if (storage) { DAT_00e01cd8(this, storage); data = 0; capacity = 0; size = 0; }
    }
};
struct Lock
{
    CRITICAL_SECTION cs;
    ~Lock() { DeleteCriticalSection(&cs); }
};
struct FUN_005e9890 : Lock
{
    int unk18;
    MapA unk1c;
    List unk2c;
    List unk34;
    MapB unk3c;
    MapC unk44;
    MapC unk60;
    MapD unk7c;
    List unk8c;
    List unk94;
    MapA unk9c;
    MapA unkac;
    Deletable* unkbc;
    Deletable* unkc0;
    int unkc4;
    MapE unkc8;
    ReleasableArray unkd8;
    ReleasableArray unke8;
    int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    List unk120;
    List unk128;
    int unk130; int unk134; int unk138;
    NiPointer<RefObj> unk13c;
    void FUN_005e8d50();
    ~FUN_005e9890();
};
// pdb: NavMeshObstacleManager::~NavMeshObstacleManager | NavMeshObstacleManager.obj | fnv360_0822_retail, objrun, medium
FUN_005e9890::~FUN_005e9890()
{
    FUN_005e8d50();
    if (Deletable* p = unkbc) p->Delete(1);
    if (Deletable* q = unkc0) q->Delete(1);
}
}
}   // namespace f3m_005e9890
