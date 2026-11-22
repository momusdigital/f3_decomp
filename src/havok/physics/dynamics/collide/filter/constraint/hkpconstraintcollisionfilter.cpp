#include "f3_common.h"
// src/havok/physics/dynamics/collide/filter/constraint/hkpconstraintcollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/filter/constraint/hkpconstraintcollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Owner
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
    void FUN_00d87c20(int value, bool mode);
};
// Calls v2(value) on the VtableObject at this+0x40 when mode is true, otherwise calls v1(value).
// @f3 0x005512f0 (community match, verified in this file)
// pdb: TESFaction::SetFlag | TESFaction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiFlag, abVal
void Owner::FUN_00d87c20(int value, bool mode)
{
    if (mode)
        unk34 |= value;
    else
        unk34 &= ~value;
    (*(void (__thiscall**)(Owner*, int))(unk00 + 0x48))(this, 2);
}


struct Secondary
{
    virtual void Operation();
    Secondary()
    {}
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
struct hkpCdBody
{
    void* m_pCollisionShape;
};
struct hkpCollidable : hkpCdBody
{
};
struct hkpEntity;
struct hkpWorld
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk98;
    hkBool m_bBlockExecutingPendingOperations;
    int unkA0;
    int m_iPendingOperationQueueCount;
    void FUN_00c91120();
    void FUN_00c91140();
    void hkpMultiThreadedSimulation_MtEntityEntityBroadPhaseListener_addCollisionPair(hkpEntity* a, hkpEntity* b);
    __forceinline void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        m_iCriticalOperationsLockCount--;
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations.m_cBooleanValue)
        {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                FUN_00c91140();
        }
    }
};
struct hkpEntity
{
    int unk00;
    int unk04;
    hkpWorld* m_pOwningWorld;
    int unk0C;
    hkpCollidable m_kCollidable;
};

struct D;
struct B;
struct C;

struct B
{
    int unk00;
    int unk04;
    D* m_iFourthElementInteger;
    int unk0C;
    int m_iB10;
};

struct C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iC10;
};

struct D
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
    int m_i8c;
    int m_i90;
    int m_i94;
    int unk98;
    unsigned char m_b9c;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    int unkA0;
    int m_ia4;
    void CleanupFirst();
    void CleanupSecond();
};

struct S_00d87f60_Arg
{
    struct S_00d87f60_Obj* unk00;
    int unk04;
};
struct S_00d87f60_Flag
{
    char unk00;
    S_00d87f60_Flag(char c)
    {
        unk00 = c;
    }
    S_00d87f60_Flag(const S_00d87f60_Flag& o)
    {
        unk00 = o.unk00;
    }
};
struct S_00d87f60_Data
{
    char unk00;
    void* unk04;
    int unk08;
    char unk0c;
};
struct S_00d87f60_Obj
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
    void FUN_00c91160(S_00d87f60_Data*);
};

typedef void(__thiscall* SlotFn)(void* self, void* arg);
struct Sub_b1297
{
    int GetCount();
    void* GetItem(int index);
};
struct Elem_b1297;
struct Elem_b1297
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
    Sub_b1297** m_48;
    int m_4c;
};

// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void FUN_00d87fc0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d87fc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d87fc0
    virtual void FUN_00d87fc0();
};

Derived::Derived()
{}

namespace fnv_00d87ff0 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for the second base of a multiple-inheritance class.
struct PrimaryBase
{
    virtual void FUN_00d87ff0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d87ff0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d87ff0
    virtual void FUN_00d87ff0();
};

Derived::Derived()
{}
}  // namespace fnv_00d87ff0

namespace fnv_00d88030 {
struct Base1
{
    virtual void FUN_00d88030();
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
};
struct Base2
{
    virtual void FUN_00d88030();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00d88030
    virtual void FUN_00d88030();
};
Derived::Derived()
{}
}  // namespace fnv_00d88030

struct Obj_d87f00;
struct Owner_d87f00;

struct Event_d87f00
{
    unsigned char m_kind;
    unsigned char unk01;
    unsigned short unk02;
    void* m_ptr;
    unsigned int m_val;
    unsigned char m_flag;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
};

struct Flag_d87f00
{
    Flag_d87f00(unsigned char v) : m_on(v)
    {}
    Flag_d87f00(const Flag_d87f00& o) : m_on(o.m_on)
    {}
    unsigned char m_on;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
};

struct Obj_d87f00
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int m_94;

    void FUN_00c91160(Event_d87f00* apEvent);
};

struct Owner_d87f00
{
    void FUN_00d87c20(unsigned int aValue, Flag_d87f00 aFlag);
};
