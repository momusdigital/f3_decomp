#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/dynamics/world/maintenance/default/hkpdefaultworldmaintenancemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/maintenance/default/hkpdefaultworldmaintenancemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d0b250_RefObj
{
    virtual ~S_00d0b250_RefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d0b250_RefObj() : m_sReferenceCount(1)
    {}
};

struct hkpDefaultWorldMaintenanceMgr : S_00d0b250_RefObj // src: F3_EXE vtable 0x00e7da5c (old: FUN_00d0b250)
{
    float m_kPointA;
    float m_kPointB;
    hkpDefaultWorldMaintenanceMgr();
    virtual ~hkpDefaultWorldMaintenanceMgr();
};

// Initializes the object's two float members to 33.0 and 63.0 and sets the base reference count to 1.
// @fnv 0x00d0b250
// pdb: hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr | hkpDefaultWorldMaintenanceMgr.obj | fnv360_0822_retail, uvref, high
hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr() : m_kPointA(33.0f), m_kPointB(63.0f)
{}

struct S_00d0b230_Dst
{
    int unk00, unk04, unk08, unk0C, unk10;
    float unk14;
    float unk18;
};

struct S_00d0b230_Arg
{
    int unk00, unk04;
    S_00d0b230_Dst* unk08;
};

struct FUN_00d0b230_class
{
    int unk00, unk04;
    float unk08;
    void hkpDefaultWorldMaintenanceMgr_init(S_00d0b230_Arg* a);
};

// @fnv 0x00d0b230
// pdb: hkpDefaultWorldMaintenanceMgr::init | hkpDefaultWorldMaintenanceMgr.obj | fnv360_0822_retail, vtable, high
// pdb params: world
// pdb: hkpDefaultWorldMaintenanceMgr::init | hkpDefaultWorldMaintenanceMgr.obj | fnv360_0822_retail, vtable, high (was: SetDstFields)
void FUN_00d0b230_class::hkpDefaultWorldMaintenanceMgr_init(S_00d0b230_Arg* a)
{
    S_00d0b230_Dst* pDst = a->unk08;
    pDst->unk14 = unk08;
    pDst->unk18 = unk08;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern void __cdecl hkpWorldOperationUtil_splitSimulationIslands(void*);
struct FUN_00d0b280_cls
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    void FUN_00d0b280(float* first, float* second);
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(float* first, float* second);
};
// Writes trace entries, calls hkpWorldOperationUtil_splitSimulationIslands(first), and if *second >= unk0c calls hkpDefaultWorldMaintenanceMgr_resetWorldTime(first, second) between further trace entries.
// @fnv 0x00d0b280
void FUN_00d0b280_cls::FUN_00d0b280(float* first, float* second)
{
    HK_TIMER_BEGIN_LIST("Maintenance", "Split");
    hkpWorldOperationUtil_splitSimulationIslands(first);
    if (*second >= unk0c)
    {
        HK_TIMER_SPLIT_LIST("ResetTime");
        hkpDefaultWorldMaintenanceMgr_resetWorldTime(first, second);
    }
    HK_TIMER_END_LIST();
}


struct FUN_00d0b350_cls
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(float* first, float* second);
    void hkpDefaultWorldMaintenanceMgr_performMaintenanceNoSplit(float* first, float* second);
};
// Writes a trace entry, calls hkpDefaultWorldMaintenanceMgr_resetWorldTime(first, second) if *second >= unk0c, then writes a closing trace entry.
// @fnv 0x00d0b350
// pdb: hkpDefaultWorldMaintenanceMgr::performMaintenanceNoSplit | hkpDefaultWorldMaintenanceMgr.obj | fnv360_0822_retail, vtable, high
// pdb params: world, stepInfo
// pdb: hkpDefaultWorldMaintenanceMgr::performMaintenanceNoSplit | hkpDefaultWorldMaintenanceMgr.obj | fnv360_0822_retail, vtable, high (was: TraceConditionalCall)
void FUN_00d0b350_cls::hkpDefaultWorldMaintenanceMgr_performMaintenanceNoSplit(float* first, float* second)
{
    HK_TIMER_BEGIN_LIST("Maintenance", "ResetTime");
    if (*second >= unk0c)
        hkpDefaultWorldMaintenanceMgr_resetWorldTime(first, second);
    HK_TIMER_END_LIST();
}

struct hkStepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct hkpEntity
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
    float m_uiCommandId;
};

struct hkpSimulationIsland
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
    hkpEntity** m_kActorEntries;
    int m_iActorEntryCount;
};

struct CollisionAgentContext
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
    hkStepInfo m_pStepInfo;
};

struct hkpSimulation
{
    virtual void vf00();
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
    virtual void shiftTime(float shift);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float m_fElapsedSimulationTime;
    float m_fSimulationTime;
    int unk1C;
    float m_fFrameMarkerTime;
};

struct hkpWorld
{
    int unk00;
    int unk04;
    hkpSimulation* m_pSimulation;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    hkpSimulationIsland** m_activeIslands;
    int m_numActiveIslands;
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
    CollisionAgentContext* m_pCollisionInput;
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
    hkStepInfo m_pStepInfo;
};

void __cdecl hkpWorldAgentUtil_warpTime(hkpSimulationIsland* island, float oldTime, float newTime, CollisionAgentContext* input);

struct TimeRebaser
{
    int unk00;
    int unk04;
    float m_newTime;
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo);
};

// @f3 0x0098ba90 (community match, verified in this file)
struct F3World
{
    int unk00;
    int unk04;
    hkpSimulation* m_pSimulation;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    hkpSimulationIsland** m_activeIslands;
    int m_numActiveIslands;
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
    CollisionAgentContext* m_pCollisionInput;
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
    hkStepInfo m_pStepInfo;
};
struct F3Entity
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
    float m_uiCommandId;
};
void __cdecl FUN_009445e0(hkpSimulationIsland* island, float oldTime, float newTime, CollisionAgentContext* input);
// pdb: hkpDefaultWorldMaintenanceMgr::resetWorldTime | hkpDefaultWorldMaintenanceMgr.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void TimeRebaser::hkpDefaultWorldMaintenanceMgr_resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo)
{
    F3World* fo3World = (F3World*)world;
    float deltaTime = stepInfo.m_fEndTime - stepInfo.m_uiStartTime;
    hkStepInfo& si = fo3World->m_pStepInfo;
    const TimeRebaser* owner = this;
    si.m_uiStartTime = owner->m_newTime;
    si.m_fEndTime = owner->m_newTime + deltaTime;
    si.m_fTimeStep = deltaTime;
    si.m_fInverseDeltaTime = 1.0f / si.m_fTimeStep;

    float shift = fo3World->m_pStepInfo.m_uiStartTime - stepInfo.m_uiStartTime;
    hkpSimulation* pSimulation = fo3World->m_pSimulation;
    pSimulation->m_fElapsedSimulationTime += shift;
    pSimulation->m_fSimulationTime = fo3World->m_pStepInfo.m_uiStartTime;
    if (pSimulation->m_fFrameMarkerTime != -1.0f)
    {
        fo3World->m_pSimulation->m_fFrameMarkerTime = (float)(fo3World->m_pSimulation->m_fFrameMarkerTime + shift);
    }

    for (int iIsland = 0; iIsland < fo3World->m_numActiveIslands; iIsland++)
    {
        hkpSimulationIsland* island = fo3World->m_activeIslands[iIsland];
        for (int iActor = 0; iActor < island->m_iActorEntryCount; iActor++)
        {
            ((F3Entity*)island->m_kActorEntries[iActor])->m_uiCommandId += shift;
        }
        FUN_009445e0(island, stepInfo.m_fEndTime, fo3World->m_pStepInfo.m_fEndTime, fo3World->m_pCollisionInput);
    }

    fo3World->m_pSimulation->shiftTime(shift);
    stepInfo = fo3World->m_pStepInfo;
    fo3World->m_pCollisionInput->m_pStepInfo = fo3World->m_pStepInfo;
}

