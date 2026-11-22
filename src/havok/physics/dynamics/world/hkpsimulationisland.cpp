#include "f3_common.h"
// src/havok/physics/dynamics/world/hkpsimulationisland.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpsimulationisland.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d070c0_Inner
{
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00d070c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00d070c0_Inner* unk14;
};

void __cdecl FUN_00cb3c80(void* a, S_00d070c0* obj);

// @fnv 0x00d070c0
void __stdcall FUN_00d070c0(S_00d070c0* obj)
{
    FUN_00cb3c80(obj->unk14->unk08, obj);
}

struct Holder
{
    int unk00;
    int unk04;
    void* m_pFlagTarget;
};

struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Holder* m_pHolder;
};

void __cdecl FUN_00cb3da0(void* apTarget, Owner* apOwner);

// @fnv 0x00d070e0
// pdb: hkpSimulationIsland::removeConstraintFromCriticalLockedIsland | hkpSimulationIsland.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpSimulationIsland_removeConstraintFromCriticalLockedIsland(Owner* apOwner)
{
    FUN_00cb3da0(apOwner->m_pHolder->m_pFlagTarget, apOwner);
}

struct FUN_00d07130Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct SaveBuffer
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
    unsigned char unk24;
    unsigned char flags;
    unsigned short unk26;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    FUN_00d07130Arg** entries;
    int count;
    void RemoveEntry(FUN_00d07130Arg* value);
};
// Clears the matching entry pointer in entries, zeroes the value's unk0c, and updates flags.
// @fnv 0x00d07130
// pdb: hkpSimulationIsland::removeAction | hkpSimulationIsland.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: act
void SaveBuffer::RemoveEntry(FUN_00d07130Arg* apEntry)
{
    int length = count;
    int index = 0;
    if (length > 0)
    {
        FUN_00d07130Arg** current = entries;
        do
        {
            if (*current == apEntry)
                goto found;
            ++index;
            ++current;
        } while (index < length);
    }
    index = -1;
found:
    entries[index] = 0;
    apEntry->unk0c = 0;
    flags = (flags & 0xdd) | 0x11;
}

struct FUN_00d07180_s
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int MergeFrom(FUN_00d07180_s* other);
};
// Merges another instance into this one: takes the larger unk08, adds unk0c and unk10, adds unk14 and returns the other's unk14.
// @fnv 0x00d07180
// pdb: hkpSimulationIsland::mergeConstraintInfo | hkpSimulationIsland.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: other
int FUN_00d07180_s::MergeFrom(FUN_00d07180_s* other)
{
    int incoming = other->unk08;
    int current = unk08;
    if (current > incoming)
        incoming = current;
    unk08 = incoming;
    unk0c += other->unk0c;
    unk10 += other->unk10;
    int last = other->unk14;
    unk14 += last;
    return last;
}

struct S_00d071b0_Item
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned short m_usIndex;
    unsigned short unkAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
};
struct S_00d071b0_Array
{
    S_00d071b0_Item** m_ppItems;
    unsigned int m_uiCount;
    S_00d071b0_Item* GetAt(unsigned int i) const
    {
        return m_ppItems[i];
    }
    void SetAt(unsigned int i, S_00d071b0_Item* p)
    {
        m_ppItems[i] = p;
    }
    unsigned int GetSize() const
    {
        return m_uiCount;
    }
    void Remove(S_00d071b0_Item* pItem)
    {
        m_ppItems[pItem->m_usIndex] = m_ppItems[m_uiCount - 1];
        m_ppItems[pItem->m_usIndex]->m_usIndex = pItem->m_usIndex;
        m_uiCount--;
    }
};
struct S_00d071b0
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
    unsigned char unk24;
    unsigned char m_ucFlags;
    unsigned short unk26;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    S_00d071b0_Array m_kUnsortedGeometryList;
    void RemoveItem(S_00d071b0_Item* pItem);
};
// Removes pItem from the item array, clears its unkCC and sets m_usIndex to 0xffff, then updates m_ucFlags.
// @f3 0x0098adc0 (community match, verified in this file)
struct S_00d071b0_ItemB
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    unsigned short m_usIndex;
    unsigned short unk96;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
};

// pdb: hkpSimulationIsland::internalRemoveEntity | hkpSimulationIsland.obj | fnv360_0822_retail, call_seq, high
// pdb params: entity
void S_00d071b0::RemoveItem(S_00d071b0_Item* pItem)
{
    S_00d071b0_Item** arr = *(S_00d071b0_Item** volatile*)&m_kUnsortedGeometryList.m_ppItems;
    S_00d071b0_ItemB* pB = *(S_00d071b0_ItemB* volatile*)&pItem;
    unsigned int count = m_kUnsortedGeometryList.m_uiCount;
    arr[pB->m_usIndex] = arr[count - 1];
    ((S_00d071b0_ItemB*)m_kUnsortedGeometryList.GetAt(pB->m_usIndex))->m_usIndex = pB->m_usIndex;
    m_kUnsortedGeometryList.m_uiCount--;
    pB->unkB8 = 0;
    pB->m_usIndex = 0xffff;
    m_ucFlags = (m_ucFlags & ~2) | 1;
}


struct D077D0MemoryRouter
{
    char* m_stackCurrent;

    void* stackAllocInts(int numInts)
    {
        char* p = m_stackCurrent;
        m_stackCurrent = p + ((numInts * 4 + 127) & ~127);
        return p;
    }
    void stackFree(void* p)
    {
        m_stackCurrent = (char*)p;
    }
};

extern "C" D077D0MemoryRouter& __cdecl FUN_00c85750();

struct GlobalObjectO2_00d472a0
{
};
extern GlobalObjectO2_00d472a0 g_012687cc;
// @fnv 0x00d078d0
// pdb: bhkCharControllerShape::GetRTTI | bhkCharControllerShape.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
GlobalObjectO2_00d472a0* bhkCharControllerShape_GetRTTI()
{
    return &g_012687cc;
}

// FUN_00d07100: OR a flag byte into a sub-object's flags field.
// Sub-object pointer lives at +0x30 of the owner; flags byte at +0x12 of it.

struct S_00d074c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00d074c0_Router
{
    int unk00, unk04, unk08, unk0C;
    S_00d074c0_Heap* unk10;
    static S_00d074c0_Router& GetMonitorStream();
    S_00d074c0_Heap& heap()
    {
        return *unk10;
    }
};

template <class T> struct S_00d074c0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(S_00d074c0_Heap& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00d074c0_Array() throw()
    {
        _clearAndDeallocate(S_00d074c0_Router::GetMonitorStream().heap());
    }
};

template <class T, int N> struct S_00d074c0_InplaceArray : S_00d074c0_Array<T>
{
    T m_kStorage[N];
    S_00d074c0_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
    ~S_00d074c0_InplaceArray() throw()
    {}
};

struct S_00d074c0_Entity;
struct S_00d074c0_Collidable
{
    int unk00, unk04, unk08, unk0C;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};
struct S_00d074c0_CollisionEntry
{
    void* m_pAgentEntry;
    S_00d074c0_Collidable* m_pCollidable;
};
struct S_00d074c0_ConstraintInternal
{
    int unk00;
    S_00d074c0_Entity* m_kActorEntries[2];
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct S_00d074c0_Entity
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
    S_00d074c0_Array<S_00d074c0_CollisionEntry> m_kCollisionEntries;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned short m_usStorageIndex;
    unsigned short unkAA;
    S_00d074c0_ConstraintInternal* m_constraintsData;
    unsigned short m_constraintsSize;
    unsigned short m_constraintsCap;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_bFlag;
    unsigned char unkE9;
    unsigned short unkEA;
    bool isFixed() const
    {
        return m_bFlag == 5;
    }
};
struct S_00d074c0_FixedArray
{
    int* m_data;
};
struct S_00d074c0_UnionFind
{
    S_00d074c0_FixedArray* m_pParentArray;
    int m_iNodeCount;
    void Union(int i, int j) throw();
    bool isOneGroup() const
    {
        return m_pParentArray->m_data[0] == -m_iNodeCount;
    }
};

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt {
AudioHolder* __cdecl FUN_00c85750();
}
void __cdecl ResizeAudioStream(AudioAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);

struct PointerList
{
    void** m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct FUN_00d07470_cls;

struct ListItem
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d07470_cls* m_pSharedOwner;
};

struct FUN_00d07470_cls
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
    PointerList m_kNode;

    void AddItem(ListItem* apItem);
};

namespace fnv_00d07720 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt {
AudioHolder* __cdecl FUN_00c85750() throw();
}
extern int DAT_010ccf28;

}  // namespace fnv_00d07720

namespace fnv_00d078e0 {
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

namespace fnvc_adapt {
AudioHolder* __cdecl FUN_00c85750() throw();
}

struct FUN_00d078e0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void ResetArrays();

    FUN_00d078e0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00d078e0

// SaveIsland

extern const void* DAT_010ccf28[];  // hkpSimulationIsland vftable (not in the symbols DB)

struct hkReferencedObjectQ
{
    const void* m_vft;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkReferencedObjectQ() : m_sReferenceCount(1)
    {}
};

struct hkpConstraintInfoQ
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
};

struct hkpConstraintOwnerQ : hkReferencedObjectQ
{
    hkpConstraintInfoQ m_kConstraintInfo;
};

struct hkMultiThreadCheckQ
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;
    hkMultiThreadCheckQ()
    {
        m_uiThreadId = 0xfffffff1;
        m_usMarkedForWrite = 0x8000;
    }
};

struct hkpWorldQ;
struct hkpAgentNnSectorQ;

template <typename T> struct hkArrayQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayQ() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    hkArrayQ(T* buffer, int size, int capacity) : m_data(buffer), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}
};

template <typename T, int N> struct hkInplaceArrayQ : hkArrayQ<T>
{
    T m_kStorage[N];
    hkInplaceArrayQ(int size = 0) : hkArrayQ<T>(m_kStorage, size, N)
    {}
};

struct hkpAgentNnTrackQ
{
    unsigned int m_iBytesUsedInLastSector;
    hkInplaceArrayQ<hkpAgentNnSectorQ*, 1> m_kSectors;
    hkpAgentNnTrackQ()
    {
        m_iBytesUsedInLastSector = 0x200;
    }
};

struct IslandBaseQ : hkpConstraintOwnerQ
{
    hkpWorldQ* m_pOwningWorld;
    int m_iConstraintCount;
    unsigned short m_usStorageIndex;
    unsigned short m_usDirtyListIndex;
    unsigned char m_ucSplitCheckFrameCounter;
    unsigned char m_bSplitCheckRequested : 2;
    unsigned char m_isSparse : 2;
    unsigned char m_bActionListCleanupNeeded : 2;
    unsigned char m_bAllowIslandLocking : 2;
    unsigned char m_ucMultiThreadCheckFlags;
    unsigned char m_bActiveMark;
    IslandBaseQ(hkpWorldQ* world) : m_pOwningWorld(world), m_usDirtyListIndex(0xffff)
    {
        m_vft = DAT_010ccf28;
        m_ucMultiThreadCheckFlags = 5;
        m_bSplitCheckRequested = 0;
        m_bActionListCleanupNeeded = 0;
    }
};

namespace fnv_00d07420 {
// FUN_00d07420: append a pointer to a list owned by this object, growing via the global allocator.

struct GlobalHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_alloc;  // +0x10
};

GlobalHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* list, unsigned int n);

}  // namespace fnv_00d07420

// @f3 0x0098b230 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0098b230 {
// 0x0098b230: simulation island, "is fully connected" test over a union-find.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace N0098b230 {

struct hkBool
{
    char m_bool;
    hkBool(bool b)
    {
        m_bool = b ? 1 : 0;
    }
    hkBool(const hkBool& other)
    {
        m_bool = other.m_bool;
    }
};

struct hkThreadMemory
{
    void FUN_008f6d90(void* data, int byteSize, int memoryClass) throw();
    static hkThreadMemory& getInstance()
    {
        return *static_cast<hkThreadMemory*>(TlsGetValue(DAT_010f3170));
    }
};

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    hkArray(T* ptr, int size, int capacity) : m_data(ptr), m_size(size), m_capacityAndFlags(capacity | 0x80000000) {}
    ~hkArray() { releaseMemory(); }
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    void clear() { m_size = 0; }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }
};

template <class T, unsigned N> struct hkInplaceArray : hkArray<T>
{
    hkInplaceArray() : hkArray<T>(m_storage, 0, N) {}
    T m_storage[N];
};

struct hkpCollidable
{
    int m_unk00, m_unk04, m_unk08, m_unk0C;
    signed char m_ownerOffset;
    void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_ownerOffset); }
};

struct CollisionEntry
{
    void* m_agentEntry;
    hkpCollidable* m_partner;
};

struct hkpLinkedCollidable : hkpCollidable
{
    int m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C, m_unk30, m_unk34, m_unk38, m_unk3C, m_unk40,
        m_unk44, m_unk48;
    hkArray<CollisionEntry> m_collisionEntries;
};

struct hkpEntity;

struct hkConstraintInternal
{
    int m_unk00;
    hkpEntity* m_entities[2];
    int m_unk0C, m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C;
};

struct ConstraintMasters
{
    hkConstraintInternal* m_data;
    unsigned short m_size;
    unsigned short m_capacity;
    int getSize() const { return m_size; }
    hkConstraintInternal& operator[](int i) { return m_data[i]; }
};

struct hkpEntity
{
    int m_unk00, m_unk04, m_unk08, m_unk0C;
    hkpLinkedCollidable m_collidable;
    int m_unk68, m_unk6C, m_unk70, m_unk74, m_unk78, m_unk7C, m_unk80, m_unk84, m_unk88, m_unk8C, m_unk90;
    unsigned short m_storageIndex;
    unsigned short m_unk96;
    ConstraintMasters m_constraintsMaster;
    int m_unkA0, m_unkA4, m_unkA8, m_unkAC, m_unkB0, m_unkB4, m_unkB8, m_unkBC, m_unkC0, m_unkC4, m_unkC8, m_unkCC,
        m_unkD0, m_unkD4;
    unsigned char m_motionType;

    const hkpLinkedCollidable* getLinkedCollidable() const { return &m_collidable; }
    bool isFixed() const { return m_motionType == 7; }
};

struct hkpAction
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void getEntities(hkArray<hkpEntity*>& entitiesOut) throw();
};

struct hkFixedArray
{
    int* m_data;
};

struct hkUnionFind
{
    hkFixedArray* m_parents;
    int m_numNodes;
    void FUN_009ad2b0(int i, int j) throw();
    bool isOneGroup() const { return m_parents->m_data[0] == -m_numNodes; }
};

struct hkpSimulationIsland
{
    int m_unk00, m_unk04, m_unk08, m_unk0C, m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C,
        m_unk30, m_unk34;
    hkArray<hkpAction*> m_actions;
    int m_unk44;
    hkArray<hkpEntity*> m_entities;
};

}

using namespace N0098b230;

struct S0098b230_Island
{
    hkBool hkpSimulationIsland_isFullyConnected(hkUnionFind& unionFind) throw();
};

// pdb: hkpSimulationIsland::isFullyConnected | hkpSimulationIsland.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_gap) + skyrim(call_gap_sim), high
hkBool S0098b230_Island::hkpSimulationIsland_isFullyConnected(hkUnionFind& unionFind) throw()
{
    hkpSimulationIsland* island = reinterpret_cast<hkpSimulationIsland*>(this);

    {
        for (int e = 0; e < island->m_entities.getSize(); e++)
        {
            const hkpLinkedCollidable* lc = island->m_entities[e]->getLinkedCollidable();
            for (int i = 0; i < lc->m_collisionEntries.getSize(); i++)
            {
                hkpEntity* other = static_cast<hkpEntity*>(lc->m_collisionEntries[i].m_partner->getOwner());
                if (!other->isFixed())
                {
                    unionFind.FUN_009ad2b0(e, other->m_storageIndex);
                    if (unionFind.isOneGroup())
                    {
                        return hkBool(true);
                    }
                }
            }
        }
    }
    {
        for (int e = 0; e < island->m_entities.getSize(); e++)
        {
            hkpEntity* entity = island->m_entities[e];
            for (int c = 0; c < entity->m_constraintsMaster.getSize(); c++)
            {
                hkConstraintInternal& ci = entity->m_constraintsMaster[c];
                if (!ci.m_entities[0]->isFixed() && !ci.m_entities[1]->isFixed())
                {
                    unionFind.FUN_009ad2b0(ci.m_entities[0]->m_storageIndex, ci.m_entities[1]->m_storageIndex);
                    if (unionFind.isOneGroup())
                    {
                        return hkBool(true);
                    }
                }
            }
        }
    }
    {
        hkInplaceArray<hkpEntity*, 10> entities;
        for (int a = 0; a < island->m_actions.getSize(); a++)
        {
            if (island->m_actions[a])
            {
                entities.clear();
                island->m_actions[a]->getEntities(entities);
                int j = 0;
                int firstNonFixed = -1;
                for (; firstNonFixed == -1 && j < entities.getSize(); j++)
                {
                    if (!entities[j]->isFixed())
                    {
                        firstNonFixed = j;
                    }
                }
                for (; j < entities.getSize(); j++)
                {
                    if (!entities[j]->isFixed())
                    {
                        unionFind.FUN_009ad2b0(entities[firstNonFixed]->m_storageIndex, entities[j]->m_storageIndex);
                        if (unionFind.isOneGroup())
                        {
                            return hkBool(true);
                        }
                    }
                }
            }
        }
    }
    return hkBool(unionFind.isOneGroup());
}
}   // namespace f3m_0098b230
