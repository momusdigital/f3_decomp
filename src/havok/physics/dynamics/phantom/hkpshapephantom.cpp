#include "f3_common.h"
// src/havok/physics/dynamics/phantom/hkpshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpShapePhantom.h"

struct FUN_00c9ea00__VirtualObject
{
    virtual void FUN_00c9ea00__M0();
    virtual void FUN_00c9ea00__M1();
    virtual void FUN_00c9ea00__M2();
    virtual void FUN_00c9ea00__M3();
    virtual void FUN_00c9ea00__M4();
    virtual void FUN_00c9ea00__M5();
    virtual void FUN_00c9ea00__M6();
    virtual void FUN_00c9ea00__M7(void*, float, void*);
};

// @fnv 0x00c9ea00
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M0()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M1()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M2()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M3()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M4()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M5()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M6()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M7(void*, float, void*)
{}

double DAT_01011588 = 0.5;

void FreeListenerArrays();
// @fnv 0x00c9e820
// pdb: NiKeyBasedInterpolator::LoadBinary | NiKeyBasedInterpolator.obj | fnv360_0721_beta, call_seq, medium
// pdb params: kStream
void FUN_00c9e820()
{
    FreeListenerArrays();
}

template <class T> class hkArrayD4CE
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD4CE() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct hkVector4D4CE
{
    hkReal x, y, z, w;
};

struct hkTransformD4CE
{
    hkVector4D4CE m_kColumn0;
    hkVector4D4CE m_kColumn1;
    hkVector4D4CE m_kColumn2;
    hkVector4D4CE m_vTranslation;
};

class hkpShapeD4CE;

struct hkpCollidableD4CE
{
    const hkpShapeD4CE* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    void SetUserInfo(hkUint32 uiInfo)
    {
        m_uiCollisionFilterData = uiInfo;
    }
};

struct hkBoolD4CE
{
    char m_cBooleanValue;
    hkBoolD4CE& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

class FUN_00c9ea40
{
  public:
    virtual ~FUN_00c9ea40() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableD4CE m_kCollidable;
    char m_pad80[0xe0];

    FUN_00c9ea40(const hkpShapeD4CE* pkShape, const hkTransformD4CE& kTransform) throw();
};

struct hkpCollisionDetailD4CE
{
    void* m_kCollidable;
    void* m_pCollisionAgent;
};

class FUN_00d4ce10 : public FUN_00c9ea40
{
  public:
    hkArrayD4CE<hkpCollisionDetailD4CE> m_kCollisionDetails;
    hkBoolD4CE m_bOrderDirty;

    FUN_00d4ce10(const hkpShapeD4CE* pkShape, const hkTransformD4CE& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    virtual ~FUN_00d4ce10() throw();
};

typedef char fnv_check_d4ce10[(sizeof(FUN_00d4ce10) == 0x170) ? 1 : -1];

// Constructs the object from a shape and transform, clears the bool flag, and stores the collision filter info in the collidable.
// @fnv 0x00d4ce10
FUN_00d4ce10::FUN_00d4ce10(const hkpShapeD4CE* pkShape, const hkTransformD4CE& kTransform,
                           hkUint32 uiCollisionFilterInfo) throw()
    : FUN_00c9ea40(pkShape, kTransform)
{
    m_bOrderDirty = false;
    m_kCollidable.SetUserInfo(uiCollisionFilterInfo);
}

struct S00c9e830_Operation
{
    unsigned char type;
    void* object;
    unsigned int parameter;
};

struct S00c9e830_Owner
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    int unk94;
    unsigned char unk98;
    unsigned char unk99;
    unsigned char unk9A;
    unsigned char unk9B;
    unsigned char unk9C;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char unkA2;
    unsigned char unkA3;
    int unkA4;

    void FUN_00c91160(S00c9e830_Operation* operation);
    void FUN_00c91120();
    void FUN_00c91140();
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        --unk94;
        if (unk94 == 0 && unk9C == 0)
        {
            if (unk8C != 0)
                FUN_00c91120();
            if (unkA4 == 1 && unk90 != 0)
                FUN_00c91140();
        }
    }
};

struct S00c9e830_Shape
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

extern "C" void __cdecl FUN_00cb5d00(S00c9e830_Owner* owner, void* object);

struct S00c9e830_Obj
{
    void* unk00;
    void* unk04;
    S00c9e830_Owner* unk08;
    void* unk0C;
    S00c9e830_Shape* unk10;

    void NotifyListeners();
    unsigned int hkpShapePhantom_setShape(S00c9e830_Shape* parameter);
};

// Sets the object's shape to the given parameter, notifying listeners and the owner, or queues the operation if the owner is locked.
// @f3 0x0090dc50 (community match, verified in this file)
struct S00c9e830_RefCounted
{
    virtual ~S00c9e830_RefCounted() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    void addReference()
    {
        if (m_usMemSizeAndFlags != 0)
            ++m_sReferenceCount;
    }
    void removeReference()
    {
        if (m_usMemSizeAndFlags != 0 && --m_sReferenceCount == 0)
            delete this;
    }
};
struct S00c9e830_Queue
{
    char m_pad00[0x80];
    void* m_pPendingOperations;
    int m_iPendingOperationCount;
    char m_pad88[4];
    hkUint8 m_bLocked;

    void FUN_00902570(S00c9e830_Operation* operation);
    void FUN_00902550();

    void unlock()
    {
        if (--m_iPendingOperationCount == 0 && m_bLocked == 0 && m_pPendingOperations != 0)
            FUN_00902550();
    }
};
struct S00c9e830_Notifier
{
    void FUN_009898a0();
};
extern "C" void __cdecl hkpWorldCallbackUtil_firePhantomShapeSet(void* owner, void* object);
extern "C" void __cdecl hkpWorldOperationUtil_addPhantomBP(void* owner, void* object);
// pdb: hkpShapePhantom::setShape | hkpShapePhantom.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(caller_sim), high
unsigned int S00c9e830_Obj::hkpShapePhantom_setShape(S00c9e830_Shape* apShape)
{
    S00c9e830_Operation operation;

    if (unk08 != 0 && reinterpret_cast<S00c9e830_Queue*>(unk08)->m_iPendingOperationCount != 0)
    {
        operation.type = 5;
        operation.object = this;
        operation.parameter = reinterpret_cast<unsigned int>(apShape);
        reinterpret_cast<S00c9e830_Queue*>(unk08)->FUN_00902570(&operation);
        return 0;
    }

    if (unk08 != 0)
    {
        ++reinterpret_cast<S00c9e830_Queue*>(unk08)->m_iPendingOperationCount;
        FUN_00cb5d00(unk08, this);
    }

    reinterpret_cast<S00c9e830_RefCounted*>(apShape)->addReference();

    if (unk10 != 0)
        reinterpret_cast<S00c9e830_RefCounted*>(unk10)->removeReference();

    unk10 = apShape;

    if (unk08 != 0)
        hkpWorldCallbackUtil_firePhantomShapeSet(unk08, this);

    reinterpret_cast<S00c9e830_Notifier*>(this)->FUN_009898a0();

    if (unk08 != 0)
    {
        hkpWorldOperationUtil_addPhantomBP(unk08, this);
        reinterpret_cast<S00c9e830_Queue*>(unk08)->unlock();
    }

    return 1;
}


#include <xmmintrin.h>
struct FUN_00c9e910_Inner
{
    int unk00;
    int unk04;
    float unk08;
};

struct FUN_00c9e910_Outer
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    FUN_00c9e910_Inner* m_pInner;
};

struct __declspec(align(16)) FUN_00c9e910_Temporary
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

class FUN_00c9e910_Class
{
  public:
    void* m_pVtable;
    int unk04;
    FUN_00c9e910_Outer* unk08;
    int unk0C;
    FUN_00c9ea00__VirtualObject* unk10;
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
    __m128 unkB0;
    __m128 unkC0;
    __m128 unkD0;
    __m128 unkE0;

    void hkpPhantom_updateBroadPhase(void* value);
    void hkpShapePhantom_setTransform(int value);
};

// Copies 16 floats from value into unkB0..unkE0; if unk08 is set, calls unk10's method with value and a scaled factor, then passes the result to hkpPhantom_updateBroadPhase.
// @f3 0x0090dd40 (community match, verified in this file)
struct W29Inner
{
    int unk00;
    float unk04;
};

struct W29Outer
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    W29Inner* m_pInner;
};

struct W29Sub
{
    void FUN_008fda60(int value);
};

// pdb: hkpShapePhantom::setTransform | hkpShapePhantom.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap_sim) + skyrim(objrun), high
void FUN_00c9e910_Class::hkpShapePhantom_setTransform(int value)
{
    reinterpret_cast<W29Sub*>(&unkA0)->FUN_008fda60(value);

    if (unk08)
    {
        float scaled = ((W29Outer*)unk08)->m_pInner->unk04 * DAT_01011588;
        FUN_00c9e910_Temporary temporary;

        unk10->FUN_00c9ea00__M7(reinterpret_cast<void*>(value), scaled, &temporary);
        hkpPhantom_updateBroadPhase(&temporary);
    }
}


struct FUN_00c9e990_Inner
{
    int unk00;
    int unk04;
    float unk08;
};
struct FUN_00c9e990_Outer
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    FUN_00c9e990_Inner* unk78;
};
struct FUN_00c9e990_VO
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void M7(void* a, float b, void* c);
};
struct FUN_00c9e990_cls
{
    int unk00;
    int unk04;
    FUN_00c9e990_Outer* m_08;
    int unk0C;
    FUN_00c9e990_VO* m_10;
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    __m128 unkE0;
    void hkpShapePhantom_setPosition(__m128* a, float b);
    void hkpPhantom_updateBroadPhase(void* a1);
};
// Stores *a in unkE0 and, if m_08 is set, calls m_10->M7 with &unkB0, b plus half of m_08->unk78->unk08, and a local buffer, then hkpPhantom_updateBroadPhase on it.
// @f3 0x0090dda0 (community match, verified in this file)
struct FUN_00989c00_stand
{
    void FUN_00989c00(void* a);
};
struct __declspec(align(16)) FUN_00c9e990_LocalA
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
// pdb: hkpShapePhantom::setPosition | hkpShapePhantom.obj | fnv360_0822_retail, call_seq + bridge(call_dedup|call_gap) + skyrim(call_gap_sim), high
void FUN_00c9e990_cls::hkpShapePhantom_setPosition(__m128* a, float b)
{
    float* src = (float*)a;
    float* dst = (float*)&unkD0;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    if (m_08 != 0)
    {
        FUN_00c9e990_LocalA local;
        float scaled = *(float*)(m_08->unk6C + 4) * 0.5;
        float sum = scaled + b;
        m_10->M7((void*)&unkA0, sum, (void*)&local);
        ((FUN_00989c00_stand*)this)->FUN_00989c00((void*)&local);
    }
}

