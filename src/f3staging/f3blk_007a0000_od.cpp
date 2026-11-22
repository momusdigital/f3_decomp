#include <math.h>
#include <windows.h>
// src/f3staging/f3blk_007a0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007a6880 (community match, verified in this file)
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void* __cdecl _alloca(unsigned);
struct Vec { float x,y,z; Vec() {} Vec(float a,float b,float c):x(a),y(b),z(c) {} Vec operator-(const Vec& b) const { return Vec(x-b.x,y-b.y,z-b.z); } float SquaredLength() const { return x*x+y*y+z*z; } Vec& operator=(const Vec& b) { memcpy(this,&b,12);return *this; } };
extern Vec DAT_011f426c;
struct Object {
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
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
virtual void slot99();
virtual void slot100();
virtual void slot101();
virtual void slot102();
virtual void slot103();
virtual void slot104();
virtual void slot105();
virtual void slot106();
virtual void slot107();
virtual void slot108();
virtual void slot109();
virtual void slot110();
virtual void slot111();
virtual void slot112();
virtual void slot113();
virtual void slot114();
virtual void slot115();
virtual void slot116();
virtual void slot117();
virtual void slot118();
virtual void slot119();
virtual void slot120();
virtual void slot121();
virtual void slot122();
virtual void slot123();
virtual void slot124();
virtual const Vec& Position();
};
struct Entry { Object* object; unsigned data; const Vec& GetPosition() { return object->Position(); } };
class Owner {
public:
unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
Entry* entries;
unsigned count;
void FUN_007a6880();
};
// pdb: CombatGroupData::SortRangedMembers | CombatGroupStrategy.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_007a6880() {
unsigned n=count;
Vec* points=(Vec*)_alloca(n*sizeof(Vec));
Vec center=DAT_011f426c;
for(unsigned i=0;i<n;i++) {
points[i]=entries[i].GetPosition();
center.x+=points[i].x; center.y+=points[i].y; center.z+=points[i].z;
}
float reciprocal=1.0f/n;
center.x*=reciprocal;center.y*=reciprocal;center.z*=reciprocal;
float* distances=(float*)_alloca(n*sizeof(float));
for(unsigned i=0;i<n;i++) {
Vec delta=points[i]-center;
distances[i]=delta.SquaredLength();
}
for(unsigned i=0;i<n-1;i++) {
float best=distances[i];unsigned k=i;
for(unsigned j=i+1;j<n;j++) {
if(best>distances[j]) {best=distances[j];k=j;}
}
if(i!=k) {
float temp=distances[i];distances[i]=distances[k];distances[k]=temp;
Entry item=entries[i];entries[i]=entries[k];entries[k]=item;
}
}
}

// @f3 0x007be880 (community match, verified in this file)
namespace ExplosionScene {
inline float Abs(float x) {return (float)fabs((double)x);}
struct Point { float x,y,z; Point() {} Point(float a,float b,float c):x(a),y(b),z(c) {} float Len() { float f=x*x+y*y+z*z;return (float)sqrt((double)f); } };
struct Local70 { float m[3][3]; Local70() {} void Ctor6815c0() {} void FUN_00823a50(float,float,float); };
struct Upd { float time; bool a,b,c,d,e; Upd() {} void Ctor(float t,int,int) {time=t;a=false;b=false;c=false;d=false;e=false;} };
struct Obj; struct Ctrl; struct Seq;
struct RTTI { const char* name; RTTI* parent; };
struct Chain {
virtual void v00(); virtual void v04(); virtual void v08(); virtual Chain* V0c(); virtual void* V10();
};
struct VBase {
virtual void v00();
virtual void v04();
virtual void v08();
virtual Chain* V0c();
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
virtual void v9c();
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
virtual void Vd0(Obj*,int,int,int,int);
virtual void vd4();
virtual void Vd8(Obj*,int);
virtual void Vdc(void*,int);
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void vec();
virtual void vf0();
virtual void vf4();
virtual void vf8();
virtual void vfc();
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
virtual const char* V130();
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
virtual void GenerateNiNode(bool);
virtual void v1cc();
virtual Obj* GetNiNode();
virtual void v1d4();
virtual void v1d8();
virtual void v1dc();
virtual void v1e0();
virtual void v1e4();
virtual void v1e8();
virtual void v1ec();
virtual void v1f0();
virtual Point* GetPos() const;
};
struct Obj : VBase {
unsigned unk04;
unsigned unk08;
Ctrl* controller;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned short unk1c;
bool unk1e;
bool unk1f;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
Local70 rotation;
Point position;
float scale;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
unsigned unk74;
unsigned unk78;
unsigned unk7c;
unsigned unk80;
unsigned unk84;
unsigned unk88;
unsigned unk8c;
unsigned unk90;
unsigned unk94;
unsigned unk98;
unsigned unk9c;
Obj** children; unsigned short capacity,count;
void FUN_00440490(float x) { scale=(float)fabs(x); }
void FUN_00440460(Point* p) { position=*p; }
void FUN_0043fa80(Local70* p) { rotation=*p; }
void FUN_004bc1f0(float x,float y,float z) { position=Point(x,y,z); }
void FUN_008264c0(Upd*);
void* FUN_00824a50(const void*);
Ctrl* FUN_0043b230() {return controller;}
unsigned short FUN_0045bc00(int) {return count;}
Obj* FUN_0043b4a0(unsigned short i) {if(i>=count)return 0;return children[i];}
bool FUN_004bae00() {return unk1e;}
};
struct BSFadeNode { void SetRange(float,float); };
struct Extra { unsigned unk00,unk04,unk08,flags; void FUN_00519230(int f,int) {flags|=f;} };
extern const char DAT_00db3438[];
struct Proj : VBase {
unsigned unk04;
unsigned unk08;
unsigned formID;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
const char* editorName;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
unsigned unk60;
unsigned unk64;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
float gridPosition;
int TESForm_GetFormEditorIDLength();
const char* Name() { const char* p=editorName; return p?p:DAT_00db3438; }
unsigned ID() {return unk0c();}
unsigned unk0c() {return formID;}
void SetGridPosition(float f) {gridPosition=f;}
};
extern const char DAT_00db3438[];
struct WorldHandle { Obj* FUN_00410f00(); };
extern Obj* DAT_01071564;
struct Cell { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,flags; WorldHandle world;
Obj* FUN_004543c0() { return (flags&1)?world.FUN_00410f00():DAT_01071564; }
};
extern int DAT_00f707e0;
struct SettingColl { int* Int() {return &DAT_00f707e0;} };
SettingColl setting;
extern const char DAT_00e1bbc4[],DAT_00e1bb88[];
extern void* DAT_0116d6e0;
extern const float DAT_00e1b70c;
extern float DAT_00f70870,DAT_00f7086c,DAT_00f70868,DAT_00f70864,DAT_00f70860,DAT_00f7085c;
Obj* FUN_00aab350(Obj*,const char*,int);
void __cdecl FUN_00887da0(const char*,...);
struct FixedStr {void* p;};
inline FixedStr& Fixed() {return *(FixedStr*)DAT_0116d6e0;}
struct TObj : Obj {Point* FUN_0043c490() {return &position;} };
struct Deletable { virtual void Destroy(bool); };
struct CopyMaps {Deletable* a; Deletable* b; unsigned c,d; CopyMaps(unsigned n); ~CopyMaps() {if(a)a->Destroy(true);if(b)b->Destroy(true);} };
struct FloatConfiguredObject { CopyMaps maps; Point scale; FloatConfiguredObject(float f):maps(0x101) {scale.z=f;scale.y=f;scale.x=f;} };
void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ed40(void*);
struct BigObj : Obj { static void* operator new(unsigned n) {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089ed40(p);} unsigned unka8; BigObj(int); };
struct Rnd { unsigned FUN_0086c4b0(int); float F() {unsigned r=FUN_0086c4b0(-1);return (float)r*4.656612873077393e-10-1.0;} };
Rnd* FUN_0044a2d0();
struct InitBase {unsigned* vtable;unsigned unk04,unk08,unk0c,unk10; InitBase(void*);};
extern unsigned DAT_00dce0cc[];
struct InitObj:InitBase {static void* operator new(unsigned n) {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089ed40(p);} InitObj(void* p):InitBase(p) {vtable=DAT_00dce0cc;} void FUN_008da000(void*);};
struct Sphere {unsigned unk00,unk04;void* shape;unsigned unk0c,unk10;static void* operator new(unsigned n) {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089ed40(p);} Sphere(float,bool);void* GetShape(){return shape;}};
extern unsigned DAT_00f79e58;
inline unsigned Filter(int layer,void*,int) {unsigned x=(DAT_00f79e58+1)&0xffff;DAT_00f79e58=x;if(!x)DAT_00f79e58=x=10;return (x<<16)|layer;}
struct Temp622 {unsigned value; Temp622* Ctor(int a,void* b,int c) {value=Filter(a,b,c);return this;} void* FUN_00559450() {return (void*)value;} };
inline void* FUN_005dbe10() {return 0;}
extern unsigned DAT_010f3170;
struct Memory {void FUN_008f6d90(void*,unsigned,int);};
struct Big {
unsigned filter;void* material;unsigned unk08; void* data;int size,capacity; unsigned unk18,unk1c;
unsigned filter2;void* material2;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
unsigned unk60;
unsigned unk64;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
unsigned unk74;
unsigned unk78;
unsigned unk7c;
unsigned unk80;
unsigned unk84;
unsigned unk88;
unsigned unk8c;
unsigned unk90;
unsigned unk94;
unsigned unk98;
unsigned unk9c;
unsigned unka0;
unsigned unka4;
unsigned unka8;
unsigned unkac;
float mass; unsigned unkb4,unkb8;float factor,zero;unsigned unkc4,unkc8,unkcc;unsigned char motion; unsigned char unkd1,unkd2,unkd3;
Big();
void FUN_00507610(float x) {mass=x;}
void FUN_006e4340(float x) {zero=x;}
void FUN_0056d360(unsigned char x) {motion=x;}
void FUN_005076c0(float x) {factor=x;}
void FUN_0056f0f0(void* x) {filter=(unsigned)x;filter2=(unsigned)x;}
void FUN_0056f110(Sphere* p) {void* x=p?p->GetShape():0;material=x;material2=x;}
~Big() {if(((unsigned)capacity&0x80000000)==0) {int n=capacity&0x3fffffff;Memory* m=(Memory*)TlsGetValue(DAT_010f3170);m->FUN_008f6d90(data,n*8,0x17);}}
};
struct Body {unsigned unk00,unk04;void* body;unsigned unk0c,unk10,unk14,unk18;static void* operator new(unsigned n) {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089ed40(p);} Body(Big*);void* FUN_004ae750(){return this?body:0;}void FUN_00900ad0(void*);};
struct Acc { static void* operator new(unsigned n) {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089ed40(p);}
unsigned unk00;
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
unsigned unk60;
unsigned unk64;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
unsigned unk74;
unsigned unk78;
unsigned unk7c;
unsigned unk80;
unsigned unk84;
unsigned unk88;
unsigned unk8c;
unsigned unk90;
unsigned unk94;
unsigned unk98;
unsigned unk9c;
unsigned unka0;
unsigned unka4;
unsigned unka8;
unsigned unkac;
unsigned unkb0;
unsigned unkb4;
Acc();void FUN_005468d0(int x) {unkb0=x;}
};
struct S1fc {unsigned unk00;void* m04;float fa,fb,fc,fd;void Ctor() {unk00=0;}};
struct Liquid {static void* operator new(unsigned n) {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089ed40(p);}
unsigned unk00;
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
Liquid(S1fc*);
};
void bhkWorld_UpdatePosition(Obj*,int,int);
bool FUN_004e8d80(void*);void FUN_004ef0a0(void*);void PrepareObjectWithNoLightingRecurse(Obj*);void FUN_00837ec0(Obj*);
extern RTTI DAT_01091f04;
struct Map {__declspec(noalias) bool FUN_00bea7b0(void*,Seq*&);};
extern FixedStr** DAT_0106e7e4;
inline FixedStr* FUN_005c1490() {return *DAT_0106e7e4;}
struct Ctrl {virtual void v00(); virtual void v04();virtual RTTI* GetRTTI(); unsigned unk04;unsigned short flags;unsigned short unka;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
Ctrl* next;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
Map sequences;
Ctrl* GetNext() {return next;}
Seq* FUN_0047a520(FixedStr* a) {Seq* s;if(sequences.FUN_00bea7b0(a,s))return s;return 0;}
void NiControllerManager_DeactivateAll(float);
void FUN_0047aa40(int f) {flags|=8;}
};
inline bool IsKind(RTTI* type,Ctrl* p) {RTTI* r=p->GetRTTI();while(r) {if(r==type)return true;r=r->parent;}return false;}
struct Seq {
unsigned unk00;
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
float end;unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
float time;
bool FUN_008aecd0(int,int,float,float,int,int);
void Free() {time=-3.4028234663852886e+38f;}
float FUN_00508100() {return end;}
};
inline void Start(Ctrl*,Seq* seq,int a,int b,float c,float d,int e) {seq->FUN_008aecd0(a,b,c,d,e,0);}
class Explosion : public VBase {
public:
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
Proj* baseForm;
Point angles;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
Cell* parentCell;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
unsigned unk60;
unsigned unk64;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
unsigned unk74;
unsigned unk78;
unsigned unk7c;
unsigned unk80;
float lifetime;
unsigned unk88;
float radius;
Proj* FUN_004181e0(){return baseForm;}
Point* FUN_00430830(){return &angles;}
Cell* FUN_008d6f30(){return parentCell;}
bool IsNotCulled(){return FUN_008d6f30()==0;}
float FUN_00644930(){return radius;}
float FUN_00507e10(){return lifetime;}
void FUN_00810550(float x){lifetime=x;}
void FUN_007be880();
};
FNV_STATIC_ASSERT(offsetof(Explosion, baseForm) == 0x1c);
FNV_STATIC_ASSERT(offsetof(Explosion, angles) == 0x20);
FNV_STATIC_ASSERT(offsetof(Explosion, parentCell) == 0x3c);
FNV_STATIC_ASSERT(offsetof(Explosion, lifetime) == 0x84);
FNV_STATIC_ASSERT(offsetof(Explosion, radius) == 0x8c);
FNV_STATIC_ASSERT(offsetof(Proj, formID) == 0x0c);
FNV_STATIC_ASSERT(offsetof(Proj, editorName) == 0x34);
FNV_STATIC_ASSERT(offsetof(Proj, gridPosition) == 0x74);
FNV_STATIC_ASSERT(offsetof(Obj, unk1e) == 0x1e);
FNV_STATIC_ASSERT(offsetof(Obj, children) == 0xa0);
// pdb: Explosion::Init3D | Explosion.obj | fnv360_0822_retail, ustr, medium
void Explosion::FUN_007be880()
{
    GenerateNiNode(false);
    Obj* obj = (Obj*)GetNiNode();
    if (obj)
    {
        float scale = 1.0f;
        if (IsNotCulled())
        {
            Chain* node = obj->V0c();
            BSFadeNode* fade = node ? (BSFadeNode*)((Chain*)node)->V10() : 0;
            if (fade)
                fade->SetRange(DAT_00e1b70c, DAT_00e1b70c);
        }
        if (*setting.Int() == 0)
        {
            TObj* named = (TObj*)FUN_00aab350(obj, DAT_00e1bbc4, 1);
            if (named)
            {
                scale = FUN_00644930() / named->FUN_0043c490()->Len();
            }
            else
            {
                const char* name;
                if (FUN_004181e0()->TESForm_GetFormEditorIDLength())
                {
                    VBase* base = (VBase*)FUN_004181e0();
                    name = (const char*)base->V130();
                }
                else
                    name = FUN_004181e0()->Name();
                FUN_00887da0(DAT_00e1bb88, FUN_004181e0()->ID(), name);
                scale = 1.0f;
            }
        }
        obj->FUN_00440490(scale);
        obj->FUN_00440460(static_cast<const Explosion*>(this)->GetPos());
        Point angles = *FUN_00430830();
        Local70 rotation;
        rotation.Ctor6815c0();
        rotation.FUN_00823a50(angles.z, angles.y, angles.x);
        obj->FUN_0043fa80(&rotation);
        if (*setting.Int() > 1)
        {
            ((Proj*)FUN_004181e0())->SetGridPosition(DAT_00f70870);
            FUN_00810550(DAT_00f7086c);
            Point position = *static_cast<const Explosion*>(this)->GetPos();
            void* extra = obj->FUN_00824a50(&Fixed());
            if (extra)
            {
                Extra* flags = (Extra*)extra;
                flags->FUN_00519230(0x10, 1);
            }
            for (int i = 0; obj && i < *setting.Int(); ++i)
            {
                FloatConfiguredObject guard(1.0f);
                BigObj* node = new BigObj(0);
                node->FUN_004bc1f0((float)(((Rnd*)FUN_0044a2d0())->F() * 10.0),
                                   (float)(((Rnd*)FUN_0044a2d0())->F() * 10.0),
                                   (float)(((Rnd*)FUN_0044a2d0())->F() * 10.0 + 32.0));
                InitObj* collision = new InitObj(node);
                Sphere* shape = new Sphere(8.0f, 1);
                __declspec(align(16)) Big info;
                info.FUN_00507610(5.0f);
                info.FUN_006e4340(0.0f);
                info.FUN_0056d360(1);
                info.FUN_005076c0(1.0f);
                Temp622 filter;
                info.FUN_0056f0f0(filter.Ctor(4, FUN_005dbe10(), 0)->FUN_00559450());
                info.FUN_0056f110(shape);
                Body* body = new Body(&info);
                collision->FUN_008da000(body);
                obj->Vdc(node, 1);
                Acc* accumulator = new Acc;
                accumulator->FUN_005468d0(0xe);
                node->Vdc(accumulator, 1);
                S1fc actionInfo;
                actionInfo.Ctor();
                actionInfo.m04 = body->FUN_004ae750();
                actionInfo.fa = DAT_00f70868;
                actionInfo.fb = DAT_00f70864;
                actionInfo.fc = DAT_00f70860;
                actionInfo.fd = DAT_00f7085c;
                Liquid* action = new Liquid(&actionInfo);
                body->FUN_00900ad0(action);
            }
            if (FUN_008d6f30() && FUN_008d6f30()->FUN_004543c0())
            {
                FUN_008d6f30()->FUN_004543c0();
                bhkWorld_UpdatePosition(obj, 1, 1);
                Upd update;
                update.Ctor(0.0f, 0, 0);
                obj->FUN_008264c0(&update);
                Obj* world = (Obj*)FUN_008d6f30()->FUN_004543c0();
                world->Vd0(obj, 1, 1, 0, 1);
            }
        }
        if (FUN_008d6f30() && FUN_008d6f30()->FUN_004543c0())
        {
            FUN_008d6f30()->FUN_004543c0();
            bhkWorld_UpdatePosition(obj, 1, 1);
            Upd update;
            update.Ctor(0.0f, 0, 0);
            obj->FUN_008264c0(&update);
            Obj* world = (Obj*)FUN_008d6f30()->FUN_004543c0();
            world->Vd0(obj, 1, 1, 0, 1);
        }
        if (obj->V0c() && FUN_004e8d80(obj->V0c()))
            FUN_004ef0a0(obj->V0c());
        if (FUN_008d6f30() && FUN_008d6f30()->FUN_004543c0() && FUN_008d6f30()->FUN_004543c0()->FUN_004bae00())
        {
            Obj* world = (Obj*)FUN_008d6f30()->FUN_004543c0();
            world->Vd8(obj, 1);
            PrepareObjectWithNoLightingRecurse(obj);
        }
        Ctrl* ctrl = (Ctrl*)obj->FUN_0043b230();
        if (!ctrl)
        {
            Ctrl* node = (Ctrl*)obj->V0c();
            if (node && ((Obj*)node)->FUN_0043b4a0(0))
                ctrl = (Ctrl*)((Obj*)((Obj*)node)->FUN_0043b4a0(0))->FUN_0043b230();
        }
        Ctrl* manager = 0;
        while (ctrl)
        {
            if (IsKind(&DAT_01091f04, ctrl))
            {
                manager = ctrl;
                break;
            }
            ctrl = (Ctrl*)ctrl->GetNext();
        }
        Seq* sequence;
        if (manager && (sequence = (Seq*)manager->FUN_0047a520(FUN_005c1490())) != 0)
        {
            manager->NiControllerManager_DeactivateAll(0.0f);
            Start(manager, sequence, 0, 0, 1.0f, 0.0f, 0);
            manager->FUN_0047aa40(1);
            sequence->Free();
            if (FUN_00507e10() < sequence->FUN_00508100())
                FUN_00810550(sequence->FUN_00508100());
        }
        else
            FUN_00837ec0(obj);
    }
}

}

// @f3 0x007bfe30 (community match, verified in this file)
// FUN_007bfe30 (4698 bytes): explosion decal/impact placement, a port of FNV 0x009ae6e0.
// Compiled as /MT /O2 /GS /EHsc /Gy (the pack lists /Od /Oy-; the target is optimised code): full match there.
// Fake matches: the dead comparison locals at the top of the function, and the named float in Floor().
// Stand-in classes store their vtable through a 'vt' field bound to DAT_<address>.
#include <windows.h>
#include <math.h>

extern DWORD DAT_010f3170;

class hkThreadMemory
{
  public:
    virtual void tm000(); virtual void tm001(); virtual void tm002(); virtual void tm003(); virtual void tm004();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    char* m_stackPrev;
    char* m_stackBase;
    char* m_stackEnd;

    void FUN_008f6d90(void* p, int nbytes, int cls);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        void* ret;
        if (current + nbytes <= m_stackEnd)
        {
            m_stackCurrent = current + nbytes;
            ret = current;
        }
        else
        {
            ret = onStackOverflow(nbytes);
        }
        return ret;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackBase)
        {
            onStackUnderflow(p);
        }
    }
};

template <typename T>
class hkArray
{
  public:
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    __forceinline ~hkArray()
    {
        releaseMemory();
    }
    __forceinline int getCapacity() const
    {
        return m_capacityAndFlags & CAPACITY_MASK;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
class hkLocalArray : public hkArray<T>
{
  public:
    __forceinline hkLocalArray(int n)
    {
        this->m_data = (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_localMemory = this->m_data;
    }
    __forceinline ~hkLocalArray()
    {
        hkThreadMemory::getInstance().deallocateStack(m_localMemory);
    }

    T* m_localMemory;
};

struct NiPoint3
{
    float x, y, z;

    NiPoint3() {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3 operator*(float f) const
    {
        return NiPoint3(x * f, y * f, z * f);
    }
    NiPoint3& operator-=(const NiPoint3& p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
    bool operator==(const NiPoint3& p) const
    {
        return x == p.x && y == p.y && z == p.z;
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
    float Length() const
    {
        return (float)sqrt(SqrLength());
    }
    void FUN_00468d00();
    float FUN_00475250(const NiPoint3& p) const;
};

NiPoint3 __cdecl FUN_00468cd0(float f, const NiPoint3& p);

inline NiPoint3 ScaleVec(float f, const NiPoint3& p)
{
    return NiPoint3(f * p.x, f * p.y, f * p.z);
}

extern NiPoint3 DAT_0108ec68;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    hkVector4() {}
    hkVector4(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};

inline void HkToNi(NiPoint3* out, const hkVector4* in)
{
    out->x = in->x * 6.999040126800537f;
    out->y = in->y * 6.999040126800537f;
    out->z = in->z * 6.999040126800537f;
}

inline NiPoint3 HkToNiDir(const hkVector4* in)
{
    return NiPoint3(in->x, in->y, in->z);
}

struct hkpShape;

struct hkpCollidable
{
    hkpShape* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int unk1c;

    hkpShape* GetShape() const
    {
        return unk00;
    }
    unsigned int GetFilterInfo() const
    {
        return unk1c;
    }
    unsigned int GetLayerGroup() const
    {
        return unk1c >> 16;
    }
};

struct FilterInfo
{
    unsigned int m_info;

    FilterInfo* Set(unsigned int info)
    {
        m_info = info;
        return this;
    }
    unsigned int GetGroup() const
    {
        return m_info >> 16;
    }
};

struct hkpRootCdPoint
{
    hkVector4 unk00;
    hkVector4 unk10;
    hkpCollidable* unk20;
    int unk24;
    hkpCollidable* unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;

    const hkVector4* GetPosition() const
    {
        return &unk00;
    }
    const hkVector4* GetNormal() const
    {
        return &unk10;
    }
};

struct __declspec(align(16)) CollidableRef
{
    hkpCollidable* m_ptr;
};

struct HitInfo
{
    hkVector4 unk00;
    float unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20[8];
    int unk40;
    CollidableRef unk50;
};

struct Big4c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HitInfo* unk10;
    int unk14;
    int unk18;
    int unk1c;
    HitInfo unk20[8];

    Big4c0();
    ~Big4c0();
    int GetCount() const
    {
        return unk14;
    }
    HitInfo* GetEntryAt(int i) const
    {
        return unk10 + i;
    }
};

struct Big570
{
    hkVector4 unk00;
    hkVector4 unk10;
    int unk20;
    unsigned int unk24;
    int unk28;
    int unk2c;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;
    hkVector4 unk60;
    hkVector4 unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    int unkA0;
    int unkA4;
    Big4c0* unkA8;
    int unkAC;

    Big570();
    void FUN_0068daa0(const NiPoint3* to);
    void SetFrom(const NiPoint3* from)
    {
        hkVector4 t;
        t.x = from->x * 0.1428767293691635f;
        t.y = from->y * 0.1428767293691635f;
        t.z = from->z * 0.1428767293691635f;
        unk00 = t;
    }
    void SetFilter(unsigned int f)
    {
        unk24 = f;
    }
    void SetCollector(Big4c0* q)
    {
        unkA8 = q;
        unkA4 = 0;
    }
    Big4c0* GetCollector() const
    {
        return unkA8;
    }
};

extern void* DAT_00de6e68;
extern void* DAT_00e1b7f0;
extern void* DAT_00e13150;

struct hkBool
{
    char m_bool;
    hkBool(bool b) : m_bool(b) {}
    operator bool() const
    {
        return m_bool != 0;
    }
};

struct CdPointCollector
{
    void* vt;
    float unk04;

    CdPointCollector()
    {
        unk04 = 3.40282e38f;
    }
    ~CdPointCollector()
    {
        vt = &DAT_00de6e68;
    }
};

struct ProjList : CdPointCollector
{
    hkpRootCdPoint* unk08;
    hkpRootCdPoint* unk0c;
    int unk10;
    int unk14;

    ProjList(hkpRootCdPoint* buffer, int capacity)
    {
        vt = &DAT_00e1b7f0;
        unk08 = buffer;
        unk0c = buffer;
        unk10 = capacity;
        unk14 = 0;
    }
    hkBool HasHits() const
    {
        return unk14 > 0;
    }
    int GetCount() const
    {
        return unk14;
    }
    hkpRootCdPoint* GetHits() const
    {
        return unk08;
    }
};

struct ByteTag
{
};

void __cdecl FUN_007bd3e0(void* data, int lo, int hi, ByteTag tag);

template <typename T, typename L>
__forceinline void hkQuickSort(T* data, int n, L less)
{
    if (n > 1)
    {
        FUN_007bd3e0(data, 0, n - 1, less);
    }
}

template <typename T>
__forceinline void hkSort(T* data, int n)
{
    hkQuickSort(data, n, ByteTag());
}

struct RootPair
{
    hkpCollidable* unk00;
    int unk04;
    hkpCollidable* unk08;
    int unk0c;
};

struct NodeList
{
    void* vt;
    char unk04;
    RootPair* unk08;
    int unk0c;
    int unk10;
    RootPair unk14[16];

    NodeList()
    {
        unk08 = unk14;
        unk10 = 0x80000010;
        unk0c = 0;
        unk04 = 0;
        vt = &DAT_00e13150;
    }
    ~NodeList();
    RootPair* GetAt(int i)
    {
        return unk08 + i;
    }
};

struct Color4
{
    float r, g, b, a;
    Color4(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

struct Color3
{
    float r, g, b;
    Color3() {}
    Color3(float r_, float g_, float b_) : r(r_), g(g_), b(b_) {}
};

struct PackedColor
{
    unsigned char r, g, b, a;
};

struct Shape
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
    NiPoint3 unk58;
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
    NiPoint3 unk8c;

    void FUN_008268a0();
    void SetPos(const NiPoint3* p)
    {
        unk58 = *p;
    }
    const NiPoint3* GetWorldPos() const
    {
        return &unk8c;
    }
};

Shape* __cdecl FUN_00479c00(float size, Color4* color, int flag);
Shape* __cdecl FUN_0047a4e0(const NiPoint3* a, Color4* ca, const NiPoint3* b, Color4* cb, int flag);

struct Params
{
    NiPoint3 unk00;
    NiPoint3 unk0c;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Shape* unk28;
    int unk2c;
    void* unk30;
    int unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    int unk48;
    float unk4c;
    int unk50;
    float unk54;
    float unk58;
    int unk5c;
    Color3 unk60;
    int unk6c;
    unsigned char unk70;
    char unk71;
    char unk72;
    bool unk73;
    bool unk74;
    bool unk75;
    unsigned char unk76;
    char unk77;

    Params();
};

struct Mgr
{
    void FUN_0046b800(Params* prm, int a, int b);
};

struct Drawer
{
    void FUN_00433df0(Shape* s, float t);
    int FUN_00435d00(NiPoint3* pos);
    Mgr* FUN_00434880(NiPoint3 pos);
};

extern Drawer* DAT_0107a0d8;

struct Proc
{
    virtual void pv000(); virtual void pv001(); virtual void pv002(); virtual void pv003(); virtual void pv004(); virtual void pv005(); virtual void pv006(); virtual void pv007(); virtual void pv008(); virtual void pv009(); virtual void pv010(); virtual void pv011(); virtual void pv012(); virtual void pv013(); virtual void pv014(); virtual void pv015(); virtual void pv016(); virtual void pv017(); virtual void pv018(); virtual void pv019(); virtual void pv020(); virtual void pv021(); virtual void pv022(); virtual void pv023(); virtual void pv024(); virtual void pv025(); virtual void pv026(); virtual void pv027(); virtual void pv028(); virtual void pv029(); virtual void pv030(); virtual void pv031(); virtual void pv032(); virtual void pv033(); virtual void pv034(); virtual void pv035(); virtual void pv036(); virtual void pv037(); virtual void pv038(); virtual void pv039(); virtual void pv040(); virtual void pv041(); virtual void pv042(); virtual void pv043(); virtual void pv044(); virtual void pv045(); virtual void pv046(); virtual void pv047(); virtual void pv048(); virtual void pv049(); virtual void pv050(); virtual void pv051(); virtual void pv052(); virtual void pv053(); virtual void pv054(); virtual void pv055(); virtual void pv056(); virtual void pv057(); virtual void pv058(); virtual void pv059(); virtual void pv060(); virtual void pv061(); virtual void pv062(); virtual void pv063();
    virtual bool IsDead();
};

void* __cdecl FUN_004780d0(hkpCollidable* c);
Proc* __cdecl FUN_004e7b90(void* r);

struct ShapeOwner2
{
    virtual void ov000(); virtual void ov001(); virtual void ov002(); virtual void ov003(); virtual void ov004(); virtual void ov005(); virtual void ov006(); virtual void ov007(); virtual void ov008(); virtual void ov009(); virtual void ov010(); virtual void ov011(); virtual void ov012(); virtual void ov013(); virtual void ov014(); virtual void ov015(); virtual void ov016(); virtual void ov017(); virtual void ov018(); virtual void ov019(); virtual void ov020(); virtual void ov021(); virtual void ov022(); virtual void ov023(); virtual void ov024(); virtual void ov025(); virtual void ov026(); virtual void ov027(); virtual void ov028(); virtual void ov029(); virtual void ov030(); virtual void ov031(); virtual void ov032(); virtual void ov033(); virtual void ov034(); virtual void ov035(); virtual void ov036(); virtual void ov037(); virtual void ov038(); virtual void ov039(); virtual void ov040(); virtual void ov041(); virtual void ov042(); virtual void ov043(); virtual void ov044(); virtual void ov045(); virtual void ov046(); virtual void ov047(); virtual void ov048(); virtual void ov049(); virtual void ov050(); virtual void ov051(); virtual void ov052(); virtual void ov053(); virtual void ov054();
    virtual int GetId(int idx);
};

struct ShapeOwner
{
    virtual void ow000(); virtual void ow001(); virtual void ow002(); virtual void ow003(); virtual void ow004(); virtual void ow005(); virtual void ow006(); virtual void ow007(); virtual void ow008(); virtual void ow009(); virtual void ow010(); virtual void ow011(); virtual void ow012(); virtual void ow013(); virtual void ow014(); virtual void ow015(); virtual void ow016(); virtual void ow017(); virtual void ow018(); virtual void ow019(); virtual void ow020(); virtual void ow021(); virtual void ow022(); virtual void ow023(); virtual void ow024(); virtual void ow025(); virtual void ow026(); virtual void ow027(); virtual void ow028(); virtual void ow029(); virtual void ow030(); virtual void ow031(); virtual void ow032(); virtual void ow033(); virtual void ow034(); virtual void ow035(); virtual void ow036(); virtual void ow037(); virtual void ow038(); virtual void ow039(); virtual void ow040(); virtual void ow041(); virtual void ow042(); virtual void ow043(); virtual void ow044(); virtual void ow045(); virtual void ow046(); virtual void ow047(); virtual void ow048(); virtual void ow049();
    virtual ShapeOwner2* GetOwner();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    int FUN_008f76a0(int key);
    int GetMaterial() const
    {
        return unk10 & 0x1f;
    }
};

struct hkpShape
{
    int unk00;
    int unk04;
    ShapeOwner* unk08;
};

inline ShapeOwner* GetOwner(hkpShape* s)
{
    return s ? s->unk08 : 0;
}

struct World
{
    virtual void wv000(); virtual void wv001(); virtual void wv002(); virtual void wv003(); virtual void wv004(); virtual void wv005(); virtual void wv006(); virtual void wv007(); virtual void wv008(); virtual void wv009(); virtual void wv010(); virtual void wv011(); virtual void wv012(); virtual void wv013(); virtual void wv014(); virtual void wv015(); virtual void wv016(); virtual void wv017(); virtual void wv018(); virtual void wv019(); virtual void wv020(); virtual void wv021(); virtual void wv022(); virtual void wv023(); virtual void wv024(); virtual void wv025(); virtual void wv026(); virtual void wv027(); virtual void wv028(); virtual void wv029(); virtual void wv030(); virtual void wv031(); virtual void wv032(); virtual void wv033(); virtual void wv034(); virtual void wv035(); virtual void wv036(); virtual void wv037(); virtual void wv038(); virtual void wv039(); virtual void wv040(); virtual void wv041(); virtual void wv042(); virtual void wv043(); virtual void wv044(); virtual void wv045(); virtual void wv046(); virtual void wv047(); virtual void wv048(); virtual void wv049();
    virtual bool Pick(Big570* p);
};

extern World* DAT_01071564;

struct ExtraList
{
    World* FUN_00410f00();
};

struct Cell
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
    unsigned char unk24;
    char unk25;
    char unk26;
    char unk27;
    ExtraList unk28;

    World* GetWorld()
    {
        if (unk24 & 1)
        {
            return unk28.FUN_00410f00();
        }
        return DAT_01071564;
    }
};

struct hkpWorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpCollidable unk10;

    hkpCollidable* GetCollidable()
    {
        return &unk10;
    }
};

struct Phantom
{
    int unk00;
    int unk04;
    hkpWorldObject* unk08;

    void FUN_0090e6c0(ProjList* list);
    unsigned int GetFilterInfo()
    {
        hkpWorldObject* o = unk08;
        if (o)
        {
            hkpCollidable* c = o->GetCollidable();
            if (c)
            {
                return c->unk1c;
            }
        }
        return 0;
    }
};

struct PhantomPtr
{
    Phantom* m_pObject;

    operator Phantom*() const
    {
        return m_pObject;
    }
    Phantom* operator->() const
    {
        return m_pObject;
    }
};

struct SndSrc
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
    const char* unk34;

    const char* GetName() const
    {
        return unk34 ? unk34 : "";
    }
};

struct Snd
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00bd0290(float x, float y, float z);
    void FUN_00bd00c0(int a);
};

struct SndMgr
{
    Snd FUN_00bcfc40(const char* name, int flags, SndSrc* src);
};

extern SndMgr* DAT_011790c8;

struct NameHolder
{
    virtual void nh000(); virtual void nh001(); virtual void nh002(); virtual void nh003(); virtual void nh004();
    virtual char* GetName();
};

struct Weap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NameHolder unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    float unk30;
    int unk34;
    float unk38;
    int unk3c;
    int unk40;
    int unk44;
    void* unk48;
    SndSrc* unk4c;
    SndSrc* unk50;
    float unk54;
    float unk58;
    int unk5c;
    int unk60;
    float unk64;
    float unk68;
    float unk6c;
    unsigned char unk70;
    unsigned char unk71;
    char unk72;
    char unk73;
    unsigned int unk74;

    unsigned int GetColor() const
    {
        return unk74;
    }
    float GetMin() const
    {
        return unk54;
    }
    float GetMax() const
    {
        return unk58;
    }
    float GetDuration() const
    {
        return unk30;
    }
    bool GetBit0() const
    {
        return (unk71 & 1) != 0;
    }
    bool GetBit1() const
    {
        return ((unk71 >> 1) & 1) != 0;
    }
    bool GetBit2() const
    {
        return ((unk71 >> 2) & 1) != 0;
    }
};

struct BaseForm
{
    Weap* FUN_004a5280(int material);
};

struct Query
{
    void FUN_00569c20(int a);
    void FUN_00569e40(World* w);
    void FUN_00569c60(NiPoint3* pos, NodeList* out);
};

Query* __cdecl FUN_0056a180(float radius, int flag);
void __cdecl FUN_008f4400(unsigned int a, unsigned int b, bool c);
float __cdecl FUN_0044a330(float lo, float hi);
float __cdecl RandomFloatTwoPi();
bool __cdecl FUN_004768c0(NiPoint3 pos, Shape* camera, float radius);
void* __cdecl FUN_004756f0(hkpCollidable* ref);
Shape* __cdecl FUN_008f1bf0(hkpCollidable* ref);
bool __cdecl FUN_00469000(Proc* u, int flag);
void __cdecl FUN_005b4d20(Cell* cell, float duration, char* name, NiPoint3 dir, NiPoint3 pos, float scale, int a,
                          int b);
void __cdecl FUN_00930570();

struct Hand8
{
    Shape* unk00;
    int unk04;
};

struct Rtti;
extern Rtti DAT_0108f414;
Hand8* __cdecl FUN_00477960(Hand8* out, void* obj, Rtti* rtti);

struct Camera
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
    int unkA0;
    int unkA4;
    int unkA8;
    Shape* unkAC;
};

extern Camera* DAT_0107a224;
extern bool DAT_0107a0f2;
extern float DAT_00f60504;
extern int DAT_00f61ff8;
extern int DAT_00f707ec;

// Fake match: the named local gives the single float store-reload after the floor call.
inline float Floor(float f)
{
    float r = (float)floor((double)f);
    return r;
}

inline Shape* GetCameraNode()
{
    return DAT_0107a224->unkAC;
}

class Obj
{
  public:
    virtual void xv000(); virtual void xv001(); virtual void xv002(); virtual void xv003(); virtual void xv004(); virtual void xv005(); virtual void xv006(); virtual void xv007(); virtual void xv008(); virtual void xv009(); virtual void xv010(); virtual void xv011(); virtual void xv012(); virtual void xv013(); virtual void xv014(); virtual void xv015(); virtual void xv016(); virtual void xv017(); virtual void xv018(); virtual void xv019(); virtual void xv020(); virtual void xv021(); virtual void xv022(); virtual void xv023(); virtual void xv024(); virtual void xv025(); virtual void xv026(); virtual void xv027(); virtual void xv028(); virtual void xv029(); virtual void xv030(); virtual void xv031(); virtual void xv032(); virtual void xv033(); virtual void xv034(); virtual void xv035(); virtual void xv036(); virtual void xv037(); virtual void xv038(); virtual void xv039(); virtual void xv040(); virtual void xv041(); virtual void xv042(); virtual void xv043(); virtual void xv044(); virtual void xv045(); virtual void xv046(); virtual void xv047(); virtual void xv048(); virtual void xv049(); virtual void xv050(); virtual void xv051(); virtual void xv052(); virtual void xv053(); virtual void xv054(); virtual void xv055(); virtual void xv056(); virtual void xv057(); virtual void xv058(); virtual void xv059(); virtual void xv060(); virtual void xv061(); virtual void xv062(); virtual void xv063(); virtual void xv064(); virtual void xv065(); virtual void xv066(); virtual void xv067(); virtual void xv068(); virtual void xv069(); virtual void xv070(); virtual void xv071(); virtual void xv072(); virtual void xv073(); virtual void xv074(); virtual void xv075(); virtual void xv076(); virtual void xv077(); virtual void xv078(); virtual void xv079(); virtual void xv080(); virtual void xv081(); virtual void xv082(); virtual void xv083(); virtual void xv084(); virtual void xv085(); virtual void xv086(); virtual void xv087(); virtual void xv088(); virtual void xv089(); virtual void xv090(); virtual void xv091(); virtual void xv092(); virtual void xv093(); virtual void xv094(); virtual void xv095(); virtual void xv096(); virtual void xv097(); virtual void xv098(); virtual void xv099(); virtual void xv100(); virtual void xv101(); virtual void xv102(); virtual void xv103(); virtual void xv104(); virtual void xv105(); virtual void xv106(); virtual void xv107(); virtual void xv108(); virtual void xv109(); virtual void xv110(); virtual void xv111(); virtual void xv112(); virtual void xv113(); virtual void xv114(); virtual void xv115(); virtual void xv116(); virtual void xv117(); virtual void xv118(); virtual void xv119(); virtual void xv120(); virtual void xv121(); virtual void xv122(); virtual void xv123(); virtual void xv124();
    virtual const NiPoint3* GetPos();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    BaseForm* unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    Cell* unk3c;
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
    PhantomPtr unk98;
    int unk9c;
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
    bool unkCC;
    bool unkCD;
    bool unkCE;
    bool unkCF;
    bool unkD0;
    bool unkD1;
    bool unkD2;
    bool unkD3;
    int unkD4;
    int unkD8;
    int unkDC;
    NiPoint3 unkE0;
    NiPoint3 unkEC;

    void FUN_007bcff0();
    void FUN_007bf200();
    void FUN_007bfe30();

    Cell* GetParentCell()
    {
        return unk3c;
    }
    void SetClosest(const NiPoint3& p)
    {
        unkE0 = p;
    }
};

// pdb: Explosion::ApplyImpactDecals | Explosion.obj | fnv360_0822_retail, call_seq, medium
void Obj::FUN_007bfe30()
{
    if (unk98 == 0)
        return;
    // Fake match: Nine dead locals. Each is an unused point comparison that emits no code. Together they add
    // value-producing conditional expressions to the function's intermediate code, which moves the compiler's
    // internal temporary numbers past the point (a multiple of 1024) where "array pointer + strength-reduced
    // offset" is ordered pointer first: the in-place add of loop 1 at 0x1c8 and the base registers of the pair
    // loads at 0xbbb and 0xbc9. The original must have that much more inline conditional code (bool helpers);
    // these stand in for it.
    bool same0 = unkE0 == unkEC;
    bool same1 = unkE0 == unkEC;
    bool same2 = unkE0 == unkEC;
    bool same3 = unkE0 == unkEC;
    bool same4 = unkE0 == unkEC;
    bool same5 = unkE0 == unkEC;
    bool same6 = unkE0 == unkEC;
    bool same7 = unkE0 == unkEC;
    bool same8 = unkE0 == unkEC;
    if (unkDC > 0 && unkCE && !unkCF)
        FUN_007bcff0();
    if (unkCD && !unkCC)
    {
        unkCC = true;
        hkLocalArray<hkpRootCdPoint> res(DAT_00f61ff8);
        ProjList list(res.begin(), DAT_00f61ff8);
        FUN_00930570();
        unk98->FUN_0090e6c0(&list);
        if (list.HasHits())
            hkSort(res.begin(), list.GetCount());
        if (DAT_00f707ec > 1)
        {
            for (int i = 0; i < list.GetCount(); i++)
            {
                hkpRootCdPoint e(list.GetHits()[i]);
                NiPoint3 a;
                HkToNi(&a, e.GetPosition());
                NiPoint3 b = HkToNiDir(e.GetNormal());
                Color4 c(1.0f, 0.0f, 0.0f, 0.65f);
                Shape* s = FUN_00479c00(1.5f, &c, 1);
                s->FUN_008268a0();
                s->SetPos(&a);
                DAT_0107a0d8->FUN_00433df0(s, 10.0f);
                s = FUN_0047a4e0(&a, &c, &(a + b * 10.0f), &c, 1);
                DAT_0107a0d8->FUN_00433df0(s, 10.0f);
            }
        }
        bool done = false;
        for (int j = 0; !done && j < list.GetCount(); j++)
        {
            hkpRootCdPoint e(list.GetHits()[j]);
            if (e.unk28)
            {
                void* r = FUN_004780d0(e.unk28);
                Proc* u = FUN_004e7b90(r);
                if (!u || !u->IsDead())
                {
                    NiPoint3 pos;
                    HkToNi(&pos, e.GetPosition());
                    NiPoint3 dir = HkToNiDir(e.GetNormal());
                    Big4c0 q;
                    Big570 p;
                    NiPoint3 v = *GetPos();
                    NiPoint3 w = ScaleVec(2.0f, pos - v);
                    if (w.Length() < 1.0f)
                    {
                        v -= dir * 16.0f;
                        w = dir * 32.0f;
                    }
                    p.SetFrom(&v);
                    p.FUN_0068daa0(&w);
                    p.SetFilter(unk98 ? unk98->GetFilterInfo() : 0);
                    p.SetCollector(&q);
                    int target = 0x20;
                    bool found = false;
                    if (GetParentCell()->GetWorld())
                    {
                        World* pk = GetParentCell()->GetWorld();
                        if (pk->Pick(&p))
                        {
                            bool stop = false;
                            for (int k = 0; !found && !stop && k < p.GetCollector()->GetCount(); k++)
                            {
                                HitInfo h(*p.GetCollector()->GetEntryAt(k));
                                hkpCollidable* c2 = h.unk50.m_ptr;
                                void* r2 = FUN_004780d0(c2);
                                Proc* u2 = FUN_004e7b90(r2);
                                if (r == r2)
                                {
                                    found = true;
                                    int last = -1;
                                    for (int m = 0; m < 8 && h.unk20[m] != -1; m++)
                                        last = h.unk20[m];
                                    FilterInfo wr;
                                    bool isActor = wr.Set(c2->GetFilterInfo())->GetGroup() == 1;
                                    if (isActor)
                                    {
                                        target = DAT_0107a0d8->FUN_00435d00(&pos);
                                    }
                                    else
                                    {
                                        ShapeOwner* ow = GetOwner(c2->GetShape());
                                        if (ow)
                                            target = ow->FUN_008f76a0(last);
                                    }
                                }
                                else if (!u2 || !u2->IsDead())
                                {
                                    stop = true;
                                }
                            }
                        }
                    }
                    if (found)
                    {
                        SetClosest(pos);
                        if (unkEC == DAT_0108ec68)
                            unkEC = dir;
                        if (DAT_00f707ec > 1)
                        {
                            Color4 c(0.0f, 1.0f, 0.0f, 0.65f);
                            Shape* s = FUN_00479c00(5.0f, &c, 1);
                            s->FUN_008268a0();
                            s->SetPos(&unkE0);
                            DAT_0107a0d8->FUN_00433df0(s, 10.0f);
                            s = FUN_0047a4e0(&unkE0, &c, &(unkE0 + unkEC * 20.0f), &c, 1);
                            DAT_0107a0d8->FUN_00433df0(s, 10.0f);
                        }
                        done = true;
                        Weap* wt = unk1c->FUN_004a5280(target);
                        if (wt)
                        {
                            bool flag = true;
                            NiPoint3 dd = pos - *GetCameraNode()->GetWorldPos();
                            if (DAT_0107a0f2 || dd.Length() > DAT_00f60504 ||
                                !FUN_004768c0(pos, GetCameraNode(), 32.0f))
                                flag = false;
                            void* proj = wt->unk48;
                            if (proj)
                            {
                                float spd = FUN_0044a330(wt->GetMin(), wt->GetMax());
                                Query* qq = FUN_0056a180(spd, 1);
                                qq->FUN_00569c20(0);
                                FUN_008f4400(0x27, 8, false);
                                FUN_008f4400(0x27, 0x1d, false);
                                Cell* p2 = GetParentCell();
                                World* t;
                                if (p2 && (t = p2->GetWorld()) != 0)
                                {
                                    qq->FUN_00569e40(t);
                                    NodeList nl;
                                    qq->FUN_00569c60(&pos, &nl);
                                    int n = nl.unk0c;
                                    float fade = RandomFloatTwoPi();
                                    unsigned char cc = (unsigned char)Floor(FUN_0044a330(0.0f, 4.0f));
                                    for (int k = 0; k < n; k++)
                                    {
                                        hkpCollidable* ref = nl.GetAt(k)->unk08;
                                        if (ref)
                                        {
                                            int id = target;
                                            int idx = nl.GetAt(k)->unk0c;
                                            if (idx != -1)
                                            {
                                                ShapeOwner* ow = GetOwner(ref->GetShape());
                                                if (!ow)
                                                    continue;
                                                ShapeOwner2* o2 = ow->GetOwner();
                                                if (o2)
                                                    id = o2->GetId(idx);
                                            }
                                            else
                                            {
                                                ShapeOwner* ow = GetOwner(ref->GetShape());
                                                if (!ow)
                                                    continue;
                                                id = ow->GetMaterial();
                                            }
                                            if (id == target)
                                            {
                                                FilterInfo wr;
                                                bool isActor = wr.Set(ref->GetFilterInfo())->GetGroup() == 1;
                                                Shape* node = 0;
                                                if (isActor)
                                                {
                                                    void* a = FUN_004756f0(ref);
                                                    if (a)
                                                    {
                                                        Hand8 hh;
                                                        node = FUN_00477960(&hh, a, &DAT_0108f414)->unk00;
                                                        if (node && node->unk18)
                                                            node = (Shape*)node->unk18;
                                                    }
                                                }
                                                else
                                                {
                                                    node = FUN_008f1bf0(ref);
                                                }
                                                Proc* u3 = FUN_004e7b90(node);
                                                if (!isActor && (!u3 || !FUN_00469000(u3, 1)))
                                                    continue;
                                                Mgr* mg = DAT_0107a0d8->FUN_00434880(pos);
                                                Params prm;
                                                prm.unk00 = unkE0;
                                                prm.unk0c = unkEC;
                                                prm.unk38 = spd;
                                                prm.unk3c = spd;
                                                prm.unk40 = wt->unk64;
                                                prm.unk28 = node;
                                                prm.unk30 = proj;
                                                prm.unk44 = fade;
                                                prm.unk70 = cc;
                                                prm.unk75 = wt->GetBit1();
                                                prm.unk74 = wt->GetBit2();
                                                prm.unk73 = wt->GetBit0();
                                                prm.unk4c = wt->unk6c;
                                                prm.unk76 = wt->unk70;
                                                prm.unk54 = wt->unk68;
                                                prm.unk58 = wt->unk38;
                                                Color3 col;
                                                col.r = (float)(GetRValue(wt->GetColor()) / 255.0);
                                                col.g = (float)(GetGValue(wt->GetColor()) / 255.0);
                                                col.b = (float)(GetBValue(wt->GetColor()) / 255.0);
                                                prm.unk60 = col;
                                                mg->FUN_0046b800(&prm, 1, 0);
                                            }
                                        }
                                    }
                                }
                            }
                            if (flag && !unkD1)
                            {
                                char* name = wt->unk18.GetName();
                                if (name && *name)
                                {
                                    NiPoint3 dv;
                                    switch (wt->unk34)
                                    {
                                    case 0:
                                        dv = dir;
                                        dv.FUN_00468d00();
                                        break;
                                    case 1:
                                        dv = *GetPos() - pos;
                                        dv.FUN_00468d00();
                                        break;
                                    case 2: {
                                        NiPoint3 a = *GetPos() - pos;
                                        a.FUN_00468d00();
                                        NiPoint3 b = dir;
                                        b.FUN_00468d00();
                                        dv = FUN_00468cd0((float)(b.FUN_00475250(a) * 2.0), b) - a;
                                        break;
                                    }
                                    default:
                                        dv = dir;
                                        dv.FUN_00468d00();
                                        break;
                                    }
                                    FUN_005b4d20(GetParentCell(), wt->GetDuration(), name, dv, pos, 1.0f, 7, 0);
                                }
                            }
                            SndSrc* s1 = wt->unk4c;
                            if (s1)
                            {
                                Snd snd = DAT_011790c8->FUN_00bcfc40(s1->GetName(), 0x4102, s1);
                                snd.FUN_00bd0290(pos.x, pos.y, pos.z);
                                snd.FUN_00bd00c0(0);
                            }
                            SndSrc* s2 = wt->unk50;
                            if (s2)
                            {
                                Snd snd = DAT_011790c8->FUN_00bcfc40(s2->GetName(), 0x4102, s2);
                                snd.FUN_00bd0290(pos.x, pos.y, pos.z);
                                snd.FUN_00bd00c0(0);
                            }
                        }
                    }
                }
            }
        }
        if (unkCD && !unkCE)
            FUN_007bf200();
    }
}
