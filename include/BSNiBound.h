// BSNiBound: Bethesda's NiBound, the type of NiAVObject's world bound.
// Names: FNV360_PDB (BSNiBound : NiBound, 0x10 bytes, no members of its own).
#ifndef FNV_BSNIBOUND_H
#define FNV_BSNIBOUND_H
#include "NiBound.h"
#pragma pack(push, 4)
class BSNiBound : public NiBound
{
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSNiBound) == 0x10);
#endif
