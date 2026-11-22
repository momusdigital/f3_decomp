#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_004c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004d8410 (community match, verified in this file)
namespace f3m_004d8410 {


struct CellLock8410 {
    volatile long owner;
    long count;
    void FUN_00409a80(const char* name);
    void Unlock() {
        if (--count == 0)
            InterlockedCompareExchange(&owner, 0, owner);
    }
};

struct RefNode8410 {
    void* item;
    RefNode8410* next;
};

struct Manager8410 {
    void FUN_004c0260(void* ref);
};

extern Manager8410* g_manager8410;

struct Cell8410 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    CellLock8410 refLock;
    int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    RefNode8410 refs;
    void FUN_004d8410();
};

// pdb: TESObjectCELL::AddReferencesToLoadedReferenceCollection | TESObjectCELL.obj | fnv360_0721_beta, call_seq, medium
void Cell8410::FUN_004d8410() {
    refLock.FUN_00409a80("TESObjectCELL::CellRefLockEnter()");
    for (RefNode8410* node = &refs; node; node = node->next) {
        if (node->item)
            g_manager8410->FUN_004c0260(node->item);
    }
    refLock.Unlock();
}
}   // namespace f3m_004d8410

// @f3 0x004d5fd0 (community match, verified in this file)
namespace f3m_004d5fd0 {


struct CellLock5fd0 {
    volatile long owner;
    long count;
    void FUN_00409a80(const char* name);
    void Unlock() {
        if (--count == 0)
            InterlockedCompareExchange(&owner, 0, owner);
    }
};

struct CellRef5fd0 {
    bool FUN_004e8f90();
    bool FUN_004e8fe0();
    void TESObjectREFR_AttachSound(bool flag);
};

struct RefNode5fd0 {
    CellRef5fd0* item;
    RefNode5fd0* next;
};

struct GameState5fd0 {
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
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    char unk5A8;
    bool flag5A9;
};

struct Settings5fd0 {
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
    unsigned int flags244;
    bool Flag1() const { return (flags244 >> 1) & 1; }
};

extern GameState5fd0* g_state5fd0;
extern Settings5fd0* g_settings5fd0;

struct Cell5fd0 {
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
    CellLock5fd0 refLock;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    RefNode5fd0 refs;
    void FUN_004d5fd0(bool flag);
};

// pdb: TESObjectCELL::AttachSounds | TESObjectCELL.obj | fnv360_0822_retail, call_gap, low
// pdb params: abAttach
void Cell5fd0::FUN_004d5fd0(bool flag)
{
    if (!g_state5fd0->flag5A9 && !g_settings5fd0->Flag1()) {
        refLock.FUN_00409a80("TESObjectCELL::CellRefLockEnter()");
        for (RefNode5fd0* node = &refs; node; ) {
            CellRef5fd0* ref = node->item;
            node = node->next;
            if (ref && ref->FUN_004e8f90()) {
                if (!flag || ref->FUN_004e8fe0())
                    ref->TESObjectREFR_AttachSound(flag);
            }
        }
        refLock.Unlock();
    }
}
}   // namespace f3m_004d5fd0

// @f3 0x004c2270 (community match, verified in this file)
#include <windows.h>
extern float g_time4C22;
namespace f3m_004c2270 {

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }

    LONG m_uiRefCount;
};

struct Target4C22
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    bool busy;
};


struct Transition4C22
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    NiPointer<NiRefObject> unk10;
    float unk14;
    int unk18;
    Target4C22* unk1C;
    Target4C22* unk20;
    float unk24;
    NiPointer<NiRefObject> unk28;
    float unk2C;

    bool ImageSpaceModifierInstanceForm_StartTransition(Target4C22* target, float arg2, float arg3, NiRefObject* object);
};

// pdb: ImageSpaceModifierInstanceForm::StartTransition | ImageSpaceModifierInstance.obj | fnv360_0721_beta, udata, high
bool Transition4C22::ImageSpaceModifierInstanceForm_StartTransition(Target4C22* target, float arg2, float arg3, NiRefObject* object)
{
    if ((unk1C && unk1C->busy) || (target && target->busy))
        return false;
    unk24 = unk0C;
    unk20 = unk1C;
    unk28 = unk10;
    unk14 = g_time4C22;
    unk1C = target;
    unk2C = arg2;
    unk0C = arg3;
    unk10 = object;
    return true;
}
}   // namespace f3m_004c2270

// @f3 0x004d3450 (community match, verified in this file)
namespace f3m_004d3450 {
struct Pair651 {
    int first;
    int second;
};
struct Owner651 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int flags;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    Pair651* value;
    int TESObjectCELL_GetDataY();
};
// pdb: TESObjectCELL::GetDataY | TESObjectCELL.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
int Owner651::TESObjectCELL_GetDataY()
{
    if (!(flags & 1) && value)
        return value->second;
    return 0;
}
}   // namespace f3m_004d3450

// @f3 0x004cdf90 (community match, verified in this file)
namespace f3m_004cdf90 {
// FUN_004cdf90 -- TESObjectLAND::TESObjectLAND (thiscall constructor)
// Two EH unwind states: base subobject at +0 (this) and a ref-counted
// smart-pointer member at +0x24 (its dtor runs through the second state).

class LandRefTarget {
public:
    void IncRefCount();
    void DecRefCount();
};

class LandFormBase {
public:
    LandFormBase();                 // declared only: the base ctor call at 0x00456190
    virtual ~LandFormBase();
    unsigned char flags04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class TESChildCell {
public:
    virtual void Unk00();
};

class TESObjectLAND : public LandFormBase, public TESChildCell {
public:
    TESObjectLAND();
    int unk1C;
    int unk20;
    NiPointer<LandRefTarget> unk24;
    int unk28;
};

char g_landInitialised;
int g_landCount;

void FUN_004ca670();

// pdb: TESObjectLAND::TESObjectLAND | TESLand.obj | fnv360_0721_beta, call_seq, high
TESObjectLAND::TESObjectLAND()
{
    if (!g_landInitialised)
        FUN_004ca670();
    unk1C = 0;
    unk20 = 0;
    flags04 = 0x42;
    unk28 = 0;
    ++g_landCount;
}
}   // namespace f3m_004cdf90

// @f3 0x004c1f50 (community match, verified in this file)
#include <windows.h>
namespace f3m_004c1f50 {
class FUN_00825830 {
public:
    virtual void v00();
    virtual void DeleteThis();
    virtual ~FUN_00825830();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    __forceinline void DecRefCount() {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class Shape : public FUN_00825830 {};
class FUN_004c1f50 : public FUN_00825830 {
public:
    int unk08;
    int unk0c;
    NiPointer<Shape> transformData;
    virtual ~FUN_004c1f50();
};
// pdb: ImageSpaceModifierInstance::~ImageSpaceModifierInstance | ImageSpaceModifierInstance.obj | fnv360_0822_retail, call_seq, medium
FUN_004c1f50::~FUN_004c1f50() {
    transformData = 0;
}
}   // namespace f3m_004c1f50

// @f3 0x004da190 (community match, verified in this file)
extern const int DAT_00f4a768_x;
extern const char DAT_00f46078_x[];
extern const char DAT_00f47a3c_x[];
extern const char DAT_00f47a58_x[];
namespace f3m_004da190 {
struct Item_004da190 {
    int type;
    int unk04;
    unsigned int unk08;
    unsigned int kind;
};


extern "C" void* __cdecl TESForm_GetFormByNumericID(unsigned int formID);
extern "C" void* __cdecl FUN_00c0050a(void* obj, int offset, const void* from, const void* to, int isRef);

struct Base_004da190 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual bool FUN_00455330(Item_004da190* item);
    virtual bool vf3c(void* form);
};

struct Cell_004da190 : Base_004da190 {
    int unk04;
    unsigned int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char unk24;

    unsigned int FUN_004d4bb0();
    unsigned int FUN_004d4c00();
    bool FUN_004da190(Item_004da190* item);
};

// pdb: TESObjectCELL::SavesBefore | TESObjectCELL.obj | fnv360_0822_retail, vtable, medium
// pdb params: apGroupFORM
bool Cell_004da190::FUN_004da190(Item_004da190* item)
{
    bool result = false;
    if (item && item->type == DAT_00f4a768_x)
    {
        switch (item->kind)
        {
        case 0:
            result = Base_004da190::FUN_00455330(item);
            break;

        case 2:
            if ((unk24 & 1) && FUN_004d4bb0() < item->unk08)
                result = true;
            break;

        case 3:
            if ((unk24 & 1) && FUN_004d4c00() < item->unk08)
                result = true;
            break;

        case 6:
        case 8:
        case 9:
            if (void* cell = FUN_00c0050a(TESForm_GetFormByNumericID(item->unk08), 0, DAT_00f46078_x, DAT_00f47a3c_x, 0))
                result = vf3c(cell);
            break;

        case 4:
            if ((unk24 & 1) || (unk08 & 0x400))
                result = true;
            else if (FUN_004d4bb0() < item->unk08)
                result = true;
            break;

        case 5:
            if ((unk24 & 1) || (unk08 & 0x400))
                result = true;
            else if (FUN_004d4c00() < item->unk08)
                result = true;
            break;

        case 1:
            if (unk24 & 1)
                result = true;
            else if (void* ws = FUN_00c0050a(TESForm_GetFormByNumericID(item->unk08), 0, DAT_00f46078_x, DAT_00f47a58_x, 0))
                result = vf3c(ws);
            break;

        case 7:
            result = true;
            break;
        }
    }
    return result;
}
}   // namespace f3m_004da190

// @f3 0x004d8460 (community match, verified in this file)
namespace f3m_004d8460 {
namespace f3m_004d8460 {

extern const char DAT_00dcd0a8[];
extern long (__stdcall* DAT_00d9b06c)(long volatile*, long, long);

struct Lock {
    long owner;
    int count;
    void FUN_00409a80(const char* name);
    void Unlock() {
        if (--count == 0)
            DAT_00d9b06c(&owner, 0, owner);
    }
};

struct BaseForm {
    int u00;
    int u04;
    unsigned int flags08;
};

struct SubNode {
    int u00; int u04; int u08; int u0c;
    int u10; int u14; int u18; int u1c;
    int u20; int u24;
    unsigned char b28;
    void FUN_00615370(struct Ref* r);
    void BGSTerrainManager_HideTree(struct Ref* r, bool b);
};

struct Node3D {
    SubNode* FUN_00501cc0();
};

struct Ref {
    int u00;
    int u04;
    unsigned int flags08;
    int u0c;
    int u10;
    int u14;
    int u18;
    BaseForm* base1c;
    Node3D* FUN_004e8880();
};

struct Mgr0b34 {
    void FUN_004c0420(Ref* r);
};
extern Mgr0b34* DAT_01070b34;

struct Sky {
    int u00; int u04; int u08; int u0c;
    int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    int u30;
    int u34;
    int FUN_00b35640();
    bool Check() { return u34 == 0 && FUN_00b35640(); }
};
extern Sky* DAT_0107a0d8;


struct ListNode {
    Ref* item;
    ListNode* next;
};

struct Cell {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    Lock lock80;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    ListNode listAC;

    void FUN_004d8460();
};

// pdb: TESObjectCELL::RemoveReferencesFromLoadedReferenceCollection | TESObjectCELL.obj | fnv360_0822_retail, call_gap, low
void Cell::FUN_004d8460()
{
    lock80.FUN_00409a80(DAT_00dcd0a8);
    for (ListNode* n = &listAC; n; n = n->next) {
        Ref* r = n->item;
        if (r) {
            DAT_01070b34->FUN_004c0420(r);
            if (DAT_0107a0d8->Check() && ((unsigned char)(r->base1c->flags08 >> 6) & 1)) {
                Node3D* node = r->FUN_004e8880();
                if (node) {
                    if (!((unsigned char)(r->flags08 >> 11) & 1))
                        node->FUN_00501cc0()->FUN_00615370(r);
                    else
                        node->FUN_00501cc0()->BGSTerrainManager_HideTree(r, true);
                    node->FUN_00501cc0()->b28 = 1;
                }
            }
        }
    }
    lock80.Unlock();
}

}
}   // namespace f3m_004d8460

// @f3 0x004cf050 (community match, verified in this file)
namespace f3m_004cf050 {



namespace f3m_004cf050 {
struct FUN_00aa5160;
}

class MemoryManager
{
public:
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
extern float DAT_01016970;  // FLT_MAX
extern float DAT_01015f5c;  // -FLT_MAX

class TESForm
{
public:
    virtual ~TESForm();
};

class TESLandTexture : public TESForm
{
public:
    void FUN_004d2af0(int count, f3m_004cf050::FUN_00aa5160* list);
};

namespace f3m_004cf050 {

struct NiPoint2
{
    float x, y;
    NiPoint2() {}
    NiPoint2(float fx, float fy) : x(fx), y(fy) {}
};

struct NiPoint3
{
    float x, y, z;
    void FUN_00468d00();  // unitize
};

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor() {}
    RgbaColor(float fr, float fg, float fb, float fa) : r(fr), g(fg), b(fb), a(fa) {}
};

// the plugin file being read
struct ModFile
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char fileName[0x104];
    int unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154,
        unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188,
        unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc,
        unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0,
        unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224,
        unk228, unk22c, unk230, unk234, unk238, unk23c, unk240, unk244, unk248, unk24c, unk250, unk254, unk258;
    unsigned int chunkLength;
    int unk260;
    unsigned int formOffset;
    int unk268, unk26c, unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290, unk294;
    char unk298;
    bool swapBytes;  // big-endian file
    ModFile* TESFile_GetThreadSafeFile();
    bool TESFile_FindForm(void* form);
    unsigned char TESFile_GetTESForm();
    bool TESFile_SetOffset(unsigned int offset);
    int TESFile_GetTESChunk();
    bool FUN_00447d60(void* buffer, unsigned int length);
    bool TESFile_NextChunk();
    unsigned int FormOffset() const { return formOffset; }
    unsigned int ChunkLength() const { return chunkLength; }
    const char* Name() const { return fileName; }
};

struct WorldForm
{
    bool FUN_005041b0(int x, int y, ModFile** file, unsigned int* offset);
};

struct ParentCell
{
    WorldForm* FUN_004d3780();
    int TESObjectCELL_GetDataX();
    int TESObjectCELL_GetDataY();
};

// the queued texture list created for the land (0x28 bytes)
struct FUN_00aa5160
{
    FUN_00aa5160(int count);
    static void* operator new(unsigned int size) throw();
    static void operator delete(void* p);
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};

struct TextureListPtr
{
    FUN_00aa5160* list;
    TextureListPtr& FUN_00ade450(FUN_00aa5160* p);
    FUN_00aa5160* Get() const { return list; }
};

extern TESLandTexture* DAT_010713e8;  // default land texture

// reference-counted collision data built from the MPCD chunk
struct CollisionData
{
    virtual ~CollisionData();
    unsigned short counted;
    short useCount;
    __forceinline void AddUse()
    {
        if (counted != 0)
            ++useCount;
    }
    __forceinline void ReleaseUse()
    {
        if (counted != 0)
        {
            --useCount;
            if (useCount == 0)
                delete this;
        }
    }
};

struct LandMesh
{
    int unk00;
    NiPoint3** points;
    NiPoint3** pointNormals;
    RgbaColor** pointColors;
    int unk10;
    int unk14;
    NiPoint2 zBounds;
    TESLandTexture* quadTexture[4];
    TESLandTexture** layerTextures[4];
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    CollisionData* collision;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c,
        unk90, unk94;
    int gridX;
    int gridY;
    float zMid;
};

struct TextureChunk
{
    unsigned int formID;
    unsigned char quadrant;
    unsigned char unused05;
    unsigned short layerIndex;
};

struct NormalBytes
{
    signed char x, y, z;
};

struct ColorBytes
{
    unsigned char r, g, b;
};

struct HeightChunk
{
    float baseHeight;
    signed char deltas[1089];
};

struct OpacityEntry
{
    unsigned short point;
    unsigned short unused02;
    float opacity;
};

void* FUN_00aa5160::operator new(unsigned int size) throw() { return g_memoryManager.Allocate(size); }

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int formID);
void __cdecl TESForm_AddCompileIndex(unsigned int* formID, ModFile* file);
void __cdecl FUN_00887da0(const char* format, ...);
extern long DAT_0116d6bc;  // warning counter
extern const float DAT_01071398[4];  // quadrant y offsets
extern const float DAT_010713a8[4];  // quadrant x offsets

class LandForm
{
public:
    void* vtbl;
    int unk04, unk08;
    unsigned int formID;
    int unk10, unk14, unk18;
    unsigned int flags;
    ParentCell* parentCell;
    TextureListPtr textureList;
    LandMesh* mesh;

    unsigned int HasData() const { return flags & 8; }
    unsigned int InWorldspace() const { return flags & 0x400; }
    int GridX() { return mesh ? mesh->gridX : (parentCell ? parentCell->TESObjectCELL_GetDataX() : 0); }
    int GridY() { return mesh ? mesh->gridY : (parentCell ? parentCell->TESObjectCELL_GetDataY() : 0); }
    ModFile* TESForm_GetFile(int index);
    void FUN_004ce5e0(void* bytes, unsigned int length, CollisionData** out);
    void FUN_004cb250();
    int FUN_004c8f00();
    int FUN_004c8f20();
    void FUN_004c9630(int quadrant, unsigned int point, int layerIndex, float opacity);
    bool FUN_004cf050();
};

// pdb: TESObjectLAND::LoadVerticesIntoArrays | TESLand.obj | fnv360_0822_retail, ustr, medium
bool LandForm::FUN_004cf050()
{
    if (HasData())
        return true;
    int lastQuadrant = -1;
    int lastLayer = -1;
    bool loadFailed = false;
    ModFile* sourceFile = 0;
    unsigned int dataOffset = 0;
    if (!InWorldspace())
    {
        if (!(flags & 1) && !(flags & 2) && !(flags & 4))
            return true;
        sourceFile = TESForm_GetFile(-1)->TESFile_GetThreadSafeFile();
        if (!sourceFile->TESFile_FindForm(this))
            loadFailed = true;
        if (!loadFailed)
        {
            unsigned char recordType = sourceFile->TESFile_GetTESForm();
            if (recordType != 0x42)
                loadFailed = true;
        }
        if (!loadFailed)
            dataOffset = sourceFile->FormOffset();
    }
    else
    {
        WorldForm* worldspace = parentCell ? parentCell->FUN_004d3780() : 0;
        if (!worldspace || !worldspace->FUN_005041b0(GridX(), GridY(), &sourceFile, &dataOffset))
            return true;
    }
    if (loadFailed)
    {
        InterlockedDecrement(&DAT_0116d6bc);
        if (DAT_0116d6bc < 0)
            DAT_0116d6bc = 0;
        const char* nameText = sourceFile ? sourceFile->Name() : "UNKNOWN";
        ParentCell* ownerCell = parentCell;
        unsigned int id = formID;
        FUN_00887da0("CELLS: Failed to load landscape data for LAND (%08X) in Cell (%i, %i) from file '%s'.", id,
                     ownerCell->TESObjectCELL_GetDataX(), ownerCell->TESObjectCELL_GetDataY(), nameText);
        InterlockedIncrement(&DAT_0116d6bc);
        if (DAT_0116d6bc < 0)
            DAT_0116d6bc = 0;
        return false;
    }
    ModFile* reader = sourceFile;
    if (!reader->TESFile_SetOffset(dataOffset))
        return false;
    bool gotHeights = false;
    bool gotNormals = false;
    bool texturesBad = false;
    int i, j;
    do
    {
        switch (reader->TESFile_GetTESChunk())
        {
        case 0x41544144:  // DATA
            if (InWorldspace())
            {
                unsigned int dataFlags;
                reader->FUN_00447d60(&dataFlags, 4);
                if (reader->swapBytes)
                    dataFlags = _byteswap_ulong(dataFlags);
                dataFlags &= 7;
                flags &= ~7;
                flags |= dataFlags;
            }
            break;
        case 0x4443504d: {  // MPCD
            unsigned int length = reader->ChunkLength();
            unsigned char* bytes = (unsigned char*)g_memoryManager.Allocate(length);
            reader->FUN_00447d60(bytes, length);
            if (mesh->collision)
            {
                mesh->collision->ReleaseUse();
                mesh->collision = 0;
            }
            FUN_004ce5e0(bytes, length, &mesh->collision);
            if (mesh->collision)
            {
                mesh->collision->AddUse();
                flags |= 0x800;
            }
            g_memoryManager.Deallocate(bytes);
        }
        break;
        case 0x54474856:  // VHGT
            if (flags & 1)
            {
                HeightChunk heightChunk;
                reader->FUN_00447d60(&heightChunk, sizeof(heightChunk));
                if (reader->swapBytes)
                    *(unsigned int*)&heightChunk.baseHeight = _byteswap_ulong(*(unsigned int*)&heightChunk.baseHeight);
                mesh->zBounds = NiPoint2(DAT_01016970, DAT_01015f5c);
                float rowStart = heightChunk.baseHeight;
                float heights[1089];
                i = 0;
                do
                {
                    heights[i] = heightChunk.deltas[i] + rowStart;
                    if ((i + 1) % 33 == 0)
                        rowStart = heights[i - 32];
                    else
                        rowStart = heights[i];
                } while (++i < 1089);
                i = 0;
                do
                {
                    int quadStart = (i / 2 * 16) * 33 + (i % 2 * 16);
                    j = 0;
                    do
                    {
                        int column = j % 17;
                        int row = j / 17;
                        int gridIndex = quadStart + row * 33 + column;
                        float zValue = float(fnv_FloatToInt(heights[gridIndex]) * 8);
                        mesh->points[i][j].x = (column * 128) + DAT_010713a8[i];
                        mesh->points[i][j].y = (row * 128) + DAT_01071398[i];
                        mesh->points[i][j].z = zValue;
                        if (zValue < mesh->zBounds.x)
                            mesh->zBounds.x = zValue;
                        else if (zValue > mesh->zBounds.y)
                            mesh->zBounds.y = zValue;
                    } while (++j < 289);
                } while (++i < 4);
                mesh->zMid = (mesh->zBounds.y + mesh->zBounds.x) * 0.5;
                i = 0;
                do
                {
                    j = 0;
                    do
                    {
                        mesh->points[i][j].z = mesh->points[i][j].z - mesh->zMid;
                    } while (++j < 289);
                } while (++i < 4);
                gotHeights = true;
            }
            break;
        case 0x4c4d4e56:  // VNML
            if (flags & 1)
            {
                NormalBytes normalChunk[1089];
                reader->FUN_00447d60(normalChunk, sizeof(normalChunk));
                i = 0;
                do
                {
                    int quadStart = (i / 2 * 16) * 33 + (i % 2 * 16);
                    j = 0;
                    do
                    {
                        int gridIndex = quadStart + (j / 17) * 33 + j % 17;
                        float nx = normalChunk[gridIndex].x;
                        mesh->pointNormals[i][j].x = nx / 127.0;
                        float ny = normalChunk[gridIndex].y;
                        mesh->pointNormals[i][j].y = ny / 127.0;
                        float nz = normalChunk[gridIndex].z;
                        mesh->pointNormals[i][j].z = nz / 127.0;
                        mesh->pointNormals[i][j].FUN_00468d00();
                    } while (++j < 289);
                } while (++i < 4);
                gotNormals = true;
            }
            break;
        case 0x524c4356:  // VCLR
            if (flags & 2)
            {
                ColorBytes colorChunk[1089];
                reader->FUN_00447d60(colorChunk, sizeof(colorChunk));
                i = 0;
                do
                {
                    int quadStart = (i / 2 * 16) * 33 + (i % 2 * 16);
                    j = 0;
                    do
                    {
                        int gridIndex = quadStart + (j / 17) * 33 + j % 17;
                        mesh->pointColors[i][j] = RgbaColor(colorChunk[gridIndex].r / 255.0, colorChunk[gridIndex].g / 255.0,
                                                            colorChunk[gridIndex].b / 255.0, 1.0f);
                    } while (++j < 289);
                } while (++i < 4);
            }
            break;
        case 0x54585442:  // BTXT
            if (flags & 4)
            {
                TextureChunk baseChunk;
                memset(&baseChunk, 0, sizeof(baseChunk));
                reader->FUN_00447d60(&baseChunk, sizeof(baseChunk));
                if (reader->swapBytes)
                {
                    baseChunk.formID = _byteswap_ulong(baseChunk.formID);
                    baseChunk.layerIndex = _byteswap_ushort(baseChunk.layerIndex);
                }
                TESForm_AddCompileIndex(&baseChunk.formID, reader);
                mesh->quadTexture[baseChunk.quadrant] = dynamic_cast<TESLandTexture*>(TESForm_GetFormByNumericID(baseChunk.formID));
                if (!mesh->quadTexture[baseChunk.quadrant])
                {
                    FUN_00887da0("TEXTURES: Land (%i, %i) unable to find base texture ID (%08X) for block %i.",
                                 FUN_004c8f00(), FUN_004c8f20(), baseChunk.formID, baseChunk.quadrant);
                    texturesBad = true;
                }
                else
                {
                    TESLandTexture* landTexture = mesh->quadTexture[baseChunk.quadrant];
                    if (!textureList.Get())
                        textureList.FUN_00ade450(new FUN_00aa5160(5));
                    landTexture->FUN_004d2af0(5, textureList.Get());
                }
            }
            break;
        case 0x54585441:  // ATXT
            if (flags & 4)
            {
                TextureChunk layerChunk;
                memset(&layerChunk, 0, sizeof(layerChunk));
                reader->FUN_00447d60(&layerChunk, sizeof(layerChunk));
                if (reader->swapBytes)
                {
                    layerChunk.formID = _byteswap_ulong(layerChunk.formID);
                    layerChunk.layerIndex = _byteswap_ushort(layerChunk.layerIndex);
                }
                if (layerChunk.layerIndex > 5)
                {
                    FUN_00887da0("CELLS: Land (%i, %i) clamping invalid index %i for block %i.", FUN_004c8f00(),
                                 FUN_004c8f20(), layerChunk.layerIndex, layerChunk.quadrant);
                    layerChunk.layerIndex = 5;
                    texturesBad = true;
                }
                TESLandTexture* landTexture = 0;
                if (layerChunk.formID)
                {
                    TESForm_AddCompileIndex(&layerChunk.formID, reader);
                    landTexture = dynamic_cast<TESLandTexture*>(TESForm_GetFormByNumericID(layerChunk.formID));
                    if (!landTexture)
                    {
                        FUN_00887da0("TEXTURES: Land (%i, %i) unable to find additional texture ID (%08X) for block %i.",
                                     FUN_004c8f00(), FUN_004c8f20(), layerChunk.formID, layerChunk.quadrant);
                        texturesBad = true;
                    }
                }
                else
                    landTexture = DAT_010713e8;
                mesh->layerTextures[layerChunk.quadrant][layerChunk.layerIndex] = landTexture;
                if (landTexture)
                {
                    if (!textureList.Get())
                        textureList.FUN_00ade450(new FUN_00aa5160(5));
                    landTexture->FUN_004d2af0(5, textureList.Get());
                }
                lastQuadrant = layerChunk.quadrant;
                lastLayer = layerChunk.layerIndex;
            }
            break;
        case 0x54585456:  // VTXT
            if (flags & 4)
            {
                if (lastQuadrant >= 0 && lastLayer >= 0)
                {
                    unsigned int length = reader->ChunkLength();
                    if (length % 8 == 0)
                    {
                        OpacityEntry* entries = (OpacityEntry*)g_memoryManager.Allocate(length);
                        reader->FUN_00447d60(entries, length);
                        unsigned int entryCount = length >> 3;
                        for (unsigned int n = 0; n < entryCount; n++)
                        {
                            if (reader->swapBytes)
                            {
                                entries[n].point = _byteswap_ushort(entries[n].point);
                                unsigned int* opacityBits = (unsigned int*)&entries[n].opacity;
                                *opacityBits = _byteswap_ulong(*opacityBits);
                            }
                            FUN_004c9630(lastQuadrant, entries[n].point, lastLayer, entries[n].opacity);
                        }
                        g_memoryManager.Deallocate(entries);
                    }
                    else
                    {
                        FUN_00887da0("TEXTURES: Land (%i, %i) found unrecognized vertex texture data in file %s.",
                                     FUN_004c8f00(), FUN_004c8f20(), reader->Name());
                        texturesBad = true;
                    }
                }
                lastQuadrant = -1;
                lastLayer = -1;
            }
            break;
        }
    } while (reader->TESFile_NextChunk());
    if (texturesBad)
        FUN_004cb250();
    if (gotHeights && !gotNormals)
        FUN_00887da0("CELLS: Land for cell (%i, %i) in file '%s' does not contain Normal Data.", GridX(), GridY(),
                     reader->Name());
    return true;
}

}  // namespace f3m_004cf050
}   // namespace f3m_004cf050

// @f3 0x004d3a10 (community match, verified in this file)
namespace f3m_004d3a10 {
namespace n4d3a10 {
struct CellCoords { int x; int y; };
struct CellPos { float x; float y; float z; };
struct CellA10 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char cellFlags;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    CellCoords* coords;
    bool IsInterior() { return (cellFlags & 1) != 0; }
    int GetX() { if (!IsInterior() && coords) return coords->x; return 0; }
    int GetY() { if (!IsInterior() && coords) return coords->y; return 0; }
    bool FUN_004d3a10(const CellPos* pos);
};
// pdb: TESObjectCELL::IsPointInCellExterior | TESObjectCELL.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aPt
bool CellA10::FUN_004d3a10(const CellPos* pos)
{
    if (IsInterior())
        return false;
    int x = fnv_FloatToInt(pos->x);
    int y = fnv_FloatToInt(pos->y);
    if ((x >> 12) != GetX())
        return false;
    if ((y >> 12) != GetY())
        return false;
    return true;
}
}
}   // namespace f3m_004d3a10

// @f3 0x004d3cc0 (community match, verified in this file)
namespace f3m_004d3cc0 {
namespace n4d3cc0 {
struct NiPoint3 { float x, y, z; };
struct NiMatrix3
{
    float m_pEntry[3][3];
    void MakeZRotation(float fAngle)
    {
        float sn, cs;
        fnv_SinCos(fAngle, sn, cs);
        m_pEntry[0][0] = cs;   m_pEntry[0][1] = sn;   m_pEntry[0][2] = 0.0f;
        m_pEntry[1][0] = -sn;  m_pEntry[1][1] = cs;   m_pEntry[1][2] = 0.0f;
        m_pEntry[2][0] = 0.0f; m_pEntry[2][1] = 0.0f; m_pEntry[2][2] = 1.0f;
    }
    NiPoint3 operator*(const NiPoint3& pt) const
    {
        NiPoint3 r;
        r.x = m_pEntry[0][0] * pt.x + m_pEntry[1][0] * pt.y + m_pEntry[2][0] * pt.z;
        r.y = m_pEntry[0][1] * pt.x + m_pEntry[1][1] * pt.y + m_pEntry[2][1] * pt.z;
        r.z = m_pEntry[0][2] * pt.x + m_pEntry[1][2] * pt.y + m_pEntry[2][2] * pt.z;
        return r;
    }
};
struct ExtraDataList { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18; float FUN_0040d5b0(); };
struct Cell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char cellFlags;
    ExtraDataList extraData;
    bool IsInterior() const { return (cellFlags & 1) != 0; }
    float GetNorthRotation()
    {
        float fRot = 0.0f;
        if (IsInterior())
            fRot = extraData.FUN_0040d5b0();
        return fRot;
    }
    void TESObjectCELL_AdjustCoordForNorthRotation(const NiPoint3& kIn, NiPoint3& kOut, bool bInvert);
};
// pdb: TESObjectCELL::AdjustCoordForNorthRotation | TESObjectCELL.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Cell::TESObjectCELL_AdjustCoordForNorthRotation(const NiPoint3& kIn, NiPoint3& kOut, bool bInvert)
{
    float fAngle = (bInvert ? -1.0f : 1.0f) * GetNorthRotation();
    if (fAngle != 0.0f)
    {
        NiMatrix3 kRot;
        kRot.MakeZRotation(fAngle);
        kOut = kRot * kIn;
    }
    else
    {
        kOut = kIn;
    }
}
}
}   // namespace f3m_004d3cc0

// @f3 0x004db3e0 (community match, verified in this file)
namespace f3m_004db3e0 {
namespace CellMapPicture {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct ThreadState {
    unsigned char engineState[0x298];
    int memoryContext;
};
extern __declspec(thread) ThreadState mapThreadState;

struct MemoryContext {
    int saved;
    MemoryContext() : saved(mapThreadState.memoryContext) { mapThreadState.memoryContext = 14; }
    ~MemoryContext() { mapThreadState.memoryContext = saved; }
};

struct RefObject {
    virtual ~RefObject();
    virtual void DeleteThis();
    long refCount;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!InterlockedDecrement(&refCount)) DeleteThis(); }
};

template<class T> class NiPointer {
    T* object;
public:
    NiPointer(T* initial = 0) : object(initial) { if (object) object->IncRefCount(); }
    ~NiPointer() { if (object) object->DecRefCount(); }
    operator T*() const { return object; }
    T* operator->() const { return object; }
    NiPointer& operator=(T* value) {
        if (object != value) {
            if (object) object->DecRefCount();
            object = value;
            if (object) object->IncRefCount();
        }
        return *this;
    }
    NiPointer& operator=(const NiPointer& value) { return *this = value.object; }
};

struct NiCamera;
struct BSRenderedTexture : RefObject {
    void* FUN_00aee520();
};
struct Color {
    float r, g, b, a;
    Color(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}
};

struct Renderer {
    virtual void slot0();
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
    virtual void SetBackground(const Color& color);
    virtual void slot44();
    virtual void GetBackground(Color& color);
};
struct TextureManager {
    BSRenderedTexture* FUN_00af1470(Renderer*, int, int, int, int);
    BSRenderedTexture* FUN_00af0600(Renderer*, int, int, int);
    void FUN_00af0de0(BSRenderedTexture*);
};
struct SceneObject : RefObject {
    unsigned char objectState[0x30 - sizeof(RefObject)];
    unsigned int flags;
    bool GetAppCulled() const { return (flags & 1) != 0; }
    void SetAppCulled(bool culled) {
        if (culled) flags |= 1;
        else flags &= ~1u;
    }
};
struct SceneNode : SceneObject {
    unsigned char transformAndBounds[0xa0 - sizeof(SceneObject)];
    SceneObject** children;
};
struct ShadowScene : SceneNode {
    unsigned char sceneState[0x130 - sizeof(SceneNode)];
    bool disableLightUpdate;
};
struct TreeManager {
    unsigned char treeState[0x18];
    bool enabled;
};
struct FrameState {
    unsigned char rendererState[0x200];
    int frameState;
    unsigned GetFrameState() const { return frameState; }
};
struct Accumulator : RefObject {
    unsigned char renderState[0x86 - sizeof(RefObject)];
    bool renderNoShader;
    unsigned char passState[0x194 - 0x87];
    ShadowScene* activeScene;
    BSRenderedTexture* waterFogTarget;
    int renderMode;
    unsigned char otherPassState[0x280 - 0x1a0];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Accumulator(int, unsigned int, unsigned int);
};

struct CullingBase {
    CullingBase(void* visibleSet);
    virtual void* GetRTTI();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual ~CullingBase();
    virtual void Process(SceneObject*);
    virtual void Process(NiCamera*, SceneObject*, void*);
    virtual void Append(void*);
    static void operator delete(void*);
    bool useVirtualAppend;
    void* visibleSet;
    NiCamera* camera;
    struct { float limits[6]; bool orthographic; } frustum;
    struct { float normal[3]; float constant; } planes[6];
    unsigned int activePlanes;
};
struct CullingProcess : CullingBase {
    virtual void* GetRTTI();
    virtual void Process(SceneObject*);
    virtual void Process(NiCamera*, SceneObject*, void*);
    virtual void Append(void*);
    int mode, modeStack[10], stackIndex;
    void* compoundFrustum;
    NiPointer<Accumulator> accumulator;
    CullingProcess(void* visible) : CullingBase(visible), mode(0), stackIndex(0), compoundFrustum(0) {}
    ~CullingProcess();
    void FUN_004691c0(Accumulator*);
    void FUN_00aad3a0(int mode);
    void FUN_00aad3d0();
};
struct ImageEffect;
struct ImageSpace {
    unsigned int state[2];
    ImageEffect** effects;
    void FUN_00b1cb50(ImageEffect*, Renderer*, BSRenderedTexture*, BSRenderedTexture*, int, bool);
};
extern Renderer* DAT_0116f2f8;
extern TextureManager* DAT_0116ef98;
extern ImageSpace* DAT_0116ef9c;
extern ShadowScene* DAT_0116efb8;
extern FrameState* DAT_0108f048;
extern bool DAT_01073c88;
Accumulator* FUN_00ad5a50();
SceneObject* FUN_00494140();
TreeManager* FUN_0059baa0(bool create);
void FUN_00aeec60(int flags, void* group);
bool FUN_00aeeb60(void* group, int flags);
inline bool BeginTexture(BSRenderedTexture* texture, int flags) {
    return FUN_00aeeb60(texture ? texture->FUN_00aee520() : 0, flags);
}
void FUN_00aeeb20();
void FUN_00aeebd0();
void FUN_00aef280(NiCamera*, SceneObject*, CullingProcess*);
void FUN_00aef470(NiCamera*, Accumulator*, int);
void FUN_00adaec0(Accumulator*);
struct RenderData { SceneNode* node; };
struct MapCell {
    unsigned char cellState[0xc4];
    RenderData* renderData;
    SceneObject* GetChild(unsigned index) const {
        SceneNode* node = renderData ? renderData->node : 0;
        if (node)
            return node->children[index];
        return 0;
    }
    void __thiscall FUN_004db3e0(NiCamera* pkCamera, NiPointer<BSRenderedTexture>& spResult);
};

// pdb: TESObjectCELL::TakeLocalMapPicture | TESObjectCELL.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apCamera, aspRenderedTexture
void MapCell::FUN_004db3e0(NiCamera* pkCamera, NiPointer<BSRenderedTexture>& spResult)
{
    MemoryContext memory;
    NiPointer<Accumulator> oldAccumulator = FUN_00ad5a50();
    CullingProcess culler(0);
    // The original constructs three texture references. Unwind state 3
    // destroys this one even though this rendering path leaves it null.
    NiPointer<BSRenderedTexture> spareTexture;
    NiPointer<BSRenderedTexture> output;
    NiPointer<BSRenderedTexture> shader;
    shader = DAT_0116ef98->FUN_00af1470(DAT_0116f2f8, 29, 0, 0, 0);
    output = DAT_0116ef98->FUN_00af0600(DAT_0116f2f8, 27, 0, 0);
    if (output && shader) {
        Color oldColor(0, 0, 0, 0);
        DAT_0116f2f8->GetBackground(oldColor);
        DAT_0116f2f8->SetBackground(Color(0, 0, 0, 1));
        ShadowScene* scene = DAT_0116efb8;
        bool oldDisable = scene->disableLightUpdate;
        scene->disableLightUpdate = true;
        bool outsideFrame = DAT_0108f048->GetFrameState() == 0;
        SceneObject* water = FUN_00494140();
        bool waterCulled = false;
        if (water) {
            waterCulled = water->GetAppCulled();
            water->SetAppCulled(true);
        }
        bool treesEnabled = DAT_01073c88 && FUN_0059baa0(true)->enabled;
        FUN_0059baa0(true)->enabled = false;
        if (outsideFrame) FUN_00aeec60(7, shader->FUN_00aee520());
        else BeginTexture(shader, 7);
        NiPointer<Accumulator> accum = new Accumulator(0x63, 1, 0x2f7);
        accum->activeScene = scene;
        culler.FUN_004691c0(accum);
        accum->renderMode = 9;
        culler.FUN_00aad3a0(3);
        FUN_00aef280(pkCamera, scene, &culler);
        culler.FUN_00aad3d0();
        if (GetChild(6)) {
            culler.FUN_00aad3a0(1);
            FUN_00aef280(pkCamera, GetChild(6), &culler);
            culler.FUN_00aad3d0();
        }
        FUN_00aef470(pkCamera, accum, 0);
        culler.accumulator = 0;
        accum = 0;
        if (outsideFrame) FUN_00aeeb20();
        else FUN_00aeebd0();
        FUN_0059baa0(true)->enabled = treesEnabled;
        if (water) water->SetAppCulled(waterCulled);
        if (outsideFrame) FUN_00aeec60(7, output->FUN_00aee520());
        else BeginTexture(output, 7);
        ImageEffect* effect = DAT_0116ef9c->effects[14];
        DAT_0116ef9c->FUN_00b1cb50(effect, DAT_0116f2f8, shader, output, 0, false);
        if (outsideFrame) FUN_00aeeb20();
        else FUN_00aeebd0();
        scene->disableLightUpdate = oldDisable;
        FUN_00ad5a50()->renderNoShader = true;
        DAT_0116f2f8->SetBackground(oldColor);
    }
    DAT_0116ef98->FUN_00af0de0(shader);
    spResult = output;
    FUN_00adaec0(oldAccumulator);
}
}
}   // namespace f3m_004db3e0
