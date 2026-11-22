#include "f3_common.h"
// src/havok/physics/dynamics/constraint/atom/hkpconstraintatomutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatomutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D92740Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D92740MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D92740Allocator* m_pStreamAllocator;

    D92740Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D92740MemoryRouter& __cdecl FUN_00c85750();

struct D92740Block
{
    unsigned short unk00;
    unsigned short m_sizeClass;
    unsigned short m_iAllocatedCount;
    unsigned short m_pRayCursor;
    unsigned char m_iAgentTypeA;
    unsigned char m_iAgentTypeB;
    unsigned short unk0A;
    unsigned short m_extra;
};

D92740Block* __cdecl hkpSimpleContactConstraintAtomUtil_allocateAtom(int capacity, int typeA, int typeB, int extra);

// @f3 0x00a26c20 (community match, verified in this file)
struct D92740Block;
D92740Block* __cdecl FUN_00a269d0(int capacity, int typeA, int typeB, int extra);
void __cdecl hkpSimpleContactConstraintAtomUtil_copyContents(D92740Block* dst, D92740Block* src);
struct D92740Heap
{
    void FUN_008f6d90(D92740Block* p, int numBytes, int flag);
};
extern unsigned int DAT_010f3170;
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
// pdb: hkpSimpleContactConstraintAtomUtil::optimizeCapacity | hkpConstraintAtomUtil.obj | fnv360_0822_retail, caller_sim, high
// pdb params: oldAtom_mightGetDeallocated, numFreeElemsLeft, atomReallocated
// pdb: hkpSimpleContactConstraintAtomUtil::optimizeCapacity | hkpConstraintAtomUtil.obj | fnv360_0822_retail, caller_sim, high (was: ShrinkBlockIfSparse)
D92740Block* __cdecl hkpSimpleContactConstraintAtomUtil_optimizeCapacity(D92740Block* block, int numToAdd, bool* pbResized)
{
    if ((block->m_iAllocatedCount + numToAdd) * 2 <= block->m_pRayCursor)
    {
        int capacity = block->m_pRayCursor >> 1;
        D92740Block* newBlock = FUN_00a269d0(capacity, block->m_iAgentTypeA, block->m_iAgentTypeB, block->m_extra);
        hkpSimpleContactConstraintAtomUtil_copyContents(newBlock, block);
        D92740Heap* heap = (D92740Heap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(block, block->m_sizeClass, 4);
        *pbResized = true;
        return newBlock;
    }
    return block;
}


extern "C" D92740MemoryRouter& __cdecl FUN_00c85750();

// @f3 0x00a269d0 (community match, verified in this file)
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct TlsHeap_w152_f2
{
    void* FUN_008f6d30(unsigned int size, int kind);
};
struct Types_w152_f2
{
    unsigned char a;
    unsigned char b;
};
struct Block_w152_f2
{
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned short f06;
    Types_w152_f2 types;
    unsigned char f0A;
    unsigned char unk0B;
    short f0C;
    unsigned short f0E;
    unsigned short f10;
    unsigned short f12;
    unsigned int contactData[7];
};
// pdb: hkpSimpleContactConstraintAtomUtil::allocateAtom | hkpConstraintAtomUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: numReservedContactPoints, numExtraUserDatasA, numExtraUserDatasB, maxNumContactPoints
// pdb: hkpSimpleContactConstraintAtomUtil::allocateAtom | hkpConstraintAtomUtil.obj | fnv360_0822_retail, call_seq, high (was: AllocateBlock)
D92740Block* __cdecl hkpSimpleContactConstraintAtomUtil_allocateAtom(int capacity, int typeA, int typeB, int extra)
{
    unsigned int uiTypeSum;
    uiTypeSum = (unsigned int)typeA + (unsigned int)typeB;
    unsigned int stride = uiTypeSum * 4 + 0x14;
    unsigned int size = (unsigned int)capacity * (stride + 0x20);
    size = (size + 0x3f) & 0xfffffff0u;
    TlsHeap_w152_f2* heap = (TlsHeap_w152_f2*)DAT_00d9b080(DAT_010f3170);
    Block_w152_f2* pBlock;
    pBlock = (Block_w152_f2*)heap->FUN_008f6d30(size, 4);

    pBlock->types.a = typeA;
    pBlock->f06 = capacity;
    pBlock->f02 = size;
    pBlock->f0A = stride;
    *(volatile unsigned char*)&pBlock->types.b = typeB;
    pBlock->f0C = extra;
    pBlock->f10 = 0;
    *(volatile unsigned short*)&pBlock->f12 = 3;
    for (int iIndex = 0; iIndex < 7; ++iIndex)
        pBlock->contactData[iIndex] = 0;
    pBlock->f00 = 0x16;
    pBlock->f04 = 0;
    return (D92740Block*)pBlock;
}

