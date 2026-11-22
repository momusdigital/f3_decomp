// src/havok/common/base/math/util/hkmathutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/util/hkmathutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
extern float DAT_01011d78;
extern float DAT_01012068;

struct __declspec(align(16)) S_c7a410_Vec
{
    float x, y, z, w;
};
struct S_c7a410_A
{
    void FUN_00cb26e0(const void* p);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_c7a410_B
{
    void FUN_00cb2d90(const void* p);
    __m128 r[3];
};
struct S_c7a410_C
{
    void FUN_00c66320(const void* p, S_c7a410_A* a);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_c7a410_D
{
    void FUN_00c74b70(S_c7a410_A* b, S_c7a410_C* c);
    void FUN_00cb2ca0(const S_c7a410_Vec* v, const void* o, float* out);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_c7a410_Node
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType();
    S_c7a410_Node* FUN_00cdf6c0();
    void FUN_00cdf230(S_c7a410_B* t);
};
struct S_c7a410_Item
{
    int unk00;
    int unk04;
    int unk08;
    S_c7a410_Node* unk0c;
};
struct S_c7a410_Cnt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_c7a410_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_c7a410_Item** unk14;
    int unk18;
    int unk1c;
    int* unk20;
    int unk24;
    int unk28;
    S_c7a410_Cnt* unk2c;
};

// Iterates indexed items, dispatches on node type, and reads per-item data from arr at 0x10 plus 0x30-byte strides.
// @f3 0x008dcb80 (community match, verified in this file)
#include <xmmintrin.h>

struct TNode;

struct V4
{
    float x, y, z, w;
};

struct __declspec(align(16)) TB
{
    void hkRotation_set(const void* p);
    V4 r0;
    V4 r1;
    V4 r2;
};

struct TA
{
    void FUN_00924360(const void* p);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct TC
{
    void FUN_008d3290(const void* p, TA* a);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct TD
{
    void FUN_008db720(TA* b, TC* c);
    void FUN_00924a70(const S_c7a410_Vec* v, const void* o, float* out);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct TNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int GetType();
    TNode* FUN_0095b0f0();
    void FUN_00959ee0(TB* t);
};

// pdb: bhkRagdollController::bhkRagdollPoweredConstraintController::driveToPose | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkaRagdollPoweredConstraintController::driveToPose)
// pdb params: ragdoll, desiredPose
void FUN_00c7a410(S_c7a410_Obj* obj, char* apBuffer)
{
    int iCount = obj->unk2c->unk10;
    for (int iIndex = 0; iIndex < iCount; iIndex++)
    {
        int iArrayIndex = obj->unk20[iIndex] - 1;
        if (iArrayIndex < 0)
            continue;
        S_c7a410_Item* pItem = obj->unk14[iArrayIndex];
        if (!pItem)
            continue;
        TNode* p = (TNode*)pItem->unk0c;
        if (p->GetType() == 13)
            p = p->FUN_0095b0f0();
        switch (p->GetType())
        {
        case 7:
        {
            TB tTransform;
            tTransform.hkRotation_set(apBuffer + 0x10 + iIndex * 0x30);
            p->FUN_00959ee0(&tTransform);
            break;
        }
        case 2:
        {
            TA a;
            a.FUN_00924360((char*)p + 0x20);
            TA b;
            b.FUN_00924360((char*)p + 0x60);
            TC c;
            ((TC*)&c)->FUN_008d3290(apBuffer + 0x10 + iIndex * 0x30, &a);
            TD d;
            ((TD*)&d)->FUN_008db720(&b, &c);
            S_c7a410_Vec v;
            v.x = 1.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            v.w = 0.0f;
            float out;
            TA o;
            ((TD*)&d)->FUN_00924a70(&v, &o, &out);
            *(float*)((char*)p + 0xac) = out;
            break;
        }
        }
    }
}

