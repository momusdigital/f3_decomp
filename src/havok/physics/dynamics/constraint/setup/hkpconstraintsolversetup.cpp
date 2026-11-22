#include "f3_common.h"
// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct State
{
    int unk00;
    void* owner;
    int unk08;
    int eventCode;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* resetA;
    int unk24;
    void* desiredA;
    void* currentA;
    void* resetB;
    int unk34;
    void* desiredB;
    void* currentB;
    int callbackFlags;
    int unk44;
    volatile float* end;
    volatile float* current;
};
void __cdecl FUN_00d8aac0(void* owner, void* current, int eventCode, int flags);
// Optionally resets currentA/currentB to their reset values, zeroes the float range up to end, and notifies callbacks when current differs from desired.
// @fnv 0x00d88340
// pdb: hkpConstraintSolverSetup::subSolve | hkpConstraintSolverSetup.obj | tesv_win, call_gap, low
void __cdecl FUN_00d88340(State* state, int reset)
{
    if (reset == 0)
    {
        state->currentA = state->resetA;
        state->currentB = state->resetB;
    }
    volatile float* p = state->current;
    while (p < state->end)
    {
        *p = 0.0f;
        ++p;
    }
    state->current = state->end;
    if (state->currentA != state->desiredA)
        FUN_00d8aac0(state->owner, state->currentA, state->eventCode, state->callbackFlags);
    if (state->currentB != state->desiredB)
        FUN_00d8aac0(state->owner, state->currentB, state->eventCode, state->callbackFlags);
    state->currentA = state->desiredA;
    state->currentB = state->desiredB;
}

struct D88310Bool
{
    char m_cBooleanValue;

    D88310Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct D88310Stream
{
    int unk00;
    int unk04;
    int unk08;
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pTileTemplate;
};

// @fnv 0x00d88310
D88310Bool __cdecl FUN_00d88310(const D88310Stream* stream, const void* unused, int numBlocks)
{
    int available = (int)(stream->m_kRayEnd - stream->m_pTileTemplate);
    if (stream->m_pTileTemplate == stream->m_kRayStart)
        numBlocks++;
    if (numBlocks * 128 > available - 16)
        return false;
    return true;
}

struct D88470Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short amountA;
    unsigned short unk16;
    unsigned short amountB;
    unsigned short unk1a;
};

struct D88470Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char type;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    D88470Sub* sub;
};

struct D88470Obj
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
    unsigned int limitA;
    unsigned int initA;
    int unk2c;
    int unk30;
    unsigned int limitB;
    unsigned int initB;
    int unk3c;
    int unk40;
    unsigned int limitSum;
    unsigned int initSum;
};

// Accumulates amountA per element type and amountB*4 into totals, then returns true if the sums stay within obj's limitSum, limitA and limitB.
// @f3 0x00a0aad0 (community match, verified in this file)
struct TotalsElementView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char type;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    int unk20;
    int unk24;
    D88470Sub* sub;
};
// pdb: hkpConstraintSolverSetup::internalIsMemoryOkForNewJacobianSchemas | hkpConstraintSolverSetup.obj | fnv360_0822_debug, objrun_sim, low
// pdb params: s, constraints, numConstraints
D88310Bool __cdecl CheckTotalsWithinLimits(D88470Obj* obj, D88470Elem** begin, int count)
{
    unsigned int totals[2];
    totals[0] = obj->initA;
    totals[1] = obj->initB;
    unsigned int sum = obj->initSum;
    D88470Elem** end = begin + count;
    if (begin < end)
    {
        D88470Elem** p = begin;
        do
        {
            TotalsElementView* pElem = reinterpret_cast<TotalsElementView*>(*p);
            unsigned int uiTypeIndex = pElem->type >= 4 ? 1 : 0;
            D88470Sub* s = pElem->sub;
            sum += s->amountB * 4;
            totals[uiTypeIndex] += s->amountA;
            ++p;
        } while (p < end);
    }
    if (sum <= obj->limitSum && totals[0] + 4 <= obj->limitA && totals[1] + 4 <= obj->limitB)
        return true;
    else
        return false;
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D886
{
    __m128 m_vComponents;

    hkVector4D886()
    {}
    hkVector4D886(const hkVector4D886& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D886& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct hkpVelocityAccumulatorD886
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02, unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0C;
    hkVector4D886 m_vLinearVelocity;
    hkVector4D886 m_vAngularVelocity;
    hkVector4D886 m_vInverseInertiaAndMass;
    hkVector4D886 m_vCenterOfMass;
    hkVector4D886 m_scratch1;
    hkVector4D886 m_scratch2;
    hkVector4D886 m_scratch3;

    void setFixed()
    {
        m_fGravityFactor = 0.0f;
        m_type = 1;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        m_vCenterOfMass.setZero4();
        m_scratch1.setZero4();
        m_scratch2.setZero4();
        m_scratch3.setZero4();
    }
};

struct hkStepInfoD886;

struct hkpEntityD886
{
    unsigned int unk00[41];
    unsigned int m_uiFilterInfo;
};

hkpVelocityAccumulatorD886* __cdecl FUN_00d29830(const hkStepInfoD886* pkInfo, hkpEntityD886* const* ppkEntities,
                                                 unsigned int uiNumEntities, int iMotionOffset,
                                                 hkpVelocityAccumulatorD886* pkAccumulatorsOut);

struct S88_Allocator;

struct S88_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_Allocator* m_pStreamAllocator;
    S88_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S88_Router* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(S88_Allocator& a, void* array, int sizeElem);

template <typename T> struct S88_PadSpu
{
    T m_kStorage;
    void operator=(T v)
    {
        m_kStorage = v;
    }
    operator T() const
    {
        return m_kStorage;
    }
    T val() const
    {
        return m_kStorage;
    }
};

struct S88_Transform
{
    hkVector4D886 c0, c1, c2, t;
};

struct S88_MotionState
{
    S88_Transform m_kMotionTransform;
    const S88_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

struct S88_Motion
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_MotionState m_kMotionState;
    const S88_MotionState* GetMotionState() const
    {
        return &m_kMotionState;
    }
};

struct S88_Collidable
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
    float m_fAllowedPenetrationDepth;
};

struct S88_Entity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_Collidable m_kCollidable;
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
    unsigned int m_uiFilterInfo;
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
    S88_Motion m_pMotionState;
    S88_Motion* getMotion()
    {
        return &m_pMotionState;
    }
    const S88_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
};

struct S88_Atom
{
    short m_type;
};

struct S88_QueryIn;

struct S88_ConstraintData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int getType() const;
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void BuildJacobianCallback(const S88_QueryIn& in);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S88_Atom* m_pAtom;
};

struct S88_Internal
{
    int unk00;
    S88_Entity* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char unk13;
    int unk14;
    unsigned short m_iSolverElementTemporaryCount;
    short unk1A;
    void* m_pRuntime;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
};

struct S88_Instance
{
    int unk00;
    int unk04;
    int unk08;
    S88_ConstraintData* m_data;
    int unk10;
    int unk14;
    int unk18;
    unsigned char m_priority;
    unsigned char unk1D;
    unsigned char unk1E;
    unsigned char unk1F;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S88_Internal* m_pConstraintInternal;
    int getPriority() const
    {
        return m_priority;
    }
    S88_Internal* getInternal()
    {
        return m_pConstraintInternal;
    }
    const S88_ConstraintData* getData() const
    {
        return m_data;
    }
    S88_ConstraintData* getDataRw() const
    {
        return m_data;
    }
    void* getRuntime() const
    {
        return m_pConstraintInternal->m_pRuntime;
    }
};

struct S88_QueryIn
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
    S88_PadSpu<const hkpVelocityAccumulatorD886*> m_pBodyA;
    S88_PadSpu<const hkpVelocityAccumulatorD886*> m_pBodyB;
    S88_PadSpu<const S88_Transform*> m_kBodyALocalFrame;
    S88_PadSpu<const S88_Transform*> m_kBodyBLocalFrame;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    S88_PadSpu<S88_Instance*> m_pConstraintChainInstance;
    S88_PadSpu<void*> m_pByteBuffer;
    int unk68;
    S88_PadSpu<unsigned int> m_uiParameterA;
    S88_PadSpu<unsigned int> m_uiParameterB;
    S88_PadSpu<void*> m_pUserData;
};

struct S88_Schema;

struct S88_QueryOut
{
    S88_PadSpu<S88_Schema*> m_pQueryResultSchema;
};

struct S88_BufferState
{
    S88_Schema* m_pRayStart;
    S88_Schema* m_kRayEnd;
    S88_Schema* m_pTileTemplate;
    S88_Schema* m_pValues;
};

struct S88_Backup
{
    hkVector4D886 m_kTranslationalVelocity;
    hkVector4D886 m_kAngularVelocity;
};

struct S88_Resources
{
    void* m_pStepInfo;
    void* m_pSolverInfo;
    S88_QueryIn* m_pConstraintQueryIn;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorA;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorB;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorC;
    S88_Backup* m_pBodyABackup;
    S88_Backup* m_pBodyBBackup;
    S88_BufferState m_akBufferStates[2];
    char* m_pBufferA;
    char* m_pBufferB;
    char* m_pBufferC;
    char* m_pBufferD;
};

struct S88_SchemaInfo
{
    S88_Instance* m_pHavokConstraint;
    S88_Schema* m_pConstraintSchema;
    float m_fAllowedPenetrationDepth;
};

struct S88_Array
{
    S88_SchemaInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    S88_SchemaInfo& AllocatePair()
    {
        S88_Allocator& alloc = FUN_00c85750()->heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(S88_SchemaInfo));
        }
        return m_data[m_iElementCount++];
    }
};

template <typename T> inline T* S88_addByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

template <typename T> inline T S88_min2(T x, T y)
{
    return x < y ? x : y;
}

void __cdecl FUN_00d92900(S88_ConstraintData* data, const S88_QueryIn* in, S88_Atom* atom, int type);
void __cdecl FUN_00d72190(S88_Atom* atom, const S88_QueryIn& in, D88310Bool writeHeader, S88_QueryOut& out);
void __cdecl FUN_00d6f460(const S88_Atom* atoms, int atomsSize, const S88_QueryIn& in, S88_QueryOut& out);

inline void S88_buildJacobianFromAtoms(S88_Atom* atoms, int atomsSize, const S88_QueryIn& in, S88_QueryOut& out)
{
    if (atoms->m_type == 0x16)
    {
        FUN_00d72190(atoms, in, D88310Bool(true), out);
    }
    else
    {
        FUN_00d6f460(atoms, atomsSize, in, out);
    }
}

// @f3 0x00a0ac60 (community match, verified in this file)
struct Native_S88_Allocator_a0ac60;
struct Native_S88_Router_a0ac60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Native_S88_Allocator_a0ac60* m_pStreamAllocator;
    Native_S88_Allocator_a0ac60& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(Native_S88_Allocator_a0ac60& a, void* array, int sizeElem);
template <typename T> struct NativePad_a0ac60
{
    T m_kStorage;
    void operator=(T v)
    {
        m_kStorage = v;
    }
    operator T() const
    {
        return m_kStorage;
    }
    T val() const
    {
        return m_kStorage;
    }
};

struct Native_S88_MotionState_a0ac60
{
    S88_Transform m_kMotionTransform;
    const S88_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
};
struct Native_S88_Motion_a0ac60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Native_S88_MotionState_a0ac60 m_kMotionState;
    const Native_S88_MotionState_a0ac60* GetMotionState() const
    {
        return &m_kMotionState;
    }
};
struct Native_S88_Collidable_a0ac60
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

    float m_fAllowedPenetrationDepth;
};
struct Native_S88_Entity_a0ac60 {
 int unk00,unk04,unk08,unk0c;
 Native_S88_Collidable_a0ac60 m_kCollidable;
 int unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c;
 unsigned int m_uiFilterInfo;
 int unk94,unk98,unk9c,unkA0,unkA4,unkA8,unkAC,unkB0,unkB4,unkB8,unkBC,unkC0,unkC4,unkC8,unkCC;
 Native_S88_Motion_a0ac60 m_pMotionState;
 Native_S88_Motion_a0ac60* getMotion() {return &m_pMotionState;}
 const Native_S88_Collidable_a0ac60* getCollidable() const {return &m_kCollidable;}
};

struct NC88_QueryIn;
struct NC88_ConstraintData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int getType() const;
    virtual void v24();
    virtual void BuildJacobianCallback(const NC88_QueryIn& in);
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S88_Atom* m_pAtom;
};
struct Native_S88_Internal_a0ac60
{
    int unk00;
    Native_S88_Entity_a0ac60* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char unk13;
    int unk14;
    unsigned short m_iSolverElementTemporaryCount;
    short unk1A;
    void* m_pRuntime;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
};
struct NC88_Instance
{
    int unk00;
    int unk04;
    int unk08;
    NC88_ConstraintData* m_data;
    int unk10;
    int unk14;
    int unk18;
    unsigned char m_priority;
    unsigned char unk1D;
    unsigned char unk1E;
    unsigned char unk1F;
    int unk20;
    int unk24;


    Native_S88_Internal_a0ac60* m_pConstraintInternal;
    int getPriority() const
    {
        return m_priority;
    }
    Native_S88_Internal_a0ac60* getInternal()
    {
        return m_pConstraintInternal;
    }
    const NC88_ConstraintData* getData() const
    {
        return m_data;
    }
    NC88_ConstraintData* getDataRw() const
    {
        return m_data;
    }
    void* getRuntime() const
    {
        return m_pConstraintInternal->m_pRuntime;
    }
};
struct NC88_QueryIn
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
    NativePad_a0ac60<const hkpVelocityAccumulatorD886*> m_pBodyA;
    NativePad_a0ac60<const hkpVelocityAccumulatorD886*> m_pBodyB;
    NativePad_a0ac60<const S88_Transform*> m_kBodyALocalFrame;
    NativePad_a0ac60<const S88_Transform*> m_kBodyBLocalFrame;
    int unk40;
    int unk44;






    NativePad_a0ac60<NC88_Instance*> m_pConstraintChainInstance;
    NativePad_a0ac60<void*> m_pByteBuffer;

    NativePad_a0ac60<unsigned int> m_uiParameterA;
    NativePad_a0ac60<unsigned int> m_uiParameterB;
    NativePad_a0ac60<void*> m_pUserData;
};
struct Native_S88_Schema_a0ac60 {unsigned int opcode;};
struct Native_S88_QueryOut_a0ac60
{
    NativePad_a0ac60<Native_S88_Schema_a0ac60*> m_pQueryResultSchema;
};
struct Native_S88_BufferState_a0ac60
{
    Native_S88_Schema_a0ac60* m_pRayStart;
    Native_S88_Schema_a0ac60* m_kRayEnd;
    Native_S88_Schema_a0ac60* m_pTileTemplate;
    Native_S88_Schema_a0ac60* m_pValues;
};
struct Native_S88_Backup_a0ac60
{
    hkVector4D886 m_kTranslationalVelocity;
    hkVector4D886 m_kAngularVelocity;
};
struct NC88_Resources
{
    void* m_pStepInfo;
    void* m_pSolverInfo;
    NC88_QueryIn* m_pConstraintQueryIn;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorA;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorB;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorC;
    Native_S88_Backup_a0ac60* m_pBodyABackup;
    Native_S88_Backup_a0ac60* m_pBodyBBackup;
    Native_S88_BufferState_a0ac60 m_akBufferStates[2];
    char* m_pBufferA;
    char* m_pBufferB;
    char* m_pBufferC;
    char* m_pBufferD;
};
struct Native_S88_SchemaInfo_a0ac60
{
    NC88_Instance* m_pHavokConstraint;
    Native_S88_Schema_a0ac60* m_pConstraintSchema;
    float m_fAllowedPenetrationDepth;
};
struct NC88_Array;
void __cdecl FUN_00901f10(NC88_Array*,int);
struct NC88_Array {
 Native_S88_SchemaInfo_a0ac60* m_data; int m_iElementCount,m_iCapacityState;
 int getCapacity() const {return m_iCapacityState&0x3fffffff;}
 Native_S88_SchemaInfo_a0ac60& AllocatePair();
};


void __cdecl FUN_00d92900(NC88_ConstraintData* data, const NC88_QueryIn* in, S88_Atom* atom, int type);
void __cdecl FUN_00d72190(S88_Atom* atom, const NC88_QueryIn& in, D88310Bool writeHeader, Native_S88_QueryOut_a0ac60& out);
void __cdecl FUN_00d6f460(const S88_Atom* atoms, int atomsSize, const NC88_QueryIn& in, Native_S88_QueryOut_a0ac60& out);
void __cdecl hkSimpleContactConstraintData_fireCallbacks(NC88_ConstraintData*,const NC88_QueryIn*,S88_Atom*);
void __cdecl FUN_00a00ec0(S88_Atom*,const NC88_QueryIn&,D88310Bool,Native_S88_QueryOut_a0ac60&);
void __cdecl FUN_009fccc0(const S88_Atom*,int,const NC88_QueryIn&,Native_S88_QueryOut_a0ac60&);
inline void S88_buildCurrentJacobianFromAtoms(S88_Atom* atoms,int size,const NC88_QueryIn& in,Native_S88_QueryOut_a0ac60& out) {
 if(atoms->m_type==0x16) FUN_00a00ec0(atoms,in,D88310Bool(true),out);
 else FUN_009fccc0(atoms,size,in,out);
}
Native_S88_SchemaInfo_a0ac60& NC88_Array::AllocatePair() {
 if(m_iElementCount==getCapacity()) FUN_00901f10(this,sizeof(Native_S88_SchemaInfo_a0ac60));
 return m_data[m_iElementCount++];
}
inline void CopyNativeVector(hkVector4D886& dst,const hkVector4D886& src) {
 dst.m_vComponents.m128_f32[0]=src.m_vComponents.m128_f32[0];
 dst.m_vComponents.m128_f32[1]=src.m_vComponents.m128_f32[1];
 dst.m_vComponents.m128_f32[2]=src.m_vComponents.m128_f32[2];
 dst.m_vComponents.m128_f32[3]=src.m_vComponents.m128_f32[3];
}
inline void ZeroNativeVector(hkVector4D886& dst) {dst.m_vComponents.m128_f32[0]=dst.m_vComponents.m128_f32[1]=dst.m_vComponents.m128_f32[2]=dst.m_vComponents.m128_f32[3]=0.0f;}
// pdb: hkpConstraintSolverSetup::internalAddJacobianSchemas | hkpConstraintSolverSetup.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: s, constraints, numConstraints, constraintStatus
void __cdecl FUN_00d88760(S88_Resources& packS, S88_Instance** packConstraints, int numConstraints, S88_Array& packStatus)
{
    NC88_Resources& s = reinterpret_cast<NC88_Resources&>(packS);
    NC88_Instance** constraints = reinterpret_cast<NC88_Instance**>(packConstraints);
    NC88_Array& constraintStatus = reinterpret_cast<NC88_Array&>(packStatus);
    NC88_QueryIn& in = *s.m_pConstraintQueryIn;
    Native_S88_QueryOut_a0ac60 out;

    for (NC88_Instance **cp = constraints, **end = constraints + numConstraints; cp < end; cp++)
    {
        NC88_Instance* instance = *cp;
        int prio = (instance->getPriority() == 4);
        Native_S88_Entity_a0ac60** entities = &instance->getInternal()->m_kActorEntries[0];
        Native_S88_Motion_a0ac60* motionA = entities[0]->getMotion();
        Native_S88_Motion_a0ac60* motionB = entities[1]->getMotion();

        hkpVelocityAccumulatorD886* pAccumulatorA =
            S88_addByteOffset(s.m_pVelocityAccumulatorA, entities[0]->m_uiFilterInfo);
        hkpVelocityAccumulatorD886* pAccumulatorB =
            S88_addByteOffset(s.m_pVelocityAccumulatorA, entities[1]->m_uiFilterInfo);
        in.m_pBodyA = pAccumulatorA;
        in.m_pBodyB = pAccumulatorB;

        Native_S88_Backup_a0ac60* backupA = &s.m_pBodyABackup[entities[0]->m_uiFilterInfo >> 7];
        Native_S88_Backup_a0ac60* backupB = &s.m_pBodyABackup[entities[1]->m_uiFilterInfo >> 7];
        CopyNativeVector(pAccumulatorA->m_vCenterOfMass,backupA->m_kTranslationalVelocity);
        CopyNativeVector(pAccumulatorA->m_scratch1,backupA->m_kAngularVelocity);
        CopyNativeVector(pAccumulatorB->m_vCenterOfMass,backupB->m_kTranslationalVelocity);
        CopyNativeVector(pAccumulatorB->m_scratch1,backupB->m_kAngularVelocity);

        const Native_S88_MotionState_a0ac60* pMotionStateA = motionA->GetMotionState();
        const Native_S88_MotionState_a0ac60* pMotionStateB = motionB->GetMotionState();
        in.m_kBodyALocalFrame = &pMotionStateA->getTransform();
        in.m_kBodyBLocalFrame = &pMotionStateB->getTransform();
        in.m_pConstraintChainInstance = instance;
        in.m_pByteBuffer = instance->getRuntime();
        in.m_uiParameterA = (unsigned short)(entities[0]->m_uiFilterInfo >> 7);
        in.m_uiParameterB = (unsigned short)(entities[1]->m_uiFilterInfo >> 7);
        in.m_pUserData = instance->getRuntime();

        Native_S88_SchemaInfo_a0ac60& info = constraintStatus.AllocatePair();
        info.m_pHavokConstraint = instance;
        info.m_pConstraintSchema = s.m_akBufferStates[prio].m_pTileTemplate;
        info.m_fAllowedPenetrationDepth = S88_min2(entities[0]->getCollidable()->m_fAllowedPenetrationDepth,
                                                   entities[1]->getCollidable()->m_fAllowedPenetrationDepth);

        out.m_pQueryResultSchema = s.m_akBufferStates[prio].m_pTileTemplate;

        if(instance->getInternal()->m_ucCallbackRequest&1) {
            NC88_ConstraintData* data=instance->getDataRw();
            hkSimpleContactConstraintData_fireCallbacks(data,&in,data->m_pAtom);
        }

        if (instance->m_pConstraintInternal->m_ucCallbackRequest & 4)
        {
            instance->getDataRw()->BuildJacobianCallback(in);
        }

        S88_buildCurrentJacobianFromAtoms(instance->m_pConstraintInternal->getAtoms(),
                                   instance->m_pConstraintInternal->getAtomsSize(), in, out);

        s.m_akBufferStates[prio].m_pTileTemplate = out.m_pQueryResultSchema;
        s.m_pBufferC += instance->m_pConstraintInternal->m_iSolverElementTemporaryCount * 4;

        ZeroNativeVector(pAccumulatorA->m_vCenterOfMass);
        ZeroNativeVector(pAccumulatorA->m_scratch1);
        ZeroNativeVector(pAccumulatorB->m_vCenterOfMass);
        ZeroNativeVector(pAccumulatorB->m_scratch1);
    }

    s.m_akBufferStates[0].m_pTileTemplate->opcode=0;
    s.m_akBufferStates[1].m_pTileTemplate->opcode=0;
}


struct S883_Vector4
{
    __m128 m_vComponents;
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void operator=(const S883_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct S883_Matrix3
{
    S883_Vector4 m_kColumn0;
    S883_Vector4 m_kColumn1;
    S883_Vector4 m_kColumn2;
    __forceinline S883_Vector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void setZero()
    {
        S883_Vector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
};

struct S883_Accumulator
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0c;
    S883_Vector4 m_vLinearVelocity;
    S883_Vector4 m_vAngularVelocity;
    S883_Vector4 m_vInverseInertiaAndMass;
    S883_Vector4 m_vCenterOfMass;
    S883_Matrix3 m_kCoreFromWorldMatrix;

    __forceinline S883_Vector4& getCenterOfMassInWorld()
    {
        return m_vCenterOfMass;
    }
    __forceinline S883_Matrix3& getCoreFromWorldMatrix()
    {
        return m_kCoreFromWorldMatrix;
    }
    __forceinline void setFixed()
    {
        m_type = 1;
        m_fGravityFactor = 0.0f;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        getCenterOfMassInWorld().setZero4();
        getCoreFromWorldMatrix().setZero();
    }
};

struct S883_EntityArray
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct S883_Island
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int m_iSchemaByteSize;
    int unk10;
    int m_iSolverElementTemporaryCount;
    int unk18;
    int m_maxConstraintInfoSize;
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
    S883_EntityArray m_kActorEntries;
    __forceinline const S883_EntityArray& GetEntities() const
    {
        return m_kActorEntries;
    }
};

struct S883_TaskHeader
{
    int m_iJobId;
    int m_iValueAt04;
    int m_iValueAt08;
    long m_sReferenceCount;
    int m_iValueAt10;
    void* m_buffer;
    int m_iBufferSize;
    int m_iValueAt1C;
    char m_cValueAt20;
    char m_bSplitCheckRequested;
    void* m_pPointerAt24;
    int unk28;
    int unk2c;
    S883_Accumulator* m_pAccumulatorA;
    void* m_pVelocityAccumulatorB;
    short m_usValueAt38;
    short m_usValueAt3A;
    void* m_pByteArrayAt3C;
    void* m_pIntegerArrayAt40;
};

// Lays out accumulator, schema and solver-element-temporary regions in buffer, sets taskHeader pointers and sizes, and initialises the first accumulator as fixed.
// @f3 0x00a0a680 (community match, verified in this file)
struct __declspec(align(16)) Vector537 {
    float x,y,z,w;
    __forceinline void Zero(){x=y=z=w=0.0f;}
    __forceinline Vector537& operator=(const Vector537& value){x=value.x;y=value.y;z=value.z;w=value.w;return *this;}
};
struct Accumulator537 {
    unsigned char type,mode,unk02,unk03;unsigned int deactivation;float gravity;unsigned int unk0c;
    Vector537 linear,angular,mass,center;
    Vector537 matrix[3];
    __forceinline void Fixed() {
        type=1;mode=1;mass.Zero();linear.Zero();angular.Zero();center.Zero();
        Vector537 zero;zero.Zero();matrix[0]=zero;matrix[1]=zero;matrix[2]=zero;
    }
};
// pdb: hkConstraintSolverSetup_integrate2 | hkpConstraintSolverSetup.obj | fnv360_0822_debug, objrun, low, conflict (skyrim: hkpConstraintSolverSetup::calcBufferOffsetsForSolve)
int __cdecl FUN_00d883c0(const S883_Island& island,char* buffer,int bufferSize,S883_TaskHeader& header) {
    header.m_buffer=buffer;
    int count=island.GetEntities().GetLogicalSize();
    header.m_pAccumulatorA=reinterpret_cast<S883_Accumulator*>(buffer);
    int accumulatorSize=island.GetEntities().GetLogicalSize()*sizeof(Accumulator537)+0x90;
    buffer+=accumulatorSize;
    int blocks=(island.m_maxConstraintInfoSize/0x90+4)*2;
    header.m_pByteArrayAt3C=buffer;
    int schemaSize=island.m_iSchemaByteSize+16+(blocks<<4);buffer+=schemaSize;
    int temporarySize=(island.m_iSolverElementTemporaryCount*4+8+blocks*12+15)&~15;
    header.m_pIntegerArrayAt40=buffer;buffer+=temporarySize;
    int size=static_cast<int>(buffer-static_cast<char*>(header.m_buffer));header.m_iBufferSize=size;
    if(header.m_buffer){Accumulator537* accum=reinterpret_cast<Accumulator537*>(header.m_pAccumulatorA);accum->Fixed();accum[count+1].type=3;}
    return size;
}


extern "C" void _mm_prefetch(char const*, int);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;

// hkMemoryAllocator
struct S88b50_Allocator
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n;
        return static_cast<T*>(p);
    }
    template <typename T> void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem);
    }
};
struct S88b50_Stack
{
    char* m_pTileTemplate;
    int unk04;
    int unk08;
    void* allocateStack(int numBytes)
    {
        char* current = m_pTileTemplate;
        m_pTileTemplate = current + numBytes;
        return current;
    }
};
struct S88b50_Router
{
    S88b50_Stack m_aiEntries;
    S88b50_Allocator* m_pTemp;
    S88b50_Allocator* m_pStreamAllocator;
    S88b50_Allocator* m_pDebugAllocator;
    S88b50_Allocator* m_pSolver;
    S88b50_Stack& stack()
    {
        return m_aiEntries;
    }
    S88b50_Allocator& temp()
    {
        return *m_pTemp;
    }
    S88b50_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
    S88b50_Allocator& solver()
    {
        return *m_pSolver;
    }
    static S88b50_Router& GetMonitorStream()
    {
        return *(S88b50_Router*)FUN_00c85750();
    }
};
static __forceinline char* S88b50_allocateStack(int n)
{
    S88b50_Router& mem = S88b50_Router::GetMonitorStream();
    return static_cast<char*>(mem.stack().allocateStack((n + 127) & ~127));
}

struct S88b50_ConstraintInternal
{
    S88_Instance* m_pHavokConstraint;
    struct S88b50_Entity* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char m_priority;
    int unk14;
    int unk18;
    void* m_pRuntime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
    int getPriority() const
    {
        return m_priority;
    }
};
struct S88b50_SmallArray
{
    S88b50_ConstraintInternal* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    const S88b50_ConstraintInternal* begin() const
    {
        return m_data;
    }
    const S88b50_ConstraintInternal* end() const
    {
        return m_data + m_iElementCount;
    }
};
// hkpEntity
struct S88b50_PtrArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
// hkpWorld
struct S88b50_World
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pSimulation;
    int unk0C;
    hkVector4D886 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    S88b50_PtrArray m_kActiveSimulationIslands;
    S88b50_PtrArray m_kInactiveSimulationIslands;
    S88b50_PtrArray m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore;
    void* m_pKdTreeManager;
    char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher;
    void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener;
    void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput;
    void* getCollisionInput() const
    {
        return m_pCollisionInput;
    }
};
// hkpCdBody
struct S88b50_CdBody
{
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S88b50_CdBody* m_parent;
    const S88_Transform& getTransform() const
    {
        return *(const S88_Transform*)m_pMotionState;
    }
};
// hkpLinkedCollidable
struct S88b50_Collidable : S88b50_CdBody
{
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;
    signed char m_broadPhaseOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    unsigned int m_bvMin0;
    unsigned int m_bvMin1;
    unsigned int m_bvMin2;
    unsigned int m_bvExpansionMinAndShift;
    unsigned int m_bvMax0;
    unsigned int m_bvMax1;
    unsigned int m_bvMax2;
    unsigned int m_bvExpansionMaxAndPadding;
    unsigned short m_bvNumChildShapeAabbs;
    unsigned short m_bvCapacityChildShapeAabbs;
    void* m_bvChildShapeAabbs;
    void* m_bvChildShapeKeys;
    float m_fAllowedPenetrationDepth;
    S88b50_PtrArray m_kCollisionEntries;
};
// hkpEntity
struct S88b50_Entity
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S88b50_World* m_pOwningWorld;
    unsigned int m_ulUserData;
    S88b50_Collidable m_kCollidable;
    unsigned int m_mtThreadId;
    unsigned short m_mtMarkCount;
    unsigned short m_mtMarkBitStack;
    const char* m_name;
    S88b50_PtrArray m_kProperties;
    void* m_kNextStreamField;
    void* m_pWorldObjectOwner;
    signed char m_materialResponseType;
    float m_materialFriction;
    float m_materialRestitution;
    void* m_pEntityUserData;
    float m_fBulletSpread;
    void* m_pShape;
    unsigned int m_uiFilterInfo;
    unsigned short m_usStorageIndex;
    unsigned short m_usNextProcessCallbackDelay;
    S88b50_SmallArray m_eSmallArraySerializeOverrideType;
    S88b50_PtrArray m_kSlaveConstraints;
    S88b50_PtrArray m_pByteBuffer;
    void* m_pSimulationIsland;
    signed char m_iAutoRemoveLevel;
    unsigned char m_ucNumShapeKeysInContactPointProperties;
    unsigned char m_ucResponseModifierFlags;
    unsigned int m_uiUniqueId;
    void* m_spuCallbackUtil;
    unsigned short m_spuCallbackCapacity;
    unsigned char m_spuCallbackEventFilter;
    unsigned char m_spuCallbackUserFilter;
    S88_Motion m_pMotionState;
    S88_Motion* getMotion()
    {
        return &m_pMotionState;
    }
    const S88b50_SmallArray& getConstraintMasters() const
    {
        return m_eSmallArraySerializeOverrideType;
    }
    S88b50_World* getWorld() const
    {
        return m_pOwningWorld;
    }
    const S88b50_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
};
static __forceinline S88b50_Entity* S88b50_getEntityA(const S88_Instance* i)
{
    return (S88b50_Entity*)i->unk14;
}
static __forceinline S88b50_Entity* S88b50_getEntityB(const S88_Instance* i)
{
    return (S88b50_Entity*)i->unk18;
}

// hkpSimulationIsland
struct S88b50_Island
{
    int unk00;
    int unk04;
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    void* m_pOwningWorld;
};
struct S88b50_InplaceArray
{
    const S88b50_ConstraintInternal** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const S88b50_ConstraintInternal* m_kStorage[256];
    void init()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 256 | 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const S88b50_ConstraintInternal*& operator[](int i)
    {
        return m_data[i];
    }
    void AddBack(const S88b50_ConstraintInternal* const& t)
    {
        S88b50_Allocator& alloc = S88b50_Router::GetMonitorStream().heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(*(S88_Allocator*)&alloc, this, sizeof(t));
        }
        m_data[m_iElementCount] = t;
        m_iElementCount++;
    }
    void destroy()
    {
        S88b50_Allocator& alloc = S88b50_Router::GetMonitorStream().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc._bufFree<const S88b50_ConstraintInternal*>(m_data, getCapacity() * 4);
        }
    }
};

struct S88b50_GotoSchema
{
    float m_kHeader;
    long m_offset;
    static void setType(S88b50_GotoSchema* schema, signed char type)
    {
        schema->m_kHeader = (float)(schema->m_kHeader + 1.1920928955078125e-07);
        *(signed char*)S88_addByteOffset(schema, 0) = type;
    }
    void initGoto(S88_Schema* destination)
    {
        m_offset = (char*)destination - (char*)this;
        setType(this, 2);
    }
};

struct S88b50_MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;
    static S88b50_MonitorStream& GetMonitorStream()
    {
        return *(S88b50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* e)
    {
        m_kRayEnd = e;
    }
};

struct S88b50_BreachedHeader
{
    int m_iBreachCount;
    int unk04;
    int unk08;
    int unk0C;
    void* getElem(int index)
    {
        return (char*)this + 16 + index * 32;
    }
};

template <typename T> inline T S88b50_max2(T x, T y)
{
    return x > y ? x : y;
}

int __cdecl FUN_00d29bf0(const void* solverInfo, const hkStepInfoD886* stepInfo,
                         const hkpVelocityAccumulatorD886* accums, S88b50_Entity* const* bodies, int numBodies,
                         int offset);
void __cdecl FUN_00d1a330(const void* input, S88b50_Entity* const* bodies, int numBodies);

// hkMatrix3
struct S88b50_Matrix3
{
    hkVector4D886 m_kColumn0;
    hkVector4D886 m_kColumn1;
    hkVector4D886 m_kColumn2;
    hkVector4D886& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    void setZero()
    {
        hkVector4D886 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
};
static __forceinline void S88b50_setFixed(hkpVelocityAccumulatorD886& a)
{
    a.m_type = 1;
    a.m_fGravityFactor = 0.0f;
    a.m_vInverseInertiaAndMass.setZero4();
    a.m_vLinearVelocity.setZero4();
    a.m_vAngularVelocity.setZero4();
    a.m_vCenterOfMass.setZero4();
    reinterpret_cast<S88b50_Matrix3&>(a.m_scratch1).setZero();
}

static __forceinline void S88b50_buildAccumulators(const hkStepInfoD886& info, S88b50_Entity* const* bodies,
                                                   int numBodies, hkpVelocityAccumulatorD886* accumulators)
{
    S88b50_setFixed(*accumulators);
    for (int i = 0; i < numBodies; i++)
    {
        unsigned int newVal = (i + 1) * 128;
        if (newVal != bodies[i]->m_uiFilterInfo)
        {
            bodies[i]->m_uiFilterInfo = newVal;
        }
    }
    hkpVelocityAccumulatorD886* accumEnd =
        FUN_00d29830(&info, (hkpEntityD886* const*)bodies, numBodies, 0xe0, accumulators + 1);
    accumEnd->m_type = 3;
}

template <int SIZE> inline void S88b50_forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}

static __forceinline void S88b50_buildJacobianElement(const S88b50_ConstraintInternal* c, S88_QueryIn& in,
                                                      hkpVelocityAccumulatorD886* accusIn, S88_QueryOut& out)
{
    S88b50_forcePrefetch<256>(c->getAtoms());
    if (c->getAtomsSize() > 256)
    {
        S88b50_forcePrefetch<256>(S88_addByteOffset(c->getAtoms(), 256));
        if (c->getAtomsSize() > 512)
        {
            S88b50_forcePrefetch<256>(S88_addByteOffset(c->getAtoms(), 512));
        }
    }
    S88b50_Entity* rA = c->m_kActorEntries[0];
    S88b50_Entity* rB = c->m_kActorEntries[1];
    S88_Motion* mA = rA->getMotion();
    S88_Motion* mB = rB->getMotion();
    in.m_pBodyA = S88_addByteOffset(accusIn, rA->m_uiFilterInfo);
    in.m_pBodyB = S88_addByteOffset(accusIn, rB->m_uiFilterInfo);
    in.m_kBodyALocalFrame = &mA->GetMotionState()->getTransform();
    in.m_kBodyBLocalFrame = &mB->GetMotionState()->getTransform();
    in.m_pConstraintChainInstance = c->m_pHavokConstraint;
    in.m_pByteBuffer = c->m_pRuntime;
    in.m_uiParameterA = (unsigned short)(rA->m_uiFilterInfo >> 7);
    in.m_uiParameterB = (unsigned short)(rB->m_uiFilterInfo >> 7);
    in.m_pUserData = in.m_pByteBuffer;
    S88_buildJacobianFromAtoms(c->getAtoms(), c->getAtomsSize(), in, out);
}

static __forceinline void S88b50_buildJacobianElements(S88_QueryIn& in, S88b50_Entity* const* bodies, int numBodies,
                                                       hkpVelocityAccumulatorD886* accusIn, S88_Schema* schemaOut,
                                                       S88_Schema* schemaOutEnd, S88_Schema* schemaOutB)
{
    S88_QueryOut out;
    out.m_pQueryResultSchema = schemaOut;
    S88b50_Entity* const* e = bodies;
    S88b50_Entity* const* eEnd = bodies + numBodies;
    S88b50_InplaceArray criticalConstraints;
    criticalConstraints.init();
    for (; e < eEnd; e++)
    {
        const S88b50_ConstraintInternal* c = (*e)->getConstraintMasters().begin();
        const S88b50_ConstraintInternal* cEnd = (*e)->getConstraintMasters().end();
        for (; c < cEnd; c++)
        {
            if (c->m_ucCallbackRequest & 0xd)
            {
                in.m_pConstraintChainInstance = c->m_pHavokConstraint;
                in.m_pByteBuffer = c->m_pRuntime;
                S88b50_Entity* rA = S88b50_getEntityA(c->m_pHavokConstraint);
                S88b50_Entity* rB = S88b50_getEntityB(c->m_pHavokConstraint);
                in.m_pBodyA = S88_addByteOffset(accusIn, rA->m_uiFilterInfo);
                in.m_pBodyB = S88_addByteOffset(accusIn, rB->m_uiFilterInfo);
                in.m_kBodyALocalFrame = &rA->getCollidable()->getTransform();
                in.m_kBodyBLocalFrame = &rB->getCollidable()->getTransform();
                if (c->m_ucCallbackRequest & 9)
                {
                    S88_ConstraintData* data = c->m_pHavokConstraint->getDataRw();
                    S88_Atom* atom = data->m_pAtom;
                    FUN_00d92900(data, &in, atom, 2);
                }
                if (c->m_ucCallbackRequest & 4)
                {
                    S88_ConstraintData* data = c->m_pHavokConstraint->getDataRw();
                    data->BuildJacobianCallback(in);
                }
            }
            if (c->getPriority() >= 4)
            {
                criticalConstraints.AddBack(c);
                continue;
            }
            if (out.m_pQueryResultSchema >= schemaOutEnd)
            {
                S88b50_GotoSchema* s = (S88b50_GotoSchema*)out.m_pQueryResultSchema.val();
                s->initGoto(schemaOutB);
                out.m_pQueryResultSchema = schemaOutB;
                schemaOutEnd = (S88_Schema*)-1;
            }
            S88b50_buildJacobianElement(c, in, accusIn, out);
        }
    }
    for (int i = 0; i < criticalConstraints.GetLogicalSize(); i++)
    {
        const S88b50_ConstraintInternal* c = criticalConstraints[i];
        if (out.m_pQueryResultSchema >= schemaOutEnd)
        {
            S88b50_GotoSchema* s = (S88b50_GotoSchema*)out.m_pQueryResultSchema.val();
            s->initGoto(schemaOutB);
            out.m_pQueryResultSchema = schemaOutB;
            schemaOutEnd = (S88_Schema*)-1;
        }
        S88b50_buildJacobianElement(c, in, accusIn, out);
    }
    *(int*)out.m_pQueryResultSchema.val() = 0;
    criticalConstraints.destroy();
}

static __forceinline int S88b50_integrate2(const void* solverInfo, const hkStepInfoD886& stepInfo,
                                           const hkpVelocityAccumulatorD886* accumulators, S88b50_Entity* const* bodies,
                                           int numBodies)
{
    int numInactiveFrames = FUN_00d29bf0(solverInfo, &stepInfo, accumulators + 1, bodies, numBodies, 0xe0);
    FUN_00d1a330(bodies[0]->getWorld()->getCollisionInput(), bodies, numBodies);
    return numInactiveFrames;
}

// Allocates solver buffers, builds velocity accumulators and Jacobian schemas, solves the constraint system, and integrates the island bodies.
// @f3 0x00a0b010 (community match, verified in this file)
struct hkVector4N {
    union { __m128 m_vComponents; struct {float x,y,z,w;}; };
    hkVector4N() {}
    hkVector4N(const hkVector4N& v) : x(v.x),y(v.y),z(v.z),w(v.w) {}
    void operator=(const hkVector4N& v) { w=v.w;z=v.z;y=v.y;x=v.x; }
    void setZero4() { w=z=y=x=0.0f; }
};
struct VelocityAccumulatorN
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02, unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0C;
    hkVector4N m_vLinearVelocity;
    hkVector4N m_vAngularVelocity;
    hkVector4N m_vInverseInertiaAndMass;
    hkVector4N m_vCenterOfMass;
    hkVector4N m_scratch1;
    hkVector4N m_scratch2;
    hkVector4N m_scratch3;

    void setFixed()
    {
        m_fGravityFactor = 0.0f;
        m_type = 1;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        m_vCenterOfMass.setZero4();
        m_scratch1.setZero4();
        m_scratch2.setZero4();
        m_scratch3.setZero4();
    }
};
struct TransformN
{
    hkVector4N c0, c1, c2, t;
};
struct MotionStateN
{
    TransformN m_kMotionTransform;
    const TransformN& getTransform() const
    {
        return m_kMotionTransform;
    }
};
struct MotionN
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MotionStateN m_kMotionState;
    const MotionStateN* GetMotionState() const
    {
        return &m_kMotionState;
    }
};





struct QueryInN;
struct S88_Entity;
struct S88_Atom;
struct EntityN;
struct InstanceN;
struct ConstraintInternalN
{
    InstanceN* m_pHavokConstraint;
    struct EntityN* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char m_priority;
    int unk14;
    int unk18;
    void* m_pRuntime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
    int getPriority() const
    {
        return m_priority;
    }
};
struct NativeBodyConstraints
{
    ConstraintInternalN* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    const ConstraintInternalN* begin() const
    {
        return m_data;
    }
    const ConstraintInternalN* end() const
    {
        return m_data + m_iElementCount;
    }
};

struct CdBodyN
{
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const CdBodyN* m_parent;
    const TransformN& getTransform() const
    {
        return *(const TransformN*)m_pMotionState;
    }
};

struct WorldN {
    void* vtable; unsigned short memSize; short references;
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
    void* m_pCollisionInput;
    void* getCollisionInput() const {return m_pCollisionInput;}
};
struct EntityN {
    void* m_ppVirtualMethodTable; unsigned short m_usMemSizeAndFlags; short m_sReferenceCount;
    WorldN* m_pOwningWorld; unsigned int m_ulUserData;
    CdBodyN m_kCollidable;
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
    unsigned int m_uiFilterInfo;
    unsigned short m_usStorageIndex,m_usNextProcessCallbackDelay;
    NativeBodyConstraints m_eSmallArraySerializeOverrideType;
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
    MotionN m_pMotionState;
    MotionN* getMotion() { return &m_pMotionState; }
    const CdBodyN* getCollidable() const { return &m_kCollidable; }
    const NativeBodyConstraints& getConstraintMasters() const { return m_eSmallArraySerializeOverrideType; }
    WorldN* getWorld() const { return m_pOwningWorld; }
};
struct ConstraintDataN
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int getType() const;
    virtual void v24();
    virtual void BuildJacobianCallback(const QueryInN& in);
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S88_Atom* m_pAtom;
};
struct S88_Internal;
struct InstanceN
{
    int unk00;
    int unk04;
    int unk08;
    ConstraintDataN* m_data;
    int unk10;
    EntityN* unk14;
    EntityN* unk18;
    unsigned char m_priority;
    unsigned char unk1D;
    unsigned char unk1E;
    unsigned char unk1F;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S88_Internal* m_pConstraintInternal;
    int getPriority() const
    {
        return m_priority;
    }
    S88_Internal* getInternal()
    {
        return m_pConstraintInternal;
    }
    const ConstraintDataN* getData() const
    {
        return m_data;
    }
    ConstraintDataN* getDataRw() const
    {
        return m_data;
    }
    void* getRuntime() const;
};
struct QueryInN {
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
    const VelocityAccumulatorN* m_pBodyA; const VelocityAccumulatorN* m_pBodyB;
    const TransformN* m_kBodyALocalFrame; const TransformN* m_kBodyBLocalFrame;
    int unk40,unk44;
    InstanceN* m_pConstraintChainInstance;
    void* m_pByteBuffer;
    unsigned int m_uiParameterA,m_uiParameterB;
    void* m_pUserData;
};
struct NativeSolverStack {
    char* top;
    int unk4;
    char* boundary;
    char* limit;
    int available() const { return static_cast<int>(limit-top)-16; }
};
struct NativeSolverMemory {
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotC();
    virtual void slot10();
    virtual void* allocateStack(int bytes);
    virtual void releaseStack(void* block);
    void FUN_008f6d90(void*,unsigned int,int);
    int unk04,unk08,unk0C,unk10,unk14,unk18,unk1C;
    NativeSolverStack stackAllocator;
    NativeSolverStack& stack() { return stackAllocator; }

    static __forceinline NativeSolverMemory* current();
    __forceinline void* allocate(int requested) {
        int aligned = (requested + 16) & ~15;
        char* begin = stackAllocator.top;
        char* end = begin + aligned;
        if (end <= stackAllocator.limit) { stackAllocator.top=end; return begin; }
        else { return allocateStack(aligned); }
    }
    void restore(char* begin) {
        stackAllocator.top=begin;
        if (begin==stackAllocator.boundary) releaseStack(begin);
    }
};

struct NativeSolverPartition {
    char* firstStorage;
    char* extraStorage;
    char* accumulators;
    char* schemaStart;
    char* primarySchemaEnd;
    char* secondarySchema;
    char* elementTemps;

    void initialize(int count,int schemaBytes,int elementBytes,int maxSchemaBytes) {
        int accumulatorBytes=(count<<7)+0x90;
        int total=accumulatorBytes+schemaBytes+elementBytes;
        NativeSolverMemory* memory=NativeSolverMemory::current();
        int firstBytes=total;
        int available=memory->stack().available();
        if(firstBytes>=available) firstBytes=available;
        firstStorage=static_cast<char*>(NativeSolverMemory::current()->allocate(firstBytes));
        extraStorage=0;
        secondarySchema=0;
        char* base=firstStorage;
        char* end=base+firstBytes;
        accumulators=base;
        schemaStart=base+accumulatorBytes;
        elementTemps=schemaStart+schemaBytes;
        primarySchemaEnd=elementTemps;

        while (elementTemps+elementBytes>end) {
            if (schemaStart>=end) {
                int bytes=static_cast<int>(elementTemps+elementBytes-firstStorage);
                extraStorage=static_cast<char*>(NativeSolverMemory::current()->allocate(bytes));
                end=extraStorage+bytes;
                base=extraStorage;
                accumulators=base;
                schemaStart=base+accumulatorBytes;
                elementTemps=schemaStart+schemaBytes;
                primarySchemaEnd=elementTemps;
            } else if (elementTemps>=end) {
                int bridgeBytes=maxSchemaBytes+16;
                char* split=end-bridgeBytes;
                int slack=static_cast<int>(split-schemaStart);
                int positiveSlack=slack>0 ? slack : 0;
                int remainingSchema=schemaBytes-positiveSlack+bridgeBytes;
                int bytes=remainingSchema+elementBytes;
                extraStorage=static_cast<char*>(NativeSolverMemory::current()->allocate(bytes));
                end=extraStorage+bytes;
                if (slack!=positiveSlack) {
                    schemaStart=extraStorage;
                    elementTemps=schemaStart+schemaBytes+16;
                    primarySchemaEnd=elementTemps;
                    secondarySchema=0;
                } else {
                    primarySchemaEnd=split;
                    secondarySchema=extraStorage;
                    elementTemps=extraStorage+remainingSchema;
                }
            } else {
                extraStorage=static_cast<char*>(NativeSolverMemory::current()->allocate(elementBytes));
                elementTemps=extraStorage;
                end=extraStorage+elementBytes;
            }
        }
    }
    void release() {
        if (extraStorage) NativeSolverMemory::current()->restore(extraStorage);
        NativeSolverMemory::current()->restore(firstStorage);
    }
};
struct NativeCriticalArray {
    const ConstraintInternalN** data;
    int count,capacity;
    const ConstraintInternalN* storage[256];
    void init() {data=storage;count=0;capacity=0x80000100;}
    void append(const ConstraintInternalN* c);
    void destroy();
};
struct NativeGotoSchema {
    union { float header; struct {unsigned char type,b1,b2,b3;}; };
    int relative;
    void set(char* destination) {
        relative=static_cast<int>(destination-reinterpret_cast<char*>(this));
        header=static_cast<float>(header+1.1920928955078125e-07);
        type=2;
    }
};
struct NativeMonitor {
    int unk0;
    char* end;
    int unk8;
    char* limit;
};
struct NativeMonitorValue {const char* name;float value;};
struct NativeBreachHeader {int count,unk4,unk8,unkC;};
void* InstanceN::getRuntime() const {return m_pConstraintInternal->m_pRuntime;}
extern unsigned long DAT_010f3170,DAT_0116913c;
extern const char str_00e854c0[],str_00e854b0[];
extern void __cdecl FUN_00901f10(NativeCriticalArray*,int);
extern VelocityAccumulatorN* __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(const hkStepInfoD886*,EntityN* const*,int,int,VelocityAccumulatorN*);
extern void __cdecl hkSimpleContactConstraintData_fireCallbacks(ConstraintDataN*,QueryInN*,S88_Atom*);
extern void __cdecl FUN_00a00ec0(S88_Atom*,QueryInN*,D88310Bool,S88_QueryOut*);
extern void __cdecl FUN_009fccc0(S88_Atom*,int,QueryInN*,S88_QueryOut*);
extern int __cdecl FUN_00a14ee0(const void*,char*,VelocityAccumulatorN*,char*);
extern void __cdecl hkExportImpulsesAndRhs(const void*,char*,char*,VelocityAccumulatorN*);
extern int __cdecl hkRigidMotionUtilApplyAccumulators(const void*,const hkStepInfoD886*,const VelocityAccumulatorN*,EntityN* const*,int,int);
extern void __cdecl FUN_0099a2d0(const void*,EntityN* const*,int);
extern void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(void*,void*,int);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
__forceinline NativeSolverMemory* NativeSolverMemory::current() { return static_cast<NativeSolverMemory*>(TlsGetValue(DAT_010f3170)); }
void NativeCriticalArray::append(const ConstraintInternalN* c) {
    if(count==(capacity&0x3fffffff)) FUN_00901f10(this,4);
    data[count++]=c;
}
void NativeCriticalArray::destroy(){if((capacity&0x80000000u)==0) {int n=capacity&0x3fffffff; NativeSolverMemory* m=NativeSolverMemory::current();m->FUN_008f6d90(data,n*4,0x17);}}
__forceinline void PopulateNativeQuery(const ConstraintInternalN* c,QueryInN& in,VelocityAccumulatorN* acc) {
    EntityN* a=c->m_kActorEntries[0];
    EntityN* b=c->m_kActorEntries[1];
    in.m_pBodyA=reinterpret_cast<VelocityAccumulatorN*>(reinterpret_cast<char*>(acc)+a->m_uiFilterInfo);
    in.m_pBodyB=reinterpret_cast<VelocityAccumulatorN*>(reinterpret_cast<char*>(acc)+b->m_uiFilterInfo);
    in.m_kBodyALocalFrame=&a->getMotion()->GetMotionState()->getTransform();
    in.m_kBodyBLocalFrame=&b->getMotion()->GetMotionState()->getTransform();
    in.m_pConstraintChainInstance=c->m_pHavokConstraint;
    in.m_pByteBuffer=c->m_pRuntime;
    in.m_uiParameterA=static_cast<unsigned short>(a->m_uiFilterInfo>>7);
    in.m_uiParameterB=static_cast<unsigned short>(b->m_uiFilterInfo>>7);
    in.m_pUserData=in.m_pByteBuffer;
}
__forceinline void NativeBuildFromAtoms(S88_Atom* atoms,unsigned short size,QueryInN& in,S88_QueryOut& out) {
    if(atoms->m_type==0x16) FUN_00a00ec0(atoms,&in,D88310Bool(true),&out);
    else FUN_009fccc0(atoms,size,&in,&out);
}
__forceinline void BuildNativeConstraint(const ConstraintInternalN* c,QueryInN& in,
                                  VelocityAccumulatorN* acc,S88_QueryOut& out) {
    PopulateNativeQuery(c,in,acc);
    S88_Atom* atoms=c->m_kBridgeAtoms;
    unsigned short size=c->m_iAtomsSize;
    if(atoms->m_type==0x16) FUN_00a00ec0(atoms,&in,D88310Bool(true),&out);
    else FUN_009fccc0(atoms,size,&in,&out);
}

template<class T> __forceinline T* AllocateNativeStorage(int bytes) {
    NativeSolverMemory& memory=*NativeSolverMemory::current();
    return static_cast<T*>(memory.allocate(bytes*sizeof(T)));
}

static __forceinline void MakeNativeAccumulators(const hkStepInfoD886& stepInfo,
    EntityN* const* entities,int count,VelocityAccumulatorN* accumulators) {
    accumulators->m_type=1;
    accumulators->m_iValueAtOffset0C=1;
    hkVector4N zero;
    zero.setZero4();
    accumulators->m_vInverseInertiaAndMass=zero;
    accumulators->m_vLinearVelocity=zero;
    accumulators->m_vAngularVelocity=zero;
    accumulators->m_vCenterOfMass=zero;
    accumulators->m_scratch1.x=0;accumulators->m_scratch1.y=0;accumulators->m_scratch1.z=0;accumulators->m_scratch1.w=0;
    accumulators->m_scratch2.x=0;accumulators->m_scratch2.y=0;accumulators->m_scratch2.z=0;accumulators->m_scratch2.w=0;
    accumulators->m_scratch3.x=0;accumulators->m_scratch3.y=0;accumulators->m_scratch3.z=0;accumulators->m_scratch3.w=0;
    for(int i=0;i<count;++i) {
        unsigned offset=(i+1)*128;
        if(offset!=entities[i]->m_uiFilterInfo) entities[i]->m_uiFilterInfo=offset;
    }
    VelocityAccumulatorN* accumEnd=hkRigidMotionUtilApplyForcesAndBuildAccumulators(&stepInfo,entities,count,0xd0,accumulators+1);
    accumEnd->m_type=3;

}
static __forceinline void MakeNativeElements(QueryInN& in,
    EntityN* const* entities,int count,VelocityAccumulatorN* acc,
    char* schemaStart,char* schemaLimit,char* secondarySchema) {
    S88_QueryOut out;
    out.m_pQueryResultSchema=reinterpret_cast<S88_Schema*>(schemaStart);
    EntityN* const* e=entities;
    EntityN* const* eEnd=entities+count;
    NativeCriticalArray critical;
    critical.init();
    for(;e<eEnd;++e) {
        const ConstraintInternalN* c=(*e)->getConstraintMasters().begin();
        const ConstraintInternalN* cEnd=(*e)->getConstraintMasters().end();
        for(;c<cEnd;++c) {
            if(c->m_ucCallbackRequest&5) {
                in.m_pConstraintChainInstance=c->m_pHavokConstraint;
                in.m_pByteBuffer=c->m_pRuntime;
                EntityN* a=c->m_pHavokConstraint->unk14;
                EntityN* b=c->m_pHavokConstraint->unk18;
                in.m_pBodyA=reinterpret_cast<VelocityAccumulatorN*>(reinterpret_cast<char*>(acc)+a->m_uiFilterInfo);
                in.m_pBodyB=reinterpret_cast<VelocityAccumulatorN*>(reinterpret_cast<char*>(acc)+b->m_uiFilterInfo);
                in.m_kBodyALocalFrame=&a->getCollidable()->getTransform();
                in.m_kBodyBLocalFrame=&b->getCollidable()->getTransform();
                if(c->m_ucCallbackRequest&1) {
                    ConstraintDataN* data=c->m_pHavokConstraint->m_data;
                    hkSimpleContactConstraintData_fireCallbacks(data,&in,data->m_pAtom);
                }
                if(c->m_ucCallbackRequest&4) c->m_pHavokConstraint->m_data->BuildJacobianCallback(in);
            }
            if(c->m_priority>=3) {critical.append(c);continue;}
            if(reinterpret_cast<char*>(out.m_pQueryResultSchema.val())>=schemaLimit) {
                NativeGotoSchema* go=reinterpret_cast<NativeGotoSchema*>(out.m_pQueryResultSchema.val());
                go->set(secondarySchema);
                out.m_pQueryResultSchema=reinterpret_cast<S88_Schema*>(secondarySchema);
                schemaLimit=reinterpret_cast<char*>(~0u);
            }
            BuildNativeConstraint(c,in,acc,out);
        }
    }
    for(int i=0;i<critical.count;++i) {
        const ConstraintInternalN* c=critical.data[i];
        if(reinterpret_cast<char*>(out.m_pQueryResultSchema.val())>=schemaLimit) {
            NativeGotoSchema* go=reinterpret_cast<NativeGotoSchema*>(out.m_pQueryResultSchema.val());
            go->set(secondarySchema);
            out.m_pQueryResultSchema=reinterpret_cast<S88_Schema*>(secondarySchema);
            schemaLimit=reinterpret_cast<char*>(~0u);
        }
        PopulateNativeQuery(c,in,acc);
        NativeBuildFromAtoms(c->m_kBridgeAtoms,c->m_iAtomsSize,in,out);
    }
    *reinterpret_cast<int*>(out.m_pQueryResultSchema.val())=0;
    critical.destroy();

}
int __cdecl FUN_00d88b50(const hkStepInfoD886& stepInfo,const void* solverInfo,S88_QueryIn& packIn,
    S88b50_Island& island,void* preallocatedBuffer,int preallocatedBufferSize,
    S88b50_Entity* const* bodies,int numBodies) {
    QueryInN& in=reinterpret_cast<QueryInN&>(packIn);
    // Fake match: the pack retains two later-version parameters; the native ABI
    // supplies the entity array and count in the preceding two argument slots.
    EntityN* const* entities=static_cast<EntityN* const*>(preallocatedBuffer);
    int count=preallocatedBufferSize;
    int inactive=0;
    char* extraStorage=0;
    int accumulatorBytes=count*128+0x90;
    int nativeSchemaBytes=island.m_iSchemaByteSize+16;
    int nativeElementBytes=island.m_iSolverElementTemporaryCount*4+8;
    char* secondarySchema=0;
    int total=nativeElementBytes+nativeSchemaBytes+accumulatorBytes;
    int available=NativeSolverMemory::current()->stack().available();
    int firstBytes=total<available ? total : available;
    char* firstStorage=AllocateNativeStorage<char>(firstBytes);
    char* base=firstStorage;
    char* end=base+firstBytes;
    VelocityAccumulatorN* accumulators;
    char* schemaStart;
    char* primarySchemaEnd;
    char* elementTemps;
head:
    accumulators=reinterpret_cast<VelocityAccumulatorN*>(base);
    base+=accumulatorBytes;
    schemaStart=base;
    base+=nativeSchemaBytes;
    primarySchemaEnd=base;
setPrimary:
    elementTemps=base;
    base+=nativeElementBytes;
    if(base<=end) {
    MakeNativeAccumulators(stepInfo,entities,count,accumulators);
    float* temps=reinterpret_cast<float*>(elementTemps);
    for(int i=0;i<island.m_iSolverElementTemporaryCount;++i) temps[i]=0.0f;
    MakeNativeElements(in,entities,count,accumulators,schemaStart,primarySchemaEnd,secondarySchema);
    int solved=FUN_00a14ee0(solverInfo,schemaStart,accumulators,elementTemps);
    NativeMonitor* monitor=static_cast<NativeMonitor*>(TlsGetValue(DAT_0116913c));
    if(monitor->end<monitor->limit) {
        NativeMonitorValue* value=reinterpret_cast<NativeMonitorValue*>(monitor->end);
        value->name=str_00e854c0;value->value=static_cast<float>(island.m_iSolverResultCount);
        monitor->end=reinterpret_cast<char*>(value+1);
    }
    monitor=static_cast<NativeMonitor*>(TlsGetValue(DAT_0116913c));
    if(monitor->end<monitor->limit) {
        NativeMonitorValue* value=reinterpret_cast<NativeMonitorValue*>(monitor->end);
        value->name=str_00e854b0;value->value=static_cast<float>(count);
        monitor->end=reinterpret_cast<char*>(value+1);
    }
    if(solved==1) {
        hkExportImpulsesAndRhs(solverInfo,elementTemps,schemaStart,accumulators);
        int res=hkRigidMotionUtilApplyAccumulators(solverInfo,&stepInfo,accumulators+1,entities,count,0xd0);
        FUN_0099a2d0(entities[0]->getWorld()->getCollisionInput(),entities,count);
        inactive=res;
        NativeBreachHeader* breaches=reinterpret_cast<NativeBreachHeader*>(schemaStart);
        if(breaches->count) hkpWorldCallbackUtil_fireContactImpulseLimitBreached(island.m_pOwningWorld,breaches+1,breaches->count);
    }

        if(extraStorage) NativeSolverMemory::current()->restore(extraStorage);
        NativeSolverMemory::current()->restore(firstStorage);
        return inactive;
    } else {
        if(schemaStart>=end) {
            int bytes=static_cast<int>(base-firstStorage);
            extraStorage=AllocateNativeStorage<char>(bytes);
            base=extraStorage;
            end=base+bytes;
            goto head;
        }
        int bridgeBytes=island.m_iMaxSchemaSize+16;
        if(primarySchemaEnd>=end) {
            int slack=static_cast<int>(end-schemaStart-bridgeBytes);
            int positiveSlack=slack>0 ? slack : 0;
            int remainingSchema=island.m_iSchemaByteSize+bridgeBytes-positiveSlack;
            int bytes=nativeElementBytes+remainingSchema;
            extraStorage=AllocateNativeStorage<char>(bytes);
            if(slack<0) {
                base=extraStorage;
                end=base+bytes;
                schemaStart=base;
                base+=island.m_iSchemaByteSize+16;
                primarySchemaEnd=base;
                secondarySchema=0;
            } else {
                primarySchemaEnd=end-bridgeBytes;
                base=extraStorage;
                end=base+bytes;
                secondarySchema=base;
                base+=remainingSchema;
            }
        } else {
            int bytes=nativeElementBytes;
            extraStorage=AllocateNativeStorage<char>(bytes);
            base=extraStorage;
            end=base+bytes;
        }
        goto setPrimary;
    }
}

