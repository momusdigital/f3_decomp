#include "f3_common.h"
// src/havok/animation/ragdoll/penetration/hkadetectragdollpenetration.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/penetration/hkadetectragdollpenetration.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator;

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkIntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(int));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const int& fill)
    {
        reserve(n);
        int num = n - m_iElementCount;
        int* p = m_data + m_iElementCount;
        for (int i = 0; i < num; i++)
            new (p + i) int(fill);
        m_iElementCount = n;
    }
};

struct Info
{
    int unk00[7];
    int m_uiItemCount;
};

struct Desc
{
    Info* m_info;
    int unk04;
    int unk08;
};

struct RefObj
{
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct FUN_00d1fa50 : RefObj
{
    Desc m_kCreateDesc;
    int m_uiItemCount;
    hkIntArray m_aiIndexedValues;
    bool m_flag;
    FUN_00d1fa50(const Desc& d);
};

// @f3 0x009a0f60 (community match, verified in this file)
extern "C" char DAT_00e7dea4[];
void __cdecl FUN_00901e90(void* array, int count, int elementSize);
namespace Native923 {
struct Info {
    int unk00, unk04, unk08, unk0c;
    int count;
};
static __forceinline void Resize(hkIntArray* a, int n) {
    int oldCount=a->m_iElementCount;
    if(n>oldCount) {
        int cap=a->m_iCapacityState & 0x3fffffff;
        if(cap<n) {
            int newCap=cap*2;
            if(n>=newCap) newCap=n;
            FUN_00901e90(a,newCap,4);
        }
        for(int i=oldCount;i<n;++i) a->m_data[i]=1;
    }
    a->m_iElementCount=n;
}
}
// pdb: hkaDetectRagdollPenetration::hkaDetectRagdollPenetration | hkaDetectRagdollPenetration.obj | fnv360_0822_retail, uvref, high
// pdb params: setup
FUN_00d1fa50::FUN_00d1fa50(const Desc& d)
{
    m_sReferenceCount = 1;
    m_vtbl = DAT_00e7dea4;
    m_kCreateDesc = d;
    m_aiIndexedValues.init();
    int n = reinterpret_cast<Native923::Info*>(m_kCreateDesc.m_info)->count;
    m_uiItemCount = n;
    Native923::Resize(&m_aiIndexedValues,n);
    m_flag = false;
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

struct hkVector4
{
    __m128 m_vComponents;
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void SetAllComponents(float f)
    {
        m_vComponents = _mm_set_ps1(f);
    }
    void setMin4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};

class hkBool
{
  public:
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    hkBool ValidateBounds() const throw();
    void includePoint(const hkVector4& p)
    {
        m_kMinimumCorner.setMin4(m_kMinimumCorner, p);
        m_kMaximumCorner.setMax4(m_kMaximumCorner, p);
    }
};

struct hkAllocVt
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

__declspec(nothrow) void __cdecl ResizeAudioStream(void* alloc, void* arr, int sizeElem);

template <typename T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArr() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArr()
    {
        hkAllocVt& alloc = (hkAllocVt&)audio()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void AddBack(const T& t)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

struct BoxEntry
{
    hkVector4 m_kPoint;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
};

struct BoxSet
{
    int unk00, unk04, unk08, unk0c;
    BoxEntry* m_boxes;
    int unk14, unk18;
    int* m_flags;
    const hkVector4& FUN_00cda180(int idx) throw();
    __forceinline const hkVector4& GetBoxVector(int idx)
    {
        if (!(m_flags[idx] & 2))
            return m_boxes[idx].m_kPoint;
        return FUN_00cda180(idx);
    }
};

namespace fnv_00d1fe70 {

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d1fe70_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_p18;
    int m_1c;
    int m_20;

    FUN_00d1fe70_cls* FUN_00d1fe70(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00d1fe70
