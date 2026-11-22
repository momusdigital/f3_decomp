// Gamebryo's atomic reference-count helpers (NiAtomicIncrement, NiAtomicSubtract; FNV360_PDB names). The file name is
// this tree's own: the helpers are shared by NiRefObject and NiGlobalStringTable.
#ifndef FNV_NIATOMIC_H
#define FNV_NIATOMIC_H
#include "layout_support.h"
#ifndef FNV_NI_ATOMIC_DEFINED
#define FNV_NI_ATOMIC_DEFINED
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}
#endif
#endif
