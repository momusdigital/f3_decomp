#include "f3_common.h"
// src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldoperationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// hkpAgentNnTrack: m_bytesUsedInLastSector, then the sectors array (size at +0x08).
struct hkpAgentNnTrackCB74
{
    int m_bytesUsedInLastSector;
    void* m_sectors;
    int m_sectorsSize;
    int __thiscall hkpAgentNnTrack_getSectorSize(int value);
};

// @fnv 0x00cb7460
// pdb: hkpAgentNnTrack::getSectorSize | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
int __thiscall hkpAgentNnTrackCB74::hkpAgentNnTrack_getSectorSize(int value)
{
    if (value + 1 == m_sectorsSize)
        return m_bytesUsedInLastSector;
    return 0x200;
}

// If the island is in the world's dirty list, clears its entry there and marks it as not listed (0xffff).
// @fnv 0x00cb3fd0
// pdb: hkpWorldOperationUtil::removeIslandFromDirtyList | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_dedup, low
// pdb params: world, island
// hkpWorld: m_dirtySimulationIslands.m_data at +0x40; hkpSimulationIsland: m_dirtyListIndex at +0x22
// (New Vegas Xbox 360 PDB).
struct DirtyListWorldCB3F
{
    char unk00[0x40];
    int* m_dirtySimulationIslands;
};
struct DirtyListIslandCB3F
{
    char unk00[0x22];
    unsigned short m_dirtyListIndex;
};
void ClearSlotReference(DirtyListWorldCB3F* world, DirtyListIslandCB3F* island)
{
    unsigned short* s = &island->m_dirtyListIndex;
    if (*s != 0xffff)
    {
        int* base = world->m_dirtySimulationIslands;
        base[*s] = 0;
        *s = 0xffff;
    }
}

void FUN_00d27ac0(int first, int second);
void FUN_00d00960(int first, int second);
// @fnv 0x00cb3c80
void FUN_00cb3c80(int first, int second)
{
    FUN_00d27ac0(first, second);
    FUN_00d00960(first, second);
}

struct FUN_00cb3ca0_object
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
    int refCount94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};

void __cdecl FUN_00d27ac0(FUN_00cb3ca0_object* object, int* value);
void __cdecl FUN_00d00960(FUN_00cb3ca0_object* object, int* value);

// @f3 0x00926420 (community match, verified in this file)
// pdb: hkpWorldOperationUtil::addConstraintImmediately | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_seq), high
int* __cdecl hkpWorldOperationUtil_addConstraintImmediately(FUN_00cb3ca0_object* object, int* value, int shouldNotify)
{
    ++object->unk84;
    FUN_00d27ac0(object, value);
    if (shouldNotify != 0)
    {
        FUN_00d00960(object, value);
    }
    --object->unk84;
    if (object->unk84 == 0 && *reinterpret_cast<unsigned char*>(&object->unk8c) == 0 && object->unk80 != 0)
    {
        object->FUN_00c91120();
    }
    return value;
}


struct S_00cb3da0_Ctx
{
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
};

void NotifyTargets(S_00cb3da0_Ctx* ctx, void* p);
void hkpWorldConstraintUtil_removeConstraint(void* p);

// If ctx->unk144 is nonzero, calls NotifyTargets with ctx and p, then always calls hkpWorldConstraintUtil_removeConstraint on p.
// @f3 0x00926480 (community match, verified in this file)
void FUN_00cb3da0(S_00cb3da0_Ctx* context, void* record)
{
    if (context->unk118)
        NotifyTargets(context, record);
    hkpWorldConstraintUtil_removeConstraint(record);
}


struct CB3DD0Collidable
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
    unsigned char unk24;
    unsigned char m_flags;
};

struct CB3DD0Entity
{
    int unk00;
    int unk04;
    CB3DD0Collidable* m_kCollidable;
};

struct CB3DD0World
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk098;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk09D;
    unsigned char unk09E;
    unsigned char unk09F;
    int unk0A0;
    int m_iPendingOperationQueueCount;
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
    void* m_kListener;

    void ExecutePendingOperations();
    void ExecutePendingOperationQueues();

    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount)
            return;
        if (m_bBlockExecutingPendingOperations)
            return;
        if (m_iPendingOperationCount)
            ExecutePendingOperations();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
            ExecutePendingOperationQueues();
    }
};

void __cdecl NotifyTargets(CB3DD0World* world, CB3DD0Entity* entity);
void __cdecl hkpWorldConstraintUtil_removeConstraint(CB3DD0Entity* entity);

// @f3 0x009264b0 (community match, verified in this file)
// pdb: hkpWorldOperationUtil::removeConstraintImmediately | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(CB3DD0World* world, CB3DD0Entity* entity, int fireCallbacks)
{
    CB3DD0Collidable* collidable = entity->m_kCollidable;
    collidable->m_flags = (collidable->m_flags & ~2) | 1;
    if (world->unk084)
    {
        if (fireCallbacks && world->unk118)
            NotifyTargets(world, entity);
        hkpWorldConstraintUtil_removeConstraint(entity);
        return;
    }
    world->unk084++;
    if (fireCallbacks && world->unk118)
        NotifyTargets(world, entity);
    hkpWorldConstraintUtil_removeConstraint(entity);
    if (--world->unk084)
        return;
    if (*reinterpret_cast<const unsigned char*>(&world->m_iPendingOperationCount))
        return;
    if (world->unk080)
        world->ExecutePendingOperations();
}


struct FUN_00d070b0_class
{
    void FUN_00d070b0();
};
struct CleanupList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d070b0_class* finalObject;
    int unk24;
    FUN_00d070b0_class** firstObjects;
    int firstCount;
    int unk30;
    FUN_00d070b0_class** secondObjects;
    int secondCount;
};
// Calls FUN_00d070b0 on every object in firstObjects and secondObjects in reverse order, then on finalObject.
// @fnv 0x00cb3e90
// pdb: hkpWorldOperationUtil::validateWorld | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun, low
// pdb params: world
void __cdecl FUN_00cb3e90(CleanupList* apCleanupList)
{
    int i = apCleanupList->firstCount - 1;
    while (i >= 0)
    {
        apCleanupList->firstObjects[i]->FUN_00d070b0();
        --i;
    }
    i = apCleanupList->secondCount - 1;
    while (i >= 0)
    {
        apCleanupList->secondObjects[i]->FUN_00d070b0();
        --i;
    }
    apCleanupList->finalObject->FUN_00d070b0();
}

struct Obj;

struct Agent
{
    virtual void v0(int);
    char pad0[0x20 - 4];
    unsigned short m_20;
    char pad1[0x4c - 0x22];
    int m_4c;
    __declspec(nothrow) void RemoveItem(Obj* o);
};

struct Obj
{
    int pad0[2];
    int m_8;
    char pad1[0xc8 - 0xc];
    bool m_c8;
    char pad2[3];
    Agent* m_cc;
};

__declspec(nothrow) void __cdecl hkpWorldOperationUtil_removeIsland(Obj* o, Agent* a);

// Clears o->m_8, calls the agent's RemoveItem, and if the agent's m_20 is not 0xffff, m_4c is 0 and ctx->m_c8 is set, calls hkpWorldOperationUtil_removeIsland and v0(1).
// @f3 0x00927460 (community match, verified in this file)
struct AgentF3
{
    virtual void v0(int);
    __declspec(nothrow) void FUN_0098adc0(Obj* o);
};
struct EntityF3
{
    int unk00;
    int unk04;
    int m_8;
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
    Agent* m_owner;
};
struct WorldF3
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
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    bool m_bFlag;
};
__declspec(nothrow) void __cdecl FUN_00926920(Obj* o, Agent* a);
// pdb: hkpWorldOperationUtil::removeEntitySI | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_seq) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_removeEntitySI(Obj* ctx, Obj* o)
{
    Agent* a = ((EntityF3*)o)->m_owner;
    ((EntityF3*)o)->m_8 = 0;
    ((AgentF3*)a)->FUN_0098adc0(o);
    if (a->m_20 != 0xffff && a->m_4c == 0 && ((WorldF3*)ctx)->m_bFlag)
    {
        FUN_00926920(ctx, a);
        a->v0(1);
    }
}


struct S_00cb5d00_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00cb5d00_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
struct S_00cb5d00_Router
{
    S_00cb5d00_Stack m_aiEntries;
    S_00cb5d00_Heap* m_pStreamAllocator;
    static S_00cb5d00_Router& FUN_00c85750() throw();
    S_00cb5d00_Stack& stack() throw()
    {
        return m_aiEntries;
    }
    S_00cb5d00_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb5d00_Elem
{
    int unk00;
    int unk04;
};
template <class T> struct S_00cb5d00_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00cb5d00_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~S_00cb5d00_Array() throw()
    {
        _clearAndDeallocate(*S_00cb5d00_Router::FUN_00c85750().m_pStreamAllocator);
    }
    void _clearAndDeallocate(S_00cb5d00_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <class T> struct S_00cb5d00_LocalArray : S_00cb5d00_Array<T>
{
    T* m_pStackAllocation;
    __forceinline S_00cb5d00_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)S_00cb5d00_Router::FUN_00c85750().stack().allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00cb5d00_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        S_00cb5d00_Router::FUN_00c85750().stack().deallocateStack(mem);
    }
};
struct S_00cb5d00_Source
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out);
    void query(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out) throw()
    {
        unk1C(key, out);
    }
};

struct Object
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
    int** items;
    int count;
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
    unsigned char enabled;
};
extern void __cdecl PropagateStateToChildren(Object*, int*);
// If object->enabled is set, walks object->items backwards and calls PropagateStateToChildren for each item whose byte at offset 0x25 has bits 0-1 set.
// @f3 0x00929630 (community match, verified in this file)
// pdb: hkpWorldOperationUtil::splitSimulationIslands | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void hkpWorldOperationUtil_splitSimulationIslands(Object* object) {
    if (*reinterpret_cast<const unsigned char*>(&object->unkB8)) {
        for (int index = object->count - 1; index >= 0; --index) {
            int* item = object->items[index];
            if ((*(unsigned char*)((char*)item + 0x25) & 3) != 0)
                PropagateStateToChildren(object, item);
        }
    }
}


struct Box
{
    char pad[0x14];
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

struct Holder
{
    char pad[0x30];
    Box* box;
};

struct Stats
{
    char pad[8];
    int maxv;
    int sum0;
    int sum1;
    int sum2;
    void hkpConstraintOwner_addConstraintInfo(Holder* h, const int* s);
};

// If the holder has a box, updates maxv and the three sums from s, adds s[1..3] into the box fields, and raises maxv to the box's a.
// @f3 0x00929b70 (community match, verified in this file)
// pdb: hkpConstraintOwner::addConstraintInfo | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller, high
// pdb params: constraint, delta
// pdb: hkpConstraintOwner::addConstraintInfo | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller, high (was: AccumulateStats)
void Stats::hkpConstraintOwner_addConstraintInfo(Holder* apHolder, const int* aiStats)
{
    Box*& box = *reinterpret_cast<Box**>(apHolder->pad + 0x28);
    if (box)
    {
        {
            int t = aiStats[0];
            maxv = maxv > t ? maxv : t;
        }
        maxv = maxv > aiStats[1] ? maxv : aiStats[1];
        sum0 += aiStats[1];
        sum1 += aiStats[2];
        sum2 += aiStats[3];
        Box* b = box;
        int nc = b->c + aiStats[3];
        int na = b->a + aiStats[1];
        b->b += aiStats[2];
        b->c = nc;
        b->a = na;
        int a = box->a;
        maxv = maxv > a ? maxv : a;
    }
}


class S_00dd7d00_Bool
{
  public:
    S_00dd7d00_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct S_00dd7d00_Item;

typedef S_00dd7d00_Bool(__cdecl* S_00dd7d00_Less)(S_00dd7d00_Item* a, S_00dd7d00_Item* b);

// Sorts the range [d, h] of pArr in place with a Hoare-style quicksort using cmpLess, recursing on the left part and looping on the right.
// @fnv 0x00dd7d00
// pdb: hkAlgorithm::quickSortRecursive<hkpSimulationIsland *,hkBool (__cdecl*)(hkpSimulationIsland const *,hkpSimulationIsland const *)> | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: pArr, d, h, cmpLess
void FUN_00dd7d00(S_00dd7d00_Item** apItems, int aiLow, int aiHigh, S_00dd7d00_Less apfnLess)
{
    int i, j;
    __declspec(align(16)) S_00dd7d00_Item* pPivot;
begin:
    i = aiHigh;
    j = aiLow;
    pPivot = apItems[(aiLow + aiHigh) >> 1];
    do
    {
        while (apfnLess(apItems[j], pPivot))
            j++;
        while (apfnLess(pPivot, apItems[i]))
            i--;
        if (i >= j)
        {
            if (i != j)
            {
                S_00dd7d00_Item* pTemp = apItems[i];
                apItems[i] = apItems[j];
                apItems[j] = pTemp;
            }
            i--;
            j++;
        }
    } while (j <= i);
    if (aiLow < i)
        FUN_00dd7d00(apItems, aiLow, i, apfnLess);
    if (j < aiHigh)
    {
        aiLow = j;
        goto begin;
    }
}

struct S_00c6aca0_Tls
{
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
    int ctx;
};
__declspec(thread) S_00c6aca0_Tls DAT_tls;

struct S_00c6aca0_Ctx
{
    int saved;
    __forceinline S_00c6aca0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00c6aca0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};

struct S_00c6aca0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00c6aca0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c6aca0_Heap* m10;
    __forceinline S_00c6aca0_Heap& heap()
    {
        return *m10;
    }
};
S_00c6aca0_Router* FUN_00c85750() throw();

struct S_00c6aca0_Item
{
    virtual ~S_00c6aca0_Item();
};
struct S_00c6aca0_Arr4
{
    S_00c6aca0_Item** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            int n = cap & 0x3fffffff;
            h.ReturnMemory(m_data, n * 4);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr4() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};
struct S_00c6aca0_Arr8
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 8);
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr8() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};

struct S_00c6aca0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    virtual ~S_00c6aca0_Base();
    void FUN_00c876a0();
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
    __forceinline void callVfn94()
    {
        vfn_94();
    }
};

struct S_00cb3f90_Bool
{
    bool m_cBooleanValue;
    S_00cb3f90_Bool(bool b) : m_cBooleanValue(b)
    {}
};

struct S_00cb3f90_Inner
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
    unsigned int unkD4;
};

struct S_00cb3f90_Sub
{
    S_00cb3f90_Inner* m_pInner;
};

struct S_00cb3f90_Obj
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
    S_00cb3f90_Sub* m_pSub;
};

// Returns false if b is null, true if a is null, otherwise compares a's inner unkD4 against b's inner unkD4.
// @f3 0x00926640 (community match, verified in this file)
// pdb: worldOperationUtil_less_hkSimulationIslandPtr | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
S_00cb3f90_Bool worldOperationUtil_less_hkSimulationIslandPtr(S_00cb3f90_Obj* pObjA, S_00cb3f90_Obj* pObjB)
{
    if (!pObjB)
        return false;
    if (!pObjA)
        return true;
    return static_cast<unsigned int>(pObjA->m_pSub->m_pInner->unkC0) < static_cast<unsigned int>(pObjB->m_pSub->m_pInner->unkC0);
}


namespace fnv_00cb4000 {
struct ListItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_uiEdgeIndex;  // +0x20
    unsigned short unk22;          // +0x22
    unsigned short unk24;          // +0x24
    unsigned char m_flags;         // +0x26 (flags & 3 selects the list)
};

struct ListOwner
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
    ListItem** m_list28;  // +0x28
    int m_count2c;        // +0x2c
    int unk30;            // +0x30
    ListItem** m_list34;  // +0x34
    int m_count38;        // +0x38
};

void ClearSlotReference(int* thisPtr, int* p);

// Removes item from one of the owner's two lists by swapping in the last element, fixes its index, decrements the count, then calls ClearSlotReference.
// @fnv 0x00cb4000
// pdb: hkpWorldOperationUtil::removeIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: world, island
// pdb: hkpWorldOperationUtil::removeIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq, high (was: RemoveListItem)
void hkpWorldOperationUtil_removeIsland(ListOwner* self, ListItem* volatile item)
{
    ListItem* pItem = item;
    if ((pItem->m_flags & 3) == 0)
    {
        ListItem** arr = self->m_list34;
        int last = self->m_count38 - 1;
        arr[pItem->m_uiEdgeIndex] = arr[last];
        self->m_list34[pItem->m_uiEdgeIndex]->m_uiEdgeIndex = pItem->m_uiEdgeIndex;
        self->m_count38--;
    }
    else
    {
        ListItem** arr = self->m_list28;
        int last = self->m_count2c - 1;
        arr[pItem->m_uiEdgeIndex] = arr[last];
        self->m_list28[pItem->m_uiEdgeIndex]->m_uiEdgeIndex = pItem->m_uiEdgeIndex;
        self->m_count2c--;
    }
    ClearSlotReference((int*)self, (int*)pItem);
}
}  // namespace fnv_00cb4000

namespace fnv_00cb5420 {
struct S_00cb5420_Heap;
struct S_00cb5420_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb5420_Heap* m_pStreamAllocator;
    S_00cb5420_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cb5420_Router& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(S_00cb5420_Heap& alloc, void* array, int elemSize);

template <class T> struct S_00cb5420_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void _pushBack(S_00cb5420_Heap& alloc, const T& t)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
            ResizeAudioStream(alloc, this, sizeof(T));
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < 1; ++i)
            p[i] = t;
        m_iElementCount++;
    }
    __forceinline void AddBack(const T& t)
    {
        _pushBack(FUN_00c85750().heap(), t);
    }
};

struct S_00cb5420_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short m_idx;
    unsigned short unk24;
    unsigned char m_flags;
};

struct S_00cb5420_Container
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
    S_00cb5420_Array<S_00cb5420_Item*> m_items;
};

// Clears bits 0x0C in the item's flags; if the item's index is 0xFFFF, assigns it the container's item count and appends the item to the container's array.
// @fnv 0x00cb5420
void AddItemToContainer(S_00cb5420_Container* pContainer, S_00cb5420_Item* item)
{
    item->m_flags &= ~0x0C;
    if (item->m_idx == 0xFFFF)
    {
        item->m_idx = (unsigned short)pContainer->m_items.m_iElementCount;
        pContainer->m_items.AddBack(item);
    }
}
}  // namespace fnv_00cb5420

struct ObjB;
struct ObjA
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
    int m_94;
    void FUN_00c91160(void* p);
};
struct ObjB
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
    int m_cc;
};

struct FUN_00cb5570_arg
{
    unsigned char tag;
    ObjB* owner;
    ObjB* other;
};

void __cdecl FUN_00cb4c60(ObjA* a1, int a2, int a3);

// @f3 0x00928630 (community match, verified in this file)
// pdb: hkpWorldOperationUtil::mergeIslands | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(caller|call_dedup) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_mergeIslands(ObjA* apObjA, ObjB* apOwner, ObjB* apOther)
{
    int iOwnerValue = apOwner->unkB8;
    int iOtherValue = apOther->unkB8;
    if (apObjA->unk84 != 0)
    {
        FUN_00cb5570_arg arg;
        arg.tag = 0xc;
        arg.owner = apOwner;
        arg.other = apOther;
        apObjA->FUN_00c91160(&arg);
        return;
    }
    FUN_00cb4c60(apObjA, iOwnerValue, iOtherValue);
}


namespace fnv_00cb59f0 {
struct S_00cb59f0_Elem
{
    int unk00;
    int unk04;
};

struct S_00cb59f0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
};

struct S_00cb59f0_Router
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    S_00cb59f0_Heap* heap;
};

S_00cb59f0_Router* FUN_00c85750() throw();

struct S_00cb59f0_Local
{
    S_00cb59f0_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    S_00cb59f0_Elem* m_localMem;
    __forceinline S_00cb59f0_Local(int n) throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
        S_00cb59f0_Router* r = FUN_00c85750();
        char* p = r->stackCur;
        r->stackCur = p + ((n * 8 + 0x7f) & 0xffffff80);
        m_data = (S_00cb59f0_Elem*)p;
        m_localMem = m_data;
        m_cap = n | 0x80000000;
    }
    __forceinline ~S_00cb59f0_Local() throw()
    {
        S_00cb59f0_Elem* lm = m_localMem;
        if (lm == m_data)
            m_iElementCount = 0;
        FUN_00c85750()->stackCur = (char*)lm;
        S_00cb59f0_Heap& h = *FUN_00c85750()->heap;
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.vfn_10(m_data, (cap & 0x3fffffff) * 8);
    }
};

}  // namespace fnv_00cb59f0

namespace fnv_00cb5b10 {
// QueryEntityIntoBuffer candidate
struct WorldRec
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
    struct BroadRec* m_pBroadPhaseRecord;
    unsigned int unk5C;
    unsigned int unk60;
    struct DispatchRec* m_pCollisionDispatcher;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    struct FilterRec* m_iFilter;
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
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int m_cap;
};

struct __declspec(align(16)) OutSlot
{
    void* m_ptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct BufAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void BufFree(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    unsigned char* m_cursor;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    BufAllocator* m_pAllocator;
};

struct LocalArr
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
};

struct BroadRec
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Query(void* aabbA, void* aabbB, LocalArr* out);
};

struct DispatchRec
{
    void FUN_00cf7080(void* pairs, int count, void* filter);
};

struct FilterRec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00cb5b10

// Stand-in model for the objects the original touches.
// The polymorphic target: vtable slots 0x10 / 0x1c / 0x20 are used.
struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
    virtual void v14();
    virtual void v18();
    virtual void v1c(void* a, void* b);
    virtual void v20(void* a, int b, void* c, int d);
};

// The object at [owner + 0x64] - its member at 0xcf70f0 pops its own arguments.
struct Coll
{
    void __thiscall add(void* p, int n);
};

// The first argument.
struct Owner
{
    int unk00;
    int unk04;
    VObj* unk08;
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
    VObj* unk58;
    int unk5c;
    int unk60;
    Coll* unk64;
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
};

namespace fnv_00cb5f50 {
struct S_00cb5f50_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00cb5f50_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb5f50_Allocator* m_pStreamAllocator;
    S_00cb5f50_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cb5f50_Router* FUN_00c85750() throw();

template <typename T> struct S_00cb5f50_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~S_00cb5f50_Array() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
    void _clearAndDeallocate(S_00cb5f50_Allocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

template <typename T, int N> struct S_00cb5f50_InplaceArray : S_00cb5f50_Array<T>
{
    T m_kStorage[N];
    S_00cb5f50_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

struct S_00cb5f50_Island;
struct S_00cb5f50_World;

struct S_00cb5f50_Entity
{
    int unk00;
    int unk04;
    S_00cb5f50_World* m_pOwningWorld;
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
    S_00cb5f50_Island* m_pSimulationIsland;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_bFlag;
};

struct S_00cb5f50_Constraint
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void getConnectedEntities(S_00cb5f50_Array<S_00cb5f50_Entity*>& entitiesOut) throw();
    void FUN_00c905b0() throw();
};

struct S_00cb5f50_Island
{
    void AddItem(S_00cb5f50_Constraint* c) throw();
};

struct S_00cb5f50_World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00cb5f50_Island* m_pFixedIsland;
};

void hkpWorldOperationUtil_mergeIslands(S_00cb5f50_World* world, S_00cb5f50_Entity* a, S_00cb5f50_Entity* b) throw();

}  // namespace fnv_00cb5f50

struct FUN_00cb7480_node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
};

struct hkpConstraintInstanceCB74
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
    FUN_00cb7480_node* m_internal;  // +0x28
    int unk2c;
    int unk30;
};

struct FUN_00cb7480_delta
{
    int unk00;
    int m_04;
    int m_08;
    int m_0c;
};

struct hkpConstraintOwnerCB74
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    int m_14;

    void hkpConstraintOwner_subConstraintInfo(hkpConstraintInstanceCB74* a1, FUN_00cb7480_delta* a2);
};

// Subtracts the delta's m_04, m_08 and m_0c from m_0c, m_10 and m_14, and from the node's m_14, m_16 and m_18, when the constraint has its internal record.
// @f3 0x00929b20 (community match, verified in this file)
// pdb: hkpConstraintOwner::subConstraintInfo | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap_sim), high
void hkpConstraintOwnerCB74::hkpConstraintOwner_subConstraintInfo(hkpConstraintInstanceCB74* apHolder, FUN_00cb7480_delta* apDelta)
{
    if (apHolder->m_internal != 0)
    {
        m_0c -= apDelta->m_04;
        m_10 -= apDelta->m_08;
        m_14 -= apDelta->m_0c;
        FUN_00cb7480_node* n = apHolder->m_internal;
        int dy = n->m_18 - apDelta->m_0c;
        int dx = n->m_14 - apDelta->m_04;
        n->m_16 -= (unsigned short)apDelta->m_08;
        n->m_14 = (unsigned short)dx;
        n->m_18 = (unsigned short)dy;
    }
}


namespace fnv_00d282c0 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <class T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        T* p = (T*)AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return p;
    }
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& stack()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

template <class T> struct hkLocalArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkLocalArr(int n)
    {
        hkMemoryAllocator& alloc = audio()->stack();
        m_data = n ? alloc._bufAlloc<T>(n) : 0;
        m_iElementCount = 0;
        m_iCapacityState = n ? n : 0x80000000;
    }
    __forceinline ~hkLocalArr()
    {
        hkMemoryAllocator& alloc = audio()->stack();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
};

struct hkArr
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(int));
        }
        m_iElementCount = n;
    }
};

__forceinline int* localAlloc(hkMemoryAllocator& alloc, int n, int& m_iCapacity)
{
    int* p = n ? alloc._bufAlloc<int>(n) : 0;
    m_iCapacity = n ? n : 0x80000000;
    return p;
}

struct IndexRemap
{
    int** m_ppIndices;
    int m_iIndexCount;

    void RemapAndAccumulate(const hkArr& map, int n, hkArr& values);
};

// Remaps each entry of the index array through map, then sums values into n buckets by mapped index and writes the sums back into values.
// @fnv 0x00d282c0
void IndexRemap::RemapAndAccumulate(const hkArr& map, int n, hkArr& values)
{
    for (int i = 0; i < m_iIndexCount; i++)
        (*m_ppIndices)[i] = map.m_data[(*m_ppIndices)[i]];

    hkMemoryAllocator& stackAlloc = audio()->stack();
    int m_iCapacity;
    int* sums = localAlloc(stackAlloc, n, m_iCapacity);
    for (int i = 0; i < n; i++)
        sums[i] = 0;
    for (int i = 0; i < values.m_iElementCount; i++)
        sums[map.m_data[i]] += values.m_data[i];

    values.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
        values.m_data[i] = sums[i];

    hkMemoryAllocator& alloc = audio()->stack();
    if ((m_iCapacity & 0x80000000) == 0)
        alloc.ReturnMemory(sums, (m_iCapacity & 0x3fffffff) * sizeof(int));
}
}  // namespace fnv_00d282c0

inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S00cb5310_Sub;
struct S00cb5310_Node;
struct S00cb5310_Piece;
struct S00cb5310_Owner;
struct S00cb5310_Sub
{
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
    virtual void v40(void* p);
    virtual void v44(void* p);
};
struct S00cb5310_List
{
    S00cb5310_Node** m_00;
    int m_04;
    unsigned int m_08;
};
struct S00cb5310_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned char m_26;
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float m_44;
    S00cb5310_Piece** m_48;
    int m_4c;
};
struct S00cb5310_Piece
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
    S00cb5310_Sub m_e0;
    int unkE4;
    int unkE8;
    int unkEC;
    int m_f0;
    int unkF4;
    int unkF8;
    int unkFC;
};
struct S00cb5310_Owner
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
    S00cb5310_Node** m_28;
    int m_2c;
    int unk30;
    S00cb5310_List m_34;
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
    float m_1d0;
};
void ResizeAudioStream(void* alloc, S00cb5310_List* list, int n);
void UpdateRotationInterpolation(float f, void* p);

namespace fnv_00cb5500 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}
struct Entry
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned short unk20;
    unsigned short index;
    unsigned short unk24;
    unsigned char flags;
};
struct EntryArray
{
    Entry** entries;
    unsigned int count;
    unsigned int capacity;
};
struct AllocatorContext
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int allocator;
};
extern AllocatorContext* __cdecl FUN_00c85750();
extern void __cdecl ResizeAudioStream(unsigned int allocator, EntryArray* list, int entrySize);

}  // namespace fnv_00cb5500

struct Cb5750_Deferred
{
    unsigned char tag;
    struct Cb5750_Param* arg;
};

struct Cb5750_Bv
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_auiShapeKeys;
};

struct Cb5750_Nav
{
    int unk00;
    int unk04;
    int unk08;
    Cb5750_Bv m_bv;
};

struct Cb5750_Inner
{
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    int m_bpId;
    Cb5750_Nav m_nav;
};

struct Cb5750_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Cb5750_Inner inner;
};

struct Cb5750_Aabb
{
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};

struct Cb5750_Sub8
{
    int unk00;
    int unk04;
    int unk08;
};

S_00c6aca0_Router* Cb5750_router() throw();

struct Cb5750_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};

template <class T> struct Cb5750_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline Cb5750_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~Cb5750_Array() throw()
    {
        S_00c6aca0_Router* router = Cb5750_router();
        S_00c6aca0_Heap& heap = *router->m10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            heap.vfn_10(m_data, (cap & 0x3fffffff) * (int)sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <class T> struct Cb5750_LocalArray : Cb5750_Array<T>
{
    T* m_pStackAllocation;
    __forceinline Cb5750_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)((Cb5750_Stack*)Cb5750_router())->allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~Cb5750_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        ((Cb5750_Stack*)Cb5750_router())->deallocateStack(mem);
    }
};

struct Cb5750_Source
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual void v2c(Cb5750_Nav** key, Cb5750_Aabb* aabb, int count, Cb5750_Array<S_00cb5d00_Elem>* a,
                     Cb5750_Array<S_00cb5d00_Elem>* b) throw();
};

struct Cb5750_Sink
{
    void addSecond(S_00cb5d00_Elem* data, int n) throw();
    void addFirst(S_00cb5d00_Elem* data, int n, void* extra) throw();
};

S_00c6aca0_Router* Cb5750_router() throw();

struct Cb5750_Owner
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
    Cb5750_Source* unk58;
    int unk5C;
    int unk60;
    Cb5750_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;
    Cb5750_Sub8* unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
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

    void defer(Cb5750_Deferred* d) throw();
    void flush8c() throw();
    void flush90() throw();
    void __cdecl AddCollisionShape(Cb5750_Param* param) throw();
};

// If unk94 is set, defers the call; otherwise expands the shape's bounding volume into an AABB, queries unk58 with it, and passes results to unk64.
// @f3 0x00927d80 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
struct F3_Deferred
{
    unsigned char tag;
    struct F3_Param* arg;
};

struct F3_Bv
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_auiShapeKeys;
};

struct F3_Nav
{
    int unk00;
    int unk04;
    int unk08;
    F3_Bv m_bv;
};

struct F3_Inner
{
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    int m_bpId;
    F3_Nav m_nav;
};

struct F3_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F3_Inner inner;
};

struct F3_Aabb
{
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};

struct F3_Sub8
{
    int unk00;
    int unk04;
    int unk08;
};


struct F3_Pair {void* first; void* second;};
struct F3_Allocator {
 virtual void v00() throw();virtual void v04() throw();virtual void v08() throw();virtual void v0c() throw();virtual void v10() throw();
 virtual void* Allocate(int) throw();virtual void Free(void*) throw();
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 char* cursor;char* unk24;char* limitBlock;char* limit;
 __forceinline void* Alloc(int n) throw() {int size=(n+16)&~15;char* p=cursor;if(p+size<=limit){cursor=p+size;return p;}return Allocate(size);}
 __forceinline void Release(void* p) throw() {cursor=(char*)p;if(p==limitBlock)Free(p);}
 void FUN_008f6d90(void*,int,int) throw();
};
__forceinline F3_Allocator* GetAllocator() throw() {return (F3_Allocator*)TlsGetValue(DAT_010f3170);}
template<class T> struct F3_Array {
 T* m_data;int m_iElementCount;int m_iCapacityState;
 __forceinline F3_Array() throw():m_data(0),m_iElementCount(0),m_iCapacityState(0x80000000){}
 __forceinline int Capacity() const throw() {return m_iCapacityState&0x3fffffff;}
 __forceinline ~F3_Array() throw() {if((m_iCapacityState&0x80000000)==0){int cap=Capacity();F3_Allocator* a=GetAllocator();a->FUN_008f6d90(m_data,cap*sizeof(T),0x17);}}
};
template<class T> struct F3_LocalArray:F3_Array<T> {
 T* m_pStackAllocation;
 __forceinline F3_LocalArray(int capacity) throw() {m_data=(T*)GetAllocator()->Alloc(capacity*sizeof(T));m_iCapacityState=capacity|0x80000000;m_pStackAllocation=m_data;}
 __forceinline ~F3_LocalArray() throw() {T* mem=m_pStackAllocation;GetAllocator()->Release(mem);}
};
struct F3_Source {
 virtual void v00() throw();virtual void v04() throw();virtual void v08() throw();virtual void v0c() throw();virtual void v10() throw();virtual void v14() throw();virtual void v18() throw();virtual void v1c() throw();virtual void v20() throw();virtual void v24() throw();virtual void v28() throw();
 virtual void v2c(F3_Nav**,F3_Aabb*,int,F3_Array<F3_Pair>*,F3_Array<F3_Pair>*) throw();
};
struct F3_Sink {void FUN_00984cc0(F3_Pair*,int) throw();void FUN_00984c50(F3_Pair*,int,void*) throw();};
void __cdecl FUN_00984d00(F3_Array<F3_Pair>*,F3_Array<F3_Pair>*) throw();
void __cdecl FUN_0099a2d0(void*,F3_Param**,int) throw();
struct F3_Owner {
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
F3_Source* source;
F3_Sink* sink;
int unk05c;
int unk060;
int unk064;
int unk068;
void* world;
F3_Sub8* sub;
int unk074;
int unk078;
int unk07c;
int pending;
int depth;
int unk088;
unsigned char blocked;unsigned char unk8d,unk8e,unk8f;
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
int capacity;
void FUN_00902570(F3_Deferred*) throw();void FUN_00902550() throw();
};
// pdb: hkpWorldOperationUtil::updateEntityBP | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun, medium
// pdb params: world, entity
void __cdecl Cb5750_Owner::AddCollisionShape(Cb5750_Param* param) throw()
{
    F3_Owner* self=(F3_Owner*)this;
    if (self->depth != 0)
    {
        F3_Deferred deferred;
        deferred.tag = 3;
        deferred.arg = (F3_Param*)param;
        self->FUN_00902570(&deferred);
        return;
    }

    F3_Param* held = (F3_Param*)param;
    void* shape = held->inner.m_pCollisionShape;
    self->depth = 1;
    if (shape != 0)
    {
        F3_Inner* inner = &held->inner;
        F3_LocalArray<F3_Pair> arr1(self->capacity);
        F3_LocalArray<F3_Pair> arr2(self->capacity);
        if (inner->m_nav.m_bv.m_kMinimumCorner[0] > inner->m_nav.m_bv.m_kMaximumCorner[0])
            FUN_0099a2d0(self->world, (F3_Param**)&param, 1);

        __declspec(align(16)) F3_Aabb aabb;
        unsigned int uiExpansionShift = inner->m_nav.m_bv.m_ucExpansionShift;
        aabb.m_kMinimumCorner[0] =
            inner->m_nav.m_bv.m_kMinimumCorner[0] - (inner->m_nav.m_bv.m_ucExpansionMin[0] << uiExpansionShift);
        aabb.m_kMinimumCorner[1] =
            inner->m_nav.m_bv.m_kMinimumCorner[1] - (inner->m_nav.m_bv.m_ucExpansionMin[1] << uiExpansionShift);
        aabb.m_kMinimumCorner[2] =
            inner->m_nav.m_bv.m_kMinimumCorner[2] - (inner->m_nav.m_bv.m_ucExpansionMin[2] << uiExpansionShift);
        aabb.m_kMaximumCorner[0] =
            inner->m_nav.m_bv.m_kMaximumCorner[0] + (inner->m_nav.m_bv.m_ucExpansionMax[0] << uiExpansionShift);
        aabb.m_kMaximumCorner[1] =
            inner->m_nav.m_bv.m_kMaximumCorner[1] + (inner->m_nav.m_bv.m_ucExpansionMax[1] << uiExpansionShift);
        aabb.m_kMaximumCorner[2] =
            inner->m_nav.m_bv.m_kMaximumCorner[2] + (inner->m_nav.m_bv.m_ucExpansionMax[2] << uiExpansionShift);
        F3_Nav* key = &inner->m_nav;

        self->source->v2c(&key, &aabb, 1, &arr1, &arr2);
        if (arr1.m_iElementCount + arr2.m_iElementCount > 0)
        {
            FUN_00984d00(&arr1, &arr2);
            self->sink->FUN_00984cc0(arr2.m_data, arr2.m_iElementCount);
            F3_Sub8* sub = self->sub;
            void* extra = sub ? &sub->unk08 : 0;
            self->sink->FUN_00984c50(arr1.m_data, arr1.m_iElementCount, extra);
        }
    }

    if (--self->depth == 0 && self->blocked == 0)
    {
        if (self->pending != 0)
            self->FUN_00902550();
    }
}


namespace fnv_00cb5dd0 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}
struct Producer;
struct Actor;
struct Heap
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void freeMemory(void* pointer, unsigned int bytes);
};
struct MemoryContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Heap* heap;
};
extern "C" MemoryContext* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(void* heap, void* array, int elementSize);

template <class T> struct Array
{
    T** data;
    int length;
    unsigned int capacity;
    void add(T* p)
    {
        MemoryContext* memory = FUN_00c85750();
        if (length == (int)(capacity & 0x3fffffff))
            ResizeAudioStream(memory->heap, this, 4);
        T** address = data + length;
        __assume(address != 0);
        new (address) T*(p);
        ++length;
    }
};
struct Scratch : Array<Actor>
{
    Actor* inline0;
    Actor* inline1;
    Actor* inline2;
    Actor* inline3;
    Actor* inline4;
    Actor* inline5;
    Actor* inline6;
    Actor* inline7;
    Actor* inline8;
    Actor* inline9;
    Actor* inline10;
    Actor* inline11;
    Actor* inline12;
    Actor* inline13;
    Actor* inline14;
    Actor* inline15;
    Scratch()
    {
        data = &inline0;
        length = 0;
        capacity = 0x80000010;
    }
};
struct Producer
{
    virtual void zero();
    virtual void one();
    virtual void two();
    virtual void three();
    virtual void enumerate(Scratch* result);
    void __thiscall FUN_00c90510();
};
struct Actor
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
    unsigned char kindE8;
};
}  // namespace fnv_00cb5dd0

struct Item_cb3d10
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
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
};
struct Owner_cb3d10
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    unsigned char unkC8;
};
struct List_cb3d10
{
    Item_cb3d10** m_data;
    int m_iElementCount;
};
// Scans the last 20 list items backwards for a non-target item with unk26 & 0xc and max(unk4c, unk1c) + threshold < owner->unkB4; sets a unk25 bit and returns it.
// @fnv 0x00cb3d10
volatile int g_cb3d10_thr;
Owner_cb3d10* volatile g_cb3d10_owner;
List_cb3d10* volatile g_cb3d10_list;
Item_cb3d10* volatile g_cb3d10_target;
Item_cb3d10* volatile g_cb3d10_out;

struct B10293_Item
{
    unsigned short Field(int off) const
    {
        return *(const unsigned short*)((const char*)this + off);
    }
};
struct B10293_Ctx
{
    unsigned char Sel(int off) const
    {
        return *((const unsigned char*)this + off);
    }
};
static inline int Dec(int w, unsigned char s)
{
    if (s == (w >> 14))
        return (w >> 7) & 0x7f;
    return w & 0x7f;
}

namespace fnv_00cb4790 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}

struct Entry;
struct Cell
{
    void* value;
    Cell()
    {}
};
struct Array
{
    Cell* data;
    int size;
    unsigned capacity;
};
struct Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* allocator;
};
Heap* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, Array*, int);
struct Actor
{
    unsigned short& id()
    {
        return *(unsigned short*)((char*)this + 0x22);
    }
    unsigned char& flags()
    {
        return *(unsigned char*)((char*)this + 0x25);
    }
    void __thiscall RemoveEntry(Entry*);
};
struct Entry
{
    int unk00;
    int unk04;
    int unk08;
    Actor* actor;
    void __thiscall FUN_00c90510();
};
}  // namespace fnv_00cb4790

template <class T> inline void S00cb4c60_copy(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
struct hkpWorld;
struct hkpSimulationIsland;
struct hkpEntity;
struct hkpAction;
struct hkBool
{
    char value;
    hkBool(bool b) : value(b)
    {}
    hkBool(const hkBool& other) : value(other.value)
    {}
};
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> struct hkArrayNative
{
    T* data;
    int count;
    unsigned int capRaw;
    int getCapacity() const
    {
        return capRaw & 0x3fffffff;
    }
    void reserve(int n)
    {
        S_00c6aca0_Heap& a = FUN_00c85750()->heap();
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
    void AddBack(const T& t)
    {
        S_00c6aca0_Router* r = FUN_00c85750();
        if (count == getCapacity())
            ResizeAudioStream(&r->heap(), this, sizeof(T));
        S00cb4c60_copy(data + count, 1, t);
        count++;
    }
    void SetSize(int size)
    {
        reserve(size);
        count = size;
    }
};
struct hkpConstraintInstance
{
    int unk00, unk04;
    hkpSimulationIsland* owner;
};
struct ConstraintRuntimeInfo
{
    hkpConstraintInstance* constraint;
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
struct hkpAction
{
    int unk00, unk04, unk08;
    hkpSimulationIsland* owner;
};
struct hkpEntity
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
    unsigned short storageIndex, unkAA;
    ConstraintRuntimeInfo* constraintMasters;
    unsigned short constraintMasterCount, unkB2;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    hkpSimulationIsland* owner;
};
struct hkpSimulationIsland
{
    virtual ~hkpSimulationIsland();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short storageIndex, dirtyIndex;
    unsigned char unk24, flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char f26lo : 2;
            unsigned char f26mid : 2;
        } f26;
    };
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkArrayNative<hkpAction*> actions;
    int unk44;
    hkArrayNative<hkpEntity*> entities;
    int unk54;
    int unk58;
    void FUN_00d07120();
    void MergeFrom(hkpSimulationIsland*);
};
struct hkpWorld
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpSimulationIsland* fixedIsland;
    int unk24;
    hkArrayNative<hkpSimulationIsland*> active;
    hkArrayNative<hkpSimulationIsland*> inactive;
    hkArrayNative<hkpSimulationIsland*> dirty;
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
    int refCount94;
    int unk98;
    unsigned char flag9c, unk9d, unk9e, unk9f;
    int unka0;
    int unka4;
    void hkpConstraintInstance_entityAddedCallback(hkpSimulationIsland*);
    void FUN_00c91120();
    void FUN_00c91140();
};
void __cdecl hkpWorldOperationUtil_internalActivateIsland(hkpWorld*, hkpSimulationIsland*, hkBool);
void __cdecl FUN_00cff290(void*, void*);
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl ClearSlotReference(hkpWorld*, hkpSimulationIsland*);
static inline int GrowCap(int cap, int need)
{
    int nc = cap * 2;
    if (need >= nc)
        nc = need;
    return nc;
}
// Merges island Q into P, reassigns entity and action owners, updates world lists, and deletes Q.
// @fnv 0x00cb4c60
void __cdecl FUN_00cb4c60(hkpWorld* apWorld, hkpSimulationIsland* apTarget, hkpSimulationIsland* apSource)
{
    hkpWorld* o = apWorld;
    if (apTarget->entities.count > apSource->entities.count)
    {
    }
    else if (apTarget->entities.count < apSource->entities.count || apTarget->storageIndex > apSource->storageIndex)
    {
        hkpSimulationIsland* t = apTarget;
        apTarget = apSource;
        apSource = t;
    }
    o->refCount94++;
    unsigned char pf = apTarget->flags26;
    unsigned char cl = pf & 3;
    unsigned char dl;
    if (cl == 0 && (apSource->flags26 & 3) == 0)
        dl = 0;
    else
        dl = 1;
    unsigned char f18;
    if ((pf & 0xc) != 0 || (apSource->flags26 & 0xc) != 0)
        f18 = 1;
    else
        f18 = 0;
    if (dl)
    {
        if (cl == 0)
        {
            apTarget->flags26 = (pf & 0xf7) | 4;
            hkpWorldOperationUtil_internalActivateIsland(apWorld, apTarget, hkBool(false));
        }
        else if ((apSource->flags26 & 3) == 0)
        {
            apSource->flags26 = (apSource->flags26 & 0xf7) | 4;
            hkpWorldOperationUtil_internalActivateIsland(apWorld, apSource, hkBool(false));
        }
    }
    apTarget->flags25 |= (apSource->flags25 & 0xc);
    apTarget->FUN_00d07120();
    apSource->FUN_00d07120();
    o->fixedIsland->FUN_00d07120();
    FUN_00cff290(&apTarget->unk58, &apSource->unk58);
    int iTargetCount = apTarget->entities.count;
    unsigned short idx = (unsigned short)iTargetCount;
    int total = iTargetCount + apSource->entities.count;
    hkArrayNative<hkpEntity*>* v48 = &apTarget->entities;
    v48->SetSize(total);
    hkArrayNative<hkpEntity*>* pSourceEntities = &apSource->entities;
    for (int i = 0; i < pSourceEntities->count; ++i, ++idx)
    {
        v48->data[idx] = pSourceEntities->data[i];
        pSourceEntities->data[i]->owner = apTarget;
        pSourceEntities->data[i]->storageIndex = (unsigned short)idx;
    }
    int k = apTarget->actions.count;
    int iTotalActions = k + apSource->actions.count;
    hkArrayNative<hkpAction*>* v38 = &apTarget->actions;
    v38->SetSize(iTotalActions);
    hkArrayNative<hkpAction*>* pSourceActions = &apSource->actions;
    for (int i = 0; i < pSourceActions->count; ++i)
    {
        if (pSourceActions->data[i] != 0)
        {
            v38->data[k] = pSourceActions->data[i];
            v38->data[k]->owner = apTarget;
            ++k;
        }
    }
    v38->SetSize(k);
    for (int i = 0; i < pSourceEntities->count; ++i)
    {
        hkpEntity* e = pSourceEntities->data[i];
        ConstraintRuntimeInfo* rec = e->constraintMasters;
        for (int cnt = e->constraintMasterCount - 1; cnt >= 0; --cnt)
        {
            rec->constraint->owner = apTarget;
            ++rec;
        }
    }
    apTarget->MergeFrom(apSource);
    apTarget->unk1C += apSource->unk1C;
    apSource->unk1C = 0;
    unsigned short uSourceIndex = apSource->storageIndex;
    hkArrayNative<hkpSimulationIsland*>* c = ((apSource->flags26 & 3) != 0) ? &o->active : &o->inactive;
    int iListCount = c->count;
    if ((int)uSourceIndex < iListCount - 1)
    {
        c->data[uSourceIndex] = c->data[iListCount - 1];
        c->data[uSourceIndex]->storageIndex = uSourceIndex;
    }
    c->count--;
    unsigned char al = ((apTarget->flags25 & 3) != 0 || (apSource->flags25 & 3) != 0) ? 1 : 0;
    unsigned char x25 = apTarget->flags25;
    x25 ^= al;
    x25 &= 3;
    apTarget->flags25 ^= x25;
    unsigned char cl2 = apTarget->flags25;
    unsigned char al2 = ((cl2 & 0x30) != 0 || (apSource->flags25 & 0x30) != 0) ? 1 : 0;
    unsigned char uNewFlags = (unsigned char)(al2 << 4);
    uNewFlags ^= cl2;
    uNewFlags &= 0x30;
    uNewFlags ^= cl2;
    apTarget->flags25 = uNewFlags;
    apTarget->f26.f26mid = f18 != 0;
    if (apSource->dirtyIndex != 0xffff && apTarget->dirtyIndex == 0xffff)
    {
        apTarget->dirtyIndex = (unsigned short)o->dirty.count;
        hkArrayNative<hkpSimulationIsland*>* pDirtyList = &o->dirty;
        pDirtyList->AddBack(apTarget);
    }
    ClearSlotReference(apWorld, apSource);
    delete apSource;
    int w;
    if ((apTarget->flags26 & 3) != 0 && (w = apTarget->storageIndex) != 0)
    {
        hkArrayNative<hkpSimulationIsland*>* pActiveList = &o->active;
        hkpSimulationIsland* pFirstIsland = pActiveList->data[0];
        if (apTarget->entities.count > pFirstIsland->entities.count)
        {
            apTarget->storageIndex = 0;
            pFirstIsland->storageIndex = w;
            pActiveList->data[0] = apTarget;
            pActiveList->data[w] = pFirstIsland;
        }
    }
    apWorld->hkpConstraintInstance_entityAddedCallback(apTarget);
    if (--o->refCount94 == 0 && o->flag9c == 0)
    {
        if (o->unk8c != 0)
            o->FUN_00c91120();
        if (o->unka4 == 1 && o->unk90 != 0)
        {
            o->FUN_00c91140();
            return;
        }
    }
}

struct IslandList
{
    struct IslandNode** items;
    int count;
    int capacity;
};
struct IslandNode
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
    unsigned char index;
    unsigned char flags;
    union
    {
        unsigned char state;
        struct
        {
            unsigned char lowState : 2;
            unsigned char highState : 2;
            unsigned char otherState : 4;
        };
    };
    unsigned char unk27;
    IslandList first;
    IslandList second;
};
void __cdecl hkpWorldOperationUtil_splitSimulationIsland(IslandNode* data, Object* object, IslandList* list, int value);
void __cdecl AddItemToContainer(Object* object, IslandNode* item);
// Picks a list by the node's low state, runs hkpWorldOperationUtil_splitSimulationIsland, then for each new item copies that state, sets its index, and may call AddItemToContainer.
// @fnv 0x00cb6e70
// pdb: hkpWorldOperationUtil::splitSimulationIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: world, currentIsland
void __cdecl PropagateStateToChildren(Object* object, int* apNode)
{
    IslandNode* node = (IslandNode*)apNode;
    unsigned char uiLowState = node->state & 3;
    IslandList* list;
    if (uiLowState != 0)
        list = &((IslandNode*)object)->first;
    else
        list = &((IslandNode*)object)->second;
    node->flags &= 0xfc;
    int initialIndex = list->count;
    hkpWorldOperationUtil_splitSimulationIsland(node, object, list, 0);
    unsigned char uiHighState = (node->state >> 2) & 3;
    int currentIndex = initialIndex;
    while (currentIndex < list->count)
    {
        IslandNode* item = list->items[currentIndex];
        item->highState = uiLowState;
        item->lowState = uiLowState;
        if (uiLowState != 0 && uiHighState == 0)
            AddItemToContainer(object, item);
        item->index = (unsigned char)(node->index - initialIndex + currentIndex);
        ++currentIndex;
    }
}

#include <windows.h>
namespace fnv_00cb5480 {
// Lock-guarded append of a pointer item into the list at this+0x40.
// Clears flag bits on the item, and if its word slot is 0xffff, stamps the
// current count into it and appends the item (growing via the allocator).

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

extern "C" AllocHolder* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, int iStride);

struct ListItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    unsigned short m_w22;
    unsigned short unk24;
    unsigned char m_b26;
};

}  // namespace fnv_00cb5480

struct Cb4890_Elem
{
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
    unsigned short unk0e8;
    unsigned short m_ea;
    unsigned short m_ec;
};
struct Cb4890_ElemArray
{
    Cb4890_Elem** m_data;
    int m_iElementCount;
};
struct Cb4890_IntArray
{
    int* m_data;
    int m_iElementCount;
};
struct Cb4890_CharArray
{
    char* m_data;
    int m_iElementCount;
};
struct Cb4890_Stack
{
    char* m_next;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb4890_LocalBuffer
{
    T* m_p;
    int m_iElementCount;
    __forceinline Cb4890_LocalBuffer(int n) throw()
    {
        m_p = (T*)((Cb4890_Stack*)FUN_00c85750())->allocateStack(n * (int)sizeof(T));
    }
    __forceinline ~Cb4890_LocalBuffer() throw()
    {
        ((Cb4890_Stack*)FUN_00c85750())->deallocateStack(m_p);
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_p[i];
    }
};
struct Cb4890_Owner
{
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
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
struct Cb4890_RemapTable
{
    Cb4890_IntArray* m_entries;
    int m_iElementCount;
    void RemapAndAccumulate(Cb4890_LocalBuffer<int>& map, int count, Cb4890_IntArray* src) throw();
};
template <class T> __forceinline T Cb4890_max2(T a, T b)
{
    return a > b ? a : b;
}

__forceinline int RemapOne(Cb4890_LocalBuffer<int>& used, int* mapped, Cb4890_CharArray* out, int i, int count)
{
    if (used[i])
        mapped[i] = 0;
    else
    {
        mapped[i] = count;
        out->m_data[count] = 0;
        count++;
    }
    return count;
}
// Marks entries used by list elements whose decoded m_ea and m_ec are both at most 5, renumbers the rest via RemapOne, then calls RemapAndAccumulate unless k > n.
// @f3 0x009274b0 (community match, verified in this file)
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
namespace f3m_009274b0 {
struct ThreadMemory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* allocateStackSlow(int nbytes);
    virtual void deallocateStackSlow(void* p);
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    char* m_stackCurrent;
    int unk24;
    char* m_stackSlowBase;
    char* m_stackEnd;
    static ThreadMemory& getInstance() throw()
    {
        return *static_cast<ThreadMemory*>(DAT_00d9b080(DAT_010f3170));
    }
    __forceinline void* allocateStack(int nbytes) throw()
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        char* next = current + nbytes;
        if (next <= m_stackEnd)
        {
            m_stackCurrent = next;
            return current;
        }
        return allocateStackSlow(nbytes);
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackSlowBase)
            deallocateStackSlow(p);
    }
};
struct LocalBuffer
{
    int* m_p;
    int m_size;
    __forceinline LocalBuffer(int n) throw() { m_p = (int*)ThreadMemory::getInstance().allocateStack(n * (int)sizeof(int)); }
    __forceinline ~LocalBuffer() throw() { int* p = m_p; ThreadMemory::getInstance().deallocateStack(p); }
    __forceinline int& operator[](int i) throw() { return m_p[i]; }
};
struct Elem { char pad[0xda]; unsigned short m_da; unsigned short m_dc; };
struct Owner { char pad[0x2c5]; unsigned char m_2c5; unsigned char m_2c6; };
struct List { Elem** m_data; int m_iElementCount; };
template <class T> __forceinline T max2(T a, T b) { return a > b ? a : b; }
}

// pdb: hkpWorldOperationUtil::removeAttachedActionsFromFixedIsland | hkpWorldOperationUtil.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: world, entity, actionsToBeMoved
static __declspec(noinline) void RemapElements(const Cb4890_ElemArray& remapArg, Cb4890_RemapTable* listArg,
                                               Cb4890_Owner* ownerArg, Cb4890_IntArray* src, Cb4890_CharArray* out)
{
    Cb4890_RemapTable& remap = *(Cb4890_RemapTable*)&remapArg;
    f3m_009274b0::List* list = (f3m_009274b0::List*)listArg;
    f3m_009274b0::Owner* owner = (f3m_009274b0::Owner*)ownerArg;
    int n = src->m_iElementCount;
    f3m_009274b0::LocalBuffer used(n);
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int j = 0; j < list->m_iElementCount; j++)
    {
        const f3m_009274b0::Elem* e = list->m_data[j];
        int a = e->m_dc;
        if (owner->m_2c6 == (a >> 14))
            a = (a >> 7) & 0x7f;
        else
            a &= 0x7f;
        int b = e->m_da;
        if (owner->m_2c5 == (b >> 14))
            b = (b >> 7) & 0x7f;
        else
            b &= 0x7f;
        if (f3m_009274b0::max2(b & 0x7f, a & 0x7f) <= 5)
            used[remap.m_entries->m_data[j]] = 1;
    }
    int* remapOut = used.m_p;
    int k = 1;
    out->m_data[0] = 1;
    for (int i = 0; i < n; i++)
        k = RemapOne(*(Cb4890_LocalBuffer<int>*)&used, remapOut, out, i, k);
    if (k > n)
        out->m_data[0] = 0;
    else
        remap.RemapAndAccumulate(*(Cb4890_LocalBuffer<int>*)&used, k, src);
}


volatile int g_cb4890[5];
void Cb4890_caller()
{
    RemapElements(*(Cb4890_ElemArray*)g_cb4890[0], (Cb4890_RemapTable*)g_cb4890[1], (Cb4890_Owner*)g_cb4890[2],
                  (Cb4890_IntArray*)g_cb4890[3], (Cb4890_CharArray*)g_cb4890[4]);
}

struct S00cb5100_WBits
{
    unsigned short lo : 14;
    unsigned short hi : 2;
};
struct S00cb5100_Bits
{
    unsigned char lo : 2;
    unsigned char hi : 6;
};
struct S00cb5100_Body;
struct S00cb5100_Ent
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
    S00cb5100_Body* owner_cc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char unke8;
    union
    {
        unsigned char be9;
        S00cb5100_Bits bits9;
    };
    union
    {
        unsigned short wea;
        S00cb5100_WBits bea;
    };
    union
    {
        unsigned short wec;
        S00cb5100_WBits bec;
    };
    unsigned short unkee;
    int unkf0;
    void FUN_00c90510();
    void FUN_00c905b0();
    void setFilter(int a0, int a1, int a2)
    {
        if ((unsigned int)(a2 & 3) < (unsigned int)(be9 & 3))
            a0 = (~a0) << 14;
        else
            a0 <<= 14;
        if (a2 < be9)
            a1 = (~a1) << 14;
        else
            a1 <<= 14;
        wea = (unsigned short)((wea & 0x3fff) | a0);
        wec = (unsigned short)((wec & 0x3fff) | a1);
    }
};
struct S00cb5100_Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int f1c;
    unsigned short idx20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned char flags26;
    unsigned char unk27;
    int unk28;
    int unk2c;
    float f30;
    float f34;
    int unk38;
    int unk3c;
    int unk40;
    float f44;
    S00cb5100_Ent** list48;
    int count4c;
};
void ResizeAudioStream(void* heap, void* arr, int elemSize);
struct S00cb5100_Arr
{
    S00cb5100_Body** m_data;
    int m_iElementCount;
    int m_cap;
    S00cb5100_Body* pick(int* n, S00cb5100_Body** b, int k);
    void AddBack(S00cb5100_Body* const& e)
    {
        S_00c6aca0_Router* r = FUN_00c85750();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->m10, this, 4);
        S00cb5100_Body** out = m_data + m_iElementCount;
        for (int k = 0; k < 1; ++k)
            out[k] = e;
        ++m_iElementCount;
    }
};
void FUN_00cf1480(float a, float b, void* p);
void hkpWorldAgentUtil_warpTime(S00cb5100_Body* b, float f, float g, int h);
struct S00cb5100_World
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
    S00cb5100_Arr arr28;
    S00cb5100_Body** data34;
    int size38;
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
    float f1d0;
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
    unsigned char unk304;
    unsigned char b305;
    unsigned char b306;
    union
    {
        unsigned char b307;
        S00cb5100_Bits bits307;
    };
};

void ProcessSceneCallbacks(S00cb5100_World* w, S00cb5100_Body* b);

static __declspec(noinline) S00cb5100_Body* FindItemForThreshold(S00cb5100_World* w, S00cb5100_Arr* arr, int n,
                                                                 S00cb5100_Body* b)
{
    if (w->size38 == 0 || arr->m_iElementCount == 0)
        return 0;
    return arr->pick(&n, &b, w->size38);
}

static inline bool S00cb5100_lt(unsigned char a, unsigned char b)
{
    return a < b;
}

// Moves b from w's data34 list to arr28, resets its entries, then merges it with another body via FUN_00cb4c60 if merge allows, else may swap it to the front.
// @f3 0x00926c70 (community match, verified in this file)
// The fixed boundary symbol uses stand-ins shared with a different, longer routine.
// Keep those declarations intact and name the native layouts used by this implementation.
struct IslandEntity926c70
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
    unsigned char unkd8;
    unsigned char bd9;
    unsigned short wda;
    unsigned short wdc;
    unsigned short unkde;
    int unke0;
    void setFilter(int a0, int a1, int a2);
};

struct IslandWorld926c70
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
    S00cb5100_Arr arr28;
    S00cb5100_Body** data34;
    int size38;
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
    float f190;
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
    unsigned char unk2c4;
    unsigned char b2c5;
    unsigned char b2c6;
    unsigned char b2c7;
};

inline void IslandEntity926c70::setFilter(int a0, int a1, int a2)
{
    if ((unsigned int)(a2 & 3) < (unsigned int)(bd9 & 3))
        a0 = (~a0) << 14;
    else
        a0 <<= 14;
    if (a2 < bd9)
        a1 = (~a1) << 14;
    else
        a1 <<= 14;
    wda = (unsigned short)((wda & 0x3fff) | a0);
    wdc = (unsigned short)((wdc & 0x3fff) | a1);
}


void __cdecl FUN_00901f10(S00cb5100_Arr* apArray, int aiElemSize);


// pdb: hkpWorldOperationUtil::internalActivateIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void hkpWorldOperationUtil_internalActivateIsland(S00cb5100_World* originalWorld, S00cb5100_Body* apBody, bool merge)
{
    IslandWorld926c70* apWorld = reinterpret_cast<IslandWorld926c70*>(originalWorld);
    apWorld->data34[apBody->idx20] = apWorld->data34[apWorld->size38 - 1];
    apWorld->data34[apBody->idx20]->idx20 = apBody->idx20;
    apWorld->size38--;

    S00cb5100_Arr* arr = &apWorld->arr28;
    if (arr->m_iElementCount == (arr->m_cap & 0x3fffffff))
        FUN_00901f10(arr, 4);
    arr->m_data[arr->m_iElementCount] = apBody;
    arr->m_iElementCount++;

    apBody->idx20 = (unsigned short)(apWorld->arr28.m_iElementCount - 1);
    apBody->f30 = 0.0f;
    apBody->f34 = 0.0f;
    apBody->flags26 = (apBody->flags26 & ~2) | 1;

    for (int i = 0; i < apBody->count4c; i++)
    {
        IslandEntity926c70* e = reinterpret_cast<IslandEntity926c70*>(apBody->list48[i]);
        FUN_00cf1480(0.0f, 0.0f, &e->unke0);
        e->wda = 0;
        e->wdc = 0;
        e->setFilter(apWorld->b2c5, apWorld->b2c6, apWorld->b2c7);
    }

    hkpWorldAgentUtil_warpTime(apBody, apBody->f44, apWorld->f190, apWorld->unk6c);
    unsigned int idx = apBody->idx20;
    if (idx != 0)
    {
        S00cb5100_Body* first = arr->m_data[0];
        if (apBody->count4c > first->count4c)
        {
            apBody->idx20 = 0;
            first->idx20 = (unsigned short)idx;
            arr->m_data[0] = apBody;
            arr->m_data[idx] = first;
        }
    }
    ProcessSceneCallbacks(originalWorld, apBody);
}


#include <xmmintrin.h>

struct C6A870_Child
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044, f048, f04c, f050, f054, f058, f05c;
    int f060, f064, f068, f06c, f070, f074, f078, f07c;
    int f080, f084, f088, f08c, f090, f094, f098, f09c;
    int f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc;
    int f0c0, f0c4, f0c8, f0cc, f0d0, f0d4, f0d8, f0dc;
    int f0e0, f0e4, f0e8, f0ec, f0f0, f0f4, f0f8, f0fc;
    int f100, f104, f108, f10c, f110, f114, f118, f11c;
    int f120, f124, f128, f12c, f130, f134, f138, f13c;
    int f140, f144, f148, f14c, f150, f154, f158, f15c;
    int f160, f164, f168, f16c, f170, f174, f178, f17c;
    int f180, f184, f188, f18c, f190, f194, f198, f19c;
    int f1a0, f1a4, f1a8, f1ac;
    __m128 m_vLinearConstraint;
    __m128 m_vAngularConstraint;
};

struct C6A870_Item
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044;
    C6A870_Child** m_children;
    int m_uiItemCount;
};

struct C6A870_Heap;
typedef void*(__thiscall* C6A870_AllocFn)(C6A870_Heap*, int&);
typedef void(__thiscall* C6A870_FreeFn)(C6A870_Heap*, void*, int);
struct C6A870_HeapTable
{
    void* v00;
    void* v04;
    void* v08;
    C6A870_AllocFn alloc;
    C6A870_FreeFn free;
};
struct C6A870_Heap
{
    C6A870_HeapTable* table;
    __forceinline void* AllocateBufferWithSize(int& numBytes)
    {
        return table->alloc(this, numBytes);
    }
    __forceinline void ReturnMemory(void* p, int n) throw()
    {
        table->free(this, p, n);
    }
    template <typename T> __forceinline T* _bufAlloc(int& n, int& numBytes)
    {
        C6A870_AllocFn alloc = table->alloc;
        numBytes = n * int(sizeof(T));
        void* p = alloc(this, numBytes);
        n = numBytes / int(sizeof(T));
        return (T*)p;
    }
};

__forceinline C6A870_Heap& c6a870Heap()
{
    return *(C6A870_Heap*)&FUN_00c85750()->heap();
}

template <typename T> __forceinline void c6a870Copy(T* dst, const T* src, int n)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <typename T> struct C6A870_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline C6A870_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~C6A870_Array() throw()
    {
        _clearAndDeallocate(c6a870Heap());
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(C6A870_Heap& h) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _copyFromArray(C6A870_Heap& h, const C6A870_Array& a, int& scratch)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                h.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = a.GetLogicalSize();
            m_data = h._bufAlloc<T>(n, scratch);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        c6a870Copy(m_data, a.m_data, m_iElementCount);
    }
    __forceinline C6A870_Array& assign(const C6A870_Array& a, int& scratch)
    {
        _copyFromArray(c6a870Heap(), a, scratch);
        return *this;
    }
};

struct C6A870_World
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024;
    C6A870_Array<C6A870_Item*> m_items;
};

void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(C6A870_World* world);
void __cdecl AddItemToContainer(C6A870_World* world, C6A870_Item* item);

struct C6A870_Self;
typedef C6A870_World*(__thiscall* C6A870_Query)(C6A870_Self*);

struct C6A870_Self
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
    virtual C6A870_World* getWorld();

    void FUN_00c6a870();
};

struct Motion4120
{
    virtual void unused();
    unsigned short storageSize, refCount;
    unsigned char kind, counter;
    unsigned short inactive[2];
    __forceinline int frames(int slot, int flag)
    {
        int packed = inactive[slot];
        int mode = packed >> 14;
        int n;
        if (flag != mode)
        {
            n = packed & 127;
        }
        else
        {
            n = (packed >> 7) & 127;
        }
        return n & 127;
    }
};

struct Entry4120
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

    unsigned short countB0;
    unsigned short unkb2;
    unsigned short unkb4;
    unsigned short unkb6;

    unsigned short unkb8;
    unsigned short unkba;
    unsigned short unkbc;
    unsigned short unkbe;

    unsigned short unkc0;
    unsigned short unkc2;
    unsigned short unkc4;
    unsigned short unkc6;

    unsigned short unkc8;
    unsigned short unkca;
    unsigned short unkcc;
    unsigned short unkce;

    unsigned short unkd0;
    unsigned short unkd2;
    unsigned short unkd4;
    unsigned short unkd6;

    unsigned short unkd8;
    unsigned short unkda;
    unsigned short unkdc;
    unsigned short unkde;

    Motion4120 motion;
    __forceinline Motion4120* movement()
    {
        return &motion;
    }
};
template <class T> struct View4120
{
    T* data;
    int count;
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline int size() const
    {
        return count;
    }
};
struct Groups4120
{
    View4120<int>& groups;
    int n;
};
template <class T> __forceinline T greater4120(T a, T b)
{
    return a > b ? a : b;
}

// Iterates entries, marks active groups when motion frames are 5 or fewer, and accumulates per-group size counts.
// @f3 0x00926a50 (community match, verified in this file)
// pdb: findInactiveGroupsAndEstimateSolverSize | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void UpdateGroupActivity(const Groups4120& map, const View4120<Entry4120*>& entries,
                                                     int unusedGroups, View4120<int>& active, View4120<int>& sizes,
                                                     unsigned char* flags)
{
    for (int i = 0; i < entries.size(); ++i)
    {
        Entry4120* entity = entries[i];
        int group = map.groups[i];
        int frames = greater4120(reinterpret_cast<Motion4120*>(&entity->unkd0)->frames(0, flags[0]), reinterpret_cast<Motion4120*>(&entity->unkd0)->frames(1, flags[1]));
        if (frames <= 5)
        {
            active[group] = 1;
        }
        int count = greater4120(1, (int)*reinterpret_cast<const unsigned short*>(&entity->unk9c));
        sizes[group] += count;
    }
}


extern const Groups4120* volatile inputMap4120;
extern const View4120<Entry4120*>* volatile inputEntities4120;
extern View4120<int>* volatile outputActive4120;
extern View4120<int>* volatile outputSizes4120;
extern unsigned char* volatile inputFlags4120;
extern int volatile groupCount4120;
void caller4120()
{
    UpdateGroupActivity(*inputMap4120, *inputEntities4120, groupCount4120, *outputActive4120, *outputSizes4120,
                        inputFlags4120);
}

struct Inner;
struct CallA
{
    signed char delta;
    void UpdateCollisionIndices();
    void CopyAndSortGeometryList(void* p);
};
struct Mgr2
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    unsigned char unk24;
    bool splitRequested : 2;
    bool sparseEnabled : 2;
    bool cleanup : 2;
    bool inActive : 2;
    unsigned char unk26, unk27;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int m_4c;
    int unk050;
    int unk054;
    int m_58;
    __forceinline void mark()
    {
        splitRequested = true;
    }
    __forceinline int count() const
    {
        return m_4c;
    }
};
struct MotionObj
{
    void* vt;
    int unk04;
    Inner* m_08;
    int unk0c;
    CallA collidable;
    unsigned char unk11, unk12, unk13;
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
    Mgr2* m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8, unke9, unkea, unkeb;
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
    int m_1f8;
};
struct Inner
{
    int unk00, unk04;
    MotionObj* m_08;
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
    int m_8c, m_90, m_94, unk98;
    unsigned char m_9c, m_9d, unk9e, unk9f;
    int m_a0, m_a4;
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
    float m_1d0;
};
typedef void(__thiscall* FnFree)(void* self, void* p, int bytes);
typedef void(__thiscall* Fn20)(void* self, void* p, int a, void* b, int c);

void hkpWorldOperationUtil_removeEntitySI(Inner* s, MotionObj* a0);
void hkpWorldOperationUtil_addConstraintImmediately(Inner* s, void* e, int z);
struct ModeBool
{
    bool value;
    ModeBool()
    {}
    ModeBool(bool b) : value(b)
    {}
    ModeBool(const ModeBool& b) : value(b.test())
    {}
    void set(bool b)
    {
        static_cast<volatile bool&>(value) = b;
    }
    bool test() const
    {
        return value;
    }
    operator bool() const
    {
        return test();
    }
};
void FUN_00cb4640(Inner* s, int a5, int a7);
void FUN_00cff290(void* m, void* w);
void hkpWorldOperationUtil_mergeIslands(Inner* in, MotionObj* a0, MotionObj* e);
void UpdateRotationInterpolation(float f, void* p);
struct Elem8
{
    int f0;
    MotionObj* f4;
};
struct VecC
{
    Elem8* data;
    int size;
    int cap;
    VecC() : data(0), size(0), cap((int)0x80000000)
    {}
};

struct S00cb4230_Vec4
{
    float& operator()(int a)
    {
        return reinterpret_cast<float*>(m_vComponents)[a];
    }
    const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(m_vComponents)[a];
    }
    __declspec(align(16)) float m_vComponents[4];
};
struct S00cb4230_Quat
{
    S00cb4230_Quat()
    {}
    S00cb4230_Vec4 m_vec;
};
struct InertiaTensor
{
    InertiaTensor()
    {}
    S00cb4230_Vec4 m_kColumn0;
    S00cb4230_Vec4 m_kColumn1;
    S00cb4230_Vec4 m_kColumn2;
};
struct S00cb4230_Rotation : InertiaTensor
{
    S00cb4230_Rotation()
    {}
};
struct S00cb4230_Transform
{
    S00cb4230_Transform()
    {}
    S00cb4230_Rotation m_rotation;
    S00cb4230_Vec4 m_vTranslation;
    const S00cb4230_Vec4& getTranslation() const
    {
        return m_vTranslation;
    }
};
struct S00cb4230_Swept
{
    S00cb4230_Swept()
    {}
    float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
    float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    S00cb4230_Vec4 m_vCenterOfMass0;
    S00cb4230_Vec4 m_vCenterOfMass1;
    S00cb4230_Quat m_qRotation0;
    S00cb4230_Quat m_qRotation1;
    S00cb4230_Vec4 m_vCenterOfMassLocal;
};
extern float DAT_010c7948[];
struct S00cb4230_UFloat8
{
    S00cb4230_UFloat8()
    {}
    operator float() const
    {
        return DAT_010c7948[m_uiFilterValue];
    }
    unsigned char m_uiFilterValue;
};
struct S00cb4230_MotionStateData
{
    S00cb4230_MotionStateData()
    {}
    S00cb4230_Transform& getTransform()
    {
        return m_kMotionTransform;
    }
    const S00cb4230_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
    S00cb4230_Swept& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    const S00cb4230_Swept& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    void FUN_00c86660(void* p);
    S00cb4230_Transform m_kMotionTransform;
    S00cb4230_Swept m_kSweptTransform;
    S00cb4230_Vec4 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    S00cb4230_UFloat8 m_fSurfaceFriction;
    S00cb4230_UFloat8 m_fRestitution;
    short m_uiDeactivationClass;
};
struct MotionFlag31
{
    inline MotionFlag31()
    {}
    inline MotionFlag31(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline MotionFlag31 operator==(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) == static_cast<int>(e);
    }
    inline MotionFlag31 operator!=(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) != static_cast<int>(e);
    }

  private:
    char m_cBooleanValue;
};
enum S00cb4230_MotionType
{
    S00cb4230_INVALID,
    S00cb4230_DYNAMIC,
    S00cb4230_SPHERE,
    S00cb4230_BOX,
    S00cb4230_KEYFRAMED,
    S00cb4230_FIXED
};
template <typename E, typename S> struct S00cb4230_Enum
{
    S00cb4230_Enum()
    {}
    S00cb4230_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    S m_kStorage;
};
struct AllocObj
{
    virtual void v00();
    virtual void* v01(int size);
};
struct MotionState;
struct S00cb4230_FinishFlag
{
    S00cb4230_FinishFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
struct S00cb4230_Half
{
    S00cb4230_Half()
    {}
    void operator=(const float& f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = short(t >> 16);
    }
    short m_uiFilterValue;
};
struct S00cb4230_BaseObject
{
    S00cb4230_BaseObject()
    {}
    virtual void v00();
};
struct RefHeader31 : S00cb4230_BaseObject
{
    RefHeader31(S00cb4230_FinishFlag flag)
    {}
    unsigned short m_04;
    mutable short m_06;
};
struct MotionBase : RefHeader31
{
    MotionBase(S00cb4230_FinishFlag flag) : RefHeader31(flag)
    {
        if (flag.m_bFinishing)
        {
            m_fGravityFactor = 1.f;
        }
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void GetInverseScaleMatrix(InertiaTensor& out) const;
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
    virtual void v25(MotionState* p);
    virtual void v26();
    virtual void v27(MotionState* p);
    S00cb4230_MotionType getType() const
    {
        return m_type;
    }
    S00cb4230_MotionStateData* GetMotionState()
    {
        return &m_kMotionState;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return m_kMotionState.getTransform().getTranslation();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return m_kMotionState.getSweptTransform().m_qRotation1;
    }
    const S00cb4230_Vec4& getCenterOfMassLocal() const
    {
        return m_kMotionState.getSweptTransform().m_vCenterOfMassLocal;
    }
    float getLinearDamping()
    {
        return m_kMotionState.m_fLinearDamping;
    }
    float getAngularDamping()
    {
        return m_kMotionState.m_fAngularDamping;
    }
    void setLinearDamping(float d)
    {
        m_kMotionState.m_fLinearDamping = d;
    }
    void setAngularDamping(float d)
    {
        m_kMotionState.m_fAngularDamping = d;
    }
    S00cb4230_Enum<S00cb4230_MotionType, unsigned char> m_type;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_MotionStateData m_kMotionState;
    S00cb4230_Vec4 m_kInertiaAndMassInv;
    S00cb4230_Vec4 m_kTranslationalVelocity;
    S00cb4230_Vec4 m_kAngularVelocity;
    S00cb4230_Vec4 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    MotionState* m_118;
    short m_11c;
    S00cb4230_Half m_fGravityFactor;
    void FUN_00c905b0();
    void FUN_00d1dff0();
    void hkpMotion_setWorldSelectFlagsNeg(int a, int b, int c);
    void FUN_00c86610(MotionBase* p);
    float hkpMotion_getMass();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        S_00c6aca0_Heap& h = FUN_00c85750()->heap();
        RefHeader31* b = static_cast<RefHeader31*>(((AllocObj*)&h)->v01(static_cast<int>(nbytes)));
        b->m_04 = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct S00cb4230_Keyframed : MotionBase
{
    S00cb4230_Keyframed() : MotionBase(S00cb4230_FinishFlag())
    {
        m_118 = 0;
    }
    S00cb4230_Keyframed(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct MotionState : S00cb4230_Keyframed
{
    MotionState() : S00cb4230_Keyframed()
    {}
};
struct S00cb4230_String
{
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
        unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
        {
            do
            {
                dst32[0] = src32[0];
                dst32[1] = src32[1];
                dst32[2] = src32[2];
                dst32[3] = src32[3];
                dst32 += 4;
                src32 += 4;
            } while (--numQuads > 0);
        }
    }
};
enum S00cb4230_Quality
{
    S00cb4230_QUALITY_FIXED,
    S00cb4230_QUALITY_KEYFRAMED
};
struct S00cb4230_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    char m_auiShapeKeys;
    int m_iFilter;
};
struct S00cb4230_Collidable
{
    const void* getShape() const
    {
        return m_pCollisionShape;
    }
    S00cb4230_Handle* getBroadPhaseHandle()
    {
        return &m_kBroadPhaseHandle;
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(m_kBroadPhaseHandle.m_ucObjectQualityType);
    }
    void setMotionState(const S00cb4230_MotionStateData* s)
    {
        m_pMotionState = s;
    }
    const void* m_pCollisionShape;
    int m_14;
    const void* m_pMotionState;
    int m_1c;
    int m_20;
    S00cb4230_Handle m_kBroadPhaseHandle;
};
struct ThisObj
{
    int m_00;
    int m_04;
    unsigned char m_08;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_Collidable m_kCollidable;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    float m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    unsigned char m_bc;
    unsigned char m_bd;
    short m_be;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    MotionState m_pMotionState;
    int m_200;
    int m_204;
    MotionBase* getMotion()
    {
        return &m_pMotionState;
    }
    MotionBase* getRigidMotion() const
    {
        return const_cast<MotionBase*>(static_cast<const MotionBase*>(&m_pMotionState));
    }
    const S00cb4230_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    S00cb4230_Collidable* getCollidableRw()
    {
        return &m_kCollidable;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(getCollidable()->getQualityType());
    }
    void setQualityType(S00cb4230_Quality type)
    {
        getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType = char(type);
    }
    void UpdateBoundingVolume(void* a, const void* b);
};
void __cdecl UpdateRotationInterpolation(float f, S00cb4230_MotionStateData* p);

struct MergeWorld
{
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
    unsigned char state0;
    bool enabled;
    unsigned char state2;
    unsigned char state3;
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
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
union MergeListArg
{
    Cb4890_ElemArray* value;
};
static __forceinline void tallyActive(Cb4890_RemapTable* remap_, Cb4890_ElemArray*& list, int n,
                                      Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt, MergeWorld* owner,
                                      Cb4890_ElemArray* const volatile& home) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++, list = home)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        int a = Dec(e->m_ec, owner->m_306);
        int b = Dec(e->m_ea, owner->m_305);
        int am = a & 0x7f;
        int bm = b & 0x7f;
        int mx = (bm > am) ? bm : am;
        if (mx <= 5)
            map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}

static __forceinline void tallyAll(Cb4890_RemapTable* remap_, Cb4890_ElemArray* list, int n,
                                   Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
// Tallies element weights per remap index, then greedily packs them into output slots bounded by owner->unk0b4 and calls RemapAndAccumulate.
// @f3 0x00927640 (community match, verified in this file)
namespace ns_00927640 {

struct MW_World
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c;
    int unk0a0;
    int m_threshold;
    int unk0a8, unk0ac, unk0b0, unk0b4;
    int unk0b8, unk0bc, unk0c0;
    unsigned char unk0c4;
    bool enabled;
    unsigned char unk0c6, unk0c7;
    int unk0c8, unk0cc, unk0d0, unk0d4;
    int unk0d8, unk0dc, unk0e0, unk0e4;
    int unk0e8, unk0ec, unk0f0, unk0f4;
    int unk0f8, unk0fc, unk100, unk104;
    int unk108, unk10c, unk110, unk114;
    int unk118, unk11c, unk120, unk124;
    int unk128, unk12c, unk130, unk134;
    int unk138, unk13c, unk140, unk144;
    int unk148, unk14c, unk150, unk154;
    int unk158, unk15c, unk160, unk164;
    int unk168, unk16c, unk170, unk174;
    int unk178, unk17c, unk180, unk184;
    int unk188, unk18c, unk190, unk194;
    int unk198, unk19c, unk1a0, unk1a4;
    int unk1a8, unk1ac, unk1b0, unk1b4;
    int unk1b8, unk1bc, unk1c0, unk1c4;
    int unk1c8, unk1cc, unk1d0, unk1d4;
    int unk1d8, unk1dc, unk1e0, unk1e4;
    int unk1e8, unk1ec, unk1f0, unk1f4;
    int unk1f8, unk1fc, unk200, unk204;
    int unk208, unk20c, unk210, unk214;
    int unk218, unk21c, unk220, unk224;
    int unk228, unk22c, unk230, unk234;
    int unk238, unk23c, unk240, unk244;
    int unk248, unk24c, unk250, unk254;
    int unk258, unk25c, unk260, unk264;
    int unk268, unk26c, unk270, unk274;
    int unk278, unk27c, unk280, unk284;
    int unk288, unk28c, unk290, unk294;
    int unk298, unk29c, unk2a0, unk2a4;
    int unk2a8, unk2ac, unk2b0, unk2b4;
    int unk2b8, unk2bc, unk2c0;
    unsigned char unk2c4;
    unsigned char m_2c5;
    unsigned char m_2c6;
};

struct MW_Elem
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098;
    unsigned short m_weight;
    int unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc;
    int unk0d0, unk0d4;
    unsigned short unk0d8;
    unsigned short m_da;
    unsigned short m_dc;
};

struct MW_ThreadMemory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* allocateStackSlow(int nbytes);
    virtual void deallocateStackSlow(void* p);
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    char* m_stackCurrent;
    int unk24;
    char* m_stackSlowBase;
    char* m_stackEnd;
    static MW_ThreadMemory& getInstance() throw()
    {
        return *static_cast<MW_ThreadMemory*>(DAT_00d9b080(DAT_010f3170));
    }
    __forceinline void* allocateStack(int nbytes) throw()
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        char* next = current + nbytes;
        if (next <= m_stackEnd)
        {
            m_stackCurrent = next;
            return current;
        }
        return allocateStackSlow(nbytes);
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackSlowBase)
            deallocateStackSlow(p);
    }
};
struct MW_LocalBuffer
{
    int* m_p;
    int m_size;
    __forceinline MW_LocalBuffer(int n) throw() { m_p = (int*)MW_ThreadMemory::getInstance().allocateStack(n * (int)sizeof(int)); }
    __forceinline ~MW_LocalBuffer() throw() { }
    __forceinline int& operator[](int i) throw() { return m_p[i]; }
};

// Guess: the list re-read from its parameter slot at the latch through the volatile `home` reproduces the original's
// reload of the element list from its parameter slot (the original most likely took the list by reference).
static __forceinline void tallyActive(int& remap_, Cb4890_ElemArray*& list, int n,
                                      MW_LocalBuffer& map, MW_LocalBuffer& cnt,
                                      MW_World* owner, Cb4890_ElemArray* const volatile& home) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++, list = home)
    {
        MW_Elem* e = (MW_Elem*)list->m_data[i];
        int idx = ((Cb4890_RemapTable*)remap_)->m_entries->m_data[i];
        int a = e->m_dc;
        if (owner->m_2c6 == (a >> 14))
            a = (a >> 7) & 0x7f;
        else
            a &= 0x7f;
        int b = e->m_da;
        if (owner->m_2c5 == (b >> 14))
            b = (b >> 7) & 0x7f;
        else
            b &= 0x7f;
        int m = f3m_009274b0::max2(b & 0x7f, a & 0x7f);
        // Guess: the redundant `remap_ <= 0 ||` term. Both paths end in the same `m <= 5` test, so after register
        // allocation only one compare remains (no code of its own), but remap_ stays a register candidate in this loop
        // while registers are assigned; that decides the order of the four reloads at the merge loop's inner exit.
        if ((remap_ <= 0 || m <= 5) && m <= 5)
            map[idx] = 1;
        int w = f3m_009274b0::max2(1, (int)e->m_weight);
        cnt[idx] += w;
    }
}

static __forceinline void tallyAll(int& remap_, Cb4890_ElemArray* list, int n,
                                   MW_LocalBuffer& map, MW_LocalBuffer& cnt) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        MW_Elem* e = (MW_Elem*)list->m_data[i];
        int idx = ((Cb4890_RemapTable*)remap_)->m_entries->m_data[i];
        map[idx] = 1;
        int w = f3m_009274b0::max2(1, (int)e->m_weight);
        cnt[idx] += w;
    }
}

}
using namespace ns_00927640;
// pdb: identifyDeactivatedSubgroups | hkpWorldOperationUtil.obj | fnv360_0822_debug, objrun_open, low
void FUN_00cb49e0(MergeWorld* ownerArg, int remap_, MergeListArg listArg, Cb4890_IntArray* src, Cb4890_CharArray* out)
{
    // Guess (kept from the stored drafts): a dead address-take of listArg. It keeps the list parameter in its home slot
    // (its slot is not reused by the merge loop's cursor, and list is loaded in the prologue as in the original). No
    // natural spelling found: a const or volatile reference to listArg.value gives the prologue loads in another order.
    MergeListArg* volatile vp; if (0) vp = &listArg;
    // Guess: the table parameter used through a named reference at the call (code-neutral; it keeps remap_ in its
    // parameter slot for the allocator, as the volatile view of remap_ in the enabled loop did in the stored drafts).
    int& table = remap_;
    MW_World* owner = (MW_World*)ownerArg;
    Cb4890_ElemArray* list = listArg.value;
    int n = src->m_iElementCount;
    MW_LocalBuffer cnt(n);
    Cb4890_ElemArray* activeList = list;
    MW_LocalBuffer map(n);

    for (int i = 0; i < n; i++)
    {
        map[i] = 0;
        cnt[i] = 0;
    }

    if (owner->enabled)
        tallyActive(remap_, activeList, n, map, cnt, owner, listArg.value);
    else
        tallyAll(remap_, list, n, map, cnt);

    for (int k = 0; k < n; k++)
    {
        if (map[k] == 0)
            cnt[k] = -1;
    }

    int pos = 0;
    int* pMap = map.m_p;
    for (int k = 0; k < n; k++)
    {
        int v = cnt[k];
        if (v == -2)
            continue;
        int p = pos++;
        out->m_data[p] = 0;
        pMap[k] = p;
        if (v < 0)
            continue;
        for (int j = k + 1; j < n; j++)
        {
            if (v + 10 >= owner->m_threshold)
                break;
            int w = cnt[j];
            if (w < 0)
                continue;
            if (v + w >= owner->m_threshold)
                continue;
            out->m_data[p] = 1;
            pMap[j] = p;
            v += w;
            cnt[j] = -2;
        }
    }

    ((Cb4890_RemapTable*)table)->RemapAndAccumulate(*(Cb4890_LocalBuffer<int>*)&map, pos, src);

    // The two LocalBuffer releases (map, then cnt) written out: the original most likely ran the buffers' destructors
    // through the TlsGetValue import (one import load kept in edi). That form compiles to the same code here, but f3check
    // shows the import operands unbound, so the unit's DAT_00d9b080 pointer is used through one local copy.
    int* pFree1 = map.m_p;
    void* (__stdcall *tls)(unsigned long) = DAT_00d9b080;
    MW_ThreadMemory* tm = (MW_ThreadMemory*)tls(DAT_010f3170);
    tm->deallocateStack(pFree1);
    int* pFree2 = cnt.m_p;
    tm = (MW_ThreadMemory*)tls(DAT_010f3170);
    tm->deallocateStack(pFree2);
}


namespace fnv_00cb5000 {
extern "C" void _ReadWriteBarrier(void);

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

Holder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* apAllocator, void* apVector, unsigned int auiElemSize);
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(int aCtx, int aObj, int aFlag);

}  // namespace fnv_00cb5000

struct S55Item;

template <typename T>

struct S55Array
{

    T* m_data;

    int m_iElementCount;

    int m_iCapacityState;

    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }

    __forceinline void popBack()
    {
        m_iElementCount--;
    }

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00c6aca0_Heap& a, int n);

    __forceinline void _setSize(S_00c6aca0_Heap& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
};

void __cdecl FUN_00c908c0(S_00c6aca0_Heap& a, void* array, int reqCapacity, int sizeElem);

template <typename T>

__forceinline void S55Array<T>::GrowArrayCapacity(S_00c6aca0_Heap& a, int n)

{

    const int capacity = getCapacity();

    if (capacity < n)
    {

        int cap2 = 2 * capacity;

        int newSize = (n < cap2) ? cap2 : n;

        FUN_00c908c0(a, this, newSize, sizeof(T));
    }
}

struct S55Item
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int m_1c;

    unsigned short unk20;

    unsigned short m_22;

    unsigned char unk24;

    unsigned char m_25;

    unsigned char m_26;

    unsigned char unk27;

    int unk28;

    int unk2c;

    int unk30;

    int unk34;

    S55Array<S55Item*> m_38;

    int unk44;

    ObjB** m_48;

    int m_4c;
};

struct S55Bool
{

    char m_cBooleanValue;

    S55Bool(bool b) : m_cBooleanValue(b)
    {}
};

struct S55Owner
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

    S55Array<S55Item*> m_28;

    int unk34;

    int unk38;

    int unk3c;

    S55Array<S55Item*> m_40;

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

    int m_b4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    unsigned char m_c8;

    void __thiscall FUN_00c910b0();
};

void __cdecl hkpWorldOperationUtil_internalActivateIsland(S55Owner* owner, S55Item* item, S55Bool b);

extern "C" void __cdecl hkpWorldOperationUtil_mergeIslands(S55Owner* owner, ObjB* first, ObjB* second);

// Sorts owner->m_40, then drains it by popping items, compacting their m_38 arrays, and applying state changes via hkpWorldOperationUtil_internalActivateIsland, FUN_00cb5310, or hkpWorldOperationUtil_mergeIslands.
// @f3 0x00927c80 (community match, verified in this file)
namespace f3m_00927c80 {
void __cdecl FUN_00990430(void** items, int low, int high, int (*less)(void*, void*));
int FUN_00926640(void*, void*);
void __cdecl FUN_00926c70(S55Owner* owner, S55Item* item);
void __cdecl FUN_00926df0(S55Owner* owner, S55Item* item);
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);

__forceinline void RemoveNulls(S55Array<S55Item*>& a)
{
    int w = -1;
    int i = 0;
    for (; i < a.m_iElementCount; i++)
    {
        if (a.m_data[i] == 0)
        {
            w = i;
            i++;
            break;
        }
    }
    for (; i < a.m_iElementCount; i++)
    {
        if (a.m_data[i] != 0)
        {
            a.m_data[w] = a.m_data[i];
            w++;
        }
    }
    if (w != -1)
    {
        int cap = a.m_iCapacityState & 0x3fffffff;
        if (cap < w)
        {
            int cap2 = cap * 2;
            FUN_00901e90(&a, w < cap2 ? cap2 : w, 4);
        }
        a.m_iElementCount = w;
    }
}
}
using namespace f3m_00927c80;

// pdb: hkpWorldOperationUtil::cleanupDirtyIslands | hkpWorldOperationUtil.obj | fnv360_0721_beta, call_seq + bridge(call_gap|call_gap), high
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(S55Owner* owner)
{
    if (owner->m_40.m_iElementCount > 1)
        FUN_00990430((void**)owner->m_40.m_data, 0, owner->m_40.m_iElementCount - 1, FUN_00926640);

    while (owner->m_40.m_iElementCount != 0)
    {
        S55Item* it = owner->m_40.back();
        owner->m_40.popBack();
        if (it != 0)
        {
            it->m_22 = (unsigned short)0xffff;
            if ((it->m_25 & 0x30) != 0)
            {
                RemoveNulls(it->m_38);
                it->m_25 &= 0xcf;
            }
            unsigned char f = it->m_26;
            unsigned char ns = (f >> 2) & 3;
            if (ns != (f & 3))
            {
                if (ns != 0) FUN_00926c70(owner, it);
                else FUN_00926df0(owner, it);
            }
        }
    }
}


extern "C" void _ReadWriteBarrier();

namespace fnv_00cb4640 {
struct TaskCtx;
struct TaskNode
{
    int unk00;
    unsigned short size04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    short index20;
    unsigned short unk22;
    unsigned char id24;
    unsigned char flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char low26 : 2;
            unsigned char high26 : 2;
            unsigned char upper26 : 4;
        };
    };
    unsigned char unk27;
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
    void FUN_00d07420(TaskCtx* arg);
    TaskNode* FUN_00d07830(TaskCtx* arg);
};
struct TaskList
{
    TaskNode** data;
    union
    {
        int count;
        struct
        {
            short countLow;
            short countHigh;
        };
    };
    int capacity;
};
struct TaskCtx
{
    int unk00;
    int unk04;
    TaskCtx* parent08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TaskNode* node20;
    int unk24;
    TaskList list28;
    TaskList list34;
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
    unsigned char enabledC8;
    unsigned char unkC9;
    unsigned short unkCA;
    int unkCC;
    int unkD0;
    unsigned char idD4;
    unsigned char unkD5;
    unsigned short unkD6;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char typeE8;
};

// Sets b's parent to a, then calls FUN_00d07420 with b on a node of a: node20 if b's type is 5, else one found or allocated in list28/list34 or list28's first.
// @f3 0x009266b0 (community match, verified in this file)
void __cdecl GrowTaskNodeList(void* list, int elemSize);

struct TaskThreadMemory
{
    TaskNode* alloc(int size, int memoryClass);
};

void __cdecl FUN_00cb4640(TaskCtx* apParent, TaskCtx* apChild, int mode)
{
    apChild->parent08 = apParent;
    if ((unsigned char)apChild->unkD8 == 7)
    {
        apParent->node20->FUN_00d07420(apChild);
        return;
    }
    TaskNode* node;
    if ((unsigned char)apParent->unkb8)
    {
        bool active = mode == 1;
        TaskList* list = active ? &apParent->list28 : &apParent->list34;
        if (active)
        {
            int i = list->count;
            int lowest = i - 10 < 0 ? 0 : i - 10;
            int count = i;
            for (--i; i >= lowest; --i)
            {
                TaskNode* item = list->data[i];
                int due = item->unk1c + 3;
                int next = item->unk4c + 1;
                if (next > due)
                    due = next;
                if ((item->flags26 & 0xc) && due < apParent->unka4)
                {
                    TaskNode* last = list->data[count - 1];
                    last->flags25 = (last->flags25 & ~8) | 4;
                    last->FUN_00d07420(apChild);
                    return;
                }
            }
        }
        TaskThreadMemory* mem = (TaskThreadMemory*)::TlsGetValue(::DAT_010f3170);
        TaskNode* raw = mem->alloc(0x6c, 0x32);
        raw->size04 = 0x6c;
        node = raw->FUN_00d07830(apParent);
        node->high26 = mode == 1;
        node->low26 = mode == 1;
        node->index20 = list->countLow;
        node->id24 = (unsigned char)node->index20;
        if (list->count == (list->capacity & 0x3fffffff))
            GrowTaskNodeList(list, 4);
        list->data[list->count] = node;
        ++list->count;
    }
    else
    {
        node = apParent->list28.data[0];
    }
    node->FUN_00d07420(apChild);
    node->id24 = (unsigned char)apChild->unkc0;
}


}
