#include "f3_common.h"
// src/havok/physics/collide/dispatch/hkpagentregisterutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/hkpagentregisterutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FlagCBFD
{
    bool m_bValue;
    FlagCBFD(bool bValue) : m_bValue(bValue)
    {}
    FlagCBFD(const FlagCBFD& kOther) : m_bValue(kOther.m_bValue)
    {}
};

class WorldCBFD
{
  public:
    void FUN_00cfb1e0(FlagCBFD kFlag);
};

void __cdecl hkRegisterAlternateShapeTypes(WorldCBFD* pkWorld);
void __cdecl ConfigureVtblHandlers(WorldCBFD* pkWorld);
void __cdecl RegisterTwoTables(WorldCBFD* pkWorld);
void __cdecl RegisterAll(WorldCBFD* pkWorld);
void __cdecl FUN_00d44310(WorldCBFD* pkWorld);
void __cdecl FUN_00cbfc60(WorldCBFD* pkWorld);
void __cdecl RegisterCallbacks(WorldCBFD* pkWorld);
void __cdecl FUN_00d42960(WorldCBFD* pkWorld);
void __cdecl FUN_00cbfcb0(WorldCBFD* pkWorld);

// Calls a sequence of registration and configuration functions on pkWorld, toggling a flag between two of them.
// @f3 0x009435a0 (community match, verified in this file)
void __cdecl FUN_009d45d0(WorldCBFD* pkWorld);
void __cdecl FUN_009d40d0(WorldCBFD* pkWorld);
void __cdecl FUN_009d2e40(WorldCBFD* pkWorld);
void __cdecl FUN_009434b0(WorldCBFD* pkWorld);
void __cdecl FUN_009d1fd0(WorldCBFD* pkWorld);
void __cdecl FUN_00943500(WorldCBFD* pkWorld);
void __cdecl FUN_009d1070(WorldCBFD* pkWorld);
void __cdecl FUN_009cdc20(WorldCBFD* pkWorld);
void __cdecl FUN_009cd3b0(WorldCBFD* pkWorld);
void __cdecl FUN_00943530(WorldCBFD* pkWorld);
struct WorldCBFDF3
{
    void FUN_00985220(FlagCBFD flag);
};
// pdb: hkpAgentRegisterUtil::registerAllAgents | hkpAgentRegisterUtil.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: dis
void __cdecl InitializeWorld(WorldCBFD* pkWorld)
{
    WorldCBFDF3* w = (WorldCBFDF3*)pkWorld;
    FUN_009d45d0(pkWorld);
    FUN_009d40d0(pkWorld);
    FUN_009d2e40(pkWorld);
    FUN_009434b0(pkWorld);
    w->FUN_00985220(FlagCBFD(false));
    FUN_009d1fd0(pkWorld);
    w->FUN_00985220(FlagCBFD(true));
    FUN_00943500(pkWorld);
    w->FUN_00985220(FlagCBFD(false));
    FUN_009d1070(pkWorld);
    w->FUN_00985220(FlagCBFD(true));
    FUN_009cdc20(pkWorld);
    FUN_009cd3b0(pkWorld);
    FUN_00943530(pkWorld);
}

