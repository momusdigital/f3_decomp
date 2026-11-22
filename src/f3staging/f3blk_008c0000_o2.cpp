#include <math.h>
#include <math.h>
#include <math.h>
#include <string.h>
#include <math.h>
#include <math.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <math.h>
#include <math.h>
#include <math.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <windows.h>
// src/f3staging/f3blk_008c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008c8cd0 (community match, verified in this file)
struct RTTI461 { const char* name; const RTTI461* base; };
extern const RTTI461 DAT_010927b0;
struct Object461 {
    virtual void slot00(); virtual void slot04(); virtual const RTTI461* GetRTTI();
};
struct Vector461 { float x,y,z; };
struct Position461 { void FUN_008c3400(Vector461); };
struct Provider461 { float FUN_00864650(int); };
__forceinline bool IsPosition461(const RTTI461* type) {
    while(type) {
        if(type==&DAT_010927b0) return true;
        type=type->base;
    }
    return false;
}
__forceinline Position461* CastPosition461(Object461* object) {
    if(!object) return 0;
    return IsPosition461(object->GetRTTI())?reinterpret_cast<Position461*>(object):0;
}
struct FUN_008c8cd0 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38;
    Provider461* provider; int index;
    void Apply(Object461*,int);
};
// pdb: NiFloatsExtraDataPoint3Controller::SynchronizePoseInterpolator | NiFloatsExtraDataPoint3Controller.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkInterp, usIndex
void FUN_008c8cd0::Apply(Object461* object,int unused) {
    Position461* position=CastPosition461(object);
    Provider461* values=provider;
    Vector461 value;
    value.x=values->FUN_00864650(index);
    value.y=values->FUN_00864650(index+1);
    value.z=values->FUN_00864650(index+2);
    position->FUN_008c3400(value);
}

// @f3 0x008dc980 (community match, verified in this file)
struct Entry466 { unsigned int unk00,unk04; void* state; };
struct Body466 { void FUN_008d8a30(Entry466*); void FUN_008d6140(Entry466*); };
struct Object466 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    unsigned int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    unsigned int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    unsigned int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    unsigned int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    unsigned int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    unsigned int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;
    unsigned int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    unsigned int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;
    unsigned int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    unsigned int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;
    unsigned int unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc;
    unsigned int unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc;
    unsigned int unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc;
    unsigned int unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c;
    unsigned int unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c;
    unsigned int unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c;
    unsigned int unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c;
    unsigned int unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c;
    unsigned int unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc;
    unsigned int unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc;
    unsigned int unk2e0,unk2e4,unk2e8,unk2ec,unk2f0,unk2f4,unk2f8,unk2fc;
    unsigned int unk300,unk304,unk308,unk30c;
    Body466* body;
};
struct Ref466 { unsigned int unk00,unk04; Object466* object; };
struct Link466 { Ref466* ref; };
struct Data466 {
    unsigned int unk00,unk04; Link466* link; unsigned int unk0c,unk10;
    Entry466** entries; int count;
};
struct FUN_008dc980 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44;
    Data466* data;
    void Update(bool);
};
// pdb: bhkRagdollController::UpdateConstraintsWorld | bhkRagdollController.obj | fnv360_0822_retail, call_seq, high
// pdb params: abAdd
void FUN_008dc980::Update(bool enable) {
    Data466* current=data;
    void* state=current->entries[0]?current->entries[0]->state:0;
    Ref466* ref=current->link->ref;
    if(ref && ref->object) {
        if(enable) { if(state) goto finished; } else { if(!state) goto finished; }
        Body466* body=ref->object->body;
        if(enable) {
            for(int i=0;i<current->count;++i) {
                Entry466* entry=current->entries[i];
                if(!entry->state) body->FUN_008d8a30(entry);
            }
        } else {
            for(int i=0;i<current->count;++i) {
                Entry466* entry=current->entries[i];
                if(entry->state) body->FUN_008d6140(entry);
            }
        }
    }
finished:;
}

// @f3 0x008d27c0 (community match, verified in this file)
#include <math.h>
class FUN_008d27c0_Obj {
public:
    float x;
    float y;
    float z;
    bool* FUN_008d2780(bool* flag);
    bool* FUN_008d27c0(bool* out, float eps);
};
// pdb: hkVector4::isNormalized3 | hkVector4.obj | tesv_win, objrun, medium
bool* FUN_008d27c0_Obj::FUN_008d27c0(bool* out, float eps)
{
    bool flag;
    bool* valid = FUN_008d2780(&flag);
    if (*valid) {
        float s = (y * y + x * x) + z * z;
        float d = s - 1.0;
        bool result;
        if (fabs(d) < eps) {
            result = true;
        } else {
            result = false;
        }
        *out = result;
    } else {
        *out = false;
    }
    return out;
}

// @f3 0x008dfa70 (community match, verified in this file)
struct Target_008dfa70 {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual int Resolve(void** key);
    __forceinline int CallIfPresent(void** key){if(this)return Resolve(key);return 0;}
};

struct NodeV {
    int unk00;
    int unk04;
    Target_008dfa70* target;
};

struct NodeListV {
    NodeV* head;
};

struct NodeOwnerV {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NodeListV list;
};

struct EntryV {
    int unk00;
    int unk04;
    NodeOwnerV* owner;
};

struct LookupV {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    EntryV* entry;
};

LookupV* __cdecl FUN_008f1d20(void* key);

// pdb: bhkRagdollController::GetCapsuleBoneShapeInfo | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low
// pdb params: apBone
int __stdcall FUN_008dfa70(void* key)
{
    if (key) {
        LookupV* lookup = FUN_008f1d20(key);
        if (lookup) {
            EntryV* entry = lookup->entry;
            if (entry) {
                NodeOwnerV* owner = entry->owner;
                if (owner) {
                    NodeListV* list = &owner->list;
                    if (list) {
                        NodeV* node = list->head;
                        if (node) {
                            return node->target->CallIfPresent(&key);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// @f3 0x008dd0c0 (community match, verified in this file)
namespace f3m_008dd0c0 {
struct Class_008dd0c0 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4;
    unsigned char unkD8;
    bool* FUN_008dd0c0(bool* out);
};

// pdb: hkpEntity::isFixedOrKeyframed | FOIslandActivationListener.obj | tesv_win, call_seq, medium
bool* Class_008dd0c0::FUN_008dd0c0(bool* out)
{
    bool flag;
    if (unkD8 == 7 || unkD8 == 6) {
        flag = true;
    } else {
        flag = false;
    }
    *out = flag;
    return out;
}
}   // namespace f3m_008dd0c0

// @f3 0x008d18b0 (community match, verified in this file)
namespace f3m_008d18b0 {
struct Owner16 {
    virtual void unknown000();
    virtual void unknown004();
    virtual void unknown008();
    virtual void unknown00c();
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();
    virtual void unknown01c();
    virtual void unknown020();
    virtual void unknown024();
    virtual void unknown028();
    virtual void unknown02c();
    virtual void unknown030();
    virtual void unknown034();
    virtual void unknown038();
    virtual void unknown03c();
    virtual void unknown040();
    virtual void unknown044();
    virtual void unknown048();
    virtual void unknown04c();
    virtual void unknown050();
    virtual void unknown054();
    virtual void unknown058();
    virtual void unknown05c();
    virtual void unknown060();
    virtual void unknown064();
    virtual void unknown068();
    virtual void unknown06c();
    virtual void unknown070();
    virtual void unknown074();
    virtual void unknown078();
    virtual void unknown07c();
    virtual void unknown080();
    virtual void unknown084();
    virtual void unknown088();
    virtual void unknown08c();
    virtual void unknown090();
    virtual void unknown094();
    virtual void unknown098();
    virtual void unknown09c();
    virtual void unknown0a0();
    virtual void unknown0a4();
    virtual void unknown0a8();
    virtual void unknown0ac();
    virtual void unknown0b0();
    virtual void unknown0b4();
    virtual void unknown0b8();
    virtual void unknown0bc();
    virtual void unknown0c0();
    virtual void unknown0c4();
    virtual void unknown0c8();
    virtual void unknown0cc();
    virtual void unknown0d0();
    virtual void unknown0d4();
    virtual void unknown0d8();
    virtual void unknown0dc();
    virtual void unknown0e0();
    virtual void unknown0e4();
    virtual void unknown0e8();
    virtual void GetPoint(Vector461*);
    void FUN_008d18b0(Object461*, int);
};
// pdb: NiPoint3InterpController::SynchronizePoseInterpolator | NiPoint3InterpController.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkInterp, usIndex
void Owner16::FUN_008d18b0(Object461* object, int unused) {
    Position461* position = CastPosition461(object);
    Vector461 value;
    GetPoint(&value);
    position->FUN_008c3400(value);
}
}   // namespace f3m_008d18b0

// @f3 0x008d11c0 (community match, verified in this file)
struct RTTI8d11c0 { const char* name; const RTTI8d11c0* base; };
extern const RTTI8d11c0 DAT_01091f90;
struct Object8d11c0 {
    virtual void slot00(); virtual void slot04();
    virtual const RTTI8d11c0* GetRTTI();
};
struct Float8d11c0 { void FUN_008b6690(float value); };
__forceinline bool IsFloat8d11c0(const RTTI8d11c0* type) {
    while (type) {
        if (type == &DAT_01091f90) return true;
        type = type->base;
    }
    return false;
}
__forceinline Float8d11c0* CastFloat8d11c0(Object8d11c0* object) {
    if (!object) return 0;
    return IsFloat8d11c0(object->GetRTTI()) ? reinterpret_cast<Float8d11c0*>(object) : 0;
}
struct Controller8d11c0 {
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
    virtual void GetValue(float* value);
    void FUN_008d11c0(Object8d11c0* object, unsigned short index);
};
// pdb: NiFloatInterpController::SynchronizePoseInterpolator | NiFloatInterpController.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkInterp, usIndex
void Controller8d11c0::FUN_008d11c0(Object8d11c0* object, unsigned short index) {
    Float8d11c0* interpolator = CastFloat8d11c0(object);
    float value;
    GetValue(&value);
    interpolator->FUN_008b6690(value);
}

// @f3 0x008da7d0 (community match, verified in this file)
extern const char* DAT_010f2c30;
namespace f3m_008da7d0 {
void __cdecl FUN_00403230(char* output, unsigned int size, const char* format, ...);
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847e70(const char* label, const char* value);
char* __cdecl FUN_00847b90(const char* label, bool value);

__forceinline char* FormatViewerFlag(const char* label, const bool& value)
{
    return FUN_00847b90(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

struct CollisionPose
{
    unsigned int fields00[32];
    float orientation;
};

class bhkNiCollisionObject
{
public:
    virtual void UnknownSlot0();
    virtual void UnknownSlot1();
    virtual void UnknownSlot2();
    virtual void UnknownSlot3();
    virtual void UnknownSlot4();
    virtual void UnknownSlot5();
    virtual void UnknownSlot6();
    virtual void UnknownSlot7();
    virtual void UnknownSlot8();
    virtual void UnknownSlot9();
    virtual void UnknownSlot10();
    virtual void UnknownSlot11();
    virtual void UnknownSlot12();
    virtual void UnknownSlot13();
    virtual void UnknownSlot14();
    virtual void UnknownSlot15();
    virtual void UnknownSlot16();
    virtual void UnknownSlot17();
    virtual void UnknownSlot18();
    virtual void UnknownSlot19();
    virtual void UnknownSlot20();
    virtual void UnknownSlot21();
    virtual void UnknownSlot22();
    virtual void UnknownSlot23();
    virtual void UnknownSlot24();
    virtual void UnknownSlot25();
    virtual void UnknownSlot26();
    virtual void UnknownSlot27();
    virtual void UnknownSlot28();
    virtual void UnknownSlot29();
    virtual void UnknownSlot30();
    virtual void UnknownSlot31();
    virtual void UnknownSlot32();
    virtual void UnknownSlot33();
    virtual void UnknownSlot34();
    virtual void UnknownSlot35();
    virtual void UnknownSlot36();
    virtual void UnknownSlot37();
    virtual void UnknownSlot38();
    virtual void UnknownSlot39();
    virtual void UnknownSlot40();
    virtual void UnknownSlot41();
    virtual void UnknownSlot42();
    virtual void UnknownSlot43();
    virtual void UnknownSlot44();
    virtual bool IsKeyframed();

    void FUN_0084a8c0(ViewerStrings* strings);
    void FUN_008da7d0(ViewerStrings* strings);

    unsigned int unk04;
    CollisionPose* pose;
    bool active : 1;
    bool unk1 : 1;
    bool notify : 1;
    bool setLocal : 1;
    bool unk4 : 1;
    bool unk5 : 1;
    bool reset : 1;
    bool unk7 : 1;
    unsigned int worldObject;
};

// pdb: bhkNiCollisionObject::AddViewerStrings | bhkNiCollisionObject.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void bhkNiCollisionObject::FUN_008da7d0(ViewerStrings* strings)
{
    FUN_0084a8c0(strings);
    strings->Add(FUN_00847b50(DAT_010f2c30));

    char label[32];
    FUN_00403230(label, sizeof(label), "0x%8X", worldObject);
    strings->Add(FUN_00847e70("bhkWorldObject", label));
    strings->Add(FormatViewerFlag("bActive", active));
    strings->Add(FormatViewerFlag("bReset", reset));
    strings->Add(FormatViewerFlag("bNotify", notify));
    strings->Add(FormatViewerFlag("bSetLocal", setLocal));
    strings->Add(FUN_00847b90("bKeyframe", IsKeyframed()));
    bool faceDown = false;
    if (pose)
        faceDown = pose->orientation < 0.0f;
    strings->Add(FormatViewerFlag("bFaceDown", faceDown));
}

}   // namespace f3m_008da7d0

// @f3 0x008d6710 (community match, verified in this file)
#include <string.h>
extern const char* DAT_010f2ad4;
extern int DAT_010f2a64, DAT_010f31ac, DAT_010f31f8, DAT_010f3240;
extern int DAT_010f321c, DAT_010f3174, DAT_010f324c, DAT_01169204;
extern const char DAT_00e3278c[];
extern const char DAT_00e32784[];
extern const char DAT_00e3277c[];
extern const char DAT_00e32770[];
extern const char DAT_00e32764[];
extern const char DAT_00e32758[];
extern const char DAT_00e32750[];
extern const char DAT_00e32744[];
extern const char DAT_00e32730[];
namespace f3m_008d6710 {

char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847b90(const char* label, bool value);

__forceinline char* FormatViewerFlag(const char* label, const bool& value)
{
    return FUN_00847b90(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

char* __cdecl FUN_00847d80(const char* label, int value);


class bhkWorld
{
public:
    void FUN_008f80d0(ViewerStrings* strings);
    void FUN_008d6710(ViewerStrings* strings);

    unsigned int fields00[6];
    void* visualDebugger;
    unsigned char unk1C;
    bool enabled;
};

// pdb: bhkWorld::GetViewerStrings | bhkWorld.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void bhkWorld::FUN_008d6710(ViewerStrings* strings)
{
    FUN_008f80d0(strings);
    strings->Add(FUN_00847b50(DAT_010f2ad4));
    bool enabledForDisplay;
    memcpy(&enabledForDisplay, &enabled, sizeof(enabledForDisplay));
    strings->Add(FormatViewerFlag("Enabled", enabledForDisplay));
    strings->Add(FormatViewerFlag(DAT_00e3278c, visualDebugger != 0));
    strings->Add(FUN_00847d80(DAT_00e32784, DAT_010f2a64));
    strings->Add(FUN_00847d80(DAT_00e3277c, DAT_010f31ac));
    strings->Add(FUN_00847d80(DAT_00e32770, DAT_010f31f8));
    strings->Add(FUN_00847d80(DAT_00e32764, DAT_010f3240));
    strings->Add(FUN_00847d80(DAT_00e32758, DAT_010f321c));
    strings->Add(FUN_00847d80(DAT_00e32750, DAT_010f3174));
    strings->Add(FUN_00847d80(DAT_00e32744, DAT_010f324c));
    strings->Add(FUN_00847d80(DAT_00e32730, DAT_01169204));
}
}   // namespace f3m_008d6710

// @f3 0x008d3c10 (community match, verified in this file)
struct TimeObj { float* FUN_00401eb0(); };
extern TimeObj g_timeObj;
extern float g_dtRaw, g_clamped, g_smooth, g_smoothRate, g_scale;
extern float g_acc, g_out, g_step;
extern int g_count;
extern unsigned int g_mode;
extern unsigned char g_force;
float __cdecl FUN_0090d870(float a, float b);

// pdb: bhkWorld::SetDeltaTime | bhkWorld.obj | fnv360_0822_retail, uconst, low
// pdb params: afDeltaTime, abQuickSimulate, abSimulateEveryFrame
void FUN_008d3c10(float dt, bool a, bool b)
{
    g_dtRaw = dt;
    bool force = b || g_force;
    g_clamped = g_acc + dt;
    if (g_clamped > 166.66667f) {
        g_clamped = 166.66667f;
    } else if (g_clamped <= 0.0f) {
        g_count = 0;
        g_out = 0.0f;
        return;
    }
    unsigned int maxc = a ? 1 : 3;
    unsigned int n;
    switch (g_mode) {
    case 10:
        g_smooth = g_smooth + (g_clamped - g_smooth) * g_smoothRate;
        g_out = g_smooth;
        g_count = 1;
        g_acc = 0.0f;
        return;
    case 0:
        g_out = g_scale * g_step;
        n = (unsigned int)(g_clamped / g_out);
        g_count = n;
        if (n > maxc) { n = a ? 1 : 3; g_count = n; }
        if (n != 0) {
            g_acc = g_clamped - g_out * n;
            g_clamped = g_clamped - g_acc;
            g_acc = FUN_0090d870(g_acc, *g_timeObj.FUN_00401eb0());
            return;
        }
        if (!force && g_out * 0.5 > g_clamped) {
            g_acc = g_clamped; g_clamped = 0.0f; g_out = 0.0f;
            return;
        }
        g_out = g_clamped; g_count = 1; g_acc = 0.0f;
        return;
    case 2:
        g_count = 1;
        g_out = dt;
        return;
    case 1:
        goto dflt2;
    case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        break;
    }
dflt2:
    if (!force && g_clamped < 0.008333334f) {
        g_count = 0; g_acc = g_clamped; g_clamped = 0.0f; g_out = 0.0f;
        return;
    }
    g_acc = 0.0f;
    n = (unsigned int)(g_clamped / g_step);
    g_count = n;
    if (n > maxc) { n = a ? 1 : 3; g_count = n; }
    if (n != 0) { g_out = g_clamped / n; return; }
    g_count = 1; g_out = g_clamped;
    return;
}

// @f3 0x008c1c80 (community match, verified in this file)
#include <new>

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);

namespace LegacySequenceConversion {

struct Type {
    const char* name;
    const Type* parent;
};

extern const Type DAT_01092778, DAT_01092768, DAT_0108f42c, DAT_01091f44;

class Object {
public:
    virtual void Slot00();
    virtual void Dispose();
    virtual const Type* GetRTTI();

    long references;
};

struct Controller : Object {
    unsigned char unknown08[0x28];
    Controller* next;
};

struct SequenceExtra : Object {
    unsigned int unknown08;
    const char* sequence;
};

struct LegacySource : Object {
    const char* name;
    Controller* controller;
    Object** extras;
    unsigned short extraCount;

    void FUN_00824be0(unsigned int index);
    void FUN_00824c30();
};

struct Stream {
    unsigned char unknown00[0xd8];
    unsigned int version;
    unsigned char unknowndc[0x144];
    Object** objects;
    unsigned int unknown224;
    unsigned int count;
};

void* __cdecl FUN_0089eb90(unsigned int bytes);

class FUN_008c1b70 {
    unsigned char unknown00[0x30];
public:
    unsigned int state;

    FUN_008c1b70(const char* name, unsigned int firstCapacity, unsigned int secondCapacity) throw();
    static void* operator new(size_t bytes) throw() { return FUN_0089eb90(bytes); }
    void FUN_008c15b0(Object* extra);
    void FUN_008c19c0(const char* sequence, Controller* controller);
};

Object* __cdecl FUN_00424d50(const Type* type, Object* object);

__forceinline bool IsKindOf(const Type* actual, const Type* desired)
{
    bool matches;
    if (actual) {
        do {
            if (actual == desired) {
                matches = true;
                return matches;
            }
            actual = actual->parent;
        } while (actual);
    }
    matches = false;
    return matches;
}

template<class T>
__forceinline T* Cast(Object* object, const Type* desired)
{
    if (!object)
        return 0;
    const bool matches = IsKindOf(object->GetRTTI(), desired);
    return matches ? static_cast<T*>(object) : 0;
}

__forceinline void Retain(Object* object)
{
    if (object)
        InterlockedIncrement(&object->references);
}

__forceinline void Release(Object* object)
{
    if (object && InterlockedDecrement(&object->references) == 0)
        object->Dispose();
}

// pdb: NiSequence::ConvertSequence | NiSequence.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream, uiIndex, pcSequenceName
FUN_008c1b70* __cdecl FUN_008c1c80(Stream* stream, unsigned int index, const char* name)
{
    if (stream->version >= 0x4010003)
        return 0;
    if (index >= stream->count)
        return 0;

    Object* entry = stream->objects[index];
    LegacySource* source = static_cast<LegacySource*>(FUN_00424d50(&DAT_01092778, entry));
    if (!source)
        return 0;
    if (!name)
        name = source->name;

    FUN_008c1b70* result = new FUN_008c1b70(name, 12, 12);
    result->state = 0;

    for (unsigned int i = 0; i < source->extraCount; ++i) {
        const unsigned short extraIndex = static_cast<unsigned short>(i);
        Object* entry = source->extras[extraIndex];
        Object* extra = FUN_00424d50(&DAT_01092768, entry);
        if (extra) {
            result->FUN_008c15b0(extra);
            source->FUN_00824be0(i);
            break;
        }
    }

    Controller* controller = source->controller;
    Retain(controller);
    for (unsigned int i = 0; i < source->extraCount; ++i) {
        SequenceExtra* extra = Cast<SequenceExtra>(
            source->extras[static_cast<unsigned short>(i)], &DAT_0108f42c);
        Controller* typedController = Cast<Controller>(controller, &DAT_01091f44);
        result->FUN_008c19c0(extra->sequence, typedController);

        Controller* next = controller->next;
        Retain(next);
        Controller* attached = controller->next;
        if (attached) {
            Release(attached);
            controller->next = 0;
        }
        if (controller != next) {
            Release(controller);
            controller = next;
            Retain(controller);
        }
        Release(next);
    }
    source->FUN_00824c30();
    Release(controller);
    return result;
}

} // namespace LegacySequenceConversion

// @f3 0x008da260 (community match, verified in this file)
struct NiPoint3 { float x,y,z; };
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    NiTransform FUN_0056fe20(const NiTransform& xform) const;
    void FUN_00477790(NiTransform& kDest) const;
};

bool __cdecl FUN_00464d70(NiPoint3 const& a, NiPoint3 const& b, float c);
bool __cdecl FUN_008d9cd0(NiPoint3 const* a, NiPoint3 const* b, float c);

struct NiNodeStub;
struct NiAVObjectStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNodeStub* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
};
struct NiNodeStub : NiAVObjectStub
{
};

struct bhkNiCollisionObjectStub;
typedef void(__cdecl* TransformCallback)(bhkNiCollisionObjectStub*, int);
extern bool DAT_010f2c2c;
extern TransformCallback DAT_010f2c28;

struct bhkNiCollisionObjectStub
{
    int unk00;
    int unk04;
    NiAVObjectStub* m_pPointer;
    unsigned short m_ucFlags;
    bool GetFlag(unsigned int ucBit) const
    {
        return (m_ucFlags >> ucBit) & 1;
    }
    void FUN_008da260(const NiTransform& kWorld);
};

// @fnv 0x00c6bbb0
// pdb: bhkNiCollisionObject::SetTransform | bhkNiCollisionObject.obj | fnv360_0721_beta, caller_sim, medium
// pdb params: arTrans
void bhkNiCollisionObjectStub::FUN_008da260(const NiTransform& kWorld)
{
    NiAVObjectStub* pkObject = m_pPointer;
    if (!pkObject)
        return;

    NiNodeStub* pkParent = pkObject->m_pParentNode;
    if ((unsigned char)(m_ucFlags >> 3) & 1)
    {
        NiTransform kLocal;
        if (pkParent)
        {
            pkParent->m_kWorldSpaceTransform.FUN_00477790(kLocal);
            kLocal = kLocal.FUN_0056fe20(kWorld);
        }
        else
        {
            kLocal = kWorld;
        }
        pkObject->m_kLocalTransform.m_kOrientation = kLocal.m_kOrientation;
        pkObject->m_kLocalTransform.m_kTranslation = kLocal.m_kTranslation;
    }

    int iResult = 0;
    if (DAT_010f2c2c)
    {
        iResult = 3;
    }
    else
    {
        if (!FUN_008d9cd0((const NiPoint3*)&pkObject->m_kWorldSpaceTransform.m_kOrientation, (const NiPoint3*)&kWorld.m_kOrientation,
                          0.001f))
            iResult = 2;
        if (!FUN_00464d70(pkObject->m_kWorldSpaceTransform.m_kTranslation, kWorld.m_kTranslation, 0.01f))
            iResult |= 1;
        if (!iResult)
            return;
    }

    pkObject->m_kWorldSpaceTransform.m_kOrientation = kWorld.m_kOrientation;
    pkObject->m_kWorldSpaceTransform.m_kTranslation = kWorld.m_kTranslation;
    if (DAT_010f2c28 && (unsigned char)(m_ucFlags >> 2) & 1)
        DAT_010f2c28(this, iResult);
}

// @f3 0x008da090 (community match, verified in this file)
namespace f3m_008da090 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct CloneProcess;
class NiInterpolator
{
  public:
    virtual void v0();
    virtual void DeleteThis();
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual NiInterpolator* Clone(CloneProcess*);
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
struct MapProxy
{
    bool FUN_00bea7b0(NiInterpolator*, NiInterpolator*&);
};
struct CloneProcess
{
    MapProxy* map;
};
struct OwnerProxy
{
    int unk00, unk04, unk08;
    unsigned short unk0c, unk0e;
    NiInterpolator* object;
    void FUN_0086b760(OwnerProxy*, CloneProcess*);
    void FUN_008da000(NiInterpolator*);
    void FUN_008da090(OwnerProxy*, CloneProcess*);
};
// @fnv 0x00c6ba30
// pdb: bhkNiCollisionObject::CopyMembers | bhkNiCollisionObject.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apDest, arCloneData
void OwnerProxy::FUN_008da090(OwnerProxy* dest, CloneProcess* process)
{
    FUN_0086b760(dest, process);
    dest->unk0c = unk0c;
    NiPointer<NiInterpolator> source = object;
    if (source)
    {
        NiPointer<NiInterpolator> clone;
        NiInterpolator* result;
        if (process->map->FUN_00bea7b0(source, result))
            clone = result;
        else
            clone = source->Clone(process);
        dest->FUN_008da000(clone);
        clone = 0;
        source = 0;
    }
}
}   // namespace f3m_008da090

// @f3 0x008d6700 (community match, verified in this file)
namespace f3m_008d6700 {
// pdb: bhkWorld::QCinfoSize | bhkWorld.obj | fnv360_0822_retail, objrun, low
int __cdecl FUN_008d6700() { return 0xd0; }
}   // namespace f3m_008d6700

// @f3 0x008d3130 (community match, verified in this file)
extern float DAT_010f2a84;
namespace f3m_008d3130 {
// pdb: bhkWorld::ClearPickData | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void __cdecl FUN_008d3130() { DAT_010f2a84 = 0.0f; }
}   // namespace f3m_008d3130

// @f3 0x008d3580 (community match, verified in this file)
namespace n8d3580 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* memory); };
extern Heap DAT_01090a78;
struct Alloc { void FUN_008d3580(void* p); };
// pdb: hkFileSystem::`scalar deleting destructor' | HavokStream.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: bhkWorld::IsBatchingRemovals)
void Alloc::FUN_008d3580(void* p)
{
    if (p) {
        unsigned char* q = (unsigned char*)p;
        DAT_01090a78.FUN_0086ba60(q - q[-1]);
    }
}
}

// @f3 0x008d3140 (community match, verified in this file)
namespace f3m_008d3140 {
namespace f3m_008d3140 { extern unsigned char DAT_010f2a63; extern float DAT_010f2a84; }
// pdb: bhkWorld::SetPickCountOverride | bhkWorld.obj | fnv360_0822_retail, call_gap, low
// pdb params: abVal
void __cdecl FUN_008d3140(unsigned char v) { using namespace f3m_008d3140; if (DAT_010f2a63 != v) { DAT_010f2a63 = v; DAT_010f2a84 = 0.0f; } }
}   // namespace f3m_008d3140

// @f3 0x008d3ab0 (community match, verified in this file)
namespace f3m_008d3ab0 {
struct I8d3ab0 { void FUN_00903020(int u); };
struct O8d3ab0 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual I8d3ab0* Get(); void FUN_008d3ab0(int u); };
// pdb: bhkTaskletManagerCallback::~bhkTaskletManagerCallback | bhkWorld.obj | fnv360_0822_debug, objrun_open, low
void O8d3ab0::FUN_008d3ab0(int u) { if (this) { I8d3ab0* p = Get(); if (p) p->FUN_00903020(u); } }
}   // namespace f3m_008d3ab0

// @f3 0x008d4fa0 (community match, verified in this file)
namespace f3m_008d4fa0 {
namespace f3m_008d4fa0 { extern void (__cdecl* DAT_00f7b4d0)(void* p); }
struct O8d4fa0 { void FUN_008d3640(); O8d4fa0* FUN_008d4fa0(unsigned int flags); };
// pdb: bhkMemoryAllocator::`scalar deleting destructor' | bhkWorld.obj | fnv360_0822_retail, objrun_open, low
O8d4fa0* O8d4fa0::FUN_008d4fa0(unsigned int flags) { FUN_008d3640(); if (flags & 1) f3m_008d4fa0::DAT_00f7b4d0(this); return this; }
}   // namespace f3m_008d4fa0

// @f3 0x008db420 (community match, verified in this file)
namespace f3m_008db420 {
struct O8db420 { int a0, a4, a8, ac, a10, a14, a18, a1c, a20; O8db420* FUN_008db420(); };
O8db420* O8db420::FUN_008db420() { a0 = 0; a4 = 0; a8 = 0; ac = 0; a10 = 0; a14 = 0; a18 = 0; a1c = 0; a20 = 0; return this; }
}   // namespace f3m_008db420

// @f3 0x008d4d60 (community match, verified in this file)
namespace f3m_008d4d60 {
namespace f3m_008d4d60 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
void __cdecl FUN_008d4d60(f3m_008d4d60::P* p) { using namespace f3m_008d4d60; T* t = (T*)DAT_00d9b080(DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x35); }
}   // namespace f3m_008d4d60

// @f3 0x008d4e50 (community match, verified in this file)
namespace f3m_008d4e50 {
namespace f3m_008d4e50 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
// pdb: bhkMemoryAllocator::blockAlloc | bhkWorld.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: nbytes
void __cdecl FUN_008d4e50(f3m_008d4e50::P* p) { using namespace f3m_008d4e50; T* t = (T*)DAT_00d9b080(DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x2f); }
}   // namespace f3m_008d4e50

// @f3 0x008dd1b0 (community match, verified in this file)
namespace f3m_008dd1b0 {
namespace f3m_008dd1b0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
// pdb: BSSimpleArray<CaravanAIPackage *,1024>::~BSSimpleArray<CaravanAIPackage *,1024> | CaravanMenu.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: bhkRagdollController::QDriveControlData)
void __cdecl FUN_008dd1b0(f3m_008dd1b0::P* p) { using namespace f3m_008dd1b0; T* t = (T*)DAT_00d9b080(DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x3b); }
}   // namespace f3m_008dd1b0

// @f3 0x008d31a0 (community match, verified in this file)
namespace f3m_008d31a0 {
struct P8d31a0 { char pad[0xc]; int f0c; int f10; };
struct O8d31a0 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c(); virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac(); virtual void Slot(int a, int b, bool c); };
// pdb: bhkWorld::EnableObject | bhkWorld.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: BSTArrayAllocatorFunctor<class BSTSmallArrayHeapAllocator<36> >::Allocate)
// pdb params: apCollision, arData
void __cdecl FUN_008d31a0(O8d31a0* o, P8d31a0* p) { o->Slot(p->f0c, 0, p->f10 != 0); }
}   // namespace f3m_008d31a0

// @f3 0x008c5730 (community match, verified in this file)
namespace f3m_008c5730 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B008c5730 { virtual ~B008c5730(); virtual void v4(); int pad[13]; B008c5730() throw(); };
struct D008c5730 : B008c5730 { unsigned short value; virtual ~D008c5730(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D008c5730() throw(); };
D008c5730::D008c5730() throw() { value = 0; }
// pdb: NiMaterialColorController::CreateObject | NiMaterialColorController.obj | fnv360_0721_retail, objrun, medium
D008c5730* __cdecl FUN_008c5730() { return new D008c5730(); }
}   // namespace f3m_008c5730

// @f3 0x008c7460 (community match, verified in this file)
namespace f3m_008c7460 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B008c7460 { virtual ~B008c7460(); virtual void v4(); int pad[13]; B008c7460() throw(); };
struct D008c7460 : B008c7460 { unsigned short value; virtual ~D008c7460(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D008c7460() throw(); };
D008c7460::D008c7460() throw() { value = 0; }
// pdb: NiLightColorController::CreateObject | NiLightColorController.obj | fnv360_0721_retail, objrun, medium
D008c7460* __cdecl FUN_008c7460() { return new D008c7460(); }
}   // namespace f3m_008c7460

// @f3 0x008d5a20 (community match, verified in this file)
namespace f3m_008d5a20 {
struct Hh { };
struct Rr { void FUN_004e6210(bool b); };
struct Sv8d5a20 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual Rr* Get(); };
struct Ob8d5a20 { char pad[0x10]; Sv8d5a20* sv; };
struct Pa8d5a20 { char pad[0xc]; int f; };
// pdb: bhkWorld::DoSetFriction | bhkWorld.obj | fnv360_0721_beta, objrun, low, conflict (skyrim: bhkWorld::DoDisable)
// pdb params: apCollision, arData
void __cdecl FUN_008d5a20(Ob8d5a20* o, Pa8d5a20* p) { if (o) { Sv8d5a20* s = o->sv; if (s) { Rr* r = s->Get(); if (r) r->FUN_004e6210(p->f != 0); } } }
}   // namespace f3m_008d5a20

// @f3 0x008d9fd0 (community match, verified in this file)
namespace f3m_008d9fd0 {
namespace f3m_008d9fd0 { extern int DAT_010f2c20; }
struct B_008d9fd0 { virtual void v0(); int a04; int a08; unsigned short w0c; unsigned short w0e; int a10; B_008d9fd0(int arg); };
struct FUN_008d9fd0 : B_008d9fd0 { FUN_008d9fd0(int arg); virtual void v0(); };
// pdb: bhkNiCollisionObject::bhkNiCollisionObject | bhkNiCollisionObject.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: NiCollisionObject::NiCollisionObject)
// pdb params: apObject
FUN_008d9fd0::FUN_008d9fd0(int arg) : B_008d9fd0(arg) { a10 = 0; ++f3m_008d9fd0::DAT_010f2c20; w0c = 0x41; }
}   // namespace f3m_008d9fd0

// @f3 0x008d4fc0 (community match, verified in this file)
namespace f3m_008d4fc0 {
namespace f3m_008d4fc0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O008d4fc0 { void* vt; unsigned short w; O008d4fc0* FUN_008d4fc0(unsigned int flags); };
O008d4fc0* O008d4fc0::FUN_008d4fc0(unsigned int flags) { vt = &f3m_008d4fc0::DAT_00dcc494; if (flags & 1) { f3m_008d4fc0::T* t = (f3m_008d4fc0::T*)f3m_008d4fc0::DAT_00d9b080(f3m_008d4fc0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2f); } return this; }
}   // namespace f3m_008d4fc0

// @f3 0x008dbcd0 (community match, verified in this file)
namespace f3m_008dbcd0 {
struct Xf8dbcd0 {
    float m[12];
    Xf8dbcd0& FUN_008dbcd0(const Xf8dbcd0& o);
};
Xf8dbcd0& Xf8dbcd0::FUN_008dbcd0(const Xf8dbcd0& o)
{
    m[0] = o.m[0]; m[1] = o.m[1]; m[2] = o.m[2]; m[3] = o.m[3];
    m[4] = o.m[4]; m[5] = o.m[5]; m[6] = o.m[6]; m[7] = o.m[7];
    m[8] = o.m[8]; m[9] = o.m[9]; m[10] = o.m[10]; m[11] = o.m[11];
    return *this;
}
}   // namespace f3m_008dbcd0

// @f3 0x008dd0f0 (community match, verified in this file)
namespace f3m_008dd0f0 {
extern void (__stdcall* DAT_00e32b90)(void*);
class FUN_008dd0f0 {
public:
    virtual ~FUN_008dd0f0();
    void* p04; int a08; int a0c;
};
FUN_008dd0f0::~FUN_008dd0f0() {
    if (p04) {
        DAT_00e32b90(p04);
        p04 = 0; a0c = 0; a08 = 0;
    }
}
}   // namespace f3m_008dd0f0

// @f3 0x008d3600 (community match, verified in this file)
namespace f3m_008d3600 {
struct O8d3600 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void Slot4(int a, int b, int c); void FUN_008d3600(int* arr, int n, int c); };
void O8d3600::FUN_008d3600(int* arr, int n, int c) { for (int i = 0; i < n; i++) Slot4(arr[i], c, 0); }
}   // namespace f3m_008d3600

// @f3 0x008d4e10 (community match, verified in this file)
namespace f3m_008d4e10 {
namespace f3m_008d4e10 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00e3205c; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O8d4e10 { void* vt; unsigned short w; void FUN_00904690(); O8d4e10* FUN_008d4e10(unsigned int flags); };
O8d4e10* O8d4e10::FUN_008d4e10(unsigned int flags) { vt = &f3m_008d4e10::DAT_00e3205c; FUN_00904690(); if (flags & 1) { f3m_008d4e10::T* t = (f3m_008d4e10::T*)f3m_008d4e10::DAT_00d9b080(f3m_008d4e10::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2f); } return this; }
}   // namespace f3m_008d4e10

// @f3 0x008d1760 (community match, verified in this file)
extern const char* DAT_01092a30;
namespace f3m_008d1760 {
namespace register_name_008d1760 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00838420(NameArray*);
    void FUN_008d1760(NameArray*);
};
// pdb: NiFloatController::GetViewerStrings | NiFloatController.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pStrings
void Object::FUN_008d1760(NameArray* names) {
    FUN_00838420(names);
    void* value=FUN_00847b50(DAT_01092a30);
    names->Append(value);
}
}

}   // namespace f3m_008d1760

// @f3 0x008d0d30 (community match, verified in this file)
extern const char* DAT_01092a00;
namespace f3m_008d0d30 {
namespace register_name_008d0d30 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00825b40(NameArray*);
    void FUN_008d0d30(NameArray*);
};
// pdb: NiInterpolator::GetViewerStrings | NiInterpolator.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkStrings
void Object::FUN_008d0d30(NameArray* names) {
    FUN_00825b40(names);
    void* value=FUN_00847b50(DAT_01092a00);
    names->Append(value);
}
}

}   // namespace f3m_008d0d30

// @f3 0x008d0790 (community match, verified in this file)
extern const char* DAT_010928c4;
namespace f3m_008d0790 {
namespace register_name_008d0790 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008d1230(NameArray*);
    void FUN_008d0790(NameArray*);
};
void Object::FUN_008d0790(NameArray* names) {
    FUN_008d1230(names);
    void* value=FUN_00847b50(DAT_010928c4);
    names->Append(value);
}
}

}   // namespace f3m_008d0790

// @f3 0x008c56e0 (community match, verified in this file)
namespace f3m_008c56e0 {

void* __cdecl FUN_0089eb90(int size);

class FUN_008c56e0_Obj {
public:
    virtual void vf00();

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
    unsigned short unk38;

    void FUN_008d1880();
    void FUN_008d1800(FUN_008c56e0_Obj* other, int value);
    FUN_008c56e0_Obj* FUN_008c56e0(int value);
};

// pdb: NiMaterialColorController::CreateClone | NiMaterialColorController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kCloning
FUN_008c56e0_Obj* FUN_008c56e0_Obj::FUN_008c56e0(int value)
{
    FUN_008c56e0_Obj* result =
        reinterpret_cast<FUN_008c56e0_Obj*>(FUN_0089eb90(0x3c));

    if (result) {
        result->FUN_008d1880();
        *reinterpret_cast<unsigned int*>(result) = 0xe2f47c;
        result->unk38 = 0;
    } else {
        result = 0;
    }

    FUN_008d1800(result, value);

    unsigned short source = unk38;
    result->unk38 = source;
    return result;
}
}   // namespace f3m_008c56e0

// @f3 0x008d1230 (community match, verified in this file)
extern const char* DAT_01092a20;
namespace f3m_008d1230 {
namespace register_name_008d1230 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008b2830(NameArray*);
    void FUN_008d1230(NameArray*);
};
// pdb: NiFloatInterpController::GetViewerStrings | NiFloatInterpController.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_008d1230(NameArray* names) {
    FUN_008b2830(names);
    void* value=FUN_00847b50(DAT_01092a20);
    names->Append(value);
}
}

}   // namespace f3m_008d1230

// @f3 0x008ccba0 (community match, verified in this file)
extern const char* DAT_0109287c;
namespace f3m_008ccba0 {
namespace register_name_008ccba0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00825b40(NameArray*);
    void FUN_008ccba0(NameArray*);
};
// pdb: NiBSplineBasisData::GetViewerStrings | NiBSplineBasisData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pStrings
void Object::FUN_008ccba0(NameArray* names) {
    FUN_00825b40(names);
    void* value=FUN_00847b50(DAT_0109287c);
    names->Append(value);
}
}

}   // namespace f3m_008ccba0

// @f3 0x008c6e20 (community match, verified in this file)
extern const char* DAT_010927d8;
namespace f3m_008c6e20 {
namespace register_name_008c6e20 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00838420(NameArray*);
    void FUN_008c6e20(NameArray*);
};
// pdb: NiLookAtController::GetViewerStrings | NiLookAtController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_008c6e20(NameArray* names) {
    FUN_00838420(names);
    void* value=FUN_00847b50(DAT_010927d8);
    names->Append(value);
}
}

}   // namespace f3m_008c6e20

// @f3 0x008c5280 (community match, verified in this file)
extern const char* DAT_010927c0;
namespace f3m_008c5280 {
namespace register_name_008c5280 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00838420(NameArray*);
    void FUN_008c5280(NameArray*);
};
// pdb: NiPathController::GetViewerStrings | NiPathController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_008c5280(NameArray* names) {
    FUN_00838420(names);
    void* value=FUN_00847b50(DAT_010927c0);
    names->Append(value);
}
}

}   // namespace f3m_008c5280

// @f3 0x008c57d0 (community match, verified in this file)
extern const char* DAT_010927c8;
namespace f3m_008c57d0 {
namespace register_name_008c57d0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008d1930(NameArray*);
    void FUN_008c57d0(NameArray*);
};
// pdb: NiMaterialColorController::GetViewerStrings | NiMaterialColorController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkStrings
void Object::FUN_008c57d0(NameArray* names) {
    FUN_008d1930(names);
    void* value=FUN_00847b50(DAT_010927c8);
    names->Append(value);
}
}

}   // namespace f3m_008c57d0

// @f3 0x008c02e0 (community match, verified in this file)
extern const char* DAT_01092758;
namespace f3m_008c02e0 {
namespace register_name_008c02e0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00838420(NameArray*);
    void FUN_008c02e0(NameArray*);
};
// pdb: NiUVController::GetViewerStrings | NiUVController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pStrings
void Object::FUN_008c02e0(NameArray* names) {
    FUN_00838420(names);
    void* value=FUN_00847b50(DAT_01092758);
    names->Append(value);
}
}

}   // namespace f3m_008c02e0

// @f3 0x008d00f0 (community match, verified in this file)
extern const char* DAT_010928b4;
extern const char DAT_00e2dbd4[];
namespace f3m_008d00f0 {
namespace extended_008d00f0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct String { char* data; unsigned short length,capacity; void* FUN_0083f9c0(const char*); };
struct Object {
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
    String value;
    void FUN_008b20a0(NameArray*);
    void FUN_008d00f0(NameArray*);
};
// pdb: NiBlendColorInterpolator::GetViewerStrings | NiBlendColorInterpolator.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: pkStrings
void Object::FUN_008d00f0(NameArray* names) {
    FUN_008b20a0(names);
    void* handle=FUN_00847b50(DAT_010928b4);
    names->Append(handle);
    handle=value.FUN_0083f9c0(DAT_00e2dbd4);
    names->Append(handle);
}
}
}   // namespace f3m_008d00f0

// @f3 0x008cf5b0 (community match, verified in this file)
extern const char* DAT_010928a4;
extern const char DAT_00e2f268[];
namespace f3m_008cf5b0 {
namespace extended_008cf5b0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct String { char* data; unsigned short length,capacity; void* FUN_008374b0(const char*); };
struct Object {
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
    String value;
    void FUN_008b20a0(NameArray*);
    void FUN_008cf5b0(NameArray*);
};
// pdb: NiBlendQuaternionInterpolator::GetViewerStrings | NiBlendQuaternionInterpolator.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: pkStrings
void Object::FUN_008cf5b0(NameArray* names) {
    FUN_008b20a0(names);
    void* handle=FUN_00847b50(DAT_010928a4);
    names->Append(handle);
    handle=value.FUN_008374b0(DAT_00e2f268);
    names->Append(handle);
}
}
}   // namespace f3m_008cf5b0

// @f3 0x008ca830 (community match, verified in this file)
extern const char* DAT_01092834;
extern const char DAT_00e30204[];
namespace f3m_008ca830 {
namespace extended_008ca830 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847d80(const char*,unsigned int);
struct Object {
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
    unsigned int value;
    void FUN_008d1e20(NameArray*);
    void FUN_008ca830(NameArray*);
};
// pdb: NiBSplinePoint3Interpolator::GetViewerStrings | NiBSplinePoint3Interpolator.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void Object::FUN_008ca830(NameArray* names) {
    FUN_008d1e20(names);
    void* handle=FUN_00847b50(DAT_01092834);
    names->Append(handle);
    handle=FUN_00847d80(DAT_00e30204,value);
    names->Append(handle);
}
}
}   // namespace f3m_008ca830

// @f3 0x008c8e70 (community match, verified in this file)
extern const char* DAT_01092804;
extern const char DAT_00e2fcc0[];
namespace f3m_008c8e70 {
namespace extended_008c8e70 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847d30(const char*,unsigned int);
struct Object {
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
    unsigned int value;
    void FUN_008d10a0(NameArray*);
    void FUN_008c8e70(NameArray*);
};
// pdb: NiFloatsExtraDataPoint3Controller::GetViewerStrings | NiFloatsExtraDataPoint3Controller.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pkStrings
void Object::FUN_008c8e70(NameArray* names) {
    FUN_008d10a0(names);
    void* handle=FUN_00847b50(DAT_01092804);
    names->Append(handle);
    handle=FUN_00847d30(DAT_00e2fcc0,value);
    names->Append(handle);
}
}
}   // namespace f3m_008c8e70

// @f3 0x008cabd0 (community match, verified in this file)
extern const char* DAT_0109283c;
extern const char FUN_00e2d99c[];
extern const char FUN_00e3031c[];
namespace f3m_008cabd0 {


char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);
char* __cdecl FUN_00847d80(const char* label, int value);

struct FloatValue008cabd0 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float unk1C;
    int unk20;

    void FUN_008d1e20(f3m_008da7d0::ViewerStrings* strings);
    void FUN_008cabd0(f3m_008da7d0::ViewerStrings* strings);
};

// pdb: NiBSplineFloatInterpolator::GetViewerStrings | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void FloatValue008cabd0::FUN_008cabd0(f3m_008da7d0::ViewerStrings* strings)
{
    char* value;
    unsigned int index;
    unsigned short capacity;
    unsigned short growBy;

    FUN_008d1e20(strings);

    value = FUN_00847b50(DAT_0109283c);

    index = strings->firstFree;
    capacity = strings->capacity;
    growBy = strings->growBy;

    if (index >= capacity) {
        strings->FUN_00555790((unsigned int)(growBy + index));
    }
    strings->FUN_005b3880(index, value);

    value = FUN_00847dd0(FUN_00e2d99c, unk1C);

    index = strings->firstFree;
    capacity = strings->capacity;
    growBy = strings->growBy;

    if (index >= capacity) {
        strings->FUN_00555790((unsigned int)(growBy + index));
    }
    strings->FUN_005b3880(index, value);

    value = FUN_00847d80(FUN_00e3031c, unk20);

    index = strings->firstFree;
    capacity = strings->capacity;
    growBy = strings->growBy;

    if (index >= capacity) {
        strings->FUN_00555790((unsigned int)(growBy + index));
    }
    strings->FUN_005b3880(index, value);
}

}   // namespace f3m_008cabd0

// @f3 0x008c2e20 (community match, verified in this file)
extern void* DAT_010927a0;
extern const char DAT_00e2f268[];
extern const char DAT_00e2f254[];
namespace f3m_008c2e20 {
namespace task0726 {
struct ViewerArray
{
    void* m_pBase;
    unsigned int m_unk04;
    unsigned short m_usMax;
    unsigned short m_usNext;
    unsigned short m_unk0c;
    unsigned short m_usGrow;
    void FUN_00555790(unsigned int newSize);
    void FUN_005b3880(unsigned int index, void* elem);
};

struct ViewerNameHolder
{
    unsigned int m_unk00;
    void* FUN_008374b0(const char* name);
};

void* FUN_00847b50(void* arg);
void* FUN_00847e20(const char* name, unsigned int value);

struct FUN_00a3c270_cls
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    ViewerNameHolder m_nameA;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_uiFilterValue;
    void FUN_008b6de0(ViewerArray* out);
    void FUN_008c2e20(ViewerArray* out);
};

// @fnv 0x00a3c270
// pdb: NiQuaternionInterpolator::GetViewerStrings | NiQuaternionInterpolator.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void FUN_00a3c270_cls::FUN_008c2e20(ViewerArray* out)
{
    this->FUN_008b6de0(out);
    void* pValue = FUN_00847b50(DAT_010927a0);
    unsigned int uiIndex = out->m_usNext;
    if (uiIndex >= out->m_usMax)
    {
        out->FUN_00555790(uiIndex + out->m_usGrow);
    }
    out->FUN_005b3880(uiIndex, &pValue);

    void* r = m_nameA.FUN_008374b0(DAT_00e2f268);
    uiIndex = out->m_usNext;
    unsigned int uiMax = out->m_usMax;
    pValue = r;
    if (uiIndex >= uiMax)
    {
        out->FUN_00555790(uiIndex + out->m_usGrow);
    }
    out->FUN_005b3880(uiIndex, &pValue);

    unsigned int v = m_uiFilterValue;
    void* s = FUN_00847e20(DAT_00e2f254, v);
    uiIndex = out->m_usNext;
    uiMax = out->m_usMax;
    pValue = s;
    if (uiIndex >= uiMax)
    {
        out->FUN_00555790(uiIndex + out->m_usGrow);
    }
    out->FUN_005b3880(uiIndex, &pValue);
}

}
}   // namespace f3m_008c2e20

// @f3 0x008c2490 (community match, verified in this file)
extern const char* DAT_01092790;
extern const char DAT_00e2d884[];
namespace f3m_008c2490 {
namespace viewer_008c2490 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847d80(const char*,unsigned int);
struct Object {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int value;
    void FUN_00825b40(NameArray*);
    void FUN_008c2490(NameArray*);
};
// pdb: NiRotData::GetViewerStrings | NiRotData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_008c2490(NameArray* names) {
    FUN_00825b40(names);
    void* handle=FUN_00847b50(DAT_01092790);
    names->Append(handle);
    handle=FUN_00847d80(DAT_00e2d884,value);
    names->Append(handle);
}
}
}   // namespace f3m_008c2490

// @f3 0x008d0af0 (community match, verified in this file)
namespace task0737 {
struct MemoryAllocator {
    void* FUN_0086b930(unsigned int size);
};
extern MemoryAllocator DAT_01090a78;
struct NiGeomMorpherUpdateTask {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
};

NiGeomMorpherUpdateTask* __cdecl FUN_008d0910(unsigned int ItemUpdateArray) throw();

struct TaskBlock
{
    NiGeomMorpherUpdateTask* m_pkTasks;
    unsigned int m_uiCount;
    TaskBlock* m_pkNext;

    TaskBlock(unsigned int ItemUpdateArray) : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkTasks = FUN_008d0910(ItemUpdateArray);
        else
            m_pkTasks = 0;
    }
    NiGeomMorpherUpdateTask* GetAt(unsigned int i)
    {
        return i >= m_uiCount ? 0 : &m_pkTasks[i];
    }

    static void* operator new(unsigned int uiSize)
    {
        return DAT_01090a78.FUN_0086b930(uiSize);
    }
    static void operator delete(void*, int, int);
};

class NiStreamLinkIDSet
{
  public:
    NiGeomMorpherUpdateTask** m_ppkFree;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    TaskBlock* m_pkBlocks;

    void FUN_008cde60(unsigned int uiNewCapacity);

    void Add(NiGeomMorpherUpdateTask* pkTask)
    {
        if (m_uiSize == m_uiCapacity)
            FUN_008cde60(m_uiCapacity > 0 ? m_uiCapacity * 2 : 1);
        m_ppkFree[m_uiSize++] = pkTask;
    }

    void FUN_008d0af0(unsigned int ItemUpdateArray);
};

// @fnv 0x00a56e60
// pdb: NiTPool<NiGeomMorpherUpdateTask,NiTNewInterface<NiGeomMorpherUpdateTask> >::CreateNewObjects | NiGeomMorpherUpdateTask.obj | fnv360_0822_retail, call_dedup, low
// pdb params: uiSize
void NiStreamLinkIDSet::FUN_008d0af0(unsigned int uiTaskCount)
{
    TaskBlock* pkBlock = new TaskBlock(uiTaskCount);
    for (unsigned int i = 0; i < uiTaskCount; i++)
        Add(pkBlock->GetAt(i));
    pkBlock->m_pkNext = m_pkBlocks;
    m_pkBlocks = pkBlock;
}

}

// @f3 0x008c80d0 (community match, verified in this file)
extern unsigned char DAT_01091fa6[];
namespace f3m_008c80d0 {
struct O8c80d0 { char pad[0xa]; unsigned short w0a; char pad1[8]; int f14; char pad2[5]; unsigned char b1d; char pad3[6]; int f24; void FUN_008c80d0(int a, int b, int c); };
// pdb: NiTransformData::SetPosAnim | NiTransformData.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: pkKeys, uiNumKeys, eType
void O8c80d0::FUN_008c80d0(int a, int b, int c) { if (a && b) { w0a = b; f24 = a; f14 = c; b1d = DAT_01091fa6[c]; } else { w0a = 0; f24 = 0; f14 = 0; b1d = 0; } }
}   // namespace f3m_008c80d0

// @f3 0x008c8110 (community match, verified in this file)
extern unsigned char DAT_01091fa0[];
namespace f3m_008c8110 {
struct O8c8110 { char pad[0xc]; unsigned short w0c; char pad1[10]; int f18; char pad2[2]; unsigned char b1e; char pad3[9]; int f28; void FUN_008c8110(int a, int b, int c); };
// pdb: NiTransformData::SetScaleAnim | NiTransformData.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: pkKeys, uiNumKeys, eType
void O8c8110::FUN_008c8110(int a, int b, int c) { if (a && b) { w0c = b; f28 = a; f18 = c; b1e = DAT_01091fa0[c]; } else { w0c = 0; f28 = 0; b1e = 0; f18 = 0; } }
}   // namespace f3m_008c8110

// @f3 0x008c5450 (community match, verified in this file)
namespace f3m_008c5450 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class A42D00Stream
{
  public:
    void* FUN_0082a280();

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
    unsigned int m_uiFileVersion;
};

void* __cdecl FUN_0089eb90(unsigned int);
class FUN_008c3540
{
  public:
    FUN_008c3540(void* pkData) throw();

    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* pvMem);

    virtual void vfn00();
    virtual void DeleteThis() throw();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void Collapse();

    long m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class A42D00InterpPtr
{
  public:
    A42D00InterpPtr& operator=(FUN_008c3540* pObject) throw()
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    FUN_008c3540* operator->() const
    {
        return m_pObject;
    }

    FUN_008c3540* m_pObject;
};

class A42D00Controller
{
  public:
    void FUN_008d1310(A42D00Stream& kStream);
    void FUN_008c5450(A42D00Stream& kStream);

    void* m_ppVirtualMethodTable;
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
    A42D00InterpPtr m_spControllerInterpolator;
};

// Links the object base from the stream and, for older file versions, creates an interpolator from the stream data and collapses it.
// @fnv 0x00a42d00
// pdb: NiMaterialColorController::LinkObject | NiMaterialColorController.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void A42D00Controller::FUN_008c5450(A42D00Stream& kStream)
{
    FUN_008d1310(kStream);
    if (kStream.m_uiFileVersion < 0x0A010068)
    {
        void* pkData = kStream.FUN_0082a280();
        m_spControllerInterpolator = new FUN_008c3540(pkData);
        m_spControllerInterpolator->Collapse();
    }
}
}   // namespace f3m_008c5450

// @f3 0x008c9080 (community match, verified in this file)
namespace f3m_008c9080 {
struct Owner8c9080 {
    char pad[0x3c];
    Provider461* values;
    int index;
    void FUN_008c9080(Object8d11c0* object, unsigned short unused);
};
// pdb: NiFloatsExtraDataController::SynchronizePoseInterpolator | NiFloatsExtraDataController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkInterp, usIndex
void Owner8c9080::FUN_008c9080(Object8d11c0* object, unsigned short unused)
{
    Float8d11c0* interpolator = CastFloat8d11c0(object);
    interpolator->FUN_008b6690(values->FUN_00864650(index));
}
}   // namespace f3m_008c9080

// @f3 0x008db590 (community match, verified in this file)
namespace f3m_008db590 {
namespace task0812 {
void* __cdecl FUN_00c01530(void*, const void*, unsigned int);
// @fnv 0x005efe70
// pdb: BSSimpleArray<FootIK_DATA::FootIK_Leg_DATA,1024>::_MoveItems | BGSRagdoll.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_008db590(char* pDest, char* pSrc, unsigned int c)
{
    if (c <= 0)
        return;
    if (pDest < pSrc)
    {
        for (unsigned int i = 0; i < c; ++i)
            FUN_00c01530(pDest + i * 0x38, pSrc + i * 0x38, 0x38);
    }
    else if (pDest > pSrc)
    {
        for (int i = c - 1; i >= 0; --i)
            FUN_00c01530(pDest + i * 0x38, pSrc + i * 0x38, 0x38);
    }
}

}
}   // namespace f3m_008db590

// @f3 0x008dd050 (community match, verified in this file)
namespace f3m_008dd050 {
namespace Task0827 {
struct Array {
 virtual void slot00();
 virtual void** Allocate(unsigned int);
 virtual void Deallocate(void**);
 virtual void** Reallocate(void**,unsigned int);
 void** buffer;
 unsigned int size;
 unsigned int capacity;
 void FUN_008db590(void**,void**,unsigned int);
 void FUN_008dd050(unsigned int,unsigned int);
};
// pdb: BSSimpleArray<FootIK_DATA::FootIK_Leg_DATA,1024>::_ReallocateBuffer | BGSRagdoll.obj | fnv360_0822_retail, callee_sim, low
// pdb params: aiNewSize, aiCopyCount
void Array::FUN_008dd050(unsigned int newCapacity,unsigned int preserveCount) {
 if(buffer) {
  if(preserveCount==capacity) buffer=Reallocate(buffer,newCapacity);
  else {
   void** newBuffer=Allocate(newCapacity);
   FUN_008db590(newBuffer,buffer,preserveCount);
   Deallocate(buffer);
   buffer=0;
   buffer=newBuffer;
  }
 } else {
  buffer=Allocate(newCapacity);
  capacity=newCapacity;
 }
}
}
}   // namespace f3m_008dd050

// @f3 0x008d7ab0 (community match, verified in this file)
extern void* DAT_00f794b0;
namespace f3m_008d7ab0 {
namespace task0829 {
struct S_c6a200_Info
{
    int unk00, unk04, unk08, unk0c;
};
struct S_c6a200_Ev
{
    int unk00;
    unsigned char unk04;
    int unk08;
    int unk0c;
    int unk10, unk14, unk18;
};
S_c6a200_Info* __cdecl FUN_00aa60f0(void* obj);
void __cdecl FUN_008d5790(void* obj, S_c6a200_Ev* ev, void* extra);
// @fnv 0x00c6a200
// pdb: bhkWorld::Activate | bhkWorld.obj | fnv360_0822_debug, caller, medium
// pdb params: apObject, abActivate, abRecurse, abForce
bool __cdecl FUN_008d7ab0(void* obj, unsigned char a1, unsigned char a2, unsigned char a3)
{
    bool r = false;
    if (obj)
    {
        S_c6a200_Info* info;
        if (a3 || ((info = FUN_00aa60f0(obj)) ? (info->unk0c & 2) : 0))
        {
            S_c6a200_Ev ev;
            ev.unk04 = a2;
            r = true;
            ev.unk00 = 0;
            ev.unk08 = 0x0c;
            ev.unk0c = a1;
            if (DAT_00f794b0)
                FUN_008d5790(obj, &ev, DAT_00f794b0);
        }
    }
    return r;
}

}
}   // namespace f3m_008d7ab0

// @f3 0x008c7590 (community match, verified in this file)
extern int DAT_00e2f958;
extern int DAT_00e2f938;
extern int DAT_00e2f918;
namespace f3m_008c7590 {
namespace task0838 {

void __cdecl FUN_0089e890(void* p);
void __fastcall FUN_006bd950(void* self);

struct FUN_00a2e460_node
{
    FUN_00a2e460_node* m_pkNext;
    void* m_pvVal;
};

struct FUN_00a2e460_cls
{
    int* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    FUN_00a2e460_node** m_ppkHashTable;
    unsigned int unk0c;
    unsigned char m_bOwnsNodes;
    void FUN_008c7590();
};

// Frees each stored value in the hash table when nodes are owned, then releases the table and resets the vtable pointers.
// @fnv 0x00a2e460
// pdb: NiTStringTemplateMap<NiTPointerMap<char const *,NiPointer<NiShaderLibrary> >,NiPointer<NiShaderLibrary> >::~NiTStringTemplateMap<NiTPointerMap<char const *,NiPointer<NiShaderLibrary> >,NiPointer<NiShaderLibrary> > | NiD3DShaderFactory.obj | fnv360_0822_retail, objrun_prop, high
void FUN_00a2e460_cls::FUN_008c7590()
{
    m_ppVirtualMethodTable = &DAT_00e2f958;
    if (m_bOwnsNodes != 0)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            FUN_00a2e460_node* node = m_ppkHashTable[i];
            while (node != 0)
            {
                FUN_00a2e460_node* cur = node;
                void* val = cur->m_pvVal;
                node = cur->m_pkNext;
                FUN_0089e890(val);
            }
        }
    }
    m_ppVirtualMethodTable = &DAT_00e2f938;
    FUN_006bd950(this);
    m_ppVirtualMethodTable = &DAT_00e2f918;
    FUN_006bd950(this);
    FUN_0089e890(m_ppkHashTable);
}

}
}   // namespace f3m_008c7590

// @f3 0x008d7b20 (community match, verified in this file)
extern void* DAT_00f79490;
namespace f3m_008d7b20 {
namespace task0854 {
struct S_00c69f50_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

S_00c69f50_Obj* FUN_00aa60f0(S_00c69f50_Obj* obj);
void FUN_008d5790(S_00c69f50_Obj* obj, int* ctx, void* g);

// @fnv 0x00c69f50
// pdb: bhkWorld::KillHavok | bhkWorld.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_gap_sim) + skyrim(objrun), high
bool bhkWorld_KillHavok(S_00c69f50_Obj* obj, unsigned char ucValue, unsigned char ucForce)
{
    bool result = false;
    if (obj)
    {
        S_00c69f50_Obj* info;
        if (ucForce || ((info = FUN_00aa60f0(obj)) ? (info->unk0c & 2) : 0))
        {
            int ctx[7];
            result = true;
            *(unsigned char*)&ctx[1] = ucValue;
            void* g = DAT_00f79490;
            ctx[0] = 0;
            ctx[2] = 4;
            if (g)
            {
                FUN_008d5790(obj, &ctx[0], g);
            }
        }
    }
    return result;
}

}
}   // namespace f3m_008d7b20

// @f3 0x008d4c10 (community match, verified in this file)
namespace f3m_008d4c10 {
namespace n8d4c10 {
void* __cdecl FUN_00c00610(void* dst, int val, unsigned int size);
struct RefObj {
    virtual void Delete(int flags);
    unsigned short memSize;
    short refCount;
    int m8;
    void RemoveReference() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) Delete(1);
        }
    }
};
struct Target { void hkpWorld_removeConstraint(char* out, RefObj* obj); };
}
struct FUN_008d4c10_t {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual n8d4c10::Target* GetTarget();
    char pad[0x4c - 4];
    n8d4c10::RefObj** m_items;
    unsigned int m_count;
    void FUN_008d4c10();
};
// pdb: PIXBeginNamedEvent_Copy_VarArgs | pix.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: bhkWorld::AddBatchedEntitiesPartial)
// pdb params: Color, pFormat
void FUN_008d4c10_t::FUN_008d4c10() {
    if (!m_count) return;
    if (m_count >= 200) m_count = 200;
    n8d4c10::Target* t = GetTarget();
    if (!t) return;
    for (unsigned int i = 0; i < m_count; ++i) {
        if (m_items[i] && m_items[i]->m8) {
            char out;
            t->hkpWorld_removeConstraint(&out, m_items[i]);
        }
        if (m_items[i]) m_items[i]->RemoveReference();
    }
    n8d4c10::FUN_00c00610(m_items, 0, m_count * sizeof(n8d4c10::RefObj*));
    m_count = 0;
}
}   // namespace f3m_008d4c10

// @f3 0x008d3640 (community match, verified in this file)
namespace f3m_008d3640 {
namespace Task0884 {
struct FUN_0092e800 {int unk00; ~FUN_0092e800();};
struct FUN_0086caa0 {~FUN_0086caa0();};
struct FUN_008d3640: FUN_0092e800 {
 int unk004;
 int unk008;
 int unk00c;
 int unk010;
 int unk014;
 int unk018;
 int unk01c;
 int unk020;
 int unk024;
 int unk028;
 int unk02c;
 int unk030;
 int unk034;
 int unk038;
 int unk03c;
 int unk040;
 int unk044;
 int unk048;
 int unk04c;
 int unk050;
 int unk054;
 int unk058;
 int unk05c;
 int unk060;
 int unk064;
 int unk068;
 int unk06c;
 int unk070;
 int unk074;
 int unk078;
 int unk07c;
 int unk080;
 int unk084;
 int unk088;
 int unk08c;
 int unk090;
 int unk094;
 int unk098;
 int unk09c;
 int unk0a0;
 int unk0a4;
 int unk0a8;
 int unk0ac;
 int unk0b0;
 int unk0b4;
 int unk0b8;
 int unk0bc;
 int unk0c0;
 int unk0c4;
 int unk0c8;
 int unk0cc;
 int unk0d0;
 int unk0d4;
 int unk0d8;
 int unk0dc;
 int unk0e0;
 int unk0e4;
 int unk0e8;
 int unk0ec;
 int unk0f0;
 int unk0f4;
 int unk0f8;
 int unk0fc;
 int unk100;
 int unk104;
 int unk108;
 int unk10c;
 int unk110;
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
 int unk194;
 int unk198;
 int unk19c;
 int unk1a0;
 int unk1a4;
 int unk1a8;
 int unk1ac;
 int unk1b0;
 int unk1b4;
 int unk1b8;
 int unk1bc;
 int unk1c0;
 int unk1c4;
 int unk1c8;
 int unk1cc;
 int unk1d0;
 int unk1d4;
 int unk1d8;
 int unk1dc;
 int unk1e0;
 int unk1e4;
 int unk1e8;
 int unk1ec;
 int unk1f0;
 int unk1f4;
 int unk1f8;
 int unk1fc;
 int unk200;
 int unk204;
 int unk208;
 int unk20c;
 int unk210;
 int unk214;
 int unk218;
 int unk21c;
 int unk220;
 int unk224;
 int unk228;
 int unk22c;
 int unk230;
 int unk234;
 int unk238;
 int unk23c;
 int unk240;
 int unk244;
 int unk248;
 int unk24c;
 int unk250;
 int unk254;
 int unk258;
 int unk25c;
 int unk260;
 int unk264;
 int unk268;
 int unk26c;
 int unk270;
 int unk274;
 int unk278;
 int unk27c;
 int unk280;
 int unk284;
 int unk288;
 int unk28c;
 int unk290;
 int unk294;
 int unk298;
 int unk29c;
 int unk2a0;
 int unk2a4;
 int unk2a8;
 int unk2ac;
 int unk2b0;
 int unk2b4;
 int unk2b8;
 int unk2bc;
 int unk2c0;
 int unk2c4;
 int unk2c8;
 int unk2cc;
 int unk2d0;
 int unk2d4;
 int unk2d8;
 int unk2dc;
 int unk2e0;
 int unk2e4;
 int unk2e8;
 int unk2ec;
 int unk2f0;
 int unk2f4;
 int unk2f8;
 int unk2fc;
 int unk300;
 int unk304;
 int unk308;
 int unk30c;
 int unk310;
 int unk314;
 int unk318;
 int unk31c;
 int unk320;
 int unk324;
 int unk328;
 int unk32c;
 int unk330;
 int unk334;
 int unk338;
 int unk33c;
 int unk340;
 int unk344;
 int unk348;
 int unk34c;
 int unk350;
 int unk354;
 int unk358;
 int unk35c;
 int unk360;
 int unk364;
 int unk368;
 int unk36c;
 int unk370;
 int unk374;
 int unk378;
 int unk37c;
 int unk380;
 int unk384;
 int unk388;
 int unk38c;
 int unk390;
 int unk394;
 int unk398;
 int unk39c;
 int unk3a0;
 int unk3a4;
 int unk3a8;
 int unk3ac;
 int unk3b0;
 int unk3b4;
 int unk3b8;
 int unk3bc;
 int unk3c0;
 int unk3c4;
 int unk3c8;
 int unk3cc;
 int unk3d0;
 int unk3d4;
 int unk3d8;
 int unk3dc;
 int unk3e0;
 int unk3e4;
 int unk3e8;
 int unk3ec;
 int unk3f0;
 int unk3f4;
 int unk3f8;
 int unk3fc;
 int unk400;
 int unk404;
 int unk408;
 int unk40c;
 int unk410;
 int unk414;
 int unk418;
 int unk41c;
 int unk420;
 int unk424;
 int unk428;
 int unk42c;
 int unk430;
 int unk434;
 int unk438;
 int unk43c;
 int unk440;
 int unk444;
 int unk448;
 int unk44c;
 int unk450;
 int unk454;
 int unk458;
 int unk45c;
 int unk460;
 int unk464;
 int unk468;
 int unk46c;
 int unk470;
 int unk474;
 int unk478;
 int unk47c;
 int unk480;
 int unk484;
 int unk488;
 int unk48c;
 int unk490;
 int unk494;
 int unk498;
 int unk49c;
 int unk4a0;
 int unk4a4;
 int unk4a8;
 int unk4ac;
 int unk4b0;
 int unk4b4;
 int unk4b8;
 int unk4bc;
 int unk4c0;
 int unk4c4;
 int unk4c8;
 int unk4cc;
 int unk4d0;
 int unk4d4;
 int unk4d8;
 int unk4dc;
 int unk4e0;
 int unk4e4;
 int unk4e8;
 int unk4ec;
 int unk4f0;
 int unk4f4;
 int unk4f8;
 int unk4fc;
 int unk500;
 int unk504;
 int unk508;
 int unk50c;
 int unk510;
 int unk514;
 int unk518;
 int unk51c;
 int unk520;
 int unk524;
 int unk528;
 int unk52c;
 int unk530;
 int unk534;
 int unk538;
 int unk53c;
 int unk540;
 int unk544;
 int unk548;
 int unk54c;
 int unk550;
 int unk554;
 int unk558;
 int unk55c;
 int unk560;
 int unk564;
 int unk568;
 int unk56c;
 int unk570;
 int unk574;
 int unk578;
 int unk57c;
 int unk580;
 int unk584;
 int unk588;
 int unk58c;
 int unk590;
 int unk594;
 int unk598;
 int unk59c;
 int unk5a0;
 int unk5a4;
 int unk5a8;
 int unk5ac;
 int unk5b0;
 int unk5b4;
 int unk5b8;
 int unk5bc;
 int unk5c0;
 int unk5c4;
 int unk5c8;
 int unk5cc;
 int unk5d0;
 int unk5d4;
 int unk5d8;
 int unk5dc;
 int unk5e0;
 int unk5e4;
 int unk5e8;
 int unk5ec;
 int unk5f0;
 int unk5f4;
 int unk5f8;
 int unk5fc;
 int unk600;
 int unk604;
 int unk608;
 int unk60c;
 int unk610;
 int unk614;
 int unk618;
 int unk61c;
 int unk620;
 int unk624;
 int unk628;
 int unk62c;
 int unk630;
 int unk634;
 int unk638;
 int unk63c;
 int unk640;
 int unk644;
 int unk648;
 int unk64c;
 int unk650;
 int unk654;
 int unk658;
 int unk65c;
 int unk660;
 int unk664;
 int unk668;
 int unk66c;
 int unk670;
 int unk674;
 int unk678;
 int unk67c;
 int unk680;
 int unk684;
 int unk688;
 int unk68c;
 int unk690;
 int unk694;
 int unk698;
 int unk69c;
 int unk6a0;
 int unk6a4;
 int unk6a8;
 int unk6ac;
 int unk6b0;
 int unk6b4;
 int unk6b8;
 int unk6bc;
 int unk6c0;
 int unk6c4;
 int unk6c8;
 int unk6cc;
 int unk6d0;
 int unk6d4;
 int unk6d8;
 int unk6dc;
 int unk6e0;
 int unk6e4;
 int unk6e8;
 int unk6ec;
 int unk6f0;
 int unk6f4;
 int unk6f8;
 int unk6fc;
 int unk700;
 int unk704;
 int unk708;
 int unk70c;
 int unk710;
 int unk714;
 int unk718;
 int unk71c;
 int unk720;
 int unk724;
 int unk728;
 int unk72c;
 int unk730;
 int unk734;
 int unk738;
 int unk73c;
 int unk740;
 int unk744;
 int unk748;
 int unk74c;
 int unk750;
 int unk754;
 int unk758;
 int unk75c;
 int unk760;
 int unk764;
 int unk768;
 int unk76c;
 int unk770;
 int unk774;
 int unk778;
 int unk77c;
 int unk780;
 int unk784;
 int unk788;
 int unk78c;
 int unk790;
 int unk794;
 int unk798;
 int unk79c;
 int unk7a0;
 int unk7a4;
 int unk7a8;
 int unk7ac;
 int unk7b0;
 int unk7b4;
 int unk7b8;
 int unk7bc;
 int unk7c0;
 int unk7c4;
 int unk7c8;
 int unk7cc;
 int unk7d0;
 int unk7d4;
 int unk7d8;
 int unk7dc;
 int unk7e0;
 int unk7e4;
 int unk7e8;
 int unk7ec;
 int unk7f0;
 int unk7f4;
 int unk7f8;
 int unk7fc;
 int unk800;
 int unk804;
 int unk808;
 int unk80c;
 int unk810;
 int unk814;
 int unk818;
 int unk81c;
 int unk820;
 int unk824;
 int unk828;
 int unk82c;
 int unk830;
 int unk834;
 int unk838;
 int unk83c;
 int unk840;
 int unk844;
 int unk848;
 int unk84c;
 int unk850;
 int unk854;
 int unk858;
 int unk85c;
 int unk860;
 int unk864;
 int unk868;
 int unk86c;
 int unk870;
 int unk874;
 int unk878;
 int unk87c;
 int unk880;
 int unk884;
 int unk888;
 int unk88c;
 int unk890;
 int unk894;
 int unk898;
 int unk89c;
 int unk8a0;
 int unk8a4;
 int unk8a8;
 int unk8ac;
 int unk8b0;
 int unk8b4;
 int unk8b8;
 int unk8bc;
 int unk8c0;
 int unk8c4;
 int unk8c8;
 int unk8cc;
 int unk8d0;
 int unk8d4;
 int unk8d8;
 int unk8dc;
 int unk8e0;
 int unk8e4;
 int unk8e8;
 int unk8ec;
 int unk8f0;
 int unk8f4;
 int unk8f8;
 int unk8fc;
 int unk900;
 int unk904;
 int unk908;
 int unk90c;
 int unk910;
 int unk914;
 int unk918;
 int unk91c;
 int unk920;
 int unk924;
 int unk928;
 int unk92c;
 int unk930;
 int unk934;
 int unk938;
 int unk93c;
 int unk940;
 int unk944;
 int unk948;
 int unk94c;
 int unk950;
 int unk954;
 int unk958;
 int unk95c;
 int unk960;
 int unk964;
 int unk968;
 int unk96c;
 int unk970;
 int unk974;
 int unk978;
 int unk97c;
 int unk980;
 int unk984;
 int unk988;
 int unk98c;
 int unk990;
 int unk994;
 int unk998;
 int unk99c;
 int unk9a0;
 int unk9a4;
 int unk9a8;
 int unk9ac;
 int unk9b0;
 int unk9b4;
 int unk9b8;
 int unk9bc;
 int unk9c0;
 int unk9c4;
 int unk9c8;
 int unk9cc;
 int unk9d0;
 int unk9d4;
 int unk9d8;
 int unk9dc;
 int unk9e0;
 int unk9e4;
 int unk9e8;
 int unk9ec;
 int unk9f0;
 int unk9f4;
 int unk9f8;
 int unk9fc;
 int unka00;
 int unka04;
 int unka08;
 int unka0c;
 int unka10;
 int unka14;
 FUN_0086caa0 member;
 ~FUN_008d3640();
};
FUN_008d3640::~FUN_008d3640(){}
}
}   // namespace f3m_008d3640

// @f3 0x008d3a60 (community match, verified in this file)
namespace n8d3a60 {
extern char DAT_00f79458;
extern const float FUN_00dcd8a0;
extern const float FUN_00de6e60;
struct Base {
    virtual ~Base();
    Base();
    char pad[0x10 - 4];
};
}
struct bhkWorldCinfo : n8d3a60::Base { // src: F3_EXE vtable 0x00e32184 (old: FUN_008d3a60)
    volatile float m10; float m14, m18, m1c;
    int m20;
    float m24;
    char m28;
    char pad29[0x50 - 0x29];
    float m50;
    char pad54[0xa7 - 0x54];
    char ma7;
    char padA8[0xbd - 0xa8];
    char mbd;
    bhkWorldCinfo();
    virtual ~bhkWorldCinfo();
};
// pdb: bhkWorldCinfo::bhkWorldCinfo | bhkWorld.obj | fnv360_0822_retail, call_gap, low
bhkWorldCinfo::bhkWorldCinfo()
{
    m10 = 0.0f;
    m14 = n8d3a60::FUN_00dcd8a0;
    m18 = 0.0f;
    m1c = 0.0f;
    m50 = 0.1f;
    m24 = n8d3a60::FUN_00de6e60;
    mbd = n8d3a60::DAT_00f79458;
    ma7 = 0;
    m28 = 3;
}

// @f3 0x008d3500 (community match, verified in this file)
extern int DAT_00e3206c;
namespace f3m_008d3500 {
namespace task0887 {
struct FUN_0092e8a0 { virtual void slot00();
int field004;
int field008;
int field00c;
int field010;
int field014;
int field018;
int field01c;
int field020;
int field024;
int field028;
int field02c;
int field030;
int field034;
int field038;
int field03c;
int field040;
int field044;
int field048;
int field04c;
int field050;
int field054;
int field058;
int field05c;
int field060;
int field064;
int field068;
int field06c;
int field070;
int field074;
int field078;
int field07c;
int field080;
int field084;
int field088;
int field08c;
int field090;
int field094;
int field098;
int field09c;
int field0a0;
int field0a4;
int field0a8;
int field0ac;
int field0b0;
int field0b4;
int field0b8;
int field0bc;
int field0c0;
int field0c4;
int field0c8;
int field0cc;
int field0d0;
int field0d4;
int field0d8;
int field0dc;
int field0e0;
int field0e4;
int field0e8;
int field0ec;
int field0f0;
int field0f4;
int field0f8;
int field0fc;
int field100;
int field104;
int field108;
int field10c;
int field110;
int field114;
int field118;
int field11c;
int field120;
int field124;
int field128;
int field12c;
int field130;
int field134;
int field138;
int field13c;
int field140;
int field144;
int field148;
int field14c;
int field150;
int field154;
int field158;
int field15c;
int field160;
int field164;
int field168;
int field16c;
int field170;
int field174;
int field178;
int field17c;
int field180;
int field184;
int field188;
int field18c;
int field190;
int field194;
int field198;
int field19c;
int field1a0;
int field1a4;
int field1a8;
int field1ac;
int field1b0;
int field1b4;
int field1b8;
int field1bc;
int field1c0;
int field1c4;
int field1c8;
int field1cc;
int field1d0;
int field1d4;
int field1d8;
int field1dc;
int field1e0;
int field1e4;
int field1e8;
int field1ec;
int field1f0;
int field1f4;
int field1f8;
int field1fc;
int field200;
int field204;
int field208;
int field20c;
int field210;
int field214;
int field218;
int field21c;
int field220;
int field224;
int field228;
int field22c;
int field230;
int field234;
int field238;
int field23c;
int field240;
int field244;
int field248;
int field24c;
int field250;
int field254;
int field258;
int field25c;
int field260;
int field264;
int field268;
int field26c;
int field270;
int field274;
int field278;
int field27c;
int field280;
int field284;
int field288;
int field28c;
int field290;
int field294;
int field298;
int field29c;
int field2a0;
int field2a4;
int field2a8;
int field2ac;
int field2b0;
int field2b4;
int field2b8;
int field2bc;
int field2c0;
int field2c4;
int field2c8;
int field2cc;
int field2d0;
int field2d4;
int field2d8;
int field2dc;
int field2e0;
int field2e4;
int field2e8;
int field2ec;
int field2f0;
int field2f4;
int field2f8;
int field2fc;
int field300;
int field304;
int field308;
int field30c;
int field310;
int field314;
int field318;
int field31c;
int field320;
int field324;
int field328;
int field32c;
int field330;
int field334;
int field338;
int field33c;
int field340;
int field344;
int field348;
int field34c;
int field350;
int field354;
int field358;
int field35c;
int field360;
int field364;
int field368;
int field36c;
int field370;
int field374;
int field378;
int field37c;
int field380;
int field384;
int field388;
int field38c;
int field390;
int field394;
int field398;
int field39c;
int field3a0;
int field3a4;
int field3a8;
int field3ac;
int field3b0;
int field3b4;
int field3b8;
int field3bc;
int field3c0;
int field3c4;
int field3c8;
int field3cc;
int field3d0;
int field3d4;
int field3d8;
int field3dc;
int field3e0;
int field3e4;
int field3e8;
int field3ec;
int field3f0;
int field3f4;
int field3f8;
int field3fc;
int field400;
int field404;
int field408;
int field40c;
int field410;
int field414;
int field418;
int field41c;
int field420;
int field424;
int field428;
int field42c;
int field430;
int field434;
int field438;
int field43c;
int field440;
int field444;
int field448;
int field44c;
int field450;
int field454;
int field458;
int field45c;
int field460;
int field464;
int field468;
int field46c;
int field470;
int field474;
int field478;
int field47c;
int field480;
int field484;
int field488;
int field48c;
int field490;
int field494;
int field498;
int field49c;
int field4a0;
int field4a4;
int field4a8;
int field4ac;
int field4b0;
int field4b4;
int field4b8;
int field4bc;
int field4c0;
int field4c4;
int field4c8;
int field4cc;
int field4d0;
int field4d4;
int field4d8;
int field4dc;
int field4e0;
int field4e4;
int field4e8;
int field4ec;
int field4f0;
int field4f4;
int field4f8;
int field4fc;
int field500;
int field504;
int field508;
int field50c;
int field510;
int field514;
int field518;
int field51c;
int field520;
int field524;
int field528;
int field52c;
int field530;
int field534;
int field538;
int field53c;
int field540;
int field544;
int field548;
int field54c;
int field550;
int field554;
int field558;
int field55c;
int field560;
int field564;
int field568;
int field56c;
int field570;
int field574;
int field578;
int field57c;
int field580;
int field584;
int field588;
int field58c;
int field590;
int field594;
int field598;
int field59c;
int field5a0;
int field5a4;
int field5a8;
int field5ac;
int field5b0;
int field5b4;
int field5b8;
int field5bc;
int field5c0;
int field5c4;
int field5c8;
int field5cc;
int field5d0;
int field5d4;
int field5d8;
int field5dc;
int field5e0;
int field5e4;
int field5e8;
int field5ec;
int field5f0;
int field5f4;
int field5f8;
int field5fc;
int field600;
int field604;
int field608;
int field60c;
int field610;
int field614;
int field618;
int field61c;
int field620;
int field624;
int field628;
int field62c;
int field630;
int field634;
int field638;
int field63c;
int field640;
int field644;
int field648;
int field64c;
int field650;
int field654;
int field658;
int field65c;
int field660;
int field664;
int field668;
int field66c;
int field670;
int field674;
int field678;
int field67c;
int field680;
int field684;
int field688;
int field68c;
int field690;
int field694;
int field698;
int field69c;
int field6a0;
int field6a4;
int field6a8;
int field6ac;
int field6b0;
int field6b4;
int field6b8;
int field6bc;
int field6c0;
int field6c4;
int field6c8;
int field6cc;
int field6d0;
int field6d4;
int field6d8;
int field6dc;
int field6e0;
int field6e4;
int field6e8;
int field6ec;
int field6f0;
int field6f4;
int field6f8;
int field6fc;
int field700;
int field704;
int field708;
int field70c;
int field710;
int field714;
int field718;
int field71c;
int field720;
int field724;
int field728;
int field72c;
int field730;
int field734;
int field738;
int field73c;
int field740;
int field744;
int field748;
int field74c;
int field750;
int field754;
int field758;
int field75c;
int field760;
int field764;
int field768;
int field76c;
int field770;
int field774;
int field778;
int field77c;
int field780;
int field784;
int field788;
int field78c;
int field790;
int field794;
int field798;
int field79c;
int field7a0;
int field7a4;
int field7a8;
int field7ac;
int field7b0;
int field7b4;
int field7b8;
int field7bc;
int field7c0;
int field7c4;
int field7c8;
int field7cc;
int field7d0;
int field7d4;
int field7d8;
int field7dc;
int field7e0;
int field7e4;
int field7e8;
int field7ec;
int field7f0;
int field7f4;
int field7f8;
int field7fc;
int field800;
int field804;
int field808;
int field80c;
int field810;
int field814;
int field818;
int field81c;
int field820;
int field824;
int field828;
int field82c;
int field830;
int field834;
int field838;
int field83c;
int field840;
int field844;
int field848;
int field84c;
int field850;
int field854;
int field858;
int field85c;
int field860;
int field864;
int field868;
int field86c;
int field870;
int field874;
int field878;
int field87c;
int field880;
int field884;
int field888;
int field88c;
int field890;
int field894;
int field898;
int field89c;
int field8a0;
int field8a4;
int field8a8;
int field8ac;
int field8b0;
int field8b4;
int field8b8;
int field8bc;
int field8c0;
int field8c4;
int field8c8;
int field8cc;
int field8d0;
int field8d4;
int field8d8;
int field8dc;
int field8e0;
int field8e4;
int field8e8;
int field8ec;
int field8f0;
int field8f4;
int field8f8;
int field8fc;
int field900;
int field904;
int field908;
int field90c;
int field910;
int field914;
int field918;
int field91c;
int field920;
int field924;
int field928;
int field92c;
int field930;
int field934;
int field938;
int field93c;
int field940;
int field944;
int field948;
int field94c;
int field950;
int field954;
int field958;
int field95c;
int field960;
int field964;
int field968;
int field96c;
int field970;
int field974;
int field978;
int field97c;
int field980;
int field984;
int field988;
int field98c;
int field990;
int field994;
int field998;
int field99c;
int field9a0;
int field9a4;
int field9a8;
int field9ac;
int field9b0;
int field9b4;
int field9b8;
int field9bc;
int field9c0;
int field9c4;
int field9c8;
int field9cc;
int field9d0;
int field9d4;
int field9d8;
int field9dc;
int field9e0;
int field9e4;
int field9e8;
int field9ec;
int field9f0;
int field9f4;
int field9f8;
int field9fc;
int fielda00;
int fielda04;
int fielda08;
int fielda0c;
int fielda10;
int fielda14;
FUN_0092e8a0(); void FUN_0092e800(); ~FUN_0092e8a0(){FUN_0092e800();}
};
struct FUN_0086cb70 { FUN_0086cb70(); };
struct FUN_008d3500 : FUN_0092e8a0 { FUN_0086cb70 member; FUN_008d3500(); };
// pdb: hkBool::operator== | bhkWorld.obj | tesv_win, call_gap_sim, low
FUN_008d3500::FUN_008d3500() {}
}
}   // namespace f3m_008d3500

// @f3 0x008db530 (community match, verified in this file)
namespace f3m_008db530 {
namespace Task0899 {
struct Item {Item* next;const char* key;unsigned short value;};
struct Map {
 virtual void slot00();
 virtual unsigned int Hash(const char*) const;
 virtual bool Equal(const char*,const char*) const;
 unsigned int hashSize;Item** table;unsigned int count;
 bool FUN_008db530(const char*,unsigned short&) const;
};
// pdb: NiTMapBase<DFALL<NiTMapItem<bhkRigidBody *,unsigned short> >,bhkRigidBody *,unsigned short>::GetAt | LoadedAreaBound.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: key, val
bool Map::FUN_008db530(const char* key,unsigned short& value) const {
 unsigned int index=Hash(key);
 Item* item=table[index];
 while(item){
  if(Equal(key,item->key)){value=item->value;return true;}
  item=item->next;
 }
 return false;
}
}
}   // namespace f3m_008db530

// @f3 0x008d34a0 (community match, verified in this file)
namespace f3m_008d34a0 {
struct hkBaseObject {
    virtual ~hkBaseObject() throw() {}
    unsigned short sizeFlags;
    short references;
};
struct hkListenerACBFB {
    virtual ~hkListenerACBFB() throw() {}
    virtual void Filter();
};
struct hkListenerBCBFB {
    virtual ~hkListenerBCBFB() throw() {}
    virtual void Filter();
};
struct hkListenerCCBFB {
    virtual ~hkListenerCCBFB() throw() {}
    virtual void Filter();
};
struct hkListenerDCBFB {
    virtual ~hkListenerDCBFB() throw() {}
    virtual void Filter();
};
struct FUN_008d34a0 : hkBaseObject, hkListenerACBFB, hkListenerBCBFB, hkListenerCCBFB, hkListenerDCBFB {
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
};
struct Owner0896 : FUN_008d34a0 {
    virtual ~Owner0896() throw();
};
Owner0896::~Owner0896() throw() {}
}   // namespace f3m_008d34a0

// @f3 0x008c5690 (community match, verified in this file)
extern int DAT_00e2f47c;
namespace f3m_008c5690 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Counted {virtual void v00(); virtual void Release(); int refCount;};
void __cdecl FUN_0089ec10(void*,unsigned);
struct Owner {
 int m_vptr;
 int field04;
 int field08;
 int field0c;
 int field10;
 int field14;
 int field18;
 int field1c;
 int field20;
 int field24;
 int field28;
 int field2c;
 int field30;
 Counted* m_pCounted;
 int field38;
 void FUN_00837e80();
 Owner* FUN_008c5690(unsigned char);
};
// pdb: NiMaterialColorController::`scalar deleting destructor' | NiMaterialColorController.obj | fnv360_0721_retail, objrun, medium
Owner* Owner::FUN_008c5690(unsigned char acFlags)
{
    *(volatile int*)&m_vptr = (int)&DAT_00e2f47c;
    Counted* pCounted = *(Counted* volatile*)&m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    FUN_00837e80();
    if (acFlags & 1)
    {
        FUN_0089ec10(this, 0x3c);
    }
    return this;
}
}   // namespace f3m_008c5690

// @f3 0x008dd120 (community match, verified in this file)
namespace Task0949 {
extern int DAT_00e32b88;
extern void (__stdcall *DAT_00e32b90)(void*);
struct Manager {void FUN_0086ba60(void*);};
extern Manager DAT_01090a78;
struct Array {
 void* vtable;void* data;int size,capacity;
 ~Array(){
  vtable=&DAT_00e32b88;
  if(data){DAT_00e32b90(data);data=0;capacity=0;size=0;}
 }
};
// pdb: BSSimpleArray<NiAVObject *,1024>::`scalar deleting destructor' | CaravanMenu.obj | fnv360_0822_retail, vtable, medium
Array* __fastcall FUN_008dd120(Array* array,int,unsigned int flags) {
 array->Array::~Array();
 if(flags&1) DAT_01090a78.FUN_0086ba60(array);
 return array;
}
}

// @f3 0x008d5730 (community match, verified in this file)
namespace f3m_008d5730 {
namespace n8d5730 {
struct Body { char pad[0x10]; int m10; };
struct Entity { char pad[8]; Body* body; };
struct Pair { int* a; int b; };
struct PairArray;
void __cdecl FUN_00901f10(PairArray* a, int elemSize);
struct PairArray {
    Pair* data; int size; int capAndFlags;
    void pushBack(const Pair& p) {
        if (size == (capAndFlags & 0x3fffffff))
            FUN_00901f10(this, 8);
        data[size++] = p;
    }
};
}
struct FUN_008d5730_c {
    char pad[0x7c];
    n8d5730::PairArray pairs;
    void FUN_008d5730(n8d5730::Entity* e, int b);
};
// pdb: bhkWorld::SetDebugObjectColor | bhkWorld.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apObject, aiColor
void FUN_008d5730_c::FUN_008d5730(n8d5730::Entity* e, int b)
{
    n8d5730::Pair p;
    p.b = b;
    p.a = (e && e->body) ? &e->body->m10 : 0;
    pairs.pushBack(p);
}
}   // namespace f3m_008d5730

// @f3 0x008d59c0 (community match, verified in this file)
namespace f3m_008d59c0 {
struct BhkPhysBody
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;




    float m_f84;
};

// Result handed back by the slot call; m_pPhysicsBody points at the physics body.
struct BhkPhysResult
{
    int unk00;
    int unk04;
    BhkPhysBody* m_pPhysicsBody;
};

struct BhkPhysObject;

// Slot 16 of the object's slot table: takes the object, returns the holder.
typedef BhkPhysResult*(__fastcall* BhkPhysGetResult)(BhkPhysObject* pSelf);

struct BhkPhysSlotTable
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
    BhkPhysGetResult m_fnGetResult;
};

struct BhkPhysObject
{
    BhkPhysSlotTable* m_pSlots;
};

// World record: the physics object it refers to sits at offset 0x10.
struct BhkPhysRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BhkPhysObject* m_pObject;
};

// Parameter record: the float to copy sits at offset 0xc.
struct BhkPhysParam
{
    int unk00;
    int unk04;
    int unk08;
    float m_f0c;
};

// Gets the physics result from the record's object and writes pParam->m_f0c into the body's m_f84, returning early if the object or result is null.
// @fnv 0x00c67150
// pdb: bhkWorld::DebugDisplayObject | bhkWorld.obj | fnv360_0822_debug, objrun_sim, low, conflict (skyrim: bhkWorld::DoSetRestitution)
// pdb params: apCollision, arData
void FUN_008d59c0(BhkPhysRecord* pRecord, BhkPhysParam* pParam)
{
    BhkPhysObject* pObject = pRecord->m_pObject;
    if (pObject == 0)
        return;

    BhkPhysGetResult fnGetResult = pObject->m_pSlots->m_fnGetResult;
    BhkPhysResult* pResult = fnGetResult(pObject);
    if (pResult == 0)
        return;

    pResult->m_pPhysicsBody->m_f84 = pParam->m_f0c;
}
}   // namespace f3m_008d59c0

// @f3 0x008d2fd0 (community match, verified in this file)
namespace f3m_008d2fd0 {
namespace n8d2fd0 {
struct Variant;
void __cdecl FUN_0093e480(Variant& oldObj, const char* oldName, Variant& newObj, const char* newName);
struct Accessor {
    void* member; void* object;
    Accessor(Variant& v, const char* name);
    float& FUN_0093d6a0(int index);
};
}
void __cdecl FUN_008d2fd0(n8d2fd0::Variant& oldObj, n8d2fd0::Variant& newObj)
{
    n8d2fd0::FUN_0093e480(oldObj, "targetGain", newObj, "newTargetGain");
    n8d2fd0::FUN_0093e480(oldObj, "lookAtGain", newObj, "onOffGain");
    {
        n8d2fd0::Accessor oldLimit(oldObj, "lookAtLimit");
        n8d2fd0::Accessor newLimit(newObj, "limitAngleDegrees");
        newLimit.FUN_0093d6a0(0) = oldLimit.FUN_0093d6a0(0) * 57.29578f;
    }
    {
        n8d2fd0::Accessor oldUp(oldObj, "lookUpAngle");
        n8d2fd0::Accessor newUp(newObj, "lookUpAngleDegrees");
        newUp.FUN_0093d6a0(0) = oldUp.FUN_0093d6a0(0) * 57.29578f;
    }
}
}   // namespace f3m_008d2fd0

// @f3 0x008d30a0 (community match, verified in this file)
extern const char str_00e31fdc[];
namespace f3m_008d30a0 {
namespace copy_reflected_signed_field {
struct FieldReference {
    void* object; unsigned int member;
    FieldReference(void*,const char*);
    const signed char* FUN_0093d700(int);
    int* FUN_0093d6c0(int);
};
void FUN_008d30a0(void* source,void* destination) {
    FieldReference from(source,str_00e31fdc);
    FieldReference to(destination,str_00e31fdc);
    *to.FUN_0093d6c0(0)=*from.FUN_0093d700(0);
}
}
}   // namespace f3m_008d30a0

// @f3 0x008d2f50 (community match, verified in this file)
extern const char str_00e31f50[],str_00e31f48[],str_00e31f34[],str_00e31f18[];
namespace f3m_008d2f50 {
namespace nested_reflected_float_copy {
struct hkClass;
struct hkVariant { void* object;const hkClass* type; };
struct hkClassMember { const hkClass* FUN_0093d890() const; };
struct hkClassMemberAccessor {
    void* object;const hkClassMember* member;
    hkClassMemberAccessor(const hkVariant&,const char*);
    const hkClassMember* FUN_0093d790() const;
    void* FUN_0093d660();
    float* FUN_0093d6a0(int);
};
static __declspec(noinline) void FUN_008d2ea0(const hkVariant& source,const hkVariant& destination) {
    hkClassMemberAccessor from(source,str_00e31f48),to(destination,str_00e31f48);
    hkVariant fromValue;fromValue.type=from.FUN_0093d790()->FUN_0093d890();fromValue.object=from.FUN_0093d660();
    hkVariant toValue;toValue.type=to.FUN_0093d790()->FUN_0093d890();toValue.object=to.FUN_0093d660();
    hkClassMemberAccessor oldField(fromValue,str_00e31f34),newField(toValue,str_00e31f18);
    *newField.FUN_0093d6a0(0)=*oldField.FUN_0093d6a0(0);
}
void FUN_008d2f50(const hkVariant& source,const hkVariant& destination) {
    hkClassMemberAccessor from(source,str_00e31f50),to(destination,str_00e31f50);
    hkVariant fromValue;fromValue.type=from.FUN_0093d790()->FUN_0093d890();fromValue.object=from.FUN_0093d660();
    hkVariant toValue;toValue.type=to.FUN_0093d790()->FUN_0093d890();toValue.object=to.FUN_0093d660();
    FUN_008d2ea0(fromValue,toValue);
}
}
}   // namespace f3m_008d2f50

// @f3 0x008d3910 (community match, verified in this file)
extern const char str_00e32174[],str_00e3215c[];
namespace f3m_008d3910 {
namespace reflect_byte_to_bool {
struct hkVariant;
struct hkClassMemberAccessor {
    void* object;void* member;
    hkClassMemberAccessor(const hkVariant&,const char*);
    const signed char* FUN_0093d700(int);
    bool* FUN_0093d690(int);
};
void FUN_008d3910(const hkVariant& source,const hkVariant& destination) {
    hkClassMemberAccessor from(source,str_00e32174),to(destination,str_00e3215c);
    *to.FUN_0093d690(0)=(*from.FUN_0093d700(0)!=0);
}
}
}   // namespace f3m_008d3910

// @f3 0x008d2a00 (community match, verified in this file)
namespace f3m_008d2a00 {
namespace n8d2a00 {
struct V4 { float x, y, z, w; };
struct M3 { V4 c0, c1, c2; };
}
struct Vec8d2a00 {
    float x, y, z, w;
    void hkVector4_setRotatedDir(const n8d2a00::M3& m, const n8d2a00::V4& v);
};
// pdb: hkVector4::setRotatedDir | hkVector4.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void Vec8d2a00::hkVector4_setRotatedDir(const n8d2a00::M3& m, const n8d2a00::V4& v)
{
    float vx = v.x;
    float vy = v.y;
    float vz = v.z;
    x = m.c0.x * vx + m.c1.x * vy + m.c2.x * vz;
    y = m.c0.y * vx + m.c1.y * vy + m.c2.y * vz;
    z = m.c0.z * vx + m.c1.z * vy + m.c2.z * vz;
    w = 0.0f;
}
}   // namespace f3m_008d2a00

// @f3 0x008d79d0 (community match, verified in this file)
namespace f3m_008d79d0 {
namespace task1199 {
struct Object;struct Collision;
struct Flags {unsigned unk00,unk04,unk08,flags;};Flags* __cdecl FUN_00aa60f0(Object*);
inline unsigned Enabled(Object*p){Flags*f=FUN_00aa60f0(p);return f ? (f->flags&2) : 0;}
struct Context {void*current;bool recurse;unsigned traversal;float value;int unk10,unk14,unk18;};
typedef void (__cdecl *Callback)(Collision*,Context*);extern Callback DAT_00f794c0;
void __cdecl FUN_008d5790(Object*,Context*,Callback);
// pdb: bhkWorld::SetFriction | bhkWorld.obj | fnv360_0721_beta, objrun, medium
// pdb params: apObject, afFriction, abRecurse, abForce
bool __cdecl FUN_008d79d0(Object*object,float value,bool recurse,bool force){bool result=false;if(object&&(force||Enabled(object))){Context context;result=true;context.current=0;context.recurse=recurse;context.traversal=0x10;context.value=value;if(DAT_00f794c0)FUN_008d5790(object,&context,DAT_00f794c0);}return result;}
}
}   // namespace f3m_008d79d0

// @f3 0x008c1ed0 (community match, verified in this file)
extern unsigned char DAT_01092788;
namespace f3m_008c1ed0 {
struct RTTI39 {const char*name;RTTI39* parent;};
struct Object39 {virtual void a() throw();virtual void Destroy() throw();virtual RTTI39* GetRTTI() const;volatile long references;void FUN_008c1560(void*) throw();void IncRefCount() throw(){InterlockedIncrement(&references);}void DecRefCount() throw(){if(!InterlockedDecrement(&references))Destroy();}};
struct Ref39 {Object39* value;Ref39():value(0){} bool operator==(Object39* p)const{return value==p;}
__forceinline ~Ref39() throw(){if(value)value->DecRefCount();}
Ref39& FUN_008e9650(Object39* p) throw(){if(value!=p){if(value)value->DecRefCount();value=p;if(value)value->IncRefCount();}return *this;}
__declspec(noinline) Ref39& FUN_008e9600(const Ref39& p) throw(){if(value!=p.value){if(value)value->DecRefCount();value=p.value;if(value)value->IncRefCount();}return *this;}
};
struct Stream39 {
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
    unsigned int version;
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
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    Object39** objects;
    unsigned int unk224,count;
};
__declspec(noinline) Object39* __cdecl FUN_00424d50(const void* type,Object39* object){if(!object)return 0;RTTI39* r=object->GetRTTI();bool found=false;while(r){if(r==type){found=true;break;}r=r->parent;}return found?object:0;}
Object39* __cdecl FUN_008c1c80(Stream39*,unsigned int,void*);
// pdb: NiSequence::CreateFromKFFile | NiSequence.obj | fnv360_0822_retail, objrun + bridge(call_seq|call_gap_sim) + skyrim(call_gap), high
void __cdecl NiSequence_CreateFromKFFile(Stream39* stream,unsigned int index,Ref39& result,void* extra) throw() {
    Ref39 program;
    if(stream->version<0x04010003) program.FUN_008e9650(FUN_008c1c80(stream,index,extra));
    else {
        if(index>=stream->count) { result.FUN_008e9650(0); return; }
        Object39* object=stream->objects[index];
        program.FUN_008e9650(FUN_00424d50(&DAT_01092788,object));
    }
    if(program == (Object39*)0) { result.FUN_008e9650(0); return; }
    if(extra) program.value->FUN_008c1560(extra);
    result.FUN_008e9600(program);
}

}   // namespace f3m_008c1ed0

// @f3 0x008c63f0 (community match, verified in this file)
namespace f3m_008c63f0 {
extern const char* FUN_00e207a8;   // the table's null string handle

struct FixedString
{
    const char* handle;

    FixedString& operator=(const FixedString& other)
    {
        const char* incoming = other.handle;
        if (handle != incoming) {
            if (incoming != FUN_00e207a8)
                InterlockedIncrement((LONG*)(incoming - 8));
            if (handle != FUN_00e207a8)
                InterlockedDecrement((LONG*)(handle - 8));
            handle = incoming;
        }
        return *this;
    }
};
extern FixedString DAT_0108f3fc;

struct RefObject
{
    virtual void Unk00();
    virtual void DeleteThis();
    LONG refCount;

    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
    RefObject* FUN_00825a70();
};

struct RefPointer
{
    RefObject* object;

    RefPointer& operator=(RefObject* other)
    {
        if (object != other) {
            if (object)
                object->DecRefCount();
            object = other;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
};

struct Block32
{
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
};

struct ObjectBase
{
    void* vtable;
    int unk04;
    int unk08;

    void FUN_0086b760(ObjectBase* dest, void* cloning);
};

struct FUN_008c63f0_Obj : public ObjectBase
{
    unsigned short flags;
    int unk10;
    FixedString name;
    Block32 block;
    RefPointer pointers[3];

    void SetBit(bool value, unsigned short mask) { if (value) flags |= mask; else flags &= ~mask; }
    bool GetBit(unsigned short mask) const { return (flags & mask) != 0; }
    void SetField(unsigned short value, unsigned short mask, unsigned short pos) { flags = (flags & ~mask) | (value << pos); }
    unsigned short GetField(unsigned short mask, unsigned short pos) const { return (flags & mask) >> pos; }

    void FUN_008c63f0(FUN_008c63f0_Obj* dest, void* cloning);
};

// pdb: NiLookAtInterpolator::CopyMembers | NiLookAtInterpolator.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkDest, kCloning
void FUN_008c63f0_Obj::FUN_008c63f0(FUN_008c63f0_Obj* dest, void* cloning)
{
    ObjectBase::FUN_0086b760(dest, cloning);
    dest->flags = flags;
    dest->SetBit(GetBit(1), 1);
    dest->SetField(GetField(6, 1), 6, 1);
    dest->unk10 = unk10;
    dest->name = DAT_0108f3fc;
    dest->block = block;
    for (int i = 0; i < 3; i++) {
        if (pointers[i].object)
            dest->pointers[i] = pointers[i].object->FUN_00825a70();
    }
}
}

// @f3 0x008d4f10 (community match, verified in this file)
namespace f3m_008d4f10 {
extern __declspec(thread) int tls_memContext;
struct AutoMemContext {
    int saved;
    AutoMemContext(int context)
    {
        saved = tls_memContext;
        tls_memContext = context;
    }
    ~AutoMemContext()
    {
        tls_memContext = saved;
    }
};
class Heap4f10
{
public:
    void* FUN_0086b930(unsigned int bytes);
};
extern Heap4f10 DAT_01090a78;
// pdb: bhkMemoryAllocator::`scalar deleting destructor' | bhkWorld.obj | fnv360_1110_retail, objopen_prop, low
void* __stdcall FUN_008d4f10(unsigned int size, int unused)
{
    AutoMemContext context(0x10);
    unsigned char* memory = (unsigned char*)DAT_01090a78.FUN_0086b930(size + 16);
    unsigned char pad = (unsigned char)(16 - ((unsigned char)(unsigned int)memory & 0xf));
    memory += pad;
    memory[-1] = pad;
    return memory;
}
}

// @f3 0x008d5ea0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern int DAT_010f3400;
extern unsigned long DAT_01179af4;
#pragma intrinsic(__readfsdword)
extern __declspec(thread) int tlsVar298;
namespace f3m_008d5ea0 {
extern "C" {
__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
__declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
}
extern "C" unsigned long __readfsdword(unsigned long);

inline void* operator new(unsigned int, void* p) { return p; }
struct Pool { void* FUN_008f6f60(int a, int b); };
struct Obj330 {
    Obj330(int a, int b);
    int unk4;
    int unk8;
    int unkc;
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
    int unk110;
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
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;

    virtual void slot00();
    virtual void slot04();
    virtual void slot08(void* buf, int size);
    __declspec(dllimport) static void* operator new(unsigned int size, int align);
    __declspec(dllimport) static void operator delete(void*, int);
};
void FUN_0092e8f0(Obj330*);
struct Slot { unsigned long unk00; Obj330* unk04; void* unk08; };

struct Lock {
    void* p;
    Lock(void* q) : p(q) { EnterCriticalSection(p); }
    ~Lock() { LeaveCriticalSection(p); }
};

struct HeapCtx {
    int saved;
    HeapCtx(int v) {
        saved = tlsVar298;
        tlsVar298 = v;
    }
    ~HeapCtx() { tlsVar298 = saved; }
};

struct FUN_008d5ea0_cls {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    void FUN_008d5ea0();
};

void FUN_008d5ea0_cls::FUN_008d5ea0()
{
    EnterCriticalSection(this);
    if (unkd8 < 16) {
        HeapCtx ctx(16);
        Obj330* o = new (16) Obj330(DAT_010f3400, 16);
        if (o) {
            FUN_0092e8f0(o);
            Pool* pool = (Pool*)TlsGetValue(DAT_010f3170);
            void* buf = pool->FUN_008f6f60(0x5000, 1);
            Slot* s = &((Slot*)this)[unkd8 + 2];
            o->slot08(buf, 0x5000);
            s->unk00 = GetCurrentThreadId();
            s->unk04 = o;
            s->unk08 = buf;
        }
        ++unkd8;
    }
    LeaveCriticalSection(this);
}
}   // namespace f3m_008d5ea0

// @f3 0x008d6420 (community match, verified in this file)
#include <stddef.h>
#include <string.h>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
extern int DAT_010f2a64;
extern float DAT_010f2be8;
extern unsigned int DAT_010f2bf4;
extern bool DAT_010f2bdc;

class WorldHeap
{
public:
    void* FUN_0086b930(unsigned int bytes);
};
extern WorldHeap DAT_01090a78;

struct HavokFreeBlock
{
    HavokFreeBlock* next;
};

struct HavokFreeList
{
    HavokFreeBlock* first;
    unsigned int count;

    __forceinline void* Take(HavokFreeBlock* block)
    {
        --count;
        first = block->next;
        return block;
    }
};

struct HavokWorldAllocator
{
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
    HavokFreeList worldSupportPool;
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
    HavokFreeList worldDebugPool;
    void* FUN_008f6800(int sizeClass, int tag);
};

struct HavokWorldData
{
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
    int mode;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    float value1A4;
    float value1A8;
};

struct WorldSupport
{
    HavokWorldData* world;
    unsigned int setting;
    unsigned int unk08;
    bool enabled;

    WorldSupport();
    __forceinline void* operator new(size_t)
    {
        HavokWorldAllocator* allocator = static_cast<HavokWorldAllocator*>(TlsGetValue(DAT_010f3170));
        HavokFreeBlock* first = allocator->worldSupportPool.first;
        if (first)
            return allocator->worldSupportPool.Take(first);
        return allocator->FUN_008f6800(3, 13);
    }
    void operator delete(void*);
};

struct WorldDebug
{
    WorldDebug(WorldSupport*);
    __forceinline void* operator new(size_t)
    {
        HavokWorldAllocator* allocator = static_cast<HavokWorldAllocator*>(TlsGetValue(DAT_010f3170));
        HavokFreeBlock* first = allocator->worldDebugPool.first;
        if (first)
        {
            --allocator->worldDebugPool.count;
            allocator->worldDebugPool.first = first->next;
            return first;
        }
        return allocator->FUN_008f6800(12, 13);
    }
    void operator delete(void*);
};

struct WorldConfig;
struct WorldInit
{
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
};
struct WorldConfig
{
    unsigned int unk00;
};
struct WorldInitData : WorldInit, WorldConfig {};

struct WorldArrayA
{
    void* buffer;
    unsigned int count;
    unsigned int capacity;
    WorldArrayA() : buffer(0), count(0), capacity(0x80000000u) {}
    ~WorldArrayA();
};

struct WorldArrayB
{
    void* buffer;
    unsigned int count;
    unsigned int capacity;
    WorldArrayB() : buffer(0), count(0), capacity(0x80000000u) {}
    ~WorldArrayB();
};

struct WorldList
{
    void* item;
    WorldList* next;
    WorldList() : item(0), next(0) {}
    ~WorldList();
    void FUN_005e3010();
};

class bhkRefObject
{
public:
    bhkRefObject();
    virtual ~bhkRefObject();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3c();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4c();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5c();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6c();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7c();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8c();
    virtual void Slot90();
    virtual void Slot94();
    virtual HavokWorldData* GetWorld();
    __forceinline HavokWorldData* World() { return GetWorld(); }
    unsigned int unk04;
    HavokWorldData* world;
};

class bhkSerializable : public bhkRefObject
{
public:
    unsigned int unk0C;
    bhkSerializable() : unk0C(0) {}
};

__forceinline void SetWorldLimit(float& setting, const float& value)
{
    setting = value;
}

class bhkWorld : public bhkSerializable
{
public:
    bhkWorld(WorldInitData* init);
    virtual ~bhkWorld();
    void FUN_008d5510(WorldConfig* init);

    WorldDebug* debug;
    WorldSupport* support;
    void* visualDebugger;
    bool unk1C, enabled, unk1E, unk1F;
    unsigned int unk20, unk24, unk28, unk2C, unk30;
    void* buffer34;
    unsigned int count38;
    void* buffer3C;
    unsigned int count40;
    void* buffer44;
    unsigned int count48;
    void* buffer4C;
    unsigned int count50;
    void* buffer54;
    unsigned int count58, unk5C;
    float value60, value64, value68, value6C;
    WorldArrayA array70;
    WorldArrayB array7C;
    float value88, value8C;
    WorldList list;
};

// pdb: bhkWorld::bhkWorld | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
bhkWorld::bhkWorld(WorldInitData* init) : debug(0), support(0)
{
    ++DAT_010f2a64;
    unk1C = false;
    visualDebugger = 0;
    enabled = false;
    unk1E = false;
    unk28 = 0;
    unk2C = 0;
    unk30 = 0;
    unk20 = 0;
    unk24 = 0;

    count38 = 0;
    buffer34 = DAT_01090a78.FUN_0086b930(0x2ee0);
    memset(buffer34, 0, 0x2ee0);
    count40 = 0;
    buffer3C = DAT_01090a78.FUN_0086b930(0x320);
    memset(buffer3C, 0, 0x320);
    count48 = 0;
    buffer44 = DAT_01090a78.FUN_0086b930(0x190);
    memset(buffer44, 0, 0x190);
    count50 = 0;
    buffer4C = DAT_01090a78.FUN_0086b930(0x320);
    memset(buffer4C, 0, 0x320);
    count58 = 0;
    buffer54 = DAT_01090a78.FUN_0086b930(0x2ee0);
    memset(buffer54, 0, 0x2ee0);

    SetWorldLimit(DAT_010f2be8, DAT_010f2be8 < 1.0f ? +DAT_010f2be8 : 1.0f);
    value60 = value64 = value68 = value6C = 0.0f;
    list.FUN_005e3010();
    FUN_008d5510(init);
    value88 = World()->value1A4;
    value8C = World()->value1A8;
    HavokWorldData* currentWorld = World();
    if (World()->mode == 3)
    {
        support = new WorldSupport;
        support->setting = DAT_010f2bf4;
        support->world = currentWorld;
        support->enabled = DAT_010f2bdc;
        debug = new WorldDebug(support);
    }
}

// @f3 0x008c1600 (community match, verified in this file)
#include <windows.h>
namespace f3m_008c1600 {
namespace task0729 {
struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_008c1600(unsigned int idx, NiRefStubB5652** a2);
};

// @fnv 0x00a32940
// pdb: NiPathInterpolator::GetTotalPathLength | NiPathInterpolator.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: NiTArray<class NiPointer<class NiTransformController>,class NiTNewInterface<class NiPointer<class NiTransformController> > >::SetAt)
void FUN_00a32940_cls::FUN_008c1600(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((unsigned int)*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((unsigned int)*apNewStub != key.m_00)
        {
            if ((unsigned int)m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((unsigned int)m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

}
}   // namespace f3m_008c1600

// @f3 0x008da650 (community match, verified in this file)
#include <windows.h>
extern int DAT_010f2c20;
namespace f3m_008da650 {
namespace task0756 {
template<class T> struct HeldPointer {
 T* value;
 ~HeldPointer() { if(value) value->DecRefCount(); }
 operator T*() const { return value; }
 T* operator->() const { return value; }
};
class C6C290Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void Detach();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            vfunc01();
    }
};


class FUN_0084a740
{
  public:
    virtual ~FUN_0084a740();
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_008da650 : public FUN_0084a740
{
  public:
    HeldPointer<C6C290Object> m_pReferencedObject;

    void FUN_008da000(int iValue);
    virtual ~FUN_008da650();
};

// Decrements DAT_010f2c20, detaches the held C6C290Object if present, then calls FUN_008da000(0).
// @fnv 0x00c6c290
// pdb: bhkNiCollisionObject::~bhkNiCollisionObject | bhkNiCollisionObject.obj | fnv360_0822_retail, call_seq, medium
FUN_008da650::~FUN_008da650()
{
    DAT_010f2c20--;
    if (m_pReferencedObject)
        m_pReferencedObject->Detach();
    FUN_008da000(0);
}

}
}   // namespace f3m_008da650

// @f3 0x008d3ad0 (community match, verified in this file)
namespace aligned_heap_allocation {
struct ThreadData {
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
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    int memoryContext;
};
extern __declspec(thread) ThreadData threadData;
struct ContextScope {
    int previous;
    __forceinline ContextScope(int value) { previous=threadData.memoryContext;threadData.memoryContext=value; }
    __forceinline ~ContextScope() { threadData.memoryContext=previous; }
};
struct Heap { void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
// pdb: hkFreeListMemorySystem::hkFreeListMemorySystem | hkFreeListMemorySystem.obj | fnv360_0822_retail, call_gap, low
void* FUN_008d3ad0(unsigned int bytes,unsigned char alignment) {
    ContextScope scope(16);
    unsigned char* memory=static_cast<unsigned char*>(DAT_01090a78.FUN_0086b930(bytes+alignment));
    unsigned char adjustment=static_cast<unsigned char>(alignment-((alignment-1)&reinterpret_cast<unsigned int>(memory)));
    memory+=adjustment;memory[-1]=adjustment;return memory;
}
}

// @f3 0x008d4e70 (community match, verified in this file)
namespace f3m_008d4e70 {
namespace aligned_heap_allocation {
struct ThreadData {
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
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    int memoryContext;
};
extern __declspec(thread) ThreadData threadData;
struct ContextScope {
    int previous;
    __forceinline ContextScope(int value) { previous=threadData.memoryContext;threadData.memoryContext=value; }
    __forceinline ~ContextScope() { threadData.memoryContext=previous; }
};
struct Heap { void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
void* __stdcall FUN_008d4e70(unsigned char alignment,unsigned int bytes,unsigned int unused) {
    ContextScope scope(16);
    unsigned char* memory=static_cast<unsigned char*>(DAT_01090a78.FUN_0086b930(bytes+alignment));
    unsigned char adjustment=static_cast<unsigned char>(alignment-((alignment-1)&reinterpret_cast<unsigned int>(memory)));
    memory+=adjustment;memory[-1]=adjustment;return memory;
}
}
}   // namespace f3m_008d4e70

// @f3 0x008d4dc0 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_008d4dc0 {

extern "C" void _ReadWriteBarrier(void);


struct ThreadMemory8d4dc0 {
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
    void* unk98;
    int unk9c;
    void FUN_008f6890(int size, void* p, int memClass);
};

// pdb: bhkWorldCinfo::`scalar deleting destructor' | bhkWorld.obj | fnv360_0721_beta, objrun_open, low
void __cdecl FUN_008d4dc0(void* p) {
    if (p) {
        ThreadMemory8d4dc0* memory = (ThreadMemory8d4dc0*)TlsGetValue(DAT_010f3170);
        if (memory->unk9c >= memory->unk34) {
            memory->FUN_008f6890(0xc, p, 0xd);
        } else {
            _ReadWriteBarrier();
            void* next = memory->unk98;
            memory->unk9c++;
            *(void**)p = next;
            memory->unk98 = p;
        }
    }
}
}   // namespace f3m_008d4dc0

// @f3 0x008c8060 (community match, verified in this file)
extern int DAT_00db7764,DAT_00e2087c,DAT_00e2fa54; extern long DAT_0108ed80;
namespace f3m_008c8060 {
namespace w8c8060 {
void* FUN_0089eb90(unsigned);
struct Object {
 void* table; int refs;
 __declspec(noinline) Object* FUN_00825800() { table=&DAT_00db7764; refs=0; InterlockedIncrement(&DAT_0108ed80); table=&DAT_00e2087c; return this; }
};
struct TransformData: Object {
 unsigned short counts[3]; void* keys[3]; unsigned char types[3]; void* auxiliary[3];
 __forceinline TransformData() {
  FUN_00825800();
  counts[0]=0; auxiliary[0]=0; keys[0]=0; types[0]=0;
  counts[1]=0; auxiliary[1]=0; keys[1]=0; types[1]=0;
  counts[2]=0; auxiliary[2]=0; keys[2]=0; types[2]=0;
  table=&DAT_00e2fa54;
 }
 static void* operator new(unsigned n) { return FUN_0089eb90(n); }
};
// pdb: NiTransformData::CreateObject | NiTransformData.obj | fnv360_0822_retail, objrun, medium
TransformData* FUN_008c8060() { return new TransformData; }
}
}   // namespace f3m_008c8060

// @f3 0x008db880 (community match, verified in this file)
#include <math.h>
namespace f3m_008db880 {
inline float PlaneProduct(float a,float b){return a*b;}
struct NormalPlane {float x,y,z,w;float Square(){return x*x+y*y+z*z;}float InverseLength(){float n=Square();if(n!=0.0f){float length=(float)sqrt(n);return 1.0f/length;}return 0.0f;}void Scale(float f){x=PlaneProduct(x,f);y=PlaneProduct(y,f);z=PlaneProduct(z,f);w=PlaneProduct(w,f);}void FUN_008db880(NormalPlane*);};
// pdb: hkpRigidBody::setAngularVelocity | TESObjectREFR.obj | fnv360_0822_retail, call_gap, low
// pdb params: newVel
void NormalPlane::FUN_008db880(NormalPlane* out){out->x=x;out->y=y;out->z=z;out->w=w;float inverse=out->InverseLength();out->Scale(inverse);if(w<0.0f){out->x=-out->x;out->y=-out->y;out->z=-out->z;out->w=-out->w;}}
}   // namespace f3m_008db880

// @f3 0x008d5670 (community match, verified in this file)
namespace f3m_008d5670 {
namespace create670 {extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);extern unsigned long DAT_010f3170;struct Alloc {void* FUN_008f6d30(unsigned,int);};struct bhkWorldCinfo {void* table;unsigned short size;short count; // src: F3_EXE vtable 0x00e32184 (old: FUN_008d3a60)
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
static void* operator new(unsigned size){Alloc* a=(Alloc*)TlsGetValue(DAT_010f3170);bhkWorldCinfo* p=(bhkWorldCinfo*)a->FUN_008f6d30(size,0x2f);p->size=(unsigned short)size;return p;}bhkWorldCinfo();};struct Owner;struct Table {
void* unk00;
void* unk04;
void* unk08;
void* unk0c;
void* unk10;
void* unk14;
void* unk18;
void* unk1c;
void* unk20;
void* unk24;
void* unk28;
void* unk2c;
void* unk30;
void* unk34;
void* unk38;
void* unk3c;
void* unk40;
void* unk44;
void* unk48;
void* unk4c;
void* unk50;
void* unk54;
void* unk58;
void* unk5c;
void* unk60;
void* unk64;
void* unk68;
void* unk6c;
void* unk70;
void* unk74;
void* unk78;
void* unk7c;
void* unk80;
void* unk84;
void* unk88;
void* unk8c;
void* unk90;
void* unk94;
void* unk98;
void* unk9c;
void* unka0;
void* unka4;
void* unka8;
void* unkac;
void* unkb0;
void* unkb4;
void* unkb8;
void* unkbc;
void* unkc0;
void (__thiscall *set)(Owner*,bhkWorldCinfo*);};struct Owner {Table* table;int unk04;int enabled;void* tail;void* FUN_008d5670(bool*);};void* Owner::FUN_008d5670(bool* created){if(!tail){bhkWorldCinfo* object=new bhkWorldCinfo;tail=object?(char*)object+0xd0:0;if(enabled){bhkWorldCinfo* adjusted=tail?(bhkWorldCinfo*)((char*)tail-0xd0):0;table->set(this,adjusted);}*created=true;}else *created=false;return tail;}}
}   // namespace f3m_008d5670

// @f3 0x008d4ad0 (community match, verified in this file)
namespace f3m_008d4ad0 {
namespace w8d4ad0 {
struct Flags { int unk00; int unk04; int unk08; int unk0c; int unk10; unsigned char value; };
struct Item { int unk00,unk04,unk08; Flags* flags; void FUN_009316f0(); };
struct Handler { void FUN_009078c0(Item**,unsigned); };
void FUN_00c00610(void*,int,unsigned);
struct Owner { void** table; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; Item** items; unsigned count;
 Handler* Get() { return ((Handler*(__thiscall*)(Owner*))table[38])(this); } void FUN_008d4ad0(); };
// pdb: bhkWorld::ProcessBatchRemovals | bhkWorld.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: bhkWorld::AddBatchedPhantoms)
// pdb params: abAllowPartial
void Owner::FUN_008d4ad0() {
 if(count>0) {
  if(count>=200) count=200;
  Handler* handler=Get();
  if(handler) {
   handler->FUN_009078c0(items,count);
   for(unsigned i=0;i<count;++i) {
    Item* item=items[i]; if(item) { Flags* flags=item->flags; if(flags) flags->value&=~0x20; }
    items[i]->FUN_009316f0();
   }
   unsigned bytes=count; bytes+=bytes; bytes+=bytes; FUN_00c00610(items,0,bytes); count=0;
  }
 }
}
}
}   // namespace f3m_008d4ad0

// @f3 0x008d4b60 (community match, verified in this file)
namespace f3m_008d4b60 {
namespace workerB8d4b60 {
struct Item{virtual ~Item();unsigned short size;short refs;void* data;};struct Context{void FUN_009084b0(Item*);};
void* __cdecl FUN_00c00610(void*,int,unsigned);
struct Pointer{Item* value;operator bool()const{return value!=0;}Item* Get(){return value;}Item* operator->(){return value;}};
struct Owner{virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1c();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2c();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3c();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4c();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5c();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6c();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7c();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8c();virtual void slot90();virtual void slot94();virtual Context* GetContext();int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;Pointer* items;unsigned count;void FUN_008d4b60();};
// pdb: PIXBeginNamedEvent_Copy_NoVarArgs | pix.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: bhkWorld::AddBatchedEntities)
// pdb params: Color, pFormat
void Owner::FUN_008d4b60(){if(count>0){if(count>=100)count=100;Context* context=GetContext();if(context){for(unsigned i=0;i<count;++i){if(items[i]&&items[i]->data)context->FUN_009084b0(items[i].Get());if(items[i]){Item* old=items[i].Get();if(old->size&&--old->refs==0)delete old;}}FUN_00c00610(items,0,count*sizeof(Item*));count=0;}}}
}

}   // namespace f3m_008d4b60

// @f3 0x008d2a80 (community match, verified in this file)
namespace f3m_008d2a80 {
// pdb: hkVector4::setMul3 | hkVector4.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: a, b
struct InputB5{float x,y,z;};union InputSlotB5{const InputB5*pointer;float y;};struct MatrixB5{float rows[3][4];};struct OutputB5{float x,y,z,w;void FUN_008d2a80(const MatrixB5*,InputSlotB5);};void OutputB5::FUN_008d2a80(const MatrixB5*m,InputSlotB5 in){const InputB5*source=in.pointer;float first=source->x;in.y=source->y;float third=source->z;x=m->rows[0][0]*first+m->rows[1][0]*in.y+m->rows[2][0]*third;y=m->rows[0][1]*first+m->rows[1][1]*in.y+m->rows[2][1]*third;z=m->rows[0][2]*first+m->rows[1][2]*in.y+m->rows[2][2]*third;w=0.0f;}
}   // namespace f3m_008d2a80

// @f3 0x008da000 (community match, verified in this file)
namespace f3m_008da000 {
class NiRefObject {
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

struct ListenerResult8da {
    int unk00;
    int unk04;
};

struct ListenerValue8da {void* object;void* context;};
struct ListenerList8da {
    ListenerResult8da FUN_009317a0(const void* key);
    void hkpWorldObject_addProperty(const void* key, ListenerValue8da value);
};

class Source8da : public NiRefObject {
public:
    ListenerList8da* m_listeners;
};

struct Owner8da {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiPointer<Source8da> m_source;
    void FUN_008da000(Source8da* source);
};

// pdb: bhkNiCollisionObject::SetWorldObject | bhkNiCollisionObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apWorldObject
void Owner8da::FUN_008da000(Source8da* source)
{
    if (m_source == source)
        return;
    if (m_source) {
        ListenerList8da* listeners = m_source->m_listeners;
        if (listeners)
            listeners->FUN_009317a0(&DAT_010f2c30);
    }
    m_source = source;
    if (m_source) {
        ListenerValue8da value={this,0};
        ListenerList8da* listeners = m_source->m_listeners;
        if (listeners)
            listeners->hkpWorldObject_addProperty(&DAT_010f2c30, value);
    }
}
}   // namespace f3m_008da000

// @f3 0x008d1350 (community match, verified in this file)
namespace f3m_008d1350 {
namespace workerA8d13 {
struct Type {int unk00;Type*parent;};extern Type DAT_0109288c;
struct Arg {void**methods;void FUN_008cd050(int);};
struct Owner {void**methods;void FUN_008d1350(Arg*,int);};
typedef Type*(__thiscall* TypeFn)(Arg*);
typedef void(__thiscall* GetFn)(Owner*,int*);
static __forceinline bool IsWanted(Arg*arg) {
 Type*type=((TypeFn)arg->methods[2])(arg);
 while(type) {if(type==&DAT_0109288c)return true;type=type->parent;}
 return false;
}
// pdb: NiBoolInterpController::SynchronizePoseInterpolator | NiBoolInterpController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkInterp, usIndex
void Owner::FUN_008d1350(Arg*arg,int) {
 Arg*filtered=arg;
 if(filtered) filtered=IsWanted(filtered)?filtered:0;
 int value;
 ((GetFn)methods[0xec/4])(this,&value);
 filtered->FUN_008cd050(value);
}
}
}   // namespace f3m_008d1350

// @f3 0x008dafb0 (community match, verified in this file)
namespace f3m_008dafb0 {
struct C8Vector {float x,y,z;};extern C8Vector DAT_0108ec68;
struct C8Root;
struct C8Proxy {void** table;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
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
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
void FUN_00752250(const C8Vector&);};
struct C8Context {void** table;
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
};
struct C8Info {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
unsigned flags;};
struct C8Event {
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
C8Info* info;};
struct C8Receiver {
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
unsigned char unk68;unsigned char enabled;unsigned char unk6a;unsigned char unk6b;int count;void FUN_008dafb0(C8Event*);};
struct C8Root:C8Proxy,C8Context,C8Receiver {};
// pdb: bhkCharacterListener::contactPointAddedCallback | bhkCharacterListener.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apProxy, arPoint
void C8Receiver::FUN_008dafb0(C8Event* event) {if((event->info->flags&0x7f)==30){++count;if(enabled){C8Root* owner=static_cast<C8Root*>(this);owner->FUN_00752250(DAT_0108ec68);}}}
}   // namespace f3m_008dafb0

// @f3 0x008d3eb0 (community match, verified in this file)
namespace f3m_008d3eb0 {
namespace workerA8d3e {
struct Vec3 {float x,y,z;};
struct Owner {
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
 float a,b,c;
 void FUN_008d3eb0(Vec3&) const;
};
// pdb: bhkWorld::GetOrigin | bhkWorld.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkTaskletManagerCallback::bhkTaskletManagerCallback)
// pdb params: arOrigin
void Owner::FUN_008d3eb0(Vec3&out) const {
 const double scale=6.999040126800537;
 out.x=a*scale;
 out.y=b*scale;
 out.z=scale*c;
}
}
}   // namespace f3m_008d3eb0

// @f3 0x008d3ba0 (community match, verified in this file)
struct RefObj8d3ba0 {
    virtual ~RefObj8d3ba0();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference() {
        if (memSizeAndFlags != 0) {
            if (--referenceCount == 0) delete this;
        }
    }
};

struct A8d3ba0 { virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10(int flag); };
struct B8d3ba0 { virtual void vf00(); virtual void vf04(); virtual void vf08(int flag); };

extern A8d3ba0* DAT_01169104;
extern B8d3ba0* DAT_01169138;
extern RefObj8d3ba0* DAT_010f2a68;
void __cdecl FUN_008e9140();
void __cdecl FUN_008e9170();
void __cdecl hkBaseSystem_quit();

// pdb: bhkWorld::QuitSystem | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_008d3ba0() {
    if (DAT_01169104) DAT_01169104->vf10(1);
    if (DAT_01169138) DAT_01169138->vf08(1);
    FUN_008e9140();
    FUN_008e9170();
    if (DAT_010f2a68) {
        DAT_010f2a68->removeReference();
        DAT_010f2a68 = 0;
    }
    hkBaseSystem_quit();
}

// @f3 0x008da450 (community match, verified in this file)
namespace f3m_008da450 {
struct Node8da450;

struct Group8da450 {
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
    Node8da450** children;
    unsigned short unka4;
    unsigned short childCount;
};

struct Result8da450;

struct Extra8da450 {
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
    virtual Result8da450* vf38();
};

struct Node8da450 {
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual Group8da450* vf0c();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Extra8da450* unk1c;
};

Result8da450* __cdecl FUN_008da450(Node8da450* node) {
    if (!node) return 0;
    Extra8da450* extra = node->unk1c;
    Result8da450* result = extra ? extra->vf38() : 0;
    if (!result) {
        Group8da450* group = node->vf0c();
        if (group) {
            for (unsigned int i = 0; i < group->childCount; i++) {
                Node8da450* child = group->children[i];
                result = FUN_008da450(child);
                if (result) break;
            }
        }
    }
    return result;
}
}   // namespace f3m_008da450

// @f3 0x008dbc60 (community match, verified in this file)
struct Vec8dbc60 {
    float x, y, z, w;
    void set(const Vec8dbc60& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};

extern Vec8dbc60 DAT_01092a50;

struct FUN_008dbc60 {
    short unk00;
    short unk02;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    Vec8dbc60 unk10;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    Vec8dbc60 unk30;
    FUN_008dbc60();
};

FUN_008dbc60::FUN_008dbc60() {
    unk00 = -1;
    unk02 = -1;
    unk04 = -1;
    unk10.set(DAT_01092a50);
    unk20 = -1.0f;
    unk24 = 1.0f;
    unk28 = 1.0f;
    unk2c = 1.0f;
    unk30.set(DAT_01092a50);
}

// @f3 0x008dd170 (community match, verified in this file)
namespace f3m_008dd170 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct T {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int limit;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    void* head;
    int count;
    void FUN_008f6890(int sizeClass, void* block, int category);
};
}

void __cdecl FUN_008dd170(void* block)
{
    if (block) {
        f3m_008dd170::T* pool =
            static_cast<f3m_008dd170::T*>(f3m_008dd170::DAT_00d9b080(f3m_008dd170::DAT_010f3170));
        if (*reinterpret_cast<volatile int*>(&pool->count) >= pool->limit) {
            pool->FUN_008f6890(5, block, 0xe);
        } else {
            void** __restrict next = static_cast<void**>(block);
            *next = pool->head;
            ++pool->count;
            pool->head = block;
        }
    }
}

// @f3 0x008dd1d0 (community match, verified in this file)
namespace f3m_008dd1d0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct T {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int limit;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    void* head;
    int count;
    void FUN_008f6890(int sizeClass, void* block, int category);
};
}

// pdb: BSSimpleArray<TESCaravanCard *,1024>::`scalar deleting destructor' | CaravanMenu.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_008dd1d0(void* block)
{
    if (block) {
        f3m_008dd1d0::T* pool =
            static_cast<f3m_008dd1d0::T*>(f3m_008dd1d0::DAT_00d9b080(f3m_008dd1d0::DAT_010f3170));
        if (*reinterpret_cast<volatile int*>(&pool->count) >= pool->limit) {
            pool->FUN_008f6890(6, block, 0xe);
        } else {
            void** __restrict next = static_cast<void**>(block);
            *next = pool->head;
            ++pool->count;
            pool->head = block;
        }
    }
}

// @f3 0x008d4d80 (community match, verified in this file)
namespace f3m_008d4d80 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct T {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int limit;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c;
    void* head;
    int count;
    void FUN_008f6890(int sizeClass, void* block, int category);
};
}

void __cdecl FUN_008d4d80(void* block)
{
    if (block) {
        f3m_008d4d80::T* pool =
            static_cast<f3m_008d4d80::T*>(f3m_008d4d80::DAT_00d9b080(f3m_008d4d80::DAT_010f3170));
        if (*reinterpret_cast<volatile int*>(&pool->count) >= pool->limit) {
            pool->FUN_008f6890(3, block, 0xd);
        } else {
            void** __restrict next = static_cast<void**>(block);
            *next = pool->head;
            ++pool->count;
            pool->head = block;
        }
    }
}

// @f3 0x008dd210 (community match, verified in this file)
namespace f3m_008dd210 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct T {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int limit;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    void* head;
    int count;
    void FUN_008f6890(int sizeClass, void* block, int category);
};
}

// pdb: CaravanMenu::`scalar deleting destructor' | CaravanMenu.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_008dd210(void* block)
{
    if (block) {
        f3m_008dd210::T* pool =
            static_cast<f3m_008dd210::T*>(f3m_008dd210::DAT_00d9b080(f3m_008dd210::DAT_010f3170));
        if (*reinterpret_cast<volatile int*>(&pool->count) >= pool->limit) {
            pool->FUN_008f6890(4, block, 0xe);
        } else {
            void** __restrict next = static_cast<void**>(block);
            *next = pool->head;
            ++pool->count;
            pool->head = block;
        }
    }
}

// @f3 0x008d2970 (community match, verified in this file)
namespace f3m_008d2970 {
struct Vec8d2970 {
    float x;
    float y;
    float z;
    float w;
};

struct Transform8d2970 {
    Vec8d2970 col0;
    Vec8d2970 col1;
    Vec8d2970 col2;
    Vec8d2970 translation;
};

struct Out8d2970 {
    float x;
    float y;
    float z;
    float w;
    void FUN_008d2970(const Transform8d2970& t, const Vec8d2970& v);
};

// pdb: hkVector4::setTransformedInversePos | hkVector4.obj | fnv360_0822_retail, objrun, medium
// pdb params: t, v
void Out8d2970::FUN_008d2970(const Transform8d2970& t, const Vec8d2970& v)
{
    float dx = v.x - t.translation.x;
    float dy = v.y - t.translation.y;
    float dz = v.z - t.translation.z;
    x = t.col0.x * dx + t.col0.y * dy + t.col0.z * dz;
    y = t.col1.x * dx + t.col1.y * dy + t.col1.z * dz;
    z = t.col2.x * dx + t.col2.y * dy + t.col2.z * dz;
    w = 0.0f;
}
}   // namespace f3m_008d2970

// @f3 0x008d28e0 (community match, verified in this file)
namespace f3m_008d28e0 {
struct Vec8d2970 {
    float x;
    float y;
    float z;
    float w;
};

struct Transform8d2970 {
    Vec8d2970 col0;
    Vec8d2970 col1;
    Vec8d2970 col2;
    Vec8d2970 translation;
};

struct Out8d2970 {
    float x;
    float y;
    float z;
    float w;
    void hkVector4_setTransformedPos(const Transform8d2970& t, const Vec8d2970& v);
};

// pdb: hkVector4::setTransformedPos | hkVector4.obj | fnv360_0822_retail, call_seq + bridge(call_dedup|call_gap_sim) + skyrim(call_seq), high
void Out8d2970::hkVector4_setTransformedPos(const Transform8d2970& t, const Vec8d2970& v)
{
    float vx = v.x;
    float vy = v.y;
    float vz = v.z;
    x = t.col0.x * vx + t.col1.x * vy + t.col2.x * vz + t.translation.x;
    y = t.col0.y * vx + t.col1.y * vy + t.col2.y * vz + t.translation.y;
    z = t.col0.z * vx + t.col1.z * vy + t.col2.z * vz + t.translation.z;
    w = 0.0f;
}
}   // namespace f3m_008d28e0

// @f3 0x008d2850 (community match, verified in this file)
#include <math.h>
extern const double DAT_00db38a8;
namespace f3m_008d2850 {


struct hkBool8d2 {
    char m_bool;
    hkBool8d2() {}
    hkBool8d2(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};

inline float hkFabs8d2(float r) { return (float)fabs(r); }

struct hkQuat8d2 {
    float x;
    float y;
    float z;
    float w;
    float lengthSquared4() const { return x * x + y * y + z * z + w * w; }
    hkBool8d2 FUN_008d27a0() const;
    hkBool8d2 FUN_008d2850(float epsilon) const;
};

// pdb: hkVector4::isNormalized4 | hkVector4.obj | tesv_win, objrun_prop, low
hkBool8d2 hkQuat8d2::FUN_008d2850(float epsilon) const
{
    if (FUN_008d27a0()) {
        float length = lengthSquared4();
        float error = hkFabs8d2((float)(length - DAT_00db38a8));
        return error < epsilon;
    }
    return false;
}
}   // namespace f3m_008d2850

// @f3 0x008d5820 (community match, verified in this file)
extern bool DAT_00f79454;
namespace f3m_008d5820 {
namespace node_update_fast_b {

struct UpdateData { float time; bool updateControllers,updateSkin,updateNormals,updateBounds,updateOther;

    UpdateData() : time(0.0f),updateControllers(false),updateSkin(false),updateNormals(false),updateBounds(false),updateOther(false) {}

};

struct Object {

    virtual void slot00();

    virtual void slot04();

    virtual void slot08();

    virtual void slot0C();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1C();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2C();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual Object* Get3C();

    virtual void slot40();

    virtual void slot44();

    virtual void slot48();

    virtual void slot4C();

    virtual void slot50();

    virtual void slot54();

    virtual void slot58();

    virtual void slot5C();

    virtual void slot60();

    virtual void slot64();

    virtual void slot68();

    virtual void slot6C();

    virtual void slot70();

    virtual void slot74();

    virtual void slot78();

    virtual void slot7C();

    virtual void slot80();

    virtual void slot84();

    virtual void slot88();

    virtual void slot8C();

    virtual void slot90();

    virtual void slot94();

    virtual unsigned int Get98();

    virtual void Set9C(Object*);

    virtual void slotA0();

    virtual void slotA4();

    virtual void slotA8();

    virtual void slotAC();

    virtual void slotB0();

    virtual void slotB4();

    virtual void UpdateB8(UpdateData*);

    virtual void SetBC(bool);

    unsigned int unk04;

    Object* controller08;

    union { unsigned short flags0C; volatile unsigned short vflags; };
    unsigned short unk0E;

    Object* target10;

    unsigned int unk14,unk18;

    unsigned short unk1C;

    bool active1E;

};

struct State { Object* object00; unsigned int unk04,unk08,flags0C,unk10,count14,flag18; };


void __cdecl FUN_008d3f70(Object*,State*);

// pdb: bhkWorld::AddObject | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apCollision, arData
void __cdecl FUN_008d5820(Object* object,State* state) {

    Object* obj=*(Object* volatile*)&object;
    Object* target=obj->target10;

    if (target) {

    Object* property=obj->Get3C();

    if(property) {

        if(!state->count14) property->flags0C|=0x100;

        else property->flags0C&=~0x100;

    }

    bool flag1=*(volatile unsigned char*)&state->flags0C&1;
    if(flag1) obj->flags0C|=4;
    else obj->flags0C&=~4;
    if(flag1) obj->flags0C=(unsigned int)obj->flags0C|8;

    if(DAT_00f79454) FUN_008d3f70(target,state);

    unsigned int first=state->object00->Get98();
    if(target->Get98()!=first) {

        if(state->flag18) obj->flags0C|=0x40;

        else obj->flags0C&=~0x40;

        if(state->object00) state->object00->Get98();

        target->Set9C(state->object00);

        if(state->object00) state->object00->Get98();

    }

    UpdateData update;

    obj->controller08->UpdateB8(&update);

    if(state->object00->active1E) obj->SetBC(true);

    }

    state->flags0C&=~1u;

    ++state->count14;

}

}
}   // namespace f3m_008d5820

// @f3 0x008db720 (community match, verified in this file)
namespace f3m_008db720 {
class hkVector4 {
public:
    float m_quad[4];

    __forceinline float& operator()(int i) { return m_quad[i]; }
    __forceinline const float& operator()(int i) const { return m_quad[i]; }
    __forceinline void set(float a, float b, float c, float d) { m_quad[0] = a; m_quad[1] = b; m_quad[2] = c; m_quad[3] = d; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2) {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    __forceinline void addMul4(float r, const hkVector4& v) {
        m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1];
        m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3];
    }
    __forceinline void subMul4(float r, const hkVector4& v) {
        m_quad[0] -= r * v.m_quad[0]; m_quad[1] -= r * v.m_quad[1];
        m_quad[2] -= r * v.m_quad[2]; m_quad[3] -= r * v.m_quad[3];
    }
    __forceinline float dot4(const hkVector4& v) const {
        return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2] + m_quad[3] * v.m_quad[3];
    }
    void FUN_008db720(const hkVector4& first, const hkVector4& second);
};

// pdb: hkQuaternion::setInverseMul | hkbFootIkDriver.obj | tesv_win, call_gap, low
void hkVector4::FUN_008db720(const hkVector4& first, const hkVector4& second) {
    setCross(second, first);
    addMul4(first(3), second);
    subMul4(second(3), first);
    m_quad[3] = first.dot4(second);
}
}   // namespace f3m_008db720

// @f3 0x008d69e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008d69e0 {
extern "C" __declspec(dllimport) void* __stdcall DAT_00d9b080(unsigned long);
struct AllocT {
    void* FUN_008f6d30(unsigned int, int);
    void FUN_008f6d90(void*, unsigned int, int);
};
void __cdecl FUN_00901f10(struct HkArray*, int);
struct HkArray {
    void** buffer;
    int count;
    int capacity;
    HkArray() : buffer(0), count(0), capacity(0x80000000) {}
    ~HkArray();
    void push_back(void* value) {
        if (count == (capacity & 0x3fffffff))
            FUN_00901f10(this, 4);
        buffer[count++] = value;
    }
};
HkArray::~HkArray() {
    if ((capacity & 0x80000000) == 0) {
        int n = capacity & 0x3fffffff;
        AllocT* a = (AllocT*)DAT_00d9b080(DAT_010f3170);
        a->FUN_008f6d90(buffer, n * 4, 0x17);
    }
}
struct FUN_00954890 {
    void* vtable_00;
    unsigned short size_04;
    unsigned short unk06;
    void* field_08;
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
    FUN_00954890();
    static void* operator new(unsigned int size) { AllocT* a = (AllocT*)DAT_00d9b080(DAT_010f3170); FUN_00954890* p = (FUN_00954890*)a->FUN_008f6d30(size, 0x35); p->size_04 = (unsigned short)size; return p; }
    void FUN_00954790(void*);
};
struct FUN_00953a90 {
    virtual ~FUN_00953a90();
    unsigned short size_04;
    unsigned short unk06;
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
    FUN_00953a90(HkArray*, int);
    static void* operator new(unsigned int size) { AllocT* a = (AllocT*)DAT_00d9b080(DAT_010f3170); FUN_00953a90* p = (FUN_00953a90*)a->FUN_008f6d30(size, 0x35); p->size_04 = (unsigned short)size; return p; }
    void FUN_00952f70(int);
};
struct Ref69e0 {
    virtual ~Ref69e0();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3c();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4c();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5c();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6c();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7c();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8c();
    virtual void Slot90();
    virtual void Slot94();
    virtual void* GetWorld();
    int unk04;
    void* world_08;
    int unk0c;
};
struct World69e0 : Ref69e0 {
    void* debug_10;
    void* support_14;
    FUN_00953a90* visual_18;
    void FUN_009542b0();
    void FUN_008d69e0(bool);
};
// pdb: bhkWorld::SetVisualDebugger | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abTF
void World69e0::FUN_008d69e0(bool enable) {
    if (enable) {
        if (visual_18)
            return;
        HkArray array;
        FUN_009542b0();
        FUN_00954890* obj = new FUN_00954890;
        (void)GetWorld();
        obj->FUN_00954790(GetWorld());
        array.push_back(obj ? &obj->field_08 : 0);
        FUN_00953a90* dbg = new FUN_00953a90(&array, 0);
        visual_18 = dbg;
        (void)GetWorld();
        visual_18->FUN_00952f70(0x61a9);
    } else {
        if (this)
            (void)GetWorld();
        if (visual_18)
            delete visual_18;
        (void)GetWorld();
        visual_18 = 0;
    }
}
}   // namespace f3m_008d69e0

// @f3 0x008d6290 (community match, verified in this file)
#include <string.h>
namespace f3m_008d6290 {

extern void* (__stdcall* FUN_00d9b080)(unsigned long);

struct ListEntry;
struct WorldObj;

struct ThreadMem {
    void FUN_008f6d90(void* p, int bytes, int unk);
};

struct List {
    ListEntry** data;
    int size;
    int capFlags;
    List() : data(0), size(0), capFlags(0x80000000) {}
    WorldObj* AtWorld(int index);
    ~List();
};

struct WorldObj {
    void FUN_00907120(void* object);
};

struct ListEntry {
    virtual void Unk00(int flag);
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void GetWorlds(List* out);
    unsigned short flags;
    short refs;
    WorldObj* world;
};

WorldObj* List::AtWorld(int index) { return data[index]->world; }
List::~List()
{
    if (capFlags & 0x80000000)
        return;
    unsigned int n = capFlags & 0x3FFFFFFF;
    ThreadMem* mem = (ThreadMem*)FUN_00d9b080(DAT_010f3170);
    mem->FUN_008f6d90(data, n * 4, 0x17);
}

struct Owner {
    virtual void U00(); virtual void U01(); virtual void U02(); virtual void U03();
    virtual void U04(); virtual void U05(); virtual void U06(); virtual void U07();
    virtual void U08(); virtual void U09(); virtual void U10(); virtual void U11();
    virtual void U12(); virtual void U13(); virtual void U14(); virtual void U15();
    virtual void U16(); virtual void U17(); virtual void U18(); virtual void U19();
    virtual void U20(); virtual void U21(); virtual void U22(); virtual void U23();
    virtual void U24(); virtual void U25(); virtual void U26(); virtual void U27();
    virtual void U28(); virtual void U29(); virtual void U30(); virtual void U31();
    virtual void U32(); virtual void U33(); virtual void U34(); virtual void U35();
    virtual void U36(); virtual void U37();
    virtual WorldObj* GetWorld();
    unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    unsigned int unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;
    ListEntry** array;
    unsigned int count;
    void FUN_008d6290();
};

// pdb: bhkWorld::AddBatchedActions | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void Owner::FUN_008d6290()
{
    if (this->count <= 0)
        return;
    if (this->count >= 0x64)
        this->count = 0x64;
    WorldObj* world = GetWorld();
    if (!world)
        return;
    for (unsigned int i = 0; i < this->count; ++i) {
        if (this->array[i] && this->array[i]->world == 0) {
            List list;
            this->array[i]->GetWorlds(&list);
            bool same = true;
            for (int j = 0; j < list.size; ++j) {
                if (!same) break;
                same = (list.AtWorld(j) == world);
            }
            if (same)
                world->FUN_00907120(this->array[i]);
        }
        if (this->array[i] && this->array[i]->flags) {
            ListEntry* entry = this->array[i];
            if (--entry->refs == 0)
                entry->Unk00(1);
        }
    }
    memset(this->array, 0, this->count * 4);
    this->count = 0;
}




}   // namespace f3m_008d6290

// @f3 0x008d36d0 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e31f80;
extern const char DAT_00e32104[];
extern const char DAT_00e32118[];
extern const char DAT_00e3212c[];
extern const char DAT_00e32140[];
namespace f3m_008d36d0 {
struct D871A0Array;
struct D871A0Buffer {
    void* unk00;
    int unk04;
    D871A0Buffer& FUN_00d871a0(const D871A0Array& arr, int name);
};
struct StringMemberAccessor : D871A0Buffer {
    int* FUN_00d87230(int index);
};
static __forceinline void StoreKneeAngle(StringMemberAccessor& destination, float radians)
{
    float* angle = reinterpret_cast<float*>(destination.FUN_00d87230(0));
    *angle = radians * DAT_00e31f80;
}

void __cdecl FUN_008d36d0(const D871A0Array& a, const D871A0Array& b)
{
    StringMemberAccessor acc[2];
    acc[0].FUN_00d871a0(a, reinterpret_cast<int>(DAT_00e32140));
    acc[1].FUN_00d871a0(b, reinterpret_cast<int>(DAT_00e3212c));
    float v = *(float*)acc[0].FUN_00d87230(0);
    float av = fabsf(v);
    float r;
    if (av >= 1.0f)
        *static_cast<volatile float*>(&r) = (v > 0.0f) ? 0.0f : 3.14159265f;
    else
        r = acosf(v);
    StoreKneeAngle(acc[1], r);
    acc[1].FUN_00d871a0(a, reinterpret_cast<int>(DAT_00e32118));
    acc[0].FUN_00d871a0(b, reinterpret_cast<int>(DAT_00e32104));
    float w = *(float*)acc[1].FUN_00d87230(0);
    float aw = fabsf(w);
    float r2;
    if (aw >= 1.0f)
        *static_cast<volatile float*>(&r2) = (w > 0.0f) ? 0.0f : 3.14159265f;
    else
        r2 = acosf(w);
    StoreKneeAngle(acc[0], r2);
}


}   // namespace f3m_008d36d0

// @f3 0x008db610 (community match, verified in this file)
namespace f3m_008db610 {
namespace quaternion_inverse_product {
struct Scalar {float value;__forceinline Scalar(float v):value(v){}__forceinline float GetReal()const{return value;}};
struct __declspec(align(16)) Vector4 {
 float x,y,z,w;
 __forceinline Scalar GetW()const{return Scalar(w);}
 __forceinline void SetCross(const Vector4& a,const Vector4& b){x=a.y*b.z-a.z*b.y;y=a.z*b.x-a.x*b.z;z=a.x*b.y-a.y*b.x;w=0.0f;}
 __forceinline void SubMul4(Scalar scale,const Vector4& v){const float s=scale.GetReal();x-=v.x*s;y-=v.y*s;z-=v.z*s;w-=v.w*s;}
 __forceinline void AddMul4(Scalar scale,const Vector4& v){const float s=scale.GetReal();x+=v.x*s;y+=v.y*s;z+=v.z*s;w+=v.w*s;}
 __forceinline Vector4& operator=(const Vector4& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 __forceinline float Dot4(const Vector4& v)const{return x*v.x+y*v.y+z*v.z+w*v.w;}
 void FUN_008db610(const Vector4& a,const Vector4& b);
};
// pdb: hkQuaternion::getAngle | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkQuaternion::setMulInverse)
void Vector4::FUN_008db610(const Vector4& a,const Vector4& b){Vector4 temporary;temporary.SetCross(b,a);temporary.SubMul4(a.GetW(),b);temporary.AddMul4(b.GetW(),a);*this=temporary;w=a.Dot4(b);}
}
}   // namespace f3m_008db610

// @f3 0x008d9060 (community match, verified in this file)
namespace f3m_008d9060 {
namespace aligned_scaled_vector {
struct Input {float x,y,z;};
struct __declspec(align(16)) AlignedVector {float x,y,z,w;};
struct Receiver {void FUN_008d6ba0(const AlignedVector*);void FUN_008d9060(const Input*);};
// pdb: bhkWorld::SetOrigin | bhkWorld.obj | fnv360_0822_retail, call_gap, low
// pdb params: arOrigin
void Receiver::FUN_008d9060(const Input* input){AlignedVector value;value.x=(float)(input->x*0.1428767293691635);value.y=(float)(input->y*0.1428767293691635);value.z=(float)(input->z*0.1428767293691635);FUN_008d6ba0(&value);}
}
}   // namespace f3m_008d9060

// @f3 0x008d6d50 (community match, verified in this file)
extern bool DAT_010f2a63;
extern unsigned char DAT_010f2a88;
extern float DAT_00f79474, DAT_00f79470, DAT_010f2a84;
extern unsigned long DAT_0116913c;
extern char str_00e3279c[], str_00e32798[];
extern int DAT_00e320fc, DAT_00e320e4;
namespace f3m_008d6d50 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct Result;
union Scratch
{
    float threshold;
    Result* result;
    volatile unsigned int stamp;
};
struct TraceBool
{
    char value;
    TraceBool(bool b)
    {
        value = (char)b;
    }
    operator bool() const
    {
        return value != 0;
    }
};
struct TraceEntry
{
    const char* tag;
    unsigned int time;
    unsigned int extra;
    void SetTime()
    {
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        time = stamp;
    }
};
struct TraceBuffer
{
    int unk00;
    TraceEntry* current;
    int unk08;
    TraceEntry* end;
    static TraceBuffer& GetInstance()
    {
        return *(TraceBuffer*)TlsGetValue(DAT_0116913c);
    }
    TraceBool MemoryAvailable() const
    {
        return current < end;
    }
    TraceEntry* Expand()
    {
        TraceEntry* e = current;
        return e;
    }
};
inline void TraceBegin(const char* tag, Scratch& scratch)
{
    TraceBuffer& stream = TraceBuffer::GetInstance();
    if (stream.MemoryAvailable())
    {
        TraceEntry* e = stream.Expand();
        e->tag = tag;
        _ReadWriteBarrier();
        scratch.stamp = (unsigned int)__rdtsc();
        e->time = scratch.stamp;
        stream.current = e + 1;
    }
}
inline void TraceEnd(const char* tag, Scratch& scratch)
{
    TraceBuffer& stream = TraceBuffer::GetInstance();
    if (stream.MemoryAvailable())
    {
        TraceEntry* e = stream.Expand();
        e->tag = tag;
        _ReadWriteBarrier();
        scratch.stamp = (unsigned int)__rdtsc();
        e->time = scratch.stamp;
        stream.current = e + 1;
    }
}
struct Result
{
    int field00;
    int field04;
    int field08;
    int field0c;
    float field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    void Clear()
    {
        field10 = 1.0f;
        field50 = 0;
        field14 = -1;
        field40 = 0;
        field20 = -1;
    }
    void FUN_007c8a50(Result*);
    void FUN_007cb010(Result*) throw();
};
struct Collector
{
    int field00;
    float fraction;
    int field08, field0c;
    Result result;
    void Finalize();
};
struct Query
{
    float startX;
    float startY;
    float startZ;
    float startW;
    float endX;
    float endY;
    float endZ;
    float endW;
    int field20;
    int field24;
    int field28;
    int field2c;
    Result result;
    int field84;
    int field88;
    int field8c;
    float deltaX;
    float deltaY;
    float deltaZ;
    float deltaW;
    void* filter;
    Collector* collector;
    struct HitResultList* hits;
    bool disabled;
    bool FUN_00432d10();
    void FUN_00458840() {
        if (FUN_00432d10()) {
            endX = deltaX + startX; endY = deltaY + startY;
            endZ = deltaZ + startZ; endW = deltaW + startW;
        }
    }
};
struct HitResultList
{
    int field00, field04, field08, field0c;
    Result* result;
    int count;
    void FUN_008f7110();
};
struct World
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    void FUN_00902510(Query*, void*);
    void FUN_00903250(Query*, Result*);
};
struct __declspec(align(16)) CastVector
{
    float x, y, z, w;
};
struct CastCollectorBase
{
    int* vtable;
    ~CastCollectorBase()
    {
        vtable = &DAT_00e320e4;
    }
};
struct __declspec(align(16)) WorldRayCaster : CastCollectorBase
{
    int field04;
    int field08;
    int field0c;
    CastVector from;
    CastVector to;
    CastVector direction;
    int field40;
    int field44;
    WorldRayCaster()
    {
        vtable = &DAT_00e320fc;
        field40 = 0;
        field44 = 0;
    }
    void FUN_00942be0(int, Query*, int, void*, void*);
};
// Trivial, identically aligned storage for the non-owning cast object.
struct __declspec(align(16)) CastStorage {
    int* vtable;
    int field04, field08, field0c;
    CastVector from, to, direction;
    int field40, field44;
};
struct FilterCast : WorldRayCaster
{
    __forceinline FilterCast(World* world, Query* query, void* cache, void* collector)
    {
        int mode = world->field70;
        FUN_00942be0(world->field54, query, mode, cache, collector);
    }
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct RayCaster
{
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual World* GetWorld();
    bool bhkWorld_PickObject(Query* query);
};
// @fnv 0x008d6d50
// pdb: bhkWorld::PickObject | bhkWorld.obj | fnv360_0822_retail, ustr + bridge(vtable|ustr) + skyrim(ustr), high
bool RayCaster::bhkWorld_PickObject(Query* query)
{
    CastStorage storage;
    Scratch scratch;
    if (!DAT_010f2a63)
    {
        scratch.threshold = DAT_010f2a88 ? DAT_00f79474 : DAT_00f79470;
        if (DAT_010f2a84 > scratch.threshold)
        {
            query->disabled = true;
            query->result.Clear();
            return false;
        }
    }
    TraceBegin(str_00e3279c, scratch);
    GetTickCount();
    bool found = false;
    World* world = GetWorld();
    if (world)
    {
        query->FUN_00458840();
        scratch.result = &query->result;
        scratch.result->Clear();
        HitResultList* hits = query->hits;
        if (hits)
        {
            void* cache = query->filter;
            if (cache)
            {
                ((FilterCast*)&storage)->FilterCast::FilterCast(world, query, cache, hits);
            }
            else
                world->FUN_00902510(query, hits);
            if (hits->count)
            {
                hits->FUN_008f7110();
                Result* hit = hits->result;
                scratch.result->FUN_007c8a50(hit);
                scratch.result->field50 = hit->field50;
                found = true;
            }
        }
        else
        {
            Collector* collector = query->collector;
            if (collector)
            {
                Result* collected = &collector->result;
                collected->Clear();
                collector->fraction = 1.0f;
                void* cache = query->filter;
                if (cache)
                {
                    ((FilterCast*)&storage)->FilterCast::FilterCast(world, query, cache, collector);
                }
                else
                    world->FUN_00902510(query, collector);
                if (collector->result.field50)
                {
                    scratch.result->FUN_007cb010(collected);
                    found = true;
                }
            }
            else
            {
                world->FUN_00903250(query, scratch.result);
                found = query->result.field50 != 0;
            }
        }
    }
    GetTickCount();
    TraceEnd(str_00e32798, scratch);
    return found;
}

}   // namespace f3m_008d6d50

// @f3 0x008d4180 (community match, verified in this file)
namespace f3m_008d4180 {



extern __declspec(thread) int g_threadMode;

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
};
extern hkVector4 DAT_01092a50;

struct S_Motion
{
    void FUN_0090b500();
};

struct S_Body
{
    int unk00;
    int unk04;
    S_Motion* m_8;
    int unk0c;
    unsigned int m_10;
};

struct S_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short m_20;
};

struct hkpEntity
{
    int unk00;
    int unk04;
    int unk08;
    S_Body* m_c;
    void removeReference();
};

struct hkBoolRet
{
    char m_bool;
};

struct S_Mgr
{
    void FUN_00c94bd0(void** items, int count, int flag);
    hkBoolRet ProcessTarget(hkpEntity* entity);
};
void __cdecl PropagateStateToChildren(S_Mgr* mgr, S_Shape* shape);

struct S_ModeGuard
{
    int m_saved;
    S_ModeGuard()
    {
        m_saved = g_threadMode;
        g_threadMode = 0x10;
    }
    ~S_ModeGuard()
    {
        g_threadMode = m_saved;
    }
};

static __forceinline float AbsF(float r)
{
    return (float)fabs(r);
}

static __forceinline bool AllNear3(const hkVector4& a, const hkVector4& b, const hkVector4& eps)
{
    hkVector4 d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    d.x = AbsF(d.x);
    d.y = AbsF(d.y);
    d.z = AbsF(d.z);
    d.w = AbsF(d.w);
    int mask = ((d.x <= eps.x) ? 8 : 0) | ((d.y <= eps.y) ? 4 : 0) | ((d.z <= eps.z) ? 2 : 0) | ((d.w <= eps.w) ? 1 : 0);
    return (mask & 0xe) == 0xe;
}

struct S_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual S_Mgr* GetMgr();

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
    hkpEntity** m_pending;
    unsigned int m_pendingCount;

    void FUN_008d4180();
};

struct S_MotionData
{
    char pad[0x1a0];
    hkVector4 m_linVel;
    hkVector4 m_angVel;
};

static inline const hkVector4& GetLinVel(S_Body* b)
{
    if (b && b->m_8)
        return ((S_MotionData*)b->m_8)->m_linVel;
    return DAT_01092a50;
}

static inline const hkVector4& GetAngVel(S_Body* b)
{
    if (b && b->m_8)
        return ((S_MotionData*)b->m_8)->m_angVel;
    return DAT_01092a50;
}

static inline S_Shape* GetShape(hkpEntity* e)
{
    return *(S_Shape**)((char*)e + 0xb8);
}

static __forceinline S_Body* GetBodyRef(hkpEntity* const& e) { return e ? e->m_c : 0; }
void S_Owner::FUN_008d4180()
{
    S_ModeGuard guard;
    if (m_pendingCount > 0)
    {
        if (m_pendingCount >= 3000)
            m_pendingCount = 3000;
        S_Mgr* mgr = GetMgr();
        if (mgr)
        {
            mgr->FUN_00c94bd0((void**)m_pending, m_pendingCount, 0);
            bool bShapeUpdated = false;
            for (unsigned int i = 0; i < m_pendingCount; i++)
            {
                hkVector4 eps;
                eps.x = eps.y = eps.z = eps.w = 0.001f;
                S_Body* body = GetBodyRef(m_pending[i]);
                if (body)
                    body->m_10 &= ~0x10;
                else
                    mgr->ProcessTarget(m_pending[i]);
                if (!bShapeUpdated)
                {
                    S_Shape* s = GetShape(m_pending[i]);
                    if (s && s->m_20 != 0xffff)
                    {
                        PropagateStateToChildren(mgr, s);
                        bShapeUpdated = true;
                    }
                }
                if (!AllNear3(GetLinVel(body), DAT_01092a50, eps) || !AllNear3(GetAngVel(body), DAT_01092a50, eps))
                {
                    if (body && body->m_8)
                        body->m_8->FUN_0090b500();
                }
                m_pending[i]->removeReference();
            }
            memset(m_pending, 0, m_pendingCount * sizeof(hkpEntity*));
            m_pendingCount = 0;
        }
    }
}
}   // namespace f3m_008d4180

// @f3 0x008d8370 (community match, verified in this file)
namespace f3m_008d8370 {



struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
};
extern hkVector4 DAT_01092a50;
extern unsigned char DAT_00f7a266;
extern unsigned char DAT_010f2a62;
extern unsigned int DAT_00f7947c;

struct S_Motion
{
    void FUN_0090b500();
};

struct S_MotionData
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
    int unk110;
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
    int unk194;
    int unk198;
    int unk19c;
    hkVector4 m_linVel;
    hkVector4 m_angVel;
};

struct S_QualityRet
{
    unsigned int m_bits;
};

struct S_Body
{
    int unk00;
    int unk04;
    S_Motion* m_8;
    int unk0c;
    unsigned int m_10;
    S_QualityRet FUN_00424270();
    const hkVector4* FUN_004e6140();
    const hkVector4* FUN_004e61f0();
};

struct S_Phantom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned char m_14;
};

struct S_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short m_20;
};

struct hkpEntity
{
    int unk00;
    int unk04;
    int unk08;
    S_Body* m_c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned char m_type;
    void RetainReference();
    void removeReference();
};

struct hkBoolRet
{
    char m_bool;
};

struct S_Mgr
{
    void FUN_009027a0(hkpEntity* entity, int active);
    void FUN_00903980(hkpEntity* entity);
    void hkpWorld_addEntityBatch(void** items, int count, int flag);
    hkBoolRet ProcessTarget(hkpEntity* entity);
};
void __cdecl PropagateStateToChildren(S_Mgr* mgr, S_Shape* shape);

static __forceinline float AbsF(float r)
{
    return (float)fabs(r);
}

static __forceinline bool AllNear3(const hkVector4& a, const hkVector4& b, const hkVector4& eps)
{
    hkVector4 d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    d.x = AbsF(d.x);
    d.y = AbsF(d.y);
    d.z = AbsF(d.z);
    d.w = AbsF(d.w);
    int mask = ((d.x <= eps.x) ? 8 : 0) | ((d.y <= eps.y) ? 4 : 0) | ((d.z <= eps.z) ? 2 : 0) | ((d.w <= eps.w) ? 1 : 0);
    return (mask & 0xe) == 0xe;
}

static inline const hkVector4& GetLinVel(S_Body* b)
{
    if (b && b->m_8)
        return ((S_MotionData*)b->m_8)->m_linVel;
    return DAT_01092a50;
}

static inline const hkVector4& GetAngVel(S_Body* b)
{
    if (b && b->m_8)
        return ((S_MotionData*)b->m_8)->m_angVel;
    return DAT_01092a50;
}

static inline S_Shape* GetShape(hkpEntity* e)
{
    return *(S_Shape**)((char*)e + 0xb8);
}

static __forceinline S_Body* GetBodyRef(hkpEntity* const& e) { return e ? e->m_c : 0; }

struct S_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual S_Mgr* GetMgr();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_deferred;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    hkpEntity** m_pending;
    unsigned int m_pendingCount;
    hkpEntity** m_phantoms;
    unsigned int m_phantomCount;

    void FUN_008d4540(int a, int b);
    void FUN_008d5db0();
    void FUN_008d6290();
    void FUN_008d48d0();
    void FUN_008d8370(hkpEntity* entity);
};

// pdb: bhkWorld::Add | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject
void S_Owner::FUN_008d8370(hkpEntity* entity)
{
    S_Phantom* phantom = 0;
    if (!this)
        return;
    S_Mgr* mgr = GetMgr();
    if (!mgr)
        return;
    if (entity->m_type == 1)
    {
        if (m_deferred > 0)
        {
            S_Body* body = entity->m_c;
            if (!body || (body->m_10 & 0x30))
                return;
            if (m_pendingCount >= 3000)
            {
                FUN_008d4540(0, 1);
                FUN_008d5db0();
                FUN_008d6290();
                FUN_008d48d0();
            }
            body->m_10 |= 0x10;
            entity->RetainReference();
            m_pending[m_pendingCount++] = entity;
        }
        else
        {
            S_Body* body = entity->m_c;
            if (!body || (body->m_10 & 0x30))
                return;
            int active = 1;
            if (DAT_00f7a266)
            {
                if ((body->FUN_00424270().m_bits & 0x7f) != 8)
                {
                    hkVector4 eps;
                    eps.x = eps.y = eps.z = eps.w = 0.001f;
                    if (AllNear3(*body->FUN_004e6140(), DAT_01092a50, eps))
                    {
                        if (AllNear3(*body->FUN_004e61f0(), DAT_01092a50, eps))
                            active = 0;
                    }
                }
            }
            mgr->FUN_009027a0(entity, active);
        }
    }
    else
    {
        if (m_deferred > 0)
        {
            phantom = (S_Phantom*)entity->m_c;
            if (!phantom || (phantom->m_14 & 0x30))
                return;
            if (m_phantomCount >= 200)
            {
                if (m_pendingCount > 0 && !DAT_010f2a62)
                {
                    if (m_pendingCount >= 3000)
                        m_pendingCount = 3000;
                    unsigned int count = m_pendingCount;
                    unsigned int removeCount;
                    if (count < DAT_00f7947c)
                        removeCount = count;
                    else
                        removeCount = DAT_00f7947c;
                    unsigned int remaining = count - removeCount;
                    S_Mgr* m = GetMgr();
                    if (m)
                    {
                        m->hkpWorld_addEntityBatch((void**)(m_pending + remaining), removeCount, 0);
                        bool bShapeUpdated = false;
                        for (unsigned int i = remaining; i < m_pendingCount; i++)
                        {
                            hkVector4 eps;
                            eps.x = eps.y = eps.z = eps.w = 0.001f;
                            S_Body* body = GetBodyRef(m_pending[i]);
                            if (body)
                                body->m_10 &= ~0x10;
                            else
                                m->ProcessTarget(m_pending[i]);
                            if (!bShapeUpdated)
                            {
                                S_Shape* s = GetShape(m_pending[i]);
                                if (s && s->m_20 != 0xffff)
                                {
                                    PropagateStateToChildren(m, s);
                                    bShapeUpdated = true;
                                }
                            }
                            if (!AllNear3(GetLinVel(body), DAT_01092a50, eps) || !AllNear3(GetAngVel(body), DAT_01092a50, eps))
                            {
                                if (body && body->m_8)
                                    body->m_8->FUN_0090b500();
                            }
                            m_pending[i]->removeReference();
                        }
                        memset(m_pending + remaining, 0, removeCount * sizeof(hkpEntity*));
                        m_pendingCount = remaining;
                    }
                    DAT_010f2a62 = 1;
                }
                FUN_008d5db0();
                FUN_008d6290();
                FUN_008d48d0();
            }
            phantom->m_14 |= 0x10;
            entity->RetainReference();
            m_phantoms[m_phantomCount++] = entity;
        }
        else
        {
            phantom = (S_Phantom*)entity->m_c;
            if (!phantom || (phantom->m_14 & 0x30))
                return;
            mgr->FUN_00903980(entity);
        }
    }
}
}   // namespace f3m_008d8370

// @f3 0x008d2480 (community match, verified in this file)
namespace f3m_008d2480 {


struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
};
extern hkVector4 DAT_01092a50;

struct S2480_RigidBody
{
    int unk00;
    int unk04;
    char* m_8;
    void FUN_004e6280(const hkVector4& v);
    void FUN_004e62c0(const hkVector4& v);
};

static __forceinline float AbsF(float r)
{
    return (float)fabs(r);
}

static __forceinline bool AllNear3(const hkVector4& a, const hkVector4& b, const hkVector4& eps)
{
    hkVector4 d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    d.x = AbsF(d.x);
    d.y = AbsF(d.y);
    d.z = AbsF(d.z);
    d.w = AbsF(d.w);
    int mask = ((d.x <= eps.x) ? 8 : 0) | ((d.y <= eps.y) ? 4 : 0) | ((d.z <= eps.z) ? 2 : 0) | ((d.w <= eps.w) ? 1 : 0);
    return (mask & 0xe) == 0xe;
}

static inline const hkVector4& GetLinVel(S2480_RigidBody* b)
{
    if (b && b->m_8)
        return *(hkVector4*)(b->m_8 + 0x1a0);
    return DAT_01092a50;
}

static inline const hkVector4& GetAngVel(S2480_RigidBody* b)
{
    if (b && b->m_8)
        return *(hkVector4*)(b->m_8 + 0x1b0);
    return DAT_01092a50;
}

struct S2480_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S2480_RigidBody* m_body;
    void FUN_008d2480();
};

void S2480_Owner::FUN_008d2480()
{
    S2480_RigidBody* body = m_body;
    if (body)
    {
        hkVector4 eps;
        eps.x = eps.y = eps.z = eps.w = 0.001f;
        if (!AllNear3(GetLinVel(body), DAT_01092a50, eps))
            body->FUN_004e6280(DAT_01092a50);
        if (!AllNear3(GetAngVel(body), DAT_01092a50, eps))
            body->FUN_004e62c0(DAT_01092a50);
    }
}
}   // namespace f3m_008d2480

// @f3 0x008d3810 (community match, verified in this file)
extern const char DAT_00e32154[], DAT_00e31f48[];
extern const char DAT_00e31f34[], DAT_00e31f18[];
namespace f3m_008d3810 {
namespace NativeFootIk3810 {
struct ObjectData {
    void* object;
    const void* type;
};
struct NestedValue { void* FUN_0093d890(); };
struct MemberValue {
    void* data;
    const void* metadata;
    void FUN_0093d600(const ObjectData*, const char*);
    NestedValue* FUN_0093d790();
    void* FUN_0093d660();
    float* FUN_0093d6a0(int);
};
typedef void (__cdecl *LegConverter)(const ObjectData*, const ObjectData*, void*);
void __cdecl FUN_008d36d0(const ObjectData*, const ObjectData*, void*);
void __cdecl FUN_00943340(MemberValue*, MemberValue*, LegConverter, void*);

void __cdecl FUN_008d3810(const ObjectData* oldData, const ObjectData* newData, void* context)
{
    struct ObjectPair { ObjectData oldObject, newObject; };
    struct MemberPair { MemberValue oldMember, newMember; };
    struct __declspec(align(8)) ConversionFrame {
        MemberPair gains;
        union {
            MemberPair legs;
            ObjectPair objects;
        } reusable;
        MemberPair scalarGains;
    } frame;
    frame.reusable.legs.oldMember.FUN_0093d600(oldData, DAT_00e32154);
    frame.reusable.legs.newMember.FUN_0093d600(newData, DAT_00e32154);
    FUN_00943340(&frame.reusable.legs.oldMember, &frame.reusable.legs.newMember, FUN_008d36d0, context);

    frame.gains.oldMember.FUN_0093d600(oldData, DAT_00e31f48);
    frame.gains.newMember.FUN_0093d600(newData, DAT_00e31f48);
    frame.reusable.objects.oldObject.type = frame.gains.oldMember.FUN_0093d790()->FUN_0093d890();
    frame.reusable.objects.oldObject.object = frame.gains.oldMember.FUN_0093d660();
    frame.reusable.objects.newObject.type = frame.gains.newMember.FUN_0093d790()->FUN_0093d890();
    frame.reusable.objects.newObject.object = frame.gains.newMember.FUN_0093d660();

    frame.scalarGains.oldMember.FUN_0093d600(&frame.reusable.objects.oldObject, DAT_00e31f34);
    frame.scalarGains.newMember.FUN_0093d600(&frame.reusable.objects.newObject, DAT_00e31f18);
    const float* previousGain = frame.scalarGains.oldMember.FUN_0093d6a0(0);
    *frame.scalarGains.newMember.FUN_0093d6a0(0) = *previousGain;
}
}
}   // namespace f3m_008d3810

// @f3 0x008d4e10 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_008d4e10 {


struct ThreadHeap
{
    void FUN_008f6d90(void* block, unsigned int size, int pool);
};

struct FUN_00904690_Base
{
    virtual ~FUN_00904690_Base();
    unsigned short m_size;
};

struct FUN_008d4e10 : FUN_00904690_Base
{
    virtual ~FUN_008d4e10();

    // pdb: ahkpWorld::`scalar deleting destructor' | bhkWorld.obj | fnv360_0822_retail, caller_sim, low
    static void operator delete(void* p)
    {
        ThreadHeap* heap = (ThreadHeap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(p, ((FUN_008d4e10*)p)->m_size, 0x2f);
    }
};

FUN_008d4e10::~FUN_008d4e10()
{
}
}   // namespace f3m_008d4e10

// @f3 0x008dccb0 (community match, verified in this file)
#include <math.h>
extern const double DAT_00db88e8;
namespace f3m_008dccb0 {
namespace f3m_008dccb0 {

// Object at this+0x58: its float at +0x98 divides the record translations.
struct World466 {
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
    float f98;   // +0x98
};

// this+0x2a4 (Step466) -> +0xc (Chain466) holds the record count at +0x10.
struct Chain466 {
    unsigned int unk00, unk04, unk08, unk0c;
    int count;   // +0x10
};
struct Step466 {
    unsigned int unk00, unk04, unk08;
    Chain466* chain;   // +0x0c
};

// 0x30-byte transform record walked at this+0x94 (hkQsTransform shape).
struct Rec466 {
    float tx, ty, tz, tw;
    float qx, qy, qz, qw;
    float sx, sy, sz, sw;
};

// Gamebryo quaternion {w,x,y,z}; converts itself into a 3x3 matrix.
struct Quat466 {
    float w, x, y, z;
    __declspec(noalias) void NiQuaternion_ToRotation(ThreeByThreeMatrix* out);
};

struct Pose466 {
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
    World466* world;        // +0x58
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
    char* recs;            // +0x94
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    NiAVObjectStub** nodes;  // +0xa4
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
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    Step466* link;         // +0x2a4
    void FUN_008dccb0();
};

void Pose466::FUN_008dccb0()
{
    int count = link->chain->count;
    float invScale = 1.0f / world->f98;
    if (count > 0) {
        int offset = 0;
        for (int i = 0; i < count; i++) {
            Rec466* rec = (Rec466*)(recs + offset);
            Quat466 q; float* wp = &q.w;
            NiAVObjectStub** nodeTable = nodes;
            double x = rec->qx;
            NiAVObjectStub* node = nodeTable[i];
            q.x = (float)x;
            q.y = rec->qy;
            q.z = rec->qz;
            *wp = rec->qw;
            float invLen = 1.0f / sqrtf((*wp)*(*wp) + q.x*q.x + q.y*q.y + q.z*q.z);
            *wp *= invLen;
            q.x *= invLen;
            q.y *= invLen;
            q.z *= invLen;
            NiTransform lt;
            q.NiQuaternion_ToRotation(&lt.m_kOrientation);
            NiTransform* __restrict dst = &node->m_kLocalTransform;
            lt.m_kTranslation.x = rec->tx * DAT_00db88e8;
            lt.m_kTranslation.y = rec->ty * DAT_00db88e8;
            lt.m_kTranslation.z = rec->tz * DAT_00db88e8;
            lt.m_kTranslation.x *= invScale;
            lt.m_kTranslation.y *= invScale;
            lt.m_kTranslation.z *= invScale;
            dst->m_kTranslation = lt.m_kTranslation;
            dst->m_kOrientation = lt.m_kOrientation;
            offset += 0x30;
        }
    }
}









}







}   // namespace f3m_008dccb0

// @f3 0x008d2ca0 (community match, verified in this file)
namespace f3m_008d2ca0 {
typedef float hkReal;

class __declspec(align(16)) S008d2ca0_hkVector4
{
public:
    hkReal m_quad[4];

    S008d2ca0_hkVector4() {}
    S008d2ca0_hkVector4(const S008d2ca0_hkVector4& v)
    {
        m_quad[0] = v.m_quad[0]; m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2]; m_quad[3] = v.m_quad[3];
    }

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        m_quad[0] = a; m_quad[1] = b; m_quad[2] = c; m_quad[3] = d;
    }
    void sub4(const S008d2ca0_hkVector4& a)
    {
        m_quad[0] -= a.m_quad[0]; m_quad[1] -= a.m_quad[1];
        m_quad[2] -= a.m_quad[2]; m_quad[3] -= a.m_quad[3];
    }
    void mul4(const S008d2ca0_hkVector4& a)
    {
        m_quad[0] *= a.m_quad[0]; m_quad[1] *= a.m_quad[1];
        m_quad[2] *= a.m_quad[2]; m_quad[3] *= a.m_quad[3];
    }
    void setMul4(hkReal r, const S008d2ca0_hkVector4& a)
    {
        m_quad[0] = r * a.m_quad[0]; m_quad[1] = r * a.m_quad[1];
        m_quad[2] = r * a.m_quad[2]; m_quad[3] = r * a.m_quad[3];
    }
    void addMul4(hkReal r, const S008d2ca0_hkVector4& a)
    {
        m_quad[0] += r * a.m_quad[0]; m_quad[1] += r * a.m_quad[1];
        m_quad[2] += r * a.m_quad[2]; m_quad[3] += r * a.m_quad[3];
    }
    void setAdd4(const S008d2ca0_hkVector4& a, const S008d2ca0_hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] + b.m_quad[0]; m_quad[1] = a.m_quad[1] + b.m_quad[1];
        m_quad[2] = a.m_quad[2] + b.m_quad[2]; m_quad[3] = a.m_quad[3] + b.m_quad[3];
    }
    void setCross(const S008d2ca0_hkVector4& v1, const S008d2ca0_hkVector4& v2)
    {
        const hkReal nx = v1.m_quad[1] * v2.m_quad[2] - v1.m_quad[2] * v2.m_quad[1];
        const hkReal ny = v1.m_quad[2] * v2.m_quad[0] - v1.m_quad[0] * v2.m_quad[2];
        const hkReal nz = v1.m_quad[0] * v2.m_quad[1] - v1.m_quad[1] * v2.m_quad[0];
        set(nx, ny, nz, 0.0f);
    }
    hkReal dot3(const S008d2ca0_hkVector4& a) const
    {
        return m_quad[0] * a.m_quad[0] + m_quad[1] * a.m_quad[1] + m_quad[2] * a.m_quad[2];
    }

    void setRotatedInverseDir(const struct S008d2ca0_hkQuaternion& quat, const S008d2ca0_hkVector4& direction);
    void FUN_008d2ca0(const struct S008d2ca0_hkQsTransform& a, const S008d2ca0_hkVector4& b);
};

struct S008d2ca0_hkQuaternion
{
    S008d2ca0_hkVector4 m_vec;
    const S008d2ca0_hkVector4& getImag() const { return m_vec; }
    hkReal getReal() const { return m_vec(3); }
};

struct S008d2ca0_hkQsTransform
{
    S008d2ca0_hkVector4 m_translation;
    S008d2ca0_hkQuaternion m_rotation;
    S008d2ca0_hkVector4 m_scale;
};

__forceinline void S008d2ca0_hkVector4::setRotatedInverseDir(const S008d2ca0_hkQuaternion& quat, const S008d2ca0_hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5;

    S008d2ca0_hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    S008d2ca0_hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);

    setAdd4(ret, ret);
}

void S008d2ca0_hkVector4::FUN_008d2ca0(const S008d2ca0_hkQsTransform& a, const S008d2ca0_hkVector4& b)
{
    S008d2ca0_hkVector4 temp = b;
    temp.sub4(a.m_translation);
    setRotatedInverseDir(a.m_rotation, temp);
    S008d2ca0_hkVector4 invScale;
    invScale.set(1.0f / a.m_scale(0), 1.0f / a.m_scale(1), 1.0f / a.m_scale(2), 0.0f);
    mul4(invScale);
}
}   // namespace f3m_008d2ca0

// @f3 0x008d7d80 (community match, verified in this file)
namespace f3m_008d7d80 {


namespace S8d7d80_ns {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}
extern unsigned long DAT_010f3170;

struct S8d7d80_ThreadMemory
{
    void* FUN_008f6d30(int nbytes, int memClass);
    void FUN_008f6d90(void* p, int nbytes, int memClass);
    static S8d7d80_ThreadMemory& getInstance() throw();
};
__forceinline S8d7d80_ThreadMemory& S8d7d80_ThreadMemory::getInstance() throw()
{
    return *(S8d7d80_ThreadMemory*)S8d7d80_ns::FUN_00d9b080(DAT_010f3170);
}

template <class T> struct S8d7d80_Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline S8d7d80_Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline S8d7d80_Array(const S8d7d80_Array& a) : m_data(0), m_size(0), m_capacityAndFlags(0x80000000)
    {
        *this = a;
    }
    __forceinline int getCapacity() const throw()
    {
        return m_capacityAndFlags & 0x3fffffff;
    }
    __forceinline S8d7d80_Array& operator=(const S8d7d80_Array& a)
    {
        if (a.m_size > getCapacity())
        {
            if ((m_capacityAndFlags & 0x80000000) == 0)
            {
                S8d7d80_ThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
            }
            m_data = (T*)S8d7d80_ThreadMemory::getInstance().FUN_008f6d30(a.m_size * sizeof(T), 0x17);
            m_capacityAndFlags = a.m_size;
        }
        m_size = a.m_size;
        copy(m_data, a.m_data, m_size);
        return *this;
    }
    static __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            dst[i] = src[i];
        }
    }
    __forceinline ~S8d7d80_Array()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            S8d7d80_ThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }
};

struct __declspec(align(16)) S8d7d80_Vector4
{
    float x;
    float y;
    float z;
    float w;
    __forceinline void setSub4(const S8d7d80_Vector4& a, const S8d7d80_Vector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setAbs4(const S8d7d80_Vector4& a)
    {
        x = fabsf(a.x);
        y = fabsf(a.y);
        z = fabsf(a.z);
        w = fabsf(a.w);
    }
    __forceinline void compareLessThanEqual4(float t, int& mask) const
    {
        mask = ((x <= t) ? 8 : 0) | ((y <= t) ? 4 : 0) | ((z <= t) ? 2 : 0) | ((w <= t) ? 1 : 0);
    }
};

extern S8d7d80_Vector4 DAT_01092a50;

struct S8d7d80_Aabb
{
    S8d7d80_Vector4 m_min;
    S8d7d80_Vector4 m_max;
};

struct S8d7d80_Elem
{
    __forceinline const S8d7d80_Aabb& aabb() const
    {
        return *(const S8d7d80_Aabb*)((const char*)this + 0x1a0);
    }
};

struct S8d7d80_Item
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
    S8d7d80_Array<S8d7d80_Elem*> unk48;
};

struct S8d7d80_World
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
    S8d7d80_Array<S8d7d80_Item*> unk28;
};

void FUN_00927c80(S8d7d80_World* world);
void hkpWorldOperationUtil_markIslandInactive(S8d7d80_World* world, S8d7d80_Item* item);

struct S8d7d80_Owner
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual S8d7d80_World* vfn_98();
    void FUN_008d7d80();
};

// pdb: bhkWorld::DeactivateAllIslands | bhkWorld.obj | fnv360_0822_retail, call_gap, low
void S8d7d80_Owner::FUN_008d7d80()
{
    S8d7d80_World* world = vfn_98();
    if (world)
    {
        vfn_98();
        FUN_00927c80(world);
        S8d7d80_Array<S8d7d80_Item*> items;
        items = world->unk28;
        for (int i = 0; i < items.m_size; i++)
        {
            S8d7d80_Item* item = items.m_data[i];
            bool changed = false;
            for (int j = 0; j < item->unk48.m_size && !changed; j++)
            {
                S8d7d80_Elem* e = item->unk48.m_data[j];
                S8d7d80_Vector4 dmin;
                dmin.setSub4(e->aabb().m_min, DAT_01092a50);
                dmin.setAbs4(dmin);
                int cmin;
                dmin.compareLessThanEqual4(0.001f, cmin);
                if ((cmin & 0xe) != 0xe)
                {
                    changed = true;
                }
                else
                {
                    S8d7d80_Vector4 dmax;
                    dmax.setSub4(e->aabb().m_max, DAT_01092a50);
                    dmax.setAbs4(dmax);
                    int cmax;
                    dmax.compareLessThanEqual4(0.001f, cmax);
                    if ((cmax & 0xe) != 0xe)
                    {
                        changed = true;
                    }
                }
            }
            if (!changed)
            {
                hkpWorldOperationUtil_markIslandInactive(world, item);
            }
        }
        FUN_00927c80(world);
        vfn_98();
    }
}
}   // namespace f3m_008d7d80

// @f3 0x008d91e0 (community match, verified in this file)
namespace f3m_008d91e0 {



struct S8d91e0_Ref;
struct S8d91e0_Snd;
struct S8d91e0_Elem;

struct __declspec(align(16)) S8d91e0_V4
{
    float x, y, z, w;
};

struct S8d91e0_Node
{
    void FUN_0090b500();
};

struct S8d91e0_Ref
{
    int unk00;
    int unk04;
    S8d91e0_Node* unk08;
    unsigned unk0c;
    unsigned unk10;
};

struct S8d91e0_Snd
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short unk20;
    unsigned short unk22;
};

struct S8d91e0_Elem
{
    int unk00, unk04, unk08;
    S8d91e0_Ref* unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4;
    S8d91e0_Snd* unkb8;
    void FUN_009316f0();
};

struct S8d91e0_Obj
{
    void hkpWorld_addEntityBatch(S8d91e0_Elem** dst, unsigned n, int z);
    void FUN_009037f0(char* out, S8d91e0_Elem* e);
};

extern S8d91e0_V4 DAT_01092a50;
extern const float DAT_00db7df0;
extern unsigned DAT_00f7947c;
extern char DAT_010f2a62;

void __cdecl FUN_00929570(S8d91e0_Obj* o, S8d91e0_Snd* s);

static __forceinline float S8d91e0_Abs(float f) { return (float)fabs(f); }

static __forceinline bool S8d91e0_Near(const S8d91e0_V4& a, const S8d91e0_V4& b, float eps)
{
    S8d91e0_V4 d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    d.x = S8d91e0_Abs(d.x);
    d.y = S8d91e0_Abs(d.y);
    d.z = S8d91e0_Abs(d.z);
    d.w = S8d91e0_Abs(d.w);
    int m = (d.x <= eps ? 8 : 0) | (d.y <= eps ? 4 : 0)
          | (d.z <= eps ? 2 : 0) | (d.w <= eps ? 1 : 0);
    return (m & 0xE) == 0xE;
}

static __forceinline S8d91e0_Ref* S8d91e0_GetRef(S8d91e0_Elem* const& e)
{
    if (e != 0)
        return e->unk0c;
    return 0;
}

struct S8d91e0_Mgr
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual S8d91e0_Obj* v38();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20;
    int unk24, unk28, unk2c, unk30;
    S8d91e0_Elem** unk34;
    unsigned unk38;
    void FUN_008d4180();
    void FUN_008d5db0();
    void FUN_008d6290();
    void FUN_008d48d0();
    void FUN_008d91e0(char a);
};

void S8d91e0_Mgr::FUN_008d91e0(char a)
{
    if (this->unk20 > 0)
    {
        if (--this->unk20 == 0)
        {
            if (a != 0)
            {
                if (this->unk38 > 0 && DAT_010f2a62 == 0)
                {
                    if (this->unk38 >= 3000)
                        this->unk38 = 3000;
                    unsigned n;
                    if (this->unk38 < DAT_00f7947c)
                        n = this->unk38;
                    else
                        n = DAT_00f7947c;
                    unsigned excess = this->unk38 - n;
                    S8d91e0_Obj* obj = this->v38();
                    if (obj != 0)
                    {
                        obj->hkpWorld_addEntityBatch(&this->unk34[excess], n, 0);
                        char flag = 0;
                        char ch;
                        for (unsigned i = excess; i < this->unk38; i++)
                        {
                            S8d91e0_Ref* ref = S8d91e0_GetRef(this->unk34[i]);
                            if (ref != 0)
                                ref->unk10 &= 0xFFFFFFEF;
                            else
                                obj->FUN_009037f0(&ch, this->unk34[i]);
                            if (flag == 0)
                            {
                                S8d91e0_Snd* s = this->unk34[i]->unkb8;
                                if (s != 0 && s->unk20 != 0xFFFF)
                                {
                                    FUN_00929570(obj, s);
                                    flag = 1;
                                }
                            }
                            const S8d91e0_V4* pv;
                            if (ref != 0 && ref->unk08 != 0)
                                pv = (const S8d91e0_V4*)((char*)ref->unk08 + 0x1A0);
                            else
                                pv = &DAT_01092a50;
                            bool same = false;
                            if (S8d91e0_Near(*pv, DAT_01092a50, 0.001f))
                            {
                                const S8d91e0_V4* qv;
                                if (ref != 0 && ref->unk08 != 0)
                                    qv = (const S8d91e0_V4*)((char*)ref->unk08 + 0x1B0);
                                else
                                    qv = &DAT_01092a50;
                                if (S8d91e0_Near(*qv, DAT_01092a50, 0.001f))
                                    same = true;
                            }
                            if (!same)
                            {
                                if (ref != 0 && ref->unk08 != 0)
                                    ref->unk08->FUN_0090b500();
                            }
                            this->unk34[i]->FUN_009316f0();
                        }
                        memset(&this->unk34[excess], 0, n * 4);
                        this->unk38 = excess;
                    }
                    DAT_010f2a62 = 1;
                }
            }
            else
            {
                FUN_008d4180();
            }
            FUN_008d5db0();
            FUN_008d6290();
            FUN_008d48d0();
        }
    }
    else if (this->unk38 > 0 && a == 0)
    {
        FUN_008d4180();
    }
}
}   // namespace f3m_008d91e0

// @f3 0x008dce20 (community match, verified in this file)
namespace f3m_008dce20 {
namespace f3m_008dce20 {
struct Point3_8dce20 {
    float x, y, z;
};

struct Matrix33_8dce20 {
    float m[9];
};

struct UpdateData8dce20 {
    float time;
    bool b4, b5, b6, b7, b8;
    UpdateData8dce20(float t, bool c, bool m)
        : time(t), b4(c), b5(m), b6(false), b7(false), b8(false) {}
};

struct Node8dce20 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    Matrix33_8dce20 m_kLocalRotate;
    Point3_8dce20 m_kLocalTranslate;

    void FUN_008264c0(UpdateData8dce20& data);
};

struct Entry8dce20 {
    Node8dce20* node;
    Matrix33_8dce20 rot;
    Point3_8dce20 trans;
    float scale;
};

struct List8dce20 {
    int unk00;
    Entry8dce20* data;
    unsigned int count;
};

void __cdecl FUN_008d7b90(Node8dce20* node, int mode, bool a, bool b, bool c);
void __cdecl FUN_008f1d80(bool flag, Node8dce20* node);
}

// pdb: bhkRagdollController::ResetPose | bhkRagdollController.obj | fnv360_0822_retail, callee_sim, low
// pdb params: apSkeleton, arPoseA, abPrevUseVel, aePrevMotion
void __cdecl FUN_008dce20(f3m_008dce20::Node8dce20* root, f3m_008dce20::List8dce20* list, bool flag, int mode)
{
    using namespace f3m_008dce20;
    for (unsigned int i = 0; i < list->count; ++i) {
        list->data[i].node->m_kLocalTranslate = list->data[i].trans;
        list->data[i].node->m_kLocalRotate = list->data[i].rot;
    }
    UpdateData8dce20 update(0.0f, false, false);
    root->FUN_008264c0(update);
    if (mode != 6)
        FUN_008d7b90(root, mode, true, false, true);
    if (flag)
        FUN_008f1d80(flag, root);
}
}   // namespace f3m_008dce20

// @f3 0x008d40c0 (community match, verified in this file)
namespace f3m_008d40c0 {
struct P8d40c0 {
    int unk00;
    int unk04;
    int unk08;
    int* unk0c;
};

struct O8d40c0 {
    int unk00;
    int unk04;
    int unk08;
    unsigned short flags;
    unsigned short unk0e;
};

O8d40c0* __cdecl FUN_008d40c0(O8d40c0* o, P8d40c0* p) {
    if (p->unk0c)
        o->flags |= 1;
    else
        o->flags &= ~1;
    return o;
}
}   // namespace f3m_008d40c0

// @f3 0x008d5970 (community match, verified in this file)
namespace f3m_008d5970 {
struct Arg2_8d5970 {
    int unk00, unk04, unk08;
    int unk0c;
};

struct Callee_8d5970 {
    void Method(bool flag);
};

struct Arg1_8d5970 {
    int unk00, unk04, unk08, unk0c;
    Callee_8d5970* field10;
};

// pdb: bhkWorld::DoEnableCollision | bhkWorld.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: bhkWorld::EnableObject)
// pdb params: apCollision, arData
void FUN_008d5970(Arg1_8d5970* a, Arg2_8d5970* b) {
    if (a->field10) {
        a->field10->Method(b->unk0c != 0);
    }
}
}   // namespace f3m_008d5970

// @f3 0x008d35a0 (community match, verified in this file)
namespace f3m_008d35a0 {
class WorldHeap
{
public:
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* memory);
};
extern WorldHeap DAT_01090a78;

// pdb: bhkRigidBody::SetDisabled | bhkWorld.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: bhkWorld::bhkConstraintProjector::bhkConstraintProjector)
// pdb params: abTF
void __stdcall FUN_008d35a0(void* memory, int, int)
{
    if (memory) {
        unsigned char* q = (unsigned char*)memory;
        DAT_01090a78.FUN_0086ba60(q - q[-1]);
    }
}
}   // namespace f3m_008d35a0

// @f3 0x008dbe90 (community match, verified in this file)
namespace f3m_008dbe90 {
struct B_Object;

struct B_Ref {
    unsigned int unk00, unk04;
    B_Object* object;
};

struct B_Link {
    B_Ref* ref;
};

struct B_Data {
    unsigned int unk00, unk04;
    B_Link* link;
    unsigned int unk0c, unk10;
    void** entries;
    int count;
};

struct B_Body { int unk00; };

struct B_Object {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    unsigned int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    unsigned int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    unsigned int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    unsigned int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    unsigned int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    unsigned int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;
    unsigned int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    unsigned int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;
    unsigned int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    unsigned int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;
    unsigned int unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc;
    unsigned int unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc;
    unsigned int unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc;
    unsigned int unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c;
    unsigned int unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c;
    unsigned int unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c;
    unsigned int unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c;
    unsigned int unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c;
    unsigned int unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc;
    unsigned int unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc;
    unsigned int unk2e0,unk2e4,unk2e8,unk2ec,unk2f0,unk2f4,unk2f8,unk2fc;
    unsigned int unk300,unk304,unk308,unk30c;
    B_Body* body;
};

struct B_Owner {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44;
    B_Data* data;
    B_Body* FUN_008dbe90();
};

// pdb: bhkRagdollController::GetRigidBodyHead | bhkRagdollController.obj | fnv360_0822_retail, call_gap_sim, low, conflict (bridge: bhkRagdollController::GetWorld)
B_Body* B_Owner::FUN_008dbe90()
{
    B_Data* current = data;
    if (current) {
        B_Ref* ref = current->link->ref;
        if (ref) {
            B_Object* object = ref->object;
            if (object)
                return object->body;
        }
    }
    return 0;
}
}   // namespace f3m_008dbe90

// @f3 0x008d4000 (community match, verified in this file)
namespace f3m_008d4000 {
// FUN_008d4000 @ 0x008d4000 - 30 bytes
// Shape: thiscall, virtual call through vtable slot 0x98 returning a pointer;
// if null -> false; else return (ptr->unk2c != 0).

struct Ctx8d4000 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
};

struct Owner8d4000 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual Ctx8d4000* GetContext();
    bool FUN_008d4000();
};

bool Owner8d4000::FUN_008d4000()
{
    bool result = false;
    Ctx8d4000* context = GetContext();
    if (context)
        result = context->unk2c != 0;
    return result;
}
}   // namespace f3m_008d4000

// @f3 0x008d31d0 (community match, verified in this file)
namespace f3m_008d31d0 {
struct P8d31d0 {
    char pad[0xc];
    int f0c;
};

struct O8d31d0 {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8();
    virtual void Slot(bool flag);
};

// pdb: bhkWorld::SetMotionOnObject | bhkWorld.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apCollision, arData
void __cdecl FUN_008d31d0(O8d31d0* o, P8d31d0* p) {
    o->Slot(p->f0c != 0);
}
}   // namespace f3m_008d31d0

// @f3 0x008d9e00 (community match, verified in this file)
namespace f3m_008d9e00 {
namespace f3m_008d9e00 {

struct V8d9e00 {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(int arg);
};

struct O8d9e00 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    V8d9e00* p10;
    void FUN_0084a770(int arg);
    void FUN_008d9e00(int arg);
};

// pdb: bhkNiCollisionObject::RegisterStreamables | bhkNiCollisionObject.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void O8d9e00::FUN_008d9e00(int arg)
{
    V8d9e00* target = p10;
    if (target) target->v054(arg);
    FUN_0084a770(arg);
}

}
}   // namespace f3m_008d9e00

// @f3 0x008daff0 (community match, verified in this file)
namespace f3m_008daff0 {
struct C8Info {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned flags;
};
struct C8Event {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    C8Info* info;
};
struct C8Receiver {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    unsigned char unk68, enabled, unk6a, unk6b;
    unsigned count;
    void FUN_008daff0(C8Event* event);
};
// pdb: bhkCharacterListener::contactPointRemovedCallback | bhkCharacterListener.obj | fnv360_0822_retail, objrun_open, low
// pdb params: __formal, arPoint
void C8Receiver::FUN_008daff0(C8Event* event) {
    if ((event->info->flags & 0x7f) == 30) {
        if (count > 0) --count;
    }
}
}   // namespace f3m_008daff0

// @f3 0x008d3170 (community match, verified in this file)
namespace f3m_008d3170 {
struct Obj8d3170 {
    virtual ~Obj8d3170();
};

struct Owner8d3170 {
    void* table;
    int unk04;
    int enabled;
    void* tail;
    void FUN_008d3170(bool b);
};

// pdb: bhkWorld::NI2HKObject | bhkWorld.obj | fnv360_0822_retail, objrun, medium
// pdb params: apCollision, __formal
void Owner8d3170::FUN_008d3170(bool b)
{
    if (b) {
        if (tail) {
            Obj8d3170* object = (Obj8d3170*)((char*)tail - 0xd0);
            delete object;
        }
        tail = 0;
    }
}
}   // namespace f3m_008d3170

// @f3 0x008d7650 (community match, verified in this file)
extern unsigned char DAT_010f2a61;
extern void* DAT_00f794a8;
extern void* DAT_00f79480;
namespace f3m_008d7650 {
namespace f3m_008d7650 {
struct Info {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
};

struct Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c;
};

Info* __cdecl FUN_00aa60f0(Obj* obj);

inline unsigned int Enabled(Obj* p) {
    Info* f = FUN_00aa60f0(p);
    return f ? (f->flags & 2) : 0;
}

struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    bool unk1c;

    bool bhkWorld_AddObjects(Obj* obj, unsigned char a2, bool a3, int a4, bool force);
};

struct Ev {
    Owner* owner;
    unsigned char a2;
    int type;
    int f0c;
    int f10;
    int f14;
    int f18;
};

void __cdecl FUN_008d5790(Obj* obj, Ev* ev, void* handler);


// pdb: bhkWorld::AddObjects | bhkWorld.obj | fnv360_0822_retail, caller_sim + bridge(vtable|caller_sim) + skyrim(caller_sim), high
bool Owner::bhkWorld_AddObjects(Obj* obj, unsigned char a2, bool a3, int a4, bool force)
{
    bool result = false;
    if (obj && (force || Enabled(obj))) {
        unk1c = true;
        Ev ev;
        ev.owner = this;
        ev.a2 = a2;
        if (DAT_010f2a61) {
            ev.type = 10;
            if (DAT_00f794a8)
                FUN_008d5790(obj, &ev, DAT_00f794a8);
        }
        int flag = a3 != 0;
        if (!obj->unk1c)
            flag = 0;
        ev.f0c = flag;
        ev.type = 0;
        ev.f10 = a4;
        ev.f14 = 0;
        ev.f18 = 1;
        if (DAT_00f79480)
            FUN_008d5790(obj, &ev, DAT_00f79480);
        result = true;
    }
    return result;
}
}
}   // namespace f3m_008d7650

// @f3 0x008d5b70 (community match, verified in this file)
namespace f3m_008d5b70 {
struct H1B;
struct H1C;
struct H1A { virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3C(); virtual H1B* GetB(); };
struct H1C { int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C, unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C, unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC, unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4; unsigned char unk00D8; };
struct H1B { int unk00; H1C* unk08; virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64(); virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74(); virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84(); virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9C(); virtual void slotA0(); virtual void slotA4(); virtual void slotA8(); virtual void slotAC(); virtual void slotB0(); virtual void slotB4(); virtual void slotB8(); virtual void slotBC(); virtual void slotC0(); virtual void slotC4(); virtual void slotC8(); virtual void slotCC(); virtual void slotD0(); virtual void slotD4(); virtual void slotD8(); virtual void Run(int); };
struct H1Holder { int unk00, unk04, unk08, unk0C; H1A* unk10; };

// pdb: bhkWorld::QActiveObject | bhkWorld.obj | tesv_win, objopen_prop, low
void __cdecl FUN_008d5b70(H1Holder* p)
{
    H1A* a = p->unk10;
    if (a != 0) {
        H1B* b = a->GetB();
        if (b != 0) {
            H1C* c = b->unk08;
            int flag = 0;
            if (c != 0) flag = c->unk00D8;
            if (c == 0 || flag == 7) {
                b->Run(6);
            }
        }
    }
}
}   // namespace f3m_008d5b70

// @f3 0x008d90a0 (community match, verified in this file)
namespace f3m_008d90a0 {
// Model of FUN_008d90a0 (85 bytes), second revision ✓✓ v1 measured 112 vs 85 / 49 lines and both problems were mine: (1) padding the local with a char array made VC8 insert /GS stack-cookie code ('xor
// eax,esp' prologue plus 'call __security_check_cookie') which their build has none of - so NO arrays in a local type here ✓✗→✓✓ and (2) my namespace-scoped prototype for FUN_008D5790 came out
// UNBOUND ('f3m_008d90a0::FUN_008d5790(?unbound)'), most likely because this unit already declares that name three times with different signatures, so I now declare it once at global scope with
// extern "C" to get an unmangled name that binds by address ✓✓ 
// The smaller unit's prelude was also decisive in a happy way: namespace f3m_008d79d0::task1199 carries a SIBLING body (FUN_008d79d0) that builds the very same local and calls FUN_008d5790(object,
// &context, DAT_00f794c0), with 'struct Context { void* current; bool recurse; unsigned traversal; float value; int unk10,unk14,unk18; }' - twenty-eight bytes ✓✓ exactly the frame their build
// reserves here. That layout explains two details v1 got wrong: the store at +4 is a BYTE store ('mov byte ptr [esp+4], 1') because recurse is a bool, and my dword store was wrong ✓✗→✓✓ 
//   mov al,[esp+arg_4] ; sub esp,1Ch ; cmp [ecx+1Eh],al ; jz past ; mov [ecx+1Eh],al    - parameter two is a BYTE compared against this->flag at +0x1E and written only when it differs ✓✓ the frame is
//                                                                                          made between loading the byte and the comparison, i.e. before any of that ✓✓ 
//   mov edx,[esp+1Ch+arg_0] ; test edx,edx ; jz common tail                              - parameter one (the object) null-skips everything ✓✓ 
//   xor eax,eax ; cmp [ecx+1Eh],al ; setne al ; mov [esp+1Ch+var_10],eax                 - the flag is tested against ZERO HELD IN A REGISTER and the boolean lands in the context's +C slot, which this
//                                                                                          variant fills with an integer rather than a float ✓✓ 
//   mov [var_1C],0 ; mov [esp+4],1 (byte) ; mov [var_14],6                               - current = 0, recurse = true, traversal = 6 ✓✓ interleaved with the setne above ✓✓ 
//   mov eax,off_F79498 ; test eax,eax ; jz common tail                                   - a global callback slot, loaded once and null-checked; it is only passed along ✓✓ 
//   push eax ; lea ecx,[esp+20h+var_1C] ; push ecx ; push edx ; call sub_8D5790 ; add esp,0Ch
//                                                                                          - (object, &context, callback), caller-cleaned ✓✓ ECX merely ends up holding the context address from the lea ✓✓ 
//   add esp,1Ch ; retn 8                                                                 - one shared tail for all three exits ✓✓ 

extern "C" void __cdecl FUN_008d5790(void* object, void* context, void* callback);   // declared once at GLOBAL scope with extern "C" so the emitted name is unmangled and binds to 0x8D5790 ✓✓ (v1's
                                                                                     //     namespace-scoped prototype reported (?unbound) because this unit already declares that name three times with
                                                                                     //     different signatures inside other namespaces) ✗✗→✓✓ 

namespace f3m_008d90a0b {

struct Ctx8D9 {                                      // mirrors the sibling unit's Context exactly: 28 bytes, no array members (an array here triggered /GS) ✓✓
    void* current;                                   // +0x00: ORIG mov [esp+1Ch+var_1C], 0 ✓✓ 
    bool recurse;                                    // +0x04: ORIG 'mov byte ptr [esp + 4], 1' - a BYTE store, hence bool ✓✓ 
    unsigned traversal;                              // +0x08: ORIG mov [esp+1Ch+var_14], 6 ✓✓ 
    int value;                                       // +0x0C: ORIG setne al then 'mov [esp+1Ch+var_10],eax' - an integer here, not the sibling's float ✓✓ 
    int unk10, unk14, unk18;                         // never written; they hold the frame at 28 bytes without needing padding ✓✓ 
};

typedef void (__cdecl *Callback8D9)(void* object, struct Ctx8D9* context);   // the sibling prelude uses a typedef'd callback in exactly this third-argument position ✓✓ 

extern Callback8D9 DAT_00f79498;                     // ORIG: mov eax,off_F79498 ; test eax,eax - loaded once, null-checked, passed through ✓✓ 

struct Owner8D9 {                                    // 'this' stays in ECX across the whole body in their build ✓✓
    char pad1E[0x1E];
    unsigned char flag1E;                            // +0x1E: a byte - set-if-changed, then tested against zero ✓✓ 

    void FUN_008d90a0(void* objectParameter, unsigned char flagParameter);   // thiscall with two stack parameters ('retn 8') ✓✓
};

// pdb: GetCollisionObjectByIndexInSceneGraph | GlobalFunc.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: apRoot, aiIndex, abIgnoreWeaponBone, abIgnoreFadeNodes, abIgnoreArrows
void Owner8D9::FUN_008d90a0(void* objectParameter, unsigned char flagParameter) {
    if (this->flag1E != flagParameter)               // ORIG: cmp [ecx+1Eh],al ; jz past ; mov [ecx+1Eh],al ✓✓ 
        this->flag1E = flagParameter;

    if (objectParameter != 0) {                      // ORIG: test edx,edx ; jz common tail ✓✓ 
        struct Ctx8D9 context;                       // ORIG: 'sub esp,1Ch' as the second instruction of the function ✓✓ 
        unsigned char notSet = 0;                    // ORIG keeps its zero in a register (xor eax,eax) and compares [ecx+1Eh] against AL rather than using an immediate ✗✗→? 

        context.current = 0;                         // ORIG: mov [esp+1Ch+var_1C], 0 ✓✓ 
        context.recurse = true;                      // ORIG: mov byte ptr [esp + 4], 1 ✓✓ 
        context.traversal = 6;                       // ORIG: mov dword ptr [esp + 8], 6 ✓✓ 
        context.value = (this->flag1E != notSet);    // ORIG: xor eax,eax ; cmp byte[ecx+1Eh],al ; setne al ; mov [esp+0Ch] wait - the store lands at var_10, i.e. +C ✓✓ 

        if (DAT_00f79498 != 0)
            FUN_008d5790(objectParameter, &context, DAT_00f79498);   // ORIG: push eax ; lea ecx,[esp+20h+var_1C] ; push ecx ; push edx ; call sub_8D5790 ; add esp,0Ch ✓✓ 
    }
}

}

extern "C" void __cdecl FUN_008d5790(void* object, void* context, void* callback);   // declared once at GLOBAL scope with extern "C" so the emitted name is unmangled and binds to 0x8D5790 ✓✓ (v1's
                                                                                     //     namespace-scoped prototype reported (?unbound) because this unit already declares that name three times with
                                                                                     //     different signatures inside other namespaces) ✗✗→✓✓ 
}   // namespace f3m_008d90a0

// @f3 0x008d8f60 (community match, verified in this file)
namespace f3m_008d8f60 {
namespace f3m_008d8f60 {

extern long (__stdcall* DAT_00d9b068)(volatile long*);
extern long (__stdcall* DAT_00d9b064)(volatile long*);

class RefObject {
public:
    virtual void vfn_00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;

    void IncRefCount() {
        DAT_00d9b068(&m_uiRefCount);
    }
    void DecRefCount() {
        if (DAT_00d9b064(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct RefPtr {
    RefObject* m_pObject;
    RefPtr(RefObject* pObject) : m_pObject(pObject) {
        m_pObject->IncRefCount();
    }
    ~RefPtr() {
        int z = 0;
        if (z)
            m_pObject->DecRefCount();
    }
};

struct Action {
    int unk00;
    unsigned short memSize04;
    short refCount06;
    int unk08;
    int unk0c;
    RefObject* unk10;

    void AddReference() {
        if (memSize04 != 0)
            ++refCount06;
    }
};

struct Context {
    void FUN_009084b0(Action* action);
};

struct NodeMap {
    void FUN_004c25a0(const RefPtr* ptr);
};

struct World {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94();
    virtual Context* GetContext();

    int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    unsigned int unk24;
    int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40;
    Action** items44;
    unsigned int count48;
    int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    NodeMap refs90;

    void FUN_008d4c10();
    void FUN_008d4b60();
    void FUN_008d4ad0();
    void FUN_008d4a40();
    bool FUN_008d8f60(Action* action);
};

// pdb: bhkWorld::Remove | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apAction
bool World::FUN_008d8f60(Action* action)
{
    bool result = false;
    Context* ctx = GetContext();
    if (ctx && action) {
        RefObject* obj = action->unk10;
        if (obj) {
            {
                RefPtr sp(obj);
                refs90.FUN_004c25a0(&sp);
            }
            obj->DecRefCount();
        }
        result = true;
        if (unk24 > 0) {
            if (count48 >= 100) {
                FUN_008d4c10();
                FUN_008d4b60();
                FUN_008d4ad0();
                FUN_008d4a40();
            }
            action->AddReference();
            items44[count48] = action;
            ++count48;
        } else {
            ctx->FUN_009084b0(action);
        }
    }
    return result;
}

}
}   // namespace f3m_008d8f60

// @f3 0x008d3ee0 (community match, verified in this file)
namespace f3m_008d3ee0 {
namespace State8d3ee0 {
struct Object;
struct Node {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
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
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
int unk260;
int unk264;
int unk268;
int unk26c;
int unk270;
int unk274;
int unk278;
int unk27c;
int unk280;
int unk284;
int unk288;
int unk28c;
int unk290;
int unk294;
int unk298;
int unk29c;
int unk2a0;
int unk2a4;
int unk2a8;
int unk2ac;
int unk2b0;
int unk2b4;
int unk2b8;
int unk2bc;
int unk2c0;
int unk2c4;
int unk2c8;
int unk2cc;
int unk2d0;
int unk2d4;
int unk2d8;
int unk2dc;
int unk2e0;
int unk2e4;
int unk2e8;
int unk2ec;
int unk2f0;
int unk2f4;
int unk2f8;
int unk2fc;
int unk300;
int unk304;
int unk308;
int unk30c;
Object* owner;
};
struct Object {
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
virtual Node* getNode();
void FUN_008f7c70(bool);
void FUN_008d3ee0(bool);
};
// pdb: bhkWorld::Link | bhkWorld.obj | fnv360_0822_retail, caller_sim, low
// pdb params: abAttach
void Object::FUN_008d3ee0(bool enabled) {
 if(this) {
 Node* node=getNode();
 if(node) node->owner=enabled?this:0;
 }
 FUN_008f7c70(enabled);
}
}
}   // namespace f3m_008d3ee0

// @f3 0x008da790 (community match, verified in this file)
extern __declspec(thread) int DAT_tls_0x2c0;
namespace f3m_008da790 {
namespace Context8da790 {
void* FUN_008da4c0(void*,int);
// pdb: bhkNiCollisionObject::Synchronize | bhkNiCollisionObject.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apObject, aeMode
void* FUN_008da790(void* object,int context) {
 int saved=DAT_tls_0x2c0;
 DAT_tls_0x2c0=context;
 void* result=FUN_008da4c0(object,0);
 DAT_tls_0x2c0=saved;
 return result;
}
}
}   // namespace f3m_008da790

// @f3 0x008d5ac0 (community match, verified in this file)
namespace f3m_008d5ac0 {
namespace Query8d5ac0 {
struct State { bool* FUN_0090b0e0(bool*); };
struct Link { int unk00,unk04; State* state; };
struct Object {
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
virtual Link* getLink();
};
struct Arg { int unk00,unk04,unk08,unk0c; Object* object; };
struct Result { int unk00; bool active; char unk05,unk06,unk07; int unk08,count; };
// pdb: bhkWorld::QActiveObject | bhkWorld.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: bhkWorld::SetMotionOnObject)
// pdb params: apCollision, arData
void FUN_008d5ac0(Arg* arg,Result* result) {
 Object* object=arg->object;
 if(object) {
 Link* link=object->getLink();
 if(link) {
 State* state=link->state;
 bool value;
 bool active=false;
 if(state) active=!!*state->FUN_0090b0e0(&value);
 if(active) result->count++;
 result->active=false;
 }
 }
}
}

}   // namespace f3m_008d5ac0

// @f3 0x008db440 (community match, verified in this file)
namespace f3m_008db440 {
namespace State8db440 {
struct Object {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
unsigned char unk40,unk41,unk42,frozen;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
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
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
unsigned char enabled,unk221,active,dirty;
void FUN_008db440(bool);
};
void Object::FUN_008db440(bool requested) {
 unsigned char previous=active;
 int state;
 if(!frozen) state=enabled && requested ? 1 : 0;
 else state=previous;
 active=(unsigned char)state;
 if(previous && !active) dirty=1;
}
}
}   // namespace f3m_008db440

// @f3 0x008d4020 (community match, verified in this file)
namespace Clear8d4020 {
struct Entry { void* first; void* second; };
struct Manager { void FUN_00909210(void*,void*,int); };
extern Manager* DAT_010f323c;
struct Object {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int enabled;
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
Entry* entries;
unsigned count;
void FUN_008d4020();
};
// pdb: bhkWorld::HasActiveItems | bhkWorld.obj | fnv360_0822_retail, objrun_sim, low
void Object::FUN_008d4020() {
 if(!enabled) goto done;
 {
 unsigned i=count;
 while(i) {
 Entry& entry=entries[--i];
 DAT_010f323c->FUN_00909210(entry.second,entry.first,0);
 }
 }
 done:
 count=0;
}
}

// @f3 0x008d5a50 (community match, verified in this file)
#include <windows.h>
namespace f3m_008d5a50 {
namespace Release8d5a50 {
struct Owner;
struct Object {
virtual void slot0();
virtual void destroy();
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
virtual void attach(Owner*);
LONG refs;
Owner* owner;
};
struct Owner {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18; Object* object;};
struct Arg {int unk00,unk04;Owner* owner;};
// pdb: bhkWorld::ActivateObject | bhkWorld.obj | fnv360_0721_beta, objrun + skyrim(objopen_prop), high
void bhkWorld_ActivateObject(Arg* arg) {
 Owner* owner=arg->owner;
 if(owner) {
 Object* previous=owner->object;
 if(previous) {
 if(InterlockedDecrement(&previous->refs)==0) previous->destroy();
 owner->object=0;
 }
 Object* object=owner->object;
 if(object && object->owner!=owner) object->attach(owner);
 }
}
}
}   // namespace f3m_008d5a50

// @f3 0x008d3960 (community match, verified in this file)
#include <windows.h>
namespace f3m_008d3960 {
struct WeightArray { int unk00,unk04,unk08; WeightArray(); ~WeightArray() {} };
namespace Construct8d3960 {
struct Lock { CRITICAL_SECTION section; Lock(){InitializeCriticalSection(&section);} ~Lock(){DeleteCriticalSection(&section);} };
struct FUN_008d3960 : Lock {
 WeightArray entries[16];
 int count;
 FUN_008d3960();
};
// pdb: bhkTaskletManagerCallback::bhkThreadState::bhkThreadState | bhkWorld.obj | fnv360_0822_debug, objrun_prop, high
FUN_008d3960::FUN_008d3960() : count(0) {}
}
}   // namespace f3m_008d3960

// @f3 0x008d7c80 (community match, verified in this file)
namespace f3m_008d7c80 {
namespace Query8d7c80 {
struct State {int unk00,unk04,unk08;unsigned flags;};
struct Query {int count;bool active;int type;int result;int unk10,unk14,unk18;};
State* FUN_00aa60f0(void*);
inline unsigned mask(void* object) { State* state=FUN_00aa60f0(object); return state ? state->flags&2 : 0; }
extern void (*DAT_00f794a0)();
void FUN_008d5790(void*,Query*,void(*)());
// pdb: bhkWorld::IsActive | bhkWorld.obj | fnv360_0822_retail, call_seq + bridge(caller_sim|call_gap_sim) + skyrim(objrun_open), high
bool bhkWorld_IsActive(void* object,bool active,bool force) {
 bool result=false;
 if(object) {
 State* state;
 if(force || mask(object)) {
 Query query;
 query.count=0;
 query.active=active;
 query.type=8;
 query.result=0;
 if(DAT_00f794a0) FUN_008d5790(object,&query,DAT_00f794a0);
 result=query.result!=0;
 }
 }
 return result;
}
}


}   // namespace f3m_008d7c80

// @f3 0x008d7960 (community match, verified in this file)
namespace f3m_008d7960 {
namespace Query8d7960 {
struct State {int unk00,unk04,unk08;unsigned flags; unsigned mask() const {return flags&2;}};
struct Query {int count;bool active;int type;float amount;int unk10,unk14,unk18;};
State* FUN_00aa60f0(void*);
inline unsigned maskedState(void* object) { State* state=FUN_00aa60f0(object); return state ? state->flags&2 : 0; }
extern void (*DAT_00f794bc)();
void FUN_008d5790(void*,Query*,void(*)());
// pdb: bhkWorld::SetRestitution | bhkWorld.obj | fnv360_0721_beta, objrun, medium
// pdb params: apObject, afRestitution, abRecurse, abForce
bool FUN_008d7960(void* object,float amount,bool active,bool force) {
 bool result=false;
 if(object) {
 State* state;
 if(force || maskedState(object)) {
 result=true;
 Query query;
 query.count=0;
 query.active=active;
 query.type=15;
 query.amount=amount;
 if(DAT_00f794bc) FUN_008d5790(object,&query,DAT_00f794bc);
 }
 }
 return result;
}
}


}   // namespace f3m_008d7960

// @f3 0x008d5990 (community match, verified in this file)
namespace f3m_008d5990 {
namespace f3m_008d5990 {

struct BhkPhysBody
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;

    float m_f88;
};

struct BhkPhysResult
{
    int unk00;
    int unk04;
    BhkPhysBody* m_pPhysicsBody;
};

struct BhkPhysObject;

typedef BhkPhysResult* (__fastcall* BhkPhysGetResult)(BhkPhysObject* pSelf);

struct BhkPhysSlotTable
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
    BhkPhysGetResult m_fnGetResult;
};

struct BhkPhysObject
{
    BhkPhysSlotTable* m_pSlots;
};

struct BhkPhysRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BhkPhysObject* m_pObject;
};

struct BhkPhysParam
{
    int unk00;
    int unk04;
    int unk08;
    float m_f0c;
};

}

// pdb: bhkWorld::SetMotionOnObject | bhkWorld.obj | fnv360_0822_debug, objrun_sim, low, conflict (skyrim: bhkWorld::DoEnableCollision)
// pdb params: apCollision, arData
void FUN_008d5990(f3m_008d5990::BhkPhysRecord* pRecord, f3m_008d5990::BhkPhysParam* pParam)
{
    f3m_008d5990::BhkPhysObject* pObject = pRecord->m_pObject;
    if (!pObject)
        return;
    f3m_008d5990::BhkPhysResult* pResult = pObject->m_pSlots->m_fnGetResult(pObject);
    if (!pResult)
        return;
    f3m_008d5990::BhkPhysBody* pBody = pResult->m_pPhysicsBody;
    f3m_008d5990::BhkPhysParam* pValue = *(f3m_008d5990::BhkPhysParam* volatile*)&pParam;
    pBody->m_f88 = pValue->m_f0c;
}
}   // namespace f3m_008d5990

// @f3 0x008d5b00 (community match, verified in this file)
namespace f3m_008d5b00 {
namespace f3m_008d5b00 {
struct Head { int unk00; int unk04; int unk08; int unk0c; };
struct Data { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; unsigned int unk1c; };
struct Node : Head, Data { };
struct Owner { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c(); virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac(); virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc(); virtual void v0c0(); int unk04; Node* unk08; };
struct Arg { int unk00; int unk04; int unk08; int unk0c; Owner* unk10; };
struct Msg { int unk00; int unk04; int unk08; unsigned int unk0c; unsigned int unk10; };

static inline Data* GetData(Owner* o) {
    if (o && o->unk08) return o->unk08;
    return 0;
}

// pdb: bhkWorld::GroupObject | bhkWorld.obj | tesv_win, objopen_prop, low
void __cdecl FUN_008d5b00(Arg* a, Msg* m) {
    Owner* o = a->unk10;
    unsigned int kind = m->unk10;
    unsigned int expected = m->unk0c;
    Data* d = GetData(o);
    unsigned int flags = d ? d->unk1c : 0;
    unsigned int cur = flags & 0x7f;
    if (kind == cur) return;
    if (expected && expected != cur) return;
    unsigned int merged = ((flags ^ kind) & 0x7f) ^ flags;
    d = GetData(o);
    if (d) d->unk1c = merged;
    o->v0c0();
}
}
}   // namespace f3m_008d5b00

// @f3 0x008d9cd0 (community match, verified in this file)
namespace f3m_008d9cd0 {
namespace Compare8d9cd0 {
struct Vec {float x,y,z;Vec(const Vec* p):x(p->x),y(p->y),z(p->z){}};
struct Matrix {Vec row[3];};bool FUN_00464d70(const Vec*,const Vec*,float);
// pdb: CloseTo | bhkNiCollisionObject.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: arM1, arM2, afEpsilon
bool FUN_008d9cd0(const Matrix* a,const Matrix* b,float tolerance){for(unsigned i=0;i<3;++i){Vec left(&a->row[i]);Vec right(&b->row[i]);if(!FUN_00464d70(&left,&right,tolerance))return false;}return true;}
}
}   // namespace f3m_008d9cd0

// @f3 0x008d6140 (community match, verified in this file)
namespace f3m_008d6140 {
namespace Insert8d6140 {
struct Item {int unk00;unsigned short kind,refs;};struct Manager {void hkpWorld_removeConstraint(Item**,Item*);};
struct Object {virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual Manager* get();int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; unsigned count;int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; Item** items;unsigned size;void FUN_008d4c10();void FUN_008d4b60();void FUN_008d4ad0();void FUN_008d4a40();bool FUN_008d6140(Item*);};
// pdb: bhkWorld::Remove | bhkWorld.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: bhkWorld::DeactivateAllIslands)
// pdb params: apConstraint
bool Object::FUN_008d6140(Item* input){bool result=false;Manager* m=get();if(m){Item* item=*(Item* volatile*)&input;if(item){result=true;if(count>0){if(size>=200){FUN_008d4c10();FUN_008d4b60();FUN_008d4ad0();FUN_008d4a40();}if(item->kind)++item->refs;items[size]=item;++size;}else m->hkpWorld_removeConstraint(&input,item);}}return result;}
}

}   // namespace f3m_008d6140

// @f3 0x008d4a40 (community match, verified in this file)
namespace f3m_008d4a40 {
namespace Flush278 {
struct Flags {int unk00,unk04,unk08,unk0c;unsigned flags;};struct Item {int unk00,unk04,unk08;Flags* owner;void FUN_009316f0();};
struct Sink {void FUN_00906d80(Item**,unsigned);};extern unsigned DAT_00f79478;
struct Object {virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094();virtual Sink* get();int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50;Item** items;unsigned count;void FUN_008d4a40();};
// pdb: bhkWorld::RemoveBatchedEntities | bhkWorld.obj | fnv360_0822_debug, call_seq, low, conflict (bridge: bhkWorld::RemoveBatchedEntitiesPartial)
void Object::FUN_008d4a40(){if(count>0){if(count>=3000)count=3000;unsigned n=DAT_00f79478;if(count<n)n=count;unsigned start=count-n;Sink* sink=get();if(sink){sink->FUN_00906d80(items+start,n);for(unsigned i=start;i<count;++i){Item* item=items[i];if(item){Flags* owner=item->owner;if(owner)owner->flags&=~32;}items[i]->FUN_009316f0();items[i]=0;}count=start;}}}
}

}   // namespace f3m_008d4a40

// @f3 0x008dcfb0 (community match, verified in this file)
#include <new>
namespace f3m_008dcfb0 {
namespace Array305 {
struct FUN_00851550 {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;FUN_00851550();~FUN_00851550();};
struct Element {int value;FUN_00851550 member;Element():value(0){}static void* operator new(unsigned,void* p){return p;}static void operator delete(void*,void*);};
void __stdcall FUN_008dcfb0(Element* first,unsigned count){for(unsigned i=0;i<count;++i)new(first+i) Element;}
}
}   // namespace f3m_008dcfb0

// @f3 0x008d4cc0 (community match, verified in this file)
namespace f3m_008d4cc0 {
namespace Refresh354 {
struct Item{void FUN_0090af70();};struct Group{int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; Item** items;int count;void refresh(){for(int i=0;i<count;++i)items[i]->FUN_0090af70();}};struct Parent{int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; Group* group;int unk24;Group** a;int countA;int unk30;Group** b;int countB;};struct Owner{virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual Parent* parent();void FUN_008d4cc0();};void Owner::FUN_008d4cc0(){Parent* p=this?parent():0;p->group->refresh();for(int i=0;i<p->countB;++i)p->b[i]->refresh();for(int j=0;j<p->countA;++j)p->a[j]->refresh();}
}
}   // namespace f3m_008d4cc0

// @f3 0x008dfac0 (community match, verified in this file)
namespace f3m_008dfac0 {
namespace f3m_008dfac0 {

struct Node30 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    unsigned int flags30;

    bool IsBit1() const {
        return (unsigned char)(flags30 >> 1) & 1;
    }
};

struct SubInfo {
    int unk00, unk04, unk08, unk0c, unk10;
    short idx14;
    short idx16;
    short idx18;
};

struct EntryD0 {
    SubInfo* info00;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
};

struct Owner8dfac0 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0;
    Node30** nodesA4;
    unsigned int nodeCountA8;
    int unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228;
    EntryD0* entries22c;
    int count230;

    Node30* GetNode(int idx) const {
        return nodeCountA8 > (unsigned int)idx ? nodesA4[idx] : 0;
    }

    bool FUN_008dfac0();
};

bool Owner8dfac0::FUN_008dfac0()
{
    bool res = false;
    for (int i = 0; i < count230; ++i) {
        if (res)
            break;
        SubInfo* info = entries22c[i].info00;
        Node30* n3 = GetNode(info->idx18);
        Node30* n2 = GetNode(info->idx16);
        Node30* n1 = GetNode(info->idx14);
        res = (n3 && !n3->IsBit1()) || (n2 && !n2->IsBit1()) || (n1 && !n1->IsBit1());
    }
    return res;
}

}
}   // namespace f3m_008dfac0

// @f3 0x008dca30 (community match, verified in this file)
extern char DAT_010f3370;
namespace f3m_008dca30 {
namespace f3m_008dca30 {

struct UpdateFlag
{
    bool value;
    UpdateFlag(bool v) : value(v) {}
};

struct ModelItem;

struct ModelEffect
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int GetType();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60;
    int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80;
    int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0;
    int unka4; int unka8;
    float unkac;
    ModelEffect* FUN_0095b0f0();
    void FUN_0092b6d0(ModelItem* item, UpdateFlag flag);
    void hkpRagdollConstraintData_setMotorsActive(ModelItem* item, UpdateFlag flag);
    void FUN_00959ee0(void* data);
};

struct ModelItem
{
    int unk00;
    int unk04;
    int unk08;
    ModelEffect* effect;
};

struct ItemCount
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int count;
};

struct ItemTable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ModelItem** items;
    int unk18;
    int unk1c;
    int* indices;
    int unk24;
    int unk28;
    ItemCount* counts;
};

// pdb: bhkRagdollController::bhkRagdollPoweredConstraintController::startMotors | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: ragdoll
void __cdecl FUN_008dca30(ItemTable* table)
{
    int count = table->counts->count;
    for (int i = 0; i < count; i++)
    {
        int index = table->indices[i] - 1;
        if (index < 0)
            continue;
        ModelItem* item = table->items[index];
        if (!item)
            continue;
        ModelEffect* effect = item->effect;
        if (effect->GetType() == 13)
            effect = effect->FUN_0095b0f0();
        if (!effect)
            continue;
        switch (effect->GetType())
        {
        case 2:
            effect->FUN_0092b6d0(item, true);
            effect->unkac = 0.0f;
            break;
        case 7:
            effect->hkpRagdollConstraintData_setMotorsActive(item, true);
            effect->FUN_00959ee0(&DAT_010f3370);
            break;
        }
    }
}
}
}   // namespace f3m_008dca30

// @f3 0x008d9d50 (community match, verified in this file)
namespace f3m_008d9d50 {
extern unsigned long DAT_01179af4;
struct TlsBlock8d9d50 {
    unsigned int unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c;
    unsigned int unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c;
    unsigned int unk040,unk044,unk048,unk04c,unk050,unk054,unk058,unk05c;
    unsigned int unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c;
    unsigned int unk080,unk084,unk088,unk08c,unk090,unk094,unk098,unk09c;
    unsigned int unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc;
    unsigned int unk0c0,unk0c4,unk0c8,unk0cc,unk0d0,unk0d4,unk0d8,unk0dc;
    unsigned int unk0e0,unk0e4,unk0e8,unk0ec,unk0f0,unk0f4,unk0f8,unk0fc;
    unsigned int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;
    unsigned int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    unsigned int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;
    unsigned int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    unsigned int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;
    unsigned int unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc;
    unsigned int unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc;
    unsigned int unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc;
    unsigned int unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c;
    unsigned int unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c;
    unsigned int unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c;
    unsigned int unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c;
    unsigned int unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c;
    int state;
};

extern __declspec(thread) TlsBlock8d9d50 tlsBlock8d9d50;

struct NiAVObject { void UpdateWorldLoc(); };

struct O8d9d50 {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual bool v0b4();
    int unk04;
    NiAVObject* unk08;
    unsigned short flags0c;
    bool TestBit(unsigned int bit) const { return (flags0c >> bit) & 1; }
    void FUN_008d9d50(int arg);
};

// pdb: bhkNiCollisionObject::UpdateWorldData | bhkNiCollisionObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: __formal
void O8d9d50::FUN_008d9d50(int arg)
{
    if (tlsBlock8d9d50.state != 3) {
        if (TestBit(6)) {
            if (tlsBlock8d9d50.state != 2) {
                v0ac();
                v0a8();
                flags0c &= ~0x40;
                return;
            }
        } else if (TestBit(0)) {
            if (v0b4()) {
                if (tlsBlock8d9d50.state != 2) {
                    v0a8();
                    return;
                }
            } else if (tlsBlock8d9d50.state != 1) {
                v0a4();
                return;
            }
        }
    }
    if (unk08) unk08->UpdateWorldLoc();
}
}

// @f3 0x008dd390 (community match, verified in this file)
namespace Collect392 {
struct Type { const char* name; const Type* base; };
extern const Type DAT_010f31fc;
struct Object {
    virtual void slot00();
    virtual void slot04();
    virtual const Type* type() const;
    int unk04;
    void* value;
};
struct Link { Object* object; Link* next; };
struct Root : Object { int unk0c; int unk10; Link children; };
struct Array { void** data; int size; int capacity; };
extern "C" void __cdecl FUN_00901f10(void*, int);
static __forceinline void append(Array& a, void* value) {
    if(a.size==(a.capacity&0x3fffffff)) FUN_00901f10(&a,4);
    a.data[a.size++]=value;
}
static __forceinline bool isType(const Type* type) {
    while(type) {
        if(type==&DAT_010f31fc) return true;
        type=type->base;
    }
    return false;
}
// pdb: bhkRagdollController::AddToArrays | bhkRagdollController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
void __cdecl bhkRagdollController_AddToArrays(Root* root, Array& first, Array& second) {
    if(root) {
        append(first,root->value);
        Link* link=&root->children;
        while(link) {
            Object* object=link->object;
            if(!object) break;
            Object* cast=isType(object->type())?object:0;
            if(cast) append(second,cast->value);
            link=link->next;
        }
    }
}
}

// @f3 0x008dc690 (community match, verified in this file)
namespace f3m_008dc690 {
namespace Check393 {
struct Item {
virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c(); virtual int kind();
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
void* attached;
void* FUN_00959f80(); void* FUN_0095a000(); void* FUN_0095a020();
};
struct Entry { int unk00,unk04,unk08; Item* item; };
struct Group { int unk00,unk04,unk08,unk0c,unk10; Entry** entries; int count; };
struct Root {
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
Group* group;
int FUN_008dc690();
};
// pdb: bhkRagdollController::IsPoweredRagdoll | bhkRagdollController.obj | fnv360_0822_retail, call_dedup, medium
int Root::FUN_008dc690() {
 bool valid=true;
 Group* g=group;
 if(g) {
  for(int i=0;i<g->count && valid;++i) {
   Item* item=g->entries[i]->item;
   if(item->kind()==13 || item->kind()==12) valid=false;
   else switch(item->kind()) {
    case 2: if(!item->attached) valid=false; break;
    case 7: if(!item->FUN_00959f80() || !item->FUN_0095a000() || !item->FUN_0095a020()) valid=false; break;
   }
  }
 }
 return valid && group ? 1:0;
}
}
}   // namespace f3m_008dc690

// @f3 0x008da4c0 (community match, verified in this file)
namespace f3m_008da4c0 {
namespace Update400 {
struct State { float time; bool a,b,c,d,e; State():time(0),a(false),b(false),c(false),d(false),e(false){} };
struct Controller {
virtual void slot00();
virtual void slot04();
virtual void slot08();
virtual void slot0c();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1c();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2c();
virtual void slot30();
virtual void slot34();
virtual int active();
};
struct Node;
struct Children {
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
Node** data; unsigned short capacity,count;
};
struct Node {
virtual void slot00();
virtual void slot04();
virtual void slot08();
virtual Children* children();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1c();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2c();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3c();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4c();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5c();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6c();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7c();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8c();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9c();
virtual void slota0();
virtual void slota4();
virtual void slota8();
virtual void slotac();
virtual void slotb0();
virtual void slotb4();
virtual void update(State&);
virtual void finish();
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
Controller* controller;
void FUN_008330a0();
};
// pdb: bhkNiCollisionObject::SynchronizeRec | bhkNiCollisionObject.obj | fnv360_0822_retail, call_seq, low
// pdb params: apObject, abUpdate
void __cdecl FUN_008da4c0(Node* node,bool force) {
 if(node) {
  Controller* controller=node->controller;
  int active=controller ? controller->active():0;
  if(active || force) {
   node->FUN_008330a0();
   State state;
   node->update(state);
   force=true;
  }
  Children* children=node->children();
  if(children) for(unsigned int i=0;i<children->count;++i) FUN_008da4c0(children->data[i],force);
  node->finish();
 }
}
}



}   // namespace f3m_008da4c0

// @f3 0x008dc830 (community match, verified in this file)
extern const double DAT_00dc2f10;
namespace f3m_008dc830 {
namespace Copy410 {
struct Params {
int unk00;
float value04;
int unk08;
float value0c;
float value10;
int unk14;
float value18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
unsigned int value38;
unsigned int value3c;
};
struct Source { int unk00,unk04,unk08,unk0c,unk10,unk14; Params* params; };
struct Target { int unk00,unk04,unk08; float a,b; int unk14,unk18; float c; };
struct Owner {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
Target** targets;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
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
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
int unk260;
int unk264;
int unk268;
int unk26c;
int unk270;
int unk274;
int unk278;
int unk27c;
int unk280;
int unk284;
int unk288;
int unk28c;
float value;
int unk294;
unsigned int first;
unsigned int second;
int unk2a0;
Source* source;
void FUN_008dc830();
};
// pdb: bhkRagdollController::ResetDriveGains | bhkRagdollController.obj | fnv360_0822_retail, objrun, medium
void Owner::FUN_008dc830() {
 if(source->params) {
  Target* target=*targets;
  target->a=source->params->value10;
  target->b=source->params->value0c;
  target->c=source->params->value18;
  value=source->params->value04;
  second=static_cast<unsigned int>(static_cast<float>(source->params->value38)*0.25);
  first=static_cast<unsigned int>(static_cast<float>(source->params->value3c)*0.25);
 }
}
}

}   // namespace f3m_008dc830

// @f3 0x008d3f20 (community match, verified in this file)
namespace f3m_008d3f20 {
typedef void (__thiscall* Vfn8d3f20)(void*, float);
struct Item8d3f20 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v0x14(float value);
};
struct Class8d3f20 {
    char unk00[8];
    void* m_pField8;
    char unk0c[0x64];
    Item8d3f20** m_pArray70;
    int m_iCount74;
    void FUN_008d3f20(float value);
};
// pdb: bhkWorld::UpdateListeners | bhkWorld.obj | fnv360_1110_retail, objrun, medium
// pdb params: afDelta
void Class8d3f20::FUN_008d3f20(float value)
{
    if (m_pField8 == 0)
        return;
    for (int i = 0; i < m_iCount74; i++)
    {
        Item8d3f20* item = m_pArray70[i];
        if (item != 0 && value != 0.0f)
            item->v0x14(value);
    }
}
}   // namespace f3m_008d3f20

// @f3 0x008d49b0 (community match, verified in this file)
#include <string.h>
namespace f3m_008d49b0 {
struct Item8d49b0;
struct Sub8d49b0 { char pad[0x10]; unsigned flags; };
struct Item8d49b0 { char pad[0xc]; Sub8d49b0* sub; void FUN_009316f0(); };
struct Parent8d49b0 { void FUN_00906d80(Item8d49b0** arr, unsigned count); };
struct Owner8d49b0 {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual Parent8d49b0* parent();
    char pad2[0x50];
    Item8d49b0** arr;
    unsigned count;
    void FUN_008d49b0();
};
// pdb: PIXEndNamedEvent | pix.obj | fnv360_0822_debug, call_seq, low, conflict (bridge: bhkWorld::RemoveBatchedEntities)
void Owner8d49b0::FUN_008d49b0()
{
    if (count <= 0) return;
    if (count >= 3000) count = 3000;
    Parent8d49b0* p = parent();
    if (!p) return;
    p->FUN_00906d80(arr, count);
    for (unsigned i = 0; i < count; i++) {
        Item8d49b0* it = arr[i];
        if (it) { Sub8d49b0* s = it->sub; if (s) s->flags &= ~0x20; }
        arr[i]->FUN_009316f0();
    }
    memset(arr, 0, count * 4);
    count = 0;
}
}   // namespace f3m_008d49b0

// @f3 0x008d5790 (community match, verified in this file)
namespace f3m_008d5790 {
struct Rec8d5790 { int pad0; unsigned char f4; char pad5[3]; int f8; };
struct Child8d5790;
struct Parent8d5790 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34();
    virtual Parent8d5790* v38();
};
struct Obj8d5790 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual Child8d5790* v0c();
    char pad[0x18];
    Parent8d5790* unk1c;
    char pad2[0x10];
    unsigned flags30;
};
struct Child8d5790 {
    char pad[0xa0];
    Obj8d5790** arr;
    unsigned short unkA4;
    unsigned short count;
};
typedef void (*Cb8d5790)(Parent8d5790*, Rec8d5790*);
// pdb: bhkWorld::DoObjectRec | bhkWorld.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: bhkWorld::DoObjects)
// pdb params: apObject, arData, apFunc
void __cdecl FUN_008d5790(Obj8d5790* p, Rec8d5790* q, Cb8d5790 cb)
{
    if (!p) return;
    Parent8d5790* par = p->unk1c ? p->unk1c->v38() : 0;
    if (q->f8 == 0) p->flags30 = (p->flags30 & ~0x10) | 6;
    if (par) cb(par, q);
    if (q->f4) {
        Child8d5790* c = p->v0c();
        if (c) {
            for (unsigned i = 0; i < c->count; i++)
                FUN_008d5790(c->arr[i], q, cb);
        }
    }
}
}   // namespace f3m_008d5790

// @f3 0x008da3b0 (community match, verified in this file)
namespace f3m_008da3b0 {
struct Fn8da3b0Attach {
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
};

struct Fn8da3b0Obj {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual Fn8da3b0Attach* GetAttach();
};

struct Fn8da3b0Child;

struct Fn8da3b0Child {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual Fn8da3b0Child* GetChildren();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Fn8da3b0Obj* unk1C;
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
    Fn8da3b0Child** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

// pdb: bhkNiCollisionObject::ResetSim | bhkNiCollisionObject.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: NiAVObject::SetRotate)
// pdb params: apObject, abRecurse
void FUN_008da3b0(Fn8da3b0Child* node, bool flag)
{
    if (node == 0) {
        return;
    }
    Fn8da3b0Obj* obj = node->unk1C;
    if (obj != 0) {
        Fn8da3b0Attach* attach = obj->GetAttach();
        if (attach != 0) {
            attach->unk0C |= 0x40;
        }
    }
    if (flag) {
        Fn8da3b0Child* holder = node->GetChildren();
        if (holder != 0) {
            unsigned int k = holder->unkA6;
            if (k != 0) {
                do {
                    Fn8da3b0Child** items = holder->unkA0;
                    k = k - 1;
                    FUN_008da3b0(items[k], true);
                } while (k != 0);
            }
        }
    }
}


}   // namespace f3m_008da3b0

// @f3 0x008da5d0 (community match, verified in this file)
namespace f3m_008da5d0 {
struct Fn8da3b0Attach {
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C; unsigned short unk0e; void* object;
};

struct Fn8da3b0Obj {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual Fn8da3b0Attach* GetAttach();
};

struct Fn8da3b0Child;

struct Fn8da3b0Child {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual Fn8da3b0Child* GetChildren();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Fn8da3b0Obj* unk1C;
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
    Fn8da3b0Child** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

// pdb: bhkNiCollisionObject::SetRigidBodyName | bhkNiCollisionObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject
struct Body431 {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int value;}; struct Converted431 {int unk00,unk04; Body431* body;}; extern int DAT_010f3220; Converted431* FUN_00424d50(const void*,void*);void FUN_008da5d0(Fn8da3b0Child* node) {
 if(node) {
  Fn8da3b0Obj* obj=node->unk1C;
  if(obj) {
   Fn8da3b0Attach* attach=obj->GetAttach();
   if(attach && attach->object) {
    Converted431* converted=FUN_00424d50(&DAT_010f3220,attach->object);
    if(converted) converted->body->value=node->unk08;
   }
  }
  Fn8da3b0Child* parent=node->GetChildren();
  if(parent) {
   int count=parent->unkA6;
   for(int i=0;i<count;++i) FUN_008da5d0(parent->unkA0[i]);
  }
 }
}
}   // namespace f3m_008da5d0

// @f3 0x008dcae0 (community match, verified in this file)
namespace f3m_008dcae0 {
namespace f3m_008dcae0 {
struct Flag {unsigned char value;Flag(bool b):value(b){} Flag(const Flag& other):value(other.value){}};
struct Entry8DC;                                     
struct Counted8DC;                                   
struct GateSet8DC;                                   
struct Node8DC {                                     
    virtual void filler000();                        
    virtual void filler004();                        
    virtual void filler008();                        
    virtual void filler00C();                        
    virtual int kind010();                           
    struct Node8DC* FUN_0095b0f0();                  
    void hkpRagdollConstraintData_setMotorsActive(struct Entry8DC* entry, Flag flag);   
    void FUN_0092b6d0(struct Entry8DC* entry, Flag flag);   
};
struct Entry8DC { int unk00,unk04,unk08; struct Node8DC* node0C; };     
struct Counted8DC { int unk00,unk04,unk08,unk0c; int count10; };             
struct GateSet8DC {                                               
    int unk00,unk04,unk08,unk0c,unk10;                                
    void* table14;                                   
    int unk18,unk1c;                                   
    void* array20;                                   
    int unk24,unk28;                                   
    struct Counted8DC* counted2C;                    
};
extern "C" void FUN_008dcae0(struct GateSet8DC* set);             
// pdb: bhkRagdollController::bhkRagdollPoweredConstraintController::stopMotors | bhkRagdollController.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: ragdoll
void FUN_008dcae0(struct GateSet8DC* set) {          
    int count = set->counted2C->count10;             
    for (int index = 0; index < count; ++index) {    
        int key = (int)(((unsigned long*)set->array20)[index]);   
        --key; if(key<0)continue;                                       
        struct Entry8DC* entry = (struct Entry8DC*)(((unsigned long*)set->table14)[key]);   
        if (entry == 0) continue;                    
        struct Node8DC* node = entry->node0C;        
        if (node->kind010() == 13) node = node->FUN_0095b0f0();   
        if (node == 0) continue;                     
        int kind = node->kind010();                  
        switch(kind) {
         case 2: node->FUN_0092b6d0(entry,Flag(false));break;
         case 7: node->hkpRagdollConstraintData_setMotorsActive(entry,Flag(false));break;
        }
    }
}
}

}   // namespace f3m_008dcae0

// @f3 0x008d7790 (community match, verified in this file)
extern void* DAT_00f79488;                           
namespace f3m_008d7790 {
namespace f3m_008d7790 {
struct Gate8D7 {                                     
    unsigned long r00;                               
    unsigned long r04;                               
    unsigned long r08;unsigned long flags;                             
};
struct Local8D7 {                                    
    unsigned long slot00;                            
    unsigned char slot04;                            
    unsigned char slot05;                            
    unsigned char slot06;                            
    unsigned char slot07;                            
    unsigned long slot08;                            
    unsigned long rest0C;                            
    unsigned long rest10;
    unsigned long rest14;                            
    unsigned long rest18;                            
};
struct Gate8D7* __cdecl FUN_00aa60f0(void* input);   
void __cdecl FUN_008d5790(void* first, struct Local8D7* second, void* third);   
__forceinline unsigned allowed(void* input) {
 Gate8D7* gate=FUN_00aa60f0(input);
 return gate ? gate->flags&2 : 0;
}
// pdb: bhkWorld::UpdatePosition | bhkWorld.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap) + skyrim(objrun_sim), high
bool bhkWorld_UpdatePosition(void* first,unsigned char second,bool third) {
 bool answer=false;
 if(first && (third || allowed(first))) {
  Local8D7 local;
  local.slot04=second;
  void* globalValue=DAT_00f79488;
  answer=true;
  local.slot00=0;
  local.slot08=2;
  if(globalValue)FUN_008d5790(first,&local,globalValue);
 }
 return answer;
}
}
}   // namespace f3m_008d7790

// @f3 0x008d7c10 (community match, verified in this file)
// Model for 0x008d7c10 (108 bytes), claim clm_1fdc270dfacb4ff7abdc.
// Sibling family spelling taken from this packs own verified model at unit line 4042-4047
// (FUN_008d79d0): Info record with flags dword at +C, inline Enabled mask, Context local
// sized so the frame reservation comes out 1Ch.
namespace f3m_008d7c10 {
struct Object;
struct Info { unsigned unk00, unk04, unk08, flags; };
Info* __cdecl FUN_00aa60f0(Object*);
inline unsigned Enabled(Object* p) { Info* f = FUN_00aa60f0(p); return f ? (f->flags & 2) : 0; }
struct Context { void* current; unsigned char recurse; unsigned traversal; int value; int unk10, unk14, unk18; };
typedef void (__cdecl *Callback)(Object*, Context*);
extern Callback DAT_00f7949c;
void __cdecl FUN_008d5790(Object*, Context*, Callback);
// pdb: bhkWorld::SetGroup | bhkWorld.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: bhkWorld::SetCollisionGroup)
// pdb params: apObject, aiGroup, abRecurse, abForce
bool __cdecl FUN_008d7c10(Object* object, int value, unsigned char recurse, unsigned char force)
{
    bool result = false;
    if (object && (force || Enabled(object))) {
        Context context;
        result = true;
        context.current = 0;
        context.recurse = recurse;
        context.traversal = 7;
        context.value = value;
        if (DAT_00f7949c) FUN_008d5790(object, &context, DAT_00f7949c);
    }
    return result;
}
}

// @f3 0x008dd320 (community match, verified in this file)
namespace f3m_008dd320 {
// Model v3 for 0x008dd320 (110 bytes), claim clm_43ce5bc4bcf740efa8a3.
// Back to the v1 shape (v2 computed both conversions early and grew an extra push ebx/pop ebx pair).
// Two measured fixes: the f43 clear is written before the f222 store to match their order, and the
// second not-zero conversion is held in an int carrier whose byte store is spelled twice - measured
// locally in probe\saE_boolprobe6.cpp variantAK, where VC8 deletes one store yet still materialises
// the value with xor plus a compare of the byte field against that register, exactly as their build does.
namespace f3m_008dd320 {
struct Rel4C { void FUN_0095b310(); };

struct Owner8DD {
    char pad00[0x41];                    // +000 .. +040
    unsigned char f41, f42, f43;         // +041, +042, +043
    char pad44[8];                       // +044 .. +04B
    Rel4C* rel4c;                        // +04C
    char pad50[0x1CD];                   // +050 .. +021C
    unsigned char f21d, f21e;            // +021D, +021E
    char gap21f;                         // +021F unused
    unsigned char f220;                  // +0220
    char gap221;                         // +0221 unused
    unsigned char f222, f223;            // +0222, +0223
    char pad224[0x6A];                   // +0224 .. +028D
    unsigned char f28e;                  // +028E

    void FUN_008dd320();
};

// pdb: bhkRagdollController::EnableRagdollAnim | bhkRagdollController.obj | fnv360_0822_retail, call_dedup, medium
void Owner8DD::FUN_008dd320()
{
    if (f41 == 0) {
        if (rel4c != 0) rel4c->FUN_0095b310();
    }
    unsigned char prev = f222;
    unsigned char copied = f42;
    f41 = copied;
    unsigned int wide = (f220 != 0);
    f43 = 0;
    f222 = (unsigned char)wide;
    if (prev != 0 && !(char)wide) { f223 = 1; }
    unsigned int other = (f21d != 0);
    f21e = (unsigned char)other;
    f21e = (unsigned char)other;
    if (f28e == 0 && copied != 0) reinterpret_cast<FUN_008dc980*>(this)->Update(false);
}
}
}   // namespace f3m_008dd320

// @f3 0x008d7880 (community match, verified in this file)
namespace f3m_008d7880 {
// Model of FUN_008d7880 (109 B) - PORTED from the verified sibling body this very unit carries at line 4042
// (FUN_008d79d0: struct Flags {unsigned unk00,unk04,unk08,flags;}; inline Enabled(p){return f ? (f->flags & 2) : 0;}
// used inside the short-circuit OR force || Enabled(object)). That verified body compiled to their exact
// mov eax,[eax+0Ch] ; and eax,2 ; je tail triple, so the corpus bit-test fold does NOT apply when the mask
// arrives as a VALUE from an inline predicate - which is what my earlier hand-made-type attempts lacked.
// Shape read from shipped bytes: cdecl, four stack params, byte answer kept in BL across one shared exit;
// param1 null exits zero; param4 byte-compared against that cleared register skips both gate checks;
// lookup FUN_00aa60f0 (caller cleans 4); record = count 0 / active byte / type immediate 3 / value widened byte;
// global slot DAT_00f7948c loaded and tested, answer set to ONE before that test branches away, then
// FUN_008d5790(object, &record, slot) with add esp,0Ch.

namespace f3m_008d7880 {
namespace Query8d7880 {
struct State {int unk00,unk04,unk08;unsigned flags;};
struct Query {int count;bool active;int type;int value;int unk10,unk14,unk18;};
State* __cdecl FUN_00aa60f0(void*);
inline unsigned maskedState(void* object) { State* state = FUN_00aa60f0(object); return state ? state->flags & 2 : 0; }
typedef void (__cdecl *Callback)(void*,Query*);extern Callback DAT_00f7948c;
void __cdecl FUN_008d5790(void*,Query*,Callback);
// pdb: bhkWorld::Enable | bhkWorld.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, abEnable, abRecurse, abForce
bool __cdecl FUN_008d7880(void* object,unsigned char value,bool active,bool force) {
 bool result=false;
 if(object) {
  State* state;
  if(force || maskedState(object)) {
   result=true;
   Query query;
   query.count=0;
   query.active=active;
   query.type=3;
   query.value=value;
   if(DAT_00f7948c) FUN_008d5790(object,&query,DAT_00f7948c);
  }
 }
 return result;
}
}
}
}   // namespace f3m_008d7880

// @f3 0x008d7d00 (community match, verified in this file)
namespace f3m_008d7d00 {
// Model of FUN_008d7d00 (116 B) - third sibling in this unit; spelling ported from the verified body at pack
// line 4042 (State/Flags struct plus inline mask predicate inside force OR maskedState(object)), which reproduced
// mov eax,[eax+0Ch] ; and eax,2 ; je tail byte-exactly on my entry 0x8d7880 one pass ago.
// Shipped shape: cdecl five stack params; sub esp,1Ch with no stack cookie; answer kept in BL through ONE shared
// exit (mov al,bl); param1 null exits zero; param5 byte-compared against that cleared register skips both gate
// checks; lookup FUN_00aa60f0 caller-cleans 4; record = count 0 / active byte at +4 / type immediate 9 /
// param3 dword at +0xC / param2 dword at +0x10, with loads emitted in source order param4, param3, param2;
// global slot DAT_00f794a4 loaded and tested, answer set to ONE before that test branches away; then
// FUN_008d5790(object,&record,slot) with add esp,0Ch.

namespace f3m_008d7d00 {
namespace Query8d7d00 {
struct State {int unk00,unk04,unk08;unsigned flags;};
struct Query {int count;bool active;int type;int valueC;int value10;int unk14,unk18;};
State* __cdecl FUN_00aa60f0(void*);
inline unsigned maskedState(void* object) { State* state = FUN_00aa60f0(object); return state ? state->flags & 2 : 0; }
typedef void (__cdecl *Callback)(void*,Query*);extern Callback DAT_00f794a4;
void __cdecl FUN_008d5790(void*,Query*,Callback);
// pdb: bhkWorld::ChangeLayer | bhkWorld.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apObject, aeTo, aeFrom, abRecurse, abForce
bool __cdecl FUN_008d7d00(void* object,unsigned int second,unsigned int third,bool active,bool force) {
 bool result=false;
 if(object) {
  State* state;
  if(force || maskedState(object)) {
   result=true;
   Query query;
   query.count=0;
   query.active=active;
   query.type=9;
   query.valueC=third;
   query.value10=second;
   if(DAT_00f794a4) FUN_008d5790(object,&query,DAT_00f794a4);
  }
 }
 return result;
}
}
}
}   // namespace f3m_008d7d00

// @f3 0x008d9100 (community match, verified in this file)
namespace f3m_008d9100 {
struct Obj_8d9100
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual int v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0(float dt);
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

struct RefPtr_8d9100
{
    Obj_8d9100* m_pObject;
    RefPtr_8d9100(Obj_8d9100* pObject) : m_pObject(pObject)
    {
        m_pObject->IncRefCount();
    }
    ~RefPtr_8d9100()
    {
        int z = 0;
        if (z)
            m_pObject->DecRefCount();
    }
};

struct List_8d9100
{
    Obj_8d9100* m_item;
    List_8d9100* m_pkNext;
    void FUN_004c25a0(const RefPtr_8d9100* ptr);
};

struct World_8d9100
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    List_8d9100 refs90;
    void FUN_008d9100(float dt);
};

// pdb: bhkWorld::UpdateActions | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: afDelta
void World_8d9100::FUN_008d9100(float dt)
{
    List_8d9100* node = &refs90;
    while (node && (node->m_pkNext || node->m_item))
    {
        List_8d9100* next = node->m_pkNext;
        Obj_8d9100* obj = node->m_item;
        if (obj)
        {
            if (!obj->v98())
            {
                if (node == &refs90)
                    next = node;
                {
                    RefPtr_8d9100 sp(obj);
                    refs90.FUN_004c25a0(&sp);
                }
                obj->DecRefCount();
            }
            else
            {
                obj->vc0(dt);
            }
        }
        node = next;
    }
}
}   // namespace f3m_008d9100

// @f3 0x008dc750 (community match, verified in this file)
namespace f3m_008dc750 {
// Model of FUN_008dc750 (224 B, thiscall, plain ret, no arguments) - v2 fixes one layout slip: v1 measured
// 224 versus 224 extents with thirteen flagged lines, and every one of them was a relocation hunk except the
// channel load, which came out plus-2A0h against their plus-2A4h because my padding stopped one dword short.
// Their object therefore carries an unmodelled dword at plus-2A0h between the two unsigned results and the
// channel pointer. No sibling and no declaration for this entry anywhere in the unit, so types are declared
// here from the shipped bytes. Screened clean: zero calls, zero inline math opcodes - all x87 work is
// fld/fmul/fstp/fild/fistp plus the fnstcw or 0C00h fldcw dance, which this spelling reproduces byte-exactly.
// Chain read off capstone operands: this plus 2A4h then plus 18h gives a record whose floats at plus-0C,
// plus-10 and plus-18 are scaled by the pool doubles double(0.3f) at dc8060, double(0.1f) at dc0ac8 and a
// qword zero at db38b0, landing in an object reached through this plus 4Ch with ONE dereference, at its
// offsets plus-0C, plus-10 and plus-1C. That target is loaded once (eax stays live over all three stores)
// while the record chain is re-read per statement, so only the target is cached in a local. The last two
// statements: fild then conditional fadd of float 4294967296 at db5744 proves an UNSIGNED int to double
// conversion, times pool double 0.25 at dc2f10, cast back with the inline unsigned dance into plus-29C and
// plus-298 as dwords, so both are unsigned members.

namespace f3m_008dc750 {
struct SrcRecord {
    char pad00[12];
    float at0C, at10;
    char pad14[4];
    float at18;
    char pad1C[28];
    int at38, at3C;
};
struct ChannelSet {
    char pad00[24];
    SrcRecord* record;
};
struct RenderTarget {
    char pad00[12];
    float at0C, at10;
    char pad14[8];
    float at1C;
};
struct PoseController {
    char pad00[76];
    RenderTarget** target;
    char pad50[584];
    unsigned int at298, at29C;
    char pad2A0[4];
    ChannelSet* channel;
    void FUN_008dc750();
};

// pdb: bhkRagdollController::DampenDriveGains | bhkRagdollController.obj | fnv360_0822_retail, objrun, medium
void PoseController::FUN_008dc750() {
    SrcRecord* record = channel->record;
    if (record) {
        RenderTarget* out = *target;
        out->at0C = channel->record->at10 * 0.3f;
        out->at10 = channel->record->at0C * 0.1f;
        out->at1C = channel->record->at18 * 0.0f;
        at29C = (unsigned)((unsigned)channel->record->at38 * 0.25f);
        at298 = (unsigned)((unsigned)channel->record->at3C * 0.25f);
    }
}
}
}   // namespace f3m_008dc750

// @f3 0x008d60a0 (community match, verified in this file)
namespace f3m_008d60a0 {
namespace f3m_008d60a0 {
struct Phantom8d60 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned char m_14;
};
struct Entity8d60 {
    int unk00;
    int unk04;
    int unk08;
    Phantom8d60* m_c;
    void FUN_009316e0();
};
struct Ctx8d60 {
    void FUN_009028d0(Entity8d60*);
};
struct Owner8d60 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual Ctx8d60* GetContext();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int m_deferred;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    Entity8d60** m_phantoms;
    unsigned int m_phantomCount;
    void FUN_008d4c10();
    void FUN_008d4b60();
    void FUN_008d4ad0();
    void FUN_008d4a40();
    bool FUN_008d60a0(Entity8d60* entity);
};

// pdb: bhkWorld::Remove | bhkWorld.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: bhkWorld::SaveSnapshot)
// pdb params: apPhantom
bool Owner8d60::FUN_008d60a0(Entity8d60* entity)
{
    bool result = false;
    Ctx8d60* ctx = GetContext();
    if (ctx && entity) {
        result = true;
        if (m_deferred > 0) {
            Phantom8d60* phantom = entity->m_c;
            if (!phantom || (phantom->m_14 & 0x30))
                return result;
            phantom->m_14 |= 0x20;
            if (m_phantomCount >= 200) {
                FUN_008d4c10();
                FUN_008d4b60();
                FUN_008d4ad0();
                FUN_008d4a40();
            }
            entity->FUN_009316e0();
            m_phantoms[m_phantomCount] = entity;
            ++m_phantomCount;
        } else {
            Phantom8d60* phantom = entity->m_c;
            if (!phantom || (phantom->m_14 & 0x30))
                return result;
            ctx->FUN_009028d0(entity);
        }
    }
    return result;
}
}
}   // namespace f3m_008d60a0

// @f3 0x008d8af0 (community match, verified in this file)
namespace f3m_008d8af0 {


struct __declspec(align(16)) Vec { float x,y,z,w; };
extern Vec DAT_01092a50;
extern const float DAT_00db7df0;
struct hkBool { char m_bool; hkBool(bool b) { m_bool=(char)b; } operator bool() const { return m_bool!=0; } };
static __forceinline void memSet(void* d,int v,int n) { memset(d,v,n); }
extern unsigned DAT_00f7947c;
extern bool DAT_010f2a62;
struct Scene {
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
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    unsigned unkdc;
    unsigned unke0;
    unsigned unke4;
    unsigned unke8;
    unsigned unkec;
    unsigned unkf0;
    unsigned unkf4;
    unsigned unkf8;
    unsigned unkfc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    Vec pos, rot;
    void FUN_0090b500();
};
struct Body { unsigned unk00,unk04; Scene* unk08; unsigned unk0c,unk10; };
struct Group { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; unsigned short unk20; hkBool isFree() const { return unk20==0xffff; } };
struct Entity {
    unsigned unk00,unk04,unk08; Body* unk0c;
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
    Group* unkB8;
    void FUN_009316f0();
};
struct World {
    void hkpWorld_addEntityBatch(Entity**,unsigned,int);
    hkBool FUN_009037f0(Entity*);
    void FUN_00907120(void*);
};
void __cdecl FUN_00929570(World*,Group*);
struct Ref {
    virtual void v0(); virtual void destroy();
    long refs;
};
struct Input { unsigned unk00; unsigned short unk04,unk06; unsigned unk08,unk0c; Ref* unk10; };
struct RefPtr;
struct Owner { Ref* unk00; void FUN_008f2610(const RefPtr&); };
struct RefPtr {
    Ref* p;
    RefPtr(Ref* q):p(q) { InterlockedIncrement(&q->refs); }
    ~RefPtr() { if(!InterlockedDecrement(&p->refs)) p->destroy(); }
};
void __cdecl OwnerStore(Owner*,Ref*);
__declspec(noinline) void Owner::FUN_008f2610(const RefPtr& r) { OwnerStore(this,r.p); }
struct Manager {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual World* world();
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
    Entity** unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    Input** unk44;
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
    Owner unk90;
    void FUN_008d5db0(); void FUN_008d6290(); void FUN_008d48d0();
    void FUN_008d8af0(Input*);
};
static __forceinline void difference(Vec& r,const Vec& a,const Vec& b) {
     r.x=a.x-b.x;r.y=a.y-b.y;r.z=a.z-b.z;r.w=a.w-b.w;
}
static __forceinline void absolute(Vec& v) {
    float f;
    f=(float)fabs(v.x);v.x=f; f=(float)fabs(v.y);v.y=f;
    f=(float)fabs(v.z);v.z=f; f=(float)fabs(v.w);v.w=f;
}
static __forceinline unsigned mask(const Vec& v,const Vec& t) {
    return (v.x<=t.x?8:0)|(v.y<=t.y?4:0)|(v.z<=t.z?2:0)|(v.w<=t.w?1:0);
}
static __forceinline bool equals3(const Vec& a,const Vec& b,float epsilon) {
    Vec t; difference(t,a,b); absolute(t);
    Vec e; e.x=epsilon; e.y=epsilon; e.z=epsilon; e.w=epsilon;
    return (mask(t,e)&14)==14;
}
// pdb: bhkWorld::Add | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: apObject
void Manager::FUN_008d8af0(Input* input) {
    if (!this) return;
    World* initial=world();
    if (initial) {
        if (unk20>0) {
            if(unk48>=100) {
                if(unk38>0 && !DAT_010f2a62) {
                    if(unk38>=3000) unk38=3000;
                    unsigned count=unk38<DAT_00f7947c?unk38:DAT_00f7947c;
                    unsigned start=unk38-count;
                    World* w=world();
                    if(w) {
                        w->hkpWorld_addEntityBatch(unk34+start,count,0);
                        bool did=false;
                        for(unsigned i=start;i<unk38;++i) {
                            
                                                        Entity* e=unk34[i];
 Body* b=e?e->unk0c:0;
                            if(b) b->unk10 &= ~16;
                            else { w->FUN_009037f0(unk34[i]); }
                            if(!did) {
                                Group* g=unk34[i]->unkB8;
                                if(g && !g->isFree()) { FUN_00929570(w,g);did=true; }
                            }
                            const Vec* v=b && b->unk08?&b->unk08->pos:&DAT_01092a50;
                            if(equals3(*v,DAT_01092a50,0.001f)) {
                                v=b && b->unk08?&b->unk08->rot:&DAT_01092a50;
                                if(equals3(*v,DAT_01092a50,0.001f)) goto unchanged;
                            }
                            if(b && b->unk08)b->unk08->FUN_0090b500();
                            unchanged:
                            unk34[i]->FUN_009316f0();
                        }
                        memSet(unk34+start,0,count*4);
                        unk38=start;
                    }
                    DAT_010f2a62=true;
                }
                FUN_008d5db0(); FUN_008d6290(); FUN_008d48d0();
            }
            if(input->unk04)++input->unk06;
            unk44[unk48++]=input;
        } else { initial->FUN_00907120(input); }
        if(input && input->unk10) { RefPtr ref(input->unk10); unk90.FUN_008f2610(ref); }
    }
}
}   // namespace f3m_008d8af0

// @f3 0x008d6ba0 (community match, verified in this file)
namespace f3m_008d6ba0 {
extern unsigned int DAT_010f3170;
struct Allocator6ba0 { void FUN_008f6d90(void* p, int bytes, int tag); };
extern Allocator6ba0* (__stdcall* DAT_00d9b080)(unsigned long);

struct Vec6ba0 {
    float x, y, z, w;
};
struct __declspec(align(16)) AVec6ba0 : Vec6ba0 {
};
struct Array6ba0 {
    void* data;
    int size;
    int capacityAndFlags;
    Array6ba0() : data(0), size(0), capacityAndFlags(0x80000000) {}
    ~Array6ba0()
    {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int cap = capacityAndFlags & 0x3fffffff;
            Allocator6ba0* a = DAT_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(data, cap * 4, 0x17);
        }
    }
};
struct Target6ba0 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
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
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    Vec6ba0 a;
    Vec6ba0 b;
    void FUN_00902450(const Vec6ba0* delta, Vec6ba0* out, Array6ba0* arr);
};
struct Owner6ba0 {
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual Target6ba0* v98();
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
    Vec6ba0 pos;
    void FUN_008d4cc0();
    void FUN_008d6ba0(const Vec6ba0* target);
};
// pdb: bhkWorld::SethkOrigin | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arOrigin
void Owner6ba0::FUN_008d6ba0(const Vec6ba0* target)
{
    Array6ba0 arr;
    AVec6ba0 delta;
    delta.x = target->x - pos.x;
    delta.y = target->y - pos.y;
    delta.z = target->z - pos.z;
    delta.w = target->w - pos.w;
    Target6ba0* t = v98();
    v98();
    AVec6ba0 out;
    t->FUN_00902450(&delta, &out, &arr);
    pos.x += out.x;
    pos.y += out.y;
    pos.z += out.z;
    pos.w += out.w;
    t->a.x += out.x;
    t->a.y += out.y;
    t->a.z += out.z;
    t->a.w += out.w;
    Vec6ba0* b = &t->b;
    b->x += out.x;
    b->y += out.y;
    b->z += out.z;
    b->w += out.w;
    FUN_008d4cc0();
    v98();
}
}

// @f3 0x008c9c20 (community match, verified in this file)
struct RttiC9CG {
    const char* name;
    struct RttiC9CG* base;
};

extern RttiC9CG DAT_01092688;

namespace f3m_008c9c20 {

struct ObjC9C {
    void* vtbl;
    virtual void slot00();
    virtual void slot04();
    virtual RttiC9CG* GetRTTI();
};

struct Rec16 {
    unsigned int at00;
    unsigned int at04;
    unsigned int at08;
    unsigned int at0c;
};

struct StreamC9C {
    unsigned u00,u04,u08;
    Rec16 record0C;
    unsigned u1c,u20,u24;
};

struct OwnerC9C {
    unsigned u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38;
    StreamC9C* stream3C;
    void FUN_008c9c20(ObjC9C* probe, ObjC9C* unused);
};

struct RecvC9C {
    void FUN_008b73d0(Rec16 record);
};

__forceinline bool IsC9C(RttiC9CG* walk) {
    while(walk) {
        if(walk==&DAT_01092688) return true;
        walk=walk->base;
    }
    return false;
}
__forceinline RecvC9C* CastC9C(ObjC9C* probe) {
    if(!probe) return 0;
    return IsC9C(probe->GetRTTI()) ? reinterpret_cast<RecvC9C*>(probe) : 0;
}
// pdb: NiColorExtraDataController::SynchronizePoseInterpolator | NiColorExtraDataController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkInterp, usIndex
void OwnerC9C::FUN_008c9c20(ObjC9C* probe, ObjC9C* unused) {
    RecvC9C* receiver=CastC9C(probe);
    receiver->FUN_008b73d0(stream3C->record0C);
}
}

// @f3 0x008dc5e0 (community match, verified in this file)
extern const double DAT_00db88e8;
namespace f3m_008dc5e0 {
namespace match672 {
struct Matrix;
struct __declspec(align(16)) Vec4 {float x,y,z,w;void Set(const Vec4& v){x=v.x;y=v.y;z=v.z;w=v.w;}void FUN_008d2b00(const Matrix*,const Vec4*);};
struct Matrix {Vec4 a,b,c;};
struct Source {const Vec4* FUN_00956290(int);};
struct Skeleton {unsigned u00,u04,u08,u0c;Matrix* data;unsigned u14,u18;unsigned* flags;Matrix* hkaPose_calculateBoneModelSpace(int);Matrix* Get(int index){if(!(flags[index]&2))return data+index;return hkaPose_calculateBoneModelSpace(index);}};
struct Vec3{float x,y,z;};
struct Owner {
 unsigned u000;
 unsigned u004;
 unsigned u008;
 unsigned u00c;
 Matrix transform;
 unsigned u040;
 unsigned u044;
 unsigned u048;
 unsigned u04c;
 unsigned u050;
 unsigned u054;
 unsigned u058;
 unsigned u05c;
 unsigned u060;
 unsigned u064;
 unsigned u068;
 unsigned u06c;
 unsigned u070;
 unsigned u074;
 unsigned u078;
 unsigned u07c;
 unsigned u080;
 unsigned u084;
 Skeleton* skeleton;
 unsigned u08c;
 unsigned u090;
 unsigned u094;
 unsigned u098;
 unsigned u09c;
 unsigned u0a0;
 unsigned u0a4;
 unsigned u0a8;
 unsigned u0ac;
 unsigned u0b0;
 unsigned u0b4;
 unsigned u0b8;
 unsigned u0bc;
 unsigned u0c0;
 unsigned u0c4;
 unsigned u0c8;
 unsigned u0cc;
 unsigned u0d0;
 unsigned u0d4;
 unsigned u0d8;
 unsigned u0dc;
 unsigned u0e0;
 unsigned u0e4;
 unsigned u0e8;
 unsigned u0ec;
 Source* source;
 unsigned u0f4;
 unsigned u0f8;
 unsigned u0fc;
 unsigned u100;
 unsigned u104;
 unsigned u108;
 unsigned u10c;
 unsigned u110;
 unsigned u114;
 unsigned u118;
 unsigned u11c;
 unsigned u120;
 unsigned u124;
 unsigned u128;
 unsigned u12c;
 unsigned u130;
 unsigned u134;
 unsigned u138;
 unsigned u13c;
 unsigned u140;
 short index;unsigned short u146;
 unsigned u148;
 unsigned u14c;
 unsigned u150;
 unsigned u154;
 unsigned u158;
 unsigned u15c;
 unsigned u160;
 unsigned u164;
 unsigned u168;
 unsigned u16c;
 unsigned u170;
 unsigned u174;
 unsigned u178;
 unsigned u17c;
 unsigned u180;
 unsigned u184;
 unsigned u188;
 unsigned u18c;
 bool active;
 bool FUN_008dc5e0(Vec3*);
};
// pdb: bhkRagdollController::GetEyeOffset | bhkRagdollController.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arOffset
bool Owner::FUN_008dc5e0(Vec3* out){
 bool result=false;
 if(active){
 Vec4 value;value.Set(*source->FUN_00956290(1));
 value.FUN_008d2b00(skeleton->Get(index),&value);
 value.FUN_008d2b00(&transform,&value);
 const double scale=6.999040126800537;
 out->x=value.x*scale;out->y=value.y*scale;out->z=value.z*scale;
 result=true;}
 return result;
}
}



}   // namespace f3m_008dc5e0

// @f3 0x008d48d0 (community match, verified in this file)
namespace f3m_008d48d0 {
namespace Process408 {
struct Body {
int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int active;
};
struct Item { virtual void destroy(unsigned int); unsigned short managed; short refs; void* owner; int unk0c; int unk10; Body* first; Body* second; };
struct Consumer { void FUN_009082b0(Item*); };
extern "C" void* __cdecl FUN_00c00610(void*,int,unsigned int);
struct Owner {
virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2c();
virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3c();
virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4c();
virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5c();
virtual void slot60(); virtual void slot64(); virtual void slot68(); virtual void slot6c();
virtual void slot70(); virtual void slot74(); virtual void slot78(); virtual void slot7c();
virtual void slot80(); virtual void slot84(); virtual void slot88(); virtual void slot8c();
virtual void slot90(); virtual void slot94(); virtual Consumer* consumer();
int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
int unk40; int unk44; int unk48;
Item** items; unsigned int count;
void FUN_008d48d0();
};
// pdb: bhkWorld::AddBatchedConstraints | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void Owner::FUN_008d48d0() {
 if(count>0u) {
  if(!unk38) {
   if(count>=200u) count=200u;
   Consumer* sink=consumer();
   if(sink) {
    for(unsigned int i=0;i<count;++i) {
     if(items[i]!=0) {
      Item* v=items[i];
      if(!v->owner&&(!v->first||v->first->active)&&(!v->second||v->second->active)) sink->FUN_009082b0(v);
     }
     if(items[i]!=0) {
      Item* w=items[i];
      if(w->managed&&--w->refs==0) w->destroy(1);
     }
    }
    FUN_00c00610(items,0,count*4);
    count=0;
   }
  }
 }
}
}
}   // namespace f3m_008d48d0

// @f3 0x008dd250 (community match, verified in this file)
namespace Cleanup403 {
namespace f3m_008dd250 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); }
struct FreeList { void* head; int count; };
struct Memory {
int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
int unk20; int unk24; int unk28; int unk2c; int unk30; int limit;
FreeList lists[5];
void FUN_008f6890(int,void*,int);
void FUN_008f6f90(void*);
};
struct Manager { void FUN_0086ba60(void*); };
extern Manager DAT_01090a78;
typedef void* (__stdcall* TlsFn)(unsigned long);
static __forceinline Memory* memory(TlsFn fn) { return static_cast<Memory*>(fn(f3m_008dd250::DAT_010f3170)); }
template<int Kind> static __forceinline void release(void* object, TlsFn fn) {
 if(object) {
  Memory* m=memory(fn);
  if(m->lists[Kind].count>=m->limit) m->FUN_008f6890(Kind,object,59);
  else {
   FreeList& l=m->lists[Kind];
   void* next=l.head;
   ++l.count;
   *static_cast<void**>(object)=next;
   l.head=object;
  }
 }
}
struct Data { int unk00; void* buffer; int unk08; void** items; int count; void* block; };
struct Owner { Data* data; void FUN_008dd250(); };
void Owner::FUN_008dd250() {
 if(data) {
  TlsFn fn=f3m_008dd250::DAT_00d9b080;
  for(int i=0;i<data->count;++i) release<1>(data->items[i],fn);
  DAT_01090a78.FUN_0086ba60(data->items);
  void* block=data->block;
  Memory* m=memory(fn);
  m->FUN_008f6f90(block);
  DAT_01090a78.FUN_0086ba60(data->buffer);
  release<4>(data,fn);
 }
}
}

// @f3 0x008d3f70 (community match, verified in this file)
extern unsigned int DAT_00f79e58;
extern unsigned int DAT_010f2ee8[];
namespace f3m_008d3f70 {
struct HandleOwnerD3F {
    void* unk00;
    void* unk04;
    void* controller08;
};

struct SlotRecD3F {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int value1C;
};

struct StateD3F {
    void* object00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags0C;
    unsigned int handle10;
    unsigned int count14;
    unsigned int flag18;
};


namespace f3m_008d3f70 {

struct NotifyRecv {
    bool FUN_008f9b90(unsigned int value);
};

// pdb: bhkWorld::SetCollisionGroup | bhkWorld.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apObject, arData
unsigned char __cdecl FUN_008d3f70(HandleOwnerD3F* object, StateD3F* state)
{
    unsigned char notified = 0;
    unsigned int raw;
    if (object != 0) {
        void* held = object->controller08;
        if (held != 0) {
            char* shifted = (char*)held + 0x10;
            if (shifted != 0) {
                raw = ((SlotRecD3F*)shifted)->value1C;
            } else {
                raw = 0;
            }
        } else {
            raw = 0;
        }
    } else {
        raw = 0;
    }

    unsigned int answer = raw >> 16;
    if (state->handle10 == 0) {
        if (answer == 0) {
            unsigned int index = raw & 0x7f;
            answer = DAT_010f2ee8[index];
            if (answer == 0) {
                unsigned int next = (DAT_00f79e58 + 1) & 0xffff;
                DAT_00f79e58 = next;
                if (next == 0) {
                    next = 0xa;
                    DAT_00f79e58 = next;
                }

                answer = next;
            }

            notified = 1;
        }

        state->handle10 = answer;
    } else {
        answer = *(volatile unsigned int*)&state->handle10;
        notified = 1;
    }

    if (notified) {
        ((NotifyRecv*)object)->FUN_008f9b90(answer);
    }

    return notified;
}
}
}   // namespace f3m_008d3f70

// @f3 0x008da580 (community match, verified in this file)
namespace f3m_008da580 {
struct Sub161 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    unsigned int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    unsigned int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    unsigned int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    unsigned int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4;
    unsigned char kind;
};
struct Base161 {
    unsigned int unk00,unk04,unk08,unk0c;
    signed char offset;
    unsigned char unk11;
    unsigned short unk12;
    unsigned int unk14;
    unsigned char flag;
};
struct Inner161 {
    unsigned int unk00,unk04,unk08,unk0c;
    Base161 base;
    Base161* GetBase() { if(this) return &base; return 0; }
};

struct Node161 {
    unsigned int unk00,unk04;
    Inner161* inner;
    Sub161* GetSub() {
        if(this) {
            Base161* base=inner->GetBase();
            return (base->flag==1) ? reinterpret_cast<Sub161*>(reinterpret_cast<char*>(base)+base->offset) : 0;
        }
        return 0;
    }
};
struct Owner161 {
    unsigned int unk00,unk04,unk08,unk0c;
    Node161* node;
    bool FUN_008da580();
};
// pdb: bhkNiCollisionObject::QKeyframe | bhkNiCollisionObject.obj | fnv360_0822_retail, objrun, medium
bool Owner161::FUN_008da580() {
    bool result=true;
    Sub161* sub=node ? node->GetSub() : 0;
    if(sub) { int kind=sub->kind; result=kind==6 || kind==7; }
    return result;
}
}   // namespace f3m_008da580

// @f3 0x008d2120 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*,long,long);

namespace N8d2120 {

class NiPoint3
{
  public:
    float x, y, z;
};
class ThreeByThreeMatrix
{
  public:
    float entry[3][3];
};
struct Transform
{
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
};
class NiAVObject
{
  public:
    void* vtable;
    int refCount;
    const char* name;
    void* extraData;
    int extraCount;
    void* controller;
    NiAVObject* parent;
    void* collision;
    void* worldBound;
    void* propertyHead;
    void* propertyTail;
    int propertyCount;
    unsigned int flags;
    Transform local;
    Transform world;
    void FUN_008330a0();
};
struct Quaternion
{
    float w, x, y, z;
    void FUN_00837260(const ThreeByThreeMatrix*);
};
struct __declspec(align(16)) FourFloatVector
{
    float x, y, z, w;
};
struct __declspec(align(16)) HavokQuaternion
{
    float x, y, z, w;
    void FUN_004e5c20();
};
void __cdecl FUN_00468f10(FourFloatVector*, const NiPoint3*);
struct MotionData
{
    void* vtable;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned char motionType;
};
struct Body;
struct BodyVTable
{
    void* method00;
    void* method04;
    void* method08;
    void* method0c;
    void* method10;
    void* method14;
    void* method18;
    void* method1c;
    void* method20;
    void* method24;
    void* method28;
    void* method2c;
    void* method30;
    void* method34;
    void* method38;
    void* method3c;
    void* method40;
    void* method44;
    void* method48;
    void* method4c;
    void* method50;
    void* method54;
    void* method58;
    void* method5c;
    void* method60;
    void* method64;
    void* method68;
    void* method6c;
    void* method70;
    void* method74;
    void* method78;
    void* method7c;
    void* method80;
    void* method84;
    void* method88;
    void* method8c;
    void* method90;
    void* method94;
    void* method98;
    void* method9c;
    void* methoda0;
    void* methoda4;
    void* methoda8;
    void* methodac;
    void* methodb0;
    void* methodb4;
    void* methodb8;
    void* methodbc;
    void* methodc0;
    void* methodc4;
    void* methodc8;
    void* methodcc;
    void* methodd0;
    void* methodd4;
    void* methodd8;
    void* methoddc;
    void(__thiscall* SetGeometryTransform)(Body*, const FourFloatVector*, const HavokQuaternion*);
};

struct PhysicsLock
{
    long owner;
    long count;
    void FUN_00409a80(const char*);
    void Unlock()
    {
        if (--count == 0)
            ::InterlockedCompareExchange(&owner, 0, owner);
    }
};
extern PhysicsLock DAT_010f2c40;
struct Body
{
    BodyVTable* vtable;
    int refCount;
    MotionData* data;
    int FUN_008f81f0();
    void FUN_008ffac0(const NiPoint3*, const Quaternion*);
};
char __cdecl FUN_0056fab0(int);

} // namespace N8d2120

using namespace N8d2120;

struct CollisionSync
{
    void* vtable;
    int refCount;
    NiAVObject* node;
    unsigned short flags;
    Body* body;
    bool FUN_0044db30();
    unsigned char flagSet(unsigned bit) const
    {
        return (flags >> bit) & 1;
    }
    void FUN_008d2120();
};

// pdb: bhkCollisionObject::NitohkTransform | bhkCollisionObject.obj | fnv360_0721_beta, call_dedup, medium
void CollisionSync::FUN_008d2120()
{
    FourFloatVector forcedPos;
    HavokQuaternion forcedQ;
    FourFloatVector flaggedPos;
    HavokQuaternion flaggedQ;
    NiAVObject* n = node;
    Body* b = body;
    if (!n)
        return;
    n->FUN_008330a0();
    if (!b)
        return;
    int type = b->data ? b->data->motionType : 7;
    if (type == 7 && b->FUN_008f81f0())
        return;
    if (!b->data)
        return;
    const Transform* world = &n->world;
    Quaternion rot;
    rot.FUN_00837260(&world->rotate);
    if (flagSet(6))
    {
        FUN_00468f10(&forcedPos, &world->translate);
        forcedQ.x = rot.x;
        forcedQ.y = rot.y;
        forcedQ.z = rot.z;
        forcedQ.w = rot.w;
        forcedQ.FUN_004e5c20();
        DAT_010f2c40.FUN_00409a80(0);
        b->vtable->SetGeometryTransform(b, &forcedPos, &forcedQ);
    }
    else
    {
        if (FUN_0044db30())
        {
            b->FUN_008ffac0(&world->translate, &rot);
            return;
        }
        if (FUN_0056fab0(type))
        {
            b->FUN_008ffac0(&world->translate, &rot);
            return;
        }
        FUN_00468f10(&flaggedPos, &world->translate);
        flaggedQ.x = rot.x;
        flaggedQ.y = rot.y;
        flaggedQ.z = rot.z;
        flaggedQ.w = rot.w;
        flaggedQ.FUN_004e5c20();
        DAT_010f2c40.FUN_00409a80(0);
        b->vtable->SetGeometryTransform(b, &flaggedPos, &flaggedQ);
    }
    DAT_010f2c40.Unlock();
}

// @f3 0x008db020 (community match, verified in this file)
namespace f3m_008db020 {

namespace f3m_8db020 {
struct __declspec(align(16)) V3 {
    float x, y, z;
    float SqrLength() const { return x * x + y * y + z * z; }
};
struct S008db020_C {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    float m50[4];
    void FUN_008db020(const V3* a, const float* b);
    static void Update(float& f, float t)
    {
        if (f == 1.175494351e-38F) f = t;
        else { float s = f + t; f = s * 0.5; }
    }
};
void S008db020_C::FUN_008db020(const V3* a, const float* b)
{
    V3 d[4];
    for (int k = 0; k < 4; ++k) { d[k].x = b[0] - a[k].x; d[k].y = b[1] - a[k].y; d[k].z = 0.0f; }
    float l0 = d[0].SqrLength();
    float l1 = d[1].SqrLength();
    int i = (l0 < l1) ? 0 : 1;
    Update(m50[i], b[2]);
    float l2 = d[2].x * d[2].x + d[2].y * d[2].y + d[2].z * d[2].z;
    float l3 = d[3].SqrLength();
    i = (l2 < l3) ? 2 : 3;
    Update(m50[i], b[2]);
}
}
}   // namespace f3m_008db020

// @f3 0x008d8a30 (community match, verified in this file)
namespace f3m_008d8a30 {
namespace f3m_008d8a30 {
struct __declspec(align(16)) Vec_8d8a30 { float x, y, z, w; };

struct Node_8d8a30 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4;
    int unkb8;
};

struct Item_8d8a30 {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c; int unk10;
    Node_8d8a30* unk14;
    Node_8d8a30* unk18;
};

struct World_8d8a30 { void FUN_009082b0(Item_8d8a30* item); };

struct Owner_8d8a30 {
    void** vtbl;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    unsigned int unk20;
    int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48;
    Item_8d8a30** unk4c;
    unsigned int unk50;
    World_8d8a30* GetWorld() { return ((World_8d8a30*(__thiscall*)(Owner_8d8a30*))vtbl[0x98 / 4])(this); }
    void FUN_008d4180();
    void FUN_008d5db0();
    void FUN_008d6290();
    void FUN_008d48d0();
    void FUN_008d8a30(Item_8d8a30* item);
};

// pdb: bhkWorld::Add | bhkWorld.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject
void Owner_8d8a30::FUN_008d8a30(Item_8d8a30* item)
{
    Vec_8d8a30 scratch;
    scratch.x = 0.0f;
    if (!this)
        return;
    World_8d8a30* world = GetWorld();
    if (!world)
        return;
    if (unk20 > 0) {
        if (unk50 >= 200) {
            FUN_008d4180();
            FUN_008d5db0();
            FUN_008d6290();
            FUN_008d48d0();
        }
        if (item->unk04)
            item->unk06 += 1;
        unk4c[unk50] = item;
        unk50 += 1;
        return;
    }
    if (item && !item->unk08
        && (!item->unk14 || item->unk14->unkb8)
        && (!item->unk18 || item->unk18->unkb8))
        world->FUN_009082b0(item);
}
}

}   // namespace f3m_008d8a30

// @f3 0x008d40e0 (community match, verified in this file)
namespace f3m_008d40e0 {
namespace f3m_8d40e0 {
struct String {
    int unk00;
    int unk04;
    const char* value;
    void FUN_00943a30(const char* s);
    void FUN_00943a60();
    String(const char* s) { FUN_00943a30(s); }
    ~String() { FUN_00943a60(); }
};

struct Bool {
    char value;
    Bool(bool v) : value(v) {}
    Bool(const Bool& o) : value(o.value) {}
};

struct Parent;

struct Key {
    Parent* p;
    const char* s;
    Key(Parent* p_, const char* s_) : p(p_), s(s_) {}
};

Bool __cdecl FUN_009443a0(Key k, Bool b, int a4, int a5);

struct Owner {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094();
    virtual Parent* parent();
    bool FUN_008d40e0(const char* name);
};

// pdb: bhkWorld::SaveSnapshot | bhkWorld.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apFileName
bool Owner::FUN_008d40e0(const char* name) {
    String s(name);
    Bool result = FUN_009443a0(Key(parent(), s.value), Bool(false), 0, 0);
    return result.value != 0;
}
}
}   // namespace f3m_008d40e0

// @f3 0x008daa60 (community match, verified in this file)
#include <math.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* __cdecl FUN_0089eb90(unsigned int);
char* __cdecl FUN_008242a0(const char*);
extern char* DAT_00e207a8;
struct Update8daa { float unk00; bool unk04,unk05,unk06,unk07,unk08; Update8daa():unk00(0),unk04(false),unk05(false),unk06(false),unk07(false),unk08(false){} };
struct Vec8daa { float unk00,unk04,unk08; };
extern Vec8daa DAT_00f731bc;
extern const char DAT_00e329b8[];
__forceinline void InvertScale8daa(float& v){v=1.0f/v;}
__forceinline void AbsScale8daa(float& v){v=(float)fabs((double)v);}
struct NiNode;
struct Material;
struct NiFixedString { char* unk00; NiFixedString(const char*); ~NiFixedString() { if(unk00!=DAT_00e207a8) InterlockedDecrement(reinterpret_cast<volatile long*>(unk00 - 8)); } };
typedef NiFixedString String8daa;
struct Lookup8daa { char* unk00; Lookup8daa(const char* p):unk00(FUN_008242a0(p)){} ~Lookup8daa() { if(unk00!=DAT_00e207a8) InterlockedDecrement(reinterpret_cast<volatile long*>(unk00 - 8)); } };
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); long m_uiRefCount; void IncRefCount(){InterlockedIncrement(&m_uiRefCount);} void DecRefCount(){if(!InterlockedDecrement(&m_uiRefCount))DeleteThis();} };
typedef NiRefObject Ref8daa;

struct Root8daa;
typedef NiPointer<Root8daa> Hold8daa;
struct InlineHold8daa { NiNode* unk00; InlineHold8daa():unk00(0){} ~InlineHold8daa(); };
typedef NiPointer<Material> SharedHold8daa;
struct Material : Ref8daa {
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
Vec8daa position28;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
Material(); static void* operator new(unsigned int n){return FUN_0089eb90(n);}
};

struct LinkData8daa { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18; unsigned kind1c; };
struct Link8daa { unsigned unk00,unk04,unk08,unk0c; LinkData8daa data; };
struct Root8daa : Ref8daa {
void FUN_008245d0(const String8daa&);
void SetScale(float v){unk64=v;} void FUN_008264c0(const Update8daa&);
void* FUN_00826590(int); void FUN_004236f0(Material*); void FUN_008268a0();
Root8daa* FUN_00826680(const Lookup8daa&);
virtual void vf08();
virtual NiNode* vf0c();
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
virtual void vf38();
virtual void vf3c();
virtual void vf40();
virtual void vf44();
virtual void vf48();
virtual void vf4c();
virtual void vf50();
virtual void vf54();
virtual void vf58();
virtual void vf5c();
virtual void vf60();
virtual void vf64();
virtual void vf68();
virtual void vf6c();
virtual void vf70();
virtual void vf74();
virtual void vf78();
virtual void vf7c();
virtual void vf80();
virtual void vf84();
virtual void vf88();
virtual void vf8c();
virtual void vf90();
virtual void vf94();
virtual void vf98();
virtual void vf9c();
virtual void vfa0();
virtual void vfa4();
virtual void vfa8();
virtual void vfac();
virtual void vfb0();
virtual void vfb4();
virtual void vfb8();
virtual void vfbc();
virtual void vfc0();
virtual void vfc4();
virtual Root8daa* vfc8(Root8daa*);
virtual void vfcc();
virtual void vfd0();
virtual void vfd4();
virtual void vfd8();
virtual void vfdc(Root8daa*,bool);
virtual void vfe0();
virtual void vfe4(Root8daa*,Root8daa*&);
Link8daa* link08;
int unk0c;
int unk10;
int unk14;
Root8daa* unk18;
int unk1c;
int unk20;
int unk24;
Vec8daa position28;
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
float unk64;
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
float unk98;
float GetScale() const {return unk98;}
int unk9c;
Root8daa** unka0;
unsigned short unkA4; unsigned short unkA6;
};
struct NiNode : Root8daa {
float unka8;
NiNode(unsigned short); static void* operator new(unsigned int n){return FUN_0089eb90(n);}

};
struct Parent8daa { int unk00,unk04; struct Data { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28; }* unk08; };
struct Target8daa : Ref8daa {
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
virtual void vf38();
virtual void vf3c();
virtual void vf40();
virtual void vf44();
virtual void vf48();
virtual void vf4c();
virtual void vf50();
virtual void vf54();
virtual void vf58();
virtual void vf5c();
virtual void vf60();
virtual void vf64();
virtual void vf68();
virtual void vf6c();
virtual void vf70();
virtual void vf74();
virtual void vf78();
virtual void vf7c();
virtual void vf80();
virtual void vf84();
virtual void vf88();
virtual void vf8c();
virtual void vf90();
virtual void vf94();
virtual void vf98();
virtual void vf9c();
virtual void vfa0();
virtual void vfa4();
virtual void vfa8();
virtual void vfac();
virtual void vfb0();
virtual void vfb4();
virtual void vfb8();
virtual void vfbc();
virtual void vfc0();
virtual void vfc4();
 virtual Root8daa* vfc8(Root8daa*);
 Link8daa* link08;
};
struct FUN_008daa60_Class {
 int unk00,unk04; Root8daa* unk08; unsigned short unk0c; unsigned short unk0e; Target8daa* unk10;
 bool GetDebugFlag() const { return (unk0c >> 4) & 1; }
 void FUN_008daa60(bool);
};
void FUN_008daa60_Class::FUN_008daa60(bool enabled) {
 static SharedHold8daa shared;
 if(enabled) {
 if(GetDebugFlag()) return;
 Target8daa* target=unk10; if(!target) return;
 Link8daa* link=target->link08;
 LinkData8daa* data=link ? &link->data : 0;
 unsigned int kind=data ? data->kind1c : 0;
 if((kind&0x7f)==17) return;
 Root8daa* src=unk08;
 NiNode* root=0;
 if(src) root = src->vf0c();
 if(!src || !root) root=static_cast<NiNode*>(src->unk18);
 NiNode* created=new NiNode(0);
 created->FUN_008245d0(String8daa(DAT_00e329b8));
 if(root) {
 float scale=root->GetScale();
 created->unk64=fabsf(1.0f/scale);
 root->vfdc(created,true);
 Update8daa params;
 created->FUN_008264c0(params);
 }
 Root8daa* cloned=target->vfc8(created);
 Hold8daa copy(cloned);
 if(cloned) {
 if(root) {
 Root8daa* clone=cloned;
 if(!clone->FUN_00826590(2)) {
 if(!shared.m_pObject) {
 shared=new Material;
 Material* state=shared.m_pObject;
 state->position28=DAT_00f731bc;
 state->unk44++;
 }
 clone->FUN_004236f0(shared.m_pObject);
 }
 clone->FUN_008268a0();
 Update8daa params;
 clone->FUN_008264c0(params);
 }
 } else if(root && created) {
 Hold8daa removed;
 root->vfe4(created,removed.m_pObject);
 }
 unk0c|=0x10;
 } else {
 if(!GetDebugFlag()) return;
 Root8daa* src=unk08;
 NiNode* root=0;
 if(src) root = src->vf0c();
 if(!src || !root) root=static_cast<NiNode*>(src->unk18);
 if(root) {
 unsigned int n=root->unkA6;
 for(unsigned int i=0;i<n;++i) {
 Root8daa* child=root->unka0[i];
 Root8daa* found=child ? child->FUN_00826680(Lookup8daa(DAT_00e329b8)) : 0;
 if(found) {
 Hold8daa removed;
 root->vfe4(found,removed.m_pObject);
 if(shared.m_pObject && shared.m_pObject->m_uiRefCount==1) {
 Material* state=shared.m_pObject;
 if(!InterlockedDecrement(&state->m_uiRefCount)) state->DeleteThis();
 shared.m_pObject=0;
 }
 }
 }
 }
 unk0c &= ~0x10;
 }
}

// @f3 0x008db1a0 (community match, verified in this file)
namespace f3m_008db1a0 {


// Four-float vector of the x87 build (16-byte aligned, lanes copied one by one).
struct __declspec(align(16)) S008db1a0_Vec4
{
    float x, y, z, w;

    float lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        float inv;
        if (l2 != 0.0f)
            inv = 1.0f / sqrtf(l2);
        else
            inv = 0.0f;
        return inv;
    }
    void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    void mul4(const S008db1a0_Vec4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    void add4(const S008db1a0_Vec4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    S008db1a0_Vec4& operator=(const S008db1a0_Vec4& a) { x = a.x; y = a.y; z = a.z; w = a.w; return *this; }
};

struct S008db1a0_Obj
{
    const S008db1a0_Vec4& GetVec10();              // 0x0091dda0: address of the vector at +0x10
    void SetVec10(const S008db1a0_Vec4& v);        // 0x0091ddb0: copies into the vector at +0x10
};
struct S008db1a0_Dir
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S008db1a0_Vec4 dir;
};
extern const S008db1a0_Vec4 DAT_01092a50;

// pdb: bhkCharacterListener::characterInteractionCallback | bhkCharacterListener.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apProxy, apOtherProxy, arContact
void __stdcall FUN_008db1a0(S008db1a0_Obj* a1, S008db1a0_Obj* a2, S008db1a0_Dir* a3)
{
    S008db1a0_Vec4 v;
    v = a1->GetVec10();

    // Nothing to do when the first three lanes are within 0.01 of the reference vector.
    S008db1a0_Vec4 d;
    d.x = v.x - DAT_01092a50.x;
    d.y = v.y - DAT_01092a50.y;
    d.z = v.z - DAT_01092a50.z;
    d.w = v.w - DAT_01092a50.w;
    d.x = fabsf(d.x);
    d.y = fabsf(d.y);
    d.z = fabsf(d.z);
    d.w = fabsf(d.w);
    int m = (d.x <= 0.01f ? 8 : 0) | (d.y <= 0.01f ? 4 : 0) |
            (d.z <= 0.01f ? 2 : 0) | (d.w <= 0.01f ? 1 : 0);
    if ((m & 0xe) == 0xe)
        return;

    // Horizontal unit direction, scaled lane by lane by the first object's vector.
    S008db1a0_Vec4 n;
    n = a3->dir;
    n.z = 0.0f;
    n.mul4(n.lengthInverse3());
    v.z = 0.0f;
    n.mul4(v);

    v = a2->GetVec10();
    v.add4(n);
    a2->SetVec10(v);
}
}   // namespace f3m_008db1a0

// @f3 0x008dc360 (community match, verified in this file)
#include <math.h>
extern const double DAT_01023128;
extern float DAT_010f2d84;
extern float DAT_010f2d78;
namespace f3m_008dc360 {


struct __declspec(align(16)) Quat
{
    float x;
    float y;
    float z;
    float w;

    __forceinline Quat& operator=(const Quat& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
        return *this;
    }

    __forceinline void setSub4(const Quat& a, const Quat& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }

    __forceinline void setAbs4(const Quat& a)
    {
        x = (float)fabs(a.x);
        y = (float)fabs(a.y);
        z = (float)fabs(a.z);
        w = (float)fabs(a.w);
    }

    __forceinline int compareLessThanEqual4(float limit) const
    {
        return (x <= limit ? 8 : 0) | (y <= limit ? 4 : 0) | (z <= limit ? 2 : 0) | (w <= limit ? 1 : 0);
    }

    __forceinline bool equals3(const Quat& other, float epsilon = 0.001f) const
    {
        Quat difference;
        difference.setSub4(*this, other);
        difference.setAbs4(difference);
        return (difference.compareLessThanEqual4(epsilon) & 0xe) == 0xe;
    }

    static __forceinline float sqrtInverse(float r) { return 1.0f / (float)sqrt(r); }
    __forceinline float lengthInverse3() const
    {
        float l2 = x * x + y * y + z * z;
        return l2 ? sqrtInverse(l2) : 0.0f;
    }
    // Fake match: the factor arrives as a double and is narrowed to a float local. The
    // arithmetic is the same as with a float parameter; this form only decides which
    // operand of each multiply is loaded first (the factor for x and w, the component
    // for y and z, as in the original).
    __forceinline void mul4(double rhs)
    {
        float r = (float)rhs;
        x *= r;
        y *= r;
        z *= r;
        w *= r;
    }
    void FUN_008db610(const Quat* to, const Quat* from);
    float FUN_008db810();
    void FUN_008db880(Quat* axis);
    void FUN_009240d0(Quat* axis, float angle);
    __forceinline void setCross(const Quat& a, const Quat& b)
    {
        x = a.y * b.z - a.z * b.y;
        y = a.z * b.x - a.x * b.z;
        z = a.x * b.y - a.y * b.x;
        w = 0.0f;
    }

    __forceinline void addMul4(float scale, const Quat& v)
    {
        x += scale * v.x;
        y += scale * v.y;
        z += scale * v.z;
        w += scale * v.w;
    }

    __forceinline float dot3(const Quat& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    void FUN_008d3290(Quat* q0, Quat* q1)
    {
        Quat vec;
        vec.setCross(*q0, *q1);
        vec.addMul4(q0->w, *q1);
        vec.addMul4(q1->w, *q0);
        float real = q0->w * q1->w - q0->dot3(*q1);
        *this = vec;
        w = real;
    }

    void FUN_004e5c20()
    {
        float lengthSquared = x * x + y * y + z * z + w * w;
        float scale;
        if (lengthSquared != 0.0f)
            scale = 1.0f / (float)sqrt(lengthSquared);
        else
            scale = 0.0f;
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;
    }
};

struct Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Quat vector;
};

struct Holder
{
    Target* FUN_00956290(int index);
};

struct Entry
{
    Holder* holder;
    short index;
    short unk06;
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
    Quat position;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct Constraint
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
    short unkb0;
    bool enabled;
    char unkb3;
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
    Entry entries[4];

    float FUN_008dc360(unsigned int index, const Quat* input);
};

// pdb: bhkRagdollController::LimitBoneRot | bhkRagdollController.obj | fnv360_0822_retail, objrun, medium
// pdb params: aeBone, arIKBoneRotLS
float Constraint::FUN_008dc360(unsigned int index, const Quat* input)
{
    float distance = 0.0f;
    if (!input->equals3(entries[index].position))
    {
        Quat delta;
        delta.FUN_008db610(input, &entries[index].position);
        distance = delta.FUN_008db810();
        float limit = enabled ? DAT_010f2d84 : DAT_010f2d78;
        if (distance > limit * DAT_01023128)
        {
            distance = (float)(limit * DAT_01023128);
            Quat axis;
            delta.FUN_008db880(&axis);
            axis.mul4(axis.lengthInverse3());
            delta.FUN_009240d0(&axis, distance);
        }
        {
            Quat result;
            result.FUN_008d3290(&delta, &entries[index].position);
            result.FUN_004e5c20();
            Target* target = entries[index].holder->FUN_00956290(entries[index].index);
            target->vector = result;
            entries[index].position = result;
        }
    }
    return distance;
}
}   // namespace f3m_008dc360

// @f3 0x008d5510 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
namespace n8d5510 {
extern unsigned long DAT_010f3170;
struct ThreadMemory {
    void* FUN_008f6d30(unsigned nbytes, int cls);
    static ThreadMemory& getInstance() { return *static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170)); }
};
struct Bool {
    char value;
    Bool() {}
    Bool(bool b) : value(b) {}
    Bool(const Bool& b) : value(b.value) {}
    Bool& operator=(bool b) { value = b; return *this; }
};
struct Dispatcher;
struct Listener;
struct Debugger;
void __cdecl FUN_009435a0(Dispatcher* d);
extern Listener* DAT_01169104;
extern Debugger* DAT_010f2a68;
struct WorldCinfo {
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
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    Bool flagbc;
    char padbd, padbe, padbf;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
};
struct SerialInfo {
    unsigned unk000;
};
struct FullInfo : WorldCinfo, SerialInfo {};
struct Referenced {
    virtual ~Referenced();
    unsigned short size;
    short refs;
    void removeReference() {
        if (size != 0) {
            --refs;
            if (refs == 0)
                delete this;
        }
    }
};
struct FUN_00904ea0 : Referenced {
    FUN_00904ea0(const WorldCinfo& info, unsigned version);
    void FUN_00903ce0(Listener* l);
    void FUN_00908780(Debugger* d, Bool flag, int a, int b);
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
    Dispatcher* dispatcher;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
};
extern char DAT_00e3205c;
struct VtableView { void* table; };
// The derived world class: its virtual table (0x00e3205c) is written by hand through the pack symbol,
// because this stand-in declares no virtual functions of its own.
struct __declspec(novtable) World : FUN_00904ea0 {
    unsigned unk310, unk314, unk318, unk31c;
    World(const WorldCinfo& info) : FUN_00904ea0(info, 0xc544) {
        reinterpret_cast<VtableView*>(this)->table = &DAT_00e3205c;
        unk310 = 0;
    }
    static void* operator new(unsigned nbytes) {
        ThreadMemory& mem = ThreadMemory::getInstance();
        Referenced* b = static_cast<Referenced*>(mem.FUN_008f6d30(nbytes, 0x2f));
        b->size = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);
};
struct Self {
    virtual ~Self();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void Attach(World* w);
    virtual void slot24();
    virtual void slot25();
    virtual FUN_00904ea0* Current();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void Set(const SerialInfo& info);
    unsigned unk004;
    FUN_00904ea0* world;
    void FUN_008d5510(const SerialInfo& arInfo);
};
// Builds the physics world from the construction info and attaches it to this object.
// arInfo is the serializable base (at +0xd0) of the full world info.
// pdb: bhkWorld::Init | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void Self::FUN_008d5510(const SerialInfo& arInfo)
{
    const FullInfo* cinfo = static_cast<const FullInfo*>(&arInfo);
    if (cinfo) {
        const_cast<FullInfo*>(cinfo)->flagbc = true;
        World* po = new World(*cinfo);
        if (DAT_010f2a68)
            po->FUN_00908780(DAT_010f2a68, Bool(true), 0, 1);
        Attach(po);
        po->removeReference();
        Set(arInfo);
        FUN_00904ea0* current = Current();
        if (current)
            FUN_009435a0(current->dispatcher);
        if (DAT_01169104) {
            Listener* listener = DAT_01169104;
            FUN_00904ea0* again = Current();
            if (again)
                again->FUN_00903ce0(listener);
        }
        po->unk0a4 = 0;
    }
}
}

// @f3 0x008d5fd0 (community match, verified in this file)
struct Obj010f2ae0
{
    void FUN_008d5ea0();
};

extern Obj010f2ae0 DAT_010f2ae0;

// pdb: bhkOnStartupCallback::operator() | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void FUN_008d5fd0()
{
    DAT_010f2ae0.FUN_008d5ea0();
}

// @f3 0x008d0ca0 (community match, verified in this file)
extern void* DAT_00e312f4[];
namespace f3m_008d0ca0 {
struct Object {
 void** vtable00;
 void FUN_00825830();
 void FUN_008d0ca0();
};
// pdb: NiInterpolator::~NiInterpolator | NiInterpolator.obj | fnv360_0822_retail, call_seq, medium
void Object::FUN_008d0ca0() { vtable00 = DAT_00e312f4; FUN_00825830(); }
}   // namespace f3m_008d0ca0

// @f3 0x008d3230 (community match, verified in this file)
namespace f3m_008d3230 {
namespace f3m_008d3230 {
struct Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int count;
    void FUN_008d3230();
};
// pdb: bhkWorld::StartBatchingRemovals | bhkWorld.obj | fnv360_0822_retail, call_gap, low
void Obj::FUN_008d3230()
{
    ++count;
}
}
}   // namespace f3m_008d3230

// @f3 0x008c9d90 (community match, verified in this file)
namespace f3m_008c9d90 {
// pdb: NiBSplineTransformInterpolator::IsTransformValueSupported | NiBSplineTransformInterpolator.obj | fnv360_0721_beta, objrun_open, low
unsigned short __cdecl FUN_008c9d90() { return 3; }
}   // namespace f3m_008c9d90

// @f3 0x008ca4f0 (community match, verified in this file)
namespace f3m_008ca4f0 {
// pdb: NiBSplinePoint3Interpolator::IsPoint3ValueSupported | NiBSplinePoint3Interpolator.obj | fnv360_0721_beta, objrun_open, low, conflict (skyrim: NiBSplinePoint3Interpolator::GetRTTI)
unsigned short __cdecl FUN_008ca4f0()
{
    return 1;
}
}   // namespace f3m_008ca4f0

// @f3 0x008d3220 (community match, verified in this file)
namespace f3m_008d3220 {
struct FUN_008d3220 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int count;
    void Increment();
};

// pdb: bhkWorld::StartBatchingAdds | bhkWorld.obj | fnv360_0822_retail, call_gap, medium
void FUN_008d3220::Increment() {
    count += 1;
}
}   // namespace f3m_008d3220

// @f3 0x008d5bb0 (community match, verified in this file)
#include <math.h>
namespace f3m_008d5bb0 {

struct SimdReal
{
    float r;
    SimdReal(float f) : r(f) {}
    SimdReal(const SimdReal& o) : r(o.r) {}
    operator float() const { return r; }
};

inline SimdReal HkFabs(float r) { return SimdReal(fabsf(r)); }

struct __declspec(align(16)) Vec4
{
    float q[4];
    Vec4() {}
    Vec4(const Vec4& o) { q[0] = o.q[0]; q[1] = o.q[1]; q[2] = o.q[2]; q[3] = o.q[3]; }
    Vec4& operator=(const Vec4& o) { q[0] = o.q[0]; q[1] = o.q[1]; q[2] = o.q[2]; q[3] = o.q[3]; return *this; }
    __forceinline void Set(float a, float b, float c, float d) { q[0] = a; q[1] = b; q[2] = c; q[3] = d; }
    __forceinline void Mul4(SimdReal s) { q[0] = static_cast<const volatile float&>(q[0]) * s.r; q[1] *= s.r; q[2] *= s.r; q[3] *= s.r; }
    __forceinline void SetSub4(const Vec4& a, const Vec4& b) { q[0] = a.q[0] - b.q[0]; q[1] = a.q[1] - b.q[1]; q[2] = a.q[2] - b.q[2]; q[3] = a.q[3] - b.q[3]; }
    __forceinline void SetAbs4(const Vec4& a) { q[0] = HkFabs(a.q[0]); q[1] = HkFabs(a.q[1]); q[2] = HkFabs(a.q[2]); q[3] = HkFabs(a.q[3]); }
    __forceinline void Add4(const Vec4& a) { q[0] += a.q[0]; q[1] += a.q[1]; q[2] += a.q[2]; q[3] += a.q[3]; }
    __forceinline int CompareLessEqual(float e) const
    {
        int mx = q[0] <= e ? 8 : 0;
        int my = q[1] <= e ? 4 : 0;
        int mz = q[2] <= e ? 2 : 0;
        int mw = q[3] <= e ? 1 : 0;
        return mx | my | mz | mw;
    }
};

extern Vec4 DAT_01092a50;

struct Scale { int unk00, unk04, unk08, unk0c, unk10, unk14; float f18; float f1c; };

struct Body
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0c();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1c();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2c();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3c();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4c();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5c();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6c();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7c();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8c();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9c();
    virtual void Va0();
    virtual void Va4();
    virtual void Va8();
    virtual void Vac();
    virtual void Vb0();
    virtual void Vb4();
    virtual void Vb8();
    virtual void Vbc();
    virtual void Vc0();
    virtual void Vc4();
    virtual void Vc8();
    virtual void GetPos(Vec4& out);
    virtual void Vd0();
    virtual void SetPos(const Vec4& p);
};

struct Phantom
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0c();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1c();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2c();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3c();
    virtual Body* GetBody();
};

struct Obj
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0c();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1c();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2c();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual Scale* GetScale();
    int unk04, unk08, unk0c;
    Phantom* phantom;
};

struct Arg { int unk00, unk04, unk08; Vec4* pos; };

void __cdecl FUN_008d5bb0(Obj* obj, Arg* arg)
{
    Scale* sc = obj->GetScale();
    Phantom* ph = obj->phantom;
    if (ph)
    {
        Body* body = ph->GetBody();
        if (body)
        {
            Vec4* p = arg->pos;
            if (p)
            {
                struct WorkVectors : Vec4 {
                    Vec4 output;
                    WorkVectors(const Vec4& p) : Vec4(p) {}
                } v(*p);
                Vec4& o = v.output;
                if (sc && sc->f18 < 1.0f)
                {
                    if (sc->f18 == 0.0f)
                        return;
                    v.Mul4(SimdReal(sc->f1c));
                    o.SetSub4(v, DAT_01092a50);
                    o.SetAbs4(o);
                    if ((o.CompareLessEqual(0.001f) & 0xe) == 0xe)
                        return;
                }
                body->GetPos(o);
                const volatile float& dx = v.q[0];
                o.q[0] = dx + o.q[0];
                o.q[1] += v.q[1];
                o.q[2] += v.q[2];
                o.q[3] += v.q[3];
                body->SetPos(o);
            }
        }
    }
}
}

// @f3 0x008dbec0 (community match, verified in this file)
extern float DAT_010f2e50;
extern const double DAT_00dbe7c0;
namespace f3m_008dbec0 {

struct S008dbec0_P3 {
    float x, y, z;
    __forceinline float Y() const { return y; }
    __forceinline float Z() const { return z; }
};
struct __declspec(align(16)) S008dbec0_V4
{
    float components[4];
    __forceinline float& component(unsigned int index) { return components[index]; }
    __forceinline const float& component(unsigned int index) const { return components[index]; }
    __forceinline float GetComponent(unsigned int index) const { return components[index]; }
    __forceinline void SetValues(float a, float b, float c, float d) {
        component(0) = a; component(1) = b; component(2) = c; component(3) = d;
    }
    __forceinline void CopyFrom(const S008dbec0_V4& value) {
        component(0) = value.component(0);
        component(1) = value.component(1);
        component(2) = value.component(2);
        component(3) = value.component(3);
    }
    __forceinline void SetScaledPosition(const S008dbec0_P3& value, double scale) {
        component(0) = value.x * scale;
        component(1) = value.Y() * scale;
        component(2) = value.Z() * scale;
    }
    __forceinline void Lerp(const S008dbec0_V4& from, const S008dbec0_V4& to,
                            const float& blend)
    {
        const S008dbec0_V4 targetSnapshot = to;
        float a = blend;
        float t = 1.0f - a;
        component(0) = from.component(0) * t + targetSnapshot.component(0) * a;
        component(1) = from.component(1) * t + targetSnapshot.component(1) * a;
        component(2) = from.component(2) * t + targetSnapshot.component(2) * a;
        component(3) = from.component(3) * t + targetSnapshot.component(3) * a;
    }
    __forceinline void LerpRot(const float& blend)
    {
        float a = blend;
        float t = 1.0f - a;
        component(0) = GetComponent(0) * t + 0.0 * a;
        component(1) = GetComponent(1) * t + a;
        component(2) = GetComponent(2) * t + 0.0 * a;
        component(3) = GetComponent(3) * t + 0.0 * a;
    }
};

struct S008dbec0_Src
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    S008dbec0_P3 pos;
};

struct S008dbec0_Q : S008dbec0_V4
{
    void Init(void* arg, S008dbec0_V4* pos);
};

struct S008dbec0_Msg
{
    short s0;
    short s2;
    short s4;
    float unk08;
    float unk0c;
    S008dbec0_V4 r;
    float unk20;
    float unk24;
    float b0;
    float b1;
    S008dbec0_V4 q;
    __forceinline void SetFirstWeight(const float& value) { b0 = value; }
    __forceinline void SetSecondWeight(const float& value) { b1 = value; }
    __forceinline void SetIndices(short first, short second, short third) {
        s0 = first; s2 = second; s4 = third;
    }
    __forceinline void SetDirection(float x, float y, float z, float w) {
        r.SetValues(x, y, z, w);
    }
    __forceinline void SetPosition(const S008dbec0_V4& value) { q.CopyFrom(value); }
    S008dbec0_Msg();
};

struct S008dbec0_Entry
{
    S008dbec0_Src* src;
    float a;
    float b;
    bool active;
    bool fading;
    S008dbec0_V4 pos;
    S008dbec0_V4 rot;
};

void S008dbec0_Send(char* out, S008dbec0_Msg* msg, int id);

struct S008dbec0_Obj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    int unk88;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    S008dbec0_Entry entries[2];
    short ids[6];
    short unk21c;
    char unk21e;
    void FUN_008dbec0(void* arg);
};

void S008dbec0_Obj::FUN_008dbec0(void* arg)
{
    S008dbec0_V4 v;
    for (int i = 0, offset = 0; i < 2; offset += 3, ++i)
    {
        S008dbec0_Entry* e = &entries[i];
        if (e->active)
        {
            if (!e->fading)
            {
                S008dbec0_P3 p = e->src->pos;
                v.SetScaledPosition(p, 0.1428767293691635);
                if (e->b > 0.0f)
                {
                    e->pos.Lerp(e->pos, v, e->a);
                    e->rot.LerpRot(e->a);
                }
                else
                {
                    e->pos.CopyFrom(v);
                    e->rot.SetValues(0.0f, 1.0f, 0.0f, 0.0f);
                }
            }
            float target = !e->fading ? 1.0f : 0.0f;
            float nb = (target - e->b) * DAT_010f2e50 + e->b;
            e->b = nb;
            if (nb < 0.01f && e->fading)
            {
                e->fading = false;
                e->b = 0.0f;
                e->active = false;
            }
            else
            {
                S008dbec0_Q q;
                q.Init(arg, &e->pos);
                S008dbec0_Msg msg;
                msg.SetFirstWeight(e->b);
                msg.SetSecondWeight(e->b);
                msg.SetIndices(ids[offset], ids[offset + 1], ids[offset + 2]);
                msg.SetDirection(0.0f, 0.0f, 1.0f, 0.0f);
                msg.SetPosition(q);
                char out;
                S008dbec0_Send(&out, &msg, unk88);
            }
        }
    }
    if (!entries[0].active && !entries[1].active)
        unk21e = 0;
}



}   // namespace f3m_008dbec0

// @f3 0x008d4540 (community match, verified in this file)
namespace f3m_008d4540 {



struct BoundE {
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
    BoundE() {}
    BoundE(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};
extern BoundE DAT_01092a50;

__forceinline bool IsZeroBoundE(const BoundE& b)
{
    BoundE diff(b.x - DAT_01092a50.x, b.y - DAT_01092a50.y, b.z - DAT_01092a50.z, b.w - DAT_01092a50.w);
    diff.x = fabs(diff.x);
    diff.y = fabs(diff.y);
    diff.z = fabs(diff.z);
    diff.w = fabs(diff.w);
    unsigned int mask = (diff.x <= 0.001f ? 8 : 0) | (diff.y <= 0.001f ? 4 : 0) | (diff.z <= 0.001f ? 2 : 0)
        | (diff.w <= 0.001f ? 1 : 0);
    return (mask & 0xe) == 0xe;
}

struct BoundOwnerE {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    BoundE bound1a0;
    BoundE bound1b0;
    void FUN_0090b500();
};

struct GeomE {
    int unk00;
    int unk04;
    BoundOwnerE* unk08;
    int unk0c;
    unsigned int unk10;
};

struct SoundRefE {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    unsigned short unk20;
};

struct ObjE {
    int unk00; int unk04; int unk08;
    GeomE* unkc;
    int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4;
    SoundRefE* unkb8;
    void FUN_009316f0();
};

struct SceneE {
    void hkpWorld_addEntityBatch(ObjE** objs, unsigned int count, int flags);
    void FUN_009037f0(unsigned char* out, ObjE* obj);
};
void __cdecl FUN_00929570(SceneE* scene, SoundRefE* sound);

extern unsigned char DAT_010f2a62;
extern unsigned int DAT_00f7947c;

struct QueueE {
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual SceneE* GetSceneE();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
    ObjE** unk34;
    unsigned int unk38;
    void FUN_008d4540(int unused, bool force);
};

void QueueE::FUN_008d4540(int unused, bool force)
{
    if (unk38 <= 0)
        return;
    if (DAT_010f2a62 && !force)
        return;
    if (unk38 >= 3000)
        unk38 = 3000;
    unsigned int count = unk38 < DAT_00f7947c ? unk38 : DAT_00f7947c;
    unsigned int start = unk38 - count;
    SceneE* scene = GetSceneE();
    if (scene) {
        // FINDING, labelled on purpose: both arms make the same call, so the behaviour is the plain call.
        // The compiler merges the arms and emits nothing for the test, but while it chooses registers
        // start*4 is used once in each arm; that puts start*4 in eax and the scene pointer in ecx, as in
        // the original.  With a single call the scene pointer stays in eax (7 instructions off).
        if (DAT_010f2a62)
            scene->hkpWorld_addEntityBatch(&unk34[start], count, 0);
        else
            scene->hkpWorld_addEntityBatch(&unk34[start], count, 0);
        bool played = false;
        for (unsigned int i = start; i < unk38; i++) {
            ObjE* obj = unk34[i];
            GeomE* geom = obj ? obj->unkc : 0;
            if (geom) {
                geom->unk10 &= ~0x10;
            } else {
                unsigned char out;
                scene->FUN_009037f0(&out, unk34[i]);
            }
            if (!played) {
                SoundRefE* sound = unk34[i]->unkb8;
                if (sound && sound->unk20 != 0xffff) {
                    FUN_00929570(scene, sound);
                    played = true;
                }
            }
            const BoundE& b1 = (geom && geom->unk08) ? geom->unk08->bound1a0 : DAT_01092a50;
            if (!IsZeroBoundE(b1) || !IsZeroBoundE((geom && geom->unk08) ? geom->unk08->bound1b0 : DAT_01092a50)) {
                if (geom && geom->unk08)
                    geom->unk08->FUN_0090b500();
            }
            unk34[i]->FUN_009316f0();
        }
        memset(&unk34[start], 0, count * 4);
        unk38 = start;
    }
    DAT_010f2a62 = 1;
}
}   // namespace f3m_008d4540

// @f3 0x008d7020 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace F3_8d7020 {
typedef float Real;
class Quat;
class Transform;

class __declspec(align(16)) Vec4
{
public:
    Real m_quad[4];
    __forceinline Vec4() {}
    __forceinline void operator=(const Vec4& v) { m_quad[0] = v.m_quad[0]; m_quad[1] = v.m_quad[1]; m_quad[2] = v.m_quad[2]; m_quad[3] = v.m_quad[3]; }
    __forceinline Real& operator()(int i) { return m_quad[i]; }
    __forceinline const Real& Y() const { return m_quad[1]; }
    __forceinline const Real& operator()(int i) const { return m_quad[i]; }
    __forceinline void set(Real a, Real b, Real c, Real d) { m_quad[0] = a; m_quad[1] = b; m_quad[2] = c; m_quad[3] = d; }
    __forceinline void setMul4(Real r, const Vec4& a) { (*this)(0) = r * a(0); (*this)(1) = r * a(1); (*this)(2) = r * a(2); (*this)(3) = r * a(3); }
    __forceinline void addMul4(const Real& rs, const Vec4& a) { Real r = rs; m_quad[0] += r * a.m_quad[0]; m_quad[1] += r * a.m_quad[1]; m_quad[2] += r * a.m_quad[2]; m_quad[3] += r * a.m_quad[3]; }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b) { m_quad[0] = a.m_quad[0] + b.m_quad[0]; m_quad[1] = a.m_quad[1] + b.m_quad[1]; m_quad[2] = a.m_quad[2] + b.m_quad[2]; m_quad[3] = a.m_quad[3] + b.m_quad[3]; }
    __forceinline Real dot3(const Vec4& a) const { return (m_quad[0] * a.m_quad[0]) + (m_quad[1] * a.m_quad[1]) + (m_quad[2] * a.m_quad[2]); }
    __forceinline void setCross(const Vec4& a, const Vec4& b)
    {
        const Real nx = a(1) * b(2) - a(2) * b(1);
        const Real ny = a(2) * b(0) - a(0) * b(2);
        const Real nz = a(0) * b(1) - a(1) * b(0);
        set(nx, ny, nz, 0);
    }
    __forceinline void setRotatedInverseDir(const Quat& q, const Vec4& v);
    __forceinline void ApplyQuaternionRotation(const Vec4& direction, const Quat& quat);
    void hkVector4_setTransformedPos(const Transform& t, const Vec4& v);
};

class Quat
{
public:
    Vec4 m_vec;
    __forceinline const Vec4& getImag() const { return m_vec; }
    __forceinline Real getReal() const { return m_vec(3); }
    void FUN_00924360(const Transform& t);
    void FUN_008d3290(const Quat& a, const Quat& b);
};

class Transform
{
public:
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
    Vec4 m_translation;
};

__forceinline void Vec4::setRotatedInverseDir(const Quat& quat, const Vec4& direction)
{
    Real qreal = quat.m_vec(3);
    Real q2minus1 = qreal * qreal - 0.5f;
    Vec4 ret;
    ret.setMul4(q2minus1, direction);
    Real imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());
    Vec4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void Vec4::ApplyQuaternionRotation(const Vec4& direction, const Quat& quat)
{
    const Vec4& imaginary = quat.getImag();
    const Real& vy = direction(1);
    const Real& vz = direction(2);
    const Real& qy = imaginary(1);
    const Real& qz = imaginary(2);
    Real qreal = quat.m_vec(3);
    Real q2minus1 = qreal * qreal - 0.5f;
    Vec4 ret;
    ret.setMul4(q2minus1, direction);
    Real imagDotDir = (direction(0) * imaginary(0)) + vy * qy + vz * qz;
    ret(0) += imagDotDir * imaginary(0);
    ret(1) += imagDotDir * imaginary(1);
    ret(2) += qz * imagDotDir;
    ret(3) += imagDotDir * imaginary(3);
    Vec4 imagCrossDir;
    const Real cx = imaginary(1) * direction(2) - qz * direction.Y();
    const Real cy = qz * direction(0) - imaginary(0) * direction(2);
    const Real cz = imaginary(0) * direction(1) - imaginary(1) * direction(0);
    imagCrossDir.set(cx, cy, cz, 0);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

struct Matrix3 { float m[9]; };
struct Point3 { float x, y, z; };

class RefObject
{
public:
    virtual void Destroy(unsigned flags);
    virtual void DeleteThis();
    long m_refCount;
};

class RigidBody : public RefObject
{
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual RigidBody* Clone();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual bool vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void GetTranslation(Vec4* out);
    virtual void GetRotation(Quat* out);
    virtual void SetType(void* type);
    virtual void SetOther(void* other);
    unsigned m_08;
    unsigned m_0C;
    unsigned m_10;
    unsigned m_14;
    unsigned m_18;
    unsigned m_1C;
    Quat m_rotation;
    Vec4 m_translation;
};

void __cdecl FUN_008d36a0(void* p);
void* __cdecl FUN_008dba50(unsigned size);

class RigidBodyT : public RigidBody
{
public:
    RigidBodyT(RigidBody* source);
    static void* operator new(unsigned size) { return FUN_008dba50(size); }
    static void operator delete(void* p) { FUN_008d36a0(p); }
};

class RigidBodyPtr
{
public:
    RigidBody* m_pObject;
    __declspec(noinline) RigidBodyPtr(RigidBody* p) : m_pObject(p)
    {
        if (m_pObject)
            InterlockedIncrement(&m_pObject->m_refCount);
    }
    __declspec(noinline) ~RigidBodyPtr()
    {
        if (m_pObject && InterlockedDecrement(&m_pObject->m_refCount) == 0)
            m_pObject->DeleteThis();
    }
    operator RigidBody*() const { return m_pObject; }
    RigidBody* operator->() const { return m_pObject; }
};

class CollisionObject : public RefObject
{
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual bool IsLinked();
    unsigned m_08;
    unsigned m_0C;
    RigidBody* m_pWorldObject;
    void FUN_008da000(RigidBody* body);
};

class CollisionHolder
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual CollisionObject* GetCollision();
};

class AVObject
{
public:
    unsigned m_00;
    unsigned m_04;
    unsigned m_08;
    unsigned m_0C;
    unsigned m_10;
    unsigned m_14;
    unsigned m_18;
    CollisionHolder* m_pCollision;
    unsigned m_20;
    unsigned m_24;
    unsigned m_28;
    unsigned m_2C;
    unsigned m_uFlags;
    Matrix3 m_kRotate;
    Point3 m_kTranslate;
    void NiAVObject_SetCollisionObject(CollisionObject* collision);
};

struct ExtraFlags { unsigned m_00, m_04, m_08, m_uFlags; };
ExtraFlags* __cdecl FUN_00aa60f0(AVObject* object);
__forceinline unsigned int IsEnabled(AVObject* object)
{
    ExtraFlags* extra = FUN_00aa60f0(object);
    return extra ? (extra->m_uFlags & 2) : 0;
}

bool __cdecl FUN_00424d20(const void* rtti, RigidBody* object);
extern const unsigned DAT_010f33b4;
extern unsigned DAT_01092a50;
extern unsigned DAT_00f7b120;
extern const Matrix3 DAT_00f72574;
extern const Point3 DAT_0108ec68;
extern unsigned char DAT_010f2a61;
extern void* DAT_00f79480;
void __cdecl FUN_004e5e40(Transform* out, const Matrix3* in);

struct ObjectRecData
{
    void* m_pWorld;
    bool m_bFlag;
    unsigned m_uiMode;
    unsigned m_uiNotify;
    unsigned m_uiIndex;
    unsigned m_ui14;
    unsigned m_uiFinal;
};
void __cdecl FUN_008d61d0(AVObject* root, ObjectRecData* data);
void __cdecl FUN_008d5790(AVObject* root, ObjectRecData* data, void* extra);

class World
{
public:
    unsigned m_00;
    unsigned m_04;
    unsigned m_08;
    unsigned m_0C;
    unsigned m_10;
    unsigned m_14;
    unsigned m_18;
    bool m_bAdding;
    bool bhkWorld_AddObjectsAndMoveController(AVObject* apObject, AVObject* apRoot);
};

// pdb: bhkWorld::AddObjectsAndMoveController | bhkWorld.obj | fnv360_0822_retail, objrun + bridge(vtable|caller_sim) + skyrim(objrun), high
bool World::bhkWorld_AddObjectsAndMoveController(AVObject* apObject, AVObject* apRoot)
{
    bool bres = false;
    World* const world = this;

    if (apObject && apRoot && IsEnabled(apRoot))
    {
        ObjectRecData recData;
        CollisionObject* pcol;
        unsigned int inotify = 0;
        if (apObject->m_pCollision)
        {
            pcol = apObject->m_pCollision->GetCollision();
            if (pcol)
            {
            RigidBody* pwo = pcol->m_pWorldObject;
            inotify = 1;
            if (pwo && !pcol->IsLinked())
            {
                world->m_bAdding = true;
                bres = true;
                if (apRoot != apObject)
                {
                    RigidBody* pbody = 0;
                    if (FUN_00424d20(&DAT_010f33b4, pwo))
                        pbody = pwo;
                    else
                    {
                        RigidBodyPtr spbhkBody(pwo->Clone());
                        RigidBody* pclone = spbhkBody;
                        if (pclone)
                        {
                            pcol->FUN_008da000(0);
                            pbody = new RigidBodyT(pclone);
                            Quat localRot;
                            Vec4 localPos;
                            pclone->GetTranslation(&localPos);
                            pclone->GetRotation(&localRot);
                            pbody->m_translation = localPos;
                            pbody->m_rotation.m_vec = localRot.m_vec;
                            pbody->SetType(&DAT_01092a50);
                            pbody->SetOther(&DAT_00f7b120);
                            pcol->FUN_008da000(pbody);
                            if (InterlockedDecrement(&pclone->m_refCount) == 0)
                                pclone->DeleteThis();
                            spbhkBody.m_pObject = 0;
                        }
                    }
                    if (pbody)
                    {
                        Vec4 pos;
                        Quat tmpRot;
                        Quat rot;
                        Vec4 tmp;
                        Transform objectTrans;
                        FUN_004e5e40(&objectTrans, &apObject->m_kRotate);
                        tmp.ApplyQuaternionRotation(pbody->m_translation,pbody->m_rotation);
                        pos.hkVector4_setTransformedPos(objectTrans, tmp);
                        tmpRot.FUN_00924360(objectTrans);
                        rot.FUN_008d3290(pbody->m_rotation, tmpRot);
                        tmp.setRotatedInverseDir(pbody->m_rotation, pos);
                        pbody->m_translation = tmp;
                        pbody->m_rotation.m_vec = rot.m_vec;
                        apRoot->NiAVObject_SetCollisionObject(pcol);
                        apObject->NiAVObject_SetCollisionObject(0);
                        apObject->m_uFlags = (apObject->m_uFlags & ~0x10) | 6;
                    }
                    else
                    {
                        apRoot->NiAVObject_SetCollisionObject(pcol);
                        apObject->NiAVObject_SetCollisionObject(0);
                        apObject->m_kRotate = DAT_00f72574;
                        apObject->m_kTranslate = DAT_0108ec68;
                        apObject->m_uFlags = (apObject->m_uFlags & ~0x10) | 6;
                    }
                }
            }
            }
        }
        recData.m_pWorld = world;
        recData.m_bFlag = true;
        if (DAT_010f2a61)
        {
            recData.m_uiMode = 10;
            FUN_008d61d0(apRoot, &recData);
        }
        recData.m_uiMode = 0;
        recData.m_uiNotify = inotify;
        recData.m_uiIndex = 0;
        recData.m_ui14 = 0;
        recData.m_uiFinal = 1;
        if (DAT_00f79480)
            FUN_008d5790(apRoot, &recData, DAT_00f79480);
    }
    return bres;
}
}

// @f3 0x008dfb90 (community match, verified in this file)
#include <math.h>
extern float DAT_00f79a58;
extern const float FUN_00e074c8;
namespace f3m_008dfb90 {

// 0x008dfb90: look-at target update (x87 Havok build). Turns the stored target into a direction, records whether
// it points below the horizon, re-aims the target from a bone offset (or lifts it), then clamps the target to a
// maximum distance from the head position. Built /O2 (the pack lists /Od).

struct hkQuaternion;
struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal() {}
    __forceinline hkSimdReal(const float& x) : m_real(x) {}
    __forceinline operator float() const { return m_real; }
};

__forceinline float hkSqrtInverseSafe(float r)
{
    if (r != 0.0f)
    {
        float l = (float)sqrt(r);
        return 1.0f / l;
    }
    return 0.0f;
}
struct hkQsTransform;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline hkVector4(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setZero4()
    {
        x = y = z = w = 0.0f;
    }
    __forceinline void add4(const hkVector4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setMul4(float s, const hkVector4& v)
    {
        x = s * v.x;
        y = s * v.y;
        z = s * v.z;
        w = s * v.w;
    }
    __forceinline void mul4(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void addMul4(float s, const hkVector4& v)
    {
        x += s * v.x;
        y += s * v.y;
        z += s * v.z;
        w += s * v.w;
    }
    // Havok's grouped dot product, used by setRotatedDir. The up test below uses the ungrouped sum: one helper for
    // both moves the x87 operand order of the first rotation (measured with f3diff); a guess at the source.
    __forceinline float dot3Grouped(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

    // addMul4 that reads the lanes into named locals first; setRotatedDir uses it for the cross-product term, which
    // gives the operand order of the second rotation's cross product (the plain addMul4 there does not; measured).
    __forceinline void addMul4Staged(float s, const hkVector4& v)
    {
        const float lanex = v.x;
        const float laney = v.y;
        const float lanez = v.z;
        const float lanew = v.w;
        x += s * lanex;
        y += s * laney;
        z += s * lanez;
        w += s * lanew;
    }
    __forceinline float dot3(const hkVector4& a) const
    {
        return x * a.x + y * a.y + z * a.z;
    }
    __forceinline hkSimdReal lengthSquared3() const
    {
        return x * x + y * y + z * z;
    }
    __forceinline hkSimdReal length3() const
    {
        float l2 = lengthSquared3();
        return (float)sqrt(l2);
    }
    __forceinline float lengthInverse3() const
    {
        return hkSqrtInverseSafe(lengthSquared3());
    }
    __forceinline void normalize3()
    {
        float invLen = lengthInverse3();
        mul4(invLen);
    }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b)
    {
        float cx = a.y * b.z - a.z * b.y;
        float cy = a.z * b.x - a.x * b.z;
        float cz = a.x * b.y - a.y * b.x;
        x = cx;
        y = cy;
        z = cz;
        w = 0.0f;
    }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);

    void FUN_008d2ca0(const hkQsTransform& t, const hkVector4& v);
    void FUN_008d2b00(const hkQsTransform& t, const hkVector4& v);
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkVector4& imag = quat.m_vec;
    float qreal = quat.m_vec.w;
    float q2minus1 = qreal * qreal - 0.5f;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    float imagDotDir = quat.m_vec.dot3Grouped(direction);
    ret.addMul4(imagDotDir, imag);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(imag, direction);
    ret.addMul4Staged(qreal, imagCrossDir);
    setAdd4(ret, ret);
}
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

struct hkaPose
{
    int unk00, unk04, unk08, unk0c;
    hkQsTransform* m_modelPose;
    int unk14, unk18;
    unsigned int* m_boneFlags;

    const hkQsTransform& hkaPose_calculateBoneModelSpace(int boneIdx);
    const hkVector4& FUN_00956290(int boneIdx);
    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx)
    {
        if (!(m_boneFlags[boneIdx] & 2))
            return m_modelPose[boneIdx];
        return hkaPose_calculateBoneModelSpace(boneIdx);
    }
};


struct LookAt8dfb90
{
    int unk00, unk04, unk08, unk0c;
    hkQsTransform m_transform;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84;
    hkaPose* m_pose;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    short unkb0;
    bool m_b2;
    char unkb3;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    hkVector4 m_target;
    int unke0, unke4, unke8, unkec;
    hkaPose* m_f0;
    int unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    int unk130, unk134, unk138, unk13c, unk140;
    short m_bone;
    short unk146;
    int unk148, unk14c;
    hkVector4 m_offset;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c;
    bool m_190;
    char unk191, unk192, unk193;
    int unk194, unk198, unk19c, unk1a0;
    bool m_1a4;

    void FUN_008dfb90();
};

// pdb: hkaFootPlacementIkSolver::doFootPlacement | hkaFootPlacementIkSolver.obj | fnv360_0721_beta, caller_sim, low
// pdb params: input, output, poseInOut
void LookAt8dfb90::FUN_008dfb90()
{
    hkVector4 direction;
    direction.FUN_008d2ca0(m_transform, m_target);
    direction.normalize3();

    hkVector4 up(0.0f, 1.0f, 0.0f, 0.0f);
    m_1a4 = up.dot3(direction) < 0.0f;
    if (m_b2 || m_1a4)
    {
        if (m_b2)
        {
            hkVector4 offset = m_offset;
            hkVector4 rotated;
            rotated.setRotatedDir(m_pose->getBoneModelSpace(m_bone).m_rotation, offset);
            rotated.setRotatedDir(m_transform.m_rotation, rotated);
            const float scale = 3.0f;      // named: one more function-level local settles R8/R9 and 0x508 (measured)
            rotated.mul4(scale);
            hkVector4 position;
            position.setZero4();
            if (m_190)
                position.add4(m_f0->FUN_00956290(1));
            position.FUN_008d2b00(m_pose->getBoneModelSpace(m_bone), position);
            position.FUN_008d2b00(m_transform, position);
            rotated.add4(position);
            m_target = rotated;
        }
        else
        {
            hkVector4 local;
            local.FUN_008d2ca0(m_transform, m_target);
            float height = 5.0f;
            if (local.x < 0.0f)
                height = FUN_00e074c8;
            hkVector4 position;
            position.setZero4();
            if (m_190)
                position.add4(m_f0->FUN_00956290(1));
            position.FUN_008d2b00(m_pose->getBoneModelSpace(m_bone), position);
            position.x += height;
            position.FUN_008d2b00(m_transform, position);
            m_target = position;
        }
    }

    {   // own scope: this position shares its frame slot with the branch locals above
    hkVector4 position;
    position.setZero4();
    if (m_190)
    {
        const hkVector4& head = m_f0->FUN_00956290(1);   // named here only; the other two adds take the call directly
        position.add4(head);
    }
    position.FUN_008d2b00(m_pose->getBoneModelSpace(m_bone), position);
    position.FUN_008d2b00(m_transform, position);
    hkVector4 difference;
    difference.setSub4(m_target, position);
    float distance = difference.length3();
    difference.mul4(difference.lengthInverse3());   // normalize3 written out; normalize3() here moves site 0x22
    bool tooFar = distance > DAT_00f79a58;
    if (tooFar)
    {
        difference.mul4(DAT_00f79a58);
        m_target.setAdd4(difference, position);
    }
    }
}
}   // namespace f3m_008dfb90

// @f3 0x008df210 (community match, verified in this file)
namespace f3m_008df210 {


extern const double DAT_00db75d0,DAT_00dba5c8;
struct Transform;
struct __declspec(align(16)) Vec {
 union { struct { float x,y,z,w; }; float m_quad[4]; }; Vec(){} Vec(float a,float b,float c,float d){x=a;y=b;z=c;w=d;}
 void FUN_008d2b00(const Transform&,const Vec&);
 __forceinline void set(const Vec& a){x=a.x;y=a.y;z=a.z;w=a.w;}
 __forceinline void set(float a,float b,float c,float d){x=a;y=b;z=c;w=d;}
 __forceinline void setMul4(float r,const Vec& v){x=r*v.x;y=r*v.y;z=r*v.z;w=r*v.w;}
 __forceinline void addMul4(float r,const Vec& v){x+=r*v.x;y+=r*v.y;z+=r*v.z;w+=r*v.w;}
 __forceinline void setAdd4(const Vec& a,const Vec& b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
 __forceinline float dot3(const Vec& v) const {return (x*v.x)+(y*v.y)+(z*v.z);}
 float& operator()(int i) { return m_quad[i]; } const float& operator()(int i) const { return m_quad[i]; }
 __forceinline void setCross(const Vec& v1,const Vec& v2){const float nx = v1(1) * v2(2) - v1(2) * v2(1); const float ny = v1(2) * v2(0) - v1(0) * v2(2); const float nz = v1(0) * v2(1) - v1(1) * v2(0);set(nx,ny,nz,0.0f);}
 __forceinline void setRotatedDir(const Vec& quat,const Vec& direction){
  float qreal=quat.w;
  Vec ret; ret.setMul4(qreal*qreal-0.5,direction);
  float imagDotDir=quat.dot3(direction);
  ret.addMul4(imagDotDir,quat);
  Vec imagCrossDir; imagCrossDir.setCross(quat,direction);
  ret.addMul4(qreal,imagCrossDir);
  this->setAdd4(ret,ret);
 }
 __forceinline void setInterpolate4(const Vec& a,const Vec& b,float t){
  float s=1.0f-t;
  for(int i=0;i<4;i++) m_quad[i]=s*a.m_quad[i]+t*b.m_quad[i];
 }
};
struct hkBool { char value; hkBool(bool b):value(b){} };
static __forceinline unsigned mask(const Vec& a);
static __forceinline Vec deltaAbs(const Vec& a,const Vec& b);
struct Cache {Vec from;Vec to;Vec normal;float fraction;};
struct CacheRow { Vec rowState; Cache slots[3]; };
struct Ray {
 Vec from;Vec to;int unk20,unk24,unk28,unk2c;Vec normal;float fraction;
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
 Vec up;int unkA0,unkA4,unkA8;unsigned char unkAC;
 void FUN_00468f40();
};
struct CastInput {Vec from;Vec to;unsigned char flag20;int filter;};
struct CastOutput {
 Vec normal;float fraction;int shapeKey;int unk18;int unk1c;int root;int unk24,unk28,unk2c;int unk30,unk34,unk38,unk3c;int hit;
 int unk44,unk48,unk4c;const void* rootBody;
};
struct World { virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2c(); virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3c(); virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4c(); virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5c(); virtual void slot60(); virtual void slot64(); virtual void slot68(); virtual void slot6c(); virtual void slot70(); virtual void slot74(); virtual void slot78(); virtual void slot7c(); virtual void slot80(); virtual void slot84(); virtual void slot88(); virtual void slot8c(); virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9c(); virtual void slota0(); virtual void slota4(); virtual void slota8(); virtual void slotac(); virtual void slotb0(); virtual void slotb4(); virtual void slotb8(); virtual void slotbc(); virtual void slotc0(); virtual void slotc4(); virtual bool cast(Ray*);};
struct Chain2 { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; World* world;};
struct Chain1 {int unk00,unk04;Chain2* next;};
struct Chain0 {Chain1* next;};
struct OwnerLink {int unk00,unk04;Chain0* link;};
struct Rotation {Vec basis;Vec q;};
struct RotOwner {int unk00,unk04,unk08,unk0c;Rotation* direct;int unk14,unk18;unsigned int* flags;Rotation* hkaPose_calculateBoneModelSpace(int);};
struct CastWorld {void hkpCachingShapePhantomRay_castRay(CastInput*,CastOutput*);};
struct Transform { Vec shift; Vec rotation; Vec scale; };
struct Controller {
 int unk000;
 int unk004;
 int unk008;
 int unk00c;
 Transform geometry;
 int unk040;
 int unk044;
 OwnerLink* link;
 int unk04c;
 int unk050;
 int unk054;
 int unk058;
 int group;
 int unk060;
 int unk064;
 int unk068;
 int unk06c;
 int unk070;
 int unk074;
 int unk078;
 int unk07c;
 int unk080;
 int unk084;
 RotOwner* rotation;
 int unk08c;
 CastWorld* castWorld;
 int unk094;
 int unk098;
 int unk09c;
 int unk0a0;
 int unk0a4;
 int unk0a8;
 int unk0ac;
 int unk0b0;
 int unk0b4;
 int unk0b8;
 int unk0bc;
 int unk0c0;
 int unk0c4;
 int unk0c8;
 int unk0cc;
 int unk0d0;
 int unk0d4;
 int unk0d8;
 int unk0dc;
 int unk0e0;
 int unk0e4;
 int unk0e8;
 int unk0ec;
 int unk0f0;
 int unk0f4;
 int unk0f8;
 int unk0fc;
 int unk100;
 int unk104;
 int unk108;
 int unk10c;
 int unk110;
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
 int unk194;
 int unk198;
 int unk19c;
 int unk1a0;
 int unk1a4;
 int unk1a8;
 int unk1ac;
 int unk1b0;
 int unk1b4;
 int unk1b8;
 int unk1bc;
 int unk1c0;
 int unk1c4;
 int unk1c8;
 int unk1cc;
 int unk1d0;
 int unk1d4;
 int unk1d8;
 int unk1dc;
 int unk1e0;
 int unk1e4;
 int unk1e8;
 int unk1ec;
 int unk1f0;
 int unk1f4;
 int unk1f8;
 int unk1fc;
 int unk200;
 int unk204;
 int unk208;
 int unk20c;
 int unk210;
 int unk214;
 int unk218;
 int unk21c;
 int unk220;
 unsigned char useHavok;
 unsigned char unk225;
 unsigned char unk226;
 unsigned char unk227;
 int unk228;
 CacheRow* cache;
 int mode;
 int unk234;
 unsigned short cursor;
 unsigned short row;
 int unk23c;
 unsigned char customNormal;
 unsigned char unk241;
 unsigned char unk242;
 unsigned char unk243;
 hkBool FUN_008df210(const Vec& from,const Vec& to,float& fraction,Vec* normal);
 __forceinline bool lookup(const Vec& from,const Vec& to){
  if(cache[row].slots[cursor].fraction!=-1.0f){
   Vec d=deltaAbs(cache[row].slots[cursor].from,from);
   if((mask(d)&14)==14){
    d=deltaAbs(cache[row].slots[cursor].to,to);
    if((mask(d)&14)==14){
     return true;
    }
   }
  }
  return false;
 }
};
void __cdecl FUN_008f4480(int,unsigned __int64);
extern Vec DAT_01092a50;
static __forceinline unsigned mask(const Vec& a) {return (a.x<=0.01f?8:0)|(a.y<=0.01f?4:0)|(a.z<=0.01f?2:0)|(a.w<=0.01f?1:0); }
static __forceinline Vec deltaAbs(const Vec& a,const Vec& b){Vec d;d.x=a.x-b.x;d.y=a.y-b.y;d.z=a.z-b.z;d.w=a.w-b.w;d.x=(float)fabs(d.x);d.y=(float)fabs(d.y);d.z=(float)fabs(d.z);d.w=(float)fabs(d.w);return d;}
static __forceinline void normalize(Vec& dst,const Vec& src) { dst.set(src); const float len=(src.y*src.y+src.x*src.x)+src.z*src.z; float scale;if(len!=0.0f){const float root=(float)sqrt(len);scale=1.0f/root;}else scale=0.0f; dst.x=src.x*scale;dst.y=src.y*scale;dst.z=src.z*scale;dst.w=scale*src.w; }

// pdb: bhkRagdollController::castRay | bhkRagdollController.obj | fnv360_0822_retail, uconst, low
// pdb params: arFromWS, arToWS, arHitFractionOut, arNormalWSOut
hkBool Controller::FUN_008df210(const Vec& from,const Vec& to,float& fraction,Vec* normal)
{
 Ray ray;CastInput input;CastOutput output;Vec transformed; Vec heightPoint;
 bool hit=false;
 float t;

 if(lookup(from,to)){
  normal->set(cache[row].slots[cursor].normal);
  Vec p; p.setInterpolate4(cache[row].slots[cursor].from,cache[row].slots[cursor].to,cache[row].slots[cursor].fraction);
  fraction=(from(2)-p(2))/(from(2)-to(2));
  hit=true;goto finish;
 }
 {
 unsigned int groupId=group;
 FUN_008f4480(0x27,0x2002200e);
 unsigned int filter=(groupId<<16)|0x27;
 ray.FUN_00468f40();
 ray.from.x=from.x; ray.from.y=from.y; ray.unk24=filter;ray.from(2)=from(2); ray.from.w=from.w;
 ray.up.set(DAT_01092a50); ray.to.set(to);
 if(!useHavok){
  World* world;
  OwnerLink* owner=link;
  if(owner){
      Chain1* info=owner->link->next;
      Chain2* record=info?info->next:0;
      World* w=record?record->world:0;
      world=w;
  }else world=0;
  if(world->cast(&ray)){fraction=ray.fraction;normalize(*normal,ray.normal);hit=true;goto finish;}
 }else if(castWorld){
  output.shapeKey=-1;output.root=-1;
  input.flag20=0;
  output.fraction=1.0f;output.hit=0;output.rootBody=0;
  input.from.set(from);input.filter=filter;input.to.set(to);
  castWorld->hkpCachingShapePhantomRay_castRay(&input,&output);
  if(output.rootBody){fraction=output.fraction;normalize(*normal,output.normal);hit=true;goto finish;}
 }
 }
finish:
 t=hit?fraction:0.0f;
 heightPoint.setInterpolate4(from,to,t);
 if(!hit){cache[row].slots[cursor].fraction=-1.0f;}
 else{
  Rotation* r=(!(*rotation->flags&2))?rotation->direct:rotation->hkaPose_calculateBoneModelSpace(0);
  transformed.FUN_008d2b00(geometry,r->basis);
  r=(!(*rotation->flags&2))?rotation->direct:rotation->hkaPose_calculateBoneModelSpace(0);
  Vec dir; dir.set(0.0f,0.0f,1.0f,0.0f);
  Vec up; up.setRotatedDir(r->q,dir);
  if(mode==2 && fabs(up(2))>DAT_00dba5c8) {
   const double floor=transformed(2)-DAT_00db75d0;
   if(heightPoint.z>floor) fraction=(from(2)-heightPoint.z+DAT_00db75d0)/(from(2)-to(2));
  }
  if(!customNormal){normal->set(Vec(0.0f,0.0f,1.0f,0.0f));}
  cache[row].slots[cursor].from.set(from);cache[row].slots[cursor].to.set(to);cache[row].slots[cursor].normal.set(*normal);cache[row].slots[cursor].fraction=fraction;
 }
 ++cursor;return hkBool(hit);
}
}   // namespace f3m_008df210

// @f3 0x008dd450 (community match, verified in this file)
namespace f3m_008dd450 {
extern double DAT_00dc1238;
struct Setting {
    virtual ~Setting();
    union { float f; int i; };
    const char* name;
    const float& Float() const { return f; }
    const int& Int() const { return i; }
    float FloatValue() const { return f; }
    int IntValue() const { return i; }
};
extern Setting DAT_010f2d98, DAT_010f2da4, DAT_010f2db0, DAT_010f2dbc, DAT_010f2dc8, DAT_010f2e10, DAT_010f2e28, DAT_010f2df8, DAT_010f2e04, DAT_010f2e1c;
extern float DAT_010f2c74;
extern const float DAT_00e074c8=-5.0f;
extern float __cdecl FUN_0089ea90();

class hkBool
{
    public:
        inline hkBool() { }
        inline hkBool(bool b) { m_bool = static_cast<char>(b); }
        inline operator bool() const { return m_bool != 0; }
        inline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
    private:
        char m_bool;
};


typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef int hkBool32;
typedef unsigned int hkUint32;
typedef short hkInt16;

namespace Math {
    inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
    inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / Math::sqrt(r); }
    inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}

struct Quaternion;
struct Transform;

struct VecComparison {
    enum Mask { MASK_NONE=0, MASK_W=1, MASK_Z=2, MASK_ZW=3, MASK_Y=4, MASK_YW=5, MASK_YZ=6, MASK_YZW=7,
                MASK_X=8, MASK_XW=9, MASK_XZ=10, MASK_XZW=11, MASK_XY=12, MASK_XYW=13, MASK_XYZ=14, MASK_XYZW=15 };
    hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
    int m_mask;
};

struct Vec {
    __forceinline Vec() { }
    __forceinline Vec(hkReal x, hkReal y, hkReal z, hkReal w=0);
    __forceinline Vec( const Vec& v);
    __forceinline void operator= ( const Vec& v );
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
    __forceinline void setAll3(hkReal x);
    __forceinline void setZero4();
    __forceinline void add4(const Vec& a);
    __forceinline void setAdd4(const Vec& a, const Vec& b);
    __forceinline void setSub4(const Vec& a, const Vec& b);
    __forceinline void setMul4(const Vec& a, const Vec& b);
    __forceinline void mul4(hkSimdRealParameter a);
    __forceinline void setMul4(hkSimdRealParameter r, const Vec& a);
    __forceinline void addMul4(hkSimdRealParameter r, const Vec& a);
    __forceinline void subMul4(hkSimdRealParameter r, const Vec& a);
    __forceinline void setCross( const Vec& a, const Vec& b );
    __forceinline void setInterpolate4( const Vec& a, const Vec& b, hkSimdRealParameter t);
    __forceinline hkBool32 equals3(const Vec &a, hkReal epsilon = 1e-3f ) const;
    __forceinline VecComparison compareLessThanEqual4(const Vec& a) const;
    __forceinline void setNeg3(const Vec& v);
    __forceinline void setNeg4(const Vec& v);
    __forceinline void setAbs4(const Vec& v);
    __forceinline void setRotatedDir(const Quaternion& q, const Vec& b);
    __forceinline void setRotatedInverseDir(const Quaternion& q, const Vec& b);
    void FUN_008d2ca0(const Transform& a, const Vec& b);
    __forceinline hkSimdReal dot3(const Vec& a) const;
    __forceinline hkSimdReal dot4(const Vec& a) const;
    __forceinline hkSimdReal length3() const;
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();
    __forceinline hkReal& operator() (int i);
    __forceinline const hkReal& operator() (int i) const;
    __forceinline void setXYZ0(const Vec& xyz);
    __forceinline void setReciprocal3(const Vec& v);
    inline hkSimdReal getSimdAt(int i) const;
    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct Quaternion {
    inline Quaternion() { }
    inline void operator= (const Quaternion& q);
    inline void setIdentity();
    inline void setInverse( const Quaternion &q );
    inline hkReal getReal() const;
    inline const Vec& getImag() const;
    inline void FUN_008d3290(const Quaternion& q0, const Quaternion& q1);
    inline void FUN_008db610(const Quaternion& q0, const Quaternion& q1);
    hkReal FUN_008db810() const;
    void FUN_008db880(Vec &axis) const;
    void FUN_009240d0(const Vec& axis, hkReal angle);
    void FUN_00924a70(const Vec& axis, Quaternion& restOut, hkReal& angleOut) const;
    void FUN_004e5c20();
    struct ByteBool FUN_00924140() const;
    Vec value;
};

inline hkReal& Vec::operator() (int i) { return (&x)[i]; }
inline const hkReal& Vec::operator() (int i) const { return (&x)[i]; }
__forceinline void Vec::setXYZ0(const Vec& xyz) { x = xyz.x; y = xyz.y; z = xyz.z; w = 0; }
inline void Vec::setReciprocal3(const Vec& v) { x = 1.0f / v.x; y = 1.0f / v.y; z = 1.0f / v.z; w = 1.0f; }
inline hkSimdReal Vec::getSimdAt(int i) const { return (&x)[i]; }
inline void Vec::operator= (const Vec& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
inline Vec::Vec(hkReal a, hkReal b, hkReal c, hkReal d) : x(a), y(b), z(c), w(d) { }
inline Vec::Vec( const Vec& v) { *this = v; }
inline void Vec::set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
inline void Vec::setAll3(hkReal a) { x = a; y = a; z = a; w = a; }
inline void Vec::setZero4() { x = y = z = w = 0; }
inline void Vec::add4(const Vec& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
inline void Vec::setAdd4(const Vec& v0, const Vec& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
inline void Vec::setSub4(const Vec& v0, const Vec& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
inline void Vec::setMul4(const Vec& a, const Vec& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
inline void Vec::mul4(hkSimdRealParameter rs) { hkReal s = hkReal(rs); x *= s; y *= s; z *= s; w *= s; }
inline void Vec::setMul4(hkSimdRealParameter rs, const Vec& a) { hkReal r = hkReal(rs); x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
inline void Vec::addMul4(hkSimdRealParameter rs, const Vec& a) { hkReal r = hkReal(rs); x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
inline void Vec::subMul4(hkSimdRealParameter rs, const Vec& a) { hkReal r = hkReal(rs); x -= r * a.x; y -= r * a.y; z -= r * a.z; w -= r * a.w; }
inline void Vec::setCross(const Vec& v1, const Vec& v2) {
    const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
    const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
    const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
    this->set( nx, ny, nz , 0.0f );
}
inline void Vec::setInterpolate4(const Vec& v0, const Vec& v1, hkSimdRealParameter rt) {
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    Vec& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}
inline VecComparison Vec::compareLessThanEqual4(const Vec& a) const {
    VecComparison ret;
    ret.m_mask =
        ((x<=a.x) ? VecComparison::MASK_X : 0) |
        ((y<=a.y) ? VecComparison::MASK_Y : 0) |
        ((z<=a.z) ? VecComparison::MASK_Z : 0) |
        ((w<=a.w) ? VecComparison::MASK_W : 0);
    return ret;
}
inline void Vec::setNeg4(const Vec& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
inline void Vec::setNeg3(const Vec& v) { x = -v.x; y = -v.y; z = -v.z; w =  v.w; }
inline void Vec::setAbs4(const Vec& v) { x = Math::fabs(v.x); y = Math::fabs(v.y); z = Math::fabs(v.z); w = Math::fabs(v.w); }
inline hkSimdReal Vec::dot3(const Vec& a) const { return (x * a.x) + ( y * a.y ) + ( z * a.z ); }
inline hkSimdReal Vec::dot4(const Vec& a) const { return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w * a.w ); }
inline hkSimdReal Vec::length3() const { return Math::sqrt((x * x) + ( y * y ) + ( z * z )); }
inline hkSimdReal Vec::lengthInverse3() const { hkReal l2 = (x*x) + (y*y) + (z*z); return l2 ? Math::sqrtInverse(l2) : 0; }
inline void Vec::normalize3() { this->mul4( this->lengthInverse3() ); }

inline const Vec& Quaternion::getImag() const { return value; }
inline hkReal Quaternion::getReal() const { return value(3); }
inline void Quaternion::operator= (const Quaternion& q) { value = q.value; }
inline void Quaternion::setIdentity() { value.set(0,0,0,1); }
void Quaternion::setInverse( const Quaternion &q ) { value.setNeg3( q.getImag() ); }

__forceinline void Vec::setRotatedDir(const Quaternion& quat, const Vec& direction) {
    hkReal qreal = quat.value(3);
    hkReal q2minus1 = qreal*qreal - 0.5f;

    Vec ret;
    ret.setMul4( q2minus1, direction );

    hkReal imagDotDir = quat.getImag().dot3( direction );
    ret.addMul4( imagDotDir, quat.getImag() );

    Vec imagCrossDir;
    imagCrossDir.setCross( quat.getImag(), direction );
    ret.addMul4( qreal, imagCrossDir );

    this->setAdd4( ret, ret );
}
__forceinline void Vec::setRotatedInverseDir(const Quaternion& quat, const Vec& direction) {
    hkReal qreal = quat.value(3);
    hkReal q2minus1 = qreal*qreal - 0.5f;

    Vec ret;
    ret.setMul4( q2minus1, direction );

    hkReal imagDotDir = quat.getImag().dot3( direction );
    ret.addMul4( imagDotDir, quat.getImag() );

    Vec imagCrossDir;
    imagCrossDir.setCross( direction, quat.getImag() );
    ret.addMul4( qreal, imagCrossDir );

    this->setAdd4( ret, ret );
}
inline hkBool32 Vec::equals3(const Vec &v, hkReal epsilon) const {
    Vec t;
    t.setSub4(*this, v);
    t.setAbs4( t );
    Vec epsilon_v;
    epsilon_v.setAll3( epsilon );
    return t.compareLessThanEqual4( epsilon_v ).allAreSet( VecComparison::MASK_XYZ );
}

inline void Quaternion::FUN_008d3290(const Quaternion& q0, const Quaternion& q1) {
    Vec vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.value.getSimdAt(3), q1.getImag());
    vec.addMul4(q1.value.getSimdAt(3), q0.getImag());
    hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.value.dot3( q1.value ) );
    value = vec;
    value(3) = real;
}
struct Transform {
    __forceinline Transform() { }
    __forceinline Transform(const Transform& other);
    __forceinline void setInterpolate4( const Transform& a, const Transform& b, hkSimdRealParameter t);
    __forceinline void setInverse( const Transform &t );
    __forceinline void setMul( const Transform &t1, const Transform &t2 );
    __forceinline void setMulInverseMul( const Transform& t1, const Transform &t2 );
    Transform& FUN_008dbcd0(const Transform& other) { position = other.position; rotation = other.rotation; scale = other.scale; return *this; }
    Vec position;
    Quaternion rotation;
    Vec scale;
};
Transform::Transform(const Transform& t) {
    position = t.position;
    rotation = t.rotation;
    scale = t.scale;
}
void Transform::setInverse( const Transform& t ) {
    position.setRotatedInverseDir(t.rotation, t.position);
    position.setNeg4(position);
    rotation.setInverse(t.rotation);

    Vec invScale; invScale.setReciprocal3( t.scale );
    scale.setXYZ0( invScale );
}
void Transform::setInterpolate4( const Transform& a, const Transform& b, hkSimdRealParameter t) {
    scale.setInterpolate4(a.scale, b.scale, t);
    position.setInterpolate4(a.position, b.position, t);

    const hkReal oneMinusT = 1.0f - hkReal(t);

    const hkReal signedT = ( a.rotation.value.dot4(b.rotation.value) < 0.0f ) ? -t : t;

    Quaternion out;
    out.value.setMul4( hkSimdReal(signedT), b.rotation.value);
    out.value.addMul4( hkSimdReal(oneMinusT), a.rotation.value);
    out.FUN_004e5c20();

    rotation = out;
}
void Transform::setMul( const Transform& aTb, const Transform& bTc ) {
    Vec extraTrans;
    extraTrans.setRotatedDir(aTb.rotation, bTc.position);
    position.setAdd4(aTb.position, extraTrans);
    rotation.FUN_008d3290(aTb.rotation, bTc.rotation);
    scale.setMul4(aTb.scale, bTc.scale);
}
void Transform::setMulInverseMul( const Transform& a, const Transform &b ) {
    Transform h;
    h.setInverse( a );
    setMul(h, b);
}

template <typename T>
struct Array {
    inline T& operator[] (int i) { return m_data[i]; }
    inline const T& operator[] (int i) const { return m_data[i]; }
    inline int getSize() const { return m_size; }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};
struct Skeleton {
    const char* name;
    hkInt16* parentIndices;
    int numParentIndices;
    void** bones;
    int numBones;
};
struct Pose {
    typedef hkUint32 PoseFlag;
    enum PropagateOrNot { DONT_PROPAGATE = 0, PROPAGATE = 1 };
    __forceinline const Transform& getBoneLocalSpace (int boneIdx) const;
    __forceinline const Transform& getBoneModelSpace (int boneIdx) const;
    __forceinline void setBoneLocalSpace (int boneIdx, const Transform& boneLocal);
    __forceinline void setBoneModelSpace (int boneIdx, const Transform& boneModel, PropagateOrNot propagateOrNot);
    Transform& FUN_00956290(int);
    Transform& FUN_00956b90(int,int);
    const Skeleton* skeleton;
    mutable Array<Transform> localPose;
    mutable Array<Transform> modelPose;
    mutable Array<PoseFlag> boneFlags;
    mutable hkBool modelInSync;
    mutable hkBool localInSync;
    enum { F_BONE_LOCAL_DIRTY = 0x1, F_BONE_MODEL_DIRTY = 0x2, F_BONE_INTERNAL_FLAG1 = 0x4 };
    __forceinline int isFlagOn (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline void setFlag (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline void clearFlag (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline int isFlagOnExplicit (PoseFlag flag, PoseFlag enumToCheck) const;
    __forceinline void setFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const;
    __forceinline void clearFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const;
    __forceinline void makeAllChildrenLocalSpace (int boneIdx) const;
    __forceinline void makeFirstChildrenModelSpace (int boneIdx) const;
    const Transform& hkaPose_calculateBoneModelSpace(int) const;
};
int Pose::isFlagOn (int boneIdx, PoseFlag enumToCheck) const { return boneFlags[boneIdx] & enumToCheck; }
void Pose::setFlag (int boneIdx, PoseFlag enumToCheck) const { boneFlags[boneIdx] |= enumToCheck; }
void Pose::clearFlag (int boneIdx, PoseFlag enumToCheck) const { boneFlags[boneIdx] &= static_cast<PoseFlag>(~enumToCheck); }
int Pose::isFlagOnExplicit (PoseFlag flag, PoseFlag enumToCheck) const { return flag & enumToCheck; }
void Pose::setFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const { flag |= enumToCheck; }
void Pose::clearFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const { flag &= static_cast<PoseFlag>(~enumToCheck); }
const Transform& Pose::getBoneModelSpace (int boneIdx) const {
    if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY)) {
        return modelPose[boneIdx];
    } else {
        return hkaPose_calculateBoneModelSpace(boneIdx);
    }
}
const Transform& Pose::getBoneLocalSpace (int boneIdx) const {
    if (! isFlagOn (boneIdx, F_BONE_LOCAL_DIRTY)) {
        return localPose[boneIdx];
    } else {
        const Transform& modelFromBone = modelPose[boneIdx];
        const hkInt16 parentIdx = skeleton->parentIndices[boneIdx];
        if (parentIdx != -1) {
            const Transform& modelFromParent = getBoneModelSpace(parentIdx);
            localPose[boneIdx].setMulInverseMul(modelFromParent, modelFromBone);
        } else {
            localPose[boneIdx].FUN_008dbcd0(modelFromBone);
        }
        clearFlag (boneIdx, F_BONE_LOCAL_DIRTY);
        return localPose[boneIdx];
    }
}
void Pose::makeAllChildrenLocalSpace(int boneIdx) const {
    const int numBones = skeleton->numBones;
    setFlag(boneIdx, F_BONE_INTERNAL_FLAG1);
        for (int i= boneIdx+1; i<numBones; ++i) {
            const hkInt16 parentId = skeleton->parentIndices[i];
            if (isFlagOn(parentId, F_BONE_INTERNAL_FLAG1)) {
                getBoneLocalSpace( i );
                setFlag( i, F_BONE_INTERNAL_FLAG1);
                modelInSync = false;
            }
        }
        for (int i= boneIdx+1; i < numBones; ++i) {
            PoseFlag f = boneFlags[i];
            if (isFlagOnExplicit( f, F_BONE_INTERNAL_FLAG1)) {
                setFlagExplicit( f, F_BONE_MODEL_DIRTY);
                clearFlagExplicit( f, F_BONE_INTERNAL_FLAG1);
                boneFlags[i] = f;
            }
        }
}
void Pose::makeFirstChildrenModelSpace(int boneIdx) const {
    const int numBones = skeleton->numBones;
    for (int i= boneIdx+1; i<numBones; ++i) {
        const hkInt16 parentId = skeleton->parentIndices[i];
        if (parentId == boneIdx) {
            getBoneModelSpace( i );
            boneFlags[i] = F_BONE_LOCAL_DIRTY;
            localInSync = false;
        }
    }
}
void Pose::setBoneLocalSpace (int boneIdx, const Transform& boneLocal) {
    makeAllChildrenLocalSpace(boneIdx);
    localPose[boneIdx].FUN_008dbcd0(boneLocal);
    boneFlags[boneIdx] = F_BONE_MODEL_DIRTY;
    modelInSync = hkBool(false);
}
void Pose::setBoneModelSpace (int boneIdx, const Transform& boneModel, PropagateOrNot propagateOrNot) {
    if (! propagateOrNot ) {
        makeFirstChildrenModelSpace(boneIdx);
    } else {
        makeAllChildrenLocalSpace(boneIdx);
    }
    modelPose[boneIdx].FUN_008dbcd0(boneModel);
    boneFlags[boneIdx] = F_BONE_LOCAL_DIRTY;
    localInSync = false;
}
inline void Quaternion::FUN_008db610(const Quaternion& q0, const Quaternion& q1) {
    Vec h; h.setCross(q1.getImag(), q0.getImag());
    h.subMul4(q0.value.getSimdAt(3), q1.getImag());
    h.addMul4(q1.value.getSimdAt(3), q0.getImag());
    value = h;
    value(3) = q0.value.dot4(q1.value);
}
struct FootInput {
    Transform m_originalAnkleTransformMS;
    Transform m_worldFromModel;
    hkBool m_footPlacementOn;
    void* m_raycastInterface;
    hkReal m_onOffGain;
    hkReal m_groundAscendingGain;
    hkReal m_groundDescendingGain;
    hkReal m_footPlantedGain;
    hkReal m_footRaisedGain;
    hkReal m_footUnlockGain;
    void FUN_0095bbb0();
    FootInput() { FUN_0095bbb0(); }
};
struct FootOutput {
    hkReal m_verticalError;
    hkBool m_hitSomething;
};
struct Solver {
    int unk00,unk04,unk08,unk0c;
    const Skeleton* m_skeleton;
    hkInt16 m_hipIndex;
    hkInt16 m_kneeIndex;
    hkInt16 m_ankleIndex;
    Vec m_kneeAxisLS;
    Vec m_footEndLS;
    Vec m_worldUpDirectionWS;
    Vec m_modelUpDirectionMS;
    hkReal m_originalGroundHeightMS;
    hkReal m_footPlantedAnkleHeightMS;
    hkReal m_footRaisedAnkleHeightMS;
    hkReal m_maxAnkleHeightMS;
    hkReal m_minAnkleHeightMS;
    hkReal m_cosineMaxKneeAngle;
    hkReal m_cosineMinKneeAngle;
    hkReal m_raycastDistanceUp;
    hkReal m_raycastDistanceDown;
    hkBool m_useFootLocking;
    void FUN_0095c070(const FootInput&,FootOutput&,Pose&);
};
struct RayResult { Vec from,to,normal; float fraction; };
struct Leg {
    Solver* solver;float error;int unk08,unk0c;
    RayResult casts[2];Transform ankle;short ragdollBone;
};
struct ConstraintBase {
    virtual void vf00();virtual void vf04();virtual void vf08();virtual void vf0c();
    virtual int type();
};
struct ConstraintData : ConstraintBase {
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    Vec columns[8];
    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    unsigned char unkc0,unkc1,unkc2,axis;
    ConstraintData* FUN_0095b0f0();
};
struct Constraint {
    int unk00,unk04,unk08;ConstraintData* data;
};
struct Ragdoll {
    int unk00,unk04,unk08,unk0c,unk10;
    Constraint** constraints;int count,cap;int* boneToConstraint;
    Constraint* constraint(int bone) {
        int i=boneToConstraint[bone]-1;
        return i<0?0:constraints[i];
    }
};
struct Controller {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    Ragdoll* ragdoll;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    Pose* pose;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
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
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    bool initFoot;
    bool easeOut;
    bool active;
    bool resetWeight;
    int unk224;
    int easeFrame;
    Array<Leg> legs;
    unsigned short currentCast;
    unsigned short currentFoot;
    float vertError;
    bool alignFeet;
    bool useFootEnd;
    bool useCurrent;
    bool downCast;
    float downDistance;
    Solver* foot(int n) { return legs[n].solver; }
    void FUN_008dd450(Transform& world);
};
__forceinline void storeIf(float& d, float v, bool c) { if (c) d = v; }
__forceinline float smaller(float a,float b) {return a<b?a:b;}
__forceinline float larger(float a,float b) {return a>b?a:b;}
void Controller::FUN_008dd450(Transform& world) {
    FootInput in;
    FootOutput out;
    in.m_worldFromModel.FUN_008dbcd0(world);
    in.m_onOffGain=!resetWeight?DAT_010f2d98.f:1.0f;
    in.m_groundAscendingGain=DAT_010f2da4.f;in.m_groundDescendingGain=DAT_010f2db0.f;
    in.m_footRaisedGain=DAT_010f2dbc.f;in.m_footPlantedGain=DAT_010f2dc8.f;
    in.m_footPlacementOn=!resetWeight?!easeOut:false;
    Controller* rays=this;
    in.m_raycastInterface=rays;
    {
    Transform root(pose->getBoneModelSpace(0));
    Vec translation(root.position);
    float oldZ=translation(2);
    float baseZ=(oldZ+vertError);
    float newZ=oldZ+(vertError*DAT_010f2e10.f);
    float delta=newZ-baseZ;
    float maxDelta=DAT_010f2e28.f;
    if(delta>maxDelta) newZ=baseZ+maxDelta;
    if(delta<-maxDelta) newZ=baseZ-maxDelta;
    Vec& worldPosition=in.m_worldFromModel.position;
    worldPosition.add4(Vec(0.0f,0.0f,newZ-oldZ));
    translation(2)=newZ;
    root.position=translation;
    pose->setBoneModelSpace(0,root,Pose::PROPAGATE);
    }
    for(int n=0;n<legs.getSize();++n) {
        Vec savedEnd(foot(n)->m_footEndLS);
        foot(n)->m_raycastDistanceDown=downDistance;
        if(!useFootEnd) foot(n)->m_footEndLS.setZero4();
        short ankleBone=foot(n)->m_ankleIndex;
        Transform original(pose->getBoneLocalSpace(ankleBone));
        in.m_originalAnkleTransformMS.FUN_008dbcd0(pose->getBoneModelSpace(foot(n)->m_ankleIndex));
        currentFoot=(unsigned short)n;currentCast=0;
        float begin=FUN_0089ea90();
        Pose& thePose=*pose;
        foot(n)->FUN_0095c070(in,out,thePose);
        float end=FUN_0089ea90();
        legs[n].error=out.m_verticalError;
        DAT_010f2c74+=(end-begin)*1000.0;
        Transform solved(pose->getBoneLocalSpace(ankleBone));
        if(alignFeet) {
            if(useCurrent) legs[n].ankle.FUN_008dbcd0(solved);
            if(legs[n].ragdollBone!=-1) {
                Constraint* c=ragdoll->constraint(legs[n].ragdollBone);
                ConstraintData* data=c->data;
                if(data->type()==13) data=data->FUN_0095b0f0();
                if(data->type()==2) {
                    Quaternion rest;Vec axis(data->columns[data->axis]);float angle;
                    Quaternion& rotation=solved.rotation;
                    rotation.FUN_00924a70(axis,rest,angle);
                    rotation.FUN_009240d0(axis,angle);
                }
            }
            Transform& cached=legs[n].ankle;
            original.setInterpolate4(solved,cached,0.5f);
            cached.FUN_008dbcd0(original);
        }
        pose->setBoneLocalSpace(ankleBone,original);
        Vec& footEndOut=foot(n)->m_footEndLS;
        footEndOut=savedEnd;
    }
    if(useCurrent) useCurrent=false;
    float bias=downCast?1.0f:DAT_010f2df8.f;
    float minError=smaller(legs[0].error,legs[1].error);
    float maxError=larger(legs[0].error,legs[1].error);
    if(!easeOut) {
        float error=bias*minError+(1.0f-bias)*maxError;
        float gain=error*DAT_010f2e04.f;
        storeIf(vertError,vertError+gain,true);
    }
    vertError=smaller(larger(vertError,DAT_00e074c8),5.0f);
    if(easeOut) {
        vertError*=DAT_00dc1238;
        ++easeFrame;
        if(DAT_010f2e1c.i==easeFrame) {
            easeFrame=0;easeOut=false;active=false;useCurrent=true;
        }
    }
    resetWeight=false;
}

}   // namespace f3m_008dd450

// @f3 0x008d95f0 (community match, verified in this file)
namespace f3m_008d95f0 {
// FUN_008d95f0: flush of the queued entities into the Havok world, then the physics step of the owner.
// Optimised code: measured under /MT /O2 /GS /EHsc /Gy, not under the listed /Od set.
// Builds on the stored draft best1.cpp (another contributor). Kept: its layouts, callee signatures, statement
// order and the vector helpers (setSub4, setAbs4, setAll3, compareLessThanEqual4, equals3 follow the Havok 5.5.0
// x87 inline definitions). Changed: the entity array is a plain pointer array; the entity accessors follow
// hkpWorldObject::getUserData, hkpEntity::getSimulationIsland and hkpSimulationIsland::isFixed; removeEntity
// takes entities[i] again instead of the local copy; the step-count clamp is written 2.0 > scaled; the blend
// global is stored through a double after the step count; the mode-2 step divides by the limit global.
// The tau sum carries two redundant pairs of parentheses on its first term, (K*((1.0f-c))): they leave no code
// but make that term the heavier operand, so (1 - c) and K*(1 - c) are formed first, as in the original.



class Bool95 {
  public:
    inline Bool95() {}
    inline Bool95(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
  private:
    char m_bool;
};
namespace hkMath
{
    inline float __cdecl fabs(float r) { return ::fabsf(r); }
}
class hkVector4Comparison
{
  public:
    enum Mask { MASK_NONE = 0, MASK_W = 1, MASK_Z = 2, MASK_Y = 4, MASK_X = 8, MASK_XYZ = 14, MASK_XYZW = 15 };
    int allAreSet( Mask m ) const { return (m_mask & m) == m; }
    int m_mask;
};
struct FNV_ALIGN(16) Vec4d95
{
    __forceinline void setAll3(float a);
    __forceinline void setSub4(const Vec4d95& a, const Vec4d95& b);
    __forceinline void setAbs4(const Vec4d95& v);
    __forceinline hkVector4Comparison compareLessThanEqual4(const Vec4d95& a) const;
    __forceinline int equals3(const Vec4d95 &a, float epsilon = 1e-3f ) const;
    float x,y,z,w;
};
inline void Vec4d95::setAll3(float a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void Vec4d95::setSub4(const Vec4d95& v0, const Vec4d95& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void Vec4d95::setAbs4(const Vec4d95& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
}
inline hkVector4Comparison Vec4d95::compareLessThanEqual4(const Vec4d95& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<=a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<=a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<=a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<=a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline int Vec4d95::equals3(const Vec4d95 &v, float epsilon) const
{
	Vec4d95 t;
	t.setSub4(*this, v);
	t.setAbs4( t );
	Vec4d95 epsilon_v;
	epsilon_v.setAll3( epsilon );
	return t.compareLessThanEqual4( epsilon_v ).allAreSet( hkVector4Comparison::MASK_XYZ );
}
extern Vec4d95 DAT_01092a50;
extern const double DAT_00dc8040;
struct Motion95 {
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
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    Vec4d95 first;
    Vec4d95 second;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    float inverse0;
    float inverse1;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    int steps;
    unsigned unk2b8;
    unsigned unk2bc;
    float inverseSteps;
    void FUN_0090b500();
};
struct Link95 {
    unsigned unk00,unk04; Motion95* motion; unsigned unk0c,flags;
};
struct State95;
struct Entity95 {
    unsigned unk00,unk04,unk08; unsigned long m_userData;
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
    State95* state;
    void FUN_009316f0();
    inline unsigned long getUserData() const;
    inline State95* getSimulationIsland() const;
};
inline unsigned long Entity95::getUserData() const { return m_userData; }
inline State95* Entity95::getSimulationIsland() const { return state; }
struct State95 {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; unsigned short id;
    inline Bool95 isFixed() const;
};
inline Bool95 State95::isFixed() const { return id == 0xffff; }

struct World95 {
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
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    int mode;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    float time0;
    float time1;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    float inverse0;
    float inverse1;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    int steps;
    unsigned unk2b8;
    unsigned unk2bc;
    float inverseSteps;
    void hkpWorld_addEntityBatch(Entity95**,unsigned,int);
    Bool95 FUN_009037f0(Entity95*);
    void FUN_009023a0();
    void FUN_00902dd0(float);
};
struct Job95 {void FUN_00942000(float,Bool95);void FUN_00942060();};

struct Finish95 {virtual void v00();virtual void v04();virtual void v08();virtual void Apply(float);};
struct Service95 {virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void Tick();};
extern Service95* DAT_010f3400;
extern bool DAT_010f2a60,DAT_010f2a62,DAT_010f2a63;
extern float DAT_010f2a84,DAT_010f2a6c,DAT_010f2be8,DAT_010f2c00,DAT_010f2bc4,DAT_010f2bd0;
extern unsigned DAT_00f7947c,DAT_010f2a74;
extern int DAT_010f2a78;
extern float DAT_00f79460,DAT_00f7945c,DAT_00f79464;
extern DWORD DAT_0116913c;
extern "C" void* (__stdcall *DAT_00fdf044)(DWORD);
void __cdecl FUN_00929570(World95*,State95*);
void __cdecl FUN_00944800(void*);
int __cdecl FUN_00954d20(float);
struct Owner95 {
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual World95* GetWorld();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    Job95* job;
    unsigned unk14;
    Finish95* finish;
    unsigned char unk1c; bool active; unsigned short unk1e;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    Entity95** entities;
    unsigned count;
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
    float saved0;
    float saved1;
    void FUN_008d48d0();void FUN_008d6290();void FUN_008d9100(float);
    void FUN_008d3f20(float);void FUN_008d4020();void FUN_008d4a40();
    bool FUN_008d95f0();
};
bool Owner95::FUN_008d95f0()
{
    DAT_010f2a60=true;
    bool result=false;
    if(!DAT_010f2a63) DAT_010f2a84=0;
    if(count>0) {
        if(!DAT_010f2a62) {
            if(count>=3000) count=3000;
            unsigned take=count<DAT_00f7947c?count:DAT_00f7947c;
            unsigned remain=count-take;
            World95* world=GetWorld();
            if(world) {
                world->hkpWorld_addEntityBatch(entities+remain,take,0);
                bool propagated=false;
                for(unsigned i=remain;i<count;++i) {
                    Entity95* entity=entities[i];
                    Link95* link=entity?(Link95*)entity->getUserData():0;
                    if(link) link->flags&=~16U;
                    else {world->FUN_009037f0(entities[i]);}
                    if(!propagated) {
                        State95* state=entities[i]->getSimulationIsland();
                        if(state && !state->isFixed()) {FUN_00929570(world,state);propagated=true;}
                    }
                    if(!(link && link->motion?link->motion->first:DAT_01092a50).equals3(DAT_01092a50) ||
                       !(link && link->motion?link->motion->second:DAT_01092a50).equals3(DAT_01092a50))
                    {
                        if(link && link->motion)link->motion->FUN_0090b500();
                    }
                    entities[i]->FUN_009316f0();
                }
                memset(entities+remain,0,take*sizeof(Entity95*));count=remain;
            }
            DAT_010f2a62=true;
        }
        FUN_008d48d0();FUN_008d6290();
    }
    FUN_008d9100(DAT_00f79460);
    if(active && DAT_010f2a74) {
        unsigned iterations=DAT_010f2a74;
        if(DAT_010f2a78!=2) {
            float baseStep=DAT_010f2a6c/DAT_010f2be8;

            World95* world=GetWorld();
            float scaled=(float)(4.0*baseStep);
            float clamped=2.0>scaled?2.0f:scaled;
            int n=(int)clamped;
            world->steps=n;world->inverseSteps=1.0f/n;
            double blend=DAT_00f7945c;
            DAT_010f2c00=blend;
            float f=(float)((DAT_00dc8040*((1.0f-DAT_010f2c00)))+DAT_00dc8040*(DAT_010f2c00*baseStep));
            world->time0=f;world->inverse0=world->time1/f;world->inverse1=f/world->time1;
        } else {
            float factor=(float)ceil(DAT_00f79464/DAT_010f2bc4);
            float step=DAT_010f2bc4;
            if(factor<DAT_010f2bd0) {factor=DAT_010f2bd0;step=DAT_00f79464/DAT_010f2bd0;}
            World95* world=GetWorld();
            float old0=world->time0;saved0=old0;
            float time0=old0+(DAT_00f79464/(step*factor)-1.0f);
            float old1=world->time1;saved1=old1;
            float time1=old1+(DAT_00f79464/(step*factor)-1.0f);
            world->time0=time0;world->time1=time1;
            int n=FUN_00954d20(factor);world->steps=n;world->inverseSteps=1.0f/n;
        }
        while(iterations) {
            --iterations;
            if(job && GetWorld()->mode==3) {
                GetWorld()->FUN_009023a0();job->FUN_00942000(DAT_010f2a6c,true);job->FUN_00942060();
            } else GetWorld()->FUN_00902dd0(DAT_010f2a6c);
            DAT_010f3400->Tick();
        }
        if(DAT_010f2a78==2) {GetWorld()->time0=saved0;GetWorld()->time1=saved1;}
        FUN_008d3f20(DAT_00f79460);
        if(finish) {finish->Apply(0);FUN_00944800(DAT_00fdf044(DAT_0116913c));}
        FUN_008d4020();result=true;
    }
    if(unk58>0) FUN_008d4a40();
    DAT_010f2a60=false;
    return result;
}
}   // namespace f3m_008d95f0

// @f3 0x008c7a10 (community match, verified in this file)
namespace f3m_008c7a10 {
struct MemoryManager { void FUN_0086ba60(void*); };
extern MemoryManager DAT_01090a78;
struct Obj {
    void FUN_008c7590();
    Obj* FUN_008c7a10(unsigned flags);
};
// pdb: NiTStringPointerMap<NiPointer<NiSequence> >::`scalar deleting destructor' | NiKeyframeManager.obj | fnv360_0822_debug, objrun_open, low
Obj* Obj::FUN_008c7a10(unsigned flags) {
    FUN_008c7590();
    if (flags & 1) DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}

// @f3 0x008c7a30 (community match, verified in this file)
namespace f3m_008c7a30 {
namespace fn_008c7a30 {
void* __cdecl AllocBuckets(unsigned int bytes);
void* __cdecl ClearBuckets(void* dst, int val, unsigned int bytes);
struct BaseObject {
    int m_baseFields[12];
    virtual void vf00();
    BaseObject();
};
struct PointerMapBase {
    unsigned int m_hashSize;
    void* m_hashTable;
    unsigned int m_count;
    unsigned char m_allocatorState;
    virtual void vf00();
    PointerMapBase(unsigned int hashSize = 37) : m_hashSize(hashSize), m_count(0) {
        m_hashTable = AllocBuckets(sizeof(void*) * hashSize);
        ClearBuckets(m_hashTable, 0, sizeof(void*) * m_hashSize);
        m_allocatorState = 0;
    }
};
struct PointerMap : PointerMapBase {
    virtual void vf00();
    PointerMap() : PointerMapBase(37) {}
};
struct FUN_008c7a30 : BaseObject {
    PointerMap m_map;
    virtual void vf00();
    FUN_008c7a30();
};
// pdb: NiKeyframeManager::NiKeyframeManager | NiKeyframeManager.obj | tesv_win, uvref, medium
FUN_008c7a30::FUN_008c7a30() : BaseObject(), m_map() {
}
}
}   // namespace f3m_008c7a30
