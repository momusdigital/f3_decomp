#include "f3_common.h"
// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpGravityGun.h"

struct DDCC60World
{
    void removeReference();
};

struct hkFinishLoadedObjectFlagE463
{
    bool m_bFinishing;
};

template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE463() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e466a0();

    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE463<void*> m_kListeners;
};

class hkpRigidBodyE463;

class FUN_00e46300 : public FUN_00e466a0
{
  public:
    hkArrayE463<hkpRigidBodyE463*> m_kPickedBodies;

    FUN_00e46300(hkFinishLoadedObjectFlagE463 flag);
    void finishLoadedObject(hkFinishLoadedObjectFlagE463 flag);
    void TESFile_GetTESForm();
    virtual ~FUN_00e46300();
};

// @f3 0x00448e80 (community match, verified in this file)
#include <string.h>

extern int DAT_00e2c4d0;

namespace ns_00448e80 {

struct Receiver448 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Notify(int, int);
};

struct Layout448 {
    int u000; int u004; int u008; int u00c;
    Receiver448* receiver;
    int u014; int u018; int u01c;
    int u020; int u024; int u028; int u02c;
    int u030; int u034; int u038; int u03c;
    int u040; int u044; int u048; int u04c;
    int u050; int u054; int u058; int u05c;
    int u060; int u064; int u068; int u06c;
    int u070; int u074; int u078; int u07c;
    int u080; int u084; int u088; int u08c;
    int u090; int u094; int u098; int u09c;
    int u0a0; int u0a4; int u0a8; int u0ac;
    int u0b0; int u0b4; int u0b8; int u0bc;
    int u0c0; int u0c4; int u0c8; int u0cc;
    int u0d0; int u0d4; int u0d8; int u0dc;
    int u0e0; int u0e4; int u0e8; int u0ec;
    int u0f0; int u0f4; int u0f8; int u0fc;
    int u100; int u104; int u108; int u10c;
    int u110; int u114; int u118; int u11c;
    int u120; int u124; int u128; int u12c;
    int u130; int u134; int u138; int u13c;
    int u140; int u144; int u148; int u14c;
    int u150; int u154; int u158; int u15c;
    int u160; int u164; int u168; int u16c;
    int u170; int u174; int u178; int u17c;
    int u180; int u184; int u188; int u18c;
    int u190; int u194; int u198; int u19c;
    int u1a0; int u1a4; int u1a8; int u1ac;
    int u1b0; int u1b4; int u1b8; int u1bc;
    int u1c0; int u1c4; int u1c8; int u1cc;
    int u1d0; int u1d4; int u1d8; int u1dc;
    int u1e0; int u1e4; int u1e8; int u1ec;
    int u1f0; int u1f4; int u1f8; int u1fc;
    int u200; int u204; int u208; int u20c;
    int u210; int u214; int u218; int u21c;
    int u220; int u224; int u228; int u22c;
    int u230; int u234; int u238; int u23c;
    int v240; int v244; int v248; int v24c; int v250; int v254;
    int u258; int u25c; int u260;
    int f264; int f268; int f26c;
};

} // namespace ns_00448e80

// pdb: TESFile::TESRewind | TESFile.obj | fnv360_0822_retail, call_gap, low
// pdb params: getform
void FUN_00e46300::finishLoadedObject(hkFinishLoadedObjectFlagE463 flag)
{
    ns_00448e80::Layout448* s = (ns_00448e80::Layout448*)this;
    if (s->receiver)
        s->receiver->Notify(0, DAT_00e2c4d0);
    s->f264 = 0;
    s->f268 = 0;
    s->f26c = 0;
    memset(&s->v240, 0, 24);
    if (flag.m_bFinishing)
        TESFile_GetTESForm();
}


namespace fnv_00e46340 {
class hkMemoryAllocatorE463
{
  public:
    virtual ~hkMemoryAllocatorE463() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE463
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE463* m_pStreamAllocator;
    hkMemoryAllocatorE463& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE463& __cdecl FUN_00c85750();

template <class T> __forceinline void destructE463(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE463() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructE463(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorE463& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

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

class hkReferencedObjectE463
{
  public:
    virtual ~hkReferencedObjectE463() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectE463*>(p)->m_usMemSizeAndFlags);
    }
};

}  // namespace fnv_00e46340

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

namespace MathUtilities {
}

struct GGVector4
{
    __m128 m_vComponents;

    void operator=(const GGVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    hkReal& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void SetTransformedPosition(const struct GGTransform& t, const GGVector4& v);
};

struct GGMotion
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    GGVector4 m_vCenterOfMass0;
    GGVector4 m_vCenterOfMass1;
    hkReal GetMassValue() const;
};

struct GGCollidable
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    int ca0;
    int ca4;
    int ca8;
    int cac;
    int cb0;
    int cb4;
    int cb8;
    int cbc;
    int cc0;
    int cc4;
    int cc8;
    int ccc;
};

struct GGRigidBody
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    GGCollidable m_kCollidable;
    GGMotion m_pMotionState;

    const GGVector4& getCenterOfMassInWorld() const
    {
        return m_pMotionState.m_vCenterOfMass1;
    }
    const GGCollidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    hkReal GetMassValue() const
    {
        return m_pMotionState.GetMassValue();
    }
};

struct GGEntityArray
{
    GGRigidBody** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct GGSimulationIsland
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
    GGEntityArray m_kActorEntries;
};

struct GGIslandArray
{
    GGSimulationIsland** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct GGWorldRayCastInput
{
    GGVector4 m_vFrom;
    GGVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    hkUint32 m_uiFilterInfo;
    GGWorldRayCastInput() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct GGRayHitCollector
{
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo) = 0;
    hkReal m_fEarlyOutHitFraction;

    GGRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
    }
};

struct GGShapeRayCastCollectorOutput
{
    GGVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    hkInt32 m_iExtraInfo;
    int unk18;
    int unk1c;

    GGShapeRayCastCollectorOutput()
    {
        reset();
    }
    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
    }
};

struct GGShapeRayCastOutput : GGShapeRayCastCollectorOutput
{
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;

    GGShapeRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        GGShapeRayCastCollectorOutput::reset();
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct GGWorldRayCastOutput : GGShapeRayCastOutput
{
    const GGCollidable* m_pRootCollidable;

    GGWorldRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        m_pRootCollidable = 0;
        GGShapeRayCastOutput::reset();
    }
};

struct GGClosestRayHitCollector : GGRayHitCollector
{
    GGWorldRayCastOutput m_kClosestHit;

    GGClosestRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_kClosestHit.reset();
        GGRayHitCollector::reset();
    }
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo);
};

struct GGWorld
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
    GGIslandArray m_kActiveSimulationIslands;
    GGIslandArray m_kInactiveSimulationIslands;

    void RayCast(const GGWorldRayCastInput& input, GGRayHitCollector& collector) const;
};

struct GGTransform
{
    GGVector4 m_kColumn0, m_kColumn1, m_kColumn2;
    GGVector4 m_vTranslation;
};

struct GravityGun : hkpGravityGun
{
    bool isGrabbed(const GGRigidBody* body) const
    {
        for (int i = 0; i < m_kPickedBodies.m_iElementCount; i++)
        {
            if (m_kPickedBodies.m_data[i] == body)
            {
                return true;
            }
        }
        return false;
    }

    GGRigidBody* FUN_00e45a60(const GGTransform& viewTransform, const GGRigidBody* characterBody, const GGWorld* world);
};

struct DDCC60World;

struct __declspec(align(16)) MyVec
{
    float x, y, z, w;
};

extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern "C" void _mm_store_ss(float* _V, __m128 _A);
class hkMemoryAllocatorE460;

struct hkMemoryRouterE460
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE460* m_pStreamAllocator;
};

namespace hkRouterE460 {
extern "C" hkMemoryRouterE460& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE460
{
    char m_cBooleanValue;
    hkBoolE460()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE460(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE460
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE460& router = hkRouterE460::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE460<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct hkSimdRealE460
{
    __m128 m_vValue;
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4E460
{
    __m128 m_vComponents;
    hkSimdRealE460 getW() const
    {
        hkSimdRealE460 r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
};

extern "C" __m128 _mm_setr_ps(float, float, float, float);

class hkStringPtrE462
{
  public:
    char* m_pcText;
    void FUN_00cb0c10(const char* pcString) throw();
    void operator=(const char* pcString)
    {
        FUN_00cb0c10(pcString);
    }
};

template <class T> class hkArrayE462
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE462() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct __declspec(align(16)) hkVector4E462
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};
