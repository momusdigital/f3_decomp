#include <string>
#include <vector>
#include <string.h>
#include <windows.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00be0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00bff8ce (community match, verified in this file)
namespace f3m_00bff8ce {
void __cdecl FUN_00bff8ce(LPCRITICAL_SECTION cs)
{
    LeaveCriticalSection(cs);
}
}   // namespace f3m_00bff8ce

// @f3 0x00bff8ad (community match, verified in this file)
namespace f3m_00bff8ad {
typedef void (__stdcall *Handler)(int);
extern Handler DAT_00d9b094;
void __cdecl FUN_00bff8ad(int arg) { DAT_00d9b094(arg); }
}   // namespace f3m_00bff8ad

// @f3 0x00bff8b8 (community match, verified in this file)
#include <windows.h>
namespace f3m_00bff8b8 {
// pdb: _Mtxdst | xmtx.obj | fnv360_0721_beta, objrun, medium
// pdb params: _Mtx
void __cdecl FUN_00bff8b8(LPCRITICAL_SECTION cs)
{
    DeleteCriticalSection(cs);
}
}   // namespace f3m_00bff8b8

// @f3 0x00bff8c3 (community match, verified in this file)
namespace f3m_00bff8c3 {
// Runtime library helper: takes the lock it is given (the C++ library's mutex 'lock' routine).
// DAT_00d9b09c is the program's import slot of the system routine EnterCriticalSection.
extern void (__stdcall* DAT_00d9b09c)(void* criticalSection);

void __cdecl FUN_00bff8c3(void* mutex)
{
    DAT_00d9b09c(mutex);
}
}   // namespace f3m_00bff8c3

// @f3 0x00bff487 (community match, verified in this file)
namespace f3m_00bff487 {
namespace f3m_00bff487 {
void* __cdecl FUN_00401000(unsigned int size);
void __cdecl FUN_00bff8ad(void* mtx);
struct Mutex {
    void* _Mtx;
    Mutex* FUN_00bff487();
};
// pdb: std::_Mutex::_Mutex | xmutex.obj | fnv360_0822_retail, call_gap, high
Mutex* Mutex::FUN_00bff487()
{
    _Mtx = FUN_00401000(0x18);
    FUN_00bff8ad(_Mtx);
    return this;
}
}
}   // namespace f3m_00bff487

// @f3 0x00bff49f (community match, verified in this file)
namespace f3m_00bff49f {
namespace f3m_00bff49f {
void __cdecl FUN_00401010(void* p);
void __cdecl FUN_00bff8b8(void* mtx);
struct Mutex {
    void* _Mtx;
    void FUN_00bff49f();
};
// pdb: std::_Mutex::~_Mutex | xmutex.obj | fnv360_0822_retail, call_gap, low
void Mutex::FUN_00bff49f()
{
    FUN_00bff8b8(_Mtx);
    FUN_00401010(_Mtx);
}
}
}   // namespace f3m_00bff49f

// @f3 0x00bff8d9 (community match, verified in this file)
namespace f3m_00bff8d9 {
namespace f3m_00bff8d9 {
typedef void (__cdecl* AtexitFn)();
extern AtexitFn DAT_01179ac0[10];
extern unsigned int DAT_0106aaec;
void __cdecl FUN_00c0ad65();
// pdb: _Atexit | iosptrs.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pf
void __cdecl FUN_00bff8d9(AtexitFn pf)
{
    if (DAT_0106aaec == 0)
        FUN_00c0ad65();
    else
        DAT_01179ac0[--DAT_0106aaec] = pf;
}
}
}   // namespace f3m_00bff8d9

// @f3 0x00bff8f9 (community match, verified in this file)
namespace f3m_00bff8f9 {
namespace f3m_00bff8f9 {
typedef void (__cdecl* AtexitFn)();
extern AtexitFn DAT_01179ac0[10];
extern unsigned int DAT_0106aaec;
struct Init_atexit {
    void FUN_00bff8f9();
};
// pdb: _Init_atexit::~_Init_atexit | iosptrs.obj | tesv_win, udata, high
void Init_atexit::FUN_00bff8f9()
{
    while (DAT_0106aaec < 10) {
        if (DAT_01179ac0[DAT_0106aaec++] != 0)
            (*DAT_01179ac0[DAT_0106aaec - 1])();
    }
}
}
}   // namespace f3m_00bff8f9

// @f3 0x00bff120 (community match, verified in this file)
namespace f3m_00bff120 {
namespace f3m_00bff120 {
struct Rmtx { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; };
extern long DAT_0106aaa8;
extern Rmtx DAT_01179848[4];
void __cdecl FUN_00bff8b8(Rmtx* mtx);
struct Init_locks {
    void FUN_00bff120();
};
// pdb: _Deletegloballocale | locale0.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: std::_Init_locks::~_Init_locks)
// pdb params: ptr
void Init_locks::FUN_00bff120()
{
    if (InterlockedDecrement(&DAT_0106aaa8) < 0)
        for (int count = 0; count < 4; ++count)
            FUN_00bff8b8(&DAT_01179848[count]);
}
}
}   // namespace f3m_00bff120

// @f3 0x00bff4b4 (community match, verified in this file)
namespace f3m_00bff4b4 {
namespace f3m_00bff4b4 {
struct ios_ {
    void* vfptr; int _Stdstr; int _Mystate; int _Except; int _Fmtfl; int _Prec; int _Wide;
    void* _Arr; void* _Calls; void* _Ploc; void* _Mystrbuf; void* _Tiestr; char _Fillch;
    void* tie(void* t) { void* o = _Tiestr; _Tiestr = t; return o; }
    int setf(int f) { int o = _Fmtfl; _Fmtfl |= f; return o; }
};
struct ostream_ : virtual ios_ {
    int unk04;
};
extern ostream_ DAT_01179928;
extern ostream_* DAT_01179aa4;
extern ostream_* DAT_01179aa8;
struct Init_cerr {
    Init_cerr* FUN_00bff4b4();
};
Init_cerr* Init_cerr::FUN_00bff4b4()
{
    DAT_01179aa8 = &DAT_01179928;
    DAT_01179928.tie(DAT_01179aa4);
    DAT_01179928.setf(2);
    return this;
}
}
}   // namespace f3m_00bff4b4

// @f3 0x00bff0f1 (community match, verified in this file)
namespace f3m_00bff0f1 {
namespace f3m_00bff0f1 {
struct Rmtx { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; };
extern long DAT_0106aaa8;
extern Rmtx DAT_01179848[4];
void __cdecl FUN_00bff8ad(Rmtx* mtx);
struct Init_locks {
    Init_locks* FUN_00bff0f1();
};
// pdb: std::_Init_locks::_Init_locks | xlock.obj | fnv360_0822_retail, caller_sim, low
Init_locks* Init_locks::FUN_00bff0f1()
{
    if (InterlockedIncrement(&DAT_0106aaa8) == 0)
        for (int count = 0; count < 4; ++count)
            FUN_00bff8ad(&DAT_01179848[count]);
    return this;
}
}
}   // namespace f3m_00bff0f1
