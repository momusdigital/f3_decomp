// gamebryo2.2/corelibs/nimain/niplane.cpp: NiSphere, NiPlane (3 functions)
#include "niplane_decls.h"

// Constructs a NiPlane with normal set to NiPoint3::ZERO and constant set to 0.0f.
// @fnv 0x00a69940
// pdb: NiPointer<NiAccumulator>::NiPointer<NiAccumulator> | BGSDecalManager.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: NiPlane::NiPlane)
// pdb params: pObject
NiPlane::NiPlane() : normal(NiPoint3::ZERO), constant(0.0f)
{}

// Loads the sphere's center and radius from the given stream.
// @fnv 0x00a69ac0
// pdb: NiSphere::LoadBinary | NiSphere.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void NiSphere::LoadBinary(NiStream& stream)
{
    center.LoadBinary(stream);
    stream.input->Read(&radius);
}

extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
struct FUN_00a69a60_Owner
{
    float m_f0;
    float m_f4;
    float m_f8;
    float m_fC;
    char* FUN_00a69a60(const char* pPrefix);
};
// Allocates a string sized from the prefix length and formats the four floats as "(%g,%g,%g), %g", returning the buffer.
// @fnv 0x00a69a60
// pdb: NiPlane::GetViewerString | NiPlane.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pPrefix
char* FUN_00a69a60_Owner::FUN_00a69a60(const char* pPrefix)
{
    char* pBuffer;
    unsigned int uiPrefixLen;
    uiPrefixLen = strlen(pPrefix);
    pBuffer = (char*)_NiMalloc(uiPrefixLen + 0x38);
    _NiSprintf(pBuffer, uiPrefixLen + 0x38, "(%g,%g,%g), %g", m_f0, m_f4, m_f8, m_fC);
    return pBuffer;
}
