#include "f3_common.h"
// src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpaabbphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpAabbPhantom.h"

// @fnv 0x00cf2460
// pdb: hkpAabbPhantom::getType | hkpAabbPhantom.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00cf2460()
{
    return 0;
}

struct hkBoolXcf24d0
{
    char m_cBooleanValue;
    hkBoolXcf24d0(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

template <class T> class hkArrayXcf24d0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkObjXcf24d0
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    hkArrayXcf24d0<void*> m_items;

    hkBoolXcf24d0 ContainsItem(void* pv) const;
};

// Searches m_items for pv and returns true if found, otherwise false.
// @f3 0x00978bb0 (community match, verified in this file)
hkBoolXcf24d0 hkObjXcf24d0::ContainsItem(void* item) const
{
    const hkArrayXcf24d0<void*>& items = *reinterpret_cast<const hkArrayXcf24d0<void*>*>(&unk0C0);
    for (int index = 0; index < items.m_iElementCount; ++index) {
        if (items.m_data[index] == item)
            return true;
    }
    return false;
}


struct PresentFlag
{
    bool value;
    PresentFlag(bool v) : value(v)
    {}
    PresentFlag(const PresentFlag& v) : value(v.value)
    {}
};
struct FUN_00cf2a60_t : hkpAabbPhantom
{
    void NotifyAll(hkpCollidable* collidable, PresentFlag wasPresent);
    void FUN_00cf2a60(hkpCollidable* collidable);
};
// Searches the phantom's collidable list for the given collidable, notifies via NotifyAll whether it was present, and removes it by swapping in the last entry.
// @f3 0x00978c40 (community match, verified in this file)
struct AabbPhantomLayout
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
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    hkAabb m_kBounds;
    hkArray<void*> m_ppOverlappingCollidables;
};

// pdb: hkpAabbPhantom::removeOverlappingCollidable | hkpAabbPhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collidable
void FUN_00cf2a60_t::FUN_00cf2a60(hkpCollidable* collidable)
{
    AabbPhantomLayout* self = (AabbPhantomLayout*)this;
    int index;
    int count = self->m_ppOverlappingCollidables.m_iElementCount;
    int i = 0;
    if (count > 0)
    {
        void** ppEntry = self->m_ppOverlappingCollidables.m_data;
        do
        {
            if (*ppEntry == collidable)
            {
                index = i;
                goto search_done;
            }
            ++i;
            ++ppEntry;
        } while (i < count);
    }
    index = -1;
search_done:
    NotifyAll(collidable, PresentFlag(index >= 0));
    if (index >= 0)
    {
        --self->m_ppOverlappingCollidables.m_iElementCount;
        int lastIndex = self->m_ppOverlappingCollidables.m_iElementCount;
        self->m_ppOverlappingCollidables.m_data[index] = self->m_ppOverlappingCollidables.m_data[lastIndex];
    }
}


class hkClassCF2A;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayCF2A
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

class hkStatisticsCollectorCF2A
{
  public:
    virtual ~hkStatisticsCollectorCF2A() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayCF2A<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            int iAllocated = FUN_00d06f80(kArray.m_data, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class FUN_00d08130
{
  public:
    virtual ~FUN_00d08130() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    char m_pad08[0xa8];

    void WritePhantomLists(hkStatisticsCollectorCF2A* pkCollector, const hkClassCF2A* pkClass) const throw();
};

class hkMemoryAllocatorCF2C;

struct hkMemoryRouterCF2C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2C* m_pStreamAllocator;
    hkMemoryAllocatorCF2C& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2C& __cdecl FUN_00c85750() throw();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyCF2C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayCF2C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorCF2C& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyCF2C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkPhantomCF2C
{
  public:
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    hkArrayCF2C<void*> m_overlaps;
    bool m_dirty;

    int FUN_00ca94c0(void* p);
    void AddOverlap(void* p);
};

namespace fnv_00cf2bf0 {
class hkMemoryAllocatorCF2B
{
  public:
    virtual ~hkMemoryAllocatorCF2B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterCF2B
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2B* m_pStreamAllocator;
    hkMemoryAllocatorCF2B& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2B& __cdecl FUN_00c85750();

template <class T> __forceinline void destructCF2B(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayCF2B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ~hkArrayCF2B()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructCF2B(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorCF2B& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkpCollidableCF2B;

struct hkVector4CF2B
{
    hkReal x, y, z, w;
};

struct hkAabbCF2B
{
    hkVector4CF2B m_kMinimumCorner;
    hkVector4CF2B m_kMaximumCorner;
};

class FUN_00d08130
{
  public:
    virtual ~FUN_00d08130() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    char m_pad08[0xa8];
};

class FUN_00cf2bf0 : public FUN_00d08130
{
  public:
    hkAabbCF2B m_kBounds;
    hkArrayCF2B<hkpCollidableCF2B*> m_ppOverlappingCollidables;
    char m_padDC[0x4];

    virtual ~FUN_00cf2bf0() throw();
};

typedef char fnv_check_cf2bf0[(sizeof(FUN_00cf2bf0) == 0xe0) ? 1 : -1];

// @fnv 0x00cf2bf0
FUN_00cf2bf0::~FUN_00cf2bf0() throw()
{}
}  // namespace fnv_00cf2bf0

namespace fnv_00cf2c50 {
class hkMemoryAllocatorCF2C
{
  public:
    virtual ~hkMemoryAllocatorCF2C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF2C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2C* m_pStreamAllocator;
    hkMemoryAllocatorCF2C& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCF2C {
extern "C" hkMemoryRouterCF2C& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayCF2C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorCF2C& kAlloc = hkRouterCF2C::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkPhantomCF2C
{
  public:
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    hkArrayCF2C<void*> m_overlaps;

    void FreeListenerArrays();
    void ClearOverlapsIfEmpty();
};

}  // namespace fnv_00cf2c50

namespace fnv_00cf2d50 {
class hkMemoryAllocatorCF2D
{
  public:
    virtual ~hkMemoryAllocatorCF2D() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> T* _bufAlloc(int& iReqNumInOut)
    {
        int n = iReqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        iReqNumInOut = n / (int)sizeof(T);
        return (T*)p;
    }
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterCF2D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2D* m_pStreamAllocator;
    hkMemoryAllocatorCF2D& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2D& __cdecl FUN_00c85750();

template <class T> __forceinline void copyCF2D(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayCF2D
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

    __forceinline void operator=(const hkArrayCF2D& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorCF2D& kAlloc, const hkArrayCF2D& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = kAlloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyCF2D(m_data, a.m_data, m_iElementCount);
    }
};

struct hkVector4CF2D
{
    hkReal x, y, z, w;
};

struct hkAabbCF2D
{
    hkVector4CF2D m_kMinimumCorner;
    hkVector4CF2D m_kMaximumCorner;
};

class hkpShapeCF2D;
class hkpPhantomOverlapListenerCF2D;
class hkpPhantomListenerCF2D;

struct hkpCollidableCF2D
{
    const hkpShapeCF2D* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    const hkpShapeCF2D* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

class hkpWorldObjectCF2D
{
  public:
    virtual ~hkpWorldObjectCF2D() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableCF2D m_kCollidable;

    const hkpCollidableCF2D* getCollidable() const
    {
        return &m_kCollidable;
    }
    void CopyEntriesFrom(const hkpWorldObjectCF2D* pkOtherObj) throw();
};

class FUN_00cf2cb0 : public hkpWorldObjectCF2D
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObjectCF2D* p = (hkpWorldObjectCF2D*)FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    char m_pad80[0xc];
    hkArrayCF2D<hkpPhantomOverlapListenerCF2D*> m_kPhantomOverlapListeners;
    hkArrayCF2D<hkpPhantomListenerCF2D*> m_kPhantomListeners;
    char m_padA4[0xc];
    hkAabbCF2D m_kBounds;
    char m_padD0[0x10];

    FUN_00cf2cb0(const hkAabbCF2D& kAabb, hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObjectCF2D* FUN_00cf2d50() const throw();
};

typedef char fnv_check_cf2d50[(sizeof(FUN_00cf2cb0) == 0xe0) ? 1 : -1];

}  // namespace fnv_00cf2d50

namespace fnv_00cf2f60 {
class hkMemoryAllocatorCF2F
{
  public:
    virtual ~hkMemoryAllocatorCF2F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF2F
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2F* m_pStreamAllocator;
    hkMemoryAllocatorCF2F& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2F& __cdecl FUN_00c85750();

class FUN_00cf2bf0
{
  public:
    virtual ~FUN_00cf2bf0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00cf2bf0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00cf2bf0* DestroyAndFree(unsigned int uiFlags) throw();
};

}  // namespace fnv_00cf2f60

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct DummyBool
{
    char m_cBooleanValue;
};

struct __declspec(align(16)) ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct DummyNormal : public hkVector4
{
    void FUN_00c7f700(const void* rot, const void* dir);
};

struct DummyCollidable;

struct WorldRayCastOutput
{
    DummyNormal m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_uiShapeKeyIndex;
    int m_pad1c;
    hkUint32 m_shapeKeys0;
    hkUint32 m_shapeKeys1;
    hkUint32 m_shapeKeys2;
    hkUint32 m_shapeKeys3;
    hkUint32 m_shapeKeys4;
    hkUint32 m_shapeKeys5;
    hkUint32 m_shapeKeys6;
    hkUint32 m_shapeKeys7;
    hkUint32 m_shapeKeys8;
    hkUint32 m_shapeKeys9;
    hkUint32 m_shapeKeys10;
    hkUint32 m_shapeKeys11;
    const DummyCollidable* m_pRootCollidable;
};

struct DummyShape
{
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
    virtual void func5() = 0;
    virtual void func6() = 0;
    virtual void func7() = 0;
    virtual DummyBool RayCast(const ShapeRayCastQuery& input, WorldRayCastOutput& output) const = 0;
};

struct DummyCollidable
{
    DummyShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    DummyCollidable* m_parent;
};

template <class T> struct Array_cf2c
{
    Array_cf2c() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct Vector4_cf2c
{
    __m128 m_vComponents;
    Vector4_cf2c& operator=(const Vector4_cf2c& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct Aabb_cf2c
{
    Vector4_cf2c m_kMinimumCorner;
    Vector4_cf2c m_kMaximumCorner;
};

struct BroadPhaseHandle_cf2c
{
    unsigned int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    unsigned short m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
};

struct Collidable_cf2c
{
    void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    BroadPhaseHandle_cf2c m_kBroadPhaseHandle;
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (char)((unsigned int)pvOwner - (unsigned int)this);
    }
};

class WorldObject_cf2c
{
  public:
    WorldObject_cf2c(const void* pkShape, int eType) throw();
    virtual ~WorldObject_cf2c() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    unsigned int m_ulUserData;
    Collidable_cf2c m_kCollidable;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
};

class Phantom_cf2c : public WorldObject_cf2c
{
  public:
    Phantom_cf2c(const void* pkShape) throw() : WorldObject_cf2c(pkShape, 2)
    {
        m_kCollidable.SetOwnerPointer(this);
    }
    Array_cf2c<void*> m_kPhantomOverlapListeners;
    Array_cf2c<void*> m_kPhantomListeners;
    int unkA4, unkA8, unkAC;
};

class FUN_00cf2cb0 : public Phantom_cf2c
{
  public:
    FUN_00cf2cb0(const Aabb_cf2c& kAabb, unsigned int uiCollisionFilterInfo) throw();
    virtual ~FUN_00cf2cb0() throw();
    Aabb_cf2c m_kBounds;
    Array_cf2c<void*> m_ppOverlappingCollidables;
    bool m_bOrderDirty;
};

// Constructs the Phantom base with a null shape, clears m_bOrderDirty, copies kAabb into m_kBounds and stores the collision filter data.
// @fnv 0x00cf2cb0
FUN_00cf2cb0::FUN_00cf2cb0(const Aabb_cf2c& kAabb, unsigned int uiCollisionFilterInfo) throw() : Phantom_cf2c(0)
{
    m_bOrderDirty = false;
    m_kBounds = kAabb;
    m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = uiCollisionFilterInfo;
}
