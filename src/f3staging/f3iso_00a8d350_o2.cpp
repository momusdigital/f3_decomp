#include <new>
// src/f3staging/f3iso_00a8d350_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a8d350 alone: its served symbol embeds an address absent from the index.
// Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a8d350 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a8d350 {
// FUN_00a8d350 (294 bytes): merge a stats tree into another, recursively. For each child of source, find
// the child with the same name under parent (FUN_00a8c7a0); if there is none, allocate a node from the
// thread's free list (or the pool fallback) and build it. Add the child's 8 float and 8 short counters
// into it, then merge the child's own children.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
int __cdecl FUN_00cb0fa0(const char* a, const char* b);

struct S_Flag
{
    bool b;
    S_Flag() : b(false) {}
    S_Flag(const S_Flag& o) : b(o.b) {}
};

struct StatsValue
{
    int m_iValue;
    StatsValue(int iValue) : m_iValue(iValue) {}
};

struct StatsNode
{
    float m_afValue[8];
    unsigned short m_ausCount[8];
    StatsNode** m_ppChildren;
    int m_iChildCount;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* m_pcName;
    int unk50;
    int m_iFlags;

    StatsNode* FUN_00a8d060(StatsNode* pkParent, const char* pcName, StatsValue kFlags);
};

struct StatsPool
{
    int unk00;
    int unk04;
    int unk08;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    void* m_pFree;
    int m_iFreeCount;
    void* FUN_008f6800(int iBlocks, int iKind);
    __forceinline void* Allocate()
    {
        void* pvMem = m_pFree;
        if (pvMem)
        {
            --m_iFreeCount;
            m_pFree = *(void**)pvMem;
            return pvMem;
        }
        return FUN_008f6800(6, 0x1b);
    }
};

static __declspec(noinline) StatsNode* FUN_00a8c7a0(StatsNode* pkOwner, const char* pcName, S_Flag kFallback)
{
    for (int i = 0; i < pkOwner->m_iChildCount; ++i)
    {
        StatsNode** ppkChild = &pkOwner->m_ppChildren[i];
        if (FUN_00cb0fa0(pcName, (*ppkChild)->m_pcName) == 0)
            return pkOwner->m_ppChildren[i];
    }
    if (kFallback.b && pkOwner->m_iChildCount > 0)
        return pkOwner->m_ppChildren[0];
    return 0;
}

// pdb: hkMakeSumRecursive | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: setAllDependeciesToDo)
void __cdecl FUN_00a8d350(StatsNode* pkParent, StatsNode* pkSource)
{
    for (int i = 0; i < pkSource->m_iChildCount; ++i)
    {
        StatsNode* pkItem = pkSource->m_ppChildren[i];
        StatsNode* pkDst = FUN_00a8c7a0(pkParent, pkItem->m_pcName, S_Flag());
        if (!pkDst)
        {
            StatsPool* pkPool = (StatsPool*)TlsGetValue(DAT_010f3170);
            void* pvMem = pkPool->Allocate();
            pkDst = pvMem ? ((StatsNode*)pvMem)->FUN_00a8d060(pkParent, pkItem->m_pcName, StatsValue(pkItem->m_iFlags)) : 0;
        }
        for (int j = 0; j < 8; ++j)
        {
            pkDst->m_afValue[j] += pkItem->m_afValue[j];
            pkDst->m_ausCount[j] += pkItem->m_ausCount[j];
        }
        FUN_00a8d350(pkDst, pkItem);
    }
}
}   // namespace f3m_00a8d350
