// NiColor: an RGB color of floats.
// Names: FNV360_PDB (NiColor: r, g, b; LoadBinary, SaveBinary).
#ifndef FNV_NICOLOR_H
#define FNV_NICOLOR_H
#include "layout_support.h"
class NiStream;
#pragma pack(push, 4)
class NiColor
{
  public:
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    char* GetViewerString(const char* pcPrefix) const;

    float r;  // +0x0
    float g;  // +0x4
    float b;  // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiColor) == 0xC);
#endif
