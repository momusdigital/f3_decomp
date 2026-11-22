#include "f3_common.h"
// src/havok/physics/collide/dispatch/broadphase/hkptypedbroadphasedispatcher.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/broadphase/hkptypedbroadphasedispatcher.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Body
{
    int m_auiShapeKeys;
    signed char m_type;
};

struct Pair
{
    Body* a;
    Body* b;
};

struct Handler
{
    virtual void V0();
    virtual void V1();
    virtual void Process(Pair* p);
};

struct Dispatcher
{
    Handler* m_table[64];
    void DispatchPairs(Pair* pairs, int n);
};

// For each of n pairs, looks up a handler by the pair's two body types and calls Process on it.
// @fnv 0x00cf70f0
// pdb: hkpTypedBroadPhaseDispatcher::removePairs | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: deletedPairs, numDeletedPairs
void Dispatcher::DispatchPairs(Pair* pairs, int aiCount)
{
    while (--aiCount >= 0)
    {
        Body* a = pairs->a;
        Body* b = pairs->b;
        m_table[a->m_type * 8 + b->m_type]->Process(pairs);
        pairs++;
    }
}

struct hkBoolCF7080
{
    char m_cBooleanValue;
};
struct HandleCF7080
{
    unsigned int m_iOwnerObjectOffset;
    signed char m_type;
    signed char m_iOwnerOffset;
    const void* getOwner() const
    {
        return reinterpret_cast<const char*>(this) + m_iOwnerOffset;
    }
};
struct PairCF7080
{
    HandleCF7080* m_kPointA;
    HandleCF7080* m_kPointB;
};
struct FilterCF7080
{
    virtual ~FilterCF7080();
    virtual hkBoolCF7080 IsCollisionEnabled(const void* a, const void* b) const;
};
struct HandlerCF7080
{
    virtual ~HandlerCF7080();
    virtual void addPair(PairCF7080& pair);
};
struct DispatcherCF7080
{
    HandlerCF7080* m_handlers[8][8];
    void FUN_00cf7080(PairCF7080* pairs, int numPairs, const FilterCF7080* filter);
};

// Iterates over collision pairs, filters them with filter->IsCollisionEnabled, and forwards accepted pairs to the handler for each type combination.
// @fnv 0x00cf7080
// pdb: hkpTypedBroadPhaseDispatcher::addPairs | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: newPairs, numNewPairs, filter
void DispatcherCF7080::FUN_00cf7080(PairCF7080* pairs, int numPairs, const FilterCF7080* filter)
{
    while (--numPairs >= 0)
    {
        const void* a = pairs->m_kPointA->getOwner();
        const void* b = pairs->m_kPointB->getOwner();
        if (filter->IsCollisionEnabled(a, b).m_cBooleanValue)
        {
            int typeA = pairs->m_kPointA->m_type;
            int typeB = pairs->m_kPointB->m_type;
            m_handlers[typeA][typeB]->addPair(*pairs);
        }
        pairs++;
    }
}

struct Edge
{
    unsigned int first;
    unsigned int second;
};
struct EdgeArray
{
    Edge* data;
    int count;
    unsigned int capacityFlags;
};
struct HashEntry
{
    unsigned int first;
    unsigned int second;
    unsigned __int64 value;
};
struct HashTableBase
{
    HashEntry* entries;
    int count;
    int capacity;
    void FUN_00cb1b80(void* handle, int length);
    int FUN_00cb1c60(unsigned int first, unsigned int second);
    void InsertKeyValue(void* allocator, unsigned int first, unsigned int second, __int64 value);
    void FUN_00cb1d20(int index);
    void FUN_00cb1e40(void* allocator);
    void FUN_00a29680();
};
struct ScratchAllocator
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void* Allocate(int* descriptor);
    virtual void Release(void* handle, int length);
};
struct S00cf7130_Buf
{
    void* data;
    int size;
    int capacityFlags;
};
struct S00cf7130_Map
{
    S00cf7130_Buf buf;
    HashTableBase table;
};
struct GlobalPool
{
    int unk00;
    int unk04;
    int unk08;
    ScratchAllocator* scratch;
    void* allocator;
    ScratchAllocator& Scratch()
    {
        return *scratch;
    }
};
extern "C" void* __cdecl FUN_00c85750();
unsigned int __cdecl FUN_00cb1810(int);
void __cdecl FUN_00c908c0(void* allocator, EdgeArray* array, int length, int elementSize);

template <typename T> static __forceinline void Swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
template <typename T> static __forceinline T Min2(T x, T y)
{
    return x < y ? x : y;
}

static __forceinline GlobalPool* GetPool()
{
    return (GlobalPool*)FUN_00c85750();
}

static void ShrinkEdges(EdgeArray* array, int size, void* allocator)
{
    int cap = array->capacityFlags & 0x3fffffff;
    if (cap < size)
    {
        int newCap = cap * 2;
        if (size >= newCap)
            newCap = size;
        FUN_00c908c0(allocator, array, newCap, 8);
    }
    array->count = size;
}

static __forceinline void MemCpy4(void* dst, const void* src, int nbytes)
{
    for (int k = 0; k < nbytes; k += 4)
    {
        *(int*)((char*)dst + k) = *(const int*)((const char*)src + k);
    }
}

static __forceinline void RemoveAt(EdgeArray* a, int i)
{
    --a->count;
    MemCpy4(&a->data[i], &a->data[i + 1], (a->count - i) * 8);
}

static __forceinline bool SameEdge(const Edge& h, const Edge& v)
{
    return (h.first == v.first && h.second == v.second) || (h.second == v.first && h.first == v.second);
}

static __forceinline int FindEdge(EdgeArray* a, const Edge& v)
{
    int i = 0;
    for (; i < a->count; ++i)
    {
        if (SameEdge(a->data[i], v))
            break;
    }
    return i;
}

// Removes edges that appear in both arrays from each, treating an edge as equal in either vertex order.
// @f3 0x00984d00 (community match, verified in this file)
// 0x00984d00: hkpTypedBroadPhaseDispatcher::removeDuplicates(hkArray<hkpBroadPhaseHandlePair>& newPairs,
// hkArray<hkpBroadPhaseHandlePair>& delPairs) of Havok 5.5.0 (hkpCollide, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Removes the pairs that are in both lists from both, a pair counting as the same in either order of its handles.
// Short lists are compared pair by pair; longer ones go through a map from the ordered pair to how often it is
// in newPairs. Class, member and function names follow the Havok 5.5.0 SDK headers; the declarations are cut down
// to what this function touches, and the bodies are written from the game's code.
// The packet's signature is kept: EdgeArray is the unit's name for hkArray<hkpBroadPhaseHandlePair>.
namespace f3m_00984d00 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef unsigned int hkUint32;
typedef unsigned __int64 hkUint64;

struct hkBool
{
    hkBool() {}
    hkBool(bool b) : m_bool(b) {}
    operator bool() const { return m_bool != 0; }
    char m_bool;
};

namespace hkMath {
template <typename T> inline T min2(T x, T y)
{
    return x < y ? x : y;
}
}  // namespace hkMath

namespace hkArrayUtil {
// grows the array to at least numElem elements
void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem);
}  // namespace hkArrayUtil

template <typename T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    void reserve(int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil::FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    void removeAtAndCopy(int index)
    {
        m_size--;
        for (int i = index; i < m_size; i++)
            m_data[i] = m_data[i + 1];
    }
};

extern unsigned long DAT_010f3170;  // thread-local slot of the thread's hkThreadMemory

struct hkMemory;

struct hkThreadMemory
{
    struct Stack
    {
        __declspec(align(16)) char* m_current;
        Stack* m_prev;
        char* m_base;
        char* m_end;
    };

    virtual void* alignedAllocate(int alignment, int nbytes, int cl);
    virtual void alignedDeallocate(void* ptr);
    virtual void setStackArea(void* buf, int nbytes);
    virtual void releaseCachedMemory();
    virtual ~hkThreadMemory();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);

    hkMemory* m_memory;
    int m_referenceCount;
    Stack m_stack;

    static hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }

    // a block from the thread's stack area, 16 bytes more than asked for and rounded down to a multiple of 16;
    // blocks are freed in reverse order
    void* allocateStack(int nbytes)
    {
        char* current = m_stack.m_current;
        nbytes = (nbytes + 16) & ~15;
        char* next = current + nbytes;
        if (next <= m_stack.m_end)
        {
            m_stack.m_current = next;
            return current;
        }
        return onStackOverflow(nbytes);
    }
    void deallocateStack(void* p)
    {
        m_stack.m_current = (char*)p;
        if (p == m_stack.m_base)
            onStackUnderflow(p);
    }
};

// open-addressing map; the keys are in the first half of m_elem and the values in the second
template <typename T> struct hkPointerMapBase
{
    typedef class Dummy* Iterator;

    // sets the map up in preallocated memory
    hkPointerMapBase* FUN_009226b0(void* ptr, int sizeInBytes);
    // frees the storage unless it was preallocated
    void FUN_00922e40();
    // memory needed for numOfKeys keys
    static int __cdecl FUN_009226f0(int numOfKeys);
    Iterator FUN_009229f0(T key) const;  // findKey
    void FUN_00922910(T key, T val);     // insert
    void FUN_00922a80(Iterator it);      // remove

    T getValue(Iterator it) const { return m_elem[(int)it + m_hashMod + 1]; }
    void setValue(Iterator it, T val) { m_elem[(int)it + m_hashMod + 1] = val; }
    hkBool isValid(Iterator it) const { return (int)it <= m_hashMod; }

    T* m_elem;
    int m_numElems;
    int m_hashMod;
};

struct hkpBroadPhaseHandle;

struct hkpBroadPhaseHandlePair
{
    hkpBroadPhaseHandle* m_a;
    hkpBroadPhaseHandle* m_b;
};

// either order of the same two handles
inline hkBool isSamePair(const hkpBroadPhaseHandlePair& a, const hkpBroadPhaseHandlePair& b)
{
    return (a.m_a == b.m_a && a.m_b == b.m_b) || (a.m_b == b.m_a && a.m_a == b.m_b);
}

// the pair's two handles as one 64-bit key, the lower address first
inline hkUint64 orderedKey(const hkpBroadPhaseHandlePair& pair)
{
    hkpBroadPhaseHandlePair ordered = pair;
    if (ordered.m_a > ordered.m_b)
    {
        hkpBroadPhaseHandle* t = ordered.m_a;
        ordered.m_a = ordered.m_b;
        ordered.m_b = t;
    }
    return *(hkUint64*)&ordered;
}

}  // namespace f3m_00984d00

// pdb: hkpTypedBroadPhaseDispatcher::removeDuplicates | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_retail, caller, medium
// pdb params: newPairs, delPairs
void __cdecl FUN_00cf7130(EdgeArray* apEdgesA, EdgeArray* apEdgesB)
{
    using namespace f3m_00984d00;
    // the unit's EdgeArray has the layout of hkArray<hkpBroadPhaseHandlePair>
    hkArray<hkpBroadPhaseHandlePair>& newPairs = *(hkArray<hkpBroadPhaseHandlePair>*)apEdgesA;
    hkArray<hkpBroadPhaseHandlePair>& delPairs = *(hkArray<hkpBroadPhaseHandlePair>*)apEdgesB;

    int n = hkMath::min2(newPairs.getSize(), delPairs.getSize());
    if (n < 32)
    {
        // short lists: look every deleted pair up in newPairs
        int d = 0;
        for (int j = 0; j < delPairs.getSize(); j++)
        {
            int i;
            for (i = 0; i < newPairs.getSize(); i++)
            {
                if (isSamePair(newPairs[i], delPairs[j]))
                    break;
            }
            if (i == newPairs.getSize())
            {
                if (d != j)
                    delPairs[d] = delPairs[j];
                d++;
            }
            else
            {
                newPairs.removeAtAndCopy(i);
            }
        }
        delPairs.setSize(d);
    }
    else
    {
        int memSize = hkPointerMapBase<hkUint64>::FUN_009226f0(newPairs.getSize());
        char* buffer = (char*)hkThreadMemory::getInstance().allocateStack(memSize);
        hkPointerMapBase<hkUint64> map;
        map.FUN_009226b0(buffer, memSize);

        // count every new pair; a repeated one is taken out of newPairs right away
        for (int i = 0; i < newPairs.getSize(); i++)
        {
            hkUint64 key = orderedKey(newPairs[i]);
            hkPointerMapBase<hkUint64>::Iterator it = map.FUN_009229f0(key);
            if (map.isValid(it))
            {
                map.setValue(it, map.getValue(it) + 1);
                newPairs[i].m_a = 0;
            }
            else
            {
                map.FUN_00922910(key, (i << 8) | 1);
            }
        }

        // a deleted pair that is also new cancels one new pair; the others stay in delPairs
        int d = 0;
        for (int j = 0; j < delPairs.getSize(); j++)
        {
            hkUint64 key = orderedKey(delPairs[j]);
            hkPointerMapBase<hkUint64>::Iterator it = map.FUN_009229f0(key);
            if (map.isValid(it))
            {
                hkUint64 val = map.getValue(it);
                if (((int)val & 0xff) > 1)
                {
                    map.setValue(it, val - 1);
                }
                else
                {
                    map.FUN_00922a80(it);
                    newPairs[(hkUint32)val >> 8].m_a = 0;
                }
            }
            else
            {
                delPairs[d++] = delPairs[j];
            }
        }
        delPairs.setSize(d);

        // close the gaps in newPairs
        d = 0;
        for (int i = 0; i < newPairs.getSize(); i++)
        {
            if (newPairs[i].m_a != 0)
                newPairs[d++] = newPairs[i];
        }
        newPairs.setSize(d);

        map.FUN_00922e40();
        hkThreadMemory::getInstance().deallocateStack(buffer);
    }
}

