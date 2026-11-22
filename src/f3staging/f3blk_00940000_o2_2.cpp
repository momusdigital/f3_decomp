#include <windows.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00940000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009504f0 (community match, verified in this file)
extern DWORD DAT_010f3170;
extern const float DAT_00f7ad9c;
namespace f3m_009504f0 {



struct Heap04f0 {
    void* FUN_008f6d30(unsigned int size, int kind);
};

struct Obj04f0 {
    virtual ~Obj04f0();
    unsigned short allocSize;
    short refCount;
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    Obj04f0(int a, int b, float c, float d);
    static void* operator new(size_t size)
    {
        Heap04f0* heap = (Heap04f0*)TlsGetValue(DAT_010f3170);
        void* mem = heap->FUN_008f6d30(size, 0x27);
        ((Obj04f0*)mem)->allocSize = (unsigned short)size;
        return mem;
    }
    void Release()
    {
        if (allocSize != 0) {
            if (--refCount == 0)
                delete this;
        }
    }
};


struct Owner04f0 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void Dispatch(Obj04f0* obj);
    void FUN_009504f0(int a, int b, float c);
};

// pdb: bhkCylinderShape::Init | bhkCylinderShape.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arTop, arBottom, afRad
void Owner04f0::FUN_009504f0(int a, int b, float c)
{
    Obj04f0* obj = new Obj04f0(a, b, c, DAT_00f7ad9c);
    Dispatch(obj);
    obj->Release();
}
}   // namespace f3m_009504f0

// @f3 0x00944050 (community match, verified in this file)
namespace f3m_00944050 {


namespace f3m_00944050 {
extern unsigned int DAT_010f3170;
struct Allocator944 { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };

struct Item944
{
    virtual void Release(bool del) throw();
};

struct Base944
{
    virtual ~Base944() {}
    int unk04;
};
}

struct FUN_00944050 : f3m_00944050::Base944
{
    f3m_00944050::Item944** data;
    int size;
    int capacityAndFlags;
    virtual ~FUN_00944050() throw();
};

// pdb: hkpHavokSnapshot::ConvertListener::~ConvertListener | hkpHavokSnapshot.obj | fnv360_0822_retail, call_seq, high
FUN_00944050::~FUN_00944050() throw()
{
    for (int i = 0; i < size; i++)
    {
        f3m_00944050::Item944* item = data[i];
        if (item)
            item->Release(true);
    }
    if (!(capacityAndFlags & 0x80000000))
    {
        int cap = capacityAndFlags & 0x3fffffff;
        f3m_00944050::Allocator944* allocator = (f3m_00944050::Allocator944*)TlsGetValue(f3m_00944050::DAT_010f3170);
        allocator->FUN_008f6d90(data, cap * sizeof(void*), 0x17);
    }
}
}   // namespace f3m_00944050

// @f3 0x0095aec0 (community match, verified in this file)
#include <windows.h>
extern unsigned long hkMonitorStreamTls;
extern unsigned long DAT_010f3170;
namespace f3m_0095aec0 {

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);


struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

struct TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

static inline void Timer_Emit(const char* name)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        TimerCommand* h = (TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct ConstraintInput
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void disable();
};

class hkpConstraintInstance;

struct MemoryPool__FreePoolBlock
{
    MemoryPool__FreePoolBlock* m_pNext;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
};

class MemoryManager
{
public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    MemoryPool__FreePoolBlock* m_pFreeBlocks;
    int m_uiFreeBlockCount;
    void* Allocate(int aiType, int aiSize);
    void* PopBlock(int aiType, int aiSize)
    {
        MemoryPool__FreePoolBlock* pkBlock = m_pFreeBlocks;
        if (pkBlock)
        {
            --m_uiFreeBlockCount;
            m_pFreeBlocks = pkBlock->m_pNext;
            return pkBlock;
        }
        return Allocate(aiType, aiSize);
    }
};

struct hkpConstraintAtom
{
    unsigned short m_type;
    unsigned short m_unk02;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    unsigned short m_unk10;
};

struct hkpModifierConstraintAtom : hkpConstraintAtom
{
};

extern "C" hkpModifierConstraintAtom* __cdecl FUN_009a94f0(hkpConstraintInstance* apInstance, unsigned int auiType);
extern "C" void __cdecl FUN_009a9550(hkpConstraintInstance* apInstance, ConstraintInput* apInput,
                                      hkpModifierConstraintAtom* apAtom);

// pdb: hkpResponseModifier::disableConstraint | hkpResponseModifier.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpResponseModifier_disableConstraint(hkpConstraintInstance* apInstance, ConstraintInput* apInput)
{
    apInput->disable();
    Timer_Emit("TtDsblConstr");
    if (!FUN_009a94f0(apInstance, 27))
    {
        MemoryManager* pkHeap = (MemoryManager*)TlsGetValue(DAT_010f3170);
        hkpModifierConstraintAtom* pkAtom = (hkpModifierConstraintAtom*)pkHeap->PopBlock(3, 0x2c);
        if (pkAtom)
        {
            pkAtom->m_type = 0x1b;
            pkAtom->m_unk10 = 0x20;
        }
        else
        {
            pkAtom = 0;
        }

        FUN_009a9550(apInstance, apInput, pkAtom);
    }
    Timer_Emit("Et");
}
}   // namespace f3m_0095aec0

// @f3 0x00949bf0 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_00949bf0 {
struct Pool { void* Alloc(unsigned int size, unsigned int align); };
struct Obj { virtual ~Obj(); unsigned short unk4; short unk6; };
struct Src2 { int unk0; int unk4; int unk8; int unkc; float unk10; };
struct Vec { void Copy(const Vec* o); };
struct Holder { virtual void v0(); virtual void v1(); virtual void v2(); virtual Obj* Get(); };
void FUN_00930d80(float s, struct Node* n);

struct Blk { int a0; int a1; int a2; int a3; int a4; int a5; int a6; int a7; int a8; int a9; int aa; int ab; int ac; int ad; int ae; int af; };
struct Node {
    int unk0;
    unsigned short unk4;
    short unk6;
    int unk8; int unkc; int unk10; int unk14; int unk18; int unk1c;
    void* operator new(unsigned int) {
        Pool* p = (Pool*)TlsGetValue(DAT_010f3170);
        Node* n = (Node*)p->Alloc(0x140, 0x2c);
        n->unk4 = 0x140;
        return (void*)n;
    }
    Node();
    void FUN_00959c80(float f);
    Holder* FUN_00959f80();
    void FUN_00959ff0(Obj*);
    void FUN_0095a030(Obj*);
    void FUN_0095a010(Obj*);
    Blk blk20;
    Blk blk60;
    short unka0;
    unsigned char unka2;
    char unka3;
    int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4;
    float unkf8;
    int unkfc; int unk100;
    float unk104;
    float unk108;
    int unk10c; int unk110; int unk114; int unk118;
    float unk11c;
    int unk120; int unk124; int unk128;
    float unk12c;
    float unk130;
};
struct VecA { void Copy(const void*); };
struct Owner { int unk0; Node* unk4; void FUN_00949bf0(Node* dst, Src2* p); void FUN_008fc3f0(Node*, Src2*); };
// pdb: hkRagdollConstraintCinfo::CloneData | bhkRagdollConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apData, arCloneData
void Owner::FUN_00949bf0(Node* dst, Src2* p) {
    Node* src = unk4;
    if (dst == 0) dst = new Node() ;
    ((VecA*)&dst->blk20)->Copy(&src->blk20);
    ((VecA*)&dst->blk60)->Copy(&src->blk60);
    dst->unk11c = src->unk11c;
    dst->unk12c = src->unk12c;
    dst->unk130 = src->unk130;
    dst->unk104 = src->unk104;
    dst->unk108 = src->unk108;
    dst->FUN_00959c80(src->unkf8);
    float s = p->unk10;
    if (s != 1.0f) FUN_00930d80(s, dst);
    Holder* h = src->FUN_00959f80();
    if (h) {
        Obj* o = h->Get();
        dst->FUN_00959ff0(o);
        dst->FUN_0095a030(o);
        dst->FUN_0095a010(o);
        if (o->unk4 != 0) { if (--o->unk6 == 0) delete o; }
        dst->unka2 = src->unka2;
    }
    FUN_008fc3f0(dst, p);
}
}   // namespace f3m_00949bf0

// @f3 0x00943b30 (community match, verified in this file)
#include <windows.h>
extern unsigned long DAT_010f3170;
namespace f3m_00943b30 {
struct Alloc1148 { void* FUN_008f6d30(int,int); };
struct Payload1148 { int unk00; unsigned short type04; unsigned short unk06; int FUN_00943bb0(int,int); };
extern void FUN_00e7a270();
struct Object1148 {
 void* unk00; unsigned short unk04,unk06; int unk08;
 Object1148* FUN_00943b30(int value);
};
// pdb: hkOstream::hkOstream | hkOStream.obj | fnv360_0822_retail, call_dedup, high
// pdb params: buf
Object1148* Object1148::FUN_00943b30(int value) {
 unk06=1;
 unk00=(void*)FUN_00e7a270;
 Alloc1148* allocator=(Alloc1148*)TlsGetValue(DAT_010f3170);
 Payload1148* payload=(Payload1148*)allocator->FUN_008f6d30(0x14,0x1a);
 payload->type04=0x14;
 unk08=payload->FUN_00943bb0(value,1);
 return this;
}
}   // namespace f3m_00943b30

// @f3 0x00946120 (community match, verified in this file)
#include <windows.h>
namespace f3m_00946120 {
extern "C" void _ReadWriteBarrier(void);

struct Arg {
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
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
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
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};

struct Rec {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
};

class Cls00946120 {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual Rec* GetRec(Arg*& a);
    void FUN_008fb740(Arg* a);
    void FUN_00946120(Arg* a1);
};

// pdb: bhkSpringAction::LoadBinary | bhkSpringAction.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: bhkAngularDashpotAction::LoadBinary)
// pdb params: arStream
void Cls00946120::FUN_00946120(Arg* a1)
{
    Arg* a = *(Arg* volatile*)&a1;
    FUN_008fb740(a);
    if (a->m1E5 != 1) {
        Rec* r = GetRec(a1);
        if (r != 0) {
            r->m10 = _byteswap_ulong(r->m10);
            _ReadWriteBarrier();
            r->m14 = _byteswap_ulong(r->m14);
            _ReadWriteBarrier();
            r->m18 = _byteswap_ulong(r->m18);
            _ReadWriteBarrier();
            r->m1C = _byteswap_ulong(r->m1C);
            _ReadWriteBarrier();
            r->m20 = _byteswap_ulong(r->m20);
            _ReadWriteBarrier();
            r->m24 = _byteswap_ulong(r->m24);
            _ReadWriteBarrier();
            r->m28 = _byteswap_ulong(r->m28);
            _ReadWriteBarrier();
            r->m2C = _byteswap_ulong(r->m2C);
            _ReadWriteBarrier();
            r->m30 = _byteswap_ulong(r->m30);
            _ReadWriteBarrier();
            r->m34 = _byteswap_ulong(r->m34);
            _ReadWriteBarrier();
            r->m38 = _byteswap_ulong(r->m38);
            _ReadWriteBarrier();
        }
    }
}
}   // namespace f3m_00946120

// @f3 0x009459c0 (community match, verified in this file)
namespace f3m_009459c0 {


extern unsigned int DAT_010f3170;

struct Blk
{
    int unk00;
    unsigned short size04;
    unsigned short unk06;
};

struct Ctx { Blk* FUN_008f6d30(int size, int flag); };

struct __declspec(align(16)) Bnd
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
    float f30;
    float f34;
    float f38;
    float f3c;
};

struct Src
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
    float f30;
    float f34;
    float f38;
    float f3c;
    Bnd FUN_008fda10();
};

struct Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Src src;
};

class Geo;

class Owner
{
public:
    virtual void S000();
    virtual void S004();
    virtual void S008();
    virtual void S00C();
    virtual void S010();
    virtual void S014();
    virtual void S018();
    virtual void S01C();
    virtual void S020();
    virtual void S024();
    virtual void S028();
    virtual void S02C();
    virtual void S030();
    virtual void S034();
    virtual void S038();
    virtual void S03C();
    virtual void S040();
    virtual void S044();
    virtual void S048();
    virtual void S04C();
    virtual void S050();
    virtual void S054();
    virtual void S058();
    virtual void S05C();
    virtual void S060();
    virtual void S064();
    virtual void S068();
    virtual void S06C();
    virtual void S070();
    virtual void S074();
    virtual void S078();
    virtual void S07C();
    virtual void S080();
    virtual void S084();
    virtual void S088();
    virtual void S08C(Geo* g);
    virtual void S090();
    virtual void S094();
    virtual void S098();
    virtual void S09C();
    virtual void S0A0();
    virtual void S0A4();
    virtual void S0A8();
    virtual void S0AC();
    virtual void S0B0();
    virtual void S0B4();
    virtual void S0B8();
    virtual void SBC(Arg* arg);
    void FUN_009459c0(Arg* arg);
};

class Geo
{
public:
    int vtbl00;
    unsigned short unk04;
    unsigned short unk06;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
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
    static void* operator new(unsigned int size)
    {
        Ctx* ctx = (Ctx*)TlsGetValue(DAT_010f3170);
        Blk* b = ctx->FUN_008f6d30(size, 0x31);
        b->size04 = (unsigned short)size;
        return b;
    }
    Geo(int a, const Bnd& b, int c);
    void FUN_009316f0();
};

// pdb: bhkCachingShapePhantom::Init | bhkCachingShapePhantom.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arInfo
void Owner::FUN_009459c0(Arg* arg)
{
    if (arg != 0) {
        Geo* q = new Geo(arg->unk04, arg->src.FUN_008fda10(), arg->unk00);
        S08C(q);
        q->FUN_009316f0();
        SBC(arg);
    }
}
}   // namespace f3m_009459c0

// @f3 0x00946380 (community match, verified in this file)
#include <windows.h>
namespace f3m_00946380 {

extern DWORD DAT_010f3170;  // TLS index of the per-thread Havok memory

struct hkThreadMemory946380 {
    void* FUN_008f6d30(int size, int memClass);  // allocateChunk
};

struct hkBool946380 {
    char m_bool;
};

struct FNV_ALIGN(16) hkVector4_946380 {
    hkVector4_946380() {}
    hkVector4_946380(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    float x, y, z, w;
};

struct DescVec946380 {
    float x, y, z, w;
    
};

struct hkReferencedObject946380 {
    virtual ~hkReferencedObject946380();
    unsigned short m_memSizeAndFlags;  // 04
    short m_referenceCount;            // 06

    static void* operator new(size_t size) {
        hkThreadMemory946380* memory = (hkThreadMemory946380*)TlsGetValue(DAT_010f3170);
        hkReferencedObject946380* object = (hkReferencedObject946380*)memory->FUN_008f6d30(size, 0x29);
        object->m_memSizeAndFlags = (unsigned short)size;
        return object;
    }
    static void operator delete(void* p, size_t size);

    void removeReference() {
        if (m_memSizeAndFlags != 0) {
            m_referenceCount--;
            if (m_referenceCount == 0) {
                delete this;
            }
        }
    }
};

// hkpSpringAction
struct FUN_00d4d340 : hkReferencedObject946380 {
    FUN_00d4d340(void* entityA, void* entityB, unsigned long userData);
    void hkpSpringAction_setPositionsInBodySpace(const hkVector4_946380& pivotA, const hkVector4_946380& pivotB);  // setPositionsInWorldSpace
    void setStrength(float s) { m_strength = s; }
    void setDamping(float d) { m_damping = d; }
    void setRestLength(float l) { m_restLength = l; }
    void setOnCompression(hkBool946380 b) { m_onCompression = b; }
    void setOnExtension(hkBool946380 b) { m_onExtension = b; }

    void* m_world;             // 08
    void* m_island;            // 0c
    unsigned long m_userData;  // 10
    void* m_name;              // 14
    void* m_entityA;           // 18
    void* m_entityB;           // 1c
    hkVector4_946380 m_lastForce;    // 20
    hkVector4_946380 m_positionAinA; // 30
    hkVector4_946380 m_positionBinB; // 40
    float m_restLength;        // 50
    float m_strength;          // 54
    float m_damping;           // 58
    hkBool946380 m_onCompression;  // 5c
    hkBool946380 m_onExtension;    // 5d
};

struct SpringDesc946380 {
    int unk00;
    void* entityA;   // 04
    void* entityB;   // 08
    int unk0c;
    DescVec946380 pivotA;  // 10
    DescVec946380 pivotB;  // 20
    float restLength; // 30
    float strength;   // 34
    float damping;    // 38
    hkBool946380 onCompression;  // 3c
    hkBool946380 onExtension;    // 3d
};

struct World946380 {
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf0a(); virtual void vf0b();
    virtual void vf0c(); virtual void vf0d(); virtual void vf0e(); virtual void vf0f();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13();
    virtual void vf14(); virtual void vf15(); virtual void vf16(); virtual void vf17();
    virtual void vf18(); virtual void vf19(); virtual void vf1a(); virtual void vf1b();
    virtual void vf1c(); virtual void vf1d(); virtual void vf1e(); virtual void vf1f();
    virtual void vf20(); virtual void vf21(); virtual void vf22();
    virtual void AddAction(FUN_00d4d340* action);  // +0x8c
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf2a(); virtual void vf2b();
    virtual void vf2c(); virtual void vf2d(); virtual void vf2e();
    virtual void AddDesc(SpringDesc946380* desc);  // +0xbc

    void FUN_00946380(SpringDesc946380* desc);
};

// pdb: bhkSpringAction::Init | bhkSpringAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void World946380::FUN_00946380(SpringDesc946380* desc) {
    if (desc) {
        FUN_00d4d340* action = new FUN_00d4d340(desc->entityA, desc->entityB, 0);
        action->setStrength(desc->strength);
        action->setDamping(desc->damping);
        action->setRestLength(desc->restLength);
        action->setOnCompression(desc->onCompression);
        action->setOnExtension(desc->onExtension);
        action->hkpSpringAction_setPositionsInBodySpace(hkVector4_946380(desc->pivotA.x, desc->pivotA.y, desc->pivotA.z, desc->pivotA.w), hkVector4_946380(desc->pivotB.x, desc->pivotB.y, desc->pivotB.z, desc->pivotB.w));
        AddAction(action);
        action->removeReference();
        AddDesc(desc);
    }
}
}   // namespace f3m_00946380

// @f3 0x00946970 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_00946970 {
namespace Slot1Shape94 {
extern void*(__stdcall* const DAT_00d9b080)(DWORD);
struct Heap { void* FUN_008f6d30(unsigned, int); };
struct Raw4 {
    float x, y, z, w;
    Raw4(const Raw4& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};
struct Aligned4 {
    __declspec(align(16)) float x;
    float y, z, w;
    Aligned4(const Raw4& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Aligned4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
};
extern void __cdecl FUN_008f90f0(void*);
struct FUN_009da340;
struct ShapeTable { void(__thiscall* destroy)(FUN_009da340*, int); };
struct FUN_009da340 {
    ShapeTable* table;
    unsigned short size;
    short refs;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    FUN_009da340(void*, const Aligned4&, float, float);
    static void operator delete(void* p) { FUN_008f90f0(p); }
    static void* operator new(unsigned n) {
        Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
        FUN_009da340* result = (FUN_009da340*)heap->FUN_008f6d30(n, 0x29);
        result->size = (unsigned short)n;
        return result;
    }
};
struct Input {
    int unk00;
    void* object;
    int unk08, unk0C;
    Raw4 direction;
    float a, b;
    __forceinline Raw4 Direction() const { return Raw4(direction); }
};
struct Owner;
struct Table {
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
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void(__thiscall* set)(Owner*, FUN_009da340*);
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void(__thiscall* finish)(Owner*, Input*);
};
struct Owner { Table* table; void FUN_00946970(Input*); };
// pdb: bhkMotorAction::Init | bhkMotorAction.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInfo
void Owner::FUN_00946970(Input* input) {
    if (input) {
        FUN_009da340* shape = new FUN_009da340(input->object, Aligned4(input->direction.x, input->direction.y, input->direction.z, input->direction.w), input->a, input->b);
        table->set(this, shape);
        if (shape->size) {
            if (--shape->refs == 0) shape->table->destroy(shape, 1);
        }
        table->finish(this, input);
    }
}
}
}   // namespace f3m_00946970

// @f3 0x0094ea60 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_0094ea60 {
namespace Task3178 {
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct V { __declspec(align(16)) float x; float y,z,w; V(float a,float b,float c,float d):x(a),y(b),z(c),w(d){} };
struct Info {int unk00,unk04,unk08,unk0c;V a,b,c;};
struct RefBase {virtual void Destroy(int); unsigned short size; short refs;};
struct FUN_009e2ec0 : RefBase {
 int unk08,unk0c;
 V a,b,c;
 static void* operator new(unsigned int bytes) {Heap* h=(Heap*)TlsGetValue(DAT_010f3170);FUN_009e2ec0*p=(FUN_009e2ec0*)h->FUN_008f6d30(bytes,0x27);p->size=(unsigned short)bytes;return p;}
 static void operator delete(void* p);
 FUN_009e2ec0(const V&,const V&,const V&);
 void RemoveReference(){if(size && --refs==0)Destroy(1);}
};
struct Owner {
virtual void Slot00();
virtual void Slot04();
virtual void Slot08();
virtual void Slot0c();
virtual void Slot10();
virtual void Slot14();
virtual void Slot18();
virtual void Slot1c();
virtual void Slot20();
virtual void Slot24();
virtual void Slot28();
virtual void Slot2c();
virtual void Slot30();
virtual void Slot34();
virtual void Slot38();
virtual void Slot3c();
virtual void Slot40();
virtual void Slot44();
virtual void Slot48();
virtual void Slot4c();
virtual void Slot50();
virtual void Slot54();
virtual void Slot58();
virtual void Slot5c();
virtual void Slot60();
virtual void Slot64();
virtual void Slot68();
virtual void Slot6c();
virtual void Slot70();
virtual void Slot74();
virtual void Slot78();
virtual void Slot7c();
virtual void Slot80();
virtual void Slot84();
virtual void Slot88();
virtual void Add(FUN_009e2ec0*);
virtual void Slot90();
virtual void Slot94();
virtual void Slot98();
virtual void Slot9c();
virtual void Slota0();
virtual void Slota4();
virtual void Slota8();
virtual void Slotac();
virtual void Slotb0();
virtual void Slotb4();
virtual void Slotb8();
virtual void Finish(Info*);
 void FUN_0094ea60(Info* info);
};
void Owner::FUN_0094ea60(Info* info){
 if(info){FUN_009e2ec0* obj=new FUN_009e2ec0(V(info->a.x,info->a.y,info->a.z,info->a.w),V(info->c.x,info->c.y,info->c.z,info->c.w),V(info->b.x,info->b.y,info->b.z,info->b.w));Add(obj);obj->RemoveReference();Finish(info);}
}
}
}   // namespace f3m_0094ea60

// @f3 0x00942cf0 (community match, verified in this file)
#include <windows.h>
#include "havok/hkMonitorStream.h"
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern int DAT_00e32798;
namespace f3m_00942cf0 {



struct Vec4 { float x, y, z, w; };
struct Blk { Vec4 a; Vec4 b; Vec4 c; };

inline void S942_MinTo(Vec4& m, const Vec4& v)
{
    if (!(m.x < v.x)) m.x = v.x;
    if (!(m.y < v.y)) m.y = v.y;
    if (!(m.z < v.z)) m.z = v.z;
    if (!(m.w < v.w)) m.w = v.w;
}

inline void S942_MaxTo(Vec4& m, const Vec4& v)
{
    if (!(m.x > v.x)) m.x = v.x;
    if (!(m.y > v.y)) m.y = v.y;
    if (!(m.z > v.z)) m.z = v.z;
    if (!(m.w > v.w)) m.w = v.w;
}

struct MemStack
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* v14(unsigned int size);
    virtual void v18(void* p);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* cur;
    int unk24;
    char* unk28;
    char* end;
};

struct Obj
{
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54();
    virtual int  v58();
    virtual void v5c();
    virtual void v60(const Vec4* mn, void* dest);
};

struct Calc
{
    void FUN_00942be0(Obj* o, Blk* elem, void* src, void* dest, int off);
};

struct Owner
{
    void hkpWorldRayCaster_castRayGroup(Obj* a1, Blk* a2, int a3, char* a4, int a5, int a6);
};

// pdb: hkpWorldRayCaster::castRayGroup | hkpWorldRayCaster.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void Owner::hkpWorldRayCaster_castRayGroup(Obj* a1, Blk* a2, int a3, char* a4, int a5, int a6)
{

    HK_TIMER_BEGIN("RayCastGroup", HK_NULL);

    __declspec(align(16)) Vec4 mn;
    __declspec(align(16)) Vec4 mx;

    mn.x = a2->a.x < a2->b.x ? a2->a.x : a2->b.x;
    mn.y = a2->a.y < a2->b.y ? a2->a.y : a2->b.y;
    mn.z = a2->a.z < a2->b.z ? a2->a.z : a2->b.z;
    mn.w = a2->a.w < a2->b.w ? a2->a.w : a2->b.w;
    mx.x = a2->a.x > a2->b.x ? a2->a.x : a2->b.x;
    mx.y = a2->a.y > a2->b.y ? a2->a.y : a2->b.y;
    mx.z = a2->a.z > a2->b.z ? a2->a.z : a2->b.z;
    mx.w = a2->a.w > a2->b.w ? a2->a.w : a2->b.w;

    Blk* p = a2 + 1;
    {
        for (int i = a3 - 2; i >= 0; i--) {
            S942_MinTo(mn, p->b);
            S942_MinTo(mn, p->a);
            S942_MaxTo(mx, p->b);
            S942_MaxTo(mx, p->a);
            p++;
        }
    }

    Obj* o = a1;
    int cnt = o->v58();
    MemStack* ms = (MemStack*)TlsGetValue(DAT_010f3170);
    unsigned int sz = (cnt + 0x10) & 0xfffffff0;
    char* p0 = ms->cur;
    char* np = p0 + sz;
    char* dest;
    if (np <= ms->end) {
        ms->cur = np;
        dest = p0;
    } else {
        dest = (char*)ms->v14(sz);
    }
    o->v60(&mn, dest);

    p = a2;
    {
        char* src = a4;
        int off = a5;
        for (int j = a3 - 1; j >= 0; j--) {
            ((Calc*)this)->FUN_00942be0(a1, p, src, dest, off);
            p++;
            off += a6;
        }
    }

    MemStack* ms2 = (MemStack*)TlsGetValue(DAT_010f3170);
    ms2->cur = dest;
    if (dest == ms2->unk28) {
        ms2->v18(dest);
    }

    HK_TIMER_END();
}
}   // namespace f3m_00942cf0

// @f3 0x00945a80 (community match, verified in this file)
namespace f3m_00945a80 {


extern DWORD DAT_0116913c;
extern const char DAT_00e7a3fc[];
extern const char DAT_00e32798[];

struct S945a80_ProfRec {
    const char* m_pName;
    unsigned int m_iTick;
    unsigned int m_iEnd;

    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov ticks, eax } m_iTick = ticks; }
};

struct S945a80_ProfBuf {
    char* unk00;
    S945a80_ProfRec* m_pCur;
    int unk08;
    S945a80_ProfRec* m_pEnd;
};

struct S945a80_Vec4 {
    float x, y, z, w;
};

struct S945a80_Key {
    int value;
    S945a80_Key() {}
    S945a80_Key(const S945a80_Key& o) : value(o.value) {}
};

struct S945a80_Mat {
    float m00, m01, m02, unk0c;
    float m10, m11, m12, unk1c;
    float m20, m21, m22, unk2c;
    float tx, ty, tz, unk3c;
    const float* col(int c) const { return &m00 + 4 * c; }
    float get(int r, int c) const { return col(c)[r]; }
};

__forceinline void S945a80_RotInv(S945a80_Vec4& out, const S945a80_Mat* m, float dx, float dy, float dz)
{
    out.x = m->m00 * dx + m->m01 * dy + m->m02 * dz;
    // Fake match: the first element of the second and third rows is read through the column accessor and
    // the rest as members; this per-cell access form sets the x87 operand order of those two dot products.
    out.y = m->get(0, 1) * dx + m->m11 * dy + m->m12 * dz;
    out.z = m->get(0, 2) * dx + m->m21 * dy + m->m22 * dz;
    out.w = 0.0f;
}
__forceinline void S945a80_InvTransform(S945a80_Vec4& out, const S945a80_Mat* m, const S945a80_Vec4& in)
{
    float dx = in.x - m->tx;
    float dy = in.y - m->ty;
    float dz = in.z - m->tz;
    S945a80_RotInv(out, m, dx, dy, dz);
    out.w = 0.0f;
}

struct S945a80_RayIn {
    S945a80_Vec4 p0;
    S945a80_Vec4 p1;
    bool useFilter;
    S945a80_Key key;
};

struct __declspec(align(16)) S945a80_Ray {
    S945a80_Vec4 p0;
    S945a80_Vec4 p1;
    S945a80_Key key;
    void* filter;
};

struct __declspec(align(16)) S945a80_Info {
    S945a80_Vec4 point;
    float dist;
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
};

struct S945a80_Bool {
    char value;
    S945a80_Bool() {}
    S945a80_Bool(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};

struct S945a80_Shape {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual S945a80_Bool Pick(S945a80_Ray* ray, S945a80_Info* info);
};

struct S945a80_Entry {
    S945a80_Shape* shape;
    int unk04;
    S945a80_Mat* mat;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S945a80_Key key;
};

struct S945a80_Pair {
    int first;
    S945a80_Entry* second;
};

struct S945a80_Out {
    S945a80_Vec4 point;
    float dist;
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
    S945a80_Entry* entry;
};

struct S945a80_World {
    char unk00[0x70];
    char* unk70;
};

bool FUN_008f62d0(S945a80_Key a, S945a80_Key b);
void __stdcall hkVector4_setRotatedDir(S945a80_Mat* mat, S945a80_Out* out);

struct S945a80_Picker {
    int unk00;
    int unk04;
    S945a80_World* world;
    char pad[0x144];
    S945a80_Pair* pairs;
    int count;
    int GetCount() const { return count; }
    void hkpCachingShapePhantomRay_castRay(S945a80_RayIn* in, S945a80_Out* out);
};

// pdb: hkpCachingShapePhantomRay::castRay | bhkCachingShapePhantom.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void S945a80_Picker::hkpCachingShapePhantomRay_castRay(S945a80_RayIn* in, S945a80_Out* out)
{
    S945a80_ProfBuf* buf = (S945a80_ProfBuf*)TlsGetValue(DAT_0116913c);
    S945a80_ProfRec* rec = buf->m_pCur;
    bool room = rec < buf->m_pEnd;
    if (room) {
        rec->m_pName = DAT_00e7a3fc;
        rec->setTime();
        buf->m_pCur = rec + 1;
    }

    S945a80_Ray ray;
    S945a80_Info info;
    info.dist = 1.0f;
    info.unk14 = -1;
    info.unk20 = -1;
    info.unk40 = 0;
    ray.filter = 0;
    ray.key = in->key;
    ray.filter = (in->useFilter && world->unk70) ? world->unk70 + 0x10 : 0;

    bool found = false;
    for (int i = GetCount() - 1; i >= 0; --i) {
        S945a80_Entry* e = pairs[i].second;
        S945a80_Shape* shape = e->shape;
        if (shape) {
            S945a80_Key ek = e->key;
            if (FUN_008f62d0(in->key, ek)) {
                S945a80_Mat* mat = e->mat;
                S945a80_InvTransform(ray.p0, mat, in->p0);
                S945a80_InvTransform(ray.p1, mat, in->p1);
                info.dist = 1.0f;
                info.unk14 = -1;
                info.unk40 = 0;
                info.unk20 = -1;
                S945a80_Bool hit = shape->Pick(&ray, &info);
                if (hit) {
                    if (!found || info.dist < out->dist) {
                        out->dist = info.dist;
                        found = true;
                        out->entry = e;
                        out->point.x = info.point.x;
                        out->point.y = info.point.y;
                        out->point.z = info.point.z;
                        out->point.w = info.point.w;
                    }
                }
            }
        }
    }
    if (out->entry)
        hkVector4_setRotatedDir(out->entry->mat, out);

    buf = (S945a80_ProfBuf*)TlsGetValue(DAT_0116913c);
    rec = buf->m_pCur;
    if (rec < buf->m_pEnd) {
        rec->m_pName = DAT_00e32798;
        rec->setTime();
        buf->m_pCur = rec + 1;
    }
}
}   // namespace f3m_00945a80
