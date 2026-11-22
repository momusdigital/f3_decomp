#include <windows.h>
#include <math.h>
// src/f3staging/f3blk_00980000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00981e50 (community match, verified in this file)
namespace f3m_00981e50 {
extern unsigned long DAT_0126835c;
namespace f3m_00981e50 {

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) : m_bool(static_cast<char>(b)) {}
    __forceinline operator bool() const { return m_bool != 0; }
    __forceinline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
private:
    char m_bool;
};

template <typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(T v) : m_storage(v) {}
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
        return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    }

    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
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

    static __forceinline void timerCommand(const char* name)
    {
        hkMonitorStream& mStream = getInstance();
        if (mStream.getEnd() < mStream.getCapacityMinus16())
        {
            TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = name;
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
};

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;

    __forceinline void setMul4(float r, const hkVector4& a)
    {
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
};

struct __declspec(align(16)) hkStepInfo
{
    __forceinline hkStepInfo() {}
    __forceinline hkStepInfo(float startTime, float endTime)
    {
        m_startTime = startTime;
        m_endTime = endTime;
        m_deltaTime = endTime - startTime;
        m_invDeltaTime = (m_deltaTime == 0.0f) ? 0.0f : 1.0f / m_deltaTime;
    }

    hkPadSpu<float> m_startTime;
    hkPadSpu<float> m_endTime;
    hkPadSpu<float> m_deltaTime;
    hkPadSpu<float> m_invDeltaTime;
};

struct hkpSimulationIsland;
struct hkpWorld;

struct __declspec(align(16)) hkpSolverInfo
{
    int unk00, unk04, unk08, unk0c;
    hkVector4 m_globalAccelerationPerSubStep;
    hkVector4 m_globalAccelerationPerStep;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108;
    float m_deltaTime;
    float m_invDeltaTime;
    int m_numSteps;
    int m_numMicroSteps;
    float m_invNumMicroSteps;
    float m_invNumSteps;
    hkBool m_forceCoherentConstraintOrderingInSolver;
    unsigned char m_deactivationNumInactiveFramesSelectFlag[2];
    unsigned char m_deactivationIntegrateCounter;
    int unk128, unk12c;

    __forceinline void incrementDeactivationFlags()
    {
        m_deactivationIntegrateCounter++;
        unsigned char c = m_deactivationIntegrateCounter;
        if (((c - 4) & 7) == 0)
        {
            m_deactivationNumInactiveFramesSelectFlag[0] ^= 1;
        }
        if ((c & 7) == 0)
        {
            m_deactivationNumInactiveFramesSelectFlag[0] ^= 2;
        }
        if ((c & 15) == 0)
        {
            m_deactivationIntegrateCounter = 0;
            m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
        }
    }
};

struct __declspec(align(16)) hkpWorldDynamicsStepInfo
{
    hkStepInfo m_stepInfo;
    hkpSolverInfo m_solverInfo;
};

struct __declspec(align(16)) hkpProcessCollisionInput
{
    int unk00;
    float m_tolerance;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c;
    hkStepInfo m_stepInfo;
};

struct hkpWeldingSinCosTableEntry
{
    float m_cosAccept0;
    float m_sinAccept0;
    float m_cosSnap0;
    float m_cosSnap1;
};

struct hkpMultiThreadedSimulation;

struct hkpMtThreadStructure
{
    hkpProcessCollisionInput* m_collisionInput;
    hkpWorldDynamicsStepInfo* m_dynamicsStepInfo;
    hkpMultiThreadedSimulation* m_simulation;
    float m_tolerance;
    const hkpWeldingSinCosTableEntry* m_weldingTable;
};

struct hkpWorldMaintenanceMgr
{
    virtual ~hkpWorldMaintenanceMgr();
    virtual void init(hkpWorld* world);
    virtual void resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo);
    virtual void performMaintenance(hkpWorld* world, hkStepInfo& stepInfo);
    virtual void performMaintenanceNoSplit(hkpWorld* world, hkStepInfo& stepInfo);
    virtual void performMaintenanceVf14(hkpWorld* world, hkStepInfo& stepInfo);
};

struct __declspec(align(16)) hkpWorld
{
    int unk00, unk04, unk08, unk0c;
    hkVector4 m_gravity;
    int unk20, unk24;
    hkpSimulationIsland** m_activeSimulationIslands;
    int m_numActiveSimulationIslands;
    int m_activeSimulationIslandsCapacity;
    hkpSimulationIsland** m_inactiveSimulationIslands;
    int m_numInactiveSimulationIslands;
    int unk3c, unk40, unk44, unk48;
    hkpWorldMaintenanceMgr* m_maintenanceMgr;
    int unk50, unk54, unk58, unk5c, unk60, unk64;
    hkpMtThreadStructure* m_multithreadedSimulationJobData;
    hkpProcessCollisionInput* m_collisionInput;
    int unk70, unk74, unk78, unk7c, unk80;
    int m_criticalOperationsLockCount;
    int m_criticalOperationsLockCountForPhantoms;
    int unk8c, unk90, unk94, unk98, unk9c;
    hkBool m_processActionsInSingleThread;
    char unka1;
    char unka2;
    char unka3;
    int unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    int unkc4, unkc8, unkcc;
    hkBool m_wantJobQueueFlag;
    char unkd1;
    char unkd2;
    char unkd3;
    int unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0;
    int unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110;
    int unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150;
    int unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170;
    int unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    hkpWorldDynamicsStepInfo m_dynamicsStepInfo;

    void hkpWorld_checkDeterminism();
};

struct __declspec(align(16)) hkpIntegrateJob
{
    __forceinline hkpIntegrateJob(int numIslands)
    {
        m_jobType = 0;
        m_taskHeader = 0;
        m_island = 0;
        m_islandIndex = 0;
        m_numIslands = numIslands;
    }

    unsigned short m_jobType;
    unsigned short m_islandIndex;
    void* m_taskHeader;
    hkpSimulationIsland* m_island;
    int m_unk0c;
    int m_numIslands;
};

struct hkJobQueue
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;

    void FUN_00a21500(int numJobs);
    void hkJobQueue_addJob(const hkpIntegrateJob& job, int priority, int affinity);  // addJob
};

struct hkJobQueueFlags
{
    int unk00, unk04, unk08, unk0c;
    hkBool m_flag10;
};

struct hkpMultiThreadedSimulation
{
    void* m_vfptr;
    short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_determinismCheckFrameCounter;
    hkpWorld* m_world;
    unsigned char m_lastProcessingStep;
    char unk11;
    char unk12;
    char unk13;
    float m_currentTime;
    float m_currentPsiTime;
    float m_physicsDeltaTime;
    float m_simulateUntilTime;
    float m_frameMarkerPsiSnap;
    unsigned int m_previousStepResult;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    hkBool m_stepInitialized;
    char unk69;
    char unk6a;
    char unk6b;
    int unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    int unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8;
    int unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8;
    int unkec, unkf0;
    int m_numActiveIslandsAtPartitioning;
    int m_numInactiveIslandsAtPartitioning;
    int unkfc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118;
    int unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138;
    int unk13c;
    hkJobQueue m_jobQueue;
    hkJobQueueFlags* m_jobQueueFlags;

    void FUN_0097f4f0();                        // processActions
    void FUN_00981e50(float physicsDeltaTime);  // stepBeginSt
};

void FUN_00927c80(hkpWorld* world);   // cleanupDirtyIslands
void FUN_00a0b770();

extern hkpWeldingSinCosTableEntry DAT_0116bf50[];
extern const char DAT_00e7d300[];   // "TtSimulate"

}
using namespace f3m_00981e50;

// hkpMultiThreadedSimulation::stepBeginSt
void hkpMultiThreadedSimulation::FUN_00981e50(float physicsDeltaTime)
{
    hkMonitorStream::timerCommand(DAT_00e7d300);

    m_stepInitialized = true;
    m_world->m_criticalOperationsLockCount++;
    m_physicsDeltaTime = physicsDeltaTime;

    hkStepInfo physicsStepInfo(m_currentPsiTime, m_currentPsiTime + m_physicsDeltaTime);
    m_world->m_dynamicsStepInfo.m_stepInfo = physicsStepInfo;
    m_world->m_collisionInput->m_stepInfo = physicsStepInfo;

    m_world->m_maintenanceMgr->performMaintenanceVf14(m_world, physicsStepInfo);
    FUN_00927c80(m_world);
    m_world->hkpWorld_checkDeterminism();
    FUN_00a0b770();

    {
        m_world->m_dynamicsStepInfo.m_stepInfo = physicsStepInfo;
        const hkStepInfo& stepInfoIn = physicsStepInfo;
        hkpSolverInfo& solverInfo = m_world->m_dynamicsStepInfo.m_solverInfo;
        solverInfo.m_deltaTime = stepInfoIn.m_deltaTime * solverInfo.m_invNumSteps;
        solverInfo.m_invDeltaTime = stepInfoIn.m_invDeltaTime * solverInfo.m_numSteps;
        solverInfo.m_globalAccelerationPerSubStep.setMul4(solverInfo.m_deltaTime, m_world->m_gravity);
        solverInfo.m_globalAccelerationPerStep.setMul4(stepInfoIn.m_deltaTime, m_world->m_gravity);
    }

    {
        hkpMtThreadStructure* tl = m_world->m_multithreadedSimulationJobData;
        tl->m_dynamicsStepInfo = &m_world->m_dynamicsStepInfo;
        tl->m_collisionInput = m_world->m_collisionInput;
        tl->m_simulation = this;
        tl->m_tolerance = m_world->m_collisionInput->m_tolerance;
        tl->m_weldingTable = DAT_0116bf50;
    }

    if (m_world->m_wantJobQueueFlag)
    {
        m_jobQueueFlags->m_flag10 = true;
    }

    int numActiveIslands = m_world->m_numActiveSimulationIslands;
    if (numActiveIslands > 0)
    {
        if (m_world->m_processActionsInSingleThread)
        {
            m_world->m_criticalOperationsLockCountForPhantoms--;
            FUN_0097f4f0();
            m_world->m_criticalOperationsLockCountForPhantoms++;
        }
        hkpIntegrateJob job(numActiveIslands);
        m_jobQueue.FUN_00a21500(numActiveIslands);
        m_jobQueue.hkJobQueue_addJob(job, 1, 0);
    }

    m_world->m_dynamicsStepInfo.m_solverInfo.incrementDeactivationFlags();
    m_numActiveIslandsAtPartitioning = m_world->m_numActiveSimulationIslands;
    m_numInactiveIslandsAtPartitioning = m_world->m_numInactiveSimulationIslands;
    m_world->hkpWorld_checkDeterminism();

    hkMonitorStream::timerCommand("Et");
}
}   // namespace f3m_00981e50

// @f3 0x009826e0 (community match, verified in this file)
extern unsigned long DAT_0126835c;
namespace f3m_009826e0 {
namespace f3m_009826e0 {
struct CRITICAL_SECTION {
    void* debugInfo;
    long lockCount;
    long recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long spinCount;
};
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }
    __forceinline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
private:
    char m_bool;
};

template <typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(T v) : m_storage(v) {}
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return m_storage; }
    __forceinline void operator=(T v) { m_storage = v; }
private:
    T m_storage;
};

template <typename T>
class hkArray
{
public:
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { m_size = 0; }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    }

    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
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

    struct TimerBeginListCommand : public TimerCommand
    {
        const char* m_nameOfFirstSplit;
    };

    static __forceinline void timerCommand(const char* name)
    {
        hkMonitorStream& mStream = getInstance();
        if (mStream.getEnd() < mStream.getCapacityMinus16())
        {
            TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = name;
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    static __forceinline void timerBeginList(const char* name, const char* firstSplit)
    {
        hkMonitorStream& mStream = getInstance();
        if (mStream.getEnd() < mStream.getCapacityMinus16())
        {
            TimerBeginListCommand* h = reinterpret_cast<TimerBeginListCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = name;
            h->m_nameOfFirstSplit = firstSplit;
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
};

struct __declspec(align(16)) hkStepInfo
{
    __forceinline hkStepInfo() {}
    __forceinline hkStepInfo(float startTime, float endTime)
    {
        m_startTime = startTime;
        m_endTime = endTime;
        m_deltaTime = endTime - startTime;
        m_invDeltaTime = (m_deltaTime == 0.0f) ? 0.0f : 1.0f / m_deltaTime;
    }

    hkPadSpu<float> m_startTime;
    hkPadSpu<float> m_endTime;
    hkPadSpu<float> m_deltaTime;
    hkPadSpu<float> m_invDeltaTime;
};

class hkCriticalSection
{
public:
    void FUN_00908a00();   // enter()

    __forceinline void leave()
    {
        m_currentThread = -1;
        m_recursionThread = -1;
        LeaveCriticalSection(&m_section);
    }

    CRITICAL_SECTION m_section;
    int m_currentThread;
    int m_recursionThread;
};

struct hkpTypedBroadPhaseHandle
{
    int m_id;
    char m_type;
    signed char m_ownerOffset;
    unsigned short m_objectQualityType;
    unsigned int m_collisionFilterInfo;

    __forceinline void* getOwner() const { return (char*)this + m_ownerOffset; }
};

struct hkpBroadPhaseHandlePair
{
    hkpTypedBroadPhaseHandle* m_a;
    hkpTypedBroadPhaseHandle* m_b;
};

struct hkpCollidable
{
    int unk00, unk04, unk08, unk0c;
    signed char m_ownerOffset;
    char unk11;
    char unk12;
    char unk13;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle;

    __forceinline void* getOwner() const { return (char*)this + m_ownerOffset; }
    __forceinline int getQualityType() const { return m_broadPhaseHandle.m_objectQualityType; }
};

class hkpSimulationIsland;
struct hkpSimulationIsland
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short m_storageIndex;
    char unk22;
    char unk23;
};

struct hkpEntity
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    hkpSimulationIsland* m_simulationIsland;
};

struct hkpCollisionQualityInfo
{
    int unk00, unk04, unk08, unk0c;
    int m_useContinuousPhysics;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};

struct hkpCollisionDispatcher
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c, unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c, unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c, unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c, unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c, unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc, unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c, unk720, unk724, unk728, unk72c, unk730, unk734, unk738, unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c, unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c, unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc, unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c, unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c, unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c, unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc, unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c, unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c, unk960, unk964, unk968, unk96c, unk970, unk974, unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c, unk9a0, unk9a4, unk9a8, unk9ac, unk9b0, unk9b4, unk9b8, unk9bc;
    int unk9c0, unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc, unk9e0, unk9e4, unk9e8, unk9ec, unk9f0, unk9f4, unk9f8, unk9fc;
    int unka00, unka04, unka08, unka0c, unka10, unka14, unka18, unka1c, unka20, unka24, unka28, unka2c, unka30, unka34, unka38, unka3c;
    int unka40, unka44, unka48, unka4c, unka50, unka54, unka58, unka5c, unka60, unka64, unka68, unka6c, unka70, unka74, unka78, unka7c;
    int unka80, unka84, unka88, unka8c, unka90, unka94, unka98, unka9c, unkaa0, unkaa4, unkaa8, unkaac, unkab0, unkab4, unkab8, unkabc;
    int unkac0, unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc, unkae0, unkae4, unkae8, unkaec, unkaf0, unkaf4, unkaf8, unkafc;
    int unkb00, unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c, unkb20, unkb24, unkb28, unkb2c, unkb30, unkb34, unkb38, unkb3c;
    int unkb40, unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c, unkb60, unkb64, unkb68, unkb6c, unkb70, unkb74, unkb78, unkb7c;
    int unkb80, unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c, unkba0, unkba4, unkba8, unkbac, unkbb0, unkbb4, unkbb8, unkbbc;
    int unkbc0, unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc, unkbe0, unkbe4, unkbe8, unkbec, unkbf0, unkbf4, unkbf8, unkbfc;
    int unkc00, unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c, unkc20, unkc24, unkc28, unkc2c, unkc30, unkc34, unkc38, unkc3c;
    int unkc40, unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c, unkc60, unkc64, unkc68, unkc6c, unkc70, unkc74, unkc78, unkc7c;
    int unkc80, unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c, unkca0, unkca4, unkca8, unkcac, unkcb0, unkcb4, unkcb8, unkcbc;
    int unkcc0, unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc, unkce0, unkce4, unkce8, unkcec, unkcf0, unkcf4, unkcf8, unkcfc;
    int unkd00, unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c, unkd20, unkd24, unkd28, unkd2c, unkd30, unkd34, unkd38, unkd3c;
    int unkd40, unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c, unkd60, unkd64, unkd68, unkd6c, unkd70, unkd74, unkd78, unkd7c;
    int unkd80, unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c, unkda0, unkda4, unkda8, unkdac, unkdb0, unkdb4, unkdb8, unkdbc;
    int unkdc0, unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc, unkde0, unkde4, unkde8, unkdec, unkdf0, unkdf4, unkdf8, unkdfc;
    int unke00, unke04, unke08, unke0c, unke10, unke14, unke18, unke1c, unke20, unke24, unke28, unke2c, unke30, unke34, unke38, unke3c;
    int unke40, unke44, unke48, unke4c, unke50, unke54, unke58, unke5c, unke60, unke64, unke68, unke6c, unke70, unke74, unke78, unke7c;
    int unke80, unke84, unke88, unke8c, unke90, unke94, unke98, unke9c, unkea0, unkea4, unkea8, unkeac, unkeb0, unkeb4, unkeb8, unkebc;
    int unkec0, unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc, unkee0, unkee4, unkee8, unkeec, unkef0, unkef4, unkef8, unkefc;
    int unkf00, unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c, unkf20, unkf24, unkf28, unkf2c, unkf30, unkf34, unkf38, unkf3c;
    int unkf40, unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c, unkf60, unkf64, unkf68, unkf6c, unkf70, unkf74, unkf78, unkf7c;
    int unkf80, unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c, unkfa0, unkfa4, unkfa8, unkfac, unkfb0, unkfb4, unkfb8, unkfbc;
    int unkfc0, unkfc4, unkfc8, unkfcc, unkfd0, unkfd4, unkfd8, unkfdc, unkfe0, unkfe4, unkfe8, unkfec, unkff0, unkff4, unkff8, unkffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c, unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c, unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc, unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c, unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c, unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c, unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc, unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c, unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c, unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0, unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c, unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760, unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc, unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820, unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860, unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c, unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0, unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920, unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c, unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0, unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c, unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc, unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c, unk1ba0, unk1ba4, unk1ba8, unk1bac;
    signed char m_collisionQualityTable[10][10];
    int unk1c14, unk1c18, unk1c1c;
    hkpCollisionQualityInfo m_collisionQualityInfo[8];

    __forceinline signed char getCollisionQualityIndex(int a, int b) const { return m_collisionQualityTable[a][b]; }
    __forceinline hkpCollisionQualityInfo* getCollisionQualityInfo(int index) { return &m_collisionQualityInfo[index]; }
};

struct hkpProcessCollisionInput
{
    hkpCollisionDispatcher* m_dispatcher;
    int unk04, unk08, unk0c;
    int m_createPredictiveAgents;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    int unk54, unk58, unk5c;
    hkpCollisionQualityInfo* m_collisionQualityInfo;
};

struct hkpProcessCdPoint
{
    float m_contact[8];
    int unk20, unk24, unk28, unk2c;
};

struct __declspec(align(16)) hkpToiInfo
{
    float m_contact[8];
    float m_time;
    float m_seperatingVelocity;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    float m_impulseApplied;
    float m_internalSolverData;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    __forceinline hkpToiInfo() : m_time(3.40282e38), m_impulseApplied(0.0f), m_internalSolverData(0.0f) {}
};

struct __declspec(align(16)) hkpProcessCollisionOutput
{
    hkpProcessCdPoint* m_firstFreeContactPoint;
    hkpSimulationIsland* m_constraintOwner;
    int unk08, unk0c;
    hkpProcessCdPoint m_contactPoints[256];
    hkpToiInfo m_toi;
    void* m_potentialContacts;
    __forceinline hkpProcessCollisionOutput(hkpSimulationIsland* owner) : m_constraintOwner(owner) {}
    __forceinline void reset()
    {
        m_firstFreeContactPoint = &m_contactPoints[0];
        m_toi.m_time = 3.40282e38;
        m_potentialContacts = 0;
    }
    __forceinline bool hasContacts() { return m_firstFreeContactPoint != &m_contactPoints[0]; }
};

class hkpContactMgr
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void processContact(const hkpCollidable& a, const hkpCollidable& b,
        const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output);
};

struct hkpAgentNnEntry
{
    int unk00, unk04;
    hkpContactMgr* m_contactMgr;
    signed char m_collisionQualityIndex;
    char unk0d, unk0e, unk0f;
    hkpCollidable* m_collidable[2];
};

struct hkpWorld
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68;
    hkpProcessCollisionInput* m_collisionInput;
    int unk70, unk74, unk78, unk7c;
    int m_pendingOperationsCount;
    int m_criticalOperationsLockCount;
    int m_criticalOperationsLockCountForPhantoms;
    hkBool m_blockExecutingPendingOperations;
    char unk8d;
    char unk8e;
    char unk8f;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkBool m_wantJobQueueFlag;
    char unkd1;
    char unkd2;
    char unkd3;
    int unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100;
    int unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    hkArray<void*> m_worldPostCollideListeners;

    void hkpWorld_checkDeterminism();
    void FUN_00902550();   // internal_executePendingOperations

    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        m_criticalOperationsLockCount--;
        if (m_criticalOperationsLockCount == 0 && !m_blockExecutingPendingOperations)
        {
            if (m_pendingOperationsCount)
            {
                FUN_00902550();
            }
        }
    }
};

struct hkJobQueueFlags
{
    int unk00, unk04, unk08, unk0c;
    hkBool m_flag10;
};

struct hkJobQueue
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;

    void FUN_00a214a0(int a);
    void FUN_00a21410(hkJobQueueFlags* flags);
    void FUN_00a213f0(int a);
};

class hkpMultiThreadedSimulation
{
public:
    short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_determinismCheckFrameCounter;
    hkpWorld* m_world;
    unsigned char m_lastProcessingStep;
    char unk11;
    char unk12;
    char unk13;
    float m_currentTime;
    float m_currentPsiTime;
    float m_physicsDeltaTime;
    float m_simulateUntilTime;
    float m_frameMarkerPsiSnap;
    unsigned int m_previousStepResult;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    int unk5c, unk60, unk64;
    hkBool m_stepInitialized;
    char unk69;
    char unk6a;
    char unk6b;
    hkArray<hkpBroadPhaseHandlePair> m_addedCrossIslandPairs;
    int unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4;
    hkArray<hkpBroadPhaseHandlePair> m_removedCrossIslandPairs;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0;
    int unke4, unke8, unkec, unkf0;
    int m_numActiveIslandsAtPartitioning;
    int m_numInactiveIslandsAtPartitioning;
    int unkfc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128;
    int unk12c, unk130, unk134, unk138, unk13c;
    hkJobQueue m_jobQueue;
    hkJobQueueFlags* m_jobQueueFlags;
    int unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0;
    int unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0;
    int unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200;
    int unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230;
    int unk234, unk238, unk23c, unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260;
    int unk264, unk268, unk26c, unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290;
    int unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc, unk2c0;
    int unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0;
    int unk2f4, unk2f8, unk2fc, unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320;
    int unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    hkCriticalSection m_toiQueueCriticalSection;

    virtual ~hkpMultiThreadedSimulation();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();

    void FUN_0098c830(const hkpProcessCollisionOutput& output, const hkpAgentNnEntry& entry);   // addToiEvent
    void hkpMultiThreadedSimulation_finishMtStep();   // stepEndSt
};

hkBool FUN_00981ac0(const hkpSimulationIsland* a, const hkpSimulationIsland* b);   // island ordering
void FUN_00990430(hkpSimulationIsland** pArr, int d, int h, hkBool (*cmpLess)(const hkpSimulationIsland*, const hkpSimulationIsland*));   // hkAlgorithm::quickSortRecursive
void FUN_00984d00(hkArray<hkpBroadPhaseHandlePair>* added, hkArray<hkpBroadPhaseHandlePair>* removed);   // removeDuplicatesFromLists
void sortPairList(hkArray<hkpBroadPhaseHandlePair>* pairs);   // sortPairList
hkpSimulationIsland* hkpWorldOperationUtil_internalMergeTwoIslands(hkpWorld* world, hkpSimulationIsland* a, hkpSimulationIsland* b);   // internalMergeTwoIslands
hkpAgentNnEntry* hkpWorldAgentUtil_addAgent(hkpCollidable* a, hkpCollidable* b, hkpProcessCollisionInput* input);   // addAgent
void FUN_00999610(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkpContactMgr* mgr);   // hkAgentNnMachine_ProcessAgent
hkpAgentNnEntry* FUN_00998710(const hkpCollidable* a, const hkpCollidable* b);   // hkAgentNnMachine_FindAgent
void FUN_009447d0(hkpAgentNnEntry* entry);   // removeAgent
void hkpWorldCallbackUtil_firePostCollideCallback(hkpWorld* world, const hkStepInfo& stepInfo);   // firePostCollideCallback

namespace hkAlgorithm
{
    template <typename T, typename L>
    __forceinline void quickSort(T* pArr, int numElem, L cmpLess)
    {
        FUN_00990430(pArr, 0, numElem - 1, cmpLess);
    }
}

extern const char DAT_00e7d300[];   // "TtSimulate"
extern const char DAT_00e7d4ac[];   // "LtInterIsland"
extern const char DAT_00e7d49c[];   // "Stduplicates"
extern const char DAT_00e7d490[];   // "StsortPairs"
extern const char DAT_00e7d484[];   // "StaddAgt"
extern const char DAT_00e7d478[];   // "StremoveAgt"
extern const char DAT_00e0811c[];   // "lt"
extern const char DAT_00e7d2c8[];   // "TtPostCollideCB"

}
using namespace f3m_009826e0;

// hkpMultiThreadedSimulation::stepEndSt
// pdb: hkpMultiThreadedSimulation::finishMtStep | hkpMultithreadedSimulation.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkpMultiThreadedSimulation::hkpMultiThreadedSimulation_finishMtStep()
{
    hkMonitorStream::timerCommand(DAT_00e7d300);

    {
        int numNewIslands = m_world->m_activeSimulationIslands.getSize() - m_numActiveIslandsAtPartitioning;
        if (numNewIslands > 1)
        {
            hkAlgorithm::quickSort(&m_world->m_activeSimulationIslands[m_numActiveIslandsAtPartitioning], numNewIslands, FUN_00981ac0);
        }
        for (int i = m_numActiveIslandsAtPartitioning; i < m_world->m_activeSimulationIslands.getSize(); i++)
        {
            m_world->m_activeSimulationIslands[i]->m_storageIndex = (unsigned short)i;
        }
    }
    m_world->hkpWorld_checkDeterminism();

    if (m_removedCrossIslandPairs.getSize() + m_addedCrossIslandPairs.getSize())
    {
        hkMonitorStream::timerBeginList(DAT_00e7d4ac, DAT_00e7d49c);
        FUN_00984d00(&m_addedCrossIslandPairs, &m_removedCrossIslandPairs);

        hkMonitorStream::timerCommand(DAT_00e7d490);
        sortPairList(&m_addedCrossIslandPairs);
        sortPairList(&m_removedCrossIslandPairs);

        hkMonitorStream::timerCommand(DAT_00e7d484);
        {
            hkpProcessCollisionOutput processOutput(0);
            for (int i = 0; i < m_addedCrossIslandPairs.getSize(); i++)
            {
                hkpCollidable* collA = static_cast<hkpCollidable*>(m_addedCrossIslandPairs[i].m_a->getOwner());
                hkpCollidable* collB = static_cast<hkpCollidable*>(m_addedCrossIslandPairs[i].m_b->getOwner());
                hkpSimulationIsland* islandA = static_cast<hkpEntity*>(collA->getOwner())->m_simulationIsland;
                hkpSimulationIsland* islandB = static_cast<hkpEntity*>(collB->getOwner())->m_simulationIsland;
                hkpSimulationIsland* island = islandA;
                if (islandA != islandB)
                {
                    island = hkpWorldOperationUtil_internalMergeTwoIslands(m_world, islandA, islandB);
                }
                processOutput.m_constraintOwner = island;

                hkpProcessCollisionInput* input = m_world->m_collisionInput;
                hkpCollisionDispatcher* dispatcher = input->m_dispatcher;
                signed char qualityIndex = dispatcher->getCollisionQualityIndex(collA->getQualityType(), collB->getQualityType());
                if (qualityIndex == 0)
                {
                    continue;
                }
                input->m_createPredictiveAgents = dispatcher->getCollisionQualityInfo(qualityIndex)->m_useContinuousPhysics;

                hkpAgentNnEntry* entry = hkpWorldAgentUtil_addAgent(collA, collB, input);
                if (entry == 0)
                {
                    continue;
                }

                input = m_world->m_collisionInput;
                hkpCollidable* entryCollA = entry->m_collidable[0];
                hkpCollidable* entryCollB = entry->m_collidable[1];
                input->m_collisionQualityInfo = input->m_dispatcher->getCollisionQualityInfo(entry->m_collisionQualityIndex);
                input->m_createPredictiveAgents = input->m_collisionQualityInfo->m_useContinuousPhysics;
                processOutput.reset();

                FUN_00999610(entry, *input, processOutput, entry->m_contactMgr);
                if (processOutput.hasContacts())
                {
                    entry->m_contactMgr->processContact(*entryCollA, *entryCollB, *input, processOutput);
                }
                if (processOutput.m_toi.m_time != (double)3.40282e38f)
                {
                    m_toiQueueCriticalSection.FUN_00908a00();
                    FUN_0098c830(processOutput, *entry);
                    m_toiQueueCriticalSection.leave();
                }
            }
        }
        m_addedCrossIslandPairs.clear();

        hkMonitorStream::timerCommand(DAT_00e7d478);
        for (int i = 0; i < m_removedCrossIslandPairs.getSize(); i++)
        {
            hkpCollidable* collA = static_cast<hkpCollidable*>(m_removedCrossIslandPairs[i].m_a->getOwner());
            hkpCollidable* collB = static_cast<hkpCollidable*>(m_removedCrossIslandPairs[i].m_b->getOwner());
            hkpAgentNnEntry* entry = FUN_00998710(collA, collB);
            if (entry)
            {
                FUN_009447d0(entry);
            }
        }
        m_removedCrossIslandPairs.clear();
        hkMonitorStream::timerCommand(DAT_00e0811c);
    }

    m_stepInitialized = false;
    m_world->unlockAndAttemptToExecutePendingOperations();
    m_currentPsiTime += m_physicsDeltaTime;

    if (m_world->m_worldPostCollideListeners.getSize())
    {
        hkMonitorStream::timerCommand(DAT_00e7d2c8);
        hkStepInfo stepInfo(m_currentPsiTime - m_physicsDeltaTime, m_currentPsiTime);
        hkpWorldCallbackUtil_firePostCollideCallback(m_world, stepInfo);
        hkMonitorStream::timerCommand("Et");
    }

    m_world->hkpWorld_checkDeterminism();
    hkMonitorStream::timerCommand("Et");

    vf18();

    if (m_world->m_wantJobQueueFlag && m_jobQueueFlags->m_flag10)
    {
        m_jobQueue.FUN_00a214a0(0);
        m_jobQueueFlags->m_flag10 = false;
        m_jobQueue.FUN_00a21410(m_jobQueueFlags);
        m_jobQueue.FUN_00a213f0(0);
    }
}

}   // namespace f3m_009826e0
