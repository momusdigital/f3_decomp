#include "f3_common.h"
// src/havok/common/base/container/string/hkstringptr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstringptr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

int __cdecl hkString_strLen(const char* s);
char* __cdecl AllocateWithHeader(void* alloc, int size);

// @f3 0x00923640 (community match, verified in this file)
typedef void* (__stdcall *TlsGetter385)(unsigned long index);
namespace Heap385 {
extern unsigned long DAT_010f3170;
extern TlsGetter385 DAT_00d9b080;
struct Heap { void* FUN_008f6f60(unsigned int size, unsigned int tag); };
}
unsigned int __cdecl FUN_009233f0(const char* text);
void __cdecl FUN_009233b0(char* destination, const char* source);
char* __cdecl FUN_00cb1160(const char* text, void* unusedAllocator) {
    unsigned int size = FUN_009233f0(text) + 1;
    Heap385::Heap* heap = static_cast<Heap385::Heap*>(Heap385::DAT_00d9b080(Heap385::DAT_010f3170));
    char* result = static_cast<char*>(heap->FUN_008f6f60(size, 0x16));
    FUN_009233b0(result, text);
    return result;
}


extern void* g_01268358;

struct FUN_00cb0a60
{
    void* unk00;
    FUN_00cb0a60();
};

// @fnv 0x00cb0a60
FUN_00cb0a60::FUN_00cb0a60()
{
    unk00 = g_01268358;
}

int __cdecl hkString_strLen(const char* s);

struct WriterCC0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Write(const char* s, int len);
};

// Writes the string s to w, or the literal "(null)" when s is null.
// @fnv 0x00cc0080
// pdb: writeString | hkOStream.obj | tesv_win, hash, low
static __declspec(noinline) void FUN_00cc0080(WriterCC0* apWriter, const char* apString)
{
    if (apString)
        apWriter->Write(apString, hkString_strLen(apString));
    else
        apWriter->Write("(null)", 6);
}

volatile int g_wcc0;
volatile int g_scc0;
void CallTarget_cc0080()
{
    WriterCC0* w = (WriterCC0*)g_wcc0;
    const char* s = (const char*)g_scc0;
    FUN_00cc0080(w, s);
    FUN_00cc0080(w, s);
}

struct SinkOwner
{
    virtual void v0();
    void* unk04;
    WriterCC0* writer;
    SinkOwner* FUN_00cc01c0(const char* text);
};

// @fnv 0x00cc01c0
// pdb: hkOstream::operator<< | hkOStream.obj | tesv_win, hash, low
SinkOwner* SinkOwner::FUN_00cc01c0(const char* text)
{
    FUN_00cc0080(writer, text);
    return this;
}

namespace fnv_00cb11b0 {
// unit_ff4bdaca3856.cpp

extern "C"
{
    void* __cdecl hkString_strLen(void* p);
    void* __cdecl AllocateWithHeader(void* p, int n);
}

// Copies up to n2 characters from p1 into a new null-terminated buffer allocated from p3 and returns it.
// @f3 0x00923680 (community match, verified in this file)
// 0x00923680, 76 bytes, demanded symbol fnv_00cb11b0::FUN_00cb11b0(void*, int, void*).
// Copy of the source into a thread-local heap buffer, truncated to the second argument.
void __cdecl FUN_009233d0(void* destination, const void* source, int length);

void* __cdecl FUN_00cb11b0(void* apSource, int anMaxLen, void* apAllocator);
namespace fnv_00cb11b0 { void* __cdecl FUN_00cb11b0(void* apSource, int anMaxLen, void* apAllocator); }
// pdb: strNdup | hkStringPtr.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void* __cdecl ::fnv_00cb11b0::FUN_00cb11b0(void* apSource, int anMaxLen, void* apAllocator)
{
    int length = (int)FUN_009233f0(static_cast<const char*>(apSource));
    if (length > anMaxLen)
        length = anMaxLen;

    Heap385::Heap* heap = static_cast<Heap385::Heap*>(Heap385::DAT_00d9b080(Heap385::DAT_010f3170));
    char* buffer = static_cast<char*>(heap->FUN_008f6f60(length + 1, 0x16));
    FUN_009233d0(buffer, apSource, length);
    buffer[length] = 0;
    return buffer;
}

}  // namespace fnv_00cb11b0
