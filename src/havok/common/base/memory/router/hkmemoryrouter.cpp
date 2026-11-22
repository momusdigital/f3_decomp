#include "f3_common.h"
// src/havok/common/base/memory/router/hkmemoryrouter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/router/hkmemoryrouter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// If p is non-null, clears the field at p-0x10 and calls heap->Free on the block at p minus the offset stored at p-8, with size from p-0xc plus 0x10.
// @f3 0x008f7010 (community match, verified in this file)
namespace f3m_008f7010 {
struct HeapBlockHeader
{
    unsigned int magic;
    unsigned int size;
    unsigned int tag;
    unsigned int offset;
};

class F3MemHeap
{
  public:
    void FUN_008f6d90(void* block, unsigned int size, unsigned int tag);
    void FUN_008f7010(char* data);
};

// pdb: hkStringPtr::hkStringPtr | hkStringPtr.obj | fnv360_0822_retail, objrun_open, low
// pdb params: s, len
void F3MemHeap::FUN_008f7010(char* data)
{
    if (!data)
        return;

    HeapBlockHeader* header = (HeapBlockHeader*)(data - 0x10);
    unsigned int tag = header->tag;
    unsigned int size = header->size + 0x10;
    char* block = data - header->offset;
    header->magic = 0xdeadbeef;
    FUN_008f6d90(block, size, tag);
}
}   // namespace f3m_008f7010


// If data is non-null, clears the block header's first field and dispatches the header with its size plus 0x10 to owner->unk08.
// @f3 0x008f6f90 (community match, verified in this file)
namespace f3m_008f6f90 {
struct HeapBlockHeader
{
    unsigned int magic;
    unsigned int size;
    unsigned int tag;
    unsigned int unk0C;
};

class F3MemHeap
{
  public:
    void FUN_008f6d90(void* block, unsigned int size, unsigned int tag);
    void FUN_008f6f90(char* data);
};

// pdb: hkMemoryRouter::easyFree | hkMemoryRouter.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: b, p
void F3MemHeap::FUN_008f6f90(char* data)
{
    if (!data)
        return;

    HeapBlockHeader* header = (HeapBlockHeader*)(data - 0x10);
    unsigned int size = header->size + 0x10;
    unsigned int tag = header->tag;
    header->magic = 0xdeadbeef;
    FUN_008f6d90(header, size, tag);
}
}   // namespace f3m_008f6f90


#include <windows.h>

namespace fnv_00c85760 {
// Global TLS slot index used by the thread-local accessor.
extern DWORD g_dwTlsIndex;

// @fnv 0x00c85760
// pdb: `dynamic atexit destructor for 'BSFaceGenManager::bUseFaceGenPreprocessedHeads'' | BSFaceGenManager.obj | tesv_win, objrun_open, low
void* FUN_00c85760()
{
    return TlsGetValue(g_dwTlsIndex);
}
}  // namespace fnv_00c85760
