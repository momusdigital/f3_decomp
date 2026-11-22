#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd9380_class
{
    void* FUN_00dd9380(const char* name, void* factory);
};
extern int DAT_01269cd0;
extern int DAT_01268fbc;
void* __cdecl FUN_00d62e20();
// @fnv 0x00d62e60
// pdb: hkpVehicleViewer::registerViewer | hkpVehicleViewer.obj | fnv360_0822_debug, udata, high
// pdb: hkpVehicleViewer::registerViewer | hkpVehicleViewer.obj | fnv360_0822_debug, udata, high (was: RegisterWeldingViewer)
void __cdecl hkpVehicleViewer_registerViewer()
{
    void* result = ((FUN_00dd9380_class*)DAT_01269cd0)->FUN_00dd9380("WeldingViewer", (void*)&FUN_00d62e20);
    DAT_01268fbc = (int)result;
}

struct S_00d62650_B1
{
    virtual void vfn1();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct S_00d62650_B3
{
    virtual void vfn3();
};
struct S_00d62650_Arg
{
    void __thiscall FUN_00c93920(S_00d62650_B3* p);
};
struct S_00d62650_B2
{
    virtual void DispatchToArg(S_00d62650_Arg* arg);
    int unk04;
};
struct S_00d62650_D : S_00d62650_B1, S_00d62650_B2, S_00d62650_B3
{
    virtual void DispatchToArg(S_00d62650_Arg* arg);
};

// Calls FUN_00c93920 on arg, passing this as the argument.
// @fnv 0x00d62650
// pdb: hkpSimulationIslandViewer::worldAddedCallback | hkpSimulationIslandViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void S_00d62650_D::DispatchToArg(S_00d62650_Arg* arg)
{
    arg->FUN_00c93920(this);
}

// hkpWeldingViewer - virtual slot 2 of the base subobject at +0x20.
// Removes the entity pointer held by this subobject from the world's list.
//   this  -> the base subobject (complete object + 0x20)
//   -0x20 -> the complete object
//   +0x08 -> the pointer that is handed to the list (complete object + 0x28)

struct HKWorldList
{
    void IsEntityAdded(void* entity);
};

struct HKConstraint
{
    int unk00;
    int unk04;
    void* unk08;
    void FUN_00d62680(HKWorldList* list);
};

// Passes a pointer to unk08 to the list's add method, or null when the adjusted this pointer is zero.
// @fnv 0x00d62680
// pdb: hkpSimulationIslandViewer::worldRemovedCallback | hkpSimulationIslandViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void HKConstraint::FUN_00d62680(HKWorldList* pWorldList)
{
    pWorldList->IsEntityAdded(((char*)this - 0x20) ? (void*)&unk08 : (void*)0);
}

struct S_00d626b0_S
{
    virtual void s0();
    S_00d626b0_S() throw()
    {}
};

class D62720Listener
{
  public:
    virtual ~D62720Listener() throw()
    {}
};

class D62720Island
{
  public:
    void removeListener(D62720Listener* listener);
};

struct D62720World
{
    int unk00;
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    D62720Island** m_islands;
    int m_iIslandCount;
};

class D62720BaseA
{
  public:
    virtual ~D62720BaseA();

    int unk04;
};

class D62720BaseB
{
  public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D62720BaseC
{
  public:
    virtual void unk00();
};

class D62720Base : public D62720BaseA, public D62720BaseB, public D62720BaseC
{
  public:
    virtual ~D62720Base();

    D62720World* m_pOwningWorld;
};

class FUN_00d62720 : public D62720Base, public D62720Listener
{
  public:
    virtual ~FUN_00d62720() throw();
};

// Destructor that unregisters this listener from every island in the world, if a world is set.
// @f3 0x009f6040 (community match, verified in this file)
#include <windows.h>
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern DWORD DAT_010f3170;

struct FUN_008f6d90_obj
{
    void FUN_008f6d90(void* p, unsigned int n, int tag);
};

// pdb: hkpConstraintViewer::~hkpConstraintViewer | hkpConstraintViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_00d62720::~FUN_00d62720() throw()
{
    if (m_pOwningWorld)
    {
        for (int i = 0; i < m_pOwningWorld->m_iIslandCount; i++)
            m_pOwningWorld->m_islands[i]->removeListener(this);
    }
    int* self = (int*)this;
    if (self[13] & 0x80000000)
        goto done;
    {
        int n = self[13] & 0x3fffffff;
        FUN_008f6d90_obj* heap = (FUN_008f6d90_obj*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90((void*)self[11], (unsigned int)(n * 4), 0x17);
    }
done:
    ;
}


// The factory that creates one hkpWeldingViewer-like record for the physics
// world: it asks the world manager's pool for a 0x2c byte block, stamps the
// block size into the record header and then runs the record's constructor.
struct Viewer;

struct Viewer
{
    int unk00;
    unsigned short unk04;
    void* ctor0d626b0(void* arg);
};

extern "C" void* __cdecl FUN_00c85750();

// Allocates a 0x2c-byte Viewer from the manager's pool, sets its size field, constructs it with arg, and returns a pointer offset by 8 or null.
// @f3 0x009ef7e0 (community match, verified in this file)
#include <windows.h>

extern DWORD DAT_010f3170;

struct R1_Heap
{
    void* __thiscall FUN_008f6d30(int size, int flags);
};

struct R1_Viewer
{
    int unk00;
    unsigned short unk04;
    void* __thiscall FUN_009ef7a0(void* arg);
};

// pdb: hkpWorldMemoryViewer::create | hkpWorldMemoryViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
void* __cdecl FUN_00d62e20_impl(void* arg)
{
    R1_Heap* heap = (R1_Heap*)TlsGetValue(DAT_010f3170);
    R1_Viewer* viewer = (R1_Viewer*)heap->FUN_008f6d30(0x54, 0x35);
    viewer->unk04 = 0x54;
    void* result = viewer->FUN_009ef7a0(arg);
    return result ? (char*)result + 8 : 0;
}


extern int g_D62E80Value;

// @fnv 0x00d62e80
// pdb: Interface::GetDetectionLevel | Interface.obj | fnv360_0822_retail, call_gap, low
int __cdecl FUN_00d62e80()
{
    return g_D62E80Value;
}

namespace fnv_00d62ec0 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d62ec0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d62720();

    FUN_00d62ec0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00d62ec0

// FUN_00d62eb0 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
struct A1_00d62eb0
{
    A1_00d62eb0();
    virtual void FUN_00d62eb0();
    char pad[0x24];
};
struct A2_00d62eb0
{
    A2_00d62eb0();
    virtual void FUN_00d62eb0();
};
struct Own_00d62eb0 : A1_00d62eb0, A2_00d62eb0
{
    Own_00d62eb0();
    virtual void key_fn();
// @fnv 0x00d62eb0
    void FUN_00d62eb0();
};
Own_00d62eb0::Own_00d62eb0()
{}
void Own_00d62eb0::key_fn()
{}
Own_00d62eb0* make_00d62eb0()
{
    static Own_00d62eb0 o;
    return &o;
}
