#include "f3_common.h"
// src/fallout/magic/bhktelekinesislistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/bhktelekinesislistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// FUN_00807e00 - MSVC 2008 adjustor thunk (8 bytes):
//
//     sub ecx, 8
//     jmp  0x008078e0
//
// The vftable of a secondary base inside a derived class (the one at
// 0x01079718, RTTI ".?AVbhkTelekinesisListener@@", complete object locator
// offset 8) points at a compiler generated adjustor thunk for the virtual
// that the derived class overrides: the secondary base sub-object starts
// eight bytes into the derived object, so the thunk moves `this' back to the
// derived object and tail-calls the overriding implementation.
//
// The primary base is eight bytes long (its vptr plus one int), which is what
// puts the secondary base at offset 8.  The overriding implementation is only
// declared, never defined, so the jmp stays an undefined external exactly
// like in the image and the checker resolves that relocation from the
// original bytes.

struct bhkTelekinesisListenerBase
{
    bhkTelekinesisListenerBase();
    virtual void* FUN_00807e00(unsigned int flags);
    int unk04;
};

struct bhkTelekinesisListenerSecondary
{
    bhkTelekinesisListenerSecondary();
    virtual void* FUN_00807e00(unsigned int flags);
};

struct bhkTelekinesisListenerDerived : public bhkTelekinesisListenerBase, public bhkTelekinesisListenerSecondary
{
    bhkTelekinesisListenerDerived();
// @fnv 0x00807e00
    virtual void* FUN_00807e00(unsigned int flags);
};

bhkTelekinesisListenerBase::bhkTelekinesisListenerBase()
{}
bhkTelekinesisListenerSecondary::bhkTelekinesisListenerSecondary()
{}
bhkTelekinesisListenerDerived::bhkTelekinesisListenerDerived()
    : bhkTelekinesisListenerBase(), bhkTelekinesisListenerSecondary()
{}
