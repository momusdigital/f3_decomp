#include "f3_common.h"
// src/havok/physics/dynamics/constraint/chain/stiffspring/hkpstiffspringchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/stiffspring/hkpstiffspringchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStiffSpringChainData.h"

// @fnv 0x00e3af30
// pdb: hkpStiffSpringChainData::getType | hkpStiffSpringChainData.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00e3af30()
{
    return 0x64;
}

struct ConstraintInfo
{
    int m_maxNumExternalSlaveContactPoints;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpBridgeAtoms* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

class hkpStiffSpringChain : public hkpStiffSpringChainData
{
  public:
    void FUN_00e3af40(ConstraintInfo& info);
};

// @fnv 0x00e3af40
// pdb: hkpStiffSpringChainData::getConstraintInfo | hkpStiffSpringChainData.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: info
void hkpStiffSpringChain::FUN_00e3af40(ConstraintInfo& info)
{
    info.m_kBridgeAtoms = &m_kBridgeAtoms;
    info.m_iSolverResultCount = 0;
    info.m_iSolverElementTemporaryCount = 0;
    info.m_maxNumExternalSlaveContactPoints = 0;
    info.m_iSchemaByteSize = 16;
    info.m_usSizeOfAllAtoms = sizeof(hkpBridgeAtoms);

    int size = m_pConstraintInfo.m_iElementCount;
    info.m_iSchemaByteSize += (size * 80 + 36 + 15) & ~15;
    info.m_iSolverResultCount = size;
    info.m_iSolverElementTemporaryCount = size;
}

class hkMemoryAllocatorE3B4
{
  public:
    virtual ~hkMemoryAllocatorE3B4() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE3B4
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE3B4* m_pStreamAllocator;
    hkMemoryAllocatorE3B4& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE3B4& __cdecl FUN_00c85750();

class FUN_00e3b0a0
{
  public:
    virtual ~FUN_00e3b0a0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00e3b0a0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00e3b0a0* DestroyAndFree(unsigned int uiFlags) throw();
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}
template <class T> struct OutputSlot31
{
    T* ptr;
    __forceinline OutputSlot31()
    {}
    __forceinline OutputSlot31(T* p) : ptr(p)
    {}
    __forceinline operator T*() const
    {
        return ptr;
    }
    __forceinline T* value() const
    {
        return ptr;
    }
    __forceinline T* const& cref() const
    {
        return ptr;
    }
    __forceinline T*& ref()
    {
        return ptr;
    }
};
class hkpStiffSpringChainDataConstraintInfo
{
  public:
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkReal m_fSpringRestLength;
    int unk24;
    int unk28;
    int unk2c;
};
struct hkMemoryAllocator
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct hkMemoryRouterS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
};
void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int sizeElem) throw();
__forceinline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
struct hkInplaceIntArray32
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    __forceinline hkInplaceIntArray32()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000 | 32;
    }
    __forceinline ~hkInplaceIntArray32()
    {
        hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(&FUN_00c85750().heap());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(int));
        }
    }
    __forceinline void pushBackUnchecked(int v)
    {
        m_data[m_iElementCount] = v;
        m_iElementCount++;
    }
    __forceinline void AddBack(hkMemoryRouterS* alloc, int v)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(alloc->m_pStreamAllocator, this, sizeof(int));
        }
        new (&m_data[m_iElementCount]) int(v);
        m_iElementCount++;
    }
};
