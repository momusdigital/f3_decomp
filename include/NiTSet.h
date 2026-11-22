// NiTSet: an unordered growable array; NiTPrimitiveSet allocates it with malloc.
// Names: FNV360_PDB (NiTSet<T, Allocator>: m_pBase, m_uiAlloced, m_uiUsed; NiTPrimitiveSet<T>).
#ifndef FNV_NITSET_H
#define FNV_NITSET_H
#include "layout_support.h"
template <class T, class Allocator> class NiTSet
{
  public:
    T* m_pBase;                // +0x0
    unsigned int m_uiAlloced;  // +0x4
    unsigned int m_uiUsed;     // +0x8
};
template <class T> class NiTPrimitiveSet : public NiTSet<T, NiTMallocInterface<T> >
{
};
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet<unsigned int>) == 0xC);
#endif
