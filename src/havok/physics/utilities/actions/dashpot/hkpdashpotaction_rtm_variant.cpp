#include "f3_common.h"
// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/dashpot/hkpdashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpDashpotAction.h"
#include <xmmintrin.h>
// FUN_00d4d9d0 - hkpDashpotAction clone-style factory (Havok)
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
unsigned long g_tlsIdx = 0;

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);

namespace DashpotApplyDetail {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef void* (__stdcall *DashpotApplyTlsGetter)(unsigned long dwTlsIndex);

static inline __m128 dashpotApplyBroadcast(float f) { __m128 t = _mm_load_ss(&f); return _mm_shuffle_ps(t,t,0); }

struct S00d4da60_Transform;

struct __declspec(align(16)) DashpotApplyVector
{
    float x, y, z, w;
    void FUN_00c7f640(const S00d4da60_Transform* transform, const DashpotApplyVector* point);
};

struct S00d4da60_Transform
{
    DashpotApplyVector m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation;
};

struct S00d4da60_ProfRec
{
    const char* m_pName;
    unsigned int m_iTick;
    unsigned int unk08;
};

struct S00d4da60_ProfBuf
{
    unsigned int unk00;
    S00d4da60_ProfRec* m_pCur;
    unsigned int unk08;
    S00d4da60_ProfRec* m_pRecordEnd;
};

struct S00d4da60_Body
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
    virtual void ApplyImpulseAtPoint(const DashpotApplyVector* impulse, const DashpotApplyVector* point);
};

struct S00d4da60_Entity
{
    void* m_vtbl;
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
    void* unk8C;
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
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    S00d4da60_Body m_kCollisionBody;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    S00d4da60_Transform m_kMotionTransform;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    DashpotApplyVector m_kTranslationalVelocity;
    void FUN_00c9c1d0();
};

struct S00d4da60_StepInfo
{
    int unk00;
    int unk04;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct S00d4da60_StepRef
{
    const S00d4da60_StepInfo* p;
    const S00d4da60_StepInfo* operator->() const { return p; }
};

struct S00d4da60_DashpotAction
{
    void* m_vtbl;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    S00d4da60_Entity* m_pEntityA;
    S00d4da60_Entity* m_pEntityB;
    DashpotApplyVector m_kPoint[2];
    float m_fSpringStrength;
    float m_fMotorDamping;
    void* unk48;
    void* unk4C;
    DashpotApplyVector m_fContactImpulse;
    void __thiscall hkpDashpotAction_applyAction(S00d4da60_StepRef stepInfo);
};

// @f3 0x009da680 (community match, verified in this file)
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0116913c;
extern char DAT_00e80290[];
extern char DAT_00e32798[];
extern const double DAT_00e80288,DAT_00dc0438;
namespace dp_009da680 {
using namespace ::DashpotApplyDetail;

struct Transform55;
struct __declspec(align(16)) ScalarVector55 {
    union {
        struct { float x,y,z,w; };
        float components[4];
    };
    void hkVector4_setTransformedPos(const Transform55*,const ScalarVector55*);
    void SubA(const ScalarVector55& a,const ScalarVector55& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
    void SubB(const ScalarVector55& a,const ScalarVector55& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
    void MulA(float s,const ScalarVector55& b){for(int i=0;i<4;i++)components[i]=b.components[i]*s;}
    void MulB(float s,const ScalarVector55& b){for(int i=0;i<4;i++)components[i]=b.components[i]*s;}
    void SetScaledDouble(const ScalarVector55& b,double s){for(int i=0;i<4;i++)components[i]=(float)(b.components[i]*s);}
    void Add(const ScalarVector55& b){for(int i=0;i<4;i++)components[i]+=b.components[i];}
};
struct Transform55 { ScalarVector55 m_kColumn0,m_kColumn1,m_kColumn2,m_vTranslation; };
struct Body55
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
    virtual void ApplyImpulseAtPoint(const ScalarVector55* impulse, const ScalarVector55* point);
};
struct Entity55
{
    void* m_vtbl;
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
    void* unk8C;
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
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    Body55 m_kCollisionBody;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    Transform55 m_kMotionTransform;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    ScalarVector55 m_kTranslationalVelocity;
    void FUN_0090b500();
};
struct Scratch55 {ScalarVector55 pointB,pointA,opposite;};
}
// pdb: hkpDashpotAction::applyAction | hkpDashpotAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void ::DashpotApplyDetail::S00d4da60_DashpotAction::hkpDashpotAction_applyAction(::DashpotApplyDetail::S00d4da60_StepRef stepInfo) {
    using namespace dp_009da680;
    volatile unsigned int tick;
    {
        S00d4da60_ProfBuf& buffer=*(S00d4da60_ProfBuf*)TlsGetValue(DAT_0116913c);
        S00d4da60_ProfRec* record=buffer.m_pCur;
        if(record<buffer.m_pRecordEnd) {
            record->m_pName=DAT_00e80290;
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            record->m_iTick=tick;
            buffer.m_pCur=record+1;
        }
    }
    float dt=(float)(stepInfo->m_fTimeStep*DAT_00e80288);
    Entity55* entityA=(Entity55*)m_pEntityA;
    Entity55* entityB=(Entity55*)m_pEntityB;
    ScalarVector55 relativeVel;
    Scratch55 scratch;
    scratch.pointA.hkVector4_setTransformedPos(&entityA->m_kMotionTransform,(const ScalarVector55*)&m_kPoint[0]);
    scratch.pointB.hkVector4_setTransformedPos(&entityB->m_kMotionTransform,(const ScalarVector55*)&m_kPoint[1]);
    scratch.opposite.SubA(scratch.pointA,scratch.pointB);
    relativeVel.SubB(entityA->m_kTranslationalVelocity,entityB->m_kTranslationalVelocity);
    ScalarVector55* impulse=(ScalarVector55*)&m_fContactImpulse;
    impulse->MulA(m_fSpringStrength*dt,scratch.opposite);
    relativeVel.MulB(dt*m_fMotorDamping,relativeVel);
    impulse->Add(relativeVel);
    scratch.opposite.SetScaledDouble(*impulse,DAT_00dc0438);
    entityA->FUN_0090b500();
    entityA->m_kCollisionBody.ApplyImpulseAtPoint(&scratch.opposite,&scratch.pointA);
    entityB->FUN_0090b500();
    entityB->m_kCollisionBody.ApplyImpulseAtPoint(impulse,&scratch.pointB);
    {
        S00d4da60_ProfBuf& buffer=*(S00d4da60_ProfBuf*)TlsGetValue(DAT_0116913c);
        S00d4da60_ProfRec* record=buffer.m_pCur;
        if(record<buffer.m_pRecordEnd) {
            record->m_pName=DAT_00e32798;
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            record->m_iTick=tick;
            buffer.m_pCur=record+1;
        }
    }
}




}
