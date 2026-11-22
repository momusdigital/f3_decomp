// NiMatrix3: a 3x3 rotation matrix, row-major.
// Names: FNV360_PDB (NiMatrix3). PC layout: nine floats (the Xbox 360 build pads each row to an NiPoint4).
#ifndef FNV_NIMATRIX3_H
#define FNV_NIMATRIX3_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiMatrix3
{
  public:
    float m_pEntry[3][3];  // +0x0

    static const NiMatrix3 ZERO;
    static const NiMatrix3 IDENTITY;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiMatrix3) == 0x24);
#endif
