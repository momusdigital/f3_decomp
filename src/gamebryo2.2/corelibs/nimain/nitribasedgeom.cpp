// gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp: BSTextureSet, NiGeometry, NiTriBasedGeom (3 functions)
#include "nitribasedgeom_decls.h"
#pragma optimize("", off)
// @fnv 0x0051d190
BSTextureSet::BSTextureSet()
{
    vtable = BSTextureSet_vtable;
}
#pragma optimize("", on)
// Initializes the NiGeometry object by setting model, skin and shader pointers to null.
// @fnv 0x00a80540
// pdb: NiGeometry::NiGeometry | NiGeometry.obj | fnv360_0822_retail, caller_sim, high
NiGeometry::NiGeometry()
{
    model = 0;
    skin = 0;
    shader = 0;
}

#pragma optimize("", off)

class NiMemObject
{
  public:
    static void __cdecl operator delete(void*, size_t);
};

void __fastcall FUN_0051d1c0(void* pThis);

struct Dummy_0051d160
{
    // Calls FUN_0051d1c0 on this, then frees this (0x38 bytes) via NiMemObject::operator delete when bit 0 of flags is set, returning this.
// @fnv 0x0051d160
    void* __thiscall FUN_0051d160(unsigned int flags)
    {
        FUN_0051d1c0(this);
        if ((flags & 1) != 0)
        {
            NiMemObject::operator delete(this, 0x38);
        }
        return this;
    }
};

static void* (__thiscall Dummy_0051d160::*p_0051d160)(unsigned int) = &Dummy_0051d160::FUN_0051d160;
