#include "f3_common.h"
// src/havok/physics/collide/query/collector/pointcollector/hkpallcdpointcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/pointcollector/hkpallcdpointcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* manager, void* array, int itemSize);

struct ByteTag
{
    char m_cValue;

    ByteTag() : m_cValue(0)
    {}

    ~ByteTag()
    {}
};

void __cdecl FUN_009b2ed0(void* apData, int aiFirst, int aiLast, ByteTag akTag);

struct SortableArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pData;
    int m_iArrayLength;

    void hkpAllCdPointCollector_sortHits();
};

// @fnv 0x00cabad0
// pdb: hkpAllCdPointCollector::sortHits | hkpAllCdPointCollector.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_gap_sim) + skyrim(callee_sim), high
void SortableArray::hkpAllCdPointCollector_sortHits()
{
    ByteTag kTag;
    if (m_iArrayLength > 1)
        FUN_009b2ed0(m_pData, 0, m_iArrayLength - 1, kTag);
}

#include <xmmintrin.h>
struct S_00cab970_Heap
{
    int unk00;
};
struct S_00cab970_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cab970_Heap* heap;
};
void* __cdecl FUN_00c85750();
struct S_00cab970_Vec
{
    __m128 q;
};
struct S_00cab970_Cd
{
    int unk00;
    unsigned int key;
    int unk08;
    S_00cab970_Cd* parent;
};
struct S_00cab970_Entry
{
    S_00cab970_Vec a;
    S_00cab970_Vec b;
    S_00cab970_Cd* rootA;
    unsigned int keyA;
    unsigned int keysA[8];
    S_00cab970_Cd* rootB;
    unsigned int keyB;
    unsigned int keysB[8];
};
struct S_00cab970_Arr;
void __cdecl ResizeAudioStream(S_00cab970_Heap* heap, S_00cab970_Arr* arr, int elemSize);
struct S_00cab970_Arr
{
    S_00cab970_Entry* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline S_00cab970_Entry& AllocatePair()
    {
        S_00cab970_Router* r = (S_00cab970_Router*)FUN_00c85750();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->heap, this, sizeof(S_00cab970_Entry));
        return m_data[m_iElementCount++];
    }
};
