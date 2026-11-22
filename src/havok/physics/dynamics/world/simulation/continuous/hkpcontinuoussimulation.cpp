#include "f3_common.h"
#include "havok/hkTimeFunctionHelper.h"
// src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d0c6d0_Body {
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
    unsigned short m_a8;
};

struct S_00d0c6d0_Pair {
    int unk0;
    S_00d0c6d0_Body* m_apEntities[2];
};

struct S_00d0c6d0_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00d0c6d0_Pair* m_pair;
};

struct S_00d0c6d0_Entry {
    S_00d0c6d0_Obj* m_obj;
    int m_iWordAt04;
    int m_8;
};

struct S_00d0c6d0_EntryArray {
    S_00d0c6d0_Entry* m_data;
    int m_iElementCount;
};

struct S_00d0c6d0_ByteArray {
    unsigned char* m_data;
    int m_iElementCount;
};

// Scans entries from *idx onward and swaps each entry whose two pair bodies both map to byte 0x10 in table to the front, advancing *idx.
// @f3 0x0098d420 (community match, verified in this file)
struct FUN_00d0c6d0_Body {
    int unk0;
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
    unsigned short m_a8;
};
struct FUN_00d0c6d0_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S_00d0c6d0_Pair* m_pair;
};
// pdb: hkLs_toiActivateConstraintsLinkingActivatedEntities | hkpContinuousSimulation.obj | tesv_win, call_gap, low
void FUN_00d0c6d0(S_00d0c6d0_EntryArray* aEntries, int* aIndex, S_00d0c6d0_ByteArray* table) {
    for (int i = *aIndex; i < aEntries->m_iElementCount; i++) {
        S_00d0c6d0_Pair* pair = ((FUN_00d0c6d0_Obj*)aEntries->m_data[i].m_obj)->m_pair;
        FUN_00d0c6d0_Body** b = (FUN_00d0c6d0_Body**)pair->m_apEntities;
        if (table->m_data[b[0]->m_a8] == 0x10 && table->m_data[b[1]->m_a8] == 0x10) {
            int j = (*aIndex)++;
            S_00d0c6d0_Entry* data = aEntries->m_data;
            S_00d0c6d0_Entry tmp = data[j];
            data[j] = data[i];
            data[i] = tmp;
        }
    }
}


extern int DAT_010cd45c;
struct Manager { int unk00; int unk04; int unk08; int unk0c; int unk10; };
Manager* __cdecl FUN_00c85750();

void __cdecl hkpContinuousSimulation_processAgentCollideContinuous();
struct S_00d0f2e0
{
    void* FUN_00cf9480(void* a, void* b, void* c, void (__cdecl *pfnCallback)(), int iFlags);
    void* FUN_00d0f2e0(void* a, void* b, void* c);
};
// @fnv 0x00d0f2e0
// pdb: hkpContinuousSimulation::collideEntitiesNarrowPhaseContinuous | hkpContinuousSimulation.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: entities, numEntities, input
void* S_00d0f2e0::FUN_00d0f2e0(void* a, void* b, void* c)
{
    return FUN_00cf9480(a, b, c, hkpContinuousSimulation_processAgentCollideContinuous, 0);
}

struct TimeStep {float start,end,delta,inverse;};
struct World {
 TimeStep& time(){return *reinterpret_cast<TimeStep*>(reinterpret_cast<char*>(this)+80);}
};
struct Context {
 World*& world(){return *reinterpret_cast<World**>(reinterpret_cast<char*>(this)+120);}
 int& depth(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+148);}
 int& pending(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+140);}
 int& otherPending(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+144);}
 unsigned char& locked(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+156);}
 int& mode(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+164);}
 void FUN_00c91120();void FUN_00c91140();
};
struct Body { unsigned char& motion(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+232);} void* state(){return reinterpret_cast<char*>(this)+240;} };
void __cdecl FUN_00cf1b10(float,void*);
void __cdecl FUN_00d1a330(World*,Body**,int);
struct Controller {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void process(Body**,int,Context*,int);
 int flags,kind,capacity,mode;float start,end;
 void FUN_00d0d3f0(Body**,int,Context*,int);
 void FUN_00d0f2e0(Body**,int,World*);
 void hkpContinuousSimulation_reintegrateAndRecollideEntities(Body**,int,Context*,int);
};
// Runs the controller's update on bodies: sets a temporary time step, processes active bodies, applies optional passes, then restores the world time step.
// @f3 0x0098f7f0 (community match, verified in this file)
struct ControllerContextView
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68;
    World* m_pWorld;            // 0x6c
    int unk70, unk74, unk78, unk7C;
    int m_iPending;             // 0x80
    int m_iDepth;               // 0x84
    int unk88;
    unsigned char m_ucLocked;   // 0x8c
    void FUN_00902550();
};

class ViewBool
{
public:
    char m_cBooleanValue;
    ViewBool() {}
    ViewBool(bool b) { m_cBooleanValue = (char)b; }
};

struct ControllerVtableView
{
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void process(Body** apBodies, int iCount, Context* pContext, ViewBool kMode);
};

void __cdecl hkSweptTransformUtil_backStepMotionState(float fStart, void* pState);
void __cdecl hkRigidMotionUtilStep(TimeStep* pStep, Body** apBodies, int iCount, int iSize);
void __cdecl FUN_0099a2d0(World* pWorld, Body** apBodies, int iCount);
struct ControllerMemberView
{
    void FUN_0098df40(Body** apBodies, int iCount, Context* pContext, int iMode);
    void FUN_0098e4a0(Body** apBodies, int iCount, World* pWorld);
};

// pdb: hkpContinuousSimulation::reintegrateAndRecollideEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, high
// pdb params: entities, numEntities, world, reintegrateRecollideMode
// pdb: hkpContinuousSimulation::reintegrateAndRecollideEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, high (was: ProcessBodies)
void Controller::hkpContinuousSimulation_reintegrateAndRecollideEntities(Body** bodies, int count, Context* context, int flags)
{
    ControllerContextView* ctx = (ControllerContextView*)context;
    ++ctx->m_iDepth;
    World* world = ctx->m_pWorld;
    float begin = start;
    float finish = end;
    __declspec(align(16)) TimeStep saved = world->time();
    TimeStep step;
    step.start = begin;
    step.end = finish;
    step.delta = finish - begin;
    step.inverse = step.delta == 0.0f ? 0.0f : 1.0f / step.delta;
    world->time() = step;
    if (flags & 1)
    {
        for (int i = 0; i < count; ++i)
            hkSweptTransformUtil_backStepMotionState(start, (void*)((char*)bodies[i] + 0xE0));
        hkRigidMotionUtilStep(&step, bodies, count, 0xD0);
        FUN_0099a2d0(ctx->m_pWorld, bodies, count);
    }
    ((ControllerVtableView*)this)->process(bodies, count, context, ViewBool(true));
    if (flags & 2)
        ((ControllerMemberView*)this)->FUN_0098df40(bodies, count, context, 0);
    if (flags & 4)
        ((ControllerMemberView*)this)->FUN_0098e4a0(bodies, count, ctx->m_pWorld);
    if (--ctx->m_iDepth == 0 && !ctx->m_ucLocked && ctx->m_iPending)
        ctx->FUN_00902550();
    ctx->m_pWorld->time() = saved;
}


struct SpawnedObject
{
    unsigned int unkD4_dummy;
};

// @f3 0x0098c220 (community match, verified in this file)
// pdb: hkpToiResources::hkpToiResources | hkpContinuousSimulation.obj | fnv360_0822_debug, objrun_open, low
bool* __cdecl IsLessByUnkD4(bool* result, SpawnedObject* first, SpawnedObject* second) {
    *result = ((unsigned int*)first)[0x30] < ((unsigned int*)second)[0x30];
    return result;
}


struct Element {
    char pad[0xd4];
    unsigned int priority;
};


struct SubItem {
    char pad0[4];
    Element* volatile array[1];
    char pad1[0x12];
    unsigned char index;
};


struct Item {
    char pad[0x30];
    SubItem* volatile sub;
};

class hkBool {
public:
    char m_cBooleanValue;
    inline hkBool() {}
    inline hkBool(bool b) : m_cBooleanValue(char(b)) {}
    inline operator bool() const { return m_cBooleanValue != 0; }
};

// Compares two items by their sub-item's current element priority, falling back to sub-item pointer order when priorities are equal.
// @f3 0x0098c240 (community match, verified in this file)
struct H05Element {
    char pad[0xc0];
    unsigned int priority;
};
struct H05SubItem {
    char pad0[4];
    H05Element* volatile array[1];
    char pad1[0x12];
    unsigned char index;
};
struct H05Item {
    char pad[0x28];
    H05SubItem* volatile sub;
};

// pdb: hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun, medium
// pdb params: constraintStatus, firstNonActiveConstraintStatus, numOfConstraintsToCheckAtTheEndOfTheList
hkBool __cdecl CompareItemPriority(const Item* apItemA, const Item* apItemB)
{
    const H05SubItem* subA = ((const H05Item*)apItemA)->sub;
    const H05SubItem* subB = ((const H05Item*)apItemB)->sub;

    if (subA->array[subA->index]->priority < subB->array[subB->index]->priority)
        return true;
    int indexB = subB->index;
    int indexA = subA->index;
    H05Element* elemA = subA->array[indexA];
    H05Element* elemB = subB->array[indexB];
    if (elemA->priority == elemB->priority)
        return subA < subB;
    return false;
}


struct D0BD00Entry {
    float m_uiCommandId;
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
};

struct D0BD00Track {
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
    D0BD00Entry* m_entries;
    int m_iNumberOfEntries;
};

struct D0BD00Binding {
    int unk00;
    int unk04;
    D0BD00Track* m_pTrack;
};

struct D0BD00Controller {
    int unk00;
    int unk04;
    int unk08;
    D0BD00Binding* m_pBinding;

    void OffsetEntries(float offset);
};

// Adds offset to the first float of every entry in the track referenced by the controller's binding.
// @fnv 0x00d0bd00
// pdb: hkpContinuousSimulation::warpTime | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, medium
// pdb params: warpDeltaTime
void D0BD00Controller::OffsetEntries(float offset)
{
    D0BD00Track* track = m_pBinding->m_pTrack;
    for (int i = 0; i < track->m_iNumberOfEntries; i++)
        track->m_entries[i].m_uiCommandId = track->m_entries[i].m_uiCommandId + offset;
}

extern "C" double fabs(double);

struct FUN_00d0bd30_q {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    signed char m_1c;
};

struct FUN_00d0bd30_p {
    FUN_00d0bd30_q* m_00;
    int unk04;
    float m_08;
};

// Scans arr for the index whose fabs value times scale exceeds a threshold derived from p and tbl, returning that index or -1.
// @f3 0x0098ce40 (community match, verified in this file)
// pdb: hkLs_areVelocitiesOk | hkpContinuousSimulation.obj | tesv_win, call_seq, medium
int __cdecl FUN_00d0bd30(float scale, FUN_00d0bd30_p* pParams, float* pafValues, int aiCount, char** ppTable)
{
    FUN_00d0bd30_q* q = pParams->m_00;
    char* pRowBase = *ppTable + ((int)q->m_1c << 6);
    float best = *(float*)(pRowBase + 0x1c50) * pParams->m_08;
    int idx = -1;
    int i = 0;

    if (aiCount >= 4) {
        int iLimit = aiCount - 3;
        float* e = pafValues + 2;
        do {
            float v0 = (float)fabs(e[-2]) * scale;
            if (v0 > best) { best = v0; idx = i; }
            float v1 = (float)fabs(e[-1]) * scale;
            if (v1 > best) { best = v1; idx = i + 1; }
            float v2 = (float)fabs(e[0]) * scale;
            if (v2 > best) { best = v2; idx = i + 2; }
            float v3 = (float)fabs(e[1]) * scale;
            if (v3 > best) { best = v3; idx = i + 3; }
            e += 4;
            i += 4;
        } while (i < iLimit);
    }
    if (i < aiCount) {
        do {
            float v = (float)fabs(pafValues[i]) * scale;
            if (v > best) { best = v; idx = i; }
            ++i;
        } while (i < aiCount);
    }
    return idx;
}


// ---------------------------------------------------------------------------
// Stand-in types for the simulation object that owns the scope table.
//
//   this + 0x30 : ScopeEntry* m_30  - the table of 0x70-byte scope entries
//   this + 0x34 : int         m_34  - the number of live entries
//
// The scope table entry is 0x70 bytes wide; the copy performed when an entry
// is removed moves it in 8-byte chunks (14 of them), so the entry is viewed
// here as a run of ScopeChunk pairs.  The lookup key lives at +0x14.
// ---------------------------------------------------------------------------

struct ScopeEntry {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_key14;
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
};

struct ScopeQuery {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

struct ScopeEntryOps4 {
    void FUN_00990390(ScopeEntry* last);
};
// hkArray<hkpToiEvent>
struct ScopeEntryArray {
    ScopeEntry* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline int getSize() const { return m_size; }
    __forceinline ScopeEntry& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_size--;
        reinterpret_cast<ScopeEntryOps4*>(&m_data[index])->FUN_00990390(&m_data[m_size]);
    }
};
class FUN_00d0bfc0_cls {
public:
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
    ScopeEntryArray m_toiEvents;  // +0x30

    void RemoveMatchingEntries(ScopeQuery* q);
};

// Walk the scope table backwards; when the entry whose key matches the query
// is found it is dropped from the table and the last entry is moved into its
// slot (the table keeps its order otherwise).
// Scans the entry array backwards and removes every entry whose m_key14 equals q->m_08, compacting the array by moving the last entry into each removed slot.
// @f3 0x0098c7e0 (community match, verified in this file)
// pdb: hkpContinuousSimulation::removeCollisionInformationForAgent | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, medium
// pdb params: agent
void FUN_00d0bfc0_cls::RemoveMatchingEntries(ScopeQuery* q)
{
    for (int i = m_toiEvents.getSize() - 1; i >= 0; i--)
    {
        if (m_toiEvents[i].unk10 == q->m_08)
        {
            m_toiEvents.removeAt(i);
        }
    }
}


typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;

extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);

class hkVector4 {
public:
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; return *this; }
};

class hkRotation {
public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

struct hkMotionState {
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    hkVector4 m_qRotation0;
    hkVector4 m_qRotation1;
    hkVector4 m_vCenterOfMassLocal;
};

struct Entity {
    int m_unk00;
    char m_auiShapeKeys[0xec];
    hkMotionState m_kMotionState;
};

struct Island {
    int m_unk00[0x12];
    Entity** m_kActorEntries;
    int m_iActorEntryCount;
};

struct InfoBlock {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short m_06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char m_0a;
};

struct Child {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    InfoBlock* m_28;
};

struct ItemObj {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Child* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char m_1c;
};

struct Entry {
    ItemObj* m_00;
    int m_04;
    int m_08;
};

struct Vec {
    Entry* m_00;
    int m_04;
    unsigned int m_08;
};

struct FloatSrc {
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
};

struct SrcA {
    FloatSrc* m_00;
    int m_04;
    unsigned int unk08;
    int m_0c;
};

void __cdecl ResizeAudioStream(void* alloc, Vec* vec, unsigned int elemSize);
int __cdecl FUN_00d9f6f0(int a, int b, int c, int d, void* e);
int __cdecl FUN_00d0bd30(float f, Entry* entry, void* out, int a, int b);

// @f3 0x0098d790 (community match, verified in this file)
struct ChildX {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    InfoBlock* m_28;
};
int __cdecl FUN_00a27c00(int a, int b, int c, int d, void* e);
int __cdecl FUN_0098ce40(float f, Entry* entry, void* out, int a, int b);
void __cdecl FUN_00901f10(Vec* vec, unsigned int elemSize);

// pdb: hkLs_toiCheckFinalValidityOfCriticalConstraints | hkpContinuousSimulation.obj | tesv_win, call_gap, low
unsigned char* __cdecl CollectMatchingEntries(unsigned char* pResult, SrcA* pSrc, Vec* pVec, int a4, Vec* dst)
{
    unsigned int auiBuffer[0x100];
    unsigned char result = 1;
    int i = 0;
    if (pVec->m_04 > 0) {
        int iOffset = 0;
        do {
            Entry* e = (Entry*)((char*)pVec->m_00 + iOffset);
            if (e->m_00->m_1c == 4) {
                int r = FUN_00a27c00(pSrc->m_04, e->m_04, pSrc->m_0c, 0x100, auiBuffer);
                int ret = FUN_0098ce40(pSrc->m_00->m_08, e, auiBuffer, r, a4);
                if (ret >= 0) {
                    if (dst == 0) {
                        *pResult = 0;
                        return pResult;
                    }
                    result = 0;
                    if (dst->m_04 == (int)(dst->m_08 & 0x3fffffff)) {
                        FUN_00901f10(dst, 0xc);
                    }
                    Entry* pNewEntry = &dst->m_00[dst->m_04];
                    dst->m_04++;
                    pNewEntry->m_00 = e->m_00;
                    if (((ChildX*)e->m_00->m_0c)->v04() == 0xb) {
                        ChildX* x = (ChildX*)e->m_00->m_0c;
                        InfoBlock* y = x->m_28;
                        pNewEntry->m_04 = (int)((char*)y + 0x30 + (ret << 5));
                        pNewEntry->m_08 = (int)((char*)x->m_28 + 0x30 + (x->m_28->m_06 << 5) + (short)ret * x->m_28->m_0a);
                    } else {
                        pNewEntry->m_04 = 0;
                        pNewEntry->m_08 = 0;
                    }
                }
            }
            iOffset += 0xc;
            ++i;
        } while (i < pVec->m_04);
    }
    *pResult = result;
    return pResult;
}



struct S_00d0d150_Vector4 {
    __m128 m_vComponents;
    void operator=(const S_00d0d150_Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct S_00d0d150_QualityInfo {
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
    char m_bUseContinuousPhysics;
    char unk35;
    char unk36;
    char unk37;
    int unk38;
    int unk3c;
};

struct S_00d0d150_Dispatcher {
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c;
    int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c;
    int unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c;
    int unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc;
    int unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c;
    int unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c;
    int unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c;
    int unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc;
    int unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c;
    int unk720, unk724, unk728, unk72c, unk730, unk734, unk738, unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c;
    int unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c;
    int unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc;
    int unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c;
    int unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c;
    int unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c;
    int unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc;
    int unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c;
    int unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c;
    int unk960, unk964, unk968, unk96c, unk970, unk974, unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c;
    int unk9a0, unk9a4, unk9a8, unk9ac, unk9b0, unk9b4, unk9b8, unk9bc;
    int unk9c0, unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc;
    int unk9e0, unk9e4, unk9e8, unk9ec, unk9f0, unk9f4, unk9f8, unk9fc;
    int unka00, unka04, unka08, unka0c, unka10, unka14, unka18, unka1c;
    int unka20, unka24, unka28, unka2c, unka30, unka34, unka38, unka3c;
    int unka40, unka44, unka48, unka4c, unka50, unka54, unka58, unka5c;
    int unka60, unka64, unka68, unka6c, unka70, unka74, unka78, unka7c;
    int unka80, unka84, unka88, unka8c, unka90, unka94, unka98, unka9c;
    int unkaa0, unkaa4, unkaa8, unkaac, unkab0, unkab4, unkab8, unkabc;
    int unkac0, unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc;
    int unkae0, unkae4, unkae8, unkaec, unkaf0, unkaf4, unkaf8, unkafc;
    int unkb00, unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c;
    int unkb20, unkb24, unkb28, unkb2c, unkb30, unkb34, unkb38, unkb3c;
    int unkb40, unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c;
    int unkb60, unkb64, unkb68, unkb6c, unkb70, unkb74, unkb78, unkb7c;
    int unkb80, unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c;
    int unkba0, unkba4, unkba8, unkbac, unkbb0, unkbb4, unkbb8, unkbbc;
    int unkbc0, unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc;
    int unkbe0, unkbe4, unkbe8, unkbec, unkbf0, unkbf4, unkbf8, unkbfc;
    int unkc00, unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c;
    int unkc20, unkc24, unkc28, unkc2c, unkc30, unkc34, unkc38, unkc3c;
    int unkc40, unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c;
    int unkc60, unkc64, unkc68, unkc6c, unkc70, unkc74, unkc78, unkc7c;
    int unkc80, unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c;
    int unkca0, unkca4, unkca8, unkcac, unkcb0, unkcb4, unkcb8, unkcbc;
    int unkcc0, unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc;
    int unkce0, unkce4, unkce8, unkcec, unkcf0, unkcf4, unkcf8, unkcfc;
    int unkd00, unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c;
    int unkd20, unkd24, unkd28, unkd2c, unkd30, unkd34, unkd38, unkd3c;
    int unkd40, unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c;
    int unkd60, unkd64, unkd68, unkd6c, unkd70, unkd74, unkd78, unkd7c;
    int unkd80, unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c;
    int unkda0, unkda4, unkda8, unkdac, unkdb0, unkdb4, unkdb8, unkdbc;
    int unkdc0, unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc;
    int unkde0, unkde4, unkde8, unkdec, unkdf0, unkdf4, unkdf8, unkdfc;
    int unke00, unke04, unke08, unke0c, unke10, unke14, unke18, unke1c;
    int unke20, unke24, unke28, unke2c, unke30, unke34, unke38, unke3c;
    int unke40, unke44, unke48, unke4c, unke50, unke54, unke58, unke5c;
    int unke60, unke64, unke68, unke6c, unke70, unke74, unke78, unke7c;
    int unke80, unke84, unke88, unke8c, unke90, unke94, unke98, unke9c;
    int unkea0, unkea4, unkea8, unkeac, unkeb0, unkeb4, unkeb8, unkebc;
    int unkec0, unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc;
    int unkee0, unkee4, unkee8, unkeec, unkef0, unkef4, unkef8, unkefc;
    int unkf00, unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c;
    int unkf20, unkf24, unkf28, unkf2c, unkf30, unkf34, unkf38, unkf3c;
    int unkf40, unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c;
    int unkf60, unkf64, unkf68, unkf6c, unkf70, unkf74, unkf78, unkf7c;
    int unkf80, unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c;
    int unkfa0, unkfa4, unkfa8, unkfac, unkfb0, unkfb4, unkfb8, unkfbc;
    int unkfc0, unkfc4, unkfc8, unkfcc, unkfd0, unkfd4, unkfd8, unkfdc;
    int unkfe0, unkfe4, unkfe8, unkfec, unkff0, unkff4, unkff8, unkffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    int unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    int unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c;
    int unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c;
    int unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    int unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc;
    int unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c;
    int unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    int unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c;
    int unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc;
    int unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    int unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c;
    int unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c;
    int unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    int unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c;
    int unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c;
    int unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    int unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc;
    int unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c;
    int unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    int unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c;
    int unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc;
    int unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    int unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c;
    int unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c;
    int unk16a0, unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc;
    int unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c;
    int unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c;
    int unk1760, unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c;
    int unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc;
    int unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c;
    int unk1820, unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c;
    int unk1860, unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c;
    int unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc;
    int unk18e0, unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c;
    int unk1920, unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c;
    int unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c;
    int unk19a0, unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc;
    int unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c;
    int unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c;
    int unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c;
    int unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc;
    int unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c;
    int unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c;
    int unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c;
    int unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    int unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    S_00d0d150_QualityInfo m_pCollisionQualityInfo[8];
};

struct S_00d0d150_World {
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
    S_00d0d150_Dispatcher* m_pDispatcher;
};

struct S_00d0d150_Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset; }
};

struct S_00d0d150_Entity;

struct S_00d0d150_AgentNnEntry {
    int unk00;
    int unk04;
    void* m_pContactManager;
    signed char m_cAgentType;
    char unk0d;
    char unk0e;
    char unk0f;
    S_00d0d150_Collidable* m_kCollidable[2];
};

struct S_00d0d150_Properties {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
    S_00d0d150_Properties() { m_fAccumulatedImpulse = 0.0f; m_fImpulseLimit = 0.0f; }
};

struct S_00d0d150_ToiEvent {
    float m_uiCommandId;
    float m_fSeparation;
    char m_cEventType;
    S_00d0d150_Entity* m_kActorEntries[2];
    void* m_pContactManager;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
    int unk48;
    int unk4c;
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
};

struct S_00d0d150_ProcessCdPoint {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2c;
};

struct S_00d0d150_ToiInfo {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
};

struct S_00d0d150_CollisionOutput {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d0d150_ProcessCdPoint m_akContactPoints[256];
    S_00d0d150_ToiInfo m_fTimeOfImpact;
};

inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }

template <typename T>
struct S_00d0d150_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline T* expandByUnchecked(int n)
    {
        int oldsize = m_iElementCount;
        m_iElementCount = oldsize + n;
        int numToConstruct = m_iElementCount - oldsize;
        T* p = m_data + oldsize;
        for (int i = 0; i < numToConstruct; ++i)
            new (p + i) T;
        return m_data + oldsize;
    }
};

struct S_00d0d150_ErrStream {
    int unk0;
    int unk4;
    int unk8;
    S_00d0d150_ErrStream(void* buf, int bufSize) throw();
    ~S_00d0d150_ErrStream() throw();
    S_00d0d150_ErrStream& operator<<(const char* s) throw();
};

struct S_00d0d150_Error {
    virtual void vfn0();
    virtual void vfn4();
    virtual void vfn8();
    virtual int message(int type, int id, const char* description, const char* file, int line) throw();
};

static __forceinline void S_00d0d150_memCpy4(void* dst, const void* src, int numWords)
{
    const int* s = static_cast<const int*>(src);
    int* d = static_cast<int*>(dst);
    for (int i = 0; i != numWords; i++)
        *(d++) = *(s++);
}

struct S_00d0d150 {
    int unk00;
    int unk04;
    int unk08;
    S_00d0d150_World* m_pOwningWorld;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00d0d150_Array<S_00d0d150_ToiEvent> m_kToiEventQueue;

    void QueueToiEvent(const S_00d0d150_CollisionOutput& result, const S_00d0d150_AgentNnEntry& entry) throw();
};

// @f3 0x0098c830 (community match, verified in this file)
extern const char FUN_00e7db88[];
extern S_00d0d150_Error* DAT_010f3364;
struct EventErrorStreamStub { int a,b,c; void FUN_00923070(void*,int); void FUN_00943710(const char*); void FUN_00943a60(); };
extern const char FUN_00e7db40[];
static __forceinline void CopyEventFloat(char* dest,int dstOffset,const char* src,int srcOffset)
{
    *(float*)(dest+dstOffset)=*(const float*)(src+srcOffset);
}
// pdb: hkpContinuousSimulation::addToiEvent | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: processOutput, entry
void S_00d0d150::QueueToiEvent(const S_00d0d150_CollisionOutput& result,const S_00d0d150_AgentNnEntry& entry) throw()
{
    if (m_kToiEventQueue.m_iElementCount == (m_kToiEventQueue.m_iCapacityState & 0x3fffffff))
    {
        unsigned int buf[128];
        EventErrorStreamStub stream;
        stream.FUN_00923070(buf,512);
        stream.FUN_00943710(FUN_00e7db88);
        DAT_010f3364->message(1,0xf0323454,(const char*)buf,FUN_00e7db40,0x399);
        stream.FUN_00943a60();
        return;
    }
    int oldCount=*(volatile int*)&m_kToiEventQueue.m_iElementCount;
    m_kToiEventQueue.m_iElementCount=oldCount+1;
    char* dst=(char*)m_kToiEventQueue.m_data + oldCount*sizeof(S_00d0d150_ToiEvent);
    const char* src=(const char*)&result;
    const char* ed=(const char*)&entry;
    CopyEventFloat(dst,0,src,0x3030);
    CopyEventFloat(dst,0x0c,src,0x3034);
    for(int i=0;i<8;++i)
        CopyEventFloat(dst,0x20+i*4,src,0x3010+i*4);
    S_00d0d150_Collidable* actor = *(S_00d0d150_Collidable* const*)(ed+0x10);
    *(void**)(dst+4)=(char*)actor + *(signed char*)((char*)actor+0x10);
    actor = *(S_00d0d150_Collidable* const*)(ed+0x14);
    *(void**)(dst+8)=(char*)actor + *(signed char*)((char*)actor+0x10);
    for(int i=0;i<5;++i)
        *(int*)(dst+0x40+i*4)=*(const int*)(src+0x3050+i*4);
    *(void**)(dst+0x10)=*(void* const*)(ed+8);
    for(int i=0;i<7;++i)
        *(int*)(dst+0x54+i*4)=*(const int*)(src+0x3064+i*4);
}


extern float DAT_0104da48;
extern int DAT_01269200;

struct ThingVCallObject {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(int aiA, int aiB, void* apP, void* apS);
};

struct ThingX {
    int unk00;
    int unk04;
    ThingVCallObject* m_pObject;
    unsigned char m_bKind;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    int m_iA;
    int m_iB;
};

struct ThingEntry {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iValue;
};

struct ThingP {
    unsigned char* m_pTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iCached;

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
    ThingEntry* m_afEntries;
};

struct ThingBlock {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};

struct ThingHead {
    void* m_pSelf;
    int unk04;
    int unk08;
    int unk0c;
    int m_iSub;
    int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};

struct ThingFloatBlock {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    float m_fValue;
    int unk34; int unk38; int unk3c;
};

struct ThingFlagBlock {
    int m_iFlags;
    int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};

struct ThingS {
    ThingHead m_pFirstNode;
    ThingBlock m_blk0040;
    ThingBlock m_blk0080;
    ThingBlock m_blk00C0;
    ThingBlock m_blk0100;
    ThingBlock m_blk0140;
    ThingBlock m_blk0180;
    ThingBlock m_blk01C0;
    ThingBlock m_blk0200;
    ThingBlock m_blk0240;
    ThingBlock m_blk0280;
    ThingBlock m_blk02C0;
    ThingBlock m_blk0300;
    ThingBlock m_blk0340;
    ThingBlock m_blk0380;
    ThingBlock m_blk03C0;
    ThingBlock m_blk0400;
    ThingBlock m_blk0440;
    ThingBlock m_blk0480;
    ThingBlock m_blk04C0;
    ThingBlock m_blk0500;
    ThingBlock m_blk0540;
    ThingBlock m_blk0580;
    ThingBlock m_blk05C0;
    ThingBlock m_blk0600;
    ThingBlock m_blk0640;
    ThingBlock m_blk0680;
    ThingBlock m_blk06C0;
    ThingBlock m_blk0700;
    ThingBlock m_blk0740;
    ThingBlock m_blk0780;
    ThingBlock m_blk07C0;
    ThingBlock m_blk0800;
    ThingBlock m_blk0840;
    ThingBlock m_blk0880;
    ThingBlock m_blk08C0;
    ThingBlock m_blk0900;
    ThingBlock m_blk0940;
    ThingBlock m_blk0980;
    ThingBlock m_blk09C0;
    ThingBlock m_blk0A00;
    ThingBlock m_blk0A40;
    ThingBlock m_blk0A80;
    ThingBlock m_blk0AC0;
    ThingBlock m_blk0B00;
    ThingBlock m_blk0B40;
    ThingBlock m_blk0B80;
    ThingBlock m_blk0BC0;
    ThingBlock m_blk0C00;
    ThingBlock m_blk0C40;
    ThingBlock m_blk0C80;
    ThingBlock m_blk0CC0;
    ThingBlock m_blk0D00;
    ThingBlock m_blk0D40;
    ThingBlock m_blk0D80;
    ThingBlock m_blk0DC0;
    ThingBlock m_blk0E00;
    ThingBlock m_blk0E40;
    ThingBlock m_blk0E80;
    ThingBlock m_blk0EC0;
    ThingBlock m_blk0F00;
    ThingBlock m_blk0F40;
    ThingBlock m_blk0F80;
    ThingBlock m_blk0FC0;
    ThingBlock m_blk1000;
    ThingBlock m_blk1040;
    ThingBlock m_blk1080;
    ThingBlock m_blk10C0;
    ThingBlock m_blk1100;
    ThingBlock m_blk1140;
    ThingBlock m_blk1180;
    ThingBlock m_blk11C0;
    ThingBlock m_blk1200;
    ThingBlock m_blk1240;
    ThingBlock m_blk1280;
    ThingBlock m_blk12C0;
    ThingBlock m_blk1300;
    ThingBlock m_blk1340;
    ThingBlock m_blk1380;
    ThingBlock m_blk13C0;
    ThingBlock m_blk1400;
    ThingBlock m_blk1440;
    ThingBlock m_blk1480;
    ThingBlock m_blk14C0;
    ThingBlock m_blk1500;
    ThingBlock m_blk1540;
    ThingBlock m_blk1580;
    ThingBlock m_blk15C0;
    ThingBlock m_blk1600;
    ThingBlock m_blk1640;
    ThingBlock m_blk1680;
    ThingBlock m_blk16C0;
    ThingBlock m_blk1700;
    ThingBlock m_blk1740;
    ThingBlock m_blk1780;
    ThingBlock m_blk17C0;
    ThingBlock m_blk1800;
    ThingBlock m_blk1840;
    ThingBlock m_blk1880;
    ThingBlock m_blk18C0;
    ThingBlock m_blk1900;
    ThingBlock m_blk1940;
    ThingBlock m_blk1980;
    ThingBlock m_blk19C0;
    ThingBlock m_blk1A00;
    ThingBlock m_blk1A40;
    ThingBlock m_blk1A80;
    ThingBlock m_blk1AC0;
    ThingBlock m_blk1B00;
    ThingBlock m_blk1B40;
    ThingBlock m_blk1B80;
    ThingBlock m_blk1BC0;
    ThingBlock m_blk1C00;
    ThingBlock m_blk1C40;
    ThingBlock m_blk1C80;
    ThingBlock m_blk1CC0;
    ThingBlock m_blk1D00;
    ThingBlock m_blk1D40;
    ThingBlock m_blk1D80;
    ThingBlock m_blk1DC0;
    ThingBlock m_blk1E00;
    ThingBlock m_blk1E40;
    ThingBlock m_blk1E80;
    ThingBlock m_blk1EC0;
    ThingBlock m_blk1F00;
    ThingBlock m_blk1F40;
    ThingBlock m_blk1F80;
    ThingBlock m_blk1FC0;
    ThingBlock m_blk2000;
    ThingBlock m_blk2040;
    ThingBlock m_blk2080;
    ThingBlock m_blk20C0;
    ThingBlock m_blk2100;
    ThingBlock m_blk2140;
    ThingBlock m_blk2180;
    ThingBlock m_blk21C0;
    ThingBlock m_blk2200;
    ThingBlock m_blk2240;
    ThingBlock m_blk2280;
    ThingBlock m_blk22C0;
    ThingBlock m_blk2300;
    ThingBlock m_blk2340;
    ThingBlock m_blk2380;
    ThingBlock m_blk23C0;
    ThingBlock m_blk2400;
    ThingBlock m_blk2440;
    ThingBlock m_blk2480;
    ThingBlock m_blk24C0;
    ThingBlock m_blk2500;
    ThingBlock m_blk2540;
    ThingBlock m_blk2580;
    ThingBlock m_blk25C0;
    ThingBlock m_blk2600;
    ThingBlock m_blk2640;
    ThingBlock m_blk2680;
    ThingBlock m_blk26C0;
    ThingBlock m_blk2700;
    ThingBlock m_blk2740;
    ThingBlock m_blk2780;
    ThingBlock m_blk27C0;
    ThingBlock m_blk2800;
    ThingBlock m_blk2840;
    ThingBlock m_blk2880;
    ThingBlock m_blk28C0;
    ThingBlock m_blk2900;
    ThingBlock m_blk2940;
    ThingBlock m_blk2980;
    ThingBlock m_blk29C0;
    ThingBlock m_blk2A00;
    ThingBlock m_blk2A40;
    ThingBlock m_blk2A80;
    ThingBlock m_blk2AC0;
    ThingBlock m_blk2B00;
    ThingBlock m_blk2B40;
    ThingBlock m_blk2B80;
    ThingBlock m_blk2BC0;
    ThingBlock m_blk2C00;
    ThingBlock m_blk2C40;
    ThingBlock m_blk2C80;
    ThingBlock m_blk2CC0;
    ThingBlock m_blk2D00;
    ThingBlock m_blk2D40;
    ThingBlock m_blk2D80;
    ThingBlock m_blk2DC0;
    ThingBlock m_blk2E00;
    ThingBlock m_blk2E40;
    ThingBlock m_blk2E80;
    ThingBlock m_blk2EC0;
    ThingBlock m_blk2F00;
    ThingBlock m_blk2F40;
    ThingBlock m_blk2F80;
    ThingBlock m_blk2FC0;
    ThingFloatBlock m_blk3000;
    ThingBlock m_blk3040;
    ThingFlagBlock m_blk3080;
};

struct FUN_00d0daa0_cls {
    int unk00;

    void QueueToiEvent(ThingS* apS, ThingX* apX);
    void hkpContinuousSimulation_processAgentCollideContinuous(ThingX* apX, ThingP* apP, ThingS* apS);
};

// @f3 0x0098dd40 (community match, verified in this file)
struct FUN_010f3400_obj {
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
    virtual unsigned char* v60(unsigned char* aOut, int aiZero);
    int unk04;
};
extern FUN_010f3400_obj* DAT_010f3400;
struct FUN_0098c830_cls { void FUN_0098c830(ThingS* apS, ThingX* apX); };
void __cdecl FUN_00999610(ThingX* apX, ThingP* apP, ThingS* apS, int aiValue);
extern float FUN_00de6e60;
extern double FUN_00de7348;

// pdb: hkpContinuousSimulation::processAgentCollideContinuous | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun_prop, high
// pdb params: entry, processInput, processOutput
// pdb: hkpContinuousSimulation::processAgentCollideContinuous | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun_prop, high (was: InitAndDispatch)
void FUN_00d0daa0_cls::hkpContinuousSimulation_processAgentCollideContinuous(ThingX* apX, ThingP* apP, ThingS* apS)
{
    apS->m_blk3000.m_fValue = DAT_0104da48;
    apS->m_blk3080.m_iFlags = 0;
    apS->m_pFirstNode.m_pSelf = &apS->m_pFirstNode.m_iSub;
    unsigned char bKind = apX->m_bKind;
    apP->m_afEntries = (ThingEntry*)(apP->m_pTable + 0x1c20 + (((int)(char)bKind) << 6));
    apP->unk10 = apP->m_afEntries->m_iValue;
    FUN_00999610(apX, apP, apS, (int)apX->m_pObject);
    FUN_010f3400_obj* pObj = DAT_010f3400;
    unsigned char bFlag;
    unsigned char* pRes = pObj->v60(&bFlag, 0);
    if (*pRes == 0) pObj->unk04 = 1;
    if (pObj->unk04 != 1) {
        if (apS->m_pFirstNode.m_pSelf != &apS->m_pFirstNode.m_iSub) {
            apX->m_pObject->v18(apX->m_iA, apX->m_iB, apP, apS);
        }
        if (apS->m_blk3000.m_fValue != FUN_00de7348) {
            reinterpret_cast<FUN_0098c830_cls*>(this)->FUN_0098c830(apS, apX);
        }
    }
}


struct CollisionMotion {
    int unk00, unk04;
    unsigned char type;
};
struct CollisionBody {
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
    CollisionMotion motion;
    hkBool FUN_00c761f0();
};
struct CollisionManager {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int constraint;
};
struct CollisionProperties {
    float impulse, solverData;
    int unk08;
    unsigned char friction, restitution, maximumImpulse;
    unsigned char unk0f;
    int unk10;
};
struct CollisionEvent {
    float time, separatingVelocity;
    int flags;
    CollisionBody* bodyA;
    CollisionBody* bodyB;
    CollisionManager* manager;
    CollisionProperties properties;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c;
    hkVector4 position, normal;
};
struct __declspec(align(16)) CollisionStateData {
    unsigned short type, count;
    int* constraint;
    CollisionProperties* properties;
    hkVector4* point;
};
struct CollisionQueue {
    CollisionBody** data;
    int size;
    int cap;
    __forceinline void add(CollisionBody* b) {
        CollisionBody** p = data + size;
        __assume(p != 0);
        *p = b;
        ++size;
    }
};
// @f3 0x0098cb20 (community match, verified in this file)
namespace Task2017 {
struct Bool {char value;Bool(){} Bool(bool b):value(b){} operator bool() const {return value!=0;}};
struct Motion {unsigned unk00,unk04;unsigned char type;};
struct Body {
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
unsigned unk0cc;Motion motion;Bool FUN_008dd0c0();};
struct Manager {
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
unsigned unk040;int constraint;};
struct Properties {float impulse,solverData;int unk08;unsigned char friction,restitution,maximumImpulse,unk0f;int unk10;};
struct Event {float time;Body* bodyA;Body* bodyB;float separatingVelocity;Manager* manager;unsigned unk14,unk18,unk1c;hkVector4 position,normal;Properties properties;};
struct __declspec(align(16)) Params {float unk00,unk04,unk08,unk0c;float friction,restitution,maximumImpulse,separatingVelocity,extraVelocity,deltaTime;bool limitBreached;};
struct Output {float impulse,velocityA,velocityB;};
struct __declspec(align(16)) State {unsigned type;int* constraint;Properties* properties;hkVector4* point;};
struct Queue {Body** data;int size,cap;void add(Body* b){data[size++]=b;}};
extern float DAT_00e35180[],DAT_00de6e60;
void __cdecl hkpSimpleCollisionResponse_solveSingleContact(hkVector4*,float,Params*,Motion*,Motion*,Manager*,Output*);
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(void*,State*,int);
}
// @fnv 0x00d0c480
// pdb: hkLs_doSimpleCollisionResponse | hkpContinuousSimulation.obj | fnv360_0822_retail, caller_sim, high
// pdb params: world, event, rotateNormal, toBeActivated
// pdb: hkLs_doSimpleCollisionResponse | hkpContinuousSimulation.obj | fnv360_0822_retail, caller_sim, high (was: ProcessCollisionEvent)
void __cdecl hkLs_doSimpleCollisionResponse(void* context, CollisionEvent* rawEvent, float deltaTime, CollisionQueue* rawQueue)
{
 Task2017::Event* event=(Task2017::Event*)rawEvent;Task2017::Queue* queue=(Task2017::Queue*)rawQueue;
    Task2017::Body* bodyA = event->bodyA;
    Task2017::Body* bodyB = event->bodyB;
    Task2017::Motion* motionA = &bodyA->motion;
    Task2017::Motion* motionB = &bodyB->motion;
    Task2017::Params params;
    params.separatingVelocity = event->separatingVelocity;
    params.extraVelocity = 0.1f;
    params.deltaTime = deltaTime;
    params.friction = Task2017::DAT_00e35180[event->properties.friction];
    params.restitution = event->properties.restitution * (1.0 / 128.0);
    params.maximumImpulse = event->properties.maximumImpulse == 0 ? Task2017::DAT_00de6e60 : Task2017::DAT_00e35180[event->properties.maximumImpulse];
    Task2017::Output result;
    Task2017::hkpSimpleCollisionResponse_solveSingleContact(&event->position, event->time, &params, motionA, motionB, event->manager, &result);
    if (params.limitBreached) {
        Task2017::State callbackEvent;
        callbackEvent.type = 2;

        callbackEvent.point = &event->position;
        callbackEvent.constraint = &event->manager->constraint;
        callbackEvent.properties = &event->properties;
        Task2017::hkpWorldCallbackUtil_fireContactImpulseLimitBreached(context, &callbackEvent, 1);
        return;
    }
    if (result.velocityA < 0.0f && result.velocityB < 0.0f) {
        if (bodyA->motion.type != 7 && bodyA->motion.type != 6) queue->add(bodyA);
        if (bodyB->motion.type != 7 && bodyB->motion.type != 6) queue->add(bodyB);
    } else if (result.velocityA < 0.0f && result.velocityB >= 0.0f) {
        if (bodyA->motion.type != 7 && bodyA->motion.type != 6) queue->add(bodyA);
        else queue->add(bodyB);
    } else if (result.velocityA >= 0.0f && result.velocityB < 0.0f) {
        if (bodyB->FUN_008dd0c0()) {
            queue->add(bodyA);
        } else {
            queue->add(bodyB);
        }
    } else {
        if (bodyA->motion.type != 7 && bodyA->motion.type != 6) {
            if (bodyB->motion.type == 7 || bodyB->motion.type == 6 || !(result.velocityB < result.velocityA)) {
                queue->add(bodyA);
                return;
            }
        }
        queue->add(bodyB);
    }
}


// expanded integer AABB into thread-stack local arrays, add them to the 3-axis sweep, then remove duplicate pairs.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _mm_prefetch(char const* p, int hint);

extern unsigned long DAT_0126835c;
extern char DAT_010cc624[];  // "LtBroadPhase"
extern char DAT_010cd3e8[];  // "StGatherAabbs"
extern char DAT_010cc5fc[];  // "St3AxisSweep"
extern char DAT_010cc5f0[];  // "StRemoveDup"
extern char DAT_01076f38[];  // "lt"

struct MonitorStreamD0 {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_capacityEnd;
};
struct TimerCommandD0 {
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};

struct BoundingVolumeDataD0 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_ucUnknownByte;
};
struct AabbUint32D0 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_expansionMaxXYZ;
};
struct CollidableD0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_kBroadPhaseHandle;
    int unk28;
    int unk2c;
    BoundingVolumeDataD0 m_kBoundingVolumeData;
};
struct PairArrayD0 {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct BroadPhaseD0 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual void UpdatePairs(int** handles, AabbUint32D0* aabbs, int numObjects, PairArrayD0& newPairs, PairArrayD0& delPairs);
    int unk04;
    int unk08;
    int unk0c;
    int m_pWorldLock;
    void lockImplementation();
    void unlockImplementation();
    void lock() { if (m_pWorldLock) lockImplementation(); }
    void unlock() { if (m_pWorldLock) unlockImplementation(); }
};
struct CollisionInputD0;
void __cdecl FUN_00d1a330(CollisionInputD0* input, CollidableD0** collidables, int numCollidables);
void __cdecl FUN_00cf7130(PairArrayD0& newPairs, PairArrayD0& delPairs);

// Havok-style query: collect candidate pairs from the source into a temporary array, skip entries
// below the level or already flagged (>= 8), mark unflagged owners once (callback), and append every
// accepted object to the output array.
struct HeapL {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct RouterL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HeapL* m_pStreamAllocator;
    HeapL& heap() { return *m_pStreamAllocator; }
};
RouterL* GetRouterL() throw();
void ReserveMoreL(HeapL& alloc, void* arr, int elemSize) throw();
template <typename T> inline void ConstructWithCopyL(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <class T> struct ArrL {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ArrL() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~ArrL() { _clearAndDeallocate(GetRouterL()->heap()); }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(HeapL& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
    }
    void _pushBack(HeapL& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ReserveMoreL(alloc, this, sizeof(T));
        ConstructWithCopyL<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(const T& t) { _pushBack(GetRouterL()->heap(), t); }
    T& operator[](int i) { return m_data[i]; }
};

struct ObjL {
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_iValueAtOffset04;
};
struct MotionL {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40;
};
struct OwnerL {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    unsigned short m_uiEdgeIndex;
    unsigned short m_aa;
    int m_ac, m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8, m_cc, m_d0, m_d4, m_d8, m_dc, m_e0, m_e4;
    unsigned char m_type;
    unsigned char m_e9, m_ea, m_eb;
    int m_ec;
    MotionL m_pMotionState;
};
struct NodeL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    OwnerL* getOwner() { return (OwnerL*)((char*)this + m_iOwnerOffset); }
};
struct ItemPairL {
    ObjL* m_obj;
    NodeL* m_node;
};
struct ListL {
    void Collect(ArrL<ItemPairL>* out) throw();
};
struct SrcL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ListL m_kNode;
};
void OnFirstVisitL(void* target, float fValue, void* arg) throw();

inline bool IsSaturatedL(OwnerL* owner, unsigned char** ppFlags)
{
    return owner->m_type != 5 && (*ppFlags)[owner->m_uiEdgeIndex] >= 8;
}
inline void VisitL(OwnerL* owner, unsigned char** ppFlags, float fValue)
{
    if (owner->m_type != 5)
    {
        if ((*ppFlags)[owner->m_uiEdgeIndex] == 0)
        {
            (*ppFlags)[owner->m_uiEdgeIndex] = 1;
            MotionL* motion = &owner->m_pMotionState;
            OnFirstVisitL(&motion->m_40, fValue, motion);
        }
    }
}

// Collects item pairs from src, skips those below level or with saturated owners, visits the rest and appends their objects to out.
// @f3 0x0098cd70 (community match, verified in this file)
struct SrcStubF5 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    ItemPairL* m_pItems;
    int m_iCount;
};

struct OwnerStubF5 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90;
    unsigned short m_uiEdgeIndex;
    unsigned short unk96;
    int unk98, unk9c, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    int unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4;
    unsigned char m_type;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    int unkDC;
    MotionL m_pMotionState;
};

struct ArrStubF5 {
    ObjL** m_data;
    int m_iCount;
    int m_iCap;
};

void hkSweptTransformUtil_lerp2(void* pTarget, float fValue, void* pMotion);
void FUN_00901f10(ArrStubF5* arr, unsigned int size);

// pdb: hkLs_collectAgentEntriesToProcess | hkpContinuousSimulation.obj | tesv_win, call_gap_sim, low
void CollectUnsaturatedObjects(SrcL* pSource, int level, float fValue, unsigned char** ppFlags, ArrL<ObjL*>* out)
{
    for (int i = 0; i < ((SrcStubF5*)pSource)->m_iCount; i++)
    {
        ItemPairL& it = ((SrcStubF5*)pSource)->m_pItems[i];
        if (level > it.m_obj->m_iValueAtOffset04)
            continue;
        OwnerStubF5* owner = (OwnerStubF5*)it.m_node->getOwner();
        if (owner->m_type != 7 && (*ppFlags)[owner->m_uiEdgeIndex] >= 8)
            continue;
        if (owner->m_type != 7)
        {
            if ((*ppFlags)[owner->m_uiEdgeIndex] == 0)
            {
                (*ppFlags)[owner->m_uiEdgeIndex] = 1;
                MotionL* motion = &owner->m_pMotionState;
                hkSweptTransformUtil_lerp2(&motion->m_40, fValue, motion);
            }
        }
        ArrStubF5* arr = (ArrStubF5*)out;
        if (arr->m_iCount == (arr->m_iCap & 0x3fffffff))
            FUN_00901f10(arr, 4);
        arr->m_data[arr->m_iCount] = it.m_obj;
        arr->m_iCount++;
    }
}


// Empty function body that takes three int arguments and does nothing.
// @fnv 0x00d0bc50
// pdb: hkArrayBase<hkMonitorStreamAnalyzer::Node *>::clear | hkStreamStatisticsCollector.obj | fnv360_0822_debug, objrun_open, low
void __stdcall FUN_00d0bc50(int, int, int) {
}

// @fnv 0x00d0bcf0
// pdb: hkpKeyframedRigidMotion::setInertiaLocal | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: inertia
void __stdcall FUN_00d0bcf0(int a)
{
}

struct MotionBody {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4;
    unsigned char m_type;
};
struct BodyPair {
    int unk0;
    MotionBody* m_apEntities[2];
};
struct PairOwner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    BodyPair* m_pair;
};
struct PairEntry {
    PairOwner* m_pOwnerObject;
    int m_iWordAt04;
    int m_8;
};
struct PairEntryArray {
    PairEntry* m_data;
    int m_iElementCount;
};
template <class T> inline void SwapT(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
// Moves pairs whose bodies have type 4 or 5 to the front of the array, tracking the count in numFixed.
// @f3 0x0098d360 (community match, verified in this file)
struct MotionBodyStandIn
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
	unsigned char m_type;
};
struct BodyPairStandIn
{
	int unk0;
	MotionBodyStandIn* m_apEntities[2];
};
struct PairOwnerStandIn
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
	BodyPairStandIn* m_pair;
};
// pdb: hkLs_toiActivateConstraintsLinkingActivatedEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities)
// pdb params: constraintStatus, firstNonActiveConstraintStatus, entityState
void PartitionMotionPairs(PairEntryArray* apEntryArray, int* apiFixedCount, int index)
{
    for (index = apEntryArray->m_iElementCount - index; index < apEntryArray->m_iElementCount; index++) {
        BodyPairStandIn* pair = ((PairOwnerStandIn*)apEntryArray->m_data[index].m_pOwnerObject)->m_pair;
        MotionBodyStandIn** bodies = pair->m_apEntities;
        if (bodies[0]->m_type == 7 || bodies[0]->m_type == 6 || bodies[1]->m_type == 7 || bodies[1]->m_type == 6) {
            int slot = *apiFixedCount;
            *apiFixedCount = slot + 1;
            SwapT(apEntryArray->m_data[slot], apEntryArray->m_data[index]);
        }
    }
}


extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
// FUN_00d0ef40 v1 - Havok collide step: monitor ticks, reverse vcall loop, two ctx array loops
extern char DAT_010c41f8[]; // Et
extern int DAT_01269200;

struct Param { int m_00; int m_04; float m_08; float m_0c;
    void set(const Param& o) { *this = o; } };
struct Sub78 {
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
    Param m_50;
};
struct BodyA {
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
    int m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8; unsigned char m_e9; unsigned char m_ea; unsigned char m_eb;
    int unk0ec;
};
class VObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void vcall8(int, void*);
};
struct Elem70 {
    int m_00; int m_04; int m_08;
    BodyA* m_0c; BodyA* m_10; VObj* m_14;
    int m_18;
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
};
struct BodyL {
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
    void* m_48; int m_4c;
};
struct Arr28 { BodyL** m_data; int m_uiItemCount; };
struct Sub1E0 {
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
    float m_10c; float m_110; int m_114;
    void setTimes(float scale, const Param& step) { m_10c = scale * step.m_08; m_110 = (float)m_114 * step.m_0c; }
};
struct Ctx {
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
    Arr28 m_aiIndexedValues;
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
    Sub78* m_78;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int m_8c; int m_90; int m_94; int m_98;
    unsigned char m_9c; unsigned char m_9d; unsigned char m_9e; unsigned char m_9f;
    int m_a0; int m_a4;
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
    int m_198;
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
    Param m_1d0;
    Sub1E0 m_1e0;
    int m_2f8; int m_2fc; float m_300;
    Sub1E0* solverInfo() { return &m_1e0; }
    void FUN_00c91120();
    void FUN_00c91140();
};
template<int Mode> static inline void TickWrite(const char* name, volatile unsigned int& t)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        if (Mode == 1) _ReadBarrier();
        if (Mode == 2) _WriteBarrier();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void ReleaseCtx(Ctx* c)
{
    --c->m_94;
    if (c->m_94 != 0) return;
    if (c->m_9c != 0) return;
    if (c->m_8c) c->FUN_00c91120();
    if (c->m_a4 != 1) return;
    if (c->m_90) c->FUN_00c91140();
}
struct ThisFull {
    int m_00; int m_04; int m_08;
    Ctx* m_0c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int m_28; int m_2c;
    Elem70* m_30; int m_34;
    void FUN_00d0d3f0(void*, int, Ctx*, int);
    void FUN_00d0d8b0(BodyL*, void*);
};

union StepArg { Param* step; volatile unsigned int tick; };
// Calls vcall8 on queued elements, stores the step parameters in the context, then loops items calling FUN_00d0d3f0, then FUN_00d0d8b0 and FUN_00d01650.
// @f3 0x0098f980 (community match, verified in this file)
struct CurrentCtx; struct CurrentElem70;
struct CurrentThisFull {
    int m_00; int m_04; int m_08;
    CurrentCtx* m_0c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int m_28; int m_2c;
    CurrentElem70* m_30; int m_34;
    void FUN_0098df40(void*, int, CurrentCtx*, int);
    void FUN_0098dae0(BodyL*, void*);
};
struct CurrentBodyA {
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
    int m_cc;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned char m_e8;
    unsigned char m_e9;
    unsigned char m_ea;
    unsigned char m_eb;
};
struct CurrentElem70 {
    int unk000;
    CurrentBodyA* m_0c;
    CurrentBodyA* m_10;
    int unk00c;
    VObj* m_14;
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
    int m_18;
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
};
struct CurrentCtx {
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
    Arr28 m_aiIndexedValues;
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
    Sub78* m_78;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int m_8c;
    int m_94;
    int unk088;
    unsigned char m_9c;
    unsigned char m_9d;
    unsigned char m_9e;
    unsigned char m_9f;
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
    int m_198;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    Param m_1d0;
    Sub1E0 m_1e0;
    int unk2b8;
    int unk2bc;
    float m_300;
    void FUN_00902550();
};

static inline void ReleaseCurrent(CurrentCtx* c) { --c->m_94; if(c->m_94 != 0) return; if(c->m_9c != 0) return; if(c->m_8c) c->FUN_00902550(); }
namespace ConstraintStep1173 { extern const char DAT_00e7d3e4[], DAT_00e7d3cc[], DAT_00e32798[]; }
void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(CurrentCtx*, BodyL*, Param*);
// pdb: hkpContinuousSimulation::collideInternal | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, medium
// pdb params: stepInfoIn
void __fastcall FUN_00d0ef40(ThisFull* original, void* edx_unused, StepArg arg)
{
    CurrentThisFull* th = (CurrentThisFull*)original;
    volatile unsigned int tA;
    TickWrite<0>(ConstraintStep1173::DAT_00e7d3e4, tA);
    if (th->m_28 != 0) {
        for (int i = th->m_34 - 1; i >= 0; --i) {
            CurrentElem70* e = &th->m_30[i];
            CurrentBodyA* b = e->m_0c;
            int a1;
            if (b->m_e8 == 7) a1 = e->m_10->m_cc;
            else a1 = b->m_cc;
            _ReadWriteBarrier();
            e->m_14->vcall8(a1, &e->m_18);
        }
        th->m_34 = 0;
    }
    _ReadWriteBarrier();
    Param& dst = static_cast<volatile CurrentThisFull*>(th)->m_0c->m_1d0;
    Param* p = *(Param* volatile*)&arg.step;
    dst.set(*p);
    th->m_0c->m_78->m_50.set(*p);
    { union SolverPointer { CurrentCtx* c; Sub1E0* s; }; SolverPointer uSolverPtr; uSolverPtr.c = th->m_0c; double delta=uSolverPtr.c->m_300 * p->m_08; uSolverPtr.s = &uSolverPtr.c->m_1e0; uSolverPtr.s->m_10c = delta; uSolverPtr.s->m_110 = (float)uSolverPtr.s->m_114 * p->m_0c; }
    th->m_0c->m_94++;
    Arr28& arr = th->m_0c->m_aiIndexedValues;
    for (int i = 0; i < arr.m_uiItemCount; ++i) {
        BodyL* b = arr.m_data[i];
        th->FUN_0098df40(b->m_48, b->m_4c, th->m_0c, 0);
        if (DAT_010f3400->unk04 == 1) { ReleaseCurrent(th->m_0c); TickWrite<1>(ConstraintStep1173::DAT_00e32798, arg.tick); return; }
    }
    ReleaseCurrent(th->m_0c);
    th->m_0c->m_94++;
    Arr28& arr2 = th->m_0c->m_aiIndexedValues;
    for (int i = 0; i < arr2.m_uiItemCount; ++i) {
        BodyL* b = arr2.m_data[i];
        th->FUN_0098dae0(b, th->m_0c->m_78);
        if (DAT_010f3400->unk04 == 1) { ReleaseCurrent(th->m_0c); TickWrite<2>(ConstraintStep1173::DAT_00e32798, arg.tick); return; }
        if (th->m_0c->m_198 != 0) {
            TickWrite<0>(ConstraintStep1173::DAT_00e7d3cc, arg.tick);
            hkpWorldCallbackUtil_fireIslandPostCollideCallback(th->m_0c, b, p);
            TickWrite<0>(ConstraintStep1173::DAT_00e32798, tA);
        }
    }
    ReleaseCurrent(th->m_0c);
    TickWrite<0>(ConstraintStep1173::DAT_00e32798, arg.tick);
}


struct Tmp {
    int unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(void* a, int n);
    void FUN_00cb1870(void* a, int id, int z);
    int FindSlot(void* o);
    void ProcessArgument(void* a);
    void FUN_00a29680();
};

struct IFace {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int v, void* p);
};

struct Obj {
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
    unsigned char unkE8;
};

struct D0C290Entry {
    int unk00;
    int unk04;
    int unk08;
    Obj* m_0c;
    Obj* m_10;
    IFace* m_14;
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
};

struct D0C290Pair { unsigned int lo, hi; };

namespace fnv_00d0c3e0 {
struct Tmp {
    int unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(void* a, int n);
    void FUN_00cb1870(void* a, int id, int z);
    int FindSlot(void* o);
    void ProcessArgument(void* a);
    void FUN_00a29680();
};

struct IFace {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int v, void* p);
};

struct Obj {
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
    unsigned char unkE8;
};

struct D0C290Entry {
    int unk00;
    int unk04;
    int unk08;
    Obj* m_0c;
    Obj* m_10;
    IFace* m_14;
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
};

struct D0C290Pair { unsigned int lo, hi; };

}  // namespace fnv_00d0c3e0

extern const char str_010c41f8[];

struct __declspec(align(16)) S00d0c9c0_Ctx {
    void* m_pData;
    int m_iValue;
    int unk08;
    int unk0c;
    ThingBlock m_kStorage[192];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301c;
    int unk3020;
    int unk3024;
    int unk3028;
    int unk302c;
    float m_fValue;
    int unk3034;
    int unk3038;
    int unk303c;
    int unk3040;
    int unk3044;
    int unk3048;
    int unk304c;
    float m_fCoefficientA;
    float m_fB;
    int unk3058;
    int unk305c;
    int unk3060;
    int unk3064;
    int unk3068;
    int unk306c;
    int unk3070;
    int unk3074;
    int unk3078;
    int unk307c;
    int m_iFlags;
    int unk3084;
    int unk3088;
    int unk308c;
};

// Iterates apEntries, builds a context struct, configures apP table offsets, calls FUN_00cfedd0, and invokes v18 on the object when m_pData changed.
// @f3 0x0098de10 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;

struct TimerCmd_00d0c9c0 {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream_00d0c9c0 {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void Timer_00d0c9c0(const char* name)
{
    MonitorStream_00d0c9c0* s = (MonitorStream_00d0c9c0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        TimerCmd_00d0c9c0* h = (TimerCmd_00d0c9c0*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct ThingXEntryArray_00d0c9c0 {
    ThingX** m_pItems;
    int      m_iCount;
};

// pdb: hkpContinuousSimulation::processAgentNnEntries | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: entries, numEntries, collisionInput, island, forceManifoldQualityType
void __stdcall FUN_00d0c9c0(ThingX** apEntries, int aiCount, ThingP* apP, int aiValue)
{
    ThingXEntryArray_00d0c9c0* entries = (ThingXEntryArray_00d0c9c0*)apEntries;
    ThingP* p = (ThingP*)aiCount;

    Timer_00d0c9c0("TtNarrowPhaseTOI");

    for (int i = 0; i < entries->m_iCount; i++) {
        ThingX* x = entries->m_pItems[i];
        S00d0c9c0_Ctx ctx;
        ctx.m_fCoefficientA = 0.0f;
        ctx.m_fB = 0.0f;
        ctx.m_iValue = (int)apP;
        ctx.m_fValue = FUN_00de6e60;
        ctx.m_pData = ctx.m_kStorage;
        ctx.m_iFlags = 0;
        p->m_afEntries = (ThingEntry*)(p->m_pTable + 0x1da0);
        int kind = (signed char)x->m_bKind;
        p->unk10 = *(int*)(p->m_pTable + 0x1c30 + (kind << 6));
        FUN_00999610(x, p, (ThingS*)&ctx, (int)x->m_pObject);
        if (ctx.m_pData != ctx.m_kStorage) {
            x->m_pObject->v18(x->m_iA, x->m_iB, p, &ctx);
        }
    }

    Timer_00d0c9c0("Et");
    (void)aiValue;
}


typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

struct S_00d0e210_Heap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00d0e210_Router {
    char* m_stackCurrent;
    int unk04;
    int unk08;
    int unk0c;
    S_00d0e210_Heap* m_pStreamAllocator;
    S_00d0e210_Heap& heap() { return *m_pStreamAllocator; }
};


template <typename T>
struct S_00d0e210_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d0e210_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d0e210_Array() throw() { _clearAndDeallocate(((S_00d0e210_Router*)FUN_00c85750())->heap()); }
    void _clearAndDeallocate(S_00d0e210_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i) { return m_data[i]; }
};

template <typename T, int N>
struct S_00d0e210_Inplace : S_00d0e210_Array<T> {
    T m_kStorage[N];
    S_00d0e210_Inplace() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

struct S_00d0e210_Island;
struct S_00d0e210_Motion { int unk00; };
struct S_00d0e210_Entity {
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
    short unk28;
    unsigned char unk2A;
    unsigned char unk2B;
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
    S_00d0e210_Island* unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
    unsigned char unkE9;
    unsigned char unkEA;
    unsigned char unkEB;
    int unkEC;
    S_00d0e210_Motion unkF0;
};

typedef S_00d0e210_Inplace<S_00d0e210_Entity*, 2> S_00d0e210_PtrArray;
struct S_00d0e210_ToiEvent;

struct S_00d0e210_ContactMgr {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void removeToi(S_00d0e210_Island* island, int* props);
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void simulate(S_00d0e210_ToiEvent& event, float dt, S_00d0e210_PtrArray& entities);
};

struct S_00d0e210_Pair { int a; int b; };

struct S_00d0e210_ToiEvent {
    float m_uiCommandId;
    int unk04;
    int unk08;
    S_00d0e210_Entity* m_kActorEntries[2];
    S_00d0e210_ContactMgr* m_pContactManager;
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
    S_00d0e210_Island* island()
    {
        S_00d0e210_Entity* x = m_kActorEntries[0];
        if (x->unkE8 == 5)
            x = m_kActorEntries[1];
        return x->unkCC;
    }
    S_00d0e210_Island* islandOf()
    {
        if (m_kActorEntries[0]->unkE8 != 5)
            return m_kActorEntries[0]->unkCC;
        return m_kActorEntries[1]->unkCC;
    }
    void copyFrom(const S_00d0e210_ToiEvent& o)
    {
        const S_00d0e210_Pair* s = (const S_00d0e210_Pair*)&o;
        S_00d0e210_Pair* d = (S_00d0e210_Pair*)this;
        for (int i = 0; i != 14; i++)
            d[i] = s[i];
    }
};

struct S_00d0e210_ToiArray : S_00d0e210_Array<S_00d0e210_ToiEvent> {
    void removeAt(int i) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != i)
            m_data[i].copyFrom(m_data[m_iElementCount]);
    }
};

struct S_00d0e210_World {
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk98;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    int unkA0;
    int unkA4;
    void FUN_00c91120();
    void FUN_00c91140();
    void lockCriticalOperations() throw() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() throw()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount != 0)
                FUN_00c91120();
            if (unkA4 == 1 && m_iQueuedOperationCount != 0)
                FUN_00c91140();
        }
    }
};

void __cdecl FUN_00cc0ea0(S_00d0e210_Entity* entity, int arg) throw();

struct D0FE00TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D0FE00MonitorStream {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
};

namespace fnv_00d10730 {
struct D10730Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D10730MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D10730Allocator* m_pStreamAllocator;

    D10730Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D10730MemoryRouter& __cdecl FUN_00c85750();

struct FUN_00d10730 {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d10730();
    virtual ~FUN_00d10730();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00d10730* b = static_cast<FUN_00d10730*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00d10730
FUN_00d10730::FUN_00d10730()
{
}
}  // namespace fnv_00d10730

struct Se4b0_Heap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct Se4b0_Router {
    int unk00, unk04, unk08, unk0c;
    Se4b0_Heap* m_pStreamAllocator;
    Se4b0_Heap& heap() { return *m_pStreamAllocator; }
};
inline Se4b0_Router* Se4b0_router()
{
    return reinterpret_cast<Se4b0_Router*>(FUN_00c85750());
}
template <typename T> inline void Se4b0_construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++) p[i] = t;
}
template <class T> struct Se4b0_Arr {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(Se4b0_Heap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
    }
    void AddBack(const T& t)
    {
        Manager* r = FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(reinterpret_cast<void*>(r->unk10), reinterpret_cast<Vec*>(this), sizeof(T));
        Se4b0_construct<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
inline void Se4b0_freeStack(void* p)
{
    FUN_00c85750()->unk00 = reinterpret_cast<int>(p);
}
template <class T> struct Se4b0_LocalArr : Se4b0_Arr<T> {
    T* m_pStackAllocation;
    Se4b0_LocalArr(int n)
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        Manager* m = FUN_00c85750();
        int p = m->unk00;
        m->unk00 = p + n * sizeof(T);
        this->m_data = reinterpret_cast<T*>(p);
        this->m_iCapacityState = 0x80000000 | 1000;
        m_pStackAllocation = reinterpret_cast<T*>(p);
    }
    void release()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        Se4b0_freeStack(m_pStackAllocation);
        this->_clearAndDeallocate(Se4b0_router()->heap());
    }
};
struct Se4b0_Body;
struct __declspec(align(16)) Se4b0_Step {
    float start, end, delta, inverse;
};
struct Se4b0_WorldView {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    Se4b0_Step step;
};
inline Se4b0_Step& Se4b0_step(World* w)
{
    return reinterpret_cast<Se4b0_WorldView*>(w)->step;
}
struct Se4b0_Constraint {
    ItemObj* item;
    unsigned int entityA;
    unsigned int entityB;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Se4b0_Body* getOther(Se4b0_Body* e)
    {
        return reinterpret_cast<Se4b0_Body*>(entityB ^ entityA ^ reinterpret_cast<unsigned int>(e));
    }
};
struct Se4b0_Instance {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Se4b0_Constraint* internal;
};
struct Se4b0_Transform {
    float rotation00, rotation01, rotation02, rotation03;
    float rotation10, rotation11, rotation12, rotation13;
    float rotation20, rotation21, rotation22, rotation23;
    float positionX, positionY, positionZ, positionW;
};
struct Se4b0_MotionState {
    Se4b0_Transform transform;
    Se4b0_Transform swept;
};
void FUN_00cf1510(const Se4b0_Transform& swept, float t, Se4b0_Transform& out);
struct Se4b0_Dispatcher {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44();
    virtual void process(Se4b0_Body** bodies, int n, World* world, void* ctx, hkBool b);
};
struct Se4b0_Owner {
    int unk00, unk04;
    Se4b0_Dispatcher* dispatcher;
};
struct Se4b0_Body {
    int unk00, unk04;
    Se4b0_Owner* owner;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4;
    unsigned short storageIndex;
    unsigned short unkaa;
    Se4b0_Constraint* constraints;
    unsigned short numConstraints;
    unsigned short unkb2;
    Se4b0_Instance** slaves;
    int numSlaves;
    int unkbc, unkc0, unkc4, unkc8;
    void* context;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4;
    unsigned char motionType, unke9, unkea, unkeb;
    int unkec;
    Se4b0_MotionState motionState;
    Se4b0_Owner* getOwner() const { return owner; }
    void* getContext() const { return context; }
};
struct Se4b0_States {
    unsigned char* m_data;
    int m_iElementCount;
    unsigned char& operator[](int i) { return m_data[i]; }
};
inline void Se4b0_ensure(Se4b0_Body* body, float time, Se4b0_States& states)
{
    if (states[body->storageIndex] == 0) {
        states[body->storageIndex] = 1;
        Se4b0_MotionState* ms = &body->motionState;
        FUN_00cf1510(ms->swept, time, ms->transform);
    }
}
__forceinline void Se4b0_visit(Se4b0_Body* body, Se4b0_Constraint* c, int level, float time,
    Se4b0_States& states, Se4b0_Arr<Se4b0_Body*>* outBodies, Se4b0_Arr<ItemObj*>* outItems)
{
    if (level <= c->item->m_1c) {
        Se4b0_Body* other = c->getOther(body);
        if (other->motionType == 5) {
            outItems->AddBack(c->item);
        } else if (states[other->storageIndex] != 16) {
            outItems->AddBack(c->item);
            if (states[other->storageIndex] < 2) {
                outBodies->AddBack(other);
                Se4b0_ensure(other, time, states);
                states[other->storageIndex] = 2;
            }
        }
    }
}

// @f3 0x0098e780 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
void FUN_0098c240(void);
void FUN_0098c220(void);
void FUN_00990430(void* base, int lo, int hi, void* cmp);
void FUN_0098cd70(void* body, int level, float time, Se4b0_States* states, void* outArr);
void hkSweptTransformUtil_lerp2(const Se4b0_Transform& swept, float time, Se4b0_Transform& transform);
void FUN_008f6d90(void* data, unsigned int bytes, int tag);
void FUN_00901f10(void* arr, unsigned int elemSize);
struct S91_Stack {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual char* take(unsigned int n);
    virtual void put(void* p);
    void FUN_008f6d90(void* data, unsigned int bytes, int tag);
    int u04, u08, u0c, u10, u14, u18, u1c;
    char* cur;
    int u24;
    void* last;
    char* limit;
};
struct S91_Dispatcher {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40();
    virtual void process(void* entries, World* world, void* ctx, hkBool b);
};
struct S91_Owner {
    int unk00, unk04;
    S91_Dispatcher* dispatcher;
};
struct S91_Constraint {
    ItemObj* item;
    unsigned int entityA;
    unsigned int entityB;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct S91_Instance {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    S91_Constraint* internal;
};
struct S91_MotionState {
    Se4b0_Transform transform;
    Se4b0_Transform swept;
    __forceinline Se4b0_Transform& getTransform() { return transform; }
    __forceinline Se4b0_Transform& getSwept() { return swept; }
};
struct S91_Body {
    int unk00; int unk04;
    void* owner;
    int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38;
    int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50;
    int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68;
    int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80;
    int unk84; int unk88; int unk8c; int unk90;
    unsigned short storageIndex;
    unsigned short unk96;
    void* constraints;
    unsigned short numConstraints;
    unsigned short unk9e;
    void** slaves;
    int numSlaves;
    int unka8; int unkac; int unkb0; int unkb4;
    void* context;
    int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0;
    int unkd4;
    unsigned char motionType; unsigned char unkd9; unsigned char unkda; unsigned char unkdb;
    int unkdc;
    S91_MotionState motionState;
    __forceinline void* getContext() const { return context; }
};

template<class T> struct S91_Arr {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void append(const T& value) {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        m_data[m_iElementCount] = value;
        m_iElementCount++;
    }
};
struct S91_IslandArr {
    Se4b0_Body** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_pStackAllocation;
};
static __forceinline void S91_ensure(S91_Body* body, float time, Se4b0_States& states) {
    if (states[body->storageIndex] == 0) {
        states[body->storageIndex] = 1;
        S91_MotionState* ms = &body->motionState;
        hkSweptTransformUtil_lerp2(ms->getSwept(), time, ms->getTransform());
    }
}
static __forceinline void S91_visit(S91_Body* body, S91_Constraint* c, int level, float time,
    Se4b0_States* states, Se4b0_Arr<Se4b0_Body*>* outBodies, Se4b0_Arr<ItemObj*>* outItems)
{
    if (level <= c->item->m_1c) {
        S91_Body* other = reinterpret_cast<S91_Body*>(c->entityB ^ c->entityA ^ reinterpret_cast<unsigned int>(body));
        if (other->motionType == 7) {
            reinterpret_cast<S91_Arr<ItemObj*>*>(outItems)->append(c->item);
        } else if (states->m_data[other->storageIndex] != 16) {
            reinterpret_cast<S91_Arr<ItemObj*>*>(outItems)->append(c->item);
            if (states->m_data[other->storageIndex] < 2) {
                reinterpret_cast<S91_Arr<S91_Body*>*>(outBodies)->append(other);
                S91_ensure(other, time, *states);
                states->m_data[other->storageIndex] = 2;
            }
        }
    }
}
// pdb: hkLs_toiActivateEntitiesAndCheckConstraints | hkpContinuousSimulation.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: collisionInput, minPriorityToProcess, time, toBeActivated, entityState, newTouchedEntities, newTouchedConstraints
void FUN_00d0e4b0(World* world, int level, float time, Se4b0_Arr<Se4b0_Body*>* bodies, Se4b0_States* states, Se4b0_Arr<Se4b0_Body*>* outBodies, Se4b0_Arr<ItemObj*>* outItems)
{
    {
        S91_IslandArr isl;
        isl.m_data = 0;
        isl.m_iElementCount = 0;
        isl.m_iCapacityState = 0x80000000;
        S91_Stack* st = (S91_Stack*)TlsGetValue(DAT_010f3170);
        char* island;
        char* current = st->cur;
        if (current + 0xfb0 <= st->limit) {
            st->cur = current + 0xfb0;
            island = current;
        } else {
            island = st->take(0xfb0);
        }
        isl.m_data = (Se4b0_Body**)island;
        isl.m_iCapacityState = 0x800003e8;
        isl.m_pStackAllocation = island;
        for (int i = 0; i < bodies->m_iElementCount; i++) {
            S91_Body* body = reinterpret_cast<S91_Body*>(bodies->m_data[i]);
            S91_ensure(body, time, *states);
            states->m_data[body->storageIndex] = 8;
            FUN_0098cd70(body, level, time, states, &isl);
        }
        Se4b0_Step& step = Se4b0_step(world);
        Se4b0_Step saved = step;
        step.end = time;
        float delta = time - step.start;
        step.delta = delta;
        step.inverse = delta > 0.0f ? 1.0f / delta : 0.0f;
        S91_Owner* own = reinterpret_cast<S91_Owner*>(reinterpret_cast<S91_Body*>(bodies->m_data[0])->owner);
        S91_Dispatcher* d = own->dispatcher;
        d->process(&isl, world, reinterpret_cast<S91_Body*>(bodies->m_data[0])->getContext(), true);
        step = saved;
        char* allocation = isl.m_pStackAllocation;
        S91_Stack* s2 = (S91_Stack*)TlsGetValue(DAT_010f3170);
        s2->cur = allocation;
        if (allocation == s2->last)
            s2->put(allocation);
        if ((isl.m_iCapacityState & 0x80000000) == 0) {
            int capacity = isl.m_iCapacityState & 0x3fffffff;
            S91_Stack* heap = (S91_Stack*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(isl.m_data, capacity * 4, 23);
        }
    }
    for (int i = 0; i < bodies->m_iElementCount; i++) {
        S91_Body* body = reinterpret_cast<S91_Body*>(bodies->m_data[i]);
        states->m_data[body->storageIndex] = 16;
        for (int j = 0; j < body->numConstraints; j++)
            S91_visit(body, &reinterpret_cast<S91_Constraint*>(body->constraints)[j], level, time, states, outBodies, outItems);
        int firstItem = outItems->m_iElementCount;
        int firstBody = outBodies->m_iElementCount;
        for (int k = 0; k < body->numSlaves; k++)
            S91_visit(body, reinterpret_cast<S91_Instance*>(body->slaves[k])->internal, level, time, states, outBodies, outItems);
        int n = outItems->m_iElementCount - firstItem;
        if (n > 1)
            FUN_00990430(outItems->m_data + firstItem, 0, n - 1, (void*)FUN_0098c240);
        n = outBodies->m_iElementCount - firstBody;
        if (n > 1)
            FUN_00990430(outBodies->m_data + firstBody, 0, n - 1, (void*)FUN_0098c220);
    }
}


// Baseline from the attributed contributor draft dated 2026-10-28.
// Current-claim official checking is required; no padding instructions are inserted.
struct S_00d0d150_Entity {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac;
    int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    int unkd0;
    unsigned int m_uiUniqueId;
};

static __forceinline float& getSubStepTime(Context* ctx) {
    return reinterpret_cast<float&>(reinterpret_cast<Ctx*>(ctx)->unk0dc);
}

static __forceinline TimeStep& getContextTimeStep(Context* ctx) {
    return reinterpret_cast<TimeStep&>(reinterpret_cast<Ctx*>(ctx)->m_1d0);
}

static __forceinline void unlockContext(Context* ctx) {
    if (--ctx->depth() == 0 && !ctx->locked()) {
        if (ctx->pending())
            ctx->FUN_00c91120();
        if (ctx->mode() == 1 && ctx->otherPending())
            ctx->FUN_00c91140();
    }
}

struct S00d0e9c0_StepInfo {
    TimeStep s;
    __forceinline S00d0e9c0_StepInfo(float start, float end) {
        s.start = start;
        s.end = end;
        s.delta = end - start;
        s.inverse = (s.delta == 0.0f) ? 0.0f : (1.0f / s.delta);
    }
};

struct S00d0e9c0_DwordPair { int a, b; };

static __forceinline void memCpyOneAligned112(void* dst, const void* src) {
    for (int i = 0; i < 14; i++) {
        static_cast<S00d0e9c0_DwordPair*>(dst)[i] = static_cast<const S00d0e9c0_DwordPair*>(src)[i];
    }
}

static __forceinline void removeToiEventAt(S_00d0d150_Array<S_00d0d150_ToiEvent>& arr, int index) {
    arr.m_iElementCount--;
    if (arr.m_iElementCount != index) {
        memCpyOneAligned112(arr.m_data + index, arr.m_data + arr.m_iElementCount);
    }
}

struct S00d0e9c0_Key {
    unsigned int hi; unsigned int lo;
    __forceinline bool operator<(const S00d0e9c0_Key& o) const { return hi < o.hi || (hi == o.hi && lo < o.lo); }
};

struct S_00d0e9c0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17(Context* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);

    int unk04;
    int unk08;
    Context* m_iValueAtOffset0C;
    int unk10;
    float m_kRayStart;
    float m_kRayEnd;
    float m_stepTime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00d0d150_Array<S_00d0d150_ToiEvent> m_kToiEventQueue;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int m_iToiEventCount;

    int hkpContinuousSimulation_handleAllToisTill(float arg1);
    hkBool FUN_00d0bc20(S_00d0d150_ToiEvent* ev, float* fSubStepTime);
    void FUN_00d0e210(Context* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);
};

// Repeatedly picks the earliest queued TOI event, removes it, dispatches via vfn17 or FUN_00d0e210, and returns 0 when none is left or 3 when DAT_01269200 is 1.
// @f3 0x0098c340 (community match, verified in this file)
struct S_00d0e9c0_Actor {
    char m_unk00[0xc0];
    unsigned int m_uiUniqueId;
};

struct S_00d0e9c0_Event {
    float m_uiCommandId;
    S_00d0e9c0_Actor* m_kActorEntries[2];
    float m_fSeparation;
    void* m_pContactManager;
    int m_aiUnk14;
    int m_aiUnk18;
    int m_aiUnk1c;
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    int m_aiContactData[5];
    int m_aiUnk54;
    int m_aiUnk58;
    int m_aiUnk5c;
    int m_aiUnk60;
    int m_aiUnk64;
    int m_aiUnk68;
    int m_aiUnk6c;
};

struct S_00d0e9c0_Context {
    char m_unk000[0x6c];
    World* m_pWorld;
    char m_unk070[0x10];
    int m_iPending;
    int m_iDepth;
    char m_unk088[4];
    unsigned char m_ucLocked;
    char m_unk08d[0x190 - 0x8d];
    TimeStep m_kStep;
    void FUN_00902550();
};

struct S_00d0e9c0_EventOps {
    void FUN_00990390(S_00d0e9c0_Event* last);
};

struct S_00d0e9c0_View {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16(S_00d0e9c0_Context* ctx, S_00d0e9c0_Event* ev, float fStepTime);

    int unk04;
    int unk08;
    S_00d0e9c0_Context* m_pContext;
    int unk10;
    float m_kRayStart;
    float m_kRayEnd;
    float m_stepTime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00d0d150_Array<S_00d0e9c0_Event> m_kToiEventQueue;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

static __forceinline void removeToiEventAt(S_00d0d150_Array<S_00d0e9c0_Event>& arr, int index) {
    arr.m_iElementCount -= 1;
    reinterpret_cast<S_00d0e9c0_EventOps*>(&arr.m_data[index])->FUN_00990390(&arr.m_data[arr.m_iElementCount]);
}

// pdb: hkpContinuousSimulation::handleAllToisTill | hkpContinuousSimulation.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int S_00d0e9c0::hkpContinuousSimulation_handleAllToisTill(float minTime) {
    S_00d0e9c0_View* self = reinterpret_cast<S_00d0e9c0_View*>(this);
    while (true) {
        float earliest = minTime;
        int bestIdx = -1;
        for (int i = 0; i < self->m_kToiEventQueue.m_iElementCount; i++) {
            S_00d0e9c0_Event& cand = self->m_kToiEventQueue.m_data[i];
            if (cand.m_uiCommandId < earliest) {
                bestIdx = i;
                earliest = cand.m_uiCommandId;
            } else if (cand.m_uiCommandId == earliest && bestIdx != -1) {
                S00d0e9c0_Key candKey = { cand.m_kActorEntries[0]->m_uiUniqueId,
                                          cand.m_kActorEntries[1]->m_uiUniqueId };
                S00d0e9c0_Key bestKey = { self->m_kToiEventQueue.m_data[bestIdx].m_kActorEntries[0]->m_uiUniqueId,
                                          self->m_kToiEventQueue.m_data[bestIdx].m_kActorEntries[1]->m_uiUniqueId };
                if (candKey < bestKey) {
                    bestIdx = i;
                    earliest = cand.m_uiCommandId;
                }
            }
        }
        if (bestIdx < 0)
            return 0;

        // Fake match: the named data pointer makes the copy's source address take the scaled index as its
        // base; read straight from the array the two address operands come out exchanged.
        S_00d0e9c0_Event* data = self->m_kToiEventQueue.m_data;
        S_00d0e9c0_Event event = data[bestIdx];
        removeToiEventAt(self->m_kToiEventQueue, bestIdx);

        self->m_kRayStart = event.m_uiCommandId;
        S00d0e9c0_StepInfo step(event.m_uiCommandId, self->m_kRayEnd);
        self->m_pContext->m_kStep = step.s;
        self->m_pContext->m_pWorld->time() = step.s;

        self->m_pContext->m_iDepth++;
        self->vfn16(self->m_pContext, &event, self->m_stepTime);
        S_00d0e9c0_Context* ctx = self->m_pContext;
        if (--ctx->m_iDepth == 0 && !ctx->m_ucLocked && ctx->m_iPending)
            ctx->FUN_00902550();

        self->unk40++;
        if (DAT_010f3400->unk04 == 1)
            return 3;
    }
}


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _mm_prefetch(const char*, int);
extern unsigned long DAT_0126835c;
extern char DAT_010cc624[], DAT_010cd3e8[], DAT_010cc5fc[], DAT_010cc5f0[];
extern char DAT_010cd3d8[], DAT_010c41f8[], DAT_010cc5e4[], DAT_010cc5d8[], DAT_01076f38[];

struct ScratchSpan {
    unsigned* start;
    int count;
    unsigned capacity;
    unsigned* original;
};
void __cdecl FUN_00cf7130(ScratchSpan*, ScratchSpan*);
struct RenderSink {
    void __thiscall DispatchPairs(unsigned*, int);
    void __thiscall FUN_00cf7080(unsigned*, int, void*);
};
struct Dispatcher {
    virtual void slot00(); virtual void slot04();
    virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24();
    virtual void slot28();
    virtual void Dispatch(unsigned**, unsigned*, int, ScratchSpan*, ScratchSpan*);
    unsigned unk04, unk08, unk0c;
    int enabled;
    void __thiscall FUN_00d97050();
    void __thiscall FUN_00d97060();
};
struct Allocator {
    virtual void slot00(); virtual void slot04();
    virtual void slot08(); virtual void slot0c();
    virtual void Free(unsigned*, unsigned);
    virtual void slot14(); virtual void slot18();
    virtual void slot1c(); virtual void slot20();
    virtual bool Available(int);
};
struct S00d0d3f0_Router {
    int cur;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* alloc;
    Allocator& heap() { return *alloc; }
};
static inline S00d0d3f0_Router* S00d0d3f0_router() { return (S00d0d3f0_Router*)FUN_00c85750(); }
struct Region { unsigned unk00, unk04; unsigned data; };
struct RenderParams {
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
    Dispatcher* dispatcher;
    unsigned unk05c;
    unsigned unk060;
    RenderSink* sink;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    World* texture;
    Region* region;
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
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    unsigned unk320;
    unsigned unk324;
    unsigned unk328;
    unsigned unk32c;
    unsigned unk330;
    unsigned unk334;
    unsigned unk338;
    unsigned batchCount;
    void __thiscall EnterLock(unsigned);
    void __thiscall FUN_00c91210(unsigned);
};
struct CompressedBounds {
    unsigned minX, minY, minZ;
    unsigned char minMarginX, minMarginY, minMarginZ, shift;
    unsigned maxX, maxY, maxZ;
    unsigned char maxMarginX, maxMarginY, maxMarginZ, reserved;
};
struct Source {
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
    CompressedBounds bounds;
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
    unsigned handle;
};
struct TraceCmd {
    const char* name;
    unsigned time0;
    unsigned time1;
    const char* category;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        time0=ticks;
    }
};
struct TraceState {
    unsigned unk00;
    char* cursor;
    unsigned unk08;
    char* end;
};
static __forceinline void Trace(unsigned char* event, unsigned char* category=0)
{
    TraceState* state=(TraceState*)TlsGetValue(DAT_0126835c);
    char* cursor=state->cursor;
    if (cursor<state->end) {
        TraceCmd* h=(TraceCmd*)cursor;
        h->name=(const char*)event;
        if (category) h->category=(const char*)category;
        h->setTime();
        state->cursor=cursor+(category ? 16 : 12);
    }
}
// @f3 0x0098df40 (community match, verified in this file)
// FUN_00d0d3f0 (0x0098df40): Havok 5.5.0 hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous (hkpInternal):
// runs the broad phase for a set of entities of one island: gathers their expanded integer AABBs (recomputing an
// invalid one), updates them in the 3-axis sweep broad phase under its lock, removes duplicate pairs, waits for the
// solver's export, then removes and adds the collision agents of the changed pairs with the island locked.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers and the
// preprocessed source was cut down mechanically to the declarations the function's code needs (every cut checked
// byte for byte against the SDK's release library object), so the declarations are the SDK's text with its names;
// the SDK's trap instructions in the unused placement operators new[] and delete[] were removed. hkpContinuousSimulation,
// which no SDK header ships, is declared from the hkpInternal library's debug records, with the bodies of its two inline
// helpers (waitForSolverExport, removeAndAddPairs) written from the library's object code; they do not use the object,
// and are static and public here. In the SDK the function is a member of hkpContinuousSimulation; its object is used only by a
// debug-build assert, so the release code is the same as for the unit's __stdcall declaration of FUN_00d0d3f0, under
// which it is defined here, its parameters bound to the SDK's types at the top of the body. The clock read in
// hkMonitorStream::TimerCommand::setTime is the SDK's own two-instruction block, the one the kit accepts: the plain
// __rdtsc() form gives 1308 bytes of the function's 1364.
namespace f3m_0098df40 {

typedef float  hkReal;
typedef signed char		hkChar;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __int64 hkUint64;
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
class hkHalf
{
	    inline hkHalf& operator=(const float& f)
	    {
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			midf++;
		}
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				__forceinline void setData(T p)
				{
					hkUlong v = hkUlong(p);
					TlsSetValue( m_slotID, (void*)v );
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		int m_referenceCount;
		Stack m_stack;
		struct FreeList
		{
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
			}
			void* get()
			{
				if(void* p = m_head)
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkFinishLoadedObjectFlag
{
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};
class hkOstream;
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		enum
		{
		};
	protected:
		T*			m_data;
		hkUint16	m_size;
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
class hkVector4
{
	public:
		__forceinline void setAll3(hkReal x);
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal w;
};
class hkQuaternion
{
};
class hkMatrix3
{
	public:
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
		void renormalize();
};
class hkTransform
{
		hkVector4 m_translation;
};
class hkSweptTransform
{
		hkVector4 m_centerOfMassLocal;
};
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkAabb
{
		hkVector4 m_max;
};
struct hkAabbUint32
{
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};
class hkSphere;
class hkpCdVertex;
enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
};
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
		hkEnum<hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
class hkMotionState;
class hkpCdBody
{
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_MAX
};
struct hkpCollisionQualityInfo;
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput
{
	public:
		struct Aabb32Info
		{
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
class hkpBroadPhaseHandle
{
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
		hkInt8 m_ownerOffset;
		hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline const hkpTypedBroadPhaseHandle* getBroadPhaseHandle() const;
		struct BoundingVolumeData
		{
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
inline const hkpTypedBroadPhaseHandle* hkpCollidable::getBroadPhaseHandle() const
{
	return &m_broadPhaseHandle;
}
struct hkpSolverInfo
{
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
class hkpConstraintData;
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
		}
		__forceinline void markForWrite( )
		{
		}
		__forceinline bool isMarkedForWrite( )
		{
			return true;
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		__forceinline void unmarkForRead( )
		{
		}
		__forceinline void unmarkForWrite()
		{
		}
		void disableChecks();
		void enableChecks();
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkpPropertyValue
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkUint64 m_data;
};
class hkpProperty
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		static void __cdecl mapStringToKey( const char* string, hkUint32& keyOut );
};
class hkpWorld;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		inline hkpCollidable* getCollidableRw();
		inline const hkpCollidable* getCollidable() const;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline const hkpLinkedCollidable* getLinkedCollidable() const;
		inline const hkpLinkedCollidable* getCollidableMtUnchecked() const;
		inline void setName( const char* name );
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
		inline void markForRead( );
		inline void markForWrite( );
		void markForWriteImpl( );
		inline void unmarkForRead( );
		inline void unmarkForWrite();
		void checkReadWrite();
		void checkReadOnly() const;
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
	public:
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		inline void copyProperties( const hkpWorldObject* otherObj );
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
inline const hkpCollidable* hkpWorldObject::getCollidable() const
{
	return &m_collidable;
}
inline hkMultiThreadCheck& hkpWorldObject::getMultiThreadCheck()
{
	return m_multiThreadCheck;
}
inline void hkpWorldObject::markForRead( )
{
	getMultiThreadCheck().markForRead();
}
inline void hkpWorldObject::unmarkForRead( )
{
	getMultiThreadCheck().unmarkForRead();
}
class hkpMaterial
{
	public:
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
		virtual ~hkpKeyframedRigidMotion();
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpSimulationIsland;
class hkpConstraintInstance;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpEntity();
		inline hkBool isFixedOrKeyframed() const;
		inline hkUint32 getUid() const;
		hkpDynamicsContactMgr* findContactMgrTo(const hkpEntity* entity) const;
		void activate();
		void deactivate();
		hkpEntity( class hkFinishLoadedObjectFlag flag );
		inline hkpMotion* getMotion();
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SpuCollisionCallback():
				m_util(0),
				m_capacity(0),
				m_eventFilter(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
				m_userFilter(0x01)
			{
			}
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
inline hkpSimulationIsland* hkpEntity::getSimulationIsland() const
{
	return m_simulationIsland;
}
inline hkUint32 hkpEntity::getUid() const
{
	return m_uid;
}
extern struct hkCheckDeterminismUtil* g_checkDeterminismUtil;
struct hkCheckDeterminismUtil
{
	public:
		struct Fuid
		{
			hkUint32 m_0, m_1, m_2, m_3;
			static Fuid& getZeroFuid();
			hkBool operator==(const Fuid& f)
			{
				return m_0 == f.m_0 && m_1 == f.m_1 && m_2 == f.m_2 && m_3 == f.m_3;
			}
			hkBool operator!=(const Fuid& f)
			{
				return m_0 != f.m_0 || m_1 != f.m_1 || m_2 != f.m_2 || m_3 != f.m_3;
			}
		};
		 hkCheckDeterminismUtil();
		void startCheckMode(const char* filename = "hkDeterminismCheckfile.bin");
		template<typename TYPE> static __forceinline void __cdecl checkSt( TYPE* object, int numObjects = 1 ) { }
		template<typename TYPE> static __forceinline void __cdecl checkSt( TYPE object ) { }
		template<typename TYPE> static __forceinline void __cdecl checkMt( TYPE* object, int numObjects = 1 ) { }
		template<typename TYPE> static __forceinline void __cdecl checkMt( TYPE object ) { }
		hkCriticalSection* m_shared;
		struct JobInfo
		{
			Fuid	  m_jobFuid;
			hkArray<char>* m_data;
			hkBool		  m_isOpen;
		};
		hkArray<JobInfo> m_registeredJobs;
		hkBool m_writingStFromWorker;
};
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
class hkpWorldCinfo : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum SolverType
		{
			SOLVER_TYPE_INVALID,
			SOLVER_TYPE_2ITERS_SOFT,
			SOLVER_TYPE_2ITERS_MEDIUM,
			SOLVER_TYPE_8ITERS_MEDIUM,
			SOLVER_TYPE_8ITERS_HARD,
			SOLVER_TYPE_MAX_ID
		};
		enum SimulationType
		{
			SIMULATION_TYPE_INVALID,
			SIMULATION_TYPE_DISCRETE,
			SIMULATION_TYPE_CONTINUOUS,
			SIMULATION_TYPE_MULTITHREADED,
		};
		enum ContactPointGeneration
		{
			CONTACT_POINT_ACCEPT_ALWAYS,
			CONTACT_POINT_REJECT_DUBIOUS,
			CONTACT_POINT_REJECT_MANY,
		};
		enum BroadPhaseBorderBehaviour
		{
			BROADPHASE_BORDER_ASSERT,
			BROADPHASE_BORDER_FIX_ENTITY,
			BROADPHASE_BORDER_REMOVE_ENTITY,
			BROADPHASE_BORDER_DO_NOTHING,
		};
		hkpWorldCinfo();
		hkReal m_contactRestingVelocity;
		hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
		class hkAabb m_broadPhaseWorldAabb;
		hkReal m_collisionTolerance;
		class hkpCollisionFilter* m_collisionFilter;
		class hkpConvexListFilter* m_convexListFilter;
		hkReal m_expectedMaxLinearVelocity;
		int m_sizeOfToiEventQueue;
		hkReal m_expectedMinPsiDeltaTime;
		class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
		virtual ~hkpWorldCinfo() {}
		explicit hkpWorldCinfo( hkFinishLoadedObjectFlag flag );
};
struct hkpProcessCollisionInput;
class hkpTypedBroadPhaseDispatcher;
struct hkpWorldRayCastInput;
struct hkpWorldRayCastOutput;
class hkpBroadPhase;
class hkpRigidBody;
class hkpPhantom;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpActionListener;
class hkpConstraintListener;
class hkpPhysicsSystem;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;
namespace hkWorldOperation {
}
enum hkpUpdateCollisionFilterOnWorldMode
{
	HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
	HK_UPDATE_FILTER_ON_WORLD_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
};
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
enum hkpUpdateCollectionFilterMode
{
	HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS,
	HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS
};
struct hkpWorldDynamicsStepInfo
{
	hkStepInfo   m_stepInfo;
	hkpSolverInfo m_solverInfo;
};
enum hkpThreadToken
{
	HK_THREAD_TOKEN_FIRST,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};
class hkpWorld : public hkReferencedObject
{
	public:
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpWorld(const hkpWorldCinfo& info, unsigned int sdkversion = ((10000*5) + (100*5) + (0)) );
		void getCinfo(hkpWorldCinfo& info) const;
		hkpEntity* addEntity( hkpEntity* entity, hkpEntityActivation initialActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE);
		void removePhysicsSystem( const hkpPhysicsSystem* sys );
		inline hkpRigidBody* getFixedRigidBody();
		inline const hkpRigidBody* getFixedRigidBody() const;
		void updateCollisionFilterOnEntity( hkpEntity* entity,
			                                hkpUpdateCollisionFilterOnEntityMode updateMode,
											hkpUpdateCollectionFilterMode updateShapeCollectionFilter);
		void updateCollisionFilterOnPhantom( hkpPhantom* phantom,
											 hkpUpdateCollectionFilterMode updateShapeCollectionFilter );
		void updateCollisionFilterOnWorld( hkpUpdateCollisionFilterOnWorldMode updateMode,
										   hkpUpdateCollectionFilterMode updateShapeCollectionFilter );
		enum ReintegrationRecollideMode
		{
			RR_MODE_REINTEGRATE = 1,
			RR_MODE_RECOLLIDE_BROADPHASE = 2,
			RR_MODE_RECOLLIDE_NARROWPHASE = 4,
			RR_MODE_ALL = 7
		};
		void reintegrateAndRecollideEntities( hkpEntity** entityBatch, int numEntities, ReintegrationRecollideMode mode = RR_MODE_ALL );
		inline const hkArray<hkpPhantom*>& getPhantoms() const;
		void setGravity( const hkVector4& gravity );
		void unlock();
		void unlockReadOnly();
		bool isLocked();
		void lockIslandForConstraintUpdate( hkpSimulationIsland* island );
		void unlockIslandForConstraintUpdate( hkpSimulationIsland* island );
		inline hkpProcessCollisionInput* getCollisionInput();
		inline hkpSolverInfo* getSolverInfo();
		inline hkpCollisionDispatcher* getCollisionDispatcher() const;
		inline const hkpCollisionFilter* getCollisionFilter() const;
		void setCollisionFilter( hkpCollisionFilter* filter,
								 hkBool             runUpdateCollisionFilterOnWorld = true,
								 hkpUpdateCollisionFilterOnWorldMode checkBroadPhaseMode = HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
								 hkpUpdateCollectionFilterMode       updateShapeCollectionFilter = HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS );
		void castRay(const hkpWorldRayCastInput& input, hkpWorldRayCastOutput& output ) const;
		void castRay(const hkpWorldRayCastInput& input, hkpRayHitCollector& collector ) const;
		hkMultiThreadCheck& getMultiThreadCheck() const { return m_multiThreadCheck; }
		void checkAccessGetActiveSimulationIslands() const;
		hkpPhysicsSystem* getWorldAsOneSystem() const;
		void getWorldAsSystems(hkArray<hkpPhysicsSystem*>& systemsOut) const;
		~hkpWorld();
	public:
		hkpSimulation* m_simulation;
		hkVector4			m_gravity;
        hkpSimulationIsland* m_fixedIsland;
			hkpRigidBody*	m_fixedRigidBody;
        hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
        hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
        hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
        hkpWorldMaintenanceMgr* m_maintenanceMgr;
        hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
        hkpBroadPhase* m_broadPhase;
        hkpTypedBroadPhaseDispatcher*    m_broadPhaseDispatcher;
        hkpPhantomBroadPhaseListener*    m_phantomBroadPhaseListener;
        hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
        hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
        hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
        hkpProcessCollisionInput* m_collisionInput;
            hkpCollisionFilter*       m_collisionFilter;
            hkpCollisionDispatcher*   m_collisionDispatcher;
            hkpConvexListFilter*     m_convexListFilter;
        hkpWorldOperationQueue* m_pendingOperations;
			int m_pendingOperationsCount;
			int m_criticalOperationsLockCount;
			int m_criticalOperationsLockCountForPhantoms;
			hkBool m_blockExecutingPendingOperations;
			hkBool m_criticalOperationsAllowed;
            hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
			int m_pendingOperationQueueCount;
        mutable class hkMultiThreadCheck m_multiThreadCheck;
		hkBool m_processActionsInSingleThread;
		hkUint32 m_minDesiredIslandSize;
        class hkCriticalSection* m_modifyConstraintCriticalSection;
        class hkCriticalSection* m_worldLock;
        class hkCriticalSection* m_islandDirtyListCriticalSection;
		struct PropertyLock
		{
			hkUint32 m_key;
			mutable hkMultiThreadCheck m_multiThreadCheck;
		};
        class hkCriticalSection* m_propertyMasterLock;
		hkBool m_wantSimulationIslands;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_wantDeactivation;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		hkBool m_processToisMultithreaded;
		int m_maxSectorsPerCollideTask;
		hkArray<hkpPhantom*> m_phantoms;
        hkArray<hkpActionListener*>              m_actionListeners;
        hkArray<hkpEntityListener*>              m_entityListeners;
        hkArray<hkpPhantomListener*>             m_phantomListeners;
        hkArray<hkpConstraintListener*>          m_constraintListeners;
        hkArray<hkpWorldDeletionListener*>       m_worldDeletionListeners;
        hkArray<hkpIslandActivationListener*>    m_islandActivationListeners;
        hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
        hkArray<hkpWorldPostIntegrateListener*>  m_worldPostIntegrateListeners;
        hkArray<hkpWorldPostCollideListener*>    m_worldPostCollideListeners;
        hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
        hkArray<hkpIslandPostCollideListener*>   m_islandPostCollideListeners;
        hkArray<hkpCollisionListener*>           m_collisionListeners;
        hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
        class hkpBroadPhaseBorder*               m_broadPhaseBorder;
	public:
		struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
		hkVector4 m_broadPhaseExtents[2];
		int			m_broadPhaseNumMarkers;
		int			m_sizeOfToiEventQueue;
		hkInt32		m_broadPhaseQuerySize;
		hkInt32		m_broadPhaseUpdateSize;
        hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
		void attachActionToEntity(hkpAction* action, hkpEntity* entity);
		void detachActionFromEntity(hkpAction* action, hkpEntity* entity);
	public:
		__forceinline void	allowCriticalOperations(hkBool allow);
		explicit hkpWorld( hkFinishLoadedObjectFlag flag );
};
inline hkpProcessCollisionInput* hkpWorld::getCollisionInput()
{
	return m_collisionInput;
}
inline const hkpCollisionFilter* hkpWorld::getCollisionFilter() const
{
	return m_collisionFilter;
}
class hkpConstraintQueryIn;
struct hkpProcessCollisionOutput;
class hkpSimulation: public hkReferencedObject
{
	public:
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
};
class hkpTypedBroadPhaseHandlePair;
class hkpBroadPhaseListener
{
	public:
		virtual ~hkpBroadPhaseListener() {}
		virtual void addCollisionPair( hkpTypedBroadPhaseHandlePair& pair ) = 0;
		virtual void removeCollisionPair( hkpTypedBroadPhaseHandlePair& pair ) = 0;
};
class hkpBroadPhaseHandlePair;
class hkpBroadPhaseCastCollector;
typedef char hkpBroadPhaseAabbCache;
class hkpBroadPhase: public hkReferencedObject
{
	public:
		hkpBroadPhase();
		~hkpBroadPhase();
		enum BroadPhaseType
		{
			BROADPHASE_16BIT,
			BROADPHASE_32BIT
		};
		virtual BroadPhaseType getType() const = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObjectBatch( hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray< hkAabb >& addAabbList, hkArray<hkpBroadPhaseHandlePair>& newPairs ) = 0;
		virtual void removeObject( hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairsOut ) = 0;
		virtual void removeObjectBatch( hkArray<hkpBroadPhaseHandle*>& removeObjectList, hkArray<hkpBroadPhaseHandlePair>& delPairsOut ) = 0;
		virtual int getNumObjects() = 0;
		virtual void updateAabbs( hkpBroadPhaseHandle* objects[], const hkAabb* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void updateAabbsUint32( hkpBroadPhaseHandle* objects[], const hkAabbUint32* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void defragment() = 0;
		virtual void getAllAabbs( hkArray<hkAabb>& allAabbs ) const = 0;
		virtual void getAabb(const hkpBroadPhaseHandle* object, hkAabb& aabb) const = 0;
		virtual void getExtents(hkVector4& worldMinOut, hkVector4& worldMaxOut) const = 0;
		virtual void querySingleAabb( const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void reQuerySingleObject( const hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void getOffsetLowHigh32bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const = 0;
		struct hkpCastRayInput
		{
			hkVector4		m_from;
			int       m_numCasts;
			const hkVector4* m_toBase;
			int		  m_toStriding;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
			hkpCastRayInput(): m_numCasts(1), m_toStriding( int(sizeof(hkVector4))),m_aabbCacheInfo(0){}
		};
		virtual	void castRay( const hkpCastRayInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const = 0;
		virtual int getAabbCacheSize() const = 0;
		virtual void calcAabbCache( const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		virtual void calcAabbCache( const hkArray<class hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		struct hkpCastAabbInput
		{
			hkVector4 m_from;
			hkVector4 m_to;
			hkVector4 m_halfExtents;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
			hkpCastAabbInput(): m_aabbCacheInfo(0){}
		};
		virtual void castAabb( const hkpCastAabbInput& input, hkpBroadPhaseCastCollector& collector ) const = 0;
		__forceinline void markForWrite();
		__forceinline void unmarkForRead() const;
		__forceinline void unmarkForWrite();
		__forceinline void lock();
		__forceinline void unlock();
		typedef hkpBroadPhase* (__cdecl *createBroadPhaseFunc)( const hkVector4& worldMin, const hkVector4& worldMax, int numMarkers );
		static createBroadPhaseFunc m_defaultCreationFunction;
	protected:
		void lockImplementation();
		void unlockImplementation();
	protected:
		mutable hkMultiThreadCheck m_multiThreadCheck;
		class hkCriticalSection *m_criticalSection;
};
inline void hkpBroadPhase::markForWrite( )
{
	m_multiThreadCheck.markForWrite();
}
inline void hkpBroadPhase::unmarkForWrite()
{
	m_multiThreadCheck.unmarkForWrite();
}
inline void hkpBroadPhase::lock()
{
	if ( m_criticalSection )
	{
		lockImplementation();
	}
	else
	{
		markForWrite();
	}
}
inline void hkpBroadPhase::unlock()
{
	if ( m_criticalSection )
	{
		unlockImplementation();
	}
	else
	{
		unmarkForWrite();
	}
}
class hkpBroadPhaseHandlePair
{
	public:
		hkpBroadPhaseHandle* m_a;
		hkpBroadPhaseHandle* m_b;
};
class hkpCollidableCollidableFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpCollidableCollidableFilter() { }
		virtual hkBool isCollisionEnabled( const hkpCollidable& a, const hkpCollidable& b ) const = 0;
};
class hkpNullBroadPhaseListener : public hkReferencedObject, public hkpBroadPhaseListener
{
	public:
		hkpNullBroadPhaseListener() { }
		virtual void addCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
		virtual void removeCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
};
class hkpTypedBroadPhaseDispatcher
{
	public:
		hkpTypedBroadPhaseDispatcher();
		~hkpTypedBroadPhaseDispatcher();
		static void __cdecl removeDuplicates( hkArray<hkpBroadPhaseHandlePair>& newPairs, hkArray<hkpBroadPhaseHandlePair>& delPairs );
		void addPairs(	hkpTypedBroadPhaseHandlePair* newPairs, int numNewPairs, const hkpCollidableCollidableFilter* filter ) const;
		void removePairs( hkpTypedBroadPhaseHandlePair* deletedPairs, int numDeletedPairs ) const;
		inline hkpBroadPhaseListener* getBroadPhaseListener( int typeA, int typeB );
		inline void setBroadPhaseListener( hkpBroadPhaseListener* listener, int typeA, int typeB );
		inline hkpBroadPhaseListener* getNullBroadPhaseListener();
	protected:
		hkpBroadPhaseListener*    m_broadPhaseListeners[8][8];
		hkpNullBroadPhaseListener m_nullBroadPhaseListener;
};
class hkpTypedBroadPhaseHandlePair : public hkpBroadPhaseHandlePair
{
	public:
		__forceinline hkpTypedBroadPhaseHandle* getElementA() const;
		__forceinline hkpTypedBroadPhaseHandle* getElementB() const;
		__forceinline hkpTypedBroadPhaseHandle* getOther(hkpTypedBroadPhaseHandle* elem) const;
};
class hkEntityAabbUtil
{
	public:
		static void __cdecl entityBatchRecalcAabb(const hkpCollisionInput* collisionInput, hkpEntity*const* entityBatch, int numEntities);
		static void __cdecl entityBatchInvalidateAabb(hkpEntity*const* entityBatch, int numEntities);
};
template <typename T>
class hkLocalArray : public hkArray<T>
{
	public:
		__forceinline hkLocalArray( int capacity )
		{
			this->m_data = hkAllocateStack<T>(capacity);
			this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline void discardAndResize(int newsize)
		{
			hkDeallocateStack<T>( m_localMemory );
			m_localMemory = this->m_data = hkAllocateStack<T>(newsize);
			this->m_size = newsize;
			this->m_capacityAndFlags = newsize | hkArray<T>::DONT_DEALLOCATE_FLAG;
		}
		void assertNotResized()
		{
		}
		hkBool wasReallocated() const
		{
			return m_localMemory != this->m_data;
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};
struct hkMemoryStatistics;
class hkLimitedMemoryListener;
typedef void (__cdecl *hkMemoryWalkCallback)(void* start, hk_size_t size,hkBool allocated,int pool,void* param);
class hkMemory
{
	public:
		friend class hkThreadMemory;
		hkMemory();
		virtual ~hkMemory();
		virtual void allocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void deallocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateChunk( void*, int nbytes, HK_MEMORY_CLASS cl ) = 0;
		virtual void* allocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void preAllocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void provideRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void freeRuntimeBlocks() = 0;
		virtual void reservePagesFromSystemMemory( int numBytes ) {}
        virtual void garbageCollect() {}
        virtual void optimize() {}
		virtual void releaseUnusedPagesToSystemMemory( void ) {}
		virtual void printStatistics(hkOstream* c) = 0;
		virtual int getAllocatedSize( int size );
		virtual bool isDebugMemory(){ return false; }
        virtual void calculateStatistics(hkMemoryStatistics& stats ) =0;
        virtual void setMemoryHardLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemoryHardLimit() { return 0; }
        virtual void setMemorySoftLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemorySoftLimit() { return 0; }
        virtual void setLimitedMemoryListener(hkLimitedMemoryListener* listener) {}
        virtual hkLimitedMemoryListener* getLimitedMemoryListener() { return 0; }
        virtual hkBool hasMemoryAvailable(hk_size_t size) { return true; }
		virtual hkBool isOk() const;
		virtual void* findBaseAddress(void* p, int nbytes) { return 0; }
		virtual void lockBlock(void* p) {}
		virtual void unlockBlock(void* p) {}
        virtual hkResult walkMemory(hkMemoryWalkCallback callback,void* param) { return HK_FAILURE; }
		enum MemoryState
		{
			MEMORY_STATE_OK,
			MEMORY_STATE_OUT_OF_MEMORY
		};
		MemoryState m_memoryState;
		int m_criticalMemoryLimit;
        int m_memoryUsed;
		static inline hkMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkMemory* m);
		__forceinline void addReference();
		__forceinline void removeReference();
		enum MemoryFill
		{
			MEMORY_FILL_GUARD_AREA = 0xFD,
			MEMORY_FILL_FREE_SPACE = 0xDD,
			MEMORY_FILL_RETURNED_TO_USER = 0xCD
		};
	protected:
		static hkMemory* s_instance;
		int m_referenceCount;
		struct BigBlockData
		{
		};
		enum { BIG_BLOCKS_SLOTS=128 };
		int m_numValidBigBlocks;
		BigBlockData m_bigBlockDataArray[BIG_BLOCKS_SLOTS];
	public:
		static hkInt32 s_fillGuardArea;
		static hkInt32 s_fillFreeSpace;
		static hkInt32 s_fillReturnedToUser;
};
hkMemory& __cdecl hkMemory::getInstance()
{
	return *s_instance;
}
namespace hkVector4Util
{
__forceinline void __cdecl uncompressExpandedAabbUint32(const hkAabbUint32& unexpandedAabbInt, hkAabbUint32& expandedAabbOut);
}
inline void __cdecl hkVector4Util::uncompressExpandedAabbUint32(const hkAabbUint32& unexpandedAabbInt, hkAabbUint32& expandedAabbOut)
{
	int shift = unexpandedAabbInt.m_expansionShift;
	hkUint32 mix = unexpandedAabbInt.m_min[0] - (unexpandedAabbInt.m_expansionMin[0] << shift);
	hkUint32 miy = unexpandedAabbInt.m_min[1] - (unexpandedAabbInt.m_expansionMin[1] << shift);
	hkUint32 miz = unexpandedAabbInt.m_min[2] - (unexpandedAabbInt.m_expansionMin[2] << shift);
	expandedAabbOut.m_min[0]= mix;
	expandedAabbOut.m_min[1]= miy;
	expandedAabbOut.m_min[2]= miz;
	hkUint32 maxx = unexpandedAabbInt.m_max[0] + (unexpandedAabbInt.m_expansionMax[0] << shift);
	hkUint32 may  = unexpandedAabbInt.m_max[1] + (unexpandedAabbInt.m_expansionMax[1] << shift);
	hkUint32 maz  = unexpandedAabbInt.m_max[2] + (unexpandedAabbInt.m_expansionMax[2] << shift);
	expandedAabbOut.m_max[0]= maxx;
	expandedAabbOut.m_max[1]= may;
	expandedAabbOut.m_max[2]= maz;
}
class hkpRayCollidableFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpRayCollidableFilter() { }
		virtual hkBool isCollisionEnabled( const hkpWorldRayCastInput& a, const hkpCollidable& collidableB ) const = 0;
};
class hkpShapeCollectionFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpShapeCollectionFilter() { }
};
class hkpRayShapeCollectionFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpRayShapeCollectionFilter() { }
};
class hkpCollisionFilter :	public hkReferencedObject,
						public hkpCollidableCollidableFilter,
						public hkpShapeCollectionFilter,
						public hkpRayShapeCollectionFilter,
						public hkpRayCollidableFilter
{
	public:
		enum hkpFilterType
		{
			HK_FILTER_UNKNOWN		= 0,
			HK_FILTER_NULL			= 1,
			HK_FILTER_GROUP			= 2,
			HK_FILTER_LIST			= 3,
			HK_FILTER_CUSTOM		= 4,
			HK_FILTER_PAIR			= 5,
			HK_FILTER_CONSTRAINT	= 6,
		};
	public:
		hkUint32 m_prepad[2];
		hkEnum<hkpFilterType,hkUint32> m_type;
		hkUint32 m_postpad[3];
};
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
struct hkpToiEvent;
class hkpToiResourceMgr;
class hkpContinuousSimulation : public hkpSimulation
{
	public:
		hkpContinuousSimulation( hkpWorld* world );
		virtual ~hkpContinuousSimulation();
	public:
		static __forceinline void waitForSolverExport( hkChar* exportFinished );
		static __forceinline void removeAndAddPairs( hkpWorld* world, hkpEntity** entities, hkLocalArray<hkpBroadPhaseHandlePair>& newPairs, hkLocalArray<hkpBroadPhaseHandlePair>& delPairs );
	public:
		__declspec(align(16)) hkArray<hkpToiEvent> m_toiEvents;
		hkpToiResourceMgr* m_toiResourceMgr;
		int m_toiCounter;
};
__forceinline void hkpContinuousSimulation::waitForSolverExport( hkChar* exportFinished )
{
	if ( exportFinished && !*exportFinished )
	{
		HK_TIMER_BEGIN("WaitForExport", HK_NULL);
		volatile hkChar* finished = exportFinished;
		while ( *finished != 1 && *finished != 2 ) { }
		HK_TIMER_END();
	}
}
__forceinline void hkpContinuousSimulation::removeAndAddPairs( hkpWorld* world, hkpEntity** entities, hkLocalArray<hkpBroadPhaseHandlePair>& newPairs, hkLocalArray<hkpBroadPhaseHandlePair>& delPairs )
{
	if ( newPairs.getSize() + delPairs.getSize() > 0 )
	{
		HK_TIMER_SPLIT_LIST("RemoveAgt");
		world->lockIslandForConstraintUpdate( entities[0]->getSimulationIsland() );
		world->m_broadPhaseDispatcher->removePairs( static_cast<hkpTypedBroadPhaseHandlePair*>( delPairs.begin() ), delPairs.getSize() );
		hkMemory& memory = hkMemory::getInstance();
		if ( !memory.hasMemoryAvailable( newPairs.getSize() * 1024 ) )
		{
			memory.m_memoryState = hkMemory::MEMORY_STATE_OUT_OF_MEMORY;
			world->unlockIslandForConstraintUpdate( entities[0]->getSimulationIsland() );
			return;
		}
		HK_TIMER_SPLIT_LIST("AddAgt");
		world->m_broadPhaseDispatcher->addPairs( static_cast<hkpTypedBroadPhaseHandlePair*>( newPairs.begin() ), newPairs.getSize(), world->getCollisionFilter() );
		world->unlockIslandForConstraintUpdate( entities[0]->getSimulationIsland() );
	}
}

}  // namespace f3m_0098df40

struct Source;
struct RenderParams;

// The function under the unit's declaration of FUN_00d0d3f0: its four parameters are the island's entities, their
// number, the world and the solver's export flag (the SDK's hkpEntity**, int, hkpWorld* and hkChar*).
// pdb: hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous | hkpContinuousSimulation.obj | fnv360_0822_retail, strset, low
// pdb params: entities, numEntities, world, exportFinished
void __stdcall FUN_00d0d3f0(Source** sources, int count, RenderParams* context, void* marker)
{
	using namespace f3m_0098df40;
	hkpEntity** entities = reinterpret_cast<hkpEntity**>( sources );
	const int numEntities = count;
	hkpWorld* world = reinterpret_cast<hkpWorld*>( context );
	hkChar* exportFinished = static_cast<hkChar*>( marker );
	if ( numEntities == 0 )
	{
		return;
	}
	hkpSimulationIsland* island = 0;
	HK_TIMER_BEGIN_LIST("BroadPhase", "GatherAabbs");
	hkLocalArray<hkpBroadPhaseHandlePair> newPairs( world->m_broadPhaseUpdateSize );
	hkLocalArray<hkpBroadPhaseHandlePair> delPairs( world->m_broadPhaseUpdateSize );
	{
		hkAabbUint32* aabbs32 = hkAllocateStack<hkAabbUint32>( numEntities );
		const hkpBroadPhaseHandle** broadPhaseHandles = hkAllocateStack<const hkpBroadPhaseHandle*>( numEntities );
		int numAabbs = numEntities;
		{
			hkpEntity** e = entities;
			hkAabbUint32* aabb32 = aabbs32;
			const hkpBroadPhaseHandle** handle = broadPhaseHandles;
			for ( int i = numAabbs - 1; i >= 0; e++, i-- )
			{
				hkpEntity* entity = *e;
				hkCheckDeterminismUtil::checkMt( entity->getUid() );
				entity->markForRead();
				const hkpCollidable* collidable = entity->getCollidable();
				*handle = collidable->getBroadPhaseHandle();
				if ( !collidable->m_boundingVolumeData.isValid() )
				{
					hkEntityAabbUtil::entityBatchRecalcAabb( world->getCollisionInput(), &entity, 1 );
				}
				const hkAabbUint32& tmp = reinterpret_cast<const hkAabbUint32&>( collidable->m_boundingVolumeData );
				hkVector4Util::uncompressExpandedAabbUint32( tmp, *aabb32 );
				aabb32++;
				handle++;
			}
		}
		HK_TIMER_SPLIT_LIST("3AxisSweep");
		{
			world->m_broadPhase->lock();
			hkpBroadPhaseHandle** nonConstHandles = const_cast<hkpBroadPhaseHandle**>( broadPhaseHandles );
			world->m_broadPhase->updateAabbsUint32( nonConstHandles, aabbs32, numAabbs, newPairs, delPairs );
			world->m_broadPhase->unlock();
		}
		hkDeallocateStack( broadPhaseHandles );
		hkDeallocateStack( aabbs32 );
	}
	if ( newPairs.getSize() + delPairs.getSize() > 0 )
	{
		HK_TIMER_SPLIT_LIST("RemoveDup");
		hkpTypedBroadPhaseDispatcher::removeDuplicates( newPairs, delPairs );
	}
	hkpContinuousSimulation::waitForSolverExport( exportFinished );
	hkpContinuousSimulation::removeAndAddPairs( world, entities, newPairs, delPairs );
	for ( int e = 0; e < numEntities; e++ ) { entities[e]->unmarkForRead(); }
	HK_TIMER_END_LIST();
}


extern const char str_010c41f8[];
struct S00d0d8b0_Array {
    unsigned char** m_data;
    int m_iElementCount;
    int GetLogicalSize() const { return m_iElementCount; }
    unsigned char* operator[](int i) const { return m_data[i]; }
};
struct S00d0d8b0_Coll {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    int m_lastSize;
    S00d0d8b0_Array m_kSectors;
    int getSectorSize(int i) const { return (i + 1 == m_kSectors.GetLogicalSize()) ? m_lastSize : 0x200; }
};
struct S00d0d8b0_Props {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
};
struct S00d0d8b0_Toi {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S00d0d8b0_Props m_kProperties;
    int m_aiContactData[7];
};
struct S00d0d8b0_Out {
    S_00d0d150_ProcessCdPoint* m_firstFree;
    S00d0d8b0_Coll* m_pOwnerObject;
    int unk08;
    int unk0c;
    S_00d0d150_ProcessCdPoint m_akContactPoints[256];
    S00d0d8b0_Toi m_fTimeOfImpact;
    void* m_potential;
    S00d0d8b0_Out(S00d0d8b0_Coll* owner) : m_pOwnerObject(owner) { m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_fTimeOfImpact.m_kProperties.m_fAccumulatedImpulse = 0.0f; m_fTimeOfImpact.m_kProperties.m_fImpulseLimit = 0.0f; }
    void reset() { m_firstFree = &m_akContactPoints[0]; m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_potential = 0; }
    bool hasToi() const { return m_fTimeOfImpact.m_uiCommandId != 3.40282e+38f; }
};
struct S00d0d8b0_Obj {
    void QueueToiEvent(S00d0d8b0_Out* out, ThingX* x);
    void FUN_00d0d8b0(S00d0d8b0_Coll* coll, ThingP* p);
};
static __forceinline void WriteClock(const char* name) {
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_uiCommandId = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
// @f3 0x0098dae0 (community match, verified in this file)
namespace Task2273 {
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d2e4[],DAT_00e32798[];
struct NativeVector{__m128 value;};
struct NativePoint{NativeVector position,normal; int id,unk24,unk28,unk2c;};
struct MonitorStreamD0{int unk00;char* m_kRayEnd;int unk08;char* m_capacityEnd;};
struct TimerCommandD0{const char* m_name;unsigned m_uiCommandId;int unk08;};
struct NativeArray {
    unsigned char** m_data;
    int m_iElementCount;
    int GetLogicalSize() const { return m_iElementCount; }
    unsigned char* operator[](int i) const { return m_data[i]; }
};
struct NativeColl {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    int m_lastSize;
    NativeArray m_kSectors;
    int getSectorSize(int i) const { return (i + 1 == m_kSectors.GetLogicalSize()) ? m_lastSize : 0x200; }
};
struct NativeProps {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
};
struct NativeToi {
    NativeVector m_vContactPosition;
    NativeVector m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    NativeProps m_kProperties;
    int m_aiContactData[7];
};
struct NativeOut {
    NativePoint* m_firstFree;
    NativeColl* m_pOwnerObject;
    int unk08;
    int unk0c;
    NativePoint m_akContactPoints[256];
    NativeToi m_fTimeOfImpact;
    void* m_potential;
    NativeOut(NativeColl* owner) : m_pOwnerObject(owner) { m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_fTimeOfImpact.m_kProperties.m_fAccumulatedImpulse = 0.0f; m_fTimeOfImpact.m_kProperties.m_fImpulseLimit = 0.0f; }
    void reset() { m_firstFree = &m_akContactPoints[0]; m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_potential = 0; }
    bool hasToi() const { return m_fTimeOfImpact.m_uiCommandId != 3.40282e+38f; }
};
static __forceinline void WriteClock(const char* name) {
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0116913c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_uiCommandId = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct NativeP {unsigned char* table;
int unk04;
int unk08;
int unk0c;
int cached;
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
ThingEntry* entries;};
struct Flag {unsigned char value; Flag(){} Flag(bool b):value(b){} };
struct State {
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
virtual Flag Query(int);int state;};
extern State* DAT_010f3400;
void __cdecl FUN_00999610(ThingX*,NativeP*,NativeOut*,ThingVCallObject*);
struct NativeObj{void FUN_0098c830(NativeOut*,ThingX*);};
}
void S00d0d8b0_Obj::FUN_00d0d8b0(S00d0d8b0_Coll* originalColl,ThingP* originalP){
 using namespace Task2273;
 NativeColl* coll=(NativeColl*)originalColl;NativeP* p=(NativeP*)originalP;
 unsigned char* end;
 Task2273::WriteClock(DAT_00e7d2e4);
 NativeOut out(coll);
 for(int i=0;i<coll->m_kSectors.GetLogicalSize();){
 unsigned char* rec=coll->m_kSectors[i];i++;
 if(i==coll->m_kSectors.GetLogicalSize())end=rec+coll->m_lastSize;else end=rec+0x200;
 while(rec<end){ThingX* x=(ThingX*)rec;int kind=(signed char)x->m_bKind;int a=x->m_iA;int b=x->m_iB;
 p->entries=(ThingEntry*)(p->table+kind*64+0x1c20);p->cached=p->entries->m_iValue;
 out.reset();FUN_00999610(x,p,&out,x->m_pObject);
 State* state=Task2273::DAT_010f3400;
 if(!state->Query(0).value){state->state=1;Task2273::WriteClock(DAT_00e32798);return;}
 if(state->state==1){state->state=1;Task2273::WriteClock(DAT_00e32798);return;}
 if(out.m_firstFree!=&out.m_akContactPoints[0])x->m_pObject->v18(a,b,p,&out);
 if(out.hasToi())((NativeObj*)this)->FUN_0098c830(&out,x);
 rec+=rec[3];
 }
 }
 Task2273::WriteClock(DAT_00e32798);
}


#include <string.h>

typedef unsigned int U32;
typedef unsigned char U8;
class BoolFlag {
    char value;
public:
    inline BoolFlag() {}
    inline BoolFlag(bool b) {value=static_cast<char>(b);}
    inline operator bool() const {return value!=0;}
    inline BoolFlag& operator=(bool b) {value=char(b);return *this;}
    inline BoolFlag operator==(bool b) const {return int(value)==int(b);}
    inline BoolFlag operator!=(bool b) const {return int(value)!=int(b);}
};
struct Heap {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) void freeBuffer(void*,int) throw();
    template<class T> inline void release(void* p,int n) {freeBuffer(p,n*sizeof(T));}
};
struct StackArena {
    char* top;
    int unk04,unk08;
    __forceinline void* take(int n) {char* p=top;top=p+n;return p;}
    __forceinline void put(void* p) {top=static_cast<char*>(p);}
};
class RouterFacade {
    StackArena arena;
    Heap* temporary;
    Heap* regular;
public:
    static __declspec(nothrow) RouterFacade& __cdecl FUN_00c85750();
    inline StackArena& stack() {return arena;}
    inline Heap& heap() {return *regular;}
};
struct ArrayOps {
    static __declspec(nothrow) void __cdecl FUN_00c908c0(Heap&,void*,int,int) throw();
    static __declspec(nothrow) void __cdecl ResizeAudioStream(Heap&,void*,int) throw();
    __forceinline static void GrowArray(Heap& a,void* p,int n) {ResizeAudioStream(a,p,n);}
};
template<class T> __forceinline void releaseArena(T* p) {RouterFacade::FUN_00c85750().stack().put(p);}
template<class T> __forceinline T* allocateArena(int n) {return static_cast<T*>(RouterFacade::FUN_00c85750().stack().take((n*sizeof(T)+127)&~127));}
struct SelectHeap {
    inline Heap& get(const void*) const {return RouterFacade::FUN_00c85750().heap();}
};
template<class T> __forceinline void copyOne(T* dst,const T* src) {*reinterpret_cast<unsigned int*>(dst)=*reinterpret_cast<const unsigned int*>(src);}
struct ScalarTag {};
struct ObjectTag {};
template<class T> struct ElementTag {typedef ObjectTag type;};
template<class T> struct ElementTag<T*> {typedef ScalarTag type;};
template<class T> __forceinline void destroyElements(T*,int,ScalarTag) {}
template<class T> __forceinline void destroyElements(T* p,int n,ObjectTag) {for(int i=0;i<n;++i)p[i].~T();}
template<class T> __forceinline void copyElements(T* p,int n,const T& value) {for(int i=0;i<n;++i)p[i]=value;}
template<class T> __forceinline void destroyRange(T* p,int n) {destroyElements(p,n,typename ElementTag<T>::type());}
template<class T> __forceinline void assignRange(T* p,int n,const T* q) {for(int j=0;j<n;++j)p[j]=q[j];}
template<class T> class ListBase {
protected:
    T* data;
    int size;
    int flags;
protected:
    __forceinline __declspec(nothrow) ListBase(const ListBase&) throw() {}
    __forceinline ListBase& operator=(const ListBase&) {return *this;}
public:
    enum { SizeMask=0x3fffffff, Borrowed=int(0x80000000u), Signed=-1 };
    __forceinline __declspec(nothrow) ListBase() throw():data(0),size(0),flags(Borrowed) {}
    __forceinline __declspec(nothrow) ListBase(T* p,int n,int cap) throw():data(p),size(n),flags(cap|Borrowed) {}
    __forceinline int GetLogicalSize() const {return size;}
    __forceinline int getCapacity() const {return flags&SizeMask;}
    __forceinline bool isEmpty() const {return size==0;}
    __forceinline T* begin() {return data;}
    __forceinline const T* begin() const {return data;}
    __forceinline T& operator[](int i) {return data[i];}
    __forceinline const T& operator[](int i) const {return data[i];}
    __forceinline void clear() {destroyRange(data,size);size=0;}
    __forceinline void drop(Heap& a) {
        clear();
        if((flags&Borrowed)==0)a.release<T>(data,getCapacity());
        data=0;flags=Borrowed;
    }
    __forceinline void reserveWith(Heap& a,int n) {
        const int capacity=getCapacity();if(capacity<n) {int doubled=2*capacity;int requested=(n<doubled)?doubled:n;ArrayOps::FUN_00c908c0(a,this,requested,sizeof(T));}
    }
    __forceinline void pushBackUnchecked(const T& value) {
        copyElements(data+size,1,value);++size;
    }
    __forceinline T* expandByUnchecked(int n) {int old=size;size=old+n;return data+old;}
    __forceinline void removeAt(int i) {--size;if(size!=i)copyOne(data+i,data+size);}
    __declspec(nothrow) void splice(Heap&,int,int,const T*,int);
    __declspec(noinline) __declspec(nothrow) void Search(Heap&,int,const T*,int) throw();
    __declspec(noinline) __declspec(nothrow) void CallWithFlag(Heap&,int,const T&) throw();

};
template<class T> __declspec(nothrow) void ListBase<T>::splice(Heap& a,int at,int erased,const T* source,int n) {
        int result=n+size-erased;
        int moving=size-at-erased;
        if(result>getCapacity())reserveWith(a,result);
        destroyRange(data+at,erased);
        memmove(data+at+n,data+at+erased,moving*sizeof(T));
        assignRange(data+at,n,source);
        size=result;
    }
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::Search(Heap& a,int at,const T* source,int n) throw() {splice(a,at,0,source,n);}
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::CallWithFlag(Heap& a,int at,const T& value) throw() {Search(a,at,&value,1);}
template<class T> class List : public ListBase<T> {
public:
    __forceinline __declspec(nothrow) List() throw() {}
    __forceinline __declspec(nothrow) List(T* p,int n,int cap) throw():ListBase<T>(p,n,cap) {}
    __forceinline __declspec(nothrow) ~List() throw() {ClearAndRelease();}
    __forceinline void ClearAndRelease() {this->drop(SelectHeap().get(this));}
    __forceinline void reserve(int n) {this->reserveWith(SelectHeap().get(this),n);}
    __forceinline void aiRecipeIndex(int i,const T& t) {this->CallWithFlag(SelectHeap().get(this),i,t);}
    __forceinline void aiRecipeIndex(int i,const T* p,int n) {this->Search(SelectHeap().get(this),i,p,n);}
};
template<class T,int N> class InlineList : public List<T> {
    T storage[N];
public:
    __forceinline __declspec(nothrow) InlineList(int n=0) throw():List<T>(storage,n,N) {}
    __forceinline __declspec(nothrow) ~InlineList() throw() {}
};
template<class T> class ArenaList : public List<T> {
    T* original;
public:
    __forceinline __declspec(nothrow) ArenaList(int n) throw() {
        this->data=allocateArena<T>(n);
        this->flags=n|ListBase<T>::Borrowed;
        original=this->data;
    }
    __forceinline BoolFlag wasReallocated() const {return original!=this->data;}
    __forceinline __declspec(nothrow) ~ArenaList() throw() {
        if(!wasReallocated())this->clear();
        releaseArena(original);
    }
};
struct DynamicNode;
struct SolverIsland {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44;
    List<DynamicNode*> entities;
    inline const List<DynamicNode*>& GetEntities() const {return entities;}
};
template<class E,class S> class StoredEnum {
    S storage;
public:
    inline StoredEnum() {}
    inline StoredEnum(E e):storage(S(e)) {}
    inline operator E() const {return E(storage);}
    inline void operator=(E e) {storage=S(e);}
    inline BoolFlag operator==(E e) const {return storage==S(e);}
    inline BoolFlag operator!=(E e) const {return storage!=S(e);}
};
struct Motion {
    enum MotionType { Invalid=0,Dynamic=1,Keyframed=4,Fixed=5,MOTION_KEYFRAMED=4 };
    int unk00,unk04;
    StoredEnum<MotionType,U8> type;
    U8 unk09,unk0a,unk0b;
    int unk0c;
    hkMotionState state;
    inline hkMotionState* GetMotionState() {return &state;}
    inline MotionType getType() const {return type;}
};
struct DynamicNode {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    U32 unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    U32 unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    U32 unk60,unk64,unk68,unk6c,unk70;
    const char* m_name;
    U32 unk78,unk7c;
    inline const char* getName() const {return m_name;}
    U32 unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4;
    unsigned short m_usStorageIndex,unkaa;
    U32 unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8;
    SolverIsland* island;
    U32 unkd0,unkd4,unkd8,unkdc;
    Motion movement;
    inline BoolFlag isFixed() const {return movement.type==Motion::Fixed;}
    inline BoolFlag isFixedOrKeyframed() const {return movement.type==Motion::Fixed || movement.type==Motion::Keyframed;}
    inline SolverIsland* GetSimulationIsland() const {return island;}
    inline Motion* getMotion() {return &movement;}
    inline Motion* getRigidMotion() {return &movement;}
};
struct ConstraintPair { int unk00;DynamicNode* bodies[2]; };
struct Constraint {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    ConstraintPair* pair;
    enum ConstraintPriority { PriorityZero=0,PriorityForced=5 };
    inline DynamicNode* getEntityA() const {return pair->bodies[0];}
    inline DynamicNode* getEntityB() const {return pair->bodies[1];}
};
struct Schema;
struct Accumulator;
struct SolverElement;
struct ResourceInfo;
struct TimeInterval;
struct BackupTransform;
struct ConstraintQuery;
template<class T> struct UnsignedShortArray {T* m_pRayStart;T* m_kRayEnd;T* m_pTileTemplate;T* m_pValues;};
struct Resources {
    TimeInterval* m_pStepInfo;
    ResourceInfo* m_pSolverInfo;
    ConstraintQuery* m_pConstraintQueryIn;
    Accumulator* m_pVelocityAccumulatorA;
    Accumulator* m_pVelocityAccumulatorB;
    Accumulator* m_pVelocityAccumulatorC;
    BackupTransform* m_pBodyABackup;
    BackupTransform* m_pBodyBBackup;
    UnsignedShortArray<Schema> m_akBufferStates[2];
    SolverElement* m_pBufferA;
    SolverElement* m_pBufferB;
    SolverElement* m_pBufferC;
    SolverElement* m_pBufferD;
};
struct SchemaRecord {Constraint* m_pHavokConstraint;Schema* m_pConstraintSchema;float m_fAllowedPenetrationDepth;};
struct CollisionInput {};
struct ProcessInput : CollisionInput {};
struct Scene {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    U32 unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    U32 unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    U32 unk60,unk64,unk68,unk6c,unk70,unk74;
    ProcessInput* input;
    inline ProcessInput* getCollisionInputRw() {return input;}
};


struct StateTable {
    unsigned char* data;
    int size;
    __forceinline unsigned char& operator[](int i) {return data[i];}
};
struct Limits {
    Constraint::ConstraintPriority priority;
    int entities,contacts,constraints,fullSteps,extraSteps;
};
struct PairEvent;
struct PairManager {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual void s10();virtual void s14();virtual void s18();virtual void s1c();
    virtual void s20();virtual void s24();virtual void s28();virtual void s2c();
    virtual void s30();virtual void s34();virtual void s38();virtual void s3c();
    virtual void s40();virtual void s44();
    virtual __declspec(nothrow) void confirm(PairEvent&,float,List<DynamicNode*>&) throw();
};
struct PairEvent {
    float time;
    int unk04,unk08;
    DynamicNode* bodies[2];
    PairManager* manager;
};
struct Violation { Constraint* constraint; const void* point; const void* properties; };
struct ResourceManager {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) int violations(List<Violation>&) throw();
    virtual __declspec(nothrow) int overflow() throw();
};

// hkTraceStream: the -Od lib shows hkToiPrintf at these sites; the SDK macro is if(0) hkTraceStream::GetMonitorStream().dontPrintf.
struct TraceStream {
    static TraceStream* s_instance;
    static inline TraceStream& GetMonitorStream() {return *s_instance;}
    void __cdecl dontPrintf(const char*,const char*,...);
};
__declspec(nothrow) void FUN_00cf1b10(float,hkMotionState&) throw();
__declspec(nothrow) void FUN_00d892d0() throw();
__declspec(nothrow) void FUN_00d88670(Resources&,DynamicNode* const*,int) throw();
__declspec(nothrow) BoolFlag FUN_00d88310(Resources&,DynamicNode**,int) throw();
__declspec(nothrow) BoolFlag CheckTotalsWithinLimits(Resources&,Constraint**,int) throw();
__declspec(nothrow) void FUN_00d88340(Resources&,int) throw();
__declspec(nothrow) void FUN_00d88760(Resources&,Constraint**,int,List<SchemaRecord>&) throw();
__declspec(nothrow) void FUN_00d0cb00(Resources&,ProcessInput&,List<SchemaRecord>&,int&,Constraint::ConstraintPriority,StateTable&,const List<DynamicNode*>&,List<DynamicNode*>&) throw();
__declspec(nothrow) void FUN_00d0e4b0(ProcessInput&,Constraint::ConstraintPriority,float,const List<DynamicNode*>&,StateTable&,List<DynamicNode*>&,List<Constraint*>&) throw();
__declspec(nothrow) void FUN_00d0cde0(float,SolverIsland*,StateTable&,List<DynamicNode*>&) throw();
__declspec(nothrow) void FUN_00cc0ea0(DynamicNode*,const CollisionInput&) throw();
__declspec(nothrow) void FUN_00d0bf30(Resources&,const List<DynamicNode*>&) throw();
__declspec(nothrow) BoolFlag CollectMatchingEntries(Resources&,const List<SchemaRecord>&,ProcessInput&,List<Violation>*) throw();
__declspec(nothrow) void FUN_00d8aac0(const ResourceInfo&,Schema*,Accumulator*,SolverElement*) throw();
__declspec(nothrow) void FUN_00d88580(const ResourceInfo&,const TimeInterval&,const Accumulator*,DynamicNode* const*,int) throw();
__declspec(nothrow) void UpdateIslandMotionStates(SolverIsland*,StateTable&,Resources&) throw();
__declspec(nothrow) void PartitionMotionPairs(List<SchemaRecord>&,int&,int) throw();
__declspec(nothrow) void FUN_00d0c6d0(List<SchemaRecord>&,int&,StateTable&) throw();

struct SweepView {hkVector4 center0,center1,rotation0,rotation1,localCenter;};
struct RotationSetter {__declspec(nothrow) void FUN_00cb2d90(void*);};
struct TransformView {hkRotation rotation;hkVector4 translation;};
__declspec(nothrow) void FUN_00cf1510(const SweepView&,float,TransformView&) throw();
__forceinline void updateEntity(DynamicNode* node,float time) {
    hkMotionState* m=node->getMotion()->GetMotionState();
    FUN_00cf1510(*reinterpret_cast<SweepView*>(&m->m_vCenterOfMass0),time,*reinterpret_cast<TransformView*>(m));
}
__forceinline void restoreState(hkMotionState* m) {
    reinterpret_cast<RotationSetter*>(m)->FUN_00cb2d90(&m->m_qRotation1);
    __m128 center=m->m_vCenterOfMassLocal.m_vComponents;
    __m128 y=_mm_mul_ps(_mm_shuffle_ps(center,center,0x55),m->m_rotation.m_kColumn1.m_vComponents);
    __m128 x=_mm_mul_ps(_mm_shuffle_ps(center,center,0),m->m_rotation.m_kColumn0.m_vComponents);
    __m128 z=_mm_mul_ps(_mm_shuffle_ps(center,center,0xaa),m->m_rotation.m_kColumn2.m_vComponents);
    m->m_vTranslation.m_vComponents=_mm_sub_ps(m->m_vCenterOfMass1.m_vComponents,_mm_add_ps(_mm_add_ps(y,x),z));
}
struct SolvePoint { hkVector4 position,normal; };
struct SolveAtoms {
    U32 unk00;
    unsigned short unk04,m_iElementCount;
    unsigned short unk08;
    U8 stride,unk0b;
    U32 unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    SolvePoint points[1];
};
struct SolveConstraintData {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual int GetType();
    U32 unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
    SolveAtoms* atoms;
};
struct SolveConstraint {
    U32 unk00,unk04,unk08;
    SolveConstraintData* data;
    U32 unk10,unk14,unk18;
    U8 priority;
};
struct SolveRecord { SolveConstraint* constraint; void* schema; float depth; };
extern "C" __declspec(nothrow) int __cdecl FUN_00d9f6f0(void*,void*,void*,int,float*) throw();
extern "C" __declspec(nothrow) int __cdecl FUN_00d0bd30(float,SolveRecord*,float*,int,void*) throw();

// @f3 0x0098ec70 (community match, verified in this file)
// Fallout 3 copy of Havok 5.5.0 hkLs_localizedSolveToi (hkpContinuousSimulation.cpp), written on the SDK headers;
// the same-file callees whose bodies the original file showed the compiler are defined above it (SDK records).
namespace hk550 {
class hkMotionState;
typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult {
HK_SUCCESS = 0,
HK_FAILURE = 1
};
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset ) {
return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
class hkClass;
typedef int hkBool32;
class hkBool {
public:
inline hkBool(bool b) {
m_bool = static_cast<char>(b);
}
inline operator bool() const {
return m_bool != 0;
}
private:
char m_bool;
};
class hkHalf {
private:
hkInt16 m_value;
};
class hkUFloat8 {
public:
enum { MAX_VALUE = 256 };
public:
hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum {
public:
operator ENUM() const {
return static_cast<ENUM>(m_storage);
}
private:
STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu {
public:
__forceinline TYPE val() const {
return m_storage;
}
__forceinline operator TYPE() const {
return val();
}
private:
TYPE m_storage;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
class hkThreadLocalData {
public:
__forceinline T getData() const {
return (T)(hkUlong)TlsGetValue(m_slotID) ;
}
unsigned long m_slotID;
};
enum HK_MEMORY_CLASS { HK_MEMORY_CLASS_ARRAY = 23 };
class hkMemory;
class hkThreadMemory {
public:
void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
__forceinline void* allocateStack(int nbytes);
__forceinline void deallocateStack(void* p);
virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
virtual void alignedDeallocate(void* ptr);
virtual void setStackArea(void* buf, int nbytes);
static inline hkThreadMemory* __cdecl getInstancePtr();
static inline hkThreadMemory& __cdecl getInstance();
virtual void releaseCachedMemory();
__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
protected:
virtual void* onStackOverflow(int nbytes);
virtual void onStackUnderflow(void* p);
public:
enum {
PAGE_ALIGN = 64,
MEMORY_MAX_SMALL_ROW = 13,
MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
MEMORY_MAX_SIZE_SMALL_BLOCK = 512,
MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
MEMORY_SYSTEM_PAGE_SIZE = 8192,
MEMORY_MAGIC_NUMBER = 0x3425234
};
struct Stack {
__declspec(align(16)) char* m_current;
Stack* m_prev;
char* m_base;
char* m_end;
};
protected:
enum { BATCH_SIZE=4 };
public:
hkMemory* m_memory;
int m_referenceCount;
Stack m_stack;
int m_stackSize;
int m_maxNumElemsOnFreeList;
struct FreeList {
enum { MAX_FREELIST=0x0fffffff };
struct FreeElem { FreeElem* m_next; };
FreeElem* m_head;
int m_numElem;
};
FreeList m_free_list[MEMORY_MAX_ALL_ROW];
int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr() {
extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance() {
hkThreadMemory* instance = getInstancePtr();
return *instance;
}
template <typename TYPE> __forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkBaseObject {
public:
__forceinline virtual ~hkBaseObject() {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject {
public:
virtual ~hkReferencedObject() { }
virtual void calcStatistics( hkStatisticsCollector* collector ) const;
virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
public:
enum {
MASK_MEMSIZE = 0x7fff
};
hkUint16 m_memSizeAndFlags;
mutable hkInt16 m_referenceCount;
};
namespace hkArrayUtil {
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray {
public:
__forceinline hkArray();
__forceinline hkArray(T* ptr, int size, int capacity);
public:
__forceinline ~hkArray();
__forceinline T& operator[] (int i);
__forceinline const T& operator[] (int i) const;
__forceinline int getSize() const;
__forceinline int getCapacity() const;
__forceinline void clear();
void removeAt(int index);
__forceinline void pushBack(const T& e);
__forceinline void pushBackUnchecked(const T& e);
__forceinline void reserve(int n);
__forceinline T& expandOne( );
void insertAt(int i, const T* p, int numElems );
void insertAt(int i, const T& t);
typedef T* iterator;
typedef const T* const_iterator;
__forceinline iterator begin();
static void __cdecl copyBackwards(T* dst, const T* src, int n);
public:
enum {
CAPACITY_MASK = int(0x3FFFFFFF),
FLAG_MASK = int(0xC0000000),
DONT_DEALLOCATE_FLAG = int(0x80000000),
LOCKED_FLAG = int(0x40000000),
FORCE_SIGNED = -1
};
protected:
void releaseMemory();
T* m_data;
int m_size;
int m_capacityAndFlags;
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T> {
public:
typedef hkInplaceArray<T,N> mytype;
__forceinline hkInplaceArray(int size = 0);
__forceinline ~hkInplaceArray(){}
public:
T m_storage[N];
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i) {
;
return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const {
return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const {
return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void hkArray<T>::clear() {
m_size = 0;
}
template <typename T>
__forceinline void __cdecl hkArray<T>::copyBackwards(T* dst, const T* src, int n) {
for(int i = n-1; i >= 0; --i) {
dst[i] = src[i];
}
}
template <typename T>
__forceinline hkArray<T>::hkArray()
: m_data(0),
m_size(0),
m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory() {
if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
}
}
template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
: m_data(ptr),
m_size(size),
m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG) {
}
template <typename T>
__forceinline hkArray<T>::~hkArray() {
releaseMemory();
}
template <typename T>
__forceinline void hkArray<T>::removeAt(int i) {
;
m_size--;
m_data[i] = m_data[m_size];
}
template <typename T>
__forceinline void hkArray<T>::reserve(int n) {
const int capacity = getCapacity();
if( capacity < n) {
int cap2 = 2 * capacity;
int newSize = (n < cap2) ? cap2 : n;
hkArrayUtil::_reserve(this, newSize, sizeof(T));
}
}
template <typename T>
__forceinline void hkArray<T>::pushBackUnchecked(const T& t) {
;
m_data[m_size++] = t;
}
template <typename T>
void hkArray<T>::insertAt(int index, const T* p, int numtoinsert) {
;
const int newsize = numtoinsert + m_size;
const int numtomove = m_size - index;
if(newsize > getCapacity()) {
reserve(newsize);
}
copyBackwards(m_data + index + numtoinsert, m_data + index, numtomove);
copyBackwards(m_data + index, p, numtoinsert);
m_size = newsize;
}
template <typename T>
void hkArray<T>::insertAt(int i, const T& t) {
insertAt(i, &t, 1 );
}
template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
: hkArray<T>(m_storage, size, N) {
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin() {
return m_data;
}
namespace hkSmallArrayUtil {
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray {
public:
typedef T* iterator;
typedef const T* const_iterator;
public:
enum {
CAPACITY_MASK = hkUint16(0x3fff),
FLAG_MASK = hkUint16(0xC000),
DONT_DEALLOCATE_FLAG = hkUint16(0x8000),
LOCKED_FLAG = hkUint16(0x4000),
FORCE_SIGNED = -1
};
protected:
T* m_data;
hkUint16 m_size;
hkUint16 m_capacityAndFlags;
};
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
#pragma pack(push,8)
#pragma pack(push,8)
#pragma pack(pop)
#pragma pack(pop)
#pragma pack(push,8)
#pragma pack(pop)
#pragma pack(push,8)
#pragma pack(pop)
class hkMatrix3;
class hkRotation;
class hkVector4 {
public:
__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
void setRotatedDir(const hkRotation& a, const hkVector4& b);
__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
__forceinline hkReal& operator() (int i);
__forceinline const hkReal& operator() (int i) const;
private:
__declspec(align(16)) hkReal x;
hkReal y;
hkReal z;
hkReal w;
};
class hkQuaternion {
public:
hkVector4 m_vec;
};
class hkMatrix3 {
public:
__forceinline const hkVector4& getColumn(int i) const;
__forceinline const hkReal& operator() (int row, int col) const;
protected:
hkVector4 m_col0;
hkVector4 m_col1;
hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3 {
public:
void set(const hkQuaternion& q);
};
class hkTransform {
public:
__forceinline hkVector4& getTranslation();
__forceinline hkRotation& getRotation();
__forceinline void setRotation(const hkQuaternion& quatRotation);
private:
hkRotation m_rotation;
hkVector4 m_translation;
};
class hkSweptTransform {
public:
hkVector4 m_centerOfMass0;
hkVector4 m_centerOfMass1;
hkQuaternion m_rotation0;
hkQuaternion m_rotation1;
hkVector4 m_centerOfMassLocal;
};
inline hkReal& hkVector4::operator() (int i) {
; ;
return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const {
; ;
return (&x)[i];
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1) {
x = v0.x - v1.x;
y = v0.y - v1.y;
z = v0.z - v1.z;
w = v0.w - v1.w;
}
inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v ) {
hkReal v0 = v(0);
hkReal v1 = v(1);
hkReal v2 = v(2);
hkVector4& t = *this;
t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
t(3) = 0;
}
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v) {
_setMul3(r,v);
}
inline const hkVector4& hkMatrix3::getColumn(int x) const {
return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const {
return getColumn(c)(r);
}
hkVector4& hkTransform::getTranslation() {
return m_translation;
}
hkRotation& hkTransform::getRotation() {
return m_rotation;
}
void hkTransform::setRotation(const hkQuaternion& quatRotation) {
m_rotation.set(quatRotation);
}
void* hkThreadMemory::allocateStack(int nbytesin) {
int actualBytes = (nbytesin+16) & (~((16)-1));
char* p = m_stack.m_current;
char* end = p + actualBytes;
if( end <= m_stack.m_end ) {
m_stack.m_current = end;
return p;
}
else {
return onStackOverflow(actualBytes);
}
}
void hkThreadMemory::deallocateStack(void* p) {
m_stack.m_current = static_cast<char*>(p);
if( p == m_stack.m_base ) {
onStackUnderflow(p);
}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what ) {
hkThreadMemory& mem = hkThreadMemory::getInstance();
return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr) {
hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkAabb {
public:
hkVector4 m_min;
hkVector4 m_max;
};
struct hkAabbUint32;
class hkSphere {
public:
protected:
hkVector4 m_pos;
};
typedef hkUint16 hkContactPointId;
class hkContactPoint {
public:
protected:
hkVector4 m_position;
hkVector4 m_separatingNormal;
};
class hkpCdVertex: public hkVector4 {
public:
};
enum hkpShapeType {
HK_SHAPE_INVALID = 0,
HK_SHAPE_CONVEX,
HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_USER_SPU_COLLECTION_0,
HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_TRANSFORM,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL = -1
};
class hkpCollisionDispatcher;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum { HK_SHAPE_BUFFER_ALIGNMENT = 16, HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape;
class hkpCdBody {
public:
public:
const hkpShape* m_shape;
hkpShapeKey m_shapeKey;
const void* m_motion;
const hkpCdBody* m_parent;
};
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpCollisionQualityInfo;
class hkpConstraintOwner;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput {
public:
hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
hkPadSpu<hkReal> m_tolerance;
hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
struct Aabb32Info {
hkVector4 m_bitOffsetLow;
hkVector4 m_bitOffsetHigh;
hkVector4 m_bitScale;
};
Aabb32Info m_aabb32Info;
};
class hkpBroadPhaseHandle {
public:
hkUint32 m_id;
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle {
public:
protected:
enum { OFFSET_INVALID = 127 };
hkInt8 m_type;
hkInt8 m_ownerOffset;
public:
hkUint16 m_objectQualityType;
hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody {
public:
struct BoundingVolumeData {
public:
hkUint32 m_min[3];
hkUint8 m_expansionMin[3];
hkUint8 m_expansionShift;
hkUint32 m_max[3];
hkUint8 m_expansionMax[3];
hkUint8 m_padding;
hkUint16 m_numChildShapeAabbs;
hkAabbUint32* m_childShapeAabbs;
};
enum ForceCollideOntoPpuReasons {
FORCE_PPU_USER_REQUEST = 1,
FORCE_PPU_SHAPE_REQUEST = 2,
FORCE_PPU_MODIFIER_REQUEST = 4,
};
protected:
hkInt8 m_ownerOffset;
public:
hkUint8 m_forceCollideOntoPpu;
hkUint16 m_shapeSizeOnSpu;
class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
public:
struct BoundingVolumeData m_boundingVolumeData;
hkReal m_allowedPenetrationDepth;
};
struct hkpProcessCollisionData;
class hkpGskCache;
class hkpSolverResults {
public:
hkReal m_impulseApplied;
hkReal m_internalSolverData;
};
class hkContactPointMaterial {
public:
protected:
hkUlong m_userData;
hkUFloat8 m_friction;
hkUint8 m_restitution;
public:
hkUFloat8 m_maxImpulse;
public:
enum FlagEnum {
CONTACT_IS_NEW_AND_POTENTIAL = 1,
CONTACT_USES_SOLVER_PATH2 = 2,
CONTACT_BREAKOFF_OBJECT_ID = 4,
};
hkUint8 m_flags;
};
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial {
public:
hkReal m_internalDataA;
typedef hkUint32 UserData;
};
class hkpContactPointPropertiesStream {
public:
__forceinline hkpContactPointProperties* asProperties() ;
};
class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
class hkpSimpleContactConstraintDataInfo {
public:
enum { HK_FLAG_OK = 0x00, HK_FLAG_POINT_REMOVED = 0x01, HK_FLAG_AREA_CHANGED = 0x04 };
__declspec(align(16)) hkUint16 m_flags;
hkUint16 m_index;
hkUint32 m_data[7];
};
struct hkpSolverInfo {
enum DeactivationClass {
DEACTIVATION_CLASS_INVALID,
DEACTIVATION_CLASS_OFF,
DEACTIVATION_CLASS_LOW,
DEACTIVATION_CLASS_MEDIUM,
DEACTIVATION_CLASS_HIGH,
DEACTIVATION_CLASS_AGGRESSIVE,
DEACTIVATION_CLASSES_END
};
struct DeactivationInfo {
float m_linearVelocityThresholdInv;
float m_angularVelocityThresholdInv;
float m_slowObjectVelocityMultiplier;
float m_relativeSleepVelocityThreshold;
float m_maxDistSqrd[2];
hkHalf m_maxRotSqrd[2];
};
__declspec(align(16)) float m_one;
float m_tau;
float m_damping;
float m_frictionTau;
hkVector4 m_globalAccelerationPerSubStep;
hkVector4 m_globalAccelerationPerStep;
hkVector4 m_integrateVelocityFactor;
hkVector4 m_invIntegrateVelocityFactor;
float m_dampDivTau;
float m_tauDivDamp;
float m_dampDivFrictionTau;
float m_frictionTauDivDamp;
float m_contactRestingVelocity;
DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
float m_deltaTime;
float m_invDeltaTime;
int m_numSteps;
int m_numMicroSteps;
float m_invNumMicroSteps;
float m_invNumSteps;
hkBool m_forceCoherentConstraintOrderingInSolver;
hkUint8 m_deactivationNumInactiveFramesSelectFlag[2];
hkUint8 m_deactivationIntegrateCounter;
};
class hkpJacobianSchema;
class hkpVelocityAccumulator;
class hkpConstraintInstance;
struct hkpSolverElemTemp {
union {
hkReal m_impulseApplied;
hkReal m_usedImpulseFactor;
hkReal m_deltaRhs;
};
};
extern "C" {
void __cdecl hkSolveUpload();
void __cdecl hkSolveStepJacobians ( const hkpSolverInfo& i, const hkpJacobianSchema *schemas, hkpVelocityAccumulator* accumulators, hkpSolverElemTemp* tmp );
int __cdecl hkSolveGetToiViolatingConstraintVelocity( hkpSolverInfo& i, const hkpJacobianSchema *schemas, const hkpVelocityAccumulator* accums, int maxNumVelocities, hkReal* velocitiesOut );
}
struct hkpConstraintInfo {
int m_maxSizeOfSchema;
int m_sizeOfSchemas;
int m_numSolverResults;
int m_numSolverElemTemps;
};
typedef void hkpConstraintRuntime;
class hkpConstraintData : public hkReferencedObject {
public:
enum ConstraintType {
CONSTRAINT_TYPE_BALLANDSOCKET = 0,
CONSTRAINT_TYPE_HINGE = 1,
CONSTRAINT_TYPE_LIMITEDHINGE = 2,
CONSTRAINT_TYPE_POINTTOPATH = 3,
CONSTRAINT_TYPE_PRISMATIC = 6,
CONSTRAINT_TYPE_RAGDOLL = 7,
CONSTRAINT_TYPE_STIFFSPRING = 8,
CONSTRAINT_TYPE_WHEEL = 9,
CONSTRAINT_TYPE_GENERIC = 10,
CONSTRAINT_TYPE_CONTACT = 11,
CONSTRAINT_TYPE_BREAKABLE = 12,
CONSTRAINT_TYPE_MALLEABLE = 13,
CONSTRAINT_TYPE_POINTTOPLANE = 14,
CONSTRAINT_TYPE_PULLEY = 15,
CONSTRAINT_TYPE_ROTATIONAL = 16,
CONSTRAINT_TYPE_HINGE_LIMITS = 18,
CONSTRAINT_TYPE_RAGDOLL_LIMITS = 19,
CONSTRAINT_TYPE_CUSTOM = 20,
BEGIN_CONSTRAINT_CHAIN_TYPES = 100,
CONSTRAINT_TYPE_STIFF_SPRING_CHAIN = 100,
CONSTRAINT_TYPE_BALL_SOCKET_CHAIN = 101,
CONSTRAINT_TYPE_POWERED_CHAIN = 102
};
inline virtual ~hkpConstraintData();
virtual hkBool isValid() const = 0;
virtual int getType() const = 0;
struct RuntimeInfo {
int m_sizeOfExternalRuntime;
int m_numSolverResults;
};
virtual void getRuntimeInfo( hkBool wantRuntime, RuntimeInfo& infoOut ) const = 0;
virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
virtual void addInstance( hkpConstraintInstance* constraint, hkpConstraintRuntime* runtime, int sizeOfRuntime ) const;
protected:
public:
virtual void buildJacobian( const hkpConstraintQueryIn &in, hkpConstraintQueryOut &out ) { ; }
virtual hkBool isBuildJacobianCallbackRequired() const { return false; }
virtual void buildJacobianCallback( const hkpConstraintQueryIn &in ) { ; }
struct ConstraintInfo : public hkpConstraintInfo {
struct hkpConstraintAtom* m_atoms;
hkUint32 m_sizeOfAllAtoms;
};
virtual void getConstraintInfo( ConstraintInfo& infoOut ) const = 0;
public:
hkUlong m_userData;
};
struct hkpConstraintAtom {
public:
enum AtomType {
TYPE_INVALID = 0,
TYPE_BRIDGE,
TYPE_SET_LOCAL_TRANSFORMS,
TYPE_SET_LOCAL_TRANSLATIONS,
TYPE_SET_LOCAL_ROTATIONS,
TYPE_BALL_SOCKET,
TYPE_STIFF_SPRING,
TYPE_LIN,
TYPE_LIN_SOFT,
TYPE_LIN_LIMIT,
TYPE_LIN_FRICTION,
TYPE_LIN_MOTOR,
TYPE_2D_ANG,
TYPE_ANG,
TYPE_ANG_LIMIT,
TYPE_TWIST_LIMIT,
TYPE_CONE_LIMIT,
TYPE_ANG_FRICTION,
TYPE_ANG_MOTOR,
TYPE_RAGDOLL_MOTOR,
TYPE_PULLEY,
TYPE_OVERWRITE_PIVOT,
TYPE_CONTACT,
TYPE_MODIFIER_SOFT_CONTACT,
TYPE_MODIFIER_MASS_CHANGER,
TYPE_MODIFIER_VISCOUS_SURFACE,
TYPE_MODIFIER_MOVING_SURFACE,
TYPE_MODIFIER_IGNORE_CONSTRAINT,
TYPE_MAX
};
enum CallbackRequest {
CALLBACK_REQUEST_NONE = 0,
CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
CALLBACK_REQUEST_SETUP_CALLBACK = 4
};
public:
hkEnum<AtomType,hkUint16> m_type;
};
struct hkpSimpleContactConstraintAtom : public hkpConstraintAtom {
public:
__forceinline hkContactPoint* getContactPoints() const ;
__forceinline hkpContactPointPropertiesStream* getContactPointPropertiesStream(int i) const;
public:
hkUint16 m_sizeOfAllAtoms;
hkUint16 m_numContactPoints;
hkUint16 m_numReservedContactPoints;
hkUint8 m_numUserDatasForBodyA;
hkUint8 m_numUserDatasForBodyB;
hkUint8 m_contactPointPropertiesStriding;
hkUint16 m_maxNumContactPoints;
__declspec(align(16)) class hkpSimpleContactConstraintDataInfo m_info;
};
class hkpContactMgr: public hkReferencedObject {
public:
enum Type {
TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
TYPE_REPORT_CONTACT_MGR,
TYPE_CONVEX_LIST_CONTACT_MGR,
TYPE_NULL_CONTACT_MGR,
TYPE_USER_CONTACT_MGR,
TYPE_MAX
};
enum ToiAccept {
TOI_ACCEPT = 0,
TOI_REJECT = 1
};
public:
virtual hkContactPointId addContactPointImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp ) = 0;
virtual hkResult reserveContactPointsImpl( int numPoints ) = 0;
virtual void removeContactPointImpl( hkContactPointId cpId, hkpConstraintOwner& constraintOwner ) = 0;
virtual void processContactImpl( const hkpCollidable& a, const hkpCollidable& b, const hkpProcessCollisionInput& input, hkpProcessCollisionData& collisionData ) = 0;
virtual ToiAccept addToiImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& propertiesOut ) = 0;
virtual void removeToiImpl( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties ) = 0;
virtual void cleanup(){}
public:
Type m_type;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable {
public:
struct CollisionEntry {
hkpAgentNnEntry* m_agentEntry;
hkpLinkedCollidable* m_partner;
};
hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck {
public:
enum AccessType {
HK_ACCESS_IGNORE = 0,
HK_ACCESS_RO = 1,
HK_ACCESS_RW = 2,
};
enum ReadMode {
THIS_OBJECT_ONLY,
RECURSIVE
};
public:
enum {
DISABLED = 0xffffffd1,
MARKED_RO = 0xffffffe1,
MARKED_RO_SELF_ONLY = 0xffffffc1,
UNMARKED = 0xfffffff1
};
hkUint32 m_threadId;
hkInt16 m_markCount;
protected:
hkUint16 m_markBitStack;
public:
static class hkCriticalSection* m_criticalSection;
};
class hkpPhantom;
class hkpRigidBody;
namespace hkWorldOperation {
enum Result {
POSTPONED,
DONE
};
}
class hkpWorldObject : public hkReferencedObject {
public:
void calcStatistics( hkStatisticsCollector* collector ) const;
public:
enum BroadPhaseType {
BROAD_PHASE_INVALID,
BROAD_PHASE_ENTITY,
BROAD_PHASE_PHANTOM,
BROAD_PHASE_BORDER,
BROAD_PHASE_MAX_ID
};
protected:
friend class hkpWorld;
virtual class hkMotionState* getMotionState() = 0;
inline virtual ~hkpWorldObject();
protected:
hkpWorld* m_world;
hkUlong m_userData;
protected:
class hkpLinkedCollidable m_collidable;
protected:
class hkMultiThreadCheck m_multiThreadCheck;
const char* m_name;
hkArray<class hkpProperty> m_properties;
};
class hkpMaterial {
public:
enum ResponseType {
RESPONSE_INVALID,
RESPONSE_SIMPLE_CONTACT,
RESPONSE_REPORTING,
RESPONSE_NONE,
RESPONSE_MAX_ID
};
private:
hkEnum<ResponseType,hkInt8> m_responseType;
hkReal m_friction;
hkReal m_restitution;
};
class hkpEntity;
class hkpConstraintInstance : public hkReferencedObject {
public:
enum ConstraintPriority {
PRIORITY_INVALID,
PRIORITY_PSI,
PRIORITY_TOI,
PRIORITY_TOI_HIGHER,
PRIORITY_TOI_FORCED,
};
enum InstanceType {
TYPE_NORMAL,
TYPE_CHAIN
};
enum AddReferences {
DO_NOT_ADD_REFERENCES,
DO_ADD_REFERENCES
};
enum CloningMode {
CLONE_INSTANCES_ONLY,
CLONE_DATAS_WITH_MOTORS
};
~hkpConstraintInstance();
public:
inline hkpConstraintData* getData() const;
inline ConstraintPriority getPriority() const;
public:
inline struct hkConstraintInternal* getInternal();
virtual InstanceType getType() const { return TYPE_NORMAL; }
protected:
friend class hkpSimulationIsland;
class hkpConstraintOwner* m_owner;
class hkpConstraintData* m_data;
struct hkpModifierConstraintAtom* m_constraintModifiers;
class hkpEntity* m_entities[2];
public:
hkEnum<ConstraintPriority,hkUint8> m_priority;
protected:
hkBool m_wantRuntime;
const char* m_name;
public:
hkUlong m_userData;
struct hkConstraintInternal* m_internal;
private:
};
__declspec(align(16)) struct hkConstraintInternal {
public:
class hkpConstraintInstance* m_constraint;
class hkpEntity* m_entities[2];
protected:
struct hkpConstraintAtom* m_atoms;
hkUint16 m_atomsSize;
public:
hkUint8 m_callbackRequest;
hkEnum<hkpConstraintInstance::ConstraintPriority,hkUint8> m_priority;
hkUint16 m_sizeOfSchemas;
hkUint16 m_numSolverResults;
hkUint16 m_numSolverElemTemps;
hkUint8 m_whoIsMaster;
hkBool m_isNormalType;
hkpConstraintRuntime* m_runtime;
hkUint16 m_runtimeSize;
hkObjectIndex m_slaveIndex;
};
class hkMotionState {
public:
inline hkTransform& getTransform();
inline hkSweptTransform& getSweptTransform();
protected:
hkTransform m_transform;
class hkSweptTransform m_sweptTransform;
public:
hkVector4 m_deltaAngle;
hkReal m_objectRadius;
hkReal m_linearDamping;
hkReal m_angularDamping;
hkUFloat8 m_maxLinearVelocity;
hkUFloat8 m_maxAngularVelocity;
hkUint8 m_deactivationClass;
};
hkTransform& hkMotionState::getTransform() {
return m_transform;
}
hkSweptTransform& hkMotionState::getSweptTransform() {
return m_sweptTransform;
}
class hkpMotion : public hkReferencedObject {
public:
enum MotionType {
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
public:
inline MotionType getType() const { return m_type; }
virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
inline hkMotionState* getMotionState();
inline const hkVector4& getLinearVelocity() const;
inline const hkVector4& getAngularVelocity() const;
virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
virtual void applyAngularImpulse(const hkVector4& imp) = 0;
virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
public:
public:
enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
hkEnum<MotionType, hkUint8> m_type;
hkUint8 m_deactivationIntegrateCounter;
hkUint16 m_deactivationNumInactiveFrames[2];
class hkMotionState m_motionState;
hkVector4 m_inertiaAndMassInv;
hkVector4 m_linearVelocity;
hkVector4 m_angularVelocity;
hkVector4 m_deactivationRefPosition[ 2 ];
hkUint32 m_deactivationRefOrientation[2];
class hkpMaxSizeMotion* m_savedMotion;
hkUint16 m_savedQualityTypeIndex;
};
hkMotionState* hkpMotion::getMotionState() {
return &m_motionState;
}
class hkpKeyframedRigidMotion : public hkpMotion {
public:
virtual ~hkpKeyframedRigidMotion();
virtual void setMass(hkReal m);
virtual void setMassInv(hkReal mInv);
virtual void getInertiaLocal(hkMatrix3& inertia) const;
virtual void setInertiaLocal(const hkMatrix3& inertia);
virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
virtual void applyLinearImpulse(const hkVector4& imp);
virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
virtual void applyAngularImpulse(const hkVector4& imp);
virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
public:
virtual void setStepPosition( hkReal position, hkReal timestep );
virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion {
public:
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject {
public:
enum SpuCollisionCallbackEventFilter {
SPU_SEND_NONE = 0x00,
SPU_SEND_CONTACT_POINT_ADDED = 0x01,
SPU_SEND_CONTACT_POINT_PROCESS = 0x02,
SPU_SEND_CONTACT_POINT_REMOVED = 0x04,
SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
};
public:
inline hkBool isFixed() const;
inline hkBool isFixedOrKeyframed() const;
void calcStatistics( hkStatisticsCollector* collector) const;
public:
inline hkpMotion* getMotion();
inline hkpSimulationIsland* getSimulationIsland() const;
virtual hkMotionState* getMotionState(){ return 0; }
protected:
class hkpMaterial m_material;
protected:
public:
class SmallArraySerializeOverrideType {
public:
void* m_data;
hkUint16 m_size;
hkUint16 m_capacityAndFlags;
};
public: void* m_breakOffPartsUtil;
public: hkUint32 m_solverData;
public: hkObjectIndex m_storageIndex;
protected: hkUint16 m_processContactCallbackDelay;
protected: hkSmallArray<struct hkConstraintInternal> m_constraintsMaster;
protected: hkArray<hkpConstraintInstance*> m_constraintsSlave;
protected:
hkArray<hkUint8> m_constraintRuntime;
hkpSimulationIsland* m_simulationIsland;
public:
hkInt8 m_autoRemoveLevel;
hkUint8 m_numUserDatasInContactPointProperties;
hkUint32 m_uid;
public:
struct SpuCollisionCallback {
public:
hkSpuCollisionCallbackUtil* m_util;
hkUint16 m_capacity;
hkUint8 m_eventFilter;
hkUint8 m_userFilter;
};
struct ExtendedListeners {
hkSmallArray<hkpEntityActivationListener*> m_activationListeners;
hkSmallArray<hkpEntityListener*> m_entityListeners;
};
public:
struct SpuCollisionCallback m_spuCollisionCallback;
protected: mutable ExtendedListeners* m_extendedListeners;
public: class hkpMaxSizeMotion m_motion;
protected:
hkSmallArray<hkpCollisionListener*> m_collisionListeners;
hkSmallArray<hkpAction*> m_actions;
};
inline hkpMotion* hkpEntity::getMotion() {
return &m_motion;
}
inline hkpSimulationIsland* hkpEntity::getSimulationIsland() const {
return m_simulationIsland;
}
inline hkBool hkpEntity::isFixed() const {
return m_motion.m_type == hkpMotion::MOTION_FIXED;
}
template <typename T>
class hkLocalArray : public hkArray<T> {
public:
__forceinline hkLocalArray( int capacity ) {
this->m_data = hkAllocateStack<T>(capacity);
this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
m_localMemory = this->m_data;
}
__forceinline ~hkLocalArray() {
hkDeallocateStack<T>( m_localMemory );
}
T* m_localMemory;
};
template <typename T>
class hkFixedArray {
public:
__forceinline T& operator[] (int i);
protected:
hkPadSpu<T*> m_data;
int m_debugSize;
};
template <typename T>
__forceinline T& hkFixedArray<T>::operator[] (int i) {
;
return m_data[i];
}
class hkStepInfo {
public:
__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
hkPadSpu<hkTime> m_endTime;
hkPadSpu<hkReal> m_deltaTime;
hkPadSpu<hkReal> m_invDeltaTime;
};
namespace hkSweptTransformUtil {
void __cdecl lerp2( const hkSweptTransform& sweptTrans, hkTime time, hkTransform& transformOut );
__forceinline void __cdecl calcTransAtT1( const hkSweptTransform& sweptTrans, hkTransform& transformOut );
__forceinline void __cdecl getVelocity( const hkMotionState& ms, hkVector4& linearVelOut, hkVector4& angularVelOut );
void __cdecl backStepMotionState( hkTime t, hkMotionState& motionState );
}
void __cdecl hkSweptTransformUtil::calcTransAtT1( const hkSweptTransform& sweptTrans, hkTransform& transformOut ) {
const hkQuaternion& qt = sweptTrans.m_rotation1;
transformOut.setRotation( qt );
hkVector4 centerShift;
centerShift._setRotatedDir( transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
transformOut.getTranslation().setSub4( sweptTrans.m_centerOfMass1, centerShift );
}
class hkpWorldCinfo : public hkReferencedObject {
public:
enum SolverType {
SOLVER_TYPE_INVALID,
SOLVER_TYPE_2ITERS_SOFT,
SOLVER_TYPE_2ITERS_MEDIUM,
SOLVER_TYPE_2ITERS_HARD,
SOLVER_TYPE_4ITERS_SOFT,
SOLVER_TYPE_4ITERS_MEDIUM,
SOLVER_TYPE_4ITERS_HARD,
SOLVER_TYPE_8ITERS_SOFT,
SOLVER_TYPE_8ITERS_MEDIUM,
SOLVER_TYPE_8ITERS_HARD,
SOLVER_TYPE_MAX_ID
};
enum SimulationType {
SIMULATION_TYPE_INVALID,
SIMULATION_TYPE_DISCRETE,
SIMULATION_TYPE_CONTINUOUS,
SIMULATION_TYPE_MULTITHREADED,
};
enum ContactPointGeneration {
CONTACT_POINT_ACCEPT_ALWAYS,
CONTACT_POINT_REJECT_DUBIOUS,
CONTACT_POINT_REJECT_MANY,
};
enum BroadPhaseBorderBehaviour {
BROADPHASE_BORDER_ASSERT,
BROADPHASE_BORDER_FIX_ENTITY,
BROADPHASE_BORDER_REMOVE_ENTITY,
BROADPHASE_BORDER_DO_NOTHING,
};
public:
hkVector4 m_gravity;
hkInt32 m_broadPhaseQuerySize;
hkReal m_contactRestingVelocity;
hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
class hkAabb m_broadPhaseWorldAabb;
hkReal m_collisionTolerance;
class hkpCollisionFilter* m_collisionFilter;
class hkpConvexListFilter* m_convexListFilter;
hkReal m_expectedMaxLinearVelocity;
int m_sizeOfToiEventQueue;
hkReal m_expectedMinPsiDeltaTime;
class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
hkInt32 m_broadPhaseNumMarkers;
hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
hkReal m_solverTau;
hkReal m_solverDamp;
hkInt32 m_solverIterations;
hkInt32 m_solverMicrosteps;
hkBool m_forceCoherentConstraintOrderingInSolver;
hkReal m_snapCollisionToConvexEdgeThreshold;
hkReal m_snapCollisionToConcaveEdgeThreshold;
hkBool m_enableToiWeldRejection;
hkBool m_enableDeprecatedWelding;
hkReal m_iterativeLinearCastEarlyOutDistance;
hkInt32 m_iterativeLinearCastMaxIterations;
hkReal m_highFrequencyDeactivationPeriod;
hkReal m_lowFrequencyDeactivationPeriod;
hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
hkUint8 m_deactivationIntegrateCounter;
hkBool m_shouldActivateOnRigidBodyTransformChange;
hkReal m_deactivationReferenceDistance;
hkReal m_toiCollisionResponseRotateNormal;
int m_maxSectorsPerCollideTask;
hkBool m_processToisMultithreaded;
int m_maxEntriesPerToiCollideTask;
hkBool m_enableDeactivation;
hkEnum<SimulationType, hkInt8> m_simulationType;
hkBool m_enableSimulationIslands;
hkUint32 m_minDesiredIslandSize;
hkBool m_processActionsInSingleThread;
hkReal m_frameMarkerPsiSnap;
virtual ~hkpWorldCinfo() {}
};
class hkpTypedBroadPhaseDispatcher;
class hkpBroadPhase;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpActionListener;
class hkpConstraintListener;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;
struct hkpWorldDynamicsStepInfo {
hkStepInfo m_stepInfo;
hkpSolverInfo m_solverInfo;
};
class hkpWorld : public hkReferencedObject {
public:
enum ReintegrationRecollideMode {
RR_MODE_REINTEGRATE = 1,
RR_MODE_RECOLLIDE_BROADPHASE = 2,
RR_MODE_RECOLLIDE_NARROWPHASE = 4,
RR_MODE_ALL = 7
};
void calcStatistics( hkStatisticsCollector* collector ) const;
enum MtAccessChecking {
MT_ACCESS_CHECKING_ENABLED = 0,
MT_ACCESS_CHECKING_DISABLED
};
inline hkpProcessCollisionInput* getCollisionInput();
hkTime getCurrentPsiTime() const;
~hkpWorld();
public:
hkpSimulation* m_simulation;
hkVector4 m_gravity;
hkpSimulationIsland* m_fixedIsland;
hkpRigidBody* m_fixedRigidBody;
hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
hkpWorldMaintenanceMgr* m_maintenanceMgr;
hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
hkpBroadPhase* m_broadPhase;
hkpTypedBroadPhaseDispatcher* m_broadPhaseDispatcher;
hkpPhantomBroadPhaseListener* m_phantomBroadPhaseListener;
hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
hkpProcessCollisionInput* m_collisionInput;
hkpCollisionFilter* m_collisionFilter;
hkpCollisionDispatcher* m_collisionDispatcher;
hkpConvexListFilter* m_convexListFilter;
hkpWorldOperationQueue* m_pendingOperations;
int m_pendingOperationsCount;
int m_criticalOperationsLockCount;
int m_criticalOperationsLockCountForPhantoms;
hkBool m_blockExecutingPendingOperations;
hkBool m_criticalOperationsAllowed;
hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
int m_pendingOperationQueueCount;
mutable class hkMultiThreadCheck m_multiThreadCheck;
hkBool m_processActionsInSingleThread;
hkUint32 m_minDesiredIslandSize;
class hkCriticalSection* m_modifyConstraintCriticalSection;
class hkCriticalSection* m_worldLock;
class hkCriticalSection* m_islandDirtyListCriticalSection;
struct PropertyLock {
hkUint32 m_key;
mutable hkMultiThreadCheck m_multiThreadCheck;
};
class hkCriticalSection* m_propertyMasterLock;
hkBool m_wantSimulationIslands;
hkReal m_snapCollisionToConvexEdgeThreshold;
hkReal m_snapCollisionToConcaveEdgeThreshold;
hkBool m_enableToiWeldRejection;
hkBool m_wantDeactivation;
hkBool m_shouldActivateOnRigidBodyTransformChange;
hkReal m_deactivationReferenceDistance;
hkReal m_toiCollisionResponseRotateNormal;
hkBool m_processToisMultithreaded;
int m_maxSectorsPerCollideTask;
int m_maxEntriesPerToiCollideTask;
hkEnum<hkpWorldCinfo::SimulationType,hkInt32> m_simulationType;
static hkBool m_forceMultithreadedSimulation;
class IgnoreForceMultithreadedSimulation {
public:
hkBool m_originalForceMultithreadedSimulationValue;
};
protected:
hkUint32 m_lastEntityUid;
public:
hkArray<hkpPhantom*> m_phantoms;
hkArray<hkpActionListener*> m_actionListeners;
hkArray<hkpEntityListener*> m_entityListeners;
hkArray<hkpPhantomListener*> m_phantomListeners;
hkArray<hkpConstraintListener*> m_constraintListeners;
hkArray<hkpWorldDeletionListener*> m_worldDeletionListeners;
hkArray<hkpIslandActivationListener*> m_islandActivationListeners;
hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
hkArray<hkpWorldPostIntegrateListener*> m_worldPostIntegrateListeners;
hkArray<hkpWorldPostCollideListener*> m_worldPostCollideListeners;
hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
hkArray<hkpIslandPostCollideListener*> m_islandPostCollideListeners;
hkArray<hkpCollisionListener*> m_collisionListeners;
hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
class hkpBroadPhaseBorder* m_broadPhaseBorder;
public:
struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
hkVector4 m_broadPhaseExtents[2];
int m_broadPhaseNumMarkers;
int m_sizeOfToiEventQueue;
hkInt32 m_broadPhaseQuerySize;
hkInt32 m_broadPhaseUpdateSize;
hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
};
inline hkpProcessCollisionInput* hkpWorld::getCollisionInput() {
;
return m_collisionInput;
}
class hkpRigidBody : public hkpEntity {
public:
hkWorldOperation::Result setShape(const hkpShape* shape);
virtual hkpRigidBody* clone() const;
public:
inline hkpMotion* getRigidMotion() const;
protected:
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const {
return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
class hkpVelocityAccumulator {
public:
enum hkpAccumulatorType {
HK_RIGID_BODY,
HK_KEYFRAMED_RIGID_BODY,
HK_NO_GRAVITY_RIGID_BODY,
HK_END
};
hkEnum<hkpAccumulatorType,hkUint8> m_type;
hkBool m_matrixIsIdentity;
hkUint32 m_deactivationClass;
hkVector4 m_linearVel;
hkVector4 m_angularVel;
hkVector4 m_invMasses;
hkRotation& getCoreFromWorldMatrix() ;
public:
hkVector4 m_scratch0;
hkVector4 m_scratch1;
hkVector4 m_scratch2;
hkVector4 m_scratch3;
};
class hkpConstraintOwner: public hkReferencedObject {
public:
virtual void addConstraintToCriticalLockedIsland( hkpConstraintInstance* constraint ){}
virtual void removeConstraintFromCriticalLockedIsland( hkpConstraintInstance* constraint ){}
virtual void addCallbackRequest( hkpConstraintInstance* constraint, int request ){}
virtual void checkAccessRw() {}
public:
hkpConstraintInfo m_constraintInfo;
};
struct hkpAgentNnSector {
hkUint8 m_data[ 512 ];
};
struct hkpAgentNnTrack {
hkUint32 m_bytesUsedInLastSector;
hkInplaceArray<hkpAgentNnSector*,1> m_sectors;
};
class hkpSimulationIsland : public hkpConstraintOwner {
public:
inline const hkArray<hkpEntity*>& getEntities() const;
void calcStatistics( hkStatisticsCollector* collector) const;
protected:
~hkpSimulationIsland();
public:
hkpWorld* m_world;
int m_numConstraints;
hkObjectIndex m_storageIndex;
hkObjectIndex m_dirtyListIndex;
hkUchar m_splitCheckFrameCounter;
bool m_splitCheckRequested:2;
bool m_sparseEnabled:2;
bool m_actionListCleanupNeeded:2;
bool m_allowIslandLocking:2;
bool m_isInActiveIslandsArray:2;
bool m_activeMark:2;
bool m_inIntegrateJob:2;
protected:
mutable hkMultiThreadCheck m_multiThreadCheck;
public:
hkReal m_timeSinceLastHighFrequencyCheck;
hkReal m_timeSinceLastLowFrequencyCheck;
hkArray<hkpAction*> m_actions;
hkTime m_timeOfDeactivation;
hkInplaceArray<hkpEntity*,1> m_entities;
hkpAgentNnTrack m_agentTrack;
;
};
inline const hkArray<hkpEntity*>& hkpSimulationIsland::getEntities() const {
return m_entities;
}
class hkpDynamicsContactMgr: public hkpContactMgr {
public:
virtual hkpContactPointProperties* getContactPointProperties( hkContactPointId id ){ return 0;}
virtual hkContactPoint* getContactPoint( hkContactPointId id ){ return 0;}
virtual void getAllContactPointIds( hkArray<hkContactPointId>& contactPointIds ) const {}
virtual Type getType() const = 0;
virtual void toiCollisionResponseBeginCallback( const hkContactPoint& cp, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB){}
virtual void toiCollisionResponseEndCallback( const hkContactPoint& cp, hkReal impulseApplied, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB){}
virtual class hkpConstraintInstance* getConstraintInstance() { return 0; }
virtual void confirmToi( struct hkpToiEvent& event, hkReal rotateNormal, class hkArray<class hkpEntity*>& outToBeActivated ){}
protected:
class hkpWorld* m_world;
};
class hkpWorldAgentUtil {
public:
static void __cdecl invalidateTim( hkpEntity* entity, hkpCollisionInput& collisionInput );
};
struct hkpProcessCollisionInput : public hkpCollisionInput {
public:
hkStepInfo m_stepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
void* m_dynamicsInfo;
bool m_enableDeprecatedWelding;
hkpCollisionAgentConfig* m_config;
};
namespace hkAlgorithm {
template<typename T>
__forceinline void __cdecl swap(T& x, T& y) {
T t(x);
x = y;
y = t;
}
}
class hkpDynamicsCpIdMgr {
public:
enum { HK_MAX_IDS_PER_OBJECT = 8 };
enum { FREE_VALUE = 0xff };
typedef hkUchar hkpValueType;
public:
hkInplaceArray<hkpValueType,HK_MAX_IDS_PER_OBJECT> m_values;
};
class hkpSimpleContactConstraintData: public hkpConstraintData {
public:
inline ~hkpSimpleContactConstraintData();
virtual hkBool isValid() const;
virtual void getConstraintInfo( hkpConstraintData::ConstraintInfo& infoOut ) const;
virtual void getRuntimeInfo( hkBool wantRuntime, hkpConstraintData::RuntimeInfo& infoOut ) const;
virtual int getType() const;
public:
hkpDynamicsCpIdMgr m_idMgrA;
void* m_clientData;
hkpConstraintInstance* m_constraint;
hkpSimpleContactConstraintAtom* m_atom;
int m_atomSize;
};
struct hkpToiResources {
hkpConstraintInstance::ConstraintPriority m_minPriorityToProcess;
int m_maxNumEntities;
int m_maxNumActiveEntities;
int m_maxNumConstraints;
int m_numToiSolverIterations;
int m_numForcedToiFinalSolverIterations;
char* m_scratchpad;
int m_scratchpadSize;
};
struct hkpToiEvent {
hkTime m_time;
hkpEntity* m_entities[2];
hkReal m_seperatingVelocity;
hkpDynamicsContactMgr* m_contactMgr;
hkContactPoint m_contactPoint;
hkpContactPointProperties m_properties;
hkUint32 m_extendedUserDatas[7];
};
enum hkpToiResourceMgrResponse {
HK_TOI_RESOURCE_MGR_RESPONSE_DO_NOT_BACKSTEP = 0,
HK_TOI_RESOURCE_MGR_RESPONSE_CONTINUE = 1,
HK_TOI_RESOURCE_MGR_RESPONSE_BACKSTEP = 2
};
class hkpToiResourceMgr : public hkReferencedObject {
public:
struct ConstraintViolationInfo {
hkpConstraintInstance* m_constraint;
hkContactPoint* m_contactPoint;
hkpContactPointProperties* m_contactPointProperties;
};
virtual ~hkpToiResourceMgr() {}
virtual hkResult beginToiAndSetupResources( const hkpToiEvent& event, const hkArray<hkpToiEvent>& otherEvents, hkpToiResources& resourcesOut ) = 0;
virtual hkpToiResourceMgrResponse cannotSolve( hkArray<ConstraintViolationInfo>& violatedConstraints );
virtual hkpToiResourceMgrResponse resourcesDepleted();
virtual void endToiAndFreeResources( const hkpToiEvent& event, const hkArray<hkpToiEvent>& otherEvents, const hkpToiResources& resources ) = 0;
};
struct hkpConstraintSolverResources {
struct VelocityAccumTransformBackup {
hkVector4 m_linear;
hkVector4 m_angular;
};
template <typename T>
struct BufferState {
T* m_begin;
T* m_end;
T* m_current;
T* m_lastProcessed;
};
hkStepInfo* m_stepInfo;
hkpSolverInfo* m_solverInfo;
hkpConstraintQueryIn* m_constraintQueryInput;
hkpVelocityAccumulator* m_accumulators;
hkpVelocityAccumulator* m_accumulatorsEnd;
hkpVelocityAccumulator* m_accumulatorsCurrent;
VelocityAccumTransformBackup* m_accumulatorsBackup;
VelocityAccumTransformBackup* m_accumulatorsBackupEnd;
BufferState<hkpJacobianSchema> m_schemas[2];
hkpSolverElemTemp* m_elemTemp;
hkpSolverElemTemp* m_elemTempEnd;
hkpSolverElemTemp* m_elemTempCurrent;
hkpSolverElemTemp* m_elemTempLastProcessed;
};
struct hkpConstraintSchemaInfo {
hkpConstraintInstance* m_constraint;
hkpJacobianSchema* m_schema;
hkReal m_allowedPenetrationDepth;
};
class hkpConstraintSolverSetup {
public:
enum SolverMode {
SOLVER_MODE_PROCESS_ALL,
SOLVER_MODE_INCREMENTAL_CONTINUE
};
static void __cdecl internalAddAccumulators( hkpConstraintSolverResources& resources, hkpEntity* const* entities, int numEntities );
static void __cdecl internalAddJacobianSchemas( hkpConstraintSolverResources& resources, hkpConstraintInstance** constraints, int numConstraints, hkArray<hkpConstraintSchemaInfo>& constraintStatusOut );
static hkBool __cdecl internalIsMemoryOkForNewAccumulators( hkpConstraintSolverResources& resources, hkpEntity** entities, int numEntities );
static hkBool __cdecl internalIsMemoryOkForNewJacobianSchemas( hkpConstraintSolverResources& resources, hkpConstraintInstance** constraints, int numConstraints );
static void __cdecl subSolve( hkpConstraintSolverResources& resources, SolverMode mode );
static void __cdecl oneStepIntegrate( const hkpSolverInfo& si, const hkStepInfo& info, const hkpVelocityAccumulator* accumulatorsBase, hkpEntity* const* entities, int numEntities );
};
enum hkContinuousSimulationToiEntityState {
HK_TOI_ENTITY_STATE_ZERO = 0,
HK_TOI_ENTITY_STATE_TRANSFORM_UPDATED = 1,
HK_TOI_ENTITY_STATE_MANIFOLD_UPDATED = 2,
HK_TOI_ENTITY_STATE_TOUCHED = 4,
HK_TOI_ENTITY_STATE_PENDING = 8,
HK_TOI_ENTITY_STATE_ACTIVE = 16
};
int __cdecl hkLs_areVelocitiesOk( hkReal deltaTime, const hkpConstraintSchemaInfo& constraintStatus, const hkReal* velocities, int numVelocities, const hkpProcessCollisionInput& processInput );
void __cdecl hkLs_toiCheckValidityOfConstraints( hkpConstraintSolverResources& solverResources, hkpProcessCollisionInput& processInput, hkArray<hkpConstraintSchemaInfo>& constraintStatus, int& firstNonActiveConstraintStatus, hkpConstraintInstance::ConstraintPriority minPriorityToProcess, hkFixedArray<hkUchar>& entityState, const hkArray<hkpEntity*>& touchedEntities, hkArray<hkpEntity*>& toBeActivated ) {
	hkVector4* origVelStack = hkAllocateStack<hkVector4>( 2 * touchedEntities.getSize() ); {
		hkVector4* origVel = origVelStack;
		for ( int i = 0; i < touchedEntities.getSize(); i++ ) {
			hkpEntity* entity = touchedEntities[i];
			hkpVelocityAccumulator* accumulator = hkAddByteOffset( solverResources.m_accumulators, entity->m_solverData );
			hkpMotion* motion = entity->getMotion();
			*(origVel++) = accumulator->m_linearVel;
			*(origVel++) = accumulator->m_angularVel;
			hkSweptTransformUtil::getVelocity( *motion->getMotionState(), accumulator->m_linearVel, accumulator->m_angularVel );
		}
	}
	for ( int i = firstNonActiveConstraintStatus; i < constraintStatus.getSize(); i++ ) {
		hkpConstraintSchemaInfo& cStatus = constraintStatus[i];
		if ( cStatus.m_constraint->getPriority() < minPriorityToProcess ) {
			continue;
		} {
			hkpEntity** e = cStatus.m_constraint->getInternal()->m_entities;
			int tmpIdx = entityState[ e[0]->m_storageIndex ] == HK_TOI_ENTITY_STATE_ACTIVE;
			hkpEntity* entity = e[tmpIdx];
			if ( entityState[ entity->m_storageIndex ] == HK_TOI_ENTITY_STATE_PENDING ) {
				hkAlgorithm::swap( constraintStatus[ firstNonActiveConstraintStatus++ ], cStatus );
				continue;
			} {
				hkReal velocities[256];
				int numVelocities = hkSolveGetToiViolatingConstraintVelocity( *solverResources.m_solverInfo, cStatus.m_schema, solverResources.m_accumulators, 256, velocities );
				hkBool satisfied = -1 == hkLs_areVelocitiesOk( solverResources.m_stepInfo->m_deltaTime, cStatus, velocities, numVelocities, processInput );
				if ( !satisfied ) {
					entityState[ entity->m_storageIndex ] = HK_TOI_ENTITY_STATE_PENDING;
					toBeActivated.pushBack( entity );
					hkAlgorithm::swap( constraintStatus[ firstNonActiveConstraintStatus++ ], cStatus );
				}
			}
		}
	} {
		hkVector4* origVel = origVelStack;
		for ( int i = 0; i < touchedEntities.getSize(); i++ ) {
			hkpEntity* entity = touchedEntities[i];
			hkpVelocityAccumulator* accumulator = hkAddByteOffset( solverResources.m_accumulators, entity->m_solverData );
			accumulator->m_linearVel = *(origVel++);
			accumulator->m_angularVel = *(origVel++);
		}
	}
	hkDeallocateStack( origVelStack );
}
void __cdecl hkLs_toiActivateEntitiesAndCheckConstraints( hkpProcessCollisionInput& processInput, hkpConstraintInstance::ConstraintPriority minPriorityToProcess, hkReal time, const hkArray<hkpEntity*>& toBeActivated, hkFixedArray<hkUchar>& entityState, hkArray<hkpEntity*>& moreTouchedEntities, hkArray<hkpConstraintInstance*>& moreConstraints );
hkBool __cdecl hkLs_toiCheckFinalValidityOfCriticalConstraints( hkpConstraintSolverResources& solverResources, const hkArray<hkpConstraintSchemaInfo>& constraintStatus, hkpProcessCollisionInput& processInput, hkArray<hkpToiResourceMgr::ConstraintViolationInfo>* violatedConstraints ) {
	hkBool areOk = true;
	for ( int i = 0; i < constraintStatus.getSize(); i++ ) {
		const hkpConstraintSchemaInfo& cStatus = constraintStatus[i];
		if ( cStatus.m_constraint->getPriority() != hkpConstraintInstance::PRIORITY_TOI_FORCED ) {
			continue;
		}
		hkReal velocities[256];
		int numVelocities = hkSolveGetToiViolatingConstraintVelocity( *solverResources.m_solverInfo, cStatus.m_schema, solverResources.m_accumulators, 256, velocities );
		int failingIndex = hkLs_areVelocitiesOk( solverResources.m_stepInfo->m_deltaTime, cStatus, velocities, numVelocities, processInput );
		if ( failingIndex >= 0 ) {
			if ( !violatedConstraints ) {
				return false;
			}
			areOk = false;
			hkpToiResourceMgr::ConstraintViolationInfo& info = violatedConstraints->expandOne();
			info.m_constraint = cStatus.m_constraint;
			if ( cStatus.m_constraint->getData()->getType() == hkpConstraintData::CONSTRAINT_TYPE_CONTACT ) {
				hkpSimpleContactConstraintData* contactData = static_cast<hkpSimpleContactConstraintData*>( cStatus.m_constraint->getData() );
				info.m_contactPoint = &contactData->m_atom->getContactPoints()[failingIndex];
				info.m_contactPointProperties = contactData->m_atom->getContactPointPropertiesStream( failingIndex )->asProperties();
			}
			else {
				info.m_contactPoint = 0;
				info.m_contactPointProperties = 0;
			}
		}
	}
	return areOk;
}
void __cdecl hkLs_toiResetVelocityAccumulatorsForEntities( hkpConstraintSolverResources& solverResources, const hkArray<hkpEntity*>& entities );
void __cdecl hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities( hkArray<hkpConstraintSchemaInfo>& constraintStatus, int& firstNonActiveConstraintStatus, int numOfConstraintsToCheckAtTheEndOfTheList ) {
	for ( int i = constraintStatus.getSize() - numOfConstraintsToCheckAtTheEndOfTheList; i < constraintStatus.getSize(); i++ ) {
		hkpRigidBody** body = reinterpret_cast<hkpRigidBody**>( constraintStatus[i].m_constraint->getInternal()->m_entities );
		if ( body[0]->isFixedOrKeyframed() || body[1]->isFixedOrKeyframed() ) {
			hkAlgorithm::swap( constraintStatus[ firstNonActiveConstraintStatus++ ], constraintStatus[i] );
		}
	}
}
void __cdecl hkLs_toiActivateConstraintsLinkingActivatedEntities( hkArray<hkpConstraintSchemaInfo>& constraintStatus, int& firstNonActiveConstraintStatus, hkFixedArray<hkUchar>& entityState ) {
	for ( int i = firstNonActiveConstraintStatus; i < constraintStatus.getSize(); i++ ) {
		hkpEntity** e = constraintStatus[i].m_constraint->getInternal()->m_entities;
		if ( entityState[ e[0]->m_storageIndex ] == HK_TOI_ENTITY_STATE_ACTIVE && entityState[ e[1]->m_storageIndex ] == HK_TOI_ENTITY_STATE_ACTIVE ) {
			hkAlgorithm::swap( constraintStatus[ firstNonActiveConstraintStatus++ ], constraintStatus[i] );
		}
	}
}
void __cdecl hkLs_backstepAndFreezeEntireIsland( hkTime time, hkpSimulationIsland* island, hkFixedArray<hkUchar>& entityState, hkArray<hkpEntity*>& activeEntities );
void __cdecl hkLs_restoreTransformOnBodiesWithUpdatedTransform( hkpSimulationIsland* island, hkFixedArray<hkUchar>& entityState, hkpVelocityAccumulator* accumulators );
static __forceinline void hkLs_toiSetTransformAtTime( hkpEntity* entity, hkTime time ) {
;
hkMotionState* motionState = entity->getMotion()->getMotionState();
hkSweptTransformUtil::lerp2( motionState->getSweptTransform(), time, motionState->getTransform() );
}
}
struct Limits;
struct Resources;
struct PairEvent;
struct ResourceManager;
struct Scene;
struct DynamicNode;
struct StateTable;
template <class T> class List;
// pdb: hkLs_localizedSolveToi | hkpContinuousSimulation.obj | tesv_win, call_gap_sim, low
int FUN_00d0f300( const Limits& limits, Resources& resources, PairEvent& pairEvent, ResourceManager& manager, Scene* scene, List<DynamicNode*>& active, StateTable& states, float ) {
	using namespace hk550;
	using hk550::hkBool;
	using hk550::hkMotionState;
	const hkpToiResources& toiResources = reinterpret_cast<const hkpToiResources&>( limits );
	hkpConstraintSolverResources& solverResources = reinterpret_cast<hkpConstraintSolverResources&>( resources );
	hkpToiEvent& event = reinterpret_cast<hkpToiEvent&>( pairEvent );
	hkpToiResourceMgr& toiResourceMgr = reinterpret_cast<hkpToiResourceMgr&>( manager );
	hkpWorld* world = reinterpret_cast<hkpWorld*>( scene );
	hkArray<hkpEntity*>& activeEntities = reinterpret_cast<hkArray<hkpEntity*>&>( active );
	hkFixedArray<hkUchar>& entityState = reinterpret_cast<hkFixedArray<hkUchar>&>( states );
	hkInplaceArray<hkpConstraintSchemaInfo, 64> constraintStatus;
	int firstNonActiveConstraintStatus = 0;
	hkpSimulationIsland* island = ( !event.m_entities[0]->isFixed() ) ? event.m_entities[0]->getSimulationIsland() : event.m_entities[1]->getSimulationIsland();
	hkLocalArray<hkpEntity*> touchedEntities( island->getEntities().getSize() );
	if ( !event.m_entities[0]->isFixed() ) {
		touchedEntities.pushBackUnchecked( event.m_entities[0] );
		hkLs_toiSetTransformAtTime( event.m_entities[0], event.m_time );
		entityState[ event.m_entities[0]->m_storageIndex ] = HK_TOI_ENTITY_STATE_MANIFOLD_UPDATED;
	}
	if ( !event.m_entities[1]->isFixed() ) {
		touchedEntities.pushBackUnchecked( event.m_entities[1] );
		hkLs_toiSetTransformAtTime( event.m_entities[1], event.m_time );
		entityState[ event.m_entities[1]->m_storageIndex ] = HK_TOI_ENTITY_STATE_MANIFOLD_UPDATED;
	}
	hkInplaceArray<hkpEntity*, 64> toBeActivated;
	event.m_contactMgr->confirmToi( event, world->m_toiCollisionResponseRotateNormal, toBeActivated );
	if ( !toBeActivated.getSize() ) {
		if ( !event.m_entities[0]->isFixed() ) {
			hkpRigidBody* bodyA = static_cast<hkpRigidBody*>( event.m_entities[0] );
			hkMotionState* motionState = bodyA->getRigidMotion()->getMotionState();
			hkSweptTransformUtil::calcTransAtT1( motionState->getSweptTransform(), motionState->getTransform() );
		}
		if ( !event.m_entities[1]->isFixed() ) {
			hkpRigidBody* bodyB = static_cast<hkpRigidBody*>( event.m_entities[1] );
			hkMotionState* motionState = bodyB->getRigidMotion()->getMotionState();
			hkSweptTransformUtil::calcTransAtT1( motionState->getSweptTransform(), motionState->getTransform() );
		}
		return HK_FAILURE;
	}
	hkpEntity* initialActivatedEntities[2] = { toBeActivated[0], ( toBeActivated.getSize() > 1 ) ? toBeActivated[1] : 0 };
	hkSolveUpload();
	hkpConstraintSolverSetup::internalAddAccumulators( solverResources, touchedEntities.begin(), touchedEntities.getSize() );
	hkBool toBeActivatedArrayIsAlreadyPreSet = true;
	hkInplaceArray<hkpEntity*, 64> moreTouchedEntities;
	hkInplaceArray<hkpConstraintInstance*, 64> moreConstraints; {
		for ( int maxNumFullSteps = toiResources.m_numToiSolverIterations; maxNumFullSteps > 0; maxNumFullSteps-- ) {
			while ( 1 ) {
				moreConstraints.clear();
				moreTouchedEntities.clear();
				int updatedFirstNonActiveConstraintStatus = firstNonActiveConstraintStatus;
				if ( !toBeActivatedArrayIsAlreadyPreSet ) {
					if ( firstNonActiveConstraintStatus < constraintStatus.getSize() ) {
						toBeActivated.clear();
						hkLs_toiCheckValidityOfConstraints( solverResources, *world->m_collisionInput, constraintStatus, updatedFirstNonActiveConstraintStatus, toiResources.m_minPriorityToProcess, entityState, touchedEntities, toBeActivated );
						if ( !toBeActivated.getSize() ) {
							goto RUN_FULL_SOLVER;
						}
					}
					else {
						goto RUN_FULL_SOLVER;
					}
				}
				hkLs_toiActivateEntitiesAndCheckConstraints( *world->getCollisionInput(), toiResources.m_minPriorityToProcess, event.m_time, toBeActivated, entityState, moreTouchedEntities, moreConstraints );
				toBeActivatedArrayIsAlreadyPreSet = false;
				if ( !hkpConstraintSolverSetup::internalIsMemoryOkForNewAccumulators( solverResources, moreTouchedEntities.begin(), moreTouchedEntities.getSize() )
				|| !hkpConstraintSolverSetup::internalIsMemoryOkForNewJacobianSchemas( solverResources, moreConstraints.begin(), moreConstraints.getSize() )
				|| toiResources.m_maxNumConstraints < constraintStatus.getSize() + moreConstraints.getSize()
				|| toiResources.m_maxNumEntities < activeEntities.getSize() + touchedEntities.getSize() + moreTouchedEntities.getSize()
				|| toiResources.m_maxNumActiveEntities < activeEntities.getSize() + toBeActivated.getSize() ) {
					for ( int i = 0; i < toBeActivated.getSize(); i++ ) {
						entityState[ toBeActivated[i]->m_storageIndex ] = HK_TOI_ENTITY_STATE_PENDING;
					}
					for ( int i = 0; i < moreTouchedEntities.getSize(); i++ ) {
						entityState[ moreTouchedEntities[i]->m_storageIndex ] = HK_TOI_ENTITY_STATE_TRANSFORM_UPDATED;
					}
					hkpToiResourceMgrResponse response = toiResourceMgr.resourcesDepleted();
					if ( response == HK_TOI_RESOURCE_MGR_RESPONSE_BACKSTEP ) {
						hkLs_backstepAndFreezeEntireIsland( event.m_time, island, entityState, activeEntities );
						for ( int i = 0; i < activeEntities.getSize(); i++ ) {
							hkpWorldAgentUtil::invalidateTim( activeEntities[i], *world->m_collisionInput );
						}
						activeEntities.clear();
						return HK_SUCCESS;
					}
					goto RUN_FULL_SOLVER;
				}
				else {
					hkpConstraintSolverSetup::internalAddAccumulators( solverResources, moreTouchedEntities.begin(), moreTouchedEntities.getSize() );
					hkpConstraintSolverSetup::internalAddJacobianSchemas( solverResources, moreConstraints.begin(), moreConstraints.getSize(), constraintStatus );
					firstNonActiveConstraintStatus = updatedFirstNonActiveConstraintStatus;
					for ( int i = 0; i < touchedEntities.getSize(); i++ ) {
						if ( entityState[ touchedEntities[i]->m_storageIndex ] == HK_TOI_ENTITY_STATE_ACTIVE ) {
							touchedEntities.removeAt( i-- );
						}
					}
					activeEntities.insertAt( activeEntities.getSize(), toBeActivated.begin(), toBeActivated.getSize() );
					touchedEntities.reserve( touchedEntities.getSize() + moreTouchedEntities.getSize() );
					for ( int i = 0; i < moreTouchedEntities.getSize(); i++ ) {
						if ( moreTouchedEntities[i]->getMotion()->getType() != hkpMotion::MOTION_KEYFRAMED ) {
							touchedEntities.pushBackUnchecked( moreTouchedEntities[i] );
						}
					}
					hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities( constraintStatus, firstNonActiveConstraintStatus, moreConstraints.getSize() );
					hkLs_toiActivateConstraintsLinkingActivatedEntities( constraintStatus, firstNonActiveConstraintStatus, entityState );
					hkpConstraintSolverSetup::subSolve( solverResources, hkpConstraintSolverSetup::SOLVER_MODE_INCREMENTAL_CONTINUE );
				}
				if ( !moreConstraints.getSize() && !moreTouchedEntities.getSize() ) {
					break;
				}
			}
RUN_FULL_SOLVER:
			hkpConstraintSolverSetup::subSolve( solverResources, hkpConstraintSolverSetup::SOLVER_MODE_PROCESS_ALL );
		}
		if ( solverResources.m_schemas[1].m_begin != solverResources.m_schemas[1].m_current ) {
			hkLs_toiResetVelocityAccumulatorsForEntities( solverResources, touchedEntities );
			hkBool forcedConstraintsAreSatisfied = hkLs_toiCheckFinalValidityOfCriticalConstraints( solverResources, constraintStatus, *world->m_collisionInput, 0 );
			if ( !forcedConstraintsAreSatisfied ) {
				int triesLeft = toiResources.m_numForcedToiFinalSolverIterations;
				while ( !forcedConstraintsAreSatisfied && --triesLeft >= 0 ) {
					hkSolveStepJacobians( *solverResources.m_solverInfo, solverResources.m_schemas[1].m_begin, solverResources.m_accumulators, solverResources.m_elemTemp );
					hkLs_toiResetVelocityAccumulatorsForEntities( solverResources, touchedEntities );
					forcedConstraintsAreSatisfied = hkLs_toiCheckFinalValidityOfCriticalConstraints( solverResources, constraintStatus, *world->m_collisionInput, 0 );
				}
			}
			if ( !forcedConstraintsAreSatisfied ) {
				hkInplaceArray<hkpToiResourceMgr::ConstraintViolationInfo, 32> violatedConstraints;
				hkLs_toiCheckFinalValidityOfCriticalConstraints( solverResources, constraintStatus, *world->m_collisionInput, &violatedConstraints );
				hkpToiResourceMgrResponse response = toiResourceMgr.cannotSolve( violatedConstraints );
				if ( response == HK_TOI_RESOURCE_MGR_RESPONSE_BACKSTEP ) {
					hkLs_backstepAndFreezeEntireIsland( event.m_time, island, entityState, activeEntities );
					for ( int i = 0; i < activeEntities.getSize(); i++ ) {
						hkpWorldAgentUtil::invalidateTim( activeEntities[i], *world->m_collisionInput );
					}
					activeEntities.clear();
					return HK_SUCCESS;
				}
			}
		}
		if ( activeEntities.getSize() == 0 ) {
			activeEntities.insertAt( 0, initialActivatedEntities[0] );
			entityState[ activeEntities[0]->m_storageIndex ] = HK_TOI_ENTITY_STATE_ACTIVE;
			if ( initialActivatedEntities[1] ) {
				activeEntities.insertAt( 1, initialActivatedEntities[1] );
				entityState[ activeEntities[1]->m_storageIndex ] = HK_TOI_ENTITY_STATE_ACTIVE;
			}
		}
		for ( int e = 0; e < activeEntities.getSize(); e++ ) {
			hkpEntity& body = *activeEntities[e];
			hkMotionState& motionState = *body.getMotion()->getMotionState();
			hkSweptTransformUtil::backStepMotionState( event.m_time, motionState );
		}
		hkpConstraintSolverSetup::oneStepIntegrate( *solverResources.m_solverInfo, *solverResources.m_stepInfo, solverResources.m_accumulators, activeEntities.begin(), activeEntities.getSize() );
		hkLs_restoreTransformOnBodiesWithUpdatedTransform( island, entityState, solverResources.m_accumulators );
		for ( int i = 0; i < activeEntities.getSize(); i++ ) {
			hkpWorldAgentUtil::invalidateTim( activeEntities[i], *world->m_collisionInput );
		}
	}
	return HK_SUCCESS;
}


namespace fnv_00d0d020 {
// FUN_00d0d020 - node-spawning constructor (thiscall, one Owner* argument).
//
// The class is a stand-in for the game's node-spawner:
//   +0x00 vptr (stored explicitly, NOT a real vptr - see below)
//   +0x10 a byte flag
//   +0x30 a {data, ?, capacity} holder, capacity has the top bit used as a flag
//   +0x3c a second {data, ?, capacity} holder
//   +0x48 the spawned node, +0x4c a counter
// The vtable pointer is modelled as a plain int member: the original stores
// 0x010cd45c with a plain `mov`, and a real vptr would drag in an EH frame
// (the base class has a non-trivial constructor) and a vtable whose bytes the
// checker would compare literally.
struct Allocator {
    virtual void v00();
    virtual void *Alloc(unsigned int bytes);
};

struct AllocHolder {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0c;
    Allocator *m_pThreadAllocator;
};

struct Owner {
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
    int m_334;
};

extern int DAT_010cd45c;

AllocHolder *__cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(Allocator *allocator, void *data, unsigned int capacity, unsigned int elemSize);

}  // namespace fnv_00d0d020

template<class T> class ScanPointer {T p;public:__forceinline ScanPointer(){} __forceinline ScanPointer(T q):p(q){} __forceinline void operator=(T q){p=q;} __forceinline operator T()const{return p;} __forceinline T const& val()const{return p;}};
// Resolve an event and remove obsolete queued events.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern int DAT_01269200;
extern char DAT_01076f38[];
typedef unsigned long DWORD;
struct ProfRec { const char* m_pName; DWORD m_iTick; DWORD unk08;
    __forceinline void stamp() {
        DWORD value;
        __asm {
            rdtsc
            mov dword ptr[value], eax
        }
        m_iTick=value;
    }
};
struct ProfBuf { DWORD unk00; ProfRec* m_pCur; DWORD unk08; ProfRec* m_pRecordEnd; };
struct HeapObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct FlagIndex16 {
    unsigned short value;
    FlagIndex16(unsigned short v) : value(v) {}
    operator unsigned short() const { return value; }
};
struct FlagView {
    unsigned char* volatile data;
    const unsigned char& operator[](const FlagIndex16& index) const {
        return data[index];
    }
};
struct Owner {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    unsigned short m_uiEdgeIndex;
    unsigned short m_aa;
    int m_ac, m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8;
    Island* m_cc;
    __forceinline Island* GetSimulationIsland() const { return m_cc; }
    __forceinline hkBool isFixed() const { return motion.type==5; }
    int m_d0, m_d4, m_d8, m_dc;
    CollisionMotion motion;
    int m_ec;
};
struct EventReleaseObj;
struct Entry70 {
    float time, separatingVelocity;
    int flags;
    Owner* bodies[2];
    EventReleaseObj* m_14;
    CollisionProperties properties;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    hkVector4 position, normal;
};
struct Arr70 {
    Entry70* m_data;
    int m_iElementCount;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline Entry70& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int);
    int unk08; int unk0c; int unk10; int unk14;
    struct PhaseObj* m_phase;
    int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
};
struct PhaseObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int collide(void* a, void* b, void* q);
    virtual void v10();
    virtual void v14();
    virtual void v18(void* a, void* b, void* c);
};
struct CtrObj {
    int unk00; int unk04; int unk08;
    int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90;
    int m_ref94;
    int unk98;
    unsigned char m_9c;
    unsigned char unk9d; unsigned char unk9e; unsigned char unk9f;
    int unkA0;
    int m_a4;
    void FUN_00c91120();
    void FUN_00c91140();
};
struct Arg0 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74;
    void* m_78;
    __forceinline void* getInput() const { return m_78; }
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
    int m_1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int m_1e0;
    float FUN_00c91030();
};
struct Elem {
    int unk00;
    int unk04;
    int m_08;
    void FUN_00c905b0();
};
struct PtrArr {
    Elem** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Elem* m_inline[64];
    __forceinline PtrArr() : m_data(m_inline),m_iElementCount(0),m_iCapacityState(0x80000040) {}
    __forceinline int GetLogicalSize() const {return m_iElementCount;}
    __forceinline Elem** begin() {return m_data;}
    __forceinline Elem*& operator[](int i) {return m_data[i];}
    __forceinline void clear() {m_iElementCount=0;}
    __forceinline void removeAt(int i) {--m_iElementCount;if(m_iElementCount!=i)m_data[i]=m_data[m_iElementCount];}
    __forceinline void dispose() {
        HeapObj* heap=(HeapObj*)FUN_00c85750()->unk10;
        int cap=m_iCapacityState;
        m_iElementCount=0;
        if(cap>=0)heap->ReturnMemory(m_data,(cap&0x3fffffff)*4);
    }
};
struct EventReleaseObj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void call20(Island* a, CollisionProperties* b);
};
struct __declspec(align(16)) Obj2 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; 
    void FUN_00cfa6e0(void* big, float* tA, int v);
};
struct EventQuery {
    int mode;
    int budgetA,budgetB,budgetC;
    int limitA,limitB;
    int flagsA,flagsB;
    __forceinline EventQuery() {
        budgetA=1000;budgetB=1000;budgetC=1000;
        limitA=4;limitB=4;flagsA=0;flagsB=0;mode=3;
    }
};
struct SolverState {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct SolverFlagView {
    unsigned char* data;
    int debugSize;
    __forceinline SolverFlagView() {}
    __forceinline SolverFlagView(unsigned char* p,int) : data(p) {}
    __forceinline unsigned char* begin() { return data; }
    __forceinline unsigned char& operator[](int i) {return data[i];}
    __forceinline const unsigned char& operator[](int i) const {return data[i];}
};
struct ScopedFlags : SolverFlagView {
    __forceinline ScopedFlags(int n) {
        Manager* r=FUN_00c85750();
        unsigned char* p=(unsigned char*)r->unk00;
        r->unk00=(int)p+((n+127)&~127);
        data=p;
    }
    __forceinline void dispose() {FUN_00c85750()->unk00=(int)data;}
};
struct Self;

struct Self {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void notify(Elem**, int, void*, void*);
    int unk04; int unk08;
    CtrObj* m_ctr;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Arr70 m_arr30;
    int pad7c; int pad80; int pad84; int pad88; int pad8c; int pad90; int pad94; int pad98; int pad9c; int pada0; int pada4; int pada8; int padac; int padb0; int padb4; int padb8; int padbc; int padc0; int padc4; int padc8; int padcc; int padd0; int padd4; int padd8; int paddc; int pade0; int pade4; int pade8; int padec; int padf0; int padf4; int padf8; int padfc; int pad100; int pad104; int pad108; int pad10c; int pad110; int pad114; int pad118; int pad11c; int pad120; int pad124; int pad128; int pad12c; int pad130; int pad134; int pad138; int pad13c; int pad140; int pad144; int pad148; int pad14c; int pad150; int pad154; int pad158; int pad15c; int pad160; int pad164; int pad168; int pad16c; int pad170; int pad174; int pad178; int pad17c; int pad180; int pad184; int pad188; int pad18c; int pad190; int pad194; int pad198; int pad19c; int pad1a0; int pad1a4; int pad1a8; int pad1ac; int pad1b0; int pad1b4;
    int m_1b8;
    int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0;
    void FUN_00d0d3f0(Elem** data, int n, Arg0* a0, int z);
    __forceinline void process(Arg0*, Elem**, int, void*);
    __forceinline void release(Entry70&);
    __forceinline void scan(const Island*,const SolverFlagView&,Arr70&);
    void FUN_00d100a0(Arg0* a0, Entry70* pair, float fa, float fb);
};

static __forceinline void copyProbe(void* destination,const void* source) {
    unsigned i=0;
    do { static_cast<__int64*>(destination)[i]=static_cast<const __int64*>(source)[i]; } while(++i<14);
}
__forceinline void Arr70::removeAt(int index) {
    --m_iElementCount;
    if(m_iElementCount!=index)copyProbe(m_data+index,m_data+m_iElementCount);
}
__forceinline void Self::release(Entry70& event) {
    Island* island=!event.bodies[0]->isFixed()?event.bodies[0]->GetSimulationIsland():event.bodies[1]->GetSimulationIsland();
    event.m_14->call20(island,&event.properties);
}
__forceinline void Self::process(Arg0* world,Elem** data,int count,void* input) {
    if(count) {
        FUN_00d0d3f0(data,count,world,0);
        if(DAT_01269200!=1)notify(data,count,input,&m_arr30.unk0c);
    }
}
int __cdecl FUN_00d0f300(const EventQuery&,SolverState&,Entry70&,PhaseObj&,Arg0*,PtrArr&,SolverFlagView&,float);

struct SolveConstraint;

void __cdecl reserveSolveArray(HeapObj&,void*,int,int);
template<class T> struct SolveArray {
    T* data;int size,capacity;
    __forceinline SolveArray():data(0),size(0),capacity(0x80000000){}
    __forceinline ~SolveArray(){if(capacity>=0)((HeapObj*)FUN_00c85750()->unk10)->ReturnMemory(data,(capacity&0x3fffffff)*sizeof(T));}
    __forceinline int GetLogicalSize()const{return size;}
    __forceinline T* begin(){return data;}
    __forceinline T& operator[](int i){return data[i];}
    __forceinline const T& operator[](int i)const{return data[i];}
    __forceinline void clear(){size=0;}
    __forceinline void reserve(int n){if(n>(capacity&0x3fffffff))reserveSolveArray(*(HeapObj*)FUN_00c85750()->unk10,this,n,sizeof(T));}
    __forceinline void pushBackUnchecked(const T& v){data[size++]=v;}
    __forceinline void AddBack(const T& v){reserve(size+1);pushBackUnchecked(v);}
    __forceinline void removeAt(int i){--size;if(size!=i)data[i]=data[size];}
    __forceinline void aiRecipeIndex(int i,const T* values,int count){reserve(size+count);for(int j=size-1;j>=i;--j)data[j+count]=data[j];for(int j=0;j<count;++j)data[i+j]=values[j];size+=count;}
    __forceinline void aiRecipeIndex(int i,const T& value){aiRecipeIndex(i,&value,1);}
};
template<class T,int N> struct SolveInlineArray:SolveArray<T> {
    T storage[N];
    __forceinline SolveInlineArray(){this->data=storage;this->capacity=N|0x80000000;}
};
template<class T> struct SolveLocalArray:SolveArray<T> {
    T* allocation;
    __forceinline SolveLocalArray(int n){Manager* r=FUN_00c85750();allocation=(T*)r->unk00;r->unk00+=((n*sizeof(T)+127)&~127);this->data=allocation;this->capacity=n|0x80000000;}
    __forceinline ~SolveLocalArray(){if(this->data==allocation)this->clear();FUN_00c85750()->unk00=(int)allocation;}
};

extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
struct AdvanceSimulation;
struct Res { DWORD unk; };




struct AdvanceSimulation {
    DWORD unk00,unk04,unk08,unk0C,unk10;
    float m_f14;
    DWORD unk18,unk1C,unk20,unk24;
    Res* m_p28;
    DWORD unk2C,unk30;
    DWORD m_34;
    Res* FUN_00cf8820() throw();
    float hkpSimulation_snapSimulateTimeAndGetTimeToAdvanceTo() throw();
    Res* hkpContinuousSimulation_handleAllToisTill(float f) throw();
    Res* FUN_00d0ed10();
};

// Under timers, calls FUN_00cf8820 if m_p28 is set, else hkpContinuousSimulation_handleAllToisTill when m_34 is set; returns the Res found, or clears m_p28 and returns null.
// @fnv 0x00d0ed10
Res* AdvanceSimulation::FUN_00d0ed10()
{
    HK_TIME_CODE_BLOCK("Simulate", HK_NULL);
    if (m_p28)
    {
        HK_TIME_CODE_BLOCK("reCollideAfterStepFailure", HK_NULL);
        Res* q = FUN_00cf8820();
        if (q)
            return q;
    }
    float delta = hkpSimulation_snapSimulateTimeAndGetTimeToAdvanceTo();
    if (m_34)
    {
        HK_TIME_CODE_BLOCK("TOIs", HK_NULL);
        Res* p = hkpContinuousSimulation_handleAllToisTill(delta);
        if (p)
        {
            m_p28 = p;
            return p;
        }
    }
    m_p28 = 0;
    m_f14 = delta;
    return 0;
}

struct ArrayRef_cls {
    int* m_pData;
    int m_iArrayLength;
    unsigned int m_iFlags;
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl ResizeAudioStream(void* allocator, ArrayRef_cls* arr, int n);
