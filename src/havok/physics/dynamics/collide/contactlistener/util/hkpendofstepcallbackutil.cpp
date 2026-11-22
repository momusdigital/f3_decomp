#include "f3_common.h"
// src/havok/physics/dynamics/collide/contactlistener/util/hkpendofstepcallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/contactlistener/util/hkpendofstepcallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d9ec10_cls
{
    void SwapThreeInts(int* a);
};

// Swaps the first three ints of this object with the first three ints of the given array.
// @fnv 0x00d9ec10
// pdb: hkArray<class hkpEntity *,struct hkContainerHeapAllocator>::swap | hkpWorldOperationUtil.obj | tesv_win, hash, low
void FUN_00d9ec10_cls::SwapThreeInts(int* paiValues)
{
    int* b = (int*)this;
    int t;
    t = b[0];
    b[0] = paiValues[0];
    paiValues[0] = t;
    t = b[1];
    b[1] = paiValues[1];
    paiValues[1] = t;
    t = b[2];
    b[2] = paiValues[2];
    paiValues[2] = t;
}

struct FirstBase
{
    int m_i00;
    int m_i04;
};

struct SecondBase
{
    int m_i00;
};

struct Derived : FirstBase, SecondBase
{
};

struct Target
{
    void FUN_00c93920(SecondBase* apObject);
};

// Calls FUN_00c93920 on apTarget, passing apObject as the argument.
// @fnv 0x00d9e250
void __fastcall PassObjectToTarget(Derived* apObject, void* apUnused, Target* apTarget)
{
    apTarget->FUN_00c93920(apObject);
}

struct S_00d9e2b0_Bool
{
    char m_cBooleanValue;
    S_00d9e2b0_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct S_00d9e2b0
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    S_00d9e2b0_Bool Equals(const S_00d9e2b0& other) const;
};

extern "C" void* __cdecl FUN_00c85750(void);
extern "C" void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

struct S_00d9e3f0_Router
{
    int unk00, unk04, unk08, unk0C;
    void* m10;
    static S_00d9e3f0_Router& GetMonitorStream()
    {
        return *(S_00d9e3f0_Router*)FUN_00c85750();
    }
};

struct S_00d9e3f0_Item
{
    int unk00, unk04, unk08, unk0C;
};

struct S_00d9e3f0_Arr
{
    S_00d9e3f0_Item* m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_00d9e3f0_Item& AllocatePair()
    {
        S_00d9e3f0_Router& r = S_00d9e3f0_Router::GetMonitorStream();
        if (m_iElementCount == (int)(m_cap & 0x3fffffff))
            ResizeAudioStream(r.m10, this, sizeof(S_00d9e3f0_Item));
        return m_data[m_iElementCount++];
    }
};

struct S_00d9ec40_Ref
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    unsigned int m_iOwnerObjectOffset;
};

struct S_00d9ec40_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    S_00d9ec40_Ref* m_kPointA;
    S_00d9ec40_Ref* m_kPointB;
};

struct __declspec(align(16)) S_00d9ec40_Entry
{
    S_00d9ec40_Obj* m_obj;
    int unk4;
    int unk8;
    int m_order;
};

static inline unsigned __int64 S_00d9ec40_getKey(const S_00d9ec40_Entry& e)
{
    return ((unsigned __int64)e.m_obj->m_kPointA->m_iOwnerObjectOffset << 32) | e.m_obj->m_kPointB->m_iOwnerObjectOffset;
}

struct S_00d9ec40_Less
{
    inline bool operator()(const S_00d9ec40_Entry& a, const S_00d9ec40_Entry& b) const
    {
        unsigned __int64 ka = S_00d9ec40_getKey(a);
        unsigned __int64 kb = S_00d9ec40_getKey(b);
        return ka < kb || (ka == kb && a.m_order < b.m_order);
    }
};

namespace fnv_00d9ee20 {
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

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d9ee20_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d0b0d0();

    FUN_00d9ee20_cls* FUN_00d9ee20(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00d9ee20

#include <windows.h>

struct S_00d9ea80_Heap
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00d9ea80_Router
{
    int unk0, unk4, unk8, unkc;
    S_00d9ea80_Heap* m_pStreamAllocator;
    static S_00d9ea80_Router& GetMonitorStream()
    {
        return *(S_00d9ea80_Router*)FUN_00c85750();
    }
    S_00d9ea80_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(S_00d9ea80_Heap*, void* arr, int n, int elemSize);

struct S_00d9ea80_Info
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
    short unk24;
    unsigned char flags26;
};
struct S_00d9ea80_Sub
{
    S_00d9ea80_Info* FUN_00cf3dd0();
};
struct S_00d9ea80_Obj
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual S_00d9ea80_Sub* FUN_vfn40();
};

struct S_00d9ea80_Entry
{
    S_00d9ea80_Obj* obj;
    int a;
    int b;
};
struct S_00d9ea80_EntryArray
{
    S_00d9ea80_Entry* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(S_00d9ea80_Heap& a, int n)
    {
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap * 2;
            FUN_00c908c0(&a, this, (n < c2) ? c2 : n, sizeof(S_00d9ea80_Entry));
        }
    }
};

// sub ecx,8; jmp FUN_00d9ee20  ==  MSVC adjustor thunk (multiple inheritance, 8-byte primary base).
struct AdjPrimaryBase
{
    virtual void FUN_00d9ee10();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void FUN_00d9ee10();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d9ee10
    virtual void FUN_00d9ee10();
};

AdjDerived::AdjDerived()
{}

struct EventFlag
{
    char value;
    EventFlag()
    {}
    EventFlag(bool v) : value((char)v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct EventBase
{
    int unk00, unk04, unk08;
    void* unk0c;
    EventBase(int source, int first, int second, void* owner) : unk00(source), unk0c(owner)
    {
        unk04 = first;
        unk08 = second;
    }
};
struct S_Notify : EventBase
{
    int unk10;
    char* unk14;
    char* unk18;
    EventFlag unk1c, unk1d, unk1e;
    float* unk20;
    float* unk24;
    char* unk28;
    void* unk2c;
    void* unk30;
    S_Notify(int source, int first, int second, void* owner, int kind, char* point, char* properties, float* velocity,
             float* normal, EventFlag full, EventFlag initial, EventFlag final, char* keys, void* accumulatorA,
             void* accumulatorB)
        : EventBase(source, first, second, owner), unk10(kind), unk14(point), unk18(properties), unk1c(full),
          unk1d(initial), unk1e(final), unk20(velocity), unk24(normal), unk28(keys)
    {
        unk2c = accumulatorA;
        unk30 = accumulatorB;
    }
};

struct S_Listener
{
    virtual void Notify0(S_Notify* n);
};

struct ListenerArg
{
    S_Listener* p;
    ListenerArg(S_Listener* v) : p(v)
    {}
};

struct StripCollisionD9E : S_00d9e2b0
{
    S_00d9e2b0_Bool Equals(const StripCollisionD9E& other) const;
};
struct hkMemAllocatorD9E
{
    virtual void Slot0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    virtual void* BufRealloc(void* pold, int oldNumBytes, int& reqNumBytesInOut);
};
struct hkMemRouterD9E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemAllocatorD9E* m_pStreamAllocator;
    __forceinline hkMemAllocatorD9E& heap()
    {
        return *m_pStreamAllocator;
    }
    static __forceinline hkMemRouterD9E& GetMonitorStream()
    {
        return *static_cast<hkMemRouterD9E*>(FUN_00c85750());
    }
};
void __cdecl FUN_00c908c0(hkMemAllocatorD9E* alloc, void* array, int reqNumElems, int sizeElem);

static __forceinline StripCollisionD9E* bufAllocD9E(hkMemAllocatorD9E* alloc, int& n)
{
    int nbytes = n * (int)sizeof(StripCollisionD9E);
    StripCollisionD9E* p = static_cast<StripCollisionD9E*>(alloc->AllocateBufferWithSize(nbytes));
    n = nbytes / (int)sizeof(StripCollisionD9E);
    return p;
}
struct CopyTypeD9E
{
    int x;
};
template <unsigned int ELEMENTSIZE> static __forceinline void memCpyOneAlignedD9E(void* dst, const void* src)
{
    int i = 0;
    do
    {
        static_cast<CopyTypeD9E*>(dst)[i] = static_cast<const CopyTypeD9E*>(src)[i];
        ++i;
    } while (i < int(ELEMENTSIZE / sizeof(CopyTypeD9E)));
}
struct ElemArrayD9E
{
    StripCollisionD9E* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static __forceinline hkMemAllocatorD9E* heap()
    {
        return static_cast<hkMemRouterD9E*>(FUN_00c85750())->m_pStreamAllocator;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ElemArrayD9E(int n)
    {
        int cap = n;
        StripCollisionD9E* p;
        int flags;
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = (int)0x80000000;
        hkMemRouterD9E* router = static_cast<hkMemRouterD9E*>(FUN_00c85750());
        hkMemAllocatorD9E* alloc = router->m_pStreamAllocator;
        p = cap ? bufAllocD9E(alloc, cap) : 0;
        flags = cap ? cap : (int)0x80000000;
        m_data = p;
        m_iElementCount = cap;
        m_iCapacityState = flags;
    }
    __forceinline int indexOf(const StripCollisionD9E& t) const
    {
        int end = m_iElementCount;
        for (int i = 0; i < end; ++i)
        {
            if (m_data[i].Equals(t).m_cBooleanValue)
                return i;
        }
        return -1;
    }
    __forceinline void removeAt(int idx)
    {
        m_iElementCount--;
        if (m_iElementCount != idx)
            memCpyOneAlignedD9E<sizeof(StripCollisionD9E)>(m_data + idx, m_data + m_iElementCount);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemAllocatorD9E& alloc = hkMemRouterD9E::GetMonitorStream().heap();
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(StripCollisionD9E));
        }
        m_iElementCount = n;
    }
    __forceinline void ClearAndRelease()
    {
        hkMemAllocatorD9E& alloc = hkMemRouterD9E::GetMonitorStream().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * (int)sizeof(StripCollisionD9E));
    }
    void SwapThreeInts(ElemArrayD9E& other);
};

struct hkValue8b0
{
    S_00d9ec40_Obj* m_pkObj;
    int m_iA;
    int m_iB;
};
struct __declspec(align(16)) hkEntry8b0
{
    hkValue8b0 m_kValue;
};

struct BatchCollision : S_00d9e2b0
{
    __declspec(noinline) S_00d9e2b0_Bool Equals(const BatchCollision& other) const;
};
struct BatchHeap
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* allocate(int* bytes);
    virtual void freeBuffer(void* data, int bytes);
};
struct BatchContext
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    BatchHeap* heap;
};

static __forceinline void transferEntry(void* out, const void* in)
{
    unsigned k = 0;
    do
    {
        ((int*)out)[k] = ((const int*)in)[k];
    } while (++k < 3);
}
template <class T> struct BatchArrayView
{
    T* data;
    int count;
    int capacity;
    __forceinline BatchArrayView() : data(0), count(0), capacity(0x80000000)
    {}
    __forceinline int size() const
    {
        return count;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline int find(const T& item, int start = 0, int end = -1) const
    {
        if (end < 0)
            end = count;
        for (int i = start; i < end; ++i)
        {
            if (data[i].Equals(item).m_cBooleanValue)
                return i;
        }
        return -1;
    }
    __forceinline void remove(int i)
    {
        --count;
        if (count != i)
            transferEntry(data + i, data + count);
    }
};
struct IncomingBatch : BatchArrayView<S_00d9e3f0_Item>
{
};
struct PendingBatch : BatchArrayView<BatchCollision>
{
};
static __forceinline S_00d9e3f0_Item* makeAllocation(BatchHeap* heap, int& size)
{
    int bytes = size * 16;
    S_00d9e3f0_Item* result = (S_00d9e3f0_Item*)heap->allocate(&bytes);
    size = bytes / 16;
    return result;
}
struct BatchBuffer;
extern "C" void __cdecl FUN_00c908c0(BatchHeap*, BatchBuffer*, int, int);
struct BatchBuffer : BatchArrayView<S_00d9e3f0_Item>
{
    __forceinline BatchBuffer(int size) : BatchArrayView<S_00d9e3f0_Item>()
    {
        BatchContext* context = (BatchContext*)FUN_00c85750();
        BatchHeap* heap = context->heap;
        S_00d9e3f0_Item* allocation = size ? makeAllocation(heap, size) : 0;
        int cap = size ? size : 0x80000000;
        data = allocation;
        count = size;
        capacity = cap;
    }
    __forceinline void resize(int size)
    {
        BatchContext* context = (BatchContext*)FUN_00c85750();
        BatchHeap* heap = context->heap;
        int cap = capacity & 0x3fffffff;
        if (cap < size)
            FUN_00c908c0(heap, this, size < 2 * cap ? 2 * cap : size, 16);
        count = size;
    }
    __forceinline void clear()
    {
        BatchContext* context = (BatchContext*)FUN_00c85750();
        BatchHeap* heap = context->heap;
        count = 0;
        if ((capacity & 0x80000000) == 0)
            heap->freeBuffer(data, (capacity & 0x3fffffff) * 16);
    }
};
struct DestinationArg
{
    PendingBatch* p;
    DestinationArg(PendingBatch* v) : p(v)
    {}
    __forceinline PendingBatch* get() const
    {
        return p;
    }
};
struct IncomingArg
{
    IncomingBatch* p;
    IncomingArg(IncomingBatch* v) : p(v)
    {}
};
