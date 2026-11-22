#include "f3_common.h"
// src/staging/blk_00ce0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00ce0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct __declspec(align(16)) SortElem16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

typedef bool(__cdecl* SortElemLess)(const SortElem16& a, const SortElem16& b);

// @f3 0x00a600a0 (community match, verified in this file)
// The fixed symbol uses the pack's SortElem16 name, but this specialization
// operates on two-word records. Keep that storage layout separate from the
// opaque type names used in the comparator's fixed signature.
struct SortRecord1142
{
    int unk00;
    int unk04;
};

class hkBool
{
    char value;
public:
    hkBool() {}
    hkBool(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};

typedef hkBool (__cdecl* SortLess1142)(const SortElem16&, const SortElem16&);

// pdb: hkAlgorithm::quickSortRecursive<struct hkGeomConvexHullBuilder::WeightedNeighbour,class hkBool (__cdecl*)(struct hkGeomConvexHullBuilder::WeightedNeighbour const &,struct hkGeomConvexHullBuilder::WeightedNeighbour const &)> | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00cf83c0(SortElem16* storage, int low, int high, SortLess1142 less)
{
    SortRecord1142* values = reinterpret_cast<SortRecord1142*>(storage);
    for (;;)
    {
        int j = high;
        int i = low;
        __declspec(align(16)) SortRecord1142 pivot = values[(i + j) >> 1];
        do
        {
            while (less(reinterpret_cast<const SortElem16&>(values[i]),
                        reinterpret_cast<const SortElem16&>(pivot)))
                ++i;
            while (less(reinterpret_cast<const SortElem16&>(pivot),
                        reinterpret_cast<const SortElem16&>(values[j])))
                --j;
            if (i <= j)
            {
                if (j != i)
                {
                    SortRecord1142 temp = values[j];
                    values[j] = values[i];
                    values[i] = temp;
                }
                --j;
                ++i;
            }
        } while (i <= j);
        if (low < j)
            FUN_00cf83c0(storage, low, j, less);
        if (i >= high)
            break;
        low = i;
    }
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

struct QuaternionVector
{
    __m128 value;
    __declspec(noinline) void FUN_00c66320(const QuaternionVector* left, const QuaternionVector* right)
    {
        __m128 a = left->value;
        __m128 b = right->value;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 imag = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xff), a),
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xff), b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        value = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

template <class T> struct PointerParam
{
    T* p;
    PointerParam(T* q) : p(q)
    {}
    operator T*() const
    {
        return p;
    }
    PointerParam& operator++()
    {
        ++p;
        return *this;
    }
    T* operator->() const
    {
        return p;
    }
};

struct SortRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

typedef char*(__cdecl* SortCmp)(void* tag, const SortRec* lhs, const SortRec* rhs);

void __cdecl FUN_00ce245a(SortRec* a, int low, int high, SortCmp cmp);

// @fnv 0x00cf8510
// pdb: hkAlgorithm::quickSortRecursive<hkWorldOperation::BiggestOperation,hkBool (__cdecl*)(hkWorldOperation::BiggestOperation const &,hkWorldOperation::BiggestOperation const &)> | hkpWorldOperationQueue.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: pArr, d, h, cmpLess
void __cdecl FUN_00cf8510(SortRec* a, int low, int high, SortCmp cmp)
{
    char tagLo;
    char tagHi;

    for (;;)
    {
        int j = high;
        int i = low;
        __declspec(align(16)) SortRec pivot = a[(i + j) >> 1];
        do
        {
            while (*cmp(&tagLo, &a[i], &pivot))
                ++i;
            while (*cmp(&tagHi, &pivot, &a[j]))
                --j;
            if (j < i)
                break;
            if (j != i)
            {
                SortRec& x = a[j];
                SortRec& y = a[i];
                __declspec(align(16)) SortRec t = x;
                x = y;
                y = t;
            }
            --j;
            ++i;
        } while (i <= j);
        if (low < j)
            FUN_00ce245a(a, low, j, cmp);
        if (i >= high)
            return;
        low = i;
    }
}

namespace fnv_00cfac20 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned int DAT_0126835c;
void* __cdecl FUN_00c85750(void);
struct S00cfac20_Vec
{
    __m128 q;
    void setMin4(const S00cfac20_Vec& a, const S00cfac20_Vec& b)
    {
        q = _mm_min_ps(a.q, b.q);
    }
    void setMax4(const S00cfac20_Vec& a, const S00cfac20_Vec& b)
    {
        q = _mm_max_ps(a.q, b.q);
    }
};
struct S00cfac20_Aabb
{
    S00cfac20_Vec mn;
    S00cfac20_Vec mx;
    void includePoint(const S00cfac20_Vec& p)
    {
        mn.setMin4(mn, p);
        mx.setMax4(mx, p);
    }
};
struct S00cfac20_Mon
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct S00cfac20_Stack
{
    char* cur;
    char* alloc(int size)
    {
        char* r = cur;
        cur = r + ((size + 0x7f) & ~0x7f);
        return r;
    }
    void release(char* p)
    {
        cur = p;
    }
};
static inline void S00cfac20_timer(const char* name)
{
    S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
    char* p = mon->cur;
    if (p < mon->end)
    {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        p += 0xc;
        mon->cur = p;
    }
}
}  // namespace fnv_00cfac20

typedef unsigned short hkUint16;

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline hkVector4()
    {}
    __forceinline hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

template <class T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;

    __forceinline void operator=(const ReferenceCountedPointer& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / int(sizeof(T));
        return static_cast<T*>(p);
    }

    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

void* __cdecl FUN_00c85750();

__forceinline hkMemoryAllocator& containerHeap()
{
    return static_cast<NineIntegerRecord*>(FUN_00c85750())->heap();
}

void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* array, int reqCapacity, int sizeElem);

template <typename T> __forceinline void hkConstructWithArray(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) T(tcopy[i]);
    }
}

template <typename T> __forceinline void hkCopy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dst[i] = src[i];
    }
}

template <typename T> __forceinline void hkConstructWithArray2(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t) T(*tcopy);
        ++t;
        ++tcopy;
    }
}

template <typename T> __forceinline void hkCopy2(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        *dst = *src;
        ++dst;
        ++src;
    }
}

template <typename T> struct hkArray
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline void _copyFromArrayClass(hkMemoryAllocator& alloc, const hkArray& a)
    {
        int oldSize = m_iElementCount;
        int newSize = a.GetLogicalSize();
        int copiedSize = newSize > oldSize ? oldSize : newSize;

        GrowArrayCapacity(alloc, newSize);
        hkCopy(m_data, a.m_data, copiedSize);
        hkConstructWithArray(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline hkArray& operator=(const hkArray& a)
    {
        _copyFromArrayClass(containerHeap(), a);
        return *this;
    }

    __forceinline void _copyFromArrayPod(hkMemoryAllocator& alloc, const hkArray& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            {
                alloc._bufFree<T>(m_data, getCapacity());
            }
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        hkCopy(m_data, a.m_data, m_iElementCount);
    }
};
