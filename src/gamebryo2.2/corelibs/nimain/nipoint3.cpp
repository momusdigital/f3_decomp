// gamebryo2.2/corelibs/nimain/nipoint3.cpp: NiColor, NiPoint3 (4 functions)
#include "f3_common.h"
#include "nipoint3_stream.h"
// Reads the r, g and b components of the color from the stream's input.
// @fnv 0x00a59be0
// pdb: NiColor::LoadBinary | NiColor.obj | fnv360_0822_retail, call_seq, high
// pdb params: stream
void NiColor::LoadBinary(NiStream& stream)
{
    stream.input->Read(&r);
    stream.input->Read(&g);
    stream.input->Read(&b);
}
// Writes the color's r, g and b components to the stream's output.
// @fnv 0x00a69780
// pdb: NiColor::SaveBinary | NiColor.obj | fnv360_0822_retail, call_seq, high
// pdb params: stream
void NiColor::SaveBinary(NiStream& stream)
{
    stream.output->Write(&r);
    stream.output->Write(&g);
    stream.output->Write(&b);
}

extern "C" int __cdecl NiSprintf(char*, unsigned int, char const*, ...);
extern "C" void* __cdecl _NiMalloc(unsigned int);
extern "C" unsigned int __cdecl strlen(char const*);

struct NiPoint3
{
    float x;
    float y;
    float z;
    char* __thiscall FUN_00a59af0(const char* pPrefix);
};

// Allocates a buffer sized to the prefix plus 0x40 and formats "%s = (%g,%g,%g)" from the prefix and x, y, z into it, returning the buffer.
// @fnv 0x00a59af0
// pdb: NiPoint3::GetViewerString | NiPoint3.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pPrefix
char* __thiscall NiPoint3::FUN_00a59af0(const char* pPrefix)
{
    unsigned int uiLen = strlen(pPrefix) + 0x40;
    char* pString = (char*)_NiMalloc(uiLen);
    NiSprintf(pString, uiLen, "%s = (%g,%g,%g)", pPrefix, x, y, z);
    return pString;
}

#include <math.h>
void* FUN_00aa1070(unsigned int uiSize);

// Allocates 256 words and stores masked bit patterns from square roots of floats constructed in two ranges.
// @fnv 0x00a59b50
// pdb: NiPoint3::InitSqrtTable | NiPoint3.obj | tesv_win, call_seq, medium
unsigned int* __cdecl BuildSqrtLut()
{
    unsigned int* pLut = (unsigned int*)FUN_00aa1070(0x400);
    for (unsigned int iIndex = 0; iIndex < 0x80; iIndex++)
    {
        float fValue;
        unsigned int* pFloatBits = (unsigned int*)&fValue;
        *pFloatBits = (iIndex | 0x3f80) << 16;
        fValue = sqrt(fValue);
        pLut[iIndex] = *pFloatBits & 0x7fffff;
        *pFloatBits = (iIndex | 0x4000) << 16;
        fValue = sqrt(fValue);
        pLut[iIndex + 0x80] = *pFloatBits & 0x7fffff;
    }
    return pLut;
}
