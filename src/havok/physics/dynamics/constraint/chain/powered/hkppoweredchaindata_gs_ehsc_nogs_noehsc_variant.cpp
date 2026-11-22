#include "f3_common.h"
// src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpPoweredChainData.h"
class hkRefObjE3B8
{
  public:
    virtual ~hkRefObjE3B8() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE3B8() throw()
    {
        m_sReferenceCount = 1;
    }
};
class hkBaseE3B8 : public hkRefObjE3B8
{
  public:
    void* m_pOwnerObject;
    hkBaseE3B8() throw() : m_pOwnerObject(0)
    {}
};
struct FUN_00d21ce0_cls
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;

    FUN_00d21ce0_cls() throw()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* owner) throw();
};
template <typename T> struct hkArrayE3B8
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE3B8() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class FUN_00e3b9a0
{
  public:
    ~FUN_00e3b9a0() throw();
};
class hkMemoryAllocatorXe3c210
{
  public:
    virtual ~hkMemoryAllocatorXe3c210() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterXe3c210
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe3c210* m_pStreamAllocator;

    hkMemoryAllocatorXe3c210& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterXe3c210& __cdecl FUN_00c85750() throw();
class hkObje3c210 : public FUN_00e3b9a0
{
  public:
    hkObje3c210* DestroyObject(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObje3c210*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

#include <xmmintrin.h>
__declspec(align(16)) extern const float DAT_010c44d0[4];

volatile int g_a, g_b, g_r;

inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct Vector
{
    union
    {
        __m128 simd;
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00cb26e0(const hkRotation*);
    void FUN_00c66320(const Vector*, const Vector*);
};
struct Rotation
{
    Vector col[3];
    void FUN_00cb2d90(const Vector*);
};
struct Transform
{
    Rotation rotation;
    Vector translation;
};
struct Entity;
struct ConstraintRuntime
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    char* solverResults;
};
struct ChainInstance
{
    int unk00, unk04, unk08, unk0c, unk10;
    Entity* master;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    ConstraintRuntime* runtime;
    int unk34;
    Entity** entities;
    int entityCount;
};
struct QueryInput
{
    int unk00;
    float unk04, unk08;
    int unk0c, unk10, unk14, unk18, unk1c;
    float virtualMass;
    float rhsFactor;
    int unk28, unk2c;
    int offsetA, offsetB;
    Transform* transformA;
    Transform* transformB;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    ChainInstance* chain;
    char* runtime;
    int unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct QueryOutput
{
    char* jacobian;
};
struct ConstraintInfo
{
    Vector pivotA, pivotB;
    Vector target, targetB;
    void* motors[3];
    unsigned char switched;
    unsigned char unk4d;
    short unk4e;
};
struct MotorState
{
    float unk00, unk04;
};
struct MotorInput
{
    float currentVelocity;
    void* step;
    MotorState state;
    float positionError, deltaTarget;
};
struct MotorOutput
{
    float a, b, c, d, e, f;
};
struct ChainMatrix
{
    unsigned char status;
    unsigned char unk01;
    short unk02;
    float values[15];
};
struct BuildInfo
{
    int count;
    float tau, damping, linAdd, linMul, angAdd, angMul;
    int* offsets;
    int offset;
    ChainMatrix* matrices;
    float zero;
    char* states;
    char* jacobian;
};
struct MemoryAllocator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void freeBlock(void*, int);
};
void __cdecl FUN_00c908c0(MemoryAllocator*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
extern "C" void __cdecl AppendEventRecord(const QueryInput*, QueryOutput*, char*, int);
char* __cdecl FUN_00dd13e0(char*, int);
void __cdecl WriteInputHeader(BuildInfo*, const QueryInput*, QueryOutput*);
struct Entity
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
    Transform transform;
};
// Quaternion error, with sign chosen for the shortest arc.
static __declspec(noinline) void FUN_00e3b680(const Vector& b, const Vector& a, Vector& out)
{
    __m128 av = a.simd, bv = b.simd;
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(bv, bv, 0xc9), _mm_shuffle_ps(av, av, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(bv, bv, 0xd2), _mm_shuffle_ps(av, av, 0xc9)));
    out.simd = cross;
    __m128 aw = _mm_shuffle_ps(a.simd, a.simd, 0xff);
    aw = _mm_shuffle_ps(aw, aw, 0);
    out.simd = _mm_add_ps(_mm_mul_ps(aw, b.simd), cross);
    __m128 bw = _mm_shuffle_ps(b.simd, b.simd, 0xff);
    bw = _mm_shuffle_ps(bw, bw, 0);
    __m128 error = _mm_sub_ps(out.simd, _mm_mul_ps(bw, a.simd));
    out.simd = _mm_add_ps(error, error);
    __m128 dot = _mm_mul_ps(a.simd, b.simd);
    dot = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0x4e), dot);
    dot = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0xb1), dot);
    if (_mm_movemask_ps(dot) & 1)
        out.simd = _mm_xor_ps(out.simd, _mm_set1_ps(-0.0f));
}
static __forceinline void transformPoint(Vector& out, const Transform& t, const Vector& p)
{
    out.simd = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p.simd, p.simd, 0x55), t.rotation.col[1].simd),
                   _mm_mul_ps(_mm_shuffle_ps(p.simd, p.simd, 0), t.rotation.col[0].simd)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p.simd, p.simd, 0xaa), t.rotation.col[2].simd), t.translation.simd));
}
template <class T> __forceinline void copyConstruct(T* dest, int n, const T& x)
{
    for (int i = 0; i < n; ++i)
        new (dest + i) T(x);
}
template <class T, int N> struct InplaceArray
{
    T* data;
    int size, capacity;
    T storage[N];
    InplaceArray() : data(storage), size(0), capacity(0x80000000 | N)
    {}
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryRouterXe3c210* router = &FUN_00c85750();
        MemoryAllocator* heap = reinterpret_cast<MemoryAllocator*>(router->m_pStreamAllocator);
        int c = capacity & 0x3fffffff;
        if (c < n)
        {
            int next = c * 2;
            if (n >= next)
                next = n;
            FUN_00c908c0(heap, this, next, sizeof(T));
        }
        for (int j = n; j < size; ++j)
            data[j].~T();
        for (int j = size; j < n; ++j)
            new (data + j) T;
        size = n;
    }
    __forceinline void pushBackUnchecked(const T& x)
    {
        copyConstruct(data + size, 1, x);
        ++size;
    }
    __forceinline void AddBack(const T& x)
    {
        hkMemoryRouterXe3c210* route = &FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(route->m_pStreamAllocator, this, sizeof(T));
        copyConstruct(data + size, 1, x);
        ++size;
    }
    __forceinline void deallocate(MemoryAllocator& heap)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            heap.freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
    }
    __forceinline void clear()
    {
        hkMemoryRouterXe3c210* router = &FUN_00c85750();
        MemoryAllocator* heap = reinterpret_cast<MemoryAllocator*>(router->m_pStreamAllocator);
        deallocate(*heap);
    }
};
__forceinline char* angularAndKeep(char* lin, QueryOutput& out, int n, char*& keep)
{
    char* p = out.jacobian;
    keep = lin;
    return FUN_00dd13e0(p, n);
}
struct PoweredChain : hkpPoweredChainData
{
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void* motorStep(char*);
    __forceinline ConstraintInfo& getInfo(int i)
    {
        return reinterpret_cast<ConstraintInfo*>(m_pConstraintInfo.m_data)[i];
    }
    void hkpPoweredChainData_buildJacobian(const QueryInput&, QueryOutput&);
};
// @f3 0x00a71810 (community match, verified in this file)
struct QueryOutput;
struct F3ChainTransform;
struct F3ChainQuaternion {
 __declspec(align(16)) float x; float y,z,w;
 __forceinline F3ChainQuaternion& operator=(const F3ChainQuaternion& s) { x=s.x;y=s.y;z=s.z;w=s.w;return *this; }
 void FUN_00924360(const hkRotation*);
 void FUN_008d3290(const F3ChainQuaternion*,const F3ChainQuaternion*);
 void setTransformedPos(const F3ChainTransform&,const F3ChainQuaternion&);
 __forceinline float getX() const { return x; }
 __forceinline float getY() const { return y; }
 __forceinline float getZ() const { return z; }
};
struct F3ChainRotation {
 F3ChainQuaternion col[3];
 void hkRotation_set(const F3ChainQuaternion*);
};
struct F3ChainTransform { F3ChainRotation rotation; F3ChainQuaternion translation; };
struct F3ConstraintInfo {
 F3ChainQuaternion pivotA,pivotB,target,targetB;
 void* motors[3]; unsigned char switched,unk4d; short unk4e;
};
template<class T> __forceinline void swapF3(T& x, T& y) { T t(x); x = y; y = t; }
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_010f3170;
struct ChainAllocatorF3 { void __thiscall FUN_008f6d90(void*,int,int); };
void __cdecl FUN_00901e90(void*,int,int);
void __cdecl FUN_00901f10(void*,int);
template<class T,int N> struct ArrayF3 {
 T* data; int size,capacity; T storage[N];
 ArrayF3():data(storage),size(0),capacity(0x80000000|N) {}
 __forceinline T& operator[](int i) { return data[i]; }
 __forceinline void SetSizeAndGrow(int n) {
 int c=capacity&0x3fffffff; if(c<n) {int next=(n<c*2)?c*2:n; FUN_00901e90(this,next,sizeof(T));}
 for(int j=n;j<size;++j) data[j].~T();
 for(int j=size;j<n;++j) new(data+j) T;
 size=n;
 }
 __forceinline void pushBackUnchecked(const T& x) { data[size]=x; ++size; }
 __forceinline void AddBack(const T& x) { if(size==(capacity&0x3fffffff)) FUN_00901f10(this,sizeof(T)); data[size]=x; ++size; }
 __forceinline void clear() { if((capacity&0x80000000)==0) { int c=capacity&0x3fffffff; ChainAllocatorF3* a=(ChainAllocatorF3*)TlsGetValue(DAT_010f3170); a->FUN_008f6d90(data,c*sizeof(T),0x17); } }
};
__forceinline void F3ChainQuaternion::setTransformedPos(const F3ChainTransform& t,const F3ChainQuaternion& p) {
 F3ChainQuaternion& o=*this;
 float x=p.getX(),y=p.getY(),z=p.getZ();
 o.x=(x*t.rotation.col[0].getX()+t.rotation.col[1].getX()*y)+t.rotation.col[2].getX()*z+t.translation.getX();
 o.y=(x*t.rotation.col[0].getY()+t.rotation.col[1].getY()*y)+t.rotation.col[2].getY()*z+t.translation.getY();
 o.z=(x*t.rotation.col[0].getZ()+t.rotation.col[1].getZ()*y)+t.rotation.col[2].getZ()*z+t.translation.getZ();
 o.w=0.0f;
}
struct EntityF3 {
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
F3ChainTransform transform;
};
struct ChainF3 {
int unk00,unk04,unk08,unk0c,unk10; EntityF3* master;
int unk18,unk1c,unk20,unk24; ConstraintRuntime* runtime; EntityF3** entities; int entityCount;
};
struct PadF3 { float v; __forceinline operator float() const { return v; } };
struct F3QueryInput {
 int unk00; float unk04; PadF3 unk08; int unk0c,unk10,unk14,unk18;
 PadF3 virtualMass; float rhsFactor; int unk24,unk28,unk2c; int offsetA,offsetB;
 F3ChainTransform* transformA; F3ChainTransform* transformB; int unk40,unk44;
 ChainF3* chain; char* runtime; int unk50,unk54,unk58,unk5c;
};
char* __cdecl FUN_00a523f0(char*);
void __cdecl FUN_00a4e400(F3QueryInput*);
void __cdecl FUN_00a4fe70(F3ChainQuaternion*,F3ChainQuaternion*,float,F3QueryInput*,char*);
void __cdecl FUN_009f9580(F3ChainQuaternion*,F3QueryInput*,char*,float*);
void __cdecl FUN_00a50540(void*,MotorInput*,MotorOutput*);
struct F3MotorDispatch : hkpPoweredChainData
{
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void* motorStep(char*);
};
__forceinline F3ConstraintInfo& getF3Info(const hkpPoweredChainData& chain, unsigned int i)
{
    return reinterpret_cast<F3ConstraintInfo*>(chain.m_pConstraintInfo.m_data)[i];
}
static __declspec(noinline) void FUN_00a71350(const F3ChainQuaternion& b, const F3ChainQuaternion& a, F3ChainQuaternion& out)
{
    float cx=b.y*a.z-b.z*a.y;
    float cy=b.z*a.x-b.x*a.z;
    float cz=b.x*a.y-b.y*a.x;
    out.x=cx; out.y=cy; out.z=cz; out.w=0.0f;
    float aw=a.w;
    out.x+=aw*b.x; out.y+=aw*b.y; out.z+=aw*b.z; out.w+=aw*b.w;
    float bw=b.w;
    out.x-=bw*a.x; out.y-=bw*a.y; out.z-=bw*a.z; out.w-=bw*a.w;
    out.x=(float)(out.x+out.x); out.y=(float)(out.y+out.y);
    out.z=(float)(out.z+out.z); out.w=(float)(out.w+out.w);
    float dot=(float)(b.x*a.x+b.y*a.y+b.z*a.z+b.w*a.w);
    if(dot<0.0f) {out.x=-out.x;out.y=-out.y;out.z=-out.z;out.w=-out.w;}
}
// pdb: hkpPoweredChainData::buildJacobian | hkpPoweredChainData.obj | fnv360_0822_retail, objrun + bridge(caller_sim|vtable) + skyrim(caller_sim), high
void PoweredChain::hkpPoweredChainData_buildJacobian(const QueryInput& rawInput, QueryOutput& output)
{
    const F3QueryInput& input=reinterpret_cast<const F3QueryInput&>(rawInput);
    char* eventRuntime = input.runtime;
    AppendEventRecord(&rawInput, &output, eventRuntime, 8);
    F3QueryInput query = input;
    query.chain = 0;
    query.runtime = 0;
    ArrayF3<int, 32> offsets;
    ChainF3* chain = input.chain;
    EntityF3* master = chain->master;
    int baseOffset = input.offsetA - master->unk90;
    int entityCount = chain->entityCount;
    int count = entityCount - 1;
    ArrayF3<ChainMatrix, 32> matrices;
    matrices.SetSizeAndGrow(count);
    EntityF3* first = chain->entities[0];
    query.offsetB = first->unk90 + baseOffset;
    offsets.pushBackUnchecked(query.offsetB - baseOffset);
    F3ChainTransform* firstTransform = &first->transform;
    query.transformB = firstTransform;
    query.virtualMass = query.unk08;
    query.rhsFactor = 1.0f;
    char* jacobian;
    char* states = angularAndKeep(FUN_00a523f0(output.jacobian), output, count, jacobian);
    for (int i = 0; i < count; ++i)
    {
        query.offsetA = query.offsetB;
        query.transformA = query.transformB;
        EntityF3* next = chain->entities[i + 1];
        query.offsetB = next->unk90 + baseOffset;
        offsets.AddBack(query.offsetB - baseOffset);
        query.transformB = &next->transform;
        F3ChainQuaternion pivotA, pivotB;
        pivotA.setTransformedPos(*query.transformA, getF3Info(*this, i).pivotA);
        pivotB.setTransformedPos(*query.transformB, getF3Info(*this, i).pivotB);
        FUN_00a4e400(&query);
        FUN_00a4fe70(&pivotA, &pivotB, m_fMaximumAngularImpulse, &query, jacobian);
        jacobian += 0x90;
        F3ChainQuaternion rotationA, rotationB;
        rotationA.FUN_00924360(reinterpret_cast<hkRotation*>(&query.transformA->rotation));
        rotationB.FUN_00924360(reinterpret_cast<hkRotation*>(&query.transformB->rotation));
        if (getF3Info(*this, i).switched)
        {
            swapF3(rotationA, rotationB);
        }
        F3ChainQuaternion product;
        product.FUN_008d3290(&rotationB, &getF3Info(*this, i).targetB);
        rotationB=product;
        int n = m_pConstraintInfo.m_iElementCount;
        const F3ChainQuaternion& target = getF3Info(*this, i).target;
        F3ChainQuaternion* previous = reinterpret_cast<F3ChainQuaternion*>(input.runtime + ((n + 3) & ~3) + (3 * n + i) * 16);
        F3ChainQuaternion previousTarget;
        previousTarget=*previous;
        float squaredLength=previousTarget.x*previousTarget.x+previousTarget.y*previousTarget.y+previousTarget.z*previousTarget.z+previousTarget.w*previousTarget.w;
        if(squaredLength==0.0f) previousTarget=target;
        F3ChainQuaternion targetWorld, oldTargetWorld;
        targetWorld.FUN_008d3290(&rotationA, &target);
        oldTargetWorld.FUN_008d3290(&rotationA, &previousTarget);
        previous->x = target.x;
        previous->y = target.y;
        previous->z = target.z;
        previous->w = target.w;
        F3ChainQuaternion error, oldError;
        FUN_00a71350(rotationB, targetWorld, error);
        FUN_00a71350(rotationB, oldTargetWorld, oldError);
        error.x-=oldError.x; error.y-=oldError.y; error.z-=oldError.z; error.w-=oldError.w;
        if (getF3Info(*this, i).switched)
        {
            error.x=-error.x; error.y=-error.y; error.z=-error.z;
            oldError.x=-oldError.x; oldError.y=-oldError.y; oldError.z=-oldError.z;
        }
        F3ChainRotation axes;
        axes.hkRotation_set(&rotationB);
        for (int axis = 0; axis < 3; ++axis)
        {
            F3ChainQuaternion direction = axes.col[axis];
            MotorInput motorInput;
            char* solverResults = chain->runtime->solverResults;
            MotorState* __restrict motorStates = static_cast<MotorState*>(reinterpret_cast<F3MotorDispatch*>(this)->motorStep(solverResults));
            motorInput.state.unk00 = 0.0f;
            motorInput.state.unk04 = 0.0f;
            FUN_009f9580(&direction, &query, states, &motorInput.currentVelocity);
            motorInput.positionError = reinterpret_cast<float*>(&error)[axis];
            motorInput.deltaTarget = reinterpret_cast<float*>(&oldError)[axis];
            motorInput.step = &query;
            motorInput.state = motorStates[i * 6 + axis + 3];
            MotorOutput motorOutput;
            FUN_00a50540(getF3Info(*this, i).motors[axis], &motorInput, &motorOutput);
            float* dst = matrices[i].values + axis * 5;
            dst[0] = motorOutput.c * query.unk04;
            dst[1] = motorOutput.d * query.unk04;
            dst[2] = motorOutput.b;
            dst[3] = motorOutput.e;
            dst[4] = motorOutput.f;
            reinterpret_cast<float*>(states)[7] = motorOutput.a * query.unk08;
            states += 0x20;
        }
    }
    char* status = chain->runtime->solverResults + m_pConstraintInfo.m_iElementCount * 0x30;
    for (int i = 0; i < count; ++i)
        matrices[i].status = status[i];
    {
        BuildInfo build;
        build.count = count;
        build.tau = m_fTau;
        build.damping = m_fMotorDamping;
        build.linAdd = m_fMaximumErrorDistance;
        build.linMul = m_fMaximumLinearImpulse;
        build.angAdd = m_fBreachImpulse;
        build.angMul = m_fInertiaStabilizationFactor;
        build.offsets = offsets.data;
        build.offset = baseOffset;
        build.matrices = matrices.data;
        build.zero = 0.0f;
        build.states = status;
        build.jacobian = states;
        WriteInputHeader(&build, &rawInput, &output);
    }
    matrices.clear();
    offsets.clear();
}

