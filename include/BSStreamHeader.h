// BSStreamHeader: Bethesda's extra NIF header block (exporter version, author and script names).
// Names: FNV360_PDB (BSStreamHeader).
#ifndef FNV_BSSTREAMHEADER_H
#define FNV_BSSTREAMHEADER_H
#include "layout_support.h"
#pragma pack(push, 4)
class BSStreamHeader
{
  public:
    unsigned int uiVersion;    // +0x0
    char pAuthor[64];          // +0x4
    char pProcessScript[64];   // +0x44
    char pExportScript[64];    // +0x84
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSStreamHeader) == 0xC4);
#endif
