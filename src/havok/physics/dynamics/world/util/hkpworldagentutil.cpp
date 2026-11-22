#include "f3_common.h"
// src/havok/physics/dynamics/world/util/hkpworldagentutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldagentutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00cc10b0_World
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
    int m_80;
};

struct S_00cc10b0_Island
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00cc10b0_World* m_pOwningWorld;
    int unk1c;
    int unk20;
    unsigned char unk24;
    unsigned char m_flags25;
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
    int unk50;
    int unk54;
    int m_58;

    void markForCheck()
    {
        m_flags25 = (m_flags25 & ~2) | 1;
    }
};

struct S_00cc10b0_Entity
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
    S_00cc10b0_Island* m_pCurrentSimulationIsland;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char m_bFlag;
    unsigned char unke9;
    unsigned short unkea;
};

struct S_00cc10b0_Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;

    S_00cc10b0_Entity* getOwner()
    {
        return (S_00cc10b0_Entity*)((char*)this + m_iOwnerOffset);
    }
};

struct S_00cc10b0_Listener
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
};

struct S_00cc10b0_Agent
{
    int unk00;
    int unk04;
    S_00cc10b0_Listener* m_kListener;
    int unk0c;
    S_00cc10b0_Collidable* m_pCollidableA;
    S_00cc10b0_Collidable* m_pCollidableB;
};

S_00cc10b0_Island* __cdecl PickIslandByValue(S_00cc10b0_Agent* agent, S_00cc10b0_Island* a, S_00cc10b0_Island* b);

// @f3 0x00944730 (community match, verified in this file)
struct S_00cc10b0_EntityF3
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
    S_00cc10b0_Island* m_pCurrentSimulationIsland;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned char m_bMotionType;
};
struct S_00cc10b0_WorldF3
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
    int m_74;
};
void __cdecl FUN_00999390(int* p, S_00cc10b0_Agent* agent, int w, S_00cc10b0_Island* island);
// pdb: hkpWorldAgentUtil::removeAgent | hkpWorldAgentUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpWorldAgentUtil_removeAgent(S_00cc10b0_Agent* agent)
{
    S_00cc10b0_EntityF3* entityA = (S_00cc10b0_EntityF3*)agent->m_pCollidableA->getOwner();
    S_00cc10b0_Island* islandA = entityA->m_pCurrentSimulationIsland;
    S_00cc10b0_EntityF3* entityB = (S_00cc10b0_EntityF3*)agent->m_pCollidableB->getOwner();
    S_00cc10b0_Island* islandB = entityB->m_pCurrentSimulationIsland;
    S_00cc10b0_Island* island;
    if (islandA == islandB)
    {
        island = islandA;
        island->markForCheck();
    }
    else if (entityA->m_bMotionType == 7)
    {
        island = islandB;
    }
    else if (entityB->m_bMotionType == 7)
    {
        island = islandA;
    }
    else
    {
        island = PickIslandByValue(agent, islandA, islandB);
        islandA->markForCheck();
        entityB->m_pCurrentSimulationIsland->markForCheck();
    }
    S_00cc10b0_Listener* listener = agent->m_kListener;
    FUN_00999390(&island->m_58, agent, ((S_00cc10b0_WorldF3*)island->m_pOwningWorld)->m_74, island);
    listener->v24();
}


struct Interface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void Invoke(void* value);
};
struct Holder
{
    int unk00;
    int unk04;
    Interface* interfaceObject;
};
struct Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Holder* holder;
};
struct Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char displacement;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
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
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Root* root;
};
void __cdecl hkpWorldAgentUtil_removeAgent(Owner* owner);
// Calls Invoke on the interface object reached through root's displacement-indexed entry, then calls hkpWorldAgentUtil_removeAgent.
// @f3 0x009447d0 (community match, verified in this file)
void __cdecl FUN_00944730(Owner* owner);

// pdb: hkpWorldAgentUtil::removeAgentAndItsToiEvents | hkpWorldAgentUtil.obj | fnv360_0822_retail, caller, medium
// pdb params: agent
void __cdecl FUN_00cc1160(Owner* owner)
{
    Owner* pOwner = owner;
    char* pRootBase = (char*)pOwner->root;
    int iDisplacement = ((signed char*)pRootBase)[0x10];
    Entry* entry = *(Entry**)(pRootBase + iDisplacement + 0xb8);
    Holder* holder = entry->holder;
    Interface* pInterface = holder->interfaceObject;
    pInterface->Invoke(pOwner);
    FUN_00944730(pOwner);
}


struct EventRecord
{
    unsigned char type;
    unsigned char dispatchId;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    void* value08;
    void* unk0c;
    void* source10;
    void* target14;
    int unk18;
    int unk1c;
    void* data20;
    int unk24;
    int unk28;
    int unk2c;
    void* data30;
};
struct EventArrayEntry
{
    EventRecord* record;
    unsigned int unk04;
};
struct EventArray
{
    EventArrayEntry* data;
    int count;
    int capacity;
};
struct SourceObject
{
    void __thiscall CopyAndSortGeometryList(EventArray* events);
};
struct EventSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SourceObject events;
};
struct DispatchContext
{
    void* table;
};
typedef void(__cdecl* EventHandler)(void*, void*, void*, void*, void*, void*, void*);
// @f3 0x00944510 (community match, verified in this file)
struct EventSourceView
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
    EventArrayEntry* data;
    int count;
};

// pdb: hkpWorldAgentUtil::getIslandFromAgentEntry | hkpWorldAgentUtil.obj | fnv360_0721_beta, objrun_open, low
// pdb params: entry, candidateA, candidateB
void __cdecl DispatchEvents(EventSource* source, DispatchContext* context)
{
    EventSourceView* view = (EventSourceView*)source;
    for (int index = 0; index < view->count; ++index)
    {
        EventRecord* event = view->data[index].record;
        unsigned char dispatchId = event->dispatchId;
        EventHandler handler = *(EventHandler*)((char*)context->table + 0x16c8 + dispatchId * 0x50);
        if (handler)
        {
            void* sourceObject = event->source10;
            void* target = event->target14;
            signed char sourceOffset = *((signed char*)sourceObject + 0x10);
            char* sourceField = (char*)sourceObject + sourceOffset;
            void* argument = *((unsigned char*)sourceField + 0xd8) == 7
                                 ? *(void**)((char*)target + *((signed char*)target + 0x10) + 0xb8)
                                 : *(void**)(sourceField + 0xb8);
            void* eventData = event->type == 4 ? (char*)event + 0x30 : (char*)event + 0x20;
            handler(event, eventData, sourceObject, target, context, event->value08, argument);
        }
    }
}


struct ItemEntry
{
    void* m_pInventoryEntryData;
    unsigned int unk04;
};

struct ItemOwner
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
    ItemEntry* m_pEntries;
    int m_iArrayLength;
};

// @f3 0x007a6d70 (community match, verified in this file)
struct ItemOwner;
struct Call7a6d70 { void CombatGroup_SetMemberGroupStrategyAssignment(void* item, int n); };
struct Ent7a6d70 { int key; void* item; };
struct Ctx7a6d70 { char pad[0x1c]; Ent7a6d70* entries; int count; };
// pdb: CombatGroupStrategyAdvance::Execute | CombatGroupStrategy.obj | fnv360_0822_retail, vtable, medium
// pdb params: apGroup, apGroupData
void __stdcall FUN_00cc0ea0(ItemOwner* pOwner, void* pContext)
{
    Ctx7a6d70* c = (Ctx7a6d70*)pContext;
    for (int i = 0; i < c->count; ++i)
        ((Call7a6d70*)pOwner)->CombatGroup_SetMemberGroupStrategyAssignment(c->entries[i].item, 4);
}


struct S_00cc0ed0_Rec
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char size;
};
struct S_00cc0ed0_Blocks
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
    int m58;
    S_00cc0ed0_Rec** volatile m5c;
    int m60;
};

void __cdecl DispatchSlotCallback(S_00cc0ed0_Rec* r, float a, float b, int c);

// Iterates over the block pointers in m5c, calling DispatchSlotCallback on each record up to the block end (m58 for the last block, 0x200 otherwise).
// @fnv 0x00cc0ed0
// pdb: hkpWorldAgentUtil::warpTime | hkpWorldAgentUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: island, oldTime, newTime, collisionInput
// pdb: hkpWorldAgentUtil::warpTime | hkpWorldAgentUtil.obj | fnv360_0822_retail, call_seq, high (was: ProcessBlocks)
void __cdecl hkpWorldAgentUtil_warpTime(S_00cc0ed0_Blocks* s, float a2, float a3, int a4)
{
    int i = 0;
    if (s->m60 > 0)
    {
        do
        {
            S_00cc0ed0_Rec* p = s->m5c[i];
            i++;
            char* end;
            if (i == s->m60)
            {
                end = (char*)p + s->m58;
            }
            else
            {
                end = (char*)p + 0x200;
            }
            while ((char*)p < end)
            {
                DispatchSlotCallback(p, a2, a3, a4);
                p = (S_00cc0ed0_Rec*)((char*)p + p->size);
            }
        } while (i < s->m60);
    }
}

struct S_00cc0f40_Type
{
    int unk00;
    int unk04;
    int unk08;
    int kind;
};
struct S_00cc0f40_Coll
{
    S_00cc0f40_Type* type;
    int unk04;
    int unk08;
    int unk0c;
    signed char off;
};
struct S_00cc0f40_Fn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(S_00cc0f40_Coll* a, S_00cc0f40_Coll* b, struct S_00cc0f40_In* in);
};
struct S_00cc0f40_Tbl
{
    int unk00;
    int unk04;
    int unk08;
    S_00cc0f40_Fn* fn[64];
};
struct S_00cc0f40_In
{
    S_00cc0f40_Tbl* table;
};

struct Island
{
    char pad[0x5c];
    int* arr;
    int count;
};

// Returns the island with the smaller count if val falls within 0x200 of an entry in its array, otherwise the island with the larger count.
// @fnv 0x00cc0e20
// pdb: hkpWorldAgentUtil::getIslandFromAgentEntry | hkpWorldAgentUtil.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: entry, candidateA, candidateB
Island* __cdecl PickIslandByValue(unsigned int val, Island* apIslandA, Island* apIslandB)
{
    bool less = apIslandA->count <= apIslandB->count;
    Island* p = less ? apIslandA : apIslandB;
    int n = p->count;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int v = p->arr[i];
        if (v <= val && val < v + 0x200)
        {
            found = true;
            break;
        }
    }
    return ((found ? true : false) ^ (less ? true : false)) ? apIslandB : apIslandA;
}

struct SelectorTarget
{
    unsigned char m_00;
};

// @fnv 0x00cc0e90
// pdb: getAgentData | hkpWorldAgentUtil.obj | fnv360_0822_retail, objrun_open, low
static unsigned int FUN_00cc0e90(SelectorTarget* p)
{
    if (p->m_00 == 4)
    {
        return (unsigned int)p + 0x30;
    }
    return (unsigned int)p + 0x20;
}

unsigned int probe_caller(SelectorTarget* p)
{
    return FUN_00cc0e90(p);
}

unsigned int probe_sink;
