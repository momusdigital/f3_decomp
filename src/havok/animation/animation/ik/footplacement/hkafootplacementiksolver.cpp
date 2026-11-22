#include "f3_common.h"
// src/havok/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalMgr
{
    void Release(void* apObject);
};

extern "C" GlobalMgr DAT_011f6238;
extern "C" int DAT_010c4b60;

struct FUN_00c74e70_cls
{
    int m_vptr;

    FUN_00c74e70_cls* FUN_00c74e70(unsigned char acFlags);
};

// Sets the object's vtable pointer to DAT_010c4b60 and, when bit 0 of acFlags is set, releases the object through DAT_011f6238, returning this.
// @fnv 0x00c74e70
// pdb: LockFreeMap<TESObjectREFR *,NiPointer<QueuedHelmet> >::LockFreeMapIterator::`scalar deleting destructor' | ModelLoader.obj | fnv360_0822_retail, vtable, medium
FUN_00c74e70_cls* FUN_00c74e70_cls::FUN_00c74e70(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010c4b60;
    if (acFlags & 1)
    {
        DAT_011f6238.Release(this);
    }
    return this;
}

struct CD8810Bool
{
    char m_cBooleanValue;

    CD8810Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

#include <xmmintrin.h>
