#include <math.h>
// src/f3staging/f3blk_00a80000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a9de50 (community match, verified in this file)
extern const NiPoint3 NiPoint3_ZERO;
extern const double DAT_01072f80;
extern int g_012030b0;
namespace f3m_00a9de50 {
namespace fnv_00c344c0 {
extern "C" double __cdecl sqrt(double);
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    inline float Dot(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    inline NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    inline float Length() const
    {
        return (float)sqrt(x * x + y * y + z * z);
    }
    inline NiPoint3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return NiPoint3(x * inv, y * inv, z * inv);
    }
    inline NiPoint3 CrossProduct(const NiPoint3& p) const
    {
        NiPoint3 cross(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
        float length = cross.Length();
        if (length > 1e-6)
            return cross / length;
        else
            return NiPoint3(0.0f, 0.0f, 0.0f);
    }
    inline NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
};
NiPoint3 __cdecl operator*(float, const NiPoint3&);
extern "C" double __cdecl fabs(double);
inline float fabs(float f)
{
    return (float)fabs((double)f);
}
struct ClipPlane
{
    NiPoint3 normal;
    float constant;
    ClipPlane(const NiPoint3&, const NiPoint3&, const NiPoint3&);
    inline float GetPlaneConstant() const
    {
        return constant;
    }
    inline float Distance(const NiPoint3& p) const
    {
        return normal.Dot(p) - constant;
    }
};
struct ClipMatrix
{
    float entries[3][3];
    inline NiPoint3 operator*(const NiPoint3& p)const{return NiPoint3(entries[0][0]*p.x+entries[0][1]*p.y+entries[0][2]*p.z,entries[1][0]*p.x+entries[1][1]*p.y+entries[1][2]*p.z,entries[2][0]*p.x+entries[2][1]*p.y+entries[2][2]*p.z);}
    inline void GetColumn(unsigned int col, NiPoint3& out) const
    {
        out.x = entries[col][0];
        out.y = entries[col][1];
        out.z = entries[col][2];
    }
};
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
struct SSNode
{
    virtual void v0();
    virtual void v1();
    virtual const void* GetType();
    int unk04;
    NiPoint3 center;
    float extentX, extentY;
    ClipMatrix orientation;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4;
    NiPoint3 cache[4];
    int unkd8, unkdc, unke0;
    bool dirty;
    void BSOcclusionPlane_GetVertices(NiPoint3* out);
    bool FUN_00c33cf0(void*, int, NiPoint3);
    bool FUN_00c344c0(void*, const NiPoint3&);
    inline bool IsExactType()
    {
        if (!this)
            return false;
        return GetType() == &g_012030b0;
    }
};

// pdb: BSOcclusionPlane::GetVertices | BSOcclusionPlane.obj | fnv360_0721_beta, call_seq + bridge(call_gap|caller), high
void SSNode::BSOcclusionPlane_GetVertices(NiPoint3* out)
    {
        if (!dirty)
            memmove(out, cache, 48);
        else
        {
            NiPoint3 a(extentX, 0.0f, 0.0f);
            NiPoint3 b(0.0f, 0.0f, extentY);
            a = orientation * a;
            b = orientation * b;
            out[3] = center - a + b;
            out[2] = center - a - b;
            out[1] = center + a - b;
            out[0] = center + a + b;
            memmove(cache, out, 48);
            dirty = false;
        }
    }
}
}   // namespace f3m_00a9de50

// @f3 0x00a8a830 (community match, verified in this file)
#include <math.h>
namespace f3m_00a8a830 {

typedef unsigned short hkUint16;

struct hkBool
{
    char m_bool;
    hkBool() {}
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
};

struct HullFace
{
    hkVector4 m_plane;
    hkUint16* m_a;
    hkUint16* m_b;
    hkUint16* m_c;
};

struct HullFaceArray
{
    HullFace* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const { return m_size; }
};

struct HullVertexArray
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const { return m_size; }
};

struct HullEdges
{
    int unk00;
    int unk04;
    int m_numEdges;
    int getNumEdges() const { return m_numEdges; }
};

hkBool FUN_00a8a620(const void* a, const HullVertexArray* verts, const void* c, float tolerance);
static __forceinline void MarkSharedEdge(hkBool& result, hkBool* seen)
{
    if (*seen)
        result = false;
    *seen = true;
}

__declspec(noinline) hkBool FUN_00a8a550(const HullFace* p, const HullFace* q, hkBool* f0, hkBool* f1, hkBool* f2)
{
    hkBool result = true;
    int pa = *p->m_a;
    int pb = *p->m_b;
    int pc = *p->m_c;
    int qa = *q->m_a;
    int qb = *q->m_b;
    int qc = *q->m_c;
    if (pa == qa)
    {
        if (pb == qb || pb == qc)
            MarkSharedEdge(result, f0);
        if (pc == qb || pc == qc)
            MarkSharedEdge(result, f1);
    }
    if (pa == qb)
    {
        if (pb == qc)
            MarkSharedEdge(result, f0);
        if (pc == qc)
            MarkSharedEdge(result, f1);
    }
    if ((pb == qa && (pc == qb || pc == qc)) || (pb == qb && pc == qc))
        MarkSharedEdge(result, f2);
    return result;
}

static __forceinline float AbsF(float r)
{
    return (float)fabs(r);
}

static __forceinline bool AllNear4(const hkVector4& a, const hkVector4& b, const hkVector4& eps)
{
    hkVector4 d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    d.x = AbsF(d.x);
    d.y = AbsF(d.y);
    d.z = AbsF(d.z);
    d.w = AbsF(d.w);
    int mask = ((d.x <= eps.x) ? 8 : 0) | ((d.y <= eps.y) ? 4 : 0) | ((d.z <= eps.z) ? 2 : 0) | ((d.w <= eps.w) ? 1 : 0);
    return (mask & 0xf) == 0xf;
}

// pdb: hkGeomConvexHullTester::isValidNonPlanarHull | hkGeomConvexHullTester.obj | tesv_win, call_gap, low
hkBool FUN_00a8a830(const void* a, const HullEdges* edges, const HullVertexArray* verts, const void* c,
                    const HullFaceArray* faces, float tolerance)
{
    hkBool result = true;
    result = result && FUN_00a8a620(a, verts, c, tolerance);
    for (int i = 0; i < faces->m_size; i++)
    {
        hkVector4 eps;
        eps.x = eps.y = eps.z = eps.w = 0.001f;
        result = result && *faces->m_data[i].m_a != *faces->m_data[i].m_b && *faces->m_data[i].m_b != *faces->m_data[i].m_c;
        hkBool f0 = false;
        hkBool f1 = false;
        hkBool f2 = false;
        for (int j = 0; j < faces->m_size; j++)
        {
            if (j == i)
                continue;
            result = result && (*faces->m_data[i].m_a != *faces->m_data[j].m_a || *faces->m_data[i].m_b != *faces->m_data[j].m_b ||
                                *faces->m_data[i].m_c != *faces->m_data[j].m_c ||
                                !AllNear4(faces->m_data[i].m_plane, faces->m_data[j].m_plane, eps));
            result = result && FUN_00a8a550(&faces->m_data[i], &faces->m_data[j], &f0, &f1, &f2);
        }
        result = result && f0 && f1 && f2;
    }
    int numVerts = verts->m_size;
    if (numVerts > 2)
    {
        result = result && faces->m_size - edges->m_numEdges / 2 + numVerts - 2 == 0;
    }
    return result;
}
}   // namespace f3m_00a8a830

// @f3 0x00a808b0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a808b0 {
namespace f3m_00a808b0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void* p, unsigned int bytes, int tag) throw(); };

struct Node { void* shape; };
struct Child { Node* node; int key; };
struct ChildArray {
    Child* data;
    int size;
    int capAndFlags;
    void init() { data = 0; size = 0; capAndFlags = 0x80000000; }
    void release() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Heap* h = (Heap*)DAT_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(data, cap * sizeof(Child), 0x17);
        }
    }
};
struct Visitor {
    virtual void v00();
    virtual int Visit(void* shape, int key, ChildArray* children);
};
int __cdecl FUN_00a808a0(void* shape, int key, ChildArray* children);
}

int __cdecl FUN_00a808b0(void* shape, int key, f3m_00a808b0::Visitor* visitor)
{
    using namespace f3m_00a808b0;
    ChildArray children;
    children.init();
    if (FUN_00a808a0(shape, key, &children) || visitor->Visit(shape, key, &children)) {
        children.release();
        return 1;
    }
    for (int i = 0; i < children.size; i++) {
        if (children.data[i].node->shape) {
            Child& c = children.data[i];
            if (FUN_00a808b0(c.node->shape, c.key, visitor) == 1) {
                children.release();
                return 1;
            }
        }
    }
    children.release();
    return 0;
}
}   // namespace f3m_00a808b0

// @f3 0x00a9fa20 (community match, verified in this file)
namespace f3m_00a9fa20 {
namespace BoxPlanes2246 {
struct Point {
    float x,y,z;
    float Dot(const Point& other) const {
        return y*other.y+x*other.x+z*other.z;
    }
};
extern const Point DAT_0108ec68;
struct Plane {
    Point normal;
    float distance;
    void Set(const Point& axis,const Point& center) {
        normal=axis;
        distance=center.Dot(axis);
    }
};
struct Box {
    unsigned unk00,unk04,unk08;
    Point center;
    float unk18,unk1C,unk20;
    float basis[3][3];
    void Axis(unsigned column,Point& axis) const {
        axis=DAT_0108ec68;
        axis.x=basis[0][column];
        axis.y=basis[1][column];
        axis.z=basis[2][column];

    }
    void FUN_00a9fa20(Plane*) const;
};
// pdb: BSMultiBoundOBB::GetPlanes | BSMultiBoundOBB.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPlanes
void Box::FUN_00a9fa20(Plane* planes) const {
    Point axis;
    Axis(0,axis);
    planes[0].Set(axis,center);
    Axis(1,axis);
    planes[1].Set(axis,center);
    Axis(2,axis);
    planes[2].normal=axis;
    double dot = static_cast<const volatile float&>(center.y) * axis.y;
    dot += static_cast<const volatile float&>(center.x) * axis.x;
    dot += static_cast<const volatile float&>(center.z) * axis.z;
    planes[2].distance = static_cast<float>(dot);
}
}


}   // namespace f3m_00a9fa20

// @f3 0x00a908d0 (community match, verified in this file)
namespace f3m_00a908d0 {
namespace wa908d0 {
struct hkError {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
extern hkError* DAT_010f3364;
struct hkOstream {
    int a, b, c;
    void FUN_00923070(char* buf, int size);
    void FUN_00943a60();
    hkOstream& FUN_00943710(const char* s) throw();
};
struct Vec4 { float x, y, z, w; };
struct ConstraintData {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual int getType() throw();
    int pad04[7];
    Vec4 m20;
    Vec4 m30;
    int pad40[4];
    Vec4 m50;
    int pad60[12];
    Vec4 m90;
};
struct ConstraintInstance {
    int pad00[3];
    ConstraintData* data;
};
__forceinline void Copy(Vec4* d, const Vec4& s) { d->x = s.x; d->y = s.y; d->z = s.z; d->w = s.w; }
}
// pdb: hkpConstraintUtils::getConstraintPivots | hkpConstraintUtils.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
int __cdecl hkpConstraintUtils_getConstraintPivots(wa908d0::ConstraintInstance* inst, wa908d0::Vec4* pivotA, wa908d0::Vec4* pivotB)
{
    wa908d0::ConstraintData* d = inst->data;
    switch (d->getType()) {
    case 0:
        wa908d0::Copy(pivotA, d->m20);
        wa908d0::Copy(pivotB, d->m30);
        return 0;
    case 1:
        wa908d0::Copy(pivotA, d->m50);
        wa908d0::Copy(pivotB, d->m90);
        return 0;
    case 2:
        wa908d0::Copy(pivotA, d->m50);
        wa908d0::Copy(pivotB, d->m90);
        return 0;
    case 7:
        wa908d0::Copy(pivotA, d->m50);
        wa908d0::Copy(pivotB, d->m90);
        return 0;
    }
    int buf[0x80];
    wa908d0::hkOstream os;
    os.FUN_00923070((char*)buf, 0x200);
    os.FUN_00943710("Unsupported type of constraint in prepareSystemForRagdoll()");
    wa908d0::DAT_010f3364->message(1, 0xabbabf3b, (char*)buf, ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 0xca);
    os.FUN_00943a60();
    return 1;
}
}   // namespace f3m_00a908d0

// @f3 0x00a82c50 (community match, verified in this file)
extern const unsigned char DAT_00e88470[128];
namespace f3m_00a82c50 {
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);

namespace w_a82c50 {

class hkBool {
public:
    hkBool() {}
    hkBool(const hkBool& o) : m_bool(o.m_bool) {}
    operator bool() const { return m_bool != 0; }
    char m_bool;
};

class hkStreamReader {
public:
    virtual ~hkStreamReader();
    virtual void v04();
    virtual void v08();
    virtual hkBool isOk() const;
    virtual int read(void* buf, int nbytes);
    virtual void v14();
    virtual void v18();
    virtual int setMark(int markLimit);
    virtual int rewindToMark();
};


int FUN_00a82c50(hkStreamReader* sr, unsigned char* out, int outLen)
{
    int extraChars[3] = { 0, 2, 3 };
    int tailBytes[4] = { 0, 0, 1, 2 };
    int n = 0;
    unsigned char* dst = out;
    int remaining = extraChars[outLen % 3] + (outLen / 3) * 4;
    unsigned char quad[4] = { 0 };
    {
    while (remaining > 0) {
        unsigned char c;
        if (sr->read(&c, 1) != 1)
            return 1;
        if (DAT_00e88470[c & 0x7f] != 0xff) {
            remaining--;
            quad[n] = DAT_00e88470[c];
            n++;
            if (n == 4) {
                dst[0] = (unsigned char)((quad[0] << 2) | (quad[1] >> 4));
                dst[1] = (unsigned char)((quad[1] << 4) | (quad[2] >> 2));
                dst[2] = (unsigned char)((quad[2] << 6) | quad[3]);
                n = 0;
                dst += 3;
                quad[0] = quad[1] = quad[2] = quad[3] = 0;
            }
        }
    }
    }
    while (sr->isOk()) {
        sr->setMark(1);
        unsigned char c = 0;
        sr->read(&c, 1);
        if (c != '=') {
            sr->rewindToMark();
            break;
        }
    }
    if (n) {
        unsigned char tail[3];
        tail[0] = (unsigned char)((quad[0] << 2) | (quad[1] >> 4));
        tail[1] = (unsigned char)((quad[1] << 4) | (quad[2] >> 2));
        tail[2] = (unsigned char)((quad[2] << 6) | quad[3]);
        int count = tailBytes[n];
        if (count > 0)
            memcpy(dst, tail, count);
    }
    return 0;
}

}
}   // namespace f3m_00a82c50

// @f3 0x00a92f00 (community match, verified in this file)
extern double DAT_00e80570;
namespace f3m_00a92f00 {

namespace f3m_00a92f00 {
struct __declspec(align(16)) V925 {
    float x, y, z, w;
    void setAll(float value) { x = value; y = value; z = value; w = value; }
};
struct Pair925 {
    V925 zero;
    V925 radius;
};
struct C925 {
    char pad00[0x10];
    V925 unk10;
    const unsigned char* unk20;
};
struct Out925 {};
namespace Query40 {
struct __declspec(align(16)) Point {
    float x, y, z;
};
struct Result {
    volatile int unk00, unk04, unk08, unk0c, unk10;
    int unk14;
    Result() { unk08=0;unk0c=0;unk10=0;unk00=0;unk04=0; }
};
struct __declspec(align(16)) State {
    void* output;
    int unk04, unk08, unk0c;
    float inverseScale;
    int unk14, unk18, unk1c;
    void* work;
    int unk24, unk28, unk2c;
    V925 sphere;
    void FUN_00a96780(Out925*, const unsigned char*, const Pair925*);
};
}

// pdb: hkMoppUsingFloatAabbVirtualMachine_querySphereOptimized | hkpMoppMachine.obj | tesv_win, objrun_open, low
void FUN_00a92f00(C925* context,
                 const V925* input, void* output, void* work) {
    Query40::State state;
    double inverseScale = 1.0 / context->unk10.w;
    state.output = output;
    Query40::Result result;
    const V925* sphere = *(const V925* const volatile*)&input;
    const unsigned char* program = *(const unsigned char* const volatile*)&context->unk20;
    result.unk14 = 16;
    state.inverseScale = inverseScale;
    Pair925 bounds;
    bounds.zero.x = bounds.zero.y = bounds.zero.z = bounds.zero.w = 0.0f;
    bounds.radius.setAll((float)(state.inverseScale * DAT_00e80570));
    Query40::Point point;
    point.x = sphere->x - context->unk10.x;
    point.y = sphere->y - context->unk10.y;
    point.z = sphere->z - context->unk10.z;
    point.x += point.x;
    point.y += point.y;
    point.z += point.z;
    state.sphere.x = point.x;
    state.sphere.y = point.y;
    state.sphere.z = point.z;
    state.sphere.w = sphere->w + sphere->w;
    state.work = work;
    state.FUN_00a96780((Out925*)&result, program, &bounds);
}
}
}   // namespace f3m_00a92f00

// @f3 0x00a8f6c0 (community match, verified in this file)
namespace f3m_00a8f6c0 {
namespace f3m_00a8f6c0 {

struct __declspec(align(16)) S00a8f6c0_Vector4
{
    float x, y, z, w;

    __forceinline S00a8f6c0_Vector4() {}
    __forceinline S00a8f6c0_Vector4(const S00a8f6c0_Vector4& v)
    {
        x = v.x; y = v.y; z = v.z; w = v.w;
    }

    __forceinline void setMul4(const float& r, const S00a8f6c0_Vector4& v)
    {
        x = v.x * r; y = v.y * r; z = v.z * r; w = v.w * r;
    }
    __forceinline void setSub4(const S00a8f6c0_Vector4& a, const S00a8f6c0_Vector4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
};

struct S00a8f6c0_Matrix3
{
    S00a8f6c0_Vector4 col0, col1, col2;
};

struct S00a8f6c0_Displayer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void displayLine(const S00a8f6c0_Vector4& start, const S00a8f6c0_Vector4& end, int color, int tag);
};

struct S00a8f6c0_Drawer
{
    S00a8f6c0_Displayer* unk00;

    void FUN_00a8f6c0(const S00a8f6c0_Vector4& center, const S00a8f6c0_Matrix3& rotation, float size, int color, int tag);
};

// pdb: hkpPrimitiveDrawer::displayOrientedPoint | hkpPrimitiveDrawer.obj | fnv360_0721_beta, call_seq, medium
// pdb params: position, rot, size, color, id, tag
void S00a8f6c0_Drawer::FUN_00a8f6c0(const S00a8f6c0_Vector4& center, const S00a8f6c0_Matrix3& rotation, float size, int color, int tag)
{
    S00a8f6c0_Vector4 col0 = rotation.col0;
    S00a8f6c0_Vector4 col1 = rotation.col1;
    S00a8f6c0_Vector4 col2 = rotation.col2;
    S00a8f6c0_Vector4 tmp;
    S00a8f6c0_Vector4 p0;
    S00a8f6c0_Vector4 p1;

    tmp.setMul4(size, col0);
    p0.setSub4(center, tmp);
    tmp.setMul4(-size, col0);
    p1.setSub4(center, tmp);
    unk00->displayLine(p0, p1, color, tag);

    tmp.setMul4(size, col1);
    p0.setSub4(center, tmp);
    tmp.setMul4(-size, col1);
    p1.setSub4(center, tmp);
    unk00->displayLine(p0, p1, color, tag);

    tmp.setMul4(size, col2);
    p0.setSub4(center, tmp);
    tmp.setMul4(-size, col2);
    p1.setSub4(center, tmp);
    unk00->displayLine(p0, p1, color, tag);
}

}
}   // namespace f3m_00a8f6c0

// @f3 0x00a98f70 (community match, verified in this file)
#include <math.h>
namespace f3m_00a98f70 {
struct __declspec(align(16)) QVec {
    float x, y, z, w;
    __forceinline void setSub3(const QVec& a, const QVec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
    __forceinline void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    __forceinline void setCross(const QVec& a, const QVec& b) {
        const float nx = a.y * b.z - a.z * b.y;
        const float ny = a.z * b.x - a.x * b.z;
        const float nz = a.x * b.y - a.y * b.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline float dot3(const QVec& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline float lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline float lengthInverse3() const {
        float l2 = lengthSquared3();
        const float zero = 0.0f;
        return l2 != zero ? 1.0f / sqrtf(l2) : zero;
    }
    __forceinline void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};
struct V3A { float x, y, z; };
struct __declspec(align(16)) V3B { float x, y, z; };
class PlaneT {
public:
    QVec m_plane;
    const QVec* m_v0;
    int unk14, unk18, unk1c;
    const QVec* m_v1;
    int unk24, unk28, unk2c;
    const QVec* m_v2;
    int unk34, unk38, unk3c;
    float m_d;
    void FUN_00a98f70();
};
// pdb: hkpWingedEdge::Triangle::calculateTriangleData | hkpWingedEdge.obj | fnv360_0822_retail, objopen_prop, low, conflict (skyrim: hkWingedEdge::Triangle::calculateTriangleData)
void PlaneT::FUN_00a98f70()
{
 QVec e0; e0.setSub3(*m_v0, *m_v1); QVec e1; e1.setSub3(*m_v1, *m_v2);
 m_plane.setCross(e0, e1);
 float l2 = m_plane.x * m_plane.x + m_plane.y * m_plane.y + m_plane.z * m_plane.z; const float zero = 0.0f; float inv; if (l2 != zero) inv = 1.0f / sqrtf(l2); else inv = zero; m_plane.mul4(inv);
 m_d = m_plane.dot3(*m_v0);
}
}   // namespace f3m_00a98f70

// @f3 0x00a92e00 (community match, verified in this file)
namespace f3m_00a92e00 {
namespace f3m_00a92560 {

struct InfoA92 { unsigned int m_00, m_04, m_08, m_0c, m_10, m_iElementIndex; };

struct __declspec(align(16)) VecA92 { float x,y,z,w; };

struct VMA92 {
    unsigned int m_pRayCastInput;
    unsigned int m_pad04;
    unsigned int m_pad08;
    unsigned int m_pad0c;
    float m_invLength;
    unsigned int m_pad14, m_pad18, m_pad1c;
    volatile unsigned int m_pRayCastOutput;
    unsigned int m_pad24, m_pad28, m_pad2c;
    VecA92 m_kRayCastVector;
    void FUN_00a95770(InfoA92*, const unsigned char*, VecA92*);
};

struct Q92 {
    VecA92 m_offset;
    VecA92 m_vScale;
    VMA92 m_vm;
};

struct SegA92 { int pad00, pad04, pad08, pad0c; VecA92 m_vTo; const unsigned char* m_pMoppCode; };

__forceinline void setZeroA92(VecA92& v) { v.w = 0.0f; v.z = 0.0f; v.y = 0.0f; v.x = 0.0f; }
__forceinline void setAllA92(VecA92& v, float a) { v.x = a; v.y = a; v.z = a; v.w = a; }

// pdb: hkMoppUsingFloatAabbVirtualMachine_querySphere | hkpMoppMachine.obj | tesv_win, objrun_open, low
void FUN_00a92e00(SegA92* seg, const VecA92* to, unsigned int input, unsigned int output) {
    Q92 q;
    q.m_vm.m_invLength = 1.0f / seg->m_vTo.w;
    q.m_vm.m_pRayCastInput = *(volatile const unsigned int*)&input;
    const unsigned char* code = seg->m_pMoppCode;
    InfoA92 info;
    info.m_08 = 0; info.m_0c = 0; info.m_10 = 0; info.m_00 = 0; info.m_04 = 0; info.m_iElementIndex = 16;
    setZeroA92(q.m_offset);
    const float t = (float)(q.m_vm.m_invLength * DAT_00e80570);
    setAllA92(q.m_vScale, t);
    VecA92 dir;
    dir.x = to->x - seg->m_vTo.x;
    dir.y = to->y - seg->m_vTo.y;
    dir.z = to->z - seg->m_vTo.z;
    dir.x += dir.x; dir.y += dir.y; dir.z += dir.z;
    q.m_vm.m_pRayCastOutput = output;    q.m_vm.m_kRayCastVector.x = dir.x;
    q.m_vm.m_kRayCastVector.y = dir.y;
    q.m_vm.m_kRayCastVector.z = dir.z;
    q.m_vm.m_kRayCastVector.w = to->w + to->w;
    q.m_vm.FUN_00a95770(&info, code, &q.m_offset);
}

}
}   // namespace f3m_00a92e00

// @f3 0x00a97990 (community match, verified in this file)
namespace f3m_00a97990 {
namespace Aabb556
{
struct __declspec(align(16)) Vector
{
    float x, y, z, w;
    inline float& operator()(int i) { return (&x)[i]; }
    inline float operator()(int i) const { return (&x)[i]; }
    inline void SetAll(float a) { x = a; y = a; z = a; w = a; }
};
struct Rotation
{
    Vector column[3];
};
struct Transform
{
    Rotation rotation;
    Vector translation;
    inline float operator()(int r, int c) const { return (&rotation.column[0])[c](r); }
};
__forceinline void SetTransformedPos(Vector& out, const Transform& t, const Vector& v)
{
    float v0 = v(0);
    float v1 = v(1);
    float v2 = v(2);
    out.x = t.rotation.column[0].x * v0 + t.rotation.column[1].x * v1 + t.rotation.column[2].x * v2 + t(0, 3);
    out.y = t.rotation.column[0].y * v0 + t.rotation.column[1].y * v1 + t.rotation.column[2].y * v2 + t(1, 3);
    // Fake match: the middle element of the z row is read through the by-value accessor, the others by member.
    // The extra float temporary makes the compiler take the v1 product (in place) before the v0 product.
    out.z = t.rotation.column[0].z * v0 + t(2, 1) * v1 + t.rotation.column[2].z * v2 + t(2, 3);
    out.w = 0.0f;
}
struct Box
{
    Vector min;
    Vector max;
};
struct Shape
{
    int unk00, unk04, unk08, unk0c;
    float radius;
    int unk14;
    Vector* vertices;
    int count;
    void FUN_00a97990(const Transform&, float, Box&);
};
// pdb: hkpConvexPieceShape::getAabbImpl | hkpConvexPieceShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: localToWorld, tolerance, out
void Shape::FUN_00a97990(const Transform& transform, float tolerance, Box& out)
{
    out.min.SetAll(3.40282e38f);
    out.max.SetAll(-3.40282e38f);
    for (int i = 0; i < count; i++)
    {
        Vector v;
        SetTransformedPos(v, transform, vertices[i]);
        out.min.x = out.min.x < v.x ? out.min.x : v.x;
        out.min.y = out.min.y < v.y ? out.min.y : v.y;
        out.min.z = out.min.z < v.z ? out.min.z : v.z;
        out.min.w = out.min.w < v.w ? out.min.w : v.w;
        out.max.x = out.max.x > v.x ? out.max.x : v.x;
        out.max.y = out.max.y > v.y ? out.max.y : v.y;
        out.max.z = out.max.z > v.z ? out.max.z : v.z;
        out.max.w = out.max.w > v.w ? out.max.w : v.w;
    }
    float r = radius + tolerance;
    out.min.x -= r;
    out.min.y -= r;
    out.min.z -= r;
    out.min.w -= r;
    out.max.x += r;
    out.max.y += r;
    out.max.z += r;
    out.max.w += r;
}
}
}   // namespace f3m_00a97990

// @f3 0x00a8f9c0 (community match, verified in this file)
namespace f3m_00a8f9c0 {
namespace N00a8f9c0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline hkQuaternion() {}
    void FUN_009240d0(const hkVector4& axis, hkReal angle);
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec(3); }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

struct hkDebugDisplayHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void displayLine(const hkVector4& start, const hkVector4& end, int color, int tag);
};

struct hkpPrimitiveDrawer
{
    hkDebugDisplayHandler* m_displayHandler;

    void FUN_00a8f9c0(const hkVector4& startPos, const hkVector4& arrowDirection, const hkVector4& perpDirection,
                      int color, hkReal scale, int tag);
};

// pdb: hkpPrimitiveDrawer::displayArrow | hkpPrimitiveDrawer.obj | fnv360_0721_beta, call_seq, medium
// pdb params: startPos, arrowDirection, perpDirection, color, scale, id, tag
void hkpPrimitiveDrawer::FUN_00a8f9c0(const hkVector4& startPos, const hkVector4& arrowDirection,
                                      const hkVector4& perpDirection, int color, hkReal scale, int tag)
{
    hkVector4 endPos = startPos;
    endPos.addMul4(scale, arrowDirection);
    m_displayHandler->displayLine(startPos, endPos, color, tag);

    hkQuaternion FortyFiveAboutPerpDirection;
    FortyFiveAboutPerpDirection.FUN_009240d0(perpDirection, 3.14159265358979f / 4.0f);
    hkQuaternion MinusNinetyAboutPerpDirection;
    MinusNinetyAboutPerpDirection.FUN_009240d0(perpDirection, -1.0f * 3.14159265358979f / 2.0f);

    hkVector4 headDirection = arrowDirection;
    headDirection.setRotatedDir(FortyFiveAboutPerpDirection, headDirection);
    hkVector4 temp = endPos;
    temp.addMul4(-scale * 0.333f, headDirection);
    m_displayHandler->displayLine(endPos, temp, color, tag);

    headDirection.setRotatedDir(MinusNinetyAboutPerpDirection, headDirection);
    temp = endPos;
    temp.addMul4(-scale * 0.333f, headDirection);
    m_displayHandler->displayLine(endPos, temp, color, tag);
}

}
}   // namespace f3m_00a8f9c0

// @f3 0x00a98580 (community match, verified in this file)
namespace f3m_00a98580 {
namespace matrix6_vector_product {
// A scalar handed around by value; reading a vector component through it gives the float copy
// on the stack that the original makes of each input component.
struct Scalar
{
    float value;
    __forceinline Scalar(float v) : value(v) {}
    __forceinline float GetReal() const { return value; }
};
struct Matrix3;
struct __declspec(align(16)) Vector4
{
    float x, y, z, w;
    __forceinline Scalar GetX() const { return Scalar(x); }
    __forceinline Scalar GetY() const { return Scalar(y); }
    __forceinline Scalar GetZ() const { return Scalar(z); }
    __forceinline void SetRotatedDir(const Matrix3&, const Vector4&);
    __forceinline void SetRotatedDirOut(const Matrix3&, const Vector4&);
    __forceinline void Add4(const Vector4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
};
struct __declspec(align(16)) Matrix3
{
    Vector4 column0, column1, column2;
};
// this = m * v for a 3x3 block; w is cleared.
__forceinline void Vector4::SetRotatedDir(const Matrix3& m, const Vector4& v)
{
    const float vx = v.GetX().GetReal(), vy = v.GetY().GetReal(), vz = v.GetZ().GetReal();
    x = (m.column1.x * vy + m.column0.x * vx) + m.column2.x * vz;
    y = (m.column1.y * vy + m.column0.y * vx) + m.column2.y * vz;
    z = (m.column1.z * vy + m.column0.z * vx) + m.column2.z * vz;
    w = 0.0f;
}
// Fake match: the same product as SetRotatedDir. The three component locals are first defined in
// the order y, x, z (dead zero initialisers) and then assigned in the order x, y, z. That only
// steers which factor the compiler loads first in the second block's products (it keeps x on top
// of the x87 stack) while the three float copies stay in x, y, z order.
__forceinline void Vector4::SetRotatedDirOut(const Matrix3& m, const Vector4& v)
{
    float vy = 0.0f, vx = 0.0f, vz = 0.0f;
    vx = v.GetX().GetReal();
    vy = v.GetY().GetReal();
    vz = v.GetZ().GetReal();
    x = (m.column1.x * vy + m.column0.x * vx) + m.column2.x * vz;
    y = (m.column1.y * vy + m.column0.y * vx) + m.column2.y * vz;
    z = (m.column1.z * vy + m.column0.z * vx) + m.column2.z * vz;
    w = 0.0f;
}
// Four 3x3 blocks, 0x30 bytes each.
struct __declspec(align(16)) Matrix6
{
    Matrix3 m[2][2];
    __forceinline const Matrix3& get(int r, int c) const { return m[r][c]; }
};
struct __declspec(align(16)) Vector6
{
    Vector4 linear, angular;
};
// out = matrix * vector for a 6x6 matrix made of four 3x3 blocks and a pair of vectors.
// pdb: hkMatrix6SetMulV | hkMatrix6.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: out, a, b
void __cdecl FUN_00a98580(Vector6* out, const Matrix6* matrix, const Vector6* vector)
{
    Vector4 first, second;
    first.SetRotatedDir(matrix->get(0, 0), vector->linear);
    out->linear.SetRotatedDirOut(matrix->get(0, 1), vector->angular);
    second.SetRotatedDir(matrix->get(1, 0), vector->linear);
    out->angular.SetRotatedDir(matrix->get(1, 1), vector->angular);
    out->linear.Add4(first);
    out->angular.Add4(second);
}
}
}   // namespace f3m_00a98580

// @f3 0x00a99d10 (community match, verified in this file)
namespace f3m_00a99d10 {


namespace N00a99d10 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return (hkReal)::sqrt(r); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
}

struct hkRotation;
struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setZero4()
    {
        x = y = z = w = 0;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal r = rs;
        x *= r;
        y *= r;
        z *= r;
        w *= r;
    }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b)
    {
        const hkReal nx = a(1) * b(2) - a(2) * b(1);
        const hkReal ny = a(2) * b(0) - a(0) * b(2);
        const hkReal nz = a(0) * b(1) - a(1) * b(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline hkReal lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkMath::sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkReal& operator()(int r, int c) const { return (&m_rotation.m_col0)[c](r); }
};

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(1, 0) * v1 + r(2, 0) * v2;
    y = r(0, 1) * v0 + r(1, 1) * v1 + r(2, 1) * v2;
    z = r(0, 2) * v0 + r(1, 2) * v1 + r(2, 2) * v2;
    w = 0;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    y = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    z = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    w = 0;
}

namespace hkVector4Util
{
    __forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
    {
        int min = 0;
        int ok1 = 1;
        int ok2 = 2;

        hkReal a0 = hkMath::fabs(vectorIn(0));
        hkReal a1 = hkMath::fabs(vectorIn(1));
        hkReal a2 = hkMath::fabs(vectorIn(2));

        if (a1 < a0)
        {
            ok1 = 0;
            min = 1;
            a0 = a1;
        }

        if (a2 < a0)
        {
            ok2 = min;
            min = 2;
        }

        biVectorOut.setZero4();
        biVectorOut(ok1) = vectorIn(ok2);
        biVectorOut(ok2) = -vectorIn(ok1);
    }
}

struct ConvexShape
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
    virtual void v28();
    virtual void v2c();
    virtual void getSupportingVertex(const hkVector4& direction, hkVector4& supportingVertexOut) const;
};

struct SampleResult
{
    hkVector4 m_pointAinA;
    hkVector4 m_pointBinB;
    hkVector4 m_plane;
};

struct SampleOutput
{
    hkVector4 m_plane;
    hkVector4 m_pointAinA;
    hkReal m_distance;
};

extern const hkReal DAT_00de731c;
extern hkVector4 DAT_010f3370[3];

// Tests one direction: support points of both shapes, keeps the direction with the largest separation.
static __declspec(noinline) void FUN_00a99b30(const ConvexShape* shapeA, const ConvexShape* shapeB, const hkTransform& aTb,
                                              const hkVector4& direction, SampleResult& result)
{
    hkVector4 negDir;
    negDir.setNeg4(direction);
    hkVector4 a;
    shapeA->getSupportingVertex(negDir, a);

    hkVector4 dirB;
    dirB._setRotatedInverseDir(aTb.getRotation(), direction);
    hkVector4 b;
    shapeB->getSupportingVertex(dirB, b);

    hkVector4 bInA;
    bInA._setTransformedPos(aTb, b);
    hkVector4 delta;
    delta.setSub4(a, bInA);

    hkReal distance = direction.dot3(delta);
    if (distance > result.m_plane(3))
    {
        result.m_plane = direction;
        result.m_pointAinA = a;
        result.m_pointBinB = b;
        result.m_plane(3) = distance;
    }
}

}

using namespace N00a99d10;

// pdb: hkpCvxCvxDistByHeuristicSampling | hkpCvxCvxDistByHeuristicSampling.obj | fnv360_0822_retail, call_gap + bridge(call_seq|callee_sim) + skyrim(call_seq), high
void __cdecl hkpCvxCvxDistByHeuristicSampling(const ConvexShape* shapeA, const ConvexShape* shapeB, const hkTransform& aTb, hkVector4& pointAinA,
                          hkVector4& pointBinB, SampleOutput& out)
{
    SampleResult result;
    result.m_plane(3) = DAT_00de731c;

    const hkVector4* axisPtr = DAT_010f3370;
    int count = 3;
    do
    {
        hkVector4 axis = *axisPtr;
        axisPtr++;
        FUN_00a99b30(shapeA, shapeB, aTb, axis, result);
        axis.setNeg4(axis);
        FUN_00a99b30(shapeA, shapeB, aTb, axis, result);
    } while (--count);

    hkReal limit = 1.0f;
    do
    {
        limit *= 0.99f;

        hkVector4 perp;
        hkVector4Util::calculatePerpendicularVector(result.m_plane, perp);
        perp.normalize3();

        hkVector4 cross;
        cross.setCross(result.m_plane, perp);

        perp.mul4(limit);
        cross.mul4(limit);

        hkVector4 n1;
        n1.setAdd4(result.m_plane, perp);
        hkVector4 n2;
        n2.setSub4(result.m_plane, perp);
        hkVector4 n3;
        n3.setAdd4(result.m_plane, cross);
        hkVector4 n4;
        n4.setSub4(result.m_plane, cross);

        hkReal inv = n1.lengthInverse3();
        n1.mul4(inv);
        n2.mul4(inv);
        n3.mul4(inv);
        n4.mul4(inv);

        FUN_00a99b30(shapeA, shapeB, aTb, n1, result);
        FUN_00a99b30(shapeA, shapeB, aTb, n2, result);
        FUN_00a99b30(shapeA, shapeB, aTb, n3, result);
        FUN_00a99b30(shapeA, shapeB, aTb, n4, result);

        limit *= 0.5f;
    } while (limit > 0.001f);

    pointAinA = result.m_pointAinA;
    pointBinB = result.m_pointBinB;
    out.m_distance = result.m_plane(3);
    out.m_plane = result.m_plane;
    out.m_pointAinA = result.m_pointAinA;
}
}   // namespace f3m_00a99d10

// @f3 0x00a8f470 (community match, verified in this file)
#include <math.h>
namespace f3m_00a8f470 {
namespace Sweep504
{
struct Matrix;
inline float Sqrt(float r) { return sqrtf(r); }
inline float SqrtInverse(float r) { return 1.0f / Sqrt(r); }
struct __declspec(align(16)) Vec
{
    float x, y, z, w;
    inline float& operator()(int i) { return (&x)[i]; }
    inline float operator()(int i) const { return (&x)[i]; }
    __forceinline float LengthInverse3() const
    {
        float l2 = (*this)(0) * (*this)(0) + (*this)(1) * (*this)(1) + (*this)(2) * (*this)(2);
        if (l2 != 0.0f)
            l2 = SqrtInverse(l2);
        else
            l2 = 0.0f;
        return l2;
    }
    inline void Mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void Normalize3() { Mul4(LengthInverse3()); }
    inline void SetMul4(float rs, const Vec& a) { float r = rs; x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    inline void SetAdd4(const Vec& a, const Vec& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    inline void SetSub4(const Vec& a, const Vec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    inline Vec& operator=(const Vec& b) { x = b.x; y = b.y; z = b.z; w = b.w; return *this; }
    void hkVector4_setRotatedDir(const Matrix*, const Vec*);
};
struct __declspec(align(16)) Matrix
{
    Vec rows[3];
    void FUN_00924c60(const Vec*, float);
};
struct Callback
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20(const Vec*, const Vec*, void*, void*);
};
struct Sweep
{
    Callback* callback;
    void FUN_00a8f470(const Vec*, Vec*, Vec*, float, float, float, int, void*, void*);
};
// pdb: hkpPrimitiveDrawer::drawSemiCircle | hkpPrimitiveDrawer.obj | fnv360_0822_retail, objrun, medium
// pdb params: center, normal, startPerp, thetaMin, thetaMax, radius, numSegments, color, id, tag
void Sweep::FUN_00a8f470(const Vec* center, Vec* axis, Vec* direction, float start, float end,
                         float radius, int count, void* context, void* output)
{
    float step = (end - start) / count;
    direction->Normalize3();
    axis->Normalize3();
    Matrix matrix;
    matrix.FUN_00924c60(axis, start);
    Vec point;
    point.SetMul4(radius, *direction);
    point.hkVector4_setRotatedDir(&matrix, &point);
    point.SetAdd4(*center, point);
    matrix.FUN_00924c60(axis, step);
    if (count > 0)
    {
        do
        {
            Vec next;
            next.SetSub4(point, *center);
            next.hkVector4_setRotatedDir(&matrix, &next);
            next.SetAdd4(*center, next);
            callback->v20(&point, &next, context, output);
            point = next;
        } while (--count);
    }
}
}
}   // namespace f3m_00a8f470

// @f3 0x00a90290 (community match, verified in this file)
namespace f3m_00a90290 {
// 0x00a90290: hkpPrimitiveDrawer::displayCone(hkReal coneAngle, const hkVector4& startPos,
// const hkVector4& coneAxis, const hkVector4& perpVector, int numSegments, int color, hkReal coneSize, int tag)
// of Havok 5.5.0 (hkpUtilities, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Draws a cone for the visual debugger as numSegments lines from the apex to the rim and numSegments lines
// around the rim. The first rim direction is the cone's axis turned by the cone angle about perpVector; each
// further one is the last turned by a full circle over numSegments about the axis.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector's assignment, setMul4,
// addMul4, setAdd4, setCross, dot3, setRotatedDir by a quaternion, the quaternion's constructor, hkAllocate and
// hkDeallocate, hkThreadMemory::getInstance through getInstancePtr and the thread-local helper class) follow the
// SDK's inline code for the x87 build; the names and types of the five locals and the statement boundaries
// follow the debug records of the SDK library's object. The function's own body is written from the game's
// code.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_00a90290 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef int hkResult;
typedef unsigned long hkUlong;

const hkReal HK_REAL_PI = 3.14159265358979f;

enum HK_MEMORY_CLASS
{
    HK_MEMORY_CLASS_TOOLS = 17
};

template <typename T>
class hkThreadLocalData
{
public:
    __forceinline T getData() const { return (T)(hkUlong)TlsGetValue(m_slotID); }

    unsigned long m_slotID;
};

class hkThreadMemory;

// hkThreadMemory__s_threadMemoryInstance, the thread-local slot that holds the thread's hkThreadMemory
extern hkThreadLocalData<hkThreadMemory*> DAT_010f3170;

class hkThreadMemory
{
public:
    // allocate
    void* FUN_008f6f60(int nbytes, HK_MEMORY_CLASS cl);
    // deallocate
    void FUN_008f6f90(void* p);

    static __forceinline hkThreadMemory* getInstancePtr() { return DAT_010f3170.getData(); }
    static __forceinline hkThreadMemory& getInstance()
    {
        hkThreadMemory* instance = getInstancePtr();
        return *instance;
    }
};

template <typename TYPE>
__forceinline TYPE* hkAllocate(int numberOfObjects, HK_MEMORY_CLASS cl)
{
    return static_cast<TYPE*>(hkThreadMemory::getInstance().FUN_008f6f60(numberOfObjects * int(sizeof(TYPE)), cl));
}

template <typename TYPE>
__forceinline void hkDeallocate(TYPE* ptr)
{
    hkThreadMemory::getInstance().FUN_008f6f90(static_cast<void*>(ptr));
}

class hkQuaternion;

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0);
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

class hkQuaternion
{
public:
    __forceinline hkQuaternion(const hkVector4& axis, hkReal angle) { FUN_009240d0(axis, angle); }

    // setAxisAngle
    void FUN_009240d0(const hkVector4& axis, hkReal angle);

    __forceinline const hkVector4& getImag() const { return m_vec; }

    hkVector4 m_vec;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x = r * a.x;
    y = r * a.y;
    z = r * a.z;
    w = r * a.w;
}

__forceinline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x += r * a.x;
    y += r * a.y;
    z += r * a.z;
    w += r * a.w;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

struct hkTransform;
class hkDisplayGeometry;
template <typename T>
class hkArray;

class hkDebugDisplayHandler
{
public:
    virtual ~hkDebugDisplayHandler() {}
    virtual hkResult addGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform,
                                 hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult addGeometryInstance(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag,
                                         hkUlong shapeIdHint) = 0;
    virtual hkResult setGeometryColor(int color, hkUlong id, int tag) = 0;
    virtual hkResult updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
    virtual hkResult removeGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult updateCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane,
                                  hkReal farPlane, hkReal fov, const char* name) = 0;
    virtual hkResult displayPoint(const hkVector4& position, int colour, int tag) = 0;
    virtual hkResult displayLine(const hkVector4& start, const hkVector4& end, int color, int tag) = 0;
};

class hkpPrimitiveDrawer
{
public:
    // displayCone
    void FUN_00a90290(hkReal coneAngle, const hkVector4& startPos, const hkVector4& coneAxis,
                      const hkVector4& perpVector, int numSegments, int color, hkReal coneSize, int tag);

protected:
    hkDebugDisplayHandler* m_displayHandler;
};

void hkpPrimitiveDrawer::FUN_00a90290(hkReal coneAngle, const hkVector4& startPos, const hkVector4& coneAxis,
                                      const hkVector4& perpVector, int numSegments, int color, hkReal coneSize,
                                      int tag)
{
    hkVector4* cone_points = hkAllocate<hkVector4>(numSegments, HK_MEMORY_CLASS_TOOLS);

    hkReal segment_length = coneSize / coneAngle;
    hkQuaternion RotationFromNormal(perpVector, coneAngle);
    hkQuaternion RotationAboutAxis(coneAxis, 2 * HK_REAL_PI / numSegments);

    hkVector4 offset_direction;
    offset_direction.setRotatedDir(RotationFromNormal, coneAxis);

    // the points on the rim
    for (int i = 0; i < numSegments; i++)
    {
        cone_points[i] = startPos;
        cone_points[i].addMul4(segment_length, offset_direction);
        offset_direction.setRotatedDir(RotationAboutAxis, offset_direction);
    }

    for (int i = 0; i < numSegments; i++)
    {
        // from the apex to the rim, and along the rim to the next point
        m_displayHandler->displayLine(startPos, cone_points[i], color, tag);
        m_displayHandler->displayLine(cone_points[i], cone_points[(i + 1) % numSegments], color, tag);
    }

    hkDeallocate<hkVector4>(cone_points);
}

}  // namespace f3m_00a90290
}   // namespace f3m_00a90290

// @f3 0x00a9a9a0 (community match, verified in this file)
#include <math.h>
namespace f3m_00a9a9a0 {

// 0x00a9a9a0: sets up a box query for a MOPP tree walk (hkpMoppObbVirtualMachine in Havok terms). The oriented box
// (half extents, transform, extra radius) is turned into an axis-aligned box, moved into the tree's integer
// coordinates (offset and scale from the tree's code), kept in the machine, and its upper 16 bits are written to
// the query the walk starts from.

namespace MoppObbQueryA9A9A0 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return (hkReal)::sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
    // float to int with the current rounding mode
    __forceinline int hkToIntFast(hkReal r) { return fnv_FloatToInt(r); }
}

class __declspec(align(16)) hkVector4
{
public:
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    __forceinline hkReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
    __forceinline void setAll(hkReal a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    // all four components = v(i)
    __forceinline void setBroadcast(const hkVector4& v, int i)
    {
        hkReal r = v(i);
        x = r;
        y = r;
        z = r;
        w = r;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void setAbs4(const hkVector4& v)
    {
        x = hkMath::fabs(v.x);
        y = hkMath::fabs(v.y);
        z = hkMath::fabs(v.z);
        w = hkMath::fabs(v.w);
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
};

struct hkpMoppCode
{
    struct CodeInfo
    {
        // offset in x, y, z and the scale in w
        hkVector4 m_offset;

        __forceinline hkReal getScale() const { return m_offset(3); }
    };

    int unk00[4];
    CodeInfo m_info;
};

// the integer box a tree walk starts with
struct hkpMoppObbVirtualMachineQuery
{
    int m_xHi;
    int m_yHi;
    int m_zHi;
    int unk0c;
    int m_xLo;
    int m_yLo;
    int m_zLo;
    int unk1c;
    int m_xM;
    int m_yM;
    int m_zM;
    int m_radius;
    int m_offset_x;
    int m_offset_y;
    int m_offset_z;
    int m_shift;
    int m_primitiveOffset;
    int m_properties;
};

class hkpMoppObbVirtualMachine
{
public:
    void FUN_00a9a9a0(const hkVector4& extent, const hkTransform& BvToWorld, const hkReal& radius, hkpMoppObbVirtualMachineQuery& query);

    int unk00[4];
    int m_xHi;
    int m_yHi;
    int m_zHi;
    int unk1c;
    int m_xLo;
    int m_yLo;
    int m_zLo;
    int unk2c;
    int m_xM;
    int m_yM;
    int m_zM;
    int m_radius;
    int unk40;
    const hkpMoppCode* m_code;
};

// pdb: hkpMoppEarlyExitObbVirtualMachine::generateQueryFromNode | hkpMoppEarlyExitObbVirtualMachine.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: extent, BvToWorld, radius, query
void hkpMoppObbVirtualMachine::FUN_00a9a9a0(const hkVector4& extent, const hkTransform& BvToWorld, const hkReal& radius, hkpMoppObbVirtualMachineQuery& query)
{
    const hkTransform& transform = BvToWorld;
    // the half extents of the box along each world axis
    hkVector4 he0;
    he0.setBroadcast(extent, 0);
    hkVector4 he1;
    he1.setBroadcast(extent, 1);
    hkVector4 he2;
    he2.setBroadcast(extent, 2);

    hkVector4 x;
    x.setMul4(he0, transform.getColumn(0));
    hkVector4 y;
    y.setMul4(he1, transform.getColumn(1));
    hkVector4 z;
    z.setMul4(he2, transform.getColumn(2));

    x.setAbs4(x);
    y.setAbs4(y);
    z.setAbs4(z);

    hkVector4 max;
    max.setAdd4(y, x);
    max.add4(z);

    hkVector4 radius4;
    radius4.setAll(radius);
    max.add4(radius4);

    hkVector4 min;
    min.setNeg4(max);

    max.add4(transform.getTranslation());
    min.add4(transform.getTranslation());

    // into the integer space of the tree, widened by one unit
    m_xLo = hkMath::hkToIntFast((min(0) - m_code->m_info.m_offset(0)) * m_code->m_info.getScale());
    m_xLo -= 1;
    m_xHi = hkMath::hkToIntFast((max(0) - m_code->m_info.m_offset(0)) * m_code->m_info.getScale()) + 1;
    m_yLo = hkMath::hkToIntFast((min(1) - m_code->m_info.m_offset(1)) * m_code->m_info.getScale());
    m_yLo -= 1;
    m_yHi = hkMath::hkToIntFast((max(1) - m_code->m_info.m_offset(1)) * m_code->m_info.getScale()) + 1;
    m_zLo = hkMath::hkToIntFast((min(2) - m_code->m_info.m_offset(2)) * m_code->m_info.getScale());
    m_zLo -= 1;
    m_zHi = hkMath::hkToIntFast((max(2) - m_code->m_info.m_offset(2)) * m_code->m_info.getScale()) + 1;

    m_xM = (m_xLo + m_xHi) >> 1;
    m_yM = (m_yLo + m_yHi) >> 1;
    m_zM = (m_zLo + m_zHi) >> 1;

    const hkReal length = extent.length3();
    const hkReal radiusSum = length + radius;
    m_radius = hkMath::hkToIntFast(radiusSum * m_code->m_info.getScale()) + 1;

    // the walk starts at the top 16 bits
    query.m_xLo = m_xLo >> 16;
    query.m_xHi = (m_xHi >> 16) + 1;
    query.m_yLo = m_yLo >> 16;
    query.m_yHi = (m_yHi >> 16) + 1;
    query.m_zLo = m_zLo >> 16;
    query.m_zHi = (m_zHi >> 16) + 1;
    query.m_xM = m_xM >> 16;
    query.m_yM = m_yM >> 16;
    query.m_zM = m_zM >> 16;
    query.m_radius = (m_radius >> 16) + 1;

    query.m_offset_x = 0;
    query.m_offset_y = 0;
    query.m_offset_z = 0;
    query.m_shift = 0;
    query.m_primitiveOffset = 0;
    query.m_properties = 0;
}

}
}   // namespace f3m_00a9a9a0

// @f3 0x00a8aae0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a8aae0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace Query503
{
struct Heap
{
    void FUN_008f6d90(void*, unsigned int, int);
};
struct __declspec(align(16)) Vector
{
    float x, y, z, w;
};
struct Pair { Vector first, second; };
template <class T> struct Array
{
    T* data;
    int count;
    int capacityFlags;
    Array() : data(0), count(0), capacityFlags(0x80000000) {}
    void Release()
    {
        if ((capacityFlags & 0x80000000) == 0)
        {
            int masked = capacityFlags & 0x3fffffff;
            Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, masked * sizeof(T), 23);
        }
    }
};
struct Config
{
    unsigned char type;
    bool transform;
    unsigned int state[4];
    float tolerance;
};
void __cdecl FUN_00901f10(Array<Vector>*, int);
void __cdecl FUN_00a58ce0(void*, Vector*, Vector*);
void __cdecl FUN_00a58f00(void*, Vector*, Vector*);
void __cdecl FUN_00a5c3d0(bool*, const Config*, void*, void*, Vector*, bool*, Array<Vector>*, Array<Pair>*);
bool* __cdecl FUN_00a8a740(bool*, Array<Vector>*, void*, void*, Array<Vector>*, Array<Pair>*, float);
bool* __cdecl FUN_00a8a830(bool*, Array<Vector>*, void*, void*, Array<Vector>*, Array<Pair>*, float);

// pdb: hkGeomConvexHullTester::isValidHull | hkGeomConvexHullTester.obj | tesv_win, call_gap_sim, low
bool* __cdecl FUN_00a8aae0(bool* output, const Config* config, const Vector* input, int count,
                            void* first, void* second)
{
    float tolerance = config->tolerance;
    bool choose = false;
    Array<Pair> pairs;
    Array<Vector> vectors;
    Array<Vector> points;
    Vector stageA0, stageA1, stageB0, stageB1, scratch;
    bool result;
    for (int i = 0; i < count; ++i)
    {
        if (points.count == (points.capacityFlags & 0x3fffffff))
            FUN_00901f10(&points, sizeof(Vector));
        Vector& point = points.data[points.count++];
        point.x = input[i].x;
        point.y = input[i].y;
        point.z = input[i].z;
        point.w = input[i].w;
    }
    if (config->transform)
    {
        FUN_00a58ce0(second, &stageA1, &stageA0);
        FUN_00a58ce0(&points, &stageB1, &stageB0);
    }
    *output = true;
    FUN_00a5c3d0(&result, config, first, second, &scratch, &choose, &vectors, &pairs);
    if (choose)
        *output = *FUN_00a8a740(&result, &points, first, second, &vectors, &pairs, tolerance);
    else
        *output = *FUN_00a8a830(&result, &points, first, second, &vectors, &pairs, tolerance);
    if (config->transform)
    {
        FUN_00a58f00(second, &stageA1, &stageA0);
        FUN_00a58f00(&points, &stageB1, &stageB0);
    }
    points.Release();
    vectors.Release();
    pairs.Release();
    return output;
}
}
}   // namespace f3m_00a8aae0

// @f3 0x00a91000 (community match, verified in this file)
namespace f3m_00a91000 {
struct Callee {
    void hkpPoweredChainData_addConstraintInfoInBodySpace(void* p1, void* p2, void* p3, int a4, int a5, int a6);
};

struct Owner {
    int unk00;
    int unk04;
    int unk08;
    Callee* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void** m_2c;
    int m_30;

    void FUN_00a50b70(char* a2);
};

struct __declspec(align(16)) PointClass {
    float x, y, z, w;
    void FUN_008d2970(const void* src, const void* a3);
};

struct LocalPoints {
    PointClass first;
    PointClass second;
};

struct RelativeOrientationData {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int argument4;
    int argument5;
    int argument6;
    int unk2c;

    void FUN_008db610(void* a1, void* a2);
};

// pdb: hkpConstraintChainUtil::addConstraintToPoweredChain | hkpConstraintChainUtil.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
void hkpConstraintChainUtil_addConstraintToPoweredChain(Owner* a1, char* a2, const void* a3, int a4, int a5, int a6)
{
    Callee* pCallee = a1->m_0c;
    char* e1;
    char* e2;
    {
        char* p = (char*)a1->m_2c[a1->m_30 - 1] + 0x10;
        e1 = (*(unsigned char*)(p + 0x18) == 1) ? p + (signed char)p[0x10] : 0;
    }
    {
        char* p = a2 + 0x10;
        e2 = (*(unsigned char*)(p + 0x18) == 1) ? p + (signed char)p[0x10] : 0;
    }
    LocalPoints points;
    points.first.FUN_008d2970((const void*)(e1 + 0xe0), a3);
    points.second.FUN_008d2970((const void*)(e2 + 0xe0), a3);
    RelativeOrientationData relativeOrientation;
    relativeOrientation.FUN_008db610(e2 + 0x150, e1 + 0x150);
    relativeOrientation.argument4 = a4;
    relativeOrientation.argument5 = a5;
    relativeOrientation.argument6 = a6;
    pCallee->hkpPoweredChainData_addConstraintInfoInBodySpace(&points.first, &points.second, (void*)&relativeOrientation, a4, a5, a6);
    a1->FUN_00a50b70(a2);
}
}   // namespace f3m_00a91000

// @f3 0x00a929b0 (community match, verified in this file)
namespace f3m_00a929b0 {

extern const double DAT_00e80570;
namespace f3m_00a929b0 {
struct __declspec(align(16)) V925 { float x,y,z,w; void setAbs(const V925& a) {x=(float)fabs(a.x);y=(float)fabs(a.y);z=(float)fabs(a.z);w=(float)fabs(a.w);} void setAdd(const V925& a,const V925& b) {x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;} void add(const V925& a) {x=a.x+x;y=a.y+y;z=a.z+z;w=a.w+w;} void setAll(float a) {x=a;y=a;z=a;w=a;} void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;} void FUN_00a93000(const void*,const V925*); };
struct __declspec(align(16)) M925 { V925 x,y,z,w;
__forceinline void transpose(const V925& a,const V925& b,const V925& c,const V925& d) {
x.set(a.x,b.x,c.x,d.x);y.set(a.y,b.y,c.y,d.y);z.set(a.z,b.z,c.z,d.z);w.set(a.w,b.w,c.w,d.w);
} };
struct Pair925 { V925 zero,radius; };
struct C925 { int unk00,unk04,unk08,unk0c; V925 unk10; const unsigned char* unk20; };
struct In925 { int count; const V925* vertices; };
struct Out925 { int unk00,unk04,unk08,unk0c,unk10,unk14; Out925() {unk08=0;unk0c=0;unk10=0;unk14=16;unk00=0;unk04=0;} };
struct __declspec(align(16)) State925 {
 void* unk00; int unk04,unk08,unk0c; float unk10; int unk14,unk18,unk1c;
 void* unk20; int unk24,unk28,unk2c; int count; int unk34,unk38,unk3c;
 M925 blocks[8]; M925 absolute[8];
 void FUN_00a942b0(Out925*,const unsigned char*,const Pair925*);
};
// pdb: hkMoppUsingFloatAabbVirtualMachine_queryPlanesOptimized | hkpMoppMachine.obj | tesv_win, objopen_prop, low
void FUN_00a929b0(C925* context,In925* input,void* output,void* work) {
 const unsigned char* program=context->unk20;
 State925 state;
 state.unk00=output;
 state.unk10=1.0f/context->unk10.w;
 Out925 result;
 int n=input->count;
 const V925* src=input->vertices;
 M925* dst=state.blocks;
 state.count=0;
 Pair925 bounds; bounds.zero.x=bounds.zero.y=bounds.zero.z=bounds.zero.w=0.0f;
 bounds.radius.setAll((float)(state.unk10*DAT_00e80570));
 int bulk=n&~3;
 int i=0;
 for(; i<bulk; i+=4,++dst,src+=4) {
  dst->transpose(src[0],src[1],src[2],src[3]);
  ++state.count;
 }
 const V925* b=src+1; const V925* c=src+2; const V925* d=src+3;
 switch(n-i) {case 1:b=src; case 2:c=src; case 3:d=src;
  dst->transpose(*src,*b,*c,*d);
  ++dst;++state.count;
 }
 M925* abs=state.absolute+state.count-1;
 --dst;
 for(;dst>=state.blocks;--dst,--abs) {
  abs->x.setAbs(dst->x);
  abs->y.setAbs(dst->y);
  abs->z.setAbs(dst->z);
  abs->w.x=abs->w.y=abs->w.z=abs->w.w=0.0f;
  V925 adjustment; adjustment.FUN_00a93000(dst,&context->unk10);
  dst->w.setAdd(dst->w,adjustment);
  dst->w.add(dst->w);
 }
 state.unk20=work;
 state.FUN_00a942b0(&result,program,&bounds);
}
}
}   // namespace f3m_00a929b0

// @f3 0x00a991d0 (community match, verified in this file)
namespace f3m_00a991d0 {

namespace NativeHullFan {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void SetSubXYZ(const Vec4& a, const Vec4& b) {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z;
    }
    __forceinline void SetCross(const Vec4& a, const Vec4& b) {
        x = a.y*b.z-a.z*b.y;
        y = a.z*b.x-a.x*b.z;
        z = a.x*b.y-a.y*b.x;
        w = 0.0f;
    }
    __forceinline float Dot3(const Vec4& b) const {
        return x*b.x+y*b.y+z*b.z;
    }
    __forceinline float MagnitudeSquared() const { return (double)(x*x)+y*y+z*z; }
    __forceinline void Normalize() {
        float squared=MagnitudeSquared();
        float inverse;
        if (squared != 0.0f) inverse = 1.0f / float(sqrt(double(squared)));
        else inverse = 0.0f;
        x*=inverse; y*=inverse; z*=inverse; w*=inverse;
    }

};
struct Face;
struct Edge;
struct Vertex {
    Vec4 position;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    Edge* pending;
    unsigned int unk34, unk38, unk3c;
};
struct Edge {
    Vertex* vertex;
    Edge* next;
    Edge* opposite;
    Face* face;
};
struct Face {
    Vec4 normal;
    Edge edges[3];
    float distance;
    unsigned int pending, unk48, unk4c;
};
struct Hull {
    unsigned int unk00, unk04;
    int vertexCount, freeCount, faceCount;
    unsigned int unk14, unk18, unk1c;
    Vertex vertices[55];
    Face* freeFaces[100];
    Face faces[100];
    int FUN_00a991d0(int count, Edge* first, Vertex* tip);
};
// pdb: hkpWingedEdge::patchInBoundaryToPointOfViewExpansion | hkpWingedEdge.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkWingedEdge::patchInBoundaryToPointOfViewExpansion)
// pdb params: chainLength, edgeChain, pointOfView
int Hull::FUN_00a991d0(int count, Edge* first, Vertex* tip)
{
    Face* staged[100];
    int remaining = count;
    int used = 0;
    for (int slot = freeCount - 1; remaining; --slot) {
        if (slot < 0)
            break;
        staged[used] = freeFaces[slot];
        --freeCount;
        --remaining;
        ++used;
    }
    if (remaining > 0) {
        for (int k = 0; k < remaining; ++k) {
            int index = faceCount++;
            staged[used++] = &faces[index];
        }
    }
    Edge* firstEdge = first;
    Edge* boundary = firstEdge;
    for (int i = 0; i < count; ++i) {
        if (!boundary)
            return 2;
        Face* face = staged[i];
        Face* nextFace;
        if (i + 1 < count)
            nextFace = staged[i + 1];
        else
            nextFace = staged[0];
        face->edges[0].face = face;
        face->edges[1].face = face;
        face->edges[2].face = face;
        face->edges[1].next = &face->edges[2];
        face->edges[2].next = &face->edges[0];
        face->edges[0].next = &face->edges[1];
        Vertex* end = boundary->next->vertex;
        Vertex* start = boundary->vertex;
        face->edges[0].vertex = end;
        face->edges[2].vertex = tip;
        face->edges[1].vertex = start;
        boundary->opposite = &face->edges[0];
        face->edges[0].opposite = boundary;
        nextFace->edges[1].opposite = &face->edges[2];
        face->edges[2].opposite = &nextFace->edges[1];
        // The two ends of the boundary edge are bound once for the first difference; the second
        // difference reads start->position directly. (Compiler note: this spelling, not the arithmetic,
        // is what makes the z term of the plane distance below load normal.z first.)
        const Vec4& endPosition=end->position;
        const Vec4& startPosition=start->position;
        Vec4 along;
        along.SetSubXYZ(endPosition,startPosition);
        Vec4 towardTip;
        towardTip.SetSubXYZ(start->position,tip->position);
        Vec4 normal;
        normal.SetCross(along,towardTip);
        float lengthSquared=normal.MagnitudeSquared();
        if (lengthSquared==0.0f)
            return 2;
        normal.Normalize();
        face->distance=normal.Dot3(end->position);
        face->normal.x=normal.x;
        face->normal.y=normal.y;
        face->normal.z=normal.z;
        face->normal.w=normal.w;
        Vertex* next = boundary->next->vertex;
        boundary = next->pending;
        next->pending = 0;
    }
    for (int i = 0; i < faceCount; ++i)
        faces[i].pending = 0;
    for (int i = 0; i < vertexCount; ++i)
        vertices[i].pending = 0;
    // The fan is closed only if the walk came back to the edge it started from. The test is written in
    // both directions: with a single comparison the compiler leaves the edge parameter in memory
    // (one byte longer) instead of keeping it in esi around the main loop as the original does.
    return (firstEdge != boundary && boundary != firstEdge) ? 2 : 0;
}
}
}   // namespace f3m_00a991d0

// @f3 0x00a995d0 (community match, verified in this file)
#include <math.h>
namespace f3m_00a995d0 {
// Shared exact draft: checkpoint chk_50ddec23e396422b9941, credited there to
// another contributor, and rechecked.
// hkpWingedEdge::findTriangleNearestOrigin written from the Havok 5.5.0 SDK (hkpInternal.lib,
// hkpWingedEdge.obj, hybrid debug records lines 426-492) on the FPU hkVector4 inline bodies of
// hk550\Source\Common\Base\Math\Vector\Fpu\hkFpuVector4.inl, hkBool from hkBaseTypes.h, hkMath::fabs from
// hkFpuMathFuncs.inl. No constructors (HK_DISABLE_VECTOR4_CONSTRUCTORS).

namespace f3m_00a995d0 {
typedef float hkReal;
typedef hkReal hkSimdReal;

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
    inline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
    char m_bool;
};

namespace hkMath
{
    inline hkReal fabs(hkReal r) { return ::fabsf(r); }
}

class hkVector4
{
public:
    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    inline hkReal& operator()(int i) { return (&x)[i]; }
    inline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    inline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    inline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
        const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
        const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
        this->set( nx, ny, nz , 0.0f );
    }
    inline hkSimdReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + ( y * a.y ) + ( z * a.z );
    }
    inline hkSimdReal lengthSquared3() const
    {
        return this->dot3(*this);
    }
};

static const hkReal HK_WINGED_EDGE_DISTANCE_TOLERANCE = 1e-5f;

struct Triangle;
struct Edge;

struct Vertex
{
    hkVector4 m_position;
    hkVector4 m_pointAinA;
    hkVector4 m_pointBinB;
    Edge* m_referee;
};

struct Edge
{
    Vertex* m_vertex;
    Edge* m_next;
    Edge* m_neighbour;
    Triangle* m_triangle;
};

struct Triangle
{
    hkVector4 m_normal;
    Edge m_edge[3];
    hkReal m_distanceToOrigin;
    enum TriangleState { HK_NOT_VISITED = 0, HK_VISIBLE = 1, HK_INVISIBLE = 2, HK_FIND_NEAREST_TRIANGLE_VISITED = 3, HK_UNKNOWN = 4 };
    TriangleState m_state;
};

struct hkpWingedEdge
{
    void FUN_00a99ae0();
    Triangle* FUN_00a995d0(Triangle* triangleOnNearestPlane);
};

// pdb: hkpWingedEdge::findTriangleNearestOrigin | hkpWingedEdge.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkWingedEdge::findTriangleNearestOrigin)
// pdb params: triangleOnNearestPlane
Triangle* hkpWingedEdge::FUN_00a995d0(Triangle* triangleOnNearestPlane)
{
    FUN_00a99ae0();

    Triangle* nearestTriangle = triangleOnNearestPlane;
    Edge* goodEdge = 0;

    hkBool found = false;
    hkBool failed = false;
    while ( !found && !failed )
    {
        nearestTriangle->m_state = Triangle::HK_FIND_NEAREST_TRIANGLE_VISITED;
        int e;
        for ( e = 0; e < 3; e++ )
        {
            if ( &nearestTriangle->m_edge[e] == goodEdge )
            {
                continue;
            }
            hkVector4& start = nearestTriangle->m_edge[e].m_vertex->m_position;
            hkVector4& end = nearestTriangle->m_edge[e].m_next->m_vertex->m_position;

            hkVector4 edgeVector; edgeVector.setSub4( end, start );
            hkReal edgeLen2 = edgeVector.lengthSquared3();
            hkVector4 edgeNormal; edgeNormal.setCross( edgeVector, nearestTriangle->m_normal );

            hkReal distanceToEdge = start.dot3( edgeNormal );

            if ( distanceToEdge * hkMath::fabs(distanceToEdge) < -HK_WINGED_EDGE_DISTANCE_TOLERANCE * HK_WINGED_EDGE_DISTANCE_TOLERANCE * edgeLen2 )
            {
                Triangle* neighbourTriangle = nearestTriangle->m_edge[e].m_neighbour->m_triangle;

                if ( triangleOnNearestPlane->m_distanceToOrigin > 0.0f )
                {
                    if ( neighbourTriangle->m_distanceToOrigin < triangleOnNearestPlane->m_distanceToOrigin * 0.9f )
                    {
                        continue;
                    }
                }

                goodEdge = nearestTriangle->m_edge[e].m_neighbour;
                nearestTriangle = neighbourTriangle;

                failed = ( neighbourTriangle->m_state == Triangle::HK_FIND_NEAREST_TRIANGLE_VISITED );
                break;
            }
        }
        found = ( e == 3 );
    }

    return nearestTriangle;
}

}
}   // namespace f3m_00a995d0
