#include "f3_common.h"
// src/havok/common/base/memory/allocator/hkmemoryallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/hkmemoryallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TargetClass
{
    virtual void f0();
    virtual void f1();
    virtual void __fastcall f2(void* a2);

    void __fastcall FUN_00cbf1d0(void* a2);
};

// @fnv 0x00cbf1d0
void __fastcall TargetClass::FUN_00cbf1d0(void* a2)
{
    f2(a2);
}

/*
 * worker/candidate.cpp — DRAFT ONLY.
 * Not compiled, not compared, no MATCH claimed. Parent owns verification.
 *
 * Unit: pack/pack.json symbol FUN_00cbf280, 67 bytes, __thiscall member of a
 * five-slot class, three stack parameters, returns a pointer, cleans 0xC.
 *
 * Every identifier below is a placeholder chosen for readability. The binary
 * carries no type, field or method names. The prose describes what the unit
 * provably does (which values reach which callee) and what that most likely
 * means; the two are kept separate and the guesses are marked as guesses.
 */

extern int DAT_010c3b30;

struct FUN_00cbf1a0_cls
{
    int m_vptr00;

    void FUN_00cbf1a0();
};

// @fnv 0x00cbf1a0
void FUN_00cbf1a0_cls::FUN_00cbf1a0()
{
    m_vptr00 = (int)&DAT_010c3b30;
}

class FUN_00cbf1e0_cls
{
  public:
    virtual void f0();
    virtual void* f1(void* a);

    void FUN_00cbf1e0(void** dest, int count, void* arg);
};

// Calls f1(arg) count times and stores each returned pointer into dest[i].
// @f3 0x008d35c0 (community match, verified in this file)
struct Vt00cbf1e0
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void* s3(void* a, int b);
};

// pdb: bhkWorld::bhkConstraintProjector::SetUseLock | bhkWorld.obj | tesv_win, objrun_open, low
void FUN_00cbf1e0_cls::FUN_00cbf1e0(void** dest, int count, void* arg)
{
    for (int i = 0; i < count; ++i)
    {
        dest[i] = reinterpret_cast<Vt00cbf1e0*>(this)->s3(arg, 0);
    }
}
