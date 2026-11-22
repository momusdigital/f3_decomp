#include "f3_common.h"
// src/havok/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStorageMeshShape.h"

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

class hkVector4D4B
{
  public:
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4D4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkMemoryAllocatorD4B
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4B
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4B* m_pStreamAllocator;
    hkMemoryAllocatorD4B& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4B& __cdecl FUN_00c85750();

template <class T> __forceinline void copyD4B(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> class hkArrayD4B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD4B() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }

    __forceinline hkArrayD4B& operator=(const hkArrayD4B& a)
    {
        hkMemoryAllocatorD4B& kHeap = FUN_00c85750().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kHeap.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kHeap.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / static_cast<int>(sizeof(T));
        }
        m_iElementCount = a.m_iElementCount;
        copyD4B<T>(m_data, a.m_data, m_iElementCount);
        return *this;
    }
};

class hkpShapeD4B
{
  public:
    virtual ~hkpShapeD4B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
};

class hkpShapeContainerD4B
{
  public:
    virtual ~hkpShapeContainerD4B() throw();
};

struct hkpMeshShapeSubpartD4B
{
    int unk00;
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
    int unk30;
    int unk34;
};

class FUN_00dcd310 : public hkpShapeD4B, public hkpShapeContainerD4B
{
  public:
    FUN_00dcd310(float fRadius, int iNumBitsForSubpartIndex) throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
    int unk18;
    int unk1C;
    hkVector4D4B m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArrayD4B<hkpMeshShapeSubpartD4B> m_kSubparts;
    hkArrayD4B<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
    int unk54;
    int unk58;
    int unk5C;

    void FUN_00d4b480(const hkpMeshShapeSubpartD4B& kSubpart) throw();
};

class FUN_00d4bab0 : public FUN_00dcd310
{
  public:
    FUN_00d4bab0(const FUN_00dcd310& kOther) throw();
    virtual ~FUN_00d4bab0() throw();

    hkArrayD4B<int> m_60;
};

// @f3 0x009d69b0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace MeshMemory2109 {
extern unsigned long DAT_010f3170;
struct Heap {void FUN_008f6d90(void*,unsigned int,int) throw();void* FUN_008f6d30(unsigned int,int) throw();};
}
// pdb: hkpStorageMeshShape::hkpStorageMeshShape | hkpStorageMeshShape.obj | fnv360_0822_retail, call_dedup, high
// pdb params: mesh
FUN_00d4bab0::FUN_00d4bab0(const FUN_00dcd310& src) throw()
 :FUN_00dcd310(src.m_fSphereRadius,src.m_iNumBitsForSubpartIndex){
 const volatile float* scale=src.m_kScaling.m_vComponents.m128_f32;
 m_kScaling.m_vComponents.m128_f32[0]=scale[0];m_kScaling.m_vComponents.m128_f32[1]=scale[1];m_kScaling.m_vComponents.m128_f32[2]=scale[2];m_kScaling.m_vComponents.m128_f32[3]=scale[3];
 m_ulUserData=src.m_ulUserData;m_bDisableWelding=src.m_bDisableWelding;
 for(int i=0;i<src.m_kSubparts.m_iElementCount;++i)FUN_00d4b480(src.m_kSubparts.m_data[i]);
 int capacity=m_kWeldingInfo.m_iCapacityState&0x3fffffff;
 if(capacity<src.m_kWeldingInfo.m_iElementCount){
  if((m_kWeldingInfo.m_iCapacityState&0x80000000u)==0){MeshMemory2109::Heap* oldHeap=static_cast<MeshMemory2109::Heap*>(TlsGetValue(MeshMemory2109::DAT_010f3170));oldHeap->FUN_008f6d90(m_kWeldingInfo.m_data,capacity*2,23);}
  MeshMemory2109::Heap* heap=static_cast<MeshMemory2109::Heap*>(TlsGetValue(MeshMemory2109::DAT_010f3170));
  m_kWeldingInfo.m_data=static_cast<unsigned short*>(heap->FUN_008f6d30(src.m_kWeldingInfo.m_iElementCount*2,23));
  m_kWeldingInfo.m_iCapacityState=(m_kWeldingInfo.m_iCapacityState&0x40000000)|src.m_kWeldingInfo.m_iElementCount;
 }
 m_kWeldingInfo.m_iElementCount=src.m_kWeldingInfo.m_iElementCount;
 int count=m_kWeldingInfo.m_iElementCount;unsigned short* output=m_kWeldingInfo.m_data;const unsigned short* input=src.m_kWeldingInfo.m_data;
 for(int i=0;i<count;++i)output[i]=input[i];
 m_eWeldingType=src.m_eWeldingType;
}


namespace fnv_00d4bc00 {
struct hkAllocatorD4BC
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD4BC
{
    void* m_apvUnk00[4];
    hkAllocatorD4BC* m_pkHeap;
    hkAllocatorD4BC& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD4BC* __cdecl FUN_00c85750() throw();

template <typename T> struct hkArrayD4BC
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(hkAllocatorD4BC& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD4BC() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};

class hkReferencedObjectD4BC
{
  public:
    virtual ~hkReferencedObjectD4BC() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00d4bc00 : public hkReferencedObjectD4BC
{
  public:
    hkArrayD4BC<hkReal> m_kVertices;
    hkArrayD4BC<hkUint16> m_kIndices16;
    hkArrayD4BC<hkUint32> m_kIndices32;
    hkArrayD4BC<hkUint8> m_kMaterialIndices8;
    hkArrayD4BC<hkUint32> m_kMaterials;
    hkArrayD4BC<hkUint16> m_kMaterialIndices16;

    virtual ~FUN_00d4bc00() throw();
};

// Destructor that releases the six hkArray members of the object via their own destructors.
// @fnv 0x00d4bc00
FUN_00d4bc00::~FUN_00d4bc00() throw()
{}
}  // namespace fnv_00d4bc00

namespace fnv_00d4bd30 {
class hkMemoryAllocatorD4BD
{
  public:
    virtual ~hkMemoryAllocatorD4BD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4BD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4BD* m_pStreamAllocator;
    hkMemoryAllocatorD4BD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4BD& __cdecl FUN_00c85750();

class FUN_00d4bc00
{
  public:
    virtual ~FUN_00d4bc00() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d4bc00*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d4bc00* DestroyAndFree(unsigned int uiFlags) throw();
};

}  // namespace fnv_00d4bd30

namespace fnv_00d4be00 {
void* __cdecl FUN_00c85750(void);

}  // namespace fnv_00d4be00

struct hkAllocatorD4B4
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4B4
{
    int unk00, unk04, unk08, unk0C;
    hkAllocatorD4B4* m_pkHeap;
    hkAllocatorD4B4& heap()
    {
        return *m_pkHeap;
    }
};

namespace hkRouterD4B4 {
extern "C" hkMemoryRouterD4B4* __cdecl FUN_00c85750() throw();
}

template <typename T> struct hkArrayD4B4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void _clearAndDeallocate(hkAllocatorD4B4& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD4B4() throw()
    {
        _clearAndDeallocate(hkRouterD4B4::FUN_00c85750()->heap());
    }
};

class hkRefD4B4
{
  public:
    void FUN_00c905b0() throw();
};

class hkBaseAD4B4
{
  public:
    virtual ~hkBaseAD4B4() throw();
    int unk04, unk08, unk0C;
};

class hkBaseBD4B4
{
  public:
    virtual void V0() throw();
};

class FUN_00d4bd60 : public hkBaseAD4B4, public hkBaseBD4B4
{
  public:
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;

    virtual ~FUN_00d4bd60() throw();
};

class FUN_00d4b400 : public FUN_00d4bd60
{
  public:
    hkArrayD4B4<hkRefD4B4*> m_children;

    virtual ~FUN_00d4b400() throw();
    virtual void V0() throw();
};

// Destructor that calls FUN_00c905b0 on each element of m_children.
// @f3 0x009d6380 (community match, verified in this file)
namespace Native925 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void*,unsigned int,int) throw(); };
struct Ref {
    virtual ~Ref();
    unsigned short memory;
    short refs;
    unsigned int Count() const { return refs; }
    void Release() {
        if(memory) {
            --refs;
            if((unsigned short)Count()==0) delete this;
        }
    }
};
}
template <> hkArrayD4B4<hkRefD4B4*>::~hkArrayD4B4() throw()
{
    if((m_iCapacityState & 0x80000000)==0) {
        unsigned int capacity=m_iCapacityState & 0x3fffffff;
        Native925::Heap* heap=static_cast<Native925::Heap*>(Native925::DAT_00d9b080(Native925::DAT_010f3170));
        heap->FUN_008f6d90(m_data,capacity*4,23);
    }
}
// pdb: hkpStorageMeshShape::~hkpStorageMeshShape | hkpStorageMeshShape.obj | fnv360_0822_retail, call_seq, high
FUN_00d4b400::~FUN_00d4b400() throw()
{
    for(int i=0;i<m_children.m_iElementCount;++i)
        reinterpret_cast<Native925::Ref*>(m_children.m_data[i])->Release();
}


class hkRefObjD4BB
{
  public:
    hkRefObjD4BB()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjD4BB();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class hkArrayD4BB
{
  public:
    hkArrayD4BB() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual inherited through a second base.
struct PrimaryBase
{
    virtual void FUN_00d4bdf0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d4bdf0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d4bdf0
    virtual void FUN_00d4bdf0();
};

Derived::Derived()
{}

extern "C" void _ReadWriteBarrier();

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct Alloc480
{
    virtual void V0() throw();
    virtual void* V1(int) throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
void __cdecl FUN_00c908c0(void* heap, void* arr, int newCap, int elemSize);
struct SubpartFlags480
{
    int vertices, stride, numVertices, indices;
    unsigned char indexType, materialIndexType;
    unsigned short flags;
};

static __declspec(noinline) int __cdecl FUN_00d4b390(int a, int n)
{
    switch (a)
    {
    case 1:
        return n + 2;
    case 2:
        return 2 * n + 1;
    default:
        return 3 * n;
    }
}

struct Trivial480
{
};
struct Complex480
{
};
struct CopyOps480
{
    template <class T> static __forceinline void initialize(T*, int, Trivial480)
    {}
    template <class T> static __forceinline void fill(T* dest, int count, const T& value, Trivial480)
    {
        for (int j = 0; j < count; ++j)
            dest[j] = value;
    }
    template <class T> static __forceinline void fill(T* dest, int count, const T& value, Complex480)
    {
        for (int j = 0; j < count; ++j)
        {
            T* slot = dest + j;
            __assume(slot != 0);
            new (slot) T(value);
        }
    }
};
struct HeapPolicy480
{
    __forceinline Alloc480& get(const void*)
    {
        return (Alloc480&)FUN_00c85750().heap();
    }
};
template <class T> struct CoreArray480
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* data480()
    {
        return m_data;
    }
    T& back480()
    {
        return m_data[m_iElementCount - 1];
    }
    T* last480()
    {
        return m_data + m_iElementCount - 1;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int n)
    {
        return m_data[n];
    }
    const T& operator[](int n) const
    {
        return m_data[n];
    }
    __forceinline void reserveHeap480(Alloc480& heap, int needed)
    {
        int capacity = getCapacity();
        if (capacity < needed)
        {
            int doubled = 2 * capacity;
            int result = needed < doubled ? doubled : needed;
            FUN_00c908c0(&heap, this, result, sizeof(T));
        }
    }
    __forceinline T* appendHeap480(Alloc480& heap, int count)
    {
        int oldSize = m_iElementCount;
        reserveHeap480(heap, m_iElementCount + count);
        CopyOps480::initialize(m_data + m_iElementCount, count, Trivial480());
        m_iElementCount += count;
        return m_data + oldSize;
    }
    __forceinline void pushHeap480(Alloc480& heap, const T& value)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
        CopyOps480::fill(m_data + m_iElementCount, 1, value, Trivial480());
        m_iElementCount++;
    }
};
template <class T> struct Arr480 : CoreArray480<T>
{
    __forceinline void growIfFull()
    {
        Alloc480& heap = HeapPolicy480().get(this);
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
    }
    __forceinline void growIfFull2()
    {
        growIfFull();
    }
    __forceinline void AddBack(const T& value)
    {
        pushHeap480(HeapPolicy480().get(this), value);
    }
    __forceinline void pushBack2(const T& value)
    {
        AddBack(value);
    }
    __forceinline T* appendRange(int count)
    {
        return appendHeap480(HeapPolicy480().get(this), count);
    }
    __forceinline T* appendRange2(int count)
    {
        return appendRange(count);
    }
    __forceinline T* appendRangeP(int count)
    {
        return appendRange(count);
    }
};
template <class Arr> __forceinline void GrowIfFull480(Arr& arr, int elemSize)
{
    hkMemoryRouterD4B& router = FUN_00c85750();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router.m_pStreamAllocator, &arr, elemSize);
}
template <class Arr> __forceinline void ReserveCount480(Arr& arr, int count, int elemSize)
{
    Alloc480* heap = (Alloc480*)&FUN_00c85750().heap();
    int cap = arr.m_iCapacityState & 0x3fffffff;
    int need = arr.m_iElementCount + count;
    if (cap < need)
    {
        int newCap = cap + cap;
        if (newCap < need)
            newCap = need;
        FUN_00c908c0(heap, &arr, newCap, elemSize);
    }
}

__forceinline hkpMeshShapeSubpartD4B* ExpandInit480(hkArrayD4B<hkpMeshShapeSubpartD4B>& arr)
{
    GrowIfFull480(arr, 0x38);
    hkpMeshShapeSubpartD4B* e = &arr.m_data[arr.m_iElementCount];
    if (e)
    {
        ((SubpartFlags480*)e)->materialIndexType = 1;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk30 = 1;
        e->unk28 = 0;
        e->unk20 = 0;
        e->unk34 = -1;
        e->unk18 = 0;
    }
    return &arr.m_data[arr.m_iElementCount++];
}

// Copies a mesh subpart's vertex, index, material, and extra data into owned storage arrays and updates the subpart's pointers and strides.
// @f3 0x009d6410 (community match, verified in this file)
extern "C" void _ReadWriteBarrier(void);
namespace storage_mesh_subpart {
extern unsigned int DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
void FUN_00901f10(void*,int);
void FUN_00901e90(void*,int,int);
struct MemoryManager { void* FUN_008f6d30(int,int); };
extern unsigned int DAT_01092a50;
extern unsigned int DAT_00e7fd3c;
template<class T> struct Array {
    T* data; int count; unsigned int capacityAndFlags;
    __forceinline Array() : data(0),count(0),capacityAndFlags(0x80000000u) {}
    T& expandOne() { if(count==int(capacityAndFlags&0x3fffffffu)) FUN_00901f10(this,sizeof(T)); return data[count++]; }
    void pushBack(const T& value) { if(count==int(capacityAndFlags&0x3fffffffu)) FUN_00901f10(this,sizeof(T)); data[count]=value; ++count; }
    T* expandBy(int added) {
        int old=count; int total=old+added; int capacity=capacityAndFlags&0x3fffffffu;
        if(capacity<total) { int grown=capacity*2; if(total>=grown)grown=total; FUN_00901e90(this,grown,sizeof(T)); }
        count=total; return data+old;
    }
    T& back() { return data[count-1]; }
};
struct SubpartStorage {
    const void* vtable;
    unsigned short memorySizeAndFlags,referenceCount;
    Array<float> vertices;
    Array<unsigned short> indices16;
    Array<unsigned int> indices32;
    Array<unsigned char> materialIndices8;
    Array<unsigned int> materials;
    Array<unsigned short> materialIndices16;
    __forceinline SubpartStorage() : vtable(&DAT_00e7fd3c), referenceCount(1) {}

};
struct TriangleSubpart {
    const float* vertexBase;
    int vertexStride,numVertices;
    const void* indexBase;
    signed char indexType,materialIndexType;
    unsigned short unk12;
    int indexStride,triangleOffset,numTriangles;
    const void* materialIndexBase;
    int materialIndexStride;
    const void* materialBase;
    int materialStride,numMaterials;
    unsigned int userData;
};
static __declspec(noinline) int FUN_009d6300(int triangles,int indicesPerTriangle) {
    switch(indicesPerTriangle) { case 1: return triangles+2; case 2: return triangles*2+1; default: return triangles*3; }
}
}
using namespace storage_mesh_subpart;
// pdb: hkpStorageMeshShape::addSubpart | hkpStorageMeshShape.obj | fnv360_0822_retail, callee_sim, low
// pdb params: partIn
void FUN_00dcd310::FUN_00d4b480(const hkpMeshShapeSubpartD4B& sourceRaw) throw() {
    const TriangleSubpart& source=reinterpret_cast<const TriangleSubpart&>(sourceRaw);
    Array<TriangleSubpart>& parts=*reinterpret_cast<Array<TriangleSubpart>*>(&m_kSubparts);
    TriangleSubpart& part=parts.expandOne();
    MemoryManager* allocator=static_cast<MemoryManager*>(DAT_00d9b080(DAT_010f3170));
    SubpartStorage* storage=static_cast<SubpartStorage*>(allocator->FUN_008f6d30(sizeof(SubpartStorage),37));
    storage->memorySizeAndFlags=sizeof(SubpartStorage);
    __assume(storage!=0);
    storage=::new(storage) SubpartStorage;
    Array<SubpartStorage*>& storages=*reinterpret_cast<Array<SubpartStorage*>*>(&static_cast<FUN_00d4bab0*>(this)->m_60);
    storages.pushBack(storage);
    _ReadWriteBarrier();
    storage=storages.back();
    float* vertex=storage->vertices.expandBy(source.numVertices*3);
    const float* input=source.vertexBase;
    for(int i=0;i<source.numVertices;++i) {
        vertex[0]=input[0];vertex[1]=input[1];vertex[2]=input[2];
        vertex+=3; input=reinterpret_cast<const float*>(reinterpret_cast<const char*>(input)+source.vertexStride);
    }
    part.vertexBase=storage->vertices.data;part.vertexStride=12;part.numVertices=source.numVertices;
    void* indices;
    if(source.indexType==1) {
        int stride=int(static_cast<unsigned int>(source.indexStride)>>1);
        part.indexStride=(stride<=2?stride:3)*2;
        unsigned short* output=storage->indices16.expandBy(FUN_009d6300(source.numTriangles,stride));
        indices=output;const unsigned short* input=static_cast<const unsigned short*>(source.indexBase);
        for(int i=0;i<source.numTriangles;++i) {
            output[0]=input[0];output[1]=input[1];output[2]=input[2];
            output=reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(output)+part.indexStride);
            input=reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(input)+source.indexStride);
        }
    } else {
        int stride=int(static_cast<unsigned int>(source.indexStride)>>2);
        part.indexStride=(stride<=2?stride:3)*4;
        unsigned int* output=storage->indices32.expandBy(FUN_009d6300(source.numTriangles,stride));
        indices=output;const unsigned int* input=static_cast<const unsigned int*>(source.indexBase);
        for(int i=0;i<source.numTriangles;++i) {
            output[0]=input[0];output[1]=input[1];output[2]=input[2];
            output=reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(output)+part.indexStride);
            input=reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(input)+source.indexStride);
        }
    }
    part.indexType=source.indexType;part.numTriangles=source.numTriangles;part.triangleOffset=source.triangleOffset;part.indexBase=indices;part.materialIndexType=source.materialIndexType;
    if(source.materialIndexBase) {
        if(source.materialIndexType==1) {
            if(source.materialIndexStride==0) {
                storage->materialIndices8.pushBack(*static_cast<const unsigned char*>(source.materialIndexBase));
                part.materialIndexBase=&storage->materialIndices8.back();
            } else {
                unsigned char* output=storage->materialIndices8.expandBy(source.numTriangles);
                part.materialIndexBase=output;
                const unsigned char* input=static_cast<const unsigned char*>(source.materialIndexBase);
                for(int i=0;i<source.numTriangles;++i) { output[i]=*input;input+=source.materialIndexStride; }
            }
        } else {
            if(source.materialIndexStride==0) {
                storage->materialIndices16.pushBack(*static_cast<const unsigned short*>(source.materialIndexBase));
                part.materialIndexBase=&storage->materialIndices16.back();
            } else {
                unsigned short* output=storage->materialIndices16.expandBy(source.numTriangles);
                part.materialIndexBase=output;
                const unsigned short* input=static_cast<const unsigned short*>(source.materialIndexBase);
                for(int i=0;i<source.numTriangles;++i) { output[i]=*input;input=reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(input)+source.materialIndexStride); }
            }
        }
        part.materialIndexStride=source.materialIndexStride;
        if(part.materialIndexStride) { switch(part.materialIndexType) { case 1:part.materialIndexStride=1;break;case 2:part.materialIndexStride=2;break; } }
    } else { part.materialIndexBase=0;part.materialIndexStride=0; }
    if(part.materialIndexBase) {
        if(source.materialStride==0) {
            storage->materials.pushBack(*static_cast<const unsigned int*>(source.materialBase));
            part.materialStride=0;part.numMaterials=1;
        } else {
            unsigned int* output=storage->materials.expandBy(source.numMaterials);
            const unsigned int* input=static_cast<const unsigned int*>(source.materialBase);
            for(int i=0;i<source.numMaterials;++i) { output[i]=*input;input=reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(input)+source.materialStride); }
            part.materialStride=4;part.numMaterials=source.numMaterials;
        }
        part.materialBase=storage->materials.data;
    } else { part.numMaterials=1;part.materialBase=&DAT_01092a50;part.materialStride=0;part.materialIndexBase=&DAT_01092a50; }
    part.userData=source.userData;
}


namespace fnv_00d4ba30 {
struct FinishingFlag
{
    int m_bFinishing;
};

template <class T> struct hkArrayD4B
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* begin()
    {
        return m_data;
    }
};

class hkpShapeContainerD4B
{
  public:
    virtual ~hkpShapeContainerD4B();
};

struct hkpMeshSubpartD4B
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    unsigned char m_ucIndexStridingType;
    unsigned char m_iMaterialIndexType;
    short unk12;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iNumTriangles;
    int m_iIndexStriding;
    int m_iTriangleOffset;
};

class hkpShapeD4B
{
  public:
    virtual ~hkpShapeD4B();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};

class FUN_00dcd380 : public hkpShapeD4B, public hkpShapeContainerD4B
{
  public:
    virtual ~FUN_00dcd380();
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    hkArrayD4B<hkpMeshSubpartD4B> m_kSubparts;

    FUN_00dcd380(FinishingFlag flag);
};

struct hkpSubpartStorageD4B
{
    void* vtbl;
    int m_memSizeAndRefCount;
    hkArrayD4B<float> m_kVertices;
    hkArrayD4B<unsigned short> m_kIndices16;
    hkArrayD4B<unsigned int> m_kIndices32;
    hkArrayD4B<unsigned char> m_kMaterialIndices8;
    hkArrayD4B<unsigned int> m_kMaterials;
    hkArrayD4B<unsigned short> m_kMaterialIndices16;
};

class FUN_00d4ba30 : public FUN_00dcd380
{
  public:
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkArrayD4B<hkpSubpartStorageD4B*> m_kStorage;

    FUN_00d4ba30(FinishingFlag flag);
    virtual ~FUN_00d4ba30();
};

// Constructor: calls the base constructor and, if flag.m_bFinishing is set, points each subpart's data fields at the begin of the matching storage arrays.
// @fnv 0x00d4ba30
// pdb: hkpStorageMeshShape::hkpStorageMeshShape | hkpStorageMeshShape.obj | fnv360_0822_retail, objrun, high
// pdb params: flag
FUN_00d4ba30::FUN_00d4ba30(FinishingFlag flag) : FUN_00dcd380(flag)
{
    if (flag.m_bFinishing)
    {
        for (int i = 0; i < m_kSubparts.GetLogicalSize(); i++)
        {
            hkpMeshSubpartD4B& part = m_kSubparts[i];
            hkpSubpartStorageD4B& storage = *m_kStorage[i];
            part.m_pMaterialIndexBase = storage.m_kVertices.begin();
            if (part.m_ucIndexStridingType == 1)
                part.m_pMaterialDataBase = storage.m_kIndices16.begin();
            else
                part.m_pMaterialDataBase = storage.m_kIndices32.begin();
            if (part.m_iMaterialIndexType == 1)
                part.m_pVertexBase = storage.m_kMaterialIndices8.begin();
            else
                part.m_pVertexBase = storage.m_kMaterialIndices16.begin();
            part.m_pIndexBase = storage.m_kMaterials.begin();
        }
    }
}
}  // namespace fnv_00d4ba30

namespace fnv_00d4bd60 {
class hkMemoryAllocatorD4BD
{
  public:
    virtual ~hkMemoryAllocatorD4BD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4BD
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD4BD* m_pStreamAllocator;

    hkMemoryAllocatorD4BD& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD4BD& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayD4BD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD4BD() throw()
    {
        hkMemoryAllocatorD4BD& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD4BD {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShape : public hkReferencedObject
{
  public:
    unsigned long m_ulUserData;
    int m_type;
};

class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer() throw()
    {}
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
  public:
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct TriangleD4BD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34;
};
}

class FUN_00d4bd60
{
  public:
    ~FUN_00d4bd60();

    hkD4BD::hkpShapeCollection m_kCollection;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    hkArrayD4BD<hkD4BD::TriangleD4BD> m_kTriangles;
    hkArrayD4BD<unsigned short> m_kMaterialIndices;
};

// Destructor for a triangle collection object that owns a shape collection, a triangle array, and a material index array.
// @fnv 0x00d4bd60
FUN_00d4bd60::~FUN_00d4bd60()
{}
}  // namespace fnv_00d4bd60

namespace fnv_00dcebd0 {
struct FUN_00dcebd0_Allocator
{
    virtual ~FUN_00dcebd0_Allocator();
    virtual void unknown04();
    virtual void unknown08();
    virtual void* AllocateBufferWithSize(int& requestedBytes);
    virtual void ReturnMemory(void* buffer, int byteCount);
};
struct FUN_00dcebd0_Router
{
    void* m_unknown00;
    void* m_unknown04;
    void* m_unknown08;
    void* m_unknown0c;
    FUN_00dcebd0_Allocator* m_pThreadAllocator;
};
FUN_00dcebd0_Router* __cdecl FUN_00c85750();

}  // namespace fnv_00dcebd0
