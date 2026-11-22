#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* DAT_01269cd0;
void* DAT_01269010;

struct FUN_00d68a70_class
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
    int** entries;
    int count;
    int FindKeyIndex(int key);
};
// Scans the entries array for the first entry whose first int equals key and returns its index, or -1 if none match.
// @fnv 0x00d68a70
// pdb: hkpConvexRadiusViewer::findWorld | hkpConvexRadiusViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: world
int FUN_00d68a70_class::FindKeyIndex(int key)
{
    int limit = count;
    int index = 0;
    if (limit > 0)
    {
        int** ppEntry = entries;
        do
        {
            if (**ppEntry == key)
                return index;
            ++index;
            ++ppEntry;
        } while (index < limit);
    }
    return -1;
}

struct D68FC0World
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
    void** m_kActorEntries;
    int m_iActorEntryCount;
};

struct D68FC0Primary
{
    virtual void vfunc00();

    int unk04;
};

struct D68FC0Listener
{
    virtual void FUN_00d68fc0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    D68FC0World* m_pOwningWorld;
};

struct D68FC0Object : D68FC0Primary, D68FC0Listener
{
    void RegisterEntity(void* entity);

    virtual void FUN_00d68fc0();
};

// @fnv 0x00d68fc0
// pdb: hkpConvexRadiusViewer::init | hkpConvexRadiusViewer.obj | fnv360_0822_retail, vtable, medium
void D68FC0Object::FUN_00d68fc0()
{
    if (m_pOwningWorld)
    {
        for (int i = 0; i < m_pOwningWorld->m_iActorEntryCount; i++)
            RegisterEntity(m_pOwningWorld->m_kActorEntries[i]);
    }
}

struct Target
{
    void FUN_00d68e60();
};
struct Outer
{
    void FUN_00d69000();
};
// @fnv 0x00d69000
// pdb: hkpRigidBodyInertiaViewer::worldRemovedCallback | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void Outer::FUN_00d69000()
{
    ((Target*)((char*)this - 0x20))->FUN_00d68e60();
}

struct Base
{
    int FindKeyIndex(int);
    void FUN_00d69010(int);
};
struct Sub
{
    void FUN_00d69160(int);
};
// Calls FindKeyIndex on the Base at this-0x20 with value, and if the result is non-negative passes it to FUN_00d69010.
// @fnv 0x00d69160
// pdb: hkpConvexRadiusViewer::worldRemovedCallback | hkpConvexRadiusViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void Sub::FUN_00d69160(int value)
{
    Base* base = reinterpret_cast<Base*>(reinterpret_cast<char*>(this) - 0x20);
    int result = base->FindKeyIndex(value);
    if (result >= 0)
        base->FUN_00d69010(result);
}

struct Heap
{
    virtual void a();
    virtual void b();
    virtual void free(void*, unsigned short);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Heap* unk10;
};
extern Holder* FUN_00c85750();

extern void* DAT_01269010;

struct FUN_00d68940_target
{
    virtual void vSlot0();
    virtual void vSlot1();
    virtual void vSlot2();
    virtual void vSlot3();
    virtual void vSlot4(void* a, void* b, void* c);
};

struct FUN_00d68940_cls
{
    void DispatchToTarget(char* a1);
};

// Calls vSlot4 on the target object stored 0x14 bytes before this, passing a1+0xf0, a1+0x13 and DAT_01269010.
// @f3 0x009f52e0 (community match, verified in this file)
extern void* DAT_01169828;

// pdb: hkpConvexRadiusViewer::inactiveEntityMovedCallback | hkpConvexRadiusViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: entity
void FUN_00d68940_cls::DispatchToTarget(char* pData)
{
    FUN_00d68940_target* target = *(FUN_00d68940_target**)((char*)this - 0x14);
    target->vSlot4(pData + 0xe0, pData + 0x13, DAT_01169828);
}


struct FUN_00d68aa0_req
{
    int unk00;
    int unk04;
    void* m_08;
    int unk0C;
    void* m_10;
};

struct FUN_00d68aa0_item_list
{
    void* unk00;
    void** m_04;
    int m_08;
};

struct FUN_00d68aa0_mgr
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(void* a, void* b, int c);
};

extern void* DAT_01269010;

struct FUN_00d68aa0_cls
{
    void* unk00;
    void* unk04;
    FUN_00d68aa0_item_list** m_08;

    void RemoveItem(FUN_00d68aa0_req* a1);
};

// @f3 0x009f5440 (community match, verified in this file)
struct FUN_009f5410_cls
{
    int FindKeyIndex(void* key);
};
struct ItemListV
{
    void* unk00;
    void** m_04;
    int m_08;
    int indexOf(void* key) const
    {
        for (int i = 0; i < m_08; i++)
            if (m_04[i] == key)
                return i;
        return -1;
    }
};
static void __forceinline RemoveAt(void**& arr, int& count, int i)
{
    count = count - 1;
    arr[i] = arr[count];
}
// pdb: hkpConvexRadiusViewer::entityRemovedCallback | hkpConvexRadiusViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: entity
void FUN_00d68aa0_cls::RemoveItem(FUN_00d68aa0_req* pRequest)
{
    if (pRequest->m_10 == 0)
        return;
    int idx = ((FUN_009f5410_cls*)((char*)this - 0x28))->FindKeyIndex(pRequest->m_08);
    if (idx < 0)
        return;
    ItemListV* list = (ItemListV*)m_08[idx];
    FUN_00d68aa0_mgr* mgr = *(FUN_00d68aa0_mgr**)((char*)this - 0x10);
    pRequest = (FUN_00d68aa0_req*)((char*)pRequest + 0x13);
    mgr->v05(pRequest, DAT_01169828, 0);
    int i = list->indexOf(pRequest);
    if (i >= 0)
        RemoveAt(list->m_04, list->m_08, i);
}


struct S_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct S_D28
{
    virtual ~S_D28() throw()
    {}
};
struct S_D2c
{
    virtual ~S_D2c() throw()
    {}
};
struct S_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Heap* m10;
    __forceinline S_Heap& heap()
    {
        return *m10;
    }
};
struct S_Arr
{
    void** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * (int)sizeof(void*));
        m_data = 0;
        m_cap = 0x80000000;
    }
};

struct SubObj
{
    virtual void v0();
    virtual void v1(void* p);
};

struct Allocator
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
};

struct PairList
{
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct ListHolder
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
    PairList m_48;
};

struct Record
{
    void* m_pOwnerObject;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_flags0C;
};

void ResizeAudioStream(Allocator* allocator, PairList* list, unsigned int elemSize);

struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ListHolder* m_20;
    int unk24;
    ListHolder** m_28;
    int m_2C;
    void FUN_00c93820(SubObj* p);
    void FUN_00c93920(SubObj* p);
    int unk30;
    ListHolder** m_34;
    int m_38;
};

struct FUN_00d68e60_cls
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
    SubObj m_28;
    SubObj m_2C;
    PairList m_30;

    void FUN_00d68e60(Owner* owner);
};

// @fnv 0x00d68e60
void FUN_00d68e60_cls::FUN_00d68e60(Owner* owner)
{
    owner->FUN_00c93820(this != 0 ? &m_28 : 0);
    owner->FUN_00c93920(this != 0 ? &m_2C : 0);

    Holder* pAllocHolder = FUN_00c85750();
    Record* pRecord = 0;
    Record* pNewRecord = (Record*)((Allocator*)pAllocHolder->unk10)->Alloc(16);
    if (pNewRecord != 0)
    {
        pNewRecord->unk04 = 0;
        pNewRecord->unk08 = 0;
        pNewRecord->m_flags0C = 0x80000000u;
        pRecord = pNewRecord;
    }
    pRecord->m_pOwnerObject = owner;

    PairList* pList = &m_30;
    Holder* holder = FUN_00c85750();
    if (pList->m_uiItemCount == (int)(pList->m_capBits & 0x3fffffffu))
    {
        ResizeAudioStream((Allocator*)holder->unk10, pList, 4);
    }
    unsigned int idx = *(volatile unsigned int*)&pList->m_uiItemCount;
    void** ppData = pList->m_data;
    void** ppSlot = &ppData[idx];
    *ppSlot = pRecord;
    *ppSlot = pRecord;
    pList->m_uiItemCount++;

    for (int i = 0; i < owner->m_2C; i++)
    {
        PairList* pPairList = &owner->m_28[i]->m_48;
        for (int j = 0; j < pPairList->m_uiItemCount; j++)
        {
            m_28.v1(pPairList->m_data[j]);
        }
    }

    for (int i = 0; i < owner->m_38; i++)
    {
        PairList* pPairList = &owner->m_34[i]->m_48;
        for (int j = 0; j < pPairList->m_uiItemCount; j++)
        {
            m_28.v1(pPairList->m_data[j]);
        }
    }

    ListHolder* pExtraHolder = owner->m_20;
    if (pExtraHolder != 0)
    {
        for (int j = 0; j < pExtraHolder->m_48.m_uiItemCount; j++)
        {
            m_28.v1(pExtraHolder->m_48.m_data[j]);
        }
    }
}

static void* DAT_01269018;
static void* DAT_01269014;

struct T68D28
{
    virtual void d28v0();
    T68D28()
    {}
};
struct T68D2c
{
    virtual void d2cv0();
    T68D2c()
    {}
};

struct T68Arr
{
    void** m_data;
    int m_iElementCount;
    unsigned int m_cap;
    T68Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000u)
    {}
};

struct Mem_d65f
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
    virtual void deallocateChunk(void* p, int nbytes) throw();
    virtual void v0C();
    virtual void deallocate(void* p, int nbytes) throw();
};

struct Holder_d65f
{
    int unk00, unk04, unk08, unk0C;
    Mem_d65f* m_pMemoryAllocator;
    Mem_d65f& heap()
    {
        return *m_pMemoryAllocator;
    }
};

struct Router_d65f
{
    static Holder_d65f& __cdecl FUN_00c85750() throw();
};
inline Mem_d65f& getMemory_d65f()
{
    return *Router_d65f::FUN_00c85750().m_pMemoryAllocator;
}

inline void memCpy4_d65f(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d65f
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~hkArray_d65f() throw()
    {
        Mem_d65f& mem = Router_d65f::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            mem.deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d65f(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Listener_d65f;
struct Watch2_d65f
{
    virtual void w00();
};

struct Agent_d65f
{
    void FUN_00c917a0(Listener_d65f* listener);
    void ClearValue(Watch2_d65f* watch);
};

struct Node_d65f
{
    Agent_d65f* m_pCollisionAgent;
    hkArray_d65f<int> m_items;
    static void operator delete(void* p) throw()
    {
        Router_d65f::FUN_00c85750().heap().deallocateChunk(p, sizeof(Node_d65f));
    }
};

struct Base_d65f
{
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
};

struct Listener_d65f
{
    virtual void l00();
};

struct Phantom_d65f : Base_d65f, Listener_d65f, Watch2_d65f
{
    hkArray_d65f<Node_d65f*> m_kNodeCollection;
    void FUN_00d68b20(int index);
    void FUN_00d69010(int index);
};

// Calls FUN_00c917a0 and ClearValue on the node's collision agent, calls FUN_00d68b20, then deletes the node at index and removes it from m_kNodeCollection.
// @fnv 0x00d69010
void Phantom_d65f::FUN_00d69010(int index)
{
    m_kNodeCollection[index]->m_pCollisionAgent->FUN_00c917a0(this);
    m_kNodeCollection[index]->m_pCollisionAgent->ClearValue(this);
    FUN_00d68b20(index);
    delete m_kNodeCollection[index];
    m_kNodeCollection.removeAt(index);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern DWORD DAT_0126835c;
extern void* DAT_01269010;

struct D68970_ProfileRecord
{
    const char* name;
    DWORD tick;
    DWORD unk08;
};

struct D68970_ProfileBuffer
{
    DWORD unk00;
    D68970_ProfileRecord* current;
    DWORD unk08;
    D68970_ProfileRecord* end;
};

struct D68970_Vector
{
    float x, y, z, w;
};
struct __declspec(align(16)) D68970_Output
{
    D68970_Vector rotation0, rotation1, rotation2, translation;
};

struct D68970_TransformObject
{
    void SweepTransform(float time, void* output);
};

struct D68970_Body
{
    DWORD unk00, unk04, unk08, unk0C;
    char unk10, unk11, unk12, displayId;
    DWORD unk14;
    DWORD unk18;
    DWORD unk1C;
    DWORD unk20;
    DWORD unk24;
    DWORD unk28;
    DWORD unk2C;
    DWORD unk30;
    DWORD unk34;
    DWORD unk38;
    DWORD unk3C;
    DWORD unk40;
    DWORD unk44;
    DWORD unk48;
    DWORD unk4C;
    DWORD unk50;
    DWORD unk54;
    DWORD unk58;
    DWORD unk5C;
    DWORD unk60;
    DWORD unk64;
    DWORD unk68;
    DWORD unk6C;
    DWORD unk70;
    DWORD unk74;
    DWORD unk78;
    DWORD unk7C;
    DWORD unk80;
    DWORD unk84;
    DWORD unk88;
    DWORD unk8C;
    DWORD unk90;
    DWORD unk94;
    DWORD unk98;
    DWORD unk9C;
    DWORD unkA0;
    DWORD unkA4;
    DWORD unkA8;
    DWORD unkAC;
    DWORD unkB0;
    DWORD unkB4;
    DWORD unkB8;
    DWORD unkBC;
    DWORD unkC0;
    DWORD unkC4;
    DWORD unkC8;
    DWORD unkCC;
    DWORD unkD0;
    DWORD unkD4;
    DWORD unkD8;
    DWORD unkDC;
    D68970_TransformObject transformObject;
};

struct D68970_BodyIsland
{
    D68970_Body** bodies;
    int bodyCount;
};

struct D68970_Entity
{
    DWORD unk00;
    DWORD unk04;
    DWORD unk08;
    DWORD unk0C;
    DWORD unk10;
    DWORD unk14;
    DWORD unk18;
    DWORD unk1C;
    DWORD unk20;
    DWORD unk24;
    DWORD unk28;
    DWORD unk2C;
    DWORD unk30;
    DWORD unk34;
    DWORD unk38;
    DWORD unk3C;
    DWORD unk40;
    DWORD unk44;
    D68970_BodyIsland islands;
};

struct D68970_Owner
{
    DWORD unk00;
    DWORD unk04;
    DWORD unk08;
    DWORD unk0C;
    DWORD unk10;
    DWORD unk14;
    DWORD unk18;
    DWORD unk1C;
    DWORD unk20;
    DWORD unk24;
    D68970_Entity** entities;
    int entityCount;

    float FUN_00c91020();
};

struct D68970_DisplayBase
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(void* transform, void* id, void* context);
};

struct D68970_Primary
{
    D68970_DisplayBase* display;
    int unk04, unk08, unk0C, unk10;
};
struct D68970_Listener
{
    int unk00;
    void FUN_00d68970(D68970_Owner* owner);
};
struct D68970_Viewer : D68970_Primary, D68970_Listener
{
};

// Sweeps each body's transform and pushes the result to the display, bracketing the work with two profile records.
// @f3 0x009f5310 (community match, verified in this file)
extern int g_stateResult;
struct CpuObject
{
    float FUN_00c91020();
};

// pdb: hkpConvexRadiusViewer::postSimulationCallback | hkpConvexRadiusViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void D68970_Listener::FUN_00d68970(D68970_Owner* owner)
{
    __assume(this != 0);
    HK_TIMER_BEGIN("hkpConvexRadiusViewer", HK_NULL);

    for (int entityIndex = 0; entityIndex < owner->entityCount; ++entityIndex)
    {
        D68970_Entity* entity = owner->entities[entityIndex];
        D68970_BodyIsland* island = &entity->islands;

        for (int bodyIndex = 0; bodyIndex < island->bodyCount; ++bodyIndex)
        {
            D68970_Body* body = island->bodies[bodyIndex];
            float time = ((CpuObject*)owner)->FUN_00c91020();

            D68970_TransformObject* transformObject = (D68970_TransformObject*)((char*)body + 0xd0);
            D68970_Output output;
            transformObject->SweepTransform(time, &output);

            static_cast<D68970_Viewer&>(*this).display->vf10(&output, &body->displayId, (void*)g_stateResult);
        }
    }

    HK_TIMER_END();
}


// sub ecx,0x28; jmp target: MSVC adjustor thunk. PrimaryBase is 0x28 bytes (vptr + 9 ints),
// so the second base sits at +0x28 and the thunk subtracts 0x28 from this.
struct PrimaryBase
{
    virtual void FUN_00d691b0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void FUN_00d691b0();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00d691b0
    virtual void FUN_00d691b0();
};

SpawnedObject::SpawnedObject()
{}

namespace fnv_00d68c00 {

struct S_00d68c00_Heap
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4(void* p, int bytes) throw();
};

struct S_00d68c00_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d68c00_Heap* unk10;
    S_00d68c00_Heap& heap()
    {
        return *unk10;
    }
};

S_00d68c00_Router* __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(S_00d68c00_Heap* heap, void* arr, int elemSize) throw();

}  // namespace fnv_00d68c00

namespace fnv_00d68e00 {
struct hkMemory
{
    virtual void unk0();
    virtual void* allocateChunk(int size);
};

struct hkThreadMemory
{
    char pad[0x10];
    hkMemory* m_pMemoryAllocator;

    void* allocateChunk(int size)
    {
        return m_pMemoryAllocator->allocateChunk(size);
    }
};

extern "C" hkThreadMemory* __cdecl FUN_00c85750();

}  // namespace fnv_00d68e00

struct VObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(void* a, void* b, int c);
};

struct HkArr
{
    void** data;
    int size;
    unsigned int m_iCapacity;
};

struct SpawnItem
{
    int unk00;
    HkArr arr;
};

struct Holder_d68b20
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* volatile m_pAllocator;
};

void __cdecl FUN_00c908c0(void* alloc, void* arr, int n, int elemSize);

struct FUN_00d68b20_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    VObj* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SpawnItem** m_30;

    void FUN_00d68b20(int idx);
};

// Calls v05 on each element of the item at idx, then conditionally calls FUN_00c908c0 on its array and sets the array size to 0.
// @fnv 0x00d68b20
void FUN_00d68b20_cls::FUN_00d68b20(int idx)
{
    SpawnItem* item = m_30[idx];
    for (int i = 0; i < item->arr.size; ++i)
    {
        m_18->v05(item->arr.data[i], DAT_01269010, 0);
    }
    HkArr* a = &item->arr;
    Holder_d68b20* h = (Holder_d68b20*)FUN_00c85750();
    void* alloc = h->m_pAllocator;
    int cap = (int)(a->m_iCapacity & 0x3fffffff);
    if (cap < 0)
    {
        FUN_00c908c0(alloc, a, (cap + cap > 0) ? cap + cap : 0, 4);
    }
    a->size = 0;
}
