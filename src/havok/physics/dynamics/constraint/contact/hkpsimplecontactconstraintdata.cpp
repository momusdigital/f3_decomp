#include "f3_common.h"
// src/havok/physics/dynamics/constraint/contact/hkpsimplecontactconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/contact/hkpsimplecontactconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_00d21a60(void* atom, unsigned short index, unsigned int arg);
// hkpSimpleContactConstraintAtom: m_sizeOfAllAtoms at +0x02 (New Vegas Xbox 360 PDB).
struct D927B0Atom
{
    unsigned short m_type;
    unsigned short m_sizeOfAllAtoms;
};
// hkpSimpleContactConstraintData: m_atom at +0x28 (New Vegas Xbox 360 PDB).
struct FUN_00d927b0_class
{
    char unk00[0x28];
    D927B0Atom* m_atom;
    void FUN_00d927b0(unsigned int arg);
};
// @fnv 0x00d927b0
// pdb: hkpSimpleContactConstraintData::getConstraintInfo | hkpSimpleContactConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: infoOut
void FUN_00d927b0_class::FUN_00d927b0(unsigned int arg)
{
    FUN_00d21a60(m_atom, m_atom->m_sizeOfAllAtoms, arg);
}

// @fnv 0x00d927d0
// pdb: hkpSimpleContactConstraintData::getRuntimeInfo | hkpSimpleContactConstraintData.obj | tesv_win, objrun_open, low
void __stdcall FUN_00d927d0(int, int* paiValues)
{
    paiValues[0] = 0;
    paiValues[1] = 0;
}

struct S_00d92690_Alloc
{
    virtual void* Alloc(int size);
    virtual void* Alloc2(int size);
    virtual void Free(void* p, int size);
};
struct S_00d92690_Mgr
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d92690_Alloc* unk10;
    S_00d92690_Alloc* GetAllocator()
    {
        return unk10;
    }
};
struct S_00d92690
{
    unsigned short unk0;
    unsigned short unk2;
    unsigned short count;
    unsigned short capacity;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char elemSize;
    unsigned char unkB;
    unsigned short maxCapacity;
};
S_00d92690* hkpSimpleContactConstraintAtomUtil_allocateAtom(int cap, int a, int b, int maxCap);

// @f3 0x00a26b70 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
struct HeapD926F3
{
    void FUN_008f6d90(void* p, unsigned int bytes, unsigned int tag);
};
S_00d92690* FUN_00a269d0(int cap, int a, int b, int maxCap);
void hkpSimpleContactConstraintAtomUtil_copyContents(S_00d92690* dst, S_00d92690* src);
S_00d92690* FUN_00d92690(S_00d92690* apContainer, bool* grew)
{
    S_00d92690* result = apContainer;
    S_00d92690* pContainer = apContainer;
    int iCount = apContainer->count;
    if (iCount >= apContainer->capacity)
    {
        int iNewCapacity = iCount > 2 ? iCount : 2;
        iNewCapacity *= 2;
        if (iNewCapacity >= apContainer->maxCapacity)
            iNewCapacity = apContainer->maxCapacity;
        result = FUN_00a269d0(iNewCapacity, apContainer->unk8, apContainer->unk9, apContainer->maxCapacity);
        hkpSimpleContactConstraintAtomUtil_copyContents(result, apContainer);
        HeapD926F3* heap = (HeapD926F3*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(apContainer, apContainer->unk2, 4);
        pContainer = result;
        *grew = true;
    }
    pContainer->count = iCount + 1;
    int iElemSize = pContainer->elemSize;
    int* data = (int*)((char*)pContainer + pContainer->capacity * 32 + 0x30 + (short)iCount * (short)iElemSize);
    for (int i = (iElemSize >> 2) - 1; i >= 0; --i)
        *data++ = 0;
    return result;
}


// @fnv 0x00d92810
// pdb: hkpSimpleContactConstraintData::getType | hkpSimpleContactConstraintData.obj | tesv_win, objrun_open, low
int __cdecl FUN_00d92810()
{
    return 11;
}

// @fnv 0x00d92800
void __stdcall FUN_00d92800(bool* p)
{
    *p = true;
}

struct PacketResult
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned short state10;
    volatile unsigned short version12;
    void* volatile ptr14;
    void* volatile ptr18;
    void* ptr1c;
    void* ptr20;
    void* ptr24;
    void* ptr28;
    void* ptr2c;
};

struct FUN_00d92f20
{
    void* vtable;
    unsigned short unk04;
    unsigned short active06;
    unsigned int field08;
    void* field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    void* volatile context24;
    S_00d92690* buffer28;
    unsigned int size2c;

    FUN_00d92f20(void* atom, const unsigned char* first, const unsigned char* second);
};

// Initialises the object's vtable and fields, allocates a buffer sized from first[0xd1] and second[0xd1], and zeroes the packet result header fields.
// @f3 0x00a268d0 (community match, verified in this file)
extern unsigned char DAT_00e7d7c8;
// pdb: hkpSimpleContactConstraintData::hkpSimpleContactConstraintData | hkpSimpleContactConstraintData.obj | fnv360_0822_retail, call_seq, high
// pdb params: constraint, bodyA, bodyB
FUN_00d92f20::FUN_00d92f20(void* atom, const unsigned char* first, const unsigned char* second)
{
    active06 = 1;
    vtable = &DAT_00e7d7c8;
    field08 = 0;
    *(void* volatile*)&field0c = &field18;
    field10 = 0;
    field14 = 0x80000008;
    context24 = atom;

    unsigned int lenA = first[0xbd];
    unsigned int lenB = second[0xbd];
    unsigned int bytesPerEntry = (lenA + lenB) * 4 + 0x14;
    buffer28 = hkpSimpleContactConstraintAtomUtil_allocateAtom(1, lenA, lenB, (unsigned short)(0x1400 / (int)bytesPerEntry));

    PacketResult* result = reinterpret_cast<PacketResult*>(buffer28);
    result->state10 = 0;
    result->version12 = 3;
    result->ptr14 = 0;
    result->ptr18 = 0;
    result->ptr1c = 0;
    result->ptr20 = 0;
    result->ptr24 = 0;
    result->ptr28 = 0;
    result->ptr2c = 0;

    size2c = buffer28->unk2;
}


struct S_00d92fd0_Atom
{
    unsigned short type;
    unsigned short unk02;
    int unk04, unk08, unk0c, unk10;
    S_00d92fd0_Atom* next;
    void FUN_00d21d00(int a, float b, int c, int d, int e, int f);
    void FUN_00d21d10(int a, float b, int c, int d, int e, int f);
    void FUN_00d21fc0(int a, float b, int c, int d, int e, int f);
    void FUN_00d22260(int a, float b, int c, int d, int e, int f);
};
struct S_00d92fd0_Arr
{
    S_00d92fd0_Atom** data;
    int size;
    int cap;
    S_00d92fd0_Atom* local[16];
    S_00d92fd0_Arr()
    {
        data = local;
        size = 0;
        cap = 0x80000010;
    }
};
void __cdecl ResizeAudioStream(S_00d92690_Alloc* a, S_00d92fd0_Arr* arr, int elem);

void __cdecl ResizeAudioStream(void*, void*, int);

struct FUN_00d93140_cls
{
    unsigned char* m_data;
    unsigned int m_len;
    unsigned int m_cap;
    unsigned int hkpDynamicsCpIdMgr_newId(unsigned char value);
};

// @f3 0x00a26970 (community match, verified in this file)
void __cdecl FUN_00901f10(void* array, int sizeOfElement);

// pdb: hkpDynamicsCpIdMgr::newId | hkpSimpleContactConstraintData.obj | fnv360_0822_retail, call_seq, high
// pdb params: value
// pdb: hkpDynamicsCpIdMgr::newId | hkpSimpleContactConstraintData.obj | fnv360_0822_retail, call_seq, high (was: ReplaceOrAppendByte)
unsigned int FUN_00d93140_cls::hkpDynamicsCpIdMgr_newId(unsigned char value)
{
    int i = (int)m_len - 1;
    while (i >= 0)
    {
        if (m_data[i] == 0xff)
        {
            m_data[i] = value;
            return (unsigned int)i;
        }
        i--;
    }
    if (m_len == (m_cap & 0x3fffffff))
    {
        FUN_00901f10(this, 1);
    }
    m_data[m_len] = value;
    m_len++;
    return m_len - 1;
}


// @fnv 0x00d927f0
int __stdcall FUN_00d927f0(int arg)
{
    return 0;
}

struct hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};
struct hkContactPoint
{
    hkVector4f m_vContactPosition;
    hkVector4f m_vSeparatingNormal;
};
struct PhysicsMaterial
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    unsigned int m_ulUserData;
    unsigned char m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned char m_usFlags;
    unsigned char m_flags;
    void init()
    {
        m_fAccumulatedImpulse = 0.0f;
        m_fImpulseLimit = 0.0f;
        m_flags = 1;
    }
};
struct hkpSimpleContactConstraintAtom
{
    unsigned short m_type;
    unsigned short m_usSizeOfAllAtoms;
    unsigned short m_usNumContactPoints;
    unsigned short m_usMaxNumContactPoints;
    unsigned char m_ucNumReservedContactPoints;
    unsigned char m_ucNumContactPointProperties;
    unsigned char m_ucContactPointPropertiesStriding;
    unsigned char unk0B;
    unsigned short m_usMaxNumContactPointProperties;
    unsigned short unk0E;
    unsigned short m_infoFlags;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    hkContactPoint* getContactPoints()
    {
        return reinterpret_cast<hkContactPoint*>(this + 1);
    }
    PhysicsMaterial* getContactPointPropertiesStream(int i)
    {
        return reinterpret_cast<PhysicsMaterial*>(reinterpret_cast<char*>(getContactPoints()) +
                                                  m_usMaxNumContactPoints * sizeof(hkContactPoint) +
                                                  i * m_ucContactPointPropertiesStriding);
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
hkpSimpleContactConstraintAtom* FUN_00d92690(hkpSimpleContactConstraintAtom* atom, hkBool* atomReallocated);
void __cdecl hkpWorldConstraintUtil_updateFatherOfMovedAtom(void* constraint, hkpSimpleContactConstraintAtom* oldAtom,
                          hkpSimpleContactConstraintAtom* newAtom, int newSize);

struct GenericConstraintAtomScheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
    void add(int schemaSize, int numSolverResults, int numSolverElemTemps)
    {
        m_iSchemaByteSize += schemaSize;
        m_iSolverResultCount += numSolverResults;
        m_iSolverElementTemporaryCount += numSolverElemTemps;
    }
};
struct hkpConstraintOwner
{
    void hkpConstraintOwner_addConstraintInfo(void* constraint, GenericConstraintAtomScheme& info);
};
struct MutableByteArray
{
    unsigned char* m_iSlotIds;
    int m_iElementCount;
    int m_iCapacityState;
    int hkpDynamicsCpIdMgr_newId(int index);
};

struct hkpSimpleContactConstraintData
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    MutableByteArray m_kAtoms;
    int unk18;
    int unk1C;
    int unk20;
    void* m_pHavokConstraint;
    hkpSimpleContactConstraintAtom* m_pAtom;
    int m_iAtomSize;

    int FUN_00d92df0(hkpConstraintOwner& constraintOwner, hkContactPoint** cpOut, PhysicsMaterial** cpPropsOut);
};

// Adds a contact point at index size, initializes its properties, updates constraint stats, and reallocates the atom if needed.
// @fnv 0x00d92df0
int hkpSimpleContactConstraintData::FUN_00d92df0(hkpConstraintOwner& constraintOwner, hkContactPoint** cpOut,
                                                 PhysicsMaterial** cpPropsOut)
{
    hkpSimpleContactConstraintAtom* atom = m_pAtom;
    atom->m_infoFlags |= 4;
    int size = atom->m_usNumContactPoints;

    hkpSimpleContactConstraintAtom* oldAtom = m_pAtom;
    hkBool atomReallocated = false;
    m_pAtom = FUN_00d92690(m_pAtom, &atomReallocated);
    hkpSimpleContactConstraintAtom* localAtom = m_pAtom;

    hkContactPoint* cp = &localAtom->getContactPoints()[size];
    PhysicsMaterial* cpp = localAtom->getContactPointPropertiesStream(size);
    PhysicsMaterial* pPrevProps = reinterpret_cast<PhysicsMaterial*>(reinterpret_cast<char*>(cpp) -
                                                                     localAtom->m_ucContactPointPropertiesStriding);
    PhysicsMaterial*& initTarget = cpp;
    initTarget->m_fAccumulatedImpulse = 0.0f;
    cpp->m_fImpulseLimit = 0.0f;
    cpp->m_flags = 1;
    if (size > 0 && (pPrevProps->m_flags & 2) == 0 && pPrevProps->m_usFlags == 0)
    {
        cpp->m_flags = 3;
    }
    *cpOut = cp;
    *cpPropsOut = cpp;

    {
        int newSize = size + 1;
        GenericConstraintAtomScheme info;
        info.clear();
        info.m_iMaxSchemaSize = 0xa0 + (newSize >> 1) * 0x70 + (newSize & 1) * 0x30;
        if (size == 1)
        {
            info.add(0x20, 1, 1);
        }
        if (newSize & 1)
        {
            info.add(0x30, 1, 1);
        }
        else
        {
            info.add(0x40, 1, 1);
        }
        constraintOwner.hkpConstraintOwner_addConstraintInfo(m_pHavokConstraint, info);
    }

    if (atomReallocated)
    {
        hkpWorldConstraintUtil_updateFatherOfMovedAtom(m_pHavokConstraint, oldAtom, m_pAtom, localAtom->m_usSizeOfAllAtoms);
        m_iAtomSize = localAtom->m_usSizeOfAllAtoms;
    }
    return m_kAtoms.hkpDynamicsCpIdMgr_newId(size);
}

// Dispatch contact callbacks and prepare new contact solver state.
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float f0;
    float f1;
    float f2;
    float f3;
};
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

extern double DAT_010cc8d0;  // 1/128
extern float DAT_010c7948[];

struct S00d92900_Config
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
    float m_fContactRestingVelocity;
};
struct S00d92900_CollisionInput
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
    S00d92900_Config* m_pConfiguration;
};
struct S00d92900_World
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
    S00d92900_CollisionInput* m_pCollisionInput;
    const S00d92900_CollisionInput* getCollisionInput() const
    {
        return m_pCollisionInput;
    }
};
struct S00d92900_ContactPoint
{
    hkVector4f m_vContactPosition;
    float m_normalX;
    float m_normalY;
    float m_normalZ;
    float m_fClosestPointDistanceSquared;
    void setDistance(float d)
    {
        m_fClosestPointDistanceSquared = d;
    }
    float getDistance() const
    {
        return m_fClosestPointDistanceSquared;
    }
};
struct S00d92900_Props
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    unsigned int m_ulUserData;
    unsigned char m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned char m_usFlags;
    unsigned char m_flags;
    float m_uiUserData;
    float getFriction() const
    {
        return DAT_010c7948[m_fSlipAngle];
    }
    float getRestitution() const
    {
        return (float)(m_fElasticity * DAT_010cc8d0);
    }
    float getMaxImpulsePerStep()
    {
        return DAT_010c7948[m_usFlags];
    }
    unsigned int* getStartOfExtendedUserData(const struct S00d92900_Atom* atom)
    {
        return (unsigned int*)(this + 1);
    }
};
struct S00d92900_PropsStream
{
    S00d92900_Props* asProperties()
    {
        return (S00d92900_Props*)this;
    }
};
struct S00d92900_Atom
{
    unsigned short m_type;
    unsigned short m_usSizeOfAllAtoms;
    unsigned short m_usNumContactPoints;
    unsigned short m_usMaxNumContactPoints;
    unsigned char m_ucNumReservedContactPoints;
    unsigned char m_ucNumContactPointProperties;
    unsigned char m_ucContactPointPropertiesStriding;
    unsigned char unk0b;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S00d92900_ContactPoint* getContactPoints() const
    {
        return (S00d92900_ContactPoint*)(this + 1);
    }
    S00d92900_PropsStream* getContactPointPropertiesStream() const
    {
        return (S00d92900_PropsStream*)(getContactPoints() + m_usMaxNumContactPoints);
    }
    int getContactPointPropertiesStriding() const
    {
        return m_ucContactPointPropertiesStriding;
    }
};
struct S00d92900_Event;
struct S00d92900_Bool
{
    char m_cBooleanValue;
    S00d92900_Bool()
    {}
    S00d92900_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct S00d92900_Body
{
    int unk00;
    int unk04;
    S00d92900_World* m_pOwningWorld;
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    __m128 m_kInertiaAndMassInv;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    void* m_contactListenersData;
    unsigned short m_contactListenersSize;
    S00d92900_World* getWorld() const
    {
        return m_pOwningWorld;
    }
    float getMassInv() const
    {
        float r;
        _mm_store_ss(&r, _mm_shuffle_ps(m_kInertiaAndMassInv, m_kInertiaAndMassInv, 255));
        return r;
    }
};
struct S00d92900_CbReq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned char m_ucCallbackRequest;
};
struct S00d92900_Instance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S00d92900_Body* m_kActorEntries[2];
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S00d92900_CbReq* m_pConstraintInternal;
    S00d92900_Body* getRigidBodyA() const
    {
        return m_kActorEntries[0];
    }
    S00d92900_Body* getRigidBodyB() const
    {
        return m_kActorEntries[1];
    }
};
struct S00d92900_Accum
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
    hkVector4f m_com;
    const float* getCenterOfMassInWorld() const
    {
        return &m_com.x;
    }
};
struct S00d92900_Mgr;

struct S00d92900_CollisionEvent
{
    int m_pObservedSource;
    S00d92900_Body* m_apEntities[2];
    S00d92900_Mgr* m_pContactManager;
    S00d92900_CollisionEvent(int source, S00d92900_Body* bodyA, S00d92900_Body* bodyB, S00d92900_Mgr* mgr)
        : m_pObservedSource(source), m_pContactManager(mgr)
    {
        m_apEntities[0] = bodyA;
        m_apEntities[1] = bodyB;
    }
};
struct S00d92900_Event : S00d92900_CollisionEvent
{
    int m_type;
    S00d92900_ContactPoint* m_vContactPoint;
    S00d92900_Props* m_pContactPointProperties;
    S00d92900_Bool m_bFullManifold;
    S00d92900_Bool m_bFirstCallback;
    S00d92900_Bool m_bLastCallback;
    float* m_pfSeparatingVelocity;
    float* m_pfRotationalNormal;
    unsigned int* m_puiKeyStorage;
    S00d92900_Accum* m_pVelocityAccumulatorA[2];
    S00d92900_Event(int source, S00d92900_Body* a, S00d92900_Body* b, S00d92900_Mgr* mgr, int type,
                    S00d92900_ContactPoint* cp, S00d92900_Props* cpp, float* sepVel, float* rotNorm,
                    S00d92900_Bool fullManifold, S00d92900_Bool firstCallback, S00d92900_Bool lastCallback,
                    unsigned int* keyStorage, S00d92900_Accum* accA, S00d92900_Accum* accB)
        : S00d92900_CollisionEvent(source, a, b, mgr), m_type(type), m_vContactPoint(cp),
          m_pContactPointProperties(cpp), m_bFullManifold(fullManifold), m_bFirstCallback(firstCallback),
          m_bLastCallback(lastCallback), m_pfSeparatingVelocity(sepVel), m_pfRotationalNormal(rotNorm),
          m_puiKeyStorage(keyStorage)
    {
        m_pVelocityAccumulatorA[0] = accA;
        m_pVelocityAccumulatorA[1] = accB;
    }
};
struct __declspec(align(16)) S00d92900_BreachInfo
{
    unsigned short m_type;
    unsigned short m_usSecondaryField;
    S00d92900_Instance* m_pConstraintChainInstance;
    S00d92900_Props* m_kProperties;
    S00d92900_ContactPoint* m_vContactPoint;
    void set(S00d92900_Instance* instance, S00d92900_Props* properties, S00d92900_ContactPoint* cp, bool toi)
    {
        m_type = 1 + toi;
        m_usSecondaryField = true;
        m_pConstraintChainInstance = instance;
        m_vContactPoint = cp;
        m_kProperties = properties;
    }
};
