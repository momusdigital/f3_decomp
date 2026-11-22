#include <math.h>
#include <intrin.h>
// src/f3staging/f3blk_007a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007b7eb0 (community match, verified in this file)
namespace f3m_007b7eb0 {
namespace task1659 {
struct NiPoint3 {float x,y,z;};
struct S_009a8460_Actor {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
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
virtual bool vfn_0100();
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
virtual void v85();
virtual void v86();
virtual void v87();
virtual void v88();
virtual void v89();
virtual void v90();
virtual void v91();
virtual void v92();
virtual void v93();
virtual void v94();
virtual void v95();
virtual void v96();
virtual void v97();
virtual void v98();
virtual void v99();
virtual void v100();
virtual void v101();
virtual void v102();
virtual void v103();
virtual void v104();
virtual void v105();
virtual void v106();
virtual void v107();
virtual void v108();
virtual void v109();
virtual void v110();
virtual void v111();
virtual void v112();
virtual void v113();
virtual void v114();
virtual void v115();
virtual void v116();
virtual void v117();
virtual NiPoint3* vfn_01d8(NiPoint3*);
virtual NiPoint3* vfn_01dc(NiPoint3*);
virtual void v120();
virtual void v121();
virtual void v122();
virtual void v123();
virtual void v124();
virtual void v125();
virtual void v126();
virtual void v127();
virtual void v128();
virtual void v129();
virtual void v130();
virtual void v131();
virtual void v132();
virtual void v133();
virtual void v134();
virtual void v135();
virtual void v136();
virtual void v137();
virtual void v138();
virtual bool vfn_022c(int);
virtual bool vfn_0230();
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
int state;
unsigned int FUN_006f58b0();
bool FUN_004997b0(){return (FUN_006f58b0()&0x400)!=0 && (FUN_006f58b0()&0x800)==0;}
float FUN_006fb050(int);float FUN_006f5de0();float FUN_004e6d80();
bool FUN_00579670(){return state==9;}
};
// @fnv 0x009a8460
// pdb: CombatUtilities::GetTargetFiringZOffset | CombatUtilities.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apTarget, aeTargetSegmentInView, abIgnoreCrouch
float __cdecl FUN_007b7eb0(S_009a8460_Actor* actor, int type, bool flag)
{
    float f;
    S_009a8460_Actor* act;
    bool b;

    if (actor->vfn_0100())
    {
        act = actor;
        b = act->FUN_004997b0() && !flag;
        f = b ? act->FUN_006fb050(0) : act->FUN_006f5de0();

        if (act->vfn_0230() || act->FUN_00579670() || act->vfn_022c(0))
        {
            return f * 0.1f;
        }

        switch (type)
        {
        case 2:
            return (float)(b ? f * 0.9f : f * 0.75);
            break;
        case 1:
        case 3:
            return f * 0.5;
            break;
        case 0:
            return f * 0.25;
            break;
        default:
            break;
        }
    }
    else
    {
        NiPoint3 p2;
        NiPoint3 p1;
        return (actor->vfn_01dc(&p2)->z - actor->vfn_01d8(&p1)->z) * actor->FUN_004e6d80() * 0.5;
    }

    return 0.0f;
}

}
}   // namespace f3m_007b7eb0

// @f3 0x007b60d0 (community match, verified in this file)
namespace f3m_007b60d0 {
namespace q7b60d0 {
struct Ref;
struct Query {
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
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void Remove(Ref*);
};
struct Ref {
virtual void v00();virtual void DeleteThis();
long count;int unk08,unk0c,unk10,unk14;Query* owner;
void IncRefCount(){InterlockedIncrement(&count);}
void DecRefCount(){if(!InterlockedDecrement(&count)) DeleteThis();}
};
struct FUN_007b60d0 {
int unk00,unk04,unk08,unk0c,unk10;NiPointer<Ref> ref;
~FUN_007b60d0();
};
// pdb: CombatThreat::~CombatThreat | CombatThreatMap.obj | fnv360_0822_retail, call_seq, medium
FUN_007b60d0::~FUN_007b60d0() {
Ref* r=ref; if(r && r->owner) r->owner->Remove(r);
}
}
}   // namespace f3m_007b60d0

// @f3 0x007b76e0 (community match, verified in this file)
namespace f3m_007b76e0 {
namespace f3m_007b76e0
{
struct __declspec(align(16)) Vector4 { float x, y, z, w; };
struct RayOutput
{
    Vector4 normal;
    float fraction;
    int extraInfo;
    unsigned int unk18, unk1C;
    unsigned int shapeKeys[8];
    unsigned int keyIndex, unk44, unk48, unk4C;
    void* collidable;
    unsigned int unk54, unk58, unk5C;
    RayOutput() : fraction(1.0f), extraInfo(-1) {}
    void Reset() { fraction = 1.0f; collidable = 0; extraInfo = -1; keyIndex = 0; shapeKeys[0] = 0xffffffff; }
};
struct RayCollector
{
    virtual ~RayCollector();
    float earlyOut;
};
struct Closest : RayCollector
{
    RayOutput output;
    Closest() { output.Reset(); earlyOut = 1.0f; }
    virtual ~Closest();
};
struct Handle
{
    unsigned int value;
    Handle() : value(0) {}
};
struct FUN_007b76e0 : Closest
{
    Handle handle;
    float value74;
    FUN_007b76e0(int index, unsigned int* reference);
    virtual ~FUN_007b76e0();
    void FUN_0056f720(int index, unsigned int* reference);
};
// pdb: SpecificItemCollector::SpecificItemCollector | CombatUtilities.obj | fnv360_0721_beta, call_gap, low
// pdb params: aePick, arFilter
FUN_007b76e0::FUN_007b76e0(int index, unsigned int* reference)
{
    FUN_0056f720(index, reference);
}
}
}   // namespace f3m_007b76e0
