#include "f3_common.h"
// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPoweredChainMapper.h"

class hkMemoryAllocatorE3A5;

struct hkMemoryRouterE3A5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE3A5* m_pStreamAllocator;
};

namespace hkRouterE3A5 {
extern "C" hkMemoryRouterE3A5& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE3A5
{
    char m_cBooleanValue;
    hkBoolE3A5()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE3A5(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE3A5
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE3A5& router = hkRouterE3A5::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE3A5<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct hkRowE3A5
{
    int m_slots[20];
};

struct hkTableE3A5
{
    int unk00[16];
    hkRowE3A5 m_rows[1];
};

struct hkOwnerE3A5
{
    int unk00[6];
    hkTableE3A5* m_table;
};

struct hkRefE3A5
{
    hkOwnerE3A5* m_pOwnerObject;
    int m_row;
};

struct hkRangeE3A5
{
    int m_kRayStart;
    int m_uiItemCount;
    int unk08;
};

class hkSetE3A5
{
  public:
    int unk00;
    int unk04;
    hkRangeE3A5* m_ranges;
    int unk0C;
    int unk10;
    hkRefE3A5* m_refs;

    void CollectSlotValues(int range, int slot, hkArrayE3A5<int>& out);
};

// Iterates the refs of a range and appends the slot value from each owner's table row to out when non-zero.
// @f3 0x00a6fa50 (community match, verified in this file)
extern "C" void __cdecl FUN_00901f10(void*, int);

// pdb: hkpPoweredChainMapper::getMotors | hkpPoweredChainMapper.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: linkIndex, coordinateIndex, motorsOut
void hkSetE3A5::CollectSlotValues(int range, int slot, hkArrayE3A5<int>& out)
{
    const hkRangeE3A5& r = m_ranges[range];
    for (int i = 0; i < r.m_uiItemCount; i++)
    {
        const hkRefE3A5& ref = m_refs[r.m_kRayStart + i];
        int v = ref.m_pOwnerObject->m_table->m_rows[ref.m_row].m_slots[slot];
        if (v)
        {
            if (out.m_iElementCount == (out.m_iCapacityState & 0x3fffffff))
                FUN_00901f10(&out, 4);
            out.m_data[out.m_iElementCount] = v;
            out.m_iElementCount++;
        }
    }
}


struct FnPlacement
{
};
inline void* operator new(unsigned int, FnPlacement* p)
{
    return p;
}
struct FnAllocator
{
    virtual void reserved0();
    virtual void* allocate(int size) throw();
    virtual void VirtualFunction8();
    virtual void reservedC();
    virtual void release(void* pointer, int size) throw();
};
struct FnMemory
{
    void* base;
    int reserved04;
    int reserved08;
    int reserved0C;
    FnAllocator* heap;
    FnAllocator& getHeap() const
    {
        return *heap;
    }
};
extern "C" FnMemory* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(FnAllocator*, void*, int, int);
extern "C" void __cdecl ResizeAudioStream(FnAllocator*, void*, int);
extern "C" int DAT_010e0654;

template <class T> struct FnArray
{
    T* data;
    int size;
    int capacity;
    FnArray() throw() : data(0), size(0), capacity(0x80000000)
    {}
    ~FnArray() throw()
    {
        clear();
    }
    void clear()
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        size = 0;
        if (!(capacity & 0x80000000))
            heap.release(data, sizeof(T) * (capacity & 0x3fffffff));
        data = 0;
        capacity = 0x80000000;
    }
    void reserve(FnAllocator& heap, int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            cap *= 2;
            if (n >= cap)
                cap = n;
            FUN_00c908c0(&heap, this, cap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(FnAllocator& allocator, int count)
    {
        reserve(allocator, count);
        int n = count - size;
        T* p = data + size;
        if (n > 0)
            do
            {
                new ((FnPlacement*)p) T;
                ++p;
            } while (--n);
        size = count;
    }
    void push(const T& value)
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, sizeof(T));
        T* destination = data + size;
        const T* source = &value;
        for (int i = 0; i < 1; ++i)
            *destination++ = *source++;
        ++size;
    }
    T& expand()
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, sizeof(T));
        return data[size++];
    }
};
struct FnMap
{
    struct Entry
    {
        int key;
        int value;
    };
    Entry* data;
    int size;
    int capacity;
    FnMap() throw() : data(0), size(0), capacity(-1)
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        EnsureCapacity(&heap, 0);
    }
    ~FnMap() throw()
    {
        ProcessArgument(FUN_00c85750()->heap);
        FUN_00a29680();
    }
    void __thiscall EnsureCapacity(FnAllocator*, int) throw();
    void __thiscall FUN_00cb1870(FnAllocator*, int, int) throw();
    int __thiscall FindSlot(int) throw();
    void __thiscall ProcessArgument(FnAllocator*) throw();
    void __thiscall FUN_00a29680() throw();
};
struct FnNodePair
{
    int first;
    int second;
};
struct FnLink
{
    int offset;
    int count;
    int fallback;
    FnLink() : offset(-1), count(0), fallback(0)
    {}
};
struct FnTarget
{
    void* constraint;
    int target;
};
struct FnVisit
{
    void* constraint;
    int localIndex;
    int linkIndex;
};
struct FnConstraint
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0C();
    virtual void VirtualFunction10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1C();
    virtual int getType() throw();
};
struct FnObject
{
    int reserved00;
    int reserved04;
    int reserved08;
    FnConstraint* constraint;
    void __thiscall FUN_00c905b0() throw();
};
struct FnMapper
{
    void* vtable;
    unsigned short GetAllocationSize;
    unsigned short refs;
    FnArray<FnLink> links;
    FnArray<FnTarget> targets;
    FnArray<FnObject*> chains;
    static void* operator new(unsigned int size)
    {
        FnAllocator& allocator = FUN_00c85750()->getHeap();
        FnMapper* p = (FnMapper*)allocator.allocate(size);
        p->GetAllocationSize = (unsigned short)size;
        return p;
    }
    FnMapper() : vtable(&DAT_010e0654), refs(1)
    {}
};
struct FnDiagnostic
{
    int stream;
    int cursor;
    int capacity;
    void __thiscall FUN_00cb1600(char*, int) throw();
    void __thiscall FUN_00cc01c0(const char*) throw();
    void __thiscall FUN_00cc00e0() throw();
};
struct FnLogger
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void report(int, unsigned int, char*, const char*, int) throw();
};
extern "C" FnLogger* DAT_01268360;
inline void reportError(const char* message, unsigned int id, int line)
{
    unsigned int buffer[128];
    FnDiagnostic diagnostic;
    diagnostic.FUN_00cb1600((char*)buffer, 512);
    diagnostic.FUN_00cc01c0(message);
    DAT_01268360->report(1, id, (char*)buffer, ".\\Constraint\\Chain\\hkpPoweredChainMapper.cpp", line);
    diagnostic.FUN_00cc00e0();
}
__forceinline int buildOffsets(FnMapper* mapper, FnArray<int>& linkCounts)
{
    int total = 0;
    for (int i = 0; i < mapper->links.size; ++i)
    {
        mapper->links.data[i].offset = total;
        total += linkCounts.data[i];
        mapper->links.data[i].count = 0;
    }
    return total;
}
struct FnFlags
{
    unsigned char copyFallbacks;
    unsigned char includeChains;
};
// Builds an FnMapper by resolving constraint chains for node pairs, populating link offsets, targets, and optionally collecting unlinked ids.
// @f3 0x00a6fae0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_010f3170;

struct HkRouter
{
    void* alloc(int size, int size2) throw();
    void release(void* p, int size, int tag) throw();
};
inline HkRouter* getRouter() throw()
{
    return (HkRouter*)TlsGetValue(DAT_010f3170);
}

extern "C" void __cdecl HkReserve(void* arr, int cap, int elemSize) throw();
extern "C" void __cdecl HkGrow(void* arr, int elemSize) throw();
extern "C" void __cdecl HkMemSet(void* p, int v, int n) throw();

template <class T> struct HArr
{
    T* data;
    int size;
    int cap;
    HArr() throw() : data(0), size(0), cap(0x80000000)
    {}
    ~HArr() throw()
    {
        if (!(cap & 0x80000000))
        {
            int n = cap & 0x3fffffff;
            HkRouter* r = getRouter();
            r->release(data, n * sizeof(T), 0x17);
        }
    }
    void reserve(int n)
    {
        int c = cap & 0x3fffffff;
        if (c < n)
        {
            c *= 2;
            if (n >= c)
                c = n;
            HkReserve(this, c, sizeof(T));
        }
    }
    T& expand()
    {
        if (size == (cap & 0x3fffffff))
            HkGrow(this, sizeof(T));
        return data[size++];
    }
};

struct HMap
{
    int* data;
    int unk04;
    int count;
    HMap() throw();
    ~HMap() throw();
    void insert(int key, int value) throw();
    int find(int key) throw();
};

struct HConstraint
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int getType() throw();
};
struct HChain
{
    void* vtable;
    unsigned short size;
    short refs;
    int unk08;
    HConstraint* constraint;
    void release() throw()
    {
        if (size != 0)
        {
            refs = refs - 1;
            if (refs == 0)
                (*(void(__thiscall**)(HChain*, int))vtable)(this, 1);
        }
    }
};
struct HRefObj
{
    void* vtable;
    unsigned short memSize;
    short refCount;
    void removeReference() throw()
    {
        if (memSize != 0)
        {
            refCount = refCount - 1;
            if (refCount == 0)
                (*(void(__thiscall**)(HRefObj*, int))vtable)(this, 1);
        }
    }
};
inline void releaseMapper(FnMapper* m) throw()
{
    ((HRefObj*)m)->removeReference();
}
template <class A> inline void reserveGeneric(A& a, int n, int elemSize) throw()
{
    int c = a.capacity & 0x3fffffff;
    if (c < n)
    {
        c *= 2;
        if (n >= c)
            c = n;
        HkReserve(&a, c, elemSize);
    }
}
extern "C" int __cdecl HkFindChain(hkArray<int>*, int, int, HArr<int>*, HArr<int>*) throw();
extern "C" HChain* __cdecl HkBuildChain(HArr<int>*, unsigned char) throw();
extern "C" int __cdecl HkCloneInstance(int) throw();

struct HRefBase
{
    unsigned short GetAllocationSize;
    unsigned short refs;
    virtual ~HRefBase() throw();
    HRefBase() throw() : refs(1)
    {}
};
HRefBase::~HRefBase() throw()
{}
struct FnMapperNew : HRefBase
{
    FnArray<FnLink> links;
    FnArray<FnTarget> targets;
    FnArray<FnObject*> chains;
    FnMapperNew() throw()
    {}
    virtual ~FnMapperNew() throw();
    static void* operator new(unsigned int sz) throw()
    {
        HkRouter* r = getRouter();
        FnMapperNew* p = (FnMapperNew*)r->alloc(sz, sz);
        p->GetAllocationSize = (unsigned short)sz;
        return p;
    }
};
FnMapperNew::~FnMapperNew() throw()
{}

template <class A> inline void setSizeTo(A* a, int n, int elemSize) throw()
{
    int c = a->capacity & 0x3fffffff;
    if (c < n)
    {
        c *= 2;
        if (n >= c)
            c = n;
        HkReserve(a, c, elemSize);
    }
    a->size = n;
}
// pdb: hkpPoweredChainMapper::buildChainMapper | hkpPoweredChainMapper.obj | fnv360_0822_retail, ustr, high
// pdb params: config, allConstraints, pairs, unusedConstraints
// pdb: hkpPoweredChainMapper::buildChainMapper | hkpPoweredChainMapper.obj | fnv360_0822_retail, ustr, high (was: BuildPoweredChainMapper)
FnMapper* __cdecl hkpPoweredChainMapper_buildChainMapper(FnFlags flags, hkArray<int>* linkIds, hkArray<FnNodePair>* pairs, hkArray<int>* unlinked) throw()
{
    FnMapper* mapper = (FnMapper*)new FnMapperNew;
    HArr<FnVisit> visits;
    HArr<int> linkCounts;
        int n = linkIds->m_iElementCount;
    if (n > 0)
        HkReserve(&linkCounts, linkIds->m_iElementCount < 0 ? 0 : linkIds->m_iElementCount, 4);
    linkCounts.size = n;
    HkMemSet(linkCounts.data, 0, n * 4);
    HMap map;
    for (int i = 0; i < linkIds->m_iElementCount; i++)
        map.insert(linkIds->m_data[i], i);
    int count = linkIds->m_iElementCount;
    setSizeTo(&mapper->links, count, 12);
    HkMemSet(mapper->links.data, 0, mapper->links.size * 12);
    for (int p = 0; p < pairs->m_iElementCount; p++)
    {
        const FnNodePair& pr = pairs->m_data[p];
        HArr<int> Y;
        HArr<int> X;
        if (HkFindChain(linkIds, pr.first, pr.second, &Y, &X) == 1)
        {
            reportError("Cannot find a chain of constraints linking one of the entity pairs.", 0xabbaaa88, 0x44);
            releaseMapper(mapper);
            return 0;
        }
        unsigned char inc = flags.includeChains;
        HChain* chain = HkBuildChain(&X, inc);
        if (!chain)
        {
            reportError("Failed to build a chain.", 0xabbaddaa, 0x4e);
            releaseMapper(mapper);
            return 0;
        }
        FnArray<FnObject*>& ch = mapper->chains;
        if (ch.size == (ch.capacity & 0x3fffffff))
            HkGrow(&ch, 4);
        ch.data[ch.size] = (FnObject*)chain;
        ch.size++;
        for (int j = 0; j < X.size; j++)
        {
            int key = X.data[j];
            int idx = map.find(key);
            if (idx > map.count)
            {
                reportError("Internal error.", 0xabba99dd, 0x5d);
                chain->release();
                releaseMapper(mapper);
                return 0;
            }
            int li = map.data[map.count + idx + 1];
            int jj = j;
            FnLink* link = &mapper->links.data[li];
            FnVisit& v = visits.expand();
            v.linkIndex = li;
            linkCounts.data[li]++;
            if (chain->constraint->getType() != 0x66)
            {
                reportError("Internal error; invalid chain type.", 0xabba9d6d, 0x6c);
                chain->release();
                releaseMapper(mapper);
                return 0;
            }
            v.constraint = chain->constraint;
            v.localIndex = jj;
            if (flags.copyFallbacks && link->fallback == 0)
                link->fallback = HkCloneInstance(X.data[j]);
        }
    }
    int total = 0;
    for (int i = 0; i < mapper->links.size; ++i)
    {
        mapper->links.data[i].offset = total;
        total += linkCounts.data[i];
        mapper->links.data[i].count = 0;
    }
    setSizeTo(&mapper->targets, total, 8);
    for (int k = 0; k < visits.size; k++)
    {
        FnVisit& v = visits.data[k];
        FnLink& l = mapper->links.data[v.linkIndex];
        FnTarget* tgts = mapper->targets.data;
        int idx = l.count + l.offset;
        tgts[idx].constraint = v.constraint;
        tgts[idx].target = v.localIndex;
        l.count++;
    }
    if (unlinked)
    {
        for (int i = 0; i < mapper->links.size; i++)
        {
            if (mapper->links.data[i].count == 0)
            {
                const int& e = linkIds->m_data[i];
                if (unlinked->m_iElementCount == (unlinked->m_iCapacityState & 0x3fffffff))
                    HkGrow(unlinked, 4);
                unlinked->m_data[unlinked->m_iElementCount] = e;
                unlinked->m_iElementCount++;
            }
        }
    }
    return mapper;
}


#include <xmmintrin.h>
struct TargetRuntime
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_vVectorData;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    TargetRuntime* m_pRuntime;
};

struct hkpPoweredChainMapperTarget
{
    ChainInstance* m_pChainInstance;
    int m_targetIndex;
};

struct hkpPoweredChainMapperLinkInfo
{
    int m_iChainIndex;
    int m_iLinkIndex;
    int unk08;
};

class hkMemoryAllocatorE3A3
{
  public:
    virtual ~hkMemoryAllocatorE3A3() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE3A3
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE3A3* m_pStreamAllocator;
    hkMemoryAllocatorE3A3& heap()
    {
        return *m_pStreamAllocator;
    }
};

template <class T> __forceinline void destructE3A3(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE3A3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T& operator[](int i)
    {
        T* p0 = m_data;
        T* p1 = p0;
        T* p2 = p1;
        T* p3 = p2;
        T* p4 = p3;
        T* p5 = p4;
        T* p6 = p5;
        T* p7 = p6;
        T* p8 = p7;
        T* p9 = p8;
        T* p10 = p9;
        T* p11 = p10;
        T* p12 = p11;
        T* p13 = p12;
        T* p14 = p13;
        T* p15 = p14;
        T* p16 = p15;
        T* p17 = p16;
        T* p18 = p17;
        T* p19 = p18;
        return p19[i];
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE3A3() throw()
    {
        ClearAndRelease(FUN_00c85750()->getHeap());
    }
    __forceinline void clear()
    {
        destructE3A3(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(FnAllocator& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.release(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkReferencedObjectE3A3
{
  public:
    virtual ~hkReferencedObjectE3A3() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

namespace FUN_00e3a3d0 {

}

class hkMemoryAllocatorE3AD
{
  public:
    virtual ~hkMemoryAllocatorE3AD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE3AD
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE3AD* m_pStreamAllocator;

    hkMemoryAllocatorE3AD& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkR3AD {
hkMemoryRouterE3AD& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayE3AD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        T* p = m_data;
        return p[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }

    ~hkArrayE3AD() throw()
    {
        hkMemoryAllocatorE3AD& kAlloc = hkR3AD::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkE3AD {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};
}

namespace hkE3AD {
struct LinkInfoE3AD
{
    int unk00;
    int unk04;
    hkReferencedObject* m_pConstraintInstance;
};

struct TargetE3AD
{
    int unk00;
    int unk04;
};
}

namespace FUN_00e3ad80 {
class hkpPoweredChainMapper : public hkE3AD::hkReferencedObject
{
  public:
    virtual ~hkpPoweredChainMapper();

    hkArrayE3AD<hkE3AD::LinkInfoE3AD> m_ppLinks;
    hkArrayE3AD<hkE3AD::TargetE3AD> m_kTargets;
    hkArrayE3AD<hkE3AD::hkReferencedObject*> m_kChainInstances;
};

}
