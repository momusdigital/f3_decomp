#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_004e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004fecc0 (community match, verified in this file)
namespace f3m_004fecc0 {

namespace f3m_004fecc0 {
class RefObject
{
public:
    virtual ~RefObject();
    virtual void DeleteThis();
    long refCount;
    void IncRef() { InterlockedIncrement(&refCount); }
    void DecRef() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
};

template <class T> class RefPtr
{
public:
    T* object;
    RefPtr& operator=(const RefPtr& other)
    {
        if (object != other.object)
        {
            if (object)
                object->DecRef();
            object = other.object;
            if (object)
                object->IncRef();
        }
        return *this;
    }
};

class Owner
{
public:
    char unk000[0x17c];
    RefPtr<RefObject> current;
    void FUN_004fecc0(RefPtr<RefObject>& out);
};

void Owner::FUN_004fecc0(RefPtr<RefObject>& out)
{
    out = current;
}
}
}   // namespace f3m_004fecc0

// @f3 0x004f18c0 (community match, verified in this file)
extern int DAT_00f4a768;
namespace f3m_004f18c0 {
// FUN_004f18c0: thiscall (Out* out, Req* req). Writes a 0x14-byte result, switch on req->kind.


struct Out4f18 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct Req4f18 {
    int unk00;
    int unk04;
    int unk08;   // compared with target->unk0c / FUN_004d4c00 result
    int unk0c;   // kind, switch 1..6
};

struct Target4f18 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool FUN_004e6b10();
    int FUN_004d4c00();
};

struct Sub4f18 {
    virtual Target4f18* Get();
};

struct FUN_004f18c0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Sub4f18 unk18;
    bool FUN_004eb8f0();
    void FUN_004f18c0(Out4f18* out, Req4f18* req);
};

// pdb: TESObjectREFR::CreateGroupData | TESObjectREFR.obj | fnv360_0822_retail, vtable, medium
// pdb params: apOutGroupFORM, apParentGroup
void FUN_004f18c0_cls::FUN_004f18c0(Out4f18* out, Req4f18* req)
{
    if (out == 0)
        return;
    out->unk00 = 0;
    if (req == 0)
        return;
    Sub4f18* sub = &unk18;
    Target4f18* t = sub->Get();
    int ebp = t->unk0c;
    bool flag = false;
    switch (req->unk0c) {
    case 1:
        if (t->FUN_004e6b10())
            flag = true;
        // fall through
    case 3:
    case 5:
        if (req->unk08 == t->FUN_004d4c00() || flag) {
            out->unk00 = DAT_00f4a768;
            out->unk08 = ebp;
            out->unk0c = 6;
            out->unk04 = 0;
            out->unk10 = 0;
        }
        break;
    case 6:
        if (req->unk08 == ebp) {
            out->unk00 = DAT_00f4a768;
            bool r = FUN_004eb8f0();
            out->unk08 = ebp;
            out->unk0c = r ? 8 : 9;
            out->unk04 = 0;
            out->unk10 = 0;
        }
        break;
    default:
        break;
    }
}
}   // namespace f3m_004f18c0

// @f3 0x004e7690 (community match, verified in this file)
namespace f3m_004e7690 {
struct Owner1131;
struct Holder1131 { Owner1131* FUN_004237e0(); };
struct Extra1131 { int head00; void* BaseExtraList_GetExtraData(int kind); Holder1131* FUN_0040aac0(); };
struct Owner1131 {
    int unk000;
    int unk004;
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
    Extra1131 extra40;
    void* FUN_004e7690();
};
// pdb: TESObjectREFR::GetExtraLock | TESObjectREFR.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: ExtraLock::UnLockDoor)
void* Owner1131::FUN_004e7690() {
    Extra1131* extra = &extra40;
    void* result = extra->BaseExtraList_GetExtraData(0x2a);
    if (!result) {
        Holder1131* holder = extra->FUN_0040aac0();
        if (holder && holder->FUN_004237e0()) {
            Owner1131* parent = holder->FUN_004237e0();
            result = parent->FUN_004e7690();
        }
    }
    return result;
}
}   // namespace f3m_004e7690

// @f3 0x004e2320 (community match, verified in this file)
namespace f3m_004e2320 {


namespace f3m_004e2320 {
class RefObject {
public:
    virtual void Slot00();
    virtual void DeleteThis();
    LONG refCount;

    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
};

struct RefPointer
{
    RefObject* object;

    RefPointer& operator=(RefObject* other)
    {
        if (object != other) {
            if (object)
                object->DecRefCount();
            object = other;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
};

struct Vector3
{
    float x;
    float y;
    float z;
};

extern Vector3 DAT_0108ec68;
extern int DAT_0107152c;
extern RefPointer DAT_01071564;
extern float DAT_00f4faa8;

RefObject* __cdecl FUN_004e1e00(Vector3* position);

// pdb: TESObjectCELL::InitStatics | TESObjectCELL.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void __cdecl FUN_004e2320()
{
    Vector3 position = DAT_0108ec68;
    DAT_0107152c = 0;
    DAT_01071564 = FUN_004e1e00(&position);
    if (DAT_00f4faa8 > 2048.0f)
        DAT_00f4faa8 = 2048.0f;
}
}
}   // namespace f3m_004e2320

// @f3 0x004f85a0 (community match, verified in this file)
#include <windows.h>
#include <math.h>
extern void* DAT_01071564;
extern DWORD DAT_010f3170;
extern const double DAT_00dbe7c0;
extern const float DAT_00f7ad9c;
namespace f3m_004f85a0 {
struct Vec3 { float x,y,z; };
struct __declspec(align(16)) Vec4 { float x,y,z,w; Vec4& operator=(const Vec4& a) { x=a.x;y=a.y;z=a.z;w=a.w;return *this; } };
struct Matrix3 { Vec3 a,b,c; };
struct __declspec(align(16)) Quaternion { float w,x,y,z; void FUN_00837260(const void*); };
struct Update { float time; bool a,b,c,d,e; Update():time(0),a(false),b(false),c(false),d(false),e(false){} };
struct Scene {
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
 float scale;
 void FUN_008264c0(Update&);
 bool FUN_00824920(void*);
};
struct Bounds { int a,b,c,d,e,f; Vec3 extent; };
struct BoundsRef { Bounds* FUN_0040cdd0(); };
struct WorldRef { void* FUN_00410f00(); };
struct Cell {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 unsigned char flags; unsigned char b25,b26,b27; WorldRef world;
};
struct Allocator;
extern Allocator* (__stdcall* DAT_00d9b080)(DWORD);
struct Allocator { void* FUN_008f6d30(unsigned,int); void FUN_008f6d90(void*,unsigned,int); };
struct HkBase {
 void* vtable; unsigned short size,refs; int unk08,kind;
 static void* operator new(unsigned n) { Allocator* a=(Allocator*)TlsGetValue(DAT_010f3170); HkBase* p=(HkBase*)a->FUN_008f6d30(n,39); p->size=(unsigned short)n; return p; }
 static void operator delete(void* p) { ((Allocator*)TlsGetValue(DAT_010f3170))->FUN_008f6d90(p,((HkBase*)p)->size,39); }
};
struct FUN_00916750 : HkBase { float radius,unk14,unk18,unk1c; Vec4 extents; FUN_00916750(const Vec4&,float); };
struct Aux : HkBase { Aux() { refs=1; unk08=0; kind=29; vtable=&DAT_00dce610; } static char DAT_00dce610; };
struct FUN_00915f80 : HkBase { HkBase* child; void* iface; HkBase* aux; FUN_00915f80(HkBase*,HkBase*); };
struct FUN_00900d70 {
 int filter; HkBase* shape; unsigned char a,b,c,d; void* data; int count,capacity;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 Vec4 position; Vec4 rotation;
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
 unsigned char motion,quality,flags,other; int unkd4,unkd8,unkdc;
 FUN_00900d70();
 ~FUN_00900d70() { if(!(capacity & 0x80000000)) { int n=capacity&0x3fffffff; Allocator* a=(Allocator*)TlsGetValue(DAT_010f3170); a->FUN_008f6d90(data,n*8,23); } }
};
void* FUN_0089eb90(unsigned);
struct NiAlloc { static void* operator new(unsigned n) { return FUN_0089eb90(n); } static void operator delete(void*); };
struct FUN_004f06c0 : NiAlloc { 
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
 virtual void AddWorld(void*);
 int a,b,c,d,e,f;
 FUN_004f06c0(FUN_00900d70&); void FUN_008f9c30(Scene*,int);
};
struct FUN_008d9fd0 : NiAlloc { void* vtable; int a,b,c,d; FUN_008d9fd0(Scene*); };
struct Collision : FUN_008d9fd0 { Collision(Scene* s):FUN_008d9fd0(s) { vtable=&DAT_00dce0cc; } static char DAT_00dce0cc; void FUN_008da000(FUN_004f06c0*); };
struct FUN_00aa5fa0 : NiAlloc { int a,b,c,flags; FUN_00aa5fa0(); };
struct Target {
 virtual void v000();
 virtual void v004();
 virtual void v008();
 virtual void v00c();
 virtual void v010();
 virtual void v014();
 virtual void v018();
 virtual void v01c();
 virtual void v020();
 virtual void v024();
 virtual void v028();
 virtual void v02c();
 virtual void v030();
 virtual void v034();
 virtual void v038();
 virtual void v03c();
 virtual void v040();
 virtual void v044();
 virtual void v048();
 virtual void v04c();
 virtual void v050();
 virtual void v054();
 virtual void v058();
 virtual void v05c();
 virtual void v060();
 virtual void v064();
 virtual void v068();
 virtual void v06c();
 virtual void v070();
 virtual void v074();
 virtual void v078();
 virtual void v07c();
 virtual void v080();
 virtual void v084();
 virtual void v088();
 virtual void v08c();
 virtual void v090();
 virtual void v094();
 virtual void v098();
 virtual void v09c();
 virtual void v0a0();
 virtual void v0a4();
 virtual void v0a8();
 virtual void v0ac();
 virtual void v0b0();
 virtual void v0b4();
 virtual void v0b8();
 virtual void v0bc();
 virtual void v0c0();
 virtual void v0c4();
 virtual void v0c8();
 virtual void v0cc();
 virtual void v0d0();
 virtual void v0d4();
 virtual void v0d8();
 virtual void v0dc();
 virtual void v0e0();
 virtual void v0e4();
 virtual void v0e8();
 virtual void v0ec();
 virtual void v0f0();
 virtual void v0f4();
 virtual void v0f8();
 virtual void v0fc();
 virtual void v100();
 virtual void v104();
 virtual void v108();
 virtual void v10c();
 virtual void v110();
 virtual void v114();
 virtual void v118();
 virtual void v11c();
 virtual void v120();
 virtual void v124();
 virtual void v128();
 virtual void v12c();
 virtual void v130();
 virtual void v134();
 virtual void v138();
 virtual void v13c();
 virtual void v140();
 virtual void v144();
 virtual void v148();
 virtual void v14c();
 virtual void v150();
 virtual void v154();
 virtual void v158();
 virtual void v15c();
 virtual void v160();
 virtual void v164();
 virtual void v168();
 virtual void v16c();
 virtual void v170();
 virtual void v174();
 virtual void v178();
 virtual void v17c();
 virtual void v180();
 virtual void v184();
 virtual void v188();
 virtual void v18c();
 virtual void v190();
 virtual void v194();
 virtual void v198();
 virtual void v19c();
 virtual void v1a0();
 virtual void v1a4();
 virtual void v1a8();
 virtual void v1ac();
 virtual void v1b0();
 virtual void v1b4();
 virtual void v1b8();
 virtual void v1bc();
 virtual void v1c0();
 virtual void v1c4();
 virtual void v1c8();
 virtual void v1cc();
 virtual Scene* GetScene();
 virtual void v1d4();
 virtual void v1d8();
 virtual void v1dc();
 virtual void v1e0();
 virtual void v1e4();
 virtual void v1e8();
 virtual void v1ec();
 virtual void v1f0();
 virtual Vec3* GetPosition();
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
 Cell* cell; BoundsRef bounds;
 void TESObjectREFR_SetScale(float);
 Matrix3 FUN_004e7c10();
 void FUN_004f85a0();
};
// pdb: TESObjectREFR::InitHavokForAcousticSpace | TESObjectREFR.obj | fnv360_0822_retail, uvref, medium
void Target::FUN_004f85a0() {
 Bounds* bound=bounds.FUN_0040cdd0();
 if(!cell) return;
 void* world=(cell->flags&1)?cell->world.FUN_00410f00():DAT_01071564;
 if(!world) return;
 TESObjectREFR_SetScale(1.0f);
 Scene* node=GetScene();
 node->scale=(float)fabs(1.0f);
 Update update;
 GetScene()->FUN_008264c0(update);
 Matrix3 transform=FUN_004e7c10();
 GetPosition();
 Vec3 ext=bound->extent;
 Vec4 half;
 half.x=(float)(ext.x*DAT_00dbe7c0);
 half.y=(float)(ext.y*DAT_00dbe7c0);
 half.z=(float)(ext.z*DAT_00dbe7c0);
 FUN_00916750* box=new FUN_00916750(half,DAT_00f7ad9c);
 Aux* aux=new Aux;
 FUN_00915f80* shape=new FUN_00915f80(box,aux);
 FUN_00900d70 info;
 info.shape=shape;
 info.motion=7;
 Quaternion q;
 q.FUN_00837260((char*)GetScene()+0x34);
 Vec3* pos=GetPosition();
 Vec4 position;
 position.x=(float)(pos->x*DAT_00dbe7c0);
 position.y=(float)(pos->y*DAT_00dbe7c0);
 position.z=(float)(pos->z*DAT_00dbe7c0);
 info.filter=0x50015;
 info.position=position;
 info.rotation.x=q.x; info.rotation.y=q.y; info.rotation.z=q.z; info.rotation.w=q.w;
 FUN_004f06c0* body=new FUN_004f06c0(info);
 Collision* coll=new Collision(GetScene());
 FUN_00aa5fa0* extra=new FUN_00aa5fa0;
 extra->flags|=2;
 GetScene()->FUN_00824920(extra);
 coll->FUN_008da000(body);
 body->FUN_008f9c30(GetScene(),0);
 if(body) body->AddWorld(world);
}
}   // namespace f3m_004f85a0
