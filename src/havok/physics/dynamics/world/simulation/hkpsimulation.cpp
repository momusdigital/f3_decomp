#include "f3_common.h"
// src/havok/physics/dynamics/world/simulation/hkpsimulation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/hkpsimulation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSimulation.h"
#include "havok/hkMonitorStream.h"

extern "C" void __cdecl FUN_00cfdbe0(int, int);

struct FUN_00cf87a0_Class {
    void __thiscall hkpSimulation_processAgentResetCollisionInformation(int a, int b, int c);
};

// @fnv 0x00cf87a0
// pdb: hkpSimulation::processAgentResetCollisionInformation | hkpSimulation.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, processInput, processOutput
// pdb: hkpSimulation::processAgentResetCollisionInformation | hkpSimulation.obj | fnv360_0822_retail, objrun, high (was: ForwardToGlobal)
void __thiscall FUN_00cf87a0_Class::hkpSimulation_processAgentResetCollisionInformation(int aiArg1, int aiArg2, int aiUnused)
{
    FUN_00cfdbe0(aiArg1, aiArg2);
}

class hkpWorld {
public:
    int __thiscall FUN_00c93570();
};

class SimulationDerived : public hkpSimulation {
public:
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10(hkReal dt);
    virtual void vfn14();
    virtual void vfn18();

    hkUint32 __thiscall FUN_00cf8730(hkReal dt);
};

// @f3 0x0097f150 (community match, verified in this file)
hkUint32 SimulationDerived::FUN_00cf8730(hkReal afDeltaTime)
{
    if (!m_uiSimulationType || m_uiSimulationType == 1)
        vfn10(afDeltaTime);
    if (!m_uiSimulationType || m_uiSimulationType == 2)
        vfn14();
    if (!m_uiSimulationType || m_uiSimulationType == 3)
        vfn18();
    return m_uiSimulationType;
}


extern "C" {
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    extern int DAT_01269200;
    extern unsigned long DAT_0126835c;
    extern const char str_010c41f8[];
    void __cdecl FUN_00d014f0(void*, void*);
}

struct hkpWorld_Fields {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
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
    int unk180;
};

__declspec(align(16)) struct hkStepInfo {
    hkReal m_uiStartTime;
    hkReal m_fEndTime;
    hkReal m_fTimeStep;
    hkReal m_fInverseDeltaTime;

    __forceinline void set(hkReal startTime, hkReal endTime) {
        m_uiStartTime = startTime;
        m_fEndTime = endTime;
        m_fTimeStep = endTime - startTime;
        m_fInverseDeltaTime = (m_fTimeStep == 0.0f) ? 0.0f : (1.0f / m_fTimeStep);
    }
};

struct StringCursor {
    int unk0;
    char* m_commandSlice;
    int unk8;
    char* m_pRayCursor;

    __forceinline void record(const char* tag, volatile hkUint32& t) {
        char* pos = m_commandSlice;
        if (pos < m_pRayCursor) {
            *(const char**)pos = tag;
            _ReadWriteBarrier();
            t = (hkUint32)__rdtsc();
            *(hkUint32*)(pos + 4) = t;
            pos += 12;
            m_commandSlice = pos;
        }
    }
};

static __forceinline void recordTimer(const char* tag, volatile hkUint32& t) {
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    stream->record(tag, t);
}

class hkpSimulation_Derived : public hkpSimulation {
public:
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void step(hkStepInfo* info);

    hkUint32 FUN_00cf8820();
};

// @f3 0x0097f210 (community match, verified in this file)
extern "C" int* DAT_010f3400;
extern "C" const char str_00e32798[];
extern "C" const char str_00e7d2c8[];
extern "C" void __cdecl hkpWorldCallbackUtil_firePostCollideCallback(void*,void*);
extern "C" void* (__stdcall *DAT_00d9b080)(unsigned long);
struct FUN_00907f30_Class { void __thiscall FUN_00907f30(int,int); };
static __forceinline void timerF3(const char* tag, volatile hkUint32& t) {
    StringCursor* stream=(StringCursor*)TlsGetValue(DAT_0126835c);
    stream->record(tag,t);
}
hkUint32 hkpSimulation_Derived::FUN_00cf8820()
{
    ((FUN_00907f30_Class*)m_pOwningWorld)->FUN_00907f30(0, 1);

    hkStepInfo stepInfo;
    if (m_uiSimulationType == 3) {
        stepInfo.set(m_fElapsedSimulationTime, m_fSimulationTime);
    } else {
        stepInfo.set(m_fSimulationTime, m_fSimulationTime + m_fStepDeltaTime);
    }

    step(&stepInfo);

    if (DAT_010f3400[1] == 1) {
        HK_TIMER_END();
        return m_uiSimulationType;
    }

    if (m_uiSimulationType == 2) {
        m_fSimulationTime += m_fStepDeltaTime;
        if (((hkpWorld_Fields*)m_pOwningWorld)->unk154 != 0) {
            HK_TIMER_BEGIN("PostCollideCB", HK_NULL);
            hkpWorldCallbackUtil_firePostCollideCallback(m_pOwningWorld, &stepInfo);
            HK_TIMER_END();
        }
        m_bHasStepped = 1;
    }

    m_uiSimulationType = 0;
    return 0;
}


extern "C" void hkpSimulation_processAgentCollideDiscrete();

struct FUN_00cfa400_Obj {
    void __thiscall FUN_00cf9480(int a1, int a2, int a3, void (*callback)(), int a5);
    void __thiscall FUN_00cfa400(int a1, int a2, int a3, int a4);
};

// Forwards the four arguments to FUN_00cf9480, passing hkpSimulation_processAgentCollideDiscrete as the callback.
// @fnv 0x00cfa400
// pdb: hkpWorld::internal_executePendingOperations | hkpWorld.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpSimulation::collideEntitiesNarrowPhaseDiscrete)
void __thiscall FUN_00cfa400_Obj::FUN_00cfa400(int a1, int a2, int a3, int a4) {
    FUN_00cf9480(a1, a2, a3, hkpSimulation_processAgentCollideDiscrete, a4);
}

namespace fnv_00cfa470 {
struct __declspec(align(16)) hkStepInfo {
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct hkpEntity;

struct hkpCollisionInputS {
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

class hkpWorld {
public:
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
    hkpCollisionInputS* m_pCollisionInput;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk98;
    hkBool m_bBlockExecutingPendingOperations;
    char unk9D;
    char unk9E;
    char unk9F;
    int unkA0;
    int m_iPendingOperationQueueCount;

    float FUN_00c91020();
    float FUN_00c91030();
    void FUN_00c91120();
    void FUN_00c91140();
};

struct hkMotionState {
    int unk00;
};

struct hkpEntity {
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
    hkUint8 m_bFlag;
    char unkE9;
    char unkEA;
    char unkEB;
    int unkEC;
    hkMotionState m_kMotionState;
};

void __cdecl FUN_00d1a330(hkpCollisionInputS* input, hkpEntity** entities, int numEntities);
void __cdecl FUN_00cf9c60(hkpEntity** entities, int numEntities, hkpWorld* world);

}  // namespace fnv_00cfa470

struct FnvCpu_FUN_00cfa7a0_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cfa7a0_CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cfa7a0_CpuAllocator* allocator;
};
FnvCpu_FUN_00cfa7a0_CpuAllocatorHolder* __cdecl FUN_00c85750();

extern "C" void __cdecl FUN_00d01380(int);
extern unsigned long DAT_0126835c;
extern const char str_010c41f8[];
typedef void* (__stdcall *S00cf8a40_TlsFn)(unsigned long);

struct S00cf8a40_Cmd {
    const char* m_name;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S00cf8a40_Stream {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_cap;

    __forceinline void timer(const char* name)
    {
        if (m_kRayEnd < m_cap) {
            S00cf8a40_Cmd* c = reinterpret_cast<S00cf8a40_Cmd*>(m_kRayEnd);
            c->m_name = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            c->m_uiStartTicks = t;
            m_kRayEnd = reinterpret_cast<char*>(c + 1);
        }
    }
};

struct S00cf8a40_Node {
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
    int m_168;
};

struct S00cf8a40_Obj {
    int unk00;
    int unk04;
    int unk08;
    S00cf8a40_Node* m_node;
    int unk10;
    float m_uiCommandId;
    int unk18;
    int unk1c;
    float m_pFreeList;
    int unk24;
    int m_uiContentCount;

    float hkpSimulation_snapSimulateTimeAndGetTimeToAdvanceTo();
    int FUN_00cf8a40();
};

// @f3 0x0097f430 (community match, verified in this file)
extern unsigned long DAT_0126835c;
extern const char str_00e7d2d8[];
extern const char str_010c41f8[];
typedef void* (__stdcall *S00cf8a40_TlsFn)(unsigned long);

int S00cf8a40_Obj::FUN_00cf8a40()
{
    m_uiCommandId = hkpSimulation_snapSimulateTimeAndGetTimeToAdvanceTo();
    if (m_uiCommandId >= m_pFreeList && m_node->unk13C) {
        S00cf8a40_TlsFn pTlsFn = (S00cf8a40_TlsFn)&TlsGetValue;
        S00cf8a40_Stream* s = (S00cf8a40_Stream*)pTlsFn(DAT_0126835c);
        s->timer(str_00e7d2d8);
        FUN_00d01380((int)m_node);
        s = (S00cf8a40_Stream*)pTlsFn(DAT_0126835c);
        s->timer(str_010c41f8);
    }
    m_uiContentCount = 0;
    return 0;
}


struct hkVector4CF9 {
    float x;
    float y;
    float z;
    float w;
};

struct hkpRootCdPointCF9 {
    hkVector4CF9 m_vContactPosition;
    hkVector4CF9 m_vSeparatingNormal;
    const void* m_pRootCollidableA;
    unsigned int m_uiShapeKeyA;
    const void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
};

struct hkpCdPointCollectorCF9 {
    hkpRootCdPointCF9* m_data;
    int unk0004;
    int unk0008;
    int unk000C;
    hkpRootCdPointCF9 m_kStorage[256];
    int unk3010, unk3014, unk3018, unk301C, unk3020, unk3024, unk3028, unk302C;
    float m_fEarlyOutDistance;
    int unk3034, unk3038, unk303C, unk3040, unk3044, unk3048, unk304C, unk3050, unk3054, unk3058, unk305C, unk3060;
    int unk3064, unk3068, unk306C, unk3070, unk3074, unk3078, unk307C;
    int m_hitCount;
};

struct hkpAgentEntryCF9 {
    void* m_pCreateFunc;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int m_aiContactPointIds[4];
};

struct hkpDispatcherCF9 {
    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C;
    int unk0030, unk0034, unk0038, unk003C, unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C, unk0080, unk0084, unk0088, unk008C;
    int unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC;
    int unk00F0, unk00F4, unk00F8, unk00FC, unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C, unk0140, unk0144, unk0148, unk014C;
    int unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC;
    int unk01B0, unk01B4, unk01B8, unk01BC, unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC, unk0200, unk0204, unk0208, unk020C;
    int unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C;
    int unk0270, unk0274, unk0278, unk027C, unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC, unk02C0, unk02C4, unk02C8, unk02CC;
    int unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C;
    int unk0330, unk0334, unk0338, unk033C, unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C, unk0380, unk0384, unk0388, unk038C;
    int unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC;
    int unk03F0, unk03F4, unk03F8, unk03FC, unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C, unk0440, unk0444, unk0448, unk044C;
    int unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC;
    int unk04B0, unk04B4, unk04B8, unk04BC, unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC, unk0500, unk0504, unk0508, unk050C;
    int unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C;
    int unk0570, unk0574, unk0578, unk057C, unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC, unk05C0, unk05C4, unk05C8, unk05CC;
    int unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C;
    int unk0630, unk0634, unk0638, unk063C, unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C, unk0680, unk0684, unk0688, unk068C;
    int unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC;
    int unk06F0, unk06F4, unk06F8, unk06FC, unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C, unk0740, unk0744, unk0748, unk074C;
    int unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC;
    int unk07B0, unk07B4, unk07B8, unk07BC, unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC, unk0800, unk0804, unk0808, unk080C;
    int unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C;
    int unk0870, unk0874, unk0878, unk087C, unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC, unk08C0, unk08C4, unk08C8, unk08CC;
    int unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C;
    int unk0930, unk0934, unk0938, unk093C, unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C, unk0980, unk0984, unk0988, unk098C;
    int unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC;
    int unk09F0, unk09F4, unk09F8, unk09FC, unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C, unk0A40, unk0A44, unk0A48, unk0A4C;
    int unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC;
    int unk0AB0, unk0AB4, unk0AB8, unk0ABC, unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC, unk0B00, unk0B04, unk0B08, unk0B0C;
    int unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C;
    int unk0B70, unk0B74, unk0B78, unk0B7C, unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC, unk0BC0, unk0BC4, unk0BC8, unk0BCC;
    int unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C;
    int unk0C30, unk0C34, unk0C38, unk0C3C, unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C, unk0C80, unk0C84, unk0C88, unk0C8C;
    int unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC;
    int unk0CF0, unk0CF4, unk0CF8, unk0CFC, unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C, unk0D40, unk0D44, unk0D48, unk0D4C;
    int unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC;
    int unk0DB0, unk0DB4, unk0DB8, unk0DBC, unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC, unk0E00, unk0E04, unk0E08, unk0E0C;
    int unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C;
    int unk0E70, unk0E74, unk0E78, unk0E7C, unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC, unk0EC0, unk0EC4, unk0EC8, unk0ECC;
    int unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C;
    int unk0F30, unk0F34, unk0F38, unk0F3C, unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C, unk0F80, unk0F84, unk0F88, unk0F8C;
    int unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC;
    int unk0FF0, unk0FF4, unk0FF8, unk0FFC, unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C, unk1040, unk1044, unk1048, unk104C;
    int unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC;
    int unk10B0, unk10B4, unk10B8, unk10BC, unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC, unk1100, unk1104, unk1108, unk110C;
    int unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C;
    int unk1170, unk1174, unk1178, unk117C, unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC, unk11C0, unk11C4, unk11C8, unk11CC;
    int unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C;
    int unk1230, unk1234, unk1238, unk123C, unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C, unk1280, unk1284, unk1288, unk128C;
    int unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC;
    int unk12F0, unk12F4, unk12F8, unk12FC, unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C, unk1340, unk1344, unk1348, unk134C;
    int unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC;
    int unk13B0, unk13B4, unk13B8, unk13BC, unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC, unk1400, unk1404, unk1408, unk140C;
    int unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C;
    int unk1470, unk1474, unk1478, unk147C, unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC, unk14C0, unk14C4, unk14C8, unk14CC;
    int unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C;
    int unk1530, unk1534, unk1538, unk153C, unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C, unk1580, unk1584, unk1588, unk158C;
    int unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC;
    int unk15F0, unk15F4, unk15F8, unk15FC, unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C, unk1640, unk1644, unk1648, unk164C;
    int unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC;
    int unk16B0, unk16B4, unk16B8, unk16BC, unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC, unk1700, unk1704, unk1708, unk170C;
    int unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C;
    int unk1770, unk1774, unk1778, unk177C, unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC, unk17C0, unk17C4, unk17C8, unk17CC;
    int unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C;
    int unk1830, unk1834, unk1838, unk183C, unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C, unk1880, unk1884, unk1888, unk188C;
    int unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC;
    int unk18F0, unk18F4, unk18F8, unk18FC, unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C;
    int unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C, unk1940, unk1944, unk1948, unk194C;
    int unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC;
    int unk19B0, unk19B4, unk19B8, unk19BC, unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC;
    int unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC, unk1A00, unk1A04, unk1A08, unk1A0C;
    int unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C;
    int unk1A70, unk1A74, unk1A78, unk1A7C, unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C;
    int unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC, unk1AC0, unk1AC4, unk1AC8, unk1ACC;
    int unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C;
    int unk1B30, unk1B34, unk1B38, unk1B3C, unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C;
    int unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C, unk1B80, unk1B84, unk1B88, unk1B8C;
    int unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC;
    int unk1BF0, unk1BF4, unk1BF8, unk1BFC, unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C;
    int unk1C20, unk1C24, unk1C28, unk1C2C;
    hkpAgentEntryCF9 m_pAgents[1];
};

struct hkpCollisionInputCF9 {
    hkpDispatcherCF9* m_pCollisionDispatcher;
    int unk04, unk08, unk0C, unk10;
    void* m_pCreateFunc;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int* m_aiContactPointIds;
};

class hkpAgentCF9 {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void getPenetrations(void* bodyA, void* bodyB, hkpCollisionInputCF9* input, hkpCdPointCollectorCF9* collector);
};

struct hkpLinearCastInputCF9 {
    int unk00;
    int unk04;
    hkpAgentCF9* m_pCollisionAgent;
    signed char m_iType;
    void* m_pBodyA;
    void* m_pBodyB;
};

extern int DAT_01269200;

// @f3 0x0097fc80 (community match, verified in this file)
struct CastBool {char value; };struct CastManager;struct CastMethods {void* unk00; void* unk04; void* unk08; void* unk0C; void* unk10; void* unk14; void* unk18; void* unk1C; void* unk20; void* unk24; void* unk28; void* unk2C; void* unk30; void* unk34; void* unk38; void* unk3C; void* unk40; void* unk44; void* unk48; void* unk4C; void* unk50; void* unk54; void* unk58; void* unk5C; CastBool* (__thiscall* query)(CastManager*,CastBool*,int);};struct CastManager {CastMethods* table;int state;};
namespace CastGlobals {extern CastManager* DAT_010f3400;}
extern float DAT_00de6e60;void __cdecl FUN_00999610(hkpLinearCastInputCF9*,hkpCollisionInputCF9*,hkpCdPointCollectorCF9*,hkpAgentCF9*);
// pdb: hkpSimulation::processAgentCollideDiscrete | hkpSimulation.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, processInput, processOutput
// pdb: hkpSimulation::processAgentCollideDiscrete | hkpSimulation.obj | fnv360_0822_retail, objrun, high (was: CollectLinearCast)
void __stdcall hkpSimulation_processAgentCollideDiscrete(hkpLinearCastInputCF9* linear,hkpCollisionInputCF9* input,hkpCdPointCollectorCF9* collector){collector->m_fEarlyOutDistance=DAT_00de6e60;collector->m_hitCount=0;collector->m_data=collector->m_kStorage;hkpDispatcherCF9* dispatcher=input->m_pCollisionDispatcher;input->m_aiContactPointIds=dispatcher->m_pAgents[0].m_aiContactPointIds;*(void**)((char*)input+0x10)=dispatcher->m_pAgents[linear->m_iType].m_pCreateFunc;FUN_00999610(linear,input,collector,linear->m_pCollisionAgent);CastManager* manager=CastGlobals::DAT_010f3400;CastBool flag;if(!manager->table->query(manager,&flag,0)->value)(CastGlobals::DAT_010f3400)->state=1;if((CastGlobals::DAT_010f3400)->state!=1&&collector->m_data!=collector->m_kStorage)linear->m_pCollisionAgent->getPenetrations(linear->m_pBodyA,linear->m_pBodyB,input,collector);}


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;

struct SimMonStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};

struct __declspec(align(16)) SimStepInfo {
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;

    SimStepInfo(float startTime, float endTime) {
        m_uiStartTime = startTime;
        m_fEndTime = endTime;
        m_fTimeStep = endTime - startTime;
        m_fInverseDeltaTime = (m_fTimeStep == 0.0f) ? 0.0f : 1.0f / m_fTimeStep;
    }
};

struct SimCollisionInput {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    SimStepInfo m_pStepInfo;
};

struct SimWorld;

struct SimMaintenanceMgr {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void PerformMaintenance(SimWorld* world, SimStepInfo& stepInfo);
};

struct SimDynamicsStepInfo {
    SimStepInfo m_pStepInfo;
};

struct SimWorld {
    void* m_vtbl;
    int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48;
    SimMaintenanceMgr* m_pMaintenanceManager;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74;
    SimCollisionInput* m_pCollisionInput;
    int unk7c; int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac;
    int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4; int unke8; int unkec;
    int unkf0; int unkf4; int unkf8; int unkfc;
    int unk100; int unk104; int unk108; int unk10c;
    int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac;
    int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc;
    SimDynamicsStepInfo m_kDynamicsStepInfo;
};

static inline SimMonStream& GetMonStream() {
    return *(SimMonStream*)TlsGetValue(DAT_0126835c);
}

struct SimLocal : hkpSimulation {
    int FUN_00cf8da0(const SimStepInfo& stepInfo);
    int hkpSimulation_integrate(float physicsDeltaTime);
};

// @f3 0x0097fd30 (community match, verified in this file)
struct S_0097fd30_WorldCall
{
    int FUN_00903760();
};

struct S_0097fd30_SimulationCall
{
    void FUN_0097f810(const SimStepInfo& stepInfo);
};

// pdb: hkpSimulation::integrate | hkpSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
int SimLocal::hkpSimulation_integrate(float physicsDeltaTime)
{
    struct LocalMonitor
    {
        char* m_start;
        char* m_end;
        char* m_capacity;
        char* m_capacityMinus16;
    };
    struct LocalStack
    {
        char* m_current;
        int unk04;
        int unk08;
        char* m_end;
        int getFreeBytes() const { return (int)(m_end - m_current) - 16; }
    };
    struct LocalThreadMemory
    {
        int unk000[8];
        LocalStack m_stack;
    };
    struct LocalWorld
    {
        char unk000[0x4c];
        SimMaintenanceMgr* m_pMaintenanceManager;
        char unk050[0x1c];
        SimCollisionInput* m_pCollisionInput;
        char unk070[0x120];
        SimStepInfo m_dynamicsStepInfo;
    };
    struct LocalBool
    {
        char m_bool;
        LocalBool(bool b) : m_bool((char)b) {}
        operator bool() const { return m_bool != 0; }
    };
    struct LocalMemory
    {
        virtual void v00() {} virtual void v04() {} virtual void v08() {} virtual void v0c() {}
        virtual void v10() {} virtual void v14() {} virtual void v18() {} virtual void v1c() {}
        virtual void v20() {} virtual void v24() {} virtual void v28() {} virtual void v2c() {}
        virtual void v30() {} virtual void v34() {} virtual void v38() {} virtual void v3c() {}
        virtual void v40() {} virtual void v44() {} virtual void v48() {} virtual void v4c() {}
        virtual void v50() {} virtual void v54() {} virtual void v58() {} virtual void v5c() {}
        virtual LocalBool hasMemoryAvailable(int size) { return LocalBool(false); }
        int m_memoryState;
    };

    HK_TIMER_BEGIN("Simulate", HK_NULL);
    m_fStepDeltaTime = physicsDeltaTime;

    int memNeeded = ((S_0097fd30_WorldCall*)m_pOwningWorld)->FUN_00903760();
    LocalThreadMemory& threadMemory = *(LocalThreadMemory*)TlsGetValue(*(unsigned long*)0x010f3170);
    if (memNeeded > threadMemory.m_stack.getFreeBytes() && !((LocalMemory*)*(LocalMemory**)0x010f3400)->hasMemoryAvailable(memNeeded))
    {
        ((LocalMemory*)*(LocalMemory**)0x010f3400)->m_memoryState = 1;
        m_uiSimulationType = 1;
        HK_TIMER_END();
        return 1;
    }

    __declspec(align(16)) SimStepInfo stepInfo(m_fSimulationTime, m_fSimulationTime + m_fStepDeltaTime);
    ((LocalWorld*)m_pOwningWorld)->m_dynamicsStepInfo = stepInfo;
    ((LocalWorld*)m_pOwningWorld)->m_pCollisionInput->m_pStepInfo = stepInfo;
    ((LocalWorld*)m_pOwningWorld)->m_pMaintenanceManager->PerformMaintenance((SimWorld*)m_pOwningWorld, stepInfo);
    ((S_0097fd30_SimulationCall*)this)->FUN_0097f810(stepInfo);
    m_bHasStepped = 0;
    m_uiSimulationType = 0;
    HK_TIMER_END();
    return 0;
}


extern "C" void hkpSimulation_processAgentResetCollisionInformation();

struct S00cfa430_Data {
    char pad[0x78];
    int unk78;
};

struct MyObj : FUN_00cfa400_Obj {
    void FUN_00cfa430(void* first, void* second, S00cfa430_Data* data, unsigned char flags);
};

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_load_ss(const float* p);

struct FUN_00cfa7d0
{
    int m_0000;
    volatile int m_0004;
    int m_0008;
    int m_000C;
    int m_0010;
    int m_0014;
    unsigned char m_0018[8];
    __m128 m_0020;
    __m128 m_0030;
    __m128 m_0040;
    int m_0050;
    int m_0054;
    int m_0058;
    int m_005C;
    int m_0060;
    unsigned char m_0064[4];
    int m_0068;
    unsigned char m_006C;
    unsigned char m_006D;
    unsigned char m_006E[2];
    int m_0070;

    FUN_00cfa7d0(const FUN_00cfa7d0& rhs);
};

// Copy constructor: copies most members from rhs but not the byte arrays at 0x18, 0x64 and 0x6E, reading m_0004 twice.
// @fnv 0x00cfa7d0
FUN_00cfa7d0::FUN_00cfa7d0(const FUN_00cfa7d0& rhs)
{
    m_0000 = rhs.m_0000;
    m_0004 = rhs.m_0004;
    m_0008 = rhs.m_0008;
    m_000C = rhs.m_000C;
    m_0010 = rhs.m_0010;
    m_0014 = rhs.m_0014;
    m_0020 = rhs.m_0020;
    m_0030 = rhs.m_0030;
    m_0040 = rhs.m_0040;
    m_0050 = rhs.m_0050;
    m_0054 = rhs.m_0054;
    m_0058 = rhs.m_0058;
    m_005C = rhs.m_005C;
    m_0060 = rhs.m_0060;
    m_0068 = rhs.m_0068;
    m_006C = rhs.m_006C;
    m_006D = rhs.m_006D;
    m_0070 = rhs.m_0070;
    m_0004 = rhs.m_0004;
}

#include <math.h>
namespace MathUtilities {
    template <typename T>
    inline T min2(T a, T b) {
        return (a < b) ? a : b;
    }
}

struct Sim : hkpSimulation {
    float hkpSimulation_snapSimulateTimeAndGetTimeToAdvanceTo();
};

// @fnv 0x00cf89c0
// pdb: hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo | hkpSimulation.obj | fnv360_0822_retail, call_seq, high
// pdb: hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo | hkpSimulation.obj | fnv360_0822_retail, call_seq, high (was: GetClampedSimulationTime)
float Sim::hkpSimulation_snapSimulateTimeAndGetTimeToAdvanceTo() {
    if (m_fFrameMarkerTime != -1.0f) {
        if (fabsf(m_fFrameMarkerTime - m_fSimulationTime) < m_fFrameMarkerPsiSnap) {
            m_fFrameMarkerTime = m_fSimulationTime;
        }
    }
    float retVal;
    if (m_fFrameMarkerTime == -1.0f) {
        retVal = m_fSimulationTime;
    } else {
        retVal = MathUtilities::min2(m_fSimulationTime, m_fFrameMarkerTime);
    }
    return retVal;
}

class hkRefObjCF87 {
public:
    virtual ~hkRefObjCF87() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCF87() { m_sReferenceCount = 1; }
};

static __forceinline void S00cf8bc0_timer(const char* tag, hkReal& slot) {
    StringCursor* s = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* pos = s->m_commandSlice;
    if (pos < s->m_pRayCursor) {
        *(const char**)pos = tag;
        _ReadWriteBarrier();
        *(volatile hkUint32*)&slot = (hkUint32)__rdtsc();
        *(hkUint32*)(pos + 4) = *(volatile hkUint32*)&slot;
        pos += 12;
        s->m_commandSlice = pos;
    }
}
struct S00cf8bc0_Sim : hkpSimulation_Derived {
    int FUN_00cf8bc0();
};
// If m_uiSimulationType is non-zero, returns FUN_00cf8820(); else calls step by m_fStepDeltaTime, returning 2 if DAT_01269200 is 1, otherwise 0.
// @f3 0x0097f630 (community match, verified in this file)
// pdb: hkpSimulation::collide | hkpSimulation.obj | fnv360_0822_retail, vtable, medium
int S00cf8bc0_Sim::FUN_00cf8bc0()
{
    hkReal startTime;

    S00cf8bc0_timer("TtSimulate", startTime);

    if (m_uiSimulationType != 0)
    {
        int r = FUN_00cf8820();
        S00cf8bc0_timer("Et", startTime);
        return r;
    }

    startTime = m_fSimulationTime;

    hkStepInfo si;
    si.set(startTime, m_fSimulationTime + m_fStepDeltaTime);
    step(&si);

    int* pSimState = (int*)DAT_01269200;
    if (pSimState[1] == 1)
    {
        m_uiSimulationType = 2;
        S00cf8bc0_timer("Et", startTime);
        return 2;
    }

    m_fSimulationTime += m_fStepDeltaTime;

    if (((hkpWorld_Fields*)m_pOwningWorld)->unk154 != 0)
    {
        S00cf8bc0_timer("TtPostCollideCB", startTime);
        FUN_00d014f0(m_pOwningWorld, &si);
        S00cf8bc0_timer("Et", startTime);
    }

    m_bHasStepped = 1;
    m_uiSimulationType = 0;

    S00cf8bc0_timer("Et", startTime);
    return 0;
}


typedef unsigned int u32;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern const char str_010cc624[], str_010cc618[], str_010cc60c[], str_010cc5fc[];
extern const char str_010cc5f0[], str_010cc5e4[], str_010cc5d8[], str_01076f38[];
struct Arr;
extern "C" void __cdecl FUN_00cf7130(Arr*, Arr*);
extern "C" void __cdecl FUN_00d1a330(void*, void*, int);
struct Ctx64 { void __thiscall DispatchPairs(u32, int); void __thiscall FUN_00cf7080(u32, int, void*); };
struct MainObj {
 virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
 virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
 virtual void s20(); virtual void s24(); virtual void s28();
 virtual void __thiscall Proc(void*, void*, int, Arr*, Arr*);
};
struct AllocX {
 virtual void a00(); virtual void a04(); virtual void a08(); virtual void a0c();
 virtual void Free(void*, u32);
 virtual void a14(); virtual void a18(); virtual void a1c(); virtual void a20();
 virtual bool Test(u32);
};
struct Stream { int unk0; char* pos; int unk8; char* cap; };
struct TimerEvent { const char* tag; u32 stamp; u32 unk08; const char* subtag; };
typedef void* (__stdcall *TlsFn)(unsigned long);
static __forceinline void record16(TlsFn get,volatile u32& t){
 Stream* s=(Stream*)get(DAT_0126835c); TimerEvent* p=(TimerEvent*)s->pos;
 if((char*)p < s->cap){ p->tag=str_010cc624; p->subtag=str_010cc618; _ReadWriteBarrier(); t=(u32)__rdtsc(); p->stamp=t; s->pos=(char*)p+16; }
}
static __forceinline void record12(const char* tag, TlsFn get=TlsGetValue){
 Stream* s=(Stream*)get(DAT_0126835c); TimerEvent* p=(TimerEvent*)s->pos;
 if((char*)p < s->cap){ p->tag=tag; _ReadWriteBarrier(); volatile u32 t=(u32)__rdtsc(); p->stamp=t; s->pos=(char*)p+12; }
}
static __forceinline void recordInto(const char* tag, volatile u32& t, TlsFn get=TlsGetValue){
 Stream* s=(Stream*)get(DAT_0126835c); TimerEvent* p=(TimerEvent*)s->pos;
 if((char*)p < s->cap){ p->tag=tag; _ReadWriteBarrier(); t=(u32)__rdtsc(); p->stamp=t; s->pos=(char*)p+12; }
}
struct Arr { u32 data; int size; u32 cap; };
static __forceinline u32 stackAlloc(int size){
 FnvCpu_FUN_00cfa7a0_CpuAllocatorHolder* h=FUN_00c85750();
 u32 base=h->unk00; h->unk00=base+((size+127)&~127); return base;
}
static __forceinline void stackFree(u32 base){ FUN_00c85750()->unk00=base; }
static __forceinline void clear(Arr* a, AllocX* allocator){
 a->size=0;
 if(!(a->cap&0x80000000)) allocator->Free((void*)a->data,(a->cap&0x3fffffff)*8);
 a->data=0; a->cap=0x80000000;
}
struct LocalArr {
 Arr arr; u32 saved;
 __forceinline void init(int count){
  arr.data=0; arr.size=0; arr.cap=0x80000000;
  u32 base=stackAlloc(count*8);
  arr.data=base; arr.cap=count|0x80000000; saved=base;
 }
 __forceinline void release(){
  if(saved==arr.data) {arr.size=0;}
  stackFree(saved);
  FnvCpu_FUN_00cfa7a0_CpuAllocatorHolder* holder=FUN_00c85750();
  clear(&arr,(AllocX*)holder->allocator);
 }
};
struct Block16 { u32 f[4]; };
static __forceinline void copyBounds(void* destination, const void* source, int n){const u32* src=(const u32*)source; u32* dst=(u32*)destination; do{dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];dst[3]=src[3]; src+=4;dst+=4;}while(--n>0);}
struct EntityData {
 u32 unk00; u32 unk04; u32 unk08; u32 unk0c; u32 unk10; u32 unk14; u32 unk18; u32 unk1c;
 Block16 bounds[2];
};
struct Entity { u32 unk00; u32 unk04; u32 unk08; u32 unk0c; EntityData data; };
struct Optional { u32 unk00; u32 unk04; u32 payload; };
struct Context {
 u32 unk000;
 u32 unk004;
 u32 unk008;
 u32 unk00c;
 u32 unk010;
 u32 unk014;
 u32 unk018;
 u32 unk01c;
 u32 unk020;
 u32 unk024;
 u32 unk028;
 u32 unk02c;
 u32 unk030;
 u32 unk034;
 u32 unk038;
 u32 unk03c;
 u32 unk040;
 u32 unk044;
 u32 unk048;
 u32 unk04c;
 u32 unk050;
 u32 unk054;
 MainObj* main;
 u32 unk05c;
 u32 unk060;
 Ctx64* ctx64;
 u32 unk068;
 u32 unk06c;
 u32 unk070;
 u32 unk074;
 void* ctx78;
 Optional* optional;
 u32 unk080;
 u32 unk084;
 u32 unk088;
 u32 unk08c;
 u32 unk090;
 u32 unk094;
 u32 unk098;
 u32 unk09c;
 u32 unk0a0;
 u32 unk0a4;
 u32 unk0a8;
 u32 unk0ac;
 u32 unk0b0;
 u32 unk0b4;
 u32 unk0b8;
 u32 unk0bc;
 u32 unk0c0;
 u32 unk0c4;
 u32 unk0c8;
 u32 unk0cc;
 u32 unk0d0;
 u32 unk0d4;
 u32 unk0d8;
 u32 unk0dc;
 u32 unk0e0;
 u32 unk0e4;
 u32 unk0e8;
 u32 unk0ec;
 u32 unk0f0;
 u32 unk0f4;
 u32 unk0f8;
 u32 unk0fc;
 u32 unk100;
 u32 unk104;
 u32 unk108;
 u32 unk10c;
 u32 unk110;
 u32 unk114;
 u32 unk118;
 u32 unk11c;
 u32 unk120;
 u32 unk124;
 u32 unk128;
 u32 unk12c;
 u32 unk130;
 u32 unk134;
 u32 unk138;
 u32 unk13c;
 u32 unk140;
 u32 unk144;
 u32 unk148;
 u32 unk14c;
 u32 unk150;
 u32 unk154;
 u32 unk158;
 u32 unk15c;
 u32 unk160;
 u32 unk164;
 u32 unk168;
 u32 unk16c;
 u32 unk170;
 u32 unk174;
 u32 unk178;
 u32 unk17c;
 u32 unk180;
 u32 unk184;
 u32 unk188;
 u32 unk18c;
 u32 unk190;
 u32 unk194;
 u32 unk198;
 u32 unk19c;
 u32 unk1a0;
 u32 unk1a4;
 u32 unk1a8;
 u32 unk1ac;
 u32 unk1b0;
 u32 unk1b4;
 u32 unk1b8;
 u32 unk1bc;
 u32 unk1c0;
 u32 unk1c4;
 u32 unk1c8;
 u32 unk1cc;
 u32 unk1d0;
 u32 unk1d4;
 u32 unk1d8;
 u32 unk1dc;
 u32 unk1e0;
 u32 unk1e4;
 u32 unk1e8;
 u32 unk1ec;
 u32 unk1f0;
 u32 unk1f4;
 u32 unk1f8;
 u32 unk1fc;
 u32 unk200;
 u32 unk204;
 u32 unk208;
 u32 unk20c;
 u32 unk210;
 u32 unk214;
 u32 unk218;
 u32 unk21c;
 u32 unk220;
 u32 unk224;
 u32 unk228;
 u32 unk22c;
 u32 unk230;
 u32 unk234;
 u32 unk238;
 u32 unk23c;
 u32 unk240;
 u32 unk244;
 u32 unk248;
 u32 unk24c;
 u32 unk250;
 u32 unk254;
 u32 unk258;
 u32 unk25c;
 u32 unk260;
 u32 unk264;
 u32 unk268;
 u32 unk26c;
 u32 unk270;
 u32 unk274;
 u32 unk278;
 u32 unk27c;
 u32 unk280;
 u32 unk284;
 u32 unk288;
 u32 unk28c;
 u32 unk290;
 u32 unk294;
 u32 unk298;
 u32 unk29c;
 u32 unk2a0;
 u32 unk2a4;
 u32 unk2a8;
 u32 unk2ac;
 u32 unk2b0;
 u32 unk2b4;
 u32 unk2b8;
 u32 unk2bc;
 u32 unk2c0;
 u32 unk2c4;
 u32 unk2c8;
 u32 unk2cc;
 u32 unk2d0;
 u32 unk2d4;
 u32 unk2d8;
 u32 unk2dc;
 u32 unk2e0;
 u32 unk2e4;
 u32 unk2e8;
 u32 unk2ec;
 u32 unk2f0;
 u32 unk2f4;
 u32 unk2f8;
 u32 unk2fc;
 u32 unk300;
 u32 unk304;
 u32 unk308;
 u32 unk30c;
 u32 unk310;
 u32 unk314;
 u32 unk318;
 u32 unk31c;
 u32 unk320;
 u32 unk324;
 u32 unk328;
 u32 unk32c;
 u32 unk330;
 u32 unk334;
 u32 unk338;
 int count;
};
// Copies entity bounds to a stack buffer, runs a2->main->Proc to fill two arrays, then dispatches pairs through a2->ctx64 if the allocator check passes.
// @f3 0x009808f0 (community match, verified in this file)
extern TlsFn FUN_00d9b080;
static __forceinline void eventF3(const char* tag,TlsFn get) {
 Stream* s=(Stream*)get(DAT_0126835c); TimerEvent* p=(TimerEvent*)s->pos;
 if((char*)p<s->cap) { p->tag=tag; unsigned int ticks;
 __asm {
 rdtsc
 mov dword ptr[ticks], eax
 }
 p->stamp=ticks; s->pos=(char*)p+12; }
}
extern "C" void __cdecl FUN_0099a2d0(void*,void*,int);
struct CtxF3 {void __thiscall FUN_00984c50(u32,int,void*);};
struct BoolF3 { char value; };
struct MemoryF3 {
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
virtual BoolF3 query(u32);
int state;
};
extern const char str_00e7d3bc[];
extern const char str_00e7d3b0[];
extern const char str_00e7d3a4[];
extern const char str_00e7d394[];
extern const char str_00e7d388[];
extern const char str_00e7d37c[];
extern const char str_00e7d370[];
static __forceinline void beginF3(TlsFn get) { Stream* s=(Stream*)get(DAT_0126835c); TimerEvent* p=(TimerEvent*)s->pos; if((char*)p<s->cap) { p->tag=str_00e7d3bc; p->subtag=str_00e7d3b0; unsigned int ticks;
 __asm {
 rdtsc
 mov dword ptr[ticks], eax
 }
 p->stamp=ticks; s->pos=(char*)p+16; }}
extern "C" unsigned long DAT_010f3170;
struct StackAllocatorF3 {
 virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c(); virtual void s10();
 virtual u32 allocate(u32); virtual void release(u32);
 void __thiscall FUN_008f6d90(void*,u32,int);
 u32 unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; u32 top; u32 unk24; u32 overflow; u32 limit;
};
static __forceinline u32 allocF3(int size,TlsFn get) {
 StackAllocatorF3* a=(StackAllocatorF3*)get(DAT_010f3170);
 u32 n=(size+16)&~15; u32 p=a->top;
 u32 end=p+n; if(end<=a->limit) { a->top=end; return p; }
 return a->allocate(n);
}
static __forceinline void freeF3(u32 p,TlsFn get) {
 StackAllocatorF3* a=(StackAllocatorF3*)get(DAT_010f3170);
 a->top=p; if(p==a->overflow) a->release(p);
}
struct LocalArrF3 {
 Arr arr; u32 saved;
 __forceinline void init(int count,TlsFn get) {
 arr.data=0; arr.size=0; arr.cap=0x80000000; u32 base=allocF3(count*8,get);
 arr.data=base; saved=base; arr.cap=count|0x80000000;
 }
 __forceinline void release(TlsFn get) { freeF3(saved,get);
 if(!(arr.cap&0x80000000)) { u32 count=arr.cap&0x3fffffff; StackAllocatorF3* a=(StackAllocatorF3*)get(DAT_010f3170); a->FUN_008f6d90((void*)arr.data,count*8,0x17); } }
};
struct ContextF3 {
u32 unk000;
u32 unk004;
u32 unk008;
u32 unk00c;
u32 unk010;
u32 unk014;
u32 unk018;
u32 unk01c;
u32 unk020;
u32 unk024;
u32 unk028;
u32 unk02c;
u32 unk030;
u32 unk034;
u32 unk038;
u32 unk03c;
u32 unk040;
u32 unk044;
u32 unk048;
u32 unk04c;
u32 unk050;
MainObj* main;
Ctx64* ctx64;
u32 unk05c;
u32 unk060;
u32 unk064;
u32 unk068;
void* ctx78;
Optional* optional;
u32 unk074;
u32 unk078;
u32 unk07c;
u32 unk080;
u32 unk084;
u32 unk088;
u32 unk08c;
u32 unk090;
u32 unk094;
u32 unk098;
u32 unk09c;
u32 unk0a0;
u32 unk0a4;
u32 unk0a8;
u32 unk0ac;
u32 unk0b0;
u32 unk0b4;
u32 unk0b8;
u32 unk0bc;
u32 unk0c0;
u32 unk0c4;
u32 unk0c8;
u32 unk0cc;
u32 unk0d0;
u32 unk0d4;
u32 unk0d8;
u32 unk0dc;
u32 unk0e0;
u32 unk0e4;
u32 unk0e8;
u32 unk0ec;
u32 unk0f0;
u32 unk0f4;
u32 unk0f8;
u32 unk0fc;
u32 unk100;
u32 unk104;
u32 unk108;
u32 unk10c;
u32 unk110;
u32 unk114;
u32 unk118;
u32 unk11c;
u32 unk120;
u32 unk124;
u32 unk128;
u32 unk12c;
u32 unk130;
u32 unk134;
u32 unk138;
u32 unk13c;
u32 unk140;
u32 unk144;
u32 unk148;
u32 unk14c;
u32 unk150;
u32 unk154;
u32 unk158;
u32 unk15c;
u32 unk160;
u32 unk164;
u32 unk168;
u32 unk16c;
u32 unk170;
u32 unk174;
u32 unk178;
u32 unk17c;
u32 unk180;
u32 unk184;
u32 unk188;
u32 unk18c;
u32 unk190;
u32 unk194;
u32 unk198;
u32 unk19c;
u32 unk1a0;
u32 unk1a4;
u32 unk1a8;
u32 unk1ac;
u32 unk1b0;
u32 unk1b4;
u32 unk1b8;
u32 unk1bc;
u32 unk1c0;
u32 unk1c4;
u32 unk1c8;
u32 unk1cc;
u32 unk1d0;
u32 unk1d4;
u32 unk1d8;
u32 unk1dc;
u32 unk1e0;
u32 unk1e4;
u32 unk1e8;
u32 unk1ec;
u32 unk1f0;
u32 unk1f4;
u32 unk1f8;
u32 unk1fc;
u32 unk200;
u32 unk204;
u32 unk208;
u32 unk20c;
u32 unk210;
u32 unk214;
u32 unk218;
u32 unk21c;
u32 unk220;
u32 unk224;
u32 unk228;
u32 unk22c;
u32 unk230;
u32 unk234;
u32 unk238;
u32 unk23c;
u32 unk240;
u32 unk244;
u32 unk248;
u32 unk24c;
u32 unk250;
u32 unk254;
u32 unk258;
u32 unk25c;
u32 unk260;
u32 unk264;
u32 unk268;
u32 unk26c;
u32 unk270;
u32 unk274;
u32 unk278;
u32 unk27c;
u32 unk280;
u32 unk284;
u32 unk288;
u32 unk28c;
u32 unk290;
u32 unk294;
u32 unk298;
u32 unk29c;
u32 unk2a0;
u32 unk2a4;
u32 unk2a8;
u32 unk2ac;
u32 unk2b0;
u32 unk2b4;
u32 unk2b8;
u32 unk2bc;
u32 unk2c0;
u32 unk2c4;
u32 unk2c8;
u32 unk2cc;
u32 unk2d0;
u32 unk2d4;
u32 unk2d8;
u32 unk2dc;
u32 unk2e0;
u32 unk2e4;
u32 unk2e8;
u32 unk2ec;
u32 unk2f0;
u32 unk2f4;
u32 unk2f8;
int count;
};
void __cdecl FUN_00cf9c60(Entity** apEntities, int aiCount, Context* context){
 ContextF3* apContextF3=(ContextF3*)context;
 TlsFn get=FUN_00d9b080;
 int rem;
 beginF3(get);
 LocalArrF3 arrA; arrA.init(apContextF3->count,get);
 LocalArrF3 arrB; arrB.init(apContextF3->count,get);
 Block16* pBoundsBuffer=(Block16*)allocF3(aiCount*32,get);
 u32** pPointersBuffer=(u32**)allocF3(aiCount*4,get);
 eventF3(str_00e7d3a4,get);
 Entity** elems=apEntities;
 Block16* destination=(Block16*)pBoundsBuffer;
 rem=aiCount-1;
 if(rem>=0){
 int pointerDifference=(char*)pPointersBuffer-(char*)elems;
 do {
  Entity* e=*elems;
  EntityData* data=&e->data;
  *(u32**)((char*)elems+pointerDifference)=&data->unk14;
  Block16* src=data->bounds;
  if(src[0].f[0] > src[1].f[0]) FUN_0099a2d0(apContextF3->ctx78, &e, 1);
  copyBounds((void*)destination,data->bounds,2);
  destination=(Block16*)((Block16*)destination+2);
  ++elems;
 } while(--rem>=0);
 }
 u32 pointerBase=(u32)pPointersBuffer;
 eventF3(str_00e7d394,get);
 apContextF3->main->Proc((void*)pointerBase,(void*)pBoundsBuffer,aiCount,&arrA.arr,&arrB.arr);
 freeF3(pointerBase,get);
 freeF3((u32)pBoundsBuffer,get);
 if(arrA.arr.size+arrB.arr.size>0){
  eventF3(str_00e7d388,get);
  FUN_00cf7130(&arrA.arr,&arrB.arr);
  eventF3(str_00e7d37c,get);
  apContextF3->ctx64->DispatchPairs(arrB.arr.data,arrB.arr.size);
  int size=arrA.arr.size;
  if(!((MemoryF3*)DAT_010f3400)->query((u32)(size*5)<<7).value){
   ((MemoryF3*)DAT_010f3400)->state=1;
   eventF3(str_01076f38,get);
   arrB.release(get); arrA.release(get); return;
  }
  eventF3(str_00e7d370,get);
  ((CtxF3*)apContextF3->ctx64)->FUN_00984c50(arrA.arr.data,arrA.arr.size,apContextF3->optional ? &apContextF3->optional->payload : 0);
 }
 eventF3(str_01076f38,get);
finish:
 arrB.release(get);
 arrA.release(get);
}


extern const char str_01076f38[];
extern const char str_010c41f8[];
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern unsigned long DAT_0126835c;
struct CommandTimingEntry { const char* name; unsigned int time; unsigned int timeHigh; };
struct TimerListCommand { const char* name; unsigned int time; unsigned int timeHigh; const char* first; };
struct MonitorStream {
    char* start; char* end; char* capacity; char* limit;
    static MonitorStream* get() { return (MonitorStream*)TlsGetValue(DAT_0126835c); }
    void timer(const char* name, unsigned int& ticks) {
        if (end < limit) {
            CommandTimingEntry* cmd = (CommandTimingEntry*)end;
            cmd->name = name;
            _ReadWriteBarrier();
            (volatile unsigned int&)ticks = (unsigned int)__rdtsc();
            cmd->time = ticks;
            end = (char*)(cmd + 1);
        }
    }
    void list(const char* name, const char* first, unsigned int& ticks) {
        if (end < limit) {
            TimerListCommand* cmd = (TimerListCommand*)end;
            cmd->name = name;
            cmd->first = first;
            _ReadWriteBarrier();
            (volatile unsigned int&)ticks = (unsigned int)__rdtsc();
            cmd->time = ticks;
            end = (char*)(cmd + 1);
        }
    }
};
struct TimeInterval { float startTime, endTime, deltaTime, invDeltaTime; };
struct SolverInfo {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    __m128 gravityPerStep;
    __m128 gravityPerFrame;
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
    void* collisionInput78;
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
    unsigned char unk0d4;
    unsigned char callbackEnabled;
    unsigned short unk0d6;
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
    float deltaTime;
    float invDeltaTime;
    int numSteps;
    unsigned int unk118;
    unsigned int unk11c;
    float tau;
    unsigned char flags0;
    unsigned char flags;
    unsigned char bufferIndex;
    unsigned char frameCounter;
    unsigned int unk128;
    unsigned int unk12c;
};
struct MemoryRequirements;
class WorldFull;
struct Island {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    int numConstraints;
    unsigned int unk010;
    unsigned int unk014;
    WorldFull* world;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned short flags0;
    unsigned char flags; unsigned char unk027;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    void* entities;
    int numEntities;
};

struct MemoryRequirements { int max, sum; Island* biggest; };
class WorldFull { public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    __m128 gravity;
    unsigned int unk020;
    unsigned int unk024;
    hkArray<Island*> activeIslands;
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
    void* collisionInput78;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    void* pendingOperations;
    void* pendingBodyOperations;
    int lockCount;
    int phantomLockCount;
    unsigned char blockPendingOperations;
    unsigned char unk09d;
    unsigned short unk09e;
    unsigned int unk0a0;
    int bodyOperationMode;
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
    unsigned char unk0d4;
    unsigned char callbackEnabled;
    unsigned short unk0d6;
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
    int worldCallbacks;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    int islandCallbacks;
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
    void* collisionInput;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    TimeInterval stepInfo;
    SolverInfo solver;
    __declspec(noinline) void ComputeMemoryUsage(MemoryRequirements*);
    int FUN_00c93570();
    void FUN_00c91120();
    void FUN_00c91140();
    __forceinline void unlock() {
        if (--lockCount == 0 && !blockPendingOperations) {
            if (pendingOperations) FUN_00c91120();
            if (bodyOperationMode == 1 && pendingBodyOperations) FUN_00c91140();
        }
    }
};

struct __declspec(align(16)) IntegrationContext {
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
    hkVector4 tolerance;
    unsigned int unk060;
    unsigned int unk064;
    void* collisionInput;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    void* collisionInput78;
    unsigned int unk07c;
    void FUN_00cfa6e0(SolverInfo*, const TimeInterval*, void*);
};
extern "C" int __cdecl FUN_00d28a30(SolverInfo*, TimeInterval*, void*, void*, int, int);
extern "C" void __cdecl FUN_00d1a330(void*, void*, int);
struct Simulation {
    unsigned int unk00, unk04, unk08;
    WorldFull* m_pOwningWorld;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int m_uiSimulationType;
    void FUN_00cf8b00();
    int FUN_00cf8da0(const TimeInterval* step);
};
// Advances the simulation by one time step, integrating island entities and invoking world and island callbacks.
// @f3 0x0097f810 (community match, verified in this file)
// Integrates every active simulation island for one step: sets up the solver step values, applies actions,
// steps or solves each island, and fires the post-integrate callbacks. Timer commands are written to the
// per-thread monitor stream along the way.
namespace sim97f810 {
struct World;
struct Island;
struct StepInfo {
    float startTime;
    float endTime;
    float deltaTime;
    float invDeltaTime;
};
// Four-lane float vector.
__declspec(align(16)) struct Vector4 {
    float x, y, z, w;
    void setMul4(const float& rs, const Vector4& a)
    {
        float r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
};
struct SolverInfo {
    int unk000, unk004, unk008, unk00C;
    Vector4 globalAccelerationPerSubStep;
    Vector4 globalAccelerationPerStep;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108;
    float deltaTime;
    float invDeltaTime;
    int numSteps;
    int numMicroSteps;
    float invNumMicroSteps;
    float invNumSteps;
    unsigned char forceCoherentOrdering;
    unsigned char deactivationFlags;
    unsigned char deactivationBuffer;
    unsigned char deactivationCounter;
    void incrementDeactivationFlags()
    {
        unsigned char counter = ++deactivationCounter;
        if (((counter - 4) & 7) == 0)
            deactivationFlags ^= 1;
        if ((counter & 7) == 0)
            deactivationFlags ^= 2;
        if ((counter & 15) == 0) {
            deactivationBuffer = 1 - deactivationBuffer;
            deactivationCounter = 0;
        }
    }
};
// The step values shared by every island of a world.
struct DynamicsStepInfo {
    StepInfo stepInfo;
    SolverInfo solverInfo;
};
template <class T> struct Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const { return m_size; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    T* begin() { return m_data; }
};
__declspec(align(16)) struct ConstraintQueryIn {
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    void FUN_00981430(const SolverInfo& solverInfo, const StepInfo& stepInfo);
};
struct World {
    int unk000, unk004, unk008, unk00C;
    Vector4 gravity;
    int unk020, unk024;
    Array<Island*> activeIslands;
    int unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068;
    void* collisionInput;
    int unk070, unk074, unk078, unk07C;
    int pendingOperationsCount;
    int criticalOperationsLockCount;
    int criticalOperationsLockCountForPhantoms;
    unsigned char blockExecutingPendingOperations;
    unsigned char criticalOperationsAllowed;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0;
    unsigned char enableToiWeldRejection;
    unsigned char wantDeactivation;
    int unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4;
    int unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124;
    int unk128, unk12C, unk130, unk134, unk138, unk13C, unk140;
    Array<void*> worldPostIntegrateListeners;
    int unk150, unk154, unk158;
    Array<void*> islandPostIntegrateListeners;
    int unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C;
    DynamicsStepInfo dynamicsStepInfo;
    void FUN_00902550();
    void lockCriticalOperations() { criticalOperationsLockCount++; }
    void unlockCriticalOperations() { criticalOperationsLockCount--; }
    void unlockAndAttemptToExecutePendingOperations()
    {
        criticalOperationsLockCount--;
        if (criticalOperationsLockCount == 0 && !blockExecutingPendingOperations) {
            if (pendingOperationsCount)
                FUN_00902550();
        }
    }
};
struct Island {
    int unk000, unk004, unk008;
    int sizeOfJacobians;
    int unk010, unk014;
    World* world;
    int unk01C, unk020;
    unsigned short storageIndex;
    unsigned char flags;
    unsigned char flags2;
    int unk028, unk02C, unk030, unk034, unk038, unk03C, unk040, unk044;
    Array<void*> entities;
};

struct TimerCommand {
    const char* m_commandAndMonitor;
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
struct TimerBeginListCommand : TimerCommand {
    const char* m_nameOfFirstSplit;
};
struct MonitorStream {
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
    static MonitorStream& getInstance() { return *(MonitorStream*)TlsGetValue(DAT_0126835c); }
    bool memoryAvailable() const { return m_end < m_capacityMinus16; }
    void* getEnd() { return m_end; }
    void setEnd(void* ptr) { m_end = (char*)ptr; }
};
__forceinline void timerCommand(const char* name)
{
    MonitorStream& stream = MonitorStream::getInstance();
    if (stream.memoryAvailable()) {
        TimerCommand* h = (TimerCommand*)stream.getEnd();
        h->m_commandAndMonitor = name;
        h->setTime();
        stream.setEnd(h + 1);
    }
}
__forceinline void timerBeginList(const char* name, const char* firstSplit)
{
    MonitorStream& stream = MonitorStream::getInstance();
    if (stream.memoryAvailable()) {
        TimerBeginListCommand* h = (TimerBeginListCommand*)stream.getEnd();
        h->m_commandAndMonitor = name;
        h->m_nameOfFirstSplit = firstSplit;
        h->setTime();
        stream.setEnd(h + 1);
    }
}

extern "C" void __cdecl FUN_00a0b770();
extern "C" void __cdecl FUN_00927c80(World* world);
extern "C" int __cdecl hkRigidMotionUtilApplyForcesAndStep(const SolverInfo& solverInfo, const StepInfo& stepInfo, const Vector4& acceleration,
                                    void** motions, int numMotions, int motionOffset);
extern "C" void __cdecl FUN_0099a2d0(void* collisionInput, void** entities, int numEntities);
extern "C" int __cdecl FUN_00a0b010(const StepInfo& stepInfo, const SolverInfo& solverInfo,
                                    ConstraintQueryIn& constraintQueryIn, Island& island, void** entities,
                                    int numEntities);
extern "C" void __cdecl hkpWorldOperationUtil_markIslandInactive(World* world, Island* island);
extern "C" void __cdecl FUN_009894a0(World* world, Island* island, const StepInfo& stepInfo);
extern "C" void __cdecl hkpWorldCallbackUtil_firePostIntegrateCallback(World* world, const StepInfo& stepInfo);

struct Simulation {
    int unk00, unk04, unk08;
    World* m_world;
    void FUN_0097f4f0();
    __forceinline void integrateInternal(const StepInfo& stepInfoIn);
};

__forceinline void Simulation::integrateInternal(const StepInfo& stepInfoIn)
{
    timerBeginList("LtIntegrate", "StInit");

    m_world->dynamicsStepInfo.stepInfo = stepInfoIn;

    SolverInfo& solverInfo = m_world->dynamicsStepInfo.solverInfo;
    solverInfo.deltaTime = stepInfoIn.deltaTime * solverInfo.invNumSteps;
    solverInfo.invDeltaTime = stepInfoIn.invDeltaTime * solverInfo.numSteps;

    solverInfo.globalAccelerationPerSubStep.setMul4(solverInfo.deltaTime, m_world->gravity);
    float deltaTime = stepInfoIn.deltaTime;
    solverInfo.globalAccelerationPerStep.setMul4(deltaTime, m_world->gravity);

    FUN_00a0b770();
    FUN_00927c80(m_world);

    m_world->lockCriticalOperations();
    m_world->criticalOperationsLockCountForPhantoms--;
    timerCommand("StActions");
    FUN_0097f4f0();
    m_world->criticalOperationsLockCountForPhantoms++;
    m_world->unlockAndAttemptToExecutePendingOperations();

    m_world->lockCriticalOperations();
    m_world->dynamicsStepInfo.solverInfo.incrementDeactivationFlags();

    ConstraintQueryIn constraintQueryIn;
    constraintQueryIn.FUN_00981430(m_world->dynamicsStepInfo.solverInfo, stepInfoIn);

    timerCommand("StIntegrate");
    {
        const Array<Island*>& activeIslands = m_world->activeIslands;
        for (int i = activeIslands.getSize() - 1; i >= 0; i--) {
            Island* island = activeIslands[i];
            int numInactiveFrames;
            DynamicsStepInfo& info = m_world->dynamicsStepInfo;
            if (island->sizeOfJacobians == 0) {
                timerCommand("TtSingleObj");
                numInactiveFrames = hkRigidMotionUtilApplyForcesAndStep(info.solverInfo, info.stepInfo,
                                                 info.solverInfo.globalAccelerationPerStep,
                                                 island->entities.begin(), island->entities.getSize(), 0xd0);
                FUN_0099a2d0(island->world->collisionInput, island->entities.begin(), island->entities.getSize());
                timerCommand("Et");
            } else {
                numInactiveFrames = FUN_00a0b010(info.stepInfo, info.solverInfo, constraintQueryIn, *island,
                                                 island->entities.begin(), island->entities.getSize());
            }
            if (numInactiveFrames > 5) {
                if ((island->flags & 0xc) && island->world->wantDeactivation)
                    hkpWorldOperationUtil_markIslandInactive(island->world, island);
            }
            if (m_world->islandPostIntegrateListeners.getSize()) {
                timerCommand("StIslandPostIntegrateCb");
                FUN_009894a0(m_world, island, stepInfoIn);
            }
        }
    }
    m_world->unlockAndAttemptToExecutePendingOperations();

    if (m_world->worldPostIntegrateListeners.getSize()) {
        timerCommand("TtWorldPostIntegrateCb");
        hkpWorldCallbackUtil_firePostIntegrateCallback(m_world, stepInfoIn);
        timerCommand("Et");
    }
    timerCommand("lt");
}
}

// The stand-in classes of the pack for the world, its step record and the island do not describe the layouts
// used here, so the body is written on the layouts above. The pack declares an int result; the function in the
// image leaves the result register unset at its exit, so no value is returned here either.
int Simulation::FUN_00cf8da0(const TimeInterval* step)
{
    ((sim97f810::Simulation*)this)->integrateInternal(*(const sim97f810::StepInfo*)step);
}


#include <string.h>
extern "C" void _ReadWriteBarrier(void);

extern "C" unsigned __int64 __cdecl __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_0126835c;
extern "C" int DAT_01269200;
struct TraceEntry { const char* m_name; unsigned int m_low; unsigned int m_high; };
struct TraceState { unsigned int unk00; TraceEntry* m_next; unsigned int unk08; TraceEntry* m_last; };
__forceinline void stamp(const char* name, volatile unsigned int& clockSlot) {
 TraceState* t = (TraceState*)TlsGetValue(DAT_0126835c);
 TraceEntry* e = t->m_next;
 if (e < t->m_last) {
  e->m_name = name;
  unsigned int ticks;
  __asm {
      rdtsc
      mov dword ptr[ticks], eax
  }
  e->m_low = ticks;
  t->m_next = e + 1;
 }
}
struct S00cfa080_Info {
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
 float m_10c;
 float m_110;
 int m_114;
 unsigned int unk118;
 unsigned int unk11c;
 float m_120;
 void setStep(const hkVector4* p) {
  m_10c = p->z * m_120;
  m_110 = (float)m_114 * p->w;
 }
};
struct O;
struct W {
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
unsigned char unk09c; unsigned char unk09d, unk09e, unk09f;
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
unsigned int unk298;
unsigned int unk29c;
unsigned int unk2a0;
unsigned int unk2a4;
unsigned int unk2a8;
unsigned int unk2ac;
unsigned int unk2b0;
unsigned int unk2b4;
unsigned int unk2b8;
unsigned int unk2bc;
unsigned int unk2c0;
unsigned int unk2c4;
unsigned int unk2c8;
unsigned int unk2cc;
unsigned int unk2d0;
unsigned int unk2d4;
unsigned int unk2d8;
unsigned int unk2dc;
unsigned int unk2e0;
unsigned int unk2e4;
unsigned int unk2e8;
unsigned int unk2ec;
unsigned int unk2f0;
unsigned int unk2f4;
unsigned int unk2f8;
unsigned int unk2fc;
unsigned int unk300;
void __thiscall FUN_00c91120();
hkArray<O*>& islands() { return *(hkArray<O*>*)&unk028; }
S00cfa080_Info& solver() { return *(S00cfa080_Info*)&unk1e0; }
void __thiscall FUN_00c91140();
};
struct O { unsigned int unk000;
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
unsigned int unk060; };
struct S00cfa080_Obj {
 unsigned int unk00, unk04, unk08; W* m_pOwningWorld;
 void __thiscall FUN_00cfa080(hkVector4* p);
};
extern "C" void __cdecl FUN_00cf9c60(unsigned int, unsigned int, W*);
__forceinline void stampN(const char* name) {
 TraceState* t = (TraceState*)TlsGetValue(DAT_0126835c);
 TraceEntry* e = t->m_next;
 if (e < t->m_last) {
  e->m_name = name;
  unsigned int ticks;
  __asm {
      rdtsc
      mov dword ptr[ticks], eax
  }
  e->m_low = ticks;
  t->m_next = e + 1;
 }
}
__forceinline void stampEnd() {
 TraceState* t = (TraceState*)TlsGetValue(DAT_0126835c);
 TraceEntry* e = t->m_next;
 if (e < t->m_last) {
  e->m_name = str_010c41f8;
  unsigned int ticks;
  __asm {
      rdtsc
      mov dword ptr[ticks], eax
  }
  e->m_low = ticks;
  t->m_next = e + 1;
 }
}
__forceinline void done(W* w) {
 if (--w->unk094 == 0 && w->unk09c == 0) {
  if(w->unk08c != 0) w->FUN_00c91120();
  if(w->unk0a4 == 1 && w->unk090 != 0) w->FUN_00c91140();
 }
}
// @f3 0x00980db0 (community match, verified in this file)
extern char DAT_00e7d3e4[], DAT_00e7d2e4[], DAT_00e7d3cc[];

struct NativeWorldCalls { void FUN_00902550(); };
extern "C" void __cdecl FUN_009808f0(unsigned, unsigned, W*);
extern "C" void __cdecl hkAgentNnMachine_ProcessTrack(O*, void*, O*);
extern "C" void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(W*, O*, hkVector4*);

// Leaves the world's critical section and runs the pending operations when this was the last lock.
__forceinline void NativeDone(W* w) {
 if (--w->unk084 == 0 && static_cast<unsigned char>(w->unk08c) == 0 && w->unk080 != 0)
  reinterpret_cast<NativeWorldCalls*>(w)->FUN_00902550();
}

// Collide step of the simulation: stores the step info in the world and its collision input, runs the
// broad phase over every active island, then the narrow phase and the post-collide listeners per island.
// Stops early, releasing the lock, when the memory system reports it is out of memory.
// pdb: hkpSimulation::collideInternal | hkpSimulation.obj | fnv360_0822_retail, vtable, medium
// pdb params: stepInfoIn
void S00cfa080_Obj::FUN_00cfa080(hkVector4* p) {
 stampN(DAT_00e7d3e4);
 memcpy(&m_pOwningWorld->unk190, p, sizeof(hkVector4));
 O* o = (O*)m_pOwningWorld->unk06c;
 *(hkVector4*)&o->unk050 = *p;
 W* physics = m_pOwningWorld;
 reinterpret_cast<S00cfa080_Info*>(&physics->unk1a0)->setStep(p);
 ++m_pOwningWorld->unk084;
 hkArray<O*>* a = (hkArray<O*>*)&m_pOwningWorld->unk028;
 for (int i = 0; i < a->m_iElementCount; ++i) {
  O* e = a->m_data[i];
  FUN_009808f0(e->unk048, e->unk04c, m_pOwningWorld);
  if (DAT_010f3400[1] == 1) {
   NativeDone(m_pOwningWorld);
   stampEnd();
   return;
  }
 }
 NativeDone(m_pOwningWorld);
 ++m_pOwningWorld->unk084;
 const hkArray<O*>* list = &m_pOwningWorld->islands();
 O* entry;
 for (int j = 0; j < list->m_iElementCount; ++j) {
  entry = list->m_data[j];
  O* obj = (O*)m_pOwningWorld->unk06c;
  stampN(DAT_00e7d2e4);
  obj->unk060 = obj->unk000 + 0x1c60;
  obj->unk010 = 0;
  hkAgentNnMachine_ProcessTrack(entry, &entry->unk058, obj);
  stampN(str_010c41f8);
  if (DAT_010f3400[1] == 1) {
   NativeDone(m_pOwningWorld);
   stampEnd();
   return;
  }
  if (m_pOwningWorld->unk16c != 0) {
   stampN(DAT_00e7d3cc);
   hkpWorldCallbackUtil_fireIslandPostCollideCallback(m_pOwningWorld, entry, p);
   stampN(str_010c41f8);
  }
 }
 NativeDone(m_pOwningWorld);
 stampEnd();
}


namespace fnv_00cf8b00 {
struct Entity {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Process(void* info);
};

struct EntityArray {
    Entity** m_data;
    int m_iElementCount;
};

struct Island {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    EntityArray m_kActorEntries;
};

struct IslandArray {
    Island** m_data;
    int m_iElementCount;
};

struct World {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    IslandArray m_islands;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    int unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc;
    int m_info;
};

struct Sim {
    int unk00;
    int unk04;
    int unk08;
    World* m_pOwningWorld;
    void FUN_00cf8b00();
};

}  // namespace fnv_00cf8b00

extern "C" {
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    float _mm_cvtss_f32(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, __m128);
    void _mm_store_ss(float*, __m128);
}
struct Allocator {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void freeBlock(void*, int);
};
struct MemoryRouter { int unk00, unk04, unk08, unk0c; Allocator* heap; };

struct Pair;
struct PairEntry { Pair* pair; int key; };
struct PairArray { PairEntry* data; int size, capacity; };
struct PairMap {
    int* data; int size, mask;
    void __thiscall EnsureCapacity(Allocator*, int);
    void __thiscall FUN_00cb1870(Allocator*, void*, int);
    int __thiscall FindSlot(int);
    void __thiscall ProcessArgument(Allocator*);
    void __thiscall FUN_00a29680();
};
struct RootBody {
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
    int owner;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char type; unsigned char flags, quality, state;
};
struct Collidable {
    void* shape; int shapeKey; void* motion; void* parent;
    signed char ownerOffset; unsigned char force, shapeSize, flags;
    RootBody* root() { return reinterpret_cast<RootBody*>(reinterpret_cast<char*>(this) + ownerOffset); }
    void __thiscall CopyAndSortGeometryList(PairArray*);
};
struct Pair {
    int unk00, unk04, unk08, unk0c;
    Collidable* bodyA; Collidable* bodyB;
};
struct Quaternion {
    __m128 value;
    void __thiscall hkQuaternion_setAxisAngle(const __m128*, float);
    void __thiscall FUN_00c66320(const Quaternion*, const Quaternion*);
    void __thiscall FUN_00c74b70(const Quaternion*, const Quaternion*);
};
struct Transform {
    hkRotation rotation;
    hkVector4 translation;
    void __thiscall FUN_00cb2d90(const Quaternion*);
};
struct MotionHeader {
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
    virtual void restore(const hkTransform*);
    int unk04, unk08, unk0c;
};
struct Motion : MotionHeader {
    Transform transform;
    hkVector4 centerOfMass0, centerOfMass1;
    Quaternion rotation0, rotation1;
    hkVector4 localCenter;
};
struct Body {
    int unk00, unk04, unk08, unk0c;
    Collidable collidable;
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
    Motion motion;
};
struct CollisionStep { float startTime, endTime, deltaTime; };
struct CollisionInput {
    int unk00, unk04; float tolerance;
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
    CollisionStep* step;
};
struct AlignedPairData { __m128 position, normal; int id; void* properties; int userData, flags; };
struct CollisionOutput {
    AlignedPairData* firstFree;
    int owner, unk08, unk0c;
    AlignedPairData contacts[256];
    __m128 toiPosition, toiNormal;
    float toiTime;
    void* toiProperties; int toiId, toiFlags, toiUserData, toiMaterial, toiShapeKey, toiState;
    float separatingVelocity, rotateNormal;
    int tail00, tail04, tail08, tail0c, tail10, tail14, tail18, tail1c, tail20, tail24, tail28, tail2c;
};
typedef void (__thiscall *ProcessCallback)(void*, Pair*, CollisionInput*, CollisionOutput*);
float __cdecl ClampAsin(float);
extern int DAT_01269200;
extern const __m128 DAT_010c44d0;
extern const double DAT_010cc5d0;
extern const double DAT_01082cb0;
inline __m128 loadVector(const hkVector4& v) { return _mm_load_ps(&v.x); }
inline __m128 dotVector(__m128 a, __m128 b) {
    __m128 p=_mm_mul_ps(a,b);
    return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p));
}
__forceinline void updateTranslation(Body* body) {
    Transform& t=body->motion.transform;
    __m128 v=loadVector(body->motion.localCenter);
    __m128 transformed=_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),loadVector(t.rotation.m_kColumn1)),
                                            _mm_mul_ps(_mm_shuffle_ps(v,v,0),loadVector(t.rotation.m_kColumn0))),
                                  _mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),loadVector(t.rotation.m_kColumn2)));
    _mm_store_ps(&t.translation.x,_mm_sub_ps(loadVector(body->motion.centerOfMass1),transformed));
}
struct SavedTransform {
    __m128 col0, col1, col2, translation;
};
struct Vec4f { int x, y, z, w; };
__forceinline void copySnapshot(Vec4f& dest,const void* value) { const Vec4f& src=*reinterpret_cast<const Vec4f*>(value); dest.x=src.x; dest.y=src.y; dest.z=src.z; dest.w=src.w; }
inline void releaseAll(PairArray& pairs, PairMap& visited) {
    MemoryRouter* router=(MemoryRouter*)FUN_00c85750();
    Allocator* heap=router->heap;
    pairs.size=0;
    if((pairs.capacity&0x80000000)==0) heap->freeBlock(pairs.data,(pairs.capacity&0x3fffffff)*8);
    pairs.data=0; pairs.capacity=0x80000000;
    Allocator* finalHeap=((MemoryRouter*)FUN_00c85750())->heap;
    visited.ProcessArgument(finalHeap);
    visited.FUN_00a29680();
}
inline float hkMaxF(float a,float b){return a>b?a:b;}
struct SimulationContext {
    void __thiscall FUN_00cf9480(Body**, int, CollisionInput*, ProcessCallback, int);
};
// Iterates over bodies, collects collision pairs, invokes callback for each, and applies corrective rotations when mode is 1 and a contact is found.
// @fnv 0x00cf9480
void __thiscall SimulationContext::FUN_00cf9480(Body** bodies, int count, CollisionInput* input, ProcessCallback callback, int mode) {
    PairMap visited;
    visited.data=0; visited.size=0; visited.mask=-1;
    MemoryRouter* router=(MemoryRouter*)FUN_00c85750(); Allocator* initialHeap=router->heap;
    visited.EnsureCapacity(initialHeap,count);
    __declspec(align(16)) CollisionOutput collisionOutput;
    collisionOutput.toiTime=3.402820018375656e38f;
    collisionOutput.owner=0;
    collisionOutput.rotateNormal=collisionOutput.separatingVelocity=0.0f;
    PairArray pairs;
    pairs.data=0; pairs.size=0; pairs.capacity=0x80000000;
    for(int i=0;i<count;++i) {
        Body* body=bodies[i];
        Collidable* root=&body->collidable;
        router=(MemoryRouter*)FUN_00c85750(); Allocator* currentHeap=router->heap;
        visited.FUN_00cb1870(currentHeap,root,0);
        root->CopyAndSortGeometryList(&pairs);
        for(int j=0;j<pairs.size;++j) {
            PairEntry* finalHeap=&pairs.data[j]; int key=finalHeap->key;
            if(visited.FindSlot(key)>visited.mask) {
                Pair* pair=finalHeap->pair;
                RootBody* collidable=pair->bodyA->root();
                Collidable* otherBody=pair->bodyB;
                int owner;
                if(collidable->type==5) owner=otherBody->root()->owner; else owner=collidable->owner;
                collisionOutput.owner=owner;
                FUN_00cfdbe0((int)pair,(int)input);
                callback(this,pair,input,&collisionOutput);
                if(mode==1 && collisionOutput.firstFree!=collisionOutput.contacts) {
                    Vec4f angle; copySnapshot(angle,&body->motion.rotation1);
                    Transform& transform=body->motion.transform;
                    Vec4f sCol2, sTrans, sCol1, sCol0;
                    copySnapshot(sCol0,&transform.rotation.m_kColumn0);
                    const __m128& copy_col0=*(const __m128*)&sCol0.x;
                    copySnapshot(sCol1,&transform.rotation.m_kColumn1);
                    const __m128& copy_col1=*(const __m128*)&sCol1.x;
                    copySnapshot(sCol2,&transform.rotation.m_kColumn2);
                    const __m128& copy_col2=*(const __m128*)&sCol2.x;
                    copySnapshot(sTrans,&transform.translation);
                    const __m128& copy_translation=*(const __m128*)&sTrans.x;
                    SavedTransform savedTransform;
                    savedTransform.col0=copy_col0;
                    savedTransform.col1=copy_col1;
                    savedTransform.col2=copy_col2;
                    savedTransform.translation=copy_translation;
                    Vec4f normalCopy; copySnapshot(normalCopy,&collisionOutput.contacts[0].normal);
                    if(finalHeap->pair->bodyA!=root) _mm_store_ps(reinterpret_cast<float*>(&normalCopy.x),_mm_xor_ps(collisionOutput.contacts[0].normal,DAT_010c44d0));
                    __m128 normal=_mm_load_ps(reinterpret_cast<float*>(&normalCopy.x));
                    __m128 delta=_mm_sub_ps(*(const __m128*)&body->motion.centerOfMass1,collisionOutput.contacts[0].position);
                    __m128 normalZXY=_mm_shuffle_ps(normal,normal,0xd2);
                    __m128 normalYZX=_mm_shuffle_ps(normal,normal,0xc9);
                    __m128 axis=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(delta,delta,0xd2),normalYZX),
                                          _mm_mul_ps(_mm_shuffle_ps(delta,delta,0xc9),normalZXY));
                    float axisLength; _mm_store_ss(&axisLength,_mm_sqrt_ss(dotVector(axis,axis)));
                    float projection; _mm_store_ss(&projection,dotVector(delta,normal));
                    float distance; _mm_store_ss(&distance,_mm_sqrt_ss(dotVector(delta,delta)));
                    float cosine=projection/distance;
                    if(axisLength>0.00001f && cosine<DAT_010cc5d0) {
                        float savedTolerance=input->tolerance;
                        float tolerance=input->tolerance*20.0;
                        input->tolerance=tolerance;
                        float savedStart=input->step->endTime;
                        float savedEnd=input->step->deltaTime;
                        input->step->endTime=tolerance;
                        input->step->deltaTime=tolerance;
                        float newCosine=hkMaxF((projection-tolerance*DAT_01082cb0)/distance,0.0f);
                        volatile float oldAngle=ClampAsin(cosine); double newAngle=ClampAsin(newCosine); float savedRotation=oldAngle-newAngle;
                        float inverseLength=1.0f/axisLength;
                        __m128 inverseScalar=_mm_load_ss(&inverseLength);
                        axis=_mm_mul_ps(_mm_shuffle_ps(inverseScalar,inverseScalar,0),axis);
                        Quaternion turn, rotated;
                        turn.hkQuaternion_setAxisAngle(&axis,savedRotation);
                        rotated.FUN_00c66320(&turn,&body->motion.rotation1);
                        transform.FUN_00cb2d90(&rotated);
                        updateTranslation(body);
                        FUN_00cfdbe0((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                        __m128 perpendicular=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(axis,axis,0xc9),normalZXY),
                                                       _mm_mul_ps(_mm_shuffle_ps(axis,axis,0xd2),normalYZX));
                        __m128 length=dotVector(perpendicular,perpendicular);
                        __m128 reciprocal=_mm_rsqrt_ss(length);
                        __m128 refined=_mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f),reciprocal),
                            _mm_sub_ss(_mm_set_ss(3.0f),_mm_mul_ss(_mm_mul_ss(length,reciprocal),reciprocal)));
                        refined=_mm_andnot_ps(_mm_cmpeq_ss(length,_mm_set_ss(0.0f)),refined);
                        perpendicular=_mm_mul_ps(_mm_shuffle_ps(refined,refined,0),perpendicular);
                        Quaternion sideways, oriented;
                        sideways.hkQuaternion_setAxisAngle(&perpendicular,savedRotation);
                        oriented.FUN_00c66320(&sideways,(Quaternion*)&angle);
                        transform.FUN_00cb2d90(&oriented);
                        updateTranslation(body);
                        FUN_00cfdbe0((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                        oriented.FUN_00c74b70(&sideways,(Quaternion*)&angle);
                        transform.FUN_00cb2d90(&oriented);
                        updateTranslation(body);
                        FUN_00cfdbe0((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                        input->tolerance=savedTolerance;
                        input->step->endTime=savedStart;
                        input->step->deltaTime=savedEnd;
                        body->motion.restore((const hkTransform*)&savedTransform);
                        FUN_00cfdbe0((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                    }
                }
                if(DAT_01269200==1) { releaseAll(pairs,visited); return; }
            }
        }
    }
    releaseAll(pairs,visited);
}

namespace fnv_00cfa5f0 {
#include <string.h>

struct __declspec(align(16)) FNVState_CFA5F0 {
    int data00;
    int data04;
    int data08;
    int data0c;
    int data10;
    int data14;
    int data18;
    int data1c;
    int data20;
    int data24;
    int data28;
    int data2c;
    int data30;
    int data34;
    int data38;
    int data3c;
    int data40;
    int data44;
    int data48;
    int data4c;
    int input50;
    int input54;
    int input58;
    int input5c;
    int reserved60;
    int result64;
    float contactNormalX;
    float contactNormalY;
    float contactNormalZ;
    float contactDistance;
    void __thiscall FUN_00cfa7d0(const int* source);
};
struct FNVSIM_CFA5F0 {
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
    int* stateSource78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int hasPending8c;
    int hasPending90;
    int activeCount94;
    int unk98;
    unsigned char flag9c;
    int unka0;
    int statusa4;
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};
struct FNVAudio_CFA5F0 {
    virtual void v0();
    virtual void v1();
    virtual void v2(int id, int flags);
};
struct FNVAudioHolder_CFA5F0 {
    int unk00, unk04, unk08, unk0c;
    FNVAudio_CFA5F0* audio10;
};
extern "C" void __cdecl FUN_00cf9c60(int arg1,int arg2,FNVSIM_CFA5F0* simulation);
FNVAudioHolder_CFA5F0* __cdecl FUN_00c85750();
}  // namespace fnv_00cfa5f0
