#include "f3_common.h"
// src/havok/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern "C" void* __cdecl FUN_00c85750();

struct CallbackTarget
{
    void FUN_00c91750(void* apValue);
    void FUN_00c91a70(void* apValue);
};

struct SubEntry
{
    int unk00;

    void FUN_00d9e280(CallbackTarget* apTarget);
};

struct FUN_00d0ae30_cls
{
    int unk00;
    int unk04;
    SubEntry m_08;

    void FUN_00d0ae30(CallbackTarget* apTarget);
};

// @f3 0x006a37a0 (community match, verified in this file)
struct Interface401 { unsigned int value; };
struct Outer401 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void Destroy(unsigned int deleting);
    Interface401 first;
    Interface401 second;
};
struct Target401 {
    void FUN_0090b020(Outer401* object);
    void FUN_0090b960(Interface401* object);
    void hkpEntity_removeEntityActivationListener(Interface401* object);
};
// pdb: bhkTelekinesisListener::entityDeletedCallback | bhkTelekinesisListener.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: hkpTriggerVolume::entityDeletedCallback)
// pdb params: apEntity
void FUN_00d0ae30_cls::FUN_00d0ae30(CallbackTarget* target) {
    Outer401* outer = reinterpret_cast<Outer401*>(reinterpret_cast<char*>(this) - 4);
    Target401* receiver = reinterpret_cast<Target401*>(target);
    receiver->FUN_0090b020(outer);
    receiver->FUN_0090b960(outer ? &outer->first : 0);
    receiver->hkpEntity_removeEntityActivationListener(outer ? &outer->second : 0);
    if (outer)
        outer->Destroy(1);
}


extern int DAT_010cb1e4;
extern int DAT_010cb1c4;

#include <windows.h>

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

// sub ecx,8; jmp target: MSVC adjustor thunk for the SecondaryBase slot of a
// class deriving from two bases; PrimaryBase is 8 bytes (vptr + one int).
struct AdjPrimaryBase
{
    virtual void FUN_00d0b1c0();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void FUN_00d0b1c0();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d0b1c0
    virtual void FUN_00d0b1c0();
};

AdjDerived::AdjDerived()
{}

// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00d0b1d0();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00d0b1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0b1d0
    virtual void FUN_00d0b1d0();
};

Derived::Derived()
{}

namespace fnv_00d0b040 {
struct hkMemory
{
    virtual void unk00();
    virtual void* allocateChunk(int size);
};

struct hkThreadMemory
{
    char pad00[0x10];
    hkMemory* m_pMemoryAllocator;
};

extern "C" hkThreadMemory* __cdecl FUN_00c85750();

}  // namespace fnv_00d0b040
