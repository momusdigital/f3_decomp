// src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/list/hkplistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl hkAgent1nMachine_InvalidateTim(void*, void*);

struct hkAgent1nMachine
{
    void __thiscall InvalidateTim(void*);
};

struct hkpListAgent
{
    char m0[0x10];
    void __thiscall FUN_00d36850(void* arg);
};

// @fnv 0x00d36850
// pdb: hkpListAgent::invalidateTim | hkpListAgent.obj | fnv360_0721_beta, objrun, high
// pdb params: input
void __thiscall hkpListAgent::FUN_00d36850(void* arg)
{
    hkAgent1nMachine_InvalidateTim((char*)this + 0x10, arg);
}

extern "C" void __cdecl FUN_00d36990(int, int, int, int);

// @fnv 0x00d36b00
void __stdcall FUN_00d36b00(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_00d36990(aiArg1, aiArg2, aiArg3, aiArg4);
}

extern "C" void __cdecl hkAgent1nMachine_WarpTime(void*, float, float, int);
struct Owner
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36870(float a1, float a2, int a3);
};
// Forwards the three arguments to hkAgent1nMachine_WarpTime with the object's field at offset 0x10 as its first argument.
// @fnv 0x00d36870
// pdb: hkpListAgent::warpTime | hkpListAgent.obj | tesv_win, hash, low
void Owner::FUN_00d36870(float afValue1, float afValue2, int aiValue)
{
    hkAgent1nMachine_WarpTime((char*)this + 0x10, afValue1, afValue2, aiValue);
}

void __cdecl FUN_00d36920(void* a, void* b, void* c, void* d);

// @fnv 0x00d36940
void __stdcall FUN_00d36940(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d36920(apArg1, apArg2, apArg3, apArg4);
}

void __cdecl FUN_00d36930(int a1, int a2, int a3, int a4, int a5);

// Forwards all five arguments to FUN_00d36930.
// @fnv 0x00d36960
// pdb: hkpListAgent::linearCast | hkpListAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void __stdcall hkpListAgent_linearCast(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FUN_00d36930(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5);
}

extern "C" void __cdecl hkAgent1nMachine_Destroy(void* a, int b, int c, int d);

struct FUN_00d36820_cls
{
    virtual void v00(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36820(int a1);
};

// Calls hkAgent1nMachine_Destroy with &unk10, unk0C, unk08 and a1, then invokes v00(1).
// @fnv 0x00d36820
// pdb: hkpListAgent::cleanup | hkpListAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: constraintOwner
void FUN_00d36820_cls::FUN_00d36820(int aiValue)
{
    hkAgent1nMachine_Destroy(&unk10, unk0C, unk08, aiValue);
    this->v00(1);
}

struct S_00d368a0_Arg
{
    int unk00;
    int unk04;
    int m_field08;
};

void __cdecl FUN_00d97250(void* sub, int field08, S_00d368a0_Arg* arg);

struct S_00d368a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_agentTrack;  // +0x10 hkpAgent1nTrack (m_sectors first)
    void hkpListAgent_calcContentStatistics(S_00d368a0_Arg* a);
};

// @f3 0x009bed10 (community match, verified in this file)
extern "C" void __cdecl FUN_00a26d90(void* a, int b, S_00d368a0_Arg* c);

// pdb: hkpListAgent::calcContentStatistics | hkpListAgent.obj | fnv360_0721_beta, objrun + bridge(caller_sim|vtable) + skyrim(objrun), high
void S_00d368a0::hkpListAgent_calcContentStatistics(S_00d368a0_Arg* a)
{
    FUN_00a26d90(&m_agentTrack, a->unk04, a);
}


extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void*, void*);

struct VirtTarget
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
};

struct CallArgs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00d368c0_cls
{
    int unk00;
    int unk04;
    int m_08;          // m_contactMgr
    int unk0C;         // m_dispatcher
    int m_agentTrack;  // +0x10 hkpAgent1nTrack (m_sectors first)
    void hkpListAgent_updateShapeCollectionFilter(void* a1, void* a2, void* a3, void* a4);
};
// Builds a CallArgs from the four arguments and m_08, calls v10 on a2, then passes it to hkAgent1nMachine_UpdateShapeCollectionFilter with this+0x10.
// @f3 0x009bed30 (community match, verified in this file)
extern "C" void __cdecl FUN_00a2b420(void* target, void* args);
struct FUN_00d368c0_Virt
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
    virtual int v14();
};
// pdb: hkpListAgent::updateShapeCollectionFilter | hkpListAgent.obj | fnv360_0721_beta, objrun_sim + bridge(caller_sim|vtable) + skyrim(caller_sim), high
void FUN_00d368c0_cls::hkpListAgent_updateShapeCollectionFilter(void* a1, void* a2, void* a3, void* a4)
{
    CallArgs args;
    args.unk00 = (int)a1;
    args.unk04 = (int)a2;
    args.unk10 = (int)a3;
    args.unk14 = m_08;
    args.unk18 = (int)a4;
    args.unk0C = ((FUN_00d368c0_Virt*)*(void**)a2)->v14();
    FUN_00a2b420(&m_agentTrack, &args);
}

