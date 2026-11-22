// bshavok/bhkrigidbody_h_unit.cpp: WorldObject (2 functions)
#include "f3_common.h"
#include "bhkrigidbody.h"

extern __declspec(thread) unsigned int g_ThreadMemoryContext;
struct MemoryContextGuard
{
    unsigned int previous;
    __forceinline MemoryContextGuard() : previous(g_ThreadMemoryContext)
    {
        g_ThreadMemoryContext = 16;
    }
    __forceinline ~MemoryContextGuard()
    {
        g_ThreadMemoryContext = previous;
    }
};
struct AllocationManager
{
    void* FUN_00aa3e40(unsigned int size);
};
struct FUN_00c8f510
{
    unsigned int value;
    FUN_00c8f510();
    ~FUN_00c8f510();
};
__forceinline void* __cdecl operator new(unsigned int size, AllocationManager& allocator)
{
    unsigned char* storage = static_cast<unsigned char*>(allocator.FUN_00aa3e40(0xf0));
    unsigned char adjustment = static_cast<unsigned char>(16 - (reinterpret_cast<unsigned int>(storage) & 15));
    storage += adjustment;
    storage[-1] = adjustment;
    return storage;
}
void __cdecl operator delete(void* memory, AllocationManager& allocator);
struct FUN_00c8f5a0_Class
{
    void* virtualFunctions;
    unsigned int referenceCount;
    void* havokObject;
    FUN_00c8f510* rigidBodyInfo;
    void FUN_00c8cfd0(FUN_00c8f510* info);
    FUN_00c8f510* GetOrCreateRigidBodyInfo(unsigned char* wasCreated);
};
// @f3 0x00900f00 (community match, verified in this file)
struct RigidBodyInfoAllocator
{
    void* FUN_0086b930(unsigned int size);
};
extern RigidBodyInfoAllocator DAT_01090a78;

__forceinline void* __cdecl operator new(unsigned int size, RigidBodyInfoAllocator& allocator)
{
    unsigned char* storage = static_cast<unsigned char*>(allocator.FUN_0086b930(0xf0));
    unsigned char adjustment = static_cast<unsigned char>(16 - (reinterpret_cast<unsigned int>(storage) & 15));
    storage += adjustment;
    storage[-1] = adjustment;
    return storage;
}
void __cdecl operator delete(void* memory, RigidBodyInfoAllocator& allocator);

namespace task1800 { struct OwnerCallView { void FUN_008fe7a0(FUN_00c8f510*); }; }

// pdb: bhkRigidBody::CreateCinfo | bhkRigidBody.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCreated
FUN_00c8f510* FUN_00c8f5a0_Class::GetOrCreateRigidBodyInfo(unsigned char* wasCreated)
{
    MemoryContextGuard guard;
    if (rigidBodyInfo == 0)
    {
        rigidBodyInfo = new (DAT_01090a78) FUN_00c8f510();
        if (havokObject)
            ((task1800::OwnerCallView*)this)->FUN_008fe7a0(rigidBodyInfo);
        *wasCreated = 1;
    }
    else
    {
        *wasCreated = 0;
    }
    return rigidBodyInfo;
}


class C8F670Heap
{
  public:
    void Deallocate(void* pvMem);
};

extern C8F670Heap g_memoryManager;

struct C8F670Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct C8F670MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8F670Allocator* m_pStreamAllocator;

    C8F670Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" C8F670MemoryRouter& __cdecl FUN_00c85750() throw();

struct C8F670Pair
{
    int m_iKey;
    int m_iValue;
};

template <class T> struct C8F670Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~C8F670Array() throw()
    {
        C8F670Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class __declspec(novtable) C8F670Object
{
  public:
    virtual ~C8F670Object() throw()
    {}

    static void operator delete(void* pvMem)
    {
        if (pvMem)
        {
            unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
            g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
        }
    }

    void* DestroyObject(unsigned int uiFlags);

    int unk04;
    int unk08;
    C8F670Array<C8F670Pair> m_kPairs;
};

class C8D9BinaryStream
{
  public:
    virtual void v00();
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(C8D9BinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    template <class T> unsigned int Write(const T* pValue, unsigned int uiElementCount)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, uiElementCount * sizeof(T), &uiSize, uiElementCount);
    }
};

class C8D9HavokData
{
  public:
    void SwapEndian();
};

class C8D9Stream
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SaveLinkID(void* pkObject);
    unsigned int unk[(0x1e4 - 4) / 4];
    unsigned char m_ucMode;
    unsigned char unk1e5, unk1e6, unk1e7;
    unsigned int unk1e8[(0x250 - 0x1e8) / 4];
    C8D9BinaryStream* m_pBackingStream;
};

template <class T> inline void C8D9SaveBinary(C8D9Stream* pkStream, const T& kValue)
{
    pkStream->m_pBackingStream->Write(&kValue, 1);
}

struct C8D9Node
{
    void* m_item;
    C8D9Node* m_pkNext;
};

struct C8D9List
{
    C8D9Node m_kHead;
    unsigned int ItemsInList() const
    {
        unsigned int ItemUpdateArray = 0;
        for (const C8D9Node* pkNode = &m_kHead; pkNode && pkNode->m_item; pkNode = pkNode->m_pkNext)
            ItemUpdateArray++;
        return ItemUpdateArray;
    }
};

class FUN_00c8d960_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va();
    virtual void vaCur();
    virtual void vaValue();
    virtual void vac();
    virtual void vb();
    virtual C8D9HavokData* CreateHavokData(bool* pbCreated);

    unsigned int unk;
    unsigned int unkCur;
    unsigned int unk0c;
    unsigned int m_uiValue1;
    C8D9List m_kList;

    void FUN_00c9d530(C8D9Stream* pkStream);
    void FUN_00c8d960(C8D9Stream* pkStream);
};

// Creates Havok data, swaps endianness when not in mode 1, saves list count and item link IDs, then swaps endianness back.
// @f3 0x008ff180 (community match, verified in this file)
struct DataFO3
{
    void FUN_008fe660();
};

struct ListFO3
{
    void FUN_0090ad10(C8D9Stream* pkStream);
};

// pdb: bhkRigidBody::SaveBinary | bhkRigidBody.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_00c8d960_cls::FUN_00c8d960(C8D9Stream* pkStream)
{
    bool bCreated;
    C8D9HavokData* pkData = CreateHavokData(&bCreated);
    if (pkData && pkStream->m_ucMode != 1)
        ((DataFO3*)pkData)->FUN_008fe660();

    ((ListFO3*)this)->FUN_0090ad10(pkStream);

    C8D9SaveBinary(pkStream, m_kList.ItemsInList());

    for (C8D9Node* pkIter = &m_kList.m_kHead; pkIter && pkIter->m_item; pkIter = pkIter->m_pkNext)
        pkStream->SaveLinkID(pkIter->m_item);

    C8D9SaveBinary(pkStream, m_uiValue1);

    if (pkData && pkStream->m_ucMode != 1)
        ((DataFO3*)pkData)->FUN_008fe660();
}
