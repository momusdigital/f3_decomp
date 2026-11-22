#include "f3_common.h"
// src/fallout_shared/teslevcharacter_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teslevcharacter.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "teslevcharacter_unit.h"

// Adjustor thunk for FUN_0050ade0: sub ecx,0x4c; jmp FUN_0050a820.
// The derived class overrides a virtual that both of its bases declare, so the
// secondary base's vtable slot holds a thunk that moves `this` back by the size
// of the primary base.
// sizeof(PrimaryBase) = vptr (4) + 18 int fields (72) = 0x4c.
struct PrimaryBase
{
    virtual void FUN_0050ade0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
};

struct SecondaryBase
{
    virtual void FUN_0050ade0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050ade0
    virtual void FUN_0050ade0();
};

Derived::Derived()
{}
