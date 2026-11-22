#include "f3_common.h"
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstraintChainInstanceAction.h"

struct FnvCpu_FUN_00e063e0_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00e063e0_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FnvCpu_FUN_00e063e0_CpuInterface* target;
    void hkpConstraintChainInstanceAction_entityRemovedCallback(int arg0);
};
// @fnv 0x00e063e0
// pdb: hkpConstraintChainInstanceAction::entityRemovedCallback | hkpConstraintChainInstanceAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FnvCpu_FUN_00e063e0_CpuOwner::hkpConstraintChainInstanceAction_entityRemovedCallback(int arg0)
{
    target->Invoke(arg0);
}

// @fnv 0x00e063c0
// pdb: hkpConstraintChainInstanceAction::applyAction | hkpConstraintChainInstanceAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpConstraintChainInstanceAction_applyAction(int)
{}

struct FnvEntityArray
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkpConstraintChainInstance
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    FnvEntityArray entities;
};
// @f3 0x00a4e2c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct FnvAllocStd_f4
{
    void* FUN_008f6d30(unsigned int size, unsigned int flags);
    void FUN_008f6d90(void* p, unsigned int size, unsigned int flags);
};
struct FnvArrayStd_f4
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void FUN_0098a280(FnvArrayStd_f4* src);
};
void __fastcall CopyEntityArray(hkpConstraintChainInstanceAction* self, void* unusedEdx, FnvEntityArray* output)
{
    FnvArrayStd_f4* dst = reinterpret_cast<FnvArrayStd_f4*>(self);
    FnvArrayStd_f4* src = reinterpret_cast<FnvArrayStd_f4*>(output);
    dst->FUN_0098a280(src);
    int capacity = dst->m_iCapacityState & 0x3fffffff;
    if (capacity < src->m_iElementCount)
    {
        void* (__stdcall* getTls)(unsigned long) = DAT_00d9b080;
        if (!(dst->m_iCapacityState & 0x80000000))
        {FnvAllocStd_f4* heap=reinterpret_cast<FnvAllocStd_f4*>(getTls(DAT_010f3170));heap->FUN_008f6d90(dst->m_data, capacity * 4, 0x17);}
        FnvAllocStd_f4* heap=reinterpret_cast<FnvAllocStd_f4*>(getTls(DAT_010f3170));dst->m_data = (void**)heap->FUN_008f6d30(src->m_iElementCount * 4, 0x17);
        dst->m_iCapacityState = (dst->m_iCapacityState & 0x40000000) | src->m_iElementCount;
    }
    int count = src->m_iElementCount;
    dst->m_iElementCount = count;
    void** to = dst->m_data;
    void** from = src->m_data;
    for(int i=0;i<count;++i) to[i]=from[i];
}

