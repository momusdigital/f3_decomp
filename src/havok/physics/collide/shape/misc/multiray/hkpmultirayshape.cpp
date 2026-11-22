#include "f3_common.h"
// src/havok/physics/collide/shape/misc/multiray/hkpmultirayshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/multiray/hkpmultirayshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMultiRayShape.h"

// FUN_00e3c610: stores zero byte through first stdcall argument and returns it.

// @fnv 0x00e3c610
// pdb: hkArray<hkpSimpleMeshShape::Triangle,hkContainerHeapAllocator>::hkArray<hkpSimpleMeshShape::Triangle,hkContainerHeapAllocator> | hkpSimpleMeshShape.obj | fnv360_0822_debug, objrun_open, low
unsigned char* __stdcall FUN_00e3c610(unsigned char* out, int a1, int a2)
{
    *out = 0;
    return out;
}

// @fnv 0x00e3c600
// pdb: hkpKeyframedRigidMotion::applyForce | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: deltaTime, force, p
void __stdcall FUN_00e3c600(int a1, int a2, int a3)
{}

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayE3C6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};

class hkStatisticsCollectorE3C6
{
  public:
    virtual ~hkStatisticsCollectorE3C6() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayE3C6<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
}

struct hkMemoryAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" NineIntegerRecord* FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int reqCapacity, int elemSize);

struct __declspec(align(16)) hkWorldRay
{
    __m128 m_kRayStart;
    __m128 m_kRayEnd;
};

struct hkWorldRayArray
{
    hkWorldRay* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(hkWorldRay));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        _setSize(FUN_00c85750()->heap(), n);
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(hkWorldRay));
    }
};

struct hkInplaceWorldRayArray : hkWorldRayArray
{
    hkWorldRay m_kStorage[16];
    __forceinline hkInplaceWorldRayArray()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000010;
    }
};

extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* array, int numElem, int sizeElem);
struct RayStandIn
{
    __m128 m_kRayStart;
    __m128 m_kRayEnd;
};

struct RayArrayStandIn
{
    RayStandIn* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    RayArrayStandIn() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(RayStandIn));
        }
    }
    RayStandIn* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    RayStandIn* expandBy(int n)
    {
        return _expandBy(FUN_00c85750()->heap(), n);
    }
};

struct RefObjStandIn
{
    virtual ~RefObjStandIn();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    RefObjStandIn() : m_sReferenceCount(1)
    {}
};

struct ShapeStandIn : RefObjStandIn
{
    unsigned long m_ulUserData;
    unsigned int m_type;
    ShapeStandIn(unsigned int type) : m_ulUserData(0), m_type(type)
    {}
};
