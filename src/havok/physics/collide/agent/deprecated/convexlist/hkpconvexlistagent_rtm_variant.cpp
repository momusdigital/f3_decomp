// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
}
extern void* __cdecl hkpConvexListAgent_createConvexListConvexAgent();
struct D338e0Agent
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};
inline void D338e0Agent::vf00()
{}
inline void D338e0Agent::vf04()
{}
inline void D338e0Agent::vf08()
{}
inline void D338e0Agent::vf0C()
{}
inline int D338e0Agent::vf10()
{
    return 0;
}
struct D338e0Local
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
};
extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(int*, D338e0Local*);
inline void D338e0Dispatch(D338e0Local* local, int* ownerField, int result)
{
    local->field0C = result;
    hkAgent1nMachine_UpdateShapeCollectionFilter(ownerField, local);
}
struct hkAllocatorD33D
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterD33D
{
    void* m_apvUnk00[4];
    hkAllocatorD33D* m_pkHeap;
    hkAllocatorD33D& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD33D* __cdecl FUN_00c85750() throw();
struct hkpCdBodyD33D;
struct hkpContactMgrD33D;
struct hkpCollisionInputD33D;
class hkpConvexListFilterD33D
{
  public:
    virtual ~hkpConvexListFilterD33D() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                    const hkpCollisionInputD33D& kInput) const throw();
};
struct hkpCollisionInputD33D
{
    int m_aiUnk00[4];
    hkpConvexListFilterD33D* m_pConvexListCollisionFilter;
};
class hkpCollisionAgentD33D
{
  public:
    virtual ~hkpCollisionAgentD33D() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpCollisionAgentD33D* p = (hkpCollisionAgentD33D*)FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
};
class FUN_00d33940 : public hkpCollisionAgentD33D
{
  public:
    FUN_00d33940(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, const hkpCollisionInputD33D& kInput,
                 hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x88];
};
class hkpSymmetricConvexListAgentD33D : public FUN_00d33940
{
  public:
    __forceinline hkpSymmetricConvexListAgentD33D(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                  const hkpCollisionInputD33D& kInput, hkpContactMgrD33D* pkMgr) throw()
        : FUN_00d33940(kBodyB, kBodyA, kInput, pkMgr)
    {}
    virtual ~hkpSymmetricConvexListAgentD33D() throw();
};
class FUN_00dacbd0 : public hkpCollisionAgentD33D
{
  public:
    FUN_00dacbd0(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x78];
};
class hkpPredGskfAgentD33D : public FUN_00dacbd0
{
  public:
    __forceinline hkpPredGskfAgentD33D(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                       hkpContactMgrD33D* pkMgr) throw()
        : FUN_00dacbd0(kBodyA, kBodyB, pkMgr)
    {}
    virtual ~hkpPredGskfAgentD33D() throw();
};
hkpCollisionAgentD33D* __cdecl hkpConvexListAgent_createConvexListConvexAgent(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                     const hkpCollisionInputD33D& kInput,
                                                     hkpContactMgrD33D* pkMgr) throw();
void __cdecl hkGskManifold_cleanup(void* out, void* src, void* arg);
struct hkArrayD33E
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD33E() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};
class hkCollectorBaseD347
{
  public:
    hkCollectorBaseD347() : m_bHasHit(false)
    {}
    virtual void AddHit(void* hit) = 0;

    bool m_bHasHit;
};
class hkCollectorD347 : public hkCollectorBaseD347
{
  public:
    hkCollectorD347(int filter) : m_iFilter(filter)
    {}
    virtual void AddHit(void* hit);

    int m_iFilter;
};
void __cdecl FUN_00d34790(void* b, void* a, void* c, int filter);
// @fnv 0x00d36930
// @fnv 0x00d33890
extern void __cdecl hkGskManifold_cleanup(void*, int, void*);
struct __declspec(align(16)) S00d33940_Out
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
    float x3;
    float y3;
    float z3;
    float w3;
    void FUN_00cb22f0(int a, int b);
};
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern char DAT_010cebd0;
struct HitCollector
{
    void* m_vtbl;
    bool m_bHit;
};
void __cdecl hkpGskBaseAgent_staticGetPenetrations(void* a, void* b, void* c, HitCollector* col);
void __cdecl FUN_00d34790(void* a, void* b, void* c, void* d);
// @fnv 0x00d33b90
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_01076f38[];
extern int DAT_010c476c;
extern float DAT_0104da48;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" int __cdecl hkpGskBaseAgent_staticGetPenetrations(const void* a, const void* b, const void* c, void* d);
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
struct hkVector4
{
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& other)
    {
        m_vComponents = other.m_vComponents;
        return *this;
    }
};
struct hkContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float getDistance() const
    {
        return m_vSeparatingNormal.m_vComponents.m128_f32[3];
    }
    hkContactPoint& operator=(const hkContactPoint& other)
    {
        m_vContactPosition = other.m_vContactPosition;
        m_vSeparatingNormal = other.m_vSeparatingNormal;
        return *this;
    }
};
struct RootContactPoint
{
    hkContactPoint m_kPoint;
    const void* m_pRootCollidableA;
    unsigned int m_uiShapeKeyA;
    const void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
};
struct hkpFlagCdBodyPairCollector
{
    const void* vtbl;
    bool m_flag;
    hkpFlagCdBodyPairCollector() : vtbl(&DAT_010cebd0), m_flag(false)
    {}
    bool DidHit() const
    {
        return m_flag;
    }
};
struct hkpClosestCdPointCollector
{
    const void* vtbl;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    RootContactPoint m_kHitPoint;
    RootContactPoint m_unweldedHitPoint;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollector()
    {
        m_kHitPoint.m_kPoint.m_vSeparatingNormal.m_vComponents.m128_f32[3] = DAT_0104da48;
        m_fEarlyOutDistance = DAT_0104da48;
        vtbl = &DAT_010c476c;
        m_kHitPoint.m_pRootCollidableA = 0;
    }

    bool DidHit() const
    {
        return m_kHitPoint.m_pRootCollidableA != 0;
    }
};

struct ProfileIndex
{
    unsigned long value;
    __forceinline ProfileIndex(unsigned long v) : value(v)
    {}
};
static __forceinline void* profileBuffer(const ProfileIndex& index)
{
    return TlsGetValue(index.value);
}
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_sqrt_ss(__m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_load_ss(const float*);
}
static __forceinline __m128 Splat(const float& f)
{
    __m128 r = _mm_load_ss(&f);
    return _mm_shuffle_ps(r, r, 0);
}
static __forceinline float ParseFloatValue(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}

extern void* DAT_010ceb44;
extern const char str_010ceb84[], str_010ceb7c[], str_010ceb70[], str_010ceca0[], str_01076f38[];

union Vec4
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };
};
struct L16
{
    Vec4 v;
};
struct L64
{
    L16 a, b, c, d;
};
struct L256
{
    L64 a, b, c, d;
};
struct L1024
{
    L256 a, b, c, d;
};
struct L4096
{
    L1024 a, b, c, d;
};
struct L128
{
    L64 a, b;
};
struct Arg4;
struct Shape;  // Collision-output snapshot: 0x1080 bytes consumed by the snapshot/reset methods.
struct Workspace
{
    L4096 contacts;
    L128 state;
    void __thiscall FUN_00d33670(Arg4&);
    void __thiscall FUN_00d33600(const Shape&, const Shape&, Arg4&, void*);
};

struct Obj
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
    Vec4 m_40;
    Vec4 m_50;
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
    float m_9c;
    float m_a0;
};
struct ShapeHead
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
    int count;
};
struct Shape
{
    ShapeHead* m_00;
    int unkp04;
    Obj* m_08;
    Shape* m_0c;
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
    float m_4c;
};
struct Arg3
{
    int unk00;
    int unk04;
    float m_08;
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
    float m_58;
};
struct Arg4
{
    int unkp00;
    void* m_04;
};
struct CollObj
{
    Vec4 a, b, c, d;
    void __thiscall FUN_00cb22f0(Obj*, Obj*);
};
struct SStruct
{
    void* pCo;
    void* pObjA;
    void* a0;
    void* b0;
    float f;
};
struct StackObj
{
    void* vptr;
    short unkp04;
    short m_06s;
    int kind;
    void* saved;
    char flag;
    char unkp19a;
    short unkp20;
};
struct Big
{
    const Shape* a;
    const Shape* b;
    int zero;
    const Arg3* c;
    void* agent08;
    int unkp14, unk18, unk1c;
    CollObj co;
    int p60, p64, p68, p6c;
    Vec4 vec;
};
struct D33ProfBuf
{
    int unkp00;
    char* cursor;
    int unkp08;
    char* end;
};
struct Rec16
{
    const char* name;
    unsigned int tick;
    void* unk;
    const char* name2;
};
struct Rec12
{
    const char* name;
    unsigned int tick;
    void* unk;
};

void FUN_00d33670(void* a);
void FUN_00d33600(void* a, void* b, void* c, void* d);
void* FUN_00cb22f0(void* a, void* b);
void hkpConvexListAgent_switchToGskMode(void* a);
void hkpConvexListAgent_switchToStreamMode(void* a);
void FUN_00d42020(void* a, void* b, void* c, void* d);
struct AddressValue
{
    void* value;
    __forceinline AddressValue(void* p) : value(p)
    {}
};
void FUN_00da4aa0(void* a, const void* b, AddressValue wrapped, void* d, void* e);
void hkGskManifold_cleanup(void* a, void* b, void* c);
struct ScratchArena
{
    int* cursor;
};

typedef void(__thiscall* Ws70Fn)(void*, const void*);
typedef void(__thiscall* Ws00Fn)(void*, const void*, const void*, const void*, void*);
typedef void*(__thiscall* CbFn)(void*, void*, void*);
typedef void(__thiscall* Ag1Fn)(void*, void*);
typedef void(__thiscall* Ag4Fn)(void*, const void*, const void*, const void*, void*);

struct StreamState
{
    short flags;
    char count;
    char unknown;
    int field04, field08;
    float distance;
};
struct ScalarScratch;
struct Agent
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 m_20w;
    short unkp30;
    char m_32;
    char unkp33;
    int unk34;
    int unk38;
    float m_3c;
    __forceinline StreamState& streaming()
    {
        return *reinterpret_cast<StreamState*>(&unkp30);
    }
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
    char m_84;
    char m_85;
    short m_86;
    void __thiscall hkpConvexListAgent_switchToGskMode(void*);
    void __thiscall hkpConvexListAgent_switchToStreamMode(void*);
    void __thiscall FUN_00d42020(const Shape&, const Shape&, const Arg3&, Arg4&);
    __forceinline void processCached(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, Workspace&, StackObj&,
                                     ScalarScratch&, bool&);
    void streamCollision(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, ShapeHead*);
    void __thiscall hkpConvexListAgent_processCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d);
};

__forceinline void projectDistance(Vec4& normal, const Vec4& vec)
{
    __m128 p = _mm_mul_ps(normal.quad, vec.quad);
    __m128 v = vec.quad;
    __m128 s3 = _mm_shuffle_ps(v, v, 0xff);
    __m128 s2 = _mm_shuffle_ps(p, p, 0xaa);
    __m128 s1 = _mm_shuffle_ps(p, p, 0x55);
    __m128 rr = _mm_add_ps(_mm_add_ss(s2, s3), _mm_add_ss(s1, p));
    float dot;
    _mm_store_ss(&dot, rr);
    normal.w -= dot;
}
// Keep the two rounded scale values together for x87 and SIMD consumers.
struct ScalarScratch
{
    union
    {
        float dt;
        D33ProfBuf* volatile monitor;
        float minimum;
    } first;
    union
    {
        float factor;
        volatile unsigned stamp;
    } a;
    float radius;
    union
    {
        float factor;
        volatile unsigned stamp;
    } b;
    union
    {
        ShapeHead* shape;
        volatile unsigned stamp;
    } last;
};
__forceinline void calculateMotion(const Obj& oa, const Obj& ob, ScalarScratch& scratch, Vec4& vec)
{
    scratch.a.factor = scratch.first.dt * oa.m_50.w;
    scratch.b.factor = scratch.first.dt * ob.m_50.w;
    __m128 scaleA = Splat(scratch.a.factor);
    __m128 scaleB = Splat(scratch.b.factor);
    __m128 vc = ob.m_40.quad;
    __m128 vd = ob.m_50.quad;
    __m128 va = oa.m_40.quad;
    __m128 vb = oa.m_50.quad;
    vec.quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(vd, vc), scaleB), _mm_mul_ps(_mm_sub_ps(va, vb), scaleA));
    vec.w = oa.m_9c * scratch.a.factor * oa.m_a0 + ob.m_9c * scratch.b.factor * ob.m_a0;
}

__forceinline void Agent::streamCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                          ShapeHead* bHead)
{
    Big big;
    big.zero = 0;
    big.a = &a;
    big.b = &b;
    big.agent08 = m_08;
    __m128 motion = vec.quad;
    big.c = &c;
    big.vec.quad = motion;
    big.co.FUN_00cb22f0(a.m_08, b.m_08);
    int count = bHead->count;
    ScratchArena* pool = (ScratchArena*)FUN_00c85750();
    int* arr = pool->cursor;
    pool->cursor = (int*)((unsigned int)arr + (((unsigned int)(count * 4 + 4) + 0x7f) & ~0x7f));
    for (int i = 0; i < count; i++)
        arr[i] = i;
    arr[count] = -1;
    FUN_00da4aa0(&streaming(), &big, AddressValue(&bHead->unk14), arr, &d);
    ScratchArena* pool2 = (ScratchArena*)FUN_00c85750();
    pool2->cursor = arr;
}
__forceinline void Agent::processCached(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                        Workspace& ws, StackObj& so, ScalarScratch& scratch, bool& retry)
{
    if (m_20w.w > c.m_08)
    {
        projectDistance(m_20w, vec);
        if (m_20w.w > c.m_08)
        {
            if (m_32 != 0)
                hkGskManifold_cleanup(&unkp30, m_08, d.m_04);
            return;
        }
    }
    {
        D33ProfBuf* pBuf;
        pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c);
        scratch.first.monitor = pBuf;
        Rec12* pRec = (Rec12*)pBuf->cursor;
        if (pRec < (Rec12*)pBuf->end)
        {
            pRec->name = str_010ceca0;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.a.stamp;
            scratch.first.monitor->cursor = (char*)(pRec + 1);
        }
        so.kind = 2;
        so.m_06s = 1;
        so.vptr = &DAT_010ceb44;
        so.flag = 0;
        so.saved = m_08;
        m_08 = &so;
        FUN_00d42020(a, b, c, d);
        m_08 = so.saved;
        if (so.flag == 0)
        {
            if (m_32 == 0)
                return;
            if (m_85 != 0)
                return;
            const Shape* pa = &b;
            while (pa->m_0c)
                pa = pa->m_0c;
            scratch.radius = pa->m_4c;
            const Shape* pb = &a;
            while (pb->m_0c)
                pb = pb->m_0c;
            scratch.first.minimum = pb->m_4c;
            double cachedDistance;
            if (scratch.first.minimum < scratch.radius)
            {
                scratch.first.minimum = (const float&)(scratch.first.minimum * 1.0f);
                cachedDistance = m_20w.w;
            }
            else
            {
                scratch.first.minimum = scratch.radius;
                cachedDistance = m_20w.w;
            }
            scratch.radius = 2.0f * scratch.first.minimum;
            if (!(cachedDistance < -scratch.radius))
                return;
        }
        ws.FUN_00d33600(a, b, d, m_08);
        hkpConvexListAgent_switchToStreamMode(d.m_04);
        retry = true;
        return;
    }
}
// @f3 0x009bdcf0 (community match, verified in this file)
#include <math.h>
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
extern const char DAT_00e7ed64[], DAT_00e7ed5c[], DAT_00e7ed50[], DAT_00e7ee88[];
extern void* DAT_00e7ed28;
namespace n9bdcf0
{
struct __declspec(align(16)) VFO {
 float x,y,z,w;
 __forceinline VFO() {}
 __forceinline VFO(const VFO& v) : x(v.x),y(v.y),z(v.z),w(v.w) {}
 __forceinline float& at(int i) { return reinterpret_cast<float*>(this)[i]; }
 __forceinline const float& at(int i) const { return reinterpret_cast<const float*>(this)[i]; }
 __forceinline void operator=(const VFO& v) {
  x=v.x; y=v.y; z=v.z; w=v.w;
 }
 __forceinline void difference(const Vec4& a, const Vec4& b) {
  x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w;
 }
 __forceinline void scale(float f, const VFO& a) {
  x=f*a.x; y=f*a.y; z=f*a.z; w=f*a.w;
 }
 __forceinline void accumulate(float f, const VFO& a) {
  x+=f*a.x; y+=f*a.y; z+=f*a.z; w+=f*a.w;
 }
 __forceinline float length() const {
  float ax=x,by=y,cz=z;
  return sqrtf((ax*ax+by*by)+cz*cz);
 }
 __forceinline float project(const VFO& n) const {
  return (x*n.x+y*n.y)+z*n.z+w;
 }
};
struct BigFO {
 const Shape* a;
 const Shape* b;
 const Arg3* c;
 void* agent08;
 CollObj co;
 int unk50, unk54, unk58, unk5c;
 VFO vec;
};
struct WorkspaceFO {
 void FUN_009bd4a0(Arg4&);
 void FUN_009bd1a0(const Shape&,const Shape&,Arg4&,void*);
};
struct CollFO { void FUN_00925300(Obj*,Obj*); };
struct AgentFO {
 void FUN_009bd610(void*);
 void FUN_009bdca0(void*);
 void FUN_009cc920(const Shape&,const Shape&,const Arg3&,Arg4&);
};
struct ScratchFO {
 virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10();
 virtual void* allocate(int);
 virtual void release(void*);
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int* cursor;
 int* unk24;
 int* block;
 int* end;
};
}
extern "C" int FUN_00a345e0(SStruct*,void*,void*,void*);
extern "C" void __cdecl FUN_00a2b910(void*,int,const void*,void*,int*,void*);
namespace n9bdcf0
{
static __forceinline void motionFO(const Obj& a,const Obj& b,float dt,VFO& v) {
 VFO da,db;
 da.difference(a.m_40,a.m_50);
 db.difference(b.m_50,b.m_40);
 float f0=dt*a.m_50.w;
 float f1=dt*b.m_50.w;
 v.scale(f0,da);
 v.accumulate(f1,db);
 v.at(3)=f0*a.m_9c*a.m_a0+f1*b.m_9c*b.m_a0;
}
static __forceinline void projectFO(Vec4& n,const VFO& v) {
 float dot=v.project(*reinterpret_cast<const VFO*>(&n));
 n.w-=dot;
}
static __forceinline float minimumFO(float a,float b) { return a<b?a:b; }
static __forceinline bool cachedFO(Agent* self,const Shape& a,const Shape& b,const Arg3& c,Arg4& d,const VFO& vec,Workspace& ws) {
{
 bool beyond=self->m_20w.w>*(const float*)&c.unk04;
 if(beyond) {projectFO(self->m_20w,vec); beyond=self->m_20w.w>*(const float*)&c.unk04;}
 if(beyond) {if(self->m_32) hkGskManifold_cleanup(&self->unkp30,self->m_08,d.m_04); return false;}
 }
 {
  {
   D33ProfBuf* p=(D33ProfBuf*)DAT_00d9b080(DAT_0126835c);
   Rec12* r=(Rec12*)p->cursor;
   if(r<(Rec12*)p->end) {
    r->name=DAT_00e7ee88;
    unsigned ticks;
    __asm {
     rdtsc
     mov dword ptr[ticks], eax
    }
    r->tick=ticks;
    p->cursor=(char*)(r+1);
   }
  }
  StackObj manager;
  manager.m_06s=1; manager.kind=2;
  manager.vptr=&DAT_00e7ed28; manager.flag=0;
  manager.saved=self->m_08;
  self->m_08=&manager;
  ((AgentFO*)self)->FUN_009cc920(a,b,c,d);
  self->m_08=manager.saved;
  if(!manager.flag) {
   if(!self->m_32 || self->m_85) return false;
   const Shape* pa=&b;
   while(pa->m_0c) pa=pa->m_0c;
   float radB=*(const float*)&pa->unk48;
   const Shape* pb=&a;
   while(pb->m_0c) pb=pb->m_0c;
   float radA=*(const float*)&pb->unk48;
   float pen=2.0f*minimumFO(radA,radB);
   if(!(self->m_20w.w < -pen)) return false;
  }
  ((WorkspaceFO*)&ws)->FUN_009bd1a0(a,b,d,self->m_08);
  ((AgentFO*)self)->FUN_009bdca0(d.m_04);
  return true;
 }
}
}
// pdb: hkpConvexListAgent::processCollision | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(vtable_prefix), high
void __thiscall Agent::hkpConvexListAgent_processCollision(const Shape& a,const Shape& b,const Arg3& c,Arg4& d) {
 Workspace ws;
 n9bdcf0::BigFO big;
 CollObj co;
 const ShapeHead* head;
 n9bdcf0::VFO vec;
 {
  D33ProfBuf* p=(D33ProfBuf*)DAT_00d9b080(DAT_0126835c);
  Rec16* r=(Rec16*)p->cursor;
  if(r<(Rec16*)p->end) {
   r->name=DAT_00e7ed64; r->name2=DAT_00e7ed5c;
   unsigned ticks;
   __asm {
    rdtsc
    mov dword ptr[ticks], eax
   }
   r->tick=ticks;
   p->cursor=(char*)(r+1);
  }
 }
 head=b.m_00;
 n9bdcf0::motionFO(*a.m_08,*b.m_08,c.m_58,vec);
 ((n9bdcf0::WorkspaceFO*)&ws)->FUN_009bd4a0(d);
 if(m_84) goto project;
stream: {
  D33ProfBuf* p=(D33ProfBuf*)DAT_00d9b080(DAT_0126835c);
  Rec12* r=(Rec12*)p->cursor;
  if(r<(Rec12*)p->end) {
   r->name=DAT_00e7ed50;
   unsigned ticks;
   __asm {
    rdtsc
    mov dword ptr[ticks], eax
   }
   r->tick=ticks;
   p->cursor=(char*)(r+1);
  }
  if(m_86--<0) {
   m_86=25;
   SStruct query;
   n9bdcf0::VFO point;
   ((n9bdcf0::CollFO*)&co)->FUN_00925300(a.m_08,b.m_08);
   query.a0=a.m_00; query.b0=b.m_00;
   query.pCo=&co; query.pObjA=a.m_08;
   query.f=*(const float*)&c.unk04;
   if(!FUN_00a345e0(&query,&m_0c,&m_20w,&point)) {
    streaming().distance=-m_20w.w;
    goto sqrtpath;
   }
   ((n9bdcf0::AgentFO*)this)->FUN_009bd610(d.m_04);
   ((n9bdcf0::WorkspaceFO*)&ws)->FUN_009bd1a0(a,b,d,m_08);
  } else goto sqrtpath;
 }
project:
 if(n9bdcf0::cachedFO(this,a,b,c,d,vec,ws)) goto stream;
 goto tail;
sqrtpath: {
  float& distance=streaming().distance;
  distance-=vec.length();
  Obj* motionA=a.m_08;
  Obj* motionB=b.m_08;
  big.a=&a; big.b=&b; big.agent08=m_08; big.c=&c;
  big.vec=vec;
  ((n9bdcf0::CollFO*)&big.co)->FUN_00925300(motionA,motionB);
  int count=head->count;
  n9bdcf0::ScratchFO* pool=(n9bdcf0::ScratchFO*)DAT_00d9b080(DAT_010f3170);
  int bytes=(count*4+20)&~15;
  int* arr=pool->cursor;
  int* next=(int*)((char*)arr+bytes);
  if(next<=pool->end) pool->cursor=next;
  else arr=(int*)pool->allocate(bytes);
  for(int i=0;i<count;++i) arr[i]=i;
  arr[count]=-1;
  FUN_00a2b910(&streaming(),0,&big,(void*)&head->unk14,arr,&d);
  pool=(n9bdcf0::ScratchFO*)DAT_00d9b080(DAT_010f3170);
  pool->cursor=arr;
  if(arr==pool->block) pool->release(arr);
 }
tail:
 m_85=1;
 {
  D33ProfBuf* p=(D33ProfBuf*)DAT_00d9b080(DAT_0126835c);
  Rec12* r=(Rec12*)p->cursor;
  if(r<(Rec12*)p->end) {
   r->name=str_01076f38;
   unsigned ticks;
   __asm {
    rdtsc
    mov dword ptr[ticks], eax
   }
   r->tick=ticks;
   p->cursor=(char*)(r+1);
  }
 }
}

