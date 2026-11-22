#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cb18f0_t
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_iPairCount;
    int FindSlot(int);
    int RemoveEntry(int);
    int FUN_00cb1fb0(int key);
};

// @fnv 0x00cb1fb0
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::remove | hkMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: key
int __thiscall FUN_00cb18f0_t::FUN_00cb1fb0(int key)
{
    int found = FindSlot(key);
    if (found <= m_iPairCount)
    {
        RemoveEntry(found);
        return 0;
    }
    return 1;
}

struct FUN_00cb1930_t
{
    int* m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_iPairCount;
    int LookupHashEntry(int key, int defaultValue);
};

// @f3 0x009227d0 (community match, verified in this file)
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::getWithDefault | hkMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: key, def
int FUN_00cb1930_t::LookupHashEntry(int key,int defaultValue) {
    int limit=m_iPairCount;
    int* table=m_uiStandInValue;
    unsigned int index=((unsigned int)key>>4)*0x9e3779b1u & limit;
    int current=table[index];
    while (current!=-1) {
        if (current==key) {
            return m_uiStandInValue[m_iPairCount+index+1];
        }
        index=(index+1)&limit;
        current=table[index];
    }
    return defaultValue;
}


struct DepthLimit
{
    int FindSlot(int);
    int* m_buckets;
};
// Hashes key, and if the hash is within the limit, writes the bucket's paired value to out and returns 0; otherwise returns 1.
// @f3 0x00922820 (community match, verified in this file)
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::get | hkMap.obj | fnv360_0822_retail, call_seq, high
// pdb params: key, out
int __fastcall LookupBucketValue(DepthLimit* self, int, int key, int* output) {
    int index = self->FindSlot(key);
    int depth = ((int*)self)[2];
    if (index <= depth) {
        *output = self->m_buckets[depth + index + 1];
        return 0;
    }
    return 1;
}


namespace fnv_00cb1ac0 {
struct TypeNode
{
    int m_key;
    int m_uiFilterValue;
};

struct Allocator
{
    virtual void Unused() = 0;
    virtual void* Allocate(int size);
    virtual void Free(void* data, int size);
};

struct DepthLimit
{
    TypeNode* m_data;
    int m_flags;
    int m_uiItemCount;

    void FUN_00cb1870(void* allocator, void* key, int value);
    void ResizeAndRehash(Allocator* allocator, int count);
};

}  // namespace fnv_00cb1ac0

struct FUN_00cb1e40_arg_t
{
    // Empty virtual function body that does nothing.
// @fnv 0x00cb1e40
    virtual void FUN_00cb1e40_dummy()
    {}

    virtual void FUN_00cb1e40_dummy2()
    {}

    virtual void FUN_00cb1e40_op(int data, int size)
    {}
};

struct HashEntryTable
{
    unsigned long FindValueForKey(unsigned long key, unsigned long defaultValue);
};
// @fnv 0x00dc8e30
unsigned long __fastcall LookupWithDefault(HashEntryTable* self, int edx, unsigned long key)
{
    return ((HashEntryTable*)((char*)self + 0xc))->FindValueForKey(key, -1);
}

struct hkMapOperatorsCB19
{
    static unsigned hash(unsigned long key, unsigned long mod)
    {
        return unsigned((key >> 4) * 2654435761U) & mod;
    }
    static void invalidate(unsigned long& key)
    {
        key = unsigned long(-1);
    }
    static bool isValid(unsigned long key)
    {
        return key != unsigned long(-1);
    }
};

class hkMapBaseCB19
{
  public:
    struct Pair
    {
        unsigned long key;
        unsigned long val;
    };

    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void RemoveEntry(void* it) throw();
};

// Removes the map entry at the given slot, invalidates its key, and shifts later entries back to fill the gap.
// @f3 0x00922860 (community match, verified in this file)
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::remove | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: it
void hkMapBaseCB19::RemoveEntry(void* it) throw()
{
    typedef hkMapOperatorsCB19 OPS;
    unsigned i = unsigned(unsigned long(it));

    --m_iCapacityFlags;
    OPS::invalidate(((unsigned long*)m_kPrimitiveElement)[i]);

    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (OPS::isValid(((unsigned long*)m_kPrimitiveElement)[lo]))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    unsigned empty = i;

    for (i = (i + 1) & m_iPairCount; OPS::isValid(((unsigned long*)m_kPrimitiveElement)[i]); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = OPS::hash(((unsigned long*)m_kPrimitiveElement)[i], m_iPairCount);

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
        ((unsigned long*)m_kPrimitiveElement)[empty] = ((unsigned long*)m_kPrimitiveElement)[i];
        ((unsigned long*)m_kPrimitiveElement)[empty + m_iPairCount + 1] = ((unsigned long*)m_kPrimitiveElement)[i + m_iPairCount + 1];
        OPS::invalidate(((unsigned long*)m_kPrimitiveElement)[i]);
        empty = i;
    }
}


struct hkMapPairCB18
{
    unsigned int key;
    unsigned int val;
};

class FUN_00cb1830
{
  public:
    hkMapPairCB18* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    FUN_00cb1830(void* ptr, unsigned int sizeInBytes);
};

// @f3 0x00922640 (community match, verified in this file)
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> > | hkMap.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: ptr, sizeInBytes
FUN_00cb1830::FUN_00cb1830(void* apElements, unsigned int sizeInBytes)
{
    int maxKeys = sizeInBytes / sizeof(hkMapPairCB18);
    m_kPrimitiveElement = static_cast<hkMapPairCB18*>(apElements);
    m_iCapacityFlags = 0x80000000;
    m_iPairCount = maxKeys - 1;
    for (int i = 0; i < maxKeys; i++)
    {
        reinterpret_cast<unsigned int*>(m_kPrimitiveElement)[i] = 0xffffffff;
    }
}


namespace fnv_00cb1870 {

struct hkMapPairCB18
{
    unsigned int key;
    unsigned int val;
};

}  // namespace fnv_00cb1870

struct Allocator;
struct EdgeEntry
{
    int key;
    int value;
};
struct EdgeMap
{
    EdgeEntry* unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(Allocator& allocator, int count);
    int FindSlot(int key);
    void FUN_00cb1870(Allocator& allocator, int key, int value);
    void ProcessArgument(Allocator& allocator);
    void FUN_00a29680();
    int first() const
    {
        int i;
        for (i = 0; i <= unk08; ++i)
        {
            if (unk00[i].key != -1)
                break;
        }
        return i;
    }
    int next(int i) const
    {
        for (++i; i <= unk08; ++i)
        {
            if (unk00[i].key != -1)
                break;
        }
        return i;
    }
};
struct Manager
{
    int unk00, unk04, unk08, unk0c;
    Allocator* unk10;
    Allocator& heap()
    {
        return *unk10;
    }
};
struct Target
{
    int unk00, unk04;
    unsigned short* unk08;
    int unk0c, unk10;
    unsigned char* unk14;
    int unk18;
    bool* hkpConvexVerticesConnectivity_isClosed(bool* out);
};
// Checks that every edge in the vertex list appears exactly twice with opposite orientation, returning true only when all edge keys have value 3.
// @f3 0x00a76e00 (community match, verified in this file)
struct EdgeKeyMap
{
    int* m_elem;
    int m_numElems;
    int m_hashMod;
    void FUN_00922cb0();
    void FUN_00922cf0();
    int FindSlot(int key);
    void FUN_00922710(int key, int value);
    int count() const
    {
        return m_hashMod;
    }
    int& ValueAt(int i)
    {
        return m_elem[m_hashMod + 1 + i];
    }
    int first() const
    {
        int i;
        for (i = 0; i <= m_hashMod; ++i)
        {
            if (m_elem[i] != -1)
                break;
        }
        return i;
    }
    int next(int i) const
    {
        for (++i; i <= m_hashMod; ++i)
        {
            if (m_elem[i] != -1)
                break;
        }
        return i;
    }
};

// pdb: hkpConvexVerticesConnectivity::isClosed | hkpConvexVerticesConnectivity.obj | fnv360_0721_beta, caller_sim + skyrim(caller_sim), high
bool* Target::hkpConvexVerticesConnectivity_isClosed(bool* apResult)
{
    int index = 0;
    EdgeKeyMap edgeMap;
    edgeMap.FUN_00922cb0();
    int count = unk18;
    int iVertexOffset = 0;
    for (int i = 0; i < count; ++i)
    {
        int n = unk14[i];
        unsigned short* vertices = &unk08[iVertexOffset];
        int iPrevVertex = vertices[n - 1];
        for (int j = 0; j < n; ++j)
        {
            int iCurrVertex = vertices[j];
            unsigned int key;
            if (iPrevVertex < iCurrVertex)
                key = (static_cast<unsigned int>(iPrevVertex) << 16) | iCurrVertex;
            else
                key = (static_cast<unsigned int>(iCurrVertex) << 16) | iPrevVertex;
            int keyPlus = key + 1;
            int iOrientation = 1 + (iPrevVertex < iCurrVertex);
            index = edgeMap.FindSlot(keyPlus);
            if (index <= edgeMap.m_hashMod)
            {
                int& value = edgeMap.ValueAt(index);
                if (value & iOrientation)
                {
                    *apResult = false;
                    edgeMap.FUN_00922cf0();
                    return apResult;
                }
                value |= iOrientation;
            }
            else
            {
                edgeMap.FUN_00922710(keyPlus, iOrientation);
            }
            iPrevVertex = iCurrVertex;
        }
        iVertexOffset += n;
    }
    for (index = edgeMap.first(); index <= edgeMap.m_hashMod; index = edgeMap.next(index))
    {
        int& value = edgeMap.ValueAt(index);
        if (value != 3)
        {
            *apResult = false;
            edgeMap.FUN_00922cf0();
            return apResult;
        }
    }
    *apResult = true;
    edgeMap.FUN_00922cf0();
    return apResult;
}


typedef unsigned __int64 hkUint64CB1C;

struct MapOpsCB1C
{
    static inline unsigned hash(hkUint64CB1C key, unsigned mod)
    {
        return (unsigned)(((unsigned)key >> 4) * 0x9e3779b1u) & mod;
    }
    static inline bool isValid(hkUint64CB1C key)
    {
        return key != hkUint64CB1C(-1);
    }
    static inline bool equal(hkUint64CB1C key0, hkUint64CB1C key1)
    {
        return key0 == key1;
    }
};

struct MapCB1C
{
    struct Pair
    {
        hkUint64CB1C key;
        hkUint64CB1C val;
    };
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    hkUint64CB1C FUN_00cb1cb0(hkUint64CB1C key, hkUint64CB1C def) const;
};

struct hkMapOperatorsU64
{
    static unsigned hash(unsigned __int64 key, unsigned mod)
    {
        return unsigned((unsigned(key) >> 4) * 2654435761U) & mod;
    }
    static void invalidate(unsigned __int64& key)
    {
        key = (unsigned __int64)(-1);
    }
    static bool isValid(unsigned __int64 key)
    {
        return key != (unsigned __int64)(-1);
    }
};

class hkMapBaseU64
{
  public:
    struct Pair
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };

    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00cb1d20(unsigned it);
};

struct hkMapOperationsCB1F
{
    static unsigned hash(unsigned int key, unsigned mod)
    {
        return (unsigned(key) >> 4) * 2654435761U & mod;
    }
    static bool equal(unsigned int keyCur, unsigned int keyValue)
    {
        return keyCur == keyValue;
    }
    static bool isValid(unsigned int key)
    {
        return key != unsigned(-1);
    }
};

// Hashes key into the open-addressing table and linearly probes for a matching entry, returning its slot index or a not-found value.
// @f3 0x00922790 (community match, verified in this file)
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::findKey | hkMap.obj | fnv360_0822_retail, call_gap, high
// pdb params: key
__declspec(noinline) int FUN_00cb18f0_t::FindSlot(int key)
{
    unsigned int limit = m_iPairCount;
    int* entries = reinterpret_cast<int*>(m_uiStandInValue);
    unsigned int index = ((unsigned int)key >> 4) * 0x9e3779b1u & limit;
    int value = entries[index];
    while (value != -1) {
        if (value == key)
            return index;
        index = (index + 1) & limit;
        value = entries[index];
    }
    return limit + 1;
}

