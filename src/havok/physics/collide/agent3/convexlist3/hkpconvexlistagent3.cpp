#include "f3_common.h"
// src/havok/physics/collide/agent3/convexlist3/hkpconvexlistagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/convexlist3/hkpconvexlistagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl hkAgent1nMachine_InvalidateTim(void* a, void* b);

// @fnv 0x00d32b20
// pdb: hkConvexListAgent3::invalidateTim | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, input
// pdb: hkConvexListAgent3::invalidateTim | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun, high (was: CallIfNotFlagged)
void __cdecl hkConvexListAgent3_invalidateTim(int aiUnused, int pObject, int c)
{
    if (!(*(char*)(pObject + 0xb) & 0x20))
        hkAgent1nMachine_InvalidateTim((void*)(pObject + 0x10), (void*)c);
}

void __cdecl SetFlagAndCall(int, int, int);
void __cdecl FUN_00d32bd0(int, int, int);
void __cdecl hkConvexListAgent3_calcStatistics(int, int, int);
void __cdecl hkConvexListAgent3_warpTime(int, int, int);

// If the flag at offset 0x0b of b is clear, calls f6 with "hkConvexListAgent3", FUN_00d97250 on b+0x10, then f7 on the agent.
// @f3 0x009bc8c0 (community match, verified in this file)
struct FUN_00d32ae0_vt
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(const char*);
    virtual void f5();
    virtual void f6(const char*);
    virtual void f7();
};

void __cdecl FUN_00a26d90(void*, void*, void*);

// pdb: hkConvexListAgent3::calcStatistics | hkpConvexListAgent3.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkConvexListAgent3_calcStatistics(int aiUnused, int b, int c)
{
    if (reinterpret_cast<unsigned char*>(b)[0x0b] & 0x20)
        return;

    FUN_00d32ae0_vt* agent = *reinterpret_cast<FUN_00d32ae0_vt**>(reinterpret_cast<char*>(&c) + 4);

    agent->f4("hkConvexListAgent3");
    FUN_00a26d90(reinterpret_cast<char*>(b) + 0x10, reinterpret_cast<void*>(c), agent);
    agent->f5();
}


void __cdecl _FUN_00da35f0(void*, float, float, int);

// If the object's byte at offset 0xb lacks flag 0x20, forwards its fields at +0x10 plus three stack arguments to _FUN_00da35f0.
// @fnv 0x00d32b40
// pdb: hkConvexListAgent3::warpTime | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun + bridge(hash|objrun) + skyrim(hash), high
void __cdecl hkConvexListAgent3_warpTime(int aiUnused, int aiArg1, int aiArg2)
{
    struct StackArguments
    {
        void* object;
        float first;
        float second;
        int third;
    };

    StackArguments* pStackArgs = reinterpret_cast<StackArguments*>(&aiArg1);
    if (!(reinterpret_cast<unsigned char*>(pStackArgs->object)[0xb] & 0x20))
    {
        _FUN_00da35f0(reinterpret_cast<unsigned char*>(pStackArgs->object) + 0x10, pStackArgs->first,
                      pStackArgs->second, pStackArgs->third);
    }
}

void __cdecl DispatchInputRecord(int a, int b, void* c);

// Calls DispatchInputRecord with a, b and c, then sets bit 0x20 and clears bit 0x40 in byte 0xb of c.
// @fnv 0x00d32b70
// pdb: hkConvexListAgent3::create | hkpConvexListAgent3.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: input, entry, agentData
void __cdecl SetFlagAndCall(int aiArg1, int aiArg2, int c)
{
    char* p = (char*)c;
    DispatchInputRecord(aiArg1, aiArg2, p);
    p[0xb] = (p[0xb] & 0xbf) | 0x20;
}

struct PackTarget
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
};

struct FUN_00d33210_cls
{
    int unk00;
    int unk04;
    int unk08;
    PackTarget* m_0c;
    void FUN_00d33210();
};

// @fnv 0x00d33210
void FUN_00d33210_cls::FUN_00d33210()
{
    m_0c->v24();
}

// hkpMapPointsToSubShapeContactMgr_reserveContactPointsImpl (0x00d33220, 10 bytes)
//
//	8b 49 0c        mov ecx, dword ptr [ecx+0xc]
//	8b 01           mov eax, dword ptr [ecx]
//	8b 40 10        mov eax, dword ptr [eax+0x10]
//	ff e0           jmp eax
//
// A __thiscall member of a wrapper class: it loads the polymorphic
// sub-object pointer at +0xc, then tail-jumps to the sub-object's
// virtual at vtable offset 0x10 (the fifth virtual), forwarding the
// incoming 4-byte stack argument in place (that is what puts the jump
// target in EAX instead of EDX).

struct Sub_d33220
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int);
};

struct Own_d33220
{
    int unk00;
    int unk04;
    int unk08;
    Sub_d33220* unk0c;
    void hkpMapPointsToSubShapeContactMgr_reserveContactPointsImpl(int);
};

// @fnv 0x00d33220
// pdb: hkpMapPointsToSubShapeContactMgr::reserveContactPointsImpl | hkpConvexListAgent3.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Own_d33220::hkpMapPointsToSubShapeContactMgr_reserveContactPointsImpl(int a)
{
    unk0c->v4(a);
}

struct FnvCpu_FUN_00d33230_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d33230_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d33230_CpuInterface* target;
    void FUN_00d33230(int arg0);
};
// @fnv 0x00d33230
// pdb: hkpMalleableConstraintData::getRuntimeInfo | hkpMalleableConstraintData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: wantRuntime, infoOut
void FnvCpu_FUN_00d33230_CpuOwner::FUN_00d33230(int arg0)
{
    target->Invoke(arg0);
}

struct Target
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18(int a);
};

struct Self
{
    int unk00;
    int unk04;
    int unk08;
    Target* unk0c;
};

// @fnv 0x00d33240
// pdb: hkpMapPointsToSubShapeContactMgr::processContactImpl | hkpConvexListAgent3.obj | fnv360_0822_retail, vtable, high
// pdb params: a, b, input, collisionData
void __fastcall FUN_00d33240(Self* self, int unused, int arg)
{
    self->unk0c->vfn18(arg);
}

struct FnvCpu_FUN_00d33250_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d33250_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d33250_CpuInterface* target;
    void hkpMapPointsToSubShapeContactMgr_removeToiImpl(int arg0);
};
// @fnv 0x00d33250
// pdb: hkpMapPointsToSubShapeContactMgr::removeToiImpl | hkpConvexListAgent3.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FnvCpu_FUN_00d33250_CpuOwner::hkpMapPointsToSubShapeContactMgr_removeToiImpl(int arg0)
{
    target->Invoke(arg0);
}

struct hkpShapeD333
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

class hkpShapeContainerD333
{
  public:
    virtual ~hkpShapeContainerD333() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual const hkpShapeD333* GetShapeForKey(unsigned int uiKey, void* pvBuffer) const throw();
};

struct hkpShapeCollectionD333 : public hkpShapeD333
{
    int m_10;
    hkpShapeContainerD333 m_container;
};

struct hkpCdBodyD333
{
    const hkpShapeD333* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyD333* m_parent;
};

struct hkpGskCacheD333
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
};

struct __declspec(align(16)) hkpShapeBufferD333
{
    unsigned int m_buffer[128];
};

class hkpChildProcessorD333
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int process(const hkpCdBodyD333& kBodyA, const hkpCdBodyD333& kBodyB, const void* pvInput,
                        const void* pvTransform, hkpGskCacheD333* pkCache, void* pvOutput) throw();
};

class hkpConvexListProcessorD333
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkpChildProcessorD333* m_processor;
    bool m_invalidCache;

    unsigned short hkpMapPointsToSubShapeContactMgr_addContactPointImpl(const hkpCdBodyD333& kBodyA, const hkpCdBodyD333& kBodyB, const void* pvInput,
                                  const void* pvTransform, hkpGskCacheD333* pkCache, void* pvOutput) throw();
};

// Resolves convex-list child shapes for both bodies from the cache keys, flags an invalid cache on mismatch, and delegates to m_processor->process.
// @f3 0x009bd210 (community match, verified in this file)
// pdb: hkpMapPointsToSubShapeContactMgr::addContactPointImpl | hkpConvexListAgent3.obj | fnv360_0822_retail, vtable, high
// pdb params: a, b, input, output, contactCache, cp
// pdb: hkpMapPointsToSubShapeContactMgr::addContactPointImpl | hkpConvexListAgent3.obj | fnv360_0822_retail, vtable, high (was: ProcessConvexListChildren)
unsigned short hkpConvexListProcessorD333::hkpMapPointsToSubShapeContactMgr_addContactPointImpl(const hkpCdBodyD333& kBodyA, const hkpCdBodyD333& kBodyB,
                                                          const void* pvInput, const void* pvTransform,
                                                          hkpGskCacheD333* pkCache, void* pvOutput) throw()
{
    hkpCdBodyD333 wrapper2;
    hkpShapeBufferD333 buffer;
    hkpCdBodyD333 wrapper1;

    const hkpCdBodyD333* bodyA = &kBodyA;
    const hkpCdBodyD333* bodyB = &kBodyB;

    if (kBodyA.m_pCollisionShape->m_type == 0x15)
    {
        int keyA = pkCache->m_kVertices[0] >> 8;
        for (int i = 1; i < pkCache->m_ucDimensionA; ++i)
        {
            if ((pkCache->m_kVertices[i] >> 8) != keyA)
            {
                m_invalidCache = 1;
                return -1;
            }
        }
        const hkpShapeD333* shape = static_cast<const hkpShapeCollectionD333*>(kBodyA.m_pCollisionShape)
                                        ->m_container.GetShapeForKey(keyA, &buffer);
        wrapper1.m_uiCollisionShapeKey = keyA;
        wrapper1.m_parent = &kBodyA;
        wrapper1.m_pMotionState = kBodyA.m_pMotionState;
        wrapper1.m_pCollisionShape = shape;
        bodyA = &wrapper1;
    }

    if (kBodyB.m_pCollisionShape->m_type == 0x15)
    {
        int keyB = pkCache->m_kVertices[pkCache->m_ucDimensionA] >> 8;
        for (int i = pkCache->m_ucDimensionA + 1; i < pkCache->m_ucDimensionB + pkCache->m_ucDimensionA; ++i)
        {
            if ((pkCache->m_kVertices[i] >> 8) != keyB)
            {
                m_invalidCache = 1;
                return -1;
            }
        }
        const hkpShapeD333* shape = static_cast<const hkpShapeCollectionD333*>(kBodyB.m_pCollisionShape)
                                        ->m_container.GetShapeForKey(keyB, &buffer);
        wrapper2.m_parent = &kBodyB;
        wrapper2.m_pMotionState = kBodyB.m_pMotionState;
        wrapper2.m_pCollisionShape = shape;
        wrapper2.m_uiCollisionShapeKey = keyB;
        bodyB = &wrapper2;
    }

    return m_processor->process(*bodyA, *bodyB, pvInput, pvTransform, pkCache, pvOutput);
}


struct ValueBlock
{
    void FUN_00d33330(ValueBlock* destination);
};

struct Callback
{
    virtual void Reserved00();
    virtual void Reserved04();
    virtual void Reserved08();
    virtual void Reserved0c();
    virtual void Reserved10();
    virtual void Reserved14();
    virtual void Reserved18();
    virtual void Reserved1c();
    virtual void OnValueChange(unsigned int identifier, void* data);
};

void __cdecl FUN_00ec44d0(void* target, const void* input, unsigned int byteCount);

struct Container
{
    unsigned int tag;
    void FUN_00d33600(void* unusedA, void* unusedB, char* source, Callback* callback);
};

// Compares the source's time field with this object's, notifies the callback and copies the value block on change, then copies the tag and payload.
// @fnv 0x00d33600
// pdb: hkpProcessCollisionOutputBackup::rollbackOutput | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: bodyA, bodyB, output, mgr
void Container::FUN_00d33600(void* unusedA, void* unusedB, char* source, Callback* callback)
{
    float sourceTime = *reinterpret_cast<float*>(source + 0x3030);
    char* destination = reinterpret_cast<char*>(this);

    if (sourceTime != *reinterpret_cast<float*>(destination + 0x1030))
    {
        callback->OnValueChange(*reinterpret_cast<unsigned int*>(source + 4), source + 0x3050);
        reinterpret_cast<ValueBlock*>(source + 0x3010)
            ->FUN_00d33330(reinterpret_cast<ValueBlock*>(destination + 0x1010));
    }

    *reinterpret_cast<unsigned int*>(source) = tag;
    void* output = *reinterpret_cast<void**>(source + 0x3080);
    if (output != 0)
    {
        FUN_00ec44d0(output, destination + 4, 0x1008);
    }
}

void __cdecl hkAgent1nMachine_Destroy(int* data, void* collector, void* input, void* output);

void __cdecl FUN_00d41860();
// @fnv 0x00d32bd0
// pdb: TESSpellList::ClearDataComponent | TESSpellList.obj | fnv360_0822_retail, vtable, medium
void __cdecl FUN_00d32bd0(int a, int b, int c)
{
    FUN_00d41860();
}

struct hkpAgent3FuncsD331
{
    hkpAgent3FuncsD331()
    {
        m_bIsPredictive = false;
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction7 = 0;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

class hkpCollisionDispatcherD331
{
  public:
    void AddEntry(const hkpAgent3FuncsD331& kFuncs, int iTypeA, int iTypeB);
};

// Initializes a hkpAgent3FuncsD331 via FUN_00d33140 and adds two entries to pkDispatcher for type pairs 0x12/0x16 and 0x16/0x16.
// @f3 0x009bcf60 (community match, verified in this file)
void __cdecl FUN_009bcf00(hkpAgent3FuncsD331& kFuncs);

// pdb: hkConvexListAgent3::registerAgent3 | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun_prop, high
// pdb params: dispatcher
// pdb: hkConvexListAgent3::registerAgent3 | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun_prop, high (was: RegisterAgent3Entries)
void __cdecl hkConvexListAgent3_registerAgent3(hkpCollisionDispatcherD331* pkDispatcher)
{
    __declspec(align(16)) hkpAgent3FuncsD331 kFuncs;
    FUN_009bcf00(kFuncs);
    pkDispatcher->AddEntry(kFuncs, 1, 0x15);
    pkDispatcher->AddEntry(kFuncs, 0x15, 0x15);
}


#include <xmmintrin.h>

struct __declspec(align(16)) HK_Stage_t
{
    int d00;
    int d04;
    int d08;
    int d0c;
    int d10;
    int d14;
    int d18;
    int d1c;
    int d20;
    int d24;
    int d28;
    int d2c;
    int d30;
    int d34;
    int d38;
    int d3c;
};

#include <string.h>
struct __declspec(align(16)) FUN_00d33330_t
{
    __m128 first;
    __m128 second;
    int alpha, beta;
    int VirtualFunction28, reserved2c;
    int gamma, delta;
    volatile int epsilon, zeta;
    int coefficients[12];
    FUN_00d33330_t& FUN_00d33330(const FUN_00d33330_t& other);
    void FUN_00aad5f0();
    FUN_00d33330_t& FUN_00d33330(const FUN_00d33330_t& first, const FUN_00d33330_t& second, const FUN_00d33330_t& third);
};
// Copies first, second, alpha, beta, gamma, delta, epsilon, zeta and 48 bytes of coefficients from other, and returns *this.
// @f3 0x0046c6c0 (community match, verified in this file)
// Bounding box object: base object, then centre and extent, then (derived) a 3x3 orientation.
// The served name is a member function, but the routine is the object's constructor:
// it runs the base constructor, fills centre and extent, then the orientation.
struct D33330_Point3
{
    float x, y, z;
};

struct D33330_Matrix3
{
    float entry[9];
};

struct D33330_Object
{
    D33330_Object() throw();
    virtual ~D33330_Object();
    int refCount;
    int unk08;
};

struct D33330_Box : D33330_Object
{
    D33330_Point3 centre;
    D33330_Point3 extent;
    D33330_Box(const D33330_Point3& c, const D33330_Point3& e) : centre(c), extent(e) {}
    virtual ~D33330_Box();
};

struct D33330_OrientedBox : D33330_Box
{
    D33330_Matrix3 axes;
    __forceinline D33330_OrientedBox(const D33330_Point3& c, const D33330_Point3& e, const D33330_Matrix3& m)
        : D33330_Box(c, e), axes(m) {}
    virtual ~D33330_OrientedBox();
};

// pdb: BSMultiBoundOBB::BSMultiBoundOBB | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arCenter, arHalfExtents, arAxis
FUN_00d33330_t& FUN_00d33330_t::FUN_00d33330(const FUN_00d33330_t& first, const FUN_00d33330_t& second, const FUN_00d33330_t& third)
{
    const D33330_Point3& centre = reinterpret_cast<const D33330_Point3&>(first);
    const D33330_Point3& extent = reinterpret_cast<const D33330_Point3&>(second);
    const D33330_Matrix3& axes = reinterpret_cast<const D33330_Matrix3&>(third);
    D33330_OrientedBox* box = reinterpret_cast<D33330_OrientedBox*>(this);
    box->D33330_OrientedBox::D33330_OrientedBox(centre, extent, axes);
    return *this;
}


extern const float DAT_0104da48 = 3.402820018375656e+38F;
struct CollisionRecord
{
    __m128 position;
    __m128 normal;
    __m128 properties;
};
struct SmallState
{
    float a;
    float b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct CollisionState
{
    SmallState* copyScalars(const CollisionState& s)
    {
        unk40 = s.unk40;
        unk44 = s.unk44;
        unk48 = s.unk48;
        unk4c = s.unk4c;
        return &extra;
    }
    __m128 vector0;
    __m128 vector1;
    float distance;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    SmallState extra;
};
struct LargeOutput
{
    int header;
    int unk04;
    int unk08;
    int unk0c;
    CollisionRecord contacts[256];
    CollisionState state;
    void* data;
};
class FUN_00d33670
{
  public:
    int header;
    unsigned char data[0x1008];
    int unk100c;
    CollisionState state;
    FUN_00d33670(const LargeOutput& src);
};

#include <xmmintrin.h>
namespace fnv_00d32cd0 {
#include <windows.h>
#include <string.h>

struct __declspec(align(16)) FourFloatVector
{
    union
    {
        __m128 v;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct Transform
{
    FourFloatVector rotation0, rotation1, rotation2, translation;
    void FUN_00cb22f0(Transform*, Transform*);
};
struct Shape
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44;
    int childCount;
    int unk4c;
    int children;
};
struct Body
{
    Shape* shape;
    int key;
    Transform* transform;
    Body* parent;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float radius;
};
struct Cache
{
    int first, second;
    unsigned int state;
};
struct Contact
{
    FourFloatVector position, normal;
};
struct Basis
{
    FourFloatVector x, y, z;
};
struct ContactIDs
{
    int id0, id1, id2, id3;
};
struct CacheState
{
    FourFloatVector first, second;
    union
    {
        float time;
        unsigned int timeBits;
    };
    int key;
    int unk28, unk2c;
    ContactIDs ids;
    Basis transform;
    __forceinline void assign(const CacheState& source)
    {
        first.v = source.first.v;
        second.v = source.second.v;
        timeBits = source.timeBits;
        key = source.key;
        ids = source.ids;
        transform = source.transform;
    }
};
struct Output
{
    int count;
    int owner;
    int unk08, unk0c;
    Contact contacts[384];
    CacheState cache;
    void* savedContacts;
};
struct Manager
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20(int, Basis*);
};
struct StateRecord
{
    union
    {
        int packed;
        struct
        {
            short countdown;
            unsigned char count;
            char unk0f;
        };
    };
    Cache cache;
};
struct Agent
{
    int unk00, unk04;
    short unk08;
    char unk0a;
    unsigned char flags;
    StateRecord state;
};
struct FUN_00d33670
{
    int count;
    int owner;
    int unk08, unk0c;
    Contact contacts[128];
    CacheState cache;
    FUN_00d33670(Output*);
    void FUN_00d33600(Body*, Body*, Output*, Manager*);
};
void __cdecl hkAgent1nMachine_Destroy(Cache*, int, Manager*, int);
void __cdecl FUN_00d41860(int, Agent*, Manager*, int);

}  // namespace fnv_00d32cd0

class hkpLinearCastProcessorD334
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual int process(const hkpCdBodyD333* pkBodyA, const hkpCdBodyD333* pkBodyB, int iArg3, int iArg4, float fArg5,
                        int iArg6, hkpGskCacheD333* pkCache, int iArg8, int iArg9) throw();
};

class hkpConvexListLinearCastD334 : public hkpConvexListProcessorD333
{
  public:
    int FUN_00d334c0(const hkpCdBodyD333* a1, const hkpCdBodyD333* a2, int a3, int a4, float a5, int a6,
                     hkpGskCacheD333* a7, int a8, int a9);
};

// Resolves shape collection sub-shapes for both bodies if needed, then delegates to the linear cast processor's process method.
// @f3 0x009bd350 (community match, verified in this file)
int hkpConvexListLinearCastD334::FUN_00d334c0(const hkpCdBodyD333* apBodyA, const hkpCdBodyD333* apBodyB, int a3,
                                              int a4, float a5, int a6, hkpGskCacheD333* apCache, int a8, int a9)
{
    hkpCdBodyD333 wrapper2;
    hkpShapeBufferD333 buffer;
    hkpCdBodyD333 wrapper1;

    const hkpCdBodyD333* bodyA = apBodyA;
    const hkpCdBodyD333* bodyB = apBodyB;

    if (apBodyA->m_pCollisionShape->m_type == 0x15)
    {
        int keyA = apCache->m_kVertices[0] >> 8;
        for (int i = 1; i < apCache->m_ucDimensionA; ++i)
        {
            if ((apCache->m_kVertices[i] >> 8) != keyA)
            {
                m_invalidCache = 1;
                return 1;
            }
        }
        const hkpShapeD333* shape = static_cast<const hkpShapeCollectionD333*>(apBodyA->m_pCollisionShape)
                                        ->m_container.GetShapeForKey(keyA, &buffer);
        wrapper1.m_uiCollisionShapeKey = keyA;
        wrapper1.m_parent = apBodyA;
        wrapper1.m_pMotionState = apBodyA->m_pMotionState;
        wrapper1.m_pCollisionShape = shape;
        bodyA = &wrapper1;
    }

    if (apBodyB->m_pCollisionShape->m_type == 0x15)
    {
        int keyB = apCache->m_kVertices[apCache->m_ucDimensionA] >> 8;
        for (int i = apCache->m_ucDimensionA + 1; i < apCache->m_ucDimensionB + apCache->m_ucDimensionA; ++i)
        {
            if ((apCache->m_kVertices[i] >> 8) != keyB)
            {
                m_invalidCache = 1;
                return 1;
            }
        }
        const hkpShapeD333* shape = static_cast<const hkpShapeCollectionD333*>(apBodyB->m_pCollisionShape)
                                        ->m_container.GetShapeForKey(keyB, &buffer);
        wrapper2.m_parent = apBodyB;
        wrapper2.m_pMotionState = apBodyB->m_pMotionState;
        wrapper2.m_pCollisionShape = shape;
        wrapper2.m_uiCollisionShapeKey = keyB;
        bodyB = &wrapper2;
    }

    return reinterpret_cast<hkpLinearCastProcessorD334*>(m_processor)
        ->process(bodyA, bodyB, a3, a4, a5, a6, apCache, a8, a9);
}


// @f3twin 0x009bd060 of 0x0095b090
struct F3Twin_009bd060 : public FnvCpu_FUN_00d33230_CpuOwner { void hkpMapPointsToSubShapeContactMgr_removeContactPointImpl(int arg0) ; };
// pdb: hkpMapPointsToSubShapeContactMgr::removeContactPointImpl | hkpConvexListAgent3.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void F3Twin_009bd060::hkpMapPointsToSubShapeContactMgr_removeContactPointImpl(int arg0) 
{
    target->Invoke(arg0);
}
