#include "f3_common.h"
// src/havok/common/base/types/physics/motionstate/hkmotionstate.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/physics/motionstate/hkmotionstate.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMotionState.h"

struct FUN_00c9ea90_Base
{
    virtual void b0();
    FUN_00c9ea90_Base(int a, int b);
};

struct FUN_00c9ea90 : FUN_00c9ea90_Base
{
    virtual void v0();
    FUN_00c9ea90(int a1);
};

struct __declspec(align(16)) FUN_00827200_class
{
    int unk00;
    int unk04;
    void __thiscall FUN_00cb26e0(int);
};

struct FUN_00cf2410_class
{
    int __thiscall FUN_00cf2410(int, void*);
};

class FUN_00c9ea40_cls : public FUN_00c9ea90
{
  public:
    virtual ~FUN_00c9ea40_cls();
    virtual void v1();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkMotionState* m_motionPtr;
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
    hkMotionState m_swept;

    FUN_00c9ea40_cls(int a, int b);
};

// Calls the base constructor, initializes a temporary from b, passes it with b + 0x30 to FUN_00cf2410, and points m_motionPtr at m_swept.
// @f3 0x0090de70 (community match, verified in this file)
struct TmpStub
{
    void __thiscall FUN_00924360(int);
};

struct SweptStub
{
    int __thiscall hkMotionState_initMotionState(int, void*);
};

// pdb: hkpShapePhantom::hkpShapePhantom | hkpShapePhantom.obj | fnv360_0822_retail, uvref, high
// pdb params: shape, transform
FUN_00c9ea40_cls::FUN_00c9ea40_cls(int a, int b) : FUN_00c9ea90(a)
{
    FUN_00827200_class tmp;
    ((TmpStub*)&tmp)->FUN_00924360(b);
    SweptStub* pSwept = (SweptStub*)((char*)this + 0xa0);
    pSwept->hkMotionState_initMotionState(b + 0x30, &tmp);
    *(hkMotionState**)((char*)this + 0x18) = (hkMotionState*)((char*)this + 0xa0);
}

