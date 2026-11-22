#include <stdarg.h>
// src/f3staging/f3blk_00c00000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00c164f4 (community match, verified in this file)
namespace f3m_00c164f4 {
namespace f3m_00c164f4 {
struct LockEntry { void* lock; int kind; };
extern "C" LockEntry DAT_0106bcc0[36];
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* cs);
extern "C" void __cdecl FUN_00c064b8(void* p);
// pdb: _mtdeletelocks | mlock.obj | tesv_win, call_seq, medium
extern "C" void __cdecl FUN_00c164f4(void)
{
    int locknum;
    for (locknum = 0; locknum < 36; locknum++) {
        if (DAT_0106bcc0[locknum].lock != 0 && DAT_0106bcc0[locknum].kind != 1) {
            void* pcs = DAT_0106bcc0[locknum].lock;
            DeleteCriticalSection(pcs);
            FUN_00c064b8(pcs);
            DAT_0106bcc0[locknum].lock = 0;
        }
    }
    for (locknum = 0; locknum < 36; locknum++) {
        if (DAT_0106bcc0[locknum].lock != 0 && DAT_0106bcc0[locknum].kind == 1) {
            DeleteCriticalSection(DAT_0106bcc0[locknum].lock);
        }
    }
}
}
}   // namespace f3m_00c164f4

// @f3 0x00c09dd5 (community match, verified in this file)
namespace f3m_00c09dd5 {
namespace f3m_00c09dd5 {
struct EHExceptionRecord {
    unsigned long ExceptionCode;
    unsigned long ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned long NumberParameters;
    unsigned long magicNumber;
    void* pExceptionObject;
    void* pThrowInfo;
};
struct EXCEPTION_POINTERS_ { EHExceptionRecord* ExceptionRecord; void* ContextRecord; };
struct UnwindMapEntry { int toState; void* action; };
struct TryBlockMapEntry { int tryLow; int tryHigh; int catchHigh; int nCatches; void* pHandlerArray; };
struct FuncInfo { unsigned int magicNumber; int maxState; UnwindMapEntry* pUnwindMap; unsigned int nTryBlocks; TryBlockMapEntry* pTryBlockMap; };
struct EHRegistrationNode { EHRegistrationNode* pNext; void* frameHandler; int state; };
struct FRAMEINFO { void* pExceptionObject; FRAMEINFO* pNext; };
struct Tiddata {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    void* _curexception;
    void* _curcontext;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208;
    int _ProcessingThrow;
};
extern "C" Tiddata* __cdecl FUN_00c0c229(void);
extern "C" FRAMEINFO* __cdecl FUN_00c00099(FRAMEINFO* pFrameInfo, void* pExceptionObject);
extern "C" void* __cdecl FUN_00c0012e(EHRegistrationNode* pRN, FuncInfo* pFuncInfo, void* handlerAddress, int CatchDepth, unsigned long NLGCode);
extern "C" void __cdecl FUN_00c09b74(EHRegistrationNode* pRN, void* pDC, FuncInfo* pFuncInfo, int targetState);
extern "C" void __cdecl FUN_00c000e2(FRAMEINFO* pFrameInfo);
extern "C" int __cdecl FUN_00c000c1(void* pExceptionObject);
extern "C" void __cdecl FUN_00c09c9a(EHExceptionRecord* pExcept, unsigned char fThrowNotAllowed);
extern "C" void* __cdecl _exception_info(void);
extern "C" int __cdecl _abnormal_termination(void);
static __declspec(noinline) int FUN_00c09c55(EXCEPTION_POINTERS_* pExPtrs)
{
    EHExceptionRecord* pExcept = pExPtrs->ExceptionRecord;
    if (pExcept->ExceptionCode == 0xe06d7363 && pExcept->NumberParameters == 3
        && (pExcept->magicNumber == 0x19930520 || pExcept->magicNumber == 0x19930521 || pExcept->magicNumber == 0x19930522)
        && pExcept->pExceptionObject == 0)
        return 1;
    return 0;
}
// pdb: __InternalCxxFrameHandler | frame.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: CallCatchBlock)
// pdb params: pExcept, pRN, pContext, pDC, pFuncInfo, CatchDepth, pMarkerRN, recursive
static __declspec(noinline) void* FUN_00c09dd5(EHExceptionRecord* pExcept, EHRegistrationNode* pRN, void* pContext, FuncInfo* pFuncInfo, void* handlerAddress, int CatchDepth, unsigned long NLGCode)
{
    void* continuationAddress = handlerAddress;
    int ExceptionObjectDestroyed = 0;
    void* saveESP = ((void**)pRN)[-1];
    FRAMEINFO FrameInfo;
    FRAMEINFO* pFrameInfo = FUN_00c00099(&FrameInfo, pExcept->pExceptionObject);
    EHExceptionRecord* pSaveException = (EHExceptionRecord*)FUN_00c0c229()->_curexception;
    void* pSaveExContext = FUN_00c0c229()->_curcontext;
    FUN_00c0c229()->_curexception = pExcept;
    FUN_00c0c229()->_curcontext = pContext;
    __try {
        __try {
            continuationAddress = FUN_00c0012e(pRN, pFuncInfo, handlerAddress, CatchDepth, NLGCode);
        }
        __except (FUN_00c09c55((EXCEPTION_POINTERS_*)_exception_info())) {
            FUN_00c0c229()->_ProcessingThrow = 0;
            UnwindMapEntry* pUnwindMap = pFuncInfo->pUnwindMap;
            int cState = pFuncInfo->maxState <= 128 ? (signed char)pRN->state : pRN->state;
            TryBlockMapEntry* pTryBlockMap = pFuncInfo->pTryBlockMap;
            unsigned int i;
            for (i = 0; i < pFuncInfo->nTryBlocks; i++) {
                if (cState > pTryBlockMap[i].tryHigh && cState <= pTryBlockMap[i].catchHigh) {
                    cState = pTryBlockMap[i].tryHigh + 1;
                    cState = pUnwindMap[cState].toState;
                    break;
                }
            }
            FUN_00c09b74(pRN, 0, pFuncInfo, cState);
            continuationAddress = 0;
        }
    }
    __finally {
        ((void**)pRN)[-1] = saveESP;
        FUN_00c000e2(pFrameInfo);
        FUN_00c0c229()->_curexception = pSaveException;
        FUN_00c0c229()->_curcontext = pSaveExContext;
        if (pExcept->ExceptionCode == 0xe06d7363 && pExcept->NumberParameters == 3
            && (pExcept->magicNumber == 0x19930520 || pExcept->magicNumber == 0x19930521 || pExcept->magicNumber == 0x19930522)
            && !ExceptionObjectDestroyed && continuationAddress != 0
            && FUN_00c000c1(pExcept->pExceptionObject))
        {
            FUN_00c09c9a(pExcept, (unsigned char)_abnormal_termination());
        }
    }
    return continuationAddress;
}
volatile int g_in;
void* volatile g_out;
extern "C" void caller_of_FUN_00c09dd5()
{
    g_out = FUN_00c09dd5((EHExceptionRecord*)g_in, (EHRegistrationNode*)g_in, (void*)g_in, (FuncInfo*)g_in, (void*)g_in, g_in, g_in);
}
}
}   // namespace f3m_00c09dd5

// @f3 0x00c0b95e (community match, verified in this file)
namespace f3m_00c0b95e {
namespace f3m_00c0b95e {
extern "C" int __cdecl FUN_00c1bc08(unsigned int* currentControl, unsigned int newControl, unsigned int mask);
extern "C" void __cdecl FUN_00c01d6b(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
// pdb: _setdefaultprecision | fp8.obj | tesv_win, caller_sim, low
extern "C" void __cdecl FUN_00c0b95e(void)
{
    if (FUN_00c1bc08(0, 0x10000, 0x30000) != 0)
        FUN_00c01d6b(0, 0, 0, 0, 0);
}
}
}   // namespace f3m_00c0b95e

// @f3 0x00c0c4e6 (community match, verified in this file)
namespace f3m_00c0c4e6 {
namespace f3m_00c0c4e6 {
typedef void (__cdecl* terminate_function)(void);
struct tiddata_ {
    unsigned long _tid; void* _thandle; int _terrno; unsigned long _tdoserrno; unsigned int _fpds; unsigned long _holdrand;
    char* _token; void* _wtoken; unsigned char* _mtoken; char* _errmsg; void* _werrmsg; char* _namebuf0; void* _wnamebuf0;
    char* _namebuf1; void* _wnamebuf1; char* _asctimebuf; void* _wasctimebuf; void* _gmtimebuf; char* _cvtbuf;
    unsigned char _con_ch_buf[5]; unsigned short _ch_buf_used; void* _initaddr; void* _initarg; void* _pxcptacttab;
    void* _tpxcptinfoptrs; int _tfpecode; void* ptmbcinfo; void* ptlocinfo; int _ownlocale; unsigned long _NLG_dwCode;
    void* _terminate;
};
extern "C" tiddata_* __cdecl FUN_00c0c229(void);
extern "C" void __cdecl FUN_00c0ad65(void);
// pdb: terminate | hooks.obj | tesv_win, hash, low
extern "C" void __cdecl FUN_00c0c4e6(void)
{
    tiddata_* ptd = FUN_00c0c229();
    terminate_function pTerminate = (terminate_function)ptd->_terminate;
    if (pTerminate != 0) {
        __try {
            (*pTerminate)();
        }
        __except (1) {
        }
    }
    FUN_00c0ad65();
}
}
}   // namespace f3m_00c0c4e6

// @f3 0x00c0c532 (community match, verified in this file)
extern "C" void* DAT_01179b80;
namespace f3m_00c0c532 {
namespace f3m_00c0c532 {
typedef void (__cdecl* terminate_function)(void);
extern "C" void* __cdecl FUN_00c0c00d(void* p);
extern "C" __declspec(noreturn) void __cdecl FUN_00c0c4e6(void);
// pdb: terminate | hooks.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: _inconsistency)
extern "C" void __cdecl FUN_00c0c532(void)
{
    terminate_function inconsistencyFunction;
    inconsistencyFunction = (terminate_function)FUN_00c0c00d(DAT_01179b80);
    if (inconsistencyFunction != 0) {
        __try {
            inconsistencyFunction();
        }
        __except (1) {
        }
    }
    FUN_00c0c4e6();
}
}
}   // namespace f3m_00c0c532

// @f3 0x00c173ab (community match, verified in this file)
extern "C" void* DAT_0117a4a4;
namespace f3m_00c173ab {
extern "C" unsigned long __cdecl _exception_code(void);
namespace f3m_00c173ab {
typedef int (__stdcall* PFN_INIT_CRITSEC_AND_SPIN_COUNT)(void* lpCriticalSection, unsigned long dwSpinCount);
extern "C" void* __cdecl FUN_00c0c00d(void* p);
extern "C" void* __cdecl FUN_00c0bf96(void* p);
extern "C" int __cdecl FUN_00c06926(int* osplatform);
extern "C" void __cdecl FUN_00c01d6b(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" int __stdcall FUN_00c1739b(void* lpCriticalSection, unsigned long dwSpinCount);
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* name);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* h, const char* name);
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long code);
// pdb: __crtInitCritSecAndSpinCount | mlock.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: GLock::GLock)
// pdb params: lpCriticalSection, dwSpinCount
extern "C" int __cdecl FUN_00c173ab(void* lpCriticalSection, unsigned long dwSpinCount)
{
    int ret;
    int osplatform = 0;
    PFN_INIT_CRITSEC_AND_SPIN_COUNT pfn = 0;
    pfn = (PFN_INIT_CRITSEC_AND_SPIN_COUNT)FUN_00c0c00d(DAT_0117a4a4);
    if (pfn == 0) {
        void* hKernel32;
        {
            int _Expr_val = (FUN_00c06926(&osplatform));
            if (_Expr_val != 0)
                FUN_00c01d6b(0, 0, 0, 0, 0);
        }
        if (osplatform == 1) {
            pfn = FUN_00c1739b;
        } else {
            hKernel32 = GetModuleHandleA("kernel32.dll");
            if (hKernel32 != 0) {
                pfn = (PFN_INIT_CRITSEC_AND_SPIN_COUNT)GetProcAddress(hKernel32, "InitializeCriticalSectionAndSpinCount");
                if (pfn == 0)
                    pfn = FUN_00c1739b;
            } else {
                pfn = FUN_00c1739b;
            }
        }
        DAT_0117a4a4 = FUN_00c0bf96((void*)pfn);
    }
    __try {
        ret = pfn(lpCriticalSection, dwSpinCount);
    }
    __except (_exception_code() == 0xc0000017 ? 1 : 0) {
        if (_exception_code() == 0xc0000017)
            SetLastError(8);
        ret = 0;
    }
    return ret;
}
}
}   // namespace f3m_00c173ab

// @f3 0x00c09b74 (community match, verified in this file)
namespace f3m_00c09b74 {
extern "C" void* __cdecl _exception_info(void);
namespace f3m_00c09b74 {
struct UnwindMapEntry_ {
    int toState;
    void* action;
};
struct FuncInfo_ {
    unsigned int magicNumber;
    int maxState;
    UnwindMapEntry_* pUnwindMap;
};
struct EHRegistrationNode_ {
    EHRegistrationNode_* pNext;
    void* frameHandler;
    int state;
};
struct DispatcherContext_;
struct tiddata_ {
    int unk[0x90 / 4];
    int _ProcessingThrow;
};
extern "C" tiddata_* __cdecl FUN_00c0c229(void);
extern "C" void __cdecl FUN_00c0c532(void);
extern "C" void* __stdcall FUN_00c0c580(void* funcAddress, void* realFP, unsigned long NLGCode);
extern "C" int __cdecl FUN_00c09b30(void* pExPtrs);
// pdb: __FrameUnwindToEmptyState | trnsctrl.obj | fnv360_0822_debug, call_gap, low, conflict (skyrim: __FrameUnwindToState)
// pdb params: pRN, pDC, pFuncInfo
extern "C" void __cdecl FUN_00c09b74(EHRegistrationNode_* pRN, DispatcherContext_* pDC, FuncInfo_* pFuncInfo, int targetState)
{
    int curState;
    if (pFuncInfo->maxState <= 128)
        curState = (signed char)pRN->state;
    else
        curState = pRN->state;
    FUN_00c0c229()->_ProcessingThrow++;
    __try {
        while (curState != targetState) {
            if (curState <= -1 || curState >= pFuncInfo->maxState)
                FUN_00c0c532();
            int nxtState = pFuncInfo->pUnwindMap[curState].toState;
            __try {
                if (pFuncInfo->pUnwindMap[curState].action != 0) {
                    pRN->state = nxtState;
                    FUN_00c0c580(pFuncInfo->pUnwindMap[curState].action, pRN, 0x103);
                }
            }
            __except (FUN_00c09b30(_exception_info())) {
            }
            curState = nxtState;
        }
    }
    __finally {
        if (FUN_00c0c229()->_ProcessingThrow > 0)
            FUN_00c0c229()->_ProcessingThrow--;
    }
    if (curState != targetState)
        FUN_00c0c532();
    pRN->state = curState;
}
}
}   // namespace f3m_00c09b74

// @f3 0x00c1270e (community match, verified in this file)
namespace f3m_00c1270e {
namespace f3m_00c1270e {
struct CritSect { void* debugInfo; long lockCount; long recursionCount; void* owningThread; void* lockSemaphore; unsigned long spinCount; };
struct ioinfo {
    long osfhnd;
    char osfile;
    char pipech;
    int lockinitflag;
    CritSect lock;
    char textmode : 7;
    char unicode : 1;
    char pipech2[2];
    int unk28, unk2c, unk30, unk34;
};
struct StartupInfoW {
    unsigned long cb;
    wchar_t* lpReserved;
    wchar_t* lpDesktop;
    wchar_t* lpTitle;
    unsigned long dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute, dwFlags;
    unsigned short wShowWindow;
    unsigned short cbReserved2;
    unsigned char* lpReserved2;
    void* hStdInput;
    void* hStdOutput;
    void* hStdError;
};
extern "C" ioinfo* DAT_0117a660[64];
extern "C" int DAT_0117a644;
extern "C" __declspec(dllimport) void __stdcall GetStartupInfoW(StartupInfoW* info);
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileType(void* h);
extern "C" __declspec(dllimport) void* __stdcall GetStdHandle(unsigned long n);
extern "C" __declspec(dllimport) unsigned int __stdcall SetHandleCount(unsigned int n);
extern "C" int __cdecl FUN_00c173ab(CritSect* cs, unsigned long spin);
extern "C" void* __cdecl FUN_00c0ab7f(unsigned int num, unsigned int size);
// pdb: _ioinit | ioinit.obj | tesv_win, uimport, low
extern "C" int __cdecl FUN_00c1270e(void)
{
    StartupInfoW StartupInfo;
    int cfi_len;
    int fh;
    int i;
    ioinfo* pio;
    char* posfile;
    long* posfhnd;
    long stdfh;
    unsigned long htype;

    __try {
        GetStartupInfoW(&StartupInfo);
    }
    __except (1) {
        return -1;
    }

    if ((pio = (ioinfo*)FUN_00c0ab7f(32, sizeof(ioinfo))) == 0)
        return -1;

    DAT_0117a660[0] = pio;
    DAT_0117a644 = 32;

    for (; pio < DAT_0117a660[0] + 32; pio++) {
        pio->osfile = 0;
        pio->osfhnd = -1;
        pio->pipech = 10;
        pio->lockinitflag = 0;
        pio->textmode = 0;
        pio->unicode = 0;
        pio->pipech2[0] = 10;
        pio->pipech2[1] = 10;
    }

    if ((StartupInfo.cbReserved2 != 0) && (StartupInfo.lpReserved2 != 0))
    {
        cfi_len = *(int*)(StartupInfo.lpReserved2);
        posfile = (char*)(StartupInfo.lpReserved2) + sizeof(int);
        posfhnd = (long*)(posfile + cfi_len);
        cfi_len = (cfi_len < 2048) ? cfi_len : 2048;

        for (i = 1; DAT_0117a644 < cfi_len; i++) {
            if ((pio = (ioinfo*)FUN_00c0ab7f(32, sizeof(ioinfo))) == 0)
            {
                cfi_len = DAT_0117a644;
                break;
            }
            DAT_0117a660[i] = pio;
            DAT_0117a644 += 32;
            for (; pio < DAT_0117a660[i] + 32; pio++) {
                pio->osfile = 0;
                pio->osfhnd = -1;
                pio->pipech = 10;
                pio->lockinitflag = 0;
                pio->textmode = 0;
                pio->pipech2[0] = 10;
                pio->pipech2[1] = 10;
            }
        }

        for (fh = 0; fh < cfi_len; fh++, posfile++, posfhnd++) {
            if ((*posfhnd != -1) && (*posfhnd != -2) && (*posfile & 1) &&
                ((*posfile & 8) || (GetFileType((void*)*posfhnd) != 0)))
            {
                pio = DAT_0117a660[fh >> 5] + (fh & 31);
                pio->osfhnd = *posfhnd;
                pio->osfile = *posfile;
                if (!FUN_00c173ab(&pio->lock, 4000))
                    return -1;
                pio->lockinitflag++;
            }
        }
    }

    for (fh = 0; fh < 3; fh++) {
        pio = DAT_0117a660[0] + fh;
        if ((pio->osfhnd == -1) || (pio->osfhnd == -2)) {
            pio->osfile = (char)(0x01 | 0x80);
            if (((stdfh = (long)GetStdHandle((fh == 0) ? -10 : ((fh == 1) ? -11 : -12))) != -1) &&
                (stdfh != 0) &&
                ((htype = GetFileType((void*)stdfh)) != 0))
            {
                pio->osfhnd = stdfh;
                if ((htype & 0xFF) == 2)
                    pio->osfile |= 0x40;
                else if ((htype & 0xFF) == 3)
                    pio->osfile |= 0x08;
                if (!FUN_00c173ab(&pio->lock, 4000))
                    return -1;
                pio->lockinitflag++;
            }
            else {
                pio->osfile |= 0x40;
                pio->osfhnd = -2;
            }
        }
        else {
            pio->osfile |= 0x80;
        }
    }

    SetHandleCount((unsigned)DAT_0117a644);
    return 0;
}
}
}   // namespace f3m_00c1270e

// @f3 0x00c17a36 (community match, verified in this file)
namespace f3m_00c17a36 {
namespace crt_handle_lock {
struct CriticalSection {
    void* debugInfo;
    long lockCount;
    long recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long spinCount;
};

struct FileDescriptor {
    long osHandle;
    unsigned char osFlags;
    char pipeLookahead;
    int lockInitialized;
    CriticalSection lock;
    unsigned char textModeAndUnicode;
    unsigned char unk25, unk26, unk27;
    unsigned unk28, unk2c, unk30, unk34;
};

}

namespace crt_write {
using crt_handle_lock::FileDescriptor;

enum { FileOpen = 1, BadFileDescriptor = 9 };

extern "C" FileDescriptor* DAT_0117a660[];
extern "C" unsigned int DAT_0117a644;
extern "C" unsigned long* __cdecl FUN_00c02a89();
extern "C" int* __cdecl FUN_00c02a76();
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00c17470(int descriptor, const void* buffer, unsigned count);
extern "C" void __cdecl FUN_00c1d511(int descriptor);
}

extern "C" int __cdecl FUN_00c1d471(int descriptor);

// pdb: _write | write.obj | fnv360_0822_retail, call_seq, medium
// pdb params: fh, buf, cnt
extern "C" int __cdecl FUN_00c17a36(int fd, const void* buffer, unsigned count)
{
    using namespace crt_write;
    if (fd == -2) {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = BadFileDescriptor;
        return -1;
    }
    int valid = !!(fd >= 0 && static_cast<unsigned int>(fd) < DAT_0117a644);
    if (!valid) {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = BadFileDescriptor;
        FUN_00c01e67(0, 0, 0, 0, 0);
        return -1;
    }
    valid = !!(DAT_0117a660[fd >> 5][fd & 31].osFlags & FileOpen);
    if (!valid) {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = BadFileDescriptor;
        FUN_00c01e67(0, 0, 0, 0, 0);
        return -1;
    }

    int result;
    FUN_00c1d471(fd);
    __try {
        if (DAT_0117a660[fd >> 5][fd & 31].osFlags & FileOpen) {
            result = FUN_00c17470(fd, buffer, count);
        } else {
            *FUN_00c02a76() = BadFileDescriptor;
            *FUN_00c02a89() = 0;
            result = -1;
        }
    }
    __finally {
        FUN_00c1d511(fd);
    }
    return result;
}
}   // namespace f3m_00c17a36

// @f3 0x00c164ab (community match, verified in this file)
namespace f3m_00c164ab {
namespace f3m_00c164ab {
struct LockEntry { void* lock; int kind; };
struct CritSect { void* debugInfo; long lockCount; long recursionCount; void* owningThread; void* lockSemaphore; unsigned long spinCount; };
extern "C" LockEntry DAT_0106bcc0[36];
extern "C" CritSect DAT_0117a330[];
extern "C" int __cdecl FUN_00c173ab(void* cs, unsigned long spin);
// pdb: _mtinitlocks | mlock.obj | fnv360_0822_retail, caller_sim, high
extern "C" int __cdecl FUN_00c164ab(void)
{
    int locknum;
    int idxPrealloc = 0;
    for (locknum = 0; locknum < 36; locknum++) {
        if (DAT_0106bcc0[locknum].kind == 1) {
            DAT_0106bcc0[locknum].lock = &DAT_0117a330[idxPrealloc++];
            if (!FUN_00c173ab(DAT_0106bcc0[locknum].lock, 4000)) {
                DAT_0106bcc0[locknum].lock = 0;
                return 0;
            }
        }
    }
    return 1;
}
}
}   // namespace f3m_00c164ab

// @f3 0x00c09c9a (community match, verified in this file)
namespace f3m_00c09c9a {
namespace f3m_00c09c9a {
struct ThrowInfo { unsigned int attributes; void* pmfnUnwind; };
struct EHExceptionRecord {
    unsigned long ExceptionCode;
    unsigned long ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned long NumberParameters;
    unsigned long magicNumber;
    void* pExceptionObject;
    ThrowInfo* pThrowInfo;
};
extern "C" void __stdcall FUN_00bffdf5(void* pthis, void* pmfn);
extern "C" __declspec(noreturn) void __cdecl FUN_00c0c4e6(void);
// pdb: __DestructExceptionObject | frame.obj | tesv_win, call_seq, medium
extern "C" void __cdecl FUN_00c09c9a(EHExceptionRecord* pExcept, unsigned char fThrowNotAllowed)
{
    if (pExcept != 0 && pExcept->ExceptionCode == 0xe06d7363 && pExcept->pThrowInfo != 0 && pExcept->pThrowInfo->pmfnUnwind != 0) {
        __try {
            FUN_00bffdf5(pExcept->pExceptionObject, pExcept->pThrowInfo->pmfnUnwind);
        }
        __except (fThrowNotAllowed ? 1 : 0) {
            FUN_00c0c4e6();
        }
    }
}
}
}   // namespace f3m_00c09c9a

// @f3 0x00c0a0f0 (community match, verified in this file)
namespace f3m_00c0a0f0 {
namespace f3m_00c0a0f0 {
struct HandlerType { unsigned int adjectives; void* pType; int dispCatchObj; void* addressOfHandler; };
struct PMD { int mdisp; int pdisp; int vdisp; };
struct CatchableType { unsigned int properties; void* pType; PMD thisDisplacement; int sizeOrOffset; void* copyFunction; };
struct EHExceptionRecord {
    unsigned long ExceptionCode;
    unsigned long ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned long NumberParameters;
    unsigned long magicNumber;
    void* pExceptionObject;
    void* pThrowInfo;
};
extern "C" int __cdecl FUN_00c09f71(EHExceptionRecord* pExcept, void* pRN, HandlerType* pCatch, CatchableType* pConv);
extern "C" void* __cdecl FUN_00c09cee(void* pThis, const PMD& pmd);
void __stdcall FUN_00bffdf5(void* pthis, void* pmfn, void* pthat);
void __stdcall FUN_00bffdf5(void* pthis, void* pmfn, void* pthat, int val2);
extern "C" __declspec(noreturn) void __cdecl FUN_00c0c4e6(void);
// pdb: __BuildCatchObject | frame.obj | tesv_win, call_gap, low
extern "C" void __cdecl FUN_00c0a0f0(EHExceptionRecord* pExcept, void* pRN, HandlerType* pCatch, CatchableType* pConv)
{
    void** pCatchBuffer;
    if (pCatch->adjectives & 0x80000000)
        pCatchBuffer = (void**)pRN;
    else
        pCatchBuffer = (void**)((char*)pRN + 0xc + pCatch->dispCatchObj);
    __try {
        switch (FUN_00c09f71(pExcept, pRN, pCatch, pConv)) {
        case 1:
            FUN_00bffdf5((char*)pCatchBuffer, pConv->copyFunction, FUN_00c09cee(pExcept->pExceptionObject, pConv->thisDisplacement));
            break;
        case 2:
            FUN_00bffdf5((char*)pCatchBuffer, pConv->copyFunction, FUN_00c09cee(pExcept->pExceptionObject, pConv->thisDisplacement), 1);
            break;
        default:
            break;
        }
    }
    __except (1) {
        FUN_00c0c4e6();
    }
}
}
}   // namespace f3m_00c0a0f0

// @f3 0x00c08ec6 (community match, verified in this file)
namespace f3m_00c08ec6 {
namespace f3m_00c08ec6 {
struct LocInfo { int refcount; };
struct MbcInfo { long refcount; };
struct LocaleStruct { LocInfo* locinfo; MbcInfo* mbcinfo; };
extern "C" LocInfo DAT_0106b7b8;
extern "C" MbcInfo DAT_0106b288;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void __cdecl FUN_00c064b8(void* p);
extern "C" void __cdecl FUN_00c08d0f(LocInfo* p);
extern "C" void __cdecl FUN_00c08b49(LocInfo* p);
// pdb: _free_locale | setlocal.obj | tesv_win, uconst, low
extern "C" void __cdecl FUN_00c08ec6(LocaleStruct* plocinfo)
{
    if (plocinfo != 0) {
        if (plocinfo->mbcinfo != 0 && InterlockedDecrement(&plocinfo->mbcinfo->refcount) == 0 && plocinfo->mbcinfo != &DAT_0106b288)
            FUN_00c064b8(plocinfo->mbcinfo);
        if (plocinfo->locinfo != 0) {
            FUN_00c16621(12);
            __try {
                FUN_00c08d0f(plocinfo->locinfo);
                if (plocinfo->locinfo != 0 && plocinfo->locinfo->refcount == 0 && plocinfo->locinfo != &DAT_0106b7b8)
                    FUN_00c08b49(plocinfo->locinfo);
            }
            __finally {
                FUN_00c16549(12);
            }
        }
        plocinfo->locinfo = (LocInfo*)0xbaadf00d;
        plocinfo->mbcinfo = (MbcInfo*)0xbaadf00d;
        FUN_00c064b8(plocinfo);
    }
}
}
}   // namespace f3m_00c08ec6

// @f3 0x00c064b8 (community match, verified in this file)
extern "C" int DAT_0117a640;
extern "C" void* DAT_0117a32c;
namespace f3m_00c064b8 {
namespace f3m_00c064b8 {
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(void);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void* __cdecl FUN_00c1669a(void* pBlock);
extern "C" void __cdecl FUN_00c166c5(void* pHeader, void* pBlock);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" int __cdecl FUN_00c02a3b(unsigned long oserr);
// pdb: free | free.obj | fnv360_0822_retail, call_seq, low
// pdb params: pBlock
extern "C" void __cdecl FUN_00c064b8(void* pBlock)
{
    int retval = 0;
    if (pBlock == 0)
        return;
    if (DAT_0117a640 == 3) {
        void* pHeader;
        FUN_00c16621(4);
        __try {
            if ((pHeader = FUN_00c1669a(pBlock)) != 0)
                FUN_00c166c5(pHeader, pBlock);
        }
        __finally {
            FUN_00c16549(4);
        }
        if (pHeader == 0) {
            retval = HeapFree(DAT_0117a32c, 0, pBlock);
            if (retval == 0)
                *FUN_00c02a76() = FUN_00c02a3b(GetLastError());
        }
    } else {
        retval = HeapFree(DAT_0117a32c, 0, pBlock);
        if (retval == 0)
            *FUN_00c02a76() = FUN_00c02a3b(GetLastError());
    }
}
}
}   // namespace f3m_00c064b8

// @f3 0x00c067da (community match, verified in this file)
extern "C" int DAT_0117a640;
extern "C" void* DAT_0117a32c;
namespace f3m_00c067da {
namespace f3m_00c067da {
struct Entry { int sizeFront; };
extern "C" __declspec(dllimport) unsigned long __stdcall HeapSize(void* hHeap, unsigned long dwFlags, const void* lpMem);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void* __cdecl FUN_00c1669a(void* pBlock);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
// pdb: _msize | msize.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pblock
extern "C" unsigned int __cdecl FUN_00c067da(void* pblock)
{
    unsigned int retval;
    {
        int _Expr_val = !!(pblock != 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return (unsigned int)-1;
        }
    }
    if (DAT_0117a640 == 3) {
        void* pHeader;
        FUN_00c16621(4);
        __try {
            if ((pHeader = FUN_00c1669a(pblock)) != 0)
                retval = (unsigned int)(((Entry*)((char*)pblock - sizeof(int)))->sizeFront - 0x9);
        }
        __finally {
            FUN_00c16549(4);
        }
        if (pHeader == 0)
            retval = (unsigned int)HeapSize(DAT_0117a32c, 0, pblock);
    } else {
        retval = (unsigned int)HeapSize(DAT_0117a32c, 0, pblock);
    }
    return retval;
}
}
}   // namespace f3m_00c067da

// @f3 0x00c0ce55 (community match, verified in this file)
namespace f3m_00c0ce55 {
namespace f3m_00c0ce55 {
struct MbcInfo { long refcount; };
struct Tiddata {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    MbcInfo* ptmbcinfo;
    void* ptlocinfo;
    int _ownlocale;
};
extern "C" MbcInfo* DAT_0106b6b0;
extern "C" int DAT_0106b7a8;
extern "C" MbcInfo DAT_0106b288;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" Tiddata* __cdecl FUN_00c0c229(void);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void __cdecl FUN_00c064b8(void* p);
extern "C" void __cdecl FUN_00c0687d(int code);
// pdb: __updatetmbcinfo | mbctype.obj | tesv_win, hash, low
extern "C" MbcInfo* __cdecl FUN_00c0ce55(void)
{
    MbcInfo* ptmbci;
    Tiddata* ptd = FUN_00c0c229();
    if (!(ptd->_ownlocale & DAT_0106b7a8) || !ptd->ptlocinfo) {
        FUN_00c16621(13);
        __try {
            if ((ptmbci = ptd->ptmbcinfo) != DAT_0106b6b0) {
                if (ptmbci != 0 && InterlockedDecrement(&ptmbci->refcount) == 0 && ptmbci != &DAT_0106b288)
                    FUN_00c064b8(ptmbci);
                ptd->ptmbcinfo = DAT_0106b6b0;
                ptmbci = DAT_0106b6b0;
                InterlockedIncrement(&ptmbci->refcount);
            }
        }
        __finally {
            FUN_00c16549(13);
        }
    } else {
        ptmbci = ptd->ptmbcinfo;
    }
    if (!ptmbci)
        FUN_00c0687d(32);
    return ptmbci;
}
}
}   // namespace f3m_00c0ce55

// @f3 0x00c0c0f3 (community match, verified in this file)
namespace f3m_00c0c0f3 {
namespace f3m_00c0c0f3 {
struct MbcInfo { long refcount; };
struct Tiddata {
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned long _holdrand;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    void* _pxcptacttab;
    int unk60, unk64;
    MbcInfo* ptmbcinfo;
    void* ptlocinfo;
    int _ownlocale;
    int unk74;
    char unk78[0x50];
    char _cachein[0x83];
    char _cacheout[0xad];
    void* _encode_ptr;
    void* _decode_ptr;
};
extern "C" char DAT_0106bc30[];
extern "C" MbcInfo DAT_0106b288;
extern "C" void* DAT_0106b890;
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* name);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* h, const char* name);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" int __cdecl FUN_00c0bf2a(void);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void __cdecl FUN_00c08c89(void* p);
// pdb: free | free.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: _initptd)
// pdb params: pBlock
extern "C" void __cdecl FUN_00c0c0f3(Tiddata* ptd, void* ptloci)
{
    void* hKernel32 = GetModuleHandleA("KERNEL32.DLL");
    ptd->_pxcptacttab = (void*)DAT_0106bc30;
    ptd->_holdrand = 1L;
    if (hKernel32 != 0 && FUN_00c0bf2a()) {
        ptd->_encode_ptr = GetProcAddress(hKernel32, "EncodePointer");
        ptd->_decode_ptr = GetProcAddress(hKernel32, "DecodePointer");
    }
    ptd->_ownlocale = 1;
    ptd->_cachein[0] = 'C';
    ptd->_cacheout[0] = 'C';
    ptd->ptmbcinfo = &DAT_0106b288;
    InterlockedIncrement(&(ptd->ptmbcinfo->refcount));
    FUN_00c16621(12);
    __try {
        ptd->ptlocinfo = ptloci;
        if (ptd->ptlocinfo == 0)
            ptd->ptlocinfo = DAT_0106b890;
        FUN_00c08c89(ptd->ptlocinfo);
    }
    __finally {
        FUN_00c16549(12);
    }
}
}
}   // namespace f3m_00c0c0f3

// @f3 0x00c07983 (community match, verified in this file)
extern "C" int DAT_0117b780;
extern "C" void** DAT_0117a770;
namespace f3m_00c07983 {
namespace f3m_00c07983 {
struct FILE_ { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; };
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void __cdecl FUN_00c07bcc(int i, void* s);
extern "C" void __cdecl FUN_00c07c30(int i, void* s);
extern "C" int __cdecl FUN_00c07941(void* s);
// pdb: flsall | fflush.obj | fnv360_0822_retail, call_gap_sim, low
extern "C" int __cdecl FUN_00c07983(int flushflag)
{
    int i;
    int count = 0;
    int err = 0;
    FUN_00c16621(1);
    __try {
        for (i = 0; i < DAT_0117b780; i++) {
            if ((DAT_0117a770[i] != 0) && (((FILE_*)DAT_0117a770[i])->_flag & 0x83)) {
                FUN_00c07bcc(i, DAT_0117a770[i]);
                __try {
                    if (((FILE_*)DAT_0117a770[i])->_flag & 0x83) {
                        if (flushflag == 1) {
                            if (FUN_00c07941(DAT_0117a770[i]) != -1)
                                count++;
                        }
                        else if ((flushflag == 0) && (((FILE_*)DAT_0117a770[i])->_flag & 2)) {
                            if (FUN_00c07941(DAT_0117a770[i]) == -1)
                                err = -1;
                        }
                    }
                }
                __finally {
                    FUN_00c07c30(i, DAT_0117a770[i]);
                }
            }
        }
    }
    __finally {
        FUN_00c16549(1);
    }
    if (flushflag == 1)
        return (count);
    else
        return (err);
}
}
}   // namespace f3m_00c07983

// @f3 0x00c18242 (community match, verified in this file)
namespace f3m_00c18242 {
namespace f3m_00c18242 {
struct ioinfo {
    long osfhnd;
    unsigned char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode;
    char unk25, unk26, unk27;
    unsigned unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" unsigned int DAT_0117a644;
extern "C" unsigned long* __cdecl FUN_00c02a89(void);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" long __cdecl FUN_00c181d0(int fh, long pos, int mthd);
extern "C" int __cdecl FUN_00c1d471(int fh);
extern "C" void __cdecl FUN_00c1d511(int fh);
// pdb: _lseek | lseek.obj | fnv360_0822_retail, call_seq, high
// pdb params: fh, pos, mthd
extern "C" long __cdecl FUN_00c18242(int fh, long pos, int mthd)
{
    long r;
    if (fh == -2) {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = 9;
        return -1;
    }
    {
        int _Expr_val = !!(fh >= 0 && (unsigned)fh < DAT_0117a644);
        if (!(_Expr_val)) {
            *FUN_00c02a89() = 0;
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    {
        int _Expr_val = !!(DAT_0117a660[fh >> 5][fh & 31].osfile & 1);
        if (!(_Expr_val)) {
            *FUN_00c02a89() = 0;
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    FUN_00c1d471(fh);
    __try {
        if (DAT_0117a660[fh >> 5][fh & 31].osfile & 1)
            r = FUN_00c181d0(fh, pos, mthd);
        else {
            *FUN_00c02a76() = 9;
            *FUN_00c02a89() = 0;
            r = -1;
        }
    }
    __finally {
        FUN_00c1d511(fh);
    }
    return r;
}
}
}   // namespace f3m_00c18242

// @f3 0x00c18480 (community match, verified in this file)
namespace f3m_00c18480 {
namespace f3m_00c18480 {
struct ioinfo {
    long osfhnd;
    unsigned char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode;
    char unk25, unk26, unk27;
    unsigned unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" unsigned int DAT_0117a644;
extern "C" unsigned long* __cdecl FUN_00c02a89(void);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" long __cdecl FUN_00c1d400(int fh);
extern "C" __declspec(dllimport) int __stdcall FlushFileBuffers(void* h);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(void);
extern "C" int __cdecl FUN_00c1d471(int fh);
extern "C" void __cdecl FUN_00c1d511(int fh);
// pdb: _commit | commit.obj | fnv360_0822_retail, call_seq, high
// pdb params: filedes
extern "C" int __cdecl FUN_00c18480(int filedes)
{
    int retval;
    if (filedes == -2) {
        *FUN_00c02a76() = 9;
        return -1;
    }
    {
        int _Expr_val = !!(filedes >= 0 && (unsigned)filedes < DAT_0117a644);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    {
        int _Expr_val = !!(DAT_0117a660[filedes >> 5][filedes & 31].osfile & 1);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    FUN_00c1d471(filedes);
    __try {
        if (DAT_0117a660[filedes >> 5][filedes & 31].osfile & 1) {
            if (!FlushFileBuffers((void*)FUN_00c1d400(filedes))) {
                retval = GetLastError();
            } else {
                retval = 0;
            }
            if (retval == 0)
                goto good;
            *FUN_00c02a89() = retval;
        }
        *FUN_00c02a76() = 9;
        retval = -1;
good:
        ;
    }
    __finally {
        FUN_00c1d511(filedes);
    }
    return (retval);
}
}
}   // namespace f3m_00c18480

// @f3 0x00c180d3 (community match, verified in this file)
namespace f3m_00c180d3 {
namespace f3m_00c180d3 {
struct ioinfo {
    long osfhnd;
    unsigned char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode;
    char unk25, unk26, unk27;
    unsigned unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" unsigned int DAT_0117a644;
extern "C" unsigned long* __cdecl FUN_00c02a89(void);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00c17b12(int fh, void* buf, unsigned cnt);
extern "C" int __cdecl FUN_00c1d471(int fh);
extern "C" void __cdecl FUN_00c1d511(int fh);
// pdb: _read | read.obj | fnv360_0822_retail, call_seq, high
// pdb params: fh, buf, cnt
extern "C" int __cdecl FUN_00c180d3(int fh, void* buf, unsigned cnt)
{
    int r;
    if (fh == -2) {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = 9;
        return -1;
    }
    {
        int _Expr_val = !!(fh >= 0 && (unsigned)fh < DAT_0117a644);
        if (!(_Expr_val)) {
            *FUN_00c02a89() = 0;
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    {
        int _Expr_val = !!(DAT_0117a660[fh >> 5][fh & 31].osfile & 1);
        if (!(_Expr_val)) {
            *FUN_00c02a89() = 0;
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    {
        int _Expr_val = !!(cnt <= 0x7fffffff);
        if (!(_Expr_val)) {
            *FUN_00c02a89() = 0;
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    FUN_00c1d471(fh);
    __try {
        if (DAT_0117a660[fh >> 5][fh & 31].osfile & 1)
            r = FUN_00c17b12(fh, buf, cnt);
        else {
            *FUN_00c02a76() = 9;
            *FUN_00c02a89() = 0;
            r = -1;
        }
    }
    __finally {
        FUN_00c1d511(fh);
    }
    return r;
}
}
}   // namespace f3m_00c180d3

// @f3 0x00c1831e (community match, verified in this file)
extern "C" int DAT_0117a640;
extern "C" unsigned int DAT_0117a630;
extern "C" void* DAT_0117a32c;
extern "C" int DAT_0117a488;
namespace f3m_00c1831e {
namespace f3m_00c1831e {
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned long dwBytes);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void* __cdecl FUN_00c16e6e(int size);
extern "C" void* __cdecl FUN_00c00610(void* dst, int val, unsigned int count);
extern "C" int __cdecl FUN_00c1715b(unsigned int size);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
// pdb: _calloc_impl | calloc_impl.obj | fnv360_0822_retail, caller, medium
// pdb params: num, size, errno_tmp
extern "C" void* __cdecl FUN_00c1831e(unsigned int num, unsigned int size, int* errno_tmp)
{
    unsigned int size_orig;
    void* pvReturn;
    if (num > 0) {
        int _Expr_val = !!((0xFFFFFFE0 / num) >= size);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 12;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }
    size_orig = size = size * num;
    if (size == 0)
        size = 1;
    for (;;) {
        pvReturn = 0;
        if (size <= 0xFFFFFFE0) {
            if (DAT_0117a640 == 3) {
                if (size <= 0xFFFFFFE0)
                    size = (size + 16 - 1) & ~(16 - 1);
                if (size_orig <= DAT_0117a630) {
                    FUN_00c16621(4);
                    __try {
                        pvReturn = FUN_00c16e6e((int)size_orig);
                    }
                    __finally {
                        FUN_00c16549(4);
                    }
                    if (pvReturn != 0)
                        FUN_00c00610(pvReturn, 0, size_orig);
                }
            }
            if (pvReturn == 0)
                pvReturn = HeapAlloc(DAT_0117a32c, 8, size);
        }
        if (pvReturn || DAT_0117a488 == 0) {
            if (pvReturn == 0) {
                if (errno_tmp)
                    *errno_tmp = 12;
            }
            return pvReturn;
        }
        if (!FUN_00c1715b(size)) {
            if (errno_tmp)
                *errno_tmp = 12;
            return 0;
        }
    }
}
}
}   // namespace f3m_00c1831e

// @f3 0x00c12da8 (community match, verified in this file)
extern "C" int DAT_0117b780;
extern "C" void** DAT_0117a770;
namespace f3m_00c12da8 {
namespace f3m_00c12da8 {
struct FILE_ { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; };
struct CritSect { void* debugInfo; long lockCount; long recursionCount; void* owningThread; void* lockSemaphore; unsigned long spinCount; };
struct FILEX { FILE_ f; CritSect lock; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSect* cs);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" int __cdecl FUN_00c1655e(int locknum);
extern "C" void __cdecl FUN_00c07bcc(int i, void* s);
extern "C" void __cdecl FUN_00c07c30(int i, void* s);
extern "C" void* __cdecl FUN_00c0ab3f(unsigned int size);
extern "C" int __cdecl FUN_00c173ab(void* cs, unsigned long spin);
extern "C" void __cdecl FUN_00c064b8(void* p);
// pdb: _getstream | stream.obj | fnv360_0822_retail, call_gap_sim, high
extern "C" FILE_* __cdecl FUN_00c12da8(void)
{
    FILE_* retval = 0;
    int i;
    FUN_00c16621(1);
    __try {
        for (i = 0; i < DAT_0117b780; i++) {
            if (DAT_0117a770[i] != 0) {
                if (!(((FILE_*)DAT_0117a770[i])->_flag & 0x83) && !(((FILE_*)DAT_0117a770[i])->_flag & 0x8000)) {
                    if (i > 2 && i < 20)
                        if (!FUN_00c1655e(16 + i))
                            break;
                    FUN_00c07bcc(i, DAT_0117a770[i]);
                    if (((FILE_*)DAT_0117a770[i])->_flag & 0x83) {
                        FUN_00c07c30(i, DAT_0117a770[i]);
                        continue;
                    }
                    retval = (FILE_*)DAT_0117a770[i];
                    break;
                }
            }
            else {
                if ((DAT_0117a770[i] = FUN_00c0ab3f(sizeof(FILEX))) != 0) {
                    if (!FUN_00c173ab(&(((FILEX*)DAT_0117a770[i])->lock), 4000)) {
                        FUN_00c064b8(DAT_0117a770[i]);
                        DAT_0117a770[i] = 0;
                        break;
                    }
                    EnterCriticalSection(&(((FILEX*)DAT_0117a770[i])->lock));
                    retval = (FILE_*)DAT_0117a770[i];
                }
                break;
            }
        }
        if (retval != 0) {
            retval->_flag &= 0x8000;
            retval->_cnt = 0;
            retval->_tmpfname = retval->_ptr = retval->_base = 0;
            retval->_file = -1;
        }
    }
    __finally {
        FUN_00c16549(1);
    }
    return (retval);
}
}
}   // namespace f3m_00c12da8

// @f3 0x00c03bca (community match, verified in this file)
namespace f3m_00c03bca {

namespace f3m_00c03bca {
struct FILE_ { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; };
struct ioinfo {
    long osfhnd;
    char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode : 7;
    char unicode : 1;
    char pipech2[2];
    int unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" ioinfo DAT_0106bbf0;
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00c07b90(FILE_* stream);
extern "C" void __cdecl FUN_00c07bfa(FILE_* stream);
extern "C" int __cdecl FUN_00c1294e(FILE_* stream);
extern "C" int __cdecl FUN_00c12649(FILE_* stream);
extern "C" void __cdecl FUN_00c126df(int flag, FILE_* stream);
extern "C" int __cdecl FUN_00c0d55e(FILE_* stream, const char* format, void* plocinfo, va_list ap);
// pdb: fprintf | fprintf.obj | tesv_win, caller_sim, low
extern "C" int __cdecl FUN_00c03bca(FILE_* str, const char* format, ...)
{
    va_list arglist;
    FILE_* stream;
    int buffing;
    int retval = 0;
    {
        int _Expr_val = !!(str != 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    {
        int _Expr_val = !!(format != 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    va_start(arglist, format);
    stream = str;
    FUN_00c07b90(stream);
    __try {
            {
                FILE_* _Stream = stream;
                int _Expr_val = !!((_Stream->_flag & 0x40) ||
                    ((((FUN_00c1294e(_Stream) != -1 && FUN_00c1294e(_Stream) != -2) ? (DAT_0117a660[FUN_00c1294e(_Stream) >> 5] + (FUN_00c1294e(_Stream) & 31)) : &DAT_0106bbf0)->textmode == 0) &&
                     !(((FUN_00c1294e(_Stream) != -1 && FUN_00c1294e(_Stream) != -2) ? (DAT_0117a660[FUN_00c1294e(_Stream) >> 5] + (FUN_00c1294e(_Stream) & 31)) : &DAT_0106bbf0)->unicode)));
                if (!(_Expr_val)) {
                    *FUN_00c02a76() = 22;
                    FUN_00c01e67(0, 0, 0, 0, 0);
                    retval = (-1);
                }
            }
        if (retval == 0) {
            buffing = FUN_00c12649(stream);
            retval = FUN_00c0d55e(stream, format, 0, arglist);
            FUN_00c126df(buffing, stream);
        }
    }
    __finally {
        FUN_00c07bfa(stream);
    }
    return (retval);
}
}
}   // namespace f3m_00c03bca

// @f3 0x00c09f71 (community match, verified in this file)
namespace f3m_00c09f71 {
namespace f3m_00c09f71 {
struct TypeDescriptor { const void* pVFTable; void* spare; char name[1]; };
struct HandlerType { unsigned int adjectives; TypeDescriptor* pType; int dispCatchObj; void* addressOfHandler; };
struct PMD { int mdisp; int pdisp; int vdisp; };
struct CatchableType { unsigned int properties; void* pType; PMD thisDisplacement; int sizeOrOffset; void* copyFunction; };
struct EHExceptionRecord {
    unsigned long ExceptionCode;
    unsigned long ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned long NumberParameters;
    unsigned long magicNumber;
    void* pExceptionObject;
    void* pThrowInfo;
};
typedef int (__stdcall* FARPROC_)();
int __cdecl FUN_00c1b6ed(const void* data, unsigned int size);
int __cdecl FUN_00c1b6ed(FARPROC_ code);
extern "C" void* __cdecl FUN_00c09cee(void* pThis, const PMD& pmd);
extern "C" void* __cdecl FUN_00c01530(void* dst, const void* src, unsigned int count);
extern "C" void __cdecl FUN_00c0c532(void);
extern "C" __declspec(noreturn) void __cdecl FUN_00c0c4e6(void);
// pdb: __BuildCatchObjectHelper | frame.obj | fnv360_0822_retail, caller_sim, high
// pdb params: pExcept, pRN, pCatch, pConv
extern "C" int __cdecl FUN_00c09f71(EHExceptionRecord* pExcept, void* pRN, HandlerType* pCatch, CatchableType* pConv)
{
    int retval = 0;
    if ((!pCatch->pType || !pCatch->pType->name[0]) ||
        (!pCatch->dispCatchObj && !(pCatch->adjectives & 0x80000000))) {
        return 0;
    }
    void** pCatchBuffer;
    if (pCatch->adjectives & 0x80000000)
        pCatchBuffer = (void**)pRN;
    else
        pCatchBuffer = (void**)((char*)pRN + 0xc + pCatch->dispCatchObj);
    __try {
        if (pCatch->adjectives & 8) {
            if (FUN_00c1b6ed(pExcept->pExceptionObject, 1) && FUN_00c1b6ed(pCatchBuffer, 1)) {
                *pCatchBuffer = pExcept->pExceptionObject;
                *pCatchBuffer = FUN_00c09cee(*pCatchBuffer, pConv->thisDisplacement);
            } else {
                FUN_00c0c532();
            }
        } else if (pConv->properties & 1) {
            if (FUN_00c1b6ed(pExcept->pExceptionObject, 1) && FUN_00c1b6ed(pCatchBuffer, 1)) {
                FUN_00c01530(pCatchBuffer, pExcept->pExceptionObject, pConv->sizeOrOffset);
                if (pConv->sizeOrOffset == sizeof(void*) && *pCatchBuffer != 0) {
                    *pCatchBuffer = FUN_00c09cee(*pCatchBuffer, pConv->thisDisplacement);
                }
            } else {
                FUN_00c0c532();
            }
        } else {
            if (pConv->copyFunction == 0) {
                if (FUN_00c1b6ed(pExcept->pExceptionObject, 1) && FUN_00c1b6ed(pCatchBuffer, 1)) {
                    FUN_00c01530(pCatchBuffer, FUN_00c09cee(pExcept->pExceptionObject, pConv->thisDisplacement), pConv->sizeOrOffset);
                } else {
                    FUN_00c0c532();
                }
            } else {
                if (FUN_00c1b6ed(pExcept->pExceptionObject, 1) && FUN_00c1b6ed(pCatchBuffer, 1) && FUN_00c1b6ed((FARPROC_)pConv->copyFunction)) {
                    retval = (pConv->properties & 4) ? 2 : 1;
                } else {
                    FUN_00c0c532();
                }
            }
        }
    }
    __except (1) {
        FUN_00c0c4e6();
    }
    return retval;
}
}
}   // namespace f3m_00c09f71

// @f3 0x00c05a70 (community match, verified in this file)
namespace f3m_00c05a70 {
namespace f3m_00c05a70 {
struct FILE_ { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; };
struct ioinfo {
    long osfhnd;
    char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode : 7;
    char unicode : 1;
    char pipech2[2];
    int unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" ioinfo DAT_0106bbf0;
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00c07b90(FILE_* stream);
extern "C" void __cdecl FUN_00c07bfa(FILE_* stream);
extern "C" int __cdecl FUN_00c1294e(FILE_* stream);
extern "C" int __cdecl FUN_00c15880(FILE_* stream);
// pdb: fgets | fgets.obj | fnv360_0822_retail, call_gap, medium
// pdb params: string, count, str
extern "C" char* __cdecl FUN_00c05a70(char* string, int count, FILE_* str)
{
    FILE_* stream;
    char* pointer = string;
    char* retval = string;
    int ch;
    {
        int _Expr_val = !!((string != 0) || (count == 0));
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }
    {
        int _Expr_val = !!(count >= 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }
    {
        int _Expr_val = !!(str != 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }
    if (count == 0) {
        return 0;
    }
    stream = str;
    FUN_00c07b90(stream);
    __try {
            {
                FILE_* _Stream = stream;
                int _Expr_val = !!((_Stream->_flag & 0x40) ||
                    ((((FUN_00c1294e(_Stream) != -1 && FUN_00c1294e(_Stream) != -2) ? (DAT_0117a660[FUN_00c1294e(_Stream) >> 5] + (FUN_00c1294e(_Stream) & 31)) : &DAT_0106bbf0)->textmode == 0) &&
                     !(((FUN_00c1294e(_Stream) != -1 && FUN_00c1294e(_Stream) != -2) ? (DAT_0117a660[FUN_00c1294e(_Stream) >> 5] + (FUN_00c1294e(_Stream) & 31)) : &DAT_0106bbf0)->unicode)));
                if (!(_Expr_val)) {
                    *FUN_00c02a76() = 22;
                    FUN_00c01e67(0, 0, 0, 0, 0);
                    retval = (0);
                }
            }
        if (retval != 0) {
            while (--count) {
                if ((ch = (--(stream)->_cnt >= 0 ? 0xff & *(stream)->_ptr++ : FUN_00c15880(stream))) == -1) {
                    if (pointer == string) {
                        retval = 0;
                        goto done;
                    }
                    break;
                }
                if ((*pointer++ = (char)ch) == '\n')
                    break;
            }
            *pointer = '\0';
        }
done: ;
    }
    __finally {
        FUN_00c07bfa(stream);
    }
    return (retval);
}
}
}   // namespace f3m_00c05a70

// @f3 0x00c1d533 (community match, verified in this file)
namespace f3m_00c1d533 {
namespace f3m_00c1d533 {
struct CritSect { void* debugInfo; long lockCount; long recursionCount; void* owningThread; void* lockSemaphore; unsigned long spinCount; };
struct ioinfo {
    long osfhnd;
    char osfile;
    char pipech;
    int lockinitflag;
    CritSect lock;
    char textmode : 7;
    char unicode : 1;
    char pipech2[2];
    int unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[64];
extern "C" int DAT_0117a644;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSect* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSect* cs);
extern "C" int __cdecl FUN_00c1655e(int locknum);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" int __cdecl FUN_00c173ab(void* cs, unsigned long spin);
extern "C" void* __cdecl FUN_00c0ab7f(unsigned int num, unsigned int size);
extern "C" int __cdecl FUN_00c1d471(int fh);
// pdb: _alloc_osfhnd | osfinfo.obj | fnv360_0822_retail, caller_sim, high
extern "C" int __cdecl FUN_00c1d533(void)
{
    int fh = -1;
    int i;
    ioinfo* pio;
    int failed = 0;

    if (!FUN_00c1655e(11))
        return -1;

    FUN_00c16621(11);
    __try {
        for (i = 0; i < 64; i++) {
            if (DAT_0117a660[i] != 0) {
                for (pio = DAT_0117a660[i]; pio < DAT_0117a660[i] + 32; pio++) {
                    if (!(pio->osfile & 1)) {
                        if (pio->lockinitflag == 0) {
                            FUN_00c16621(10);
                            __try {
                                if (pio->lockinitflag == 0) {
                                    if (!FUN_00c173ab(&(pio->lock), 4000)) {
                                        failed = 1;
                                    } else {
                                        pio->lockinitflag++;
                                    }
                                }
                            }
                            __finally {
                                FUN_00c16549(10);
                            }
                        }
                        if (!failed) {
                            EnterCriticalSection(&(pio->lock));
                            if (pio->osfile & 1) {
                                LeaveCriticalSection(&(pio->lock));
                                continue;
                            }
                        }
                        if (!failed) {
                            pio->osfile = 1;
                            pio->osfhnd = -1;
                            fh = i * 32 + (int)(pio - DAT_0117a660[i]);
                            break;
                        }
                    }
                }
                if (fh != -1)
                    break;
            }
            else {
                if ((pio = (ioinfo*)FUN_00c0ab7f(32, sizeof(ioinfo))) != 0) {
                    DAT_0117a660[i] = pio;
                    DAT_0117a644 += 32;
                    for (; pio < DAT_0117a660[i] + 32; pio++) {
                        pio->osfile = 0;
                        pio->osfhnd = -1;
                        pio->pipech = 10;
                        pio->lockinitflag = 0;
                    }
                    fh = i * 32;
                    DAT_0117a660[fh >> 5][fh & 31].osfile = 1;
                    if (!FUN_00c1d471(fh)) {
                        fh = -1;
                    }
                }
                break;
            }
        }
    }
    __finally {
        FUN_00c16549(11);
    }
    return (fh);
}
}
}   // namespace f3m_00c1d533

// @f3 0x00c05def (community match, verified in this file)
extern "C" char __ImageBase;
extern "C" unsigned int DAT_01179b18;
extern "C" unsigned int DAT_01179b20;
extern "C" unsigned int DAT_01179b24;
extern "C" unsigned int DAT_01179b28;
extern "C" unsigned int DAT_01179b1c;
extern "C" char* DAT_0117b798;
extern "C" char* DAT_01179b08;
namespace f3m_00c05def {
extern "C" unsigned long __cdecl _exception_code(void);
extern "C" void* __cdecl _exception_info(void);
namespace f3m_00c05def {
struct OSVERSIONINFOA_ {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};
struct STARTUPINFOA_ {
    unsigned long cb;
    char* lpReserved;
    char* lpDesktop;
    char* lpTitle;
    unsigned long dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute, dwFlags;
    unsigned short wShowWindow;
    unsigned short cbReserved2;
    unsigned char* lpReserved2;
    void* hStdInput;
    void* hStdOutput;
    void* hStdError;
};
struct EXCEPTION_POINTERS_ { void* ExceptionRecord; void* ContextRecord; };
}
namespace f3m_00c05def {
extern "C" __declspec(dllimport) void __stdcall GetStartupInfoA(STARTUPINFOA_* si);
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap(void);
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned long dwBytes);
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(OSVERSIONINFOA_* vi);
extern "C" __declspec(dllimport) char* __stdcall GetCommandLineA(void);
extern "C" void __cdecl FUN_00c05d8a(int rterrnum);
extern "C" int __cdecl FUN_00c05dae(void);
extern "C" int __cdecl FUN_00c160ab(int mtflag);
extern "C" int __cdecl FUN_00c0c362(void);
extern "C" void __cdecl FUN_00c16008(void);
extern "C" int __cdecl FUN_00c1270e(void);
extern "C" void __cdecl FUN_00c0687d(int rterrnum);
extern "C" char* __cdecl FUN_00c15ed3(void);
extern "C" int __cdecl FUN_00c15e1a(void);
extern "C" int __cdecl FUN_00c15ba7(void);
extern "C" int __cdecl FUN_00c06999(int initFloatingPrecision);
extern "C" char* __cdecl FUN_00c15b4a(void);
extern "C" int __stdcall FUN_006ee300(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nCmdShow);
extern "C" __declspec(noreturn) void __cdecl FUN_00c06b0d(int code);
extern "C" void __cdecl FUN_00c06b2f(void);
extern "C" __declspec(noreturn) void __cdecl FUN_00c06b1e(int code);
extern "C" void __cdecl FUN_00c06b3e(void);
extern "C" int __cdecl FUN_00c159ec(unsigned long xcptnum, EXCEPTION_POINTERS_* pxcptinfoptrs);
// pdb: __tmainCRTStartup | wincrt0.obj | tesv_win, udata, high
extern "C" __declspec(noinline) int __cdecl FUN_00c05def(void)
{
    int initret;
    int mainret = 0;
    OSVERSIONINFOA_* posvi;
    int managedapp;
    char* lpszCommandLine;
    STARTUPINFOA_ StartupInfo;
    unsigned int osplatform, winmajor, winminor, osver, winver;

    __try {
        GetStartupInfoA(&StartupInfo);
    } __except (1) {
        return 255;
    }

    posvi = (OSVERSIONINFOA_*)HeapAlloc(GetProcessHeap(), 0, sizeof(OSVERSIONINFOA_));
    if (posvi == 0) {
        FUN_00c05d8a(18);
        return 255;
    }
    posvi->dwOSVersionInfoSize = sizeof(OSVERSIONINFOA_);
    if (!GetVersionExA(posvi)) {
        HeapFree(GetProcessHeap(), 0, posvi);
        return 255;
    }
    osplatform = posvi->dwPlatformId;
    winmajor = posvi->dwMajorVersion;
    winminor = posvi->dwMinorVersion;
    osver = (posvi->dwBuildNumber) & 0x07fff;
    HeapFree(GetProcessHeap(), 0, posvi);
    if (osplatform != 2)
        osver |= 0x08000;
    winver = (winmajor << 8) + winminor;

    DAT_01179b18 = osplatform;
    DAT_01179b20 = winver;
    DAT_01179b24 = winmajor;
    DAT_01179b28 = winminor;
    DAT_01179b1c = osver;

    managedapp = FUN_00c05dae();

    if (!FUN_00c160ab(1))
        FUN_00c05d8a(28);
    if (!FUN_00c0c362())
        FUN_00c05d8a(16);

    FUN_00c16008();

    __try {
        if (FUN_00c1270e() < 0)
            FUN_00c0687d(27);
        DAT_0117b798 = GetCommandLineA();
        DAT_01179b08 = FUN_00c15ed3();
        if (FUN_00c15e1a() < 0)
            FUN_00c0687d(8);
        if (FUN_00c15ba7() < 0)
            FUN_00c0687d(9);
        initret = FUN_00c06999(1);
        if (initret != 0)
            FUN_00c0687d(initret);
        lpszCommandLine = FUN_00c15b4a();
        mainret = FUN_006ee300((void*)&__ImageBase, 0, lpszCommandLine,
                               StartupInfo.dwFlags & 1 ? StartupInfo.wShowWindow : 10);
        if (!managedapp)
            FUN_00c06b0d(mainret);
        FUN_00c06b2f();
    }
    __except (FUN_00c159ec(_exception_code(), (EXCEPTION_POINTERS_*)_exception_info())) {
        mainret = _exception_code();
        if (!managedapp)
            FUN_00c06b1e(mainret);
        FUN_00c06b3e();
    }
    return mainret;
}
}
}   // namespace f3m_00c05def

// @f3 0x00c171d7 (community match, verified in this file)
namespace f3m_00c171d7 {
namespace f3m_00c171d7 {
typedef void (__cdecl* _PHNDLR)(int);
struct XCPT_ACTION { unsigned long XcptNum; int SigNum; _PHNDLR XcptAction; };
struct Tiddata {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    XCPT_ACTION* _pxcptacttab;
    void* _tpxcptinfoptrs;
    int _tfpecode;
};
extern "C" _PHNDLR DAT_0117a48c;
extern "C" _PHNDLR DAT_0117a490;
extern "C" _PHNDLR DAT_0117a494;
extern "C" _PHNDLR DAT_0117a498;
extern "C" int DAT_0106bcb4;
extern "C" int DAT_0106bca8;
extern "C" int DAT_0106bcac;
extern "C" Tiddata* __cdecl FUN_00c0c1b2(void);
extern "C" void* __cdecl FUN_00c0c00d(void* p);
extern "C" void* __cdecl FUN_00c0c004(void);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" __declspec(noreturn) void __cdecl FUN_00c06b1e(int code);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);

static __declspec(noinline) XCPT_ACTION* __cdecl FUN_00c17196(int signum, XCPT_ACTION* pxcptacttab)
{
    XCPT_ACTION* pxcptact = pxcptacttab;
    while ((pxcptact->SigNum != signum) && (++pxcptact < pxcptacttab + DAT_0106bcb4))
        ;
    if ((pxcptact < (pxcptacttab + DAT_0106bcb4)) && (pxcptact->SigNum == signum))
        return (pxcptact);
    else
        return (0);
}

// pdb: raise | winsig.obj | fnv360_0822_debug, call_seq, medium
// pdb params: signum
extern "C" int __cdecl FUN_00c171d7(int signum)
{
    _PHNDLR sigact;
    _PHNDLR* psigact;
    void* oldpxcptinfoptrs;
    int oldfpecode;
    int indx;
    int siglock = 0;
    Tiddata* ptd = 0;

    switch (signum) {
    case 2: sigact = *(psigact = &DAT_0117a48c); siglock++; goto global;
    case 21: sigact = *(psigact = &DAT_0117a490); siglock++; goto global;
    case 22:
    case 6: sigact = *(psigact = &DAT_0117a494); siglock++; goto global;
    case 15: sigact = *(psigact = &DAT_0117a498); siglock++;
    global:
        sigact = (_PHNDLR)FUN_00c0c00d((void*)sigact);
        break;
    case 8:
    case 4:
    case 11:
        ptd = FUN_00c0c1b2();
        if (ptd == 0)
            return (-1);
        sigact = *(psigact = &(FUN_00c17196(signum, ptd->_pxcptacttab)->XcptAction));
        break;
    default:
        {
            int _Expr_val = !!(0);
            if (!(_Expr_val)) {
                *FUN_00c02a76() = 22;
                FUN_00c01e67(0, 0, 0, 0, 0);
                return -1;
            }
        }
    }

    if (sigact == (_PHNDLR)1)
        return (0);

    if (sigact == (_PHNDLR)0) {
        FUN_00c06b1e(3);
    }

    if (siglock)
        FUN_00c16621(0);

    __try {
        if ((signum == 8) || (signum == 11) || (signum == 4)) {
            oldpxcptinfoptrs = ptd->_tpxcptinfoptrs;
            ptd->_tpxcptinfoptrs = 0;
            if (signum == 8) {
                oldfpecode = ptd->_tfpecode;
                ptd->_tfpecode = 0x8c;
            }
        }
        if (signum == 8)
            for (indx = DAT_0106bca8; indx < DAT_0106bca8 + DAT_0106bcac; indx++) {
                (ptd->_pxcptacttab + indx)->XcptAction = (_PHNDLR)0;
            }
        else
            *psigact = (_PHNDLR)FUN_00c0c004();
    }
    __finally {
        if (siglock)
            FUN_00c16549(0);
    }

    if (signum == 8)
        (*(void (__cdecl*)(int, int))sigact)(8, ptd->_tfpecode);
    else
        (*sigact)(signum);

    if ((signum == 8) || (signum == 11) || (signum == 4)) {
        ptd->_tpxcptinfoptrs = oldpxcptinfoptrs;
        if (signum == 8)
            ptd->_tfpecode = oldfpecode;
    }
    return (0);
}
}
}   // namespace f3m_00c171d7

// @f3 0x00c0d14c (community match, verified in this file)
namespace f3m_00c0d14c {
namespace f3m_00c0d14c {
struct MbcInfo {
    long refcount;
    int mbcodepage;
    int ismbcodepage;
    int mblcid;
    unsigned short mbulinfo[6];
    unsigned char mbctype[257];
    unsigned char mbcasemap[256];
    unsigned char pad[3];
};
struct LocInfo { int refcount; unsigned int lc_codepage; };
struct LocaleStruct { LocInfo* locinfo; MbcInfo* mbcinfo; };
struct Tiddata {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    MbcInfo* ptmbcinfo;
    LocInfo* ptlocinfo;
    int _ownlocale;
};
class _LocaleUpdate {
    LocaleStruct localeinfo;
    Tiddata* ptd;
    bool updated;
public:
    _LocaleUpdate(LocaleStruct* plocinfo);
    ~_LocaleUpdate() { if (updated) ptd->_ownlocale &= ~2; }
    LocaleStruct* GetLocaleT() { return &localeinfo; }
};
extern "C" int DAT_0117a1d8;
extern "C" int DAT_0117a1e8;
extern "C" int DAT_0117a1ec;
extern "C" int DAT_0117a1f0;
extern "C" unsigned short DAT_0117a1dc[5];
extern "C" unsigned char DAT_0106b4a8[257];
extern "C" unsigned char DAT_0106b5b0[256];
extern "C" MbcInfo* DAT_0106b6b0;
extern "C" MbcInfo DAT_0106b288;
extern "C" int DAT_0106b7a8;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) unsigned int __stdcall GetOEMCP(void);
extern "C" __declspec(dllimport) unsigned int __stdcall GetACP(void);
extern "C" Tiddata* __cdecl FUN_00c0c229(void);
extern "C" MbcInfo* __cdecl FUN_00c0ce55(void);
extern "C" void* __cdecl FUN_00c0ab3f(unsigned int size);
extern "C" void __cdecl FUN_00c064b8(void* p);
extern "C" int __cdecl FUN_00c0cf73(int codepage, MbcInfo* ptmbci);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" int* __cdecl FUN_00c02a76(void);

static __declspec(noinline) int __cdecl FUN_00c0cef9(int codepage)
{
    _LocaleUpdate _loc_update(0);
    DAT_0117a1d8 = 0;
    if (codepage == -2) {
        DAT_0117a1d8 = 1;
        return GetOEMCP();
    }
    else if (codepage == -3) {
        DAT_0117a1d8 = 1;
        return GetACP();
    }
    else if (codepage == -4) {
        DAT_0117a1d8 = 1;
        return _loc_update.GetLocaleT()->locinfo->lc_codepage;
    }
    return codepage;
}

// pdb: _setmbcp | mbctype.obj | tesv_win, hash, low
extern "C" int __cdecl FUN_00c0d14c(int codepage)
{
    int retcode = -1;
    MbcInfo* ptmbci;
    int i;
    Tiddata* ptd = FUN_00c0c229();

    FUN_00c0ce55();
    ptmbci = ptd->ptmbcinfo;

    codepage = FUN_00c0cef9(codepage);

    if (codepage != ptmbci->mbcodepage) {
        ptmbci = (MbcInfo*)FUN_00c0ab3f(sizeof(MbcInfo));
        if (ptmbci != 0) {
            *ptmbci = *(ptd->ptmbcinfo);
            ptmbci->refcount = 0;
            if ((retcode = FUN_00c0cf73(codepage, ptmbci)) == 0) {
                if (!InterlockedDecrement(&ptd->ptmbcinfo->refcount) && ptd->ptmbcinfo != &DAT_0106b288)
                    FUN_00c064b8(ptd->ptmbcinfo);
                ptd->ptmbcinfo = ptmbci;
                InterlockedIncrement(&(ptd->ptmbcinfo->refcount));
                if (!(ptd->_ownlocale & 2) && !(DAT_0106b7a8 & 1)) {
                    FUN_00c16621(13);
                    __try {
                        DAT_0117a1e8 = ptmbci->mbcodepage;
                        DAT_0117a1ec = ptmbci->ismbcodepage;
                        DAT_0117a1f0 = ptmbci->mblcid;
                        for (i = 0; i < 5; i++)
                            DAT_0117a1dc[i] = ptmbci->mbulinfo[i];
                        for (i = 0; i < 257; i++)
                            DAT_0106b4a8[i] = ptmbci->mbctype[i];
                        for (i = 0; i < 256; i++)
                            DAT_0106b5b0[i] = ptmbci->mbcasemap[i];
                        if (!InterlockedDecrement(&DAT_0106b6b0->refcount) && DAT_0106b6b0 != &DAT_0106b288)
                            FUN_00c064b8(DAT_0106b6b0);
                        DAT_0106b6b0 = ptmbci;
                        InterlockedIncrement(&(ptmbci->refcount));
                    }
                    __finally {
                        FUN_00c16549(13);
                    }
                }
            }
            else if (retcode == -1) {
                if (ptmbci != &DAT_0106b288)
                    FUN_00c064b8(ptmbci);
                *FUN_00c02a76() = 22;
            }
        }
    }
    else
        retcode = 0;

    return retcode;
}
}
}   // namespace f3m_00c0d14c

// @f3 0x00c1de2b (community match, verified in this file)
namespace f3m_00c1de2b {
namespace f3m_00c1de2b {
struct ioinfo {
    long osfhnd;
    char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode;
    char pipech2[3];
    int unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00c1d511(int fh);
extern "C" int __cdecl FUN_00c1d533(void);
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned long, unsigned long, void*, unsigned long, unsigned long, void*);

static __declspec(noinline) int __cdecl FUN_00c1d6d2(int* punlock_flag, int* pfh, const char* path, int oflag, int shflag, int pmode, int bSecure)
{
    *pfh = -1;
    *pfh = FUN_00c1d533();
    if (*pfh == -1) {
        *FUN_00c02a76() = 24;
        return 24;
    }
    *punlock_flag = 1;
    if (CreateFileA(path, oflag, shflag, 0, pmode, *pfh, 0) == (void*)-1) {
        DAT_0117a660[*pfh >> 5][*pfh & 31].osfile = 0;
        return 13;
    }
    DAT_0117a660[*pfh >> 5][*pfh & 31].osfile = 1;
    return 0;
}

// pdb: _sopen_helper | open.obj | fnv360_0822_retail, call_seq, high
// pdb params: path, oflag, shflag, pmode, pfh, bSecure
extern "C" int __cdecl FUN_00c1de2b(const char* path, int oflag, int shflag, int pmode, int* pfh, int bSecure)
{
    int retval;
    int unlock_flag = 0;

    {
        int _Expr_val = !!(pfh != 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 22;
        }
    }
    *pfh = -1;
    {
        int _Expr_val = !!(path != 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 22;
        }
    }
    if (bSecure) {
        int _Expr_val = !!((pmode & (~(0x0100 | 0x0080))) == 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 22;
        }
    }
    __try {
        retval = FUN_00c1d6d2(&unlock_flag, pfh, path, oflag, shflag, pmode, bSecure);
    }
    __finally {
        if (unlock_flag) {
            if (retval) {
                DAT_0117a660[*pfh >> 5][*pfh & 31].osfile &= ~1;
            }
            FUN_00c1d511(*pfh);
        }
    }
    if (retval != 0) {
        *pfh = -1;
    }
    return retval;
}
}
}   // namespace f3m_00c1de2b

// @f3 0x00c1cad2 (community match, verified in this file)
namespace f3m_00c1cad2 {
namespace f3m_00c1cad2 {
struct SYSTEMTIME_ { unsigned short wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds; };
struct TIME_ZONE_INFORMATION_ {
    long Bias;
    wchar_t StandardName[32];
    SYSTEMTIME_ StandardDate;
    long StandardBias;
    wchar_t DaylightName[32];
    SYSTEMTIME_ DaylightDate;
    long DaylightBias;
};
extern "C" TIME_ZONE_INFORMATION_ DAT_0117a510;
extern "C" int DAT_0117a5bc;
extern "C" int DAT_0106c090;
extern "C" int DAT_0106c084;
extern "C" char* DAT_0117a5c0;
extern "C" __declspec(dllimport) unsigned long __stdcall GetTimeZoneInformation(TIME_ZONE_INFORMATION_* tzi);
extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int cp, unsigned long flags, const wchar_t* wide, int cchWide, char* mb, int cbMb, const char* defChar, int* usedDef);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" char** __cdecl FUN_00c1d2fc(void);
extern "C" int __cdecl FUN_00c1d2b6(long* p);
extern "C" int __cdecl FUN_00c1d24e(int* p);
extern "C" int __cdecl FUN_00c1d282(long* p);
extern "C" void __cdecl FUN_00c01d6b(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" unsigned int __cdecl FUN_00c08afd(void);
extern "C" char* __cdecl FUN_00c1fa48(const char* name);
extern "C" int __cdecl FUN_00c0c740(const char* a, const char* b);
extern "C" void __cdecl FUN_00c064b8(void* p);
extern "C" unsigned int __cdecl FUN_00c08660(const char* s);
extern "C" void* __cdecl FUN_00c0ab3f(unsigned int size);
extern "C" int __cdecl FUN_00c007fc(char* dst, unsigned int size, const char* src);
extern "C" int __cdecl FUN_00c0388a(char* dst, unsigned int size, const char* src, unsigned int count);
extern "C" long __cdecl FUN_00c047cd(const char* s);
extern "C" long* __cdecl FUN_00c1d2f6(void);
extern "C" int* __cdecl FUN_00c1d2ea(void);
extern "C" long* __cdecl FUN_00c1d2f0(void);

static __forceinline void SetTimezone(long v) { *FUN_00c1d2f6() = v; }
static __forceinline void SetDaylight(int v) { *FUN_00c1d2ea() = v; }
static __forceinline void SetDstbias(long v) { *FUN_00c1d2f0() = v; }

// pdb: _tzset_nolock | tzset.obj | tesv_win, call_seq, medium
extern "C" void __cdecl FUN_00c1cad2(void)
{
    char* TZ;
    int defused;
    int negdiff = 0;
    unsigned int lc_cp;
    int done = 0;
    long timezone = 0;
    int daylight = 0;
    long dstbias = 0;
    char** tzname = 0;

    FUN_00c16621(7);
    __try {
        tzname = FUN_00c1d2fc();
        { int _Expr_val = (int)(FUN_00c1d2b6(&timezone)); if ((_Expr_val) != 0) { FUN_00c01d6b(0, 0, 0, 0, 0); } }
        { int _Expr_val = (int)(FUN_00c1d24e(&daylight)); if ((_Expr_val) != 0) { FUN_00c01d6b(0, 0, 0, 0, 0); } }
        { int _Expr_val = (int)(FUN_00c1d282(&dstbias)); if ((_Expr_val) != 0) { FUN_00c01d6b(0, 0, 0, 0, 0); } }

        lc_cp = FUN_00c08afd();
        DAT_0117a5bc = 0;
        DAT_0106c090 = DAT_0106c084 = -1;

        if (((TZ = FUN_00c1fa48("TZ")) == 0) || (*TZ == '\0')) {
            if (DAT_0117a5c0 != 0) {
                FUN_00c064b8(DAT_0117a5c0);
                DAT_0117a5c0 = 0;
            }
            if (GetTimeZoneInformation(&DAT_0117a510) != 0xFFFFFFFF) {
                DAT_0117a5bc = 1;
                timezone = DAT_0117a510.Bias * 60;
                if (DAT_0117a510.StandardDate.wMonth != 0)
                    timezone += (DAT_0117a510.StandardBias * 60);
                if ((DAT_0117a510.DaylightDate.wMonth != 0) && (DAT_0117a510.DaylightBias != 0)) {
                    daylight = 1;
                    dstbias = (DAT_0117a510.DaylightBias - DAT_0117a510.StandardBias) * 60;
                }
                else {
                    daylight = 0;
                    dstbias = 0;
                }
                if ((WideCharToMultiByte(lc_cp, 0, DAT_0117a510.StandardName, -1, tzname[0], 64 - 1, 0, &defused) != 0) && (!defused))
                    tzname[0][64 - 1] = '\0';
                else
                    tzname[0][0] = '\0';
                if ((WideCharToMultiByte(lc_cp, 0, DAT_0117a510.DaylightName, -1, tzname[1], 64 - 1, 0, &defused) != 0) && (!defused))
                    tzname[1][64 - 1] = '\0';
                else
                    tzname[1][0] = '\0';
            }
            done = 1;
        }
        else {
            if ((DAT_0117a5c0 != 0) && (FUN_00c0c740(TZ, DAT_0117a5c0) == 0)) {
                done = 1;
            }
            else {
                if (DAT_0117a5c0 != 0)
                    FUN_00c064b8(DAT_0117a5c0);
                if ((DAT_0117a5c0 = (char*)FUN_00c0ab3f(FUN_00c08660(TZ) + 1)) == 0) {
                    done = 1;
                }
                else {
                    { int _Expr_val = (int)(FUN_00c007fc(DAT_0117a5c0, FUN_00c08660(TZ) + 1, TZ)); if ((_Expr_val) != 0) { FUN_00c01d6b(0, 0, 0, 0, 0); } }
                }
            }
        }
        SetTimezone(timezone);
        SetDaylight(daylight);
        SetDstbias(dstbias);
    }
    __finally {
        FUN_00c16549(7);
    }

    if (done)
        return;

    { int _Expr_val = (int)(FUN_00c0388a(tzname[0], 64, TZ, 3)); if ((_Expr_val) != 0) { FUN_00c01d6b(0, 0, 0, 0, 0); } }

    if (*(TZ += 3) == '-') {
        negdiff++;
        TZ++;
    }
    timezone = FUN_00c047cd(TZ) * 3600;
    while ((*TZ == '+') || ((*TZ >= '0') && (*TZ <= '9'))) TZ++;
    if (*TZ == ':') {
        timezone += FUN_00c047cd(++TZ) * 60;
        while ((*TZ >= '0') && (*TZ <= '9')) TZ++;
        if (*TZ == ':') {
            timezone += FUN_00c047cd(++TZ);
            while ((*TZ >= '0') && (*TZ <= '9')) TZ++;
        }
    }
    if (negdiff)
        timezone = -timezone;
    if ((daylight = *TZ) != 0) {
        { int _Expr_val = (int)(FUN_00c0388a(tzname[1], 64, TZ, 3)); if ((_Expr_val) != 0) { FUN_00c01d6b(0, 0, 0, 0, 0); } }
    }
    else
        *tzname[1] = '\0';
    SetTimezone(timezone);
    SetDaylight(daylight);
}
}
}   // namespace f3m_00c1cad2

// @f3 0x00c0c241 (community match, verified in this file)
namespace f3m_00c0c241 {
namespace f3m_00c0c241 {
struct MbcInfo { long refcount; };
struct LocInfo { int refcount; };
struct Tiddata {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    char* _errmsg;
    int unk28;
    char* _namebuf0;
    int unk30;
    char* _namebuf1;
    int unk38;
    char* _asctimebuf;
    int unk40;
    char* _wasctimebuf;
    char* _gmtimebuf;
    int unk4C, unk50, unk54, unk58;
    void* _pxcptacttab;
    int unk60, unk64;
    MbcInfo* ptmbcinfo;
    LocInfo* ptlocinfo;
};
extern "C" char DAT_0106bc30[];
extern "C" MbcInfo DAT_0106b288;
extern "C" LocInfo* DAT_0106b890;
extern "C" LocInfo DAT_0106b7b8;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" void __cdecl FUN_00c064b8(void* p);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void __cdecl FUN_00c08d0f(LocInfo* p);
extern "C" void __cdecl FUN_00c08b49(LocInfo* p);
// pdb: _tzset_nolock | tzset.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: _freefls)
extern "C" void __stdcall FUN_00c0c241(void* data)
{
    Tiddata* ptd;
    LocInfo* ptloci;
    MbcInfo* ptmbci;

    ptd = (Tiddata*)data;
    if (ptd != 0) {
        if (ptd->_errmsg) FUN_00c064b8((void*)ptd->_errmsg);
        if (ptd->_namebuf0) FUN_00c064b8((void*)ptd->_namebuf0);
        if (ptd->_namebuf1) FUN_00c064b8((void*)ptd->_namebuf1);
        if (ptd->_asctimebuf) FUN_00c064b8((void*)ptd->_asctimebuf);
        if (ptd->_wasctimebuf) FUN_00c064b8((void*)ptd->_wasctimebuf);
        if (ptd->_gmtimebuf) FUN_00c064b8((void*)ptd->_gmtimebuf);
        if (ptd->_pxcptacttab != (void*)DAT_0106bc30) FUN_00c064b8((void*)ptd->_pxcptacttab);

        FUN_00c16621(13);
        __try {
            if (((ptmbci = ptd->ptmbcinfo) != 0) &&
                (InterlockedDecrement(&(ptmbci->refcount)) == 0) &&
                (ptmbci != &DAT_0106b288))
                FUN_00c064b8(ptmbci);
        }
        __finally {
            FUN_00c16549(13);
        }

        FUN_00c16621(12);
        __try {
            if ((ptloci = ptd->ptlocinfo) != 0) {
                FUN_00c08d0f(ptloci);
                if ((ptloci != DAT_0106b890) &&
                    (ptloci != &DAT_0106b7b8) &&
                    (ptloci->refcount == 0))
                    FUN_00c08b49(ptloci);
            }
        }
        __finally {
            FUN_00c16549(12);
        }
        FUN_00c064b8((void*)ptd);
    }
}
}
}   // namespace f3m_00c0c241

// @f3 0x00c09937 (community match, verified in this file)
namespace f3m_00c09937 {
namespace f3m_00c09937 {
struct LocInfo {
    int refcount;
    unsigned int lc_codepage;
    unsigned int lc_collate_cp;
    unsigned long lc_handle[6];
    char rest[0xd8 - 0x24];
};
struct Tiddata {
    int unk00[0x6c / 4];
    LocInfo* ptlocinfo;
    int _ownlocale;
};
extern "C" LocInfo* DAT_0106b890;
extern "C" int DAT_0106b7a8;
extern "C" int DAT_01179b64;
extern "C" unsigned long DAT_0117a1f4[6];
extern "C" char DAT_0106b7b0[];
extern "C" LocInfo DAT_0106b7b8;
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" Tiddata* __cdecl FUN_00c0c229(void);
extern "C" void __cdecl FUN_00c08dfd(void);
extern "C" void* __cdecl FUN_00c0ab7f(unsigned int count, unsigned int size);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void __cdecl FUN_00c08c89(LocInfo* p);
extern "C" void __cdecl FUN_00c08d0f(LocInfo* p);
extern "C" void __cdecl FUN_00c08b49(LocInfo* p);
extern "C" int __cdecl FUN_00c0c740(const char* a, const char* b);
extern "C" void* __cdecl FUN_00bffa60(void* d, const void* s, unsigned int n);
extern "C" void __cdecl FUN_00c08e73(void);

static __declspec(noinline) void __cdecl FUN_00c08d9b(LocInfo* ptlocid, LocInfo* ptlocis)
{
    if (ptlocis != 0 && ptlocid != 0 && ptlocid != ptlocis) {
        *ptlocid = *ptlocis;
        ptlocid->refcount = 0;
        FUN_00c08c89(ptlocid);
    }
}

static __declspec(noinline) LocInfo* __cdecl FUN_00c08dbf(LocInfo** pptlocid, LocInfo* ptlocis)
{
    LocInfo* ptloci;
    if (ptlocis == 0 || pptlocid == 0)
        return 0;
    ptloci = *pptlocid;
    if (ptloci != ptlocis) {
        *pptlocid = ptlocis;
        FUN_00c08c89(ptlocis);
        if (ptloci != 0) {
            FUN_00c08d0f(ptloci);
            if (ptloci->refcount == 0 && ptloci != &DAT_0106b7b8)
                FUN_00c08b49(ptloci);
        }
    }
    return ptlocis;
}

extern "C" char* __cdecl SetCategory(LocInfo* ploci, int category, const char* locale);
extern "C" char* __cdecl SetAll(LocInfo* ploci, const char* locale);
extern "C" char* __cdecl SetCatP(LocInfo* ploci, int* category, const char* locale);
static __declspec(noinline) char* __cdecl FUN_00c09769(LocInfo* ploci, int _category, const char* _locale)
{
    char* retval;
    if (_category != 0) {
        if (_locale == 0)
            retval = (char*)ploci->lc_handle[_category];
        else
            retval = SetCatP(ploci, &_category, _locale);
    } else {
        if (_locale == 0)
            return 0;
        retval = SetAll(ploci, _locale);
    }
    ploci->refcount = 0;
    {
        char* p;
        for (p = retval; *p; p++)
            SetAll(0, p);
    }
    return retval;
}

// pdb: setlocale | setlocal.obj | tesv_win, hash, low
extern "C" char* __cdecl FUN_00c09937(int _category, const char* _locale)
{
    char* retval = 0;
    Tiddata* ptd;
    LocInfo* ptloci = 0;

    {
        int _Expr_val = !!(0 <= _category && _category <= 5);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }

    ptd = FUN_00c0c229();
    FUN_00c08dfd();
    ptd->_ownlocale |= 0x10;

    __try {
        if ((ptloci = (LocInfo*)FUN_00c0ab7f(sizeof(LocInfo), 1)) != 0) {
            FUN_00c16621(12);
            __try {
                FUN_00c08d9b(ptloci, ptd->ptlocinfo);
            }
            __finally {
                FUN_00c16549(12);
            }

            if ((retval = FUN_00c09769(ptloci, _category, _locale)) != 0) {
                if (_locale != 0 && FUN_00c0c740(_locale, DAT_0106b7b0) != 0) {
                    DAT_01179b64 = 1;
                }

                FUN_00c16621(12);
                __try {
                    (void)FUN_00c08dbf(&ptd->ptlocinfo, ptloci);
                    FUN_00c08d0f(ptloci);
                    if (!(ptd->_ownlocale & 2) && !(DAT_0106b7a8 & 1)) {
                        (void)FUN_00c08dbf(&DAT_0106b890, ptd->ptlocinfo);
                        FUN_00bffa60((void*)DAT_0117a1f4, (void*)DAT_0106b890->lc_handle, sizeof(DAT_0117a1f4));
                        FUN_00c08e73();
                    }
                }
                __finally {
                    FUN_00c16549(12);
                }
            } else {
                FUN_00c08d0f(ptloci);
                FUN_00c08b49(ptloci);
            }
        }
    }
    __finally {
        ptd->_ownlocale &= ~0x10;
    }

    return retval;
}
}
}   // namespace f3m_00c09937

// @f3 0x00c06546 (community match, verified in this file)
extern "C" int DAT_0117a640;
extern "C" unsigned int DAT_0117a630;
extern "C" void* DAT_0117a32c;
extern "C" int DAT_0117a488;
namespace f3m_00c06546 {
namespace f3m_00c06546 {
struct Entry { int sizeFront; };
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned long dwBytes);
extern "C" __declspec(dllimport) void* __stdcall HeapReAlloc(void* hHeap, unsigned long dwFlags, void* lpMem, unsigned long dwBytes);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(void);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" void* __cdecl FUN_00c063f5(unsigned int size);
extern "C" void __cdecl FUN_00c064b8(void* p);
extern "C" void* __cdecl FUN_00c1669a(void* pBlock);
extern "C" int __cdecl FUN_00c16b8f(void* pHeader, void* pBlock, int newsize);
extern "C" void* __cdecl FUN_00c16e6e(int size);
extern "C" void __cdecl FUN_00c166c5(void* pHeader, void* pBlock);
extern "C" void* __cdecl FUN_00bffa60(void* d, const void* s, unsigned int n);
extern "C" int __cdecl FUN_00c1715b(unsigned int size);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" int __cdecl FUN_00c02a3b(unsigned long oserr);
// pdb: realloc | realloc.obj | fnv360_0721_beta, call_gap, medium
// pdb params: pBlock, newsize
extern "C" void* __cdecl FUN_00c06546(void* pBlock, unsigned int newsize)
{
    void* pvReturn;

    if (pBlock == 0)
        return FUN_00c063f5(newsize);

    if (newsize == 0) {
        FUN_00c064b8(pBlock);
        return 0;
    }

    if (DAT_0117a640 == 3) {
        void* pHeader;
        unsigned int oldsize;

        for (;;) {
            pvReturn = 0;
            if (newsize <= 0xFFFFFFE0) {
                FUN_00c16621(4);
                __try {
                    if ((pHeader = FUN_00c1669a(pBlock)) != 0) {
                        if (newsize <= DAT_0117a630) {
                            if (FUN_00c16b8f(pHeader, pBlock, (int)newsize))
                                pvReturn = pBlock;
                            else if ((pvReturn = FUN_00c16e6e((int)newsize)) != 0) {
                                oldsize = ((Entry*)((char*)pBlock - sizeof(int)))->sizeFront - 1;
                                FUN_00bffa60(pvReturn, pBlock, (oldsize < newsize) ? oldsize : newsize);
                                pHeader = FUN_00c1669a(pBlock);
                                FUN_00c166c5(pHeader, pBlock);
                            }
                        }
                        if (pvReturn == 0) {
                            if (newsize == 0)
                                newsize = 1;
                            newsize = (newsize + 16 - 1) & ~(16 - 1);
                            if ((pvReturn = HeapAlloc(DAT_0117a32c, 0, newsize)) != 0) {
                                oldsize = ((Entry*)((char*)pBlock - sizeof(int)))->sizeFront - 1;
                                FUN_00bffa60(pvReturn, pBlock, (oldsize < newsize) ? oldsize : newsize);
                                FUN_00c166c5(pHeader, pBlock);
                            }
                        }
                    }
                }
                __finally {
                    FUN_00c16549(4);
                }

                if (pHeader == 0) {
                    if (newsize == 0)
                        newsize = 1;
                    newsize = (newsize + 16 - 1) & ~(16 - 1);
                    pvReturn = HeapReAlloc(DAT_0117a32c, 0, pBlock, newsize);
                }
            }
            else {
                FUN_00c1715b(newsize);
                *FUN_00c02a76() = 12;
                return 0;
            }

            if (pvReturn || DAT_0117a488 == 0) {
                if (pvReturn) {
                }
                else {
                    if (pHeader == 0)
                        *FUN_00c02a76() = FUN_00c02a3b(GetLastError());
                    else
                        *FUN_00c02a76() = 12;
                }
                return pvReturn;
            }

            if (!FUN_00c1715b(newsize)) {
                if (pHeader == 0)
                    *FUN_00c02a76() = FUN_00c02a3b(GetLastError());
                else
                    *FUN_00c02a76() = 12;
                return 0;
            }
        }
    }
    else {
        for (;;) {
            pvReturn = 0;
            if (newsize <= 0xFFFFFFE0) {
                if (newsize == 0)
                    newsize = 1;
                pvReturn = HeapReAlloc(DAT_0117a32c, 0, pBlock, newsize);
            }
            else {
                FUN_00c1715b(newsize);
                *FUN_00c02a76() = 12;
                return 0;
            }

            if (pvReturn || DAT_0117a488 == 0) {
                if (pvReturn) {
                }
                else {
                    *FUN_00c02a76() = FUN_00c02a3b(GetLastError());
                }
                return pvReturn;
            }

            if (!FUN_00c1715b(newsize)) {
                *FUN_00c02a76() = FUN_00c02a3b(GetLastError());
                return 0;
            }
        }
    }
}
}
}   // namespace f3m_00c06546

// @f3 0x00c1d471 (community match, verified in this file)
namespace f3m_00c1d471 {
namespace f3m_00c1d471 {
struct ioinfo {
    long osfhnd;
    unsigned char osfile;
    char pipech;
    int lockinitflag;
    char lock[24];
    char textmode;
    char unk25, unk26, unk27;
    unsigned unk28, unk2c, unk30, unk34;
};
extern "C" ioinfo* DAT_0117a660[];
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" void __cdecl FUN_00c16621(int locknum);
extern "C" void __cdecl FUN_00c16549(int locknum);
extern "C" int __cdecl FUN_00c173ab(void* lpCriticalSection, unsigned long dwSpinCount);
// pdb: __lock_fhandle | osfinfo.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: fh
extern "C" int __cdecl FUN_00c1d471(int fh)
{
    ioinfo* pio = &DAT_0117a660[fh >> 5][fh & 31];
    int retval = 1;

    if (pio->lockinitflag == 0) {
        FUN_00c16621(10);
        __try {
            if (pio->lockinitflag == 0) {
                if (!FUN_00c173ab(&(pio->lock), 4000)) {
                    retval = 0;
                }
                pio->lockinitflag++;
            }
        }
        __finally {
            FUN_00c16549(10);
        }
    }

    if (retval) {
        EnterCriticalSection(&(DAT_0117a660[fh >> 5][fh & 31].lock));
    }

    return retval;
}
}
}   // namespace f3m_00c1d471
