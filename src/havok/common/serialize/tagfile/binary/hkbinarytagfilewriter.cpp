#include "f3_common.h"
// src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSAudio
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
};
BSAudio* __cdecl FUN_00c85750();
struct UnkRet
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
};
struct UnkHolder
{
    int a;
    int b;
    int c;
    void __thiscall FUN_00dbedb0(UnkRet*, int);
};
struct FUN_00dc0380
{
    BSAudio* p;
    UnkHolder unk;
    int a;
    int b;
    int c;
    FUN_00dc0380(BSAudio* v);
};
// @fnv 0x00dc0380
FUN_00dc0380::FUN_00dc0380(BSAudio* pAudio)
{
    p = pAudio;
    UnkHolder* h = &unk;
    h->a = 0;
    h->b = 0;
    h->c = -1;
    BSAudio* r = FUN_00c85750();
    h->FUN_00dbedb0(reinterpret_cast<UnkRet*>(*(reinterpret_cast<int**>(r) + 4)), 0);
    a = 0;
    b = 0;
    c = 0x80000000;
}

struct ObjectHandle
{
    void* object;
    __declspec(nothrow) int FUN_00dbac00();
    __declspec(nothrow) void FUN_00dbab70();
    ~ObjectHandle()
    {
        FUN_00dbab70();
    }
};
struct StringHandle
{
    void* object;
    __declspec(nothrow) int FUN_00dba980();
    __declspec(nothrow) void FUN_00dba7f0();
    ~StringHandle()
    {
        FUN_00dba7f0();
    }
};

struct ResourceKey
{
    int first;
    int second;
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
};

inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
void* __cdecl _fnv_zlib_memset(void* dst, int val, int n);

struct hkCharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->tempHeap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, 1);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        char* p = m_data + m_iElementCount;
        int num = n - m_iElementCount;
        if (num <= 0)
        {
            m_iElementCount = n;
            return;
        }
        _fnv_zlib_memset(p, 0, num);
        m_iElementCount = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct FUN_00dbef20 : hkCharArray
{
    FUN_00dbef20(int n);
};

// Initializes the char array to empty, reserves capacity rounded up to a multiple of 8, then sets the size to n.
// @fnv 0x00dbef20
FUN_00dbef20::FUN_00dbef20(int aiSize)
{
    m_data = 0;
    m_iElementCount = 0;
    m_iCapacityState = 0x80000000;
    SetSizeAndGrow((aiSize + 7) & ~7);
    setSizeUnchecked(aiSize);
}

namespace fnv_00dc0460 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct Elem24
{
    int v[6];
};

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = audio()->tempHeap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct MemberA
{
    int pad[4];
    void FreeBuffer();
};
struct MemberB
{
    int pad[3];
    void AllocBufferIfNotFlagged(hkMemoryAllocator* alloc);
};
struct MemberC
{
    void ClearArray();
};

struct BaseObj
{
    int pad[4];
    void FUN_00d60590();
};

struct Obj : BaseObj
{
    MemberA m10;
    MemberA m20;
    int unk30;
    MemberB m34;
    hkArray<char> m40;
    hkArray<Elem24> m4c;
    MemberC m58;
    void FUN_00dc0460();
};

}  // namespace fnv_00dc0460

struct CallbackTarget
{
    virtual void Dummy0()
    {}
    virtual void Dummy1()
    {}
    virtual void Dummy2()
    {}
    virtual void Dummy3()
    {}
    virtual void Dummy4()
    {}
    virtual void Complete()
    {}
};
// @f3 0x00933ce0 (community match, verified in this file)
extern const char DAT_00e77288[];
extern const char DAT_00e77274[];
namespace f3m_00933ce0 {
namespace f3m_00933ce0 {


struct PairValue93 { unsigned int f0, f1; };

struct NamedRef93
{
    void* source;
    const char* name;
    void FUN_0093d600(void* src, const char* nm);
    PairValue93* FUN_0093d760(int flag);
};

} // namespace f3m_00933ce0

using namespace f3m_00933ce0;

int __cdecl FUN_00933ce0(int value, CallbackTarget* target, int source)
{
    NamedRef93 first, second, third, fourth;
    first.FUN_0093d600((void*)(size_t)value, DAT_00e77288);
    second.FUN_0093d600((void*)target, DAT_00e77288);
    third.FUN_0093d600((void*)(size_t)value, DAT_00e77274);
    fourth.FUN_0093d600((void*)target, DAT_00e77274);
    PairValue93* gotFirst = first.FUN_0093d760(0);
    *second.FUN_0093d760(0) = *gotFirst;
    PairValue93* gotThird = third.FUN_0093d760(0);
    PairValue93* destination = fourth.FUN_0093d760(0);
    PairValue93* __restrict dst = destination;
    const PairValue93* __restrict src = gotThird;
    *dst = *src;
    return (int)destination;
}
}   // namespace f3m_00933ce0


struct Obj
{
    void __thiscall hkOArchive_write8u(unsigned char);
    void __thiscall WriteVarint(__int64);
};

struct FUN_00dbe8c0_cls
{
    struct HashEntry
    {
        unsigned int key0;
        unsigned int key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    unsigned int hkAgentNnMachine_FindAgent(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault);
};

// A 12-byte hash table (as used by the hkPackfileWriter module): a pointer to
// an array of 12-byte entries, a flag word and the number of entries.
struct HashEntry
{
    int unk00;
    int unk04;
    int unk08;
};

struct AllocOwner
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};

struct Entry12
{
    int a;
    int b;
    int c;
};

struct FUN_00dbe810_cls
{
    void InsertOrUpdate(AllocOwner* alloc, int e0, int e1, int e2);
};

struct FUN_00dbec60_cls
{
    Entry12* m_00;
    unsigned int m_04;
    int m_08;

    void FUN_00dbec60(AllocOwner* alloc, int count);
};

// @fnv 0x00dbec60
void FUN_00dbec60_cls::FUN_00dbec60(AllocOwner* alloc, int count)
{
    int newCap = count;
    if (newCap <= 8)
        newCap = 8;

    unsigned int oldFlags = m_04 & 0x80000000u;
    Entry12* pOldEntries = m_00;
    int oldCount = m_08 + 1;

    m_00 = (Entry12*)alloc->Alloc(newCap * 12);
    for (int i = 0; i < newCap; ++i)
        m_00[i].a = 0;

    m_04 = 0;
    m_08 = newCap - 1;

    for (int i = 0; i < oldCount; ++i)
    {
        if (pOldEntries[i].a == 0)
            continue;
        volatile Entry12* v = pOldEntries;
        reinterpret_cast<FUN_00dbe810_cls*>(this)->InsertOrUpdate(alloc, v[i].a, v[i].b, v[i].c);
    }

    if (oldFlags == 0)
        alloc->Free(pOldEntries, oldCount * 12);
}

struct S_dbefc0_Heap
{
    int unk;
};
struct S_dbefc0_Router
{
    int unk00;
    int unk04;
    int unk08;
    S_dbefc0_Heap* unk0c;
    S_dbefc0_Heap& heap()
    {
        return *unk0c;
    }
};
void __cdecl FUN_00c908c0(S_dbefc0_Heap* heap, void* arr, int n, int elemSize);
void* __cdecl FUN_00ec61c0(void* dst, int value, unsigned int count);

static __forceinline S_dbefc0_Heap& S_dbefc0_GetHeap()
{
    return ((S_dbefc0_Router*)FUN_00c85750())->heap();
}

struct S_dbefc0_Bytes
{
    char* data;
    int size;
    int cap;

    __forceinline void GrowArrayCapacity(S_dbefc0_Heap& heap, int n)
    {
        int c = cap & 0x3fffffff;
        if (c < n)
        {
            int c2 = c + c;
            FUN_00c908c0(&heap, this, (n < c2) ? c2 : n, 1);
        }
    }
    __forceinline void _setSize(S_dbefc0_Heap& heap, int n)
    {
        GrowArrayCapacity(heap, n);
        char* p = data + size;
        int diff = n - size;
        if (diff <= 0)
        {
            size = n;
            return;
        }
        FUN_00ec61c0(p, 0, diff);
        size = n;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        _setSize(S_dbefc0_GetHeap(), n);
    }
    __forceinline void trim(int n)
    {
        GrowArrayCapacity(S_dbefc0_GetHeap(), n);
        size = n;
    }
    void FUN_00dbefc0(const unsigned char* bytes, int count);
};

struct S_00dc0500_Flag
{
    bool b;
    S_00dc0500_Flag(bool v) : b(v)
    {}
};
struct S_00dc0500_Opt
{
    bool b;
    S_00dc0500_Opt(bool v) : b(v)
    {}
    S_00dc0500_Opt(const S_00dc0500_Opt& o) : b(o.b)
    {}
};
struct S_00dc0500_Holder : UnkHolder
{
    S_00dc0500_Holder()
    {
        a = 0;
        b = 0;
        c = -1;
        BSAudio* p = FUN_00c85750();
        FUN_00dbedb0((UnkRet*)p->e, 0);
    }
};
struct S_00dc0500_Arr
{
    int a;
    int b;
    int c;
    S_00dc0500_Arr() : a(0), b(0), c(0x80000000)
    {}
};

inline void* operator new(size_t, void* p) throw()
{
    return p;
}

struct S_dbf1a0_Handle
{
    void* m_ptr;
    S_dbf1a0_Handle(void* p) throw()
    {
        FUN_00dba650(p);
    }
    S_dbf1a0_Handle() throw()
    {
        m_ptr = 0;
    }
    ~S_dbf1a0_Handle() throw()
    {
        FUN_00dba660();
    }

    void __thiscall FUN_00dba650(void* p) throw();
    void __thiscall FUN_00dba660() throw();
    const char* __thiscall FUN_00dba680() const throw();
    int __thiscall FUN_00dba690() const throw();
    S_dbf1a0_Handle __thiscall SetShiftedValue() const throw();
    int __thiscall FUN_00dba6f0() const throw();
    void __thiscall DispatchRecords(void* arr) const throw();
};

struct S_dbf1a0_Elem
{
    const char* name;
    int unk04;
    int flags;
    void* sub;
    int unk10;

    S_dbf1a0_Elem() throw() : name(0), unk04(0), flags(0), sub(0), unk10(0)
    {}
};

struct hkTempAlloc : hkMemoryAllocator
{
    virtual void* v04() throw();
    virtual void* v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut) throw()
    {
        int n = reqNumInOut * (int)sizeof(T);
        T* p = (T*)AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return p;
    }
    template <typename T> __forceinline void _bufFree(void* p, int numElem) throw()
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};

struct S_dbf1a0_Router
{
    int unk00, unk04, unk08;
    hkTempAlloc* unk0c;
    hkTempAlloc& heap() throw()
    {
        return *unk0c;
    }
};

template <typename T> struct S_dbf1a0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline S_dbf1a0_Array(int n) throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)FUN_00c85750())->heap();
        T* p = n ? alloc._bufAlloc<T>(n) : 0;
        int cap = n ? n : 0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
        if (n > 0)
        {
            T* e = p;
            do
            {
                new (e) T();
                ++e;
            } while (--n != 0);
        }
    }

    __forceinline ~S_dbf1a0_Array() throw()
    {
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
    }
};

class hkMemoryAllocatorDBE8;

struct hkPairKeyDBE8
{
    unsigned int m_k1;
    unsigned int m_k2;
    bool operator==(const hkPairKeyDBE8& o) const
    {
        return m_k1 == o.m_k1 && m_k2 == o.m_k2;
    }
};

struct hkPairMapElemDBE8
{
    hkPairKeyDBE8 m_key;
    unsigned int m_uiFilterValue;
};

class hkPairMapDBE8
{
  public:
    hkPairMapElemDBE8* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00dbec60(hkMemoryAllocatorDBE8& alloc, int iNewCap);
    int InsertOrUpdate(hkMemoryAllocatorDBE8& alloc, hkPairKeyDBE8 key, unsigned int uiValue);
};

// Grows the map if needed, finds the slot for key via open addressing, stores uiValue, and returns 1 if the key was newly inserted.
// @fnv 0x00dbe810
int hkPairMapDBE8::InsertOrUpdate(hkMemoryAllocatorDBE8& alloc, hkPairKeyDBE8 key, unsigned int uiValue)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        FUN_00dbec60(alloc, m_iPairCount * 2 + 2);

    unsigned int i = ((key.m_k1 >> 4) * 0x9e3779b1) & m_iPairCount;
    int isNewKey = 1;
    while (m_kPrimitiveElement[i].m_key.m_k1 != 0)
    {
        if (m_kPrimitiveElement[i].m_key == key)
        {
            isNewKey = 0;
            break;
        }
        i = (i + 1) & m_iPairCount;
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].m_key = key;
    m_kPrimitiveElement[i].m_uiFilterValue = uiValue;
    return isNewKey;
}

struct Pair;
struct ObjC;
struct Arr;
struct Rec
{
    int key;
    int value;
    int enabled;
    int fourth;
    int fifth;
    Rec() : key(0), value(0), enabled(0), fourth(0), fifth(0)
    {}
};
struct Wrap
{
    void* m_p;
    __declspec(nothrow) int FUN_00dbac10() const;
    __declspec(nothrow) Pair FUN_00dbabb0(int idx) const;
    __declspec(nothrow) Pair FUN_00dbab90(int idx) const;
    __declspec(nothrow) int FUN_00dbac00() const;
    __declspec(nothrow) void FUN_00dbab70();
    __declspec(nothrow) void FUN_00dba7f0();
    __declspec(nothrow) ObjC FUN_00dbac20() const;
    __declspec(nothrow) void FUN_00dba660();
    __declspec(nothrow) Wrap InvokeCallbackInto(int v) const;
    ~Wrap()
    {
        FUN_00dbab70();
    }
};
struct Node50
{
    int m_00;
    int m_04;
    int m_08;
    float m_0c;
};
struct Pair
{
    void* m_p;
    int m_i;
    __declspec(nothrow) Wrap FUN_00dbacd0();
    __declspec(nothrow) StringHandle CreateValueInto();
    __declspec(nothrow) Node50* DispatchToVTableSlot8(int mode);
    __declspec(nothrow) int FUN_00dbac70();
    __declspec(nothrow) float hkOffsetOnlyStreamWriter_seek();
    __declspec(nothrow) int CallVirtualWithArg();
};
struct Arr
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    Arr()
    {}
    Arr(int n);
};
struct ObjC
{
    void* m_00;
    __declspec(nothrow) int FUN_00dba730();
    __declspec(nothrow) void DispatchItems(Arr& a);
    __declspec(nothrow) void FUN_00dba660();
    ~ObjC()
    {
        FUN_00dba660();
    }
};
struct __declspec(align(8)) Obj2
{
    char* m_00;
    int m_04;
    int m_08;
    __declspec(nothrow) void FUN_00dbef20(int n);
    __declspec(nothrow) void PackBitsToBytes(void* data);
};
struct AllocV
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void* AllocBytes(int* psize);
    virtual void Free(void* p, unsigned int size);
};
static __forceinline Rec* allocateRecords(AllocV* allocator, int& capacity)
{
    if (capacity)
    {
        int bytes = capacity * (int)sizeof(Rec);
        Rec* data = (Rec*)allocator->AllocBytes(&bytes);
        capacity = bytes / (int)sizeof(Rec);
        return data;
    }
    return 0;
}
__forceinline Arr::Arr(int n)
{
    int capacity = n;
    m_data = 0;
    m_iElementCount = 0;
    m_cap = (int)0x80000000;
    BSAudio* router = FUN_00c85750();
    AllocV* allocator = (AllocV*)router->d;
    Rec* data = allocateRecords(allocator, capacity);
    int flags = capacity ? capacity : (int)0x80000000;
    m_data = data;
    m_iElementCount = capacity;
    m_cap = flags;
    for (int k = 0; k < capacity; ++k)
        new (data + k) Rec;
}
extern "C" void __cdecl FUN_00c908c0(void* owner, Arr* arr, int newCap, int stride);

struct S_00dbfef0_A;
struct S_00dbfef0_B;

struct S_00dbfef0_X
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct S_00dbfef0_Node
{
    int QueryAndWriteResult();
    int FUN_00dba990();
    float FUN_00dbaa00();
    int DispatchToInterface(int n);
    int FUN_00dba9c0();
    int FUN_00dba9d0(S_00dbfef0_B* out);
    void GetResult(S_00dbfef0_A* out);
};

struct S_00dbfef0_B
{
    S_00dbfef0_X* p;
    void FUN_00dba7f0();
    int FUN_00dba680();
    void FUN_00dba660();
};

struct S_00dbfef0_A
{
    S_00dbfef0_Node* p;
    int FUN_00dbac00();
    int FUN_00dbac10();
    void FUN_00dbac20(S_00dbfef0_B* b);
    void FUN_00dbab70();
};

typedef unsigned int size_t;
struct __declspec(nothrow) IHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int* pBytes);
    virtual void ReleaseBlock(void* p, int n);
};
inline __declspec(nothrow) IHeap& myAlloc()
{
    typedef BSAudio*(__cdecl * GetAudioFn)();
    GetAudioFn fn = (GetAudioFn)FUN_00c85750;
    AudioMgr* mgr = (AudioMgr*)fn();
    return *(IHeap*)mgr->unk0c;
}
struct FUN_00dba650
{
    void* object;
    __declspec(nothrow) FUN_00dba650()
    {}
    __declspec(nothrow) ~FUN_00dba650()
    {
        FUN_00dba660();
    }
    __declspec(nothrow) void __thiscall FUN_00dba660();
    __declspec(nothrow) int __thiscall FUN_00dba730();
    __declspec(nothrow) void __thiscall DispatchItems(void* arr);
};
struct MyDesc
{
    void* object;
    __declspec(nothrow) MyDesc()
    {
        object = 0;
    }
    __declspec(nothrow) ~MyDesc()
    {
        FUN_00dba7f0();
    }
    __declspec(nothrow) int __thiscall FUN_00dba980();
    __declspec(nothrow) void __thiscall FUN_00dba7f0();
    __declspec(nothrow) ResourceKey __thiscall GetSourcePair();
    __declspec(nothrow) FUN_00dba650 __thiscall GetObjectValue();
    __declspec(nothrow) ResourceKey __thiscall FUN_00dba890(int id);
};
struct Struct20
{
    int a;
    int b;
    int c;
    int d;
    int e;
    __forceinline __declspec(nothrow) Struct20() : a(0), b(0), c(0), d(0), e(0)
    {}
};
struct MyCharArray : FUN_00dbef20
{
    int unk0c;
    __declspec(nothrow) MyCharArray(int n) : FUN_00dbef20(n)
    {}
    __declspec(nothrow) void __thiscall FUN_00dbefc0(const void* bytes, int count);
    __forceinline __declspec(nothrow) ~MyCharArray()
    {
        IHeap& heap = myAlloc();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct TempArr
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline __declspec(nothrow) TempArr(char* data, int size, int capacity)
        : m_data(data), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}

    __forceinline __declspec(nothrow) ~TempArr()
    {
        IHeap& heap = myAlloc();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};
struct Array20
{
    Struct20* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline __declspec(nothrow) Array20() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    static __forceinline __declspec(nothrow) Struct20* allocate(IHeap& heap, int& n)
    {
        if (n)
        {
            int bytes = n * 20;
            Struct20* p = (Struct20*)heap.AllocateBufferWithSize(&bytes);
            n = bytes / 20;
            return p;
        }
        return 0;
    }
    __forceinline __declspec(nothrow) Array20(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        IHeap& heap = myAlloc();
        Struct20* data = allocate(heap, n);
        int capacity = n ? n : 0x80000000;
        setData(data, n, capacity);
        for (int i = 0; i < n; ++i)
        {
            new (data + i) Struct20();
        }
    }

    __forceinline __declspec(nothrow) void setData(Struct20* data, int n, int capacity)
    {
        m_data = data;
        m_iElementCount = n;
        m_iCapacityState = capacity;
    }

    __forceinline __declspec(nothrow) ~Array20()
    {
        IHeap& heap = myAlloc();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, (cap & 0x3fffffff) * 20);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct ScanKey
{
    int first, second;
    ScanKey& operator=(const ScanKey& k)
    {
        first = k.first;
        second = k.second;
        return *this;
    }
};
struct ScanClass;
struct ScanArray;
struct ScanValue;
struct ScanItem;
struct ScanObject
{
    void* object;
    __declspec(nothrow) int FUN_00dba980() const;
    __declspec(nothrow) ScanKey GetSourcePair() const;
    __declspec(nothrow) ScanClass GetObjectValue() const;
    __declspec(nothrow) int FUN_00dba8b0() const;
    __declspec(nothrow) int FUN_00dba8c0(int iterator) const;
    __declspec(nothrow) int FUN_00dba8d0(int iterator) const;
    __declspec(nothrow) int FUN_00dba8e0(int iterator) const;
    __declspec(nothrow) ScanValue FUN_00dba8f0(int iterator) const;
    __declspec(nothrow) void FUN_00dba7f0();
    ~ScanObject()
    {
        FUN_00dba7f0();
    }
};
struct ScanMember
{
    int name, flags, type, className, extra;
    ScanMember() : name(0), flags(0), type(0), className(0), extra(0)
    {}
};
struct ScanClass
{
    void* object;
    __declspec(nothrow) int FUN_00dba730() const;
    __declspec(nothrow) int FUN_00dba740(int name) const;
    __declspec(nothrow) void FUN_00dba720(int index, ScanMember& member) const;
    __declspec(nothrow) void FUN_00dba660();
    ~ScanClass()
    {
        FUN_00dba660();
    }
};
struct ScanArray
{
    void* object;
    __declspec(nothrow) int FUN_00dbac00() const;
    __declspec(nothrow) ScanClass FUN_00dbac20() const;
    __declspec(nothrow) ScanArray InvokeCallbackInto(int name) const;
    __declspec(nothrow) ScanItem FUN_00dbab90(int index) const;
    __declspec(nothrow) void FUN_00dbab70();
    ~ScanArray()
    {
        FUN_00dbab70();
    }
};
struct ScanValue
{
    void* object;
    int index;
    __declspec(nothrow) int QueryAndWriteResult() const;
    __declspec(nothrow) ScanObject FUN_00dba9d0() const;
    __declspec(nothrow) ScanArray GetResult() const;
};
struct ScanItem
{
    void* object;
    int index;
    __declspec(nothrow) ScanObject CreateValueInto() const;
};
struct ScanRecord
{
    int first, second, bitOffset, count;
    ScanKey key;
};
void __cdecl ResizeAudioStream(hkMemoryAllocator& heap, void* array, int elementSize);
struct ScanReferences
{
    ScanRecord* data;
    int size, capacity;
    __forceinline ScanRecord& back()
    {
        return data[size - 1];
    }
    __forceinline void append(const ScanRecord& value)
    {
        hkMemoryAllocator& heap = ::audio()->tempHeap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(heap, this, sizeof(ScanRecord));
        data[size++] = value;
    }
};
struct ScanMap
{
    void* data;
    int size, capacity;
    __declspec(nothrow) int hkAgentNnMachine_FindAgent(ScanKey key, int fallback) const;
    __declspec(nothrow) void InsertOrUpdate(AllocOwner* heap, ScanKey key, int value);
    __forceinline void insert(AllocOwner* heap, ScanKey key, int value)
    {
        InsertOrUpdate(heap, key, value);
    }
};
struct ScanMask : hkCharArray
{
    int unk0c;
    __declspec(nothrow) void FUN_00dbef20(int n);
    __declspec(nothrow) void PackBitsToBytes(void* destination);
    __forceinline char& memberInteresting(int index)
    {
        return m_data[index];
    }
    __forceinline ScanMask(int n)
    {
        FUN_00dbef20(n);
    }
    __forceinline ~ScanMask()
    {
        hkTempAlloc& heap = ((S_dbf1a0_Router*)FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000u) == 0)
            heap.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct S00dbedb0_Callee : UnkHolder
{
    void __thiscall FUN_00dbec60(UnkRet*, int);
};
// @fnv 0x00dbedb0
__declspec(noinline) void __thiscall UnkHolder::FUN_00dbedb0(UnkRet* value, int count)
{
    int needed = count + count;
    int capacity = 8;
    while (capacity < needed)
        capacity += capacity;
    ((S00dbedb0_Callee*)this)->FUN_00dbec60(value, capacity);
}
