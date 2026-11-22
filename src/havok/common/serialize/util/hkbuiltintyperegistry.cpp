#include "f3_common.h"
// src/havok/common/serialize/util/hkbuiltintyperegistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkbuiltintyperegistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d479e0_class
{
    void* __thiscall GetValue(const void* key, const void* def);
    void* __thiscall FUN_00d479e0(const void* key);
};

// @fnv 0x00d479e0
// pdb: BGSMessageIcon::SetMessageIconTextureName | BGSMessageIcon.obj | fnv360_0822_retail, call_gap, low
// pdb params: apTexture
void* __thiscall FUN_00d479e0_class::FUN_00d479e0(const void* key)
{
    return ((FUN_00d479e0_class*)((char*)this + 8))->GetValue(key, 0);
}

struct FUN_00d47a80_class
{
    void* GetValue(void* a, int b);
    void* hkDynamicClassNameRegistry_getClassByName(void* a);
};

// @fnv 0x00d47a80
// pdb: hkDynamicClassNameRegistry::getClassByName | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable, high
// pdb params: className
// pdb: hkDynamicClassNameRegistry::getClassByName | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable, high (was: ForwardToOffsetMember)
void* FUN_00d47a80_class::hkDynamicClassNameRegistry_getClassByName(void* apArg)
{
    return ((FUN_00d47a80_class*)((char*)this + 0xc))->GetValue(apArg, 0);
}

struct HashEntryTable
{
    unsigned long FindValueForKey(unsigned long a, unsigned long b);
};
struct hkVtableClassRegistry
{
    unsigned long LookupClassByVtable(const unsigned long* p);
};
// @fnv 0x00d47c40
// pdb: hkVtableClassRegistry::getClassFromVirtualInstance | hkBuiltinTypeRegistry.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: obj
unsigned long hkVtableClassRegistry::LookupClassByVtable(const unsigned long* pVtable)
{
    unsigned long v = *pVtable;
    return ((HashEntryTable*)((char*)this + 8))->FindValueForKey(v, 0);
}

struct D481D0Class
{
    const char* getName() const;
};
struct FUN_00d874d0_s
{
    void FUN_00d874d0(const char*, int);
};
struct FUN_00d47aa0_s
{
    int a;
    int b;
    int c;
    void hkDynamicClassNameRegistry_registerClass(int a, const char* name);
};
// Calls FUN_00d874d0 on the object at this+0xc with the given name (or the name from a) and a.
// @fnv 0x00d47aa0
// pdb: hkDynamicClassNameRegistry::registerClass | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FUN_00d47aa0_s::hkDynamicClassNameRegistry_registerClass(int a, const char* name)
{
    ((FUN_00d874d0_s*)((char*)this + 0xc))->FUN_00d874d0(name ? name : ((D481D0Class*)a)->getName(), a);
}

struct FUN_00d87440_Class
{
    int __thiscall FUN_00d87440(int);
};
struct SlotBitmap
{
    int __thiscall FindNextUsedSlot(int);
};
struct FUN_00d874b0_class
{
    char* __thiscall SetBoolFromThreshold(char*, int);
};
struct FUN_00d87410_Class
{
    int __thiscall FUN_00d87410();
};

struct FUN_00d47ad0_class
{
    void ProcessRegistryEntries(FUN_00d874b0_class* reg);
};

// @fnv 0x00d47ad0
// pdb: hkDynamicClassNameRegistry::merge | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable, high
// pdb params: mergeFromMap
void FUN_00d47ad0_class::ProcessRegistryEntries(FUN_00d874b0_class* reg)
{
    int key = ((FUN_00d87410_Class*)reg)->FUN_00d87410();
    char flag;
    reg->SetBoolFromThreshold(&flag, key);
    while (flag)
    {
        int val = ((FUN_00d87440_Class*)reg)->FUN_00d87440(key);
        (*(void(__thiscall**)(void*, int, int))(*(int*)this + 0x1c))(this, val, 0);
        key = ((SlotBitmap*)reg)->FindNextUsedSlot(key);
        reg->SetBoolFromThreshold(&flag, key);
    }
}

extern int DAT_01269b18;

// @fnv 0x00d47a00
// pdb: BGSTextureSet::GetNullTextureSet | BGSTextureSet.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BGSTextureSet::ClearNullTextureSet)
int __cdecl FUN_00d47a00()
{
    return DAT_01269b18;
}

extern int DAT_01269b14;

// @fnv 0x00d47a10
// pdb: TESIdleManager::GetUsedItem | TESIdleManager.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BGSCollisionLayer::QDebugColor)
int __cdecl FUN_00d47a10()
{
    return DAT_01269b14;
}

extern int DAT_01269b10;

// @fnv 0x00d47a20
// pdb: TESIdleManager::GetUsedItemLevel | TESIdleManager.obj | fnv360_0822_retail, call_seq, medium
int FUN_00d47a20()
{
    return DAT_01269b10;
}

struct D477C0Input
{
    int unk00, unk04, unk08;
    void* value0c;
};
struct D477C0Source
{
    int FUN_00d46d40();
    int hkClass_getNumInterfaces();
};
struct D477C0RegistryA
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void registerObject(D477C0Source*, int);
};
struct D477C0RegistryB
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void registerInput(D477C0Input*);
};
struct D477C0RegistryC
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void registerLink(void*, D477C0Source*);
};
// @f3 0x00932620 (community match, verified in this file)
struct S00dbddc0_Node
{
    int FUN_00d46d40();
};
extern int DAT_011693a0;
extern int DAT_0126900c;
extern int DAT_011693a8;
void __stdcall RegisterInputSource(D477C0Input* input, D477C0Source* source)
{
    D477C0RegistryA* registryA = *(D477C0RegistryA**)&DAT_011693a0;
    registryA->registerObject(source, reinterpret_cast<S00dbddc0_Node*>(source)->FUN_00d46d40());
    D477C0RegistryB* registryB = *(D477C0RegistryB**)&DAT_0126900c;
    registryB->registerInput(input);
    D477C0RegistryC* registryC = *(D477C0RegistryC**)&DAT_011693a8;
    registryC->registerLink(input->value0c, source);
}


struct hkClassD478
{
    const char* m_name;

    const char* getName() const
    {
        return m_name;
    }
};

class hkClassNameRegistryD478
{
  public:
    int m_00;
    int m_04;
    FUN_00d874d0_s m_map;

    void hkTypeInfoRegistry_registerTypeInfo(const hkClassD478* pkClass);
};

// @fnv 0x00d478e0
// pdb: hkTypeInfoRegistry::registerTypeInfo | hkBuiltinTypeRegistry.obj | fnv360_0721_beta, caller_sim, high
// pdb params: info
// pdb: hkTypeInfoRegistry::registerTypeInfo | hkBuiltinTypeRegistry.obj | fnv360_0721_beta, caller_sim, high (was: RegisterClass)
void hkClassNameRegistryD478::hkTypeInfoRegistry_registerTypeInfo(const hkClassD478* pkClass)
{
    m_map.FUN_00d874d0(pkClass->getName(), (int)pkClass);
}

struct FUN_00d47940_Result
{
    int unk00;
    int unk04;
    void(__cdecl* unk08)(int);
};

struct FUN_00d47940_Registry
{
    void* __thiscall GetValue(const void* key, const void* def);
};

struct FUN_00d47940_Obj
{
    int unk00;
    int unk04;
    FUN_00d47940_Registry unk08;
    void* __thiscall hkTypeInfoRegistry_cleanupLoadedObject(int param1, int param2);
};

// Looks up a result by key in the registry, and if found and it has a callback, invokes that callback with param1; returns the result.
// @fnv 0x00d47940
// pdb: hkTypeInfoRegistry::cleanupLoadedObject | hkBuiltinTypeRegistry.obj | fnv360_0721_beta, objrun + bridge(hash|vtable) + skyrim(objopen_prop), high
void* __thiscall FUN_00d47940_Obj::hkTypeInfoRegistry_cleanupLoadedObject(int param1, int aKey)
{
    FUN_00d47940_Result* result = (FUN_00d47940_Result*)this->unk08.GetValue((const void*)aKey, 0);

    if (result != 0 && result->unk08 != 0)
    {
        result->unk08(param1);
    }

    return result;
}

struct FUN_00d87430_Class
{
    int __thiscall GetEntry(int index);
};
struct FUN_00d47970_Class
{
    int unk00;
    int unk04;
    FUN_00d874d0_s m_map08;

    void FUN_00d47970(void* iterator);
};

// @fnv 0x00d47970
// pdb: hkTypeInfoRegistry::merge | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: mergeFrom
void FUN_00d47970_Class::FUN_00d47970(void* iterator)
{
    FUN_00d87410_Class* registry = (FUN_00d87410_Class*)((char*)iterator + 8);
    int index = registry->FUN_00d87410();
    ((FUN_00d874b0_class*)registry)->SetBoolFromThreshold((char*)&iterator, index);
    if (*(char*)&iterator != 0)
    {
        FUN_00d874d0_s* destination = &m_map08;
        do
        {
            int key = ((FUN_00d87440_Class*)registry)->FUN_00d87440(index);
            int value = ((FUN_00d87430_Class*)registry)->GetEntry(index);
            destination->FUN_00d874d0((const char*)value, key);
            index = ((SlotBitmap*)registry)->FindNextUsedSlot(index);
            ((FUN_00d874b0_class*)registry)->SetBoolFromThreshold((char*)&iterator, index);
        } while (*(char*)&iterator != 0);
    }
}

class hkObjD47A
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void add(const char* pcName, int iFlags);

    void hkDynamicClassNameRegistry_registerList(const char* const* ppcNames);
};

// Calls add on each name in the null-terminated array ppcNames with flags 0.
// @fnv 0x00d47a50
// pdb: hkDynamicClassNameRegistry::registerList | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable, high
// pdb params: classes
// pdb: hkDynamicClassNameRegistry::registerList | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable, high (was: AddNames)
void hkObjD47A::hkDynamicClassNameRegistry_registerList(const char* const* ppcNames)
{
    for (; *ppcNames; ++ppcNames)
        add(*ppcNames, 0);
}

struct HavokHeap
{
    virtual void reserve();
    virtual void allocate();
    virtual void release(void* memory, unsigned int size);
};
struct HavokRouter
{
    int unk00, unk04, unk08, unk0c;
    HavokHeap* heap;
};
extern "C" HavokRouter* __cdecl FUN_00c85750();
struct EmbeddedRegistry
{
    void FreeBuffer();
    ~EmbeddedRegistry()
    {
        FreeBuffer();
    }
};
struct RegistryBase
{
    virtual ~RegistryBase()
    {}
    unsigned short allocatedSize;
    unsigned short unk06;
    int unk08;
};

namespace fnv_00d47bb0 {
struct D47Array
{
    int* data;
    int count;
    unsigned int capacityAndFlags;
};
struct D47Router
{
    int field00;
    int field04;
    int field08;
    int field0c;
    void* heap;
};
D47Router* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, D47Array* array, int elementSize);

}  // namespace fnv_00d47bb0

namespace fnv_00d47c90 {
struct Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void Free(void* p, unsigned int n) throw();
};
struct Holder
{
    int a, b, c, d;
    Alloc* alloc;
};
Holder* __cdecl FUN_00c85750() throw();
}  // namespace fnv_00d47c90

namespace fnv_00d47ce0 {
class hkMemoryAllocatorD47C;

struct hkMemoryRouterD47C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD47C* m_pStreamAllocator;
    hkMemoryAllocatorD47C& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD47C& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyD47C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayD47C
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
        hkMemoryAllocatorD47C& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyD47C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct hkMapPairD47C
{
    int key;
    int val;
};

class hkMapIterD47C;
typedef hkMapIterD47C* hkMapIteratorD47C;

class hkPointerMapD47C
{
  public:
    hkMapPairD47C* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkMapIteratorD47C GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != -1)
                break;
        }
        return reinterpret_cast<hkMapIteratorD47C>(i);
    }
    hkMapIteratorD47C getNext(hkMapIteratorD47C it) const
    {
        int i = reinterpret_cast<int>(it);
        for (i += 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != -1)
                break;
        }
        return reinterpret_cast<hkMapIteratorD47C>(i);
    }
    bool isValid(hkMapIteratorD47C it) const
    {
        return reinterpret_cast<int>(it) <= m_iPairCount;
    }
    int getValue(hkMapIteratorD47C it) const
    {
        return m_kPrimitiveElement[reinterpret_cast<int>(it)].val;
    }
};

}  // namespace fnv_00d47ce0

namespace fnv_00d47d70 {

struct MyAllocator
{
    virtual void unk00();
    virtual void* allocate(int size);
};

struct MyRouter
{
    int unk00, unk04, unk08, unk0c;
    MyAllocator* heap;
    __forceinline void* alloc(int size)
    {
        return heap->allocate(size);
    }
};

extern "C" MyRouter* FUN_00c85750();

}  // namespace fnv_00d47d70

namespace fnv_00d47eb0 {
class hkMemoryAllocatorD47E
{
  public:
    virtual ~hkMemoryAllocatorD47E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD47E
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD47E* m_pStreamAllocator;
    hkMemoryAllocatorD47E& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD47E& __cdecl FUN_00c85750();

template <class T> __forceinline void destructD47E(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayD47E
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD47E() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayD47E() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructD47E(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorD47E& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

}  // namespace fnv_00d47eb0

class hkMemoryAllocatorD47B
{
  public:
    virtual ~hkMemoryAllocatorD47B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD47B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD47B* m_pStreamAllocator;
    hkMemoryAllocatorD47B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD47B {
extern "C" hkMemoryRouterD47B& __cdecl FUN_00c85750() throw();
}

class hkReferencedObjectD47B
{
  public:
    virtual ~hkReferencedObjectD47B() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkRouterD47B::FUN_00c85750().heap().ReleaseBlock(p,
                                                         static_cast<hkReferencedObjectD47B*>(p)->m_usMemSizeAndFlags);
    }
};
