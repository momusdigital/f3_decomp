#include "f3_common.h"
// src/havok/physics/dynamics/action/hkpunaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpunaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpUnaryAction.h"

struct FUN_00c97510
{
    void ProcessPointer(void*);
};

struct FUN_00d2b1f0
{
    char m0[8];
    FUN_00c97510* m1;
    void EntityRemovedCallback(int);
};

// @fnv 0x00d2b1f0
// pdb: hkpUnaryAction::entityRemovedCallback | hkpUnaryAction.obj | fnv360_0822_retail, vtable, high
// pdb params: entity
void FUN_00d2b1f0::EntityRemovedCallback(int)
{
    if (m1)
        m1->ProcessPointer(this);
}

struct DDCC60World
{
    void removeReference();
};

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

struct FUN_00d2b2b0_class
{
    void* vptr;
    unsigned char padding[0x10];
    S_00d49310_Lock lock;
    DDCC60World* world;

    void FUN_00d2b2b0();
};

// Resets the vtable, releases the world reference if present, then destroys the lock and resets the vtable again.
// @f3 0x004d8840 (community match, verified in this file)
struct FUN_004d8740_elem
{
    void FUN_004d8740();
};

struct FUN_00433530_mgr
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
    FUN_004d8740_elem** m_arr;
    unsigned int FUN_00433530();
};

extern FUN_00433530_mgr* DAT_0107a0d8;

// pdb: TESObjectCELL::ForceLODFadeInLoadedCells | TESObjectCELL.obj | fnv360_0822_retail, caller_sim, low
void FUN_00d2b2b0_class::FUN_00d2b2b0()
{
    for (unsigned int i = 0; i < DAT_0107a0d8->FUN_00433530(); i++)
    {
        FUN_004d8740_elem* e = DAT_0107a0d8->m_arr[i];
        if (e)
            e->FUN_004d8740();
    }
}


void FUN_00d2b2b0();

class hkpWorld;

class hkpEntity : public hkReferencedObject
{
  public:
    void RetainReference();
    void removeReference();
};

class hkpWorld
{
  public:
    void RemoveActionFromEntity(hkpUnaryAction* action, hkpEntity* entity);
    void hkpWorld_attachActionToEntity(hkpUnaryAction* action, hkpEntity* entity);
};

class UnaryActionHelper : public hkpUnaryAction
{
  public:
    void SetEntity(hkpEntity* entity);
};

// @fnv 0x00d2b210
// pdb: hkpBinaryAction::setEntityA | hkpBinaryAction.obj | fnv360_0822_retail, objrun, high
// pdb params: entityA
void UnaryActionHelper::SetEntity(hkpEntity* entity)
{
    if (m_pEntity)
    {
        if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
        {
            world->RemoveActionFromEntity(this, m_pEntity);
        }
        m_pEntity->removeReference();
        m_pEntity = 0;
    }
    m_pEntity = entity;
    m_pEntity->RetainReference();
    if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
    {
        world->hkpWorld_attachActionToEntity(this, m_pEntity);
    }
}

class hkMemoryAllocatorXd2b2f0;

struct hkMemoryRouterXd2b2f0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXd2b2f0* m_pStreamAllocator;
    hkMemoryAllocatorXd2b2f0& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterXd2b2f0& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyXd2b2f0(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayXd2b2f0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorXd2b2f0& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyXd2b2f0(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

// @f3twin 0x009ae940 of 0x00979da0
struct F3Twin_009ae940 : public UnaryActionHelper { void hkpUnaryAction_setEntity(hkpEntity* entity) ; };
// pdb: hkpUnaryAction::setEntity | hkpUnaryAction.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void F3Twin_009ae940::hkpUnaryAction_setEntity(hkpEntity* entity) 
{
    if (m_pEntity)
    {
        if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
        {
            world->RemoveActionFromEntity(this, m_pEntity);
        }
        m_pEntity->removeReference();
        m_pEntity = 0;
    }
    m_pEntity = entity;
    m_pEntity->RetainReference();
    if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
    {
        world->hkpWorld_attachActionToEntity(this, m_pEntity);
    }
}
