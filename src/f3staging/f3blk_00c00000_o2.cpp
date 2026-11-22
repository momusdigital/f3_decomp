#include <stdio.h>
#include <windows.h>
// src/f3staging/f3blk_00c00000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"



// @f3 0x00c068dc (community match, verified in this file)
namespace f3m_00c068dc {
void __cdecl FUN_00c16621(int code);
// pdb: _lockexit | crt0dat.obj | fnv360_0822_retail, caller_sim, low
void FUN_00c068dc() { FUN_00c16621(8); }
}   // namespace f3m_00c068dc

// @f3 0x00c0afff (community match, verified in this file)
namespace f3m_00c0afff {
int __cdecl FUN_00c0aee7(void* value, int mode);
// pdb: _cropzeros | cvt.obj | tesv_win, caller_sim, low
int __cdecl FUN_00c0afff(void* value)
{
    return FUN_00c0aee7(value, 0);
}
}   // namespace f3m_00c0afff

// @f3 0x00c0468a (community match, verified in this file)
namespace f3m_00c0468a {
int __cdecl FUN_00c045e1(void* value, int mode);
int __cdecl FUN_00c0468a(void* value)
{
    return FUN_00c045e1(value, 0);
}
}   // namespace f3m_00c0468a

// @f3 0x00c03d8b (community match, verified in this file)
namespace f3m_00c03d8b {
namespace c00c03d8b {
struct FILE_ { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; };
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00c07b90(FILE_* stream);
extern "C" int __cdecl FUN_00c03d19(FILE_* stream);
extern "C" void __cdecl FUN_00c07bfa(FILE_* stream);
// pdb: fclose | fclose.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: stream
extern "C" int __cdecl FUN_00c03d8b(FILE_* stream)
{
    int result = -1;
    int valid = !!(stream != 0);
    if (!valid) {
        *FUN_00c02a76() = 22;
        FUN_00c01e67(0, 0, 0, 0, 0);
        return -1;
    }
    if (stream->_flag & 0x40) {
        stream->_flag = 0;
    } else {
        FUN_00c07b90(stream);
        __try {
            result = FUN_00c03d19(stream);
        }
        __finally {
            FUN_00c07bfa(stream);
        }
    }
    return result;
}
}
}   // namespace f3m_00c03d8b

// @f3 0x00c058e0 (community match, verified in this file)
namespace f3m_00c058e0 {
namespace c00c058e0 {
struct FILE_ { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; };
typedef int (__cdecl* OUTPUTFN)(FILE_*, const char*, void*, char*);
extern "C" FILE_* __cdecl FUN_00c07ab9(void);
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00c07b90(FILE_* stream);
extern "C" void __cdecl FUN_00c07bfa(FILE_* stream);
extern "C" int __cdecl FUN_00c12649(FILE_* stream);
extern "C" void __cdecl FUN_00c126df(int flag, FILE_* stream);
// pdb: vprintf_helper | vprintf.obj | fnv360_0822_retail, caller_sim, low
// pdb params: outfn, format, plocinfo, ap
extern "C" int __cdecl FUN_00c058e0(OUTPUTFN outfn, const char* format, void* plocinfo, char* ap)
{
    FILE_* stream = &FUN_00c07ab9()[1];
    int buffing;
    int retval;
    int valid = !!(format != 0);
    if (!valid) {
        *FUN_00c02a76() = 22;
        FUN_00c01e67(0, 0, 0, 0, 0);
        return -1;
    }
    FUN_00c07b90(stream);
    __try {
        buffing = FUN_00c12649(stream);
        retval = outfn(stream, format, plocinfo, ap);
        FUN_00c126df(buffing, stream);
    }
    __finally {
        FUN_00c07bfa(stream);
    }
    return retval;
}
}
}   // namespace f3m_00c058e0


// @f3 0x00c0f5da (community match, verified in this file)
extern int DAT_0117a760;
namespace f3m_00c0f5da {

// pdb: _crt_debugger_hook | dbghook.obj | tesv_win, call_seq, medium
void __cdecl FUN_00c0f5da()
{
    DAT_0117a760 = 0;
}
}   // namespace f3m_00c0f5da

// @f3 0x00c1164f (community match, verified in this file)
namespace f3m_00c1164f {
int __cdecl FUN_00c115ab(void* value, int mode);
// pdb: _mbctolower | mbtolwr.obj | tesv_win, call_gap, low
int __cdecl FUN_00c1164f(void* value)
{
    return FUN_00c115ab(value, 0);
}
}   // namespace f3m_00c1164f

// @f3 0x00c171ca (community match, verified in this file)
namespace f3m_00c171ca {
extern void* DAT_0117a494;
void __cdecl FUN_00c0c00d(void* p);
}
void __cdecl FUN_00c171ca()
{
    f3m_00c171ca::FUN_00c0c00d(f3m_00c171ca::DAT_0117a494);
}

// @f3 0x00c0d33a (community match, verified in this file)
namespace f3m_00c0d33a {
namespace f3m_00c0d33a {
int __cdecl FUN_00c0d304(void* p, int flag);
}
// pdb: isxdigit | _ctype.obj | fnv360_0721_beta, call_gap_sim, low, conflict (skyrim: isleadbyte)
// pdb params: c
int __cdecl FUN_00c0d33a(void* p)
{
    return f3m_00c0d33a::FUN_00c0d304(p, 0);
}
}   // namespace f3m_00c0d33a

// @f3 0x00c0aff1 (community match, verified in this file)
namespace f3m_00c0aff1 {
namespace f3m_00c0aff1 {
int __cdecl FUN_00c0ae76(void* p, int flag);
}
// pdb: _forcdecpt | cvt.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: buffer
int __cdecl FUN_00c0aff1(void* p)
{
    return f3m_00c0aff1::FUN_00c0ae76(p, 0);
}
}   // namespace f3m_00c0aff1

// @f3 0x00c1b6ed (community match, verified in this file)
namespace f3m_00c1b6ed {
// pdb: _ValidateRead | validate.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: data, size
int __cdecl FUN_00c1b6ed(int value)
{
    int result = 1;
    if (value == 0)
        result = 0;
    return result;
}
}   // namespace f3m_00c1b6ed

// @f3 0x00c078cc (community match, verified in this file)
namespace f3m_00c078cc {
namespace f3m_00c078cc {
extern "C" void* __cdecl FUN_00c0781e(unsigned int size, unsigned int align, unsigned int offset);
// pdb: _aligned_malloc | align.obj | tesv_win, caller_sim, low
extern "C" void* __cdecl FUN_00c078cc(unsigned int size, unsigned int align)
{
    return FUN_00c0781e(size, align, 0);
}
}
}   // namespace f3m_00c078cc

// @f3 0x00c078b7 (community match, verified in this file)
namespace f3m_00c078b7 {
namespace f3m_00c078b7 {
extern "C" void __cdecl FUN_00c064b8(void* pBlock);
// pdb: XGRAPHICS::MyClientFreeSysMem | r500assembler.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: _aligned_free)
// pdb params: hClientDevHandle, lpAddress
extern "C" void __cdecl FUN_00c078b7(void* memblock)
{
    unsigned int ptr;
    if (memblock == 0)
        return;
    ptr = (unsigned int)memblock;
    ptr = (ptr & ~(4 - 1)) - 4;
    ptr = *((unsigned int*)ptr);
    FUN_00c064b8((void*)ptr);
}
}
}   // namespace f3m_00c078b7

// @f3 0x00c0781e (community match, verified in this file)
namespace f3m_00c0781e {
namespace f3m_00c0781e {
extern "C" int* __cdecl FUN_00c02a76(void);
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" void* __cdecl FUN_00c063f5(unsigned int size);
// pdb: _aligned_offset_malloc | align.obj | tesv_win, caller_sim, low
extern "C" void* __cdecl FUN_00c0781e(unsigned int size, unsigned int align, unsigned int offset)
{
    unsigned int ptr, retptr, gap;
    {
        int _Expr_val = !!(((align) & (align - 1)) == 0);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }
    {
        int _Expr_val = !!(offset == 0 || offset < size);
        if (!(_Expr_val)) {
            *FUN_00c02a76() = 22;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return 0;
        }
    }
    align = (align > 4 ? align : 4) - 1;
    gap = (0 - offset) & (4 - 1);
    if ((ptr = (unsigned int)FUN_00c063f5(4 + gap + align + size)) == 0)
        return 0;
    retptr = ((ptr + 4 + gap + align + offset) & ~align) - offset;
    ((unsigned int*)(retptr - gap))[-1] = ptr;
    return (void*)retptr;
}
}
}   // namespace f3m_00c0781e

// @f3 0x00c12a0f (community match, verified in this file)
namespace f3m_00c12a0f {
namespace f3m_00c12a0f {
struct ioinfo { long osfhnd; char osfile; char pipech; short unk06; int lockinitflag; char lock[0x18]; char textmode; char unicode; char pipech2[2]; long startposLow, startposHigh; int utf8translations; char dbcsBuffer; char dbcsBufferUsed; short unk36; };
}
extern "C" unsigned long* __cdecl FUN_00c02a89();   // __doserrno
extern "C" int* __cdecl FUN_00c02a76();             // _errno
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int); // _invalid_parameter
extern "C" int __cdecl FUN_00c1d471(int fh);        // _lock_fhandle
extern "C" void __cdecl FUN_00c1d511(int fh);       // _unlock_fhandle
extern "C" int __cdecl FUN_00c1297b(int fh);        // _close_nolock
extern "C" int DAT_0117a644;                        // _nhandle
extern "C" f3m_00c12a0f::ioinfo* DAT_0117a660[];    // __pioinfo

inline f3m_00c12a0f::ioinfo* pioinfo(int fh) { return DAT_0117a660[fh >> 5] + (fh & 0x1f); }

// pdb: _close | close.obj | fnv360_0822_retail, call_seq, high
// pdb params: fh
extern "C" int __cdecl FUN_00c12a0f(int fh)
{
    int r;
    if (fh == -2) {
        *FUN_00c02a89() = 0L;
        *FUN_00c02a76() = 9;
        return -1;
    }
    {
        int ok = (fh >= 0 && (unsigned)fh < (unsigned)DAT_0117a644);
        if (!ok) {
            *FUN_00c02a89() = 0L;
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    {
        int ok = !!(pioinfo(fh)->osfile & 1);
        if (!ok) {
            *FUN_00c02a89() = 0L;
            *FUN_00c02a76() = 9;
            FUN_00c01e67(0, 0, 0, 0, 0);
            return -1;
        }
    }
    FUN_00c1d471(fh);
    __try {
        if (pioinfo(fh)->osfile & 1)
            r = FUN_00c1297b(fh);
        else {
            *FUN_00c02a76() = 9;
            r = -1;
        }
    }
    __finally {
        FUN_00c1d511(fh);
    }
    return r;
}
}   // namespace f3m_00c12a0f

// @f3 0x00c07fe5 (community match, verified in this file)
namespace crt_c07fe5 {
struct Descriptor {
    long handle;
    unsigned char osFlags;
    unsigned char pipeLookahead;
    unsigned short unknown06;
    int lockInitialized;
    CRITICAL_SECTION lock;
    unsigned char textModeAndUnicode;
    unsigned char unknown25,unknown26,unknown27;
    unsigned unknown28,unknown2c,unknown30,unknown34;
};
extern "C" Descriptor* __pioinfo[64];
extern "C" Descriptor _badioinfo;
int* __cdecl FUN_00c02a76();
void __cdecl FUN_00c01e67(const wchar_t*,const wchar_t*,const wchar_t*,unsigned,unsigned);
void __cdecl FUN_00c07b90(FILE*);
void __cdecl FUN_00c07bfa(FILE*);
int __cdecl FUN_00c1294e(FILE*);
int __cdecl FUN_00c15880(FILE*);
__forceinline Descriptor* GetDescriptor(FILE* stream)
{
    if(FUN_00c1294e(stream)!=-1 && FUN_00c1294e(stream)!=-2) {
        Descriptor** group=&__pioinfo[FUN_00c1294e(stream)>>5];
        return *group+(FUN_00c1294e(stream)&31);
    }
    return &_badioinfo;
}
}
// pdb: fgetc | fgetc.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: fputs)
// pdb params: stream
int __cdecl FUN_00c07fe5(FILE* stream)
{
    using namespace crt_c07fe5;
    int result=0;
    int valid=!!(stream!=0);
    if(!valid) {
        *FUN_00c02a76()=22;
        FUN_00c01e67(0,0,0,0,0);
        return -1;
    }
    FUN_00c07b90(stream);
    __try {
        if(!(stream->_flag&0x40)) {
            if((GetDescriptor(stream)->textModeAndUnicode&0x7f)!=0 ||
               (GetDescriptor(stream)->textModeAndUnicode&0x80)!=0) {
                *FUN_00c02a76()=22;
                FUN_00c01e67(0,0,0,0,0);
                result=-1;
            }
        }
        if(!result) {
            result=--stream->_cnt>=0 ? (unsigned char)*stream->_ptr++ : FUN_00c15880(stream);
        }
    } __finally {
        FUN_00c07bfa(stream);
    }
    return result;
}

// @f3 0x00c0811c (community match, verified in this file)
#include <stdio.h>
#include <windows.h>
namespace crt_c0811c {
struct Descriptor {
    long handle;
    unsigned char osFlags;
    unsigned char pipeLookahead;
    unsigned short unknown06;
    int lockInitialized;
    CRITICAL_SECTION lock;
    unsigned char textModeAndUnicode;
    unsigned char unknown25,unknown26,unknown27;
    unsigned unknown28,unknown2c,unknown30,unknown34;
};
extern "C" Descriptor* __pioinfo[64];
extern "C" Descriptor __badioinfo;
int* __cdecl FUN_00c02a76();
void __cdecl FUN_00c01e67(const wchar_t*,const wchar_t*,const wchar_t*,unsigned,unsigned);
void __cdecl FUN_00c07b90(FILE*);
void __cdecl FUN_00c07bfa(FILE*);
int __cdecl FUN_00c1294e(FILE*);
int __cdecl FUN_00c0d3fe(int,FILE*);
__forceinline Descriptor* GetDescriptor(FILE* stream)
{
    if(FUN_00c1294e(stream)!=-1 && FUN_00c1294e(stream)!=-2) {
        Descriptor** group=&__pioinfo[FUN_00c1294e(stream)>>5];
        return *group+(FUN_00c1294e(stream)&31);
    }
    return &__badioinfo;
}
}
// pdb: fputc | fputc.obj | fnv360_0822_retail, caller_sim, low
// pdb params: ch, str
int __cdecl FUN_00c0811c(int character,FILE* stream)
{
    using namespace crt_c0811c;
    int result=0;
    int valid=!!(stream!=0);
    if(!valid) {
        *FUN_00c02a76()=22;
        FUN_00c01e67(0,0,0,0,0);
        return -1;
    }
    FUN_00c07b90(stream);
    __try {
        if(!(stream->_flag&0x40)) {
            if((GetDescriptor(stream)->textModeAndUnicode&0x7f)!=0 ||
               (GetDescriptor(stream)->textModeAndUnicode&0x80)!=0) {
                *FUN_00c02a76()=22;
                FUN_00c01e67(0,0,0,0,0);
                result=-1;
            }
        }
        if(!result) {
            result=--stream->_cnt>=0 ? (unsigned char)(*stream->_ptr++=(char)character) : FUN_00c0d3fe(character,stream);
        }
    } __finally {
        FUN_00c07bfa(stream);
    }
    return result;
}

// @f3 0x00c1c4d7 (community match, verified in this file)
struct QIoInfo39
{
    int osfhnd;
    char osfile;
    char pipech;
    char unk06;
    char unk07;
    int lockinitflag;
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
};
extern "C" QIoInfo39* DAT_0117a660[];
extern "C" int DAT_0117a644;
extern "C" int* __cdecl FUN_00c02a76();
extern "C" unsigned long* __cdecl FUN_00c02a89();
extern "C" void __cdecl FUN_00c01e67(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00c1d471(int fh);
extern "C" void __cdecl FUN_00c1d511(int fh);
extern "C" __int64 __cdecl FUN_00c1c454(int fh, __int64 pos, int mthd);

// pdb: _lseeki64 | lseeki64.obj | fnv360_0822_retail, call_seq, medium
// pdb params: fh, pos, mthd
extern "C" __int64 __cdecl FUN_00c1c4d7(int fh, __int64 pos, int mthd)
{
    __int64 r = -1i64;
    if (fh == -2)
    {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = 9;
        return -1i64;
    }
    {
    int ev = !!(fh >= 0 && (unsigned)fh < (unsigned)DAT_0117a644);
    if (!ev)
    {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = 9;
        FUN_00c01e67(0, 0, 0, 0, 0);
        return -1i64;
    }
    }
    {
    int ev = !!(DAT_0117a660[fh >> 5][fh & 0x1f].osfile & 1);
    if (!ev)
    {
        *FUN_00c02a89() = 0;
        *FUN_00c02a76() = 9;
        FUN_00c01e67(0, 0, 0, 0, 0);
        return -1i64;
    }
    }
    FUN_00c1d471(fh);
    __try
    {
        if (DAT_0117a660[fh >> 5][fh & 0x1f].osfile & 1)
            r = FUN_00c1c454(fh, pos, mthd);
        else
        {
            *FUN_00c02a76() = 9;
            *FUN_00c02a89() = 0;
            r = -1i64;
        }
    }
    __finally
    {
        FUN_00c1d511(fh);
    }
    return r;
}

// @f3 0x00c06a2b (community match, verified in this file)
namespace f3m_00c06a2b {
typedef void (__cdecl *_PVFV)(void);
enum { _EXIT_LOCK1 = 8 };

extern "C" {
extern int DAT_01179b58;      // _C_Exit_Done
extern int DAT_01179b54;      // _C_Termination_Done
extern char DAT_01179b50;     // _exitflag
extern _PVFV* DAT_0117b78c;   // __onexitbegin
extern _PVFV* DAT_0117b788;   // __onexitend
extern _PVFV DAT_00db3080[];  // __xp_a
extern _PVFV DAT_00db308c[];  // __xp_z
extern _PVFV DAT_00db3090[];  // __xt_a
extern _PVFV DAT_00db3094[];  // __xt_z

void __cdecl FUN_00c16621(int locknum);   // _lock
void __cdecl FUN_00c16549(int locknum);   // _unlock
void* __cdecl FUN_00c0c00d(void* ptr);    // _decode_pointer
void* __cdecl FUN_00c0c004(void);         // _encoded_null
__declspec(noreturn) void __cdecl FUN_00c068c7(int status);  // __crtExitProcess

static __declspec(noinline) void __cdecl FUN_00c068ee(_PVFV* pfbegin, _PVFV* pfend)  // _initterm
{
    while (pfbegin < pfend) {
        if (*pfbegin)
            (**pfbegin)();
        ++pfbegin;
    }
}

// pdb: doexit | crt0dat.obj | fnv360_0822_retail, udata, high
static void __cdecl FUN_00c06a2b(int code, int quick, int retcaller)  // doexit
{
    FUN_00c16621(_EXIT_LOCK1);
    __try {
        if (DAT_01179b58 != 1) {
            DAT_01179b54 = 1;
            DAT_01179b50 = (char)retcaller;
            if (!quick) {
                _PVFV* onexitbegin = (_PVFV*)FUN_00c0c00d(DAT_0117b78c);
                _PVFV* onexitend = (_PVFV*)FUN_00c0c00d(DAT_0117b788);
                if (onexitbegin) {
                    while (--onexitend >= onexitbegin) {
                        if (*onexitend && *onexitend != (_PVFV)FUN_00c0c004())
                            ((_PVFV)FUN_00c0c00d((void*)*onexitend))();
                    }
                }
                FUN_00c068ee(DAT_00db3080, DAT_00db308c);
            }
            FUN_00c068ee(DAT_00db3090, DAT_00db3094);
        }
    }
    __finally {
        if (retcaller)
            FUN_00c16549(_EXIT_LOCK1);
    }
    if (!retcaller) {
        DAT_01179b58 = 1;
        FUN_00c16549(_EXIT_LOCK1);
        FUN_00c068c7(code);
    }
}

void __cdecl FUN_00c06b3e(void)  // _c_exit
{
    FUN_00c06a2b(0, 1, 1);
}

}  // extern "C"
}   // namespace f3m_00c06a2b
