#include "f3_common.h"
// src/havok/physics/collide/filter/list/hkpcollisionfilterlist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/list/hkpcollisionfilterlist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCollisionFilterList.h"

struct hkBoolRet
{
    char b;
    hkBoolRet(bool val) : b(val)
    {}
};

struct Interface
{
    virtual hkBoolRet IsCollisionEnabled(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7) = 0;
};

struct BaseWithVptr
{
    virtual ~BaseWithVptr()
    {}
    int unk04;
    int unk08;
};

struct SubFilter : public BaseWithVptr, public Interface
{
};

class FilterList
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkArray<SubFilter*> m_kFilters;

    hkBoolRet FUN_00e49cf0(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};

// @fnv 0x00e49cf0
// pdb: hkpCollisionFilterList::isCollisionEnabled | hkpCollisionFilterList.obj | fnv360_0822_retail, vtable, high
// pdb params: input, collectionBodyA, collectionBodyB, containerShapeA, containerShapeB, keyA, keyB
hkBoolRet FilterList::FUN_00e49cf0(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    for (int i = m_kFilters.m_iElementCount - 1; i >= 0; --i)
    {
        if (!m_kFilters.m_data[i]->IsCollisionEnabled(a1, a2, a3, a4, a5, a6, a7).b)
        {
            return false;
        }
    }
    return true;
}

struct CheckResult
{
    unsigned char enabled;
    explicit CheckResult(bool value) : enabled(value)
    {}
};

struct FilterPredicate
{
    virtual void unknownMethod();
    virtual CheckResult evaluate(int first, int second);
};

struct FilterEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FilterPredicate predicate;
};

struct FilterChain
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FilterEntry** filters;
    int filterCount;

    CheckResult hkpCollisionFilterList_isCollisionEnabled(int first, int second);
};

// Evaluates each filter predicate from last to first and returns false as soon as one is disabled, otherwise true.
// @fnv 0x00e49d60
// pdb: hkpCollisionFilterList::isCollisionEnabled | hkpCollisionFilterList.obj | fnv360_0822_retail, vtable, high
// pdb params: a, collidableB
// pdb: hkpCollisionFilterList::isCollisionEnabled | hkpCollisionFilterList.obj | fnv360_0822_retail, vtable, high (was: EvaluateAllFilters)
CheckResult FilterChain::hkpCollisionFilterList_isCollisionEnabled(int first, int second)
{
    for (int index = filterCount - 1; index >= 0; --index)
    {
        if (!filters[index]->predicate.evaluate(first, second).enabled)
        {
            return CheckResult(false);
        }
    }
    return CheckResult(true);
}

struct hkBool9BC0
{
    hkBool9BC0(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct CollidableA9BC0;
struct CollidableB9BC0;

class CollidableFilter9BC0
{
  public:
    virtual ~CollidableFilter9BC0();
    virtual hkBool9BC0 IsCollisionEnabled(const CollidableA9BC0& a, const CollidableB9BC0& b) const;
};

class ReferencedObject9BC0
{
  public:
    virtual ~ReferencedObject9BC0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class CollisionFilter9BC0 : public ReferencedObject9BC0, public CollidableFilter9BC0
{
};

template <class T> struct hkArray9BC0
{
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class CollisionFilterList9BC0
{
  public:
    hkBool9BC0 FUN_00e49bc0(const CollidableA9BC0& a, const CollidableB9BC0& b) const;

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
    hkArray9BC0<CollisionFilter9BC0*> m_kFilters;
};

// Returns true if every filter in m_kFilters reports that collision between a and b is enabled, otherwise false.
// @fnv 0x00e49bc0
// pdb: hkpCollisionFilterList::isCollisionEnabled | hkpCollisionFilterList.obj | fnv360_0822_retail, vtable, high
// pdb params: a, b
hkBool9BC0 CollisionFilterList9BC0::FUN_00e49bc0(const CollidableA9BC0& a, const CollidableB9BC0& b) const
{
    for (int i = m_kFilters.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (!m_kFilters[i]->IsCollisionEnabled(a, b))
            return false;
    }
    return true;
}

struct hkBool9C20
{
    hkBool9C20(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
class Iface9C20
{
  public:
    virtual void vpad0();
    virtual hkBool9C20 IsCollisionEnabled(const void* p0, const void* p1, const void* p2, const void* p3,
                                          const void* p4) const;
};
class ReferencedObject9C20
{
  public:
    virtual ~ReferencedObject9C20();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class IfacePad9C20_0
{
  public:
    virtual void v();
};
class Filter9C20 : public ReferencedObject9C20, public IfacePad9C20_0, public Iface9C20
{
};
template <class E> struct hkArray9C20
{
    const E& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    E* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FilterList9C20
{
  public:
    hkBool9C20 FUN_00e49c20(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkArray9C20<Filter9C20*> m_kFilters;
};
// Returns true only if every filter in m_kFilters reports IsCollisionEnabled true for the given arguments.
// @fnv 0x00e49c20
// pdb: hkpCollisionFilterList::isCollisionEnabled | hkpCollisionFilterList.obj | fnv360_0822_retail, vtable, high
// pdb params: input, a, b, bContainer, bKey
hkBool9C20 FilterList9C20::FUN_00e49c20(const void* p0, const void* p1, const void* p2, const void* p3,
                                        const void* p4) const
{
    for (int i = m_kFilters.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (!m_kFilters[i]->IsCollisionEnabled(p0, p1, p2, p3, p4))
            return false;
    }
    return true;
}

struct hkBool9C90
{
    hkBool9C90(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
class Iface9C90
{
  public:
    virtual hkBool9C90 IsCollisionEnabled(const void* p0, const void* p1, const void* p2, const void* p3) const;
};
class ReferencedObject9C90
{
  public:
    virtual ~ReferencedObject9C90();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class IfacePad9C90_0
{
  public:
    virtual void v();
};
class IfacePad9C90_1
{
  public:
    virtual void v();
};
class Filter9C90 : public ReferencedObject9C90, public IfacePad9C90_0, public IfacePad9C90_1, public Iface9C90
{
};
template <class E> struct hkArray9C90
{
    const E& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    E* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FilterList9C90
{
  public:
    hkBool9C90 FUN_00e49c90(const void* p0, const void* p1, const void* p2, const void* p3) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkArray9C90<Filter9C90*> m_kFilters;
};
// Returns true only if every filter in m_kFilters reports IsCollisionEnabled true for the given arguments.
// @fnv 0x00e49c90
// pdb: hkpCollisionFilterList::isCollisionEnabled | hkpCollisionFilterList.obj | fnv360_0822_retail, vtable, high
// pdb params: aInput, bShape, bContainer, bKey
hkBool9C90 FilterList9C90::FUN_00e49c90(const void* p0, const void* p1, const void* p2, const void* p3) const
{
    for (int i = m_kFilters.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (!m_kFilters[i]->IsCollisionEnabled(p0, p1, p2, p3))
            return false;
    }
    return true;
}

struct AllocatorE49
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* Allocate(int& bytes) throw();
    virtual void Free(void*, int) throw();
};
struct RouterE49
{
    int unk00, unk04, unk08, unk0c;
    AllocatorE49* heap;
};
RouterE49* GetRouterE49() throw();
struct RefE49
{
    virtual ~RefE49() throw();
    unsigned short sizeFlags;
    short references;
    void AddReference() throw();
};
struct CollidableE49
{
    virtual ~CollidableE49() throw();
    virtual void Test();
};
struct CollectionE49
{
    virtual ~CollectionE49() throw();
    virtual void Test();
};
struct RayCollectionE49
{
    virtual ~RayCollectionE49() throw();
    virtual void Test();
};
struct RayCollidableE49
{
    virtual ~RayCollidableE49() throw();
    virtual void Test();
};
struct FilterE49 : RefE49, CollidableE49, CollectionE49, RayCollectionE49, RayCollidableE49
{
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
    FilterE49() throw();
};
struct FilterArrayE49
{
    FilterE49** data;
    int size;
    int capacity;
    FilterArrayE49() : data(0), size(0), capacity(0x80000000)
    {}
    static __forceinline void CopyItems(FilterE49** dest, FilterE49* const* src, int count)
    {
        for (int i = 0; i < count; ++i)
            dest[i] = src[i];
    }
    __forceinline void Copy(const FilterArrayE49& source)
    {
        AllocatorE49* heap = GetRouterE49()->heap;
        if ((capacity & 0x3fffffff) < source.size)
        {
            if ((capacity & 0x80000000) == 0)
                heap->Free(data, (capacity & 0x3fffffff) * 4);
            int bytes = source.size * 4;
            data = (FilterE49**)heap->Allocate(bytes);
            capacity = bytes / 4;
        }
        size = source.size;
        CopyItems(data, source.data, size);
    }
};
struct FUN_00e49e50 : FilterE49
{
    FilterArrayE49 filters;
    FUN_00e49e50(const FilterArrayE49& source) throw();
    virtual ~FUN_00e49e50() throw();
};
// Initializes type to 3, copies the source filter array into filters, and adds a reference to each filter element.
// @f3 0x00a77840 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
namespace na77840 {
struct ThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};
inline ThreadMemory* GetThreadMemory() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
inline int GetCapacity(const FilterArrayE49& a) { return a.capacity & 0x3fffffff; }
__forceinline void Assign(FilterArrayE49& dst, const FilterArrayE49& src)
{
    if (GetCapacity(dst) < src.size)
    {
        if ((dst.capacity & 0x80000000) == 0)
            GetThreadMemory()->FUN_008f6d90(dst.data, GetCapacity(dst) * 4, 0x17);
        dst.data = (FilterE49**)GetThreadMemory()->FUN_008f6d30(src.size * 4, 0x17);
        dst.capacity = (dst.capacity & 0x40000000) | src.size;
    }
    int n = src.size;
    dst.size = n;
    FilterArrayE49::CopyItems(dst.data, src.data, n);
}
}
// pdb: hkpCollisionFilterList::hkpCollisionFilterList | hkpCollisionFilterList.obj | fnv360_0721_beta, objrun, high
// pdb params: collisionFilters
FUN_00e49e50::FUN_00e49e50(const FilterArrayE49& source) throw()
{
    type = 3;
    na77840::Assign(filters, source);
    for (int i = 0; i < filters.size; ++i)
    {
        RefE49* r = filters.data[i];
        if (r->sizeFlags != 0)
            r->references++;
    }
}


struct FilterAllocatorE4
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void DeallocateMemory(void*, int) throw();
};
struct FilterRouterE4
{
    int unk00, unk04, unk08, unk0c;
    FilterAllocatorE4* m_pStreamAllocator;
    FilterAllocatorE4& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
FilterRouterE4* GetFilterRouterE4() throw();
struct FilterRefE4
{
    virtual ~FilterRefE4() throw()
    {}
    unsigned short sizeFlags;
    short references;
    void RemoveReference() throw();
};
struct CollectionFilterE4
{
    virtual ~CollectionFilterE4() throw()
    {}
    virtual void Filter();
};
struct RayCollectionFilterE4
{
    virtual ~RayCollectionFilterE4() throw()
    {}
    virtual void Filter();
};
struct RayCollidableFilterE4
{
    virtual ~RayCollidableFilterE4() throw()
    {}
    virtual void Filter();
};
struct BorderFilterE4
{
    virtual ~BorderFilterE4() throw()
    {}
    virtual void Filter();
};
struct CollisionFilterE4 : FilterRefE4, CollectionFilterE4, RayCollectionFilterE4, RayCollidableFilterE4, BorderFilterE4
{
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
};
struct FilterArrayE4
{
    CollisionFilterE4** data;
    int size;
    int capacityAndFlags;
    ~FilterArrayE4() throw()
    {
        FilterAllocatorE4& a = GetFilterRouterE4()->heap();
        size = 0;
        if ((capacityAndFlags & 0x80000000) == 0)
            a.DeallocateMemory(data, (capacityAndFlags & 0x3fffffff) * 4);
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};

// @f3 0x00a779f0 (community match, verified in this file)
namespace f3m_00a779f0 {
struct S00a779f0_Ref
{
    virtual ~S00a779f0_Ref() throw();
    unsigned short sizeFlags;
    short references;
};
struct S00a779f0_CollectionFilter
{
    virtual ~S00a779f0_CollectionFilter() throw();
    virtual void Filter();
};
struct S00a779f0_RayCollectionFilter
{
    virtual ~S00a779f0_RayCollectionFilter() throw();
    virtual void Filter();
};
struct S00a779f0_RayCollidableFilter
{
    virtual ~S00a779f0_RayCollidableFilter() throw();
    virtual void Filter();
};
struct S00a779f0_BorderFilter
{
    virtual ~S00a779f0_BorderFilter() throw();
    virtual void Filter();
};
struct S00a779f0_CollisionFilter : S00a779f0_Ref, S00a779f0_CollectionFilter, S00a779f0_RayCollectionFilter,
                                   S00a779f0_RayCollidableFilter, S00a779f0_BorderFilter
{
    S00a779f0_CollisionFilter() throw();
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
};
template <class T> struct S00a779f0_Array
{
    T* data;
    int size;
    int capacityAndFlags;
    S00a779f0_Array() throw() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
struct FUN_00a779f0 : S00a779f0_CollisionFilter
{
    FUN_00a779f0() throw();
    virtual ~FUN_00a779f0() throw();
    S00a779f0_Array<S00a779f0_CollisionFilter*> filters;
};
// pdb: hkpCollisionFilterList::hkpCollisionFilterList | hkpCollisionFilterList.obj | tesv_win, hash, low
FUN_00a779f0::FUN_00a779f0() throw()
{
}
}   // namespace f3m_00a779f0
