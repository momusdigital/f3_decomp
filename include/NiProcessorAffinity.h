// NiProcessorAffinity: the processor a Gamebryo thread prefers and the processors it may run on.
// Names: FNV360_PDB (NiProcessorAffinity).
#ifndef FNV_NIPROCESSORAFFINITY_H
#define FNV_NIPROCESSORAFFINITY_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiProcessorAffinity
{
  public:
    enum Processor
    {
        PROCESSOR_DONT_CARE = -1
    };

    Processor m_eIdealProcessor;    // +0x0
    unsigned int m_uiAffinityMask;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiProcessorAffinity) == 0x8);
#endif
