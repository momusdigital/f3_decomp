// fallout_shared/bgsidlecollection.cpp: BGSIdleCollection (1 function)
#include "f3_common.h"
#include "MemoryManager.h"
#include "bgsidlecollection_types_BGSIdleCollection.h"

// @f3 0x0044d5c0 (community match, verified in this file; formerly Calendar::GetGameDayOfWeek, a name contradicted by
// the BGSIdleCollection vtable the body stores, F3_EXE RTTI)
// pdb: BGSIdleCollection::~BGSIdleCollection | BGSIdleCollection.obj | fnv360_0822_retail, call_seq, medium
// Frees the idle array and clears the count.
BGSIdleCollection::~BGSIdleCollection()
{
    g_memoryManager.Deallocate(pIdleArray);
    cIdleCount = 0;
    pIdleArray = 0;
}
