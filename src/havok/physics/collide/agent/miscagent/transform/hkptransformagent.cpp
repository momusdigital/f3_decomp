#include "f3_common.h"
// src/havok/physics/collide/agent/miscagent/transform/hkptransformagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/transform/hkptransformagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CollisionAgentFunctionTable {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    char f10;
    char f11;
};
void __cdecl hkpTransformAgent_createTransformBAgent();
void __cdecl RunCollector();
void __cdecl RunSymmetricAgentFlipCollector();
void __cdecl hkpTransformAgent_createTransformAAgent();
void __cdecl ProcessTransformShapeCollision();
void __cdecl hkpTransformAgent_staticGetClosestPoints();
void __cdecl hkpTransformAgent_staticLinearCast();

struct Target {
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
    virtual int v10(float a, float b, int c);
};

struct Obj {
    int pad[3];
    Target* m_target;
    int ForwardToTarget(float a, float b, int c);
};

// Calls v10 on m_target with the given float and int arguments and returns its result.
// @fnv 0x00d42a10
// pdb: hkpTransformAgent::warpTime | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: oldTime, newTime, input
int Obj::ForwardToTarget(float a, float b, int c)
{
    return m_target->v10(a, b, c);
}

typedef int (__thiscall *FUN_00d42a60_method)(void*);
struct FUN_00d42a60_vtable {
    FUN_00d42a60_method slot00;
    FUN_00d42a60_method slot04;
    FUN_00d42a60_method slot08;
    FUN_00d42a60_method slot0c;
    FUN_00d42a60_method slot10;
    FUN_00d42a60_method slot14;
    FUN_00d42a60_method slot18;
    FUN_00d42a60_method slot1c;
    FUN_00d42a60_method slot20;
    FUN_00d42a60_method slot24;
    FUN_00d42a60_method slot28;
    FUN_00d42a60_method slot2c;
    FUN_00d42a60_method slot30;
    FUN_00d42a60_method slot34;
};
struct FUN_00d42a60_interface {
    FUN_00d42a60_vtable* vtable;
};
struct FUN_00d42a60_class {
    void* unk00;
    void* unk04;
    void* unk08;
    FUN_00d42a60_interface* unk0c;
    int __thiscall hkpTransformAgent_createZombie();
};
// @fnv 0x00d42a60
// pdb: hkpTransformAgent::createZombie | hkpTransformAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FUN_00d42a60_class::hkpTransformAgent_createZombie() {
    FUN_00d42a60_method method = unk0c->vtable->slot34;
    return method(unk0c);
}

struct hkVector4 { float x, y, z, w; };
struct __declspec(align(16)) hkTransform {
    hkVector4 col0;
    hkVector4 col1;
    hkVector4 col2;
    hkVector4 trans;
    hkTransform(const void* rot, const hkVector4& t);
};
struct Body {
    char pad[0x14];
    int unk14;
    char pad2[0x18];
    hkVector4 unk30;
};
struct Source {
    Body* body;
    int unk04;
    const void* rot;
};
struct Input {
    int unk00;
    int unk04;
    hkTransform* xf;
    Source* src;
};
struct Collector {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int Process(Input* in, int a, int b, int c, int d);
};
struct Caster {
    int unk00;
    int unk04;
    int unk08;
    Collector* coll;
    int hkpTransformAgent_linearCast(Source* s, int a, int b, int c, int d);
};
// @fnv 0x00d42cf0
// pdb: hkpTransformAgent::linearCast | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyAin, bodyB, input, collector, startCollector
// pdb: hkpTransformAgent::linearCast | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high (was: ProcessSource)
int Caster::hkpTransformAgent_linearCast(Source* pSource, int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    Body* body = pSource->body;
    hkTransform xf(pSource->rot, body->unk30);
    Input in;
    in.xf = &xf;
    in.src = pSource;
    in.unk00 = body->unk14;
    in.unk04 = 0;
    return coll->Process(&in, aiArg1, aiArg2, aiArg3, aiArg4);
}

struct S_00d42d60_Transform
{
    float m[16];
    void FUN_00cb2240(const S_00d42d60_Transform& a, const S_00d42d60_Transform& b);
};

struct S_00d42d60_Shape
{
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d42d60_TransformShape : S_00d42d60_Shape
{
    int unk10;
    S_00d42d60_Shape* m_pContainedShape;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00d42d60_Transform m_kMotionTransform;
};

struct S_00d42d60_CdBody
{
    const S_00d42d60_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d42d60_CdBody* m_parent;
};

struct S_00d42d60_Input;
struct S_00d42d60_Collector;

typedef void (__cdecl *S_00d42d60_Func)(const S_00d42d60_CdBody&, const S_00d42d60_CdBody&,
                                         const S_00d42d60_Input&, S_00d42d60_Collector*, S_00d42d60_Collector*);

struct S_00d42d60_Funcs
{
    S_00d42d60_Func m_getClosestPoints;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct S_00d42d60_Dispatcher
{
    char unk000[0x1a0];
    unsigned char m_agent2TypeMap[32][32];
    char unk5a0[0x9ac - 0x5a0];
    S_00d42d60_Funcs m_agent2Funcs[64];
};

struct S_00d42d60_Input
{
    S_00d42d60_Dispatcher* m_pCollisionDispatcher;
};


// @fnv 0x00d42d60
// pdb: hkpTransformAgent::staticLinearCast | hkpTransformAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyAin, bodyB, input, collector, startCollector
// pdb: hkpTransformAgent::staticLinearCast | hkpTransformAgent.obj | fnv360_0822_retail, objrun, high (was: DispatchClosestPoints)
void __cdecl hkpTransformAgent_staticLinearCast(const S_00d42d60_CdBody& bodyA, const S_00d42d60_CdBody& bodyB,
                          const S_00d42d60_Input& input, S_00d42d60_Collector* pCollectorA, S_00d42d60_Collector* pCollectorB)
{
    const S_00d42d60_TransformShape* pTransformShape = (const S_00d42d60_TransformShape*)bodyA.m_pCollisionShape;
    __declspec(align(16)) S_00d42d60_Transform t;
    t.FUN_00cb2240(*(const S_00d42d60_Transform*)bodyA.m_pMotionState, pTransformShape->m_kMotionTransform);

    S_00d42d60_CdBody childBody;
    childBody.m_parent = &bodyA;
    childBody.m_pMotionState = &t;
    childBody.m_pCollisionShape = pTransformShape->m_pContainedShape;
    childBody.m_uiCollisionShapeKey = 0;

    S_00d42d60_Dispatcher* d = input.m_pCollisionDispatcher;
    unsigned char agent = d->m_agent2TypeMap[childBody.m_pCollisionShape->m_type][bodyB.m_pCollisionShape->m_type];
    d->m_agent2Funcs[agent].m_getClosestPoints(childBody, bodyB, input, pCollectorA, pCollectorB);
}

namespace fnv_00d42ed0 {
struct FourFloatVector { float x,y,z,w; };
__declspec(align(16)) struct Matrix43 { FourFloatVector row0,row1,row2,row3; };
struct MatrixOps { void FUN_00cb2240(const Matrix43*, const Matrix43*); };
struct Object { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; Matrix43 transform; };
struct Input { Object* object; int unk04; Matrix43* transform; };
struct DispatchData { int unk00; int unk04; Matrix43* unk08; Input* unk0c; };
struct Handler { virtual int V0(); virtual int V1(); virtual int V2(); virtual int Dispatch(DispatchData*,int,int,int); };
struct Owner { int a,b,c; Handler* handler; void FUN_00d42ed0(Input*,int,int,int); };
// @fnv 0x00d42ed0
void Owner::FUN_00d42ed0(Input* input,int aiArg1,int aiArg2,int aiArg3)
{
    Object* object=input->object;
    Matrix43 temp;
    ((MatrixOps*)&temp)->FUN_00cb2240(input->transform,&object->transform);
    DispatchData data;
    data.unk08=&temp;
    data.unk0c=input;
    data.unk00=object->unk14;
    data.unk04=0;
    handler->Dispatch(&data,aiArg1,aiArg2,aiArg3);
}
}  // namespace fnv_00d42ed0

namespace fnv_00d42fc0 {
struct FourFloatVector { float x, y, z, w; };
__declspec(align(16)) struct Matrix43 { FourFloatVector row0, row1, row2, row3; };
struct FUN_00cb2240_shell { void __thiscall FUN_00cb2240(const Matrix43*, const Matrix43*); };
struct Object { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; Matrix43 transform; };
struct Input { Object* object; int unk04; Matrix43* transform; };
struct DispatchData { int unk00; int unk04; Matrix43* unk08; Input* unk0c; };
struct Handler {
    virtual int V0(); virtual int V1(); virtual int V2(); virtual int V3();
    virtual int V4(); virtual int V5(); virtual int V6(); virtual int V7();
    virtual int Dispatch(DispatchData*, int, int, int);
};
struct Owner { int unk00; int unk04; int unk08; Handler* handler; int hkpTransformAgent_updateShapeCollectionFilter(Input*, int, int, int); };
// @fnv 0x00d42fc0
// pdb: hkpTransformAgent::updateShapeCollectionFilter | hkpTransformAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int Owner::hkpTransformAgent_updateShapeCollectionFilter(Input* input, int aiArg1, int aiArg2, int aiArg3)
{
    Object* object = input->object;
    Matrix43 temp;
    ((FUN_00cb2240_shell*)&temp)->FUN_00cb2240(input->transform, &object->transform);
    DispatchData data;
    data.unk08 = &temp;
    data.unk0c = input;
    data.unk00 = object->unk14;
    data.unk04 = 0;
    return handler->Dispatch(&data, aiArg1, aiArg2, aiArg3);
}
}  // namespace fnv_00d42fc0

struct D432F0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D432F0CollectorBase() : m_bFound(false) {}
};

struct D432F0Collector : D432F0CollectorBase {
    int m_iData;

    D432F0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl ProcessTransformShapeCollision(int a, int b, int c, D432F0CollectorBase* collector);

// Constructs a D432F0Collector from d and calls ProcessTransformShapeCollision with b, a, c and the collector.
// @fnv 0x00d432f0
// pdb: hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::staticGetPenetrations | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl RunCollector(int aiArgA, int aiArgB, int aiArgC, int aiData)
{
    D432F0Collector collector(aiData);
    ProcessTransformShapeCollision(aiArgB, aiArgA, aiArgC, &collector);
}

extern float DAT_0104da48;
extern void __cdecl hkpTransformAgent_staticGetClosestPoints(void*, void*, int, void*);

struct hkpSymmetricAgentFlipCollector
{
    virtual void unk00();
    float unk04;
    int unk08;
};

// Builds a local hkpSymmetricAgentFlipCollector from DAT_0104da48 and arg4, then calls hkpTransformAgent_staticGetClosestPoints with arg2, arg1, arg3 and the collector.
// @fnv 0x00d43330
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticGetClosestPoints | hkpTransformAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl RunSymmetricAgentFlipCollector(void* arg1, void* arg2, int arg3, int arg4)
{
    hkpSymmetricAgentFlipCollector local;
    local.unk04 = DAT_0104da48;
    local.unk08 = arg4;
    hkpTransformAgent_staticGetClosestPoints(arg2, arg1, arg3, &local);
}

struct CallData { void* descriptor; float bound; unsigned int value; };
extern unsigned char DAT_010ce7fc;
extern float DAT_0104da48;
struct Wrapper {
    void FUN_00d42de0(void*, void*, unsigned int, CallData*);
    void FUN_00d434a0(void*, void*, unsigned int, unsigned int);
};
// Builds a CallData from fourth and DAT_0104da48 with descriptor DAT_010ce7fc, then calls FUN_00d42de0 with second, first and third.
// @fnv 0x00d434a0
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::getClosestPoints | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void Wrapper::FUN_00d434a0(void* first, void* second, unsigned int third, unsigned int fourth) {
    CallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d42de0(second, first, third, &data);
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned int m128_u32[4];
} __m128;

extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);

extern char DAT_010ce80c[];
extern const __m128 DAT_010c44d0;

struct __declspec(align(16)) Vec4_d43620 {
    float x, y, z, w;
};

struct Collector_d43620 {
    void* m_vtbl;
    float m_fHitFraction;
    int m_auiShapeKeys[2];
    Vec4_d43620 m_dir;
    int m_uiFilterValue;

    Collector_d43620* Init(const __m128& dir, int value)
    {
        m_vtbl = DAT_010ce80c;
        m_fHitFraction = 3.40282e+38f;
        m_dir = *(const Vec4_d43620*)&dir;
        m_uiFilterValue = value;
        return this;
    }
};

// FUN_00d429c0: thiscall, one stack argument (callee pops 4).
// Forwards the argument to a virtual slot of the member at +0x0c, then
// calls this object's virtual slot 0 (scalar deleting dtor) with flags = 1.

class ForwardTarget {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(unsigned int arg);
};

class ForwardOwner {
public:
    virtual void vDtor(unsigned int flags);
    void FUN_00d429c0(unsigned int arg);
    unsigned int unk04;
    unsigned int unk08;
    ForwardTarget* m_0c;
};

// Forwards arg to the target's v1c and then calls the virtual destructor with flags 1.
// @fnv 0x00d429c0
void ForwardOwner::FUN_00d429c0(unsigned int arg)
{
    m_0c->v1c(arg);
    vDtor(1);
}

struct S_00d42a40_T {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C(int a);
};

struct S_00d42a40_H {
    int unk00;
    int unk04;
    int unk08;
    S_00d42a40_T* m_0C;
    void hkpTransformAgent_removePoint(int a);
};

// @fnv 0x00d42a40
// pdb: hkpTransformAgent::removePoint | hkpTransformAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S_00d42a40_H::hkpTransformAgent_removePoint(int a) {
    m_0C->v2C(a);
}

struct FnvCpu_FUN_00d42a50_CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d42a50_CpuOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d42a50_CpuInterface* target;
    void FUN_00d42a50(int arg0);
};
// @fnv 0x00d42a50
void FnvCpu_FUN_00d42a50_CpuOwner::FUN_00d42a50(int arg0)
{
    target->Invoke(arg0);
}

struct Header {
    const char* tag;
    unsigned short byteCount;
    unsigned short format;
    int userValue;
    int result;
};
struct Allocator {
    virtual void* unknown();
    virtual Header* allocate(int size);
};
struct Resource { int unk00;int unk04;int unk08;int unk0c; Allocator* allocator; };
Resource* __cdecl FUN_00c85750();

struct Meta {int unk00; int unk04; int unk08; int sequence;};
struct Root {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    Meta* volatile meta;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    int portion30;
};
struct DataHandle{int handle;DataHandle(int n):handle(n) {}};
struct InputA { Root* root; int unk04; int data; };
struct Path {int unk00; int unk04; int unk08; int subIndex;};
struct InputB {Path* path;};
struct InputC {unsigned char* state; int unk04;int unk08;int unk0c;int unk10;int tableFlag;};
__declspec(align(16)) struct WorkArea {
    void* entries[44];
    void CopyFrom(struct DataHandle data);
    void FUN_00cb2240(struct DataHandle data, int* portion);
};
struct CallbackArgs {
    Meta* meta;
    int zero;
    WorkArea* workspace;
    InputA* source;
};
typedef int (__cdecl *Handler)(CallbackArgs*,InputB*,InputC*,int);
struct HandlerEntry {
    Handler handler;
    int unk04; int unk08; int unk0c; int unk10;
};
// Allocates a 16-byte Header, fills tag/format/userValue, runs workspace setup, selects a handler by kind from a table and stores its return in header->result.
// @f3 0x009cd4e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall *DAT_00d9b080)(unsigned long);

struct BlockAllocator {
    void* FUN_008f6d30(int size, int flags);
};

__declspec(align(16)) struct MotionState {
    void* entries[44];
    MotionState* FUN_009cdcb0(const void* src);
    void hkTransform_setMul(const void* rot, const hkVector4& t);
};

// pdb: hkpTransformAgent::createTransformAAgent | hkpTransformAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, mgr
// pdb: hkpTransformAgent::createTransformAAgent | hkpTransformAgent.obj | fnv360_0822_retail, caller_sim, high (was: BuildHeaderAndDispatchHandler)
Header* __cdecl hkpTransformAgent_createTransformAAgent(InputA* pSource,InputB* pPathInput,InputC* pStateInput,int value) {
    void* tls = DAT_00d9b080(DAT_010f3170);
    Header* header = (Header*)((BlockAllocator*)tls)->FUN_008f6d30(0x10, 0x1f);
    header->userValue = value;
    header->byteCount = 16;
    header->format = 1;
    header->tag = (const char*)0xe7f3f8;
    Root* root = pSource->root;
    Meta* meta = *(Meta**)&root->meta;
    MotionState ms;
    ms.FUN_009cdcb0((const void*)pSource->data);
    ms.hkTransform_setMul((const void*)pSource->data, *(const hkVector4*)&root->portion30);
    CallbackArgs callbackArgs = {meta,0,(WorkArea*)&ms,pSource};
    Path* path = pPathInput->path;
    bool flag = pStateInput->unk10 != 0;
    unsigned char* state = pStateInput->state;
    int subIndex = path->subIndex;
    int iSequence = meta->sequence;
    unsigned char* pKindTable = flag ? state+0x5a0 : state+0x1a0;
    unsigned char kind = pKindTable[(iSequence<<5)+subIndex];
    Handler handler = ((HandlerEntry*)(state+0x9a0))[kind].handler;
    header->result = handler(&callbackArgs,pPathInput,pStateInput,value);
    return header;
}


struct __declspec(align(16)) Vector4_00d42f40
{
    float x, y, z, w;
};

struct __declspec(align(16)) Transform_00d42f40
{
    Vector4_00d42f40 basisX;
    Vector4_00d42f40 basisY;
    Vector4_00d42f40 basisZ;
    Vector4_00d42f40 translation;
    void __thiscall FUN_00cb2240(const Transform_00d42f40*, const Transform_00d42f40*);
};

struct Shape_00d42f40
{
    void* vtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int type;
};

struct TransformShape_00d42f40 : Shape_00d42f40
{
    unsigned int unk10;
    Shape_00d42f40* child;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    Transform_00d42f40 transform;
};

struct CollisionBody_00d42f40
{
    Shape_00d42f40* shape;
    unsigned int shapeKey;
    const Transform_00d42f40* transform;
    const CollisionBody_00d42f40* parent;
};

struct CollisionInput_00d42f40;
typedef void (__cdecl *CollisionFunction_00d42f40)(
    const CollisionBody_00d42f40*, const CollisionBody_00d42f40*,
    const CollisionInput_00d42f40*, void*);

struct AgentFunctions_00d42f40
{
    CollisionFunction_00d42f40 process;
    void* create;
    void* closestPoints;
    void* penetrations;
    void* linearCast;
};

struct Dispatcher_00d42f40
{
    CollisionFunction_00d42f40 getFunction(unsigned int firstType, unsigned int secondType) const
    {
        const unsigned char* storage = reinterpret_cast<const unsigned char*>(this);
        const unsigned int lookupRow = firstType + 13;
        const unsigned int agent = storage[lookupRow * 32 + secondType];
        const AgentFunctions_00d42f40* functions =
            reinterpret_cast<const AgentFunctions_00d42f40*>(storage + 0x9A4);
        return functions[agent].process;
    }
};

struct CollisionInput_00d42f40
{
    const Dispatcher_00d42f40* dispatcher;
};

// Builds a child collision body from the transform shape's child and transform, then dispatches it against the second body via the dispatcher.
// @fnv 0x00d42f40
// pdb: hkpTransformAgent::staticGetPenetrations | hkpTransformAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyAin, bodyB, input, collector
void __cdecl ProcessTransformShapeCollision(
    const CollisionBody_00d42f40* first,
    const CollisionBody_00d42f40* second,
    const CollisionInput_00d42f40* input,
    void* output)
{
    const TransformShape_00d42f40* shape =
        static_cast<const TransformShape_00d42f40*>(first->shape);
    Transform_00d42f40 transform;
    transform.FUN_00cb2240(first->transform, &shape->transform);

    CollisionBody_00d42f40 childBody;
    childBody.parent = first;
    childBody.transform = &transform;
    childBody.shape = shape->child;
    childBody.shapeKey = 0;

    input->dispatcher->getFunction(childBody.shape->type, second->shape->type)(
        &childBody, second, input, output);
}

struct CallTarget_00d42fc0 { int hkpTransformAgent_updateShapeCollectionFilter(int, int, int, int); };
struct SearchObject {
    int FUN_00d43600(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d43600
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::updateShapeCollectionFilter | hkpTransformAgent.obj | fnv360_0822_debug, vtable, high
// pdb params: bodyA, bodyB, input, constraintOwner
int SearchObject::FUN_00d43600(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiResult = (unsigned int)((CallTarget_00d42fc0*)this)->hkpTransformAgent_updateShapeCollectionFilter((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)uiResult;
}

__declspec(align(16)) struct S_00d431b0_Raw {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
};

struct S_00d431b0_Vec {
    __m128 q;
};

struct S_00d431b0_Rows {
    S_00d431b0_Vec r0;
    S_00d431b0_Vec r1;
    S_00d431b0_Vec r2;
    S_00d431b0_Vec r3;
};

struct S_00d431b0_Blk {
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
};

struct S_00d431b0 {
    S_00d431b0_Rows rows;
    S_00d431b0_Blk blk;
    int u90;
    int u94;
    int u98;
    int u9c;
    float fa0;
    float fa4;
    float fa8;
    char ba;
    char bb;
    char bc;
    S_00d431b0& CopyFrom(const S_00d431b0& o);
};

// Copies the rows, blk, u90-u9c, fa0-fa8 and ba-bc members from o into this object and returns *this.
// @f3 0x009cdcb0 (community match, verified in this file)
// pdb: hkMotionState::hkMotionState | hkpTransformAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: __that
S_00d431b0& S_00d431b0::CopyFrom(const S_00d431b0& o)
{
  volatile S_00d431b0_Raw stage;
  stage.u00 = ((const int*)&o.rows)[0];
  double first = *(volatile float*)&stage.u00;
  stage.u04 = ((const int*)&o.rows)[1];
  stage.u08 = ((const int*)&o.rows)[2];
  stage.u0c = ((const int*)&o.rows)[3];
  stage.u10 = ((const int*)&o.rows)[4];
  stage.u14 = ((const int*)&o.rows)[5];
  stage.u18 = ((const int*)&o.rows)[6];
  stage.u1c = ((const int*)&o.rows)[7];
  stage.u20 = ((const int*)&o.rows)[8];
  stage.u24 = ((const int*)&o.rows)[9];
  stage.u28 = ((const int*)&o.rows)[10];
  stage.u2c = ((const int*)&o.rows)[11];
  stage.u30 = ((const int*)&o.rows)[12];
  stage.u34 = ((const int*)&o.rows)[13];
  stage.u38 = ((const int*)&o.rows)[14];
  int tailWord = ((const int*)&o.rows)[15];
  ((volatile float*)&rows)[0] = (float)first;
  double second = *(volatile float*)&stage.u04;
  stage.u3c = tailWord;
  ((volatile float*)&rows)[1] = (float)second;
  ((float*)&rows)[2] = *(volatile float*)&stage.u08;
  ((float*)&rows)[3] = *(volatile float*)&stage.u0c;
  ((float*)&rows)[4] = *(volatile float*)&stage.u10;
  ((float*)&rows)[5] = *(volatile float*)&stage.u14;
  ((float*)&rows)[6] = *(volatile float*)&stage.u18;
  ((float*)&rows)[7] = *(volatile float*)&stage.u1c;
  ((float*)&rows)[8] = *(volatile float*)&stage.u20;
  ((float*)&rows)[9] = *(volatile float*)&stage.u24;
  ((float*)&rows)[10] = *(volatile float*)&stage.u28;
  ((float*)&rows)[11] = *(volatile float*)&stage.u2c;
  ((float*)&rows)[12] = *(volatile float*)&stage.u30;
  ((float*)&rows)[13] = *(volatile float*)&stage.u34;
  ((float*)&rows)[14] = *(volatile float*)&stage.u38;
  ((float*)&rows)[15] = *(volatile float*)&stage.u3c;
  blk = o.blk;
  u90 = o.u90; u94 = o.u94; u98 = o.u98; u9c = o.u9c;
  fa0 = o.fa0; fa4 = o.fa4; fa8 = o.fa8;
  ba = o.ba; bb = o.bb; bc = o.bc;
  return *this;
}


extern const __m128 DAT_010c4c00;
extern "C" __m128 __cdecl _mm_mul_ps(__m128, __m128);
extern "C" __m128 __cdecl _mm_add_ps(__m128, __m128);
extern "C" __m128 __cdecl _mm_shuffle_ps(__m128, __m128, unsigned int);

struct VectorComponentValue {
    __m128 m_vValue;
    __forceinline VectorComponentValue(const __m128& r) : m_vValue(r) {}
};

struct __declspec(align(16)) FourFloatVector {
    __m128 m_vComponents;
    __forceinline VectorComponentValue getDistanceSimdReal() const {
        return VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
    }
    __forceinline void addMul4(const VectorComponentValue& r, const FourFloatVector& a) {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.m_vValue, a.m_vComponents), m_vComponents);
    }
    __forceinline void setNeg3(const FourFloatVector& a) {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setNeg3() {
        m_vComponents = _mm_xor_ps(m_vComponents, DAT_010c4c00);
    }
};

struct __declspec(align(16)) AlignedPairData {
    FourFloatVector m_vContactPosition;
    FourFloatVector m_vSeparatingNormal;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct Features {
    unsigned char a : 4;
    unsigned char b : 4;
    __forceinline void flip() {
        unsigned char t = a;
        a = b;
        b = t;
    }
};
struct ConvexFeaturePairCache {
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    Features m_features;
    unsigned char m_auiShapeKeys;
    __forceinline void flip() {

        unsigned char t = m_features.a;
        m_features.a = m_features.b;
        unsigned char dimA;
        m_features.b = t;
        dimA = m_ucDimensionA;

        unsigned char dimB = m_ucDimensionB;
        m_ucDimensionB = dimA;
        m_ucDimensionA = dimB;

        int idx = (int)dimB + (int)dimA - 1;
        unsigned short v0 = m_kVertices[0];
        m_kVertices[0] = m_kVertices[idx];
        m_kVertices[idx] = v0;

        if ((m_ucDimensionA & m_ucDimensionB) == 2) {
            unsigned short v1 = m_kVertices[1];
            m_kVertices[1] = m_kVertices[2];
            m_kVertices[2] = v1;
        }

    }
};

struct CollisionCacheState {
    FourFloatVector m_vSeparatingNormal;
    float m_uiCommandId;
    int unk3034;
    int unk3038;
    int unk303c;
    ConvexFeaturePairCache m_kGskCache;
    __forceinline void flip() {
        m_vSeparatingNormal.setNeg3();
        m_kGskCache.flip();
    }
};

struct hkpCdBody; struct GskAgentInput;

struct __declspec(align(16)) S_00d43030_Transform {
    float m00; float m04; float m08; float m0C;
    float m10; float m14; float m18; float m1C;
    float m20; float m24; float m28; float m2C;
    float m30; float m34; float m38; float m3C;
    void FUN_00cb2240(const S_00d43030_Transform& a, const S_00d43030_Transform& b);
};
struct __declspec(align(16)) S_00d43030_MotionState {
    S_00d43030_Transform m_kMotionTransform;
    float unk40; float unk44; float unk48; float unk4C;
    float unk50; float unk54; float unk58; float unk5C;
    float unk60; float unk64; float unk68; float unk6C;
    float unk70; float unk74; float unk78; float unk7C;
    float unk80; float unk84; float unk88; float unk8C;
    float unk90; float unk94; float unk98; float unk9C;
    float unkA0; float unkA4; float unkA8; float unkAC;
    S_00d43030_MotionState(const S_00d43030_MotionState& o) { m_kMotionTransform = o.m_kMotionTransform; unk40 = o.unk40; unk44 = o.unk44; unk48 = o.unk48; unk4C = o.unk4C; unk50 = o.unk50; unk54 = o.unk54; unk58 = o.unk58; unk5C = o.unk5C; unk60 = o.unk60; unk64 = o.unk64; unk68 = o.unk68; unk6C = o.unk6C; unk70 = o.unk70; unk74 = o.unk74; unk78 = o.unk78; unk7C = o.unk7C; unk80 = o.unk80; unk84 = o.unk84; unk88 = o.unk88; unk8C = o.unk8C; unk90 = o.unk90; unk94 = o.unk94; unk98 = o.unk98; unk9C = o.unk9C; unkA0 = o.unkA0; unkA4 = o.unkA4; unkA8 = o.unkA8; unkAC = o.unkAC; }
    S_00d43030_Transform& getTransform() { return m_kMotionTransform; }
};
struct S_00d43030_Shape {
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};
struct __declspec(align(16)) S_00d43030_TransformShape : S_00d43030_Shape {
    void* m_containerVtbl;
    S_00d43030_Shape* m_pContainedShape;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    S_00d43030_Transform m_kMotionTransform;
};
struct S_00d43030_CdBody {
    const S_00d43030_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d43030_CdBody* m_parent;
    S_00d43030_CdBody(const S_00d43030_CdBody* parent, const S_00d43030_MotionState* ms, const S_00d43030_Shape* shape, unsigned int key) { m_pCollisionShape = shape; m_uiCollisionShapeKey = key; m_pMotionState = ms; m_parent = parent; }
    const S_00d43030_Shape* getShape() const { return m_pCollisionShape; }
    const S_00d43030_MotionState* GetMotionState() const { return static_cast<const S_00d43030_MotionState*>(m_pMotionState); }
    const S_00d43030_Transform& getTransform() const { return static_cast<const S_00d43030_MotionState*>(m_pMotionState)->m_kMotionTransform; }
};
struct S_00d43030_ContactMgr;
struct S_00d43030_CollisionInput;
struct S_00d43030_Agent;
typedef S_00d43030_Agent* (*S_00d43030_CreateFunc)(const S_00d43030_CdBody&, const S_00d43030_CdBody&, const S_00d43030_CollisionInput&, S_00d43030_ContactMgr*);
struct S_00d43030_AgentFuncs {
    S_00d43030_CreateFunc m_pCreateFunc;
    void* unk04; void* unk08; void* unk0C; void* unk10;
};
struct S_00d43030_Dispatcher {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d43030_AgentFuncs m_agent2Funcs[32];
    __forceinline S_00d43030_Agent* getNewCollisionAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) const;
};
struct S_00d43030_CollisionInput {
    S_00d43030_Dispatcher* m_pCollisionDispatcher;
    int unk04; int unk08; int unk0C; int unk10;
    int m_bCreatePredictiveAgents;
};
__forceinline S_00d43030_Agent* S_00d43030_Dispatcher::getNewCollisionAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) const
{
    int typeA = bodyA.getShape()->m_type;
    int typeB = bodyB.getShape()->m_type;
    const unsigned char (*tbl)[32] = input.m_bCreatePredictiveAgents ? m_agent3TypeMap : m_agent2TypeMap;
    int idx = tbl[typeA][typeB];
    S_00d43030_CreateFunc f = m_agent2Funcs[idx].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct S_00d43030_Router : Resource {
    Allocator& heap() { return *allocator; }
};

struct S_00d43030_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00d43030_RefObj() throw();
    __forceinline S_00d43030_RefObj() throw() { m_sReferenceCount = 1; }
    __forceinline void* operator new(unsigned int nbytes)
    {
        S_00d43030_RefObj* b = static_cast<S_00d43030_RefObj*>((void*)static_cast<S_00d43030_Router*>(FUN_00c85750())->heap().allocate(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void*) {}
};
struct S_00d43030_Agent : S_00d43030_RefObj {
    S_00d43030_ContactMgr* m_pContactManager;
    __forceinline S_00d43030_Agent(S_00d43030_ContactMgr* mgr) throw() : m_pContactManager(mgr) {}
    virtual void vfn04();
};
struct S_00d43030_TransformAgent : S_00d43030_Agent {
    S_00d43030_Agent* m_pAgent;
    __forceinline S_00d43030_TransformAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw();
    virtual void vfn04();
};
__forceinline S_00d43030_TransformAgent::S_00d43030_TransformAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw()
    : S_00d43030_Agent(mgr)
{
    const S_00d43030_TransformShape* tShapeA = static_cast<const S_00d43030_TransformShape*>(bodyA.getShape());
    const S_00d43030_Shape* childShape = tShapeA->m_pContainedShape;

    S_00d43030_MotionState ms = *bodyA.GetMotionState();
    ms.getTransform().FUN_00cb2240(bodyA.getTransform(), tShapeA->m_kMotionTransform);

    S_00d43030_CdBody newOperandA(&bodyA, &ms, childShape, 0);
    m_pAgent = input.m_pCollisionDispatcher->getNewCollisionAgent(newOperandA, bodyB, input, mgr);
}
template <class AGENT> struct S_00d43030_Symmetric : AGENT {
    __forceinline S_00d43030_Symmetric(const S_00d43030_CdBody& A, const S_00d43030_CdBody& B, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw()
        : AGENT(B, A, input, mgr) {}
    virtual void vfn04();
};

// Allocates a symmetric TransformAgent for the two bodies and returns it as an Agent pointer.
// @f3 0x009cdb30 (community match, verified in this file)
struct S9cdb30_TransformAgent : S_00d43030_Agent {
    S_00d43030_Agent* m_pAgent;
    __forceinline void* operator new(unsigned int nbytes)
    {
        void* tls = DAT_00d9b080(DAT_010f3170);
        S_00d43030_RefObj* b = (S_00d43030_RefObj*)((BlockAllocator*)tls)->FUN_008f6d30(nbytes, 0x1f);
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void*) {}
    __forceinline S9cdb30_TransformAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw()
        : S_00d43030_Agent(mgr)
    {
        const S_00d43030_TransformShape* tShapeA = static_cast<const S_00d43030_TransformShape*>(bodyA.getShape());
        const S_00d43030_Shape* childShape = tShapeA->m_pContainedShape;
        MotionState ms;
        ms.FUN_009cdcb0(bodyA.m_pMotionState);
        ms.hkTransform_setMul(bodyA.m_pMotionState, *(const hkVector4*)&tShapeA->m_kMotionTransform);
        S_00d43030_CdBody newOperandA(&bodyA, (const S_00d43030_MotionState*)&ms, childShape, 0);
        const S_00d43030_Dispatcher* d = input.m_pCollisionDispatcher;
        int typeA = newOperandA.getShape()->m_type;
        int typeB = bodyB.getShape()->m_type;
        const unsigned char (*tbl)[32] = input.unk10 ? d->m_agent3TypeMap : d->m_agent2TypeMap;
        int idx = tbl[typeA][typeB];
        S_00d43030_CreateFunc f = d->m_agent2Funcs[idx].m_pCreateFunc;
        m_pAgent = f(newOperandA, bodyB, input, mgr);
    }
    virtual void vfn04();
};
struct S9cdb30_Symmetric : S9cdb30_TransformAgent {
    __forceinline S9cdb30_Symmetric(const S_00d43030_CdBody& A, const S_00d43030_CdBody& B, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw()
        : S9cdb30_TransformAgent(B, A, input, mgr) {}
    virtual void vfn04();
};

// pdb: hkpTransformAgent::createTransformBAgent | hkpTransformAgent.obj | fnv360_0822_retail, uvref, high
// pdb params: bodyA, bodyB, input, mgr
// pdb: hkpTransformAgent::createTransformBAgent | hkpTransformAgent.obj | fnv360_0822_retail, uvref, high (was: CreateTransformAgent)
S_00d43030_Agent* hkpTransformAgent_createTransformBAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr)
{
    S9cdb30_TransformAgent* agent = new S9cdb30_Symmetric(bodyA, bodyB, input, mgr);
    return agent;
}


extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl hkpTransformAgent_staticLinearCast(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern unsigned long DAT_0126835c;

struct S_00d42b50_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        m_uiStartTicks = t;
    }
};

struct S_00d42b50_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d42b50_MonitorStream& GetMonitorStream()
    {
        return *(S_00d42b50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
};

struct __declspec(align(16)) S_00d42b50_Vec { float x, y, z, w; };

struct __declspec(align(16)) S_00d42b50_Rot {
    float x, y, z, w;
    void FUN_00c66320(const S_00d42b50_Vec* a, const S_00d42b50_Vec* b);
};

struct S_00d42b50_Xform {
    S_00d42b50_Vec c0, c1, c2, t;
    void FUN_00cb2240(const S_00d42b50_Xform& a, const S_00d42b50_Xform& b);
};

struct S_00d42b50_Motion {
    S_00d42b50_Xform m_kMotionTransform;
    S_00d42b50_Vec unk40;
    S_00d42b50_Vec unk50;
    S_00d42b50_Rot unk60;
    S_00d42b50_Rot unk70;
    S_00d42b50_Vec unk80;
    S_00d42b50_Vec unk90;
    float unkA0;
};

struct S_00d42b50_Shape {
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
};

struct S_00d42b50_TShape : S_00d42b50_Shape {
    int unk10;
    S_00d42b50_Shape* m_pContainedShape;
    int unk18;
    int unk1C;
    S_00d42b50_Vec m_rotation;
    S_00d42b50_Xform m_kMotionTransform;
};

struct S_00d42b50_CdBody {
    const S_00d42b50_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d42b50_Motion* m_pMotionState;
    const S_00d42b50_CdBody* m_parent;
};

struct S_00d42b50_Input;
struct S_00d42b50_Output;

struct S_00d42b50_Agent {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void ProcessAgent(const S_00d42b50_CdBody& a, const S_00d42b50_CdBody& b, const S_00d42b50_Input& in, S_00d42b50_Output& out);
};

struct S_00d42b50_Cls {
    int unk00;
    int unk04;
    int unk08;
    S_00d42b50_Agent* m_pAgent;
    void hkpTransformAgent_processCollision(const S_00d42b50_CdBody& bodyA, const S_00d42b50_CdBody& bodyB, const S_00d42b50_Input& input, S_00d42b50_Output& output);
};

// @f3 0x009cd5c0 (community match, verified in this file)
// pdb: hkpTransformAgent::processCollision | hkpTransformAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S_00d42b50_Cls::hkpTransformAgent_processCollision(const S_00d42b50_CdBody& bodyA, const S_00d42b50_CdBody& bodyB, const S_00d42b50_Input& input, S_00d42b50_Output& output)
{
    union Scratch {
        unsigned int tick;
        const S_00d42b50_TShape* shape;
    } scratch;
    {
        S_00d42b50_MonitorStream& mStream = S_00d42b50_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S_00d42b50_TimerCommand* h = (S_00d42b50_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "TtTransform";
            { unsigned int fnv_ticks;
                __asm {
                    rdtsc
                    mov dword ptr[fnv_ticks], eax
                }
                scratch.tick = fnv_ticks; }
            h->m_uiStartTicks = scratch.tick;
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }

    scratch.shape = (const S_00d42b50_TShape*)bodyA.m_pCollisionShape;
    const S_00d42b50_Xform& xf = scratch.shape->m_kMotionTransform;
    S_00d42b50_Motion ms;
    ms.m_kMotionTransform.FUN_00cb2240(bodyA.m_pMotionState->m_kMotionTransform, xf);
    const S_00d42b50_Motion* src = bodyA.m_pMotionState;
    ms.unk40.x = src->unk40.x;
    ms.unk40.y = src->unk40.y;
    ms.unk40.z = src->unk40.z;
    ms.unk40.w = src->unk40.w;
    ms.unk50.x = src->unk50.x;
    ms.unk50.y = src->unk50.y;
    ms.unk50.z = src->unk50.z;
    ms.unk50.w = src->unk50.w;
    ms.unk60.FUN_00c66320((const S_00d42b50_Vec*)&src->unk60, &scratch.shape->m_rotation);
    ms.unk70.FUN_00c66320((const S_00d42b50_Vec*)&src->unk70, &scratch.shape->m_rotation);

    float dx = src->unk80.x - xf.t.x;
    float dy = src->unk80.y - xf.t.y;
    float dz = src->unk80.z - xf.t.z;
    ms.unk80.x = xf.c0.x * dx + xf.c0.y * dy + xf.c0.z * dz;
    ms.unk80.y = xf.c1.x * dx + xf.c1.y * dy + xf.c1.z * dz;
    ms.unk80.z = xf.c2.x * dx + xf.c2.y * dy + xf.c2.z * dz;
    ms.unk80.w = 0.0f;
    ms.unk90.x = src->unk90.x;
    ms.unk90.y = src->unk90.y;
    ms.unk90.z = src->unk90.z;
    ms.unk90.w = src->unk90.w;
    ms.unkA0 = src->unkA0;

    S_00d42b50_CdBody newBody;
    newBody.m_pMotionState = &ms;
    newBody.m_parent = &bodyA;
    newBody.m_pCollisionShape = scratch.shape->m_pContainedShape;
    newBody.m_uiCollisionShapeKey = 0;
    m_pAgent->ProcessAgent(newBody, bodyB, input, output);

    {
        S_00d42b50_MonitorStream& mStream = S_00d42b50_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S_00d42b50_TimerCommand* h = (S_00d42b50_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "Et";
            { unsigned int fnv_ticks;
                __asm {
                    rdtsc
                    mov dword ptr[fnv_ticks], eax
                }
                scratch.tick = fnv_ticks; }
            h->m_uiStartTicks = scratch.tick;
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }
}


struct CollisionAgentContext;

struct TimInvalidationTarget
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
    virtual void RemovePoint(const CollisionAgentContext& input);
};

struct TransformTimForwarder
{
    int unk00;
    int unk04;
    int unk08;
    TimInvalidationTarget* m_pAgent;
    void hkpTransformAgent_invalidateTim(const CollisionAgentContext& input);
};

// @fnv 0x00d42a00
// pdb: hkpTransformAgent::invalidateTim | hkpTransformAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void TransformTimForwarder::hkpTransformAgent_invalidateTim(const CollisionAgentContext& input)
{
    m_pAgent->RemovePoint(input);
}

struct TransformClosestPointCollector;

struct TransformClosestChildAgent {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void getClosestPoints(const S_00d42d60_CdBody& bodyA,
        const S_00d42d60_CdBody& bodyB, const S_00d42d60_Input& input,
        TransformClosestPointCollector& collector);
};

struct TransformClosestAgent {
    int unk00;
    int unk04;
    int unk08;
    TransformClosestChildAgent* m_pAgent;
    void FUN_00d42de0(const S_00d42d60_CdBody& bodyA,
        const S_00d42d60_CdBody& bodyB, const S_00d42d60_Input& input,
        TransformClosestPointCollector& collector);
};

// Builds a temporary child body from bodyA's contained shape and motion transform, then delegates to m_pAgent to collect closest points with bodyB.
// @fnv 0x00d42de0
void TransformClosestAgent::FUN_00d42de0(const S_00d42d60_CdBody& bodyA,
    const S_00d42d60_CdBody& bodyB, const S_00d42d60_Input& input,
    TransformClosestPointCollector& collector)
{
    __declspec(align(16)) S_00d42d60_Transform transform;
    const S_00d42d60_TransformShape* shape =
        static_cast<const S_00d42d60_TransformShape*>(bodyA.m_pCollisionShape);
    transform.FUN_00cb2240(
        *static_cast<const S_00d42d60_Transform*>(bodyA.m_pMotionState),
        shape->m_kMotionTransform);

    S_00d42d60_CdBody childBody;
    childBody.m_pMotionState = &transform;
    childBody.m_parent = &bodyA;
    childBody.m_pCollisionShape = shape->m_pContainedShape;
    childBody.m_uiCollisionShapeKey = 0;
    m_pAgent->getClosestPoints(childBody, bodyB, input, collector);
}

struct TransformClosestDispatcher
{
    int unk000; int unk004; int unk008; int unk00c;
    int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c;
    int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c;
    int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c;
    int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c;
    int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac;
    int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc;
    int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c;
    int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    int unk190; int unk194; int unk198; int unk19c;
    unsigned char agentTypes[32][32];
    unsigned char predictiveAgentTypes[32][32];
    CollisionAgentFunctionTable functions[64];
};

struct __declspec(align(16)) TransformClosestFrame
{
    const Shape_00d42f40* shape;
    unsigned int shapeKey;
    const Transform_00d42f40* motion;
    const CollisionBody_00d42f40* parent;
    Transform_00d42f40 transform;
};

// @fnv 0x00d42e50
// pdb: hkpTransformAgent::staticGetClosestPoints | hkpTransformAgent.obj | fnv360_0822_retail, objrun + bridge(hash|objrun) + skyrim(hash), high
void __cdecl hkpTransformAgent_staticGetClosestPoints(const CollisionBody_00d42f40* bodyA,
                         const CollisionBody_00d42f40* bodyB,
                         const CollisionInput_00d42f40* input, void* collector)
{
    const TransformShape_00d42f40* shape =
        static_cast<const TransformShape_00d42f40*>(bodyA->shape);
    TransformClosestFrame frame;
    frame.transform.FUN_00cb2240(bodyA->transform, &shape->transform);
    frame.parent = bodyA;
    frame.motion = &frame.transform;
    const Shape_00d42f40* child = shape->child;
    frame.shape = child;
    frame.shapeKey = 0;

    const unsigned char* table = reinterpret_cast<const unsigned char*>(input->dispatcher);
    unsigned int index = ((child->type + 13) << 5) + bodyB->shape->type;
    unsigned char agent = table[index];
    const TransformClosestDispatcher* dispatcher =
        reinterpret_cast<const TransformClosestDispatcher*>(input->dispatcher);
    void* function = dispatcher->functions[agent].f8;
    reinterpret_cast<void (__cdecl*)(const void*, const CollisionBody_00d42f40*,
                                    const CollisionInput_00d42f40*, void*)>(function)
        (&frame.shape, bodyB, input, collector);
}
