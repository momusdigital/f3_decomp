#include <stdio.h>
// src/bsshader/mtrenderingsystem_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/mtrenderingsystem.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "mtrenderingsystem_decls.h"
#pragma optimize("gty", on)
#pragma optimize("", off)
#pragma optimize("gty", on)
#pragma optimize("", off)

namespace fnv_00ba3690 {
#pragma optimize("gty", on)
extern "C" void _ReadWriteBarrier(void);

struct HandlerRegistration
{
    void* queuedHead;
    void* queuedTail;
    unsigned int queuedCount;
    HandlerRegistration();
    ~HandlerRegistration();
};

struct ThreadNode
{
    void* firstTask;
    void* lastTask;
    unsigned int taskCount;
    unsigned int nextTask;
    void* batch;
    void* renderer;
    unsigned int stage;
    unsigned int flags;
    ThreadNode();
    ~ThreadNode();
};

struct RenderingState
{
    int threadStages[3];
    int threadCounts[3];
    HandlerRegistration taskQueues[3];
    ThreadNode taskThreads[24];

    RenderingState();
};

// @fnv 0x00ba3690
// pdb: MTRenderingSystem::MTRenderingSystem | MTRenderingSystem.obj | fnv360_0822_debug, objopen_prop, medium
RenderingState::RenderingState()
{
    int i = 0;
    do
    {
        threadStages[i] = 0;
        threadCounts[i] = 0;
        _ReadWriteBarrier();
    } while (++i < 3);
}
}  // namespace fnv_00ba3690

namespace RenderStageWait {
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct WaitHandleCounter
{
    volatile long count;
    void* handle;
    unsigned int maximum;

    __forceinline void Acquire()
    {
        WaitForSingleObject(handle, ~0UL);
        InterlockedDecrement(&count);
    }
};

struct ThreadStages : ::TaskThreadManager
{
    void* renderWorker;
    void* visibilityWorker;
    void* linearWorker;
    volatile int completed[3];
    WaitHandleCounter signals[3];
};

// @fnv 0x00ba3130
// pdb: MTRenderingSystem::WaitOnThreadStage | MTRenderingSystem.obj | fnv360_0822_retail, call_seq, high
// pdb params: aiThreadIndex, aiStage
extern "C" void __fastcall FUN_00ba3130(ThreadStages* system, void*, int threadIndex, int stage)
{
    if (!::DAT_011f94b4)
        return;

    while (system->completed[threadIndex] < stage)
    {
        system->signals[threadIndex].Acquire();
        ++system->completed[threadIndex];
    }
}
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

struct MemoryManager
{
    void* Allocate(unsigned int size);
    void Free(void* p);
};
extern MemoryManager _g_memoryManager;

namespace AccumTaskDetail {

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;

    __forceinline NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
            {
                m_pObject->DecRefCount();
            }
            m_pObject = pObject;
            if (m_pObject)
            {
                m_pObject->IncRefCount();
            }
        }
        return *this;
    }
};

class Class0xa4
{
  public:
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

    Class0xa4();
    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }
    void operator delete(void* p)
    {
        _g_memoryManager.Free(p);
    }
};

class TaskArg1
{
  public:
    void CopyTo(Class0xa4* obj);
};

extern "C" const void* DAT_0101e2ec;

struct NiVisibleArray;
class FUN_00a69400
{
  public:
    const void* vtable;
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

    FUN_00a69400(NiVisibleArray* pArray = 0);
};

class BSCullingProcess : public FUN_00a69400
{
  public:
    unsigned int cullMode;
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
    void* field_bc;
    void* field_c0;
    void* field_c4;

    BSCullingProcess(NiVisibleArray* pkVisibleSet = 0) : FUN_00a69400(pkVisibleSet)
    {
        vtable = &DAT_0101e2ec;
        cullMode = 0;
        field_bc = 0;
        field_c0 = 0;
        field_c4 = 0;
    }

    void FUN_004a0f60();

    void SetAccumulator(NiRefObject* accumulator)
    {
        if (accumulator)
        {
            field_c4 = accumulator;
            accumulator->IncRefCount();
        }
    }

    void SetCullMode(unsigned int mode)
    {
        cullMode = mode;
    }

    void SetCompoundFrustum(TaskArg1* frustum)
    {
        field_c0 = frustum;
    }

    __forceinline ~BSCullingProcess()
    {
        FUN_004a0f60();
    }
};

void __cdecl FUN_00b6bee0(void* arg0, void* arg2, BSCullingProcess* pCulling);
void __cdecl FUN_00b6bfc0(void* arg0, void* arg, BSCullingProcess* pCulling);

struct TaskItem
{
    NiPointer<NiRefObject> sp00;
    Class0xa4* p04;
    NiPointer<NiRefObject> sp08;
    void* unk0c;
    void* unk10;
    NiPointer<NiRefObject> sp14;
    unsigned int cullMode;
    void* unk1c;
};

class AccumTaskReceiver : public ::TaskThreadManager
{
  public:
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
    TaskItem tasks[24];

    __forceinline TaskItem& GetTask(unsigned int index)
    {
        return tasks[index];
    }
};

// @fnv 0x00ba3390
// pdb: MTRenderingSystem::AddAccumTask | MTRenderingSystem.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: BSTextureManager::ReturnFrustumShadowTexture)
// pdb params: apCamera, apFrustum, apScene, apSceneList1, apSceneList2, apAccum, akCullType, aiStage, aiBatchRendererIndex
void __fastcall FUN_00ba3390(AccumTaskReceiver* self, void*, NiRefObject* a1, TaskArg1* a2, NiRefObject* a3, void* a4,
                             void* a5, NiRefObject* a6, unsigned int a7, unsigned int a8, void* a9)
{
    if (::DAT_011f94b4)
    {
        self->GetTask(a8).sp00 = a1;
        self->GetTask(a8).p04 = 0;
        self->GetTask(a8).sp08 = a3;
        self->GetTask(a8).unk0c = a4;
        self->GetTask(a8).unk10 = a5;
        self->GetTask(a8).sp14 = a6;
        self->GetTask(a8).cullMode = a7;
        self->GetTask(a8).unk1c = a9;

        if (a2)
        {
            Class0xa4* obj = new Class0xa4();
            self->GetTask(a8).p04 = obj;
            a2->CopyTo(obj);
        }
    }
    else
    {
        BSCullingProcess culling;
        culling.SetAccumulator(a6);
        culling.SetCullMode(a7);
        culling.SetCompoundFrustum(a2);
        if (a3)
        {
            FUN_00b6bee0(a1, a3, &culling);
        }
        if (a4)
        {
            FUN_00b6bfc0(a1, a4, &culling);
        }
        if (a5)
        {
            FUN_00b6bfc0(a1, a5, &culling);
        }
    }
}

}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace RenderShutdownDetail {
typedef int(__stdcall* SemaphoreRelease)(void*, long, long*);
struct TaskSemaphore
{
    volatile long count;
    void* handle;
    void Signal(SemaphoreRelease release)
    {
        release(handle, 1, 0);
        InterlockedIncrement(&count);
    }
    void Wait()
    {
        WaitForSingleObject(handle, 0xffffffffUL);
        InterlockedDecrement(&count);
    }
};
struct RenderTask
{
    virtual ~RenderTask();
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
    TaskSemaphore signal;
    unsigned int unk38;
    TaskSemaphore completion;
    unsigned int unk44;
    bool stopping;
};
struct RenderTaskManager : ::TaskThreadManager
{
    RenderTask* tasks[2];
};
// @fnv 0x00ba2d80
// pdb: MTRenderingSystem::DestroyThreads | MTRenderingSystem.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: BeamShader::Free)
void __fastcall FUN_00ba2d80(RenderTaskManager* manager)
{
    if (!::DAT_011f94b4)
        return;
    SemaphoreRelease release = &ReleaseSemaphore;
    for (unsigned int index = 0; index < 2; ++index)
    {
        RenderTask* task = manager->tasks[index];
        if (task)
        {
            task->stopping = true;
            task->signal.Signal(release);
            task = manager->tasks[index];
            task->completion.Wait();
            delete manager->tasks[index];
            manager->tasks[index] = 0;
        }
    }
}

}

int sprintf_s(char*, size_t, const char*, ...);

extern MemoryManager g_memoryManager;
struct BSThread
{
    void Initialize(int stackSize, const char* name, bool suspended);
    void FUN_00aa6550(unsigned int);
    void SetThreadPriority(int);
    void SetName(const char*);
};
struct BSLinearTaskThread : BSThread
{
    BSLinearTaskThread();
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
};
extern void* DAT_010b7f50;
struct RenderTaskThread : BSLinearTaskThread
{
    void(__cdecl* m_pTaskFunction)();
    RenderTaskThread(void(__cdecl* f)())
    {
        *(void**)this = &DAT_010b7f50;
        m_pTaskFunction = f;
    }
    void* operator new(size_t s)
    {
        return g_memoryManager.Allocate(s);
    }
    void operator delete(void*);
};
struct ThreadOwner
{
    RenderTaskThread* m_threads[2];
    void FUN_00ba2e00(int index, unsigned int affinity, void(__cdecl* task)(), const char* name,
                      unsigned int stackSize);
};
// @f3 0x00724220 (community match, verified in this file)
namespace Task1449 {
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct FUN_007240a0 {
    FUN_007240a0();
    virtual ~FUN_007240a0();
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
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    void FUN_0086ce90(unsigned,const char*);
    void FUN_0078c030(unsigned);
    void FUN_0078c030(const char*);
    void FUN_0086ce30(int);
};
struct RenderTaskThread : FUN_007240a0 {
    void (__cdecl* task)();
    RenderTaskThread(void (__cdecl* f)()) {task=f;}
    virtual ~RenderTaskThread();
    static void* operator new(unsigned n) {return DAT_01090a78.FUN_0086b930(n);}
    static void operator delete(void* p) {DAT_01090a78.FUN_0086ba60(p);}
};
}
// pdb: AILinearTaskThreadManager::AddThread | AILinearTaskThreadManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiThreadIndex, aiHWThread, apfnTaskFunc, apThreadName, aeStackSize
void ThreadOwner::FUN_00ba2e00(int index,unsigned affinity,void (__cdecl* task)(),const char* name,unsigned stackSize) {
    using namespace Task1449;
    Task1449::RenderTaskThread** threads=(Task1449::RenderTaskThread**)this;
    if(index<3 && index<2 && !threads[index]) {
        threads[index]=new Task1449::RenderTaskThread(task);
        threads[index]->FUN_0086ce90(stackSize,name);
        threads[index]->FUN_0078c030(affinity);
        threads[index]->FUN_0086ce30(0);
        if(!name) {
            char buf[0x104];
            sprintf_s(buf,0x104,"AI Linear Task Thread DEF %i",index);
            threads[index]->FUN_0078c030(buf);
        }
    }
}


extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* lpPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
struct WorkerSync_ba2f30
{
    volatile long activeCount;
    void* semaphore;
};
struct WorkerState_ba2f30
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    WorkerSync_ba2f30 synchronization;
};
class ThreadCoordinator_ba2f30
{
  public:
    WorkerState_ba2f30* workers[2];
    unsigned int unk08;
    volatile unsigned int counters[2];
    void FUN_00ba2f30();
};
// @fnv 0x00ba2f30
// pdb: MTRenderingSystem::StartThreads | MTRenderingSystem.obj | fnv360_0822_retail, caller, medium
void ThreadCoordinator_ba2f30::FUN_00ba2f30()
{
    if (!DAT_011f94b4)
        return;
    volatile unsigned int* current = counters;
    unsigned int remaining = 2;
    do
    {
        *current++ = 0;
    } while (--remaining);
    for (unsigned int index = 0; index < 2; ++index)
    {
        WorkerState_ba2f30* worker = workers[index];
        if (worker != 0)
        {
            WorkerSync_ba2f30* synchronization = &worker->synchronization;
            ReleaseSemaphore(synchronization->semaphore, 1, 0);
            InterlockedIncrement(&synchronization->activeCount);
        }
    }
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern bool DAT_011f94b4;

struct SemaphoreBA2
{
    long m_lCount;
    void* m_hEvent;

    void Wait()
    {
        WaitForSingleObject(m_hEvent, 0xffffffff);
        InterlockedDecrement(&m_lCount);
    }
};

struct TaskThreadBA2
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
    SemaphoreBA2 m_kDoneSemaphore;
};

class FUN_00ba2fa0_C
{
  public:
    TaskThreadBA2* m_apThreads[2];

    void FUN_00ba2fa0();
};

// @fnv 0x00ba2fa0
// pdb: MTRenderingSystem::WaitForThreads | MTRenderingSystem.obj | fnv360_0822_retail, call_gap, medium
void FUN_00ba2fa0_C::FUN_00ba2fa0()
{
    if (DAT_011f94b4)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            TaskThreadBA2* pThread = m_apThreads[i];
            if (pThread)
                pThread->m_kDoneSemaphore.Wait();
        }
    }
}

namespace fnv_00ba2ff0 {
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
namespace fnv_ba2ff0_cleanup {
struct ThreadState
{
    void* vtable;
    void* criticalSection;
    unsigned int unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    void __thiscall FUN_00aa63c0();
};
struct SemaphoreState
{
    volatile int count;
    void* handle;
    int maximumCount;
    __forceinline void Release()
    {
        CloseHandle(handle);
    }
};
struct WorkerThreadState : ThreadState
{
    SemaphoreState startProcessing;
    SemaphoreState finishedProcessing;
    bool killThread;
};
// @fnv 0x00ba2ff0
// pdb: AITaskThread::`scalar deleting destructor' | AITaskManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: RenderingTaskThread::RunLinearTasks)
void* __fastcall FUN_00ba2ff0(WorkerThreadState* self, void*, unsigned int flags)
{
    self->finishedProcessing.Release();
    self->startProcessing.Release();
    self->ThreadState::FUN_00aa63c0();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}
}  // namespace fnv_00ba2ff0

struct NiRefObject
{
    virtual void F0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct NiPointer
{
    T* m_pObject;
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct FUN_00ba3030
{
    NiPointer<NiRefObject> m_p1;
    int m_iValueAfterStandIn;
    NiPointer<NiRefObject> m_p2;
    int m_pAuxiliaryObject[2];
    NiPointer<NiRefObject> m_p3;
    int m_pad3[2];

    ~FUN_00ba3030();
};

// @fnv 0x00ba3030
// pdb: MTRenderingSystem::AccumTask::~AccumTask | MTRenderingSystem.obj | fnv360_0721_beta, objrun_open, low
FUN_00ba3030::~FUN_00ba3030()
{}

struct FUN_00ba30e0
{
    int state00;
    int unk04;
    int state08;
    int unk0c;
    int unk10;
    int state14;

    FUN_00ba30e0();
};

// @fnv 0x00ba30e0
// pdb: RenderingTaskThread::OnFinish | MTRenderingSystem.obj | tesv_win, objrun_open, low
FUN_00ba30e0::FUN_00ba30e0()
{
    state00 = 0;
    state08 = 0;
    state14 = 0;
}

__declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern int(__stdcall* DAT_00fdf1c0)(void*);

namespace ThreadStageSignalDetail {
struct Semaphore
{
    volatile int count;
    void* handle;
    int maximum;
};

class RenderingStageController : public TaskThreadManager
{
  public:
    void* threads[3];
    volatile int stages[3];
    Semaphore semaphores[3];

    void FUN_00ba30f0(int threadIndex, int stage);
};

// @fnv 0x00ba30f0
// pdb: MTRenderingSystem::SetThreadStage | MTRenderingSystem.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aiThreadIndex, aiStage
void RenderingStageController::FUN_00ba30f0(int threadIndex, int stage)
{
    if (DAT_011f94b4 && threadIndex < 2)
    {
        Semaphore& signal = semaphores[threadIndex];
        ReleaseSemaphore(signal.handle, 1, 0);
        DAT_00fdf1c0(const_cast<int*>(&signal.count));
    }
}
}

namespace fnv_00ba3190 {
extern "C" unsigned long __readfsdword(unsigned long offset);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* semaphore, long releaseCount,
                                                                long* previousCount);

struct RefObjMt
{
    virtual void vfn00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

struct SubObjMt
{
    void FUN_00c47770();
};

struct MemoryManagerMt
{
    void Deallocate(void* p);
};
extern MemoryManagerMt g_memoryManager;

struct MTRenderingSystem_Helper
{
    void FUN_00ba3130(int a, int b);
};

struct FUN_00a69400
{
    FUN_00a69400(void* pArray);
    void* vtbl;
};

extern const void* DAT_0101e2ec;

struct BSCullingProcess
{
    void FUN_004a0f60();
};

struct CullProc : FUN_00a69400
{
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
    SubObjMt* unkC0;
    RefObjMt* unkC4;
    CullProc() : FUN_00a69400(0)
    {
        vtbl = &DAT_0101e2ec;
        unk90 = 0;
        unkBC = 0;
        unkC0 = 0;
        unkC4 = 0;
    }
    ~CullProc()
    {
        ((BSCullingProcess*)this)->FUN_004a0f60();
    }
};
void FUN_00b6bee0(RefObjMt* a, RefObjMt* b, CullProc* c);
void FUN_00b6bfc0(RefObjMt* a, void* b, CullProc* c);
static inline void AddB(RefObjMt* a, RefObjMt* b, CullProc* c)
{
    FUN_00b6bee0(a, b, c);
}
static inline void AddC(RefObjMt* a, void* b, CullProc* c)
{
    FUN_00b6bfc0(a, b, c);
}

struct TaskRecordMt
{
    RefObjMt* unk00;
    SubObjMt* unk04;
    RefObjMt* unk08;
    void* unk0C;
    void* unk10;
    RefObjMt* unk14;
    int unk18;
    int unk1C;
};
extern TaskRecordMt DAT_012000e4[23];

extern unsigned int DAT_0126fd98;
extern volatile long DAT_012000ac;
extern void* DAT_012000b0;

static inline void Release(RefObjMt*& rp)
{
    RefObjMt* p = rp;
    if (p)
    {
        if (InterlockedDecrement(&p->m_uiRefCount) == 0)
            p->DeleteThis();
        rp = 0;
    }
}

// @f3 0x00b0d290 (community match, verified in this file)
#include <intrin.h>

extern "C" const void* DAT_0101e2ec;
extern unsigned int __tls_index;
extern "C" void* DAT_01175748;
extern "C" volatile long DAT_01175744;

namespace h_00b0d290 {

struct RefObject
{
    virtual void v00();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
};

template <class T> struct RefPtr
{
    T* m_pObject;

    RefPtr& operator=(T* pObject)
    {
        if (m_pObject != pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct SubObj
{
    void FUN_00c47770();
};

// The project's file declares fnv_00ba3190::MemoryManagerMt, whose deallocation
// entry point is Deallocate (it has no Free member). The pack's local memory-manager
// stand-in only offers Free, so the same thiscall is written through a view of the
// real manager object: identical code, and it compiles against the file's class.
struct MemoryManagerDeallocView
{
    void Deallocate(void* p);
};

struct TaskItem
{
    RefPtr<RefObject> sp00;
    SubObj* p04;
    RefPtr<RefObject> sp08;
    void* unk0c;
    void* unk10;
    RefPtr<RefObject> sp14;
    unsigned int cullMode;
    void* unk1c;
};

struct CullBase
{
    const void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c;

    CullBase(void* visibleSet = 0);
};

struct Cull : CullBase
{
    unsigned int cullMode;
    int unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8;
    void* field_bc;
    void* field_c0;
    void* field_c4;

    Cull() : CullBase(0)
    {
        vtable = &DAT_0101e2ec;
        cullMode = 0;
        field_bc = 0;
        field_c0 = 0;
        field_c4 = 0;
    }

    void SetAccumulator(RefObject* accumulator)
    {
        if (accumulator) {
            field_c4 = accumulator;
            accumulator->IncRefCount();
        }
    }
    void SetCullMode(unsigned int mode)
    {
        cullMode = mode;
    }
    void SetCompoundFrustum(void* frustum)
    {
        field_c0 = frustum;
    }

    void FUN_004a0f60();

    __forceinline ~Cull()
    {
        FUN_004a0f60();
    }
};

struct StageWait
{
    void FUN_00ba3130(int threadIndex, int stage);
};

void __cdecl FUN_00b6bee0(void* arg0, void* arg2, Cull* pCulling);
void __cdecl FUN_00b6bfc0(void* arg0, void* arg, Cull* pCulling);

static void AddB(void* a, void* b, Cull* c) { FUN_00b6bee0(a, b, c); }
static void AddC(void* a, void* b, Cull* c) { FUN_00b6bfc0(a, b, c); }

extern StageWait DAT_01175720;
extern TaskItem DAT_0117577c[24];
}
void __cdecl FUN_00ba3190();
namespace fnv_00ba3190 { void __cdecl FUN_00ba3190(); }
// pdb: MTRenderingSystem::Thread2TaskFunc | MTRenderingSystem.obj | fnv360_0822_retail, caller_sim, low
void __cdecl ::fnv_00ba3190::FUN_00ba3190()
{
    for (int i = 1; i < 24; i++) {
        h_00b0d290::TaskItem* rec = &h_00b0d290::DAT_0117577c[i - 1];
        h_00b0d290::DAT_01175720.FUN_00ba3130(0, i);
        if (rec->sp14.m_pObject) {
            *(void**)(((char**)__readfsdword(0x2c))[__tls_index] + 0x2a4) = rec->unk1c;
            h_00b0d290::Cull cull;
            cull.SetAccumulator(rec->sp14.m_pObject);
            cull.SetCullMode(rec->cullMode);
            cull.SetCompoundFrustum(rec->p04);
            if (rec->sp08.m_pObject)
                h_00b0d290::AddB(rec->sp00.m_pObject, rec->sp08.m_pObject, &cull);
            if (rec->unk0c)
                h_00b0d290::AddC(rec->sp00.m_pObject, rec->unk0c, &cull);
            if (rec->unk10)
                h_00b0d290::AddC(rec->sp00.m_pObject, rec->unk10, &cull);
            rec->unk1c = 0;
            rec->unk0c = 0;
            rec->unk10 = 0;
            rec->sp14 = 0;
            rec->sp00 = 0;
            rec->sp08 = 0;
            h_00b0d290::SubObj* s = rec->p04;
            if (s) {
                s->FUN_00c47770();
                ((h_00b0d290::MemoryManagerDeallocView*)&g_memoryManager)->Deallocate(s);
                rec->p04 = 0;
            }
        }
        if (DAT_011f94b4) {
            ReleaseSemaphore(DAT_01175748, 1, 0);
            InterlockedIncrement(&DAT_01175744);
        }
    }
}

}  // namespace fnv_00ba3190

void __cdecl FUN_00ba2d70();
void __cdecl FUN_00ba3030();
void __stdcall FUN_00ec5fce(void*, unsigned int, int, void(__cdecl*)());

struct LinearTaskRecord
{
    unsigned int taskId;
    unsigned int flags;
    unsigned int state;
};

struct RenderTaskRecord
{
    unsigned int type;
    unsigned int index;
    unsigned int input;
    unsigned int output;
    unsigned int width;
    unsigned int height;
    unsigned int format;
    unsigned int options;
};

struct LinearTaskGroup
{
    LinearTaskRecord tasks[3];
    __forceinline ~LinearTaskGroup()
    {
        FUN_00ec5fce(tasks, sizeof(LinearTaskRecord), 3, FUN_00ba2d70);
    }
};

struct RenderTaskGroup
{
    RenderTaskRecord tasks[24];
    __forceinline ~RenderTaskGroup()
    {
        FUN_00ec5fce(tasks, sizeof(RenderTaskRecord), 24, FUN_00ba3030);
    }
};

struct FUN_00ba3620
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    LinearTaskGroup linearTasks;
    RenderTaskGroup renderTasks;
    ~FUN_00ba3620();
};

// @fnv 0x00ba3620
FUN_00ba3620::~FUN_00ba3620()
{}
