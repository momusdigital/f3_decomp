#include "f3_common.h"
// src/havok/physics/dynamics/entity/hkprigidbody.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkprigidbody.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00ca86c0_class
{
    unsigned char __thiscall FUN_00ca86c0();
};
// @f3 0x005af1d0 (community match, verified in this file)
// pdb: NiTask::Clear | BSTECreateTask.obj | fnv360_0822_retail, vtable, medium
unsigned char FUN_00ca86c0_class::FUN_00ca86c0()          // ORIG entry at 0x005af1d0, nineteen bytes ✓⚠',
{                                                             //     their unit declares this struct with NO data ⚠✓',
    unsigned int kind = *(unsigned int*)((char*)this + 8);    //     members, and their own bodies cast through raw ✗✓',
                                                              //     pointers - same style used here ✓⚠',
                                                              // ORIG: mov eax, dword ptr [ecx+8] ⇒ one load ⚠✓',
    if (kind == 4u || kind == 3u)                             // ORIG: cmp eax,4 ; je tail ; cmp eax,3 ; je tail ✓⚠',
    {                                                         //     two separate compares jumping to ONE shared tail ✗✓',
        return 1u;                                            // ORIG tail at +10h: mov al,1 ; ret ✓⚠',
    }                                                         //     - not a single combined test ✗✓',
    return 0u;                                                // ORIG fallthrough: xor al,al ; ret ⇒ zero flag ✗✓',
}                                                             //     value in AL with no store anywhere ⚠✓'


struct FUN_00ca88c0_Class
{
    void FUN_00ca88c0(float f);
};

// @f3 0x0090c710 (community match, verified in this file)
// pdb: bhkConvexShape::GetCinfo | bhkConvexShape.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: hkpRigidBody::setMass)
void FUN_00ca88c0_Class::FUN_00ca88c0(float afValue)
{
    ((void(__thiscall*)(void*, float))(*(void**)(*(int*)((char*)this + 0xd0) + 12)))((char*)this + 0xd0, afValue);
}


extern float DAT_01016248;
struct Vector3
{
    float x, y, z;
};
struct Output
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48;
    float value;
};
inline float lowerPair(float left, float right)
{
    return left < right ? left : right;
}
inline float lowerPairReversed(float left, float right)
{
    return left > right ? right : left;
}
// Computes the minimum of the three components of values and stores 0.2 times it in result->value if below DAT_01016248, otherwise 0.1.
// @f3 0x0090c7b0 (community match, verified in this file)
struct Output_0090c7b0
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44;
    float value;
};
// pdb: hkpEntity::setCachedShapeData | hkpEntity.obj | fnv360_0721_beta, call_gap, low, conflict (skyrim: estimateAllowedPenetrationDepth)
// pdb params: world, shape
void __fastcall ComputeScaledMinimum(const Vector3* values, Output* result)
{
    float firstMinimum = lowerPair(values->x, values->y);
    float minimum = lowerPair(firstMinimum, values->z);
    Output_0090c7b0* out = (Output_0090c7b0*)result;
    if (DAT_01016248 > minimum)
        out->value = 0.2 * minimum;
    else
        out->value = 0.1f;
}


struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};
struct Subobject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void update(unsigned int value);
};
struct Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Subobject subobjectE0;
    void FUN_00ca8150(unsigned int value, Vec4* result);
    void hkpRigidBody_setCenterOfMassLocal(unsigned int value);
};
// @f3 0x0090cdb0 (community match, verified in this file)
struct FUN_00ca85f0_Layout
{
    char m_unk00[0x10];
    unsigned int m_unk10;               // +0x10
    char m_unk14[0xd0 - 0x14];
    Subobject m_sub;                    // +0xd0
};

struct FUN_00ca85f0_Self : Owner
{
    void hkpRigidBody_updateCachedShapeInfo(unsigned int value, Vec4* result);
};

// pdb: hkpRigidBody::setCenterOfMassLocal | hkpRigidBody.obj | fnv360_0822_retail, call_gap + bridge(caller_sim|caller_sim) + skyrim(call_gap), high
void Owner::hkpRigidBody_setCenterOfMassLocal(unsigned int value)
{
    Vec4 vec;
    FUN_00ca85f0_Layout* self = (FUN_00ca85f0_Layout*)this;
    self->m_sub.update(value);
    ((FUN_00ca85f0_Self*)this)->hkpRigidBody_updateCachedShapeInfo(self->m_unk10, &vec);
}


struct AudioInterface;
struct AudioInterfaceVTable
{
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1C;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2C;
    void(__thiscall* dispatch)(AudioInterface*, int);
};
struct AudioInterface
{
    AudioInterfaceVTable* vtbl;
};
struct FUN_00ca8800_Class
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
    AudioInterface interfaceE0;
    void hkpRigidBody_setPosition(int value);
};
extern "C" void __cdecl FUN_00ca8700(FUN_00ca8800_Class* self);
// Calls the interface's dispatch with value, then invokes FUN_00ca8700 on this object.
// @f3 0x0090d5f0 (community match, verified in this file)
struct FUN_00ca8800_ClassOrig
{
    int pad00, pad04, pad08, pad0c, pad10, pad14, pad18, pad1c;
    int pad20, pad24, pad28, pad2c, pad30, pad34, pad38, pad3c;
    int pad40, pad44, pad48, pad4c, pad50, pad54, pad58, pad5c;
    int pad60, pad64, pad68, pad6c, pad70, pad74, pad78, pad7c;
    int pad80, pad84, pad88, pad8c, pad90, pad94, pad98, pad9c;
    int padA0, padA4, padA8, padAC, padB0, padB4, padB8, padBC;
    int padC0, padC4, padC8, padCC;
    AudioInterface interface;
};

// pdb: hkpRigidBody::setPosition | hkpRigidBody.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
void FUN_00ca8800_Class::hkpRigidBody_setPosition(int value)
{
    FUN_00ca8800_ClassOrig* self = (FUN_00ca8800_ClassOrig*)this;
    self->interface.vtbl->dispatch(&self->interface, value);
    FUN_00ca8700(this);
}


struct CA8830Member
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void setValue(int value);
};

struct CA8830Object;

void __cdecl FUN_00ca8700(CA8830Object* obj);

struct CA8830Object
{
    char unk000[0xe0];
    CA8830Member m_kMemberDescriptor;

    void FUN_00ca8830(int value);
};

struct SubObject;

typedef void(__thiscall* SubDoFn)(SubObject* apThis, int aiFirst, int aiSecond);

struct SubObjectVtbl
{
    void* fn00;
    void* fn04;
    void* fn08;
    void* fn0c;
    void* fn10;
    void* fn14;
    void* fn18;
    void* fn1c;
    void* fn20;
    void* fn24;
    void* fn28;
    void* fn2c;
    void* fn30;
    void* fn34;
    SubDoFn Do;
};

struct SubObject
{
    SubObjectVtbl* m_pVtbl;
};

void __cdecl FUN_00ca8700(void* apOwner);

struct FUN_00ca8860_cls
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
    SubObject m_sub;
    void hkpRigidBody_setPositionAndRotation(int aiFirst, int aiSecond);
};

// Calls the sub-object's Do virtual with aiFirst and aiSecond, then invokes FUN_00ca8700 on this.
// @f3 0x0090d650 (community match, verified in this file)
struct FUN_00ca8860_body
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
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    SubObject m_sub;
};

// pdb: hkpRigidBody::setPositionAndRotation | hkpRigidBody.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap), high
void FUN_00ca8860_cls::hkpRigidBody_setPositionAndRotation(int aiFirst, int aiSecond)
{
    FUN_00ca8860_body* body = (FUN_00ca8860_body*)this;
    body->m_sub.m_pVtbl->Do(&body->m_sub, aiFirst, aiSecond);
    FUN_00ca8700(this);
}


struct BaseRecord
{
    virtual void v00();

    int m_i04;
    char m_c08;

    BaseRecord(void* apFirst, void* apSecond, int aiFlag);
};

struct FUN_00ca9270 : BaseRecord
{
    FUN_00ca9270(void* apFirst, void* apSecond);
};

// Constructs the object by forwarding apFirst and apSecond to BaseRecord with flag 0, then sets m_c08 to 2.
// @fnv 0x00ca9270
// pdb: hkpSphereMotion::hkpSphereMotion | hkpRigidBody.obj | tesv_win, hash, low
FUN_00ca9270::FUN_00ca9270(void* apFirst, void* apSecond) : BaseRecord(apFirst, apSecond, 0)
{
    m_c08 = 2;
}

struct S_00ca8630_Owner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
};
struct S_00ca8630_Sub
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0a;
    unsigned short unk0c;
    void hkpMotion_setWorldSelectFlagsNeg(int a, int b, int c);
    __forceinline void Set(unsigned char v, int a, int b, int c)
    {
        unk09 = v;
        hkpMotion_setWorldSelectFlagsNeg(a, b, c);
    }
};
struct S_00ca8630_Class
{
    unsigned int unk00;
    unsigned int unk04;
    S_00ca8630_Owner* unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned char unkd4;
    unsigned char unkd5;
    unsigned char unkd6;
    unsigned char unkd7;
    unsigned int unkd8;
    unsigned int unkdc;
    S_00ca8630_Sub unke0;
    void FUN_00ca8630(bool f);
};
// @f3 0x0090c670 (community match, verified in this file)
namespace n90c670 {
struct Owner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned char unk2c4;
    unsigned char unk2c5;
    unsigned char unk2c6;
    unsigned char unk2c7;
    unsigned int unk2c8;
};
struct View
{
    unsigned int unk00;
    unsigned int unk04;
    Owner* unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned char unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    S_00ca8630_Sub unkd0;
    __forceinline void Apply(int mode);
};

void View::Apply(int mode)
{
    switch (mode)
    {
    case 1:
        unkd0.unk09 = 0xff;
        unkd0.unk0a = 0;
        unkd0.unk0c = 0;
        break;
    case 2:
        if (unk08)
        {
            Owner* volatile* pv = (Owner* volatile*)&unk08;
            Owner* o = *pv;
            int c = o->unk2c7;
            int b = o->unk2c6;
            int a = o->unk2c5;
            unkd0.Set(unkc0 & 0xf, a, b, c);
        }
        else
        {
            unkd0.Set(unkc0 & 0xf, 0, 0, 0);
        }
        break;
    }
}
}

// pdb: hkpRigidBody::enableDeactivation | hkpRigidBody.obj | fnv360_0822_retail, call_gap, medium, conflict (bridge: hkpMotion::enableDeactivation)
// pdb params: _enableDeactivation
void S_00ca8630_Class::FUN_00ca8630(bool f)
{
    reinterpret_cast<n90c670::View*>(this)->Apply(*(int*)&f);
}


struct CA8890Member
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void setValue(int value);
};

struct CA8890Object;

void __cdecl FUN_00ca8700(CA8890Object* obj);

struct CA8890Object
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
    CA8890Member m_kMemberDescriptor;

    void FUN_00ca8890(int value);
};

struct CA92A0Allocator;

struct CA92A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA92A0Allocator* m_pStreamAllocator;

    CA92A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CA92A0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(CA92A0Allocator* alloc, void* array, int numElements, int sizeElem);

struct CA92A0Element
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};

struct CA92A0Array
{
    CA92A0Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void reserve(CA92A0Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(CA92A0Element));
        }
    }

    __forceinline CA92A0Array& operator=(const CA92A0Array& a)
    {
        CA92A0Allocator& alloc = FUN_00c85750().heap();
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        {
            const CA92A0Element* src = a.m_data;
            CA92A0Element* dst = m_data;
            for (int i = 0; i < copiedSize; i++)
                dst[i] = src[i];
        }
        {
            const CA92A0Element* src = a.m_data + copiedSize;
            CA92A0Element* dst = m_data + copiedSize;
            for (int i = 0; i < newSize - copiedSize; i++)
                new (dst + i) CA92A0Element(src[i]);
        }
        m_iElementCount = newSize;
        return *this;
    }
};

struct CA92A0Object
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
    CA92A0Array m_entries;

    void CopyEntriesFrom(const CA92A0Object* other);
};

// Copies the m_entries array from other into this object's m_entries via the array assignment operator.
// @fnv 0x00ca92a0
void CA92A0Object::CopyEntriesFrom(const CA92A0Object* other)
{
    m_entries = other->m_entries;
}

struct CA92A0Allocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
};

static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}

__declspec(align(16)) struct FnvScratch
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
    void FUN_00cf5ea0();
};

struct FUN_00ca90c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    FUN_00ca90c0_cls* Clone();
    void hkpRigidBody_getCinfo(FnvScratch* pScratch);
    FUN_00ca90c0_cls* FUN_00ca8c90(FnvScratch* pScratch);
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int v10();
    void CopyEntriesFrom(FUN_00ca90c0_cls* pSrc);
};

// @f3 0x0090d3e0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
extern int DAT_0126988c;

struct EntityThreadMemory
{
    void* alloc(int nbytes, int memClass);
};

struct EntityMotionBlock
{
    int vtbl;
    unsigned short memSize;
    unsigned short refCount;
};

static __forceinline void EntityCopyQuads(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}

// pdb: hkpRigidBody::clone | hkpRigidBody.obj | fnv360_0822_retail, vtable, medium
FUN_00ca90c0_cls* FUN_00ca90c0_cls::Clone()
{
    FnvScratch cinfo;
    cinfo.FUN_00cf5ea0();
    hkpRigidBody_getCinfo(&cinfo);
    EntityThreadMemory* mem = (EntityThreadMemory*)TlsGetValue(DAT_010f3170);
    FUN_00ca90c0_cls* pBlock = (FUN_00ca90c0_cls*)mem->alloc(0x200, 0x2d);
    *(unsigned short*)((char*)pBlock + 4) = 0x200;
    FUN_00ca90c0_cls* pCopy = pBlock->FUN_00ca8c90(&cinfo);
    EntityCopyQuads((char*)pCopy + 0xd0, (char*)this + 0xd0, 0x12);
    if (*(void**)((char*)this + 0x1e8))
    {
        EntityThreadMemory* mem2 = (EntityThreadMemory*)TlsGetValue(DAT_010f3170);
        EntityMotionBlock* pMotion = (EntityMotionBlock*)mem2->alloc(0x120, 0x2e);
        pMotion->memSize = 0x120;
        pMotion->refCount = 1;
        *(int*)((char*)pMotion + 0x118) = 0;
        pMotion->vtbl = (int)&DAT_0126988c;
        *(EntityMotionBlock**)((char*)pCopy + 0x1e8) = pMotion;
        EntityCopyQuads(pMotion, *(void**)((char*)this + 0x1e8), 0x12);
    }
    *(int*)((char*)pCopy + 0x18) = pCopy->v10();
    pCopy->CopyEntriesFrom(this);
    *(int*)((char*)pCopy + 0x70) = *(int*)((char*)this + 0x70);
    pCopy->unk08 = unk08;
    return pCopy;
}


class hkBoolCA8B
{
  public:
    hkBoolCA8B(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

struct S_00ca84b0_Shape
{
    void RetainReference();  // FUN_00c90510
    void removeReference();  // FUN_00c905b0
};

struct S_00ca84b0_Entity;

struct S_00ca84b0_Op
{
    unsigned char m_type;
    S_00ca84b0_Entity* m_pEntity;
    S_00ca84b0_Shape* m_pCollisionShape;
};

struct S_00ca84b0_World
{
    void FUN_00c91160(const S_00ca84b0_Op& op);
    void FUN_00c91120();
    void FUN_00c91140();

    __forceinline void lockCriticalOperations()
    {
        unk94++;
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unk94--;
        if (unk94 == 0 && !unk9c)
        {
            if (unk8c)
                FUN_00c91120();
            if (unka4 == 1 && unk90)
                FUN_00c91140();
        }
    }

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    unsigned char unk9c;
    int unka0;
    int unka4;
};

struct S_00ca84b0_Vector4
{
    float x, y, z, w;
};

// Same-unit static helper (0x00ca80d0): the allowed penetration depth is a fifth of the
// smallest extent, or 0.1 once that extent reaches 0.5.
static __declspec(noinline) void ComputeScaledMinimum(void* pvCollidable, const S_00ca84b0_Vector4& kExtent)
{
    const float* pfExtent = (const float*)&kExtent;
    float fMin = pfExtent[0];
    if (pfExtent[1] < fMin)
        fMin = pfExtent[1];
    if (pfExtent[2] < fMin)
        fMin = pfExtent[2];
    float* pfDepth = (float*)((char*)pvCollidable + 0x4c);
    if (fMin < 0.5f)
        *pfDepth = (float)(fMin * 0.2);
    else
        *pfDepth = 0.1f;
}

class hkClass;
class hkStatisticsCollector;
// hkpRigidBody: the seven slots of its Fallout 3 vtable (0x00e35e28), named as the New Vegas Xbox 360 PDB names them.
struct S_00ca84b0_Entity
{
    virtual ~S_00ca84b0_Entity();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int setShape(const S_00ca84b0_Shape* shape);
    virtual void* getMotionState();
    virtual void deallocateInternalArrays();
    virtual S_00ca84b0_Entity* clone() const;
    int unk4;
    S_00ca84b0_World* m_pOwningWorld;
    int unkc;
    S_00ca84b0_Shape* m_pCollisionShape;
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
    float m_fAllowedPenetrationDepth;  // 0x5c

    void FUN_00ca8150(S_00ca84b0_Shape* shape, S_00ca84b0_Vector4* extentOut);
    void UpdateBoundingVolume(S_00ca84b0_World* world, S_00ca84b0_Shape* shape);
    int hkpRigidBody_setShape(S_00ca84b0_Shape* shape);
};

// Sets the entity's collision shape, updating penetration depth and notifying the owning world of the change.
// @f3 0x0090cc60 (community match, verified in this file)
extern const double FUN_00de7348;

struct S_00ca84b0_WorldStub

{

    void FUN_00902570(const S_00ca84b0_Op& op);

    void FUN_00902550();

};

struct S_00ca84b0_EntityStub

{

    void hkpRigidBody_updateCachedShapeInfo(S_00ca84b0_Shape* shape, S_00ca84b0_Vector4* extentOut);

    void FUN_0090b280(S_00ca84b0_World* world, S_00ca84b0_Shape* shape);

};

struct S_00ca84b0_RefShape

{

    virtual ~S_00ca84b0_RefShape();  // hkReferencedObject

    unsigned short refFlag;

    short refCount;

};

void hkpWorldOperationUtil_removeEntityBP(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);

void hkpWorldOperationUtil_addEntityBP(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);

void hkpWorldCallbackUtil_fireEntityShapeSet(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);

void hkpEntityCallbackUtil_fireEntityShapeSet(S_00ca84b0_Entity* entity);

static __forceinline float Minimum90c7(float a,float b){return a<b?a:b;}
static __declspec(noinline) void FUN_0090c7b0(void* collidable,const S_00ca84b0_Vector4& extent){
 float minimum=Minimum90c7(Minimum90c7(extent.x,extent.y),extent.z);
 float* depth=reinterpret_cast<float*>(static_cast<char*>(collidable)+0x48);
 if(minimum<0.5f)*depth=(float)(minimum*0.2);else *depth=0.1f;
}



// pdb: hkpRigidBody::setShape | hkpRigidBody.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
int S_00ca84b0_Entity::hkpRigidBody_setShape(S_00ca84b0_Shape* shape)

{

    if (m_pOwningWorld && m_pOwningWorld->unk84)

    {

        S_00ca84b0_Op op;

        op.m_type = 5;

        op.m_pEntity = this;

        op.m_pCollisionShape = shape;

        ((S_00ca84b0_WorldStub*)m_pOwningWorld)->FUN_00902570(op);

        return 0;

    }



    if (m_pOwningWorld)

        ((S_00ca84b0_EntityStub*)this)->FUN_0090b280(m_pOwningWorld, shape);

    if (m_pOwningWorld)

    {

        m_pOwningWorld->unk84++;

        hkpWorldOperationUtil_removeEntityBP(m_pOwningWorld, this);

    }



    S_00ca84b0_Shape* oldShape = m_pCollisionShape;

    m_pCollisionShape = shape;

    if (((S_00ca84b0_RefShape*)shape)->refFlag)

        ((S_00ca84b0_RefShape*)shape)->refCount++;

    S_00ca84b0_RefShape* oldRef = (S_00ca84b0_RefShape*)oldShape;

    if (oldRef && oldRef->refFlag)

    {

        oldRef->refCount += -1;

        if (oldRef->refCount == 0)

            delete oldRef;

    }



    {

        __declspec(align(16)) S_00ca84b0_Vector4 extent;

        ((S_00ca84b0_EntityStub*)this)->hkpRigidBody_updateCachedShapeInfo(shape, &extent);



        if (oldShape && (double)*(float*)&unk58 != FUN_00de7348)

            *(float*)&unk58 = -1.0f;

        if (*(float*)&unk58 <= 0.0f)

            FUN_0090c7b0(&m_pCollisionShape, extent);

    }



    if (m_pOwningWorld)

        hkpWorldCallbackUtil_fireEntityShapeSet(m_pOwningWorld, this);

    hkpEntityCallbackUtil_fireEntityShapeSet(this);

    if (m_pOwningWorld)

    {

        hkpWorldOperationUtil_addEntityBP(m_pOwningWorld, this);

        S_00ca84b0_World* world = m_pOwningWorld;

        if (--world->unk84 == 0 && !*(unsigned char*)&world->unk8c && world->unk80)

            ((S_00ca84b0_WorldStub*)world)->FUN_00902550();

    }

    return 1;

}


#include <xmmintrin.h>
namespace fnv_00ca8af0 {
struct AllocIface
{
    virtual void* unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00ca8af0

struct S_00ca8f50_Vec
{
    __m128 m_vComponents;
};
struct S_00ca8f50_Half
{
    short m_uiFilterValue;
    operator float() const
    {
        int t = ((int)m_uiFilterValue) << 16;
        return *(float*)&t;
    }
};
struct S_00ca8f50_Transform
{
    S_00ca8f50_Vec m_kColumn0;
    S_00ca8f50_Vec m_kColumn1;
    S_00ca8f50_Vec m_kColumn2;
};
struct S_00ca8f50_Sub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void getTransform(S_00ca8f50_Transform& out);
    float hkpMotion_getMass();
    int unk4;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
    int unkC;
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
};
struct S_00ca8f50_Info
{
    int m0;
    int m4;
    int m8;
    unsigned char mC;
    unsigned char unkD;
    short mE;
    S_00ca8f50_Vec m10;
    S_00ca8f50_Vec m20;
    S_00ca8f50_Vec m30;
    S_00ca8f50_Vec m40;
    S_00ca8f50_Transform m50;
    S_00ca8f50_Vec m80;
    float m90;
    float m94;
    float m98;
    float m9C;
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    float mB0;
    unsigned char mB4;
    unsigned char mB5;
    unsigned char mB6;
    unsigned char mB7;
    unsigned char mB8;
    unsigned char mB9;
    unsigned char mBA;
    unsigned char mBB;
    int unkBC;
};

struct S_00ca8f50_Src
{
    bool FUN_00ca80c0();
    void hkpRigidBody_getCinfo(S_00ca8f50_Info* info);
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int m10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char m21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char m2A;
    unsigned char unk2B;
    int m2C;
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
    float m5C;
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
    unsigned char m8C;
    unsigned char unk8D;
    unsigned char unk8E;
    unsigned char unk8F;
    float m90;
    float m94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned char unkA8;
    unsigned char unkA9;
    short mAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    unsigned char mD0;
    unsigned char mD1;
    unsigned char unkD2;
    unsigned char unkD3;
    int unkD4;
    int unkD8;
    int unkDC;
    S_00ca8f50_Sub mE0;
    S_00ca8f50_Vec m120;
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
    S_00ca8f50_Vec m160;
    S_00ca8f50_Vec m170;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    float m194;
    float m198;
    unsigned char m19C;
    unsigned char m19D;
    unsigned char m19E;
    unsigned char unk19F;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    S_00ca8f50_Vec m1B0;
    S_00ca8f50_Vec m1C0;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    unsigned char unk1FC;
    unsigned char unk1FD;
    S_00ca8f50_Half m1FE;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int m210;
    int unk214;
    int unk218;
    int unk21C;
};

// Copies fields from this S_00ca8f50_Src into the given S_00ca8f50_Info, including vectors, a transform, and lookup-table values.
// @f3 0x0090d210 (community match, verified in this file)
extern float DAT_00e35180[];
struct SrcMethodC9 { bool FUN_0090c700(); };
struct SubMethodC9 { float FUN_008f8410(); };
static __forceinline void copyFloatC9(char* out,int od,const char* in,int sd)
{
    *(float*)(out+od) = *(const float*)(in+sd);
}
// pdb: hkpRigidBody::getCinfo | hkpRigidBody.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: info
// pdb: hkpRigidBody::getCinfo | hkpRigidBody.obj | fnv360_0822_retail, bridge_fnvpc, high (was: WriteToInfo)
void S_00ca8f50_Src::hkpRigidBody_getCinfo(S_00ca8f50_Info* info)
{
    char* dst=(char*)info;
    const char* src=(const char*)this;
    *(unsigned char*)(dst+0xb6) = m21 & 1;
    *(unsigned char*)(dst+0xb4) = *(const unsigned char*)(src+0xbc);
    *(unsigned char*)(dst+0xb5) = *(const unsigned char*)(src+0xbd);
    *(unsigned short*)(dst+0x0a) = *(const unsigned short*)(src+0x96);
    *(unsigned char*)(dst+0xb1) = ((SrcMethodC9*)this)->FUN_0090c700();
    copyFloatC9(dst,0x9c,src,0x84);
    *(unsigned char*)(dst+8) = *(const unsigned char*)(src+0x80);
    copyFloatC9(dst,0xa0,src,0x88);
    copyFloatC9(dst,0x94,src,0x184);
    copyFloatC9(dst,0x98,src,0x188);
    copyFloatC9(dst,0x30,src,0x1a0);
    copyFloatC9(dst,0x34,src,0x1a4);
    copyFloatC9(dst,0x38,src,0x1a8);
    copyFloatC9(dst,0x3c,src,0x1ac);
    copyFloatC9(dst,0x40,src,0x1b0);
    copyFloatC9(dst,0x44,src,0x1b4);
    copyFloatC9(dst,0x48,src,0x1b8);
    copyFloatC9(dst,0x4c,src,0x1bc);
    S_00ca8f50_Sub* sub=(S_00ca8f50_Sub*)((char*)this+0xd0);
    info->m90=((SubMethodC9*)sub)->FUN_008f8410();
    sub->getTransform(info->m50);
    *(unsigned char*)(dst+0xb0)=*(const unsigned char*)(src+0xd8);
    *(unsigned char*)(dst+0xb2)=*(const unsigned char*)(src+0x18e);
    info->mA4=DAT_00e35180[*(const unsigned char*)(src+0x18c)];
    info->mA8=DAT_00e35180[*(const unsigned char*)(src+0x18d)];
    copyFloatC9(dst,0x10,src,0x110);
    copyFloatC9(dst,0x14,src,0x114);
    copyFloatC9(dst,0x18,src,0x118);
    copyFloatC9(dst,0x1c,src,0x11c);
    copyFloatC9(dst,0x20,src,0x150);
    copyFloatC9(dst,0x24,src,0x154);
    copyFloatC9(dst,0x28,src,0x158);
    copyFloatC9(dst,0x2c,src,0x15c);
    copyFloatC9(dst,0x80,src,0x160);
    copyFloatC9(dst,0x84,src,0x164);
    copyFloatC9(dst,0x88,src,0x168);
    copyFloatC9(dst,0x8c,src,0x16c);
    info->m4=m10;
    info->m0=m2C;
    copyFloatC9(dst,0xac,src,0x58);
    *(unsigned char*)(dst+0xb3)=m2A;
}


namespace fnv_00ca9210 {
struct S_00ca9210_Alloc
{
    virtual ~S_00ca9210_Alloc();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00ca9210_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ca9210_Alloc* m_pStreamAllocator;
    S_00ca9210_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ca9210_Router* FUN_00c85750();

struct S_00ca9210_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00ca9210_RefObj() throw()
    {}
    void operator delete(void* p)
    {
        S_00ca9210_RefObj* b = static_cast<S_00ca9210_RefObj*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

}  // namespace fnv_00ca9210

struct Entity;
struct World;

struct Manager
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void v8(void* ents, int count, World* world, int flags);
};

struct Holder5c
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void v5(int x);
};

struct World
{
    int unk00;
    int unk04;
    Manager* m_8;
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
    Holder5c* m_5c;
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
    int m_8c;
    int m_90;
    int m_94;
    int unk98;
    unsigned char m_9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unk_a0;
    int m_a4;
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
    unsigned char unk_d4;
    unsigned char unk_d5;
    unsigned char m_d6;
    void __thiscall FUN_00c91160(void* op);
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};

struct Entity
{
    int unk00;
    int unk04;
    World* m_8;
    int unk0c;
    int m_10;
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
    unsigned char m_e8;
    unsigned char* __thiscall FUN_00c9bff0(unsigned char* out);
    void __thiscall FUN_00c9c1d0();
};

struct Op
{
    unsigned char type;
    void* entity;
};

extern void __cdecl FUN_00cf9c60(void* ents, int count, World* world);
extern void __cdecl NotifyEntityRemoved(World* world, Entity* entity);

// Processes an entity by dispatching an operation, updating the world manager, and handling post-processing callbacks based on world state.
// @f3 0x0090d520 (community match, verified in this file)
struct ManagerFix;
struct FlagByte
{
    unsigned char b;
    FlagByte() : b(0) {}
    FlagByte(const FlagByte& o) : b(o.b) {}
};
struct WorldFix
{
    int unk00;
    int unk04;
    ManagerFix* m_8;
    int unk0c, unk10, unk14, unk18;
    int unk1c, unk20, unk24, unk28;
    int unk2c, unk30, unk34, unk38;
    int unk3c, unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58;
    int unk5c, unk60, unk64, unk68;
    int unk6c, unk70, unk74, unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    unsigned char m_8c;
    unsigned char unk8d, unk8e, unk8f;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0;
    unsigned char unkc4, unkc5;
    unsigned char m_c6;
    void __thiscall FUN_00c91160(void* op);
    void __thiscall FUN_00c91120();
};
struct ManagerFix
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void v8(void* ents, int count, WorldFix* world, FlagByte flags);
};

void __cdecl FUN_00ca8700(Entity* apEntity)
{
    Op op;
    Entity* ents[1];

    WorldFix* world = (WorldFix*)apEntity->m_8;

    if (!world)
        return;

    if (world->unk84 != 0)
    {
        op.type = 0x15;
        op.entity = apEntity;
        world->FUN_00c91160(&op);
        return;
    }

    world->unk84 = 1;
    {
        ents[0] = apEntity;
        world->m_8->v8(ents, 1, world, FlagByte());

        if (apEntity->m_10 != 0)
            FUN_00cf9c60(ents, 1, (World*)world);
    }

    {
        unsigned char flag;
        if (!*apEntity->FUN_00c9bff0(&flag))
        {
            if (world->m_c6 != 0 && *(unsigned char*)&apEntity->unkd8 != 7)
                apEntity->FUN_00c9c1d0();
            NotifyEntityRemoved((World*)world, apEntity);
        }
    }

    world->unk84 -= 1;
    if (world->unk84 == 0 && world->m_8c == 0 && world->unk80 != 0)
        world->FUN_00c91120();
}
