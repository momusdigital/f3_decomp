#include <math.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_005c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005c8b90 (community match, verified in this file)
namespace f3m_005c8b90 {


class NiRefObject
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiObjPtr
{
    NiRefObject* m_pObject;

    NiObjPtr& operator=(const NiObjPtr& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    ~NiObjPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct AE8DE0_Record
{
    int unk00;
    int m_04;
    NiObjPtr m_08;
};

class AE8DE0_Class
{
  public:
    int unk00;

    void FUN_005c8b90(AE8DE0_Record* a1, int a2, NiObjPtr a3);
};

// pdb: NiTMapBase<DFALL<NiTMapItem<bhkRigidBody *,NiPointer<ObstacleData> > >,bhkRigidBody *,NiPointer<ObstacleData> >::SetValue | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkItem, key, val
void AE8DE0_Class::FUN_005c8b90(AE8DE0_Record* a1, int a2, NiObjPtr a3)
{
    a1->m_04 = a2;
    a1->m_08 = a3;
}

}   // namespace f3m_005c8b90

// @f3 0x005c89c0 (community match, verified in this file)
#include <windows.h>
namespace f3m_005c89c0 {
namespace Cleanup108{
struct Reference108;
struct Manager108{
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
virtual void Remove(Reference108*);
};

struct Reference108{
 virtual void slot00();virtual void Destroy();
 volatile long references;
 unsigned int unk08,unk0c,unk10,unk14;
 Manager108* manager;
};
struct Handle108{
 Reference108* pointer;
 void Reset(){if(pointer){Reference108* old=pointer;if(!InterlockedDecrement(&old->references))old->Destroy();pointer=0;}}
};
struct Owner108{
 unsigned int unk00;Handle108 first,second;
 void FUN_005c89c0();
};
// pdb: NavMeshRender::Update | NavMeshRender.obj | fnv360_0822_retail, call_gap, low
void Owner108::FUN_005c89c0(){
 if(first.pointer&&first.pointer->manager)first.pointer->manager->Remove(first.pointer);
 if(second.pointer&&second.pointer->manager)second.pointer->manager->Remove(second.pointer);
 first.Reset();second.Reset();
}
}


}   // namespace f3m_005c89c0

// @f3 0x005c31a0 (community match, verified in this file)
extern char DAT_00dbe764;
namespace f3m_005c31a0 {
struct VecA { float x, y, z; VecA() { x = -3.402823466e+38f; y = -3.402823466e+38f; z = -3.402823466e+38f; } };
struct VecB { float x, y, z; VecB() { x = 3.402823466e+38f; y = 3.402823466e+38f; z = 3.402823466e+38f; } };
struct Base18 { virtual ~Base18(); int unk1c; int unk20; int unk24; Base18() { unk1c = 0; unk20 = 0; unk24 = 0; } };
struct Tail { void* table; int unk2c; int unk30; int unk34; Tail(unsigned n) { table = &DAT_00dbe764; unk2c = 0; unk30 = 0; unk34 = 0; if (n) Grow(n); } void Grow(unsigned); ~Tail(); };
class Holder { public: VecA a; VecB b; Base18 sub; Tail tail; Holder(); };
// pdb: NavMeshBounds::NavMeshBounds | NavMeshBounds.obj | fnv360_0822_retail, call_seq, high
Holder::Holder() : tail(0) {  }
}   // namespace f3m_005c31a0

// @f3 0x005c6320 (community match, verified in this file)
namespace f3m_005c6320 {



inline float AbsF(float a) { return (float)fabs(a); }
inline float CosF(float a) { return (float)cos(a); }
inline float SinF(float a) { return (float)sin(a); }
struct V3C { float x,y,z; V3C() {} V3C(float a,float b,float c):x(a),y(b),z(c) {}
 V3C operator-(const V3C& o) const { return V3C(x-o.x,y-o.y,z-o.z); }
 V3C operator+(const V3C& o) const { return V3C(x+o.x,y+o.y,z+o.z); }
 V3C Cross(const V3C& p) const { return V3C(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x); }
 float SqrLengthXY() const { float fx=x; float fy=y; return fx*fx+fy*fy; }
 float Length() const { return (float)sqrt(x*x+y*y+z*z); }
};
struct V2C { bool FUN_005c42b0(const V2C&) const; float x,y; V2C() {} V2C(float a,float b):x(a),y(b) {}
 V2C(float angle) { Set(angle); }
 V2C(const V2C& v):x(v.x),y(v.y) {}
 V2C& operator=(const V2C& v) { x=v.x; y=v.y; return *this; }
 V2C* Set(float angle) { x=CosF(angle); y=SinF(angle); return this; }
 V2C& Left(const V2C& o) { float b=y; float c=o.x; float a=x; float s=o.y; x=a*c-b*s; y=a*s+b*c; return *this; }
 V2C& Right(const V2C& o) { float b=x; float a=y; x=b*o.x+a*o.y; y=a*o.x-b*o.y; return *this; }
 V2C operator-(const V2C& o) const { V2C r; double sum=y*o.y; sum+=x*o.x; r.x=(float)sum; r.y=-(x*o.y)+y*o.x; return r; }
 V3C ToPoint(float radius) const { return V3C(radius*x,radius*y,0.0f); }
};
struct CircleC { V3C position; float radius; CircleC(const V3C& p,float r):position(p),radius(r) {} };
struct MotionC { V2C from,to; int direction; float FUN_005c43e0(float radius);
 MotionC(const V2C& f,const V2C& t,int d):from(f),to(t),direction(d) {}
 MotionC(const MotionC& m):from(m.from),to(m.to),direction(m.direction) {}
 bool Contains(const V2C& angle) const {
  const V2C& startAngle=from;
  const V2C& endAngle=to;
  const int orientation=direction;
  const V2C& first=orientation==0?startAngle:endAngle;
  const V2C& last=orientation==0?endAngle:startAngle;
  const V2C& sampleAngle=angle;
  const V2C span=last-first;
  const float& cx=sampleAngle.x;
  const float& cbase=first.x;
  const float& sbase=first.y;
  const float& sy=sampleAngle.y;
  V2C relative;
  relative.x=cx*cbase+sy*sbase;
  relative.y=-(cx*sbase)+sy*cbase;
  return relative.FUN_005c42b0(span);
 }
};
struct NodeC { int kind; V3C position; float radius; V3C sideA,sideB; float extraCost; };
struct RefBaseC { virtual void Slot00(); virtual void Destroy(); volatile long references;
 void Release() { if(!InterlockedDecrement(&references)) Destroy(); } };
struct RootC { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18; RefBaseC ref; };
struct RootGuardC { RootC* root; RootGuardC():root(0) {} ~RootGuardC() { if(root) root->ref.Release(); } RootC* Get() const { return root; } };
struct LocationC { RootC* root; unsigned short tag; int flags; V3C position;
 LocationC& operator=(const LocationC& other) { root=other.root;tag=other.tag;flags=other.flags;position=other.position;return *this; }
};
struct NodePartC { NodeC* node; int direction; unsigned bucket; };
struct LinkPartC { int unk00,unk04; V2C forward; int unk10,unk14,unk18,unk1c,unk20,unk24; LocationC location; };
struct QueryC { float cost; int unk04; NodePartC nodePart; LinkPartC linkPart; QueryC* parent;
 const NodePartC& GetNode() const { return nodePart; }
 const LinkPartC& GetLink() const { return linkPart; }
 QueryC* GetParent() const { return parent; }
 float GetCost() const { return cost; }
};
struct ResultC { float cost; int unk04,unk08,unk0c,unk10; V2C from,to; LocationC locationA,locationB;
 void SetCost(float c) { cost=c; }
};
struct BucketC { int unk00; NodeC** nodes; unsigned count; unsigned capacity; };
struct TangentC { int endpoint; V2C from,to; };
struct TangentsC { int unk00; TangentC entries[2]; };
int FUN_005dea40(const CircleC&, const CircleC&, int direction, TangentsC&);
void FUN_005c4d50(const V3C&,const V3C&,const void*);
void FUN_005c5410(const V3C&,float,const V2C&,const V2C&,int,const void*);
struct OutputC { int unk00; ResultC** entries; int FUN_005e5350();
 void Add(ResultC* const& item) { int index=FUN_005e5350(); entries[index]=item; }
};
struct CacheC { bool FUN_005fc8f0(RootGuardC&,unsigned short&); int unk00; V3C defaultPosition;
 V3C GetPosition() const { return defaultPosition; }
};
extern const double DAT_00dc8080;
extern const double g_thresholdB;
extern const float DAT_00de7c24 = 180.0f;
extern V3C DAT_0108ec68;
extern bool DAT_0107454c;
extern int DAT_00f73260,DAT_00f73230,DAT_00f73240;
class SearchC { public:
int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014; int unk0018; int unk001C; int unk0020; int unk0024;
int unk0028; int unk002C; int unk0030; int unk0034; int unk0038; int unk003C; int unk0040; int unk0044; int unk0048; int unk004C;
int unk0050; int unk0054; int unk0058; int unk005C; int unk0060; int unk0064; int unk0068; int unk006C; int unk0070; int unk0074;
int unk0078; int unk007C; int unk0080; int unk0084; int unk0088; int unk008C; int unk0090; int unk0094; int unk0098; int unk009C;
int unk00A0; int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4; int unk00B8; int unk00BC; int unk00C0; int unk00C4;
int unk00C8; int unk00CC; int unk00D0; int unk00D4; int unk00D8; int unk00DC; int unk00E0; int unk00E4; int unk00E8; int unk00EC;
int unk00F0; int unk00F4; int unk00F8; int unk00FC; int unk0100; int unk0104; int unk0108; int unk010C; int unk0110; int unk0114;
int unk0118; int unk011C; int unk0120; int unk0124; int unk0128; int unk012C; int unk0130; int unk0134; int unk0138; int unk013C;
int unk0140; int unk0144; int unk0148; int unk014C; int unk0150; int unk0154; int unk0158; int unk015C; int unk0160; int unk0164;
int unk0168; int unk016C; int unk0170; int unk0174; int unk0178; int unk017C; int unk0180; int unk0184; int unk0188; int unk018C;
int unk0190; int unk0194; int unk0198; int unk019C; int unk01A0; int unk01A4; int unk01A8; int unk01AC; int unk01B0; int unk01B4;
int unk01B8; int unk01BC; int unk01C0; int unk01C4; int unk01C8; int unk01CC; int unk01D0; int unk01D4; int unk01D8; int unk01DC;
int unk01E0; int unk01E4; int unk01E8; int unk01EC; int unk01F0; int unk01F4; int unk01F8; int unk01FC; int unk0200; int unk0204;
int unk0208; int unk020C; int unk0210; int unk0214; int unk0218; int unk021C; int unk0220; int unk0224; int unk0228; int unk022C;
int unk0230; int unk0234; int unk0238; int unk023C; int unk0240; int unk0244; int unk0248; int unk024C; int unk0250; int unk0254;
int unk0258; int unk025C; int unk0260; int unk0264; int unk0268; int unk026C; int unk0270; int unk0274; int unk0278; int unk027C;
int unk0280; int unk0284; int unk0288; int unk028C; int unk0290; int unk0294; int unk0298; int unk029C; int unk02A0; int unk02A4;
int unk02A8; int unk02AC; int unk02B0; int unk02B4; int unk02B8; int unk02BC; int unk02C0; int unk02C4; int unk02C8; int unk02CC;
int unk02D0; int unk02D4; int unk02D8; int unk02DC; int unk02E0; int unk02E4; int unk02E8; int unk02EC; int unk02F0; int unk02F4;
int unk02F8; int unk02FC; int unk0300; int unk0304; int unk0308; int unk030C; int unk0310; int unk0314; int unk0318; int unk031C;
int unk0320; int unk0324; int unk0328; int unk032C; int unk0330; int unk0334; int unk0338; int unk033C; int unk0340; int unk0344;
int unk0348; int unk034C; int unk0350; int unk0354; int unk0358; int unk035C; int unk0360; int unk0364; int unk0368; int unk036C;
int unk0370; int unk0374; int unk0378; int unk037C; int unk0380; int unk0384; int unk0388; int unk038C; int unk0390; int unk0394;
int unk0398; int unk039C; int unk03A0; int unk03A4; int unk03A8; int unk03AC; int unk03B0; int unk03B4; int unk03B8; int unk03BC;
int unk03C0; int unk03C4; int unk03C8; int unk03CC; int unk03D0; int unk03D4; int unk03D8; int unk03DC; int unk03E0; int unk03E4;
int unk03E8; int unk03EC; int unk03F0; int unk03F4; int unk03F8; int unk03FC; int unk0400; int unk0404; int unk0408; int unk040C;
int unk0410; int unk0414; int unk0418; int unk041C; int unk0420; int unk0424; int unk0428; int unk042C; int unk0430; int unk0434;
int unk0438; int unk043C; int unk0440; int unk0444; int unk0448; int unk044C; int unk0450; int unk0454; int unk0458; int unk045C;
int unk0460; int unk0464; int unk0468; int unk046C; int unk0470; int unk0474; int unk0478; int unk047C; int unk0480; int unk0484;
int unk0488; int unk048C; int unk0490; int unk0494; int unk0498; int unk049C; int unk04A0; int unk04A4; int unk04A8; int unk04AC;
int unk04B0; int unk04B4; int unk04B8; int unk04BC; int unk04C0; int unk04C4; int unk04C8; int unk04CC; int unk04D0; int unk04D4;
int unk04D8; int unk04DC; int unk04E0; int unk04E4; int unk04E8; int unk04EC; int unk04F0; int unk04F4; int unk04F8; int unk04FC;
int unk0500; int unk0504; int unk0508; int unk050C; int unk0510; int unk0514; int unk0518; int unk051C; int unk0520; int unk0524;
int unk0528; int unk052C; int unk0530; int unk0534; int unk0538; int unk053C; int unk0540; int unk0544; int unk0548; int unk054C;
int unk0550; int unk0554; int unk0558; int unk055C; int unk0560; int unk0564; int unk0568; int unk056C; int unk0570; int unk0574;
int unk0578; int unk057C; int unk0580; int unk0584; int unk0588; int unk058C; int unk0590; int unk0594; int unk0598; int unk059C;
int unk05A0; int unk05A4; int unk05A8; int unk05AC; int unk05B0; int unk05B4; int unk05B8; int unk05BC; int unk05C0; int unk05C4;
int unk05C8; int unk05CC; int unk05D0; int unk05D4; int unk05D8; int unk05DC; int unk05E0; int unk05E4; int unk05E8; int unk05EC;
int unk05F0; int unk05F4; int unk05F8; int unk05FC; int unk0600; int unk0604; int unk0608; int unk060C; int unk0610; int unk0614;
int unk0618; int unk061C; int unk0620; int unk0624; int unk0628; int unk062C; int unk0630; int unk0634; int unk0638; int unk063C;
int unk0640; int unk0644; int unk0648; int unk064C; int unk0650; int unk0654; int unk0658; int unk065C; int unk0660; int unk0664;
int unk0668; int unk066C; int unk0670; int unk0674; int unk0678; int unk067C; int unk0680; int unk0684; int unk0688; int unk068C;
int unk0690; int unk0694; int unk0698; int unk069C; int unk06A0; int unk06A4; int unk06A8; int unk06AC; int unk06B0; int unk06B4;
int unk06B8; int unk06BC; int unk06C0; int unk06C4; int unk06C8; int unk06CC; int unk06D0; int unk06D4; int unk06D8; int unk06DC;
int unk06E0; int unk06E4; int unk06E8; int unk06EC; int unk06F0; int unk06F4; int unk06F8; int unk06FC; int unk0700; int unk0704;
int unk0708; int unk070C; int unk0710; int unk0714; int unk0718; int unk071C; int unk0720; int unk0724; int unk0728; int unk072C;
int unk0730; int unk0734; int unk0738; int unk073C; int unk0740; int unk0744; int unk0748; int unk074C; int unk0750; int unk0754;
int unk0758; int unk075C; int unk0760; int unk0764; int unk0768; int unk076C; int unk0770; int unk0774; int unk0778; int unk077C;
int unk0780; int unk0784; int unk0788; int unk078C; int unk0790; int unk0794; int unk0798; int unk079C; int unk07A0; int unk07A4;
int unk07A8; int unk07AC; int unk07B0; int unk07B4; int unk07B8; int unk07BC; int unk07C0; int unk07C4; int unk07C8; int unk07CC;
int unk07D0; int unk07D4; int unk07D8; int unk07DC; int unk07E0; int unk07E4; int unk07E8; int unk07EC; int unk07F0; int unk07F4;
int unk07F8; int unk07FC; int unk0800; int unk0804; int unk0808; int unk080C; int unk0810; int unk0814; int unk0818; int unk081C;
int unk0820; int unk0824; int unk0828; int unk082C; int unk0830; int unk0834; int unk0838; int unk083C; int unk0840; int unk0844;
int unk0848; int unk084C; int unk0850; int unk0854; int unk0858; int unk085C; int unk0860; int unk0864; int unk0868; int unk086C;
int unk0870; int unk0874; int unk0878; int unk087C; int unk0880; int unk0884; int unk0888; int unk088C; int unk0890; int unk0894;
int unk0898; int unk089C; int unk08A0; int unk08A4; int unk08A8; int unk08AC; int unk08B0; int unk08B4; int unk08B8; int unk08BC;
int unk08C0; int unk08C4; int unk08C8; int unk08CC; int unk08D0; int unk08D4; int unk08D8; int unk08DC; int unk08E0; int unk08E4;
int unk08E8; int unk08EC; int unk08F0; int unk08F4; int unk08F8; int unk08FC; int unk0900; int unk0904; int unk0908; int unk090C;
int unk0910; int unk0914; int unk0918; int unk091C; int unk0920; int unk0924; int unk0928; int unk092C; int unk0930; int unk0934;
int unk0938; int unk093C; int unk0940; int unk0944; int unk0948; int unk094C; int unk0950; int unk0954; int unk0958; int unk095C;
int unk0960; int unk0964; int unk0968; int unk096C; int unk0970; int unk0974; int unk0978; int unk097C; int unk0980; int unk0984;
int unk0988; int unk098C; int unk0990; int unk0994; int unk0998; int unk099C; int unk09A0; int unk09A4; int unk09A8; int unk09AC;
int unk09B0; int unk09B4; int unk09B8; int unk09BC; int unk09C0; int unk09C4; int unk09C8; int unk09CC; int unk09D0; int unk09D4;
int unk09D8; int unk09DC; int unk09E0; int unk09E4; int unk09E8; int unk09EC; int unk09F0; int unk09F4; int unk09F8; int unk09FC;
int unk0A00; int unk0A04; int unk0A08; int unk0A0C; int unk0A10; int unk0A14; int unk0A18; int unk0A1C; int unk0A20; int unk0A24;
int unk0A28; int unk0A2C; int unk0A30; int unk0A34; int unk0A38; int unk0A3C; int unk0A40; int unk0A44; int unk0A48; int unk0A4C;
int unk0A50; int unk0A54; int unk0A58; int unk0A5C; int unk0A60; int unk0A64; int unk0A68; int unk0A6C; int unk0A70; int unk0A74;
int unk0A78; int unk0A7C; int unk0A80; int unk0A84; int unk0A88; int unk0A8C; int unk0A90; int unk0A94; int unk0A98; int unk0A9C;
int unk0AA0; int unk0AA4; int unk0AA8; int unk0AAC; int unk0AB0; int unk0AB4; int unk0AB8; int unk0ABC; int unk0AC0; int unk0AC4;
int unk0AC8; int unk0ACC; int unk0AD0; int unk0AD4; int unk0AD8; int unk0ADC; int unk0AE0; int unk0AE4; int unk0AE8; int unk0AEC;
int unk0AF0; int unk0AF4; int unk0AF8; int unk0AFC; int unk0B00; int unk0B04; int unk0B08; int unk0B0C; int unk0B10; int unk0B14;
int unk0B18; int unk0B1C; int unk0B20; int unk0B24; int unk0B28; int unk0B2C; int unk0B30; int unk0B34; int unk0B38; int unk0B3C;
int unk0B40; int unk0B44; int unk0B48; int unk0B4C; int unk0B50; int unk0B54; int unk0B58; int unk0B5C; int unk0B60; int unk0B64;
int unk0B68; int unk0B6C; int unk0B70; int unk0B74; int unk0B78; int unk0B7C; int unk0B80; int unk0B84; int unk0B88; int unk0B8C;
int unk0B90; int unk0B94; int unk0B98; int unk0B9C; int unk0BA0; int unk0BA4; int unk0BA8; int unk0BAC; int unk0BB0; int unk0BB4;
int unk0BB8; int unk0BBC; int unk0BC0; int unk0BC4; int unk0BC8; int unk0BCC; int unk0BD0; int unk0BD4; int unk0BD8; int unk0BDC;
int unk0BE0; int unk0BE4; int unk0BE8; int unk0BEC; int unk0BF0; int unk0BF4; int unk0BF8; int unk0BFC; int unk0C00; int unk0C04;
int unk0C08; int unk0C0C; int unk0C10; int unk0C14; int unk0C18; int unk0C1C; int unk0C20; int unk0C24; int unk0C28; int unk0C2C;
int unk0C30; int unk0C34; int unk0C38; int unk0C3C; int unk0C40; int unk0C44; int unk0C48; int unk0C4C; int unk0C50; int unk0C54;
int unk0C58; int unk0C5C; int unk0C60; int unk0C64; int unk0C68; int unk0C6C; int unk0C70; int unk0C74; int unk0C78; int unk0C7C;
int unk0C80; int unk0C84; int unk0C88; int unk0C8C; int unk0C90; int unk0C94; int unk0C98; int unk0C9C; int unk0CA0; int unk0CA4;
int unk0CA8; int unk0CAC; int unk0CB0; int unk0CB4; int unk0CB8; int unk0CBC; int unk0CC0; int unk0CC4; int unk0CC8; int unk0CCC;
int unk0CD0; int unk0CD4; int unk0CD8; int unk0CDC; int unk0CE0; int unk0CE4; int unk0CE8; int unk0CEC; int unk0CF0; int unk0CF4;
int unk0CF8; int unk0CFC; int unk0D00; int unk0D04; int unk0D08; int unk0D0C; int unk0D10; int unk0D14; int unk0D18; int unk0D1C;
int unk0D20; int unk0D24; int unk0D28; int unk0D2C; int unk0D30; int unk0D34; int unk0D38; int unk0D3C; int unk0D40; int unk0D44;
int unk0D48; int unk0D4C; int unk0D50; int unk0D54; int unk0D58; int unk0D5C; int unk0D60; int unk0D64; int unk0D68; int unk0D6C;
int unk0D70; int unk0D74; int unk0D78; int unk0D7C; int unk0D80; int unk0D84; int unk0D88; int unk0D8C; int unk0D90; int unk0D94;
int unk0D98; int unk0D9C; int unk0DA0; int unk0DA4; int unk0DA8; int unk0DAC; int unk0DB0; int unk0DB4; int unk0DB8; int unk0DBC;
int unk0DC0; int unk0DC4; int unk0DC8; int unk0DCC; int unk0DD0; int unk0DD4; int unk0DD8; int unk0DDC; int unk0DE0; int unk0DE4;
int unk0DE8; int unk0DEC; int unk0DF0; int unk0DF4; int unk0DF8; int unk0DFC; int unk0E00; int unk0E04; int unk0E08; int unk0E0C;
int unk0E10; int unk0E14; int unk0E18; int unk0E1C; int unk0E20; int unk0E24; int unk0E28; int unk0E2C; int unk0E30; int unk0E34;
int unk0E38; int unk0E3C; int unk0E40; int unk0E44; int unk0E48; int unk0E4C; int unk0E50; int unk0E54; int unk0E58; int unk0E5C;
int unk0E60; int unk0E64; int unk0E68; int unk0E6C; int unk0E70; int unk0E74; int unk0E78; int unk0E7C; int unk0E80; int unk0E84;
int unk0E88; int unk0E8C; int unk0E90; int unk0E94; int unk0E98; int unk0E9C; int unk0EA0; int unk0EA4; int unk0EA8; int unk0EAC;
int unk0EB0; int unk0EB4; int unk0EB8; int unk0EBC; int unk0EC0; int unk0EC4; int unk0EC8; int unk0ECC; int unk0ED0; int unk0ED4;
int unk0ED8; int unk0EDC; int unk0EE0; int unk0EE4; int unk0EE8; int unk0EEC; int unk0EF0; int unk0EF4; int unk0EF8; int unk0EFC;
int unk0F00; int unk0F04; int unk0F08; int unk0F0C; int unk0F10; int unk0F14; int unk0F18; int unk0F1C; int unk0F20; int unk0F24;
int unk0F28; int unk0F2C; int unk0F30; int unk0F34; int unk0F38; int unk0F3C; int unk0F40; int unk0F44; int unk0F48; int unk0F4C;
int unk0F50; int unk0F54; int unk0F58; int unk0F5C; int unk0F60; int unk0F64; int unk0F68; int unk0F6C; int unk0F70; int unk0F74;
int unk0F78; int unk0F7C; int unk0F80; int unk0F84; int unk0F88; int unk0F8C; int unk0F90; int unk0F94; int unk0F98; int unk0F9C;
int unk0FA0; int unk0FA4; int unk0FA8; int unk0FAC; int unk0FB0; int unk0FB4; int unk0FB8; int unk0FBC; int unk0FC0; int unk0FC4;
int unk0FC8; int unk0FCC; int unk0FD0; int unk0FD4; int unk0FD8; int unk0FDC; int unk0FE0; int unk0FE4; int unk0FE8; int unk0FEC;
int unk0FF0; int unk0FF4; int unk0FF8; int unk0FFC; int unk1000; int unk1004; int unk1008; int unk100C; int unk1010; int unk1014;
int unk1018; int unk101C; int unk1020; int unk1024; int unk1028; int unk102C; int unk1030; int unk1034; int unk1038; int unk103C;
int unk1040; int unk1044; int unk1048; int unk104C; int unk1050; int unk1054; int unk1058; int unk105C; int unk1060; int unk1064;
int unk1068; int unk106C; int unk1070; int unk1074; int unk1078; int unk107C; int unk1080; int unk1084; int unk1088; int unk108C;
int unk1090; int unk1094; int unk1098; int unk109C; int unk10A0; int unk10A4; int unk10A8; int unk10AC; int unk10B0; int unk10B4;
int unk10B8; int unk10BC; int unk10C0; int unk10C4; int unk10C8; int unk10CC; int unk10D0; int unk10D4; int unk10D8; int unk10DC;
int unk10E0; int unk10E4; int unk10E8; int unk10EC; int unk10F0; int unk10F4; int unk10F8; int unk10FC; int unk1100; int unk1104;
int unk1108; int unk110C; int unk1110; int unk1114; int unk1118; int unk111C; int unk1120; int unk1124; int unk1128; int unk112C;
int unk1130; int unk1134; int unk1138; int unk113C; int unk1140; int unk1144; int unk1148; int unk114C; int unk1150; int unk1154;
int unk1158; int unk115C; int unk1160; int unk1164; int unk1168; int unk116C; int unk1170; int unk1174; int unk1178; int unk117C;
int unk1180; int unk1184; int unk1188; int unk118C; int unk1190; int unk1194; int unk1198; int unk119C; int unk11A0; int unk11A4;
int unk11A8; int unk11AC; int unk11B0; int unk11B4; int unk11B8; int unk11BC; int unk11C0; int unk11C4; int unk11C8; int unk11CC;
int unk11D0; int unk11D4; int unk11D8; int unk11DC; int unk11E0; int unk11E4; int unk11E8; int unk11EC; int unk11F0; int unk11F4;
int unk11F8; int unk11FC; int unk1200; int unk1204; int unk1208; int unk120C; int unk1210; int unk1214; int unk1218; int unk121C;
int unk1220; int unk1224; int unk1228; int unk122C; int unk1230; int unk1234; int unk1238; int unk123C; int unk1240; int unk1244;
int unk1248; int unk124C; int unk1250; int unk1254; int unk1258; int unk125C; int unk1260; int unk1264; int unk1268; int unk126C;
int unk1270; int unk1274; int unk1278; int unk127C; int unk1280; int unk1284; int unk1288; int unk128C; int unk1290; int unk1294;
int unk1298; int unk129C; int unk12A0; int unk12A4; int unk12A8; int unk12AC; int unk12B0; int unk12B4; int unk12B8; int unk12BC;
int unk12C0; int unk12C4; int unk12C8; int unk12CC; int unk12D0; int unk12D4; int unk12D8; int unk12DC; int unk12E0; int unk12E4;
int unk12E8; int unk12EC; int unk12F0; int unk12F4; int unk12F8; int unk12FC; int unk1300; int unk1304; int unk1308; int unk130C;
int unk1310; int unk1314; int unk1318; int unk131C; int unk1320; int unk1324; int unk1328; int unk132C; int unk1330; int unk1334;
int unk1338; int unk133C; int unk1340; int unk1344; int unk1348; int unk134C; int unk1350; int unk1354; int unk1358; int unk135C;
int unk1360; int unk1364; int unk1368; int unk136C; int unk1370; int unk1374; int unk1378; int unk137C; int unk1380; int unk1384;
int unk1388; int unk138C; int unk1390; int unk1394; int unk1398; int unk139C; int unk13A0; int unk13A4; int unk13A8; int unk13AC;
int unk13B0; int unk13B4; int unk13B8; int unk13BC; int unk13C0; int unk13C4; int unk13C8; int unk13CC; int unk13D0; int unk13D4;
int unk13D8; int unk13DC; int unk13E0; int unk13E4; int unk13E8; int unk13EC; int unk13F0; int unk13F4; int unk13F8; int unk13FC;
int unk1400; int unk1404; int unk1408; int unk140C; int unk1410; int unk1414; int unk1418; int unk141C; int unk1420; int unk1424;
int unk1428; int unk142C; int unk1430; int unk1434; int unk1438; int unk143C; int unk1440; int unk1444; int unk1448; int unk144C;
int unk1450; int unk1454; int unk1458; int unk145C; int unk1460; int unk1464; int unk1468; int unk146C; int unk1470; int unk1474;
int unk1478; int unk147C; int unk1480; int unk1484; int unk1488; int unk148C; int unk1490; int unk1494; int unk1498; int unk149C;
int unk14A0; int unk14A4; int unk14A8; int unk14AC; int unk14B0; int unk14B4; int unk14B8; int unk14BC; int unk14C0; int unk14C4;
int unk14C8; int unk14CC; int unk14D0; int unk14D4; int unk14D8; int unk14DC; int unk14E0; int unk14E4; int unk14E8; int unk14EC;
int unk14F0; int unk14F4; int unk14F8; int unk14FC; int unk1500; int unk1504; int unk1508; int unk150C; int unk1510; int unk1514;
int unk1518; int unk151C; int unk1520; int unk1524; int unk1528; int unk152C; int unk1530; int unk1534; int unk1538; int unk153C;
int unk1540; int unk1544; int unk1548; int unk154C; int unk1550; int unk1554; int unk1558; int unk155C; int unk1560; int unk1564;
int unk1568; int unk156C; int unk1570; int unk1574; int unk1578; int unk157C; int unk1580; int unk1584; int unk1588; int unk158C;
int unk1590; int unk1594; int unk1598; int unk159C; int unk15A0; int unk15A4; int unk15A8; int unk15AC; int unk15B0; int unk15B4;
int unk15B8; int unk15BC; int unk15C0; int unk15C4; int unk15C8; int unk15CC; int unk15D0; int unk15D4; int unk15D8; int unk15DC;
int unk15E0; int unk15E4; int unk15E8; int unk15EC; int unk15F0; int unk15F4; int unk15F8; int unk15FC; int unk1600; int unk1604;
int unk1608; int unk160C; int unk1610; int unk1614; int unk1618; int unk161C; int unk1620; int unk1624; int unk1628; int unk162C;
int unk1630; int unk1634; int unk1638; int unk163C; int unk1640; int unk1644; int unk1648; int unk164C; int unk1650; int unk1654;
int unk1658; int unk165C; int unk1660; int unk1664; int unk1668; int unk166C; int unk1670; int unk1674; int unk1678; int unk167C;
int unk1680; int unk1684; int unk1688; int unk168C; int unk1690; int unk1694; int unk1698; int unk169C; int unk16A0; int unk16A4;
int unk16A8; int unk16AC; int unk16B0; int unk16B4; int unk16B8; int unk16BC; int unk16C0; int unk16C4; int unk16C8; int unk16CC;
int unk16D0; int unk16D4; int unk16D8; int unk16DC; int unk16E0; int unk16E4; int unk16E8; int unk16EC; int unk16F0; int unk16F4;
int unk16F8; int unk16FC; int unk1700; int unk1704; int unk1708; int unk170C; int unk1710; int unk1714; int unk1718; int unk171C;
int unk1720; int unk1724; int unk1728; int unk172C; int unk1730; int unk1734; int unk1738; int unk173C; int unk1740; int unk1744;
int unk1748; int unk174C; int unk1750; int unk1754; int unk1758; int unk175C; int unk1760; int unk1764; int unk1768; int unk176C;
int unk1770; int unk1774; int unk1778; int unk177C; int unk1780; int unk1784; int unk1788; int unk178C; int unk1790; int unk1794;
int unk1798; int unk179C; int unk17A0; int unk17A4; int unk17A8; int unk17AC; int unk17B0; int unk17B4; int unk17B8; int unk17BC;
int unk17C0; int unk17C4; int unk17C8; int unk17CC; int unk17D0; int unk17D4; int unk17D8; int unk17DC; int unk17E0; int unk17E4;
int unk17E8; int unk17EC; int unk17F0; int unk17F4; int unk17F8; int unk17FC; int unk1800; int unk1804; int unk1808; int unk180C;
int unk1810; int unk1814; int unk1818; int unk181C; int unk1820; int unk1824; int unk1828; int unk182C; int unk1830; int unk1834;
int unk1838; int unk183C; int unk1840; int unk1844; int unk1848; int unk184C; int unk1850; int unk1854; int unk1858; int unk185C;
int unk1860; int unk1864; int unk1868; int unk186C; int unk1870; int unk1874; int unk1878; int unk187C; int unk1880; int unk1884;
int unk1888; int unk188C; int unk1890; int unk1894; int unk1898; int unk189C; int unk18A0; int unk18A4; int unk18A8; int unk18AC;
int unk18B0; int unk18B4; int unk18B8; int unk18BC; int unk18C0; int unk18C4; int unk18C8; int unk18CC; int unk18D0; int unk18D4;
int unk18D8; int unk18DC; int unk18E0; int unk18E4; int unk18E8; int unk18EC; int unk18F0; int unk18F4; int unk18F8; int unk18FC;
int unk1900; int unk1904; int unk1908; int unk190C; int unk1910; int unk1914; int unk1918; int unk191C; int unk1920; int unk1924;
int unk1928; int unk192C; int unk1930; int unk1934; int unk1938; int unk193C; int unk1940; int unk1944; int unk1948; int unk194C;
int unk1950; int unk1954; int unk1958; int unk195C; int unk1960; int unk1964; int unk1968; int unk196C; int unk1970; int unk1974;
int unk1978; int unk197C; int unk1980; int unk1984; int unk1988; int unk198C; int unk1990; int unk1994; int unk1998; int unk199C;
int unk19A0; int unk19A4; int unk19A8; int unk19AC; int unk19B0; int unk19B4; int unk19B8; int unk19BC; int unk19C0; int unk19C4;
int unk19C8; int unk19CC; int unk19D0; int unk19D4; int unk19D8; int unk19DC; int unk19E0; int unk19E4; int unk19E8; int unk19EC;
int unk19F0; int unk19F4; int unk19F8; int unk19FC; int unk1A00; int unk1A04; int unk1A08; int unk1A0C; int unk1A10; int unk1A14;
int unk1A18; int unk1A1C; int unk1A20; int unk1A24; int unk1A28; int unk1A2C; int unk1A30; int unk1A34; int unk1A38; int unk1A3C;
int unk1A40; int unk1A44; int unk1A48; int unk1A4C; int unk1A50; int unk1A54; int unk1A58; int unk1A5C; int unk1A60; int unk1A64;
int unk1A68; int unk1A6C; int unk1A70; int unk1A74; int unk1A78; int unk1A7C; int unk1A80; int unk1A84; int unk1A88; int unk1A8C;
int unk1A90; int unk1A94; int unk1A98; int unk1A9C; int unk1AA0; int unk1AA4; int unk1AA8; int unk1AAC; int unk1AB0; int unk1AB4;
int unk1AB8; int unk1ABC; int unk1AC0; int unk1AC4; int unk1AC8; int unk1ACC; int unk1AD0; int unk1AD4; int unk1AD8; int unk1ADC;
int unk1AE0; int unk1AE4; int unk1AE8; int unk1AEC; int unk1AF0; int unk1AF4; int unk1AF8; int unk1AFC; int unk1B00; int unk1B04;
int unk1B08; int unk1B0C; int unk1B10; int unk1B14; int unk1B18; int unk1B1C; int unk1B20; int unk1B24; int unk1B28; int unk1B2C;
int unk1B30; int unk1B34; int unk1B38; int unk1B3C; int unk1B40; int unk1B44; int unk1B48; int unk1B4C; int unk1B50; int unk1B54;
int unk1B58; int unk1B5C; int unk1B60; int unk1B64; int unk1B68; int unk1B6C; int unk1B70; int unk1B74; int unk1B78; int unk1B7C;
int unk1B80; int unk1B84; int unk1B88; int unk1B8C; int unk1B90; int unk1B94; int unk1B98; int unk1B9C; int unk1BA0; int unk1BA4;
int unk1BA8; int unk1BAC; int unk1BB0; int unk1BB4; int unk1BB8; int unk1BBC; int unk1BC0; int unk1BC4; int unk1BC8; int unk1BCC;
int unk1BD0; int unk1BD4; int unk1BD8; int unk1BDC; int unk1BE0; int unk1BE4; int unk1BE8; int unk1BEC; int unk1BF0; int unk1BF4;
int unk1BF8; int unk1BFC; int unk1C00; int unk1C04; int unk1C08; int unk1C0C; int unk1C10; int unk1C14; int unk1C18; int unk1C1C;
int unk1C20; int unk1C24; int unk1C28; int unk1C2C; int unk1C30; int unk1C34; int unk1C38; int unk1C3C; int unk1C40; int unk1C44;
int unk1C48; int unk1C4C; int unk1C50; int unk1C54; int unk1C58; int unk1C5C; int unk1C60; int unk1C64; int unk1C68; int unk1C6C;
int unk1C70; int unk1C74; int unk1C78; int unk1C7C; int unk1C80; int unk1C84; int unk1C88; int unk1C8C; int unk1C90; int unk1C94;
int unk1C98; int unk1C9C; int unk1CA0; int unk1CA4; int unk1CA8; int unk1CAC; int unk1CB0; int unk1CB4; int unk1CB8; int unk1CBC;
int unk1CC0; int unk1CC4; int unk1CC8; int unk1CCC; int unk1CD0; int unk1CD4; int unk1CD8; int unk1CDC; int unk1CE0; int unk1CE4;
int unk1CE8; int unk1CEC; int unk1CF0; int unk1CF4; int unk1CF8; int unk1CFC; int unk1D00; int unk1D04; int unk1D08; int unk1D0C;
int unk1D10; int unk1D14; int unk1D18; int unk1D1C; int unk1D20; int unk1D24; int unk1D28; int unk1D2C; int unk1D30; int unk1D34;
int unk1D38; int unk1D3C; int unk1D40; int unk1D44; int unk1D48; int unk1D4C; int unk1D50; int unk1D54; int unk1D58; int unk1D5C;
int unk1D60; int unk1D64; int unk1D68; int unk1D6C; int unk1D70; int unk1D74; int unk1D78; int unk1D7C; int unk1D80; int unk1D84;
int unk1D88; int unk1D8C; int unk1D90; int unk1D94; int unk1D98; int unk1D9C; int unk1DA0; int unk1DA4; int unk1DA8; int unk1DAC;
int unk1DB0; int unk1DB4; int unk1DB8; int unk1DBC; int unk1DC0; int unk1DC4; int unk1DC8; int unk1DCC; int unk1DD0; int unk1DD4;
int unk1DD8; int unk1DDC; int unk1DE0; int unk1DE4; int unk1DE8; int unk1DEC; int unk1DF0; int unk1DF4; int unk1DF8; int unk1DFC;
int unk1E00; int unk1E04; int unk1E08; int unk1E0C; int unk1E10; int unk1E14; int unk1E18; int unk1E1C; int unk1E20; int unk1E24;
int unk1E28; int unk1E2C; int unk1E30; int unk1E34; int unk1E38; int unk1E3C; int unk1E40; int unk1E44; int unk1E48; int unk1E4C;
int unk1E50; int unk1E54; int unk1E58; int unk1E5C; int unk1E60; int unk1E64; int unk1E68; int unk1E6C; int unk1E70; int unk1E74;
int unk1E78; int unk1E7C; int unk1E80; int unk1E84; int unk1E88; int unk1E8C; int unk1E90; int unk1E94; int unk1E98; int unk1E9C;
int unk1EA0; int unk1EA4; int unk1EA8; int unk1EAC; int unk1EB0; int unk1EB4; int unk1EB8; int unk1EBC; int unk1EC0; int unk1EC4;
int unk1EC8; int unk1ECC; int unk1ED0; int unk1ED4; int unk1ED8; int unk1EDC; int unk1EE0; int unk1EE4; int unk1EE8; int unk1EEC;
int unk1EF0; int unk1EF4; int unk1EF8; int unk1EFC; int unk1F00; int unk1F04; int unk1F08; int unk1F0C; int unk1F10; int unk1F14;
int unk1F18; int unk1F1C; int unk1F20; int unk1F24; int unk1F28; int unk1F2C; int unk1F30; int unk1F34; int unk1F38; int unk1F3C;
int unk1F40; int unk1F44; int unk1F48; int unk1F4C; int unk1F50; int unk1F54; int unk1F58; int unk1F5C; int unk1F60; int unk1F64;
int unk1F68; int unk1F6C; int unk1F70; int unk1F74; int unk1F78; int unk1F7C; int unk1F80; int unk1F84; int unk1F88; int unk1F8C;
int unk1F90; int unk1F94; int unk1F98; int unk1F9C; int unk1FA0; int unk1FA4; int unk1FA8; int unk1FAC; int unk1FB0; int unk1FB4;
int unk1FB8; int unk1FBC; int unk1FC0; int unk1FC4; int unk1FC8; int unk1FCC; int unk1FD0; int unk1FD4; int unk1FD8; int unk1FDC;
int unk1FE0; int unk1FE4; int unk1FE8; int unk1FEC; int unk1FF0; int unk1FF4; int unk1FF8; int unk1FFC; int unk2000; int unk2004;
int unk2008; int unk200C; int unk2010; int unk2014; int unk2018; int unk201C; int unk2020; int unk2024; int unk2028; int unk202C;
int unk2030; int unk2034; int unk2038; int unk203C; int unk2040; int unk2044; int unk2048; int unk204C; int unk2050; int unk2054;
int unk2058; int unk205C; int unk2060; int unk2064; int unk2068;
 BucketC* buckets; unsigned count; int unk2074,unk2078,unk207c,unk2080,unk2084; CacheC cache;
 bool FUN_005c6320(QueryC*,OutputC*);
 bool FUN_005c4a10(const LocationC&,const V3C&,LocationC&);
 bool FUN_005c50a0(const LocationC&,const CircleC&,MotionC,LocationC&);
 float FUN_005c46e0(NodeC*,MotionC,NodeC*);
 float FUN_005c48c0(NodeC*,const V3C&,const V3C&,NodeC*);
 int FUN_005c5e80(unsigned,float,ResultC**);
 void FUN_005c4650(ResultC*,NodeC*,int,unsigned);
 unsigned MakeKey(NodeC* node,int endpoint) { return (unsigned)node+endpoint; }
};
typedef char CheckNode[(sizeof(NodeC)==0x30)?1:-1];
typedef char CheckMotion[(sizeof(MotionC)==20)?1:-1];
typedef char CheckLocation[(sizeof(LocationC)==24)?1:-1];
typedef char CheckQuery[(offsetof(QueryC,parent)==0x54)?1:-1];
typedef char CheckBuckets[(offsetof(SearchC,buckets)==0x206c)?1:-1];
typedef char CheckCache[(offsetof(SearchC,cache)==0x2088)?1:-1];
typedef char CheckRootRef[(offsetof(RootC,ref)==0x1c)?1:-1];

// Same-unit arc traversal: copy the input location before passing local storage to projection.
__declspec(noinline) bool SearchC::FUN_005c50a0(const LocationC& start,const CircleC& circle,MotionC arc,LocationC& output) {
 const float stepAngle = arc.direction == 0 ? 0.2617993950843811f : -0.2617993950843811f;
 const V2C rotation(stepAngle);
 V2C direction=arc.from;
 direction.Left(rotation);
 LocationC current=start;
 V3C point=circle.position+arc.from.ToPoint(circle.radius);
 LocationC next;
 unsigned steps=0;
 while(arc.Contains(direction)) {
  if(steps>=24) break;
  current.flags=-1;
  if(!FUN_005c4a10(current,point,next)) { output=next; return false; }
  current=next;
  ++steps;
  direction.Left(rotation);
  point=circle.position+direction.ToPoint(circle.radius);
 }
 if(steps==24) { output=next; return false; }
 current.flags=-1;
 bool success=FUN_005c4a10(current,circle.position+arc.to.ToPoint(circle.radius),next);
 output=next;
 return success;
}

// pdb: NavMeshPOVSearch::GetNodeConnections | NavMeshPOVSearch.obj | fnv360_0822_retail, vtable, medium
// pdb params: apNode, apRetNodes
bool SearchC::FUN_005c6320(QueryC* query,OutputC* output) {
 const NodePartC& parentNode=query->GetNode();
 const LinkPartC& parentLink=query->GetLink();
 unsigned limit=count;
 for(unsigned layer=parentNode.bucket;layer<limit;layer++) {
  BucketC& bucket=buckets[layer];
  unsigned nodeCount=bucket.count;
  for(unsigned ni=0;ni<nodeCount;ni++) {
   NodeC* node=bucket.nodes[ni];
   if(node==parentNode.node) continue;
   if(query->GetParent() && node==query->GetParent()->GetNode().node) continue;
   V3C toNode=node->position-parentNode.node->position;
   int n;
   float horizontal=toNode.SqrLengthXY();
   {
    float vertical=toNode.z*toNode.z;
    if(vertical>horizontal*DAT_00dc8080*DAT_00dc8080) continue;
   }
   CircleC a(parentNode.node->position,parentNode.node->radius);
   CircleC b(node->position,node->radius);
   TangentsC tangents;
   n=FUN_005dea40(a,b,parentNode.direction,tangents);
   if(n==0) continue;
   for(int ti=0;ti<n;ti++) {
    if(query->GetParent()) {
     V2C plus;
     plus=parentLink.forward;
     int direction=parentNode.direction;
     if(direction==0) plus.Left(V2C(4.712389f));
     else plus.Right(V2C(4.712389f));
     MotionC wedge(plus,parentLink.forward,direction);
     if(wedge.Contains(tangents.entries[ti].from)) continue;
    }
    V3C cross1=DAT_0108ec68;
    V3C cross2=DAT_0108ec68;
    V3C delta=(b.position+tangents.entries[ti].to.ToPoint(b.radius)-a.position)-tangents.entries[ti].from.ToPoint(a.radius);
    if(parentNode.node->kind!=3 && node->kind==0) {
     const float threshold=1.0f;
     toNode.z=0.0f;
     V3C edge1=node->sideA;
     edge1.z=0.0f;
     V3C edge2=node->sideB;
     edge2.z=0.0f;
     cross1=edge1.Cross(delta);
     cross2=edge2.Cross(delta);
     if(cross1.z>threshold && cross2.z>threshold) continue;
    }
    if(parentNode.node->kind!=3 && node->kind==0) {
     if(tangents.entries[ti].endpoint==0) { if(cross2.z<g_thresholdB) continue; }
     else { if(cross1.z<g_thresholdB) continue; }
    }
    int direction=parentNode.direction;
    MotionC arc(parentLink.forward,tangents.entries[ti].from,direction);
    LocationC parentEntry;
    if(!query->GetParent()) {
     RootGuardC root;
     unsigned short tag;
     if(!cache.FUN_005fc8f0(root,tag)) return false;
     parentEntry.root=root.Get();
     parentEntry.tag=tag;
     parentEntry.flags=-1;
     parentEntry.position=cache.GetPosition();
    } else parentEntry=parentLink.location;
    float arcFactor=1.0f;
    LocationC entry;
    if(!query->GetParent()) entry=parentEntry;
    else {
     if(!FUN_005c50a0(parentEntry,a,MotionC(arc.from,arc.to,direction),entry)) {
      if(DAT_0107454c) FUN_005c5410(a.position,a.radius,arc.from,arc.to,direction,&DAT_00f73260);
      continue;
     }
     if(AbsF((entry.position-a.position).z)>=DAT_00de7c24) continue;
     arcFactor=FUN_005c46e0(parentNode.node,MotionC(arc.from,arc.to,direction),node);
     if(arcFactor==3.402823466e+38F) {
      if(DAT_0107454c) FUN_005c5410(a.position,a.radius,arc.from,arc.to,direction,&DAT_00f73230);
      continue;
     }
    }
    LocationC exitLocation;
    V3C exitPoint=b.position+tangents.entries[ti].to.ToPoint(b.radius);
    if(!FUN_005c4a10(entry,exitPoint,exitLocation)) {
     if(DAT_0107454c) FUN_005c4d50(entry.position,exitLocation.position,&DAT_00f73260);
     continue;
    }
    if(AbsF((exitLocation.position-b.position).z)>=DAT_00de7c24) continue;
    float segmentFactor=FUN_005c48c0(parentNode.node,entry.position,exitLocation.position,node);
    if(segmentFactor==3.402823466e+38F) {
     if(DAT_0107454c) FUN_005c4d50(entry.position,exitLocation.position,&DAT_00f73230);
     continue;
    }
    if(DAT_0107454c) {
     if(query->GetParent()) FUN_005c5410(a.position,a.radius,arc.from,arc.to,direction,&DAT_00f73240);
     FUN_005c4d50(entry.position,exitLocation.position,&DAT_00f73240);
    }
    float cost=query->GetCost();
    if(query->GetParent()) cost+=arc.FUN_005c43e0(parentNode.node->radius)*(node->extraCost+arcFactor+segmentFactor);
    cost+=(exitLocation.position-entry.position).Length();
    ResultC* out;
    int action=FUN_005c5e80(MakeKey(node,tangents.entries[ti].endpoint),cost,&out);
    ResultC* result=out;
    switch(action) {
    case 0: FUN_005c4650(result,node,tangents.entries[ti].endpoint,layer);
    case 1:
     result->locationA=entry;
     result->locationB=exitLocation;
     result->from=tangents.entries[ti].from;
     result->to=tangents.entries[ti].to;
     result->SetCost(cost);
     output->Add(result);
     break;
    }
   }
  }
 }
 return true;
}
}   // namespace f3m_005c6320

// @f3 0x005d31c0 (community match, verified in this file)
#include <math.h>
extern float DAT_00e00ea4;
extern float DAT_00e00ea0;
namespace f3m_005d31c0 {

// PathSmootherPOVSearch::DoubleCheckArcAgainstNavMesh (the New Vegas twin's name): the arc is checked against the
// nav mesh once on a sphere shrunk by 0.9 actor radii and once on one grown by the same amount.
namespace f3m_005d31c0 {

struct Point {
    float x, y, z;
    Point() {}
    Point(float a, float b, float c) : x(a), y(b), z(c) {}
    Point operator+(const Point& p) const
    {
        // The named alias emits nothing; it gives the y lane the target's x87 operand order (a guess at the source).
        const Point& a = *this;
        return Point(a.x + p.x, a.y + p.y, a.z + p.z);
    }
};

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float ax, float ay) : x(ax), y(ay) {}
    Vec2(const Vec2& o) : x(o.x), y(o.y) {}
    Vec2& operator=(const Vec2& o)
    {
        x = o.x;
        y = o.y;
        return *this;
    }
    bool FUN_005c42b0(const Vec2& other) const;
};

inline Vec2 Rotate(const Vec2& v, const Vec2& rot)
{
    return Vec2(v.x * rot.x - v.y * rot.y, v.x * rot.y + v.y * rot.x);
}

inline Vec2 Relative(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x * b.x + a.y * b.y, b.y * a.x - a.y * b.x);
}

inline Point Scale(const Vec2& v, float f)
{
    return Point(v.x * f, v.y * f, 0.0f);
}

class Sphere {
public:
    // stand-in layout
    Point center;
    float radius;
};

// CircularArc: start and end directions and the turning side, passed by value.
class CircularArc {
public:
    Vec2 from, to;
    int side;
    CircularArc(const CircularArc& o) : from(o.from), to(o.to), side(o.side) {}
};

// NavMeshEdgePoint
class NavMeshEdgePoint {
public:
    void* triangle;
    unsigned short index;
    int edge;
    Point point;
};

struct Request {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;
    int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64;
    float radius;
};


struct PathSmootherPOVSearch {
    char unk[0x2058];
    Request* request;

    float GetRadius() const { return request->radius; }
    bool FUN_005d2160(NavMeshEdgePoint& edge, const Point& point, NavMeshEdgePoint& hit, float& t);
    bool FUN_005d2e50(const NavMeshEdgePoint& start, Sphere& sphere, CircularArc arc, NavMeshEdgePoint* out);
    bool FUN_005d31c0(const NavMeshEdgePoint& edge, Sphere& sphere, CircularArc arc);
};

// FUN_005d2e50 is defined just before this function in the original file; its body (as matched in the unit) must be
// visible here: with it the compiler sees that the out edge point does not escape, so it shares the 24-byte slot of the
// probe points and the frame is 0x48 bytes.
bool PathSmootherPOVSearch::FUN_005d2e50(const NavMeshEdgePoint& start, Sphere& sphere, CircularArc arc, NavMeshEdgePoint* out)
{
    float angle = arc.side == 0 ? DAT_00e00ea4 : DAT_00e00ea0;
    Vec2 rot(cosf(angle), sinf(angle));
    NavMeshEdgePoint loc = start;
    Vec2 dir = Rotate(arc.from, rot);
    Point off = Scale(dir, sphere.radius);
    Point pos(sphere.center.x + off.x, sphere.center.y + off.y, sphere.center.z + 0.0);
    NavMeshEdgePoint result;
    float dist;
    unsigned int i = 0;
    for (;;) {
        const Vec2* limit = 0;
        const Vec2* origin = 0;
        if (arc.side == 0) {
            origin = &arc.from;
            limit = &arc.to;
        } else {
            origin = &arc.to;
            limit = &arc.from;
        }
        if (!Relative(*origin, dir).FUN_005c42b0(Relative(*origin, *limit)) || i >= 24)
            break;
        loc.edge = -1;
        if (!FUN_005d2160(loc, pos, result, dist)) {
            *out = result;
            return false;
        }
        loc = result;
        i++;
        dir = Rotate(dir, rot);
        Point off2 = Scale(dir, sphere.radius);
        pos = Point(sphere.center.x + off2.x, sphere.center.y + off2.y, sphere.center.z + 0.0);
    }
    if (i == 24) {
        *out = result;
        return false;
    }
    loc.edge = -1;
    Vec2 t(arc.to.x, arc.to.y);
    Point off3 = Scale(t, sphere.radius);
    if (!FUN_005d2160(loc, Point(sphere.center.x + off3.x, sphere.center.y + off3.y, sphere.center.z + 0.0), result, dist)) {
        *out = result;
        return false;
    }
    *out = result;
    return true;
}

// pdb: PathSmootherPOVSearch::DoubleCheckArcAgainstNavMesh | PathSmootherPOV.obj | fnv360_0721_beta, call_gap, low
// pdb params: aEntryLocation, aSphere, aArc
bool PathSmootherPOVSearch::FUN_005d31c0(const NavMeshEdgePoint& edge, Sphere& sphere, CircularArc arc)
{
    float radius;
    if (arc.side == 0)
        radius = sphere.radius - GetRadius() * 0.9f;
    else
        radius = GetRadius() * 0.9f + sphere.radius;
    Sphere test;
    test.center = sphere.center;
    float x = arc.from.x * radius;
    float y = arc.from.y * radius;
    test.radius = radius;
    NavMeshEdgePoint hit;
    float t;
    if (!FUN_005d2160(const_cast<NavMeshEdgePoint&>(edge), sphere.center + Point(x, y, 0.0f), hit, t))
        return false;
    NavMeshEdgePoint out;
    if (!FUN_005d2e50(hit, test, arc, &out))
        return false;

    if (arc.side == 0)
        radius = GetRadius() * 0.9f + sphere.radius;
    else
        radius = sphere.radius - GetRadius() * 0.9f;
    test.center = sphere.center;
    float x2 = arc.from.x * radius;
    float y2 = arc.from.y * radius;
    test.radius = radius;
    if (!FUN_005d2160(const_cast<NavMeshEdgePoint&>(edge), sphere.center + Point(x2, y2, 0.0f), hit, t))
        return false;
    if (FUN_005d2e50(hit, test, arc, &out))
        return true;
    return false;
}

}
}   // namespace f3m_005d31c0

// @f3 0x005dbc20 (community match, verified in this file)
extern unsigned int DAT_00e27ed4;
namespace f3m_005dbc20 {

namespace fn_005dbc20 {

struct ScrapHeapBuffer
{
    char* m_pHeapBase;
    char* m_pCurrentPosition;
    char* m_pBufferLimit;
    void* m_pBufferHeader;
    void* ScrapHeap_Allocate(unsigned int size, unsigned int align);
};

struct AStarNode
{
    float m_fPathingCostCur;
    float m_fCost;
    const void* ObjectResolver;
    void* m_kOpenListLink;
    AStarNode* m_pParentNode;
    AStarNode** m_ppPreviousNodeLink;
    AStarNode* pListNode;
    unsigned int iKey;
    AStarNode* m_pNextHashNode;
};

struct AStarNodeFresh : AStarNode
{
    AStarNodeFresh()
    {
        m_pParentNode = 0;
        m_fPathingCostCur = 0.0f;
        m_ppPreviousNodeLink = 0;
        m_fCost = 0.0f;
        pListNode = 0;
        iKey = 0;
        m_pNextHashNode = 0;
    }
    static void* operator new(unsigned int size, ScrapHeapBuffer& pool) throw()
    {
        return pool.ScrapHeap_Allocate(size, ::DAT_00e27ed4);
    }
};

struct AStarOpenList
{
    float m_fValue;
    AStarNode* m_ppNodes[20];
    void FUN_005dba60(AStarNode* node);
};

enum
{
    ASTARNODE_CREATED = 0,
    ASTARNODE_UPDATED = 1,
    ASTARNODE_UNCHANGED = 2
};

inline unsigned int ChooseBucket(unsigned int nKey)
{
    return nKey % 2039;
}

inline AStarNode* CarveNode(ScrapHeapBuffer& pool)
{
    return new (pool) AStarNodeFresh;
}

class AStarSearch
{
public:
    virtual ~AStarSearch();
    int FUN_005dbc20(unsigned int nKey, float fWeight, AStarNode*& rNode);
    ScrapHeapBuffer m_kNodeAllocator;
    AStarNode* m_ppHashNodes[2039];
    unsigned int iCount;
    AStarOpenList AStarBucketQueue;
    AStarNode* m_pFirstNode;
    AStarNode* m_pCurrentNode;
    AStarNode* m_pLastCreatedNode;
    bool m_bUseBestNode;
};

// pdb: AStarSearch<CombatPlanNode *,CombatPlanLink *>::GetOrCreateAStarNode | CombatPlanner.obj | fnv360_0822_retail, caller, low
// pdb params: aiKey, afCost, aRetNode
int AStarSearch::FUN_005dbc20(unsigned int nKey, float fWeight, AStarNode*& rNode)
{
    AStarNode** ppSlot = &m_ppHashNodes[ChooseBucket(nKey)];
    if (*ppSlot)
    {
        if ((*ppSlot)->iKey == nKey)
        {
            if ((*ppSlot)->m_fPathingCostCur > fWeight)
            {
                rNode = *ppSlot;
                AStarBucketQueue.FUN_005dba60(rNode);
                rNode->m_fPathingCostCur = fWeight;
                return ASTARNODE_UPDATED;
            }
            else
                return ASTARNODE_UNCHANGED;
        }
        else
        {
            AStarNode* pWalk = (*ppSlot)->m_pNextHashNode;
            while (pWalk)
            {
                if (pWalk->iKey == nKey)
                {
                    if (pWalk->m_fPathingCostCur > fWeight)
                    {
                        rNode = pWalk;
                        AStarBucketQueue.FUN_005dba60(rNode);
                        rNode->m_fPathingCostCur = fWeight;
                        return ASTARNODE_UPDATED;
                    }
                    else
                        return ASTARNODE_UNCHANGED;
                }
                pWalk = pWalk->m_pNextHashNode;
            }
        }
    }
    rNode = CarveNode(m_kNodeAllocator);
    rNode->iKey = nKey;
    rNode->m_fPathingCostCur = fWeight;
    rNode->m_pNextHashNode = *ppSlot;
    *ppSlot = rNode;
    return ASTARNODE_CREATED;
}

} // namespace fn_005dbc20
}   // namespace f3m_005dbc20

// @f3 0x005d25a0 (community match, verified in this file)
#include <math.h>
#include <float.h>
namespace f3m_005d25a0 {

namespace S5d25a0_ {

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator-(const NiPoint3& o) const { return NiPoint3(x - o.x, y - o.y, z - o.z); }
    NiPoint3 operator+(const NiPoint3& o) const { return NiPoint3(x + o.x, y + o.y, z + o.z); }
    NiPoint3 operator*(float s) const { NiPoint3 r(x * s, y * s, z * s); return r; }
    float FUN_004a7290() const { return x * x + y * y + z * z; }
    float Length() const { return sqrt(x * x + y * y + z * z); }
    __declspec(noinline) void FUN_00468d00();
};

__declspec(noinline) void NiPoint3::FUN_00468d00()
{
    float length = sqrt(x * x + y * y + z * z);
    if (length > 1e-06f)
    {
        float recip = 1.0f / length;
        x *= recip;
        y *= recip;
        z *= recip;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}

struct UpAxis
{
    static const NiPoint3 DAT_00f725b0;
};

inline NiPoint3 Cross(const NiPoint3& a, const NiPoint3& b)
{
    return NiPoint3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

inline NiPoint3 Negate(const NiPoint3& p)
{
    return NiPoint3(-p.x, -p.y, -p.z);
}

class NavMesh
{
  public:
    bool FUN_005bdc10(unsigned short tri, const NiPoint3& pos, float a, float b, float& height);
};

class NavMeshEdgePoint
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
    NiPoint3 Location;
    NavMeshEdgePoint() {}
};

class PathingRequest
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    float m_fRadius;
    float GetRadius() { return m_fRadius; }
};

class AStarNodeAllocator
{
  public:
    unsigned int m_uiBlock;
    unsigned int m_uiCount;
    unsigned int m_uiFree;
    unsigned int m_uiSize;
};

class AStarNodeHashTable
{
  public:
    void* m_ppNodes[2039];
    unsigned int iCount;
};

class AStarOpenList
{
  public:
    float m_fValue;
    void* m_ppNodes[20];
};

class PathSmootherPOVSearch
{
  public:
    void* vtable;
    AStarNodeAllocator m_kNodeAllocator;
    AStarNodeHashTable m_kNodeHashTable;
    AStarOpenList AStarBucketQueue;
    void* m_pFirstNode;
    void* m_pCurrentNode;
    void* m_pLastCreatedNode;
    bool m_bUseBestNode;
    PathingRequest* pRequest;
    void* m_pOutputSolution;
    NiPoint3 m_kPathStartPosition;
    NiPoint3 m_kGoalPosition;
    bool m_bUnderwaterPath;

    bool FUN_005d2160(NavMeshEdgePoint& from, const NiPoint3& to, NavMeshEdgePoint& result, float& distance);
    bool FUN_005d25a0(const NavMeshEdgePoint& origin, const NiPoint3& target, NavMeshEdgePoint* hit,
                      bool startArc, bool endArc, float& destinationHeight);
};

// pdb: PathSmootherPOVSearch::TripleCheckSegmentAgainstNavMesh | PathSmootherPOV.obj | fnv360_0822_retail, objrun, medium
// pdb params: aStartLocation, aEndLocation, apReturnLocation, abStartNode, abGoalNode, afRetPercentPreferred
bool PathSmootherPOVSearch::FUN_005d25a0(const NavMeshEdgePoint& origin, const NiPoint3& target,
                                         NavMeshEdgePoint* hit, bool startArc, bool endArc,
                                         float& destinationHeight)
{
    if (!FUN_005d2160(const_cast<NavMeshEdgePoint&>(origin), target, *hit, destinationHeight))
        return false;

    if (m_bUnderwaterPath)
    {
        hit->Location.z = target.z;
        return true;
    }

    NiPoint3 delta = target - origin.Location;
    NiPoint3 direction = delta;
    direction.FUN_00468d00();

    float spread;
    if (pRequest->GetRadius() * pRequest->GetRadius() > delta.FUN_004a7290())
        spread = delta.Length() * static_cast<double>(0.9f);
    else
        spread = pRequest->GetRadius() * static_cast<double>(0.9f);

    NiPoint3 advance = direction * spread;
    NiPoint3 lateral = Cross(UpAxis::DAT_00f725b0, direction);

    NiPoint3 startLeft, endLeft, startRight, endRight;
    if (startArc)
    {
        startLeft = ((lateral * spread) * 0.5f) + (advance * 0.5f);
        startRight = ((Negate(lateral) * spread) * 0.5f) + (advance * 0.5f);
    }
    else
    {
        startLeft = (lateral * pRequest->GetRadius()) * 0.9f;
        startRight = (Negate(lateral) * pRequest->GetRadius()) * 0.9f;
    }

    if (endArc)
    {
        endLeft = ((lateral * spread) * 0.5f) - (advance * 0.5f);
        endRight = ((Negate(lateral) * spread) * 0.5f) - (advance * 0.5f);
    }
    else
    {
        endLeft = (lateral * pRequest->GetRadius()) * 0.9f;
        endRight = (Negate(lateral) * pRequest->GetRadius()) * 0.9f;
    }

    {
        NavMeshEdgePoint result;
        float probeDistance;
        if (!FUN_005d2160(const_cast<NavMeshEdgePoint&>(origin), origin.Location + startLeft, result, probeDistance))
            return false;
        {
            NavMeshEdgePoint endResult;
            if (!FUN_005d2160(result, target + endLeft, endResult, probeDistance))
                return false;
        }
        if (!FUN_005d2160(const_cast<NavMeshEdgePoint&>(origin), origin.Location + startRight, result, probeDistance))
            return false;
        {
            NavMeshEdgePoint endResult;
            if (!FUN_005d2160(result, target + endRight, endResult, probeDistance))
                return false;
        }
    }

    if (!endArc)
    {
        float savedHeight = hit->Location.z;
        hit->m_pLocationNavMesh->FUN_005bdc10(hit->m_usTriangleID, hit->Location, FLT_MAX, FLT_MAX, savedHeight);
        hit->Location.z = savedHeight;
    }
    return true;
}

}
}   // namespace f3m_005d25a0
