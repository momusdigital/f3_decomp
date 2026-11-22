#include "f3_common.h"
// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// hkAlgorithm::less<T>: the empty comparison functor the sort takes by value.
struct LessC852 {};
void __cdecl FUN_00c852c0(void* owner, int a2, int a3, LessC852 cmpLess);
// hkAlgorithm::quickSort(pArr, numElem, cmpLess)
__forceinline void QuickSortC852(void* pArr, int numElem, LessC852 cmpLess)
{
    if (numElem > 1)
    {
        FUN_00c852c0(pArr, 0, numElem - 1, cmpLess);
    }
}

class FUN_00c855f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_10;
    int m_14;

    void FUN_00c855f0();
};

// Sorts the hits (m_10, m_14 of them) with the quicksort and a default less-than functor when there are two or more.
// @fnv 0x00c855f0
// pdb: hkpAllRayHitCollector::sortHits | hkpAllRayHitCollector.obj | fnv360_0822_retail, call_dedup, low
void FUN_00c855f0_cls::FUN_00c855f0()
{
            QuickSortC852(m_10, m_14, LessC852());
}

#include <xmmintrin.h>
