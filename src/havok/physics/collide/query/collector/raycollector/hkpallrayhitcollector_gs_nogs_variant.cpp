// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl FUN_00c852c0(void* owner, int a2, int a3, int a4);
class FUN_00c855f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_10;
    int m_14;

    void FUN_00c855f0();
};

#include <xmmintrin.h>
struct __declspec(align(16)) Item
{
    __m128 v;
    float key;
    int unk14;
    int shapeKeys[10];
    void* u40;
    __declspec(align(16)) void* u50;

    __forceinline Item()
    {
        shapeKeys[2] = -1;
    }

    __forceinline Item(const Item& rhs)
    {
        v = rhs.v;
        key = rhs.key;
        unk14 = rhs.unk14;
        for (int n = 0; n < 10; ++n)
            shapeKeys[n] = rhs.shapeKeys[n];
        u40 = rhs.u40;
        u50 = rhs.u50;
    }

    __forceinline Item& operator=(const Item& rhs)
    {
        v = rhs.v;
        key = rhs.key;
        unk14 = rhs.unk14;
        for (int n = 0; n < 10; ++n)
            shapeKeys[n] = rhs.shapeKeys[n];
        u40 = rhs.u40;
        u50 = rhs.u50;
        return *this;
    }
};

static __forceinline bool lessThan(const Item& a, const Item& b)
{
    return a.key < b.key;
}

template <typename T> static __forceinline void swap(T& a, T& b)
{
    T t;
    t = b;
    b = a;
    a = t;
}

// @f3 0x008f7140 (community match, verified in this file)
static __forceinline void copyItem(Item& d, const Item& s)
{
    float* df = (float*)&d;
    const float* sf = (const float*)&s;
    df[0] = sf[0];
    df[1] = sf[1];
    df[2] = sf[2];
    df[3] = sf[3];
    df[4] = sf[4];
    d.unk14 = s.unk14;
    for (int n = 0; n < 10; ++n)
        d.shapeKeys[n] = s.shapeKeys[n];
    d.u40 = s.u40;
    d.u50 = s.u50;
}

static __forceinline void swapItem(Item& a, Item& b)
{
    Item t;
    copyItem(t, b);
    copyItem(b, a);
    copyItem(a, t);
}

// pdb: hkAlgorithm::quickSortRecursive<hkpWorldRayCastOutput,hkAlgorithm::less<hkpWorldRayCastOutput> > | hkpAllRayHitCollector.obj | fnv360_0822_retail, call_seq, high
// pdb params: pArr, d, h, cmpLess
void __cdecl FUN_00c852c0(Item* arr, int low, int high, int a4)
{
    int i = low;
    int j = high;
    Item pivot;
    copyItem(pivot, arr[(low + high) >> 1]);

    do
    {
        while (lessThan(arr[i], pivot))
            i++;
        while (lessThan(pivot, arr[j]))
            j--;

        if (j >= i)
        {
            if (j == i)
            {
                j--;
                i++;
            }
            else
            {
                swapItem(arr[i], arr[j]);
                j--;
                i++;
            }
        }
    } while (i <= j);

    if (low < j)
        FUN_00c852c0(arr, low, j, a4);
    if (i < high)
        FUN_00c852c0(arr, i, high, a4);
}

