#include "f3_common.h"
// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d1bb40_Class
{
    int* FUN_00d1bb40(unsigned short index);
};

// @fnv 0x00d1bb40
int* FUN_00d1bb40_Class::FUN_00d1bb40(unsigned short index)
{
    return *reinterpret_cast<int**>(this) + index * 12;
}

inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}

struct S_00d1bcb0_Allocator
{
    int unk00;
};

struct S_00d1bcb0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d1bcb0_Allocator* m_pStreamAllocator;
    S_00d1bcb0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00d1bcb0_Router* FUN_00c85750();
void ResizeAudioStream(S_00d1bcb0_Allocator& alloc, void* array, int sizeElem);

struct S_00d1bcb0_Entry
{
    int m_kPointA;
    int m_kPointB;
};

struct S_00d1bcb0_Array
{
    S_00d1bcb0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _pushBack(S_00d1bcb0_Allocator& alloc, const S_00d1bcb0_Entry& e)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(S_00d1bcb0_Entry));
        new (m_data + m_iElementCount) S_00d1bcb0_Entry(e);
        m_iElementCount++;
    }
    void AddBack(const S_00d1bcb0_Entry& e)
    {
        _pushBack(FUN_00c85750()->heap(), e);
    }
};

extern int __cdecl FUN_00d1c560(void*, int, int, int, int, int);

int __cdecl FUN_00d1c560(void* a, void* b, int c, int d, void* e, void* f);

extern int __cdecl FUN_00d1c560(void*, int, int, int, int, int);

extern "C" void __cdecl FUN_00d1ca00();
// @fnv 0x00d1d530
// pdb: bhkShape::LinkObject | bhkShape.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: arStream
extern "C" void __cdecl FUN_00d1d530()
{
    FUN_00d1ca00();
}

extern int __cdecl FUN_00d1bfa0();
// @fnv 0x00d1d490
int __cdecl FUN_00d1d490()
{
    return FUN_00d1bfa0();
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct DIntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _pushBack(S_00d1bcb0_Allocator& alloc, int e)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(int));
        hkConstructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
    __forceinline void AddBack(int e)
    {
        _pushBack(FUN_00c85750()->heap(), e);
    }
};

namespace fnv_00d1d5a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_cmple_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmpge_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" int _mm_movemask_ps(__m128 a);

void __cdecl FUN_00c908c0(S_00d1bcb0_Allocator* alloc, void* array, int reqCapacity, int elemSize);

struct hkMemoryAllocatorV
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct TreeVector4
{
    __m128 m_vComponents;
};

struct TreeAabb
{
    TreeVector4 m_kMinimumCorner;
    TreeVector4 m_kMaximumCorner;

    bool overlaps(const TreeAabb& other) const
    {
        __m128 mincomp = _mm_cmple_ps(m_kMinimumCorner.m_vComponents, other.m_kMaximumCorner.m_vComponents);
        __m128 maxcomp = _mm_cmpge_ps(m_kMaximumCorner.m_vComponents, other.m_kMinimumCorner.m_vComponents);
        return (_mm_movemask_ps(_mm_and_ps(mincomp, maxcomp)) & 7) == 7;
    }
};

struct TreeNode
{
    TreeAabb m_kBounds;
    int m_children[2];
    unsigned int m_parent;
    int m_next;

    unsigned int isLeaf() const
    {
        return m_parent & 0x80000000u;
    }
};

struct TreeNodeArray
{
    TreeNode* FUN_00d9a4c0(int index);
};

typedef S_00d1bcb0_Entry TreePair;

struct TreePairStack
{
    TreePair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    TreePair m_kStorage[64];

    __forceinline TreePairStack()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000040;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(S_00d1bcb0_Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(TreePair));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(FUN_00c85750()->heap(), n);
        m_iElementCount = n;
    }
    __forceinline void _clearAndDeallocate(S_00d1bcb0_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            reinterpret_cast<hkMemoryAllocatorV&>(alloc).ReturnMemory(m_data, getCapacity() * sizeof(TreePair));
    }
};

struct TreePairArray
{
    TreePair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _pushBack(S_00d1bcb0_Allocator& alloc, const TreePair& e)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(TreePair));
        new (m_data + m_iElementCount) TreePair(e);
        m_iElementCount++;
    }
    __forceinline void AddBack(const TreePair& e)
    {
        _pushBack(FUN_00c85750()->heap(), e);
    }
};

}  // namespace fnv_00d1d5a0

#include <windows.h>

extern "C" __m128 _mm_set_ps1(float a);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_or_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmpeq_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_rcp_ps(__m128 a);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

extern __m128 DAT_010c7170;  // (1,1,1,1)
extern float DAT_01267e30;   // zero vector (bss)
extern __m128 DAT_010cd670;  // HK_REAL_MAX x4

struct VectorMask
{
    __m128 bits;
    __forceinline int testX() const
    {
        return _mm_movemask_ps(bits) & 1;
    }
};
struct TreeVector4
{
    __forceinline void operator=(const TreeVector4& other)
    {
        m_vComponents = other.m_vComponents;
    }
    __m128 m_vComponents;
    __forceinline void subtract(const TreeVector4& a, const TreeVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void multiply(const TreeVector4& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void minimum(const TreeVector4& a, const TreeVector4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void maximum(const TreeVector4& a, const TreeVector4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void broadcastY(const TreeVector4& a)
    {
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0x55);
    }
    __forceinline void broadcastZ(const TreeVector4& a)
    {
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xaa);
    }
    __forceinline VectorMask equal(const TreeVector4& b) const
    {
        VectorMask r;
        r.bits = _mm_cmpeq_ps(m_vComponents, b.m_vComponents);
        return r;
    }
    __forceinline VectorMask less(const TreeVector4& b) const
    {
        VectorMask r;
        r.bits = _mm_cmplt_ps(m_vComponents, b.m_vComponents);
        return r;
    }
    __forceinline void choose(const TreeVector4& a, const TreeVector4& b, const VectorMask& m)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(m.bits, b.m_vComponents), _mm_andnot_ps(m.bits, a.m_vComponents));
    }
    __forceinline void reciprocal(const TreeVector4& a)
    {
        __m128 input = _mm_shuffle_ps(a.m_vComponents, _mm_unpackhi_ps(a.m_vComponents, DAT_010c7170), 0xc4);
        __m128 estimate = _mm_rcp_ps(input);
        m_vComponents = _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, input), estimate));
    }
};

struct RayQ
{
    TreeVector4 m_kRayStart;
    TreeVector4 m_vInverseDirection;
    __forceinline void init(const TreeVector4& from, const TreeVector4& to)
    {
        m_kRayStart = from;
        TreeVector4 delta;
        delta.subtract(to, from);
        VectorMask zeros = delta.equal(*reinterpret_cast<const TreeVector4*>(&DAT_01267e30));
        TreeVector4 safe;
        safe.choose(delta, *reinterpret_cast<const TreeVector4*>(&DAT_010c7170), zeros);
        TreeVector4 inverse;
        inverse.reciprocal(safe);
        m_vInverseDirection.choose(inverse, *reinterpret_cast<const TreeVector4*>(&DAT_010cd670), zeros);
    }
};

struct TreeAabb
{
    TreeVector4 m_kMinimumCorner;
    TreeVector4 m_kMaximumCorner;
    __forceinline int hit(const TreeVector4& start, const TreeVector4& invDir, const TreeVector4& limit) const
    {
        TreeVector4 lo;
        lo.subtract(m_kMinimumCorner, start);
        lo.multiply(invDir);
        TreeVector4 hi;
        hi.subtract(m_kMaximumCorner, start);
        hi.multiply(invDir);
        TreeVector4 nearT;
        nearT.minimum(lo, hi);
        TreeVector4 nz;
        nz.broadcastZ(nearT);
        TreeVector4 nX;
        nX.maximum(nearT, *reinterpret_cast<const TreeVector4*>(&DAT_01267e30));
        TreeVector4 ny;
        ny.broadcastY(nearT);
        TreeVector4 farT;
        farT.maximum(lo, hi);
        TreeVector4 afDepth;
        afDepth.broadcastZ(farT);
        TreeVector4 fX;
        fX.minimum(farT, limit);
        TreeVector4 nYZ;
        nYZ.maximum(ny, nz);
        nX.maximum(nX, nYZ);
        TreeVector4 fy;
        fy.broadcastY(farT);
        TreeVector4 fYZ;
        fYZ.minimum(fy, afDepth);
        fX.minimum(fX, fYZ);
        return nX.less(fX).testX();
    }
};

struct TreeNode
{
    TreeVector4 m_kMinimumCorner;
    TreeVector4 m_kMaximumCorner;
    int m_child0;
    int m_child1;
    unsigned int m_parent;
    int m_next;
};

struct TreeNodeArray
{
    TreeNode* FUN_00d9a4c0(int index);
};

extern "C" __m128 _mm_setr_ps(float, float, float, float);

extern __m128 DAT_01268460[];
extern const int DAT_010c92e0[4];

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vComponents;
    }
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void sub4(const hkVector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void mul4(const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad());
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_max_ps(a.getQuad(), b.getQuad());
    }
    __forceinline void setBroadcast(const hkVector4& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
};

struct Vector4Comparison
{
    __m128 m_uiMask;
    __forceinline void set(int m)
    {
        m_uiMask = DAT_01268460[m];
    }
    __forceinline void setAnd(const Vector4Comparison& a, const Vector4Comparison& b)
    {
        m_uiMask = _mm_and_ps(a.m_uiMask, b.m_uiMask);
    }
    __forceinline int anyIsSet(int m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
};

struct Bundle
{
    hkVector4 m_data[3];
};

struct RayQuerySet
{
    Bundle m_vFrom;
    Bundle m_vInverseDirection;
    int m_uiMask;
};

struct QuantizedAabb
{
    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];
};

struct Node16
{
    QuantizedAabb m_iBufferSize;
    unsigned short m_ausChildIndices[2];
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;
    __forceinline int isLeaf() const
    {
        return m_usNodeValue & 0x8000;
    }
};

struct IndexedNode16Collection
{
    int unk00;
    const Node16* GetEntryOffset(unsigned short idx) const;
};

struct hkAabbTree16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    IndexedNode16Collection m_kNodeManager;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_kAabbMin;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    hkVector4 m_kAabbInverseScale;
    __forceinline const Node16* getChild(const Node16* node, int i) const
    {
        return m_kNodeManager.GetEntryOffset(node->m_ausChildIndices[i]);
    }
    __forceinline const Node16* getSkipNode(const Node16* node) const
    {
        return (node->m_iSkipNodeIndex != 0x7fff) ? m_kNodeManager.GetEntryOffset(node->m_iSkipNodeIndex) : 0;
    }
};

struct Collector
{
    virtual ~Collector();
    virtual float GetHitDistance(const Node16* leaf);
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    __forceinline hkAabb()
    {}
};

struct RayQueryAabb : hkAabb
{
    __forceinline RayQueryAabb()
    {}
    __forceinline int overlaps(const RayQuerySet& ray, const hkVector4& ealyOutFractions,
                               Vector4Comparison& hitOut) const
    {
        hkVector4 max[3];
        max[0].setBroadcast(m_kMaximumCorner, 0);
        max[1].setBroadcast(m_kMaximumCorner, 1);
        max[2].setBroadcast(m_kMaximumCorner, 2);

        hkVector4 min[3];
        min[0].setBroadcast(m_kMinimumCorner, 0);
        min[1].setBroadcast(m_kMinimumCorner, 1);
        min[2].setBroadcast(m_kMinimumCorner, 2);

        Bundle dNear;
        Bundle dFar;

        for (int i = 0; i < 3; i++)
        {
            hkVector4 dNearTmp;
            hkVector4 dFarTmp;
            dNearTmp.setSub4(min[i], ray.m_vFrom.m_data[i]);
            dFarTmp.setSub4(max[i], ray.m_vFrom.m_data[i]);
            dNearTmp.mul4(ray.m_vInverseDirection.m_data[i]);
            dFarTmp.mul4(ray.m_vInverseDirection.m_data[i]);

            dNear.m_data[i].setMin4(dNearTmp, dFarTmp);
            dFar.m_data[i].setMax4(dNearTmp, dFarTmp);
        }

        hkVector4 maxNear;
        hkVector4 minFar;

        maxNear.setMax4(dNear.m_data[0], dNear.m_data[1]);
        maxNear.setMax4(maxNear, dNear.m_data[2]);
        maxNear.setMax4(maxNear, *reinterpret_cast<const hkVector4*>(&DAT_01267e30));

        minFar.setMin4(dFar.m_data[0], dFar.m_data[1]);
        minFar.setMin4(minFar, dFar.m_data[2]);
        minFar.setMin4(minFar, ealyOutFractions);

        hitOut.set(ray.m_uiMask);
        Vector4Comparison lt;
        lt.m_uiMask = _mm_cmplt_ps(maxNear.m_vComponents, minFar.m_vComponents);
        hitOut.setAnd(lt, hitOut);

        return hitOut.anyIsSet(ray.m_uiMask);
    }
};

static __forceinline void restoreAabb(const QuantizedAabb& in, const hkVector4& bitScaleInv,
                                      const hkVector4& bitOffsetLow, hkAabb& out)
{
    out.m_kMaximumCorner.set((float)(in.m_kMaximumCorner[0] << 15), (float)(in.m_kMaximumCorner[1] << 15),
                             (float)(in.m_kMaximumCorner[2] << 15));
    out.m_kMinimumCorner.set((float)(in.m_kMinimumCorner[0] << 15), (float)(in.m_kMinimumCorner[1] << 15),
                             (float)(in.m_kMinimumCorner[2] << 15));

    out.m_kMinimumCorner.mul4(bitScaleInv);
    out.m_kMaximumCorner.mul4(bitScaleInv);
    out.m_kMinimumCorner.sub4(bitOffsetLow);
    out.m_kMaximumCorner.sub4(bitOffsetLow);
}

// Walks the AABB tree from node to escapeNode, testing each node's bounds against the ray and updating collector hit distances on leaf overlaps.
// @fnv 0x00d1bfa0
void FUN_00d1bfa0(const hkAabbTree16* tree, const Node16* apStartNode, const Node16* escapeNode,
                  const RayQuerySet& rayBundle, Collector* const* appCollectors, const float* apEarlyOutFractions)
{
    hkVector4 earlyOut;
    earlyOut.set(apEarlyOutFractions[0], apEarlyOutFractions[1], apEarlyOutFractions[2], apEarlyOutFractions[3]);

    const hkVector4& bitScaleInv = tree->m_kAabbInverseScale;
    const hkVector4& bitOffsetLow = tree->m_kAabbMin;

    while (1)
    {
        RayQueryAabb aabb;
        restoreAabb(apStartNode->m_iBufferSize, bitScaleInv, bitOffsetLow, aabb);

        const Node16* next = tree->getSkipNode(apStartNode);

        Vector4Comparison hits;
        if (aabb.overlaps(rayBundle, earlyOut, hits))
        {
            if (!apStartNode->isLeaf())
            {
                apStartNode = tree->getChild(apStartNode, 0);
                continue;
            }
            for (int ir = 0; ir < 4; ir++)
            {
                if (hits.anyIsSet(DAT_010c92e0[ir]))
                {
                    earlyOut(ir) = appCollectors[ir]->GetHitDistance(apStartNode);
                }
            }
        }

        if (next == escapeNode)
            break;
        apStartNode = next;
    }
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

struct S1c2b0_Cmp
{
    __m128 m_uiMask;
    __forceinline int anyIsSet(int m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
};

struct hkVector4Real
{
    __m128 m_vComponents;
    __forceinline hkVector4Real& operator=(const hkVector4Real& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vComponents;
    }
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    __forceinline void setAdd4(const hkVector4Real& a, const hkVector4Real& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4Real& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void sub4(const hkVector4Real& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void mul4(const hkVector4Real& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline hkVector4Real setSub4(const hkVector4Real& a, const hkVector4Real& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
        return *this;
    }
    __forceinline hkVector4Real setMin4(const hkVector4Real& a, const hkVector4Real& b)
    {
        m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad());
        return *this;
    }
    __forceinline hkVector4Real setMax4(const hkVector4Real& a, const hkVector4Real& b)
    {
        m_vComponents = _mm_max_ps(a.getQuad(), b.getQuad());
        return *this;
    }
    __forceinline hkVector4Real& setBroadcast(const hkVector4Real& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        return *this;
    }
    __forceinline S1c2b0_Cmp compareEqual4(const hkVector4Real& a) const
    {
        S1c2b0_Cmp m;
        m.m_uiMask = _mm_cmpeq_ps(m_vComponents, a.m_vComponents);
        return m;
    }
    __forceinline S1c2b0_Cmp compareLessThan4(const hkVector4Real& a) const
    {
        S1c2b0_Cmp m;
        m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
        return m;
    }
    __forceinline hkVector4Real& select32(const hkVector4Real& a, const hkVector4Real& b, const S1c2b0_Cmp& comp)
    {
        m_vComponents =
            _mm_or_ps(_mm_and_ps(comp.m_uiMask, b.m_vComponents), _mm_andnot_ps(comp.m_uiMask, a.m_vComponents));
        return *this;
    }
    __forceinline hkVector4Real& setReciprocal3(const hkVector4Real& a)
    {
        __m128 input = _mm_shuffle_ps(a.m_vComponents, _mm_unpackhi_ps(a.m_vComponents, DAT_010c7170), 0xc4);
        __m128 estimate = _mm_rcp_ps(input);
        m_vComponents = _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, input), estimate));
        return *this;
    }
};

struct hkpCompressedNode
{
    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];
    unsigned short m_pChildAtom;
    unsigned short m_unk0e;
    unsigned short m_flags;
    unsigned short m_skip;
};

struct S1c2b0_Ray
{
    hkVector4Real m_kRayStart;
    hkVector4Real m_vInverseDirection;
    __forceinline void setRay(const hkVector4Real& start, const hkVector4Real& end)
    {
        m_kRayStart = start;
        hkVector4Real delta;
        delta.m_vComponents = _mm_sub_ps(end.m_vComponents, start.m_vComponents);
        S1c2b0_Cmp isZero = delta.compareEqual4(*reinterpret_cast<const hkVector4Real*>(&DAT_01267e30));
        hkVector4Real maskedDelta;
        maskedDelta.select32(delta, *reinterpret_cast<const hkVector4Real*>(&DAT_010c7170), isZero);
        hkVector4Real invDelta;
        invDelta.setReciprocal3(maskedDelta);
        m_vInverseDirection.select32(invDelta, *reinterpret_cast<const hkVector4Real*>(&DAT_010cd670), isZero);
    }
};

struct S1c2b0_Aabb
{
    hkVector4Real m_kMinimumCorner;
    hkVector4Real m_kMaximumCorner;
    __forceinline int overlaps(const S1c2b0_Ray& r, const hkVector4Real& earlyOutHitFraction) const
    {
        hkVector4Real dNearTemp;
        hkVector4Real dFarTemp;
        dNearTemp.setSub4(m_kMinimumCorner, r.m_kRayStart);
        dFarTemp.setSub4(m_kMaximumCorner, r.m_kRayStart);
        dNearTemp.mul4(r.m_vInverseDirection);
        dFarTemp.mul4(r.m_vInverseDirection);
        hkVector4Real dNear;
        dNear.setMin4(dNearTemp, dFarTemp);
        hkVector4Real dFar;
        dFar.setMax4(dNearTemp, dFarTemp);
        hkVector4Real dNearY;
        dNearY.setBroadcast(dNear, 1);
        hkVector4Real dNearZ;
        dNearZ.setBroadcast(dNear, 2);
        hkVector4Real dFarY;
        dFarY.setBroadcast(dFar, 1);
        hkVector4Real dFarZ;
        dFarZ.setBroadcast(dFar, 2);
        hkVector4Real nearYZ;
        nearYZ.setMax4(dNearY, dNearZ);
        hkVector4Real farYZ;
        farYZ.setMin4(dFarY, dFarZ);
        hkVector4Real nearX;
        nearX.setMax4(dNear, *reinterpret_cast<const hkVector4Real*>(&DAT_01267e30));
        hkVector4Real farX;
        farX.setMin4(dFar, earlyOutHitFraction);
        nearX.setMax4(nearX, nearYZ);
        farX.setMin4(farX, farYZ);
        S1c2b0_Cmp nearLtFar = nearX.compareLessThan4(farX);
        return nearLtFar.anyIsSet(1);
    }
};

struct S1c2b0_TreeAabb : S1c2b0_Aabb
{
    __forceinline S1c2b0_TreeAabb()
    {}
};

static __forceinline void restoreAabb(const hkpCompressedNode& in, const hkVector4Real& bitScaleInv,
                                      const hkVector4Real& bitOffsetLow, S1c2b0_Aabb& out)
{
    out.m_kMaximumCorner.set((float)(in.m_kMaximumCorner[0] << 15), (float)(in.m_kMaximumCorner[1] << 15),
                             (float)(in.m_kMaximumCorner[2] << 15));
    out.m_kMinimumCorner.set((float)(in.m_kMinimumCorner[0] << 15), (float)(in.m_kMinimumCorner[1] << 15),
                             (float)(in.m_kMinimumCorner[2] << 15));
    out.m_kMinimumCorner.mul4(bitScaleInv);
    out.m_kMaximumCorner.mul4(bitScaleInv);
    out.m_kMinimumCorner.sub4(bitOffsetLow);
    out.m_kMaximumCorner.sub4(bitOffsetLow);
}

static __forceinline hkVector4Real expandedValue(const hkVector4Real& a, const hkVector4Real& b)
{
    hkVector4Real out;
    out.setAdd4(a, b);
    return out;
}
static __forceinline __m128 expandedQuad(__m128 a, __m128 b)
{
    return _mm_add_ps(a, b);
}
static __forceinline void expandedRef(hkVector4Real& out, const hkVector4Real& a, const hkVector4Real& b)
{
    out.setAdd4(a, b);
}
static __forceinline void expandedVal(hkVector4Real& out, __m128 a, __m128 b)
{
    out.m_vComponents = _mm_add_ps(a, b);
}

static __forceinline Vector4Comparison queryLessEqual(const hkVector4& a, const hkVector4& b)
{
    Vector4Comparison r;
    r.m_uiMask = _mm_cmple_ps(a.m_vComponents, b.m_vComponents);
    return r;
}

class QueryAabb
{
  public:
    __forceinline QueryAabb()
    {}
    __forceinline int overlaps(const QueryAabb& other) const
    {
        Vector4Comparison mincomp = queryLessEqual(m_kMinimumCorner, other.m_kMaximumCorner);
        Vector4Comparison maxcomp = queryLessEqual(other.m_kMinimumCorner, m_kMaximumCorner);
        Vector4Comparison both;
        both.setAnd(mincomp, maxcomp);
        return ((_mm_movemask_ps(both.m_uiMask) & 7) == 7);
    }
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct QueryAabbTreeAabbD : public QueryAabb
{
    __forceinline QueryAabbTreeAabbD()
    {}
};

struct QueryBounds16
{
    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];

    __forceinline static void restoreAabb(const QueryBounds16& in, const hkVector4& bitScaleInv,
                                          const hkVector4& bitOffsetLow, QueryAabb& out)
    {
        out.m_kMaximumCorner.set((float)(in.m_kMaximumCorner[0] << 15), (float)(in.m_kMaximumCorner[1] << 15),
                                 (float)(in.m_kMaximumCorner[2] << 15));
        out.m_kMinimumCorner.set((float)(in.m_kMinimumCorner[0] << 15), (float)(in.m_kMinimumCorner[1] << 15),
                                 (float)(in.m_kMinimumCorner[2] << 15));
        out.m_kMinimumCorner.mul4(bitScaleInv);
        out.m_kMaximumCorner.mul4(bitScaleInv);
        out.m_kMinimumCorner.sub4(bitOffsetLow);
        out.m_kMaximumCorner.sub4(bitOffsetLow);
    }
};

class QueryNode
{
  public:
    static const unsigned short s_leafMask = 0x7fff;
    static const unsigned short s_leafFlag = 0x8000;
    QueryBounds16 m_iBufferSize;
    union
    {
        struct
        {
            unsigned short m_ausChildIndices[2];
        } m_kChildIndices;
        struct
        {
            void* m_ulUserData;
        } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;

    __forceinline int isLeaf() const
    {
        return m_usNodeValue & s_leafFlag;
    }
    template <typename T> __forceinline T getLeafData() const
    {
        T r = (T)m_kLeafData.m_ulUserData;
        return r;
    }
};

class QueryNodeManager
{
  public:
    QueryNode* GetEntryOffset(unsigned short idx);
    int m_kNodeCollection;
};

class QueryTree16
{
  public:
    static const unsigned short s_invalidIdx = 0x7fff;
    __forceinline QueryNode* getRootNode() const
    {
        return m_pAabbRootNode;
    }
    __forceinline QueryNode* getChild(const QueryNode* node, int i) const
    {
        return const_cast<QueryNodeManager&>(m_kNodeManager).GetEntryOffset(node->m_kChildIndices.m_ausChildIndices[i]);
    }
    __forceinline QueryNode* getSkipNode(const QueryNode* node) const
    {
        return (node->m_iSkipNodeIndex != s_invalidIdx)
                   ? const_cast<QueryNodeManager&>(m_kNodeManager).GetEntryOffset(node->m_iSkipNodeIndex)
                   : 0;
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    QueryNode* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    QueryNodeManager m_kNodeManager;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_kAabbMin;
    hkVector4 m_kAabbMaximum;
    hkVector4 m_kAabbScale;
    hkVector4 m_kAabbInverseScale;
};

struct VoidArray
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _pushBack(S_00d1bcb0_Allocator& alloc, void* const& e)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(void*));
        hkConstructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
    __forceinline void AddBack(void* const& e)
    {
        _pushBack(FUN_00c85750()->heap(), e);
    }
};

struct NodeMgrSV
{
    int* FUN_00d1bb40(unsigned short index);
};

struct FilterRays_Ray
{
    hkVector4 m_kRayStart;
    hkVector4 m_vInverseDirection;
};

class FilterRays_FilterAabb
{
  public:
    __forceinline FilterRays_FilterAabb()
    {}
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;

    __forceinline int overlaps(const FilterRays_Ray& r, const hkVector4& earlyOutHitFraction) const
    {
        hkVector4 dNearTemp;
        hkVector4 dFarTemp;
        dNearTemp.setSub4(m_kMinimumCorner, r.m_kRayStart);
        dFarTemp.setSub4(m_kMaximumCorner, r.m_kRayStart);
        dNearTemp.mul4(r.m_vInverseDirection);
        dFarTemp.mul4(r.m_vInverseDirection);
        hkVector4 dNear;
        dNear.setMin4(dNearTemp, dFarTemp);
        hkVector4 dFar;
        dFar.setMax4(dNearTemp, dFarTemp);
        hkVector4 dNearY;
        dNearY.setBroadcast(dNear, 1);
        hkVector4 dNearZ;
        dNearZ.setBroadcast(dNear, 2);
        hkVector4 dFarY;
        dFarY.setBroadcast(dFar, 1);
        hkVector4 dFarZ;
        dFarZ.setBroadcast(dFar, 2);
        hkVector4 nearYZ;
        nearYZ.setMax4(dNearY, dNearZ);
        hkVector4 farYZ;
        farYZ.setMin4(dFarY, dFarZ);
        hkVector4 nearX;
        nearX.setMax4(dNear, *reinterpret_cast<const hkVector4*>(&DAT_01267e30));
        hkVector4 farX;
        farX.setMin4(dFar, earlyOutHitFraction);
        nearX.setMax4(nearX, nearYZ);
        farX.setMin4(farX, farYZ);
        Vector4Comparison nearLtFar;
        nearLtFar.m_uiMask = _mm_cmplt_ps(nearX.m_vComponents, farX.m_vComponents);
        return nearLtFar.anyIsSet(1);
    }
    __forceinline static void restoreAabb(const FilterRays_FilterAabb& in, const hkVector4& bitScaleInv,
                                          const hkVector4& bitOffsetLow, FilterRays_FilterAabb& out)
    {
        out = in;
    }
};

struct FilterRays_Node
{
    FilterRays_FilterAabb m_iBufferSize;
    unsigned short m_ausChildIndices[2];
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;

    __forceinline int isLeaf() const
    {
        return m_usNodeValue & 0x8000;
    }
    void CopyFrom(int* other);
};

struct FilterRays_Tree
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_00d1bb40_Class m_kNodeManager;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    hkVector4 m_kAabbMin;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    hkVector4 m_kAabbInverseScale;
    __forceinline int* getChild(const FilterRays_Node* node, int i) const
    {
        return ((NodeMgrSV*)&m_kNodeManager)->FUN_00d1bb40(node->m_ausChildIndices[i]);
    }
};

struct FilterRays_FilterCollector
{
    virtual ~FilterRays_FilterCollector();
    virtual float GetHitDistance(const FilterRays_Node* leaf);
};

class hkpFixedBufferRayHitCollector
{
  public:
    __forceinline hkpFixedBufferRayHitCollector(int buffer, int capacity) : m_fEarlyOutHitFraction(1.0f)
    {
        m_pRayHitBuffer = buffer;
        m_pHitBufferEnd = buffer;
        m_pRayCursor = capacity;
        m_iHitCount = 0;
        m_pCollidable = 0;
    }
    virtual void CollectRayHit();
    float m_fEarlyOutHitFraction;
    int m_pRayHitBuffer;
    int m_pHitBufferEnd;
    int m_pRayCursor;
    int m_iHitCount;
    int m_pCollidable;
};

void __cdecl FUN_00d1ca00(const FilterRays_Tree* tree, const FilterRays_Node* node, const void* skipNode,
                          const RayQuerySet* bundle, FilterRays_FilterCollector** collectors, float* fractions);
