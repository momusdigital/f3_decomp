#include "f3_common.h"
// src/staging/blk_00dc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00dc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
}

struct MemAllocator;

struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemAllocator* unk10;
    MemAllocator& heap()
    {
        return *unk10;
    }
};

void* __cdecl FUN_00c85750();

namespace fnv_00dd6a10 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

typedef __m128 Plane;

struct Triangle
{
    Plane plane;
    int v0, v1, v2;
    int unk1c;
};

struct Edge
{
    int a, b;
    Triangle* tri;
    int unk0c;
    Plane plane;

    void set(Triangle* t, int ia, int ib)
    {
        a = ia;
        b = ib;
        tri = t;
    }
};

struct Allocator
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void freeBlock(void* data, int size);
};

struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
    Allocator& heap()
    {
        return *allocator;
    }
};

Holder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(Allocator* allocator, void* container, int elementSize);

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct Arr_00dd6a10
{
    T* data;
    int size;
    int capacity;

    __forceinline int findEdge(const Edge& e) const
    {
        int i = 0;
        if (size <= 0)
            return -1;
        for (; i < size; i++)
        {
            const T& o = data[i];
            if ((o.a == e.a && o.b == e.b) || (o.b == e.a && o.a == e.b))
                return i;
        }
        return -1;
    }
    __forceinline void AddBack(const T& v)
    {
        Holder* h = FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(h->allocator, this, sizeof(T));
        T* p = &data[size];
        if (p)
            *p = v;
        size++;
    }
    __forceinline void pushBackPlain(const T& v)
    {
        Allocator& a = FUN_00c85750()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&a, this, sizeof(T));
        hkConstructWithCopy(data + size, 1, v);
        size++;
    }
    __forceinline void clearAndFree()
    {
        Allocator& a = FUN_00c85750()->heap();
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};

typedef Arr_00dd6a10<Plane> PlaneArray;
typedef Arr_00dd6a10<Triangle> TriangleArray;
typedef Arr_00dd6a10<Edge> EdgeArray;

}  // namespace fnv_00dd6a10

struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00dced70_Object
{
  public:
    S00dced70_Object(FinishingFlag flag);  // FUN_00d4dfc0
    void* m_ppVirtualMethodTable;
    int unk04;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dced70
// pdb: getVtablehkpBreakableConstraintData | hkpDynamicsReflections.obj | tesv_win, caller_sim, low
const void* __cdecl FUN_00dced70()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dced70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct __declspec(align(16)) FUN_00dd1f00
{
    __m128 unk00;
    int unk10;
    float unk14;
    int unk18;
    int unk1c;
    FUN_00dd1f00(const FUN_00dd1f00& o);
};

namespace fnv_00dd62e0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float f[4];
} __m128;
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern const __m128 DAT_010c44d0;

}  // namespace fnv_00dd62e0

struct Pair_00dd6c10
{
    int first;
    int second;

    static __forceinline Pair_00dd6c10 make(int a, int b)
    {
        Pair_00dd6c10 p;
        p.first = a;
        p.second = b;
        return p;
    }
    __forceinline bool operator==(const Pair_00dd6c10& o) const
    {
        return first == o.first && second == o.second;
    }
};

struct Alloc_00dd6c10
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void freeBlock(void* data, int size);
};

struct Holder_00dd6c10
{
    int unk00, unk04, unk08, unk0c;
    Alloc_00dd6c10* allocator;
    __forceinline Alloc_00dd6c10& heap()
    {
        return *allocator;
    }
};

void* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* container, int elementSize);

template <class T> struct Arr_00dd6c10
{
    T* data;
    int size;
    int capacity;
};

struct PairList_00dd6c10
{
    Pair_00dd6c10* data;
    int size;
    int capacity;
    Pair_00dd6c10 storage[32];

    __forceinline void init()
    {
        data = storage;
        size = 0;
        capacity = 0x80000020;
    }
    __forceinline int indexOf(const Pair_00dd6c10& t) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == t)
                return i;
        }
        return -1;
    }
    __forceinline void add(const Pair_00dd6c10& item)
    {
        Holder_00dd6c10* h = static_cast<Holder_00dd6c10*>(FUN_00c85750());
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(h->allocator, this, sizeof(Pair_00dd6c10));
        Pair_00dd6c10* p = &data[size];
        if (p)
        {
            p->first = item.first;
            p->second = item.second;
        }
        size++;
    }
    __forceinline void _clearAndDeallocate(Alloc_00dd6c10& a)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * sizeof(Pair_00dd6c10));
    }
    __forceinline void clearAndFree()
    {
        _clearAndDeallocate(static_cast<Holder_00dd6c10*>(FUN_00c85750())->heap());
    }
};

typedef Arr_00dd6c10<__m128> VecArr_00dd6c10;

static __forceinline float dot3_00dd6c10(const __m128& a, const __m128& b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    return r;
}

static __forceinline __m128 cross_00dd6c10(__m128 b, __m128 a)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                      _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
}
static __forceinline __m128 cross2_00dd6c10(__m128 a, __m128 b)
{
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2));
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9));
    return _mm_sub_ps(t1, t0);
}
struct hkVector4q_00dd6c10
{
    __m128 m_vComponents;
    __forceinline void setCross(const hkVector4q_00dd6c10& v1, const hkVector4q_00dd6c10& v2)
    {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(positive, negative);
    }
};
static __forceinline bool lt_00dd6c10(const float& a, const float& b)
{
    return a < b;
}
static __forceinline bool gt_00dd6c10(const float& a, const float& b)
{
    return a > b;
}
extern const float DAT_010c8440 = -1.1920929e-07f;

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern const float DAT_010b9be8;
extern const __m128 DAT_010c44d0;
struct PlanePoint
{
    __m128 position;
    int plane0, plane1, plane2, unk1c;
    __forceinline void copyPlanes(const PlanePoint& other)
    {
        plane0 = other.plane0;
        plane1 = other.plane1;
        plane2 = other.plane2;
    }
};
int __cdecl FUN_00dd6380(VecArr_00dd6c10* vectors, int first, int second, int third, PlanePoint* point);
__declspec(noinline) int __cdecl FUN_00dd6510(const __m128* normal, VecArr_00dd6c10* vectors, int first, int second,
                                              PlanePoint* lower, PlanePoint* upper)
{
    lower->plane0 = lower->plane1 = lower->plane2 = -1;
    upper->plane0 = upper->plane1 = upper->plane2 = -1;
    bool initialized = false;
    for (int i = 0; i < vectors->size; ++i)
    {
        if (i == first || i == second)
            continue;
        PlanePoint point;
        if (FUN_00dd6380(vectors, first, second, i, &point) != 0)
            continue;
        if (!initialized)
        {
            __m128 scale = _mm_load_ss(&DAT_010b9be8);
            scale = _mm_shuffle_ps(scale, scale, 0);
            upper->position = _mm_add_ps(_mm_mul_ps(scale, *normal), point.position);
            lower->position = _mm_xor_ps(upper->position, DAT_010c44d0);
            initialized = true;
        }
        float topDistance = dot3_00dd6c10(_mm_sub_ps(upper->position, point.position), vectors->data[i]);
        if (topDistance > DAT_010c8440)
        {
            upper->position = point.position;
            upper->copyPlanes(point);
        }
        float bottomDistance = dot3_00dd6c10(_mm_sub_ps(lower->position, point.position), vectors->data[i]);
        if (bottomDistance > DAT_010c8440)
        {
            lower->position = point.position;
            lower->copyPlanes(point);
        }
    }
    if (lower->plane0 == -1)
    {
        if (upper->plane0 == -1)
            return 1;
        lower->copyPlanes(*upper);
    }
    if (upper->plane0 == -1)
    {
        if (lower->plane0 == -1)
            return 1;
        upper->copyPlanes(*lower);
    }
    return 0;
}

// @f3 0x00a578b0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

int __cdecl FUN_00a57240(const __m128*, VecArr_00dd6c10*, int, int, PlanePoint*, PlanePoint*);
extern float DAT_00de731c;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;

static __forceinline bool gtv_00dd6c10(float a, float b) { return a > b; }

struct PairArray {
    Pair_00dd6c10* data; int size; int capacity;
    Pair_00dd6c10 storage[32];
    void init() { data = storage; size = 0; capacity = 0x80000020; }
    int indexOf(const Pair_00dd6c10& t) const {
        for (int i = 0; i < size; i++) if (data[i] == t) return i;
        return -1;
    }
    void add(const Pair_00dd6c10& p);
    void clearAndFree();
};
void __cdecl FUN_00901f10(PairArray*, int);
struct ScalarAlloc { void FUN_008f6d90(void*, int, int); };

void PairArray::add(const Pair_00dd6c10& p) {
    if (size == (capacity & 0x3fffffff)) FUN_00901f10(this, 8);
    data[size].first = p.first; data[size].second = p.second; ++size;
}
void PairArray::clearAndFree() {
    if ((capacity & 0x80000000) == 0) {
        int cap = (capacity & 0x3fffffff);
        ScalarAlloc* a = static_cast<ScalarAlloc*>(DAT_00d9b080(DAT_010f3170));
        a->FUN_008f6d90(data, cap * 8, 0x17);
    }
}

int __cdecl FUN_00dd6c10(VecArr_00dd6c10* vectors, int* first, int* second, PlanePoint* q, PlanePoint* p)
{
    PairArray visited; visited.init();
    __m128 normal;
    for (;;) {
        float best = DAT_00de731c;
        Pair_00dd6c10 bestPair = Pair_00dd6c10::make(-1, -1);
        for (int i = 0; i < vectors->size; i++) {
            for (int j = i + 1; j < vectors->size; j++) {
                const __m128& a = vectors->data[i];
                const __m128& b = vectors->data[j];
                float score = a.m128_f32[0] * b.m128_f32[0] + a.m128_f32[1] * b.m128_f32[1] + a.m128_f32[2] * b.m128_f32[2];
                if (!(score > best && score < 0.8999999761581421)) continue;
                if (visited.indexOf(Pair_00dd6c10::make(i, j)) != -1) continue;
                best = score; *first = i; *second = j; bestPair = Pair_00dd6c10::make(i, j);
            }
        }
        if (bestPair.first == -1) { visited.clearAndFree(); return 1; }
        visited.add(bestPair);
        int uc_0 = 0; int uc_1 = 0; int uc_2 = 0; int uc_3 = 0; int uc_4 = 0; int uc_5 = 0;
        const __m128& b = vectors->data[*second];
        int um_0 = 0; int um_1 = 0; int um_2 = 0; int um_3 = 0; int um_4 = 0; int um_5 = 0; int um_6 = 0;
        const __m128& a = vectors->data[*first];
        normal.m128_f32[0] = a.m128_f32[1] * b.m128_f32[2] - a.m128_f32[2] * b.m128_f32[1];
        normal.m128_f32[1] = b.m128_f32[0] * a.m128_f32[2] - a.m128_f32[0] * b.m128_f32[2];
        normal.m128_f32[2] = a.m128_f32[0] * b.m128_f32[1] - b.m128_f32[0] * a.m128_f32[1];
        normal.m128_f32[3] = 0;
        if (FUN_00a57240(&normal, vectors, *first, *second, p, q) == 1) { visited.clearAndFree(); return 1; }
        __m128 diff;
        diff.m128_f32[0] = p->position.m128_f32[0] - q->position.m128_f32[0];
        diff.m128_f32[1] = p->position.m128_f32[1] - q->position.m128_f32[1];
        diff.m128_f32[2] = p->position.m128_f32[2] - q->position.m128_f32[2];
        double d0 = normal.m128_f32[0];
        _ReadWriteBarrier();
        d0 *= diff.m128_f32[0];
        d0 += (double)diff.m128_f32[1] * normal.m128_f32[1];
        d0 += (double)diff.m128_f32[2] * normal.m128_f32[2];
        float d = (float)d0;
        if (gtv_00dd6c10(d, -1.1920929e-07f)) { visited.clearAndFree(); return 0; }
    }
    visited.clearAndFree(); return 0;
}

