// NiTransform: rotation, translation and uniform scale.
// Names: FNV360_PDB (NiTransform). PC layout: 0x34 bytes (NiMatrix3 is 0x24 on PC).
#ifndef FNV_NITRANSFORM_H
#define FNV_NITRANSFORM_H
#include "layout_support.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
#pragma pack(push, 4)
class NiTransform
{
  public:
    NiMatrix3 m_Rotate;     // +0x0
    NiPoint3 m_Translate;   // +0x24
    float m_fScale;         // +0x30
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransform) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_Translate) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_fScale) == 0x30);
#endif
