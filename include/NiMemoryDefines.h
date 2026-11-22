// The Gamebryo heap entry points (FNV360_PDB: _NiMalloc and _NiFree, nisystem/nimemorydefines.cpp; F3 0x0089e810 and
// 0x0089e890).
#ifndef FNV_NIMEMORYDEFINES_H
#define FNV_NIMEMORYDEFINES_H
#include "layout_support.h"
void* _NiMalloc(size_t stSize);
void _NiFree(void* pvMem);
#endif
