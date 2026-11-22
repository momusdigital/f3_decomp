#include "f3_common.h"
// src/havok/physics/collide/agent/deprecated/multisphere/hkpmultisphereagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/multisphere/hkpmultisphereagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Listener
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void Notify(unsigned int);
};
struct Entry
{
    int unk00;
    Listener* listener;
};
struct Dispatcher
{
    virtual void Finish(unsigned int);
    int unk04;
    int unk08;
    Entry* entries;
    int count;
    void __thiscall NotifyAll(unsigned int);
};
// Calls Notify(value) on every entry's listener, then calls Finish(1).
// @fnv 0x00d443a0
// pdb: hkpMultiSphereAgent::cleanup | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: info
void Dispatcher::NotifyAll(unsigned int value)
{
    for (int i = 0; i < count; ++i)
        entries[i].listener->Notify(value);
    Finish(1);
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;

extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);

class hkVector4
{
  public:
    __m128 m_vComponents;
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};

class hkRotation
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

class hkTransform
{
  public:
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

class hkMotionState
{
  public:
    hkTransform m_kMotionTransform;
    int m_rest[0x1c];
    hkMotionState(const hkMotionState& o);
};

class hkpShape
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};

class __declspec(align(16)) hkpSphereShape : public hkpShape
{
  public:
    float m_fSphereRadius;
    hkpSphereShape(float radius);
};

class hkpMultiSphereShape : public hkpShape
{
  public:
    int m_iSphereCount;
    hkVector4 m_kSpheres[8];
};

class hkpCdBody
{
  public:
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
    hkpCdBody(const hkpCdBody* parent, const void* motion)
    {
        m_parent = parent;
        m_pMotionState = motion;
    }
    const hkpShape* getShape() const
    {
        return m_pCollisionShape;
    }
    const hkMotionState* GetMotionState() const
    {
        return (const hkMotionState*)m_pMotionState;
    }
    const hkTransform& getTransform() const
    {
        return *(const hkTransform*)m_pMotionState;
    }
    void SetCollisionShapeAndKey(const hkpShape* s, unsigned int key)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = key;
    }
};

class CollisionAgentContext;
class hkpCdBodyPairCollector;

class hkpCollisionAgent
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void getPenetrations(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& input,
                                 hkpCdBodyPairCollector& collector);
};

struct CollisionAgentMapRecord
{
    unsigned int m_key;
    hkpCollisionAgent* m_pCollisionAgent;
};

class hkpMultiSphereAgent
{
  public:
    void* m_vtbl;
    int m_pad04;
    int m_pad08;
    CollisionAgentMapRecord* m_pAgents;
    int m_iElementCount;
    void GetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                         hkpCdBodyPairCollector& collector);
};

// For each stored sphere pair, transforms the sphere centre into world space, sets its radius and queries the agent's getPenetrations against bodyB.
// @fnv 0x00d444f0
void hkpMultiSphereAgent::GetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                          const CollisionAgentContext& input, hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    hkMotionState ms = *bodyA.GetMotionState();
    hkpSphereShape sphereShape(0.0f);
    hkpCdBody newOperandA(&bodyA, &ms);

    const CollisionAgentMapRecord* pair = m_pAgents;
    for (int i = m_iElementCount - 1; i >= 0; pair++, i--)
    {
        const hkVector4& b = msA->m_kSpheres[pair->m_key];
        const hkRotation& r = ms.m_kMotionTransform.m_rotation;
        __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
        __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
        __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
        ms.m_kMotionTransform.m_vTranslation.m_vComponents =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().m_vTranslation.m_vComponents);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        pair->m_pCollisionAgent->getPenetrations(newOperandA, bodyB, input, collector);
    }
}

struct S_00d44e20_Collector
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    float m_fHitDistance;
    int m_iFilter;
    S_00d44e20_Collector(int filter) : m_fHitDistance(3.40282e+38f), m_iFilter(filter)
    {}
};

void FUN_00d445e0(void* b, void* a, void* c, S_00d44e20_Collector* collector);

// Constructs a collector with the given filter and runs FUN_00d445e0 over b, a and c with it.
// @fnv 0x00d44e20
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticGetClosestPoints | hkpMultiSphereAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void FUN_00d44e20(void* apFirst, void* apSecond, void* apThird, int filter)
{
    S_00d44e20_Collector collector(filter);
    FUN_00d445e0(apSecond, apFirst, apThird, &collector);
}

struct __declspec(novtable) S_00d44f50_Base
{
    bool m_flag;
    S_00d44f50_Base() : m_flag(false)
    {}
    virtual void unk0() = 0;
};
struct S_00d44f50_Collector : S_00d44f50_Base
{
    int m_uiFilterValue;
    S_00d44f50_Collector(int value) : m_uiFilterValue(value)
    {}
    virtual void unk0();
};

struct S_00d44f50
{
    void ProcessSpheres(void* a, void* b, void* c, S_00d44f50_Collector* collector);
    void RunWithCollector(void* a, void* b, void* c, int value);
};

// Constructs a collector holding value and forwards it with the reordered arguments to ProcessSpheres.
// @fnv 0x00d44f50
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::getPenetrations | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void S_00d44f50::RunWithCollector(void* pFirst, void* pSecond, void* pThird, int value)
{
    S_00d44f50_Collector collector(value);
    ProcessSpheres(pSecond, pFirst, pThird, &collector);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;

struct FUN_00d44f90_Data
{
    unsigned int descriptor;
    float bound;
    unsigned int value;
};

struct FUN_00d44f90_Class
{
    void GetPenetrations(void* first, void* second, void* third, FUN_00d44f90_Data* data);
    void FUN_00d44f90(void* first, void* second, void* third, unsigned int value);
};

// Builds a data record from value, DAT_0104da48 and DAT_010ce7fc, then calls GetPenetrations with second, first and third.
// @fnv 0x00d44f90
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::getClosestPoints | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void FUN_00d44f90_Class::FUN_00d44f90(void* first, void* second, void* third, unsigned int value)
{
    FUN_00d44f90_Data data;
    data.value = value;
    data.bound = DAT_0104da48;
    data.descriptor = (unsigned int)&DAT_010ce7fc;
    GetPenetrations(second, first, third, &data);
}

struct Allocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pAllocator;
};

extern char DAT_010cf390[];

struct SpawnedObject
{
    void* m_vptr;
    unsigned short m_iElementCount;
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

    void Init(int a, int b, int c, int d);
};

AllocHolder* FUN_00c85750();

// @fnv 0x00d44d00
void* FUN_00d44d00(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    AllocHolder* pAllocHolder = FUN_00c85750();
    Allocator* pAllocator = pAllocHolder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)pAllocator->Alloc(0x38);
    obj->m_iElementCount = 0x38;
    obj->Init(aiArg2, aiArg1, aiArg3, aiArg4);
    *(void* volatile*)obj = (void*)DAT_010cf390;
    return obj;
}

void FUN_00d44d00();
void FUN_00d44de0();
void FUN_00d44e20();
void FUN_00d44cc0();
void FUN_00d449f0();
void FUN_00d445e0();
void ProcessMultiSphereCollision();

extern char DAT_010ce81c;

struct FUN_00d44de0_tmp
{
    const void* vt;
    unsigned char flag;
    unsigned int a4;
};

void __cdecl FUN_00d449f0(void* a, void* b, void* c, void* d);

// Builds a temporary object holding a4 and a cleared flag, then calls FUN_00d449f0 with a2, a1, a3 and that object.
// @fnv 0x00d44de0
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticGetPenetrations | hkpTransformAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d44de0(void* apArg1, void* apArg2, void* apArg3, unsigned int a4)
{
    FUN_00d44de0_tmp t;
    t.a4 = a4;
    t.flag = 0;
    t.vt = &DAT_010ce81c;
    FUN_00d449f0(apArg2, apArg1, apArg3, &t);
}

namespace fnv_00d450f0 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00d450f0

struct DispatchEntry
{
    void* a;
    void* b;
    void* c;
    void(__cdecl* process)(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, void*, void*);
    int e;
};
struct CollisionDispatcher
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
    unsigned char table[32][32];
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;

    DispatchEntry entries[32];
};
class CollisionAgentContext
{
  public:
    CollisionDispatcher* dispatcher;
};

class hkpCdBodyPairCollector
{
  public:
    virtual ~hkpCdBodyPairCollector();
    unsigned char earlyOut;
};
struct SphereChildAgent
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Process(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
struct SphereChildEntry
{
    int key;
    SphereChildAgent* agent;
};
struct SphereDispatch
{
    int unk00, unk04, unk08;
    SphereChildEntry* entries;
    int count;
    void ProcessSpheres(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
// @f3 0x009d2840 (community match, verified in this file)
// pdb: hkpMultiSphereAgent::getPenetrations | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void SphereDispatch::ProcessSpheres(const hkpCdBody& aBody, const hkpCdBody& aOtherBody,
                                    const CollisionAgentContext& input, hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* shape = (const hkpMultiSphereShape*)aBody.getShape();
    hkMotionState motionState(*aBody.GetMotionState());
    hkpSphereShape sphere(0.0f);
    hkpCdBody cdBodyProxy(&aBody, &motionState);
    SphereChildEntry* entry = entries;
    for (int remaining = count - 1; remaining >= 0; remaining--)
    {
        const hkVector4& point = shape->m_kSpheres[entry->key];
        const hkRotation& r = motionState.m_kMotionTransform.m_rotation;
        float v0 = point(0);
        float v1 = point(1);
        float v2 = point(2);
        hkVector4 rotated;
        rotated(0) = r.m_kColumn0(0) * v0 + r.m_kColumn1(0) * v1 + r.m_kColumn2(0) * v2;
        rotated(1) = r.m_kColumn0(1) * v0 + r.m_kColumn1(1) * v1 + r.m_kColumn2(1) * v2;
        rotated(2) = r.m_kColumn0(2) * v0 + r.m_kColumn1(2) * v1 + r.m_kColumn2(2) * v2;
        rotated(3) = 0.0f;
        const hkVector4& t = aBody.getTransform().m_vTranslation;
        hkVector4& dst = motionState.m_kMotionTransform.m_vTranslation;
        dst(0) = t(0) + rotated(0);
        dst(1) = t(1) + rotated(1);
        dst(2) = t(2) + rotated(2);
        dst(3) = t(3) + rotated(3);
        sphere.m_fSphereRadius = point(3);
        cdBodyProxy.SetCollisionShapeAndKey(&sphere, remaining);
        entry->agent->Process(cdBodyProxy, aOtherBody, input, collector);
        if (collector.earlyOut)
            break;
        entry++;
    }
}


// @fnv 0x00d44cc0
void FUN_00d44cc0(int a1, int a2, int a3, int a4)
{
    AllocHolder* pAllocHolder = FUN_00c85750();
    SpawnedObject* obj = (SpawnedObject*)pAllocHolder->m_pAllocator->Alloc(0x38);
    obj->m_iElementCount = 0x38;
    obj->Init(a1, a2, a3, a4);
}

extern "C" __m128 _mm_xor_ps(__m128 _A, __m128 _B);

extern float DAT_0104da48;

union __declspec(align(16)) S_00d45160_Vec
{
    __m128 m_vComponents;
    struct S_00d45160_Components
    {
        int x;
        int y;
        int z;
        int w;
    } m_auiHeaderValues;
};

struct __declspec(align(16)) S_00d45160_Input
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
    S_00d45160_Vec m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct __declspec(align(16)) S_00d45160_Collector
{
    void* m_vtbl;
    float m_fHitDistance;
    int unk08;
    int unk0c;
    S_00d45160_Vec m_vec;
    unsigned int m_key;
};

extern __m128 DAT_010c4c00;

template <class T> inline void S00d44fd0_swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct S00d44fd0_SR
{
    __m128 r;
};

struct S00d44fd0_V
{
    __m128 q;
    inline S00d44fd0_SR getW() const
    {
        S00d44fd0_SR s;
        s.r = _mm_shuffle_ps(q, q, 0xff);
        return s;
    }
    inline void addMul4(const S00d44fd0_SR& r, const S00d44fd0_V& a)
    {
        q = _mm_add_ps(_mm_mul_ps(r.r, a.q), q);
    }
    inline void setNeg4(const S00d44fd0_V& a)
    {
        q = _mm_xor_ps(a.q, DAT_010c4c00);
    }
};

extern float DAT_0104da48;

struct __declspec(align(16)) Key_d2e9
{
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union
    {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9
{
    const char* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl ProcessMultiSphereCollision(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

struct __declspec(align(16)) FUN_00cd8160 : hkpShape
{
    float m_fSphereRadius;
    FUN_00cd8160(float r);
};
struct S_00d44b00_A;
struct __declspec(align(16)) S_00d44b00_V4
{
    float x, y, z, w;
};
struct S_00d44b00_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct S_00d44b00_Elem
{
    int first;
    int second;
};
struct LocalHolder : AllocHolder
{
    S_00d44b00_Alloc& heap()
    {
        return *(S_00d44b00_Alloc*)m_pAllocator;
    }
};
struct S_00d44b00_Arr;
extern void FUN_00c908c0(S_00d44b00_Alloc* a, S_00d44b00_Arr* arr, int n, int elemSize);
struct S_00d44b00_Arr
{
    S_00d44b00_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    void reserve(S_00d44b00_Alloc& a, int n)
    {
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            FUN_00c908c0(&a, this, (n < cap2) ? cap2 : n, 8);
        }
    }
    S_00d44b00_Elem* expandByUnchecked(int n)
    {
        int oldSize = m_iElementCount;
        m_iElementCount = oldSize + n;
        return m_data + oldSize;
    }
};
struct __declspec(align(16)) S_00d44b00_Tri
{
    void CopyFrom(const S_00d44b00_Tri* o);
    S_00d44b00_V4 c0;
    S_00d44b00_V4 c1;
    S_00d44b00_V4 c2;
    S_00d44b00_V4 va;
    S_00d44b00_V4 vb;
    S_00d44b00_V4 vc;
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
};
struct S_00d44b00_Entry
{
    int (*fn)(const hkpCdBody& ctx, const hkpCdBody& a, const S_00d44b00_A& b, void* c);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_00d44b00_Disp
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
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char tblA[32][32];
    unsigned char tblB[32][32];
    S_00d44b00_Entry entries[32];
    typedef int (*CreateFunc)(const hkpCdBody&, const hkpCdBody&, const S_00d44b00_A&, void*);
    inline CreateFunc getCreationFunction(int typeA, int typeB, int predictive) const
    {
        int idx = (predictive ? tblB : tblA)[typeA][typeB];
        return entries[idx].fn;
    }
    inline int getNewAgent(const hkpCdBody& a, const hkpCdBody& b, const S_00d44b00_A& env, void* mgr) const;
};
struct S_00d44b00_A
{
    S_00d44b00_Disp* disp;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int flag;
};
struct S_00d44b00_Inplace : S_00d44b00_Arr
{
    S_00d44b00_Elem inline0, inline1, inline2, inline3;
    S_00d44b00_Inplace()
    {
        m_data = &inline0;
        m_iElementCount = 0;
        m_cap = 0x80000004;
    }
};
struct S_00d44b00_Base
{
    virtual void v0();
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    S_00d44b00_Base(void* c) : unk06(1), unk08(c)
    {}
};

__declspec(align(16)) struct S_V4
{
    float x, y, z, w;
};

struct S00d443e0_S_Input
{
    S_V4 m00;
    S_V4 m10;
    S_V4 m20;
    S_V4 m30;
    S_V4 m40;
    S_V4 m50;
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
    S00d443e0_S_Input(const S00d443e0_S_Input& o) throw();
};

struct S00d443e0_S_Coll
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    float m10;
    int unk14;
    int unk18;
    int unk1c;
    S00d443e0_S_Coll* FUN_00cd8160(float f) throw();
};

struct S00d443e0_S_Ctx
{
    S00d443e0_S_Coll* coll;
    int idx;
    S00d443e0_S_Input* input;
    void* owner;
};

struct S00d443e0_S_Child
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(S00d443e0_S_Ctx* c, int a, int b, int d);
};
struct S00d443e0_S_Entry
{
    int off;
    S00d443e0_S_Child* child;
};

struct S00d443e0_S_Wrap
{
    S_V4* base;
    int unk4;
    S00d443e0_S_Input* src;
};

struct S00d443e0_S_Owner
{
    int unk0;
    int unk4;
    int unk8;
    S00d443e0_S_Entry* arr;
    int count;
    void hkpMultiSphereAgent_getClosestPoints(S00d443e0_S_Wrap* in, int a, int b, int d);
};

// Iterates entries in reverse, adds a rotation term to the input copy, and dispatches each child's v6 with a shared context.
// @f3 0x009d2260 (community match, verified in this file)
struct Coll443
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    float m10;
    int unk14;
    int unk18;
    int unk1c;
    Coll443* FUN_00970f60(float f) throw();
};
extern double DAT_00db38b0;
struct Ctx443
{
    Coll443* coll;
    int idx;
    S00d443e0_S_Input* input;
    void* owner;
};
struct ChildCall443e0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(Ctx443*, int, int, int); };

// pdb: hkpMultiSphereAgent::getClosestPoints | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S00d443e0_S_Owner::hkpMultiSphereAgent_getClosestPoints(S00d443e0_S_Wrap* wrap, int a, int b, int d)
{
    S_V4* base = wrap->base;
    S00d443e0_S_Input copy(*wrap->src);
    Coll443 collision;
    collision.FUN_00970f60(0.0f);
    Ctx443 context;
    context.owner = wrap;
    context.input = &copy;
    S00d443e0_S_Entry* e = arr;
    int i = count - 1;
    if (i >= 0)
    do
    {
        S_V4* p = base + e->off + 2;
        S_V4 n;
        float x = p->x;
        float y = p->y;
        float z = p->z;
        n.x = x*copy.m00.x + y*copy.m10.x + z*copy.m20.x;
        n.y = x*copy.m00.y + y*copy.m10.y + z*copy.m20.y;
        n.z = x*copy.m00.z + y*copy.m10.z + z*copy.m20.z;
        S_V4* s = &wrap->src->m30;
        copy.m30.x = s->x + n.x;
        copy.m30.y = s->y + n.y;
        copy.m30.z = s->z + n.z;
        copy.m30.w = (float)(s->w + DAT_00db38b0);
        collision.m10 = p->w;
        context.coll = &collision;
        context.idx = i;
        ((ChildCall443e0*)e->child)->v4(&context, a, b, d);
        ++e;
    } while (--i >= 0);
}


class CollisionAgentContext;
class hkpCdBodyPairCollector;

typedef void(__cdecl* GetPenetrationsFunc)(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& input,
                                           hkpCdBodyPairCollector& collector);

struct S00d445e0_AgentFuncs
{
    void* m_pCreateFunc;
    GetPenetrationsFunc m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    void* m_pLinearCastFunc;
    int m_bIsFlipped;
};

class S00d445e0_hkpCollisionDispatcher
{
  public:
    int m_pad000;
    S00d445e0_AgentFuncs* agentFuncs() const
    {
        return (S00d445e0_AgentFuncs*)((char*)this + 0x9a4);
    }
    GetPenetrationsFunc getGetPenetrationsFunc(int typeA, int typeB) const
    {
        int idx = ((const unsigned char(*)[32])((const char*)this + 0x1a0))[typeA][typeB];
        return agentFuncs()[idx].m_pQueryPenetrationsFunc;
    }
};

// Iterates over each sphere of a multi-sphere shape, transforms it into world space, and dispatches penetration queries against bodyB.
// @fnv 0x00d445e0
void FUN_00d445e0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                  hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    hkMotionState ms = *bodyA.GetMotionState();
    hkpSphereShape sphereShape(0.0f);
    hkpCdBody newOperandA(&bodyA, &ms);

    int typeB = bodyB.getShape()->m_type;
    for (int i = 0; i < msA->m_iSphereCount; i++)
    {
        const hkVector4& b = msA->m_kSpheres[i];
        const hkRotation& r = ms.m_kMotionTransform.m_rotation;
        __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
        __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
        __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
        ms.m_kMotionTransform.m_vTranslation.m_vComponents =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().m_vTranslation.m_vComponents);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        GetPenetrationsFunc func =
            ((S00d445e0_hkpCollisionDispatcher*)input.dispatcher)->getGetPenetrationsFunc(sphereShape.m_type, typeB);
        func(newOperandA, bodyB, input, collector);
    }
}

class CollisionAgentContext;

typedef void(__cdecl* GetPenetrationsFunc)(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& input,
                                           hkpCdBodyPairCollector& collector);

struct S00d449f0_AgentFuncs
{
    void* m_pCreateFunc;
    GetPenetrationsFunc m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    void* m_pLinearCastFunc;
    int m_bIsFlipped;
};

class S00d449f0_hkpCollisionDispatcher
{
  public:
    int m_pad000;
    S00d449f0_AgentFuncs* agentFuncs() const
    {
        return (S00d449f0_AgentFuncs*)((char*)this + 0x9a0);
    }
    GetPenetrationsFunc getGetPenetrationsFunc(int typeA, int typeB) const
    {
        int idx = ((const unsigned char(*)[32])((const char*)this + 0x1a0))[typeA][typeB];
        return agentFuncs()[idx].m_pQueryPenetrationsFunc;
    }
};

// Iterates over each sphere in a multi-sphere shape, transforms it, and queries penetrations against bodyB via the dispatcher's per-type collision function.
// @fnv 0x00d449f0
void FUN_00d449f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                  hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    hkMotionState ms = *bodyA.GetMotionState();
    hkpSphereShape sphereShape(0.0f);
    hkpCdBody newOperandA(&bodyA, &ms);

    int typeB = bodyB.getShape()->m_type;
    for (int i = 0; i < msA->m_iSphereCount; i++)
    {
        const hkVector4& b = msA->m_kSpheres[i];
        const hkRotation& r = ms.m_kMotionTransform.m_rotation;
        __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
        __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
        __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
        ms.m_kMotionTransform.m_vTranslation.m_vComponents =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().m_vTranslation.m_vComponents);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        GetPenetrationsFunc func =
            ((S00d449f0_hkpCollisionDispatcher*)input.dispatcher)->getGetPenetrationsFunc(sphereShape.m_type, typeB);
        func(newOperandA, bodyB, input, collector);
        if (collector.earlyOut)
        {
            break;
        }
    }
}
