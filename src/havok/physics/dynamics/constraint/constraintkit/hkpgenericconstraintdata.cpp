#include "f3_common.h"
// src/havok/physics/dynamics/constraint/constraintkit/hkpgenericconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/constraintkit/hkpgenericconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpGenericConstraintData.h"

struct FUN_00d503a0_class : public hkpGenericConstraintData
{
    void FUN_00d503a0(int, int* out);
};

// @fnv 0x00d503a0
void FUN_00d503a0_class::FUN_00d503a0(int, int* paiOut)
{
    int v = m_kConstraintDataScheme.m_info.m_iSolverResultCount;
    paiOut[1] = v;
    paiOut[0] = v * 8;
}

struct FUN_00d50520_s : public hkpGenericConstraintData
{
    void FUN_00d50520(int* o);
};
// @fnv 0x00d50520
// pdb: hkpGenericConstraintData::getConstraintInfo | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun, medium
// pdb params: info
void FUN_00d50520_s::FUN_00d50520(int* aiOut)
{
    aiOut[4] = (int)&m_kBridgeAtoms;
    aiOut[0] = 0;
    aiOut[1] = 0;
    aiOut[2] = 0;
    aiOut[3] = 0;
    aiOut[5] = 0xc;
    aiOut[0] = m_kConstraintDataScheme.m_info.m_iMaxSchemaSize;
    aiOut[1] = m_kConstraintDataScheme.m_info.m_iSchemaByteSize;
    aiOut[2] = m_kConstraintDataScheme.m_info.m_iSolverResultCount;
    aiOut[3] = m_kConstraintDataScheme.m_info.m_iSolverElementTemporaryCount;
}

struct FUN_00d50560_class
{
    char pad[0x28];
    int* m_items;
    int* FUN_00d50560(unsigned int index);
};

// @fnv 0x00d50560
int* FUN_00d50560_class::FUN_00d50560(unsigned int index)
{
    return m_items + index * 4;
}

// @fnv 0x00d50500
// pdb: hkStdioStreamWriter::markSupported | hkStdioStreamWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkStdioStreamWriter_markSupported(unsigned char* out)
{
    *out = 1;
}

// @fnv 0x00d50510
// pdb: CombatProcedureSearch::GetType | CombatProcedureSearch.obj | fnv360_0822_retail, vtable, medium
int FUN_00d50510()
{
    return 10;
}

class CFoo : public hkpGenericConstraintData
{
  public:
    void* FUN_00d504f0();
};

// @fnv 0x00d504f0
// pdb: hkpGenericConstraintData::getScheme | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun, medium
void* CFoo::FUN_00d504f0()
{
    return (void*)&m_kConstraintDataScheme;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};

struct SolverItem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
};

void __cdecl AppendEventRecord(SolverItem* item, int index, int count, int stride);

struct FUN_00d50bd0_owner
{
    hkpConstraintData m_base;
    hkpBridgeAtoms m_kBridgeAtoms;
    hkpGenericConstraintDataScheme m_kConstraintDataScheme;

    void FUN_00d50640(hkpGenericConstraintDataScheme* scheme, SolverItem* item, int index);
    void FUN_00d50bd0(SolverItem* item, int index);
};

// @f3 0x009de670 (community match, verified in this file)
struct OwnerM50B {
    char pad[0x18];
    unsigned int constraintData;
    void hkpGenericConstraintData_hatchScheme(void* data, SolverItem* item, int index);
};

// pdb: hkpGenericConstraintData::constrainLinearW | hkpGenericConstraintData.obj | fnv360_0822_debug, objopen_prop, low, conflict (skyrim: hkpGenericConstraintData::buildJacobian)
// pdb params: currentCommand, currentData, scheme, vars, in, out
void FUN_00d50bd0_owner::FUN_00d50bd0(SolverItem* item, int index) {
    AppendEventRecord(item, index, item->unk4c, 8);
    OwnerM50B* self = (OwnerM50B*)this;
    self->hkpGenericConstraintData_hatchScheme(&self->constraintData, item, index);
}


struct FUN_00d51620_Alloc
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void* p, unsigned int n);
};

struct FUN_00d51620_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d51620_Alloc* m_pThreadAllocator;
};

FUN_00d51620_Router* FUN_00c85750();

namespace fnv_00d516f0 {
struct FnvCpu_FUN_00d516f0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d516f0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d516f0_CpuAllocator* allocator;
};
FnvCpu_FUN_00d516f0_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d516f0

union FUN_00d503c0_vec
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};
struct FUN_00d503c0_m
{
    FUN_00d503c0_vec r0, r1, r2;
};
struct FUN_00d503c0_src
{
    FUN_00d503c0_vec r0;
    FUN_00d503c0_vec r1;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8;
};

void __cdecl FUN_00dcf280(FUN_00d503c0_m* m, void* obj, void* out);

// Copies two vectors from src, sets a third to each unit axis in turn calling FUN_00dcf280 each time, then adds 3 to src->unkB8.
// @f3 0x009ddb70 (community match, verified in this file)
// pdb: hkpGenericConstraintData::constrainAllLinearW | hkpGenericConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_00d503c0(int a, int b, int c, FUN_00d503c0_src* src, void* obj, void* out)
{
    FUN_00d503c0_m m;
    m.r0.x = src->r0.x;
    m.r0.y = src->r0.y;
    m.r0.z = src->r0.z;
    m.r0.w = src->r0.w;

    m.r1.x = src->r1.x;
    m.r1.y = src->r1.y;
    m.r1.z = src->r1.z;
    m.r1.w = src->r1.w;

    m.r2.w = 0.0f;
    m.r2.z = 0.0f;
    m.r2.y = 0.0f;
    m.r2.x = 1.0f;
    FUN_00dcf280(&m, obj, out);

    m.r2.x = 0.0f;
    m.r2.y = 1.0f;
    FUN_00dcf280(&m, obj, out);

    m.r2.y = 0.0f;
    m.r2.z = 1.0f;
    FUN_00dcf280(&m, obj, out);

    src->unkB8 += 3;
}


struct FUN_00d50c90;
struct ReferenceFields
{
    virtual void Release() = 0;
    unsigned short memSizeAndFlags;
    short referenceCount;
    unsigned int userData;
    ReferenceFields() : referenceCount(1), userData(0)
    {}
};
struct BridgeAtom
{
    unsigned short type;
    unsigned short flags;
    void* jacobian;
    void* constraintData;
    BridgeAtom() : type(1)
    {}
    void FUN_00d21ce0(FUN_00d50c90* parent);
};
template <class T> struct ConstraintArray
{
    T* data;
    int size;
    int capacityAndFlags;
    ConstraintArray() : data(0), size(0), capacityAndFlags(0x80000000)
    {}
};
struct ConstraintScheme
{
    hkpGenericConstraintDataSchemeConstraintInfo info;
    ConstraintArray<hkVector4> data;
    ConstraintArray<int> commands;
    ConstraintArray<void*> modifiers;
    ConstraintArray<hkpConstraintMotor*> motors;
    ConstraintScheme()
    {
        info.m_iMaxSchemaSize = 0;
        info.m_iSchemaByteSize = 0;
        info.m_iSolverResultCount = 0;
        info.m_iSolverElementTemporaryCount = 0;
    }
};
struct FUN_00d50c90 : ReferenceFields
{
    BridgeAtom atom;
    ConstraintScheme scheme;
    FUN_00d50c90();
};
// @fnv 0x00d50c90
// pdb: hkpGenericConstraintData::hkpGenericConstraintData | hkpGenericConstraintData.obj | fnv360_0822_retail, caller_sim, high
FUN_00d50c90::FUN_00d50c90()
{
    *(volatile int*)&scheme.info.m_iSchemaByteSize += 16;
    atom.FUN_00d21ce0(this);
}

struct S00d50e10_Rows
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
};

void __cdecl FUN_00dcee80(S00d50e10_Rows* out, int d, int e);

struct __declspec(align(16)) hkVector4D510
{
    float x, y, z, w;
};

struct SolverInfoD510
{
    hkVector4D510 m_jacobian;
    float m_f0;
    float m_f1;
    float m_out;
    float m_vScale;
};

struct SolverStateD510
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int m_numJacobians;
};

void __cdecl FUN_00dcfec0(const hkVector4D510* pkLinA, const hkVector4D510* pkAngA, const hkVector4D510* pkLinB,
                          const hkVector4D510* pkAngB, hkVector4D510* pkJac, float* pfOut);
void __cdecl FUN_00d6cb30(const SolverInfoD510* pkInfo, void* pvA, void* pvB);

// Reads two indices from ppSchema, computes a Jacobian via FUN_00dcfec0, stores it with two floats from ppData, and calls FUN_00d6cb30.
// @fnv 0x00d51060
// pdb: hkpGenericConstraintData::setTwistLimitW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_00d51060(const char** ppSchema, const float** ppData, void* pvUnused, SolverStateD510* pkState,
                            void* pvA, void* pvB)
{
    SolverInfoD510 kInfo;
    *ppSchema += 4;
    int iIndexA = *(const int*)*ppSchema;
    *ppSchema += 4;
    int iIndexB = *(const int*)*ppSchema;
    kInfo.m_vScale = 0.5f;
    const hkVector4D510* pkVecs = (const hkVector4D510*)pkState;
    FUN_00dcfec0(&pkVecs[iIndexA + 5], &pkVecs[iIndexA + 8], &pkVecs[iIndexB + 5], &pkVecs[iIndexB + 8],
                 &kInfo.m_jacobian, &kInfo.m_out);
    const float* pVector4 = *ppData;
    kInfo.m_f0 = pVector4[0];
    *ppData = pVector4 + 4;
    kInfo.m_f1 = pVector4[1];
    FUN_00d6cb30(&kInfo, pvA, pvB);
    pkState->m_numJacobians++;
}

struct d51390_rec
{
    float r0;
    float r1;
    float r2;
    float r3;
};

struct d51390_pool
{
    d51390_rec recs[11];
    int unkB0;
    int unkB4;
    int unkB8;
};

struct d51390_ctx
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
};

struct d51390_item
{
    d51390_rec* rec;
    int dest;
    float val;
    int flag;
};

extern "C" void __cdecl DAT_00dcefb0(d51390_item* item, d51390_ctx* ctx, void* a6);

// Advances the stream, builds an item from a pool record and the cursor value with a destination offset by pool->unkB8, calls DAT_00dcefb0, and increments unkB8.
// @f3 0x009def70 (community match, verified in this file)
// pdb: hkpGenericConstraintData::setAngularFrictionW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_00d51390(int** stream, float** cursor, int a3, d51390_pool* pool, d51390_ctx* ctx, void* a6)
{
    int destBase = ctx->unk4C;
    (*stream) += 1;
    d51390_item item;
    item.rec = &pool->recs[**stream + 5];
    float* cur = *cursor;
    float v = cur[0];
    *cursor = cur + 4;
    item.val = v;
    item.flag = 1;
    item.dest = destBase + pool->unkB8 * 8;
    DAT_00dcefb0(&item, ctx, a6);
    pool->unkB8 += 1;
}


extern "C"
{
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    void _mm_store_ss(float* p, __m128 a);
}

struct VectorComponentValue
{
    __m128 m_vValue;

    VectorComponentValue()
    {}
    VectorComponentValue(const __m128& r) : m_vValue(r)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline VectorComponentValue dot3(const hkVector4q& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return _mm_add_ss(z, xySum);
    }
};

struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline const hkVector4q& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
};

extern int DAT_011b5a90[];
extern int DAT_011b5a94[];

float __cdecl Atan2(float y, float x);

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);

namespace fnv_00d50d60 {
extern "C" __m128 __cdecl _mm_load_ps(const float*);
extern "C" void __cdecl _mm_store_ps(float*, __m128);

extern unsigned int DAT_011b5a90;
extern unsigned int DAT_011b5a94;

void __cdecl FUN_00dcee80(void* pair, int a2, int a3);

}  // namespace fnv_00d50d60

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, __m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}

struct __declspec(align(16)) hkVec4A
{
    float x, y, z, w;
};

struct hkAngInfo
{
    hkVec4A m_kAxisEndPoints;
    float m_kPointA;
    float m_kPointB;
    float m_dot;
    float m_fTau;
};

extern "C" void FUN_00d6cb30(hkAngInfo* info, int p1, int p2);

// @f3 0x009de6a0 (community match, verified in this file)
struct Vector457 {
    float x, y, z, w;
    __forceinline void operator=(const Vector457& other) {
        x = other.x; y = other.y; z = other.z; w = other.w;
    }
};
struct __declspec(align(16)) Input457 {
    Vector457 first, second, selected;
};
void __cdecl FUN_00a4ebf0(Input457*, int*, int);
// pdb: hkpGenericConstraintData::constrainAllLinearW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: hkpGenericConstraintData::constrainLinearW)
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_00d51100(int** commands, int* unusedData, void* unusedScheme, int* state, int* configuration, int index)
{
    ++*commands;
    int selected = **commands;
    Input457 input;
    Vector457* vectors = reinterpret_cast<Vector457*>(state);
    input.selected = vectors[selected + 2];
    input.first = vectors[0];
    input.second = vectors[1];
    FUN_00a4ebf0(&input, configuration, index);
    ++state[0xb8 / 4];
}


namespace fnv_00d51170 {

extern "C" __m128 __cdecl _mm_mul_ps(__m128, __m128);
extern "C" __m128 __cdecl _mm_add_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_shuffle_ps(__m128, __m128, int);
extern "C" void __cdecl _mm_store_ss(float*, __m128);
extern int DAT_011b5a90[];
extern float Atan2(float, float);

}  // namespace fnv_00d51170

extern "C"
{
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    __m128 _mm_load_ps(float const* p);
    void _mm_store_ss(float* p, __m128 a);
}

struct ContactImpulseInfo
{
    hkReal m_fContactImpulse;
    hkReal m_data;
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
    ContactImpulseInfo* m_pSolverResults;
};

struct GenericConstraintRuntime
{
    hkVector4 m_kShapeVectorData[11];
    int unkB0;
    int unkB4;
    int m_solverResultIndex;
};

struct SolverElementTemp
{
    hkReal m_invMass;
    SixteenWordFloatRecord* m_pStepInfo;
    ContactImpulseInfo m_lastImpulse;
    hkReal m_rhs;
    hkReal m_deltaPosition;

    SolverElementTemp()
    {
        m_lastImpulse.m_fContactImpulse = 0;
        m_lastImpulse.m_data = 0;
    }
};

struct SixIntegerData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

void __cdecl FUN_00dcfff0(const hkpConstraintMotor* motor, const SolverElementTemp* input, SixIntegerData* output);

// Advances the command and data pointers, computes a dot product for a motor constraint, and updates the solver state if a motor is present.
// @f3 0x009dee30 (community match, verified in this file)
inline void Subtract1747(hkVector4& out,const hkVector4& a,const hkVector4& b){out.x=a.x-b.x;out.y=a.y-b.y;out.z=a.z-b.z;}
void __cdecl FUN_00a507b0(const hkVector4*,const hkVector4*,SixteenWordFloatRecord*,void*,SolverElementTemp*);
void __cdecl FUN_00a50540(const hkpConstraintMotor*,const SolverElementTemp*,SixIntegerData*);
void __cdecl FUN_00a50a80(SixIntegerData*,SixteenWordFloatRecord*,void*,void**);
// @fnv 0x00d51270
// pdb: hkpGenericConstraintData::setLinearMotorW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop + bridge(caller_sim|call_gap) + skyrim(caller_sim), high
void __stdcall hkpGenericConstraintData_setLinearMotorW(const int** commands, const hkVector4** data, hkpGenericConstraintDataScheme* scheme,
                            GenericConstraintRuntime* runtime, SixteenWordFloatRecord* apStepInfo, void** schema)
{
    *commands += 1;
    int axisIdx = **commands;

    const hkVector4* currentData = *data;
    ContactImpulseInfo* p = (ContactImpulseInfo*)apStepInfo->unk4C;
    *data = currentData + 1;
    int motorIdx = (int)currentData->x;

    hkpConstraintMotor* motor = scheme->m_ppMotors.m_data[motorIdx];

    int axisIndex = axisIdx + 2;
    hkVector4 axis = runtime->m_kShapeVectorData[axisIndex];
    hkVector4 delta;
    Subtract1747(delta,runtime->m_kShapeVectorData[0],runtime->m_kShapeVectorData[1]);
    float dot=delta.x*axis.x+delta.y*axis.y+delta.z*axis.z;

    if (motor)
    {
        void* currentSchema = *schema;
        __declspec(align(16)) SolverElementTemp input;
        SixIntegerData output;

        FUN_00a507b0(&axis, &runtime->m_kShapeVectorData[1], apStepInfo, currentSchema, &input);

        input.m_lastImpulse = p[runtime->m_solverResultIndex];
        input.m_rhs = 0.0f;
        input.m_deltaPosition = -dot;
        input.m_pStepInfo = apStepInfo;

        FUN_00a50540(motor, &input, &output);
        FUN_00a50a80(&output, apStepInfo, currentSchema, schema);
    }

    runtime->m_solverResultIndex += 1;
}


struct Motor;

union Vec
{
    __m128 m;
    struct
    {
        float x, y, z, w;
    };
};

struct Pair
{
    int a;
    int b;
};

struct QueryIn
{
    float m_fTau;
    float m_fMotorDamping;
    float m_fThirdQueryValue;
    float m_fFourthQueryValue;
    float m_fFifthQueryValue;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* m_pFirstQueryData;
    void* m_pSecondQueryData;
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
    Pair* m_pSolverResults;
};

struct Scheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    Vec* m_data;
    int m_iDataSize;
    int m_dataCap;
    int* m_commands;
    int m_cmdSize;
    int m_cmdCap;
    void** m_ppModifiers;
    int m_modSize;
    int m_modCap;
    Motor** m_ppMotors;
};

struct Runtime
{
    Vec v[11];
    int unkB0;
    int unkB4;
    int m_iFirstInteger;
};

struct __declspec(align(16)) MotorStuff
{
    float effMass;
    QueryIn* query;
    union
    {
        float last0f;
        int last0;
    };
    union
    {
        float last1f;
        int last1;
    };
    float zero;
    float negTarget;
    float out0;
    float out1;
    float out2;
    float out3;
    float out4;
};

extern int DAT_011b5a90[];

void __cdecl FUN_00dcfff0(Motor* motor, MotorStuff* input, float* output);

static __forceinline __m128 dot3(__m128 p, __m128 q)
{
    __m128 m = _mm_mul_ps(p, q);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xAA), s);
}

// Computes and unwraps an angle from runtime vectors, stores it back, and if a motor exists calls FUN_00dcfff0 and FUN_00d6ce70; then increments m_iFirstInteger.
// @f3 0x009df0b0 (community match, verified in this file)
struct F3MotorResults9df0b0 { float a; float b; };
struct F3QueryIn9df0b0
{
    float m_fTau;
    float m_fMotorDamping;
    float m_fThirdQueryValue;
    float m_fFourthQueryValue;
    float m_fFifthQueryValue;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* m_pFirstQueryData;
    void* m_pSecondQueryData;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    F3MotorResults9df0b0* m_results;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    F3MotorResults9df0b0* m_pSolverResults;
};
extern int DAT_01062d90[];
extern int DAT_01062d94[];
extern double FUN_00dc0770;
extern double FUN_00dc0778;
extern double FUN_00dc0760;
float __cdecl FUN_00954db0(float y, float x);
static inline void QSetVec(Vec* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
struct QMotorPacket
{
    float a;
    QueryIn* query;
    F3MotorResults9df0b0 previous;
    float zero;
    float negTarget;
    float out0;
    float target;
    float out3;
    float out2;
    float out4;
    float results;
};
void __cdecl FUN_009f9580(Vec* ptr, QueryIn* in, void* schema, QMotorPacket* packet);
void __cdecl FUN_00a50540(Motor* motor, QMotorPacket* input, float* output);
void __cdecl FUN_009f97a0(float* output, QueryIn* in, void* schema, void** out);

// pdb: hkpGenericConstraintData::setAngularMotorW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop + bridge(caller_sim|call_gap) + skyrim(caller_sim), high
void __stdcall hkpGenericConstraintData_setAngularMotorW(int** cmdPtr, Vec** dataPtr, Scheme* scheme, Runtime* runtime, QueryIn* apQuery, void** out)
{
    ++*cmdPtr;
    F3MotorResults9df0b0* out5 = reinterpret_cast<F3QueryIn9df0b0*>(apQuery)->m_results;
    long ptr = **cmdPtr;
    Vec* axisVec;
    Vec* data = *dataPtr;
    *dataPtr = data + 1;
    float prev;
    prev = data->y;
    float turns;
    turns = data->z;
    Motor* motor;
    motor = scheme->m_ppMotors[(int)data->x];
    axisVec = &runtime->v[ptr + 5];
    const Vec& effMass = runtime->v[DAT_01062d90[ptr] + 5];
    const Vec& d1 = runtime->v[DAT_01062d94[ptr] + 8];
    float b = d1.y * effMass.y + d1.x * effMass.x + d1.z * effMass.z;
    const Vec& c = runtime->v[DAT_01062d90[ptr] + 8];
    float d2;
    d2 = c.y * effMass.y + static_cast<const volatile float&>(c.x) * effMass.x + c.z * effMass.z;
    float angle = FUN_00954db0(-b, -d2) + FUN_00dc0770;
    if (angle - prev < FUN_00dc0778)
        turns = turns + 1.0;
    else if (angle - prev > FUN_00dc0770)
        turns = turns - 1.0;
    QSetVec(data, static_cast<const volatile float&>(data->x), angle, turns, 0.0f);
    if (motor)
    {
        void* schema = *out;
        QMotorPacket packet;
        packet.previous.a = 0.0f;
        packet.previous.b = 0.0f;
        FUN_009f9580(axisVec, apQuery, schema, &packet);
        packet.query = apQuery;
        packet.previous = out5[runtime->m_iFirstInteger];
        packet.zero = 0.0f;
        float out1 = turns * FUN_00dc0760 + angle;
        packet.negTarget = -out1;
        FUN_00a50540(motor, &packet, &packet.out0);
        FUN_009f97a0(&packet.out0, apQuery, schema, out);
    }
    ++runtime->m_iFirstInteger;
}


extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);

struct VecD506
{
    __m128 v;
    __forceinline void operator=(const VecD506& a)
    {
        v = a.v;
    }
    void FUN_00c7f640(const void*, const VecD506*);
};
struct FUN_00cdf250_class
{
    __m128 c0, c1, c2;
    __forceinline void operator=(const FUN_00cdf250_class& m)
    {
        c0 = m.c0;
        c1 = m.c1;
        c2 = m.c2;
    }
    void FUN_00cd55b0(int*, int);
};
struct __declspec(align(16)) InputD506
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    union
    {
        float real;
        int bits;
    } factor;
    int unk28, unk2c, unk30, unk34;
    FUN_00cdf250_class* transformA;
    FUN_00cdf250_class* transformB;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct StateD506
{
    VecD506 pivotA, pivotB;
    VecD506 axes[3];
    FUN_00cdf250_class basisA, basisB;
    FUN_00cdf250_class* transformA;
    FUN_00cdf250_class* transformB;
    int count;
};
struct ModifierD506;
typedef void(__thiscall* ApplyD506)(ModifierD506*, StateD506*, int);
struct ModifierVTableD506
{
    void* unknown;
    ApplyD506 apply;
};
struct ModifierD506
{
    ModifierVTableD506* vtable;
};
extern "C" void FUN_00c7f640();
typedef void(__thiscall* PivotD506)(VecD506*, const void*, const VecD506*);
struct InterpreterD506
{
    void FUN_00d50640(hkpGenericConstraintDataScheme*, const InputD506*, void*);
    void FUN_00d50d00(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d503c0(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d50d60(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d50e10(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d51100(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d51170(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d50ec0(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d51060(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_setAngularMotorW(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_setLinearMotorW(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d51390(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void FUN_00d505c0(int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
};
typedef void(__thiscall* HandlerD506)(InterpreterD506*, int**, VecD506**, hkpGenericConstraintDataScheme*, StateD506*,
                                      InputD506*, void*);

static __forceinline void rotateD506(VecD506& out, const FUN_00cdf250_class* m, const VecD506& vec)
{
    const __m128& v = vec.v;
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    __m128 x = _mm_shuffle_ps(v, v, 0);
    __m128 z = _mm_shuffle_ps(v, v, 0xaa);
    y = _mm_mul_ps(y, m->c1);
    x = _mm_mul_ps(x, m->c0);
    y = _mm_add_ps(y, x);
    z = _mm_mul_ps(z, m->c2);
    out.v = _mm_add_ps(y, z);
}
