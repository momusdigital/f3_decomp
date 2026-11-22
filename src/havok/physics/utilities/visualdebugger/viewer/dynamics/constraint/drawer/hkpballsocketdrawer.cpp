#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpballsocketdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpballsocketdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
};
struct hkTransform
{
    hkVector4 c0, c1, c2, t;
};

struct Motion
{
    hkVector4 v00;
    hkVector4 v10;
    hkVector4 v20;
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Motion motion;
};
struct Body
{
    int unk00;
    int unk04;
    int unk08;
    Shape* shape;
};
struct Vec
{
    hkVector4 v;
    void FUN_00c7f640(const void* m, const hkVector4& p);
};
struct Sub
{
    void FUN_00e10a10(void* a);
};
struct Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void Fire(Vec* a, Vec* b, unsigned c, int d, int e);
};
struct Obj
{
    char pad[0x40];
    Vec m40;
    Vec m50;
    char pad2[0x60];
    Sub mC0;
    void FUN_00de47e0(Body* b, hkTransform* t, hkTransform* r);
    void FUN_00de44c0(int a, int b);
    void FUN_00de4530(int a, int b);
    void FireMotionEvent(Body* b, Listener* l, int a);
};

// Computes transforms from the body's shape motion, updates m40/m50 vectors, calls FUN_00de44c0/FUN_00de4530, then fires the listener with both vectors.
// @f3 0x00a6f260 (community match, verified in this file)
struct VecM
{
    hkVector4 v;
    void hkVector4_setTransformedPos(const void* m, const hkVector4& p);
};
struct SubM
{
    void FUN_00a8f460(void* a);
};
struct ListenerM
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Fire(Vec* a, Vec* b, unsigned c, int d);
};
struct ObjM
{
    char pad[0x40];
    Vec m40;
    Vec m50;
    char pad2[0x60];
    SubM mC0;
    void FUN_00a6aa20(Body* b, hkTransform* t, hkTransform* r);
    void FUN_00a6a750(int a);
    void FUN_00a6a7b0(int a);
};
// pdb: hkpBallSocketDrawer::drawConstraint | hkpBallSocketDrawer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: constraint, displayHandler, id, tag
void Obj::FireMotionEvent(Body* apBody, Listener* apListener, int aiArg)
{
    ObjM* pSelf = (ObjM*)this;
    ListenerM* pListener = (ListenerM*)apListener;
    Motion* pMotion = &apBody->shape->motion;
    pSelf->mC0.FUN_00a8f460(apListener);
    hkTransform r;
    hkTransform t;
    pSelf->FUN_00a6aa20(apBody, &t, &r);
    Vec* pVec40;
    Vec* pVec50;
    pVec50 = &m50;
    ((VecM*)pVec50)->hkVector4_setTransformedPos(&t, pMotion->v20);
    pVec40 = &m40;
    ((VecM*)pVec40)->hkVector4_setTransformedPos(&r, pMotion->v10);
    pSelf->FUN_00a6a750(aiArg);
    pSelf->FUN_00a6a7b0(aiArg);
    pListener->Fire(pVec40, pVec50, 0xffff0000, aiArg);
}

