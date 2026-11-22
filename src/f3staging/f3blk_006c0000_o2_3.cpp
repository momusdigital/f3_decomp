// src/f3staging/f3blk_006c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d32f0 (community match, verified in this file)
namespace f3m_006d32f0 {

class FUN_007bc0b0;

struct ExtraList006d32f0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void* FUN_0040d2d0();
};

class Allocator006d32f0 {
public:
    void* FUN_0086b930(unsigned int auiSize);
};
extern Allocator006d32f0 g_allocator006d32f0;

class Manager006d32f0 {
public:
    bool TESDataHandler_IsFormIDCreated(unsigned int auiID);
};
extern Manager006d32f0* g_manager006d32f0;

class RefManager006d32f0 {
public:
    void BGSSaveLoadGame_ClearForm(FUN_007bc0b0* apRef);
};
extern RefManager006d32f0* g_refManager006d32f0;

extern int DAT_f46078;
extern int DAT_f460fc;

class FUN_007bc0b0 {
public:
    static void* operator new(unsigned int auiSize);
    FUN_007bc0b0();
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual bool vfF0();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    // pdb: TESForm::IsActor (slot 64; F3 TESForm vtable 78 slots = FNV360_PDB TESForm 78, Actor's slot 64 returns true)
    virtual bool IsActor();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf128(unsigned int auiID, int ai1);
    int BGSProjectile_GetProjectileRefFormType();
    void TESObjectREFR_SetObjectReference(FUN_007bc0b0* apForm);
    void TESObjectREFR_SetRefPersists(int ai1);
    unsigned char unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_007bc0b0* unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    ExtraList006d32f0 unk40;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
};

inline void* FUN_007bc0b0::operator new(unsigned int auiSize)
{
    return g_allocator006d32f0.FUN_0086b930(auiSize);
}

struct CreatedRef006d32f0 {
    unsigned int unk00;
    unsigned int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_007bc0b0* unk1C;
    int unk20;
    int unk24;
    int unk28;
    unsigned char unk2C;
};

FUN_007bc0b0* TESForm_GetFormByNumericID(unsigned int auiID);
FUN_007bc0b0* FUN_00c0050a(void* ap0, int ai1, void* ap2, void* ap3, int ai4);
FUN_007bc0b0* TESObjectREFR_CreateReference(int aeType, int ai1);
void FUN_006cd570(const char* apFormat, ...);

// pdb: BGSSaveLoadInitialData::CreateReference | BGSSaveLoadInitialData.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(call_gap), high
FUN_007bc0b0* BGSSaveLoadInitialData_CreateReference(unsigned int auiRefID, CreatedRef006d32f0* apCreated, FUN_007bc0b0* apRef)
{
    if (!apRef)
        apRef = TESForm_GetFormByNumericID(auiRefID);
    if (g_manager006d32f0->TESDataHandler_IsFormIDCreated(apCreated->unk04))
        apCreated->unk04 = 0;
    FUN_007bc0b0* form = FUN_00c0050a(TESForm_GetFormByNumericID(apCreated->unk04), 0, &DAT_f46078, &DAT_f460fc, 0);
    if (!form) {
        FUN_006cd570("SAVELOAD: Bound object %08X no longer exists.  Reference %08X will not be created.",
                     apCreated->unk04, auiRefID);
        return 0;
    }
    if (apRef) {
        if (!(apRef->vfF0() && (apRef->unk1C == form ||
                               (apRef->IsActor() && apRef->unk40.FUN_0040d2d0() == form)))) {
            g_refManager006d32f0->BGSSaveLoadGame_ClearForm(apRef);
            apRef = 0;
        }
    }
    unsigned char flags = apCreated->unk2C;
    if (!apRef) {
        int refType = 0x3a;
        FUN_007bc0b0* newRef = 0;
        switch (form->unk04) {
        case 0x2b: refType = 0x3c; break;
        case 0x2a: refType = 0x3b; break;
        case 0x33: refType = form->BGSProjectile_GetProjectileRefFormType(); break;
        case 0x51: newRef = new FUN_007bc0b0; break;
        }
        if (flags & 4)
            refType = 0x16;
        if (flags & 3) {
            if (!newRef)
                newRef = TESObjectREFR_CreateReference(refType, 1);
            newRef->TESObjectREFR_SetObjectReference(form);
            newRef->vf128(auiRefID, 1);
            apRef = newRef;
        } else {
            FUN_006cd570("SAVELOAD: Invalid created reference type %i for form %08X with bound object %08X in location %08X",
                         flags, auiRefID, apCreated->unk04, apCreated->unk00);
            goto done;
        }
    }
    if (flags & 2)
        apRef->TESObjectREFR_SetRefPersists(1);
    if (apRef)
        apRef->unk08 |= 0x200000;
done:
    return apRef;
}
}   // namespace f3m_006d32f0

// @f3 0x006cef40 (community match, verified in this file)
namespace f3m_006cef40 {
namespace N6CEF40 {
struct TypeInfo6ce { const char* name; int unk04; int unk08; };
extern TypeInfo6ce DAT_00f4a74c[];
struct Data6ce { unsigned int TESDataHandler_GetNextID(int flag); };
extern Data6ce* DAT_0106cdcc;
void FUN_006cd570(const char* format, ...);
struct Form6ce {
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010(int flag);
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void SetRefID(unsigned int id);
    unsigned char typeID; char unk05, unk06, unk07; int unk08; unsigned int refID;
};
inline const char* TypeName6ce(unsigned char type) { return type < 0x67 ? DAT_00f4a74c[type].name : ""; }
// pdb: BGSSaveLoadGame::ClearForm | BGSSaveLoadGame.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(callee_sim), high
void __stdcall BGSSaveLoadGame_ClearForm(Form6ce* form) {
    if (!form) return;
    int type = form->typeID;
    switch (type) {
    case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 73:
        form->vfn010(1);
        break;
    case 4: case 17: case 18: case 42: case 43: case 57: case 66: case 67:
        form->SetRefID(DAT_0106cdcc->TESDataHandler_GetNextID(1));
        break;
    default:
        FUN_006cd570("FORMS: Form %08X with form type %i %s was re-numbered by BGSSaveLoadGame::ClearForm()", form->refID,
                     type, TypeName6ce(type));
        form->SetRefID(DAT_0106cdcc->TESDataHandler_GetNextID(1));
        break;
    }
}
}
}   // namespace f3m_006cef40
