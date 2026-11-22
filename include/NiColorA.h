// NiColorA: an RGBA color of floats.
// Names: FNV360_PDB (NiColorA: r, g, b, a; LoadBinary, SaveBinary).
#ifndef FNV_NICOLORA_H
#define FNV_NICOLORA_H
#include "layout_support.h"
class NiStream;
#pragma pack(push, 4)
class NiColorA
{
  public:
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    char* GetViewerString(const char* pcPrefix) const;

    float r;  // +0x0
    float g;  // +0x4
    float b;  // +0x8
    float a;  // +0xC
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiColorA) == 0x10);
#endif
