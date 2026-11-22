#include "f3_common.h"
// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
};

struct BSAudio {
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
};

BSAudio* FUN_00c85750();

void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct hkArrayU16 {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init() { m_data = 0; m_iElementCount = 0; m_iCapacityState = 0x80000000; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(int n)
    {
        BSAudio* a = FUN_00c85750();
        hkMemoryAllocator* alloc = a->unk10;
        int c = m_iCapacityState & 0x3fffffff;
        if (c < n) {
            c = c * 2;
            FUN_00c908c0(*alloc, this, n < c ? c : n, 2);
        }
    }
    __forceinline void SetSizeAndGrow(int n, const unsigned short& fill)
    {
        reserve(n);
        int num = n - m_iElementCount;
        unsigned short* p = m_data + m_iElementCount;
        for (int i = 0; i < num; ++i) {
            p[i] = fill;
        }
        m_iElementCount = n;
    }
};

namespace fnv_00d32110 {
struct Allocator {
    virtual void unk0();
    virtual void* Allocate(unsigned int size);
};

struct BSAudio {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* allocator;
};

BSAudio* FUN_00c85750();

}  // namespace fnv_00d32110

extern void __cdecl FUN_00d319e0(void*, void*, void*, void*);
// @fnv 0x00d32170
// pdb: hkpHeightFieldAgent::getClosestPoints | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpHeightFieldAgent_getClosestPoints(void* apArg1, void* apArg2, void* apArg3, void* apArg4) {
    FUN_00d319e0(apArg1, apArg2, apArg3, apArg4);
}

typedef void (*S_00d321e0_Func)();

void FUN_00d32370();
void FUN_00d323b0();
void FUN_00d317d0();
void FUN_00d319e0();
void FUN_00d31d30();

extern float g_D323B0MaxDistance;

struct D323B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D323B0CollectorBase() : m_fEarlyOutDistance(g_D323B0MaxDistance) {}
};

struct D323B0Collector : D323B0CollectorBase {
    int m_iData;

    D323B0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl FUN_00d319e0(int a, int b, int c, D323B0CollectorBase* collector);

// Constructs a D323B0Collector from d and passes it with b, a, c to FUN_00d319e0.
// @fnv 0x00d323b0
// pdb: hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticGetClosestPoints | hkpHeightFieldAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d323b0(int aiArg1, int aiArg2, int aiArg3, int aiData)
{
    D323B0Collector collector(aiData);
    FUN_00d319e0(aiArg2, aiArg1, aiArg3, &collector);
}

struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void invoke(unsigned short item, int value);
};
struct Owner {
    virtual void clear(unsigned int mode);
    int unk04;
    Handler* callback;
    unsigned short* indices;
    int count;
    void hkpHeightFieldAgent_cleanup(int value);
};
// Invokes callback->invoke for each non-0xffff entry in indices, then calls clear(1).
// @fnv 0x00d31770
// pdb: hkpHeightFieldAgent::cleanup | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: constraintOwner
// pdb: hkpHeightFieldAgent::cleanup | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high (was: NotifyAndClear)
void Owner::hkpHeightFieldAgent_cleanup(int value) {
    if (callback) {
        for(int index=0; index<count; ++index) {
            unsigned short item=indices[index];
            if(item!=0xffff)
                callback->invoke(item,value);
        }
    }
    clear(1);
}

extern "C" void __cdecl FUN_00d31d30(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
// Forwards all five arguments unchanged to FUN_00d31d30.
// @fnv 0x00d32030
// pdb: hkpHeightFieldAgent::linearCast | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: csBody, hfBody, input, collector, startCollector
extern "C" void __stdcall FUN_00d32030(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4)
{
    FUN_00d31d30(arg0, arg1, arg2, arg3, arg4);
}

extern "C" void __cdecl FUN_00d317d0(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d32150
// pdb: hkpHeightFieldAgent::getPenetrations | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: csBody, hfBody, input, collector
extern "C" void __stdcall FUN_00d32150(void* arg0, void* arg1, void* arg2, void* arg3)
{
    FUN_00d317d0(arg0, arg1, arg2, arg3);
}

extern char DAT_010ce81c;

void __cdecl FUN_00d317d0(int a1, int a2, int a3, void* a4);

struct FUN_00d32370_cls {
    void* vt;
    unsigned char flag;
    int d;
};

// Builds a FUN_00d32370_cls with vt set to DAT_010ce81c and d set to a4, then calls FUN_00d317d0 with a2, a1, a3 and the struct.
// @fnv 0x00d32370
// pdb: hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticGetPenetrations | hkpHeightFieldAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d32370(int aiArg1, int aiArg2, int aiArg3, int a4) {
    FUN_00d32370_cls local;
    local.flag = 0;
    local.d = a4;
    local.vt = &DAT_010ce81c;
    FUN_00d317d0(aiArg2, aiArg1, aiArg3, &local);
}

#include <xmmintrin.h>
namespace fnv_00d323f0 {
struct FourFloatVector { float x, y, z, w; };
struct __declspec(align(16)) CopyPacket {
    void* unk00;
    unsigned int unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    FourFloatVector orientation;
    unsigned int unk60, unk64, unk68, unk6c;
};
struct Argument {
    const void* vtable;
    float scale;
    unsigned int unk08, unk0c;
    FourFloatVector orientation;
    int identifier;
    unsigned int unk24, unk28, unk2c;
};
extern "C" void __cdecl FUN_00d31d30(int, int, const CopyPacket*, const Argument*, const Argument*);

}  // namespace fnv_00d323f0

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128 {float m128_f32[4];};
extern "C" {
__m128 _mm_add_ps(__m128,__m128); __m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,int); __m128 _mm_unpackhi_ps(__m128,__m128);
}
}
extern unsigned long DAT_0126835c;
extern const char str_010cea1c[];

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHi;
    const char* subName;
};
struct StringCursor {
    int unk00;
    char* m_memPos;
    int unk08;
    char* m_memEnd;

    static __forceinline StringCursor& GetMonitorStream() {
        return *(StringCursor*)TlsGetValue(DAT_0126835c);
    }
    __forceinline void timerBegin(const char* name1, const char* name2) {
        if (m_memPos < m_memEnd) {
            MonitorCommand* cmd = (MonitorCommand*)m_memPos;
            cmd->name = name1;
            cmd->subName = name2;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            cmd->time = ticks;
            m_memPos = (char*)(cmd + 1);
        }
    }
    __forceinline void timerSplit(const char* name) {
        if (m_memPos < m_memEnd) {
            MonitorCommand* cmd = (MonitorCommand*)m_memPos;
            cmd->name = name;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            cmd->time = ticks;
            m_memPos = (char*)cmd + 12;
        }
    }
    __forceinline void timerEnd(const char* name) { timerSplit(name); }
};

struct hkTransform;

struct hkVector4 {
    union { N::__m128 m_vComponents; struct { float x,y,z,w; }; };

    __forceinline void SetRotatedDirection(const hkTransform& a, const hkVector4& b);
    __forceinline void SetTransformedPoint(const hkTransform& a, const hkVector4& b);
};

struct hkTransform {
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    hkTransform() {}
    __forceinline hkTransform(const hkTransform& other) {
        m_kColumn0.m_vComponents=other.m_kColumn0.m_vComponents;
        m_kColumn1.m_vComponents=other.m_kColumn1.m_vComponents;
        m_kColumn2.m_vComponents=other.m_kColumn2.m_vComponents;
        m_vTranslation.m_vComponents=other.m_vTranslation.m_vComponents;
    }
    void FUN_00cb22f0(const void* b, const void* a);
};

__forceinline void hkVector4::SetRotatedDirection(const hkTransform& a, const hkVector4& b) {
    N::__m128 y = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    N::__m128 x = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    N::__m128 z = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, a.m_kColumn1.m_vComponents), N::_mm_mul_ps(x, a.m_kColumn0.m_vComponents)), N::_mm_mul_ps(z, a.m_kColumn2.m_vComponents));
}

__forceinline void hkVector4::SetTransformedPoint(const hkTransform& a, const hkVector4& b) {
    N::__m128 y = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    N::__m128 x = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    N::__m128 z = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, a.m_kColumn1.m_vComponents), N::_mm_mul_ps(x, a.m_kColumn0.m_vComponents)), N::_mm_add_ps(N::_mm_mul_ps(z, a.m_kColumn2.m_vComponents), a.m_vTranslation.m_vComponents));
}

__forceinline void transformSphere(hkVector4& __restrict out, const hkTransform& __restrict a, const hkVector4& __restrict sphere) {
    N::__m128 y = N::_mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x55);
    N::__m128 x = N::_mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x00);
    N::__m128 z = N::_mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0xaa);
    N::__m128 pos = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, a.m_kColumn1.m_vComponents), N::_mm_mul_ps(x, a.m_kColumn0.m_vComponents)), N::_mm_add_ps(N::_mm_mul_ps(z, a.m_kColumn2.m_vComponents), a.m_vTranslation.m_vComponents));
    N::__m128 unpck = N::_mm_unpackhi_ps(pos, sphere.m_vComponents);
    out.m_vComponents = N::_mm_shuffle_ps(pos, unpck, 0xc4);
}

struct hkSphere : hkVector4 {};

__forceinline void transformSpheres(const hkTransform& tr, const hkSphere* src, int count, hkSphere* dst) {
    hkTransform local = tr;
    int i = count - 1;
    do {
        hkVector4 value;
        value.SetTransformedPoint(local,src[i]);
        value.m_vComponents = N::_mm_shuffle_ps(value.m_vComponents,N::_mm_unpackhi_ps(value.m_vComponents,src[i].m_vComponents),0xc4);
        dst[i].m_vComponents = value.m_vComponents;
    } while (--i >= 0);
}

struct hkpShape {
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
    virtual int getNumCollisionSpheres();
    virtual const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer);
};

struct CollisionSphereData {
    __forceinline void setSpheres(const hkSphere* p){ m_kSpheres=p; }
    const hkSphere* m_kSpheres;
    int m_iSphereCount;
    float m_fScalar;
};

struct hkpHeightFieldShape {
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
    virtual void CollideSpheres(const CollisionSphereData& input, hkSphere* hitResults);
};

struct hkMotionState {
    hkTransform m_kMotionTransform;
};

struct hkpCdBody {
    const hkpShape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const hkMotionState* m_pMotionState;
};

struct CollisionAgentContext {
    int unk00;
    int unk04;
    float m_fScalar;
};

struct hkContactPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};

struct ContactPointPair {
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    ContactPointPair() {}
    __forceinline ContactPointPair(const hkpCdBody* a, const hkpCdBody* b) : m_pBodyA(a), m_pBodyB(b) {}
};

struct hkpCdBodyPairCollector {
    virtual void v00();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};

// @fnv 0x00d317d0
void __cdecl FUN_00d317d0(int a1, int a2, int a3, void* a4)
{
    const hkpCdBody* bodyA = (const hkpCdBody*)a1;
    const hkpCdBody* bodyB = (const hkpCdBody*)a2;
    const CollisionAgentContext* input = (const CollisionAgentContext*)a3;
    hkpCdBodyPairCollector* collector = (hkpCdBodyPairCollector*)a4;

    StringCursor::GetMonitorStream().timerBegin("LtHeightField", "StGetSpheres");

    const hkpShape* shapeA = bodyA->m_pCollisionShape;
    hkpHeightFieldShape* shapeB = (hkpHeightFieldShape*)bodyB->m_pCollisionShape;
    hkTransform aTb;
    aTb.FUN_00cb22f0(bodyB->m_pMotionState, bodyA->m_pMotionState);

    int count = ((hkpShape*)shapeA)->getNumCollisionSpheres();

    BSAudio* q = FUN_00c85750();
    char* cur1 = (char*)q->unk00;
    hkSphere* sphereBuffer = (hkSphere*)cur1;
    q->unk00 = (int)(cur1 + ((count * 16 + 127) & ~127));

    const hkSphere* spheres = ((hkpShape*)shapeA)->getCollisionSpheres(sphereBuffer);
    transformSpheres(aTb, spheres, count, sphereBuffer);

    StringCursor::GetMonitorStream().timerSplit("StCollide");

    BSAudio* bs2 = FUN_00c85750();
    char* cur2 = (char*)bs2->unk00;
    hkSphere* hitResults = (hkSphere*)cur2;
    {
        const CollisionAgentContext* __restrict in = input;
        CollisionSphereData shB;
        shB.m_kSpheres = sphereBuffer;
        bs2->unk00 = (int)(cur2 + ((count * 16 + 127) & ~127));
        shB.m_iSphereCount = count;
        shB.m_fScalar = in->m_fScalar;
        shapeB->CollideSpheres(shB, hitResults);
    }

    StringCursor::GetMonitorStream().timerSplit(str_010cea1c);

    const hkSphere* hit = hitResults;
    for (int i = count - 1; i >= 0; ++hit, --i) {
        if (hit->w < 0.0f) {
            collector->AddCdBodyPair(*bodyA, *bodyB);
            break;
        }
    }

    FUN_00c85750()->unk00 = (int)hitResults;
    FUN_00c85750()->unk00 = (int)sphereBuffer;

    StringCursor::GetMonitorStream().timerEnd("lt");
}

namespace fnv_00d32190 {
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00d32190
