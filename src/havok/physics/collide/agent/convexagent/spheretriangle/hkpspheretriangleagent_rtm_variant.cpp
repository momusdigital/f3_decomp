// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct D3DD50CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D3DD50CollectorBase() : m_bFound(false) {}
};
struct D3DD50Collector : D3DD50CollectorBase {
    int m_iData;

    D3DD50Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
struct hkMemory {
    virtual void unk0();
    virtual void* allocateChunk(int size);
};
struct hkThreadMemory {
    char pad[0x10];
    hkMemory* m_pMemoryAllocator;

    void* allocateChunk(int size) {
        return m_pMemoryAllocator->allocateChunk(size);
    }
};
extern "C" void __cdecl FUN_00cd7160(void* src, void* dst);
extern "C" const void* DAT_010cf060;
extern "C" const void* DAT_010cf09c;
struct TargetAgent {
    const void* vtable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pContactManager;
    unsigned short m_padC;
    short m_padE;
    char m_pAccessManager[0x10];

    TargetAgent(const void* bodyA, void* mgr)
        : m_usMemSizeAndFlags(0x20),
          m_sReferenceCount(1),
          m_pContactManager(mgr),
          m_padC(0xffff)
    {
        vtable = &DAT_010cf060;
        void* triangle = *(void**)bodyA;
        FUN_00cd7160((char*)triangle + 0x20, m_pAccessManager);
        vtable = &DAT_010cf09c;
    }
};
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void setBroadcast3(const hkVector4q& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff); }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
    __forceinline void xor4(const hkVector4q& b) { m_vComponents = _mm_xor_ps(m_vComponents, b.m_vComponents); }
    __forceinline void setXor4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_xor_ps(a.m_vComponents, b.m_vComponents); }
};
template <typename T>
__forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
unsigned __int64 __rdtsc();
void _ReadWriteBarrier();
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_unpacklo_ps(__m128, __m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_movelh_ps(__m128, __m128);
__m128 _mm_movehl_ps(__m128, __m128);
}
extern "C" DWORD DAT_0126835c;
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};
struct Res {
    Vec4 pt;
    float d;
};
struct XForm {
    __m128 r0;
    __m128 r1;
    __m128 r2;
    __m128 t;
};
struct BodyB {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct BodyHolderB {
    BodyB* obj;
    int unk04;
    XForm* xf;
};
struct Sink {
    virtual void unk00();
    virtual void unk04(BodyHolderB& a, BodyHolderB& b);
};
extern void __cdecl FUN_00cd7850(Vec4* v, void* tri, float* f, Res* out, void* flag);
// non-POD 1-dword wrapper params: block the entry-enregister pass so the
// params are read lazily from their incoming arg slots (see e2fbc0)
struct BHWrap {
    BodyHolderB* p;
    BHWrap(BodyHolderB* q) : p(q) {}
};
struct SinkWrap {
    Sink* p;
    SinkWrap(Sink* q) : p(q) {}
};
// rotate the translation difference by the inverse of B's rotation (HK_TRANSPOSE3), compute the
// closest point, and report a contact when the distance is below the summed radii.
extern DWORD DAT_0126835c;
// "TtSphereTri"
// "Et"
struct __declspec(align(16)) S_00d3d3e0_V4 {
    float x, y, z, w;
};
struct S_00d3d3e0_Mat {
    S_00d3d3e0_V4 r0, r1, r2, t;
};
struct S_00d3d3e0_Shape {
    int unk00, unk04, unk08, unk0c;
    float f10;
};
struct S_00d3d3e0_Obj {
    int unk00, unk04, unk08, unk0c;
    float f10;
    int unk14, unk18, unk1c;
    int unk20;
};
struct S_00d3d3e0_P1 {
    S_00d3d3e0_Shape* shape;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P2 {
    S_00d3d3e0_Obj* obj;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P3 {
    virtual void v0();
    virtual void v1(S_00d3d3e0_P1* a, S_00d3d3e0_P2* b);
};
struct __declspec(align(16)) S_00d3d3e0_Out {
    int unk00, unk04, unk08, unk0c;
    float f10;
};
void __cdecl FUN_00cd7160(void* a, S_00d3d3e0_V4* out);
void __cdecl FUN_00cd7850(S_00d3d3e0_V4* a, void* b, S_00d3d3e0_V4* c, S_00d3d3e0_Out* d, bool* e);
struct S_00d3d3e0_P1P { S_00d3d3e0_P1* p; S_00d3d3e0_P1* val() const { return p; } };
struct S_00d3d3e0_P2P { S_00d3d3e0_P2* p; S_00d3d3e0_P2* val() const { return p; } };
struct S_00d3d3e0_P3P { S_00d3d3e0_P3* p; S_00d3d3e0_P3* val() const { return p; } };

extern "C" __m128 _mm_load_ss(float const*_A);
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
unsigned __int64 __rdtsc();
void _ReadWriteBarrier();
__m128 _mm_load_ss(const float*);
}
struct __declspec(align(16)) S00d3d6b0_Vec4 { float x,y,z,w; };
struct S00d3d6b0_Res { S00d3d6b0_Vec4 pt; float d; };
struct S00d3d6b0_ProfRec { const char* name; unsigned int tsc; unsigned int unk08; };
struct S00d3d6b0_ProfBuf { unsigned int unk00; S00d3d6b0_ProfRec* cur; unsigned int unk08; S00d3d6b0_ProfRec* end; };
struct S00d3d6b0_XForm { S00d3d6b0_Vec4 r0,r1,r2,t; };
struct S00d3d6b0_BodyB {
    int unk00,unk04,unk08,unk0C;
    float radius;
    int unk14,unk18,unk1C;
    S00d3d6b0_Vec4 vertices[3];
};
struct S00d3d6b0_BodyHolderB { S00d3d6b0_BodyB* obj; int unk04; S00d3d6b0_XForm* xf; };
struct S00d3d6b0_HitInfo { S00d3d6b0_Vec4 pt,nrm; S00d3d6b0_BodyHolderB* a; S00d3d6b0_BodyHolderB* b; };
// hkpCdPointCollector: its two Fallout 3 slots (0x00de6e68), with the New Vegas Xbox 360 PDB's names.
struct S00d3d6b0_Sink { virtual ~S00d3d6b0_Sink(); virtual void addCdPoint(S00d3d6b0_HitInfo*); };
struct S00d3d6b0_Input { int unk00,unk04; float tolerance; };
extern void __cdecl FUN_00cd7850(S00d3d6b0_Vec4* v, void* tri, float* f, S00d3d6b0_Res* out, void* flag);
class S00d3d6b0_SphereTriAgent {
public:
    int unk00,unk04,unk08,unk0C;
    float unk10;
    void hkpSphereTriangleAgent_getClosestPoints(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, S00d3d6b0_Sink* sink);
};
// @f3 0x009c74a0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7f23c[], DAT_00e32798[];
namespace f3m_009c74a0 {
struct DeadFloats { float f0; float f1; float f2; float f3; float f4; __forceinline void operator=(const DeadFloats& o) { f0 = o.f0; f1 = o.f1; f2 = o.f2; f3 = o.f3; f4 = o.f4; } };
struct NativeSphereInput { int unknown00; float tolerance; };
struct __declspec(align(16)) NativeFloat4 {
    float x, y, z, w;
    __forceinline NativeFloat4() {}
    __forceinline void operator=(const NativeFloat4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float& operator()(int i) { if(i==0)return x;if(i==1)return y;if(i==2)return z;return w; }
    __forceinline const float& operator()(int i) const { if(i==0)return x;if(i==1)return y;if(i==2)return z;return w; }
};
struct NativeMat3 {
    NativeFloat4 m_col0, m_col1, m_col2;
    __forceinline NativeFloat4& getColumn(int i) { if(i==0)return m_col0;if(i==1)return m_col1;return m_col2; }
    __forceinline const NativeFloat4& getColumn(int i) const { if(i==0)return m_col0;if(i==1)return m_col1;return m_col2; }
    __forceinline float& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};
struct __declspec(align(16)) NativeRot : public NativeMat3 {};
struct NativeTransform {
    NativeRot m_rotation;
    NativeFloat4 m_translation;
    __forceinline NativeTransform(const NativeTransform& t) {
        const NativeFloat4 r0 = t.m_rotation.getColumn(0);
        const NativeFloat4 r1 = t.m_rotation.getColumn(1);
        const NativeFloat4 r2 = t.m_rotation.getColumn(2);
        const NativeFloat4 r3 = t.m_translation;
        m_rotation.getColumn(0) = r0;
        m_rotation.getColumn(1) = r1;
        m_rotation.getColumn(2) = r2;
        m_translation = r3;
    }
    __forceinline const NativeRot& getRotation() const { return m_rotation; }
    __forceinline const NativeFloat4& getTranslation() const { return m_translation; }
};
struct Scalar977 {
    float value;
    __forceinline Scalar977(float v):value(v){}
    __forceinline double ReadProduct(const float& c) const {return c*value;}
    friend __forceinline double operator*(float c,const Scalar977& s){return s.value*c;}
};
__forceinline void NativeTransformPoints(const NativeTransform& transform, const NativeFloat4* source, NativeFloat4* destination, int count) {
    NativeTransform unaliased = transform;
    int i = count - 1;
    do {
        const NativeFloat4& b = source[i];
        NativeFloat4& t = destination[i];
        const NativeRot& r = unaliased.getRotation();
        const NativeFloat4& tr = unaliased.getTranslation();
        Scalar977 v0(b(0));
        Scalar977 v1(b(1));
        Scalar977 v2(b(2));
        t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + tr(0);
        t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + tr(1);
        t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + tr(2);
        t(3) = 0;
    } while (--i >= 0);
}
static __forceinline bool GetSphereTriHit(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, float* cache, S00d3d6b0_HitInfo& hit);
}
void hkpCollideTriangleUtil_closestPointTriangle(S00d3d6b0_Vec4*, const void*, float*, S00d3d6b0_Res*);
static __forceinline bool f3m_009c74a0::GetSphereTriHit(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, float* cache, S00d3d6b0_HitInfo& hit) {
    S00d3d6b0_BodyB* shapeA = a->obj;
    S00d3d6b0_BodyB* shapeB = b->obj;
    S00d3d6b0_Vec4* center = &a->xf->t;
    NativeFloat4 tri[3];
    if (0) { DeadFloats d0; DeadFloats u0 = *reinterpret_cast<const DeadFloats*>(input); d0 = u0; }
    NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(b->xf), reinterpret_cast<const NativeFloat4*>(shapeB->vertices), tri, 3);
    S00d3d6b0_Res out;
    hkpCollideTriangleUtil_closestPointTriangle(center, tri, cache, &out);
    float sum = shapeA->radius + shapeB->radius;
    float distance = out.d;
    float threshold = reinterpret_cast<const NativeSphereInput*>(input)->tolerance + sum;
    if (distance < threshold) {
        float delta = shapeB->radius - distance;
        hit.pt.x = out.pt.x * delta + center->x;
        hit.pt.y = out.pt.y * delta + center->y;
        hit.pt.z = out.pt.z * delta + center->z;
        hit.pt.w = out.pt.w * delta + center->w;
        hit.nrm.x = out.pt.x;
        hit.nrm.y = out.pt.y;
        hit.nrm.z = out.pt.z;
        hit.nrm.w = distance - sum;
        return true;
    }
    return false;
}
// pdb: hkpSphereTriangleAgent::getClosestPoints | hkpSphereTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S00d3d6b0_SphereTriAgent::hkpSphereTriangleAgent_getClosestPoints(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, S00d3d6b0_Sink* sink)
{
    using namespace f3m_009c74a0;
    {
        S00d3d6b0_ProfBuf* buffer = static_cast<S00d3d6b0_ProfBuf*>(TlsGetValue(DAT_0116913c));
        S00d3d6b0_ProfRec* record = buffer->cur;
        if (record < buffer->end) {
            record->name = DAT_00e7f23c;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            record->tsc = tick;
            buffer->cur = record + 1;
        }
    }
    S00d3d6b0_HitInfo hit;
    hit.a = a;
    hit.b = b;
    if (GetSphereTriHit(a, b, input, &unk10, hit)) {
        sink->addCdPoint(&hit);
    }
    {
        S00d3d6b0_ProfBuf* buffer = static_cast<S00d3d6b0_ProfBuf*>(TlsGetValue(DAT_0116913c));
        S00d3d6b0_ProfRec* record = buffer->cur;
        if (record < buffer->end) {
            record->name = DAT_00e32798;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            record->tsc = tick;
            buffer->cur = record + 1;
        }
    }
}


extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_load_ss(const float*);
}

struct Transform;

struct FourFloatVector {
    union { __m128 m; float f[4]; };
    __forceinline void operator=(const FourFloatVector& rhs) { m = rhs.m; }
    __forceinline void transformed(const Transform& t, const FourFloatVector& v);
    __forceinline void addScaled(const FourFloatVector& base, const FourFloatVector& direction, float amount) {
        __m128 scalar = _mm_load_ss(&amount);
        scalar = _mm_shuffle_ps(scalar, scalar, 0);
        m = _mm_add_ps(base.m, _mm_mul_ps(scalar, direction.m));
    }
    __forceinline float& component(int n) { return f[n]; }

};

struct Transform {
    FourFloatVector col0;
    FourFloatVector col1;
    FourFloatVector col2;
    FourFloatVector translation;
    __forceinline Transform(const Transform& rhs) {
        const FourFloatVector c0 = rhs.col0, c1 = rhs.col1, c2 = rhs.col2, c3 = rhs.translation;
        col0 = c0; col1 = c1; col2 = c2; translation = c3;
    }
};

struct Shape;
struct CdBody {
    Shape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    Transform* m_kMotionState;
    Shape* shape() const { return m_pCollisionShape; }
    const Transform& transform() const { return *m_kMotionState; }
};

struct Shape {
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
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual int weldContactPoint(void* a1, void* a2, void* a3, const void* a4, const void* a5, const void* a6, void* a7);

    float m_fSphereRadius;
    int pad14;
    int pad18;
    int pad1C;
    FourFloatVector m_kVertices[3];
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

extern "C" int __cdecl FUN_00cd7850(
    const void* spherePos,
    const void* vertices,
    void* cache,
    void* output,
    void* weldFlag
);

extern "C" __m128 _mm_load_ss(const float*);
static __forceinline __m128 PlainBroadcast(const float& f) {
 __m128 t=_mm_load_ss(&f); return _mm_shuffle_ps(t,t,0);
}


struct __declspec(align(16)) S_00d3d520_V4 {
    float x, y, z, w;
    __m128& q() { return reinterpret_cast<__m128&>(*this); }
    const __m128& q() const { return reinterpret_cast<const __m128&>(*this); }
};

struct S_00d3d520_Col {
    float x, y, z, w;
};

struct S_00d3d520_T {
    S_00d3d520_Col c0;
    S_00d3d520_Col c1;
    S_00d3d520_Col c2;
    S_00d3d520_Col c3;
};

static __forceinline void S_00d3d520_Xform(S_00d3d520_V4& out, const S_00d3d520_Col& c0, const S_00d3d520_Col& c1, const S_00d3d520_Col& c2, const S_00d3d520_Col& c3, const S_00d3d520_V4& b)
{
    const __m128 xb = _mm_shuffle_ps(b.q(), b.q(), 0x00);
    const __m128 yb = _mm_shuffle_ps(b.q(), b.q(), 0x55);
    const __m128 zb = _mm_shuffle_ps(b.q(), b.q(), 0xaa);
    const __m128 t0 = _mm_mul_ps(xb, *(const __m128*)&c0);
    const __m128 t1 = _mm_mul_ps(yb, *(const __m128*)&c1);
    const __m128 t2 = _mm_mul_ps(zb, *(const __m128*)&c2);
    out.q() = _mm_add_ps(_mm_add_ps(t1, t0), _mm_add_ps(t2, *(const __m128*)&c3));
}

static __forceinline void S_00d3d520_TransformPoints(const S_00d3d520_T& t, const S_00d3d520_V4* in, S_00d3d520_V4* out)
{
    S_00d3d520_Col c0 = t.c0;
    S_00d3d520_Col c1 = t.c1;
    S_00d3d520_Col c2 = t.c2;
    S_00d3d520_Col c3 = t.c3;
    int i = 2;
    do {
        S_00d3d520_Xform(out[i], c0, c1, c2, c3, in[i]);
    } while (--i >= 0);
}

struct S_00d3d520_Shape {
    int unk00, unk04, unk08, unk0c;
    float radius;
    int unk14, unk18, unk1c;
    S_00d3d520_V4 verts[3];
};

struct S_00d3d520_Body {
    S_00d3d520_Shape* shape;
    int unk04;
    S_00d3d520_T* motion;
};

struct S_00d3d520_A {
    S_00d3d520_Shape* shape;
    int unk04;
    S_00d3d520_V4* pos;
};

struct S_00d3d520_Info {
    int unk00;
    int unk04;
    float distance;
};

struct __declspec(align(16)) S_00d3d520_Res {
    S_00d3d520_V4 normal;
    float dist;
};

struct S_00d3d520_Out { S_00d3d520_V4 point; union { S_00d3d520_V4 normal; struct {float nx,ny,nz; volatile float distance;}; }; };

int __cdecl FUN_00cd7850(const S_00d3d520_V4* pos, const S_00d3d520_V4* tri, int a4, S_00d3d520_Res* out, char* flag);

// @f3 0x009c7290 (community match, verified in this file)
struct S_00d3d520_Tol { int unk00; float distance; };

int __cdecl hkpCollideTriangleUtil_closestPointTriangle(const S_00d3d520_V4* pos, const S_00d3d520_V4* tri, int a4, S_00d3d520_Res* out);

struct TransformScalar974 {
    float value;
    __forceinline double ReadProduct(const float& component) const { return component * value; }
    __forceinline TransformScalar974(float v) : value(v) {}
    friend __forceinline double operator*(float component, const TransformScalar974& scalar) { return scalar.value * component; }
};

static __forceinline void TransformVertex(
    S_00d3d520_V4& out, const S_00d3d520_V4& vertex,
    const S_00d3d520_Col& c0, const S_00d3d520_Col& c1,
    const S_00d3d520_Col& c2, const S_00d3d520_Col& c3)
{
    const TransformScalar974 x(vertex.x);
    const TransformScalar974 y(vertex.y);
    const TransformScalar974 z(vertex.z);
    const double xx = c0.x * x;
    const double xy = c0.y * x;
    const double xz = c0.z * x;
    const double yx = c1.x * y;
    const double yy = c1.y * y;
    const double yz = c1.z * y;
    out.x = static_cast<float>(yx + xx + c2.x * z + c3.x);
    out.y = static_cast<float>(yy + xy + z.ReadProduct(c2.y) + c3.y);
    out.z = static_cast<float>(yz + xz + c2.z * z + c3.z);
    out.w = 0.0f;
}
// pdb: hkpSphereTriangleAgent::getClosestPoint | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, cache, cpoint
int __cdecl FUN_00d3d520(S_00d3d520_A* a, S_00d3d520_Body* b, S_00d3d520_Info* info, int a4, S_00d3d520_Out* outp)
{
    S_00d3d520_Shape* sphere = a->shape;
    S_00d3d520_Shape* tri = b->shape;
    const S_00d3d520_V4* center = a->pos + 3;
    const S_00d3d520_T& t = *b->motion;
    struct {
        union {
            S_00d3d520_Col c3;
            S_00d3d520_Res contact;
        };
    } scratch;
    S_00d3d520_Col c0 = t.c0;
    const S_00d3d520_Col c1 = t.c1;
    const S_00d3d520_Col c2 = t.c2;
    scratch.c3 = t.c3;
    S_00d3d520_V4 v[3];
    int i = 2;
    do {
        TransformVertex(v[i], tri->verts[i], c0, c1, c2, scratch.c3);
    } while (--i >= 0);

    S_00d3d520_Res& pen = scratch.contact;
    int r = hkpCollideTriangleUtil_closestPointTriangle(center, v, a4, &pen);
    float k = sphere->radius + tri->radius;

    float thr = reinterpret_cast<const S_00d3d520_Tol*>(info)->distance + k;
    if (pen.dist < thr) {
        S_00d3d520_Out* o = outp;
        float res = tri->radius - pen.dist;
        double separation = pen.dist - k;
        volatile float* distance = &o->distance;
        const float nx = pen.normal.x;
        const float ny = pen.normal.y;
        const float nz = pen.normal.z;
        const float nw = pen.normal.w;
        o->point.x = nx * res + center->x;
        o->point.y = ny * res + center->y;
        o->point.z = nz * res + center->z;
        o->point.w = nw * res + center->w;
        o->normal.x = nx;
        o->normal.y = ny;
        o->normal.z = nz;
        o->normal.w = nw;
        *distance = (float)separation;
        return 1 + (r != 0);
    }
    return 0;
}

