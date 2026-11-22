// bssystem/console/bsconsolefilecache.cpp: FaceGenData (1 function)
#include "f3_common.h"
#include "bsconsolefilecache_decls.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct DelObj
{
    virtual ~DelObj()
    {}
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long dwExitCode);

extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long);
struct Unk00b023f0
{
    void CallVfn1OnAllEntries();
    void FUN_00b02460();
    void CallVirtualOnAllEntries();
};
// Calls three methods on p in sequence, then terminates the calling thread with ExitThread(0).
// @f3 0x00bcf260 (community match, verified in this file)
// pdb: BSXenonTaskletManager::ThreadProc | BSXenonTaskletManager.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: apThis
void __stdcall FUN_00b023f0(Unk00b023f0* pTarget)
{
    pTarget->CallVfn1OnAllEntries();
    pTarget->FUN_00b02460();
    pTarget->CallVirtualOnAllEntries();
    ExitThread(0);
    __assume(0);
}


extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);

extern "C" __declspec(dllimport) void __stdcall ReleaseSemaphore(void* hSemaphore, long cReleaseCount,
                                                                 long* lPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForMultipleObjects(unsigned long nCount,
                                                                                const void* const* lpHandles,
                                                                                int bWaitAll,
                                                                                unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
