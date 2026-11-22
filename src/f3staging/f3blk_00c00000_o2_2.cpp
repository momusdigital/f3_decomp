#include <windows.h>
// src/f3staging/f3blk_00c00000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00c01b0b (community match, verified in this file)
extern char DAT_00eaab1c;
namespace f3m_00c01b0b {
namespace FallbackC01 {
struct ValueOwner {
 int unk00; void* value;
 void* std_exception_what();
};
// pdb: std::exception::what | xthrow.obj | fnv360_0822_retail, ustr + bridge(vtable|ustr) + skyrim(vtable), high
void* ValueOwner::std_exception_what() {
 void* result = value;
 if (!result) result = &DAT_00eaab1c;
 return result;
}
}
}   // namespace f3m_00c01b0b

// @f3 0x00c17387 (community match, verified in this file)
extern unsigned int DAT_0117a4a0;
namespace f3m_00c17387 {
// pdb: _initp_misc_rand_s | rand_s.obj | tesv_win, call_seq, medium
void FUN_00c17387(unsigned int value) { DAT_0117a4a0 = value; }
}   // namespace f3m_00c17387

// @f3 0x00c04d8d (community match, verified in this file)
namespace f3m_00c04d8d {
namespace f3_00c04d8d {
struct Ptd {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int field14;
};
extern "C" Ptd* __cdecl FUN_00c0c229();
}

// pdb: srand | rand.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: seed
void __cdecl FUN_00c04d8d(int value) {
    f3_00c04d8d::FUN_00c0c229()->field14 = value;
}
}   // namespace f3m_00c04d8d

// @f3 0x00c09aa7 (community match, verified in this file)
namespace f3m_00c09aa7 {
namespace f3_00c09aa7 {
struct Base {
    virtual void vf();
    void FUN_00c01af5() throw();
    ~Base() throw() { FUN_00c01af5(); }
};
}
struct FUN_00c09aa7 : f3_00c09aa7::Base {
    virtual ~FUN_00c09aa7() throw();
};
FUN_00c09aa7::~FUN_00c09aa7() throw() {}
}   // namespace f3m_00c09aa7

// @f3 0x00c0c07b (community match, verified in this file)
namespace f3m_00c0c07b {
extern "C" __declspec(dllimport) unsigned long __stdcall FUN_00d9b078();

// pdb: __crtTlsAlloc | tidtable.obj | tesv_win, objrun, medium
unsigned long __stdcall FUN_00c0c07b(void* unused) {
    return FUN_00d9b078();
}
}   // namespace f3m_00c0c07b

// @f3 0x00c068e5 (community match, verified in this file)
namespace f3m_00c068e5 {
namespace f3_00c068e5 {
void __cdecl FUN_00c16549(int lockId);
// pdb: _unlockexit | crt0dat.obj | tesv_win, call_seq, medium
void __cdecl FUN_00c068e5()
{
    FUN_00c16549(8);
}
}
}   // namespace f3m_00c068e5

// @f3 0x00c06b3e (community match, verified in this file)
namespace f3m_00c06b3e {
void __cdecl FUN_00c06a2b(int code,int quick,int returnToCaller);
// pdb: _c_exit | crt0dat.obj | tesv_win, call_gap, low
void __cdecl FUN_00c06b3e(){FUN_00c06a2b(0,1,1);}
}   // namespace f3m_00c06b3e

// @f3 0x00c0cafb (community match, verified in this file)
extern void* DAT_0117a1d4;
namespace f3m_00c0cafb {
// pdb: _initp_misc_purevirt | inithelp.obj | tesv_win, call_seq, medium
void __cdecl FUN_00c0cafb(void* value){DAT_0117a1d4=value;}
}   // namespace f3m_00c0cafb

// @f3 0x00c01d61 (community match, verified in this file)
extern void* DAT_01179af8;
namespace f3m_00c01d61 {

// pdb: _initp_misc_invarg | invarg.obj | fnv360_0822_retail, udata, high
// pdb params: enull
extern "C" void* __cdecl FUN_00c01d61(void* p) {
    return DAT_01179af8 = p;
}
}   // namespace f3m_00c01d61

// @f3 0x00c01b49 (community match, verified in this file)
extern const void* DAT_00eaab34;
namespace f3m_00c01b49 {
namespace f3_00c01b49 {
struct Obj {
    const void* vftable;
    void FUN_00c01af5();
    void FUN_00c01b49();
};

// pdb: std::bad_cast::~bad_cast | cerr.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
void Obj::FUN_00c01b49() {
    vftable = &DAT_00eaab34;
    FUN_00c01af5();
}
}
}   // namespace f3m_00c01b49

// @f3 0x00c07ab0 (community match, verified in this file)
namespace f3m_00c07ab0 {
namespace f3m_00c07ab0 {
extern "C" void __cdecl FUN_00c07983(int flag);
// pdb: _flushall | fflush.obj | fnv360_0822_retail, caller_sim, medium
extern "C" void __cdecl FUN_00c07ab0() {
    FUN_00c07983(1);
}
}
}   // namespace f3m_00c07ab0

// @f3 0x00c01bb5 (community match, verified in this file)
extern const void* DAT_00eaab40;
namespace f3m_00c01bb5 {
namespace f3_00c01bb5 {
struct Obj {
    const void* vftable;
    void FUN_00c01af5();
    void FUN_00c01bb5();
};

// pdb: std::__non_rtti_object::~__non_rtti_object | rtti.obj | fnv360_0721_beta, objrun_open, low
void Obj::FUN_00c01bb5() {
    vftable = &DAT_00eaab40;
    FUN_00c01af5();
}
}
}   // namespace f3m_00c01bb5

// @f3 0x00c17391 (community match, verified in this file)
namespace f3m_00c17391 {
namespace f3m_00c17391 {
extern int DAT_0117a4a4;
}
// pdb: _initp_misc_initcrit | initcrit.obj | tesv_win, call_seq, medium
void __cdecl FUN_00c17391(int value)
{
    f3m_00c17391::DAT_0117a4a4 = value;
}
}   // namespace f3m_00c17391



// @f3 0x00c0c004 (community match, verified in this file)
namespace f3m_00c0c004 {
void __cdecl FUN_00c0bf96(int);

// pdb: _encoded_null | tidtable.obj | tesv_win, call_seq, medium
void FUN_00c0c004()
{
    FUN_00c0bf96(0);
}
}   // namespace f3m_00c0c004

// @f3 0x00c1bbff (community match, verified in this file)
namespace f3m_00c1bbff {
namespace f3m_00c1bbff {
void __cdecl FUN_00c0687d(int n);
}
// pdb: _fptrap | crt0fp.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void __cdecl _fptrap()
{
    f3m_00c1bbff::FUN_00c0687d(2);
}
}   // namespace f3m_00c1bbff

// @f3 0x00c159dd (community match, verified in this file)
namespace f3m_00c159dd {

namespace f3m_00c159dd {
LONG WINAPI FUN_00c159a0(EXCEPTION_POINTERS* info);
}
// pdb: __CxxSetUnhandledExceptionFilter | unhandld.obj | tesv_win, objrun_open, low
int __cdecl FUN_00c159dd()
{
    SetUnhandledExceptionFilter(f3m_00c159dd::FUN_00c159a0);
    return 0;
}
}   // namespace f3m_00c159dd

// @f3 0x00c06b2f (community match, verified in this file)
namespace f3m_00c06b2f {
namespace f3m_00c06b2f {
void __cdecl FUN_00c06a2b(int code, int quick, int retcaller);
}
// pdb: _cexit | crt0dat.obj | fnv360_0822_debug, objrun_open, low
void __cdecl FUN_00c06b2f()
{
    f3m_00c06b2f::FUN_00c06a2b(0, 0, 1);
}
}   // namespace f3m_00c06b2f

// @f3 0x00c17151 (community match, verified in this file)
extern int DAT_0117a484;
namespace f3m_00c17151 {
// pdb: _initp_heap_handler | handler.obj | fnv360_0822_retail, udata + skyrim(call_seq), high
void __cdecl _initp_heap_handler(int v)
{
    DAT_0117a484 = v;
}
}   // namespace f3m_00c17151

// @f3 0x00c05dae (community match, verified in this file)
#include <windows.h>
extern "C" IMAGE_DOS_HEADER __ImageBase;
namespace f3m_00c05dae {

int __cdecl FUN_00c05dae()
{
    if (__ImageBase.e_magic == IMAGE_DOS_SIGNATURE)
    {
        const IMAGE_NT_HEADERS32* headers = reinterpret_cast<const IMAGE_NT_HEADERS32*>(
            reinterpret_cast<const unsigned char*>(&__ImageBase) + __ImageBase.e_lfanew);
        if (headers->Signature == IMAGE_NT_SIGNATURE &&
            headers->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC &&
            headers->OptionalHeader.NumberOfRvaAndSizes > IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
            return headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress != 0;
    }
    return 0;
}
}   // namespace f3m_00c05dae

// @f3 0x00c05fcf (community match, verified in this file)
namespace f3m_00c05fcf {
namespace f3m_00c05fcf {
extern "C" void __cdecl FUN_00c16105(void);
extern "C" int __cdecl FUN_00c05def(void);
// pdb: WinMainCRTStartup | wincrt0.obj | tesv_win, caller_sim, low
extern "C" int __cdecl FUN_00c05fcf(void)
{
    FUN_00c16105();
    return FUN_00c05def();
}
}
}   // namespace f3m_00c05fcf

// @f3 0x00c1be1e (community match, verified in this file)
extern "C" int DAT_0117a76c;
namespace f3m_00c1be1e {
namespace f3m_00c1be1e {
extern "C" int __cdecl FUN_00c1bdbe(void);
// pdb: __sse2_available_init | cpu_disp.obj | tesv_win, caller_sim, low
extern "C" int __cdecl FUN_00c1be1e(void)
{
    DAT_0117a76c = FUN_00c1bdbe();
    return 0;
}
}
}   // namespace f3m_00c1be1e

// @f3 0x00c0019b (community match, verified in this file)
extern "C" char DAT_00eaaa7c;
namespace f3m_00c0019b {
namespace f3m_00c0019b {
struct type_info_ {
    void* vfptr;
    void* _m_data;
    char _m_d_name[1];
    void FUN_00c0019b();
};
extern "C" void __cdecl FUN_00c0c6d0(type_info_* ti);
// pdb: type_info::~type_info | typinfo.obj | tesv_win, uvref, medium
void type_info_::FUN_00c0019b()
{
    vfptr = &DAT_00eaaa7c;
    FUN_00c0c6d0(this);
}
}
}   // namespace f3m_00c0019b
