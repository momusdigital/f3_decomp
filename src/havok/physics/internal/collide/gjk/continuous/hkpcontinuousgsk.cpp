// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>

namespace fnv_00db52c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};

}  // namespace fnv_00db52c0

struct Table
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
    unsigned int(__thiscall* f2c)(struct Ctrl*);
    void(__thiscall* f30)(struct Ctrl*, unsigned int);
};
struct Ctrl
{
    Table* tab;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float f10;
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
    float fa0;
};
struct Stat
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
    float fa0;
};
struct ObjA
{
    Ctrl* ctrl;
    unsigned int unk04;
    void* p8;
};
struct ObjB
{
    Ctrl* ctrl;
    unsigned int unk04;
    Stat* p8;
};
struct In
{
    ObjA* a;
    ObjB* b;
    unsigned int unk08;
    unsigned char* p0c;
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
    __m128 v70;
};
struct Out
{
    void* f0;
    void* f4;
    unsigned int f8;
    unsigned int f0c;
    unsigned int f10;
    float f14;
    float f18;
    float f1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned char* f40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    __m128 f50;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float f6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    float f7c;
};
// Fills out from in: stores both p8 pointers and the f10 sum, reserves v*16 bytes (rounded to 128) from FUN_00c85750's cursor, and computes f18 and f1c.
// @f3 0x00a42140 (community match, verified in this file)
namespace ns_00a42140 {

struct Float4 {
    float x, y, z, w;
};

struct CtrlVtbl {
    void* unk00; void* unk04; void* unk08; void* unk0c; void* unk10;
    void* unk14; void* unk18; void* unk1c; void* unk20;
    int(__thiscall* GetCount)(Ctrl*);
    void(__thiscall* SetBuffer)(Ctrl*, void*);
};

struct ScratchArena;
struct ScratchArenaVtbl {
    void* unk00; void* unk04; void* unk08; void* unk0c; void* unk10;
    char* (__thiscall* AllocSlow)(ScratchArena*, int);
};

struct ScratchArena {
    ScratchArenaVtbl* vtbl;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* cur;
    unsigned int unk24, unk28;
    char* end;
    char* Alloc(int size) {
        char* p = cur;
        char* next = p + size;
        if (next <= end) { cur = next; return p; }
        return vtbl->AllocSlow(this, size);
    }
};

struct MyIn {
    ObjA* a; ObjB* b; unsigned int unk08; unsigned char* p0c;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c;
    Float4 vector60;
    __m128 v70;
};

struct MyOut {
    void* f0; void* f4; unsigned int f8; unsigned int f0c; unsigned int f10;
    float f14; float f18; float f1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned char* f40;
    unsigned int unk44, unk48, unk4c;
    Float4 f50;
    unsigned int unk60, unk64, unk68; float f6c;
    unsigned int unk70, unk74, unk78; float f7c;
};

} // namespace ns_00a42140

extern int DAT_010f3170;
extern "C" void* (__stdcall* const DAT_00fdf044)(unsigned long);

// pdb: hk4dGskCollPInputInitialize | hkpContinuousGsk.obj | tesv_win, objrun, medium
static __declspec(noinline) void FUN_00db53f0(In* in, Out* out)
{
    ns_00a42140::MyIn* mi = (ns_00a42140::MyIn*)in;
    ns_00a42140::MyOut* mo = (ns_00a42140::MyOut*)out;
    ObjA* a = mi->a;
    ObjB* b = mi->b;
    Ctrl* ctrlA = a->ctrl;
    Ctrl* ctrlB = b->ctrl;
    Stat* statA = (Stat*)a->p8;
    Stat* statB = b->p8;
    mo->f0 = statA;
    mo->f4 = statB;
    mo->f14 = ctrlB->f10 + ctrlA->f10;
    mo->f50.x = mi->vector60.x;
    mo->f50.y = mi->vector60.y;
    mo->f50.z = mi->vector60.z;
    double w = mi->vector60.w;
    mo->f40 = (unsigned char*)mi->unk08 + 0x50;
    mo->f50.w = (float)w;
    int count = ((ns_00a42140::CtrlVtbl*)ctrlA->tab)->GetCount(ctrlA);
    mo->f10 = count;
    mo->f0c = count;
    ns_00a42140::ScratchArena* arena = (ns_00a42140::ScratchArena*)DAT_00fdf044(DAT_010f3170);
    char* p = arena->Alloc((count * 16 + 16) & ~15);
    mo->f8 = (unsigned int)p;
    ((ns_00a42140::CtrlVtbl*)ctrlA->tab)->SetBuffer(ctrlA, p);
    float t1 = statB->fa0 * mo->f7c * mo->f7c;
    float t2 = statA->fa0 * mo->f6c * mo->f6c;
    float t = t1 + t2;
    mo->f18 = t;
    mo->f1c = (float)(1.0 / (t + 1.1920928955078125e-07));
}

namespace ns_00a42140 {
extern In* volatile gIn_00a42140;
extern Out* volatile gOut_00a42140;
void caller_00a42140() { FUN_00db53f0(gIn_00a42140, gOut_00a42140); }
}


extern In* volatile inputIn;
extern Out* volatile inputOut;
void emit_function()
{
    FUN_00db53f0(inputIn, inputOut);
}
