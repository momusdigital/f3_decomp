#include "f3_common.h"
// src/staging/blk_00ec0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;

struct FUN_00ec1f40Class
{
    void __thiscall FUN_00ec1020();
    void __thiscall FUN_00ec1f40();
};

namespace fnv_00ec20a0 {
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
}  // namespace fnv_00ec20a0

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};

void __cdecl FNV_Warning(const char*);

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int priority);

extern "C" __declspec(dllimport) int __stdcall GetExitCodeThread(void* hThread, unsigned long* pExitCode);

struct FUN_00ec19a0_Class
{
    int m_0000;
    void* m_0004;
    void __thiscall FUN_00ec19a0(void*);
    void* __thiscall FUN_00ec19a0(const void*);
};

extern "C" __declspec(dllimport) void __stdcall FUN_00fdf1c8(void* a, int b);

// If m_0004 is non-null, calls FUN_00fdf1c8 with m_0004 and -1.
// @f3 0x00430260 (community match, verified in this file)
namespace str_00430260 {
struct StringX
{
    void FUN_0042eff0(const void* right, int pos, int count);
};
}

// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> > | FanCtlFile.obj | fnv360_0822_retail, callee_sim, low
// pdb params: _Right
void* FUN_00ec19a0_Class::FUN_00ec19a0(const void* right)
{
    *(int*)((char*)this + 0x18) = 0xf;
    *((char*)this + 4 + (*(int*)((char*)this + 0x14) = 0)) = 0;
    ((str_00430260::StringX*)this)->FUN_0042eff0(right, 0, -1);
    return this;
}


extern int DAT_010f1ca4;

extern int DAT_010f1c20;

void __cdecl FNV_Warning(const char*, ...);

extern "C" __declspec(dllimport) void __stdcall BinkClose(int handle);

extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(void* hBink);
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBufferRect(void* hBink, void* dest, int destPitch,
                                                                    unsigned int destHeight, unsigned int destX,
                                                                    unsigned int destY, unsigned int srcX,
                                                                    unsigned int srcY, unsigned int srcWidth,
                                                                    unsigned int srcHeight, unsigned int flags);

// EnableSoundSystem: enables the Bink direct-sound output path.
// The Bink library is reached through the executable's import table; the
// address of the direct-sound entry point is passed to BinkSetSoundSystem.

extern "C" __declspec(dllimport) void __stdcall BinkOpenDirectSound(void* apDirectSound);
extern "C" __declspec(dllimport) void __stdcall BinkSetSoundSystem(void* system, unsigned int flags);

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pvSecurity, unsigned long ulStackSize,
                                                              unsigned long(__stdcall* pfnStart)(void*), void* pvParam,
                                                              unsigned long ulFlags, unsigned long* pulThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long ulMilliseconds);

void __cdecl FUN_00aa2740(unsigned long ulThreadId, const char* pcName);

extern int DAT_010f1ca4;

struct FUN_00ec1df0_pool
{
    void FUN_00aa4060(void* apMemory);
};
extern FUN_00ec1df0_pool DAT_011f6238;

namespace fnv_00ec1ee0 {
extern int DAT_010f1c20;

class FUN_00ec1ee0_pool
{
  public:
    void FUN_00aa4060(void* apMemory);
};
extern FUN_00ec1ee0_pool DAT_011f6238;

}  // namespace fnv_00ec1ee0

extern "C" __declspec(dllimport) int __stdcall SetThreadPriorityBoost(void* hThread, int fDisable);

extern "C" __declspec(dllimport) void __stdcall _BinkPause_8(void*, int);

namespace fnv_00ec25e0 {
struct FUN_00aa4060_Obj
{
    void __thiscall FUN_00aa4060(FUN_00ec1f40Class* p);
};
extern FUN_00aa4060_Obj DAT_011f6238;

}  // namespace fnv_00ec25e0

namespace fnv_00ec2d80 {

struct S_00aa3e40_Class
{
    char* __thiscall FUN_00aa3e40(char* a);
};

extern S_00aa3e40_Class DAT_011f6238;

}  // namespace fnv_00ec2d80

// Look up the file name registered under a key and copy it into a MAX_PATH buffer.

extern "C" __declspec(dllimport) int __stdcall BinkWait(void*);
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(void*);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

namespace fnv_00ec1940 {
#include <windows.h>

DWORD WINAPI FUN_00ec2ca0(LPVOID param);
void FUN_00aa2740(DWORD threadId, const char* name);

}  // namespace fnv_00ec1940

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

struct PlaybackMessage
{
    void* window;
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    long cursorX;
    long cursorY;
};

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(PlaybackMessage*, void*, unsigned int, unsigned int,
                                                            unsigned int);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const PlaybackMessage*);
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const PlaybackMessage*);
