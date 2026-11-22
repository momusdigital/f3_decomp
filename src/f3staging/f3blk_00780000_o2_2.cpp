#include <math.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00780000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00794c40 (community match, verified in this file)
namespace f3m_00794c40 {


struct FUN_005a22f0_Obj {
    void FUN_005a22f0();
};

extern "C" __declspec(dllimport) LONG __stdcall InterlockedIncrement(LONG volatile* Addend);

struct FUN_00794c40_Obj {
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
    FUN_005a22f0_Obj* unk118;

    void FUN_00794c40(int value);
};

// pdb: UpdateTempEffect | ProcessLists.obj | fnv360_0822_debug, objrun_open, low
void __thiscall FUN_00794c40_Obj::FUN_00794c40(int value)
{
    FUN_005a22f0_Obj* oldValue = unk118;

    if (oldValue != (FUN_005a22f0_Obj*)value) {
        if (oldValue != 0) {
            oldValue->FUN_005a22f0();
        }

        unk118 = (FUN_005a22f0_Obj*)value;

        if (value != 0) {
            InterlockedIncrement((LONG volatile*)((char*)value + 0x18));
        }
    }
}
}   // namespace f3m_00794c40

// @f3 0x0078c970 (community match, verified in this file)
namespace f3m_0078c970 {


namespace f3m_0078c970 {
extern long (__stdcall* DAT_00d9b06c)(long volatile*, long, long);
struct SpinLock
{
    volatile LONG owner;
    LONG count;

    void FUN_00409a80(int flags);
    void Unlock()
    {
        if (--count == 0)
            { long cur = owner; DAT_00d9b06c(&owner, 0, cur); }
    }
};

struct Actor;
extern Actor* DAT_0107a104;
extern int DAT_00f5ec8c;

struct Actor
{
    float FUN_004edbf0(Actor* other, int a, int b);
};

struct ActorList
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
    Actor* items[50];
    int count;
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
    unsigned char buffer[0x10000];
    SpinLock lock;

    void FUN_0078c970();
};

// pdb: ProcessLists::SortActorsCloseToPlayer | ProcessLists.obj | fnv360_0721_retail, call_seq, medium
void ActorList::FUN_0078c970()
{
    lock.FUN_00409a80(0);
    int last = count - 1;
    int h;
    for (h = 1; h <= last / 9; h = 3 * h + 1)
        ;
    for (; h > 0; h /= 3) {
        for (int i = h; i <= last; i++) {
            int j = i;
            Actor* value = items[i];
            while (j >= h) {
                Actor* prev = items[j - h];
                float keyValue = value->FUN_004edbf0(DAT_0107a104, 0, 0);
                volatile float keyPrev = prev->FUN_004edbf0(DAT_0107a104, 0, 0);
                if (!(keyValue < keyPrev))
                    break;
                items[j] = items[j - h];
                j -= h;
            }
            items[j] = value;
        }
    }
    while (this && count > DAT_00f5ec8c) {
        items[count - 1] = 0;
        count--;
    }
    lock.Unlock();
}
}
}   // namespace f3m_0078c970

// @f3 0x00796730 (community match, verified in this file)
namespace f3m_00796730 {
namespace task796730 {
struct Entry { int unk00,unk04; void FUN_007bb870(int,int); };
struct Base { virtual void Slot(); Entry first,second,third; Base(int); ~Base(); };
struct FUN_00796730: Base { FUN_00796730(int); virtual void Slot(); };
// pdb: CombatActionAttackRangedExplosive::CombatActionAttackRangedExplosive | CombatActions.obj | fnv360_0822_retail, uvref, medium
// pdb params: aeType
FUN_00796730::FUN_00796730(int x):Base(x) {
 first.FUN_007bb870(3,0); first.FUN_007bb870(8,0);
 second.FUN_007bb870(5,1); second.FUN_007bb870(6,0); second.FUN_007bb870(11,0); second.FUN_007bb870(10,0);
 third.FUN_007bb870(0,1);
}
}
}   // namespace f3m_00796730

// @f3 0x00796180 (community match, verified in this file)
namespace f3m_00796180 {
namespace combat_action_ctor {
struct ActionDescriptor { unsigned int value,unk04,unk08; };
extern const ActionDescriptor DAT_00f6f170[];
struct ListNode { void* data; ListNode* next; __forceinline ListNode() throw() : data(0),next(0) {} };
struct CombatAction {
 virtual bool Evaluate(void*,void*,void*);
 ListNode conditions,values,ownedData,actions;
 unsigned int actionType,descriptor;
 CombatAction(unsigned int);
};
// pdb: CombatAction::CombatAction | CombatAction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeType
CombatAction::CombatAction(unsigned int type) { actionType=type;descriptor=DAT_00f6f170[type].value; }
}
}   // namespace f3m_00796180

// @f3 0x00796c00 (community match, verified in this file)
namespace f3m_00796c00 {
namespace task1359 {
struct StateMap {
    int unk00, unk04;
    void FUN_007bb870(int, int);
};
struct FUN_00796180 {
    virtual ~FUN_00796180();
    StateMap preconditions, effects, values;
    int unk1c, unk20, unk24, unk28;
    FUN_00796180(int action);
};
struct FUN_00796c00 : FUN_00796180 {
    virtual ~FUN_00796c00();
    FUN_00796c00(int action);
};
// pdb: CombatActionAttackGrenade::CombatActionAttackGrenade | CombatActions.obj | fnv360_0822_retail, uvref, medium
// pdb params: aeType
FUN_00796c00::FUN_00796c00(int action) : FUN_00796180(action)
{
    preconditions.FUN_007bb870(3, 0);
    preconditions.FUN_007bb870(8, 0);
    effects.FUN_007bb870(5, 1);
    effects.FUN_007bb870(11, 3);
    effects.FUN_007bb870(10, 3);
    values.FUN_007bb870(0, 1);
}
}
}   // namespace f3m_00796c00

// @f3 0x0078b930 (community match, verified in this file)
namespace f3m_0078b930 {
namespace f3m_0078b930 {
struct RangeTable78b930 {
    unsigned int unk00;
    unsigned int* data;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int starts[4];
    unsigned int ends[4];
    int FUN_0078b930(unsigned int index);
};
// pdb: ProcessArray::GetProcessLevelFromIndex | ProcessArray.obj | fnv360_0822_retail, call_dedup, low
// pdb params: auiIndex
int RangeTable78b930::FUN_0078b930(unsigned int index)
{
    for (int i = 0; i < 4; i++) {
        if (index >= starts[i] && index < ends[i]) {
            switch (i) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            default:
                return -1;
            }
        }
    }
    return -1;
}
}
}   // namespace f3m_0078b930

// @f3 0x00791300 (community match, verified in this file)
#include <float.h>
namespace f3m_00791300 {
namespace F791300 {
struct Target { virtual void v00(); virtual void* v04(); };
struct Sub { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20; Target* unk24; };
struct Entry {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual void v098();
    virtual int v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac(); virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0();
    int unk04, unk08, unk0c;
    float unk10;
    int unk14;
    Sub* unk18;
    void FUN_006b54e0();
};
struct Node { Entry* item; Node* next; bool IsEmpty() { return !next && !item; } };
bool __cdecl FUN_008257f0(void* value);
struct Owner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    Node list;
    bool FUN_00791300(void* target, void* value);
};
// pdb: ProcessLists::FlareHitEffect | ProcessLists.obj | fnv360_0721_beta, caller, medium
// pdb params: apEffectTarget, aeFlareType
bool Owner::FUN_00791300(void* target, void* value)
{
    if (!list.IsEmpty()) {
        float best = FLT_MAX;
        Entry* found = 0;
        for (Node* node = &list; node; node = node->next) {
            Entry* entry = node->item;
            if (entry && entry->v09c() == 6) {
                Sub* sub = entry->unk18;
                if (sub && entry->unk10 < best) {
                    Target* owner = sub->unk24;
                    if (owner && owner->v04() == target && FUN_008257f0(value)) {
                        best = entry->unk10;
                        found = entry;
                    }
                }
            }
        }
        if (found) {
            found->v0c0();
            found->FUN_006b54e0();
            return true;
        }
    }
    return false;
}
}
}   // namespace f3m_00791300

// @f3 0x00785750 (community match, verified in this file)
namespace f3m_00785750 {


namespace f3_785750 {
struct Pt3 {
    float x, y, z;
    Pt3() {}
    Pt3(float a, float b, float c) : x(a), y(b), z(c) {}
    Pt3 operator+(const Pt3& o) const { return Pt3(x + o.x, y + o.y, z + o.z); }
    Pt3 operator*(float s) const { return Pt3(x * s, y * s, z * s); }
    Pt3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float Magnitude() const { return sqrt(x * x + y * y + z * z); }
    void FUN_00468d00();
};
struct Rot3 {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void MakeZ(float a)
    {
        float s, c;
        fnv_SinCos(a, s, c);
        m00 = c; m01 = s; m02 = 0.0f;
        m10 = -s; m11 = c; m12 = 0.0f;
        m20 = 0.0f; m21 = 0.0f; m22 = 1.0f;
    }
    Pt3 operator*(const Pt3& p) const
    {
        return Pt3(m00 * p.x + m01 * p.y + m02 * p.z, m10 * p.x + m11 * p.y + m12 * p.z, m20 * p.x + m21 * p.y + m22 * p.z);
    }
};
extern const double DAT_00dbe7c0;
// The void unitize at 0x00468d00 with its body visible (it reproduces 0x00468d00's own code): with the body visible
// dir does not count as escaped, which puts dir after the two 11-reference scalar homes in the frame (guess at what
// the original saw: an inline unitize compiled out of line).
__declspec(noinline) void Pt3::FUN_00468d00()
{
    float len = sqrt(x * x + y * y + z * z);
    if (len > 1e-6f) {
        float inv = 1.0f / len;
        x *= inv;
        y *= inv;
        z *= inv;
    } else {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}
struct __declspec(align(16)) HkVec {
    float x, y, z, w;
    HkVec() {}
    HkVec& operator=(const HkVec& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
inline void ToHk(HkVec& out, const Pt3& p)
{
    out.x = (float)(p.x * DAT_00dbe7c0);
    out.y = (float)(p.y * DAT_00dbe7c0);
    out.z = (float)(p.z * DAT_00dbe7c0);
}
struct HitRec {
    float nx, ny, nz, nw;
    float frac;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
};
struct __declspec(align(16)) FUN_0046a820 {
    void* unk00;
    float unk04;
    int unk08, unk0c;
    HitRec* data;
    int hitCount, hitCapacity, unk1c;
    HitRec storage[8];
    FUN_0046a820();
    ~FUN_0046a820();   // FUN_0046a920: the unwind funclet jumps straight to it
    HitRec* GetAt(int n) { return &data[n]; }
};
extern HkVec DAT_01092a50;
struct __declspec(align(16)) CastData {
    HkVec start;
    HkVec end;
    unsigned char useLayer;
    unsigned int layerInfo;
    int unk28, unk2c;
    HkVec n4;
    float frac;
    int extra;
    int unk48, unk4c;
    int keyList[8];
    int keyCount;
    int unk74, unk78, unk7c;
    void* rootObj;
    int unk84, unk88, unk8c;
    HkVec delta;
    int unka0;
    int unka4;
    FUN_0046a820* sink;
    unsigned char unkac;
    CastData() : useLayer(0), layerInfo(0)
    {
        frac = 1.0f;
        extra = -1;
        keyCount = 0;
        keyList[0] = -1;
        rootObj = 0;
        delta = DAT_01092a50;
        unka0 = 0;
        unka4 = 0;
        sink = 0;
        unkac = 0;
    }
    void PutLayer(unsigned int f) { layerInfo = f; }
    void PutStart(const Pt3* p) { HkVec v; ToHk(v, *p); start = v; }
    void PutDelta(const Pt3* p) { HkVec v; ToHk(v, *p); delta = v; }
    void PutSink(FUN_0046a820* c) { sink = c; unka4 = 0; }
};
struct World785 {
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
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4();
    virtual bool CastRay(CastData* data);
};
extern World785* DAT_01071564;
struct Extra785 {
    int unk00;
    World785* FUN_00410f00();
};
struct Area785 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char flags24;
    Extra785 extra28;
    World785* GetSpace() { return (flags24 & 1) ? extra28.FUN_00410f00() : DAT_01071564; }
};
struct Item785 {
    float FUN_004b2220();
};
struct Ctrl785 {
    float bhkCharacterController_GetRadius();
};
struct Group785 {
    unsigned short layer;
    unsigned short group;
};
// The group goes in the high half and the layer is OR-ed in through a named intermediate: the same code as the
// single expression, but it is what puts this before i in the reloads at the end of the phantom block (+0x9d3).
inline unsigned int MakeFilter(int layer, int group) { unsigned int word = group << 16; word |= layer; return word; }
void* __cdecl FUN_0089eb90(unsigned int bytes);
struct FUN_004e9520 {
    virtual void v00();
    virtual void DeleteThis();
    LONG refs;
    void* native;
    int unk0c, unk10;
    FUN_004e9520(float radius, bool flag);
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p, unsigned int bytes);   // sized form, as the unwind funclet of the new-expression calls it
};
struct BallRef {
    FUN_004e9520* ptr;
    BallRef(FUN_004e9520* p) : ptr(p) { if (ptr) InterlockedIncrement(&ptr->refs); }
    ~BallRef() { if (ptr && InterlockedDecrement(&ptr->refs) == 0) ptr->DeleteThis(); }
    BallRef& operator=(FUN_004e9520* p)
    {
        if (ptr != p) {
            if (p) InterlockedIncrement(&p->refs);
            if (ptr && InterlockedDecrement(&ptr->refs) == 0) ptr->DeleteThis();
            ptr = p;
        }
        return *this;
    }
    operator FUN_004e9520*() const { return ptr; }
};
struct ThreadMem {
    void FUN_008f6d90(void* p, int bytes, int cls);
};
extern DWORD DAT_010f3170;
struct __declspec(align(16)) Xform {
    HkVec rot[3];
    HkVec pos4;
    void MakeIdentity()
    {
        rot[0].y = 0.0f; rot[0].z = 0.0f; rot[0].w = 0.0f;
        rot[1].x = 0.0f; rot[1].z = 0.0f; rot[1].w = 0.0f;
        rot[2].x = 0.0f; rot[2].y = 0.0f; rot[2].w = 0.0f;
        rot[0].x = 1.0f; rot[1].y = 1.0f; rot[2].z = 1.0f;
    }
};
struct __declspec(align(16)) FUN_004f64e0 {
    unsigned int layerInfo;
    void* shapeObj;
    unsigned char kind;
    void* data;
    int count;
    int capacity;
    int unk18, unk1c;
    Xform xf;
    FUN_004f64e0();
    ~FUN_004f64e0()
    {
        if ((static_cast<unsigned int>(capacity) & 0x80000000u) == 0) {
            int n = capacity & 0x3fffffff;
            ThreadMem* mem = (ThreadMem*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(data, n * 8, 0x17);
        }
    }
};
struct PairRec {
    void* a;
    unsigned int keyA;
    void* b;
    unsigned int keyB;
};
struct OverlapList {
    virtual void v00();
    unsigned char earlyOut;
    PairRec* data;
    int count;
    int capacity;
    PairRec storage[16];
    OverlapList() : data(storage), count(0), capacity(0x80000010) {}
    void Clear() { count = 0; earlyOut = 0; }
    ~OverlapList();    // FUN_005715d0
};
struct PhantomObj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void Collect(OverlapList* list, void* input);
};
struct FUN_004e64b0 {
    void* unk00;
    int unk04;
    PhantomObj* phantom;
    int unk0c, unk10;
    unsigned char unk14;
    FUN_004e64b0(FUN_004f64e0* desc);
    void FUN_008f9b20(World785* space);
    void FUN_00c24b70();
    void FUN_0090c2c0();
    ~FUN_004e64b0();   // FUN_0090e490
    void GatherPairs(OverlapList* list)
    {
        PhantomObj* p = phantom;
        if (p) {
            FUN_00c24b70();
            p->Collect(list, 0);
            FUN_00c24b70();
        }
    }
};
inline float ToGame(float v) { return v * 6.999040126800537; }
extern float DAT_00f61ea8;
extern const double DAT_00dc0760;   // 2*pi as stored, for the wrap of unk7a8
inline float Asin1(float v) { return (float)asin(v); }
// Float min: the compare is made against the double form of the literal in memory and the selected literal is
// loaded separately (fld1 / the float 64.0), as in the target.
inline float Min2(float a, float b) { return a < b ? a : b; }
struct Player785 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028;
    Pt3 pos;
    int unk038;
    Area785* cell;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc;
    int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc;
    int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc;
    int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c;
    int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c;
    int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c;
    int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c;
    int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c;
    int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc;
    int unk3c0; int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc;
    int unk3e0; int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc;
    int unk400; int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c;
    int unk420; int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c;
    int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c;
    int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c;
    int unk480; int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c;
    int unk4a0; int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc;
    int unk4c0; int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc;
    int unk4e0; int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc;
    int unk500; int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c;
    int unk520; int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c;
    int unk540; int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c;
    int unk560; int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c;
    int unk580; int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c;
    int unk5a0; int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc;
    int unk5c0; int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc;
    int unk5e0; int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc;
    int unk600; int unk604; int unk608; int unk60c; int unk610; int unk614; int unk618; int unk61c;
    int unk620; int unk624; int unk628; int unk62c; int unk630; int unk634; int unk638; int unk63c;
    int unk640; int unk644; int unk648; int unk64c; int unk650; int unk654; int unk658; int unk65c;
    int unk660; int unk664; int unk668; int unk66c; int unk670; int unk674; int unk678; int unk67c;
    int unk680; int unk684; int unk688; int unk68c; int unk690; int unk694; int unk698; int unk69c;
    int unk6a0; int unk6a4; int unk6a8; int unk6ac; int unk6b0; int unk6b4; int unk6b8; int unk6bc;
    int unk6c0; int unk6c4; int unk6c8; int unk6cc; int unk6d0; int unk6d4; int unk6d8; int unk6dc;
    int unk6e0; int unk6e4; int unk6e8; int unk6ec; int unk6f0; int unk6f4; int unk6f8; int unk6fc;
    int unk700; int unk704; int unk708; int unk70c; int unk710; int unk714; int unk718; int unk71c;
    int unk720; int unk724; int unk728; int unk72c; int unk730; int unk734; int unk738; int unk73c;
    int unk740; int unk744; int unk748; int unk74c; int unk750; int unk754; int unk758; int unk75c;
    int unk760; int unk764; int unk768; int unk76c; int unk770; int unk774; int unk778; int unk77c;
    int unk780; int unk784; int unk788; int unk78c; int unk790; int unk794; int unk798; int unk79c;
    int unk7a0; int unk7a4;
    float unk7a8;
    float unk7ac;
    Ctrl785* FUN_00764ea0();
    float FUN_004e6d80();
    void FUN_00701790(Pt3* a, Pt3* b, bool c);
    Group785 FUN_00766b00();
    Area785* GetArea() { return cell; }
    Pt3* GetPos() { return &pos; }
    bool PlayerCharacter_GetDropPoint(Item785* item, Pt3* outPos, bool tryAround, bool advance);
};
extern Player785* DAT_0107a104;
// pdb: PlayerCharacter::GetDropPoint | PlayerCharacter.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
bool Player785::PlayerCharacter_GetDropPoint(Item785* item, Pt3* outPos, bool tryAround, bool advance)
{
    float span = item->FUN_004b2220() * 2.0f;
    float minGap = ToGame(DAT_0107a104->FUN_00764ea0()->bhkCharacterController_GetRadius());
    float placeDist = FUN_004e6d80() * DAT_00f61ea8;
    Pt3 eye, aim;
    FUN_00701790(&eye, &aim, true);
    Rot3 spin;
    if (advance) {
        if (unk7a8 != 0.0)
            unk7a8 += Asin1(Min2(1.0f, float(span * 0.5 / placeDist)));
        spin.MakeZ(unk7a8);
        unk7ac = unk7a8;
        if (advance) {
            unk7a8 += Asin1(Min2(1.0f, float(span * 0.5 / placeDist)));
            if (unk7a8 > DAT_00dc0760)
                unk7a8 -= DAT_00dc0760;
        }
    } else
        spin.MakeZ(unk7ac);
    bool placed = false;
    int tries = tryAround ? 10 : 0;
    for (int i = 0; !placed && i <= tries; ++i) {
        Pt3 dir = spin * aim;
        if (i != 0) {
            dir.z = 0.0f;
            dir.FUN_00468d00();
            float step = (i - 1) * (6.2831855f / tries);   // float literal: the compiler widens it (0xdc0760) and folds the int into fimul
            Rot3 stepMat;
            stepMat.MakeZ(step);
            dir = stepMat * dir;
        }
        bool clear = false;
        CastData cast;
        cast.PutLayer(MakeFilter(42, DAT_0107a104->FUN_00766b00().group));
        cast.PutStart(&eye);
        cast.PutDelta(&(dir * float(placeDist + span)));
        FUN_0046a820 hits;
        cast.PutSink(&hits);
        World785* space = DAT_0107a104->GetArea()->GetSpace();
        if (space->CastRay(&cast)) {
            float hitLen = (double)(placeDist + span) * hits.GetAt(0)->frac;
            float pullBack = hitLen - span / 2.0;
            dir *= pullBack;
            *outPos = eye + dir;
            Pt3 flat(dir.x, dir.y, 0.0f);
            float gap = flat.Magnitude() - span / 2.0;
            if (gap - minGap > 0.0)
                clear = true;
        } else {
            dir *= float(span / 2.0 + placeDist);
            *outPos = eye + dir;
            clear = true;
        }
        if (clear) {
            BallRef ball(new FUN_004e9520(span / 2.0, true));
            unsigned int shapeLayer = MakeFilter(42, DAT_0107a104->FUN_00766b00().group);
            FUN_004f64e0 desc;
            desc.layerInfo = shapeLayer;
            desc.shapeObj = ball ? ball.ptr->native : 0;
            desc.xf.MakeIdentity();
            HkVec hkPos;
            ToHk(hkPos, *outPos);
            desc.xf.pos4 = hkPos;
            FUN_004e64b0 ghost(&desc);
            ghost.FUN_008f9b20(GetArea()->GetSpace());
            OverlapList overlaps;
            overlaps.Clear();
            ghost.GatherPairs(&overlaps);
            ghost.FUN_0090c2c0();
            ball = 0;
            if (!overlaps.count)
                placed = true;
        }
    }
    if (!placed && tryAround) {
        float lift = Min2(64.0f, float(span / 2.0));
        *outPos = *GetPos();
        float& oz = outPos->z;   // guess: through a reference the z lane is loaded before lift (fld [eax+8]; fadd [lift])
        oz += lift;
        return true;
    }
    return placed;
}
}
}   // namespace f3m_00785750
