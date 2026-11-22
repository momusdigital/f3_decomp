// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmagnitudectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmagnitudectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPSysModifierFloatCtlr
{
};

struct NiPSysFieldMagnitudeCtlr : NiPSysModifierFloatCtlr
{
    void __thiscall FUN_00c29ea0(float& fValue);
};

// @fnv 0x00c29ea0
void __thiscall NiPSysFieldMagnitudeCtlr::FUN_00c29ea0(float& fValue)
{
    fValue = *(float*)(*(NiPSysModifierFloatCtlr**)((char*)this + 0x3C) + 0x1C);
}

struct NiPSysFieldMagnitudeCtlr_shell : NiPSysFieldMagnitudeCtlr
{
    void __thiscall FUN_00c2b150(float value);
};

// @fnv 0x00c2b150
void __thiscall NiPSysFieldMagnitudeCtlr_shell::FUN_00c2b150(float value)
{
    ((float*)*(int*)((char*)this + 0x3c))[7] = value;
}

struct Base
{
    int unk04;
    Base() throw();
    virtual void vf();
};

struct Node : Base
{
    int unk08[14];
    static void* operator new(unsigned int size) throw();
    Node() throw()
    {}
    virtual void vf();
};

struct Owner
{
    void FUN_00c32de0(Node* node, int arg);
    Node* FUN_00c2b160(int arg);
};

// @fnv 0x00c2b160
// pdb: NiPSysFieldMagnitudeCtlr::CreateClone | NiPSysFieldMagnitudeCtlr.obj | tesv_win, caller_sim, low
Node* Owner::FUN_00c2b160(int arg)
{
    Node* node = new Node();
    FUN_00c32de0(node, arg);
    return node;
}
