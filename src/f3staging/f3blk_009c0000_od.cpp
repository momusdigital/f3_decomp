// src/f3staging/f3blk_009c0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009de740 (community match, verified in this file)
extern int g_tab[];
namespace f3m_009de740 {
struct __declspec(align(16)) V4 { float x, y, z, w; };
struct Out { V4 a, b, c; };
struct Stream { char pad[0xb8]; int numDecoded; };
extern "C" void FUN_00a4e410(Out* o, int a4, int a5);
static inline void cp(V4& d, const V4& s) { d.x = s.x; d.y = s.y; d.z = s.z; d.w = s.w; }
// pdb: hkpGenericConstraintData::constrainToAngularW | hkpGenericConstraintData.obj | tesv_win, objrun, medium
void __stdcall FUN_009de740(unsigned int** a0, int u1, int u2, V4* apStream, int a4, int a5)
{
    Out out;
    ++*a0;
    unsigned int idx = **a0;
    cp(out.b, apStream[g_tab[idx] + 5]);
    cp(out.a, apStream[g_tab[idx+1] + 5]);
    cp(out.c, apStream[idx + 8]);
    FUN_00a4e410(&out, a4, a5);
    V4 t; t.x = -out.b.x; t.y = -out.b.y; t.z = -out.b.z; t.w = -out.b.w;
    cp(out.b, out.a);
    cp(out.a, t);
    FUN_00a4e410(&out, a4, a5);
    ((Stream*)apStream)->numDecoded += 2;
}
}   // namespace f3m_009de740

// @f3 0x009d29b0 (community match, verified in this file)
namespace f3m_009d29b0 {
struct __declspec(align(16)) Vec_x { float x,y,z,w;
    __forceinline void setAdd(const Vec_x& a,float bx,float by,float bz,float bw) {
        x=bx+a.x; y=by+a.y; z=bz+a.z; w=bw+a.w;
    }
};
struct Transform_x { Vec_x c0,c1,c2,pos; };
struct Motion_x {
    Transform_x transform;
    Vec_x center0,center1,rotation0,rotation1,deltaAngle;
    float radius,linearDamping,angularDamping,timeFactor;
    float maxLinear,maxAngular,deactivation,unused;
    Motion_x(const Motion_x&);
};
struct Shape_x { void* vtable; unsigned short size,flags; int user; int type; };
struct __declspec(align(16)) Sphere_x : Shape_x { float radius; Sphere_x(float); };
struct Multi_x : Shape_x { int count; Vec_x spheres[8]; };
struct Body_x { Shape_x* shape; unsigned key; const Motion_x* motion; const Body_x* parent;
    Body_x(const Body_x* p,const Motion_x* m) { parent=p; motion=m; }
};
struct Collector_x { void* vtable; unsigned char earlyOut; };
struct Input_x;
typedef void (__cdecl *Penetrate_x)(const Body_x&,const Body_x&,const Input_x&,Collector_x&);
struct Entry_x { void* agent; Penetrate_x penetrate; void* closest; void* linear; void* flags; };
struct Dispatcher_x { unsigned char table[77][32]; Entry_x entries[256];
    __forceinline Penetrate_x get(int a,int b) const { return entries[table[a+13][b]].penetrate; }
};
struct Input_x { Dispatcher_x* dispatcher; };
// pdb: hkpMultiSphereAgent::staticGetPenetrations | hkpMultiSphereAgent.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void hkpMultiSphereAgent_staticGetPenetrations(const Body_x& a,const Body_x& b,const Input_x* volatile input,Collector_x& collector)
{
    const Multi_x* multi=static_cast<const Multi_x*>(a.shape);
    Motion_x ms(*a.motion);
    Sphere_x sphere(0.0f);
    Body_x operand(&a,&ms);
    int typeB=b.shape->type;
    int i=0;
    if (multi->count<=0) return;
    const Input_x* ctx=input;
    Vec_x rotated;
    do {
        int typeA=sphere.type;
        const Vec_x& v=multi->spheres[i];
        float x=v.x,y=v.y,z=v.z;
        rotated.x=ms.transform.c1.x*y+ms.transform.c0.x*x+ms.transform.c2.x*z;
        rotated.y=ms.transform.c1.y*y+ms.transform.c0.y*x+ms.transform.c2.y*z;
        rotated.z=ms.transform.c1.z*y+ms.transform.c0.z*x+ms.transform.c2.z*z;
        rotated.w=0.0f;
        ms.transform.pos.setAdd(a.motion->transform.pos,rotated.x,rotated.y,rotated.z,rotated.w);
        sphere.radius=v.w;
        operand.shape=&sphere;
        operand.key=i;
        Penetrate_x fn=ctx->dispatcher->get(typeA,typeB);
        fn(operand,b,*ctx,collector);
        if(collector.earlyOut) break;
        i++;
    } while(i<multi->count);
}
}   // namespace f3m_009d29b0

// @f3 0x009d1840 (community match, verified in this file)
#include <intrin.h>
extern unsigned DAT_0116913c;
namespace f3m_009d1840 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace task2987 {
struct StringCursor {char* begin;char* m_cur;char* spare;char* m_kRayEnd;};
struct hkpShapeCollection;

struct hkpShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual hkpShapeCollection* GetShapeContainer();
    int m_unk04;
    int m_unk08;
    int m_type;
};

struct hkpShapeCollection
{
    virtual void v00();
    virtual void v04();
    virtual unsigned int GetFirstKey();
    virtual unsigned int GetNextShapeKey(unsigned int key);
    virtual void v10();
    virtual const hkpShape* GetShapeForKey(unsigned int key, void* buffer);
};

struct hkBool
{
    char m_cBooleanValue;
};

struct hkpCdBody;
struct CollisionAgentContext;

struct hkpShapeCollectionFilter
{
    virtual void v00();
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& bodyB,
                                      const hkpCdBody& bodyA, const hkpShapeCollection& containerShapeA,
                                      unsigned int key);
};

struct hkpCollisionFilter
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    hkpShapeCollectionFilter m_shapeCollectionFilter;
};

struct hkpCollisionDispatcher;

struct CollisionAgentContext
{
    hkpCollisionDispatcher* m_pCollisionDispatcher;
    int m_unk04;
    hkpShapeCollectionFilter* m_pCollisionFilter;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
};

typedef void(__cdecl* AgentFunc)(const hkpCdBody* local_body, const hkpCdBody* bodyB,
                                 const CollisionAgentContext* input, void* collector);

typedef void(__cdecl* LinearCastFunc)(const hkpCdBody*,const hkpCdBody*,const CollisionAgentContext*,void*,void*);
struct CollisionAgentFunctionTable
{
    AgentFunc m_staticGetClosestPoints;
    LinearCastFunc m_func1;
    AgentFunc m_func2;
    AgentFunc m_func3;
    AgentFunc m_func4;
};

struct hkpCollisionDispatcher
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    unsigned char m_agentTable[35][32];
    int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    int unk09a0, unk09a4;
    CollisionAgentFunctionTable m_agentFuncs[100];
};
__forceinline void hkTimerBegin(const char* tag)
{
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0116913c);
    char* cur = stream->m_cur;
    if (cur < stream->m_kRayEnd)
    {
        *(const char**)cur = tag;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)time;
        cur += 12;
        stream->m_cur = cur;
    }
}

__forceinline void hkTimerEnd()
{
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0116913c);
    char* cur = stream->m_cur;
    if (cur < stream->m_kRayEnd)
    {
        *(const char**)cur = "Et";
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)time;
        cur += 12;
        stream->m_cur = cur;
    }
}

// Iterates the shape collection's keys, filters each child shape, and dispatches the static get-closest-points agent for each accepted pair.
struct RootBody : hkpCdBody {unsigned u10,u14,u18,flags;};
struct __declspec(align(16)) hkpShapeBuffer {unsigned long m_data[128];};
// @fnv 0x00d43b90
// pdb: hkpShapeCollectionAgent::staticLinearCast | hkpShapeCollectionAgent.obj | fnv360_0822_retail, call_dedup, low
// pdb params: bodyA, bodyB, input, collector, startCollector
void __cdecl FUN_009d1840(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const CollisionAgentContext* input, void* a4,
                          void* a5)
{
    hkTimerBegin("TtShapeCollection");

    hkpShapeCollection* collection = const_cast<hkpShape*>(bodyA->m_pCollisionShape)->GetShapeContainer();
    hkpCdBody localBody;
    localBody.m_pMotionState = bodyA->m_pMotionState;
    localBody.m_parent = bodyA;

    int typeB = bodyB->m_pCollisionShape->m_type;
    unsigned int key = collection->GetFirstKey();
    if (key != -1)
    {
        do
        {
            if (input->m_pCollisionFilter->IsCollisionEnabled(*input, *bodyB, *bodyA, *collection, key)
                    .m_cBooleanValue)
            {
                hkpShapeBuffer buffer;
                const hkpShape* childShape = collection->GetShapeForKey(key, &buffer);
                localBody.m_pCollisionShape = childShape;
                localBody.m_uiCollisionShapeKey = key;

                int typeA = childShape->m_type;
                if(typeB==11){const hkpCdBody* root=bodyB;while(root->m_parent)root=root->m_parent;if(static_cast<const RootBody*>(root)->flags & 0x2000)typeB=9;}
                unsigned char agentType = input->m_pCollisionDispatcher->m_agentTable[typeA][typeB];
                LinearCastFunc func = (LinearCastFunc)input->m_pCollisionDispatcher->m_agentFuncs[agentType].m_func1;
                func(&localBody, bodyB, input, a4, a5);
            }
            key = collection->GetNextShapeKey(key);
        } while (key != -1);
    }

    hkTimerEnd();
}

}
}   // namespace f3m_009d1840

// @f3 0x009c6780 (community match, verified in this file)
#include <math.h>
namespace f3m_009c6780 {


namespace N9c6780 {

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

typedef float hkReal;
typedef unsigned int hkUint32;

namespace hkMath
{
    __forceinline hkReal fabs(hkReal r) { return hkReal(::fabs(r)); }
    __forceinline hkReal sqrt(hkReal r) { return hkReal(::sqrt(r)); }
    template <typename T> __forceinline T min2(T x, T y) { return x < y ? x : y; }
}

struct hkVector4Comparison
{
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };
    int m_mask;
    __forceinline int anyIsSet(Mask m) const { return m_mask & m; }
};

struct hkMatrix3;
struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    union
    {
        struct
        {
            hkReal x;
            hkReal y;
            hkReal z;
            hkReal w;
        };
        hkUint32 u[4];
    };

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    void FUN_008d2970(const hkTransform& t, const hkVector4& v);

    __forceinline void setAbs4(const hkVector4& v)
    {
        x = hkMath::fabs(v.x);
        y = hkMath::fabs(v.y);
        z = hkMath::fabs(v.z);
        w = hkMath::fabs(v.w);
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? (hkReal)a.x : (hkReal)b.x;
        y = a.y < b.y ? (hkReal)a.y : (hkReal)b.y;
        z = a.z < b.z ? (hkReal)a.z : (hkReal)b.z;
        w = a.w < b.w ? (hkReal)a.w : (hkReal)b.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline hkVector4Comparison compareLessThanZero4() const
    {
        hkVector4Comparison ret;
        ret.m_mask = ((x < 0) ? hkVector4Comparison::MASK_X : 0) |
                     ((y < 0) ? hkVector4Comparison::MASK_Y : 0) |
                     ((z < 0) ? hkVector4Comparison::MASK_Z : 0) |
                     ((w < 0) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline hkReal length3() const { return hkMath::sqrt(dot3(*this)); }
    __forceinline void mul4(hkReal s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void mul3(hkReal s)
    {
        x *= s;
        y *= s;
        z *= s;
    }
    __forceinline hkReal normalizeWithLength3()
    {
        hkReal len = length3();
        mul4(1.0f / len);
        return len;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setXYZ(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v) { _setMul3(r, v); }
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    const hkReal v0 = v.x;
    const hkReal v1 = v.y;
    const hkReal v2 = v.z;
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}

namespace hkVector4Util
{
    __forceinline void mulSigns4(hkVector4& inout, const hkVector4& signs)
    {
        int* io = reinterpret_cast<int*>(&inout);
        const int* s = reinterpret_cast<const int*>(&signs);
        io[0] ^= s[0] & 0x80000000;
        io[1] ^= s[1] & 0x80000000;
        io[2] ^= s[2] & 0x80000000;
        io[3] ^= s[3] & 0x80000000;
    }
}

struct hkpShape
{
    void* vtbl;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_userData;
    unsigned int m_type;
};

struct hkpConvexShape : hkpShape
{
    hkReal m_radius;
    __forceinline hkReal getRadius() const { return m_radius; }
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpBoxShape : hkpConvexShape
{
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_halfExtents;
    __forceinline const hkVector4& getHalfExtents() const { return m_halfExtents; }
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;
    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setNormal(const hkVector4& n) { m_separatingNormal.setXYZ(n); }
    __forceinline void setDistance(hkReal d) { m_separatingNormal.w = d; }
};

struct hkpCdPoint
{
    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;

    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;
    hkReal m_earlyOutDistance;
};

struct TimerRecord
{
    const char* name;
    unsigned int ticks;
    unsigned int extra;
};

struct Monitor
{
    TimerRecord* start;
    TimerRecord* next;
    TimerRecord* capacity;
    TimerRecord* limit;
};

__forceinline void timerBegin(const char* name)
{
    Monitor* monitor = static_cast<Monitor*>(FUN_00d9b080(DAT_0116913c));
    TimerRecord* record = monitor->next;
    if (record < monitor->limit)
    {
        record->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        record->ticks = ticks;
        monitor->next = record + 1;
    }
}

__forceinline bool ComputeClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                        const hkpCollisionInput& input, hkContactPoint& contactOut)
{
    const hkVector4& posA = bodyA.getTransform().getTranslation();
    hkVector4 posLocalB;
    posLocalB.FUN_008d2970(bodyB.getTransform(), posA);

    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());

    hkVector4 absPosB;
    absPosB.setAbs4(posLocalB);
    hkVector4 clippedAbsPos;
    clippedAbsPos.setMin4(absPosB, boxB->getHalfExtents());
    hkVector4 delta;
    delta.setSub4(clippedAbsPos, absPosB);

    hkReal distance;
    if (delta.compareLessThanZero4().anyIsSet(hkVector4Comparison::MASK_XYZ))
    {
        distance = delta.normalizeWithLength3();
        distance = distance - (sphereA->getRadius() + boxB->getRadius());
        if (distance > input.getTolerance())
        {
            return false;
        }
        hkVector4Util::mulSigns4(delta, posLocalB);
        delta.setNeg4(delta);
        contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        hkReal d0 = absPosB.x - boxB->getHalfExtents().x;
        hkReal d1 = absPosB.y - boxB->getHalfExtents().y;
        hkReal d2 = absPosB.z - boxB->getHalfExtents().z;
        int i;
        if (d0 > d1)
        {
            if (d0 > d2)
            {
                i = 0;
                contactOut.setNormal(bodyB.getTransform().getColumn(0));
                distance = d0;
            }
            else
            {
                i = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = d2;
            }
        }
        else
        {
            if (d1 > d2)
            {
                i = 1;
                contactOut.setNormal(bodyB.getTransform().getColumn(1));
                distance = d1;
            }
            else
            {
                i = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = d2;
            }
        }
        if (posLocalB(i) < 0)
        {
            contactOut.getSeparatingNormal().setNeg4(contactOut.getSeparatingNormal());
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }

    contactOut.getPosition().setAddMul4(posA, contactOut.getNormal(), -distance - sphereA->getRadius());
    contactOut.setDistance(distance);
    return true;
}

} // namespace N9c6780

// pdb: hkpSphereBoxAgent::staticGetClosestPoints | hkpSphereBoxAgent.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void __cdecl hkpSphereBoxAgent_staticGetClosestPoints(const N9c6780::hkpCdBody& bodyA, const N9c6780::hkpCdBody& bodyB,
                          const N9c6780::hkpCollisionInput& input, N9c6780::hkpCdPointCollector& collector)
{
    using namespace N9c6780;
    timerBegin("TtSphereBox");

    hkpCdPoint event(bodyA, bodyB);
    if (ComputeClosestPoints(bodyA, bodyB, input, event.m_contact))
    {
        collector.addCdPoint(event);
    }

    timerBegin("Et");
}
}   // namespace f3m_009c6780

// @f3 0x009db1a0 (community match, verified in this file)
#include <math.h>
#pragma intrinsic(sin, sqrt)
extern double DAT_00db38b0;
namespace f3m_009db1a0 {



struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
};

struct Obj {
    char pad000[0x100];
    Vector4 out0;
    Vector4 out1;
    Vector4 out2;
    char pad130[0x10];
    Vector4 row[2];
    void FUN_009db1a0(float angle);
};

void Obj::FUN_009db1a0(float angle)
{
    float sn = sinf(angle);
    Vector4 c;
    c.x = row[1].y * row[0].z - row[1].z * row[0].y;
    c.y = row[1].z * row[0].x - *(volatile float*)&row[0].z * row[1].x;
    c.z = *(volatile float*)&row[0].y * row[1].x - row[1].y * row[0].x;

    float cs = sqrtf(1.0f - sn * sn);

    Vector4 v;
    v.x = *(volatile float*)&row[0].x * cs;
    v.y = row[0].y * cs;
    v.z = *(volatile float*)&row[0].z * cs;
    v.w = row[0].w * cs;

    v.x += c.x * sn;
    v.y += c.y * sn;
    v.z += c.z * sn;
    v.w += sn * DAT_00db38b0;

    out0.x = v.x;
    out0.y = v.y;
    out0.z = v.z;
    out0.w = v.w;

    float ry = row[1].x * v.z - row[1].z * v.x;
    volatile float rz = row[1].y * v.x - row[1].x * v.y;
    out2.x = v.y * row[1].z - row[1].y * v.z;
    out2.y = ry;
    out2.z = rz;
    out2.w = 0.0f;
}
}   // namespace f3m_009db1a0

// @f3 0x009d26b0 (community match, verified in this file)
namespace f3m_009d29b0 {
inline void Add867(Vec_x& out,const Vec_x& a,const float& bx,const float& by,const float& bz,const float& bw) {
out.x=bx+a.x;
out.y=by+a.y;
out.z=bz+a.z;
out.w=bw+a.w;
}
typedef void (__cdecl *Process867)(const Body_x&,const Body_x&,const Input_x&,void*,void*);
// pdb: hkpMultiSphereAgent::staticLinearCast | hkpMultiSphereAgent.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void hkpMultiSphereAgent_staticLinearCast(const Body_x& a,const Body_x& b,const Input_x* input,void* output,void* context)
{
    const Multi_x* multi=static_cast<const Multi_x*>(a.shape);
    Motion_x ms(*a.motion);
    Sphere_x sphere(0.0f);
    Body_x operand(&a,&ms);
    int typeB=b.shape->type;
    int i=0;
    if(multi->count<=0) return;
    const Input_x* ctx=input;
    Vec_x rotated;
    do {
        int typeA=sphere.type;
        const Vec_x& v=multi->spheres[i];
        float x=v.x,y=v.y,z=v.z;
        rotated.x=ms.transform.c1.x*y+ms.transform.c0.x*x+ms.transform.c2.x*z;
        rotated.y=ms.transform.c1.y*y+ms.transform.c0.y*x+ms.transform.c2.y*z;
        rotated.z=ms.transform.c1.z*y+ms.transform.c0.z*x+ms.transform.c2.z*z;
        rotated.w=0.0f;
        Add867(ms.transform.pos,a.motion->transform.pos,rotated.x,rotated.y,rotated.z,rotated.w);
        sphere.radius=v.w;
        operand.shape=&sphere;
        operand.key=i;
        Process867 fn=reinterpret_cast<Process867>(ctx->dispatcher->entries[ctx->dispatcher->table[typeA+13][typeB]].linear);
        fn(operand,b,*ctx,output,context);
        ++i;
    } while(i<multi->count);
}
}

// @f3 0x009c5c30 (community match, verified in this file)
#include <intrin.h>
#include <math.h>

#include "havok/hkMonitorStream.h"
namespace NativeBox891 {
extern unsigned long DAT_0116913c;
extern const char DAT_00e7f1b8[],DAT_00e32798[];
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct S009c5c30_Ev {
    const char* id;
    unsigned int tick;
    unsigned int unk08;

    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov ticks, eax } tick = ticks; }
};

struct S009c5c30_Tls {
    unsigned int unk00;
    S009c5c30_Ev* cur;
    unsigned int unk08;
    S009c5c30_Ev* end;
};

struct S009c5c30_Vec {
    float x;
    float y;
    float z;
    void FUN_008d2970(void* r, void* qv);
};

struct S009c5c30_Y {
    int unk00,unk04,unk08,unk0c;
    float r;
};

struct S009c5c30_Q {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    S009c5c30_Vec pos;
};

struct S009c5c30_A {
    S009c5c30_Y* y;
    unsigned int unk04;
    S009c5c30_Q* q;
};

struct S009c5c30_D {
    int unk00,unk04,unk08,unk0c;
    float r;
    int unk14,unk18,unk1c;
    float ex;
    float ey;
    float ez;
};

struct S009c5c30_R {
    float m[16];
};

struct S009c5c30_B {
    S009c5c30_D* d;
    unsigned int unk04;
    S009c5c30_R* r;
};

struct S009c5c30_Cb {
    virtual void Slot0();
    virtual void Slot1(void* a, void* b);
};

// pdb: hkpSphereBoxAgent::staticGetPenetrations | hkpSphereBoxAgent.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void hkpSphereBoxAgent_staticGetPenetrations(S009c5c30_A* a, S009c5c30_B* b, unsigned int unk10, S009c5c30_Cb* cb) {
    HK_TIMER_BEGIN("SphereBox", HK_NULL);

    S009c5c30_Y* y = a->y;
    S009c5c30_Vec* pos = &a->q->pos;
    S009c5c30_R* r = b->r;
    S009c5c30_D* d = b->d;

    __declspec(align(16)) S009c5c30_Vec v;
    v.FUN_008d2970(r, pos);

    __declspec(align(16)) S009c5c30_Vec w;
    w.x = fabsf(v.x);
    w.y = fabsf(v.y);
    w.z = fabsf(v.z);
    if (!(w.x < d->ex)) w.x = d->ex;
    if (!(w.y < d->ey)) w.y = d->ey;
    if (!(w.z < d->ez)) w.z = d->ez;

    *(unsigned int*)&w.x ^= *(unsigned int*)&v.x & 0x80000000u;
    *(unsigned int*)&w.y ^= *(unsigned int*)&v.y & 0x80000000u;
    *(unsigned int*)&w.z ^= *(unsigned int*)&v.z & 0x80000000u;

    S009c5c30_Vec transformed;
        transformed.x=b->r->m[0]*w.x+b->r->m[4]*w.y+b->r->m[8]*w.z+b->r->m[12];
        transformed.y=b->r->m[1]*w.x+b->r->m[5]*w.y+b->r->m[9]*w.z+b->r->m[13];
        transformed.z=b->r->m[2]*w.x+b->r->m[6]*w.y+b->r->m[10]*w.z+b->r->m[14];
    w=transformed;

    __declspec(align(16)) S009c5c30_Vec df;
    df.x = w.x - pos->x;
    df.y = w.y - pos->y;
    df.z = w.z - pos->z;

    float rad = d->r + y->r;
    float dist2 = df.x * df.x + df.y * df.y + df.z * df.z;
    if (dist2 < rad * rad) {
        cb->Slot1(a, b);
    }

    HK_TIMER_END();
}

}

// @f3 0x009ca130 (community match, verified in this file)
#include <intrin.h>
namespace f3m_009ca130 {
// 0x009ca130: hkBoxBoxAgent3::process(const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, hkpAgentData*
// agentData, hkVector4* separatingNormalOut, hkpProcessCollisionOutput& output) of Havok 5.5.0 (hkpInternal,
// compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets up a box-box detector for the two bodies (half extents grown by the shapes' radii, the relative
// transform, the tolerance) and lets it update the manifold kept in the agent's data; the entry gets the
// manifold's number of points, and the function returns the address behind the manifold. A timer brackets it.
// Names follow the Havok 5.5.0 SDK headers where the SDK declares them (the agent input, the manifold, the
// monitor stream, the shapes); the detector class is not in the SDK's headers, so its members are named from
// their use here. Every body is written from the game's code.
namespace f3m_009ca130 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream
extern const char DAT_00e7f31c[];  // "TtBoxBox3"

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        command->m_time0 = time;
        stream.setEnd((char*)(command + 1));
    }
}

struct __declspec(align(16)) hkVector4
{
    void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void setAll(hkReal a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    hkTransform() {}
    // the four columns are copied out first and then assigned
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.m_rotation.m_col0;
        const hkVector4 col1 = t.m_rotation.m_col1;
        const hkVector4 col2 = t.m_rotation.m_col2;
        const hkVector4 col3 = t.m_translation;
        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkpShape
{
    virtual ~hkpShape();

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpBoxShape : hkpConvexShape
{
    const hkVector4& getHalfExtents() const { return m_halfExtents; }

    hkVector4 m_halfExtents;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;
struct hkpContactMgr;
struct hkpProcessCollisionOutput;

struct hkpProcessCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkpAgent3ProcessInput
{
    hkPadSpu<const hkpCdBody*> m_bodyA;
    hkPadSpu<const hkpCdBody*> m_bodyB;
    hkPadSpu<const hkpProcessCollisionInput*> m_input;
    hkPadSpu<hkpContactMgr*> m_contactMgr;
    hkTransform m_aTb;
};

struct hkpAgentEntry
{
    hkUchar m_streamCommand;
    hkUchar m_agentType;
    hkUchar m_numContactPoints;
    hkUchar m_size;
};

struct hkpFeatureContactPoint
{
    hkUint32 m_data;
};

struct hkpBoxBoxManifold
{
    hkpFeatureContactPoint m_contactPoints[8];
    hkUchar m_faceVertexFeatureCount;
    hkUchar m_numPoints;
    bool m_isComplete;
    bool m_manifoldNormalInitialized;
    hkUint32 m_manifoldNormalB;
    hkVector4 m_manifoldNormalA;
};

// the box-box detector: the two bodies, their world transforms, B's transform in A's space, the half extents
// with the radii added, the tolerance in the forms the detector works with
struct hkpBoxBoxCollisionDetection
{
    __forceinline hkpBoxBoxCollisionDetection(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                              const hkpProcessCollisionInput* env,
                                hkpContactMgr* mgr, hkpProcessCollisionOutput* result, const hkTransform& aTb,
                                const hkTransform& wTa, const hkVector4& radiusA, const hkTransform& wTb,
                                const hkVector4& radiusB, hkReal tolerance)
        : m_bodyA(&bodyA), m_bodyB(&bodyB), m_env(env), m_contactMgr(mgr), m_result(result), m_wTa(&wTa), m_wTb(&wTb),
          m_aTb(aTb), m_radiusA(radiusA), m_radiusB(radiusB)
    {
        m_tolerance = tolerance;
        m_boundaryTolerance = 0.01f;
        m_tolerance4.setAll(tolerance);
        m_keepRadiusA.setAdd4(radiusA, m_tolerance4);
        m_keepRadiusB.setAdd4(radiusB, m_tolerance4);
    }

    void hkpBoxBoxCollisionDetection_calcManifold(hkpBoxBoxManifold& manifold) const;  // calcManifold

    const hkpCdBody* m_bodyA;
    const hkpCdBody* m_bodyB;
    const hkpProcessCollisionInput* m_env;
    hkpContactMgr* m_contactMgr;
    hkpProcessCollisionOutput* m_result;
    const hkTransform* m_wTa;
    const hkTransform* m_wTb;
    hkTransform m_aTb;
    hkVector4 m_radiusA;
    hkVector4 m_radiusB;
    hkVector4 m_tolerance4;
    hkVector4 m_keepRadiusA;
    hkVector4 m_keepRadiusB;
    hkReal m_tolerance;
    hkReal m_boundaryTolerance;
    hkVector4 m_unkC0;
    hkVector4 m_unkD0;
    hkVector4 m_unkE0;
    hkVector4 m_unkF0;
    hkVector4 m_unk100;
    hkVector4 m_unk110;
    hkVector4 m_unk120;
};

}  // namespace f3m_009ca130

// pdb: hkBoxBoxAgent3::process | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void* __cdecl hkBoxBoxAgent3_process(const f3m_009ca130::hkpAgent3ProcessInput& input, f3m_009ca130::hkpAgentEntry* entry,
                           void* agentData, f3m_009ca130::hkVector4* separatingNormalOut,
                           f3m_009ca130::hkpProcessCollisionOutput& output)
{
    namespace hk = f3m_009ca130;
    hk::hkTimerCommand(hk::DAT_00e7f31c);

    const hk::hkpCdBody* bodyA = input.m_bodyA;
    const hk::hkpCdBody* bodyB = input.m_bodyB;
    const hk::hkpBoxShape* boxA = static_cast<const hk::hkpBoxShape*>(bodyA->getShape());
    const hk::hkpBoxShape* boxB = static_cast<const hk::hkpBoxShape*>(bodyB->getShape());

    // the boxes' half extents grown by their radii
    hk::hkVector4 radiusA4;
    radiusA4.setAll(boxA->getRadius());
    hk::hkVector4 radiusA;
    radiusA.setAdd4(boxA->getHalfExtents(), radiusA4);

    hk::hkVector4 radiusB4;
    radiusB4.setAll(boxB->getRadius());
    hk::hkVector4 radiusB;
    radiusB.setAdd4(boxB->getHalfExtents(), radiusB4);

    const hk::hkReal tolerance = input.m_input.val()->getTolerance();
    hk::hkpBoxBoxCollisionDetection detector(*bodyA, *bodyB, input.m_input, input.m_contactMgr, &output, input.m_aTb,
                                             bodyA->getTransform(), radiusA, bodyB->getTransform(), radiusB,
                                             tolerance);

    hk::hkpBoxBoxManifold* manifold = static_cast<hk::hkpBoxBoxManifold*>(agentData);
    detector.hkpBoxBoxCollisionDetection_calcManifold(*manifold);
    entry->m_numContactPoints = manifold->m_numPoints;

    hk::hkTimerCommand("Et");
    return manifold + 1;
}
}   // namespace f3m_009ca130

// @f3 0x009ca610 (community match, verified in this file)
#include <intrin.h>
namespace f3m_009ca610 {
// 0x009ca610: hkpBoxBoxAgent::processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result) of Havok 5.5.0 (hkpCollide, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets up a box-box detector for the two bodies (half extents grown by the shapes' radii, B's transform in A's
// space, the tolerance) and lets it update the manifold the agent keeps. A timer brackets it.
// Names follow the Havok 5.5.0 SDK headers where the SDK declares them (the agent, the manifold, the monitor
// stream, the shapes); the detector class is not in the SDK's headers, so its members are named from their use.
// The vector helpers follow the forms of the SDK's inline maths; the function's body is written from the game's
// code.
namespace f3m_009ca610 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream
extern const char DAT_00e7f370[];  // "TtBoxBox"

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        command->m_time0 = time;
        stream.setEnd((char*)(command + 1));
    }
}

struct __declspec(align(16)) hkVector4
{
    void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void setAll(hkReal a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    void add4(const hkVector4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    hkTransform() {}
    // setMulInverseMul: this = inverse(bTa) * bTc
    void FUN_00925300(const hkTransform& bTa, const hkTransform& bTc);
    // the four columns are copied out first and then assigned
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.m_rotation.m_col0;
        const hkVector4 col1 = t.m_rotation.m_col1;
        const hkVector4 col2 = t.m_rotation.m_col2;
        const hkVector4 col3 = t.m_translation;
        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkpShape
{
    virtual ~hkpShape();

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpBoxShape : hkpConvexShape
{
    const hkVector4& getHalfExtents() const { return m_halfExtents; }

    hkVector4 m_halfExtents;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;
struct hkpContactMgr;
struct hkpProcessCollisionOutput;

struct hkpProcessCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkpFeatureContactPoint
{
    hkUint32 m_data;
};

struct hkpBoxBoxManifold
{
    hkpFeatureContactPoint m_contactPoints[8];
    hkUchar m_faceVertexFeatureCount;
    hkUchar m_numPoints;
    bool m_isComplete;
    bool m_manifoldNormalInitialized;
    hkUint32 m_manifoldNormalB;
    hkVector4 m_manifoldNormalA;
};

// the box-box detector: the two bodies, their world transforms, B's transform in A's space, the half extents
// with the radii added, the tolerance in the forms the detector works with
struct hkpBoxBoxCollisionDetection
{
    __forceinline hkpBoxBoxCollisionDetection(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                              const hkpProcessCollisionInput* env,
                                hkpContactMgr* mgr, hkpProcessCollisionOutput* result, const hkTransform& aTb,
                                const hkTransform& wTa, const hkVector4& radiusA, const hkTransform& wTb,
                                const hkVector4& radiusB, hkReal tolerance)
        : m_bodyA(&bodyA), m_bodyB(&bodyB), m_env(env), m_contactMgr(mgr), m_result(result), m_wTa(&wTa), m_wTb(&wTb),
          m_aTb(aTb), m_radiusA(radiusA), m_radiusB(radiusB)
    {
        m_tolerance = tolerance;
        m_boundaryTolerance = 0.01f;
        m_tolerance4.setAll(tolerance);
        m_keepRadiusA.setAdd4(radiusA, m_tolerance4);
        m_keepRadiusB.setAdd4(radiusB, m_tolerance4);
    }

    void hkpBoxBoxCollisionDetection_calcManifold(hkpBoxBoxManifold& manifold) const;  // calcManifold

    const hkpCdBody* m_bodyA;
    const hkpCdBody* m_bodyB;
    const hkpProcessCollisionInput* m_env;
    hkpContactMgr* m_contactMgr;
    hkpProcessCollisionOutput* m_result;
    const hkTransform* m_wTa;
    const hkTransform* m_wTb;
    hkTransform m_aTb;
    hkVector4 m_radiusA;
    hkVector4 m_radiusB;
    hkVector4 m_tolerance4;
    hkVector4 m_keepRadiusA;
    hkVector4 m_keepRadiusB;
    hkReal m_tolerance;
    hkReal m_boundaryTolerance;
    hkVector4 m_unkC0;
    hkVector4 m_unkD0;
    hkVector4 m_unkE0;
    hkVector4 m_unkF0;
    hkVector4 m_unk100;
    hkVector4 m_unk110;
    hkVector4 m_unk120;
};

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpCollisionAgent : hkReferencedObject
{
    hkpContactMgr* m_contactMgr;
};

struct hkpBoxBoxAgent : hkpCollisionAgent
{
    // processCollision
    void hkpBoxBoxAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input,
                      hkpProcessCollisionOutput& result);

    hkpBoxBoxManifold m_manifold;
};

// pdb: hkpBoxBoxAgent::processCollision | hkpBoxBoxAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpBoxBoxAgent::hkpBoxBoxAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                  const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result)
{
    hkTimerCommand(DAT_00e7f370);

    const hkpBoxShape* boxA = static_cast<const hkpBoxShape*>(bodyA.getShape());
    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());

    // the boxes' half extents grown by their radii
    hkVector4 radiusA;
    radiusA.setAll(boxA->getRadius());
    radiusA.add4(boxA->getHalfExtents());

    hkVector4 radiusB;
    radiusB.setAll(boxB->getRadius());
    radiusB.add4(boxB->getHalfExtents());

    hkTransform aTb;
    aTb.FUN_00925300(bodyA.getTransform(), bodyB.getTransform());

    hkpBoxBoxCollisionDetection detector(bodyA, bodyB, &input, m_contactMgr, &result, aTb, bodyA.getTransform(),
                                         radiusA, bodyB.getTransform(), radiusB, input.getTolerance());

    detector.hkpBoxBoxCollisionDetection_calcManifold(m_manifold);

    hkTimerCommand("Et");
}

}  // namespace f3m_009ca610
}   // namespace f3m_009ca610

// @f3 0x009c2530 (community match, verified in this file)
extern unsigned DAT_0116913c;
namespace f3m_009c2530 {
namespace S009c2530_ns {

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct S009c2530_Stream { char* m_start; char* m_cur; char* m_spare; char* m_end; };
// hkMonitorStream::TimerCommand (class and member names: FNV360_PDB)
struct S009c2530_TimerCommand
{
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov dword ptr[ticks], eax } m_time0 = ticks; }
};

struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.getColumn(3);
        m_rotation.m_col0 = col0;
        m_rotation.m_col1 = col1;
        m_rotation.m_col2 = col2;
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline const float& operator()(int r, int c) const { return m_rotation(r, c); }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    float v0 = b(0);
    float v1 = b(1);
    float v2 = b(2);
    x = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    y = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    z = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    w = 0;
}

__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkContactPoint { hkVector4 m_position; hkVector4 m_separatingNormal; };

struct hkpShape { void* vtbl; int m_memSizeAndFlags; int m_userData; int m_type; };
struct hkpConvexShape : hkpShape { float m_radius; };
struct hkpCapsuleShape : hkpConvexShape { int unk14, unk18, unk1c; hkVector4 m_vertices[2]; };
struct hkpTriangleShape : hkpConvexShape { int unk14, unk18, unk1c; hkVector4 m_vertices[3]; };

struct hkpCdBody { const hkpShape* m_shape; unsigned int m_shapeKey; const hkTransform* m_motion; const hkpCdBody* m_parent; };

struct hkpProcessCollisionInput { void* m_dispatcher; float m_tolerance; };

struct hkpProcessCollisionOutput;
struct hkpGskCache;
struct hkpConstraintOwner;

struct hkpContactMgr
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual unsigned short addContactPoint(const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input,
                                           hkpProcessCollisionOutput& output, const hkpGskCache* cache, hkContactPoint& cp);
    virtual int reserveContactPoints(int numPoints);
    virtual void removeContactPoint(unsigned short cpId, hkpConstraintOwner& owner);
};

__forceinline unsigned short S009c2530_addPoint(hkpContactMgr* mgr, const hkpCdBody& a, const hkpCdBody& b,
                                               const hkpProcessCollisionInput& in, hkpProcessCollisionOutput& out, hkContactPoint& cp)
{
    return mgr->addContactPoint(a, b, in, out, 0, cp);
}

struct hkpAgent3ProcessInput
{
    const hkpCdBody* m_bodyA;
    const hkpCdBody* m_bodyB;
    const hkpProcessCollisionInput* m_input;
    hkpContactMgr* m_contactMgr;
};

struct __declspec(align(16)) hkpProcessCdPoint { hkContactPoint m_contact; unsigned int m_contactPointId; };

struct hkpAgentEntry { unsigned char m_streamCommand; unsigned char m_numContactPoints2; unsigned char m_numContactPoints; unsigned char m_size; };

struct S009c2530_Cache { float unk00, unk04, unk08, unk0c, unk10, unk14; };
struct S009c2530_AgentData { unsigned short m_contactPointId[3]; unsigned short unk06; S009c2530_Cache m_cache; };

struct ContactRef { hkpProcessCdPoint* m_contactPoint; hkpAgentEntry* m_agentEntry; void* m_agentData; };
struct PotentialInfo { ContactRef* m_firstFreePotentialContact; hkpProcessCdPoint** m_firstFreeRepresentativeContact; };

struct __declspec(align(16)) ToiInfo
{
    float m_time;
    float m_separatingVelocity;
    int unk08, unk0c;
    hkContactPoint m_contact;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};

struct hkpProcessCollisionOutput
{
    hkpProcessCdPoint* m_firstFreeContactPoint;
    hkpConstraintOwner* m_constraintOwner;
    hkpProcessCdPoint m_contactPoints[256];
    ToiInfo m_toi;
    PotentialInfo* m_potentialContacts;
};

void __cdecl hkCollideCapsuleUtilCapsVsTri(const hkVector4* capsPoints, float capsRadius, const hkVector4* triVertices, float triRadius,
                                           const S009c2530_Cache& cache, float searchManifoldTolerance, int searchManifold, hkContactPoint* points);

}
using namespace S009c2530_ns;

// pdb: hkCapsuleTriangleAgent3::process | hkpCapsuleTriangleAgent3.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
S009c2530_AgentData* hkCapsuleTriangleAgent3_process(const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, S009c2530_AgentData* agentData,
                                  hkVector4* separatingNormal, hkpProcessCollisionOutput& output)
{
    {
        S009c2530_Stream* s = (S009c2530_Stream*)FUN_00d9b080(DAT_0116913c);
        char* cur = s->m_cur;
        if (cur < s->m_end)
        {
            S009c2530_TimerCommand* h = (S009c2530_TimerCommand*)cur;
            h->m_commandAndMonitor = "TtCapsTri3";
            h->setTime();
            s->m_cur = (char*)(h + 1);
        }
    }

    int numContacts = 0;
    const hkpCapsuleShape* capsA = static_cast<const hkpCapsuleShape*>(input.m_bodyA->m_shape);
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(input.m_bodyB->m_shape);

    hkVector4 endPoints[2];
    hkVector4 triVertices[3];
    transformPoints(*input.m_bodyA->m_motion, capsA->m_vertices, 2, endPoints);
    transformPoints(*input.m_bodyB->m_motion, triB->m_vertices, 3, triVertices);

    hkContactPoint points[3];
    hkCollideCapsuleUtilCapsVsTri(endPoints, capsA->m_radius, triVertices, triB->m_radius, agentData->m_cache, 3.40282e38f, 1, points);

    int closest;
    if (points[0].m_separatingNormal.w < points[1].m_separatingNormal.w)
    {
        closest = 0;
        *separatingNormal = points[0].m_separatingNormal;
    }
    else
    {
        closest = 1;
        *separatingNormal = points[1].m_separatingNormal;
    }

    for (int i = 0; i < 3; i++)
    {
        unsigned short cpId = agentData->m_contactPointId[i];
        const hkpProcessCollisionInput* procInput = input.m_input;
        if (points[i].m_separatingNormal.w < procInput->m_tolerance)
        {
            if (cpId == 0xffff)
            {
                if (output.m_potentialContacts)
                {
                    if (input.m_contactMgr->reserveContactPoints(1) != 0)
                    {
                        goto storeId;
                    }
                    ContactRef* ref = output.m_potentialContacts->m_firstFreePotentialContact++;
                    ref->m_contactPoint = output.m_firstFreeContactPoint;
                    ref->m_agentData = agentData;
                    ref->m_agentEntry = entry;
                }
                else
                {
                    cpId = S009c2530_addPoint(input.m_contactMgr, *input.m_bodyA, *input.m_bodyB, *procInput, output, points[i]);
                    if (cpId == 0xffff)
                    {
                        goto storeId;
                    }
                }
            }
            {
                hkpProcessCdPoint* p = output.m_firstFreeContactPoint++;
                numContacts++;
                p->m_contact.m_position = points[i].m_position;
                p->m_contact.m_separatingNormal = points[i].m_separatingNormal;
                p->m_contactPointId = cpId;
                if (i == closest)
                {
                    PotentialInfo* potential = output.m_potentialContacts;
                    if (potential)
                    {
                        *potential->m_firstFreeRepresentativeContact = p;
                        potential->m_firstFreeRepresentativeContact++;
                    }
                }
            }
        }
        else if (cpId != 0xffff)
        {
            input.m_contactMgr->removeContactPoint(cpId, *output.m_constraintOwner);
            cpId = 0xffff;
        }
storeId:
        agentData->m_contactPointId[i] = cpId;
    }
    entry->m_numContactPoints = (unsigned char)numContacts;

    {
        S009c2530_Stream* s = (S009c2530_Stream*)FUN_00d9b080(DAT_0116913c);
        char* cur = s->m_cur;
        if (cur < s->m_end)
        {
            S009c2530_TimerCommand* h = (S009c2530_TimerCommand*)cur;
            h->m_commandAndMonitor = "Et";
            h->setTime();
            s->m_cur = (char*)(h + 1);
        }
    }
    return agentData + 1;
}
}   // namespace f3m_009c2530

// @f3 0x009c4bb0 (community match, verified in this file)
namespace f3m_009c4bb0 {
namespace S009c4bb0_ns {

struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.getColumn(3);
        m_rotation.m_col0 = col0;
        m_rotation.m_col1 = col1;
        m_rotation.m_col2 = col2;
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline const float& operator()(int r, int c) const { return m_rotation(r, c); }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    float v0 = b(0);
    float v1 = b(1);
    float v2 = b(2);
    x = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    y = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    z = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    w = 0;
}

__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    __forceinline void setDistance(float d) { m_separatingNormal(3) = d; }
};

struct hkpShape { void* vtbl; int m_memSizeAndFlags; int m_userData; int m_type; };
struct hkpConvexShape : hkpShape
{
    float m_radius;
    __forceinline float getRadius() const { return m_radius; }
};
struct hkpCapsuleShape : hkpConvexShape
{
    int unk14, unk18, unk1c;
    hkVector4 m_vertices[2];
    __forceinline const hkVector4* getVertices() const { return &m_vertices[0]; }
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const hkTransform* m_motion;
    const hkpCdBody* m_parent;
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *m_motion; }
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    float m_tolerance;
    __forceinline float getTolerance() const { return m_tolerance; }
};

void __cdecl FUN_0096d120(const hkVector4* capsAPoints, float capsARadius, const hkVector4* capsBPoints, float capsBRadius,
                          hkContactPoint* points);

// pdb: getThreeClosestPointsInl | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009c4bb0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                                              hkContactPoint* points)
{
    float tolerance = input.getTolerance();
    points[0].setDistance(tolerance);
    points[1].setDistance(tolerance);
    points[2].setDistance(tolerance);
    const hkpCapsuleShape* capsA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());
    hkVector4 pA[2];
    transformPoints(bodyA.getTransform(), capsA->getVertices(), 2, pA);
    hkVector4 pB[2];
    transformPoints(bodyB.getTransform(), capsB->getVertices(), 2, pB);

    FUN_0096d120(pA, capsA->getRadius(), pB, capsB->getRadius(), points);
}

volatile int S009c4bb0_in;
void S009c4bb0_caller()
{
    FUN_009c4bb0(*(const hkpCdBody*)S009c4bb0_in, *(const hkpCdBody*)S009c4bb0_in, *(const hkpCollisionInput*)S009c4bb0_in,
                 (hkContactPoint*)S009c4bb0_in);
}

}
}   // namespace f3m_009c4bb0

// @f3 0x009d5360 (community match, verified in this file)
// 0x009d5360: hkpStorageExtendedMeshShape::addTrianglesSubpart(const hkpExtendedMeshShape::TrianglesSubpart& partIn) of
// Havok 5.5.0 (hkpCollide, hkpStorageExtendedMeshShape.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-): adds a
// triangles subpart whose data the shape stores itself. It appends a fresh subpart, creates a MeshSubpartStorage,
// copies the vertices into it as hkVector4, the 16- or 32-bit indices (index striding clamped to 4 indices per
// triangle) and the 8- or 16-bit material indices and the materials, points the new subpart at the copies, and
// recalculates the shape's bounding box extents.
// The index counts come from the SDK's file-local `static int numIndices(int stride, int numTri)`, the game's
// 0x009d5030, which takes stride in eax and numTri in ecx: Visual C++ 2005 gives a static function whose address is
// never taken a register convention of its own when it sees every call to it in the same file, so the target cannot
// match without that body in the file. It is defined below, before the namespace, under the project symbol map's own
// name and parameter type for 0x009d5030 (FUN_00d49c20(d20base*, int)); the stand-in pointer type is the only change
// to the SDK's body (the stride is cast back to int for the switch, and to the pointer type at the two calls).
// The member is named hkpStorageExtendedMeshShape_addTrianglesSubpart inside its class (the base class's virtual addTrianglesSubpart is not overridden
// here, which changes no byte of the function).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, then whole lines, every cut checked byte for byte against the SDK's release
// library object); those declarations are the SDK's text with its names. The bodies follow the SDK's unoptimized
// (hybrid) library objects statement by statement (all 34 named locals of the target and both of the helper at the
// library's places) and reproduce the release objects. Only the two functions carry the project's names.
struct d20base;

static int FUN_00d49c20( d20base* stride, int numTri )
{
	switch ( reinterpret_cast<int>( stride ) )
	{
		case 1:
			return numTri + 2;
		case 2:
			return numTri * 2 + 1;
		default:
			return numTri * 4;
	}
}

namespace f3m_009d5360 {

typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				__forceinline void setData(T p)
				{
					hkUlong v = hkUlong(p);
					TlsSetValue( m_slotID, (void*)v );
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
__forceinline hkReferencedObject::hkReferencedObject()
: m_referenceCount(1)
{
}
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline T& hkArray<T>::back()
{
	;
	return m_data[ m_size - 1 ];
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::_reserve(this, newSize, sizeof(T));
	}
}
template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}
template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}
template <typename T>
__forceinline T* hkArray<T>::expandBy( int n )
{
	int oldsize = m_size;
	setSize( oldsize + n );
	return m_data+oldsize;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
class hkAabb;
class hkSphere;
class hkpCdVertex;
enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpShape( hkpShapeType type );
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShape::CalcSizeForSpuInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			static void __cdecl resetShapeFunctions();
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShape::ShapeFuncs), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShape::ShapeFuncs2), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
	public:
		hkUlong m_userData;
	public:
		hkEnum<hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const = 0;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const = 0;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const = 0;
		virtual hkBool32 isChildEnabled( hkpShapeKey key ) const { return true; }
		virtual bool isWeldingEnabled() const { return true; }
};
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpShapeCollection( hkpShapeType type );
		hkpShapeCollection( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_COLLECTION; }
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
 		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
		__forceinline bool isWeldingEnabled() const { return !m_disableWelding; }
	public:
		hkBool m_disableWelding;
};
class hkpWeldingUtility
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		static void __cdecl initWeldingTable(hkReal edgeNormalSnapDeltaAngle, hkReal triangleNormalSnapDeltaAngle);
		enum WeldingType
		{
			WELDING_TYPE_ANTICLOCKWISE = 0,
			WELDING_TYPE_CLOCKWISE = 4,
			WELDING_TYPE_TWO_SIDED = 5,
			WELDING_TYPE_NONE = 6
		};
		enum SectorType
		{
			ACCEPT_0	= 1,
			SNAP_0		= 0,
			REJECT		= 2,
			SNAP_1		= 4,
			ACCEPT_1	= 3
		};
		static __forceinline void calcSnapVector( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, SectorType sector, hkVector4& snapVectorOut );
		static __forceinline SectorType getSector(const hkVector4& triangleNormal, const hkVector4& collisionNormal, int edgeBitcode);
		static __forceinline void snapCollisionNormal( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, SectorType sector, hkVector4& collisionNormalInOut );
		static __forceinline hkBool shouldSnapOneSided(hkpWeldingUtility::WeldingType weldingType, const hkVector4& triangleNormal, const hkVector4& collisionNormal, int edgeBitcode );
		static __forceinline void calcSnapVectorOneSided( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, hkpWeldingUtility::WeldingType weldingType, hkVector4& snapVectorOut );
		enum NumAngles
		{
			NUM_ANGLES = 31
		};
	public:
		struct SinCosTableEntry
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpWeldingUtility::SinCosTableEntry), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkReal m_cosAccept0;
			hkReal m_sinAccept0;
			hkReal m_cosSnap0;
			hkReal m_cosSnap1;
			hkReal m_cosAccept1;
			hkReal m_sinAccept1;
		};
		static __declspec(align(16)) SinCosTableEntry m_sinCosTable[NUM_ANGLES+1];
};
extern hkReal hkConvexShapeDefaultRadius;
class hkpMeshMaterial;
class hkpMoppBvTreeShape;
class hkpExtendedMeshShape: public hkpShapeCollection
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){  return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) {  } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum IndexStridingType
		{
			INDICES_INVALID,
			INDICES_INT16,
			INDICES_INT32,
			INDICES_MAX_ID
		};
		enum MaterialIndexStridingType
		{
			MATERIAL_INDICES_INVALID,
			MATERIAL_INDICES_INT8,
			MATERIAL_INDICES_INT16,
			MATERIAL_INDICES_MAX_ID
		};
		enum SubpartType
		{
			SUBPART_TRIANGLES,
			SUBPART_SHAPE
		};
		struct Subpart
		{
			public:
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpExtendedMeshShape::Subpart), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			public:
				inline Subpart(SubpartType type);
				Subpart(hkFinishLoadedObjectFlag flag){};
			public:
				hkEnum<SubpartType,hkInt8> m_type;
				hkEnum<MaterialIndexStridingType,hkInt8> m_materialIndexStridingType;
				hkInt16 m_materialStriding;
				const void* m_materialIndexBase;
				hkUint16 m_materialIndexStriding;
				hkUint16 m_numMaterials;
				const hkpMeshMaterial* m_materialBase;
		};
		struct TrianglesSubpart : public hkpExtendedMeshShape::Subpart
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpExtendedMeshShape::TrianglesSubpart), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			public:
				inline TrianglesSubpart();
				TrianglesSubpart(hkFinishLoadedObjectFlag flag) : Subpart(flag) {};
				int	m_numTriangleShapes;
				const float*  m_vertexBase;
				int		m_vertexStriding;
				int		m_numVertices;
				hkVector4 m_extrusion;
				const void*	m_indexBase;
				int m_indexStriding;
				hkEnum<IndexStridingType,hkInt8> m_stridingType;
				hkInt8 m_flipAlternateTriangles;
				int m_triangleOffset;
		};
		struct ShapesSubpart : public hkpExtendedMeshShape::Subpart
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpExtendedMeshShape::ShapesSubpart), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			public:
				 ShapesSubpart( const hkpConvexShape*const* childShapes, int numChildShapes, const hkVector4& offset = hkVector4::getZero() );
				 ShapesSubpart( const hkpConvexShape*const* childShapes, int numChildShapes, const hkTransform& transform );
				 ShapesSubpart(hkFinishLoadedObjectFlag flag) : Subpart(flag) {};
				~ShapesSubpart();
			private:
			public:
				const hkpConvexShape*const*	m_childShapes;
				int 						m_numChildShapes;
				hkBool						m_offsetSet;
				hkBool						m_rotationSet;
				hkQuaternion				m_rotation;
				hkVector4					m_translation;
		};
	public:
		hkpExtendedMeshShape( hkReal radius = hkConvexShapeDefaultRadius, int numBitsForSubpartIndex = 12 );
		hkpExtendedMeshShape( const class hkpMeshShape* meshShape );
		~hkpExtendedMeshShape();
		void computeWeldingInfo( const hkpMoppBvTreeShape* mopp, hkpWeldingUtility::WeldingType weldingType );
		virtual void addTrianglesSubpart( const TrianglesSubpart& part );
		virtual void addShapesSubpart( const ShapesSubpart& part );
		inline int getNumTrianglesSubparts() const;
		inline int getNumShapesSubparts() const;
		inline TrianglesSubpart& getTrianglesSubpartAt( int i );
		inline const TrianglesSubpart& getTrianglesSubpartAt( int i ) const;
		inline ShapesSubpart& getShapesSubpartAt( int i );
		inline const ShapesSubpart& getShapesSubpartAt( int i ) const;
		inline const Subpart& getSubPart( hkpShapeKey shapeKey ) const;
		__forceinline hkInt32 getSubPartIndex( hkpShapeKey shapeKey ) const;
		__forceinline hkInt32 getTerminalIndexInSubPart( hkpShapeKey key ) const;
		__forceinline hkInt32 getNumBitsForSubpartIndex() const;
		__forceinline hkInt32 getSubpartShapeKeyBase( int subpartIndex) const;
		__forceinline SubpartType getSubpartType( hkpShapeKey key ) const;
		inline const hkVector4&	getScaling() const;
		void setScaling( const hkVector4& scaling ) ;
		inline hkReal getRadius() const;
		inline void setRadius(hkReal r );
		virtual hkpShapeKey getFirstKey() const;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const;
		const hkpMeshMaterial* getMeshMaterial( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape(  hkpShapeKey key, ShapeBuffer& buffer ) const;
		virtual hkUint32 getCollisionFilterInfo(  hkpShapeKey key ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		void recalcAabbExtents();
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		void assertTrianglesSubpartValidity( const TrianglesSubpart& part );
		void assertShapesSubpartValidity   ( const ShapesSubpart&    part );
	public:
		hkInt32								m_numBitsForSubpartIndex;
		hkVector4							m_scaling;
		hkVector4							m_aabbHalfExtents;
		hkVector4							m_aabbCenter;
		static hkReal m_triangleDengeneracyTolerance;
	protected:
		struct TrianglesSubpart*			m_trianglesSubparts;
		int									m_numTrianglesSubparts;
		struct ShapesSubpart*				m_shapesSubparts;
		int									m_numShapesSubparts;
	public:
		hkArray<hkUint16> m_weldingInfo;
		hkEnum<hkpWeldingUtility::WeldingType, hkUint8> m_weldingType;
	public:
		hkpExtendedMeshShape( hkFinishLoadedObjectFlag flag );
	protected:
		struct TrianglesSubpart m_embeddedTrianglesSubpart;
		struct TrianglesSubpart* expandOneTriangleSubparts();
		struct ShapesSubpart*	 expandOneShapesSubparts();
		void freeTriangleSubparts();
		void freeShapesSubparts();
		hkReal m_triangleRadius;
		int m_pad16[3];
};
__forceinline hkpExtendedMeshShape::Subpart::Subpart(SubpartType type)
{
	m_type = type;
	m_materialIndexStridingType = MATERIAL_INDICES_INT8;
	m_materialIndexStriding = 0;
	m_materialStriding = 0;
	m_numMaterials = 1;
	m_materialBase = 0;
	m_materialIndexBase = 0;
}
__forceinline hkpExtendedMeshShape::TrianglesSubpart::TrianglesSubpart(): Subpart( SUBPART_TRIANGLES )
{
	m_flipAlternateTriangles = 0;
	m_extrusion.setZero4();
}
class hkpStorageExtendedMeshShape : public hkpExtendedMeshShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpStorageExtendedMeshShape( hkReal radius = hkConvexShapeDefaultRadius, int numBitsForSubpartIndex = 12 );
		hkpStorageExtendedMeshShape( const hkpExtendedMeshShape* mesh );
		~hkpStorageExtendedMeshShape();
		virtual void hkpStorageExtendedMeshShape_addTrianglesSubpart( const TrianglesSubpart& part );
		virtual void addShapesSubpart( const ShapesSubpart& part );
	public:
		hkpStorageExtendedMeshShape( hkFinishLoadedObjectFlag flag );
		struct MeshSubpartStorage : public hkReferencedObject
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_SHAPE)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_SHAPE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_SHAPE)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_SHAPE); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){  return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) {  } class MustEndWithSemiColon;
				MeshSubpartStorage() {}
				virtual ~MeshSubpartStorage() {}
				hkArray<hkVector4> m_vertices;
				hkArray<hkUint16> m_indices16;
				hkArray<hkUint32> m_indices32;
				hkArray<hkUint8> m_materialIndices;
				hkArray<hkUint32> m_materials;
				hkArray<hkUint16> m_materialIndices16;
			public:
				MeshSubpartStorage( hkFinishLoadedObjectFlag flag );
		};
		struct ShapeSubpartStorage : public hkReferencedObject
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_SHAPE)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_SHAPE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_SHAPE)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_SHAPE); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){  return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) {  } class MustEndWithSemiColon;
				ShapeSubpartStorage() {}
				virtual ~ShapeSubpartStorage() {}
				hkArray<const hkpConvexShape*> m_shapes;
				hkArray<hkUint8> m_materialIndices;
				hkArray<hkUint32> m_materials;
				hkArray<hkUint16> m_materialIndices16;
			public:
				ShapeSubpartStorage( hkFinishLoadedObjectFlag flag );
		};
	protected:
		hkArray<struct MeshSubpartStorage*> m_meshstorage;
		hkArray<struct ShapeSubpartStorage*> m_shapestorage;
};
// pdb: hkpStorageExtendedMeshShape::addTrianglesSubpart | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, call_gap + bridge(call_gap|vtable) + skyrim(call_gap), high
void hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape_addTrianglesSubpart( const TrianglesSubpart& partIn )
{
	TrianglesSubpart& part = *expandOneTriangleSubparts();
	{
		TrianglesSubpart temp;
		part = temp;
	}
	m_meshstorage.pushBack( new MeshSubpartStorage() );
	MeshSubpartStorage& store = *m_meshstorage.back();
	{
		hkVector4* dst = store.m_vertices.expandBy( partIn.m_numVertices );
		const float* src = partIn.m_vertexBase;
		for ( int j = 0; j < partIn.m_numVertices; j++ )
		{
			dst->set( src[0], src[1], src[2] );
			dst++;
			src = reinterpret_cast<const float*>( reinterpret_cast<const char*>( src ) + partIn.m_vertexStriding );
		}
		part.m_vertexBase = reinterpret_cast<const float*>( store.m_vertices.begin() );
		part.m_vertexStriding = sizeof( hkVector4 );
		part.m_numVertices = partIn.m_numVertices;
	}
	{
		void* newIndicesBegin;
		if ( partIn.m_stridingType == INDICES_INT16 )
		{
			int strideIn = partIn.m_indexStriding / sizeof( hkUint16 );
			part.m_indexStriding = ( strideIn <= 2 ? strideIn : 4 ) * sizeof( hkUint16 );
			int nindices = FUN_00d49c20( reinterpret_cast<d20base*>( strideIn ), partIn.m_numTriangleShapes );
			hkUint16* dst = store.m_indices16.expandBy( nindices );
			newIndicesBegin = dst;
			const hkUint16* src = static_cast<const hkUint16*>( partIn.m_indexBase );
			for ( int j = 0; j < partIn.m_numTriangleShapes; j++ )
			{
				dst[0] = src[0];
				dst[1] = src[1];
				dst[2] = src[2];
				dst = reinterpret_cast<hkUint16*>( reinterpret_cast<char*>( dst ) + part.m_indexStriding );
				src = reinterpret_cast<const hkUint16*>( reinterpret_cast<const char*>( src ) + partIn.m_indexStriding );
			}
		}
		else
		{
			int strideIn = partIn.m_indexStriding / sizeof( hkUint32 );
			part.m_indexStriding = ( strideIn <= 2 ? strideIn : 4 ) * sizeof( hkUint32 );
			int nindices = FUN_00d49c20( reinterpret_cast<d20base*>( strideIn ), partIn.m_numTriangleShapes );
			hkUint32* dst = store.m_indices32.expandBy( nindices );
			newIndicesBegin = dst;
			const hkUint32* src = static_cast<const hkUint32*>( partIn.m_indexBase );
			for ( int j = 0; j < partIn.m_numTriangleShapes; j++ )
			{
				dst[0] = src[0];
				dst[1] = src[1];
				dst[2] = src[2];
				dst = reinterpret_cast<hkUint32*>( reinterpret_cast<char*>( dst ) + part.m_indexStriding );
				src = reinterpret_cast<const hkUint32*>( reinterpret_cast<const char*>( src ) + partIn.m_indexStriding );
			}
		}
		part.m_stridingType = partIn.m_stridingType;
		part.m_numTriangleShapes = partIn.m_numTriangleShapes;
		part.m_flipAlternateTriangles = partIn.m_flipAlternateTriangles;
		part.m_indexBase = newIndicesBegin;
	}
	part.m_materialIndexStridingType = partIn.m_materialIndexStridingType;
	if ( partIn.m_materialIndexBase )
	{
		if ( partIn.m_materialIndexStridingType == MATERIAL_INDICES_INT8 )
		{
			if ( partIn.m_materialIndexStriding == 0 )
			{
				store.m_materialIndices.pushBack( *static_cast<const hkUint8*>( partIn.m_materialIndexBase ) );
				part.m_materialIndexBase = &store.m_materialIndices.back();
			}
			else
			{
				hkUint8* dst = store.m_materialIndices.expandBy( partIn.m_numTriangleShapes );
				part.m_materialIndexBase = dst;
				const hkUint8* src = static_cast<const hkUint8*>( partIn.m_materialIndexBase );
				for ( int j = 0; j < partIn.m_numTriangleShapes; j++ )
				{
					dst[j] = *src;
					src += partIn.m_materialIndexStriding;
				}
			}
		}
		else
		{
			if ( partIn.m_materialIndexStriding == 0 )
			{
				store.m_materialIndices16.pushBack( *static_cast<const hkUint16*>( partIn.m_materialIndexBase ) );
				part.m_materialIndexBase = &store.m_materialIndices16.back();
			}
			else
			{
				hkUint16* dst = store.m_materialIndices16.expandBy( partIn.m_numTriangleShapes );
				part.m_materialIndexBase = dst;
				const hkUint16* src = static_cast<const hkUint16*>( partIn.m_materialIndexBase );
				for ( int j = 0; j < partIn.m_numTriangleShapes; j++ )
				{
					dst[j] = *src;
					src = reinterpret_cast<const hkUint16*>( reinterpret_cast<const char*>( src ) + partIn.m_materialIndexStriding );
				}
			}
		}
		part.m_materialIndexStriding = partIn.m_materialIndexStriding;
		if ( part.m_materialIndexStriding )
		{
			switch ( part.m_materialIndexStridingType )
			{
				case MATERIAL_INDICES_INT8: part.m_materialIndexStriding = sizeof( hkUint8 ); break;
				case MATERIAL_INDICES_INT16: part.m_materialIndexStriding = sizeof( hkUint16 ); break;
				default: ;
			}
		}
	}
	else {
		part.m_materialIndexBase = 0;
		part.m_materialIndexStriding = 0;
	}
	if ( part.m_materialIndexBase )
	{
		if ( partIn.m_materialStriding == 0 )
		{
			store.m_materials.pushBack( *reinterpret_cast<const hkUint32*>( partIn.m_materialBase ) );
			part.m_materialStriding = 0;
			part.m_numMaterials = 1;
		}
		else
		{
			hkUint32* dst = store.m_materials.expandBy( partIn.m_numMaterials );
			const hkUint32* src = reinterpret_cast<const hkUint32*>( partIn.m_materialBase );
			for ( int j = 0; j < partIn.m_numMaterials; j++ )
			{
				dst[j] = *src;
				src = reinterpret_cast<const hkUint32*>( reinterpret_cast<const char*>( src ) + partIn.m_materialStriding );
			}
			part.m_materialStriding = sizeof( hkUint32 );
			part.m_numMaterials = partIn.m_numMaterials;
		}
		part.m_materialBase = reinterpret_cast<const hkpMeshMaterial*>( store.m_materials.begin() );
	}
	recalcAabbExtents();
}

}  // namespace f3m_009d5360

// @f3 0x009ceea0 (community match, verified in this file)
#include <math.h>
namespace S9ceea0_ {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;

class hkBool
{
	private:
		char m_bool;
};

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline int __cdecl hkToIntFast( hkReal r )
	{
		return fnv_FloatToInt( r );
	}
}

extern const hkQuadReal hkQuadReal0000;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void setAll(hkReal x);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal length3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline static const hkVector4& __cdecl getZero();
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_vec;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline const hkVector4& getTranslation() const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};

inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}

inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	(*this)(0) *= s;
	(*this)(1) *= s;
	(*this)(2) *= s;
	(*this)(3) *= s;
}

inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}

inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}

inline hkReal minReal(hkReal a, hkReal b) { return a < b ? a : b; }
	inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = minReal(a.x, b.x);
		y = minReal(a.y, b.y);
		z = minReal(a.z, b.z);
		w = minReal(a.w, b.w);
	}

inline hkReal maxReal(hkReal a, hkReal b) { return a > b ? a : b; }
	inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = maxReal(a.x, b.x);
		y = maxReal(a.y, b.y);
		z = maxReal(a.z, b.z);
		w = maxReal(a.w, b.w);
	}

	inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = 0;
	}

	inline hkSimdReal hkVector4::length3() const
	{
		double squareLength = y*y;
		squareLength += x*x;
		squareLength += z*z;
		return hkMath::sqrt(hkReal(squareLength));
	}

inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
	return zero;
}

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

const hkVector4& hkTransform::getTranslation() const
{
	return m_translation;
}

inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}

class hkString
{
	public:
		                class MustEndWithSemiColon;
	public:
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
	private:
		hkArray<char> m_string;
	public:
		template<int size>
		static __forceinline void __cdecl memCpy16(void* dst, const void* src);
};

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

struct hkAabbUint32
{
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};

void hkAabb::setEmpty()
{
	m_min.setAll(3.40282e+38f);
	m_max.setAll(-3.40282e+38f);
}

class hkSphere
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		hkVector4 m_pos;
};

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};

class hkpCollisionDispatcher;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;

class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			                class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				                class MustEndWithSemiColon;
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				                class MustEndWithSemiColon;
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
};

void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}

class hkMotionState;

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline const hkpCdBody* getParent() const;
	public:
		__forceinline const hkMotionState* getMotionState() const;
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}

const hkMotionState* hkpCdBody::getMotionState() const
{
	return static_cast<const hkMotionState*>(m_motion);
}

const hkpCollidable* hkpCdBody::getRootCollidable() const
{
	const hkpCdBody* body = this;
	while( body->m_parent )
	{
		body = body->m_parent;
	}
	return reinterpret_cast<const hkpCollidable*>(body);
}

const hkpCdBody* hkpCdBody::getParent() const
{
	return m_parent;
}

struct hkpCollisionQualityInfo
{
	                class MustEndWithSemiColon;
	__declspec(align(16)) hkReal m_keepContact;
	hkReal m_create4dContact;
	hkReal m_createContact;
	hkReal m_manifoldTimDistance;
	hkPadSpu<hkBool32>		m_useContinuousPhysics;
	hkReal m_minSeparation;
	hkReal m_minExtraSeparation;
	hkReal m_minSafeDeltaTime;
	hkReal m_minAbsoluteSafeDeltaTime;
	hkReal m_toiSeparation;
	hkReal m_toiExtraSeparation;
	hkReal m_toiAccuracy;
	hkReal m_maxContraintViolation;
	hkReal m_minToiDeltaTime;
	hkUint16	m_constraintPriority;
	hkBool m_enableToiWeldRejection;
};

class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;

struct hkpCollisionInput
{
		                class MustEndWithSemiColon;
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			                class MustEndWithSemiColon;
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};

class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		hkUint32 m_id;
};

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	protected:
		enum { OFFSET_INVALID = 127 };
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};

class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				                class MustEndWithSemiColon;
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};

class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		inline const hkSweptTransform& getSweptTransform() const;
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};

const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}

class hkStepInfo
{
	public:
		                class MustEndWithSemiColon;
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};

struct hkpProcessCollisionInput : public hkpCollisionInput
{
		                class MustEndWithSemiColon;
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};

class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const = 0;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const = 0;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const = 0;
		virtual hkBool32 isChildEnabled( hkpShapeKey key ) const { return true; }
		virtual bool isWeldingEnabled() const { return true; }
};

class hkpAabbUtil
{
	public:
		struct OffsetAabbInput
		{
			                class MustEndWithSemiColon;
			hkPadSpu<const hkMotionState*> m_motionState;
			hkTransform m_transforms[4];
			hkPadSpu<int> m_numTransforms;
			hkTransform m_startTransform;
			hkTransform m_endTransformInv;
		};
		static void __cdecl initOffsetAabbInput(const hkMotionState* motionstate, OffsetAabbInput& input);
		static void __cdecl sweepOffsetAabb(const OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut);
};

__forceinline void __cdecl hkpAabbUtil::sweepOffsetAabb(const hkpAabbUtil::OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut)
{
	hkSimdReal half(0.5f);
	hkVector4 aabbHalfSize; aabbHalfSize.setSub4(aabbIn.m_max, aabbIn.m_min);  aabbHalfSize.mul4(half);
	hkVector4 aabbCenter; aabbCenter.setInterpolate4(aabbIn.m_max, aabbIn.m_min, half);
	hkVector4 arm; arm._setTransformedPos(input.m_endTransformInv, aabbCenter);
	hkVector4 min = aabbCenter;
	hkVector4 max = aabbCenter;
	{
		hkVector4 p; p._setTransformedPos(input.m_startTransform, arm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	const hkVector4 centerOfMassLocal = input.m_motionState->getSweptTransform().m_centerOfMassLocal;
	for (int i = 0; i < input.m_numTransforms; i++)
	{
		hkVector4 extendedArm;
		extendedArm.setSub4(arm, centerOfMassLocal);
		extendedArm.mul4(input.m_transforms[i].getTranslation().getSimdAt(3));
		extendedArm.add4(centerOfMassLocal);
		hkVector4 p; p._setTransformedPos(input.m_transforms[i], extendedArm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	{
		hkSimdReal r = aabbHalfSize.length3();
		hkVector4 radius; radius.setAll(r);
		aabbHalfSize.addMul4(input.m_motionState->m_deltaAngle.getSimdAt(3), radius);
		aabbHalfSize.setMin4(radius, aabbHalfSize);
	}
	aabbOut.m_min.setSub4(min, aabbHalfSize);
	aabbOut.m_max.setAdd4(max, aabbHalfSize);
	aabbOut.m_min.setMin4(aabbIn.m_min, aabbOut.m_min);
	aabbOut.m_max.setMax4(aabbIn.m_max, aabbOut.m_max);
}

class hk1AxisSweep
{
	public:
		struct AabbInt : public hkAabbUint32
		{
			                class MustEndWithSemiColon;
			hkpShapeKey& getShapeKey() { return m_min[3]; }
		};
};

namespace hkAlgorithm
{
	template<typename T>
	class less
	{
	};
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
	template<typename T>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize)
	{
		quickSort( pArr, iSize, less<T>() );
	}
	template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}

namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}

namespace hkVector4Util
{
	__forceinline void __cdecl convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out);
	__forceinline void __cdecl convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
	__forceinline void __cdecl uncompressExpandedAabbUint32(const hkAabbUint32& unexpandedAabbInt, hkAabbUint32& expandedAabbOut);
	extern __declspec(align(16)) float hkAabbUint32MaxVal[4];
}

inline void __cdecl hkVector4Util::convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	out[0] = static_cast<hkUint32>(hkMath::hkToIntFast(x(0)));
	out[1] = static_cast<hkUint32>(hkMath::hkToIntFast(x(1)));
	out[2] = static_cast<hkUint32>(hkMath::hkToIntFast(x(2)));
	out[3] = static_cast<hkUint32>(hkMath::hkToIntFast(x(3)));
}

inline void __cdecl hkVector4Util::convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
	;
	hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&hkVector4Util::hkAabbUint32MaxVal));
	hkVector4Util::convertToUint32WithClip( aabb.m_min, offsetLow,  scale, hkVector4::getZero(), maxVal, aabbOut.m_min );
	hkVector4Util::convertToUint32WithClip( aabb.m_max, offsetHigh, scale, hkVector4::getZero(), maxVal, aabbOut.m_max );
}

inline void __cdecl hkVector4Util::uncompressExpandedAabbUint32(const hkAabbUint32& unexpandedAabbInt, hkAabbUint32& expandedAabbOut)
{
	int shift = unexpandedAabbInt.m_expansionShift;
	hkUint32 mix = unexpandedAabbInt.m_min[0] - (unexpandedAabbInt.m_expansionMin[0] << shift);
	hkUint32 miy = unexpandedAabbInt.m_min[1] - (unexpandedAabbInt.m_expansionMin[1] << shift);
	hkUint32 miz = unexpandedAabbInt.m_min[2] - (unexpandedAabbInt.m_expansionMin[2] << shift);
	expandedAabbOut.m_min[0]= mix;
	expandedAabbOut.m_min[1]= miy;
	expandedAabbOut.m_min[2]= miz;
	hkUint32 maxx = unexpandedAabbInt.m_max[0] + (unexpandedAabbInt.m_expansionMax[0] << shift);
	hkUint32 may  = unexpandedAabbInt.m_max[1] + (unexpandedAabbInt.m_expansionMax[1] << shift);
	hkUint32 maz  = unexpandedAabbInt.m_max[2] + (unexpandedAabbInt.m_expansionMax[2] << shift);
	expandedAabbOut.m_max[0]= maxx;
	expandedAabbOut.m_max[1]= may;
	expandedAabbOut.m_max[2]= maz;
}

}

using namespace S9ceea0_;

// pdb: hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate | hkpCollectionCollectionAgent3.obj | fnv360_0822_retail, call_gap, medium, conflict (bridge: hk1AxisSweep::collide)
static int __cdecl FUN_009ceea0( const hkpCdBody* cdBody, const hkpShapeContainer* collection, const hkpProcessCollisionInput& input, hk1AxisSweep::AabbInt* aabbs, int aabbsCapacity )
{
	const int useContinuousPhysics = input.m_collisionQualityInfo->m_useContinuousPhysics;
	int numChildAabbs = 0;
	const hkpCollidable::BoundingVolumeData* bvData;
	if ( !cdBody->getParent() && (bvData = &static_cast<const hkpCollidable*>(cdBody)->m_boundingVolumeData) && bvData->m_childShapeAabbs && bvData->isValid() )
	{
		hkAabbUint32* childShapeAabbs = bvData->m_childShapeAabbs;
		for ( hkpShapeKey key = collection->getFirstKey(); key != 0xffffffff; key = collection->getNextKey( key ) )
		{
			int destIndex = ( numChildAabbs < 256 ) ? childShapeAabbs->m_sortIndex : numChildAabbs;
			hk1AxisSweep::AabbInt& aabbInt = aabbs[destIndex];
			if ( useContinuousPhysics )
			{
				hkVector4Util::uncompressExpandedAabbUint32( *childShapeAabbs, aabbInt );
			}
			else
			{
				hkString::memCpy16<sizeof(hkAabbUint32)>( &aabbInt, childShapeAabbs );
			}
			aabbInt.getShapeKey() = key;
			childShapeAabbs++;
			numChildAabbs++;
		}
		if ( numChildAabbs < 256 && !useContinuousPhysics )
		{
			goto DONT_SORT;
		}
	}
	else
	{
		char buffer[512];
		hkpAabbUtil::OffsetAabbInput sweepInput;
		if ( useContinuousPhysics )
		{
			hkpAabbUtil::initOffsetAabbInput( cdBody->getRootCollidable()->getMotionState(), sweepInput );
		}
		hkAabb rootAabb; rootAabb.setEmpty();
		for ( hkpShapeKey key = collection->getFirstKey(); key != 0xffffffff; key = collection->getNextKey( key ) )
		{
			if ( !collection->isChildEnabled( key ) )
			{
				continue;
			}
			const hkpShape* child = collection->getChildShape( key, buffer );
			hkAabb aabb;
			child->getAabb( cdBody->getTransform(), input.m_tolerance, aabb );
			if ( useContinuousPhysics )
			{
				hkpAabbUtil::sweepOffsetAabb( sweepInput, aabb, aabb );
			}
			rootAabb.m_min.setMin4( rootAabb.m_min, aabb.m_min );
			rootAabb.m_max.setMax4( rootAabb.m_max, aabb.m_max );
			hk1AxisSweep::AabbInt& aabbInt = aabbs[numChildAabbs++];
			hkVector4Util::convertAabbToUint32( aabb, input.m_aabb32Info.m_bitOffsetLow, input.m_aabb32Info.m_bitOffsetHigh, input.m_aabb32Info.m_bitScale, aabbInt );
			aabbInt.getShapeKey() = key;
		}
	}
	hkAlgorithm::quickSort( aabbs, numChildAabbs );
DONT_SORT:
	;
	return numChildAabbs;
}

int extractCaller( const hkpCdBody* cdBody, const hkpShapeContainer* collection, const hkpProcessCollisionInput& input, hk1AxisSweep::AabbInt* aabbs, int aabbsCapacity )
{
	return FUN_009ceea0( cdBody, collection, input, aabbs, aabbsCapacity );
}
