#include "f3_common.h"
// src/havok/physics/utilities/actions/mousespring/hkpmousespringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/mousespring/hkpmousespringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMouseSpringAction.h"

struct FUN_00d2b1f0
{
    void __thiscall EntityRemovedCallback(int);
};

struct FUN_00cbb1c0 : FUN_00d2b1f0
{
    void __thiscall Method(int);
};

// @fnv 0x00cbb1c0
// pdb: hkpMouseSpringAction::entityRemovedCallback | hkpMouseSpringAction.obj | fnv360_0822_retail, vtable, high
// pdb params: entity
void __thiscall FUN_00cbb1c0::Method(int aiValue)
{
    EntityRemovedCallback(aiValue);
    *(int*)((char*)this + 0x18) = 0;
}

struct FUN_00cbb1b0_Class
{
    char pad0[0x48];
    hkReal m_fMaxRelativeForce;
    void __thiscall hkpMouseSpringAction_setMaxRelativeForce(hkReal a);
};

// @fnv 0x00cbb1b0
// pdb: hkpMouseSpringAction::setMaxRelativeForce | hkpMouseSpringAction.obj | fnv360_0822_debug, call_seq + bridge(call_seq|call_gap) + skyrim(objrun_open), high
void FUN_00cbb1b0_Class::hkpMouseSpringAction_setMaxRelativeForce(hkReal a)
{
    m_fMaxRelativeForce = a;
}

extern "C" int DAT_01268a14;

// @fnv 0x00cbb8a0
// pdb: bhkBlendController::GetRTTI | bhkBlendController.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00cbb8a0()
{
    return (int)&DAT_01268a14;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct Ms_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* n);
    virtual void ReturnMemory(void* p, int n);
};
struct Ms_Tls
{
    int u0;
    int u1;
    int u2;
    int u3;
    Ms_Heap* heap;
};
Ms_Tls* __cdecl FUN_00c85750();

struct Ms_ArrInit
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};

struct Ms_Sphere
{
    int v0;
    int v1;
    int v2;
    int type;
    float radius;
    int u5;
    int u6;
    int u7;
    void __thiscall FUN_00cd8160(float r);
};
struct Ms_Xf
{
    __m128 c0;
    __m128 c1;
    __m128 c2;
    __m128 t;
};
struct Ms_Body
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    void __thiscall FUN_00cd2d80(Ms_Sphere* s, Ms_Xf* x, int parent);
};

struct Ms_Input
{
    int i0;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    __m128 q0;
    __m128 q1;
    __m128 q2;
};
struct Ms_Coll
{
    int* vptr;
    float early;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    float dist;
    int hit;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int key;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    int u30;
    int u31;
};

typedef void(__cdecl* Ms_Fn)(Ms_Body*, void*, Ms_Input*, Ms_Coll*);
extern "C"
{
}

namespace fnv_00cbb790 {
struct hkAllocatorCBB7
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCBB7
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    hkAllocatorCBB7* m_pStreamAllocator;
};
void* __cdecl FUN_00c85750();
inline hkAllocatorCBB7& heapCBB7()
{
    return *((hkMemoryRouterCBB7*)FUN_00c85750())->m_pStreamAllocator;
}

template <typename T> inline void copyCBB7(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <typename T> struct hkArrayCBB7
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline hkArrayCBB7& operator=(const hkArrayCBB7& kOther)
    {
        hkAllocatorCBB7& kAlloc = heapCBB7();
        if (getCapacity() < kOther.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = kOther.m_iElementCount * sizeof(T);
            m_data = (T*)kAlloc.AllocateBufferWithSize(iNumBytes);
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = kOther.m_iElementCount;
        copyCBB7(m_data, kOther.m_data, m_iElementCount);
        return *this;
    }
};

struct __declspec(align(16)) hkVector4CBB7
{
    __m128 m_vComponents;
    void operator=(const hkVector4CBB7& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkpEntity;

class FUN_00cbb4e0 : public hkpUnaryAction
{
  public:
    hkUint32 m_1c;
    hkVector4CBB7 m_kMousePositionInWorld;
    hkVector4CBB7 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    hkUint32 m_uiCollisionShapeKey;
    hkArrayCBB7<void*> m_kAppliedCallbacks;

    FUN_00cbb4e0(hkpEntity* pkEntity) throw();

    void* operator new(unsigned int uiSize)
    {
        hkMemoryRouterCBB7* pkRouter = (hkMemoryRouterCBB7*)FUN_00c85750();
        hkReferencedObject* pkObj = (hkReferencedObject*)pkRouter->m_pStreamAllocator->AllocateMemoryBlock(uiSize);
        pkObj->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return pkObj;
    }

    FUN_00cbb4e0* CloneForEntity(const hkArrayCBB7<hkpEntity*>& kNewEntities,
                                 const hkArrayCBB7<void*>& kNewPhantoms) const throw();
};

}  // namespace fnv_00cbb790

class FUN_00d01a60
{
  public:
    FUN_00d01a60();
    int unk00[11];
};

extern const float DAT_01012054;

class hkpCdBodyCD2D
{
  public:
    hkpCdBodyCD2D(const void* shape, const void* motionState)
    {
        m_pCollisionShape = shape;
        m_pMotionState = motionState;
        m_parent = 0;
        m_uiCollisionShapeKey = 0xffffffff;
    }
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyCD2D* m_parent;
};

class hkpBroadPhaseHandleCD2D
{
  public:
    hkpBroadPhaseHandleCD2D()
    {
        m_iOwnerObjectOffset = 0;
    }
    unsigned int m_iOwnerObjectOffset;
};

class hkpTypedBroadPhaseHandleCD2D : public hkpBroadPhaseHandleCD2D
{
  public:
    hkpTypedBroadPhaseHandleCD2D(int type)
    {
        m_type = (signed char)type;
        m_ucObjectQualityType = -1;
        m_uiCollisionFilterData = 0;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* owner)
    {
        int offset = (int)((char*)owner - (char*)this);
        m_iOwnerOffset = (signed char)offset;
    }
    signed char m_type;
    signed char m_iOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
};

class FUN_00cd2d80 : public hkpCdBodyCD2D
{
  public:
    FUN_00cd2d80(const void* shape, const void* motionState, int type);

    signed char m_iOwnerOffset;
    signed char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleCD2D m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};

// Constructs the body from shape and motionState, builds the broad phase handle with type, sets its owner pointer, and sets a default allowed penetration depth.
// @fnv 0x00cd2d80
FUN_00cd2d80::FUN_00cd2d80(const void* apCollisionShape, const void* motionState, int aiBroadPhaseType)
    : hkpCdBodyCD2D(apCollisionShape, motionState), m_iOwnerOffset(0), m_kBroadPhaseHandle(aiBroadPhaseType),
      m_fAllowedPenetrationDepth(DAT_01012054)
{
    m_kBroadPhaseHandle.SetOwnerPointer(this);
    m_uiForceCollideOntoPpu = 0;
    m_uiShapeSizeOnSpu = 0;
}

struct Ms_Tls;
Ms_Tls* FUN_00c85750();

extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

extern "C"
{
}

struct __declspec(align(16)) hkVector4CBB1
{
    __m128 m_vComponents;
    void operator=(const hkVector4CBB1& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct FUN_00cbb4e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0C;
    unsigned int unk10;
    hkStringPtr m_name;
    void* m_pEntity;
    unsigned int unk1C;
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    unsigned int m_uiCollisionShapeKey;
    hkArray<char> m_kAppliedCallbacks;
    FUN_00cbb4e0(int arg);
};
extern float DAT_01016248, DAT_01017870, DAT_0101ffc0;
// Initializes the hkpMouseSpringAction fields with default spring constants, zeroed vectors, and the action name.
// @f3 0x008feb20 (community match, verified in this file)
namespace f3m_008feb20 {
// Makes a copy of this object (FUN_008fa0e0) and, when that worked, gives the copy a freshly made
// attachment placed at this object's position, converted from physics units to world units.
struct __declspec(align(16)) F8feb20_Vector4
{
    float x, y, z, w;
};

struct F8feb20_Point3
{
    float x, y, z;
};

struct F8feb20_Attachment
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    F8feb20_Point3 position;
};

F8feb20_Attachment* __cdecl BSTestObjects_CreateCoordinateJack(float size);

struct F8feb20_Object
{
    virtual void Unused00();
    virtual void Unused04();
    virtual void Unused08();
    virtual void Unused0C();
    virtual void Unused10();
    virtual void Unused14();
    virtual void Unused18();
    virtual void Unused1C();
    virtual void Unused20();
    virtual void Unused24();
    virtual void Unused28();
    virtual void Unused2C();
    virtual void Unused30();
    virtual void Unused34();
    virtual void Unused38();
    virtual void Unused3C();
    virtual void Unused40();
    virtual void Unused44();
    virtual void Unused48();
    virtual void Unused4C();
    virtual void Unused50();
    virtual void Unused54();
    virtual void Unused58();
    virtual void Unused5C();
    virtual void Unused60();
    virtual void Unused64();
    virtual void Unused68();
    virtual void Unused6C();
    virtual void Unused70();
    virtual void Unused74();
    virtual void Unused78();
    virtual void Unused7C();
    virtual void Unused80();
    virtual void Unused84();
    virtual void Unused88();
    virtual void Unused8C();
    virtual void Unused90();
    virtual void Unused94();
    virtual void Unused98();
    virtual void Unused9C();
    virtual void UnusedA0();
    virtual void UnusedA4();
    virtual void UnusedA8();
    virtual void UnusedAC();
    virtual void UnusedB0();
    virtual void UnusedB4();
    virtual void UnusedB8();
    virtual void UnusedBC();
    virtual void UnusedC0();
    virtual void UnusedC4();
    virtual void UnusedC8();
    virtual void UnusedCC();
    virtual void UnusedD0();
    virtual void UnusedD4();
    virtual void UnusedD8();
    virtual void Attach(F8feb20_Attachment* attachment, int first);
    virtual void UnusedE0();
    virtual void GetPosition(F8feb20_Vector4* out);

    F8feb20_Object* FUN_008fa0e0(int arg);
    F8feb20_Object* FUN_008feb20(int arg);
};

static const float kPhysicsToWorld = 6.99904f;

// pdb: bhkRigidBody::CreateDisplayGeometry | bhkRigidBody.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apNode
F8feb20_Object* F8feb20_Object::FUN_008feb20(int arg)
{
    F8feb20_Object* copy = FUN_008fa0e0(arg);
    if (copy)
    {
        F8feb20_Vector4 position;
        GetPosition(&position);

        F8feb20_Point3 world;
        world.x = position.x * (double)kPhysicsToWorld;
        world.y = position.y * (double)kPhysicsToWorld;
        world.z = position.z * (double)kPhysicsToWorld;

        F8feb20_Attachment* attachment = BSTestObjects_CreateCoordinateJack(6.0f);
        if (attachment)
        {
            attachment->position = world;
            copy->Attach(attachment, 1);
        }
    }
    return copy;
}
}   // namespace f3m_008feb20

