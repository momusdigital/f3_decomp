#pragma intrinsic(__rdtsc)
#pragma intrinsic(_ReadWriteBarrier)
// src/f3staging/f3blk_00980000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00992c40 (community match, verified in this file)
struct Serializer92 {
    virtual void v0();
    virtual void NiStream_SaveHeader(const char*, int, void*);
    virtual void writeArray64(const char*, int, const void*, unsigned int, unsigned int);
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Finish();
};
struct Array92 { void* data; unsigned int count; int capacity; };
struct Row92 { int key; Array92 arr; };
struct Container92 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    Array92 a;
    Array92 b;
    Array92 c;
    Array92 d;
    int count;
    int unkD4;
    Row92* rows;
    void hkp3AxisSweep_calcContentStatistics(Serializer92* writer);
};
extern const char DAT_00e7dd2c[];
extern const char DAT_00e7dd24[];
extern const char DAT_00de0378[];
extern const char DAT_00e7dd1c[];
// pdb: hkp3AxisSweep::calcContentStatistics | hkp3AxisSweep.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(ustr), high
void Container92::hkp3AxisSweep_calcContentStatistics(Serializer92* writer)
{
    writer->NiStream_SaveHeader(DAT_00e7dd2c,4,this);
    if ((a.capacity & 0x80000000u) == 0) writer->writeArray64(DAT_00e7dd24,4,a.data,a.count*16,(a.capacity&0x3fffffff)*16);
    if ((b.capacity & 0x80000000u) == 0) writer->writeArray64(DAT_00de0378,4,b.data,b.count*4,(b.capacity&0x3fffffff)*4);
    if ((c.capacity & 0x80000000u) == 0) writer->writeArray64(DAT_00de0378,4,c.data,c.count*4,(c.capacity&0x3fffffff)*4);
    if ((d.capacity & 0x80000000u) == 0) writer->writeArray64(DAT_00de0378,4,d.data,d.count*4,(d.capacity&0x3fffffff)*4);
    if (count != 0) writer->writeArray64(DAT_00e7dd1c,4,rows,count*16,0);
    for (int i=0;i<count;i++)
    {
        Array92* r = (Array92*)((char*)rows + i*16 + 4);
        if((r->capacity & 0x80000000u) == 0)
            writer->writeArray64(DAT_00e7dd1c,8,r->data,r->count*2,(r->capacity&0x3fffffff)*2);
    }
    writer->Finish();
}

// @f3 0x00981430 (community match, verified in this file)
struct FUN_00981430_Src
{
    int unk00;
    float unk04;
    float unk08;
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
    float unk54;
    int unk58;
    float unk5C;
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
    float unk10C;
    float unk110;
    int unk114;
    int unk118;
    float unk11C;
    float unk120;
};

struct FUN_00981430_Pair
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct FUN_00981430_Dst
{
    float unk00;
    float unk04;
    float unk08;
    int unk0C;
    int unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    float unk40;
    float unk44;
    void FUN_00981430(const FUN_00981430_Src* src, const FUN_00981430_Pair* pair);
};

// pdb: hkpConstraintSolverSetup::initializeSolverState | hkpConstraintSolverSetup.obj | tesv_win, call_gap, low
void FUN_00981430_Dst::FUN_00981430(const FUN_00981430_Src* src, const FUN_00981430_Pair* pair)
{
    unk00 = src->unk10C;
    unk04 = src->unk11C * src->unk10C;
    unk08 = src->unk110;
    unk14 = src->unk120;
    unk18 = src->unk120 * src->unk11C;
    unk40 = src->unk04;
    unk44 = src->unk08;
    unk1C = src->unk54 * src->unk110;
    unk20 = src->unk08;
    unk24 = src->unk5C * src->unk110;
    unk0C = pair->unk08;
    unk10 = pair->unk0C;
}

// @f3 0x00989ec0 (community match, verified in this file)
class FUN_00c903b0_class {
public:
    void ReleaseReference();
};
struct FUN_00989ec0_Obj {
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
    FUN_00c903b0_class** arr;
    int count;
    void FUN_00989ec0(int index);
};
void FUN_00989ec0_Obj::FUN_00989ec0(int index)
{
    FUN_00c903b0_class* item = arr[index];
    item->ReleaseReference();
    count = count - 1;
    arr[index] = arr[count];
}

// @f3 0x00989a20 (community match, verified in this file)
struct Container989a20 {
    char pad[0x80];
    Array92 arr1;
    Array92 arr2;

    void hkpWorldObject_calcContentStatistics(Serializer92* writer);
    void hkpPhantom_calcContentStatistics(Serializer92* writer);
};

extern const char DAT_00e7d998[];
extern const char DAT_00e7d988[];

// pdb: hkpPhantom::calcContentStatistics | hkpPhantom.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void Container989a20::hkpPhantom_calcContentStatistics(Serializer92* writer)
{
    hkpWorldObject_calcContentStatistics(writer);
    if ((arr1.capacity & 0x80000000u) == 0) {
        writer->writeArray64(DAT_00e7d998, 4, arr1.data, arr1.count * 4, (arr1.capacity & 0x3fffffff) * 4);
    }
    if ((arr2.capacity & 0x80000000u) == 0) {
        writer->writeArray64(DAT_00e7d988, 4, arr2.data, arr2.count * 4, (arr2.capacity & 0x3fffffff) * 4);
    }
}

// @f3 0x009869e0 (community match, verified in this file)
struct Manager459 { int unk00,unk04; void* context; };
struct Source459 {
    int unk00; Manager459* first; Manager459* second; float value;
    int unk10,unk14,unk18,unk1c;
    int contact20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,properties40;
};
struct Info459 {
    void* first; void* second; int unused08;
    void* contact; void* properties; float parameter, value;
    int state0,state1;
};
void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(void*,Info459*);
void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(Manager459*,Info459*);
__forceinline bool HasCallbacks459(Manager459* manager) {
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(manager)+0x1f4)!=0;
}
// pdb: hkpReportContactMgr::confirmToi | hkpReportContactMgr.obj | fnv360_0822_retail, objrun_open, low
// pdb params: event, rotateNormal, outToBeActivated
void __stdcall FUN_009869e0(Source459* source,float value,void* unused) {
    Info459 info;
    info.parameter=value;
    info.value=source->value;
    info.first=reinterpret_cast<char*>(source->first)+0x10;
    info.second=reinterpret_cast<char*>(source->second)+0x10;
    info.contact=&source->contact20;
    info.properties=&source->properties40;
    info.state0=0;
    info.state1=0;
    hkpWorldCallbackUtil_fireContactPointCallback(source->first->context,&info);
    if(HasCallbacks459(source->first)) hkpEntityCallbackUtil_fireContactPointCallbackInternal(source->first,&info);
    if(HasCallbacks459(source->second)) hkpEntityCallbackUtil_fireContactPointCallbackInternal(source->second,&info);
}

// @f3 0x00990390 (community match, verified in this file)
struct FUN_00990390 {
    float scalar00; unsigned int unk04,unk08; float scalar0c; unsigned int unk10,unk14,unk18,unk1c;
    float scalar20,scalar24,scalar28,scalar2c,scalar30,scalar34,scalar38,scalar3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
    FUN_00990390* Assign(const FUN_00990390&);
};
// pdb: hkReferencedObject::addReferences | hkReferencedObject.obj | fnv360_0822_debug, call_gap, low
// pdb params: objects, numObjects, pointerStriding
FUN_00990390* FUN_00990390::Assign(const FUN_00990390& source) {
    scalar00=source.scalar00; unk04=source.unk04; unk08=source.unk08;
    scalar0c=source.scalar0c; unk10=source.unk10;
    scalar20=source.scalar20; scalar24=source.scalar24; scalar28=source.scalar28; scalar2c=source.scalar2c;
    scalar30=source.scalar30; scalar34=source.scalar34; scalar38=source.scalar38; scalar3c=source.scalar3c;
    unk40=source.unk40; unk44=source.unk44; unk48=source.unk48; unk4c=source.unk4c;
    unk50=source.unk50; unk54=source.unk54; unk58=source.unk58; unk5c=source.unk5c;
    unk60=source.unk60; unk64=source.unk64; unk68=source.unk68; unk6c=source.unk6c;
    return this;
}

// @f3 0x009985d0 (community match, verified in this file)
typedef void (__cdecl* Handler511)(void*,void*,void*);
struct TableEntry511 {
    Handler511 fn;
    unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
    unsigned int unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
};
struct Context511 {TableEntry511* table;};
struct Object511 {
    unsigned char type,subType;unsigned short unk02;
    unsigned int unk04,unk08,unk0c,unk10,unk14;float time;unsigned int unk1c;
    float x,y,z,w;unsigned char payload;
    __forceinline void Dispatch(Context511* context,void* data) {
        Handler511 callback=context->table[subType+0x49].fn;
        if(callback) callback(this,data,context);
    }
};
extern const float DAT_00db38b8;
void __cdecl FUN_009985d0(Object511* object,Context511* context) {
    switch(object->type) {
    case 2:case 6:object->Dispatch(context,&object->x);break;
    case 4:
        object->time=DAT_00db38b8;
        float* vector=&object->x; vector[0]=vector[1]=vector[2]=vector[3]=0.0f;
        object->Dispatch(context,&object->payload);
        break;
    }
}

// @f3 0x0098d900 (community match, verified in this file)
struct Array517 {void* data;int count,capacity;__forceinline Array517():data(0),count(0),capacity(0x80000000){}};
struct Heap517 {void* FUN_008f6d30(unsigned int,int);};
namespace Globals517 {extern unsigned long DAT_010f3170;extern Heap517* (__stdcall* const DAT_00d9b080)(unsigned long);extern int DAT_00e7dc14;}
struct Item517 {void* table;unsigned short size,references;unsigned int unk08;Item517* FUN_00a28370();};
struct Source517 {unsigned int unk0,unk4,unk8,unkc,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c,unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c,unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c,unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c,unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc,unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc,unk2e0,unk2e4,unk2e8,unk2ec,unk2f0;int count;};
void __cdecl FUN_00901e90(Array517*,int,int);
struct Owner517 {
    void* table;unsigned int unk04,unk08,unk0c;bool enabled;unsigned char unk11,unk12,unk13;
    unsigned int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    Array517 values;Item517* item;unsigned int unk40;
    void FUN_0097f1c0(Source517*);
    Owner517* FUN_0098d900(Source517*);
};
// pdb: hkpContinuousSimulation::hkpContinuousSimulation | hkpContinuousSimulation.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkCriticalSection::hkCriticalSection)
// pdb params: world
Owner517* Owner517::FUN_0098d900(Source517* source) {
    FUN_0097f1c0(source);table=&Globals517::DAT_00e7dc14;
    Array517* array=&values;
    array->data=0;array->count=0;array->capacity=0x80000000;enabled=true;
    Heap517* heap=Globals517::DAT_00d9b080(Globals517::DAT_010f3170);
    Item517* allocated=static_cast<Item517*>(heap->FUN_008f6d30(12,21));
    allocated->size=12;item=allocated->FUN_00a28370();unk40=0;
    int capacity=array->capacity&0x3fffffff;
    int required=source->count;
    if(capacity<required) {int target=capacity*2;if(required>=target)target=required;FUN_00901e90(array,target,112);}
    return this;
}

// @f3 0x00996ad0 (community match, verified in this file)
#include <new>
namespace f3m_00996ad0 {

struct Ep96 { unsigned short m_uiFilterValue; unsigned short m_usIndex; };
struct Less96 { };

template <class T> struct Arr96 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacity;
    Arr96(T* d, int n, int cap) : m_data(d), m_iElementCount(n), m_iCapacity(cap | 0x80000000) {}
    void pushBackUnchecked(const T& v) { m_data[m_iElementCount] = v; m_iElementCount++; }
};

struct Node96 {
    unsigned short m_min1;
    unsigned short m_min2;
    unsigned short m_max1;
    unsigned short m_max2;
    unsigned short m_min0;
    unsigned short m_max0;
};

void FUN_00998410(Ep96* first, int lo, int hi, Less96 cmp);

static void SortAxis96(Arr96<Ep96>& axis, Less96 cmp)
{
    int n = axis.m_iElementCount - 1;
    if (n > 1) FUN_00998410(axis.m_data + 1, 0, n - 1, cmp);
}

struct SweepClass96 {
    unsigned char unk00[0xac];
    Arr96<Ep96> m_kAxisEndPoints[3];
    void FUN_00996ad0(const Arr96<Node96*>& nodes, Arr96<Ep96>* tempAxes);
};

void SweepClass96::FUN_00996ad0(const Arr96<Node96*>& nodes, Arr96<Ep96>* tempAxes)
{
    Ep96* buf = (Ep96*)(tempAxes + 3);
    int cap = 2 * nodes.m_iElementCount + 2;
    new (&tempAxes[0]) Arr96<Ep96>(buf, 0, cap);
    new (&tempAxes[1]) Arr96<Ep96>(buf + cap, 0, cap);
    new (&tempAxes[2]) Arr96<Ep96>(buf + cap * 2, 0, cap);

    Ep96 sentinel;
    sentinel.m_uiFilterValue = 0;
    sentinel.m_usIndex = 0;
    tempAxes[0].pushBackUnchecked(sentinel);
    tempAxes[1].pushBackUnchecked(sentinel);
    tempAxes[2].pushBackUnchecked(sentinel);

    Node96* const* nodeIt = nodes.m_data;
    for (int i = nodes.m_iElementCount - 1; i >= 0; --i) {
        tempAxes[0].pushBackUnchecked(m_kAxisEndPoints[0].m_data[(*nodeIt)->m_min0]);
        tempAxes[0].pushBackUnchecked(m_kAxisEndPoints[0].m_data[(*nodeIt)->m_max0]);
        tempAxes[1].pushBackUnchecked(m_kAxisEndPoints[1].m_data[(*nodeIt)->m_min1]);
        tempAxes[1].pushBackUnchecked(m_kAxisEndPoints[1].m_data[(*nodeIt)->m_max1]);
        tempAxes[2].pushBackUnchecked(m_kAxisEndPoints[2].m_data[(*nodeIt)->m_min2]);
        tempAxes[2].pushBackUnchecked(m_kAxisEndPoints[2].m_data[(*nodeIt)->m_max2]);
        nodeIt++;
    }

    for (int j = 0; j < 3; ++j) {
        SortAxis96(tempAxes[j], Less96());
    }

    sentinel.m_uiFilterValue = 0xfffc;
    sentinel.m_usIndex = 0;
    tempAxes[0].pushBackUnchecked(sentinel);
    tempAxes[1].pushBackUnchecked(sentinel);
    tempAxes[2].pushBackUnchecked(sentinel);
}
}   // namespace f3m_00996ad0

// @f3 0x00998550 (community match, verified in this file)
namespace f3m_00998550 {
struct Edge;
struct Slot {
    Edge* m_p;
    int unk04;
};

struct Point {
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48;
    Slot* m_slots;
};

struct Edge {
    int unk00;
    unsigned short m_idxA;
    unsigned short m_idxB;
    int unk08;
    int unk0C;
    Point* m_kPointA;
    Point* m_kPointB;
};

// pdb: hkAgentNnMachine_RelinkEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00998550(Edge* apEdge)
{
    unsigned short a = apEdge->m_idxA;
    unsigned short b = apEdge->m_idxB;
    apEdge->m_kPointA->m_slots[a].m_p = apEdge;
    apEdge->m_kPointB->m_slots[b].m_p = apEdge;
}

void DummyLinkEdgeCaller(Edge* e)
{
    FUN_00998550(e);
}
}   // namespace f3m_00998550

// @f3 0x00981d00 (community match, verified in this file)
namespace f3m_00981d00 {
struct Ent98 {
    void* unk00;
    void* unk04;
};

struct Arr98 { Ent98* data; int count; int capacity; };

struct Owner98 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    int unk60,unk64;
    unsigned char unk68;
    unsigned char unk69,unk6a,unk6b;
    int unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4;
    Arr98 arr;
};

void* __cdecl FUN_00998710(void* first, void* second);
void __cdecl FUN_00944730(void* item);
void __cdecl FUN_00901f10(Arr98* list, int elementSize);

class Ctx98 {
public:
    int unk00;
    Owner98* owner;
    void hkpMultiThreadedSimulation_MtEntityEntityBroadPhaseListener_removeCollisionPair(Ent98* entry);
};

// pdb: hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::removeCollisionPair | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Ctx98::hkpMultiThreadedSimulation_MtEntityEntityBroadPhaseListener_removeCollisionPair(Ent98* entry)
{
    char* a = (char*)entry->unk00;
    char* b = (char*)entry->unk04;
    char* pFirstRec = a + *(signed char*)(a + 5);
    char* pSecondRec = b + *(signed char*)(b + 5);
    char* na = pFirstRec + *(signed char*)(pFirstRec + 0x10);
    char* nb = pSecondRec + *(signed char*)(pSecondRec + 0x10);

    Owner98* owner = this->owner;
    if (owner->unk68 != 0)
    {
        if (*(unsigned char*)(na + 0xd8) != 7 && *(unsigned char*)(nb + 0xd8) != 7
            && *(int*)(na + 0xb8) != *(int*)(nb + 0xb8))
        {
            Arr98* list = &owner->arr;
            if (list->count == (list->capacity & 0x3fffffff))
                FUN_00901f10(list, 8);
            list->data[list->count] = *entry;
            list->count = list->count + 1;
            return;
        }
    }

    void* found = FUN_00998710(pFirstRec, pSecondRec);
    if (found != 0)
        FUN_00944730(found);
}
}   // namespace f3m_00981d00

// @f3 0x00989340 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d950[];
extern const char DAT_00e32798[];
namespace f3m_00989340 {

extern "C" void _ReadWriteBarrier(void);

struct Item989340 {
    virtual void v0();
    virtual void Run(void* a, void* b);
};

struct Rec989340 {
    const void* label;
    unsigned int ticks;
    unsigned int unk08;

    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};

struct Buf989340 {
    int unk00;
    Rec989340* cur;
    int unk08;
    Rec989340* end;
};

extern Buf989340* (__stdcall* const DAT_00d9b080)(unsigned long);

struct Arr989340 {
    Item989340** data;
    int count;
};


volatile int g_sink989340;
static __declspec(noinline) void FUN_00988440(Arr989340* arr) { g_sink989340 = arr->count; }

struct Container989340 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140;
    Arr989340 arr;
};

// pdb: hkpWorldCallbackUtil::firePostIntegrateCallback | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpWorldCallbackUtil_firePostIntegrateCallback(Container989340* self, void* a)
{
    Arr989340* arr = &self->arr;
    int i = arr->count - 1;
    if (i >= 0) {
    Buf989340* (__stdcall* getter)(unsigned long) = DAT_00d9b080;
    do {
        if (arr->data[i] != 0) {
            Buf989340* b = getter(DAT_0116913c);
            Rec989340* r = b->cur;
            if (r < b->end) {
                r->label = DAT_00e7d950;
                _ReadWriteBarrier();
r->setTime();
                b->cur = r + 1;
            }
            arr->data[i]->Run(self, a);
            b = getter(DAT_0116913c);
            r = b->cur;
            if (r < b->end) {
                r->label = DAT_00e32798;
                _ReadWriteBarrier();
r->setTime();
                b->cur = r + 1;
            }
        }
    } while (--i >= 0);
    }
    FUN_00988440(arr);
}
}   // namespace f3m_00989340

// @f3 0x0099ea40 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0099ea40 {
struct HeapB { void* FUN_008f6d30(unsigned int, int); void FUN_008f6d90(void*, unsigned int, int); };
extern HeapB* (__stdcall* const FUN_00d9b080)(unsigned long);

struct Arr { int* data; int count; unsigned int cap; };

struct Obj {
    void* vt; unsigned short size; unsigned short pad6;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int* unk80; int unk84; unsigned int unk88; int* unk8c; int unk90; unsigned int unk94;
    unsigned int unk98, unk9c, unka0;
    Obj* FUN_0099e9b0(unsigned int, unsigned int*, unsigned int);
    void FUN_0090d960(Obj*);
    Obj* FUN_0099ea40();
};

// pdb: hkpSimpleShapePhantom::clone | hkpSimpleShapePhantom.obj | fnv360_1110_retail, objrun, medium
Obj* Obj::FUN_0099ea40()
{
    HeapB* (__stdcall* const getHeap)(unsigned long) = FUN_00d9b080;
    HeapB* h = getHeap(DAT_010f3170);
    Obj* r = static_cast<Obj*>(h->FUN_008f6d30(0x160, 0x31));
    r->size = 0x160;
    unsigned int a2c = unk2c;
    unsigned int a10 = unk10;
    r = r->FUN_0099e9b0(a10, &unka0, a2c);
    unsigned int n = r->unk88 & 0x3fffffff;
    if ((int)n < unk84) {
        if ((r->unk88 & 0x80000000u) == 0)
            { HeapB* hf = getHeap(DAT_010f3170); hf->FUN_008f6d90(r->unk80, n * 4, 0x17); }
        HeapB* ha = getHeap(DAT_010f3170);
        r->unk80 = (int*)ha->FUN_008f6d30(unk84 * 4, 0x17);
        r->unk88 = (r->unk88 & 0x40000000) | unk84;
    }
    int c84 = unk84;
    int* d80 = r->unk80;
    r->unk84 = c84;
    int* s80 = *(int* volatile*)&unk80;
    if (c84 > 0) { int off80 = (char*)s80 - (char*)d80; do { *d80 = *(int*)((char*)d80 + off80); d80++; } while (--c84); }
    n = r->unk94 & 0x3fffffff;
    if ((int)n < unk90) {
        if ((r->unk94 & 0x80000000u) == 0)
            { HeapB* hf = getHeap(DAT_010f3170); hf->FUN_008f6d90(r->unk8c, n * 4, 0x17); }
        HeapB* hb = getHeap(DAT_010f3170);
        r->unk8c = (int*)hb->FUN_008f6d30(unk90 * 4, 0x17);
        r->unk94 = (r->unk94 & 0x40000000) | unk90;
    }
    int c90 = unk90;
    int* d8c = r->unk8c;
    r->unk90 = c90;
    int* s8c = *(int* volatile*)&unk8c;
    if (c90 > 0) { int off8c = (char*)s8c - (char*)d8c; do { *d8c = *(int*)((char*)d8c + off8c); d8c++; } while (--c90); }
    r->FUN_0090d960(this);
    return r;
}
}   // namespace f3m_0099ea40

// @f3 0x00991b60 (community match, verified in this file)
extern unsigned short* DAT_01060de4[];
namespace f3m_00991b60 {
struct Entry991b60 { unsigned char type; unsigned char unk01; unsigned short index; };
struct Arr991b60 {
    Entry991b60* data;
    int count;
    int capacity;
    void FUN_00991b60(int offset, int group, int** remap);
};

void Arr991b60::FUN_00991b60(int offset, int group, int** remap)
{
    Entry991b60* dst = data;
    Entry991b60* src = data;
    Entry991b60* end = data + count;
    int kept = 0;
    while (src < end) {
        int mapped = (*remap)[src->index];
        if (mapped >= 0) {
            *dst = *src;
            dst->index = (unsigned short)mapped;
            *(unsigned short*)((char*)DAT_01060de4[group * 2 + (dst->type & 1)] + mapped * 16 + offset) = (unsigned short)kept;
            ++dst;
            ++kept;
        }
        ++src;
    }
    int capacity = this->capacity & 0x3fffffff;
    if (capacity < kept) {
        int newCapacity = capacity * 2;
        if (kept >= newCapacity) newCapacity = kept;
        FUN_00901e90((Array517*)this, newCapacity, 4);
    }
    this->count = kept;
}
}   // namespace f3m_00991b60

// @f3 0x00987bc0 (community match, verified in this file)
namespace f3m_00987bc0 {
struct hkArrayUShort {
    unsigned short* m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
};

void __cdecl FUN_00901f10(hkArrayUShort* array, int elementSize);

void hkArrayUShortAddBack(hkArrayUShort* a, unsigned short value) {
    if (a->m_size == (int)(a->m_capacityAndFlags & 0x3fffffff))
        FUN_00901f10(a, 2);
    a->m_data[a->m_size] = value;
    a->m_size = a->m_size + 1;
}

struct hkpShapeKeyMask {
    unsigned char* m_data;
    int m_iElementCount;
    void FUN_00987bc0(hkArrayUShort& kIndicesOut) const;
};

// pdb: hkpDynamicsCpIdMgr::getAllUsedIds | hkpSimpleConstraintContactMgr.obj | tesv_win, objrun, medium
void hkpShapeKeyMask::FUN_00987bc0(hkArrayUShort& kIndicesOut) const
{
    for (int i = 0; i < m_iElementCount; i++) {
        if (m_data[i] != 0xff)
            hkArrayUShortAddBack(&kIndicesOut, (unsigned short)i);
    }
}
}   // namespace f3m_00987bc0

// @f3 0x00991ad0 (community match, verified in this file)
namespace f3m_00991ad0 {
struct Arr_b0377 {
    void* data;
    int count;
    int capacity;
};

struct Slot_b0377 {
    unsigned int unk00;
    unsigned short* data;
    int count;
};

struct Pair_b0377 {
    unsigned int first;
    unsigned int second;
};

void __cdecl FUN_00901f10(Arr_b0377* arr, int elemSize);

// pdb: hkp3AxisSweep::endOverlapCheckMarker | hkp3AxisSweep.obj | tesv_win, objrun_open, low
void __fastcall FUN_00991ad0(void* self, unsigned int* rec, unsigned int key, unsigned int* obj, Arr_b0377* arr)
{
    if ((obj[3] & 1) == 0) {
        if (arr->count == (arr->capacity & 0x3fffffff)) {
            FUN_00901f10(arr, 8);
        }
        Pair_b0377* p = (Pair_b0377*)((char*)arr->data + arr->count * 8);
        arr->count++;
        p->first = rec[3];
        p->second = obj[3];
        return;
    }
    Slot_b0377* slot = (Slot_b0377*)((char*)self + (obj[3] & 0xfffffffe));
    int count = slot->count;
    int idx = 0;
    if (count > 0) {
        unsigned short* p = slot->data;
        do {
            if (*p == (unsigned short)key) goto found;
            p++;
            idx++;
        } while (idx < count);
    }
    idx = -1;
found:
    (*(volatile int*)&slot->count)--;
    int n = *(volatile int*)&slot->count;
    unsigned short last = slot->data[n];
    slot->data[idx] = last;
}
}   // namespace f3m_00991ad0

// @f3 0x00998d40 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00998d40 {
struct Record {
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned int word0c;
    unsigned int word10;
    unsigned int word14;
    unsigned int word18;
    unsigned int word1c;
    unsigned int word20;
    unsigned int word24;
    unsigned int word28;
    unsigned int word2c;
    unsigned int word30;
    unsigned int word34;
    unsigned int word38;
    unsigned int word3c;
    unsigned int word40;
    unsigned int word44;
    unsigned int word48;
    unsigned int word4c;
    unsigned int word50;
    unsigned int word54;
    unsigned int word58;
    unsigned int word5c;
    unsigned int word60;
    unsigned int word64;
    unsigned int word68;
    unsigned int word6c;
    unsigned int word70;
    unsigned int word74;
    unsigned int word78;
    unsigned int word7c;
};
struct DataBufferInfo { Record* record; unsigned int unk4; };
extern "C" void _ReadWriteBarrier(void);
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct PoolAllocator
{
    void* FUN_008f6d30(unsigned int bytes, int memoryClass);
};
struct SlabArray;
void __cdecl FUN_00901f10(SlabArray*, int);
struct SlabArray
{
    char** data;
    int count;
    unsigned int capacityFlags;
    void Append(char* block)
    {
        if (count == (capacityFlags & 0x3fffffffu))
            FUN_00901f10(this, 4);
        data[count] = block;
        ++count;
    }
};
struct State
{
    unsigned int used;
    SlabArray slabs;
};
// pdb: hkAgentNnMachine_AllocateEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, call_seq + bridge(caller|call_gap) + skyrim(call_seq), high
static __declspec(noinline) Record* hkAgentNnMachine_AllocateEntry(State* state)
{
    if (state->used < 512u)
    {
        char* result = state->slabs.data[state->slabs.count - 1] + state->used;
        state->used += 128;
        return reinterpret_cast<Record*>(result);
    }
    PoolAllocator* allocator = (PoolAllocator*)DAT_00d9b080(DAT_010f3170);
    char* block = static_cast<char*>(allocator->FUN_008f6d30(512, 0x27));
    state->slabs.Append(block);
    state->used = 128;
    return reinterpret_cast<Record*>(block);
}
// @fnv 0x00cfeca0
// pdb: hkAgentNnMachine_CopyAndRelinkAgentEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap), high
Record* hkAgentNnMachine_CopyAndRelinkAgentEntry(State* state, const Record* source)
{
    Record* record = hkAgentNnMachine_AllocateEntry(state);
    record->word00 = source->word00;
    record->word04 = source->word04;
    record->word08 = source->word08;
    record->word0c = source->word0c;
    record->word10 = source->word10;
    record->word14 = source->word14;
    record->word18 = source->word18;
    record->word1c = source->word1c;
    record->word20 = source->word20;
    record->word24 = source->word24;
    record->word28 = source->word28;
    record->word2c = source->word2c;
    record->word30 = source->word30;
    record->word34 = source->word34;
    record->word38 = source->word38;
    record->word3c = source->word3c;
    record->word40 = source->word40;
    record->word44 = source->word44;
    record->word48 = source->word48;
    record->word4c = source->word4c;
    record->word50 = source->word50;
    record->word54 = source->word54;
    record->word58 = source->word58;
    record->word5c = source->word5c;
    record->word60 = source->word60;
    record->word64 = source->word64;
    record->word68 = source->word68;
    record->word6c = source->word6c;
    record->word70 = source->word70;
    record->word74 = source->word74;
    record->word78 = source->word78;
    record->word7c = source->word7c;
    _ReadWriteBarrier();
    unsigned short indexA = static_cast<unsigned short>(record->word04);
    unsigned short indexB = static_cast<unsigned short>(record->word04 >> 16);
    DataBufferInfo* tableA = *reinterpret_cast<DataBufferInfo**>(record->word10 + 0x4c);
    tableA[indexA].record = record;
    DataBufferInfo* tableB = *reinterpret_cast<DataBufferInfo**>(record->word14 + 0x4c);
    tableB[indexB].record = record;
    return record;
}
}   // namespace f3m_00998d40

// @f3 0x009898a0 (community match, verified in this file)
namespace f3m_009898a0 {
namespace n9898a0 {
struct Owner;
struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Notify(Owner* o);
};
struct PtrArray {
    Listener** data;
    int count;
    Listener*& GetAt(int i) { return data[i]; }
};
static __declspec(noinline) void FUN_00989760(PtrArray* a)
{
    for (int i = a->count - 1; i >= 0; i--) {
        if (!a->data[i]) {
            a->count--;
            for (int j = i; j < a->count; j++)
                a->data[j] = a->data[j + 1];
        }
    }
}
struct Owner {
    char pad[0x8c];
    PtrArray listeners;
    void FUN_009898a0();
};
// pdb: hkpPhantom::firePhantomShapeSet | hkpPhantom.obj | tesv_win, caller_sim, low
void Owner::FUN_009898a0()
{
    for (int i = listeners.count - 1; i >= 0; i--) {
        if (listeners.GetAt(i))
            listeners.GetAt(i)->Notify(this);
    }
    FUN_00989760(&listeners);
}
}
}   // namespace f3m_009898a0

// @f3 0x0099e9f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0099e9f0 {
namespace n99e9f0 {
struct Alloc { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long) throw();
struct PtrArr {
    void** data;
    int size;
    unsigned int cap;
    ~PtrArr()
    {
        if ((cap & 0x80000000u) == 0) {
            unsigned int n = cap & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, n << 2, 0x17);
        }
    }
};
struct Base {
    virtual ~Base();
    char pad[0x14c];
};
struct FUN_0099e9f0 : Base {
    PtrArr arr;
    virtual ~FUN_0099e9f0();
};
// pdb: hkpSimpleShapePhantom::~hkpSimpleShapePhantom | hkpSimpleShapePhantom.obj | fnv360_0822_retail, call_seq, high
FUN_0099e9f0::~FUN_0099e9f0()
{
}
}
}   // namespace f3m_0099e9f0

// @f3 0x00988020 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d864[];
extern const char DAT_00e32798[];
namespace f3m_00988020 {
namespace f3m_00988020 {
extern "C" void _ReadWriteBarrier(void);
struct Rec { const void* label; unsigned int ticks; unsigned int unk08; };
struct Buf { int unk00; Rec* cur; int unk08; Rec* end; };
extern Buf* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void Run(void* a); };
struct Arr { int unk00, unk04; Item** data; unsigned short count; };
struct Obj { char pad[0xcc]; Arr* arr; };

// pdb: hkpEntityCallbackUtil::fireEntityShapeSet | hkpEntityCallbackUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpEntityCallbackUtil_fireEntityShapeSet(Obj* obj)
{
    volatile unsigned int t[2];
    Arr* arr = obj->arr;
    if (arr) {
        int i = arr->count - 1;
        if (i >= 0) {
        Buf* (__stdcall* getter)(unsigned long) = DAT_00d9b080;
        do {
            if (arr->data[i]) {
                Buf* b = getter(DAT_0116913c);
                Rec* r = b->cur;
                if (r < b->end) {
                    r->label = DAT_00e7d864;
                    _ReadWriteBarrier();
                    t[0] = (unsigned int)__rdtsc();
                    r->ticks = t[0];
                    b->cur = r + 1;
                }
                arr->data[i]->Run(obj);
                b = getter(DAT_0116913c);
                r = b->cur;
                if (r < b->end) {
                    r->label = DAT_00e32798;
                    _ReadWriteBarrier();
                    t[1] = (unsigned int)__rdtsc();
                    r->ticks = t[1];
                    b->cur = r + 1;
                }
            }
        } while (--i >= 0);
        }
    }
}
}
}   // namespace f3m_00988020

// @f3 0x009852c0 (community match, verified in this file)
namespace f3m_009852c0 {
struct Obj9852c0 {
    virtual void Delete(int flags);
    unsigned short active;
    short refs;
};
struct Ptr9852c0 {
    Obj9852c0* p;
    Ptr9852c0& operator=(Obj9852c0* o) {
        if (o->active) ++o->refs;
        Obj9852c0* old = p;
        if (old->active) {
            --old->refs;
            if (!old->refs) old->Delete(1);
        }
        p = o;
        return *this;
    }
};
struct Grid9852c0 {
    char pad00[0xc];
    Ptr9852c0 cells[8][8];
    void hkpCollisionDispatcher_registerContactMgrFactoryWithAll(Obj9852c0* o, int idx);
};
// pdb: hkpCollisionDispatcher::registerContactMgrFactoryWithAll | hkpCollisionDispatcher.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void Grid9852c0::hkpCollisionDispatcher_registerContactMgrFactoryWithAll(Obj9852c0* o, int idx)
{
    for (int k = 0; k < 8; ++k) {
        cells[k][idx] = o;
        cells[idx][k] = o;
    }
}
}   // namespace f3m_009852c0

// @f3 0x00989ff0 (community match, verified in this file)
namespace f3m_00989ff0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Ref989ff0 { int vtbl; short active; short refs; };
struct Arr989ff0 {
    Ref989ff0** data;
    int size;
    int capFlags;
    void PushBack(Ref989ff0* p) {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[size] = p;
        size++;
    }
};
struct Obj989ff0 {
    char pad00[0x14];
    Arr989ff0 arr;
    void hkpPhysicsSystem_addConstraint(Ref989ff0* p);
};
// pdb: hkpPhysicsSystem::addConstraint | hkpPhysicsSystem.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
void Obj989ff0::hkpPhysicsSystem_addConstraint(Ref989ff0* p)
{
    if (p) {
        if (p->active) ++p->refs;
        arr.PushBack(p);
    }
}
}   // namespace f3m_00989ff0

// @f3 0x0099f620 (community match, verified in this file)
extern const char DAT_00e7de84[];
namespace f3m_0099f620 {
struct Writer99f620 {
    virtual void v0();
    virtual void Begin(const void* cls, int n, void* obj);
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void End();
};
struct Obj99f620 { void FUN_0099f620(Writer99f620* w); };
void Obj99f620::FUN_0099f620(Writer99f620* w)
{
    w->Begin(DAT_00e7de84, 1, this);
    w->End();
}
}   // namespace f3m_0099f620

// @f3 0x00988e70 (community match, verified in this file)
namespace f3m_00989340 {
struct Item988e70 { virtual void v0(); virtual void Run(void* a); };
struct Container988e70 {
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
    Arr989340 arr;
};
extern const char DAT_00e7d904[];
// pdb: hkpWorldCallbackUtil::fireWorldDeleted | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_dedup, low
// pdb params: world
void __cdecl FUN_00988e70(Container988e70* self) {
    Arr989340* arr = &self->arr;
    int i = arr->count - 1;
    if (i >= 0) {
        Buf989340* (__stdcall* getter)(unsigned long) = DAT_00d9b080;
        do {
            if (arr->data[i] != 0) {
                Buf989340* b = getter(DAT_0116913c);
                Rec989340* r = b->cur;
                if (r < b->end) {
                    r->label = DAT_00e7d904;
                    _ReadWriteBarrier();
                    r->setTime();
                    b->cur = r + 1;
                }
                ((Item988e70*)arr->data[i])->Run(self);
                b = getter(DAT_0116913c);
                r = b->cur;
                if (r < b->end) {
                    r->label = DAT_00e32798;
                    _ReadWriteBarrier();
                    r->setTime();
                    b->cur = r + 1;
                }
            }
        } while (--i >= 0);
    }
    FUN_00988440(arr);
}
}

// @f3 0x0098b5f0 (community match, verified in this file)
namespace f3m_0098b5f0 {
struct Obj98b5f0 { int v; void hkMultiThreadCheck_disableChecks(); };
// pdb: hkMultiThreadCheck::disableChecks | hkMultiThreadCheck.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_gap) + skyrim(call_gap_sim), high
void Obj98b5f0::hkMultiThreadCheck_disableChecks()
{
    v = -47;
}
}   // namespace f3m_0098b5f0

// @f3 0x009880d0 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d874[];
extern const char DAT_00e32798[];
namespace f3m_009880d0 {
namespace task0733 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct CFFCF0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct CFFCF0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};


__forceinline CFFCF0MonitorStream& CFFCF0GetMonitorStream()
{
    return *(CFFCF0MonitorStream*)TlsGetValue(DAT_0116913c);
}

__forceinline void CFFCF0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    CFFCF0MonitorStream& mStream = CFFCF0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        CFFCF0TimerCommand* h = (CFFCF0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct CFFCF0TimerTicks
{
    unsigned int m_pRayStart;
    unsigned int m_kRayEnd;
};

struct CFFCF0Owner;

struct CFFCF0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void callback(CFFCF0Owner* owner);
};

struct CFFCF0ListenerList
{
    int unk00;
    int unk04;
    CFFCF0Listener** m_kListeners;
    unsigned short m_uiItemCount;
};

struct CFFCF0Owner
{
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
    CFFCF0ListenerList* m_listenerList;
};


// @fnv 0x00cffcf0
// pdb: hkpEntityCallbackUtil::fireEntityDeleted | hkpEntityCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpEntityCallbackUtil_fireEntityDeleted(CFFCF0Owner* owner)
{
    CFFCF0TimerTicks ticks;
    CFFCF0ListenerList* list = owner->m_listenerList;
    if (list)
    {
        for (int i = list->m_uiItemCount - 1; i >= 0; i--)
        {
            if (list->m_kListeners[i] != 0)
            {
                CFFCF0TimerBegin(DAT_00e7d874, ticks.m_pRayStart);
                list->m_kListeners[i]->callback(owner);
                CFFCF0TimerBegin(DAT_00e32798, ticks.m_kRayEnd);
            }
        }
    }
}

}
}   // namespace f3m_009880d0

// @f3 0x00988390 (community match, verified in this file)
namespace task0738 {
struct CFF9B0SmallArray
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++)
            m_data[i] = m_data[i + 1];
    }
};

// Iterates the array backwards and removes every entry whose pointer is null via removeAtAndCopy.
// @fnv 0x00cff9b0
static void FUN_00987ce0(CFF9B0SmallArray& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0116913c;
extern char DAT_00e7d8a4[];
extern char DAT_00e32798[];
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
struct MonitorStream
{
    int m_00;
    char* m_cur;
    int m_08;
    char* m_kRayEnd;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0116913c);
    if (s->m_cur < s->m_kRayEnd)
    {
        TimerEntry* h = (TimerEntry*)s->m_cur;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_cur = (char*)(h + 1);
    }
}
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void callback(void* event);
};
struct ListenerEvent
{
    int m_00;
    int m_04;
    void* m_pObservedSource;
};
struct ListenerOwner
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    int m_1a0, m_1a4, m_1a8, m_1ac, m_1b0, m_1b4, m_1b8, m_1bc;
    int m_1c0, m_1c4, m_1c8, m_1cc, m_1d0, m_1d4, m_1d8, m_1dc;
    int m_1e0, m_1e4, m_1e8, m_1ec;
    CFF9B0SmallArray m_kListeners;
};
// Sets event->m_pObservedSource to owner, calls callback on each non-null listener in reverse with timers, then calls FUN_00987ce0 to remove null entries.
// @fnv 0x00d00110
// pdb: hkpEntityCallbackUtil::fireContactProcessInternal | hkpEntityCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpEntityCallbackUtil_fireContactProcessInternal(ListenerOwner* owner, ListenerEvent* event)
{
    CFF9B0SmallArray& kListeners = owner->m_kListeners;
    event->m_pObservedSource = owner;
    for (int i = kListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (kListeners.m_data[i] != 0)
        {
            unsigned int t1;
            unsigned int uiTimerEnd;
            TimerWriteV(DAT_00e7d8a4, t1);
            ((ContactListener*)kListeners.m_data[i])->callback(event);
            TimerWriteV(DAT_00e32798, uiTimerEnd);
        }
    }
    FUN_00987ce0(kListeners);
}

}

// @f3 0x009882e0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern char DAT_00e7d898[];
extern const char DAT_00e32798[];
namespace f3m_009882e0 {
struct CFF9B0SmallArray
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++)
            m_data[i] = m_data[i + 1];
    }
};

// Iterates the array backwards and removes every entry whose pointer is null via removeAtAndCopy.
// @fnv 0x00cff9b0
static __declspec(noinline) void FUN_00987ce0(CFF9B0SmallArray& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
struct MonitorStream
{
    int m_00;
    char* m_cur;
    int m_08;
    char* m_kRayEnd;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0116913c);
    if (s->m_cur < s->m_kRayEnd)
    {
        TimerEntry* h = (TimerEntry*)s->m_cur;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_cur = (char*)(h + 1);
    }
}
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void callback(void* event);
};
struct ListenerEvent
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_pObservedSource;
};
struct ListenerOwner
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    int m_1a0, m_1a4, m_1a8, m_1ac, m_1b0, m_1b4, m_1b8, m_1bc;
    int m_1c0, m_1c4, m_1c8, m_1cc, m_1d0, m_1d4, m_1d8, m_1dc;
    int m_1e0, m_1e4, m_1e8, m_1ec;
    CFF9B0SmallArray m_kListeners;
};
// @fnv 0x00d00110
// pdb: hkpEntityCallbackUtil::fireContactPointRemovedInternal | hkpEntityCallbackUtil.obj | fnv360_0822_retail, caller_sim + bridge(ustr_rel|call_seq) + skyrim(caller_sim), high
void __cdecl hkpEntityCallbackUtil_fireContactPointRemovedInternal(ListenerOwner* owner, ListenerEvent* event)
{
    CFF9B0SmallArray& kListeners = owner->m_kListeners;
    event->m_pObservedSource = owner;
    for (int i = kListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (kListeners.m_data[i] != 0)
        {
            unsigned int t1;
            unsigned int uiTimerEnd;
            TimerWriteV(DAT_00e7d898, t1);
            ((ContactListener*)kListeners.m_data[i])->callback(event);
            TimerWriteV(DAT_00e32798, uiTimerEnd);
        }
    }
    FUN_00987ce0(kListeners);
}
}   // namespace f3m_009882e0

// @f3 0x00988230 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d88c[];
extern const char DAT_00e32798[];
namespace f3m_00988230 {
struct CFF9B0SmallArray
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++)
            m_data[i] = m_data[i + 1];
    }
};

// Iterates the array backwards and removes every entry whose pointer is null via removeAtAndCopy.
// @fnv 0x00cff9b0
static __declspec(noinline) void FUN_00987ce0(CFF9B0SmallArray& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
struct MonitorStream
{
    int m_00;
    char* m_cur;
    int m_08;
    char* m_kRayEnd;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0116913c);
    if (s->m_cur < s->m_kRayEnd)
    {
        TimerEntry* h = (TimerEntry*)s->m_cur;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_cur = (char*)(h + 1);
    }
}
struct ContactListener
{
    virtual void v00();
    virtual void callback(void* event);
};
struct ListenerEvent
{
    int m_00;
    int m_04;
    void* m_pObservedSource;
};
struct ListenerOwner {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec;
    CFF9B0SmallArray m_kListeners;
};
// @fnv 0x00d00110
// pdb: hkpEntityCallbackUtil::fireContactPointCallbackInternal | hkpEntityCallbackUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_seq) + skyrim(call_gap_sim), high
void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(ListenerOwner* owner, ListenerEvent* event)
{
    CFF9B0SmallArray& kListeners = owner->m_kListeners;
    event->m_pObservedSource = owner;
    for (int i = kListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (kListeners.m_data[i] != 0)
        {
            unsigned int t1;
            unsigned int uiTimerEnd;
            TimerWriteV(DAT_00e7d88c, t1);
            ((ContactListener*)kListeners.m_data[i])->callback(event);
            TimerWriteV(DAT_00e32798, uiTimerEnd);
        }
    }
    FUN_00987ce0(kListeners);
}
}   // namespace f3m_00988230

// @f3 0x00988580 (community match, verified in this file)
extern unsigned long DAT_0116913c;
namespace f3m_00988580 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Task0742 {
class ContactPointEvent;
class Listener {public: virtual void v0(); virtual void v4(); virtual void actionRemovedCallback(ContactPointEvent*);};
struct Array833 {Listener** data; int size; int capacity;};
struct World833 {
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
 Array833 contactPointListeners;
};
struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireActionRemoved | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_fireActionRemoved(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtactRemCb", beginTicks);
            listeners.data[i]->actionRemovedCallback(event);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00988440(listeners);
}

}
}   // namespace f3m_00988580

// @f3 0x009886e0 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
namespace f3m_009886e0 {
namespace task0743 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833 {
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
Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireEntityRemoved | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_seq) + skyrim(call_gap), high
void __cdecl hkpWorldCallbackUtil_fireEntityRemoved(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtentRemCb", beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00988440(listeners);
}
}  // namespace task0743
}   // namespace f3m_009886e0

// @f3 0x009889a0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d864[];
extern const char DAT_00e32798[];
namespace f3m_009889a0 {
namespace fnv_00d00060 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void slot00();
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::firePhantomShapeSet | hkpWorldCallbackUtil.obj | fnv360_0721_beta, ustr_rel + bridge(ustr_rel|call_seq) + skyrim(ustr_rel), high
void __cdecl hkpWorldCallbackUtil_firePhantomShapeSet(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833(DAT_00e7d864, beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}  // namespace fnv_00d00060
}   // namespace f3m_009889a0

// @f3 0x00988a50 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d8e0[];
extern const char DAT_00e32798[];
namespace f3m_00988a50 {
namespace task0748 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833 {
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110;
    Array833 contactPointListeners;
};
struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireConstraintAdded | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap_sim), high
void __cdecl hkpWorldCallbackUtil_fireConstraintAdded(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833(DAT_00e7d8e0, beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}
}   // namespace f3m_00988a50

// @f3 0x00988630 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
namespace f3m_00988630 {
namespace task0751 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833 {
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
Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireEntityAdded | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_dedup|call_dedup) + skyrim(call_gap), high
void __cdecl hkpWorldCallbackUtil_fireEntityAdded(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtentAddCb", beginTicks);
            listeners.data[i]->newCollisionCallback(event);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00988440(listeners);
}
}  // namespace task0751
}   // namespace f3m_00988630

// @f3 0x00988b00 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d8ec[];
extern const char DAT_00e32798[];
namespace f3m_00988b00 {
namespace task0749 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833 {
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110;
    Array833 contactPointListeners;
};
struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireConstraintRemoved | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap_sim), high
void __cdecl hkpWorldCallbackUtil_fireConstraintRemoved(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833(DAT_00e7d8ec, beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}
}   // namespace f3m_00988b00

// @f3 0x00988790 (community match, verified in this file)
namespace task0744 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0116913c;
extern char DAT_00e7d864[];
extern char DAT_00e32798[];
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void reservedCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireEntityShapeSet | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpWorldCallbackUtil_fireEntityShapeSet(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833(DAT_00e7d864, beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}

// @f3 0x009896b0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d97c[];
extern const char DAT_00e32798[];
namespace f3m_009896b0 {
namespace task0750 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireInactiveEntityMoved | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_fireInactiveEntityMoved(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833(DAT_00e7d97c, beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}  // namespace task0750
}   // namespace f3m_009896b0

// @f3 0x00988840 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d8c8[];
extern const char DAT_00e32798[];
namespace f3m_00988840 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace task0745 {
class PhantomEvent;
class PhantomListener {
public:
    virtual void v0();
    virtual void phantomAddedCallback(PhantomEvent*);
};
struct ListenerArray {
    PhantomListener** data;
    int size;
    unsigned int capacity;
};
struct World {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104;
    ListenerArray phantomListeners;
};
struct Timer {
    const char* command;
    unsigned int time0, time1;
};
struct Stream {
    int unk00;
    Timer* end;
    int unk08;
    Timer* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(ListenerArray& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index) {
        if (!listeners.data[index]) {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent(const char* name, volatile unsigned int& ticks)
{
    Stream* stream = static_cast<Stream*>(TlsGetValue(DAT_0116913c));
    Timer* command = stream->end;
    if (command < stream->capacityEnd) {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// pdb: hkpWorldCallbackUtil::firePhantomAdded | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_firePhantomAdded(World* world, PhantomEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    ListenerArray& listeners = world->phantomListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i) {
        if (listeners.data[i]) {
            TimerEvent(DAT_00e7d8c8, beginTicks);
            listeners.data[i]->phantomAddedCallback(event);
            TimerEvent(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}
}   // namespace f3m_00988840

// @f3 0x009888f0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
namespace f3m_009888f0 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Task0746 {
class ContactPointEvent;
class Listener {public: virtual void v0(); virtual void v4(); virtual void phantomRemovedCallback(ContactPointEvent*);};
struct Array833 {Listener** data; int size; int capacity;};
struct World833 {
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
 Array833 phantomListeners;
};
struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::firePhantomRemoved | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_firePhantomRemoved(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->phantomListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtphntRemCb", beginTicks);
            listeners.data[i]->phantomRemovedCallback(event);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00988440(listeners);
}

}
}   // namespace f3m_009888f0

// @f3 0x00983000 (community match, verified in this file)
namespace f3m_00983000 {
struct O_983000 { char pad[0x140]; int v; int* FUN_00983000(); };
// pdb: hkArrayBase<hkpTypedBroadPhaseHandlePair>::end | hkpMultithreadedSimulation.obj | fnv360_0822_debug, objrun_open, low
int* O_983000::FUN_00983000() { return &v; }
}   // namespace f3m_00983000

// @f3 0x00986d20 (community match, verified in this file)
namespace f3m_00986d20 {
struct O_986d20 { char pad[0x20]; int v; int FUN_00986d20(); };
// pdb: hkpContactMgr::removeContactPoint | hkpSimpleConstraintContactMgr.obj | fnv360_0822_debug, objrun_open, low
// pdb params: cpId, constraintOwner
int O_986d20::FUN_00986d20() { return v - 0x14; }
}   // namespace f3m_00986d20

// @f3 0x00981730 (community match, verified in this file)
namespace f3m_00981730 {
struct Owner00981730 {
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    void hkpMultiThreadedSimulation_getMultithreadConfig(unsigned int* out);
};
// pdb: hkpMultiThreadedSimulation::getMultithreadConfig | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_open), high
void Owner00981730::hkpMultiThreadedSimulation_getMultithreadConfig(unsigned int* out) { *out = unkE8; }
}   // namespace f3m_00981730

// @f3 0x0099e740 (community match, verified in this file)
namespace f3m_0099e740 {
namespace n99e740 {
struct Bool { char b; Bool(bool v) : b(v) {} };
}
struct Obj99e740 {
    char pad[0x150];
    void** items;
    int count;
    n99e740::Bool FUN_0099e740(void* k);
};
// pdb: hkpSimpleShapePhantom::isOverlappingCollidableAdded | hkpSimpleShapePhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collidable
n99e740::Bool Obj99e740::FUN_0099e740(void* k)
{
    for (int i = 0; i < count; i++)
        if (items[i] == k) return true;
    return false;
}
}   // namespace f3m_0099e740

// @f3 0x00981720 (community match, verified in this file)
namespace f3m_00981720 {
struct O_981720 { char pad[0xec]; int v; void FUN_00981720(); };
void O_981720::FUN_00981720() { v = 0; }
}   // namespace f3m_00981720

// @f3 0x00986d30 (community match, verified in this file)
namespace f3m_00986d30 {
namespace task0810 {
struct Contact {
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
unsigned short listenerCount;
};
struct ContactRecord {
    unsigned short flags;
    unsigned short reserved;
    void* secondInput;
    Contact* firstContact;
    Contact* secondContact;
    void* optional;
    void* owner;
    void* firstInput;
};
void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(void* handler, ContactRecord* record);
void __cdecl hkpEntityCallbackUtil_fireContactPointRemovedInternal(Contact* contact, ContactRecord* record);
struct FUN_00cfccf0_class {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c;
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    void* m_40; void* m_44; void* m_48; void* m_4c;
    void* m_50; void* m_54;
    Contact* m_58;
    Contact* m_5c;
    void FUN_00986d30(void* firstInput, void* secondInput);
};
// Builds a ContactRecord from the two stored contacts and inputs, dispatches it via m_0c, then processes each contact whose flag at index 0x102 is set.
// @fnv 0x00cfccf0
// pdb: hkpSimpleConstraintContactMgr::removeToiImpl | hkpSimpleConstraintContactMgr.obj | fnv360_0822_retail, objrun_open, low
// pdb params: constraintOwner, properties
void FUN_00cfccf0_class::FUN_00986d30(void* firstInput, void* secondInput) {
    Contact* first = m_58;
    Contact* second = m_5c;
    ContactRecord record;
    record.flags = 0xffff;
    record.secondInput = secondInput;
    record.firstContact = first;
    record.secondContact = second;
    record.owner = this;
    record.firstInput = firstInput;
    hkpWorldCallbackUtil_fireContactPointRemoved(m_0c, &record);
    if (first->listenerCount) hkpEntityCallbackUtil_fireContactPointRemovedInternal(first, &record);
    if (second->listenerCount) hkpEntityCallbackUtil_fireContactPointRemovedInternal(second, &record);
}

}
}   // namespace f3m_00986d30

// @f3 0x0098b620 (community match, verified in this file)
namespace f3m_0098b620 {
namespace f3m_0098b620 {
struct Obj {
    int unk00;
    bool FUN_0098b620();
};
// pdb: hkMultiThreadCheck::reenableChecks | hkMultiThreadCheck.obj | fnv360_0822_retail, objrun_open, low
bool Obj::FUN_0098b620() {
    return unk00 != -0x2f;
}
}
}   // namespace f3m_0098b620

// @f3 0x00991080 (community match, verified in this file)
namespace f3m_00991080 {
namespace f3m_00991080 {
struct Vec4 { float x, y, z, w; };
// pdb: memclear16 | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
void __fastcall FUN_00991080(Vec4* p, int bytes) {
    for (int n = bytes >> 4; n >= 0; n--) {
        Vec4* v = p++;
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = 0.0f;
        v->w = 0.0f;
    }
}
}
}   // namespace f3m_00991080

// @f3 0x009835d0 (community match, verified in this file)
namespace f3m_009835d0 {

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct Heap { void FUN_008f6d90(void* p, unsigned int size, int kind); };
extern unsigned long DAT_010f3170;

struct GlobalLock {
    void FUN_00908a00();
    void Leave() {
        unk18 = -1;
        unk1c = -1;
        LeaveCriticalSection(this);
    }
    int cs0, cs4, cs8, csc, cs10, cs14;
    int unk18;
    int unk1c;
};
extern GlobalLock DAT_011692e8;

struct Entry { int a, b, c, d, e; };

struct Array {
    Entry* data;
    int unk4;
    unsigned int capacity;
    int unkc;
    void Release() {
        if (!(capacity & 0x80000000)) {
            unsigned int n = capacity & 0x3fffffff;
            Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, n * sizeof(Entry), 0x17);
        }
    }
};

struct TrackedLock {
    int cs0, cs4, cs8, csc, cs10, cs14;
    int unk18, unk1c, unk20;
    TrackedLock* prev;
    TrackedLock* next;
    void Destroy() {
        DeleteCriticalSection(this);
        if (prev) {
            DAT_011692e8.FUN_00908a00();
            prev->next = next;
            if (next) next->prev = prev;
            DAT_011692e8.Leave();
        }
    }
};

struct Owner {
    Array first;
    Array second;
    TrackedLock lock;
    void FUN_009835d0();
};

// pdb: hkpProcessCollisionInput::`scalar deleting destructor' | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
void Owner::FUN_009835d0() {
    lock.Destroy();
    second.Release();
    first.Release();
}

}

// @f3 0x00998570 (community match, verified in this file)
namespace f3m_00998570 {
namespace Dispatch322{struct Input322;struct Context322;typedef void(__cdecl *Callback322)(Input322*,void*,unsigned int,unsigned int,Context322*,unsigned int,void*);struct Row322{Callback322 function;unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;};struct Root322{unsigned int unk0000,unk0004,unk0008,unk000c,unk0010,unk0014,unk0018,unk001c,unk0020,unk0024,unk0028,unk002c,unk0030,unk0034,unk0038,unk003c,unk0040,unk0044,unk0048,unk004c,unk0050,unk0054,unk0058,unk005c,unk0060,unk0064,unk0068,unk006c,unk0070,unk0074,unk0078,unk007c,unk0080,unk0084,unk0088,unk008c,unk0090,unk0094,unk0098,unk009c,unk00a0,unk00a4,unk00a8,unk00ac,unk00b0,unk00b4,unk00b8,unk00bc,unk00c0,unk00c4,unk00c8,unk00cc,unk00d0,unk00d4,unk00d8,unk00dc,unk00e0,unk00e4,unk00e8,unk00ec,unk00f0,unk00f4,unk00f8,unk00fc,unk0100,unk0104,unk0108,unk010c,unk0110,unk0114,unk0118,unk011c,unk0120,unk0124,unk0128,unk012c,unk0130,unk0134,unk0138,unk013c,unk0140,unk0144,unk0148,unk014c,unk0150,unk0154,unk0158,unk015c,unk0160,unk0164,unk0168,unk016c,unk0170,unk0174,unk0178,unk017c,unk0180,unk0184,unk0188,unk018c,unk0190,unk0194,unk0198,unk019c,unk01a0,unk01a4,unk01a8,unk01ac,unk01b0,unk01b4,unk01b8,unk01bc,unk01c0,unk01c4,unk01c8,unk01cc,unk01d0,unk01d4,unk01d8,unk01dc,unk01e0,unk01e4,unk01e8,unk01ec,unk01f0,unk01f4,unk01f8,unk01fc,unk0200,unk0204,unk0208,unk020c,unk0210,unk0214,unk0218,unk021c,unk0220,unk0224,unk0228,unk022c,unk0230,unk0234,unk0238,unk023c,unk0240,unk0244,unk0248,unk024c,unk0250,unk0254,unk0258,unk025c,unk0260,unk0264,unk0268,unk026c,unk0270,unk0274,unk0278,unk027c,unk0280,unk0284,unk0288,unk028c,unk0290,unk0294,unk0298,unk029c,unk02a0,unk02a4,unk02a8,unk02ac,unk02b0,unk02b4,unk02b8,unk02bc,unk02c0,unk02c4,unk02c8,unk02cc,unk02d0,unk02d4,unk02d8,unk02dc,unk02e0,unk02e4,unk02e8,unk02ec,unk02f0,unk02f4,unk02f8,unk02fc,unk0300,unk0304,unk0308,unk030c,unk0310,unk0314,unk0318,unk031c,unk0320,unk0324,unk0328,unk032c,unk0330,unk0334,unk0338,unk033c,unk0340,unk0344,unk0348,unk034c,unk0350,unk0354,unk0358,unk035c,unk0360,unk0364,unk0368,unk036c,unk0370,unk0374,unk0378,unk037c,unk0380,unk0384,unk0388,unk038c,unk0390,unk0394,unk0398,unk039c,unk03a0,unk03a4,unk03a8,unk03ac,unk03b0,unk03b4,unk03b8,unk03bc,unk03c0,unk03c4,unk03c8,unk03cc,unk03d0,unk03d4,unk03d8,unk03dc,unk03e0,unk03e4,unk03e8,unk03ec,unk03f0,unk03f4,unk03f8,unk03fc,unk0400,unk0404,unk0408,unk040c,unk0410,unk0414,unk0418,unk041c,unk0420,unk0424,unk0428,unk042c,unk0430,unk0434,unk0438,unk043c,unk0440,unk0444,unk0448,unk044c,unk0450,unk0454,unk0458,unk045c,unk0460,unk0464,unk0468,unk046c,unk0470,unk0474,unk0478,unk047c,unk0480,unk0484,unk0488,unk048c,unk0490,unk0494,unk0498,unk049c,unk04a0,unk04a4,unk04a8,unk04ac,unk04b0,unk04b4,unk04b8,unk04bc,unk04c0,unk04c4,unk04c8,unk04cc,unk04d0,unk04d4,unk04d8,unk04dc,unk04e0,unk04e4,unk04e8,unk04ec,unk04f0,unk04f4,unk04f8,unk04fc,unk0500,unk0504,unk0508,unk050c,unk0510,unk0514,unk0518,unk051c,unk0520,unk0524,unk0528,unk052c,unk0530,unk0534,unk0538,unk053c,unk0540,unk0544,unk0548,unk054c,unk0550,unk0554,unk0558,unk055c,unk0560,unk0564,unk0568,unk056c,unk0570,unk0574,unk0578,unk057c,unk0580,unk0584,unk0588,unk058c,unk0590,unk0594,unk0598,unk059c,unk05a0,unk05a4,unk05a8,unk05ac,unk05b0,unk05b4,unk05b8,unk05bc,unk05c0,unk05c4,unk05c8,unk05cc,unk05d0,unk05d4,unk05d8,unk05dc,unk05e0,unk05e4,unk05e8,unk05ec,unk05f0,unk05f4,unk05f8,unk05fc,unk0600,unk0604,unk0608,unk060c,unk0610,unk0614,unk0618,unk061c,unk0620,unk0624,unk0628,unk062c,unk0630,unk0634,unk0638,unk063c,unk0640,unk0644,unk0648,unk064c,unk0650,unk0654,unk0658,unk065c,unk0660,unk0664,unk0668,unk066c,unk0670,unk0674,unk0678,unk067c,unk0680,unk0684,unk0688,unk068c,unk0690,unk0694,unk0698,unk069c,unk06a0,unk06a4,unk06a8,unk06ac,unk06b0,unk06b4,unk06b8,unk06bc,unk06c0,unk06c4,unk06c8,unk06cc,unk06d0,unk06d4,unk06d8,unk06dc,unk06e0,unk06e4,unk06e8,unk06ec,unk06f0,unk06f4,unk06f8,unk06fc,unk0700,unk0704,unk0708,unk070c,unk0710,unk0714,unk0718,unk071c,unk0720,unk0724,unk0728,unk072c,unk0730,unk0734,unk0738,unk073c,unk0740,unk0744,unk0748,unk074c,unk0750,unk0754,unk0758,unk075c,unk0760,unk0764,unk0768,unk076c,unk0770,unk0774,unk0778,unk077c,unk0780,unk0784,unk0788,unk078c,unk0790,unk0794,unk0798,unk079c,unk07a0,unk07a4,unk07a8,unk07ac,unk07b0,unk07b4,unk07b8,unk07bc,unk07c0,unk07c4,unk07c8,unk07cc,unk07d0,unk07d4,unk07d8,unk07dc,unk07e0,unk07e4,unk07e8,unk07ec,unk07f0,unk07f4,unk07f8,unk07fc,unk0800,unk0804,unk0808,unk080c,unk0810,unk0814,unk0818,unk081c,unk0820,unk0824,unk0828,unk082c,unk0830,unk0834,unk0838,unk083c,unk0840,unk0844,unk0848,unk084c,unk0850,unk0854,unk0858,unk085c,unk0860,unk0864,unk0868,unk086c,unk0870,unk0874,unk0878,unk087c,unk0880,unk0884,unk0888,unk088c,unk0890,unk0894,unk0898,unk089c,unk08a0,unk08a4,unk08a8,unk08ac,unk08b0,unk08b4,unk08b8,unk08bc,unk08c0,unk08c4,unk08c8,unk08cc,unk08d0,unk08d4,unk08d8,unk08dc,unk08e0,unk08e4,unk08e8,unk08ec,unk08f0,unk08f4,unk08f8,unk08fc,unk0900,unk0904,unk0908,unk090c,unk0910,unk0914,unk0918,unk091c,unk0920,unk0924,unk0928,unk092c,unk0930,unk0934,unk0938,unk093c,unk0940,unk0944,unk0948,unk094c,unk0950,unk0954,unk0958,unk095c,unk0960,unk0964,unk0968,unk096c,unk0970,unk0974,unk0978,unk097c,unk0980,unk0984,unk0988,unk098c,unk0990,unk0994,unk0998,unk099c,unk09a0,unk09a4,unk09a8,unk09ac,unk09b0,unk09b4,unk09b8,unk09bc,unk09c0,unk09c4,unk09c8,unk09cc,unk09d0,unk09d4,unk09d8,unk09dc,unk09e0,unk09e4,unk09e8,unk09ec,unk09f0,unk09f4,unk09f8,unk09fc,unk0a00,unk0a04,unk0a08,unk0a0c,unk0a10,unk0a14,unk0a18,unk0a1c,unk0a20,unk0a24,unk0a28,unk0a2c,unk0a30,unk0a34,unk0a38,unk0a3c,unk0a40,unk0a44,unk0a48,unk0a4c,unk0a50,unk0a54,unk0a58,unk0a5c,unk0a60,unk0a64,unk0a68,unk0a6c,unk0a70,unk0a74,unk0a78,unk0a7c,unk0a80,unk0a84,unk0a88,unk0a8c,unk0a90,unk0a94,unk0a98,unk0a9c,unk0aa0,unk0aa4,unk0aa8,unk0aac,unk0ab0,unk0ab4,unk0ab8,unk0abc,unk0ac0,unk0ac4,unk0ac8,unk0acc,unk0ad0,unk0ad4,unk0ad8,unk0adc,unk0ae0,unk0ae4,unk0ae8,unk0aec,unk0af0,unk0af4,unk0af8,unk0afc,unk0b00,unk0b04,unk0b08,unk0b0c,unk0b10,unk0b14,unk0b18,unk0b1c,unk0b20,unk0b24,unk0b28,unk0b2c,unk0b30,unk0b34,unk0b38,unk0b3c,unk0b40,unk0b44,unk0b48,unk0b4c,unk0b50,unk0b54,unk0b58,unk0b5c,unk0b60,unk0b64,unk0b68,unk0b6c,unk0b70,unk0b74,unk0b78,unk0b7c,unk0b80,unk0b84,unk0b88,unk0b8c,unk0b90,unk0b94,unk0b98,unk0b9c,unk0ba0,unk0ba4,unk0ba8,unk0bac,unk0bb0,unk0bb4,unk0bb8,unk0bbc,unk0bc0,unk0bc4,unk0bc8,unk0bcc,unk0bd0,unk0bd4,unk0bd8,unk0bdc,unk0be0,unk0be4,unk0be8,unk0bec,unk0bf0,unk0bf4,unk0bf8,unk0bfc,unk0c00,unk0c04,unk0c08,unk0c0c,unk0c10,unk0c14,unk0c18,unk0c1c,unk0c20,unk0c24,unk0c28,unk0c2c,unk0c30,unk0c34,unk0c38,unk0c3c,unk0c40,unk0c44,unk0c48,unk0c4c,unk0c50,unk0c54,unk0c58,unk0c5c,unk0c60,unk0c64,unk0c68,unk0c6c,unk0c70,unk0c74,unk0c78,unk0c7c,unk0c80,unk0c84,unk0c88,unk0c8c,unk0c90,unk0c94,unk0c98,unk0c9c,unk0ca0,unk0ca4,unk0ca8,unk0cac,unk0cb0,unk0cb4,unk0cb8,unk0cbc,unk0cc0,unk0cc4,unk0cc8,unk0ccc,unk0cd0,unk0cd4,unk0cd8,unk0cdc,unk0ce0,unk0ce4,unk0ce8,unk0cec,unk0cf0,unk0cf4,unk0cf8,unk0cfc,unk0d00,unk0d04,unk0d08,unk0d0c,unk0d10,unk0d14,unk0d18,unk0d1c,unk0d20,unk0d24,unk0d28,unk0d2c,unk0d30,unk0d34,unk0d38,unk0d3c,unk0d40,unk0d44,unk0d48,unk0d4c,unk0d50,unk0d54,unk0d58,unk0d5c,unk0d60,unk0d64,unk0d68,unk0d6c,unk0d70,unk0d74,unk0d78,unk0d7c,unk0d80,unk0d84,unk0d88,unk0d8c,unk0d90,unk0d94,unk0d98,unk0d9c,unk0da0,unk0da4,unk0da8,unk0dac,unk0db0,unk0db4,unk0db8,unk0dbc,unk0dc0,unk0dc4,unk0dc8,unk0dcc,unk0dd0,unk0dd4,unk0dd8,unk0ddc,unk0de0,unk0de4,unk0de8,unk0dec,unk0df0,unk0df4,unk0df8,unk0dfc,unk0e00,unk0e04,unk0e08,unk0e0c,unk0e10,unk0e14,unk0e18,unk0e1c,unk0e20,unk0e24,unk0e28,unk0e2c,unk0e30,unk0e34,unk0e38,unk0e3c,unk0e40,unk0e44,unk0e48,unk0e4c,unk0e50,unk0e54,unk0e58,unk0e5c,unk0e60,unk0e64,unk0e68,unk0e6c,unk0e70,unk0e74,unk0e78,unk0e7c,unk0e80,unk0e84,unk0e88,unk0e8c,unk0e90,unk0e94,unk0e98,unk0e9c,unk0ea0,unk0ea4,unk0ea8,unk0eac,unk0eb0,unk0eb4,unk0eb8,unk0ebc,unk0ec0,unk0ec4,unk0ec8,unk0ecc,unk0ed0,unk0ed4,unk0ed8,unk0edc,unk0ee0,unk0ee4,unk0ee8,unk0eec,unk0ef0,unk0ef4,unk0ef8,unk0efc,unk0f00,unk0f04,unk0f08,unk0f0c,unk0f10,unk0f14,unk0f18,unk0f1c,unk0f20,unk0f24,unk0f28,unk0f2c,unk0f30,unk0f34,unk0f38,unk0f3c,unk0f40,unk0f44,unk0f48,unk0f4c,unk0f50,unk0f54,unk0f58,unk0f5c,unk0f60,unk0f64,unk0f68,unk0f6c,unk0f70,unk0f74,unk0f78,unk0f7c,unk0f80,unk0f84,unk0f88,unk0f8c,unk0f90,unk0f94,unk0f98,unk0f9c,unk0fa0,unk0fa4,unk0fa8,unk0fac,unk0fb0,unk0fb4,unk0fb8,unk0fbc,unk0fc0,unk0fc4,unk0fc8,unk0fcc,unk0fd0,unk0fd4,unk0fd8,unk0fdc,unk0fe0,unk0fe4,unk0fe8,unk0fec,unk0ff0,unk0ff4,unk0ff8,unk0ffc,unk1000,unk1004,unk1008,unk100c,unk1010,unk1014,unk1018,unk101c,unk1020,unk1024,unk1028,unk102c,unk1030,unk1034,unk1038,unk103c,unk1040,unk1044,unk1048,unk104c,unk1050,unk1054,unk1058,unk105c,unk1060,unk1064,unk1068,unk106c,unk1070,unk1074,unk1078,unk107c,unk1080,unk1084,unk1088,unk108c,unk1090,unk1094,unk1098,unk109c,unk10a0,unk10a4,unk10a8,unk10ac,unk10b0,unk10b4,unk10b8,unk10bc,unk10c0,unk10c4,unk10c8,unk10cc,unk10d0,unk10d4,unk10d8,unk10dc,unk10e0,unk10e4,unk10e8,unk10ec,unk10f0,unk10f4,unk10f8,unk10fc,unk1100,unk1104,unk1108,unk110c,unk1110,unk1114,unk1118,unk111c,unk1120,unk1124,unk1128,unk112c,unk1130,unk1134,unk1138,unk113c,unk1140,unk1144,unk1148,unk114c,unk1150,unk1154,unk1158,unk115c,unk1160,unk1164,unk1168,unk116c,unk1170,unk1174,unk1178,unk117c,unk1180,unk1184,unk1188,unk118c,unk1190,unk1194,unk1198,unk119c,unk11a0,unk11a4,unk11a8,unk11ac,unk11b0,unk11b4,unk11b8,unk11bc,unk11c0,unk11c4,unk11c8,unk11cc,unk11d0,unk11d4,unk11d8,unk11dc,unk11e0,unk11e4,unk11e8,unk11ec,unk11f0,unk11f4,unk11f8,unk11fc,unk1200,unk1204,unk1208,unk120c,unk1210,unk1214,unk1218,unk121c,unk1220,unk1224,unk1228,unk122c,unk1230,unk1234,unk1238,unk123c,unk1240,unk1244,unk1248,unk124c,unk1250,unk1254,unk1258,unk125c,unk1260,unk1264,unk1268,unk126c,unk1270,unk1274,unk1278,unk127c,unk1280,unk1284,unk1288,unk128c,unk1290,unk1294,unk1298,unk129c,unk12a0,unk12a4,unk12a8,unk12ac,unk12b0,unk12b4,unk12b8,unk12bc,unk12c0,unk12c4,unk12c8,unk12cc,unk12d0,unk12d4,unk12d8,unk12dc,unk12e0,unk12e4,unk12e8,unk12ec,unk12f0,unk12f4,unk12f8,unk12fc,unk1300,unk1304,unk1308,unk130c,unk1310,unk1314,unk1318,unk131c,unk1320,unk1324,unk1328,unk132c,unk1330,unk1334,unk1338,unk133c,unk1340,unk1344,unk1348,unk134c,unk1350,unk1354,unk1358,unk135c,unk1360,unk1364,unk1368,unk136c,unk1370,unk1374,unk1378,unk137c,unk1380,unk1384,unk1388,unk138c,unk1390,unk1394,unk1398,unk139c,unk13a0,unk13a4,unk13a8,unk13ac,unk13b0,unk13b4,unk13b8,unk13bc,unk13c0,unk13c4,unk13c8,unk13cc,unk13d0,unk13d4,unk13d8,unk13dc,unk13e0,unk13e4,unk13e8,unk13ec,unk13f0,unk13f4,unk13f8,unk13fc,unk1400,unk1404,unk1408,unk140c,unk1410,unk1414,unk1418,unk141c,unk1420,unk1424,unk1428,unk142c,unk1430,unk1434,unk1438,unk143c,unk1440,unk1444,unk1448,unk144c,unk1450,unk1454,unk1458,unk145c,unk1460,unk1464,unk1468,unk146c,unk1470,unk1474,unk1478,unk147c,unk1480,unk1484,unk1488,unk148c,unk1490,unk1494,unk1498,unk149c,unk14a0,unk14a4,unk14a8,unk14ac,unk14b0,unk14b4,unk14b8,unk14bc,unk14c0,unk14c4,unk14c8,unk14cc,unk14d0,unk14d4,unk14d8,unk14dc,unk14e0,unk14e4,unk14e8,unk14ec,unk14f0,unk14f4,unk14f8,unk14fc,unk1500,unk1504,unk1508,unk150c,unk1510,unk1514,unk1518,unk151c,unk1520,unk1524,unk1528,unk152c,unk1530,unk1534,unk1538,unk153c,unk1540,unk1544,unk1548,unk154c,unk1550,unk1554,unk1558,unk155c,unk1560,unk1564,unk1568,unk156c,unk1570,unk1574,unk1578,unk157c,unk1580,unk1584,unk1588,unk158c,unk1590,unk1594,unk1598,unk159c,unk15a0,unk15a4,unk15a8,unk15ac,unk15b0,unk15b4,unk15b8,unk15bc,unk15c0,unk15c4,unk15c8,unk15cc,unk15d0,unk15d4,unk15d8,unk15dc,unk15e0,unk15e4,unk15e8,unk15ec,unk15f0,unk15f4,unk15f8,unk15fc,unk1600,unk1604,unk1608,unk160c,unk1610,unk1614,unk1618,unk161c,unk1620,unk1624,unk1628,unk162c,unk1630,unk1634,unk1638,unk163c,unk1640,unk1644,unk1648,unk164c,unk1650,unk1654,unk1658,unk165c,unk1660,unk1664,unk1668,unk166c,unk1670,unk1674,unk1678,unk167c,unk1680,unk1684,unk1688,unk168c,unk1690,unk1694,unk1698,unk169c,unk16a0,unk16a4,unk16a8,unk16ac,unk16b0,unk16b4,unk16b8,unk16bc,unk16c0,unk16c4;Row322 callbacks[256];};struct Context322{Root322*root;};struct Input322{unsigned char type,index;unsigned short unk02;unsigned int unk04,value08,unk0c,value10,value14,unk18,unk1c,data20,unk24,unk28,unk2c,data30;};
// pdb: hkAgentNnMachine_IsEntryOnTrack | hkpAgentNnMachine.obj | fnv360_0822_retail, objopen_prop, low, conflict (skyrim: hkAgentNnMachine_UpdateShapeCollectionFilter)
// pdb params: track, entry
void __cdecl FUN_00998570(Input322*input,Context322*context,void*user){void*data;switch(input->type){case 2:case 6:data=&input->data20;break;case 4:data=&input->data30;break;default:return;}Callback322 callback=context->root->callbacks[input->index].function;if(callback)callback(input,data,input->value10,input->value14,context,input->value08,user);}
}
}   // namespace f3m_00998570

// @f3 0x0099db10 (community match, verified in this file)
namespace f3m_0099db10 {
namespace n99db10 {
struct Vec4 {
    float x, y, z, w;
    Vec4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};
struct Mat { float m[3][5]; };
}
struct Obj99db10 {
    char pad[0xc0];
    n99db10::Vec4 v;
    void FUN_0099db10(const n99db10::Mat* m);
};
// pdb: hkpBoxMotion::applyForce | hkpBoxMotion.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpBoxMotion::setInertiaInvLocal)
// pdb params: deltaTime, force, p
void Obj99db10::FUN_0099db10(const n99db10::Mat* m)
{
    v.Set4(m->m[0][0], m->m[1][0], m->m[2][0], v.w);
}
}   // namespace f3m_0099db10

// @f3 0x0098ad90 (community match, verified in this file)
namespace f3m_0098ad90 {
namespace n98ad90 {
struct Info { char pad[0x12]; unsigned char flags; };
struct Body { char pad[0x28]; Info* info; };
}
struct Obj98ad90 {
    void hkpSimulationIsland_addCallbackRequest(n98ad90::Body* b, unsigned char f);
};
// pdb: hkpSimulationIsland::addCallbackRequest | hkpSimulationIsland.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Obj98ad90::hkpSimulationIsland_addCallbackRequest(n98ad90::Body* b, unsigned char f)
{
    b->info->flags |= f;
}
}   // namespace f3m_0098ad90

// @f3 0x00981740 (community match, verified in this file)
namespace f3m_00981740 {
struct O_981740 { char pad[0xe8]; int v; void hkpMultiThreadedSimulation_setMultithreadConfig(const int* p); };
// pdb: hkpMultiThreadedSimulation::setMultithreadConfig | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_open), high
void O_981740::hkpMultiThreadedSimulation_setMultithreadConfig(const int* p) { v = *p; }
}   // namespace f3m_00981740

// @f3 0x0098b600 (community match, verified in this file)
namespace f3m_0098b600 {
struct O_98b600 { int v; unsigned short w4; void FUN_0098b600(); };
// pdb: hkMultiThreadCheck::enableChecks | hkMultiThreadCheck.obj | fnv360_0822_retail, objopen_prop, medium
void O_98b600::FUN_0098b600() { if (v == -0x2f) { v = -15; w4 = 0; } }
}   // namespace f3m_0098b600

// @f3 0x0098b6f0 (community match, verified in this file)
namespace n98b6f0 {
struct Lock {
    int cs[6];
    int owner;
    int depth;
    void FUN_00908a00();
};
int __cdecl FUN_00984b00() throw();
 }
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
namespace n98b6f0 {
struct ScopedLock {
    Lock* lock;
    ScopedLock(Lock* l) : lock(l) { l->FUN_00908a00(); }
    ~ScopedLock() { lock->owner = -1; lock->depth = -1; LeaveCriticalSection(lock); }
};
}
extern n98b6f0::Lock* DAT_01169318;
struct FUN_0098b6f0_t {
    int id;
    unsigned short count;
    unsigned short bits;
    void FUN_0098b6f0();
};
void FUN_0098b6f0_t::FUN_0098b6f0() {
    if (id == -0x2f) return;
    n98b6f0::ScopedLock guard(DAT_01169318);
    int n = n98b6f0::FUN_00984b00();
    ++count;
    bits = bits * 2 | 1;
    if (id == -0xf) id = n;
}

// @f3 0x0099da40 (community match, verified in this file)
namespace f3m_0099da40 {
struct Matrix349{float values[16];};struct Owner349{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;float x,y,z,w;void Set(float a,float b,float c,const volatile float& d){x=a;y=b;z=c;w=d;}void FUN_0099da40(const Matrix349*);};
// pdb: hkpBoxMotion::setInertiaLocal | hkpBoxMotion.obj | tesv_win, objrun, medium
void Owner349::FUN_0099da40(const Matrix349*matrix){float second=1.0f/matrix->values[5];float third=1.0f/matrix->values[10];float fourth=w;Set(1.0f/matrix->values[0],second,third,fourth);}
}   // namespace f3m_0099da40

// @f3 0x00989b30 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00989b30 {
namespace n989b30 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long) throw();
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    __forceinline void clearAndDeallocate() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
        data = 0;
        size = 0;
        capAndFlags = (capAndFlags & 0xc0000000) | 0x80000000;
    }
};
}
struct FUN_00989b30_c {
    char pad[0x80];
    n989b30::Array<int> a80;
    n989b30::Array<int> a8c;
    void FUN_00989b30();
};
// pdb: hkpPhantom::deallocateInternalArrays | hkpPhantom.obj | fnv360_0822_retail, objrun_prop, low
void FUN_00989b30_c::FUN_00989b30()
{
    if (a80.size == 0)
        a80.clearAndDeallocate();
    if (a8c.size == 0)
        a8c.clearAndDeallocate();
}
}   // namespace f3m_00989b30

// @f3 0x0098a960 (community match, verified in this file)
namespace n98a960 {
extern unsigned long DAT_010f3170;
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
void* __cdecl FUN_00bffa60(void* dst, const void* src, unsigned int n);
struct SmallArray { void* data; unsigned short size; unsigned short capAndFlags; };
}
void __cdecl FUN_0098a960(n98a960::SmallArray* a, int cap, int elemSize)
{
    n98a960::Alloc* al = n98a960::FUN_00d9b080(n98a960::DAT_010f3170);
    void* p = al->FUN_008f6d30(cap * elemSize, 0x17);
    n98a960::FUN_00bffa60(p, a->data, a->size * elemSize);
    if ((a->capAndFlags & 0x8000) == 0) {
        int oldCap = a->capAndFlags & 0x3fff;
        n98a960::Alloc* al2 = n98a960::FUN_00d9b080(n98a960::DAT_010f3170);
        al2->FUN_008f6d90(a->data, oldCap * elemSize, 0x17);
    }
    a->data = p;
    a->capAndFlags = (unsigned short)((a->capAndFlags & 0x4000) | cap);
}

// @f3 0x0098b150 (community match, verified in this file)
namespace f3m_0098b150 {
struct Item_98b150 { int unk00; int unk04; int unk08; void* unk0C; };
struct Arr_98b150;
void __cdecl FUN_00901f10(Arr_98b150* a, int elemSize);
struct Arr_98b150 {
    Item_98b150** data;
    int count;
    unsigned int capacity;
    void Push(Item_98b150* x) {
        if (count == (int)(capacity & 0x3fffffff)) FUN_00901f10(this, 4);
        data[count] = x;
        count = count + 1;
    }
};
struct FUN_0098b150_T {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
    Arr_98b150 arr;
    void hkpSimulationIsland_addAction(Item_98b150* x);
};
// pdb: hkpSimulationIsland::addAction | hkpSimulationIsland.obj | fnv360_0822_retail, call_gap + bridge(call_gap_sim|call_seq) + skyrim(call_gap), high
void FUN_0098b150_T::hkpSimulationIsland_addAction(Item_98b150* x) {
    arr.Push(x);
    x->unk0C = this;
}
}   // namespace f3m_0098b150

// @f3 0x009819f0 (community match, verified in this file)
namespace f3m_009819f0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
struct CS_9819f0 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; };
struct Lock_9819f0 {
    CS_9819f0 cs;
    int unk18;
    int unk1C;
    void FUN_00908a00();
    void Leave() { unk18 = -1; unk1C = -1; LeaveCriticalSection(&cs); }
};
struct FUN_009819f0_T {
    int unk00[0x3b];
    int unkEC;
    int unkF0; int unkF4; int unkF8; int unkFC;
    Lock_9819f0 lock;
    int FUN_009819f0();
};
int FUN_009819f0_T::FUN_009819f0() {
    lock.FUN_00908a00();
    int id = unkEC;
    unkEC = id + 1;
    lock.Leave();
    return id;
}
}   // namespace f3m_009819f0

// @f3 0x0099f680 (community match, verified in this file)
namespace f3m_0099f680 {
struct V4_0099f680 { float x, y, z, w; };
struct O_0099f680 { char pad[0x20]; V4_0099f680 v; void FUN_0099f680(V4_0099f680* out); };
// pdb: hkpTriangleShape::getCentreImpl | hkpTriangleShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpTriangleShape::getFirstVertex)
// pdb params: centreOut
void O_0099f680::FUN_0099f680(V4_0099f680* out) { out->x = v.x; out->y = v.y; out->z = v.z; out->w = v.w; }
}   // namespace f3m_0099f680

// @f3 0x009814b0 (community match, verified in this file)
namespace n9814b0 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
}
struct Obj9814b0 {
    void* vtable;
    unsigned short memSize;
    unsigned short refCount;
    void FUN_0097f0f0();
    Obj9814b0* FUN_009814b0(unsigned int flags);
};
// pdb: hkpSimulation::`scalar deleting destructor' | hkpSimulation.obj | fnv360_0721_beta, vtable, high
Obj9814b0* Obj9814b0::FUN_009814b0(unsigned int flags)
{
    FUN_0097f0f0();
    if (flags & 1) {
        n9814b0::Alloc* al = n9814b0::FUN_00d9b080(n9814b0::DAT_010f3170);
        al->FUN_008f6d90(this, memSize, 0x15);
    }
    return this;
}

// @f3 0x0099efe0 (community match, verified in this file)
namespace f3m_0099efe0 {
namespace n99efe0 {
struct Collector {
    virtual void v00();
    virtual void beginObject(const char* name, int category, const void* object);
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void endObject();
};
}
struct Shape99efe0 {
    void FUN_0099efe0(n99efe0::Collector* c);
};
void Shape99efe0::FUN_0099efe0(n99efe0::Collector* c)
{
    c->beginObject("Collection", 1, this);
    c->endObject();
}
}   // namespace f3m_0099efe0

// @f3 0x00986ca0 (community match, verified in this file)
namespace f3m_00986ca0 {
namespace task1094{
struct Member{
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
virtual void Forward(int);};
struct Object{int unk00,unk04,unk08,unk0c,unk10;Member inner;void FUN_00986ca0(int);};
// pdb: hkpConstraintInfo::clear | hkpSimpleConstraintContactMgr.obj | fnv360_0822_debug, objopen_prop, low, conflict (skyrim: hkpSimpleConstraintContactMgr::toiCollisionResponseBeginCallback)
void Object::FUN_00986ca0(int a){inner.Forward(a);}
}
}   // namespace f3m_00986ca0

// @f3 0x0099d250 (community match, verified in this file)
namespace f3m_0099d250 {
namespace n99d250 {
struct RefObj {
    unsigned short memSize;
    short refCount;
    virtual ~RefObj() throw() {}
    void addReference() throw() { if (memSize != 0) ++refCount; }
    void removeReference() throw() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
}
struct C99d250 {
    char p00[0x118];
    n99d250::RefObj* ref;
    void FUN_0099d250(n99d250::RefObj* r);
};
// pdb: hkpKeyframedRigidMotion::setStoredMotion | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: savedMotion
void C99d250::FUN_0099d250(n99d250::RefObj* r)
{
    if (r) r->addReference();
    if (ref) ref->removeReference();
    ref = r;
}
}   // namespace f3m_0099d250

// @f3 0x009919f0 (community match, verified in this file)
namespace f3m_009919f0 {
namespace n9919f0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Pair { int a, b; };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    T& expandOne() {
        if (size == (capAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        return data[size++];
    }
};
struct Obj { int m0, m4, m8; int id; };
}
// pdb: hkp3AxisSweep::endOverlap | hkp3AxisSweep.obj | tesv_win, objrun_open, low
void __fastcall FUN_009919f0(n9919f0::Obj* a, n9919f0::Obj* b, n9919f0::Array<n9919f0::Pair>* arr)
{
    n9919f0::Pair& p = arr->expandOne();
    p.a = a->id;
    p.b = b->id;
}
}   // namespace f3m_009919f0

// @f3 0x009899a0 (community match, verified in this file)
namespace f3m_009899a0 {
namespace n9899a0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    void pushBack(const T& v) {
        if (size == (capAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = v;
        size++;
    }
};
}
struct C9899a0 {
    char p00[0x8c];
    n9899a0::Array<void*> items;
    void FUN_009899a0(void* item);
};
// pdb: hkpPhantom::addPhantomListener | hkpPhantom.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: el
void C9899a0::FUN_009899a0(void* item)
{
    items.pushBack(item);
}
}   // namespace f3m_009899a0

// @f3 0x00986610 (community match, verified in this file)
namespace f3m_00986610 {
namespace f3m_00986610 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00986610 { char pad[4]; unsigned short w; void FUN_009860f0(); O00986610* FUN_00986610(unsigned int flags); };
// pdb: hkpCollisionDispatcher::`scalar deleting destructor' | hkpCollisionDispatcher.obj | fnv360_0822_retail, vtable, high
O00986610* O00986610::FUN_00986610(unsigned int flags) { FUN_009860f0(); if (flags & 1) { f3m_00986610::T* t = (f3m_00986610::T*)f3m_00986610::DAT_00d9b080(f3m_00986610::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_00986610

// @f3 0x00986be0 (community match, verified in this file)
namespace f3m_00986be0 {
namespace f3m_00986be0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00986be0 { char pad[4]; unsigned short w; void FUN_00986640(); O00986be0* FUN_00986be0(unsigned int flags); };
// pdb: hkpReportContactMgr::`scalar deleting destructor' | hkpReportContactMgr.obj | fnv360_0721_beta, vtable_prefix, medium
O00986be0* O00986be0::FUN_00986be0(unsigned int flags) { FUN_00986640(); if (flags & 1) { f3m_00986be0::T* t = (f3m_00986be0::T*)f3m_00986be0::DAT_00d9b080(f3m_00986be0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x22); } return this; }
}   // namespace f3m_00986be0

// @f3 0x009860f0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long index);
namespace n9860f0 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };

void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
struct RefObj {
    unsigned short memSize;
    short refCount;
    virtual ~RefObj() throw() {}
    void removeReference() throw() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
struct Entity : RefObj {
    virtual void v4() throw(); virtual void v8() throw(); virtual void vc() throw();
    virtual void v10() throw();
};
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    void setSize(int n) throw() {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        size = n;
    }
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)::FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
}
struct FUN_009860f0 : n9860f0::RefObj {
    int m08;
    n9860f0::RefObj* grid[8][8];
    char pad[0x1e24 - 0x10c];
    n9860f0::Array<double> arr;
    void FUN_00985aa0() throw();
    virtual ~FUN_009860f0() throw();
};
// pdb: hkpCollisionDispatcher::~hkpCollisionDispatcher | hkpCollisionDispatcher.obj | fnv360_0822_retail, call_seq, high
FUN_009860f0::~FUN_009860f0() throw()
{
    FUN_00985aa0();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (grid[i][j])
                grid[i][j]->removeReference();
}

// @f3 0x00987c80 (community match, verified in this file)
namespace f3m_00987c80 {
namespace f3m_00987c80 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00987c80 { char pad[4]; unsigned short w; void FUN_00987c10(); O00987c80* FUN_00987c80(unsigned int flags); };
// pdb: hkpSimpleContactConstraintData::`scalar deleting destructor' | hkpSimpleConstraintContactMgr.obj | fnv360_0822_retail, vtable_prefix, high
O00987c80* O00987c80::FUN_00987c80(unsigned int flags) { FUN_00987c10(); if (flags & 1) { f3m_00987c80::T* t = (f3m_00987c80::T*)f3m_00987c80::DAT_00d9b080(f3m_00987c80::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2c); } return this; }
}   // namespace f3m_00987c80

// @f3 0x0098a930 (community match, verified in this file)
namespace f3m_0098a930 {
namespace f3m_0098a930 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0098a930 { char pad[4]; unsigned short w; void FUN_0098a0e0(); O0098a930* FUN_0098a930(unsigned int flags); };
// pdb: hkpPhysicsSystem::`scalar deleting destructor' | hkpPhysicsSystem.obj | fnv360_0822_retail, vtable, high
O0098a930* O0098a930::FUN_0098a930(unsigned int flags) { FUN_0098a0e0(); if (flags & 1) { f3m_0098a930::T* t = (f3m_0098a930::T*)f3m_0098a930::DAT_00d9b080(f3m_0098a930::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2f); } return this; }
}   // namespace f3m_0098a930

// @f3 0x0098c150 (community match, verified in this file)
namespace f3m_0098c150 {
namespace f3m_0098c150 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0098c150 { char pad[4]; unsigned short w; void FUN_0098bbd0(); O0098c150* FUN_0098c150(unsigned int flags); };
// pdb: hkpBroadPhaseBorder::`scalar deleting destructor' | hkpBroadPhaseBorder.obj | fnv360_0822_retail, vtable, high
O0098c150* O0098c150::FUN_0098c150(unsigned int flags) { FUN_0098bbd0(); if (flags & 1) { f3m_0098c150::T* t = (f3m_0098c150::T*)f3m_0098c150::DAT_00d9b080(f3m_0098c150::DAT_010f3170); t->FUN_008f6d90(this, w, 0xd); } return this; }
}   // namespace f3m_0098c150

// @f3 0x00990520 (community match, verified in this file)
namespace f3m_00990520 {
namespace f3m_00990520 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00990520 { char pad[4]; unsigned short w; void FUN_0098d990(); O00990520* FUN_00990520(unsigned int flags); };
// pdb: hkpContinuousSimulation::`scalar deleting destructor' | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable_prefix, high
O00990520* O00990520::FUN_00990520(unsigned int flags) { FUN_0098d990(); if (flags & 1) { f3m_00990520::T* t = (f3m_00990520::T*)f3m_00990520::DAT_00d9b080(f3m_00990520::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_00990520

// @f3 0x00989600 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d96c[];
extern const char DAT_00e32798[];
namespace f3m_00989600 {
namespace n989600 {
struct Item {
    virtual void v0();
    virtual void Run(void* a, void* b);
};
struct Rec { const void* label; unsigned int ticks; unsigned int unk08; 
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};
struct Buf { int unk00; Rec* cur; int unk08; Rec* end; };
extern Buf* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Arr { Item** data; int count; };
static __declspec(noinline) void FUN_00988440(Arr* arr) {
 for(int i=arr->count-1;i>=0;--i) if(!arr->data[i]) {
 --arr->count;
 for(int j=i;j<arr->count;++j) arr->data[j]=arr->data[j+1];
 }
}
struct Container { unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c; unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17c; Arr arr; };
}
// pdb: hkpWorldCallbackUtil::fireContactImpulseLimitBreached | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(n989600::Container* self, void* a, void* b)
{
    n989600::Arr* arr = &self->arr;
    int i = arr->count - 1;
    if (i >= 0) {
        n989600::Buf* (__stdcall* getter)(unsigned long) = n989600::DAT_00d9b080;
        do {
            if (arr->data[i] != 0) {
                n989600::Buf* buf = getter(DAT_0116913c);
                n989600::Rec* r = buf->cur;
                if (r < buf->end) {
                    r->label = DAT_00e7d96c;
                    _ReadWriteBarrier();
                    r->setTime();
                    buf->cur = r + 1;
                }
                arr->data[i]->Run(a, b);
                buf = getter(DAT_0116913c);
                r = buf->cur;
                if (r < buf->end) {
                    r->label = DAT_00e32798;
                    _ReadWriteBarrier();
                    r->setTime();
                    buf->cur = r + 1;
                }
            }
        } while (--i >= 0);
    }
    n989600::FUN_00988440(arr);
}
}   // namespace f3m_00989600

// @f3 0x009893f0 (community match, verified in this file)
typedef unsigned long DWORD; typedef void* LPVOID;

extern DWORD DAT_0116913c;
extern LPVOID(__stdcall* DAT_00d9b080)(DWORD);
extern const char DAT_00e7d95c[];
extern const char DAT_00e32798[];

unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

struct ListenerOwner;

class ListenerObj
{
  public:
    virtual void v00(void);
    virtual void v03(ListenerOwner* pEvent, void* arg);
};

struct ListenerOwner;

struct ListenerArray
{
    ListenerObj** m_ppItems;
    int m_wCount;
};

struct ListenerOwner
{
        DWORD unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    DWORD unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    DWORD unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    DWORD unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    DWORD unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    DWORD unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    DWORD unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    DWORD unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    DWORD unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    DWORD unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    DWORD unk140, unk144, unk148, unk14c;
    ListenerArray m_kListeners;
};

static __declspec(noinline) void FUN_00988440(ListenerArray* pArr)
{
    for (int i = (int)pArr->m_wCount - 1; i >= 0; i--)
    {
        if (pArr->m_ppItems[i] == 0)
        {
            pArr->m_wCount--;
            for (int j = i; j < (int)pArr->m_wCount; j++)
                pArr->m_ppItems[j] = pArr->m_ppItems[j + 1];
        }
    }
}

// Invokes v03 on each non-null listener in pOwner->m_kListeners with pOwner, logging start and end ticks, then compacts the array.
// @fnv 0x00d85ef0
// pdb: hkpWorldCallbackUtil::firePostCollideCallback | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap), high
void __cdecl hkpWorldCallbackUtil_firePostCollideCallback(ListenerOwner* pOwner, void* arg)
{
    volatile DWORD ticks[2];
    ListenerArray* pArr = &pOwner->m_kListeners;
    int i = (int)pArr->m_wCount - 1;
    if (i >= 0)
    {
        LPVOID(__stdcall * pfnTls)(DWORD) = DAT_00d9b080;
        do
        {
            if (pArr->m_ppItems[i] != 0)
            {
                ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0116913c);
                ProfRec* cur = pBuf->m_pCur;
                if (cur < pBuf->m_pRecordEnd)
                {
                    cur->m_pName = DAT_00e7d95c;
                    _ReadWriteBarrier();
                    ticks[0] = (DWORD)__rdtsc();
                    cur->m_iTick = ticks[0];
                    cur++;
                    pBuf->m_pCur = cur;
                }
                pArr->m_ppItems[i]->v03(pOwner,arg);
                pBuf = (ProfBuf*)pfnTls(DAT_0116913c);
                cur = pBuf->m_pCur;
                if (cur < pBuf->m_pRecordEnd)
                {
                    cur->m_pName = DAT_00e32798;
                    _ReadWriteBarrier();
                    ticks[1] = (DWORD)__rdtsc();
                    cur->m_iTick = ticks[1];
                    cur++;
                    pBuf->m_pCur = cur;
                }
            }
            i--;
        } while (i >= 0);
    }
    FUN_00988440(pArr);
}

// @f3 0x00989550 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern char str_00e7d95c[], str_00e32798[];
namespace f3m_00989550 {
namespace fnv_00d00060 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*, ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireIslandPostCollideCallback | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap + bridge(ustr_rel|call_dedup) + skyrim(ustr_rel), high
void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(World833* world, ContactPointEvent* first, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833(str_00e7d95c, beginTicks);
            listeners.data[i]->newCollisionCallback(first, event);
            TimerEvent833(str_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}
}   // namespace f3m_00989550

// @f3 0x00996fd0 (community match, verified in this file)
namespace f3m_00996fd0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_996fd0 { void* FUN_008f6d30(int size, int kind); };
struct Hdr_996fd0 { int unk00; unsigned short unk04; };
class Obj_996fd0 {
public:
    int unk00;
    unsigned short unk04;
    Obj_996fd0(int a, int b, int c) throw();
    static void* operator new(unsigned int size) {
        Pool_996fd0* pool = (Pool_996fd0*)DAT_00d9b080(DAT_010f3170);
        Hdr_996fd0* p = (Hdr_996fd0*)pool->FUN_008f6d30(0xe0, 0x21);
        p->unk04 = 0xe0;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hk3AxisSweep16CreateBroadPhase | hkp3AxisSweep.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: worldMin, worldMax, numMarkers
Obj_996fd0* __cdecl FUN_00996fd0(int a, int b, int c) {
    return new Obj_996fd0(a, b, c);
}
}   // namespace f3m_00996fd0

// @f3 0x0098d4e0 (community match, verified in this file)
namespace f3m_0098d4e0 {
struct SubD4E0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    float f40, f44, f48;
    volatile float f4c;
    float f50, f54, f58, f5c;
    float f60, f64, f68, f6c;
    float f70, f74, f78, f7c;
};

struct ItemD4E0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void* unk18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    SubD4E0 sub;
};

struct SrcD4E0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void* unk18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    ItemD4E0** items;
    int count;
};

struct ArrD4E0 {
    ItemD4E0** data;
    int count;
    unsigned int capacity;
};

struct CtxD4E0 {
    int unk00, unk04;
    void* unk08;
    float FUN_009022e0();
};

void __cdecl hkSweptTransformUtil_backStepMotionState(float time, void* sub);
void __cdecl FUN_00901f10(ArrD4E0* arr, int elementSize);

// pdb: hkLs_backstepAndFreezeEntireIsland | hkpContinuousSimulation.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: time, island, entityState, activeEntities
void __cdecl FUN_0098d4e0(float time, SrcD4E0* src, unsigned char** flags, ArrD4E0* out)
{
    for (int i = 0; i < src->count; i++) {
        ItemD4E0* item = src->items[i];
        SubD4E0* sub = &item->sub;
        hkSweptTransformUtil_backStepMotionState(time, sub);
        if ((*flags)[i] != 0x10) {
            if (out->count == (int)(out->capacity & 0x3fffffffu))
                FUN_00901f10(out, 4);
            out->data[out->count] = item;
            out->count = out->count + 1;
            (*flags)[i] = 0x10;
        }
        sub->f40 = sub->f50;
        sub->f44 = sub->f54;
        sub->f48 = sub->f58;
        sub->f4c = sub->f5c;
        sub->f60 = sub->f70;
        sub->f64 = sub->f74;
        sub->f68 = sub->f78;
        sub->f6c = sub->f7c;
        sub->f4c = time;
        float p = ((CtxD4E0*)src->unk18)->FUN_009022e0();
        sub->f5c = 1.0f / (p - time);
    }
}
}   // namespace f3m_0098d4e0

// @f3 0x0099e540 (community match, verified in this file)
namespace f3m_0099e540 {
struct Vec4f { float x, y, z, w; };

struct Obj99e540 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Vec4f m_row0;
    Vec4f m_row1;
    Vec4f m_row2;
    void FUN_0099e540(const float* v);
};

void Obj99e540::FUN_0099e540(const float* v)
{
    const Vec4f& r0 = m_row0;
    Vec4f& r2 = m_row2;
    r2.x = r0.x * v[0] + r2.x;
    r2.y = r0.y * v[1] + r2.y;
    r2.z = r0.z * v[2] + r2.z;
    r2.w = r0.w * v[3] + r2.w;
}
}   // namespace f3m_0099e540

// @f3 0x00985040 (community match, verified in this file)
extern "C" int FUN_00e34ac8;
extern "C" int FUN_00dcc494;
extern unsigned long DAT_010f3170;
namespace f3m_00985040 {

extern void* (__stdcall *DAT_00d9b080)(unsigned long);

struct Heap985040 {
    void FUN_008f6d90(int, int, int);
};

struct Object985040 {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;

    unsigned int* FUN_00985040(unsigned char flag);
};

// pdb: hkpNullBroadPhaseListener::`scalar deleting destructor' | hkpTypedBroadPhaseDispatcher.obj | fnv360_0721_beta, vtable, medium
unsigned int* Object985040::FUN_00985040(unsigned char flag)
{
    unsigned int* target = this ? &this->unk08 : 0;
    *target = (unsigned int)&FUN_00e34ac8;
    this->unk00 = (unsigned int)&FUN_00dcc494;

    if ((flag & 1) != 0) {
        Heap985040* heap =
            static_cast<Heap985040*>(DAT_00d9b080(DAT_010f3170));
        heap->FUN_008f6d90(
            (int)this,
            (int)this->unk04,
            0x27);
    }

    return (unsigned int*)this;
}
}   // namespace f3m_00985040

// @f3 0x0099e700 (community match, verified in this file)
namespace f3m_0099e700 {
class Base99e700 {
public:
    Base99e700(int a, int b);
    virtual ~Base99e700();
    int f4;
    unsigned char type;
};
class Obj99e700 : public Base99e700 {
public:
    Obj99e700(int a, int b);
    virtual ~Obj99e700();
};
// pdb: hkpThinBoxMotion::hkpThinBoxMotion | hkpThinBoxMotion.obj | fnv360_0822_retail, caller_sim, low
// pdb params: position, rotation
Obj99e700::Obj99e700(int a, int b) : Base99e700(a, b)
{
    type = 8;
}
}   // namespace f3m_0099e700

// @f3 0x0099f010 (community match, verified in this file)
namespace f3m_0099f010 {
namespace f3m_0099f010 {

struct __declspec(novtable) Base {
    virtual void V0();
    unsigned short unk4;
    unsigned short unk6;
    int unk8;
    int unkc;
    Base(int a) : unk6(1), unk8(0), unkc(a) {}
};

struct Interface {
    virtual void V1();
    Interface() {}
};

struct Node : Base, Interface {
    bool unk14;
    Node(int a);
    virtual void V0();
    virtual void V1();
};

// pdb: hkpShapeCollection::hkpShapeCollection | hkpShapeCollection.obj | fnv360_0822_retail, call_seq, high
// pdb params: type, subType
Node::Node(int a) : Base(a) {
    unk14 = false;
}

}
}   // namespace f3m_0099f010

// @f3 0x0099ef50 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0099ef50 {
namespace n99ef50 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern Heap* (__stdcall* const FUN_00d9b080)(unsigned long);
class Base {
public:
    unsigned short memSizeAndFlags;
    short refCount;
    virtual ~Base();
};
}
struct FUN_0099ef50 : n99ef50::Base {
    static void* operator new(unsigned int n);
    // pdb: hkpSimpleShapePhantom::`scalar deleting destructor' | hkpSimpleShapePhantom.obj | fnv360_0822_retail, vtable_prefix, high
    static void operator delete(void* p) {
        FUN_0099ef50* o = static_cast<FUN_0099ef50*>(p);
        n99ef50::Heap* h = n99ef50::FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 0x31);
    }
};
void* Make99ef50() { return new FUN_0099ef50; }
}   // namespace f3m_0099ef50

// @f3 0x0098b740 (community match, verified in this file)
namespace f3m_0098b740 {
namespace n98b740 {
struct Lock {
    int cs[6];
    int owner;
    int depth;
    void FUN_00908a00();
};
int __cdecl FUN_00984b00() throw();
 }
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
namespace n98b740 {
struct ScopedLock {
    Lock* lock;
    ScopedLock(Lock* l) : lock(l) { l->FUN_00908a00(); }
    ~ScopedLock() { lock->owner = -1; lock->depth = -1; LeaveCriticalSection(lock); }
};
}
extern n98b740::Lock* DAT_01169318;
struct FUN_0098b740_t {
    int id;
    bool FUN_0098b740();
};
bool FUN_0098b740_t::FUN_0098b740() {
    if (id == -0x2f) return true;
    n98b740::ScopedLock guard(DAT_01169318);
    if (id == n98b740::FUN_00984b00())
        return true;
    return false;
}
}   // namespace f3m_0098b740

// @f3 0x0098a090 (community match, verified in this file)
namespace f3m_0098a090 {
namespace physics_system_ctor {
struct hkBaseObject { virtual ~hkBaseObject() throw(); };
struct hkReferencedObject : hkBaseObject { unsigned short memorySizeAndFlags,referenceCount; __forceinline hkReferencedObject() throw():referenceCount(1){} };
template<class T> struct Array { T* data;int count;unsigned int capacityAndFlags; __forceinline Array() throw():data(0),count(0),capacityAndFlags(0x80000000u){} };
struct hkpRigidBody;struct hkpConstraintInstance;struct hkpAction;struct hkpPhantom;
struct hkpPhysicsSystem : hkReferencedObject {
 Array<hkpRigidBody*> rigidBodies;Array<hkpConstraintInstance*> constraints;Array<hkpAction*> actions;Array<hkpPhantom*> phantoms;
 const char* name;unsigned int userData;bool active;
 hkpPhysicsSystem() throw();
};
// pdb: hkpPhysicsSystem::hkpPhysicsSystem | hkpPhysicsSystem.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkStringPtr::operator=)
hkpPhysicsSystem::hkpPhysicsSystem() throw() { name=0;userData=0;active=true; }
}
}   // namespace f3m_0098a090

// @f3 0x00984160 (community match, verified in this file)
namespace f3m_00984160 {
namespace null_collision_filter_dtor {
struct hkBaseObject { virtual ~hkBaseObject() throw(); };
struct hkReferencedObject : hkBaseObject { unsigned short memorySizeAndFlags,referenceCount; };
struct hkpCollidableCollidableFilter { virtual ~hkpCollidableCollidableFilter() throw(); };
struct hkpShapeCollectionFilter { virtual ~hkpShapeCollectionFilter() throw(); };
struct hkpRayShapeCollectionFilter { virtual ~hkpRayShapeCollectionFilter() throw(); };
struct hkpRayCollidableFilter { virtual ~hkpRayCollidableFilter() throw(); };
struct hkpCollisionFilter : hkReferencedObject,hkpCollidableCollidableFilter,hkpShapeCollectionFilter,hkpRayShapeCollectionFilter,hkpRayCollidableFilter { virtual ~hkpCollisionFilter() throw(); };
struct hkpNullCollisionFilter : hkpCollisionFilter { virtual ~hkpNullCollisionFilter() throw(); };
hkpNullCollisionFilter::~hkpNullCollisionFilter() throw() {}
}
}   // namespace f3m_00984160

// @f3 0x0098a040 (community match, verified in this file)
namespace f3m_0098a040 {
namespace f3m_0098a040 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Ref { int u0; unsigned short w4; unsigned short w6; };
struct Arr {
    Ref** data; int size; unsigned int capFlags;
    void Push(Ref* r) {
        if (size == (int)(capFlags & 0x3fffffff)) FUN_00901f10(this, 4);
        data[size] = r;
        size = size + 1;
    }
};
struct O { char pad[0x20]; Arr arr; void FUN_0098a040(Ref* r); };
// pdb: hkpPhysicsSystem::addAction | hkpPhysicsSystem.obj | fnv360_0822_retail, call_seq, medium, conflict (bridge: enumerateAllConstraintsInIsland)
// pdb params: a
void O::FUN_0098a040(Ref* r) {
    if (r) {
        if (r->w4) ++r->w6;
        arr.Push(r);
    }
}
}
}   // namespace f3m_0098a040

// @f3 0x00989860 (community match, verified in this file)
namespace f3m_00989860 {
namespace task1295 {
struct Owner;struct Listener {virtual void v0();virtual void Removed(Owner*);};
struct Array {Listener**data;int count;unsigned capacity;Listener** operator[](int i){return data+i;}};
static __declspec(noinline) void FUN_00989760(Array*a){for(int i=a->count-1;i>=0;--i){if(a->data[i]==0){--a->count;for(int j=i;j<a->count;++j)a->data[j]=a->data[j+1];}}}
struct Owner {
unsigned u0;
unsigned u4;
unsigned u8;
unsigned uc;
unsigned u10;
unsigned u14;
unsigned u18;
unsigned u1c;
unsigned u20;
unsigned u24;
unsigned u28;
unsigned u2c;
unsigned u30;
unsigned u34;
unsigned u38;
unsigned u3c;
unsigned u40;
unsigned u44;
unsigned u48;
unsigned u4c;
unsigned u50;
unsigned u54;
unsigned u58;
unsigned u5c;
unsigned u60;
unsigned u64;
unsigned u68;
unsigned u6c;
unsigned u70;
unsigned u74;
unsigned u78;
unsigned u7c;
unsigned u80;
unsigned u84;
unsigned u88;
Array listeners;void FUN_00989860();};
// pdb: hkpPhantom::firePhantomAdded | hkpPhantom.obj | tesv_win, call_gap, low
void Owner::FUN_00989860(){for(int i=listeners.count-1;i>=0;--i){if(*listeners[i])(*listeners[i])->Removed(this);}FUN_00989760(&listeners);}
}
}   // namespace f3m_00989860

// @f3 0x0098aea0 (community match, verified in this file)
namespace f3m_0098aea0 {
namespace f3m_0098aea0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct O;
struct Child { char pad[0x94]; unsigned short idx; char pad2[0x22]; O* owner; };
struct Arr {
    Child** data; int size; unsigned int capFlags;
    void Push(Child* c) {
        if (size == (int)(capFlags & 0x3fffffff)) FUN_00901f10(this, 4);
        data[size] = c;
        size = size + 1;
    }
};
struct O { char pad[0x48]; Arr arr; void FUN_0098aea0(Child* c); };
// pdb: hkpSimulationIsland::internalAddEntity | hkpSimulationIsland.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkpEntity::setCachedShapeData)
// pdb params: entity
void O::FUN_0098aea0(Child* c) {
    c->owner = this;
    c->idx = (unsigned short)arr.size;
    arr.Push(c);
}
}
}   // namespace f3m_0098aea0

// @f3 0x009984a0 (community match, verified in this file)
namespace f3m_009984a0 {
struct V4_9984a0 { float x, y, z, w; };
struct O_9984a0 { char pad[0x70]; V4_9984a0 a; V4_9984a0 b; void FUN_009984a0(V4_9984a0* oa, V4_9984a0* ob); };
void O_9984a0::FUN_009984a0(V4_9984a0* oa, V4_9984a0* ob) {
    oa->x = a.x; oa->y = a.y; oa->z = a.z; oa->w = a.w;
    ob->x = b.x; ob->y = b.y; ob->z = b.z; ob->w = b.w;
}
}   // namespace f3m_009984a0

// @f3 0x0099e160 (community match, verified in this file)
namespace f3m_0099e160 {
struct Sub_99e160 { int u0, u1, u2, u3; void FUN_008f8720(const Sub_99e160* src); };
struct Dst_99e160 {
    char pad[0x10]; Sub_99e160 sub; char pad2[0xb0];
    float fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec;
};
struct O_99e160 { char pad[0x10]; Sub_99e160 sub; void FUN_0099e160(Dst_99e160* d); };
// pdb: hkpFixedRigidMotion::getPositionAndVelocities | hkpFixedRigidMotion.obj | tesv_win, caller_sim, low
void O_99e160::FUN_0099e160(Dst_99e160* d) {
    d->sub.FUN_008f8720(&sub);
    d->fdc = 0.0f; d->fd8 = 0.0f; d->fd4 = 0.0f; d->fd0 = 0.0f;
    d->fec = 0.0f; d->fe8 = 0.0f; d->fe4 = 0.0f; d->fe0 = 0.0f;
}
}   // namespace f3m_0099e160

// @f3 0x0098c550 (community match, verified in this file)
extern const char DAT_00e7db0c[];extern const char DAT_00e7daf8[];extern int DAT_0116b504;
namespace f3m_0098c550 {
struct Tracker9855 { virtual void slot0(); virtual void slot1(); virtual void array(const char*,int,void*,int,int); virtual void value(const char*,int,int); };
struct Owner9855 {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;void* data;int count;int capacity;int value;void hkReferencedObject_calcContentStatistics(Tracker9855*,int*);void hkpContinuousSimulation_calcContentStatistics(Tracker9855*,int);};
// pdb: hkpContinuousSimulation::calcContentStatistics | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
void Owner9855::hkpContinuousSimulation_calcContentStatistics(Tracker9855* t,int){if(!(capacity&0x80000000))t->array(DAT_00e7db0c,2,data,count*112,(capacity&0x3fffffff)*112);t->value(DAT_00e7daf8,2,value);hkReferencedObject_calcContentStatistics(t,&DAT_0116b504);}
}   // namespace f3m_0098c550

// @f3 0x00981a30 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d300[],DAT_00e32798[];
namespace f3m_00981a30 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Event981 {const char* name;unsigned int ticks;int unk08;
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};
struct Monitor981 {int unk00;Event981* current;int unk08;Event981* end;};
struct Input981 {int type;};
struct Owner981 {void FUN_009817a0(int);void FUN_00981a30(Input981*);};
void Owner981::FUN_00981a30(Input981* input){
 Monitor981* mon=(Monitor981*)TlsGetValue(DAT_0116913c);
 if(mon->current<mon->end){Event981* event=mon->current;event->name=DAT_00e7d300;
 event->setTime();mon->current=event+1;}
 int type=input->type;
 if(type==0) FUN_009817a0(2);else if(type==1) FUN_009817a0(type);else FUN_009817a0(0);
 mon=(Monitor981*)TlsGetValue(DAT_0116913c);
 if(mon->current<mon->end){Event981* event=mon->current;event->name=DAT_00e32798;
 event->setTime();mon->current=event+1;}
}
}   // namespace f3m_00981a30

// @f3 0x00989fb0 (community match, verified in this file)
namespace f3m_00989fb0 {
struct Element9fb { void FUN_009316e0(); };
struct Array9fb { Element9fb** data; int size; unsigned capacity; };
void __cdecl FUN_00901f10(Array9fb*,int);
struct Owner9fb { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; Array9fb array; void FUN_00989fb0(Element9fb*); };
// pdb: hkpPhysicsSystem::addPhantom | hkpPhysicsSystem.obj | fnv360_0822_retail, caller, medium, conflict (bridge: hkpPhysicsSystem::addRigidBody)
// pdb params: p
void Owner9fb::FUN_00989fb0(Element9fb* element) {
if(element) {element->FUN_009316e0();
Array9fb* a=&array;
if(a->size == (a->capacity & 0x3fffffff)) FUN_00901f10(a,4);
a->data[a->size]=element; ++a->size;
}}
}   // namespace f3m_00989fb0

// @f3 0x00985230 (community match, verified in this file)
namespace f3m_00985230 {
struct MatrixRefNode { virtual ~MatrixRefNode(); unsigned short memoryFlags; short refs; void AddRef(){if(memoryFlags)++refs;} void Release(){if(memoryFlags){--refs;if(refs==0)delete this;}} };
struct MatrixRef { MatrixRefNode* p; void operator=(MatrixRefNode* n){n->AddRef();p->Release();p=n;} };
struct RefMatrix { int unk00,unk04,unk08; MatrixRef nodes[8][8]; void hkpCollisionDispatcher_registerContactMgrFactory(MatrixRefNode*,int,int); };
// pdb: hkpCollisionDispatcher::registerContactMgrFactory | hkpCollisionDispatcher.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void RefMatrix::hkpCollisionDispatcher_registerContactMgrFactory(MatrixRefNode* node,int index,int group) { node->AddRef(); MatrixRef* slot = &nodes[group][index]; slot->p->Release();slot->p=node;node->AddRef();slot=&nodes[index][group];slot->p->Release();slot->p=node; }
}   // namespace f3m_00985230

// @f3 0x0098c100 (community match, verified in this file)
namespace f3m_0098c100 {
namespace w98c100 {
struct Shape { int unk00; int unk04; int unk08; int unk0c; signed char offset; unsigned char unk11,unk12,unk13; int unk14; unsigned char type; };
struct Argument { int unk00; Shape* shape; };
struct Handler { void FUN_0098c100(Argument*); };
struct Owner { void** table; int unk04,unk08; Handler handler; };
// pdb: hkpBroadPhaseBorder::operator delete | hkpBroadPhaseBorder.obj | fnv360_0822_debug, objrun_sim, low, conflict (skyrim: hkpBroadPhaseBorder::collidableAddedCallback)
// pdb params: p
void Handler::FUN_0098c100(Argument* arg) {
 Shape* shape=arg->shape;
 if(shape->type==1) {
  void* p=reinterpret_cast<char*>(shape)+shape->offset;
  if(p) {
   Owner* owner=reinterpret_cast<Owner*>(reinterpret_cast<char*>(this)-12);
   ((void(__thiscall*)(Owner*,void*))owner->table[3])(owner,p);
  }
 }
}
}
}   // namespace f3m_0098c100

// @f3 0x00983540 (community match, verified in this file)
namespace w983540 {
struct Lock;
extern Lock DAT_011692e8;
extern void (__stdcall* DAT_00d9b0a0)(Lock*);
extern int (__stdcall* DAT_00d9b1ac)(Lock*,unsigned);
struct Lock { int unk00,unk04,unk08,unk0c,unk10,unk14; int unk18,unk1c; unsigned spin; Lock* prev; Lock* next;
 void FUN_00908a00();
 __forceinline Lock():spin(4000),prev(0),next(0) {
  DAT_011692e8.FUN_00908a00(); next=DAT_011692e8.next;
  if(next) next->prev=this;
  prev=&DAT_011692e8; DAT_011692e8.next=this;
  DAT_011692e8.unk18=-1; DAT_011692e8.unk1c=-1;
  DAT_00d9b0a0(&DAT_011692e8); DAT_00d9b1ac(this,4000);
  unk18=-1; unk1c=-1;
 }
};
struct Array { void* data; int count,capacity; __forceinline Array():data(0),count(0),capacity(0x80000000) {} };
struct FUN_00983540 { Array first; int value; Array second; int unk1c; Lock lock; FUN_00983540(int); };
// pdb: hkpWorldOperationQueue::hkpWorldOperationQueue | hkpWorldOperationQueue.obj | fnv360_0822_retail, call_gap, low
// pdb params: world
FUN_00983540::FUN_00983540(int v) { value=v; }
}

// @f3 0x00981750 (community match, verified in this file)
namespace f3m_00981750 {
namespace motion_flag_wrapper {
struct Motion {void FUN_00a21470(int);};
struct Owner {
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
 Motion motion;void FUN_00981750(int enabled);
};
void Owner::FUN_00981750(int enabled){if(enabled==0){motion.FUN_00a21470(0);return;}motion.FUN_00a21470(2);}
}
}   // namespace f3m_00981750

// @f3 0x00988dc0 (community match, verified in this file)
extern const char DAT_00e7d8f8[],DAT_00e32798[];
namespace f3m_00988dc0 {
namespace visit988 {
extern unsigned long DAT_0116913c;extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Event {const char* tag;unsigned ticks;int unk08;
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};struct Monitor {int unk00;Event* current;int unk08;Event* end;};
struct Out {int unk00,unk04,unk08;};struct Elem {virtual void V0();virtual void V4();virtual void V8();virtual void Visit(Out*);};
struct List {Elem** data;int size,capacity;};
static __declspec(noinline) void FUN_00988440(List* list){for(int i=list->size-1;i>=0;--i){if(!list->data[i]){--list->size;for(int j=i;j<list->size;++j)list->data[j]=list->data[j+1];}}}
struct Owner {int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; List list;};
// pdb: hkpWorldCallbackUtil::fireContactProcess | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkpWorldCallbackUtil_fireContactProcess(Owner* owner,Out* out){List* list=&owner->list;out->unk08=0;int i=list->size-1;if(i>=0){void* (__stdcall *tls)(unsigned long)=DAT_00d9b080;do{if(list->data[i]){
 Monitor* m=(Monitor*)tls(DAT_0116913c);
 if(m->current<m->end){Event* event=m->current;event->tag=DAT_00e7d8f8;event->setTime();m->current=event+1;}
 list->data[i]->Visit(out);
 m=(Monitor*)tls(DAT_0116913c);
 if(m->current<m->end){Event* event=m->current;event->tag=DAT_00e32798;event->setTime();m->current=event+1;}
 }}while(--i>=0);}FUN_00988440(list);}
}
}   // namespace f3m_00988dc0

// @f3 0x0098c180 (community match, verified in this file)
namespace f3m_0098c180 {
namespace Q98C { struct Owner; struct Factory; extern char DAT_00e7dad0; struct FactoryOps { void* unk00; void (__thiscall *begin)(Factory*,void*,int,Owner*); void* unk08; void* unk0c; void* unk10; void* unk14; void (__thiscall *finish)(Factory*); }; struct OwnerOps { void* unk00; void* unk04; void (__thiscall *load)(Owner*,Factory*,int); }; struct Factory {FactoryOps* ops;}; struct Owner {OwnerOps* ops; void FUN_0098c180(Factory*);};
void Owner::FUN_0098c180(Factory* f) { f->ops->begin(f,&DAT_00e7dad0,2,this); ops->load(this,f,0); f->ops->finish(f); } }
}   // namespace f3m_0098c180

// @f3 0x00985aa0 (community match, verified in this file)
namespace f3m_00985aa0 {
namespace BufferCleanup985 {extern unsigned long DAT_010f3170;extern void* (__stdcall* DAT_00d9b080)(unsigned long);struct Allocator{void FUN_008f6f90(void*);};struct BufferOwner {int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014; int unk0018; int unk001C; int unk0020; int unk0024; int unk0028; int unk002C; int unk0030; int unk0034; int unk0038; int unk003C; int unk0040; int unk0044; int unk0048; int unk004C; int unk0050; int unk0054; int unk0058; int unk005C; int unk0060; int unk0064; int unk0068; int unk006C; int unk0070; int unk0074; int unk0078; int unk007C; int unk0080; int unk0084; int unk0088; int unk008C; int unk0090; int unk0094; int unk0098; int unk009C; int unk00A0; int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4; int unk00B8; int unk00BC; int unk00C0; int unk00C4; int unk00C8; int unk00CC; int unk00D0; int unk00D4; int unk00D8; int unk00DC; int unk00E0; int unk00E4; int unk00E8; int unk00EC; int unk00F0; int unk00F4; int unk00F8; int unk00FC; int unk0100; int unk0104; int unk0108; int unk010C; int unk0110; int unk0114; int unk0118; int unk011C; int unk0120; int unk0124; int unk0128; int unk012C; int unk0130; int unk0134; int unk0138; int unk013C; int unk0140; int unk0144; int unk0148; int unk014C; int unk0150; int unk0154; int unk0158; int unk015C; int unk0160; int unk0164; int unk0168; int unk016C; int unk0170; int unk0174; int unk0178; int unk017C; int unk0180; int unk0184; int unk0188; int unk018C; int unk0190; int unk0194; int unk0198; int unk019C; int unk01A0; int unk01A4; int unk01A8; int unk01AC; int unk01B0; int unk01B4; int unk01B8; int unk01BC; int unk01C0; int unk01C4; int unk01C8; int unk01CC; int unk01D0; int unk01D4; int unk01D8; int unk01DC; int unk01E0; int unk01E4; int unk01E8; int unk01EC; int unk01F0; int unk01F4; int unk01F8; int unk01FC; int unk0200; int unk0204; int unk0208; int unk020C; int unk0210; int unk0214; int unk0218; int unk021C; int unk0220; int unk0224; int unk0228; int unk022C; int unk0230; int unk0234; int unk0238; int unk023C; int unk0240; int unk0244; int unk0248; int unk024C; int unk0250; int unk0254; int unk0258; int unk025C; int unk0260; int unk0264; int unk0268; int unk026C; int unk0270; int unk0274; int unk0278; int unk027C; int unk0280; int unk0284; int unk0288; int unk028C; int unk0290; int unk0294; int unk0298; int unk029C; int unk02A0; int unk02A4; int unk02A8; int unk02AC; int unk02B0; int unk02B4; int unk02B8; int unk02BC; int unk02C0; int unk02C4; int unk02C8; int unk02CC; int unk02D0; int unk02D4; int unk02D8; int unk02DC; int unk02E0; int unk02E4; int unk02E8; int unk02EC; int unk02F0; int unk02F4; int unk02F8; int unk02FC; int unk0300; int unk0304; int unk0308; int unk030C; int unk0310; int unk0314; int unk0318; int unk031C; int unk0320; int unk0324; int unk0328; int unk032C; int unk0330; int unk0334; int unk0338; int unk033C; int unk0340; int unk0344; int unk0348; int unk034C; int unk0350; int unk0354; int unk0358; int unk035C; int unk0360; int unk0364; int unk0368; int unk036C; int unk0370; int unk0374; int unk0378; int unk037C; int unk0380; int unk0384; int unk0388; int unk038C; int unk0390; int unk0394; int unk0398; int unk039C; int unk03A0; int unk03A4; int unk03A8; int unk03AC; int unk03B0; int unk03B4; int unk03B8; int unk03BC; int unk03C0; int unk03C4; int unk03C8; int unk03CC; int unk03D0; int unk03D4; int unk03D8; int unk03DC; int unk03E0; int unk03E4; int unk03E8; int unk03EC; int unk03F0; int unk03F4; int unk03F8; int unk03FC; int unk0400; int unk0404; int unk0408; int unk040C; int unk0410; int unk0414; int unk0418; int unk041C; int unk0420; int unk0424; int unk0428; int unk042C; int unk0430; int unk0434; int unk0438; int unk043C; int unk0440; int unk0444; int unk0448; int unk044C; int unk0450; int unk0454; int unk0458; int unk045C; int unk0460; int unk0464; int unk0468; int unk046C; int unk0470; int unk0474; int unk0478; int unk047C; int unk0480; int unk0484; int unk0488; int unk048C; int unk0490; int unk0494; int unk0498; int unk049C; int unk04A0; int unk04A4; int unk04A8; int unk04AC; int unk04B0; int unk04B4; int unk04B8; int unk04BC; int unk04C0; int unk04C4; int unk04C8; int unk04CC; int unk04D0; int unk04D4; int unk04D8; int unk04DC; int unk04E0; int unk04E4; int unk04E8; int unk04EC; int unk04F0; int unk04F4; int unk04F8; int unk04FC; int unk0500; int unk0504; int unk0508; int unk050C; int unk0510; int unk0514; int unk0518; int unk051C; int unk0520; int unk0524; int unk0528; int unk052C; int unk0530; int unk0534; int unk0538; int unk053C; int unk0540; int unk0544; int unk0548; int unk054C; int unk0550; int unk0554; int unk0558; int unk055C; int unk0560; int unk0564; int unk0568; int unk056C; int unk0570; int unk0574; int unk0578; int unk057C; int unk0580; int unk0584; int unk0588; int unk058C; int unk0590; int unk0594; int unk0598; int unk059C; int unk05A0; int unk05A4; int unk05A8; int unk05AC; int unk05B0; int unk05B4; int unk05B8; int unk05BC; int unk05C0; int unk05C4; int unk05C8; int unk05CC; int unk05D0; int unk05D4; int unk05D8; int unk05DC; int unk05E0; int unk05E4; int unk05E8; int unk05EC; int unk05F0; int unk05F4; int unk05F8; int unk05FC; int unk0600; int unk0604; int unk0608; int unk060C; int unk0610; int unk0614; int unk0618; int unk061C; int unk0620; int unk0624; int unk0628; int unk062C; int unk0630; int unk0634; int unk0638; int unk063C; int unk0640; int unk0644; int unk0648; int unk064C; int unk0650; int unk0654; int unk0658; int unk065C; int unk0660; int unk0664; int unk0668; int unk066C; int unk0670; int unk0674; int unk0678; int unk067C; int unk0680; int unk0684; int unk0688; int unk068C; int unk0690; int unk0694; int unk0698; int unk069C; int unk06A0; int unk06A4; int unk06A8; int unk06AC; int unk06B0; int unk06B4; int unk06B8; int unk06BC; int unk06C0; int unk06C4; int unk06C8; int unk06CC; int unk06D0; int unk06D4; int unk06D8; int unk06DC; int unk06E0; int unk06E4; int unk06E8; int unk06EC; int unk06F0; int unk06F4; int unk06F8; int unk06FC; int unk0700; int unk0704; int unk0708; int unk070C; int unk0710; int unk0714; int unk0718; int unk071C; int unk0720; int unk0724; int unk0728; int unk072C; int unk0730; int unk0734; int unk0738; int unk073C; int unk0740; int unk0744; int unk0748; int unk074C; int unk0750; int unk0754; int unk0758; int unk075C; int unk0760; int unk0764; int unk0768; int unk076C; int unk0770; int unk0774; int unk0778; int unk077C; int unk0780; int unk0784; int unk0788; int unk078C; int unk0790; int unk0794; int unk0798; int unk079C; int unk07A0; int unk07A4; int unk07A8; int unk07AC; int unk07B0; int unk07B4; int unk07B8; int unk07BC; int unk07C0; int unk07C4; int unk07C8; int unk07CC; int unk07D0; int unk07D4; int unk07D8; int unk07DC; int unk07E0; int unk07E4; int unk07E8; int unk07EC; int unk07F0; int unk07F4; int unk07F8; int unk07FC; int unk0800; int unk0804; int unk0808; int unk080C; int unk0810; int unk0814; int unk0818; int unk081C; int unk0820; int unk0824; int unk0828; int unk082C; int unk0830; int unk0834; int unk0838; int unk083C; int unk0840; int unk0844; int unk0848; int unk084C; int unk0850; int unk0854; int unk0858; int unk085C; int unk0860; int unk0864; int unk0868; int unk086C; int unk0870; int unk0874; int unk0878; int unk087C; int unk0880; int unk0884; int unk0888; int unk088C; int unk0890; int unk0894; int unk0898; int unk089C; int unk08A0; int unk08A4; int unk08A8; int unk08AC; int unk08B0; int unk08B4; int unk08B8; int unk08BC; int unk08C0; int unk08C4; int unk08C8; int unk08CC; int unk08D0; int unk08D4; int unk08D8; int unk08DC; int unk08E0; int unk08E4; int unk08E8; int unk08EC; int unk08F0; int unk08F4; int unk08F8; int unk08FC; int unk0900; int unk0904; int unk0908; int unk090C; int unk0910; int unk0914; int unk0918; int unk091C; int unk0920; int unk0924; int unk0928; int unk092C; int unk0930; int unk0934; int unk0938; int unk093C; int unk0940; int unk0944; int unk0948; int unk094C; int unk0950; int unk0954; int unk0958; int unk095C; int unk0960; int unk0964; int unk0968; int unk096C; int unk0970; int unk0974; int unk0978; int unk097C; int unk0980; int unk0984; int unk0988; int unk098C; int unk0990; int unk0994; int unk0998; int unk099C; int unk09A0; int unk09A4; int unk09A8; int unk09AC; int unk09B0; int unk09B4; int unk09B8; int unk09BC; int unk09C0; int unk09C4; int unk09C8; int unk09CC; int unk09D0; int unk09D4; int unk09D8; int unk09DC; int unk09E0; int unk09E4; int unk09E8; int unk09EC; int unk09F0; int unk09F4; int unk09F8; int unk09FC; int unk0A00; int unk0A04; int unk0A08; int unk0A0C; int unk0A10; int unk0A14; int unk0A18; int unk0A1C; int unk0A20; int unk0A24; int unk0A28; int unk0A2C; int unk0A30; int unk0A34; int unk0A38; int unk0A3C; int unk0A40; int unk0A44; int unk0A48; int unk0A4C; int unk0A50; int unk0A54; int unk0A58; int unk0A5C; int unk0A60; int unk0A64; int unk0A68; int unk0A6C; int unk0A70; int unk0A74; int unk0A78; int unk0A7C; int unk0A80; int unk0A84; int unk0A88; int unk0A8C; int unk0A90; int unk0A94; int unk0A98; int unk0A9C; int unk0AA0; int unk0AA4; int unk0AA8; int unk0AAC; int unk0AB0; int unk0AB4; int unk0AB8; int unk0ABC; int unk0AC0; int unk0AC4; int unk0AC8; int unk0ACC; int unk0AD0; int unk0AD4; int unk0AD8; int unk0ADC; int unk0AE0; int unk0AE4; int unk0AE8; int unk0AEC; int unk0AF0; int unk0AF4; int unk0AF8; int unk0AFC; int unk0B00; int unk0B04; int unk0B08; int unk0B0C; int unk0B10; int unk0B14; int unk0B18; int unk0B1C; int unk0B20; int unk0B24; int unk0B28; int unk0B2C; int unk0B30; int unk0B34; int unk0B38; int unk0B3C; int unk0B40; int unk0B44; int unk0B48; int unk0B4C; int unk0B50; int unk0B54; int unk0B58; int unk0B5C; int unk0B60; int unk0B64; int unk0B68; int unk0B6C; int unk0B70; int unk0B74; int unk0B78; int unk0B7C; int unk0B80; int unk0B84; int unk0B88; int unk0B8C; int unk0B90; int unk0B94; int unk0B98; int unk0B9C; int unk0BA0; int unk0BA4; int unk0BA8; int unk0BAC; int unk0BB0; int unk0BB4; int unk0BB8; int unk0BBC; int unk0BC0; int unk0BC4; int unk0BC8; int unk0BCC; int unk0BD0; int unk0BD4; int unk0BD8; int unk0BDC; int unk0BE0; int unk0BE4; int unk0BE8; int unk0BEC; int unk0BF0; int unk0BF4; int unk0BF8; int unk0BFC; int unk0C00; int unk0C04; int unk0C08; int unk0C0C; int unk0C10; int unk0C14; int unk0C18; int unk0C1C; int unk0C20; int unk0C24; int unk0C28; int unk0C2C; int unk0C30; int unk0C34; int unk0C38; int unk0C3C; int unk0C40; int unk0C44; int unk0C48; int unk0C4C; int unk0C50; int unk0C54; int unk0C58; int unk0C5C; int unk0C60; int unk0C64; int unk0C68; int unk0C6C; int unk0C70; int unk0C74; int unk0C78; int unk0C7C; int unk0C80; int unk0C84; int unk0C88; int unk0C8C; int unk0C90; int unk0C94; int unk0C98; int unk0C9C; int unk0CA0; int unk0CA4; int unk0CA8; int unk0CAC; int unk0CB0; int unk0CB4; int unk0CB8; int unk0CBC; int unk0CC0; int unk0CC4; int unk0CC8; int unk0CCC; int unk0CD0; int unk0CD4; int unk0CD8; int unk0CDC; int unk0CE0; int unk0CE4; int unk0CE8; int unk0CEC; int unk0CF0; int unk0CF4; int unk0CF8; int unk0CFC; int unk0D00; int unk0D04; int unk0D08; int unk0D0C; int unk0D10; int unk0D14; int unk0D18; int unk0D1C; int unk0D20; int unk0D24; int unk0D28; int unk0D2C; int unk0D30; int unk0D34; int unk0D38; int unk0D3C; int unk0D40; int unk0D44; int unk0D48; int unk0D4C; int unk0D50; int unk0D54; int unk0D58; int unk0D5C; int unk0D60; int unk0D64; int unk0D68; int unk0D6C; int unk0D70; int unk0D74; int unk0D78; int unk0D7C; int unk0D80; int unk0D84; int unk0D88; int unk0D8C; int unk0D90; int unk0D94; int unk0D98; int unk0D9C; int unk0DA0; int unk0DA4; int unk0DA8; int unk0DAC; int unk0DB0; int unk0DB4; int unk0DB8; int unk0DBC; int unk0DC0; int unk0DC4; int unk0DC8; int unk0DCC; int unk0DD0; int unk0DD4; int unk0DD8; int unk0DDC; int unk0DE0; int unk0DE4; int unk0DE8; int unk0DEC; int unk0DF0; int unk0DF4; int unk0DF8; int unk0DFC; int unk0E00; int unk0E04; int unk0E08; int unk0E0C; int unk0E10; int unk0E14; int unk0E18; int unk0E1C; int unk0E20; int unk0E24; int unk0E28; int unk0E2C; int unk0E30; int unk0E34; int unk0E38; int unk0E3C; int unk0E40; int unk0E44; int unk0E48; int unk0E4C; int unk0E50; int unk0E54; int unk0E58; int unk0E5C; int unk0E60; int unk0E64; int unk0E68; int unk0E6C; int unk0E70; int unk0E74; int unk0E78; int unk0E7C; int unk0E80; int unk0E84; int unk0E88; int unk0E8C; int unk0E90; int unk0E94; int unk0E98; int unk0E9C; int unk0EA0; int unk0EA4; int unk0EA8; int unk0EAC; int unk0EB0; int unk0EB4; int unk0EB8; int unk0EBC; int unk0EC0; int unk0EC4; int unk0EC8; int unk0ECC; int unk0ED0; int unk0ED4; int unk0ED8; int unk0EDC; int unk0EE0; int unk0EE4; int unk0EE8; int unk0EEC; int unk0EF0; int unk0EF4; int unk0EF8; int unk0EFC; int unk0F00; int unk0F04; int unk0F08; int unk0F0C; int unk0F10; int unk0F14; int unk0F18; int unk0F1C; int unk0F20; int unk0F24; int unk0F28; int unk0F2C; int unk0F30; int unk0F34; int unk0F38; int unk0F3C; int unk0F40; int unk0F44; int unk0F48; int unk0F4C; int unk0F50; int unk0F54; int unk0F58; int unk0F5C; int unk0F60; int unk0F64; int unk0F68; int unk0F6C; int unk0F70; int unk0F74; int unk0F78; int unk0F7C; int unk0F80; int unk0F84; int unk0F88; int unk0F8C; int unk0F90; int unk0F94; int unk0F98; int unk0F9C; int unk0FA0; int unk0FA4; int unk0FA8; int unk0FAC; int unk0FB0; int unk0FB4; int unk0FB8; int unk0FBC; int unk0FC0; int unk0FC4; int unk0FC8; int unk0FCC; int unk0FD0; int unk0FD4; int unk0FD8; int unk0FDC; int unk0FE0; int unk0FE4; int unk0FE8; int unk0FEC; int unk0FF0; int unk0FF4; int unk0FF8; int unk0FFC; int unk1000; int unk1004; int unk1008; int unk100C; int unk1010; int unk1014; int unk1018; int unk101C; int unk1020; int unk1024; int unk1028; int unk102C; int unk1030; int unk1034; int unk1038; int unk103C; int unk1040; int unk1044; int unk1048; int unk104C; int unk1050; int unk1054; int unk1058; int unk105C; int unk1060; int unk1064; int unk1068; int unk106C; int unk1070; int unk1074; int unk1078; int unk107C; int unk1080; int unk1084; int unk1088; int unk108C; int unk1090; int unk1094; int unk1098; int unk109C; int unk10A0; int unk10A4; int unk10A8; int unk10AC; int unk10B0; int unk10B4; int unk10B8; int unk10BC; int unk10C0; int unk10C4; int unk10C8; int unk10CC; int unk10D0; int unk10D4; int unk10D8; int unk10DC; int unk10E0; int unk10E4; int unk10E8; int unk10EC; int unk10F0; int unk10F4; int unk10F8; int unk10FC; int unk1100; int unk1104; int unk1108; int unk110C; int unk1110; int unk1114; int unk1118; int unk111C; int unk1120; int unk1124; int unk1128; int unk112C; int unk1130; int unk1134; int unk1138; int unk113C; int unk1140; int unk1144; int unk1148; int unk114C; int unk1150; int unk1154; int unk1158; int unk115C; int unk1160; int unk1164; int unk1168; int unk116C; int unk1170; int unk1174; int unk1178; int unk117C; int unk1180; int unk1184; int unk1188; int unk118C; int unk1190; int unk1194; int unk1198; int unk119C; int unk11A0; int unk11A4; int unk11A8; int unk11AC; int unk11B0; int unk11B4; int unk11B8; int unk11BC; int unk11C0; int unk11C4; int unk11C8; int unk11CC; int unk11D0; int unk11D4; int unk11D8; int unk11DC; int unk11E0; int unk11E4; int unk11E8; int unk11EC; int unk11F0; int unk11F4; int unk11F8; int unk11FC; int unk1200; int unk1204; int unk1208; int unk120C; int unk1210; int unk1214; int unk1218; int unk121C; int unk1220; int unk1224; int unk1228; int unk122C; int unk1230; int unk1234; int unk1238; int unk123C; int unk1240; int unk1244; int unk1248; int unk124C; int unk1250; int unk1254; int unk1258; int unk125C; int unk1260; int unk1264; int unk1268; int unk126C; int unk1270; int unk1274; int unk1278; int unk127C; int unk1280; int unk1284; int unk1288; int unk128C; int unk1290; int unk1294; int unk1298; int unk129C; int unk12A0; int unk12A4; int unk12A8; int unk12AC; int unk12B0; int unk12B4; int unk12B8; int unk12BC; int unk12C0; int unk12C4; int unk12C8; int unk12CC; int unk12D0; int unk12D4; int unk12D8; int unk12DC; int unk12E0; int unk12E4; int unk12E8; int unk12EC; int unk12F0; int unk12F4; int unk12F8; int unk12FC; int unk1300; int unk1304; int unk1308; int unk130C; int unk1310; int unk1314; int unk1318; int unk131C; int unk1320; int unk1324; int unk1328; int unk132C; int unk1330; int unk1334; int unk1338; int unk133C; int unk1340; int unk1344; int unk1348; int unk134C; int unk1350; int unk1354; int unk1358; int unk135C; int unk1360; int unk1364; int unk1368; int unk136C; int unk1370; int unk1374; int unk1378; int unk137C; int unk1380; int unk1384; int unk1388; int unk138C; int unk1390; int unk1394; int unk1398; int unk139C; int unk13A0; int unk13A4; int unk13A8; int unk13AC; int unk13B0; int unk13B4; int unk13B8; int unk13BC; int unk13C0; int unk13C4; int unk13C8; int unk13CC; int unk13D0; int unk13D4; int unk13D8; int unk13DC; int unk13E0; int unk13E4; int unk13E8; int unk13EC; int unk13F0; int unk13F4; int unk13F8; int unk13FC; int unk1400; int unk1404; int unk1408; int unk140C; int unk1410; int unk1414; int unk1418; int unk141C; int unk1420; int unk1424; int unk1428; int unk142C; int unk1430; int unk1434; int unk1438; int unk143C; int unk1440; int unk1444; int unk1448; int unk144C; int unk1450; int unk1454; int unk1458; int unk145C; int unk1460; int unk1464; int unk1468; int unk146C; int unk1470; int unk1474; int unk1478; int unk147C; int unk1480; int unk1484; int unk1488; int unk148C; int unk1490; int unk1494; int unk1498; int unk149C; int unk14A0; int unk14A4; int unk14A8; int unk14AC; int unk14B0; int unk14B4; int unk14B8; int unk14BC; int unk14C0; int unk14C4; int unk14C8; int unk14CC; int unk14D0; int unk14D4; int unk14D8; int unk14DC; int unk14E0; int unk14E4; int unk14E8; int unk14EC; int unk14F0; int unk14F4; int unk14F8; int unk14FC; int unk1500; int unk1504; int unk1508; int unk150C; int unk1510; int unk1514; int unk1518; int unk151C; int unk1520; int unk1524; int unk1528; int unk152C; int unk1530; int unk1534; int unk1538; int unk153C; int unk1540; int unk1544; int unk1548; int unk154C; int unk1550; int unk1554; int unk1558; int unk155C; int unk1560; int unk1564; int unk1568; int unk156C; int unk1570; int unk1574; int unk1578; int unk157C; int unk1580; int unk1584; int unk1588; int unk158C; int unk1590; int unk1594; int unk1598; int unk159C; int unk15A0; int unk15A4; int unk15A8; int unk15AC; int unk15B0; int unk15B4; int unk15B8; int unk15BC; int unk15C0; int unk15C4; int unk15C8; int unk15CC; int unk15D0; int unk15D4; int unk15D8; int unk15DC; int unk15E0; int unk15E4; int unk15E8; int unk15EC; int unk15F0; int unk15F4; int unk15F8; int unk15FC; int unk1600; int unk1604; int unk1608; int unk160C; int unk1610; int unk1614; int unk1618; int unk161C; int unk1620; int unk1624; int unk1628; int unk162C; int unk1630; int unk1634; int unk1638; int unk163C; int unk1640; int unk1644; int unk1648; int unk164C; int unk1650; int unk1654; int unk1658; int unk165C; int unk1660; int unk1664; int unk1668; int unk166C; int unk1670; int unk1674; int unk1678; int unk167C; int unk1680; int unk1684; int unk1688; int unk168C; int unk1690; int unk1694; int unk1698; int unk169C; int unk16A0; int unk16A4; int unk16A8; int unk16AC; int unk16B0; int unk16B4; int unk16B8; int unk16BC; int unk16C0; int unk16C4; int unk16C8; int unk16CC; int unk16D0; int unk16D4; int unk16D8; int unk16DC; int unk16E0; int unk16E4; int unk16E8; int unk16EC; int unk16F0; int unk16F4; int unk16F8; int unk16FC; int unk1700; int unk1704; int unk1708; int unk170C; int unk1710; int unk1714; int unk1718; int unk171C; int unk1720; int unk1724; int unk1728; int unk172C; int unk1730; int unk1734; int unk1738; int unk173C; int unk1740; int unk1744; int unk1748; int unk174C; int unk1750; int unk1754; int unk1758; int unk175C; int unk1760; int unk1764; int unk1768; int unk176C; int unk1770; int unk1774; int unk1778; int unk177C; int unk1780; int unk1784; int unk1788; int unk178C; int unk1790; int unk1794; int unk1798; int unk179C; int unk17A0; int unk17A4; int unk17A8; int unk17AC; int unk17B0; int unk17B4; int unk17B8; int unk17BC; int unk17C0; int unk17C4; int unk17C8; int unk17CC; int unk17D0; int unk17D4; int unk17D8; int unk17DC; int unk17E0; int unk17E4; int unk17E8; int unk17EC; int unk17F0; int unk17F4; int unk17F8; int unk17FC; int unk1800; int unk1804; int unk1808; int unk180C; int unk1810; int unk1814; int unk1818; int unk181C; int unk1820; int unk1824; int unk1828; int unk182C; int unk1830; int unk1834; int unk1838; int unk183C; int unk1840; int unk1844; int unk1848; int unk184C; int unk1850; int unk1854; int unk1858; int unk185C; int unk1860; int unk1864; int unk1868; int unk186C; int unk1870; int unk1874; int unk1878; int unk187C; int unk1880; int unk1884; int unk1888; int unk188C; int unk1890; int unk1894; int unk1898; int unk189C; int unk18A0; int unk18A4; int unk18A8; int unk18AC; int unk18B0; int unk18B4; int unk18B8; int unk18BC; int unk18C0; int unk18C4; int unk18C8; int unk18CC; int unk18D0; int unk18D4; int unk18D8; int unk18DC; int unk18E0; int unk18E4; int unk18E8; int unk18EC; int unk18F0; int unk18F4; int unk18F8; int unk18FC; int unk1900; int unk1904; int unk1908; int unk190C; int unk1910; int unk1914; int unk1918; int unk191C; int unk1920; int unk1924; int unk1928; int unk192C; int unk1930; int unk1934; int unk1938; int unk193C; int unk1940; int unk1944; int unk1948; int unk194C; int unk1950; int unk1954; int unk1958; int unk195C; int unk1960; int unk1964; int unk1968; int unk196C; int unk1970; int unk1974; int unk1978; int unk197C; int unk1980; int unk1984; int unk1988; int unk198C; int unk1990; int unk1994; int unk1998; int unk199C; int unk19A0; int unk19A4; int unk19A8; int unk19AC; int unk19B0; int unk19B4; int unk19B8; int unk19BC; int unk19C0; int unk19C4; int unk19C8; int unk19CC; int unk19D0; int unk19D4; int unk19D8; int unk19DC; int unk19E0; int unk19E4; int unk19E8; int unk19EC; int unk19F0; int unk19F4; int unk19F8; int unk19FC; int unk1A00; int unk1A04; int unk1A08; int unk1A0C; int unk1A10; int unk1A14; int unk1A18; int unk1A1C; int unk1A20; int unk1A24; int unk1A28; int unk1A2C; int unk1A30; int unk1A34; int unk1A38; int unk1A3C; int unk1A40; int unk1A44; int unk1A48; int unk1A4C; int unk1A50; int unk1A54; int unk1A58; int unk1A5C; int unk1A60; int unk1A64; int unk1A68; int unk1A6C; int unk1A70; int unk1A74; int unk1A78; int unk1A7C; int unk1A80; int unk1A84; int unk1A88; int unk1A8C; int unk1A90; int unk1A94; int unk1A98; int unk1A9C; int unk1AA0; int unk1AA4; int unk1AA8; int unk1AAC; int unk1AB0; int unk1AB4; int unk1AB8; int unk1ABC; int unk1AC0; int unk1AC4; int unk1AC8; int unk1ACC; int unk1AD0; int unk1AD4; int unk1AD8; int unk1ADC; int unk1AE0; int unk1AE4; int unk1AE8; int unk1AEC; int unk1AF0; int unk1AF4; int unk1AF8; int unk1AFC; int unk1B00; int unk1B04; int unk1B08; int unk1B0C; int unk1B10; int unk1B14; int unk1B18; int unk1B1C; int unk1B20; int unk1B24; int unk1B28; int unk1B2C; int unk1B30; int unk1B34; int unk1B38; int unk1B3C; int unk1B40; int unk1B44; int unk1B48; int unk1B4C; int unk1B50; int unk1B54; int unk1B58; int unk1B5C; int unk1B60; int unk1B64; int unk1B68; int unk1B6C; int unk1B70; int unk1B74; int unk1B78; int unk1B7C; int unk1B80; int unk1B84; int unk1B88; int unk1B8C; int unk1B90; int unk1B94; int unk1B98; int unk1B9C; int unk1BA0; int unk1BA4; int unk1BA8; int unk1BAC; int unk1BB0; int unk1BB4; int unk1BB8; int unk1BBC; int unk1BC0; int unk1BC4; int unk1BC8; int unk1BCC; int unk1BD0; int unk1BD4; int unk1BD8; int unk1BDC; int unk1BE0; int unk1BE4; int unk1BE8; int unk1BEC; int unk1BF0; int unk1BF4; int unk1BF8; int unk1BFC; int unk1C00; int unk1C04; int unk1C08; int unk1C0C; int unk1C10; int unk1C14; int unk1C18; int unk1C1C; int unk1C20; int unk1C24; int unk1C28; int unk1C2C; int unk1C30; int unk1C34; int unk1C38; int unk1C3C; int unk1C40; int unk1C44; int unk1C48; int unk1C4C; int unk1C50; int unk1C54; int unk1C58; int unk1C5C; int unk1C60; int unk1C64; int unk1C68; int unk1C6C; int unk1C70; int unk1C74; int unk1C78; int unk1C7C; int unk1C80; int unk1C84; int unk1C88; int unk1C8C; int unk1C90; int unk1C94; int unk1C98; int unk1C9C; int unk1CA0; int unk1CA4; int unk1CA8; int unk1CAC; int unk1CB0; int unk1CB4; int unk1CB8; int unk1CBC; int unk1CC0; int unk1CC4; int unk1CC8; int unk1CCC; int unk1CD0; int unk1CD4; int unk1CD8; int unk1CDC; int unk1CE0; int unk1CE4; int unk1CE8; int unk1CEC; int unk1CF0; int unk1CF4; int unk1CF8; int unk1CFC; int unk1D00; int unk1D04; int unk1D08; int unk1D0C; int unk1D10; int unk1D14; int unk1D18; int unk1D1C; int unk1D20; int unk1D24; int unk1D28; int unk1D2C; int unk1D30; int unk1D34; int unk1D38; int unk1D3C; int unk1D40; int unk1D44; int unk1D48; int unk1D4C; int unk1D50; int unk1D54; int unk1D58; int unk1D5C; int unk1D60; int unk1D64; int unk1D68; int unk1D6C; int unk1D70; int unk1D74; int unk1D78; int unk1D7C; int unk1D80; int unk1D84; int unk1D88; int unk1D8C; int unk1D90; int unk1D94; int unk1D98; int unk1D9C; int unk1DA0; int unk1DA4; int unk1DA8; int unk1DAC; int unk1DB0; int unk1DB4; int unk1DB8; int unk1DBC; int unk1DC0; int unk1DC4; int unk1DC8; int unk1DCC; int unk1DD0; int unk1DD4; int unk1DD8; int unk1DDC; int unk1DE0; int unk1DE4; int unk1DE8; int unk1DEC; int unk1DF0; int unk1DF4; int unk1DF8; int unk1DFC; int unk1E00; int unk1E04; int unk1E08; int unk1E0C; int unk1E10; int unk1E14; int unk1E18; int unk1E1C; int unk1E20; int unk1E24; int unk1E28; int unk1E2C; void* first;void* second;void* third;void* fourth;void FUN_00985aa0();};
// pdb: hkpCollisionDispatcher::disableDebugging | hkpCollisionDispatcher.obj | fnv360_0822_retail, callee_sim, low
void BufferOwner::FUN_00985aa0(){Allocator* allocator;void* buffer=first;if(buffer){void* (__stdcall* get)(unsigned long)=DAT_00d9b080;allocator=(Allocator*)get(DAT_010f3170);allocator->FUN_008f6f90(buffer);buffer=second;allocator=(Allocator*)get(DAT_010f3170);allocator->FUN_008f6f90(buffer);buffer=third;allocator=(Allocator*)get(DAT_010f3170);allocator->FUN_008f6f90(buffer);buffer=fourth;allocator=(Allocator*)get(DAT_010f3170);allocator->FUN_008f6f90(buffer);first=0;second=0;third=0;fourth=0;}}
}
}   // namespace f3m_00985aa0

// @f3 0x0099e940 (community match, verified in this file)
extern const char DAT_00e7ddc4[],DAT_00e7ddb8[]; struct Writer99e; struct Owner99e;
struct Table99e {void* unk00;void (__thiscall* begin)(Writer99e*,const char*,int,Owner99e*);void (__thiscall* data)(Writer99e*,const char*,int,void*,int,int);void* unk0c;void* unk10;void* unk14;void (__thiscall* end)(Writer99e*);};struct Writer99e{Table99e* table;};
struct Owner99e { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; void* data; int count; int capacity;void hkpPhantom_calcContentStatistics(Writer99e*);void hkpSimpleShapePhantom_calcContentStatistics(Writer99e*);};
// pdb: hkpSimpleShapePhantom::calcContentStatistics | hkpSimpleShapePhantom.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void Owner99e::hkpSimpleShapePhantom_calcContentStatistics(Writer99e* writer){writer->table->begin(writer,DAT_00e7ddc4,2,this);hkpPhantom_calcContentStatistics(writer);if(!(capacity & 0x80000000u)){int cap=capacity&0x3fffffff;cap+=cap;cap+=cap;int size=count;size+=size;size+=size;writer->table->data(writer,DAT_00e7ddb8,8,data,size,cap);}writer->table->end(writer);}

// @f3 0x0099d300 (community match, verified in this file)
extern int DAT_00e3599c;extern int DAT_00dcc494;
namespace f3m_0099d300 {
struct Refd300;struct Tabled300 {void (__thiscall* destroy)(Refd300*,int);};
struct Refd300 {Tabled300* table;unsigned short managed;short refs;void Release(){if(managed){unsigned short count=--refs;if(!count)table->destroy(this,1);}}};
struct Ownerd300 {void* table;int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; Refd300* object;void FUN_0099d300();};
// pdb: hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, call_seq, high
void Ownerd300::FUN_0099d300(){table=&DAT_00e3599c;if(object)object->Release();table=&DAT_00dcc494;}
}   // namespace f3m_0099d300

// @f3 0x00987940 (community match, verified in this file)
namespace f3m_00987940 {
namespace Q9879 {struct Memory {void* FUN_008f6d30(int,int);}; __declspec(dllimport) Memory* __stdcall FUN_00d9b080(int);extern int DAT_010f3170;struct Input {int unk00;int unk04;int unk08;int unk0c;signed char offset;};struct Block {int unk00;unsigned short size;unsigned short unk06;void* FUN_00987840(void*,void*,void*);};struct Owner {int unk00;int unk04;void* context;void* hkpSimpleConstraintContactMgr_Factory_createContactMgr(Input*,Input*,int);};
// pdb: hkpSimpleConstraintContactMgr::Factory::createContactMgr | hkpSimpleConstraintContactMgr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void* Owner::hkpSimpleConstraintContactMgr_Factory_createContactMgr(Input* a,Input* b,int unused){void* first=(char*)a+a->offset;void* second=(char*)b+b->offset;Memory* memory=FUN_00d9b080(DAT_010f3170);Block* block=(Block*)memory->FUN_008f6d30(128,0x22);block->size=128;return block->FUN_00987840(context,first,second);} }
}   // namespace f3m_00987940

// @f3 0x009899e0 (community match, verified in this file)
namespace f3m_009899e0 {
namespace w9899e0 {
struct Array; void FUN_00901f10(Array*,int);
struct Array { int* data; int count; unsigned capacity; void Push(int value) { if(count==(capacity&0x3fffffff)) FUN_00901f10(this,4); data[count]=value; ++count; } };
struct Owner { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; Array array; void FUN_009899e0(int); };
// pdb: hkpPhantom::addPhantomOverlapListener | hkpPhantom.obj | fnv360_0721_beta, call_gap, low
// pdb params: el
void Owner::FUN_009899e0(int value) { array.Push(value); }
}
}   // namespace f3m_009899e0

// @f3 0x00988c60 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d88c[];
extern const char DAT_00e32798[];
namespace f3m_00988c60 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace task1366 {
struct PhantomEvent {int unk00;int unk04;int unused08;};
class PhantomListener {
public:
    virtual void v0();
    virtual void phantomAddedCallback(PhantomEvent*);
};
struct ListenerArray {
    PhantomListener** data;
    int size;
    unsigned int capacity;
};
struct World {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104;
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
    ListenerArray phantomListeners;
};
struct Timer {
    const char* command;
    unsigned int time0, time1;
};
struct Stream {
    int unk00;
    Timer* end;
    int unk08;
    Timer* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(ListenerArray& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index) {
        if (!listeners.data[index]) {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent(const char* name, volatile unsigned int& ticks)
{
    Stream* stream = static_cast<Stream*>(TlsGetValue(DAT_0116913c));
    Timer* command = stream->end;
    if (command < stream->capacityEnd) {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// pdb: hkpWorldCallbackUtil::fireContactPointCallback | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_seq) + skyrim(call_gap_sim), high
void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(World* world, PhantomEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    ListenerArray& listeners = world->phantomListeners;
    event->unused08=0;
    int i = listeners.size - 1;
    for (; i >= 0; --i) {
        if (listeners.data[i]) {
            TimerEvent(DAT_00e7d88c, beginTicks);
            listeners.data[i]->phantomAddedCallback(event);
            TimerEvent(DAT_00e32798, endTicks);
        }
    }
    FUN_00988440(listeners);
}
}
}   // namespace f3m_00988c60

// @f3 0x0099d980 (community match, verified in this file)
namespace f3m_0099d980 {
namespace Init99Batch {extern int DAT_00e35b64;struct Scale {float x,y,z,w;void Set(float n){x=n;y=n;z=n;w=n;}};struct Object {int* table;int unk04;unsigned char type,unk09,unk0A,unk0B;int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; Scale scale;void FUN_008f8530(int,int,int);Object* FUN_0099d980(int,int);};
// pdb: hkpBoxMotion::hkpBoxMotion | hkpBoxMotion.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: position, rotation
Object* Object::FUN_0099d980(int a,int b){FUN_008f8530(a,b,0);table=&DAT_00e35b64;scale.Set(1.0f);type=4;return this;}
}
}   // namespace f3m_0099d980

// @f3 0x00988d10 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
namespace f3m_00988d10 {
namespace task1367 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct ContactPointEvent { int unk00,unk04,unk08,unk0c; int unk10; };
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    int size;
    int capacity;
};
struct World833 {
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
Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00988440(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0116913c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00988440.
// @fnv 0x00d00060
// pdb: hkpWorldCallbackUtil::fireContactPointRemoved | hkpWorldCallbackUtil.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|call_seq) + skyrim(caller_sim), high
void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(World833* world, ContactPointEvent* event)
{
    unsigned beginTicks;
    unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    event->unk10 = 0;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtcpRemCb", beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00988440(listeners);
}
}  // namespace task1367
}   // namespace f3m_00988d10

// @f3 0x00989e90 (community match, verified in this file)
namespace f3m_00989e90 {
namespace pointer_swap_remove {
struct Item {void FUN_009316f0();};
struct Array {Item** data;int count,capacity;__forceinline void RemoveAt(int i){--count;data[i]=data[count];}};
struct Owner {unsigned int unk00,unk04;Array array;void FUN_00989e90(int);};
// pdb: hkStringPtr::operator= | hkStringPtr.obj | tesv_win, call_gap, low
void Owner::FUN_00989e90(int index){array.data[index]->FUN_009316f0();array.RemoveAt(index);}
}
}   // namespace f3m_00989e90

// @f3 0x00986ce0 (community match, verified in this file)
namespace f3m_00986ce0 {
namespace reverse_byte_index {
struct ContactPoint {float position[4];float separatingNormal[4];};
struct Atom {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;ContactPoint points[1];};
struct Storage {unsigned int unk00,unk04,unk08;unsigned char* ids;int count;unsigned int unk14,unk18,unk1c,unk20,unk24;Atom* atom;};
struct Owner {unsigned int unk00,unk04,unk08;ContactPoint* point;unsigned int unk10,unk14,unk18;unsigned int valid;Storage* storage;unsigned short FUN_00986ce0();};
// pdb: hkpSimpleConstraintContactMgr::reserveContactPointsImpl | hkpSimpleConstraintContactMgr.obj | fnv360_0822_retail, objrun_open, low
// pdb params: numPoints
unsigned short Owner::FUN_00986ce0(){if(!valid)return (unsigned short)-1;Storage* data=storage;int index=point-data->atom->points;int i=data->count-1;if(i>=0){unsigned char* ids=data->ids;do{if(ids[i]==index)break;--i;}while(i>=0);}return (unsigned short)i;}
}
}   // namespace f3m_00986ce0

// @f3 0x0098b630 (community match, verified in this file)
namespace f3m_0098b630 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);

struct Lock9318 {
    int cs00;
    int cs04;
    int cs08;
    int cs0c;
    int cs10;
    int cs14;
    int unk18;
    int unk1c;
    void FUN_00908a00();
};

extern Lock9318* DAT_01169318;

struct Self630 {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    void FUN_0098b630(int arg);
};

void Self630::FUN_0098b630(int arg)
{
    switch (unk00) {
    case -0x3f:
    case -0x1f:
    case -0x0f:
        DAT_01169318->FUN_00908a00();
        unk00 = (arg == 1) ? -0x1f : -0x3f;
        break;
    case -0x2f:
        return;
    default:
        DAT_01169318->FUN_00908a00();
        break;
    }
    unk06 <<= 1;
    unk04++;
    Lock9318* l = DAT_01169318;
    l->unk18 = -1;
    DAT_01169318->unk1c = -1;
    LeaveCriticalSection(l);
}
}   // namespace f3m_0098b630

// @f3 0x0098d990 (community match, verified in this file)
namespace G98d990 {
struct Heap98 {
    void FUN_008f6d90(void*, unsigned int, int);
};
extern Heap98* (__stdcall* const DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
extern int DAT_00e7dc14;
}

struct Arr98d990 { void* data; int count; int capacity; };

static __forceinline void FreeArr98d990(Arr98d990* a)
{
    if ((a->capacity & 0x80000000u) == 0) {
        unsigned int n = a->capacity & 0x3fffffff;
        G98d990::Heap98* heap = G98d990::DAT_00d9b080(G98d990::DAT_010f3170);
        heap->FUN_008f6d90(a->data, n * 0x70, 0x17);
    }
}

struct Vt98d990 { virtual void v0(int); };

struct Owner98d990;
void __fastcall FUN_0097f0f0(Owner98d990* self);

struct Owner98d990 {
    void* table;
    int unk04, unk08, unk0c;
    char enabled;
    char unk11, unk12, unk13;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Arr98d990 values;
    Vt98d990* item;
    int unk40;
    void FUN_0098d990();
};

// pdb: hkpContinuousSimulation::~hkpContinuousSimulation | hkpContinuousSimulation.obj | fnv360_0822_retail, call_seq, medium
void Owner98d990::FUN_0098d990()
{
    table = &G98d990::DAT_00e7dc14;
    if (item) item->v0(1);
    FreeArr98d990(&values);
    FUN_0097f0f0(this);
}

// @f3 0x00987c10 (community match, verified in this file)
namespace f3m_00987c10 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern unsigned long DAT_010f3170;
extern char DAT_00e7d7c8[];
extern char DAT_00dcc494[];

struct Heap987c10
{
    void FUN_008f6d90(void* ptr, unsigned int size, int tag);
};

struct Sub987c10
{
    unsigned short unk00;
    unsigned short unk02;
};

struct Obj987c10
{
    const char* vtbl;
    int unk04;
    int unk08;
    void* data0C;
    unsigned int count10;
    unsigned int cap14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    Sub987c10* sub28;
    void FUN_00987c10();
};

// pdb: hkpSimpleContactConstraintData::~hkpSimpleContactConstraintData | hkpSimpleConstraintContactMgr.obj | fnv360_0822_retail, call_seq, high
void Obj987c10::FUN_00987c10()
{
    vtbl = DAT_00e7d7c8;
    Sub987c10* p = sub28;
    if (p)
    {
        Heap987c10* heap = (Heap987c10*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(p, p->unk02, 4);
    }
    if ((cap14 & 0x80000000u) == 0)
    {
        unsigned int size = cap14 & 0x3fffffff;
        Heap987c10* heap2 = (Heap987c10*)TlsGetValue(DAT_010f3170);
        heap2->FUN_008f6d90(data0C, size, 0x17);
    }
    vtbl = DAT_00dcc494;
}
}   // namespace f3m_00987c10

// @f3 0x0099e8f0 (community match, verified in this file)
namespace f3m_0099e8f0 {
struct SlabArray;
void __cdecl FUN_00901f10(SlabArray*, int);
struct SlabArray {
    char** data;
    int count;
    unsigned int capacityFlags;
    void Append(char* block) {
        if (count == (capacityFlags & 0x3fffffffu))
            FUN_00901f10(this, 4);
        char** slot = data + count;
        count++;
        *slot = block;
    }
};
struct Block99e { int unk00; };
int __stdcall FUN_0091a520(Block99e* block);
struct Owner99e {
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
    SlabArray slabs;
    void FUN_0099e8f0(Block99e* block);
};
// pdb: hkpSimpleShapePhantom::addOverlappingCollidable | hkpSimpleShapePhantom.obj | tesv_win, objopen_prop, low
void Owner99e::FUN_0099e8f0(Block99e* block)
{
    if (block->unk00 == 0)
        return;
    if (FUN_0091a520(block))
        return;
    slabs.Append((char*)block);
}
}   // namespace f3m_0099e8f0

// @f3 0x009898e0 (community match, verified in this file)
namespace f3m_009898e0 {
namespace Erase389{struct Owner{
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
// pdb: hkpPhantom::removePhantomListener | hkpPhantom.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void**data;int count;int Find(void*key){int size=count;int i=0;if(size>0){void**entry=data;do{if(*entry==key)return i;++i;++entry;}while(i<size);}return -1;}void hkpPhantom_removePhantomListener(void*);};void Owner::hkpPhantom_removePhantomListener(void*key){int index=Find(key);--*(volatile int*)&count;int i=index;if(i<*(volatile int*)&count){do{data[i]=data[i+1];++i;}while(i<count);}}}



}   // namespace f3m_009898e0

// @f3 0x0098a0e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0098a0e0 {
struct HeapB {
    void FUN_008f6d90(void*, unsigned int, int);
};
extern HeapB* (__stdcall* const FUN_00d9b080)(unsigned long);

struct Elem1 {
    void FUN_009316f0();
};

struct Elem2 {
    virtual ~Elem2();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void removeReference() {
        if (m_memSizeAndFlags != 0) {
            if (--m_referenceCount == 0) {
                delete this;
            }
        }
    }
};

template <typename T>
struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct hkBaseObject {
    virtual ~hkBaseObject() {}
};

struct hkReferencedObject : public hkBaseObject {
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
};

struct FUN_0098a0e0 : public hkReferencedObject {
    hkArray<Elem1*> arr1;
    hkArray<Elem2*> arr2;
    hkArray<Elem2*> arr3;
    hkArray<Elem1*> arr4;

    virtual ~FUN_0098a0e0() throw();
};

// pdb: hkpPhysicsSystem::~hkpPhysicsSystem | hkpPhysicsSystem.obj | fnv360_0822_retail, call_seq, high
FUN_0098a0e0::~FUN_0098a0e0() throw() {
    int count1 = arr1.m_size;
    for (int i = 0; i < count1; ++i) {
        if (arr1.m_data[i]) {
            arr1.m_data[i]->FUN_009316f0();
        }
    }

    int count4 = arr4.m_size;
    for (int i = 0; i < count4; ++i) {
        if (arr4.m_data[i]) {
            arr4.m_data[i]->FUN_009316f0();
        }
    }

    int count2 = arr2.m_size;
    for (int i = 0; i < count2; ++i) {
        if (arr2.m_data[i]) {
            arr2.m_data[i]->removeReference();
        }
    }

    int count3 = arr3.m_size;
    for (int i = 0; i < count3; ++i) {
        if (arr3.m_data[i]) {
            arr3.m_data[i]->removeReference();
        }
    }

    HeapB* (__stdcall* getHeap)(unsigned long) = FUN_00d9b080;
    if ((arr4.m_capacityAndFlags & 0x80000000u) == 0) {
        int cap = arr4.m_capacityAndFlags & 0x3fffffff;
        HeapB* h = getHeap(DAT_010f3170);
        h->FUN_008f6d90(arr4.m_data, cap * 4, 0x17);
    }
    if ((arr3.m_capacityAndFlags & 0x80000000u) == 0) {
        int cap = arr3.m_capacityAndFlags & 0x3fffffff;
        HeapB* h = getHeap(DAT_010f3170);
        h->FUN_008f6d90(arr3.m_data, cap * 4, 0x17);
    }
    if ((arr2.m_capacityAndFlags & 0x80000000u) == 0) {
        int cap = arr2.m_capacityAndFlags & 0x3fffffff;
        HeapB* h = getHeap(DAT_010f3170);
        h->FUN_008f6d90(arr2.m_data, cap * 4, 0x17);
    }
    if ((arr1.m_capacityAndFlags & 0x80000000u) == 0) {
        int cap = arr1.m_capacityAndFlags & 0x3fffffff;
        HeapB* h = getHeap(DAT_010f3170);
        h->FUN_008f6d90(arr1.m_data, cap * 4, 0x17);
    }
}
}   // namespace f3m_0098a0e0

// @f3 0x009877d0 (community match, verified in this file)
namespace f3m_009877d0 {
struct E77D0Stream
{
    virtual void v00();
    virtual void Begin(int kind, int size, void* object);
    virtual void Block(const char* name, int size, void* data, int count, int flags);
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void End();
};

struct E77D0Atom
{
    unsigned short unk00;
    unsigned short unk02;
};

struct FUN_009877d0_Contact
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    void* unk20;
    int unk24;
    int unk28;
    int unk2C; int unk30; int unk34; int unk38;
    E77D0Atom* unk3C;
    void hkpSimpleConstraintContactMgr_calcContentStatistics(E77D0Stream* stream);
};

// Writes the contact: its atom block and, when present, the id block.
// pdb: hkpSimpleConstraintContactMgr::calcContentStatistics | hkpSimpleConstraintContactMgr.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void FUN_009877d0_Contact::hkpSimpleConstraintContactMgr_calcContentStatistics(E77D0Stream* stream)
{
    stream->Begin(0, 8, this);
    stream->Block("ContactAtom", 8, unk3C, unk3C->unk02, 0);
    if ((unk28 & 0x80000000) == 0)
        stream->Block("ContactIds", 8, unk20, unk24, unk28 & 0x3fffffff);
    stream->End();
}
}   // namespace f3m_009877d0

// @f3 0x00989aa0 (community match, verified in this file)
namespace f3m_00989aa0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Destroy406{extern unsigned long DAT_010f3170;extern int DAT_00e35e64;struct Heap{void FUN_008f6d90(void*,unsigned int,int);};struct Array{void*data;unsigned int count,capacityFlags;void Free(){if(!(capacityFlags&0x80000000)){unsigned int capacity=capacityFlags&0x3fffffff;Heap*heap=(Heap*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,capacity*4,23);}}};struct Owner{void*vtable;
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
// pdb: hkpPhantom::~hkpPhantom | hkpPhantom.obj | fnv360_0822_retail, call_seq, high
Array first,second;void FUN_009897e0();void FUN_0090c0a0();void FUN_00989aa0();};void Owner::FUN_00989aa0(){vtable=&DAT_00e35e64;FUN_009897e0();second.Free();first.Free();FUN_0090c0a0();}}
}   // namespace f3m_00989aa0

// @f3 0x00986c10 (community match, verified in this file)
namespace deletion_00986c10 {
extern unsigned int DAT_010f3170;extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
extern const void* const DAT_00dcc494[];
struct Heap {void FUN_008f6d90(void*,int,int);};
struct Header {const void* const* vtable;unsigned short memorySizeAndFlags;short refCount;Header* FUN_00986c10(unsigned int);};
// pdb: hkpReportContactMgr::Factory::`scalar deleting destructor' | hkpReportContactMgr.obj | fnv360_0822_debug, objrun_open, low
Header* Header::FUN_00986c10(unsigned int flags){bool release=(flags&1)!=0;vtable=DAT_00dcc494;if(release){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(this,memorySizeAndFlags,34);}return this;}
}

// @f3 0x0098b560 (community match, verified in this file)
namespace deletion_0098b560 {
extern unsigned int DAT_010f3170;extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
extern const void* const DAT_00dcc494[];
struct Heap {void FUN_008f6d90(void*,int,int);};
struct Header {const void* const* vtable;unsigned short memorySizeAndFlags;short refCount;Header* FUN_0098b560(unsigned int);};
Header* Header::FUN_0098b560(unsigned int flags){bool release=(flags&1)!=0;vtable=DAT_00dcc494;if(release){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(this,memorySizeAndFlags,4);}return this;}
}

// @f3 0x00981190 (community match, verified in this file)
namespace f3m_00981190 {
void __cdecl FUN_0097f1a0();
void __cdecl hkpEntityAabbUtil_entityBatchInvalidateAabb(int**,int);
struct CallbackContext {unsigned int unk00;unsigned int unk04;unsigned int unk08;unsigned int unk0c;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3c;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4c;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5c;unsigned int unk60;unsigned int unk64;unsigned int unk68; int value6c;};
struct FUN_00cfa400_Obj {void FUN_00cf9480(int,int,int,void(__cdecl*)(),int);void hkpSimulation_resetCollisionInformationForEntities(int**,int,CallbackContext*,bool);};
// pdb: hkpSimulation::resetCollisionInformationForEntities | hkpSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void FUN_00cfa400_Obj::hkpSimulation_resetCollisionInformationForEntities(int** entries,int count,CallbackContext* context,bool skip){if(!skip)FUN_00cf9480((int)entries,count,context->value6c,FUN_0097f1a0,0);hkpEntityAabbUtil_entityBatchInvalidateAabb(entries,count);}
}   // namespace f3m_00981190

// @f3 0x00989f30 (community match, verified in this file)
namespace f3m_00989f30 {
struct hkBaseObject {virtual ~hkBaseObject() {}};
struct hkReferencedObject : hkBaseObject {
    unsigned short allocationBytes; short references;
    void RemoveReference() {
        if(allocationBytes != 0) {
            --references;
            if(references == 0) delete this;
        }
    }
};
struct Owner {
    unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C;
    hkReferencedObject** data; int count;
    void hkpPhysicsSystem_removeConstraint(int);
};
// pdb: hkpPhysicsSystem::removeConstraint | hkpPhysicsSystem.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void Owner::hkpPhysicsSystem_removeConstraint(int index) {data[index]->RemoveReference(); --count; data[index]=data[count];}
}   // namespace f3m_00989f30

// @f3 0x00989f70 (community match, verified in this file)
namespace f3m_00989f70 {
struct RefObject {void FUN_009316e0();};
struct Array {RefObject** data;int count;unsigned int capacity;void Append(RefObject* value);};
void __cdecl FUN_00901f10(Array*,int);
inline void Array::Append(RefObject* value){if(count==(capacity&0x3FFFFFFF))FUN_00901f10(this,4);data[count]=value;++count;}
struct Owner {unsigned int unk00,unk04;Array objects;void FUN_00989f70(RefObject*);};
// pdb: hkpPhysicsSystem::addRigidBody | hkpPhysicsSystem.obj | fnv360_0822_retail, call_seq, medium
// pdb params: rb
void Owner::FUN_00989f70(RefObject* value){if(value){value->FUN_009316e0();objects.Append(value);}}
}   // namespace f3m_00989f70

// @f3 0x00982c20 (community match, verified in this file)
namespace f3m_00982c20 {
struct Sub982c20 { void FUN_009b4a50(int); void FUN_009b4a40(); };
struct Owner982c20 {
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
    Sub982c20 sub;
    void* FUN_009819f0();
    void FUN_00981e50(float);
    void FUN_00981a30(void**);
    void hkpMultiThreadedSimulation_finishMtStep();
    int FUN_00982c20(float);
};
// pdb: hkpWorld::finishMtStep | hkpWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: jobQueue, threadPool
int Owner982c20::FUN_00982c20(float x) {
    void* original=FUN_009819f0();
    void* p=original;
    if (!original) {
        FUN_00981e50(x);
        sub.FUN_009b4a50(unkec);
    }
    sub.FUN_009b4a40();
    FUN_00981a30(&p);
    if (!original) hkpMultiThreadedSimulation_finishMtStep();
    return 0;
}
}   // namespace f3m_00982c20

// @f3 0x0099f6a0 (community match, verified in this file)
namespace f3m_0099f6a0 {
struct SrcObj {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};

class FunClass {
public:
    void FUN_0099f6a0(float* dest);
};

// pdb: diffCrossDiffDotNormal | hkpTriangleShape.obj | fnv360_0822_retail, objrun_open, low
void FunClass::FUN_0099f6a0(float* dest) {
    SrcObj* src = reinterpret_cast<SrcObj*>(this);

    dest[0] = src->unk20 + src->unk30;
    dest[1] = src->unk24 + src->unk34;
    dest[2] = src->unk28 + src->unk38;
    dest[3] = src->unk2C + src->unk3C;

    dest[0] = src->unk30 + dest[0];
    dest[1] = src->unk34 + dest[1];
    dest[2] = src->unk38 + dest[2];
    dest[3] = src->unk3C + dest[3];

    dest[0] = dest[0] * (double)0.33333334f;
    dest[1] = dest[1] * (double)0.33333334f;
    dest[2] = dest[2] * (double)0.33333334f;
    dest[3] = dest[3] * (double)0.33333334f;
}
}   // namespace f3m_0099f6a0

// @f3 0x0099eed0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0099eed0 {

namespace f3m_0099eed0 {

struct HeapB {
    void* FUN_008f6d30(unsigned int, int);
    void FUN_008f6d90(void*, unsigned int, int);
};
extern HeapB* (__stdcall* const FUN_00d9b080)(unsigned long);

struct Obj {
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
    void* m_data;                     // 0x150
    int m_count;                        // 0x154
    unsigned int m_capacityAndFlags;    // 0x158
    void FUN_0090dc40();
    void FUN_0099eed0();
};

// pdb: hkAlgorithm::quickSortRecursive<hkpSimpleShapePhantom::CollisionDetail,hkpSimpleShapePhantom::OrderByUid> | hkpSimpleShapePhantom.obj | fnv360_1110_retail, objrun, medium
// pdb params: pArr, d, h, cmpLess
void Obj::FUN_0099eed0()
{
    if (m_count == 0) {
        if ((m_capacityAndFlags & 0x80000000u) == 0) {
            unsigned int n = m_capacityAndFlags & 0x3fffffff;
            HeapB* h = FUN_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(m_data, n * 4, 0x17);
        }
        m_data = 0;
        m_count = 0;
        m_capacityAndFlags = (m_capacityAndFlags & 0xc0000000) | 0x80000000;
    }
    FUN_0090dc40();
}

}
}   // namespace f3m_0099eed0

// @f3 0x0098c2b0 (community match, verified in this file)
namespace f3m_0098c2b0 {
struct ItemC2b0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    char* unk90;
    int unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0;
    int unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0;
    int unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110;
    int unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150;
    int unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170;
    int unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190;
    int unk194, unk198, unk19c;
    float qx, qy, qz, qw;
    float vx, vy, vz, vw;
};

struct NodeC2b0
{
    unsigned char type;
    unsigned char subType;
    unsigned short unk02;
    int unk04, unk08, unk0c;
    float qx, qy, qz, qw;
    float tx, ty, tz, tw;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};

struct OutC2b0
{
    float x, y, z, w;
    void hkVector4_setRotatedDir(const void* matrix, const void* vector);
};

struct CtxC2b0
{
    int unk00, unk04, unk08, unk0c;
};

struct ArrC2b0
{
    ItemC2b0** data;
    int count;
};

extern "C" void _ReadWriteBarrier(void);

void FUN_0098c2b0(CtxC2b0* ctx, ArrC2b0* arr)
{
    for (int i = 0; i < arr->count; i++)
    {
        ItemC2b0* item = arr->data[i];
        NodeC2b0* node = (NodeC2b0*)(item->unk90 + ctx->unk0c);
        node->qx = item->qx;
        node->qy = item->qy;
        node->qz = item->qz;
        node->qw = item->qw;
        _ReadWriteBarrier();
        if (node->subType != 0)
        {
            node->tx = item->vx;
            node->ty = item->vy;
            node->tz = item->vz;
            node->tw = item->vw;
        }
        else
        {
            ((OutC2b0*)&node->tx)->hkVector4_setRotatedDir(&node->m00, &item->vx);
        }
    }
}
}   // namespace f3m_0098c2b0

// @f3 0x00990de0 (community match, verified in this file)
namespace f3m_00990de0 {
struct FUN_00990de0_Obj {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    float unk40; float unk44; float unk48; float unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    float unk60; float unk64; float unk68; float unk6C;
    void FUN_00990de0(float* out1, float* out2);
};
void FUN_00990de0_Obj::FUN_00990de0(float* out1, float* out2)
{
    out1[0] = -unk40;
    out1[1] = -unk44;
    out1[2] = -unk48;
    out1[3] = -unk4C;
    out2[0] = 1.0f / unk60;
    out2[1] = 1.0f / unk64;
    out2[2] = 1.0f / unk68;
    out2[0] *= 65532.0;
    out2[1] *= 65532.0;
    out2[2] *= 65532.0;
    out2[3] = 65532.0f;
    out2[0] += out1[0];
    out2[1] += out1[1];
    out2[2] += out1[2];
    out2[3] += out1[3];
}
}   // namespace f3m_00990de0

// @f3 0x00981680 (community match, verified in this file)
namespace f3m_00981680 {
namespace f3m_00981680 {
struct QObj {
    int unk00; char unk04; signed char off05; char unk06, unk07;
    int unk08, unk0C;
    signed char off10; char unk11, unk12, unk13;
    int unk14;
    char type18;
};
struct QTarget { int unk[48]; int valueC0; };
inline QObj* Base(QObj* p) { return (QObj*)((char*)p + p->off05); }
inline QTarget* Target(QObj* p) { return p->type18 == 1 ? (QTarget*)((char*)p + p->off10) : 0; }
struct QPair { QObj* first; QObj* second; };
}
using namespace f3m_00981680;
bool __cdecl FUN_00981680(QPair* left, QPair* right)
{
    QObj* a = Base(left->first);
    QObj* b = Base(left->second);
    QObj* c = Base(right->first);
    QObj* d = Base(right->second);
    int va = Target(a)->valueC0;
    int vb = Target(b)->valueC0;
    int vc = Target(c)->valueC0;
    QTarget* td = Target(d);
    if (va < vc) return true;
    if (va == vc) return vb < td->valueC0;
    return false;
}
}   // namespace f3m_00981680

// @f3 0x0098b190 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern int DAT_00e7da3c;
extern int DAT_00dcc494;
namespace f3m_0098b190 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct A270Heap98b {
    void FUN_008f6d90(void* data, unsigned int bytes, int cls) throw();
};
struct A270Arr98b {
    int* data;
    int size;
    int capacityAndFlags;
    ~A270Arr98b() throw() {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int cap = capacityAndFlags & 0x3fffffff;
            A270Heap98b* h = (A270Heap98b*)TlsGetValue(DAT_010f3170);
            h->FUN_008f6d90(data, cap * 4, 0x17);
        }
    }
};
struct A270Base98b {
    void* vtable;
    int unk04;
    ~A270Base98b() throw() { vtable = &DAT_00dcc494; }
};
struct FUN_0098b190 : A270Base98b {
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    A270Arr98b unk38;
    int unk44;
    A270Arr98b unk48;
    int unk54, unk58;
    A270Arr98b unk5C;
    ~FUN_0098b190() throw();
};
// pdb: hkpSimulationIsland::~hkpSimulationIsland | hkpSimulationIsland.obj | fnv360_0822_retail, call_seq, medium
FUN_0098b190::~FUN_0098b190() throw() {
    vtable = &DAT_00e7da3c;
}
}   // namespace f3m_0098b190

// @f3 0x00989940 (community match, verified in this file)
namespace f3m_00989940 {
struct IntArray {
    int* m_data;
    int m_size;
    int m_capacityAndFlags;

    int indexOf(int value) const
    {
        for (int i = 0; i < m_size; ++i)
            if (m_data[i] == value)
                return i;
        return -1;
    }
    void removeAtAndCopy(int index)
    {
        m_size--;
        for (int i = index; i < m_size; ++i)
            m_data[i] = m_data[i + 1];
    }
};

struct FUN_00989940_Obj {
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
    IntArray unk80;
    void hkpPhantom_removePhantomOverlapListener(int value);
};

// pdb: hkpPhantom::removePhantomOverlapListener | hkpPhantom.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_00989940_Obj::hkpPhantom_removePhantomOverlapListener(int value)
{
    unk80.removeAtAndCopy(unk80.indexOf(value));
}
}   // namespace f3m_00989940

// @f3 0x0099d7d0 (community match, verified in this file)
namespace f3m_0099d7d0 {
struct FUN_0099d7d0_Obj {
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
    float unkC0;
    float unkC4;
    float unkC8;
    float unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    float unkE0;
    float unkE4;
    float unkE8;
    float unkEC;

    void __thiscall FUN_0099d7d0(float* values);
};

void __thiscall FUN_0099d7d0_Obj::FUN_0099d7d0(float* values)
{
    unkE0 = static_cast<volatile float&>(unkC0) * values[0] + unkE0;
    unkE4 = unkC4 * values[1] + unkE4;
    unkE8 = unkC8 * values[2] + unkE8;
    unkEC = unkCC * values[3] + unkEC;
}

}   // namespace f3m_0099d7d0

// @f3 0x00985e20 (community match, verified in this file)
namespace f3m_00985e20 {
namespace f3m_00985e20 {
struct Pair { int first; int second; };
struct PairArray;
void __cdecl FUN_00901f10(PairArray* array, int grow);
struct PairArray {
    Pair* data;
    int count;
    unsigned int capacity;
    void RemoveAt(int index) {
        count -= 1;
        for (int i = index; i < count; i++) {
            data[i] = data[i + 1];
        }
    }
    void Push(int first, int second) {
        if (count == (int)(capacity & 0x3fffffff))
            FUN_00901f10(this, 8);
        Pair* slot = &data[count++];
        slot->first = first;
        slot->second = second;
    }
};
struct Owner {
    char unk00[0x1e24];
    PairArray pairs;
    void FUN_009855c0(int first, int second, int flag);
    void FUN_00985e20(int first, int second);
};
// pdb: hkpCollisionDispatcher::registerAlternateShapeType | hkpCollisionDispatcher.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: primaryType, alternateType
void Owner::FUN_00985e20(int first, int second)
{
    for (int i = 0; i < pairs.count; i++) {
        Pair* p = &pairs.data[i];
        if (p->first == first && p->second == second) {
            pairs.RemoveAt(i);
            i--;
        }
    }
    FUN_009855c0(first, second, 0);
    pairs.Push(first, second);
}
}
}   // namespace f3m_00985e20

// @f3 0x0099d2a0 (community match, verified in this file)
namespace KeyMotion2145 {
struct Position;
struct Rotation;
extern void* DAT_00e3599c[];

struct FUN_008f8530 {
    void** table;
    unsigned unk04;
    unsigned char type, unk09, unk0a, unk0b;
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
    FUN_008f8530(const Position&, const Rotation&, bool);
};

struct InverseMass4 {
    float x, y, z, w;
    void Clear(float value) {
        w = value;
        z = value;
        y = value;
        x = value;
    }
};

struct FUN_0099d2a0 : FUN_008f8530 {
    InverseMass4 inverse;
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
    FUN_008f8530* savedMotion;
    unsigned short savedSize;
    FUN_0099d2a0(const Position&, const Rotation&);
};

// pdb: hkpKeyframedRigidMotion::hkpKeyframedRigidMotion | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, call_gap, high
// pdb params: position, rotation
FUN_0099d2a0::FUN_0099d2a0(const Position& position, const Rotation& rotation)
    : FUN_008f8530(position, rotation, false)
{
    const float zero = 0.0f;
    table = DAT_00e3599c;
    savedMotion = 0;
    savedSize = 0;
    inverse.Clear(zero);
    type = 6;
}
}

// @f3 0x0099fc60 (community match, verified in this file)
namespace f3m_0099fc60 {
namespace f3m_0099fc60 {

struct V4 { float x, y, z, w; };

struct Obj {
    char pad00[0x10];
    float w;             // 0x10
    char pad14[3];       // 0x14..0x16
    unsigned char flag;  // 0x17
    char pad18[8];       // 0x18..0x1f
    V4 r0;               // 0x20
    V4 r1;               // 0x30
    V4 r2;               // 0x40
    V4 t;                // 0x50
    V4* FUN_0099fc60(V4* out);
};

static void addv(V4& d, const V4& a, const V4& b)
{
    d.x = a.x + b.x;
    d.y = a.y + b.y;
    d.z = a.z + b.z;
    d.w = a.w + b.w;
}

V4* Obj::FUN_0099fc60(V4* out)
{
    V4* p = out + 1;

    out[0].x = r0.x;
    out[0].y = r0.y;
    out[0].z = r0.z;
    out[0].w = r0.w;
    out[0].w = w;

    p->x = r1.x;
    p->y = r1.y;
    p->z = r1.z;
    p->w = r1.w;
    p->w = w;
    p++;

    p->x = r2.x;
    p->y = r2.y;
    p->z = r2.z;
    p->w = r2.w;
    p->w = w;
    p++;

    if (flag) {
        p->x = r0.x + t.x;
        p->y = r0.y + t.y;
        p->z = r0.z + t.z;
        p->w = r0.w + t.w;
        p->w = w;
        p++;

        addv(p[0], r1, t);
        p[0].w = w;

        addv(p[1], r2, t);
        p[1].w = w;
    }

    return out;
}

}
}   // namespace f3m_0099fc60

// @f3 0x00988f20 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d920[];
extern const char DAT_00e7d914[];
extern const char DAT_00e32798[];
namespace f3m_00988f20 {
extern "C" void _ReadWriteBarrier(void);
namespace f3m_00988f20 {

struct Item988 {
    virtual void v0();
    virtual void Run1(void* a);
    virtual void Run2(void* a);
};
struct Rec988 { const void* label; unsigned int ticks; unsigned int unk08; };
struct Buf988 { int unk00; Rec988* cur; int unk08; Rec988* end; };
extern Buf988* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Arr988 { Item988** data; int count; };
struct Arr988b { Item988** data; unsigned short count; unsigned short unk06; };
struct Child988 { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; Arr988b* cont; };
static __declspec(noinline) void FUN_00988440(Arr988* a) { for (int i = a->count - 1; i >= 0; --i) if (a->data[i] == 0) { --a->count; for (int j = i; j < a->count; ++j) a->data[j] = a->data[j + 1]; } }
static __declspec(noinline) void FUN_00988480(Arr988b* a) { for (int i = a->count - 1; i >= 0; --i) if (a->data[i] == 0) { --a->count; for (int j = i; j < a->count; ++j) a->data[j] = a->data[j + 1]; } }
struct Owner988 {
    int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int refs; int unk88; char unk8c;
    int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128;
    Arr988 arr;
    void FUN_00902550();
};
struct Self988 {
    int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44;
    Child988** children; int childCount;
};

// pdb: hkpWorldCallbackUtil::fireIslandActivated | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_fireIslandActivated(Owner988* o, Self988* sp)
{
    volatile unsigned int t[2];
    o->refs++;
    Arr988* arr = &o->arr;
    for (int i = arr->count - 1; i >= 0; --i) {
        if (arr->data[i] != 0) {
            Buf988* (__stdcall* getter)(unsigned long) = DAT_00d9b080;
            Buf988* b = getter(DAT_0116913c);
            Rec988* r = b->cur;
            if (r < b->end) {
                r->label = DAT_00e7d920;
                _ReadWriteBarrier();
                t[0] = (unsigned int)__rdtsc();
                r->ticks = t[0];
                b->cur = r + 1;
            }
            Item988* it = arr->data[i];
            it->Run1(sp);
            b = getter(DAT_0116913c);
            r = b->cur;
            if (r < b->end) {
                r->label = DAT_00e32798;
                _ReadWriteBarrier();
                t[1] = (unsigned int)__rdtsc();
                r->ticks = t[1];
                b->cur = r + 1;
            }
        }
    }
    FUN_00988440(arr);
    for (int j = 0; j < sp->childCount; j++) {
        Child988* child = sp->children[j];
        if (child->cont) {
            Arr988b* c = child->cont;
            for (int i = c->count - 1; i >= 0; --i) {
                if (c->data[i] != 0) {
                    Buf988* b = DAT_00d9b080(DAT_0116913c);
                    Rec988* r = b->cur;
                    if (r < b->end) {
                        r->label = DAT_00e7d914;
                        _ReadWriteBarrier();
                        t[1] = (unsigned int)__rdtsc();
                        r->ticks = t[1];
                        b->cur = r + 1;
                    }
                    c->data[i]->Run2(sp->children[j]);
                    b = DAT_00d9b080(DAT_0116913c);
                    r = b->cur;
                    if (r < b->end) {
                        r->label = DAT_00e32798;
                        _ReadWriteBarrier();
                        t[0] = (unsigned int)__rdtsc();
                        r->ticks = t[0];
                        b->cur = r + 1;
                    }
                }
            }
            FUN_00988480(c);
        }
    }
    Owner988* oe = o;
    if (--oe->refs == 0 && oe->unk8c == 0 && oe->unk80 != 0)
        oe->FUN_00902550();
}


}
}   // namespace f3m_00988f20

// @f3 0x009890d0 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d938[];
extern const char DAT_00e7d92c[];
extern const char DAT_00e32798[];
namespace f3m_009890d0 {
namespace f3m_009890d0 {

extern "C" void _ReadWriteBarrier(void);

struct Entity;
struct Event;

struct Listener {
    virtual void v0();
    virtual void OnEntity(Entity* entity);
    virtual void OnEvent(Event* event);
};

struct Rec {
    const void* label;
    unsigned int ticks;
    unsigned int unk08;
};

struct Buf {
    int unk00;
    Rec* cur;
    int unk08;
    Rec* end;
};

extern void* (__stdcall* const DAT_00d9b080)(unsigned long);

struct WorldList {
    Listener** data;
    int count;
};

struct EntityList {
    Listener** data;
    unsigned short count;
};

static __declspec(noinline) void FUN_00988440(WorldList* list)
{
    for (int i = list->count - 1; i >= 0; i--) {
        if (list->data[i] == 0) {
            list->count = (list->count - 1);
            for(int k=i;k<(int)list->count;++k) list->data[k]=list->data[k+1];
        }
    }
}
static __declspec(noinline) void FUN_00988480(EntityList* list)
{
    for (int i = list->count - 1; i >= 0; i--) {
        if (list->data[i] == 0) {
            list->count = (unsigned short)(list->count - 1);
            for(int k=i;k<(int)list->count;++k) list->data[k]=list->data[k+1];
        }
    }
}

struct Entity {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8;
    EntityList* listeners;
};

struct Event {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    Entity** entities;
    int entityCount;
};

struct World {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int pending;
    int lockCount;
    int unk88;
    bool blocked;
    char unk8d, unk8e, unk8f;
    int unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128;
    WorldList listeners;
    void FUN_00902550();
    void Lock() { lockCount += 1; }
    void Unlock() { if (--lockCount == 0 && !blocked && pending != 0) FUN_00902550(); }
};

// pdb: hkpWorldCallbackUtil::fireIslandDeactivated | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_fireIslandDeactivated(World* game, Event* scene)
{
    struct
    {
        volatile unsigned int tick1;
        volatile unsigned int tick2;
    } timer;
    ++game->lockCount;
    WorldList* pSlots = &game->listeners;
    for (int i = pSlots->count - 1; i >= 0; --i)
    {
        if (pSlots->data[i])
        {
            void* (__stdcall* getter)(unsigned long) = DAT_00d9b080;
            {
                Buf* log = (Buf*)getter(DAT_0116913c);
                Rec* current = log->cur;
                if (current < log->end)
                {
                    current->label = DAT_00e7d938;
                    _ReadWriteBarrier();
                    timer.tick1 = (unsigned int)__rdtsc();
                    current->ticks = timer.tick1;
                    log->cur = current + 1;
                }
            }
            ((Listener*)pSlots->data[i])->OnEvent(scene);
            {
                Buf* log = (Buf*)getter(DAT_0116913c);
                Rec* current = log->cur;
                if (current < log->end)
                {
                    current->label = DAT_00e32798;
                    _ReadWriteBarrier();
                    timer.tick2 = (unsigned int)__rdtsc();
                    current->ticks = timer.tick2;
                    log->cur = current + 1;
                }
            }
        }
    }
    FUN_00988440(pSlots);
    for (int i = 0; i < scene->entityCount; ++i)
    {
        Entity* ent = scene->entities[i];
        if (ent->listeners)
        {
            EntityList* callbacks = ent->listeners;
            for (int j = (int)callbacks->count - 1; j >= 0; --j)
            {
                if (callbacks->data[j])
                {
                    {
                        Buf* log = (Buf*)DAT_00d9b080(DAT_0116913c);
                        Rec* current = log->cur;
                        if (current < log->end)
                        {
                            current->label = DAT_00e7d92c;
                            _ReadWriteBarrier();
                            timer.tick2 = (unsigned int)__rdtsc();
                            current->ticks = timer.tick2;
                            log->cur = current + 1;
                        }
                    }
                    callbacks->data[j]->OnEntity(scene->entities[i]);
                    {
                        Buf* log = (Buf*)DAT_00d9b080(DAT_0116913c);
                        Rec* current = log->cur;
                        if (current < log->end)
                        {
                            current->label = DAT_00e32798;
                            _ReadWriteBarrier();
                            timer.tick1 = (unsigned int)__rdtsc();
                            current->ticks = timer.tick1;
                            log->cur = current + 1;
                        }
                    }
                }
            }
            FUN_00988480(callbacks);
        }
    }
    game->Unlock();
}

}
}   // namespace f3m_009890d0

// @f3 0x0098a4b0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0098a4b0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace f3m_0098a4b0 {

struct Heap {
    void* FUN_008f6d30(unsigned int bytes, int tag) throw();
    void FUN_008f6d90(void* p, unsigned int bytes, int tag) throw();
};
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();

template <class T> struct Array {
    T* data;
    int count;
    int capAndFlags;
    void init() throw() { data = 0; count = 0; capAndFlags = 0x80000000; }
    void clearAndDeallocate() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
            h->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
    void setSize(int n) throw() {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        count = n;
    }
    T& operator[](int i) throw() { return data[i]; }
    const T& operator[](int i) const throw() { return data[i]; }
    int indexOf(T t) const throw() {
        for (int i = 0; i < count; i++)
            if (data[i] == t) return i;
        return -1;
    }
};

struct hkpRigidBody {
    virtual void v00() throw(); virtual void v04() throw(); virtual void v08() throw(); virtual void v0c() throw();
    virtual void v10() throw(); virtual void v14() throw();
    virtual hkpRigidBody* clone() const throw();
};
typedef hkpRigidBody hkpEntity;
struct hkpPhantom {
    virtual void v00() throw(); virtual void v04() throw(); virtual void v08() throw(); virtual void v0c() throw();
    virtual void v10() throw(); virtual void v14() throw(); virtual void v18() throw(); virtual void v1c() throw();
    virtual void v20() throw(); virtual void v24() throw();
    virtual hkpPhantom* clone() const throw();
};
struct hkpConstraintInstance {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    hkpEntity* entityA;
    hkpEntity* entityB;
    hkpConstraintInstance* FUN_0097a150(hkpRigidBody* a, hkpRigidBody* b, int c) throw();
};
struct hkpAction {
    virtual void v00() throw(); virtual void v04() throw(); virtual void v08() throw(); virtual void v0c() throw();
    virtual void getEntities(Array<hkpEntity*>& out) throw();
    virtual void getPhantoms(Array<hkpPhantom*>& out) throw();
    virtual void v18() throw();
    virtual hkpAction* clone(const Array<hkpEntity*>& entities, const Array<hkpPhantom*>& phantoms) const throw();
};

struct hkpPhysicsSystem {
    void* vtbl;
    unsigned short memSize;
    unsigned short refCount;
    Array<hkpRigidBody*> rigidBodies;
    Array<hkpConstraintInstance*> constraints;
    Array<hkpAction*> actions;
    Array<hkpPhantom*> phantoms;
    const char* name;
    unsigned int userData;
    bool active;

    static void* operator new(unsigned int n) {
        Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
        void* p = h->FUN_008f6d30(n, 0x2f);
        ((hkpPhysicsSystem*)p)->memSize = (unsigned short)n;
        return p;
    }
    hkpPhysicsSystem() throw();
    hkpPhysicsSystem* hkpPhysicsSystem_clone() const;
};

// pdb: hkpPhysicsSystem::clone | hkpPhysicsSystem.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
hkpPhysicsSystem* hkpPhysicsSystem::hkpPhysicsSystem_clone() const
{
    hkpPhysicsSystem* s = new hkpPhysicsSystem();

    s->name = name;
    s->userData = userData;
    s->active = active;

    s->rigidBodies.setSize(rigidBodies.count);
    s->phantoms.setSize(phantoms.count);
    s->constraints.setSize(constraints.count);
    s->actions.setSize(actions.count);

    int i;
    for (i = 0; i < rigidBodies.count; i++)
        s->rigidBodies[i] = rigidBodies[i]->clone();

    for (i = 0; i < phantoms.count; i++)
        s->phantoms[i] = phantoms[i]->clone();

    for (i = 0; i < constraints.count; i++) {
        hkpConstraintInstance* c = constraints[i];
        hkpEntity* ea = c->entityA;
        int a = rigidBodies.indexOf(ea);
        hkpEntity* eb = c->entityB;
        int b = rigidBodies.indexOf(eb);
        hkpRigidBody* ra = s->rigidBodies[a];
        hkpRigidBody* rb = s->rigidBodies[b];
        s->constraints[i] = c->FUN_0097a150(ra, rb, 0);
    }

    for (i = 0; i < actions.count; i++) {
        hkpAction* action = actions[i];
        if (!action) {
            s->actions[i] = 0;
            continue;
        }
        {
            Array<hkpEntity*> oldEntities;
            oldEntities.init();
            _ReadWriteBarrier();
            action->getEntities(oldEntities);
            Array<hkpEntity*> newEntities;
            newEntities.init();
            int numEntities = oldEntities.count;
            newEntities.setSize(numEntities);
            for (int j = 0; j < numEntities; j++) {
                hkpEntity* e = oldEntities[j];
                int index = rigidBodies.indexOf(e);
                newEntities[j] = s->rigidBodies[index];
            }

            Array<hkpPhantom*> oldPhantoms;
            oldPhantoms.init();
            _ReadWriteBarrier();
            action->getPhantoms(oldPhantoms);
            Array<hkpPhantom*> newPhantoms;
            newPhantoms.init();
            int numPhantoms = oldPhantoms.count;
            newPhantoms.setSize(numPhantoms);
            for (int k = 0; k < numPhantoms; k++) {
                hkpPhantom* p = oldPhantoms[k];
                int index = phantoms.indexOf(p);
                newPhantoms[k] = s->phantoms[index];
            }

            s->actions[i] = action->clone(newEntities, newPhantoms);
            newPhantoms.clearAndDeallocate();
            oldPhantoms.clearAndDeallocate();
            newEntities.clearAndDeallocate();
            oldEntities.clearAndDeallocate();
        }
    }

    return s;
}
}
}   // namespace f3m_0098a4b0

// @f3 0x00989280 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d944[];
extern const char DAT_00e32798[];
namespace f3m_00989280 {
namespace f3m_00989280 {

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct World;

struct PostSimListener {
    virtual void v0();
    virtual void postSimulationCallback(World* world);
};

struct Rec {
    const void* label;
    unsigned int ticks;
    unsigned int unk08;

    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};

struct Stream {
    int unk00;
    Rec* cur;
    int unk08;
    Rec* end;
};

struct Array {
    PostSimListener** data;
    int size;
    int capacity;
};

static __declspec(noinline) void FUN_00988440(Array& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}

struct World {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134;
    Array postSimulationListeners;
};

// pdb: hkpWorldCallbackUtil::firePostSimulationCallback | hkpWorldCallbackUtil.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(World* world)
{
    Array& listeners = world->postSimulationListeners;
    int previousSize = listeners.size;
    for (int i = previousSize - 1; i >= 0; --i)
    {
        if (previousSize > listeners.size)
        {
            i += listeners.size - previousSize;
            previousSize = listeners.size;
        }
        if (listeners.data[i])
        {
            Stream* b = (Stream*)TlsGetValue(DAT_0116913c);
            Rec* r = b->cur;
            if (r < b->end) {
                r->label = DAT_00e7d944;
                _ReadWriteBarrier();
                r->setTime();
                b->cur = r + 1;
            }
            listeners.data[i]->postSimulationCallback(world);
            b = (Stream*)TlsGetValue(DAT_0116913c);
            r = b->cur;
            if (r < b->end) {
                r->label = DAT_00e32798;
                _ReadWriteBarrier();
                r->setTime();
                b->cur = r + 1;
            }
        }
    }
    FUN_00988440(listeners);
}
}
}   // namespace f3m_00989280

// @f3 0x00990a90 (community match, verified in this file)
namespace f3m_00990a90 {
// 0x00990A90 - static helper under /O2's private register convention:
// the two unsigned-short arguments arrive in eax and ecx, the small struct
// (one unsigned short) is pushed on the stack.  It counts how many of the
// two values lie below the pivot:
//     (a < pivot) + (k.value < pivot)
// written as subtraction and sign extraction so the compiler emits sub/shr.

struct UShortValue {
    unsigned short value;
};

static __declspec(noinline) int FUN_00990a90(unsigned short a, unsigned short pivot, UShortValue k)
{
    return ((unsigned)(a - pivot) >> 31) + ((unsigned)(k.value - pivot) >> 31);
}

volatile unsigned short g_in_a;
volatile unsigned short g_in_pivot;
volatile UShortValue    g_in_value;
volatile int            g_out_count;

void caller_of_FUN_00990a90()
{
    UShortValue k;
    k.value = g_in_value.value;
    g_out_count = FUN_00990a90(g_in_a, g_in_pivot, k);
}
}   // namespace f3m_00990a90

// @f3 0x00981db0 (community match, verified in this file)
namespace f3m_00981db0 {
namespace pair_sort_981db0 {
struct BroadPhaseHandle;
struct Collidable;
struct Entity {
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
    int uid;
};

struct Collidable {
    int unk00, unk04, unk08, unk0c;
    signed char ownerOffset;
    unsigned char unk11, unk12, unk13;
    unsigned int handleId;
    unsigned char handleType;

    Entity* GetEntity() {
        if (handleType == 1)
            return reinterpret_cast<Entity*>(reinterpret_cast<char*>(this) + ownerOffset);
        return 0;
    }
};

struct BroadPhaseHandle {
    unsigned int id;
    unsigned char type;
    signed char ownerOffset;

    Collidable* GetCollidable() {
        return reinterpret_cast<Collidable*>(reinterpret_cast<char*>(this) + ownerOffset);
    }
};

struct Pair { BroadPhaseHandle* a; BroadPhaseHandle* b; };
struct Array { Pair* data; int count; };
typedef bool (__cdecl* Compare)(const Pair&, const Pair&);
bool __cdecl FUN_00981680(const Pair&, const Pair&);
void __cdecl FUN_00982ee0(Pair*, int, int, Compare);

// pdb: sortPairList | hkpMultithreadedSimulation.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl sortPairList(Array* array)
{
    Pair* p = array->data;
    Pair* const end = p + array->count;
    if (p < end) do {
        BroadPhaseHandle* a = p->a;
        BroadPhaseHandle* b = p->b;
        Collidable* collidableA = a->GetCollidable();
        Collidable* collidableB = b->GetCollidable();
        const int uidA = collidableA->GetEntity()->uid;
        const int uidB = collidableB->GetEntity()->uid;
        if (uidA > uidB) {
            p->a = static_cast<BroadPhaseHandle* const volatile&>(p->b);
            p->b = a;
        }
        ++p;
    } while (p < end);

    if (array->count > 1)
        FUN_00982ee0(array->data, 0, array->count - 1, FUN_00981680);
}
}

}   // namespace f3m_00981db0

// @f3 0x0099d650 (community match, verified in this file)
namespace f3m_0099d650 {
struct V4d650 { float x, y, z, w; };
struct M34d650 { V4d650 r0; V4d650 r1; V4d650 r2; };
struct __declspec(align(16)) V16d650 { float x, y, z, w; };

struct Cd650 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    float unkC0;
    void FUN_0099d650(M34d650* out);
};

void Cd650::FUN_0099d650(M34d650* out)
{
    V16d650 t;
    t.x = 0.0f;
    t.y = 0.0f;
    t.z = 0.0f;
    t.w = unkC0;
    V4d650& r0 = out->r0;
    V4d650& r1 = out->r1;
    V4d650& r2 = out->r2;
    out->r0.x = 0.0f; out->r0.y = 0.0f; out->r0.z = 0.0f; out->r0.w = 0.0f;
    out->r1.x = 0.0f; out->r1.y = 0.0f; out->r1.z = 0.0f; out->r1.w = 0.0f;
    out->r2.x = 0.0f; out->r2.y = 0.0f; out->r2.z = 0.0f; out->r2.w = 0.0f;
    float* q = &r0.x;
    q[0] = t.w; q[5] = t.w; q[10] = t.w;
}
}   // namespace f3m_0099d650

// @f3 0x0099d9c0 (community match, verified in this file)
#include <intrin.h>
namespace f3m_0099d9c0 {
namespace n99d9c0 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct Mat3 { Vec4 c0, c1, c2; };
}
struct C99d9c0 {
    char pad[0xc0];
    float ix, iy, iz;
    void FUN_0099d9c0(n99d9c0::Mat3* out);
};
// pdb: hkpBoxMotion::getInertiaLocal | hkpBoxMotion.obj | tesv_win, objrun, medium
void C99d9c0::FUN_0099d9c0(n99d9c0::Mat3* out)
{
    n99d9c0::Vec4 inv;
    float one = 1.0f;
    inv.y = one / ix;
    inv.z = one / iy;
    inv.w = one / iz;
    out->c0.w = out->c0.z = out->c0.y = out->c0.x = 0.0f;
    out->c1.w = out->c1.z = out->c1.y = out->c1.x = 0.0f;
    out->c2.w = out->c2.z = out->c2.y = out->c2.x = 0.0f;
    _ReadWriteBarrier();
    out->c0.x = inv.y;
    out->c1.y = inv.z;
    out->c2.z = inv.w;
}
}   // namespace f3m_0099d9c0

// @f3 0x0099dc20 (community match, verified in this file)
namespace f3m_0099dc20 {
struct __declspec(align(16)) Vdc20
{
    float x, y, z, w;
};
struct Mdc20
{
    Vdc20 c0, c1, c2;
    __forceinline void setZero()
    {
        c0.x = 0.0f; c0.y = 0.0f; c0.z = 0.0f; c0.w = 0.0f;
        c1.x = 0.0f; c1.y = 0.0f; c1.z = 0.0f; c1.w = 0.0f;
        c2.x = 0.0f; c2.y = 0.0f; c2.z = 0.0f; c2.w = 0.0f;
    }
    __forceinline void setDiagonal(float a, float b, float c)
    {
        setZero();
        (*this)(0, 0) = a; (*this)(1, 1) = b; (*this)(2, 2) = c;
    }
    float& operator()(int r, int c)
    {
        return (&c0.x)[c * 4 + r];
    }
    void FUN_0096d0f0(const Mdc20& m);
};
struct Cdc20
{
    char pad[0x10];
    Mdc20 m10;
    char pad2[0xc0 - 0x40];
    float m_c0, m_c4, m_c8;
    void FUN_0099dc20(Mdc20& out);
};
// pdb: hkpBoxMotion::getInertiaWorld | hkpBoxMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: inertia
void Cdc20::FUN_0099dc20(Mdc20& out)
{
    __declspec(align(16)) struct { float pad, x, y, z; } inv;
    inv.x = 1.0f / m_c0;
    inv.y = 1.0f / m_c4;
    inv.z = 1.0f / m_c8;
    out.setDiagonal(inv.x, inv.y, inv.z);
    out.FUN_0096d0f0(m10);
}
}   // namespace f3m_0099dc20

// @f3 0x009897a0 (community match, verified in this file)
namespace f3m_009897a0 {
struct PtrList_9897a0 {
    void** data;
    int count;
};

// pdb: hkpPhantom::removeNullOverlapListeners | hkpPhantom.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_gap_sim), high
static __declspec(noinline) void hkpPhantom_removeNullOverlapListeners(PtrList_9897a0* a)
{
    for (int i = a->count - 1; i >= 0; i--) {
        if (!a->data[i]) {
            a->count--;
            for (int j = i; j < a->count; j++)
                a->data[j] = a->data[j + 1];
        }
    }
}

PtrList_9897a0* volatile g_list_9897a0;
void caller_of_FUN_009897a0() { hkpPhantom_removeNullOverlapListeners(g_list_9897a0); }
}   // namespace f3m_009897a0

// @f3 0x0099e370 (community match, verified in this file)
namespace f3m_0099e370 {
struct __declspec(align(16)) VXe370
{
    float x, y, z, w;
};
struct MXe370
{
    VXe370 c0, c1, c2;
    __forceinline void setZero()
    {
        c0.x = 0.0f; c0.y = 0.0f; c0.z = 0.0f; c0.w = 0.0f;
        c1.x = 0.0f; c1.y = 0.0f; c1.z = 0.0f; c1.w = 0.0f;
        c2.x = 0.0f; c2.y = 0.0f; c2.z = 0.0f; c2.w = 0.0f;
    }
    __forceinline void setDiagonal(float a, float b, float c)
    {
        setZero();
        (*this)(0, 0) = a; (*this)(1, 1) = b; (*this)(2, 2) = c;
    }
    float& operator()(int r, int c)
    {
        return (&c0.x)[c * 4 + r];
    }
    void FUN_0096d0f0(const MXe370& m);
};
struct Ce370
{
    char pad[0xc0];
    float m_c0;
    void FUN_0099e370(MXe370& out);
};
void Ce370::FUN_0099e370(MXe370& out)
{
    VXe370 v;
    float s = m_c0;
    v.x = s; v.y = s; v.z = s; v.w = s;
    out.setDiagonal(v.x, v.y, v.z);
}
}   // namespace f3m_0099e370

// @f3 0x0099e1b0 (community match, verified in this file)
namespace f3m_0099e1b0 {
struct __declspec(align(16)) VXe1b0
{
    float x, y, z, w;
};
struct MXe1b0
{
    VXe1b0 c0, c1, c2;
    __forceinline void setZero()
    {
        c0.x = 0.0f; c0.y = 0.0f; c0.z = 0.0f; c0.w = 0.0f;
        c1.x = 0.0f; c1.y = 0.0f; c1.z = 0.0f; c1.w = 0.0f;
        c2.x = 0.0f; c2.y = 0.0f; c2.z = 0.0f; c2.w = 0.0f;
    }
    __forceinline void setDiagonal(float a, float b, float c)
    {
        setZero();
        (*this)(0, 0) = a; (*this)(1, 1) = b; (*this)(2, 2) = c;
    }
    float& operator()(int r, int c)
    {
        return (&c0.x)[c * 4 + r];
    }
    void FUN_0096d0f0(const MXe1b0& m);
};
struct Ce1b0
{
    char pad[0xc0];
    float m_c0;
    void FUN_0099e1b0(MXe1b0& out);
};
void Ce1b0::FUN_0099e1b0(MXe1b0& out)
{
    VXe1b0 v;
    float s = 1.0f / m_c0;
    v.x = s; v.y = s; v.z = s; v.w = s;
    out.setDiagonal(v.x, v.y, v.z);
}
}   // namespace f3m_0099e1b0

// @f3 0x0099d6a0 (community match, verified in this file)
namespace f3m_0099d6a0 {
struct __declspec(align(16)) Vd6a0
{
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void setSub4(const Vd6a0& a, const Vd6a0& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void setCross(const Vd6a0& v1, const Vd6a0& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline void addMul4(float rs, const Vd6a0& a)
    {
        float r = float(rs);
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    __forceinline void addMul4(const Vd6a0& a, const Vd6a0& b)
    {
        x += a.x * b.x; y += a.y * b.y; z += a.z * b.z; w += a.w * b.w;
    }
};
struct Cd6a0
{
    char pad[0x60];
    Vd6a0 m_com;
    char pad2[0xc0 - 0x70];
    Vd6a0 m_invInertia;
    Vd6a0 m_linVel;
    Vd6a0 m_angVel;
    void FUN_0099d6a0(const Vd6a0& imp, const Vd6a0& pos);
};
void Cd6a0::FUN_0099d6a0(const Vd6a0& imp, const Vd6a0& pos)
{
    float invMass = m_invInertia.w;
    m_linVel.addMul4(invMass, imp);
    Vd6a0 rel;
    rel.setSub4(pos, m_com);
    Vd6a0 c;
    c.setCross(rel, imp);
    m_angVel.addMul4(m_invInertia, c);
}
}   // namespace f3m_0099d6a0

// @f3 0x009811d0 (community match, verified in this file)
namespace f3m_009811d0 {
struct Item;
struct __declspec(align(16)) V4 { float x; float y; float z; float w; };
struct Cam {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68;
    V4* unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80;
    int unk84;
    int unk88;
    char unk8c;
    float FUN_009022d0();
    float FUN_009022e0();
    void FUN_00902550();
};
struct Owner {
    int unk00;
    void FUN_00981160(Item** a, int n, V4* d, int z);
    void hkpSimulation_reintegrateAndRecollideEntities(Item** items, int n, Cam* cam, unsigned flags);
};
void hkSweptTransformUtil_backStepMotionState(float f, float* p);
void hkRigidMotionUtilStep(V4* o, Item** items, int n, int sz);
void FUN_0099a2d0(V4* d, Item** items, int n);
void FUN_009808f0(Item** items, int n, Cam* c);
void FUN_009445b0(Item* items, V4* d);

// pdb: hkpSimulation::reintegrateAndRecollideEntities | hkpSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void Owner::hkpSimulation_reintegrateAndRecollideEntities(Item** items, int n, Cam* cam, unsigned flags)
{
    cam->unk84++;
    float a = cam->FUN_009022d0();
    float b = cam->FUN_009022e0();
    V4 v;
    v.x = a;
    v.y = b;
    v.z = b - a;
    v.w = (v.z == 0.0f) ? 0.0f : 1.0f / v.z;
    V4* dst = cam->unk6c + 5;
    int i;
    *dst = v;
    if (flags & 1) {
        for (i = 0; i < n; i++)
        {   float* p = (float*)((char*)items[i] + 0xe0);
            hkSweptTransformUtil_backStepMotionState(cam->FUN_009022d0(), p); }
        hkRigidMotionUtilStep(&v, items, n, 0xd0);
        FUN_0099a2d0(cam->unk6c, items, n);
    }
    if (flags & 2)
        FUN_009808f0(items, n, cam);
    for (i = 0; i < n; i++)
        FUN_009445b0(items[i], cam->unk6c);
    if (flags & 4)
        this->FUN_00981160(items, n, cam->unk6c, 0);
    if (--cam->unk84 == 0 && cam->unk8c == 0 && cam->unk80 != 0)
        cam->FUN_00902550();
}
}   // namespace f3m_009811d0

// @f3 0x0098aef0 (community match, verified in this file)
extern const char DAT_00e7da2c[];
extern const char DAT_00e35dd0[];
extern const char DAT_00e7bf1c[];
extern const char DAT_00e7da20[];
extern const char DAT_00e7da14[];
extern const char DAT_00e7da08[];
extern const char DAT_00e7da00[];
extern const char DAT_00e7d9f8[];
extern const char DAT_00e7d9ec[];
extern const char DAT_00e3277c[];
extern const char DAT_00e7d9e0[];
namespace f3m_0098aef0 {
struct Writer98a {
    virtual void v00();
    virtual void NiStream_SaveHeader(const char* name, int kind, void* obj);
    virtual void writeArray64(const char* name, int kind, const void* data, unsigned int size, unsigned int capacity);
    virtual void WritePointer(const char* name, int kind, void* ptr);
    virtual void BeginObject(const char* name);
    virtual void EndObject();
    virtual void Finish();
};

struct RefObj98a { int unk00; unsigned short flags; unsigned short unk06; int unk08; RefObj98a* link; };
struct Elem98a {
    RefObj98a* first;
    int unk04, unk08;
    RefObj98a* second;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};

struct Item98a {
    int unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    Elem98a* elems;
    unsigned short elemCount;
    unsigned short elemCapacity;
    int* words;
    int wordCount;
    int wordCapacity;
    char* bytes;
    int byteCount;
    int byteCapacity;
};

struct Owner98a { int unk00; int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68; void* unk6c; };

struct Sub98a { int unk00; };
void __cdecl FUN_00a26e70(Sub98a*, Writer98a*);
void __cdecl hkpAgentMachineUtil_calcNnStatistics(Sub98a*, void*, Writer98a*);


struct Group98a {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Owner98a* owner;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    void** refs;
    int refCount;
    int refCapacity;
    int unk44;
    Item98a** items;
    int itemCount;
    int itemCapacity;
    int unk54;
    Sub98a sub;

    void hkpSimulationIsland_calcContentStatistics(Writer98a* writer);
};

// pdb: hkpSimulationIsland::calcContentStatistics | hkpSimulationIsland.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void Group98a::hkpSimulationIsland_calcContentStatistics(Writer98a* writer)
{
    writer->NiStream_SaveHeader(0, 8, this);
    if ((itemCapacity & 0x80000000u) == 0)
        writer->writeArray64(DAT_00e7da2c, 8, items, itemCount * 4, (itemCapacity & 0x3fffffff) * 4);
    for (int i = 0; i < itemCount; i++) {
        Item98a* item = items[i];
        writer->WritePointer(DAT_00e35dd0, 2, item);
        writer->BeginObject(DAT_00e7bf1c);
        if ((item->elemCapacity & 0x8000) == 0)
            writer->writeArray64(DAT_00e7da20, 8, item->elems, item->elemCount * 48, (item->elemCapacity & 0x3fff) * 48);
        if ((item->wordCapacity & 0x80000000u) == 0)
            writer->writeArray64(DAT_00e7da14, 8, item->words, item->wordCount * 4, (item->wordCapacity & 0x3fffffff) * 4);
        for (int j = 0; j < item->elemCount; j++) {
            if (item->elems[j].first->flags & 0x7fff)
                writer->WritePointer(DAT_00e7da08, 2, item->elems[j].first);
            if (item->elems[j].first->link->flags & 0x7fff)
                writer->WritePointer(DAT_00e7da00, 1, item->elems[j].first->link);
        }
        if ((item->byteCapacity & 0x80000000u) == 0)
            writer->writeArray64(DAT_00e7d9f8, 4, item->bytes, item->byteCount, item->byteCapacity & 0x3fffffff);
        writer->EndObject();
    }
    if ((refCapacity & 0x80000000u) == 0)
        writer->writeArray64(DAT_00e7d9ec, 8, refs, refCount * 4, (refCapacity & 0x3fffffff) * 4);
    for (int k = 0; k < refCount; k++)
        writer->WritePointer(DAT_00e3277c, 2, refs[k]);
    FUN_00a26e70(&sub, writer);
    writer->BeginObject(DAT_00e7d9e0);
    hkpAgentMachineUtil_calcNnStatistics(&sub, owner->unk6c, writer);
    writer->EndObject();
    writer->Finish();
}
}   // namespace f3m_0098aef0

// @f3 0x0099d3c0 (community match, verified in this file)
namespace f3m_0099d3c0 {
struct M99d3c0 { float m[12]; };
void __stdcall FUN_0099d3c0(M99d3c0* p)
{
    __declspec(align(16)) float z = 0.0f;
    p->m[0] = z; p->m[1] = z; p->m[2] = z; p->m[3] = z;
    p->m[4] = z; p->m[5] = z; p->m[6] = z; p->m[7] = z;
    p->m[8] = z; p->m[9] = z; p->m[10] = z; p->m[11] = z;
}
}   // namespace f3m_0099d3c0

// @f3 0x0099daa0 (community match, verified in this file)
namespace f3m_0099daa0 {
// The engine keeps 3x4 float matrices in Havok layout: three rows of four floats, so the
// diagonal elements sit at 0, 5 and 10. These cells are written straight into the live scene
// data, so every element store has to happen.
class ThreeByThreeMatrix
{
public:
    volatile float m[12];
};

// A 16-byte aligned float quad, the shape the engine uses for its vector temporaries; this
// build only fills the three diagonal components.
class __declspec(align(16)) DiagonalQuad
{
public:
    float unused0;
    float x, y, z;
};

// Stand-in for the object that caches a diagonal triple just past its fixed state block.
class DiagonalMatrixOwner
{
public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8, unkBC;
    float diagX, diagY, diagZ;

    void FUN_0099daa0(ThreeByThreeMatrix* out);
};

// pdb: hkpBoxMotion::getInertiaInvLocal | hkpBoxMotion.obj | tesv_win, objrun, medium
void DiagonalMatrixOwner::FUN_0099daa0(ThreeByThreeMatrix* out)
{
    DiagonalQuad saved;

    saved.x = diagX;
    saved.y = diagY;
    saved.z = diagZ;

    out->m[0] = 0.0f;
    out->m[1] = 0.0f;
    out->m[2] = 0.0f;
    out->m[3] = 0.0f;
    out->m[4] = 0.0f;
    out->m[5] = 0.0f;
    out->m[6] = 0.0f;
    out->m[7] = 0.0f;
    out->m[8] = 0.0f;
    out->m[9] = 0.0f;
    out->m[10] = 0.0f;
    out->m[11] = 0.0f;

    out->m[0] = saved.x;
    out->m[5] = saved.y;
    out->m[10] = saved.z;
}
}   // namespace f3m_0099daa0

// @f3 0x0099fea0 (community match, verified in this file)
extern int DAT_01060f20[];
extern float DAT_01060ef4[];
namespace f3m_0099fea0 {
namespace f3m_0099fea0 {


struct S0099fea0_V4 {
    float x, y, z, w;
};

struct S0099fea0_Obj {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    S0099fea0_V4 rows[4];
    void FUN_0099fea0(unsigned short* src, int count, S0099fea0_V4* dst);
};

void S0099fea0_Obj::FUN_0099fea0(unsigned short* src, int count, S0099fea0_V4* dst)
{
    for (int i = count - 1; i >= 0; --i) {
        S0099fea0_V4* m = &rows[DAT_01060f20[*src]];
        dst->x = m->x;
        dst->y = m->y;
        dst->z = m->z;
        dst->w = m->w;
        float s = DAT_01060ef4[*src];
        dst->x = dst->x + rows[3].x * s;
        dst->y = dst->y + rows[3].y * s;
        dst->z = dst->z + rows[3].z * s;
        dst->w = dst->w + rows[3].w * s;
        *(unsigned int*)&dst->w = *src | 0x3f000000;
        ++src;
        ++dst;
    }
}

}
}   // namespace f3m_0099fea0

// @f3 0x009824b0 (community match, verified in this file)
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
extern unsigned long DAT_010f3170;

namespace f3m_009824b0 {

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long index) throw();

struct S9824b0_Heap { void FUN_008f6d90(void* p, unsigned int size, int kind) throw(); };

struct S9824b0_ListLock {
    int cs0, cs4, cs8, csc, cs10, cs14;
    int owner;
    int depth;
    void FUN_00908a00() throw();
    void Leave() {
        owner = -1;
        depth = -1;
        LeaveCriticalSection(this);
    }
};
}
extern f3m_009824b0::S9824b0_ListLock DAT_011692e8;
namespace f3m_009824b0 {

struct S9824b0_TrackedLock {
    int cs0, cs4, cs8, csc, cs10, cs14;
    int unk18, unk1c, unk20;
    S9824b0_TrackedLock* prev;
    S9824b0_TrackedLock* next;
    ~S9824b0_TrackedLock() {
        DeleteCriticalSection(this);
        if (prev) {
            DAT_011692e8.FUN_00908a00();
            prev->next = next;
            if (next) next->prev = prev;
            DAT_011692e8.Leave();
        }
    }
};

struct S9824b0_Pair { int a, b; };

struct S9824b0_Array {
    S9824b0_Pair* data;
    int size;
    unsigned int capacity;
    ~S9824b0_Array() {
        if (!(capacity & 0x80000000)) {
            unsigned int n = capacity & 0x3fffffff;
            S9824b0_Heap* heap = (S9824b0_Heap*)FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, n * sizeof(S9824b0_Pair), 0x17);
        }
    }
};

struct S9824b0_Ref {
    int unk04;
    virtual ~S9824b0_Ref() throw() {}
};

struct S9824b0_Map {
    int unk00, unk04, unk08, unk0c;
    ~S9824b0_Map() throw();
};

struct S9824b0_Set {
    int unk00, unk04, unk08, unk0c;
    ~S9824b0_Set() throw();
};

struct S9824b0_Base {
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c;
    virtual ~S9824b0_Base() throw();
};

}
using namespace f3m_009824b0;
struct FUN_009824b0 : S9824b0_Base {
    S9824b0_Ref ref50;
    S9824b0_Ref ref58;
    S9824b0_Ref ref60;
    int unk68;
    S9824b0_Array array6c;
    S9824b0_TrackedLock lock78;
    int unka4;
    S9824b0_Array arraya8;
    int unkb4;
    S9824b0_TrackedLock lockb8;
    int unke4; int unke8; int unkec;
    S9824b0_Map mapf0;
    S9824b0_TrackedLock lock100;
    int unk12c; int unk130; int unk134; int unk138; int unk13c;
    S9824b0_Set set140;
    int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    S9824b0_Map map200;
    int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c;
    S9824b0_Map map280;
    int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc;
    S9824b0_Map map300;
    int unk310; int unk314; int unk318; int unk31c; int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c;
    S9824b0_TrackedLock lock340;
    int unk36c; int unk370; int unk374; int unk378; int unk37c;
    S9824b0_TrackedLock lock380;
    virtual ~FUN_009824b0() throw();
};

// pdb: hkpMultiThreadedSimulation::~hkpMultiThreadedSimulation | hkpMultithreadedSimulation.obj | fnv360_0822_retail, call_seq, medium
FUN_009824b0::~FUN_009824b0() throw()
{
}

// @f3 0x0098a280 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0098a280 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);

namespace f3m_0098a280 {

struct S0098a280_Mem {
    void* FUN_008f6d30(int bytes, int memClass);
    void FUN_008f6d90(void* p, int bytes, int memClass);
};

struct S0098a280_Array {
    int* m_data;
    int m_size;
    int m_capacityAndFlags;

    static __forceinline void copy(int* dst, const int* src, int n)
    {
        for (int i = 0; i < n; ++i)
            dst[i] = src[i];
    }

    __forceinline S0098a280_Array& operator=(const S0098a280_Array& a)
    {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < a.m_size) {
            if ((m_capacityAndFlags & 0x80000000) == 0) {
                S0098a280_Mem* mem = static_cast<S0098a280_Mem*>(FUN_00d9b080(DAT_010f3170));
                mem->FUN_008f6d90(m_data, cap * 4, 0x17);
            }
            S0098a280_Mem* mem = static_cast<S0098a280_Mem*>(FUN_00d9b080(DAT_010f3170));
            m_data = static_cast<int*>(mem->FUN_008f6d30(a.m_size * 4, 0x17));
            m_capacityAndFlags = (m_capacityAndFlags & 0x40000000) | a.m_size;
        }
        m_size = a.m_size;
        copy(m_data, a.m_data, m_size);
        return *this;
    }
};

struct S0098a280_Obj {
    void* vtbl;
    int unk04;
    S0098a280_Array unk08;
    S0098a280_Array unk14;
    S0098a280_Array unk20;
    S0098a280_Array unk2c;
    int unk38;
    int unk3c;
    unsigned char unk40;

    void FUN_0098a280(const S0098a280_Obj& o);
};

void S0098a280_Obj::FUN_0098a280(const S0098a280_Obj& o)
{
    unk08 = o.unk08;
    unk2c = o.unk2c;
    unk14 = o.unk14;
    unk20 = o.unk20;
    unk38 = o.unk38;
    unk3c = o.unk3c;
    unk40 = o.unk40;
}

}
}   // namespace f3m_0098a280

// @f3 0x0098d5c0 (community match, verified in this file)
extern double DAT_00db38b0;
namespace f3m_0098d5c0 {
struct S98d5c0_Context
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44;
    char** entries48;
    int count4C;
};
struct __declspec(align(16)) S98d5c0_Vec4
{
    float x, y, z, w;
};
struct S98d5c0_Block
{
    S98d5c0_Vec4 col0;
    S98d5c0_Vec4 col1;
    S98d5c0_Vec4 col2;
    S98d5c0_Vec4 out30;
    S98d5c0_Vec4 unk40;
    S98d5c0_Vec4 base50;
    S98d5c0_Vec4 unk60;
    S98d5c0_Vec4 sample70;
    S98d5c0_Vec4 value80;
    void hkRotation_set(S98d5c0_Vec4* sample);
};
struct S98d5c0_Aux
{
    S98d5c0_Vec4 unk00;
    S98d5c0_Vec4 pos10;
    S98d5c0_Vec4 vec20;
    S98d5c0_Vec4 unk30;
    S98d5c0_Vec4 unk40;
    S98d5c0_Vec4 row50;
    S98d5c0_Vec4 row60;
    S98d5c0_Vec4 row70;
};

// pdb: hkLs_restoreTransformOnBodiesWithUpdatedTransform | hkpContinuousSimulation.obj | tesv_win, call_gap, low
void __cdecl FUN_0098d5c0(S98d5c0_Context* context, const unsigned char** kindMap, int offset)
{
    for (int i = 0; i < context->count4C; i++)
    {
        int kind = (*kindMap)[i];
        if (kind == 1 || kind == 2)
        {
            S98d5c0_Block* block = (S98d5c0_Block*)(context->entries48[i] + 0xe0);
            block->hkRotation_set(&block->sample70);
            float x = block->value80.x;
            float y = block->value80.y;
            float z = block->value80.z;
            S98d5c0_Vec4 r;
            r.x = block->col0.x * x + block->col1.x * y + block->col2.x * z;
            r.y = block->col0.y * x + block->col1.y * y + block->col2.y * z;
            r.z = block->col0.z * x + block->col1.z * y + block->col2.z * z;
            block->out30.x = block->base50.x - r.x;
            block->out30.y = block->base50.y - r.y;
            block->out30.z = block->base50.z - r.z;
            block->out30.w = (float)(block->base50.w - DAT_00db38b0);
        }
        if (kind == 8 || kind == 2)
        {
            char* entry = context->entries48[i];
            S98d5c0_Aux* aux = (S98d5c0_Aux*)(*(char**)(entry + 0x90) + offset);
            S98d5c0_Vec4* out = (S98d5c0_Vec4*)(entry + 0x1a0);
            out[0].x = aux->pos10.x;
            out[0].y = aux->pos10.y;
            out[0].z = aux->pos10.z;
            out[0].w = aux->pos10.w;
            float x = aux->vec20.x;
            float y = aux->vec20.y;
            float z = aux->vec20.z;
            out[1].x = aux->row50.x * x + aux->row50.y * y + aux->row50.z * z;
            out[1].y = aux->row60.x * x + aux->row60.y * y + aux->row60.z * z;
            out[1].z = aux->row70.x * x + aux->row70.y * y + aux->row70.z * z;
            out[1].w = 0.0f;
        }
    }
}
}   // namespace f3m_0098d5c0

// @f3 0x00992dc0 (community match, verified in this file)
namespace f3m_00992dc0 {
namespace f3m_00992dc0 {

struct __declspec(align(16)) Vec4 {
    float v[4];
};

struct IntArray {
    int* data;
    int size;
    int capacityAndFlags;
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void pushBack(const int& x);
};
void __cdecl FUN_00901f10(IntArray* a, int elemSize);
inline void IntArray::pushBack(const int& x)
{
    if (size == getCapacity())
        FUN_00901f10(this, 4);
    data[size] = x;
    size++;
}

struct Pair { unsigned short value; unsigned short index; };
struct Block { Pair* data; int count; int pad; };
struct Entry16 { int a, b, c, id; };

struct Quant {
    int unk00[24];
    float scale[3];
    int unk6c[13];
    Entry16* entries;
    int unka4, unka8;
    Block blocks[3];
    void FUN_00992dc0(const Vec4* in, Vec4* out, IntArray* list);
};

void Quant::FUN_00992dc0(const Vec4* in, Vec4* out, IntArray* list)
{
    Vec4 v = *in;
    int k[3];
    for (int i = 0; i < 3; i++) {
        k[i] = fnv_FloatToInt(scale[i] * v.v[i]) & ~1;
        v.v[i] = (float)k[i] / scale[i];
    }
    out->v[0] = v.v[0];
    out->v[1] = v.v[1];
    out->v[2] = v.v[2];
    out->v[3] = v.v[3];
    for (int j = 0; j < 3; j++) {
        int delta = k[j];
        Block& b = blocks[j];
        for (int m = 1; m < b.count - 1; m++) {
            Pair* p = &b.data[m];
            unsigned int val = p->value;
            if (val - 2 > 0xfff9)
                continue;
            int nv = delta + val;
            if (nv < 0) {
                nv = val & 1;
                list->pushBack(entries[p->index].id);
            } else if (nv >= 0xfffc) {
                nv = (val & 1) | 0xfffc;
                list->pushBack(entries[p->index].id);
            }
            p->value = (unsigned short)nv;
        }
    }

}

}
}   // namespace f3m_00992dc0

// @f3 0x0099fd60 (community match, verified in this file)
namespace f3m_0099fd60 {
struct __declspec(align(16)) Vec4_9fd60
{
    float x, y, z, w;
};

struct Motion_9fd60
{
    float unk00, unk04, unk08, unk0c;
    Vec4_9fd60 m_cols[4];
    float unk50, unk54, unk58, unk5c;

    void FUN_0099fd60(const Vec4_9fd60& v, Vec4_9fd60& out);
};

inline float Dot9a(const Vec4_9fd60& a, const Vec4_9fd60& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline void AddTo9a(Vec4_9fd60& o, const Vec4_9fd60& r) { o.x += r.x; o.y += r.y; o.z += r.z; o.w += r.w; }
inline void AddTo9b(Vec4_9fd60& o, const Vec4_9fd60& r) { o.x = r.x + o.x; o.y = r.y + o.y; o.z = r.z + o.z; o.w = r.w + o.w; }
void Motion_9fd60::FUN_0099fd60(const Vec4_9fd60& v, Vec4_9fd60& out)
{
    float vx = v.x;
    float vy = v.y;
    float vz = v.z;
    Vec4_9fd60 d;
    d.x = m_cols[1].x * vx + m_cols[1].y * vy + m_cols[1].z * vz;
    d.y = m_cols[2].x * vx + m_cols[2].y * vy + m_cols[2].z * vz;
    d.z = m_cols[3].x * vx + m_cols[3].y * vy + m_cols[3].z * vz;
    int axis;
    float m;
    if (d.z > d.y)
    {
        axis = 2;
        m = d.z;
    }
    else
    {
        axis = 1;
        m = d.y;
    }
    if (d.x > m)
        axis = 0;
    const Vec4_9fd60& col = ((Vec4_9fd60*)this)[axis + 2];
    out.x = col.x; out.y = col.y; out.z = col.z; out.w = col.w;
    float t = Dot9a(v, (*(const Vec4_9fd60*)&unk50));
    if (t > 0.0f)
    {
        out.x += unk50;
        out.y += unk54;
        out.z += unk58;
        out.w += unk5c;
        axis += 3;
    }
    int bits = axis | 0x3f000000;
    *(int*)&out.w = bits;
}
}   // namespace f3m_0099fd60

// @f3 0x0099f850 (community match, verified in this file)
namespace f3m_0099f850 {
// Matches only under /MT,/O2,/GS,/EHsc,/Gy (pack lists /Od).
// Needed for the match (measured): helpers are __forceinline (plain inline leaves them as calls);
// setMin4/setMax4 assign through a float temporary; the offset sums reuse `first` instead of a new local.
struct Transform;
struct __declspec(align(16)) Vec4 {
 float x,y,z,w;
 __forceinline void setAll(float r){x=r;y=r;z=r;w=r;}
 __forceinline void setAdd4(const Vec4& a,const Vec4& b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
 __forceinline void setMin4(const Vec4& a,const Vec4& b){float t;t=a.x<b.x?a.x:b.x;x=t;t=a.y<b.y?a.y:b.y;y=t;t=a.z<b.z?a.z:b.z;z=t;t=a.w<b.w?a.w:b.w;w=t;}
 __forceinline void setMax4(const Vec4& a,const Vec4& b){float t;t=a.x>b.x?a.x:b.x;x=t;t=a.y>b.y?a.y:b.y;y=t;t=a.z>b.z?a.z:b.z;z=t;t=a.w>b.w?a.w:b.w;w=t;}
 __forceinline void add4(const Vec4& a){x+=a.x;y+=a.y;z+=a.z;w+=a.w;}
 __forceinline void sub4(const Vec4& a){x-=a.x;y-=a.y;z-=a.z;w-=a.w;}
 void hkVector4_setTransformedPos(const Transform*,const Vec4*);
};
struct Bounds {Vec4 minimum,maximum;};
struct Shape {
 unsigned int unk00,unk04,unk08,unk0c;
 float radius; unsigned int unk14,unk18,unk1c;
 Vec4 a,b,c,offset;
 void FUN_0099f850(const Transform*,float,Bounds*);
};
void Shape::FUN_0099f850(const Transform* transform,float tolerance,Bounds* out) {
 Vec4 tol4; tol4.setAll(radius+tolerance);
 Vec4 first,second,third;
 first.hkVector4_setTransformedPos(transform,&a);
 second.hkVector4_setTransformedPos(transform,&b);
 third.hkVector4_setTransformedPos(transform,&c);
 out->minimum.setMin4(first,second);
 out->maximum.setMax4(first,second);
 out->minimum.setMin4(out->minimum,third);
 out->maximum.setMax4(out->maximum,third);
 first.setAdd4(out->minimum,offset);
 out->minimum.setMin4(out->minimum,first);
 first.setAdd4(out->maximum,offset);
 out->maximum.setMax4(out->maximum,first);
 out->minimum.sub4(tol4);
 out->maximum.add4(tol4);
}
}   // namespace f3m_0099f850

// @f3 0x00984aa0 (community match, verified in this file)
namespace f3m_00984aa0 {
typedef unsigned long (__stdcall *ThreadEntry984)(void*);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*,unsigned long,ThreadEntry984,void*,unsigned long,unsigned long*);
namespace Thread984aa0 {
struct Thread {void* handle;int unk04;unsigned long id;int FUN_00984aa0(ThreadEntry984,void*);};
int Thread::FUN_00984aa0(ThreadEntry984 entry,void* argument) {
 handle=CreateThread(0,0,entry,argument,0,&id);
 return handle==0;
}
}
}   // namespace f3m_00984aa0

// @f3 0x00987b00 (community match, verified in this file)
namespace f3m_00987b00 {
struct hkQuadReal { float x, y, z, w; };
class hkVector4 {
public:
    hkQuadReal m_quad;
    inline void operator=(const hkVector4& v)
    {
        m_quad.x = v.m_quad.x;
        m_quad.y = v.m_quad.y;
        m_quad.z = v.m_quad.z;
        m_quad.w = v.m_quad.w;
    }
};
class hkContactPoint {
public:
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};
struct hkpSimpleContactConstraintAtom {
    unsigned short m_type;
    unsigned short m_unk02;
    unsigned short m_numContactPoints;
    unsigned short m_numReservedContactPoints;
    signed char m_numUserDatasForBodyA;
    signed char m_numUserDatasForBodyB;
    unsigned char m_contactPointPropertiesStriding;
    unsigned char m_pad0b;
    unsigned short m_maxNumContactPoints;
    unsigned short m_pad0e;
    char m_info[0x20];
    hkContactPoint* getContactPoints() { return reinterpret_cast<hkContactPoint*>(this + 1); }
    int getContactPointPropertiesStriding() { return m_contactPointPropertiesStriding; }
    char* getContactPointPropertiesStream() { return reinterpret_cast<char*>(getContactPoints() + m_numReservedContactPoints); }
};
static inline void memCpy4(void* dst, const void* src, int numWords)
{
    const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
    unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
    for (int i = 0; i < numWords; i++)
    {
        *(dst32++) = *(src32++);
    }
}
// pdb: hkpSimpleContactConstraintAtomUtil::removeAtAndCopy | hkpSimpleConstraintContactMgr.obj | tesv_win, call_seq, medium
void FUN_00987b00(hkpSimpleContactConstraintAtom* atom, int index)
{
    int numContactPoints = atom->m_numContactPoints - 1;
    atom->m_numContactPoints = (unsigned short)numContactPoints;
    hkContactPoint* cp = &atom->getContactPoints()[index];
    int stride = atom->getContactPointPropertiesStriding();
    char* cpp = atom->getContactPointPropertiesStream() + short(index) * short(stride);
    for (int i = index; i < numContactPoints; i++)
    {
        cp[0] = cp[1];
        char* next = cpp + stride;
        memCpy4(cpp, next, stride >> 2);
        cp++;
        cpp = next;
    }
}
}   // namespace f3m_00987b00

// @f3 0x00985ef0 (community match, verified in this file)
namespace f3m_00985ef0 {
namespace f3m_00985ef0 {

struct Serializer {
    virtual void v00();
    virtual void NiStream_SaveHeader(const char* name, int a, void* obj);
    virtual void writeArray64(const char* name, int a, const void* data, int size, int capSize);
    virtual void WritePointer(const char* name, int a, void* ptr);
    virtual void v10();
    virtual void v14();
    virtual void Finish();
    void FUN_008f69e0(const char* name, int a, void* ptr);
};

struct B16 { int a, b, c, d; };
struct B64 { B16 a, b, c, d; };
struct B256 { B64 a, b, c, d; };
struct B1024 { B256 a, b, c, d; };

struct Dispatcher {
    int unk00, unk04, unk08;
    void* contactMgrFactory[8][8];
    B1024 s0, s1, s2, s3, s4, s5, s6;
    B256 s7;
    B16 s8;
    int s9, s10;
    void* shapeInheritanceData;
    int shapeInheritanceCount;
    int shapeInheritanceCapacity;
    void* debugTable0;
    void* debugTable1;
    void* debugTable2;
    void* debugTable3;

    void hkpCollisionDispatcher_calcContentStatistics(Serializer* writer);
};

// pdb: hkpCollisionDispatcher::calcContentStatistics | hkpCollisionDispatcher.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void Dispatcher::hkpCollisionDispatcher_calcContentStatistics(Serializer* writer)
{
    writer->NiStream_SaveHeader(0, 2, this);
    if (debugTable0) {
        writer->FUN_008f69e0("DebugTable", 4, debugTable0);
        writer->FUN_008f69e0("DebugTable", 4, debugTable1);
        writer->FUN_008f69e0("DebugTable", 4, debugTable2);
        writer->FUN_008f69e0("DebugTable", 4, debugTable3);
    }
    if ((shapeInheritanceCapacity & 0x80000000u) == 0) {
        writer->writeArray64("shapeInheritanceArray", 4, shapeInheritanceData, shapeInheritanceCount * 8, (shapeInheritanceCapacity & 0x3fffffff) * 8);
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            writer->WritePointer("contactMgrFactory", 4, contactMgrFactory[i][j]);
        }
    }
    writer->Finish();
}

}
}   // namespace f3m_00985ef0

// @f3 0x0098c9b0 (community match, verified in this file)
namespace f3m_0098c9b0 {
namespace ns_0098c9b0 {

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
  unsigned char typeD8;
};

struct Listener {
  virtual void v00() throw();
  virtual void v04() throw();
  virtual void v08() throw();
  virtual void v0C() throw();
  virtual void v10() throw();
  virtual void v14() throw();
  virtual void v18() throw();
  virtual void v1C() throw();
  virtual void v20(int a, void* b) throw();
};

struct Entry {
  int unk00;
  Node* first04;
  Node* second08;
  int unk0C;
  Listener* listener10;
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
  int prop40;
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

  void FUN_00990390(const Entry& other) throw();
};

struct Table {
  int unk00;
  int unk04;
  int unk08;

  void FUN_00922c50(int n) throw();
  void FUN_00922cf0() throw();
  void FUN_00922710(int key, int val) throw();
  int FUN_00922790(Node* key) throw();

  Table(int n) throw() {
    FUN_00922c50(n);
  }
  ~Table() throw() {
    FUN_00922cf0();
  }
};

struct Self {
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
  Entry* m_30;
  int m_34;

  void hkpContinuousSimulation_removeToiEventsOfEntities(int* ids, int n) throw();
};

// pdb: hkpContinuousSimulation::removeToiEventsOfEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void Self::hkpContinuousSimulation_removeToiEventsOfEntities(int* ids, int n) throw() {
  if (m_34 != 0) {
    Table t(n);
    for (int i = 0; i < n; ++i) {
      t.FUN_00922710(ids[i], 0);
    }
    for (int k = 0; k < m_34; ++k) {
      Entry& e = m_30[k];
      int lo = t.FUN_00922790(e.first04);
      int hi = t.FUN_00922790(e.second08);
      if (lo > t.unk08 && hi > t.unk08) {
        continue;
      }
      int v;
      if (e.first04->typeD8 != 7) {
        v = e.first04->unkB8;
      } else {
        v = e.second08->unkB8;
      }
      e.listener10->v20(v, &e.prop40);
      m_34--;
      m_30[k].FUN_00990390(m_30[m_34]);
      k--;
    }
  }
}

} // namespace ns_0098c9b0
}   // namespace f3m_0098c9b0

// @f3 0x0098d9e0 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d2d8[];
extern const char DAT_00e32798[];
namespace f3m_0098d9e0 {
namespace f3m_0098d9e0 {
extern "C" void _ReadWriteBarrier(void);

struct Rec98d9e0 {
    const void* label;
    unsigned int ticks;
    unsigned int unk08;
};
struct Buf98d9e0 {
    int unk00;
    Rec98d9e0* cur;
    int unk08;
    Rec98d9e0* end;
};
extern Buf98d9e0* (__stdcall* const DAT_00d9b080)(unsigned long);

struct World98d9e0 {
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
    int postSimCallbacks;
};
void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(World98d9e0* world);

struct Sim98d9e0 {
    int unk00, unk04, unk08;
    World98d9e0* world;
    int unk10;
    float unk14;
    int unk18, unk1c;
    float unk20;
    void* FUN_0098c5b0();
    void* FUN_0098d9e0();
};

// pdb: hkpContinuousSimulation::advanceTime | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, medium
void* Sim98d9e0::FUN_0098d9e0()
{
    void* result = FUN_0098c5b0();
    if (unk14 >= unk20 && world->postSimCallbacks) {
        Buf98d9e0* (__stdcall* getter)(unsigned long) = DAT_00d9b080;
        Buf98d9e0* b = getter(DAT_0116913c);
        Rec98d9e0* r = b->cur;
        if (r < b->end) {
            r->label = DAT_00e7d2d8;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            r->ticks = t;
            b->cur = r + 1;
        }
        hkpWorldCallbackUtil_firePostSimulationCallback(world);
        b = getter(DAT_0116913c);
        r = b->cur;
        if (r < b->end) {
            r->label = DAT_00e32798;
            _ReadWriteBarrier();
            volatile unsigned int t2 = (unsigned int)__rdtsc();
            r->ticks = t2;
            b->cur = r + 1;
        }
    }
    return result;
}
}
}   // namespace f3m_0098d9e0

// @f3 0x00986db0 (community match, verified in this file)
namespace f3m_00986db0 {
namespace c3_00986db0 {

struct Manager
{
    int unk00, unk04;
    void* context;
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
    unsigned char motionType,unkd9;unsigned short unkda;
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
    unsigned short callbacks;
};

struct Source
{
    int unk00;
    Manager* first;
    Manager* second;
    float value;
    int unk10, unk14, unk18, unk1c;
    int contact20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, properties40;
};

struct Info
{
    void* first;
    void* second;
    int unused08;
    void* contact;
    void* properties;
    float parameter, value;
    int state0;
    void* state1;
};

void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(void* context, Info* info);
void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(Manager* manager, Info* info);
void __cdecl FUN_0098cb20(void* context, Source* source, float value, void* extra);

__forceinline bool HasCallbacks(Manager* manager)
{
    return manager->callbacks != 0;
}

__forceinline unsigned char MotionType(Manager* manager)
{
    return manager->motionType;
}

struct Listener
{
    int unk00, unk04, unk08, unk0c, unk10;
    int list14;

    void FUN_00986db0(Source* source, float value, void* extra);
};

// pdb: hkpSimpleConstraintContactMgr::fireCallbacksForEarliestToi | hkpSimpleConstraintContactMgr.obj | tesv_win, caller_sim, low
void Listener::FUN_00986db0(Source* source, float value, void* extra)
{
    Info info;
    info.parameter = value;
    Manager* first = source->first;
    info.value = source->value;
    void* context = first->context;
    info.first = reinterpret_cast<char*>(first) + 0x10;
    info.second = reinterpret_cast<char*>(source->second) + 0x10;
    info.contact = &source->contact20;
    info.properties = &source->properties40;
    info.state0 = 0;
    info.state1 = &list14;
    hkpWorldCallbackUtil_fireContactPointCallback(context, &info);
    if (HasCallbacks(source->first))
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(source->first, &info);
    if (HasCallbacks(source->second))
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(source->second, &info);
    Manager* firstBody=source->first;
    Manager* secondBody=source->second;
    if ((firstBody->motionType != 7 && firstBody->motionType != 6) ||
        (secondBody->motionType != 7 && secondBody->motionType != 6))    FUN_0098cb20(context, source, info.parameter, extra);
}

}



}   // namespace f3m_00986db0

// @f3 0x00997010 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* const DAT_00e7dd3c[];
namespace f3m_00997010 {
namespace f3m_00997010 {
struct Heap {
    void FUN_008f6f90(void* item) throw();
    void FUN_008f6d90(void* memory, unsigned int bytes, int tag) throw();
};
extern __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned int index);

template <class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    void Free() throw()
    {
        if (((unsigned int)capacityAndFlags & 0x80000000u) == 0) {
            unsigned int capacity = (unsigned int)capacityAndFlags & 0x3fffffff;
            Heap* heap = FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
struct Vec4 { float x, y, z, w; };
struct Row { int unk00; hkArray<short> values; };

template <class T> __forceinline void FreeArrays(hkArray<T>* first, int count) { hkArray<T>* list = first + count; while (--count >= 0) { --list; list->Free(); } }
struct Base {
    void* const* vptr;
 int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    ~Base() throw();
};
struct Owner : Base {
    hkArray<Vec4> vectors;
    hkArray<int> lists[3];
    int rowCount;
    int unkd4;
    Row* rows;
    ~Owner() throw();
};
// pdb: hkp3AxisSweep::~hkp3AxisSweep | hkp3AxisSweep.obj | fnv360_0822_retail, call_seq, high
Owner::~Owner() throw()
{
    vptr = DAT_00e7dd3c;
    for (int i = 0; i < rowCount; i++)
        rows[i].values.Free();
    Row* block = rows;
    Heap* heap = FUN_00d9b080(DAT_010f3170);
    heap->FUN_008f6f90(block);
    FreeArrays(lists, 3);
    vectors.Free();
}
}
}   // namespace f3m_00997010

// @f3 0x00991820 (community match, verified in this file)
namespace f3m_00991820 {
namespace Bounds991820 {
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    __forceinline void Set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
    __forceinline void Set(const Vec4& other) {x=other.x;y=other.y;z=other.z;w=other.w;}
    __forceinline void Sub4(const Vec4& other) {x-=other.x;y-=other.y;z-=other.z;w-=other.w;}
};
struct Aabb {Vec4 lo,hi;};
struct Endpoint {unsigned short value,node;};
struct Axis {Endpoint* data;int size;unsigned int capacityAndFlags;};
struct Node {unsigned short minY,minZ,maxY,maxZ,minX,maxX;};
struct Sweep {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    Vec4 offset;
    Vec4 unk50;
    Vec4 scale;
    unsigned int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    Axis axes[3];
    void FUN_00991820(const Node& node,Aabb& out);
};
// pdb: hkp3AxisSweep::getAabbFromNode | hkp3AxisSweep.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: node, aabb
void Sweep::FUN_00991820(const Node& node,Aabb& out) {
    float i0=1.0f/scale.x;
    float i1=1.0f/scale.y;
    float i2=1.0f/scale.z;
    int a=axes[0].data[node.minX].value;
    int b=axes[1].data[node.minY].value;
    int c=axes[2].data[node.minZ].value;
    int d=axes[0].data[node.maxX].value;
    int e=axes[1].data[node.maxY].value;
    Aabb result;
    result.lo.Set(a*i0,b*i1,c*i2,0.0f);
    result.lo.Sub4(offset);
    result.hi.x=d*i0; result.hi.y=e*i1;
    const int& f=axes[2].data[node.maxZ].value;
    result.hi.z=i2*f; result.hi.w=0.0f;
    result.hi.Sub4(offset);
    out.lo.Set(result.lo);
    out.hi.Set(result.hi);
}
}



}   // namespace f3m_00991820

// @f3 0x0098ab20 (community match, verified in this file)
#include <math.h>
namespace f3m_0098ab20 {

namespace NativeCollector890 {
struct Vec4
{
    float x, y, z, w;
    void Set(const Vec4& a){x=a.x;y=a.y;z=a.z;w=a.w;}
    void Average(const Vec4& a,const Vec4& b){x=a.x*0.5+b.x*0.5;y=a.y*0.5+b.y*0.5;z=a.z*0.5+b.z*0.5;w=a.w*0.5+b.w*0.5;}
};

struct Transform
{
    float m00, m04, m08, m0c;
    float m10, m14, m18, m1c;
    float m20, m24, m28, m2c;
    Vec4 translation;
};

struct AabbBox
{
    Vec4 low;
    Vec4 high;
};

struct Engine
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void getBounds(Transform* transform, float value, AabbBox* out);
    int unk04, unk08, unk0c;
};

struct Obj
{
    Engine* engine;
    int unk04;
    Transform* transform;
};

struct Vertex
{
    Vec4 value;
    float unk10;
    float unk14;
};

struct MatrixData
{
    int f00; float radius; int f08, f0c, f10;
    int unk14, unk18, unk1c;
    Vec4 a, b, c;
    Vec4 displacement;
    float vertexValue;
    float distance;
    void __thiscall FUN_00921790(const MatrixData* source);
    void SetMotion(const Vec4& diff,float r){displacement.Set(diff);distance=sqrtf(diff.x*diff.x+diff.y*diff.y+diff.z*diff.z);radius=r;}
};

struct Triple
{
    Vec4 average;
    Vec4 midpoint;
    Vec4 half;
    void* auxiliary;
    Triple():auxiliary(0){}
};

struct CollectorState;

struct Callback
{
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void f40(); virtual void f44(); virtual void f48(); virtual void f4c();
    virtual void f50(); virtual void f54(); virtual void f58(); virtual void f5c();
    virtual void f60();
    virtual void process(Triple* triple, CollectorState* state);
};

struct CollectorState
{
    void* unk00;
    Vertex* vertex;
    void* arg4;
    void* arg8;
    void* arg9;
    Obj* object;
    int engineValue;
    int unk1c;
    MatrixData matrix;
    float* scalar;

    void __thiscall FUN_0098ab20(Callback* callback, Obj* obj, Vertex* point,
        void* root, MatrixData* input, float* value, void* unused,
        void* callbackArg1, void* callbackArg2);
};

// pdb: hkpWorldLinearCaster::linearCast | hkpWorldLinearCaster.obj | tesv_win, call_seq, medium
void CollectorState::FUN_0098ab20(Callback* callback, Obj* obj, Vertex* point,
    void* root, MatrixData* input, float* value, void* unused,
    void* callbackArg1, void* callbackArg2)
{
    arg8 = callbackArg1;
    arg9 = callbackArg2;
    arg4 = root;
    vertex = point;
    object = obj;
    engineValue = obj->engine->unk0c;
    matrix.FUN_00921790(input);
    scalar = value;

    float radius;
    Transform* transform = obj->transform;
    __declspec(align(16)) Triple temp;

    __declspec(align(16)) Vec4 diff;
    diff.x = point->value.x - transform->translation.x;
    diff.y = point->value.y - transform->translation.y;
    diff.z = point->value.z - transform->translation.z;
    diff.w = point->value.w - transform->translation.w;
    radius = point->unk14;
    matrix.SetMotion(diff,radius);

    __declspec(align(16)) AabbBox out;
    obj->engine->getBounds(transform, point->unk14, &out);

    temp.average.Average(out.low,out.high);
    temp.auxiliary = unused;
    temp.midpoint.x = temp.average.x + diff.x;
    temp.midpoint.y = temp.average.y + diff.y;
    temp.midpoint.z = temp.average.z + diff.z;
    temp.midpoint.w = temp.average.w + diff.w;
    temp.half.x = out.high.x - out.low.x;
    temp.half.y = out.high.y - out.low.y;
    temp.half.z = out.high.z - out.low.z;
    temp.half.w = out.high.w - out.low.w;
    temp.half.x *= 0.5;
    temp.half.y *= 0.5;
    temp.half.z *= 0.5;
    temp.half.w *= 0.5;
    matrix.vertexValue = point->unk10;
    callback->process(&temp, this);
}

}
}   // namespace f3m_0098ab20

// @f3 0x0098caa0 (community match, verified in this file)
namespace f3m_0098caa0 {
namespace f3m_0098caa0 {
struct Sub { int unk00; };

struct Node {
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
    int id;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    unsigned char type;
};

struct Listener {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void Removed(int id, Sub* sub);
};

struct Entry {
    int unk00;
    Node* a;
    Node* b;
    int unk0c;
    Listener* listener;
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
    Sub sub;
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
    void FUN_00990390(const Entry& other);
};

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
    Entry* entries;
    int count;
    void hkpContinuousSimulation_removeToiEventsOfEntity(void* node);
};

// pdb: hkpContinuousSimulation::removeToiEventsOfEntity | hkpContinuousSimulation.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void Owner::hkpContinuousSimulation_removeToiEventsOfEntity(void* node)
{
    void* const target = node;

    for (int i = 0; i < count; i++) {
        Entry& entry = entries[i];

        if (entries[i].a == target || entries[i].b == target) {
            int id;
            if(entry.a->type != 7) id=entry.a->id;
            else id=entry.b->id;
            entry.listener->Removed(id, &entry.sub);

            count--;
            entries[i].FUN_00990390(entries[count]);
            i--;
        }
    }
}
}

}   // namespace f3m_0098caa0

// @f3 0x009844e0 (community match, verified in this file)
namespace f3m_009844e0 {
extern "C" unsigned __int64 __rdtsc(void);

extern "C" void _ReadWriteBarrier(void);

extern unsigned long DAT_0116913c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const char str_00e7d4cc[];
extern const char str_00e32798[];
namespace c_009844e0 {
struct MonitorStream { int unk00; char* end; int unk08; char* capacityEnd; };
static __forceinline void TimerMark(const char* name)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0116913c);
    char* p = s->end;
    if (p < s->capacityEnd) {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        ((unsigned int*)p)[1] = t;
        s->end = p + 0xc;
    }
}
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct Input { Vec4 pos; int unk10[4]; bool flag; };
struct Linked { int unk00[4]; int unk10; int unk14; };
struct QueryInput { Vec4 pos; int count; const void* data; int stride; void* user; };
struct Query;
struct World {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void Run(QueryInput* in, Query* collector, int flags);
};
struct Query {
    virtual void v00();
    const Input* input;
    void* linked14;
    void* user;
    int unk10[9];
    void* linked10;
    void FUN_009844e0(World* world, const Input* in, Linked* linked, void* user, void* e);
};
// pdb: hkpSimpleWorldRayCaster::castRay | hkpSimpleWorldRayCaster.obj | fnv360_0822_retail, ustr, high
// pdb params: broadphase, input, filter, cache, output
void Query::FUN_009844e0(World* world, const Input* in, Linked* linked, void* user, void* e)
{
    TimerMark(str_00e7d4cc);
    input = in;
    this->user = e;
    linked14 = linked ? &linked->unk14 : 0;
    if (in->flag)
        linked10 = linked ? &linked->unk10 : 0;
    else
        linked10 = 0;
    QueryInput qi;
    qi.pos.x = in->pos.x; qi.pos.y = in->pos.y; qi.pos.z = in->pos.z; qi.pos.w = in->pos.w;
    qi.count = 1;
    qi.data = in->unk10;
    qi.stride = 0x10;
    qi.user = user;
    world->Run(&qi, this, 0);
    TimerMark(str_00e32798);
}
}
}   // namespace f3m_009844e0

// @f3 0x0099db60 (community match, verified in this file)
namespace f3m_0099db60 {
__declspec(align(16)) struct Vdb60 { float x,y,z,w; void setMul4(float s,const Vdb60&a){x=s*a.x;y=s*a.y;z=s*a.z;w=s*a.w;} };
struct Mdb60 { Vdb60 c0,c1,c2; void FUN_0096cf70(const Mdb60&,const Mdb60&); };
struct Cdb60 { float unk00,unk04,unk08,unk0c; Mdb60 m10; float unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc; float m_c0,m_c4,m_c8; void hkpBoxMotion_getInertiaInvWorld(Mdb60& out); };
__declspec(align(16)) struct Sdb60 { float pad,x,y,z; float& operator()(int i){ return (&x)[i]; } };
// pdb: hkpBoxMotion::getInertiaInvWorld | hkpBoxMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void Cdb60::hkpBoxMotion_getInertiaInvWorld(Mdb60& out){ Sdb60 v; v(0)=m_c0;v(1)=m_c4;v(2)=m_c8; Mdb60 t; t.c0.setMul4(v(0),m10.c0);t.c1.setMul4(v(1),m10.c1);t.c2.setMul4(v(2),m10.c2); out.FUN_0096cf70(t,m10); }
}   // namespace f3m_0099db60

// @f3 0x00991450 (community match, verified in this file)
namespace f3m_00991450 {
struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void mul4(const hkVector4& a)
    {
        x = a.x * x;
        y = a.y * y;
        z = a.z * z;
        w = a.w * w;
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
};
extern hkVector4 DAT_01064a40;
extern hkVector4 DAT_01092a50;
struct hkAabb {
    hkVector4 m_min;
    hkVector4 m_max;
};
struct hkAabbUint32 {
    unsigned int m_min[4];
    unsigned int m_max[4];
};
__forceinline void ConvertToUint32WithClip(const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& minVal, const hkVector4& maxVal, unsigned int* out)
{
    hkVector4 x;
    x.setAdd4(in, offset);
    x.mul4(scale);
    x.setMin4(x, maxVal);
    x.setMax4(x, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}
__forceinline void ConvertAabbToUint32(const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut)
{
    hkVector4 maxVal = DAT_01064a40;
    ConvertToUint32WithClip(aabb.m_min, offsetLow, scale, DAT_01092a50, maxVal, aabbOut.m_min);
    ConvertToUint32WithClip(aabb.m_max, offsetHigh, scale, DAT_01092a50, maxVal, aabbOut.m_max);
}
struct SweepBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int first, hkAabbUint32* aabb, int third);
};
struct Sweep : SweepBase {
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030;
    int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060;
    int unk064; int unk068; int unk06c;
    hkVector4 m_offsetLow;
    hkVector4 m_offsetHigh;
    hkVector4 m_scale;
    void FUN_00991450(int first, const hkAabb& aabb, int third);
};
void Sweep::FUN_00991450(int first, const hkAabb& aabb, int third)
{
    hkAabbUint32 aabbInt;
    ConvertAabbToUint32(aabb, m_offsetLow, m_offsetHigh, m_scale, aabbInt);
    v5(first, &aabbInt, third);
}
}

// @f3 0x0099ebd0 (community match, verified in this file)
#include <math.h>
namespace f3m_0099ebd0 {

namespace f3m_0099ebd0 {

class __declspec(align(16)) hkVector4
{
public:
    float x, y, z, w;
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void setZero4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
    __forceinline void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    __forceinline float lengthSquared3() const { return x * x + y * y + z * z; }
};

struct hkTransform { hkVector4 m_col0, m_col1, m_col2, m_translation; };
struct hkAabb { hkVector4 m_min; hkVector4 m_max; };

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getAabb(const hkTransform& t, float tolerance, hkAabb& out) const;
    int unk04;
    int unk08;
    int m_type;
};

struct hkpCollidable
{
    hkpShape* m_shape;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int m_collisionFilterInfo;
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    float m_tolerance;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    void FUN_00921790(const hkpCollisionInput& other);
};

struct hkpProcessCollisionInput : hkpCollisionInput
{
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    void* m_config;
};

struct hkpLinearCastCollisionInput : hkpCollisionInput
{
    hkVector4 m_path;
    float m_maxExtraPenetration;
    float m_pathLength;
    void* m_config;
    __forceinline hkpLinearCastCollisionInput() : m_maxExtraPenetration(1.1920928955078125e-07f) {}
    __forceinline void set(const hkpProcessCollisionInput& input)
    {
        FUN_00921790(input);
        m_config = input.m_config;
    }
    __forceinline void setPathAndTolerance(const hkVector4& path, float tolerance)
    {
        m_path = path;
        m_pathLength = sqrtf(path.lengthSquared3());
        m_tolerance = tolerance;
    }
};

struct hkpLinearCastInput
{
    hkVector4 m_to;
    float m_maxExtraPenetration;
    float m_startPointTolerance;
};

struct hkpCdPointCollector;

typedef void (__cdecl *LinearCastFunc)(const hkpCollidable& a, const hkpCollidable& b,
    const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector,
    hkpCdPointCollector* startCollector);

struct AgentFuncs
{
    void* unk00;
    void* unk04;
    void* unk08;
    LinearCastFunc m_linearCastFunc;
    void* unk10;
};

struct hkpCollisionDispatcher
{
    int unk000[0x68];
    unsigned char m_agent2Types[32][32];
    int unk5a0[0x100];
    AgentFuncs m_agent2Func[32];
};

struct hkpWorld
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
    hkpProcessCollisionInput* m_collisionInput;
    int unk70;
    hkpCollisionDispatcher* m_collisionDispatcher;
};

class hkpSimpleShapePhantom
{
public:
    int unk00;
    int unk04;
    hkpWorld* m_world;
    int unk0c;
    hkpCollidable m_collidable;
    int unk30[0x1c];
    hkTransform m_transform;
    int unke0[0x1c];
    hkpCollidable** m_overlapping;
    int m_overlappingSize;
    void FUN_00989c00(const hkAabb& aabb);
    void FUN_0099ebd0(const hkVector4& position, const hkpLinearCastInput& input,
        hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector);
};

void hkpSimpleShapePhantom::FUN_0099ebd0(const hkVector4& position, const hkpLinearCastInput& input,
    hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector)
{
    m_transform.m_translation = position;

    hkAabb aabb;
    {
        float halfTolerance = m_world->m_collisionInput->m_tolerance * 0.5;
        float tol = halfTolerance + input.m_startPointTolerance;
        m_collidable.m_shape->getAabb(m_transform, tol, aabb);
    }
    hkVector4 path;
    path.setSub4(input.m_to, position);
    {
        hkVector4 zero; zero.setZero4();
        hkVector4 pathMin; pathMin.setMin4(zero, path);
        hkVector4 pathMax; pathMax.setMax4(zero, path);
        aabb.m_min.add4(pathMin);
        aabb.m_max.add4(pathMax);
    }
    FUN_00989c00(aabb);

    hkpLinearCastCollisionInput lcInput;
    lcInput.set(*m_world->m_collisionInput);
    lcInput.setPathAndTolerance(path, input.m_startPointTolerance);
    lcInput.m_maxExtraPenetration = input.m_maxExtraPenetration;

    hkpCollisionDispatcher* dispatcher = m_world->m_collisionDispatcher;
    for (int i = m_overlappingSize - 1; i >= 0; i--)
    {
        hkpCollidable*& other = m_overlapping[i];
        int typeB = other->m_shape->m_type;
        if (typeB == 0xb && (other->m_collisionFilterInfo & 0x2000))
            typeB = 9;
        int typeA = m_collidable.m_shape->m_type;
        LinearCastFunc f = dispatcher->m_agent2Func[dispatcher->m_agent2Types[typeA][typeB]].m_linearCastFunc;
        f(m_collidable, *other, lcInput, castCollector, startCollector);
    }
}

}
}   // namespace f3m_0099ebd0

// @f3 0x0098bc80 (community match, verified in this file)
namespace f3m_0098bc80 {
namespace BorderReleaseB {
struct Ref;
struct RefVtable { void (__thiscall *release)(Ref*, int); };
struct Ref {
    RefVtable* vtable;
    unsigned short memorySize;
    short references;
};
struct Deletion;
struct World { void hkpWorld_removeWorldDeletionListener(Deletion*); };
struct Deletion {
    void* unk00;
    void* unk04;
    World* world;
    Ref* Owner() { return reinterpret_cast<Ref*>(reinterpret_cast<char*>(this)-sizeof(Ref)); }
    void hkpBroadPhaseBorder_worldDeletedCallback(World*);
};
__forceinline void F(Ref* self, RefVtable* vt, int n) { self->vtable == vt ? vt->release(self, n) : vt->release(self, n); }
// pdb: hkpBroadPhaseBorder::worldDeletedCallback | hkpBroadPhaseBorder.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(objrun_open), high
void Deletion::hkpBroadPhaseBorder_worldDeletedCallback(World*) {
    world->hkpWorld_removeWorldDeletionListener(Owner() ? this : 0);
    Ref* owner = Owner();
    if (owner->memorySize && --owner->references == 0)
        F(owner, owner->vtable, 1);

}
}
}   // namespace f3m_0098bc80

// @f3 0x00982c80 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00982c80 {
namespace z982c80 {

struct StackMem {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocBlock(int size);
    virtual void FreeBlock(void* p);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* cur;
    int unk24;
    char* base;
    char* end;
};

struct Heap {
    void FUN_008f6d90(void* p, unsigned int size, int tag);
};

__declspec(dllimport) StackMem* __stdcall FUN_00d9b080(unsigned long index) throw();

void __cdecl FUN_00923500(void* dst, int value, int count);
void __cdecl FUN_00901f10(void* array, int elementSize);

static __forceinline void* StackAlloc(int bytes)
{
    StackMem* m = FUN_00d9b080(DAT_010f3170);
    int size = (bytes + 16) & ~15;
    char* p = m->cur;
    char* next = p + size;
    if (next <= m->end) {
        m->cur = next;
        return p;
    }
    return m->AllocBlock(size);
}

static __forceinline void StackFree(void* p)
{
    StackMem* m = FUN_00d9b080(DAT_010f3170);
    m->cur = (char*)p;
    if (p == m->base)
        m->FreeBlock(p);
}

template <class T> struct Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline void init()
    {
        m_data = 0;
        m_size = 0;
        m_capacityAndFlags = 0x80000000;
    }
    __forceinline void release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = m_capacityAndFlags & 0x3fffffff;
            Heap* h = (Heap*)FUN_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    __forceinline void pushBack(const T& v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = v;
        m_size++;
    }
};

template <class T> struct LocalArray : Array<T> {
    void* m_localMemory;

    __forceinline void initLocal(int n)
    {
        this->init();
        T* p = (T*)StackAlloc(n * sizeof(T));
        this->m_data = p;
        m_localMemory = p;
        this->m_capacityAndFlags = n | 0x80000000;
    }
    __forceinline void releaseLocal()
    {
        StackFree(m_localMemory);
        this->release();
    }
};
struct World;

struct Bool {
    char value;
    Bool(bool v) : value(v) {}
    Bool(const Bool& o) : value(o.value) {}
};

struct ConstraintLink {
    char unk00[0x10];
    signed char entityOffset;
};

struct ConstraintRef {
    void* constraint;
    ConstraintLink* link;
};

struct Entity {
    char unk00[0x5c];
    ConstraintRef* constraints;
    int numConstraints;
    char unk64[0x94 - 0x64];
    unsigned short storageIndex;
    char unk96[0xb8 - 0x96];
    World* world;
};

struct World {
    char unk00[0x4c];
    int numEntities;
};

struct FlagsC {
    char unk00[0xd0];
    bool enabled;
};

struct Flags170 {
    char unk00[0x10];
    bool enabled;
};

struct Collector {
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
    virtual void v44(Array<void*>* constraints, void* arg, World* world, Bool flag);
    int unk04, unk08;
    FlagsC* unk0c;
    char unk10[0x170 - 0x10];
    Flags170* unk170;

    void collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(Entity** entities, int num, void* arg);
    void FUN_00982c80(Entity** entities, int num, void* arg);
};

// pdb: hkpMultiThreadedSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable, medium
// pdb params: entities, numEntities, input, entitiesNeedingPsiCollisionDetection
void Collector::FUN_00982c80(Entity** entities, int num, void* arg)
{
    if (unk0c->enabled && unk170->enabled) {
    World* world = entities[0]->world;
    int n = world->numEntities;
    LocalArray<char> marks;
    marks.initLocal(n);
    FUN_00923500(marks.m_data, 0, n);
    LocalArray<void*> found;
    found.initLocal(1000);
    for (int i = 0; i < num; i++) {
        Entity* e = entities[i];
        marks.m_data[e->storageIndex] = 1;
        for (int j = 0; j < e->numConstraints; j++) {
            ConstraintRef* c = &e->constraints[j];
            Entity* other = (Entity*)((char*)c->link + c->link->entityOffset);
            if (other->world != world || !marks.m_data[other->storageIndex])
                found.pushBack(c->constraint);
        }
    }
    if (found.m_size)
        v44(&found, arg, world, Bool(false));
    found.releaseLocal();
    marks.releaseLocal();
    return;
    }
    collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(entities, num, arg);
}

}
}   // namespace f3m_00982c80

// @f3 0x0099f1c0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7de38[];
extern const char DAT_00e32798[];
extern const float DAT_00de731c;
namespace f3m_0099f1c0 {
namespace Bounds879 {
namespace imp {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}
struct TimerCommand { const char* command; unsigned int time0,time1; };
struct MonitorStream {
    void* unknown00;
    TimerCommand* end;
    TimerCommand* start;
    TimerCommand* limit;
    static MonitorStream* Get() {return (MonitorStream*)imp::FUN_00d9b080(DAT_0116913c);}
    void Record(const char* label) {
        TimerCommand* p=end;
        if (p < limit) {
            p->command=label;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            p->time0=ticks;
            end=p+1;
        }
    }
};
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    __forceinline void SetAll(float f) {x=f;y=f;z=f;w=f;}
    static __forceinline float Min(const float& a,const float& b) {return a<b?a:b;}
    static __forceinline float Max(const float& a,const float& b) {return a>b?a:b;}
    __forceinline void SetMin(const Vec4& a,const Vec4& b) {x=Min(a.x,b.x);y=Min(a.y,b.y);z=Min(a.z,b.z);w=Min(a.w,b.w);}
    __forceinline void SetMax(const Vec4& a,const Vec4& b) {x=Max(a.x,b.x);y=Max(a.y,b.y);z=Max(a.z,b.z);w=Max(a.w,b.w);}
};
struct Aabb {Vec4 low,high;};
struct Transform {Vec4 c0,c1,c2,translation;};
struct ShapeBuffer {Vec4 storage[32];};
struct Shape {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18();
    virtual void GetAabb(const Transform& transform,float tolerance,Aabb& out);
};
struct Container {
    virtual void f00(); virtual void f04();
    virtual unsigned int First();
    virtual unsigned int Next(unsigned int key);
    virtual void f10();
    virtual Shape* Child(unsigned int key,ShapeBuffer& buffer);
};
struct Collection {
    void* vtable;
    unsigned int u04,u08,u0c;
    Container container;
    void hkpShapeCollection_getAabbImpl(const Transform& transform,float tolerance,Aabb& out);
};
// pdb: hkpShapeCollection::getAabbImpl | hkpShapeCollection.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void Collection::hkpShapeCollection_getAabbImpl(const Transform& transform,float tolerance,Aabb& out) {
    MonitorStream::Get()->Record(DAT_00e7de38);
    out.low.SetAll(3.40282e38f);
    out.high.SetAll(-3.40282e38f);
    for(unsigned int key=container.First();key!=~0u;key=container.Next(key)) {
        ShapeBuffer buffer;
        Aabb childBounds;
        Shape* child=container.Child(key,buffer);
        child->GetAabb(transform,tolerance,childBounds);
        out.low.SetMin(out.low,childBounds.low);
        out.high.SetMax(out.high,childBounds.high);
    }
    MonitorStream::Get()->Record(DAT_00e32798);
}
}



}   // namespace f3m_0099f1c0

// @f3 0x00982160 (community match, verified in this file)
// Adapted from the older contributor checkpoint nm_c5d23c4dff3f47c2b2a8.
namespace f3m_00982160 {
extern "C" __declspec(dllimport) int __stdcall InitializeCriticalSectionAndSpinCount(void*, unsigned long);
struct Lock;
extern Lock DAT_011692e8;


struct Lock {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c;
    unsigned spin;
    Lock* prev;
    Lock* next;
    void FUN_00908a00();
    __forceinline Lock() : spin(4000), prev(0), next(0) {
        DAT_011692e8.FUN_00908a00();
        next = DAT_011692e8.next;
        if (next) next->prev = this;
        prev = &DAT_011692e8;
        DAT_011692e8.next = this;
        DAT_011692e8.unk18 = -1;
        DAT_011692e8.unk1c = -1;
        f3m_009835d0::LeaveCriticalSection(&DAT_011692e8);
        InitializeCriticalSectionAndSpinCount(this, 4000);
        unk18 = -1;
        unk1c = -1;
    }
};
struct Array { void* data; int count, capacity; __forceinline Array() : data(0), count(0), capacity(0x80000000) {} };

extern int DAT_00e7d424, DAT_00e7d3f4, DAT_00e7d404, DAT_00e7d414;
struct Dispatcher {
        void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* f24; void* f28; void* f2c;
        void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* f44; void* f48; void* f4c;
        void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* f64; void* f68; void* f6c;
};
struct World {     int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54; Dispatcher* unk58; };
struct Timer { void FUN_00a25c00(int); };
struct Inner {     int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50; Timer* unk54; };
struct ListenerA { void* table; void* owner; ListenerA() : table(&DAT_00e7d3f4), owner(0) {} };
struct ListenerB { void* table; void* owner; ListenerB() : table(&DAT_00e7d404), owner(0) {} };
struct ListenerC { void* table; void* owner; ListenerC() : table(&DAT_00e7d414), owner(0) {} };
void FUN_00a25250();
void FUN_00a256c0();
}
struct FUN_0098d900 {
    void* table;
    int unk04, unk08;
    f3m_00982160::Inner* unk0c;
        int unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    __forceinline FUN_0098d900(f3m_00982160::World* world) {
        reinterpret_cast<Owner517*>(this)->FUN_0098d900(
            reinterpret_cast<Source517*>(world));
    }
};
struct FUN_009021e0 { int unk00; FUN_009021e0(); };
struct FUN_009b4a10 {     int unk00, unk04, unk08, unk0c; FUN_009b4a10(int a, int b); };
struct FUN_00a21550 {
        int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    void* cb0;
    void* cb1;
    f3m_00982160::World* world;
        int unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78;
    int unk7c, unk80, unk84, unk88, unk8c, unk90;
    int unk94, unk98, unk9c, unka0, unka4, unka8;
    int unkac, unkb0, unkb4, unkb8, unkbc;
    FUN_00a21550(void* a, void* b, void* c);
};
struct SimulationBase : FUN_0098d900 {
    __forceinline SimulationBase(f3m_00982160::World* world)
        : FUN_0098d900(world) { table = &f3m_00982160::DAT_00e7d424; }
};
struct Flag1296 { char value; Flag1296() {} Flag1296(bool v):value(v) {} Flag1296& operator=(bool v) { value=v; return *this; } operator bool() const { return value!=0; } };
struct FUN_00982160 : SimulationBase {
    f3m_00982160::ListenerA m50;
    f3m_00982160::ListenerB m58;
    f3m_00982160::ListenerC m60;
    Flag1296 m68;
    f3m_00982160::Array m6c;
    f3m_00982160::Lock m78;
    int ma4;
    f3m_00982160::Array ma8;
    int mb4;
    f3m_00982160::Lock mb8;
    int me4;
    FUN_009021e0 me8;
    int mec;
    FUN_009b4a10 mf0;
    f3m_00982160::Lock m100;
        int unk12c, unk130, unk134, unk138, unk13c;
    FUN_00a21550 m140;
    FUN_009b4a10 m200;
        int unk210, unk214, unk218, unk21c, unk220, unk224;
    int unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254;
    int unk258, unk25c, unk260, unk264, unk268, unk26c;
    int unk270, unk274, unk278, unk27c;
    FUN_009b4a10 m280;
        int unk290, unk294, unk298, unk29c, unk2a0, unk2a4;
    int unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4;
    int unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec;
    int unk2f0, unk2f4, unk2f8, unk2fc;
    FUN_009b4a10 m300;
        int unk310, unk314, unk318, unk31c, unk320, unk324;
    int unk328, unk32c, unk330, unk334, unk338, unk33c;
    f3m_00982160::Lock m340;
        int unk36c, unk370, unk374, unk378, unk37c;
    f3m_00982160::Lock m380;
    FUN_00982160(f3m_00982160::World* world);
};
// pdb: hkpMultiThreadedSimulation::hkpMultiThreadedSimulation | hkpMultithreadedSimulation.obj | fnv360_0822_retail, uvref, high
// pdb params: world
FUN_00982160::FUN_00982160(f3m_00982160::World* world)
    : SimulationBase(world), mf0(0, 10), m140(&m200, &m280, &m300), m200(0, 1000), m280(0, 1000), m300(0, 1000)
{
    mec = 0;
    m68 = false;
    unk0c->unk54->FUN_00a25c00(10000);
    m58.owner = &m380;
    m50.owner = this;
    world->unk58->f24 = &m50;
    world->unk58->f44 = &m58;
    world->unk58->f28 = &m58;
    world->unk58->f48 = &m58;
    m60.owner = &m380;
    world->unk58->f2c = &m60;
    world->unk58->f64 = &m60;
    world->unk58->f4c = &m60;
    world->unk58->f68 = &m60;
    world->unk58->f6c = &m60;
    m140.world = world;
    m140.cb0 = (void*)&f3m_00982160::FUN_00a25250;
    m140.cb1 = (void*)&f3m_00982160::FUN_00a256c0;
}

// @f3 0x0098cf90 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0098cf90 {

namespace f3m_0098cf90 {

struct Vec4
{
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setSub4(const Vec4& a, const Vec4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void mul4(double rs)
    {
        float s = float(rs);
        (*this)(0) *= s;
        (*this)(1) *= s;
        (*this)(2) *= s;
        (*this)(3) *= s;
    }
    __forceinline void setMul4(float rs, const Vec4& a)
    {
        float r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
};

struct StackMem
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocBlock(int size);
    virtual void FreeBlock(void* p);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* cur;
    int unk24;
    char* base;
    char* end;
};

__declspec(dllimport) StackMem* __stdcall FUN_00d9b080(unsigned long index) throw();

__forceinline StackMem& getThreadMemory() { return *FUN_00d9b080(DAT_010f3170); }

__forceinline void* StackMem_allocateStack(StackMem& mem, int nbytes)
{
    int size = (nbytes + 16) & ~15;
    char* current = mem.cur;
    char* next = current + size;
    if (next <= mem.end) {
        mem.cur = next;
        return current;
    }
    return mem.AllocBlock(size);
}

__forceinline void StackMem_deallocateStack(StackMem& mem, void* p)
{
    mem.cur = (char*)p;
    if (p == mem.base)
        mem.FreeBlock(p);
}

template <class T> __forceinline T* allocateStackT(int n) { return (T*)StackMem_allocateStack(getThreadMemory(), n * sizeof(T)); }
template <class T> __forceinline void deallocateStackT(T* p) { StackMem_deallocateStack(getThreadMemory(), p); }

struct Accumulator
{
    int unk00, unk04, unk08, unk0c;
    Vec4 linearVel;
    Vec4 angularVel;
};

struct Entity
{
    char unk000[0x90];
    unsigned int solverData;
    unsigned short storageIndex;
    char unk096[0x120 - 0x96];
    Vec4 centerOfMass0;
    Vec4 centerOfMass1;
    char unk140[0x170 - 0x140];
    Vec4 deltaAngle;
};

struct ConstraintInternal
{
    void* constraint;
    Entity* entities[2];
};

struct ConstraintInstance
{
    char unk00[0x1c];
    unsigned char priority;
    char unk1d[0x28 - 0x1d];
    ConstraintInternal* internal;
};

struct SchemaInfo
{
    ConstraintInstance* constraint;
    void* schema;
    int unk08;
};

struct StepInfo
{
    int unk00, unk04;
    float deltaTime;
};

struct SolverResources
{
    StepInfo* stepInfo;
    void* solverInfo;
    int unk08;
    char* accumulators;
};

template <class T> struct Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const { return m_size; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
};

template <class T> struct FixedArray
{
    T* m_data;
    T& operator[](int i) { return m_data[i]; }
};

struct ProcessInput;

void __cdecl FUN_00901f10(void* array, int elementSize);
int __cdecl FUN_00a27c00(void* solverInfo, void* schema, char* accumulators, int maxVelocities, float* velocities);
int __cdecl FUN_0098ce40(float deltaTime, SchemaInfo* info, float* velocities, int numVelocities, ProcessInput& input);

template <class T> __forceinline void swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

__forceinline void pushBack(Array<Entity*>& a, Entity* e)
{
    if (a.m_size == (a.m_capacityAndFlags & 0x3fffffff))
        FUN_00901f10(&a, 4);
    a.m_data[a.m_size] = e;
    a.m_size++;
}

}

using f3m_0098cf90::Vec4;

// pdb: hkLs_toiCheckValidityOfConstraints | hkpContinuousSimulation.obj | tesv_win, call_gap, low
void __cdecl FUN_0098cf90(f3m_0098cf90::SolverResources& solverResources, f3m_0098cf90::ProcessInput& processInput,
    f3m_0098cf90::Array<f3m_0098cf90::SchemaInfo>& constraintStatus, int& firstNonActive, int minPriority,
    f3m_0098cf90::FixedArray<unsigned char>& entityState, const f3m_0098cf90::Array<f3m_0098cf90::Entity*>& touchedEntities,
    f3m_0098cf90::Array<f3m_0098cf90::Entity*>& toBeActivated)
{
    using namespace f3m_0098cf90;
    Entity* entity;
    float velocities[256];
    Vec4* oldVelocities = allocateStackT<Vec4>(touchedEntities.getSize() * 2);
    {
        Vec4* v = oldVelocities;
        for (int i = 0; i < touchedEntities.getSize(); i++)
        {
            Entity* e = touchedEntities[i];
            Accumulator* acc = (Accumulator*)(solverResources.accumulators + e->solverData);
            *v++ = acc->linearVel;
            *v++ = acc->angularVel;
            acc->linearVel.setSub4(e->centerOfMass1, e->centerOfMass0);
            acc->linearVel.mul4(e->centerOfMass1.w);
            acc->angularVel.setMul4(e->centerOfMass1.w, e->deltaAngle);
        }
    }
    for (int i = firstNonActive; i < constraintStatus.getSize(); i++)
    {
        SchemaInfo& info = constraintStatus[i];
        ConstraintInstance* instance = info.constraint;
        if (minPriority > instance->priority)
            continue;
        ConstraintInternal* ci = instance->internal;
        Entity** entities = ci->entities;
        int movingIndex = entityState[entities[0]->storageIndex] == 0x10;
        entity = entities[movingIndex];
        if (entityState[entity->storageIndex] & 4)
        {
            int j = firstNonActive++;
            swap(constraintStatus[j], constraintStatus[i]);
            continue;
        }
        int numVelocities = FUN_00a27c00(solverResources.solverInfo, info.schema, solverResources.accumulators, 256, velocities);
        if (FUN_0098ce40(solverResources.stepInfo->deltaTime, &info, velocities, numVelocities, processInput) != -1)
        {
            entityState[entity->storageIndex] |= 4;
            pushBack(toBeActivated, entity);
            int j = firstNonActive++;
            swap(constraintStatus[j], constraintStatus[i]);
        }
    }
    {
        Vec4* v = oldVelocities;
        for (int i = 0; i < touchedEntities.getSize(); i++)
        {
            Accumulator* acc = (Accumulator*)(solverResources.accumulators + touchedEntities[i]->solverData);
            acc->linearVel = *v++;
            acc->angularVel = *v++;
        }
    }
    deallocateStackT(oldVelocities);
}
}   // namespace f3m_0098cf90

// @f3 0x009874f0 (community match, verified in this file)
namespace f3m_009874f0 {
namespace n_009874f0 {
struct hkVector4 { float x, y, z, w; void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; } };
struct hkContactPoint { hkVector4 m_position; hkVector4 m_separatingNormal; };
struct hkpProcessCdPoint { hkContactPoint m_contact; int m_contactPointId; int unk24, unk28, unk2c; };
struct hkpProcessCollisionData { hkpProcessCdPoint* m_firstFreeContactPoint; int unk04, unk08, unk0c; hkpProcessCdPoint m_contactPoints[1]; };
struct hkpContactPointProperties;
struct hkpSimpleContactConstraintAtom {
    unsigned short m_type, m_numContactPoints, m_numReservedContactPoints, m_maxNumContactPoints;
    unsigned char m_numUserDatasInContactPointProperties, m_flag, m_contactPointPropertiesStriding, m_pad;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    hkContactPoint* getContactPoints() { return (hkContactPoint*)(this + 1); }
    hkpContactPointProperties* getContactPointPropertiesStream(short i) { return (hkpContactPointProperties*)((char*)this + 0x30 + m_maxNumContactPoints * sizeof(hkContactPoint) + m_contactPointPropertiesStriding * i); }
};
struct hkpCollidable { int unk00, unk04, unk08, unk0c; signed char m_ownerOffset; void* getOwner() const { return (void*)((char*)this + m_ownerOffset); } };
struct hkpRigidBody { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; unsigned short unk94; unsigned short m_processContactCallbackDelay; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; unsigned short m_contactListenersSize; };
struct hkpWorld;
struct Mgr;
struct hkpContactProcessEvent {
    const hkpCollidable* m_collidableA;
    const hkpCollidable* m_collidableB;
    int m_callbackFiredFrom;
    hkpProcessCollisionData* m_collisionData;
    hkpContactPointProperties* m_contactPointProperties[256];
    Mgr* m_internalContactMgr;
    hkpContactProcessEvent(Mgr* mgr, const hkpCollidable& a, const hkpCollidable& b, hkpProcessCollisionData* data) : m_collidableA(&a), m_collidableB(&b), m_collisionData(data), m_internalContactMgr(mgr) {}
};
void __cdecl hkpWorldCallbackUtil_fireContactProcess(hkpWorld* world, hkpContactProcessEvent& event);
void __cdecl hkpEntityCallbackUtil_fireContactProcessInternal(hkpRigidBody* body, hkpContactProcessEvent& event);
template <class T> inline T min2(T a, T b) { return a < b ? a : b; }
struct Mgr {
    void* vt;
    int unk04, unk08;
    hkpWorld* m_world;
    short unk10;
    unsigned short m_skipNextNprocessCallbacks;
    struct ContactData {
    int unk14, unk18, unk1c;
    unsigned char* m_values;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
    hkpSimpleContactConstraintAtom* m_atom;
    hkpContactPointProperties* getContactPointProperties(int id) { return id == 0xff ? 0 : m_atom->getContactPointPropertiesStream((short)id); }
    hkContactPoint& getPoint(int id) { int index = m_values[id]; return m_atom->getContactPoints()[index]; }
    } data;
    void FUN_009874f0(const hkpCollidable& a, const hkpCollidable& b, const void* input, hkpProcessCollisionData* collisionData);
};
}


void n_009874f0::Mgr::FUN_009874f0(const hkpCollidable& a, const hkpCollidable& b, const void* input, hkpProcessCollisionData* collisionData)
{
    int skip = m_skipNextNprocessCallbacks;
    if (skip-- == 0)
    {
        hkpRigidBody* rbA = (hkpRigidBody*)a.getOwner();
        hkpRigidBody* rbB = (hkpRigidBody*)b.getOwner();
        skip = min2(rbA->m_processContactCallbackDelay, rbB->m_processContactCallbackDelay);
        hkpContactProcessEvent event(this, a, b, collisionData);
        hkpContactPointProperties** props = event.m_contactPointProperties;
        hkpProcessCdPoint* callbackEnd = collisionData->m_firstFreeContactPoint;
        for (hkpProcessCdPoint* p = &collisionData->m_contactPoints[0]; p < callbackEnd; p++)
            *props++ = data.getContactPointProperties(data.m_values[p->m_contactPointId]);
        hkpWorldCallbackUtil_fireContactProcess(m_world, event);
        if (rbA->m_contactListenersSize)
            hkpEntityCallbackUtil_fireContactProcessInternal(rbA, event);
        if (rbB->m_contactListenersSize)
            hkpEntityCallbackUtil_fireContactProcessInternal(rbB, event);
    }
    m_skipNextNprocessCallbacks = (unsigned short)skip;
    hkpProcessCdPoint* end = collisionData->m_firstFreeContactPoint;
    for (hkpProcessCdPoint* p = &collisionData->m_contactPoints[0]; p < end; p++)
        data.getPoint(p->m_contactPointId) = p->m_contact;
}
}   // namespace f3m_009874f0

// @f3 0x009817a0 (community match, verified in this file)
namespace f3m_009817a0 {
// FUN_009817a0 - job dispatch loop (twin: FNV DispatchNodeByKind 0x00d01e50)
extern unsigned int DAT_010f3170;
namespace f3m_009817a0_ns {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}
using f3m_009817a0_ns::FUN_00d9b080;

struct __declspec(align(16)) Record {
    unsigned short kind;
    unsigned short pad02;
    int data[31];
};

struct Node {
    Node* unk00;
    Node* FUN_00a25600(int a, void* b, void* c);
};

struct TempStack {
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
    Node* unk88;
    int unk8c;
    void* FUN_008f6800(int a, int b);
    void FUN_008f6890(int a, void* p, int b);
    __forceinline void* pop()
    {
        Node* p = unk88;
        if (p) {
            unk8c--;
            unk88 = p->unk00;
            return p;
        }
        return FUN_008f6800(0xa, 4);
    }
};


struct JobQueue {
    int unk00;
    int FUN_00a22250(void* arg, Record* kind, int zero);
};

int __cdecl integrateJob(void*, void*, Record*);
int __cdecl FUN_00a23da0(void*, void*, Record*);
int __cdecl FUN_00a23c30(void*, void*, Record*);
int __cdecl hkCpuBuildJacobiansJob(void*, void*, Record*);
int __cdecl FUN_00a23820(void*, void*, Record*);
int __cdecl FUN_00a234f0(void*, void*, Record*);
int __cdecl hkCpuSolveConstraintBatchJob(void*, void*, Record*);
int __cdecl FUN_00a236b0(void*, void*, Record*);
int __cdecl hkCpuSolveExportResultsJob(void*, void*, Record*);
int __cdecl FUN_00a23410(void*, void*, Record*);
int __cdecl hkCpuSplitSimulationIslandJob(void*, void*, Record*);
int __cdecl hkpSingleThreadedJobsOnIsland_cpuBroadPhaseJob(void*, void*, Record*);
int __cdecl FUN_00a22660(void*, void*, Record*);
int __cdecl FUN_00a22490(void*, void*, Record*);

struct Ctx {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10[0x4c];
    JobQueue unk140;
    void FUN_009817a0(void* arg);
};

void Ctx::FUN_009817a0(void* arg)
{
    Record rec;
    if (unk140.FUN_00a22250(arg, &rec, 0))
        return;

    int status = 0;
    void* mem = ((TempStack*)FUN_00d9b080(DAT_010f3170))->pop();
    Node* node = mem ? ((Node*)mem)->FUN_00a25600(unk0c, this, arg) : 0;

    while (!status) {
        switch (rec.kind) {
        case 0: status = integrateJob(node, &unk140, &rec); break;
        case 1: status = FUN_00a23da0(node, &unk140, &rec); break;
        case 3: status = FUN_00a23c30(node, &unk140, &rec); break;
        case 4: status = hkCpuBuildJacobiansJob(node, &unk140, &rec); break;
        case 6: status = FUN_00a23820(node, &unk140, &rec); break;
        case 7: status = FUN_00a234f0(node, &unk140, &rec); break;
        case 8: status = hkCpuSolveConstraintBatchJob(node, &unk140, &rec); break;
        case 9: status = FUN_00a236b0(node, &unk140, &rec); break;
        case 10: status = hkCpuSolveExportResultsJob(node, &unk140, &rec); break;
        case 11: status = FUN_00a23410(node, &unk140, &rec); break;
        case 5: status = hkCpuSplitSimulationIslandJob(node, &unk140, &rec); break;
        case 12: status = hkpSingleThreadedJobsOnIsland_cpuBroadPhaseJob(node, &unk140, &rec); break;
        case 13:
        case 15: status = FUN_00a22660(node, &unk140, &rec); break;
        case 14:
            if (FUN_00a22490(node, &unk140, &rec))
                goto done;
            break;
        }
    }

done:
    if (node) {
        TempStack* t2 = (TempStack*)FUN_00d9b080(DAT_010f3170);
        if (*(const volatile int*)&t2->unk8c >= t2->unk34) {
            t2->FUN_008f6890(0xa, node, 4);
        } else {
            Node* head = t2->unk88;
            t2->unk8c += 1;
            node->unk00 = head;
            t2->unk88 = node;
        }
    }
}
}   // namespace f3m_009817a0

// @f3 0x00998e30 (community match, verified in this file)
extern const float DAT_00de731c;
namespace f3m_00998e30 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace N998e30 {
struct __declspec(align(16)) Vec {
    float x,y,z,w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void zero() { x=y=z=w=0.0f; }
    __forceinline void sub(const Vec& a,const Vec& b) { x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w; }
    __forceinline void mul(float s,const Vec& a) { x=s*a.x; y=s*a.y; z=s*a.z; w=s*a.w; }
    __forceinline void addmul(float s,const Vec& a) { x+=s*a.x; y+=s*a.y; z+=s*a.z; w+=s*a.w; }
    __forceinline float dot(const Vec& a) const { return x*a.x+y*a.y+z*a.z+w; }
};
struct Transform {
    Vec c0,c1,c2,pos;
    void FUN_00925300(const Transform&,const Transform&);
};
struct Sweep { Vec p0,p1,q0,q1,center; __forceinline float inv() const { return p1.w; } };
struct Motion {
    Transform transform;
    Sweep sweep;
    Vec delta;
    float radius;
    __forceinline const Transform& getTransform() const { return transform; }
    __forceinline const Sweep& getSweep() const { return sweep; }
};
struct Body {
    void* shape;
    unsigned key;
    const Transform* motion;
    const Body* parent;
    __forceinline const Motion* getMotion() const { return (const Motion*)motion; }
    __forceinline void* getShape() const { return shape; }
    __forceinline unsigned getKey() const { return key; }
    __forceinline void setShape(void* s,unsigned k) { shape=s; key=k; }
    __forceinline Body() {}
    __forceinline Body(const Body* p,const Transform* t) { parent=p; motion=t; }
    void* operator new(unsigned,void* p) throw() { return p; }
};
struct Quality { int u0,u4,u8,uc,continuous; };
struct Input {
    void* dispatcher;
    float tolerance;
    int u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c,u40,u44,u48,u4c;
    float start,end,dt,invdt;
    Quality* quality;
    __forceinline float getTolerance() const { return tolerance; }
};
struct Output { void* first; void* owner; };
struct Agent {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10(); virtual void v14();
    virtual void process(const Body&,const Body&,const Input&,Output&);
};
struct Entry {
    unsigned char command,index,count,size;
    unsigned short u4,u6;
    void* manager;
    int uc;
    const Body* a; const Body* b;
};
struct TimEntry : Entry { float time; int u1c; Vec normal; };
struct BaseInput { const Body* a; const Body* b; const Input* input; void* manager; Transform transform; };
struct ProcessInput : BaseInput { float distance; int offset; Vec tim; };
struct BodyTemp { Body a,b; Transform ta,tb; };
extern void __cdecl hkSweptTransformUtil_lerp2(const Sweep&,float,Transform&);
typedef void* (__cdecl *ProcessFn)(const ProcessInput&,Entry*,void*,Vec*,Output&);
typedef void (__cdecl *SepFn)(const BaseInput&,Entry*,void*,Vec&);
typedef void* (__cdecl *CleanFn)(Entry*,void*,void*,void*);
__forceinline ProcessFn processFn(const Input& i,int t) { return *(ProcessFn*)((char*)i.dispatcher+0x16dc+80*t); }
__forceinline SepFn sepFn(const Input& i,int t) { return *(SepFn*)((char*)i.dispatcher+0x16d8+80*t); }
__forceinline CleanFn cleanFn(const Input& i,int t) { return *(CleanFn*)((char*)i.dispatcher+0x16b8+80*t); }
static __forceinline void calc(const Motion& a,const Motion& b,float dt,Vec& out) {
    const Sweep& sa=a.getSweep(); const Sweep& sb=b.getSweep();
    Vec da; da.sub(sa.p0,sa.p1);
    Vec db; db.sub(sb.p1,sb.p0);
    float fa=dt*sa.inv(); float fb=dt*sb.inv();
    out.mul(fa,da); out.addmul(fb,db);
    out.w=fa*a.delta.w*a.radius+fb*b.delta.w*b.radius;
}
static __forceinline void init(BaseInput& in,BodyTemp& temp,BaseInput& out) {
    hkSweptTransformUtil_lerp2(in.a->getMotion()->getSweep(),in.input->start,temp.ta);
    hkSweptTransformUtil_lerp2(in.b->getMotion()->getSweep(),in.input->start,temp.tb);
    out.a=&temp.a; out.b=&temp.b; out.manager=in.manager; out.input=in.input;
    temp.a.setShape(in.a->getShape(),in.a->getKey());
    temp.b.setShape(in.b->getShape(),in.b->getKey());
    new (&temp.a) Body(in.a,&temp.ta);
    new (&temp.b) Body(in.b,&temp.tb);
    out.transform.FUN_00925300(temp.ta,temp.tb);
}
// pdb: hkAgentNnMachine_InlineProcessAgent | hkpAgentNnMachine.obj | tesv_win, caller_sim, low
static __declspec(noinline) void __cdecl FUN_00998e30(Entry* entry,int offset,const Input& input,int& counter,Output& output,void* mgr) {
    switch(entry->command) {
    case 6: {
        Agent* agent=*(Agent**)((char*)entry+0x20);
        agent->process(*entry->a,*entry->b,input,output);
        break;
    }
    case 2: {
        ProcessInput in;
        in.a=entry->a; in.b=entry->b; in.manager=entry->manager; in.input=&input;
        const Motion* ma=in.a->getMotion(); const Motion* mb=in.b->getMotion();
        calc(*ma,*mb,in.input->dt,in.tim);
        in.transform.FUN_00925300(ma->getTransform(),mb->getTransform());
        void* data=(char*)entry+0x20;
        in.offset=offset;
        processFn(input,entry->index)(in,entry,data,0,output);
        break;
    }
    case 4: {
        TimEntry* e=(TimEntry*)entry;
        ProcessInput in;
        in.a=entry->a; in.b=entry->b; in.manager=entry->manager; in.input=&input;
        in.offset=offset;
        const Motion* ma=in.a->getMotion(); const Motion* mb=in.b->getMotion();
        calc(*ma,*mb,in.input->dt,in.tim);
        void* data=e+1;
        float dist;
        if(e->time!=input.start) {
            if(!input.quality->continuous) {
                e->time=input.end;
                dist=-3.40282e38f;
                e->normal.zero(); e->normal(3)=dist;
                goto processEnd;
            }
            BodyTemp temp; BaseInput previous;
            init(in,temp,previous);
            sepFn(input,entry->index)(previous,entry,data,e->normal);
        }
        {
            Vec& normal=e->normal;
            e->time=input.end;
            dist=normal(3)-in.tim.dot(e->normal);
            if(dist>=input.getTolerance()) {
                e->normal(3)=dist;
                if(entry->count) cleanFn(input,entry->index)(entry,data,in.manager,output.owner);
                counter++;
                break;
            }
        }
    processEnd:
        in.distance=dist;
        in.transform.FUN_00925300(ma->getTransform(),mb->getTransform());
        processFn(input,entry->index)(in,entry,data,&e->normal,output);
        break;
    }
    default: break;
    }
}
// Fake match: this caller retains the static helper and its compiler-selected private register convention.
volatile Entry* callEntry; volatile int callOffset; const Input* volatile callInput; int callCounter; Output* volatile callOutput; void* volatile callMgr;
void caller() { FUN_00998e30((Entry*)callEntry,callOffset,*callInput,callCounter,*callOutput,callMgr); }
}
}   // namespace f3m_00998e30

// @f3 0x00997830 (community match, verified in this file)
namespace f3m_00997830 {
// 0x00997830: removes a batch of objects from the sweep-and-prune broad phase (hkp3AxisSweep::removeObjectBatch in
// Havok terms). The pairs the objects were part of are collected first; then their nodes are marked, the node array
// is compacted (the last live node moves into each freed slot), the three axes are rewritten with the relocation
// table, and the markers are updated for the removed end points.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_00997830 {

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

extern unsigned long DAT_010f3170;      // TLS slot of the per-thread memory manager

void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem);     // hkArrayUtil::_reserve

// per-thread memory manager with a stack for short-lived buffers
class hkThreadMemory
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void* onStackOverflow(int numBytes);
    virtual void onStackUnderflow(void* p);

    static __forceinline hkThreadMemory& getInstance() { return *static_cast<hkThreadMemory*>(TlsGetValue(DAT_010f3170)); }

    __forceinline void* allocateStack(int numBytes)
    {
        char* current = m_stackCurrent;
        char* next = current + numBytes;
        if (next <= m_stackEnd)
        {
            m_stackCurrent = next;
            return current;
        }
        return onStackOverflow(numBytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = static_cast<char*>(p);
        if (p == m_stackBase)
        {
            onStackUnderflow(p);
        }
    }

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    char* m_stackPrev;
    char* m_stackBase;
    char* m_stackEnd;
};

template <typename T>
__forceinline T* hkAllocateStack(int n)
{
    return static_cast<T*>(hkThreadMemory::getInstance().allocateStack((n * sizeof(T) + 16) & ~15));
}

template <typename T>
__forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

class __declspec(align(16)) hkVector4
{
public:
    __forceinline void setZero4() { x = 0; y = 0; z = 0; w = 0; }
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

// clears numQuads blocks of 16 bytes
__forceinline void memClear16(void* dst, int numQuads)
{
    hkVector4 zero;
    zero.setZero4();
    hkVector4* dest = static_cast<hkVector4*>(dst);
    for (int i = numQuads - 1; i >= 0; i--)
    {
        *dest++ = zero;
    }
}

struct hkBool
{
    __forceinline hkBool(bool b) : m_bool(b) {}
    char m_bool;
};

template <typename T>
struct hkArray
{
    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline T* begin() { return m_data; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

// where each node went when the node array was compacted: new index per old index, -1 for a removed node
struct hkpBpNodeRelocations
{
    int* m_newIndex;
    int unk04;
};

struct hkpBroadPhaseHandle
{
    hkUint32 m_id;
};

struct hkpBroadPhaseHandlePair;

// one object (or marker) in the sweep: its end-point indices on the three axes and its handle
struct hkpBpNode
{
    __forceinline int isMarker() const { return static_cast<int>(reinterpret_cast<unsigned long>(m_handle)) & 1; }

    hkUint16 min_y;
    hkUint16 min_z;
    hkUint16 max_y;
    hkUint16 max_z;
    hkUint16 min_x;
    hkUint16 max_x;
    hkpBroadPhaseHandle* m_handle;
};

struct hkpBpMarker
{
    hkUint16 m_nodeIndex;
    hkUint16 m_value;
    hkArray<hkUint16> m_overlappingObjects;
};

struct hkpBpAxis
{
    // drops the end points of removed nodes and renumbers the rest
    void FUN_00991b60(hkpBpNode* nodes, int axis, hkpBpNodeRelocations& relocations);

    void* m_endPoints;
    int m_numElements;
    int m_maxElements;
};

class hkp3AxisSweep
{
public:
    void FUN_00996690(const hkUint32* bitField, hkArray<hkpBroadPhaseHandlePair>& pairsOut, hkBool addMode);
    void FUN_00997830(const hkArray<hkpBroadPhaseHandle*>& removeObjectList, hkArray<hkpBroadPhaseHandlePair>& delPairsOut);

    __forceinline hkpBpMarker& getMarker(const hkpBpNode& node)
    {
        return *reinterpret_cast<hkpBpMarker*>(reinterpret_cast<char*>(m_markers) + (reinterpret_cast<unsigned long>(node.m_handle) & ~1));
    }

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
    hkArray<hkpBpNode> m_nodes;
    hkpBpAxis m_axis[3];
    int m_numMarkers;
    int m_ld2NumMarkers;
    hkpBpMarker* m_markers;
};

void hkp3AxisSweep::FUN_00997830(const hkArray<hkpBroadPhaseHandle*>& removeObjectList, hkArray<hkpBroadPhaseHandlePair>& delPairsOut)
{
    const int numObjects = removeObjectList.getSize();
    int numNodes = m_nodes.getSize();

    // the pairs the removed objects are part of, found with a bit per node
    {
        const int numBytes = numNodes >> 3;
        hkUint32* bitField = hkAllocateStack<hkUint32>((numNodes >> 5) + 8);
        memClear16(bitField, (numBytes >> 4) + 1);

        for (int i = 0; i < numObjects; i++)
        {
            int nodeIndex = removeObjectList[i]->m_id;
            int pos = nodeIndex >> 5;
            hkUint32 mask = 1 << (nodeIndex & 0x1f);
            bitField[pos] ^= mask;
        }

        FUN_00996690(bitField, delPairsOut, false);

        hkDeallocateStack(bitField);
    }

    // mark the nodes that go away
    hkpBroadPhaseHandle deletedHandle;
    deletedHandle.m_id = 0;
    {
        for (int i = 0; i < numObjects; i++)
        {
            m_nodes[removeObjectList[i]->m_id].m_handle = &deletedHandle;
            removeObjectList[i]->m_id = 0;
        }
    }

    // compact the node array; relocations[old index] = new index, or -1 for a removed node
    int* relocations = hkAllocateStack<int>(numNodes);
    hkpBpNodeRelocations relocationInfo;
    relocationInfo.m_newIndex = relocations;
    int last = numNodes - 1;
    {
        int i = 0;
        while (i <= last)
        {
            if (m_nodes[last].m_handle == &deletedHandle)
            {
                relocations[last] = -1;
                last--;
                continue;
            }

            hkpBpNode& node = m_nodes[i];
            if (node.m_handle == &deletedHandle)
            {
                node = m_nodes[last];
                relocations[last] = i;
                relocations[i] = -1;
                if (!node.isMarker())
                {
                    node.m_handle->m_id = i;
                }
                else
                {
                    getMarker(node).m_nodeIndex = static_cast<hkUint16>(i);
                }
                last--;
            }
            else
            {
                relocations[i] = i;
            }
            i++;
        }
    }
    numNodes = last + 1;
    m_nodes.setSize(numNodes);

    m_axis[0].FUN_00991b60(m_nodes.begin(), 0, relocationInfo);
    m_axis[1].FUN_00991b60(m_nodes.begin(), 1, relocationInfo);
    m_axis[2].FUN_00991b60(m_nodes.begin(), 2, relocationInfo);

    // the markers: fewer end points in front of their upper ends, and renumbered overlap lists
    if (m_numMarkers)
    {
        const int numEndPoints = numObjects * 2;
        for (int m = 0; m < m_numMarkers; m++)
        {
            hkpBpMarker& marker = m_markers[m];
            hkpBpNode& node = m_nodes[marker.m_nodeIndex];
            node.max_y = static_cast<hkUint16>(node.max_y - numEndPoints);
            node.max_z = static_cast<hkUint16>(node.max_z - numEndPoints);

            for (int j = 0; j < marker.m_overlappingObjects.getSize(); j++)
            {
                marker.m_overlappingObjects[j] = static_cast<hkUint16>(relocations[marker.m_overlappingObjects[j]]);
            }
        }
    }

    hkDeallocateStack(relocations);
}

}
}   // namespace f3m_00997830

// @f3 0x0099f710 (community match, verified in this file)
#include <math.h>
namespace f3m_0099f710 {

namespace TriangleNormal99f710 {
__forceinline float sqrtInverse(float value) {
    if (value != 0.0f) return 1.0f / (float)sqrt((double)value);
    return 0.0f;
}
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    __forceinline void setSub4(const Vector4& a, const Vector4& b) {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void setCross(const Vector4& a, const Vector4& b) {
        const float nx = a.y * b.z - a.z * b.y;
        const float ny = a.z * b.x - a.x * b.z;
        const float nz = a.x * b.y - a.y * b.x;
        x = nx; y = ny; z = nz; w = 0.0f;
    }
    __forceinline float lengthSquared3() const { return x*x + y*y + z*z; }
    __forceinline void mul4(float scale) {
        x *= scale; y *= scale; z *= scale; w *= scale;
    }
    __forceinline void normalize3() {
        float inverseLength = sqrtInverse(lengthSquared3());
        mul4(inverseLength);
    }
};

static __declspec(noinline) void FUN_0099f710(const Vector4& c, const Vector4& a,
                                           const Vector4& b, Vector4& normal) {
    Vector4 edges[2];
    edges[0].setSub4(a, c);
    edges[1].setSub4(b, a);
    normal.setCross(edges[0], edges[1]);
    normal.normalize3();
}

const Vector4* volatile inputA;
const Vector4* volatile inputB;
const Vector4* volatile inputC;
Vector4* volatile outputNormal;
void CallTriangleNormal() {
    FUN_0099f710(*inputC, *inputA, *inputB, *outputNormal);
}
}
}   // namespace f3m_0099f710

// @f3 0x00992f80 (community match, verified in this file)
// FUN_00992f80: Havok 3-axis sweep broad phase, batch AABB update. Per object the float AABB is quantised to
// 16-bit end-point values (offset, scale, clip against DAT_01060dd0 and zero, magic add DAT_01060db0, bits >> 7),
// then the node's six end points are moved through the three sorted axes: x through the marker-aware
// same-file __fastcall callees FUN_00991a40/FUN_00991ad0, y and z through FUN_009919a0/FUN_009919f0.
// Optimised code although the pack lists /Od: matched under /MT /O2 /GS /EHsc /Gy (same listing with /GS-).
// Spellings found by measurement that decide x87 operand order or register choice with identical instructions
// (a guess at the original source): the parentheses on the min-half adds and multiplies and on the last max-half
// magic add, vmin.y in the min-half magic add, the member forms for the max-half add and clip, the named oi in the
// first loop and the edges/maxPos locals of the x-axis loops, and the statements between the quantisation and the
// node set-up (the fourth max lane, the zeroed expansion words, the named object and node reference): together
// they set the numbering that orders the y-axis overlap terms.
inline float ClampMin(const float& a,const float& b){return a<b?a:b;}
inline float ClampMax(const float& a,const float& b){return a>b?a:b;}
struct __declspec(align(16)) V4
{
    float x, y, z, w;
    const float& Get(int i) const { return (&x)[i]; }
    float& Get(int i) { return (&x)[i]; }
    __forceinline void setAdd4(const V4& a, const V4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void mul4(const V4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline void setMinOf(const V4& a, const V4& b) { x = a.x < b.x ? a.x : b.x; y = a.y < b.y ? a.y : b.y; z = a.z < b.z ? a.z : b.z; w = a.w < b.w ? a.w : b.w; }
    __forceinline void setMaxOf(const V4& a, const V4& b) { x = a.x > b.x ? a.x : b.x; y = a.y > b.y ? a.y : b.y; z = a.z > b.z ? a.z : b.z; w = a.w > b.w ? a.w : b.w; }
};
struct hkAabbF { V4 m_min; V4 m_max; };
extern V4 DAT_01060dd0;
extern float DAT_01060db0;
extern float DAT_01060db4;
extern float DAT_01060db8;

struct __declspec(align(16)) hkAabbUint32 { unsigned int m_min[3]; unsigned int m_expansionMin; unsigned int m_max[3]; unsigned int m_expansionMax; };
struct __declspec(align(16)) S4 { unsigned short x, y, z, w; };
struct Edge { unsigned short pos; unsigned short node; };
struct Node {
    unsigned short minB;
    unsigned short minC;
    unsigned short maxB;
    unsigned short maxC;
    unsigned short minA;
    unsigned short maxA;
    unsigned unk0c;
    template <int AX> __forceinline unsigned short& getMin();
    template <int AX> __forceinline unsigned short& getMax();
    template <int AX> __forceinline unsigned short disjointOr(const Node& other) const;
};
template <> __forceinline unsigned short& Node::getMin<0>() { return minA; }
template <> __forceinline unsigned short& Node::getMax<0>() { return maxA; }
template <> __forceinline unsigned short& Node::getMin<1>() { return minB; }
template <> __forceinline unsigned short& Node::getMax<1>() { return maxB; }
template <> __forceinline unsigned short& Node::getMin<2>() { return minC; }
template <> __forceinline unsigned short& Node::getMax<2>() { return maxC; }
template <> __forceinline unsigned short Node::disjointOr<1>(const Node& other) const
{
    return (unsigned short)((maxC - other.minC) | (other.maxC - minC) | (maxA - other.minA) | (other.maxA - minA));
}
template <> __forceinline unsigned short Node::disjointOr<2>(const Node& other) const
{
    return (unsigned short)((other.maxA - minA) | (maxA - other.minA) | (other.maxB - minB) | (maxB - other.minB));
}
struct Obj { unsigned idx; };
struct Sink { int unk00; };

void __fastcall FUN_00991a40(Sink* s, Node* n, unsigned idx, Node* o, int a);
void __fastcall FUN_00991ad0(Sink* s, Node* n, unsigned idx, Node* o, int a);
void __fastcall FUN_009919a0(Node* n, Node* o, int a);
void __fastcall FUN_009919f0(Node* n, Node* o, int a);

struct FUN_00992f80_cls {
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
    union { float m_worldMin[3]; V4 m_offsetLow; };
    union { float m_worldMax[3]; V4 m_offsetHigh; };
    union { float m_quant[3]; V4 m_scale; };
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
    Node* m_nodes;
    int unka4;
    int unka8;
    Edge* m_edgesA;
    int unkb0;
    int unkb4;
    Edge* m_edgesB;
    int unkbc;
    int unkc0;
    Edge* m_edgesC;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    Sink* m_d8;
    template <int AX> __forceinline Edge*& edgesOf();
    template <int AX>
    __forceinline void updateYZ(Node* n, unsigned idx, Node* nodes, const hkAabbUint32& a32, int a14, int a18)
    {
        {
            unsigned b = n->getMin<AX>();
            Edge* e = edgesOf<AX>() + b;
            unsigned p;
            while (a32.m_min[AX] < (p = e[-1].pos)) {
                unsigned oi = e[-1].node;
                Node* o = nodes + oi;
                e->pos = (unsigned short)p;
                e->node = (unsigned short)oi;
                if (p & 1) {
                    unsigned short d = n->disjointOr<AX>(*o);
                    o->getMax<AX>() = (unsigned short)b;
                    if (!(d & 0x8000)) FUN_009919a0(n, o, a14);
                } else {
                    o->getMin<AX>() = (unsigned short)b;
                }
                e--;
                e->node = (unsigned short)idx;
                b--;
            }
            n->getMin<AX>() = (unsigned short)b;
            e->pos = (unsigned short)a32.m_min[AX];
        }

        {
            Edge* e = edgesOf<AX>() + n->getMax<AX>();
            int cnt = 0;
            unsigned p = e[1].pos;
            while (a32.m_max[AX] > p) {
                e++;
                Node* o = nodes + e->node;
                e[-1] = e[0];
                cnt++;
                e->node = (unsigned short)idx;
                if (!(p & 1)) {
                    unsigned short d = n->disjointOr<AX>(*o);
                    o->getMin<AX>()--;
                    if (!(d & 0x8000)) FUN_009919a0(n, o, a14);
                } else {
                    o->getMax<AX>()--;
                }
                p = e[1].pos;
            }
            n->getMax<AX>() += (unsigned short)cnt;
        }

        {
            Edge* e = edgesOf<AX>() + n->getMax<AX>();
            int cnt = 0;
            unsigned p = e[-1].pos;
            while (a32.m_max[AX] < p) {
                Node* o = nodes + e[-1].node;
                cnt--;
                e--;
                e[1] = e[0];
                e->node = (unsigned short)idx;
                if (!(p & 1)) {
                    unsigned short d = n->disjointOr<AX>(*o);
                    o->getMin<AX>()++;
                    if (!(d & 0x8000)) FUN_009919f0(n, o, a18);
                } else {
                    o->getMax<AX>()++;
                }
                p = e[-1].pos;
            }
            n->getMax<AX>() += (unsigned short)cnt;
            e->pos = (unsigned short)a32.m_max[AX];
        }

        {
            Edge* e = edgesOf<AX>() + n->getMin<AX>();
            int cnt = 0;
            unsigned p = e[1].pos;
            while (a32.m_min[AX] > p) {
                Node* o = nodes + e[1].node;
                cnt++;
                e++;
                e[-1] = e[0];
                e->node = (unsigned short)idx;
                if (p & 1) {
                    unsigned short d = n->disjointOr<AX>(*o);
                    o->getMax<AX>()--;
                    if (!(d & 0x8000)) FUN_009919f0(n, o, a18);
                } else {
                    o->getMin<AX>()--;
                }
                p = e[1].pos;
            }
            n->getMin<AX>() += (unsigned short)cnt;
            e->pos = (unsigned short)a32.m_min[AX];
        }

    }
    void FUN_00992f80(Obj** begin, float* aabb, unsigned count, int a14, int a18);
};

template <> __forceinline Edge*& FUN_00992f80_cls::edgesOf<0>() { return m_edgesA; }
template <> __forceinline Edge*& FUN_00992f80_cls::edgesOf<1>() { return m_edgesB; }
template <> __forceinline Edge*& FUN_00992f80_cls::edgesOf<2>() { return m_edgesC; }

void FUN_00992f80_cls::FUN_00992f80(Obj** begin, float* aabb, unsigned count, int a14, int a18)
{
    Obj** end = begin + count;
    for (Obj** it = begin; it < end; ++it, aabb += 8) {
        V4 vmin, vmax;
        V4 hi = DAT_01060dd0;
        V4 zero; zero.x = zero.y = zero.z = zero.w = 0.0f;
        vmin.Get(0) = (m_worldMin[0] + aabb[0]);
        vmin.Get(1) = (m_worldMin[1] + aabb[1]);
        vmin.Get(2) = (m_worldMin[2] + aabb[2]);
        vmin.Get(0) = (m_quant[0] * vmin.Get(0));
        vmin.Get(1) = (m_quant[1] * vmin.Get(1));
        vmin.Get(2) = (m_quant[2] * vmin.Get(2));
        vmin.Get(0) = ClampMin(vmin.Get(0),hi.Get(0));
        vmin.Get(1) = ClampMin(vmin.Get(1),hi.Get(1));
        vmin.Get(2) = ClampMin(vmin.Get(2),hi.Get(2));
        vmin.Get(0) = ClampMax(vmin.Get(0),0.0f);
        vmin.Get(1) = ClampMax(vmin.Get(1),0.0f);
        vmin.Get(2) = ClampMax(vmin.Get(2),0.0f);
        vmin.Get(0) = DAT_01060db0 + vmin.Get(0);
        vmin.y = DAT_01060db4 + vmin.y;
        vmin.Get(2) = DAT_01060db8 + vmin.Get(2);
        S4 qmin, qmax;
        qmin.x = (unsigned short)(*(unsigned*)&vmin.Get(0) >> 7);
        qmin.y = (unsigned short)(*(unsigned*)&vmin.Get(1) >> 7);
        qmin.z = (unsigned short)(*(unsigned*)&vmin.Get(2) >> 7);
        vmax.setAdd4(m_offsetHigh, ((const hkAabbF*)aabb)->m_max);
        vmax.Get(0) = m_quant[0] * vmax.Get(0);
        vmax.Get(1) = m_quant[1] * vmax.Get(1);
        vmax.Get(2) = m_quant[2] * vmax.Get(2);
        vmax.setMinOf(vmax, hi);
        vmax.Get(0) = ClampMax(vmax.Get(0),0.0f);
        vmax.Get(1) = ClampMax(vmax.Get(1),0.0f);
        vmax.Get(2) = ClampMax(vmax.Get(2),0.0f);
        vmax.Get(0) = vmax.Get(0) + DAT_01060db0;
        vmax.Get(1) = vmax.Get(1) + DAT_01060db4;
        vmax.Get(2) = (vmax.Get(2) + DAT_01060db8);
        qmax.x = (unsigned short)(*(unsigned*)&vmax.Get(0) >> 7);
        qmax.y = (unsigned short)(*(unsigned*)&vmax.Get(1) >> 7);
        qmax.z = (unsigned short)(*(unsigned*)&vmax.Get(2) >> 7);
        qmax.w = (unsigned short)(*(unsigned*)&vmax.Get(3) >> 7);
        hkAabbUint32 a32;
        a32.m_min[0] = qmin.x & 0xfffe;
        a32.m_min[1] = qmin.y & 0xfffe;
        a32.m_min[2] = qmin.z & 0xfffe;
        a32.m_max[0] = qmax.x | 1;
        a32.m_max[1] = qmax.y | 1;
        a32.m_max[2] = qmax.z | 1;
        a32.m_expansionMin = 0;
        a32.m_expansionMax = 0;
        Node* nodes = m_nodes;
        Obj* object = *it;
        unsigned idx = object->idx;
        Node& node = nodes[idx];
        Node* n = &node;
        {
            unsigned b = n->getMin<0>();
            Edge* edges = edgesOf<0>(); Edge* e = edges + b;
            unsigned p;
            while (a32.m_min[0] < (p = e[-1].pos)) {
                unsigned oi = e[-1].node;
                Node* o = nodes + oi;
                e->pos = (unsigned short)p;
                e->node = (unsigned short)oi;
                if (p & 1) {
                    unsigned d0=*(unsigned*)&o->maxB - *(unsigned*)&n->minB; unsigned d1=*(unsigned*)&n->maxB - *(unsigned*)&o->minB; unsigned overlap=d0|d1;
                    o->maxA = (unsigned short)b;
                    if (!(overlap & 0x80008000u)) FUN_00991a40(m_d8, n, idx, o, a14);
                } else {
                    o->minA = (unsigned short)b;
                }
                e--;
                e->node = (unsigned short)idx;
                b--;
            }
            n->getMin<0>() = (unsigned short)b;
            e->pos = (unsigned short)a32.m_min[0];
        }

        {
            Edge* edges = edgesOf<0>(); Edge* e = edges + n->getMax<0>();
            int cnt = 0;
            unsigned p = e[1].pos;
            while (a32.m_max[0] > p) {
                e++;
                Node* o = nodes + e->node;
                e[-1] = e[0];
                cnt++;
                e->node = (unsigned short)idx;
                if (!(p & 1)) {
                    unsigned d0=*(unsigned*)&o->maxB - *(unsigned*)&n->minB; unsigned d1=*(unsigned*)&n->maxB - *(unsigned*)&o->minB; unsigned overlap=d0|d1;
                    o->minA--;
                    if (!(overlap & 0x80008000u)) FUN_00991a40(m_d8, n, idx, o, a14);
                } else {
                    o->maxA--;
                }
                p = e[1].pos;
            }
            n->getMax<0>() += (unsigned short)cnt;
        }

        {
            Edge* edges = edgesOf<0>();
            unsigned short maxPos = n->getMax<0>();
            Edge* e = edges + maxPos;
            int cnt = 0;
            unsigned p = e[-1].pos;
            while (a32.m_max[0] < p) {
                Node* o = nodes + e[-1].node;
                cnt--;
                e--;
                e[1] = e[0];
                e->node = (unsigned short)idx;
                if (!(p & 1)) {
                    unsigned d0=*(unsigned*)&o->maxB - *(unsigned*)&n->minB; unsigned d1=*(unsigned*)&n->maxB - *(unsigned*)&o->minB; unsigned overlap=d0|d1;
                    o->minA++;
                    if (!(overlap & 0x80008000u)) FUN_00991ad0(m_d8, n, idx, o, a18);
                } else {
                    o->maxA++;
                }
                p = e[-1].pos;
            }
            n->getMax<0>() += (unsigned short)cnt;
            e->pos = (unsigned short)a32.m_max[0];
        }

        {
            Edge* edges = edgesOf<0>(); Edge* e = edges + n->getMin<0>();
            int cnt = 0;
            unsigned p = e[1].pos;
            while (a32.m_min[0] > p) {
                Node* o = nodes + e[1].node;
                cnt++;
                e++;
                e[-1] = e[0];
                e->node = (unsigned short)idx;
                if (p & 1) {
                    unsigned d0=*(unsigned*)&o->maxB - *(unsigned*)&n->minB; unsigned d1=*(unsigned*)&n->maxB - *(unsigned*)&o->minB; unsigned overlap=d0|d1;
                    o->maxA--;
                    if (!(overlap & 0x80008000u)) FUN_00991ad0(m_d8, n, idx, o, a18);
                } else {
                    o->minA--;
                }
                p = e[1].pos;
            }
            n->getMin<0>() += (unsigned short)cnt;
            e->pos = (unsigned short)a32.m_min[0];
        }

        updateYZ<1>(n, idx, nodes, a32, a14, a18);
        updateYZ<2>(n, idx, nodes, a32, a14, a18);
    }
}

// @f3 0x009845e0 (community match, verified in this file)
extern unsigned long hkMonitorStreamTls;
extern unsigned long DAT_010f3170;
extern const char DAT_00e7d4dc[];
namespace f3m_009845e0 {
extern "C" __declspec(dllimport) void* __stdcall DAT_00d9b080(unsigned long dwTlsIndex);

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) : m_bool(static_cast<char>(b)) {}
    __forceinline operator bool() const { return m_bool != 0; }
private:
    char m_bool;
};

template <typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return m_storage; }
    __forceinline void operator=(T v) { m_storage = v; }
private:
    T m_storage;
};

class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)DAT_00d9b080(hkMonitorStreamTls);
    }

    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
    hkBool m_isBufferAllocatedOnTheHeap;

    struct Command
    {
        const char* m_commandAndMonitor;
    };

    struct TimerCommand : public Command
    {
        unsigned int m_time0;
        unsigned int m_time1;

        __forceinline void setTime()
        {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class hkThreadMemory
{
public:
    virtual ~hkThreadMemory();
    virtual void* alignedAllocate(int alignment, int nbytes, int cl);
    virtual void alignedDeallocate(void* ptr);
    virtual void* allocateChunk(int nbytes, int cl);
    virtual void deallocateChunk(void* ptr, int nbytes, int cl);
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* ptr);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)DAT_00d9b080(DAT_010f3170);
    }

    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 0x10) & ~0xf;
        char* p = m_stack.m_current;
        char* next = p + nbytes;
        if (next <= m_stack.m_end)
        {
            m_stack.m_current = next;
            return p;
        }
        return onStackOverflow(nbytes);
    }

    __forceinline void deallocateStack(void* p)
    {
        m_stack.m_current = static_cast<char*>(p);
        if (p == m_stack.m_base)
        {
            onStackUnderflow(p);
        }
    }

    struct Stack
    {
        char* m_current;
        Stack* m_prev;
        char* m_base;
        char* m_end;
    };

    void* m_memory;
    int m_referenceCount;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    Stack m_stack;
};

template <typename T>
__forceinline T* hkAllocateStack(int n)
{
    return static_cast<T*>(hkThreadMemory::getInstance().allocateStack(n * sizeof(T)));
}

template <typename T>
__forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(static_cast<void*>(p));
}

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkVector4() {}

    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }

    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }

    float x;
    float y;
    float z;
    float w;
};

class hkAabb
{
public:
    __forceinline hkAabb() {}

    hkVector4 m_min;
    hkVector4 m_max;
};

struct hkpWorldRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkBool m_enableShapeCollectionFilter;
    unsigned int m_filterInfo;
};

struct hkpWorldRayCastOutput
{
    hkVector4 m_normal;
    float m_hitFraction;
    int m_extraInfo;
    int m_shapeKeyIndex;
    int m_pad1c;
    int m_shapeKeys[8];
    int m_pad40[4];
    const void* m_rootCollidable;
    int m_pad54[3];
};

class hkpCollisionFilter;

class hkpBroadPhase
{
public:
    virtual ~hkpBroadPhase();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual int getAabbCacheSize() const;
    virtual void calcAabbCache0(const void* collidables, char* cache) const;
    virtual void calcAabbCache(const hkAabb& aabb, char* cache) const;
};

class hkpSimpleWorldRayCaster
{
public:
    virtual ~hkpSimpleWorldRayCaster();
    virtual float addBroadPhaseHandle(const void* broadPhaseHandle, int castIndex);

    void FUN_009844e0(const hkpBroadPhase& broadphase, const hkpWorldRayCastInput& input, const hkpCollisionFilter* filter, const char* cache, hkpWorldRayCastOutput& output);
    void hkpSimpleWorldRayCaster_castRayGroup(const hkpBroadPhase& broadphase, const hkpWorldRayCastInput* inputArray, int numRays, const hkpCollisionFilter* filter, hkpWorldRayCastOutput* outputs);

    const hkpWorldRayCastInput* m_input;
    const void* m_filter;
    hkpWorldRayCastOutput* m_result;
    hkVector4 m_shapeInputFrom;
    hkVector4 m_shapeInputTo;
    unsigned int m_shapeInputFilterInfo;
    const void* m_shapeInputCollidableFilter;
};

// pdb: hkpSimpleWorldRayCaster::castRayGroup | hkpSimpleWorldRayCaster.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void hkpSimpleWorldRayCaster::hkpSimpleWorldRayCaster_castRayGroup(const hkpBroadPhase& broadphase, const hkpWorldRayCastInput* inputArray, int numRays, const hkpCollisionFilter* filter, hkpWorldRayCastOutput* outputs)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = DAT_00e7d4dc;
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkAabb aabb;
    {
        aabb.m_min.setMin4(inputArray->m_from, inputArray->m_to);
        aabb.m_max.setMax4(inputArray->m_from, inputArray->m_to);
        const hkpWorldRayCastInput* in = inputArray;
        in++;
        for (int x = numRays - 2; x >= 0; x--)
        {
            aabb.m_min.setMin4(aabb.m_min, in->m_to);
            aabb.m_min.setMin4(aabb.m_min, in->m_from);
            aabb.m_max.setMax4(aabb.m_max, in->m_to);
            aabb.m_max.setMax4(aabb.m_max, in->m_from);
            in++;
        }
    }

    int cacheSize = broadphase.getAabbCacheSize();
    char* cache = hkAllocateStack<char>(cacheSize);
    broadphase.calcAabbCache(aabb, cache);

    {
        const hkpWorldRayCastInput* in = inputArray;
        hkpWorldRayCastOutput* out = outputs;
        for (int x = numRays - 1; x >= 0; x--)
        {
            FUN_009844e0(broadphase, *in, filter, cache, *out);
            in++;
            out++;
        }
    }

    hkDeallocateStack<char>(cache);

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}
}   // namespace f3m_009845e0

// @f3 0x009866a0 (community match, verified in this file)
namespace f3m_009866a0 {
// 0x009866a0: hkpReportContactMgr::addContactPointImpl(const hkpCdBody& a, const hkpCdBody& b,
// const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
// hkContactPoint& cp) of Havok 5.5.0 (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The contact manager that only reports: it works out the two bodies' relative velocity along the contact normal,
// fires the contact point added callbacks (the world's, then each body's own listeners) and, if a listener
// rejected the point, removes it again and returns the invalid id; otherwise it takes over the listeners' process
// callback delay and returns id 0.
// The event structs, their constructors, the callback wrapper and the vector helpers follow the Havok 5.5.0 SDK's
// headers and inline code. The SDK ships no header for this class: its members are named after the SDK's other
// contact managers. The function's own body is written from the game's code.
namespace f3m_009866a0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef int hkInt32;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef hkUint16 hkContactPointId;

const int HK_NULL = 0;
const hkContactPointId HK_INVALID_CONTACT_POINT = 0xffff;

template <typename ENUM, typename STORAGE>
class hkEnum
{
public:
    hkEnum() {}
    hkEnum(ENUM e) { m_storage = static_cast<STORAGE>(e); }
    operator ENUM() const { return static_cast<ENUM>(m_storage); }

private:
    STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

template <typename T>
class hkSmallArray
{
public:
    __forceinline int getSize() const { return m_size; }

    T* m_data;
    hkUint16 m_size;
    hkUint16 m_capacityAndFlags;
};

struct hkVector4
{
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

class hkContactPoint
{
public:
    __forceinline const hkVector4& getPosition() const { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();
    virtual void calcStatistics(void* collector) const;
    virtual void calcContentStatistics(void* collector, const void* cls) const;

    hkUint16 m_memSizeAndFlags;
    hkInt16 m_referenceCount;
};

class hkpCdBody;
class hkpWorld;
class hkpGskCache;
class hkpProcessCdPoint;
class hkpCollisionListener;
class hkpContactPointProperties;
class hkpDynamicsContactMgr;
class hkCollisionConstraintOwner;
struct hkpProcessCollisionInput;

struct hkpProcessCollisionOutput
{
    hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
    hkPadSpu<hkCollisionConstraintOwner*> m_constraintOwner;
};

// hkpWorldObject and hkpEntity up to the collision listeners; the members in between are not used here
class hkpEntity : public hkReferencedObject
{
public:
    char m_worldObjectAndEntityMembers[0x1e8];
    hkSmallArray<hkpCollisionListener*> m_collisionListeners;
};

class hkpRigidBody : public hkpEntity
{
public:
    // getPointVelocity, kept out of line
    void FUN_00917120(const hkVector4& p, hkVector4& vecOut) const;
};

enum hkpContactPointAccept
{
    HK_CONTACT_POINT_ACCEPT = 0,
    HK_CONTACT_POINT_REJECT = 1
};

struct hkpContactPointAddedEvent
{
    const hkpCdBody* m_bodyA;
    const hkpCdBody* m_bodyB;

    enum Type
    {
        TYPE_TOI,
        TYPE_MANIFOLD
    };

    const hkEnum<Type, hkInt32> m_type;
    hkpEntity* m_callbackFiredFrom;
    const hkContactPoint* m_contactPoint;
    const hkpGskCache* m_gskCache;
    hkpContactPointProperties* m_contactPointProperties;
    hkReal m_projectedVelocity;
    hkpContactPointAccept m_status;
    hkpDynamicsContactMgr* m_internalContactMgr;
    const hkpProcessCollisionInput* m_collisionInput;
    hkpProcessCollisionOutput* m_collisionOutput;

    inline hkpContactPointAddedEvent(hkpDynamicsContactMgr* contactMgr, const hkpProcessCollisionInput* collisionInput,
                                     hkpProcessCollisionOutput* collisionOutput, const hkpCdBody* a,
                                     const hkpCdBody* b, hkContactPoint* cp, const hkpGskCache* gskCache,
                                     hkpContactPointProperties* cpp, hkReal projectedVelocity, Type pointType);
};

inline hkpContactPointAddedEvent::hkpContactPointAddedEvent(hkpDynamicsContactMgr* contactMgr,
                                                            const hkpProcessCollisionInput* collisionInput,
                                                            hkpProcessCollisionOutput* collisionOutput,
                                                            const hkpCdBody* a, const hkpCdBody* b, hkContactPoint* ccp,
                                                            const hkpGskCache* gskCache, hkpContactPointProperties* dcp,
                                                            hkReal projectedVelocity, Type pointType)
    : m_bodyA(a),
      m_bodyB(b),
      m_type(pointType),
      m_contactPoint(ccp),
      m_gskCache(gskCache),
      m_contactPointProperties(dcp),
      m_projectedVelocity(projectedVelocity),
      m_internalContactMgr(contactMgr),
      m_collisionInput(collisionInput),
      m_collisionOutput(collisionOutput)
{
    m_status = HK_CONTACT_POINT_ACCEPT;
}

struct hkpManifoldPointAddedEvent : public hkpContactPointAddedEvent
{
    hkContactPointId m_contactPointId;
    mutable hkUint16 m_nextProcessCallbackDelay;

    inline hkpManifoldPointAddedEvent(hkContactPointId contactPointId, hkpDynamicsContactMgr* contactMgr,
                                      const hkpProcessCollisionInput* collisionInput,
                                      hkpProcessCollisionOutput* collisionOutput, const hkpCdBody* a,
                                      const hkpCdBody* b, hkContactPoint* cp, const hkpGskCache* gskCache,
                                      hkpContactPointProperties* cpp, hkReal projectedVelocity);
};

inline hkpManifoldPointAddedEvent::hkpManifoldPointAddedEvent(hkContactPointId contactPointId,
                                                              hkpDynamicsContactMgr* contactMgr,
                                                              const hkpProcessCollisionInput* collisionInput,
                                                              hkpProcessCollisionOutput* collisionOutput,
                                                              const hkpCdBody* a, const hkpCdBody* b,
                                                              hkContactPoint* cp, const hkpGskCache* gskCache,
                                                              hkpContactPointProperties* cpp, hkReal projectedVelocity)
    : hkpContactPointAddedEvent(contactMgr, collisionInput, collisionOutput, a, b, cp, gskCache, cpp,
                                projectedVelocity, TYPE_MANIFOLD),
      m_contactPointId(contactPointId)
{
    m_nextProcessCallbackDelay = 0;
}

class hkpWorldCallbackUtil
{
public:
    // fireContactPointAdded
    static void FUN_00988bb0(hkpWorld* world, hkpContactPointAddedEvent& event);
};

class hkpEntityCallbackUtil
{
public:
    static __forceinline void fireContactPointAdded(hkpEntity* entity, hkpContactPointAddedEvent& event);

protected:
    // fireContactPointAddedInternal
    static void FUN_00988180(hkpEntity* entity, hkpContactPointAddedEvent& event);
};

__forceinline void hkpEntityCallbackUtil::fireContactPointAdded(hkpEntity* entity, hkpContactPointAddedEvent& event)
{
    if (entity->m_collisionListeners.getSize())
    {
        FUN_00988180(entity, event);
    }
}

class hkpContactMgr : public hkReferencedObject
{
public:
    enum Type
    {
        TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
        TYPE_REPORT_CONTACT_MGR,
        TYPE_CONVEX_LIST_CONTACT_MGR,
        TYPE_NULL_CONTACT_MGR,
        TYPE_USER_CONTACT_MGR,
        TYPE_MAX
    };

    virtual hkContactPointId addContactPointImpl(const hkpCdBody& a, const hkpCdBody& b,
                                                 const hkpProcessCollisionInput& input,
                                                 hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                                 hkContactPoint& cp) = 0;
    virtual int reserveContactPointsImpl(int numPoints) = 0;
    virtual void removeContactPointImpl(hkContactPointId cpId, hkCollisionConstraintOwner& constraintOwner) = 0;

    Type m_type;
};

class hkpDynamicsContactMgr : public hkpContactMgr
{
public:
    hkpWorld* m_world;
};

class hkpReportContactMgr : public hkpDynamicsContactMgr
{
public:
    // addContactPointImpl
    hkContactPointId FUN_009866a0(const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input,
                                  hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                  hkContactPoint& cp);

    hkpRigidBody* m_bodyA;
    hkpRigidBody* m_bodyB;
    hkInt16 m_skipNextNprocessCallbacks;
};

// pdb: hkpVehicleLinearCastWheelCollide::getCollisionOutputFromCastResult | hkpVehicleLinearCastWheelCollide.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkpReportContactMgr::addContactPointImpl)
// pdb params: vehicle, wheelNum, linearCastOutput, output
hkContactPointId hkpReportContactMgr::FUN_009866a0(const hkpCdBody& a, const hkpCdBody& b,
                                                   const hkpProcessCollisionInput& input,
                                                   hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                                   hkContactPoint& cp)
{
    hkpRigidBody* rbA = m_bodyA;
    hkpRigidBody* rbB = m_bodyB;

    // the bodies' relative velocity at the contact point, along the contact normal
    hkVector4 velA;
    rbA->FUN_00917120(cp.getPosition(), velA);
    hkVector4 velB;
    rbB->FUN_00917120(cp.getPosition(), velB);
    hkVector4 dv;
    dv.setSub4(velB, velA);
    hkReal projectedVelocity = dv.dot3(cp.getNormal());

    hkpManifoldPointAddedEvent event(0, this, &input, &output, &a, &b, &cp, contactCache, HK_NULL, projectedVelocity);
    hkpWorldCallbackUtil::FUN_00988bb0(m_world, event);
    hkpEntityCallbackUtil::fireContactPointAdded(rbA, event);
    hkpEntityCallbackUtil::fireContactPointAdded(rbB, event);

    if (event.m_status == HK_CONTACT_POINT_REJECT)
    {
        // a listener refused the point
        removeContactPointImpl(0, *output.m_constraintOwner.val());
        return HK_INVALID_CONTACT_POINT;
    }

    m_skipNextNprocessCallbacks = event.m_nextProcessCallbackDelay;
    return 0;
}

}  // namespace f3m_009866a0
}   // namespace f3m_009866a0

// @f3 0x0098fce0 (community match, verified in this file)
// hkpContinuousSimulation::simulateToi (Havok 5.5), FNV twin Self::FUN_00d100a0
// (hkpcontinuoussimulation.cpp). FO3 has no rotation argument, no reference counter and no
// entity sort; the active array and the stack flags are released inside the solve block.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace N98fce0 {

extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern bool DAT_0116931c;

struct SimulationSettings { int unk00; int m_simulationType; };
extern SimulationSettings* DAT_010f3400;

bool __cdecl FUN_00a284b0(int feature) throw();
void __cdecl FUN_00923500(void* p, int value, int n) throw();
void __cdecl FUN_00a0a5c0(void* resources) throw();

struct ProfRec {
    const char* m_pName;
    unsigned int m_iTick;
    const char* m_subName;
    __forceinline void stamp()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_iTick = ticks;
    }
};
struct ProfPairRec {
    const char* m_pName;
    unsigned int m_iTick;
    int unk08;
    const char* m_subName;
    __forceinline void stamp()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_iTick = ticks;
    }
};
struct ProfBuf { int unk00; char* m_pCur; int unk08; char* m_pRecordEnd; };

static __forceinline void clockOne(const char* name)
{
    ProfBuf& stream = *(ProfBuf*)TlsGetValue(DAT_0116913c);
    if (stream.m_pCur < stream.m_pRecordEnd) {
        ProfRec* command = (ProfRec*)stream.m_pCur;
        command->m_pName = name;
        command->stamp();
        stream.m_pCur = (char*)(command + 1);
    }
}
static __forceinline void clockTwo(const char* name, const char* sub)
{
    ProfBuf& stream = *(ProfBuf*)TlsGetValue(DAT_0116913c);
    if (stream.m_pCur < stream.m_pRecordEnd) {
        ProfPairRec* command = (ProfPairRec*)stream.m_pCur;
        command->m_pName = name;
        command->m_subName = sub;
        command->stamp();
        stream.m_pCur = (char*)(command + 1);
    }
}

struct hkThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes) throw();
    virtual void onStackUnderflow(void* p) throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_current;
    int unk24;
    char* m_base;
    char* m_end;

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 15) & ~15;
        char* current = m_current;
        if (current + nbytes <= m_end) {
            m_current = current + nbytes;
            return current;
        }
        return onStackOverflow(nbytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_base)
            onStackUnderflow(p);
    }
    void FUN_008f6d90(void* p, int size, int cls) throw();
};

template <class T>
struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = getCapacity();
            hkThreadMemory* mem = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline int getSize() const { return m_size; }
    __forceinline T* begin() { return m_data; }
};

template <class T, int N>
struct hkInplaceArray : hkArray<T> {
    T m_storage[N];
    __forceinline hkInplaceArray()
    {
        this->m_data = m_storage;
        this->m_size = 0;
        this->m_capacityAndFlags = N | 0x80000000;
    }
};

struct hkpSimulationIsland {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
    void* m_entitiesData;
    int m_numEntities;
};

struct hkpEntity {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90;
    unsigned short m_storageIndex;
    unsigned short unk96;
    int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4;
    hkpSimulationIsland* m_simulationIsland;
    int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4;
    unsigned char m_motionType;
    __forceinline hkpSimulationIsland* getSimulationIsland() const { return m_simulationIsland; }
    __forceinline bool isFixed() const { return m_motionType == 7; }
};

struct hkpContactPointProperties;
struct hkpDynamicsContactMgr {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void confirmToi(hkpSimulationIsland* island, hkpContactPointProperties* properties) throw();
};

struct hkpContactPointProperties {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
};

struct hkpToiEvent {
    float m_time;
    hkpEntity* m_entities[2];
    float m_separatingVelocity;
    hkpDynamicsContactMgr* m_contactMgr;
    int unk14; int unk18; int unk1c;
    float m_position[4];
    float m_normal[4];
    hkpContactPointProperties m_properties;
    hkpToiEvent& FUN_00990390(const hkpToiEvent& other) throw();
};

struct hkpToiEventArray {
    hkpToiEvent* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline int getSize() const { return m_size; }
    __forceinline hkpToiEvent& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_size--;
        m_data[index].FUN_00990390(m_data[m_size]);
    }
};

struct hkpToiResources {
    int m_mode;
    int m_maxNumActiveEntities;
    int m_maxNumConstraints;
    int m_maxNumEntities;
    int m_numToiSolverIterations;
    int m_numForcedToiFinalSolverIterations;
    char* m_scratchpad;
    int m_scratchpadSize;
    __forceinline hkpToiResources()
    {
        m_maxNumActiveEntities = 1000;
        m_maxNumConstraints = 1000;
        m_maxNumEntities = 1000;
        m_numToiSolverIterations = 4;
        m_numForcedToiFinalSolverIterations = 4;
        m_scratchpad = 0;
        m_scratchpadSize = 0;
        m_mode = 2;
    }
};

struct hkpToiResourceMgr {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int beginToiAndSetupResources(hkpToiEvent* event, hkpToiEventArray* events, hkpToiResources* resources) throw();
    virtual void v10();
    virtual void v14();
    virtual void endToiAndFreeResources(hkpToiEvent* event, hkpToiEventArray* events, hkpToiResources* resources) throw();
};

struct __declspec(align(16)) hkVector4 {
    float m_quad[4];
    __forceinline void setZero4() { m_quad[0] = m_quad[1] = m_quad[2] = m_quad[3] = 0.0f; }
};

struct hkFlagView {
    unsigned char* m_data;
    int m_debugSize;
    __forceinline hkFlagView(unsigned char* p) : m_data(p) {}
};

struct hkStepInfoD881 {
    float m_startTime;
    float m_endTime;
    float m_deltaTime;
    float m_invDeltaTime;
    __forceinline hkStepInfoD881() {}
    hkStepInfoD881(float startTime, float endTime) throw();
};

struct hkpSolverInfoD881 {
    int unk00; int unk04; int unk08; int unk0c;
    hkVector4 m_globalAccelerationPerSubStep;
    hkVector4 m_globalAccelerationPerStep;
    int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac;
    int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc;
    int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec;
    int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108;
    float m_deltaTime;
    float m_invDeltaTime;
    int m_numSteps;
    int m_numMicroSteps;
    int unk11c;
    float m_invNumSteps;
    int unk124; int unk128; int unk12c;
    void FUN_00990200(const void* other) throw();
    void FUN_00902100(float tau, float damping) throw();
};

struct __declspec(align(16)) hkpConstraintQueryInD881 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    void FUN_00981430(hkpSolverInfoD881* solverInfo, hkStepInfoD881* stepInfo) throw();
};

struct hkpConstraintSolverResourcesD881 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
};

void __cdecl InitializeConstraintSolverResources(hkStepInfoD881* stepInfo, hkpSolverInfoD881* solverInfo,
    hkpConstraintQueryInD881* queryIn, char* buffer, int bufferSize, hkpConstraintSolverResourcesD881* resources) throw();

struct hkpProcessCollisionInput {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    hkStepInfoD881 m_stepInfo;
};

struct hkpWorld {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    hkpProcessCollisionInput* m_collisionInput;
    int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int m_solverInfo;
    __forceinline hkpProcessCollisionInput* getCollisionInput() const { return m_collisionInput; }
    float FUN_009022e0() throw();
};

__declspec(noinline) hkStepInfoD881::hkStepInfoD881(float startTime, float endTime) throw()
{
    m_startTime = startTime;
    m_endTime = endTime;
    m_deltaTime = endTime - startTime;
    m_invDeltaTime = (m_deltaTime == 0.0f) ? 0.0f : 1.0f / m_deltaTime;
}

typedef hkInplaceArray<hkpEntity*, 64> hkEntityArray64;

int __cdecl solveToiIsland(int mode, hkpConstraintSolverResourcesD881* solver, hkpToiEvent* event,
    hkpToiResourceMgr* mgr, hkpWorld* world, hkArray<hkpEntity*>* active, unsigned char* flags) throw();

// Same-file localized TOI solve (0x0098ec70): the flag view's address does not escape it.
__declspec(noinline) int __cdecl localizedSolveToi(const hkpToiResources& resources, hkpConstraintSolverResourcesD881& solver,
    hkpToiEvent& event, hkpToiResourceMgr& mgr, hkpWorld* world, hkArray<hkpEntity*>& active, const hkFlagView& flags) throw()
{
    return solveToiIsland(resources.m_mode, &solver, &event, &mgr, world, &active, flags.m_data);
}

struct hkpContinuousSimulation {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void collideEntitiesNarrowPhase(hkpEntity** entities, int numEntities, hkpProcessCollisionInput* input) throw();
    int unk04; int unk08; int unk0c; int unk10; int unk14;
    float m_18;
    int unk1c; int unk20; int unk24; int unk28; int unk2c;
    hkpToiEventArray m_toiEvents;
    hkpToiResourceMgr* m_toiResourceMgr;

    void FUN_0098df40(hkpEntity** entities, int numEntities, hkpWorld* world, int mode) throw();
    __forceinline void release(hkpToiEvent& event)
    {
        hkpSimulationIsland* island = !event.m_entities[0]->isFixed() ? event.m_entities[0]->getSimulationIsland()
                                                                      : event.m_entities[1]->getSimulationIsland();
        event.m_contactMgr->confirmToi(island, &event.m_properties);
    }
    __forceinline void scan(const hkpSimulationIsland* island, const unsigned char* flags, hkpToiEventArray& events)
    {
        for (int i = events.getSize() - 1; i >= 0; --i) {
            hkpToiEvent& e = events[i];
            if ((e.m_entities[0]->getSimulationIsland() == island && flags[e.m_entities[0]->m_storageIndex] == 16) ||
                (e.m_entities[1]->getSimulationIsland() == island && flags[e.m_entities[1]->m_storageIndex] == 16)) {
                release(events[i]);
                events.removeAt(i);
            }
        }
    }
    __forceinline void process(hkpWorld* world, hkpEntity** data, int count, hkpProcessCollisionInput* input)
    {
        if (count) {
            FUN_0098df40(data, count, world, 0);
            if (DAT_010f3400->m_simulationType != 1)
                collideEntitiesNarrowPhase(data, count, input);
        }
    }
    void FUN_0098fce0(hkpWorld* world, hkpToiEvent* pair, float physicsDeltaTime);
};

// pdb: hkpMultiThreadedSimulation::collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: hkpContinuousSimulation::simulateToi)
// pdb params: input, entitiesNeedingPsiCollisionDetection
void hkpContinuousSimulation::FUN_0098fce0(hkpWorld* world, hkpToiEvent* pair, float physicsDeltaTime)
{
    if (!DAT_0116931c) {
        DAT_0116931c = FUN_00a284b0(3);
        if (!DAT_0116931c)
            return;
    }
    hkpToiEvent& event = *pair;
    hkpToiResources query;
    if (m_toiResourceMgr->beginToiAndSetupResources(&event, &m_toiEvents, &query) == 1)
        return;
    {
        hkStepInfoD881 step;
        hkpSolverInfoD881 solver;
        hkpConstraintQueryInD881 input;
        step.m_startTime = event.m_time;
        step.m_endTime = world->FUN_009022e0();
        step.m_deltaTime = step.m_endTime - step.m_startTime;
        step.m_invDeltaTime = 1.0f / step.m_deltaTime;
        solver.FUN_00990200(&world->m_solverInfo);
        solver.m_numSteps = 1;
        solver.m_invNumSteps = 1.0f;
        solver.m_numMicroSteps = 1;
        solver.m_invNumSteps = 1.0f;
        solver.m_deltaTime = physicsDeltaTime;
        solver.m_invDeltaTime = 1.0f / physicsDeltaTime;
        solver.m_globalAccelerationPerSubStep.setZero4();
        solver.m_globalAccelerationPerStep.setZero4();
        solver.FUN_00902100(0.5f, 1.4f);
        input.FUN_00981430(&solver, &step);
        hkpConstraintSolverResourcesD881 state;
        InitializeConstraintSolverResources(&step, &solver, &input, query.m_scratchpad, query.m_scratchpadSize, &state);
        clockTwo("LtTOI", "StSolveToi");
        hkpSimulationIsland* island = !event.m_entities[0]->isFixed() ? event.m_entities[0]->getSimulationIsland()
                                                                      : event.m_entities[1]->getSimulationIsland();
        int count = island->m_numEntities;
        unsigned char* flags = (unsigned char*)hkThreadMemory::getInstance().allocateStack(count + 1);
        hkFlagView view(flags);
        FUN_00923500(flags, 0, count);
        {
            hkEntityArray64 active;
            int result = localizedSolveToi(query, state, event, *m_toiResourceMgr, world, active, view);
            FUN_00a0a5c0(&state);
            release(event);
            if (result == 0) {
                scan(island, flags, m_toiEvents);
                clockOne("StCollide");
                hkStepInfoD881 stepInfo(event.m_time, m_18);
                world->getCollisionInput()->m_stepInfo = stepInfo;
                process(world, active.begin(), active.getSize(), world->getCollisionInput());
            }
            active.releaseMemory();
        }
        hkThreadMemory::getInstance().deallocateStack(flags);
    }
    m_toiResourceMgr->endToiAndFreeResources(&event, &m_toiEvents, &query);
    clockOne("lt");
}

} // namespace N98fce0

// @f3 0x00990930 (community match, verified in this file)
namespace f3m_00990930 {
struct __declspec(align(16)) V0930
{
    float x, y, z, w;
    float& operator()(int i)
    {
        return (&x)[i];
    }
};
struct Quant0930
{
    V0930 m00;
    V0930 m10;
    V0930 m_min;
    V0930 m_max;
    V0930 m_offset;
    V0930 m_center;
    V0930 m_scale;
    V0930 m_a;
    V0930 m_b;
    V0930 m_c;
    void FUN_00990930(const V0930& a, const V0930& b, const V0930& c);
};
void Quant0930::FUN_00990930(const V0930& a, const V0930& b, const V0930& c)
{
    m_a.x = a.x; m_a.y = a.y; m_a.z = a.z; m_a.w = a.w;
    m_b.x = b.x; m_b.y = b.y; m_b.z = b.z; m_b.w = b.w;
    m_c.x = c.x; m_c.y = c.y; m_c.z = c.z; m_c.w = c.w;
    m_offset.x = a.x; m_offset.y = a.y; m_offset.z = a.z; m_offset.w = a.w;
    V0930 d;
    d.x = m_max.x - m_min.x;
    d.y = m_max.y - m_min.y;
    d.z = m_max.z - m_min.z;
    d.w = m_max.w - m_min.w;
    V0930 h;
    h.x = d.x * 1.5259720385074615e-05;
    h.y = d.y * 1.5259720385074615e-05;
    h.z = d.z * 1.5259720385074615e-05;
    h.w = d.w * 1.5259720385074615e-05;
    m_center.x = m_offset.x + h.x;
    m_center.y = m_offset.y + h.y;
    m_center.z = m_offset.z + h.z;
    m_center.w = m_offset.w + h.w;
    V0930 r;
    r.x = 1.0f / d.x;
    r.y = 1.0f / d.y;
    r.z = 1.0f / d.z;
    r.w = 0.0f;
    m_scale.x = r.x * 65532.0;
    m_scale.y = r.y * 65532.0;
    m_scale.z = r.z * 65532.0;
    m_scale.w = r.w * 65532.0;
    m_scale(3) = 0.0f;
    m_offset(3) = 0.0f;
    m_center(3) = 0.0f;
}
}   // namespace f3m_00990930

// @f3 0x00998a30 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace pair998a30 {
struct Body;struct Obj;struct Info;
struct __declspec(align(16)) Vec4 {float x,y,z,w;};
struct __declspec(align(16)) Transform {Vec4 c0,c1,c2,translation;void FUN_00925300(const Transform*,const Transform*);};
struct Entry {Obj* pair;Body* partner;};
struct EntryArray {Entry* data;int size;int capAndFlags;};
struct BlockArray {unsigned char** data;int size;int capAndFlags;};
struct Track {unsigned int used;BlockArray blocks;};
struct Allocator {void* FUN_008f6d30(int bytes,int memoryClass);};
void __cdecl FUN_00901f10(void* array,int elementSize);
struct Body {
 unsigned int unk00,unk04;
 const Transform* motion;
 unsigned int unk0c,unk10,unk14;
 unsigned short unk18,shapeType;
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
 EntryArray entries;
 unsigned int unk58;
};
struct Obj {
 unsigned char type,quality,unk02,state;
 unsigned short indexA,indexB;
 void* userData;
 signed char agentType;
 unsigned char unk0d,unk0e,unk0f;
 Body* first;Body* second;
 float timeOfImpact;
 unsigned int unk1c;
 Vec4 separatingNormal;
 unsigned int payloadAt30;
};
struct Context {char* base;unsigned int unk04;
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
 char* currentEntry;
};
struct __declspec(align(16)) Info {Body* first;Body* second;Context* context;void* userData;Transform relative;};
typedef void (__cdecl* CreateAgent)(Info*,Obj*,void*);
struct Slot {CreateAgent create;unsigned int unk04;
 unsigned int unk08;
 unsigned int unk0c;
 unsigned int unk10;
 unsigned int unk14;
 unsigned int unk18;
 unsigned int unk1c;
 unsigned int unk20;
 unsigned int unk24;
 int flag28;unsigned int unk2c;
 unsigned int unk30;
 unsigned int unk34;
 unsigned int unk38;
 unsigned int unk3c;
 unsigned int unk40;
 unsigned int unk44;
 unsigned int unk48;
 unsigned int unk4c;
};
extern float DAT_00db38b8;
// pdb: hkAgentNnMachine_AllocateEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, call_seq + bridge(caller|call_gap) + skyrim(call_seq), high
static __declspec(noinline) Obj* hkAgentNnMachine_AllocateEntry(Track* track) {
 if(track->used<0x200u) {
  unsigned char* page=track->blocks.data[track->blocks.size-1];
  Obj* result=reinterpret_cast<Obj*>(page+track->used);
  track->used+=0x80u;
  return result;
 }
 Allocator* allocator=static_cast<Allocator*>(TlsGetValue(DAT_010f3170));
 unsigned char* page=static_cast<unsigned char*>(allocator->FUN_008f6d30(0x200,0x27));
 BlockArray* blocks=&track->blocks;
 if(blocks->size==(blocks->capAndFlags&0x3fffffff))FUN_00901f10(blocks,4);
 blocks->data[blocks->size++]=page;
 track->used=0x80;
 return reinterpret_cast<Obj*>(page);
}
// pdb: hkAgentNnMachine_CreateAgent | hkpAgentNnMachine.obj | fnv360_0822_retail, call_gap + bridge(call_gap_sim|call_dedup) + skyrim(call_gap_sim), high
Obj* __cdecl hkAgentNnMachine_CreateAgent(Track* track,Body* first,Body* second,int quality,Context* context,void* userData) {
 char* base=context->base;
 Obj* pair=hkAgentNnMachine_AllocateEntry(track);
 pair->userData=userData;
 pair->first=first;pair->second=second;
 pair->indexA=static_cast<unsigned short>(first->entries.size);
 pair->indexB=static_cast<unsigned short>(second->entries.size);
 EntryArray* a=&first->entries;
 if(a->size==(a->capAndFlags&0x3fffffff))FUN_00901f10(a,8);
 Entry* entryA=&a->data[a->size++];
 EntryArray* b=&second->entries;
 if(b->size==(b->capAndFlags&0x3fffffff))FUN_00901f10(b,8);
 Entry* entryB=&b->data[b->size++];
 entryA->pair=pair;entryB->pair=pair;
 entryA->partner=second;entryB->partner=first;
 Info info;
 info.userData=pair->userData;
 info.first=first;info.second=second;info.context=context;
 info.relative.FUN_00925300(first->motion,second->motion);
 signed char agentType=context->base[first->shapeType*10+second->shapeType+0x1bb0];
 pair->agentType=agentType;
 context->currentEntry=context->base+0x1c20+static_cast<int>(agentType)*64;
 pair->quality=static_cast<unsigned char>(quality);
 Slot* table=reinterpret_cast<Slot*>(base+0x16b0);
 void* data;
 if(table[quality].flag28) {
  pair->timeOfImpact=DAT_00db38b8;
  pair->type=4;
  float* normal=&pair->separatingNormal.x;
  normal[3]=0.0f;normal[2]=0.0f;normal[1]=0.0f;normal[0]=0.0f;
  data=&pair->payloadAt30;
 } else {
  pair->type=2;data=&pair->separatingNormal;
 }
 table[pair->quality].create(&info,pair,data);
 pair->state=0x80;
 return pair;
}
}

// @f3 0x0099d340 (community match, verified in this file)
namespace f3m_0099d340 {
namespace c_0099d340 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 { Vec4 col0, col1, col2; };
void __stdcall FUN_0099d340(Matrix3* m)
{
    Vec4 z;
    z.SetZero4();
    m->col0 = z;
    m->col1 = z;
    m->col2 = z;
}
}
}   // namespace f3m_0099d340

// @f3 0x0099d380 (community match, verified in this file)
namespace f3m_0099d380 {
namespace c_0099d380 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 { Vec4 col0, col1, col2; };
void __stdcall FUN_0099d380(Matrix3* m)
{
    Vec4 z;
    z.SetZero4();
    m->col0 = z;
    m->col1 = z;
    m->col2 = z;
}
}
}   // namespace f3m_0099d380

// @f3 0x0099d400 (community match, verified in this file)
namespace f3m_0099d400 {
namespace c_0099d400 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 { Vec4 col0, col1, col2; };
void __stdcall FUN_0099d400(Matrix3* m)
{
    Vec4 z;
    z.SetZero4();
    m->col0 = z;
    m->col1 = z;
    m->col2 = z;
}
}
}   // namespace f3m_0099d400

// @f3 0x0099d4a0 (community match, verified in this file)
namespace f3m_0099d4a0 {
namespace c_0099d4a0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 {
    Vec4 col0, col1, col2;
    void SetZero() { Vec4 z; z.SetZero4(); col0 = z; col1 = z; col2 = z; }
    float& operator()(int r, int c) { return (&(&col0)[c].x)[r]; }
    void SetDiagonal(float v) { SetZero(); (*this)(0, 0) = v; (*this)(1, 1) = v; (*this)(2, 2) = v; }
};
struct Motion {
    int unk00[0x30];
    float mC0;
    void FUN_0099d4a0(Matrix3* out);
};
void Motion::FUN_0099d4a0(Matrix3* out)
{
    float v = 1.0f / mC0;
    out->SetDiagonal(v);
}
}
}   // namespace f3m_0099d4a0

// @f3 0x0099d830 (community match, verified in this file)
namespace f3m_0099d830 {
struct __declspec(align(16)) Vec4_9d830 {
    float x;
    float y;
    float z;
    float w;
};
struct Obj9d830 {
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
    float unkCC;
    float unkD0;
    float unkD4;
    float unkD8;
    float unkDC;
    void FUN_0099d830(float s, const float* v);
};
void Obj9d830::FUN_0099d830(float s, const float* v)
{
    Vec4_9d830 t;
    t.x = s * v[0];
    t.y = s * v[1];
    t.z = s * v[2];
    t.w = s * v[3];
    float x = unkCC;
    unkD0 = unkD0 + x * t.x;
    unkD4 = unkD4 + x * t.y;
    unkD8 = unkD8 + x * t.z;
    unkDC = unkDC + x * t.w;
}
}   // namespace f3m_0099d830

// @f3 0x0099d8c0 (community match, verified in this file)
namespace f3m_0099d8c0 {
namespace c_0099d8c0 {
__declspec(align(16)) struct Vec { float x,y,z,w; };
struct Owner {
    virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9(); virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18();
    virtual void Apply(Vec*, void*);
    void FUN_0099d8c0(float, Vec*, void*);
};
void Owner::FUN_0099d8c0(float scale, Vec* in, void* q) { Vec out; out.x=in->x*scale; out.y=in->y*scale; out.z=in->z*scale; out.w=in->w*scale; Apply(&out, q); }
}
}   // namespace f3m_0099d8c0

// @f3 0x0099d910 (community match, verified in this file)
namespace f3m_0099d910 {
namespace f3m_0099d910 {
struct __declspec(align(16)) Vec4 { float x, y, z, w;
  Vec4() {}
  Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
  Vec4 operator*(float s) const { return Vec4(x * s, y * s, z * s, w * s); }
};
struct Obj {
  virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
  virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
  virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
  virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
  virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
  virtual void v50(const Vec4& v);
  void FUN_0099d910(float s, const Vec4& v);
};
void Obj::FUN_0099d910(float s, const Vec4& v) { v50(v * s); }
}
}   // namespace f3m_0099d910

// @f3 0x0099dca0 (community match, verified in this file)
namespace f3m_0099dca0 {
namespace VectorTemplate0099dca0 { struct V { float x,y,z,w; }; struct C { unsigned unk00;unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;unsigned unk14;unsigned unk18;unsigned unk1c;unsigned unk20;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;unsigned unk80;unsigned unk84;unsigned unk88;unsigned unk8c;unsigned unk90;unsigned unk94;unsigned unk98;unsigned unk9c;unsigned unka0;unsigned unka4;unsigned unka8;unsigned unkac;unsigned unkb0;unsigned unkb4;unsigned unkb8;unsigned unkbc;unsigned unkc0;unsigned unkc4;unsigned unkc8; float factor; V output; void FUN_0099dca0(float,const V*); };
// pdb: hkpBoxMotion::applyPointImpulse | hkpBoxMotion.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpBoxMotion::applyAngularImpulse)
// pdb params: imp, p
void C::FUN_0099dca0(float s,const V* v) { __declspec(align(16)) V t; t.x=v->x*s; t.y=v->y*s; t.z=v->z*s; t.w=v->w*s; float f=factor; output.x += f*t.x; output.y += f*t.y; output.z += f*t.z; output.w += f*t.w; } }
}   // namespace f3m_0099dca0

// @f3 0x0099dd30 (community match, verified in this file)
namespace f3m_0099dd30 {
struct __declspec(align(16)) Vdd30
{
    float x, y, z, w;
    __forceinline void setMul4(float rs, const Vdd30& a)
    {
        float r = float(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
};
class Cdd30
{
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(const Vdd30& v, void* p);
    void FUN_0099dd30(float s, const Vdd30& v, void* p);
};
// pdb: hkpBoxMotion::applyAngularImpulse | hkpBoxMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: imp
void Cdd30::FUN_0099dd30(float s, const Vdd30& v, void* p)
{
    Vdd30 t;
    t.setMul4(s, v);
    v19(t, p);
}
}   // namespace f3m_0099dd30

// @f3 0x0099dd80 (community match, verified in this file)
namespace f3m_0099dd80 {
namespace task99dd80 {
__declspec(align(16)) struct Vec { float x,y,z,w; };
struct Owner { virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9(); virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19(); virtual void Apply(Vec*); void FUN_0099dd80(float,Vec*); };
void Owner::FUN_0099dd80(float scale,Vec* in) { Vec out; out.x=in->x*scale; out.y=in->y*scale; out.z=in->z*scale; out.w=in->w*scale; Apply(&out); }
}
}   // namespace f3m_0099dd80

// @f3 0x0099e210 (community match, verified in this file)
namespace f3m_0099e210 {
namespace c_0099e210 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 {
    Vec4 col0, col1, col2;
    void SetZero() { Vec4 z; z.SetZero4(); col0 = z; col1 = z; col2 = z; }
    float& operator()(int r, int c) { return (&(&col0)[c].x)[r]; }
    void SetDiagonal(float v) { SetZero(); (*this)(0, 0) = v; (*this)(1, 1) = v; (*this)(2, 2) = v; }
};
struct Motion {
    int unk00[0x30];
    float mC0;
    void FUN_0099e210(Matrix3* out);
};
void Motion::FUN_0099e210(Matrix3* out)
{
    float v = 1.0f / mC0;
    out->SetDiagonal(v);
}
}
}   // namespace f3m_0099e210

// @f3 0x0099e3c0 (community match, verified in this file)
namespace f3m_0099e3c0 {
namespace c_0099e3c0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 {
    Vec4 col0, col1, col2;
    void SetZero() { Vec4 z; z.SetZero4(); col0 = z; col1 = z; col2 = z; }
    float& operator()(int r, int c) { return (&(&col0)[c].x)[r]; }
    void SetDiagonal(float v) { SetZero(); (*this)(0, 0) = v; (*this)(1, 1) = v; (*this)(2, 2) = v; }
};
struct Motion {
    int unk00[0x30];
    float mC0;
    void FUN_0099e3c0(Matrix3* out);
};
void Motion::FUN_0099e3c0(Matrix3* out)
{
    float v = mC0;
    out->SetDiagonal(v);
}
}
}   // namespace f3m_0099e3c0

// @f3 0x0099e410 (community match, verified in this file)
namespace f3m_0099e410 {
namespace f3m_0099e410
{
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void setSub4(const Vec4& a, const Vec4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline void addMul4(float rs, const Vec4& a)
    {
        float r = float(rs);
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    __forceinline void addMul4(const Vec4& a, const Vec4& b)
    {
        x += a.x * b.x; y += a.y * b.y; z += a.z * b.z; w += a.w * b.w;
    }
};
struct Body
{
    char pad[0x60];
    Vec4 m_com;
    char pad2[0xc0 - 0x70];
    Vec4 m_invInertia;
    Vec4 m_linVel;
    Vec4 m_angVel;
    void FUN_0099e410(const Vec4& imp, const Vec4& pos);
};
}

void f3m_0099e410::Body::FUN_0099e410(const Vec4& imp, const Vec4& pos)
{
    float invMass = m_invInertia.w;
    m_linVel.addMul4(invMass, imp);
    Vec4 rel;
    rel.setSub4(pos, m_com);
    Vec4 c;
    c.setCross(rel, imp);
    m_angVel.addMul4(m_invInertia, c);
}
}   // namespace f3m_0099e410

// @f3 0x0099e5a0 (community match, verified in this file)
namespace f3m_0099e5a0 {
namespace VectorTemplate0099e5a0 { struct V { float x,y,z,w; }; struct C { unsigned unk00;unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;unsigned unk14;unsigned unk18;unsigned unk1c;unsigned unk20;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;unsigned unk80;unsigned unk84;unsigned unk88;unsigned unk8c;unsigned unk90;unsigned unk94;unsigned unk98;unsigned unk9c;unsigned unka0;unsigned unka4;unsigned unka8;unsigned unkac;unsigned unkb0;unsigned unkb4;unsigned unkb8;unsigned unkbc;unsigned unkc0;unsigned unkc4;unsigned unkc8; float factor; V output; void FUN_0099e5a0(float,const V*); };
void C::FUN_0099e5a0(float s,const V* v) { __declspec(align(16)) V t; t.x=v->x*s; t.y=v->y*s; t.z=v->z*s; t.w=v->w*s; float f=factor; output.x += f*t.x; output.y += f*t.y; output.z += f*t.z; output.w += f*t.w; } }
}   // namespace f3m_0099e5a0

// @f3 0x0099e630 (community match, verified in this file)
namespace f3m_0099e630 {
namespace f3m_0099e630 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;

    void SetMul(float s, const Vec4& v) {
        x = s * v.x;
        y = s * v.y;
        z = s * v.z;
        w = s * v.w;
    }
};

struct Body {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48();
    virtual void Apply(const Vec4& v, int arg);

    void FUN_0099e630(float s, const Vec4& v, int arg);
};

void Body::FUN_0099e630(float s, const Vec4& v, int arg) {
    Vec4 t;
    t.SetMul(s, v);
    Apply(t, arg);
}

}
}   // namespace f3m_0099e630

// @f3 0x0099e680 (community match, verified in this file)
namespace f3m_0099e680 {
namespace task99e680 {
__declspec(align(16)) struct Vec { float x,y,z,w; };
struct Owner { virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9(); virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19(); virtual void Apply(Vec*); void FUN_0099e680(float,Vec*); };
void Owner::FUN_0099e680(float scale,Vec* in) { Vec out; out.x=in->x*scale; out.y=in->y*scale; out.z=in->z*scale; out.w=in->w*scale; Apply(&out); }
}
}   // namespace f3m_0099e680

// @f3 0x0099f4c0 (community match, verified in this file)
namespace f3m_0099f4c0 {
struct __declspec(align(16)) F3Vector4 { float x,y,z,w; };
class hkpShapeCollection_L {
public:
    virtual ~hkpShapeCollection_L();
    virtual int FUN_00d213d0();
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwIndex);

extern "C" unsigned int DAT_0116913c;
extern "C" char DAT_00e7de28[];
extern "C" char DAT_00e32798[];

class Arg0_L;
class Arg1_L;
class Arg2_L;
class ShapeBuf_L;
struct Ctx_L;
class Owner_L;

struct ProfRec_L
{
    void* id;
    unsigned int time;
    int unk08;
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov ticks, eax } time = ticks; }
};
struct ProfSlot_L
{
    int unk00;
    ProfRec_L* head;
    int unk08;
    ProfRec_L* end;
};

class Shape_L
{
  public:
    virtual ~Shape_L();
    virtual int s01();
    virtual int s02();
    virtual int s03();
    virtual void process_L(Arg0_L* arg0, Ctx_L* ctx, Arg2_L* arg2);
};

class Coll_L2 : public hkpShapeCollection_L
{
  public:
    virtual int getFirstKey_L();
    virtual int getNextKey_L(int key);
    virtual int s04();
    virtual Shape_L* getChildShape_L(int key, ShapeBuf_L& buffer);
};

class Filter_L
{
  public:
    virtual bool* isEnabled_L(bool* out, Arg0_L* arg0, Owner_L* self, Coll_L2* coll, int key);
};

class Arg0_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    Filter_L* m_iFilter;
};

class Arg1_L
{
  public:
    void* unk00;
    void* unk04;
    int unk08;
};
class Arg2_L
{
  public:
    int dummy;
};

struct Ctx_L
{
    Shape_L* shape;
    int key;
    int unk08;
    Arg1_L* arg1;
};

struct __declspec(align(16)) ShapeBuf_L
{
    F3Vector4 v00, v01, v02, v03, v04, v05, v06, v07;
    F3Vector4 v08, v09, v10, v11, v12, v13, v14, v15;
    F3Vector4 v16, v17, v18, v19, v20, v21, v22, v23;
    F3Vector4 v24, v25, v26, v27, v28, v29, v30, v31;
};

class Owner_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Coll_L2 m_coll;
    void hkpShapeCollection_castRayWithCollectorImpl(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2);
};

// @fnv 0x00d217d0
// pdb: hkpShapeCollection::castRayWithCollectorImpl | hkpShapeCollection.obj | fnv360_0822_retail, objrun_prop + skyrim(objrun_prop), high
void Owner_L::hkpShapeCollection_castRayWithCollectorImpl(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2)
{
    ProfSlot_L* pProfSlot = (ProfSlot_L*)TlsGetValue(DAT_0116913c);
    ProfRec_L* pProfRec = pProfSlot->head;
    if (pProfRec < pProfSlot->end)
    {
        pProfRec->id = &DAT_00e7de28;
        pProfRec->setTime();
        pProfSlot->head = pProfRec + 1;
    }
    ShapeBuf_L buffer;
    Ctx_L ctx;
    int key;
    if (arg0->m_iFilter == 0)
    {
        key = this->m_coll.getFirstKey_L();
        if (key != -1)
        {
            do
            {
                ctx.shape = this->m_coll.getChildShape_L(key, buffer);
                ctx.arg1 = arg1;
                ctx.unk08 = arg1->unk08;
                ctx.key = key;
                ctx.shape->process_L(arg0, &ctx, arg2);
                key = this->m_coll.getNextKey_L(key);
            } while (key != -1);
        }
    }
    else
    {
        key = this->m_coll.getFirstKey_L();
        if (key != -1)
        {
            do
            {
                bool enabled;
                if (*arg0->m_iFilter->isEnabled_L(&enabled, arg0, this, &this->m_coll, key))
                {
                    ctx.shape = this->m_coll.getChildShape_L(key, buffer);
                    ctx.arg1 = arg1;
                    ctx.unk08 = arg1->unk08;
                    ctx.key = key;
                    ctx.shape->process_L(arg0, &ctx, arg2);
                }
                key = this->m_coll.getNextKey_L(key);
            } while (key != -1);
        }
    }
    pProfSlot = (ProfSlot_L*)TlsGetValue(DAT_0116913c);
    pProfRec = pProfSlot->head;
    if (pProfRec < pProfSlot->end)
    {
        pProfRec->id = &DAT_00e32798;
        pProfRec->setTime();
        pProfSlot->head = pProfRec + 1;
    }
}
}   // namespace f3m_0099f4c0

// @f3 0x009830d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009830d0 {
namespace f3m_009830d0 {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct Ref9830 {
 void* unk00;
 unsigned short unk04,unk06;
 void AddRef() { if(unk04) ++unk06; }
};
struct Ref6:Ref9830 {};
struct Ref7:Ref9830 {};
struct Ref15:Ref9830 {};
struct Ref16:Ref9830 {};
struct Ref22:Ref9830 {};
struct Ref30 { void FUN_00983050(); };
struct Blob9830 {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 __forceinline Blob9830(const Blob9830& b) {
unk00=b.unk00;
unk04=b.unk04;
unk08=b.unk08;
unk0c=b.unk0c;
unk10=b.unk10;
unk14=b.unk14;
unk18=b.unk18;
unk1c=b.unk1c;
 }
 static void* operator new(unsigned int);
 static void operator delete(void*);
};
static inline void memCpy4(void* dst, const void* src, int numWords)
{
    const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
    unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
    for (int i = 0; i < numWords; i++)
    {
        *(dst32++) = *(src32++);
    }
}
struct Record9830 {
 unsigned char type;
 union { Ref9830* object; Ref6** list6; Ref7** list7; Ref15** list15; Ref16** list16; Ref22** list22; Ref30* nested; };
 union { unsigned int count; Ref9830* other; Blob9830* blob; };
 unsigned int unk0c,unk10;
};
struct Lock9830 {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 void FUN_00908a00();
 void Leave() { unk18=-1; unk1c=-1; LeaveCriticalSection(this); }
};
struct Guard9830 {
 Lock9830* lock;
 Guard9830(Lock9830& l):lock(&l) { l.FUN_00908a00(); }
 ~Guard9830() { lock->Leave(); }
};
struct Array9830;
extern "C" void __cdecl FUN_00901f10(Array9830*,int);
extern "C" void __cdecl FUN_009234e0(void*,const void*,unsigned int);
struct Array9830 {
 Record9830* data; int count; unsigned capacity;
 void Grow() { if(count==(capacity & 0x3fffffff)) FUN_00901f10(this,20); }
 __forceinline void Add(const Record9830& src) { Grow(); data[count]=src; ++count; }
};
struct Counter9830 {
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
};
struct Pool9830 {
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
 void* head; int count;
 void* FUN_008f6d30(int,int);
 void* FUN_008f6800(int,int);
 __forceinline void* AllocBlob() {
  void* p=head;
  if(p) { --count; head=*(void**)p; }
  else p=FUN_008f6800(3,0x27);
  return p;
 }
};
inline Pool9830* GetPool9830() { return (Pool9830*)FUN_00d9b080(DAT_010f3170); }
__forceinline void* Blob9830::operator new(unsigned int) { return GetPool9830()->AllocBlob(); }
struct Queue9830 {
 Array9830 main; Counter9830* counter;
 Array9830 secondary; int unk1c;
 Lock9830 lock;
 void FUN_009830d0(const Record9830&);
};
// pdb: hkpWorldOperationQueue::queueOperation | hkpWorldOperationQueue.obj | tesv_win, call_seq, medium
void Queue9830::FUN_009830d0(const Record9830& src) {
 Lock9830* guard=&lock;
 guard->FUN_00908a00();
 main.Grow();
 Record9830& dst=main.data[main.count++];
 ++counter->unk80;
 memCpy4(&dst,&src,sizeof(Record9830)/4);
 switch(dst.type) {
 case 5:
  dst.object->AddRef(); dst.other->AddRef(); break;
 case 6: {
  int n=(unsigned short)dst.count;
  dst.list6=(Ref6**)GetPool9830()->FUN_008f6d30(n*4,4);
  FUN_009234e0(dst.list6,src.list6,(unsigned short)src.count*4);
  Ref6** end=dst.list6+(unsigned short)dst.count;
  for(Ref6** p=dst.list6;p<end;++p) (*p)->AddRef();
  break;
 }
 case 7: {
  int n=(unsigned short)dst.count;
  dst.list7=(Ref7**)GetPool9830()->FUN_008f6d30(n*4,4);
  FUN_009234e0(dst.list7,src.list7,(unsigned short)src.count*4);
  Ref7** end=dst.list7+(unsigned short)dst.count;
  for(Ref7** p=dst.list7;p<end;++p) (*p)->AddRef();
  break;
 }
 case 12:
  dst.object->AddRef(); dst.other->AddRef();
  secondary.Add(dst); --main.count; break;
 case 15: {
  int n=(unsigned short)dst.count;
  dst.list15=(Ref15**)GetPool9830()->FUN_008f6d30(n*4,4);
  FUN_009234e0(dst.list15,src.list15,(unsigned short)src.count*4);
  Ref15** end=dst.list15+(unsigned short)dst.count;
  for(Ref15** p=dst.list15;p<end;++p) (*p)->AddRef();
  break;
 }
 case 16: {
  int n=(unsigned short)dst.count;
  dst.list16=(Ref16**)GetPool9830()->FUN_008f6d30(n*4,4);
  FUN_009234e0(dst.list16,src.list16,(unsigned short)src.count*4);
  Ref16** end=dst.list16+(unsigned short)dst.count;
  for(Ref16** p=dst.list16;p<end;++p) (*p)->AddRef();
  break;
 }
 case 17: {
  dst.object->AddRef();
  dst.blob=new Blob9830(*src.blob);
  break;
 }
 case 22: {
  int n=(unsigned short)dst.count;
  dst.list22=(Ref22**)GetPool9830()->FUN_008f6d30(n*4,4);
  FUN_009234e0(dst.list22,src.list22,(unsigned short)src.count*4);
  Ref22** end=dst.list22+(unsigned short)dst.count;
  for(Ref22** p=dst.list22;p<end;++p) (*p)->AddRef();
  break;
 }
 case 29:
  dst.object->AddRef(); --main.count; --counter->unk80; break;
 case 30:
  dst.nested->FUN_00983050(); --main.count; --counter->unk80; break;
 case 1: dst.object->AddRef(); break;
 case 2: dst.object->AddRef(); break;
 case 3: dst.object->AddRef(); break;
 case 4: dst.object->AddRef(); break;
 case 8: dst.object->AddRef(); break;
 case 9: dst.object->AddRef(); break;
 case 10: dst.object->AddRef(); break;
 case 11: dst.object->AddRef(); break;
 case 13: dst.object->AddRef(); break;
 case 14: dst.object->AddRef(); break;
 case 18: dst.object->AddRef(); break;
 case 19: dst.object->AddRef(); break;
 case 21: dst.object->AddRef(); break;
 case 23: dst.object->AddRef(); break;
 case 24: dst.object->AddRef(); break;
 case 25: dst.object->AddRef(); break;
 case 26: dst.object->AddRef(); break;
 case 27: dst.object->AddRef(); break;
 case 28: dst.object->AddRef(); break;
 case 32: dst.object->AddRef(); break;
 case 33: dst.object->AddRef(); break;
 case 34: dst.object->AddRef(); break;
 }
 guard->Leave();
}
}
}   // namespace f3m_009830d0

// @f3 0x00998520 (community match, verified in this file)
namespace f3m_00998520 {
// 0x00998520 — target is a single `ret` (C3, 1 byte).
// pdb: hkAgentNnMachine_TouchAgent | hkpAgentNnMachine.obj | fnv360_0822_retail, objrun_open, low
// pdb params: entry, input
void FUN_00998520() {}
}   // namespace f3m_00998520

// @f3 0x0098b5d0 (community match, verified in this file)
namespace f3m_0098b5d0 {
// w494 — 0x0098b5d0, 3 bytes: C2 04 00 = ret 4 (stdcall, callee pops one 4-byte argument).
// Empty __stdcall body with one parameter compiles to exactly `ret 4`.
// pdb: hkMultiThreadCheck::accessCheck | hkMultiThreadCheck.obj | fnv360_0822_retail, objrun_open, low
// pdb params: type
void __stdcall FUN_0098b5d0(void* p)
{
    (void)p;
}
}   // namespace f3m_0098b5d0

// @f3 0x009843e0 (community match, verified in this file)
    extern const char str_00e7d4bc[];
namespace f3m_009843e0 {
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct WStream { int unk00; char* end; int unk08; char* capacityEnd; };

static __forceinline void WTimerMark(const char* name)
{
    WStream* s = (WStream*)TlsGetValue(DAT_0116913c);
    char* p = s->end;
    if (p < s->capacityEnd) {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        ((unsigned int*)p)[1] = t;
        s->end = p + 0xc;
    }
}

struct __declspec(align(16)) WVec4 { float x, y, z, w; };
struct WInput { WVec4 pos; int unk10[4]; bool flag; };
struct WLinked { int unk00[4]; int unk10; int unk14; };
struct WQueryInput { WVec4 pos; int count; const void* data; int stride; void* user; };
struct WQuery;

struct WWorld {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void Run(WQueryInput* in, WQuery* collector, int flags);
};

struct WQuery {
    virtual void v00();
    const WInput* input;
    void* linked14;
    void* user;
    int unk10[9];
    void* linked10;
    void FUN_009843e0(WWorld* world, const WInput* in, WLinked* linked, void* e);
};

// pdb: hkpSimpleWorldRayCaster::castRay | hkpSimpleWorldRayCaster.obj | fnv360_0822_retail, ustr, high
// pdb params: broadphase, input, filter, output
void WQuery::FUN_009843e0(WWorld* world, const WInput* in, WLinked* linked, void* e)
{
    WTimerMark(str_00e7d4bc);
    input = in;
    this->user = e;
    linked14 = linked ? &linked->unk14 : 0;
    if (in->flag)
        linked10 = linked ? &linked->unk10 : 0;
    else
        linked10 = 0;
    WQueryInput qi;
    qi.pos.x = in->pos.x;
    qi.pos.y = in->pos.y;
    qi.pos.z = in->pos.z;
    qi.pos.w = in->pos.w;
    qi.count = 1;
    qi.data = in->unk10;
    qi.stride = 0x10;
    qi.user = 0;
    world->Run(&qi, this, 0);
    WTimerMark(str_00e32798);
}
}   // namespace f3m_009843e0

// @f3 0x00990c60 (community match, verified in this file)
namespace f3m_00990c60 {
namespace f3m_00990c60
{
    typedef unsigned short Uint16;
    typedef unsigned int Uint32;

    struct BroadPhaseHandle;

    struct BpNode
    {
        Uint16 min_y;
        Uint16 min_z;
        Uint16 max_y;
        Uint16 max_z;
        Uint16 min_x;
        Uint16 max_x;
        BroadPhaseHandle* handle;
    };
}

// pdb: hkp3AxisSweep::updateNodesAfterDelete | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
extern "C" void __stdcall FUN_00990c60(f3m_00990c60::BpNode* nodes, int numNodes, f3m_00990c60::BpNode& oldNode)
{
    using namespace f3m_00990c60;

    __declspec(align(16)) const Uint32 protectPointerMask[4] = { 0xffffffff, 0xffffffff, 0xffffffff, 0 };

    BpNode miNode;
    BpNode maNode;
    miNode.min_x = oldNode.min_x;
    miNode.max_x = oldNode.min_x;
    miNode.min_y = oldNode.min_y;
    miNode.max_y = oldNode.min_y;
    miNode.min_z = oldNode.min_z;
    miNode.max_z = oldNode.min_z;
    maNode.min_x = oldNode.max_x;
    maNode.max_x = oldNode.max_x;
    maNode.min_y = oldNode.max_y;
    maNode.max_y = oldNode.max_y;
    maNode.min_z = oldNode.max_z;
    maNode.max_z = oldNode.max_z;

    BpNode* end = nodes + numNodes;
    for (BpNode* n = nodes; n != end; n++)
    {
        n->min_x = n->min_x - ((Uint32(miNode.min_x) - n->min_x) >> 31) - ((Uint32(maNode.min_x) - n->min_x) >> 31);
        n->max_x = n->max_x - ((Uint32(miNode.max_x) - n->max_x) >> 31) - ((Uint32(maNode.max_x) - n->max_x) >> 31);
        n->min_y = n->min_y - ((Uint32(miNode.min_y) - n->min_y) >> 31) - ((Uint32(maNode.min_y) - n->min_y) >> 31);
        n->max_y = n->max_y - ((Uint32(miNode.max_y) - n->max_y) >> 31) - ((Uint32(maNode.max_y) - n->max_y) >> 31);
        n->min_z = n->min_z - ((Uint32(miNode.min_z) - n->min_z) >> 31) - ((Uint32(maNode.min_z) - n->min_z) >> 31);
        n->max_z = n->max_z - ((Uint32(miNode.max_z) - n->max_z) >> 31) - ((Uint32(maNode.max_z) - n->max_z) >> 31);
    }
}
}   // namespace f3m_00990c60

// @f3 0x0098b790 (community match, verified in this file)
namespace f3m_0098b790 {
extern int DAT_01169318;
namespace n98b790 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
struct Lock {
    int cs[6];
    int owner;
    int depth;
    void FUN_00908a00();
};
struct ScopedLock {
    Lock* lock;
    ScopedLock(Lock* l) : lock(l) { l->FUN_00908a00(); }
    ~ScopedLock() { lock->owner = -1; lock->depth = -1; LeaveCriticalSection(lock); }
};
}
struct S0098b790_t {
    int id;
    short count;
    unsigned short bits;
    void FUN_0098b790();
};
// pdb: hkMultiThreadCheck::staticQuit | hkMultiThreadCheck.obj | fnv360_0822_retail, objrun_open, low
void S0098b790_t::FUN_0098b790() {
    if (id == -0x2f) return;
    n98b790::ScopedLock guard(*(n98b790::Lock**)&DAT_01169318);
    bits >>= 1;
    if (--count == 0) id = -0xf;
}
}

// @f3 0x00983010 (community match, verified in this file)
namespace f3m_00983010 {
extern int DAT_010f3170;
namespace n983010 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct hkThreadMemory { void FUN_008f6d90(void* p, int nbytes, int cls); };
class hkReferencedObject {
public:
    virtual ~hkReferencedObject();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};
}
class hkpMultiThreadedSimulation : public n983010::hkReferencedObject {
public:
    void FUN_009824b0();
    hkpMultiThreadedSimulation* FUN_00983010(unsigned int flags);
};
// pdb: hkpMultiThreadedSimulation::`scalar deleting destructor' | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable, high
hkpMultiThreadedSimulation* hkpMultiThreadedSimulation::FUN_00983010(unsigned int flags) {
    FUN_009824b0();
    if (flags & 1) {
        n983010::hkThreadMemory* mem = (n983010::hkThreadMemory*)n983010::TlsGetValue(*(unsigned long*)&DAT_010f3170);
        mem->FUN_008f6d90(this, m_memSizeAndFlags, 0x15);
    }
    return this;
}
}

// @f3 0x009984f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009984f0 {
namespace f3m_009984f0 {

extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct hkThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls);
};

class hkReferencedObject
{
    public:
        virtual ~hkReferencedObject();

        unsigned short m_memSizeAndFlags;
        short m_referenceCount;
};

class hkp3AxisSweep : public hkReferencedObject
{
    public:
        void FUN_00997010();
        hkp3AxisSweep* FUN_009984f0(unsigned int flags);
};

// pdb: hkp3AxisSweep::`scalar deleting destructor' | hkp3AxisSweep.obj | fnv360_0822_retail, vtable_prefix, high
hkp3AxisSweep* hkp3AxisSweep::FUN_009984f0(unsigned int flags)
{
    FUN_00997010();
    if (flags & 1)
    {
        hkThreadMemory* mem = (hkThreadMemory*)DAT_00d9b080(DAT_010f3170);
        mem->FUN_008f6d90(this, m_memSizeAndFlags, 0x21);
    }
    return this;
}

}
}   // namespace f3m_009984f0

// @f3 0x00983040 (community match, verified in this file)
namespace f3m_00983040 {
namespace f3m_00983040 {
namespace n983040 {
struct hkReferencedObject
{
    void* m_vfptr;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};
}
// 0x00983040: addReference for a Havok object; file-local helper (object in eax)
static __declspec(noinline) void FUN_00983040(n983040::hkReferencedObject* obj)
{
    if (obj->m_memSizeAndFlags != 0)
        ++obj->m_referenceCount;
}
volatile int g_00983040_obj;
void Caller00983040()
{
    FUN_00983040((n983040::hkReferencedObject*)g_00983040_obj);
}
}
}   // namespace f3m_00983040

// @f3 0x0098b5a0 (community match, verified in this file)
namespace n98b5a0 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
}
struct C98b5a0 {
    void* vtbl;
    unsigned short memSize;
    short refCount;
    void FUN_0098b190();
    C98b5a0* FUN_0098b5a0(unsigned int flags);
};
// pdb: hkpSimulationIsland::`scalar deleting destructor' | hkpSimulationIsland.obj | fnv360_0822_retail, vtable, high
C98b5a0* C98b5a0::FUN_0098b5a0(unsigned int flags)
{
    FUN_0098b190();
    if (flags & 1) {
        n98b5a0::Alloc* a = n98b5a0::FUN_00d9b080(n98b5a0::DAT_010f3170);
        a->FUN_008f6d90(this, memSize, 0x32);
    }
    return this;
}

// @f3 0x0099a2d0 (community match, verified in this file)
// 0x0099a2d0: hkEntityAabbUtil::entityBatchRecalcAabb(const hkpCollisionInput* collisionInput,
// hkpEntity*const* entityBatch, int numEntities) of Havok 5.5.0 (hkpDynamics, hkpEntityAabbUtil.cpp lines 33-198,
// compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). For every entity of the batch it recomputes the collidable's
// 32-bit bounding box and its swept (expanded) box: for a shape with child boxes one pair per enabled child plus
// the root pair and a sort index per child, else one pair from the shape itself.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers,
// and the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by a reducer, then single lines, every cut checked byte for byte against the uncut compile); those
// declarations are the SDK's text with its names.
// The body's statements follow the library's records (the hybrid object's line table and named locals); with
// the SDK's own convertAabbToUint32 this source compiles to the SDK's release object exactly (11,382 bytes).
// The game's build (11,798 bytes) differs from the SDK's in one inlined function, and so does this file:
// hkVector4Util::convertAabbToUint32 (six instances here)
// (1) copies hkAabbUint32MaxVal into a local vector before the two clips, as an assignment of the vector's
//     hkQuadReal (the frame grows from 0x734 to 0x7e4 bytes, as in the original);
// (2) passes the zero vector to the clips as the constant hkQuadReal0000 itself, not through
//     hkVector4::getZero(), whose body in the SDK's header holds a local reference.
// Neither changes an instruction of the conversions; both change the order in which the compiler loads the two
// operands of single x87 lanes, here and in the inlined sweepOffsetAabb, and only with both is every lane the
// original's.
// hkVector4Util::convertToUint32WithClip calls the pack's fnv_FloatToInt where the SDK's text calls
// hkMath::hkToIntFast: that function's body in the SDK's header is two instructions of inline assembly (fld,
// fistp), the same two as the pack's helper. The helper is called at the same inline depth, because the
// compiler's symbol numbering, which the x87 operand order follows, counts every inline level (through
// hkToIntFast as a wrapper the function comes out 16 bytes longer).
// Only entityBatchRecalcAabb is renamed, to the packet's name.
namespace f3m_0099a2d0 {

typedef float  hkReal;
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
		inline hkBool& operator=(bool e)
		{
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
		hkInt32 f = *(int*)&fv;
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
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
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
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
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
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
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		void removeReference();
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
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
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
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
	public:
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
}
extern const hkQuadReal hkQuadReal0000;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
class hkQsTransform
{
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline hkQuadReal& hkVector4::getQuad()
{
	return reinterpret_cast<hkQuadReal&>(x);
}
inline const hkQuadReal& hkVector4::getQuad() const
{
	return reinterpret_cast<const hkQuadReal&>(x);
}
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setAll3(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
	}
inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = 0;
	}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkVector4& hkTransform::getTranslation() const
{
	return m_translation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
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
enum hkpShapeType
{
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
class hkpCdVertex;
class hkAabb;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpShape( hkpShapeType type );
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			static void __cdecl resetShapeFunctions();
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		enum { OFFSET_INVALID = 127 };
		inline void setType( int type );
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
struct hkAabbUint32;
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline hkpCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpCollidable();
		inline const hkpShape* getShape() const;
		inline void setShape(const hkpShape* shape);
		inline void setOwner( void* owner );
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
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
__forceinline const hkpShape* hkpCollidable::getShape() const
{
	return m_shape;
}
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
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
			;
		}
		__forceinline void unmarkForWrite()
		{
			;
		}
		void disableChecks();
		void enableChecks();
		bool isCheckingEnabled() const;
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
	inline hkpPropertyValue( const int i );
	inline hkpPropertyValue( const hkReal f );
	inline hkpPropertyValue( void* p );
	inline hkpPropertyValue( ) { }
	inline void setReal(const hkReal r);
	inline void setInt(const int i);
	inline void setPtr(void* p);
	inline hkReal getReal() const;
	inline int getInt() const;
	inline void* getPtr() const;
};
class hkpProperty
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkpProperty();
		inline hkpProperty( hkUint32 key, hkInt32 value );
		inline hkpProperty( hkUint32 key, hkpPropertyValue value );
	public:
		hkUint32 m_key;
		hkUint32 m_alignmentPadding;
		struct hkpPropertyValue m_value;
	public:
		hkpProperty( class hkFinishLoadedObjectFlag flag ) { }
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
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkpCollidable* getCollidable() const;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline const hkpLinkedCollidable* getLinkedCollidable() const;
		inline const hkpLinkedCollidable* getCollidableMtUnchecked() const;
		inline hkBool isAddedToWorld() const;
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
		inline void markForRead( );
		inline void markForWrite( );
		void markForWriteImpl( );
		void removeReference();
		void addReferenceAsCriticalOperation();
		void removeReferenceAsCriticalOperation();
	public:
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
		friend class hkpWorldOperationUtil;
		inline void setWorld( hkpWorld* world );
		virtual class hkMotionState* getMotionState() = 0;
		hkpWorldObject( const hkpShape* shape, BroadPhaseType type );
		inline virtual ~hkpWorldObject();
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
class hkpMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpMaterial();
		inline hkReal getFriction() const;
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
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
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
const hkTransform& hkMotionState::getTransform() const
{
	return m_transform;
}
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
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
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline const hkVector4& getCenterOfMassLocal() const;
	inline const hkVector4& getCenterOfMassInWorld() const;
	inline hkMotionState* getMotionState();
	inline const hkMotionState* getMotionState() const;
	inline const hkVector4& getPosition() const;
	virtual void setPosition(const hkVector4& position);
	inline const hkQuaternion& getRotation() const;
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	void approxTransformAt( hkTime time, hkTransform& transformOut );
	virtual void setTransform(const hkTransform& transform);
	inline const hkVector4& getLinearVelocity() const;
	virtual void setLinearVelocity(const hkVector4& newVel);
	inline const hkVector4& getAngularVelocity() const;
	virtual void setAngularVelocity(const hkVector4& newVel);
	__forceinline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
	inline hkReal getLinearDamping();
	inline void setLinearDamping( hkReal d );
	inline hkReal getAngularDamping();
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
	inline int getNumInactiveFrames(int select);
	inline int getNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void setWorldSelectFlagsNeg(int worldFlag0, int worldFlag1, int worldDeactivationIntegrateCounter);
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
hkMotionState* hkpMotion::getMotionState()
{
	return &m_motionState;
}
const hkVector4& hkpMotion::getCenterOfMassInWorld() const
{
	return m_motionState.getSweptTransform().m_centerOfMass1;
}
const hkTransform& hkpMotion::getTransform() const
{
	return m_motionState.getTransform();
}
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
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
	protected:
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
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
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
		void addEntityListener( hkpEntityListener* el);
		void removeEntityListener( hkpEntityListener* el);
		void addEntityActivationListener( hkpEntityActivationListener* el);
		void calcStatistics( hkStatisticsCollector* collector) const;
		hkpEntity( const hkpShape* shape );
	public:
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
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
inline hkpMotion* hkpEntity::getMotion()
{
	return &m_motion;
}
class hkAabb
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
struct hkAabbUint32
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline void operator=( const hkAabbUint32& other );
	inline void setInvalid();
	inline void setInvalidY();
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};
inline void hkAabbUint32::setInvalid()
{
	const int ma = 0x7fffffff;
	hkUint32* minP = m_min;
	hkUint32* maxP = m_max;
	minP[0] = ma;
	minP[1] = ma;
	minP[2] = ma;
	minP[3] = 0;
	maxP[0] = 0;
	maxP[1] = 0;
	maxP[2] = 0;
	maxP[3] = 0;
}
template <typename T>
class hkFixedArray
{
	public:
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T* begin();
		__forceinline const T* begin() const;
	protected:
		__forceinline	hkFixedArray(){}
		hkPadSpu<T*> m_data;
		int m_debugSize;
};
template <typename T>
class hkLocalBuffer: public hkFixedArray<T>
{
	public:
		__forceinline hkLocalBuffer(int n, const char* what = 0 );
		__forceinline ~hkLocalBuffer();
};
template <typename T>
__forceinline hkLocalBuffer<T>::hkLocalBuffer( int capacity, const char* what )
{
	this->m_data = hkAllocateStack<T>(capacity);
	;
}
template <typename T>
__forceinline hkLocalBuffer<T>::~hkLocalBuffer()
{
	hkDeallocateStack( this->m_data.val() );
}
template <typename T>
T* hkFixedArray<T>::begin()
{
	return m_data;
}
struct hkpCollisionInput;
class hkValueIndexPair
{
public:
	hkUint32 m_value;
	hkUint32 m_index;
	__forceinline bool operator< (const hkValueIndexPair& p1) const { return (m_value < p1.m_value); }
};
class hkEntityAabbUtil
{
	public:
		static void __cdecl FUN_0099a2d0(const hkpCollisionInput* collisionInput, hkpEntity*const* entityBatch, int numEntities);
		static void __cdecl entityBatchInvalidateAabb(hkpEntity*const* entityBatch, int numEntities);
};
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const = 0;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const = 0;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const = 0;
		virtual hkBool32 isChildEnabled( hkpShapeKey key ) const { return true; }
		virtual bool isWeldingEnabled() const { return true; }
};
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out);
__forceinline void __cdecl convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
__forceinline void __cdecl compressExpandedAabbUint32(const hkAabbUint32& expandedAabbInt, hkAabbUint32& unexpandedAabbInt_InOut);
extern __declspec(align(16)) float hkAabbUint32MaxVal[4];
}
inline void __cdecl hkVector4Util::convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	out[0] = static_cast<hkUint32>(fnv_FloatToInt(x(0)));
	out[1] = static_cast<hkUint32>(fnv_FloatToInt(x(1)));
	out[2] = static_cast<hkUint32>(fnv_FloatToInt(x(2)));
	out[3] = static_cast<hkUint32>(fnv_FloatToInt(x(3)));
}
inline void __cdecl hkVector4Util::compressExpandedAabbUint32(const hkAabbUint32& expandedAabbInt, hkAabbUint32& unexpandedAabbInt_InOut)
{
	hkInt32 mix = unexpandedAabbInt_InOut.m_min[0] - expandedAabbInt.m_min[0];
	hkInt32 miy = unexpandedAabbInt_InOut.m_min[1] - expandedAabbInt.m_min[1];
	hkInt32 miz = unexpandedAabbInt_InOut.m_min[2] - expandedAabbInt.m_min[2];
	hkInt32 maxx= expandedAabbInt.m_max[0] - unexpandedAabbInt_InOut.m_max[0];
	hkInt32 may = expandedAabbInt.m_max[1] - unexpandedAabbInt_InOut.m_max[1];
	hkInt32 maz = expandedAabbInt.m_max[2] - unexpandedAabbInt_InOut.m_max[2];
	hkInt32 m = (mix | miy) | (miz | maxx) | (may | maz);
	;
	int shift = 0;
	while ( m >=  0x800){ shift += 4; m = unsigned(m) >> 4; };
	while ( m >=  0x100){ shift += 1; m = unsigned(m) >> 1; };
	unexpandedAabbInt_InOut.m_expansionShift = hkUchar(shift);
	unexpandedAabbInt_InOut.m_expansionMin[0] = hkUchar(mix >> shift);
	unexpandedAabbInt_InOut.m_expansionMin[1] = hkUchar(miy >> shift);
	unexpandedAabbInt_InOut.m_expansionMin[2] = hkUchar(miz >> shift);
	unexpandedAabbInt_InOut.m_expansionMax[0] = hkUchar(maxx >> shift);
	unexpandedAabbInt_InOut.m_expansionMax[1] = hkUchar(may >> shift);
	unexpandedAabbInt_InOut.m_expansionMax[2] = hkUchar(maz >> shift);
}
namespace hkAlgorithm
{
template<typename T>
	class less
	{
		public:
			__forceinline hkBool operator() ( const T& a, const T& b )
			{
				return ( a < b );
			}
	};
template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
template<typename T>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize)
	{
		quickSort( pArr, iSize, less<T>() );
	}
template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}
namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}
class hkpAabbUtil
{
	public:
		static void __cdecl calcAabb( const float* vertexArray, int numVertices, int striding, hkAabb& aabbOut );
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, const hkVector4& center, float extraRadius, hkAabb& aabbOut);
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, float extraRadius, hkAabb& aabbOut);
	public:
		struct OffsetAabbInput
		{
			hkPadSpu<const hkMotionState*> m_motionState;
			hkTransform m_transforms[4];
			hkPadSpu<int> m_numTransforms;
			hkTransform m_startTransform;
			hkTransform m_endTransformInv;
		};
		__forceinline static void __cdecl sweepAabb(const hkMotionState* motionstate, hkReal tolerance, const hkAabb& aabbIn, hkAabb& aabbOut);
		static void __cdecl initOffsetAabbInput(const hkMotionState* motionstate, OffsetAabbInput& input);
		static void __cdecl sweepOffsetAabb(const OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut);
};
void hkpAabbUtil::sweepAabb(const hkMotionState* motionState, hkReal tolerance, const hkAabb& aabbIn, hkAabb& aabbOut)
{
	hkReal radius = motionState->m_deltaAngle(3) * motionState->m_objectRadius;
	hkVector4 rotationalGain; rotationalGain.setAll(radius);
	aabbOut.m_min.setSub4(aabbIn.m_min, rotationalGain);
	aabbOut.m_max.setAdd4(aabbIn.m_max, rotationalGain);
	{
		hkVector4 radius4; radius4.setAll3( motionState->m_objectRadius + tolerance );
		hkVector4 maxR; maxR.setAdd4( motionState->getSweptTransform().m_centerOfMass1, radius4 );
		hkVector4 minR; minR.setSub4( motionState->getSweptTransform().m_centerOfMass1, radius4 );
		;
		aabbOut.m_min.setMax4( aabbOut.m_min, minR );
		aabbOut.m_min.setMin4( aabbOut.m_min, aabbIn.m_min );
		aabbOut.m_max.setMin4( aabbOut.m_max, maxR );
		aabbOut.m_max.setMax4( aabbOut.m_max, aabbIn.m_max );
	}
	hkVector4 invPath; invPath.setSub4( motionState->getSweptTransform().m_centerOfMass0, motionState->getSweptTransform().m_centerOfMass1 );
	hkVector4 zero; zero.setZero4();
	hkVector4 minPath; minPath.setMin4( zero, invPath );
	hkVector4 maxPath; maxPath.setMax4( zero, invPath );
	aabbOut.m_min.add4( minPath );
	aabbOut.m_max.add4( maxPath );
}
__forceinline void __cdecl hkpAabbUtil::sweepOffsetAabb(const hkpAabbUtil::OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut)
{
	hkSimdReal half(0.5f);
	hkVector4 aabbHalfSize; aabbHalfSize.setSub4(aabbIn.m_max, aabbIn.m_min);  aabbHalfSize.mul4(half);
	hkVector4 aabbCenter; aabbCenter.setInterpolate4(aabbIn.m_max, aabbIn.m_min, half);
	hkVector4 arm; arm._setTransformedPos(input.m_endTransformInv, aabbCenter);
	hkVector4 min = aabbCenter;
	hkVector4 max = aabbCenter;
	{
		hkVector4 p; p._setTransformedPos(input.m_startTransform, arm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	const hkVector4 centerOfMassLocal = input.m_motionState->getSweptTransform().m_centerOfMassLocal;
	for (int i = 0; i < input.m_numTransforms; i++)
	{
		hkVector4 extendedArm;
		extendedArm.setSub4(arm, centerOfMassLocal);
		extendedArm.mul4(input.m_transforms[i].getTranslation().getSimdAt(3));
		extendedArm.add4(centerOfMassLocal);
		hkVector4 p; p._setTransformedPos(input.m_transforms[i], extendedArm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	{
		hkSimdReal r = aabbHalfSize.length3();
		hkVector4 radius; radius.setAll(r);
		aabbHalfSize.addMul4(input.m_motionState->m_deltaAngle.getSimdAt(3), radius);
		aabbHalfSize.setMin4(radius, aabbHalfSize);
	}
	aabbOut.m_min.setSub4(min, aabbHalfSize);
	aabbOut.m_max.setAdd4(max, aabbHalfSize);
	aabbOut.m_min.setMin4(aabbIn.m_min, aabbOut.m_min);
	aabbOut.m_max.setMax4(aabbIn.m_max, aabbOut.m_max);
}
inline void __cdecl hkVector4Util::convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
	hkVector4 maxVal;
	maxVal.getQuad() = (*reinterpret_cast<const hkVector4*>(&hkVector4Util::hkAabbUint32MaxVal)).getQuad();
	hkVector4Util::convertToUint32WithClip( aabb.m_min, offsetLow,  scale, (*reinterpret_cast<const hkVector4*>(&hkQuadReal0000)), maxVal, aabbOut.m_min );
	hkVector4Util::convertToUint32WithClip( aabb.m_max, offsetHigh, scale, (*reinterpret_cast<const hkVector4*>(&hkQuadReal0000)), maxVal, aabbOut.m_max );
}
// pdb: hkpEntityAabbUtil::entityBatchRecalcAabb | hkpEntityAabbUtil.obj | fnv360_0822_debug, call_gap, low
// pdb params: collisionInput, entityBatch, numEntities
void __cdecl hkEntityAabbUtil::FUN_0099a2d0(const hkpCollisionInput* collisionInput, hkpEntity*const* entityBatch, int numEntities)
{
	const hkReal tolerance = collisionInput->getTolerance() * 0.5;
	for ( int entityIndex = 0; entityIndex < numEntities; entityIndex++ )
	{
		hkpEntity* entity = entityBatch[entityIndex];
		hkpCollidable* collidable = const_cast<hkpCollidable*>( entity->getCollidable() );
		const hkpShape* shape = collidable->getShape();
		int numChildShapeAabbs = collidable->m_boundingVolumeData.m_numChildShapeAabbs;
		if ( numChildShapeAabbs )
		{
			hkAabbUint32* childShapeAabbs = collidable->m_boundingVolumeData.m_childShapeAabbs;
			const hkpShapeContainer* container = shape->getContainer();
			hkpAabbUtil::OffsetAabbInput input;
			hkpAabbUtil::initOffsetAabbInput( entity->getMotion()->getMotionState(), input );
			{
				const hkVector4& massCenter = entity->getMotion()->getCenterOfMassInWorld();
				hkAabb rootAabb; rootAabb.m_min = massCenter; rootAabb.m_max = massCenter;
				hkAabb rootSweptAabb = rootAabb;
				hkAabbUint32* da = childShapeAabbs;
				hkpShapeContainer::ShapeBuffer shapeBuffer;
				for ( hkpShapeKey key = container->getFirstKey(); key != 0xffffffff; key = container->getNextKey( key ) )
				{
					if ( !container->isChildEnabled( key ) )
					{
						da->setInvalid();
						da++;
						continue;
					}
					const hkpShape* child = container->getChildShape( key, shapeBuffer );
					hkAabb aabb;
					hkAabb sweptAabb;
					child->getAabb( entity->getMotion()->getTransform(), tolerance, aabb );
					hkpAabbUtil::sweepOffsetAabb( input, aabb, sweptAabb );
					rootAabb.m_min.setMin4( rootAabb.m_min, aabb.m_min );
					rootAabb.m_max.setMax4( rootAabb.m_max, aabb.m_max );
					rootSweptAabb.m_min.setMin4( rootSweptAabb.m_min, sweptAabb.m_min );
					rootSweptAabb.m_max.setMax4( rootSweptAabb.m_max, sweptAabb.m_max );
					hkVector4Util::convertAabbToUint32( aabb, collisionInput->m_aabb32Info.m_bitOffsetLow, collisionInput->m_aabb32Info.m_bitOffsetHigh, collisionInput->m_aabb32Info.m_bitScale, *da );
					hkAabbUint32 sweptAabbUint32;
					hkVector4Util::convertAabbToUint32( sweptAabb, collisionInput->m_aabb32Info.m_bitOffsetLow, collisionInput->m_aabb32Info.m_bitOffsetHigh, collisionInput->m_aabb32Info.m_bitScale, sweptAabbUint32 );
					hkVector4Util::compressExpandedAabbUint32( sweptAabbUint32, *da );
					da++;
				}
				hkAabbUint32& rootAabbUint32 = reinterpret_cast<hkAabbUint32&>( collidable->m_boundingVolumeData );
				hkAabbUint32 rootSweptAabbUint32;
				hkVector4Util::convertAabbToUint32( rootAabb, collisionInput->m_aabb32Info.m_bitOffsetLow, collisionInput->m_aabb32Info.m_bitOffsetHigh, collisionInput->m_aabb32Info.m_bitScale, rootAabbUint32 );
				hkVector4Util::convertAabbToUint32( rootSweptAabb, collisionInput->m_aabb32Info.m_bitOffsetLow, collisionInput->m_aabb32Info.m_bitOffsetHigh, collisionInput->m_aabb32Info.m_bitScale, rootSweptAabbUint32 );
				hkVector4Util::compressExpandedAabbUint32( rootSweptAabbUint32, rootAabbUint32 );
			}
			if ( numChildShapeAabbs < 256 )
			{
				hkLocalBuffer<hkValueIndexPair> data( numChildShapeAabbs );
				hkAabbUint32* a = childShapeAabbs;
				hkValueIndexPair* d = data.begin();
				for ( int i = 0; i < numChildShapeAabbs; i++ ) { d->m_index = i; d->m_value = a->m_min[0]; a++; d++; }
				hkAlgorithm::quickSort( data.begin(), numChildShapeAabbs );
				d = data.begin();
				for ( int i = 0; i < numChildShapeAabbs; i++ ) { childShapeAabbs[d->m_index].m_sortIndex = hkUchar( i ); d++; }
			}
			else
			{
				hkAabbUint32* a = childShapeAabbs;
				for ( int i = 0; i < 256; i++ ) { a->m_sortIndex = hkUchar( i ); a++; }
			}
		}
		else
		{
			hkAabb aabb;
			hkAabb sweptAabb;
			shape->getAabb( entity->getMotion()->getTransform(), tolerance, aabb );
			hkpAabbUtil::sweepAabb( entity->getMotion()->getMotionState(), tolerance, aabb, sweptAabb );
			hkAabbUint32& aabbUint32 = reinterpret_cast<hkAabbUint32&>( collidable->m_boundingVolumeData );
			hkAabbUint32 sweptAabbUint32;
			hkVector4Util::convertAabbToUint32( aabb, collisionInput->m_aabb32Info.m_bitOffsetLow, collisionInput->m_aabb32Info.m_bitOffsetHigh, collisionInput->m_aabb32Info.m_bitScale, aabbUint32 );
			hkVector4Util::convertAabbToUint32( sweptAabb, collisionInput->m_aabb32Info.m_bitOffsetLow, collisionInput->m_aabb32Info.m_bitOffsetHigh, collisionInput->m_aabb32Info.m_bitScale, sweptAabbUint32 );
			hkVector4Util::compressExpandedAabbUint32( sweptAabbUint32, aabbUint32 );
		}
	}
}

}  // namespace f3m_0099a2d0

// @f3 0x00997b90 (community match, verified in this file)
// 0x00997b90: hkp3AxisSweep::calcAabbCache(const hkAabb& aabb, char* AabbCacheOut) const of Havok 5.5.0
// (hkpInternal, hkp3AxisSweep.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Collects the nodes whose boxes
// overlap the query box into a local array (the file's force-inlined _querySingleAabb with the node query type)
// and lets calcAabbCacheInternal build the cache from them (three small end point lists in the caller's buffer).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by a reducer, then single lines, every cut checked byte for byte); those declarations are the
// SDK's text with its names. hkp3AxisSweep itself is a class of the hkpInternal library that no SDK header ships:
// it is declared from the library's debug records (base class, data members, nested types, the methods used).
// The bodies follow the library's records (the debug build's _querySingleAabb with its named locals, the hybrid
// objects of this function and of calcAabbCacheInternal). The game's build differs from the SDK's release object
// (1,772 bytes) in three inlined functions, and so does this file:
// (1) hkp3AxisSweep::_convertAabbToInt copies MaxVal into a local vector before the two clips;
// (2) hkVector4Util::convertToUint16WithClip adds a magic that is a plain static of the file (four times 65536.0,
//     the game's data at 0x01060db0), lane by lane;
// (3) hkArray<T>::pushBackUnchecked stores through a pointer (T* p = m_data + m_size; *p = t; m_size++;) where
//     the SDK's header has m_data[m_size++] = t. The instructions of a push are the same; what changes is the
//     numbering of the compiler's temporaries, and by it which of the two differences of the third node test
//     is formed first (17 bytes with the SDK's wording).
// hkp3AxisSweep::calcAabbCacheInternal (the game's function at 0x00996ad0, 537 bytes) is defined here with its
// body under its address name; it compiles to the game's bytes, with the same pushBackUnchecked. With it in
// sight the compiler drops the local array's dead initial stores, as the original does. It is marked inline only
// so that it is a section of its own in the object (the SDK's flags have no /Gy) and the checker can bind the
// call; the compiler still calls it. hkpBpAxis::find (the game's 0x00990ea0) is declared under its address
// name; its body in the file changes no byte of this function. Besides these two only calcAabbCache is renamed,
// to the packet's name.
namespace f3m_00997b90 {

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
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
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
		}
		inline operator bool() const
		{
		}
		inline hkBool operator!=(bool e) const
		{
		}
		char m_bool;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
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
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
class hkThreadMemory
{
	public:
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			void put( void* p )
			{
				FreeElem* fl = static_cast<FreeElem*>(p);
			}
			void* get()
			{
				if(void* p = m_head)
				{
				}
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
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
};
class hkBaseObject
{
	public:
		__forceinline virtual ~hkBaseObject() {}
		__forceinline hkBaseObject() { }
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};
namespace hkArrayUtil
{
}
template <typename T>
class hkArray
{
	public:
		__forceinline hkArray();
		__forceinline hkArray(T* ptr, int size, int capacity);
		__forceinline ~hkArray();
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	return m_data[i];
}
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
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
}
template <typename T>
__forceinline void hkArray<T>::pushBackUnchecked(const T& t)
{
	T* p = m_data + m_size;
	*p = t;
	m_size++;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::end() const
{
	return m_data + m_size;
}
typedef float hkReal;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison
{
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		int m_mask;
};
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void setZero4();
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		__forceinline hkReal& operator() (int i);
		__forceinline hkQuadReal& getQuad();
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkQuadReal& hkVector4::getQuad()
{
	return reinterpret_cast<hkQuadReal&>(x);
}
inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
	}
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
	public:
		hkVector4 m_min;
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
class hkMultiThreadCheck
{
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
		}
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
		hkUint16 m_markBitStack;
};
class hkpBroadPhaseHandle;
class hkpBroadPhaseHandlePair;
class hkpBroadPhaseCastCollector;
typedef char hkpBroadPhaseAabbCache;
class hkpBroadPhase: public hkReferencedObject
{
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
		virtual void shiftAllObjects( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void shiftBroadPhase( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void getOffsetLowHigh32bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const = 0;
		struct hkpCastRayInput
		{
			hkVector4		m_from;
			int       m_numCasts;
			const hkVector4* m_toBase;
			int		  m_toStriding;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
		};
		virtual	void castRay( const hkpCastRayInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const = 0;
		virtual int getAabbCacheSize() const = 0;
		virtual void FUN_00997b90( const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		virtual void FUN_00997b90( const hkArray<class hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		struct hkpCastAabbInput
		{
			hkVector4 m_from;
			hkVector4 m_to;
			hkVector4 m_halfExtents;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
		};
		virtual void castAabb( const hkpCastAabbInput& input, hkpBroadPhaseCastCollector& collector ) const = 0;
		virtual void set32BitOffsetAndScale(const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale) = 0;
		mutable hkMultiThreadCheck m_multiThreadCheck;
		class hkCriticalSection *m_criticalSection;
};
class hkpBroadPhaseHandlePair
{
	public:
		hkpBroadPhaseHandle* m_a;
		hkpBroadPhaseHandle* m_b;
};
class hkpBroadPhaseCastCollector
{
	public:
		virtual ~hkpBroadPhaseCastCollector() { }
		virtual	hkReal addBroadPhaseHandle( const hkpBroadPhaseHandle* broadphaseHandle, int castIndex ) = 0;
};
union hkIntUnion64
{
	hkQuadReal quad;
	hkInt64 i64;
	hkUint64 u64;
	hkInt32 i32[2];
	hkUint32 u32[2];
	hkInt16 i16[4];
	hkUint16 u16[4];
	hkInt8 i8[8];
	hkUint8 u8[8];
};
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out);
}
namespace hkAlgorithm
{
template<typename T>
	class less
	{
	};
template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
template<typename T>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize)
	{
		quickSort( pArr, iSize, less<T>() );
	}
template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}
namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}
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
		}
		hkBool wasReallocated() const
		{
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};
static hkQuadReal convertToUint16WithClipMagic = {65536.0f,65536.0f,65536.0f,65536.0f};
inline void __cdecl hkVector4Util::convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	x(0) += convertToUint16WithClipMagic.x;
	x(1) += convertToUint16WithClipMagic.y;
	x(2) += convertToUint16WithClipMagic.z;
	x(3) += convertToUint16WithClipMagic.w;
	union
	{
		hkQuadReal q;
		hkUint32 i[4];
	} u;
	u.q = x.getQuad();
	out.i16[0] = hkInt16(u.i[0] >> 7);
	out.i16[1] = hkInt16(u.i[1] >> 7);
	out.i16[2] = hkInt16(u.i[2] >> 7);
	out.i16[3] = hkInt16(u.i[3] >> 7);
}
static inline void memclear16( void* dest, int bytesize )
{
	hkVector4 val; val.setZero4();
	hkVector4* d = (hkVector4*)dest;
	bytesize = bytesize >> 4;
	while ( bytesize >= 0 )
	{
		*(d++) = val;
		bytesize--;
	}
}
static __forceinline void toggleBit( int index, hkUint32* bitField )
{
	int word = index >> 5;
	hkUint32 mask = 1 << ( index & 31 );
	bitField[word] ^= mask;
}
static __forceinline void clearBit( int index, hkUint32* bitField )
{
	int word = index >> 5;
	hkUint32 mask = 1 << ( index & 31 );
	bitField[word] &= ~mask;
}
class hkp3AxisSweep : public hkpBroadPhase
{
	public:
		typedef hkUint16 BpInt;
		class hkpBpNode
		{
			public:
				__forceinline BpInt& getMin( int index ) { return ( index == 0 ) ? min_x : ( ( index == 1 ) ? min_y : min_z ); }
				__forceinline BpInt& getMax( int index ) { return ( index == 0 ) ? max_x : ( ( index == 1 ) ? max_y : max_z ); }
				__forceinline int isMarker() const { return int( hkUlong( m_handle ) ) & 1; }
				__forceinline hkUint32 yzDisjoint( const hkpBpNode& other ) const
				{
					hkUint32 minA = *reinterpret_cast<const hkUint32*>( &min_y );
					hkUint32 minB = *reinterpret_cast<const hkUint32*>( &other.min_y );
					hkUint32 maxA = *reinterpret_cast<const hkUint32*>( &max_y );
					hkUint32 maxB = *reinterpret_cast<const hkUint32*>( &other.max_y );
					maxA -= minB;
					maxB -= minA;
					maxA |= maxB;
					maxA &= 0x80008000;
					return maxA;
				}
				BpInt min_y;
				BpInt min_z;
				BpInt max_y;
				BpInt max_z;
				BpInt min_x;
				BpInt max_x;
				hkpBroadPhaseHandle* m_handle;
		};
		class hkpBpEndPoint
		{
			public:
				__forceinline int isMaxPoint() const { return m_value & 1; }
				__forceinline hkBool operator<( const hkpBpEndPoint& b ) const { return m_value < b.m_value; }
				BpInt m_value;
				BpInt m_nodeIndex;
		};
		class hkpBpAxis
		{
			public:
				__forceinline hkpBpAxis() {}
				__forceinline hkpBpAxis( hkpBpEndPoint* buffer, int capacity ) : m_endPoints( buffer, 0, capacity ) {}
				__forceinline void* operator new( hk_size_t, void* p ) { return p; }
				__forceinline void operator delete( void* ) {}
				__forceinline void operator delete( void*, void* ) {}
				const hkpBpEndPoint* FUN_00990ea0( const hkpBpEndPoint* start, const hkpBpEndPoint* end, BpInt value ) const;
				hkArray<hkpBpEndPoint> m_endPoints;
		};
		class hkpBpMarker
		{
			public:
				BpInt m_nodeIndex;
				BpInt m_value;
				hkArray<BpInt> m_overlappingObjects;
		};
		enum hkpBpQuerySingleType
		{
			HK_BP_REPORT_HANDLES,
			HK_BP_REPORT_NODES,
			HK_BP_REPORT_COLLECTOR
		};
		virtual void FUN_00997b90( const hkAabb& aabb, char* AabbCacheOut ) const;
		__forceinline void _convertAabbToInt( const hkAabb& aabb, hkAabbUint32& aabbOut ) const;
		static __forceinline void __cdecl _convertAabbToInt( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
	protected:
		void FUN_00996ad0( const hkArray<const hkpBpNode*>& overlaps, char* AabbCacheOut ) const;
		__forceinline void querySingleAabbSub( hkpBroadPhaseHandle* object, const hkUint32* bitField, hkpBpNode& refNode, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const;
		__forceinline void _querySingleAabb( const hkAabb& aabbIn, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const;
	public:
		static __declspec(align(16)) hkUint32 OneMask[4];
		static __declspec(align(16)) hkReal MaxVal[4];
		hkAabb m_aabb;
		hkVector4 m_offsetLow;
		hkVector4 m_offsetHigh;
		hkVector4 m_scale;
		hkVector4 m_offsetLow32bit;
		hkVector4 m_offsetHigh32bit;
		hkVector4 m_scale32bit;
		hkArray<hkpBpNode> m_nodes;
		hkpBpAxis m_axis[3];
		int m_numMarkers;
		int m_ld2NumMarkers;
		hkpBpMarker* m_markers;
		hkReal m_intToFloatFloorCorrection;
};
__forceinline void __cdecl hkp3AxisSweep::_convertAabbToInt( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
	hkVector4 zero; zero.setZero4();
	hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&MaxVal));
	hkIntUnion64 mi;
	hkIntUnion64 ma;
	hkVector4Util::convertToUint16WithClip( aabb.m_min, offsetLow, scale, zero, maxVal, mi );
	hkVector4Util::convertToUint16WithClip( aabb.m_max, offsetHigh, scale, zero, maxVal, ma );
	aabbOut.m_min[0] = mi.u16[0] & 0xfffe;
	aabbOut.m_min[1] = mi.u16[1] & 0xfffe;
	aabbOut.m_min[2] = mi.u16[2] & 0xfffe;
	aabbOut.m_max[0] = ma.u16[0] | 1;
	aabbOut.m_max[1] = ma.u16[1] | 1;
	aabbOut.m_max[2] = ma.u16[2] | 1;
}
__forceinline void hkp3AxisSweep::_convertAabbToInt( const hkAabb& aabb, hkAabbUint32& aabbOut ) const
{
	_convertAabbToInt( aabb, m_offsetLow, m_offsetHigh, m_scale, aabbOut );
}
__forceinline void hkp3AxisSweep::querySingleAabbSub( hkpBroadPhaseHandle* object, const hkUint32* bitField, hkpBpNode& refNode, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const
{
	hkpBroadPhaseHandlePair pair;
	pair.m_a = object;
	const hkpBpNode* nodes = &m_nodes[0];
	const hkUint32* bitsEnd = bitField + ( m_nodes.getSize() >> 5 ) + 1;
	for ( ; bitField < bitsEnd; nodes += 32, bitField++ )
	{
		hkUint32 b = *bitField;
		if ( !b )
		{
			continue;
		}
		const hkpBpNode* n = nodes;
		do
		{
			if ( b & 0xf )
			{
				if ( ( b & 1 ) && !n[0].yzDisjoint( refNode ) && !n[0].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						pair.m_b = n[0].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[0] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[0].m_handle, 0 );
					}
				}
				if ( ( b & 2 ) && !n[1].yzDisjoint( refNode ) && !n[1].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						pair.m_b = n[1].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[1] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[1].m_handle, 0 );
					}
				}
				if ( ( b & 4 ) && !n[2].yzDisjoint( refNode ) && !n[2].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						pair.m_b = n[2].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[2] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[2].m_handle, 0 );
					}
				}
				if ( ( b & 8 ) && !n[3].yzDisjoint( refNode ) && !n[3].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						pair.m_b = n[3].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[3] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[3].m_handle, 0 );
					}
				}
			}
			n += 4;
		}
		while ( b >>= 4 );
	}
}
__forceinline void hkp3AxisSweep::_querySingleAabb( const hkAabb& aabbIn, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const
{
	int numNodes = m_nodes.getSize();
	hkUint32* bitField = hkAllocateStack<hkUint32>( ( numNodes >> 5 ) + 8 );
	memclear16( bitField, numNodes >> 3 );
	hkAabbUint32 aabb;
	_convertAabbToInt( aabbIn, aabb );
	const hkpBpEndPoint* ep = &m_axis[0].m_endPoints[1];
	if ( m_numMarkers )
	{
		int xValue = aabb.m_min[0];
		int pos = xValue >> ( 16 - m_ld2NumMarkers );
		if ( pos > 0 )
		{
			hkpBpMarker* m = &m_markers[pos - 1];
			toggleBit( m->m_nodeIndex, bitField );
			BpInt* o = m->m_overlappingObjects.begin();
			for ( int k = m->m_overlappingObjects.getSize() - 1; k >= 0; k-- )
			{
				toggleBit( *o, bitField );
				o++;
			}
			const hkpBpNode& markerNode = m_nodes[m->m_nodeIndex];
			ep = &m_axis[0].m_endPoints[markerNode.min_x + 1];
			const hkpBpEndPoint* end = &m_axis[0].m_endPoints[markerNode.max_x];
			for ( ; ep < end; ep++ )
			{
				if ( !ep->isMaxPoint() )
				{
					clearBit( ep->m_nodeIndex, bitField );
				}
			}
			ep = &m_axis[0].m_endPoints[markerNode.min_x + 1];
		}
	}
	while ( ep->m_value < aabb.m_min[0] )
	{
		toggleBit( ep->m_nodeIndex, bitField );
		ep++;
	}
	while ( ep->m_value < aabb.m_max[0] )
	{
		if ( !ep->isMaxPoint() )
		{
			toggleBit( ep->m_nodeIndex, bitField );
		}
		ep++;
	}
	hkpBpNode refNode;
	{
		const hkpBpAxis& axis = m_axis[1];
		const hkpBpEndPoint* start = &axis.m_endPoints[0];
		const hkpBpEndPoint* end = axis.m_endPoints.end() - 2;
		refNode.min_y = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_min[1] ) ) - start );
		refNode.max_y = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_max[1] ) ) - ( start + 1 ) );
	}
	{
		const hkpBpAxis& axis = m_axis[2];
		const hkpBpEndPoint* start = &axis.m_endPoints[0];
		const hkpBpEndPoint* end = axis.m_endPoints.end() - 2;
		refNode.min_z = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_min[2] ) ) - start );
		refNode.max_z = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_max[2] ) ) - ( start + 1 ) );
	}
	querySingleAabbSub( 0, bitField, refNode, type, pairs_out, nodesOut, collector );
	hkDeallocateStack( bitField );
}
void hkp3AxisSweep::FUN_00997b90( const hkAabb& aabb, char* AabbCacheOut ) const
{
	hkLocalArray<const hkpBpNode*> overlaps( m_nodes.getSize() );
	_querySingleAabb( aabb, HK_BP_REPORT_NODES, 0, &overlaps, 0 );
	FUN_00996ad0( overlaps, AabbCacheOut );
}
inline void hkp3AxisSweep::FUN_00996ad0( const hkArray<const hkpBpNode*>& overlaps, char* AabbCacheOut ) const
{
	hkpBpAxis* axis = reinterpret_cast<hkpBpAxis*>( AabbCacheOut );
	{
		hkpBpEndPoint* ep = reinterpret_cast<hkpBpEndPoint*>( axis + 3 );
		int size = 2 * overlaps.getSize() + 2;
		new ( &axis[0] ) hkpBpAxis( ep + size * 0, size );
		new ( &axis[1] ) hkpBpAxis( ep + size * 1, size );
		new ( &axis[2] ) hkpBpAxis( ep + size * 2, size );
	}
	hkpBpEndPoint ep;
	ep.m_value = 0;
	ep.m_nodeIndex = 0;
	axis[0].m_endPoints.pushBackUnchecked( ep );
	axis[1].m_endPoints.pushBackUnchecked( ep );
	axis[2].m_endPoints.pushBackUnchecked( ep );
	hkpBpNode** p = const_cast<hkpBpNode**>( overlaps.begin() );
	{
		for ( int i = overlaps.getSize() - 1; i >= 0; i-- )
		{
			axis[0].m_endPoints.pushBackUnchecked( m_axis[0].m_endPoints[ p[0]->getMin( 0 ) ] );
			axis[0].m_endPoints.pushBackUnchecked( m_axis[0].m_endPoints[ p[0]->getMax( 0 ) ] );
			axis[1].m_endPoints.pushBackUnchecked( m_axis[1].m_endPoints[ p[0]->getMin( 1 ) ] );
			axis[1].m_endPoints.pushBackUnchecked( m_axis[1].m_endPoints[ p[0]->getMax( 1 ) ] );
			axis[2].m_endPoints.pushBackUnchecked( m_axis[2].m_endPoints[ p[0]->getMin( 2 ) ] );
			axis[2].m_endPoints.pushBackUnchecked( m_axis[2].m_endPoints[ p[0]->getMax( 2 ) ] );
			p++;
		}
	}
	{
		for ( int i = 0; i < 3; i++ )
		{
			hkAlgorithm::quickSort( axis[i].m_endPoints.begin() + 1, axis[i].m_endPoints.getSize() - 1 );
		}
	}
	ep.m_value = 0xfffc;
	ep.m_nodeIndex = 0;
	axis[0].m_endPoints.pushBackUnchecked( ep );
	axis[1].m_endPoints.pushBackUnchecked( ep );
	axis[2].m_endPoints.pushBackUnchecked( ep );
}

}  // namespace f3m_00997b90
