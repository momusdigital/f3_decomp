#include "f3_common.h"
// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl InitAndReturnTail(void*, void*, void*);
extern "C" void __cdecl FUN_00d34db0(void*, void*, void*);
extern "C" void __cdecl FUN_00d34d30(void*, void*, void*);
extern "C" void __cdecl ForwardCall(void*, void*, void*);
extern "C" void __cdecl FUN_00d34d80(void*, void*, void*);
extern "C" void __cdecl FUN_00d35770(void*, void*, void*);
extern "C" void __cdecl FUN_00da6dc0(void*, void*, void*);

struct FUN_00d36270_s {
    void* m_vt;
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
    void* m_k;
    unsigned char m_flag;
};

// Initializes the object's vtable and function pointers, clears several pointer fields to zero, and sets m_flag to 1.
// @fnv 0x00d36270
void FUN_00d36270(FUN_00d36270_s* self)
{
    self->m_vt = &InitAndReturnTail;
    self->m_k = &FUN_00d35770;
    self->m_iUnknownValue = 0;
    self->m_kPointB = 0;
    self->m_iThirdValue = 0;
    self->m_iFourthElementInteger = 0;
    self->m_usTrailingValue = 0;
    self->m_f = &FUN_00d34db0;
    self->m_g = &FUN_00d34d30;
    self->m_h = &ForwardCall;
    self->m_i = &FUN_00d34d80;
    self->m_kPointA = &FUN_00da6dc0;
    self->m_flag = 1;
}

void __cdecl hkAgent1nMachine_WarpTime(void*, float, float, void*);

// Calls hkAgent1nMachine_WarpTime with b, c, d and e, ignoring a.
// @fnv 0x00d34d80
// pdb: hkListAgent3::warpTime | hkpListAgent3.obj | fnv360_0822_retail, objrun, medium
// pdb params: entry, agentData, oldTime, newTime, input
void __cdecl FUN_00d34d80(void* apUnused, void* b, float afValue1, float afValue2, void* e)
{
    hkAgent1nMachine_WarpTime(b, afValue1, afValue2, e);
}

struct __declspec(align(16)) D36270Data {
    void* vtable;
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
    void* g;
    void* h;
    void* i;
    void* j;
    void* k;
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
};
void FUN_00d36270(D36270Data*);
struct D362Script {
    void AddEntry(D36270Data*, int row, int column);
};
// @f3 0x009d1070 (community match, verified in this file)
// pdb: hkpCollectionCollectionAgent3::registerAgent3 | hkpCollectionCollectionAgent3.obj | tesv_win, caller_sim, low
void FUN_00d362c0(D362Script* script)
{
    D36270Data data;
    data.flag0 = 0; data.flag1 = 0; data.flag2 = 0;
    data.f = 0; data.g = 0; data.h = 0; data.i = 0; data.j = 0;
    FUN_00d36270(&data);
    script->AddEntry(&data, 9, 9);
    data.flag1 = 1; data.flag2 = 1;
    script->AddEntry(&data, 8, 9);
    script->AddEntry(&data, 9, 8);
    script->AddEntry(&data, 8, 8);
    *(unsigned char*)((char*)script + 0x1e22) = 1;
}


#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern "C" void __cdecl FUN_00d97250(void*, void*, void*);
extern "C" const char str_010ceca8[];

struct S00d34d30_Obj
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(const char* s);
    virtual void m7();
};

// @fnv 0x00d34d30
void __cdecl FUN_00d34d30(void* a, void* b, void* c, void* d)
{
    S00d34d30_Obj* obj = (S00d34d30_Obj*)d;
    obj->m6(str_010ceca8);
    FUN_00d97250(b, c, d);
    obj->m7();
}

extern "C" void __cdecl FUN_00da4900(void*, void*);

// Fills a Local struct with a3 through a7 and the m10() results of the objects at a3 and a4, then calls FUN_00da4900 with a2 and the struct.
// @f3 0x009ce320 (community match, verified in this file)
struct Obj6 {
    virtual void* m00();
    virtual void* m04();
    virtual void* m08();
    virtual void* m0c();
    virtual void* m10();
    virtual void* m14();
};
struct Local7 {
    void* f0; void* f1; void* f2; void* f3; void* f4; void* f5; void* f6; void* f7;
};
extern "C" void __cdecl FUN_00da4900(void*, void*);
// pdb: hkpCollectionCollectionAgent3::updateFilter | hkpCollectionCollectionAgent3.obj | tesv_win, caller_sim, low
void __cdecl FUN_00d34db0(void* apUnused, void* a2, void* apFirstObj, void* apSecondObj, void* a5, void* a6, void* a7)
{
    Local7 s;
    void* pFirstObj = *(void**)apFirstObj;
    void* pSecondObj = *(void**)apSecondObj;

    s.f0 = apFirstObj;
    s.f1 = apSecondObj;
    s.f4 = a5;
    s.f5 = a6;
    s.f6 = a7;
    s.f2 = ((Obj6*)pFirstObj)->m14();
    s.f3 = ((Obj6*)pSecondObj)->m14();

    FUN_00da4900(a2, &s);
}


union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };

extern "C" {
__m128 _mm_load_ps(const float* p);
__m128 _mm_add_ps(__m128 a, __m128 b);
__m128 _mm_sub_ps(__m128 a, __m128 b);
__m128 _mm_mul_ps(__m128 a, __m128 b);
__m128 _mm_min_ps(__m128 a, __m128 b);
__m128 _mm_max_ps(__m128 a, __m128 b);
__m128 _mm_add_ss(__m128 a, __m128 b);
__m128 _mm_sqrt_ss(__m128 a);
__m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm8);
}

extern __m128 DAT_010ec7f0;

typedef unsigned int hkpShapeKey;

struct hkSimdRealq
{
    __m128 m_vValue;
};

struct hkVector4q
{
    __m128 m_vComponents;


    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAdd4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const hkVector4q& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }

    __forceinline void setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(DAT_010ec7f0.m128_f32), t.m_vComponents), a.m_vComponents), _mm_mul_ps(t.m_vComponents, b.m_vComponents));
    }

    __forceinline void setAddMul4(const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& r)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents), a.m_vComponents);
    }

    __forceinline hkSimdRealq getSimdAt3() const
    {
        hkSimdRealq r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }

    __forceinline hkSimdRealq length3() const
    {
        const __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
        hkSimdRealq r;
        r.m_vValue = _mm_sqrt_ss(s);
        return r;
    }
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct hkAabbUint32
{
    unsigned int m_kMinimumCorner[3];
    union {
        struct { unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; };
        hkpShapeKey m_uiCollisionShapeKey;
    };
    union {
        unsigned int m_kMaximumCorner[4];
        struct { unsigned int m_maxX; unsigned int m_maxY; unsigned int m_maxZ;
                 unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
    };
};
typedef hkAabbUint32 hkAabbUint32Key;

class hkpShapeq
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, hkAabbq& out) const;
};

struct hkpCdBodyq
{
    const hkpShapeq* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyq* m_parent;

    __forceinline const hkpCdBodyq* getRootCollidable() const
    {
        const hkpCdBodyq* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return body;
    }
};

union hkVec4F
{
    __m128 m_vComponents;
    float m_f[4];
    __forceinline float operator()(int i) const { return m_f[i]; }
};

static __forceinline void convertToUint32WithClip(const hkVector4q& a, const hkVector4q& b, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}


struct BoundingVolumeData : hkAabbUint32
{
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    hkAabbUint32* m_pChildShapeAabbs;
    hkpShapeKey* m_pChildShapeKeys;

    __forceinline bool isValid() const { return m_kMinimumCorner[0] <= m_kMaximumCorner[0]; }
};

struct hkAabbUint32Less
{
    unsigned char m_unused;
};

void __cdecl FUN_00d36360(hkAabbUint32Key* arr, int iStart, int iEnd, hkAabbUint32Less cmp);

typedef unsigned int hkUint32;

struct hkStringQ {
    static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
        hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
        do
        {
            dst32[0] = src32[0];
            dst32[1] = src32[1];
            dst32[2] = src32[2];
            dst32[3] = src32[3];
            dst32 += 4;
            src32 += 4;
        } while (--numQuads > 0);
    }
};

struct __declspec(align(16)) SortEntry {
    hkUint32 m_key;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkUint32 unk10;
    hkUint32 unk14;
    hkUint32 unk18;
    hkUint32 unk1C;
    SortEntry() {}
    SortEntry(const SortEntry& o) { hkStringQ::memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
    void operator=(const SortEntry& o) { hkStringQ::memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
};

struct SortEntryLess {
    bool operator()(const SortEntry& a, const SortEntry& b) const { return a.m_key < b.m_key; }
};

template <typename T>
__forceinline void hkSwap(T& x, T& y)
{
    T t(y);
    y = x;
    x = t;
}

// Sorts pArr[d..h] in place with quicksort, using the middle element as pivot and the cmpLess comparator.
// @fnv 0x00d36360
// pdb: hkAlgorithm::quickSortRecursive<hk1AxisSweep::AabbInt,hkAlgorithm::less<hk1AxisSweep::AabbInt> > | hkpCollectionCollectionAgent3.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: pArr, d, h, cmpLess
void __cdecl FUN_00d36360(SortEntry* pArr, int aiLow, int aiHigh, SortEntryLess cmpLess)
{
    int i, j;
    SortEntry strPivot;
begin:
    j = aiHigh;
    i = aiLow;
    strPivot = pArr[(aiLow + aiHigh) >> 1];
    do
    {
        while (cmpLess(pArr[i], strPivot)) { i++; }
        while (cmpLess(strPivot, pArr[j])) { j--; }
        if (j >= i)
        {
            if (j != i)
            {
                hkSwap(pArr[i], pArr[j]);
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (aiLow < j) FUN_00d36360(pArr, aiLow, j, cmpLess);
    if (i < aiHigh) { aiLow = i; goto begin; }
}
