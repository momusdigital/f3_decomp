#include <windows.h>
#include <string.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00560000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0057e0a0 (community match, verified in this file)
namespace f3m_0057e0a0 {

extern "C" unsigned long __readfsdword(unsigned long);
extern unsigned long DAT_01179af4;
struct TLS { int unk0;
int unk4;
int unk8;
int unkC;
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
int unk294; int context; };
extern __declspec(thread) int DAT_0117c298;
struct Context { int old; Context(int n) {old=DAT_0117c298; DAT_0117c298=n;} ~Context(){DAT_0117c298=old;} };
struct Manager { int unk0;
int unk4;
int unk8;
int unkC;
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
int unk3C; };
extern Manager* DAT_0107a104;
struct Mode { int unk0;
int unk4;
int unk8;
int unkC;
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
unsigned bits; bool active() const { return (bits>>1)&1; } };
extern Mode* DAT_01079858;
struct Value { int unk0;
int unk4;
int unk8;
int unkC;
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
int unk90; float value; };
struct Values { int unk0;
int unk4;
int unk8;
int unkC;
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
int unk9C; Value** items; unsigned short unkA4; unsigned short count; Value* get(){if(count<=0)return 0; return items[0];} };
extern Values* DAT_0107a224;
struct Timer { float FUN_006e2a90(); unsigned FUN_006e2ac0(); };
extern Timer DAT_01079f68;
extern unsigned DAT_01090bb0;
extern float DAT_00f5dff4;
struct Obj;
struct Component { virtual void v0(); virtual void v4(); virtual void v8(); virtual void update(Obj*,float); int unk0;
int unk4;
int unk8;
int unkC;
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
int unk68; int state; };
struct Other { void FUN_00579dc0(float); };
bool FUN_00576ba0(Obj*);
void FUN_0048fd80(void*);
struct Manager2 { double TESObjectREFR_GetRelevantWaterHeight(); };
__forceinline bool checkThreshold(){ double limit=DAT_0107a224->get()->value; return ((Manager2*)DAT_0107a104)->TESObjectREFR_GetRelevantWaterHeight()>limit; }
struct Obj { int unk0;
int unk4;
int unk8;
int unkC;
int unk10;
int unk14;
int unk18;
int unk1C;
Component* c20;
Component* c24;
Component* c28;
Component* c2c;
Component* c30;
Component* c34;
Other* c38;
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
float time;
int unkF0;
int unkF4;
int mode;
int unkFC;
float fade;
unsigned start;
unsigned stamp;
int unk10C;
int unk110;
int unk114;
unsigned flags;
void FUN_0057c650(float); void Sky_HandleClimateChange(); void Sky_UpdateWeather(); void FUN_0057b700(); void FUN_0057bac0(); void FUN_0057aaa0(); void FUN_0057cae0();
void Sky_Update(float dt);
};
// pdb: Sky::Update | Sky.obj | fnv360_0822_retail, call_seq + bridge(call_gap|caller), high
void Obj::Sky_Update(float dt) {
 Context context(33);
 if(DAT_0107a104->unk3C) {
 time=DAT_01079f68.FUN_006e2a90();
 if(DAT_0107a104 && DAT_0107a104->unk3C && checkThreshold()) flags|=4; else flags&=~4;
 if(mode==1 && !DAT_01079858->active()) FUN_0057c650(dt);
 else {
 Sky_HandleClimateChange();
 if(DAT_01079858->active()) flags|=1;
 Sky_UpdateWeather(); FUN_0057b700(); FUN_0057bac0(); FUN_0057aaa0(); FUN_0057cae0();
 if(c20)c20->update(this,dt); if(c24)c24->update(this,dt); if(c2c)c2c->update(this,dt); if(c28)c28->update(this,dt);
 if(((flags&0x20) && stamp<DAT_01079f68.FUN_006e2ac0()) || DAT_01079858->active()) {
 bool ok=FUN_00576ba0(this);
 if(c30 && ok && c30->state==0) c30->state=DAT_01079858->active()?2:1;
 if(c34 && ok && c34->state==0) c34->state=DAT_01079858->active()?2:1;
 stamp=DAT_01079f68.FUN_006e2ac0();
 }
 if(c30)c30->update(this,dt); if(c34)c34->update(this,dt); if(c38)c38->FUN_00579dc0(dt);
 if(fade>0.0f) fade=1.0-(float)(DAT_01090bb0-start)/(DAT_00f5dff4*1000.0); if(fade<0.0f)fade=0.0f;
 FUN_0048fd80(&unk48); flags&=~3;
 }
 }
}
}   // namespace f3m_0057e0a0

// @f3 0x00578210 (community match, verified in this file)
namespace f3m_00578210 {
struct State578210 {
    unsigned char kind;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    State578210();
};
// pdb: BSMasterParticleSystem::GetActiveEmitterObjCount | BSPSysMultiTargetEmitterCtlr.obj | tesv_win, objrun_open, low
State578210::State578210()
    : unk04(0), unk08(0), unk0C(0), unk10(0), unk14(0), unk18(0) { kind = 2; }
}   // namespace f3m_00578210

// @f3 0x0056fc20 (community match, verified in this file)
extern const float DAT_00f62004,DAT_00f62010,DAT_00f6201c,DAT_00f62028,DAT_00f62034,DAT_00f62040,DAT_00f6204c;
namespace f3m_0056fc20 {
struct Properties56 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; unsigned unk1C;};
struct Metric56 {float FUN_008f8410();};
struct Body56 {int unk00; int unk04; int unk08; int unk0C; Properties56 unk10; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; Metric56 unkD0; Properties56* Properties(){return &unk10;} unsigned Type(){Properties56* p=Properties();return p?p->unk1C:0;}};
struct Input56 {int unk00,unk04;Body56* unk08;};
// pdb: TESHavokUtilities::ScaleGameplayImpulseForce | TEShavokUtilities.obj | fnv360_0822_retail, call_gap_sim, low, conflict (bridge: hkpVehicleDefaultSuspension::calcSuspension)
// pdb params: afBaseForce, apPushedBody, abUseMinMass
float FUN_0056fc20(float scale,Input56* input,bool adjust){if(!input)return scale;Body56* body=input->unk08;unsigned type=body?body->Type():0;float value;switch(type&0x7f){case 14:value=DAT_00f62010;break;case 8:case 29:value=DAT_00f6201c;break;case 10:value=DAT_00f62028;break;case 20:value=DAT_00f6204c;break;default:value=DAT_00f62034;break;}if(adjust){float metric=body?body->unkD0.FUN_008f8410():0.0f;if(metric<DAT_00f62040)value=value*(metric/DAT_00f62040);}value=DAT_00f62004*value;value=value*scale;return value;}
}   // namespace f3m_0056fc20

// @f3 0x00573570 (community match, verified in this file)
extern int DAT_0106e9cc;
namespace f3m_00573570 {
namespace waterAlloc573 {struct Heap {void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;}
struct WaterScalar573 {float value;static void* operator new[](unsigned int size){return waterAlloc573::DAT_01090a78.FUN_0086b930(size);}};
struct bhkWaterListener {virtual ~bhkWaterListener();int unk04,unk08,unk0C,unk10;bhkWaterListener();};
struct BGSZoneTargetListener {virtual ~BGSZoneTargetListener();int unk04;BGSZoneTargetListener();};
struct WaterList573 {int first,count,capacity;WaterList573(){capacity=0;first=0;count=0;}~WaterList573();};
struct TESWaterListener:bhkWaterListener,BGSZoneTargetListener {float scale;WaterScalar573* data;int unk24;int side;int unk2C,unk30;WaterList573 list;TESWaterListener();virtual ~TESWaterListener();};
// pdb: TESWaterListener::TESWaterListener | TESWaterListener.obj | fnv360_0822_retail, call_seq, medium
TESWaterListener::TESWaterListener():bhkWaterListener(),BGSZoneTargetListener(),scale(1.0f){side=DAT_0106e9cc;data=new WaterScalar573[side*side];}
}   // namespace f3m_00573570

// @f3 0x005688b0 (community match, verified in this file)
#include <new>
#include <windows.h>
extern unsigned int DAT_010f3170;
extern unsigned int DAT_00f79e58;
namespace f3m_005688b0 {

extern void* __cdecl FUN_0089eb90(unsigned int size);
extern "C" void __cdecl FUN_0089ec10(void* storage, unsigned int size);

struct GameAllocator {
    static void* operator new(size_t size)
    {
        return FUN_0089eb90(size);
    }

    static void operator delete(void* storage, size_t size)
    {
        FUN_0089ec10(storage, size);
    }
};

struct RefObj {
    virtual void v000();
    virtual void DeleteThis();
    long m_refs;

    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }

    void DecRefCount()
    {
        if (InterlockedDecrement(&m_refs) == 0)
            DeleteThis();
    }
};

struct Thing : GameAllocator {
    int unk00;
    int unk04;
    void* unk08;
    int unk0c;
    int unk10;
    Thing(float f, int n);
};

struct TlsObj {
    void FUN_008f6d90(void* storage, unsigned int size, int pool);
};

struct __declspec(align(16)) Info {
    unsigned int formID;
    void* unk04;
    char unk08;
    char unk09;
    char unk0a;
    char unk0b;
    void* unk0c;
    int unk10;
    int unk14;
    const int GetCapacity() const { return unk14 & 0x3fffffff; }
    int unk18;
    int unk1c;
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    float m9;
    float m10;
    float m11;
    float m12;
    float m13;
    float m14;
    float m15;
    Info() throw();
    void SetIdentity();
    ~Info();
};

void Info::SetIdentity()
{
    m1 = 0.0f;
    m2 = 0.0f;
    m3 = 0.0f;
    m4 = 0.0f;
    m6 = 0.0f;
    m7 = 0.0f;
    m8 = 0.0f;
    m9 = 0.0f;
    m11 = 0.0f;
    m0 = 1.0f;
    m5 = 1.0f;
    m10 = 1.0f;
    m12 = 0.0f;
    m13 = 0.0f;
    m14 = 0.0f;
    m15 = 0.0f;
}

Info::~Info()
{
    int count = unk14;
    if ((static_cast<unsigned int>(count) >> 31) == 0) {
        int entryCount = GetCapacity();
        TlsObj* tl = static_cast<TlsObj*>(TlsGetValue(DAT_010f3170));
        tl->FUN_008f6d90(unk0c, entryCount * sizeof(__int64), 0x17);
    }
}

struct Item : RefObj, GameAllocator {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    explicit Item(Info* src);
};

struct C {
    NiPointer<Item> m_p0;
    NiPointer<Item> m_p1;
    void FUN_005688b0(float f, int n);
};

// pdb: CameraCaster::Init | CameraCaster.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afRadius, aiGroup
void C::FUN_005688b0(float f, int n)
{
    Thing* t = new Thing(f, 1);
    Info a;
    Info b;

    unsigned int firstId = (n << 16) | 0x23;
    unsigned int id = (DAT_00f79e58 + 1) & 0xffff;
    DAT_00f79e58 = id;
    if (id == 0) {
        id = 10;
        DAT_00f79e58 = id;
    }
    unsigned int secondId = (id << 16) | 0x23;

    a.formID = firstId;
    a.unk04 = t ? t->unk08 : 0;
    a.SetIdentity();
    m_p0 = new Item(&a);

    b.formID = secondId;
    b.unk04 = t ? t->unk08 : 0;
    b.SetIdentity();
    m_p1 = new Item(&b);
}
}   // namespace f3m_005688b0

// @f3 0x0056ec10 (community match, verified in this file)
namespace f3m_0056ec10 {

namespace f3m_0056ec10 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};
inline float MaxF(float a, float b) { return a > b ? a : b; }
inline float MinF(float a, float b) { return a < b ? a : b; }
struct Box {
    Vec4 min;
    Vec4 max;
};
struct Child { void FUN_0056cb70(Box* out); };
struct Target;
struct Mgr;
struct Sub28 { Mgr* FUN_00410f00(); };
struct Obj20 { int u00, u04, u08, u0c, u10, u14, u18, u1c, u20; unsigned char flags24; unsigned char b25, b26, b27; Sub28 sub28; };

// Layouts inferred from the two local callees; names remain descriptive stand-ins.
struct CollisionNode;
struct Group;
struct Transform;
struct Body;
struct GameObject;
template<class T> struct ArrayView {
    T* data;
    int size;
    int capacityAndFlags;
};
void __cdecl FUN_00901f10(void* array, int elementSize);
struct Heap {
    void FUN_008f6d90(void* memory, int bytes, int category);
};
extern unsigned long DAT_010f3170;
template<class T> struct LocalArray : ArrayView<T> {
    LocalArray() { this->data=0; this->size=0; this->capacityAndFlags=(int)0x80000000u; }
    ~LocalArray() {
        if (this->capacityAndFlags >= 0)
            static_cast<Heap*>(TlsGetValue(DAT_010f3170))->FUN_008f6d90(
                this->data, (this->capacityAndFlags & 0x3fffffff)*sizeof(T), 0x17);
    }
    void append(const T& value) {
        if (this->size == (this->capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this,sizeof(T));
        this->data[this->size]=value;
        ++this->size;
    }
    int find(T value) const {
        for (int i=0; i<this->size; ++i)
            if (this->data[i]==value) return i;
        return -1;
    }
};
struct Collidable {
    int active00, unk04, unk08, unk0c;
    signed char ownerOffset10;
    unsigned char unk11, unk12, unk13;
    int bounds14;
    unsigned char type18, unk19, unk1a, unk1b;
    unsigned int flags1c;
};
struct CollisionNode {
    int unk00, unk04, unk08, unk0c;
    Collidable collision10;
};
struct Transform {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38(int* input, Box* output);
};
struct Body {
    int unk00, unk04, unk08;
    void* object0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    unsigned char motionTypeD8;
};
struct GameObject {
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
    virtual bool v100();
};
GameObject* __cdecl FUN_0056fbf0(Collidable* collision);
struct Group {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Target* target18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    ArrayView<CollisionNode*> items48;
};

struct Target { int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24; ArrayView<Group*> p28; ArrayView<Group*> p34; int u40, u44, u48, u4c, u50; Transform* transform54; int u58, u5c, u60, u64, u68, u6c, u70, u74, u78, u7c, u80, u84, u88, u8c, u90, u94, u98, u9c, ua0, ua4, ua8, uac, ub0, ub4, ub8, ubc, uc0, uc4, uc8, ucc, ud0, ud4, ud8, udc, ue0; ArrayView<CollisionNode*> subE4; };
struct Mgr {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual Target* v98();
};
extern Mgr* DAT_01071564;
extern const float FUN_00de731c;
extern const float FUN_00de6e60;
struct Owner {
    int u00, u04;
    Child* children[6];
    Obj20* obj20;
    __declspec(noinline) void FUN_0056d930(Box* box, ArrayView<CollisionNode*>* a, Target* t);
    __declspec(noinline) void FUN_0056e770(Box* box, ArrayView<Group*>* a);
    void FUN_0056d6f0(GameObject* object);
    void FUN_0056dba0(void* object, LocalArray<Body*>* output);
    void FUN_0056ec10();
};


// Keep the four-lane comparisons and the original xyz mask, including ordered
// comparisons on NaNs; the fourth lane does not determine the final result.
__forceinline unsigned int GreaterEqualMask(const Vec4& a, const Vec4& b) {
    return (a.x >= b.x ? 8 : 0) | (a.y >= b.y ? 4 : 0) |
           (a.z >= b.z ? 2 : 0) | (a.w >= b.w ? 1 : 0);
}
__forceinline unsigned int LessEqualMask(const Vec4& a, const Vec4& b) {
    return (a.x <= b.x ? 8 : 0) | (a.y <= b.y ? 4 : 0) |
           (a.z <= b.z ? 2 : 0) | (a.w <= b.w ? 1 : 0);
}
__forceinline bool KeepsBounds(const Box& box, const Box& other) {
    unsigned int contained = GreaterEqualMask(other.min, box.min) &
                             GreaterEqualMask(box.max, other.max);
    if ((contained & 14) != 14) return false;
    unsigned int intersects = LessEqualMask(box.min, other.max) &
                              GreaterEqualMask(box.max, other.min);
    return (intersects & 14) == 14;
}

__declspec(noinline) void Owner::FUN_0056d930(
    Box* box, ArrayView<CollisionNode*>* a, Target* t)
{
    for (int i=0; i<a->size; ++i) {
        Collidable* collision=&a->data[i]->collision10;
        if (!collision->active00) continue;
        Box bounds;
        t->transform54->v38(&collision->bounds14, &bounds);
        if (KeepsBounds(*box,bounds)) continue;
        if ((collision->flags1c & 0x7f) != 0x1e) continue;
        GameObject* object=FUN_0056fbf0(collision);
        if (object && object->v100()) FUN_0056d6f0(object);
    }
}

__declspec(noinline) void Owner::FUN_0056e770(Box* box, ArrayView<Group*>* a)
{
    LocalArray<Body*> candidates;
    for (int i=0; i<a->size; ++i) {
        Group* group=a->data[i];
        Target* t=group->target18;
        for (int j=0; j<group->items48.size; ++j) {
            Collidable* collision=&group->items48.data[j]->collision10;
            if (!collision->active00) continue;
            Box bounds;
            t->transform54->v38(&collision->bounds14,&bounds);
            if (KeepsBounds(*box,bounds)) continue;
            if (collision->type18 != 1) continue;
            Body* body=reinterpret_cast<Body*>(
                reinterpret_cast<char*>(collision) + collision->ownerOffset10);
            if (!body) continue;
            unsigned char type=body->motionTypeD8;
            if (type != 6 && type != 7 && type != 9) candidates.append(body);
        }
    }
    LocalArray<Body*> processed;
    for (int i=0; i<candidates.size; ++i) {
        Body* body=candidates.data[i];
        if (processed.find(body) != -1) continue;
        LocalArray<Body*> related;
        FUN_0056dba0(body ? body->object0c : 0, &related);
        for (int j=0; j<related.size; ++j) processed.append(related.data[j]);
    }
}

// pdb: LoadedAreaBound::CheckForDynamicBodiesOutsideBound | LoadedAreaBound.obj | fnv360_1110_retail, objrun_prop, low
void Owner::FUN_0056ec10()
{
    Box cur;
    cur.max.x = FUN_00de731c; cur.max.y = FUN_00de731c; cur.max.z = FUN_00de731c; cur.max.w = FUN_00de731c;
    cur.min.x = FUN_00de6e60; cur.min.y = FUN_00de6e60; cur.min.z = FUN_00de6e60; cur.min.w = FUN_00de6e60;
    for (int i = 0; i < 6; i++) {
        Box b;
        children[i]->FUN_0056cb70(&b);
        cur.max.x = MaxF(cur.max.x, b.max.x);
        cur.max.y = MaxF(cur.max.y, b.max.y);
        cur.max.z = MaxF(cur.max.z, b.max.z);
        cur.max.w = MaxF(cur.max.w, b.max.w);
        cur.min.x = MinF(cur.min.x, b.min.x);
        cur.min.y = MinF(cur.min.y, b.min.y);
        cur.min.z = MinF(cur.min.z, b.min.z);
        cur.min.w = MinF(cur.min.w, b.min.w);
    }
    {
        Box box = cur;
        Mgr* m;
        if (obj20->flags24 & 1)
            m = obj20->sub28.FUN_00410f00();
        else
            m = DAT_01071564;
        if (m) {
            Target* t = m->v98();
            if (t) {
                FUN_0056d930(&box, &t->subE4, t);
                FUN_0056e770(&box, &t->p28);
                FUN_0056e770(&box, &t->p34);
            }
        }
    }
}
}

}   // namespace f3m_0056ec10

// @f3 0x0056edf0 (community match, verified in this file)
namespace f3m_0056edf0 {



namespace w56edf0
{

// ---- Havok 5.5.0 (hk550 SDK forms; FPU build) ----
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned long hkUlong;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
    char m_bool;
};

class hkVector4
{
public:
    inline hkVector4() {}
    inline hkVector4(const hkVector4& v) { *this = v; }
    inline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    inline void mul4(hkSimdRealParameter rs)
    {
        hkReal s = hkReal(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    inline hkReal& operator()(int i) { return (&x)[i]; }
    static inline const hkVector4& getZero();
    __declspec(align(16)) hkReal x;
    hkReal y, z, w;
};
extern const hkVector4 hkQuadReal0000;
inline const hkVector4& hkVector4::getZero()
{
    const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
    return zero;
}

class hkAabb
{
public:
    hkAabb() {}
    hkVector4 m_min;
    hkVector4 m_max;
};

enum HK_MEMORY_CLASS { HK_MEMORY_CLASS_ARRAY = 0x17 };

class hkThreadMemory
{
public:
    void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS);
    static inline hkThreadMemory& getInstance();
};

template <typename T> class hkThreadLocalData
{
public:
    inline T getData() const { return (T)(hkUlong)TlsGetValue(m_slotID); }
    unsigned long m_slotID;
};
extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
inline hkThreadMemory& hkThreadMemory::getInstance()
{
    return *hkThreadMemory__s_threadMemoryInstance.getData();
}

namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}

template <typename T> class hkArray
{
public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FORCE_SIGNED = -1,
        LOCKED_FLAG = int(0x40000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };
    inline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    inline ~hkArray() { releaseMemory(); }
    inline T& operator[](int i) { return m_data[i]; }
    inline const T& operator[](int i) const { return m_data[i]; }
    inline int getSize() const { return m_size; }
    inline int getCapacity() const { return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK)); }
    inline hkBool isEmpty() const { return m_size == 0; }
    inline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().deallocateChunk(m_data, getCapacity() * sizeof(T), HK_MEMORY_CLASS_ARRAY);
        }
    }
    inline int indexOf(const T& t) const
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (m_data[i] == t)
            {
                return i;
            }
        }
        return -1;
    }
    inline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil::_reserve(this, newSize, sizeof(T));
        }
    }
    inline void pushBack(const T& t)
    {
        if (m_size == getCapacity())
        {
            hkArrayUtil::_reserveMore(this, sizeof(T));
        }
        m_data[m_size++] = t;
    }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

class hkpShape;
class hkpWorld;
class hkpMotion;

class hkpCdBody
{
public:
    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

class hkpTypedBroadPhaseHandle
{
public:
    inline int getType() const { return m_type; }
    inline hkUint32 getCollisionFilterInfo() const { return m_collisionFilterInfo; }
    hkUint32 m_id;
    hkInt8 m_type;
    hkInt8 m_ownerOffset;
    hkUint16 m_objectQualityType;
    hkUint32 m_collisionFilterInfo;
};

class hkpCollidable : public hkpCdBody
{
public:
    inline void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this) + m_ownerOffset);
    }
    inline int getType() const { return m_broadPhaseHandle.getType(); }
    inline hkUint32 getCollisionFilterInfo() const { return m_broadPhaseHandle.getCollisionFilterInfo(); }
    hkInt8 m_ownerOffset;
    hkUint8 m_forceCollideOntoPpu;
    hkUint16 m_shapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle;
};

class hkStatisticsCollector;
class hkClass;

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject() {}
    virtual void calcStatistics(hkStatisticsCollector* collector) const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    hkUint16 m_memSizeAndFlags;
    hkInt16 m_referenceCount;
};

class hkpWorldObject : public hkReferencedObject
{
public:
    enum BroadPhaseType
    {
        BROAD_PHASE_INVALID,
        BROAD_PHASE_ENTITY,
        BROAD_PHASE_PHANTOM,
        BROAD_PHASE_BORDER,
        BROAD_PHASE_MAX_ID
    };
    inline const hkpCollidable* getCollidable() const { return &m_collidable; }
    inline hkUlong getUserData() const { return m_userData; }
    hkpWorld* m_world;
    hkUlong m_userData;
    hkpCollidable m_collidable;
};

inline hkpWorldObject* hkGetWorldObject(const hkpCollidable* collidable)
{
    return reinterpret_cast<hkpWorldObject*>(const_cast<void*>(collidable->getOwner()));
}

class hkpPhantom : public hkpWorldObject
{
};

inline hkpPhantom* __cdecl hkGetPhantom(const hkpCollidable* collidable)
{
    if (collidable->getType() == hkpWorldObject::BROAD_PHASE_PHANTOM)
    {
        return static_cast<hkpPhantom*>(hkGetWorldObject(collidable));
    }
    return 0;
}

class TESObjectREFR;
class Actor;
class NiPoint3;

// The phantom held by each LoadedAreaBound layer (its overlapping-collidable list at +0xc0).
class hkpAabbPhantom : public hkpPhantom
{
public:
    inline hkArray<hkpCollidable*>& getOverlappingCollidables() { return m_overlappingCollidables; }

    hkUint32 m_unk30, m_unk34, m_unk38, m_unk3c, m_unk40, m_unk44, m_unk48, m_unk4c;
    hkUint32 m_unk50, m_unk54, m_unk58, m_unk5c, m_unk60, m_unk64, m_unk68, m_unk6c;
    hkUint32 m_unk70, m_unk74, m_unk78, m_unk7c, m_unk80, m_unk84, m_unk88, m_unk8c;
    hkUint32 m_unk90, m_unk94, m_unk98, m_unk9c, m_unka0, m_unka4, m_unka8, m_unkac;
    hkUint32 m_unkb0, m_unkb4, m_unkb8, m_unkbc;
    hkArray<hkpCollidable*> m_overlappingCollidables;
};

class hkpMotion : public hkReferencedObject
{
public:
    enum MotionType
    {
        MOTION_INVALID,
        MOTION_DYNAMIC,
        MOTION_SPHERE_INERTIA,
        MOTION_STABILIZED_SPHERE_INERTIA,
        MOTION_BOX_INERTIA,
        MOTION_STABILIZED_BOX_INERTIA,
        MOTION_KEYFRAMED,
        MOTION_FIXED,
        MOTION_THIN_BOX_INERTIA,
        MOTION_CHARACTER,
        MOTION_MAX_ID
    };
    inline MotionType getType() const { return static_cast<MotionType>(m_type); }
    inline const hkVector4& getLinearVelocity() const { return m_linearVelocity; }
    virtual void setMass(hkReal m);
    virtual void setMassInv(hkReal mInv);
    virtual void getInertiaLocal(void* inertia) const;
    virtual void getInertiaWorld(void* inertia) const;
    virtual void setInertiaLocal(const void* inertia);
    virtual void setInertiaInvLocal(const void* inertiaInv);
    virtual void getInertiaInvLocal(void* inertiaInv) const;
    virtual void getInertiaInvWorld(void* inertiaInvOut) const;
    virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
    virtual void setPosition(const hkVector4& position);
    virtual void setRotation(const void* rotation);
    virtual void setPositionAndRotation(const hkVector4& position, const void* rotation);
    virtual void setTransform(const void* transform);
    virtual void setLinearVelocity(const hkVector4& newVel);
    hkInt8 m_type;
    hkUint8 m_deactivationIntegrateCounter;
    hkUint16 m_deactivationNumInactiveFrames[2];
    hkUint32 m_unk10, m_unk14, m_unk18, m_unk1c, m_unk20, m_unk24, m_unk28, m_unk2c;
    hkUint32 m_unk30, m_unk34, m_unk38, m_unk3c, m_unk40, m_unk44, m_unk48, m_unk4c;
    hkUint32 m_unk50, m_unk54, m_unk58, m_unk5c, m_unk60, m_unk64, m_unk68, m_unk6c;
    hkUint32 m_unk70, m_unk74, m_unk78, m_unk7c, m_unk80, m_unk84, m_unk88, m_unk8c;
    hkUint32 m_unk90, m_unk94, m_unk98, m_unk9c, m_unka0, m_unka4, m_unka8, m_unkac;
    hkUint32 m_unkb0, m_unkb4, m_unkb8, m_unkbc, m_unkc0, m_unkc4, m_unkc8, m_unkcc;
    hkVector4 m_linearVelocity;
};

class hkpEntity : public hkpWorldObject
{
public:
    void activate();
    hkUint32 m_unk30, m_unk34, m_unk38, m_unk3c, m_unk40, m_unk44, m_unk48, m_unk4c;
    hkUint32 m_unk50, m_unk54, m_unk58, m_unk5c, m_unk60, m_unk64, m_unk68, m_unk6c;
    hkUint32 m_unk70, m_unk74, m_unk78, m_unk7c, m_unk80, m_unk84, m_unk88, m_unk8c;
    hkUint32 m_unk90, m_unk94, m_unk98, m_unk9c, m_unka0, m_unka4, m_unka8, m_unkac;
    hkUint32 m_unkb0, m_unkb4, m_unkb8, m_unkbc, m_unkc0, m_unkc4, m_unkc8, m_unkcc;
    hkpMotion m_motion;
};

class hkpRigidBody : public hkpEntity
{
public:
    inline hkpMotion* getRigidMotion() const { return const_cast<hkpMotion*>(&m_motion); }
    inline const hkVector4& getLinearVelocity() const { return getRigidMotion()->getLinearVelocity(); }
    inline hkpMotion::MotionType getMotionType() const { return getRigidMotion()->getType(); }
    inline void setLinearVelocity(const hkVector4& newVel)
    {
        activate();
        getRigidMotion()->setLinearVelocity(newVel);
    }
};

inline hkpRigidBody* hkGetRigidBody(const hkpCollidable* collidable)
{
    if (collidable->getType() == hkpWorldObject::BROAD_PHASE_ENTITY)
    {
        return static_cast<hkpRigidBody*>(hkGetWorldObject(collidable));
    }
    return 0;
}

// ---- Gamebryo 2.x ----
void* __cdecl FUN_0089e810(unsigned int uiSize);   // NiMalloc
void __cdecl FUN_0089e890(void* pvMem);           // NiFree
typedef void* NiTMapIterator;

class NiPoint3
{
public:
    NiPoint3() {}
    float x, y, z;
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    unsigned int m_uiRefCount;
};

template <class TKEY, class TVAL> class NiTMapItem
{
public:
    NiTMapItem* m_pkNext;
    TKEY m_key;
    TVAL m_val;
};

template <class T> class NiTPointerAllocator
{
};

template <class TPARENT, class TKEY, class TVAL> class NiTMapBase
{
public:
    typedef NiTMapItem<TKEY, TVAL> EntryType;
    class AntiBloatAllocator : public TPARENT
    {
    public:
        unsigned int m_uiCount;
    };

    NiTMapBase(unsigned int uiHashSize = 37)
    {
        m_uiHashSize = uiHashSize;
        m_kAllocator.m_uiCount = 0;
        unsigned int uiSize = sizeof(NiTMapItem<TKEY, TVAL>*) * m_uiHashSize;
        m_ppkHashTable = (NiTMapItem<TKEY, TVAL>**)FUN_0089e810(uiSize);
        unsigned int uiBytes = m_uiHashSize * sizeof(NiTMapItem<TKEY, TVAL>*);
        memset(m_ppkHashTable, 0, uiBytes);
    }
    virtual ~NiTMapBase()
    {
        RemoveAll();
        FUN_0089e890(m_ppkHashTable);
    }

    void SetAt(TKEY key, TVAL val);
    bool RemoveAt(TKEY key);
    void RemoveAll();
    bool GetAt(TKEY key, TVAL& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTMapItem<TKEY, TVAL>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    NiTMapIterator GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void GetNext(NiTMapIterator& pos, TKEY& key, TVAL& val) const
    {
        NiTMapItem<TKEY, TVAL>* pkItem = (NiTMapItem<TKEY, TVAL>*)pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }

    virtual unsigned int KeyToHashIndex(TKEY key) const;
    virtual bool IsKeysEqual(TKEY key1, TKEY key2) const;
    virtual void SetValue(NiTMapItem<TKEY, TVAL>* pkItem, TKEY key, TVAL val);
    virtual void ClearValue(NiTMapItem<TKEY, TVAL>* pkItem);
    virtual NiTMapItem<TKEY, TVAL>* NewItem() = 0;
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem) = 0;

    unsigned int m_uiHashSize;
    NiTMapItem<TKEY, TVAL>** m_ppkHashTable;
    AntiBloatAllocator m_kAllocator;
};

template <class TKEY, class TVAL>
class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<unsigned int>, TKEY, TVAL>
{
public:
    NiTPointerMap(unsigned int uiHashSize = 37) : NiTMapBase<NiTPointerAllocator<unsigned int>, TKEY, TVAL>(uiHashSize) {}
    virtual ~NiTPointerMap() { this->RemoveAll(); }
    virtual NiTMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem);
};

// ---- Bethesda ----
template <class T, unsigned int RESIZE_SIZE = 1024> class BSSimpleArray
{
public:
    BSSimpleArray() { _InitialSetup(0, 0); }
    virtual ~BSSimpleArray() { Clear(true); }
    virtual T* _Allocate(unsigned int auiCount);
    virtual void _Deallocate(T* apBuffer);
    virtual T* _Reallocate(T* apBuffer, unsigned int auiCount);

    void _InitialSetup(unsigned int auiAllocSize, unsigned int auiSize)
    {
        pBuffer = 0;
        iSize = 0;
        SimpleArrayStorage = 0;
        if (auiSize > auiAllocSize)
            auiAllocSize = auiSize;
        if (auiAllocSize > 0)
        {
            pBuffer = _Allocate(auiAllocSize);
            SimpleArrayStorage = auiAllocSize;
        }
        if (auiSize > 0)
            iSize = auiSize;
    }
    void Clear(bool abFreeMemory)
    {
        if (pBuffer)
        {
            if (abFreeMemory)
            {
                _Deallocate(pBuffer);
                pBuffer = 0;
                SimpleArrayStorage = 0;
            }
            iSize = 0;
        }
    }
    unsigned int GetSize() const { return iSize; }
    T& operator[](unsigned int auiIndex) { return pBuffer[auiIndex]; }
    void ReallocateStorage(unsigned int auiNewAllocSize, unsigned int auiCopyCount);
    unsigned int ReserveIndex()
    {
        if (iSize == SimpleArrayStorage)
        {
            if (SimpleArrayStorage == 0)
            {
                pBuffer = _Allocate(4);
                SimpleArrayStorage = 4;
            }
            else
            {
                unsigned int newCapacity = SimpleArrayStorage > RESIZE_SIZE ? SimpleArrayStorage + RESIZE_SIZE : SimpleArrayStorage * 2;
                ReallocateStorage(newCapacity, iSize);
                SimpleArrayStorage = newCapacity;
            }
        }
        iSize = iSize + 1;
        return iSize - 1;
    }
    unsigned int Add(const T& aItem)
    {
        unsigned int index = ReserveIndex();
        pBuffer[index] = aItem;
        return index;
    }

    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};


class bhkRefObject : public NiRefObject
{
public:
    hkReferencedObject* m_phkObject;
};

class bhkWorldObject : public bhkRefObject
{
public:
    void FUN_00c24b70();   // empty access hook around Havok writes
};

class bhkRigidBody : public bhkWorldObject
{
public:
    inline hkpRigidBody* GetRigidBody() { return this ? (hkpRigidBody*)m_phkObject : 0; }
    inline const hkVector4& GetLinearVelocity()
    {
        hkpRigidBody* pb = GetRigidBody();
        return pb ? pb->getLinearVelocity() : hkVector4::getZero();
    }
    inline void SetLinearVelocity(const hkVector4& arVel)
    {
        hkpRigidBody* pb = GetRigidBody();
        if (pb)
        {
            FUN_00c24b70();
            pb->setLinearVelocity(arVel);
            FUN_00c24b70();
        }
    }
};

class bhkAabbPhantom : public bhkWorldObject
{
public:
    inline hkpAabbPhantom* GetPhantom() { return (hkpAabbPhantom*)m_phkObject; }
};

class bhkCharacterListener
{
public:
    void* m_vtbl;
    unsigned int m_uiFlags;
    inline void SetStuckQuadruped(bool abStuck)
    {
        if (abStuck)
            m_uiFlags |= 0x20;
        else
            m_uiFlags &= ~0x20;
    }
};

class bhkCharacterController;

class CFilter
{
public:
    inline CFilter(unsigned int auiFilter) : m_uiFilter(auiFilter) {}
    inline int GetLayer() const { return m_uiFilter & 0x7f; }
    unsigned int m_uiFilter;
};

class TESObjectREFR
{
public:
    virtual void Unk_00(); virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03();
    virtual void Unk_04(); virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07();
    virtual void Unk_08(); virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B();
    virtual void Unk_0C(); virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F();
    virtual void Unk_10(); virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13();
    virtual void Unk_14(); virtual void Unk_15(); virtual void Unk_16(); virtual void Unk_17();
    virtual void Unk_18(); virtual void Unk_19(); virtual void Unk_1A(); virtual void Unk_1B();
    virtual void Unk_1C(); virtual void Unk_1D(); virtual void Unk_1E(); virtual void Unk_1F();
    virtual void Unk_20(); virtual void Unk_21(); virtual void Unk_22(); virtual void Unk_23();
    virtual void Unk_24(); virtual void Unk_25(); virtual void Unk_26(); virtual void Unk_27();
    virtual void Unk_28(); virtual void Unk_29(); virtual void Unk_2A(); virtual void Unk_2B();
    virtual void Unk_2C(); virtual void Unk_2D(); virtual void Unk_2E(); virtual void Unk_2F();
    virtual void Unk_30(); virtual void Unk_31(); virtual void Unk_32(); virtual void Unk_33();
    virtual void Unk_34(); virtual void Unk_35(); virtual void Unk_36(); virtual void Unk_37();
    virtual void Unk_38(); virtual void Unk_39(); virtual void Unk_3A(); virtual void Unk_3B();
    virtual void Unk_3C(); virtual void Unk_3D(); virtual void Unk_3E(); virtual void Unk_3F();
    virtual bool IsActor();                                                          // +0x100
    virtual void Unk_41(); virtual void Unk_42(); virtual void Unk_43();
    virtual void Unk_44(); virtual void Unk_45(); virtual void Unk_46(); virtual void Unk_47();
    virtual void Unk_48(); virtual void Unk_49(); virtual void Unk_4A(); virtual void Unk_4B();
    virtual void Unk_4C(); virtual void Unk_4D(); virtual void Unk_4E(); virtual void Unk_4F();
    virtual void Unk_50(); virtual void Unk_51(); virtual void Unk_52(); virtual void Unk_53();
    virtual void Unk_54(); virtual void Unk_55(); virtual void Unk_56(); virtual void Unk_57();
    virtual void Unk_58(); virtual void Unk_59(); virtual void Unk_5A(); virtual void Unk_5B();
    virtual void Unk_5C(); virtual void Unk_5D(); virtual void Unk_5E(); virtual void Unk_5F();
    virtual void Unk_60(); virtual void Unk_61(); virtual void Unk_62(); virtual void Unk_63();
    virtual void Unk_64(); virtual void Unk_65(); virtual void Unk_66(); virtual void Unk_67();
    virtual void Unk_68(); virtual void Unk_69(); virtual void Unk_6A(); virtual void Unk_6B();
    virtual void Unk_6C(); virtual void Unk_6D(); virtual void Unk_6E(); virtual void Unk_6F();
    virtual void Unk_70(); virtual void Unk_71(); virtual void Unk_72(); virtual void Unk_73();
    virtual void Unk_74(); virtual void Unk_75(); virtual void Unk_76(); virtual void Unk_77();
    virtual void Unk_78(); virtual void Unk_79(); virtual void Unk_7A(); virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos() const;                                            // +0x1f4
    virtual void Unk_7E(); virtual void Unk_7F();
    virtual void Unk_80(); virtual void Unk_81(); virtual void Unk_82(); virtual void Unk_83();
    virtual void Unk_84(); virtual void Unk_85(); virtual void Unk_86(); virtual void Unk_87();
    virtual void Unk_88(); virtual void Unk_89(); virtual void Unk_8A(); virtual void Unk_8B();
    virtual void Unk_8C(); virtual void Unk_8D(); virtual void Unk_8E(); virtual void Unk_8F();
    virtual void Unk_90(); virtual void Unk_91(); virtual void Unk_92(); virtual void Unk_93();
    virtual void Unk_94(); virtual void Unk_95(); virtual void Unk_96(); virtual void Unk_97();
    virtual void Unk_98(); virtual void Unk_99(); virtual void Unk_9A(); virtual void Unk_9B();
    virtual void Unk_9C(); virtual void Unk_9D(); virtual void Unk_9E(); virtual void Unk_9F();
    virtual void Unk_A0(); virtual void Unk_A1(); virtual void Unk_A2(); virtual void Unk_A3();
    virtual void Unk_A4(); virtual void Unk_A5(); virtual void Unk_A6(); virtual void Unk_A7();
    virtual void Unk_A8(); virtual void Unk_A9();
    virtual void SetPos(const NiPoint3* apPos);                                      // +0x2a8
};

class Actor : public TESObjectREFR
{
public:
    bhkCharacterController* FUN_00764ea0();   // the actor's character controller, or 0
};

namespace TESHavokUtilities
{
TESObjectREFR* __cdecl FUN_0056fbf0(const hkpCollidable* apCollidable);   // FindCollidableRef
}

class TESObjectCELL
{
public:
    inline bool IsInterior() const { return (cCellFlags & 1) != 0; }
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char cCellFlags;
};

class GridCellArray;

class LoadedAreaBound : public NiRefObject
{
public:
    NiPointer<bhkAabbPhantom> m_spPhantoms[6];
    TESObjectCELL* m_pCell;
    NiTPointerMap<bhkRigidBody*, unsigned short> m_kBodyFlags;
    unsigned int unk34, unk38, unk3c;
    float m_fDistance;

    bool FUN_0056d2d0(TESObjectCELL* apCell, GridCellArray* apCellGrid, hkAabb* arBound);   // GetBoundFromCell
    void FUN_0056e2d0(TESObjectCELL* apCell, hkAabb* arBound);                             // Create
    void FUN_0056ec10();                                                                    // CheckForDynamicBodiesOutsideBound
    void FUN_0056ccd0(Actor* apActor, const NiPoint3& arCurLoc, NiPoint3& arWarpLoc);
    void FUN_0056cc80();                                                                    // Clear
    void FUN_0056dba0(bhkRigidBody* apBody, hkArray<hkpRigidBody*>* apBodies);             // collect child bodies
    void FUN_0056edf0(TESObjectCELL* apCell, GridCellArray* apCellGrid);                   // Update
};

// pdb: LoadedAreaBound::Update | LoadedAreaBound.obj | fnv360_1110_retail, objrun_prop, low
// pdb params: apCell, apCellGrid
void LoadedAreaBound::FUN_0056edf0(TESObjectCELL* apCell, GridCellArray* apCellGrid)
{
    if (apCell != m_pCell && apCell)
    {
        hkAabb loadedAreaAABB;
        if (!FUN_0056d2d0(apCell, apCellGrid, &loadedAreaAABB))
            return;
        FUN_0056e2d0(apCell, &loadedAreaAABB);
        m_pCell = apCell;
        FUN_0056ec10();
    }
    if (!apCell)
    {
        m_pCell = apCell;
        FUN_0056cc80();
        return;
    }
    unsigned short uscurrentFlag = 1;
    NiTPointerMap<bhkRigidBody*, unsigned short> curhitMap(37);
    for (unsigned int ui = 0; ui < 6; ui++, uscurrentFlag <<= 1)
    {
        bool buseWarp = m_pCell->IsInterior() || ui == 0;
        hkpAabbPhantom* pphantom = m_spPhantoms[ui]->GetPhantom();
        const hkArray<hkpCollidable*>& rcols = pphantom->getOverlappingCollidables();
        if (!rcols.isEmpty())
        {
            int isize = rcols.getSize();
            hkArray<hkpPhantom*> phantomA;
            hkArray<hkpRigidBody*> bodyA;
            bodyA.reserve(rcols.getSize());
            for (int i = 0; i < isize; i++)
            {
                hkpRigidBody* prb = hkGetRigidBody(rcols[i]);
                if (prb)
                    bodyA.pushBack(prb);
                else
                {
                    hkpPhantom* pp = hkGetPhantom(rcols[i]);
                    if (pp)
                        phantomA.pushBack(pp);
                }
            }
            for (int i = 0; i < phantomA.getSize(); i++)
            {
                if (buseWarp)
                {
                    CFilter filter(phantomA[i]->getCollidable()->getCollisionFilterInfo());
                    TESObjectREFR* pref = TESHavokUtilities::FUN_0056fbf0(phantomA[i]->getCollidable());
                    if (filter.GetLayer() == 30 && pref && pref->IsActor())
                    {
                        Actor* pactor = (Actor*)pref;
                        NiPoint3 warpLoc;
                        FUN_0056ccd0(pactor, *pactor->GetPos(), warpLoc);
                        pactor->SetPos(&warpLoc);
                        if (pactor->FUN_00764ea0())
                            ((bhkCharacterListener*)((char*)pactor->FUN_00764ea0() + 0x290))->SetStuckQuadruped(false);
                    }
                }
            }
            hkArray<hkpRigidBody*> warpedBodies;
            for (int i = 0; i < bodyA.getSize(); i++)
            {
                hkpRigidBody* prb = bodyA[i];
                if (warpedBodies.indexOf(prb) == -1)
                {
                    TESObjectREFR* pref = TESHavokUtilities::FUN_0056fbf0(prb->getCollidable());
                    if (prb && prb->getMotionType() != hkpMotion::MOTION_KEYFRAMED && prb->getMotionType() != hkpMotion::MOTION_FIXED && prb->getMotionType() != hkpMotion::MOTION_CHARACTER)
                    {
                        bhkRigidBody* pbhkRb = (bhkRigidBody*)prb->getUserData();
                        if (!buseWarp)
                        {
                            unsigned short usbodyCurrFlags;
                            if (!m_kBodyFlags.GetAt(pbhkRb, usbodyCurrFlags) || !(usbodyCurrFlags & uscurrentFlag))
                            {
                                hkVector4 vel(pbhkRb->GetLinearVelocity());
                                float fscale = ui != 1 ? m_fDistance * -1.0 : m_fDistance;
                                hkSimdReal s(fscale);
                                vel.mul4(s);
                                float& z = vel(2);
                                z = z * -1.0;
                                pbhkRb->SetLinearVelocity(vel);
                            }
                            unsigned short usborderFlags = uscurrentFlag;
                            if (curhitMap.GetAt(pbhkRb, usborderFlags))
                                usborderFlags |= uscurrentFlag;
                            curhitMap.SetAt(pbhkRb, usborderFlags);
                        }
                        else
                        {
                            hkArray<hkpRigidBody*> warpedChildBodies;
                            FUN_0056dba0(pbhkRb, &warpedChildBodies);
                            for (int j = 0; j < warpedChildBodies.getSize(); j++)
                                warpedBodies.pushBack(warpedChildBodies[j]);
                        }
                    }
                }
            }
        }
    }
    NiTMapIterator it = curhitMap.GetFirstPos();
    bhkRigidBody* pbody;
    unsigned short usflags;
    while (it)
    {
        curhitMap.GetNext(it, pbody, usflags);
        m_kBodyFlags.SetAt(pbody, usflags);
    }
    BSSimpleArray<bhkRigidBody*, 1024> removeBodyA;
    it = m_kBodyFlags.GetFirstPos();
    while (it)
    {
        m_kBodyFlags.GetNext(it, pbody, usflags);
        bool bcontains = curhitMap.GetAt(pbody, usflags);
        if (!bcontains)
            removeBodyA.Add(pbody);
    }
    for (unsigned int ui = 0; ui < removeBodyA.GetSize(); ui++)
        m_kBodyFlags.RemoveAt(removeBodyA[ui]);
}
}  // namespace w56edf0
}   // namespace f3m_0056edf0
