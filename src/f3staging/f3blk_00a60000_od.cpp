#include <math.h>
#include <windows.h>
// src/f3staging/f3blk_00a60000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a76580 (community match, verified in this file)
extern const char identity_transform;
namespace f3m_00a76580 {
struct Vec4 { float x,y,z,w; };
struct __declspec(align(16)) Bounds { Vec4 min, max; };
struct __declspec(align(16)) ShapeBuffer { char data[512]; };
struct Shape {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6();
 virtual void aabb(const void*, float, Bounds&);
};
struct Container {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
 virtual Shape* get(unsigned, ShapeBuffer&);
};
struct Keys { unsigned* data; int size; int capacity; };
struct Base { virtual void f(); short a,b; Base():b(1) {} };
struct OtherBase { virtual void g(); };
struct ArrayX { int* data; int size; unsigned capacity; ArrayX():data(0),size(0),capacity(0x80000000) {} };
struct Result : Base, OtherBase { ArrayX items; const Keys* keys; Result(void*,Container*,const Keys&); };
extern void __cdecl build(void*, Bounds&, OtherBase*);
// pdb: hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun, high
// pdb params: moppCode, shapeContainer, shapesToRemove
Result::Result(void* code, Container* container, const Keys& k) {
 if (k.size != 0) {
  Bounds a;
  ShapeBuffer buffer;
  unsigned key = k.data[0];
  container->get(key, buffer)->aabb(&identity_transform, 0.0f, a);
  for (int i=1; i<k.size; ++i) {
   Bounds b;
   unsigned key = k.data[i];
   container->get(key, buffer)->aabb(&identity_transform, 0.0f, b);
   a.min.x = a.min.x < b.min.x ? a.min.x : b.min.x;
   a.min.y = a.min.y < b.min.y ? a.min.y : b.min.y;
   a.min.z = a.min.z < b.min.z ? a.min.z : b.min.z;
   a.min.w = a.min.w < b.min.w ? a.min.w : b.min.w;
   a.max.x = a.max.x > b.max.x ? a.max.x : b.max.x;
   a.max.y = a.max.y > b.max.y ? a.max.y : b.max.y;
   a.max.z = a.max.z > b.max.z ? a.max.z : b.max.z;
   a.max.w = a.max.w > b.max.w ? a.max.w : b.max.w;
  }
  keys = &k;
  build(code,a,static_cast<OtherBase*>(this));
  keys = 0;
 }
}
}   // namespace f3m_00a76580

// @f3 0x00a7e460 (community match, verified in this file)
struct __declspec(align(16)) V4
{
    float x, y, z, w;
    V4& operator=(const V4& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};

struct VData
{
    V4 a;
    V4 b;
    V4 c;
};

struct Node
{
    V4     unk00;
    VData* unk10;
    int    unk14;
    int    unk18;
    int    unk1c;
    VData* unk20;
    int    unk24;
    int    unk28;
    int    unk2c;
    VData* unk30;
    int    unk34;
    int    unk38;
    int    unk3c;
    float  unk40;
};

struct Out
{
    V4    unk00;
    V4    unk10;
    float unk20;
};

struct Owner
{
    Node* FUN_00a995d0(Node* node);
};

extern V4 DAT_01092a50;

void hkpCollideTriangleUtil_calcBarycentricCoordinates(const V4* point, const V4* a, const V4* b, const V4* c, float* out);

struct This
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    V4* unk60;
    V4* unk64;
    V4* unk68;
    int unk6c;
    void FUN_00a7e460(Owner* owner, Node* node, Out* out);
};

// pdb: hkpConvexPenetrationUtil::convertResultToFeature | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, call_dedup, low
// pdb params: polytope, nearestTriangle, output
void This::FUN_00a7e460(Owner* owner, Node* node, Out* out)
{
    float bary[3];
    V4 tmp;

    for (int i = 0; i < 10; i++)
    {
        V4& dst0 = this->unk68[0];
        dst0 = node->unk10->a;
        this->unk68[1] = node->unk20->a;
        this->unk68[2] = node->unk30->a;

        hkpCollideTriangleUtil_calcBarycentricCoordinates(&DAT_01092a50, &this->unk68[0], &this->unk68[1], &this->unk68[2], bary);

        if (!(bary[0] < 0.0f) && !(bary[1] < 0.0f) && !(bary[2] < 0.0f))
            break;

        node = owner->FUN_00a995d0(node);
    }

    VData* d = node->unk10;
    this->unk60[0] = d->b;
    this->unk64[0] = d->c;
    d = node->unk20;
    this->unk60[1] = d->b;
    this->unk64[1] = d->c;
    d = node->unk30;
    this->unk60[2] = d->b;
    this->unk64[2] = d->c;
    this->unk6c = 3;

    V4* m = this->unk60;
    tmp.x = m[0].x * bary[0];
    tmp.y = m[0].y * bary[0];
    tmp.z = m[0].z * bary[0];
    tmp.w = m[0].w * bary[0];
    tmp.x += m[1].x * bary[1];
    tmp.y += m[1].y * bary[1];
    tmp.z += m[1].z * bary[1];
    tmp.w += m[1].w * bary[1];
    tmp.x += m[2].x * bary[2];
    tmp.y += m[2].y * bary[2];
    tmp.z += m[2].z * bary[2];
    tmp.w += m[2].w * bary[2];

    out->unk10 = tmp;
    out->unk20 = -node->unk40;
    out->unk00.x = -node->unk00.x;
    out->unk00.y = -node->unk00.y;
    out->unk00.z = -node->unk00.z;
    out->unk00.w = -node->unk00.w;
}

// @f3 0x00a7d850 (community match, verified in this file)
namespace f3m_00a7d850 {
namespace hk7d850 {
struct hkQuadReal { float v[4]; };
class hkMatrix3;
class __declspec(align(16)) hkVector4
{
public:
    hkQuadReal m_quad;
    __forceinline float& operator()(int i) { return m_quad.v[i]; }
    __forceinline const float& operator()(int i) const { return m_quad.v[i]; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_quad.v[0] = a.m_quad.v[0] - b.m_quad.v[0];
        m_quad.v[1] = a.m_quad.v[1] - b.m_quad.v[1];
        m_quad.v[2] = a.m_quad.v[2] - b.m_quad.v[2];
        m_quad.v[3] = a.m_quad.v[3] - b.m_quad.v[3];
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_quad.v[0] = a.m_quad.v[0] + b.m_quad.v[0];
        m_quad.v[1] = a.m_quad.v[1] + b.m_quad.v[1];
        m_quad.v[2] = a.m_quad.v[2] + b.m_quad.v[2];
        m_quad.v[3] = a.m_quad.v[3] + b.m_quad.v[3];
    }
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3& r, const hkVector4& b);
};
class hkMatrix3
{
public:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};
__forceinline void hkVector4::_setRotatedDir(const hkMatrix3& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    m_quad.v[0] = r(0,0)*b0 + r(0,1)*b1 + r(0,2)*b2;
    m_quad.v[1] = r(1,0)*b0 + r(1,1)*b1 + r(1,2)*b2;
    m_quad.v[2] = r(2,0)*b0 + r(2,1)*b1 + r(2,2)*b2;
    m_quad.v[3] = 0;
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkMatrix3& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    m_quad.v[0] = r(0,0)*b0 + r(1,0)*b1 + r(2,0)*b2;
    m_quad.v[1] = r(0,1)*b0 + r(1,1)*b1 + r(2,1)*b2;
    m_quad.v[2] = r(0,2)*b0 + r(1,2)*b1 + r(2,2)*b2;
    m_quad.v[3] = 0;
}
struct Body
{
    hkVector4 m_position;
    hkVector4 m_velocity;
};
struct Frames
{
    hkMatrix3 m_rotA;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;
    hkVector4 unk60;
    hkMatrix3 m_rotB;
    hkVector4 unkA0;
    hkVector4 unkB0;
    hkVector4 unkC0;
    hkVector4 unkD0;
    hkMatrix3 m_rotC;
};
}

namespace hk7d850 {
__forceinline void rotInvS(hkVector4& o, const hkMatrix3& r, float b0, float b1, float b2)
{
    o.m_quad.v[0] = r(0,0)*b0 + r(1,0)*b1 + r(2,0)*b2;
    o.m_quad.v[1] = r(0,1)*b0 + r(1,1)*b1 + r(2,1)*b2;
    o.m_quad.v[2] = r(0,2)*b0 + r(1,2)*b1 + r(2,2)*b2;
    o.m_quad.v[3] = 0;
}
__forceinline void rotInvP(hkVector4& o, const hkMatrix3& r, const hkVector4& b)
{
    const float* m = &r.m_col0.m_quad.v[0];
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    o.m_quad.v[0] = m[0]*b0 + m[1]*b1 + m[2]*b2;
    o.m_quad.v[1] = m[4]*b0 + m[5]*b1 + m[6]*b2;
    o.m_quad.v[2] = m[8]*b0 + m[9]*b1 + m[10]*b2;
    o.m_quad.v[3] = 0;
}
__forceinline void sub4(hkVector4& o, const hkVector4& b)
{
    o.m_quad.v[0] -= b.m_quad.v[0];
    o.m_quad.v[1] -= b.m_quad.v[1];
    o.m_quad.v[2] -= b.m_quad.v[2];
    o.m_quad.v[3] -= b.m_quad.v[3];
}
}
using namespace hk7d850;
namespace hk7d850 {
__forceinline void rotInvX(hkVector4& o, const hkMatrix3& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    o.m_quad.v[0] = r(0,0)*b0 + r(1,0)*b1 + r(2,0)*b2;
    o.m_quad.v[1] = r(0,1)*b0 + r(1,1)*b1 + r(2,1)*b2;
    o.m_quad.v[2] = r(0,2)*b0 + r(1,2)*b1 + r(2,2)*b2;
    o.m_quad.v[3] = 0;
}
}
void __cdecl FUN_00a7d850(const Frames* f, const Body* a, const Body* b, hkVector4* out)
{
    int dd0 = 1;
    hkVector4 va;
    va._setRotatedDir(f->m_rotA, a->m_velocity);
    hkVector4 vb;
    vb._setRotatedDir(f->m_rotB, b->m_velocity);
    hkVector4 d;
    d.setSub4(a->m_position, b->m_position);
    va.setSub4(va, vb);
    rotInvX(d, f->m_rotC, d);
    out->m_quad.v[0] = va.m_quad.v[0] + d.m_quad.v[0];
    out->m_quad.v[1] = d.m_quad.v[1] + va.m_quad.v[1];
    out->m_quad.v[2] = d.m_quad.v[2] + va.m_quad.v[2];
    out->m_quad.v[3] = va.m_quad.v[3] + d.m_quad.v[3];
}
}   // namespace f3m_00a7d850

// @f3 0x00a6c820 (community match, verified in this file)
unsigned int __cdecl PackColorBigEndian(float, float, float, float);
namespace ZA6C820 {
struct TransformQ;
struct MatrixQ;
// Scalar wrapper: the reciprocal length lives in it and is handed on by reference.
struct ScalarQ
{
    float value;
    ScalarQ() {}
    void SetInverse(float a) { value = a != 0.0f ? (float)(1.0 / (float)sqrt((double)a)) : 0.0f; }
};
struct __declspec(align(16)) VecQ
{
    float x, y, z, w;
    void hkVector4_setTransformedPos(const TransformQ*, const VecQ*);
    void hkVector4_setRotatedDir(const MatrixQ*, const VecQ*);
    void setMul(float scale, const VecQ& a)
    {
        x = scale * a.x;
        y = scale * a.y;
        z = scale * a.z;
        w = scale * a.w;
    }
    void set(const VecQ& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
        w = a.w;
    }
    void add(const VecQ& a)
    {
        x = a.x + x;
        y = a.y + y;
        z = a.z + z;
        w = a.w + w;
    }
    void setAddMul(const VecQ& a, const VecQ& b, float scale)
    {
        x = a.x + scale * b.x;
        y = a.y + scale * b.y;
        z = a.z + scale * b.z;
        w = a.w + scale * b.w;
    }
    void mul4(const float& rs)
    {
        float s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void normalize()
    {
        float length = x * x + y * y + z * z;
        ScalarQ reciprocal;
        reciprocal.SetInverse(length);
        mul4(reciprocal.value);
    }
};
struct MatrixQ
{
    VecQ a, b, c;
    const VecQ& getColumn(int i) const { return (&a)[i]; }
};
struct TransformQ
{
    MatrixQ rotation;
    VecQ translation;
};
struct DataQ
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MatrixQ rotA, rotB;
    int unk80;
    float minimum, maximum;
};
struct ConstraintQ
{
    int unk00, unk04, unk08;
    DataQ* data;
};
struct ArcQ
{
    int unk00;
    void FUN_00a6ac00(float, float, float, int, const VecQ*, const VecQ*, const VecQ*);
};
struct AllocatorQ
{
    void FUN_008f6d90(void*, int, int);
};
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct ArrayQ;
void __cdecl FUN_00901e90(ArrayQ*, int, int);
struct ArrayQ
{
    ArcQ** data;
    int count;
    int capacity;
    ArrayQ() : data(0), count(0), capacity(0x80000000) {}
    ~ArrayQ()
    {
        if ((capacity & 0x80000000) == 0)
        {
            int n = capacity & 0x3fffffff;
            AllocatorQ* a = (AllocatorQ*)DAT_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(data, n * 4, 0x17);
        }
    }
    void push(ArcQ* p)
    {
        FUN_00901e90(this, 1, 4);
        count = 1;
        data[0] = p;
    }
};
struct HandlerQ
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void line(const VecQ*, const VecQ*, unsigned int, int);
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void geometry(ArrayQ*, int, int);
};
struct PrimitiveQ
{
    int unk00, unk04, unk08, unk0c;
    void FUN_00a8f460(HandlerQ*);
};
extern VecQ DAT_01092a50;
struct HingeQ
{
    float length;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    VecQ pivotA, pivotB;
    MatrixQ rotationA, rotationB;
    PrimitiveQ primitive;
    ArcQ arc;
    void FUN_00a6aa20(ConstraintQ*, TransformQ*, TransformQ*);
    void FUN_00a6a7b0(int);
    void FUN_00a6a750(int);
    void FUN_00a6c820(ConstraintQ*, HandlerQ*, int);
};
// pdb: hkpRagdollLimitsDrawer::drawConstraint | hkpRagdollLimitsDrawer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: constraint, displayHandler, id, tag
void HingeQ::FUN_00a6c820(ConstraintQ* constraint, HandlerQ* handler, int tag)
{
    DataQ* data = constraint->data;
    primitive.FUN_00a8f460(handler);
    TransformQ worldA, worldB;
    FUN_00a6aa20(constraint, &worldA, &worldB);
    pivotB.hkVector4_setTransformedPos(&worldA, &DAT_01092a50);
    pivotA.hkVector4_setTransformedPos(&worldB, &DAT_01092a50);
    FUN_00a6a7b0(tag);
    FUN_00a6a750(tag);
    VecQ axisA, axisB;
    const MatrixQ* rb = &data->rotB;
    axisA.hkVector4_setRotatedDir(&rotationB, &rb->getColumn(0));
    axisB.hkVector4_setRotatedDir(&rotationB, &rb->getColumn(2));
    handler->line(&pivotA, &pivotB, 0xffff0000, tag);
    {
        VecQ positive, negative;
        positive.setMul((float)(length * 0.5), axisA);
        positive.add(pivotB);
        negative.setMul((float)(length * -0.5), axisA);
        negative.add(pivotB);
        handler->line(&negative, &positive, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), tag);
    }
    arc.FUN_00a6ac00(1.5f, data->minimum, data->maximum, 24, &pivotB, &axisA, &axisB);
    {
        ArrayQ geometry;
        geometry.push(&arc);
        handler->geometry(&geometry, -1, tag);
    }
    {
        VecQ from, to;
        from.set(pivotB);
        to.setAddMul(from, axisB, (float)(length * 0.5));
        handler->line(&from, &to, 0xffffff00, tag);
        VecQ normal;
        normal.hkVector4_setRotatedDir(&rotationA, &data->rotA.c);
        normal.normalize();
        from.set(pivotA);
        to.setAddMul(from, normal, (float)(length * 0.5));
        handler->line(&from, &to, 0xffffff00, tag);
    }
}
}

// @f3 0x00a6ec10 (community match, verified in this file)
#include <math.h>
extern unsigned long DAT_010f3170;
namespace f3m_00a6ec10 {

namespace S00a6ec10_ns {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}

__forceinline float S00a6ec10_sqrt(float r) { return (float)sqrt(r); }
__forceinline float S00a6ec10_sqrtInverse(float r)
{
    if (r != 0.0f)
        return 1.0f / S00a6ec10_sqrt(r);
    return 0.0f;
}

struct __declspec(align(16)) S00a6ec10_Vec4
{
    float x, y, z, w;
    void setMul4(float s, const S00a6ec10_Vec4& v) { x = s * v.x; y = s * v.y; z = s * v.z; w = s * v.w; }
    void add4(const S00a6ec10_Vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    void setAddMul4(const S00a6ec10_Vec4& a, const S00a6ec10_Vec4& b, float r)
    {
        x = a.x + r * b.x; y = a.y + r * b.y; z = a.z + r * b.z; w = a.w + r * b.w;
    }
    float lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline void normalize3() { mul4(S00a6ec10_sqrtInverse(lengthSquared3())); }
    S00a6ec10_Vec4() {}
    S00a6ec10_Vec4(const S00a6ec10_Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void operator=(const S00a6ec10_Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void hkVector4_setTransformedPos(const struct S00a6ec10_Transform& t, const S00a6ec10_Vec4& p);
    void hkVector4_setRotatedDir(const struct S00a6ec10_Rotation& r, const S00a6ec10_Vec4& d);
};

struct __declspec(align(16)) S00a6ec10_Rotation
{
    S00a6ec10_Vec4 col0, col1, col2;
};

struct __declspec(align(16)) S00a6ec10_Transform
{
    S00a6ec10_Rotation rot;
    S00a6ec10_Vec4 pos;
};

struct S00a6ec10_ThreadMem
{
    void FUN_008f6d90(void* p, int nbytes, int cls);
};

extern void __cdecl FUN_00901e90(void* arr, int n, int elemSize);
extern int __cdecl FUN_00921880(float r, float g, float b, float a);

template <class T>
struct S00a6ec10_Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    S00a6ec10_Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~S00a6ec10_Array()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int cap = getCapacity();
            S00a6ec10_ThreadMem* mem = (S00a6ec10_ThreadMem*)S00a6ec10_ns::FUN_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(m_data, cap * sizeof(T), 0x17);
        }
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        m_size = n;
    }
    T& operator[](int i) { return m_data[i]; }
};

struct S00a6ec10_Geom
{
    int unk00;
    void FUN_00a6ac00(float scale, float minA, float maxA, int segments, const S00a6ec10_Vec4& center, const S00a6ec10_Vec4& axis, const S00a6ec10_Vec4& perp);
};

struct S00a6ec10_Display
{
    virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03();
    virtual void f04(); virtual void f05(); virtual void f06(); virtual void f07();
    virtual void displayLine(const S00a6ec10_Vec4& a, const S00a6ec10_Vec4& b, int color, int id);
    virtual void f09(); virtual void f0a(); virtual void f0b();
    virtual void displayGeometry(const S00a6ec10_Array<S00a6ec10_Geom*>& geoms, int color, int id);
};

struct __declspec(align(16)) S00a6ec10_Constraint
{
    S00a6ec10_Vec4 unk00;
    S00a6ec10_Vec4 unk10;
    S00a6ec10_Vec4 unk20;
    S00a6ec10_Vec4 unk30;
    S00a6ec10_Vec4 dir40;
    S00a6ec10_Vec4 pivot50;
    S00a6ec10_Vec4 axis60;
    S00a6ec10_Vec4 unk70;
    S00a6ec10_Vec4 perp80;
    S00a6ec10_Vec4 pivot90;
    S00a6ec10_Vec4 unkA0;
    S00a6ec10_Vec4 unkB0;
    char unkC0;
    char unkC1;
    bool limitsEnabled;
    char unkC3;
    float minAngle;
    float maxAngle;
};

struct S00a6ec10_Input
{
    int unk00;
    int unk04;
    int unk08;
    S00a6ec10_Constraint* constraint;
};

struct S00a6ec10_C0
{
    int unk00;
    void FUN_00a8f460(S00a6ec10_Display* display);
};

struct __declspec(align(16)) S00a6ec10_Viewer
{
    float scale;
    int unk04;
    int unk08;
    int unk0c;
    S00a6ec10_Vec4 unk10;
    S00a6ec10_Vec4 unk20;
    S00a6ec10_Vec4 unk30;
    S00a6ec10_Vec4 pivotB;
    S00a6ec10_Vec4 pivotA;
    S00a6ec10_Rotation rotB;
    S00a6ec10_Rotation rotA;
    S00a6ec10_C0 unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    S00a6ec10_Geom arc;

    void FUN_00a6aa20(S00a6ec10_Input* input, S00a6ec10_Transform& a, S00a6ec10_Transform& b);
    void FUN_00a6a7b0(int id);
    void FUN_00a6a750(int id);
    void FUN_00a6ec10(S00a6ec10_Input* input, S00a6ec10_Display* display, int id);
};

// pdb: hkpLimitedHingeDrawer::drawConstraint | hkpLimitedHingeDrawer.obj | fnv360_0822_retail, call_gap, low
// pdb params: constraint, displayHandler, id, tag
void S00a6ec10_Viewer::FUN_00a6ec10(S00a6ec10_Input* input, S00a6ec10_Display* display, int id)
{
    S00a6ec10_Constraint* data = input->constraint;
    unkC0.FUN_00a8f460(display);

    S00a6ec10_Transform transA;
    S00a6ec10_Transform transB;
    FUN_00a6aa20(input, transA, transB);
    pivotA.hkVector4_setTransformedPos(transA, data->pivot90);
    pivotB.hkVector4_setTransformedPos(transB, data->pivot50);
    FUN_00a6a7b0(id);
    FUN_00a6a750(id);

    S00a6ec10_Vec4 perp;
    S00a6ec10_Vec4 axis;
    axis.hkVector4_setRotatedDir(rotA, data->axis60);
    perp.hkVector4_setRotatedDir(rotA, data->perp80);

    display->displayLine(pivotB, pivotA, 0xffff0000, id);

    {
        S00a6ec10_Vec4 end;
        S00a6ec10_Vec4 start;
        end.setMul4((float)(scale * 0.5), axis);
        end.add4(pivotA);
        start.setMul4((float)(scale * -0.5), axis);
        start.add4(pivotA);
        display->displayLine(start, end, FUN_00921880(0.0f, 0.5f, 1.0f, 1.0f), id);
    }

    if (data->limitsEnabled)
    {
        float maxA = data->maxAngle;
        float minA = data->minAngle;
        if (maxA - minA < 100000000376832.0)
        {
            arc.FUN_00a6ac00(1.5f, minA, maxA, 0x18, pivotA, axis, perp);
            S00a6ec10_Array<S00a6ec10_Geom*> geoms;
            geoms.setSize(1);
            geoms[0] = &arc;
            display->displayGeometry(geoms, -1, id);
        }
    }

    {
        S00a6ec10_Vec4 start;
        S00a6ec10_Vec4 end;
        start = pivotA;
        end.setAddMul4(start, perp, (float)(scale * 0.5));
        display->displayLine(start, end, 0xffffff00, id);
        S00a6ec10_Vec4 dir;
        dir.hkVector4_setRotatedDir(rotB, data->dir40);
        dir.normalize3();
        start = pivotB;
        end.setAddMul4(start, dir, (float)(scale * 0.5));
        display->displayLine(start, end, 0xffffff00, id);
    }
}
}   // namespace f3m_00a6ec10

// @f3 0x00a6c270 (community match, verified in this file)
#include <math.h>
#include <windows.h>
namespace ZA6C270 {
struct Rotation;
struct Transform;
struct ScalarQ
{
    float value;
    ScalarQ() {}
    void SetInverse(float a) { value = a != 0.0f ? (float)(1.0 / (float)sqrt((double)a)) : 0.0f; }
};
struct __declspec(align(16)) Vec {
 float x,y,z,w;
 __forceinline void fill(const float& value) {x=value;y=value;z=value;w=value;}
 void hkVector4_setRotatedDir(const Rotation*,const Vec*);
 void hkVector4_setTransformedPos(const Transform*,const Vec*);
 const float& operator()(int i) const { return (&x)[i]; }
 void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
 __forceinline void setCross(const Vec& a1,const Vec& a2)
 {
  // Fake match: named copies of the two references steer the product operand order.
  const Vec& v1=a1; const Vec& v2=a2;
  const float nx=v1(1)*v2(2)-v1(2)*v2(1);
  const float ny=v1(2)*v2(0)-v1(0)*v2(2);
  const float nz=v1(0)*v2(1)-v1(1)*v2(0);
  x=nx;y=ny;z=nz;w=0.0f;
 }
 void mul4(const float& rs) { float s=rs; x*=s;y*=s;z*=s;w*=s; }
 __forceinline void normalize() { float length=x*x+y*y+z*z; ScalarQ r; r.SetInverse(length); mul4(r.value); }
};
inline float absReal(float r) { return (float)fabs((double)r); }
// Fake match: this helper computes two cross-product terms and discards them. Its one call at the end of the
// function emits no code; the two dead float locals only shift the compiler's float temporaries so that the first
// squared length reloads y before x and squares x first, as the original does.
__forceinline void discardedCrossTerms(const Vec& v1,const Vec& v2) {const float nx=v1.y*v2.z-v1.z*v2.y;const float ny=v1.z*v2.x-v1.x*v2.z;}
struct Rotation { Vec col0,col1,col2; const Vec& getColumn(int i) const { return (&col0)[i]; } };
// Fake match: the wrapper level only steers which operand of each product is loaded first in the first cross product.
__forceinline void crossNorm(Vec& d,const Vec& a,const Vec& b) { d.setCross(a,b); d.normalize(); }

struct Transform { Rotation rotation; Vec translation; };
extern Vec DAT_01092a50;
extern double DAT_00dce6b8;
extern float DAT_00dbe1e0,DAT_00dbea4c;
struct Mat {
unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
Rotation rotationA;
Rotation rotationB;
unsigned unk080;
unsigned unk084;
unsigned unk088;
unsigned unk08c;
unsigned unk090;
unsigned unk094;
unsigned unk098;
unsigned unk09c;
float angle;
unsigned unk0a4;
unsigned unk0a8;
unsigned unk0ac;
float limit0;
float limit1;};
struct P1 { unsigned unk00,unk04,unk08;Mat* mat; };
struct PtrVec { void** buf; int len; int cap; };
struct Renderer { virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void draw(PtrVec*,unsigned,int); };
struct DrawHelper {unsigned unk00,unk04,unk08,unk0c; void FUN_00a8f460(Renderer*);void FUN_00a8f9c0(const Vec*,const Vec*,const Vec*,unsigned,float,int);};
struct ArcShape {
unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
unsigned unk040;
unsigned unk044;
unsigned unk048;
unsigned unk04c;
unsigned unk050;
unsigned unk054;
unsigned unk058;
unsigned unk05c;
unsigned unk060;
unsigned unk064;
unsigned unk068;
unsigned unk06c;
unsigned unk070;
unsigned unk074;
unsigned unk078;
unsigned unk07c;
unsigned unk080;
unsigned unk084;
unsigned unk088;
unsigned unk08c;void FUN_00a6ba40(float,float,int,const Vec*,const Vec*);};
struct Quad {void FUN_00a6b470(const Vec*,const Vec*,const Vec*,const Vec*);};
struct Allocator {void FUN_008f6d90(void*,int,int);};
extern unsigned DAT_010f3170;
extern void __cdecl FUN_00901e90(PtrVec*,int,int);
extern unsigned __cdecl FUN_00921850(int,int,int,int);
struct This {
unsigned unk000;
unsigned unk004;
unsigned unk008;
float size;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
Vec m40;
Vec m50;
Rotation m60;
Rotation m90;
DrawHelper mC0;
ArcShape mD0;
ArcShape m160;
ArcShape m1f0;Quad m280;
void FUN_00a6c270(P1*,Renderer*,int);
void FUN_00a6aa20(P1*,Transform*,Transform*);
void FUN_00a6a750(int);
};
// pdb: hkpConstraintChainDrawer::drawConstraint | hkpConstraintChainDrawer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: constraint, displayHandler, id, tag
void This::FUN_00a6c270(P1* p1,Renderer* renderer,int tag) {
 Mat* mat=p1->mat;
 // Fake match: the const copy of the handler and the two named rotation references below only steer product operand order.
 Renderer* const rend=renderer;
 Vec* anchor;
 mC0.FUN_00a8f460(rend);
 { Transform a,b;FUN_00a6aa20(p1,&a,&b);(anchor=&m50)->hkVector4_setTransformedPos(&a,&DAT_01092a50);m40.hkVector4_setTransformedPos(&b,&DAT_01092a50); }
 FUN_00a6a750(tag);
 const Rotation& rA=m60;
 const Rotation& rB=m90;
 const Rotation& b=mat->rotationB;
 Vec t80;t80.hkVector4_setRotatedDir(&rB,&b.getColumn(0));
 Vec t70;crossNorm(t70,b.getColumn(0),b.getColumn(1));t70.hkVector4_setRotatedDir(&rB,&t70);
 Vec t60;t60.hkVector4_setRotatedDir(&rB,&b.getColumn(1));
 // Fake match: the volatile view below makes the rotation address live in a stack slot, as the original has it.
 const Rotation* aHome=&mat->rotationA;
 const Rotation& a=*aHome;
 Vec temp;temp.setCross(a.col1,a.col0);temp.normalize();
 Vec t90;t90.hkVector4_setRotatedDir(&rA,&temp);
 Vec tc0;tc0.hkVector4_setRotatedDir(&rA,&(*(const Rotation* volatile*)&aHome)->col0);
 mC0.FUN_00a8f9c0(anchor,&t80,&t70,0xff008000,size,tag);
 mC0.FUN_00a8f9c0(&m40,&tc0,&t90,FUN_00921850(255,255,0,255),size,tag);
 mD0.FUN_00a6ba40(mat->angle,DAT_00dbe1e0,24,&t80,anchor);
 Vec scale;scale.fill(DAT_00dbea4c);
 Quad* quad=&m280;quad->FUN_00a6b470(&t60,&t70,anchor,&scale);
 float limit0=mat->limit0;
 m160.FUN_00a6ba40((float)(DAT_00dce6b8-(double)absReal(mat->limit1)),DAT_00dbe1e0,24,&t60,anchor);
 t60.x=-t60.x;t60.y=-t60.y;t60.z=-t60.z;t60.w=-t60.w;
 m1f0.FUN_00a6ba40((float)(DAT_00dce6b8-(double)absReal(limit0)),DAT_00dbe1e0,24,&t60,anchor);
 PtrVec vec1,vec3,vec2;
 vec1.buf=0;vec1.len=0;vec1.cap=0x80000000;
 vec3.buf=0;vec3.len=0;vec3.cap=0x80000000;
 vec2.buf=0;vec2.len=0;vec2.cap=0x80000000;
 FUN_00901e90(&vec1,1,4);vec1.len=1;
 if((vec2.cap&0x3fffffff)<1) {int n=(vec2.cap&0x3fffffff)*2;if(n<=1)n=1;FUN_00901e90(&vec2,n,4);}vec2.len=1;
 if((vec3.cap&0x3fffffff)<2) {int n=(vec3.cap&0x3fffffff)*2;if(n<=2)n=2;FUN_00901e90(&vec3,n,4);}vec3.len=2;
 vec1.buf[0]=&mD0;vec3.buf[0]=&m160;vec3.buf[1]=&m1f0;vec2.buf[0]=quad;
 renderer->draw(&vec1,0xffffff00,tag);renderer->draw(&vec3,0xffff0000,tag);renderer->draw(&vec2,FUN_00921850(255,0,255,255),tag);
 if(!(vec2.cap&0x80000000)) {int capacity=vec2.cap&0x3fffffff;Allocator* heap=(Allocator*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(vec2.buf,capacity*4,23);}
 if(!(vec3.cap&0x80000000)) {int capacity=vec3.cap&0x3fffffff;Allocator* heap=(Allocator*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(vec3.buf,capacity*4,23);}
 // Fake match: dead call, see discardedCrossTerms above.
 discardedCrossTerms(m60.col1,m90.col2);
 if(!(vec1.cap&0x80000000)) {int capacity=vec1.cap&0x3fffffff;Allocator* heap=(Allocator*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(vec1.buf,capacity*4,23);}
}

}

// @f3 0x00a65740 (community match, verified in this file)
#include <math.h>
#include <new>
#include <windows.h>

namespace GeometryBuildA65740 {
struct Transform;
struct Builder;
struct Geometry;
struct DisplayObject;
using f3m_00a76580::ShapeBuffer;

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline Vec4() {}
    __forceinline Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
    __forceinline Vec4(const Vec4& other) {*this=other;}
    __forceinline Vec4& operator=(const Vec4& other) {
        x=other.x; y=other.y; z=other.z; w=other.w; return *this;
    }
    // Fake match: the nine dead int locals and the float copy of b only shift the compiler's symbol numbering;
    // with them the first and fourth height-field points multiply the scale's y lane first, as the original does.
    __forceinline void Set(float a,float b,float c,float d=0.0f) {
        int pad0=5; int pad1=6; int pad2=7; int pad3=8; int pad4=9; int pad5=10; int pad6=11; int pad7=12; int pad8=13;
        float lane1=b;
        (*this)(0)=a; (*this)(1)=lane1; (*this)(2)=c; (*this)(3)=d;
    }
    // Fake match: a second set helper without the copy, used only by the two middle height-field points so that
    // their y lanes stay height-first.
    __forceinline void SetDirect(float a,float b,float c,float d=0.0f) {(*this)(0)=a;(*this)(1)=b;(*this)(2)=c;(*this)(3)=d;}
    __forceinline float& Component(int index) {return (&x)[index];}
    __forceinline const float& Component(int index) const {return (&x)[index];}
    __forceinline void SetComponent(int index,float value) {Component(index)=value;}
    __forceinline void SetZero() {(*this)(0)=(*this)(1)=(*this)(2)=(*this)(3)=0.0f;}
    __forceinline void SetAdd(const Vec4& a,const Vec4& b) {x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
    __forceinline void SetSub(const Vec4& a,const Vec4& b) {x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
    __forceinline void SetMul(const Vec4& a,const Vec4& b) {x=a.x*b.x;y=a.y*b.y;z=a.z*b.z;w=a.w*b.w;}
    __forceinline void Add(const Vec4& a) {x+=a.x;y+=a.y;z+=a.z;w+=a.w;}
    __forceinline void Mul(const Vec4& a) {(*this)(0)*=a.x;(*this)(1)*=a.y;(*this)(2)*=a.z;(*this)(3)*=a.w;}
    __forceinline void Scale(const float& s) {float r=s;x*=r;y*=r;z*=r;w*=r;}
    __forceinline const float& operator()(int index) const {return (&x)[index];}
    __forceinline float& operator()(int index) {return (&x)[index];}
    void hkVector4_setTransformedPos(const Transform& transform,const Vec4& source) throw();
    __forceinline float Dot3(const Vec4& a) const {return (*this)(0)*a(0)+(*this)(1)*a(1)+(*this)(2)*a(2);}
    __forceinline float LengthSquared3() const {return Dot3(*this);}
    __forceinline float Length3() const {return static_cast<float>(sqrt(LengthSquared3()));}
};
struct __declspec(align(16)) Transform {
    Vec4 basis0, basis1, basis2, translation;
    __forceinline Transform() {}
    __forceinline Vec4& Column(int index) {return (&basis0)[index];}
    __forceinline void SetIdentityRotation() {
        basis0.Set(0.0f,0.0f,0.0f,0.0f);
        basis1.Set(0.0f,0.0f,0.0f,0.0f);
        basis2.Set(0.0f,0.0f,0.0f,0.0f);
        Column(0)(0)=1.0f;
        Column(1)(1)=1.0f;
        Column(2)(2)=1.0f;
    }
    __forceinline void SetIdentity() {SetIdentityRotation();translation.SetZero();}
    Transform& FUN_008fda60(const Transform& source) throw();
    void hkTransform_setMul(const Transform& parent,const Transform& local) throw();
};
struct __declspec(align(16)) Aabb {Vec4 minimum,maximum;};
struct __declspec(align(16)) Sphere {
    Vec4 centerAndRadius;
    __forceinline Sphere() {}
    Sphere(const Vec4& center,float radius) throw();
};
struct __declspec(align(16)) Ray {
    Vec4 start,end;
    Ray(const Ray& source) throw();
};
struct Triangle {
    int a,b,c;
    __forceinline Triangle() {}
    __forceinline Triangle(int first,int second,int third):a(first),b(second),c(third) {}
    __forceinline void Set(int first,int second,int third) {a=first;b=second;c=third;}
};
struct Flag {
    bool value;
    __forceinline Flag() {}
};

struct ThreadMemory {
    virtual ~ThreadMemory() throw();
    virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void* StackAlloc(int bytes) throw();
    virtual void StackFree(void* marker) throw();
    unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    char* stackCurrent;
    unsigned int unk24;
    char* stackChunkBoundary;
    char* stackLimit;
    unsigned int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
    void* geometryFreeList;
    int geometryFreeCount;
    void* FUN_008f6d30(int bytes,int memoryClass) throw();
    void FUN_008f6d90(void* data,int byteSize,int memoryClass) throw();
    void* FUN_008f6800(int sizeClass,int memoryClass) throw();
    __forceinline void* AllocateChunk3() {
        void* slot=geometryFreeList;
        if (slot) {
            --geometryFreeCount;
            geometryFreeList=*static_cast<void**>(slot);
            return slot;
        }
        return FUN_008f6800(3,0x27);
    }
};
extern unsigned long DAT_010f3170;
__forceinline ThreadMemory* GetMemory() {
    return static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
}
void __cdecl FUN_00901e90(void* array,int capacity,int elementBytes) throw();
void __cdecl FUN_00901f10(void* array,int elementBytes) throw();
template<class T> struct Array {
    T* data;
    int size;
    unsigned int capacityFlags;
    __forceinline void Init() {data=0;size=0;capacityFlags=0x80000000u;}
    __forceinline int Capacity() const {return capacityFlags&0x3fffffffu;}
    __forceinline void Reserve(int needed) {
        int capacity=Capacity();
        if (capacity<needed) {
            int grown=capacity*2;
            int target=(needed<grown)?grown:needed;
            FUN_00901e90(this,target,sizeof(T));
        }
    }
    __forceinline void Resize(int count) {Reserve(count);size=count;}
    __forceinline T* ExpandBy(int count) {
        int old=size;
        Resize(old+count);
        return data+old;
    }
    __forceinline T& ExpandOne() {return *ExpandBy(1);}
    __forceinline void Append(const T& value) {
        if (size==Capacity()) FUN_00901f10(this,sizeof(T));
        data[size]=value;
        ++size;
    }
    __forceinline void Release() {
        if ((capacityFlags&0x80000000u)==0)
            GetMemory()->FUN_008f6d90(data,Capacity()*sizeof(T),0x17);
    }
    __forceinline T* Begin() {return data;}
};
template<class T> __forceinline T* AllocateStack(int count) {
    ThreadMemory* memory=GetMemory();
    int bytes=(count*sizeof(T)+1+15)&~15;
    char* current=memory->stackCurrent;
    char* next=current+bytes;
    if (next<=memory->stackLimit) {
        memory->stackCurrent=next;
        return reinterpret_cast<T*>(current);
    }
    return static_cast<T*>(memory->StackAlloc(bytes));
}
__forceinline void DeallocateStack(void* block) {
    ThreadMemory* memory=GetMemory();
    memory->stackCurrent=static_cast<char*>(block);
    if (block==memory->stackChunkBoundary) memory->StackFree(block);
}
template<class T> struct LocalArray : Array<T> {
    T* localMemory;
    __forceinline LocalArray(int capacity) {
        Init();
        data=AllocateStack<T>(capacity);
        capacityFlags=static_cast<unsigned int>(capacity)|0x80000000u;
        localMemory=data;
    }
    __forceinline void Finish() {
        DeallocateStack(localMemory);
        Release();
    }
};
struct Geometry {
    Array<Vec4> vertices;
    Array<Triangle> triangles;
    inline Geometry() {vertices.Init();triangles.Init();}
    __forceinline void* operator new(size_t) {
        return GetMemory()->AllocateChunk3();
    }
    __forceinline void operator delete(void*) {}
};
struct StridedVertices {const void* data;int count;int stride;};
void __cdecl FUN_009ec800(const StridedVertices& input,Geometry* output,int option) throw();

struct ReferenceObject {
    virtual ~ReferenceObject() throw();
    unsigned short allocationSize;
    unsigned short references;
};
struct DisplayObject : ReferenceObject {
    virtual ~DisplayObject() throw();
    Geometry* geometry;
    Transform transform;
    int displayKind;
};
struct DisplaySphere : DisplayObject {
    Sphere sphere;
    int firstDetail,secondDetail;
    DisplaySphere(const Sphere& value,int first,int second) throw();
};
struct DisplayPlane : DisplayObject {
    Vec4 plane,center,axis,halfExtents;
    DisplayPlane(const Vec4& equation,const Vec4& direction,const Vec4& middle,const Vec4& extents) throw();
};
struct DisplayCapsule : DisplayObject {
    Vec4 firstEnd,secondEnd;
    float radius;
    int firstDetail,secondDetail;
    DisplayCapsule(const Vec4& first,const Vec4& second,float radius,int firstDetail,int secondDetail) throw();
};
struct DisplayCylinder : DisplayObject {
    Vec4 firstEnd,secondEnd;
    float radius;
    int firstDetail,secondDetail;
    DisplayCylinder(const Vec4& first,const Vec4& second,float radius,int firstDetail,int secondDetail) throw();
};
struct DisplayBox : DisplayObject {
    Vec4 halfExtents;
    DisplayBox(const Vec4& value) throw();
};
struct DisplayMesh : DisplayObject {DisplayMesh(Geometry* mesh) throw();};
enum {
    CheckVec4Size=1/(sizeof(Vec4)==0x10),
    CheckTransformSize=1/(sizeof(Transform)==0x40),
    CheckGeometrySize=1/(sizeof(Geometry)==0x18),
    CheckDisplayBaseSize=1/(sizeof(DisplayObject)==0x60),
    CheckSphereDisplaySize=1/(sizeof(DisplaySphere)==0x80),
    CheckPlaneDisplaySize=1/(sizeof(DisplayPlane)==0xa0),
    CheckCapsuleDisplaySize=1/(sizeof(DisplayCapsule)==0x90),
    CheckCylinderDisplaySize=1/(sizeof(DisplayCylinder)==0x90),
    CheckBoxDisplaySize=1/(sizeof(DisplayBox)==0x70),
    CheckMeshDisplaySize=1/(sizeof(DisplayMesh)==0x60)
};
struct AllocationHeader {unsigned int vtableWord;unsigned short allocationSize,references;};
template<class T> __forceinline void* AllocateRef() {
    void* memory=GetMemory()->FUN_008f6d30(sizeof(T),8);
    static_cast<AllocationHeader*>(memory)->allocationSize=sizeof(T);
    return memory;
}

struct ShapeContainer;
struct Shape : ReferenceObject {
    virtual ~Shape() throw();
    virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual ShapeContainer* GetContainer() const throw();
    virtual void v18();
    virtual void GetAabb(const Transform& transform,float tolerance,Aabb& result) const throw();
    virtual void v20();
    virtual int GetVertexCount() const throw();
    virtual const Vec4* GetVertices(Vec4* scratch) const throw();
    virtual float GetHeight(int first,int second) const throw();
    virtual Flag GetTriangleFlip() const throw();
    unsigned int userData;
    int type;
};
struct ShapeContainer {
    virtual ~ShapeContainer() throw();
    virtual void v04();
    virtual unsigned int FirstKey() const throw();
    virtual unsigned int NextKey(unsigned int key) const throw();
    virtual void v10();
    virtual const Shape* GetChild(unsigned int key,ShapeBuffer& buffer) const throw();
};
struct SphereShape : Shape {float radius;};
struct MultiSphereShape : Shape {
    int count;
    unsigned int unk14,unk18,unk1c;
    Vec4 spheres[8];
    __forceinline const Vec4* GetSpheres() const {return &spheres[0];}
};
struct PlaneShape : Shape {Vec4 equation;};
struct SegmentShape : Shape {
    float radius,secondRadius;
    unsigned int unk18,unk1c;
    Vec4 first,second;
    float FUN_009e5240() const throw();
    __forceinline float GetRadius() const {return radius;}
};
struct BoxShape : Shape {unsigned int unk10,unk14,unk18,unk1c;Vec4 halfExtents;};
struct RayShape : Shape {const Ray* records;int count;};
struct TranslateShape : Shape {
    float radius;
    unsigned int unk14;
    const Shape* child;
    unsigned int unk1c;
    Vec4 translation;
};
struct ConvexTransformShape : Shape {
    float radius;
    unsigned int unk14;
    const Shape* child;
    unsigned int unk1c;
    Transform local;
};
struct TransformShape : Shape {
    unsigned int unk10;
    const Shape* child;
    unsigned int unk18,unk1c,unk20,unk24,unk28,unk2c;
    Transform local;
};
struct ChildShape : Shape {const Shape* child;};
struct TriangleShape : Shape {
    unsigned int unk10,unk14,unk18,unk1c;
    Vec4 vertices[3];
    Vec4 extrusion;
    __forceinline const Vec4& GetVertex(int i) const {return vertices[i];}
    __forceinline const Vec4& GetExtrusion() const {return extrusion;}
};
struct TriangleCollection : Shape, ShapeContainer {
};
struct TriangleKeysShape : Shape {
    unsigned int unk10,unk14,unk18,unk1c;
    TriangleCollection* collection;
    const unsigned int* keys;
    int count;
};
struct HeightfieldShape : Shape {
    int xCount,zCount;
    unsigned int unk18,unk1c;
    Vec4 scale;
};
extern Vec4 DAT_01092a50;
extern const Transform DAT_010f3370;
extern const double DAT_00db7de8;
extern const float DAT_00db7df0;
extern const double DAT_00dc8028;
extern const float DAT_00eaad58;
extern const double DAT_00db38a8;
extern const double DAT_00db38b0;

struct Builder {
    unsigned int unk00,unk04;
    int detailA,detailB;
    DisplayMesh* cachedMesh;
    DisplayMesh* FUN_00a65650(Array<DisplayObject*>& output) throw();
    void FUN_00a65740(const Shape* shape,const Transform& parent,Array<DisplayObject*>& output);
};
typedef void (__cdecl* ShapeCallback)(const Shape*,const Transform&,Array<DisplayObject*>&,Builder*);
struct Handler {ShapeCallback callback;int type;};
struct Registry {unsigned int unk00,unk04;Array<Handler> entries;};
extern Registry* DAT_0116c4a0;


// pdb: hkpShapeDisplayBuilder::buildShapeDisplay | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, objrun, medium
// pdb params: shape, transform, displayGeometries
void Builder::FUN_00a65740(const Shape* shape,const Transform& parent,Array<DisplayObject*>& output)
{
    switch (shape->type)
    {
    case 2:
    {
        const SphereShape* sphereShape = static_cast<const SphereShape*>(shape);
        Vec4 center;
        center.SetZero();
        Sphere sphere(center,sphereShape->radius);
        DisplaySphere* display = new (AllocateRef<DisplaySphere>()) DisplaySphere(sphere,detailB,detailA);
        display->transform.FUN_008fda60(parent);
        output.Append(display);
        return;
    }
    case 20:
    {
        const MultiSphereShape* spheres = static_cast<const MultiSphereShape*>(shape);
        const Vec4* v = spheres->GetSpheres();
        for (int i=0;i<spheres->count;++i)
        {
            Sphere sphere;
            sphere.centerAndRadius.x=DAT_01092a50.x;
            sphere.centerAndRadius.y=DAT_01092a50.y;
            sphere.centerAndRadius.z=DAT_01092a50.z;
            sphere.centerAndRadius.w=v[i].w;
            DisplaySphere* display = new (AllocateRef<DisplaySphere>()) DisplaySphere(sphere,detailB,detailA);
            display->transform.SetIdentity();
            display->transform.translation = v[i];
            output.Append(display);
        }
        return;
    }
    case 27:
    {
        const PlaneShape* plane = static_cast<const PlaneShape*>(shape);
        const Vec4& equation = plane->equation;
        Aabb bounds;
        shape->GetAabb(DAT_010f3370,0.001f,bounds);
        Vec4 center;
        center.SetSub(bounds.maximum,bounds.minimum);
        Vec4 axis;
        axis.SetZero();
        Vec4 magnitude;
        magnitude(0) = static_cast<float>(fabs(center(0)));
        magnitude(1) = static_cast<float>(fabs(center(1)));
        magnitude(2) = static_cast<float>(fabs(center(2)));
        int major;
        if (magnitude.x<magnitude.y)
            major = magnitude.y<magnitude.z ? 2 : 1;
        else
            major = magnitude.x<magnitude.z ? 2 : 0;
        axis.SetComponent(major,1.0f);
        center.Scale(0.5f);
        Vec4 halfExtents = center;
        center.Add(bounds.minimum);
        DisplayPlane* display = new (AllocateRef<DisplayPlane>()) DisplayPlane(equation,axis,center,halfExtents);
        display->transform.FUN_008fda60(parent);
        output.Append(display);
        return;
    }
    case 6:
    {
        const SegmentShape* capsule = static_cast<const SegmentShape*>(shape);
        DisplayCapsule* display = new (AllocateRef<DisplayCapsule>()) DisplayCapsule(capsule->second,capsule->first,
                                                                                capsule->GetRadius(),6,1);
        display->transform.FUN_008fda60(parent);
        output.Append(display);
        return;
    }
    case 3:
    {
        const SegmentShape* cylinder = static_cast<const SegmentShape*>(shape);
        Vec4 first;
        first.hkVector4_setTransformedPos(parent,cylinder->second);
        Vec4 second;
        second.hkVector4_setTransformedPos(parent,cylinder->first);
        DisplayCylinder* display = new (AllocateRef<DisplayCylinder>()) DisplayCylinder(first,second,
                                                                                      cylinder->FUN_009e5240(),9,1);
        display->transform.FUN_008fda60(parent);
        output.Append(display);
        return;
    }
    case 23:
    {
        const RayShape* rays = static_cast<const RayShape*>(shape);
        Geometry* geometry = FUN_00a65650(output)->geometry;
        int base = 0;
        for (int i=0;i<rays->count;++i)
        {
            Ray ray(rays->records[i]);
            {
                Vec4& vertex = geometry->vertices.ExpandOne();
                vertex = ray.start;
                vertex.hkVector4_setTransformedPos(parent,vertex);
            }
            {
                Vec4& vertex = geometry->vertices.ExpandOne();
                Vec4 offset;
                offset.Set(0.01f,0.0f,0.0f,0.0f);
                vertex.SetAdd(ray.start,offset);
            }
            {
                Vec4& vertex = geometry->vertices.ExpandOne();
                vertex = ray.end;
                vertex.hkVector4_setTransformedPos(parent,vertex);
            }
            Triangle& triangle = geometry->triangles.ExpandOne();
            triangle.Set(base,base+1,base+2);
            base += 3;
        }
        return;
    }
    case 5:
    {
        const BoxShape* box = static_cast<const BoxShape*>(shape);
        DisplayBox* display = new (AllocateRef<DisplayBox>()) DisplayBox(box->halfExtents);
        display->transform.FUN_008fda60(parent);
        output.Append(display);
        return;
    }
    case 12:
    {
        const TranslateShape* translated = static_cast<const TranslateShape*>(shape);
        Transform local;
        local.SetIdentityRotation();
        local.translation = translated->translation;
        Transform combined;
        combined.hkTransform_setMul(parent,local);
        FUN_00a65740(translated->child,combined,output);
        return;
    }
    case 13:
    {
        const ConvexTransformShape* transformed = static_cast<const ConvexTransformShape*>(shape);
        Transform combined;
        combined.hkTransform_setMul(parent,transformed->local);
        FUN_00a65740(transformed->child,combined,output);
        return;
    }
    case 28:
    {
        const TransformShape* transformed = static_cast<const TransformShape*>(shape);
        Transform combined;
        combined.hkTransform_setMul(parent,transformed->local);
        FUN_00a65740(transformed->child,combined,output);
        return;
    }
    case 26:
    {
        const ChildShape* wrapper = static_cast<const ChildShape*>(shape);
        FUN_00a65740(wrapper->child,parent,output);
        return;
    }
    case 9:
    case 11:
    {
        ShapeContainer* container = shape->GetContainer();
        unsigned int key = container->FirstKey();
        if (key!=0xffffffffu)
        {
            ShapeBuffer scratch;
            do
            {
                const Shape* child = container->GetChild(key,scratch);
                FUN_00a65740(child,parent,output);
                key = container->NextKey(key);
            } while (key!=0xffffffffu);
        }
        return;
    }
    case 8:
    case 10:
    case 15:
    case 21:
    case 22:
    {
        ShapeContainer* container = shape->GetContainer();
        ShapeBuffer scratch;
        for (unsigned int key=container->FirstKey();key!=0xffffffffu;key=container->NextKey(key))
        {
            const Shape* child = container->GetChild(key,scratch);
            FUN_00a65740(child,parent,output);
        }
        return;
    }
    case 4:
    {
        const TriangleShape* triangle = static_cast<const TriangleShape*>(shape);
        Geometry* geometry = FUN_00a65650(output)->geometry;
        const int firstVertex = geometry->vertices.size;
        geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,triangle->vertices[0]);
        geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,triangle->vertices[1]);
        geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,triangle->vertices[2]);

        Triangle& base = geometry->triangles.ExpandOne();
        base.Set(firstVertex,firstVertex+1,firstVertex+2);

        const Vec4& extrusion = triangle->GetExtrusion();
        if (extrusion.Length3() > 0.0f)
        {
            Vec4 firstExtruded;
            Vec4 secondExtruded;
            Vec4 thirdExtruded;
            firstExtruded.SetAdd(triangle->GetVertex(0),triangle->GetExtrusion());
            secondExtruded.SetAdd(triangle->GetVertex(1),triangle->GetExtrusion());
            thirdExtruded.SetAdd(triangle->GetVertex(2),triangle->GetExtrusion());
            geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,firstExtruded);
            geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,secondExtruded);
            geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,thirdExtruded);

            Triangle* sides = geometry->triangles.ExpandBy(7);
            sides[0].Set(firstVertex+3,firstVertex+1,firstVertex);
            sides[1].Set(firstVertex+3,firstVertex+4,firstVertex+1);
            sides[2].Set(firstVertex+4,firstVertex+5,firstVertex+1);
            sides[3].Set(firstVertex+5,firstVertex+2,firstVertex+1);
            sides[4].Set(firstVertex+5,firstVertex,firstVertex+2);
            sides[5].Set(firstVertex+5,firstVertex+3,firstVertex);
            sides[6].Set(firstVertex+5,firstVertex+4,firstVertex+3);
        }
        return;
    }
    case 7:
    {
        int count = shape->GetVertexCount();
        LocalArray<Vec4> raw(count);
        raw.Resize(count);
        const Vec4* source = shape->GetVertices(raw.Begin());

        Array<Vec4> transformed;
        transformed.Init();
        transformed.Resize(count);
        for (int i=0;i<count;++i)
            transformed.data[i].hkVector4_setTransformedPos(parent,source[i]);

        Geometry* geometry = new Geometry;
        StridedVertices input;
        input.count = transformed.size;
        input.stride = sizeof(Vec4);
        input.data = transformed.data;
        FUN_009ec800(input,geometry,1);
        DisplayMesh* display = new (AllocateRef<DisplayMesh>()) DisplayMesh(geometry);
        output.Append(display);
        transformed.Release();
        raw.Finish();
        return;
    }
    case 19:
    {
        const TriangleKeysShape* compound = static_cast<const TriangleKeysShape*>(shape);
        Geometry* geometry = new Geometry;

        for (int keyIndex=0;keyIndex<compound->count;++keyIndex)
        {
            ShapeBuffer buffer;
            const Shape* child = compound->collection->GetChild(compound->keys[keyIndex],buffer);
            const TriangleShape* triangle = static_cast<const TriangleShape*>(child);
            Triangle& indices = geometry->triangles.ExpandOne();
            const int firstVertex = geometry->vertices.size;
            indices.Set(firstVertex,firstVertex+1,firstVertex+2);

            const Vec4* vertex = triangle->vertices;
            for (int vertexIndex=0;vertexIndex<3;++vertexIndex)
                geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,vertex[vertexIndex]);
        }

        DisplayMesh* display = new (AllocateRef<DisplayMesh>()) DisplayMesh(geometry);
        output.Append(display);
        return;
    }
    case 14:
    {
        const HeightfieldShape* heightfield = static_cast<const HeightfieldShape*>(shape);
        Geometry* geometry = FUN_00a65650(output)->geometry;
        Vec4 scale = heightfield->scale;

        for (int i=0;i<heightfield->xCount-1;i++)
        {
            for (int j=0;j<heightfield->zCount-1;j++)
            {
                const int nextRow = i+1;
                const int nextColumn = j+1;
                Vec4 first;
                first.Set(i+0.f,heightfield->GetHeight(i,j),j+0.f);
                first.Mul(scale);
                Vec4 second;
                second.SetDirect(i+0.f,heightfield->GetHeight(i,nextColumn),j+1.f);
                second.Mul(scale);
                Vec4 third;
                third.SetDirect(i+1.f,heightfield->GetHeight(nextRow,j),j+0.f);
                third.Mul(scale);
                Vec4 fourth;
                fourth.Set(i+1.f,heightfield->GetHeight(nextRow,nextColumn),j+1.f);
                fourth.Mul(scale);

                const int firstVertex = geometry->vertices.size;
                geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,first);
                geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,second);
                geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,third);
                geometry->vertices.ExpandOne().hkVector4_setTransformedPos(parent,fourth);

                if (heightfield->GetTriangleFlip().value)
                {
                    Triangle& firstTriangle = geometry->triangles.ExpandOne();
                    firstTriangle.Set(firstVertex,firstVertex+1,firstVertex+3);
                    Triangle& secondTriangle = geometry->triangles.ExpandOne();
                    secondTriangle.Set(firstVertex,firstVertex+3,firstVertex+2);
                }
                else
                {
                    Triangle& firstTriangle = geometry->triangles.ExpandOne();
                    firstTriangle.Set(firstVertex,firstVertex+1,firstVertex+2);
                    Triangle& secondTriangle = geometry->triangles.ExpandOne();
                    secondTriangle.Set(firstVertex+3,firstVertex+2,firstVertex+1);
                }
            }
        }
        return;
    }

    default:
    {
        for (int index=0;index<DAT_0116c4a0->entries.size;++index)
        {
            Handler& handler=DAT_0116c4a0->entries.data[index];
            if (handler.type==shape->type)
                handler.callback(shape,parent,output,this);
        }
        return;
    }
    }
}
}

// @f3 0x00a7bcf0 (community match, verified in this file)
namespace f3m_00a7bcf0 {
// 0x00a7bcf0: hkPoweredChain_BuildConstraintMatrixAndLuDecomposition(int numConstraints, const hkpCfmParam& cfm,
// hkp3dAngularMotorSolverInfo* motorsState, hkp1Lin2AngJacobian* j, hkp2AngJacobian* jAng,
// hkpVelocityAccumulatorOffset* va, const hkpVelocityAccumulator* accumsBase, hkpConstraintChainMatrix6Triple* triples,
// int bufferSize) of Havok 5.5.0 (hkpConstraintSolver, hkpPoweredChainSolverUtil.cpp, compiled with /MT /Ox /Ob1 /Oi
// /Ot /GF /GS-). Builds the powered chain's block-tridiagonal 6x6 constraint matrix, row by row: the diagonal block
// from the jacobians of the row's two bodies (with the cfm terms on its diagonal) and the off-diagonal block to the
// next row through the body they share; then the LU decomposition one row at a time.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The library's own types that no SDK header ships
// (hkpCfmParam, hkpConstraintChainMatrix6Triple, the two jacobian classes, hkpVelocityAccumulatorOffset) are declared
// from the hkpConstraintSolver library's debug records (members, types, order, method signatures; the parameters'
// restrict qualifiers); the bodies of the inline helpers (the two per-row matrix blocks and the jacobian products)
// follow the SDK's unoptimized (hybrid) library object, which this source reproduces, and the release object.
// Only the function carries the packet's name.
namespace f3m_00a7bcf0 {

typedef unsigned char	hkUint8;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
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
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
inline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
	;
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
inline void hkMatrix3::_setTranspose( const hkMatrix3& s )
{
	hkMatrix3& d = *this;
	d(0,0) = s(0,0);
	d(1,1) = s(1,1);
	d(2,2) = s(2,2);
	d(3,0) = 0.0f;
	d(3,1) = 0.0f;
	d(3,2) = 0.0f;
	d(1,0) = s(0,1);
	d(0,1) = s(1,0);
	d(2,0) = s(0,2);
	d(0,2) = s(2,0);
	d(2,1) = s(1,2);
	d(1,2) = s(2,1);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
struct hkp1dMotorSolverInfo
{
    __forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1dMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkp3dAngularMotorSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp3dAngularMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	typedef hkUint8 Status;
	enum Mask
	{
		ANGULAR_1ST = 0x03,
		ANGULAR_2ND = 0x0c,
		ANGULAR_3RD = 0x30,
	};
	enum MotorState
	{
		MOTOR_NOT_BROKEN          = 0x00,
		MOTOR_BROKEN_MAX_BREACHED = 0x01,
		MOTOR_BROKEN_MIN_BREACHED = 0x03,
		MOTOR_DISABLED = 0x02
	};
	Status m_broken;
	inline int getState(int idx) const
	{
		;
		return (m_broken >> (2 * idx)) & ANGULAR_1ST;
	}
	inline void setState(int idx, int value)
	{
		;
		const int shiftedValue  = (value & ANGULAR_1ST) << (2 * idx);
		const int shiftedMask   = ANGULAR_1ST << (2 * idx);
		m_broken &= hkUint8(~shiftedMask);
		m_broken |= hkUint8(shiftedValue);
	}
	hkp1dMotorSolverInfo m_motorInfos[3];
};
class hkMatrix6
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix6), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix6() { }
		__forceinline void operator= ( const hkMatrix6& a )
		{
			m_m[0][0] = a.m_m[0][0];
			m_m[0][1] = a.m_m[0][1];
			m_m[1][0] = a.m_m[1][0];
			m_m[1][1] = a.m_m[1][1];
		}
		__forceinline void setZero()
		{
			m_m[0][0].setZero();
			m_m[0][1].setZero();
			m_m[1][0].setZero();
			m_m[1][1].setZero();
		}
		__forceinline void setIdentity()
		{
			m_m[0][0].setIdentity();
			m_m[0][1].setZero();
			m_m[1][0].setZero();
			m_m[1][1].setIdentity();
		}
		__forceinline void setTranspose( const hkMatrix6& s )
		{
			m_m[0][0].setTranspose( s.m_m[0][0] );
			m_m[0][1].setTranspose( s.m_m[1][0] );
			m_m[1][0].setTranspose( s.m_m[0][1] );
			m_m[1][1].setTranspose( s.m_m[1][1] );
		}
		__forceinline void setMul( const hkMatrix6& a, const hkMatrix6& b )
		{
			hkMatrix3 tmp;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					tmp      ._setMul( a.m_m[i][0], b.m_m[0][j] );
					m_m[i][j]._setMul( a.m_m[i][1], b.m_m[1][j] );
					m_m[i][j]._add( tmp );
				}
			}
		}
		__forceinline void add( const hkMatrix6& a )
		{
			m_m[0][0]._add( a.m_m[0][0] );
			m_m[0][1]._add( a.m_m[0][1] );
			m_m[1][0]._add( a.m_m[1][0] );
			m_m[1][1]._add( a.m_m[1][1] );
		}
		__forceinline void sub( const hkMatrix6& a )
		{
			m_m[0][0]._sub( a.m_m[0][0] );
			m_m[0][1]._sub( a.m_m[0][1] );
			m_m[1][0]._sub( a.m_m[1][0] );
			m_m[1][1]._sub( a.m_m[1][1] );
		}
		__forceinline void mul( const hkMatrix6& a)
		{
			hkMatrix6 temp;
			temp.setMul( *this, a );
			*this = temp;
		}
		__forceinline void mul( hkSimdRealParameter scale )
		{
			m_m[0][0]._setMul(scale, m_m[0][0]);
			m_m[0][1]._setMul(scale, m_m[0][1]);
			m_m[1][0]._setMul(scale, m_m[1][0]);
			m_m[1][1]._setMul(scale, m_m[1][1]);
		}
		void setInvert( const hkMatrix6& in );
	public:
		__declspec(align(16)) hkMatrix3 m_m[2][2];
};
class hkpVelocityAccumulator
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulator), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return reinterpret_cast<hkRotation&>(m_scratch1); }
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return m_scratch1; }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return m_scratch1; }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		void setAngularRhs( hkReal v );
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		hkReal getAngularRhsSr() const;
		hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp2AngJacobian& jacB ) const;
};
class hkp1Lin2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1Lin2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		hkp2AngJacobian& as2AngJacobian_internal();
		void setRHS( hkReal v );
		inline const hkReal& getRHS() const { return m_linear0(3); }
		hkReal& getRHS();
		const hkSimdReal getRhsSr() const;
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		hkReal getUserValue() const;
		hkReal getUserValueSr() const;
		void setUserValue( hkReal v );
		hkReal getDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulatorOffset), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpVelocityAccumulatorOffset( const hkpVelocityAccumulator* base, const hkpVelocityAccumulator* accumulator );
		hkpVelocityAccumulatorOffset();
		inline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<const hkpVelocityAccumulator*>( reinterpret_cast<const char*>(base) + m_offset );
		}
		inline hkpVelocityAccumulator& getAccumulator( hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<hkpVelocityAccumulator*>( reinterpret_cast<char*>(base) + m_offset );
		}
		unsigned m_offset;
};
struct hkpConstraintChainMatrix6Triple
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintChainMatrix6Triple), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkMatrix6 m_lower;
	hkMatrix6 m_diagonalInv;
	hkMatrix6 m_upper;
	hkMatrix6 m_mtxDiag;
	hkMatrix6 m_mtxNextOffdiag;
};
struct hkpCfmParam
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCfmParam), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkReal m_linAdd;
	hkReal m_linMul;
	hkReal m_angAdd;
	hkReal m_angMul;
};
__forceinline hkp2AngJacobian& hkp1Lin2AngJacobian::as2AngJacobian_internal()
{
	return *reinterpret_cast<hkp2AngJacobian*>( &m_angular[0] );
}
__forceinline hkReal hkp2AngJacobian::getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const
{
	const hkp2AngJacobian& jacA = *this;
	hkVector4 ang0; ang0.setMul4( jacA.m_angular[0], jacB.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jacA.m_angular[1], jacB.m_angular[1] );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	ang0.add4( ang1 );
	const hkReal result = ang0.horizontalAdd3();
	return result;
}
__forceinline hkReal hkp2AngJacobian::getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const
{
	return getNonDiagOptimized( mA, mB, jacB );
}
__forceinline hkReal hkp2AngJacobian::getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp2AngJacobian& jacB ) const
{
	const hkp2AngJacobian& jacA = *this;
	hkVector4 ang; ang.setMul4( jacA.m_angular[1], jacB.m_angular[0] );
	ang.mul4( mA.m_invMasses );
	const hkReal result = ang.horizontalAdd3();
	return result;
}
__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const
{
	const hkp1Lin2AngJacobian& jacA = *this;
	hkVector4 lin; lin.setMul4( jacA.m_linear0, jacB.m_linear0 );
	hkVector4 ang0; ang0.setMul4( jacA.m_angular[0], jacB.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jacA.m_angular[1], jacB.m_angular[1] );
	hkVector4 massA; massA.setBroadcast3clobberW( mA.m_invMasses, 3 );
	hkVector4 massB; massB.setBroadcast3clobberW( mB.m_invMasses, 3 );
	hkVector4 linA; linA.setMul4( massA, lin );
	hkVector4 linB; linB.setMul4( massB, lin );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	linA.add4( linB );
	ang0.add4( ang1 );
	ang0.add4( linA );
	const hkReal result = ang0.horizontalAdd3();
	return result;
}
__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const
{
	return getNonDiagOptimized( mA, mB, jacB );
}
__forceinline hkReal hkp1Lin2AngJacobian::getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const
{
	const hkp1Lin2AngJacobian& jacA = *this;
	hkVector4 lin; lin.setMul4( jacA.m_linear0, jacB.m_linear0 );
	hkVector4 ang; ang.setMul4( jacA.m_angular[1], jacB.m_angular[0] );
	hkVector4 mass; mass.setBroadcast3clobberW( mA.m_invMasses, 3 );
	hkVector4 linA; linA.setMul4( mass, lin );
	ang.mul4( mA.m_invMasses );
	ang.sub4( linA );
	const hkReal result = ang.horizontalAdd3();
	return result;
}
extern "C" void __cdecl hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow( hkBool isNotLastRow, hkpConstraintChainMatrix6Triple& triple, hkp3dAngularMotorSolverInfo* motorsState, hkMatrix6& mtxPrevOffdiag, hkMatrix6*& triplePrevUpper );
extern "C" __forceinline void __cdecl hkPoweredChain_ComputeConstraintMatrix_DiagonalAtRow( int row, const hkpCfmParam& cfm, hkp1Lin2AngJacobian* __restrict j, hkp2AngJacobian* __restrict jAng, hkpVelocityAccumulatorOffset* __restrict va, const hkpVelocityAccumulator* accumsBase, hkMatrix6& mtxDiag )
{
	const int stride = 3;
	const int index = row * stride;
	int r;
	for ( r = 0; r < 3; r++ )
	{
		for ( int c = r; c < 3; c++ )
		{
			const hkpVelocityAccumulator& mA = va[row].getAccumulator( accumsBase );
			const hkpVelocityAccumulator& mB = va[row + 1].getAccumulator( accumsBase );
			mtxDiag.m_m[0][0]( c, r ) = mtxDiag.m_m[0][0]( r, c ) = j[index + r].getNonDiagSameObjects( mA, mB, j[index + c] );
			mtxDiag.m_m[1][1]( c, r ) = mtxDiag.m_m[1][1]( r, c ) = jAng[index + r].getNonDiagSameObjects( mA, mB, jAng[index + c] );
		}
		mtxDiag.m_m[0][0]( r, r ) *= cfm.m_linMul;
		mtxDiag.m_m[1][1]( r, r ) *= cfm.m_angMul;
		mtxDiag.m_m[0][0]( r, r ) += cfm.m_linAdd;
		mtxDiag.m_m[1][1]( r, r ) += cfm.m_angAdd;
	}
	for ( r = 0; r < 3; r++ )
	{
		for ( int c = 0; c < 3; c++ )
		{
			mtxDiag.m_m[1][0]( r, c ) = jAng[index + r].getNonDiagSameObjects( va[row].getAccumulator( accumsBase ), va[row + 1].getAccumulator( accumsBase ), j[index + c].as2AngJacobian_internal() );
		}
	}
	mtxDiag.m_m[0][1]._setTranspose( mtxDiag.m_m[1][0] );
}
extern "C" __forceinline void __cdecl hkPoweredChain_ComputeConstraintMatrix_NextOffDiagonalAtRow( int row, hkp1Lin2AngJacobian* j, hkp2AngJacobian* jAng, hkpVelocityAccumulatorOffset* va, const hkpVelocityAccumulator* accumsBase, hkMatrix6& mtxNextOffdiag )
{
	const int stride = 3;
	const int index = row * stride;
	for ( int r = 0; r < 3; r++ )
	{
		for ( int c = 0; c < 3; c++ )
		{
			const hkpVelocityAccumulator& mB = va[row + 1].getAccumulator( accumsBase );
			mtxNextOffdiag.m_m[0][0]( r, c ) = j[index + r].getNonDiagDifferentObjects_With2ndBodyFromFirstObject( mB, j[index + stride + c] );
			mtxNextOffdiag.m_m[1][1]( r, c ) = jAng[index + r].getNonDiagDifferentObjects_With2ndBodyFromFirstObject( mB, jAng[index + stride + c] );
			mtxNextOffdiag.m_m[0][1]( r, c ) = j[index + r].as2AngJacobian_internal().getNonDiagDifferentObjects_With2ndBodyFromFirstObject( mB, jAng[index + stride + c] );
			mtxNextOffdiag.m_m[1][0]( r, c ) = jAng[index + r].getNonDiagDifferentObjects_With2ndBodyFromFirstObject( mB, j[index + stride + c].as2AngJacobian_internal() );
		}
	}
}
// pdb: hkPoweredChain_BuildConstraintMatrixAndLuDecomposition | hkpPoweredChainSolverUtil.obj | fnv360_1110_retail, objrun, medium
// pdb params: numConstraints, cfm, motorsState, j, jAng, va, accumsBase, triples, bufferSize
void __cdecl FUN_00a7bcf0( int numConstraints, const hkpCfmParam& cfm, hkp3dAngularMotorSolverInfo* motorsState, hkp1Lin2AngJacobian* __restrict j, hkp2AngJacobian* __restrict jAng, hkpVelocityAccumulatorOffset* __restrict va, const hkpVelocityAccumulator* accumsBase, hkpConstraintChainMatrix6Triple* triples, int bufferSize )
{
	hkMatrix6 mtxPrevOffdiag; mtxPrevOffdiag.setZero();
	hkMatrix6* triplePrevUpper = &mtxPrevOffdiag;
	int row;
	for ( row = 0; row < numConstraints; row++ )
	{
		hkPoweredChain_ComputeConstraintMatrix_DiagonalAtRow( row, cfm, j, jAng, va, accumsBase, triples[row].m_mtxDiag );
		if ( row < numConstraints - 1 )
		{
			hkPoweredChain_ComputeConstraintMatrix_NextOffDiagonalAtRow( row, j, jAng, va, accumsBase, triples[row].m_mtxNextOffdiag );
		}
		else
		{
			triples[row].m_mtxNextOffdiag.setZero();
		}
	}
	for ( row = 0; row < numConstraints; row++ )
	{
		hkBool isNotLastRow = numConstraints - 1 - row != 0;
		hkp3dAngularMotorSolverInfo* localmotorsState = &motorsState[row];
		hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow( isNotLastRow, triples[row], localmotorsState, mtxPrevOffdiag, triplePrevUpper );
	}
}

}  // namespace f3m_00a7bcf0
}   // namespace f3m_00a7bcf0

// @f3 0x00a72e90 (community match, verified in this file)
// 0x00a72e90: hkpMultiRayShape::getAabbImpl(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
// of Havok 5.5.0 (hkpCollide, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Transforms the start and end points of all rays into world space (into a local 16-ray inplace array) and returns
// the box around them.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The function body follows the SDK's unoptimized (hybrid) library
// object statement by statement and reproduces the release object. Only the function carries the packet's name.
namespace f3m_00a72e90 {

typedef float  hkReal;
typedef signed short	hkInt16;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
template < typename T , unsigned N > class hkInplaceArray;
template <typename T, unsigned N>
class hkInplaceArrayAligned16 : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(mytype), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkInplaceArrayAligned16(int size = 0);
		__forceinline ~hkInplaceArrayAligned16(){}
		hkArray<T>& operator= (const hkArray<T>& a);
		hkArray<T>& operator= (const hkInplaceArrayAligned16<T,N>& a);
		inline hkBool wasReallocated() const;
	protected:
		int m_padding;
		__declspec(align(16)) hkReal m_storage[sizeof(T)/sizeof(hkReal) * N];
	public:
		hkInplaceArrayAligned16(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
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
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}
template <typename T, unsigned N>
__forceinline hkInplaceArrayAligned16<T,N>::hkInplaceArrayAligned16(int size)
	: hkArray<T>( (T*)&m_storage[0], size, N)
{
}
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
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
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
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
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
hkTransform::hkTransform(const hkTransform& t)
{
	const hkVector4 r0 = t.m_rotation.getColumn(0);
	const hkVector4 r1 = t.m_rotation.getColumn(1);
	const hkVector4 r2 = t.m_rotation.getColumn(2);
	const hkVector4 r3 = t.m_rotation.getColumn(3);
	m_rotation.getColumn(0) = r0;
	m_rotation.getColumn(1) = r1;
	m_rotation.getColumn(2) = r2;
	m_rotation.getColumn(3) = r3;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
class hkAabb
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkAabb), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline hkBool overlaps( const hkAabb& testAabb ) const;
		hkBool isValid() const;
		__forceinline hkBool contains(const hkAabb& other) const;
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkpMultiRayShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct Ray
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMultiRayShape::Ray), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkVector4 m_start;
			hkVector4 m_end;
		};
	public:
		hkpMultiRayShape( const Ray* rays, int nRays, hkReal rayPenetrationDistance = 0.0f );
 		void FUN_00a72e90( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out  ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		inline const hkArray<Ray>& getRays() const{ return m_rays; }
		inline hkReal getRayPenetrationDistance() const{ return m_rayPenetrationDistance; }
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		hkArray<struct Ray> m_rays;
		hkReal m_rayPenetrationDistance;
	public:
		hkpMultiRayShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag), m_rays(flag) { m_type = HK_SHAPE_MULTI_RAY; }
};
namespace hkVector4Util
{
__forceinline void __cdecl transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	;
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setTransformedPos( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
void hkpMultiRayShape::FUN_00a72e90( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	hkInplaceArrayAligned16<Ray,16> worldRays;
	worldRays.setSize( m_rays.getSize() );
	hkVector4Util::transformPoints( localToWorld, &m_rays[0].m_start, m_rays.getSize() * 2, &worldRays[0].m_start );
	hkVector4 absMin; absMin.setAll( 3.40282e+38f );
	hkVector4 absMax; absMax.setAll( -3.40282e+38f );
	const Ray* ray = &worldRays[0];
	for ( int i = 0; i < worldRays.getSize(); i++ )
	{
		absMin.setMin4( absMin, ray->m_end );
		absMin.setMin4( absMin, ray->m_start );
		absMax.setMax4( absMax, ray->m_end );
		absMax.setMax4( absMax, ray->m_start );
		ray++;
	}
	out.m_min = absMin;
	out.m_max = absMax;
}

}  // namespace f3m_00a72e90

// @f3 0x00a73380 (community match, verified in this file)
// 0x00a73380: hkpReorientAction::applyAction(const hkStepInfo& stepInfo) of Havok 5.5.0 (hkpUtilities, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Turns the body back upright about its rotation axis: the angle between the body's up axis and the up axis
// projected onto the plane of the rotation axis, signed by whether the cross product agrees with the rotation axis,
// gives an angular impulse along the rotation axis, damped by the body's angular velocity.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names.
namespace f3m_00a73380 {

typedef float  hkReal;
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
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
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
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
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
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
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
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
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
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		__forceinline hkSmallArray();
		explicit __forceinline hkSmallArray(int size);
		__forceinline ~hkSmallArray();
		__forceinline int getSize() const;
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
extern "C" {
double  __cdecl acos(     double _X);
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float acosf(     float _X)
        {return ((float)acos((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
inline hkReal __cdecl acos(hkReal r)
	{
		;
		if( hkMath::fabs(r) >= 1.0f )
		{
			r = ( r>0 )	? 0 : 3.14159265358979f;
			return r;
		}
		return acosf(r);
	}
inline int __cdecl isNegative(hkReal r0)
	{
		return (r0<0)? hkVector4Comparison::MASK_X : 0;
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
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
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
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
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
inline int hkVector4::getMajorAxis() const
{
	hkVector4 tmp;
	tmp.setAbs4(*this);
	return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
}
inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody(  ){}
		friend class hkpCollidable;
		__forceinline hkpCdBody( const hkpShape* shape, const hkMotionState* motionState );
		__forceinline hkpCdBody( const hkpShape* shape, const hkTransform* t );
		__forceinline hkpCdBody( const hkpCdBody& body ){}
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline hkpShapeKey getShapeKey() const ;
		__forceinline const hkpCdBody* getParent() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkMotionState* ms );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpTypedBroadPhaseHandle( int type );
		__forceinline hkpTypedBroadPhaseHandle( void* owner, int type );
		__forceinline int getType() const;
		__forceinline void setOwner(void* o);
		__forceinline void* getOwner() const;
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		hkpTypedBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ) : hkpBroadPhaseHandle(flag) {}
	protected:
		enum { OFFSET_INVALID = 127 };
		inline void setType( int type );
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
struct hkAabbUint32;
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline hkpCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpCollidable();
		inline const hkpShape* getShape() const;
		inline void setShape(const hkpShape* shape);
		inline void setOwner( void* owner );
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
		void checkPerformance();
		inline const hkpTypedBroadPhaseHandle* getBroadPhaseHandle() const;
		inline       hkpTypedBroadPhaseHandle* getBroadPhaseHandle();
		__forceinline hkpCollidableQualityType getQualityType() const;
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
	public:
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline int getType() const;
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				BoundingVolumeData();
				__forceinline const hkAabbUint32& getAabbUint32() const { return reinterpret_cast<const hkAabbUint32&>(m_min); }
				__forceinline       hkAabbUint32& getAabbUint32()		  { return reinterpret_cast<      hkAabbUint32&>(m_min); }
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
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
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		__forceinline bool isMarkedForWrite( )
		{
			return true;
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		__forceinline void unmarkForRead( )
		{
			;
		}
		__forceinline void unmarkForWrite()
		{
			;
		}
		void disableChecks();
		void enableChecks();
		bool isCheckingEnabled() const;
		void accessCheck( AccessType type ) const;
		static void __cdecl accessCheckWithParent( const hkMultiThreadCheck* parentLock, AccessType parentType, const hkMultiThreadCheck& lock, AccessType type );
		static void staticInit();
		static void staticQuit();
	protected:
		void markForReadImpl(ReadMode mode  );
		void markForWriteImpl( );
		bool isMarkedForWriteImpl( );
		void unmarkForReadImpl( );
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkpPropertyValue;
class hkpWorld;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void addProperty( hkUint32 key, hkpPropertyValue value );
		hkpPropertyValue removeProperty( hkUint32 key );
		void editProperty( hkUint32 key, hkpPropertyValue value );
		inline hkpPropertyValue getProperty( hkUint32 key ) const;
		inline hkBool hasProperty( hkUint32 key ) const;
		void lockProperty( hkUint32 key );
		void unlockProperty( hkUint32 key );
		inline void unlockPropertiesFromLoadedObject();
		inline void clearAndDeallocateProperties();
		inline hkpCollidable* getCollidableRw();
		inline const hkpCollidable* getCollidable() const;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline const hkpLinkedCollidable* getLinkedCollidable() const;
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
class hkpMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpMaterial();
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		inline void setFriction( hkReal newFriction );
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
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
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
	hkpMotion(const hkVector4& position, const hkQuaternion& rotation, bool wantDeactivation = false);
	hkReal getMass() const;
	inline hkSimdReal getMassInv() const;
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline const hkVector4& getCenterOfMassLocal() const;
	inline const hkVector4& getCenterOfMassInWorld() const;
	inline hkMotionState* getMotionState();
	inline const hkMotionState* getMotionState() const;
	inline const hkVector4& getPosition() const;
	virtual void setPosition(const hkVector4& position);
	inline const hkQuaternion& getRotation() const;
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	void approxTransformAt( hkTime time, hkTransform& transformOut );
	virtual void setTransform(const hkTransform& transform);
	inline const hkVector4& getLinearVelocity() const;
	virtual void setLinearVelocity(const hkVector4& newVel);
	inline const hkVector4& getAngularVelocity() const;
	virtual void setAngularVelocity(const hkVector4& newVel);
	__forceinline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
	inline hkReal getLinearDamping();
	inline void setLinearDamping( hkReal d );
	inline hkReal getAngularDamping();
	inline void setAngularDamping( hkReal d );
	inline int getDeactivationClass();
	void setDeactivationClass(int deactivationClass);
	inline void enableDeactivation( bool value, int randomNumber = 0, int worldFlag0 = 0, int worldFlag1 = 0, int worldDeactivationIntegrateCounter = 0);
	inline bool isActivationEnabled() const;
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
	inline int getNumInactiveFrames(int select);
	inline int getNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void setWorldSelectFlagsNeg(int worldFlag0, int worldFlag1, int worldDeactivationIntegrateCounter);
	inline void incrementNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void zeroNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
const hkQuaternion& hkpMotion::getRotation() const
{
	return m_motionState.getSweptTransform().m_rotation1;
}
const hkVector4& hkpMotion::getAngularVelocity() const
{
	return m_angularVelocity;
}
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	protected:
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpSimulationIsland;
class hkpConstraintInstance;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		void activate();
		void deactivate();
		void activateAsCriticalOperation();
		void deactivateAsCriticalOperation();
		hkBool isActive() const;
		inline int getNumActions() const;
		inline hkpAction* getAction(int i);
		int getNumConstraints() const;
		hkpConstraintInstance* getConstraint( int i );
		const hkpConstraintInstance* getConstraint( int i ) const;
		inline const hkSmallArray<struct hkConstraintInternal>&  getConstraintMasters() const;
		inline hkSmallArray<struct hkConstraintInternal>&  getConstraintMastersRw();
		inline const hkArray<class hkpConstraintInstance*>&  getConstraintSlaves() const;
		void calcStatistics( hkStatisticsCollector* collector) const;
		void setCachedShapeData(const hkpWorld* world, const hkpShape* shape);
		void updateCachedAabb();
	protected:
		const	hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersImpl() const;
				hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersRwImpl();
		const	hkArray<class hkpConstraintInstance*>&	getConstraintSlavesImpl() const;
		hkpEntity( const hkpShape* shape );
	public:
		hkpEntity( class hkFinishLoadedObjectFlag flag );
		inline hkpMotion* getMotion();
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SpuCollisionCallback():
				m_util(0),
				m_capacity(0),
				m_eventFilter(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
				m_userFilter(0x01)
			{
			}
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
class hkpPhantom;
class hkStepInfo;
class hkpAction : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpAction(hkUlong userData);
		virtual ~hkpAction() { }
		virtual void applyAction( const hkStepInfo& stepInfo ) = 0;
		virtual void getEntities( hkArray<hkpEntity*>& entitiesOut ) = 0;
		virtual void getPhantoms( hkArray<hkpPhantom*>& phantomsOut ) {}
		inline hkpWorld* getWorld();
		virtual void entityRemovedCallback(hkpEntity* entity) = 0;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline const char* getName() const;
		inline void setName( const char* name );
		virtual hkpAction* clone( const hkArray<hkpEntity*>& newEntities, const hkArray<hkpPhantom*>& newPhantoms ) const = 0;
	private:
		hkpWorld* m_world;
		hkpSimulationIsland* m_island;
	protected:
		hkUlong m_userData;
		const char* m_name;
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		friend class hkpSimulationIsland;
	public:
		inline hkpSimulationIsland* getSimulationIsland();
	public:
		inline void setSimulationIsland(hkpSimulationIsland* island);
		inline void setWorld( hkpWorld* owner );
	public:
		hkpAction( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
class hkpEntityDeactivator : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool shouldDeactivateHighFrequency( const hkpEntity* entity ) = 0;
		virtual hkBool shouldDeactivateLowFrequency( const hkpEntity* entity ) = 0;
	protected:
		hkpEntityDeactivator() {}
	public:
		hkpEntityDeactivator( class hkFinishLoadedObjectFlag flag ) {}
};
class hkpRigidBodyDeactivator : public hkpEntityDeactivator
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum DeactivatorType
		{
			DEACTIVATOR_INVALID,
			DEACTIVATOR_NEVER,
			DEACTIVATOR_SPATIAL,
			DEACTIVATOR_MAX_ID
		};
		virtual enum DeactivatorType getRigidBodyDeactivatorType() const = 0;
};
class hkpRigidBodyCinfo;
class hkpRigidBody : public hkpEntity
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpRigidBody( const hkpRigidBodyCinfo& info );
		virtual ~hkpRigidBody();
		void getCinfo(hkpRigidBodyCinfo& info) const;
		inline hkReal getMass() const;
		inline hkReal getMassInv() const;
		void setMass(hkReal m);
		void setMassInv(hkReal mInv);
		inline void getInertiaLocal(hkMatrix3& inertiaOut) const;
		inline void getInertiaWorld(hkMatrix3& inertiaOut) const;
		void setInertiaLocal(const hkMatrix3& inertia);
		void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		inline void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		inline void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		void setCenterOfMassLocal(const hkVector4& centerOfMass);
		inline const hkVector4& getCenterOfMassLocal() const;
		inline const hkVector4& getCenterOfMassInWorld() const;
		inline const hkVector4& getPosition() const;
		void setPosition(const hkVector4& position);
		inline const hkQuaternion& getRotation() const;
		void setRotation(const hkQuaternion& rotation);
		void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
		inline const hkTransform& getTransform() const;
		void setTransform(const hkTransform& transform);
		void setPositionAndRotationAsCriticalOperation(const hkVector4& position, const hkQuaternion& rotation);
		inline void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		inline void approxCurrentTransform( hkTransform& transformOut ) const;
		inline const hkVector4& getLinearVelocity() const;
		inline void	setLinearVelocity(const hkVector4& newVel);
		inline const hkVector4& getAngularVelocity() const;
		inline void	setAngularVelocity(const hkVector4& newVel);
		inline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
		void setLinearVelocityAsCriticalOperation(const hkVector4& newVel);
		void setAngularVelocityAsCriticalOperation(const hkVector4& newVel);
		inline void applyLinearImpulse(const hkVector4& imp);
		inline void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		inline void applyAngularImpulse(const hkVector4& imp);
		void applyLinearImpulseAsCriticalOperation(const hkVector4& imp);
		void applyPointImpulseAsCriticalOperation(const hkVector4& imp, const hkVector4& p);
		void applyAngularImpulseAsCriticalOperation(const hkVector4& imp);
		inline void applyForce(const hkReal deltaTime, const hkVector4& force);
		inline void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		inline void applyTorque(const hkReal deltaTime, const hkVector4& torque);
		inline hkReal getLinearDamping() const;
		inline void setLinearDamping( hkReal d );
		inline hkReal getAngularDamping() const;
		inline void setAngularDamping( hkReal d );
		inline hkReal getMaxLinearVelocity() const;
		inline void setMaxLinearVelocity( hkReal maxVel );
		inline hkReal getMaxAngularVelocity() const;
		inline void setMaxAngularVelocity( hkReal maxVel );
		void setDeactivator( hkpRigidBodyDeactivator::DeactivatorType rigidBodyDeactivatorType );
		hkpRigidBodyDeactivator::DeactivatorType getDeactivatorType() const;
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline hkpCollidableQualityType getQualityType() const;
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
		void setMotionType( hkpMotion::MotionType newState,
							hkpEntityActivation preferredActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE,
							hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode = HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
		inline hkpMotion::MotionType getMotionType() const;
		hkpMotion* getStoredDynamicMotion();
		const hkpMotion* getStoredDynamicMotion() const;
		void updateCachedShapeInfo (const hkpShape* shape, hkVector4& extentOut );
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		void setFriction( hkReal newFriction );
		void setRestitution( hkReal newRestitution );
		hkWorldOperation::Result setShape(const hkpShape* shape);
		virtual hkpRigidBody* clone() const;
	public:
		inline hkpMotion* getRigidMotion() const;
		void checkPerformance() const;
	public:
		static void __cdecl createDynamicRigidMotion( hkpMotion::MotionType motionType,
																const hkVector4& position, const hkQuaternion& rotation,
																hkReal mass, const hkMatrix3& inertiaLocal, const hkVector4& centreOfMassLocal,
																hkReal maxLinearVelocity, hkReal maxAngularVelocity,
																hkpMaxSizeMotion* motionBufferOut );
		static void __cdecl updateBroadphaseAndResetCollisionInformationOfWarpedBody( hkpEntity* entity );
	protected:
		virtual hkMotionState* getMotionState();
	public:
		hkpRigidBody( class hkFinishLoadedObjectFlag flag ) : hkpEntity( flag ) {}
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const
{
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
inline const hkQuaternion& hkpRigidBody::getRotation() const
{
	return getRigidMotion()->getRotation();
}
inline const hkVector4& hkpRigidBody::getAngularVelocity() const
{
	return getRigidMotion()->getAngularVelocity();
}
inline void hkpRigidBody::applyAngularImpulse(const hkVector4& imp)
{
	;
	activate();
	getRigidMotion()->applyAngularImpulse(imp);
}
class hkpUnaryAction : public hkpAction
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpUnaryAction(hkpEntity* entity = 0, hkUlong userData = 0);
		~hkpUnaryAction();
		virtual void getEntities( hkArray<hkpEntity*>& entitiesOut );
		virtual void entityRemovedCallback(hkpEntity* entity);
		void setEntity(hkpEntity* entity);
		inline hkpEntity* getEntity();
		inline hkpRigidBody* getRigidBody();
		virtual void applyAction( const hkStepInfo& stepInfo ) = 0;
	protected:
		hkpEntity* m_entity;
	public:
		hkpUnaryAction( class hkFinishLoadedObjectFlag flag ) : hkpAction(flag) {}
};
hkpRigidBody* hkpUnaryAction::getRigidBody()
{
	return static_cast<hkpRigidBody*>( m_entity );
}
class hkpReorientAction : public hkpUnaryAction
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpReorientAction();
		hkpReorientAction( hkpRigidBody* body,
			const hkVector4& rotationAxis,
			const hkVector4& upAxis,
			hkReal strength = 1.0f,
			hkReal damping = 0.1f );
		void hkpReorientAction_applyAction( const hkStepInfo& stepInfo );
		virtual hkpAction* clone( const hkArray<hkpEntity*>& newEntities, const hkArray<hkpPhantom*>& newPhantoms ) const;
	public:
		hkVector4 m_rotationAxis;
		hkVector4 m_upAxis;
		hkReal m_strength;
		hkReal m_damping;
	public:
		hkpReorientAction( class hkFinishLoadedObjectFlag flag ) : hkpUnaryAction(flag) {}
};
// pdb: hkpReorientAction::applyAction | hkpReorientAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpReorientAction::hkpReorientAction_applyAction( const hkStepInfo& stepInfo )
{
	hkpRigidBody* rb = getRigidBody();
	hkVector4 bodyUpAxis; bodyUpAxis.setRotatedDir( rb->getRotation(), m_upAxis );
	hkVector4 bodyRotationAxis; bodyRotationAxis.setRotatedDir( rb->getRotation(), m_rotationAxis );
	hkVector4 projectedUpAxis = m_upAxis;
	const hkReal distance = projectedUpAxis.dot3( bodyRotationAxis );
	projectedUpAxis.addMul4( -distance, bodyRotationAxis );
	projectedUpAxis.normalize3();
	hkReal angle = hkMath::acos( bodyUpAxis.dot3( projectedUpAxis ) );
	hkVector4 calculatedRotationAxis; calculatedRotationAxis.setCross( bodyUpAxis, projectedUpAxis );
	const hkReal cra = calculatedRotationAxis( calculatedRotationAxis.getMajorAxis() );
	const hkReal ra = bodyRotationAxis( bodyRotationAxis.getMajorAxis() );
	if ( hkMath::isNegative( cra ) != hkMath::isNegative( ra ) )
	{
		angle = -angle;
	}
	hkVector4 av; av.setMul4( m_damping * stepInfo.m_invDeltaTime, rb->getAngularVelocity() );
	hkVector4 impulse; impulse.setMul4( m_strength * angle * stepInfo.m_invDeltaTime, bodyRotationAxis );
	impulse.sub4( av );
	rb->applyAngularImpulse( impulse );
}

}  // namespace f3m_00a73380

// @f3 0x00a694a0 (community match, verified in this file)
// FUN_00a694a0 = the game's build of Havok 5.5.0 hkpConvexRadiusBuilder::buildShapeDisplay (hkpUtilities.lib,
// hkpConvexRadiusBuilder.obj), written from the SDK library's debug records and the Havok 5.5.0 SDK headers
// (preprocessed and cut by tools\hktrim.py; data members and virtual functions kept). The three file-static
// helpers are defined static here, which gives their calls the private register conventions of the original.
// Game-only difference against the SDK library: a separate HK_SHAPE_CONVEX_LIST case.
// The convex-vertices test is written currentDist > ( RADIUS_EPSILON - convexRadius ): the parentheses emit no code
// (the SDK library's unoptimized build is unchanged by them) but set the x87 operand order at plane 0 of the triangle case;
// with them this source also reproduces the SDK library's release object exactly (hkcheck.py release: MATCH).
// void hkpConvexRadiusBuilder::FUN_00a694a0(class hkpShape const *,class hkTransform const &,class hkArray<class hkDisplayGeometry *> &)  (?FUN_00a694a0@hkpConvexRadiusBuilder@@QAEXPBVhkpShape@@ABVhkTransform@@AAV?$hkArray@PAVhkDisplayGeometry@@@@@Z; Havok 5.5.0 hkpUtilities.lib / hkpConvexRadiusBuilder.obj)
// reduced by hktrim.py from sdk_game2.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
			typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;

class hkBool
{
	public:
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	private:
		TYPE m_storage;
};

		extern "C" {
			extern "C" __declspec(dllimport) void* __stdcall TlsGetValue( unsigned long dwTlsIndex );
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
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

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
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
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
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
		__forceinline void removeReference() const;
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

template <typename T>
class hkSingleton
{
	public:
		static T* s_instance;
		static __forceinline T& __cdecl getInstance()
		{
			return *s_instance;
		}
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
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		typedef T* iterator;
		typedef const T* const_iterator;
		static void __cdecl copy(T* dst, const T* src, int n);
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
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void __cdecl hkArray<T>::copy(T* dst, const T* src, int n)
{
	for(int i = 0; i < n; ++i)
	{
		dst[i] = src[i];
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::hkArray(int n)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().allocateChunk(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
		m_size(n),
		m_capacityAndFlags(n)
{
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>& hkArray<T>::operator= (const hkArray<T>& a)
{
	if(getCapacity() < a.m_size)
	{
		releaseMemory();
		m_data = static_cast<T*>( hkThreadMemory::getInstance().allocateChunk( a.m_size * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY));
		m_capacityAndFlags = a.m_size | (m_capacityAndFlags & static_cast<int>(LOCKED_FLAG));
	}
	m_size = a.m_size;
	copy(m_data, a.m_data, m_size);
	return *this;
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
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

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg4(const hkVector4& v);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
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
		__forceinline hkVector4& getColumn(int i);
		__forceinline hkReal& operator() (int row, int col);
		__forceinline void setZero();
		__forceinline void setIdentity();
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
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		__forceinline void setTranslation(const hkVector4& t);
		void setMul( const hkTransform &t1, const hkTransform &t2 );
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
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

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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

inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}

inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}

inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}

inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}

inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}

void hkTransform::setTranslation(const hkVector4& t)
{
	m_translation = t;
}

const hkTransform& __cdecl hkTransform::getIdentity()
{
	extern hkReal hkTransformIdentity[];
	return reinterpret_cast<const hkTransform&>(hkTransformIdentity);
}

void hkTransform::setIdentity()
{
	m_rotation.setIdentity();
	m_translation.setZero4();
}

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

class hkDisplayGeometry;
class hkpShape;

class hkpConvexRadiusBuilder: public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		struct hkpConvexRadiusBuilderEnvironment
		{
			                class MustEndWithSemiColon;
			float m_minVisibleRadius;
		};
		void FUN_00a694a0(				const hkpShape* shape,
											const hkTransform& transform,
											hkArray<hkDisplayGeometry*>& displayGeometries);
	protected:
		hkpConvexRadiusBuilderEnvironment m_environment;
		hkDisplayGeometry* m_currentGeometry;
};

class hkpUserConvexRadiusBuilder : public hkReferencedObject, public hkSingleton< hkpUserConvexRadiusBuilder >
{
	public:
		typedef void (__cdecl *ConvexRadiusBuilderFunction)(	const hkpShape* shape,
														const hkTransform& transform,
														hkArray<hkDisplayGeometry*>& displayGeometries,
														hkpConvexRadiusBuilder* builder );
	public:
		struct UserShapeBuilder
		{
			                class MustEndWithSemiColon;
			ConvexRadiusBuilderFunction f;
			hkpShapeType type;
		};
		hkArray< UserShapeBuilder > m_userConvexRadiusBuilders;
};

struct hkGeometry
{
	                class MustEndWithSemiColon;
	struct Triangle
	{
		                class MustEndWithSemiColon;
		int m_a;
		int m_b;
		int m_c;
	};
	hkArray<hkVector4> m_vertices;
	hkArray<Triangle> m_triangles;
};

struct hkStridedVertices
{
	                class MustEndWithSemiColon;
	const float* m_vertices;
	int m_numVertices;
	int m_striding;
};

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

enum hkDisplayGeometryType
{
	HK_DISPLAY_RECTANGLE = 0,
	HK_DISPLAY_SPHERE,
	HK_DISPLAY_BOX,
	HK_DISPLAY_AABB,
	HK_DISPLAY_CONE,
	HK_DISPLAY_SEMICIRCLE,
	HK_DISPLAY_CONVEX,
	HK_DISPLAY_PLANE,
	HK_DISPLAY_CAPSULE,
	HK_DISPLAY_CYLINDER
};

class hkDisplayGeometry : public hkReferencedObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_DISPLAY)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; }               class MustEndWithSemiColon;
		virtual ~hkDisplayGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines) = 0;
		virtual void buildGeometry() = 0;
		inline hkTransform& getTransform();
		hkGeometry* m_geometry;
	protected:
		hkTransform m_transform;
		hkDisplayGeometryType m_type;
};

inline hkTransform& hkDisplayGeometry::getTransform()
{
	return m_transform;
}

class hkDisplayCylinder : public hkDisplayGeometry
{
	public:
		hkDisplayCylinder( const hkVector4& top, const hkVector4& bottom, hkReal radius, int numSides = 9, int numHeightSegments = 1 );
		virtual void buildGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines);
	protected:
		hkVector4	m_top;
		hkVector4	m_bottom;
		hkReal		m_radius;
		int m_numSides;
		int m_numHeightSegments;
};

class hkDisplayBox : public hkDisplayGeometry
{
	public:
		hkDisplayBox(const hkVector4& halfExtents);
		virtual void buildGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines);
	protected:
		hkVector4 m_halfExtents;
};

class hkDisplayConvex : public hkDisplayGeometry
{
	public:
		hkDisplayConvex(hkGeometry* geom);
		virtual void buildGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines);
};

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
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
		__forceinline hkpShapeType getType() const;
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
		hkEnum< ::hkpShapeType, hkUint32> m_type;
};

__declspec(align(16)) class hkAlignedShape: public hkpShape{
};

hkpShapeType hkpShape::getType() const
{
	return static_cast<const hkAlignedShape*>(this)->m_type;
}

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

class hkpSingleShapeContainer : public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		~hkpSingleShapeContainer()
		{
			m_childShape->removeReference();
		}
		virtual int getNumChildShapes() const { return 1; }
		virtual hkpShapeKey getFirstKey() const { return 0; }
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const { return 0xffffffff; }
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const;
		inline const hkpShape* getChild() const { return m_childShape; }
	protected:
		const hkpShape* m_childShape;
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
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

class hkpBvTreeShape: public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual void queryObb( const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance, hkArray< hkpShapeKey >& hits ) const = 0;
		virtual void queryAabb( const hkAabb& aabb, hkArray<hkpShapeKey>& hits ) const = 0;
		virtual hkUint32 queryAabb( const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys ) const = 0;
		virtual const hkpShapeContainer* getContainer() const = 0;
};

class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
};

class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		hkReal m_radius;
};

inline hkReal hkpConvexShape::getRadius() const
{
	return m_radius;
}

class hkpBoxShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		inline const hkVector4& getHalfExtents() const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkVector4 m_halfExtents;
	public:
		~hkpBoxShape();
};

inline const hkVector4 &hkpBoxShape::getHalfExtents() const
{
	return m_halfExtents;
}

class hkpConvexTransformShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		inline const hkpConvexShape* getChildShape() const;
		inline const hkTransform& getTransform() const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& parentCdBody, hkpRayHitCollector& collector ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		class hkpSingleShapeContainer m_childShape;
		mutable int m_childShapeSize;
		hkTransform m_transform;
};

inline const hkpConvexShape* hkpConvexTransformShape::getChildShape() const
{
	return static_cast<const hkpConvexShape*>(m_childShape.getChild());
}

inline const hkTransform& hkpConvexTransformShape::getTransform() const
{
	return m_transform;
}

class hkpConvexTranslateShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		inline const hkpConvexShape* getChildShape() const;
		inline const hkVector4& getTranslation() const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		class hkpSingleShapeContainer m_childShape;
		mutable int m_childShapeSize;
		hkVector4 m_translation;
};

inline const hkpConvexShape* hkpConvexTranslateShape::getChildShape() const
{
	return static_cast<const hkpConvexShape*>(m_childShape.getChild());
}

inline const hkVector4& hkpConvexTranslateShape::getTranslation() const
{
	return m_translation;
}

class hkpConvexVerticesConnectivity;

class hkpConvexVerticesShape : public hkpConvexShape
{
	public:
		struct FourVectors
		{
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkVector4 m_x;
			hkVector4 m_y;
			hkVector4 m_z;
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		~hkpConvexVerticesShape();
		void getOriginalVertices( hkArray<hkVector4>& vertices ) const;
		const hkArray<hkVector4>& getPlaneEquations() const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkVector4	m_aabbHalfExtents;
		hkVector4	m_aabbCenter;
		hkArray<struct FourVectors> m_rotatedVertices;
		hkInt32		m_numVertices;
		hkArray<hkVector4>	m_planeEquations;
        mutable const hkpConvexVerticesConnectivity* m_connectivity;
};

class hkpCylinderShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		inline const hkVector4* getVertices() const;
		__forceinline const hkVector4& getVertex(int i) const;
		hkReal getCylinderRadius() const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkReal    m_cylRadius;
		hkReal m_cylBaseRadiusFactorForHeightFieldCollisions;
		hkVector4 m_vertexA;
		hkVector4 m_vertexB;
		hkVector4 m_perpendicular1;
		hkVector4 m_perpendicular2;
	public:
		enum VertexIdEncoding
		{
			VERTEX_ID_ENCODING_IS_BASE_A_SHIFT     = 7,
			VERTEX_ID_ENCODING_SIN_SIGN_SHIFT      = 6,
			VERTEX_ID_ENCODING_COS_SIGN_SHIFT      = 5,
			VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT = 4,
			VERTEX_ID_ENCODING_VALUE_MASK          = 0x0f
		};
	private:
		static hkReal s_virtualTesselationParameter;
		static hkReal s_virtualTesselationParameterInv;
		static hkReal s_intRoundUpThreshold;
};

const hkVector4* hkpCylinderShape::getVertices() const
{
	return &m_vertexA;
}

const hkVector4& hkpCylinderShape::getVertex(int i) const
{
	;
	return (getVertices())[i];
}

class hkpWeldingUtility
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
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
		enum NumAngles
		{
			NUM_ANGLES = 31
		};
	public:
		struct SinCosTableEntry
		{
			                class MustEndWithSemiColon;
			hkReal m_cosAccept0;
			hkReal m_sinAccept0;
			hkReal m_cosSnap0;
			hkReal m_cosSnap1;
			hkReal m_cosAccept1;
			hkReal m_sinAccept1;
		};
		static __declspec(align(16)) SinCosTableEntry m_sinCosTable[NUM_ANGLES+1];
};

class hkpTriangleShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		__forceinline const hkVector4& getVertex(int i) const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkUint16 m_weldingInfo;
		hkEnum<hkpWeldingUtility::WeldingType, hkUint8> m_weldingType;
		hkUint8 m_isExtruded;
		hkVector4 m_vertexA;
		hkVector4 m_vertexB;
		hkVector4 m_vertexC;
		hkVector4 m_extrusion;
};

const hkVector4& hkpTriangleShape::getVertex(int i) const
{
	;
	return (&m_vertexA)[i];
}

class hkpConvexPieceShape : public hkpConvexShape, protected hkpShapeContainer
{
	public:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertex ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getFirstVertex(hkVector4& v) const;
		void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out  ) const;
		virtual hkBool castRayImpl(const hkpShapeRayCastInput& input,hkpShapeRayCastOutput& results) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual int getNumCollisionSpheresImpl( )  const;
		virtual const hkSphere* getCollisionSpheresImpl( hkSphere* sphereBuffer ) const;
		virtual const hkpShapeContainer* getContainer() const;
		virtual hkpShapeKey getFirstKey() const;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const;
	public:
		hkVector4* m_vertices;
		int m_numVertices;
		const hkpShapeCollection* m_displayMesh;
		const hkpShapeKey* m_displayShapeKeys;
		int m_numDisplayShapeKeys;
};

class hkpBvShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		~hkpBvShape();
		inline const hkpShape* getBoundingVolumeShape() const;
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
 		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out  ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
	public:
		const hkpShape*		m_boundingVolumeShape;
		class hkpSingleShapeContainer m_childShape;
};

inline const hkpShape* hkpBvShape::getBoundingVolumeShape() const
{
	return m_boundingVolumeShape;
}

class hkpTransformShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		inline const hkpShape* getChildShape() const;
		inline const hkTransform& getTransform() const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual const hkpShapeContainer* getContainer() const;
	protected:
		class hkpSingleShapeContainer m_childShape;
		hkQuaternion m_rotation;
		hkTransform m_transform;
};

inline const hkpShape* hkpTransformShape::getChildShape() const
{
	return m_childShape.getChild();
}

inline const hkTransform& hkpTransformShape::getTransform() const
{
	return m_transform;
}

class hkpConvexListShape : public hkpConvexShape, public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		~hkpConvexListShape();
		void getSupportingVertexImpl( hkVector4Parameter dir, hkpCdVertex& supportingVertexOut ) const;
		void convertVertexIdsToVerticesImpl( const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getFirstVertex(hkVector4& v) const;
		int getNumCollisionSpheresImpl( )  const;
		const hkSphere* getCollisionSpheresImpl( hkSphere* sphereBuffer ) const;
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape(  hkpShapeKey key, ShapeBuffer& buffer ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual const hkpShapeContainer* getContainer() const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	public:
		hkReal	m_minDistanceToUseConvexHullForGetClosestPoints;
	protected:
		hkVector4	m_aabbHalfExtents;
		hkVector4	m_aabbCenter;
		bool m_useCachedAabb;
	public:
		hkArray<const hkpConvexShape*> m_childShapes;
};

extern hkReal hkDefaultTriangleDegeneracyTolerance;

class hkpTriangleUtil
{
	public:
		static hkBool __cdecl isDegenerate(const hkVector4& a, const hkVector4& b, const hkVector4& c , hkReal tolerance = hkDefaultTriangleDegeneracyTolerance);
};

enum hkpGeomConvexHullMode
{
	HK_GEOM_CONVEXHULL_MODE_INVALID,
	HK_GEOM_CONVEXHULL_MODE_FAST,
	HK_GEOM_CONVEXHULL_MODE_ACCURATE_BUT_SLOW,
	HK_GEOM_CONVEXHULL_MODE_MAX_ID
};

class hkpGeometryUtility
{
public:
	static void __cdecl createConvexGeometry( const hkStridedVertices& stridedVertsIn, hkGeometry& geometryOut, hkpGeomConvexHullMode mode = HK_GEOM_CONVEXHULL_MODE_FAST );
	static void __cdecl createVerticesFromPlaneEquations(  const hkArray<hkVector4>& planeEquationsIn, hkArray<hkVector4>& vertsOut );
};

static float _getPlaneToSurfaceDistance(const hkpConvexVerticesShape* shape)
{
	const hkArray<hkVector4>& planes = shape->getPlaneEquations();
	hkArray<hkVector4> vertices;
	shape->getOriginalVertices( vertices );
	const int numVerts = vertices.getSize();
	const int numPlanes = planes.getSize();
	float closest = -1000.0f;
	for (int v = 0; v < numVerts; v++)
	{
		const hkVector4& vert = vertices[v];
		for (int p = 0; p < numPlanes; p++)
		{
			const float distFromPlane = static_cast<float>(vert.dot3(planes[p])) + planes[p](3);
			if (distFromPlane > closest)
			{
				closest = distFromPlane;
			}
		}
	}
	return closest;
}

static void _addBoundingPlanes(const hkpShape* s, float extraRadius, hkArray<hkVector4>& planes)
{
	hkAabb aabb;
	s->getAabb(hkTransform::getIdentity(), extraRadius, aabb);
	planes.setSize( planes.getSize() + 6 );
	int numPlanes = planes.getSize();
	planes[numPlanes - 6].set( 1, 0, 0, -aabb.m_max(0) );
	planes[numPlanes - 5].set( 0, 1, 0, -aabb.m_max(1) );
	planes[numPlanes - 4].set( 0, 0, 1, -aabb.m_max(2) );
	planes[numPlanes - 3].set( -1, 0, 0, aabb.m_min(0) );
	planes[numPlanes - 2].set( 0, -1, 0, aabb.m_min(1) );
	planes[numPlanes - 1].set( 0, 0, -1, aabb.m_min(2) );
}

static hkDisplayConvex* _createConvexDisplayFromPlanes( const hkArray<hkVector4>& planeEqs, const hkTransform& transform )
{
	hkArray<hkVector4> verts;
	hkpGeometryUtility::createVerticesFromPlaneEquations(planeEqs, verts);
	if (verts.getSize() < 1)
	{
		return 0;
	}
	hkArray<hkVector4> transformedVerts;
	int numVerts = verts.getSize();
	transformedVerts.setSize(numVerts);
	for (int i = 0; i < numVerts; ++i)
	{
		transformedVerts[i].setTransformedPos(transform, verts[i]);
	}
	hkGeometry* outputGeom = new hkGeometry;
	hkStridedVertices stridedVerts;
	stridedVerts.m_numVertices = transformedVerts.getSize();
	stridedVerts.m_striding = sizeof(hkVector4);
	stridedVerts.m_vertices = &(transformedVerts[0](0));
	hkpGeometryUtility::createConvexGeometry( stridedVerts, *outputGeom );
	return new hkDisplayConvex(outputGeom);
}

// pdb: hkpConvexRadiusBuilder::buildShapeDisplay | hkpConvexRadiusBuilder.obj | fnv360_0822_debug, objrun_prop, medium
// pdb params: shape, transform, displayGeometries
void hkpConvexRadiusBuilder::FUN_00a694a0(		const hkpShape* shape,
												const hkTransform& transform,
												hkArray<hkDisplayGeometry*>& displayGeometries)
{
	switch (shape->getType())
	{
		case HK_SHAPE_SPHERE:
		case HK_SHAPE_MULTI_SPHERE:
		case HK_SHAPE_PLANE:
		case HK_SHAPE_CAPSULE:
		case HK_SHAPE_MULTI_RAY:
		case HK_SHAPE_SAMPLED_HEIGHT_FIELD:
			break;
		case HK_SHAPE_CONVEX_TRANSLATE:
		{
			const hkpConvexTranslateShape* ts = static_cast<const hkpConvexTranslateShape*>( shape );
			hkTransform tst; tst.setIdentity();	tst.setTranslation( ts->getTranslation());
			hkTransform T; T.setMul( transform, tst );
			FUN_00a694a0( ts->getChildShape(), T, displayGeometries);
			break;
		}
		case HK_SHAPE_CONVEX_TRANSFORM:
		{
			const hkpConvexTransformShape* ts = static_cast<const hkpConvexTransformShape*>( shape );
			hkTransform T; T.setMul( transform, ts->getTransform() );
			FUN_00a694a0( ts->getChildShape(), T, displayGeometries);
			break;
		}
		case HK_SHAPE_TRANSFORM:
		{
			const hkpTransformShape* ts = static_cast<const hkpTransformShape*>( shape );
			hkTransform T; T.setMul( transform, ts->getTransform() );
			FUN_00a694a0( ts->getChildShape(), T, displayGeometries);
			break;
		}
		case HK_SHAPE_BV:
		{
			const hkpBvShape* bvShape = static_cast<const hkpBvShape*>( shape );
			FUN_00a694a0( bvShape->getBoundingVolumeShape(), transform, displayGeometries);
			break;
		}
		case HK_SHAPE_BV_TREE:
		case HK_SHAPE_MOPP:
		{
			const hkpBvTreeShape* bvShape = static_cast<const hkpBvTreeShape*>( shape );
			const hkpShapeContainer* shapeContainer = bvShape->getContainer();
			hkpShapeCollection::ShapeBuffer buffer;
			for (hkpShapeKey key = shapeContainer->getFirstKey(); key != 0xffffffff; key = shapeContainer->getNextKey( key ) )
			{
				const hkpShape* child = shapeContainer->getChildShape(key, buffer );
				FUN_00a694a0(child, transform, displayGeometries);
			}
			break;
		}
		case HK_SHAPE_CONVEX_LIST:
		{
			const hkpConvexListShape* convexListShape = static_cast<const hkpConvexListShape*>( shape );
			hkpShapeCollection::ShapeBuffer buffer;
			for (hkpShapeKey key = convexListShape->getFirstKey(); key != 0xffffffff; key = convexListShape->getNextKey( key ) )
			{
				const hkpShape* child = convexListShape->getChildShape(key, buffer );
				FUN_00a694a0(child, transform, displayGeometries);
			}
			break;
		}
		case HK_SHAPE_LIST:
		case HK_SHAPE_COLLECTION:
		case HK_SHAPE_TRIANGLE_COLLECTION:
		{
			const hkpShapeContainer* container = shape->getContainer();
			hkpShapeCollection::ShapeBuffer buffer;
			for (hkpShapeKey key = container->getFirstKey(); container && key != 0xffffffff; key = container->getNextKey( key ) )
			{
				const hkpShape* child = container->getChildShape(key, buffer );
				FUN_00a694a0(child, transform, displayGeometries);
			}
			break;
		}
		case HK_SHAPE_CONVEX_PIECE:
		{
			const hkpConvexPieceShape* triangulatedConvexShape = static_cast<const hkpConvexPieceShape*>( shape );
			if ( triangulatedConvexShape->getRadius() > m_environment.m_minVisibleRadius )
			{
				hkpShapeCollection::ShapeBuffer buffer2;
				for ( int i = 0 ; i < triangulatedConvexShape->m_numDisplayShapeKeys ; i++ )
				{
					const hkpTriangleShape& triangleShape = *( static_cast< const hkpTriangleShape* >(
						triangulatedConvexShape->m_displayMesh->getChildShape( triangulatedConvexShape->m_displayShapeKeys[i], buffer2 ) ));
					FUN_00a694a0(&triangleShape, transform, displayGeometries);
				}
			}
			break;
		}
		case HK_SHAPE_CYLINDER:
		{
			const hkpCylinderShape* s = static_cast<const hkpCylinderShape*>(shape);
			float cylRadius = s->getCylinderRadius();
			float convexRadius = s->getRadius();
			if (convexRadius > m_environment.m_minVisibleRadius)
			{
				hkVector4 top;		top.setTransformedPos( transform, s->getVertex(1) );
				hkVector4 bottom;	bottom.setTransformedPos( transform, s->getVertex(0) );
				hkVector4 axis; axis.setSub4(top, bottom); axis.normalize3();
				axis.mul4(convexRadius);
				top.add4(axis);
				bottom.sub4(axis);
				float totalRadius = cylRadius + convexRadius;
				hkDisplayCylinder* displayCylinder = new hkDisplayCylinder( top, bottom, totalRadius );
				displayCylinder->getTransform() = transform;
				displayGeometries.pushBack(displayCylinder);
			}
			break;
		}
		case HK_SHAPE_BOX:
		{
			const hkpBoxShape* boxShape = static_cast<const hkpBoxShape*>(shape);
			float convexRadius = boxShape->getRadius();
			if (convexRadius > m_environment.m_minVisibleRadius)
			{
				hkVector4 trueExtents; trueExtents.setAll(convexRadius);
				trueExtents.add4(boxShape->getHalfExtents());
				hkDisplayBox* displayBox = new hkDisplayBox(trueExtents);
				displayBox->getTransform() = transform;
				displayGeometries.pushBack(displayBox);
			}
			break;
		}
		case HK_SHAPE_TRIANGLE:
		{
			const hkpTriangleShape* triangleShape = static_cast<const hkpTriangleShape*>(shape);
			float convexRadius = triangleShape->getRadius();
			if (convexRadius > m_environment.m_minVisibleRadius)
			{
				const hkVector4& p0 = triangleShape->getVertex(0);
				const hkVector4& p1 = triangleShape->getVertex(1);
				const hkVector4& p2 = triangleShape->getVertex(2);
				if ( hkpTriangleUtil::isDegenerate(p0, p1, p2, 0.001f) )
				{
					break;
				}
				hkVector4 edge01; edge01.setSub4(p1, p0);
				edge01.normalize3();
				hkVector4 edge12; edge12.setSub4(p2, p1);
				edge12.normalize3();
				hkVector4 edge02; edge02.setSub4(p2, p0);
				edge02.normalize3();
				hkVector4 normal; normal.setCross(edge01, edge02);
				hkArray<hkVector4> planes(8);
				planes.setSize(8);
				hkVector4 planePoint;
				hkVector4 convexRadiusNormal;
				planes[0] = normal;
				convexRadiusNormal.setMul4(convexRadius, planes[0]);
				planePoint.setAdd4(convexRadiusNormal, p0);
				planes[0](3) = -planes[0].dot3(planePoint);
				planes[1].setNeg4(normal);
				convexRadiusNormal.setMul4(convexRadius, planes[1]);
				planePoint.setAdd4(convexRadiusNormal, p0);
				planes[1](3) = -planes[1].dot3(planePoint);
				planes[2].setCross(edge01, normal);
				convexRadiusNormal.setMul4(convexRadius, planes[2]);
				planePoint.setAdd4(convexRadiusNormal, p0);
				planes[2](3) = -planes[2].dot3(planePoint);
				planes[3].setCross(edge12, normal);
				convexRadiusNormal.setMul4(convexRadius, planes[3]);
				planePoint.setAdd4(convexRadiusNormal, p1);
				planes[3](3) = -planes[3].dot3(planePoint);
				planes[4].setCross(normal, edge02);
				convexRadiusNormal.setMul4(convexRadius, planes[4]);
				planePoint.setAdd4(convexRadiusNormal, p2);
				planes[4](3) = -planes[4].dot3(planePoint);
				planes[5].setAdd4(planes[2], planes[3]); planes[5].normalize3();
				convexRadiusNormal.setMul4(convexRadius, planes[5]);
				planePoint.setAdd4(convexRadiusNormal, p1);
				planes[5](3) = -planes[5].dot3(planePoint);
				planes[6].setAdd4(planes[3], planes[4]); planes[6].normalize3();
				convexRadiusNormal.setMul4(convexRadius, planes[6]);
				planePoint.setAdd4(convexRadiusNormal, p2);
				planes[6](3) = -planes[6].dot3(planePoint);
				planes[7].setAdd4(planes[4], planes[2]); planes[7].normalize3();
				convexRadiusNormal.setMul4(convexRadius, planes[7]);
				planePoint.setAdd4(convexRadiusNormal, p0);
				planes[7](3) = -planes[7].dot3(planePoint);
				hkDisplayConvex* displayGeom = _createConvexDisplayFromPlanes( planes, transform );
				if (displayGeom)
				{
					displayGeometries.pushBack(displayGeom);
				}
				else
				{
				}
			}
			break;
		}
		case HK_SHAPE_CONVEX_VERTICES:
		{
			const hkpConvexVerticesShape* convexVerticesShape = static_cast<const hkpConvexVerticesShape*>(shape);
			float convexRadius = convexVerticesShape->getRadius();
			if (convexRadius > m_environment.m_minVisibleRadius)
			{
				const hkArray<hkVector4>& planeEqs = convexVerticesShape->getPlaneEquations();
				float currentDist = _getPlaneToSurfaceDistance(convexVerticesShape);
				hkDisplayConvex* displayGeom = 0;
				const float RADIUS_EPSILON = 0.005f;
				hkArray<hkVector4> newPlanesEqs; newPlanesEqs = planeEqs;
				if ( currentDist > ( RADIUS_EPSILON - convexRadius ) )
				{
					int numPlanes = planeEqs.getSize();
					for (int i = 0; i < numPlanes; i++)
					{
						newPlanesEqs[i](3) -= convexRadius;
					}
				}
				_addBoundingPlanes(convexVerticesShape, convexRadius, newPlanesEqs);
				displayGeom = _createConvexDisplayFromPlanes( newPlanesEqs, transform );
				if (displayGeom)
				{
					displayGeometries.pushBack(displayGeom);
				}
				else
				{
				}
			}
			break;
		}
		default:
			for (int i = 0; i < hkpUserConvexRadiusBuilder::getInstance().m_userConvexRadiusBuilders.getSize(); ++i )
			{
				if ( hkpUserConvexRadiusBuilder::getInstance().m_userConvexRadiusBuilders[i].type == shape->getType() )
				{
					hkpUserConvexRadiusBuilder::getInstance().m_userConvexRadiusBuilders[i].f( shape, transform, displayGeometries, this );
					continue;
				}
			}
	}
}

// @f3 0x00a7ce70 (community match, verified in this file)
namespace f3m_00a7ce70 {
// 0x00a7ce70: hkSimpleConstraintUtil_InitInfo(const hkpSimpleConstraintInfoInitInput& bodyA,
// const hkpSimpleConstraintInfoInitInput& bodyB, const hkMatrix3& directions, hkpSimpleConstraintInfo& out)
// of Havok 5.5.0 (hkpConstraintSolver, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets up the simple constraint solver's info for two bodies and three directions: per body the transposed
// jacobians (relPos x direction), the inverse inertia times them, the body's mass; the summed inverse mass matrix,
// its symmetric inverse (with epsilon cubed added to the determinant), the reciprocal of its first element and of
// the determinant of its lower 2x2 block.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py); the declarations are therefore the SDK's text with its names.
// The function body follows the SDK's unoptimized (hybrid) library object of this function statement by
// statement, and built with the SDK's headers it reproduces both that object and the release object. The symmetric
// inverse at the end is a force-inline helper of the library's own source file, which the SDK does not ship; the
// helper here (its name is ours) was written from the hybrid object's code for that line.
namespace f3m_00a7ce70 {

typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
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
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
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
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkMatrix3::hkMatrix3( const hkMatrix3& other )
{
	m_col0 = other.m_col0;
	m_col1 = other.m_col1;
	m_col2 = other.m_col2;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
inline void hkMatrix3::setCols( const hkVector4& r0,
								const hkVector4& r1,
								const hkVector4& r2)
{
	m_col0 = r0;
	m_col1 = r1;
	m_col2 = r2;
}
inline void hkMatrix3::_add( const hkMatrix3& a )
{
	getColumn(0).add4( a.getColumn(0) );
	getColumn(1).add4( a.getColumn(1) );
	getColumn(2).add4( a.getColumn(2) );
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setDiagonal( hkReal m00, hkReal m11, hkReal m22 )
{
	setZero();
	(*this)(0,0) = m00;
	(*this)(1,1) = m11;
	(*this)(2,2) = m22;
}
struct hkpSimpleConstraintInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSimpleConstraintInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	struct BodyInfo
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSimpleConstraintInfo::BodyInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkRotation m_jacT;
		hkMatrix3 m_invIjac;
		hkReal m_invMass;
		hkReal m_mass;
		hkReal getMass() const { return m_mass; }
	};
	BodyInfo m_bodyInfo[2];
	hkRotation m_base;
	hkMatrix3 m_invMassMatrix;
	hkMatrix3 m_massMatrix;
	hkReal& getMass00(){ return 	m_invMassMatrix.getColumn(0)(3); }
	hkReal getMass00() const{ return 	m_invMassMatrix.getColumn(0)(3); }
	hkReal& getInvDetM12(){ return 	m_invMassMatrix.getColumn(1)(3); }
	hkReal getInvDetM12() const { return 	m_invMassMatrix.getColumn(1)(3); }
};
struct hkpSimpleConstraintInfoInitInput
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSimpleConstraintInfoInitInput), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkVector4 m_massRelPos;
	hkMatrix3 m_invInertia;
	hkReal m_invMass;
};

void __cdecl FUN_00a7ce70(	const hkpSimpleConstraintInfoInitInput& bodyA, const hkpSimpleConstraintInfoInitInput& bodyB,
													const hkMatrix3& directions, hkpSimpleConstraintInfo& infoOut);
namespace hkVector4Util
{
__forceinline void __cdecl rotatePoints( const hkMatrix3& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
__forceinline void __cdecl setMul( const hkMatrix3& aTb, const hkMatrix3& bTc, hkMatrix3& aTcOut );
__forceinline void __cdecl transpose( hkMatrix3& m );
__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::rotatePoints( const hkMatrix3& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	;
	checkRegisters( 0x70000000 );
	hkMatrix3 unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setMul3( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
inline void __cdecl hkVector4Util::setMul( const hkMatrix3& aTb, const hkMatrix3& bTc, hkMatrix3& aTcOut )
{
	;
	;
	hkVector4Util::rotatePoints( aTb, &bTc.getColumn(0), 3, &aTcOut.getColumn(0) );
}
inline void __cdecl hkVector4Util::transpose( hkMatrix3& m )
{
	hkReal h1 = m(0,1); m(0,1) = m(1,0), m(1,0) = h1;
	hkReal h2 = m(0,2); m(0,2) = m(2,0), m(2,0) = h2;
	hkReal h3 = m(1,2); m(1,2) = m(2,1), m(2,1) = h3;
}
static __forceinline void invertSymmetricWithEps( const hkMatrix3& m, hkMatrix3& out, hkReal eps )
{
	hkVector4 r0; r0.setCross( m.getColumn(1), m.getColumn(2) );
	hkVector4 r1; r1.setCross( m.getColumn(2), m.getColumn(0) );
	hkVector4 r2; r2.setCross( m.getColumn(0), m.getColumn(1) );
	hkSimdReal det = hkSimdReal( eps * eps * eps ) + m.getColumn(0).dot3( r0 );
	hkSimdReal dinv = hkSimdReal(1.0f) / det;
	out.getColumn(0).setMul4( dinv, r0 );
	out.getColumn(1).setMul4( dinv, r1 );
	out.getColumn(2).setMul4( dinv, r2 );
}
void __cdecl FUN_00a7ce70( const hkpSimpleConstraintInfoInitInput& bodyA, const hkpSimpleConstraintInfoInitInput& bodyB, const hkMatrix3& directions, hkpSimpleConstraintInfo& out )
{
	const hkpSimpleConstraintInfoInitInput* in = &bodyA;
	hkReal d = bodyA.m_invMass + bodyB.m_invMass;
	out.m_invMassMatrix.setDiagonal( d, d, d );
	const hkVector4& d0 = directions.getColumn(0);
	const hkVector4& d1 = directions.getColumn(1);
	const hkVector4& d2 = directions.getColumn(2);
	out.m_base.setCols( d0, d1, d2 );
	for (int i = 0; i < 2; i++)
	{
		hkpSimpleConstraintInfo::BodyInfo& s = out.m_bodyInfo[i];
		const hkVector4& relPos = in->m_massRelPos;
		s.m_jacT.getColumn(0).setCross( relPos, d0 );
		s.m_jacT.getColumn(1).setCross( relPos, d1 );
		s.m_jacT.getColumn(2).setCross( relPos, d2 );
		hkVector4Util::setMul( in->m_invInertia, s.m_jacT, s.m_invIjac );
		hkVector4Util::transpose( s.m_jacT );
		hkMatrix3 invM;
		hkVector4Util::setMul( s.m_jacT, s.m_invIjac, invM );
		out.m_invMassMatrix._add( invM );
		s.m_invMass = in->m_invMass;
		s.m_mass = 1.0f / ( s.m_invMass + 1.192092896e-07F );
		in = &bodyB;
	}
	invertSymmetricWithEps( out.m_invMassMatrix, out.m_massMatrix, 1.192092896e-07F );
	out.getMass00() = 1.0f / ( out.m_invMassMatrix(0,0) + 1.192092896e-07F );
	const hkReal det12 = out.m_invMassMatrix(1,1) * out.m_invMassMatrix(2,2) - out.m_invMassMatrix(1,2) * out.m_invMassMatrix(2,1);
	out.getInvDetM12() = 1.0f / ( det12 + 1.192092896e-07F );
}

}  // namespace f3m_00a7ce70
}   // namespace f3m_00a7ce70

// @f3 0x00a7b270 (community match, verified in this file)
namespace f3m_00a7b270 {
// 0x00a7b270: hkPoweredChain_ScanAndEnableMotors(const hkpChainSolverInfo& info, int& modifiedConstraintIndex,
// int& modifiedCoordinateIndex, hkReal& impulse, hkp3dAngularMotorSolverInfo* motorsState) of Havok 5.5.0
// (hkpConstraintSolver, hkpPoweredChainSolverUtil.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Scans the powered chain's broken angular motors from the last constraint to the first: rebuilds each
// constraint's resulting velocity from the chain's LU matrices and the impulse buffer, compares it with the motor's
// target velocity and re-enables (marks not broken) the motor with the largest breach.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The library's own types that no SDK header ships
// (hkpChainSolverInfo, hkpConstraintChainMatrix6Triple, hkp2AngJacobian, hkpVelocityAccumulatorOffset) are declared
// from the hkpConstraintSolver library's debug records (members, types, order, method signatures); the bodies of
// hkp2AngJacobian::getAngularRhs and the accumulator lookup, and the target-velocity helper (whose signature is in
// the records), follow the SDK's unoptimized (hybrid) library object. The function body follows that object
// statement by statement and reproduces the release object. Only the function carries the packet's name.
namespace f3m_00a7b270 {

typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
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
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
extern "C" {
double  __cdecl fabs(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
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
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}
struct hkpSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo::DeactivationInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
struct hkp1dMotorSolverInfo
{
    __forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1dMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkp3dAngularMotorSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp3dAngularMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	typedef hkUint8 Status;
	enum Mask
	{
		ANGULAR_1ST = 0x03,
		ANGULAR_2ND = 0x0c,
		ANGULAR_3RD = 0x30,
	};
	enum MotorState
	{
		MOTOR_NOT_BROKEN          = 0x00,
		MOTOR_BROKEN_MAX_BREACHED = 0x01,
		MOTOR_BROKEN_MIN_BREACHED = 0x03,
		MOTOR_DISABLED = 0x02
	};
	Status m_broken;
	inline int getState(int idx) const
	{
		;
		return (m_broken >> (2 * idx)) & ANGULAR_1ST;
	}
	inline void setState(int idx, int value)
	{
		;
		const int shiftedValue  = (value & ANGULAR_1ST) << (2 * idx);
		const int shiftedMask   = ANGULAR_1ST << (2 * idx);
		m_broken &= hkUint8(~shiftedMask);
		m_broken |= hkUint8(shiftedValue);
	}
	hkp1dMotorSolverInfo m_motorInfos[3];
};
class hkMatrix6;
class hkVector8
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector8), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_lin;
		hkVector4 m_ang;
	public:
		__forceinline void setAll(hkReal x) { m_lin.setAll(x); m_ang.setAll(x);; }
		__forceinline void setAll6(hkReal x) { m_lin.setAll3(x); m_ang.setAll3(x);; }
		__forceinline void setZero8() { m_lin.setZero4(); m_ang.setZero4();; }
		__forceinline void add8(const hkVector8& a)
		{
			m_lin.add4( a.m_lin );
			m_ang.add4( a.m_ang );
		}
		__forceinline void add6clobberW(const hkVector8& a)
		{
			m_lin.add3clobberW( a.m_lin );
			m_ang.add3clobberW( a.m_ang );
		}
		__forceinline void setSub8(const hkVector8& a, const hkVector8& b)
		{
			m_lin.setSub4( a.m_lin, b.m_lin );
			m_ang.setSub4( a.m_ang, b.m_ang );
		}
		__forceinline void mul8(hkSimdRealParameter a) { m_lin.mul4(a); m_ang.mul4(a);; }
		__forceinline void setNeg8() { m_lin.setNeg4(m_lin); m_ang.setNeg4(m_ang); }
		__forceinline void addMul8(hkSimdRealParameter r, const hkVector8& a)
		{
			m_lin.addMul4( r, a.m_lin );
			m_ang.addMul4( r, a.m_ang );
		}
		__forceinline void _setMul6(const hkMatrix6& a, const hkVector8& b );
};
class hkMatrix6
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix6), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix6() { }
		__forceinline void operator= ( const hkMatrix6& a )
		{
			m_m[0][0] = a.m_m[0][0];
			m_m[0][1] = a.m_m[0][1];
			m_m[1][0] = a.m_m[1][0];
			m_m[1][1] = a.m_m[1][1];
		}
		__forceinline void setZero()
		{
			m_m[0][0].setZero();
			m_m[0][1].setZero();
			m_m[1][0].setZero();
			m_m[1][1].setZero();
		}
		__forceinline void setIdentity()
		{
			m_m[0][0].setIdentity();
			m_m[0][1].setZero();
			m_m[1][0].setZero();
			m_m[1][1].setIdentity();
		}
		__forceinline void setTranspose( const hkMatrix6& s )
		{
			m_m[0][0].setTranspose( s.m_m[0][0] );
			m_m[0][1].setTranspose( s.m_m[1][0] );
			m_m[1][0].setTranspose( s.m_m[0][1] );
			m_m[1][1].setTranspose( s.m_m[1][1] );
		}
		__forceinline void setMul( const hkMatrix6& a, const hkMatrix6& b )
		{
			hkMatrix3 tmp;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					tmp      ._setMul( a.m_m[i][0], b.m_m[0][j] );
					m_m[i][j]._setMul( a.m_m[i][1], b.m_m[1][j] );
					m_m[i][j]._add( tmp );
				}
			}
		}
		__forceinline void add( const hkMatrix6& a )
		{
			m_m[0][0]._add( a.m_m[0][0] );
			m_m[0][1]._add( a.m_m[0][1] );
			m_m[1][0]._add( a.m_m[1][0] );
			m_m[1][1]._add( a.m_m[1][1] );
		}
		__forceinline void sub( const hkMatrix6& a )
		{
			m_m[0][0]._sub( a.m_m[0][0] );
			m_m[0][1]._sub( a.m_m[0][1] );
			m_m[1][0]._sub( a.m_m[1][0] );
			m_m[1][1]._sub( a.m_m[1][1] );
		}
		__forceinline void mul( const hkMatrix6& a)
		{
			hkMatrix6 temp;
			temp.setMul( *this, a );
			*this = temp;
		}
		__forceinline void mul( hkSimdRealParameter scale )
		{
			m_m[0][0]._setMul(scale, m_m[0][0]);
			m_m[0][1]._setMul(scale, m_m[0][1]);
			m_m[1][0]._setMul(scale, m_m[1][0]);
			m_m[1][1]._setMul(scale, m_m[1][1]);
		}
		void setInvert( const hkMatrix6& in );
	public:
		__declspec(align(16)) hkMatrix3 m_m[2][2];
};
extern "C"
{
void __cdecl hkMatrix6SetMulV(hkVector8& out, const hkMatrix6&a, const hkVector8& b);
void __cdecl hkMatrix6SetTranspose(hkMatrix6& out, const hkMatrix6&in );
}
class hkpVelocityAccumulator
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulator), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return reinterpret_cast<hkRotation&>(m_scratch1); }
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return m_scratch1; }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return m_scratch1; }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkp1Lin2AngJacobian;
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		void setAngularRhs( hkReal v );
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		hkReal getAngularRhsSr() const;
		hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp2AngJacobian& jacB ) const;
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulatorOffset), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpVelocityAccumulatorOffset( const hkpVelocityAccumulator* base, const hkpVelocityAccumulator* accumulator );
		hkpVelocityAccumulatorOffset();
		inline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<const hkpVelocityAccumulator*>( reinterpret_cast<const char*>(base) + m_offset );
		}
		inline hkpVelocityAccumulator& getAccumulator( hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<hkpVelocityAccumulator*>( reinterpret_cast<char*>(base) + m_offset );
		}
		unsigned m_offset;
};
struct hkpConstraintChainMatrix6Triple
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintChainMatrix6Triple), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkMatrix6 m_lower;
	hkMatrix6 m_diagonalInv;
	hkMatrix6 m_upper;
	hkMatrix6 m_mtxDiag;
	hkMatrix6 m_mtxNextOffdiag;
};
struct hkpChainSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpChainSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpChainSolverInfo( const hkpSolverInfo& solverInfo );
	const hkpSolverInfo& m_solverInfo;
	hkPadSpu<int> m_numConstraints;
	hkPadSpu<hkReal> m_schemaTau;
	hkPadSpu<hkReal> m_schemaDamping;
	hkPadSpu<hkp1Lin2AngJacobian*> m_j;
	hkPadSpu<hkp2AngJacobian*> m_jAng;
	hkPadSpu<hkpVelocityAccumulatorOffset*> m_va;
	hkPadSpu<hkpVelocityAccumulator*> m_accumsBase;
	hkPadSpu<hkpConstraintChainMatrix6Triple*> m_triples;
	hkPadSpu<hkp3dAngularMotorSolverInfo*> m_motorsState;
	hkPadSpu<hkVector8*> m_gTempBuffer;
	hkPadSpu<hkVector8*> m_velocitiesBuffer;
};
static __forceinline hkReal calcTargetVelocityImpl( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& solverInfo, hkReal tau, hkReal damping )
{
	const hkReal rhs = jac.getAngularRhs();
	hkVector4 relVelA; relVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
	hkVector4 relVelB; relVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
	hkVector4 projA; projA.setMul4( relVelA, jac.m_angular[0] );
	hkVector4 projB; projB.setMul4( relVelB, jac.m_angular[1] );
	hkVector4 relVel; relVel.setAdd4( projA, projB );
	hkVector4 sumVelA = mA.getSumAngularVel();
	hkVector4 sumVelB = mB.getSumAngularVel();
	hkVector4 sumA; sumA.setMul4( sumVelA, jac.m_angular[0] );
	hkVector4 sumB; sumB.setMul4( sumVelB, jac.m_angular[1] );
	hkVector4 sumVel; sumVel.setAdd4( sumA, sumB );
	sumVel.mul4( solverInfo.m_invIntegrateVelocityFactor(0) * tau );
	relVel.mul4( damping );
	hkVector4 vel; vel.setAdd4( sumVel, relVel );
	const hkReal v = vel.horizontalAdd3();
	hkReal result = rhs * tau - v;
	return result;
}
static __forceinline hkReal calcTargetVelocity( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& solverInfo, hkReal tau, hkReal damping )
{
	return calcTargetVelocityImpl( jac, mA, mB, solverInfo, tau, damping );
}
// pdb: hkPoweredChain_ScanAndEnableMotors | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: info, modifiedConstraintIndex, modifiedCoordinateIndex, impulse, motorsState
void __cdecl FUN_00a7b270( const hkpChainSolverInfo& info, int& modifiedConstraintIndex, int& modifiedCoordinateIndex, hkReal& impulse, hkp3dAngularMotorSolverInfo* motorsState )
{
	const hkVector8* g = info.m_gTempBuffer + 1;
	hkReal maxBreaching = 0.0f;
	int constraintIndex = -1;
	int coordinate = -1;
	hkVector8 impRight; impRight.setZero8();
	hkVector8 impCenter; impCenter.setZero8();
	hkVector8 impLeft; impLeft.setZero8();
	{
		hkVector8 tmp; hkMatrix6SetMulV( tmp, info.m_triples[info.m_numConstraints - 1].m_upper, impLeft );
		impLeft.setSub8( g[info.m_numConstraints - 1], tmp );
	}
	for (int i = info.m_numConstraints - 1; i >= 0; i--)
	{
		int tIdx = i - 1;
		impRight = impCenter;
		impCenter = impLeft;
		const hkpConstraintChainMatrix6Triple* baseTriple = &info.m_triples[hkInt16(tIdx)];
		if (tIdx >= 0)
		{
			hkVector8 tmp; hkMatrix6SetMulV( tmp, baseTriple->m_upper, impLeft );
			impLeft.setSub8( g[tIdx], tmp );
		}
		else
		{
			impLeft.setZero8();
		}
		{
			hkMatrix6 offDiagTransp;
			if (tIdx >= 0)
			{
				hkMatrix6SetTranspose( offDiagTransp, baseTriple->m_mtxNextOffdiag );
			}
			else
			{
				offDiagTransp.setIdentity();
			}
			hkVector8 resultVelocityVec; hkMatrix6SetMulV( resultVelocityVec, offDiagTransp, impLeft );
			hkVector8 tmp; hkMatrix6SetMulV( tmp, baseTriple[1].m_mtxDiag, impCenter );
			resultVelocityVec.add8( tmp );
			hkMatrix6SetMulV( tmp, baseTriple[1].m_mtxNextOffdiag, impRight );
			resultVelocityVec.add8( tmp );
			for (int c = 0; c < 3; c++)
			{
				int state = info.m_motorsState[i].getState(c);
				if (state == hkp3dAngularMotorSolverInfo::MOTOR_BROKEN_MIN_BREACHED || state == hkp3dAngularMotorSolverInfo::MOTOR_BROKEN_MAX_BREACHED)
				{
					int gi = i;
					hkpVelocityAccumulator* __restrict mA = &info.m_va[gi].getAccumulator( info.m_accumsBase );
					hkpVelocityAccumulator* __restrict mB = &info.m_va[gi + 1].getAccumulator( info.m_accumsBase );
					const hkp3dAngularMotorSolverInfo& ami = info.m_motorsState[gi];
					hkReal targetVelocity = calcTargetVelocity( info.m_jAng[gi * 3 + c], *mA, *mB, info.m_solverInfo, ami.m_motorInfos[c].m_tau, ami.m_motorInfos[c].m_damping );
					hkReal resultVelocity = resultVelocityVec.m_ang(c);
					if ( (state == hkp3dAngularMotorSolverInfo::MOTOR_BROKEN_MIN_BREACHED && resultVelocity <= targetVelocity) || (state == hkp3dAngularMotorSolverInfo::MOTOR_BROKEN_MAX_BREACHED && resultVelocity >= targetVelocity) )
					{
						hkReal velocityBreach = hkMath::fabs( resultVelocity - targetVelocity );
						if (velocityBreach > maxBreaching)
						{
							maxBreaching = velocityBreach;
							constraintIndex = gi;
							coordinate = c;
						}
					}
				}
			}
		}
	}
	if (constraintIndex >= 0)
	{
		info.m_motorsState[constraintIndex].setState( coordinate, hkp3dAngularMotorSolverInfo::MOTOR_NOT_BROKEN );
		modifiedConstraintIndex = constraintIndex;
		modifiedCoordinateIndex = coordinate;
	}
}

}  // namespace f3m_00a7b270
}   // namespace f3m_00a7b270

// @f3 0x00a7a4c0 (community match, verified in this file)
namespace f3m_00a7a4c0 {
// 0x00a7a4c0: hkPoweredChain_CalculateVelocities(const hkpChainSolverInfo& info, hkVector8* velocities) of Havok 5.5.0
// (hkpConstraintSolver, hkpPoweredChainSolverUtil.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Fills the powered chain's velocity vector: for each constraint the three linear and three angular target
// velocities from its jacobians, the solver's tau and damping (the motors' own for the angular part) and the two
// bodies' velocity accumulators; the w components are zeroed.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The library's own types that no SDK header ships
// (hkpChainSolverInfo, hkp1Lin2AngJacobian, hkp2AngJacobian, hkpVelocityAccumulatorOffset) are declared
// from the hkpConstraintSolver library's debug records (members, types, order, method signatures); the bodies of
// the jacobians' rhs getters and the accumulator lookup, and the two target-velocity helpers (whose signatures
// are in the records), follow the SDK's unoptimized (hybrid) library object. The function body follows that object
// statement by statement and reproduces the release object. Only the function carries the packet's name.
namespace f3m_00a7a4c0 {

typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
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
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
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
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
struct hkpSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo::DeactivationInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
struct hkp1dMotorSolverInfo
{
    __forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1dMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkp3dAngularMotorSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp3dAngularMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	typedef hkUint8 Status;
	enum Mask
	{
		ANGULAR_1ST = 0x03,
		ANGULAR_2ND = 0x0c,
		ANGULAR_3RD = 0x30,
	};
	enum MotorState
	{
		MOTOR_NOT_BROKEN          = 0x00,
		MOTOR_BROKEN_MAX_BREACHED = 0x01,
		MOTOR_BROKEN_MIN_BREACHED = 0x03,
		MOTOR_DISABLED = 0x02
	};
	Status m_broken;
	inline int getState(int idx) const
	{
		;
		return (m_broken >> (2 * idx)) & ANGULAR_1ST;
	}
	inline void setState(int idx, int value)
	{
		;
		const int shiftedValue  = (value & ANGULAR_1ST) << (2 * idx);
		const int shiftedMask   = ANGULAR_1ST << (2 * idx);
		m_broken &= hkUint8(~shiftedMask);
		m_broken |= hkUint8(shiftedValue);
	}
	hkp1dMotorSolverInfo m_motorInfos[3];
};
class hkMatrix6;
class hkVector8
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector8), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_lin;
		hkVector4 m_ang;
	public:
		__forceinline void setAll(hkReal x) { m_lin.setAll(x); m_ang.setAll(x);; }
		__forceinline void setAll6(hkReal x) { m_lin.setAll3(x); m_ang.setAll3(x);; }
		__forceinline void setZero8() { m_lin.setZero4(); m_ang.setZero4();; }
		__forceinline void add8(const hkVector8& a)
		{
			m_lin.add4( a.m_lin );
			m_ang.add4( a.m_ang );
		}
		__forceinline void add6clobberW(const hkVector8& a)
		{
			m_lin.add3clobberW( a.m_lin );
			m_ang.add3clobberW( a.m_ang );
		}
		__forceinline void setSub8(const hkVector8& a, const hkVector8& b)
		{
			m_lin.setSub4( a.m_lin, b.m_lin );
			m_ang.setSub4( a.m_ang, b.m_ang );
		}
		__forceinline void mul8(hkSimdRealParameter a) { m_lin.mul4(a); m_ang.mul4(a);; }
		__forceinline void setNeg8() { m_lin.setNeg4(m_lin); m_ang.setNeg4(m_ang); }
		__forceinline void addMul8(hkSimdRealParameter r, const hkVector8& a)
		{
			m_lin.addMul4( r, a.m_lin );
			m_ang.addMul4( r, a.m_ang );
		}
		__forceinline void _setMul6(const hkMatrix6& a, const hkVector8& b );
};
class hkpVelocityAccumulator
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulator), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return reinterpret_cast<hkRotation&>(m_scratch1); }
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return m_scratch1; }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return m_scratch1; }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		void setAngularRhs( hkReal v );
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		hkReal getAngularRhsSr() const;
		hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp2AngJacobian& jacB ) const;
};
class hkp1Lin2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1Lin2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		hkp2AngJacobian& as2AngJacobian_internal();
		void setRHS( hkReal v );
		inline const hkReal& getRHS() const { return m_linear0(3); }
		hkReal& getRHS();
		const hkSimdReal getRhsSr() const;
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		hkReal getUserValue() const;
		hkReal getUserValueSr() const;
		void setUserValue( hkReal v );
		hkReal getDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulatorOffset), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpVelocityAccumulatorOffset( const hkpVelocityAccumulator* base, const hkpVelocityAccumulator* accumulator );
		hkpVelocityAccumulatorOffset();
		inline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<const hkpVelocityAccumulator*>( reinterpret_cast<const char*>(base) + m_offset );
		}
		inline hkpVelocityAccumulator& getAccumulator( hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<hkpVelocityAccumulator*>( reinterpret_cast<char*>(base) + m_offset );
		}
		unsigned m_offset;
};
struct hkpConstraintChainMatrix6Triple;
struct hkpChainSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpChainSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpChainSolverInfo( const hkpSolverInfo& solverInfo );
	const hkpSolverInfo& m_solverInfo;
	hkPadSpu<int> m_numConstraints;
	hkPadSpu<hkReal> m_schemaTau;
	hkPadSpu<hkReal> m_schemaDamping;
	hkPadSpu<hkp1Lin2AngJacobian*> m_j;
	hkPadSpu<hkp2AngJacobian*> m_jAng;
	hkPadSpu<hkpVelocityAccumulatorOffset*> m_va;
	hkPadSpu<hkpVelocityAccumulator*> m_accumsBase;
	hkPadSpu<hkpConstraintChainMatrix6Triple*> m_triples;
	hkPadSpu<hkp3dAngularMotorSolverInfo*> m_motorsState;
	hkPadSpu<hkVector8*> m_gTempBuffer;
	hkPadSpu<hkVector8*> m_velocitiesBuffer;
};
static __forceinline hkReal calcTargetVelocityImpl( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& solverInfo, hkReal tau, hkReal damping )
{
	const hkReal rhs = jac.getRHS();
	hkVector4 relLinVelA; relLinVelA.setSub4( mA.m_linearVel, mA.getSumLinearVel() );
	hkVector4 relAngVelA; relAngVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
	hkVector4 relLinVelB; relLinVelB.setSub4( mB.m_linearVel, mB.getSumLinearVel() );
	hkVector4 relAngVelB; relAngVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
	hkVector4 relLin; relLin.setSub4( relLinVelA, relLinVelB );
	hkVector4 relAngA; relAngA.setMul4( relAngVelA, jac.m_angular[0] );
	hkVector4 relAngB; relAngB.setMul4( relAngVelB, jac.m_angular[1] );
	relLin.mul4( jac.m_linear0 );
	relAngA.add4( relAngB );
	hkVector4 relVel; relVel.setAdd4( relAngA, relLin );
	hkVector4 sumLinVelA = mA.getSumLinearVel();
	hkVector4 sumAngVelA = mA.getSumAngularVel();
	hkVector4 sumLinVelB = mB.getSumLinearVel();
	hkVector4 sumAngVelB = mB.getSumAngularVel();
	hkVector4 sumLin; sumLin.setSub4( sumLinVelA, sumLinVelB );
	hkVector4 sumAngA; sumAngA.setMul4( sumAngVelA, jac.m_angular[0] );
	hkVector4 sumAngB; sumAngB.setMul4( sumAngVelB, jac.m_angular[1] );
	sumLin.mul4( jac.m_linear0 );
	sumAngA.add4( sumAngB );
	hkVector4 sumVel; sumVel.setAdd4( sumAngA, sumLin );
	sumVel.mul4( solverInfo.m_invIntegrateVelocityFactor(0) * tau );
	relVel.mul4( damping );
	hkVector4 vel; vel.setAdd4( sumVel, relVel );
	const hkReal v = vel.horizontalAdd3();
	hkReal result = rhs * tau - v;
	return result;
}
static __forceinline hkReal calcTargetVelocityImpl( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& solverInfo, hkReal tau, hkReal damping )
{
	const hkReal rhs = jac.getAngularRhs();
	hkVector4 relVelA; relVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
	hkVector4 relVelB; relVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
	hkVector4 projA; projA.setMul4( relVelA, jac.m_angular[0] );
	hkVector4 projB; projB.setMul4( relVelB, jac.m_angular[1] );
	hkVector4 relVel; relVel.setAdd4( projA, projB );
	hkVector4 sumVelA = mA.getSumAngularVel();
	hkVector4 sumVelB = mB.getSumAngularVel();
	hkVector4 sumA; sumA.setMul4( sumVelA, jac.m_angular[0] );
	hkVector4 sumB; sumB.setMul4( sumVelB, jac.m_angular[1] );
	hkVector4 sumVel; sumVel.setAdd4( sumA, sumB );
	sumVel.mul4( solverInfo.m_invIntegrateVelocityFactor(0) * tau );
	relVel.mul4( damping );
	hkVector4 vel; vel.setAdd4( sumVel, relVel );
	const hkReal v = vel.horizontalAdd3();
	hkReal result = rhs * tau - v;
	return result;
}
static __forceinline hkReal calcTargetVelocity( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& solverInfo, hkReal tau, hkReal damping )
{
	return calcTargetVelocityImpl( jac, mA, mB, solverInfo, tau, damping );
}
static __forceinline hkReal calcTargetVelocity( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& solverInfo, hkReal tau, hkReal damping )
{
	return calcTargetVelocityImpl( jac, mA, mB, solverInfo, tau, damping );
}
// pdb: hkPoweredChain_CalculateVelocities | hkpPoweredChainSolverUtil.obj | tesv_win, objrun, medium
void __cdecl FUN_00a7a4c0( const hkpChainSolverInfo& info, hkVector8* velocities )
{
	hkp1Lin2AngJacobian* j = info.m_j;
	hkp2AngJacobian* jAng = info.m_jAng;
	for (int gi = 0; gi < info.m_numConstraints; j += 3, jAng += 3, gi++)
	{
		hkVector8& dv = velocities[gi];
		hkpVelocityAccumulator* __restrict mA = &info.m_va[gi].getAccumulator( info.m_accumsBase );
		hkpVelocityAccumulator* __restrict mB = &info.m_va[gi + 1].getAccumulator( info.m_accumsBase );
		const hkp3dAngularMotorSolverInfo& ami = info.m_motorsState[gi];
		for (int i = 0; i < 3; i++)
		{
			dv.m_lin(i) = calcTargetVelocity( j[i], *mA, *mB, info.m_solverInfo, info.m_schemaTau, info.m_schemaDamping );
			dv.m_ang(i) = calcTargetVelocity( jAng[i], *mA, *mB, info.m_solverInfo, ami.m_motorInfos[i].m_tau, ami.m_motorInfos[i].m_damping );
		}
		dv.m_lin(3) = 0.0f;
		dv.m_ang(3) = 0.0f;
	}
}

}  // namespace f3m_00a7a4c0
}   // namespace f3m_00a7a4c0
