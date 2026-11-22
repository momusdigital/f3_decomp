#include "f3_common.h"
// src/havok/common/base/thread/semaphore/win32/hkwin32semaphore.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/semaphore/win32/hkwin32semaphore.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* h, unsigned long ms);

// @fnv 0x00d04380
// pdb: hkSemaphore::acquire | hkWin32Semaphore.obj | tesv_win, objopen_prop, low
int __fastcall FUN_00d04380(void* h, int)
{
    return WaitForSingleObject(*(void**)h, (unsigned long)-1);
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* h, long releaseCount, long* previousCount);
struct FUN_00d04390
{
    void* handle;
    unsigned long wait(unsigned long amount);
};
// @fnv 0x00d04390
// pdb: hkSemaphore::release | hkWin32Semaphore.obj | tesv_win, objrun_open, low
unsigned long FUN_00d04390::wait(unsigned long amount)
{
    return (unsigned long)ReleaseSemaphore(*(void**)this, (long)amount, 0);
}

#include <windows.h>
struct FUN_00d04350_cls
{
    void* handle;
    FUN_00d04350_cls* Create(long initialCount, long maximumCount);
};

// @fnv 0x00d04350
// pdb: hkSemaphore::hkSemaphore | hkWin32Semaphore.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: initialCount, maxCount
FUN_00d04350_cls* FUN_00d04350_cls::Create(long initialCount, long maximumCount)
{
    handle = CreateSemaphoreA(0, initialCount, maximumCount, 0);
    return this;
}

struct FUN_00d04370_cls
{
    HANDLE m_hHandle;

    void FUN_00d04370();
};

// @fnv 0x00d04370
void FUN_00d04370_cls::FUN_00d04370()
{
    CloseHandle(m_hHandle);
}
