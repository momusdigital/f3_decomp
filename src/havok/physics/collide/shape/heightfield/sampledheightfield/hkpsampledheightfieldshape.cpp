#include "f3_common.h"
// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSampledHeightFieldShape.h"

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };

struct hkInfoD260 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScalar;
};

class hkBoolD260 {
public:
    hkBoolD260(bool b) { m_cBooleanValue = (char)b; }
    hkBoolD260(const hkBoolD260& o) { m_cBooleanValue = o.m_cBooleanValue; }

    char m_cBooleanValue;
};

class hkCollectorD260 {
public:
    hkCollectorD260(hkInfoD260* info) : m_fScalar(info->m_fScalar), m_bHasHit(false), m_info(info) {}
    virtual void AddHit(void* hit);

    float m_fScalar;
    bool m_bHasHit;
    hkInfoD260* m_info;
};

struct FUN_00d24b50_Obj {
    void __thiscall FUN_00d24b50(void* object, int flags, hkBoolD260 flag2, float f, hkCollectorD260* collector);
};

class hkShapeD260 : public FUN_00d24b50_Obj {
public:
    hkBoolD260 __thiscall FUN_00d26080(void* object, hkInfoD260* info);
};

// Runs FUN_00d24b50 on object with a collector built from info and returns whether the collector recorded a hit.
// @fnv 0x00d26080
hkBoolD260 __thiscall hkShapeD260::FUN_00d26080(void* object, hkInfoD260* info) {
    hkCollectorD260 collector(info);
    this->FUN_00d24b50(object, 0, hkBoolD260(false), 0.0f, &collector);
    return collector.m_bHasHit;
}

struct S00d261b0_Elem {
    __m128 v00;
    float f10;
    int i14;
    int unk18;
    int unk1c;
    int m_slots[8];
    int m_idx40;
};

struct S00d261b0_cls {
    int unk00;
    float f04;
    unsigned char b08;
    S00d261b0_Elem* p0c;
    void UpdateMinValue(int a0, int a1);
};

// If a1's f10 is below f04, stores it in f04, copies v00, f10 and i14 into *p0c, sets p0c's slot at m_idx40 to -1, and sets b08 to 1.
// @f3 0x009a7950 (community match, verified in this file)
// pdb: `anonymous namespace'::NearestHitCollector::addRayHit | hkpSampledHeightFieldShape.obj | fnv360_0822_retail, vtable, high
// pdb params: cdBody, hitInfoIn
void S00d261b0_cls::UpdateMinValue(int a0, int a1)
{
    S00d261b0_Elem* e = (S00d261b0_Elem*)a1;
    if (e->f10 < f04)
    {
        f04 = e->f10;
        S00d261b0_Elem* dst = p0c;
        dst->v00.m128_f32[0] = e->v00.m128_f32[0];
        dst->v00.m128_f32[1] = e->v00.m128_f32[1];
        dst->v00.m128_f32[2] = e->v00.m128_f32[2];
        dst->v00.m128_f32[3] = e->v00.m128_f32[3];
        p0c->f10 = e->f10;
        dst=*(S00d261b0_Elem* volatile*)&p0c;
        dst->i14=e->i14;
        p0c->m_slots[p0c->m_idx40] = -1;
        b08 = 1;
    }
}


extern int DAT_010ce310;

struct Arg3 {
    int unk00;
    float m_04;
};

struct Local12 {
    void* m_00;
    float m_04;
    const Arg3* m_08;
};

struct Val1 {
    unsigned char m_00;
    Val1() : m_00(0) {}
    Val1(const Val1& o) : m_00(o.m_00) {}
};

struct Host {
    void FUN_00d24b50(int a1, int a2, Val1 v, float f, Local12* pLocal);
    void hkpSampledHeightFieldShape_castRayWithCollectorImpl(int a1, int a2, const Arg3* a3);
};

// Builds a local record from DAT_010ce310 and a3 (its float and pointer), then calls FUN_00d24b50 with a1, a2, a default Val1, 0.0f and that record.
// @fnv 0x00d260d0
// pdb: hkpSampledHeightFieldShape::castRayWithCollectorImpl | hkpSampledHeightFieldShape.obj | fnv360_0822_retail, uvref + bridge(uvref|vtable) + skyrim(uvref), high
void Host::hkpSampledHeightFieldShape_castRayWithCollectorImpl(int a1, int a2, const Arg3* a3)
{
    Local12 local;
    local.m_00 = &DAT_010ce310;
    local.m_04 = a3->m_04;
    local.m_08 = a3;
    FUN_00d24b50(a1, a2, Val1(), 0.0f, &local);
}

struct __declspec(align(16)) RayData {
    float x; float y; float z; float w;
    float endX; float endY; float endZ; float endW;
    float extraX; float extraY; float extraZ; float extraW;
};

struct Input {
    RayData base;
    float f30;
    float f34;
};

struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;

    void FUN_00d24b50(RayData* data, void* arg2, hkBoolD260 arg3, float arg4, void* arg5);
    void hkpSampledHeightFieldShape_castSphere(Input* input, void* arg2, void* arg3);
};

// Copies the input ray, offsets its Y and endY by a signed value, and calls FUN_00d24b50 with the modified ray.
// @fnv 0x00d26120
// pdb: hkpSampledHeightFieldShape::castSphere | hkpSampledHeightFieldShape.obj | fnv360_0822_retail, objrun + bridge(hash|vtable) + skyrim(hash), high
void Obj::hkpSampledHeightFieldShape_castSphere(Input* input, void* arg2, void* arg3) {
    float a = input->f30;
    RayData local = input->base;

    if (this->unk24 > 0.0f)
        a = -a;

    local.y += a;
    local.endY += a;

    this->FUN_00d24b50(&local, arg2, true, input->f34, arg3);
}

__declspec(align(16)) const hkVector4 halfScale = {0.5f, 0.5f, 0.5f, 0.5f};
