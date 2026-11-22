#include "f3_common.h"
// src/havok/physics/dynamics/constraint/util/hkpconstraintdatacloningutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/util/hkpconstraintdatacloningutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator858
{
    virtual void v00();
    virtual void* Allocate(unsigned int uiSize);
};
struct Heap858
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator858* m_pHeapAllocator;

    void* Allocate(unsigned int uiSize)
    {
        return m_pHeapAllocator->Allocate(uiSize);
    }
};
extern "C" Heap858* __cdecl FUN_00c85750();

struct Clonable858
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Clonable858* Clone();
};

struct Object858
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int GetType();
    unsigned short usSize;
    unsigned short usFlags;
    int iValue;
    int unk0c;
};

struct Payload858
{
    void FUN_00d85ba0(const Payload858* pkSrc);
    void AssignFrom(const Payload858* pkSrc);
    void CopyStateFrom(const Payload858* pkSrc);
};

struct Type7Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xe0 - 0x11];
    Clonable858* apkChildren[3];
};
struct Type6Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xac - 0x11];
    Clonable858* pkChild;
};
struct Type2Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xb0 - 0x11];
    Clonable858* pkChild;
};

struct Raw858
{
    Type7Object858* FUN_00cdf2f0();
    Type6Object858* FUN_00d4fe80();
    Type2Object858* FUN_00cb9090();
};

inline Raw858* Allocate858(unsigned int uiSize)
{
    Object858* pkObject = (Object858*)FUN_00c85750()->Allocate(uiSize);
    pkObject->usSize = (unsigned short)uiSize;
    return (Raw858*)pkObject;
}

// Allocates a new object matching pkSource's type (7, 6 or 2), copies its payload and iValue, clones child pointers, and returns it or 0.
// @f3 0x00a09500 (community match, verified in this file)
struct ObjectView858
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual int GetType();
};
struct PayloadF3
{
    void FUN_00a093d0(const Payload858* pkSrc);
    void FUN_00a09310(const Payload858* pkSrc);
    void FUN_00a09230(const Payload858* pkSrc);
};
struct RawF3
{
    Type7Object858* FUN_0095a6f0();
    Type6Object858* FUN_009dd270();
    Type2Object858* FUN_0092b710();
};
struct MemF3
{
    RawF3* FUN_008f6d30(unsigned int uiSize, unsigned int uiClass);
};
extern unsigned int DAT_010f3170;
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);

static RawF3* AllocF3(unsigned int uiSize)
{
    MemF3* pkMem = (MemF3*)TlsGetValue(DAT_010f3170);
    RawF3* pkObject = pkMem->FUN_008f6d30(uiSize, 0x2c);
    ((Object858*)pkObject)->usSize = (unsigned short)uiSize;
    return pkObject;
}

// pdb: hkpRagdollConstraintData::setMotorsActive | hkpRagdollConstraintData.obj | fnv360_0822_debug, call_gap, low, conflict (skyrim: hkpConstraintDataCloningUtil::cloneIfCanHaveMotors)
// pdb params: instance, toBeEnabled
Object858* __cdecl FUN_00d858f0(Object858* pkSource)
{
    switch (((ObjectView858*)pkSource)->GetType())
    {
    case 7: {
        Type7Object858* pkResult = AllocF3(0x140)->FUN_0095a6f0();
        ((PayloadF3*)&pkResult->kPayload)->FUN_00a093d0(&((Type7Object858*)pkSource)->kPayload);
        pkResult->iValue = pkSource->iValue;
        Clonable858** ppkChildren = pkResult->apkChildren;
        for (int i = 0; i < 3; i++)
        {
            if (ppkChildren[i])
                ppkChildren[i] = ppkChildren[i]->Clone();
        }
        return pkResult;
    }
    case 6: {
        Type6Object858* pkResult = AllocF3(0xd0)->FUN_009dd270();
        ((PayloadF3*)&pkResult->kPayload)->FUN_00a09310(&((Type6Object858*)pkSource)->kPayload);
        pkResult->iValue = pkSource->iValue;
        Clonable858*& rpkChild = pkResult->pkChild;
        if (rpkChild)
            rpkChild = rpkChild->Clone();
        return pkResult;
    }
    case 2: {
        Type2Object858* pkResult = AllocF3(0xe0)->FUN_0092b710();
        ((PayloadF3*)&pkResult->kPayload)->FUN_00a09230(&((Type2Object858*)pkSource)->kPayload);
        pkResult->iValue = pkSource->iValue;
        Clonable858*& rpkChild = pkResult->pkChild;
        if (rpkChild)
            rpkChild = rpkChild->Clone();
        return pkResult;
    }
    }
    return 0;
}


struct Heap858b
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator858* m_pHeapAllocator;
    Allocator858& heap()
    {
        return *m_pHeapAllocator;
    }
};
struct Breakable858 : Object858
{
    int unk10;
    int unk14;
    Object858* m_pConstraintData;
    int unk1c;
    float m_fBreakingStrength;
    unsigned char m_bRemoveWhenBroken;
    unsigned char m_bRevertBackVelocityOnBreak;
    Object858* GetBreakableObject() const
    {
        return m_pConstraintData;
    }
    float getThreshold() const
    {
        return m_fBreakingStrength;
    }
    void setThreshold(float t)
    {
        m_fBreakingStrength = t;
    }
    unsigned char getRemoveWhenBroken() const
    {
        return m_bRemoveWhenBroken;
    }
    void setRemoveWhenBroken(unsigned char b)
    {
        m_bRemoveWhenBroken = b;
    }
    unsigned char getRevertBackVelocityOnBreak() const
    {
        return m_bRevertBackVelocityOnBreak;
    }
    void setRevertBackVelocityOnBreak(unsigned char b)
    {
        m_bRevertBackVelocityOnBreak = b;
    }
};
