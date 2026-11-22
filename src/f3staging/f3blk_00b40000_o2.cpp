// src/f3staging/f3blk_00b40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b57630 (community match, verified in this file)
struct Owner381;
struct Object381 {
    virtual void Slot00() = 0;
    virtual void Slot04() = 0;
    virtual void Slot08() = 0;
    virtual void Slot0C() = 0;
    virtual void Slot10() = 0;
    virtual void Slot14() = 0;
    virtual void Slot18() = 0;
    virtual void Slot1C() = 0;
    virtual void Slot20() = 0;
    virtual void Slot24() = 0;
    virtual void Slot28() = 0;
    virtual void Slot2C() = 0;
    virtual void Slot30() = 0;
    virtual void Slot34() = 0;
    virtual void Slot38() = 0;
    virtual void Slot3C() = 0;
    virtual void Slot40() = 0;
    virtual void Slot44() = 0;
    virtual void Slot48() = 0;
    virtual void Slot4C() = 0;
    virtual void Slot50() = 0;
    virtual void Slot54() = 0;
    virtual void Slot58() = 0;
    virtual void Slot5C() = 0;
    virtual void Slot60() = 0;
    virtual void Slot64() = 0;
    virtual void Slot68() = 0;
    virtual void Slot6C() = 0;
    virtual void Slot70() = 0;
    virtual void Slot74() = 0;
    virtual void Slot78() = 0;
    virtual void Slot7C() = 0;
    virtual void Slot80() = 0;
    virtual void Slot84() = 0;
    virtual void Slot88() = 0;
    virtual void Slot8C() = 0;
    virtual void Slot90() = 0;
    virtual void Slot94() = 0;
    virtual void Slot98() = 0;
    virtual void Process(Owner381* owner) = 0;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int kind;
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
    unsigned int state;
};
struct Owner381 { Object381* FUN_00826590(unsigned int kind); };
// pdb: BSShader::SetupGeometry | BSShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apGeometry
bool __stdcall FUN_00b57630(Owner381* owner) {
    Object381* object = owner->FUN_00826590(3);
    int matches = 0;
    if (object) matches = object->kind == 9;
    Object381* typed = matches ? object : 0;
    typed->state = 4;
    typed->Process(owner);
    return true;
}

// @f3 0x00b54b30 (community match, verified in this file)
extern void* DAT_0116f2f8;
namespace f3m_00b54b30 {
struct FUN_00b54940;

void* FUN_0087e9a0(void* renderer, int a, int b);
void* FUN_0089eb90(unsigned int size);

struct FUN_00b54940 {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b54940(void* a, void* b);
    unsigned char unk00[0xec];
};

// pdb: HairShader::CreateShader | HairShader.obj | fnv360_0822_retail, call_gap, medium
FUN_00b54940* FUN_00b54b30()
{
    void* a = FUN_0087e9a0(DAT_0116f2f8, 6, 1);
    void* b = FUN_0087e9a0(DAT_0116f2f8, 8, 1);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)a)[35])(a, 0, 0, 0, 2, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)a)[35])(a, 1, 3, 3, 2, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)a)[35])(a, 2, 5, 4, 3, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)a)[35])(a, 3, 7, 5, 1, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)a)[35])(a, 4, 14, 13, 2, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)a)[35])(a, 5, 15, 14, 2, 0);
    ((void (__thiscall*)(void*))(*(void***)a)[45])(a);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 0, 0, 0, 2, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 1, 1, 1, 3, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 2, 2, 2, 4, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 3, 3, 3, 2, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 4, 5, 4, 3, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 5, 7, 5, 1, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 6, 14, 13, 2, 0);
    ((void (__thiscall*)(void*, int, int, int, int, int))(*(void***)b)[35])(b, 7, 15, 14, 2, 0);
    ((void (__thiscall*)(void*))(*(void***)b)[45])(b);
    FUN_00b54940* p = new FUN_00b54940(a, b);
    ((void (__thiscall*)(void*))(*(void***)p)[19])(p);
    ((void (__thiscall*)(void*))(*(void***)p)[81])(p);
    ((void (__thiscall*)(void*))(*(void***)p)[84])(p);
    ((void (__thiscall*)(void*))(*(void***)p)[71])(p);
    ((void (__thiscall*)(void*, void*))(*(void***)p)[48])(p, a);
    return p;
}
}   // namespace f3m_00b54b30

// @f3 0x00b53190 (community match, verified in this file)
extern void* DAT_0116f2f8;
namespace f3m_00b53190 {
void* FUN_0087e9a0(void* renderer, int a, int b);
void* FUN_0089eb90(unsigned int size);

struct FUN_00b52e80
{
    unsigned char unk00[0x128];
    FUN_00b52e80(void* a, void* b);
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};

typedef void (__thiscall* FUN_00b53190_V0)(void*);
typedef void (__thiscall* FUN_00b53190_V1)(void*, void*);
typedef void (__thiscall* FUN_00b53190_V5)(void*, int, int, int, int, int);

// pdb: SkinShader::CreateShader | SkinShader.obj | fnv360_0822_retail, call_gap, medium
void* FUN_00b53190()
{
    void* a = FUN_0087e9a0(DAT_0116f2f8, 6, 1);
    void* b = FUN_0087e9a0(DAT_0116f2f8, 8, 1);

    ((FUN_00b53190_V5)(*(void***)a)[35])(a, 0, 0, 0, 2, 0);
    ((FUN_00b53190_V5)(*(void***)a)[35])(a, 1, 3, 3, 2, 0);
    ((FUN_00b53190_V5)(*(void***)a)[35])(a, 2, 5, 4, 3, 0);
    ((FUN_00b53190_V5)(*(void***)a)[35])(a, 3, 7, 5, 1, 0);
    ((FUN_00b53190_V5)(*(void***)a)[35])(a, 4, 14, 13, 2, 0);
    ((FUN_00b53190_V5)(*(void***)a)[35])(a, 5, 15, 14, 2, 0);
    ((FUN_00b53190_V0)(*(void***)a)[45])(a);

    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 0, 0, 0, 2, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 1, 1, 1, 3, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 2, 2, 2, 4, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 3, 3, 3, 2, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 4, 5, 4, 3, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 5, 7, 5, 1, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 6, 14, 13, 2, 0);
    ((FUN_00b53190_V5)(*(void***)b)[35])(b, 7, 15, 14, 2, 0);
    ((FUN_00b53190_V0)(*(void***)b)[45])(b);

    FUN_00b52e80* n = new FUN_00b52e80(a, b);
    void* nn = n;
    ((FUN_00b53190_V0)(*(void***)nn)[19])(nn);
    ((FUN_00b53190_V0)(*(void***)nn)[81])(nn);
    ((FUN_00b53190_V0)(*(void***)nn)[84])(nn);
    ((FUN_00b53190_V0)(*(void***)nn)[71])(nn);
    ((FUN_00b53190_V1)(*(void***)nn)[48])(nn, a);
    return nn;
}
}   // namespace f3m_00b53190

// @f3 0x00b51b90 (community match, verified in this file)
extern int DAT_0116efd4;
namespace f3m_00b51b90 {
// FUN_00b51b90 stand-in: switch on global, shared tail via goto

struct UnkReq {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct FUN_00b51b90_cls {
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
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    void c_afeb90(int, int, int, int);
    void c_afea40(int, int, int);
    void c_afea80(int, int, int);
    void c_afebd0(int, int, int, int);
    void c_9905c0(int, int, int, int);
    void c_afeac0(int);
    void c_affb80(UnkReq*);
    void FUN_00b51b90(UnkReq* p);
};

// pdb: ParallaxShader::SetupGeometryTextures | ParallaxShader.obj | fnv360_0721_beta, objrun, medium
// pdb params: apState
void FUN_00b51b90_cls::FUN_00b51b90(UnkReq* p)
{
    unsigned int sel = (unsigned int)DAT_0116efd4;
    int m = p->unk0c;
    switch (sel) {
    case 0xda: case 0xe3: case 0xec: case 0xf5: 
        c_afeb90(m, 3, 0, 1);
    case 0xd9: case 0xe2: case 0xeb: case 0xf4: 
        c_afea40(m, 0, 0);
        c_afea80(m, 1, 0);
    L_006a:
        c_afebd0(m, 2, 0, 1);
        vf66();
        return;
    case 0x103: case 0x10f: case 0x11a: case 0x125: 
        c_afeb90(m, 4, 0, 1);
    case 0x101: case 0x10e: case 0x119: case 0x124: 
        c_afea40(m, 0, 0);
        c_afea80(m, 1, 0);
        c_afebd0(m, 3, 0, 1);
        vf66();
        return;
    case 0x9a: case 0xa5: case 0xb0: case 0xbb: 
        c_afeb90(m, 4, 0, 1);
    case 0x99: case 0xa4: case 0xaf: case 0xba: 
        c_afea40(m, 0, 0);
        c_afea80(m, 1, 0);
        c_afebd0(m, 3, 0, 1);
        c_9905c0(m, 2, 0, 1);
        vf66();
        return;
    case 0x134: case 0x140: 
        c_afea40(m, 1, 0);
        c_afea80(m, 0, 0);
        c_afebd0(m, 2, 0, 1);
        vf66();
        return;
    case 0x153: 
        c_afea40(m, 0, 0);
        c_afebd0(m, 2, 0, 1);
        vf66();
        return;
    case 0x15c: case 0x162: case 0x168: case 0x16e: case 0x174: 
        c_afea40(m, 1, 0);
        c_afea80(m, 0, 0);
        c_afebd0(m, 2, 0, 1);
        c_9905c0(m, 6, 0, 1);
        vf66();
        return;
    case 0x231: case 0x232: case 0x233:
        c_afea40(m, 0, 0);
        c_afeac0(6);
        vf66();
        return;
    default:
        c_affb80(p);
        return;
    }
}
}   // namespace f3m_00b51b90

// @f3 0x00b48bd0 (community match, verified in this file)
extern bool DAT_01067b4e;
namespace f3m_00b48bd0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    long refs;
};

struct Sub {
    void FUN_008905a0(int a, int b, int c);
};

Sub* FUN_00890750();

struct A {
    unsigned char unk00;
};

struct ACls {
    int unk00;
    int unk04;
};

struct Held {
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
    Sub* unk30;
};

struct B;
struct C;

struct Tmp {
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
    long refs;
    void FUN_0088f0b0(int a);
    void FUN_0088fe30();
};


struct TmpPtr {
    Tmp* p;
    TmpPtr() : p(0) {}
    ~TmpPtr() {
        if (p) {
            Tmp* q = p;
            q->refs--;
            if (q->refs == 0)
                q->FUN_0088fe30();
        }
    }
};

struct RefPtr {
    RefObj* p;
};

struct Slot {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    C* unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Sub* unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RefObj* unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RefObj* unk5c;

    void FUN_00888d30(C* c, Tmp* t);
    Sub* GetSub() {
        if (!unk30)
            unk30 = FUN_00890750();
        return unk30;
    }
};


void FUN_00888f80(Slot** pp);
void FUN_0088ff50(Tmp** pp);
void FUN_00b62c70(Tmp* t, int a, int b, int c, int d);


inline void AssignRef(RefObj** pd, RefObj* src)
{
    RefObj* old = *pd;
    if (old != src) {
        if (old) {
            if (InterlockedDecrement(&old->refs) == 0)
                old->DeleteThis();
        }
        *pd = src;
        if (src)
            InterlockedIncrement(&src->refs);
    }
}

struct FUN_00b48bd0_cls {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    Slot* unk6c;
    Slot* unk70;
    Slot* unk74;
    RefObj* unk78;
    RefObj* unk7c;
    RefObj* unk80;
    RefObj* unk84;
    bool FUN_00b48bd0();
};

// pdb: VolumetricFogShader::LoadStagesAndPasses | VolumetricFogShader.obj | fnv360_0822_retail, objrun_prop, medium
bool FUN_00b48bd0_cls::FUN_00b48bd0()
{
    Slot** slots = &unk6c;
    for (int i = 0; i < 3; i++) {
        if (i == 2 && !DAT_01067b4e)
            continue;
        Slot** pp = &slots[i];
        if (*pp == 0) {
            FUN_00888f80(pp);
            TmpPtr tmp;
            FUN_0088ff50(&tmp.p);
            FUN_00b62c70(tmp.p, 0, 3, 2, 1);
            tmp.p->FUN_0088f0b0(0);
            Slot* s = *pp;
            s->FUN_00888d30(s->unk14, tmp.p);
        }
        switch (i) {
        case 0:
        case 1:
            AssignRef(&(*pp)->unk44, unk80);
            AssignRef(&(*pp)->unk5c, unk78);
            break;
        case 2:
            AssignRef(&(*pp)->unk44, unk84);
            AssignRef(&(*pp)->unk5c, unk7c);
            break;
        }
    skip:
        (*pp)->GetSub()->FUN_008905a0(0xa8, 0xf, 1);
        (*pp)->GetSub()->FUN_008905a0(7, 0, 1);
        (*pp)->GetSub()->FUN_008905a0(0xe, 0, 1);
        (*pp)->GetSub()->FUN_008905a0(0x17, 8, 1);
        (*pp)->GetSub()->FUN_008905a0(0x1b, 1, 1);
        Slot* o2 = *pp;
        o2->GetSub()->FUN_008905a0(0x13, 2, 1);
        o2->GetSub()->FUN_008905a0(0x14, 2, 1);
        if (i == 1) {
            unk70->GetSub()->FUN_008905a0(0x16, 3, 1);
        } else if (i == 0) {
            unk6c->GetSub()->FUN_008905a0(0x16, 2, 1);
        } else if (i == 2) {
            unk74->GetSub()->FUN_008905a0(0x16, 1, 1);
        }
        (*pp)->GetSub()->FUN_008905a0(0x34, 1, 1);
        (*pp)->GetSub()->FUN_008905a0(0x38, 8, 1);
        (*pp)->GetSub()->FUN_008905a0(0x39, 1, 1);
        (*pp)->GetSub()->FUN_008905a0(0x37, 3, 1);
        (*pp)->GetSub()->FUN_008905a0(0x36, 3, 1);
    }
    return true;
}
}   // namespace f3m_00b48bd0

// @f3 0x00b54710 (community match, verified in this file)
namespace f3m_00b54710 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }

    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }

    volatile long referenceCount;
};

struct ObjectReferences
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
    NiPointer<NiRefObject> object30;
    NiPointer<NiRefObject> object34;
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
    NiPointer<NiRefObject> object7C;
    NiPointer<NiRefObject> object80;
    NiPointer<NiRefObject> object84;
    NiPointer<NiRefObject> object88;

    void FUN_00b54710();
};

ObjectReferences* __cdecl FUN_00adb960(unsigned int selector);

void ObjectReferences::FUN_00b54710()
{
    ObjectReferences* source = FUN_00adb960(1);
    NiPointer<NiRefObject> first(source->object30);
    NiPointer<NiRefObject> second(source->object34);

    object34 = static_cast<NiRefObject*>(second);
    object30 = static_cast<NiRefObject*>(first);
    object7C = static_cast<NiRefObject*>(source->object7C);
    object80 = static_cast<NiRefObject*>(source->object80);
    object84 = static_cast<NiRefObject*>(source->object84);
    object88 = static_cast<NiRefObject*>(source->object88);
}
}   // namespace f3m_00b54710

// @f3 0x00b43df0 (community match, verified in this file)
#include <stdlib.h>
#include <string.h>
#include <new>

namespace EffectConstruction {

class Heap {
public:
    void* FUN_0086b930(size_t bytes);
};

extern Heap DAT_01090a78;

struct Sample {
    float values[4];

    static void* operator new[](size_t bytes)
    {
        return DAT_01090a78.FUN_0086b930(bytes);
    }
};

struct Point {
    float x, y, z;

    Point() {}
    Point(float xValue, float yValue, float zValue) : x(xValue), y(yValue), z(zValue) {}
};

struct Color {
    float r, g, b, a;

    Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
};

class FUN_00b2afb0 {
public:
    FUN_00b2afb0();
    virtual ~FUN_00b2afb0();

protected:
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
};

class FUN_00b43df0 : public FUN_00b2afb0 {
public:
    FUN_00b43df0();
    virtual ~FUN_00b43df0();

private:
    Sample* samples;
    Point position;
    float field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    float field84;
    float randomValues[40];
    unsigned int field128;
    float distance;
    float field130;
    float field134;
    float field138;
    float field13c;
    unsigned int sampleCount;
    float field144;
    float field148;
    unsigned int field14c;
    float field150;
    Color startColor;
    Color endColor;
    bool field174;
    bool field175;
    bool field176;
    bool field177;
    unsigned int field178;
    unsigned int field17c;
    float field180;
    unsigned int field184;
    unsigned int field188;
    float field18c;
};

extern const Color DAT_00f73220;
extern unsigned int DAT_01068958;
extern unsigned int DAT_01177ce4;

unsigned int __cdecl FUN_00b42bd0();
void __cdecl FUN_00b42c00();

// pdb: BoltShaderProperty::BoltShaderProperty | BoltShaderProperty.obj | fnv360_0822_retail, call_gap, low
FUN_00b43df0::FUN_00b43df0()
{
    field84 = 0.0f;
    field80 = 0;
    field180 = 0.0f;
    field184 = 0;
    field70 = 0.0f;
    field78 = 0;
    field7c = 0;
    field174 = false;
    field176 = true;
    field177 = true;
    position = Point(0.0f, distance, 0.0f);
    field74 = 4;

    sampleCount = FUN_00b42bd0();
    field144 = 1.0f;
    field148 = 1.0f;
    field14c = DAT_01068958;
    field150 = 1.0f;
    distance = 2048.0f;
    field128 = 1;
    field130 = 100.0f;
    field188 = 0;
    field134 = 3.0f;
    field138 = 3.0f;
    field13c = 1.0f;
    startColor = DAT_00f73220;
    endColor = DAT_00f73220;
    field175 = true;
    FUN_00b42c00();
    field178 = 0;

    const unsigned int count = FUN_00b42bd0();
    samples = new Sample[count];
    memset(samples, 0, count * sizeof(Sample));

    for (unsigned int i = 0; i < 40; ++i)
        randomValues[i] = static_cast<float>(rand() / 32767.0);

    ++DAT_01177ce4;
    field18c = 1.0f;
    field188 = 0;
    field58 = 0x19;
    field1c = 0xe;
}

}

// @f3 0x00b5c2c0 (community match, verified in this file)
namespace f3m_00b5c2c0 {
namespace f3_00b5c2c0 {
struct NiGeometry;
struct ShadowSceneLight;
struct RenderPassSink
{
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                    ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderSelector
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
    RenderPassSink* pPasses;
    int FUN_00b5c2c0(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d, bool e, bool f, bool g);
};
// Chooses a pass id from the seven boolean flags and type, submits it via pPasses when type is 1, otherwise increments count; sets out to false and returns 0.
// @fnv 0x00bda0a0
// pdb: BSShaderPPLightingProperty::AddAmbDiffTexPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abAlphaTest, abGlowMap, abFacegenBlend, abFog, abVertexColors, abTreeBranch
int ShaderSelector::FUN_00b5c2c0(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                                 bool* out, bool a, bool b, bool c, bool d, bool e, bool f, bool g)
{
    if (!a)
    {
        if (b)
        {
            if (c)
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x88, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x6e, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x86, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x87, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x6b, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x6c, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
            else
            {
                if (d)
                {
                    if (!e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x6d, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x83, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x84, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x69, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x6a, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x81, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x82, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x66, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x67, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                }
            }
            else
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x85, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x68, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x7f, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (!g)
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geom, 0x80, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geom, 0x7b, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x64, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (!g)
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geom, 0x65, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geom, 0x7a, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (c)
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x92, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x79, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x90, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x91, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x76, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x77, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
            else
            {
                if (d)
                {
                    if (!e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x78, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x8d, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x8e, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x74, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x75, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x8b, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x8c, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x71, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x72, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                }
            }
            else
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x8f, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x73, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x89, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x8a, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x6f, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geom, 0x70, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}
}
}   // namespace f3m_00b5c2c0

// @f3 0x00b50e50 (community match, verified in this file)
extern int DAT_0116efb0;
namespace f3m_00b50e50 {
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct PixelRef
{
    virtual void Destroy();
    virtual void DeleteThis();
    long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct PixelPtr
{
    PixelRef* ptr;
    void operator=(PixelRef* value)
    {
        if (ptr != value)
        {
            PixelRef* old = ptr;
            if (old)
                old->DecRefCount();
            ptr = value;
            if (value)
                value->IncRefCount();
        }
    }
};
extern "C" void* __cdecl FUN_00c00610(void*, int, unsigned int);
struct Macro
{
    const char* name;
    const char* value;
};
struct PixelDesc
{
    const char* file;
    const char* macros[18];
};
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
struct PixelLoader
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    PixelPtr shaders[33];
    PixelRef* FUN_00b636d0(char*, const char**, const char*, char*);
    void FUN_00b50e50();
};
// @fnv 0x00bcd7c0
void PixelLoader::FUN_00b50e50()
{
    PixelDesc desc[33];
    desc[0].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[0].macros[0] = "PARALLAX";
    desc[0].macros[1] = "";
    desc[0].macros[2] = 0;
    FUN_00c00610(&desc[0].macros[3], 0, 60);
    desc[1].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[1].macros[0] = "PARALLAX";
    desc[1].macros[1] = "";
    desc[1].macros[2] = "OPT";
    desc[1].macros[3] = "";
    desc[1].macros[4] = 0;
    FUN_00c00610(&desc[1].macros[5], 0, 52);
    desc[2].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[2].macros[0] = "PARALLAX";
    desc[2].macros[1] = "";
    desc[2].macros[2] = "SI";
    desc[2].macros[3] = "";
    desc[2].macros[4] = 0;
    FUN_00c00610(&desc[2].macros[5], 0, 52);
    desc[3].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[3].macros[0] = "PARALLAX";
    desc[3].macros[1] = "";
    desc[3].macros[2] = "PROJ_SHADOW";
    desc[3].macros[3] = "";
    desc[3].macros[4] = 0;
    FUN_00c00610(&desc[3].macros[5], 0, 52);
    desc[4].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[4].macros[0] = "PARALLAX";
    desc[4].macros[1] = "";
    desc[4].macros[2] = "SI";
    desc[4].macros[3] = "";
    desc[4].macros[4] = "PROJ_SHADOW";
    desc[4].macros[5] = "";
    desc[4].macros[6] = 0;
    FUN_00c00610(&desc[4].macros[7], 0, 44);
    desc[5].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[5].macros[0] = "LIGHTS";
    desc[5].macros[1] = "2";
    desc[5].macros[2] = "PARALLAX";
    desc[5].macros[3] = "";
    desc[5].macros[4] = 0;
    FUN_00c00610(&desc[5].macros[5], 0, 52);
    desc[6].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[6].macros[0] = "LIGHTS";
    desc[6].macros[1] = "2";
    desc[6].macros[2] = "PARALLAX";
    desc[6].macros[3] = "";
    desc[6].macros[4] = "SI";
    desc[6].macros[5] = "";
    desc[6].macros[6] = 0;
    FUN_00c00610(&desc[6].macros[7], 0, 44);
    desc[7].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[7].macros[0] = "LIGHTS";
    desc[7].macros[1] = "2";
    desc[7].macros[2] = "PARALLAX";
    desc[7].macros[3] = "";
    desc[7].macros[4] = "PROJ_SHADOW";
    desc[7].macros[5] = "";
    desc[7].macros[6] = 0;
    FUN_00c00610(&desc[7].macros[7], 0, 44);
    desc[8].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[8].macros[0] = "LIGHTS";
    desc[8].macros[1] = "2";
    desc[8].macros[2] = "PARALLAX";
    desc[8].macros[3] = "";
    desc[8].macros[4] = "SI";
    desc[8].macros[5] = "";
    desc[8].macros[6] = "PROJ_SHADOW";
    desc[8].macros[7] = "";
    desc[8].macros[8] = 0;
    memset(&desc[8].macros[9], 0, 36);
    desc[9].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[9].macros[0] = "SPECULAR";
    desc[9].macros[1] = "";
    desc[9].macros[2] = "PARALLAX";
    desc[9].macros[3] = "";
    desc[9].macros[4] = 0;
    FUN_00c00610(&desc[9].macros[5], 0, 52);
    desc[10].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[10].macros[0] = "SPECULAR";
    desc[10].macros[1] = "";
    desc[10].macros[2] = "PARALLAX";
    desc[10].macros[3] = "";
    desc[10].macros[4] = "SI";
    desc[10].macros[5] = "";
    desc[10].macros[6] = 0;
    FUN_00c00610(&desc[10].macros[7], 0, 44);
    desc[11].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[11].macros[0] = "SPECULAR";
    desc[11].macros[1] = "";
    desc[11].macros[2] = "PARALLAX";
    desc[11].macros[3] = "";
    desc[11].macros[4] = "PROJ_SHADOW";
    desc[11].macros[5] = "";
    desc[11].macros[6] = 0;
    FUN_00c00610(&desc[11].macros[7], 0, 44);
    desc[12].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[12].macros[0] = "SPECULAR";
    desc[12].macros[1] = "";
    desc[12].macros[2] = "PARALLAX";
    desc[12].macros[3] = "";
    desc[12].macros[4] = "SI";
    desc[12].macros[5] = "";
    desc[12].macros[6] = "PROJ_SHADOW";
    desc[12].macros[7] = "";
    desc[12].macros[8] = 0;
    memset(&desc[12].macros[9], 0, 36);
    desc[13].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[13].macros[0] = "LIGHTS";
    desc[13].macros[1] = "2";
    desc[13].macros[2] = "PARALLAX";
    desc[13].macros[3] = "";
    desc[13].macros[4] = 0;
    FUN_00c00610(&desc[13].macros[5], 0, 52);
    desc[14].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[14].macros[0] = "LIGHTS";
    desc[14].macros[1] = "2";
    desc[14].macros[2] = "PARALLAX";
    desc[14].macros[3] = "";
    desc[14].macros[4] = "SI";
    desc[14].macros[5] = "";
    desc[14].macros[6] = 0;
    FUN_00c00610(&desc[14].macros[7], 0, 44);
    desc[15].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[15].macros[0] = "LIGHTS";
    desc[15].macros[1] = "2";
    desc[15].macros[2] = "PARALLAX";
    desc[15].macros[3] = "";
    desc[15].macros[4] = "PROJ_SHADOW";
    desc[15].macros[5] = "";
    desc[15].macros[6] = 0;
    FUN_00c00610(&desc[15].macros[7], 0, 44);
    desc[16].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[16].macros[0] = "LIGHTS";
    desc[16].macros[1] = "2";
    desc[16].macros[2] = "PARALLAX";
    desc[16].macros[3] = "";
    desc[16].macros[4] = "SI";
    desc[16].macros[5] = "";
    desc[16].macros[6] = "PROJ_SHADOW";
    desc[16].macros[7] = "";
    desc[16].macros[8] = 0;
    memset(&desc[16].macros[9], 0, 36);
    desc[17].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[17].macros[0] = "LIGHTS";
    desc[17].macros[1] = "3";
    desc[17].macros[2] = "PARALLAX";
    desc[17].macros[3] = "";
    desc[17].macros[4] = 0;
    FUN_00c00610(&desc[17].macros[5], 0, 52);
    desc[18].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[18].macros[0] = "LIGHTS";
    desc[18].macros[1] = "3";
    desc[18].macros[2] = "PARALLAX";
    desc[18].macros[3] = "";
    desc[18].macros[4] = "SI";
    desc[18].macros[5] = "";
    desc[18].macros[6] = 0;
    FUN_00c00610(&desc[18].macros[7], 0, 44);
    desc[19].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[19].macros[0] = "LIGHTS";
    desc[19].macros[1] = "3";
    desc[19].macros[2] = "PARALLAX";
    desc[19].macros[3] = "";
    desc[19].macros[4] = "PROJ_SHADOW";
    desc[19].macros[5] = "";
    desc[19].macros[6] = 0;
    FUN_00c00610(&desc[19].macros[7], 0, 44);
    desc[20].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[20].macros[0] = "LIGHTS";
    desc[20].macros[1] = "3";
    desc[20].macros[2] = "PARALLAX";
    desc[20].macros[3] = "";
    desc[20].macros[4] = "SI";
    desc[20].macros[5] = "";
    desc[20].macros[6] = "PROJ_SHADOW";
    desc[20].macros[7] = "";
    desc[20].macros[8] = 0;
    memset(&desc[20].macros[9], 0, 36);
    desc[21].file = "lighting\\2x\\p\\DiffusePt.p.hlsl";
    desc[21].macros[0] = "LIGHTS";
    desc[21].macros[1] = "2";
    desc[21].macros[2] = "PARALLAX";
    desc[21].macros[3] = "";
    desc[21].macros[4] = 0;
    FUN_00c00610(&desc[21].macros[5], 0, 52);
    desc[22].file = "lighting\\2x\\p\\DiffusePt.p.hlsl";
    desc[22].macros[0] = "LIGHTS";
    desc[22].macros[1] = "3";
    desc[22].macros[2] = "PARALLAX";
    desc[22].macros[3] = "";
    desc[22].macros[4] = 0;
    FUN_00c00610(&desc[22].macros[5], 0, 52);
    desc[23].file = "lighting\\2x\\p\\Texture.p.hlsl";
    desc[23].macros[0] = "PARALLAX";
    desc[23].macros[1] = "";
    desc[23].macros[2] = 0;
    FUN_00c00610(&desc[23].macros[3], 0, 60);
    desc[24].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[24].macros[0] = "PARALLAX";
    desc[24].macros[1] = "";
    desc[24].macros[2] = 0;
    FUN_00c00610(&desc[24].macros[3], 0, 60);
    desc[25].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[25].macros[0] = "PARALLAX";
    desc[25].macros[1] = "";
    desc[25].macros[2] = "PROJ_SHADOW";
    desc[25].macros[3] = "";
    desc[25].macros[4] = 0;
    FUN_00c00610(&desc[25].macros[5], 0, 52);
    desc[26].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[26].macros[0] = "POINT";
    desc[26].macros[1] = "";
    desc[26].macros[2] = "PARALLAX";
    desc[26].macros[3] = "";
    desc[26].macros[4] = 0;
    FUN_00c00610(&desc[26].macros[5], 0, 52);
    desc[27].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[27].macros[0] = "NUM_PT_LIGHTS";
    desc[27].macros[1] = "2";
    desc[27].macros[2] = "POINT";
    desc[27].macros[3] = "";
    desc[27].macros[4] = "PARALLAX";
    desc[27].macros[5] = "";
    desc[27].macros[6] = 0;
    FUN_00c00610(&desc[27].macros[7], 0, 44);
    desc[28].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[28].macros[0] = "NUM_PT_LIGHTS";
    desc[28].macros[1] = "3";
    desc[28].macros[2] = "POINT";
    desc[28].macros[3] = "";
    desc[28].macros[4] = "PARALLAX";
    desc[28].macros[5] = "";
    desc[28].macros[6] = 0;
    FUN_00c00610(&desc[28].macros[7], 0, 44);
    desc[29].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[29].macros[0] = "SPECULAR";
    desc[29].macros[1] = "";
    desc[29].macros[2] = "LIGHTS";
    desc[29].macros[3] = "2";
    desc[29].macros[4] = "PARALLAX";
    desc[29].macros[5] = "";
    desc[29].macros[6] = 0;
    FUN_00c00610(&desc[29].macros[7], 0, 44);
    desc[30].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[30].macros[0] = "SPECULAR";
    desc[30].macros[1] = "";
    desc[30].macros[2] = "LIGHTS";
    desc[30].macros[3] = "2";
    desc[30].macros[4] = "PARALLAX";
    desc[30].macros[5] = "";
    desc[30].macros[6] = "SI";
    desc[30].macros[7] = "";
    desc[30].macros[8] = 0;
    memset(&desc[30].macros[9], 0, 36);
    desc[31].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[31].macros[0] = "SPECULAR";
    desc[31].macros[1] = "";
    desc[31].macros[2] = "LIGHTS";
    desc[31].macros[3] = "2";
    desc[31].macros[4] = "PARALLAX";
    desc[31].macros[5] = "";
    desc[31].macros[6] = "PROJ_SHADOW";
    desc[31].macros[7] = "";
    desc[31].macros[8] = 0;
    memset(&desc[31].macros[9], 0, 36);
    desc[32].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[32].macros[0] = "SPECULAR";
    desc[32].macros[1] = "";
    desc[32].macros[2] = "LIGHTS";
    desc[32].macros[3] = "2";
    desc[32].macros[4] = "PARALLAX";
    desc[32].macros[5] = "";
    desc[32].macros[6] = "SI";
    desc[32].macros[7] = "";
    desc[32].macros[8] = "PROJ_SHADOW";
    desc[32].macros[9] = "";
    desc[32].macros[10] = 0;
    memset(&desc[32].macros[11], 0, 28);
    static const char format[] = "PAR2%03i.pso";
    char path[260];
    char name[260];
    int shaderLevel = DAT_0116efb0;
    if (shaderLevel >= 2)
    {
        for (int index = 0; index < 29; ++index)
        {
            FUN_00b62b90(desc[index].file, path);
            FUN_00403230(name, 260, format, index);
            shaders[index] = FUN_00b636d0(path, desc[index].macros, "ps_2_0", name);
        }
        if (shaderLevel >= 5)
        {
            for (int index = 29; index < 33; ++index)
            {
                FUN_00b62b90(desc[index].file, path);
                FUN_00403230(name, 260, format, index);
                shaders[index] = FUN_00b636d0(path, desc[index].macros, "ps_2_0", name);
            }
        }
    }
}
}   // namespace f3m_00b50e50

// @f3 0x00b51fe0 (community match, verified in this file)
extern const char DAT_00db3438;
extern const char DAT_00dfa7c4;
extern const char DAT_00dfa800;
extern const char DAT_00dfa80c;
extern const char DAT_00dfa818;
extern const char DAT_00e2a53c;
extern const char DAT_00e9566c;
extern const char DAT_00e9568c;
extern const char DAT_00e956a8;
extern const char DAT_00e956c4;
extern const char DAT_00e956d0;
extern const char DAT_00e956d8;
extern const char DAT_00e9572c;
extern const char DAT_00e340d4;
extern const char DAT_00e95884;
extern const char DAT_00ea24ac;
extern int DAT_0116efb0;
namespace f3m_00b51fe0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void* __cdecl FUN_00c00610(void*, int, unsigned int);
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
struct ShaderObject
{
    virtual void Destroy();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct ShaderTail
{
    const char* arg12;
    const char* arg13;
    const char* arg14;
    const char* arg15;
    const char* arg16;
    const char* arg17;
};
struct ShaderEntry
{
    const char* filename;
    const char* arg00;
    const char* arg01;
    const char* arg02;
    const char* arg03;
    const char* arg04;
    const char* arg05;
    const char* arg06;
    const char* arg07;
    const char* arg08;
    const char* arg09;
    const char* arg10;
    const char* arg11;
    ShaderTail tail;
};
struct ShaderManager
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
    NiPointer<ShaderObject> m_programs[26];
    ShaderObject* FUN_00b62f60(const char*, const char* const*, const char*, const char*);
    void FUN_00b51fe0();
};
// @fnv 0x00bce950
// pdb: SkinShader::LoadVertexShaders | SkinShader.obj | fnv360_0822_retail, ustr, medium
void ShaderManager::FUN_00b51fe0()
{
    ShaderEntry entries[26];
    // Shader variant 0
    entries[0].filename = &DAT_00e9572c;
    entries[0].arg00 = &DAT_00e95884;
    entries[0].arg01 = &DAT_00db3438;
    entries[0].arg02 = 0;
    FUN_00c00610(&entries[0].arg03, 0, 60);
    // Shader variant 1
    entries[1].filename = &DAT_00e9572c;
    entries[1].arg00 = &DAT_00e340d4;
    entries[1].arg01 = &DAT_00db3438;
    entries[1].arg02 = &DAT_00e95884;
    entries[1].arg03 = &DAT_00db3438;
    entries[1].arg04 = 0;
    FUN_00c00610(&entries[1].arg05, 0, 52);
    // Shader variant 2
    entries[2].filename = &DAT_00e9572c;
    entries[2].arg00 = &DAT_00e95884;
    entries[2].arg01 = &DAT_00db3438;
    entries[2].arg02 = &DAT_00e956d8;
    entries[2].arg03 = &DAT_00db3438;
    entries[2].arg04 = 0;
    FUN_00c00610(&entries[2].arg05, 0, 52);
    // Shader variant 3
    entries[3].filename = &DAT_00e9572c;
    entries[3].arg00 = &DAT_00e340d4;
    entries[3].arg01 = &DAT_00db3438;
    entries[3].arg02 = &DAT_00e95884;
    entries[3].arg03 = &DAT_00db3438;
    entries[3].arg04 = &DAT_00e956d8;
    entries[3].arg05 = &DAT_00db3438;
    entries[3].arg06 = 0;
    FUN_00c00610(&entries[3].arg07, 0, 44);
    // Shader variant 4
    entries[4].filename = &DAT_00e9572c;
    entries[4].arg00 = &DAT_00e956d0;
    entries[4].arg01 = &DAT_00dfa818;
    entries[4].arg02 = &DAT_00e95884;
    entries[4].arg03 = &DAT_00db3438;
    entries[4].arg04 = 0;
    FUN_00c00610(&entries[4].arg05, 0, 52);
    // Shader variant 5
    entries[5].filename = &DAT_00e9572c;
    entries[5].arg00 = &DAT_00e340d4;
    entries[5].arg01 = &DAT_00db3438;
    entries[5].arg02 = &DAT_00e956d0;
    entries[5].arg03 = &DAT_00dfa818;
    entries[5].arg04 = &DAT_00e95884;
    entries[5].arg05 = &DAT_00db3438;
    entries[5].arg06 = 0;
    FUN_00c00610(&entries[5].arg07, 0, 44);
    // Shader variant 6
    entries[6].filename = &DAT_00e9572c;
    entries[6].arg00 = &DAT_00e956d0;
    entries[6].arg01 = &DAT_00dfa818;
    entries[6].arg02 = &DAT_00e95884;
    entries[6].arg03 = &DAT_00db3438;
    entries[6].arg04 = &DAT_00e956d8;
    entries[6].arg05 = &DAT_00db3438;
    entries[6].arg06 = 0;
    FUN_00c00610(&entries[6].arg07, 0, 44);
    // Shader variant 7
    entries[7].filename = &DAT_00e9572c;
    entries[7].arg00 = &DAT_00e340d4;
    entries[7].arg01 = &DAT_00db3438;
    entries[7].arg02 = &DAT_00e956d0;
    entries[7].arg03 = &DAT_00dfa818;
    entries[7].arg04 = &DAT_00e95884;
    entries[7].arg05 = &DAT_00db3438;
    entries[7].arg06 = &DAT_00e956d8;
    entries[7].arg07 = &DAT_00db3438;
    entries[7].arg08 = 0;
    entries[7].arg09 = 0;
    entries[7].arg10 = 0;
    entries[7].arg11 = 0;
    entries[7].tail = ShaderTail();
    // Shader variant 8
    entries[8].filename = &DAT_00e9568c;
    entries[8].arg00 = &DAT_00e956d0;
    entries[8].arg01 = &DAT_00dfa818;
    entries[8].arg02 = &DAT_00e95884;
    entries[8].arg03 = &DAT_00db3438;
    entries[8].arg04 = 0;
    FUN_00c00610(&entries[8].arg05, 0, 52);
    // Shader variant 9
    entries[9].filename = &DAT_00e9568c;
    entries[9].arg00 = &DAT_00e340d4;
    entries[9].arg01 = &DAT_00db3438;
    entries[9].arg02 = &DAT_00e956d0;
    entries[9].arg03 = &DAT_00dfa818;
    entries[9].arg04 = &DAT_00e95884;
    entries[9].arg05 = &DAT_00db3438;
    entries[9].arg06 = 0;
    FUN_00c00610(&entries[9].arg07, 0, 44);
    // Shader variant 10
    entries[10].filename = &DAT_00e9568c;
    entries[10].arg00 = &DAT_00e956d0;
    entries[10].arg01 = &DAT_00dfa818;
    entries[10].arg02 = &DAT_00e95884;
    entries[10].arg03 = &DAT_00db3438;
    entries[10].arg04 = &DAT_00e956d8;
    entries[10].arg05 = &DAT_00db3438;
    entries[10].arg06 = 0;
    FUN_00c00610(&entries[10].arg07, 0, 44);
    // Shader variant 11
    entries[11].filename = &DAT_00e9568c;
    entries[11].arg00 = &DAT_00e340d4;
    entries[11].arg01 = &DAT_00db3438;
    entries[11].arg02 = &DAT_00e956d0;
    entries[11].arg03 = &DAT_00dfa818;
    entries[11].arg04 = &DAT_00e95884;
    entries[11].arg05 = &DAT_00db3438;
    entries[11].arg06 = &DAT_00e956d8;
    entries[11].arg07 = &DAT_00db3438;
    entries[11].arg08 = 0;
    entries[11].arg09 = 0;
    entries[11].arg10 = 0;
    entries[11].arg11 = 0;
    entries[11].tail = ShaderTail();
    // Shader variant 12
    entries[12].filename = &DAT_00e9568c;
    entries[12].arg00 = &DAT_00e956d0;
    entries[12].arg01 = &DAT_00dfa80c;
    entries[12].arg02 = &DAT_00e95884;
    entries[12].arg03 = &DAT_00db3438;
    entries[12].arg04 = 0;
    FUN_00c00610(&entries[12].arg05, 0, 52);
    // Shader variant 13
    entries[13].filename = &DAT_00e9568c;
    entries[13].arg00 = &DAT_00e340d4;
    entries[13].arg01 = &DAT_00db3438;
    entries[13].arg02 = &DAT_00e956d0;
    entries[13].arg03 = &DAT_00dfa80c;
    entries[13].arg04 = &DAT_00e95884;
    entries[13].arg05 = &DAT_00db3438;
    entries[13].arg06 = 0;
    FUN_00c00610(&entries[13].arg07, 0, 44);
    // Shader variant 14
    entries[14].filename = &DAT_00e9568c;
    entries[14].arg00 = &DAT_00e956d0;
    entries[14].arg01 = &DAT_00dfa80c;
    entries[14].arg02 = &DAT_00e95884;
    entries[14].arg03 = &DAT_00db3438;
    entries[14].arg04 = &DAT_00e956d8;
    entries[14].arg05 = &DAT_00db3438;
    entries[14].arg06 = 0;
    FUN_00c00610(&entries[14].arg07, 0, 44);
    // Shader variant 15
    entries[15].filename = &DAT_00e9568c;
    entries[15].arg00 = &DAT_00e340d4;
    entries[15].arg01 = &DAT_00db3438;
    entries[15].arg02 = &DAT_00e956d0;
    entries[15].arg03 = &DAT_00dfa80c;
    entries[15].arg04 = &DAT_00e95884;
    entries[15].arg05 = &DAT_00db3438;
    entries[15].arg06 = &DAT_00e956d8;
    entries[15].arg07 = &DAT_00db3438;
    entries[15].arg08 = 0;
    entries[15].arg09 = 0;
    entries[15].arg10 = 0;
    entries[15].arg11 = 0;
    entries[15].tail = ShaderTail();
    // Shader variant 16
    entries[16].filename = &DAT_00e9566c;
    entries[16].arg00 = &DAT_00e956d0;
    entries[16].arg01 = &DAT_00dfa818;
    entries[16].arg02 = &DAT_00e95884;
    entries[16].arg03 = &DAT_00db3438;
    entries[16].arg04 = 0;
    FUN_00c00610(&entries[16].arg05, 0, 52);
    // Shader variant 17
    entries[17].filename = &DAT_00e9566c;
    entries[17].arg00 = &DAT_00e956d0;
    entries[17].arg01 = &DAT_00dfa818;
    entries[17].arg02 = &DAT_00e340d4;
    entries[17].arg03 = &DAT_00db3438;
    entries[17].arg04 = &DAT_00e95884;
    entries[17].arg05 = &DAT_00db3438;
    entries[17].arg06 = 0;
    FUN_00c00610(&entries[17].arg07, 0, 44);
    // Shader variant 18
    entries[18].filename = &DAT_00e9566c;
    entries[18].arg00 = &DAT_00e956d0;
    entries[18].arg01 = &DAT_00dfa80c;
    entries[18].arg02 = &DAT_00e95884;
    entries[18].arg03 = &DAT_00db3438;
    entries[18].arg04 = 0;
    FUN_00c00610(&entries[18].arg05, 0, 52);
    // Shader variant 19
    entries[19].filename = &DAT_00e9566c;
    entries[19].arg00 = &DAT_00e956d0;
    entries[19].arg01 = &DAT_00dfa80c;
    entries[19].arg02 = &DAT_00e340d4;
    entries[19].arg03 = &DAT_00db3438;
    entries[19].arg04 = &DAT_00e95884;
    entries[19].arg05 = &DAT_00db3438;
    entries[19].arg06 = 0;
    FUN_00c00610(&entries[19].arg07, 0, 44);
    // Shader variant 20
    entries[20].filename = &DAT_00e956a8;
    entries[20].arg00 = &DAT_00e956d0;
    entries[20].arg01 = &DAT_00dfa7c4;
    entries[20].arg02 = &DAT_00e95884;
    entries[20].arg03 = &DAT_00db3438;
    entries[20].arg04 = 0;
    FUN_00c00610(&entries[20].arg05, 0, 52);
    // Shader variant 21
    entries[21].filename = &DAT_00e956a8;
    entries[21].arg00 = &DAT_00e956d0;
    entries[21].arg01 = &DAT_00dfa7c4;
    entries[21].arg02 = &DAT_00e340d4;
    entries[21].arg03 = &DAT_00db3438;
    entries[21].arg04 = &DAT_00e95884;
    entries[21].arg05 = 0;
    entries[21].arg06 = 0;
    FUN_00c00610(&entries[21].arg07, 0, 44);
    // Shader variant 22
    entries[22].filename = &DAT_00e956a8;
    entries[22].arg00 = &DAT_00e956d0;
    entries[22].arg01 = &DAT_00dfa800;
    entries[22].arg02 = &DAT_00e95884;
    entries[22].arg03 = &DAT_00db3438;
    entries[22].arg04 = 0;
    FUN_00c00610(&entries[22].arg05, 0, 52);
    // Shader variant 23
    entries[23].filename = &DAT_00e956a8;
    entries[23].arg00 = &DAT_00e956d0;
    entries[23].arg01 = &DAT_00dfa800;
    entries[23].arg02 = &DAT_00e340d4;
    entries[23].arg03 = &DAT_00db3438;
    entries[23].arg04 = &DAT_00e95884;
    entries[23].arg05 = 0;
    entries[23].arg06 = 0;
    FUN_00c00610(&entries[23].arg07, 0, 44);
    // Shader variant 24
    entries[24].filename = &DAT_00e956a8;
    entries[24].arg00 = &DAT_00e956c4;
    entries[24].arg01 = &DAT_00db3438;
    entries[24].arg02 = &DAT_00e956d0;
    entries[24].arg03 = &DAT_00dfa800;
    entries[24].arg04 = &DAT_00e95884;
    entries[24].arg05 = 0;
    entries[24].arg06 = 0;
    FUN_00c00610(&entries[24].arg07, 0, 44);
    // Shader variant 25
    entries[25].filename = &DAT_00e956a8;
    entries[25].arg00 = &DAT_00e956c4;
    entries[25].arg01 = &DAT_00db3438;
    entries[25].arg02 = &DAT_00e956d0;
    entries[25].arg03 = &DAT_00dfa800;
    entries[25].arg04 = &DAT_00e340d4;
    entries[25].arg05 = &DAT_00db3438;
    entries[25].arg06 = &DAT_00e95884;
    entries[25].arg07 = 0;
    entries[25].arg08 = 0;
    entries[25].arg09 = 0;
    entries[25].arg10 = 0;
    entries[25].arg11 = 0;
    entries[25].tail = ShaderTail();
    if (DAT_0116efb0 >= 2)
    {
        char name[260];
        char path[260];
        for (int i = 0; i < 26; ++i)
        {
            const ShaderEntry& entry = entries[i];
            if (entry.filename)
            {
                FUN_00b62b90(entry.filename, path);
                FUN_00403230(name, 260, &DAT_00ea24ac, i);
                m_programs[i] = FUN_00b62f60(path, &entry.arg00, &DAT_00e2a53c, name);
            }
        }
    }
}
}   // namespace f3m_00b51fe0

// @f3 0x00b4fde0 (community match, verified in this file)
#include <string.h>
extern int DAT_0116efb0;
namespace f3m_00b4fde0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void* __cdecl FUN_00c00610(void*, int, unsigned int);
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
// Adapted from FNV; prior contributor credited in the reference (2026-10-23).
struct RefObject
{
    virtual void Unused() = 0;
    virtual void Release() = 0;

    long m_iObjectReferenceCount;
};
struct BeamPtr
{
    RefObject* ptr;
    void Assign(RefObject* p)
    {
        RefObject* old = ptr;
        if (old != p)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            ptr = p;
            if (p)
                InterlockedIncrement(&p->m_iObjectReferenceCount);
        }
    }
};
struct ParallaxDescriptor
{
    const char* file;
    const char* macros[18];
};
struct ParallaxShader
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
    BeamPtr shaders[20];
    RefObject* FUN_00b62f60(const char*, unsigned int*, const char*, const char*);
    void FUN_00b4fde0();
};
// @fnv 0x00bcc750
void ParallaxShader::FUN_00b4fde0()
{
    ParallaxDescriptor descriptors[20];
    descriptors[0].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[0].macros[0] = "PARALLAX";
    descriptors[0].macros[1] = "";
    descriptors[0].macros[2] = 0;
    FUN_00c00610(&descriptors[0].macros[3], 0, 60);
    descriptors[1].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[1].macros[0] = "PARALLAX";
    descriptors[1].macros[1] = "";
    descriptors[1].macros[2] = "PROJ_SHADOW";
    descriptors[1].macros[3] = "";
    descriptors[1].macros[4] = 0;
    FUN_00c00610(&descriptors[1].macros[5], 0, 52);
    descriptors[2].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[2].macros[0] = "LIGHTS";
    descriptors[2].macros[1] = "2";
    descriptors[2].macros[2] = "PARALLAX";
    descriptors[2].macros[3] = "";
    descriptors[2].macros[4] = 0;
    FUN_00c00610(&descriptors[2].macros[5], 0, 52);
    descriptors[3].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[3].macros[0] = "LIGHTS";
    descriptors[3].macros[1] = "2";
    descriptors[3].macros[2] = "PARALLAX";
    descriptors[3].macros[3] = "";
    descriptors[3].macros[4] = "PROJ_SHADOW";
    descriptors[3].macros[5] = "";
    descriptors[3].macros[6] = 0;
    FUN_00c00610(&descriptors[3].macros[7], 0, 44);
    descriptors[4].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[4].macros[0] = "SPECULAR";
    descriptors[4].macros[1] = "";
    descriptors[4].macros[2] = "PARALLAX";
    descriptors[4].macros[3] = "";
    descriptors[4].macros[4] = 0;
    FUN_00c00610(&descriptors[4].macros[5], 0, 52);
    descriptors[5].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[5].macros[0] = "SPECULAR";
    descriptors[5].macros[1] = "";
    descriptors[5].macros[2] = "PARALLAX";
    descriptors[5].macros[3] = "";
    descriptors[5].macros[4] = "PROJ_SHADOW";
    descriptors[5].macros[5] = "";
    descriptors[5].macros[6] = 0;
    FUN_00c00610(&descriptors[5].macros[7], 0, 44);
    descriptors[6].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[6].macros[0] = "SPECULAR";
    descriptors[6].macros[1] = "";
    descriptors[6].macros[2] = "LIGHTS";
    descriptors[6].macros[3] = "2";
    descriptors[6].macros[4] = "PARALLAX";
    descriptors[6].macros[5] = "";
    descriptors[6].macros[6] = 0;
    FUN_00c00610(&descriptors[6].macros[7], 0, 44);
    descriptors[7].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[7].macros[0] = "SPECULAR";
    descriptors[7].macros[1] = "";
    descriptors[7].macros[2] = "LIGHTS";
    descriptors[7].macros[3] = "2";
    descriptors[7].macros[4] = "PARALLAX";
    descriptors[7].macros[5] = "";
    descriptors[7].macros[6] = "PROJ_SHADOW";
    descriptors[7].macros[7] = "";
    descriptors[7].macros[8] = 0;
    memset(&descriptors[7].macros[9], 0, 36);
    descriptors[8].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[8].macros[0] = "LIGHTS";
    descriptors[8].macros[1] = "2";
    descriptors[8].macros[2] = "PARALLAX";
    descriptors[8].macros[3] = "";
    descriptors[8].macros[4] = 0;
    FUN_00c00610(&descriptors[8].macros[5], 0, 52);
    descriptors[9].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[9].macros[0] = "LIGHTS";
    descriptors[9].macros[1] = "2";
    descriptors[9].macros[2] = "PARALLAX";
    descriptors[9].macros[3] = "";
    descriptors[9].macros[4] = "PROJ_SHADOW";
    descriptors[9].macros[5] = "";
    descriptors[9].macros[6] = 0;
    FUN_00c00610(&descriptors[9].macros[7], 0, 44);
    descriptors[10].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[10].macros[0] = "LIGHTS";
    descriptors[10].macros[1] = "3";
    descriptors[10].macros[2] = "PARALLAX";
    descriptors[10].macros[3] = "";
    descriptors[10].macros[4] = 0;
    FUN_00c00610(&descriptors[10].macros[5], 0, 52);
    descriptors[11].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[11].macros[0] = "LIGHTS";
    descriptors[11].macros[1] = "3";
    descriptors[11].macros[2] = "PARALLAX";
    descriptors[11].macros[3] = "";
    descriptors[11].macros[4] = "PROJ_SHADOW";
    descriptors[11].macros[5] = "";
    descriptors[11].macros[6] = 0;
    FUN_00c00610(&descriptors[11].macros[7], 0, 44);
    descriptors[12].file = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    descriptors[12].macros[0] = "LIGHTS";
    descriptors[12].macros[1] = "2";
    descriptors[12].macros[2] = "PARALLAX";
    descriptors[12].macros[3] = "";
    descriptors[12].macros[4] = 0;
    FUN_00c00610(&descriptors[12].macros[5], 0, 52);
    descriptors[13].file = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    descriptors[13].macros[0] = "LIGHTS";
    descriptors[13].macros[1] = "3";
    descriptors[13].macros[2] = "PARALLAX";
    descriptors[13].macros[3] = "";
    descriptors[13].macros[4] = 0;
    FUN_00c00610(&descriptors[13].macros[5], 0, 52);
    descriptors[14].file = "lighting\\2x\\v\\Texture.v.hlsl";
    descriptors[14].macros[0] = "PARALLAX";
    descriptors[14].macros[1] = "";
    descriptors[14].macros[2] = 0;
    FUN_00c00610(&descriptors[14].macros[3], 0, 60);
    descriptors[15].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[15].macros[0] = "PARALLAX";
    descriptors[15].macros[1] = "";
    descriptors[15].macros[2] = 0;
    FUN_00c00610(&descriptors[15].macros[3], 0, 60);
    descriptors[16].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[16].macros[0] = "PARALLAX";
    descriptors[16].macros[1] = "";
    descriptors[16].macros[2] = "PROJ_SHADOW";
    descriptors[16].macros[3] = "";
    descriptors[16].macros[4] = 0;
    FUN_00c00610(&descriptors[16].macros[5], 0, 52);
    descriptors[17].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[17].macros[0] = "POINT";
    descriptors[17].macros[1] = "";
    descriptors[17].macros[2] = "PARALLAX";
    descriptors[17].macros[3] = "";
    descriptors[17].macros[4] = 0;
    FUN_00c00610(&descriptors[17].macros[5], 0, 52);
    descriptors[18].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[18].macros[0] = "NUM_PT_LIGHTS";
    descriptors[18].macros[1] = "2";
    descriptors[18].macros[2] = "POINT";
    descriptors[18].macros[3] = "";
    descriptors[18].macros[4] = "PARALLAX";
    descriptors[18].macros[5] = "";
    descriptors[18].macros[6] = 0;
    FUN_00c00610(&descriptors[18].macros[7], 0, 44);
    descriptors[19].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[19].macros[0] = "NUM_PT_LIGHTS";
    descriptors[19].macros[1] = "3";
    descriptors[19].macros[2] = "POINT";
    descriptors[19].macros[3] = "";
    descriptors[19].macros[4] = "PARALLAX";
    descriptors[19].macros[5] = "";
    descriptors[19].macros[6] = 0;
    FUN_00c00610(&descriptors[19].macros[7], 0, 44);

    char sourceName[260];
    char binaryName[260];
    if (DAT_0116efb0 >= 2)
    {
        for (int i = 0; i < 20; ++i)
        {
            FUN_00b62b90(descriptors[i].file, sourceName);
            FUN_00403230(binaryName, 260, "PAR2%03i.vso", i);
            shaders[i].Assign(FUN_00b62f60(sourceName, (unsigned int*)descriptors[i].macros, "vs_2_0", binaryName));
        }
    }
}
}   // namespace f3m_00b4fde0

// @f3 0x00b529b0 (community match, verified in this file)
extern const char DAT_00e95c44;
extern const char DAT_00e95884;
extern const char DAT_00db3438;
extern const char DAT_00e956d8;
extern const char DAT_00e956d0;
extern const char DAT_00dfa818;
extern const char DAT_00e95be0;
extern const char DAT_00dfa80c;
extern const char DAT_00e95bc0;
extern const char DAT_00e95bf8;
extern const char DAT_00dfa7c4;
extern const char DAT_00dfa800;
extern const char DAT_00e956c4;
extern const char DAT_00ea24bc;
extern const char DAT_00e2a504;
extern int DAT_0116efb0;
namespace f3m_00b529b0 {
struct FeatureDescription
{
    const char* name;
    const char* family;
    const char* source;
    const char* variant;
    const char* suffix;
    const char* selection;
    const char* support;
    const char* fallback;
    const char* p08;
    const char* p09;
    const char* p0a;
    const char* p0b;
    const char* p0c;
    const char* p0d;
    const char* p0e;
    const char* p0f;
    const char* p10;
    const char* p11;
    const char* p12;
};
struct FeatureObject
{
    virtual void v00();
    virtual void Release();
    volatile long references;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" void* __cdecl FUN_00c00610(void*, int, unsigned int);
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
struct FeatureManager
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    FeatureObject* features[13];
    FeatureObject* __thiscall FUN_00b636d0(char*, const char**, const char*, char*);
    void __thiscall FUN_00b529b0();
};
// @fnv 0x00bcf320
// pdb: SkinShader::LoadPixelShaders | SkinShader.obj | fnv360_0822_retail, ustr, medium
void FeatureManager::FUN_00b529b0()
{
    FeatureDescription descriptors[13];
    descriptors[0].name = &DAT_00e95c44;
    descriptors[0].family = &DAT_00e95884;
    descriptors[0].source = &DAT_00db3438;
    descriptors[0].variant = 0;
    FUN_00c00610(&descriptors[0].suffix, 0, 60);
    descriptors[1].name = &DAT_00e95c44;
    descriptors[1].family = &DAT_00e95884;
    descriptors[1].source = &DAT_00db3438;
    descriptors[1].variant = &DAT_00e956d8;
    descriptors[1].suffix = &DAT_00db3438;
    descriptors[1].selection = 0;
    FUN_00c00610(&descriptors[1].support, 0, 52);
    descriptors[2].name = &DAT_00e95c44;
    descriptors[2].family = &DAT_00e956d0;
    descriptors[2].source = &DAT_00dfa818;
    descriptors[2].variant = &DAT_00e95884;
    descriptors[2].suffix = &DAT_00db3438;
    descriptors[2].selection = 0;
    FUN_00c00610(&descriptors[2].support, 0, 52);
    descriptors[3].name = &DAT_00e95c44;
    descriptors[3].family = &DAT_00e956d0;
    descriptors[3].source = &DAT_00dfa818;
    descriptors[3].variant = &DAT_00e95884;
    descriptors[3].suffix = &DAT_00db3438;
    descriptors[3].selection = &DAT_00e956d8;
    descriptors[3].support = &DAT_00db3438;
    descriptors[3].fallback = 0;
    FUN_00c00610(&descriptors[3].p08, 0, 44);
    descriptors[4].name = &DAT_00e95be0;
    descriptors[4].family = &DAT_00e956d0;
    descriptors[4].source = &DAT_00dfa818;
    descriptors[4].variant = &DAT_00e95884;
    descriptors[4].suffix = &DAT_00db3438;
    descriptors[4].selection = 0;
    FUN_00c00610(&descriptors[4].support, 0, 52);
    descriptors[5].name = &DAT_00e95be0;
    descriptors[5].family = &DAT_00e956d0;
    descriptors[5].source = &DAT_00dfa818;
    descriptors[5].variant = &DAT_00e95884;
    descriptors[5].suffix = &DAT_00db3438;
    descriptors[5].selection = &DAT_00e956d8;
    descriptors[5].support = &DAT_00db3438;
    descriptors[5].fallback = 0;
    FUN_00c00610(&descriptors[5].p08, 0, 44);
    descriptors[6].name = &DAT_00e95be0;
    descriptors[6].family = &DAT_00e956d0;
    descriptors[6].source = &DAT_00dfa80c;
    descriptors[6].variant = &DAT_00e95884;
    descriptors[6].suffix = &DAT_00db3438;
    descriptors[6].selection = 0;
    FUN_00c00610(&descriptors[6].support, 0, 52);
    descriptors[7].name = &DAT_00e95be0;
    descriptors[7].family = &DAT_00e956d0;
    descriptors[7].source = &DAT_00dfa80c;
    descriptors[7].variant = &DAT_00e95884;
    descriptors[7].suffix = &DAT_00db3438;
    descriptors[7].selection = &DAT_00e956d8;
    descriptors[7].support = &DAT_00db3438;
    descriptors[7].fallback = 0;
    FUN_00c00610(&descriptors[7].p08, 0, 44);
    descriptors[8].name = &DAT_00e95bc0;
    descriptors[8].family = &DAT_00e956d0;
    descriptors[8].source = &DAT_00dfa818;
    descriptors[8].variant = &DAT_00e95884;
    descriptors[8].suffix = &DAT_00db3438;
    descriptors[8].selection = 0;
    FUN_00c00610(&descriptors[8].support, 0, 52);
    descriptors[9].name = &DAT_00e95bc0;
    descriptors[9].family = &DAT_00e956d0;
    descriptors[9].source = &DAT_00dfa80c;
    descriptors[9].variant = &DAT_00e95884;
    descriptors[9].suffix = &DAT_00db3438;
    descriptors[9].selection = 0;
    FUN_00c00610(&descriptors[9].support, 0, 52);
    descriptors[10].name = &DAT_00e95bf8;
    descriptors[10].family = &DAT_00e956d0;
    descriptors[10].source = &DAT_00dfa7c4;
    descriptors[10].variant = &DAT_00e95884;
    descriptors[10].suffix = 0;
    descriptors[10].selection = 0;
    FUN_00c00610(&descriptors[10].support, 0, 52);
    descriptors[11].name = &DAT_00e95bf8;
    descriptors[11].family = &DAT_00e956d0;
    descriptors[11].source = &DAT_00dfa800;
    descriptors[11].variant = &DAT_00e95884;
    descriptors[11].suffix = 0;
    descriptors[11].selection = 0;
    FUN_00c00610(&descriptors[11].support, 0, 52);
    descriptors[12].name = &DAT_00e95bf8;
    descriptors[12].family = &DAT_00e956c4;
    descriptors[12].source = &DAT_00db3438;
    descriptors[12].variant = &DAT_00e956d0;
    descriptors[12].suffix = &DAT_00dfa800;
    descriptors[12].selection = &DAT_00e95884;
    descriptors[12].support = 0;
    descriptors[12].fallback = 0;
    FUN_00c00610(&descriptors[12].p08, 0, 44);
    if (DAT_0116efb0 >= 2)
    {
        char qualifiedName[260];
        char formatBuffer[260];
        int index = 0;
        FeatureDescription* descriptor = descriptors;
        FeatureObject** destination = features;
        for (; index < 13; ++index, ++destination, ++descriptor)
        {
            if (!descriptor->name)
                continue;
            FUN_00b62b90(descriptor->name, qualifiedName);
            FUN_00403230(formatBuffer, 0x104, &DAT_00ea24bc, index);
            FeatureObject* next = FUN_00b636d0(qualifiedName, &descriptor->family, &DAT_00e2a504, formatBuffer);
            FeatureObject* old = *destination;
            if (old != next)
            {
                if (old && InterlockedDecrement(&old->references) == 0)
                    old->Release();
                *destination = next;
                if (next)
                    InterlockedIncrement(&next->references);
            }
        }
    }
}
}   // namespace f3m_00b529b0

// @f3 0x00b5e380 (community match, verified in this file)
namespace f3m_00b5e380 {
class NiGeometry;
class ShadowSceneLight;
struct ShaderPassList {
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char,
                     ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderTarget
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
    ShaderPassList* pPasses;
    int FUN_00b5e380(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, unsigned char, bool*, bool,
                     bool, bool, bool, bool, bool, bool);
};
// @fnv 0x00bdc0d0
// pdb: BSShaderPPLightingProperty::AddAmbDiff2Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, apSunlight, apPtLight, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abFacegenBlend, abMultitexture, abProjShadow, abParallax, abTreeBranch
int ShaderTarget::FUN_00b5e380(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                               unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c,
                               bool unused, bool d, bool e, bool f)
{
    if (!a)
    {
        if (!b)
        {
            if (!c)
            {
                if (!e)
                {
                    if (!d)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geometry, 0xd7, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geometry, 0xdf, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geometry, 0xe0, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geometry, 0xe8, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!d)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xd9, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xe2, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xdb, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xe4, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xd8, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xe1, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
    }
    else
    {
        if (!b)
        {
            if (!c)
            {
                if (!e)
                {
                    if (!d)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xdc, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xe5, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xde, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xe7, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xdd, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xe6, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
    }
    *out = false;
    return 0;
}
}   // namespace f3m_00b5e380

// @f3 0x00b5ed10 (community match, verified in this file)
namespace f3m_00b5ed10 {
namespace fo3_b5ed10 {
struct NiGeometry; struct ShadowSceneLight;
struct PassArray { void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*); };
struct ShaderTwoLightSelector
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
    PassArray* passes;

    __forceinline void RegisterPass(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                    unsigned short* count, unsigned char type, unsigned short pass)
    {
        if (type == 1)
            passes->FUN_00b2c0b0(geometry, pass, true, 2, light0, light1, 0, 0);
        else
            ++*count;
    }

    int FUN_00b5ed10(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                           unsigned short* count, unsigned char type, bool* first, bool a, bool b, bool c, bool unused,
                           bool e, bool f, bool g, bool h);
};

// @fnv 0x00bdca60
// pdb: BSShaderPPLightingProperty::AddAmbDiffTexPass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abFacegenBlend, abMultitexture, abProjShadow, abParallax, abModelSpaceNormals, abTreeBranch, abTreeBillboard, abHair, abAlphaTest
int ShaderTwoLightSelector::FUN_00b5ed10(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                               unsigned short* count, unsigned char type, bool* first, bool a, bool b,
                                               bool c, bool unused, bool e, bool f, bool g, bool h)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x117);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x122);
                    }
                }
                else
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x11a);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x125);
                    }
                }
            }
            else
            {
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x118);
                }
                else
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x123);
                }
            }
            else
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x116);
                            }
                            else
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x11b);
                            }
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x11f);
                        }
                    }
                    else
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x121);
                            }
                            else
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x126);
                            }
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x12a);
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x119);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x124);
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x11d);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x128);
                    }
                }
                else
                {
                }
            }
            else
            {
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x11e);
                }
                else
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x129);
                }
            }
            else
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!h)
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x11c);
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x120);
                        }
                    }
                    else
                    {
                        if (!h)
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x127);
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x12b);
                        }
                    }
                }
                else
                {
                }
            }
        }
    }
    *first = false;
    return 0;
}

}
}   // namespace f3m_00b5ed10

// @f3 0x00b5b760 (community match, verified in this file)
namespace f3m_00b5b760 {
class NiGeometry;
class ShadowSceneLight;
struct ShaderPassList {
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char,
                     ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderSelector {
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
    ShaderPassList* pPasses;
    int FUN_00b5b760(NiGeometry*, ShadowSceneLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
};
// @fnv 0x00bd9540
// pdb: BSShaderPPLightingProperty::AddAmbientPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abAlphaTest, abGlowMap, abTreeBranch
int ShaderSelector::FUN_00b5b760(NiGeometry* geom, ShadowSceneLight* light, unsigned short* pusCount,
                                  unsigned char type, bool* pbOut, bool a, bool b, bool c, bool d)
{
    if (!a)
    {
        if (b)
        {
            if (c)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x5b, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x5a, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
        else
        {
            if (c)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x59, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else if (!d)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x58, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x60, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
    }
    else
    {
        if (b)
        {
            if (c)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x5f, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x5e, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
        else
        {
            if (c)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x5d, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x5c, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
    }
    *pbOut = false;
    return 0;
}
}   // namespace f3m_00b5b760

// @f3 0x00b53bb0 (community match, verified in this file)
namespace f3_0214 {
struct RefObject
{
    virtual void Unused() = 0;
    virtual void Release() = 0;

    long m_iObjectReferenceCount;
};
extern int DAT_0116efb0;

extern const char DAT_00ea2688[];
extern const char DAT_00ea2680[];
extern const char DAT_00ea267c[];
extern const char DAT_00ea2678[];
extern const char DAT_00ea2670[];
extern const char DAT_00ea266c[];
extern const char DAT_00ea2658[];
extern const char DAT_00ea2648[];
extern const char DAT_00ea2638[];
extern const char DAT_00e2a544[];
extern const char DAT_00e2a53c[];
extern char DAT_00db3438;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void* __cdecl FUN_00c00610(void* dst, int val, unsigned int n);
void __cdecl FUN_00b62b90(void* val, void* buf);
void __cdecl FUN_00403230(char* dst, unsigned int n, const char* fmt, int i);

struct Elem540
{
    const char* f00;
    const char* f04;
    void* f08;
    const char* f0c;
    void* f10;
    const char* f14;
    void* f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
};

struct Manager0214
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
    RefObject* m_arr94[7];
    unsigned int unkB0, unkB4, unkB8;
    RefObject* m_arrBC[7];
    RefObject* __thiscall FUN_00b62f60(void* buf, void* pField, const char* str, char* buf2);
    void FUN_00b53bb0();
};

// @fnv 0x00bd0540
// pdb: HairShader::LoadVertexShaders | HairShader.obj | fnv360_0822_retail, ustr, medium
void Manager0214::FUN_00b53bb0()
{
    Elem540 arrB[7];
    Elem540 arrA[7];
    char bufB[0x104];
    char bufA[0x104];

    arrA[0].f00 = DAT_00ea2688;
    arrA[0].f04 = DAT_00ea2680;
    arrA[0].f08 = &DAT_00db3438;
    arrA[0].f0c = 0;
    FUN_00c00610(&arrA[0].f10, 0, 0x3c);
    arrA[1].f00 = DAT_00ea2688;
    arrA[1].f04 = DAT_00ea2680;
    arrA[1].f08 = &DAT_00db3438;
    arrA[1].f0c = DAT_00ea267c;
    arrA[1].f10 = &DAT_00db3438;
    arrA[1].f14 = 0;
    FUN_00c00610(&arrA[1].f18, 0, 0x34);
    arrA[2].f00 = DAT_00ea2688;
    arrA[2].f04 = DAT_00ea2678;
    arrA[2].f08 = &DAT_00db3438;
    arrA[2].f0c = DAT_00ea2670;
    arrA[2].f10 = &DAT_00db3438;
    arrA[2].f14 = 0;
    FUN_00c00610(&arrA[2].f18, 0, 0x34);
    arrA[3].f00 = DAT_00ea2688;
    arrA[3].f04 = DAT_00ea2680;
    arrA[3].f08 = &DAT_00db3438;
    arrA[3].f0c = DAT_00ea267c;
    arrA[3].f10 = &DAT_00db3438;
    arrA[3].f14 = DAT_00ea266c;
    arrA[3].f18 = &DAT_00db3438;
    arrA[3].f1c = 0;
    FUN_00c00610(&arrA[3].f20, 0, 0x2c);
    arrA[4].f00 = DAT_00ea2688;
    arrA[4].f04 = DAT_00ea2678;
    arrA[4].f08 = &DAT_00db3438;
    arrA[4].f0c = DAT_00ea2670;
    arrA[4].f10 = &DAT_00db3438;
    arrA[4].f14 = DAT_00ea266c;
    arrA[4].f18 = &DAT_00db3438;
    arrA[4].f1c = 0;
    FUN_00c00610(&arrA[4].f20, 0, 0x2c);
    arrA[5].f00 = DAT_00ea2688;
    arrA[5].f04 = DAT_00ea2678;
    arrA[5].f08 = &DAT_00db3438;
    arrA[5].f0c = DAT_00ea267c;
    arrA[5].f10 = &DAT_00db3438;
    arrA[5].f14 = DAT_00ea266c;
    arrA[5].f18 = &DAT_00db3438;
    arrA[5].f1c = 0;
    FUN_00c00610(&arrA[5].f20, 0, 0x2c);
    arrA[6].f00 = DAT_00ea2688;
    arrA[6].f04 = DAT_00ea2678;
    arrA[6].f08 = &DAT_00db3438;
    arrA[6].f0c = DAT_00ea267c;
    arrA[6].f10 = &DAT_00db3438;
    arrA[6].f14 = 0;
    FUN_00c00610(&arrA[6].f18, 0, 0x34);

    arrB[0].f00 = DAT_00ea2658;
    arrB[0].f04 = DAT_00ea2680;
    arrB[0].f08 = &DAT_00db3438;
    arrB[0].f0c = 0;
    FUN_00c00610(&arrB[0].f10, 0, 0x3c);
    arrB[1].f00 = DAT_00ea2658;
    arrB[1].f04 = DAT_00ea2680;
    arrB[1].f08 = &DAT_00db3438;
    arrB[1].f0c = DAT_00ea267c;
    arrB[1].f10 = &DAT_00db3438;
    arrB[1].f14 = 0;
    FUN_00c00610(&arrB[1].f18, 0, 0x34);
    arrB[2].f00 = DAT_00ea2658;
    arrB[2].f04 = DAT_00ea2678;
    arrB[2].f08 = &DAT_00db3438;
    arrB[2].f0c = DAT_00ea2670;
    arrB[2].f10 = &DAT_00db3438;
    arrB[2].f14 = 0;
    FUN_00c00610(&arrB[2].f18, 0, 0x34);
    arrB[3].f00 = DAT_00ea2658;
    arrB[3].f04 = DAT_00ea2680;
    arrB[3].f08 = &DAT_00db3438;
    arrB[3].f0c = DAT_00ea267c;
    arrB[3].f10 = &DAT_00db3438;
    arrB[3].f14 = DAT_00ea266c;
    arrB[3].f18 = &DAT_00db3438;
    arrB[3].f1c = 0;
    FUN_00c00610(&arrB[3].f20, 0, 0x2c);
    arrB[4].f00 = DAT_00ea2658;
    arrB[4].f04 = DAT_00ea2678;
    arrB[4].f08 = &DAT_00db3438;
    arrB[4].f0c = DAT_00ea2670;
    arrB[4].f10 = &DAT_00db3438;
    arrB[4].f14 = DAT_00ea266c;
    arrB[4].f18 = &DAT_00db3438;
    arrB[4].f1c = 0;
    FUN_00c00610(&arrB[4].f20, 0, 0x2c);
    arrB[5].f00 = DAT_00ea2658;
    arrB[5].f04 = DAT_00ea2678;
    arrB[5].f08 = &DAT_00db3438;
    arrB[5].f0c = DAT_00ea267c;
    arrB[5].f10 = &DAT_00db3438;
    arrB[5].f14 = DAT_00ea266c;
    arrB[5].f18 = &DAT_00db3438;
    arrB[5].f1c = 0;
    FUN_00c00610(&arrB[5].f20, 0, 0x2c);
    arrB[6].f00 = DAT_00ea2658;
    arrB[6].f04 = DAT_00ea2678;
    arrB[6].f08 = &DAT_00db3438;
    arrB[6].f0c = DAT_00ea267c;
    arrB[6].f10 = &DAT_00db3438;
    arrB[6].f14 = 0;
    FUN_00c00610(&arrB[6].f18, 0, 0x34);

    for (int i = 0; i < 7; i++)
    {
        if (arrA[i].f00 != 0)
        {
            FUN_00b62b90((void*)arrA[i].f00, bufB);
            FUN_00403230(bufA, 0x104, DAT_00ea2648, i);
            RefObject* nv = FUN_00b62f60(bufB, &arrA[i].f04, DAT_00e2a544, bufA);
            RefObject* old = m_arr94[i];
            if (old != nv)
            {
                if (old != 0)
                {
                    if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                        old->Release();
                }
                m_arr94[i] = nv;
                if (nv != 0)
                    InterlockedIncrement(&nv->m_iObjectReferenceCount);
            }
        }
    }
    if (DAT_0116efb0 >= 2)
    {
        for (int i = 0; i < 7; i++)
        {
            FUN_00b62b90((void*)arrB[i].f00, bufB);
            FUN_00403230(bufA, 0x104, DAT_00ea2638, i);
            RefObject* nv = FUN_00b62f60(bufB, &arrB[i].f04, DAT_00e2a53c, bufA);
            RefObject* old = m_arrBC[i];
            if (old != nv)
            {
                if (old != 0)
                {
                    if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                        old->Release();
                }
                m_arrBC[i] = nv;
                if (nv != 0)
                    InterlockedIncrement(&nv->m_iObjectReferenceCount);
            }
        }
    }
}
}  // namespace fnv_00bd0540

// @f3 0x00b54360 (community match, verified in this file)
namespace f3m_00b54360 {
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct PassView
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
    int references;
    void FUN_00888c10();
};
struct PassPtr
{
    PassView* ptr;
    PassPtr() : ptr(0)
    {}
    ~PassPtr()
    {
        if (ptr && --ptr->references == 0)
            ptr->FUN_00888c10();
    }
    void clear()
    {
        PassView* old = ptr;
        if (old)
        {
            if (--old->references == 0)
                old->FUN_00888c10();
            ptr = 0;
        }
    }
};
struct FUN_00afc720
{
    virtual void Initialize();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    ~FUN_00afc720();
};
struct FUN_00b54360 : FUN_00afc720
{
    PassPtr passes[2];
    NiPointer<RefObj> vs1[7];
    NiPointer<RefObj> vs2[3];
    NiPointer<RefObj> ps1[7];
    NiPointer<RefObj> ps2[3];
    NiPointer<RefObj> spE4;
    NiPointer<RefObj> spE8;

    virtual void Initialize();
    ~FUN_00b54360();
};
// @fnv 0x00bd0ce0
// pdb: HairShader::~HairShader | HairShader.obj | fnv360_0822_retail, objrun, medium
FUN_00b54360::~FUN_00b54360()
{
    for (int i = 0; i < 7; ++i)
        vs1[i] = 0;
    for (int i = 0; i < 7; ++i)
        ps1[i] = 0;
    for (int i = 0; i < 3; ++i)
        vs2[i] = 0;
    for (int i = 0; i < 3; ++i)
        ps2[i] = 0;
    for (int i = 0; i < 2; ++i)
        passes[i].clear();
    spE4 = 0;
    spE8 = 0;
    unk060 = 0;
}
}   // namespace f3m_00b54360

// @f3 0x00b5e7e0 (community match, verified in this file)
namespace f3m_00b5e7e0 {
class NiGeometry;
class ShadowSceneLight;
struct ShaderPassList {
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderPassOwner
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
    ShaderPassList* pPasses;
    typedef ShaderPassList RPA;
    int __thiscall FUN_00b5e7e0(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                                 unsigned short* count, bool flag, bool* out, bool b8, bool b9, bool b10, bool b11,
                                 bool b12, bool b13, bool b14);
};
// @fnv 0x00bdc530
// pdb: BSShaderPPLightingProperty::AddAmbDiff3Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apSunlight, apPtLight, apPtLight2, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abFacegenBlend, abMultitexture, abProjShadow, abParallax, abTreeBranch
int __thiscall ShaderPassOwner::FUN_00b5e7e0(NiGeometry* apGeometry, ShadowSceneLight* apLight0,
                                              ShadowSceneLight* apLight1, ShadowSceneLight* apLight2,
                                              unsigned short* count, bool flag, bool* out, bool b8, bool b9, bool b10,
                                              bool b11, bool b12, bool b13, bool b14)
{
    if (!b8)
    {
        if (!b9)
        {
            if (!b10)
            {
                if (!b13)
                {
                    if (!b12)
                    {
                        if (!b14)
                        {
                            if (flag == true)
                            {
                                pPasses->FUN_00b2c0b0(apGeometry, 233, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                        else
                        {
                            if (flag == true)
                            {
                                pPasses->FUN_00b2c0b0(apGeometry, 241, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!b14)
                        {
                            if (flag == true)
                            {
                                pPasses->FUN_00b2c0b0(apGeometry, 242, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                        else
                        {
                            if (flag == true)
                            {
                                pPasses->FUN_00b2c0b0(apGeometry, 250, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!b12)
                    {
                        if (flag == true)
                        {
                            pPasses->FUN_00b2c0b0(apGeometry, 235, true, 3, apLight0, apLight1, apLight2, 0);
                        }
                        else
                            ++*count;
                    }
                    else
                    {
                        if (flag == true)
                        {
                            pPasses->FUN_00b2c0b0(apGeometry, 244, true, 3, apLight0, apLight1, apLight2, 0);
                        }
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 237, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 246, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (b10)
                goto done;
            if (!b13)
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 234, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 243, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
            else
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 236, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 245, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
        }
    }
    else
    {
        if (!b9)
        {
            if (!b10)
            {
                if (b13)
                    goto done;
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 238, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 247, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
            else
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 240, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->FUN_00b2c0b0(apGeometry, 249, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (b10)
                goto done;
            if (b13)
                goto done;
            if (!b12)
            {
                if (flag == true)
                {
                    pPasses->FUN_00b2c0b0(apGeometry, 239, true, 3, apLight0, apLight1, apLight2, 0);
                }
                else
                    ++*count;
            }
            else
            {
                if (flag == true)
                {
                    pPasses->FUN_00b2c0b0(apGeometry, 248, true, 3, apLight0, apLight1, apLight2, 0);
                }
                else
                    ++*count;
            }
        }
    }
done:
    *out = false;
    return 0;
}
}   // namespace f3m_00b5e7e0

// @f3 0x00b5f7e0 (community match, verified in this file)
namespace f3m_00b5f7e0 {
namespace task0217 {
struct NiGeometry;
struct ShadowSceneLight;
struct BSShaderProperty
{
    struct ShaderPassList
    {
        void FUN_00b2c0b0(NiGeometry* geom, unsigned short pass, bool enabled, unsigned char numLights, ShadowSceneLight* l0,
                 ShadowSceneLight* l1, ShadowSceneLight* l2, ShadowSceneLight* l3);
    };
};
struct Shader_00bd9540
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
    BSShaderProperty::ShaderPassList* pPasses;
    int FUN_00bd9540(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d);
};
struct ShaderPassBuilder : Shader_00bd9540
{
    int FUN_00b5f7e0(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, unsigned char, bool*, bool,
                     bool, bool, bool, bool, bool, bool, bool);
};
// Selects a shader pass index from the boolean flags and adds it to pPasses when type==1, otherwise increments *count; sets *out to false and returns 0.
// @fnv 0x00bdd520
// pdb: BSShaderPPLightingProperty::AddAmbDiffTexSpecular2Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, apSunlight, apPtLight, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abFacegenBlend, abMultitexture, abProjShadow, abParallax, abTreeBranch, abHair
int ShaderPassBuilder::FUN_00b5f7e0(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                    unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c,
                                    bool d, bool e, bool f, bool g, bool h)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xac, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xb7, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xb0, true, 1, light0, 0, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xbb, true, 1, light0, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geometry, 0xab, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geometry, 0xad, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geometry, 0xb5, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geometry, 0xb6, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->FUN_00b2c0b0(geometry, 0xb8, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->FUN_00b2c0b0(geometry, 0xc0, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xaf, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xba, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xb2, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geometry, 0xbd, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (!h)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xb1, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xb3, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
                else
                {
                    if (!h)
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xbc, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->FUN_00b2c0b0(geometry, 0xbe, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}


}
}   // namespace f3m_00b5f7e0

// @f3 0x00b5fce0 (community match, verified in this file)
namespace f3m_00b5fce0 {
namespace f3_0248 {
struct NiGeometry;
struct ShadowSceneLight;
struct PassArray
{
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderPassSelector
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
    PassArray* pPasses;
    int FUN_00b5fce0(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1, unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c, bool d, bool e);
};
// @fnv 0x00bdda20
// pdb: BSShaderPPLightingProperty::AddDiffusePt2Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apGeom, apPtLight1, apPtLight2, asCount, abUpdateList, abFirst, abSkinned, abFacegenBlend, abMultitexture, abParallax, abTreeBranch
int ShaderPassSelector::FUN_00b5fce0(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                     unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c,
                                     bool d, bool e)
{
    if (!a)
    {
        if (!b)
        {
            if (!d)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x132, *out, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x137, *out, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (type == 1)
                {
                    ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x134, *out, 2, light0, light1, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x133, *out, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    else
    {
        if (!b)
        {
            if (!d)
            {
                if (type == 1)
                {
                    ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x135, *out, 2, light0, light1, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x136, *out, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    *out = false;
    return 0;
}

}
}   // namespace f3m_00b5fce0

// @f3 0x00b5f310 (community match, verified in this file)
namespace f3m_00b5f310 {
class NiGeometry;
class ShadowSceneLight;
struct Passes
{
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                      ShadowSceneLight*, ShadowSceneLight*);
};
struct Shader
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
    Passes* passes;
    int FUN_00b5f310(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);
};
// @fnv 0x00bdd050
// pdb: BSShaderPPLightingProperty::AddAmbDiffTexSpecularPass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abFacegenBlend, abMultitexture, abProjShadow, abParallax, abTreeBranch, abHair
int Shader::FUN_00b5f310(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                         bool* out, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0x96, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0xa1, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0x9a, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0xa5, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00b2c0b0(geom, 0x95, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                            else
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00b2c0b0(geom, 0x97, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                        }
                        else
                        {
                            if (type == 1)
                            {
                                passes->FUN_00b2c0b0(geom, 0x9f, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                    }
                    else
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00b2c0b0(geom, 0xa0, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                            else
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00b2c0b0(geom, 0xa2, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                        }
                        else
                        {
                            if (type == 1)
                            {
                                passes->FUN_00b2c0b0(geom, 0xaa, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0x99, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0xa4, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 0x9c, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 0xa7, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
        }
        else
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (!h)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0x9b, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0x9d, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!h)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0xa6, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 0xa8, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}
}   // namespace f3m_00b5f310

// @f3 0x00b583a0 (community match, verified in this file)
namespace f3m_00b583a0 {
namespace task0250 {
void* __cdecl FUN_0089eb90(unsigned int size);
class FUN_00886f30
{
  public:
    virtual ~FUN_00886f30();
    virtual void DeleteThis();
    long m_uiRefCount;
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

    FUN_00886f30(void* pkD3DDevice, int eType);
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p);

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

void __cdecl FUN_00b35120(FUN_00886f30* map, int count);

struct Shader0250
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pD3DDevice;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NiPointer<FUN_00886f30> m_spFirstShaderConstantMap;
    NiPointer<FUN_00886f30> m_spSecondShaderConstantMap;
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
    NiPointer<FUN_00886f30> m_spCurrPixelConstantMap;
    NiPointer<FUN_00886f30> m_spCurrVertexConstantMap;

    void FUN_00b583a0();
};

// @fnv 0x00bd4d30
void Shader0250::FUN_00b583a0()
{
    if (m_spSecondShaderConstantMap == 0)
        m_spSecondShaderConstantMap = new FUN_00886f30(m_pD3DDevice, 0);
    if (m_spFirstShaderConstantMap == 0)
        m_spFirstShaderConstantMap = new FUN_00886f30(m_pD3DDevice, 2);
    m_spCurrPixelConstantMap = m_spFirstShaderConstantMap;
    m_spCurrVertexConstantMap = m_spSecondShaderConstantMap;
    FUN_00b35120(m_spSecondShaderConstantMap, 0x2a);
}


}
}   // namespace f3m_00b583a0

// @f3 0x00b45d40 (community match, verified in this file)
namespace f3_0227 {
struct Heap0227 { void* FUN_0086b930(unsigned int); };
extern Heap0227 DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Ref
{
    virtual void unused();
    virtual void release();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            release();
    }
};
template <class T> struct Ptr
{
    T* p;
    Ptr() : p(0)
    {}
    ~Ptr()
    {
        if (p)
            p->DecRefCount();
    }
    void operator=(const Ptr& q)
    {
        T* old = p;
        if (old != q.p)
        {
            if (old)
                old->DecRefCount();
            p = q.p;
            if (p)
                p->IncRefCount();
        }
    }
    void operator=(T* q)
    {
        T* old = p;
        if (old != q)
        {
            if (old)
                old->DecRefCount();
            p = q;
            if (p)
                p->IncRefCount();
        }
    }
    operator T*() const
    {
        return p;
    }
    T* operator->() const
    {
        return p;
    }
};
struct Vec
{
    float x, y, z, w;
    static void* operator new[](unsigned n)
    {
        return DAT_01090a78.FUN_0086b930(n);
    }
};
struct IntElement
{
    void* value;
    static void* operator new[](unsigned n)
    {
        return DAT_01090a78.FUN_0086b930(n);
    }
};
struct FUN_00ad3a50
{
    int a, b, c;
    FUN_00ad3a50();
};
struct Source : Ref
{
    int data;
    unsigned char mode;
    int indices;
    int multiplier;
    Ptr<Ref> texture;
    Ref* prop1;
    Ref* prop2;
    Ref* prop3;
    int unk28;
    unsigned int count;
    bool flag;
};
struct FUN_00b28610
{
    FUN_00b28610(int, bool);
    static void* operator new(unsigned size)
    {
        return FUN_0089eb90(size);
    }
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28;
    void FUN_0083d070(bool);
    void FUN_0083cf80(int, int, unsigned, int);
    void FUN_0083ca40(int, int, int, int, int, int, int);
};
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
    FUN_00b28610* program;
    void FUN_00831580(FUN_00b28610*);
};
struct Geometry : Ref
{
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
    Owner* owner;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    static void* operator new(unsigned size)
    {
        return FUN_0089eb90(size);
    }
    void FUN_004236f0(Ref*);
};
struct FUN_00b8e660 : Geometry
{
    FUN_00b8e660(int);
};
struct FUN_00b8e870 : Geometry
{
    FUN_00b8e870(int);
};
struct FUN_00ad3a80 : Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned flags20, flags24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    void* volatile dirty;
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
    void* parent;
    Ptr<Ref> texture;
    int unk84, unk88;
    FUN_00ad3a80();
    static void* operator new(unsigned size)
    {
        return FUN_0089eb90(size);
    }
};
extern int DAT_0116efb0;
void __cdecl FUN_00ade300(Geometry*, int, int);
struct FUN_00b45d40
{
    Ptr<Geometry> geometry;
    Ptr<Source> source;
    Ptr<FUN_00ad3a80> property;
    unsigned short capacity, count;
    Vec* values;
    IntElement* indices;
    FUN_00ad3a50 member;
    int arg;
    FUN_00b45d40(Source*, int, bool);
    void FUN_00b459e0();
};
// @fnv 0x00bd6190
// pdb: DistantLODGroup::DistantLODGroup | DistantLODGroup.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apCachedGeometry, aiCellChunk, abLowDetail
FUN_00b45d40::FUN_00b45d40(Source* src, int argValue, bool flag)
{
    capacity = src->count;
    source = src;
    arg = argValue;
    values = new Vec[capacity];
    indices = new IntElement[capacity];
    for (int index = 0; index < capacity; ++index)
    {
        values[index].x = 0;
        values[index].y = 0;
        values[index].z = 0;
        values[index].w = 0;
        indices[index].value = 0;
    }
    count = capacity;
    for (int index = 0; index < count; ++index)
    {
        values[index].z = 0;
        values[index].w = 0;
        indices[index].value = 0;
    }
    count = 0;
    FUN_00b459e0();
    geometry = (Geometry*)0;
    int data = src->data;
    if (src->mode == 1)
        geometry = new FUN_00b8e660(data);
    else
        geometry = new FUN_00b8e870(data);
    Ref* prop = DAT_0116efb0 < 2 ? src->prop2 : src->prop1;
    if (prop)
        geometry->FUN_004236f0(prop);
    if (src->prop3)
        geometry->FUN_004236f0(src->prop3);
    FUN_00ad3a80* shader = new FUN_00ad3a80;
    shader->texture = src->texture;
    shader->parent = this;
    if (flag)
    {
        if (!(shader->flags20 & 4))
            shader->dirty = 0;
        shader->flags20 |= 4;
    }
    else
    {
        if (shader->flags20 & 4)
            shader->dirty = 0;
        shader->flags20 &= ~4;
    }
    if (src->flag)
    {
        if (!(shader->flags24 & 0x2000))
            shader->dirty = 0;
        shader->flags24 |= 0x2000;
    }
    else
    {
        if (shader->flags24 & 0x2000)
            shader->dirty = 0;
        shader->flags24 &= ~0x2000;
    }
    geometry->FUN_004236f0(shader);
    property = shader;
    FUN_00ade300(geometry, 0, 0);
    Owner* owner = geometry->owner;
    if (!owner || !owner->program)
    {
        int total = src->multiplier * src->count;
        FUN_00b28610* program = new FUN_00b28610(total, true);
        program->FUN_0083d070(true);
        program->FUN_0083cf80(0, src->indices, total * 4, 0);
        program->FUN_0083ca40(0, 0, 0, 1, total, 4, 4);
        geometry->owner->FUN_00831580(program);
    }
}

}

// @f3 0x00b5a2a0 (community match, verified in this file)
namespace f3m_00b5a2a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObj_bd74a0
{
    virtual void v00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};

struct FUN_00839f80
{
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    virtual ~FUN_00839f80();
};

struct FUN_00b5a2a0 : FUN_00839f80
{
    NiPointer<RefObj_bd74a0> m_spArr[6];
    NiPointer<RefObj_bd74a0> m_sp130;
    int unk134;
    NiPointer<RefObj_bd74a0> m_sp138;
    NiPointer<RefObj_bd74a0> m_sp13c;
    virtual ~FUN_00b5a2a0();
};

// @fnv 0x00bd74a0
FUN_00b5a2a0::~FUN_00b5a2a0()
{
    for (int i = 0; i < 6; i++)
        m_spArr[i] = 0;
    m_sp130 = 0;
    m_sp13c = 0;
}
}   // namespace f3m_00b5a2a0

// @f3 0x00b5ba60 (community match, verified in this file)
namespace f3m_00b5ba60 {
namespace task0256 {
struct NiGeometry;
struct ShadowSceneLight;
struct PassArray9840
{
    void __thiscall FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                                 ShadowSceneLight*, ShadowSceneLight*);
};
struct Shader9840
{
    void* field00;
    void* field04;
    void* field08;
    void* field0c;
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void* field24;
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    PassArray9840* passes;
    int __thiscall FUN_00b5ba60(NiGeometry*, ShadowSceneLight*, unsigned short*, unsigned char, bool&, bool, bool, bool,
                                bool);
};
// Chooses a pass index from the boolean flags and type, calls the pass array for type 1 or increments count otherwise, then clears out and returns 0.
// @fnv 0x00bd9840
// pdb: BSShaderPPLightingProperty::AddDiffusePass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apLight, asCount, abUpdateList, abFirst, abSkinned, abPointLight, abMultitexture, abTreeBranch
int Shader9840::FUN_00b5ba60(NiGeometry* geometry, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                             bool& out, bool a, bool b, bool c, bool d)
{
    if (!a)
    {
        if (!b)
        {
            if (!d)
            {
                if (type == 1)
                {
                    passes->FUN_00b2c0b0(geometry, 300, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
            else
            {
                if (type == 1)
                {
                    passes->FUN_00b2c0b0(geometry, 304, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (!d)
            {
                if (type == 1)
                {
                    passes->FUN_00b2c0b0(geometry, 301, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
            else
            {
                if (type == 1)
                {
                    passes->FUN_00b2c0b0(geometry, 305, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
    }
    else
    {
        if (!b)
        {
            if (type == 1)
            {
                passes->FUN_00b2c0b0(geometry, 302, out, 1, light, 0, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
        else
        {
            if (type == 1)
            {
                passes->FUN_00b2c0b0(geometry, 303, out, 1, light, 0, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    out = false;
    return 0;
}


}
}   // namespace f3m_00b5ba60

// @f3 0x00b47b50 (community match, verified in this file)
namespace fo3_b47b50 {
struct StrArray
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
    unsigned int Add(char* item)
    {
        unsigned int idx = m_usSize;
        if (idx >= m_usMaxSize)
            FUN_00555790(idx + m_usGrowBy);
        FUN_005b3880(idx, item);
        return idx;
    }
};
struct NiTexture;
struct TexPtr
{
    NiTexture* m_pObject;
    operator NiTexture*() const
    {
        return m_pObject;
    }
};
struct DebugStrGlobal
{
    char* pData;
};
extern DebugStrGlobal DAT_01177d54;
char* __cdecl FUN_00847b50(char*);
char* __cdecl FUN_00847e20(const char*, void*);
char* __cdecl FUN_00847b90(const char*, bool);

struct ShaderBase_00b690d0
{
    void FUN_00aec6a0(StrArray* arr);
};
struct TerrainShader : ShaderBase_00b690d0
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
    unsigned int flags24;
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
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    TexPtr m_kTerrainTexture;
    bool GetFlag(unsigned int mask)
    {
        return (flags24 & mask) > 0;
    }
    void FUN_00b47b50(StrArray* arr);
};

// Appends base debug info plus height map, light flags and point-light status strings to arr.
// @fnv 0x00bc4460
// pdb: HairShaderProperty::GetViewerStrings | HairShaderProperty.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: BSLightingShaderMaterialMultiLayerParallax::ComputeCRC32)
// pdb params: apStrings
void TerrainShader::FUN_00b47b50(StrArray* arr)
{
    FUN_00aec6a0(arr);
    arr->Add(FUN_00847b50(DAT_01177d54.pData));
    arr->Add(FUN_00847e20("height map", m_kTerrainTexture));
    arr->Add(FUN_00847b90("primary light is point", GetFlag(0x80)));
    arr->Add(FUN_00847b90("second light", GetFlag(0x100)));
    arr->Add(FUN_00847b90("third light", GetFlag(0x200)));
}


}

// @f3 0x00b42d20 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" void* __cdecl FUN_00c00610(void*,int,unsigned int);
struct RGBWords { unsigned int r,g,b; };
extern RGBWords DAT_00f73220;
extern int DAT_0116efb0;
extern unsigned int DAT_01177cd0;
struct Bd9120Allocator { void* FUN_0086b930(unsigned int); };
extern Bd9120Allocator DAT_01090a78;
struct CountedRef
{
    virtual void unused();
    virtual void Release();
    long references;
};
struct PassView
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
    int references;
    void FUN_00888c10();
};
struct PassPtr
{
    PassView* ptr;
    PassPtr() : ptr(0)
    {}
    ~PassPtr()
    {
        if (ptr && --ptr->references == 0)
            ptr->FUN_00888c10();
    }
    void clear()
    {
        PassView* old = ptr;
        if (old)
        {
            if (--old->references == 0)
                old->FUN_00888c10();
            ptr = 0;
        }
    }
};
struct RefPtr
{
    CountedRef* ptr;
    RefPtr() : ptr(0)
    {}
    ~RefPtr()
    {
        if (ptr && InterlockedDecrement(&ptr->references) == 0)
            ptr->Release();
    }
    void assign(CountedRef* value)
    {
        CountedRef* old = ptr;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->references) == 0)
                old->Release();
            ptr = value;
            if (value)
                InterlockedIncrement(&value->references);
        }
    }
    void clear()
    {
        CountedRef* old = ptr;
        if (old)
        {
            if (InterlockedDecrement(&old->references) == 0)
                old->Release();
            ptr = 0;
        }
    }
};
struct FUN_00b64170
{
    virtual ~FUN_00b64170();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char flag24;
    RefPtr source;
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
    int mode;
    int flags;
    float value;
    float matrix[16];
    FUN_00b64170();
};
namespace f3_00b42d20 {
extern "C" double __cdecl FUN_00c03f30(double);

struct Vec2A
{
    float x, y;
    Vec2A() : x(0.0f), y(0.0f)
    {}
    Vec2A(float _x, float _y) : x(_x), y(_y)
    {}
};

struct Color4A
{
    float r, g, b, a;
    Color4A() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
    Color4A(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a)
    {}
};

struct BoltAllocElem
{
    float x, y, z, w;
    static void* operator new[](unsigned int bytes)
    {
        return DAT_01090a78.FUN_0086b930(bytes);
    }
};

struct FUN_00b42d20 : FUN_00b64170
{
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
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    Vec2A pt1;
    Vec2A pt2;
    int unk128;
    int unk12C;
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
    int unk160;
    int unk164;
    PassPtr pass;
    float f16C;
    float f170;
    float f174;
    float f178;
    float f17C;
    float f180;
    float f184;
    float f188;
    RefPtr first;
    RefPtr second;

    FUN_00b42d20(CountedRef* source);
    virtual ~FUN_00b42d20();
};

// @fnv 0x00bc0c90
// pdb: BoltShader::BoltShader | BoltShader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apShaderDecl
FUN_00b42d20::FUN_00b42d20(CountedRef* apSource)
    : FUN_00b64170(), pt1(), pt2(), pass(), f16C(0.0f), f170(0.0f), f174(0.0f), f178(0.0f), f17C(0.0f), f180(0.0f),
      f184(0.0f), f188(0.0f), first(), second()
{
    mode = 0xf;
    flag24 = 1;
    flags = 0x242;
    pass.clear();
    source.assign(apSource);
    first.clear();
    second.clear();

    matrix[0] = 0.0f;
    *(Color4A*)&pt1 = Color4A(0.0f, 0.0f, 0.0f, 0.0f);
    *(Color4A*)&f16C = *(Color4A*)&DAT_00f73220;
    *(Color4A*)&f17C = *(Color4A*)&DAT_00f73220;

    if (!DAT_01177cd0)
    {
        DAT_01177cd0 = (DAT_0116efb0 < 2 ? 0 : 0xa0) + 0x4b;
    }
    float fVal = (float)DAT_01177cd0 * 0.25;
    unsigned int count = (unsigned int)(float)FUN_00c03f30(fVal);
    count *= 4;
    BoltAllocElem* p = new BoltAllocElem[count];
    *(void**)&value = p;
    FUN_00c00610(p, 0, count * sizeof(BoltAllocElem));
    FUN_00c00610(&unk128, 0, 0x40);
    FUN_00c00610(&matrix[1], 0, 0xa0);
}

}

// @f3 0x00b42a40 (community match, verified in this file)
namespace f3m_00b42a40 {
namespace fo3_b42a40 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObject { virtual void Unused() = 0; virtual void Release() = 0; long m_iObjectReferenceCount; };
void* __cdecl FUN_00c00610(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, int, const char*, ...);
const char* __cdecl FUN_00ad5850(bool);
struct BeamDesc
{
    const char* file;
    unsigned int count;
    unsigned int flags;
    char arguments[64];
    BeamDesc(const char* name) : file(name), count(0), flags(0)
    {
        FUN_00c00610(arguments, 0, 64);
    }
};
struct BeamPtr
{
    RefObject* ptr;
    void Assign(RefObject* p)
    {
        RefObject* old = ptr;
        if (old != p)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            ptr = p;
            if (p)
                InterlockedIncrement(&p->m_iObjectReferenceCount);
        }
    }
};
struct TargetBeam
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
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    BeamPtr vertex;
    BeamPtr pixel;
    RefObject* FUN_00b62f60(const char*, unsigned int*, const char*, const char*);
    RefObject* FUN_00b636d0(const char*, unsigned int*, const char*, const char*);
    void FUN_00b42a40();
};
// Builds source and binary paths for the beam vertex and pixel shaders and assigns the compiled shader objects to vertex and pixel.
// @fnv 0x00bc4680
// pdb: BoltShader::LoadShaders | BoltShader.obj | fnv360_0822_retail, ustr, medium
void TargetBeam::FUN_00b42a40()
{
    BeamDesc vertexDesc("bolt\\v\\bolt.v.hlsl");
    char sourcePath[260];
    char binaryPath[260];
    FUN_00b62b90(vertexDesc.file, sourcePath);
    FUN_00403230(binaryPath, 260, "BOLT.vso");
    vertex.Assign(FUN_00b62f60(sourcePath, &vertexDesc.count, "vs_1_1", binaryPath));
    const char* profile = FUN_00ad5850(true);
    BeamDesc pixelDesc("bolt\\p\\bolt.p.hlsl");
    FUN_00b62b90(pixelDesc.file, sourcePath);
    FUN_00403230(binaryPath, 260, "BOLT.pso");
    pixel.Assign(FUN_00b636d0(sourcePath, &pixelDesc.count, profile, binaryPath));
}

}
}   // namespace f3m_00b42a40

// @f3 0x00b5b090 (community match, verified in this file)
extern float DAT_00db97e0;
namespace f3m_00b5b090 {
namespace task0239 {
void* __cdecl FUN_0089eb90(unsigned int);
struct RefObj_bd74a0
{
    virtual void v00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};

struct FUN_0083bf50
{
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;

    FUN_0083bf50(bool bOrtho);
};

extern "C" double __cdecl tan(double);
inline float tanf(float _X)
{
    return (float)tan((double)_X);
}


class FUN_0083b6d0
{
  public:
    FUN_0083b6d0();
    virtual ~FUN_0083b6d0();

    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    FUN_0083bf50 m_kViewFrustum;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;

    void UpdateViewFrustum(const FUN_0083bf50& kFrustum)
    {
        m_kViewFrustum = kFrustum;
    }
};

struct BSShaderManager
{
    enum BATCHRENDERER_CREATION_MODE
    {
        BRCM_DEFAULT
    };
};

class FUN_00ae9090 : public RefObj_bd74a0
{
  public:
    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* pvMem);
    FUN_00ae9090(BSShaderManager::BATCHRENDERER_CREATION_MODE eMode, unsigned int uiA, unsigned int uiB);

    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
};

class FUN_00b5b090 : public FUN_0083b6d0
{
  public:
    int m_114;
    NiPointer<RefObj_bd74a0> m_spArr[6];
    NiPointer<RefObj_bd74a0> m_sp130;
    int m_134;
    NiPointer<RefObj_bd74a0> m_sp138;
    NiPointer<RefObj_bd74a0> m_sp13c;

    FUN_00b5b090(int iArg);
    virtual ~FUN_00b5b090();
};

// Stores iArg in m_114, nulls m_spArr/m_sp130/m_sp138, sets a tan(pi/4) perspective frustum via UpdateViewFrustum, and creates a FUN_00ae9090 in m_sp13c.
// @fnv 0x00bd8290
// pdb: BSCubeMapCamera::BSCubeMapCamera | BSCubeMapCamera.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aecubemaptype
FUN_00b5b090::FUN_00b5b090(int iArg)
{
    m_114 = iArg;
    for (int i = 0; i < 6; i++)
    {
        m_spArr[i] = 0;
    }
    m_sp130 = 0;
    m_sp138 = 0;

    FUN_0083bf50 kFrustum(false);
    kFrustum.m_bOrthographic = false;
    double dTan = tanf(0.7853982f);
    float fTan = (float)dTan;
    kFrustum.m_fLeftBound = -fTan;
    kFrustum.m_fRightBound = fTan;
    kFrustum.m_fTopBound = fTan;
    kFrustum.m_fBottomBound = -fTan;
    kFrustum.m_fNearPlane = 1.0f;
    kFrustum.m_fFarPlane = DAT_00db97e0;
    UpdateViewFrustum(kFrustum);

    m_sp13c = new FUN_00ae9090((BSShaderManager::BATCHRENDERER_CREATION_MODE)0x63, 1, 0x2f7);
}

}
}   // namespace f3m_00b5b090

// @f3 0x00b54160 (community match, verified in this file)
extern int DAT_01172d08;
extern int DAT_01172d04;
extern int DAT_01172124;
extern int DAT_01172128;
namespace f3m_00b54160 {
namespace f3_00b54160 {
struct StageReturn
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
    int m_iObjectReferenceCount;
    void FUN_0088fe30();
    void DecRef()
    {
        if (--m_iObjectReferenceCount == 0)
            FUN_0088fe30();
    }
};

struct StageReturnPtr
{
    StageReturn* m_p;
    StageReturnPtr() : m_p(0)
    {}
    operator StageReturn*() const
    {
        return m_p;
    }
    ~StageReturnPtr()
    {
        if (m_p)
            m_p->DecRef();
    }
};

void __cdecl FUN_0088ff50(StageReturnPtr& out);
struct ShaderPassOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_pDirectInputDevice;
    void FUN_00888d30(void* list, StageReturn* stage);
};

struct ShaderPassOwnerPtr
{
    ShaderPassOwner* m_p;
    ShaderPassOwner* operator->() const
    {
        return m_p;
    }
};
void __cdecl FUN_00888f80(ShaderPassOwnerPtr& owner);
void __cdecl FUN_00b62c70(StageReturn* pass, int index, int a, int b, int c);

int __cdecl FUN_0048f8f0(int arg);


struct ShaderBase
{
    virtual void Initialize();
};

struct FUN_00b54160_class : ShaderBase
{
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
    ShaderPassOwnerPtr m_spOwners[2];

    bool FUN_00b54160();
};

// @fnv 0x00bd0ae0
// pdb: HairShader::LoadStagesAndPasses | HairShader.obj | fnv360_0822_retail, objrun, medium
bool FUN_00b54160_class::FUN_00b54160()
{
    for (int i = 0; i < 2; i++)
    {
        FUN_00888f80(m_spOwners[i]);
        StageReturnPtr spRenderPass;

        FUN_0088ff50(spRenderPass);
        FUN_00b62c70(spRenderPass.m_p, 0, 1, 2, 1);
        m_spOwners[i]->FUN_00888d30(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        FUN_0088ff50(spRenderPass);
        FUN_00b62c70(spRenderPass.m_p, 1, 1, 2, 1);
        m_spOwners[i]->FUN_00888d30(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        FUN_0088ff50(spRenderPass);
        FUN_00b62c70(spRenderPass.m_p, 2, 1, 2, 1);
        m_spOwners[i]->FUN_00888d30(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        FUN_0088ff50(spRenderPass);
        FUN_00b62c70(spRenderPass.m_p, 3, 3, 2, 1);
        m_spOwners[i]->FUN_00888d30(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        FUN_0088ff50(spRenderPass);
        FUN_00b62c70(spRenderPass.m_p, 4, 1, 2, 1);
        m_spOwners[i]->FUN_00888d30(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        if (FUN_0048f8f0(0) >= 2)
        {
            FUN_0088ff50(spRenderPass);
            FUN_00b62c70(spRenderPass.m_p, 5, 3, 2, 1);
            m_spOwners[i]->FUN_00888d30(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);
        }
    }
    DAT_01172d08 = DAT_01172d04 = 0x482;
    DAT_01172124 = 0x2c;
    DAT_01172128 = 0x3c;
    return true;
}

}
}   // namespace f3m_00b54160

// @f3 0x00b472a0 (community match, verified in this file)
namespace fo3_b472a0 {
extern "C" void _ReadWriteBarrier();

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct EffectRef
{
    virtual ~EffectRef();
    virtual void DeleteThis();
    volatile long count;
};
template <bool Ordered> struct EffectPtr
{
    EffectRef* value;
    EffectPtr()
    {
        if (Ordered)
            _ReadWriteBarrier();
        value = 0;
    }
    ~EffectPtr()
    {
        if (value && !InterlockedDecrement(&value->count))
            value->DeleteThis();
    }
    EffectPtr& operator=(EffectRef* other)
    {
        EffectRef* previous = value;
        if (previous != other)
        {
            if (previous && !InterlockedDecrement(&previous->count))
                previous->DeleteThis();
            value = other;
        }
        return *this;
    }
};
struct EffectVector
{
    float x, y, z;
};
extern EffectVector DAT_0108ec68;
struct EffectQuad
{
    float x, y, z, w;
    EffectQuad() : x(0), y(0), z(0), w(0)
    {}
};
struct FUN_00aea2f0
{
    virtual ~FUN_00aea2f0();
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    FUN_00aea2f0();
};
struct FUN_00b472a0 : FUN_00aea2f0
{
    EffectPtr<false> first, second;
    EffectVector a, b, c;
    volatile float d, e, f;
    EffectQuad q0, q1, q2, RunFourthVirtual;
    EffectPtr<true> third;
    FUN_00b472a0();
    virtual ~FUN_00b472a0();
};
// Constructor: clears the effect pointers, initialises three vectors from DAT_0108ec68, zeroes the floats, and sets unk1c to 9.
// @fnv 0x00bc3bb0
// pdb: HairShaderProperty::HairShaderProperty | HairShaderProperty.obj | fnv360_0822_retail, objrun, medium
FUN_00b472a0::FUN_00b472a0()
{
    third = 0;
    first = 0;
    second = 0;
    a = DAT_0108ec68;
    d = 0.0f;
    b = DAT_0108ec68;
    e = 0.0f;
    c = DAT_0108ec68;
    f = 0.0f;
    unk1c = 8;
}

}

// @f3 0x00b47d60 (community match, verified in this file)
namespace f3m_00b47d60 {
namespace f3_0255 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObject
{
    virtual void Unused() = 0;
    virtual void Release() = 0;

    long m_iObjectReferenceCount;
};
void* __cdecl FUN_00c00610(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, int, const char*, ...);
const char* __cdecl FUN_00ad5850(bool);
struct BeamDesc
{
    const char* file;
    unsigned int count;
    unsigned int flags;
    char arguments[64];
    BeamDesc(const char* name) : file(name), count(0), flags(0)
    {
        FUN_00c00610(arguments, 0, 64);
    }
};
struct BeamPtr
{
    RefObject* ptr;
    void Assign(RefObject* p)
    {
        RefObject* old = ptr;
        if (old != p)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            ptr = p;
            if (p)
                InterlockedIncrement(&p->m_iObjectReferenceCount);
        }
    }
};
struct TargetBeam
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
    BeamPtr vertex;
    BeamPtr pixel;
    RefObject* FUN_00b62f60(const char*, unsigned int*, const char*, const char*);
    RefObject* FUN_00b636d0(const char*, unsigned int*, const char*, const char*);
    void FUN_00b47d60();
};
// @fnv 0x00bc4680
// pdb: BeamShader::LoadShaders | BeamShader.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: BSLightingShaderMaterialMultiLayerParallax::GetTextures)
void TargetBeam::FUN_00b47d60()
{
    BeamDesc vertexDesc("beam\\v\\beam.v.hlsl");
    char sourcePath[260];
    char binaryPath[260];
    FUN_00b62b90(vertexDesc.file, sourcePath);
    FUN_00403230(binaryPath, 260, "BEAM.vso");
    vertex.Assign(FUN_00b62f60(sourcePath, &vertexDesc.count, "vs_1_1", binaryPath));
    const char* profile = FUN_00ad5850(true);
    BeamDesc pixelDesc("beam\\p\\beam.p.hlsl");
    FUN_00b62b90(pixelDesc.file, sourcePath);
    FUN_00403230(binaryPath, 260, "BEAM.pso");
    pixel.Assign(FUN_00b636d0(sourcePath, &pixelDesc.count, profile, binaryPath));
}

}
}   // namespace f3m_00b47d60

// @f3 0x00b46120 (community match, verified in this file)
namespace task0267 {
struct MM { void FUN_0086ba60(void*); };
extern MM DAT_01090a78;
struct CallbackOwner;
struct ReleaseCallback
{
    virtual void Method00();
    virtual void Method01();
    virtual void Method02();
    virtual void Method03();
    virtual void Method04();
    virtual void Method05();
    virtual void Method06();
    virtual void Method07();
    virtual void Method08();
    virtual void Method09();
    virtual void Method10();
    virtual void Method11();
    virtual void Method12();
    virtual void Method13();
    virtual void Method14();
    virtual void Method15();
    virtual void Method16();
    virtual void Method17();
    virtual void Method18();
    virtual void Method19();
    virtual void Method20();
    virtual void Method21();
    virtual void Method22();
    virtual void Method23();
    virtual void Method24();
    virtual void Method25();
    virtual void Method26();
    virtual void Method27();
    virtual void Method28();
    virtual void Method29();
    virtual void Method30();
    virtual void Method31();
    virtual void Method32();
    virtual void Method33();
    virtual void Method34();
    virtual void Method35();
    virtual void Method36();
    virtual void Method37();
    virtual void Method38();
    virtual void Method39();
    virtual void Method40();
    virtual void Method41();
    virtual void Method42();
    virtual void Method43();
    virtual void Method44();
    virtual void Method45();
    virtual void Method46();
    virtual void Method47();
    virtual void Method48();
    virtual void Method49();
    virtual void Method50();
    virtual void Method51();
    virtual void Method52();
    virtual void Method53();
    virtual void Method54();
    virtual void Method55();
    virtual void Method56();
    virtual void Method57();
    virtual void OnDetach(CallbackOwner* owner);
};

struct CallbackOwner
{
    virtual void Unused();
    virtual void Release();
    volatile long referenceCount;
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    void* unknown14;
    ReleaseCallback* callback;
    void DecrementReference()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};

struct ObjectReference
{
    CallbackOwner* object;
    void Reset()
    {
        if (object)
        {
            object->DecrementReference();
            object = 0;
        }
    }
    ~ObjectReference()
    {
        if (object)
            object->DecrementReference();
    }
};

struct FUN_00b46120
{
    ObjectReference owner;
    ObjectReference other;
    ObjectReference additional;
    void* unknown0c;
    void* allocation10;
    void* allocation14;
    void FUN_00b45cf0();
    ~FUN_00b46120();
};
// Releases the three object references, detaches the owner's callback, frees allocation10 and allocation14, and calls FUN_00b45cf0.
// @fnv 0x00bd6570
// pdb: DistantLODGroup::~DistantLODGroup | DistantLODGroup.obj | fnv360_0822_retail, call_seq, medium
FUN_00b46120::~FUN_00b46120()
{
    additional.Reset();
    other.Reset();
    if (owner.object->callback)
        owner.object->callback->OnDetach(owner.object);
    owner.Reset();
    FUN_00b45cf0();
    if (allocation10)
    {
        DAT_01090a78.FUN_0086ba60(allocation10);
        allocation10 = 0;
    }
    {
        void* buffer = allocation14;
        DAT_01090a78.FUN_0086ba60(buffer);
    }
    allocation14 = 0;
}

}

// @f3 0x00b48860 (community match, verified in this file)
extern bool DAT_01067b4e;
namespace f3m_00b48860 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObject
{
    virtual void Unused() = 0;
    virtual void Release() = 0;

    long m_iObjectReferenceCount;
};

struct BeamPtr
{
    RefObject* ptr;
    void Assign(RefObject* p)
    {
        RefObject* old = ptr;
        if (old != p)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            ptr = p;
            if (p)
                InterlockedIncrement(&p->m_iObjectReferenceCount);
        }
    }
};
extern "C" void* __cdecl FUN_00c00610(void*, int, unsigned int);
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, int, const char*, ...);

struct ShaderMacro
{
    const char* Name;
    const char* Definition;
};

struct FogShaderDesc
{
    const char* filename;
    ShaderMacro macros[9];
};

struct VolumetricFog
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
    BeamPtr pixelShaders[2];

    RefObject* FUN_00b636d0(const char*, unsigned int*, const char*, const char*);
    void FUN_00b48860();
};

// @fnv 0x00bc51a0
// pdb: VolumetricFogShader::LoadPixelShaders | VolumetricFogShader.obj | fnv360_0822_retail, ustr, medium
void VolumetricFog::FUN_00b48860()
{
    const char* shaderTargets[2];
    shaderTargets[0] = "ps_2_a";
    shaderTargets[1] = "ps_3_0";

    FogShaderDesc shaderDescs[2];
    shaderDescs[0].filename = "vfog\\VolumetricFog.p.hlsl";
    shaderDescs[0].macros[0].Name = 0;
    FUN_00c00610(&shaderDescs[0].macros[0].Definition, 0, 0x44);

    shaderDescs[1].filename = "vfog\\VolumetricFog.p.hlsl";
    shaderDescs[1].macros[0].Name = "SINGLE_PASS";
    shaderDescs[1].macros[0].Definition = "";
    shaderDescs[1].macros[1].Name = 0;
    FUN_00c00610(&shaderDescs[1].macros[1].Definition, 0, 0x3c);

    for (int i = 0; i < 2; ++i)
    {
        if (i == 1 && !DAT_01067b4e)
            continue;

        char szFullPath[260];
        FUN_00b62b90(shaderDescs[i].filename, szFullPath);

        char szShaderName[260];
        FUN_00403230(szShaderName, 260, "VolumetricFog%03d.pso", i);

        RefObject* pShader =
            FUN_00b636d0(szFullPath, (unsigned int*)shaderDescs[i].macros, shaderTargets[i], szShaderName);
        pixelShaders[i].Assign(pShader);
    }
}
}   // namespace f3m_00b48860

// @f3 0x00b54940 (community match, verified in this file)
namespace f3m_00b54940 {
namespace f3_0242 {
struct Ref_bd12c0
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct Pass_bd12c0
{
    void IncRefCount();
    void DecRefCount();
};
struct VShader_bd12c0
{
    void IncRefCount();
    void DecRefCount();
};
struct PShader_bd12c0
{
    void IncRefCount();
    void DecRefCount();
};

struct FUN_00afc480
{
    FUN_00afc480(Ref_bd12c0* a, Ref_bd12c0* b, int c, int d);
    virtual ~FUN_00afc480();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    NiPointer<Ref_bd12c0> m_sp28;
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
};

struct FUN_00b54940 : FUN_00afc480
{
    NiPointer<Pass_bd12c0> m_spPasses[2];
    NiPointer<VShader_bd12c0> m_spVS94[7];
    NiPointer<PShader_bd12c0> m_spPSb0[3];
    NiPointer<VShader_bd12c0> m_spVSbc[7];
    NiPointer<PShader_bd12c0> m_spPSd8[3];
    NiPointer<Ref_bd12c0> m_spe4;
    NiPointer<Ref_bd12c0> m_spe8;

    FUN_00b54940(Ref_bd12c0* a, Ref_bd12c0* b);
    virtual ~FUN_00b54940();
};

// @fnv 0x00bd12c0
// pdb: HairShader::HairShader | HairShader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apShaderDecl, apSkinnedShaderDecl
FUN_00b54940::FUN_00b54940(Ref_bd12c0* apRefA, Ref_bd12c0* apRefB) : FUN_00afc480(apRefA, apRefB, 0, 0)
{
    unk68 = 2;
    m_spe4 = apRefA;
    m_spe8 = apRefB;
    m_sp28 = (Ref_bd12c0*)m_spe8;
    unk60 = 0;
}

}
}   // namespace f3m_00b54940

// @f3 0x00b5fe80 (community match, verified in this file)
namespace f3m_00b5fe80 {
namespace fo3_b5fe80 {
struct NiGeometry; struct ShadowSceneLight;
struct PassList { void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*); };
struct Shader244 {
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
PassList* pPasses;
int FUN_00b5fe80(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                                     unsigned short* count, unsigned char type, bool* out, bool abFlagA, bool abFlagB,
                                     bool abFlagC, bool abFlagD, bool abFlagE);
};
// @fnv 0x00bddbc0
// pdb: BSShaderPPLightingProperty::AddDiffusePt3Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apPtLight1, apPtLight2, apPtLight3, asCount, abUpdateList, abFirst, abSkinned, abFacegenBlend, abMultitexture, abParallax, abTreeBranch
int Shader244::FUN_00b5fe80(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                                     unsigned short* count, unsigned char type, bool* out, bool abFlagA, bool abFlagB,
                                     bool abFlagC, bool abFlagD, bool abFlagE)
{
    if (!abFlagA)
    {
        if (!abFlagB)
        {
            if (!abFlagD)
            {
                if (!abFlagE)
                {
                    if (type == 1)
                    {
                        pPasses->FUN_00b2c0b0(geom, 0x13e, *out, 3, l0, l1, l2, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        pPasses->FUN_00b2c0b0(geom, 0x143, *out, 3, l0, l1, l2, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (type == 1)
                {
                    pPasses->FUN_00b2c0b0(geom, 0x140, *out, 3, l0, l1, l2, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->FUN_00b2c0b0(geom, 0x13f, *out, 3, l0, l1, l2, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    else
    {
        if (!abFlagB)
        {
            if (!abFlagD)
            {
                if (type == 1)
                {
                    pPasses->FUN_00b2c0b0(geom, 0x141, *out, 3, l0, l1, l2, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->FUN_00b2c0b0(geom, 0x142, *out, 3, l0, l1, l2, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    *out = false;
    return 0;
}

}
}   // namespace f3m_00b5fe80

// @f3 0x00b5a420 (community match, verified in this file)
extern void* DAT_0116f2f8;
namespace f3m_00b5a420 {
struct Renderer_bd7620;
struct Pt_bd7620
{
    float x, y, z;
};
struct Frustum_bd7620
{
    float l;
    float r;
    float t;
    float b;
    float n;
    float f;
    bool ortho;
};
struct Port_bd7620
{
    float l;
    float r;
    float t;
    float b;
};
struct UpdData_bd7620
{
    float fTime;
    bool b4;
    bool b5;
    bool b6;
    bool b7;
    bool b8;
    UpdData_bd7620(float t) : fTime(t), b4(false), b5(false), b6(false), b7(false), b8(false)
    {}
};
struct Renderer_bd7620
{
    virtual void rv00();
    virtual void rv01();
    virtual void rv02();
    virtual void rv03();
    virtual void rv04();
    virtual void rv05();
    virtual void rv06();
    virtual void rv07();
    virtual void rv08();
    virtual void rv09();
    virtual void rv10();
    virtual void rv11();
    virtual void rv12();
    virtual void rv13();
    virtual void rv14();
    virtual void rv15();
    virtual void rv16();
    virtual void rv17();
    virtual void rv18();
    virtual void rv19();
    virtual void rv20();
    virtual void rv21();
    virtual void rv22();
    virtual void rv23();
    virtual void rv24();
    virtual void rv25();
    virtual void rv26();
    virtual void rv27();
    virtual void rv28();
    virtual void rv29();
    virtual void rv30();
    virtual void rv31();
    virtual void rv32();
    virtual void rv33();
    virtual void rv34();
    virtual void rv35();
    virtual void rv36();
    virtual void rv37();
    virtual void rv38();
    virtual void rv39();
    virtual void rv40();
    virtual void rv41();
    virtual void rv42();
    virtual void rv43();
    virtual void rv44();
    virtual void rv45();
    virtual void rv46();
    virtual void rv47();
    virtual void rv48();
    virtual void rv49();
    virtual void rv50();
    virtual void rv51();
    virtual void rv52();
    virtual void rv53();
    virtual void rv54();
    virtual void rv55();
    virtual void rv56();
    virtual void rv57();
    virtual void rv58();
    virtual void rv59();
    virtual void rv60();
    virtual void rv61();
    virtual void rv62();
    virtual void rv63();
    virtual void rv64();
    virtual void rv65();
    virtual void rv66();
    virtual void rv67();
    virtual void rv68();
    virtual void rv69();
    virtual void rv70();
    virtual void rv71();
    virtual void rv72();
    virtual void rv73();
    virtual void rv74();
    virtual void rv75();
    virtual void rv76();
    virtual void rv77();
    virtual void rv78();
    virtual void rv79();
    virtual void rv80();
    virtual void rv81();
    virtual void rv82();
    virtual void rv83();
    virtual void rv84();
    virtual void rv85();
    virtual void rv86();
    virtual void rv87();
    virtual void rv88();
    virtual void rv89();
    virtual void rv90();
    virtual void rv91();
    virtual void rv92();
    virtual void rv93();
    virtual void rv94();
    virtual void rv95();
    virtual void rv96();
    virtual void rv97();
    virtual void rv98();
    virtual void SetCurrentCamera(const Pt_bd7620& pos, const Pt_bd7620& dir, const Pt_bd7620& up,
                                  const Pt_bd7620& right, const Frustum_bd7620& fr, const Port_bd7620& port);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    bool unk208;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
struct NiMemObject_bd7620
{
};
struct NiRefObject_bd7620 : NiMemObject_bd7620
{
    virtual ~NiRefObject_bd7620();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    unsigned int GetRefCount() const
    {
        return m_uiRefCount;
    }
};
struct NiObject_bd7620 : NiRefObject_bd7620
{
};
struct Accum_bd7620 : NiObject_bd7620
{
    virtual void av02();
    virtual void av03();
    virtual void av04();
    virtual void av05();
    virtual void av06();
    virtual void av07();
    virtual void av08();
    virtual void av09();
    virtual void av10();
    virtual void av11();
    virtual void av12();
    virtual void av13();
    virtual void av14();
    virtual void av15();
    virtual void av16();
    virtual void av17();
    virtual void av18();
    virtual void av19();
    virtual void av20();
    virtual void av21();
    virtual void av22();
    virtual void av23();
    virtual void av24();
    virtual void av25();
    virtual void av26();
    virtual void av27();
    virtual void av28();
    virtual void av29();
    virtual void av30();
    virtual void av31();
    virtual void av32();
    virtual void av33();
    virtual void av34();
    virtual void Begin(void* cam);
    virtual void End();

    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    bool unk84;
};
struct Culler_bd7620
{
    int unk00;
    int unk04;
    int unk08;
    void* m_pkAccumulationCamera;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    void FUN_00833810(void* vis);
    void FUN_008337f0();
    Culler_bd7620(void* vis) { FUN_00833810(vis); }
    ~Culler_bd7620() { FUN_008337f0(); }
    void FUN_008338b0(const Frustum_bd7620* fr);
};
struct Scene_bd7620
{
    void FUN_00b1f390(Culler_bd7620* c);
};
struct Cam_bd7620
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    float r00;
    float r01;
    float r02;
    float r10;
    float r11;
    float r12;
    float r20;
    float r21;
    float r22;
    Pt_bd7620 m_kTranslate;
    float m_fScale;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    Frustum_bd7620 m_kCameraFrustum;
    int unk0f8;
    int unk0fc;
    Port_bd7620 m_kPort;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    Accum_bd7620* m_p13c;
    void FUN_008264c0(UpdData_bd7620& d);
    void FUN_00b5a420(Scene_bd7620* scene);
};

// @fnv 0x00bd7620
// pdb: BSCubeMapCamera::RenderGeomForLight | BSCubeMapCamera.obj | fnv360_1110_retail, call_gap, low
// pdb params: apLight
void Cam_bd7620::FUN_00b5a420(Scene_bd7620* scene)
{
    if (!scene)
        return;
    Pt_bd7620 kRight;
    kRight.x = r02;
    Renderer_bd7620* r = (Renderer_bd7620*)DAT_0116f2f8;
    int mode = r->unk200;
    kRight.y = r12;
    kRight.z = r22;
    Pt_bd7620 kUp = {r01, r11, r21};
    Pt_bd7620 kWorldPosition = {r00, r10, r20};
    if ((mode == 1 || mode == 2) && r->unk208 == 1)
        r->SetCurrentCamera(m_kTranslate, kWorldPosition, kUp, kRight, m_kCameraFrustum, m_kPort);
    m_p13c->Begin(this);
    Accum_bd7620* acc = m_p13c;
    acc->unk84 = true;
    Culler_bd7620 kCuller(0);
    UpdData_bd7620 kData(0.0f);
    FUN_008264c0(kData);
    kCuller.m_pkAccumulationCamera = this;
    kCuller.FUN_008338b0(&m_kCameraFrustum);
    scene->FUN_00b1f390(&kCuller);
    m_p13c->End();
    if (m_p13c->GetRefCount() < 2)
        m_p13c->IncRefCount();
}
}   // namespace f3m_00b5a420

// @f3 0x00b470e0 (community match, verified in this file)
// FNV recovery:9275 adaptation; actual FO3 claim context supplies NiPointer.
namespace task0245 {
class NiPoint3
{
  public:
    float x, y, z;
};
extern const NiPoint3 DAT_0108ec68;
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct FUN_00aea720
{
    virtual ~FUN_00aea720();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
};
struct FUN_00b470e0 : FUN_00aea720
{
    NiPointer<RefObj> m_sp104;
    NiPointer<RefObj> m_sp108;
    NiPoint3 m_akPts[3];
    float m_afVals[3];
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    NiPointer<RefObj> m_sp17c;
    virtual ~FUN_00b470e0();
};
// Clears the three NiPointer members and resets each of the three m_akPts points to DAT_0108ec68 and each m_afVals entry to 0.0f.
// @fnv 0x00bc39f0
// pdb: HairShaderProperty::~HairShaderProperty | HairShaderProperty.obj | fnv360_0822_retail, caller_sim, low
FUN_00b470e0::~FUN_00b470e0()
{
    m_sp17c = 0;
    m_sp104 = 0;
    m_sp108 = 0;
    for (int i = 0; i < 3; i++)
    {
        m_akPts[i] = DAT_0108ec68;
        m_afVals[i] = 0.0f;
    }
}


}

// @f3 0x00b47f10 (community match, verified in this file)
namespace f3m_00b47f10 {
// Adapted FNV recovery:8859 compatibility-overlay example.
namespace task0277 {
void* __cdecl FUN_00c00610(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct CountedRef
{
    virtual void unused();
    virtual void Release();
    long references;
};
struct PassView
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
    int references;
    void FUN_00888c10();
};
struct PassPtr
{
    PassView* ptr;
    PassPtr() : ptr(0)
    {}
    ~PassPtr()
    {
        if (ptr && --ptr->references == 0)
            ptr->FUN_00888c10();
    }
    void clear()
    {
        PassView* old = ptr;
        if (old)
        {
            if (--old->references == 0)
                old->FUN_00888c10();
            ptr = 0;
        }
    }
};
struct RefPtr
{
    CountedRef* ptr;
    RefPtr() : ptr(0)
    {}
    ~RefPtr()
    {
        if (ptr && InterlockedDecrement(&ptr->references) == 0)
            ptr->Release();
    }
    void assign(CountedRef* value)
    {
        CountedRef* old = ptr;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->references) == 0)
                old->Release();
            ptr = value;
            if (value)
                InterlockedIncrement(&value->references);
        }
    }
    void clear()
    {
        CountedRef* old = ptr;
        if (old)
        {
            if (InterlockedDecrement(&old->references) == 0)
                old->Release();
            ptr = 0;
        }
    }
};
struct FUN_00b64170
{
    virtual ~FUN_00b64170();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char flag24;
    RefPtr source;
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
    int mode;
    int flags;
    float value;
    float matrix[16];
    FUN_00b64170();
};
struct FUN_00b47f10 : FUN_00b64170
{
    PassPtr pass;
    RefPtr first;
    RefPtr second;
    FUN_00b47f10(CountedRef* source);
    virtual ~FUN_00b47f10();
};
// @fnv 0x00bc4830
// pdb: BeamShader::BeamShader | BeamShader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apShaderDecl
FUN_00b47f10::FUN_00b47f10(CountedRef* pSource)
{
    mode = 16;
    flag24 = 1;
    flags = 0x243;
    pass.clear();
    source.assign(pSource);
    first.clear();
    second.clear();
    value = 0.0f;
    FUN_00c00610(matrix, 0, 0x40);
}


}
}   // namespace f3m_00b47f10

// @f3 0x00b562b0 (community match, verified in this file)
namespace f3m_00b562b0 {
namespace fo3_b562b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObject { virtual void Unused()=0; virtual void Release()=0; long m_iObjectReferenceCount; };
struct FUN_00424aa0 { RefObject* m_pObject; ~FUN_00424aa0(); };
struct PassView {
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
int references; void FUN_00888c10(); };
struct NiD3DPassPtr
{
    PassView* m_pObject;
    ~NiD3DPassPtr()
    {
        PassView* pkPass = m_pObject;
        if (pkPass && --pkPass->references == 0)
            pkPass->FUN_00888c10();
    }
};
struct FUN_00b62e90
{
    virtual void Unk_00();
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
    ~FUN_00b62e90();
};
struct FUN_00b562b0 : FUN_00b62e90
{
    FUN_00424aa0 m_aspPixelShader[4];
    FUN_00424aa0 m_aspVertexShader[2];
    NiD3DPassPtr m_spPass;
    ~FUN_00b562b0();
};

// Destructor releases the four pixel shader and two vertex shader references held by the object.
// @fnv 0x00bd2c40
// pdb: SpeedTreeFrondShader::~SpeedTreeFrondShader | SpeedTreeFrondShader.obj | fnv360_0822_retail, objrun, medium
FUN_00b562b0::~FUN_00b562b0()
{
    for (unsigned int i = 0; i < 4; i++)
    {
        RefObject* pkShader = (RefObject*)m_aspPixelShader[i].m_pObject;
        if (pkShader)
        {
            if (InterlockedDecrement(&pkShader->m_iObjectReferenceCount) == 0)
                pkShader->Release();
            m_aspPixelShader[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; i++)
    {
        RefObject* pkShader = (RefObject*)m_aspVertexShader[i].m_pObject;
        if (pkShader)
        {
            if (InterlockedDecrement(&pkShader->m_iObjectReferenceCount) == 0)
                pkShader->Release();
            m_aspVertexShader[i].m_pObject = 0;
        }
    }
}

}
}   // namespace f3m_00b562b0

// @f3 0x00b5d5b0 (community match, verified in this file)
namespace fnv_00bdb380 {
struct Key
{
    unsigned int first, second, third;
    bool FUN_00914770(const Key* other);
};
extern "C" Key DAT_0108f450;
struct AllocationManager
{
    void* FUN_0086b930(unsigned int count);
};
extern "C" AllocationManager DAT_01090a78;
struct ShaderPassEntry
{
    int unk00, unk04; unsigned char enabled;
    void SetEnabled()
    {
        enabled = 1;
    }
};
struct RenderPassStack
{
    unsigned int field00;
    ShaderPassEntry** passes;
    unsigned int field08;
    unsigned int field0c;
    unsigned int count;
    ShaderPassEntry* Last() const
    {
        return passes[count - 1];
    }
};
struct FUN_00b2b020
{
    unsigned int type;
    unsigned int actor;
    unsigned int data;
    unsigned int state;
    __cdecl FUN_00b2b020(void* actor, unsigned int code, int first, int second, int third, ...);
    static void* operator new(unsigned int count)
    {
        return DAT_01090a78.FUN_0086b930(count);
    }
};
struct Resource {
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
Key embeddedKey; Key* key; };
struct Actor {
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
Resource* resource; };
struct Shader
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
RenderPassStack* stack;

    FUN_00b2b020* FUN_00b5d5b0(void* actor, unsigned short* missed, unsigned char passType, unsigned char useAlternate,
                               unsigned int context);
};
// Checks the actor's resource key against DAT_0108f450, enables the last render pass, and returns a new FUN_00b2b020 (0x2d6/0x2d7) or increments missed.
// @fnv 0x00bdb380
// pdb: BSShaderPPLightingProperty::AddSelfIllumAlphaPass | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apGeom, asCount, abUpdateList, abSkinned, abGlow
FUN_00b2b020* Shader::FUN_00b5d5b0(void* actor, unsigned short* missed, unsigned char passType,
                                   unsigned char useAlternate, unsigned int context)
{
    FUN_00b2b020* result = 0;
    Resource* resource = static_cast<Actor*>(actor)->resource;
    if (resource)
    {
        Key* key = resource->key;
        if (!key)
            key = &resource->embeddedKey;
        if (Key(*key).FUN_00914770(&DAT_0108f450))
        {
            RenderPassStack* stack = this->stack;
            ShaderPassEntry* last = stack->Last();
            if (last)
                last->SetEnabled();
            if (!useAlternate)
            {
                if (passType == 1)
                {
                    result = new FUN_00b2b020(actor, 0x2d6, 0, 0, 0);
                }
                else
                {
                    ++*missed;
                }
            }
            else
            {
                if (passType == 1)
                {
                    result = new FUN_00b2b020(actor, 0x2d7, 0, 0, 0);
                }
                else
                {
                    ++*missed;
                }
            }
        }
    }
    return result;
}
}  // namespace fnv_00bdb380

// @f3 0x00b43020 (community match, verified in this file)
// Adapted recovery:9390 with actual FO3 helper bindings.
namespace task0261 {
struct ShaderObject
{
    virtual void Destroy();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct MM { void FUN_0086ba60(void*); };
extern MM DAT_01090a78;

struct Pass_bc0f80
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
    int count;
    void FUN_00888c10();
    void IncRefCount()
    {
        ++count;
    }
    void DecRefCount()
    {
        if (--count == 0)
            FUN_00888c10();
    }
};

extern NiPointer<ShaderObject> DAT_01177cd8;
struct FUN_00b62e90
{
    virtual ~FUN_00b62e90();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    void* unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
};
struct FUN_00b43020 : FUN_00b62e90
{
    NiPointer<Pass_bc0f80> pass;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    NiPointer<ShaderObject> refA;
    NiPointer<ShaderObject> refB;
    virtual ~FUN_00b43020();
};

// @fnv 0x00bc0f80
// pdb: BoltShader::~BoltShader | BoltShader.obj | fnv360_0822_retail, objrun, medium
FUN_00b43020::~FUN_00b43020()
{
    DAT_01177cd8 = 0;
    DAT_01090a78.FUN_0086ba60(unk070);
    unk070 = 0;
    pass = 0;
    if (ShaderObject* obj = refA)
    {
        long volatile* p = &obj->m_uiRefCount;
        if (InterlockedDecrement(p) == 0)
            obj->DeleteThis();
        refA.m_pObject = 0;
    }
    refB = 0;
}
}  // namespace fnv_00bc0f80

// @f3 0x00b58210 (community match, verified in this file)
struct DispatchHandler;
struct DispatchRegistry
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
    DispatchHandler* handler;
};
extern DispatchRegistry* DAT_01091980;
namespace f3_00b58210 {
struct GeomB8
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
};
struct BoundStub
{
    float cx;
    float cy;
    float cz;
    float radius;
};
struct GeomStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    BoundStub* bound;
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
    GeomB8* unkb8;
    int unkbc;
};
struct PassArg
{
    int unk00;
    int unk04;
    int unk08;
};
struct FogStub;
struct PassShader
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void SetupPass(void* handler, GeomStub* geom, int bc, int a, int b8, PassArg* arg, int c, int* bounds68,
                           BoundStub* bound, int d, int e);
};
struct PassOwner
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
    PassShader* unk30;
    PassShader* unk34;
};
extern GeomStub** DAT_0116efd0;
extern BoundStub DAT_0108edc8;
extern unsigned char DAT_0116efb4;
FogStub* __cdecl FUN_00adb920(int idx);
PassOwner* __cdecl FUN_00adb960(int idx);
struct FUN_00bd4ba0_class
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void Apply(GeomStub* geom, FogStub* fog, int x);
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
    PassShader* unk30;
    PassShader* unk34;
    void FUN_00b00430(PassArg* arg);
    void FUN_00b58210(PassArg* arg);
};

// @fnv 0x00bd4ba0
// pdb: SpeedTreeBranchShader::SetupGeometryConstants | SpeedTreeBranchShader.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apState
void FUN_00bd4ba0_class::FUN_00b58210(PassArg* pPassArg)
{
    GeomStub* geom = *DAT_0116efd0;
    BoundStub* bound = geom->bound;
    if (!bound)
        bound = &DAT_0108edc8;
    int b8 = geom->unkb8->unk34;
    int bc = geom->unkbc;
    int x = pPassArg->unk08;
    FUN_00b00430(pPassArg);
    FogStub* fog = FUN_00adb920(DAT_0116efb4);
    Apply(geom, fog, x);
    PassOwner* owner = FUN_00adb960(1);
    owner->unk30->SetupPass((void*)DAT_01091980->unk44, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    owner->unk34->SetupPass(DAT_01091980->handler, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    PassShader* pShader30 = unk30;
    if (pShader30)
    {
        void* h = (void*)DAT_01091980->unk44;
        if (h)
            pShader30->SetupPass(h, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    }
    PassShader* pShader34 = unk34;
    if (pShader34)
    {
        void* h = DAT_01091980->handler;
        if (h)
            pShader34->SetupPass(h, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    }
}

}

// @f3 0x00b57dc0 (community match, verified in this file)
extern void* DAT_0116f2f8;
namespace f3m_00b57dc0 {
namespace f3_0268 {
void* __cdecl FUN_0089eb90(unsigned int);
struct NiMemObject { static void* operator new(unsigned int n) { return FUN_0089eb90(n); } };
void* __cdecl FUN_0087e9a0(void*, unsigned int, unsigned int);
struct NiD3DShaderDeclaration
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual bool SetEntry(unsigned int auiEntry, unsigned int auiRegister, unsigned int auiType, unsigned int auiUsage,
                          unsigned int auiStream);
    virtual void Unk_24();
    virtual bool SetEntryAlt(unsigned int auiStream, unsigned int auiEntry, unsigned int auiRegister,
                             unsigned int auiInput, unsigned int auiType, unsigned int auiUsage,
                             unsigned int auiUsageIndex, unsigned int auiTesselator);
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Finalize();
};
struct FUN_00b57b30 : NiMemObject
{
    static void operator delete(void* pvMem);
    FUN_00b57b30(NiD3DShaderDeclaration* apDecl);
    virtual ~FUN_00b57b30();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void UseShaderDeclaration(NiD3DShaderDeclaration* apDecl);
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
};
// @fnv 0x00bd4750
// pdb: SpeedTreeBranchShader::CreateShader | SpeedTreeBranchShader.obj | fnv360_0822_retail, call_gap, medium
FUN_00b57b30* FUN_00b57dc0()
{
    NiD3DShaderDeclaration* pDecl = (NiD3DShaderDeclaration*)FUN_0087e9a0(DAT_0116f2f8, 6, 1);
    pDecl->SetEntry(0, 0, 0, 2, 0);
    pDecl->SetEntry(1, 3, 3, 2, 0);
    pDecl->SetEntry(2, 7, 5, 1, 0);
    pDecl->SetEntry(3, 0xe, 0xd, 2, 0);
    pDecl->SetEntry(4, 0xf, 0xe, 2, 0);
    pDecl->SetEntryAlt(0, 5, 0xa, 0x80000000, 3, 2, 0, 0);
    pDecl->Finalize();
    FUN_00b57b30* pShader = new FUN_00b57b30(pDecl);
    pShader->Unk_13();
    pShader->Unk_51();
    pShader->Unk_54();
    pShader->Unk_47();
    pShader->UseShaderDeclaration(pDecl);
    return pShader;
}

}
}   // namespace f3m_00b57dc0

// @f3 0x00b563c0 (community match, verified in this file)
namespace f3m_00b563c0 {
namespace fo3_b563c0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefObject
{
    virtual void Destroy();
    virtual void DeleteThis();
    long m_uiRefCount;
};

template <class T> struct ShaderRefPtr
{
    T* m_pObject;
    ShaderRefPtr<T>& operator=(T* object)
    {
        T* old = m_pObject;
        if (old != object)
        {
            if (old)
            {
                if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                    old->DeleteThis();
            }
            m_pObject = object;
            if (m_pObject)
                InterlockedIncrement(&m_pObject->m_uiRefCount);
        }
        return *this;
    }
};

struct StageReturn
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
    int m_iObjectReferenceCount;
    void FUN_0088fe30();
    void DecRefCount()
    {
        if (--m_iObjectReferenceCount == 0)
            FUN_0088fe30();
    }
};

struct StagePtr
{
    StageReturn* m_pObject;
    StagePtr() : m_pObject(0)
    {}
    ~StagePtr()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

struct ShaderPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_kTextureStages;
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
    ShaderRefPtr<ShaderRefObject> m_spObject44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    ShaderRefPtr<ShaderRefObject> m_spObject5c;
    int FUN_00888d30(unsigned int index, StageReturn* stage);
};

struct ShaderPassPtr
{
    ShaderPass* m_pObject;
    ShaderPass* operator->() const
    {
        return m_pObject;
    }
};

void __cdecl FUN_00888f80(ShaderPassPtr& pass);
void __cdecl FUN_0088ff50(StagePtr& stage);
void __cdecl FUN_00b62c70(StageReturn* stage, int a, int b, int c, int d);

struct FUN_00bd2d50_class
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
    ShaderRefObject* m_pObject6c;
    int unk70;
    int unk74;
    int unk78;
    ShaderRefObject* m_pObject7c;
    int unk80;
    ShaderPassPtr m_spPass;
    void FUN_00b563c0();
};

// Creates a shader pass, builds a stage, configures it with FUN_00b62c70, assigns the stage to the pass, and sets the pass's two shader objects.
// @fnv 0x00bd2d50
// pdb: SpeedTreeFrondShader::LoadStagesAndPasses | SpeedTreeFrondShader.obj | fnv360_0822_retail, call_seq, medium
void FUN_00bd2d50_class::FUN_00b563c0()
{
    FUN_00888f80(m_spPass);
    StagePtr stage;
    FUN_0088ff50(stage);
    FUN_00b62c70(stage.m_pObject, 0, 3, 2, 1);
    m_spPass->FUN_00888d30(m_spPass->m_kTextureStages, stage.m_pObject);
    m_spPass->m_spObject5c = m_pObject6c;
    m_spPass->m_spObject44 = m_pObject7c;
}

}
}   // namespace f3m_00b563c0

// @f3 0x00b50d10 (community match, verified in this file)
namespace f3_0271 {
void* __cdecl FUN_0089eb90(unsigned int);
struct RendererStub;
extern RendererStub* DAT_0116f2f8;
struct PassStub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void SetStage(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void Finish();
};
PassStub* __cdecl FUN_0087e9a0(RendererStub* r, int a, int b);
struct FUN_00b50a20
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void Init19();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void SetPass(PassStub* p);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Init71();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void Init81();
    virtual void v52();
    virtual void v53();
    virtual void Init84();
    FUN_00b50a20(PassStub* p);
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void*);
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
};

// Creates a pass with six stages, finishes it, constructs a FUN_00b50a20 from it, runs several init calls, sets the pass and returns the object.
// @fnv 0x00bcd680
// pdb: ParallaxShader::CreateShader | ParallaxShader.obj | fnv360_0822_retail, call_gap, medium
FUN_00b50a20* __cdecl FUN_00b50d10()
{
    PassStub* pass = FUN_0087e9a0(DAT_0116f2f8, 6, 1);
    pass->SetStage(0, 0, 0, 2, 0);
    pass->SetStage(1, 3, 3, 2, 0);
    pass->SetStage(2, 5, 4, 3, 0);
    pass->SetStage(3, 7, 5, 1, 0);
    pass->SetStage(4, 0xe, 0xd, 2, 0);
    pass->SetStage(5, 0xf, 0xe, 2, 0);
    pass->Finish();
    FUN_00b50a20* obj = new FUN_00b50a20(pass);
    obj->Init19();
    obj->Init81();
    obj->Init84();
    obj->Init71();
    obj->SetPass(pass);
    return obj;
}
}  // namespace f3_0271

// @f3 0x00b5bde0 (community match, verified in this file)
namespace f3m_00b5bde0 {
namespace f3_0276 {
struct NiGeometry;
struct PassList { void FUN_00b2c0b0(NiGeometry*, unsigned int, bool, unsigned char, void*, void*, void*, unsigned int); };
struct Shader_00bd9bc0
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
    PassList* pPasses;

    int FUN_00b5bde0(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool a, bool b,
                     bool c);
};

// @fnv 0x00bd9bc0
// pdb: BSShaderPPLightingProperty::AddFogPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned, abTreeBranch, abAlphaBlend
int Shader_00bd9bc0::FUN_00b5bde0(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool a,
                                  bool b, bool c)
{
    if (!b)
    {
        if (!a)
        {
            if (!c)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x252, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x253, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
        }
        else
        {
            if (!c)
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x254, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x255, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
        }
    }
    else
    {
        if (type == 1)
            pPasses->FUN_00b2c0b0(geom, 0x256, *enabled, 0, 0, 0, 0, 0);
        else
            ++*count;
    }
    *enabled = false;
    return 0;
}

}
}   // namespace f3m_00b5bde0

// @f3 0x00b48730 (community match, verified in this file)
extern bool DAT_01067b4e;
namespace f3m_00b48730 {
// Adapted recovery:9328 with FO3 helper bindings.
namespace task0279 {
struct RefObject {
    virtual void Unused() = 0;
    virtual void Release() = 0;
    long m_iObjectReferenceCount;
};
void* __cdecl FUN_00c00610(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct ShaderRef_bc5070 : RefObject
{
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            Release();
    }
};
struct Config_bc5070
{
    const char* filename;
    unsigned int flags;
    unsigned int macros[17];
    Config_bc5070(const char* path)
    {
        filename = path;
        flags = 0;
        FUN_00c00610(macros, 0, 0x44);
    }
};
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
struct FUN_00bc5070_shell
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
    NiPointer<ShaderRef_bc5070> shaders[2];
    ShaderRef_bc5070* FUN_00b62f60(const char*, unsigned int*, const char*, const char*);
    void FUN_00b48730();
};
// @fnv 0x00bc5070
// pdb: VolumetricFogShader::LoadVertexShaders | VolumetricFogShader.obj | fnv360_0822_retail, ustr, medium
void FUN_00bc5070_shell::FUN_00b48730()
{
    const char* profileNames[2] = {"vs_2_0", "vs_3_0"};
    Config_bc5070 configs[2] = {Config_bc5070("vfog\\VolumetricFog.v.hlsl"),
                                Config_bc5070("vfog\\VolumetricFog.v.hlsl")};
    char binaryName[260];
    char sourceName[260];
    for (int i = 0; i < 2; ++i)
    {
        if (i == 1 && !DAT_01067b4e)
            continue;
        FUN_00b62b90(configs[i].filename, sourceName);
        FUN_00403230(binaryName, 260, "VolumetricFog%03d.vso", i);
        shaders[i] = FUN_00b62f60(sourceName, &configs[i].flags, profileNames[i], binaryName);
    }
}


}
}   // namespace f3m_00b48730

// @f3 0x00b52e80 (community match, verified in this file)
namespace f3m_00b52e80 {
namespace f3_00b52e80 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct ShaderRefObject
{
    virtual ~ShaderRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct ShaderPtr
{
    T* m_pObject;
    ShaderPtr() : m_pObject(0) {}
    ~ShaderPtr() { if(m_pObject) m_pObject->DecRefCount(); }
};

struct ShaderRefPtr
{
    ShaderRefObject* m_pObject;
    ShaderRefPtr& operator=(ShaderRefObject* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct FUN_00afc480
{
    FUN_00afc480(void* a, void* b, int c, int d);
    virtual ~FUN_00afc480();
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
    bool unk64;
    int unk68;
    ShaderRefPtr m_spPixelShaderObject;
    ShaderRefPtr m_spVertexShaderObject;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
};

struct FUN_00b52e80 : FUN_00afc480
{
    ShaderPtr<ShaderRefObject> m_aspPasses[26];
    ShaderPtr<ShaderRefObject> m_aspOtherPasses[13];
    FUN_00b52e80(ShaderRefObject* pPixel, ShaderRefObject* pVertex);
    virtual ~FUN_00b52e80();
};

// @fnv 0x00bcf7f0
// pdb: SkinShader::SkinShader | SkinShader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apShaderDecl, apSkinnedShaderDecl
FUN_00b52e80::FUN_00b52e80(ShaderRefObject* pPixel, ShaderRefObject* pVertex) : FUN_00afc480(pPixel, pVertex, 0, 0)
{
    unk68 = 4;
    unk64 = false;
    m_spPixelShaderObject = pPixel;
    m_spVertexShaderObject = pVertex;
    unk60 = 0;
}

}
}   // namespace f3m_00b52e80

// @f3 0x00b5d130 (community match, verified in this file)
namespace f3_0563 {
inline unsigned short CapCount(unsigned short value, unsigned int limit) { return value < limit ? value : limit; }
struct SelectColor { float r,g,b; };
struct NiGeometry;
struct ShadowSceneLight;

extern SelectColor DAT_0108f450;
extern int DAT_0116efb0;
extern unsigned int DAT_01067b68;
extern unsigned char DAT_0116ef97;

struct PassElem
{
    int unk00;
    int unk04;
    short unk08;
    unsigned char unk0a;
    unsigned char m_0b;
};

struct PassSinkBdaf10
{
    int unk00;
    PassElem** m_04;
    int unk08;
    int unk0c;
    int m_10;
    void __thiscall FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                                 ShadowSceneLight*, ShadowSceneLight*);
};

struct GeomInfo
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
    int* m_ac;
    int unk_b0;
    int* m_b4;
};

struct F8Obj
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
    SelectColor m_d4;
};

struct IterObj
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    F8Obj* m_f8;
};

struct NiGeometry
{
    GeomInfo* __thiscall FUN_00826590(int);
};

struct ShaderBdaf10
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
    PassSinkBdaf10* m_3c;
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
    unsigned short m_c8;
    short unk_ca;
    unsigned short GetShadowCount() const { return m_c8; }
    IterObj* __thiscall FUN_00af32e0(void*);
    IterObj* __thiscall FUN_00af33d0(void*);
    void __thiscall BSShaderPPLightingProperty_AddLandscapePasses_1x(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count,
                                     unsigned char type, bool* out, bool flag6);
};

// Emits shadow rendering passes for geom and light into m_3c, or increments *count when type is not 1.
// @fnv 0x00bdaf10
// pdb: BSShaderPPLightingProperty::AddLandscapePasses_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, udata + bridge(caller_sim|caller_sim), high
void __thiscall ShaderBdaf10::BSShaderPPLightingProperty_AddLandscapePasses_1x(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count,
                                               unsigned char type, bool* out, bool flag6)
{
    GeomInfo* info = geom->FUN_00826590(3);
    bool* pOut = out;
    bool flag = DAT_0116efb0 <= 1;
    unsigned short n = CapCount(GetShadowCount(), DAT_01067b68);
    if (DAT_0116ef97)
    {
        if (type == 1)
            m_3c->FUN_00b2c0b0(geom, 0x93, *pOut, 0, 0, 0, 0, 0);
        else
            ++*count;
        *pOut = false;
        for (unsigned char i = 0; i < n; ++i)
        {
            if (info->m_ac[i + 1] != 0)
            {
                if (type == 1)
                {
                    m_3c->FUN_00b2c0b0(geom, 0x1f2, *pOut, 0, 0, 0, 0, 0);
                    ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                }
                else
                {
                    ++*count;
                }
            }
        }
        return;
    }
    if (!flag6)
    {
        if (type == 1)
            m_3c->FUN_00b2c0b0(geom, 0x93, *pOut, 1, light, 0, 0, 0);
        else
            ++*count;
    }
    else
    {
        if (type == 1)
            m_3c->FUN_00b2c0b0(geom, 0x94, *pOut, 1, light, 0, 0, 0);
        else
            ++*count;
    }
    *pOut = false;
    if (*info->m_b4 != 0)
    {
        if (type == 1)
            m_3c->FUN_00b2c0b0(geom, 0x1f1, false, 0, 0, 0, 0, 0);
        else
            ++*count;
    }
    if (flag)
    {
        void* cursor;
        IterObj* obj = FUN_00af32e0(&cursor);
        while (obj)
        {
            if (!obj)
                break;
            SelectColor& col = obj->m_f8->m_d4;
            if (!(col.r == DAT_0108f450.r && col.g == DAT_0108f450.g && col.b == DAT_0108f450.b))
            {
                if (type == 1)
                    m_3c->FUN_00b2c0b0(geom, 0x1ef, *pOut, 1, (ShadowSceneLight*)obj, 0, 0, 0);
                else
                    ++*count;
            }
            obj = FUN_00af33d0(&cursor);
        }
    }
    for (unsigned char i = 0; i < n; ++i)
    {
        if (info->m_ac[i + 1] != 0)
        {
            if (!flag6)
            {
                if (type == 1)
                {
                    m_3c->FUN_00b2c0b0(geom, 0x1f2, *pOut, 1, light, 0, 0, 0);
                    ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                }
                else
                {
                    ++*count;
                }
            }
            else
            {
                if (type == 1)
                {
                    m_3c->FUN_00b2c0b0(geom, 0x1f3, *pOut, 1, light, 0, 0, 0);
                    ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                }
                else
                {
                    ++*count;
                }
            }
        }
    }
    for (unsigned char i = 0; i < n; ++i)
    {
        if (info->m_ac[i + 1] == 0)
            continue;
        if (info->m_b4[i + 1] != 0)
        {
            if (type == 1)
            {
                m_3c->FUN_00b2c0b0(geom, 0x1f4, *pOut, 0, 0, 0, 0, 0);
                ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
            }
            else
            {
                ++*count;
            }
        }
        if (flag)
        {
            void* cursor;
            IterObj* obj = FUN_00af32e0(&cursor);
            while (obj)
            {
                if (!obj)
                    break;
                SelectColor& col = obj->m_f8->m_d4;
                if (!(col.r == DAT_0108f450.r && col.g == DAT_0108f450.g && col.b == DAT_0108f450.b))
                {
                    if (type == 1)
                    {
                        m_3c->FUN_00b2c0b0(geom, 0x1f5, *pOut, 1, (ShadowSceneLight*)obj, 0, 0, 0);
                        ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                    }
                    else
                    {
                        ++*count;
                    }
                }
                obj = FUN_00af33d0(&cursor);
            }
        }
    }
}

}

// @f3 0x00b459e0 (community match, verified in this file)
#include <math.h>
namespace f3_0568 {
struct BoundPoint
{
    float x, y, z;
    BoundPoint()
    {}
    BoundPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    BoundPoint operator-(const BoundPoint& b) const
    {
        return BoundPoint(x - b.x, y - b.y, z - b.z);
    }
    BoundPoint operator+(const BoundPoint& b) const
    {
        return BoundPoint(x + b.x, y + b.y, z + b.z);
    }
    BoundPoint operator*(float a) const
    {
        return BoundPoint(x * a, y * a, z * a);
    }
    float Length() const
    {
        double squaredX = x * x;
        double squaredY = y * y;
        double squaredZ = z * z;
        float squaredLength = (float)(squaredX + squaredY + squaredZ);
        return (float)sqrt(squaredLength);
    }
};
struct ParticleBound
{
    BoundPoint center;
    float radius;
};
struct ParticleRTTI
{
    const char* name;
    const ParticleRTTI* base;
};
class ParticleNiObject
{
  public:
    virtual void Method00();
    virtual void Method01();
    virtual const ParticleRTTI* GetRTTI();
    virtual void Method03();
    virtual void Method04();
    virtual void Method05();
    virtual void Method06();
    virtual void Method07();
    virtual void Method08();
    virtual void Method09();
    virtual void Method10();
    virtual void Method11();
    virtual void Method12();
    virtual void Method13();
    virtual void Method14();
    virtual void Method15();
    virtual void Method16();
    virtual void Method17();
    virtual void Method18();
    virtual void Method19();
    virtual void Method20();
    virtual void Method21();
    virtual void Method22();
    virtual void Method23();
    virtual void Method24();
    virtual void Method25();
    virtual void Method26();
    virtual void Method27();
    virtual void Method28();
    virtual void Method29();
    virtual void Method30();
    virtual void Method31();
    virtual void Method32();
    virtual void Method33();
    virtual void Method34();
    virtual void Method35();
    virtual void Method36();
    virtual void Method37();
    virtual void Method38();
    virtual void Method39();
    virtual void Method40();
    virtual void Method41();
    virtual void Method42();
    virtual void Method43();
    virtual void Method44();
    virtual void Method45();
    virtual void Method46();
    virtual void Method47();
    virtual void Method48();
    virtual void Method49();
    virtual void Method50();
    virtual void Method51();
    virtual void Method52();
    virtual void Method53();
    virtual void Method54();
    virtual void Method55();
    virtual void Method56();
    virtual void Method57();
    virtual void Method58();
    virtual void Method59();
    virtual void Method60();
    virtual void Method61();
    virtual void Method62();
    virtual void SetObjectBound(ParticleBound bound);
    virtual void SetCount(unsigned short count);
    bool IsKindOfType(const ParticleRTTI* desired) const
    {
        const ParticleRTTI* type = const_cast<ParticleNiObject*>(this)->GetRTTI();
        while (type)
        {
            if (type == desired)
                return true;
            type = type->base;
        }
        return false;
    }
};
extern ParticleRTTI DAT_01178250;
ParticleNiObject* __cdecl FUN_00424d50(const ParticleRTTI*, ParticleNiObject*);
extern ParticleRTTI DAT_01178258;
struct BoundDataBlock
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    float radius;
};
inline float m_kBoundMin(float a, float b)
{
    return a < b ? a : b;
}
inline float m_kBoundMax(float a, float b)
{
    return a > b ? a : b;
}
struct ParticleBounds0568
{
    int unk00;
    int unk04;
    int unk08;
    short unk0c;
    unsigned short m_uiItemCount;
    float* m_kFloatData;
    int* m_intData;

    void __thiscall FUN_00b459e0();
    
};

// Computes a bounding sphere from m_kFloatData positions (skipping z <= -2147483648.0f) and passes it to unk00's SetObjectBound and SetCount.
// @fnv 0x00bd5e40
// pdb: DistantLODGroup::UpdateGroupBound | DistantLODGroup.obj | fnv360_0822_retail, call_dedup, medium
void ParticleBounds0568::FUN_00b459e0()
{
    float limit = 5000000000.0f;
    if (m_uiItemCount == 0)
        limit = 0.0f;
    BoundPoint minimum(limit, limit, limit);
    BoundPoint maximum(-limit, -limit, -limit);
    for (int i = 0; i < m_uiItemCount; ++i)
    {
        float* position = m_kFloatData + 4 * i;
        if (position[2] > -2147483648.0f)
        {
            minimum.x = m_kBoundMin(minimum.x, position[0]);
            maximum.x = m_kBoundMax(maximum.x, position[0]);
            minimum.y = m_kBoundMin(minimum.y, position[1]);
            maximum.y = m_kBoundMax(maximum.y, position[1]);
            minimum.z = m_kBoundMin(minimum.z, position[2]);
            maximum.z = m_kBoundMax(maximum.z, position[2]);
        }
    }
    BoundDataBlock* data = (BoundDataBlock*)unk04;
    if (data)
    {
        ParticleNiObject* object = (ParticleNiObject*)unk00;
        if (object)
        {
            BoundPoint difference = maximum - minimum;
            BoundPoint upper = maximum;
            maximum = difference * 0.5f;
            minimum = minimum + maximum;
            difference = upper - minimum;
            ParticleBound bound;
            bound.center = minimum;
            bound.radius = difference.Length() + data->radius;
            bool compatible = object->IsKindOfType((const ParticleRTTI*)&DAT_01178258);
            ParticleNiObject* geometry = compatible ? object : 0;
            if (geometry)
            {
                geometry->SetObjectBound(bound);
                geometry->SetCount(m_uiItemCount);
            }
            else
            {
                object = (ParticleNiObject*)unk00;
                geometry = FUN_00424d50(&DAT_01178250, object);
                if (geometry)
                {
                    geometry->SetObjectBound(bound);
                    geometry->SetCount(m_uiItemCount);
                }
            }
        }
    }
}

}

// @f3 0x00b41030 (community match, verified in this file)
namespace f3m_00b41030 {
struct P36 { float x,y,z; __declspec(noinline) P36 FUN_004229a0(const P36& other) { P36 out; out.x=x-other.x; out.y=y-other.y; out.z=z-other.z; return out; } float FUN_00432bd0(); };
struct C36 { float r,g,b; float FUN_00af4630(); C36 FUN_00575500(float scale); float ComputeWeightedSum() { return FUN_00af4630(); } C36 ScaleTo(float s) { return FUN_00575500(s); } };
struct T36 {
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
 P36 pos8c;
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
 float radC4;
    int unkc8;
    int unkcc;
    int unkd0;
 C36 posD4; float fE0; };
struct N36 {
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
 T36* target; };
struct H36 {
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
 N36* listE0; };
struct O36 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
 unsigned int flags; float opacity; float FUN_00aea020(); bool FUN_00468ec0(int); N36* FUN_00af32e0(int*); };
struct F36 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
 unsigned short flags; unsigned char strength; };
struct RGBWords { float ambient,diffuse,specular,emissive; };
extern RGBWords DAT_01177900, DAT_00f73220;
extern int DAT_0116efa8;
extern H36* DAT_0116efb8;
extern double DAT_00dbeb78;
extern bool DAT_01176995;
struct D36 { int unk00,unk04; unsigned char dim; }; extern D36* DAT_01176e70;
double __cdecl FUN_005b4fe0(double,float);
double __cdecl FUN_00af4610(double,double);
// pdb: Lighting30Shader::SetupGeometryConstants_MaterialAlpha | Lighting30Shader.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: aWorldBound, apProp, apState, auiCurrentPass
void __stdcall FUN_00b41030(const P36* original, O36* lighting, F36** state,
                            unsigned int renderMode)
{
    DAT_01177900 = DAT_00f73220;
    if (DAT_0116efa8 == 8)
    {
        DAT_01177900.ambient = ((lighting->flags & 0x20000u) > 0u) ? 0.0f : 1.0f;
        F36* s = *state;
        if (s && (((*(unsigned char*)&s->flags) & 1u) || ((((unsigned char)(s->flags >> 9)) & 1u) != 0)))
        {
            DAT_01177900.diffuse = 0.0f;
        }
        else
        {
            DAT_01177900.diffuse = 1.0f;
        }
        return;
    }
    if (DAT_0116efa8 == 10 || renderMode - 0x1bd > 6)
    {
        DAT_01177900.ambient = lighting->opacity < 1.0f ? lighting->opacity : 1.0f;
    }
    else
    {
        float modifier = lighting->FUN_00aea020();
        float illumination = lighting->opacity * modifier;
        DAT_01177900.ambient = illumination < 1.0f ? illumination : 1.0f;
        if (((lighting->flags & 0x8000u) > 0u) && !lighting->FUN_00468ec0(0x11))
        {
            renderMode = 0;
            illumination = 0.0f;
            N36* node = lighting->FUN_00af32e0((int*)&renderMode);
            T36* __restrict cam = ((H36*)DAT_0116efb8)->listE0->target;
            float alpha;
            {
                C36 sun = cam->posD4;
                alpha = sun.ComputeWeightedSum();
            }
            if (node)
            {
                T36* t = node->target;
                P36 relative = t->pos8c.FUN_004229a0(*original);
                C36 scaledColor = node->target->posD4.FUN_00575500(node->target->radC4);
                float distance = relative.FUN_00432bd0() / t->fE0;
                double d = FUN_005b4fe0(0.0, distance);
                float vfade = 1.0f - (float)FUN_00af4610(1.0, d);
                float fade = (float)((double)vfade * 1.0);
                illumination = scaledColor.ComputeWeightedSum() * fade;
            }
            DAT_01177900.ambient *= (illumination > alpha ? illumination : alpha);
        }
    }
    F36* s = *state;
    if (!(((unsigned char)(s->flags >> 9)) & 1))
    {
        DAT_01177900.diffuse = 0.0f;
    }
    else
    {
        DAT_01177900.diffuse = (float)(s->strength / DAT_00dbeb78);
    }
    DAT_01177900.specular = 0.0f;
    DAT_01177900.emissive = 0.0f;
    unsigned int mode = (s->flags >> 5) & 0xf;
    if (mode == 0)
    {
        DAT_01177900.specular = 1.0f;
    }
    else if (mode == 2)
    {
        DAT_01177900.emissive = 1.0f;
    }
    bool previouslyDim = DAT_01176995;
    bool dim = DAT_01177900.ambient < 1.0f;
    DAT_01176995 = dim;
    DAT_01176e70->dim = (previouslyDim || dim);
}
}   // namespace f3m_00b41030

// @f3 0x00b4e8a0 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }

    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }

    volatile long referenceCount;
};

class RendererResource
{
public:
    void FUN_00888c10();

    __forceinline void IncRefCount()
    {
        ++referenceCount;
    }

    __forceinline void DecRefCount()
    {
        if (--referenceCount == 0)
            FUN_00888c10();
    }

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    unsigned int unk54, unk58, unk5c, unk60;
    unsigned int referenceCount;
};

class ShaderBase
{
public:
    virtual ~ShaderBase();

    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    unsigned int unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    unsigned int unk58, unk5c, unk60, unk64, unk68;
};

class ShaderResources : public ShaderBase
{
public:
    virtual ~ShaderResources();

    NiPointer<RendererResource> renderTargets[2];
    NiPointer<NiRefObject> firstGroup[2];
    NiPointer<NiRefObject> secondGroup[2];
    NiPointer<NiRefObject> firstObject;
    NiPointer<NiRefObject> secondObject;
    NiPointer<NiRefObject> thirdObject;
};

extern NiPointer<NiRefObject> DAT_01177f80;
extern NiPointer<NiRefObject> DAT_01177f84;

// pdb: GeometryDecalShader::~GeometryDecalShader | GeometryDecalShader.obj | fnv360_0822_retail, objrun_prop, low
ShaderResources::~ShaderResources()
{
    NiRefObject* empty = 0;
    firstObject = empty;
    secondObject = empty;
    thirdObject = empty;

    for (unsigned int i = 0; i < 2; ++i)
    {
        renderTargets[i] = static_cast<RendererResource*>(0);
        firstGroup[i] = empty;
        secondGroup[i] = empty;
    }

    DAT_01177f80 = empty;
    DAT_01177f84 = empty;
}

// @f3 0x00b564e0 (community match, verified in this file)
namespace f3_0262 {
void* __cdecl FUN_0089eb90(unsigned int);
struct TLSData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int iAllocType;
};
extern __declspec(thread) TLSData g_tlsData;

struct MemContextGuard
{
    int iSaved;
    MemContextGuard(int iType)
    {
        iSaved = g_tlsData.iAllocType;
        g_tlsData.iAllocType = iType;
    }
    ~MemContextGuard()
    {
        g_tlsData.iAllocType = iSaved;
    }
};

struct NiRenderer;
extern NiRenderer* DAT_0116f2f8;

struct ShaderDecl
{
    static ShaderDecl* __cdecl FUN_0087e9a0(NiRenderer* pRenderer, unsigned int uiMaxStreamEntryCount,
                                      unsigned int uiStreamCount);
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool SetEntry(unsigned int uiEntry, unsigned int uiRegister, unsigned int eInput, unsigned int eType,
                          unsigned int uiStream);
    virtual void v24();
    virtual bool SetEntryEx(unsigned int uiStream, unsigned int uiEntry, unsigned int uiElapsedMilliseconds,
                            unsigned int eType, unsigned int eMethod, unsigned int eUsage, unsigned int uiUsageIndex,
                            unsigned int uiExtra);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void MarkAsModified();
};

struct FUN_00b561d0
{
    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* p);
    FUN_00b561d0();
    void FUN_00b563c0();
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void Initialize();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void SetShaderDeclaration(ShaderDecl* pDecl);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void InitPasses();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void CreatePasses();
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
};

// @fnv 0x00bd2e70
// pdb: SpeedTreeFrondShader::CreateShader | SpeedTreeFrondShader.obj | fnv360_0822_retail, call_gap, medium
FUN_00b561d0* __cdecl FUN_00b564e0()
{
    MemContextGuard kGuard(0x1f);
    ShaderDecl* pDecl = ShaderDecl::FUN_0087e9a0(DAT_0116f2f8, 5, 1);
    pDecl->SetEntry(0, 0, 0, 2, 0);
    pDecl->SetEntry(1, 3, 3, 2, 0);
    pDecl->SetEntry(2, 5, 4, 3, 0);
    pDecl->SetEntry(3, 7, 5, 1, 0);
    pDecl->SetEntryEx(0, 4, 8, 0x80000000, 3, 2, 0, 0);
    pDecl->MarkAsModified();
    FUN_00b561d0* pShader = new FUN_00b561d0;
    pShader->Initialize();
    pShader->CreatePasses();
    pShader->FUN_00b563c0();
    pShader->InitPasses();
    pShader->SetShaderDeclaration(pDecl);
    return pShader;
}
}  // namespace f3_0262

// @f3 0x00b5d6d0 (community match, verified in this file)
extern unsigned int DAT_00e8ff6c;
extern unsigned char DAT_0116ef97;
extern unsigned char DAT_0116f212;
extern float DAT_0116f248;
extern float DAT_0116f250;
extern float DAT_0116f258;
extern int DAT_0108f450;
extern int DAT_01176520;
extern int DAT_0117826c;
extern int DAT_01176508;
namespace f3m_00b5d6d0 {
namespace task1307 {
static __forceinline bool AlphaOrdered(float left, float right)
{
    return left < right;
}
struct SceneGeometry;
struct DrawLight;
struct ShaderPassEntry
{
    unsigned int passId;
    unsigned short technique;
    unsigned char status;
};
struct RenderPassCollection
{
    unsigned int unknown00;
    ShaderPassEntry** entries;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int size;
    void AddPass(SceneGeometry*, unsigned short, bool, unsigned char, DrawLight*, DrawLight*, DrawLight*, DrawLight*);
};
struct GeometryState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char flags;
};
struct GeometryData
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
    int normalCount;
};
struct GeometryProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short flags;
};
struct PropHelper
{
    void* FUN_00826590(unsigned int);
};
struct SceneGeometry : PropHelper
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
    GeometryState* state;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    GeometryData* data;
};
struct AttributeTester
{
    bool FUN_00914770(const void* property);
};
struct LightProperties
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
    AttributeTester primary;
    unsigned char unkd5;
    unsigned short unkd6;
    unsigned int unkd8;
    unsigned int unkdc;
    AttributeTester alternate;
};
struct DrawLight
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
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    LightProperties* properties;
    bool Matches(const void* property)
    {
        return properties->primary.FUN_00914770(property);
    }
    bool MatchesAlternate(const void* property)
    {
        return properties->alternate.FUN_00914770(property);
    }
};
struct ExtraPassContext
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
    int enabled;
};
struct LightConfiguration
{
    unsigned int reserved00;
    unsigned int reserved04;
    unsigned int reserved08;
    unsigned int reserved0c;
    unsigned int VirtualFunction10;
    unsigned int reserved14;
    unsigned int reserved18;
    unsigned int reserved1c;
    unsigned int reserved20;
    unsigned int VirtualFunction24;
    unsigned int VirtualFunction28;
    unsigned int reserved2c;
    unsigned int reserved30;
    unsigned int category34;
};
struct TypeInfo { const char* name; const TypeInfo* parent; };
struct DynCastHelper {
 virtual void v00(); virtual void v04(); virtual const TypeInfo* GetRTTI();
 bool IsKindOf(const void* target) { const TypeInfo* t=GetRTTI(); while(t) { if(t==target)return true; t=t->parent; } return false; }
 static DynCastHelper* DynamicCast(const void* target, DynCastHelper* object) { if (!object) return 0; return object->IsKindOf(target) ? object : 0; }
};
struct ConfigurationArg
{
    LightConfiguration* value;
};
struct ShaderPassBuilder : DynCastHelper
{
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int renderFlags;
    unsigned int propertyFlags;
    float alphaCutoff;
    unsigned int unk2c;
    unsigned int unk30;
    float fade;
    unsigned int unk38;
    RenderPassCollection* passes;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0;
    int* renderContext;
    unsigned int unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    ExtraPassContext* extraContext;
    unsigned short FUN_00af3490();
    DrawLight* FUN_00af32e0(void**);
    DrawLight* FUN_00af33d0(void**);
    ShaderPassEntry* FUN_00b5c120(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool);
    ShaderPassEntry* FUN_00b5c080(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
    void FUN_00b5b990(SceneGeometry*, DrawLight*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool);
    void FUN_00b5b760(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void FUN_00b5ba60(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void FUN_00b5ce20(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool);
    void FUN_00b5bbe0(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool);
    void FUN_00b5bce0(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool);
    void BSShaderPPLightingProperty_AddLandscapePasses_1x(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool);
    void FUN_00b5bde0(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool, bool);
    ShaderPassEntry* FUN_00b5c1b0(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
    ShaderPassEntry* FUN_00b5bf20(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
    void FUN_00b5d5b0(SceneGeometry*, unsigned short*, unsigned char, bool, bool);
    void FUN_00b5c2c0(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool);
    ShaderPassEntry* FUN_00b5bfc0(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool);
    ShaderPassEntry* AddEffectPass(SceneGeometry* geometry, unsigned short* count, unsigned char type, bool* first,
                                   bool overlay, bool effect)
    {
        FUN_00b5bfc0(geometry, count, type, first, overlay, effect);
        return 0;
    }
    __forceinline void GenerateLightingPasses(SceneGeometry* geometry, unsigned int passMask, unsigned short* count,
                                              unsigned char effectType, bool hasNoBasePass, bool addAdditional,
                                              bool basePass, bool hasNoOverlay, bool& needsShadow,
                                              bool hasRenderContext, bool needsExtraPass, bool needsNormal, bool attr0,
                                              bool attr1, bool attr2, bool opaque, bool translucent,
                                              bool blockedByEffect, bool allowFirstPass, bool specialBlend,
                                              bool hasHighFlags, bool lightingCondition, bool extraLight, bool useAlpha,
                                              bool useAlternate, DrawLight* primaryLight);
    void FUN_00b5d6d0(SceneGeometry* geometry, unsigned int passMask, unsigned short* count, int mode,
                      LightConfiguration* config, unsigned char effectType);
};
extern void* __cdecl FUN_00ad5a50();
struct DefaultRenderer
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
    DrawLight* light;
};
struct ShaderEngine
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
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    DefaultRenderer* renderer;
};
static DrawLight* GetDefaultLight()
{
    return static_cast<ShaderEngine*>(FUN_00ad5a50())->renderer->light;
}
__forceinline void ShaderPassBuilder::GenerateLightingPasses(
    SceneGeometry* geometry, unsigned int passMask, unsigned short* count, unsigned char effectType, bool hasNoBasePass,
    bool addAdditional, bool basePass, bool hasNoOverlay, bool& needsShadow, bool hasRenderContext, bool needsExtraPass,
    bool needsNormal, bool attr0, bool attr1, bool attr2, bool opaque, bool translucent, bool blockedByEffect,
    bool allowFirstPass, bool specialBlend, bool hasHighFlags, bool lightingCondition, bool extraLight, bool useAlpha,
    bool useAlternate, DrawLight* primaryLight)
{
    bool first = true;
    if (translucent || blockedByEffect)
    {
        AddEffectPass(geometry, count, effectType, &first, hasNoOverlay, blockedByEffect)->status = 6;
        return;
    }
    if ((propertyFlags & 0x40) > 0)
        FUN_00b5c080(geometry, count, effectType, &first, hasNoOverlay)->status = 7;
    unsigned short numLights = FUN_00af3490();
    if (allowFirstPass && (needsShadow || passMask == DAT_00e8ff6c))
    {
        if (!needsShadow && opaque)
            goto afterLighting;
        if (numLights >= 1 && !needsShadow)
        {
            DrawLight* light;
            void* cursor = 0;
            light = FUN_00af32e0(&cursor);
            if (!extraLight && !hasNoOverlay && !hasRenderContext)
            {
                FUN_00b5b990(geometry, primaryLight, light, count, effectType, &first, false, attr0);
            }
            else
            {
                if ((passMask & 1) != 0)
                    FUN_00b5b760(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight,
                                 hasRenderContext, attr0);
                if (primaryLight->Matches(&DAT_0108f450))
                    FUN_00b5ba60(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false, attr0);
                if (light->Matches(&DAT_0108f450))
                    FUN_00b5ba60(geometry, light, count, effectType, &first, hasNoOverlay, true, false, attr0);
            }
            for (light = FUN_00af33d0(&cursor); light; light = FUN_00af33d0(&cursor))
            {
                if (light->Matches(&DAT_0108f450))
                    FUN_00b5ba60(geometry, light, count, effectType, &first, hasNoOverlay, true, false, attr0);
            }
            FUN_00b5ce20(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, needsExtraPass,
                         needsNormal, attr0, specialBlend);
            if (basePass)
            {
                light = FUN_00af32e0(&cursor);
                if (useAlternate && primaryLight->Matches(&DAT_0108f450))
                {
                    FUN_00b5bbe0(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false,
                                 hasNoBasePass, false, attr0);
                }
                else
                {
                    FUN_00b5bbe0(geometry, light, count, effectType, &first, hasNoOverlay, true, false, hasNoBasePass,
                                 false, attr0);
                    light = FUN_00af33d0(&cursor);
                }
                while (light)
                {
                    if (light->Matches(&DAT_0108f450))
                        FUN_00b5bbe0(geometry, light, count, effectType, &first, hasNoOverlay, true, false,
                                     hasNoBasePass, false, attr0);
                    light = FUN_00af33d0(&cursor);
                }
            }
            if (addAdditional)
                FUN_00b5bce0(geometry, count, effectType, &first, hasNoOverlay, needsNormal);
        }
        else
        {
            if ((needsShadow || !useAlternate) && !attr1 && !attr2)
            {
                FUN_00b5c2c0(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight,
                             hasRenderContext, needsExtraPass, true, needsNormal, attr0);
                needsShadow = true;
            }
            else
            {
                FUN_00b5c2c0(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight,
                             hasRenderContext, needsExtraPass, false, needsNormal, attr0);
            }
            if (useAlternate && !needsShadow)
                FUN_00b5bbe0(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false,
                             hasNoBasePass, false, attr0);
            if (addAdditional)
                FUN_00b5bce0(geometry, count, effectType, &first, hasNoOverlay, needsNormal);
        }
    }
    else
    {
        if (opaque)
            goto afterLighting;
        first = true;
        if (passMask & 1)
            FUN_00b5b760(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight, hasRenderContext,
                         attr0);
        if (passMask & 2)
        {
            DrawLight* light;
            if (primaryLight->Matches(&DAT_0108f450))
                FUN_00b5ba60(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false, attr0);
            void* cursor = 0;
            for (light = FUN_00af32e0(&cursor); light; light = FUN_00af33d0(&cursor))
                if (light->Matches(&DAT_0108f450))
                    FUN_00b5ba60(geometry, light, count, effectType, &first, hasNoOverlay, true, false, attr0);
        }
        if (passMask & 4)
            FUN_00b5ce20(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, needsExtraPass,
                         needsNormal, attr0, specialBlend);
        if (basePass && (passMask & 8))
        {
            DrawLight* light;
            void* cursor = 0;
            light = FUN_00af32e0(&cursor);
            if (useAlternate && primaryLight->Matches(&DAT_0108f450))
            {
                FUN_00b5bbe0(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false,
                             hasNoBasePass, false, attr0);
                first = false;
            }
            else if (light && light->Matches(&DAT_0108f450))
            {
                FUN_00b5bbe0(geometry, light, count, effectType, &first, hasNoOverlay, true, false, hasNoBasePass,
                             false, attr0);
                light = FUN_00af33d0(&cursor);
            }
            while (light)
            {
                if (light->Matches(&DAT_0108f450))
                    FUN_00b5bbe0(geometry, light, count, effectType, &first, hasNoOverlay, true, false, hasNoBasePass,
                                 false, attr0);
                light = FUN_00af33d0(&cursor);
            }
        }
        if (addAdditional && (8 & passMask))
            FUN_00b5bce0(geometry, count, effectType, &first, hasNoOverlay, needsNormal);
    }
afterLighting:
    if (opaque)
        BSShaderPPLightingProperty_AddLandscapePasses_1x(geometry, primaryLight, count, effectType, &first, false);
    if (passMask == DAT_00e8ff6c && !needsShadow)
        FUN_00b5bde0(geometry, count, effectType, &first, hasNoOverlay, attr0, useAlpha);
    if (extraContext)
    {
        if (0 != extraContext->enabled)
            FUN_00b5c1b0(geometry, count, effectType, &first, hasNoOverlay)->status = 1;
        FUN_00b5bf20(geometry, count, effectType, &first, hasNoOverlay)->status = 1;
    }
    if (DAT_0116f212 && (passMask & 1))
        FUN_00b5d5b0(geometry, count, effectType, hasNoOverlay, hasRenderContext);
    unsigned long missingPassStatus = 0;
    if (lightingCondition)
        missingPassStatus = 10;
    else if (hasHighFlags)
        missingPassStatus = ((propertyFlags & 0x200000) > 0) ? 1 : 4;
    else if (useAlpha)
        missingPassStatus = 1;
    for (unsigned int i = 0; i < passes->size; ++i)
        if (passes->entries[i]->status == 0)
            passes->entries[i]->status = static_cast<unsigned char>(missingPassStatus);
}
// @fnv 0x00b5d6d0
// pdb: BSShaderPPLightingProperty::GetRenderPasses_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apGeom, aiEnabledPasses, asCount, auiRenderMode, apAccumulator, abUpdateList
void ShaderPassBuilder::FUN_00b5d6d0(SceneGeometry* geometry, unsigned int passMask, unsigned short* count, int mode,
                                     LightConfiguration* config, unsigned char effectType)
{
    const unsigned int initialFlags = renderFlags;
    bool hasNoBasePass;
    hasNoBasePass = (1 & initialFlags) > 0;
    bool addAdditional = (initialFlags & 0x80) > 0;
    bool basePass = hasNoBasePass;
    bool hasNoOverlay = (initialFlags & 2) > 0;
    bool needsShadow = (initialFlags & 0x20) > 0 || mode == 3;
    bool hasRenderContext = *renderContext != 0;
    bool needsExtraPass = (initialFlags & 0x400) > 0;
    bool needsNormal = false;
    if (0 != geometry->data->normalCount)
        needsNormal = true;
    needsNormal |= (propertyFlags & 0x20) > 0;
    bool attr0 = DynamicCast(&DAT_01176520, this) != 0;
    bool attr1 = DynamicCast(&DAT_0117826c, this) != 0;
    bool attr2 = DynamicCast(&DAT_01176508, this) != 0;
    const unsigned long activeFlags = renderFlags;
    bool opaque = (activeFlags & 0x4000) > 0;
    bool translucent = (activeFlags & 0x8000) > 0;
    bool blockedByEffect = (activeFlags & 0x10000) > 0;
    bool shadowPass;
    shadowPass = (activeFlags & 0x200) > 0;
    bool allowFirstPass = !((activeFlags & 0x100000) > 0) || DAT_0116ef97 != 0;
    bool specialBlend = (activeFlags & 0x40000) > 0;
    bool hasHighFlags = ((activeFlags & 0x4000000) > 0) || ((activeFlags & 0x8000000) > 0);
    bool lightingCondition;
    if ((geometry->state->flags & 1) == 0 &&
        (config->category34 == 2 || (4 & propertyFlags) > 0 || (propertyFlags & 2) > 0))
        lightingCondition = true;
    else
        lightingCondition = false;
    GeometryProperty* property = static_cast<GeometryProperty*>(geometry->FUN_00826590(0));
    bool extraLight = property && ((static_cast<unsigned char>(property->flags >> 9) & 1) != 0);
    bool useAlpha = (property && ((property->flags & 1) != 0)) || AlphaOrdered(alphaCutoff, 1.0f);
    if ((renderFlags & 0x20000) > 0)
    {
        if (DAT_0116f258 != 0.0f && DAT_0116f258 <= fade)
            addAdditional = false;
        else
            addAdditional = true;
        basePass = false;
    }
    else if (DAT_0116f250 != 0.0f && DAT_0116f250 <= fade)
    {
        addAdditional = false;
    }
    if (DAT_0116f248 != 0.0f && fade >= DAT_0116f248)
        basePass = false;
    DrawLight* primaryLight = GetDefaultLight();
    bool useAlternate = basePass && primaryLight->MatchesAlternate(&DAT_0108f450);
    if (useAlpha)
    {
        bool alphaFirst = true;
        if (shadowPass)
        {
            FUN_00b5c120(geometry, count, effectType, &alphaFirst, hasNoOverlay, extraLight);
            basePass = false;
        }
        needsShadow = true;
    }
    GenerateLightingPasses(geometry, passMask, count, effectType, hasNoBasePass, addAdditional, basePass, hasNoOverlay,
                           needsShadow, hasRenderContext, needsExtraPass, needsNormal, attr0, attr1, attr2, opaque,
                           translucent, blockedByEffect, allowFirstPass, specialBlend, hasHighFlags, lightingCondition,
                           extraLight, useAlpha, useAlternate, primaryLight);
}
}  // namespace task1307
}   // namespace f3m_00b5d6d0

// @f3 0x00b57f00 (community match, verified in this file)
extern void* DAT_0116f3d4; extern void* DAT_0116f3d8;
namespace f3m_00b57f00 {
namespace match33_b57f00 {
struct Entry { int unk00, unk04; void* value; };
struct Registry {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
Entry** entries; };
struct Geometry {
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
void** data;
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
int unke8;
int unkec;
int unkf0;
int unkf4;
int unkf8;
int unkfc;
int unk100;
int unk104;
int unk108;
struct Texture* texture; };
struct Request { int unk00,unk04,unk08; Geometry* geom; };
struct Texture { void* FUN_0047b7b0(int); };
struct GlobalRequest { int unk00,unk04,unk08; Geometry** geom; }; extern GlobalRequest* DAT_0116efd0;
struct Owner {
virtual void slot00();
virtual void slot04();
virtual void slot08();
virtual void slot0c();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1c();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2c();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3c();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4c();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5c();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6c();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7c();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8c();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9c();
virtual void slota0();
virtual void slota4();
virtual void slota8();
virtual void slotac();
virtual void slotb0();
virtual void slotb4();
virtual void slotb8();
virtual void slotbc();
virtual void slotc0();
virtual void slotc4();
virtual void slotc8();
virtual void slotcc();
virtual void slotd0();
virtual void slotd4();
virtual void slotd8();
virtual void slotdc();
virtual void slote0();
virtual void slote4();
virtual void slote8();
virtual void slotec();
virtual void slotf0();
virtual void slotf4();
virtual void slotf8();
virtual void slotfc();
virtual void slot100();
virtual void slot104();
virtual void Finish();
void* FUN_00b85ce0(Geometry*,int);
void FUN_00b57f00(Request*);
};
void Owner::FUN_00b57f00(Request* req) {
 Geometry* geom=req->geom;
 Registry* registry=reinterpret_cast<Registry*>(::DAT_01091980);
 unsigned int mode=DAT_0116efd4;
 switch(mode) {
case 126:
case 304:
case 305:
case 311:
case 323:
case 344:
case 345:
case 351:
case 357:
case 363:
case 369:
case 375:
{ Entry* target=registry->entries[0]; target->value=FUN_00b85ce0(geom,0); } break;
case 122:
case 123:
case 159:
case 170:
case 181:
case 192:
case 223:
case 232:
case 241:
case 250:
case 264:
case 276:
case 287:
case 298:
registry->entries[0]->value=*geom->data;
{ Entry* target=registry->entries[1]; target->value=FUN_00b85ce0(geom,0); } break;
case 337:
case 564:
registry->entries[0]->value=*geom->data;break;
}
switch(mode) {
case 232:
case 250:
registry->entries[5]->value=DAT_0116f3d4;
registry->entries[6]->value=DAT_0116f3d8;
break;
case 170:
case 192:
case 276:
case 298:
registry->entries[6]->value=DAT_0116f3d4;
registry->entries[7]->value=DAT_0116f3d8;
break;
case 357:
registry->entries[1]->value=DAT_0116f3d4;
registry->entries[2]->value=DAT_0116f3d8;
break;
}
if(mode==0x234) { Entry* target=registry->entries[6]; target->value=(*DAT_0116efd0->geom)->texture->FUN_0047b7b0(0); }
Finish();
}
}
}   // namespace f3m_00b57f00

// @f3 0x00b449a0 (community match, verified in this file)
extern const char* DAT_01177ce8;
namespace f3m_00b449a0 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00b2b9f0(ViewerStrings* strings);
    void FUN_00b449a0(ViewerStrings* strings);
};

// pdb: BoltShaderProperty::GetViewerStrings | BoltShaderProperty.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apStrings
void Owner::FUN_00b449a0(ViewerStrings* strings)
{
    FUN_00b2b9f0(strings);
    strings->Add(FUN_00847b50(DAT_01177ce8));
}
}   // namespace f3m_00b449a0

// @f3 0x00b46b00 (community match, verified in this file)
extern const char* DAT_01177d38;
namespace f3m_00b46b00 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_008d1230(ViewerStrings* strings);
    void FUN_00b46b00(ViewerStrings* strings);
};

// pdb: BSRefractionFirePeriodController::GetViewerStrings | BSRefractionFirePeriodController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Owner::FUN_00b46b00(ViewerStrings* strings)
{
    FUN_008d1230(strings);
    strings->Add(FUN_00847b50(DAT_01177d38));
}
}   // namespace f3m_00b46b00

// @f3 0x00b46df0 (community match, verified in this file)
extern const char* DAT_01177d44;
namespace f3m_00b46df0 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_008d1230(struct ViewerStrings* strings);

struct ViewerStrings
{
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

void __stdcall FUN_00b46df0(ViewerStrings* strings)
{
    FUN_008d1230(strings);
    strings->Add(FUN_00847b50(DAT_01177d44));
}
}   // namespace f3m_00b46df0

// @f3 0x00b51f80 (community match, verified in this file)
namespace f3m_00b51f80 {
struct FUN_00b51f80_child {
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
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
};

struct FUN_00b71b90_class {
    void FUN_00b71b90();
};

struct FUN_00b51f80_cls {
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
    FUN_00b51f80_child* unk8C[26];
    FUN_00b51f80_child* unkF4[13];
    void FUN_00b51f80();
};

// pdb: SkinShader::RecreateRendererData | SkinShader.obj | fnv360_0822_retail, objrun_open, medium
void FUN_00b51f80_cls::FUN_00b51f80()
{
    FUN_00b51f80_child** slot = unk8C;
    int n = 26;
    do {
        FUN_00b51f80_child* c = *slot;
        if (c)
            c->vf40();
        ++slot;
    } while (--n);

    slot = unkF4;
    n = 13;
    do {
        FUN_00b51f80_child* c = *slot;
        if (c)
            c->vf34();
        ++slot;
    } while (--n);

    reinterpret_cast<FUN_00b71b90_class*>(this)->FUN_00b71b90();
}
}   // namespace f3m_00b51f80

// @f3 0x00b46aa0 (community match, verified in this file)
namespace f3m_00b46aa0 {
void* FUN_0089eb90(unsigned int size);

struct A4F820Controller {
    virtual ~A4F820Controller();
    A4F820Controller();
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
};

struct FUN_00b46aa0_cls : A4F820Controller {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b46aa0_cls() {}
    virtual ~FUN_00b46aa0_cls() {}
};

void* FUN_00b46aa0()
{
    return new FUN_00b46aa0_cls();
}
}   // namespace f3m_00b46aa0

// @f3 0x00b46d90 (community match, verified in this file)
namespace f3m_00b46d90 {
void* FUN_0089eb90(unsigned int size);

struct A4F820Controller {
    virtual ~A4F820Controller();
    A4F820Controller();
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
};

struct FUN_00b46d90_cls : A4F820Controller {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b46d90_cls() {}
    virtual ~FUN_00b46d90_cls() {}
};

void* FUN_00b46d90()
{
    return new FUN_00b46d90_cls();
}
}   // namespace f3m_00b46d90

// @f3 0x00b46a20 (community match, verified in this file)
namespace f3m_00b46a20 {
void* FUN_0089eb90(unsigned int size);

struct A4F820Controller {
    virtual ~A4F820Controller();
    A4F820Controller();
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
};

struct FUN_00b46a20_obj : A4F820Controller {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b46a20_obj() {}
    virtual ~FUN_00b46a20_obj() {}
};

struct NiNew;
class CloningProcess;

struct Holder {
    void Copy(NiNew* dst, CloningProcess* process);
    NiNew* FUN_00b46a20(CloningProcess* process);
};

NiNew* Holder::FUN_00b46a20(CloningProcess* process)
{
    NiNew* copy = reinterpret_cast<NiNew*>(new FUN_00b46a20_obj());
    Copy(copy, process);
    return copy;
}
}   // namespace f3m_00b46a20

// @f3 0x00b46d10 (community match, verified in this file)
namespace f3m_00b46d10 {
void* FUN_0089eb90(unsigned int size);

struct A4F820Controller {
    virtual ~A4F820Controller();
    A4F820Controller();
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
};

struct FUN_00b46d10_obj : A4F820Controller {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b46d10_obj() {}
    virtual ~FUN_00b46d10_obj() {}
};

struct NiNew;
class CloningProcess;

struct Holder {
    void Copy(NiNew* dst, CloningProcess* process);
    NiNew* FUN_00b46d10(CloningProcess* process);
};

NiNew* Holder::FUN_00b46d10(CloningProcess* process)
{
    NiNew* copy = reinterpret_cast<NiNew*>(new FUN_00b46d10_obj());
    Copy(copy, process);
    return copy;
}
}   // namespace f3m_00b46d10

// @f3 0x00b46360 (community match, verified in this file)
namespace f3m_00b46360 {
void* FUN_0089eb90(unsigned int size);

struct SpawnedObject {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    SpawnedObject();
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
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
};

// pdb: BSOrderedNode::CreateObject | BSOrderedNode.obj | fnv360_0721_beta, objrun_sim, low
SpawnedObject* FUN_00b46360()
{
    return new SpawnedObject();
}
}   // namespace f3m_00b46360

// @f3 0x00b46fa0 (community match, verified in this file)
namespace f3m_00b46fa0 {
void* FUN_0089eb90(unsigned int size);

struct FUN_00b46e90_cls {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b46e90_cls();
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
};

// pdb: VolumetricFogShaderProperty::CreateObject | VolumetricFogShaderProperty.obj | fnv360_0822_retail, objrun, low, conflict (bridge: VolumetricFogShaderProperty::CreateClone)
FUN_00b46e90_cls* FUN_00b46fa0()
{
    return new FUN_00b46e90_cls();
}
}   // namespace f3m_00b46fa0

// @f3 0x00b47a30 (community match, verified in this file)
namespace f3m_00b47a30 {
void* FUN_0089eb90(unsigned int size);

struct FUN_00b472a0_cls {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b472a0_cls();
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
};

// pdb: HairShaderProperty::CreateObject | HairShaderProperty.obj | fnv360_0721_beta, objrun_prop, low
FUN_00b472a0_cls* FUN_00b47a30()
{
    return new FUN_00b472a0_cls();
}
}   // namespace f3m_00b47a30

// @f3 0x00b440d0 (community match, verified in this file)
namespace f3m_00b440d0 {
void* FUN_0089eb90(unsigned int size);

struct BB0ED0CloningProcess;

struct BB0ED0Base {
    void CopyMemberData(BB0ED0Base* dst, BB0ED0CloningProcess& process);
    BB0ED0Base* FUN_00b440d0(BB0ED0CloningProcess& process);
};

struct FUN_00b43df0_stand {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    FUN_00b43df0_stand();
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
};

BB0ED0Base* BB0ED0Base::FUN_00b440d0(BB0ED0CloningProcess& process)
{
    BB0ED0Base* copy = reinterpret_cast<BB0ED0Base*>(new FUN_00b43df0_stand());
    CopyMemberData(copy, process);
    return copy;
}
}   // namespace f3m_00b440d0

// @f3 0x00b47040 (community match, verified in this file)
extern int DAT_0126bea0;
extern const char* const DAT_010babec;
namespace f3m_00b47040 {
char* __cdecl FUN_00847b50(const char* label);

struct ViewerStrings_b47040
{
    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }
};

struct ViewerColor_b47040
{
    char* FUN_0083f9c0(const char* label);
    float r, g, b, a;
};

struct Owner_b47040
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    ViewerColor_b47040 color60;
    void FUN_00b2b9f0(ViewerStrings_b47040* strings);
    void VolumetricFogShaderProperty_GetViewerStrings(ViewerStrings_b47040* strings);
};

// pdb: VolumetricFogShaderProperty::GetViewerStrings | VolumetricFogShaderProperty.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel), high
void Owner_b47040::VolumetricFogShaderProperty_GetViewerStrings(ViewerStrings_b47040* strings)
{
    FUN_00b2b9f0(strings);
    strings->Add(FUN_00847b50((const char*)DAT_0126bea0));
    strings->Add(color60.FUN_0083f9c0((const char*)&DAT_010babec));
}
}   // namespace f3m_00b47040

// @f3 0x00b44150 (community match, verified in this file)
extern "C" double __cdecl sqrt(double);

class NiPoint3 { public: float x, y, z; };
extern const NiPoint3 DAT_0108ec68;
extern "C" int __cdecl rand(void);
extern "C" double __cdecl fabs(double);


inline void BoltScale(float& x,float& y,double s) { x*=s;y*=s; }
struct BoltDirection : public NiPoint3 {
    void FUN_00468d00();
};

struct Point4 { float x,y,z,w; };
struct ShellBC_00b44150 {
 int unk0;
 int unk4;
 int unk8;
 int unkc;
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
 Point4* points;
 float unk64;
 int unk68;
 float unk6c;
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
 int unke8;
 int unkec;
 int unkf0;
 int unkf4;
 int unkf8;
 int unkfc;
 int unk100;
 int unk104;
 int unk108;
 int unk10c;
 int unk110;
 int unk114;
 int unk118;
 int unk11c;
 int unk120;
 int unk124;
 int unk128;
 int unk12c;
 float unk130;
 float unk134;
 int unk138;
 int unk13c;
 int unk140;
 float unk144;
 float unk148;
 void FUN_00b44150(int row,int col,int previous,int next);
};

// pdb: BoltShaderProperty::CreateSegment | BoltShaderProperty.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiBolt, aiSegment, aiLastSegment, aiLookBackSegment
void ShellBC_00b44150::FUN_00b44150(int row,int col,int previous,int next) {
 int index=row*unk140+col;
 Point4 a=points[row*unk140+previous];
 int width=unk140;
 Point4 b=points[row*width+next];
 BoltDirection dir;
 dir.x=a.x-b.x; dir.y=a.y-b.y; dir.z=a.z-b.z;
 if(dir.y<0.0f) static_cast<NiPoint3&>(dir)=DAT_0108ec68;
 dir.y+=1.0;
 dir.FUN_00468d00();
 float speed=unk144;
 dir.x*=speed;dir.y*=speed;dir.z*=speed;
 float ratio=(float)col/width;
 float random=(float)(rand()/32767.0);
 points[index].x=(float)(dir.x+a.x+unk148*random-unk148*0.5);
 points[index].y=dir.y+a.y;
 random=(float)(rand()/32767.0);
 points[index].z=(float)(dir.z+a.z+unk148*random-unk148*0.5);
 dir.x=unk64*ratio-points[index].x;
 dir.y=unk6c*ratio-points[index].z;
 float root=(float)sqrt((float)(dir.x*dir.x+dir.y*dir.y));
 float len=root;
 if(len>unk130) {
  double delta=len-unk130;
  double length=len;
  double scale=(float)(unk134*delta/length);
  if((float)fabs((float)(scale*length))>unk130) scale=(float)(delta/length);
  BoltScale(dir.x,dir.y,scale);
  points[index].x+=dir.x;points[index].z+=dir.y;
 }
}

// @f3 0x00b468a0 (community match, verified in this file)
extern char* DAT_01177d2c;
namespace f3m_00b468a0 {
struct FUN_00b468a0_Param {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;

    void FUN_00555790(unsigned int value);
    void FUN_005b3880(unsigned int value, char*& result);
};

void __stdcall FUN_008d1230(FUN_00b468a0_Param* param);
char* __cdecl FUN_00847b50(char* value);


// pdb: BSMaterialEmittanceMultController::GetViewerStrings | BSMaterialEmittanceMultController.obj | fnv360_0721_retail, objrun_open, low
// pdb params: pkStrings
void __stdcall FUN_00b468a0(FUN_00b468a0_Param* object) {
    FUN_008d1230(object);
    char* str = FUN_00847b50(DAT_01177d2c);

    unsigned int size = object->unk0A;

    if (size >= object->unk08)
        object->FUN_00555790(size + object->unk0E);

    object->FUN_005b3880(size, str);
}
}   // namespace f3m_00b468a0

// @f3 0x00b46730 (community match, verified in this file)
extern const float DAT_01096324;
namespace f3m_00b46730 {
namespace f3m_00b46730 {
struct Values
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    float m_fValue;
    int m_iCount;
};
struct Target
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual bool Interpolate(float time, Values* values, float* result);
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual bool IsActive();
};
}

struct f3m_00b46730_Controller
{
    void* unk00;
    int unk04;
    unsigned short m_uiObjectFlags;
    unsigned short unk0a;
    int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
    float m_fTime;
    f3m_00b46730::Values* m_pValues;
    int unk30;
    f3m_00b46730::Target* m_pTarget;

    unsigned char GetMC() const { return (m_uiObjectFlags >> 5) & 1; }
    bool FUN_008b0270(float time);
    void FUN_00b46730(const float& time);
};

// pdb: BSMaterialEmittanceMultController::Update | BSMaterialEmittanceMultController.obj | fnv360_0721_retail, objrun_open, low
// pdb params: UpdateData
void f3m_00b46730_Controller::FUN_00b46730(const float& time)
{
    if (GetMC())
    {
        m_fTime = DAT_01096324;
    }
    else if (FUN_008b0270(time) && (!m_pTarget || !m_pTarget->IsActive()))
    {
        return;
    }
    if (m_pTarget)
    {
        float result;
        if (m_pTarget->Interpolate(m_fTime, m_pValues, &result))
        {
            f3m_00b46730::Values* p = m_pValues;
            p->m_fValue = result;
            p->m_iCount++;
        }
    }
}
}   // namespace f3m_00b46730

// @f3 0x00b46840 (community match, verified in this file)
extern int DAT_00ea13b0;
namespace f3m_00b46840 {
void* FUN_0089eb90(unsigned int size);


struct NiFloatInterpController
{
    NiFloatInterpController();
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
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};

struct __declspec(novtable) Derived46840 : public NiFloatInterpController
{
    Derived46840() { *(int**)this = &DAT_00ea13b0; }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};

// pdb: BSMaterialEmittanceMultController::CreateObject | BSMaterialEmittanceMultController.obj | fnv360_0721_retail, objopen_prop, low
Derived46840* __cdecl FUN_00b46840()
{
    return new Derived46840();
}
}   // namespace f3m_00b46840

// @f3 0x00b467c0 (community match, verified in this file)
extern int DAT_00ea13b0;
namespace f3m_00b467c0 {
void* FUN_0089eb90(unsigned int size);


struct NiFloatInterpController
{
    NiFloatInterpController();
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
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};

struct __declspec(novtable) Derived467c0 : public NiFloatInterpController
{
    Derived467c0() { *(int**)this = &DAT_00ea13b0; }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};

struct Owner467c0
{
    void FUN_008d1800(void* obj, int arg);
    Derived467c0* FUN_00b467c0(int arg);
};

// pdb: BSMaterialEmittanceMultController::CreateClone | BSMaterialEmittanceMultController.obj | fnv360_0721_retail, objopen_prop, low
// pdb params: kCloning
Derived467c0* Owner467c0::FUN_00b467c0(int arg)
{
    Derived467c0* p = new Derived467c0();
    FUN_008d1800(p, arg);
    return p;
}
}   // namespace f3m_00b467c0

// @f3 0x00b47aa0 (community match, verified in this file)
namespace f3m_00b47aa0 {
void* operator new(unsigned int size)
{
    return f3_0262::FUN_0089eb90(size);
}

struct FUN_00b47aa0_owner
{
    void FUN_00b474a0(fo3_b472a0::FUN_00b472a0* obj, int arg);
    fo3_b472a0::FUN_00b472a0* FUN_00b47aa0(int arg);
};

// pdb: HairShaderProperty::CreateClone | HairShaderProperty.obj | fnv360_0721_beta, objrun, low, conflict (skyrim: BSLightingShaderMaterialMultiLayerParallax::CopyMembers)
// pdb params: arCloneData
fo3_b472a0::FUN_00b472a0* FUN_00b47aa0_owner::FUN_00b47aa0(int arg)
{
    f3_0262::MemContextGuard guard(0x28);
    fo3_b472a0::FUN_00b472a0* obj = new fo3_b472a0::FUN_00b472a0();
    FUN_00b474a0(obj, arg);
    return obj;
}
}   // namespace f3m_00b47aa0

// @f3 0x00b42bd0 (community match, verified in this file)
extern int DAT_0116efb0;
extern unsigned int DAT_01177cd0;
namespace f3m_00b42bd0 {

// pdb: BoltShader::GetMaxSegments | BoltShader.obj | fnv360_0822_retail, call_gap, medium
unsigned int __cdecl FUN_00b42bd0()
{
    unsigned int v = DAT_01177cd0;
    if (v == 0)
    {
        v = DAT_0116efb0 < 2;
        v = (v - 1 & 0xa0) + 0x4b;
        DAT_01177cd0 = v;
    }
    return v;
}
}   // namespace f3m_00b42bd0

// @f3 0x00b5c1b0 (community match, verified in this file)
namespace f3m_00b5c1b0 {
struct SceneGeometry;
struct ShaderPassEntry;
struct RenderPassSink {
    void FUN_00b2c0b0(SceneGeometry*, unsigned short, bool, unsigned char,
                     void*, void*, void*, void*);
};
struct ShaderSelector {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    RenderPassSink* passes;
    ShaderPassEntry* FUN_00b5c1b0(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
};
// pdb: BSShaderPPLightingProperty::AddZOnlyTextureEffectPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned
ShaderPassEntry* ShaderSelector::FUN_00b5c1b0(SceneGeometry* geometry, unsigned short* count,
 unsigned char type, bool* first, bool overlay) {
 if (overlay) {
  if (type == 1) {
   passes->FUN_00b2c0b0(geometry, 5, *first, 0, 0, 0, 0, 0);
   *first = false;
   return 0;
  } else {
   ++*count;
   *first = false;
   return 0;
  }
 } else {
  if (type == 1) {
   passes->FUN_00b2c0b0(geometry, 4, *first, 0, 0, 0, 0, 0);
   *first = false;
   return 0;
  } else {
   ++*count;
   *first = false;
   return 0;
  }
 }
}
}   // namespace f3m_00b5c1b0

// @f3 0x00b5e2e0 (community match, verified in this file)
namespace f3m_00b5e2e0 {

struct PassArray {
    void FUN_00b2c0b0(void* geom, unsigned short pass, unsigned char enabled, unsigned char lights, void* l0, void* l1, void* l2, void* l3);
};

struct Holder {
    int FUN_00b5e2e0(void* geom, unsigned short* counter, unsigned char flag, unsigned char* enabled, unsigned char outer);
};

// pdb: BSShaderPPLightingProperty::AddTextureEffectPass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned
int Holder::FUN_00b5e2e0(void* geom, unsigned short* counter, unsigned char flag, unsigned char* enabled, unsigned char outer)
{
    if (outer != 0)
    {
        if (flag == 1)
        {
            unsigned char value = *enabled;
            void* geom2 = geom;
            PassArray* array = *(PassArray**)((unsigned char*)this + 0x3c);
            array->FUN_00b2c0b0(geom2, 0x251, value, 0, 0, 0, 0, 0);
            *enabled = 0;
        }
        else
        {
            ++(*counter);
            *enabled = 0;
        }
    }
    else
    {
        if (flag == 1)
        {
            unsigned char value = *enabled;
            void* geom2 = geom;
            PassArray* array = *(PassArray**)((unsigned char*)this + 0x3c);
            array->FUN_00b2c0b0(geom2, 0x250, value, 0, 0, 0, 0, 0);
            *enabled = 0;
        }
        else
        {
            ++(*counter);
            *enabled = 0;
        }
    }
    return 0;
}
}   // namespace f3m_00b5e2e0

// @f3 0x00b46c30 (community match, verified in this file)
namespace f3m_00b46c30 {
namespace f3m_00b46c30 {
void* __cdecl FUN_0089eb90(unsigned int size);

struct RefObj_b46c30 {
    virtual ~RefObj_b46c30();
    virtual void DeleteThis();
    volatile long m_uiRefCount;

    __forceinline void IncRefCount() {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount() {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct Stream_b46c30 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    unsigned int version;
    void* FUN_0082a280();
};
}

class A42D00Interpolator : public f3m_00b46c30::RefObj_b46c30 {
public:
    static void* operator new(unsigned int size) { return f3m_00b46c30::FUN_0089eb90(size); }
    static void operator delete(void* p);
    A42D00Interpolator(void* data);

    virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void Collapse();

    int unk08, unk0c, unk10, unk14;
};

namespace f3m_00b46c30 {
struct Controller_b46c30 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    NiPointer<A42D00Interpolator> m_spInterpolator;

    void FUN_008d1310(Stream_b46c30& stream);
    void FUN_00b46c30(Stream_b46c30& stream);
};

void Controller_b46c30::FUN_00b46c30(Stream_b46c30& stream)
{
    FUN_008d1310(stream);
    if (stream.version < 0x0A010068) {
        void* data = stream.FUN_0082a280();
        m_spInterpolator = new A42D00Interpolator(data);
        m_spInterpolator->Collapse();
    }
}
}
}   // namespace f3m_00b46c30

// @f3 0x00b45cf0 (community match, verified in this file)
namespace f3m_00b45cf0 {
namespace f3m_00b45cf0 {
struct Elem16 {
    int unk00;
    int unk04;
    float f08;
    float f0c;
};

struct Owner {
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
    unsigned short count;
    Elem16* arr10;
    int* arr14;

    void FUN_00b459e0();
    void FUN_00b45cf0();
};

// pdb: NiTListBase<NiTPointerAllocator<unsigned int>,DistantLODGroup *>::AddNodeTail | DistantLODShaderProperty.obj | fnv360_0822_debug, objrun_open, low
// pdb params: pkNode
void Owner::FUN_00b45cf0()
{
    for (int i = 0; i < count; ++i) {
        arr10[i].f08 = 0.0f;
        arr10[i].f0c = 0.0f;
        arr14[i] = 0;
    }
    count = 0;
    FUN_00b459e0();
}
}
}   // namespace f3m_00b45cf0

// @f3 0x00b46e90 (community match, verified in this file)
extern int DAT_00ea1680;
extern int DAT_011a9be0;
extern int DAT_011a9be4;
extern int DAT_011a9be8;
namespace f3m_00b46e90 {
class BlobBase_cls {
public:
    BlobBase_cls();
    virtual ~BlobBase_cls();
protected:
    unsigned int field04, field08, field0c, field10, field14, field18, field1c;
    unsigned int field20, field24, field28, field2c, field30, field34, field38, field3c;
    unsigned int field40, field44, field48, field4c, field50, field54, field58, field5c;
};
namespace f3m_00b46e90 {
struct Color4 {
    float r, g, b, a;
    Color4() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
};
struct __declspec(novtable) Base : public BlobBase_cls {
    Base() { *(int**)this = &DAT_00ea1680; }
};
class __declspec(novtable) FUN_00b46e90 : public Base {
public:
    FUN_00b46e90();
    Color4 color;
};
// pdb: VolumetricFogShaderProperty::VolumetricFogShaderProperty | VolumetricFogShaderProperty.obj | fnv360_0822_retail, call_gap, medium
FUN_00b46e90::FUN_00b46e90() {
    *(int*)&color.r = DAT_011a9be0;
    *(int*)&color.g = DAT_011a9be4;
    *(volatile int*)&color.b = DAT_011a9be8;
    *(volatile float*)&color.a = 100.0f;
    field1c = 0x15;
}
}
}   // namespace f3m_00b46e90

// @f3 0x00b4c3b0 (community match, verified in this file)
namespace UpdateB4c3b0 {
struct Source {
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
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void* getData();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual int getValue();
};
struct Arg {int unk00,unk04,unk08;Source* source;};
struct Target {int unk00,unk04;void* data;void FUN_0088f050(int);void FUN_0088fcc0(int);};
struct Link {Target* target;};
struct Manager {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;Link* link;};
extern Manager* DAT_01091980;
// pdb: SpeedTreeLeafShader::SetupGeometryTextures | SpeedTreeLeafShader.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apState
void __stdcall FUN_00b4c3b0(Arg* arg) {
 Target* target=DAT_01091980->link->target;
 if(target) {
 Source* source=arg->source;
 void* data=source->getData();
 if(data) {
 target->data=data;
 target->FUN_0088f050(source->getValue());
 target->FUN_0088fcc0(0);
 }
 }
}
}

// @f3 0x00b4eaf0 (community match, verified in this file)
namespace DispatchB4eaf0 {
struct First {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;void* data;};
struct Second {int unk00;void* data;int unk08,unk0c,unk10,unk14,unk18,unk1c;unsigned short count;};
struct Engine {void FUN_00874f80(First*,void*,int,int,int);};
extern Engine* DAT_0116f2f8;
struct Dispatch {
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
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void dispatch(void*,void*,unsigned,int,void*);
};
struct Manager {
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
Dispatch* dispatcher;
};
extern Manager* DAT_01091980;
struct Object {
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
int busy;
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
void* resource;
int FUN_00b4eaf0(void*,First*,Second*,void*,void*,void*,void*,void*);
};
// pdb: GeometryDecalShader::SetupBoneMatrices | GeometryDecalShader.obj | fnv360_0822_retail, objrun, medium
// pdb params: apGeometry, apSkin, apPartition, apBuffData, apState, apEffects, aWorld, aWorldBound
int Object::FUN_00b4eaf0(void* a,First* first,Second* second,void* d,void* e,void* f,void* context,void* h) {
 if(first && second && !busy && resource) {
 DAT_0116f2f8->FUN_00874f80(first,context,0,3,1);
 DAT_01091980->dispatcher->dispatch(resource,first->data,second->count,3,second->data);
 }
 return 0;
}
}

// @f3 0x00b5bbe0 (community match, verified in this file)
namespace f3m_00b5bbe0 {
namespace f3m_00b5bbe0 {
struct NiGeometry;
struct ShadowSceneLight;
struct PassArray { void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*); };
struct ShaderOneLightSelector
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
    PassArray* passes;

    __forceinline void RegisterPass(NiGeometry* geometry, ShadowSceneLight* light, unsigned short* count,
                                    unsigned char type, bool* first, unsigned short pass)
    {
        if (type == 1)
            passes->FUN_00b2c0b0(geometry, pass, *first, 1, light, 0, 0, 0);
        else
            ++*count;
    }

    int FUN_00b5bbe0(NiGeometry* geometry, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                     bool* first, bool a, bool b, bool c, bool d, bool e, bool f);
};

// pdb: BSShaderPPLightingProperty::AddSpecularPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, apLight, asCount, abUpdateList, abFirst, abSkinned, abPointLight, abMultitexture, abBaseSpecular, abDecalSpecular, abTreeBranch
int ShaderOneLightSelector::FUN_00b5bbe0(NiGeometry* geometry, ShadowSceneLight* light, unsigned short* count,
                                         unsigned char type, bool* first, bool a, bool b, bool c, bool d, bool e,
                                         bool f)
{
    if (!a) {
        if (!b)
            RegisterPass(geometry, light, count, type, first, 0x154);
        else
            RegisterPass(geometry, light, count, type, first, 0x155);
    } else {
        if (!b)
            RegisterPass(geometry, light, count, type, first, 0x156);
        else
            RegisterPass(geometry, light, count, type, first, 0x157);
    }
    *first = false;
    return 0;
}
}
}   // namespace f3m_00b5bbe0

// @f3 0x00b474a0 (community match, verified in this file)
namespace f3m_00b474a0 {
namespace Copyb474a0 {
struct Ref {virtual void v00();virtual void destroy();long refs;};struct Data {unsigned a,b,c,d;};extern long (__stdcall* DAT_00d9b064)(volatile long*);extern long (__stdcall* DAT_00d9b068)(volatile long*);
struct Object {int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; Data data;Ref* ref;void FUN_00ae99b0(Object*,int);void FUN_00b474a0(Object*,int);};
void Object::FUN_00b474a0(Object* dst,int value){FUN_00ae99b0(dst,value);Ref* old=dst->ref;if(old!=ref){if(old&&!DAT_00d9b064(&old->refs))old->destroy();Ref* incoming=ref;dst->ref=incoming;if(incoming)DAT_00d9b068(&incoming->refs);}dst->data=data;}
}

}   // namespace f3m_00b474a0

// @f3 0x00b46f10 (community match, verified in this file)
namespace f3m_00b46f10 {
namespace Clone284 {
void* FUN_0089eb90(unsigned);
struct Data {int a,b,c,d;};
struct FUN_00b46e90 {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;Data data;FUN_00b46e90();static void* operator new(unsigned n){return FUN_0089eb90(n);}static void operator delete(void*);};
struct Object {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;Data data;void FUN_00b2ad60(FUN_00b46e90*,int);FUN_00b46e90* FUN_00b46f10(int);};
// pdb: VolumetricFogShaderProperty::CreateClone | VolumetricFogShaderProperty.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
FUN_00b46e90* Object::FUN_00b46f10(int mode){FUN_00b46e90* clone=new FUN_00b46e90;FUN_00b2ad60(clone,mode);clone->data=data;return clone;}
}
}   // namespace f3m_00b46f10

// @f3 0x00b5bce0 (community match, verified in this file)
namespace f3m_00b5bce0 {
namespace f3m_00b5bce0 {

struct PassArray {
    void FUN_00b2c0b0(void* geom, unsigned short pass, bool enabled, unsigned char lights, void* l0, void* l1, void* l2, void* l3);
};

struct Holder {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    PassArray* array;
    int FUN_00b5bce0(void* geom, unsigned short* counter, unsigned char flag, bool* enabled, bool outer, bool inner);
};

// pdb: BSShaderPPLightingProperty::AddEnvmapPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned, abVertexColors
int Holder::FUN_00b5bce0(void* geom, unsigned short* counter, unsigned char flag, bool* enabled, bool outer, bool inner)
{
    if (!outer)
    {
        if (!inner)
        {
            if (flag == 1)
                array->FUN_00b2c0b0(geom, 0x244, *enabled, 0, 0, 0, 0, 0);
            else
                ++(*counter);
        }
        else
        {
            if (flag == 1)
                array->FUN_00b2c0b0(geom, 0x245, *enabled, 0, 0, 0, 0, 0);
            else
                ++(*counter);
        }
    }
    else
    {
        if (!inner)
        {
            if (flag == 1)
                array->FUN_00b2c0b0(geom, 0x246, *enabled, 0, 0, 0, 0, 0);
            else
                ++(*counter);
        }
        else
        {
            if (flag == 1)
                array->FUN_00b2c0b0(geom, 0x247, *enabled, 0, 0, 0, 0, 0);
            else
                ++(*counter);
        }
    }
    *enabled = false;
    return 0;
}

}
}   // namespace f3m_00b5bce0

// @f3 0x00b5bf20 (community match, verified in this file)
namespace f3m_00b5bf20 {
struct NiGeometry;
struct ShadowSceneLight;
struct ShaderPassEntry;
struct PassList
{
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                      ShadowSceneLight*, ShadowSceneLight*);
};
struct Shader_00b5bf20
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
    PassList* passes;

    ShaderPassEntry* FUN_00b5bf20(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool flag);
};

// pdb: BSShaderPPLightingProperty::AddTextureEffectPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned
ShaderPassEntry* Shader_00b5bf20::FUN_00b5bf20(NiGeometry* geom, unsigned short* count, unsigned char type,
                                               bool* enabled, bool flag)
{
    if (flag)
    {
        if (type == 1)
        {
            passes->FUN_00b2c0b0(geom, 0x24f, *enabled, 0, 0, 0, 0, 0);
            *enabled = false;
            return 0;
        }
        else
        {
            ++*count;
            *enabled = false;
            return 0;
        }
    }
    else
    {
        if (type == 1)
        {
            passes->FUN_00b2c0b0(geom, 0x24e, *enabled, 0, 0, 0, 0, 0);
            *enabled = false;
            return 0;
        }
        else
        {
            ++*count;
            *enabled = false;
            return 0;
        }
    }
}
}   // namespace f3m_00b5bf20

// @f3 0x00b5b2b0 (community match, verified in this file)
namespace f3m_00b5b2b0 {
namespace f3m_00b5b2b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObject
{
    virtual void Unused() = 0;
    virtual void DeleteThis() = 0;
    long m_uiRefCount;
};

struct RefPtr
{
    RefObject* object;
    void Clear()
    {
        RefObject* old = object;
        if (old)
        {
            if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                old->DeleteThis();
            object = 0;
        }
    }
};

struct ShaderState
{
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110;
    int state;
    RefPtr passes[6];
    RefPtr extra;
    void Idle() {}
    void FUN_00b5a5c0();
    void FUN_00b5a9b0(int arg);
    void FUN_00b5b2b0(int arg);
};

// pdb: BSCubeMapCamera::Click | BSCubeMapCamera.obj | fnv360_1110_retail, caller_sim, medium
// pdb params: aiFace
void ShaderState::FUN_00b5b2b0(int arg)
{
    switch (state)
    {
    case 0:
        FUN_00b5a5c0();
        break;
    case 1:
        Idle();
        break;
    case 2:
        Idle();
        break;
    case 3:
        FUN_00b5a9b0(arg);
        break;
    }
    extra.Clear();
    for (int i = 0; i < 6; i++)
        passes[i].Clear();
}
}
}   // namespace f3m_00b5b2b0

// @f3 0x00b59570 (community match, verified in this file)
#include <string.h>
namespace f3m_00b59570 {
namespace f3m_00b59570 {

struct Target00b59570 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags24;
    int unk28, unk2c, unk30, unk34;
    int unk38;
};

inline void SetFlag(unsigned int& flags, int& counter, unsigned int mask, bool on)
{
    if (on) {
        if (!(flags & mask)) counter = 0;
        flags |= mask;
    } else {
        if (flags & mask) counter = 0;
        flags &= ~mask;
    }
}

struct O00b59570 {
    int unk00, unk04, unk08;
    Target00b59570* unk0c;
    int unk10, unk14, unk18;
    char name1c[0x1c];
    bool b38;
    bool b39;
    bool b3a;
    void FUN_00b59570(const char* name);
};

// pdb: NiPointer<TallGrassShaderProperty>::operator= | TallGrassGroup.obj | fnv360_0721_beta, objrun, low, conflict (bridge: TallGrassGroup::SetGrassParam)
// pdb params: pObject
void O00b59570::FUN_00b59570(const char* name)
{
    if (name) memmove(name1c, name, 0x20);
    SetFlag(unk0c->flags24, unk0c->unk38, 0x400, b38);
    SetFlag(unk0c->flags24, unk0c->unk38, 0x800, b39);
    SetFlag(unk0c->flags24, unk0c->unk38, 0x1000, b3a);
}
}
}   // namespace f3m_00b59570

// @f3 0x00b5bfc0 (community match, verified in this file)
namespace f3m_00b5bfc0 {
namespace Select394 {
struct Passes { void FUN_00b2c0b0(void*,unsigned short,bool,unsigned char,void*,void*,void*,void*); };
struct Owner {
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
Passes* passes;
void* FUN_00b5bfc0(void*,unsigned short*,unsigned char,bool*,bool,bool);
};
// pdb: BSShaderPPLightingProperty::AddRenderNormalsPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned, abRefractionFire
void* Owner::FUN_00b5bfc0(void* geometry,unsigned short* count,unsigned char type,bool* first,bool overlay,bool effect) {
 if(effect) {
  if(type==1) { passes->FUN_00b2c0b0(geometry,0x1e4,*first,0,0,0,0,0); }
  else { ++*count; }
 } else if(!overlay) {
  if(type==1) { passes->FUN_00b2c0b0(geometry,0x1e2,*first,0,0,0,0,0); }
  else { ++*count; }
 } else {
  if(type==1) { passes->FUN_00b2c0b0(geometry,0x1e3,*first,0,0,0,0,0); }
  else { ++*count; }
 }
 *first=false; return 0;
}
}

}   // namespace f3m_00b5bfc0

// @f3 0x00b59480 (community match, verified in this file)
extern const float DAT_00de7b70;
extern int DAT_0116f444;
namespace f3m_00b59480 {
namespace Remove397 {
struct Vector { float x,y,z,w; };
struct Owner {
 int unk00,unk04,unk08,unk0c;
 unsigned short capacity,count;
 Vector* vectors;
 void** items;
 unsigned int FUN_00b59480(unsigned short);
};
// pdb: TallGrassGroup::RemoveTerrainChunk | TallGrassGroup.obj | fnv360_0721_beta, objrun, low
// pdb params: alTerrainChunkSeed
unsigned int Owner::FUN_00b59480(unsigned short index) {
 if(index<count) {
  if(index!=count-1) {
   vectors[index]=vectors[count-1];
   items[index]=items[count-1];
  }
  vectors[count-1].x=0;
  vectors[count-1].y=0;
  vectors[count-1].z=DAT_00de7b70;
  vectors[count-1].w=0;
  items[count-1]=0;
  --count;
  --DAT_0116f444;
 }
 return count;
}
}

}   // namespace f3m_00b59480

// @f3 0x00b44640 (community match, verified in this file)
namespace f3m_00b44640 {
struct OwnerB44640 {
    int a00, a04, a08, a0C, a10, a14, a18, a1C, a20, a24, a28, a2C;
    int a30, a34, a38, a3C, a40, a44, a48, a4C, a50, a54, a58, a5C;
    int a60, a64, a68, a6C, a70;
    int unk74;
    int unk78;
    int unk7C;
    int a80, a84, a88, a8C, a90, a94, a98, a9C, aA0, aA4, aA8, aAC;
    int aB0, aB4, aB8, aBC, aC0, aC4, aC8, aCC, aD0, aD4, aD8, aDC;
    int aE0, aE4, aE8, aEC, aF0, aF4, aF8, aFC, a100, a104, a108, a10C;
    int a110, a114, a118, a11C, a120, a124;
    int unk128;
    int a12C, a130, a134, a138, a13C;
    int unk140;
    int a144, a148, a14C, a150, a154, a158, a15C, a160, a164, a168, a16C, a170;
    bool unk174;

    void __thiscall FUN_00b44150(int row, int col, int previous, int next);
    void __thiscall FUN_00b44640(int steps);
};

// pdb: BoltShaderProperty::ExtendSegments | BoltShaderProperty.obj | fnv360_0721_beta, objrun, medium
// pdb params: aiNewSegments
void OwnerB44640::FUN_00b44640(int steps) {
    for (int s = 0; s < steps; ++s) {
        ++unk7C;
        if (unk7C >= unk140) {
            unk7C = 0;
        }
        int col = unk7C;
        if (col == unk78) {
            ++unk78;
            if (unk78 >= unk140) {
                unk78 -= unk140;
            }
        }
        unk174 = unk78 > col;
        for (int row = 0; row < unk128; ++row) {
            int previous;
            if (col == 0) {
                if (unk174) {
                    previous = unk140 - 1;
                } else {
                    previous = 0;
                }
            } else {
                previous = col - 1;
            }
            int next;
            if (col < unk74) {
                if (unk174) {
                    next = unk140 - unk74 + col;
                } else {
                    next = 0;
                }
            } else {
                next = col - unk74;
            }
            FUN_00b44150(row, col, previous, next);
        }
    }
}
}   // namespace f3m_00b44640

// @f3 0x00b44b40 (community match, verified in this file)
extern const float DAT_00dc0bc8,DAT_00ea10f4;
extern void* DAT_00ea10f8[];
namespace f3m_00b44b40 {
namespace Clone405 {
extern "C" void* __cdecl FUN_0089eb90(unsigned int);
extern "C" void __cdecl FUN_0089e890(void*);
struct FUN_0082ea60 {
void** table;
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
FUN_0082ea60(int);
};
struct Derived: FUN_0082ea60 {
bool flagAC,flagAD; unsigned short unkAE; float value,limit;
Derived():FUN_0082ea60(0),limit(DAT_00dc0bc8) { table=DAT_00ea10f8; value=DAT_00ea10f4; flagAD=false; flagAC=false; }
static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); }
static void operator delete(void* p) { FUN_0089e890(p); }
};
struct Owner {
void FUN_0082daa0(Derived*,void*);
Derived* FUN_00b44b40(void*);
};
// pdb: BSClearZNode::CreateClone | BSClearZNode.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
Derived* Owner::FUN_00b44b40(void* context) {
 Derived* result=new Derived;
 FUN_0082daa0(result,context);
 return result;
}
}

}   // namespace f3m_00b44b40

// @f3 0x00b5b990 (community match, verified in this file)
namespace f3m_00b5b990 {
namespace Select421 {
struct Passes { void FUN_00b2c0b0(void*,unsigned short,bool,unsigned char,void*,void*,void*,void*); };
struct Owner {
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
Passes* passes;
void* FUN_00b5b990(void*,void*,void*,unsigned short*,unsigned char,bool*,bool,bool);
};
// pdb: BSShaderPPLightingProperty::AddAmbDiffDirAndPtPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apSunlight, apPtLight, asCount, abUpdateList, abFirst, abSkinned, abTreeBranch
void* Owner::FUN_00b5b990(void* geometry,void* light0,void* light1,unsigned short* count,unsigned char type,bool* first,bool overlay,bool effect) {
 if(!overlay) {
  if(!effect) {
   if(type==1) { passes->FUN_00b2c0b0(geometry,0x7c,true,2,light0,light1,0,0); }
   else { ++*count; }
  } else {
   if(type==1) { passes->FUN_00b2c0b0(geometry,0x7e,true,2,light0,light1,0,0); }
   else { ++*count; }
  }
 } else {
  if(type==1) { passes->FUN_00b2c0b0(geometry,0x7d,true,2,light0,light1,0,0); }
  else { ++*count; }
 }
 *first=false; return 0;
}
}
}   // namespace f3m_00b5b990

// @f3 0x00b5c120 (community match, verified in this file)
namespace f3m_00b5c120 {
namespace Select432 {
struct Passes { void FUN_00b2c0b0(void*,unsigned int,bool,unsigned char,void*,void*,void*,void*); };
struct Owner {
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
Passes* passes;
void* FUN_00b5c120(void*,unsigned short*,unsigned char,bool*,bool,bool);
};
// pdb: BSShaderPPLightingProperty::AddZOnlyPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned, abAlphaTest
void* Owner::FUN_00b5c120(void* geometry,unsigned short* count,unsigned char type,bool* first,bool overlay,bool effect) {
 if(overlay) {
  if(type==1) passes->FUN_00b2c0b0(geometry,3,*first,0,0,0,0,0);
  else ++*count;
 } else {
  if(type==1) passes->FUN_00b2c0b0(geometry,(effect!=0)+1,*first,0,0,0,0,0);
  else ++*count;
 }
 *first=false;
 return 0;
}
}

}   // namespace f3m_00b5c120

// @f3 0x00b50a20 (community match, verified in this file)
namespace f3m_00b50a20 {
struct Ref_b50a20
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct FUN_00afc480
{
    FUN_00afc480(Ref_b50a20* a, Ref_b50a20* b, int c, int d);
    virtual ~FUN_00afc480();
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
    bool unk64;
    int unk68;
    NiPointer<Ref_b50a20> m_sp6c;
    NiPointer<Ref_b50a20> m_sp70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
};

struct FUN_00b50a20 : FUN_00afc480
{
    NiPointer<Ref_b50a20> m_asp8c[20];
    NiPointer<Ref_b50a20> m_aspdc[33];
    FUN_00b50a20(Ref_b50a20* a);
    virtual ~FUN_00b50a20();
};

// pdb: ParallaxShader::ParallaxShader | ParallaxShader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apShaderDecl
FUN_00b50a20::FUN_00b50a20(Ref_b50a20* a) : FUN_00afc480(a, 0, 0, 0)
{
    unk68 = 3;
    unk64 = false;
    m_sp6c = a;
    m_sp70 = 0;
    unk60 = 0;
}
}   // namespace f3m_00b50a20

// @f3 0x00b42c00 (community match, verified in this file)
namespace Table411 {
struct Heap { void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
struct Scalar {
 float value;
 static void* operator new[](unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};
extern Scalar* DAT_01177ccc;
extern unsigned int DAT_01177cd0;
extern int DAT_0116efb0,DAT_01068958;
inline unsigned int GetCount() { if(!DAT_01177cd0) DAT_01177cd0=DAT_0116efb0>=2 ? 235:75; return DAT_01177cd0; }
// pdb: BoltShader::GetSegmentIndices | BoltShader.obj | fnv360_0721_beta, objrun, medium
Scalar* __cdecl FUN_00b42c00() {
 if(!DAT_01177ccc) {
  unsigned int count=GetCount()*DAT_01068958;
  Scalar* data=new Scalar[count*4];
  DAT_01177ccc=data;
  for(unsigned int i=0;i<count;++i) {
   float index=static_cast<float>(i);
   float divisor=static_cast<float>(DAT_01068958);
   float low=index/divisor;
   float high=(index+1.0f)/divisor;
   data[i*4].value=low;
   data[i*4+1].value=low;
   data[i*4+2].value=high;
   data[i*4+3].value=high;
  }
 }
 return DAT_01177ccc;
}
}

// @f3 0x00b5c080 (community match, verified in this file)
namespace f3m_00b5c080 {
// Model of FUN_00b5c080 (154 B, thiscall, ret 14h) - ported from the verified sibling body this same unit
// carries at line 9220 (f3m_00b5c1b0::ShaderSelector plus RenderPassSink::FUN_00b2c0b0), whose shipped
// listing at 0xb5c120 is the identical shape. Read from capstone: param5 byte compared against zero picks
// which duplicated half runs (fall-through is the zero case, so source order tests NOT overlay); each half
// byte-compares param3 against one - on equality it calls this plus 3Ch receiver with (geometry, code,
// *param4bytepointer, five zeros) then clears that byte through the cached esi, otherwise it does
// add word ptr [param2],1 and clears the same byte. xor eax,eax before both returns means the answer is null.

namespace f3m_00b5c080 {
struct SceneGeometry;
struct ShaderPassEntry;
struct RenderPassSink {
    void FUN_00b2c0b0(SceneGeometry*, unsigned short, bool, unsigned char, void*, void*, void*, void*);
};
struct ShaderSelector {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    RenderPassSink* passes;
    ShaderPassEntry* FUN_00b5c080(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
};

// pdb: BSShaderPPLightingProperty::AddRenderNormalsClearPass_1x | BSShaderPPLightingProperty_Passes_1x.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apGeom, asCount, abUpdateList, abFirst, abSkinned
ShaderPassEntry* ShaderSelector::FUN_00b5c080(SceneGeometry* geometry, unsigned short* count,
    unsigned char type, bool* first, bool overlay) {
    if (!overlay) {
        if (type == 1) {
            passes->FUN_00b2c0b0(geometry, 0x1e5, *first, 0, 0, 0, 0, 0);
            *first = false;
        } else {
            ++*count;
            *first = false;
        }
    } else {
        if (type == 1) {
            passes->FUN_00b2c0b0(geometry, 0x1e6, *first, 0, 0, 0, 0, 0);
            *first = false;
        } else {
            ++*count;
            *first = false;
        }
    }
    return 0;
}
}
}   // namespace f3m_00b5c080

// @f3 0x00b5e210 (community match, verified in this file)
namespace f3m_00b5e210 {
// Model of FUN_00b5e210 - v9: BOTH halves write the call twice under if and else, which is what shipped
// behaviour shows once each half is compared separately. Ladder measured offline at these exact pack flags:
// ternary in both halves 47 flagged lines with 205 extents; path A only as calls 16 flagged with 205 extents
// (every remaining line then a jump or call relocation except the second-half selection); path B only as calls
// 46 flagged. The duplicated-call form makes this compiler merge the two sites and duplicate only the push of
// the differing argument, exactly as shipped does in both halves.

namespace f3m_00b5e210 {
struct SceneGeometry;
struct ShadowSceneLight;
struct RenderPassSink {
    void FUN_00b2c0b0(SceneGeometry*, unsigned short, bool, unsigned char,
                     ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderSelector {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    RenderPassSink* passes;
    int FUN_00b5e210(SceneGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                     unsigned char, bool*, bool, bool, bool);
};

// pdb: BSShaderPPLightingProperty::AddEnvmapPass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apSunLight, apPtLight, asCount, abUpdateList, abFirst, abSkinned, abEyeReflect, abWindowReflect
int ShaderSelector::FUN_00b5e210(SceneGeometry* geometry, ShadowSceneLight* fallback,
    ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* first,
    bool outer, bool wide, bool extra) {
    if (!outer) {
        if (type == 1) {
            unsigned short pass;
            if (wide) {
                pass = 0x24b;
            } else if (!extra) {
                pass = 0x248;
            } else {
                passes->FUN_00b2c0b0(geometry, 0x24a, *first, 0, 0, 0, 0, 0);
                return 0;
            }
            if (light)
                passes->FUN_00b2c0b0(geometry, pass, *first, 1, light, 0, 0, 0);
            else
                passes->FUN_00b2c0b0(geometry, pass, *first, 1, fallback, 0, 0, 0);
            return 0;
        }
        ++*count;
        return 0;
    }
    if (type == 1) {
        if (light) {
            passes->FUN_00b2c0b0(geometry, 0x249, *first, 1, light, 0, 0, 0);
            return 0;
        }
        passes->FUN_00b2c0b0(geometry, 0x249, *first, 1, fallback, 0, 0, 0);
        return 0;
    }
    ++*count;
    return 0;
}
}
}   // namespace f3m_00b5e210

// @f3 0x00b43c50 (community match, verified in this file)
namespace f3m_00b43c50 {
struct Point4_b43c50 { float x,y,z,w; };
struct Ring216_b43c50 {
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
    Point4_b43c50* data;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    int index;
    int end;
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
    int count;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    int size;
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
    char wrapped;
    void FUN_00b43c50(float value);
};

// pdb: BoltShaderProperty::MoveAllSegments | BoltShaderProperty.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: afMoveDelta
void Ring216_b43c50::FUN_00b43c50(float value)
{
    int i = this->index;
    char wrapped = this->wrapped;
    for (;;)
    {
        if ((!wrapped || i >= this->size) && i > this->end)
            break;
        for (int c = 0; c < this->count; ++c)
        {
            int offset = this->size;
            offset *= c;
            offset += i;
            this->data[offset].y += value;
        }
        if (++i < this->size)
            continue;
        if (!wrapped)
            continue;
        i = 0;
        wrapped = 0;
    }
}
}   // namespace f3m_00b43c50

// @f3 0x00b59620 (community match, verified in this file)
#include <math.h>
extern float FUN_00ea1280;
namespace ns_00b59620 {
struct V3 {
 float x,y,z;
 V3() {}
 V3(float a,float b,float c):x(a),y(b),z(c){}
 V3& operator+=(const V3& b) {x+=b.x;y+=b.y;z+=b.z;return *this;}
 V3 operator-(const V3& b) const {return V3(x-b.x,y-b.y,z-b.z);}
 V3 operator+(const V3& b) const {return V3(x+b.x,y+b.y,z+b.z);}
 V3 operator*(float b) const {return V3(x*b,y*b,z*b);}
 float length() const {return sqrt(x*x+y*y+z*z);}
};
struct Point {float x,y,z,w;};
struct Bound {V3 center;float radius;};
struct Type {const char* name; const Type* parent;};
static __forceinline bool IsKindOf(const Type* p,const Type* t){while(p){if(p==t)return true;p=p->parent;}return false;}
}
extern const ns_00b59620::Type DAT_01178250,DAT_01178258;
namespace ns_00b59620 {
struct Obj {
virtual void slot00(); virtual void slot01();
virtual const Type* GetType() const;
virtual void slot03(); virtual void slot04(); virtual void slot05(); virtual void slot06();
virtual void slot07(); virtual void slot08(); virtual void slot09(); virtual void slot10();
virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14();
virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18();
virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22();
virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26();
virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30();
virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34();
virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38();
virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42();
virtual void slot43(); virtual void slot44(); virtual void slot45();
virtual void GetTranslation(V3*);
virtual void slot47(); virtual void slot48(); virtual void slot49(); virtual void slot50();
virtual void slot51(); virtual void slot52(); virtual void slot53(); virtual void slot54();
virtual void slot55(); virtual void slot56(); virtual void slot57(); virtual void slot58();
virtual void slot59(); virtual void slot60(); virtual void slot61(); virtual void slot62();
virtual void SetBound(Bound);
virtual void SetCount(unsigned int);
int field04,field08,field0c,field10,field14; V3 displacement;
};
}
ns_00b59620::Obj* __cdecl FUN_00424d50(const ns_00b59620::Type*,ns_00b59620::Obj*);
namespace ns_00b59620 {
struct Params {int field00,field04,field08,field0c,field10,field14,field18,field1c,field20,field24;float size;};
struct Link {int field00,field04,field08;Obj* obj;};
struct Owner {int field00;int field04;int field08;int field0c;int field10;int field14;int field18;int field1c;int field20;int field24;int field28;int field2c;int field30;int field34;int field38;int field3c;int field40;int field44;int field48;int field4c;int field50;int field54;int field58;int field5c;int field60;int field64;int field68;int field6c;int field70;int field74;int field78;int field7c;int field80;int field84;int field88;int field8c;int field90;int field94;int field98;int field9c;int fielda0;int fielda4;int fielda8;Link* link;};
template<class T> inline T Min(T a,T b) {return a<b?a:b;}
template<class T> inline T Max(T a,T b) {return a>b?a:b;}
struct Worker {
 Obj* obj;Owner* owner;Params* params;int field0c;unsigned short capacity,count;Point* points;
 void FUN_00b59620();
};

// pdb: TallGrassGroup::UpdateGroupBound | TallGrassGroup.obj | fnv360_0822_retail, call_gap, medium
void Worker::FUN_00b59620() {
 float limit=FUN_00ea1280;
 if(!count) limit=0.0f;
 V3 lo(limit,limit,limit),hi(-limit,-limit,-limit);
 for(int i=0;i<(int)count;++i) {
 lo.x=Min(lo.x,points[i].x);hi.x=Max(hi.x,points[i].x);
 lo.y=Min(lo.y,points[i].y);hi.y=Max(hi.y,points[i].y);
 lo.z=Min(lo.z,points[i].z);hi.z=Max(hi.z,points[i].z);
 }
 if(params && obj) {
 V3 center=lo+(hi-lo)*0.5f;
 Bound sphere;
 sphere.center=center;
 sphere.radius=(hi-center).length()+params->size;
 Obj* result=obj;
 result=IsKindOf(result->GetType(),&DAT_01178258)?result:0;
 if(!result) {
  Obj* o=obj;
  result=FUN_00424d50(&DAT_01178250,o);
 }
 if(result){result->SetBound(sphere);result->SetCount(count);}
 Obj* associated=owner->link->obj;
 associated->GetTranslation(&center);
 associated->displacement=hi-center;
 }
}
}

// @f3 0x00b5b4d0 (community match, verified in this file)
namespace f3m_b5b4d0 {
struct Sub58 {
    void* FUN_00b22300();
    void FUN_00b22440();
};

struct GlobalMgr {
    void FUN_00af0de0(void* p);
};
}
extern "C" f3m_b5b4d0::GlobalMgr* DAT_0116ef98;

namespace f3m_b5b4d0 {
class BaseRenderer {
public:
    virtual void Unk00();
    virtual void Draw(int a, int b, void* c, int d);
    void FUN_00b228d0(int stage, void* tex, int flags);
};

struct OtherBase {
    BaseRenderer m_renderer;
};

struct Pad6C {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
};

struct DerivedRenderer : Pad6C, OtherBase {};

struct Holder0C {
    OtherBase* m_pBase;
};

struct Holder1C {
    void* m_p00;
};

struct Holder2C {
    void* m_p00;
    void* m_p04;
};

class Owner {
public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0c();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual bool UpdateFlag(int arg);

    char m_04;
    bool m_05;
    short m_06;
    int m_08;
    Holder0C* m_0c;
    int m_10;
    int m_14;
    int m_18;
    Holder1C* m_1c;
    int m_20;
    int m_24;
    int m_28;
    Holder2C* m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54;
    Sub58 m_58;

    void FUN_00b5b4d0(int a1, int a2, int a3, int a4);
};

// pdb: ImageSpaceEffectRefraction::Render | ImageSpaceEffectRefraction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apGeometry, apRenderer, apParam, abEndFrame
void Owner::FUN_00b5b4d0(int a1, int a2, int a3, int a4)
{
    if (m_05) {
        m_05 = UpdateFlag(a3);
    }
    DerivedRenderer* d = static_cast<DerivedRenderer*>(*(OtherBase* volatile*)&m_0c->m_pBase);
    BaseRenderer* r = &d->m_renderer;
    void* p1c = m_1c->m_p00;
    r->FUN_00b228d0(0, m_2c->m_p00, 0);
    r->FUN_00b228d0(1, m_2c->m_p04, 0);
    r->FUN_00b228d0(2, &m_58, 0);
    r->Draw(a1, a2, p1c, 1);
    r->FUN_00b228d0(0, 0, 0);
    r->FUN_00b228d0(1, 0, 0);
    r->FUN_00b228d0(2, 0, 0);
    GlobalMgr* mgr = DAT_0116ef98;
    mgr->FUN_00af0de0(m_58.FUN_00b22300());
    m_58.FUN_00b22440();
}
}

// @f3 0x00b40790 (community match, verified in this file)
struct Tgt { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); };
struct Switch { unsigned int unk00, unk04; unsigned char b; };
struct V3 { float x, y, z; };
struct V4 { float x, y, z, w; V4() {} V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
struct Info { unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C; V3 v; float a; float b; unsigned int unk34;unsigned int unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4C;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5C; float c; };
extern Switch* DAT_01176e20[17];
extern Switch* DAT_01176e64;
extern Switch* DAT_01176e68;
extern Switch* DAT_01176e6c;
extern Switch* DAT_01176e70;
extern Switch* DAT_01176e74;
extern Switch* DAT_01176e78;
extern Switch* DAT_01176e7c;
extern Switch* DAT_01176e80;
extern Switch* DAT_01176e84;
extern Switch* DAT_01176e88;
extern unsigned int DAT_011767c8[];
extern unsigned int DAT_01176608[];
extern unsigned char DAT_011765f4[17];
extern unsigned char DAT_011765e8;
extern unsigned char DAT_011765e9;
extern unsigned char DAT_011765ea;
extern unsigned char DAT_011765eb;
extern unsigned char DAT_011765ec;
extern unsigned char DAT_011765ed;
extern unsigned char DAT_011765ee;
extern unsigned char DAT_011765ef;
extern unsigned char DAT_011765f0;
extern unsigned char DAT_011765f1;
extern Switch* DAT_01176e5c;
extern Switch* DAT_01176e60;
extern unsigned char DAT_0116efb4;
extern Info* FUN_00adb920(unsigned char k);
extern float DAT_00e943f4;
extern V4 DAT_00f73210;
extern V4 DAT_01177150;
extern V4 DAT_01177160;
extern V4 DAT_01170020;
extern float DAT_0108f04c;
extern float DAT_0108f050;
extern float DAT_0108f054;
extern V4 DAT_01177170;
struct FUN_00b40790_cls {
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
    Tgt* unk30;
    Tgt* unk34;
    void FUN_00b40790(int aiShaderIndex);
};
// pdb: Lighting30Shader::SetupPassConstants | Lighting30Shader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: auiCurrentPass
void FUN_00b40790_cls::FUN_00b40790(int aiShaderIndex) {
    if (aiShaderIndex == 480 || aiShaderIndex == 481) return;
    int iTableIndex;
    switch ((unsigned int)aiShaderIndex) {
    case 467: iTableIndex = 89; break;
    case 10: iTableIndex = 1; break;
    case 11: iTableIndex = 2; break;
    case 12: iTableIndex = 3; break;
    case 13: iTableIndex = 4; break;
    case 14: iTableIndex = 5; break;
    case 15: iTableIndex = 6; break;
    case 468: iTableIndex = 90; break;
    case 469: iTableIndex = 91; break;
    case 470: iTableIndex = 92; break;
    case 471: iTableIndex = 93; break;
    case 472: iTableIndex = 94; break;
    case 473: iTableIndex = 95; break;
    case 474: iTableIndex = 96; break;
    case 730: iTableIndex = 104; break;
    case 731: iTableIndex = 105; break;
    case 736: iTableIndex = 104; break;
    case 737: iTableIndex = 105; break;
    case 742: iTableIndex = 104; break;
    case 743: iTableIndex = 105; break;
    case 748: iTableIndex = 104; break;
    case 749: iTableIndex = 105; break;
    default: iTableIndex = aiShaderIndex - 376; break;
    }
    for (int i = 0; i < 17; i++) {
        Switch* s = DAT_01176e20[i];
        if (s) s->b = (DAT_011767c8[iTableIndex] & (1 << (i + 1))) != 0;
        DAT_011765f4[i] = (DAT_011767c8[iTableIndex] & (1 << (i + 1))) != 0;
    }
    if (DAT_01176e64) DAT_01176e64->b = (DAT_01176608[iTableIndex] >> 1) & 1;
    DAT_011765e8 = (DAT_01176608[iTableIndex] >> 1) & 1;
    if (DAT_01176e68) DAT_01176e68->b = (DAT_01176608[iTableIndex] >> 2) & 1;
    DAT_011765e9 = (DAT_01176608[iTableIndex] >> 2) & 1;
    if (DAT_01176e6c) DAT_01176e6c->b = (DAT_01176608[iTableIndex] >> 3) & 1;
    DAT_011765ea = (DAT_01176608[iTableIndex] >> 3) & 1;
    if (DAT_01176e70) DAT_01176e70->b = (DAT_01176608[iTableIndex] >> 4) & 1;
    DAT_011765eb = (DAT_01176608[iTableIndex] >> 4) & 1;
    if (DAT_01176e74) DAT_01176e74->b = (DAT_01176608[iTableIndex] >> 5) & 1;
    DAT_011765ec = (DAT_01176608[iTableIndex] >> 5) & 1;
    if (DAT_01176e78) DAT_01176e78->b = (DAT_01176608[iTableIndex] >> 6) & 1;
    DAT_011765ed = (DAT_01176608[iTableIndex] >> 6) & 1;
    if (DAT_01176e7c) DAT_01176e7c->b = (DAT_01176608[iTableIndex] >> 7) & 1;
    DAT_011765ee = (DAT_01176608[iTableIndex] >> 7) & 1;
    if (DAT_01176e80) DAT_01176e80->b = (DAT_01176608[iTableIndex] >> 8) & 1;
    DAT_011765ef = (DAT_01176608[iTableIndex] >> 8) & 1;
    if (DAT_01176e84) DAT_01176e84->b = (DAT_01176608[iTableIndex] >> 9) & 1;
    DAT_011765f0 = (DAT_01176608[iTableIndex] >> 9) & 1;
    if (DAT_01176e88) DAT_01176e88->b = (DAT_01176608[iTableIndex] >> 10) & 1;
    DAT_011765f1 = (DAT_01176608[iTableIndex] >> 10) & 1;
    unk34->s9();
    unk30->s9();
    if (DAT_01176e5c->b) {
        Info* p = FUN_00adb920(DAT_0116efb4);
        if (p) {
            V3 v = p->v;
            float a = p->a;
            float b = p->b;
            float c = p->c;
            if (b == 0.0f && a == 0.0f) {
                DAT_01177150 = V4(DAT_00e943f4, 0.0f, c, 0.0f);
                DAT_01177160 = DAT_00f73210;
            } else {
                DAT_01177150 = V4(b, b - a, c, 0.0f);
                DAT_01177160 = V4(v.x, v.y, v.z, 1.0f);
            }
        }
    }
    if (DAT_01176e60->b) {
        V4 t = DAT_01170020;
        V3 d;
        d.x = t.x - DAT_0108f04c;
        d.y = t.y - DAT_0108f050;
        d.z = t.z - DAT_0108f054;
        DAT_01177170 = V4(d.x, d.y, d.z, 1.0f);
    }
}

// @f3 0x00b41c10 (community match, verified in this file)
struct S00b41c10_RefObject {
    virtual ~S00b41c10_RefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement(&m_uiRefCount)) DeleteThis(); }
};
struct S00b41c10_ConstantEntry : S00b41c10_RefObject {
};
struct S00b41c10_ConstantMap : S00b41c10_RefObject {
    virtual void AddConstant(const char* name, unsigned int flags, unsigned int extra, unsigned int reg, unsigned int count, const char* desc, unsigned int dataSize, unsigned int stride, void* data, unsigned int copy);
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void AddPredefined(const char* name, unsigned int flags, unsigned int predef, const char* desc, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    virtual void Unk6C();
    virtual S00b41c10_ConstantEntry* GetEntry(const char* name);
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
    S00b41c10_ConstantMap(void* device, int programType);
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};
typedef NiPointer<S00b41c10_ConstantMap> S00b41c10_ConstantMapPtr;
typedef NiPointer<S00b41c10_ConstantEntry> S00b41c10_ConstantEntryPtr;

extern bool g_S00b41c10_initGlobals;
extern float g_S00b41c10_prevBones[];
extern float g_S00b41c10_objToCubeMap[];
extern float g_S00b41c10_eyePos[];
extern float g_S00b41c10_worldEyePos[];
extern float g_S00b41c10_fog[];
extern float g_S00b41c10_depthData[];
extern float g_S00b41c10_refraction[];
extern float g_S00b41c10_worldBoundCenter[];
extern float g_S00b41c10_shadowProj[];
extern float g_S00b41c10_prevWorldViewPT[];
extern float g_S00b41c10_prevWorldViewT[];
extern float g_S00b41c10_skinToCubeMap[];
extern float g_S00b41c10_ambientColor[];
extern float g_S00b41c10_psEyePos[];
extern float g_S00b41c10_hairTint[];
extern float g_S00b41c10_matAlpha[];
extern float g_S00b41c10_matEmit[];
extern float g_S00b41c10_refractPower[];
extern float g_S00b41c10_parallaxData[];
extern float g_S00b41c10_waterFog[];
extern float g_S00b41c10_envMapToggles[];
extern float g_S00b41c10_lightData[];
extern float g_S00b41c10_uOffset;
extern float g_S00b41c10_vOffset;
extern float g_S00b41c10_invBoundDiameter;
extern float g_S00b41c10_fogParam[];
extern float g_S00b41c10_fogColor[];
extern float g_S00b41c10_fillColor[];
extern float g_S00b41c10_rimColor[];
extern float g_S00b41c10_vars[];
extern S00b41c10_ConstantEntryPtr g_S00b41c10_WorldViewProjTranspose;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_SkinWorldViewProjTranspose;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_WorldViewTranspose;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_SkinWorldViewTranspose;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_BoneMatrix3;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_PrevBoneMatrix3;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_ObjToCubeMap;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_PrevWorldViewPT;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_PrevWorldViewT;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_EyePos;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_DepthData;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_Refraction;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_WorldBoundCenter;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_ShadowProjectionData;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_SkinToCubeMap;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_Fog;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_WorldEyePos;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_ambientcolor;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_eyepos;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_hairtint;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_matalpha;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_matemit;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_refractpower;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_parallaxdata;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_envmaptoggles;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_waterfog;
extern S00b41c10_ConstantEntryPtr g_S00b41c10_lightdata;

struct S00b41c10_SkinShader {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pD3DDevice;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S00b41c10_ConstantMapPtr m_spPixelConstantMap;
    S00b41c10_ConstantMapPtr m_spVertexConstantMap;
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
    S00b41c10_ConstantMapPtr m_spRimPixelConstantMap;
    S00b41c10_ConstantMapPtr m_spRimVertexConstantMap;
    S00b41c10_ConstantMapPtr m_spPassPixelConstantMap;
    S00b41c10_ConstantMapPtr m_spPassVertexConstantMap;
    void FUN_00b41c10();
};

// pdb: Lighting30Shader::CreateConstantMaps | Lighting30Shader.obj | fnv360_0822_retail, ustr, medium
void S00b41c10_SkinShader::FUN_00b41c10()
{
    if (m_spVertexConstantMap == 0 && !g_S00b41c10_initGlobals)
    {
        g_S00b41c10_initGlobals = true;
        m_spVertexConstantMap = new S00b41c10_ConstantMap(m_pD3DDevice, 0);
        m_spVertexConstantMap->AddPredefined("WorldViewProjTranspose", 0x20000009, 0, "", 0, 0, 0, 0);
        g_S00b41c10_WorldViewProjTranspose = m_spVertexConstantMap->GetEntry("WorldViewProjTranspose");
        m_spVertexConstantMap->AddPredefined("SkinWorldViewProjTranspose", 0x20000009, 0x14, "", 0, 0, 0, 0);
        g_S00b41c10_SkinWorldViewProjTranspose = m_spVertexConstantMap->GetEntry("SkinWorldViewProjTranspose");
        m_spVertexConstantMap->AddPredefined("WorldViewTranspose", 0x20000009, 4, "", 0, 0, 0, 0);
        g_S00b41c10_WorldViewTranspose = m_spVertexConstantMap->GetEntry("WorldViewTranspose");
        m_spVertexConstantMap->AddPredefined("SkinWorldViewTranspose", 0x20000009, 0x18, "", 0, 0, 0, 0);
        g_S00b41c10_SkinWorldViewTranspose = m_spVertexConstantMap->GetEntry("SkinWorldViewTranspose");
        m_spVertexConstantMap->AddConstant("BoneMatrix3", 0x20000009, 0x120000, 0x34, 0x36, 0, 0, 0, 0, 0);
        g_S00b41c10_BoneMatrix3 = m_spVertexConstantMap->GetEntry("BoneMatrix3");
        m_spVertexConstantMap->AddConstant("PrevBoneMatrix3", 0x10000009, 0, 0x6c, 0x36, "", 0x360, 4, g_S00b41c10_prevBones, 0);
        g_S00b41c10_PrevBoneMatrix3 = m_spVertexConstantMap->GetEntry("PrevBoneMatrix3");
        m_spVertexConstantMap->AddConstant("ObjToCubeMap", 0x10000009, 0, 8, 4, "", 0x40, 4, g_S00b41c10_objToCubeMap, 0);
        g_S00b41c10_ObjToCubeMap = m_spVertexConstantMap->GetEntry("ObjToCubeMap");
        m_spVertexConstantMap->AddConstant("EyePos", 0x10000007, 0, 0x28, 1, "", 0x10, 4, g_S00b41c10_eyePos, 0);
        g_S00b41c10_EyePos = m_spVertexConstantMap->GetEntry("EyePos");
        m_spVertexConstantMap->AddConstant("WorldEyePos", 0x10000007, 0, 0x2e, 1, "", 0x10, 4, g_S00b41c10_worldEyePos, 0);
        g_S00b41c10_WorldEyePos = m_spVertexConstantMap->GetEntry("WorldEyePos");
        m_spVertexConstantMap->AddConstant("Fog", 0x1000000c, 0, 0x2c, 2, "", 0x20, 4, g_S00b41c10_fog, 0);
        g_S00b41c10_Fog = m_spVertexConstantMap->GetEntry("Fog");
        m_spVertexConstantMap->AddConstant("DepthData", 0x10000007, 0, 0x29, 1, "", 0x10, 4, g_S00b41c10_depthData, 0);
        g_S00b41c10_DepthData = m_spVertexConstantMap->GetEntry("DepthData");
        m_spVertexConstantMap->AddConstant("Refraction", 0x10000007, 0, 0x26, 1, "", 0x10, 4, g_S00b41c10_refraction, 0);
        g_S00b41c10_Refraction = m_spVertexConstantMap->GetEntry("Refraction");
        m_spVertexConstantMap->AddConstant("WorldBoundCenter", 0x10000007, 0, 0x27, 1, "", 0x10, 4, g_S00b41c10_worldBoundCenter, 0);
        g_S00b41c10_WorldBoundCenter = m_spVertexConstantMap->GetEntry("WorldBoundCenter");
        m_spVertexConstantMap->AddConstant("ShadowProjectionData", 0x10000009, 0, 0x20, 6, "", 0x60, 4, g_S00b41c10_shadowProj, 0);
        g_S00b41c10_ShadowProjectionData = m_spVertexConstantMap->GetEntry("ShadowProjectionData");
        m_spVertexConstantMap->AddConstant("PrevWorldViewPT", 0x10000009, 0, 0xc, 4, "", 0x40, 4, g_S00b41c10_prevWorldViewPT, 0);
        g_S00b41c10_PrevWorldViewPT = m_spVertexConstantMap->GetEntry("PrevWorldViewPT");
        m_spVertexConstantMap->AddConstant("PrevWorldViewT", 0x10000009, 0, 0x10, 4, "", 0x40, 4, g_S00b41c10_prevWorldViewT, 0);
        g_S00b41c10_PrevWorldViewT = m_spVertexConstantMap->GetEntry("PrevWorldViewT");
        m_spVertexConstantMap->AddConstant("SkinToCubeMap", 0x10000009, 0, 0x1c, 4, "", 0x40, 4, g_S00b41c10_skinToCubeMap, 0);
        g_S00b41c10_SkinToCubeMap = m_spVertexConstantMap->GetEntry("SkinToCubeMap");
        m_spVertexConstantMap = new S00b41c10_ConstantMap(m_pD3DDevice, 0);
    }
    if (m_spPixelConstantMap == 0)
    {
        m_spPixelConstantMap = new S00b41c10_ConstantMap(m_pD3DDevice, 2);
        m_spPixelConstantMap->AddConstant("ambientcolor", 0x10000007, 0, 0, 1, "", 0x10, 4, g_S00b41c10_ambientColor, 0);
        g_S00b41c10_ambientcolor = m_spPixelConstantMap->GetEntry("ambientcolor");
        m_spPixelConstantMap->AddConstant("eyepos", 0x10000007, 0, 1, 1, "", 0x10, 4, g_S00b41c10_psEyePos, 0);
        g_S00b41c10_eyepos = m_spPixelConstantMap->GetEntry("eyepos");
        m_spPixelConstantMap->AddConstant("hairtint", 0x10000007, 0, 2, 1, "", 0x10, 4, g_S00b41c10_hairTint, 0);
        g_S00b41c10_hairtint = m_spPixelConstantMap->GetEntry("hairtint");
        m_spPixelConstantMap->AddConstant("matalpha", 0x10000007, 0, 3, 1, "", 0x10, 4, g_S00b41c10_matAlpha, 0);
        g_S00b41c10_matalpha = m_spPixelConstantMap->GetEntry("matalpha");
        m_spPixelConstantMap->AddConstant("matemit", 0x10000007, 0, 4, 1, "", 0x10, 4, g_S00b41c10_matEmit, 0);
        g_S00b41c10_matemit = m_spPixelConstantMap->GetEntry("matemit");
        m_spPixelConstantMap->AddConstant("refractpower", 0x10000007, 0, 6, 1, "", 0x10, 4, g_S00b41c10_refractPower, 0);
        g_S00b41c10_refractpower = m_spPixelConstantMap->GetEntry("refractpower");
        m_spPixelConstantMap->AddConstant("parallaxdata", 0x10000007, 0, 7, 1, "", 0x10, 4, g_S00b41c10_parallaxData, 0);
        g_S00b41c10_parallaxdata = m_spPixelConstantMap->GetEntry("parallaxdata");
        m_spPixelConstantMap->AddConstant("waterfog", 0x1000000c, 0, 9, 2, "", 0x20, 4, g_S00b41c10_waterFog, 0);
        g_S00b41c10_waterfog = m_spPixelConstantMap->GetEntry("waterfog");
        m_spPixelConstantMap->AddConstant("envmaptoggles", 0x10000007, 0, 0xb, 1, "", 0x10, 4, g_S00b41c10_envMapToggles, 0);
        g_S00b41c10_envmaptoggles = m_spPixelConstantMap->GetEntry("envmaptoggles");
        m_spPixelConstantMap->AddConstant("lightdata", 0x10000009, 0, 0x14, 0x29, "", 0x290, 4, g_S00b41c10_lightData, 0);
        g_S00b41c10_lightdata = m_spPixelConstantMap->GetEntry("lightdata");
        m_spPixelConstantMap = new S00b41c10_ConstantMap(m_pD3DDevice, 2);
    }
    m_spPassVertexConstantMap = m_spVertexConstantMap;
    m_spPassPixelConstantMap = m_spPixelConstantMap;
    if (!m_spRimVertexConstantMap)
    {
        m_spRimVertexConstantMap = new S00b41c10_ConstantMap(m_pD3DDevice, 0);
        m_spRimVertexConstantMap->AddPredefined("WorldViewProjTranspose", 0x20000009, 0, "", 0, 0, 0, 0);
        m_spRimVertexConstantMap->AddPredefined("SkinWorldViewProjTranspose", 0x20000009, 4, "", 0, 0, 0, 0);
        m_spRimVertexConstantMap->AddConstant("BoneMatrix3", 0x20000009, 0x120000, 0xe, 0x36, 0, 0, 0, 0, 0);
        m_spRimVertexConstantMap->AddConstant("EyePosition", 0x10000007, 0, 8, 1, "", 0x10, 4, g_S00b41c10_eyePos, 0);
        m_spRimVertexConstantMap->AddConstant("U Offset", 0x10000004, 0, 9, 1, "", 4, 4, &g_S00b41c10_uOffset, 0);
        m_spRimVertexConstantMap->AddConstant("V Offset", 0x10000004, 0, 0xa, 1, "", 4, 4, &g_S00b41c10_vOffset, 0);
        m_spRimVertexConstantMap->AddConstant("InvBoundDiameter", 0x10000004, 0, 0xb, 1, "", 4, 4, &g_S00b41c10_invBoundDiameter, 0);
        m_spRimVertexConstantMap->AddConstant("FogParam", 0x10000007, 0, 0xc, 1, "", 0x10, 4, g_S00b41c10_fogParam, 0);
        m_spRimVertexConstantMap->AddConstant("FogColor", 0x10000007, 0, 0xd, 1, "", 0x10, 4, g_S00b41c10_fogColor, 0);
    }
    if (!m_spRimPixelConstantMap)
    {
        m_spRimPixelConstantMap = new S00b41c10_ConstantMap(m_pD3DDevice, 2);
        m_spRimPixelConstantMap->AddConstant("Fill Color", 0x10000007, 0, 0, 1, "", 0x10, 4, g_S00b41c10_fillColor, 0);
        m_spRimPixelConstantMap->AddConstant("Rim Color", 0x10000007, 0, 1, 1, "", 0x10, 4, g_S00b41c10_rimColor, 0);
        m_spRimPixelConstantMap->AddConstant("Vars", 0x10000007, 0, 2, 1, "", 0x10, 4, g_S00b41c10_vars, 0);
    }
}

// @f3 0x00b415f0 (community match, verified in this file)
#include <string.h>
namespace ShaderB415F0 {
struct Point3 {
    float x,y,z;
    Point3() {}
    Point3(float ax,float ay,float az):x(ax),y(ay),z(az) {}
    float FUN_00475250(const Point3& b) const;
    Point3 operator+(const Point3& v) const { return Point3(x+v.x,y+v.y,z+v.z); }
};
struct RawMatrix { float m[4][4]; };
struct Matrix : RawMatrix {
    float& operator()(int r,int c) { return m[r][c]; }
    Matrix() {}
    Matrix(const RawMatrix& other) { memcpy(this, &other, sizeof(Matrix)); }
};
struct Plane { float a,b,c,d; };
struct GeomValue; struct Geometry; struct Args; struct Root; struct RenderData;
struct Light {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void Apply(int, Geometry*, int, int, int, Args*, int, void*, const char*, int, int);
};
struct PlaneTarget {
    virtual void __stdcall v00();
    virtual void __stdcall v04();
    virtual void __stdcall v08();
    virtual void __stdcall v0C();
    virtual void __stdcall v10();
    virtual void __stdcall v14();
    virtual void __stdcall v18();
    virtual void __stdcall v1C();
    virtual void __stdcall v20();
    virtual void __stdcall v24();
    virtual void __stdcall v28();
    virtual void __stdcall v2C();
    virtual void __stdcall v30();
    virtual void __stdcall v34();
    virtual void __stdcall v38();
    virtual void __stdcall v3C();
    virtual void __stdcall v40();
    virtual void __stdcall v44();
    virtual void __stdcall v48();
    virtual void __stdcall v4C();
    virtual void __stdcall v50();
    virtual void __stdcall v54();
    virtual void __stdcall v58();
    virtual void __stdcall v5C();
    virtual void __stdcall v60();
    virtual void __stdcall v64();
    virtual void __stdcall v68();
    virtual void __stdcall v6C();
    virtual void __stdcall v70();
    virtual void __stdcall v74();
    virtual void __stdcall v78();
    virtual void __stdcall v7C();
    virtual void __stdcall v80();
    virtual void __stdcall v84();
    virtual void __stdcall v88();
    virtual void __stdcall v8C();
    virtual void __stdcall v90();
    virtual void __stdcall v94();
    virtual void __stdcall v98();
    virtual void __stdcall v9C();
    virtual void __stdcall vA0();
    virtual void __stdcall vA4();
    virtual void __stdcall vA8();
    virtual void __stdcall vAC();
    virtual void __stdcall vB0();
    virtual void __stdcall vB4();
    virtual void __stdcall vB8();
    virtual void __stdcall vBC();
    virtual void __stdcall vC0();
    virtual void __stdcall vC4();
    virtual void __stdcall vC8();
    virtual void __stdcall vCC();
    virtual void __stdcall vD0();
    virtual void __stdcall vD4();
    virtual void __stdcall vD8();
    virtual void __stdcall SetPlane(int index, Plane* plane);
};
struct Handler {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void Apply(Geometry*);
    unsigned int unk000;
};
struct Geometry {

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int flags;
    unsigned int unk01C;
    const char* name;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    Matrix sub;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    GeomValue* value;
    int index;
};
struct GeomValue {

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    int value;
};
struct RenderData {

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    int frequency;
    float fogNear;
    float fogFar;
};
struct Args {

    Geometry* g0;
    unsigned int unk004;
    int param;
    RenderData* data;
    Geometry* g10;
};
struct Clip {
    void FUN_00af4660(Plane*);
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    Plane planes[6];
    unsigned int unk1A4;
    Plane planes2[6];
    bool frozen;
    unsigned char unk209;
    unsigned char unk20A;
    unsigned char unk20B;
};
struct Root {

    Geometry* obj;
    unsigned int unk004;
    unsigned int unk008;
    Clip** clip;
};
struct Renderer {
    void FUN_00874d00(void*,int);
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    unsigned int unk5F0;
    unsigned int unk5F4;
    unsigned int unk5F8;
    unsigned int unk5FC;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60C;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61C;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62C;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63C;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64C;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65C;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66C;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67C;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68C;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69C;
    unsigned int unk6A0;
    unsigned int unk6A4;
    unsigned int unk6A8;
    unsigned int unk6AC;
    unsigned int unk6B0;
    unsigned int unk6B4;
    unsigned int unk6B8;
    unsigned int unk6BC;
    unsigned int unk6C0;
    unsigned int unk6C4;
    unsigned int unk6C8;
    unsigned int unk6CC;
    unsigned int unk6D0;
    unsigned int unk6D4;
    unsigned int unk6D8;
    unsigned int unk6DC;
    unsigned int unk6E0;
    unsigned int unk6E4;
    unsigned int unk6E8;
    unsigned int unk6EC;
    unsigned int unk6F0;
    unsigned int unk6F4;
    unsigned int unk6F8;
    unsigned int unk6FC;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70C;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71C;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72C;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73C;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74C;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75C;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76C;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77C;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78C;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79C;
    unsigned int unk7A0;
    unsigned int unk7A4;
    unsigned int unk7A8;
    unsigned int unk7AC;
    unsigned int unk7B0;
    unsigned int unk7B4;
    unsigned int unk7B8;
    unsigned int unk7BC;
    unsigned int unk7C0;
    unsigned int unk7C4;
    unsigned int unk7C8;
    unsigned int unk7CC;
    unsigned int unk7D0;
    unsigned int unk7D4;
    unsigned int unk7D8;
    unsigned int unk7DC;
    unsigned int unk7E0;
    unsigned int unk7E4;
    unsigned int unk7E8;
    unsigned int unk7EC;
    unsigned int unk7F0;
    unsigned int unk7F4;
    unsigned int unk7F8;
    unsigned int unk7FC;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80C;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81C;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82C;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83C;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84C;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85C;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86C;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87C;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88C;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89C;
    unsigned int unk8A0;
    unsigned int unk8A4;
    unsigned int unk8A8;
    unsigned int unk8AC;
    unsigned int unk8B0;
    unsigned int unk8B4;
    unsigned int unk8B8;
    unsigned int unk8BC;
    unsigned int unk8C0;
    unsigned int unk8C4;
    unsigned int unk8C8;
    unsigned int unk8CC;
    unsigned int unk8D0;
    unsigned int unk8D4;
    unsigned int unk8D8;
    unsigned int unk8DC;
    unsigned int unk8E0;
    unsigned int unk8E4;
    unsigned int unk8E8;
    unsigned int unk8EC;
    unsigned int unk8F0;
    unsigned int unk8F4;
    unsigned int unk8F8;
    unsigned int unk8FC;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90C;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91C;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92C;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93C;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94C;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95C;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96C;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97C;
    RawMatrix view;
    RawMatrix projection;
};
struct Camera {
    void FUN_00af46d0(Point3*);
    unsigned int unk000;
};
struct Settings {

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    bool a;
    bool b;
    unsigned char unk166;
    unsigned char unk167;
};
struct BoolSetting {

    unsigned int unk000;
    unsigned int unk004;
    bool enabled;
    unsigned char unk009;
    unsigned char unk00A;
    unsigned char unk00B;
};
struct RenderGlobals {

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    Light* first;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    int firstHandle;
    Light* second;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    int secondHandle;
};
struct PlaneGlobals {

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    PlaneTarget* target;
};
extern Root* DAT_0116efd0;
extern unsigned int DAT_0116efd4;
extern const char DAT_0108edc8[];
extern RenderGlobals* DAT_01091980;
extern BoolSetting* DAT_01176e4c;
extern BoolSetting* DAT_01176e7c;
extern float DAT_0116f1fc;
extern float DAT_011770f0;
extern float DAT_01177940;
extern float DAT_01177944;
extern Camera* DAT_0116efb8;
extern float DAT_0108f04c, DAT_0108f050, DAT_0108f054;
extern PlaneGlobals* DAT_0108f048;
void __cdecl FUN_00b0da80(int,int);
void __cdecl FUN_00aabd50(void*,int,Matrix*);
Settings* __cdecl FUN_00ad5a50();
Matrix* __stdcall FUN_00c2082c(Matrix*,Matrix*,Matrix*);
Matrix* __stdcall FUN_00c20844(Matrix*,float*,Matrix*);
Matrix* __stdcall FUN_00c2083e(Matrix*,Matrix*);
Plane* __stdcall FUN_00c20838(Plane*,Plane*);
Plane* __stdcall FUN_00c20832(Plane*,Plane*,Matrix*);
void __stdcall FUN_00b3e480(RenderData*);
struct Shader {
    void FUN_00b415f0(Args*);
    Shader* UpdateFrustum(Clip* clip, Plane* src, Shader* volatile& owner);
    void FUN_00b40410(RenderData*,RenderGlobals*);
    void FUN_00b3e6a0(RenderData*,Root*,unsigned,int,Matrix*,int,void*);
    void FUN_00b40d30(Root*,unsigned,int,void*);
    void FUN_00b3e050(int,void*);
    void FUN_00b3e340(const char*);
    void FUN_00b3dee0(Matrix,void*);
    void FUN_00b3e3f0(RenderData*);
    void FUN_00b41030(const char*,RenderData*,Args*,unsigned);
    void FUN_00b41330(int,RenderData*);
    void FUN_00b3e440(RenderData*);
    void FUN_00b3e4d0();
    void FUN_00b40340(RenderData*,RenderGlobals*);
    void FUN_00b40490(Geometry*,RenderData*,RenderGlobals*);
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    Renderer* renderer;
    Renderer* GetRenderer() const { return renderer; }
    Handler* handler;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    int enableFirst;
    int enableSecond;
};
union Scratch {
    float vector[3];
    Plane plane;
    Scratch() {}
};
struct __declspec(align(16)) MatA : Matrix {};
static __forceinline Renderer* SetProjectionTranslation(Shader& object, double value, float& out)
{
    Renderer* r = object.GetRenderer();
    out = (float)value;
    return r;
}
__forceinline Shader* Shader::UpdateFrustum(Clip* clip, Plane* src, Shader* volatile& owner)
{
    Scratch one, two;
    Shader& current = *owner;
    Matrix view = current.GetRenderer()->view;
    Point3 cam;
    DAT_0116efb8->FUN_00af46d0(&cam);
    Renderer* projectionRenderer;
    float px, py, pz;
    {
        Point3& pos = *(Point3*)one.vector;
        Point3& col = *(Point3*)two.vector;
        col.x = view(0,0); col.y = view(1,0); col.z = view(2,0);
        px = cam.x + DAT_0108f04c; pos.x = px;
        py = cam.y + DAT_0108f050; pos.y = py;
        pz = cam.z + DAT_0108f054; pos.z = pz;
        view(3,0) = -pos.FUN_00475250(col);
    }
    {
        Point3& pos = *(Point3*)two.vector;
        Point3& col = *(Point3*)one.vector;
        col.x = view(0,1); col.y = view(1,1); col.z = view(2,1);
        pos.x = px; pos.y = py; pos.z = pz;
        view(3,1) = -pos.FUN_00475250(col);
    }
    {
        Point3& pos = *(Point3*)two.vector;
        Point3& col = *(Point3*)one.vector;
        col.x = view(0,2); col.y = view(1,2); col.z = view(2,2);
        pos.x = px; pos.y = py; pos.z = pz;
        projectionRenderer = SetProjectionTranslation(*owner, -pos.FUN_00475250(col), view(3,2));
    }
    Matrix proj = projectionRenderer->projection;
    MatA vp, inv;
    FUN_00c2082c(&vp, &view, &proj);
    FUN_00c20844(&inv, 0, &vp);
    FUN_00c2083e(&vp, &inv);
    Plane out[6];
    for (int i = 0; i < 6; i++)
    {
        memcpy(&cam, &src[i], sizeof(cam));
        Plane& p = one.plane;
        Plane& t = two.plane;
        p.a = cam.x; p.b = cam.y; p.c = cam.z;
        p.d = -src[i].d;
        FUN_00c20838(&p, &p);
        FUN_00c20832(&t, &p, &vp);
        out[i].a = t.a; out[i].b = t.b; out[i].c = t.c; out[i].d = t.d;
    }
    int i = 0;
    PlaneTarget** pt = &DAT_0108f048->target;
    for (; i < 6; i++)
        (*pt)->SetPlane(i, &out[i]);
    clip->FUN_00af4660(out);
    return owner;
}
// pdb: Lighting30Shader::SetupGeometryConstants | Lighting30Shader.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apState
void Shader::FUN_00b415f0(Args* args)
{
    Shader* self=this;
    Shader* volatile frustumOwner = this;
    unsigned mode=DAT_0116efd4;
    Root* root=DAT_0116efd0;
    Geometry* obj=root->obj;
    void* sub=&obj->sub;
    const char* name=obj->name;
    if(!name) name=DAT_0108edc8;
    int a=obj->value->value;
    int b=obj->index;
    RenderData* pc=args->data;
    int p8=args->param;
    Matrix mat;
    if(unsigned(mode-0x1d3)<=3 && (args->g0->flags&1)) FUN_00b0da80(0,1);
    FUN_00aabd50(sub,b,&mat);
    renderer->FUN_00874d00(sub,0);
    if(mode==0x1e0 || mode==0x1e1) {
        FUN_00b40340(pc,DAT_01091980);
        FUN_00b40490(obj,pc,DAT_01091980);
        FUN_00b3dee0(mat,sub);
    } else {
        if(mode==0xe || mode==0xf) FUN_00b40410(pc,DAT_01091980);
        FUN_00b3e6a0(pc,root,mode,p8,&mat,b,sub);
        FUN_00b40d30(root,mode,b,sub);
        FUN_00b3e050(b,sub);
        if(DAT_01176e4c->enabled)
            DAT_011770f0=float(DAT_0116f1fc/3600.0*6.283180236816406*pc->frequency);
        FUN_00b3e340(name);
        FUN_00b3dee0(mat,sub);
        FUN_00b3e3f0(pc);
        FUN_00b41030(name,pc,args,mode);
        FUN_00b41330(p8,pc);
        FUN_00b3e440(pc);
        if(DAT_01176e7c->enabled) {
            DAT_01177940=pc->fogNear;
            DAT_01177944=pc->fogFar;
        }
        FUN_00b3e480(pc);
        FUN_00b3e4d0();
        if(unsigned(mode-0x1c4)<=3) {
            Clip* clip=*DAT_0116efd0->clip;
            if(!clip->frozen && !FUN_00ad5a50()->a && !FUN_00ad5a50()->b) {
                self=UpdateFrustum(clip, clip->planes, frustumOwner);
            } else if(!FUN_00ad5a50()->a && !FUN_00ad5a50()->b) {
                Plane (&planes)[6] = clip->planes2;
                int i = 0;
                PlaneTarget** targets=&DAT_0108f048->target;
                for(;i<6;++i) (*targets)->SetPlane(i,&planes[i]);
            }
        }
    }
    if(self->enableFirst && DAT_01091980->firstHandle)
        DAT_01091980->first->Apply(DAT_01091980->firstHandle,obj,b,0,a,args,0,sub,name,0,1);
    if(self->enableSecond && DAT_01091980->secondHandle)
        DAT_01091980->second->Apply(DAT_01091980->secondHandle,obj,b,0,a,args,0,sub,name,0,1);
    Geometry* g=args->g10;
    if(g && (g->flags&1)) self->handler->Apply(g);
}
}

// @f3 0x00b4a480 (community match, verified in this file)
namespace nb4a480 {
struct Switch { unsigned int unk00, unk04; unsigned char b; };
struct V3 { float x, y, z; };
struct V4 { float x, y, z, w; V4() {} V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
struct Info { unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C; V3 v; float a; float b; unsigned int unk34;unsigned int unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4C;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5C; float c; };
extern unsigned char DAT_0116efb4;
extern Info* FUN_00adb920(unsigned char k);
extern float DAT_00e943f4;
extern V4 DAT_00f73210;
extern V4 DAT_01177ee8;
extern V4 DAT_01177ef8;
struct Pass
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
    Switch* unk170;
    unsigned int unk174;
    Switch* unk178;
    void FUN_00b4a480(unsigned int id);
};
// pdb: BSShaderNoLighting::SetupPassConstants | BSShaderNoLighting.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: auiCurrentPass
void Pass::FUN_00b4a480(unsigned int id)
{
    if (id >= 0x52 && id <= 0x57)
        unk170->b = true;
    else
        unk170->b = false;
    if ((id >= 0x4a && id <= 0x51) || id == 0x56 || id == 0x57)
        unk178->b = true;
    else
        unk178->b = false;
    Info* p = FUN_00adb920(DAT_0116efb4);
    if (p) {
        V3 v = p->v;
        float a = p->a;
        float b = p->b;
        float c = p->c;
        if (b == 0.0f && a == 0.0f) {
            DAT_01177ee8 = V4(DAT_00e943f4, 0.0f, c, 0.0f);
            DAT_01177ef8 = DAT_00f73210;
        } else {
            DAT_01177ee8 = V4(b, b - a, c, 0.0f);
            DAT_01177ef8 = V4(v.x, v.y, v.z, 1.0f);
        }
    }
}
}
