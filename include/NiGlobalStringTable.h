// NiGlobalStringTable: the table of reference-counted, shared strings that NiFixedString handles point into. A handle
// points at the characters; the reference count and the length are the two words before them.
// Names: FNV360_PDB (NiGlobalStringTable, 0822 debug: IncRefCount, DecRefCount, GetRealBufferStart and GetString are
// inline in niglobalstringtable.inl; NULL_STRING, F3 0x00e207a8).
#ifndef FNV_NIGLOBALSTRINGTABLE_H
#define FNV_NIGLOBALSTRINGTABLE_H
#include "layout_support.h"
#include "NiAtomic.h"
#pragma pack(push, 4)
class NiGlobalStringTable
{
  public:
    typedef char* GlobalStringHandle;

    static GlobalStringHandle AddString(const char* pcString);

    static char* GetRealBufferStart(const GlobalStringHandle& kHandle)
    {
        return kHandle - 2 * sizeof(unsigned int);
    }
    static void IncRefCount(GlobalStringHandle& kHandle)
    {
        if (kHandle == NULL_STRING)
            return;
        NiAtomicIncrement(*(unsigned int*)GetRealBufferStart(kHandle));
    }
    static void DecRefCount(GlobalStringHandle& kHandle)
    {
        if (kHandle == NULL_STRING)
            return;
        NiAtomicSubtract(*(unsigned int*)GetRealBufferStart(kHandle));
    }
    static const char* GetString(const GlobalStringHandle& kHandle)
    {
        return kHandle;
    }

    static GlobalStringHandle const NULL_STRING;
};
#pragma pack(pop)
#endif
