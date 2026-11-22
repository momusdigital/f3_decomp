// src/f3staging/f3blk_00a00000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a09310 (community match, verified in this file)
#include <string.h>
struct Matrix477 { float cells[16]; void FUN_008fda60(const Matrix477&); };
struct Triple477 {
    unsigned int first,second,third;
    __forceinline void operator=(const Triple477& value) { first=value.first;second=value.second;third=value.third; }
};
struct FUN_00a09310 {
    unsigned short type,unk02; unsigned int unk04,unk08,unk0c;
    Matrix477 first,second;
    unsigned int unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0;
    Triple477 tail;
    FUN_00a09310* Assign(const FUN_00a09310&);
};
// pdb: hkpPrismaticConstraintData::Atoms::operator= | hkpConstraintDataCloningUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: __that
FUN_00a09310* FUN_00a09310::Assign(const FUN_00a09310& source) {
    type=source.type;
    first.FUN_008fda60(source.first);
    second.FUN_008fda60(source.second);
    unk90=source.unk90;unk94=source.unk94;unk98=source.unk98;unk9c=source.unk9c;
    unka0=source.unka0;unka4=source.unka4;unka8=source.unka8;unkac=source.unkac;unkb0=source.unkb0;
    memcpy(&tail,&source.tail,sizeof(tail));
    return this;
}

// @f3 0x00a093d0 (community match, verified in this file)
namespace f3m_00a093d0 {
namespace f3m_00a093d0 {
struct EmbeddedState {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    void FUN_00a091b0(const EmbeddedState& source);
};

struct FUN_00a093d0 {
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    Matrix477 first;
    Matrix477 second;
    EmbeddedState state;
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
    unsigned short unk128;

    FUN_00a093d0* Assign(const FUN_00a093d0& source);
};

// pdb: hkpRagdollConstraintData::Atoms::operator= | hkpConstraintDataCloningUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: __that
FUN_00a093d0* FUN_00a093d0::Assign(const FUN_00a093d0& source) {
    type = source.type;
    first.FUN_008fda60(source.first);
    second.FUN_008fda60(source.second);
    state.FUN_00a091b0(source.state);
    unke0 = source.unke0;
    unke4 = source.unke4;
    unke8 = source.unke8;
    unkec = source.unkec;
    unkf0 = source.unkf0;
    unkf4 = source.unkf4;
    unkf8 = source.unkf8;
    unkfc = source.unkfc;
    unk100 = source.unk100;
    unk104 = source.unk104;
    unk108 = source.unk108;
    unk10c = source.unk10c;
    unk110 = source.unk110;
    unk114 = source.unk114;
    unk118 = source.unk118;
    unk11c = source.unk11c;
    unk120 = source.unk120;
    unk124 = source.unk124;
    unk128 = source.unk128;
    return this;
}
}
}   // namespace f3m_00a093d0

// @f3 0x00a04370 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_00a04370 {
namespace f3m_00a04370 {
struct QAlloc { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
__declspec(dllimport) QAlloc* __stdcall FUN_00d9b080(int) throw();
extern "C" void __cdecl FUN_00901f10(void* arr, int elemSize) throw();

struct QKey {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct QKeyArray {
    QKey** data;
    int size;
    unsigned int cap;
    QKeyArray() { data = 0; size = 0; cap = 0x80000000u; }
    ~QKeyArray()
    {
        if ((cap & 0x80000000u) == 0) {
            unsigned int n = cap & 0x3fffffff;
            QAlloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, n * 4, 0x17);
        }
    }
};
struct QEntry {
    QKey* key;
    int unk04;
    int count;
};
struct QCounter { virtual void v0(); virtual int Count(); };
struct QKeyEx {
    int unk00; unsigned short unk04; unsigned short unk06; int unk08;
    int type;
    QCounter counter;
    QKey* single14;
    QKey** list18;
};
inline void QPush(QKeyArray* out, QKey* v)
{
    if (out->size == (int)(out->cap & 0x3fffffff))
        FUN_00901f10(out, 4);
    out->data[out->size] = v;
    out->size++;
}
static __declspec(noinline) void FUN_00a04270(QKey* key, QKeyArray* out) throw()
{
    QKeyEx* k = (QKeyEx*)key;
    switch (k->type) {
    case 10: {
        for (int i = 0; i < k->counter.Count(); i++)
            QPush(out, k->list18[i * 4]);
        break;
    }
    case 11:
        QPush(out, k->single14);
        break;
    case 12:
        QPush(out, (QKey*)k->list18);
        break;
    case 20:
        QPush(out, k->single14);
        break;
    case 28:
        QPush(out, (QKey*)k->list18);
        break;
    }
}
}
using namespace f3m_00a04370;
struct FUN_00a04370_cls {
    QEntry* data;
    int size;
    unsigned int cap;
    void FUN_00a04370(QKey* k) throw();
};
void FUN_00a04370_cls::FUN_00a04370(QKey* k) throw()
{
    int idx = -1;
    for (int i = 0; i < size; i++) {
        if (data[i].key == k) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        data[idx].count++;
        return;
    }
    QEntry e;
    e.key = k;
    e.unk04 = 0;
    e.count = 1;
    if (size == (int)(cap & 0x3fffffff))
        FUN_00901f10(this, 12);
    data[size] = e;
    size++;
    if (k->unk04 != 0)
        k->unk06++;
    QKeyArray children;
    FUN_00a04270(k, &children);
    for (int j = 0; j < children.size; j++)
        FUN_00a04370(children.data[j]);
}
}   // namespace f3m_00a04370

// @f3 0x00a09840 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_00a09840 {
struct AllocB0 { void* FUN_008f6d30(int size, int tag); };
extern AllocB0* (__stdcall *DAT_00d9b080)(int);
struct MatrixB0 { float cells[16]; void FUN_008fda60(const MatrixB0&); };
struct NiDynamicEffect_GetRTTI {
    int vptr00;
    short unk04;
    short unk06;
    int unk08;
    short unk0c;
    short unk0e;
    int unk10;
    int unk14;
    int unk18;
    float f1c;
    unsigned char b20;
    unsigned char pad21[15];
    MatrixB0 m1;
    MatrixB0 m2;
    NiDynamicEffect_GetRTTI();
    static void* operator new(unsigned int size) { AllocB0* alloc = DAT_00d9b080(DAT_010f3170); NiDynamicEffect_GetRTTI* mem = (NiDynamicEffect_GetRTTI*)alloc->FUN_008f6d30(0xb0, 0x2c); *(short*)((char*)mem + 4) = 0xb0; return mem; }
};
struct SettingsB0 { int pad[4]; float scale; };
struct OwnerB0 {
    int unk00;
    NiDynamicEffect_GetRTTI* field4;
    void FUN_008fc3f0(NiDynamicEffect_GetRTTI* dest, SettingsB0* settings);
    void FUN_00a09840(NiDynamicEffect_GetRTTI* dest, SettingsB0* settings);
};

void OwnerB0::FUN_00a09840(NiDynamicEffect_GetRTTI* dest, SettingsB0* settings)
{
    NiDynamicEffect_GetRTTI* src = field4;
    if (!dest)
        dest = new NiDynamicEffect_GetRTTI();
    dest->f1c = src->f1c;
    dest->b20 = src->b20;
    dest->m1.FUN_008fda60(src->m1);
    dest->m2.FUN_008fda60(src->m2);
    float factor = settings->scale;
    if (factor != 1.0f) {
dest->m1.cells[12] *= factor;
        dest->m1.cells[13] *= factor;
        dest->m1.cells[14] *= factor;
        dest->m1.cells[15] *= factor;
float* p = &dest->m2.cells[12];
        for (int i = 0; i < 4; i++) { *p *= factor; p++; }
    }
    FUN_008fc3f0(dest, settings);
}
}   // namespace f3m_00a09840

// @f3 0x00a09ae0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00a09ae0 {
void SwapEndianBlocks(unsigned int*);
struct CC63E0_Context;
struct Stream477 {
 unsigned int unk0;
 unsigned int counter;
 unsigned int unk8;
 int (__cdecl *callback)(Stream477*, void*, int, unsigned int*, int);
};
struct CC63E0_Context {
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
 unsigned int unk194;
 unsigned int unk198;
 unsigned int unk19c;
 unsigned int unk1a0;
 unsigned int unk1a4;
 unsigned int unk1a8;
 unsigned int unk1ac;
 unsigned int unk1b0;
 unsigned int unk1b4;
 unsigned int unk1b8;
 unsigned int unk1bc;
 unsigned int unk1c0;
 unsigned int unk1c4;
 unsigned int unk1c8;
 unsigned int unk1cc;
 unsigned int unk1d0;
 unsigned int unk1d4;
 unsigned int unk1d8;
 unsigned int unk1dc;
 unsigned int unk1e0;
 unsigned char unk1e4;
 unsigned char unk1e5; unsigned char unk1e6; unsigned char unk1e7;
 unsigned int unk1e8;
 unsigned int unk1ec;
 unsigned int unk1f0;
 unsigned int unk1f4;
 unsigned int unk1f8;
 unsigned int unk1fc;
 unsigned int unk200;
 unsigned int unk204;
 unsigned int unk208;
 unsigned int unk20c;
 unsigned int unk210;
 unsigned int unk214;
 unsigned int unk218;
 unsigned int unk21c;
 unsigned int unk220;
 unsigned int unk224;
 unsigned int unk228;
 unsigned int unk22c;
 unsigned int unk230;
 unsigned int unk234;
 unsigned int unk238;
 unsigned int unk23c;
 unsigned int unk240;
 unsigned int unk244;
 unsigned int unk248;
 unsigned int unk24c;
 Stream477* stream;
};
struct Block477 {
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
};
struct Inner477 {
 unsigned int unk00;
 unsigned int unk04;
 unsigned int unk08;
 unsigned int unk0c;
 unsigned int unk10;
 unsigned int unk14;
 unsigned int unk18;
 unsigned int buf1c;
 unsigned char buf20; unsigned char unk21; unsigned char unk22; unsigned char unk23;
 unsigned int unk24;
 unsigned int unk28;
 unsigned int unk2c;
 Block477 block30;
 Block477 block70;
};
__forceinline void SwapWord477(unsigned int& value){value=_byteswap_ulong(value);}
__forceinline void SwapBlock477(Block477& b){SwapWord477(b.unk30);SwapWord477(b.unk34);SwapWord477(b.unk38);SwapWord477(b.unk3c);SwapEndianBlocks((unsigned int*)&b);}
struct ComponentSize477{unsigned int value;__forceinline ComponentSize477(unsigned int n):value(n){}__forceinline operator unsigned int*(){return &value;}};
struct Owner477 {
 unsigned int unk0;
 Inner477* inner;
 void SaveBase(CC63E0_Context*);
 void FUN_00a09ae0(CC63E0_Context*);
};

void Owner477::FUN_00a09ae0(CC63E0_Context* ctx) {
    CC63E0_Context* c = ctx;
    Inner477* p = inner;
    if (c->unk1e4 != 1) {

        SwapBlock477(p->block30);
        SwapBlock477(p->block70);
    }
    SaveBase(c);
    {

        Stream477* s;
        s = c->stream;
        s->counter += s->callback(s, &p->buf1c, 4, ComponentSize477(4), 1);
        s = c->stream;
        s->counter += s->callback(s, &p->buf20, 1, ComponentSize477(1), 1);
        s = c->stream;
        s->counter += s->callback(s, &p->block30, 0x40, ComponentSize477(0x40), 1);
        s = c->stream;
        s->counter += s->callback(s, &p->block70, 0x40, ComponentSize477(0x40), 1);
    }
    if (c->unk1e4 != 1) {
        SwapBlock477(p->block30);
        SwapBlock477(p->block70);
    }
}

}   // namespace f3m_00a09ae0

// @f3 0x00a02710 (community match, verified in this file)
namespace f3m_00a02710 {
struct F3Quat {
  float x,y,z,w;
  void FUN_00a02710(const F3Quat* b, F3Quat* out);
};
void F3Quat::FUN_00a02710(const F3Quat* b, F3Quat* out)
{
  const F3Quat* a = this;
  float tempY = a->z * b->x - x * b->z;
  float tempZ = b->y * x - b->x * a->y;
  out->x = a->y * b->z - a->z * b->y;
  out->y = tempY;
  out->z = tempZ;
  out->w = 0.0f;
  float bW = b->w;
  out->x -= x * bW;
  out->y -= y * bW;
  out->z -= a->z * bW;
  out->w -= w * bW;
  float aW = w;
  out->x += b->x * aW;
  out->y += b->y * aW;
  out->z += b->z * aW;
  out->w += b->w * aW;
  out->x = out->x + out->x;
  out->y = out->y + out->y;
  out->z = out->z + out->z;
  out->w = out->w + out->w;
  float dot = b->x * x + b->y * a->y + a->z * b->z + w * b->w;
  if (dot < 0.0f) {
    out->x = -out->x;
    out->y = -out->y;
    out->z = -out->z;
    out->w = -out->w;
  }
}


}   // namespace f3m_00a02710

// @f3 0x00a0d5e0 (community match, verified in this file)
#include <intrin.h>
namespace f3m_00a0d5e0 {
namespace f3m_00a0d5e0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void Clear() { x = y = z = w = 0.0f; }
    __forceinline void Add(const Vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
};
struct Context {
    unsigned int unk00, unk04, unk08, unk0c;
    Vec4 offset;
};
struct Record {
    unsigned char kind, unk01, unk02, unk03;
    unsigned int unk04, unk08, unk0c;
    Vec4 position;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    Vec4 linear, angular;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
// pdb: hkSolveApplyGravityByTheSteps | hkpSolver.obj | fnv360_0822_retail, call_seq, medium
// pdb params: info, accumulators, accumulatorsEnd
void __cdecl FUN_00a0d5e0(const Context* context, Record* begin, Record* end)
{
    Vec4 offset = context->offset;
    Record* current = begin;
    Record* limit = end;
    if (!end) limit = reinterpret_cast<Record*>(-1);
    while (current < limit) {
        switch (current->kind) {
        case 1:
        case 2:
            current->linear.Clear();
            current->angular.Clear();
            ++current;
            break;
        case 0:
            do {
                current->linear.Clear();
                current->angular.Clear();
                current->position.Add(offset);
                ++current;
            } while (current->kind == 0 && current < limit);
            break;
        case 3:
            return;
        default:
            __debugbreak();
            break;
        }
    }
}
}




}   // namespace f3m_00a0d5e0

// @f3 0x00a08ee0 (community match, verified in this file)
extern int DAT_01269dd8;
extern int DAT_0126908c;
namespace f3m_00a08ee0 {
struct S_a08ee0 {
    void* vtbl;
    unsigned short unk04;
    unsigned short m06;
    unsigned int unk08;
    unsigned int m0c;
    unsigned int unk10;
    void* m14;
};
void FUN_00a08ee0(S_a08ee0* p)
{
    if (p) {
        p->m06 = 1;
        p->vtbl = &DAT_01269dd8;
        p->m14 = &DAT_0126908c;
        p->m0c = 0xd;
    }
}
}   // namespace f3m_00a08ee0

// @f3 0x00a06b40 (community match, verified in this file)
namespace f3m_00a06b40 {
struct Flag_a06b40 { int value; };
struct Owner_a06b40 { void FUN_00a06b80(Flag_a06b40 flag); };
// pdb: finishLoadedObjecthkpBallGun | hkpUtilitiesReflections.obj | tesv_win, objopen_prop, low
void __cdecl FUN_00a06b40(Owner_a06b40* p) {
    Flag_a06b40 one = { 1 };
    if (p) p->FUN_00a06b80(one);
}
}   // namespace f3m_00a06b40

// @f3 0x00a06d30 (community match, verified in this file)
namespace f3m_00a06d30 {
struct Flag_a06d30 { int value; };
struct Owner_a06d30 { void FUN_00a70c30(Flag_a06d30 flag); };
// pdb: getVtablehkpStiffSpringChainData | hkpStiffSpringChainDataClass.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: finishLoadedObjecthkpStiffSpringChainData)
void __cdecl FUN_00a06d30(Owner_a06d30* p) {
    Flag_a06d30 one = { 1 };
    if (p) p->FUN_00a70c30(one);
}
}   // namespace f3m_00a06d30

// @f3 0x00a06df0 (community match, verified in this file)
namespace f3m_00a06df0 {
struct Flag_a06df0 { int value; };
struct Owner_a06df0 { void FUN_00a06e30(Flag_a06df0 flag); };
void __cdecl FUN_00a06df0(Owner_a06df0* p) {
    Flag_a06df0 one = { 1 };
    if (p) p->FUN_00a06e30(one);
}
}   // namespace f3m_00a06df0

// @f3 0x00a08e50 (community match, verified in this file)
namespace f3m_00a08e50 {

struct A08e50Object {
    int unk00;
    unsigned short unk04;

    void __thiscall FUN_00a08de0();
    int __thiscall FUN_00a08e50(unsigned char flag);
};

// pdb: hkpConvexVerticesConnectivity::`scalar deleting destructor' | hkpConvexVerticesConnectivityClass.obj | fnv360_0822_retail, vtable, high
int __thiscall A08e50Object::FUN_00a08e50(unsigned char flag)
{
    FUN_00a08de0();

    if ((flag & 1) != 0) {
        f3m_00a04370::QAlloc* allocator =
            (f3m_00a04370::QAlloc*)f3m_00a09840::DAT_00d9b080(DAT_010f3170);

        allocator->FUN_008f6d90(this, unk04, 0x27);
    }

    return (int)this;
}
}   // namespace f3m_00a08e50

// @f3 0x00a08be0 (community match, verified in this file)
extern unsigned int FUN_00e84fdc;
extern unsigned int FUN_00e84fd0;
extern unsigned int FUN_00e84fbc;
extern unsigned int FUN_00e84fb0;
extern unsigned int FUN_00e84fa4;
namespace f3m_00a08be0 {

struct FUN_00943410_Base {
    void FUN_00943410();
};

void __cdecl FUN_00a08be0(unsigned int* param_1) {
    if (param_1 != NULL) {
        FUN_00943410_Base* obj = reinterpret_cast<FUN_00943410_Base*>(param_1);
        obj->FUN_00943410();
        *param_1 = reinterpret_cast<unsigned int>(&FUN_00e84fdc);
        param_1[2] = reinterpret_cast<unsigned int>(&FUN_00e84fd0);
        param_1[3] = reinterpret_cast<unsigned int>(&FUN_00e84fbc);
        param_1[4] = reinterpret_cast<unsigned int>(&FUN_00e84fb0);
        param_1[5] = reinterpret_cast<unsigned int>(&FUN_00e84fa4);
        param_1[8] = 2;
    }
}
}   // namespace f3m_00a08be0

// @f3 0x00a08b30 (community match, verified in this file)
namespace f3m_00a08b30 {
struct A08B30Object {
    void __thiscall FUN_00943410();
};

// pdb: hkpNullCollisionFilter::hkpNullCollisionFilter | hkpWorld.obj | fnv360_0822_retail, caller_sim, low
void __cdecl FUN_00a08b30(unsigned int* param_1)
{
    if (param_1 != 0) {
        ((A08B30Object*)param_1)->FUN_00943410();
        param_1[0] = 0x00e34b64;
        param_1[2] = 0x00e34b58;
        param_1[3] = 0x00e34b44;
        param_1[4] = 0x00e34b38;
        param_1[5] = 0x00e34b2c;
        param_1[8] = 1;
    }
}
}   // namespace f3m_00a08b30

// @f3 0x00a08200 (community match, verified in this file)
namespace f3m_00a08200 {

struct A08200 {
    int unk00;
    unsigned short unk04;
    A08200* FUN_00a08200(int flag);
};

extern void __cdecl FUN_00a74870();

// pdb: hkpPointToPathConstraintData::`scalar deleting destructor' | hkpPointToPathConstraintData.obj | fnv360_0822_retail, vtable_prefix, medium
A08200* A08200::FUN_00a08200(int flag) {
    FUN_00a74870();

    if ((flag & 1) != 0) {
        f3m_00a04370::QAlloc* allocator =
            reinterpret_cast<f3m_00a04370::QAlloc*>(
                f3m_00a09840::DAT_00d9b080(DAT_010f3170));
        allocator->FUN_008f6d90(this, this->unk04, 0x2c);
    }

    return this;
}
}   // namespace f3m_00a08200

// @f3 0x00a08fc0 (community match, verified in this file)
extern void* FUN_00e8088c;
namespace f3m_00a08fc0 {

void __cdecl FUN_00a08fc0(unsigned int* param_1) {
    if (param_1 != 0) {
        *(volatile unsigned short*)((unsigned char*)param_1 + 6) = 1;
        *(volatile unsigned int*)((unsigned char*)param_1 + 0x14) = 0xe35eec;
        *(volatile unsigned int*)param_1 = (unsigned int)&FUN_00e8088c;
        *(volatile unsigned int*)((unsigned char*)param_1 + 0x14) = 0xe80864;
        *(volatile unsigned int*)((unsigned char*)param_1 + 0xc) = 0x15;
    }
}
}   // namespace f3m_00a08fc0

// @f3 0x00a06cf0 (community match, verified in this file)
extern unsigned int FUN_00e802f8;
namespace f3m_00a06cf0 {

void __cdecl FUN_00a06cf0(unsigned int* param_1)
{
    if (param_1 != 0) {
        *((unsigned short*)((char*)param_1 + 6)) = 1;
        *param_1 = (unsigned int)&FUN_00e802f8;
    }
}
}   // namespace f3m_00a06cf0

// @f3 0x00a085c0 (community match, verified in this file)
struct CpuOpaque;
extern struct CpuOpaque DAT_0126997c;
struct StubA085
{
    CpuOpaque* unk00;
    unsigned short unk04;
    unsigned short unk06;
};
void __cdecl FUN_00a085c0(StubA085* p)
{
    if (p) {
        p->unk06 = 1;
        p->unk00 = &DAT_0126997c;
    }
}

// @f3 0x00a07bd0 (community match, verified in this file)
extern unsigned int FUN_00e83c44;
extern unsigned int FUN_00e83c38;
extern unsigned int FUN_00e83c24;
extern unsigned int FUN_00e83c18;
extern unsigned int FUN_00e83c0c;
namespace f3m_00a07bd0 {
struct FNV_A07bd0_Base {
    void FUN_00943410();
};

void __cdecl FUN_00a07bd0(unsigned int* param_1)
{
    if (param_1 != 0) {
        ((FNV_A07bd0_Base*)param_1)->FUN_00943410();
        param_1[0] = (unsigned int)&FUN_00e83c44;
        param_1[2] = (unsigned int)&FUN_00e83c38;
        param_1[3] = (unsigned int)&FUN_00e83c24;
        param_1[4] = (unsigned int)&FUN_00e83c18;
        param_1[5] = (unsigned int)&FUN_00e83c0c;
    }
}
}   // namespace f3m_00a07bd0

// @f3 0x00a09010 (community match, verified in this file)
extern char DAT_00e853ac;
extern char DAT_00e853a0;
extern char DAT_00e8538c;
extern char DAT_00e85380;
extern char DAT_00e85374;
namespace f3m_00a09010 {

struct Obj09010
{
    void* vt00;
    int unk04;
    void* vt08;
    void* vt0C;
    void* vt10;
    void* vt14;
    int unk18;
    int unk1C;
    int count20;
    void FUN_00943410();
};

void __cdecl FUN_00a09010(Obj09010* p)
{
    if (p != 0)
    {
        p->FUN_00943410();
        p->vt00 = (void*)&DAT_00e853ac;
        p->vt08 = (void*)&DAT_00e853a0;
        p->vt0C = (void*)&DAT_00e8538c;
        p->vt10 = (void*)&DAT_00e85380;
        p->vt14 = (void*)&DAT_00e85374;
        p->count20 = 3;
    }
}
}   // namespace f3m_00a09010

// @f3 0x00a07d40 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_00a07d40 {
struct A07d40Allocator {
    void FUN_008f6d90(void* object, unsigned int size, int tag);
};

extern A07d40Allocator* (__stdcall *DAT_00d9b080)(int);

struct A07d40Class {
    int unk00;
    unsigned short unk04;
    void FUN_00a740c0();
    int FUN_00a07d40(unsigned char flag);
};

// pdb: hkpDisableEntityCollisionFilter::`scalar deleting destructor' | hkpDisableEntityCollisionFilterClass.obj | fnv360_0822_retail, vtable, high
int A07d40Class::FUN_00a07d40(unsigned char flag)
{
    FUN_00a740c0();
    if ((flag & 1) != 0) {
        A07d40Allocator* allocator = DAT_00d9b080(DAT_010f3170);
        unsigned int size = unk04;
        allocator->FUN_008f6d90(this, size, 0x27);
    }
    return (int)this;
}
}   // namespace f3m_00a07d40

// @f3 0x00a09130 (community match, verified in this file)
namespace f3m_00a09130 {
extern void FUN_00e36438();
extern void FUN_00e36414();

void FUN_00a09130(unsigned int* param_1)
{
    if (param_1 != 0) {
        *(unsigned short*)((unsigned char*)param_1 + 6) = 1;
        *(unsigned int*)param_1 = (unsigned int)(unsigned long)&FUN_00e36438;
        *(unsigned int*)((unsigned char*)param_1 + 0x14) =
            (unsigned int)(unsigned long)&FUN_00e36414;
        *(unsigned int*)((unsigned char*)param_1 + 0x0c) = 0x1a;
    }
}
}   // namespace f3m_00a09130

// @f3 0x00a07a20 (community match, verified in this file)
namespace f3m_00a07a20 {
struct FUN_00a07a20_Object {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
};

void FUN_00e83a0c();

// pdb: finishLoadedObjecthkpSerializedDisplayMarker | hkpSerializedDisplayMarkerClass.obj | fnv360_0721_beta, objrun_open, low
void __cdecl FUN_00a07a20(unsigned int* param_1) {
    if (param_1 != 0) {
        FUN_00a07a20_Object* object = (FUN_00a07a20_Object*)param_1;
        object->unk06 = 1;
        object->unk00 = (void*)&FUN_00e83a0c;
    }
}
}   // namespace f3m_00a07a20

// @f3 0x00a068f0 (community match, verified in this file)
namespace f3m_00a068f0 {
struct FUN_00a068f0_Obj {
    unsigned int unk00;
    unsigned short unk04;

    void FUN_00a6f800();
    FUN_00a068f0_Obj* FUN_00a068f0(unsigned char flag);
};

// pdb: hkpSerializedAgentNnEntry::`scalar deleting destructor' | hkpSaveContactPointsUtil.obj | fnv360_0822_retail, vtable, high
FUN_00a068f0_Obj* FUN_00a068f0_Obj::FUN_00a068f0(unsigned char flag)
{
    FUN_00a6f800();

    if ((flag & 1) != 0) {
        f3m_00a04370::QAlloc* allocator =
            (f3m_00a04370::QAlloc*)f3m_00a09840::DAT_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(this, unk04, 0xd);
    }

    return this;
}
}   // namespace f3m_00a068f0

// @f3 0x00a08b70 (community match, verified in this file)
extern void* const DAT_00e34b64[];
namespace f3m_00a08b70 {
namespace f3m_00a08b70 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct Base {
    void* const* vptr;
    int unk04, unk08, unk0c;
    Base();
};
struct Shape : Base {
    Vec4 center;
    Vec4 extent;
    Shape() { vptr = DAT_00e34b64; }
};
void* const* __cdecl FUN_00a08b70()
{
    Shape shape;
    return shape.vptr;
}
}
}   // namespace f3m_00a08b70

// @f3 0x00a00cf0 (community match, verified in this file)
namespace f3m_00a00cf0 {
struct Cls_00a00cf0 {
    unsigned char m_ucFlag00;
    unsigned char m_ucFlag01;
    unsigned short unk02;
    int m_iValue04;
    void* unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;
    float m_f40;
    float m_f44;
    float m_f48;
    float m_f4c;
    float m_f50;
    float m_f54;
    float m_f58;
    float m_f5c;
    float m_f60;
    float m_f64;
    float m_f68;
    float m_f6c;
    float m_f70;
    float m_f74;
    float m_f78;
    float m_f7c;

    Cls_00a00cf0* FUN_00a00cf0(const Cls_00a00cf0* pSrc);
};

// pdb: hkpVelocityAccumulator::operator= | hkpConstraintSolverSetup.obj | fnv360_0822_debug, call_gap, low
// pdb params: __that
Cls_00a00cf0* Cls_00a00cf0::FUN_00a00cf0(const Cls_00a00cf0* pSrc)
{
    m_ucFlag00 = pSrc->m_ucFlag00;
    m_ucFlag01 = pSrc->m_ucFlag01;
    m_iValue04 = pSrc->m_iValue04;
    m_f10 = pSrc->m_f10;
    m_f14 = pSrc->m_f14;
    m_f18 = pSrc->m_f18;
    m_f1c = pSrc->m_f1c;
    m_f20 = pSrc->m_f20;
    m_f24 = pSrc->m_f24;
    m_f28 = pSrc->m_f28;
    m_f2c = pSrc->m_f2c;
    m_f30 = pSrc->m_f30;
    m_f34 = pSrc->m_f34;
    m_f38 = pSrc->m_f38;
    m_f3c = pSrc->m_f3c;
    m_f40 = pSrc->m_f40;
    m_f44 = pSrc->m_f44;
    m_f48 = pSrc->m_f48;
    m_f4c = pSrc->m_f4c;
    m_f50 = pSrc->m_f50;
    m_f54 = pSrc->m_f54;
    m_f58 = pSrc->m_f58;
    m_f5c = pSrc->m_f5c;
    m_f60 = pSrc->m_f60;
    m_f64 = pSrc->m_f64;
    m_f68 = pSrc->m_f68;
    m_f6c = pSrc->m_f6c;
    m_f70 = pSrc->m_f70;
    m_f74 = pSrc->m_f74;
    m_f78 = pSrc->m_f78;
    m_f7c = pSrc->m_f7c;
    return this;
}
}   // namespace f3m_00a00cf0

// @f3 0x00a08240 (community match, verified in this file)
extern void* const FUN_00e7d9ac[];
namespace f3m_00a08240 {
namespace f3m_00a08240 {


struct Obj {
    void* const* vptr;
    short unk04;
    short unk06;
};

void __cdecl FUN_00a08240(Obj* obj)
{
    if (obj) {
        obj->unk06 = 1;
        obj->vptr = FUN_00e7d9ac;
    }
}

}
}   // namespace f3m_00a08240

// @f3 0x00a069d0 (community match, verified in this file)
namespace f3m_00a069d0 {

struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;

struct Array {
    int* data;
    int size;
    int capacity;
};

void __cdecl FUN_00a069d0(Array* array)
{
    if (((unsigned)array->capacity & 0x80000000u) == 0) {
        int count = array->capacity & 0x3fffffff;
        Heap* heap = FUN_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(array->data, count * sizeof(int), 0x17);
    }
}

}

// @f3 0x00a0a2f0 (community match, verified in this file)
namespace f3m_00a0a2f0 {
namespace f3m_00a0a2f0 {

struct List {
    void* data;
    int capacity;
    int last;
    int FUN_00922790(void* item);
    void FUN_00922860(int index);
};

struct Owner {
    void* vtable;
    int unk04;
    List items;
    void FUN_00a0a2f0(void* item);
};

// pdb: hkMapBase<void *,int,struct hkMapOperations<void *> >::remove | hkTempDetectAllocator.obj | tesv_win, caller_sim, low
void Owner::FUN_00a0a2f0(void* item)
{
    int index = items.FUN_00922790(item);
    if (index <= items.last)
        items.FUN_00922860(index);
}

}
}   // namespace f3m_00a0a2f0

// @f3 0x00a08670 (community match, verified in this file)
extern void* const FUN_00e84c54[];
namespace f3m_00a08670 {
namespace f3m_00a08670 {


struct Obj {
    void* const* vptr;
    short unk04;
    short unk06;
};

void __cdecl FUN_00a08670(Obj* obj)
{
    if (obj) {
        obj->unk06 = 1;
        obj->vptr = FUN_00e84c54;
    }
}

}
}   // namespace f3m_00a08670

// @f3 0x00a06f20 (community match, verified in this file)
extern void* const FUN_00e8032c[];
namespace f3m_00a06f20 {
namespace f3m_00a06f20 {


struct Flag { char value; Flag(bool b) : value(b) {} Flag(const Flag& o) : value(o.value) {} };

struct Obj {
    void* const* vptr;
    short unk04;
    short unk06;
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94;
    short unk98;
    bool enabled;
    void FUN_009dc7f0(Flag flag);
};

// pdb: finishLoadedObjecthkpRagdollLimitsData | hkpRagdollLimitsDataClass.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void __cdecl finishLoadedObjecthkpRagdollLimitsData(Obj* obj)
{
    if (obj) {
        obj->unk06 = 1;
        obj->vptr = FUN_00e8032c;
        if (obj->enabled)
            obj->FUN_009dc7f0(Flag(true));
    }
}

}
}   // namespace f3m_00a06f20

// @f3 0x00a07c60 (community match, verified in this file)
namespace f3m_00a07c60 {
namespace f3m_00a07c60 {
struct hkFinishLoadedObjectFlag { int m_finishing; };
struct Obj { int unk00; void FUN_00a07ca0(hkFinishLoadedObjectFlag flag); };
void __cdecl FUN_00a07c60(Obj* obj)
{
    hkFinishLoadedObjectFlag flag;
    flag.m_finishing = 1;
    if (obj)
        obj->FUN_00a07ca0(flag);
}
}
}   // namespace f3m_00a07c60

// @f3 0x00a08960 (community match, verified in this file)
extern void* const FUN_00e7dff4[];
extern const char FUN_00e36414[];
namespace f3m_00a08960 {
namespace f3m_00a08960 {


struct Obj {
    void* const* vptr;
    short unk04;
    short unk06;
    int unk08;
    int type;
    const char* name;
};

void __cdecl FUN_00a08960(Obj* obj)
{
    if (obj) {
        obj->unk06 = 1;
        obj->vptr = FUN_00e7dff4;
        obj->name = FUN_00e36414;
        obj->type = 9;
    }
}

}
}   // namespace f3m_00a08960

// @f3 0x00a06e30 (community match, verified in this file)
extern void* const DAT_00e7dddc[];
namespace f3m_00a06e30 {
namespace f3m_00a06e30 {
struct hkFinishLoadedObjectFlag { int m_finishing; };
struct hkArray {
    void* data;
    int size;
    int capacityAndFlags;
    hkArray(hkFinishLoadedObjectFlag) : data(0), size(0), capacityAndFlags(0x80000000) {}
};
struct Base {
    void* const* vptr;
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    Base(hkFinishLoadedObjectFlag flag);
};
struct Mid : Base {
    hkArray first;
    hkArray second;
    int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c;
    Mid(hkFinishLoadedObjectFlag flag) : Base(flag), first(flag), second(flag) { vptr = DAT_00e7dddc; }
};
struct Shape : Mid {
    hkArray third;
    Shape(hkFinishLoadedObjectFlag flag);
};
Shape::Shape(hkFinishLoadedObjectFlag flag) : Mid(flag), third(flag)
{
}
}
}   // namespace f3m_00a06e30

// @f3 0x00a09180 (community match, verified in this file)
extern int g_unk01269ec8;
namespace f3m_00a09180 {
namespace f3m_00a09180 {
struct S_a09180 {
    void* vtbl;
    unsigned short unk04;
    unsigned short m06;
    unsigned int unk08;
    unsigned int m0c;
};
void FUN_00a09180(S_a09180* p)
{
    if (p) {
        p->m06 = 1;
        p->vtbl = &g_unk01269ec8;
        p->m0c = 5;
    }
}
}
}   // namespace f3m_00a09180

// @f3 0x00a070c0 (community match, verified in this file)
namespace f3m_00a070c0 {
namespace f3m_00a070c0 {
struct hkFinishLoadedObjectFlag { int m_finishing; };
struct Obj { int unk00; void FUN_00a71730(hkFinishLoadedObjectFlag flag); };
// pdb: getVtablehkpPoweredChainData | hkpPoweredChainDataClass.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: finishLoadedObjecthkpPoweredChainData)
void __cdecl FUN_00a070c0(Obj* obj)
{
    hkFinishLoadedObjectFlag flag;
    flag.m_finishing = 1;
    if (obj)
        obj->FUN_00a71730(flag);
}
}
}   // namespace f3m_00a070c0

// @f3 0x00a08d20 (community match, verified in this file)
extern char FUN_00e34b74;
namespace f3m_00a08d20 {

void __cdecl FUN_00a08d20(unsigned int* param_1) {
    if (param_1 != 0) {
        *reinterpret_cast<short*>(static_cast<char*>(static_cast<void*>(param_1)) + 6) = 1;
        *param_1 = reinterpret_cast<unsigned int>(reinterpret_cast<const char*>(&FUN_00e34b74));
    }
}
}   // namespace f3m_00a08d20

// @f3 0x00a07960 (community match, verified in this file)
namespace f3m_00a07960 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;
struct hkBaseObject {
    virtual ~hkBaseObject() throw() {}
};
struct hkReferencedObject : hkBaseObject {
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference() throw()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                delete this;
        }
    }
};
template<class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    ~hkArray() throw()
    {
        if (((unsigned)capacityAndFlags & 0x80000000u) == 0) {
            int capacity = capacityAndFlags & 0x3fffffff;
            Heap* heap = FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
struct Container : hkBaseObject {
    int unk04;
    hkArray<hkReferencedObject*> objects;
    virtual ~Container() throw();
};
// pdb: hkpSerializedDisplayMarkerList::~hkpSerializedDisplayMarkerList | hkpSerializedDisplayMarkerListClass.obj | fnv360_0822_retail, call_seq, high
Container::~Container() throw()
{
    for (int i = 0; i < objects.size; i++)
        objects.data[i]->removeReference();
}
}

// @f3 0x00a077e0 (community match, verified in this file)
extern int DAT_01269104;
namespace f3m_00a077e0 {


struct FUN_00a077e0_Obj {
    int* vtbl;
    unsigned short unk04;
    unsigned short unk06;
};

// pdb: finishLoadedObjecthkpConvexPieceStreamData | hkpConvexPieceStreamDataClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00a077e0(FUN_00a077e0_Obj* p)
{
    if (p) {
        p->unk06 = 1;
        p->vtbl = &DAT_01269104;
    }
}
}   // namespace f3m_00a077e0

// @f3 0x00a06940 (community match, verified in this file)
namespace f3m_00a06940 {
namespace f3m_00a06940 {
extern int DAT_010cf9a4;   // vtable at 0x00e81b18
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpSerializedDisplayRbTransforms | hkpSerializedDisplayRbTransformsClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00a06940(f3m_00a06940::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a06940::DAT_010cf9a4;
    }
}
}   // namespace f3m_00a06940

// @f3 0x00a06ac0 (community match, verified in this file)
namespace f3m_00a06ac0 {
namespace f3m_00a06ac0 {
extern int DAT_01268bcc;   // vtable at 0x00e81c94
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpPoweredChainMapper | hkpPoweredChainMapperClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00a06ac0(f3m_00a06ac0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a06ac0::DAT_01268bcc;
    }
}
}   // namespace f3m_00a06ac0

// @f3 0x00a06c90 (community match, verified in this file)
namespace f3m_00a06c90 {
namespace f3m_00a06c90 {
extern int DAT_01268c14;   // vtable at 0x00e802c4
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a06c90(f3m_00a06c90::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a06c90::DAT_01268c14;
    }
}
}   // namespace f3m_00a06c90

// @f3 0x00a06da0 (community match, verified in this file)
namespace f3m_00a06da0 {
namespace f3m_00a06da0 {
extern int DAT_01268c8c;   // vtable at 0x00e7d270
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a06da0(f3m_00a06da0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a06da0::DAT_01268c8c;
    }
}
}   // namespace f3m_00a06da0

// @f3 0x00a07000 (community match, verified in this file)
namespace f3m_00a07000 {
namespace f3m_00a07000 {
extern int DAT_01268d94;   // vtable at 0x00e82534
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07000(f3m_00a07000::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07000::DAT_01268d94;
    }
}
}   // namespace f3m_00a07000

// @f3 0x00a07080 (community match, verified in this file)
namespace f3m_00a07080 {
namespace f3m_00a07080 {
extern int DAT_01268dc4;   // vtable at 0x00e80360
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07080(f3m_00a07080::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07080::DAT_01268dc4;
    }
}
}   // namespace f3m_00a07080

// @f3 0x00a07140 (community match, verified in this file)
namespace f3m_00a07140 {
namespace f3m_00a07140 {
extern int DAT_01268df4;   // vtable at 0x00e82898
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07140(f3m_00a07140::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07140::DAT_01268df4;
    }
}
}   // namespace f3m_00a07140

// @f3 0x00a071b0 (community match, verified in this file)
namespace f3m_00a071b0 {
namespace f3m_00a071b0 {
extern int DAT_01268e24;   // vtable at 0x00e36d04
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a071b0(f3m_00a071b0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a071b0::DAT_01268e24;
    }
}
}   // namespace f3m_00a071b0

// @f3 0x00a07210 (community match, verified in this file)
namespace f3m_00a07210 {
namespace f3m_00a07210 {
extern int DAT_01268e6c;   // vtable at 0x00e803e0
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07210(f3m_00a07210::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07210::DAT_01268e6c;
    }
}
}   // namespace f3m_00a07210

// @f3 0x00a07270 (community match, verified in this file)
namespace f3m_00a07270 {
namespace f3m_00a07270 {
extern int g_unk01268eb4;   // vtable at 0x00e37524
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07270(f3m_00a07270::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07270::g_unk01268eb4;
    }
}
}   // namespace f3m_00a07270

// @f3 0x00a07370 (community match, verified in this file)
namespace f3m_00a07370 {
namespace f3m_00a07370 {
extern int g_unk01268efc;   // vtable at 0x00e804a8
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07370(f3m_00a07370::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07370::g_unk01268efc;
    }
}
}   // namespace f3m_00a07370

// @f3 0x00a078e0 (community match, verified in this file)
namespace f3m_00a078e0 {
namespace f3m_00a078e0 {
extern int DAT_010d08f4;   // vtable at 0x00e80220
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a078e0(f3m_00a078e0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a078e0::DAT_010d08f4;
    }
}
}   // namespace f3m_00a078e0

// @f3 0x00a07930 (community match, verified in this file)
namespace f3m_00a07930 {
namespace f3m_00a07930 {
extern int DAT_010cc4f4;   // vtable at 0x00e839e4
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpSerializedDisplayMarkerList | hkpSerializedDisplayMarkerListClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00a07930(f3m_00a07930::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07930::DAT_010cc4f4;
    }
}
}   // namespace f3m_00a07930

// @f3 0x00a07a90 (community match, verified in this file)
namespace f3m_00a07a90 {
namespace f3m_00a07a90 {
extern int g_unk0126958c;   // vtable at 0x00e83a7c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07a90(f3m_00a07a90::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07a90::g_unk0126958c;
    }
}
}   // namespace f3m_00a07a90

// @f3 0x00a07ae0 (community match, verified in this file)
namespace f3m_00a07ae0 {
namespace f3m_00a07ae0 {
extern int DAT_012695bc;   // vtable at 0x00e8014c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07ae0(f3m_00a07ae0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07ae0::DAT_012695bc;
    }
}
}   // namespace f3m_00a07ae0

// @f3 0x00a07b80 (community match, verified in this file)
namespace f3m_00a07b80 {
namespace f3m_00a07b80 {
extern int DAT_012695ec;   // vtable at 0x00e80244
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07b80(f3m_00a07b80::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07b80::DAT_012695ec;
    }
}
}   // namespace f3m_00a07b80

// @f3 0x00a07d70 (community match, verified in this file)
namespace f3m_00a07d70 {
namespace f3m_00a07d70 {
extern int g_unk0126961c;   // vtable at 0x00e80268
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07d70(f3m_00a07d70::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07d70::g_unk0126961c;
    }
}
}   // namespace f3m_00a07d70

// @f3 0x00a07fa0 (community match, verified in this file)
namespace f3m_00a07fa0 {
namespace f3m_00a07fa0 {
extern int DAT_012696c4;   // vtable at 0x00e7cf30
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07fa0(f3m_00a07fa0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07fa0::DAT_012696c4;
    }
}
}   // namespace f3m_00a07fa0

// @f3 0x00a07fe0 (community match, verified in this file)
namespace f3m_00a07fe0 {
namespace f3m_00a07fe0 {
extern int DAT_0126970c;   // vtable at 0x00e35cac
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a07fe0(f3m_00a07fe0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a07fe0::DAT_0126970c;
    }
}
}   // namespace f3m_00a07fe0

// @f3 0x00a08020 (community match, verified in this file)
namespace f3m_00a08020 {
namespace f3m_00a08020 {
extern int DAT_01269754;   // vtable at 0x00e35afc
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: cleanupLoadedObjecthkpKeyframedRigidMotion | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00a08020(f3m_00a08020::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08020::DAT_01269754;
    }
}
}   // namespace f3m_00a08020

// @f3 0x00a08060 (community match, verified in this file)
namespace f3m_00a08060 {
namespace f3m_00a08060 {
extern int DAT_010c6bec;   // vtable at 0x00e35bcc
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpDefaultWorldMemoryWatchDog | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00a08060(f3m_00a08060::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08060::DAT_010c6bec;
    }
}
}   // namespace f3m_00a08060

// @f3 0x00a080a0 (community match, verified in this file)
namespace f3m_00a080a0 {
namespace f3m_00a080a0 {
extern int DAT_010d3838;   // vtable at 0x00e84834
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a080a0(f3m_00a080a0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a080a0::DAT_010d3838;
    }
}
}   // namespace f3m_00a080a0

// @f3 0x00a080e0 (community match, verified in this file)
namespace f3m_00a080e0 {
namespace f3m_00a080e0 {
extern int DAT_0126979c;   // vtable at 0x00e35a7c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a080e0(f3m_00a080e0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a080e0::DAT_0126979c;
    }
}
}   // namespace f3m_00a080e0

// @f3 0x00a08120 (community match, verified in this file)
namespace f3m_00a08120 {
namespace f3m_00a08120 {
extern int DAT_012697cc;   // vtable at 0x00e7d28c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpSimulation | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00a08120(f3m_00a08120::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08120::DAT_012697cc;
    }
}
}   // namespace f3m_00a08120

// @f3 0x00a08160 (community match, verified in this file)
namespace f3m_00a08160 {
namespace f3m_00a08160 {
extern int DAT_012697fc;   // vtable at 0x00e7c198
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a08160(f3m_00a08160::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08160::DAT_012697fc;
    }
}
}   // namespace f3m_00a08160

// @f3 0x00a08290 (community match, verified in this file)
namespace f3m_00a08290 {
namespace f3m_00a08290 {
extern int DAT_0126985c;   // vtable at 0x00e3599c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a08290(f3m_00a08290::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08290::DAT_0126985c;
    }
}
}   // namespace f3m_00a08290

// @f3 0x00a082c0 (community match, verified in this file)
namespace f3m_00a082c0 {
namespace f3m_00a082c0 {
extern int DAT_0126988c;   // vtable at 0x00e35a0c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a082c0(f3m_00a082c0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a082c0::DAT_0126988c;
    }
}
}   // namespace f3m_00a082c0

// @f3 0x00a08350 (community match, verified in this file)
namespace f3m_00a08350 {
namespace f3m_00a08350 {
extern int g_target_00da0a40;   // vtable at 0x00e84b0c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpLinearParametricCurve | hkpLinearParametricCurveClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00a08350(f3m_00a08350::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08350::g_target_00da0a40;
    }
}
}   // namespace f3m_00a08350

// @f3 0x00a08480 (community match, verified in this file)
namespace f3m_00a08480 {
namespace f3m_00a08480 {
extern int DAT_012698ec;   // vtable at 0x00e35c34
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a08480(f3m_00a08480::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08480::DAT_012698ec;
    }
}
}   // namespace f3m_00a08480

// @f3 0x00a084c0 (community match, verified in this file)
namespace f3m_00a084c0 {
namespace f3m_00a084c0 {
extern int DAT_0126991c;   // vtable at 0x00e84b70
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a084c0(f3m_00a084c0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a084c0::DAT_0126991c;
    }
}
}   // namespace f3m_00a084c0

// @f3 0x00a08530 (community match, verified in this file)
namespace f3m_00a08530 {
namespace f3m_00a08530 {
extern int DAT_0126994c;   // vtable at 0x00e84ba4
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a08530(f3m_00a08530::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08530::DAT_0126994c;
    }
}
}   // namespace f3m_00a08530

// @f3 0x00a08630 (community match, verified in this file)
namespace f3m_00a08630 {
namespace f3m_00a08630 {
extern int DAT_012699ac;   // vtable at 0x00e35d14
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a08630(f3m_00a08630::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08630::DAT_012699ac;
    }
}
}   // namespace f3m_00a08630

// @f3 0x00a087b0 (community match, verified in this file)
namespace f3m_00a087b0 {
namespace f3m_00a087b0 {
extern int DAT_010c6fd0;   // vtable at 0x00e35b64
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_00a087b0(f3m_00a087b0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a087b0::DAT_010c6fd0;
    }
}
}   // namespace f3m_00a087b0

// @f3 0x00a08db0 (community match, verified in this file)
namespace f3m_00a08db0 {
namespace f3m_00a08db0 {
extern int g_unk01269d78;   // vtable at 0x00e8515c
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

// pdb: finishLoadedObjecthkpConvexVerticesConnectivity | hkpConvexVerticesConnectivityClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00a08db0(f3m_00a08db0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_00a08db0::g_unk01269d78;
    }
}
}   // namespace f3m_00a08db0

// @f3 0x00a09050 (community match, verified in this file)
namespace f3m_00a09050 {
namespace f3m_00a09050 {
struct ReferencedBase {
    ReferencedBase();      // 0x00943410, finish-loading base constructor
    virtual void v00();
};
struct __declspec(align(16)) LoadedObject : ReferencedBase {
    virtual void v00();
    virtual void v04();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
}

void* __cdecl FUN_00a09050()
{
    // build a throwaway object to read its vtable pointer (Havok vtable registration)
    f3m_00a09050::LoadedObject object;
    return *(void**)&object;
}
}   // namespace f3m_00a09050

// @f3 0x00a07e10 (community match, verified in this file)
namespace f3m_00a07e10 {
namespace f3m_00a07e10 {
struct ReferencedBase {
    ReferencedBase();      // 0x00943410, finish-loading base constructor
    virtual void v00();
};
struct __declspec(align(16)) LoadedObject : ReferencedBase {
    virtual void v00();
    virtual void v04();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
}

void* __cdecl FUN_00a07e10()
{
    // build a throwaway object to read its vtable pointer (Havok vtable registration)
    f3m_00a07e10::LoadedObject object;
    return *(void**)&object;
}
}   // namespace f3m_00a07e10

// @f3 0x00a07c10 (community match, verified in this file)
namespace f3m_00a07c10 {
namespace f3m_00a07c10 {
struct ReferencedBase {
    ReferencedBase();      // 0x00943410, finish-loading base constructor
    virtual void v00();
};
struct __declspec(align(16)) LoadedObject : ReferencedBase {
    virtual void v00();
    virtual void v04();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    int unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
};
}

void* __cdecl FUN_00a07c10()
{
    // build a throwaway object to read its vtable pointer (Havok vtable registration)
    f3m_00a07c10::LoadedObject object;
    return *(void**)&object;
}
}   // namespace f3m_00a07c10

// @f3 0x00a08c20 (community match, verified in this file)
namespace f3m_00a08c20 {
namespace f3m_00a08c20 {
struct ReferencedBase {
    ReferencedBase();      // 0x00943410, finish-loading base constructor
    virtual void v00();
};
struct __declspec(align(16)) LoadedObject : ReferencedBase {
    virtual void v00();
    virtual void v04();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    int unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    int unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0;
    int unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
};
}

void* __cdecl FUN_00a08c20()
{
    // build a throwaway object to read its vtable pointer (Havok vtable registration)
    f3m_00a08c20::LoadedObject object;
    return *(void**)&object;
}
}   // namespace f3m_00a08c20

// @f3 0x00a06e10 (community match, verified in this file)
namespace f3m_00a06e10 {
namespace f3m_00a06e10 {
struct A06e10Flag { int m_finishing; };
struct __declspec(align(16)) A06e10Vec { float x, y, z, w; };
struct FUN_00a06e30 {
    void* vtable;
    int unk04[3];
    A06e10Vec unk10[0x15];
    FUN_00a06e30(A06e10Flag flag) throw();
};
void* FUN_00a06e10()
{
    A06e10Flag flag;
    flag.m_finishing = 0;
    FUN_00a06e30 object(flag);
    return object.vtable;
}
}
}   // namespace f3m_00a06e10

// @f3 0x00a07f20 (community match, verified in this file)
namespace f3m_00a07f20 {
namespace f3m_00a07f20 {
struct V00a07f20Flag { int m_finishing; };
struct __declspec(align(16)) V00a07f20Vec { float x, y, z, w; };
struct FUN_0090ab60 {
    void* vtable;
    int unk04[3];
    V00a07f20Vec unk10[12];
    FUN_0090ab60(V00a07f20Flag flag) throw();
};
// pdb: getVtablehkpRigidBody | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void* FUN_00a07f20()
{
    V00a07f20Flag flag;
    flag.m_finishing = 0;
    FUN_0090ab60 object(flag);
    return object.vtable;
}
}
}   // namespace f3m_00a07f20

// @f3 0x00a07f70 (community match, verified in this file)
namespace f3m_00a07f70 {
namespace f3m_00a07f70 {
struct V00a07f70Flag { int m_finishing; };
struct __declspec(align(16)) V00a07f70Vec { float x, y, z, w; };
struct FUN_00904560 {
    void* vtable;
    int unk04[3];
    V00a07f70Vec unk10[48];
    FUN_00904560(V00a07f70Flag flag) throw();
};
void* FUN_00a07f70()
{
    V00a07f70Flag flag;
    flag.m_finishing = 0;
    FUN_00904560 object(flag);
    return object.vtable;
}
}
}   // namespace f3m_00a07f70

// @f3 0x00a086d0 (community match, verified in this file)
namespace f3m_00a086d0 {
namespace f3m_00a086d0 {
struct V00a086d0Flag { int m_finishing; };
struct __declspec(align(16)) V00a086d0Vec { float x, y, z, w; };
struct FUN_00a086f0 {
    void* vtable;
    int unk04[3];
    V00a086d0Vec unk10[21];
    FUN_00a086f0(V00a086d0Flag flag) throw();
};
void* FUN_00a086d0()
{
    V00a086d0Flag flag;
    flag.m_finishing = 0;
    FUN_00a086f0 object(flag);
    return object.vtable;
}
}
}   // namespace f3m_00a086d0

// @f3 0x00a08810 (community match, verified in this file)
namespace f3m_00a08810 {
namespace f3m_00a08810 {
struct V00a08810Flag { int m_finishing; };
struct __declspec(align(16)) V00a08810Vec { float x, y, z, w; };
struct FUN_00a08830 {
    void* vtable;
    int unk04[3];
    V00a08810Vec unk10[12];
    FUN_00a08830(V00a08810Flag flag) throw();
};
// pdb: getVtablehkpGroupFilter | hkpCollideReflections.obj | tesv_win, objrun_open, low
void* FUN_00a08810()
{
    V00a08810Flag flag;
    flag.m_finishing = 0;
    FUN_00a08830 object(flag);
    return object.vtable;
}
}
}   // namespace f3m_00a08810

// @f3 0x00a07540 (community match, verified in this file)
#include <new>
namespace f3m_00a07540 {
namespace f3m_00a07540 {
struct A0754Base {
    virtual ~A0754Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A0754Base() { referenceCount = 1; }
};
struct A0754Obj : A0754Base {
    int unk08;
    int unk0c;
    A0754Obj() { unk0c = 0x17; }
    virtual ~A0754Obj();
};
// pdb: hkpMultiRayShape::hkpMultiRayShape | hkpMultiRayShapeClass.obj | fnv360_0822_debug, objrun_open, low
// pdb params: flag
void FUN_00a07540(void* p)
{
    new (p) A0754Obj();
}
}
}   // namespace f3m_00a07540

// @f3 0x00a072b0 (community match, verified in this file)
#include <new>
namespace f3m_00a072b0 {
namespace f3m_00a072b0 {
struct F00a072b0Flag { int m_finishing; };
struct FUN_00a50ae0 {
    int unk00;
    FUN_00a50ae0(F00a072b0Flag flag) throw();
};
// pdb: finishLoadedObjecthkpGenericConstraintDataScheme | hkpDynamicsReflections.obj | tesv_win, caller_sim, low
void FUN_00a072b0(void* p)
{
    F00a072b0Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_00a50ae0(flag);
}
}
}   // namespace f3m_00a072b0

// @f3 0x00a07600 (community match, verified in this file)
#include <new>
namespace f3m_00a07600 {
namespace f3m_00a07600 {
struct F00a07600Flag { int m_finishing; };
struct FUN_0097db40 {
    int unk00;
    FUN_0097db40(F00a07600Flag flag) throw();
};
// pdb: finishLoadedObjecthkpListShape | hkpCollideReflections.obj | tesv_win, objrun_prop, low
void FUN_00a07600(void* p)
{
    F00a07600Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_0097db40(flag);
}
}
}   // namespace f3m_00a07600

// @f3 0x00a08570 (community match, verified in this file)
namespace f3m_00a08570 {
struct FUN_00a08570_Obj {
    int unk00;
    unsigned short unk04;
};

struct FUN_00a08570_Alloc {
    void FUN_008f6d90(void* data, unsigned int size, int tag);
};

extern void FUN_00dcc494();

struct FUN_00a08570_Class {
    int __thiscall FUN_00a08570(unsigned char flag);
};

// pdb: hkpConstraintChainInstanceAction::`scalar deleting destructor' | hkpConstraintChainInstance.obj | fnv360_0822_retail, vtable, high
int FUN_00a08570_Class::FUN_00a08570(unsigned char flag)
{
    FUN_00a08570_Obj* self = (FUN_00a08570_Obj*)this;
    self->unk00 = (int)&FUN_00dcc494;
    if ((flag & 1) != 0) {
        FUN_00a08570_Alloc* alloc =
            (FUN_00a08570_Alloc*)f3m_00a09840::DAT_00d9b080(DAT_010f3170);
        alloc->FUN_008f6d90(self, self->unk04, 0x29);
    }
    return (int)self;
}
}   // namespace f3m_00a08570

// @f3 0x00a06970 (community match, verified in this file)
namespace f3m_00a06970 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a06970Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a06970 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a6f8c0();
    D00a06970* FUN_00a06970(unsigned int flags);
};
// pdb: hkpSerializedDisplayRbTransforms::`scalar deleting destructor' | hkpSerializedDisplayRbTransformsClass.obj | fnv360_0822_retail, vtable, high
D00a06970* D00a06970::FUN_00a06970(unsigned int flags)
{
    FUN_00a6f8c0();
    if (flags & 1) {
        D00a06970Heap* heap = (D00a06970Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0xd);
    }
    return this;
}
}

// @f3 0x00a07a50 (community match, verified in this file)
namespace f3m_00a07a50 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a07a50Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
extern void* DAT_00dcc494[];
struct D00a07a50 {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    D00a07a50* FUN_00a07a50(unsigned int flags);
};
// pdb: hkpSerializedDisplayMarker::`scalar deleting destructor' | hkpSerializedDisplayMarkerClass.obj | fnv360_0721_beta, vtable, medium
D00a07a50* D00a07a50::FUN_00a07a50(unsigned int flags)
{
    vtable = DAT_00dcc494;
    if (flags & 1) {
        D00a07a50Heap* heap = (D00a07a50Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 5);
    }
    return this;
}
}

// @f3 0x00a06c20 (community match, verified in this file)
namespace f3m_00a06c20 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a06c20Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a06c20 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a70700();
    D00a06c20* FUN_00a06c20(unsigned int flags);
};
D00a06c20* D00a06c20::FUN_00a06c20(unsigned int flags)
{
    FUN_00a70700();
    if (flags & 1) {
        D00a06c20Heap* heap = (D00a06c20Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a074e0 (community match, verified in this file)
namespace f3m_00a074e0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a074e0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a074e0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a07430();
    D00a074e0* FUN_00a074e0(unsigned int flags);
};
// pdb: hkpSimpleMeshShape::`scalar deleting destructor' | hkpSimpleMeshShapeClass.obj | fnv360_0822_retail, vtable_prefix, high
D00a074e0* D00a074e0::FUN_00a074e0(unsigned int flags)
{
    FUN_00a07430();
    if (flags & 1) {
        D00a074e0Heap* heap = (D00a074e0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a078b0 (community match, verified in this file)
namespace f3m_00a078b0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a078b0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a078b0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a07810();
    D00a078b0* FUN_00a078b0(unsigned int flags);
};
// pdb: hkpConvexPieceStreamData::`scalar deleting destructor' | hkpConvexPieceStreamDataClass.obj | fnv360_0822_retail, vtable, high
D00a078b0* D00a078b0::FUN_00a078b0(unsigned int flags)
{
    FUN_00a07810();
    if (flags & 1) {
        D00a078b0Heap* heap = (D00a078b0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a079e0 (community match, verified in this file)
namespace f3m_00a079e0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a079e0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a079e0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a07960();
    D00a079e0* FUN_00a079e0(unsigned int flags);
};
// pdb: hkpSerializedDisplayMarkerList::`scalar deleting destructor' | hkpSerializedDisplayMarkerListClass.obj | fnv360_0822_retail, vtable, high
D00a079e0* D00a079e0::FUN_00a079e0(unsigned int flags)
{
    FUN_00a07960();
    if (flags & 1) {
        D00a079e0Heap* heap = (D00a079e0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0xd);
    }
    return this;
}
}

// @f3 0x00a07e80 (community match, verified in this file)
namespace f3m_00a07e80 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a07e80Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a07e80 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a742c0();
    D00a07e80* FUN_00a07e80(unsigned int flags);
};
// pdb: hkpConstrainedSystemFilter::`scalar deleting destructor' | hkpConstrainedSystemFilterClass.obj | fnv360_0822_retail, vtable, high
D00a07e80* D00a07e80::FUN_00a07e80(unsigned int flags)
{
    FUN_00a742c0();
    if (flags & 1) {
        D00a07e80Heap* heap = (D00a07e80Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a083f0 (community match, verified in this file)
namespace f3m_00a083f0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a083f0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a083f0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a08380();
    D00a083f0* FUN_00a083f0(unsigned int flags);
};
// pdb: hkpLinearParametricCurve::`scalar deleting destructor' | hkpLinearParametricCurveClass.obj | fnv360_0822_retail, vtable_prefix, high
D00a083f0* D00a083f0::FUN_00a083f0(unsigned int flags)
{
    FUN_00a08380();
    if (flags & 1) {
        D00a083f0Heap* heap = (D00a083f0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x2c);
    }
    return this;
}
}

// @f3 0x00a085f0 (community match, verified in this file)
namespace f3m_00a085f0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a085f0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a085f0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a50c50();
    D00a085f0* FUN_00a085f0(unsigned int flags);
};
// pdb: hkpConstraintChainInstance::`scalar deleting destructor' | hkpConstraintChainInstance.obj | fnv360_0822_retail, vtable, high
D00a085f0* D00a085f0::FUN_00a085f0(unsigned int flags)
{
    FUN_00a50c50();
    if (flags & 1) {
        D00a085f0Heap* heap = (D00a085f0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x2c);
    }
    return this;
}
}

// @f3 0x00a08ab0 (community match, verified in this file)
namespace f3m_00a08ab0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a08ab0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a08ab0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a767b0();
    D00a08ab0* FUN_00a08ab0(unsigned int flags);
};
// pdb: hkpRemoveTerminalsMoppModifier::`scalar deleting destructor' | hkpRemoveTerminalsMoppModifierClass.obj | fnv360_0822_retail, vtable, high
D00a08ab0* D00a08ab0::FUN_00a08ab0(unsigned int flags)
{
    FUN_00a767b0();
    if (flags & 1) {
        D00a08ab0Heap* heap = (D00a08ab0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x28);
    }
    return this;
}
}

// @f3 0x00a08c80 (community match, verified in this file)
namespace f3m_00a08c80 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a08c80Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a08c80 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a76aa0();
    D00a08c80* FUN_00a08c80(unsigned int flags);
};
// pdb: hkpGroupFilter::`scalar deleting destructor' | hkpGroupFilterClass.obj | fnv360_0822_retail, vtable, high
D00a08c80* D00a08c80::FUN_00a08c80(unsigned int flags)
{
    FUN_00a76aa0();
    if (flags & 1) {
        D00a08c80Heap* heap = (D00a08c80Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a090b0 (community match, verified in this file)
namespace f3m_00a090b0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a090b0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a090b0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a77940();
    D00a090b0* FUN_00a090b0(unsigned int flags);
};
// pdb: hkpCollisionFilterList::`scalar deleting destructor' | hkpCollisionFilterListClass.obj | fnv360_0822_retail, vtable, high
D00a090b0* D00a090b0::FUN_00a090b0(unsigned int flags)
{
    FUN_00a77940();
    if (flags & 1) {
        D00a090b0Heap* heap = (D00a090b0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a08300 (community match, verified in this file)
#include <new>
namespace f3m_00a08300 {

struct FinishingFlag { int value; };
struct S00dfb400_Object {
    S00dfb400_Object(FinishingFlag flag) throw();
};

// pdb: getVtablehkpMalleableConstraintData | hkpMalleableConstraintDataClass.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: finishLoadedObjecthkpMalleableConstraintData)
void __cdecl FUN_00a08300(S00dfb400_Object* object) throw()
{
    FinishingFlag flag;
    flag.value = 1;
    if (object)
        new (object) S00dfb400_Object(flag);
}
}   // namespace f3m_00a08300

// @f3 0x00a0a1e0 (community match, verified in this file)
namespace f3m_00a0a1e0 {
struct Entry { const char* name; int value; };
extern Entry DAT_01064a50[];
struct ClassInfo { const char* FUN_009b0490(); };   // getName
int __cdecl hkString_strCmp(const char* a, const char* b);   // string compare
struct Bool {
    char value;
    Bool(bool b) : value(b) {}
};
}

f3m_00a0a1e0::Bool __stdcall FUN_00a0a1e0(f3m_00a0a1e0::ClassInfo* info, int* valueOut)
{
    for (int i = 0; i < 1; i++) {
        if (f3m_00a0a1e0::hkString_strCmp(f3m_00a0a1e0::DAT_01064a50[i].name, info->FUN_009b0490()) == 0) {
            *valueOut = f3m_00a0a1e0::DAT_01064a50[i].value;
            return true;
        }
    }
    return false;
}

// @f3 0x00a07ef0 (community match, verified in this file)
#include <new>
namespace f3m_00a07ef0 {
namespace f3m_00a07ef0 {
struct P00a07ef0Flag { int m_finishing; };
struct FUN_0090ab60 {
    int unk00;
    FUN_0090ab60(P00a07ef0Flag flag) throw();
};
// pdb: finishLoadedObjecthkpRigidBody | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void FUN_00a07ef0(void* p)
{
    P00a07ef0Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_0090ab60(flag);
}
}
}   // namespace f3m_00a07ef0

// @f3 0x00a086b0 (community match, verified in this file)
#include <new>
namespace f3m_00a086b0 {
namespace f3m_00a086b0 {
struct P00a086b0Flag { int m_finishing; };
struct FUN_00a086f0 {
    int unk00;
    FUN_00a086f0(P00a086b0Flag flag) throw();
};
// pdb: hkpPointToPlaneConstraintData::staticClass | hkpDynamicsReflections.obj | tesv_win, objopen_prop, low
void FUN_00a086b0(void* p)
{
    P00a086b0Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_00a086f0(flag);
}
}
}   // namespace f3m_00a086b0

// @f3 0x00a097a0 (community match, verified in this file)
extern int DAT_010d3838;
namespace f3m_00a097a0 {

struct FUN_00a097a0 {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    float unk0c, unk10, unk14, unk18;
    FUN_00a097a0(float a, float b, float c);
};

// pdb: hkpSpringDamperConstraintMotor::hkpSpringDamperConstraintMotor | hkpSpringDamperConstraintMotor.obj | fnv360_0822_retail, objrun_open, low
// pdb params: springConstant, springDamping, maxForce
FUN_00a097a0::FUN_00a097a0(float a, float b, float c) {
    unk06 = 1;
    *(volatile unsigned char*)&unk08 = 0;
    unk0c = -c;
    unk00 = &DAT_010d3838;
    unk08 = 3;
    unk10 = c;
    unk14 = a;
    unk18 = b;
}
}   // namespace f3m_00a097a0

// @f3 0x00a08760 (community match, verified in this file)
#include <new>
namespace f3m_00a08760 {
namespace f3m_00a08760 {
struct P00a08760Flag { int m_finishing; };
struct FUN_009dad20 {
    int unk00;
    FUN_009dad20(P00a08760Flag flag) throw();
};
// pdb: getVtablehkpBreakableConstraintData | hkpBreakableConstraintDataClass.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: finishLoadedObjecthkpBreakableConstraintData)
void FUN_00a08760(void* p)
{
    P00a08760Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_009dad20(flag);
}
}
}   // namespace f3m_00a08760

// @f3 0x00a087f0 (community match, verified in this file)
#include <new>
namespace f3m_00a087f0 {
namespace f3m_00a087f0 {
struct P00a087f0Flag { int m_finishing; };
struct FUN_00a08830 {
    int unk00;
    FUN_00a08830(P00a087f0Flag flag) throw();
};
// pdb: finishLoadedObjecthkpGroupFilter | hkpCollideReflections.obj | tesv_win, objrun_open, low
void FUN_00a087f0(void* p)
{
    P00a087f0Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_00a08830(flag);
}
}
}   // namespace f3m_00a087f0

// @f3 0x00a08d60 (community match, verified in this file)
#include <new>
namespace f3m_00a08d60 {
namespace f3m_00a08d60 {
struct P00a08d60Flag { int m_finishing; };
struct FUN_009e5f30 {
    int unk00;
    FUN_009e5f30(P00a08d60Flag flag) throw();
};
// pdb: finishLoadedObjecthkpCylinderShape | hkpCollideReflections.obj | tesv_win, caller_sim, low
void FUN_00a08d60(void* p)
{
    P00a08d60Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_009e5f30(flag);
}
}
}   // namespace f3m_00a08d60

// @f3 0x00a00c20 (community match, verified in this file)
namespace f3m_00a00c20 {
namespace f3m_00a00c20 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct __declspec(align(16)) RawTransform { int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c; int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c; };
struct Info {
    unsigned char type;
    unsigned char flags;
    int shape;
    RawTransform transform;
    Vec4 a, b, c;
    Info& FUN_00a00c20(const Info& o);
};
// pdb: hkpVelocityAccumulator::hkpVelocityAccumulator | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: __that
Info& Info::FUN_00a00c20(const Info& o)
{
    type = o.type;
    flags = o.flags;
    shape = o.shape;
    transform.m00 = o.transform.m00;
    transform.m04 = o.transform.m04;
    transform.m08 = o.transform.m08;
    transform.m0c = o.transform.m0c;
    transform.m10 = o.transform.m10;
    transform.m14 = o.transform.m14;
    transform.m18 = o.transform.m18;
    transform.m1c = o.transform.m1c;
    transform.m20 = o.transform.m20;
    transform.m24 = o.transform.m24;
    transform.m28 = o.transform.m28;
    transform.m2c = o.transform.m2c;
    transform.m30 = o.transform.m30;
    transform.m34 = o.transform.m34;
    transform.m38 = o.transform.m38;
    transform.m3c = o.transform.m3c;
    a = o.a;
    b = o.b;
    c = o.c;
    return *this;
}
}
}   // namespace f3m_00a00c20

// @f3 0x00a088d0 (community match, verified in this file)
#include <new>
namespace f3m_00a088d0 {
namespace f3m_00a088d0 {
struct I00a088d0Base {
    virtual ~I00a088d0Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    I00a088d0Base() { referenceCount = 1; }
};
struct I00a088d0Obj : I00a088d0Base {
    int unk08;
    int unk0c;
    I00a088d0Obj() { unk0c = 4; }
    virtual ~I00a088d0Obj();
};
void FUN_00a088d0(void* p)
{
    new (p) I00a088d0Obj();
}
}
}   // namespace f3m_00a088d0

// @f3 0x00a08a00 (community match, verified in this file)
#include <new>
namespace f3m_00a08a00 {
namespace f3m_00a08a00 {
struct I00a08a00Base {
    virtual ~I00a08a00Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    I00a08a00Base() { referenceCount = 1; }
};
struct I00a08a00Obj : I00a08a00Base {
    int unk08;
    int unk0c;
    I00a08a00Obj() { unk0c = 2; }
    virtual ~I00a08a00Obj();
};
void FUN_00a08a00(void* p)
{
    new (p) I00a08a00Obj();
}
}
}   // namespace f3m_00a08a00

// @f3 0x00a08af0 (community match, verified in this file)
#include <new>
namespace f3m_00a08af0 {
namespace f3m_00a08af0 {
struct I00a08af0Base {
    virtual ~I00a08af0Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    I00a08af0Base() { referenceCount = 1; }
};
struct I00a08af0Obj : I00a08af0Base {
    int unk08;
    int unk0c;
    I00a08af0Obj() { unk0c = 0x1b; }
    virtual ~I00a08af0Obj();
};
void FUN_00a08af0(void* p)
{
    new (p) I00a08af0Obj();
}
}
}   // namespace f3m_00a08af0

// @f3 0x00a08ba0 (community match, verified in this file)
#include <new>
namespace f3m_00a08ba0 {
namespace f3m_00a08ba0 {
struct I00a08ba0Base {
    virtual ~I00a08ba0Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    I00a08ba0Base() { referenceCount = 1; }
};
struct I00a08ba0Obj : I00a08ba0Base {
    int unk08;
    int unk0c;
    I00a08ba0Obj() { unk0c = 0x14; }
    virtual ~I00a08ba0Obj();
};
void FUN_00a08ba0(void* p)
{
    new (p) I00a08ba0Obj();
}
}
}   // namespace f3m_00a08ba0

// @f3 0x00a090f0 (community match, verified in this file)
#include <new>
namespace f3m_00a090f0 {
namespace f3m_00a090f0 {
struct I00a090f0Base {
    virtual ~I00a090f0Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    I00a090f0Base() { referenceCount = 1; }
};
struct I00a090f0Obj : I00a090f0Base {
    int unk08;
    int unk0c;
    I00a090f0Obj() { unk0c = 6; }
    virtual ~I00a090f0Obj();
};
void FUN_00a090f0(void* p)
{
    new (p) I00a090f0Obj();
}
}
}   // namespace f3m_00a090f0

// @f3 0x00a07810 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
namespace f3m_00a07810 {
extern unsigned long DAT_010f3170;
struct ThreadMemory { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
template <class T> struct Array {
    T* data;
    int size;
    int capacityAndFlags;
    __forceinline ~Array()
    {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemory* memory = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            memory->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};
class __declspec(novtable) ReferencedObject : public hkBaseObject {
public:
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}
class __declspec(novtable) FUN_00a07810 : public f3m_00a07810::ReferencedObject {
public:
    virtual ~FUN_00a07810();
    f3m_00a07810::Array<void*> first;
    f3m_00a07810::Array<void*> second;
    f3m_00a07810::Array<void*> third;
};

// pdb: hkpConvexPieceStreamData::~hkpConvexPieceStreamData | hkpConvexPieceStreamDataClass.obj | fnv360_0822_retail, call_seq, high
FUN_00a07810::~FUN_00a07810()
{
}

// @f3 0x00a06890 (community match, verified in this file)
#include <new>
namespace f3m_00a06890 {
namespace f3m_00a06890 {
struct A0689Flag { int m_finishing; };
struct FUN_009a1c00 { int unk00; FUN_009a1c00(A0689Flag flag) throw(); };
inline A0689Flag A0689MakeFlag(int f) { A0689Flag r; r.m_finishing = f; return r; }
struct A0689Base {
    virtual ~A0689Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A0689Base() { referenceCount = 1; }
};
struct A0689Obj : A0689Base {
    int unk08[6];
    FUN_009a1c00 unk20;
    A0689Obj(A0689Flag flag) throw() : unk20(flag) {}
    virtual ~A0689Obj();
};
// pdb: getVtablehkpSerializedAgentNnEntry | hkpSerializedAgentNnEntryClass.obj | fnv360_0822_retail, objopen_prop, low, conflict (skyrim: finishLoadedObjecthkpSerializedAgentNnEntry)
void FUN_00a06890(void* p)
{
    new (p) A0689Obj(A0689MakeFlag(1));
}
}
}   // namespace f3m_00a06890

// @f3 0x00a08f30 (community match, verified in this file)
namespace f3m_00a08f30 {
namespace f3m_00a08f30 {
struct FinishFlag { int finishing; };
class __declspec(novtable) ReferencedObject {
public:
    virtual ~ReferencedObject() {}
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    ReferencedObject(FinishFlag) { referenceCount = 1; }
};
class ShapeBase : public ReferencedObject {
public:
    ShapeBase(FinishFlag f) : ReferencedObject(f) {}
    int unk08;
    int type;
};
class Interface {
public:
    virtual void v00();
    Interface(FinishFlag) {}
};
class Shape : public ShapeBase, public Interface {
public:
    static void* operator new(unsigned int, void* where) { return where; }
    static void operator delete(void*, void*) {}
    Shape(FinishFlag f) : ShapeBase(f), Interface(f) { type = 8; }
    virtual void v04();
};
}

void __cdecl FUN_00a08f30(void* p)
{
    f3m_00a08f30::FinishFlag flag;
    if (p)
        new (p) f3m_00a08f30::Shape(flag);
}
}   // namespace f3m_00a08f30

// @f3 0x00a08910 (community match, verified in this file)
namespace f3m_00a08910 {
namespace f3m_00a08910 {
struct FinishFlag { int finishing; };
class __declspec(novtable) ReferencedObject {
public:
    virtual ~ReferencedObject() {}
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    ReferencedObject(FinishFlag) { referenceCount = 1; }
};
class ShapeBase : public ReferencedObject {
public:
    ShapeBase(FinishFlag f) : ReferencedObject(f) {}
    int unk08;
    int type;
};
class Interface {
public:
    virtual void v00();
    Interface(FinishFlag) {}
};
class Shape : public ShapeBase, public Interface {
public:
    static void* operator new(unsigned int, void* where) { return where; }
    static void operator delete(void*, void*) {}
    Shape(FinishFlag f) : ShapeBase(f), Interface(f) { type = 8; }
    virtual void v04();
};
}

void __cdecl FUN_00a08910(void* p)
{
    f3m_00a08910::FinishFlag flag;
    if (p)
        new (p) f3m_00a08910::Shape(flag);
}
}   // namespace f3m_00a08910

// @f3 0x00a073e0 (community match, verified in this file)
#include <new>
namespace f3m_00a073e0 {
namespace f3m_00a073e0 {
struct A073Base {
    virtual ~A073Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08;
    int unk0c;
    A073Base() { referenceCount = 1; }
};
struct A073Base2 {
    virtual ~A073Base2();
};
struct A073Obj : A073Base, A073Base2 {
    A073Obj() { unk0c = 0x16; }
    virtual ~A073Obj();
};
void FUN_00a073e0(void* p)
{
    new (p) A073Obj();
}
}
}   // namespace f3m_00a073e0

// @f3 0x00a08a60 (community match, verified in this file)
namespace f3m_00a08a60 {
namespace f3m_00a08a60 {
struct FinishFlag { int finishing; };
class __declspec(novtable) ReferencedObject {
public:
    virtual ~ReferencedObject() {}
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    ReferencedObject(FinishFlag) { referenceCount = 1; }
};
class ShapeBase : public ReferencedObject {
public:
    ShapeBase(FinishFlag f) : ReferencedObject(f) {}
    int unk08;
    int type;
};
class Interface {
public:
    virtual void v00();
    Interface(FinishFlag) {}
};
class Shape : public ReferencedObject, public Interface {
public:
    static void* operator new(unsigned int, void* where) { return where; }
    static void operator delete(void*, void*) {}
    Shape(FinishFlag f) : ReferencedObject(f), Interface(f) {}
    virtual void v04();
};
}

// pdb: hkpRemoveTerminalsMoppModifier::staticClass | hkpRemoveTerminalsMoppModifierClass.obj | fnv360_1110_retail, objrun, low
void __cdecl FUN_00a08a60(void* p)
{
    f3m_00a08a60::FinishFlag flag;
    if (p)
        new (p) f3m_00a08a60::Shape(flag);
}
}   // namespace f3m_00a08a60

// @f3 0x00a08e90 (community match, verified in this file)
namespace f3m_00a08e90 {
namespace f3m_00a08e90 {
struct FinishFlag { int finishing; };
class __declspec(novtable) ReferencedObject {
public:
    virtual ~ReferencedObject() {}
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    ReferencedObject(FinishFlag) { referenceCount = 1; }
};
class ShapeBase : public ReferencedObject {
public:
    ShapeBase(FinishFlag f) : ReferencedObject(f) {}
    int unk08;
    int type;
};
class Interface {
public:
    virtual void v00();
    Interface(FinishFlag) {}
};
class Shape : public ShapeBase {
public:
    static void* operator new(unsigned int, void* where) { return where; }
    static void operator delete(void*, void*) {}
    Shape(FinishFlag f) : ShapeBase(f), member(f) { type = 0xc; }
    int unk10;
    Interface member;
    virtual void v04();
};
}

void __cdecl FUN_00a08e90(void* p)
{
    f3m_00a08e90::FinishFlag flag;
    if (p)
        new (p) f3m_00a08e90::Shape(flag);
}
}   // namespace f3m_00a08e90

// @f3 0x00a0a2c0 (community match, verified in this file)
namespace f3m_00a0a2c0 {

struct A0A2C0_Owner {
    unsigned int unk00;
    unsigned short unk04;

    __declspec(noinline) void* FUN_00a0a240();
};

void* __cdecl FUN_00a0a2c0()
{
    f3m_00a09840::AllocB0* allocator =
        f3m_00a09840::DAT_00d9b080(DAT_010f3170);

    void* memory = allocator->FUN_008f6d30(0x14, 0x2d);

    A0A2C0_Owner* object = (A0A2C0_Owner*)memory;
    object->unk04 = 0x14;

    return object->FUN_00a0a240();
}
}   // namespace f3m_00a0a2c0

// @f3 0x00a0a410 (community match, verified in this file)
namespace f3m_00a0a410 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00dcc494[];
struct A0a41Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct A0a41Member { int unk00[3]; void FUN_00922cf0(); };
struct A0a41Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A0a41Member unk08;
    A0a41Obj* FUN_00a0a410(unsigned int flags);
};
A0a41Obj* A0a41Obj::FUN_00a0a410(unsigned int flags)
{
    unk08.FUN_00922cf0();
    vtable = DAT_00dcc494;
    if (flags & 1) {
        A0a41Heap* heap = (A0a41Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x2d);
    }
    return this;
}
}

// @f3 0x00a07b20 (community match, verified in this file)
#include <new>
namespace f3m_00a07b20 {
namespace f3m_00a07b20 {
struct FUN_009ae990 {
    virtual ~FUN_009ae990();
    int unk04[20];
    FUN_009ae990(int a, int b) throw();
};
struct A07b2Array {
    void* data;
    int size;
    int capacityAndFlags;
    A07b2Array() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
struct A07b2Obj : FUN_009ae990 {
    A07b2Array unk54;
    A07b2Obj() throw() : FUN_009ae990(0, 0) {}
    virtual ~A07b2Obj();
};
void FUN_00a07b20(void* p)
{
    new (p) A07b2Obj();
}
}
}   // namespace f3m_00a07b20

// @f3 0x00a0a320 (community match, verified in this file)
namespace f3m_00a0a320 {
namespace f3m_00a0a320 {
struct A0a32Map {
    int* data;
    int unk04;
    int hashMod;
    int FUN_00922790(int key);
    void FUN_00922710(int key, int value);
    void setValue(int i, int value) { data[hashMod + i + 1] = value; }
};
struct A0a32Obj {
    int unk00, unk04;
    A0a32Map map;
    void FUN_00a0a320(int key, int value);
};
void A0a32Obj::FUN_00a0a320(int key, int value)
{
    int i = map.FUN_00922790(key);
    if (i <= map.hashMod)
        map.setValue(i, value);
    else
        map.FUN_00922710(key, value);
}
}
}   // namespace f3m_00a0a320

// @f3 0x00a0a370 (community match, verified in this file)
namespace f3m_00a0a370 {
namespace f3m_00a0a370 {
struct A0a37Bool { char m_bool; A0a37Bool(bool b) { m_bool = b; } };
struct A0a37Map {
    int* data;
    int unk04;
    int hashMod;
    int FUN_00922790(int key);
    int getValue(int i) { return data[hashMod + i + 1]; }
};
struct A0a37Obj {
    int unk00, unk04;
    A0a37Map map;
    A0a37Bool FUN_00a0a370(int key, int* out);
};
A0a37Bool A0a37Obj::FUN_00a0a370(int key, int* out)
{
    int i = map.FUN_00922790(key);
    if (i <= map.hashMod) {
        *out = map.getValue(i);
        return true;
    }
    return false;
}
}
}   // namespace f3m_00a0a370

// @f3 0x00a0a3c0 (community match, verified in this file)
namespace f3m_00a0a3c0 {
namespace f3m_00a0a3c0 {
struct A0a3cKey { A0a3cKey* FUN_009b04a0(); };
struct A0a3cMap {
    int* data;
    int unk04;
    int hashMod;
    int FUN_00922790(A0a3cKey* key);
    int getValue(int i) { return data[hashMod + i + 1]; }
};
struct A0a3cObj {
    int unk00, unk04;
    A0a3cMap map;
    int FUN_00a0a260(A0a3cKey* key);
    int FUN_00a0a3c0(A0a3cKey* key);
};
int A0a3cObj::FUN_00a0a3c0(A0a3cKey* key)
{
    A0a3cKey* k = key;
    do {
        int i = map.FUN_00922790(k);
        if (i <= map.hashMod)
            return map.getValue(i);
        k = k->FUN_009b04a0();
    } while (k);
    return FUN_00a0a260(key);
}
}
}   // namespace f3m_00a0a3c0

// @f3 0x00a086f0 (community match, verified in this file)
extern void* DAT_00e801dc[];
namespace f3m_00a086f0 {
namespace f3m_00a086f0 {
struct A086fArray {
    void* data;
    int size;
    int capacityAndFlags;
    void Init() { data = 0; size = 0; capacityAndFlags = 0x80000000; }
};
struct A086fObj {
    void** vtable;
    int unk04[31];
    A086fArray unk80;
    A086fArray unk8c;
    int unk98[46];
    A086fArray unk150;
    void FUN_009319e0(int arg);
    A086fObj* FUN_00a086f0(int arg);
};
A086fObj* A086fObj::FUN_00a086f0(int arg)
{
    FUN_009319e0(arg);
    unk80.Init();
    unk8c.Init();
    vtable = DAT_00e801dc;
    unk150.Init();
    return this;
}
}
}   // namespace f3m_00a086f0

// @f3 0x00a07770 (community match, verified in this file)
extern void* DAT_00e8057c[];
extern void* DAT_00e36414[];
namespace f3m_00a07770 {
namespace f3m_00a07770 {
struct A0777Vec { float x, y, z, w; void operator=(const A0777Vec& o) { x = o.x; y = o.y; z = o.z; w = o.w; } };
struct A0777Src { int unk00[4]; A0777Vec v; int unk20; int unk24; };
struct A0777Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08;
    int unk0c;
    A0777Src* unk10;
    int unk14;
    int unk18;
    int unk1c;
    A0777Vec v20;
    void** unk30;
    A0777Obj* FUN_00a07770(int finishing);
};
A0777Obj* A0777Obj::FUN_00a07770(int finishing)
{
    referenceCount = 1;
    vtable = DAT_00e8057c;
    unk30 = DAT_00e36414;
    unk0c = 0xb;
    if (finishing == 1) {
        v20 = unk10->v;
        unk14 = unk10->unk20;
        unk18 = unk10->unk24;
    }
    return this;
}
}
}   // namespace f3m_00a07770

// @f3 0x00a06a20 (community match, verified in this file)
namespace f3m_00a06a20 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
struct A06a2Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A06a2Array {
    int* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            A06a2Heap* heap = (A06a2Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(int), 0x17);
        }
    }
};
struct A06a2Obj {
    A06a2Array a;
    A06a2Array b;
    void FUN_00a06a20();
};
void A06a2Obj::FUN_00a06a20()
{
    b.Free();
    a.Free();
}
}

// @f3 0x00a08380 (community match, verified in this file)
namespace f3m_00a08380 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
extern void* DAT_00dcc494[];
struct A0838Heap { void FUN_008f6d90(void* p, int size, int tag); };
template <class T> struct A0838Array {
    T* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            A0838Heap* heap = (A0838Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
struct A0838Vec { float x, y, z, w; };
struct A0838Obj {
    void** vtable;
    int unk04[7];
    A0838Array<A0838Vec> unk20;
    A0838Array<int> unk2c;
    void FUN_00a08380();
};
// pdb: hkpLinearParametricCurve::~hkpLinearParametricCurve | hkpLinearParametricCurveClass.obj | fnv360_0822_retail, call_seq, high
void A0838Obj::FUN_00a08380()
{
    unk2c.Free();
    unk20.Free();
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a089b0 (community match, verified in this file)
namespace f3m_00a089b0 {
extern const void* DAT_00e7d238;
extern const void* DAT_00e36414;

struct Entry2370
{
    const void* vtable;
    unsigned short unk04, references;
    int unk08, size;
    const void* embeddedVtable;
};

// pdb: finishLoadedObjecthkpTransformShape | hkpCollideReflections.obj | tesv_win, objrun_open, low
Entry2370* __cdecl FUN_00a089b0(Entry2370* entry)
{
    if (entry)
    {
        entry->references = 1;
        entry->vtable = &DAT_00e7d238;
        entry->embeddedVtable = &DAT_00e36414;
        entry->size = 0x1c;
    }
    return entry;
}
}   // namespace f3m_00a089b0

// @f3 0x00a06b80 (community match, verified in this file)
namespace f3m_00a06b80 {
class BE468B0Base {
public:
    virtual ~BE468B0Base();

    int m_iRefCount;
};

class BE468B0InterfaceA {
public:
    virtual void OnA();
};

class BE468B0InterfaceB {
public:
    virtual void OnB();
};

class BE468B0InterfaceC {
public:
    virtual void OnC();
};

class BE468B0InterfaceD {
public:
    virtual void OnD();
};

class BE468B0Shape : public BE468B0Base, public BE468B0InterfaceA, public BE468B0InterfaceB,
    public BE468B0InterfaceC, public BE468B0InterfaceD {
public:
    BE468B0Shape();
    virtual ~BE468B0Shape();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
    int unk24;
    int unk28;
    int unk2C;
};

class BE468B0Listener {
public:
    virtual void OnEvent();
};

template <class T>
class BE468B0Array {
public:
    BE468B0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class FUN_00a06b80 : public BE468B0Shape, public BE468B0Listener {
public:
    FUN_00a06b80(int unused);
    virtual ~FUN_00a06b80();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();
    virtual void OnEvent();

    BE468B0Array<int> m_kEntries;
};


// pdb: hkpBallGun::hkpBallGun | hkpBallGun.obj | tesv_win, objopen_prop, low
FUN_00a06b80::FUN_00a06b80(int unused) {}

}   // namespace f3m_00a06b80

// @f3 0x00a07730 (community match, verified in this file)
#include <new>
namespace f3m_00a07730 {
namespace task2375 {
struct FinishingFlag {int finishing; FinishingFlag():finishing(1){} };
struct FUN_00a07770 {
 virtual void vf00();
 unsigned short unk04,flags06;
 unsigned unk08,type0c;
 void* source10;
 unsigned unk14,unk18,unk1c;
 float x20,y24,z28,w2c;
 void* interface30;
 FUN_00a07770(FinishingFlag) throw();
};
void __cdecl FUN_00a07730(void* memory){FinishingFlag flag;new(memory) FUN_00a07770(flag);}
}
}   // namespace f3m_00a07730

// @f3 0x00a07ca0 (community match, verified in this file)
namespace f3m_00a07ca0 {
inline void* operator new(unsigned int, void* p) { return p; }
class BE468B0Base {
public:
    virtual ~BE468B0Base();

    int m_iRefCount;
};

class BE468B0InterfaceA {
public:
    virtual void OnA();
};

class BE468B0InterfaceB {
public:
    virtual void OnB();
};

class BE468B0InterfaceC {
public:
    virtual void OnC();
};

class BE468B0InterfaceD {
public:
    virtual void OnD();
};

class BE468B0Shape : public BE468B0Base, public BE468B0InterfaceA, public BE468B0InterfaceB,
    public BE468B0InterfaceC, public BE468B0InterfaceD {
public:
    BE468B0Shape();
    virtual ~BE468B0Shape();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
    int unk24;
    int unk28;
    int unk2C;
};

class BE468B0Listener {
public:
    virtual void OnEvent();
};

template <class T>
class BE468B0Array {
public:
    BE468B0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class FUN_00a07ca0 : public BE468B0Shape, public BE468B0Listener {
public:
    FUN_00a07ca0(int unused);
    virtual ~FUN_00a07ca0();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();
    virtual void OnEvent();

    BE468B0Array<int> m_kEntries;
};

// @fnv 0x00e468b0
FUN_00a07ca0::FUN_00a07ca0(int unused)
{
}


}   // namespace f3m_00a07ca0

// @f3 0x00a07660 (community match, verified in this file)
extern int DAT_00e8074c;
namespace f3m_00a07660 {
struct Object2371 {
    int* table;
    unsigned short unk04;
    unsigned short references;
    int unk08;
    int kind;
};
void __cdecl FUN_00a07660(Object2371* object) {
    if (object) {
        object->references = 1;
        object->table = &DAT_00e8074c;
        object->kind = 7;
    }
}
}   // namespace f3m_00a07660

// @f3 0x00a07f40 (community match, verified in this file)
#include <new>
namespace f3m_00a07f40 {
namespace Task2373 {
struct FinishFlag {
    int finishing;
    FinishFlag() : finishing(1) {}
};
struct FUN_00904560 {
    virtual void vf00();
    unsigned short unk04, flags06;
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
    FUN_00904560(FinishFlag) throw();
};
// pdb: hkpRigidBody::staticClass | hkpDynamicsReflections.obj | tesv_win, objopen_prop, low
void __cdecl FUN_00a07f40(void* memory) {
    FinishFlag flag;
    new (memory) FUN_00904560(flag);
}
}
}   // namespace f3m_00a07f40

// @f3 0x00a08430 (community match, verified in this file)
#include <new>
namespace f3m_00a08430 {
namespace task2374 {
struct FinishingFlag {
    int finishing;
    FinishingFlag() : finishing(1) {}
};
struct FUN_009ddec0 {
    FUN_009ddec0(FinishingFlag) throw();
};
// pdb: getVtablehkpGenericConstraintData | hkpGenericConstraintDataClass.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: finishLoadedObjecthkpGenericConstraintData)
void __cdecl FUN_00a08430(void* memory) {
    FinishingFlag flag;
    new (memory) FUN_009ddec0(flag);
}
}

}   // namespace f3m_00a08430

// @f3 0x00a09970 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_00a09970 {
struct Allocator2377
{
    void* FUN_008f6d30(int size, int tag);
};
extern Allocator2377* (__stdcall* DAT_00d9b080)(int);
void __cdecl FUN_009e10c0(void* memory);

struct NiDynamicEffect_GetRTTI
{
    void* vtable;
    unsigned short allocationSize, references;
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
    NiDynamicEffect_GetRTTI();

    static void* operator new(unsigned int size)
    {
        Allocator2377* allocator = DAT_00d9b080(DAT_010f3170);
        NiDynamicEffect_GetRTTI* memory = static_cast<NiDynamicEffect_GetRTTI*>(allocator->FUN_008f6d30(size, 0x2c));
        memory->allocationSize = static_cast<unsigned short>(size);
        return memory;
    }
    static void operator delete(void* memory)
    {
        FUN_009e10c0(memory);
    }
};

struct Owner2377
{
    int unk00;
    NiDynamicEffect_GetRTTI* payload;
    int FUN_00a09970();
};

// pdb: hkPointToPathConstraintCinfo::CreateData | bhkPointToPathConstraint.obj | fnv360_0721_beta, caller_sim, low
int Owner2377::FUN_00a09970()
{
    if (!payload)
        payload = new NiDynamicEffect_GetRTTI();
    return sizeof(NiDynamicEffect_GetRTTI);
}
}   // namespace f3m_00a09970

// @f3 0x00a07b60 (community match, verified in this file)
extern const void* DAT_00e37244;
namespace f3m_00a07b60 {

struct __declspec(align(16)) FUN_009ae990
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    FUN_009ae990(int first, int second);
};

const void* __cdecl FUN_00a07b60()
{
    FUN_009ae990 object(0, 0);
    return &DAT_00e37244;
}
}   // namespace f3m_00a07b60

// @f3 0x00a06ec0 (community match, verified in this file)
extern int DAT_01268cbc;
namespace f3m_00a06ec0 {

// pdb: finishLoadedObjecthkpRotationalConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void FUN_00a06ec0(void* apObject)
{
    if (apObject)
    {
        *(unsigned short*)((char*)apObject + 6) = 1;
        *(int**)(char*)apObject = &DAT_01268cbc;
    }
}
}   // namespace f3m_00a06ec0

// @f3 0x00a07eb0 (community match, verified in this file)
extern CpuOpaque DAT_0126967c;
namespace f3m_00a07eb0 {
struct CpuOpaque;

void FUN_00a07eb0(void* apObject)
{
    if (apObject)
    {
        *(unsigned short*)((char*)apObject + 6) = 1;
        *(int**)(char*)apObject = (int*)&DAT_0126967c;
    }
}
}   // namespace f3m_00a07eb0

// @f3 0x00a09230 (community match, verified in this file)
namespace f3m_00a09230 {
namespace Task2381 {
struct FUN_00a09230 {
    unsigned short type, unk02;
    unsigned int unk04, unk08, unk0c;
    Matrix477 first, second;
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
    unsigned short unkc4;
    FUN_00a09230* Assign(const FUN_00a09230& source);
};
// pdb: hkpLimitedHingeConstraintData::Atoms::operator= | hkpConstraintDataCloningUtil.obj | fnv360_0721_beta, call_gap, high
// pdb params: __that
FUN_00a09230* FUN_00a09230::Assign(const FUN_00a09230& source) {
    type = source.type;
    first.FUN_008fda60(source.first);
    second.FUN_008fda60(source.second);
    unk90 = source.unk90;
    unk94 = source.unk94;
    unk98 = source.unk98;
    unk9c = source.unk9c;
    unka0 = source.unka0;
    unka4 = source.unka4;
    unka8 = source.unka8;
    unkac = source.unkac;
    unkb0 = source.unkb0;
    unkb4 = source.unkb4;
    unkb8 = source.unkb8;
    unkbc = source.unkbc;
    unkc0 = source.unkc0;
    unkc4 = source.unkc4;
    return this;
}
}
}   // namespace f3m_00a09230

// @f3 0x00a0a450 (community match, verified in this file)
namespace f3m_00a0a450 {
struct StepInfo;
struct Accumulator { unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c; unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2c; unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3c; unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4c; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5c; unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6c; unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7c; };
struct World { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68; void* collisionInput; };
struct Entity { unsigned int unk00; unsigned short unk04; short unk06; World* world; };
int __cdecl hkRigidMotionUtilApplyAccumulators(const void*, const StepInfo*, const Accumulator*, Entity* const*, int, int);
void __cdecl FUN_0099a2d0(const void*, Entity* const*, int);
// pdb: hkConstraintSolverSetup_integrate2 | hkpConstraintSolverSetup.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) int __cdecl hkConstraintSolverSetup_integrate2(const void* solverInfo, const StepInfo& stepInfo, const Accumulator* accumulators, Entity* const* bodies, int numBodies)
{
    int result = hkRigidMotionUtilApplyAccumulators(solverInfo, &stepInfo, accumulators + 1, bodies, numBodies, 0xd0);
    FUN_0099a2d0(bodies[0]->world->collisionInput, bodies, numBodies);
    return result;
}

const void* volatile w06_solver; const StepInfo* volatile w06_step; const Accumulator* volatile w06_acc; Entity* const* volatile w06_bodies; volatile int w06_count, w06_result;
void w06_emit_integrate() { w06_result = hkConstraintSolverSetup_integrate2(w06_solver, *w06_step, w06_acc, w06_bodies, w06_count); }
}   // namespace f3m_00a0a450

// @f3 0x00a0af50 (community match, verified in this file)
namespace f3m_00a0af50 {
struct Scratch {
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
    unsigned short unk7C; unsigned short unk7E;
};
struct Pool { void FUN_008f6d90(void*, unsigned int, int); };
extern unsigned long DAT_010f3170;
extern "C" Pool* (__stdcall* const DAT_00d9b080)(unsigned long);
void* __cdecl FUN_00a0a680(void*, unsigned int, unsigned int, Scratch*);
// pdb: hkpConstraintSolverSetup::calcBufferSize | hkpConstraintSolverSetup.obj | tesv_win, callee_sim, low
void* __cdecl FUN_00a0af50(void* input) {
    __declspec(align(16)) Scratch s;
    s.unk0C=1; s.unk10=1; s.unk14=0; s.unk18=0;
    s.unk5C=0; s.unk60=0; s.unk64=0x80000000u;
    s.unk68=0; s.unk6C=0; s.unk70=0; s.unk74=0; s.unk78=0; s.unk7C=0;
    void* result=FUN_00a0a680(input,0,0,&s);
    unsigned int capacity=s.unk64;
    if ((capacity & 0x80000000u)==0) {
        Pool* pool=DAT_00d9b080(DAT_010f3170);
        pool->FUN_008f6d90((void*)s.unk5C,(capacity&0x3fffffffu)*4,0x17);
    }
    return result;
}
}   // namespace f3m_00a0af50

// @f3 0x00a07570 (community match, verified in this file)
struct Alloc07570 {
    void FUN_008f6d90(void* data, unsigned int size, int tag);
};

typedef Alloc07570* (__stdcall *AllocFn07570)(int);

extern AllocFn07570 FUN_00d9b080;
extern int FUN_00dcc494;

struct FUN_00a07570_obj {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    void* unk10;
    int unk14;
    int unk18;

    FUN_00a07570_obj* FUN_00a07570(unsigned int flags);
};

// pdb: hkpMultiRayShape::`scalar deleting destructor' | hkpMultiRayShapeClass.obj | fnv360_0721_beta, vtable_prefix, medium
FUN_00a07570_obj* FUN_00a07570_obj::FUN_00a07570(unsigned int flags) {
    AllocFn07570 allocator = FUN_00d9b080;

    if (!(unk18 & 0x80000000)) {
        unsigned int size = (unsigned int)unk18 & 0x3fffffffu;
        Alloc07570* alloc = allocator(DAT_010f3170);
        alloc->FUN_008f6d90(unk10, size * 32, 0x17);
    }

    unk00 = (int)&FUN_00dcc494;

    if (flags & 1) {
        Alloc07570* alloc = allocator(DAT_010f3170);
        alloc->FUN_008f6d90(this, unk04, 0x27);
    }

    return this;
}

// @f3 0x00a081a0 (community match, verified in this file)
namespace f3m_00a081a0 {
struct Sub81a0 {
    int unk00;
    int vtbl04;
    int field08;
    void __thiscall hkpBridgeConstraintAtom_init(int value);
};

struct Obj81a0 {
    int vtbl;
    short unk04;
    short word6;
    int unk08;
    Sub81a0 sub;
};

// pdb: finishLoadedObjecthkpPointToPathConstraintData | hkpPointToPathConstraintDataClass.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void finishLoadedObjecthkpPointToPathConstraintData(Obj81a0* p)
{
    if (!p)
        return;
    Sub81a0* q = &p->sub;
    p->word6 = 1;
    p->vtbl = 0xe84950;
    q->hkpBridgeConstraintAtom_init(q->field08);
}
}   // namespace f3m_00a081a0

// @f3 0x00a05610 (community match, verified in this file)
namespace f3m_00a05610 {
// candidate for hkpTransformCollapseUtil_collapseTransforms
extern "C" int __cdecl FUN_00a05580(void* arr, void* a, void* b);
// pdb: hkpTransformCollapseUtil::collapseTransforms | hkpTransformCollapseUtil.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_gap_sim), high
int __cdecl hkpTransformCollapseUtil_collapseTransforms(f3m_00a04370::QKey* pkEntity, void* iA, void* iB)
{
    f3m_00a04370::QKeyArray kEntities;
    f3m_00a04370::QPush(&kEntities, pkEntity);
    return FUN_00a05580(&kEntities, iA, iB);
}
}   // namespace f3m_00a05610

// @f3 0x00a08cc0 (community match, verified in this file)
namespace f3m_00a08cc0 {
struct Flag8cc0 {
    int v;
    Flag8cc0(int x) : v(x) {}
};

extern void FUN_00e85014();
extern void FUN_00e84ff0();

struct Init8cc0 {
    int vtbl;
    int unk04;
    int unk08;
    int f0c;
    int f10;
    Init8cc0* __thiscall FUN_00a45d60(Flag8cc0 flag);
};

// pdb: finishLoadedObjecthkpFastMeshShape | hkpCollidehkpMeshShapeReflections.obj | tesv_win, caller_sim, low
void FUN_00a08cc0(Init8cc0* p)
{
    if (!p)
        return;
    p->FUN_00a45d60(Flag8cc0(1));
    p->vtbl = (int)&FUN_00e85014;
    p->f10 = (int)&FUN_00e84ff0;
    p->f0c = 0x16;
}
}   // namespace f3m_00a08cc0

// @f3 0x00a07dc0 (community match, verified in this file)
namespace f3m_00a07dc0 {
struct FUN_00a07dc0_Obj {
    void FUN_00943410();
};

extern void FUN_00e7bf10();
extern void FUN_00e83d8c();
extern void FUN_00e83d80();
extern void FUN_00e83d6c();
extern void FUN_00e83d60();
extern void FUN_00e83d54();
extern void FUN_00e83d44();

void __cdecl FUN_00a07dc0(volatile unsigned int* param_1) {
    if (param_1 != 0) {
        FUN_00a07dc0_Obj* object = (FUN_00a07dc0_Obj*)param_1;
        object->FUN_00943410();
        param_1[12] = (unsigned int)(unsigned long)&FUN_00e7bf10;
        param_1[0] = (unsigned int)(unsigned long)&FUN_00e83d8c;
        param_1[2] = (unsigned int)(unsigned long)&FUN_00e83d80;
        param_1[3] = (unsigned int)(unsigned long)&FUN_00e83d6c;
        param_1[4] = (unsigned int)(unsigned long)&FUN_00e83d60;
        param_1[5] = (unsigned int)(unsigned long)&FUN_00e83d54;
        param_1[12] = (unsigned int)(unsigned long)&FUN_00e83d44;
    }
}
}   // namespace f3m_00a07dc0

// @f3 0x00a06f90 (community match, verified in this file)
namespace f3m_00a06f90 {
struct Flag6f90 {
    char v;
    Flag6f90(bool b) { v = b; }
};

extern void FUN_00e7c094();

struct P6f90 {
    int vtbl;
    short w4;
    short w6;
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
    short unk114;
    char flag116;
    void __thiscall FUN_00959c90(Flag6f90 value);
};

// pdb: finishLoadedObjecthkpRagdollConstraintData | hkpRagdollConstraintDataClass.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void finishLoadedObjecthkpRagdollConstraintData(P6f90* p)
{
    if (!p)
        return;
    p->w6 = 1;
    p->vtbl = (int)&FUN_00e7c094;
    if (p->flag116)
        p->FUN_00959c90(true);
}
}   // namespace f3m_00a06f90

// @f3 0x00a06760 (community match, verified in this file)
namespace f3m_00a06760 {
extern void FUN_00dcc864();

struct ObjA06760 {
    int unk0;
    char pad4[2];
    short unk6;
};

void FUN_00a06760(ObjA06760* p) {
    if (p) {
        p->unk6 = 1;
        p->unk0 = (int)FUN_00dcc864;
    }
}
}   // namespace f3m_00a06760

// @f3 0x00a05810 (community match, verified in this file)
namespace f3m_00a05810 {
// FUN_00a05810 - destructor of a 12-byte-entry array of two reference-counted keys.
struct KeyA05810 {
    virtual ~KeyA05810();
    unsigned short unk04;
    short unk06;
};

struct EntryA05810 {
    KeyA05810* key;
    KeyA05810* unk04;
    int count;
};

struct OwnerA05810 {
    EntryA05810* data;
    int size;
    unsigned int cap;
    void FUN_00a05810();
};

static __forceinline void ReleaseA05810(KeyA05810* p)
{
    if (p != 0 && p->unk04 != 0) {
        if (--p->unk06 == 0)
            delete p;
    }
}

// pdb: _SharedShapeData::~_SharedShapeData | hkpTransformCollapseUtil.obj | fnv360_0822_retail, call_seq, medium
void OwnerA05810::FUN_00a05810()
{
    for (int i = 0; i < size; i++) {
        ReleaseA05810(data[i].key);
        ReleaseA05810(data[i].unk04);
    }
    if ((cap & 0x80000000u) == 0) {
        unsigned int n = cap & 0x3fffffff;
        f3m_00a04370::QAlloc* allocator = f3m_00a04370::FUN_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(data, n * 12, 0x17);
    }
}
}   // namespace f3m_00a05810

// @f3 0x00a06790 (community match, verified in this file)
#include <intrin.h>

namespace f3m_00a06790 {
struct hkThreadMemory {
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
    int maxFree;
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
    void* freeList;
    int freeCount;
    void FUN_008f6d90(void* p, int size, int cls) throw();
    void FUN_008f6890(int bucket, void* p, int size) throw();
};
typedef hkThreadMemory* (__stdcall* AllocFn)(int);
extern AllocFn FUN_00d9b080;
extern int DAT_010f3170;
inline void Free(void* p, AllocFn mem)
{
    if (!p)
        return;
    hkThreadMemory* m = mem(DAT_010f3170);
    if (m->freeCount >= m->maxFree)
        m->FUN_008f6890(6, p, 0x27);
    else {
        _ReadWriteBarrier();
        m->freeCount++;
        *(void**)p = m->freeList;
        m->freeList = p;
    }
}
struct Arr06790 {
    int* data;
    int size;
    int capacityAndFlags;
};
struct Obj {
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
    Obj* FUN_00a06790(unsigned int flags);
};
Obj* Obj::FUN_00a06790(unsigned int flags)
{
    AllocFn mem = FUN_00d9b080;
    Arr06790* ar = (Arr06790*)((char*)this + 0x4c);
    if (!(ar->capacityAndFlags & 0x80000000)) {
        int cap = ar->capacityAndFlags & 0x3fffffff;
        hkThreadMemory* m = mem(DAT_010f3170);
        m->FUN_008f6d90(ar->data, cap * 8, 0x17);
    }
    if (flags & 1)
        Free(this, mem);
    return this;
}
}

// @f3 0x00a08f80 (community match, verified in this file)
namespace f3m_00a08f80 {
namespace f3m_00a08f80 {

struct A08f80 {
    unsigned int unk00;
    unsigned short unk04;
    A08f80* FUN_00a08f80(unsigned char flag);
};

extern void __cdecl FUN_00a77010();

// pdb: hkpConvexPieceMeshShape::`scalar deleting destructor' | hkpConvexPieceMeshShapeClass.obj | fnv360_0822_retail, vtable_prefix, high
A08f80* A08f80::FUN_00a08f80(unsigned char flag)
{
    FUN_00a77010();

    if ((flag & 1) != 0) {
        f3m_00a04370::QAlloc* allocator =
            reinterpret_cast<f3m_00a04370::QAlloc*>(
                f3m_00a09840::DAT_00d9b080(DAT_010f3170));
        allocator->FUN_008f6d90(this, this->unk04, 0x27);
    }

    return this;
}
}
}   // namespace f3m_00a08f80

// @f3 0x00a06af0 (community match, verified in this file)
namespace f3m_00a06af0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned int DAT_010f3170;

class hkThreadMemory6af0 {
public:
    void FUN_008f6d90(void* a_pMemory, int a_iBytes, int a_iClass);
};

class hkBaseObject6af0 {
public:
    virtual ~hkBaseObject6af0() {}
};

class hkReferencedObject6af0 : public hkBaseObject6af0 {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;

    static void operator delete(void* a_pMemory) {
        hkThreadMemory6af0* pMemory = (hkThreadMemory6af0*)TlsGetValue(DAT_010f3170);
        pMemory->FUN_008f6d90(a_pMemory, ((hkReferencedObject6af0*)a_pMemory)->m_memSizeAndFlags, 0x2c);
    }
};

class FUN_00a06af0 : public hkReferencedObject6af0 {
public:
    FUN_00a06af0();
    virtual ~FUN_00a06af0();
};

FUN_00a06af0::FUN_00a06af0() {}
}

// @f3 0x00a072f0 (community match, verified in this file)
namespace f3m_00a072f0 {
namespace f3m_00a072f0 {
struct Object72f0 {
    int FUN_009e1680(int a_Arg);
};

// pdb: getVtablehkpBallSocketChainData | hkpBallSocketChainDataClass.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: finishLoadedObjecthkpBallSocketChainData)
int __cdecl FUN_00a072f0(Object72f0* a_pObject) {
    int bResult = 1;
    if (a_pObject)
        bResult = a_pObject->FUN_009e1680(bResult);
    return bResult;
}
}
}   // namespace f3m_00a072f0

// @f3 0x00a084f0 (community match, verified in this file)
extern int DAT_010f3170;

namespace f3m_00a084f0 {

struct PoolAllocator {
    void FUN_008f6d90(void* pBlock, unsigned int size, int tag) throw();
};

extern PoolAllocator* (__stdcall *DAT_00d9b080)(int);

// Virtual method table installed while the object is being destroyed.
extern void* FUN_00dcc494;

struct PooledObject {
    void** m_ppVtbl;                  // virtual method table
    unsigned short m_usBlockSize;     // size of this block in the pool

    PooledObject* FUN_00a084f0(int deleteFlag);
};

// pdb: hkpConstraintChainInstanceAction::~hkpConstraintChainInstanceAction | hkpConstraintChainInstance.obj | fnv360_0822_debug, objrun_open, low
PooledObject* PooledObject::FUN_00a084f0(int deleteFlag)
{
    m_ppVtbl = &FUN_00dcc494;

    if ((deleteFlag & 1) != 0) {
        PoolAllocator* allocator = DAT_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(this, m_usBlockSize, 0x2b);
    }

    return this;
}
}

// @f3 0x00a08de0 (community match, verified in this file)
namespace f3m_00a08de0 {
// The shared allocator's free routine and the factory that hands it out.
struct A08de0Allocator {
    void FUN_008f6d90(void* block, unsigned int byteCount, int tag) throw();
};

__declspec(dllimport) A08de0Allocator* __stdcall FUN_00d9b080(int);   // heap factory for the shared allocator
extern int DAT_010f3170;                                              // handle of that shared heap
extern unsigned char FUN_00dcc494;                                    // vtable of the base object

// Object holding two owned buffers: 8-bit elements at +0x14, 16-bit elements at +0x08.
// Bit 31 of each capacity says "this buffer is not ours to free".
struct A08de0Object {
    void* vtbl;                 // +0x00
    int unk04;                  // +0x04
    unsigned short* words;      // +0x08
    int wordCount;              // +0x0c
    unsigned int wordCapacity;  // +0x10
    unsigned char* bytes;       // +0x14
    int byteCount;              // +0x18
    unsigned int byteCapacity;  // +0x1c
};

// pdb: hkpConvexVerticesConnectivity::~hkpConvexVerticesConnectivity | hkpConvexVerticesConnectivityClass.obj | fnv360_0822_retail, call_seq, high
void __fastcall FUN_00a08de0(A08de0Object* self)
{
    if ((self->byteCapacity & 0x80000000u) == 0) {
        unsigned int byteLength = self->byteCapacity & 0x3fffffff;
        A08de0Allocator* allocator = FUN_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(self->bytes, byteLength, 0x17);
    }

    if ((self->wordCapacity & 0x80000000u) == 0) {
        unsigned int wordLength = self->wordCapacity & 0x3fffffff;
        A08de0Allocator* allocator = FUN_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(self->words, wordLength * sizeof(unsigned short), 0x17);
    }

    self->vtbl = (void*)&FUN_00dcc494;
}
}   // namespace f3m_00a08de0

// @f3 0x00a029e0 (community match, verified in this file)
namespace f3m_00a029e0 {
struct FUN_00a029e0_Input {
    int count;
    f3m_00a09ae0::CC63E0_Context** items;
};

// pdb: hkaKeyFrameHierarchyUtility::initialize | hkaKeyFrameHierarchyUtility.obj | fnv360_0822_retail, call_seq, medium
// pdb params: bodies, internalReferencePose
void FUN_00a029e0(FUN_00a029e0_Input* in, float* out) {
    int i=0;
    if(in->count<=i) return;
    float* o = out + 10;
    do {
        const f3m_00a09ae0::CC63E0_Context* c = in->items[i];
        o[-2] = *(const float*)&c->unk1a0;
        o[-1] = *(const float*)&c->unk1a4;
        o[0] = *(const float*)&c->unk1a8;
        o[1] = *(const float*)&c->unk1ac;
        o[2] = *(const float*)&c->unk1b0;
        o[3] = *(const float*)&c->unk1b4;
        o[4] = *(const float*)&c->unk1b8;
        o[5] = *(const float*)&c->unk1bc;
        o[-10] = *(const float*)&c->unk130;
        o[-9] = *(const float*)&c->unk134;
        o[-8] = *(const float*)&c->unk138;
        o[-7] = *(const float*)&c->unk13c;
        o[-6] = *(const float*)&c->unk150;
        o[-5] = *(const float*)&c->unk154;
        o[-4] = *(const float*)&c->unk158;
        o[-3] = *(const float*)&c->unk15c;
        o += 16;
    } while(++i < in->count);
}
}   // namespace f3m_00a029e0

// @f3 0x00a099f0 (community match, verified in this file)
#include <intrin.h>
namespace f3m_00a099f0 {

using f3m_00a09ae0::CC63E0_Context;
using f3m_00a09ae0::Inner477;

struct A099f0Stream {
    int unk00;
    int counter;
    int (__cdecl *callback)(A099f0Stream*, void*, int, unsigned int*, int);
};

struct A099f0Size {
    unsigned int value;
    A099f0Size(unsigned int n) : value(n) {}
    operator unsigned int*() { return &value; }
};

struct A099f0Owner {
    int unk00;
    Inner477* inner;

    void FUN_008fc580(CC63E0_Context* context);
    void FUN_00a099f0(CC63E0_Context* context);
};

extern "C" void __cdecl FUN_008fe580(void* block);

void A099f0Owner::FUN_00a099f0(CC63E0_Context* context)
{
    A099f0Owner* owner = this;
    CC63E0_Context* ctx = context;

    owner->FUN_008fc580(ctx);

    Inner477* data = owner->inner;

    A099f0Stream* stream =
        reinterpret_cast<A099f0Stream*>(ctx->unk24c);
    int written = stream->callback(stream, &data->buf1c, 4,
                                   A099f0Size(4), 1);
    stream->counter += written;

    stream = reinterpret_cast<A099f0Stream*>(ctx->unk24c);
    written = stream->callback(stream, &data->buf20, 1,
                               A099f0Size(1), 1);
    stream->counter += written;

    stream = reinterpret_cast<A099f0Stream*>(ctx->unk24c);
    f3m_00a09ae0::Block477* firstBlock=&data->block30;
    written = stream->callback(stream, firstBlock, 0x40, 0, 0);
    stream->counter += written;

    stream = reinterpret_cast<A099f0Stream*>(ctx->unk24c);
    f3m_00a09ae0::Block477* secondBlock=&data->block70;
    written = stream->callback(stream, secondBlock, 0x40, 0, 0);
    stream->counter += written;

    if (*(reinterpret_cast<unsigned char*>(ctx) + 0x1e5) != 1) {
        f3m_00a09ae0::SwapWord477(firstBlock->unk30);
        f3m_00a09ae0::SwapWord477(firstBlock->unk34);
        f3m_00a09ae0::SwapWord477(firstBlock->unk38);
        f3m_00a09ae0::SwapWord477(firstBlock->unk3c);
        FUN_008fe580(firstBlock);

        f3m_00a09ae0::SwapWord477(secondBlock->unk30);
        f3m_00a09ae0::SwapWord477(secondBlock->unk34);
        f3m_00a09ae0::SwapWord477(secondBlock->unk38);
        f3m_00a09ae0::SwapWord477(secondBlock->unk3c);
        FUN_008fe580(secondBlock);
    }
}
}   // namespace f3m_00a099f0

// @f3 0x00a091b0 (community match, verified in this file)
namespace f3m_00a091b0 {
namespace f3m_00a093d0 {

struct EmbeddedState {
    unsigned short type;
    unsigned char  unk02;
    unsigned char  pad03;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int   pad08;
    unsigned int   pad0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;

    EmbeddedState* FUN_00a091b0(const EmbeddedState& source);
};

}

f3m_00a093d0::EmbeddedState* f3m_00a093d0::EmbeddedState::FUN_00a091b0(const EmbeddedState& source)
{
    type  = source.type;
    unk02 = source.unk02;
    unk04 = source.unk04;
    unk06 = source.unk06;
    unsigned int a40 = source.unk40;
    f10 = source.f10;
    unk40 = a40;
    unsigned int a44 = source.unk44;
    f14 = source.f14;
    unk44 = a44;
    f18 = source.f18;
    f1c = source.f1c;
    f20 = source.f20;
    f24 = source.f24;
    f28 = source.f28;
    f2c = source.f2c;
    f30 = source.f30;
    f34 = source.f34;
    f38 = source.f38;
    const EmbeddedState* __restrict tail=&source;
    f3c=tail->f3c;
    unk48=tail->unk48;
    return this;
}
}   // namespace f3m_00a091b0

// @f3 0x00a07430 (community match, verified in this file)
extern char DAT_00e35eec[];
extern char DAT_00dcc494[];
namespace f3m_00a07430 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long index);

struct QAlloc07430 { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };

template <unsigned int SHIFT>
struct Arr07430 {
    void* data;
    int unk04;
    unsigned int count;
    void Free(void* (__stdcall* tls)(unsigned long)) throw()
    {
        if (!(count & 0x80000000u)) {
            unsigned int size = count & 0x3fffffffu;
            QAlloc07430* alloc = (QAlloc07430*)tls(DAT_010f3170);
            alloc->FUN_008f6d90(data, size << SHIFT, 0x17);
        }
    }
};

struct Sub07430 {
    void* vt00;
};

struct Obj07430 {
    void* vt00;
    int unk04, unk08, unk0C;
    void* vt10;
    int unk14;
    Arr07430<4> a18;
    Arr07430<4> a24;
    Arr07430<0> a30;
    void FUN_00a07430();
};

inline Sub07430* GetSub07430(Obj07430* owner) { return owner ? reinterpret_cast<Sub07430*>(&owner->vt10) : 0; }

// pdb: hkpSimpleMeshShape::~hkpSimpleMeshShape | hkpSimpleMeshShapeClass.obj | fnv360_0822_retail, call_seq, high
void Obj07430::FUN_00a07430()
{
    void* (__stdcall* tls)(unsigned long) = DAT_00d9b080;
    a30.Free(tls);
    a24.Free(tls);
    a18.Free(tls);
    GetSub07430(this)->vt00 = DAT_00e35eec;
    vt00 = DAT_00dcc494;
}
}   // namespace f3m_00a07430

// @f3 0x00a09c50 (community match, verified in this file)
#include <stddef.h>
namespace f3m_00a09c50 {
namespace f3m_00a09c50 {
struct Vec4
{
    float x, y, z, w;
};
struct Transform
{
    __declspec(align(16)) Vec4 m_kCol0;
    Vec4 m_kCol1;
    Vec4 m_kCol2;
    Vec4 m_kCol3;
    void FUN_008fda60(const Transform* src);
};
struct Desc
{
    Desc() { unk08 = 0; unk0c = 0; }
    int m_i00;
    int m_i04;
    int unk08;
    int unk0c;
    bool m_bFlag;
    char unk11; char unk12; char unk13;
    int unk14;
    float m_fValue;
    int unk1c;
    Transform m_kTransformA;
    Transform m_kTransformB;
};
struct Reader;
typedef int (__cdecl* ReadFunc)(Reader* reader, void* buffer, int size, int a, int b);
struct Reader
{
    int unk00;
    int m_iBytesRead;
    ReadFunc m_pfnRead;
};
struct Stream
{
    int unk000;
};
struct Target
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    float m_fValue;
    bool m_bFlag;
    char unk21; char unk22; char unk23;
    int unk24; int unk28; int unk2c;
    Transform m_kSlotA;
    Transform m_kSlotB;
};
typedef char CheckTransformSize[sizeof(Transform) == 0x40 ? 1 : -1];
typedef char CheckSlotA[offsetof(Target, m_kSlotA) == 0x30 ? 1 : -1];
typedef char CheckSlotB[offsetof(Target, m_kSlotB) == 0x70 ? 1 : -1];
}

struct f3m_00a09c50_Obj
{
    int unk00;
    f3m_00a09c50::Target* m_pTarget;
    void FUN_008fc680(void* stream, f3m_00a09c50::Desc* desc);
    void FUN_00a09c50(void* stream, f3m_00a09c50::Desc* desc);
};

void f3m_00a09c50_Obj::FUN_00a09c50(void* stream, f3m_00a09c50::Desc* desc)
{
    f3m_00a09c50::Desc local;
    if (desc == 0)
    {
        f3m_00a09c50::Reader* reader = *(f3m_00a09c50::Reader**)((char*)stream + 0x24c);
        desc = &local;
        reader->m_iBytesRead += reader->m_pfnRead(reader, desc, sizeof(f3m_00a09c50::Desc), 0, 0);
    }
    FUN_008fc680(stream, desc);
    f3m_00a09c50::Target* target = m_pTarget;
    target->m_fValue = desc->m_fValue;
    target->m_bFlag = desc->m_bFlag;
    target->m_kSlotA.FUN_008fda60(&desc->m_kTransformA);
    target->m_kSlotB.FUN_008fda60(&desc->m_kTransformB);
}
}   // namespace f3m_00a09c50

// @f3 0x00a05900 (community match, verified in this file)
#include <math.h>

typedef float hkReal;

namespace S00a05900_hkMath
{
	inline hkReal sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal sqrtInverse(hkReal r) { return 1.0f / S00a05900_hkMath::sqrt(r); }
	inline hkReal fabs(hkReal r) { return ::fabsf(r); }
}

enum S00a05900_hkResult { S00a05900_HK_SUCCESS = 0, S00a05900_HK_FAILURE = 1 };

class S00a05900_hkBool
{
public:
	S00a05900_hkBool() {}
	S00a05900_hkBool(bool b) { m_bool = (char)b; }
	operator bool() const { return m_bool != 0; }
	S00a05900_hkBool& operator=(bool e) { m_bool = (char)e; return *this; }
	char m_bool;
};

class S00a05900_hkVector4Comparison
{
public:
	enum Mask { MASK_NONE = 0, MASK_W = 1, MASK_Z = 2, MASK_Y = 4, MASK_X = 8, MASK_XYZ = 14, MASK_XYZW = 15 };
	int allAreSet(Mask m) const { return (m_mask & m) == m; }
	int m_mask;
};

class __declspec(align(16)) S00a05900_hkVector4
{
public:
	S00a05900_hkVector4() {}
	S00a05900_hkVector4(const S00a05900_hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
	void operator=(const S00a05900_hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
	void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f) { x = a; y = b; z = c; w = d; }
	void setAll(hkReal a) { x = a; y = a; z = a; w = a; }
	void setZero4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
	void setSub4(const S00a05900_hkVector4& v0, const S00a05900_hkVector4& v1)
	{
		x = v0.x - v1.x;
		y = v0.y - v1.y;
		z = v0.z - v1.z;
		w = v0.w - v1.w;
	}
	void mul4(hkReal s) { x *= s; y *= s; z *= s; w *= s; }
	void setCross(const S00a05900_hkVector4& v1, const S00a05900_hkVector4& v2)
	{
		const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
		const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
		const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
		this->set(nx, ny, nz, 0.0f);
	}
	void setAbs4(const S00a05900_hkVector4& v)
	{
		x = S00a05900_hkMath::fabs(v.x);
		y = S00a05900_hkMath::fabs(v.y);
		z = S00a05900_hkMath::fabs(v.z);
		w = S00a05900_hkMath::fabs(v.w);
	}
	__forceinline S00a05900_hkVector4Comparison compareLessThanEqual4(const S00a05900_hkVector4& a) const
	{
		S00a05900_hkVector4Comparison ret;
		ret.m_mask =
			((x <= a.x) ? S00a05900_hkVector4Comparison::MASK_X : 0) |
			((y <= a.y) ? S00a05900_hkVector4Comparison::MASK_Y : 0) |
			((z <= a.z) ? S00a05900_hkVector4Comparison::MASK_Z : 0) |
			((w <= a.w) ? S00a05900_hkVector4Comparison::MASK_W : 0);
		return ret;
	}
	__forceinline int equals3(const S00a05900_hkVector4& v, hkReal epsilon) const
	{
		S00a05900_hkVector4 t;
		t.setSub4(*this, v);
		t.setAbs4(t);
		S00a05900_hkVector4 epsilon_v;
		epsilon_v.setAll(epsilon);
		return t.compareLessThanEqual4(epsilon_v).allAreSet(S00a05900_hkVector4Comparison::MASK_XYZ);
	}
	hkReal dot3(const S00a05900_hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
	__forceinline hkReal lengthInverse3() const
	{
		hkReal l2 = (x * x) + (y * y) + (z * z);
		return l2 ? S00a05900_hkMath::sqrtInverse(l2) : 0;
	}
	__forceinline void normalize3() { this->mul4(this->lengthInverse3()); }
	hkReal& operator()(int i) { return (&x)[i]; }
	const hkReal& operator()(int i) const { return (&x)[i]; }

	hkReal x, y, z, w;
};

class S00a05900_hkQuaternion;

class S00a05900_hkMatrix3
{
public:
	S00a05900_hkMatrix3() {}
	S00a05900_hkMatrix3(const S00a05900_hkMatrix3& a) { m_col0 = a.m_col0; m_col1 = a.m_col1; m_col2 = a.m_col2; }
	void operator=(const S00a05900_hkMatrix3& a) { m_col0 = a.getColumn(0); m_col1 = a.getColumn(1); m_col2 = a.getColumn(2); }
	S00a05900_hkVector4& getColumn(int i) { return (&m_col0)[i]; }
	const S00a05900_hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
	hkReal& operator()(int r, int c) { return getColumn(c)(r); }
	void setCols(const S00a05900_hkVector4& r0, const S00a05900_hkVector4& r1, const S00a05900_hkVector4& r2)
	{
		m_col0 = r0;
		m_col1 = r1;
		m_col2 = r2;
	}
	void setZero() { m_col0.setZero4(); m_col1.setZero4(); m_col2.setZero4(); }
	void setDiagonal(hkReal m00, hkReal m11, hkReal m22)
	{
		setZero();
		(*this)(0, 0) = m00;
		(*this)(1, 1) = m11;
		(*this)(2, 2) = m22;
	}
	static const S00a05900_hkMatrix3& getIdentity();

	S00a05900_hkResult invert(hkReal epsilon);
	void transpose();
	void add(const S00a05900_hkMatrix3& a);
	void setMul(hkReal scale, const S00a05900_hkMatrix3& a);
	void setMul(const S00a05900_hkMatrix3& a, const S00a05900_hkMatrix3& b);
	S00a05900_hkBool isApproximatelyEqual(const S00a05900_hkMatrix3& m, hkReal zero) const;

	S00a05900_hkVector4 m_col0;
	S00a05900_hkVector4 m_col1;
	S00a05900_hkVector4 m_col2;
};

extern const S00a05900_hkMatrix3 S00a05900_hkMatrix3Identity;
inline const S00a05900_hkMatrix3& S00a05900_hkMatrix3::getIdentity() { return S00a05900_hkMatrix3Identity; }

class S00a05900_hkRotation : public S00a05900_hkMatrix3
{
public:
	void set(const S00a05900_hkQuaternion& q);
};

class S00a05900_hkQuaternion
{
public:
	S00a05900_hkQuaternion() {}
	S00a05900_hkQuaternion(const S00a05900_hkRotation& r) { set(r); }
	void operator=(const S00a05900_hkQuaternion& q) { m_vec = q.m_vec; }
	void set(const S00a05900_hkRotation& r);
	void normalize();
	void setInverse(const S00a05900_hkQuaternion& q) { m_vec.set(-q.m_vec(0), -q.m_vec(1), -q.m_vec(2), q.m_vec(3)); }
	S00a05900_hkVector4 m_vec;
};

class S00a05900_hkTransform
{
public:
	void set4x4ColumnMajor(const hkReal* p);
	S00a05900_hkRotation& getRotation() { return m_rotation; }
	S00a05900_hkVector4& getTranslation() { return m_translation; }
	S00a05900_hkRotation m_rotation;
	S00a05900_hkVector4 m_translation;
};

struct S00a05900_Decomposition
{
	S00a05900_hkVector4 m_translation;
	S00a05900_hkQuaternion m_rotation;
	S00a05900_hkVector4 m_scale;
	S00a05900_hkBool m_hasScale;
	S00a05900_hkBool m_hasSkew;
	S00a05900_hkBool m_flips;
	S00a05900_hkMatrix3 m_scaleAndSkew;
	S00a05900_hkMatrix3 m_skew;
	S00a05900_hkRotation m_basis;
};

// pdb: hkMathUtil::decompose4x4ColTransform | hkMathUtil.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: matrixIn, decompOut
void FUN_00a05900(const hkReal* matrixIn, S00a05900_Decomposition& decomposition)
{
	const hkReal eps = 1.192092896e-07f;

	S00a05900_hkTransform transform;
	transform.set4x4ColumnMajor(matrixIn);

	decomposition.m_translation = transform.getTranslation();

	S00a05900_hkRotation prev;
	S00a05900_hkRotation cur;
	S00a05900_hkRotation invT;

	int i = 0;
	cur = transform.getRotation();
	do
	{
		prev = cur;
		invT = prev;
		invT.invert(eps);
		invT.transpose();
		S00a05900_hkMatrix3 tmp;
		tmp = prev;
		tmp.add(invT);
		cur.setMul(0.5f, tmp);
		i++;
	} while (i < 30 && !cur.isApproximatelyEqual(prev, eps));

	decomposition.m_basis = cur;

	S00a05900_hkVector4 c0 = decomposition.m_basis.getColumn(0);
	c0.normalize3();
	S00a05900_hkVector4 c1 = decomposition.m_basis.getColumn(1);
	c1.normalize3();
	S00a05900_hkVector4 c2 = decomposition.m_basis.getColumn(2);
	c2.normalize3();

	{
		S00a05900_hkVector4 cross;
		cross.setCross(c1, c2);
		const hkReal det = cross.dot3(c0);
		if (det < 0.0f)
		{
			c0.mul4(-1.0f);
		}
		decomposition.m_flips = det < 0.0f;
	}

	{
		S00a05900_hkRotation rot;
		rot.setCols(c0, c1, c2);
		S00a05900_hkQuaternion q(rot);
		decomposition.m_rotation = q;
		decomposition.m_rotation.normalize();
	}

	{
		S00a05900_hkQuaternion qInv;
		qInv.setInverse(decomposition.m_rotation);
		S00a05900_hkRotation rotInv;
		rotInv.set(qInv);
		decomposition.m_scaleAndSkew.setMul(rotInv, transform.getRotation());
	}

	decomposition.m_scale.set(decomposition.m_scaleAndSkew(0, 0), decomposition.m_scaleAndSkew(1, 1), decomposition.m_scaleAndSkew(2, 2), 0.0f);

	S00a05900_hkVector4 one;
	one.setAll(1.0f);
	decomposition.m_hasScale = !decomposition.m_scale.equals3(one, 1e-3f);

	{
		S00a05900_hkMatrix3 invScale;
		invScale.setDiagonal(1.0f / decomposition.m_scale(0), 1.0f / decomposition.m_scale(1), 1.0f / decomposition.m_scale(2));
		decomposition.m_skew.setMul(invScale, decomposition.m_scaleAndSkew);
	}

	decomposition.m_hasSkew = !decomposition.m_skew.isApproximatelyEqual(S00a05900_hkMatrix3::getIdentity(), 1e-3f);
}

// @f3 0x00a0a120 (community match, verified in this file)
namespace f3m_00a0a120 {
namespace c3_00a0a120 {

union __declspec(align(16)) PackBits
{
    float f[4];
    unsigned int u[4];
};

// pdb: hkVector4Util::packQuaternionIntoInt32 | hkVector4Util.obj | fnv360_0822_retail, objrun_prop + skyrim(objrun_prop), high
unsigned int __cdecl hkVector4Util_packQuaternionIntoInt32(const float* in)
{
    PackBits scaled;
    PackBits biased;
    scaled.f[0] = (float)(in[0] * 116.36363220214844);
    scaled.f[1] = (float)(in[1] * 116.36363220214844);
    scaled.f[2] = (float)(in[2] * 116.36363220214844);
    scaled.f[3] = (float)(in[3] * 116.36363220214844);
    biased.f[0] = (float)(scaled.f[0] + 196736.5);
    biased.f[1] = (float)(scaled.f[1] + 196736.5);
    biased.f[2] = (float)(scaled.f[2] + 196736.5);
    biased.f[3] = (float)(scaled.f[3] + 196736.5);
    scaled.f[0] = biased.f[0];
    scaled.f[1] = biased.f[1];
    scaled.f[2] = biased.f[2];
    scaled.f[3] = biased.f[3];
    return ((scaled.u[3] & 0xffffffc0u) << 18) | ((scaled.u[2] & 0x3fc0u) << 10) |
           ((scaled.u[1] & 0x3fc0u) << 2) | ((scaled.u[0] >> 6) & 0xffu);
}

}
}   // namespace f3m_00a0a120

// @f3 0x00a06200 (community match, verified in this file)
namespace match665 {
struct __declspec(align(16)) Vec4 {float x,y,z,w;void Set(const Vec4& a){x=a.x;y=a.y;z=a.z;w=a.w;}};
struct Matrix {Vec4 c0,c1,c2;};
struct Transform {Matrix matrix;Vec4 position;};
extern Vec4 DAT_01092a50;
void __cdecl FUN_00a061f0(const Transform*,void*);
void __cdecl FUN_00a06200(const Matrix* source,void* out){
 Transform value;
 value.matrix.c0.Set(source->c0);value.matrix.c1.Set(source->c1);value.matrix.c2.Set(source->c2);
 value.position.Set(DAT_01092a50);
 FUN_00a061f0(&value,out);
}
}

// @f3 0x00a0a260 (community match, verified in this file)
namespace f3m_00a0a260 {
struct SmallBool772 {
    char value;
    SmallBool772(bool flag) : value(flag) {}
};
struct Node772 {
    Node772* FUN_009b04a0() const;
    SmallBool772 FUN_009b0780();
};
struct Owner772 {
    SmallBool772 FUN_00a0a1e0(Node772*, unsigned int*);
    int FUN_00a0a260(Node772*);
};
int Owner772::FUN_00a0a260(Node772* arg) {
    unsigned int result;
    Node772* initial = arg;
    Node772* node = initial;
    do {
        if (FUN_00a0a1e0(initial, &result).value)
            return result;
        node = node->FUN_009b04a0();
    } while (node);
    return initial->FUN_009b0780().value ? 1 : 2;
}
}   // namespace f3m_00a0a260

// @f3 0x00a08830 (community match, verified in this file)
extern void* DAT_00e7c994[];
namespace f3m_00a08830 {
void __cdecl FUN_00901e90(void* arr, int count, int elemSize);
namespace a365 {
struct Arr {
    void* data;
    int size;
    int capacityAndFlags;
    int Capacity() const { return capacityAndFlags & 0x3fffffff; }
    void Reserve(int n) { if (Capacity() < n) FUN_00901e90(this, n, 4); }
    void FixAlign() {
        int count = Capacity();
        if (count == 0 || ((int)data & 0xf) != 0) {
            int want = count + 1;
            Reserve(want < 4 ? 4 : want);
        }
    }
    void Init() { data = 0; size = 0; capacityAndFlags = 0x80000000; }
};
struct Obj {
    void** vtable;
    int unk04[31];
    Arr unk80;
    Arr unk8c;
    int unk98[10];
    Arr unkC0;
    void FUN_009319e0(int arg);
    Obj* FUN_00a08830(int arg);
};
Obj* Obj::FUN_00a08830(int arg)
{
    FUN_009319e0(arg);
    unk80.Init();
    unk8c.Init();
    vtable = DAT_00e7c994;
    unkC0.Init();
    if (arg) {
        int count = unkC0.Capacity();
        if (count == 0 || ((int)unkC0.data & 0xf) != 0) {
            int want = count + 1;
            unkC0.Reserve(want < 4 ? 4 : want);
        }
    }
    return this;
}
}
}   // namespace f3m_00a08830

// @f3 0x00a0c070 (community match, verified in this file)
namespace f3m_00a0c070 {
namespace f3_a0c070 {

typedef float Real;
typedef float SimdReal;
typedef float SimdRealParameter;

class Matrix3;

class __declspec(align(16)) Vector4
{
public:
    Real x, y, z, w;

    inline Vector4() {}
    inline Real& operator()(int i) { return (&x)[i]; }
    inline const Real& operator()(int i) const { return (&x)[i]; }
    inline SimdReal getSimdAt(int i) const { return (&x)[i]; }
    inline void setZero4() { x = y = z = w = 0.0f; }
    inline void setSub4(const Vector4& a, const Vector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    inline void setAdd4(const Vector4& a, const Vector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    inline void setMul4(const Vector4& a, const Vector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    inline void setMul4(SimdRealParameter rs, const Vector4& a)
    {
        Real r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    inline void mul4(const Vector4& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }
    inline void mul4(SimdRealParameter rs)
    {
        Real s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    inline void add4(const Vector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    inline void add3clobberW(const Vector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
    }
    inline void sub3clobberW(const Vector4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
    }
    inline void setBroadcast3clobberW(const Vector4& v, int i)
    {
        Real r = v(i);
        x = r;
        y = r;
        z = r;
    }
    inline SimdReal horizontalAdd3() const { return x + y + z; }
    __forceinline void _setMul3(const Matrix3& r, const Vector4& v);
};

class Matrix3
{
public:
    Vector4 m_col0;
    Vector4 m_col1;
    Vector4 m_col2;
    inline Real& operator()(int r, int c) { return (&m_col0)[c](r); }
    inline const Real& operator()(int r, int c) const { return (&m_col0)[c](r); }
};

__forceinline void Vector4::_setMul3(const Matrix3& r, const Vector4& v)
{
    Real v0 = v.x;
    Real v1 = v.y;
    Real v2 = v.z;

    Vector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

template <class T> inline T* AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

class VelocityAccumulator
{
public:
    Vector4 m_unk00;
    Vector4 m_linearVel;
    Vector4 m_angularVel;
    Vector4 m_invMasses;
    Vector4 m_scratch0;
    Vector4 m_scratch1;
    inline const Vector4& getSumLinearVel() const { return m_scratch0; }
    inline const Vector4& getSumAngularVel() const { return m_scratch1; }
};

class VelocityAccumulatorOffset
{
public:
    inline VelocityAccumulator& getAccumulator(VelocityAccumulator* base) { return *AddByteOffset(base, m_offset); }
    int m_offset;
};

class Lin2AngJacobian
{
public:
    inline Real getRHS() const { return m_linear0(3); }
    Vector4 m_linear0;
    Vector4 m_angular[2];
};

struct ChainMatrixTriple
{
    Matrix3 m_lower;
    Matrix3 m_diagonalInv;
    Matrix3 m_upper;
};

struct BallSocketChainSchema
{
    inline static Lin2AngJacobian* getJacobians(BallSocketChainSchema* s)
    {
        return reinterpret_cast<Lin2AngJacobian*>(s + 1);
    }
    inline ChainMatrixTriple* getMatrixBuffer()
    {
        return reinterpret_cast<ChainMatrixTriple*>(AddByteOffset(getJacobians(this), m_numConstraints * 3 * sizeof(Lin2AngJacobian)));
    }
    inline Vector4* getTempBuffer()
    {
        return reinterpret_cast<Vector4*>(AddByteOffset(getMatrixBuffer(), m_numConstraints * sizeof(ChainMatrixTriple)));
    }
    inline VelocityAccumulatorOffset* getAccumulatorOffsetsBase()
    {
        return reinterpret_cast<VelocityAccumulatorOffset*>(AddByteOffset(getTempBuffer(), (m_numConstraints + 1) * sizeof(Vector4)));
    }
    short m_type;
    unsigned short m_numConstraints;
    int m_elementCount;
    Real m_tau;
    Real m_damping;
};

struct SolverInfo
{
    Vector4 m_unk00;
    Vector4 m_unk10;
    Vector4 m_unk20;
    Vector4 m_unk30;
    Vector4 m_integrateVelocityFactor;
};

struct SolverStepTemp
{
    int m_unused;
};

struct SolverElemTemp
{
    Real m_impulseApplied;
};

static __forceinline SimdReal getLinearDv0UserTauWithCustomRhs(const Lin2AngJacobian& jac, const VelocityAccumulator& mA, const VelocityAccumulator& mB, const SolverInfo& info, Real tau, Real damping, Real customRhs)
{
    Vector4 vel4;
    {
        Vector4 linVelA; linVelA.setSub4(mA.m_linearVel, mA.getSumLinearVel());
        Vector4 angVelA; angVelA.setSub4(mA.m_angularVel, mA.getSumAngularVel());
        Vector4 linVelB; linVelB.setSub4(mB.m_linearVel, mB.getSumLinearVel());
        Vector4 angVelB; angVelB.setSub4(mB.m_angularVel, mB.getSumAngularVel());
        Vector4 c; c.setSub4(linVelA, linVelB);
        Vector4 a; a.setMul4(angVelA, jac.m_angular[0]);
        Vector4 b; b.setMul4(angVelB, jac.m_angular[1]);
        c.mul4(jac.m_linear0);
        a.add4(b);
        vel4.setAdd4(a, c);
    }
    Vector4 svel4;
    {
        Vector4 linVelA = mA.getSumLinearVel();
        Vector4 angVelA = mA.getSumAngularVel();
        Vector4 linVelB = mB.getSumLinearVel();
        Vector4 angVelB = mB.getSumAngularVel();
        Vector4 c; c.setSub4(linVelA, linVelB);
        Vector4 a; a.setMul4(angVelA, jac.m_angular[0]);
        Vector4 b; b.setMul4(angVelB, jac.m_angular[1]);
        c.mul4(jac.m_linear0);
        a.add4(b);
        svel4.setAdd4(a, c);
    }
    const Real tf = info.m_integrateVelocityFactor(0) * tau;
    svel4.mul4(tf);
    vel4.mul4(damping);
    Vector4 rhsUpdate; rhsUpdate.setAdd4(svel4, vel4);
    SimdReal ru = rhsUpdate.horizontalAdd3();
    SimdReal dv = customRhs * tau - ru;
    return dv;
}

static __forceinline SimdReal getLinearDv0UserTau(const Lin2AngJacobian& jac, const VelocityAccumulator& mA, const VelocityAccumulator& mB, const SolverInfo& info, Real tau, Real damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}


static __forceinline void applyImpulse(SimdRealParameter imp, const Lin2AngJacobian& jac, VelocityAccumulator& mA, VelocityAccumulator& mB, SolverElemTemp& sr)
{
    Vector4 impA; impA.setMul4(imp, mA.m_invMasses);
    Vector4 impB; impB.setMul4(imp, mB.m_invMasses);
    Vector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    Vector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_linear0);
    negImpLinB.mul4(jac.m_linear0);
    mA.m_linearVel.add3clobberW(impLinA);
    mB.m_linearVel.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_angular[0]);
    impB.mul4(jac.m_angular[1]);
    mA.m_angularVel.add3clobberW(impA);
    mB.m_angularVel.add3clobberW(impB);
    Real acc = sr.m_impulseApplied;
    sr.m_impulseApplied = acc + imp;
}

}

using namespace f3_a0c070;

void __cdecl FUN_00a0c070(const SolverInfo& info, const SolverStepTemp& temp, VelocityAccumulator* accums, BallSocketChainSchema* chain, SolverElemTemp* sr)
{
    int numConstraints = chain->m_numConstraints;
    Lin2AngJacobian* j = BallSocketChainSchema::getJacobians(chain);
    VelocityAccumulatorOffset* va = chain->getAccumulatorOffsetsBase();
    ChainMatrixTriple* triple = chain->getMatrixBuffer();
    Vector4* g = chain->getTempBuffer() + 1;
    g[-1].setZero4();
    {
        for (int gi = 0; gi < numConstraints; j += 3, gi++)
        {
            VelocityAccumulator* raA = &va[gi].getAccumulator(accums);
            VelocityAccumulator* raB = &va[gi + 1].getAccumulator(accums);
            Vector4 dv;
            dv(0) = getLinearDv0UserTau(j[0], *raA, *raB, info, chain->m_tau, chain->m_damping);
            dv(1) = getLinearDv0UserTau(j[1], *raA, *raB, info, chain->m_tau, chain->m_damping);
            dv(2) = getLinearDv0UserTau(j[2], *raA, *raB, info, chain->m_tau, chain->m_damping);
            dv(3) = 0.0f;
            Vector4 tmp;
            tmp._setMul3(triple[gi].m_lower, g[gi - 1]);
            tmp.setSub4(dv, tmp);
            g[gi]._setMul3(triple[gi].m_diagonalInv, tmp);
        }
    }
    {
        Vector4 imp; imp.setZero4();
        j = BallSocketChainSchema::getJacobians(chain);
        for (int gi = numConstraints - 1; gi >= 0; gi--)
        {
            VelocityAccumulator* raA = &va[gi].getAccumulator(accums);
            VelocityAccumulator* raB = &va[gi + 1].getAccumulator(accums);
            int jIdx = gi * 3;
            Vector4 tmp;
            tmp._setMul3(triple[gi].m_upper, imp);
            imp.setSub4(g[gi], tmp);
            applyImpulse(imp(0), j[jIdx], *raA, *raB, sr[jIdx]);
            applyImpulse(imp(1), j[jIdx + 1], *raA, *raB, sr[jIdx + 1]);
            applyImpulse(imp(2), j[jIdx + 2], *raA, *raB, sr[jIdx + 2]);
        }
    }
}
}   // namespace f3m_00a0c070

// @f3 0x00a0a770 (community match, verified in this file)
namespace f3m_00a0a770 {
struct __declspec(align(16)) V4
{
    float x;
    float y;
    float z;
    float w;
    void operator=(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    void setZero4() { w = 0.0f; z = 0.0f; y = 0.0f; x = 0.0f; }
};

struct SrcElem
{
    unsigned char f00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    int f04;
    int f08;
    int f0c;
    V4 v10;
    V4 v20;
    V4 v30;
    V4 v40;
    V4 v50;
    V4 v60;
    V4 v70;
};

struct DstElem
{
    V4 a;
    V4 b;
};

struct Item
{
    int f00; int f04; int f08; int f0c;
    int f10; int f14; int f18; int f1c;
    int f20; int f24; int f28; int f2c;
    int f30; int f34; int f38; int f3c;
    int f40; int f44; int f48; int f4c;
    int f50; int f54; int f58; int f5c;
    int f60; int f64; int f68; int f6c;
    int f70; int f74; int f78; int f7c;
    int f80; int f84; int f88; int f8c;
    unsigned int f90;
};

struct Ctx
{
    void* f00;
    int f04;
    int f08;
    SrcElem* f0c;
    int f10;
    SrcElem* f14;
    DstElem* f18;
};

SrcElem* hkRigidMotionUtilApplyForcesAndBuildAccumulators(void* owner, Item** items, unsigned int count, unsigned int bytes, SrcElem* cur);

// pdb: hkpConstraintSolverSetup::initializeSolverState | hkpConstraintSolverSetup.obj | fnv360_0822_debug, objrun, low, conflict (skyrim: hkpConstraintSolverSetup::internalAddAccumulators)
// pdb params: stepInfo, solverInfo, constraintQueryIn, buffer, bufferSize, s
void FUN_00a0a770(Ctx* ctx, Item** items, unsigned int count)
{
    if (count == 0)
        return;

    if (ctx->f14 == ctx->f0c) {
        SrcElem* e = ctx->f14;
        e->f00 = 1;
        e->f01 = 1;
        e->v30.setZero4();
        e->v10.setZero4();
        e->v20.setZero4();
        e->v40.setZero4();
        e->v50.x = 0.0f;
        e->v50.y = 0.0f;
        e->v50.z = 0.0f;
        e->v50.w = 0.0f;
        e->v60.x = 0.0f;
        e->v60.y = 0.0f;
        e->v60.z = 0.0f;
        e->v60.w = 0.0f;
        e->v70.x = 0.0f;
        e->v70.y = 0.0f;
        e->v70.z = 0.0f;
        e->v70.w = 0.0f;
        ctx->f14 = e + 1;
        DstElem* d0 = ctx->f18;
        d0->b.setZero4();
        d0->a.setZero4();
    }

    for (unsigned int i = 0; i < count; i++)
        items[i]->f90 = (char*)ctx->f14 - (char*)ctx->f0c + i * 0x80;

    SrcElem* src = ctx->f14;
    DstElem* dst = ctx->f18 + (items[0]->f90 >> 7);
    ctx->f14 = hkRigidMotionUtilApplyForcesAndBuildAccumulators(ctx->f00, items, count, 0xd0, ctx->f14);

    V4 zero;
    zero.setZero4();
    for (unsigned int i = 0; i < count; i++) {
        dst->a = src->v40;
        dst->b = src->v50;
        src->v40.setZero4();
        src->v50.setZero4();
        src++;
        dst++;
    }

    ctx->f14->f00 = 3;
}
}   // namespace f3m_00a0a770

// @f3 0x00a0b790 (community match, verified in this file)
namespace f3m_00a0b790 {
namespace Integrate546
{
struct __declspec(align(16)) Vector
{
    float x, y, z, w;
    __forceinline void Difference(const Vector& left, const Vector& right)
    {
        x = left.x - right.x;
        y = left.y - right.y;
        z = left.z - right.z;
        w = left.w - right.w;
    }
    __forceinline void AddScaled(const Vector& vector, float scale)
    {
        x += vector.x * scale;
        y += vector.y * scale;
        z += vector.z * scale;
        w += vector.w * scale;
    }
    __forceinline void Add(const Vector& vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        w += vector.w;
    }
    __forceinline void SetProduct(const Vector& a,const Vector& b) {x=a.x*b.x;y=a.y*b.y;z=a.z*b.z;w=a.w*b.w;}
    static __forceinline void Mul(float& destination, const float& weight) { destination *= weight; }
    __forceinline void Multiply(const Vector& vector)
    {
        Mul(x, vector.x);
        Mul(y, vector.y);
        Mul(z, vector.z);
        Mul(w, vector.w);
    }
    __forceinline void Copy(const Vector& vector)
    {
        x = vector.x;
        y = vector.y;
        z = vector.z;
        w = vector.w;
    }
};
struct State
{
    int unk00,unk04,unk08,unk0c;
    Vector first, second;
    int unk30,unk34,unk38,unk3c;
    Vector baseFirst, baseSecond;
};
struct Parameters
{
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    float scale;
};


// pdb: updateSumVelocities | hkpSolver.obj | fnv360_0822_debug, objrun, medium
static __declspec(noinline) void FUN_00a0b790(const Parameters* parameters, bool flag, const Vector* bias, const Vector* weights, State* state)
{
    Vector first, second;
    first.Difference(state->first, state->baseFirst);
    second.Difference(state->second, state->baseSecond);
    state->baseFirst.AddScaled(first, parameters->scale);
    state->baseSecond.AddScaled(second, parameters->scale);
    if (!flag)
    {
        first.Add(state->baseFirst);
        second.Add(state->baseSecond);
        first.Add(*bias);
    }
    else
    {
        state->baseFirst.SetProduct(*weights,state->baseFirst);
        state->baseSecond.Multiply(*weights);
    }
    state->first.Copy(first);
    state->second.Copy(second);
}
State* volatile stateInput;
const Vector* volatile weightInput;

const Parameters* volatile parameterInput;
volatile bool flagInput;
const Vector* volatile biasInput;
void caller_of_FUN_00a0b790()
{


    FUN_00a0b790(parameterInput, flagInput, biasInput, weightInput, stateInput);
}
}












}   // namespace f3m_00a0b790

// @f3 0x00a062a0 (community match, verified in this file)
namespace f3m_00a062a0 {
// 0x00a062a0: hkpCharacterMovementUtil::calculateMovement(const hkpMovementUtilInput& input, hkVector4& velocityOut)
// of Havok 5.5.0 (hkpUtilities, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Builds a surface frame from the forward direction, the up direction and the surface normal (returning at once
// when forward and up are parallel), takes the velocity relative to the surface into that frame, moves it towards
// the desired velocity by the gain with the change clamped to the maximum velocity delta, and rotates it back.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The function body follows the SDK's unoptimized
// (hybrid) library object statement by statement and reproduces the release object. Only the function carries the
// packet's name.
namespace f3m_00a062a0 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline void hkMatrix3::setCols( const hkVector4& r0,
								const hkVector4& r1,
								const hkVector4& r2)
{
	m_col0 = r0;
	m_col1 = r1;
	m_col2 = r2;
}
class hkpCharacterMovementUtil
{
	public:
		struct hkpMovementUtilInput
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_UTILITIES); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCharacterMovementUtil::hkpMovementUtilInput), HK_MEMORY_CLASS_UTILITIES); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_UTILITIES); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkReal    m_gain;
			hkVector4 m_forward;
			hkVector4 m_up;
			hkVector4 m_surfaceNormal;
			hkVector4 m_currentVelocity;
			hkVector4 m_desiredVelocity;
			hkReal	  m_maxVelocityDelta;
			hkVector4 m_surfaceVelocity;
		};
		static void __cdecl FUN_00a062a0(const hkpMovementUtilInput& input, hkVector4& velocityOut);
};
// pdb: hkpCharacterMovementUtil::calculateMovement | hkpCharacterMovementUtil.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: input, velocityOut
void __cdecl hkpCharacterMovementUtil::FUN_00a062a0( const hkpMovementUtilInput& input, hkVector4& velocityOut )
{
	hkRotation surfaceFrame;
	{
		hkVector4 binorm;
		binorm.setCross( input.m_forward, input.m_up );
		if ( binorm.lengthSquared3() < 1.192092896e-07F )
		{
			return;
		}
		binorm.normalize3();
		hkVector4 tangent;
		tangent.setCross( binorm, input.m_surfaceNormal );
		tangent.normalize3();
		binorm.setCross( tangent, input.m_surfaceNormal );
		binorm.normalize3();
		surfaceFrame.setCols( tangent, binorm, input.m_surfaceNormal );
	}
	hkVector4 relative;
	relative.setSub4( input.m_currentVelocity, input.m_surfaceVelocity );
	relative.setRotatedInverseDir( surfaceFrame, relative );
	hkVector4 diff;
	diff.setSub4( input.m_desiredVelocity, relative );
	if ( diff.lengthSquared3() * input.m_gain > input.m_maxVelocityDelta * input.m_maxVelocityDelta )
	{
		diff.normalize3();
		diff.mul4( input.m_maxVelocityDelta / input.m_gain );
	}
	relative.addMul4( input.m_gain, diff );
	velocityOut.setRotatedDir( surfaceFrame, relative );
	velocityOut.add4( input.m_surfaceVelocity );
}

}  // namespace f3m_00a062a0
}   // namespace f3m_00a062a0

// @f3 0x00a033a0 (community match, verified in this file)
#include <math.h>
extern int DAT_010f3170;
extern "C" int DAT_00fdf044;
extern int DAT_01092a50;
namespace f3m_00a033a0 {
struct __declspec(align(16)) V4 {
 float x,y,z,w;
 V4& operator=(const V4& b){x=b.x;y=b.y;z=b.z;w=b.w;return *this;}
 void setMul(float s,const V4& b){x=s*b.x;y=s*b.y;z=s*b.z;w=s*b.w;}
 V4 operator+(const V4& b) const { V4 r={x+b.x,y+b.y,z+b.z,w+b.w};return r; }
 V4 operator-(const V4& b) const { V4 r={x-b.x,y-b.y,z-b.z,w-b.w};return r; }
 V4 operator*(float b) const { V4 r={x*b,y*b,z*b,w*b};return r; }
 void addScaled(const V4& b,float s){x+=b.x*s;y+=b.y*s;z+=b.z*s;w+=b.w*s;}
 void add(const V4& b){x+=b.x;y+=b.y;z+=b.z;w+=b.w;}
 void sub(const V4& b){x-=b.x;y-=b.y;z-=b.z;w-=b.w;}
 void scale(float b){x*=b;y*=b;z*=b;w*=b;}
 __forceinline V4 rotateVector(const V4& v) const {
   const float& vectorZ=v.z;
   const float& quaternionZ=z;

   float q=w;float scalar=q*q-0.5;
   V4 rotated={v.x*scalar,v.y*scalar,vectorZ*scalar,v.w*scalar};
   float dot=v.x*x+v.y*y+z*vectorZ;
   rotated.x+=dot*x;rotated.y+=dot*y;rotated.z+=dot*z;rotated.w+=dot*w;
   V4 cross={y*vectorZ-v.y*quaternionZ,(v.x*quaternionZ)-(v.z*x),v.y*x-v.x*y,0};
   rotated.addScaled(cross,q);
   return rotated+rotated;
  }
__declspec(noinline) void FUN_008d3290(const V4*,const V4*);
 __declspec(noinline) void FUN_009243a0(const V4*,const V4*,float);
 __declspec(noinline) void FUN_00a02710(const V4*,V4*) const;
};
struct MotionOrigin {float x,y,z,w;};
struct Motion {
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
 virtual void setLinear(const V4*);
 virtual void setAngular(const V4*);
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
 MotionOrigin origin;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
};
struct Body {
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
 Motion motion;
 V4 unk130;
 V4 unk140;
 V4 unk150;
 V4 unk160;
 V4 unk170;
 V4 unk180;
 V4 unk190;
 V4 unk1a0;
 V4 unk1b0;
 void FUN_0090b500();
};
struct History { V4 pos,rot,linear,angular; };
struct Context {
 V4 rootPos,rootRot,rootScale;
 V4* unk30; History* unk34; };
struct List { int count; Body** bodies; short* parents; int* indices; };
struct Params { float unk00,damping,kp,kd,correction,maxLinear,maxAngular,spring,maxVelocity,maxSpin,linearFactor,angularFactor; };
struct Transform { V4 pos,rot,unk20,unk30,axis; V4 unk50; };
struct Alloc {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void* allocate(unsigned); virtual void release(void*);
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 char* top;int unk24;char* mark;char* end;
};
typedef void* (__stdcall *TlsAllocatorGetter)(unsigned long);
__forceinline void* threadAllocator() {return (*(TlsAllocatorGetter*)&DAT_00fdf044)((unsigned long)DAT_010f3170);}
struct LocalPose { V4 pos,rot,scale; };
static __declspec(noinline) void FUN_00a02ab0(V4* v,float limit) {
 float length=v->x*v->x+v->y*v->y+v->z*v->z;
 float square=limit*limit;
 if(length>square) { float inv=1.0f/(float)sqrt(length);limit=inv*limit;v->scale(limit); }
}
static __declspec(noinline) float FUN_00a02b30(V4* v,float limit,float maximum) {
 float length=v->x*v->x+v->y*v->y+v->z*v->z;
 limit*=limit;
 float ratio=limit/length;
 if(length>limit) {
  float max2=maximum*maximum;
  float scale;
  if(max2<length){scale=(float)sqrt(max2/length);}else{scale=maximum*limit/length;}
  v->scale(scale);
 }
 return ratio;
}

void V4::FUN_00a02710(const V4* q,V4* out) const {
 float cy=z*q->x-x*q->z;
 float cz=x*q->y-y*q->x;
 out->x=y*q->z-z*q->y;
 out->y=cy;out->z=cz;out->w=0.0f;
 float qw=q->w;
 out->x-=x*qw;out->y-=y*qw;out->z-=z*qw;out->w-=w*qw;
 float sw=w;
 out->x+=q->x*sw;out->y+=q->y*sw;out->z+=q->z*sw;out->w+=q->w*sw;
 out->x=out->x+out->x;out->y=out->y+out->y;out->z=out->z+out->z;out->w=out->w+out->w;
 float dot=x*q->x+y*q->y+z*q->z+w*q->w;
 if(dot<0.0f){out->x=-out->x;out->y=-out->y;out->z=-out->z;out->w=-out->w;}
}

void V4::FUN_008d3290(const V4* a,const V4* b) {
 V4 r={a->y*b->z-a->z*b->y,a->z*b->x-a->x*b->z,a->x*b->y-b->x*a->y,0};
 r.addScaled(*b,a->w);r.addScaled(*a,b->w);
 float dot=a->x*b->x+b->y*a->y+a->z*b->z;
 r.w=a->w*b->w-dot;
 *this=r;
}
extern float __cdecl FUN_008d3240(float);
void V4::FUN_009243a0(const V4* a,const V4* b,float t) {
 float dot=a->x*b->x+a->y*b->y+a->z*b->z+a->w*b->w;
 float sign=1.0f;
 if(dot<0.0f){dot=-dot;sign=-1.0f;}
 float s0,s1;
 if(dot<0.9989999999525025){
  float angle=FUN_008d3240(dot);
  float reciprocal=1.0f/(float)sqrt(1.0f-dot*dot);
  float theta=angle*t;
  s0=(float)sin(angle-theta)*reciprocal;
  s1=(float)sin(theta)*reciprocal*sign;
 }else{s0=1.0f-t;s1=t*sign;}
 V4 r=*a*s0;r.addScaled(*b,s1);
 float length=r.x*r.x+r.y*r.y+r.z*r.z+r.w*r.w;
 float inverse=length!=0.0f?1.0f/(float)sqrt(length):0.0f;
 r.scale(inverse);*this=r;
}
static V4 rotatePose(const V4& q,const V4& v) {
 float scalar=q.w*q.w-0.5;
 V4 r=v*scalar;
 float dot=v.x*q.x+v.y*q.y+v.z*q.z;
 r.addScaled(q,dot);
 V4 cross={q.y*v.z-v.y*q.z,v.x*q.z-v.z*q.x,v.y*q.x-v.x*q.y,0};
 r.addScaled(cross,q.w);
 return r+r;
}
__forceinline const V4& solverDefaultVector(){return *(const V4*)&DAT_01092a50;}
static __declspec(noinline) void FUN_00a02bf0(LocalPose* poses,List* list,Params* params,Context* context,Transform* out) {
 for(int i=0;i<list->count;++i){
  int parent=list->parents[i];
  const V4* parentPos;
  const V4* parentRot;
  const V4* parentScale;
  if(parent>=0){parentPos=&out[parent].unk30;parentRot=&out[parent].axis;parentScale=&out[parent].unk50;}
  else {parentPos=&context->rootPos;parentRot=&context->rootRot;parentScale=&context->rootScale;}
  LocalPose* pose=poses+i;
  V4 rotated=rotatePose(*parentRot,pose->pos);
  out[i].unk30=rotated+*parentPos;
  out[i].axis.FUN_008d3290(parentRot,&pose->rot);
  V4 scale={pose->scale.x*parentScale->x,pose->scale.y*parentScale->y,pose->scale.z*parentScale->z,pose->scale.w*parentScale->w};
  out[i].unk50=scale;
  V4 position=out[i].unk30;
  V4 rotation=out[i].axis;
  Params* p=list->indices?params+list->indices[i]:params;
  if(p->unk00>0.0f && parent>=0){
   Body* b=list->bodies[parent];
   V4 parentOrigin={b->motion.origin.x,b->motion.origin.y,b->motion.origin.z,b->motion.origin.w};
   V4 currentPosition=rotatePose(b->unk150,pose->pos)+parentOrigin;
   V4 currentRotation;currentRotation.FUN_008d3290(&b->unk150,&pose->rot);
   rotation.FUN_009243a0(&rotation,&currentRotation,p->unk00);
   position.scale(1.0f-p->unk00);position.addScaled(currentPosition,p->unk00);
  }
  V4 offset=rotatePose(rotation,list->bodies[i]->unk160);
  position.add(offset);
  out[i].pos=position;
  out[i].rot=rotation;
  out[i].unk20=solverDefaultVector();
 }
}

typedef char VerifyVectorSize[(sizeof(V4)==16)?1:-1];
typedef char VerifyVectorAlignment[(__alignof(V4)==16)?1:-1];
typedef char VerifyMotionSize[(sizeof(Motion)==0x60)?1:-1];
typedef char VerifyMotionOrigin[(offsetof(Motion,origin)==0x40)?1:-1];
typedef char VerifyBodyMotion[(offsetof(Body,motion)==0xd0)?1:-1];
typedef char VerifyBodyPosition[(offsetof(Body,unk130)==0x130)?1:-1];
typedef char VerifyBodyQuaternion[(offsetof(Body,unk150)==0x150)?1:-1];
typedef char VerifyBodyLocalCOM[(offsetof(Body,unk160)==0x160)?1:-1];
typedef char VerifyBodyLinear[(offsetof(Body,unk1a0)==0x1a0)?1:-1];
typedef char VerifyBodyAngular[(offsetof(Body,unk1b0)==0x1b0)?1:-1];
typedef char VerifyBodySize[(sizeof(Body)==0x1c0)?1:-1];
typedef char VerifyParamStride[(sizeof(Params)==0x30)?1:-1];
typedef char VerifyHistoryStride[(sizeof(History)==0x40)?1:-1];
typedef char VerifyStreamStride[(sizeof(Transform)==0x60)?1:-1];
typedef char VerifyPoseStride[(sizeof(LocalPose)==0x30)?1:-1];
typedef char VerifyContextPoses[(offsetof(Context,unk30)==0x30)?1:-1];
typedef char VerifyContextHistory[(offsetof(Context,unk34)==0x34)?1:-1];
typedef char VerifyAllocatorCursor[(offsetof(Alloc,top)==0x20)?1:-1];
typedef char VerifyAllocatorMark[(offsetof(Alloc,mark)==0x28)?1:-1];
typedef char VerifyAllocatorEnd[(offsetof(Alloc,end)==0x2c)?1:-1];

void __cdecl FUN_00a033a0(float timestep,Context* context,List* list,Params* params,float* output) {
 int count=list->count;
 Alloc* allocator=(Alloc*)threadAllocator();
 unsigned size=(count*96+16)&~15;
 Transform* transforms;
 char* current=allocator->top;char* next=current+size;
 if(next<=allocator->end){allocator->top=next;transforms=(Transform*)current;}
 else transforms=(Transform*)allocator->allocate(size);
 FUN_00a02bf0((LocalPose*)context->unk30,list,params,context,transforms);
 float inverse=1.0f/timestep;
 for(int i=0;i<list->count;++i){
  Params* p=list->indices?params+list->indices[i]:params;
  Body* body=list->bodies[i];
  History* history=context->unk34+i;
  Transform* t=transforms+i;
  float damping=1.0f-p->damping;
  V4 linear=(t->pos-body->unk130);linear.scale(inverse);
  V4 velocity=t->pos-history->pos;history->pos=t->pos;velocity.scale(inverse);
  V4 acceleration=velocity-history->linear;history->linear=velocity;
  V4 force=body->unk1a0;
  V4 target;target.setMul(damping,force);target.addScaled(acceleration,p->kp);
  velocity.sub(target);V4 derivative;derivative.setMul(p->kd,velocity);target.add(derivative);
  linear.sub(target);
  V4 correction;correction.setMul(p->correction,linear);
  FUN_00a02ab0(&correction,p->maxLinear);target.add(correction);
  if(p->spring!=0.0f){
   V4 doubled=t->axis.rotateVector(body->unk160);doubled.add(t->unk30);
   V4 spring=doubled-body->unk130;spring.scale(inverse);spring.sub(target);spring.scale(p->spring);
   float factor=inverse*p->linearFactor*p->spring;
   float ratio=FUN_00a02b30(&spring,p->maxVelocity,factor);
   if(output)output[i]=ratio;
   target.add(spring);
  }
  body->FUN_0090b500();body->motion.setLinear(&target);
  V4 angular;
  body->unk150.FUN_00a02710(&t->rot,&angular);angular.scale(inverse);
  V4 oldVelocity;
  history->rot.FUN_00a02710(&t->rot,&oldVelocity);history->rot=t->rot;oldVelocity.scale(inverse);
  V4 angularAcceleration=oldVelocity-history->angular;history->angular=oldVelocity;
  V4 angularForce=body->unk1b0;
  V4 angularTarget;angularTarget.setMul(damping,angularForce);angularTarget.addScaled(angularAcceleration,p->kp);
  oldVelocity.sub(angularTarget);V4 angularDerivative;angularDerivative.setMul(p->kd,oldVelocity);angularTarget.add(angularDerivative);
  angular.sub(angularTarget);
  V4 angularCorrection;angularCorrection.setMul(p->correction,angular);
  FUN_00a02ab0(&angularCorrection,p->maxAngular);angularTarget.add(angularCorrection);
  if(p->spring!=0.0f){
   V4 spring;
   body->unk150.FUN_00a02710(&t->axis,&spring);spring.scale(inverse);spring.sub(angularTarget);spring.setMul(p->spring,spring);
   float factor=inverse*p->angularFactor*p->spring;
   float ratio=FUN_00a02b30(&spring,p->maxSpin,factor);
   if(output)output[i]+=ratio;
   angularTarget.add(spring);
  }
  body->FUN_0090b500();body->motion.setAngular(&angularTarget);
 }
 allocator=(Alloc*)threadAllocator();
 allocator->top=(char*)transforms;
 if((char*)transforms==allocator->mark)allocator->release(transforms);
}
}   // namespace f3m_00a033a0

// @f3 0x00a09ce0 (community match, verified in this file)
namespace f3m_00a09ce0 {
// 0x00a09ce0: finds, by 23 bisection steps between 10 and 11, where the four-lane float to 16-bit conversion
// (add offset, scale, add 3 * 65536, take bits 6..21 of the float) steps from 10 to 11, and returns how far that
// point is from 11. The conversion is the vector helper below, forced inline; only its first lane survives.
namespace hkA09CE0 {
struct hkQuadReal {
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};
class hkVector4 {
public:
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
    void setAll(float a) { x = a; y = a; z = a; w = a; }
    void setAdd4(const hkVector4& a, const hkVector4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void mul4(const hkVector4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    const hkQuadReal& getQuad() const { return *reinterpret_cast<const hkQuadReal*>(this); }
    hkQuadReal& getQuad() { return *reinterpret_cast<hkQuadReal*>(this); }
};
union hkIntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
extern const hkQuadReal DAT_00f7b0c0;   // 3 * 65536 in all four lanes
extern hkVector4 DAT_01092a50;          // offset vector
extern const float DAT_00db8ea4;        // 10.0f
extern const float DAT_00e0613c;        // 11.0f
extern const double DAT_00dd2790;       // 11.0

__forceinline void convertToUint16(const hkVector4& in, const hkVector4& offset, const hkVector4& scale, hkIntUnion64& out)
{
    hkVector4 x;
    x.setAdd4(in, offset);
    x.mul4(scale);
    hkVector4 magic;
    magic.getQuad() = DAT_00f7b0c0;
    x.add4(magic);
    union {
        hkQuadReal q;
        unsigned int i[4];
    } u;
    u.q = x.getQuad();
    out.u16[0] = static_cast<unsigned short>(u.i[0] >> 6);
    out.u16[1] = static_cast<unsigned short>(u.i[1] >> 6);
    out.u16[2] = static_cast<unsigned short>(u.i[2] >> 6);
    out.u16[3] = static_cast<unsigned short>(u.i[3] >> 6);
}
}

// pdb: hkpSampledHeightFieldShape::hkpSampledHeightFieldShape | hkpSampledHeightFieldShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: ci, hfType
float __cdecl FUN_00a09ce0()
{
    using namespace hkA09CE0;
    float l = DAT_00db8ea4;
    float h = DAT_00e0613c;
    hkVector4 one;
    one.setAll(1.0f);
    for (int i = 0; i < 23; i++) {
        float m = static_cast<float>((h + l) * 0.5);
        hkVector4 p;
        p.setAll(m);
        hkIntUnion64 out;
        convertToUint16(p, DAT_01092a50, one, out);
        if (out.u16[0] < 11)
            l = m;
        else
            h = m;
    }
    return static_cast<float>((h + l) * 0.5 - DAT_00dd2790);
}
}   // namespace f3m_00a09ce0

// @f3 0x00a0b990 (community match, verified in this file)
namespace f3m_00a0b990 {
// Best measured flags: /MT /O2 /GS /EHsc /Gy (not the pack's listed flags).
namespace f3m_00a0b990 {
// Fake match: this scalar wrapper preserves the candidate's inlined float rounding and temporary form.
struct S0a0b990_Scalar { float value; S0a0b990_Scalar(float f) : value(f) {} };
union S0a0b990_SolverSlot { float lambda; int bodyOffset; };
struct __declspec(align(16)) S0a0b990_Vec {
    float x;
    float y;
    float z;
    float w;

    void setSub3(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
    void setAdd3(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; }
    void setMul3(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = b.x * a.x; y = b.y * a.y; z = b.z * a.z; }
    void setMul3(const S0a0b990_Vec& a, float s) { x = a.x * s; y = a.y * s; z = a.z * s; }
    void setMul3r(const S0a0b990_Vec& a, const float& s) { x = a.x * s; y = a.y * s; z = a.z * s; }
    void mul3r(const S0a0b990_Vec& a) { x *= a.x; y *= a.y; z *= a.z; }
    void setMul4(const S0a0b990_Vec& a, const S0a0b990_Scalar& factor) { x = a.x * factor.value; y = a.y * factor.value; z = a.z * factor.value; w = a.w * factor.value; }
    void add3(const S0a0b990_Vec& a) { x += a.x; y += a.y; z += a.z; }
    void sub3(const S0a0b990_Vec& a) { x -= a.x; y -= a.y; z -= a.z; }
    void mul3(const S0a0b990_Vec& a) { x = a.x * x; y = a.y * y; z = a.z * z; }
    void mul3(float s) { x *= s; y *= s; z *= s; }
    void setSub4(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    void setAdd4(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void setMul4(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    void add4(const S0a0b990_Vec& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    void mul4(const S0a0b990_Vec& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    void mul4(const S0a0b990_Scalar& factor) { float s = factor.value; x *= s; y *= s; z *= s; w *= s; }
    float horizontalAdd3() const { return x + y + z; }
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
};

struct S0a0b990_Accum {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S0a0b990_Vec linVel;
    S0a0b990_Vec angVel;
    S0a0b990_Vec invMasses;
    S0a0b990_Vec linVel0;
    S0a0b990_Vec angVel0;
};

struct S0a0b990_Jac {
    S0a0b990_Vec lin;
    S0a0b990_Vec angA;
    S0a0b990_Vec angB;

    __forceinline void calcJv(const S0a0b990_Vec& linA, const S0a0b990_Vec& angA0,
                              const S0a0b990_Vec& linB, const S0a0b990_Vec& angB0, S0a0b990_Vec& out) const
    {
        S0a0b990_Vec l;
        l.setSub4(linA, linB);
        S0a0b990_Vec a;
        a.setMul4(angA0, angA);
        S0a0b990_Vec b;
        b.setMul4(angB0, angB);
        l.mul4(lin);
        a.add4(b);
        out.setAdd4(a, l);
    }
};

struct S0a0b990_Diag {
    float lower;
    float diag;
    float upper;
};

struct S0a0b990_Chain {
    __forceinline unsigned short getnumLinks() {return numLinks;}
    unsigned short unk00;
    unsigned short numLinks;
    float unk04;
    float tau;
    float damping;
    S0a0b990_Jac jacs[1];
};

struct S0a0b990_Info {
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
    float invDeltaTime;
};

}
using namespace f3m_00a0b990;
// Fake match: the array view steers the inlined subscript's operand ranking.
struct FloatArray { float* data; FloatArray(float* p):data(p){} float& operator[](int i)const{return data[i];} };

static __forceinline void mulLanes(S0a0b990_Vec& v, const S0a0b990_Vec& m, float s) { v.x = m.x * s; v.y = m.y * s; v.z = m.z * s; v.w = m.w * s; }

// pdb: hkSolver_solveStiffSpringChain | hkpSolver.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkSolver_solveBallAndSocketChain)
// pdb params: info, temp, accums, chain, sr
void FUN_00a0b990(S0a0b990_Info* info, void* unused, char* accums, S0a0b990_Chain* chain, float* impulses)
{
    S0a0b990_Jac* jacs = chain->jacs;
    int* offsets = (int*)((char*)chain->jacs + chain->getnumLinks() * (sizeof(S0a0b990_Jac) + sizeof(S0a0b990_Diag) + sizeof(float)) + sizeof(float));
    S0a0b990_Diag* diags = (S0a0b990_Diag*)((char*)chain->jacs + chain->getnumLinks() * sizeof(S0a0b990_Jac));
    FloatArray lam = (float*)((char*)chain->jacs + chain->getnumLinks() * (sizeof(S0a0b990_Jac) + sizeof(S0a0b990_Diag)) + sizeof(float));
    int n = chain->getnumLinks();

    lam[-1] = 0.0f;
    int i;
    for (i = 0; i < n; i++) {
        float s = chain->tau;
        int oa = offsets[i];
        int ob = offsets[i + 1];
        S0a0b990_Accum* a = (S0a0b990_Accum*)(accums + oa);
        S0a0b990_Accum* b = (S0a0b990_Accum*)(accums + ob);
        S0a0b990_Vec dLinA; dLinA.setSub4(a->linVel, a->linVel0);
        S0a0b990_Vec dAngA; dAngA.setSub4(a->angVel, a->angVel0);
        S0a0b990_Vec dLinB; dLinB.setSub4(b->linVel, b->linVel0);
        S0a0b990_Vec dAngB; dAngB.setSub4(b->angVel, b->angVel0);
        S0a0b990_Vec r1;
        jacs[i].calcJv(dLinA, dAngA, dLinB, dAngB, r1);
        S0a0b990_Vec r2;
        S0a0b990_Vec linA0 = a->linVel0;
        S0a0b990_Vec angA0 = a->angVel0;
        S0a0b990_Vec linB0 = b->linVel0;
        S0a0b990_Vec angB0 = b->angVel0;
        jacs[i].calcJv(linA0, angA0, linB0, angB0, r2);
        r2.mul4(info->invDeltaTime * s);
        float c = chain->damping;
        r1.mul4(c);
        S0a0b990_Vec sum;
        sum.setAdd4(r2, r1);
        float rhs = s * jacs[i].lin.w - sum.horizontalAdd3();
        lam[i] = (rhs - lam[i - 1] * diags[i].lower) / diags[i].diag;
    }

    float x = 0.0f;
    // Guess at the source: the impulses use a second counter j that runs with i. VC8 places each strength-reduced
    // cursor update right after the update of the counter it derives from and merges the two counters afterwards,
    // which gives the original order of the cursor updates (sub esi,4 before sub edx,0x30) with no extra code.
    int j;
    for (j = n - 1, i = j; i >= 0; i--, j--) {
        float up = diags[i].upper;
        x = lam[i] - x * up;
        int oa = offsets[i];
        int ob = offsets[i + 1];
        S0a0b990_Accum* a = (S0a0b990_Accum*)(accums + oa);
        S0a0b990_Accum* b = (S0a0b990_Accum*)(accums + ob);
        S0a0b990_Vec va; mulLanes(va, a->invMasses, x);
        S0a0b990_Vec vb; mulLanes(vb, b->invMasses, x);
        S0a0b990_Vec la; la.setMul3r(jacs[i].lin, va.w);
        S0a0b990_Vec lb; lb.setMul3r(jacs[i].lin, vb.w);
        // Guess: the lane access paths (operator() or member) set the x87 operand order of each add.
        a->linVel(0) += la(0); a->linVel(1) += la.y; a->linVel(2) += la(2);
        b->linVel.x -= lb.x; b->linVel.y -= lb.y; b->linVel.z -= lb.z;
        va.mul3r(jacs[i].angA);
        vb.mul3r(jacs[i].angB);
        a->angVel.add3(va);
        S0a0b990_Vec& bav = b->angVel;   // guess: the alias sets the operand order of the b->angVel.x add
        bav.add3(vb);
        impulses[j] += x;
    }
}

}   // namespace f3m_00a0b990

// @f3 0x00a00ec0 (community match, verified in this file)
extern const hkReal hkUFloat8_intToReal[256];
	extern hkReal hkTransformIdentity[];
extern hkReal HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY;
extern hkReal HK_CONTACT_EXPONENTIAL_ERROR_RECOVERY_VELOCITY;
namespace f3m_00a00ec0 {
// 0x00a00ec0: hkSimpleContactConstraintDataBuildJacobian(hkpSimpleContactConstraintAtom* atom, const hkpConstraintQueryIn&
// in, hkBool writeHeaderSchemas, hkpConstraintQueryOut& out) of Havok 5.5.0 (hkpConstraintSolver,
// hkpSimpleContactConstraintInfo.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Builds the jacobian schemas of a
// simple contact constraint: an optional header schema, then per contact point a linear row along the normal (a single
// contact schema, or a pair schema with the previous row when the point uses the second solver path), then the
// friction rows from the averaged normal and position (2d friction, or 3d friction with the contact radius).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and the
// preprocessed source was cut down mechanically to the declarations the function's code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the full compile); those declarations are the
// SDK's text with its names. The library's own types that no SDK header ships (the jacobian classes, the jacobian
// schemas and their SchemaType enum, hkSimpleContactConstraintDataInfoInternal, namespace hkJacobianBuilder,
// calculateRhs) are declared from the hkpConstraintSolver library's debug records; the inline bodies follow the SDK's
// unoptimized (hybrid) library object, which this source reproduces up to one assert temporary, and the release
// object's own copies of each helper, which this source matches one by one. Only the function carries the packet's
// name. Compiled for the check with /MT /O2 /GS /EHsc /Gy (the pack lists /Od; the target is optimised code).
namespace f3m_00a00ec0 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
};
extern "C"
{
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
__forceinline void hkVector4::setW(const hkVector4& v)
{
	w = v.w;
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
}
inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
inline hkSimdReal hkVector4::horizontalAdd4() const
{
	return x+y+z+w;
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
	;
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkVector4& hkTransform::getColumn(int x) const
{
	return m_rotation.getColumn(x);
}
const hkTransform& __cdecl hkTransform::getIdentity()
{
	return reinterpret_cast<const hkTransform&>(hkTransformIdentity);
}
namespace hkVector4Util
{
__forceinline void __cdecl reserveRegisters( hkUint32 registerMask );
__forceinline void __cdecl releaseRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::reserveRegisters( hkUint32 registerMask )
{
}
__forceinline void __cdecl hkVector4Util::releaseRegisters( hkUint32 registerMask )
{
}
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkContactPoint), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getPosition() const
{
	return m_position;
}
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
inline hkReal hkContactPoint::getDistance() const
{
	return m_separatingNormal(3);
}
class hkpVelocityAccumulator
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulator), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return reinterpret_cast<hkRotation&>(m_scratch1); }
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return m_scratch1; }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return m_scratch1; }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkpSolverResults
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverResults), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
struct hkpSimpleContactConstraintAtom;
class hkpSimpleContactConstraintDataInfo
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSimpleContactConstraintDataInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		enum {	HK_FLAG_OK = 0x00, HK_FLAG_POINT_REMOVED = 0x01, HK_FLAG_AREA_CHANGED = 0x04 };
		void init()
		{
			m_flags = HK_FLAG_OK;
			m_index = 3;
			for(int i = 0; i < 7; ++i)
			{
				m_data[i] = 0;
			}
		}
		hkpSimpleContactConstraintDataInfo()
		{
			init();
		}
		__declspec(align(16)) hkUint16 m_flags;
		hkUint16 m_index;
		hkUint32 m_data[7];
		hkpSimpleContactConstraintDataInfo(hkFinishLoadedObjectFlag f) {}
};
struct hkpSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo::DeactivationInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
struct hkpConstraintInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_DYNAMICS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintInfo), HK_MEMORY_CLASS_DYNAMICS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_DYNAMICS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	inline void clear( ) { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
	inline void addHeader( ) { m_sizeOfSchemas += 16; }
	inline void add( int schemaSize, int numSolverResults, int numSolverTempElems ) { m_sizeOfSchemas += schemaSize; m_numSolverResults += numSolverResults; m_numSolverElemTemps += numSolverTempElems; }
	inline void add( const hkpConstraintInfo& other);
	inline void sub( const hkpConstraintInfo& other);
	inline void merge( const hkpConstraintInfo& other);
};
class hkpContactPointPropertiesStream;
struct hkpConstraintAtom
{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintAtom), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_SET_LOCAL_TRANSFORMS,
			TYPE_SET_LOCAL_TRANSLATIONS,
			TYPE_SET_LOCAL_ROTATIONS,
			TYPE_BALL_SOCKET,
			TYPE_STIFF_SPRING,
			TYPE_LIN,
			TYPE_LIN_SOFT,
			TYPE_LIN_LIMIT,
			TYPE_LIN_FRICTION,
			TYPE_LIN_MOTOR,
			TYPE_2D_ANG,
			TYPE_ANG,
			TYPE_ANG_LIMIT,
			TYPE_TWIST_LIMIT,
			TYPE_CONE_LIMIT,
			TYPE_ANG_FRICTION,
			TYPE_ANG_MOTOR,
			TYPE_RAGDOLL_MOTOR,
			TYPE_PULLEY,
			TYPE_OVERWRITE_PIVOT,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			TYPE_MODIFIER_IGNORE_CONSTRAINT,
			TYPE_MAX
		};
		enum CallbackRequest
		{
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		__forceinline enum AtomType getType() const { return m_type; }
		__forceinline int isModifierType() const { return m_type >= TYPE_MODIFIER_SOFT_CONTACT; }
	protected:
		hkpConstraintAtom(enum AtomType type) : m_type(type) {}
	private:
		hkpConstraintAtom();
	public:
		hkEnum<AtomType,hkUint16> m_type;
		hkpConstraintAtom(hkFinishLoadedObjectFlag f) {}
};
struct hkpSimpleContactConstraintAtom : public hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSimpleContactConstraintAtom), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	public:
		hkpSimpleContactConstraintAtom() : hkpConstraintAtom(TYPE_CONTACT) {}
		__forceinline hkContactPoint* getContactPoints() const { return const_cast<hkContactPoint*>( reinterpret_cast<const hkContactPoint*>( this+1 ) ); }
		__forceinline int getContactPointPropertiesStriding() const;
		__forceinline hkpContactPointPropertiesStream* getContactPointPropertiesStream() const { return const_cast<hkpContactPointPropertiesStream*>( reinterpret_cast<const hkpContactPointPropertiesStream*>( hkAddByteOffsetConst( getContactPoints(), sizeof(hkContactPoint) * m_numReservedContactPoints ) ) ); }
		__forceinline hkpContactPointPropertiesStream* getContactPointPropertiesStream(int i) const;
	public:
		__forceinline hkpConstraintAtom* next() const { ; return 0; }
		__forceinline int numSolverResults() const    { return m_numContactPoints+3; }
		__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const
		{
			int size = m_numContactPoints;
			infoOut.m_sizeOfSchemas    += 16
										+ (size >> 1) * 112
				                        + (size & 1) * 48
										+ 112;
			infoOut.m_maxSizeOfSchema = infoOut.m_sizeOfSchemas + (144 - 112);
			infoOut.m_numSolverResults   += size + 2;
			infoOut.m_numSolverElemTemps += size + (2 + 1);
			if ( size >= 2 )
			{
				infoOut.m_sizeOfSchemas   += 144 - 112;
				infoOut.m_numSolverResults   += 1;
				infoOut.m_numSolverElemTemps += 1 + 0;
			}
		}
	public:
		hkUint16 m_sizeOfAllAtoms;
		hkUint16 m_numContactPoints;
		hkUint16 m_numReservedContactPoints;
		hkUint8 m_numUserDatasForBodyA;
		hkUint8 m_numUserDatasForBodyB;
		hkUint8 m_contactPointPropertiesStriding;
		hkUint16 m_maxNumContactPoints;
		__declspec(align(16)) class hkpSimpleContactConstraintDataInfo m_info;
	public:
		hkpSimpleContactConstraintAtom(hkFinishLoadedObjectFlag f);
};
class hkContactPointMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkReal getFriction( ) const;
		inline void setFriction( hkReal r );
		inline hkReal getRestitution( ) const;
		inline void setRestitution( hkReal r );
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline hkBool32 isPotential();
		inline void setMaxImpulsePerStep( hkUFloat8 impulse );
		inline hkReal getMaxImpulsePerStep();
	protected:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkContactPointMaterial), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		void reset()
		{
			m_friction.m_value = 0;
			m_maxImpulse.m_value = 0;
			m_restitution = 0;
			m_flags = CONTACT_IS_NEW_AND_POTENTIAL;
		}
		enum  FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL  = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};
inline hkReal hkContactPointMaterial::getFriction() const
{
	return m_friction;
}
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpContactPointProperties), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkBool wasUsed()
		{
			return !isPotential() && ( m_impulseApplied > 0.f );
		}
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
		static inline int getNumExtendedUserDatas(const hkpSimpleContactConstraintAtom* atom, int bodyIdx);
		inline hkpContactPointProperties::UserData& getExtendedUserData(const hkpSimpleContactConstraintAtom* atom, int bodyIdx, int i);
};
class hkpContactPointPropertiesStream
{
public:
	__forceinline hkpContactPointProperties* asProperties() { return reinterpret_cast<hkpContactPointProperties*>(this); }
	__forceinline const hkpContactPointProperties* asProperties() const { return reinterpret_cast<const hkpContactPointProperties*>(this); }
};
__forceinline int hkpSimpleContactConstraintAtom::getContactPointPropertiesStriding() const { return m_contactPointPropertiesStriding; }
class hkStepInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkStepInfo), HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
class hkpConstraintQueryStepInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintQueryStepInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
		hkPadSpu<float>		m_microStepDeltaTime;
		hkPadSpu<float>		m_substepInvDeltaTime;
		hkPadSpu<float>		m_frameDeltaTime;
		hkPadSpu<float>		m_frameInvDeltaTime;
		hkPadSpu<float>		m_invNumSteps;
		hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
		hkPadSpu<float>		m_rhsFactor;
		hkPadSpu<float>		m_virtMassFactor;
		hkPadSpu<float> m_frictionRhsFactor;
};
class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintQueryIn), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpConstraintQueryIn() { }
		__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
		hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
		hkPadSpu<const hkTransform*>	m_transformA;
		hkPadSpu<const hkTransform*>	m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
		hkPadSpu<void*>	m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
		inline void set( const hkpSolverInfo& si, const hkStepInfo& stepInfo )
		{
			m_substepDeltaTime    = si.m_deltaTime;
			m_microStepDeltaTime  = si.m_deltaTime * si.m_invNumMicroSteps;
			m_substepInvDeltaTime = si.m_invDeltaTime;
			m_invNumSteps		  = si.m_invNumSteps;
			m_invNumStepsTimesMicroSteps	  = si.m_invNumSteps * si.m_invNumMicroSteps;
			m_tau			      = si.m_tau;
			m_damping		      = si.m_damping;
			m_rhsFactor			  = si.m_tauDivDamp * si.m_invDeltaTime;
			m_virtMassFactor      = si.m_damping;
			m_frictionRhsFactor   = si.m_frictionTauDivDamp * si.m_invDeltaTime;
			m_frameDeltaTime      = stepInfo.m_deltaTime;
			m_frameInvDeltaTime   = stepInfo.m_invDeltaTime;
		}
};
class hkpJacobianSchema;
class  hkpConstraintQueryOut
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintQueryOut), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline void setInvJacDiag( hkReal v ) { m_angular[0](3) = v; }
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
};
class hkp1Lin2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1Lin2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		inline void setRHS( hkReal v ) { m_linear0(3) = v; }
		inline const hkReal& getRHS() const { return m_linear0(3); }
		inline void setInvJacDiag( hkReal v ) { m_angular[0](3) = v; }
		inline hkReal getUserValue() const { return m_angular[1](3); }
		inline void setUserValue( hkReal v ) { m_angular[1](3) = v; }
		hkReal getDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
};
class hkpJacDouble2Bil
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacDouble2Bil), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac0;
		hkp1Lin2AngJacobian m_jac1;
};
class hkpJacTriple2Bil1Ang
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacTriple2Bil1Ang), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac0;
		hkp1Lin2AngJacobian m_jac1;
		hkp2AngJacobian m_jac2;
};
class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO,
			SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
			SCHEMA_TYPE_SIMPLE_BEGIN,
			SCHEMA_TYPE_1D_BILATERAL,
			SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
			SCHEMA_TYPE_1D_LINEAR_LIMITS,
			SCHEMA_TYPE_1D_FRICTION,
			SCHEMA_TYPE_1D_LINEAR_MOTOR,
			SCHEMA_TYPE_1D_PULLEY,
			SCHEMA_TYPE_1D_ANGULAR,
			SCHEMA_TYPE_1D_ANGULAR_LIMITS,
			SCHEMA_TYPE_1D_ANGULAR_FRICTION,
			SCHEMA_TYPE_1D_ANGULAR_MOTOR,
			SCHEMA_TYPE_SINGLE_CONTACT,
			SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_PAIR_CONTACT,
			SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_2D_FRICTION,
			SCHEMA_TYPE_3D_FRICTION,
			SCHEMA_TYPE_SET_MASS,
			SCHEMA_TYPE_ADD_VELOCITY,
			SCHEMA_TYPE_SIMPLE_END,
			SCHEMA_TYPE_STIFF_SPRING_CHAIN,
			SCHEMA_TYPE_BALL_SOCKET_CHAIN,
			SCHEMA_TYPE_POWERED_CHAIN,
			SCHEMA_TYPE_MAX
		};
		static __forceinline hkEnum<SchemaType, hkInt8> __cdecl getType( const hkpJacobianSchema* schema )
		{
			return *reinterpret_cast<const hkEnum<SchemaType, hkInt8>*>( schema );
		}
		static __forceinline void __cdecl setType( hkpJacobianSchema* schema, hkEnum<SchemaType, hkInt8> type )
		{
			*reinterpret_cast<hkReal*>( schema ) += 1.192092896e-07f;
			*reinterpret_cast<hkEnum<SchemaType, hkInt8>*>( schema ) = type;
		}
};
class hkpJacobianHeaderSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianHeaderSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void initHeader( hkpConstraintInstance* instance, const int bodyAIndex, const int bodyBIndex, hkpSolverResults* sr, const int solverResultStriding )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_HEADER );
			m_bodyAIndex = hkUint16( bodyAIndex );
			m_bodyBIndex = hkUint16( bodyBIndex );
			m_solverResultInMainMemory = sr;
			m_constraintInstance = instance;
			;
			;
			m_solverResultStriding = hkUint8( solverResultStriding );
		}
		hkUint8 m_padding0;
		hkUint8 m_solverResultStriding;
		hkUint16 m_padding1;
		hkUint16 m_bodyAIndex;
		hkUint16 m_bodyBIndex;
		hkpSolverResults* m_solverResultInMainMemory;
		hkpConstraintInstance* m_constraintInstance;
};
class hkpJacobianSingleContactSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianSingleContactSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void initSingleContact( const hkp1Lin2AngJacobian& jac, int typeAddon )
		{
			const int type = hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT + typeAddon;
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SchemaType( type ) );
		}
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobianPairContactSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianPairContactSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void initPairContact( const hkpJacDouble2Bil& jac, hkReal invJac01, int requestAccessorCheck )
		{
			;
			m_invJac01 = invJac01;
			const int type = hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT + requestAccessorCheck;
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SchemaType( type ) );
		}
		hkpJacDouble2Bil m_jac;
		hkReal m_invJac01;
		hkReal m_padding[3];
};
class hkpJacobian2dFrictionSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian2dFrictionSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void init2dFriction( const hkpJacDouble2Bil& jac, hkReal maxImpulse, hkReal invJac01, hkpSolverResults* sr )
		{
			m_invJac01 = invJac01;
			m_maxImpulse = maxImpulse;
			m_solverResults = sr;
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_2D_FRICTION );
		}
		hkpJacDouble2Bil m_jac;
		hkReal m_invJac01;
		hkReal m_maxImpulse;
		hkpSolverResults* m_solverResults;
		hkReal m_padding55;
};
class hkpJacobian3dFrictionSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian3dFrictionSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void init3dFriction( const hkpJacTriple2Bil1Ang& jac, hkReal maxImpulse, hkReal invJac01, hkReal contactRadius, hkpSolverResults* sr )
		{
			m_invJac01 = invJac01;
			m_maxImpulse = maxImpulse;
			m_contactRadius = contactRadius;
			m_solverResults = sr;
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_3D_FRICTION );
		}
		hkpJacTriple2Bil1Ang m_jac;
		hkReal m_invJac01;
		hkReal m_maxImpulse;
		hkReal m_contactRadius;
		hkpSolverResults* m_solverResults;
};
class hkSimpleContactConstraintDataInfoInternal
{
	public:
		hkUint16 m_flags;
		hkUint16 m_biNormalAxis;
		hkReal m_contactRadius;
		hkpSolverResults m_frictionResults[3];
};
__forceinline hkReal hkp1Lin2AngJacobian::getDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const
{
	const hkp1Lin2AngJacobian& jac = *this;
	;
	hkVector4 ang0; ang0.setMul4( jac.m_angular[0], jac.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jac.m_angular[1], jac.m_angular[1] );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	ang0.add4( ang1 );
	hkVector4 mass; mass.setAdd4( mA.m_invMasses, mB.m_invMasses );
	ang0.setW( mass );
	const hkReal dot = ang0.horizontalAdd4();
	return dot + 1.192092896e-07f;
}
__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const
{
	const hkp1Lin2AngJacobian& jacA = *this;
	hkVector4 lin; lin.setMul4( jacA.m_linear0, jacB.m_linear0 );
	hkVector4 ang0; ang0.setMul4( jacA.m_angular[0], jacB.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jacA.m_angular[1], jacB.m_angular[1] );
	hkVector4 massA; massA.setBroadcast3clobberW( mA.m_invMasses, 3 );
	hkVector4 massB; massB.setBroadcast3clobberW( mB.m_invMasses, 3 );
	hkVector4 linA; linA.setMul4( massA, lin );
	hkVector4 linB; linB.setMul4( massB, lin );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	linA.add4( linB );
	ang0.add4( ang1 );
	ang0.add4( linA );
	const hkReal result = ang0.horizontalAdd3();
	return result;
}
__forceinline hkReal hkp2AngJacobian::getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const
{
	const hkp2AngJacobian& jac = *this;
	hkVector4 ang0; ang0.setMul4( jac.m_angular[0], jac.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jac.m_angular[1], jac.m_angular[1] );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	ang0.add4( ang1 );
	const hkReal eps = 1.192092896e-07f;
	const hkReal dot = ang0.horizontalAdd3();
	return dot + eps;
}
namespace hkJacobianBuilder
{
__forceinline void __cdecl initBuilder( const hkpVelocityAccumulator* opaA, const hkpVelocityAccumulator* opaB, const hkReal rhsFactor )
	{
		hkVector4Util::reserveRegisters( 0x0fff0000 );
	}
__forceinline void __cdecl exitBuilder()
	{
		hkVector4Util::releaseRegisters( 0x0fff0000 );
	}
__forceinline void __cdecl copyJacRegToJac1Reg()
	{
	}
__forceinline void __cdecl buildLinearBegin( const hkpVelocityAccumulator* opaA, const hkpVelocityAccumulator* opaB, const hkVector4& position, const hkVector4& direction, hkReal invJacFactor, hkp1Lin2AngJacobian& jac )
	{
		jac.m_linear0 = direction;
		hkVector4 massCenterRelative0; massCenterRelative0.setSub4( position, opaA->getCenterOfMassInWorld() );
		hkVector4 massCenterRelative1; massCenterRelative1.setSub4( position, opaB->getCenterOfMassInWorld() );
		hkVector4 cross0; cross0.setCross( massCenterRelative0, direction );
		if ( opaA->m_matrixIsIdentity )
		{
			jac.m_angular[0] = cross0;
		}
		else
		{
			jac.m_angular[0]._setRotatedDir( opaA->getCoreFromWorldMatrix(), cross0 );
		}
		hkVector4 cross1; cross1.setCross( direction, massCenterRelative1 );
		if ( opaB->m_matrixIsIdentity )
		{
			jac.m_angular[1] = cross1;
		}
		else
		{
			jac.m_angular[1]._setRotatedDir( opaB->getCoreFromWorldMatrix(), cross1 );
		}
		hkReal a = jac.getDiag( *opaA, *opaB );
		jac.setUserValue( a );
		jac.setInvJacDiag( invJacFactor / a );
	}
// 2026-11-16: the two friction rows are built by this copy of buildLinearBegin, which writes the linear row lane by
// lane. The code is the same; with the contact row's operator= form here as well, info.m_contactRadius *= invNum
// (+0x1574) takes the other operand order. A guess at the source (a separate builder for the friction rows).
__forceinline void __cdecl buildLinearBeginFriction( const hkpVelocityAccumulator* opaA, const hkpVelocityAccumulator* opaB, const hkVector4& position, const hkVector4& direction, hkReal invJacFactor, hkp1Lin2AngJacobian& jac )
	{
		jac.m_linear0(0) = direction(0);
		jac.m_linear0(1) = direction(1);
		jac.m_linear0(2) = direction(2);
		jac.m_linear0(3) = direction(3);
		hkVector4 massCenterRelative0; massCenterRelative0.setSub4( position, opaA->getCenterOfMassInWorld() );
		hkVector4 massCenterRelative1; massCenterRelative1.setSub4( position, opaB->getCenterOfMassInWorld() );
		hkVector4 cross0; cross0.setCross( massCenterRelative0, direction );
		if ( opaA->m_matrixIsIdentity )
		{
			jac.m_angular[0] = cross0;
		}
		else
		{
			jac.m_angular[0]._setRotatedDir( opaA->getCoreFromWorldMatrix(), cross0 );
		}
		hkVector4 cross1; cross1.setCross( direction, massCenterRelative1 );
		if ( opaB->m_matrixIsIdentity )
		{
			jac.m_angular[1] = cross1;
		}
		else
		{
			jac.m_angular[1]._setRotatedDir( opaB->getCoreFromWorldMatrix(), cross1 );
		}
		hkReal a = jac.getDiag( *opaA, *opaB );
		jac.setUserValue( a );
		jac.setInvJacDiag( invJacFactor / a );
	}
__forceinline void __cdecl buildLinearEnd( hkp1Lin2AngJacobian& jac, hkReal rhs, hkReal rhsFactor )
	{
		jac.setRHS( rhs * rhsFactor );
	}
__forceinline void __cdecl buildAngularBegin( const hkpVelocityAccumulator* opaA, const hkpVelocityAccumulator* opaB, const hkVector4& direction, hkReal virtMassFactor, hkp2AngJacobian& jac )
	{
		hkVector4Util::reserveRegisters( 0xf0000000 );
		if ( opaA->m_matrixIsIdentity )
		{
			jac.m_angular[0] = direction;
		}
		else
		{
			jac.m_angular[0]._setRotatedDir( opaA->getCoreFromWorldMatrix(), direction );
		}
		if ( opaB->m_matrixIsIdentity )
		{
			jac.m_angular[1].setNeg4( direction );
		}
		else
		{
			hkVector4 negDir; negDir.setNeg4( direction );
			jac.m_angular[1]._setRotatedDir( opaB->getCoreFromWorldMatrix(), negDir );
		}
		hkReal diag = jac.getAngularDiag( *opaA, *opaB );
		jac.setInvJacDiag( virtMassFactor / diag );
	}
__forceinline void __cdecl mulInvJacDiag( hkp2AngJacobian* jac, hkReal f )
	{
		jac->setInvJacDiag( jac->m_angular[0](3) * f );
	}
__forceinline void __cdecl buildAngularEnd( hkp2AngJacobian& jac, hkReal rhs, hkReal rhsFactor )
	{
		jac.setAngularRhs( rhs * rhsFactor );
		hkVector4Util::releaseRegisters( 0xf0000000 );
	}
__forceinline hkReal __cdecl getInvJac01Optimized( const hkpVelocityAccumulator* opaA, const hkpVelocityAccumulator* opaB, hkp1Lin2AngJacobian* jac, hkReal virtMassFactor, hkReal nonDiagFactor )
	{
		hkReal nonDiag = jac[1].getNonDiagOptimized( *opaA, *opaB, jac[0] );
		hkReal a = jac[0].getUserValue();
		hkReal b = jac[1].getUserValue();
		nonDiag *= nonDiagFactor;
		const hkReal invDet = virtMassFactor / ( a * b - nonDiag * nonDiag );
		jac[0].setUserValue( b * invDet );
		jac[1].setUserValue( a * invDet );
		return -nonDiag * invDet;
	}
__forceinline void __cdecl addLastPosition( const hkVector4& pos, const hkVector4& dir, hkVector4& sumPos, hkVector4& sumDir )
	{
		sumPos.add4( pos );
		sumDir.add4( dir );
	}
}
static __forceinline hkReal __cdecl calculateRhs( const hkContactPoint* ccp, hkpContactPointProperties& sr, hkReal distance, hkReal dt, int& solverResultsModified )
{
	hkReal distanceOffset = sr.m_internalDataA;
	hkReal RHS = distance - distanceOffset;
	const hkReal estimatedRHS = -sr.m_internalSolverData;
	const hkReal secondOrderError = estimatedRHS - RHS;
	const hkReal maxDiff = dt * HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY;
	hkReal distanceOffsetRelaxation = hkMath::min2( distanceOffset * -HK_CONTACT_EXPONENTIAL_ERROR_RECOVERY_VELOCITY, maxDiff );
	distanceOffset += distanceOffsetRelaxation;
	RHS -= distanceOffsetRelaxation;
	if ( secondOrderError > distanceOffsetRelaxation * 2.0 + maxDiff )
	{
		distanceOffset -= secondOrderError;
		RHS += secondOrderError;
	}
	sr.m_internalDataA = hkMath::min2( distanceOffset, -1.192092896e-07f );
	return RHS;
}
void __cdecl FUN_00a00ec0( hkpSimpleContactConstraintAtom* atom, const hkpConstraintQueryIn& in, hkBool writeHeaderSchemas, hkpConstraintQueryOut& out )
{
	int modified = 0;
	const hkContactPoint* contacts = atom->getContactPoints();
	const int numContacts = atom->m_numContactPoints;
	hkpContactPointPropertiesStream* properties = atom->getContactPointPropertiesStream();
	int propertiesStriding = atom->getContactPointPropertiesStriding();
	hkpContactPointPropertiesStream* propertiesInMainMemory = properties;
	hkSimpleContactConstraintDataInfoInternal& info = *reinterpret_cast<hkSimpleContactConstraintDataInfoInternal*>( &atom->m_info );
	hkVector4 avgPosition; avgPosition.setZero4();
	hkVector4 avgNormal; avgNormal.setZero4();
	hkReal sumImpulse = 0.0f;
	hkReal invNum = 1.0f / numContacts;
	hkReal sumFriction = 0.0f;
	hkpJacobianSchema* com = out.m_jacobianSchemas;
	const hkpVelocityAccumulator* opaA = in.m_bodyA;
	const hkpVelocityAccumulator* opaB = in.m_bodyB;
	if ( writeHeaderSchemas )
	{
		hkpJacobianHeaderSchema* header = reinterpret_cast<hkpJacobianHeaderSchema*>( com );
		header->initHeader( in.m_constraintInstance, in.m_accumulatorAIndex, in.m_accumulatorBIndex, reinterpret_cast<hkpSolverResults*>( propertiesInMainMemory ), atom->getContactPointPropertiesStriding() );
		com = reinterpret_cast<hkpJacobianSchema*>( header + 1 );
	}
	hkJacobianBuilder::initBuilder( opaA, opaB, in.m_substepInvDeltaTime );
	{
		hkBool jac0Initialized = false;
		// 2026-11-16: HK_RESTRICT (__restrict) on the loop's contact cursor; it emits nothing. With it (and the plain
		// propertiesInMainMemory above, and the direct lane read in mulInvJacDiag) the x lanes of avgPosition/avgNormal
		// (+0x4f7, +0x52a) and jac2.invJacDiag * f (+0x17b4) take the original operand order. A guess at the source.
		const hkContactPoint* __restrict contact = contacts;
		hkpContactPointPropertiesStream* sr = properties;
		int srStriding = propertiesStriding;
		{
			int i = 0;
			do
			{
				const int contactUsesSolverPath2 = sr->asProperties()->m_flags & hkContactPointMaterial::CONTACT_USES_SOLVER_PATH2;
				// agent 2026-11-16: __restrict on the row pointer of the loop. It emits nothing; it lets the three byte loads
				// (opaA/opaB m_matrixIsIdentity, the friction byte) be scheduled above the float stores into the row, as the
				// original has them at +0xef, +0x22e and +0x3e0, while the tripleJac rows keep them behind. REWORK item.
				hkp1Lin2AngJacobian* __restrict jac1Lin2Ang = reinterpret_cast<hkp1Lin2AngJacobian*>( com );
				const int jacIdx = 0;
				hkJacobianBuilder::buildLinearBegin( opaA, opaB, contact->getPosition(), contact->getNormal(), in.m_virtMassFactor, *jac1Lin2Ang );
				sumFriction += sr->asProperties()->getFriction();
				// 2026-11-16: the impulse goes through a named local. It emits the same code; with the sum written
				// directly, the x87 operand order of dt * HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY in calculateRhs
				// (+0x441) comes out reversed. Goes with the unnamed squared length of biNormal2 below. A guess at the source.
				const hkReal impulse = sr->asProperties()->m_impulseApplied;
				sumImpulse += impulse;
				const hkReal rhs = -calculateRhs( contact, *sr->asProperties(), contact->getDistance(), in.m_frameDeltaTime, modified );
				hkJacobianBuilder::buildLinearEnd( *jac1Lin2Ang, rhs, in.m_rhsFactor );
				hkJacobianBuilder::addLastPosition( contact->getPosition(), contact->getNormal(), avgPosition, avgNormal );
				if ( !contactUsesSolverPath2 )
				{
					int maxImpulse = sr->asProperties()->m_maxImpulse.m_value;
					hkpJacobianSingleContactSchema* sc = reinterpret_cast<hkpJacobianSingleContactSchema*>( com );
					sc->initSingleContact( *jac1Lin2Ang,  0 );
					com = reinterpret_cast<hkpJacobianSchema*>( sc + 1 );
					jac0Initialized = true;
					if ( maxImpulse )
					{
						hkpContactPointPropertiesStream* sr_1 = hkAddByteOffset( sr, srStriding );
						int typeAddon =  2;
						sc->initSingleContact( *jac1Lin2Ang, typeAddon );
						jac1Lin2Ang->setUserValue( hkUFloat8_intToReal[maxImpulse] );
					}
				}
				else
				{
					hkpJacobianSingleContactSchema* single = reinterpret_cast<hkpJacobianSingleContactSchema*>( com );
					hkpJacobianPairContactSchema* sc = reinterpret_cast<hkpJacobianPairContactSchema*>( single - 1 );
					hkReal jacNonDiagFactor = 0.99f;
					const int jacIdx2 = 0;
					hkReal invJac01 = hkJacobianBuilder::getInvJac01Optimized( opaA, opaB, jac1Lin2Ang - 1, in.m_virtMassFactor, jacNonDiagFactor );
					sc->initPairContact( *reinterpret_cast<const hkpJacDouble2Bil*>( jac1Lin2Ang - 1 ), invJac01,  0 );
					com = reinterpret_cast<hkpJacobianSchema*>( sc + 1 );
					jac0Initialized = false;
				}
				sr = hkAddByteOffset( sr, srStriding );
				contact++;
			} while ( ++i < numContacts );
		}
	}
	hkVector4 biNormal;
	hkVector4 biNormal2;
	hkReal maxImp = sumImpulse * sumFriction * invNum;
	if ( maxImp > 0.0f )
	{
		{
			hkReal invNum2 = invNum * invNum;
			hkReal nl = avgNormal.lengthSquared3();
			if ( nl * invNum2 > 0.9999f )
			{
				avgNormal = contacts->getNormal();
			}
			else
			{
				if ( nl > 0.1f )
				{
					avgNormal.normalize3();
				}
				else
				{
					avgNormal = contacts->getNormal();
					nl = avgNormal.lengthSquared3();
					if ( nl < 0.9f )
					{
						maxImp = 0.0f;
						avgNormal.setZero4();
						avgNormal(1) = 1.0f;
					}
				}
			}
			biNormal = hkTransform::getIdentity().getColumn( info.m_biNormalAxis );
			biNormal2.setCross( biNormal, avgNormal );
			// 2026-11-16: the squared length is tested without a named local (same code). With the named impulse in the
			// contact loop this gives the original's temporary numbering: the x lanes of the position/normal sums
			// (+0x4f7, +0x52a), the contact radius scale (+0x1574) and the R6 rotation keep their order. A guess at the source.
			if ( biNormal2.lengthSquared3() > 0.1f )
			{
			}
			else
			{
				hkVector4 absNormal; absNormal.setAbs4( avgNormal );
				if ( absNormal(0) < absNormal(1) )
				{
					info.m_biNormalAxis = ( absNormal(0) < absNormal(2) ) ? hkUint16(0) : hkUint16(2);
				}
				else
				{
					info.m_biNormalAxis = ( absNormal(1) < absNormal(2) ) ? hkUint16(1) : hkUint16(2);
				}
				info.m_frictionResults[0].m_internalSolverData = 0.0f;
				info.m_frictionResults[1].m_internalSolverData = 0.0f;
				biNormal = hkTransform::getIdentity().getColumn( info.m_biNormalAxis );
				biNormal2.setCross( biNormal, avgNormal );
			}
			biNormal2.normalize3();
			biNormal.setCross( avgNormal, biNormal2 );
		}
		avgPosition.mul4( invNum );
		hkpJacTriple2Bil1Ang& tripleJac = *reinterpret_cast<hkpJacTriple2Bil1Ang*>( com );
		{
			hkJacobianBuilder::buildLinearBeginFriction( opaA, opaB, avgPosition, biNormal, in.m_virtMassFactor, tripleJac.m_jac0 );
			hkReal rhs = info.m_frictionResults[0].m_internalSolverData;
			hkJacobianBuilder::buildLinearEnd( tripleJac.m_jac0, rhs, in.m_frictionRhsFactor );
		}
		hkJacobianBuilder::copyJacRegToJac1Reg();
		{
			hkJacobianBuilder::buildLinearBeginFriction( opaA, opaB, avgPosition, biNormal2, in.m_virtMassFactor, tripleJac.m_jac1 );
			hkReal rhs = info.m_frictionResults[1].m_internalSolverData;
			hkJacobianBuilder::buildLinearEnd( tripleJac.m_jac1, rhs, in.m_frictionRhsFactor );
		}
		hkpJacobian2dFrictionSchema* frictionSchema = reinterpret_cast<hkpJacobian2dFrictionSchema*>( com );
		hkReal invJac01 = hkJacobianBuilder::getInvJac01Optimized( opaA, opaB, &tripleJac.m_jac0, in.m_virtMassFactor, 1.0f );
		hkReal corrMaxImpulse = maxImp * in.m_invNumStepsTimesMicroSteps;
		hkpSolverResults* solverResults = &info.m_frictionResults[0];
		frictionSchema->init2dFriction( reinterpret_cast<const hkpJacDouble2Bil&>( tripleJac ), corrMaxImpulse, invJac01, solverResults );
		com = reinterpret_cast<hkpJacobianSchema*>( frictionSchema + 1 );
		if ( numContacts > 1 )
		{
			while ( true )
			{
				if ( ( info.m_flags & hkpSimpleContactConstraintDataInfo::HK_FLAG_AREA_CHANGED ) == 0 )
				{
					const hkReal f = 1.0f / info.m_contactRadius;
					hkJacobianBuilder::buildAngularBegin( opaA, opaB, avgNormal, in.m_virtMassFactor, tripleJac.m_jac2 );
					hkJacobianBuilder::buildAngularEnd( tripleJac.m_jac2, info.m_frictionResults[2].m_internalSolverData, in.m_frictionRhsFactor );
					hkJacobianBuilder::mulInvJacDiag( &tripleJac.m_jac2, f );
					hkpJacobian3dFrictionSchema* sc = reinterpret_cast<hkpJacobian3dFrictionSchema*>( frictionSchema );
					sc->init3dFriction( tripleJac, corrMaxImpulse, invJac01, info.m_contactRadius, solverResults );
					com = reinterpret_cast<hkpJacobianSchema*>( sc + 1 );
					break;
				}
				info.m_contactRadius = 0.0f;
				{
					const hkContactPoint* cp = contacts;
					for ( int j = numContacts - 1; j >= 0; j-- )
					{
						hkVector4 diff; diff.setSub4( cp->getPosition(), avgPosition );
						info.m_contactRadius = diff.length3() + info.m_contactRadius;
						cp++;
					}
				}
				info.m_contactRadius *= invNum;
				if ( info.m_contactRadius < 1e-6f )
				{
					break;
				}
				info.m_flags &= ~hkpSimpleContactConstraintDataInfo::HK_FLAG_AREA_CHANGED;
			}
		}
	}
	out.m_jacobianSchemas = com;
	hkJacobianBuilder::exitBuilder();
}

}  // namespace f3m_00a00ec0


}   // namespace f3m_00a00ec0
