#include "f3_common.h"
// src/staging/blk_00d40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00c9ce00_cls
{
    void __thiscall FUN_00c9ce00(int);
};

// @f3 0x009d4820 (community match, verified in this file)
struct FUN_0090b6c0_arg
{
    int iValue;
};
struct FUN_0090b6c0_cls
{
    void __thiscall FUN_0090b6c0(FUN_0090b6c0_arg);
};
extern int DAT_00e35e28;

void __cdecl FUN_00d49530(FUN_00c9ce00_cls* pObject, int aiValue)
{
    if (pObject)
    {
        FUN_0090b6c0_arg kArg;
        kArg.iValue = 1;
        ((FUN_0090b6c0_cls*)pObject)->FUN_0090b6c0(kArg);
        *(int*)pObject = (int)&DAT_00e35e28;
    }
}


extern "C" void __cdecl AppendEventRecord(int, int, int, int);

// @fnv 0x00d4de30
// pdb: hkBeginConstraints | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpBreakableConstraintData::buildNopJacobian)
// pdb params: in, out, sr, solverResultStriding
void __stdcall FUN_00d4de30(int a, int b)
{
    AppendEventRecord(a, b, 0, 8);
}

struct NiStream
{
    unsigned int ReadUnsignedInteger();
};

struct FUN_00d53200_class
{
    void FUN_00c8a230(NiStream& stream);
    void FUN_00d53200(NiStream& stream);
};

// @fnv 0x00d53200
void FUN_00d53200_class::FUN_00d53200(NiStream& stream)
{
    stream.ReadUnsignedInteger();
    FUN_00c8a230(stream);
}

void* __cdecl hkBoxBoxAgent3_create(void*, void*, void*);
void __cdecl RemoveEntryByKey(void);
void __cdecl hkBoxBoxAgent3_commitPotential(void);
void __cdecl FUN_00d3fde0(void);
void __cdecl hkBoxBoxAgent3_cleanup(void);
void __cdecl FUN_00d3fe70(void);
void __cdecl FUN_00d3fe90(void);

// Fills the object's function-pointer slots with the given handlers, zeroes slots 6 and 10, and clears the byte at offset 0x30.
// @fnv 0x00d400f0
void __cdecl FUN_00d400f0(void* apObject)
{
    void** f = (void**)apObject;
    f[0] = (void*)&hkBoxBoxAgent3_create;
    f[11] = (void*)&FUN_00d3fe90;
    f[10] = 0;
    f[2] = (void*)&hkBoxBoxAgent3_cleanup;
    f[3] = (void*)&RemoveEntryByKey;
    f[4] = (void*)&hkBoxBoxAgent3_commitPotential;
    f[5] = (void*)&FUN_00d3fde0;
    f[6] = 0;
    f[1] = (void*)&FUN_00d3fe70;
    ((char*)f)[0x30] = 0;
}

void __cdecl DispatchInputRecord();
void __cdecl hkPredGskAgent3_process();
void __cdecl FUN_00d41930();
void __cdecl FUN_00d41860();
void __cdecl hkPredGskAgent3_removePoint();
void __cdecl hkPredGskAgent3_commitPotential();
void __cdecl hkPredGskAgent3_createZombie();
void __cdecl ForwardToTarget();

// Fills the object's vtable slots with function pointers and sets the byte at p+48 to 1.
// @fnv 0x00d41ec0
// pdb: hkPredGskAgent3::initAgentFunc | hkpPredGskAgent3.obj | fnv360_0822_retail, objrun + bridge(hash|objrun) + skyrim(call_gap), high
void __cdecl hkPredGskAgent3_initAgentFunc(int* pObject)
{
    *pObject = (int)&DispatchInputRecord;
    pObject[0x2c / 4] = (int)&hkPredGskAgent3_process;
    pObject[0x28 / 4] = (int)&FUN_00d41930;
    pObject[2] = (int)&FUN_00d41860;
    pObject[3] = (int)&hkPredGskAgent3_removePoint;
    pObject[4] = (int)&hkPredGskAgent3_commitPotential;
    pObject[5] = (int)&hkPredGskAgent3_createZombie;
    pObject[1] = (int)&ForwardToTarget;
    *(unsigned char*)(pObject + 12) = 1;
}

extern int DAT_010cf9a4;

struct FUN_00d49580_vtbl
{
    virtual void v0(int);
};

// @fnv 0x00d49580
// pdb: hkEnum<enum hkpMeshShape::MeshShapeMaterialIndexStridingType,signed char>::operator== | hkpStorageMeshShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: cleanupLoadedObjecthkpStorageExtendedMeshShape)
// pdb params: e
void __cdecl FUN_00d49580(FUN_00d49580_vtbl* p)
{
    p->v0(0);
}

extern int DAT_010cfb34;

// @fnv 0x00d4b190
// pdb: cleanupLoadedObjecthkbStateMachine | hkbBehaviorReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00d4b190(void* p)
{
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(p))[0])(p, 0);
}

struct FUN_00d4b250_vt
{
    virtual void __thiscall FUN_00d4b250(int);
};
// @fnv 0x00d4b250
// pdb: cleanupLoadedObjecthkpStorageMeshShape | hkpCollidehkpMeshShapeReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00d4b250(FUN_00d4b250_vt* p)
{
    p->FUN_00d4b250(0);
}

struct FUN_00d4be50_vt
{
    virtual void FUN_00d4be50(int);
};
// @fnv 0x00d4be50
// pdb: cleanupLoadedObjecthkpPhysicsData | hkpPhysicsDataClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00d4be50(FUN_00d4be50_vt* p)
{
    p->FUN_00d4be50(0);
}

struct CollisionAgentFunctionTable
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    bool b0;
    bool b1;
};
struct Agent
{
    void __thiscall FUN_00cfbbe0(CollisionAgentFunctionTable*, int, int);
};

struct FUN_00d48330_vt
{
    virtual void v0(int);
};
// @fnv 0x00d48330
// pdb: cleanupLoadedObjecthkpExtendedMeshShape | hkpCollidehkpExtendedMeshShapeReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00d48330(FUN_00d48330_vt* p)
{
    p->v0(0);
}

// @fnv 0x00d49510
// pdb: hkEnum<enum hkpMeshShape::MeshShapeIndexStridingType,signed char>::operator== | hkpStorageMeshShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: cleanupLoadedObjecthkpStorageExtendedMeshShapeShapeSubpartStorage)
// pdb params: e
void __cdecl FUN_00d49510(FUN_00d49580_vtbl* p)
{
    p->v0(0);
}

struct FUN_00d4b1f0_vt
{
    virtual void __thiscall FUN_00d4b1f0(int);
};
// @fnv 0x00d4b1f0
// pdb: cleanupLoadedObjecthkpStorageMeshShapeSubpartStorage | hkpCollidehkpMeshShapeReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00d4b1f0(FUN_00d4b1f0_vt* p)
{
    p->FUN_00d4b1f0(0);
}

struct FUN_00d4b320_vt
{
    virtual void v0(int);
};
// @fnv 0x00d4b320
// pdb: cleanupLoadedObjecthkpMeshShape | hkpCollidehkpMeshShapeReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00d4b320(FUN_00d4b320_vt* p)
{
    p->v0(0);
}

// @fnv 0x00d4beb0
void __cdecl FUN_00d4beb0(FUN_00d49580_vtbl* p)
{
    p->v0(0);
}

struct FUN_00d4bf30_vt
{
    virtual void FUN_00d4bf30(int);
};

// @fnv 0x00d4bf30
// pdb: hkSkipSolverResults | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00d4bf30(FUN_00d4bf30_vt* p)
{
    p->FUN_00d4bf30(0);
}

extern const char* const g_01268eb4_arg1;
// @fnv 0x00d4bf60
const char* const* __cdecl FUN_00d4bf60()
{
    return &g_01268eb4_arg1;
}

struct FUN_00d532a0_cls
{
    void __thiscall DispatchToInnerSlot(int);
    void __thiscall ApplyToAllEntries(int arg);
};

// @f3 0x009e0cd0 (community match, verified in this file)
// pdb: bhkConstraintChain::RegisterStreamables | bhkConstraintChain.obj | fnv360_0822_retail, objrun, low
// pdb params: arStream
void __thiscall FUN_00d532a0_cls::ApplyToAllEntries(int aiValue)
{
    int* p = this ? *(int**)((char*)this + 8) : 0;
    int i = 0;
    if (p[0xc] > 0)
    {
        do
        {
            int* e = *(int**)((char*)p + 0x2c);
            int* obj = *(int**)((char*)e + i * 4);
            int* v;
            if (obj)
                v = *(int**)((char*)obj + 0xc);
            else
                v = 0;
            void(__thiscall * pfnMethod)(void*, int) = *(void(__thiscall**)(void*, int))(*(int*)v + 0x54);
            pfnMethod(v, aiValue);
            ++i;
        } while (i < p[0xc]);
    }
    DispatchToInnerSlot(aiValue);
}


// CreateSpawnObject: cdecl factory. Allocates one of two object sizes through the
// global allocator holder. A non-zero flag selects the large object (0x80 bytes,
// constructor takes the flag, then the vtable is stored); zero selects the small
// object (0x30 bytes, constructor returns the object).

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

AllocHolder* __cdecl FUN_00c85750();

namespace fnv_00d42800 {
struct D42800Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D42800MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D42800Allocator* m_pStreamAllocator;

    D42800Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D42800MemoryRouter& __cdecl FUN_00c85750();

struct D42800Collidable;
struct D42800CollisionInput;
struct D42800ContactMgr;

class D42800Shape
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void HandleCollision(const D42800Collidable* pkA, const D42800Collidable* pkB,
                                 const D42800CollisionInput& kInput);
};

struct D42800CdBody
{
    D42800Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const D42800CdBody* m_parent;

    const D42800Collidable* getRootCollidable() const
    {
        const D42800CdBody* pkBody = this;
        while (pkBody->m_parent)
            pkBody = pkBody->m_parent;
        return reinterpret_cast<const D42800Collidable*>(pkBody);
    }
};

class D42800ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D42800ReferencedObject* b =
            static_cast<D42800ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D42800Agent : public D42800ReferencedObject
{
  public:
    D42800Agent(const D42800CdBody& kBodyA, const D42800CdBody& kBodyB, D42800ContactMgr* pkMgr) throw();

    int unk08;
    int unk0C;
    int unk10;
    D42800Shape* m_pkShapeA;
    D42800Shape* m_pkShapeB;
    int m_iTypeA;
    int m_iTypeB;
};

// @fnv 0x00d42800
D42800Agent* FUN_00d42800(const D42800CdBody& kBodyA, const D42800CdBody& kBodyB, const D42800CollisionInput& kInput,
                          D42800ContactMgr* pkMgr)
{
    D42800Agent* pkAgent = new D42800Agent(kBodyA, kBodyB, pkMgr);
    if (pkAgent->m_iTypeA == 0x1d)
    {
        D42800Shape* pkShape = kBodyA.m_pCollisionShape;
        pkShape->HandleCollision(kBodyA.getRootCollidable(), kBodyB.getRootCollidable(), kInput);
        pkAgent->m_pkShapeA = pkShape;
    }
    if (pkAgent->m_iTypeB == 0x1d)
    {
        D42800Shape* pkShape = kBodyB.m_pCollisionShape;
        pkShape->HandleCollision(kBodyB.getRootCollidable(), kBodyA.getRootCollidable(), kInput);
        pkAgent->m_pkShapeB = pkShape;
    }
    return pkAgent;
}
}  // namespace fnv_00d42800

struct FNVDispatchType
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
    virtual void v11(void* first, void* second, int code);
    int m_unk04;
    int m_unk08;
    int m_typeId;
};

struct FNVDispatchNode
{
    FNVDispatchType* m_pName;
    int m_unk04;
    int m_unk08;
    FNVDispatchNode* m_pNext;
};

static FNVDispatchNode* FNVTailOf(FNVDispatchNode* n)
{
    FNVDispatchNode* t = n;
    while (t->m_pNext != 0)
    {
        t = t->m_pNext;
    }
    return t;
}

// If either node's dispatch type has typeId 0x1d, calls its v11 with the two lists' tails and the code, then returns 0.
// @f3 0x009cd320 (community match, verified in this file)
struct S_009cd320_Name
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void v09(void* first, void* second, int code);
};

// pdb: hkpPhantomAgent::createNoPhantomAgent | hkpPhantomAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, mgr
// pdb: hkpPhantomAgent::createNoPhantomAgent | hkpPhantomAgent.obj | fnv360_0822_retail, objrun, high (was: DispatchToType1dNodes)
int __cdecl hkpPhantomAgent_createNoPhantomAgent(FNVDispatchNode* pNodeA, FNVDispatchNode* pNodeB, int iCode)
{
    if (pNodeA->m_pName->m_typeId == 0x1d)
    {
        FNVDispatchNode* pTailB = FNVTailOf(pNodeB);
        FNVDispatchNode* pTailA = FNVTailOf(pNodeA);
        ((S_009cd320_Name*)pNodeA->m_pName)->v09(pTailA, pTailB, iCode);
    }
    if (pNodeB->m_pName->m_typeId == 0x1d)
    {
        FNVDispatchNode* pTailA = FNVTailOf(pNodeA);
        FNVDispatchNode* pTailB = FNVTailOf(pNodeB);
        ((S_009cd320_Name*)pNodeB->m_pName)->v09(pTailB, pTailA, iCode);
    }
    return 0;
}


void __cdecl FUN_00d42800();
void __cdecl hkpPhantomAgent_staticGetPenetrations();
void __cdecl FUN_00d42760();
void __cdecl FUN_00d42780();

// @fnv 0x00d42960
// pdb: hkpPhantomAgent::registerAgent | hkpPhantomAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void __cdecl FUN_00d42960(Agent* apAgent)
{
    CollisionAgentFunctionTable s;
    s.b0 = 0;
    s.f0 = (void*)FUN_00d42800;
    s.f1 = (void*)hkpPhantomAgent_staticGetPenetrations;
    s.f2 = (void*)FUN_00d42760;
    s.f3 = (void*)FUN_00d42780;
    s.b1 = 1;
    apAgent->FUN_00cfbbe0(&s, 0x1d, -1);
    apAgent->FUN_00cfbbe0(&s, -1, 0x1d);
}

namespace fnv_00d44280 {
// AllocateAndInitBlock : allocates a 0x38 byte block through the global allocator holder,
// stamps the block header size and runs the block constructor with the four
// incoming arguments.

// Allocator vtable: slot 0 is unused, slot 1 hands out raw blocks.
struct Allocator
{
    virtual void* v0();
    virtual void* v1(unsigned int nSize);
};

// Global allocator holder: the allocator pointer sits at +0x10.
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pAllocator;
};

extern Holder* __cdecl FUN_00c85750();

}  // namespace fnv_00d44280

namespace fnv_00d442c0 {
struct D442C0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D442C0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D442C0Allocator* m_pStreamAllocator;

    D442C0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D442C0MemoryRouter& __cdecl FUN_00c85750();

class D442C0ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D442C0ReferencedObject* b =
            static_cast<D442C0ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D442C0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D442C0Agent : public D442C0ReferencedObject
{
  public:
    __declspec(nothrow) D442C0Agent(const void* a, const void* b, const void* input, void* mgr);

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
};

class D442C0ShapeAgent : public D442C0Agent
{
  public:
    D442C0ShapeAgent(const void* a, const void* b, const void* input, void* mgr) : D442C0Agent(a, b, input, mgr)
    {}
    virtual ~D442C0ShapeAgent();
};

}  // namespace fnv_00d442c0

extern int DAT_01268b9c;

// @fnv 0x00d48340
void* __cdecl FUN_00d48340()
{
    return &DAT_01268b9c;
}

extern int DAT_010cf9a4;
// @fnv 0x00d48360
// pdb: getVtablehkpSerializedDisplayRbTransforms | hkpSerializedDisplayRbTransformsClass.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00d48360()
{
    return &DAT_010cf9a4;
}

struct S_00d483a0_Result
{
    char v;
    S_00d483a0_Result()
    {}
    S_00d483a0_Result(char c)
    {
        v = c;
    }
};

// InitAndCall: cdecl, 5 stack args. Builds a 12-byte temp from (a1, a2),
// reads a field of the temp's returned pointer, calls a 4-arg cdecl helper,
// then disposes the temp and returns the helper result.

// Initialises a KeyTemp from a1 and a2, calls FUN_00d48fc0 with the stored pointer and a3/a4/a5, disposes the temp and returns the result.
// @f3 0x00935f40 (community match, verified in this file)
namespace q935f40 {
extern const char DAT_00e43f14[];
extern const char DAT_00e3d9c4[];
extern const char DAT_00e3d9ac[];
struct Member { int FUN_0093dac0(); };
struct Field {
    char* data;
    int count;
    Field(void* obj, const char* name);
    Member* FUN_0093d790();
    Field* FUN_0093d660();
    int* FUN_0093d6b0(int index);
};
static __declspec(noinline) void FUN_00935ea0(Field* src, Field* dst)
{
    int srcStride = src->FUN_0093d790()->FUN_0093dac0();
    int dstStride = dst->FUN_0093d790()->FUN_0093dac0();
    Field* s = src->FUN_0093d660();
    Field* d = dst->FUN_0093d660();
    char* sp = s->data;
    int n = s->count;
    char* dp = d->data;
    for (; n > 0; --n) {
        *(int*)dp = *(int*)sp;
        sp += srcStride;
        dp += dstStride;
    }
}
}
void* __cdecl InitAndCall(void* volatile a1, void* volatile a2, void* volatile a3, void* volatile a4, void* volatile a5)
{
    q935f40::Field a(a1, q935f40::DAT_00e43f14);
    void* v2 = a2;
    q935f40::Field b(v2, q935f40::DAT_00e43f14);
    q935f40::FUN_00935ea0(&a, &b);
    q935f40::Field c(v2, q935f40::DAT_00e3d9c4);
    q935f40::Field d(v2, q935f40::DAT_00e3d9ac);
    int* p = c.FUN_0093d6b0(0);
    *p = -1;
    int* q = d.FUN_0093d6b0(0);
    *q = -1;
    return q;
}


extern int DAT_01268bcc;

// @fnv 0x00d49520
// pdb: getVtablehkpPoweredChainMapper | hkpPoweredChainMapperClass.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00d49520()
{
    return &DAT_01268bcc;
}

extern int DAT_01268c14;

// @fnv 0x00d49590
int __cdecl FUN_00d49590()
{
    return (int)&DAT_01268c14;
}

extern int DAT_010cfb34;

// @fnv 0x00d495f0
int __cdecl FUN_00d495f0()
{
    return reinterpret_cast<int>(&DAT_010cfb34);
}

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00d49c40(unsigned int unusedArg);
};

struct FUN_00d49c50_cls
{
    volatile void* m_pVtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    volatile void* m_pVtblAlt;
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
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6C;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7C;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8C;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9C;
    int m_unkA0;
    int m_unkA4;
    int m_unkA8;
    int m_unkAC;
    int m_unkB0;
    int m_unkB4;
    int m_unkB8;
    int m_unkBC;
    int m_unkC0;
    int m_unkC4;
    int m_unkC8;
    int m_unkCC;
    int m_unkD0;
    int m_unkD4;
    int m_unkD8;
    int m_unkDC;
    int m_unkE0;
    int m_unkE4;
    int m_unkE8;
    int m_unkEC;
    volatile int m_iF0;
    volatile int m_iF4;
    volatile int m_iF8;
    volatile int m_iFC;
    volatile int m_i100;
    volatile int m_i104;
    void FUN_00d569c0(float f, int i);
    void* FUN_00d49c50(float f, int i);
};

// Calls FUN_00d569c0, sets both vtables, and initializes the six fields at offsets 0xF0-0x104, returning this.
// @f3 0x009d5190 (community match, verified in this file)
extern int DAT_00e7fa88;
extern int DAT_00e7fa64;

struct FUN_009e4660_stub
{
    void FUN_009e4660(float f, int i);
};

// pdb: hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, caller_sim, high
// pdb params: radius, numbits
void* FUN_00d49c50_cls::FUN_00d49c50(float afValue, int i)
{
    reinterpret_cast<FUN_009e4660_stub*>(this)->FUN_009e4660(afValue, i);
    *(void* volatile*)&m_pVtbl = (void*)&DAT_00e7fa88;
    *(void* volatile*)&m_pVtblAlt = (void*)&DAT_00e7fa64;
    *(volatile int*)&m_unkC0 = 0;
    *(volatile int*)&m_unkC4 = 0;
    *(volatile int*)&m_unkC8 = 0x80000000u;
    *(volatile int*)&m_unkCC = 0;
    *(volatile int*)&m_unkD0 = 0;
    *(volatile int*)&m_unkD4 = 0x80000000u;
    return this;
}


extern "C" int DAT_01268c8c;

// @fnv 0x00d4b160
// pdb: hkpConstraintChainInstance::staticClass | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
extern "C" void* __cdecl FUN_00d4b160()
{
    return &DAT_01268c8c;
}

extern int DAT_01268cbc;

// @fnv 0x00d4b1c0
// pdb: getVtablehkpRotationalConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void* __cdecl FUN_00d4b1c0()
{
    return &DAT_01268cbc;
}

extern int DAT_01268d04;

// @fnv 0x00d4b220
// pdb: getVtablehkpRagdollLimitsData | hkpRagdollLimitsDataClass.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00d4b220()
{
    return reinterpret_cast<int>(&DAT_01268d04);
}

extern int DAT_01268d4c;
// @fnv 0x00d4b280
// pdb: getVtablehkpRagdollConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
int* __cdecl FUN_00d4b280()
{
    return &DAT_01268d4c;
}

extern int DAT_01268d94;
// @fnv 0x00d4b2a0
void* __cdecl FUN_00d4b2a0()
{
    return &DAT_01268d94;
}

extern unsigned char DAT_01268dc4;
// @fnv 0x00d4b2c0
void* __cdecl FUN_00d4b2c0()
{
    return &DAT_01268dc4;
}

extern int DAT_01268df4;

// @fnv 0x00d4b2f0
void* __cdecl FUN_00d4b2f0()
{
    return &DAT_01268df4;
}

extern int DAT_01268e24;

// @fnv 0x00d4b350
void* FUN_00d4b350()
{
    return &DAT_01268e24;
}

struct TailTarget
{
    void Run();
};

// @fnv 0x00d4b380
// pdb: cleanupLoadedObjecthkpEntityExtendedListeners | hkpEntityClass.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void __cdecl cleanupLoadedObjecthkpEntityExtendedListeners(TailTarget* pTarget)
{
    pTarget->Run();
}

namespace fnv_00d4b3b0 {

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00d4b3b0(unsigned int unusedArg);
};

}  // namespace fnv_00d4b3b0

extern int DAT_01268e6c;

// @fnv 0x00d4be80
int* FUN_00d4be80()
{
    return &DAT_01268e6c;
}

extern int g_unk01268eb4;

// @fnv 0x00d4bee0
void* __cdecl FUN_00d4bee0()
{
    return &g_unk01268eb4;
}

extern int g_unk01268efc;

// @fnv 0x00d4bf00
void* __cdecl FUN_00d4bf00()
{
    return &g_unk01268efc;
}

struct D4BF10FinishFlag
{
    int m_bFinishing;
};

class D4BF10Object
{
  public:
    D4BF10Object(D4BF10FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

namespace fnv_00d4ce60 {
struct S_00d4ce60_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00d4ce60_Router
{
    int unk00, unk04, unk08, unk0C;
    S_00d4ce60_Heap* unk10;
    S_00d4ce60_Heap& heap()
    {
        return *unk10;
    }
};
S_00d4ce60_Router* FUN_00c85750();
struct S_00d4ce60_MsgBase
{
    virtual void v00();
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00d4ce60_MsgBase() throw()
    {
        unk06 = 1;
    }
};
struct S_00d4ce60_Msg : S_00d4ce60_MsgBase
{
    virtual void v00();
    S_00d4ce60_Msg() throw()
    {}
};
}  // namespace fnv_00d4ce60

namespace fnv_00d4de00 {
struct FnvCpu_FUN_00d4de00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d4de00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d4de00_CpuAllocator* allocator;
};
FnvCpu_FUN_00d4de00_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d4de00

extern int DAT_01268f74;

class FUN_00d50020_base
{
  public:
    virtual void unk00();
    ~FUN_00d50020_base();
    int unk04;
};

class FUN_00d50020 : public FUN_00d50020_base
{
  public:
    virtual ~FUN_00d50020();
    void unk08();
};

// Calls unk08() on this object and decrements the global counter DAT_01268f74.
// @fnv 0x00d50020
FUN_00d50020::~FUN_00d50020()
{
    this->unk08();
    DAT_01268f74--;
}

namespace fnv_00d50140 {
struct FUN_00d50140_tls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00d50140_tls g_tls;

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};

class FUN_00d50140_alloc
{
  public:
    virtual void v0();
    virtual void* Alloc(unsigned int size);
};

class FUN_00d50140_holder
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_00d50140_alloc* m_10;
};

class SpawnedObject
{
  public:
    unsigned int unk00;
    unsigned short m_04;
    unsigned short unk06;
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
    static void* operator new(unsigned int size);
    SpawnedObject();
};

FUN_00d50140_holder* FUN_00c85750();

class FUN_00d50140_cls
{
  public:
    unsigned int unk00;
    SpawnedObject* m_04;
    int EnsureSpawnedObject();
};

void* SpawnedObject::operator new(unsigned int size)
{
    FUN_00d50140_holder* h = FUN_00c85750();
    void* p = h->m_10->Alloc(size);
    ((SpawnedObject*)p)->m_04 = (unsigned short)size;
    return p;
}

// If m_04 is null, allocates a SpawnedObject via operator new and stores it in m_04; returns sizeof(SpawnedObject).
// @fnv 0x00d50140
int FUN_00d50140_cls::EnsureSpawnedObject()
{
    TlsFlagGuard guard;
    if (m_04 == 0)
    {
        m_04 = new SpawnedObject();
    }
    return sizeof(SpawnedObject);
}
}  // namespace fnv_00d50140

extern int DAT_01268188;
extern int DAT_01268f74;
extern __declspec(thread) int g_ThreadMemoryContext;
void* __cdecl FUN_00aa13e0(unsigned int size);

struct DataBase
{
    DataBase();
    virtual ~DataBase();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

struct DataIntermediate : DataBase
{
    int unk04;
    int unk08;
    int unk0c;
    DataIntermediate() : unk0c(0)
    {
        ++DAT_01268188;
    }
};

struct DataObject : DataIntermediate
{
    DataObject()
    {
        ++DAT_01268f74;
    }
};

struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_ThreadMemoryContext;
        g_ThreadMemoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_ThreadMemoryContext = previousContext;
    }
};

class FUN_00d51720_helper
{
  public:
    unsigned int Query();
};

class FUN_00d51720_cls
{
  public:
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;

    void InitFromHelper(void* p);
};

// Stores the helper pointer, its Query() result in m_04, and zeroes m_08, m_0c and the trailing byte fields.
// @fnv 0x00d51720
// pdb: hkpConstraintConstructionKit::begin | hkpConstraintConstructionKit.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: constraint
void FUN_00d51720_cls::InitFromHelper(void* pHelper)
{
    m_04 = reinterpret_cast<FUN_00d51720_helper*>(pHelper)->Query();
    m_00 = pHelper;
    m_08 = 0;
    m_0c = 0;
    unk10 = 0;
    unk11 = 0;
    unk12 = 0;
    unk13 = 0;
    unk14 = 0;
    unk15 = 0;
    unk18 = 0;
    unk19 = 0;
    unk16 = 0;
    *(volatile unsigned char*)&unk17 = 0;
}

struct D51760Buffer
{
    unsigned int* data;
    int count;
};

struct D51760Stats
{
    int unk00;
    int bytes;
    int unk08;
    int unk0C;
};

// @f3 0x009df600 (community match, verified in this file)
// pdb: hkpConstraintConstructionKit::computeConstraintInfo | hkpConstraintConstructionKit.obj | fnv360_0822_retail, call_seq + bridge(call_seq|objrun_prop) + skyrim(call_seq), high
void __cdecl hkpConstraintConstructionKit_computeConstraintInfo(D51760Buffer* buf, D51760Stats* stats)
{
    unsigned int* p = buf->data;
    unsigned int* end = p + buf->count;
    while (p < end)
    {
        switch (*p)
        {
        case 0:
            return;
        case 6:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 7:
            stats->bytes += 0x90;
            stats->unk08 += 3;
            stats->unk0C += 3;
            break;
        case 12:
            p++;
            stats->bytes += 0x60;
            stats->unk08 += 2;
            stats->unk0C += 2;
            break;
        case 13:
            stats->bytes += 0x90;
            stats->unk08 += 3;
            stats->unk0C += 3;
            break;
        case 16:
            p++;
            stats->bytes += 0x40;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 17:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 18:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 19:
            p += 2;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 14:
            p++;
            stats->bytes += 0x40;
            stats->unk08 += 1;
            stats->unk0C += 3;
            break;
        case 15:
            p++;
            stats->bytes += 0x50;
            stats->unk08 += 1;
            stats->unk0C += 3;
            break;
        case 20:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 2;
            break;
        case 21:
            p++;
            stats->bytes += 0x40;
            stats->unk08 += 1;
            stats->unk0C += 2;
            break;
        case 3:
        case 4:
        case 5:
        case 24:
            p++;
            break;
        }
        p++;
    }
}


namespace fnv_00d51b30 {
struct FUN_00d51b30_arr
{
    int* m_pBase;
    unsigned int m_uiCount;
    unsigned int m_uiCap;
};

struct FUN_00d51b30_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

FUN_00d51b30_holder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, FUN_00d51b30_arr* arr, int n);

}  // namespace fnv_00d51b30

namespace fnv_00d51e50 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(void* apAllocator, void* apVec, int aElemSize);

}  // namespace fnv_00d51e50

namespace fnv_00d51f90 {
struct S_00d51f90_Heap
{
    int unk00;
};
struct S_00d51f90_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d51f90_Heap* m_pStreamAllocator;
};
S_00d51f90_Router* FUN_00c85750();
struct S_00d51f90_Arr
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};
void ResizeAudioStream(S_00d51f90_Heap* heap, S_00d51f90_Arr* arr, int elemSize);
}  // namespace fnv_00d51f90

namespace fnv_00d52ba0 {
struct D52BA0Allocator;

struct D52BA0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D52BA0Allocator* m_pStreamAllocator;

    D52BA0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D52BA0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D52BA0IntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void construct(int* p, int n, const int& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    void _pushBack(D52BA0Allocator& alloc, const int& value)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(int));
        construct(m_data + m_iElementCount, 1, value);
        m_iElementCount++;
    }

    void AddBack(const int& value)
    {
        _pushBack(FUN_00c85750().heap(), value);
    }
};

}  // namespace fnv_00d52ba0

namespace fnv_00d52be0 {
extern "C" void _ReadWriteBarrier(void);

struct FUN_00d52be0_AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

FUN_00d52be0_AudioHolder* __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize) throw();

}  // namespace fnv_00d52be0

namespace fnv_00d52ca0 {
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct PairList
{
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

AllocHolder* FUN_00c85750();
void ResizeAudioStream(void* allocator, PairList* list, unsigned int elemSize);

}  // namespace fnv_00d52ca0

// FUN_00d53220 — destructor of a polymorphic class.
//
// Shape deduced from the target disassembly:
//   * SEH prologue (push -1 / handler / fs:[0]) with an EH state slot at
//     [esp+0x14] and a saved `this` slot at [esp+8]  -> destructor whose
//     unwind funclet must run the base class destructor.
//   * `mov [esi], vftable`  -> class with a virtual destructor.
//   * state 0 guards the body call to the free routine at 0x00c876a0.
//   * `dec dword ptr [0x1268f80]` -> body decrements a global counter.
//   * `mov ecx, esi / state -1 / call 0x00c89640` -> compiler-generated
//     base class destructor call (stand-in base named by its address).

extern int DAT_01268f80;
void __cdecl FUN_00c876a0(void);

// Stand-in for the polymorphic base class whose destructor lives at
// 0x00c89640. The base supplies the vfptr at offset 0, so the generated
// base-destructor call in ~FUN_00d53220 passes `this` unchanged.
struct FUN_00c89640
{
    virtual ~FUN_00c89640();
};

struct FUN_00d53220 : FUN_00c89640
{
    virtual ~FUN_00d53220();
};

// @fnv 0x00d53220
// pdb: bhkGenericConstraint::~bhkGenericConstraint | bhkGenericConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00d53220::~FUN_00d53220()
{
    FUN_00c876a0();
    --DAT_01268f80;
}

struct S_00d532f0_Data
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
    int* unk38;
    int unk3c;
};

struct S_00d532f0_Class
{
    int unk00;
    int unk04;
    S_00d532f0_Data* unk08;

    bool __thiscall IsEqualWithValues(S_00d532f0_Class* p);
    bool __thiscall CompareData(S_00d532f0_Class* p);
};

// Calls IsEqualWithValues, then compares the unk3c counts and each of the unk38 entries of this's and p's unk08 data, returning whether all match.
// @f3 0x009e0d20 (community match, verified in this file)
// pdb: bhkConstraintChain::CopyCinfo | bhkConstraintChain.obj | fnv360_0822_debug, objrun, low, conflict (bridge: bhkConstraintChain::IsEqual)
// pdb params: arInfo
bool S_00d532f0_Class::CompareData(S_00d532f0_Class* apOther)
{
    bool result = IsEqualWithValues(apOther);

    if (result)
    {
        S_00d532f0_Data* pLeftData = this ? this->unk08 : 0;
        S_00d532f0_Data* pRightData = apOther ? apOther->unk08 : 0;
        int count = pLeftData->unk30;

        result &= (count == pRightData->unk30);

        for (int i = 0; i < count; ++i)
        {
            if (!result)
            {
                break;
            }

            result &= (reinterpret_cast<int*>(pLeftData->unk2c)[i] == reinterpret_cast<int*>(pRightData->unk2c)[i]);
        }
    }

    return result;
}


class D53360BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(D53360BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(D53360BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class D53360Object;

class D53360Stream
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(D53360Object* pkObject);
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
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    D53360BinaryStream* m_pBackingStream;
};

template <class T>
inline void D53360BinaryStreamSave(D53360BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void D53360SaveBinary(D53360Stream& kStream, const T& value)
{
    D53360BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

struct D53360Entry
{
    int unk00;
    int unk04;
    int unk08;
    D53360Object* m_pPointer;
};

class D53360Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    D53360Entry** m_ppkEntries;
    unsigned int m_uiCount;

    void FUN_00c8a280(D53360Stream& kStream);
    void FUN_00d53360(D53360Stream& kStream);
};

// @fnv 0x00d53360
// pdb: bhkConstraintChain::LinkObject | bhkConstraintChain.obj | fnv360_0822_debug, objrun, low, conflict (bridge: hkConstraintChainCinfo::SaveBinary)
// pdb params: arStream
void D53360Owner::FUN_00d53360(D53360Stream& kStream)
{
    unsigned int ItemUpdateArray = m_uiCount;
    D53360SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        D53360Entry* pkEntry = m_ppkEntries[i];
        kStream.SaveLinkID(pkEntry ? pkEntry->m_pPointer : 0);
    }
    FUN_00c8a280(kStream);
}

namespace fnv_00d57120 {
struct FnvCpu_FUN_00d57120_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d57120_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d57120_CpuAllocator* allocator;
};
FnvCpu_FUN_00d57120_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d57120

extern double DAT_0101ffa0;
extern double DAT_010d0f08;
extern float DAT_011b5be0;
extern float DAT_011b5be4;

// Converts a bit count to bytes, computes a normalized scale from it, and stores the scale and its reciprocal in two globals.
// @fnv 0x00d57160
// pdb: hkpCylinderShape::setNumberOfVirtualSideSegements | hkpCylinderShape.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: numSegments
void ComputeByteScale(int bits)
{
    int bytes = bits / 8;
    float v = (float)(((double)bytes - DAT_0101ffa0) / DAT_010d0f08);
    DAT_011b5be0 = v;
    DAT_011b5be4 = 1.0f / v;
}

class ObjBaseA
{
  public:
    virtual ~ObjBaseA();
    int m_04;
    int m_08;
    int m_0c;

    ObjBaseA(int flag)
    {
        if (flag)
            *(volatile int*)&m_0c = 0;
        m_0c = 0x12;
    }
};

void __cdecl ResizeAudioStream(void*, void*, int);

extern __declspec(thread) int g_tlsMemContext;

struct ScopedMemoryContextD53
{
    int iOldContext;
    __forceinline ScopedMemoryContextD53(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    __forceinline ~ScopedMemoryContextD53()
    {
        g_tlsMemContext = iOldContext;
    }
};

class hkBool
{
  public:
    char m_cBooleanValue;
    __forceinline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct WorldObjD53
{
    char pad00[0x24];
    void* m_pvEntity;
};

struct ParamD53
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual WorldObjD53* v037();
    virtual void v038();
    virtual void v039();
    char pad04[0x14];
    unsigned int m_uiCount;
};

struct HolderD53
{
    char pad00[8];
    void* m_pvWorld;
};

struct InfoD53
{
    char pad00[0x2c];
    unsigned int m_uiFilterInfo;
};

struct ConstraintD53
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual int v037();
    virtual void v038();
    virtual void v039(ParamD53* pkParam);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050(ParamD53* pkParam);
    char pad04[4];
    HolderD53* m_pkHolder;
    char pad0c[4];
    unsigned char m_ucFlags;

    void FUN_00a29680();
};

struct EntryD53
{
    char pad00[0xc];
    ConstraintD53* m_pkConstraint;
    char pad10[0x1c];
    unsigned int m_uiFilterInfo;
};

struct ListD53
{
    char pad00[0x38];
    EntryD53** m_ppkEntries;
    int m_iArrayLength;
};

__forceinline hkBool IsInWorldD53(HolderD53* pkHolder)
{
    return pkHolder->m_pvWorld != 0;
}
__forceinline bool HasWorldD53(ConstraintD53* pkConstraint, HolderD53* pkHolder)
{
    pkConstraint->FUN_00a29680();
    bool bResult = IsInWorldD53(pkHolder);
    pkConstraint->FUN_00a29680();
    return bResult;
}

__forceinline void* GetEntityD53(WorldObjD53* pkObj)
{
    void* pvEntity = 0;
    if (pkObj)
        pvEntity = pkObj->m_pvEntity;
    return pvEntity;
}

struct FUN_00d536a0_shell
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050(void* pvEntity);
    virtual InfoD53* v051();
    char pad04[4];
    ListD53* m_pkList;

    bool UpdateConstraintEntries(ParamD53* pkParam, bool bAdd);
};

// @f3 0x009e0e70 (community match, verified in this file)
namespace co_9e0e70_ns {
// FO3 layouts (the pack's D53 types are the New Vegas ones, one vtable slot off)
struct WorldObj { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; void* entity; };
struct Param {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04(); virtual void s05();
    virtual void s06(); virtual void s07(); virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37();
    virtual WorldObj* GetWorldObject();   // 0x98
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    unsigned int count;                   // 0x20
};
struct Holder { int unk00; int unk04; void* world; };
struct hkBool { char v; hkBool(bool b) { v = (char)b; } operator bool() const { return v != 0; } };
__forceinline hkBool IsInWorld(Holder* h) { return h->world != 0; }
__forceinline bool HasWorld(Holder* h) { bool result = IsInWorld(h); return result; }
struct Constraint {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04(); virtual void s05();
    virtual void s06(); virtual void s07(); virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37();
    virtual int IsInWorld();               // 0x98
    virtual void Prepare(Param* p);        // 0x9c
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48();
    virtual void Add(Param* p);            // 0xc4
    int unk04;
    Holder* holder;                        // 0x08
    int unk0c;
    unsigned char flags;                   // 0x10
};
struct Info { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; unsigned int filterInfo; };
struct Entry { int unk00; int unk04; int unk08; Constraint* constraint; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; unsigned int filterInfo; };
struct List { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; Entry** entries; int count; };
struct Shell {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04(); virtual void s05();
    virtual void s06(); virtual void s07(); virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48();
    virtual void SetEntity(void* entity);  // 0xc4
    virtual Info* GetInfo();               // 0xc8
    int unk04;
    List* list;                            // 0x08
};
struct WriterFlag {
    bool value;
    WriterFlag(bool enabled) : value(enabled) {}
};
// hkOstream on a fixed buffer: ctor 0x943ae0, dtor 0x943a60, operator<< 0x943710
struct FUN_00943ae0 {
    void* vtable;
    unsigned short flags;
    unsigned short referenceCount;
    void* writer;
    FUN_00943ae0(char* buffer, int length, WriterFlag enabled);
    ~FUN_00943ae0();
    FUN_00943ae0& FUN_00943710(const char* text);
};
struct ErrorReporter { virtual void s00(); virtual void s01(); virtual void s02();
    virtual void Report(int severity, unsigned int id, const char* message, const char* file, int line); };
extern ErrorReporter* DAT_010f3364;

__forceinline void* EntityOf(Param* p)
{
    if (p) {
        WorldObj* o = p->GetWorldObject();
        if (o)
            return o->entity;
    }
    return 0;
}
}

// pdb: bhkConstraintChain::ProcessEntities | bhkConstraintChain.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: apWorld, abAdd
bool FUN_00d536a0_shell::UpdateConstraintEntries(ParamD53* pkParam, bool bAdd)
{
    using namespace co_9e0e70_ns;
    Shell* self = reinterpret_cast<Shell*>(this);
    Param* param = reinterpret_cast<Param*>(pkParam);
    bool result = false;
    List* list = self ? self->list : 0;
    for (int i = 0; i < list->count; i++) {
        Entry* entry = list->entries[i];
        if (bAdd) {
            Constraint* c;
            if (!entry || !(c = entry->constraint)) {
                result = true;
                self->SetEntity(EntityOf(param));
                continue;
            }
            Holder* h = c->holder;
            if (!h || !HasWorld(h))
            {
                unsigned int uiInfo = self->GetInfo()->filterInfo;
                unsigned int uiLayer = (unsigned short)entry->filterInfo;
                entry->filterInfo = (uiInfo & 0xffff0000) | uiLayer;
            }
            if (param->count <= 0) {
                c->Prepare(param);
                if (!c->IsInWorld() && !(c->flags & 0x30)) {
                    {
                        char buffer[0x200];
                        FUN_00943ae0 writer(buffer, sizeof(buffer), true);
                        writer.FUN_00943710("A Constraint is being added to the world before its target bodies have been added. Did an bad actor skeleton just switch from keyframed?\n");
                        DAT_010f3364->Report(1, 0x234f24fc, buffer, "c:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkConstraintChain.cpp", 348);
                    }
                    c->Add(param);
                }
            }
        } else {
            if (entry == EntityOf(param))
                self->SetEntity(0);
        }
    }
    return result;
}


struct D53970Stream
{
    unsigned int ReadCount();
    struct D53970Link* ReadLink();
};
struct D53970Link
{
    int unk00;
    int unk04;
    int m_uiFilterValue;
};
struct D53970Alloc
{
    int unk00;
};
struct D53970Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D53970Alloc* m_pStreamAllocator;
    D53970Alloc& Heap()
    {
        return *m_pStreamAllocator;
    }
};
D53970Router& GetMemoryRouter();
struct D53970HeapAlloc
{
    D53970Alloc& Get()
    {
        return GetMemoryRouter().Heap();
    }
};
struct D53970Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void Reserve(D53970Alloc& alloc, int n);
    void SetSizeA(D53970Alloc& alloc, int n)
    {
        Reserve(alloc, n);
        m_iElementCount = n;
    }
    void SetSize(int n)
    {
        SetSizeA(D53970HeapAlloc().Get(), n);
    }
};
struct D53970Scope
{
    int m_saved;
    int* m_pVar;
    D53970Scope()
    {
        m_pVar = &g_ThreadMemoryContext;
        m_saved = *m_pVar;
        *m_pVar = 16;
    }
    ~D53970Scope()
    {
        *m_pVar = m_saved;
    }
};
void __cdecl FUN_00c908c0(D53970Alloc* alloc, D53970Array* arr, int n, int elemSize);
inline void D53970Array::Reserve(D53970Alloc& alloc, int n)
{
    if (GetCapacity() < n)
    {
        int cap2 = 2 * GetCapacity();
        int newSize = (n < cap2) ? cap2 : n;
        FUN_00c908c0(&alloc, this, newSize, 4);
    }
}
struct D53970BaseB
{
    virtual void unk00();
    int unk08;
    int unk0c;
    int unk10;
};
struct D53970Obj
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
    virtual D53970BaseB* GetData(int* out);
    void FUN_00c89860(D53970Stream* stream);
    void ReadDataArray(D53970Stream* stream);
};

// @f3 0x009e11d0 (community match, verified in this file)
struct D53970Callee
{
    void FUN_008fbe70(D53970Stream* s);
};
void __cdecl FUN_00901e90(D53970Array* arr, int n, int elemSize);

// pdb: bhkConstraintChain::IsEqual | bhkConstraintChain.obj | fnv360_0822_debug, objrun, low, conflict (bridge: bhkConstraintChain::LinkObject)
// pdb params: apObject
void D53970Obj::ReadDataArray(D53970Stream* stream)
{
    D53970Stream* s = *(D53970Stream* volatile*)&stream;
    int count = (int)s->ReadCount();
    D53970BaseB* b = GetData((int*)&stream);
    char* data = b ? (char*)b - 4 : 0;
    D53970Array* arr = (D53970Array*)(data + 0x14);
    int cap = arr->GetCapacity();
    if (cap < count)
    {
        int cap2 = 2 * cap;
        int newSize = (count < cap2) ? cap2 : count;
        FUN_00901e90(arr, newSize, 4);
    }
    arr->m_iElementCount = count;
    for (unsigned int i = 0; i < (unsigned int)count; ++i)
    {
        D53970Link* link = s->ReadLink();
        arr->m_data[i] = link->m_uiFilterValue;
    }
    ((D53970Callee*)this)->FUN_008fbe70(s);
}


// Copies 16 consecutive ints from s to d, four at a time, in a loop of four iterations.
// @fnv 0x00d570d0
void __cdecl FUN_00d570d0(int* aiDest, const int* aiSrc)
{
    int n = 4;
    const int* piSrc = aiSrc;
    int* p = aiDest;
    do
    {
        p[0] = piSrc[0];
        p[1] = piSrc[1];
        p[2] = piSrc[2];
        p[3] = piSrc[3];
        p += 4;
        piSrc += 4;
    } while (--n > 0);
}

struct PlaceTag
{
};
inline void* operator new(unsigned int, void* p, PlaceTag)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, PlaceTag)
{}
AllocHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, void*, int);
namespace d51 {
template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& e)
    {
        AllocHolder* a = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(a->m_pAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount], PlaceTag()) T(e);
        m_iElementCount++;
    }
};
struct Writer
{
    int unk;
    int m_iBytes;
    int m_iArrayLength;
    int m_iCount2;
    char pad[0x1c - 0x10];
    hkArray<int> m_kArr;
    void Add()
    {
        m_iArrayLength++;
        m_iCount2++;
        m_iBytes += 0x30;
    }
};
}

// @fnv 0x00d42760
void FUN_00d42760()
{}

// @fnv 0x00d42780
void __cdecl FUN_00d42780()
{}

class hkListNodeD46D
{
  public:
    int unk00;
    hkListNodeD46D* m_next;

    int hkClass_getInheritanceDepth() const;
};

// @fnv 0x00d46d70
// pdb: hkClass::getInheritanceDepth | hkClass.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
int hkListNodeD46D::hkClass_getInheritanceDepth() const
{
    int iCount = 0;
    for (const hkListNodeD46D* pkNode = this; pkNode; pkNode = pkNode->m_next)
        iCount++;
    return iCount;
}

class hkBlockD46E
{
  public:
    int unk00;
    hkBlockD46E* m_next;
    int unk08;
    int m_iVertexCount;

    int hkClass_getNumInterfaces() const;
};

// @fnv 0x00d46de0
// pdb: hkClass::getNumInterfaces | hkClass.obj | fnv360_0822_retail, objrun, high
// pdb: hkClass::getNumInterfaces | hkClass.obj | fnv360_0822_retail, objrun, high (was: SumLinkedValues)
int hkBlockD46E::hkClass_getNumInterfaces() const
{
    const hkBlockD46E* pkBlock = m_next;
    int iTotal = m_iVertexCount;
    while (pkBlock)
    {
        iTotal += pkBlock->m_iVertexCount;
        pkBlock = pkBlock->m_next;
    }
    return iTotal;
}

// @fnv 0x00d46e00
// pdb: hkClass::getInterface | hkClass.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
int __stdcall hkClass_getInterface(int arg0)
{
    return 0;
}

// @fnv 0x00d46e10
int __stdcall FUN_00d46e10(int arg0)
{
    return 0;
}

struct FUN_00d46e20_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    int unk0C;
    int __thiscall hkpMoppShapeMediator_getNumPrimitives();
};

// @fnv 0x00d46e20
// pdb: hkpMoppShapeMediator::getNumPrimitives | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FUN_00d46e20_cls::hkpMoppShapeMediator_getNumPrimitives()
{
    return unk0C;
}

struct hkListNodeD46E
{
    int m_00;
    hkListNodeD46E* m_next;
    int m_08;
    int m_0c;
    int m_10;
    int m_iElementCount;

    int SumListValues() const;
};

// @fnv 0x00d46e30
// pdb: hkClass::getNumEnums | hkClass.obj | fnv360_0822_retail, objrun_sim, low
int hkListNodeD46E::SumListValues() const
{
    const hkListNodeD46E* pkNode = m_next;
    int iTotal = m_iElementCount;
    while (pkNode)
    {
        iTotal += pkNode->m_iElementCount;
        pkNode = pkNode->m_next;
    }
    return iTotal;
}

int __cdecl FUN_00cb0fa0(int, int);

struct hkNamedEntryD46E
{
    int m_name;
};

class hkEntryListD46E
{
  public:
    int SumListValues() const;
    hkNamedEntryD46E* FUN_00d46e50(int i);

    hkNamedEntryD46E* FindByName(int iName);
};

// Scans the entries and returns the first whose m_name matches iName via FUN_00cb0fa0, or null if none match.
// @fnv 0x00d46e90
// pdb: hkClass::getEnumByName | hkClass.obj | tesv_win, caller_sim, low
hkNamedEntryD46E* hkEntryListD46E::FindByName(int iName)
{
    for (int i = 0; i < SumListValues(); i++)
    {
        hkNamedEntryD46E* pkEntry = FUN_00d46e50(i);
        if (FUN_00cb0fa0(pkEntry->m_name, iName) == 0)
            return pkEntry;
    }
    return 0;
}

// @fnv 0x00d46ee0
int* __fastcall GetEntryAt(char* self, int edx, int index)
{
    int* base = (int*)(*(int*)(self + 0x10));
    return &base[index * 5];
}

struct FnvCpu_FUN_00d46ef0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    int value;
    int FUN_00d46ef0();
};
// @fnv 0x00d46ef0
// pdb: VirtualActorPathHandler::GetCurrentNodeIndex | VirtualActorPathHandler.obj | fnv360_0822_retail, vtable, medium
int FnvCpu_FUN_00d46ef0_CpuObject::FUN_00d46ef0()
{
    return value;
}

struct FUN_00c90510_Obj
{
    void FUN_00c90510();
};

struct FUN_00d47730_cls
{
    FUN_00c90510_Obj* unk00;
    FUN_00d47730_cls* __thiscall SetObject();
};

// @f3 0x0044bed0 (community match, verified in this file)
struct View44 { void* m_pad; FUN_00c90510_Obj* m_04; };
struct Obj44 { void FUN_0044bbd0(); };
struct Global44 { void FUN_0086ba60(void* o); };
extern char DAT_01090a78;
// pdb: BGSDestructibleObjectForm::ClearDataComponent | BGSDestructibleObjectForm.obj | fnv360_0822_retail, vtable, medium
FUN_00d47730_cls* FUN_00d47730_cls::SetObject()
{
    View44* v = (View44*)this;
    FUN_00c90510_Obj* o = v->m_04;
    if (o) { ((Obj44*)o)->FUN_0044bbd0(); ((Global44*)&DAT_01090a78)->FUN_0086ba60(o); }
    v->m_04 = 0;
    if (0) return this;
}


class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01268b24;

// @fnv 0x00d47f60
// pdb: getHkVehicleInstanceName | hkpVehicleViewer.obj | fnv360_0822_retail, objrun, medium
GlobalObjectO2_00d472a0* __cdecl FUN_00d47f60()
{
    return &g_01268b24;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268b54;
// @fnv 0x00d47f90
CpuOpaque* __cdecl FUN_00d47f90()
{
    return &DAT_01268b54;
}

struct FUN_00d47fe0_cls
{
    void __thiscall Destroy(int value);
};

// @fnv 0x00d47fd0
void __cdecl FUN_00d47fd0(FUN_00d47fe0_cls* object)
{
    object->Destroy(0);
}

void __cdecl FUN_00c8a230(int* param_1, int param_2);

// @fnv 0x00d50000
// pdb: bhkBlendCollisionObjectAddRotation::IsEqual | bhkBlendCollisionObjectAddRotation.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apObject
void __cdecl FUN_00d50000(int* param_1, int param_2)
{
    FUN_00c8a230(param_1, param_2);
}

class hkMemoryAllocatorD539;

struct hkMemoryRouterD539
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD539* m_pStreamAllocator;

    hkMemoryAllocatorD539& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD539 {
extern "C" hkMemoryRouterD539& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD539& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayD539
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD539& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD539::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

struct hkInfoD539
{
    int unk00[5];
    hkArrayD539<int> m_keys;
};

struct hkContainerD539
{
    int unk00[14];
    int* m_keys;
    int m_numKeys;
};

class FUN_00c89c80_obj
{
  public:
    void CopyFromSource(unsigned int info) throw();
};

class hkShapeD539 : public FUN_00c89c80_obj
{
  public:
    int unk00;
    int unk04;
    hkContainerD539* m_container;

    void CopyContainerKeysToInfo(hkInfoD539& info);
};

// Calls CopyFromSource on info, then if m_container is set resizes info.m_keys to m_numKeys and copies the container's keys into it.
// @f3 0x009e1160 (community match, verified in this file)
void __cdecl FUN_00901e90(void* arr, int newCap, int elemSize);

struct hkContainerW
{
    int unk00[11];
    int* m_keys;
    int m_numKeys;
};

// pdb: bhkConstraintChain::CopyCinfo | bhkConstraintChain.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arInfo
void hkShapeD539::CopyContainerKeysToInfo(hkInfoD539& info)
{
    CopyFromSource((unsigned int)&info);
    if (this && m_container)
    {
        hkContainerW* c = (hkContainerW*)m_container;
        hkArrayD539<int>* arr = &info.m_keys;
        int iCap = arr->getCapacity();
        int n = c->m_numKeys;
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00901e90(arr, iNewCap, sizeof(int));
        }
        arr->m_iElementCount = n;
        for (int i = 0; i < c->m_numKeys; i++)
            arr->m_data[i] = c->m_keys[i];
    }
}


struct FnvCpu_FUN_00d54d60_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float value;
    void FUN_00d54d60(float input);
};
// @fnv 0x00d54d60
// pdb: hkpMoppCompilerInput::setAbsoluteFitToleranceOfTriangles | hkpMoppCompilerInput.obj | tesv_win, objrun_open, low
void FnvCpu_FUN_00d54d60_CpuObject::FUN_00d54d60(float input)
{
    value = input;
}

struct FnvCpu_FUN_00d54d70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float value;
    float FUN_00d54d70();
};
// @fnv 0x00d54d70
// pdb: VirtualActorPathHandler::GetDistanceTraveled | VirtualActorPathHandler.obj | fnv360_0822_retail, vtable, medium
float FnvCpu_FUN_00d54d70_CpuObject::FUN_00d54d70()
{
    return value;
}

struct FUN_00d54da0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;

    void hkpMoppCompilerInput_setRelativeFitToleranceOfInternalNodes(float value);
};

// @fnv 0x00d54da0
// pdb: hkpMoppCompilerInput::setRelativeFitToleranceOfInternalNodes | hkpMoppCompilerInput.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void FUN_00d54da0_Class::hkpMoppCompilerInput_setRelativeFitToleranceOfInternalNodes(float value)
{
    m_10 = value;
}

struct FnvCpu_FUN_00d54db0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float FUN_00d54db0();
};
// @fnv 0x00d54db0
float FnvCpu_FUN_00d54db0_CpuObject::FUN_00d54db0()
{
    return value;
}

struct FUN_00d54dc0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;

    void __thiscall hkpMoppCompilerInput_setAbsoluteFitToleranceOfInternalNodes(float value);
};

// @fnv 0x00d54dc0
// pdb: hkpMoppCompilerInput::setAbsoluteFitToleranceOfInternalNodes | hkpMoppCompilerInput.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __thiscall FUN_00d54dc0_cls::hkpMoppCompilerInput_setAbsoluteFitToleranceOfInternalNodes(float value)
{
    unk14 = value;
}

// @fnv 0x00d54dd0
// pdb: TESActorBaseData::GetKarma | TESActorBaseData.obj | fnv360_0822_retail, vtable, medium
float __fastcall FUN_00d54dd0(char* self, int)
{
    return *(float*)(self + 0x14);
}

typedef unsigned int D57Uint32;

static __forceinline void D57MemCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const D57Uint32* src32 = reinterpret_cast<const D57Uint32*>(src);
    D57Uint32* dst32 = reinterpret_cast<D57Uint32*>(dst);
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        dst32 += 4;
        src32 += 4;
    } while (--numQuads > 0);
}

// Copies six 16-byte blocks from s to d using D57MemCpy16NonEmpty.
// @f3 0x009813f0 (community match, verified in this file)
// pdb: hkString::memCpy16<32> | hkpSimulation.obj | tesv_win, objrun_prop, low
void __cdecl CopySixteenByteBlocks(int* pDest, const int* pSrc)
{
    D57MemCpy16NonEmpty(pDest, pSrc, 2);
}


// @fnv 0x00d584f0
// pdb: hkpConvexVerticesShape::calcSizeForSpu | bhkCharControllerShape.obj | fnv360_0721_beta, objrun_open, low
// pdb params: input, spuBufferSizeLeft
int __stdcall FUN_00d584f0(int iUnused0, int iUnused1)
{
    return 0x60;
}

class hkMemoryAllocatorD5E0
{
  public:
    virtual ~hkMemoryAllocatorD5E0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD5E0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD5E0* m_pStreamAllocator;
    hkMemoryAllocatorD5E0& heap()
    {
        return *m_pStreamAllocator;
    }
};

class hkReferencedObject
{
  public:
    void removeReference() throw();
};

class hkReferencedObjectD5E0
{
  public:
    virtual ~hkReferencedObjectD5E0() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        reinterpret_cast<hkMemoryRouterD5E0*>(FUN_00c85750())
            ->heap()
            .ReleaseBlock(p, static_cast<hkReferencedObjectD5E0*>(p)->m_usMemSizeAndFlags);
    }
};

class hkpShapeContainerD5E0
{
  public:
    virtual ~hkpShapeContainerD5E0() throw()
    {}
};

class hkpSingleShapeContainerD5E0 : public hkpShapeContainerD5E0
{
  public:
    hkReferencedObject* m_pContainedShape;

    ~hkpSingleShapeContainerD5E0() throw()
    {
        if (m_pContainedShape)
            m_pContainedShape->removeReference();
    }
};

struct FUN_00d5e0c0_Obj
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
    unsigned char unk40;

    unsigned char __thiscall FUN_00d5e0c0();
};

// @fnv 0x00d5e0c0
// pdb: hkpConvexListShape::getUseCachedAabb | hkpConvexListShape.obj | fnv360_0822_retail, call_gap_sim, low
unsigned char FUN_00d5e0c0_Obj::FUN_00d5e0c0()
{
    return unk40;
}

struct D46E50Node
{
    int unk00;
    D46E50Node* m_pNext;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    int FUN_00d46e50(int param);
};

struct D46E50Helper
{
    int unk00;
    void* m_pNext;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    __declspec(noinline) int SumListValues();
};

int D46E50Helper::SumListValues()
{
    int sum = unk14;
    for (void* p = m_pNext; p; p = ((D46E50Helper*)p)->m_pNext)
        sum += ((D46E50Helper*)p)->unk14;
    return sum + unk00;
}

// Walks nodes adding unk14 to param minus SumListValues() until it is non-negative, returning that node's unk10 + value * 20; otherwise this->unk10.
// @fnv 0x00d46e50
// pdb: hkClass::getEnum | hkClass.obj | tesv_win, hash, low
int D46E50Node::FUN_00d46e50(int param)
{
    D46E50Node* node = this;
    int d = param - ((D46E50Helper*)this)->SumListValues();
    if (this)
    {
        do
        {
            d += node->unk14;
            if (d >= 0)
            {
                return node->unk10 + d * 20;
            }
            node = node->m_pNext;
        } while (node);
    }
    return this->unk10;
}

struct MemberD472
{
    int m_data;
};

class OwnerD472
{
  public:
    MemberD472* GetMember();

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
    MemberD472 m_kMember;
};

// @fnv 0x00d47290
// pdb: NiGPUProgramCache::GetValidCompileTargetsForPlatform | NiGPUProgramCache.obj | fnv360_0822_retail, objrun_open, low
MemberD472* OwnerD472::GetMember()
{
    return &m_kMember;
}

// FUN_00d48fc0 - loads a Havok packfile/tagfile from a stream and dispatches
// on the format that was detected in it.

struct Hk48fc0_Bool
{
    char m_bVal;
    Hk48fc0_Bool()
    {}
    operator bool() const
    {
        return m_bVal != 0;
    }
};

struct d20base
{
    int f0;
};

d20base* volatile g_d20_self;

extern "C" int d20_sel(void);

// @fnv 0x00d49c20
// pdb: numIndices | hkpStorageExtendedMeshShape.obj | tesv_win, hash, low
static __declspec(noinline) int FUN_00d49c20(d20base* self, int sel)
{
    switch (sel)
    {
    case 1:
        return (int)self + 2;
    case 2:
        return 2 * (int)self + 1;
    default:
        return 4 * (int)self;
    }
}

int d20_probe(void)
{
    return FUN_00d49c20((d20base*)g_d20_self, d20_sel());
}

// FUN_00d4b390: element-size helper of the BGS load-form buffer code.
// Takes the base element size and a small type code, and returns the
// element size for that type code: type 1 -> base + 2, type 2 -> base*2 + 1,
// anything else -> base * 3.
//
// The original keeps its operands in registers (base in ecx, type code in
// eax): it is a helper VC9 gives a private register convention because its
// callers are known at compile time. Defining it as a static noinline
// helper with its caller in this file reproduces that convention.
volatile int g_base_d4b390;
volatile int g_code_d4b390;
volatile int g_sink_d4b390;

// @fnv 0x00d4b390
// pdb: storageMeshShape_numIndices | hkpStorageMeshShape.obj | tesv_win, objrun_prop, low
static __declspec(noinline) int FUN_00d4b390(int base, int code)
{
    switch (code)
    {
    case 1:
        return base + 2;
    case 2:
        return base * 2 + 1;
    default:
        return base * 3;
    }
}

// Stand-in for the in-binary caller: reads both operands at call time and
// stores the result, so the helper call and its register convention stay.
void elem_size_case_d4b390(void)
{
    g_sink_d4b390 = FUN_00d4b390(g_base_d4b390, g_code_d4b390);
}

struct hkpD500Stream;

class hkpD500Object
{
  public:
    void FUN_00c8a280(hkpD500Stream* pkStream);
    void FUN_00d50010(hkpD500Stream* pkStream);
};

// @fnv 0x00d50010
void hkpD500Object::FUN_00d50010(hkpD500Stream* pkStream)
{
    FUN_00c8a280(pkStream);
}

struct hkFinishLoadedObjectFlagD50
{
    int m_bFinishing;
};

class FUN_00d21ce0_cls
{
  public:
    FUN_00d21ce0_cls(hkFinishLoadedObjectFlagD50 flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pOwnerObject);
    }
    void FUN_00d21ce0(void* owner);

    int unk00;
    int unk04;
    void* m_pOwnerObject;
};

extern __declspec(thread) unsigned int t_uiMemContextD53;

class AutoMemContextD53
{
  public:
    AutoMemContextD53(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = t_uiMemContextD53;
        t_uiMemContextD53 = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextD53()
    {
        t_uiMemContextD53 = m_uiPrevious;
    }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorD53
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct hkMemoryRouterD53
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorD53* m_pTemp;
    hkMemoryAllocatorD53* m_pStreamAllocator;
    hkMemoryAllocatorD53& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterD53& __cdecl GetMemoryRouterD53();
struct hkArrayUtilD53
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocatorD53& kAlloc, void* apvArray, int iNumElements,
                                          int iSizeElem);
};

template <typename T> struct hkArrayD53
{
    hkArrayD53() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayD53()
    {
        hkMemoryAllocatorD53& kAlloc = GetMemoryRouterD53().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void reserve(hkMemoryAllocatorD53& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtilD53::GrowArrayCapacity(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(GetMemoryRouterD53().heap(), n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class NiCloningProcessD53;
class hkpShapeContainerD53;
class NiObjectD53
{
  public:
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
    virtual NiObjectD53* MakeClone(NiCloningProcessD53& kCloning);
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
    virtual hkpShapeContainerD53* GetContainer(char* pcOut);
};

template <class K, class V> struct NiTMapItemD53
{
    NiTMapItemD53* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> class NiTMapD53
{
  public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeysEqual(K key1, K key2) const;
    bool GetAt(K key, V& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTMapItemD53<K, V>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    unsigned int m_uiHashSize;
    NiTMapItemD53<K, V>** m_ppkHashTable;
};

class NiCloningProcessD53
{
  public:
    NiTMapD53<NiObjectD53*, NiObjectD53*>* m_pCloneMap;
};

class bhkRefObjectD53 : public NiObjectD53
{
  public:
    unsigned int m_uiRefCount;
    void* m_phkObject;
};

class hkpShapeD53
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    bhkRefObjectD53* m_pkWrapper;
};

class hkpShapeContainerD53
{
  public:
    virtual void v00();
};

class hkpListShapeD53
{
  public:
    unsigned int unk00;
    hkpShapeContainerD53 m_kContainer;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    hkArrayD53<hkpShapeD53*> m_kChildShapes;
};

class bhkListShapeD53 : public NiObjectD53
{
  public:
    void CopyMembersBase(NiObjectD53* pkDest, NiCloningProcessD53& kCloning);
    void FUN_00d53a80(NiObjectD53* pkDest, NiCloningProcessD53& kCloning);
};

inline hkpListShapeD53* ToListShapeD53(hkpShapeContainerD53* pkContainer)
{
    return pkContainer ? reinterpret_cast<hkpListShapeD53*>(reinterpret_cast<char*>(pkContainer) - 4) : 0;
}

// @f3 0x009e1350 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
struct hkThreadMemoryD53
{
    void Deallocate(void* p, int iNumBytes, int iMemClass);
    static hkThreadMemoryD53& Get()
    {
        return *(hkThreadMemoryD53*)TlsGetValue(DAT_010f3170);
    }
};
struct hkArrayGrowD53
{
    static void __cdecl Reserve(void* apvArray, int iNumElements, int iSizeElem);
};
template <class A> __forceinline void SetSizeAndGrowD53(A& kArray, int n)
{
    const int iCap = kArray.m_iCapacityState & 0x3fffffff;
    if (iCap < n)
    {
        int iCap2 = 2 * iCap;
        int iNewSize = (n < iCap2) ? iCap2 : n;
        hkArrayGrowD53::Reserve(&kArray, iNewSize, sizeof(*kArray.m_data));
    }
    kArray.m_iElementCount = n;
}
template <typename T> struct hkLocalArrayD53
{
    hkLocalArrayD53() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkLocalArrayD53()
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            int iCapacity = m_iCapacityState & 0x3fffffff;
            hkThreadMemoryD53& kMemory = hkThreadMemoryD53::Get();
            kMemory.Deallocate(m_data, iCapacity * sizeof(T), 0x17);
        }
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// pdb: bhkConstraintChain::CopyMembers | bhkConstraintChain.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: pDest, arCloneData
void bhkListShapeD53::FUN_00d53a80(NiObjectD53* pkDest, NiCloningProcessD53& kCloning)
{
    char cTmp;
    hkpListShapeD53* pkList = ToListShapeD53(GetContainer(&cTmp));

    hkLocalArrayD53<bhkRefObjectD53*> kChildren;
    SetSizeAndGrowD53(kChildren, pkList->m_kChildShapes.GetLogicalSize());
    for (int i = 0; i < pkList->m_kChildShapes.GetLogicalSize(); i++)
    {
        hkpShapeD53* pkShape = pkList->m_kChildShapes[i];
        kChildren[i] = pkShape ? pkShape->m_pkWrapper : 0;
    }
    pkList->m_kChildShapes.clear();

    SetSizeAndGrowD53(pkList->m_kChildShapes, kChildren.GetLogicalSize());
    for (int j = 0; j < kChildren.GetLogicalSize(); j++)
    {
        NiObjectD53* pkClone;
        if (!kCloning.m_pCloneMap->GetAt(kChildren[j], pkClone))
            pkClone = kChildren[j]->MakeClone(kCloning);
        hkpShapeD53* pkShape = static_cast<hkpShapeD53*>(static_cast<bhkRefObjectD53*>(pkClone)->m_phkObject);
        pkList->m_kChildShapes[j] = pkShape;
    }

    CopyMembersBase(pkDest, kCloning);
}


struct QuadD54D
{
    int unk00, unk04, unk08, unk0C;
};

class HolderD54D
{
  public:
    QuadD54D m_kValue;

    QuadD54D GetValue() const;
};

// @fnv 0x00d54d80
// pdb: hkpMoppCompilerInput::getAbsoluteFitToleranceOfAxisAlignedTriangles | hkpMoppCompilerInput.obj | fnv360_0822_retail, call_gap, low
QuadD54D HolderD54D::GetValue() const
{
    return m_kValue;
}

volatile char* g_d48420_p;

struct FieldWord
{
    unsigned char value;
    FieldWord(unsigned char x) : value(x)
    {}
    FieldWord& operator=(unsigned char x)
    {
        value = x;
        return *this;
    }
    operator unsigned char() const
    {
        return value;
    }
};
extern "C" void _ReadWriteBarrier();

extern int DAT_010cfb34;

class hkMemoryAllocatorD539
{
  public:
    virtual ~hkMemoryAllocatorD539();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
};
class FUN_00d50c90
{
  public:
    virtual ~FUN_00d50c90();
    unsigned short sizeAndFlags, referenceCount;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    void* data28;
    int size2c, flags30;
    void* data34;
    int size38, flags3c;
    void* data40;
    int size44, flags48;
    void* data4c;
    int size50, flags54;
    FUN_00d50c90();
    static void* operator new(unsigned int bytes)
    {
        FUN_00d50c90* p = (FUN_00d50c90*)hkRouterD539::FUN_00c85750().heap().AllocateMemoryBlock(bytes);
        p->sizeAndFlags = (unsigned short)bytes;
        return p;
    }
    static void operator delete(void* p)
    {
        hkRouterD539::FUN_00c85750().heap().ReleaseBlock(p, sizeof(FUN_00d50c90));
    }
};

struct D502D0_TlsBlock
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) D502D0_TlsBlock g_d502d0Tls;
struct D502D0_TlsGuard
{
    unsigned int m_saved;
    D502D0_TlsGuard()
    {
        m_saved = g_d502d0Tls.m_2b4;
        g_d502d0Tls.m_2b4 = 0x10;
    }
    ~D502D0_TlsGuard()
    {
        g_d502d0Tls.m_2b4 = m_saved;
    }
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement);

template <class T> struct hkArray_d51b
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        AllocHolder* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pAllocator, this, sizeof(T));
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};

struct Info_d51b
{
    int unk00;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    int unk10, unk14, unk18;
    hkArray_d51b<int> m_kBridgeAtoms;
    void add(int schema, int results, int temps)
    {
        m_iSchemaByteSize += schema;
        m_iSolverResultCount += results;
        m_iSolverElementTemporaryCount += temps;
    }
};

struct Kit_d51b
{
    int unk00;
    Info_d51b* m_info;
    void AddBridgeAtoms();
};

// Adds a bridge atom to m_info and accumulates schema byte size, solver result count, and temporary element count three times.
// @f3 0x009df390 (community match, verified in this file)
void __cdecl FUN_00901f10(void* array, int sizeOfElement);

void Kit_d51b::AddBridgeAtoms()
{
    hkArray_d51b<int>& atoms = m_info->m_kBridgeAtoms;
    if (atoms.m_iElementCount == (atoms.m_iCapacityState & 0x3fffffff))
        FUN_00901f10(&atoms, 4);
    atoms.m_data[atoms.m_iElementCount] = 7;
    atoms.m_iElementCount++;
    m_info->add(0x30, 1, 1);
    m_info->add(0x30, 1, 1);
    m_info->add(0x30, 1, 1);
}


struct FUN_00dd0530
{
    unsigned int unk00;
    unsigned short size, flags;
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
    FUN_00dd0530(int);
    void hkpConstraintChainInstance_addEntity(int);

    __forceinline void* SetSizeAndGrow(unsigned int n)
    {
        size = (unsigned short)n;
        return this;
    }
    static void* operator new(unsigned int n)
    {
        AllocHolder* h = FUN_00c85750();
        return ((FUN_00dd0530*)((ObjAllocator*)h->m_pAllocator)->Alloc(n))->SetSizeAndGrow(n);
    }
    static void operator delete(void*);
};

extern __declspec(thread) unsigned int t_uiMemContext35D0;
inline unsigned int GetMemContext35D0()
{
    return t_uiMemContext35D0;
}
inline void SetMemContext35D0(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContext35D0 = m_uiGeometryShaderFlags;
}
class AutoMemContext35D0
{
  public:
    AutoMemContext35D0(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContext35D0();
        SetMemContext35D0(m_uiGeometryShaderFlags);
    }
    ~AutoMemContext35D0()
    {
        SetMemContext35D0(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

struct hkpWorld35D0
{
    bool UpdateEntity(void* m_pHavokObject);
};
struct Entity35D0
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    hkpWorld35D0* GetWorld() const
    {
        return m_pkWorld;
    }
    hkpWorld35D0* m_pkWorld;
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4
{
    __m128 m_vComponents;
};

typedef signed char hkInt8;
typedef unsigned char hkUint8;

struct FinishingFlag
{
    int m_bFinishing;
};

template <typename ENUM, typename STORAGE> struct hkEnumF
{
    STORAGE m_kStorage;

    __forceinline hkEnumF(FinishingFlag)
    {}
    __forceinline operator ENUM() const
    {
        return (ENUM)m_kStorage;
    }
    __forceinline void operator=(ENUM e)
    {
        m_kStorage = (STORAGE)e;
    }
};

struct hkMemoryAllocatorF
{
    virtual ~hkMemoryAllocatorF();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemoryRouterF
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocatorF* m_pStreamAllocator;

    __forceinline hkMemoryAllocatorF& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline hkMemoryRouterF* getRouter()
{
    return (hkMemoryRouterF*)FUN_00c85750();
}

template <typename T> struct hkArrayF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArrayF(FinishingFlag)
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorF& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void ClearAndRelease()
    {
        _clearAndDeallocate(getRouter()->heap());
    }

    __forceinline void setDataUserFree(T* p, int size, int capacity)
    {
        m_data = p;
        m_iElementCount = size;
        m_iCapacityState = capacity | 0x80000000;
    }
};

class hkBaseObjectF
{
  public:
    virtual void __vecDelDtor(unsigned int);
};

class hkReferencedObjectF : public hkBaseObjectF
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    __forceinline hkReferencedObjectF(FinishingFlag)
    {}
};

class hkpShapeF : public hkReferencedObjectF
{
  public:
    unsigned int m_ulUserData;
    int m_type;

    __forceinline hkpShapeF(FinishingFlag flag) : hkReferencedObjectF(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 0;
        }
    }
};

class hkpShapeContainerF
{
  public:
    virtual void unkContainer0();
    virtual int GetNumChildShapes() const;
};

class hkpShapeCollectionF : public hkpShapeF, public hkpShapeContainerF
{
  public:
    enum CollectionType
    {
        COLLECTION_LIST,
        COLLECTION_EXTENDED_MESH,
        COLLECTION_TRISAMPLED_HEIGHTFIELD,
        COLLECTION_USER
    };

    bool m_bDisableWelding;
    hkEnumF<CollectionType, hkUint8> m_eCollectionType;

    __forceinline hkpShapeCollectionF(FinishingFlag flag) : hkpShapeF(flag), m_eCollectionType(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_eCollectionType = COLLECTION_USER;
        }
    }
};

enum MaterialIndexStridingType
{
    MATERIAL_INDICES_INVALID,
    MATERIAL_INDICES_INT8,
    MATERIAL_INDICES_INT16
};

struct Subpart
{
    hkEnumF<int, hkInt8> m_type;
    hkEnumF<MaterialIndexStridingType, hkInt8> m_iMaterialIndexType;
    short m_iIndexStriding;
    int m_pVertexBase;
    unsigned short m_iVertexStriding;
    unsigned short m_iNumTriangles;
    int m_pIndexBase;
    unsigned int m_ulUserData;

    __forceinline Subpart(FinishingFlag flag) : m_type(flag), m_iMaterialIndexType(flag)
    {}
};

struct TrianglesSubpart : public Subpart
{
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    hkVector4 m_kVertexTransform;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;

    __forceinline TrianglesSubpart(FinishingFlag flag) : Subpart(flag)
    {}
};

struct InputBuffer
{
    unsigned int data;
    unsigned int size;
    unsigned int flags;
};
struct ArrayData
{
    unsigned int data;
    unsigned int size;
    unsigned int capacityAndFlags;
};
struct LoadResult
{
    ArrayData primary;
    ArrayData secondary;
    LoadResult()
    {
        primary.data = 0;
        primary.size = 0;
        primary.capacityAndFlags = 0x80000000;
        secondary.data = 0;
        secondary.size = 0;
        secondary.capacityAndFlags = 0x80000000;
    }
    ~LoadResult();
};
void FUN_00d5a630(InputBuffer*, LoadResult*, unsigned int);
// Copies src into a temporary InputBuffer, calls FUN_00d5a630 to fill a LoadResult, then swaps result.primary into dst.
// @f3 0x009e8ae0 (community match, verified in this file)
void FUN_00d5a630(InputBuffer*, LoadResult*, unsigned int, int);
// pdb: bhkGeometryUtil::ComputePlanesFromVertices | bhkGeometryUtil.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arVerts, arPlaneEquations, arOutVerts
void LoadIntoArray(const InputBuffer* src, unsigned int flags, ArrayData* dst)
{
    InputBuffer input;
    input.data = src->data;
    input.size = src->size;
    input.flags = 0x10;
    LoadResult result;
    FUN_00d5a630(&input, &result, flags, 1);
    unsigned int old = dst->data;
    dst->data = result.primary.data;
    result.primary.data = old;
    old = dst->size;
    dst->size = result.primary.size;
    result.primary.size = old;
    old = dst->capacityAndFlags;
    dst->capacityAndFlags = result.primary.capacityAndFlags;
    result.primary.capacityAndFlags = old;
}


class hkMemoryAllocatorD47F
{
  public:
    virtual ~hkMemoryAllocatorD47F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD47F
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD47F* m_pStreamAllocator;
    hkMemoryAllocatorD47F& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD47F {
extern "C" hkMemoryRouterD47F& __cdecl FUN_00c85750() throw();
}

class hkStringPtrD47F
{
  public:
    const char* m_pcText;
    void FUN_00cb0c00() throw();
    ~hkStringPtrD47F()
    {
        FUN_00cb0c00();
    }
};

template <class T> class hkRefPtrD47F
{
  public:
    T* m_pRetainedObject;
    ~hkRefPtrD47F()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct hkNamedVariantD47F
{
    hkStringPtrD47F m_name;
    hkStringPtrD47F m_pClassName;
    hkRefPtrD47F<hkReferencedObject> m_pReferencedResource;
};

namespace hkArrayUtilD47F {
template <class T> __forceinline void destruct(T* t, int numElements)
{
    for (int i = 0; i < numElements; i++)
        t[i].~T();
}
}

template <class T> class hkArrayD47F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorD47F& alloc)
    {
        hkArrayUtilD47F::destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }

    ~hkArrayD47F()
    {
        _clearAndDeallocate(hkRouterD47F::FUN_00c85750().heap());
    }

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterD47F::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

    hkArrayD47F* Destroy(unsigned int uiFlags);
};

// Destroys the array contents and optionally deallocates the object itself when uiFlags has bit 0 set, returning this.
// @fnv 0x00d47fe0
template <> hkArrayD47F<hkNamedVariantD47F>* hkArrayD47F<hkNamedVariantD47F>::Destroy(unsigned int uiFlags)
{
    _clearAndDeallocate(hkRouterD47F::FUN_00c85750().heap());
    if (uiFlags & 1)
        operator delete(this, sizeof(*this));
    return this;
}

struct C
{
    C();
    volatile unsigned short f00;
    short unk02;
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
    volatile unsigned short f90;
    volatile bool f92;
    char unk93;
    volatile unsigned short f94;
    volatile unsigned short f96;
    int unk98;
    int unk9c;
    volatile unsigned short fa0;
    bool fa2;
    char unka3;
    int unka4;
    volatile unsigned short fa8;
    short unkaa;
    volatile unsigned short fac;
    short unkae;
    volatile unsigned short fb0;
    short unkb2;
    volatile unsigned short fb4;
};
// Constructor for C that initializes f00, f90, f92, f94, f96, fa0, fa2, fa8, fac, fb0, and fb4 to fixed values.
// @fnv 0x00d4ff60
// pdb: hkpPrismaticConstraintData::Atoms::Atoms | hkpPrismaticConstraintData.obj | tesv_win, objrun_sim, low
C::C() : f00(2), f90(0xb), f92(1), f94(0), f96(0), fa0(0xa), fa2(1), fa8(0xd), fac(7), fb0(7), fb4(9)
{}

// sub ecx,0x10; jmp FUN_00d57120
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x10 = vptr + three int fields).
struct PrimaryBase
{
    virtual void FUN_00d57110();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d57110();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d57110
    virtual void FUN_00d57110();
};

Derived::Derived()
{}

struct VectorS
{
    __m128 m_vComponents;
    VectorS(const VectorS& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct S
{
    char pad[2];
    char val;
};

volatile S* g_dst;
volatile S* g_src;
volatile int g_b;
volatile int g_c;

class hkStringPtr
{
  public:
    const char* m_pcText;

    void operator=(const char* pcString) throw();
};

class FUN_00cb0a60 : public hkStringPtr
{
  public:
    FUN_00cb0a60() throw();
    using hkStringPtr::operator=;
};

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() throw();
};

class RefPtrD482
{
  public:
    hkReferencedObject* m_pRetainedObject;

    RefPtrD482() throw()
    {}
    RefPtrD482(hkReferencedObject* pkObject) throw() : m_pRetainedObject(pkObject)
    {}
    ~RefPtrD482() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
    }
    void operator=(const RefPtrD482& rp) throw()
    {
        if (this != &rp)
        {
            hkReferencedObject* pkNew = rp.m_pRetainedObject;
            if (pkNew)
                ((FUN_00c90510_Obj*)pkNew)->FUN_00c90510();
            if (m_pRetainedObject)
                m_pRetainedObject->removeReference();
            m_pRetainedObject = pkNew;
        }
    }
    FUN_00d46d40_s* FUN_00d477a0() const throw();
    void AssignObject(int iParam) throw();
};

namespace SpringSimd {
union __declspec(intrin_type) __m128
{
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } lanes;
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, __m128);
}
struct S_00d4f0f0_B1
{
    virtual void v0();
    short unk04;
    short unk06;
    __forceinline S_00d4f0f0_B1()
    {
        unk06 = 1;
    }
};
struct S_00d4f0f0_B2 : S_00d4f0f0_B1
{
    int unk08;
    int unk0c;
    __forceinline S_00d4f0f0_B2()
    {
        unk08 = 0;
    }
};
struct S_00d4f0f0_H
{
    short unk10;
    __forceinline S_00d4f0f0_H() : unk10(3)
    {}
};
struct S_00d4f0f0_S
{
    short unk40;
    __forceinline S_00d4f0f0_S() : unk40(6)
    {}
};

namespace D4F2A0Simd {
union __declspec(intrin_type) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C" __m128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float*, __m128);
}

struct __declspec(align(16)) D4F2A0Vector
{
    float x, y, z, w;
};

struct hkBaseObjectS
{
    virtual void unk00();
};

struct hkReferencedObjectS : hkBaseObjectS
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObjectS() : m_sReferenceCount(1)
    {}
};

struct hkpConstraintDataS : hkReferencedObjectS
{
    unsigned int m_ulUserData;
    hkpConstraintDataS() : m_ulUserData(0)
    {}
};

inline void setZero4(D4F2A0Vector& v)
{
    D4F2A0Simd::_mm_store_ps(&v.x, D4F2A0Simd::_mm_setzero_ps());
}

struct hkRotationS
{
    D4F2A0Vector m_kColumn0;
    D4F2A0Vector m_kColumn1;
    D4F2A0Vector m_kColumn2;
    void setIdentity()
    {
        setZero4(m_kColumn0);
        setZero4(m_kColumn1);
        setZero4(m_kColumn2);
        m_kColumn0.x = 1.0f;
        m_kColumn1.y = 1.0f;
        m_kColumn2.z = 1.0f;
    }
};

struct hkpSetLocalRotationsAtomS
{
    unsigned short m_type;
    hkRotationS m_kRotationA;
    hkRotationS m_kRotationB;
    hkpSetLocalRotationsAtomS()
    {
        m_type = 4;
    }
};

struct hkpTwistLimitAtomS
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucTwistAxis;
    unsigned char m_ucReferenceAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
    hkpTwistLimitAtomS()
    {
        m_type = 0xf;
        m_bLimitEnabled = 1;
    }
};

struct hkpConeLimitAtomS
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucMemOffsetToAngleOffset;
    unsigned char m_ucMemOffsetToOldAngleOffset;
    unsigned char m_ucMemOffsetToFirstConstrainedDof;
    unsigned char m_ucAngleMeasurementMode;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
    hkpConeLimitAtomS()
    {
        m_type = 0x10;
        m_bLimitEnabled = 1;
        m_ucAngleMeasurementMode = 0;
    }
};

struct hkpRagdollAtomsS
{
    hkpSetLocalRotationsAtomS m_kLocalRotations;
    hkpTwistLimitAtomS m_kTwistLimit;
    hkpConeLimitAtomS m_kConeLimit;
    hkpConeLimitAtomS m_kPlaneLimit;
    hkpRagdollAtomsS()
    {}
};

struct hkpRagdollDataS : hkpConstraintDataS
{
    void setConeStab(hkBool b);
};

struct FUN_00d4f2a0 : hkpRagdollDataS
{
    hkpRagdollAtomsS m_kBridgeAtoms;
    FUN_00d4f2a0();
    virtual ~FUN_00d4f2a0();
};

__declspec(noinline) void hkpRagdollDataS::setConeStab(hkBool b)
{
    static_cast<FUN_00d4f2a0*>(this)->m_kBridgeAtoms.m_kConeLimit.m_ucAngleMeasurementMode = b.m_cBooleanValue ? 16 : 0;
}

// Initializes bridge ragdoll atoms with identity rotations, twist limits of ±0.5236 rad, cone limits, and plane limits with tau factor 0.8.
// @f3 0x009dc8c0 (community match, verified in this file)
extern float FUN_00e7c0cc;
extern float FUN_00e7c0c8;
extern float FUN_00dc3b0c;
extern float FUN_00e7c0c4;
extern float FUN_00dcf7d8;
// pdb: hkpRagdollLimitsData::hkpRagdollLimitsData | hkpRagdollLimitsData.obj | tesv_win, callee_sim, low
FUN_00d4f2a0::FUN_00d4f2a0()
{
    float* pa = &m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.m_kColumn0.x;
    float* pb = &m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.m_kColumn0.x;
        pa[0]=0.0f;
    pa[1]=0.0f;
    pa[2]=0.0f;
    pa[3]=0.0f;
    pa[4]=0.0f;
    pa[5]=0.0f;
    pa[6]=0.0f;
    pa[7]=0.0f;
    pa[8]=0.0f;
    pa[9]=0.0f;
    pa[10]=0.0f;
    pa[11]=0.0f;
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.m_kColumn0.x=1.0f;
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.m_kColumn1.y=1.0f;
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.m_kColumn2.z=1.0f;
    pb[0]=0.0f;
    pb[1]=0.0f;
    pb[2]=0.0f;
    pb[3]=0.0f;
    pb[4]=0.0f;
    pb[5]=0.0f;
    pb[6]=0.0f;
    pb[7]=0.0f;
    pb[8]=0.0f;
    pb[9]=0.0f;
    pb[10]=0.0f;
    pb[11]=0.0f;
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.m_kColumn0.x=1.0f;
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.m_kColumn1.y=1.0f;
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.m_kColumn2.z=1.0f;
    *static_cast<volatile unsigned char*>(&m_kBridgeAtoms.m_kTwistLimit.m_ucTwistAxis)=0;
    m_kBridgeAtoms.m_kTwistLimit.m_fMinAngle=FUN_00e7c0cc;
    m_kBridgeAtoms.m_kTwistLimit.m_ucReferenceAxis=1;
    m_kBridgeAtoms.m_kConeLimit.m_ucMemOffsetToAngleOffset=0;
    m_kBridgeAtoms.m_kTwistLimit.m_fMaxAngle=FUN_00e7c0c8;
    m_kBridgeAtoms.m_kConeLimit.m_ucMemOffsetToOldAngleOffset=0;
    m_kBridgeAtoms.m_kConeLimit.m_ucMemOffsetToFirstConstrainedDof=0;
    m_kBridgeAtoms.m_kTwistLimit.m_fAngularLimitsTauFactor=0.8f;
    m_kBridgeAtoms.m_kConeLimit.m_fMinAngle=FUN_00dc3b0c;
    m_kBridgeAtoms.m_kConeLimit.m_fMaxAngle=1.0f;
    m_kBridgeAtoms.m_kConeLimit.m_fAngularLimitsTauFactor=0.8f;

    setConeStab(true);
    m_kBridgeAtoms.m_kPlaneLimit.m_fMinAngle=FUN_00e7c0c4;
    m_kBridgeAtoms.m_kPlaneLimit.m_ucMemOffsetToOldAngleOffset=1;
    m_kBridgeAtoms.m_kPlaneLimit.m_fMaxAngle=FUN_00dcf7d8;
    m_kBridgeAtoms.m_kPlaneLimit.m_ucMemOffsetToFirstConstrainedDof=1;
    m_kBridgeAtoms.m_kPlaneLimit.m_ucMemOffsetToAngleOffset=0;
    m_kBridgeAtoms.m_kPlaneLimit.m_fAngularLimitsTauFactor=0.8f;
}


namespace HingeLimitsD52FC0Detail {
struct Matrix
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    __forceinline void setZero()
    {
        ::D4F2A0Simd::_mm_store_ps(&m00, ::D4F2A0Simd::_mm_setzero_ps());
        ::D4F2A0Simd::_mm_store_ps(&m10, ::D4F2A0Simd::_mm_setzero_ps());
        ::D4F2A0Simd::_mm_store_ps(&m20, ::D4F2A0Simd::_mm_setzero_ps());
    }
    __forceinline void setDiagonal(float x, float y, float z)
    {
        setZero();
        m00 = x;
        m11 = y;
        m22 = z;
    }
    __forceinline void setIdentity()
    {
        setDiagonal(1.0f, 1.0f, 1.0f);
    }
};
}

static const float DAT_010181bc = 0.05f;
static const float DAT_01011d78 = 0.0f;
static const float DAT_01017870 = 0.3f;
static const float DAT_010231a8 = 0.4f;
static const float DAT_0101e2bc = 0.1f;

// @f3twin 0x009b0620 of 0x006b8970
struct F3Twin_009b0620 : public FnvCpu_FUN_00d46ef0_CpuObject { int F3_FUN_009b0620() ; };
// pdb: hkClass::getNumDeclaredEnums | hkClass.obj | fnv360_0822_retail, objrun_sim, medium
int F3Twin_009b0620::F3_FUN_009b0620() 
{
    return value;
}

// @f3twin 0x009e27e0 of 0x0046c1f0
struct F3Twin_009e27e0 : public FnvCpu_FUN_00d54d70_CpuObject { float hkpMoppCompilerInput_getAbsoluteFitToleranceOfTriangles() ; };
// pdb: hkpMoppCompilerInput::getAbsoluteFitToleranceOfTriangles | hkpMoppCompilerInput.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_seq), high
float F3Twin_009e27e0::hkpMoppCompilerInput_getAbsoluteFitToleranceOfTriangles() 
{
    return value;
}

// @f3twin 0x009e5240 of 0x0044f5c0
// pdb: hkpCylinderShape::getCylinderRadius | hkpCylinderShape.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim) + skyrim(call_gap), high
float __fastcall hkpCylinderShape_getCylinderRadius(char* self, int)
{
    return *(float*)(self + 0x14);
}

// @f3twin 0x00a498c0 of 0x006b8970
struct F3Twin_00a498c0 : public FnvCpu_FUN_00d46ef0_CpuObject { int F3_FUN_00a498c0() ; };
int F3Twin_00a498c0::F3_FUN_00a498c0() 
{
    return value;
}

// @f3twin 0x00a811f0 of 0x006b8970
struct F3Twin_00a811f0 : public FnvCpu_FUN_00d46ef0_CpuObject { int F3_FUN_00a811f0() ; };
int F3Twin_00a811f0::F3_FUN_00a811f0() 
{
    return value;
}

// @f3 0x009e1a70 (community match, verified in this file)
namespace f3m_009e1a70 {
struct Vec9E1A70
{
    float x, y, z, w;
    void __thiscall FUN_008d2970(const void* kTransform, const void* kVector);
};

struct C9E1A70
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    Vec9E1A70 m_20;
    Vec9E1A70 m_30;

    void __thiscall FUN_009e1a70(const void* kTransformA, const void* kTransformB, const void* kVector);
};

// pdb: hkpBallAndSocketConstraintData::setInWorldSpace | hkpBallAndSocketConstraintData.obj | tesv_win, hash, low
void __thiscall C9E1A70::FUN_009e1a70(const void* kTransformA, const void* kTransformB, const void* kVector)
{
    m_20.FUN_008d2970(kTransformA, kVector);
    m_30.FUN_008d2970(kTransformB, kVector);
}
}   // namespace f3m_009e1a70

// @f3 0x009e1a40 (community match, verified in this file)
namespace f3m_009e1a40 {
extern unsigned long DAT_010f3170;
typedef void* (__stdcall* TlsGetter)(unsigned long);
extern "C" TlsGetter DAT_00fdf044;
struct ThreadMemory {
    void FUN_008f6d90(void* block, unsigned int bytes, int memoryClass);
};
struct Object {
    void* vtable;
    unsigned short allocatedSizeAndFlags;
    short referenceCount;
    void FUN_009e16b0();
    Object* FUN_009e1a40(unsigned int deletionFlags);
};
// pdb: hkpBallSocketChainData::`scalar deleting destructor' | hkpBallSocketChainData.obj | fnv360_0822_retail, vtable_prefix, high
Object* Object::FUN_009e1a40(unsigned int deletionFlags) {
    FUN_009e16b0();
    if (deletionFlags & 1) {
        ThreadMemory* memory = static_cast<ThreadMemory*>(DAT_00fdf044(DAT_010f3170));
        memory->FUN_008f6d90(this, allocatedSizeAndFlags, 44);
    }
    return this;
}
}
