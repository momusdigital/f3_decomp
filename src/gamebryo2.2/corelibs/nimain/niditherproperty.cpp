#include "f3_common.h"
// src/gamebryo2.2/corelibs/nimain/niditherproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niditherproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dc9bc0
// pdb: hkpStiffSpringConstraintData::getType | hkpStiffSpringConstraintData.obj | tesv_win, objopen_prop, low
int __cdecl FUN_00dc9bc0()
{
    return 8;
}

struct NiProperty
{
    void FUN_00a9a640_ctor();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern void* DAT_010a0f6c;

struct CloningProcess;
struct NiCullingProperty : NiProperty
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short unk18;
    void FUN_00a5d7a0(NiCullingProperty*, CloningProcess&);
    NiCullingProperty* FUN_00a9a5f0(CloningProcess&);
};
// Allocates and constructs a copy of this NiCullingProperty, runs FUN_00a5d7a0 on it, copies unk18, and returns the copy.
// @fnv 0x00a9a5f0
// pdb: NiDitherProperty::CreateClone | NiDitherProperty.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kCloning
NiCullingProperty* NiCullingProperty::FUN_00a9a5f0(CloningProcess& process)
{
    NiCullingProperty* copy = (NiCullingProperty*)BSFadeNode::operator new(0x1c);
    if (copy)
    {
        copy->FUN_00a9a640_ctor();
        copy->vtable = &DAT_010a0f6c;
        copy->unk18 = 0;
    }
    else
    {
        copy = 0;
    }
    FUN_00a5d7a0(copy, process);
    copy->unk18 = unk18;
    return copy;
}

template <class T> struct NiTMallocInterface
{
};
template <class T, class I> struct NiTPrimitiveArray
{
    void* unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growth;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
