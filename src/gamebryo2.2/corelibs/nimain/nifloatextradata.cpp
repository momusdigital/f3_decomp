#include "f3_common.h"
// src/gamebryo2.2/corelibs/nimain/nifloatextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifloatextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiFloatExtraData
{
    void* m_ppVirtualMethodTable;
    void* Destroy(unsigned int flags);
};

extern void* DAT_010a0ec4;
extern void __cdecl FUN_00a7b300();
extern void __cdecl operator delete(void*, unsigned int);

// @fnv 0x00a9a4b0
// pdb: NiFloatExtraData::`scalar deleting destructor' | NiFloatExtraData.obj | fnv360_0822_retail, objrun, high
void* NiFloatExtraData::Destroy(unsigned int flags)
{
    this->m_ppVirtualMethodTable = &DAT_010a0ec4;
    FUN_00a7b300();
    if (flags & 1)
        operator delete(this, 0x10);
    return this;
}

struct NiObject
{
};
struct FUN_00a9a3f0_Class
{
    char _pad[12];
    float m_fValue;
    bool MatchesFloatValue(NiObject* pObject);
};
// Returns true if pObject is non-null and its float at offset 12 equals m_fValue, otherwise false.
// @fnv 0x00a9a3f0
// pdb: NiFloatExtraData::IsEqual | NiFloatExtraData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pObject
bool FUN_00a9a3f0_Class::MatchesFloatValue(NiObject* pObject)
{
    NiFloatExtraData* pExtra = (NiFloatExtraData*)pObject;
    if (!pExtra)
        return false;
    if (m_fValue != *(float*)((char*)pExtra + 12))
        return false;
    return true;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiExtraData
{
    void FUN_00a7b2e0();
    void FUN_00a7b330(void*, void*);
    void* NiFloatExtraData_CreateClone(void*);
};
// @fnv 0x00a9a430
// pdb: NiFloatExtraData::CreateClone | NiFloatExtraData.obj | fnv360_0822_retail, objrun, high
// pdb params: kCloning
// pdb: NiFloatExtraData::CreateClone | NiFloatExtraData.obj | fnv360_0822_retail, objrun, high (was: CloneFloatExtraData)
void* NiExtraData::NiFloatExtraData_CreateClone(void* kCloning)
{
    NiFloatExtraData* pkObject;
    pkObject = (NiFloatExtraData*)BSFadeNode::operator new(0x10);
    if (pkObject)
    {
        ((NiExtraData*)pkObject)->FUN_00a7b2e0();
        *(float*)((char*)pkObject + 0xc) = 0.0f;
        pkObject->m_ppVirtualMethodTable = &DAT_010a0ec4;
    }
    else
    {
        pkObject = 0;
    }
    this->FUN_00a7b330(pkObject, kCloning);
    *(float*)((char*)pkObject + 0xc) = *(float*)((char*)this + 0xc);
    return pkObject;
}

namespace fnv_00a9a480 {
struct NiExtraData
{
    void FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* operator new(unsigned int size);
};

// @fnv 0x00a9a480
// pdb: NiFloatExtraData::CreateObject | NiFloatExtraData.obj | fnv360_0822_retail, objrun + bridge(hash|objrun), high
void* __cdecl NiFloatExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        reinterpret_cast<NiExtraData*>(p)->FUN_00a7b2e0();
        *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0xc) = 0.0f;
        *reinterpret_cast<void**>(p) = &DAT_010a0ec4;
        return p;
    }
    return 0;
}
}  // namespace fnv_00a9a480

namespace fnv_00a9a4e0 {
struct NiStream;
struct NiBinaryStream
{
    void* _00;
    int m_pos;
    int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    int(__cdecl* write)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct NiExtraData
{
    char _pad[0xc];
    void SaveBinary(NiStream&);
};
struct Cls_00a9a4e0 : NiExtraData
{
    float m_fValue;
    void FUN_00a9a4e0(NiStream&);
};
// Calls NiExtraData::SaveBinary then writes the 4-byte m_fValue to the stream and advances its position.
// @fnv 0x00a9a4e0
// pdb: NiSphere::SaveBinary | NiSphere.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void Cls_00a9a4e0::FUN_00a9a4e0(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    NiBinaryStream* __restrict output = stream.m_pBackingStream;
    unsigned int size = 4;
    output->m_pos += output->write(output, &m_fValue, 4, &size, 1);
}
}  // namespace fnv_00a9a4e0
