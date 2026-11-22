#include <windows.h>
// src/f3staging/f3blk_00540000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0055a310 (community match, verified in this file)
namespace f3m_0055a310 {

struct Keyframe {
    int unk00; float* unk04; int unk08; int unk0c; int unk10; int unk14;
    Keyframe();
    ~Keyframe();
};
struct RandomSource { unsigned int FUN_0086c4b0(int); };
RandomSource* FUN_0044a2d0();
extern "C" void _ReadWriteBarrier();
inline unsigned int Random55() { RandomSource* r=FUN_0044a2d0(); _ReadWriteBarrier(); return r->FUN_0086c4b0(-1); }
void FUN_0058e100(Keyframe*);
void FUN_0058f8a0(float, void*, Keyframe*);
float FUN_0058f580(Keyframe*, int, int);
void FUN_00592370(Keyframe*, int, int, float);
void FUN_0058e510(void*, Keyframe*, Keyframe*, int);
bool FUN_0058ca80(Keyframe*, void*);
void BSFaceGenManager_CopyFaceGenCoord(Keyframe*, void*, int, int);
struct RefCache { virtual void slot00(); virtual void destroy(); long unk04; };
struct Actor55 {
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
    int unk104;
    int unk108;
    int unk10c;
    char* unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    void* unk194;
    int unk198;
    float unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    RefCache* unk1ac;
    int FUN_0054a930();
    void FUN_0055a310(bool keepFirst, bool keepSecond, bool keepStored);
};
inline float Max55(float a, float b) { return a > b ? a : b; }
inline float Min55(float a, float b) { return a < b ? a : b; }
// pdb: TESNPC::RandomizeFaceCoord | TESNPC.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abLockAge, abLockComplexion, abLockHairlength
void Actor55::FUN_0055a310(bool keepFirst, bool keepSecond, bool keepStored)
{
    Keyframe working[4];
    Keyframe baseline[4];
    FUN_0058e100(baseline);
    char* model = unk110;
    void* source;
    if (!FUN_0054a930()) source=model+0x458; else source=model+0x3f8;
    FUN_0058f8a0(0.5f, source, working);
    float x = FUN_0058f580(working,0,0);
    float y = FUN_0058f580(working,0,1);
    float amount = keepFirst ? x : (float)((float)((float)Random55() * 2.3283064365386963e-10) * 50.0 + 15.0);
    x = y - (x - amount);
    amount=Min55(Max55(amount,15.0f),65.0f);
    x=Min55(Max55(x,15.0f),65.0f);
    FUN_00592370(working,0,0,amount);
    FUN_00592370(working,0,1,x);
    x=FUN_0058f580(working,1,0);
    y=FUN_0058f580(working,1,1);
    if (keepSecond) { amount=x; x=y; }
    else {
        amount=(float)((float)((float)Random55() * 2.3283064365386963e-10) * 4.0 - 2.0);
        x = y - (x - amount);
    }
    amount=Min55(Max55(amount,-2.0f),2.0f);
    x=Min55(Max55(x,-2.0f),2.0f);
    FUN_00592370(working,1,0,amount);
    FUN_00592370(working,1,1,x);
    if (!keepStored)
        unk19c=(float)((float)Random55() * 2.3283064365386963e-10);
    model=unk110;
    if (!FUN_0054a930()) source=model+0x458; else source=model+0x3f8;
    FUN_0058e510(source,working,baseline,0);
    void* saved=unk194 ? unk194 : &unk134;
    if (FUN_0058ca80(baseline,saved)) {
        saved=unk194 ? unk194 : &unk134;
        BSFaceGenManager_CopyFaceGenCoord(baseline,saved,0,0);
        RefCache* ref=unk1ac;
        if (ref) {
            if (!InterlockedDecrement(&ref->unk04)) ref->destroy();
            unk1ac=0;
        }
    }
}
}   // namespace f3m_0055a310

// @f3 0x0054a310 (community match, verified in this file)
namespace f3m_0054a310 {
void* __cdecl FUN_00c00610(void*,int,unsigned int);
struct Record1485
{
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
    Record1485();
};
// pdb: CreatureSounds::CreatureSounds | CreatureSounds.obj | fnv360_0721_beta, call_seq, medium
Record1485::Record1485()
{
    FUN_00c00610(this,0,sizeof(*this));
}
}   // namespace f3m_0054a310

// @f3 0x00553f10 (community match, verified in this file)
namespace f3m_00553f10 {
void __cdecl FUN_0089e890(void*);
struct StringMapItem0192 {
    StringMapItem0192* next;
    const char* key;
    void* value;
};
struct FUN_00553ea0 {
    virtual ~FUN_00553ea0();
    virtual void ClearAll();
    unsigned int bucketCount;
    StringMapItem0192** buckets;
    unsigned int count;
};
struct FUN_00553f10 : FUN_00553ea0 {
    bool copyKeys;
    virtual ~FUN_00553f10();
};
// pdb: NiTStringTemplateMap<NiTMap<char const *,IDLE_ANIM_ROOT *>,IDLE_ANIM_ROOT *>::~NiTStringTemplateMap<NiTMap<char const *,IDLE_ANIM_ROOT *>,IDLE_ANIM_ROOT *> | TESIdleManager.obj | fnv360_0822_retail, call_seq, medium
FUN_00553f10::~FUN_00553f10() {
    if (copyKeys) {
        for (unsigned int i=0; i<bucketCount; ++i) {
            StringMapItem0192* item=buckets[i];
            while(item) {
                StringMapItem0192* saved=item;
                item=item->next;
                FUN_0089e890((void*)saved->key);
            }
        }
    }
}
}   // namespace f3m_00553f10

// @f3 0x005441b0 (community match, verified in this file)
#include <stddef.h>
extern char DAT_00de14f8[],DAT_00de13a0[],DAT_00de13c0[];
namespace f3m_005441b0 {
namespace PerkFactory2078 {
struct Heap {void* __thiscall FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;
struct Data {
    void* vtable;
    static void* operator new(size_t n){return DAT_01090a78.FUN_0086b930(n);}
    static void operator delete(void*);
};
struct One:Data {float value;One(){vtable=DAT_00de14f8;value=0.0f;}};
struct Two:Data {float first,second;Two(){vtable=DAT_00de13a0;first=0.0f;second=0.0f;}};
struct Leveled:Data {void* list;Leveled(){vtable=DAT_00de13c0;list=0;}};
struct Choice:Data {
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
    Choice();
};
// pdb: BGSEntryPointFunctionData::CreateFunctionDataOfType | BGSEntryPointFunction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeFunctionDataType
Data* __cdecl FUN_005441b0(unsigned int type){
    switch(type){
        case 1:return new One;
        case 2:return new Two;
        case 3:return new Leveled;
        case 4:return new Choice;
        default:return 0;
    }
}
}
}   // namespace f3m_005441b0
