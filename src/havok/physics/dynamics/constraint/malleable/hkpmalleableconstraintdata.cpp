#include "f3_common.h"
// src/havok/physics/dynamics/constraint/malleable/hkpmalleableconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/malleable/hkpmalleableconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMalleableConstraintData.h"

struct hkMalleableContactNormal : hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct hkMalleableConstraintData
{
    int m_auiShapeKeys[56];
    hkMalleableContactNormal* m_contactNormals[16];
    void SetContactNormal(int index);
};

// @f3 0x008fbfc0 (community match, verified in this file)
struct MalleableRuntime
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkMalleableContactNormal* m_normal;
};

struct MalleableReal
{
    int unk00;
    int unk04;
    MalleableRuntime* m_runtime;
};

// pdb: bhkConstraint::SetEntityA | bhkConstraint.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apEntity
void hkMalleableConstraintData::SetContactNormal(int index)
{
    if (this == 0)
        return;

    MalleableRuntime* runtime = ((MalleableReal*)this)->m_runtime;
    if (runtime == 0)
        return;

    hkMalleableContactNormal* normal = (hkMalleableContactNormal*)index;
    if (normal)
        normal->RetainReference();

    hkMalleableContactNormal* old = runtime->m_normal;
    if (old)
        old->removeReference();

    runtime->m_normal = normal;
}


// @fnv 0x00cdf6b0
// pdb: PatrolActorPackageData::GetPackageType | PatrolPackage.obj | fnv360_0822_retail, vtable, high
int FUN_00cdf6b0()
{
    return 13;
}

struct FUN_00cdf620_Arg
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_data;
    int m_iElementCount;
};

class FUN_00cdf620_Target
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15(FUN_00cdf620_Arg* pkArg);
};

struct FUN_00cdf620_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00cdf620_Target* m_target;
    char m_10;

    void DispatchArg(FUN_00cdf620_Arg* pkArg);
};

// @f3 0x0095b060 (community match, verified in this file)
namespace task1470 {
class FUN_00cdf620_Target {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V15(FUN_00cdf620_Arg* argument);
};
}
// pdb: hkpMalleableConstraintData::getConstraintInfo | hkpMalleableConstraintData.obj | fnv360_0822_debug, objrun_open, low
// pdb params: info
void FUN_00cdf620_cls::DispatchArg(FUN_00cdf620_Arg* argument) {
    ((task1470::FUN_00cdf620_Target*)m_target)->V15(argument);
    argument->m_data = &m_10;
    argument->m_iElementCount = 12;
}


// Forwards the pair to m_inner's virtual forward and returns its result.
// @f3 0x00652db0 (community match, verified in this file)
extern int DAT_01076860;
extern int DAT_01075b24;
namespace f3m_00652db0 {

struct InventoryActionHandler
{
    int FUN_00697500(int selected, int item);
};

// pdb: InventoryMenu::SetKnobPosition | InventoryMenu.obj | fnv360_0822_debug, objrun, medium
// pdb params: abPlaySounds
int __cdecl FUN_00652db0(int item)
{
    if (DAT_01076860 != 0)
    {
        return (*(InventoryActionHandler**)(DAT_01075b24 + 0x174))->FUN_00697500(*(int*)(DAT_01076860 + 0x60), item);
    }
}
}   // namespace f3m_00652db0


class MalleableGetterStandIn : public hkpMalleableConstraintData
{
  public:
    hkpConstraintData* FUN_00cdf6c0();
};

// @fnv 0x00cdf6c0
// pdb: hkpMalleableConstraintData::getWrappedConstraintData | hkpMalleableConstraintData.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpRagdollConstraintData::getType)
hkpConstraintData* MalleableGetterStandIn::FUN_00cdf6c0()
{
    return m_pConstraintData;
}

struct FUN_00cdf6d0_t
{
    int m_auiShapeKeys[3];
    int m_field_c;
    int hkClass_getNumDeclaredInterfaces();
};

// @fnv 0x00cdf6d0
// pdb: hkClass::getNumDeclaredInterfaces | hkClass.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap|call_seq) + skyrim(call_gap), high
int FUN_00cdf6d0_t::hkClass_getNumDeclaredInterfaces()
{
    return m_field_c;
}

struct Cdf7c0Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpConstraintAtom* unk10;
    int unk14;
};

struct __declspec(align(16)) Cdf7c0Buf
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
    float unk24;
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
};

struct Cdf7c0VTable
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
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v36();
    virtual void v38(Cdf7c0Info* info);
};

struct Cdf7c0Flag
{
    bool v;
};

void FUN_00d72190(hkpConstraintAtom* atom, Cdf7c0Buf* buf, Cdf7c0Flag flag, int param2);
void FUN_00d6f460(hkpConstraintAtom* atom, int unk14, Cdf7c0Buf* buf, int param2);

struct Cdf7c0Self
{
    int unk00;
    int unk04;
    int unk08;
    Cdf7c0VTable* m_pConstraintData;
    int unk10;
    int unk14;
    int unk18;
    float m_fSpringStrength;
    void FUN_00cdf7c0(const Cdf7c0Buf& src, int param2);
};

// Copies src, scales the copy's unk24 by m_fSpringStrength, then calls FUN_00d72190 for a contact atom or FUN_00d6f460 otherwise.
// @f3 0x0095b220 (community match, verified in this file)
struct __declspec(align(16)) Cdf7c0Buf96
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20;
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
};
struct Cdf7c0VTableX
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
    virtual void v24();
    virtual void v28();
    virtual void v2c(Cdf7c0Info* info);
};

void Cdf7c0Self::FUN_00cdf7c0(const Cdf7c0Buf& src, int param2)
{
    Cdf7c0Buf96 buf = *(const Cdf7c0Buf96*)&src;
    buf.unk20 = m_fSpringStrength * buf.unk20;
    Cdf7c0Info info;
    ((Cdf7c0VTableX*)m_pConstraintData)->v2c(&info);
    if (info.unk10->m_type == hkpConstraintAtom::TYPE_CONTACT)
    {
        Cdf7c0Flag flag;
        flag.v = true;
        FUN_00d72190(info.unk10, (Cdf7c0Buf*)&buf, flag, param2);
    }
    else
    {
        FUN_00d6f460(info.unk10, info.unk14, (Cdf7c0Buf*)&buf, param2);
    }
}
