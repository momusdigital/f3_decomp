#include "f3_common.h"
// src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Stand-ins for the script handler functions whose addresses are stored in the
// handler table (0xd417b0 .. 0xd40d80).  Only declared, never defined.
extern "C" void __cdecl hkPredGskAgent3_removePoint(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskAgent3_commitPotential(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskAgent3_createZombie(int a, int b, int c, int d);
extern "C" void __cdecl FUN_00d41930(int a, int b, int c, int d);
// The handler table that is handed to CScript::RegisterHandler.  It is kept
// 16 byte aligned, which is what makes the compiler emit the aligned frame
// prologue of this function.
struct __declspec(align(16)) HandlerTable
{
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* p6;
    void* p7;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    int unk34;
    int unk38;
    int unk3C;
};
// Stand-in for the script object: the registration is a __thiscall member.
struct S_00d417b0_Entry
{
    short unk00;
    short m_iOwnerObjectOffset;
    int unk04;
};
struct S_00d417b0_Sub
{
    short unk00;
    unsigned char m_uiItemCount;
    char unk03;
    S_00d417b0_Entry m_entries[1];
};
struct S_00d417b0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00d417b0_Sub m_sub;
};
void __cdecl hkPredGskAgent3_removePoint(int a, S_00d417b0_Obj* obj, short id);
struct Slot
{
    unsigned short id;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
};
struct Table
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    unsigned short unk10;
    Slot slots[1];
};
void __cdecl hkPredGskAgent3_commitPotential(int a, Table* table, unsigned short value);
struct FUN_00d41830_entry
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short key02;
    unsigned int unk04;
};
struct FUN_00d41830_table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    FUN_00d41830_entry entries[8];
};
int __cdecl hkPredGskAgent3_createZombie(int unused, FUN_00d41830_table* table, unsigned short key);

#include <xmmintrin.h>
class hkpConvexShape_s
{
  public:
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1C();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2C();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, void* out) const;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
};

struct hkpCdBody_s
{
    hkpConvexShape_s* m_pCollisionShape;
    int unk04;
    void* m_kMotionState;
};

struct hkpGskCache_s
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_verticesDim;
    unsigned char m_flags;
};

struct Gsk_s
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_numA;
    int m_numB;
    int m_unk10;
    int m_cacheChanged;
    int m_pad18;
    int m_pad1C;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;

    void __thiscall ComputeClosestPoints(hkpConvexShape_s* a, hkpConvexShape_s* b, void* t, void* out);
    void __thiscall writeToCache(hkpGskCache_s* cache);
};

struct Input_s
{
    hkpCdBody_s* m_pBodyA;
    hkpCdBody_s* m_pBodyB;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_kMotionTransform;
};

struct Output_s
{
    union
    {
        __m128 v;
        struct
        {
            float nx;
            float ny;
            float nz;
            float m_fClosestPointDistanceSquared;
        };
    };
};

struct SeparatingNormal
{
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

// @f3 0x009cc140 (community match, verified in this file)
struct FNV_Shape13
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, void* out) const;
};

// pdb: hkPredGskAgent3::sepNormal | hkpPredGskAgent3.obj | fnv360_0822_debug, objrun, medium
// pdb params: input, entry, agentData, separatingNormalOut
void __cdecl FUN_00d41930(Input_s* input, int unused, hkpGskCache_s* cache, Output_s* output)
{
    hkpConvexShape_s* shapeA = input->m_pBodyA->m_pCollisionShape;
    hkpConvexShape_s* shapeB = input->m_pBodyB->m_pCollisionShape;
    SeparatingNormal norm;
    Gsk_s gsk;
    gsk.m_unk10 = 0;
    gsk.m_ucDimensionB = cache->m_ucDimensionB;
    gsk.m_ucDimensionA = cache->m_ucDimensionA;
    gsk.m_numA = cache->m_verticesDim & 0xf;
    gsk.m_numB = cache->m_verticesDim >> 4;
    gsk.m_cacheChanged = 0;
    ((FNV_Shape13*)shapeA)->GetVerticesForIds(cache->m_kVertices, gsk.m_ucDimensionA, &gsk.unk20);
    ((FNV_Shape13*)shapeB)->GetVerticesForIds(&cache->m_kVertices[gsk.m_ucDimensionA], gsk.m_ucDimensionB, &gsk.unkE0);
    gsk.ComputeClosestPoints(shapeA, shapeB, &input->unk10, &norm);
    if (gsk.m_cacheChanged)
        gsk.writeToCache(cache);
    const float* rot = (const float*)input->m_pBodyA->m_kMotionState;
    float nx = norm.x;
    float ny = norm.y;
    float nz = norm.z;
    output->nx = rot[4] * ny + rot[0] * nx + rot[8] * nz;
    output->ny = rot[5] * ny + rot[1] * nx + rot[9] * nz;
    output->nz = rot[6] * ny + rot[2] * nx + rot[10] * nz;
    *(volatile float*)&output->m_fClosestPointDistanceSquared = 0.0f;
    output->m_fClosestPointDistanceSquared = norm.w - (shapeB->m_fSphereRadius + shapeA->m_fSphereRadius);
}

