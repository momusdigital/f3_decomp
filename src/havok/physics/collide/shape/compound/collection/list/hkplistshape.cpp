#include "f3_common.h"
// src/havok/physics/collide/shape/compound/collection/list/hkplistshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/list/hkplistshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpListShape.h"

// hkpListShape::ChildInfo (New Vegas Xbox 360 PDB layout, 16 bytes)
struct ListShapeChildInfoF3
{
    const void* m_shape;
    unsigned int m_collisionFilterInfo;
    int m_shapeSize;
    int m_numChildShapes;
};

// hkpListShape: m_childInfo (an hkArray<ChildInfo>) at +0x18
struct hkPListShape
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    ListShapeChildInfoF3* m_childInfo;  // +0x18 m_childInfo.m_data
    void __thiscall SetChildShape(int index, void* shape);
};
// @fnv 0x00cf50a0
// pdb: hkpListShape::setCollisionFilterInfo | hkpListShape.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: index, filterInfo
void __thiscall hkPListShape::SetChildShape(int index, void* shape)
{
    m_childInfo[index].m_collisionFilterInfo = (unsigned int)shape;
}

// The hkpShapeContainer subobject of hkpListShape (at +0x10): +8 is hkpListShape::m_childInfo.m_data.
struct FUN_00cf5070_class
{
    int unk00, unk04;
    ListShapeChildInfoF3* m_childInfo;
    void* GetShapeAt(int index, void* buffer);
};

// @fnv 0x00cf5070
// pdb: hkpListShape::getCollisionFilterInfo | hkpListShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpListShape::getChildShape)
// pdb params: key
void* FUN_00cf5070_class::GetShapeAt(int index, void* buffer)
{
    return (void*)m_childInfo[index].m_shape;
}

// The hkpShapeContainer subobject of hkpListShape, as above.
struct hkPListShape2
{
    int unk00, unk04;
    ListShapeChildInfoF3* m_childInfo;
    int __thiscall GetElementAt(int index);
};

// @fnv 0x00cf5080
// pdb: hkpListShape::getCollisionFilterInfo | hkpListShape.obj | tesv_win, objrun_open, low
int hkPListShape2::GetElementAt(int index)
{
    return (int)m_childInfo[index].m_collisionFilterInfo;
}

struct __declspec(align(16)) BufAligned32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkClassCF54;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayCF54
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

class hkStatisticsCollectorCF54
{
  public:
    virtual ~hkStatisticsCollectorCF54() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayCF54<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

struct hkChildInfoCF54
{
    const void* m_pCollisionShape;
    int m_04;
    int m_08;
    int m_0c;
};

class hkpShapeCF54
{
  public:
    void FUN_00d213e0(hkStatisticsCollectorCF54* pkCollector, const hkClassCF54* pkClass) const throw();
};

class hkObjCF54 : public hkpShapeCF54
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkArrayCF54<hkChildInfoCF54> m_kChildInfoList;

    void AddChildObjectsToCollector(hkStatisticsCollectorCF54* pkCollector) const throw();
};

// @f3 0x0097da20 (community match, verified in this file)
namespace n97da20 {
class Collector {
  public:
    virtual ~Collector();
    virtual void beginObject(const char* name, int type, const void* object);
    virtual void addChunk(const char* name, int type, const void* data, int used, int allocated);
    virtual void addChildObject(const char* name, int type, const void* object);
    virtual void v4();
    virtual void v5();
    virtual void endObject();
};
}

// pdb: hkpListShape::getAabbImpl | hkpListShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: localToWorld, tolerance, out
void hkObjCF54::AddChildObjectsToCollector(hkStatisticsCollectorCF54* pkCollector) const throw()
{
    n97da20::Collector* c = (n97da20::Collector*)pkCollector;
    c->beginObject("ListShape", 1, this);
    if ((m_kChildInfoList.m_iCapacityState & 0x80000000) == 0)
        c->addChunk("ChildPtrs", 1, m_kChildInfoList.m_data,
            m_kChildInfoList.m_iElementCount * sizeof(hkChildInfoCF54),
            m_kChildInfoList.getCapacity() * sizeof(hkChildInfoCF54));
    for (int i = 0; i < m_kChildInfoList.m_iElementCount; ++i)
        c->addChildObject("Child", 1, m_kChildInfoList.m_data[i].m_pCollisionShape);
    c->endObject();
}


struct hkFinishFlagCF56
{
    int m_bFinishing;
};

class hkLevel0CF56
{
  public:
    virtual ~hkLevel0CF56() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int m_type;

    hkLevel0CF56(hkFinishFlagCF56 flag)
    {
        if (flag.m_bFinishing)
            m_type = 0;
    }
};

class hkIfaceCF56
{
  public:
    virtual void i0() = 0;
    char unk14;
    char m_15;
};

class hkLevel1CF56 : public hkLevel0CF56, public hkIfaceCF56
{
  public:
    hkLevel1CF56(hkFinishFlagCF56 flag) : hkLevel0CF56(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_15 = 3;
        }
    }
};

// @f3 0x006139a0 (community match, verified in this file)
namespace Clear98 {
struct Value {unsigned unk00,unk04;unsigned state;};
struct Link {unsigned unk00,unk04,unk08;Value* value;};
struct Object {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 Link* link;
};
struct Triple {unsigned unk00,unk04,unk08,unk0c;Object* first;Object* second;Object* third;};
struct Node {Triple* item;Node* next;};
extern Node DAT_01075804;
}
// pdb: BGSTerrainChunk::ResetMultiBoundResults | BGSTerrainChunk.obj | fnv360_0822_retail, call_seq, low
void __cdecl FUN_006139a0(){
 using namespace Clear98;
 for(Node* node=&DAT_01075804;node;node=node->next){
  Triple* item=node->item;
  if(item){
   if(item->first)item->first->link->value->state=0;
   if(item->second)item->second->link->value->state=0;
   if(item->third)item->third->link->value->state=0;
  }
 }
}


struct hkListShapeCF58
{
    int unk00;
    int unk04;
    void* m_kChildInfoList;
    int m_childInfoSize;
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
    int unk38;
    int unk3C;
    unsigned int m_uiChildEnabledFlags[8];

    unsigned int isChildEnabled(unsigned int index) const
    {
        if (index < 256)
            return m_uiChildEnabledFlags[index >> 5] & (1 << (index & 31));
        return 1;
    }

    int FindNextEnabledChild(int oldKey) const;
};

struct FnvCpu_FUN_00cf5890_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cf5890_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cf5890_CpuAllocator* allocator;
};
FnvCpu_FUN_00cf5890_CpuAllocatorHolder* __cdecl FUN_00c85750();

class hkMemoryAllocatorCF56;

struct hkMemoryRouterCF56
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorCF56* m_pStreamAllocator;
    hkMemoryAllocatorCF56& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterCF56& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorCF56& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayCF56
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayCF56() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocatorCF56& kAlloc = fnvc_adapt::FUN_00c85750().heap();
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
};

struct Stream_cf50c0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual int CalcSizeForSpu(const bool& input, int iSize) const;
};
struct Entry_cf50c0
{
    const Stream_cf50c0* m_pCollisionShape;
    int m_uiFilterInfo;
    int m_iShapeKey;
    int m_iChildShapeCount;
};
template <class T> struct ArrCF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct ListShapeCF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ArrCF<Entry_cf50c0> m_kChildInfoList;
    int FUN_00cf50c0(const bool& input, int spuBufferSizeLeft);
};
// @fnv 0x00cf50c0
int ListShapeCF::FUN_00cf50c0(const bool& input, int spuBufferSizeLeft)
{
    if (input && m_kChildInfoList.GetLogicalSize() > 252)
        return -1;
    if (m_kChildInfoList.GetLogicalSize() >= 4095)
        return -1;
    for (int i = 0; i < m_kChildInfoList.GetLogicalSize(); i++)
    {
        m_kChildInfoList[i].m_iShapeKey = m_kChildInfoList[i].m_pCollisionShape->CalcSizeForSpu(input, 256);
        m_kChildInfoList[i].m_iChildShapeCount = m_kChildInfoList.GetLogicalSize();
        if (m_kChildInfoList[i].m_iShapeKey == -1)
            return -1;
    }
    return 0x70;
}

struct ShapeAlloc;
struct ShapeRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ShapeAlloc* m_pStreamAllocator;
    ShapeAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(void* allocator, void* array, int capacity, int elementSize);

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_cmple_ps(__m128 a, __m128 b);
    int _mm_movemask_ps(__m128 a);
    __m128 _mm_load_ps1(const float* p);
    __m128 _mm_xor_ps(__m128 a, __m128 b);
    __m128 _mm_min_ps(__m128 a, __m128 b);
    __m128 _mm_max_ps(__m128 a, __m128 b);
}

struct hkVector4q
{
    __m128 m_vComponents;

    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(const float& x)
    {
        m_vComponents = _mm_load_ps1(&x);
    }
    __forceinline void setNeg4(const hkVector4q& v);
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline int compareLessThanEqual4(const hkVector4q& v) const
    {
        return _mm_movemask_ps(_mm_cmple_ps(m_vComponents, v.m_vComponents));
    }
};

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <string.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010c41f8[];

struct S00cf5140_Bool
{
    char m_cBooleanValue;
    S00cf5140_Bool()
    {}
    S00cf5140_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S00cf5140_Input
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    const struct S00cf5140_Filter* m_pRayShapeCollectionFilter;
};

struct S00cf5140_Output
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

struct S00cf5140_Container
{
    int unk00;
};

struct S00cf5140_Filter
{
    virtual S00cf5140_Bool IsCollisionEnabled(const S00cf5140_Input& aInput, const hkpShape& shape,
                                              const S00cf5140_Container& container, unsigned int aKey) const;
};

struct S00cf5140_ShapeIface
{
    virtual void vt00();
    virtual void vt01();
    virtual void vt02();
    virtual void vt03();
    virtual void vt04();
    virtual void vt05();
    virtual void vt06();
    virtual void vt07();
    virtual S00cf5140_Bool RayCast(const S00cf5140_Input& input, S00cf5140_Output& output) const;
};

class hkpListShapeChildInfo
{
  public:
    const S00cf5140_ShapeIface* m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0c;
};

struct S00cf5140_Stream
{
    int unk0;
    char* m_curr;
    int unk8;
    char* m_kRayEnd;

    void timerBegin(const char* name)
    {
        char* p = m_curr;
        if (p < m_kRayEnd)
        {
            *(const char**)p = name;
            _ReadWriteBarrier();
            unsigned int tb = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&tb;
            if (0)
                memmove(&tb, &tb, 4);
            p += 12;
            m_curr = p;
        }
    }

    void timerEnd()
    {
        char* p = m_curr;
        if (p < m_kRayEnd)
        {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            unsigned int te = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&te;
            if (0)
                memmove(&te, &te, 4);
            p += 12;
            m_curr = p;
        }
    }
};

struct S00cf5140_Obj : public hkpListShape
{
    unsigned int isChildEnabled(unsigned int i) const
    {
        if (i < 0x100)
        {
            return m_uiChildEnabledFlags[i >> 5] & (1 << (i & 0x1f));
        }
        return 1;
    }

    S00cf5140_Bool FUN_00cf5140(const S00cf5140_Input& input, S00cf5140_Output& results) const;
};

// Performs a ray cast against all enabled child shapes of this list shape, recording the hit child index in the output and returning whether any child was hit.
// @f3 0x0097ae60 (community match, verified in this file)
struct S00cf5140_ContainerVtbl
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10();
    virtual void c14();
    virtual unsigned int isChildEnabled(unsigned int index) const;
};

// pdb: hkpListShape::castRayWithCollectorImpl | hkpListShape.obj | fnv360_0822_retail, objrun, low
// pdb params: input, cdBody, collector
S00cf5140_Bool S00cf5140_Obj::FUN_00cf5140(const S00cf5140_Input& input, S00cf5140_Output& results) const
{
    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerBegin("TtrcList");

    results.m_uiShapeKeyIndex++;
    int hitChild = -1;

    if (!input.m_pRayShapeCollectionFilter)
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (((S00cf5140_ContainerVtbl*)((char*)this + 0x10))->isChildEnabled(i))
            {
                const S00cf5140_ShapeIface* child = m_kChildInfoList.m_data[i].m_pCollisionShape;
                S00cf5140_Bool hit = child->RayCast(input, results);
                if (hit)
                {
                    hitChild = i;
                }
            }
        }
    }
    else
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (((S00cf5140_ContainerVtbl*)((char*)this + 0x10))->isChildEnabled(i))
            {
                if (input.m_pRayShapeCollectionFilter->IsCollisionEnabled(
                        input, *this, *(const S00cf5140_Container*)((char*)this + 0x10), i))
                {
                    const S00cf5140_ShapeIface* child = m_kChildInfoList.m_data[i].m_pCollisionShape;
                    S00cf5140_Bool hit = child->RayCast(input, results);
                    if (hit)
                    {
                        hitChild = i;
                    }
                }
            }
        }
    }

    results.m_uiShapeKeyIndex--;
    if (hitChild != -1)
    {
        results.m_uiShapeKeys[results.m_uiShapeKeyIndex] = hitChild;
    }

    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerEnd();
    return hitChild != -1;
}


// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00cf5820();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00cf5820();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cf5820
    virtual void FUN_00cf5820();
};

Derived::Derived()
{}

namespace fnv_00cf5750 {
class hkMemoryAllocatorCF5
{
  public:
    virtual ~hkMemoryAllocatorCF5();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterCF5
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorCF5* m_pTemp;
    hkMemoryAllocatorCF5* m_pStreamAllocator;
    hkMemoryAllocatorCF5& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterCF5* __cdecl FUN_00c85750() throw();

template <class T> class hkArrayCF5
{
  public:
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
    ~hkArrayCF5() throw()
    {
        hkMemoryAllocatorCF5& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseObjectCF5
{
  public:
    virtual ~hkBaseObjectCF5()
    {}
};

class hkpShapeContainerCF5
{
  public:
    virtual ~hkpShapeContainerCF5()
    {}
};

}  // namespace fnv_00cf5750
