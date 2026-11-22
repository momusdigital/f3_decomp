#include "f3_common.h"
// src/havok/physics/dynamics/constraint/breakable/hkpbreakableconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/breakable/hkpbreakableconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBreakableConstraintData.h"

struct FUN_00d4de80_class : public hkpBreakableConstraintData
{
    void FUN_00d4de80(int, void* out);
};
// @fnv 0x00d4de80
// pdb: hkpBreakableConstraintData::getRuntimeInfo | hkpBreakableConstraintData.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: wantRuntime, infoOut
void FUN_00d4de80_class::FUN_00d4de80(int, void* out)
{
    ((int*)out)[1] = m_usNumSolverResults;
    ((int*)out)[0] = m_usRuntimeOffset + 0x34;
}

struct GenericConstraintAtomScheme
{
    char pad[0x10];
    void* m_kBridgeAtoms;    // +0x10
    int m_usSizeOfAllAtoms;  // +0x14
};

struct FUN_00d4de50_class
{
    char pad[0x18];
    void* m_pHavokConstraint;  // +0x18
    void PopulateInfo(GenericConstraintAtomScheme* info);
};

// @fnv 0x00d4de50
void FUN_00d4de50_class::PopulateInfo(GenericConstraintAtomScheme* info)
{
    ((void(__thiscall*)(void*, GenericConstraintAtomScheme*))((*(void***)m_pHavokConstraint)[0x3c / 4]))(
        m_pHavokConstraint, info);
    info->m_kBridgeAtoms = (char*)this + 0xc;
    info->m_usSizeOfAllAtoms = 0xc;
}

// @fnv 0x00d4dec0
// pdb: SandBoxActorPackageData::GetPackageType | SandBoxPackage.obj | fnv360_1110_retail, vtable, medium
int __cdecl FUN_00d4dec0()
{
    return 0xc;
}

struct hkFinishLoadedObjectFlagD4DF
{
    int m_bFinishing;
};

class hkpConstraintDataD4DF;

struct FUN_00d21ce0_cls
{
    hkUint16 m_type;
    hkUint16 m_pad02;
    void* m_pBridge;
    hkpConstraintDataD4DF* m_pConstraintData;

    FUN_00d21ce0_cls(hkFinishLoadedObjectFlagD4DF flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pConstraintData);
    }
    void FUN_00d21ce0(void* pvConstraintData) throw();
};

struct hkpBridgeAtomsD4DF
{
    FUN_00d21ce0_cls m_kBridgeAtom;

    hkpBridgeAtomsD4DF(hkFinishLoadedObjectFlagD4DF flag) : m_kBridgeAtom(flag)
    {}
};

class hkReferencedObjectD4DF
{
  public:
    hkReferencedObjectD4DF(hkFinishLoadedObjectFlagD4DF flag)
    {}
    virtual ~hkReferencedObjectD4DF();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpConstraintDataD4DF : public hkReferencedObjectD4DF
{
  public:
    hkpConstraintDataD4DF(hkFinishLoadedObjectFlagD4DF flag) : hkReferencedObjectD4DF(flag)
    {}
    hkUlong m_ulUserData;
};

class hkReferencedObjectCDF7
{
  public:
    hkReferencedObjectCDF7() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectCDF7() throw();
    void FUN_00c90510() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkListenerCDF7
{
  public:
    hkListenerCDF7() throw()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* owner) throw();

    short m_type;
    short unk02;
    int unk04;
    int unk08;
};

class hkMidCDF7 : public hkReferencedObjectCDF7
{
  public:
    hkMidCDF7() throw() : m_08(0)
    {}
    virtual ~hkMidCDF7() throw();
    int m_08;
};

class hkBoolD4DE
{
  public:
    hkBoolD4DE(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

struct hkpConstraintInfoD4E0
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpConstraintAtom* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

struct hkpVelocityAccumulatorD4E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
};

struct hkpConstraintQueryInD4E0
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
    const hkpVelocityAccumulatorD4E0* m_pBodyA;
    const hkpVelocityAccumulatorD4E0* m_pBodyB;
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
    struct hkpConstraintInstanceD4E0* m_pConstraintChainInstance;
    char* m_pByteBuffer;
};

struct hkpWorldD4E0
{
    void FUN_00c97e80(hkBool* result, struct hkpConstraintInstanceD4E0* constraint);
};

struct hkpEntityD4E0
{
    int unk00;
    int unk04;
    hkpWorldD4E0* m_pOwningWorld;
};

struct hkpConstraintInstanceD4E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpEntityD4E0* m_entities0;
};

struct hkpBoolResultD4E0
{
    hkBool m_cBooleanValue;
};

struct RuntimeD4E0
{
    hkBool m_bFlag;
    hkReal m_fVectorA[3];
    hkReal m_fVectorB[3];
    hkReal m_fVectorC[3];
    hkReal m_fVectorD[3];
};

__forceinline void store3(const hkVector4& v, hkReal* p)
{
    p[0] = v.x;
    p[1] = v.y;
    p[2] = v.z;
}

struct S00d4e0f0_Object : hkpBreakableConstraintData
{
    void hkpBreakableConstraintData_buildJacobian(const hkpConstraintQueryInD4E0& in, int out);
};

// If the runtime flag is clear, saves body velocities and calls FUN_00d72190 or FUN_00d6f460; else calls FUN_00d4de30 and optionally removes the constraint.
// @f3 0x009db0b0 (community match, verified in this file)
struct hkpVtW130 : hkReferencedObject
{
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void PopulateInfo(hkpConstraintInfoD4E0& info) const;
};
struct hkpQueryW130
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
    const hkpVelocityAccumulatorD4E0* m_pBodyA;
    const hkpVelocityAccumulatorD4E0* m_pBodyB;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    struct hkpConstraintInstanceD4E0* m_pConstraintChainInstance;
    char* m_pByteBuffer;
};
struct hkpWorldW130
{
    void hkpWorld_removeConstraint(hkBool* result, struct hkpConstraintInstanceD4E0* constraint);
};
void __stdcall FUN_009dabb0(const hkpConstraintQueryInD4E0& in, int out);
void __cdecl FUN_00a00ec0(hkpConstraintAtom* atoms, const hkpConstraintQueryInD4E0& in, hkpBoolResultD4E0 flag,
                          int out);
void __cdecl FUN_009fccc0(hkpConstraintAtom* atoms, int sizeOfAllAtoms, const hkpConstraintQueryInD4E0& in, int out);

// pdb: hkpBreakableConstraintData::buildJacobian | hkpBreakableConstraintData.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|vtable) + skyrim(caller_sim), high
void S00d4e0f0_Object::hkpBreakableConstraintData_buildJacobian(const hkpConstraintQueryInD4E0& in, int out)
{
    const hkpQueryW130& q = reinterpret_cast<const hkpQueryW130&>(in);
    RuntimeD4E0* runtime = reinterpret_cast<RuntimeD4E0*>(q.m_pByteBuffer + m_usRuntimeOffset);

    if (!runtime->m_bFlag)
    {
        const hkpVelocityAccumulatorD4E0* bodyA = q.m_pBodyA;
        const hkpVelocityAccumulatorD4E0* bodyB = q.m_pBodyB;
        store3(bodyA->m_vLinearVelocity, runtime->m_fVectorA);
        store3(bodyB->m_vLinearVelocity, runtime->m_fVectorB);
        store3(bodyA->m_vAngularVelocity, runtime->m_fVectorC);
        store3(bodyB->m_vAngularVelocity, runtime->m_fVectorD);

        hkpConstraintInfoD4E0 info;
        reinterpret_cast<const hkpVtW130*>(m_pConstraintData)->PopulateInfo(info);

        if (info.m_kBridgeAtoms->m_type == hkpConstraintAtom::TYPE_CONTACT)
        {
            hkpBoolResultD4E0 flag;
            flag.m_cBooleanValue = 1;
            FUN_00a00ec0(info.m_kBridgeAtoms, in, flag, out);
        }
        else
        {
            FUN_009fccc0(info.m_kBridgeAtoms, info.m_usSizeOfAllAtoms, in, out);
        }
    }
    else
    {
        FUN_009dabb0(in, out);

        if (m_bRemoveWhenBroken)
        {
            hkBool result;
            hkpConstraintInstanceD4E0* instance = q.m_pConstraintChainInstance;
            reinterpret_cast<hkpWorldW130*>(instance->m_entities0->m_pOwningWorld)->hkpWorld_removeConstraint(&result, instance);
        }
    }
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_set_ps1(float);
}

extern const __m128 DAT_010ec7f0;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(hkReal s)
    {
        m_vComponents = _mm_set_ps1(s);
    }
    __forceinline void setInterpolate4(const hkVector4q& v0, const hkVector4q& v1, const hkVector4q& t)
    {
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t.m_vComponents);
        m_vComponents = _mm_add_ps(_mm_mul_ps(v0.m_vComponents, s), _mm_mul_ps(v1.m_vComponents, t.m_vComponents));
    }
    __forceinline void blendFrom(const hkVector4q& v0, const hkVector4q& t)
    {
        hkVector4q tmp;
        tmp.setInterpolate4(v0, *this, t);
        m_vComponents = tmp.m_vComponents;
    }
};

struct ContactImpulseInfo
{
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;

    __forceinline hkReal getImpulseApplied() const
    {
        return m_fAccumulatedImpulse;
    }
};

struct QuantizedBoundsData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4q m_vLinearVelocity;
    hkVector4q m_vAngularVelocity;
};

struct SixteenWordFloatRecord
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
    QuantizedBoundsData* m_pBodyA;
    QuantizedBoundsData* m_pBodyB;
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
    struct Pad
    {
        void* m_val;
        __forceinline void* val() const
        {
            return m_val;
        }
    } m_pConstraintChainInstance;
    ContactImpulseInfo* m_pByteBuffer;
};

class hkBoolC
{
  public:
    __forceinline hkBoolC(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

namespace fnv_00d4df30 {
struct hkBoolD4D
{
    char m_cBooleanValue;
    hkBoolD4D()
    {}
    hkBoolD4D(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBoolD4D& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct RuntimeInfoD4D
{
    int m_iSolverIterationCount;
    int m_iSolverResultCount;
};

class hkpConstraintDataD4D
{
  public:
    hkpConstraintDataD4D() : m_sReferenceCount(1), m_ulUserData(0)
    {}
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void GetConstraintRuntimeInfo(hkBoolD4D wantRuntime, RuntimeInfoD4D& infoOut) const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;

    void FUN_00c90510() const throw();
};

struct FUN_00d21ce0_cls
{
    unsigned short m_type;
    unsigned short unk02;
    void* m_pBridge;
    hkpConstraintDataD4D* m_pConstraintData;

    FUN_00d21ce0_cls()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* constraintData) throw();
};

}  // namespace fnv_00d4df30

class GlobalObjectO2_00d472a0;

class hkBoolD4E0
{
  public:
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    hkBoolD4E0& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }
    bool operator==(bool e) const
    {
        return m_cBooleanValue == e;
    }
    char m_cBooleanValue;
};

struct hkpConstraintRuntimeD4E0
{
    int unk00, unk04, unk08, unk0c;
    unsigned short unk10;
    unsigned char m_flags;
    unsigned char unk13;
    int unk14, unk18;
    char* m_pRuntime;
};

class hkpSimulationIslandD4E0;

struct BrkEntity
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpSimulationIslandD4E0* m_pSimulationIsland;
};

struct BrkInstance
{
    int unk00;
    int unk04;
    BrkEntity* m_pEntity;
    int unk0C, unk10, unk14, unk18, unk1c, unk20;
    unsigned short m_kListeners;
    unsigned short unk26;
    int unk28, unk2c;
    hkpConstraintRuntimeD4E0* m_pConstraintInternal;
};

struct BrkInfo
{
    hkpSimulationIslandD4E0* m_pCurrentSimulationIsland;
    BrkInstance* m_pHavokConstraint;
    const GlobalObjectO2_00d472a0* m_type;
    int m_0c;
    float m_uiFilterValue;
    float m_threshold;

    BrkInfo(hkpSimulationIslandD4E0* island, BrkInstance* constraint, const GlobalObjectO2_00d472a0* type)
        : m_pCurrentSimulationIsland(island), m_pHavokConstraint(constraint), m_type(type), m_0c(0)
    {}
};

// @f3twin 0x009dac40 of 0x007efe40
// pdb: hkpBreakableConstraintData::getType | hkpBreakableConstraintData.obj | fnv360_0822_retail, objrun_open, low
int __cdecl F3_FUN_009dac40()
{
    return 0xc;
}
