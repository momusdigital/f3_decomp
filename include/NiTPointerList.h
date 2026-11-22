// NiTPointerList: Gamebryo's doubly linked list of pointer-sized items, allocated from a shared pool.
// Names: FNV360_PDB (NiTPointerList<T> : NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>).
#ifndef FNV_NITPOINTERLIST_H
#define FNV_NITPOINTERLIST_H
#include "layout_support.h"
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
};
FNV_STATIC_ASSERT(sizeof(NiTPointerList<void*>) == 0xC);
#endif
