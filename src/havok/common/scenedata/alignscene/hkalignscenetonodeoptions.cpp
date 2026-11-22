#include "f3_common.h"
// src/havok/common/scenedata/alignscene/hkalignscenetonodeoptions.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/alignscene/hkalignscenetonodeoptions.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkAlignSceneToNodeOptions.h"

struct Inner
{
    void Run();
};

struct FUN_00e4a540_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Inner* m_14;
    void FUN_00e4a540();
};

// @fnv 0x00e4a540
// pdb: BGSSaveLoadGame::QueueSubBuffer | BGSSaveLoadGame.obj | fnv360_0721_retail, call_seq, low
// pdb params: aeType, apLoadFormBuffer, apParentForm
void FUN_00e4a540_cls::FUN_00e4a540()
{
    m_14->Run();
}

class hkMemoryAllocatorE4AF
{
  public:
    virtual ~hkMemoryAllocatorE4AF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE4AF
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE4AF* m_pStreamAllocator;
    hkMemoryAllocatorE4AF& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE4AF& __cdecl FUN_00c85750();

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        FUN_00cb0c00();
    }
};

class hkReferencedObjectE4AF
{
  public:
    virtual ~hkReferencedObjectE4AF() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectE4AF*>(p)->m_usMemSizeAndFlags);
    }
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps();
struct HeapAllocE4
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct RouterE4
{
    int unk00, unk04, unk08, unk0c;
    HeapAllocE4* m_pStreamAllocator;
    HeapAllocE4& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct Vec4E4
{
    __m128 m_vComponents;
    __forceinline Vec4E4& operator=(const Vec4E4& v) throw()
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setZero4() throw()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i) throw()
    {
        return ((float*)&m_vComponents)[i];
    }
};
struct Matrix4E4
{
    Vec4E4 m_kColumn0, m_kColumn1, m_kColumn2, m_kColumn3;
    __forceinline void setIdentity() throw()
    {
        Vec4E4 zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn3 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_kColumn3(3) = 1.0f;
    }
    void FUN_00de8e50(const Matrix4E4& m) throw();
};
template <class T, int N> struct InplaceArrE4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];
    __forceinline InplaceArrE4() throw()
    {
        static_cast<T* volatile&>(m_data) = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = N | 0x80000000;
    }
    __forceinline int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline void release() throw()
    {
        HeapAllocE4& h = ((RouterE4*)&FUN_00c85750())->heap();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            h.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    __forceinline ~InplaceArrE4() throw()
    {
        release();
    }
};
