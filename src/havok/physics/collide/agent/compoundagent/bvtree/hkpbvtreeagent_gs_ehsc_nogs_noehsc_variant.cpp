#include "f3_common.h"
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_d2f5a0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};
struct S_d2f5a0_Entry
{
    int unk0;
    int unk4;
    S_d2f5a0_Obj* m_obj;
};
struct S_d2f5a0_Array
{
    S_d2f5a0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_d2f5a0_Entry* begin()
    {
        return m_data;
    }
    S_d2f5a0_Entry* end()
    {
        return m_data + m_iElementCount;
    }
};
struct __declspec(align(16)) Transform
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;

    Transform(void* apFirst, void* apSecond);
};
struct Allocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
extern "C" Global* __cdecl FUN_00c85750();

struct D2FA00Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D2FA00MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2FA00Allocator* m_pStreamAllocator;

    D2FA00Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" D2FA00MemoryRouter& __cdecl FUN_00c85750();
}

class D2FA00ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b =
            static_cast<D2FA00ReferencedObject*>(fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
    virtual ~D2FA00ReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class D2FA00Agent : public D2FA00ReferencedObject
{
  public:
    __declspec(nothrow) D2FA00Agent(void* mgr);

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
};
class D2FA00ShapeAgent : public D2FA00Agent
{
  public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr)
    {}
    virtual ~D2FA00ShapeAgent();
};
struct S_00d2f8f0_Elem
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00d2f8f0_Array
{
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const
    {
        return m_pEntries;
    }
    S_00d2f8f0_Elem* end() const
    {
        return m_pEntries + m_iArrayLength;
    }
};
template <class T> class hkArrayD2F5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T* begin()
    {
        return m_data;
    }
    T* end()
    {
        return m_data + m_iElementCount;
    }
};

#include <xmmintrin.h>

__declspec(align(16)) struct SlotTemp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    void Init(unsigned int a, unsigned int b);
};

__declspec(align(16)) struct SlotTemp2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void Build(unsigned int a, void* b);
};

class SolBool
{
    char state;

  public:
    SolBool()
    {}
    SolBool(bool x) : state((char)x)
    {}
    operator bool() const
    {
        return state != 0;
    }
};
template <class T> class SolField
{
    T data;

  public:
    __forceinline T operator->() const
    {
        return data;
    }
    __forceinline operator T() const
    {
        return val();
    }
    __forceinline T val() const
    {
        return data;
    }
};
struct SolVec
{
    __m128 q;
    __forceinline SolVec& operator=(const SolVec& r)
    {
        q = r.q;
        return *this;
    }
};
struct SolBox
{
    SolVec low, high;
    SolBool contains(const SolBox& rhs) const
    {
        __m128 lo = _mm_cmple_ps(low.q, rhs.low.q);
        __m128 hi = _mm_cmple_ps(rhs.high.q, high.q);
        return (_mm_movemask_ps(_mm_and_ps(lo, hi)) & 7) == 7;
    }
};
struct __declspec(align(16)) SolTransform
{
    float m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c;
    void FUN_00cb22f0(const SolTransform&, const SolTransform&);
    inline void SetMulInverse(const SolTransform& a, const SolTransform& b)
    {
        FUN_00cb22f0(a, b);
    }
};
template <class T> struct SolArray;
struct SolContainer;
enum SolKind
{
    SolKindInvalid = -1,
    SolKindLast = 31
};
template <class E, class I> class SolEnum
{
    I data;

  public:
    __forceinline operator E() const
    {
        return static_cast<E>(data);
    }
};
struct SolShape
{
    virtual void v00();
    unsigned short GetAllocationSize, refs;
    int user;
    SolEnum<SolKind, unsigned> type;
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const SolContainer* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const SolTransform&, float, SolBox&) const;
    __forceinline SolKind getType() const;
};
struct __declspec(align(16)) SolAlignedShape : SolShape
{
};
__forceinline SolKind SolShape::getType() const
{
    return static_cast<const SolAlignedShape*>(this)->type;
}
struct __declspec(align(16)) SolBuffer
{
    unsigned data[128];
};
struct SolContainer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const SolShape* GetShapeForKey(unsigned, SolBuffer&) const;
};
struct SolBody
{
    const SolShape* shape;
    unsigned key;
    const SolTransform* motion;
    const SolBody* parent;
    __forceinline SolBody(const SolBody* p) : parent(p)
    {
        motion = p->motion;
    }
    __forceinline const SolTransform& getTransform() const
    {
        return *motion;
    }
    __forceinline const SolShape* getShape() const
    {
        return shape;
    }
    __forceinline void SetCollisionShapeAndKey(const SolShape* s, unsigned k)
    {
        shape = s;
        key = k;
    }
};
struct SolInput;
struct SolShapeFilter
{
    virtual void v00();
    virtual SolBool IsCollisionEnabled(const SolInput&, const SolBody&, const SolBody&, const SolContainer&,
                                       unsigned) const;
};
struct SolReferenced
{
    virtual void v00();
    unsigned short size, refs;
};
struct SolPairFilter
{
    virtual void v00();
};
struct SolFilter : SolReferenced, SolPairFilter, SolShapeFilter
{
    virtual SolBool IsCollisionEnabled(const SolInput&, const SolBody&, const SolBody&, const SolContainer&,
                                       unsigned) const;
};
struct SolOwner;
struct SolManager;
struct SolAgent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void cleanup(SolOwner&);
    unsigned short GetAllocationSize, refs;
    SolManager* m_pContactManager;
};
typedef SolAgent*(__cdecl* SolFactory)(const SolBody&, const SolBody&, const SolInput&, SolManager*);
struct SolFactoryRecord
{
    SolFactory create;
    void* u04;
    void* u08;
    void* u0c;
    void* u10;
};
struct SolDispatcher;
struct SolInput
{
    SolField<SolDispatcher*> m_pCollisionDispatcher;
    SolField<int> weld;
    SolField<float> tolerance;
    SolField<const SolFilter*> m_iFilter;
    SolField<const void*> convexFilter;
    mutable SolField<int> predictive;
    float getTolerance() const
    {
        return tolerance;
    }
};
struct SolDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;

    unsigned char regular[32][32];
    unsigned char predictive[32][32];
    SolFactoryRecord functions[32];
    enum Prediction
    {
        NoPrediction,
        UsePrediction
    };
    __forceinline SolFactory find(SolKind a, SolKind b, const Prediction& predictiveFlag) const
    {
        int kind = (predictiveFlag ? predictive : regular)[a][b];
        return functions[kind].create;
    }
    __forceinline SolAgent* getNewCollisionAgent(const SolBody& a, const SolBody& b, const SolInput& input,
                                                 SolManager* mgr) const
    {
        const SolKind firstKind = a.getShape()->getType();
        const SolKind secondKind = b.getShape()->getType();
        Prediction prediction = static_cast<Prediction>((int)input.predictive.val());
        SolFactory f = find(firstKind, secondKind, prediction);
        return f(a, b, input, mgr);
    }
};

struct SolHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void freeBuffer(void*, int);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual bool CanAllocateBytes(int);
};
struct SolStack
{
    char* cursor;
    __forceinline void* allocate(int n, const char*)
    {
        char* p = cursor;
        cursor += n;
        return p;
    }
    __forceinline void deallocate(void* p)
    {
        cursor = (char*)p;
    }
};
struct SolRouter
{
    SolStack local;
    int u04, u08, u0c;
    SolHeap* heapPtr;
    static SolRouter& GetMonitorStream()
    {
        return *reinterpret_cast<SolRouter*>(FUN_00c85750());
    }
    SolHeap& heap()
    {
        return *heapPtr;
    }
    SolStack& stack()
    {
        return local;
    }
};
struct SolHeapSource
{
    SolHeap& get(const void*)
    {
        return SolRouter::GetMonitorStream().heap();
    }
};
template <class T> __forceinline void SolFreeStack(T* p)
{
    SolRouter::GetMonitorStream().stack().deallocate(p);
}
extern void __cdecl FUN_00c908c0(SolHeap&, void*, int, int);
extern void __cdecl FUN_00d2cc70(void*, const void*, int);
extern char DAT_011b4284, DAT_01268ad4;
struct SolSortState
{
};
extern void __cdecl QuickSortRange(unsigned*, int, int, SolSortState);
struct SolPlace;
inline void* operator new(unsigned int, SolPlace* p)
{
    return p;
}
struct SolPodTag
{
};
struct SolClassTag
{
};
template <class T> struct SolTypeTag
{
    typedef SolClassTag Type;
};
template <> struct SolTypeTag<unsigned>
{
    typedef SolPodTag Type;
};
namespace SolArrayOps {
template <class T> __forceinline void construct(T*, int, SolPodTag)
{}
template <class T> __forceinline void construct(T* p, int n, SolClassTag)
{
    for (int i = 0; i < n; ++i)
        ::new (reinterpret_cast<SolPlace*>(p + i)) T;
}
template <class T> __forceinline void destroy(T*, int, SolPodTag)
{}
template <class T> __forceinline void destroy(T* p, int n, SolClassTag)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}
template <class T> __forceinline void copy(T* d, const T* p, int n)
{
    for (int i = 0; i < n; ++i)
        d[i] = p[i];
}
template <class T> __forceinline void constructFrom(T* d, int n, const T* p, SolClassTag)
{
    for (int i = 0; i < n; ++i)
        ::new (reinterpret_cast<SolPlace*>(d + i)) T(p[i]);
}
__forceinline void move(void* d, const void* p, int n)
{
    FUN_00d2cc70(d, p, n);
}
__forceinline void copyBytes(void* d, const void* p, int n)
{
    for (int i = 0; i < n; i += 4)
        *reinterpret_cast<unsigned*>((char*)d + i) = *reinterpret_cast<const unsigned*>((const char*)p + i);
}
}
template <class T> struct SolArrayBase
{
    T* data;
    int count;
    int capacity;
    __forceinline SolArrayBase() : data(0), count(0), capacity(0x80000000)
    {}
    __forceinline SolArrayBase(T* p, int n, int c) : data(p), count(n), capacity(c | 0x80000000)
    {}
    inline T* begin()
    {
        return data;
    }
    inline T* end()
    {
        return data + count;
    }
    inline int GetLogicalSize() const
    {
        return count;
    }
    inline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline void reserveWith(SolHeap& heap, int n)
    {
        int available = getCapacity();
        if (available < n)
        {
            int twice = 2 * available;
            int target = n < twice ? twice : n;
            FUN_00c908c0(heap, this, target, sizeof(T));
        }
    }
    __forceinline void setSizeWith(SolHeap& heap, int n)
    {
        reserveWith(heap, n);
        SolArrayOps::destroy(data + n, count - n, typename SolTypeTag<T>::Type());
        SolArrayOps::construct(data + count, n - count, typename SolTypeTag<T>::Type());
        count = n;
    }
    __forceinline T* expandWith(SolHeap& heap, int at, int n)
    {
        int total = n + count;
        int shifted = count - at;
        if (total > getCapacity())
            reserveWith(heap, total);
        SolArrayOps::move(data + at + n, data + at, shifted * sizeof(T));
        SolArrayOps::construct(data + at, n, typename SolTypeTag<T>::Type());
        count = total;
        return data + at;
    }
    __forceinline void removeAtAndCopy(int at)
    {
        SolArrayOps::destroy(data + at, 1, typename SolTypeTag<T>::Type());
        --count;
        SolArrayOps::copyBytes(data + at, data + at + 1, (count - at) * sizeof(T));
    }
    __forceinline void clear()
    {
        SolArrayOps::destroy(data, count, typename SolTypeTag<T>::Type());
        count = 0;
    }
    __forceinline void release(SolHeap& heap)
    {
        clear();
        if ((capacity & 0x80000000) == 0)
            heap.freeBuffer(data, getCapacity() * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
    __forceinline void assignWith(SolHeap& heap, const SolArrayBase& rhs, SolClassTag)
    {
        int old = count;
        int total = rhs.GetLogicalSize();
        int common = total > old ? old : total;
        reserveWith(heap, total);
        SolArrayOps::destroy(data + total, old - total, SolClassTag());
        SolArrayOps::copy(data, rhs.data, common);
        SolArrayOps::constructFrom(data + common, total - common, rhs.data + common, SolClassTag());
        count = total;
    }
};
template <class T> struct SolArray : SolArrayBase<T>
{
    __forceinline SolArray()
    {}
    __forceinline SolArray(T* p, int n, int c) : SolArrayBase<T>(p, n, c)
    {}
    __forceinline ~SolArray()
    {
        this->release(SolHeapSource().get(this));
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->setSizeWith(SolHeapSource().get(this), n);
    }
    __forceinline T* expandAt(int at, int n)
    {
        return this->expandWith(SolHeapSource().get(this), at, n);
    }
    __forceinline SolArray& operator=(const SolArray& rhs)
    {
        this->assignWith(SolHeapSource().get(this), rhs, typename SolTypeTag<T>::Type());
        return *this;
    }
};
template <class T, int N> struct SolFixedArray : SolArray<T>
{
    T storage[N];
    __forceinline SolFixedArray(int n = 0) : SolArray<T>(storage, n, N)
    {}
};
template <class T> struct SolLocalArray : SolArray<T>
{
    T* localMemory;
    __forceinline SolLocalArray(int n)
    {
        this->data = static_cast<T*>(SolRouter::GetMonitorStream().stack().allocate((n * sizeof(T) + 127) & ~127, 0));
        this->capacity = n | 0x80000000;
        localMemory = this->data;
    }
    __forceinline ~SolLocalArray()
    {
        if (localMemory == this->data)
            this->clear();
        SolFreeStack(localMemory);
    }
};
extern D2FA00Agent* __cdecl FUN_00d107a0();
struct SolNull
{
    static D2FA00Agent* getNullAgentOriginal()
    {
        return FUN_00d107a0();
    }
    static SolAgent* GetNullAgent()
    {
        return reinterpret_cast<SolAgent*>(getNullAgentOriginal());
    }
};
namespace SolAlgorithm {
__forceinline void sort(unsigned* p, int n, SolSortState state)
{
    if (n > 1)
        QuickSortRange(p, 0, n - 1, state);
}
__forceinline void quickSort(unsigned* p, int n)
{
    sort(p, n, SolSortState());
}
}
struct SolEntry
{
    unsigned m_key;
    int userInfo;
    SolAgent* m_pCollisionAgent;
    unsigned& GetIteratorKey()
    {
        return m_key;
    }
    void setKey(unsigned& k)
    {
        m_key = k;
    }
};
struct SolUpdater : SolAgent
{
    SolArray<SolEntry> m_kEntries;
    SolBox m_kBoundingBox;
    void FUN_00d2fac0(const SolBody&, const SolBody&, const SolInput&, SolOwner&);
};

struct SolChildState
{
    const SolContainer* container;
    SolBody child;
    SolBuffer scratch;
    SolChildState(const SolBody& parent) : child(&parent)
    {}
    inline const SolBody* getChild(const SolBody&, const SolInput&, unsigned k)
    {
        child.SetCollisionShapeAndKey(container->GetShapeForKey(k, scratch), k);
        return &child;
    }
    inline const SolContainer* GetShapeContainer()
    {
        return container;
    }
};
template <class E> struct SolMerge
{
    static __forceinline void slow(SolArray<E>& entries, SolArray<unsigned>& keys, const SolBody& first,
                                   const SolBody& second, const SolInput& value, SolManager* owner, SolOwner& context,
                                   SolChildState& w)
    {
        E* old = entries.begin();
        E* oldEnd = entries.end();
        unsigned* key = keys.begin();
        unsigned* keyEnd = keys.end();
        SolLocalArray<E> output(keys.GetLogicalSize());
        output.SetSizeAndGrow(keys.GetLogicalSize());
        const SolContainer* container = w.GetShapeContainer();
        E* out = output.begin();
        while (old != oldEnd && key != keyEnd)
        {
            if (*key == old->GetIteratorKey())
            {
                *out = *old;
                ++out;
                ++old;
                ++key;
                continue;
            }
            if (*key < old->GetIteratorKey())
            {
                const SolBody* a = &first;
                const SolBody* b = &second;
                const SolBody* modified = w.getChild(second, value, *key);
                if (value.m_iFilter->IsCollisionEnabled(value, *a, *b, *container, *key))
                    out->m_pCollisionAgent =
                        value.m_pCollisionDispatcher->getNewCollisionAgent(*a, *modified, value, owner);
                else
                    out->m_pCollisionAgent = SolNull::GetNullAgent();
                out->setKey(*key);
                ++out;
                ++key;
                continue;
            }
            if (old->m_pCollisionAgent)
                old->m_pCollisionAgent->cleanup(context);
            ++old;
        }
        while (old != oldEnd)
        {
            if (old->m_pCollisionAgent)
                old->m_pCollisionAgent->cleanup(context);
            ++old;
        }
        while (key != keyEnd)
        {
            const SolBody* a = &first;
            const SolBody* b = &second;
            const SolBody* modified = w.getChild(second, value, *key);
            if (value.m_iFilter->IsCollisionEnabled(value, *a, *b, *container, *key))
                out->m_pCollisionAgent =
                    value.m_pCollisionDispatcher->getNewCollisionAgent(*a, *modified, value, owner);
            else
                out->m_pCollisionAgent = SolNull::GetNullAgent();
            out->setKey(*key);
            ++out;
            ++key;
        }
        entries = output;
    }
    static __forceinline void fast(SolArray<E>& entries, SolArray<unsigned>& keys, const SolBody& first,
                                   const SolBody& second, const SolInput& value, SolManager* owner, SolOwner& context,
                                   SolChildState& w)
    {
        {
            E* entry = entries.begin();
            E* end = entries.end();
            unsigned* hit = keys.begin();
            unsigned* hitEnd = keys.end();
            for (; entry != end; ++entry)
            {
                if (hit != hitEnd && entry->GetIteratorKey() == *hit)
                {
                    ++hit;
                    continue;
                }
                for (hit = keys.begin(); hit != hitEnd; ++hit)
                {
                    if (entry->GetIteratorKey() == *hit)
                    {
                        ++hit;
                        goto found;
                    }
                }
                entry->m_pCollisionAgent->cleanup(context);
                entries.removeAtAndCopy(int(entry - entries.begin()));
                --entry;
                --end;
            found:;
            }
        }
        const SolContainer* container = w.GetShapeContainer();
        if (keys.GetLogicalSize() != entries.GetLogicalSize())
        {
            E* entry = entries.begin();
            E* end = entries.end();
            unsigned* hit = keys.begin();
            unsigned* hitEnd = keys.end();
            for (; hit != hitEnd; ++hit)
            {
                if (entry != end && entry->GetIteratorKey() == *hit)
                {
                    ++entry;
                    continue;
                }
                int at = int(hit - keys.begin());
                entry = entries.expandAt(at, 1);
                const SolBody* a = &first;
                const SolBody* b = &second;
                const SolBody* modified = w.getChild(second, value, *hit);
                if (value.m_iFilter->IsCollisionEnabled(value, *a, *b, *container, *hit))
                    entry->m_pCollisionAgent =
                        value.m_pCollisionDispatcher->getNewCollisionAgent(*a, *modified, value, owner);
                else
                    entry->m_pCollisionAgent = SolNull::GetNullAgent();
                entry->m_key = *hit;
                end = entries.end();
                ++entry;
            }
        }
    }
};
// @f3 0x009b8230 (community match, verified in this file)
// 0x009b8230: Havok 5.5.0 hkpBvTreeAgent::prepareCollisionPartners (hkpCollide.lib, hkpBvTreeAgent.obj).
// The classes and inline definitions in namespace hk_009b8230 are the SDK's own, cut down to what this function uses;
// hkpAgentDispatchUtil, hkAgentDispatchUtilHelper and the body are written from the SDK's unoptimized library object.
// Out-of-line callees and data carry the game addresses they bind to (FUN_/DAT_<address>).
namespace hk_009b8230 {
typedef float  hkReal;
typedef signed char		hkChar;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

			typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void* FUN_008f6d30( int nbytes, HK_MEMORY_CLASS cl );
		void FUN_008f6d90(void*, int nbytes, HK_MEMORY_CLASS );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> DAT_010f3170;
	return DAT_010f3170.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

class hkOstream;

namespace hkArrayUtil
{
	void __cdecl FUN_00901e90(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::FUN_00901e90(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray();
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		void removeAtAndCopy(int index);
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		__forceinline T* expandAt( int index, int numToInsert );
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
	public:
		T m_storage[N];
};

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void __cdecl hkArray<T>::copy(T* dst, const T* src, int n)
{
	for(int i = 0; i < n; ++i)
	{
		dst[i] = src[i];
	}
}

template <typename T>
__forceinline void __cdecl hkArray<T>::copyBackwards(T* dst, const T* src, int n)
{
	for(int i = n-1; i >= 0; --i)
	{
		dst[i] = src[i];
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>& hkArray<T>::operator= (const hkArray<T>& a)
{
	if(getCapacity() < a.m_size)
	{
		releaseMemory();
		m_data = static_cast<T*>( hkThreadMemory::getInstance().FUN_008f6d30( a.m_size * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY));
		m_capacityAndFlags = a.m_size | (m_capacityAndFlags & static_cast<int>(LOCKED_FLAG));
	}
	m_size = a.m_size;
	copy(m_data, a.m_data, m_size);
	return *this;
}

template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::removeAtAndCopy(int index)
{
	;
	m_size--;
	for(int i = index; i < m_size; ++i)
	{
		m_data[i] = m_data[i+1];
	}
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::FUN_00901e90(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T>
__forceinline T* hkArray<T>::expandAt(int index, int numtoinsert)
{
	;
	const int newsize = numtoinsert + m_size;
	const int numtomove = m_size - index;
	if(newsize > getCapacity())
	{
		reserve(newsize);
	}
	copyBackwards(m_data + index + numtoinsert, m_data + index, numtomove);
	m_size = newsize;
	return m_data + index;
}

template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::end()
{
	return m_data + m_size;
}

class hkVector4;
typedef const hkVector4& hkVector4Parameter;

class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
	private:
		int m_mask;
		friend class hkVector4;
};


class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
		void FUN_00925300( const hkTransform& bTa, const hkTransform &bTc );
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline hkVector4Comparison hkVector4::compareLessThanEqual4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<=a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<=a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<=a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<=a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}

void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}

template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}

template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkBool contains(const hkAabb& other) const;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

hkBool hkAabb::contains(const hkAabb& other) const
{
	hkVector4Comparison mincomp = m_min.compareLessThanEqual4(other.m_min);
	hkVector4Comparison maxcomp = other.m_max.compareLessThanEqual4(m_max);
	hkVector4Comparison both; both.setAnd( mincomp, maxcomp );
	return both.allAreSet(hkVector4Comparison::MASK_XYZ) != 0;
}

class hkSphere
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		hkVector4 m_pos;
};

typedef hkUint16 hkContactPointId;

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};

class hkpCollisionDispatcher;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;

class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			                class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				                class MustEndWithSemiColon;
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				                class MustEndWithSemiColon;
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
};

__declspec(align(16)) class hkAlignedShape: public hkpShape{
};

hkpShapeType hkpShape::getType() const
{
	return static_cast<const hkAlignedShape*>(this)->m_type;
}

void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}

const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}

hkpCdBody::hkpCdBody( const hkpCdBody* parent )
{
	m_parent = parent;
	m_motion = parent->m_motion;
}

void hkpCdBody::setShape( const hkpShape* shape, hkpShapeKey key )
{
	m_shape = shape;
	m_shapeKey = key;
}

struct hkpProcessCollisionInput;
class hkpContactMgr;
struct hkpProcessCollisionOutput;
class hkpConstraintOwner;
struct hkpCollisionInput;
class hkpCollisionAgent;

struct hkpAgentEntry
{
	                class MustEndWithSemiColon;
	hkUchar     m_streamCommand;
	hkUchar     m_agentType;
	hkUchar     m_numContactPoints;
	hkUchar     m_size;
};

typedef void hkpAgentData;

struct hkpAgent3Input
{
	                class MustEndWithSemiColon;
	hkPadSpu<const hkpCdBody*> m_bodyA;
	hkPadSpu<const hkpCdBody*> m_bodyB;
	hkPadSpu<const hkpProcessCollisionInput*> m_input;
	hkPadSpu<hkpContactMgr*>	m_contactMgr;
	hkTransform		m_aTb;
};

struct hkpAgent3ProcessInput : public hkpAgent3Input
{
	                class MustEndWithSemiColon;
	hkPadSpu<hkReal>          m_distAtT1;
	hkPadSpu<int>		m_offsetPpuSectorMinusSpuSector;
	hkVector4       m_linearTimInfo;
};

namespace hkAgent3
{
	typedef hkpAgentData* (__cdecl* CreateFunc)( const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData );
	typedef void  (__cdecl* DestroyFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher );
	typedef hkpAgentData* (__cdecl* ProcessFunc)( const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4* separatingNormalOut, hkpProcessCollisionOutput& result);
	enum Symmetric
	{
		IS_SYMMETRIC,
		IS_NOT_SYMMETRIC,
		IS_NOT_SYMMETRIC_AND_FLIPPED
	};
	typedef void  (__cdecl* SepNormalFunc)( const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4& separatingNormalOut );
	typedef hkpAgentData* (__cdecl* CleanupFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner );
	typedef void (__cdecl* RemovePointFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkContactPointId idToRemove );
	typedef void (__cdecl* CommitPotentialFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkContactPointId newId );
	typedef void (__cdecl* CreateZombieFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkContactPointId idTobecomeZombie );
	typedef void (__cdecl* UpdateFilterFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner );
	typedef void (__cdecl* CalcStatisticsFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, const hkpCollisionInput& input, hkStatisticsCollector* collector );
	typedef void (__cdecl* InvalidateTimFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpCollisionInput& input );
	typedef void (__cdecl* WarpTimeFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkTime oldTime, hkTime newTime, hkpCollisionInput& input );
}

enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};

struct hkpCollisionQualityInfo
{
	                class MustEndWithSemiColon;
	__declspec(align(16)) hkReal m_keepContact;
	hkReal m_create4dContact;
	hkReal m_createContact;
	hkReal m_manifoldTimDistance;
	hkPadSpu<hkBool32>		m_useContinuousPhysics;
	hkReal m_minSeparation;
	hkReal m_minExtraSeparation;
	hkReal m_minSafeDeltaTime;
	hkReal m_minAbsoluteSafeDeltaTime;
	hkReal m_toiSeparation;
	hkReal m_toiExtraSeparation;
	hkReal m_toiAccuracy;
	hkReal m_maxContraintViolation;
	hkReal m_minToiDeltaTime;
	hkUint16	m_constraintPriority;
	hkBool m_enableToiWeldRejection;
};

class hkpShapeCollectionFilter;
class hkpConvexListFilter;

struct hkpCollisionInput
{
		                class MustEndWithSemiColon;
	public:
		hkReal getTolerance() const { return m_tolerance; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			                class MustEndWithSemiColon;
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};

class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct hkpLinearCastCollisionInput;

class hkpCollisionDispatcher : public hkReferencedObject
{
	public:
		enum {
			HK_MAX_RESPONSE_TYPE = 8,
			HK_MAX_SHAPE_TYPE    = 32,
			HK_MAX_AGENT2_TYPES  = 64,
			HK_MAX_AGENT3_TYPES = 16,
			HK_MAX_COLLISION_QUALITIES = 8
		};
	public:
		                class MustEndWithSemiColon;
		typedef hkpCollisionAgent* (__cdecl *CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& env, hkpContactMgr* mgr);
		typedef void (__cdecl *GetPenetrationsFunc)     (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		typedef void (__cdecl *GetClosestPointsFunc)   (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& output );
		typedef void (__cdecl *LinearCastFunc)         (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector );
		typedef CreateFunc CollisionAgentCreationFunction;
		typedef hkChar CollisionQualityIndex;
		struct AgentFuncs
		{
			                class MustEndWithSemiColon;
			CreateFunc           m_createFunc;
			GetPenetrationsFunc  m_getPenetrationsFunc;
			GetClosestPointsFunc m_getClosestPointFunc;
			LinearCastFunc       m_linearCastFunc;
			hkBool				 m_isFlipped;
			hkBool				 m_isPredictive;
		};
		struct Agent3Funcs
		{
			                class MustEndWithSemiColon;
			__declspec(align(16)) hkAgent3::CreateFunc m_createFunc;
			hkAgent3::DestroyFunc     m_destroyFunc;
			hkAgent3::CleanupFunc     m_cleanupFunc;
			hkAgent3::RemovePointFunc m_removePointFunc;
			hkAgent3::CommitPotentialFunc m_commitPotentialFunc;
			hkAgent3::CreateZombieFunc  m_createZombieFunc;
			hkAgent3::UpdateFilterFunc  m_updateFilterFunc;
			hkAgent3::CalcStatisticsFunc  m_calcStatisticsFunc;
			hkAgent3::InvalidateTimFunc m_invalidateTimFunc;
			hkAgent3::WarpTimeFunc      m_warpTimeFunc;
			hkAgent3::SepNormalFunc     m_sepNormalFunc;
			hkAgent3::ProcessFunc       m_processFunc;
			hkBool						m_isPredictive;
			hkBool						m_ignoreSymmetricVersion;
			hkBool						m_reusePreviousEntry;
		};
		struct InitCollisionQualityInfo
		{
			                class MustEndWithSemiColon;
			hkReal m_gravityLength;
			hkReal m_collisionTolerance;
			hkReal m_minDeltaTime;
			hkReal m_maxLinearVelocity;
			hkUint16 m_defaultConstraintPriority;
			hkUint16 m_toiConstraintPriority;
			hkUint16 m_toiHigherConstraintPriority;
			hkUint16 m_toiForcedConstraintPriority;
			hkBool m_wantContinuousCollisionDetection;
			hkBool m_enableNegativeManifoldTims;
			hkBool m_enableNegativeToleranceToCreateNon4dContacts;
			hkBool m_enableToiWeldRejection;
		};
		enum TableType
		{
			TABLE_TYPE_AGENT2,
			TABLE_TYPE_AGENT2_PRED,
			TABLE_TYPE_AGENT3,
			TABLE_TYPE_AGENT3_PRED
		};
		enum IsAgentPredictive
		{
			IS_NOT_PREDICTIVE,
			IS_PREDICTIVE
		};
	public:
		~hkpCollisionDispatcher();
		__forceinline hkpCollisionAgent* getNewCollisionAgent(	const hkpCdBody& a, const hkpCdBody& b, const hkpCollisionInput& env, hkpContactMgr* mgr) const;
		__forceinline CreateFunc getCollisionAgentCreationFunction( hkpShapeType typeA, hkpShapeType typeB, IsAgentPredictive predictive ) const;
		void calcStatistics( hkStatisticsCollector* collector ) const;
	public:
		struct ShapeInheritance
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_primaryType;
			hkpShapeType m_alternateType;
		};
		struct AgentEntry
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_typeA;
			hkpShapeType m_typeB;
			hkBool m_checkEnabled;
			AgentFuncs  m_createFunc;
		};
		struct Agent3Entry
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_typeA;
			hkpShapeType m_typeB;
			hkBool m_checkEnabled;
			Agent3Funcs  m_funcs;
		};
		struct Agent3FuncsIntern: public Agent3Funcs
		{
			                class MustEndWithSemiColon;
			hkAgent3::Symmetric       m_symmetric;
		};
		struct DebugEntry
		{
			                class MustEndWithSemiColon;
			char m_typeA;
			char m_typeB;
			char m_priority;
		};
		typedef DebugEntry	DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
	public:
		enum CollisionQualityLevel
		{
			COLLISION_QUALITY_INVALID,
			COLLISION_QUALITY_PSI,
			COLLISION_QUALITY_TOI,
			COLLISION_QUALITY_TOI_HIGHER,
			COLLISION_QUALITY_TOI_FORCED,
			COLLISION_QUALITY_CHARACTER,
			COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
		};
		CreateFunc	m_defaultCollisionAgent;
		hkpContactMgrFactory*	m_contactMgrFactory[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
		__declspec(align(16)) hkUint32 m_hasAlternateType[ HK_MAX_SHAPE_TYPE ];
		int						m_numAgent2Types;
		__declspec(align(16)) hkUchar m_agent2Types [HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		hkUchar				    m_agent2TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		AgentFuncs				m_agent2Func     [ HK_MAX_AGENT2_TYPES ];
		int						m_numAgent3Types;
		__declspec(align(16)) hkUchar m_agent3Types [HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		__declspec(align(16)) hkUchar m_agent3TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		Agent3FuncsIntern       m_agent3Func     [ HK_MAX_AGENT3_TYPES ];
		__declspec(align(16)) hkChar m_collisionQualityTable[ HK_COLLIDABLE_QUALITY_MAX][HK_COLLIDABLE_QUALITY_MAX];
		__declspec(align(16)) hkpCollisionQualityInfo m_collisionQualityInfo[ HK_MAX_COLLISION_QUALITIES ];
		hkBool m_collisionAgentRegistered;
		hkBool m_agent3Registered;
		hkBool m_midphaseAgent3Registered;
		hkBool m_checkEnabled;
		hkArray<ShapeInheritance> m_shapeInheritance;
		DebugTable	*m_debugAgent2Table;
		DebugTable	*m_debugAgent2TablePred;
		DebugTable	*m_debugAgent3Table;
		DebugTable	*m_debugAgent3TablePred;
	public:
		hkReal m_expectedMaxLinearVelocity;
		hkReal m_expectedMinPsiDeltaTime;
};

hkpCollisionDispatcher::CreateFunc hkpCollisionDispatcher::getCollisionAgentCreationFunction( hkpShapeType typeA, hkpShapeType typeB, hkpCollisionDispatcher::IsAgentPredictive predictive ) const
{
	;
	;
	int idx = (predictive ? m_agent2TypesPred : m_agent2Types)[typeA][typeB];
	return m_agent2Func[idx].m_createFunc;
}

hkpCollisionAgent* hkpCollisionDispatcher::getNewCollisionAgent(const hkpCdBody& collA,  const hkpCdBody& collB,
															  const hkpCollisionInput& environment, hkpContactMgr* mgr) const
{
	const hkpShapeType typeA = collA.getShape()->getType();
	const hkpShapeType typeB = collB.getShape()->getType();
	;
	;
	hkpCollisionDispatcher::IsAgentPredictive predictive = static_cast<hkpCollisionDispatcher::IsAgentPredictive>((int)environment.m_createPredictiveAgents.val());
	CreateFunc f = getCollisionAgentCreationFunction(typeA, typeB, predictive);
	return f(collA, collB, environment, mgr);
}

class hkpCollisionAgent : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner ) {}
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
		virtual void removePoint( hkContactPointId idToRemove );
		virtual void commitPotential( hkContactPointId newId );
		virtual void createZombie( hkContactPointId idTobecomeZombie );
	protected:
		inline virtual ~hkpCollisionAgent();
	public:
		hkpContactMgr* m_contactMgr;
};

class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const = 0;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const = 0;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const = 0;
		virtual hkBool32 isChildEnabled( hkpShapeKey key ) const { return true; }
		virtual bool isWeldingEnabled() const { return true; }
};

class hkpBvTreeAgent : public hkpCollisionAgent
{
	public:
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector ) ;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		virtual void processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
		virtual void cleanup(hkpConstraintOwner& info);
	public:
		static hkBool DAT_011693e0;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner );
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
	public:
		void calcStatistics( hkStatisticsCollector* collector) const;
		void prepareCollisionPartners          ( const hkpCdBody& bodyA, const hkpCdBody& bodyB,  const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner);
		~hkpBvTreeAgent(){}
		struct hkpBvAgentEntryInfo
		{
			                class MustEndWithSemiColon;
			hkpShapeKey m_key;
			hkInt32 m_userInfo;
			hkpCollisionAgent* m_collisionAgent;
			hkpShapeKey& getKey() { return m_key; }
			void setKey( hkpShapeKey& key) { m_key = key; }
		};
		hkArray<hkpBvAgentEntryInfo> m_collisionPartners;
		hkAabb	m_cachedAabb;
		static hkBool DAT_01061950;
};

class hkpBvTreeShape: public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual void queryObb( const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance, hkArray< hkpShapeKey >& hits ) const = 0;
		virtual void queryAabb( const hkAabb& aabb, hkArray<hkpShapeKey>& hits ) const = 0;
		virtual hkUint32 queryAabb( const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys ) const = 0;
		virtual const hkpShapeContainer* getContainer() const = 0;
};

class hkpShapeCollectionFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB  ) const = 0;
		virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB ) const = 0;
		virtual int numShapeKeyHitsLimitBreached( const hkpCollisionInput& input,
															const hkpCdBody& bodyA, const hkpCdBody& bodyB,
															const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb,
															hkpShapeKey* shapeKeysInOut,
															int shapeKeysCapacity) const = 0;
		virtual ~hkpShapeCollectionFilter() { }
};

class hkpNullAgent : public hkpCollisionAgent
{
	public:
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) { }
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& pointDetails) { }
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector ){ }
		virtual void processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result){}
		virtual void cleanup(hkpConstraintOwner& info){}
		static hkpNullAgent* __cdecl FUN_00990590();
};

template <typename T>
class hkLocalArray : public hkArray<T>
{
	public:
		                class MustEndWithSemiColon;
		__forceinline hkLocalArray( int capacity )
		{
			this->m_data = hkAllocateStack<T>(capacity);
			this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};

namespace hkAlgorithm
{
	template<typename T>
	class less
	{
	};
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
	template<typename T>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize)
	{
		quickSort( pArr, iSize, less<T>() );
	}
	void __cdecl FUN_009b5910(unsigned int *pArr, int d, int h, less<unsigned int> cmpLess);
}

namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		FUN_009b5910(pArr,low,high, cmpLess);
	}
}
}

struct hkMemoryStatistics
{
    static const hk_size_t INFINITE_SIZE = (hk_size_t(0)-1);
    hk_size_t m_allocated;
    hk_size_t m_used;
    hk_size_t m_available;
    hk_size_t m_totalAvailable;
    hk_size_t m_largestBlock;
	        class MustEndWithSemiColon;
};

class hkLimitedMemoryListener
{
public:
	        class MustEndWithSemiColon;
	virtual ~hkLimitedMemoryListener(){}
    virtual void cannotAllocate(hkMemory* mem,hk_size_t size) =0;
    virtual void allocationFailure(hkMemory* mem,hk_size_t size) = 0;
};

typedef void (__cdecl *hkMemoryWalkCallback)(void* start, hk_size_t size,hkBool allocated,int pool,void* param);

class hkMemory
{
	public:
		        class MustEndWithSemiColon;
		friend class hkThreadMemory;
		virtual ~hkMemory();
		virtual void allocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void deallocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateChunk( void*, int nbytes, HK_MEMORY_CLASS cl ) = 0;
		virtual void* allocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void preAllocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void provideRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void freeRuntimeBlocks() = 0;
		virtual void reservePagesFromSystemMemory( int numBytes ) {}
        virtual void garbageCollect() {}
        virtual void optimize() {}
		virtual void releaseUnusedPagesToSystemMemory( void ) {}
		virtual void printStatistics(hkOstream* c) = 0;
		virtual int getAllocatedSize( int size );
		virtual bool isDebugMemory(){ return false; }
        virtual void calculateStatistics(hkMemoryStatistics& stats ) =0;
        virtual void setMemoryHardLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemoryHardLimit() { return 0; }
        virtual void setMemorySoftLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemorySoftLimit() { return 0; }
        virtual void setLimitedMemoryListener(hkLimitedMemoryListener* listener) {}
        virtual hkLimitedMemoryListener* getLimitedMemoryListener() { return 0; }
        virtual hkBool hasMemoryAvailable(hk_size_t size) { return true; }
		virtual hkBool isOk() const;
		virtual void* findBaseAddress(void* p, int nbytes) { return 0; }
		virtual void lockBlock(void* p) {}
		virtual void unlockBlock(void* p) {}
        virtual hkResult walkMemory(hkMemoryWalkCallback callback,void* param) { return HK_FAILURE; }
		enum MemoryState
		{
			MEMORY_STATE_OK,
			MEMORY_STATE_OUT_OF_MEMORY
		};
		MemoryState m_memoryState;
		int m_criticalMemoryLimit;
        int m_memoryUsed;
		static inline hkMemory& __cdecl getInstance();
		enum MemoryFill
		{
			MEMORY_FILL_GUARD_AREA = 0xFD,
			MEMORY_FILL_FREE_SPACE = 0xDD,
			MEMORY_FILL_RETURNED_TO_USER = 0xCD
		};
	protected:
		static hkMemory* DAT_010f3400;
		int m_referenceCount;
		struct BigBlockData
		{
			hkBool m_available;
			int m_size;
			void* m_memory;
			HK_MEMORY_CLASS m_class;
			hkBool m_providedByOutside;
		};
		enum { BIG_BLOCKS_SLOTS=128 };
		int m_numValidBigBlocks;
		BigBlockData m_bigBlockDataArray[BIG_BLOCKS_SLOTS];
	public:
		static hkInt32 s_fillGuardArea;
		static hkInt32 s_fillFreeSpace;
		static hkInt32 s_fillReturnedToUser;
};

hkMemory& __cdecl hkMemory::getInstance()
{
	return *DAT_010f3400;
}

template<typename KEY, typename ENTRY, typename HELPER>
class hkpAgentDispatchUtil
{
	public:
		static __forceinline void __cdecl update( hkArray<ENTRY>& entries, hkArray<KEY>& keys,
									const hkpCdBody& cA, const hkpCdBody& cB,
									const hkpCollisionInput& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, HELPER& helper );
		static __forceinline void __cdecl fastUpdate( hkArray<ENTRY>& entries, hkArray<KEY>& keys,
									const hkpCdBody& cA, const hkpCdBody& cB,
									const hkpCollisionInput& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, HELPER& helper );
};

template<typename KEY, typename ENTRY, typename HELPER>
void __cdecl hkpAgentDispatchUtil<KEY,ENTRY,HELPER>::update( hkArray<ENTRY>& entries, hkArray<KEY>& keys,
									const hkpCdBody& cA, const hkpCdBody& cB,
									const hkpCollisionInput& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, HELPER& helper )
{
	ENTRY* oldEntry = entries.begin();
	ENTRY* oldEntryEnd = entries.end();
	KEY* newKey = keys.begin();
	KEY* newKeyEnd = keys.end();
	hkLocalArray<ENTRY> newEntries( keys.getSize() );
	newEntries.setSize( keys.getSize() );
	const hkpShapeContainer* container = helper.getShapeContainerB();
	ENTRY* newEntry = newEntries.begin();
	while ( oldEntry != oldEntryEnd && newKey != newKeyEnd )
	{
		if ( *newKey == oldEntry->getKey() )
		{
			*newEntry = *oldEntry;
			newEntry++;
			oldEntry++;
			newKey++;
			continue;
		}
		if ( *newKey < oldEntry->getKey() )
		{
			const hkpCdBody* bodyA = &cA;
			const hkpCdBody* bodyB = &cB;
			const hkpCdBody* childB = helper.getBodyB( cB, input, *newKey );
			if ( input.m_filter->isCollisionEnabled( input, *bodyA, *bodyB, *container, *newKey ) )
			{
				newEntry->m_collisionAgent = input.m_dispatcher->getNewCollisionAgent( *bodyA, *childB, input, mgr );
			}
			else
			{
				newEntry->m_collisionAgent = hkpNullAgent::FUN_00990590();
			}
			newEntry->setKey( *newKey );
			newEntry++;
			newKey++;
			continue;
		}
		if ( oldEntry->m_collisionAgent )
		{
			oldEntry->m_collisionAgent->cleanup( constraintOwner );
		}
		oldEntry++;
	}
	while ( oldEntry != oldEntryEnd )
	{
		if ( oldEntry->m_collisionAgent )
		{
			oldEntry->m_collisionAgent->cleanup( constraintOwner );
		}
		oldEntry++;
	}
	while ( newKey != newKeyEnd )
	{
		const hkpCdBody* bodyA = &cA;
		const hkpCdBody* bodyB = &cB;
		const hkpCdBody* childB = helper.getBodyB( cB, input, *newKey );
		if ( input.m_filter->isCollisionEnabled( input, *bodyA, *bodyB, *container, *newKey ) )
		{
			newEntry->m_collisionAgent = input.m_dispatcher->getNewCollisionAgent( *bodyA, *childB, input, mgr );
		}
		else
		{
			newEntry->m_collisionAgent = hkpNullAgent::FUN_00990590();
		}
		newEntry->setKey( *newKey );
		newEntry++;
		newKey++;
	}
	entries = newEntries;
}

template<typename KEY, typename ENTRY, typename HELPER>
void __cdecl hkpAgentDispatchUtil<KEY,ENTRY,HELPER>::fastUpdate( hkArray<ENTRY>& entries, hkArray<KEY>& keys,
									const hkpCdBody& cA, const hkpCdBody& cB,
									const hkpCollisionInput& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, HELPER& helper )
{
	{
		ENTRY* entry = entries.begin();
		ENTRY* entryEnd = entries.end();
		KEY* key = keys.begin();
		KEY* keyEnd = keys.end();
		for ( ; entry != entryEnd; entry++ )
		{
			if ( key != keyEnd && entry->getKey() == *key )
			{
				key++;
				continue;
			}
			for ( key = keys.begin(); key != keyEnd; key++ )
			{
				if ( entry->getKey() == *key )
				{
					key++;
					goto nextEntry;
				}
			}
			entry->m_collisionAgent->cleanup( constraintOwner );
			entries.removeAtAndCopy( int(entry - entries.begin()) );
			entry--;
			entryEnd--;
nextEntry:;
		}
	}
	const hkpShapeContainer* container = helper.getShapeContainerB();
	if ( keys.getSize() != entries.getSize() )
	{
		ENTRY* entry = entries.begin();
		ENTRY* entryEnd = entries.end();
		KEY* key = keys.begin();
		KEY* keyEnd = keys.end();
		for ( ; key != keyEnd; key++ )
		{
			if ( entry != entryEnd && entry->getKey() == *key )
			{
				entry++;
				continue;
			}
			int index = int(key - keys.begin());
			entry = entries.expandAt( index, 1 );
			const hkpCdBody* bodyA = &cA;
			const hkpCdBody* bodyB = &cB;
			const hkpCdBody* childB = helper.getBodyB( cB, input, *key );
			if ( input.m_filter->isCollisionEnabled( input, *bodyA, *bodyB, *container, *key ) )
			{
				entry->m_collisionAgent = input.m_dispatcher->getNewCollisionAgent( *bodyA, *childB, input, mgr );
			}
			else
			{
				entry->m_collisionAgent = hkpNullAgent::FUN_00990590();
			}
			entry->setKey( *key );
			entryEnd = entries.end();
			entry++;
		}
	}
}

class hkAgentDispatchUtilHelper
{
	public:
		hkAgentDispatchUtilHelper( const hkpCdBody& bodyB ): m_bodyB( &bodyB ){}
		const hkpCdBody* getBodyB( const hkpCdBody& cIn, const hkpCollisionInput& input, hkpShapeKey key )
		{
			m_bodyB.setShape( m_container->getChildShape( key, m_shapeBuffer ), key );
			return &m_bodyB;
		}
		const hkpShapeContainer* getShapeContainerB()
		{
			return m_container;
		}
		const hkpShapeContainer* m_container;
		hkpCdBody m_bodyB;
		hkpShapeContainer::ShapeBuffer m_shapeBuffer;
};

}

// pdb: hkpBvTreeAgent::prepareCollisionPartners | hkpBvTreeAgent.obj | tesv_win, caller_sim, low
void SolUpdater::FUN_00d2fac0( const SolBody& bodyA, const SolBody& bodyB, const SolInput& input, SolOwner& constraintOwner )
{
	using namespace hk_009b8230;
	hkpBvTreeAgent& agent = reinterpret_cast<hkpBvTreeAgent&>( *this );
	hkAabb aabb;
	{
		hkTransform bTa;
		{
			const hkTransform& wTb = reinterpret_cast<const hkpCdBody&>( bodyB ).getTransform();
			const hkTransform& wTa = reinterpret_cast<const hkpCdBody&>( bodyA ).getTransform();
			bTa.FUN_00925300( wTb, wTa );
		}
		{
			const hkReal checkEpsilon = reinterpret_cast<const hkpCollisionInput&>( input ).getTolerance() * 0.5f;
			reinterpret_cast<const hkpCdBody&>( bodyA ).getShape()->getAabb( bTa, reinterpret_cast<const hkpCollisionInput&>( input ).getTolerance() + checkEpsilon, aabb );
			if ( hkpBvTreeAgent::DAT_01061950 )
			{
				if ( agent.m_cachedAabb.contains( aabb ) )
				{
					return;
				}
				agent.m_cachedAabb = aabb;
			}
		}
	}
	const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>(reinterpret_cast<const hkpCdBody&>( bodyB ).getShape());
	hkInplaceArray<hkpShapeKey,128> hitList;
	bvB->queryAabb( aabb, hitList );
	int newMemNeeded = ( hitList.getSize() - agent.m_collisionPartners.getSize() ) * 128;
	if ( !hkMemory::getInstance().hasMemoryAvailable( newMemNeeded ) )
	{
		hkMemory::getInstance().m_memoryState = hkMemory::MEMORY_STATE_OUT_OF_MEMORY;
		return;
	}
	{
		const hkpShapeContainer* shapeContainer = bvB->getContainer();
		hkAgentDispatchUtilHelper helper( reinterpret_cast<const hkpCdBody&>( bodyB ) );
		helper.m_container = shapeContainer;
		if ( hkpBvTreeAgent::DAT_011693e0 )
		{
			hkpAgentDispatchUtil<hkpShapeKey, hkpBvTreeAgent::hkpBvAgentEntryInfo, hkAgentDispatchUtilHelper>::fastUpdate( agent.m_collisionPartners, hitList, reinterpret_cast<const hkpCdBody&>( bodyA ), reinterpret_cast<const hkpCdBody&>( bodyB ), reinterpret_cast<const hkpCollisionInput&>( input ), agent.m_contactMgr, reinterpret_cast<hkpConstraintOwner&>( constraintOwner ), helper );
		}
		else
		{
			hkAlgorithm::quickSort( hitList.begin(), hitList.getSize() );
			hkpAgentDispatchUtil<hkpShapeKey, hkpBvTreeAgent::hkpBvAgentEntryInfo, hkAgentDispatchUtilHelper>::update( agent.m_collisionPartners, hitList, reinterpret_cast<const hkpCdBody&>( bodyA ), reinterpret_cast<const hkpCdBody&>( bodyB ), reinterpret_cast<const hkpCollisionInput&>( input ), agent.m_contactMgr, reinterpret_cast<hkpConstraintOwner&>( constraintOwner ), helper );
		}
	}
}

