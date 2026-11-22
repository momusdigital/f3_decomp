#include "f3_common.h"
// src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void removeReference();
};
struct Item : hkReferencedObject
{
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
    void FUN_00d07c80(void* owner);
};
struct Manager
{
    void FUN_00c95800(Item** entries, int count);
};
struct Collection
{
    virtual void slot00();
    virtual void removeItems(Manager* manager);
};
struct AllocatorOwner
{
    int unk00;
    int unk04;
    Collection collection;
    int unk0C;
    int unk10;
    Manager* manager;
    Item* entries[6];
    void hkpBroadPhaseBorder_deactivate();
};
// @f3 0x0098bcc0 (community match, verified in this file)
struct ManagerStub : public Manager
{
    void FUN_009078c0(Item** entries, unsigned short count);
};

struct ItemStub : public Item
{
    void hkpPhantom_removePhantomOverlapListener(int* pValue);
    void FUN_009316f0();
};

struct AllocatorOwnerBody
{
    int unk00;
    int unk04;
    Collection collection;
    int unk0C;
    Manager* m_pManager;
    Item* m_pEntries[6];
};

// pdb: hkpBroadPhaseBorder::deactivate | hkpBroadPhaseBorder.obj | fnv360_0822_retail, vtable, high
// pdb: hkpBroadPhaseBorder::deactivate | hkpBroadPhaseBorder.obj | fnv360_0822_retail, vtable, high (was: ReleaseEntries)
void AllocatorOwner::hkpBroadPhaseBorder_deactivate()
{
    AllocatorOwnerBody* pBody = (AllocatorOwnerBody*)this;
    if (pBody->m_pManager)
    {
        ((ManagerStub*)pBody->m_pManager)->FUN_009078c0(pBody->m_pEntries, 6);
        for (int i = 0; i < 6; ++i)
        {
            ((ItemStub*)pBody->m_pEntries[i])->hkpPhantom_removePhantomOverlapListener(&pBody->unk0C);
            ((ItemStub*)pBody->m_pEntries[i])->FUN_009316f0();
            pBody->m_pEntries[i] = 0;
        }
        pBody->collection.removeItems(pBody->m_pManager);
        pBody->m_pManager = 0;
    }
}


struct DispatchItem;
struct DispatchOwner
{
    void ProcessTarget(bool*, DispatchItem*);
};
struct DispatchItem
{
    unsigned int unknown00;
    unsigned int unknown04;
    DispatchOwner* owner;
    void FUN_00ca8420(unsigned char, unsigned char, unsigned char);
};
struct Dispatcher
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    DispatchOwner* owner;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    int mode;
    void hkpBroadPhaseBorder_maxPositionExceededCallback(DispatchItem* item);
};
// Switches on mode: for modes 0 and 1 calls item->FUN_00ca8420(5,1,0); for mode 2, if item->owner equals owner, calls owner->ProcessTarget(&success, item).
// @f3 0x0098bc40 (community match, verified in this file)
struct RestartDispatchItem;
struct RestartDispatchOwner;
struct RestartDispatchOwner {
    void FUN_009037f0(RestartDispatchItem** output, RestartDispatchItem* item);
};
struct RestartDispatchItem {
    unsigned int unk00, unk04;
    RestartDispatchOwner* owner;
    void hkpRigidBody_setMotionType(unsigned char kind, unsigned char enabled, unsigned char flag);
};
struct RestartDispatchLayout {
    unsigned int unk00, unk04, unk08, unk0c;
    RestartDispatchOwner* owner;
    unsigned int unk14, unk18, unk1c, unk20, unk24, unk28;
    int mode;
    void RestartDispatchItemByMode(RestartDispatchItem* item);
};
// pdb: hkpBroadPhaseBorder::maxPositionExceededCallback | hkpBroadPhaseBorder.obj | fnv360_0822_retail, vtable, high
// pdb params: entity
// pdb: hkpBroadPhaseBorder::maxPositionExceededCallback | hkpBroadPhaseBorder.obj | fnv360_0822_retail, vtable, high (was: DispatchItemByMode)
void Dispatcher::hkpBroadPhaseBorder_maxPositionExceededCallback(DispatchItem* item) {
    RestartDispatchLayout* layout = reinterpret_cast<RestartDispatchLayout*>(this);
    RestartDispatchItem* target = reinterpret_cast<RestartDispatchItem*>(item);
    switch (layout->mode) {
    case 0:
        target->hkpRigidBody_setMotionType(7, 1, 0);
        break;
    case 1:
        target->hkpRigidBody_setMotionType(7, 1, 0);
        break;
    case 2:
        layout->owner->FUN_009037f0(reinterpret_cast<RestartDispatchItem**>(&item), target);
        break;
    }
}


struct S_00e10760_Item;
typedef bool (*S_00e10760_Less)(S_00e10760_Item* a, S_00e10760_Item* b);

struct D0B630Entity;

class D0B630Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(D0B630Entity* entity);

    int unk04;
    int unk08;
    int unk0C;
};

class D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);
};

class D0B630Collector : public D0B630Primary, public D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);

    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    D0B630Entity** m_deferred;
    int m_numDeferred;
};

// @f3 0x00be9ba0 (community match, verified in this file)
struct Entity518 {
    virtual void __stdcall slot00();virtual void __stdcall slot04();virtual void __stdcall Release();
    virtual void __stdcall slot0c();virtual void __stdcall slot10();virtual void __stdcall slot14();
    virtual void __stdcall slot18();virtual void __stdcall slot1c();virtual void __stdcall Finish();
};
typedef void (__cdecl* Callback518)(void*,void*);
void __cdecl FUN_00be9900(void*,void*);
struct Source518 {
    virtual void __stdcall slot00();virtual void __stdcall slot04();
    virtual void __stdcall slot08();virtual void __stdcall slot0c();
    virtual void __stdcall Flush(int,Callback518,void*,bool);
};
struct ResetView518 {Entity518* initial[10];unsigned char workspace[0x500];};
union Storage518 {Entity518* deferred[1594];ResetView518 reset;};
void __cdecl FUN_00c00610(void*,int,unsigned int);
struct NativeCollector1486 {
    void* vtable;
    unsigned int flags;Source518* source;Storage518 storage;int count;
};
void D0B630Collector::FlushDeferredEntities(const void* dispatchWord) {
    NativeCollector1486* self=reinterpret_cast<NativeCollector1486*>(reinterpret_cast<char*>(&unk14)-sizeof(void*));
    if(static_cast<unsigned char>(reinterpret_cast<unsigned int>(dispatchWord))) {
        self->flags|=1;
        self->source->Flush(0,FUN_00be9900,self,true);
        if(self->count==0) {self->flags&=~1u;return;}
    } else {
        for(int i=0;i<self->count;++i) {self->storage.deferred[i]->Finish();self->storage.deferred[i]->Release();}
        self->flags&=~1u;self->count=0;
        FUN_00c00610(self->storage.reset.workspace,0,0x500);
    }
}


struct D0B6A0Allocator;

struct D0B6A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0B6A0Allocator* m_pStreamAllocator;

    D0B6A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D0B6A0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D0B6A0Entity
{
    void RetainReference() const;
};

struct D0B6A0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};

struct D0B6A0EntityArray
{
    D0B6A0Entity** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    static void construct(D0B6A0Entity** p, int n, D0B6A0Entity* const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    __forceinline void AddBack(D0B6A0Entity* const& e)
    {
        D0B6A0Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D0B6A0Entity*));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

namespace fnv_00d0bb20 {

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();

extern int DAT_010ccf7c;
extern int DAT_010c925c;
extern int DAT_010cb1c4;
extern int DAT_0102e388;

static inline void ResetBaseVptrs(int* vptrs)
{
    vptrs[4] = (int)&DAT_010ccf7c;
    vptrs[3] = (int)&DAT_010c925c;
    vptrs[2] = (int)&DAT_010cb1c4;
    vptrs[0] = (int)&DAT_0102e388;
}

}  // namespace fnv_00d0bb20

// @fnv 0x00d0b520
// pdb: hkpKeyframedRigidMotion::setMassInv | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: mInv
void __stdcall FUN_00d0b520(int)
{}

// hkpBroadPhaseBorder (the RTTI name in the image) has one primary base and
// several secondary bases; all of them declare the same virtual function and
// the border class overrides it.  MSVC 2008 builds a per-base vftable for
// every secondary base, and the slot of the overridden virtual points at a
// compiler generated adjustor thunk that moves `this' from the secondary base
// back to the border object.  This is the thunk of the base that sits eight
// bytes into the object, so it steps `this' back by eight and jumps to the
// overriding implementation.
//
// The virtual itself is deliberately left undefined: the thunk then jumps to
// an undefined external just like in the image, and the checker resolves that
// relocation from the original bytes instead of comparing a second function.
struct hkBroadPhasePrimary
{
    hkBroadPhasePrimary();
    virtual void FUN_00d0bbc0(int flag);
    int unk04;
};

struct hkBroadPhaseSecondary
{
    hkBroadPhaseSecondary();
    virtual void FUN_00d0bbc0(int flag);
};

struct hkBroadPhaseBorder : public hkBroadPhasePrimary, public hkBroadPhaseSecondary
{
    hkBroadPhaseBorder();
// @fnv 0x00d0bbc0
    virtual void FUN_00d0bbc0(int flag);
};

hkBroadPhasePrimary::hkBroadPhasePrimary()
{}
hkBroadPhaseSecondary::hkBroadPhaseSecondary()
{}
hkBroadPhaseBorder::hkBroadPhaseBorder() : hkBroadPhasePrimary(), hkBroadPhaseSecondary()
{}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00d0bbe0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d0bbe0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0bbe0
    virtual void FUN_00d0bbe0();
};

Derived::Derived()
{}

namespace fnv_00d0bbf0 {
struct Allocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Deallocate(void*, unsigned short);
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};

extern "C" Manager* __cdecl FUN_00c85750();

struct FUN_00d0bbf0
{
    __declspec(noinline) virtual ~FUN_00d0bbf0();
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    static void operator delete(void* object)
    {
        Manager* manager = FUN_00c85750();
        manager->allocator->Deallocate(object, ((FUN_00d0bbf0*)object)->unk04);
    }
};

// Empty destructor; the class's operator delete returns the block to the allocator using the size stored in unk04.
// @fnv 0x00d0bbf0
FUN_00d0bbf0::~FUN_00d0bbf0()
{}
}  // namespace fnv_00d0bbf0
