#include "f3_common.h"
// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleLinearCastWheelCollide.h"

struct FUN_00e368a0_Class
{
    void FUN_00e368a0();
};

// Iterates the entries in the array at this+0x10, calling FUN_00c92c70 on each entry's object at offset 8.
// @f3 0x0079f010 (community match, verified in this file)
struct FUN_00e368a0_Target
{
    virtual void v00();
};

struct FUN_00e368a0_Entry
{
    FUN_00e368a0_Target* m_pTarget;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
};

struct FUN_00e368a0_Self : FUN_00e368a0_Class
{
    char m_unk00[0x1c];
    FUN_00e368a0_Entry* m_pEntries;  // +0x1c
    unsigned int m_iEntryCount;      // +0x20
};

typedef void(__thiscall* FUN_00e368a0_HitFn)(FUN_00e368a0_Target*, int);

// pdb: CombatGroup::RemoveFromMembers | CombatGroup.obj | fnv360_0721_beta, call_seq, medium
void FUN_00e368a0_Class::FUN_00e368a0()
{
    FUN_00e368a0_Self* self = static_cast<FUN_00e368a0_Self*>(this);
    unsigned int count = self->m_iEntryCount;
    if (count)
    {
        for (unsigned int i = 0; i < count; i++)
        {
            FUN_00e368a0_Target* target = self->m_pEntries[i].m_pTarget;
            FUN_00e368a0_HitFn* vtbl = *(FUN_00e368a0_HitFn**)target;
            vtbl[0x3f4 / 4](target, 0);
        }
    }
}


void __cdecl FUN_00e36900();
// @fnv 0x00e36aa0
// pdb: hkString::strRchr | hkString.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkString_strRchr()
{
    FUN_00e36900();
}

inline hkBaseObject::~hkBaseObject()
{}

struct FUN_00d1df70
{
    virtual void v00() throw();
    void removeReference() throw();
};

struct hkpPhantomOverlapListener
{
    int dummy;
};

class hkpPhantom : public FUN_00d1df70
{
  public:
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void FUN_00d07c80(hkpPhantomOverlapListener*) throw();
};

struct WheelState
{
    hkpPhantom* m_pPhantom;
    FUN_00d1df70* m_pCollisionShape;
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
};

struct HavokMemoryRouter
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void deallocate(void* p, int numBytes) throw();
};

struct HavokAllocatorContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HavokMemoryRouter* m_router;
};

extern "C" HavokAllocatorContext* __cdecl FUN_00c85750() throw();

struct WheelStatesArray
{
    WheelState* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    inline ~WheelStatesArray() throw()
    {
        HavokAllocatorContext* mem = FUN_00c85750();
        HavokMemoryRouter* router = mem->m_router;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            router->deallocate(this->m_data, (cap & 0x3fffffff) * sizeof(WheelState));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

namespace fnv_00e36e20 {
struct hkAllocatorE36E
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterE36E
{
    void* m_apvUnk00[4];
    hkAllocatorE36E* m_pkHeap;
    hkAllocatorE36E& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterE36E* __cdecl FUN_00c85750() throw();

void __cdecl FUN_00c908c0(hkAllocatorE36E& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayE36E
{
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
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkAllocatorE36E& kAlloc, int n)
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
        GrowArrayCapacity(FUN_00c85750()->heap(), n);
        m_iElementCount = n;
    }
};

class hkReferencedObjectE36E
{
  public:
    virtual ~hkReferencedObjectE36E() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90510() throw();
};

class hkpPhantomOverlapListenerE36E
{
  public:
    virtual ~hkpPhantomOverlapListenerE36E() throw();
};

class hkpCollidableE36E;

class hkpRigidBodyE36E
{
  public:
    char m_acUnk00[0x10];
    char m_kCollidable[0x10];

    const hkpCollidableE36E* getCollidable() const
    {
        return (const hkpCollidableE36E*)m_kCollidable;
    }
};

class hkpPhantomE36E : public hkReferencedObjectE36E
{
  public:
    void FUN_00d07c80(hkpPhantomOverlapListenerE36E* pkListener) throw();
    void FUN_00d07de0(hkpPhantomOverlapListenerE36E* pkListener) throw();
};

class hkpShapeE36E : public hkReferencedObjectE36E
{
};

class hkpRejectChassisListenerE36E : public hkReferencedObjectE36E, public hkpPhantomOverlapListenerE36E
{
  public:
    const hkpCollidableE36E* m_pChassisCollidable;
};

struct hkpVehicleLinearCastWheelCollideWheelStateE36E
{
    hkpPhantomE36E* m_pPhantom;
    hkpShapeE36E* m_pCollisionShape;
    char m_acUnk08[0x58];
};

class hkpVehicleLinearCastWheelCollideE36E : public hkReferencedObjectE36E
{
  public:
    hkBool m_bWheelCollisionEnabled;
    hkUint8 m_type;
    hkUint32 m_uiWheelCount;
    hkArrayE36E<hkpVehicleLinearCastWheelCollideWheelStateE36E> m_kWheelStates;
    hkpRejectChassisListenerE36E m_kRejectChassisListener;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fMaxExtraPenetrationAgainstFixed;

    hkpVehicleLinearCastWheelCollideE36E* CloneWithChassis(const hkpRigidBodyE36E& kNewChassis,
                                                           const hkArrayE36E<hkpPhantomE36E*>& kNewPhantoms) const
        throw();
};

class FUN_00e36b20 : public hkpVehicleLinearCastWheelCollideE36E
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkReferencedObjectE36E* p = (hkReferencedObjectE36E*)FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00e36b20() throw();
};

}  // namespace fnv_00e36e20

__declspec(align(16)) struct LCWheelCastOut
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18, u1c;
    unsigned int u20, u24, u28, u2c, u30, u34, u38, u3c;
    unsigned int u40, u44, u48, u4c, u50, u54, u58, u5c;
    unsigned int u60, u64, u68, u6c;
};

template <class T> struct hkArrayE363
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

extern const __m128 DAT_010c44d0;

struct hkVector4E366
{
    __m128 m_vComponents;

    hkVector4E366()
    {}
    hkVector4E366(const hkVector4E366& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4E366& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setNeg4(const hkVector4E366& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    void setXYZ(const hkVector4E366& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct __declspec(align(16)) FUN_00e36900_V
{
    union
    {
        __m128 vec;
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00c7f690(void* ws, void* result);
    void FUN_00c7f640(void* ws, void* src);
};

class FUN_00e36900_Wrap : public hkpVehicleLinearCastWheelCollide
{
  public:
    void FUN_00e36900(int unused, unsigned char wheelIndex, FUN_00e36900_V* result);
};

// Passes result and the wheel state at wheelIndex through two helpers with z zeroed in between, and stores the final vector in result.
// @fnv 0x00e36900
void FUN_00e36900_Wrap::FUN_00e36900(int unused, unsigned char wheelIndex, FUN_00e36900_V* result)
{
    FUN_00e36900_V second;
    FUN_00e36900_V first;

    void* ws = (char*)m_kWheelStates.m_data + wheelIndex * 0x60 + 0x10;

    first.FUN_00c7f690(ws, result);

    first.z = 0.0f;

    second.FUN_00c7f640(ws, &first);

    result->vec = second.vec;
}

__declspec(align(16)) struct hkAabb_36950
{
    float m_minX;
    float m_minY;
    float m_minZ;
    float m_maxX;
    float m_maxY;
    float m_maxZ;
};

struct __declspec(align(16)) LCAVec4
{
    hkReal v[4];
};

struct __declspec(align(16)) hkpVehicleLinearCastWheelCollideWheelState
{
    void* m_pCollisionShape;
    hkUint32 m_04;
    hkUint32 m_08;
    hkUint32 m_0c;
    LCAVec4 m_pos;
    LCAVec4 m_20;
    LCAVec4 m_30;
    LCAVec4 m_40;
    LCAVec4 m_vContactPosition;
};

struct __declspec(align(16)) LCCastInput
{
    LCAVec4 m_vTo;
    volatile hkReal m_10;
    volatile hkReal m_14;
    hkUint32 m_18;
    hkUint32 m_1c;
    const hkUint8* m_20;
    hkReal m_24;
    hkUint32 m_28;
    hkUint32 m_2c;
    hkUint32 m_30;
    hkUint32 m_34;
    hkUint32 m_38;
    hkUint32 m_3c;
    hkUint32 m_40;
    hkUint32 m_44;
    hkUint32 m_48;
    hkReal m_4c;
    hkInt32 m_50;
    hkUint32 m_54;
    hkUint32 m_58;
    hkUint32 m_5c;
    hkUint32 m_60;
    hkUint32 m_64;
    hkUint32 m_68;
    hkUint32 m_6c;
    hkUint32 m_70;
    hkUint32 m_74;
    hkUint32 m_78;
    hkUint32 m_7c;
    hkUint32 m_80;
    hkUint32 m_84;
    hkUint32 m_88;
    hkUint32 m_8c;
    hkUint32 m_90;
    hkUint32 m_94;
    hkUint32 m_98;
    hkUint32 m_9c;
};

class hkMemoryAllocatorE36;

struct hkMemoryRouterE36
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorE36* m_pTemp;
    hkMemoryAllocatorE36* m_pStreamAllocator;
    hkMemoryAllocatorE36& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE36 {
extern "C" hkMemoryRouterE36& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorE36& alloc, void* array, int numElem, int sizeElem) throw();

template <class T> class hkArrayE36
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(hkMemoryAllocatorE36& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newCap = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterE36::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

struct hkAllocatorE36C
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterE36C
{
    void* m_apvUnk00[4];
    hkAllocatorE36C* m_pkHeap;
    hkAllocatorE36C& heap()
    {
        return *m_pkHeap;
    }
};
namespace fnvc_adapt {
extern "C" hkMemoryRouterE36C& __cdecl FUN_00c85750() throw();
}

void __cdecl FUN_00c908c0(hkAllocatorE36C& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayE36C
{
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
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkAllocatorE36C& kAlloc, int n)
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
        GrowArrayCapacity(fnvc_adapt::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

class hkReferencedObjectE36C
{
  public:
    virtual ~hkReferencedObjectE36C() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpPhantomOverlapListenerE36C
{
  public:
    virtual ~hkpPhantomOverlapListenerE36C() throw();
};

class hkpCollidableE36C;

class hkpRigidBodyE36C
{
  public:
    char m_acUnk00[0x10];
    char m_kCollidable[0x10];

    const hkpCollidableE36C* getCollidable() const
    {
        return (const hkpCollidableE36C*)m_kCollidable;
    }
};

struct __declspec(align(16)) hkVector4E36C
{
    float x, y, z, w;
};

struct hkAabbE36C
{
    hkVector4E36C m_kMinimumCorner;
    hkVector4E36C m_kMaximumCorner;
};

class hkpPhantomE36C : public hkReferencedObjectE36C
{
  public:
    void FUN_00d07de0(hkpPhantomOverlapListenerE36C* pkListener) throw();
};

class FUN_00cf2cb0 : public hkpPhantomE36C
{
  public:
    static __forceinline void* operator new(unsigned int, void* pvMem) throw()
    {
        return pvMem;
    }
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkReferencedObjectE36C* p =
            (hkReferencedObjectE36C*)fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00cf2cb0(const hkAabbE36C& kAabb, hkUint32 uiCollisionFilterInfo) throw();

    char m_acUnk08[0xd8];
};

struct hkpVehicleDataWheelComponentParamsE36C
{
    hkReal m_fSphereRadius;
    hkReal m_fViscosityFriction;
    hkReal m_fMaxFriction;
    hkReal m_fSlipAngle;
    hkReal m_fSlipVelocity;
    hkReal m_fMaxContactBodyAcceleration;
    hkReal m_fForceFeedbackMultiplier;
    hkReal m_fMaxFrictionForce;
    hkReal m_fFrictionEqualizer;
    hkInt8 m_iAxle;
};

struct hkpVehicleDataE36C
{
    char m_acUnk00[0x20];
    hkUint8 m_iWheelCount;
    char m_acUnk21[0x6b];
    hkArrayE36C<hkpVehicleDataWheelComponentParamsE36C> m_kWheelParams;
};

struct hkpVehicleInstanceE36C
{
    char m_acUnk00[0x18];
    hkpRigidBodyE36C* m_pChassisCollidable;
    hkpVehicleDataE36C* m_data;

    hkpRigidBodyE36C* getChassis() const
    {
        return m_pChassisCollidable;
    }
};

class hkBaseObjE36B
{
  public:
    virtual ~hkBaseObjE36B() throw();
};

class hkRefObjE36B : public hkBaseObjE36B
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjE36B() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjE36B() throw();
};

class hkIfaceE36B
{
  public:
    hkIfaceE36B() throw()
    {}
    virtual ~hkIfaceE36B() throw();
};

template <class T> class hkArrayE36B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE36B() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkToleranceE36B : public hkRefObjE36B, public hkIfaceE36B
{
  public:
    int unk0C;
    float m_tolerance0;
    float m_tolerance1;

    hkToleranceE36B() throw()
    {}
    virtual ~hkToleranceE36B() throw();
};

class FUN_00e36b20 : public hkRefObjE36B
{
  public:
    unsigned char m_08;
    unsigned char m_09;
    int unk0C;
    hkArrayE36B<void*> m_ppData;
    hkToleranceE36B m_fScalar;

    FUN_00e36b20(void*, void*, void*, void*) throw();
    virtual ~FUN_00e36b20() throw();
};

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
extern const __m128 g_kSignMaskE36120;
struct __declspec(align(16)) Vector4E36120
{
    float x;
    float y;
    float z;
    float w;
    __m128& Vector4f()
    {
        return *reinterpret_cast<__m128*>(this);
    }
    const __m128& Vector4f() const
    {
        return *reinterpret_cast<const __m128*>(this);
    }
    void set(float fX, float fY, float fZ, float fW)
    {
        Vector4f() = _mm_setr_ps(fX, fY, fZ, fW);
    }
    void setNeg4(const Vector4E36120& v)
    {
        Vector4f() = _mm_xor_ps(g_kSignMaskE36120, v.Vector4f());
    }
};
struct MemoryE36120
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct ContextE36120
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemoryE36120* m_pkMemory;
};
ContextE36120* GetContextE36120();
struct ShapeE36120
{
    static void* operator new(unsigned int nbytes) throw()
    {
        ContextE36120* pkContext = GetContextE36120();
        ShapeE36120* pkShape = static_cast<ShapeE36120*>(pkContext->m_pkMemory->allocateChunk(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSize;
    unsigned short m_usRefCount;
};

inline void* operator new(unsigned int, void* pvMem) throw()
{
    return pvMem;
}

struct __declspec(align(16)) hkVector4E363
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }
    void operator=(const hkVector4E363& v)
    {
        getQuad() = v.getQuad();
    }
};

struct hkTransformE363
{
    hkVector4E363 m_kColumn0;
    hkVector4E363 m_kColumn1;
    hkVector4E363 m_kColumn2;
    hkVector4E363 m_vTranslation;
    const hkVector4E363& getTranslation() const
    {
        return m_vTranslation;
    }
};

struct hkpShapeE363;
struct hkpCollidableE363;

struct FUN_00d01a60
{
    int m_minX;
    int m_minY;
    int m_minZ;
    unsigned char m_expansionMinX;
    unsigned char m_expansionMinY;
    unsigned char m_expansionMinZ;
    unsigned char m_ucExpansionShift;
    int m_maxX;
    int m_maxY;
    int m_maxZ;
    unsigned char m_expansionMaxX;
    unsigned char m_expansionMaxY;
    unsigned char m_expansionMaxZ;
    unsigned char m_ucUnknownByte;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;

    FUN_00d01a60() throw();
};

struct hkpTypedBroadPhaseHandleE363
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;

    __forceinline hkpTypedBroadPhaseHandleE363(int iType)
    {
        m_iOwnerObjectOffset = 0;
        m_type = (char)iType;
        m_uiCollisionFilterData = 0;
        m_ucObjectQualityType = (char)0xff;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (char)((unsigned long)pvOwner - (unsigned long)this);
    }
};

struct hkpCollidableE363
{
    const hkpShapeE363* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCollidableE363* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleE363 m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;

    __forceinline hkpCollidableE363(const hkpShapeE363* pkShape, const hkTransformE363* pkTransform, int iType = 0)
        : m_pCollisionShape(pkShape), m_uiCollisionShapeKey(0xffffffff), m_pMotionState(pkTransform), m_parent(0),
          m_iOwnerOffset(0), m_kBroadPhaseHandle(iType)
    {
        m_fAllowedPenetrationDepth = -1.0f;
        m_kBroadPhaseHandle.SetOwnerPointer(this);
        m_uiForceCollideOntoPpu = 0;
        m_uiShapeSizeOnSpu = 0;
    }
};
