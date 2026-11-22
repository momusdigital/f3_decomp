// NiTPrimitiveArray: an NiTArray of plain values, allocated with malloc.
// Names: FNV360_PDB (NiTPrimitiveArray<T> : NiTArray<T, NiTMallocInterface<T> >; NiTArray::SetSize, SetAt, SetAtGrow, Add).
#ifndef FNV_NITPRIMITIVEARRAY_H
#define FNV_NITPRIMITIVEARRAY_H
#include "layout_support.h"
// The members Gamebryo declares on NiTArray are declared here: layout_support.h's NiTArray is shared by units whose
// code changes when it gains members.
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= this->m_usMaxSize)
            SetSize(uiIndex + this->m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(this->m_usSize, element);
    }
};
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray<void*>) == 0x10);
#endif
