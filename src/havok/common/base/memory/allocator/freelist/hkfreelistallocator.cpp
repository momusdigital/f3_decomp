#include "f3_common.h"
// src/havok/common/base/memory/allocator/freelist/hkfreelistallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelistallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FUN_00d5f850_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28(int* out);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void FUN_00d5f850();
};

// Zeroes a six-int buffer, fills it via v28, then stores the second element into unk20.
// @f3 0x0049e910 (community match, verified in this file)
#include <stdlib.h>
#include <string.h>

extern unsigned char DAT_0106dd0e;
void __cdecl TESForm___AddChunkData(int tag, void* p, int n);

struct FUN_0049e910_vt
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
};

// pdb: TESRegionData::Save | TESRegionData.obj | fnv360_0822_retail, call_seq, medium
void FUN_00d5f850_cls::FUN_00d5f850()
{
    int buf[2];
    unsigned char* self = (unsigned char*)this;
    memset(buf, 0, sizeof(buf));
    int r = ((FUN_0049e910_vt*)this)->v0c();
    buf[0] = r;
    ((unsigned char*)buf)[4] = self[4];
    ((unsigned char*)buf)[5] = self[6];
    if (DAT_0106dd0e != 0)
    {
        buf[0] = _byteswap_ulong(r);
    }
    TESForm___AddChunkData(0x54414452, buf, 8);
}


struct FUN_00d5fc30_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    void FUN_00d5fc30();
};

// @fnv 0x00d5fc30
// pdb: ExteriorCellLoader::QueuedCellCount | ExteriorCellLoader.obj | fnv360_0822_retail, call_gap, low
void FUN_00d5fc30_cls::FUN_00d5fc30()
{
    this->v40();
}

extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);
namespace d5f {
struct Res
{
    bool m_kPointB;
    Res()
    {}
};
}

// @fnv 0x00d5fab0
// pdb: hkpCollisionAgent::invalidateTim | hkpCollisionAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpCollisionAgent_invalidateTim(int)
{}

extern void(__stdcall* DAT_00fdf05c)(int* pkCriticalSection);
extern void(__stdcall* DAT_00fdf100)(int* pkCriticalSection);

void __cdecl FUN_00d88040(int);

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef void(__cdecl* hkMemoryWalkCallback)(void* start, unsigned int size, hkBool allocated, int pool, void* param);

struct hkFreeListBlock
{
    hkFreeListBlock* m_next;
};

struct hkFreeListW
{
    void* m_free;
    unsigned int m_iFirstIndex;
    unsigned int m_unk08;
    hkFreeListBlock* m_activeBlocks;
    hkFreeListBlock* m_pFreeBlocks;

    static int _getNumBlocks(const hkFreeListBlock* blocks)
    {
        int num = 0;
        while (blocks)
        {
            num++;
            blocks = blocks->m_next;
        }
        return num;
    }
    int getTotalNumBlocks() const
    {
        return _getNumBlocks(m_pFreeBlocks) + _getNumBlocks(m_activeBlocks);
    }
    void CollectFreeNodes(hkFreeListBlock** blocks, int numBlocks);
    void FUN_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param);
};

struct hkMemChunkW
{
    unsigned int m_prevFoot;
    unsigned int m_pFirstNode;
};

struct hkLargeBlockIteratorW
{
    hkMemChunkW* m_pCurrentMemoryChunk;
    void* m_pHandlePage;
    void* m_kRayEnd;
    bool isValid() const
    {
        return m_pCurrentMemoryChunk != 0;
    }
    void* GetChunkPayload() const
    {
        return (char*)m_pCurrentMemoryChunk + 0x10;
    }
    unsigned int GetLogicalSize() const
    {
        return m_pCurrentMemoryChunk->m_pFirstNode & ~3u;
    }
    hkBool isInuse() const
    {
        return (m_pCurrentMemoryChunk->m_pFirstNode & 2) != 0;
    }
};

// ---- stand-in models of the objects the original code touches -------------
// The unit file only names hkFreeListAllocator, so the layout below is
// derived from the disassembly of FUN_00d5f750 itself.

// Stand-in for the Fallout: New Vegas pool allocator that owns FUN_00d5fca0.

void __cdecl FUN_00d88040(int);

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);

namespace FreeListCreationView {
}
