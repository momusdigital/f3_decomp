#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d87430_class
{
    int* m_p;
    int m_kPointB;
    int m_iThirdValue;
    int GetEntry(int idx);
};

// @fnv 0x00d87430
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey | hkStringMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: it
int FUN_00d87430_class::GetEntry(int idx)
{
    return m_p[m_iThirdValue + idx + 1];
}

struct FUN_00d87440_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int __thiscall FUN_00d87440(int a);
};
// @fnv 0x00d87440
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue | hkStringMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: it
int __thiscall FUN_00d87440_Class::FUN_00d87440(int aiIndex)
{
    return *(int*)((char*)m_iWordAt00 + aiIndex * 4 + m_8 * 8 + 8);
}

struct SlotBitmap
{
    unsigned long* m_kPrimitiveElement;
    int m_auiShapeKeys;
    int m_iPairCount;
    int FindNextUsedSlot(int i);
};

// @fnv 0x00d87480
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getNext | hkStringMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: it
int SlotBitmap::FindNextUsedSlot(int aiStartIndex)
{
    ++aiStartIndex;
    if (aiStartIndex <= m_iPairCount)
    {
        unsigned long* p = m_kPrimitiveElement + aiStartIndex;
        do
        {
            if (*p != 0xffffffff)
                break;
            ++aiStartIndex;
            p += 1;
        } while (aiStartIndex <= m_iPairCount);
    }
    return aiStartIndex;
}

struct FUN_00d874b0_class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    char* SetBoolFromThreshold(char* p, int value);
};

// @fnv 0x00d874b0
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid | hkStringMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: it
char* FUN_00d874b0_class::SetBoolFromThreshold(char* pbOut, int value)
{
    *pbOut = value <= m_cByteAtOffset2;
    return pbOut;
}

struct FUN_00d87760_class
{
    void** m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void ClearEntries();
};

// @fnv 0x00d87760
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear | hkStringMap.obj | fnv360_0822_retail, objrun_open, low
void FUN_00d87760_class::ClearEntries()
{
    int i;
    for (i = 0; i < m_iPairCount + 1; i++)
        ((unsigned long*)m_kPrimitiveElement)[i] = 0xffffffff;
    m_iCapacityFlags = 0;
}

struct FUN_00d877d0_allocator
{
    virtual void FUN_00d877d0_virtual0() = 0;
    virtual void FUN_00d877d0_virtual1() = 0;
    virtual void FUN_00d877d0_free(void* p, unsigned int size) = 0;
};

struct FUN_00d877d0_router
{
    unsigned char m_auiShapeKeys[0x10];
    FUN_00d877d0_allocator* m_pThreadAllocator;
};

FUN_00d877d0_router* _D1A0E0GetMemoryRouter();

struct FUN_00d87820_Class
{
    char* SetBoolFromThreshold(char* p, int value);
    int FindStringKey(int);
    void FUN_00d876a0(int);
    int FUN_00d87820(int a);
};

namespace fnv_00dc8080 {

struct FUN_allocator_class
{
// @fnv 0x00dc8080
    virtual void FUN_00dc8080_0()
    {}
    virtual void FUN_00dc8080_1()
    {}
    virtual void FUN_00dc8080_2(void* p, unsigned int size)
    {}
};

struct FUN_router_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
};

FUN_router_class* _D1A0E0GetMemoryRouter();

}  // namespace fnv_00dc8080

int __cdecl FUN_00cb0fa0(const char*, const char*);

static __forceinline int stringHash(const char* str)
{
    int hash = 0;
    if (*str)
    {
        const char* p = str;
        do
        {
            hash = 31 * hash + *p;
            ++p;
        } while (*p);
    }
    return hash & 0x7fffffff;
}

// @fnv 0x00d87580
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::findKey | hkStringMap.obj | fnv360_0822_retail, caller, high
// pdb params: key
int FUN_00d87820_Class::FindStringKey(int key)
{
    const char* str = (const char*)key;
    SlotBitmap* table = (SlotBitmap*)this;
    int hash = stringHash(str);
    unsigned int slot = hash & table->m_iPairCount;
    while (table->m_kPrimitiveElement[slot] != 0xffffffffu)
    {
        if (table->m_kPrimitiveElement[slot] == (unsigned int)hash &&
            FUN_00cb0fa0(str, (const char*)table->m_kPrimitiveElement[table->m_iPairCount + slot + 1]) == 0)
            return slot;
        slot = (slot + 1) & table->m_iPairCount;
    }
    return table->m_iPairCount + 1;
}

struct Allocator
{
    virtual void v0() = 0;
    virtual void* alloc(int size) = 0;
    virtual void free(void* p, unsigned int size) = 0;
};

struct MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pThreadAllocator;
};

MemoryRouter* FUN_00c85750();
extern "C" void* FUN_00cb1280(void*, int, unsigned int);

struct FUN_00d87790
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    FUN_00d87790(int a);
};

// @f3 0x009b1110 (community match, verified in this file)
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern DWORD DAT_010f3170;

struct ThreadMemory
{
    void* AllocateChunk(int size, int flags);
};

// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> | hkStringMap.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: ops
FUN_00d87790::FUN_00d87790(int a)
{
    ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
    void* p = mem->AllocateChunk(0xc0, 0x17);
    m_kPrimitiveElement = p;
    FUN_00cb1280(p, 0xff, 0x40);
    m_iCapacityFlags = 0;
    m_iPairCount = 0xf;
}


class hkObjectD878
{
  public:
    void FUN_00d87650(int a, int* piValue);
    int GetValue(int a, int b);
};

// @fnv 0x00d87800
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getWithDefault | hkStringMap.obj | fnv360_0822_debug, call_seq, medium
// pdb params: key, def
int hkObjectD878::GetValue(int a, int aiDefault)
{
    int iValue = aiDefault;
    FUN_00d87650(a, &iValue);
    return iValue;
}

struct hkBoolD876
{
    char m_cBooleanValue;
    hkBoolD876(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkStringMapD876
{
  public:
    int unk00;
    int unk04;
    int unk08;

    int FindStringKey(const char* key);
    hkBoolD876 SetBoolFromThreshold(int it);
    int FUN_00d87440(int it);
    void FUN_00d874d0(const char* key, int val);
    int hkpContinuousSimulation_resetCollisionInformationForEntities(const char* key, int def, void* a, void* b);
};

// Looks up key; if found returns its value, otherwise stores def under key and returns def.
// @f3 0x0098da90 (community match, verified in this file)
struct MapOps
{
    int hkpSimulation_resetCollisionInformationForEntities(const char* key, int def, void* a, void* b);
    int hkpContinuousSimulation_removeToiEventsOfEntities(const char* key, int def);
    int hkpContinuousSimulation_removeToiEventsOfEntity(int value);
};

// pdb: hkpContinuousSimulation::resetCollisionInformationForEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, high
// pdb params: entities, numEntities, world, resetInfo
// pdb: hkpContinuousSimulation::resetCollisionInformationForEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable, high (was: GetOrSetInt)
int hkStringMapD876::hkpContinuousSimulation_resetCollisionInformationForEntities(const char* key, int def, void* a, void* b)
{
    ((MapOps*)this)->hkpSimulation_resetCollisionInformationForEntities(key, def, a, b);
    if (def != 1)
        return ((MapOps*)this)->hkpContinuousSimulation_removeToiEventsOfEntities(key, def);
    return ((MapOps*)this)->hkpContinuousSimulation_removeToiEventsOfEntity(*(int*)key);
}


struct hkBoolD8765
{
    char m_cBooleanValue;
    hkBoolD8765(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkStringMapD8765
{
  public:
    int unk00;
    int unk04;
    int unk08;

    int FindStringKey(const char* key);
    hkBoolD8765 SetBoolFromThreshold(int it);
    int FUN_00d87440(int it);
    int FUN_00d87650(const char* key, int* out);
};

// Looks up key; if found writes its value to out and returns 0, otherwise returns 1.
// @fnv 0x00d87650
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get | hkStringMap.obj | fnv360_0822_retail, call_gap, medium
// pdb params: key, out
int hkStringMapD8765::FUN_00d87650(const char* key, int* piOut)
{
    int it = FindStringKey(key);
    if (SetBoolFromThreshold(it))
    {
        *piOut = FUN_00d87440(it);
        return 0;
    }
    return 1;
}

class hkMemoryAllocatorD878
{
  public:
    virtual ~hkMemoryAllocatorD878() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD878
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD878* m_pStreamAllocator;
    hkMemoryAllocatorD878& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterD878& __cdecl FUN_00c85750() throw();
}

class FUN_00d874d0_s
{
  public:
    unsigned int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00d874d0(const char* pcKey, int iValue);
    void FUN_00d87860(int iNewCap);
};

// Grows the primitive element array to iNewCap, re-inserts existing pairs via FUN_00d874d0, and releases the old block.
// @f3 0x009b1190 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
extern "C" void* FUN_00923500(void*, int, unsigned int);
struct HeapD878F3
{
    void* FUN_008f6d30(unsigned int bytes, unsigned int tag);
    void FUN_008f6d90(void* p, unsigned int bytes, unsigned int tag);
};
struct MapD878F3
{
    unsigned int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void FUN_009b0e60(const char* pcKey, int iValue);
};
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::resizeTable | hkStringMap.obj | fnv360_0822_debug, call_seq, high
// pdb params: newcap
void FUN_00d874d0_s::FUN_00d87860(int iNewCap)
{
    MapD878F3* self = (MapD878F3*)this;
    int iOldCap = self->m_iPairCount + 1;
    unsigned int* puiOldElements = self->m_kPrimitiveElement;
    HeapD878F3* heap = (HeapD878F3*)TlsGetValue(DAT_010f3170);
    self->m_kPrimitiveElement = (unsigned int*)heap->FUN_008f6d30(iNewCap * 3 * sizeof(unsigned int), 0x17);
    FUN_00923500(self->m_kPrimitiveElement, 0xff, iNewCap * sizeof(unsigned int));
    self->m_iCapacityFlags = 0;
    self->m_iPairCount = iNewCap - 1;

    for (int i = 0; i < iOldCap; i++)
    {
        if (puiOldElements[i] != 0xffffffff)
            self->FUN_009b0e60((const char*)puiOldElements[iOldCap + i], puiOldElements[i + 2 * iOldCap]);
    }

    HeapD878F3* heap2 = (HeapD878F3*)TlsGetValue(DAT_010f3170);
    heap2->FUN_008f6d90(puiOldElements, iOldCap * 3 * sizeof(unsigned int), 0x17);
}


struct S00d876a0_Map
{
    unsigned long* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00d876a0(int it);
};

// Removes the element at index it from the open-addressing hash table, compacting remaining entries to fill the gap.
// @fnv 0x00d876a0
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove | hkStringMap.obj | fnv360_0822_retail, objrun_open, low
// pdb params: it
void S00d876a0_Map::FUN_00d876a0(int aiIndex)
{
    unsigned i = aiIndex;

    // remove it
    --m_iCapacityFlags;
    m_kPrimitiveElement[i] = unsigned(-1);

    // find lowest element of this unbroken run
    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (m_kPrimitiveElement[lo] != unsigned(-1))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    // the slot which has become empty
    unsigned empty = i;

    // shift up, closing any gaps we find
    for (i = (i + 1) & m_iPairCount; m_kPrimitiveElement[i] != unsigned(-1); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = m_kPrimitiveElement[i] & m_iPairCount;

        if ((i >= lo) && (hash > empty))
        {
            continue;
        }
        else if ((i < empty) && (hash > empty || hash <= i))
        {
            continue;
        }
        else if (hash > empty && hash < lo)
        {
            continue;
        }
        m_kPrimitiveElement[empty] = m_kPrimitiveElement[i];
        m_kPrimitiveElement[m_iPairCount + 1 + empty] = m_kPrimitiveElement[m_iPairCount + 1 + i];
        m_kPrimitiveElement[2 * (m_iPairCount + 1) + empty] = m_kPrimitiveElement[2 * (m_iPairCount + 1) + i];
        m_kPrimitiveElement[i] = unsigned(-1);
        empty = i;
    }
}

int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB) throw();

class hkStringMapD874
{
  public:
    unsigned long* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    static __forceinline int hash(const char* pcKey)
    {
        int h = 0;
        for (int i = 0; pcKey[i]; i++)
            h = 31 * h + pcKey[i];
        return h & 0x7fffffff;
    }

    void FUN_00d874d0(const char* pcKey, int iValue);
    void FUN_00d87860(int iNewCap);
};

// Inserts a key-value pair into the hash map, growing the table if the load factor exceeds half capacity.
// @fnv 0x00d874d0
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert | hkStringMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: key, val
void hkStringMapD874::FUN_00d874d0(const char* pcKey, int iValue)
{
    int uiHash = hash(pcKey);
    if (m_iCapacityFlags * 2 > m_iPairCount)
        FUN_00d87860(m_iPairCount + m_iPairCount + 2);

    int i = uiHash & m_iPairCount;
    while (m_kPrimitiveElement[i] != 0xffffffffu)
    {
        if (m_kPrimitiveElement[i] == uiHash)
        {
            const char* pcStored = (const char*)m_kPrimitiveElement[m_iPairCount + i + 1];
            if (FUN_00cb0fa0(pcKey, pcStored) == 0)
                goto KEY_FOUND;
        }
        i = (i + 1) & m_iPairCount;
    }

    m_iCapacityFlags += 1;

KEY_FOUND:
    m_kPrimitiveElement[i] = uiHash;
    m_kPrimitiveElement[m_iPairCount + i + 1] = (unsigned long)pcKey;
    m_kPrimitiveElement[2 * m_iPairCount + 2 + i] = iValue;
}

namespace fnv_00e02800 {
class AllocatorE028
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct RouterE028
{
    int unk00, unk04, unk08, unk0C;
    AllocatorE028* m_pStreamAllocator;

    AllocatorE028& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE028 {
extern "C" RouterE028& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(AllocatorE028* pAlloc, void* pArray, int iElemSize);

struct hkBoolE028
{
    char m_cBooleanValue;
    hkBoolE028(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class FUN_00d87790
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int unk0C;

    FUN_00d87790(hkBoolE028 bOwnsKeys) throw();

    static void* operator new(unsigned int uiSize)
    {
        return hkRouterE028::FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
    }
    static void operator delete(void* p);

    int FindStringKey(const char* pcKey);
    char* SetBoolFromThreshold(char* pcOut, int iIt);
    void FUN_00d874d0(const char* pcKey, int iValue);
    int GetEntry(int iIt);
    void SetElement(int iIt, int iValue);

    bool isValid(int iIt)
    {
        char cValid;
        SetBoolFromThreshold(&cValid, iIt);
        return cValid != 0;
    }
};

class StringMapE028 : public FUN_00d87790
{
  public:
    StringMapE028() throw() : FUN_00d87790(hkBoolE028(false))
    {}
};

template <class T> __forceinline void constructWithCopyE028(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayE028
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void _pushBack(RouterE028& kRouter, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kRouter.heap(), this, sizeof(T));
        constructWithCopyE028(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(const T& t)
    {
        _pushBack(hkRouterE028::FUN_00c85750(), t);
    }
};

}  // namespace fnv_00e02800
