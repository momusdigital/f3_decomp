// fallout/ai/ailineartaskthreadmanager.cpp: AIThreadManager (1 function)
#include "f3_common.h"
#include <new>
#include "ailineartaskthreadmanager_rendering.h"

typedef void(__cdecl* AIThreadFunction)();

class BSThread
{
  public:
    enum StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };
    void Initialize(StackSize, const char*, bool);
    void SetSchedulingPriority(unsigned int);
    void SetThreadPriority(int);
    void SetName(const char*);
};

class AILinearTaskThread : public BSThread
{
  public:
    AILinearTaskThread(AIThreadFunction);
    unsigned char layoutPadding[0x78];
};

class AIThreadManager
{
  public:
    enum AI_THREAD_INDEX
    {
        AI_THREAD_1 = 0,
        AI_THREAD_2 = 1,
        AI_THREAD_COUNT = 2
    };
    AILinearTaskThread* m_pTaskThreads[3];
    unsigned char layoutPadding0[0x30];
    void* threadHandles1[12];
    void* threadHandles2[8];
    void LaunchWorkerThread(AI_THREAD_INDEX, unsigned int, AIThreadFunction, const char*, BSThread::StackSize);
    void MTRenderingSystem_CreateThreads();
    static void SetThreadingEnabled(bool);
};

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);

class CountingSemaphore
{
  public:
    void Wait();
};

struct ActiveEffect;
struct Actor;
struct PackedTaskQueueProcessor;
struct Character;
struct DismemberLimbTaskData;
struct BooleanFloatQuery;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct TESBoundObject;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TaskQueueInterface
{
    void ThreadProcessInput();
    void ThreadBeginSecondaryInput();
    void ThreadProcessSecondaryInput();
    void ThreadEndSecondaryInput();
    void ProcessQueue();
    void ProcessTaskQueue();
    unsigned long QProcessingThread();
    void ExamplePrintFloat(float);
    void ExamplePrintInt(int);
    void QueueSkyEmittanceUpdate(NiNode*, NiColor*);
    void ProcessPackedTask(unsigned int, TESObjectREFR*, ...);
    void QueueWeaponFire(TESObjectWEAP*, TESObjectREFR*);
    void QueueParallelTaskProcessing();
    void QueueCellTransformChildTask(NiNode*);
    void QueueActorHavokSync(NiNode*);
    void QueueActorNodeUpdate(Actor*, NiAVObject*);
    void QueueParticlesUpdate(NiNode*);
    void QueueMorphControllerUpdate(NiNode*);
    void QueueNodeAttach(NiAVObject*, NiNode*, bool, bool);
    void QueueNodeDetach(NiAVObject*);
    void QueueBiped3DDetach(NiAVObject*);
    void QueueSSNRemoveObject(NiAVObject*, int);
    void QueueObjectUpdate(NiAVObject*);
    void QueueActorHitMe(Actor*, BooleanFloatQuery*);
    void QueueActorCreateBlood(Actor*, BooleanFloatQuery*);
    void QueueMobileObjectInitialize(MobileObject*);
    void QueueMHEInstantiateHitEffects(ActiveEffect*);
    void QueueReferenceFloatTask(TESObjectREFR*, float, bool);
    void QueuePickedUpObjectRemoval(TESObjectREFR*, bool);
    void QueueActorDismemberLimb(Actor*, float*, DismemberLimbTaskData*);
    void QueueActorCombatTask(Actor*, bool, bool);
    void QueueActorKnockExplosion(Actor*, float, float, float, float);
    void QueueHavokInit(TESObjectREFR*);
    void QueueHavokAdd(NiAVObject*);
    void QueueHavokDelete(NiAVObject*);
    void QueueHavokMotionChange(NiAVObject*, int);
    void QueueHavokMove(TESObjectREFR*);
    void QueueHavokDetach(TESObjectREFR*);
    void QueueHavokAdjustForceAddCount(NiAVObject*, bool, bool, bool);
    void CopyStringToBuffer(Actor*, TESObjectWEAP*);
    void QueueRemoveWeapon(Actor*, TESBoundObject*);
    void QueueSet3DNull(TESObjectREFR*);
    void QueueDismemberLimb(Actor*, int, int, bool, bool);
    void QueueWaterObjectForAdd(TESObjectREFR*, TESObjectREFR*, float);
    void QueueWaterObjectForRemove(TESObjectREFR*, TESObjectREFR*, float);
    void QueueObstacleDoorOpen(TESObjectREFR*);
    void QueueObstacleDoorClose(TESObjectREFR*);
    void QueueCharacterReset3D(Character*);
    void QueueReferenceStateTask(TESObjectREFR*, bool, bool);
    void QueueActorDataTask(Actor*, void*);
    void QueueActorSetHavokWeapon(Actor*, bool);
    void QueueWaterSplashEffects(float, void*);
    void QueueAddRipple(float, void*);
    void QueueActorTriggerPain(Actor*, bool, bool);
    void QueueActorDisarm(Actor*);
    void QueueActorResetLoadedAnims(Actor*);
    void QueueActorAnimationTask(Actor*);
    void QueueDeleteActiveEffect(ActiveEffect*);
    static void Instantiate(PackedTaskQueueProcessor*, PackedTaskQueueProcessor*);
    static void Shutdown();
    static TaskQueueInterface* GetInstance();
    static void ProcessQueuedTask(void*);
    bool QQueueFurtherTasks();
    static bool QActive();
    static void SetActive(bool);
    PackedTaskQueueProcessor* GetActiveQueue();
    void SetActiveQueue(void*);
    void* __vecDelDtor(unsigned int);
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;
    unsigned long m_uiTaskFlags;
};
typedef char _sizecheck_TaskQueueInterface[sizeof(TaskQueueInterface) == 16 ? 1 : -1];

class BSAudio
{
  public:
    void* GetAudioBackendData();
};
void* __stdcall FUN_00713d80(int);
extern BSAudio* g_osGlobals;

__declspec(thread) int DAT_tls_0264;

struct FUN_0086c600_shell
{
    void SignalAtOffset();
};
struct FUN_0087a6b0_shell
{
    FUN_0086c600_shell* p;
    void FUN_0087a6b0();
};

struct FUN_0086cdd0_shell
{
    void FUN_0086cdd0();
};
struct FUN_0087a6d0_shell
{
    FUN_0086cdd0_shell* p;
    void FUN_0087a6d0();
};

namespace fnv_008c74b0 {
struct CountingSemaphore
{
    void Signal();
};

}  // namespace fnv_008c74b0

extern bool DAT_011dfa18;

namespace fnv_008c80b0 {
class CountingSemaphore
{
  public:
    void Wait();
};

extern CountingSemaphore g_011dfafc;

}  // namespace fnv_008c80b0

namespace fnv_008c80c0 {
struct CountingSemaphore
{
    void Signal();
};
extern CountingSemaphore g_011dfafc;

}  // namespace fnv_008c80c0

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
struct FUN_008c79e0_shell
{
    void* apThreads[3];
    int aiCurrent[2];
    char pad[0x78];
    void** ppEvents[2];
    void SignalThreadEvent(int aiIndex, int aiEvent);
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
struct FUN_008c7a70_shell
{
    char pad[0x8c];
    void** ppEvents[2];
    void WaitForEvent(int aiEvent);
};
// Waits indefinitely on the event at ppEvents[aiIndex][aiEvent].
// @f3 0x00406d70 (community match, verified in this file)
void __stdcall FUN_00406d70_probe(int a, int b);

struct FUN_00406d70_shell
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    FUN_00406d70_shell(int a0);
};

// pdb: ActiveEffect::FromWornEnchantment | ActiveEffect.obj | tesv_win, objrun_open, low
FUN_00406d70_shell::FUN_00406d70_shell(int a0)
{
    int z = 0;
    unk00 = z;
    unk04 = z;
    unk06 = z;
    FUN_00406d70_probe(a0, z);
}


struct FUN_008c7d80_shell
{
    void* m_pObjectPointers[3];
    int aiCurrent[2];
    char pad[0x74];
    void SetCurrent(int aiIndex, int aiValue);
};

struct CombatTargetMap
{
    void ResetTargetMap();
};
struct FUN_00991500_shell
{
    char pad[0x14];
    CombatTargetMap* m_pTargetMap;
    void FUN_00991500(bool abFlag);
};

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

namespace fnv_008c7bd0 {
struct BSAudio
{
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct Zt5TES
{
    void FUN_00453550(float);
};

struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
};

struct NavMeshObstacleManager
{
    static NavMeshObstacleManager* __cdecl GetSingleton();
    void Update();
};

struct BGSDestructibleObjectForm
{
    static void __cdecl UpdateDestructionMap();
};

struct FUN_008c79e0_shell
{
    void SignalThreadEvent(int);
};

struct FUN_008c7d80_shell
{
    void SetCurrent(int);
};

struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};

struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};

struct FUN_00991500_shell
{
    void FUN_00991500(bool);
};

struct FUN_0096cb50_shell
{
    void UpdateHighProcessActors();
};

struct FUN_009784c0_shell
{
    void FUN_009784c0();
};

struct FUN_00455640_shell
{
    void FUN_00455640();
};

struct SkyObject
{
    void Update(float, int);
};

struct ProcessLists
{
    void RunActorUpdates();
};

void* __stdcall FUN_00713d80(int);
void __fastcall FUN_0086fd70(void*);
float __cdecl FUN_00453850();
bool __cdecl FUN_005c42d0();
void __cdecl FUN_005ae270();
void __cdecl TESAmbushPackageData_Copy();
void __cdecl FUN_008c80d0();
void __cdecl ProcessPlayerCellActors();
void __fastcall FUN_00991dc0(void*);

extern BSAudio* g_osGlobals;
extern int g_TES;
extern GlobalObject_0045cf30 g_011d73e4;
extern int DAT_011e0e80;
extern void* BGSSaveLoadGlobalDataWorldspacePtr;

}  // namespace fnv_008c7bd0

namespace fnv_008c7f50 {

struct Zt5TES
{
    void FUN_00453550(float);
};

struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};

struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* __cdecl GetInstance();
};

struct FUN_008c79e0_shell
{
    void SignalThreadEvent(int);
};

struct FUN_008c7a70_shell
{
    void WaitForEvent(int);
};

struct SkyObject
{
    void Update(float, int);
};

struct BGSDestructibleObjectForm
{
    static void __cdecl UpdateDestructionMap();
};

struct FUN_0096cb50_shell
{
    void UpdateHighProcessActors();
};

void* __stdcall FUN_00713d80(int);
float __cdecl FUN_00453850(void);
void __cdecl FUN_005ae270(void);
void __cdecl TESAmbushPackageData_Copy(void);
extern int g_TES;
extern int DAT_011e0e80;

}  // namespace fnv_008c7f50

namespace fnv_008c7da0 {
struct FUN_00455640_shell
{
    void FUN_00455640();
};

struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};

struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};

struct FUN_008c79e0_shell
{
    void SignalThreadEvent(int, int);
};

struct FUN_008c7a70_shell
{
    void WaitForEvent(int, int);
};

struct FUN_009784c0_shell
{
    void FUN_009784c0();
};

struct FUN_00991500_shell
{
    void FUN_00991500(bool);
};

struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
};

struct ProcessLists
{
    void FUN_0096cca0();
    void FUN_0096cda0();
    void FUN_0096bcd0(float, int);
    static void ProcessPlayerCellActors();
    void RunActorUpdates();
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct NavMeshObstacleManager
{
    static NavMeshObstacleManager* __cdecl GetSingleton();
    void Update();
};

struct BSAudio
{
};

extern BSAudio* g_osGlobals;
extern FUN_00455640_shell* g_TES;
extern void* BGSSaveLoadGlobalDataWorldspacePtr;
extern int DAT_011e0e80;
extern GlobalObject_0045cf30 g_011d73e4;

void* __cdecl FUN_00713d80();
void __fastcall FUN_0086fd70(void*);
void __fastcall FUN_00991dc0(void*);
void __cdecl TESAmbushPackageData_Copy();
void __cdecl FUN_005ae270();
bool __cdecl FUN_005c42d0();
void __cdecl FUN_008c80d0();

}  // namespace fnv_008c7da0
