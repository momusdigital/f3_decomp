#include "f3_common.h"
// src/havok/common/serialize/resourcedatabase/hkresourcehandle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resourcedatabase/hkresourcehandle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkResourceHandle.h"

extern int DAT_010eb19c;
void __cdecl Deallocate(void*);

struct D481D0RefVariant
{
    const void* GetVariantValue() const;
};
// @fnv 0x00e2df20
// pdb: PathingLOSMap::GetOffsetForNavMesh | PathingLOSMap.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aNavMeshID, aRetOffset
const void* __fastcall FUN_00e2df20(char* self, int)
{
    return reinterpret_cast<D481D0RefVariant*>(self + 8)->GetVariantValue();
}

namespace fnv_00e2df30 {
struct D481D0ReferencedObject;
struct D481D0Class;
struct D481D0RefVariant
{
    void set(D481D0ReferencedObject*, D481D0Class const*);
};

struct FUN_00e2df30_class
{
    void FUN_00e2df30(D481D0ReferencedObject* obj, D481D0Class const* cls);
};

// @fnv 0x00e2df30
// pdb: hkDefaultError::enableAll | hkDefaultError.obj | fnv360_0822_retail, vtable, medium
void FUN_00e2df30_class::FUN_00e2df30(D481D0ReferencedObject* obj, D481D0Class const* cls)
{
    ((D481D0RefVariant*)((char*)this + 8))->set(obj, cls);
}
}  // namespace fnv_00e2df30

extern int DAT_010eb288;
// @f3 0x00600920 (community match, verified in this file)
namespace f3m_00600920 {
struct Helper { void FUN_005fc430(int*); char pad[0x28]; };
struct X { int m_p; Helper h; int unk2c; int unk30; int unk34; int unk38; X* FUN_00600920(int*, int*); };
// pdb: PathingNode::PathingNode | PathingNode.obj | fnv360_0822_debug, objrun_open, low
// pdb params: aLocation, aTangent
X* X::FUN_00600920(int* p, int* q)
{
    m_p = 0;
    h.FUN_005fc430(p);
    unk2c = q[0];
    unk30 = q[1];
    unk34 = q[2];
    unk38 = 0;
    return this;
}
}   // namespace f3m_00600920


struct S_00e028e0_Base
{
    ~S_00e028e0_Base();
};

struct FUN_00e2f1e0_class
{
    void* m_p;
    S_00e028e0_Base m_base;
    void* __thiscall Destroy(int flags);
};

// @fnv 0x00e2f1e0
// pdb: `anonymous namespace'::hkEntitySelectorListed::`scalar deleting destructor' | hkpSaveContactPointsUtil.obj | fnv360_0822_retail, vtable, high
void* __thiscall FUN_00e2f1e0_class::Destroy(int flags)
{
    m_base.~S_00e028e0_Base();
    m_p = &DAT_010eb19c;
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00e2f210_manager
{
    virtual void unused();
    virtual void unused2();
    virtual void __thiscall release(void* resource, unsigned short handle);
};

struct FUN_00e2f210_router
{
    void* vftable;
    unsigned char padding[0x0c];
    FUN_00e2f210_manager* manager;
};

FUN_00e2f210_router* _D1A0E0GetMemoryRouter();

namespace fnv_00e2f240 {

struct FUN_00e2f240_manager_class
{
    virtual void FUN_00e2f240_virtual_0();
    virtual void FUN_00e2f240_virtual_1();
    virtual void __thiscall FUN_00e2f240_free(void*, unsigned short);
};

struct FUN_00e2f240_router_class
{
    unsigned char m_auiShapeKeys[0x10];
    FUN_00e2f240_manager_class* m_manager;
};

FUN_00e2f240_router_class* _D1A0E0GetMemoryRouter();

}  // namespace fnv_00e2f240

struct FUN_00e2df50_Obj
{
    int unk00;
    int unk04;
    int unk08;

    int hkOffsetOnlyStreamWriter_tell();
};

// @fnv 0x00e2df50
// pdb: hkOffsetOnlyStreamWriter::tell | hkOffsetOnlyStreamWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FUN_00e2df50_Obj::hkOffsetOnlyStreamWriter_tell()
{
    return unk08;
}

int __cdecl FUN_00cb0fa0(const void* filter, const void* tagged);
// @f3 0x0058ca80 (community match, verified in this file)
namespace f3m_0058ca80 {

struct Sub_0058b6e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    bool __thiscall FUN_0058b6e0(Sub_0058b6e0* rhs) const;
};

struct Arr_0058b6e0
{
    Sub_0058b6e0 m[2][2];
};

// pdb: BSFaceGenManager::CompareFaceGenCoord | BSFaceGenManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCoord1, apCoord2
bool __cdecl FUN_0058ca80(Arr_0058b6e0* a, Arr_0058b6e0* b)
{
    if (a == 0 && b == 0)
        return true;
    if (a == 0 || b == 0)
        return false;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (!a->m[i][j].FUN_0058b6e0(&b->m[i][j]))
                return true;
        }
    }
    return false;
}
}   // namespace f3m_0058ca80


struct MemoryManager
{
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual void freeBlock(void*, int);
};
struct MemoryRouter
{
    void* vt;
    int unk04;
    int unk08;
    int unk0c;
    MemoryManager* manager;
};
MemoryRouter* __cdecl FUN_00c85750();

namespace fnv_00e2ec00 {
extern "C" int DAT_010eb2c4;
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct MemoryAllocator
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Free(void* address, unsigned int bytes);
};
struct MemoryRouter
{
    int m_00, m_04, m_08, m_0c;
    MemoryAllocator* m_pThreadAllocator;
};
void* FUN_00c85750() throw();
}  // namespace fnv_00e2ec00

namespace fnv_00e2f090 {
struct hkAllocatorE2F0
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE2F0
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    hkAllocatorE2F0* m_pkTemp;
    hkAllocatorE2F0* m_pkHeap;
    hkAllocatorE2F0& temp()
    {
        return *m_pkTemp;
    }
    hkAllocatorE2F0& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterE2F0* __cdecl FUN_00c85750() throw();

void __cdecl FUN_00c908c0(hkAllocatorE2F0& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayE2F0
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE2F0() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayE2F0() throw()
    {
        hkAllocatorE2F0& kAlloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

template <typename T, int N> struct hkInplaceArrayE2F0
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[N / 4];

    hkInplaceArrayE2F0() : m_data((T*)m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}
    ~hkInplaceArrayE2F0() throw()
    {
        hkAllocatorE2F0& kAlloc = FUN_00c85750()->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkAllocatorE2F0& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(FUN_00c85750()->temp(), n);
        m_iElementCount = n;
    }
};

class hkStringBufE2F0
{
  public:
    hkInplaceArrayE2F0<char, 128> m_kStringBuffer;

    hkStringBufE2F0()
    {
        m_kStringBuffer.SetSizeAndGrow(1);
        m_kStringBuffer[0] = 0;
    }
    void setEmpty()
    {
        m_kStringBuffer[0] = 0;
    }
};

struct hkBoolE2F0
{
    char m_cBooleanValue;
    hkBoolE2F0(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class FUN_00d87790
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;

    FUN_00d87790(hkBoolE2F0 bIsValid) throw();
    void FUN_00d874d0(const char* pcKey, const void* pvValue) throw();
};

template <typename V> class hkStringMapE2F0
{
  public:
    FUN_00d87790 m_map;

    hkStringMapE2F0(hkBoolE2F0 bIsValid = false) : m_map(bIsValid)
    {}
    void insert(const char* pcKey, V val)
    {
        m_map.FUN_00d874d0(pcKey, val);
    }
};

}  // namespace fnv_00e2f090

class hkMemoryAllocatorE2E2;

struct hkMemoryRouterE2E2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE2E2* m_pStreamAllocator;
};

namespace hkRouterE2E2 {
extern "C" hkMemoryRouterE2E2& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE2E2
{
    char m_cBooleanValue;
    hkBoolE2E2()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE2E2(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE2E2
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE2E2& router = hkRouterE2E2::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE2E2<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

class hkMemoryAllocatorE2E3;

struct hkMemoryRouterE2E3
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE2E3* m_pStreamAllocator;
};

namespace hkRouterE2E3 {
extern "C" hkMemoryRouterE2E3& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE2E3
{
    char m_cBooleanValue;
    hkBoolE2E3()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE2E3(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE2E3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE2E3& router = hkRouterE2E3::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE2E3<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct S00e2e3f0_Pair
{
    int m_kPointA;
    int m_kPointB;
};

struct S00e2e3f0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00e2e3f0_Pair* m_aiIndexedValues;
    int m_uiItemCount;
    void FUN_00e2e3f0();
};

extern "C" __declspec(noinline) void __fastcall FUN_00cb0c00(void* self)
{
    Deallocate(self);
}

// @f3 0x00b4fd80 (community match, verified in this file)
// pdb: ParallaxShader::RecreateRendererData | ParallaxShader.obj | fnv360_0822_retail, objrun_open, medium
void S00e2e3f0_Obj::FUN_00e2e3f0()
{
    void** slot = reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x8c);
    int count = 0x14;
    do
    {
        void* obj = *slot;
        if (obj)
        {
            reinterpret_cast<void (__thiscall*)(void*)>((*reinterpret_cast<void***>(obj))[40])(obj);
        }
        slot++;
    } while (--count);
    slot = reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xdc);
    count = 0x21;
    do
    {
        void* obj2 = *slot;
        if (obj2)
        {
            reinterpret_cast<void (__thiscall*)(void*)>((*reinterpret_cast<void***>(obj2))[34])(obj2);
        }
        slot++;
    } while (--count);
    FUN_00cb0c00(this);
}


extern "C" int __cdecl FUN_00cb0fa0(const char*, const char*);
struct String839
{
    unsigned int tagged;
    void FUN_00cb0c00();
    const char* text() const
    {
        return reinterpret_cast<const char*>(tagged & ~1u);
    }
};

struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};

template <class T> struct RefPtrE2E710
{
    RefPtrE2E710(T* e) throw() : m_pRetainedObject(e)
    {
        if (e)
            e->FUN_00c90510();
    }
    ~RefPtrE2E710() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};
template <class T> struct ArrayE2E710
{
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i].m_pRetainedObject == t.m_pRetainedObject)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_data[index].~T();
        m_iElementCount--;
        if (m_iElementCount != index)
            *reinterpret_cast<int*>(m_data + index) = *reinterpret_cast<int*>(m_data + m_iElementCount);
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct FUN_00cb0a60_target
{
    void __thiscall FUN_00cb0a60();
};

struct FUN_00e2e9e0_class
{
    void* m_class;
    unsigned short unk04;
    volatile unsigned short m_handle;
    volatile int m_iObjectReferenceCount;
    FUN_00cb0a60_target m_target;
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_flags;

    void* __thiscall Ctor();
};

extern int DAT_010eb288;

// Initializes the object handle, class pointer, reference count, target, and flags, then returns this.
// @f3 0x00422160 (community match, verified in this file)
extern char DAT_00db5760;
struct Target1203 {void* FUN_0041fd10();};
struct Reset1203 { void** vtable; Reset1203(void** slot):vtable(slot){} ~Reset1203(){*vtable=&DAT_00db5760;} };
// pdb: ExtraWaterZoneMap::~ExtraWaterZoneMap | ExtraDataObjects.obj | fnv360_0822_retail, call_seq, medium
void* FUN_00e2e9e0_class::Ctor() {
 Reset1203 reset(&m_class);
 return reinterpret_cast<Target1203*>(&m_target)->FUN_0041fd10();
}


struct ReferencedE2EB70
{
    ReferencedE2EB70() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedE2EB70() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct NameE2EB70
{
    NameE2EB70(const char* pcName) throw();
    const char* m_pcName;
};
template <class T> struct ArrayE2EB70
{
    ArrayE2EB70() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct FUN_00e2eb70 : public ReferencedE2EB70
{
    FUN_00e2eb70(const char* pcName) throw();
    virtual ~FUN_00e2eb70() throw();
    NameE2EB70 m_kName;
    int m_iValue;
    ArrayE2EB70<int> m_kFirst;
    ArrayE2EB70<int> m_kSecond;
};

// Constructs the object, storing pcName in m_kName and initialising m_iValue to 0.
// @fnv 0x00e2eb70
FUN_00e2eb70::FUN_00e2eb70(const char* pcName) throw() : m_kName(pcName), m_iValue(0)
{}

extern int DAT_010eb2c4;

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct Heap_e2ef
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int nbytes) throw();
};
struct Router_e2ef
{
    int unk00, unk04, unk08, unk0C;
    Heap_e2ef* m_pStreamAllocator;
    Heap_e2ef& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_e2ef& __cdecl FUN_00c85750() throw();
};
struct RouterPtr_e2ef
{
    int unk00, unk04, unk08, unk0C;
    void* m_pStreamAllocator;
};
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement) throw();

struct Container_e2ef;

struct Resource_e2ef
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08;
    Container_e2ef* m_parent;
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
    static void* operator new(unsigned int nbytes) throw()
    {
        Resource_e2ef* p = (Resource_e2ef*)Router_e2ef::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Resource_e2ef* FUN_00e2eb70(const char* name) throw();
    int unk10, unk14, unk18, unk1C, unk20, unk24;
};

template <class T> struct hkRefPtr_e2ef
{
    T* m_pRetainedObject;
    hkRefPtr_e2ef(T* p) throw() : m_pRetainedObject(p)
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c90510();
    }
    hkRefPtr_e2ef(const hkRefPtr_e2ef& o) throw()
    {
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~hkRefPtr_e2ef() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
};

template <class T> struct hkArray_e2ef
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void AddBack(const T& t) throw()
    {
        RouterPtr_e2ef* router = (RouterPtr_e2ef*)FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
};

struct Container_e2ef
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual Resource_e2ef* findResource(const char* name, int flags);
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    hkArray_e2ef<hkRefPtr_e2ef<Resource_e2ef> > m_kResources;
    Resource_e2ef* FUN_00e2efe0(const char* name);
};

namespace fnv_00e2ea40 {
class hkMemoryAllocatorE2EA
{
  public:
    virtual ~hkMemoryAllocatorE2EA() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE2EA
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE2EA* m_pStreamAllocator;

    hkMemoryAllocatorE2EA& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterE2EA& __cdecl FUN_00c85750() throw();
}

namespace FUN_00cb0c00 {
class hkStringPtr
{
  public:
    ~hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace hkE2EA {
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
    void FUN_00c905b0() throw();
};

template <class T> class ReferenceCountedPointer
{
  public:
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};

template <class T> __forceinline void destruct(T* ptr, int size)
{
    for (int i = 0; i < size; i++)
        ptr[i].~T();
}

template <class T> class hkArray
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~hkArray() throw()
    {
        hkMemoryAllocatorE2EA& kAlloc = fnvc_adapt::FUN_00c85750().heap();
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
}

namespace hkE2EA {
}

namespace FUN_00e2ea40 {

}
}  // namespace fnv_00e2ea40

namespace fnv_00e2eae0 {

struct FUN_00c85750_Object
{
    virtual void* vf00();
    virtual void* vf04();
    virtual void* vf08();
    virtual void* vf0c();
    virtual void vf10(void* arg1, int arg2);
};

struct FUN_00c85750_Owner
{
    void* unk00;
    void* unk04;
    void* unk08;
    FUN_00c85750_Object* unk0c;
};

FUN_00c85750_Owner* __cdecl FUN_00c85750();

}  // namespace fnv_00e2eae0

struct ExternalLinkString
{
    unsigned int tagged;
    ExternalLinkString() throw()
    {
        FUN_00cb0a60();
    }
    void FUN_00cb0a60() throw();
    void FUN_00cb0c10(const char* text) throw();
};

extern void __cdecl ResizeAudioStream(MemoryManager*, void*, int);

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
