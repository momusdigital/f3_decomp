#include <windows.h>
#include <math.h>
// src/f3staging/f3blk_00900000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00900260 (community match, verified in this file)
namespace f3m_00900260 {
namespace f3m_00900260 {
struct Matrix;
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void hkVector4_setTransformedPos(const Matrix& m, const Vec4& v);
};
struct __declspec(align(16)) Matrix { float m[16]; };
struct Bounds { Vec4 min; Vec4 max; };
struct Shape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(const Matrix& m, float scale, Bounds* out);
};
struct ShapePtr { Shape* p; Shape* Get() { return p; } };
struct Holder { int unk00; int unk04; int unk08; int unk0c; ShapePtr shape; };
struct Object {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void vec(Matrix* m);
    int unk04;
    Holder* holder;
    Shape* GetShape() {
        Holder* h = holder;
        ShapePtr* r = h ? &h->shape : 0;
        return r ? r->Get() : 0;
    }
    void FUN_00900260(Bounds* out);
};
void Object::FUN_00900260(Bounds* out)
{
    Matrix m;
    vec(&m);
    Shape* s = GetShape();
    if (s) {
        s->v1c(m, 0.001f, out);
        return;
    }
    Vec4 a(-0.001f, -0.001f, -0.001f, 0.0f);
    Vec4 b(0.001f, 0.001f, 0.001f, 0.0f);
    out->min.hkVector4_setTransformedPos(m, a);
    out->max.hkVector4_setTransformedPos(m, b);
}
}
}   // namespace f3m_00900260

// @f3 0x0090a3a0 (community match, verified in this file)
namespace f3m_0090a3a0 {
namespace gizmo90a3a0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void FUN_008d2b00(void* matrix, const Vec4* source);
};
struct AxisRenderer {
    void FUN_009095d0(const Vec4* start, const Vec4* delta, unsigned int color, int mode);
    void FUN_0090a3a0(void* matrix, float scale, int mode);
};
void AxisRenderer::FUN_0090a3a0(void* matrix, float scale, int mode)
{
    Vec4 input;
    Vec4 origin;
    Vec4 xAxis;
    Vec4 yAxis;
    Vec4 zAxis;
    Vec4 xDelta;
    Vec4 yDelta;
    Vec4 zDelta;
    input.w = 0.0f;
    input.z = 0.0f;
    input.y = 0.0f;
    input.x = 0.0f;
    origin.FUN_008d2b00(matrix, &input);

    input.x = scale;
    input.y = 0.0f;
    input.z = 0.0f;
    input.w = 0.0f;
    xAxis.FUN_008d2b00(matrix, &input);

    input.x = 0.0f;
    input.y = scale;
    input.z = 0.0f;
    input.w = 0.0f;
    yAxis.FUN_008d2b00(matrix, &input);

    input.x = 0.0f;
    input.y = 0.0f;
    input.z = scale;
    input.w = 0.0f;
    zAxis.FUN_008d2b00(matrix, &input);

    xDelta.x = xAxis.x - origin.x;
    xDelta.y = xAxis.y - origin.y;
    xDelta.z = xAxis.z - origin.z;
    xDelta.w = xAxis.w - origin.w;
    yDelta.x = yAxis.x - origin.x;
    yDelta.y = yAxis.y - origin.y;
    yDelta.z = yAxis.z - origin.z;
    yDelta.w = yAxis.w - origin.w;
    zDelta.x = zAxis.x - origin.x;
    zDelta.y = zAxis.y - origin.y;
    zDelta.z = zAxis.z - origin.z;
    zDelta.w = zAxis.w - origin.w;

    FUN_009095d0(&origin, &xDelta, 0xffff0000u, mode);
    FUN_009095d0(&origin, &yDelta, 0xff008000u, mode);
    FUN_009095d0(&origin, &zDelta, 0xff0000ffu, mode);
}
}
}   // namespace f3m_0090a3a0

// @f3 0x00904ea0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
namespace Port904ea0 {
struct WorldCtor;
struct ObjectCtor;
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    inline void setSub4(const Vec4& a,const Vec4& b) { x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w; }
    inline void setMul4(double s,const Vec4& a) { x=s*a.x;y=s*a.y;z=s*a.z;w=s*a.w; }
    inline void setAdd4(const Vec4& a,const Vec4& b) { x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w; }
    inline void setNeg4(const Vec4& a) { x=-a.x;y=-a.y;z=-a.z;w=-a.w; }
    inline Vec4& operator=(const Vec4& b) { x=b.x;y=b.y;z=b.z;w=b.w;return *this; }
};
struct __declspec(align(16)) AlignedVec4 : Vec4 {};
struct ThreadCheck { unsigned id; unsigned short marked; unsigned short unk06; void hkMultiThreadCheck_disableChecks(); };
struct ObjectVtableCtor {
    void (__thiscall* vf00)(ObjectCtor*,int);
    void (__thiscall* vf04)(ObjectCtor*);
    void (__thiscall* vf08)(ObjectCtor*);
    void (__thiscall* vf0c)(ObjectCtor*,WorldCtor*);
    void (__thiscall* vf10)(ObjectCtor*);
    void (__thiscall* vf14)(ObjectCtor*);
    void (__thiscall* vf18)(ObjectCtor*);
    void (__thiscall* vf1c)(ObjectCtor*);
    void (__thiscall* vf20)(ObjectCtor*);
    void (__thiscall* vf24)(ObjectCtor*);
    void (__thiscall* vf28)(ObjectCtor*);
    void (__thiscall* vf2c)(ObjectCtor*);
    void (__thiscall* vf30)(ObjectCtor*);
    void (__thiscall* vf34)(ObjectCtor*);
    void (__thiscall* vf38)(ObjectCtor*);
    void (__thiscall* vf3c)(ObjectCtor*);
    void (__thiscall* vf40)(ObjectCtor*);
    void (__thiscall* vf44)(ObjectCtor*);
    void (__thiscall* vf48)(ObjectCtor*);
    void (__thiscall* vf4c)(ObjectCtor*);
    void (__thiscall* vf50)(ObjectCtor*);
    void (__thiscall* vf54)(ObjectCtor*);
    void (__thiscall* vf58)(ObjectCtor*);
    void (__thiscall* vf5c)(ObjectCtor*);
    void (__thiscall* vf60)(ObjectCtor*);
    void (__thiscall* vf64)(ObjectCtor*);
    void (__thiscall* vf68)(ObjectCtor*,Vec4*,Vec4*,Vec4*);
};
union WordCtor { int i; float f; ObjectCtor* p; void* raw; };
struct ObjectCtor {
    ObjectVtableCtor* vtable;
    unsigned short size;
    short references;
    WordCtor unk08;
    WordCtor unk0c;
    WordCtor unk10;
    WordCtor unk14;
    WordCtor unk18;
    WordCtor unk1c;
    union { WordCtor unk20; struct { unsigned short id20,id22; }; } ;
    union { WordCtor unk24; struct { unsigned short id24; unsigned char flags26,flags27; }; } ;
    WordCtor unk28;
    WordCtor unk2c;
    WordCtor unk30;
    WordCtor unk34;
    WordCtor unk38;
    WordCtor unk3c;
    WordCtor unk40;
    WordCtor unk44;
    WordCtor unk48;
    WordCtor unk4c;
    WordCtor unk50;
    WordCtor unk54;
    WordCtor unk58;
    WordCtor unk5c;
    WordCtor unk60;
    WordCtor unk64;
    WordCtor unk68;
    WordCtor unk6c;

    ObjectCtor* FUN_00983540(WorldCtor*);
    ObjectCtor* FUN_00984b50();
    ObjectCtor* FUN_009905d0(WorldCtor*);
    ObjectCtor* FUN_009874c0(WorldCtor*);
    ObjectCtor* FUN_00985fe0(void*,ObjectCtor*);
    ObjectCtor* FUN_00943410();
    ObjectCtor* FUN_00982160(WorldCtor*);
    ObjectCtor* FUN_0098d900(WorldCtor*);
    ObjectCtor* FUN_0097f1c0(WorldCtor*);
    ObjectCtor* FUN_0098b4c0(WorldCtor*);
    ObjectCtor* FUN_0090cff0(void*);
    ObjectCtor* FUN_0098bd20(WorldCtor*,int);
    ObjectCtor* FUN_0098b900();
    void FUN_009316f0();
    void FUN_00985630(void*);
    inline void addReference() { if(size) ++references; }
    inline void removeReference() {
        if(size) { --references; if(references==0) vtable->vf00(this,1); }
    }

};
extern DWORD DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(DWORD);
extern BOOL (__stdcall* DAT_00d9b1ac)(LPCRITICAL_SECTION,DWORD);
struct ThreadMemory {
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
    ObjectCtor* pool38;
    int unk03c;
    ObjectCtor* pool40;
    int unk044;
    ObjectCtor* pool48;
    int unk04c;
    ObjectCtor* pool50;
    int unk054;
    ObjectCtor* pool58;
    int unk05c;
    ObjectCtor* pool60;
    int unk064;
    ObjectCtor* pool68;
    int unk06c;
    ObjectCtor* pool70;
    int unk074;
    ObjectCtor* pool78;
    int unk07c;
    ObjectCtor* pool80;
    int unk084;
    ObjectCtor* pool88;
    int unk08c;
    ObjectCtor* pool90;
    int unk094;
    void* FUN_008f6800(int,int);
    void* FUN_008f6d30(int,int);
};

template<int N,int C> inline void* poolAlloc() {
    ThreadMemory* m=(ThreadMemory*)DAT_00d9b080(DAT_010f3170);
    struct Block { Block* next; };
    Block** head=(Block**)((char*)m+0x38+8*N);
    Block* p=*head;
    void* result;
    if(p) { --*(int*)(head+1); *head=p->next; result=p; } else result=m->FUN_008f6800(N,C);
    return result;
}
struct FreeElemCtor { FreeElemCtor* next; };
struct FreeListCtor { FreeElemCtor* head; int count; };
template<class T,int C> inline T* allocObject(int size) {
    ThreadMemory* m=(ThreadMemory*)DAT_00d9b080(DAT_010f3170);
    T* obj=(T*)m->FUN_008f6d30(size,C);
    obj->size=(unsigned short)size;
    return obj;
}
inline void release(ObjectCtor* p) { p->removeReference(); }
struct RawArrayCtor;
extern void __cdecl FUN_00901f10(RawArrayCtor*,int);
struct RawArrayCtor {
    ObjectCtor** data; int count; unsigned capacity;
    inline void push(ObjectCtor* value) {
        if(count==(capacity&0x3fffffffu)) FUN_00901f10(this,4);
        data[count]=value;
        ++count;
    }
};
inline void initArray(RawArrayCtor& a) { a.data=0; a.count=0; a.capacity=0x80000000u; }
struct Half {
    short bits;
    inline Half& operator=(float f) { bits=(short)(*(int*)&f>>16);return *this; }
    inline operator float() const { int value=int(bits)<<16;return *(float*)&value; }
};
struct RangeCtor { float start,end,delta,inverse; };
inline void setRange(RangeCtor& r,double a,double b) {
    r.start=a; r.end=b; float d=b-a; r.delta=d; r.inverse=d==0.0f ? 0.0f : 1.0f/d;
}
struct DeactivationCtor { float inverseThreshold,inverseVelocity,damping,time,distanceSquared,radiusSquared; Half distanceHalf,radiusHalf; };
struct SolverCtor {
    float unk00;
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
    float unk60;
    DeactivationCtor tiers[6];
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    float unk11c;
    float unk120;
    unsigned char unk124;
    unsigned char unk125;
    unsigned char unk126;
    unsigned char unk127;
    int unk128;
    int unk12c;
    void FUN_00902100(float,float);
    __forceinline DeactivationCtor& configureTier(int,float,float,float,float);
};
struct ManifoldCtor { float tolerance; int count; static void* operator new(unsigned int) { return poolAlloc<2,0x1f>(); } ManifoldCtor() : tolerance(0.01f), count(20) {} };
struct JobsCtor { int unk00; static void* operator new(unsigned int) { return poolAlloc<3,0x2f>(); } JobsCtor() {} };
struct CollisionInputCtor {
    ObjectCtor* dispatcher;
    float tolerance;
    void* filter;
    ObjectCtor* convexFilter;
    int unk10;
    int unk014;
    int unk018;
    int unk01c;
    Vec4 offset;
    Vec4 extent;
    Vec4 scale;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    void* agents;
    RangeCtor* time;
    unsigned char flag68;
    unsigned char unk069;
    short unk06a;
    ManifoldCtor* manifold;

};
struct WorldInfoCtor {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    Vec4 gravity;
    int querySize;
    float solverFriction;
    signed char borderBehavior;
    unsigned char unk029;
    short unk02a;
    int unk02c;
    Vec4 minimum;
    Vec4 maximum;
    float tolerance;
    ObjectCtor* filter;
    ObjectCtor* convexFilter;
    float config60;
    int toiQueueSize;
    float config68;
    ObjectCtor* watchdog;
    int markers;
    signed char generation;
    unsigned char unk071;
    short unk072;
    float solverTau;
    float solverDamping;
    int iterations;
    int microsteps;
    unsigned char flag8c;
    unsigned char unk085;
    short unk086;
    float snap;
    float snapOther;
    unsigned char weld;
    unsigned char flag99;
    short unk092;
    float manifoldTolerance;
    int manifoldCount;
    int unk09c;
    int unk0a0;
    unsigned char flagA4;
    unsigned char flagA5;
    unsigned char flagA6;
    unsigned char activate;
    float referenceDistance;
    float rotateNormal;
    int toiEntries;
    unsigned char threadToi;
    unsigned char unk0b5;
    short unk0b6;
    int toiPairs;
    unsigned char deactivate;
    signed char simulationType;
    unsigned char wantIslands;
    unsigned char unk0bf;
    int minIsland;
    unsigned char singleActions;
    unsigned char unk0c5;
    short unk0c6;
    float simulationValue;

};
struct WorldCtor {
    void* vtable;
    unsigned short size;
    short references;
    ObjectCtor* simulation;
    int unk00c;
    Vec4 gravity;
    ObjectCtor* fixedIsland;
    ObjectCtor* fixedBody;
    RawArrayCtor active;
    RawArrayCtor inactive;
    RawArrayCtor dirty;
    ObjectCtor* kdTree;
    ObjectCtor* watchdog;
    ObjectCtor* broadphase;
    ObjectCtor* broadphaseDispatcher;
    ObjectCtor* phantomListener;
    ObjectCtor* entityListener;
    ObjectCtor* borderListener;
    ObjectCtor* jobs;
    CollisionInputCtor* input;
    ObjectCtor* filter;
    ObjectCtor* dispatcher;
    ObjectCtor* convexFilter;
    ObjectCtor* pending;
    int pendingCount;
    int bodyCount;
    int criticalCount;
    unsigned char blockOperations;
    unsigned char allowOperations;
    short unk08e;
    int pendingQueues;
    int queueCount;
    ThreadCheck threadCheck;
    unsigned char singleActions;
    unsigned char unk0a1;
    short unk0a2;
    int minIsland;
    ObjectCtor* modifyLock;
    ObjectCtor* dirtyLock;
    ObjectCtor* extraLock;
    ObjectCtor* propertyLock;
    unsigned char wantIslands;
    unsigned char unk0b9;
    short unk0ba;
    float snapConvex;
    float snapConcave;
    unsigned char weld;
    unsigned char deactivate;
    unsigned char activate;
    unsigned char unk0c7;
    float referenceDistance;
    float rotateNormal;
    unsigned char threadToi;
    unsigned char unk0d1;
    short unk0d2;
    int toiEntries;
    int toiPairs;
    int simulationType;
    int lastConstraint;
    RawArrayCtor phantoms;
    RawArrayCtor actions;
    RawArrayCtor entities;
    RawArrayCtor phantomCallbacks;
    RawArrayCtor constraints;
    RawArrayCtor deletionCallbacks;
    RawArrayCtor islandCallbacks;
    RawArrayCtor postSimulation;
    RawArrayCtor postIntegrate;
    RawArrayCtor postCollide;
    RawArrayCtor islandIntegrate;
    RawArrayCtor islandCollide;
    RawArrayCtor contacts;
    RawArrayCtor impulseLimits;
    ObjectCtor* broadphaseBorder;
    RangeCtor time;
    SolverCtor solver;
    Vec4 minimum;
    Vec4 maximum;
    int markers;
    int toiQueueSize;
    int querySize;
    int updateSize;
    unsigned char generation;
    unsigned char unk301;
    short unk302;
    WorldCtor* FUN_00904ea0(WorldInfoCtor*,int);
    void FUN_009027a0(ObjectCtor*,int);
};

struct StreamCtor {
    int unk00,unk04,unk08;
    StreamCtor* FUN_00923070(char*,int);
    StreamCtor* FUN_00943710(const char*);
    StreamCtor* FUN_009437d0(int);
    StreamCtor* FUN_00943820(int);
    void FUN_00943a60();
};
struct ErrorCtor {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual int report(int,unsigned,const char*,const char*,int);
};
extern ErrorCtor* DAT_010f3364;
extern unsigned char DAT_010f3230;
extern void FUN_00990690(float,float);
extern void* FUN_00990580();
extern void __cdecl hkWorld_setupContactMgrFactories(WorldCtor*,ObjectCtor*);
extern ObjectCtor* (__cdecl* DAT_01060de0)(Vec4*,Vec4*,int);
extern const char DAT_00e34e6c[], DAT_00e34e90[], DAT_00e34eb0[], DAT_00e34e54[];
extern int DAT_00e34e10;
extern int DAT_00e34ac8;
extern int DAT_00e34ae8;
extern int DAT_00e34ad8;
extern int DAT_00e34b08;
extern int DAT_00e34af8;
extern int DAT_00e34b64;
extern int DAT_00e34b58;
extern int DAT_00e34b44;
extern int DAT_00e34b38;
extern int DAT_00e34b2c;
extern int DAT_00e34b74;
extern const float DAT_00e32888;
struct __declspec(align(16)) BodyInfoCtor {
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
    float unk90;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    unsigned char motionType;
    unsigned char unk0b1;
    short unk0b2;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    void FUN_0097e690();
};

extern const float DAT_00e34e38;
struct __declspec(align(16)) BuildConfigCtor {
    float magnitude,tolerance,config68,config60;
    unsigned short one,three,four,five;
    unsigned char multithread,quality,contacts,weld;
};
inline float length3(const Vec4& v) { float square=v.x*v.x+v.y*v.y+v.z*v.z; return sqrtf(square); }
struct LockCtor {
    CRITICAL_SECTION section;
    int index18,index1c,spinCount;
    LockCtor *next,*prev;
    void FUN_00908a00();
    __forceinline LockCtor* construct(int spin);
};
extern LockCtor DAT_011692e8;
extern LockCtor* DAT_01169310;
extern int DAT_01169300,DAT_01169304;
__forceinline LockCtor* LockCtor::construct(int spin) {
    spinCount=spin;next=0;prev=0;
    DAT_011692e8.FUN_00908a00();
    prev=DAT_01169310;
    if(DAT_01169310) DAT_01169310->next=this;
    next=&DAT_011692e8;
    DAT_01169310=this;
    DAT_01169300=-1;DAT_01169304=-1;
    ::LeaveCriticalSection(&DAT_011692e8.section);
    DAT_00d9b1ac(&section,spin);
    index18=-1;index1c=-1;
    return this;
}
__forceinline DeactivationCtor& SolverCtor::configureTier(int tierIndex,float threshold,float speed,float magnitude,float gravityScale) {
    struct Quotient { double denominator; float threshold; inline float value() const {return denominator/threshold;} };
    Quotient quotient; quotient.denominator=speed*magnitude; quotient.threshold=threshold;
    float ratio=quotient.value();
    DeactivationCtor& tier=tiers[tierIndex];
    tier.damping=1.0f-(unk120*0.01600000075995922)*ratio;
    tier.inverseThreshold=1.0f/threshold;
    tier.inverseVelocity=1.0f/(threshold*gravityScale);
    return tier;
}

__forceinline ObjectCtor* newLock(int spin) {
    LockCtor* home=(LockCtor*)poolAlloc<4,0x15>();
    LockCtor* p;
    if(home) {
        // Fake match: 'p' is reassigned from 'home' after each call so the lock pointer is reloaded from its slot.
        p=home;
        p->spinCount=spin; p->next=0;p->prev=0;
        DAT_011692e8.FUN_00908a00();
        p=home;p->prev=DAT_01169310;
        LockCtor* previous=p->prev;
        if(previous) previous->next=home;
        p=home;p->next=&DAT_011692e8;DAT_01169310=p;
        DAT_01169300=-1;DAT_01169304=-1;
        ::LeaveCriticalSection(&DAT_011692e8.section);
        DAT_00d9b1ac(&home->section,spin);
        p=home;p->index18=-1;p->index1c=-1;
    } else p=0;
    return (ObjectCtor*)p;
}

__forceinline ManifoldCtor* makeManifold(ManifoldCtor* memory) {
    ManifoldCtor* result=0;
    if(memory) {memory->tolerance=0.01f;memory->count=20;result=memory;}
    return result;
}
// pdb: hkpWorld::hkpWorld | hkpWorld.obj | fnv360_0822_retail, ustr, high
// pdb params: info, sdkversion
WorldCtor* WorldCtor::FUN_00904ea0(WorldInfoCtor* info,int version) {
    references=1;
    vtable=&DAT_00e34e10;
    initArray(active); initArray(inactive); initArray(dirty);
    threadCheck.id=0xffffffd1;
    threadCheck.marked=0;
    initArray(phantoms); initArray(actions); initArray(entities);
    initArray(phantomCallbacks); initArray(constraints); initArray(deletionCallbacks);
    initArray(islandCallbacks); initArray(postSimulation); initArray(postIntegrate);
    initArray(postCollide); initArray(islandIntegrate); initArray(islandCollide);
    initArray(contacts); initArray(impulseLimits);
    lastConstraint=-1;
    ObjectCtor* object=(ObjectCtor*)poolAlloc<6,0x2f>();
    pending=object ? object->FUN_00983540(this) : 0;
    pendingQueues=0; pendingCount=0; bodyCount=0; criticalCount=0;
    blockOperations=0; allowOperations=1;
    modifyLock=0; propertyLock=0; dirtyLock=0; extraLock=0;
    queueCount=1;
    minimum=info->minimum;
    maximum=info->maximum;
    markers=info->markers;
    broadphase=DAT_01060de0(&minimum,&maximum,info->markers);
    int broadphaseQuerySize=info->querySize;
    querySize=broadphaseQuerySize;
    updateSize=broadphaseQuerySize/2;
    toiQueueSize=info->toiQueueSize;
    if(version!=0xc544) {
        char buffer[0x200];
        StreamCtor stream;
        stream.FUN_00923070((char*)buffer,sizeof(buffer));
        stream.FUN_00943710(DAT_00e34e6c)
              ->FUN_009437d0(0xc544)
              ->FUN_00943710(DAT_00e34e90)
              ->FUN_00943820(version)
              ->FUN_00943710(DAT_00e34eb0);
        DAT_010f3364->report(3,0x53c94b42,(char*)buffer,DAT_00e34e54,0xa50);
        stream.FUN_00943a60();
    }
    gravity=info->gravity;
    FUN_00990690(info->snap,info->snapOther);
    snapConvex=info->snap;
    snapConcave=info->snap;
    weld=info->weld;
    activate=info->activate;
    rotateNormal=info->rotateNormal;
    threadToi=info->threadToi;
    toiEntries=info->toiEntries;
    toiPairs=info->toiPairs;
    referenceDistance=info->referenceDistance;
    solver.unk00=1.0f;
    solver.FUN_00902100(info->solverTau,info->solverDamping);
    solver.unk60=info->solverFriction;
    solver.unk114=info->iterations;
    solver.unk120=1.0f/info->iterations;
    solver.unk118=info->microsteps;
    solver.unk11c=1.0f/info->microsteps;
    solver.unk124=info->flag8c;
    solver.unk125=info->flagA4;
    solver.unk126=info->flagA5;
    solver.unk127=info->flagA6;
    float magnitude=length3(info->gravity);
    if(magnitude==0.0f) magnitude=9.81f;
    float gravityScale=magnitude*double(0.1f);
    for(int tierIndex=0;tierIndex<6;++tierIndex) {
        float threshold; float speed;
        switch(tierIndex) {
        case 0: case 1: threshold=1.1920928955078125e-7f; speed=0.0f; break;
        case 2: threshold=0.01f; speed=0.08f; break;
        case 3: threshold=0.017f; speed=0.2f; break;
        case 4: threshold=0.02f; speed=0.3f; break;
        default: threshold=0.025f; speed=0.4f; break;
        }
        DeactivationCtor& tier=solver.configureTier(tierIndex,threshold*magnitude,speed,magnitude,gravityScale);
        tier.time=speed>0.0f ? solver.unk120*0.01600000075995922/speed : DAT_00e34e38;
        float distance=info->referenceDistance;
        tier.distanceSquared=distance;
        tier.radiusSquared=4.0*distance;
        tier.distanceHalf=2.0*distance;
        tier.radiusHalf=8.0*distance;
        tier.distanceSquared*=tier.distanceSquared;
        tier.radiusSquared*=tier.radiusSquared;
        tier.distanceHalf=float(tier.distanceHalf)*float(tier.distanceHalf);
        tier.radiusHalf=float(tier.distanceHalf)*float(tier.radiusHalf);
    }
    watchdog=info->watchdog;
    if(watchdog) watchdog->addReference();
    wantIslands=info->wantIslands;
    deactivate=info->deactivate;
    if(!wantIslands && deactivate) deactivate=wantIslands;
    singleActions=info->singleActions;
    object=(ObjectCtor*)poolAlloc<11,0x27>();
    broadphaseDispatcher=object ? object->FUN_00984b50() : 0;
    object=allocObject<ObjectCtor,4>(0xc);
    object->references=1;
    object->unk08.raw=&DAT_00e34ac8;
    // Fake match: the barrier keeps the base vtable store ahead of the derived one without a volatile store.
    _ReadWriteBarrier();
    object->vtable=(ObjectVtableCtor*)&DAT_00e34ae8;
    object->unk08.raw=&DAT_00e34ad8;
    phantomListener=object;
    object=allocObject<ObjectCtor,4>(0x10);
    entityListener=object->FUN_009905d0(this);
    object=allocObject<ObjectCtor,4>(0xc);
    object->references=1;
    object->unk08.raw=&DAT_00e34ac8;
    // Fake match: the barrier keeps the base vtable store ahead of the derived one without a volatile store.
    _ReadWriteBarrier();
    object->vtable=(ObjectVtableCtor*)&DAT_00e34b08;
    object->unk08.raw=&DAT_00e34af8;
    borderListener=object;
    broadphaseDispatcher->unk28.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk44.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk48.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk24.raw=entityListener ? &entityListener->unk08 : 0;
    broadphaseDispatcher->unk2c.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk64.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk4c.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk68.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk6c.raw=borderListener ? &borderListener->unk08 : 0;
    ObjectCtor* agent=allocObject<ObjectCtor,0x22>(0xc)->FUN_009874c0(this);
    dispatcher=allocObject<ObjectCtor,0x27>(0x1e50)->FUN_00985fe0((void*)&FUN_00990580,agent);
    release(agent);
    if(!info->filter) {
        object=allocObject<ObjectCtor,0x27>(0x30);
        ObjectCtor* filterHome=object;
        object->FUN_00943410();
        object=filterHome;
        object->vtable=(ObjectVtableCtor*)&DAT_00e34b64;
        object->unk08.raw=&DAT_00e34b58;
        object->unk0c.raw=&DAT_00e34b44;
        object->unk10.raw=&DAT_00e34b38;
        object->unk14.raw=&DAT_00e34b2c;
        object->unk20.i=1;
        filter=object;
    } else {
        filter=info->filter;
        filter->addReference();
    }
    if(!info->convexFilter) {
        object=allocObject<ObjectCtor,0x27>(8);
        object->references=1;
        object->vtable=(ObjectVtableCtor*)&DAT_00e34b74;
        convexFilter=object;
    } else {
        convexFilter=info->convexFilter;
        convexFilter->addReference();
    }
    // Fake match: the input pool allocation is written out here with two pointers. 'in' is the copy that lives
    // in the stack slot and is stored in each arm; 'reg' is a short register copy for the three stores after the
    // join, so those uses do not count for 'in' and it does not take the zero register.
    CollisionInputCtor* in; CollisionInputCtor* reg;
    {
    ThreadMemory* inputMemory=(ThreadMemory*)DAT_00d9b080(DAT_010f3170);
    FreeListCtor* inputList=(FreeListCtor*)&inputMemory->pool70;
    FreeElemCtor* p=inputList->head;
    if(p) { --inputList->count; inputList->head=p->next; in=(CollisionInputCtor*)p; reg=(CollisionInputCtor*)p;
        // Fake match: redundant branch (assigns the value reg already has). It keeps the thread-memory pointer
        // alive past the two copies, so 'reg' stays in the popped block's register and is not moved.
        if(inputMemory==0) reg=(CollisionInputCtor*)p; } else { in=(CollisionInputCtor*)inputMemory->FUN_008f6800(7,0x1f); reg=in; }
    }
    input=reg;
    reg->dispatcher=dispatcher;
    reg->tolerance=info->tolerance;
    // The base adjust is kept on one variable (assign, then test and adjust) so it is done in place.
    ObjectCtor* shapeFilter=filter;
    shapeFilter=shapeFilter ? (ObjectCtor*)&shapeFilter->unk0c : 0;
    in->filter=shapeFilter;
    in->convexFilter=convexFilter;
    in->manifold=new ManifoldCtor();
    generation=info->generation;
    in->manifold->tolerance=info->manifoldTolerance;
    in->manifold->count=info->manifoldCount;
    in->flag68=info->flag99!=0;
    in->unk10=0;
    in->agents=(char*)in->dispatcher+0x1c60;
    {
    Vec4 extent;
    extent.setSub4(info->maximum,info->minimum);
    Vec4 reciprocal;
    reciprocal.x=1.0f/extent.x;reciprocal.y=1.0f/extent.y;reciprocal.z=1.0f/extent.z;reciprocal.w=0.0f;
    in->scale.setMul4(2147352576.0,reciprocal);
    in->offset.setNeg4(info->minimum);
    Vec4 scaled;
    scaled.setMul4(4.656897090171697e-10,extent);
    in->extent.setAdd4(scaled,in->offset);
    in->scale.w=0.0f; in->offset.w=0.0f; in->extent.w=0.0f;
    broadphase->vtable->vf68(broadphase,&in->offset,&in->extent,&in->scale);
    }
    hkWorld_setupContactMgrFactories(this,dispatcher);
    if(DAT_010f3230) info->simulationType=3;
    minIsland=0;
    simulationType=info->simulationType;
    switch(simulationType) {
    case 3:
        modifyLock=newLock(4000);
        propertyLock=newLock(4000);
        simulation=allocObject<ObjectCtor,0x15>(0x400)->FUN_00982160(this);
        minIsland=info->minIsland;
        break;
    case 2: simulation=allocObject<ObjectCtor,0x15>(0x50)->FUN_0098d900(this); break;
    case 1: simulation=allocObject<ObjectCtor,0x15>(0x2c)->FUN_0097f1c0(this); break;
    }
    dirtyLock=newLock(4000);
    extraLock=newLock(4000);
    simulation->unk24.f=info->simulationValue;
    float secondMagnitude=length3(gravity);
    if(secondMagnitude==0.0f) secondMagnitude=9.81f;
    {
    BuildConfigCtor config;
    config.magnitude=secondMagnitude;
    config.tolerance=input->tolerance;
    config.config68=info->config68;
    config.config60=info->config60;
    config.multithread=info->simulationType>=2;
    config.quality=info->generation==2;
    config.contacts=info->generation>=1;
    config.one=1;config.three=2;config.four=3;config.five=4;
    config.weld=info->weld;
    dispatcher->FUN_00985630(&config);
    }
    input->agents=(char*)dispatcher+0x1c60;
    fixedIsland=allocObject<ObjectCtor,0x32>(0x6c)->FUN_0098b4c0(this);
    fixedIsland->id20=0xffff;
    fixedIsland->flags26 &= 0xf3;
    fixedIsland->flags26 &= 0xfc;
    if(!wantIslands) {
        ObjectCtor* island=allocObject<ObjectCtor,0x32>(0x6c)->FUN_0098b4c0(this);
        active.push(island);
        island->id20=0;
    }
    BodyInfoCtor body;
    body.FUN_0097e690();
    body.unk90=0.0f;
    body.motionType=7;
    fixedBody=allocObject<ObjectCtor,0x2d>(0x200)->FUN_0090cff0(&body);
    FUN_009027a0(fixedBody,1);
    fixedBody->FUN_009316f0();
    setRange(time,0.0f,0.01666666753590107);
    input->time=&time;
    if(info->borderBehavior!=3) {
        ObjectCtor* pendingBorder=allocObject<ObjectCtor,0xd>(0x30);
        int behavior=info->borderBehavior;
        broadphaseBorder=pendingBorder->FUN_0098bd20(this,behavior);
    } else broadphaseBorder=0;
    kdTree=allocObject<ObjectCtor,0x15>(0x10)->FUN_0098b900();
    kdTree->vtable->vf0c(kdTree,this);
    if(info->simulationType!=3) threadCheck.hkMultiThreadCheck_disableChecks();
    jobs=(ObjectCtor*)new JobsCtor();
    return this;
}
}

// @f3 0x00916540 (community match, verified in this file)
namespace f3m_00916540 {
namespace box916540 {
// x87 (FPU build) four-float vector, 16-byte aligned.
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    inline Vector4() {}
    inline Vector4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    inline void setMul4(const Vector4& a, const Vector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
};
struct Sphere {
    Vector4 pos; // xyz position, w radius
    inline void setPositionAndRadius(const Vector4& v) { pos.x = v.x; pos.y = v.y; pos.z = v.z; pos.w = v.w; }
};
struct BoxShape {
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    unsigned int userData;
    int type;
    float radius;
    Vector4 halfExtents;
    const Sphere* FUN_00916540(Sphere* sphereBuffer) const;
};
// Writes the eight corner spheres of the box: every sign combination of the half extents, each with the
// shape's convex radius in w.
const Sphere* BoxShape::FUN_00916540(Sphere* sphereBuffer) const
{
    Vector4 extents = halfExtents;
    extents.w = radius;
    Vector4 v0;
    Vector4 v1;
    Sphere* s = sphereBuffer;
    {
        v0.setMul4(Vector4(1.0f, 1.0f, 1.0f, 1.0f), extents);
        v1.setMul4(Vector4(1.0f, 1.0f, -1.0f, 1.0f), extents);
        s[0].setPositionAndRadius(v0);
        s[1].setPositionAndRadius(v1);
    }
    {
        v0.setMul4(Vector4(1.0f, -1.0f, 1.0f, 1.0f), extents);
        v1.setMul4(Vector4(1.0f, -1.0f, -1.0f, 1.0f), extents);
        s[2].setPositionAndRadius(v0);
        s[3].setPositionAndRadius(v1);
    }
    {
        v0.setMul4(Vector4(-1.0f, 1.0f, 1.0f, 1.0f), extents);
        v1.setMul4(Vector4(-1.0f, 1.0f, -1.0f, 1.0f), extents);
        s[4].setPositionAndRadius(v0);
        s[5].setPositionAndRadius(v1);
    }
    {
        v0.setMul4(Vector4(-1.0f, -1.0f, 1.0f, 1.0f), extents);
        v1.setMul4(Vector4(-1.0f, -1.0f, -1.0f, 1.0f), extents);
        s[6].setPositionAndRadius(v0);
        s[7].setPositionAndRadius(v1);
    }
    return sphereBuffer;
}
}
}   // namespace f3m_00916540
