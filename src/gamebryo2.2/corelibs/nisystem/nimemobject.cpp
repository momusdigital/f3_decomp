// gamebryo2.2/corelibs/nisystem/nimemobject.cpp: NiPoint2 (2 functions)
#include "f3_common.h"
#include "nimemobject_decls.h"

// Initializes the point's x and y components from the two float arguments.
// @fnv 0x00452dc0
NiPoint2::NiPoint2(float afX, float afY)
{
    x = afX;
    y = afY;
}

#pragma optimize("gsty", on)
#pragma optimize("", off)

struct _NiAllocatorDummy
{
    virtual void v0();
    virtual void v1();
    virtual void Deallocate(void* pvMemory, int aiAllocationType, size_t stSizeInBytes);
};

// pdb: NiMemObject::operator delete[] | NiMemObject.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: pvMem, stElementSize
__pragma(optimize("gsty", on))
// @fnv 0x00aa1490
    void __cdecl FUN_00aa1490(void* apMemory, unsigned int stElementSize)
{
    if (apMemory != 0)
    {
        (*reinterpret_cast<_NiAllocatorDummy**>(DAT_011f6080))->Deallocate(apMemory, 4, static_cast<size_t>(-1));
    }
}
