#include "f3_common.h"
// src/fallout/ai/combat/explosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/explosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct ActorCause
{
};
struct NiPointer
{
    NiPointer& operator=(ActorCause*);
};

struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM g_memoryManager;
void __cdecl FUN_00cbc740();

struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};

// @fnv 0x00cbd4e0
// pdb: ExtraLastFinishedSequence::`scalar deleting destructor' | ExtraDataObjects.obj | fnv360_0822_debug, vtable, high
void* FUN_00cbd4e0_shell::FUN_00cbd4e0(unsigned char flag)
{
    FUN_00cbc740();
    if (flag & 1)
        g_memoryManager.DeallocateAlias(this);
    return this;
}

extern __declspec(thread) int g_memoryContext;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct AutoMemContext
{
    int oldContext;
    AutoMemContext()
    {
        oldContext = g_memoryContext;
        g_memoryContext = 16;
    }
    ~AutoMemContext()
    {
        g_memoryContext = oldContext;
    }
};
struct FUN_00cbc550_class
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
    static void* __cdecl operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    FUN_00cbc550_class();
};

struct HavokAllocator
{
    virtual void vf00();
    virtual void* allocate(int size);
    virtual void deallocate(void* p, int size);
};

struct HavokAllocatorContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HavokAllocator* m_alloc;
};

extern "C" HavokAllocatorContext* __cdecl FUN_00c85750();

struct HavokObj
{
    int unk00;
    short m_flags;
    short m_ref;
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

    static void* operator new(size_t size)
    {
        HavokAllocatorContext* tm = FUN_00c85750();
        HavokObj* p = (HavokObj*)tm->m_alloc->allocate(size);
        p->m_flags = (short)size;
        return p;
    }
    static void operator delete(void* p);

    HavokObj(void* a1, int a2);
    void removeReference();
};

class NiViewerStringArray
{
  public:
    virtual ~NiViewerStringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

inline void* operator new(size_t, void* p)
{
    return p;
}
struct SmallAlignedState
{
    unsigned int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    SmallAlignedState() : unk00(0), unk04(0), unk08(5000.0f), unk0c(15.0f), unk10(64.0f), unk14(15.0f)
    {}
};
struct StateOwner
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    SmallAlignedState* unk0c;
    unsigned int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    void __thiscall FUN_00c867d0(SmallAlignedState* state);
    SmallAlignedState* FUN_00cbcad0(bool* created);
};
// @f3 0x0092f810 (community match, verified in this file)
struct MemoryManagerGlobal
{
    void* __thiscall Allocate(unsigned int size);
};
extern MemoryManagerGlobal DAT_01090a78;

// pdb: bhkLiquidAction::CreateCinfo | bhkLiquidAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCreated
SmallAlignedState* StateOwner::FUN_00cbcad0(bool* created)
{
    if (unk0c == 0)
    {
        void* raw = DAT_01090a78.Allocate(0x28);
        unsigned char offset = 16 - ((unsigned int)raw & 15);
        raw = (char*)raw + offset;
        *((char*)raw - 1) = offset;

        SmallAlignedState* state = new (raw) SmallAlignedState;
        unk0c = state;

        if (unk08)
        {
            FUN_00c867d0(state);
            state->unk08 = unk1c;
            state->unk0c = unk20;
            state->unk10 = unk14;
            state->unk14 = unk18;
        }

        *created = true;
        return unk0c;
    }
    else
    {
        *created = false;
        return unk0c;
    }
}


struct ThreadBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int context;
};
extern __declspec(thread) ThreadBlock threadBlock;
struct ContextScope
{
    unsigned int saved;
    ContextScope(unsigned int old)
    {
        saved = old;
        threadBlock.context = 16;
    }
    ~ContextScope()
    {
        threadBlock.context = saved;
    }
};
