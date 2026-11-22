#include "f3_common.h"
// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d98300_Entry
{
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    void reset()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

struct FUN_00d979f0_cls : SpawnedBase
{
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;

    FUN_00d979f0_cls* ResetFields() throw();
};

// @fnv 0x00d979f0
// pdb: TESModelList::TESModelList | TESModelList.obj | fnv360_0822_retail, call_seq, medium
FUN_00d979f0_cls* FUN_00d979f0_cls::ResetFields() throw()
{
    this->SpawnedBase::~SpawnedBase();
    m_i04 = 0;
    m_i08 = 0;
    m_i0C = 0;
    m_i10 = 0;
    return this;
}

// Scalar deleting destructor of a small polymorphic Havok helper with an empty destructor.

void __cdecl operator delete(void* pvMem);

class FUN_00d979a0
{
// @fnv 0x00d979a0
  public:
    FUN_00d979a0()
    {}
    virtual ~FUN_00d979a0()
    {}

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    static void operator delete(void*, void*)
    {}

    int m_iData;
};

// Placement construction so the vtable (and with it the deleting destructor) is emitted.
void* D979A0Make(void* pvMem)
{
    return new (pvMem) FUN_00d979a0;
}

struct S00d97bf0_Obj;

struct S00d97bf0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2(int a);

    int m04;
    int m08;
    int m0C;
    int m10;

    int __thiscall FUN_00d97bf0(int a0, int a1, int a2, int a3);
};

struct D98360Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D98360MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D98360Allocator* m_pStreamAllocator;

    D98360Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D98360MemoryRouter& __cdecl FUN_00c85750();

struct D98360Base
{
    virtual ~D98360Base()
    {}

    int unk04;
};

struct FUN_00d98360 : D98360Base
{
    int unk08;
    int unk0C;
    int unk10;

    FUN_00d98360();
    virtual ~FUN_00d98360();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
};
