// NiTLargeObjectArray: an NiTLargeArray of objects, allocated with new.
// Names: FNV360_PDB (NiTLargeObjectArray<T> : NiTLargeArray<T, NiTNewInterface<T> >).
#ifndef FNV_NITLARGEOBJECTARRAY_H
#define FNV_NITLARGEOBJECTARRAY_H
#include "layout_support.h"
template <class T> class NiTLargeObjectArray : public NiTLargeArray<T, NiTNewInterface<T> >
{
};
FNV_STATIC_ASSERT(sizeof(NiTLargeObjectArray<void*>) == 0x18);
#endif
