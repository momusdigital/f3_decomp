#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void FUN_00d3a8c0();
void FUN_00d3a280();
void FUN_00daf8e0();

void __cdecl CreateAllocatedObject();
void __cdecl FUN_00d3ac80();
void __cdecl FUN_00d3b1a0();
void __cdecl FUN_00d3b220();

// @fnv 0x00d3ab90
// pdb: hkpCapsuleTriangleAgent::initAgentFuncInverse | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun + bridge(call_gap|objrun) + skyrim(call_seq), high
void __cdecl hkpCapsuleTriangleAgent_initAgentFuncInverse(void** apTable)
{
    apTable[0] = (void*)&CreateAllocatedObject;
    apTable[1] = (void*)&FUN_00d3b1a0;
    apTable[2] = (void*)&FUN_00d3b220;
    apTable[3] = (void*)&FUN_00d3ac80;
    ((unsigned char*)apTable)[0x10] = 1;
    ((unsigned char*)apTable)[0x11] = 0;
}

void __cdecl FUN_00d3ac80();
void __cdecl FUN_00daf8e0();

typedef void (__cdecl *S_00d389f0_Func)();

struct ReceiverBase { virtual void Release(unsigned int value); int unk04; };
struct NoteDispatcher {
    virtual void Unknown00(unsigned int, void*);
    virtual void Unknown04(unsigned int, void*);
    virtual void Unknown08(unsigned int, void*);
    virtual void Unknown0C(unsigned int, void*);
    virtual void Unknown10(unsigned int, void*);
    virtual void Dispatch(unsigned int id, void* value);
};
struct FUN_00d39930_class : ReceiverBase {
    NoteDispatcher* dispatcher;
    unsigned short receiverIds[3];
    void __thiscall hkpCapsuleTriangleAgent_cleanup(void* value);
};
// Dispatches value to each non-0xFFFF receiver id via dispatcher, then releases this if non-null.
// @fnv 0x00d39930
// pdb: hkpCapsuleTriangleAgent::cleanup | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: constraintOwner
// pdb: hkpCapsuleTriangleAgent::cleanup | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable, high (was: DispatchToReceivers)
void FUN_00d39930_class::hkpCapsuleTriangleAgent_cleanup(void* value)
{
    unsigned short* id = receiverIds;
    int count = 3;
    do {
        unsigned int current = *id;
        if ((unsigned short)current != 0xFFFF)
            dispatcher->Dispatch(current, value);
        ++id;
    } while (--count != 0);
    if (this)
        Release(1);
}

extern const int DAT_010ce7fc;

struct CallbackState {
    const int* m_pIntegerValue;
    float m_fFirstLightParameter;
    int m_iValue;
};

void __cdecl FUN_00d3a280(void* apFirst, void* apSecond, void* apThird,
                          CallbackState* apState);

// Builds a CallbackState with a max float, the given value and a constant pointer, then passes it to FUN_00d3a280 with the three pointers reordered.
// @fnv 0x00d3b220
// pdb: hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticGetClosestPoints | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d3b220(void* apOne, void* apTwo, void* apThree, int aiValue)
{
    CallbackState kState;
    kState.m_fFirstLightParameter = 3.40282e+38f;
    kState.m_iValue = aiValue;
    kState.m_pIntegerValue = &DAT_010ce7fc;
    FUN_00d3a280(apTwo, apOne, apThree, &kState);
}

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

void __cdecl ComputeInverseLengths(void* value, void* self);

extern char DAT_010ceefc[];
extern char DAT_010cef38[];

struct FUN_00d39980_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
    unsigned short m_w0E;
    unsigned short m_w10;
    unsigned short m_w12;
    void* m_sub;
};

// @fnv 0x00d39980
FUN_00d39980_cls* __cdecl CreateAllocatedObject(int a1, int a2, int a3, int a4)
{
    AllocHolder* pAllocHolder = FUN_00c85750();
    FUN_00d39980_cls* pObject = (FUN_00d39980_cls*)pAllocHolder->m_pAllocator->Alloc(0x28);
    pObject->m_w04 = 0x28;
    pObject->m_w06 = 1;
    pObject->m_i08 = a4;
    pObject->m_w0C = 0xffff;
    pObject->m_w0E = 0xffff;
    pObject->m_w10 = 0xffff;
    pObject->m_vptr = DAT_010ceefc;
    ComputeInverseLengths((void*)(*(int*)a1 + 0x20), &pObject->m_sub);
    pObject->m_vptr = DAT_010cef38;
    return pObject;
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned int m128_u32[4];
} __m128;

extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

extern const __m128 DAT_010c4c00;

struct hkVector4 {
    __m128 m_vComponents;
    void operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; }
    void setBroadcast3(const hkVector4& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff); }
    void mul4(const hkVector4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    void add4(const hkVector4& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    void addMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
    void setNeg4(const hkVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00); }
    void neg() { m_vComponents = _mm_xor_ps(m_vComponents, DAT_010c4c00); }
};

struct __declspec(align(16)) FourWord {
    unsigned int x, y, z, w;
};

struct __declspec(align(16)) FourFloat {
    union { __m128 simd; FourWord words; };
};

struct __declspec(align(16)) MotionPacket {
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned int word0c;
    unsigned int word10;
    unsigned int word14;
    unsigned int word18;
    unsigned int word1c;
    unsigned int word20;
    unsigned int word24;
    unsigned int word28;
    unsigned int word2c;
    unsigned int word30;
    unsigned int word34;
    unsigned int word38;
    unsigned int word3c;
    unsigned int word40;
    unsigned int word44;
    unsigned int word48;
    unsigned int word4c;
    FourFloat direction;
    unsigned int trailing60, trailing64, trailing68, trailing6c;
};

struct __declspec(align(16)) MotionCallData {
    const void* descriptor;
    float scale;
    FourWord direction;
    unsigned int mode;
};

extern "C" float DAT_0104da48;
extern "C" const __m128 DAT_010c44d0;
extern "C" unsigned char UNK_010ce80c;

extern "C" void __cdecl FUN_00daf8e0(unsigned int second, unsigned int first,
                            MotionPacket* packet, MotionCallData* primary,
                            MotionCallData* secondary);

// Copies the input packet, XORs its direction with DAT_010c44d0, builds primary/secondary MotionCallData and calls FUN_00daf8e0.
// @fnv 0x00d3ac80
void __cdecl FUN_00d3ac80(unsigned int first, unsigned int second,
                           const MotionPacket* apPacket, unsigned int mode,
                           unsigned int optionalMode)
{
    MotionPacket packetCopy = *apPacket;
    packetCopy.direction.simd = _mm_xor_ps(apPacket->direction.simd, DAT_010c44d0);
    const void* descriptor = &UNK_010ce80c;
    MotionCallData primary;
    primary.descriptor = descriptor;
    primary.scale = DAT_0104da48;
    primary.direction = apPacket->direction.words;
    primary.mode = mode;

    if (optionalMode) {
        MotionCallData secondary;
        secondary.descriptor = descriptor;
        secondary.scale = DAT_0104da48;
        secondary.direction = apPacket->direction.words;
        secondary.mode = optionalMode;
        FUN_00daf8e0(second, first, &packetCopy, &primary, &secondary);
    } else {
        FUN_00daf8e0(second, first, &packetCopy, &primary, 0);
    }
}

extern char DAT_010ce81c;
struct FUN_00d3b160_tmp { const void* vt; unsigned char flag; unsigned int a4; };
struct CallbackHost_d3b160 {
    void hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, void*);
    void FUN_00d3b160(void*, void*, void*, unsigned int);
};

// Builds a temporary object holding a4 and a cleared flag with a vtable, then calls hkpCapsuleTriangleAgent_getPenetrations with a2, a1, a3 and that object.
// @fnv 0x00d3b160
// pdb: hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::getPenetrations | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void CallbackHost_d3b160::FUN_00d3b160(void* a1, void* a2, void* a3, unsigned int a4)
{
    FUN_00d3b160_tmp t;
    t.a4 = a4;
    t.flag = 0;
    t.vt = &DAT_010ce81c;
    hkpCapsuleTriangleAgent_getPenetrations(a2, a1, a3, &t);
}

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    Vec4 row0, row1, row2, row3;
};

void __cdecl FUN_00cd6520(void* a, float b, void* c, float d, void* e, float f, int g, int h, int i);

static __forceinline void transform(Vec4* out, const char* shape, int count, const Mat4* m)
{
    Vec4 p0 = m->row0;
    Vec4 p1 = m->row1;
    Vec4 p2 = m->row2;
    Vec4 p3 = m->row3;
    __m128 r0 = *(__m128*)&p0;
    __m128 r1 = *(__m128*)&p1;
    __m128 r2 = *(__m128*)&p2;
    __m128 r3 = *(__m128*)&p3;

    __m128* v = (__m128*)(shape + 0x20);
    for (int i = count - 1; i >= 0; --i) {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0x00);
        __m128 y = _mm_shuffle_ps(vi, vi, 0x55);
        __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(a, b);
    }
}

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern "C" __m128 _mm_rsqrt_ps(__m128 a);
extern __m128 DAT_010c71c0;
extern __m128 DAT_010c71d0;

static __forceinline float SqLenLane(__m128 x)
{
    __m128 sq = _mm_mul_ps(x, x);
    __m128 yx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 zyx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), yx);
    float r;
    _mm_store_ss(&r, zyx);
    return r;
}

// Computes Newton-refined inverse square roots of four vector lengths from pts and stores them plus a fifth value into out.
// @fnv 0x00cd72a0
void __cdecl ComputeInverseLengths(__m128* pts, float* out)
{
    __m128 c = pts[2];
    __m128 a = pts[0];
    __m128 b = pts[1];

    __m128 v = _mm_sub_ps(c, b);
    __m128 u = _mm_sub_ps(a, c);
    __m128 w = _mm_sub_ps(b, a);

    __m128 p = _mm_mul_ps(_mm_shuffle_ps(u, u, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(u, u, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 x = _mm_sub_ps(q, p);

    __declspec(align(16)) float lens[4];
    float fSqLen = SqLenLane(v);
    lens[0] = fSqLen;
    fSqLen = SqLenLane(u);
    lens[1] = fSqLen;
    fSqLen = SqLenLane(w);
    lens[2] = fSqLen;
    fSqLen = SqLenLane(x);
    lens[3] = fSqLen;

    __m128 l = _mm_load_ps(lens);
    __m128 r = _mm_rsqrt_ps(l);
    __m128 t = _mm_mul_ps(_mm_mul_ps(r, l), r);
    __m128 k1 = _mm_sub_ps(DAT_010c71c0, t);
    __m128 k2 = _mm_mul_ps(r, DAT_010c71d0);
    __m128 inv = _mm_mul_ps(k1, k2);

    _mm_store_ps(lens, inv);
    out[0] = lens[0];
    out[1] = lens[1];
    out[2] = lens[2];
    out[3] = lens[3];
    out[4] = fSqLen * lens[3];
}

struct __declspec(align(16)) ScalarVector {
    int x, y, z, w;
    __m128 quad() const { return *(const __m128*)this; }
};
struct Xf {
    ScalarVector r0, r1, r2, t;
};
struct ShapeInterface {
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
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual int refine(void*,void*,void*,void*,void*,void*,void*);
};
struct Shape : ShapeInterface {
    int unk04;
    int unk08;
    int unk0c;
    float radius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 vertices[3];
};
struct Contact {
    __m128 normal;
    __m128 position;
    Contact& operator=(const Contact& c) { normal = c.normal; position = c.position; return *this; }
    void __thiscall FUN_00caad60(void* arg);
};



static __forceinline void xform(const Xf& m, const __m128* src, __m128* dst, int hi)
{
    ScalarVector column0 = m.r0;
    __m128 c0 = column0.quad();
    ScalarVector column1 = m.r1;
    __m128 c1 = column1.quad();
    ScalarVector column2 = m.r2;
    __m128 c2 = column2.quad();
    ScalarVector translation = m.t;
    __m128 ct = translation.quad();
    for (int i = hi; i >= 0; --i) {
        __m128 v = src[i];
        __m128 x = _mm_shuffle_ps(v, v, 0);
        __m128 y = _mm_shuffle_ps(v, v, 0x55);
        __m128 z = _mm_shuffle_ps(v, v, 0xaa);
        dst[i] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, c1), _mm_mul_ps(x, c0)), _mm_add_ps(_mm_mul_ps(z, c2), ct));
    }
}

#include <windows.h>
extern DWORD DAT_0126835c;

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

typedef ScalarVector Vec4f;

struct ContactMatrix
{
    Vec4f row[4];
};

struct VirtObj
{
    virtual void v00();
    virtual void Run(const void* a, const void* b);
};

struct ManifoldPoint
{
    __m128 pos;
    int unk10;
    int unk14;
    int unk18;
    float dist;
};

struct HitRec
{
    ManifoldPoint pt0;
    ManifoldPoint pt1;
    ManifoldPoint pt2;
};

extern "C" void __cdecl FUN_00cd6520(void* out1, float fx, void* out2, float fy, void* p, float afDepth, int zero, HitRec* hit, int zero2);

struct hkpShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_kVertices[4];
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    int unk04;
    const ContactMatrix* m_kMotionState;
};

struct CollisionInput { int unk00; int unk04; float tolerance; };

struct __declspec(align(16)) RowPair { Vec4f first, second; };

struct CapsuleTriangleAgent {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void hkpCapsuleTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector);
};

// Transforms capsule and triangle vertices into world space, tests for intersection, and reports a hit to the collector if found.
// @f3 0x009c3990 (community match, verified in this file)
namespace f3m_009c3990 {
struct FloatPair {
    float x, y;
    __forceinline void operator=(const FloatPair& o) { x = o.x; y = o.y; }
};
struct NativeCollisionInput { int unk00; float tolerance; };
extern "C" void __cdecl FUN_0096e450(const void*, float, const void*, float, void*, float, int, HitRec*);
struct __declspec(align(16)) NativeFloat4 {
    float x, y, z, w;
    __forceinline NativeFloat4() {}
    __forceinline void operator=(const NativeFloat4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float& operator()(int i) { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
    __forceinline const float& operator()(int i) const { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
};
struct NativeMat3 {
    NativeFloat4 m_col0, m_col1, m_col2;
    __forceinline NativeFloat4& getColumn(int i) { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
    __forceinline const NativeFloat4& getColumn(int i) const { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
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
struct ScalarReal {
    float value;
    __forceinline ScalarReal(float v) : value(v) {}
    friend __forceinline double operator*(float c, const ScalarReal& s) { return s.value * c; }
};
__forceinline void NativeTransformPoints(const NativeTransform& transform, const NativeFloat4* source, NativeFloat4* destination, int count) {
    NativeTransform unaliased = transform;
    int i = count - 1;
    do {
        const NativeFloat4& b = source[i];
        NativeFloat4& t = destination[i];
        const NativeRot& r = unaliased.getRotation();
        const NativeFloat4& tr = unaliased.getTranslation();
        ScalarReal v0(b(0));
        ScalarReal v1(b(1));
        ScalarReal v2(b(2));
        t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + tr(0);
        t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + tr(1);
        t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + tr(2);
        t(3) = 0;
    } while (--i >= 0);
}
__forceinline void ProcessCapsuleTriangle(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, void* cache, HitRec* hit) {
    const hkpShape* capsuleShape = bodyA.m_pCollisionShape;
    const hkpShape* triangleShape = bodyB.m_pCollisionShape;
    NativeFloat4 capsule[2];
    if (0) { FloatPair d0; FloatPair u0 = *reinterpret_cast<const FloatPair*>(input); d0 = u0; }
    NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(bodyA.m_kMotionState), reinterpret_cast<const NativeFloat4*>(capsuleShape->m_kVertices), capsule, 2);
    NativeFloat4 triangle[3];
    NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(bodyB.m_kMotionState), reinterpret_cast<const NativeFloat4*>(triangleShape->m_kVertices), triangle, 3);
    FUN_0096e450(capsule, capsuleShape->m_fSphereRadius, triangle, triangleShape->m_fSphereRadius, cache, reinterpret_cast<const NativeCollisionInput*>(input)->tolerance, 0, hit);
}
}
// pdb: hkpCapsuleTriangleAgent::getPenetrations | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void CapsuleTriangleAgent::hkpCapsuleTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector)
{
    using namespace f3m_009c3990;
    extern char DAT_010cef80[], DAT_010c41f8[];
    {
        ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = DAT_010cef80;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            pRec->m_iTick = tick;
            pBuf->m_pCur = pRec + 1;
        }
    }

    HitRec hit;
    ProcessCapsuleTriangle(bodyA, bodyB, input, &this->unk14, &hit);
    if (hit.pt0.dist < 0.0f || hit.pt1.dist < 0.0f)
    {
        collector->Run(&bodyA, &bodyB);
    }

    {
        ProfBuf* pBuf2 = (ProfBuf*)TlsGetValue(DAT_0126835c);
        if (pBuf2->m_pCur < pBuf2->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf2->m_pCur;
            pRec->m_pName = DAT_010c41f8;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            pRec->m_iTick = tick;
            pBuf2->m_pCur = pRec + 1;
        }
    }
}


namespace fnv_00d3b1a0 {
extern "C" const int DAT_010ce81c;

struct LocalState_d3b1a0 {
    const int* m_pIntegerValue;
    unsigned char m_bZero;
    int m_iValue;
};

typedef void (__cdecl *Call_d3a8c0)(int, int, int, LocalState_d3b1a0*);

// Initialises a LocalState_d3b1a0 with param4, a zero flag and a pointer to DAT_010ce81c, then calls FUN_00d3a8c0 with param2, param1, param3 and the state.
// @fnv 0x00d3b1a0
void __cdecl FUN_00d3b1a0(int param1, int param2, int param3, int aiValue) {
    LocalState_d3b1a0 state;
    state.m_iValue = aiValue;
    state.m_bZero = 0;
    state.m_pIntegerValue = &DAT_010ce81c;

    Call_d3a8c0 call = (Call_d3a8c0)FUN_00d3a8c0;
    call(param2, param1, param3, &state);
}
}  // namespace fnv_00d3b1a0

namespace fnv_00d3b1e0 {
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject {
    void FUN_00d39ef0(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d3b1e0(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and &DAT_010ce7fc, then calls FUN_00d39ef0 with second, first, third and that data.
// @fnv 0x00d3b1e0
// pdb: hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::getClosestPoints | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void CpuObject::FUN_00d3b1e0(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d39ef0(second, first, third, &data);
}
}  // namespace fnv_00d3b1e0

extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);

struct ContactNormalSetter : Contact
{
    ContactNormalSetter* FUN_00caad60(const __m128* source);
};

// Copies the x, y and z components of *source into position, keeping position's existing w, and returns this.
// @fnv 0x00caad60
ContactNormalSetter* ContactNormalSetter::FUN_00caad60(const __m128* source)
{
    __m128 incoming = *source;
    __m128 current = position;
    __m128 high = _mm_unpackhi_ps(incoming, current);
    position = _mm_shuffle_ps(incoming, high, 0xc4);
    return this;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct MonitorRecord { const char* name; unsigned int time; unsigned int unk08; };
struct MonitorStream { unsigned int unk00; MonitorRecord* cursor; unsigned int unk08; MonitorRecord* end; };
struct __declspec(align(16)) PlainVector { int x,y,z,w; __m128 quad() const { return *(const __m128*)this; } };
struct PlainMatrix { PlainVector r0,r1,r2,t; };
struct ContactRecord {
    __m128 position;
    __m128 normal;
    ContactRecord& operator=(const ContactRecord& o) { position=o.position; normal=o.normal; return *this; }
    void FUN_00caad60(const PlainVector*);
};
struct CacheRecord { unsigned char flag; unsigned char unk01; unsigned short feature; unsigned int unk04; };
union __declspec(align(16)) TransformCacheScratch { PlainVector column; CacheRecord cache[3]; };
struct CollisionShape;
struct CapsuleShapeInterface {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3c();
    virtual int process(unsigned short*,unsigned char*,ContactRecord*,const PlainMatrix*,const CollisionShape*,const PlainMatrix*,PlainVector*);
};
struct CollisionShape : CapsuleShapeInterface {
    unsigned int unk04,unk08,unk0c;
    float radius;
    unsigned int unk14,unk18,unk1c;
    hkVector4 points[3];
};
struct BodyRecord { const CollisionShape* shape; unsigned int unk04; const PlainMatrix* matrix; };
struct PointEvent { ContactRecord contact; const BodyRecord* a; const BodyRecord* b; unsigned int unk28,unk2c; };
struct Collector { virtual void slot00(); virtual void accept(const PointEvent*); };
struct ContactResults { ContactRecord points[3]; };
void __cdecl FUN_00cd6520(hkVector4*,float,hkVector4*,float,void*,float,int,ContactResults*,CacheRecord*);
struct CollisionAgent {
    unsigned int unk00,unk04,unk08,unk0c,unk10,cache14;
    void FUN_00d39ef0(const BodyRecord& a,const BodyRecord& b,const CollisionInput& input,Collector* output);
};
// @fnv 0x00d39ef0
void CollisionAgent::FUN_00d39ef0(const BodyRecord& a,const BodyRecord& b,const CollisionInput& input,Collector* output) {
    {
        MonitorStream* stream=(MonitorStream*)TlsGetValue(DAT_0126835c);
        if(stream->cursor < stream->end) {
            MonitorRecord* rec=stream->cursor;
            rec->name="TtCapsTriangle";
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            rec->time=ticks;
            stream->cursor=rec+1;
        }
    }
    {
    PointEvent event;
    event.a=&a; event.b=&b;
    TransformCacheScratch transformCache;
    hkVector4 pointsA[2];
    hkVector4 pointsB[3];
    const CollisionShape* shapeA=a.shape;
    const CollisionShape* shapeB=b.shape;
    xform(*(const Xf*)a.matrix,&shapeA->points[0].m_vComponents,&pointsA[0].m_vComponents,1);
    xform(*(const Xf*)b.matrix,&shapeB->points[0].m_vComponents,&pointsB[0].m_vComponents,2);
    ContactResults result;
    CacheRecord* cache=transformCache.cache;
    FUN_00cd6520(pointsA,shapeA->radius,pointsB,shapeB->radius,&cache14,input.tolerance,0,&result,cache);
    int index;
    if(result.points[0].normal.m128_f32[3] < result.points[1].normal.m128_f32[3]) {
        if(!(input.tolerance > result.points[0].normal.m128_f32[3])) goto done;
        index=0;
    } else {
        if(!(input.tolerance > result.points[1].normal.m128_f32[3])) goto done;
        index=1;
    }
    {
        unsigned char flag=cache[index].flag;
        if(input.unk04 && flag>0) {
            PlainVector normal=*(const PlainVector*)&result.points[index].normal;
            const PlainMatrix* transformA=a.matrix;
            const PlainMatrix* transformB=b.matrix;
            ContactRecord* contact=&result.points[index];
            int outcome=const_cast<CollisionShape*>(shapeB)->process(&cache[index].feature,&flag,contact,transformB,shapeA,transformA,&normal);
            if(outcome==0) goto done;
            if(outcome==1) result.points[index].FUN_00caad60(&normal);
        }
        event.contact=result.points[index];
        output->accept(&event);
    }
    }
done:
    {
        MonitorStream* stream=(MonitorStream*)TlsGetValue(DAT_0126835c);
        if(stream->cursor < stream->end) {
            MonitorRecord* rec=stream->cursor;
            rec->name="Et";
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            rec->time=ticks;
            stream->cursor=rec+1;
        }
    }
}

extern char DAT_010cef80[], DAT_010c41f8[];
struct Body { Shape* shape; int unused; Mat4* matrix; };
struct Input { int unk00,unk04; float tolerance; };
struct PenetrationCollector { virtual void unused(); virtual void add(Body*, Body*); };
struct Cache { float inverseEdge0,inverseEdge1,inverseEdge2,inverseNormal,normalLength; };
static __forceinline void mytransform(Vec4* out, const Shape* shape, int count, const Mat4* m)
{
    struct Rows { Vec4 p3,p2,p1,p0; } p;
    p.p0 = m->row0; p.p1 = m->row1; p.p2 = m->row2; p.p3 = m->row3;
    __m128 r0 = *(__m128*)&p.p0, r1 = *(__m128*)&p.p1, r2 = *(__m128*)&p.p2, r3 = *(__m128*)&p.p3;
    const __m128* v = (const __m128*)shape->vertices;
    for (int i = count - 1; i >= 0; --i) {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0);
        __m128 y = _mm_shuffle_ps(vi, vi, 0x55);
        __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(r0, x), _mm_mul_ps(r1, y));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(a, b);
    }
}
static __forceinline void mytransform2(Vec4* out, const Shape* shape, int count, const Mat4* m)
{
    __m128 r0,r1,r2,r3; (void)r1; (void)r2; 
    struct Rows { Vec4 p0,p1,p2,p3; } p;
    p.p0 = m->row0; p.p1 = m->row1; p.p2 = m->row2; p.p3 = m->row3;
    r0 = _mm_load_ps((const float*)&p.p0); r1 = _mm_load_ps((const float*)&p.p1); r2 = _mm_load_ps((const float*)&p.p2); r3 = _mm_load_ps((const float*)&p.p3);
    const __m128* __restrict v = (const __m128*)shape->vertices;
    int i = count - 1;
    do {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0); __m128 y = _mm_shuffle_ps(vi, vi, 0x55); __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(b, a);
    } while (--i >= 0);
}
// Transforms two body shapes, tests for penetration, and adds the pair to the collector if the result normals indicate overlap.
// @f3 0x009c3cc0 (community match, verified in this file)
namespace f3m_009c3cc0 {
struct DeadFloats { float f0; float f1; __forceinline void operator=(const DeadFloats& o) { f0 = o.f0; f1 = o.f1; } };
struct NativeCollisionInput { int unk00; float tolerance; };
extern "C" void __cdecl FUN_0096fd30(const void*, void*);
extern "C" void __cdecl FUN_0096e450(const void*, float, const void*, float, void*, float, int, HitRec*);
struct __declspec(align(16)) NativeFloat4 {
    float x, y, z, w;
    __forceinline NativeFloat4() {}
    __forceinline void operator=(const NativeFloat4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float& operator()(int i) { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
    __forceinline const float& operator()(int i) const { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
};
struct NativeMat3 {
    NativeFloat4 m_col0, m_col1, m_col2;
    __forceinline NativeFloat4& getColumn(int i) { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
    __forceinline const NativeFloat4& getColumn(int i) const { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
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
struct ScalarReal {
    float value;
    __forceinline ScalarReal(float v) : value(v) {}
    friend __forceinline double operator*(float c, const ScalarReal& s) { return s.value * c; }
};
__forceinline void NativeTransformPoints(const NativeTransform& transform, const NativeFloat4* source, NativeFloat4* destination, int count) {
    NativeTransform unaliased = transform;
    int i = count - 1;
    do {
        const NativeFloat4& b = source[i];
        NativeFloat4& t = destination[i];
        const NativeRot& r = unaliased.getRotation();
        const NativeFloat4& tr = unaliased.getTranslation();
        ScalarReal v0(b(0));
        ScalarReal v1(b(1));
        ScalarReal v2(b(2));
        t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + tr(0);
        t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + tr(1);
        t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + tr(2);
        t(3) = 0;
    } while (--i >= 0);
}
__forceinline void ProcessCapsuleTriangle(Body* bodyA, Body* bodyB, const Input* input, void* cache, HitRec* hit) {
    const Shape* capsuleShape = bodyA->shape;
    const Shape* triangleShape = bodyB->shape;
    NativeFloat4 capsule[2];
    if (0) { DeadFloats d0; DeadFloats u0 = *reinterpret_cast<const DeadFloats*>(input); d0 = u0; }
NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(bodyA->matrix), reinterpret_cast<const NativeFloat4*>(capsuleShape->vertices), capsule, 2);
    NativeFloat4 triangle[3];
    NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(bodyB->matrix), reinterpret_cast<const NativeFloat4*>(triangleShape->vertices), triangle, 3);
    FUN_0096e450(capsule, capsuleShape->radius, triangle, triangleShape->radius, cache, reinterpret_cast<const NativeCollisionInput*>(input)->tolerance, 0, hit);
}
}
// pdb: hkpCapsuleTriangleAgent::staticGetPenetrations | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d3a8c0(Body* apBodyA, Body* apBodyB, Input* input, PenetrationCollector* collector)
{
    using namespace f3m_009c3cc0;
    {
        ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = ::DAT_010cef80;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            pRec->m_iTick = tick;
            pBuf->m_pCur = pRec + 1;
        }
    }

    Cache cache;
    FUN_0096fd30(apBodyB->shape->vertices, &cache);
    HitRec hit;
    ProcessCapsuleTriangle(apBodyA, apBodyB, input, &cache, &hit);

    if (hit.pt0.dist < 0.0f || hit.pt1.dist < 0.0f)
    {
        collector->add(apBodyA, apBodyB);
    }

    {
        ProfBuf* pBuf2 = (ProfBuf*)TlsGetValue(DAT_0126835c);
        if (pBuf2->m_pCur < pBuf2->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf2->m_pCur;
            pRec->m_pName = ::DAT_010c41f8;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            pRec->m_iTick = tick;
            pBuf2->m_pCur = pRec + 1;
        }
    }
}

