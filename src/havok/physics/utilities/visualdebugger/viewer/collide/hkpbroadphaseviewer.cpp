#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Container
{
    int ClearValue(void* value);
};
struct Owner
{
    int FUN_00d6a910(Container* container);
};
// Passes a pointer to this+8 (or null when this equals 0x20) to container->ClearValue and returns its result.
// @fnv 0x00d6a910
// pdb: hkpContactPointViewer::worldRemovedCallback | hkpContactPointViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: w
int Owner::FUN_00d6a910(Container* container)
{
    void* value;
    if ((char*)this - 0x20)
        value = (char*)this + 8;
    else
        value = 0;
    return container->ClearValue(value);
}

extern int DAT_01269028;
void FUN_00d6ad00();

extern int DAT_01269028;

struct Target
{
    void FUN_00c93920(void* apArg);
};

struct FUN_00d6a8e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void CallTargetWithSelfOffset(Target* apTarget);
};

// Passes a pointer derived from this (this+8, or null when this-0x20 is null) to apTarget's FUN_00c93920.
// @fnv 0x00d6a8e0
// pdb: hkpContactPointViewer::worldAddedCallback | hkpContactPointViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: w
void FUN_00d6a8e0_cls::CallTargetWithSelfOffset(Target* apTarget)
{
    apTarget->FUN_00c93920(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

// ---------------------------------------------------------------------------
// FUN_00d6a940  (0x00d6a940, 112 bytes) - the constructor of the game's
// hkpBroadphaseViewer.
//
//   8b442404          mov eax,[esp+4]        ; the ctor argument
//   53 56 57         push ebx / esi / edi
//   50                push eax
//   8bf1              mov esi,ecx             ; this -> esi
//   e861230700        call 0xddccb0           ; hkpWorldViewerBase::hkpWorldViewerBase(arg)
//   c746287ccf0c01   mov [esi+0x28],<hkpWorldPostSimulationListener vftable>
//   8d5e28            lea ebx,[esi+0x28]
//   33ff              xor edi,edi
//   c706b4230d01     mov [esi],<hkpBroadphaseViewer vftable>
//   c7460894230d01   mov [esi+8],<hkpBroadphaseViewer vftable>
//   c7462084230d01   mov [esi+0x20],<hkpBroadphaseViewer vftable>
//   c70374230d01     mov [ebx],<hkpBroadphaseViewer vftable>
//   897e2c 897e30     mov [esi+0x2c],edi / mov [esi+0x30],edi
//   c7463400000080   mov [esi+0x34],0x80000000
//   8b4624            mov eax,[esi+0x24]     ; the shape list of the world
//   3bc7 741f         cmp eax,edi / je end
//   397870 7e1a       cmp [eax+0x70],edi / jle end
//   ...loop: for each shape, shape->FUN_00c93920(this+0x28)
//   5f 8bc6 5e 5b     pop edi / mov eax,esi / pop esi / pop ebx
//   c20400            ret 4
//
// The class therefore has four vptr-bearing base subobjects, at complete
// object offsets 0x00, 0x08, 0x20 and 0x28.  Modelling that hierarchy for
// real makes MSVC emit the vftable-initialisation itself, which is the only
// way to get the two vtable stores at 0x28 (the base's own vtable first, the
// derived's per-base vtable second, the second one through the address
// taken in ebx) and the exact order of the initialisations.
// ---------------------------------------------------------------------------

// the object the world keeps at this+0x24: an array of shapes and a count
struct BroadCtx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    void** arr;  // +0x6c
    int count;   // +0x70
};

// the secondary base at 0x28 - the listener the shapes are told about
struct PostSimListener
{
    virtual void ps0();
    virtual void ps1();
    virtual void ps2();
    virtual void ps3();
};

// one shape of the world; 0xc93920 appends a listener to its list at +0x164
struct BroadElem
{
    void FUN_00c93920(PostSimListener* p);
};

// the primary base at 0x00 (its vptr is the one at 0x00)
struct PrimBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int unk04;
};

// the secondary base at 0x08, 0x18 bytes long
struct ProcBase
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// the secondary base at 0x20
struct CtxListenerBase
{
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
};

// 0xddccb0 - hkpWorldViewerBase's constructor; it fills the three vptrs it
// owns and the shape list at 0x24
struct WorldViewerBase : PrimBase, ProcBase, CtxListenerBase
{
    BroadCtx* m_ctx;  // +0x24
    WorldViewerBase(void* a);
};

// hkpBroadphaseViewer itself (the class is named after the function so that
// its constructor's decorated name carries the tag the checker looks for)
struct FUN_00d6a940 : WorldViewerBase, PostSimListener
{
    int unk2c;  // +0x2c
    int unk30;  // +0x30
    int unk34;  // +0x34
    FUN_00d6a940(void* a);

  private:
    ~FUN_00d6a940();  // never defined: keeps a second tagged
                      // symbol out of the object file
};

// @fnv 0x00d6a940
// pdb: hkpBroadphaseViewer::hkpBroadphaseViewer | hkpBroadphaseViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
FUN_00d6a940::FUN_00d6a940(void* a) : WorldViewerBase(a)
{
    // The three flags are written through a pointer: that gives the stores an
    // unknown member displacement, so MSVC may not hoist the load of the
    // shape list (this+0x24) above them - the original keeps that load below
    // the three stores, this source does the same.
    int* q = (int*)((char*)this + 0x2c);
    q[0] = 0;
    q[1] = 0;
    q[2] = (int)0x80000000;
    if (m_ctx)
    {
        for (int i = 0; i < m_ctx->count; i++)
        {
            BroadElem* e = (BroadElem*)m_ctx->arr[i];
            e->FUN_00c93920(this);  // this+0x28: the listener subobject
        }
    }
}

struct AudioAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void FreeData(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct PrimaryBase
{
    virtual void unk00();
    unsigned int unk04;
    ~PrimaryBase();
};

struct SubObject
{
    virtual ~SubObject()
    {}
};

namespace fnv_00d6ad00 {
struct AllocatorIface
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorIface* m_pAllocator;
};
AllocHolder* __cdecl FUN_00c85750();

struct SpawnedObject
{
    int unk00;
    unsigned short m_wSize;
    unsigned short unk06;
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
    int __thiscall Init(int arg);
};

// Allocates a 0x38-byte object from the holder's allocator, sets its size, calls Init(arg), and returns the result plus 8 or 0.
// @fnv 0x00d6ad00
int FUN_00d6ad00(int arg)
{
    AllocHolder* pAllocHolder = FUN_00c85750();
    AllocatorIface* pAllocator = pAllocHolder->m_pAllocator;
    SpawnedObject* pObject = (SpawnedObject*)pAllocator->allocate(0x38);
    pObject->m_wSize = 0x38;
    int iInitResult = pObject->Init(arg);
    return iInitResult != 0 ? iInitResult + 8 : 0;
}
}  // namespace fnv_00d6ad00

namespace fnv_00d6ad70 {
// MSVC adjustor thunk: the primary base occupies 0x20 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00d6ad70();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00d6ad70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d6ad70
    virtual void FUN_00d6ad70();
};

Derived::Derived()
{}
}  // namespace fnv_00d6ad70

namespace fnv_00d6ada0 {
struct S_00d6ada0_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d6ada0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d6ada0_Allocator* m_pStreamAllocator;
    S_00d6ada0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00d6ada0_Router* FUN_00c85750();

struct S_00d6ada0_ReferencedObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void operator delete(void* p, unsigned int)
    {
        S_00d6ada0_ReferencedObject* b = static_cast<S_00d6ada0_ReferencedObject*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
    virtual ~S_00d6ada0_ReferencedObject()
    {}
};

}  // namespace fnv_00d6ada0
