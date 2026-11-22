#include "f3_common.h"
// src/havok/common/base/monitor/hkmonitorstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/hkmonitorstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00cb0da0
{
    int m_00;
    int m_04;
};

// @fnv 0x00cb0da0
// pdb: hkMonitorStream::reset | hkMonitorStream.obj | tesv_win, objrun_open, low
void FUN_00cb0da0(S_00cb0da0* p)
{
    p->m_04 = p->m_00;
}

// ResizeBuffer - grow/shrink a spawned byte buffer through the audio allocator.
//
// The buffer keeps four pointers and a flag:
//   +0x00  m_00  start of the allocation
//   +0x04  m_04  current write position
//   +0x08  m_08  end of the allocation
//   +0x0c  m_0c  end - 0x20 (the reserved tail)
//   +0x10  m_10  "the allocation is live" flag
//
// FUN_00c85750 hands back the thread's audio system; its +0x14 member is the
// byte allocator whose virtual 4 allocates (through an in/out size) and whose
// virtual 5 releases a block.

struct ByteAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(unsigned int* count);
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ByteAllocator* m_14;
};

struct SpawnedBuffer
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    unsigned char m_10;
};

char* FUN_00c85750();

// @f3 0x009448d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
void FUN_00944860(SpawnedBuffer* buf);

struct StubAllocF3 {
    int unk00;
    void FUN_008f6f90(char* p);
    char* FUN_008f6f60(unsigned int size, int kind);
};

// pdb: NiObject::NiObject | NiObject.obj | fnv360_0822_debug, objopen_prop, low, conflict (skyrim: hkMonitorStream::resize)
void ResizeBuffer(SpawnedBuffer* pBuffer, int iSize)
{

    char* begin = pBuffer->m_00;
    if (iSize == (int)(pBuffer->m_08 - begin))
    {
        return;
    }
    if (iSize > 0)
    {

        if (begin != 0 && pBuffer->m_10 != 0)
        {
            StubAllocF3* h = (StubAllocF3*)TlsGetValue(DAT_010f3170);
            h->FUN_008f6f90(begin);
        }
        pBuffer->m_10 = 1;
        StubAllocF3* h2 = (StubAllocF3*)TlsGetValue(DAT_010f3170);
        char* p = h2->FUN_008f6f60((unsigned int)iSize, 0x1b);
        pBuffer->m_00 = p;
        pBuffer->m_04 = p;
        pBuffer->m_08 = p + iSize;
        pBuffer->m_0c = p + iSize - 0x20;
    }
    else
    {
        FUN_00944860(pBuffer);
    }
}


#include <windows.h>
namespace fnv_00cb0db0 {
extern DWORD DAT_0126835c;

class SpawnedAllocator
{
  public:
    virtual void vSlot0();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    SpawnedAllocator* m_14;
};

AllocHolder* __cdecl FUN_00c85750();

struct SpawnedObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char m_10;
};

// Allocates a SpawnedObject via the AllocHolder's SpawnedAllocator, stores it in TLS, and zeroes its fields.
// @fnv 0x00cb0db0
void __cdecl FUN_00cb0db0()
{
    AllocHolder* holder = FUN_00c85750();
    SpawnedAllocator* alloc = holder->m_14;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x14);
    TlsSetValue(DAT_0126835c, obj);
    obj->m_10 = 0;
    obj->m_00 = 0;
    obj->m_08 = 0;
    obj->m_04 = 0;
    obj->m_0c = 0;
}
}  // namespace fnv_00cb0db0

namespace fnv_00cb0df0 {
extern DWORD DAT_0126835c;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

}  // namespace fnv_00cb0df0
