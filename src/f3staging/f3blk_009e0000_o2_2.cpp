#include <windows.h>
#include <math.h>
#include <math.h>
// src/f3staging/f3blk_009e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x009ed140 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e80824[];
namespace f3m_009ed140 {
namespace f3m_009ed140 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct S9ed140_Rot;
struct S9ed140_Transform;
struct __declspec(align(16)) S9ed140_Vec4 {
    float x, y, z, w;
    __forceinline void setRotatedInverseDir(const S9ed140_Rot& r, const S9ed140_Vec4& v);
    __forceinline void setTransformedInversePos(const S9ed140_Transform& t, const S9ed140_Vec4& v);
};
struct S9ed140_Rot {
    S9ed140_Vec4 col0, col1, col2;
};
struct S9ed140_Transform {
    S9ed140_Rot rot;
    S9ed140_Vec4 trans;
};
__forceinline void S9ed140_Vec4::setRotatedInverseDir(const S9ed140_Rot& r, const S9ed140_Vec4& v)
{
    float vx = v.x;
    float vy = v.y;
    float vz = v.z;
    x = r.col0.x * vx + r.col0.y * vy + r.col0.z * vz;
    y = r.col1.x * vx + r.col1.y * vy + r.col1.z * vz;
    z = r.col2.x * vx + r.col2.y * vy + r.col2.z * vz;
    w = 0.0f;
}
__forceinline void S9ed140_Vec4::setTransformedInversePos(const S9ed140_Transform& t, const S9ed140_Vec4& v)
{
    float dx = v.x - t.trans.x;
    float dy = v.y - t.trans.y;
    float dz = v.z - t.trans.z;
    const S9ed140_Rot& r = t.rot;
    x = r.col0.x * dx + r.col0.y * dy + r.col0.z * dz;
    y = r.col1.x * dx + r.col1.y * dy + r.col1.z * dz;
    z = r.col2.x * dx + r.col2.y * dy + r.col2.z * dz;
    w = 0.0f;
}
__forceinline void TIP3(S9ed140_Vec4& o, const S9ed140_Transform& t, const S9ed140_Vec4& v)
{
    float dz = 0.0f, dy = 0.0f, dx = 0.0f;
    dx = v.x - t.trans.x;
    dy = v.y - t.trans.y;
    dz = v.z - t.trans.z;
    const S9ed140_Rot& r = t.rot;
    o.x = r.col0.x * dx + r.col0.y * dy + r.col0.z * dz;
    o.y = r.col1.x * dx + r.col1.y * dy + r.col1.z * dz;
    o.z = r.col2.x * dx + r.col2.y * dy + r.col2.z * dz;
    o.w = 0.0f;
}
struct S9ed140_RayInput {
    S9ed140_Vec4 from;
    S9ed140_Vec4 to;
    unsigned int filterInfo;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};
struct S9ed140_Bool {
    char m_bool;
    S9ed140_Bool() {}
    S9ed140_Bool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};
struct S9ed140_Normal {
    float x, y, z, w;
    void hkVector4_setRotatedDir(const S9ed140_Rot& r, const S9ed140_Normal& v);
};
struct S9ed140_RayOutput {
    S9ed140_Normal normal;
    float hitFraction;
    unsigned int extraInfo;
    unsigned int unk18, unk1c;
    unsigned int keys[8];
    int keyIndex;
};
struct S9ed140_Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual S9ed140_Bool castRay(const S9ed140_RayInput& in, S9ed140_RayOutput& out);
};
struct S9ed140_Mon { unsigned int unk00; unsigned int* pos; unsigned int unk08; unsigned int* cap; };

struct S9ed140_TransformShape {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    S9ed140_Shape* child;
    unsigned int unk1c;
    S9ed140_Transform transform;
    S9ed140_Bool hkpConvexTransformShape_castRayImpl(const S9ed140_RayInput& input, S9ed140_RayOutput& results);
};
}
namespace f3m_009ed140 {
// pdb: hkpConvexTransformShape::castRayImpl | hkpConvexTransformShape.obj | fnv360_0822_retail, objopen_prop + bridge(caller_sim|vtable) + skyrim(caller_sim), high
S9ed140_Bool S9ed140_TransformShape::hkpConvexTransformShape_castRayImpl(const S9ed140_RayInput& input, S9ed140_RayOutput& results)
{
    S9ed140_Mon* mon = (S9ed140_Mon*)TlsGetValue(DAT_0116913c);
    unsigned int* pos = mon->pos;
    if (pos < mon->cap) {
        *(const char**)pos = ::DAT_00e80824;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        pos[1] = ticks;
        mon->pos = pos + 3;
    }
    S9ed140_RayInput sub = input;
    sub.from.setTransformedInversePos(transform, input.from);
    TIP3(sub.to, transform, input.to);
    results.keyIndex += 1;
    S9ed140_Bool hit = child->castRay(sub, results);
    results.keyIndex -= 1;
    if (hit) {
        S9ed140_Normal old = results.normal;
        results.normal.hkVector4_setRotatedDir(transform.rot, old);
        results.keys[results.keyIndex] = 0;
    }
    S9ed140_Mon* mon2 = (S9ed140_Mon*)TlsGetValue(DAT_0116913c);
    unsigned int* pos2 = mon2->pos;
    if (pos2 < mon2->cap) {
        *(const char**)pos2 = "Et";
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        pos2[1] = ticks;
        mon2->pos = pos2 + 3;
    }
    return hit;
}
}
}   // namespace f3m_009ed140

// @f3 0x009ec920 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009ec920 {



// Havok 5.5 hkGeometryUtility: oriented bounding box of a shape's triangle vertices (x87 FPU build).
namespace N9ec920 {


struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    __forceinline void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    static void* operator new[](unsigned int nbytes);
    static void operator delete[](void* p);
    __forceinline float dot3(const hkVector4& v) const { return x * v.x + y * v.y + z * v.z; }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline float& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline void setIdentity()
    {
        m_col0.set(1.0f, 0.0f, 0.0f, 0.0f);
        m_col1.set(0.0f, 1.0f, 0.0f, 0.0f);
        m_col2.set(0.0f, 0.0f, 1.0f, 0.0f);
    }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkBool
{
    char m_bool;
};

struct hkThreadMemory
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual char* allocateStackSlow(int nbytes) throw();
    virtual void deallocateStackSlow(void* p) throw();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    int unk24;
    char* m_stackBase;
    char* m_stackEnd;

    static __forceinline hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }

    void* allocateChunk(int nbytes, int cl) throw();
    void deallocateChunk(void* p, int nbytes, int cl) throw();
    void FUN_008f6d90(void* p, int nbytes, int cl) throw();
    void* allocate(int nbytes, int cl) throw();
    void deallocate(void* p) throw();

    __forceinline void* allocateStack(int nbytes)
    {
        int size = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        char* next = current + size;
        if (next <= m_stackEnd)
        {
            m_stackCurrent = next;
            return current;
        }
        return allocateStackSlow(size);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackBase)
            deallocateStackSlow(p);
    }
};

__forceinline void* hkVector4::operator new[](unsigned int nbytes)
{
    return hkThreadMemory::getInstance().allocate((int)nbytes, 9);
}
__forceinline void hkVector4::operator delete[](void* p)
{
    hkThreadMemory::getInstance().deallocate(p);
}

void __cdecl hkArray_reserve(void* arr, int n, int sizeElem) throw();

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
    }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArray_reserve(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
};

template <class T> struct hkLocalArray : public hkArray<T>
{
    T* m_localMemory;

    __forceinline hkLocalArray(int n)
    {
        this->m_data = (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | 0x80000000;
        m_localMemory = this->m_data;
    }
    __forceinline void release()
    {
        T* p = m_localMemory;
        hkThreadMemory::getInstance().deallocateStack(p);
        this->releaseMemory();
    }
};

struct hkGeometryTriangle
{
    int m_a;
    int m_b;
    int m_c;
};

struct hkGeometry
{
    hkArray<hkVector4> m_vertices;
    hkArray<hkGeometryTriangle> m_triangles;

    __forceinline void release()
    {
        m_triangles.releaseMemory();
        m_vertices.releaseMemory();
    }
};

void __cdecl FUN_009ec800(const void* shape, hkGeometry* geometryOut, int flags) throw();
bool __cdecl FUN_009eb8c0(const hkGeometry* geometry, hkVector4* halfExtents, hkTransform* transform, float tolerance) throw();
void __cdecl FUN_009e91d0(char* ok, const hkRotation* m, hkVector4* e0, hkVector4* e1, hkVector4* e2) throw();
float __cdecl FUN_009ea230(const float* data, int count, int stride, int steps) throw();
float __cdecl FUN_00954b60() throw();

// 0x9e93b0: extents and center of the points projected on three axes.
static __declspec(noinline) void ObbExtents(const float* verts, int numVerts, int striding, hkVector4& halfExtents,
                                            const hkVector4* axes, hkVector4& center)
{
    hkVector4 minV;
    minV.x = minV.y = minV.z = 1.3611281e+38f;
    hkVector4 maxV;
    maxV.x = maxV.y = maxV.z = -1.3611281e+38f;

    const float* v = verts;
    for (int i = 0; i < numVerts / 3; i++)
    {
        hkVector4 p;
        p.set(v[0], v[1], v[2], 0.0f);
        v = (const float*)((const char*)v + striding);
        for (int k = 0; k < 3; k++)
        {
            float d = axes[k].dot3(p);
            if (d < minV(k))
                minV(k) = d;
            if (d > maxV(k))
                maxV(k) = d;
        }
        p.set(v[0], v[1], v[2], 0.0f);
        v = (const float*)((const char*)v + striding);
        for (int k = 0; k < 3; k++)
        {
            float d = axes[k].dot3(p);
            if (d < minV(k))
                minV(k) = d;
            if (d > maxV(k))
                maxV(k) = d;
        }
        p.set(v[0], v[1], v[2], 0.0f);
        v = (const float*)((const char*)v + striding);
        for (int k = 0; k < 3; k++)
        {
            float d = axes[k].dot3(p);
            if (d < minV(k))
                minV(k) = d;
            if (d > maxV(k))
                maxV(k) = d;
        }
    }

    hkVector4 c;
    c.x = (maxV.x + minV.x) * 0.5;
    c.y = (maxV.y + minV.y) * 0.5;
    c.z = (maxV.z + minV.z) * 0.5;
    halfExtents.x = (maxV.x - minV.x) * 0.5;
    halfExtents.y = (maxV.y - minV.y) * 0.5;
    halfExtents.z = (maxV.z - minV.z) * 0.5;
    halfExtents.w = 0.0f;
    center.x = c.x * axes[0].x;
    center.y = c.x * axes[0].y;
    center.z = c.x * axes[0].z;
    center.w = c.x * axes[0].w;
    center.x += c.y * axes[1].x;
    center.y += c.y * axes[1].y;
    center.z += c.y * axes[1].z;
    center.w += c.y * axes[1].w;
    center.x += c.z * axes[2].x;
    center.y += c.z * axes[2].y;
    center.z += c.z * axes[2].z;
    center.w += c.z * axes[2].w;
}

static __forceinline float TriangleArea(const hkVector4& e0, const hkVector4& e1)
{
    hkVector4 n;
    n.x = e0.y * e1.z - e0.z * e1.y;
    n.y = e0.z * e1.x - e0.x * e1.z;
    n.z = e0.x * e1.y - e0.y * e1.x;
    return (float)sqrt(n.dot3(n)) * 0.5;
}

// 0x9eaf10: area-weighted mean and covariance of the triangles.
static __declspec(noinline) void ObbCovariance(const float* vertices, int count, int stride, hkRotation* covariance,
                                               hkVector4* center, hkBool perturb)
{
    int n = count / 3;
    float totalArea = 0;
    hkVector4 weighted;
    weighted.setZero4();
    hkVector4* all = new hkVector4[n];
    covariance->m_col0.setZero4();
    covariance->m_col1.setZero4();
    covariance->m_col2.setZero4();
    const char* p = (const char*)vertices;
    for (int t = 0; t < n; t++)
    {
        hkVector4& centroid = all[t];
        hkVector4 a, b, c;
        a.x = ((const float*)p)[0];
        a.y = ((const float*)p)[1];
        a.z = ((const float*)p)[2];
        p += stride;
        b.x = ((const float*)p)[0];
        b.y = ((const float*)p)[1];
        b.z = ((const float*)p)[2];
        p += stride;
        c.x = ((const float*)p)[0];
        c.y = ((const float*)p)[1];
        c.z = ((const float*)p)[2];
        p += stride;
        float area;
        if (perturb.m_bool)
        {
            hkVector4 r;
            r.x = FUN_00954b60();
            r.y = FUN_00954b60();
            r.z = FUN_00954b60();
            hkVector4 e0;
            e0.x = r.x * 0.01f + a.x - b.x;
            e0.y = r.y * 0.01f + a.y - b.y;
            e0.z = r.z * 0.01f + a.z - b.z;
            hkVector4 e1;
            e1.x = a.x - c.x;
            e1.y = a.y - c.y;
            e1.z = a.z - c.z;
            area = TriangleArea(e0, e1);
        }
        else
        {
            hkVector4 e0;
            e0.x = a.x - b.x;
            e0.y = a.y - b.y;
            e0.z = a.z - b.z;
            hkVector4 e1;
            e1.x = a.x - c.x;
            e1.y = a.y - c.y;
            e1.z = a.z - c.z;
            area = TriangleArea(e0, e1);
        }
        if (area > 0)
        {
            totalArea += area;
            centroid.x = (b.x + a.x + c.x) * (1.0f / 3.0f);
            centroid.y = (b.y + a.y + c.y) * (1.0f / 3.0f);
            centroid.z = (b.z + a.z + c.z) * (1.0f / 3.0f);
            centroid.w = 0.0f;
            weighted.x += area * centroid.x;
            weighted.y += area * centroid.y;
            weighted.z += area * centroid.z;
            weighted.w += area * centroid.w;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    (*covariance)(j, k) +=
                        (9.0 * centroid(j) * centroid(k) + a(j) * a(k) + b(j) * b(k) + c(j) * c(k)) * area;
                }
            }
        }
        else
        {
            centroid.x = (b.x + a.x + c.x) * (1.0f / 3.0f);
            centroid.y = (b.y + a.y + c.y) * (1.0f / 3.0f);
            centroid.z = (b.z + a.z + c.z) * (1.0f / 3.0f);
            centroid.w = 0.0f;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    (*covariance)(j, k) += a(j) * a(k) + b(j) * b(k) + c(j) * c(k);
                }
            }
        }
    }
    if (totalArea <= 0)
    {
        center->setZero4();
        covariance->m_col0.setZero4();
        covariance->m_col1.setZero4();
        covariance->m_col2.setZero4();
        (*covariance)(0, 0) = 1;
        (*covariance)(1, 1) = 1;
        (*covariance)(2, 2) = 1;
    }
    else
    {
        float inv = 1.0f / totalArea;
        weighted.x *= inv;
        weighted.y *= inv;
        weighted.z *= inv;
        weighted.w *= inv;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                (*covariance)(j, k) = (*covariance)(j, k) / 12.0 - (weighted(j) * weighted(k)) * totalArea;
            }
        }
        *center = weighted;
    }
    delete[] all;
}

} // namespace N9ec920
namespace obbh {


inline float root(float f)
{
    return (float)sqrt((double)f);
}

struct __declspec(align(16)) Vec
{
    float x, y, z, w;

    void operator=(const Vec& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    float& operator()(int i)
    {
        return (&x)[i];
    }
    const float& operator()(int i) const
    {
        return (&x)[i];
    }
    void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void setAll(float f)
    {
        x = f;
        y = f;
        z = f;
        w = f;
    }
    void mul4(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    void setMul4(float s, const Vec& v)
    {
        x = s * v.x;
        y = s * v.y;
        z = s * v.z;
        w = s * v.w;
    }
    void addMul4(float s, const Vec& v)
    {
        x += s * v.x;
        y += s * v.y;
        z += s * v.z;
        w += s * v.w;
    }
    void subMul4(float s, const Vec& v)
    {
        x -= s * v.x;
        y -= s * v.y;
        z -= s * v.z;
        w -= s * v.w;
    }
    void setAdd4(const Vec& a, const Vec& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    void setSub4(const Vec& a, const Vec& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    void setCross(const Vec& a, const Vec& b)
    {
        float cx = a.y * b.z - a.z * b.y;
        float cy = a.z * b.x - a.x * b.z;
        float cz = a.x * b.y - a.y * b.x;
        set(cx, cy, cz, 0.0f);
    }
    float dot3(const Vec& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    float lengthSquared3() const
    {
        return dot3(*this);
    }
    float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        return l2 != 0.0f ? 1.0f / root(l2) : 0.0f;
    }
    void normalize3()
    {
        mul4(lengthInverse3());
    }
};

// 0x009e93b0: half extents and centre of the vertices projected on three axes.
static __declspec(noinline) void FUN_009e93b0(const float* verts, int count, int stride, Vec& extents, const Vec* axes,
                                              Vec& position)
{
    Vec lower;
    lower.setAll(3.40282e38f);
    Vec upper;
    upper.setAll(-3.40282e38f);
    const float* vertex = verts;
    for (int tri = 0; tri < count / 3; ++tri)
    {
        Vec point;
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
    }
    Vec midpoint;
    midpoint.setAdd4(upper, lower);
    midpoint.mul4(0.5f);
    extents.setSub4(upper, lower);
    extents.mul4(0.5f);
    position.setMul4(midpoint(0), axes[0]);
    position.addMul4(midpoint(1), axes[1]);
    position.addMul4(midpoint(2), axes[2]);
}

// 0x009e97e0: volume of the box spanned by the first two axes (third from their cross product).
static __declspec(noinline) float FUN_009e97e0(const float* verts, int count, int stride, const Vec* axes)
{
    Vec tmp[3];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    tmp[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    tmp[1].subMul4(projection, axes[0]);
    tmp[1].normalize3();
    tmp[2].setCross(axes[0], axes[1]);
    tmp[2].normalize3();
    Vec position, extents;
    FUN_009e93b0(verts, count, stride, extents, tmp, position);
    return extents(1) * extents(0) * extents(2);
}

// 0x009e9c60: the two axes moved by step along the direction, then made orthonormal again.
static __declspec(noinline) void FUN_009e9c60(const Vec* axes, Vec* direction, float step, Vec* out)
{
    for (int i = 0; i < 2; ++i)
    {
        out[i] = axes[i];
        out[i].addMul4(step, direction[i]);
    }
    out[0].normalize3();
    float projection = out[0].dot3(out[1]);
    out[1].subMul4(projection, out[0]);
    out[1].normalize3();
    out[2].setCross(out[0], out[1]);
    out[2].normalize3();
}

static __declspec(noinline) float FUN_009e9ee0(const float* apVertices, int numVertices, int aiStride,
                                               const Vec* axes, float afStep, Vec* direction, int maxIter)
{
    float fb = 0;
    float fc = 0;
    float a = 0;
    float fa = FUN_009e97e0(apVertices, numVertices, aiStride, (const Vec*)axes);
    Vec tempAxes[3];
    FUN_009e9c60((const Vec*)axes, (Vec*)direction, afStep, tempAxes);
    float fTempVol = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
    float b, c;
    if (fTempVol < fa)
    {
        b = afStep;
        fb = fTempVol;
        c = b;
        for (int i = 0; i < maxIter; i++)
        {
            c *= double(1.2f);
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, c, tempAxes);
            fc = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fb < fc)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (i == maxIter - 1)
                return c;
        }
    }
    else
    {
        c = afStep;
        fc = fTempVol;
        b = c;
        for (int i = 0; i < maxIter; i++)
        {
            b = (a + b) * 0.5;
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, b, tempAxes);
            fb = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fb < fa && fb < fc)
                break;
            if (i == maxIter - 1)
                return -1.0f;
        }
    }
    if (a > b || b > c || fa < fb || fc < fb)
        return -1.0f;
    const float goldenRatio = (3.0 - root(5.0f)) * 0.5;
    float lenLeft, lenRight, x, fx;
    for (int i = 0; i < maxIter; i++)
    {
        lenLeft = b - a;
        lenRight = c - b;
        if (lenLeft > lenRight)
        {
            x = b - goldenRatio * lenLeft;
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, x, tempAxes);
            fx = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fx < fb)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + goldenRatio * lenRight;
            FUN_009e9c60((const Vec*)axes, (Vec*)direction, x, tempAxes);
            fx = FUN_009e97e0(apVertices, numVertices, aiStride, tempAxes);
            if (fx < fb)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}

// 0x009e9a70: numerical gradient of the box volume with respect to the first two axes,
// negated, and scaled down to unit length when longer.
static __declspec(noinline) void FUN_009e9a70(const float* verts, int count, int stride, const Vec* axes, float delta,
                                              Vec* direction)
{
    Vec tmp[2];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    float volume = FUN_009e97e0(verts, count, stride, axes);
    float inverse = 1.0f / delta;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            tmp[i](j) += delta;
            direction[i](j) = (FUN_009e97e0(verts, count, stride, tmp) - volume) * inverse;
            tmp[i](j) = axes[i](j);
        }
        direction[i].mul4(-1.0f);
    }
    float l2 = direction[0].lengthSquared3() + direction[1].lengthSquared3();
    if (l2 > 1.0f)
    {
        float scale = 1.0f / root(l2);
        direction[0].mul4(scale);
        direction[1].mul4(scale);
    }
}

// 0x009ea230: turns the axes step by step down the volume gradient while the volume shrinks.
static __declspec(noinline) float FUN_009ea230(const float* verts, int count, int stride, int maxIterations,
                                               const Vec* initialAxes, Vec* resultAxes)
{
    float step = 0.001f;
    float volume = FUN_009e97e0(verts, count, stride, initialAxes);
    resultAxes[0] = initialAxes[0];
    resultAxes[1] = initialAxes[1];
    resultAxes[2] = initialAxes[2];
    for (int iter = 0; iter < maxIterations; ++iter)
    {
        Vec previous[3];
        previous[0] = resultAxes[0];
        previous[1] = resultAxes[1];
        previous[2] = resultAxes[2];
        Vec direction[2];
        FUN_009e9a70(verts, count, stride, resultAxes, 0.0001f, direction);
        step = FUN_009e9ee0(verts, count, stride, resultAxes, step, direction, maxIterations);
        if (step < 0.0f)
            break;
        FUN_009e9c60(resultAxes, direction, step, resultAxes);
        float lastVolume = volume;
        volume = FUN_009e97e0(verts, count, stride, resultAxes);
        if (lastVolume < volume)
        {
            volume = lastVolume;
            resultAxes[0] = previous[0];
            resultAxes[1] = previous[1];
            resultAxes[2] = previous[2];
            break;
        }
        if (step < 1e-6f)
            break;
    }
    return volume;
}

}


using namespace N9ec920;

void __cdecl FUN_009ec920(const void* shape, hkVector4* halfExtentsOut, hkTransform* transformOut, int mode)
{
    hkGeometry geom;
    FUN_009ec800(shape, &geom, 1);

    hkLocalArray<hkVector4> verts(geom.m_triangles.getSize() * 3);
    verts.setSize(geom.m_triangles.getSize() * 3);
    for (int i = 0; i < geom.m_triangles.getSize(); i++)
    {
        verts[i * 3 + 0] = geom.m_vertices[geom.m_triangles[i].m_a];
        verts[i * 3 + 1] = geom.m_vertices[geom.m_triangles[i].m_b];
        verts[i * 3 + 2] = geom.m_vertices[geom.m_triangles[i].m_c];
    }

    if (FUN_009eb8c0(&geom, halfExtentsOut, transformOut, 0.01f))
    {
        verts.release();
        geom.release();
        return;
    }

    const float* data = &verts[0].x;
    int count = verts.getSize();

    hkVector4 ext0, ext1, ctr0, ctr1;
    hkRotation rot0, rot1;

    rot0.setIdentity();
    ObbExtents(data, count, 16, ext0, &rot0.m_col0, ctr0);
    float vol0 = ext0.x * ext0.y * ext0.z;

    {
        hkRotation cov;
        hkBool perturb;
        perturb.m_bool = 0;
        ObbCovariance(data, count, 16, &cov, &ctr1, perturb);
        char ok;
        FUN_009e91d0(&ok, &cov, &rot1.m_col0, &rot1.m_col1, &rot1.m_col2);
    }
    ObbExtents(data, count, 16, ext1, &rot1.m_col0, ctr1);
    float vol1 = ext1.x * ext1.y * ext1.z;

    if (mode == 2)
    {
        vol0 = obbh::FUN_009ea230(data, count, 16, 20, (const obbh::Vec*)&rot0, (obbh::Vec*)&rot0);
        ObbExtents(data, count, 16, ext0, &rot0.m_col0, ctr0);
        vol1 = obbh::FUN_009ea230(data, count, 16, 20, (const obbh::Vec*)&rot1, (obbh::Vec*)&rot1);
        ObbExtents(data, count, 16, ext1, &rot1.m_col0, ctr1);
    }

    hkVector4* he = halfExtentsOut;
    hkVector4 pickedCtr;
    const hkRotation* pickedRot;
    if (vol0 < vol1)
    {
        pickedRot = &rot0;
        *he = ext0;
        pickedCtr = ctr0;
    }
    else
    {
        pickedRot = &rot1;
        *he = ext1;
        pickedCtr = ctr1;
    }
    hkRotation rot = *pickedRot;
    transformOut->m_rotation = rot;
    transformOut->m_translation = pickedCtr;
    verts.release();
    geom.release();
}
}   // namespace f3m_009ec920

// @f3 0x009e2f90 (community match, verified in this file)
#include <math.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e80608[];
namespace f3m_009e2f90 {


namespace f3m_009e2f90 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct MonitorStream {
    char* start;
    char* current;
    char* end;
    char* capacityEnd;
    static MonitorStream& GetInstance() { return *(MonitorStream*)TlsGetValue(DAT_0116913c); }
    bool HasRoom() const { return current < capacityEnd; }
};

struct TimerCommand {
    const char* label;
    unsigned int time;
    unsigned int extra;
    __forceinline void SetTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        time = ticks;
    }
};

// Scoped timer: the constructor writes the begin record, the destructor the end record.
struct TimeBlock {
    __forceinline TimeBlock(const char* name)
    {
        MonitorStream& stream = MonitorStream::GetInstance();
        if (stream.HasRoom()) {
            TimerCommand* command = (TimerCommand*)stream.current;
            command->label = name;
            command->SetTime();
            stream.current = (char*)(command + 1);
        }
    }
    __forceinline ~TimeBlock()
    {
        MonitorStream& stream = MonitorStream::GetInstance();
        if (stream.HasRoom()) {
            TimerCommand* command = (TimerCommand*)stream.current;
            command->label = "Et";
            command->SetTime();
            stream.current = (char*)(command + 1);
        }
    }
};

struct Bool8 {
    char value;
    Bool8(bool b) : value(b) {}
};

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline float dot4xyz1(const Vec4& p) const { return p.x * x + p.y * y + p.z * z + w; }
    __forceinline void setInterpolate4(const Vec4& a, const Vec4& b, float t)
    {
        float s = 1.0f - t;
        x = b.x * t + a.x * s;
        y = b.y * t + a.y * s;
        z = b.z * t + a.z * s;
        w = b.w * t + a.w * s;
    }
    __forceinline void sub4(const Vec4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline void setAbs4(const Vec4& a)
    {
        x = fabs(a.x);
        y = fabs(a.y);
        z = fabs(a.z);
        w = fabs(a.w);
    }
    __forceinline int compareLessThanEqual4(const Vec4& a) const
    {
        return (x <= a.x ? 8 : 0) | (y <= a.y ? 4 : 0) | (z <= a.z ? 2 : 0) | (w <= a.w ? 1 : 0);
    }
    __forceinline void operator=(const Vec4& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
        w = a.w;
    }
};

struct RayInput { Vec4 from; Vec4 to; };

struct RayOutput {
    Vec4 normal;
    float hitFraction;
    int extraInfo, unk18, unk1c;
    int shapeKeys[8];
    int shapeKeyIndex;
    void setKey(int key) { shapeKeys[shapeKeyIndex] = key; }
};

struct PlaneShape {
    unsigned int unk00, unk04, unk08, unk0c;
    Vec4 plane;
    Vec4 center;
    Vec4 halfExtents;
    Bool8 hkpPlaneShape_castRayImpl(const RayInput& input, RayOutput& results);
};

// pdb: hkpPlaneShape::castRayImpl | hkpPlaneShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
Bool8 PlaneShape::hkpPlaneShape_castRayImpl(const RayInput& input, RayOutput& results)
{
    TimeBlock timer(::DAT_00e80608);
    float f = plane.dot4xyz1(input.from);
    float t = plane.dot4xyz1(input.to);
    if (f >= 0.0f && t < 0.0f) {
        float hitFraction = f / (f - t);
        Vec4 hitPoint;
        hitPoint.setInterpolate4(input.from, input.to, hitFraction);
        hitPoint.sub4(center);
        hitPoint.setAbs4(hitPoint);
        int mask = hitPoint.compareLessThanEqual4(halfExtents) & 0xe;
        if (mask == 0xe) {
            results.hitFraction = hitFraction;
            results.normal = plane;
            results.setKey(-1);
            return true;
        }
    }
    return false;
}

}
}   // namespace f3m_009e2f90

// @f3 0x009ea550 (community match, verified in this file)
#include <math.h>
namespace f3m_009ea550 {
// Havok 5.5 makeSphere(a, b, c, extraRadius) (hkpGeometryUtility.cpp, static). FPU hkVector4 and hkSphere as in the
// Havok 5.5 headers (hkFpuVector4.inl, hkSphere.inl).
namespace f3h_009ea550 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

struct RoundedReal
{
    hkReal value;
    RoundedReal(hkReal v) { *reinterpret_cast<volatile hkReal*>(&value) = v; }
    operator hkReal() const { return value; }
};

namespace hkMath { __forceinline hkReal sqrt(hkReal r) { return ::sqrtf(r); } }

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        x = v1.y * v2.z - v1.z * v2.y;
        y = v1.z * v2.x - v1.x * v2.z;
        z = v1.x * v2.y - v1.y * v2.x;
        w = 0.0f;
    }
    __forceinline void addMul4(const RoundedReal& rs, const hkVector4& a)
    {
        x += a.x * rs;
        y += a.y * rs;
        z += a.z * rs;
        w += a.w * rs;
    }
    __forceinline void mul4(hkSimdRealParameter rs)
    {
        hkReal s = hkReal(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkSimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkSimdReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
};

class hkSphere
{
public:
    __forceinline hkSphere() {}
    __forceinline hkSphere(const hkVector4& pt, hkReal radius)
    {
        m_pos = pt;
        m_pos(3) = radius;
    }
protected:
    hkVector4 m_pos;
};

static hkSphere FUN_009ea550(const hkVector4& c, const hkVector4& a, const hkVector4& b, hkReal r)
{
    hkVector4 u; u.setSub4(a, c);
    hkVector4 v; v.setSub4(b, c);
    hkVector4 n; n.setCross(u, v);
    hkVector4 T; T.setZero4();
    hkVector4 t;
    t.setCross(n, u);
    RoundedReal v2 = v.dot3(v);
    T.addMul4(v2, t);
    t.setCross(v, n);
    RoundedReal u2 = u.dot3(u);
    T.addMul4(u2, t);
    hkVector4 centre = c;
    T.mul4(0.5f / n.lengthSquared3());
    centre.add4(T);
    hkReal radius = T.length3();
    return hkSphere(centre, radius + r);
}

// Stand-ins for the file's callers (the bounding-sphere builders in the same file).
hkSphere makeSphereCallerStandIn(const hkVector4& p0, const hkVector4& p1, const hkVector4& p2, hkReal r)
{
    return FUN_009ea550(p0, p1, p2, r);
}
hkSphere makeSphereCallerStandIn2(const hkVector4* p, hkReal r)
{
    return FUN_009ea550(p[0], p[2], p[1], r);
}

} // namespace f3h_009ea550

}   // namespace f3m_009ea550

// @f3 0x009e3220 (community match, verified in this file)
namespace f3m_009e3220 {
// claim clm_d94de9de7ec849f3af90  target 0x009e3220 (334 B)
// box expansion: min into out->a, max into out->b (NaN picks r)
namespace f3m_009e3220 {

struct V3_9e3220 { float x, y, z; };
struct __declspec(align(16)) V4_9e3220 { float x, y, z, w; };
struct M44_9e3220 { float m[16]; };
struct B8_9e3220 { V4_9e3220 a; V4_9e3220 b; };

struct Xf_9e3220 { void hkVector4_setTransformedPos(const M44_9e3220* m, const V4_9e3220* v); };

// pdb: hkVector4::setTransformedPos | hkVector4.obj | tesv_win, objopen_prop, low
static __declspec(noinline) void FUN_009e3220(V3_9e3220* a, V3_9e3220* b,
                                              const M44_9e3220* m, B8_9e3220* out)
{
    V4_9e3220 p;
    p.x = a->x * b->x;
    p.y = a->y * b->y;
    p.z = a->z * b->z;
    p.w = 0.0f;
    V4_9e3220 r;
    ((Xf_9e3220*)&r)->hkVector4_setTransformedPos(m, &p);
    out->a.x = out->a.x < r.x ? out->a.x : r.x;
    out->a.y = out->a.y < r.y ? out->a.y : r.y;
    out->a.z = out->a.z < r.z ? out->a.z : r.z;
    out->a.w = out->a.w < r.w ? out->a.w : r.w;
    out->b.x = out->b.x > r.x ? out->b.x : r.x;
    out->b.y = out->b.y > r.y ? out->b.y : r.y;
    out->b.z = out->b.z > r.z ? out->b.z : r.z;
    out->b.w = out->b.w > r.w ? out->b.w : r.w;
}

void Caller_9e3220(V3_9e3220* a, V3_9e3220* b, const M44_9e3220* m, B8_9e3220* out)
{
    FUN_009e3220(a, b, m, out);
}

} // namespace f3m_009e3220
}   // namespace f3m_009e3220

// @f3 0x009ea810 (community match, verified in this file)
namespace f3m_009ea810 {
// 0x009ea810: the four-point makeSphere of Havok 5.5.0 (hkpGeometryUtility.cpp), a file-local static function:
// the sphere through four points, its radius widened by radiusEpsilon. It takes the result pointer in esi, pB in
// edi, pC in edx and pD in ecx; the compiler gives a static function that register convention when it sees every
// call to it, so its callers miniSphereRecurseCall and hkpGeometryUtility::createMinBoundingSphere are defined
// here too. makeSphere2 and makeSphere3 stand for the two- and three-point overloads.
// Built on an earlier contributor's draft (chk_e325b9a23e0841628511), which was three instruction pairs short. The
// one change: each squared length is passed as (0, x.lengthSquared3()). The comma expression makes the compiler
// round the scalar to float a second time, as the original does at all three addMul4 calls.
namespace f3m_009ea810 {

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
class hkThreadMemory
{
    public:
        void* allocate( int nbytes, HK_MEMORY_CLASS cl );
        void deallocate(void*);
        static inline hkThreadMemory& __cdecl getInstance();
};
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocate(int numberOfObjects, HK_MEMORY_CLASS cl)
{
    return static_cast<TYPE*>(hkThreadMemory::getInstance().allocate(numberOfObjects*int(sizeof(TYPE)), cl));
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocate(TYPE* ptr)
{
    hkThreadMemory::getInstance().deallocate(static_cast<void *>(ptr));
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
}
class hkVector4
{
    public:
        __forceinline void operator= ( const hkVector4& v );
        __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
        __forceinline void setZero4();
        __forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
        __forceinline void setSub4(const hkVector4& a, const hkVector4& b);
        __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
        __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
        __forceinline void setCross( const hkVector4& a, const hkVector4& b );
        __forceinline hkSimdReal dot3(const hkVector4& a) const;
        __forceinline hkSimdReal length3() const;
        __forceinline hkSimdReal lengthSquared3() const;
        __forceinline hkReal& operator() (int i);
        __forceinline const hkReal& operator() (int i) const;
    private:
        __declspec(align(16)) hkReal x;
        hkReal y;
        hkReal z;
        hkReal w;
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
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
    {
        return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
    }
inline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}
class hkSphere
{
    public:
        __forceinline hkSphere();
        inline hkSphere(const hkVector4& pt, hkReal radius);
        inline hkReal getRadius() const;
        inline const hkVector4& getPosition() const;
    protected:
        hkVector4 m_pos;
};
inline hkSphere::hkSphere(const hkVector4& pt, hkReal radius)
{
    m_pos = pt;
    m_pos(3) = radius;
}
struct hkStridedVertices
{
    const float* m_vertices;
    int m_numVertices;
    int m_striding;
};
class hkpGeometryUtility
{
public:
    static hkSphere __cdecl createMinBoundingSphere( const hkStridedVertices& stridedVertsIn, const hkReal radiusEpsilon = 1e-5f);
};
static hkSphere makeSphere2( const hkVector4& pA, const hkVector4& pB, const hkReal radiusEpsilon )
{
    hkVector4 diamV; diamV.setSub4( pB, pA );
    hkVector4 radiusV; radiusV.setMul4( 0.5f, diamV );
    hkVector4 pr; pr.setAdd4( pA, radiusV );
    hkReal radius = radiusV.length3();
    return hkSphere( pr, radius + radiusEpsilon );
}
hkSphere makeSphere3( const hkVector4& pA, const hkVector4& pB, const hkVector4& pC, const hkReal radiusEpsilon );
// pdb: makeSphere | hkGeometryUtility.obj | tesv_win, call_gap, low
static hkSphere FUN_009ea810( const hkVector4& pA, const hkVector4& pB, const hkVector4& pC, const hkVector4& pD, const hkReal radiusEpsilon )
{
    hkVector4 b; b.setSub4( pB, pA );
    hkVector4 c; c.setSub4( pC, pA );
    hkVector4 d; d.setSub4( pD, pA );
    hkReal det = b(0) * ( c(1) * d(2) - c(2) * d(1) ) - b(1) * ( c(0) * d(2) - c(2) * d(0) ) + b(2) * ( c(0) * d(1) - c(1) * d(0) );
    hkVector4 radiusV; radiusV.setZero4();
    hkVector4 xrs; xrs.setCross( b, c );
    radiusV.addMul4( (0, d.lengthSquared3()), xrs );
    xrs.setCross( d, b );
    radiusV.addMul4( (0, c.lengthSquared3()), xrs );
    xrs.setCross( c, d );
    radiusV.addMul4( (0, b.lengthSquared3()), xrs );
    radiusV.setMul4( 0.5f / det, radiusV );
    hkVector4 pA2; pA2.setAdd4( pA, radiusV );
    const hkReal rad = radiusV.length3();
    return hkSphere( pA2, rad + radiusEpsilon );
}
static hkSphere miniSphereRecurseCall( hkVector4* verts, int numVerts, int supportSize, const hkReal radiusEpsilon )
{
    hkSphere currentSphere;
    switch( supportSize )
    {
        case 0:
        {
            hkVector4 vZero; vZero.setZero4();
            currentSphere = hkSphere( vZero, -1.0f );
        }
        break;
        case 1:
            currentSphere = hkSphere( verts[-1], radiusEpsilon );
            break;
        case 2:
            currentSphere = makeSphere2( verts[-1], verts[-2], radiusEpsilon );
            break;
        case 3:
            currentSphere = makeSphere3( verts[-1], verts[-2], verts[-3], radiusEpsilon );
            break;
        default:
            currentSphere = FUN_009ea810( verts[-1], verts[-2], verts[-3], verts[-4], radiusEpsilon );
            return currentSphere;
    }
    for( int i = 0; i < numVerts; i++ )
    {
        hkVector4 vip; vip.setSub4( verts[i], currentSphere.getPosition() );
        hkReal dist = vip.length3();
        if( currentSphere.getRadius() < dist )
        {
            for( int j = i; j > 0; j-- )
            {
                hkVector4 temp = verts[j];
                verts[j] = verts[j - 1];
                verts[j - 1] = temp;
            }
            currentSphere = miniSphereRecurseCall( verts + 1, i, supportSize + 1, radiusEpsilon );
        }
    }
    return currentSphere;
}
hkSphere hkpGeometryUtility::createMinBoundingSphere( const hkStridedVertices& stridedVertsIn, const hkReal radiusEpsilon )
{
    ;
    hkVector4* array = hkAllocate<hkVector4>( stridedVertsIn.m_numVertices, HK_MEMORY_CLASS_GEOMETRY );
    int floatstriding = stridedVertsIn.m_striding / int(sizeof(float));
    for( int i = 0; i < stridedVertsIn.m_numVertices; i++ )
    {
        array[i](0) = stridedVertsIn.m_vertices[ i * floatstriding ];
        array[i](1) = stridedVertsIn.m_vertices[ i * floatstriding + 1 ];
        array[i](2) = stridedVertsIn.m_vertices[ i * floatstriding + 2 ];
    }
    hkSphere result = miniSphereRecurseCall( array, stridedVertsIn.m_numVertices, 0, radiusEpsilon );
    hkDeallocate<hkVector4>( array );
    return result;
}

}  // namespace f3m_009ea810
}   // namespace f3m_009ea810

// @f3 0x009e3540 (community match, verified in this file)
namespace f3m_009e3540 {
namespace n9e3540
{
    struct Transform;
    struct __declspec(align(16)) Vec4 {
        float x, y, z, w;
        Vec4() {}
        Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
        void SetAll(float value) { x = value; y = value; z = value; w = value; }
        void Min(const Vec4& o) { if (!(x < o.x)) x = o.x; if (!(y < o.y)) y = o.y; if (!(z < o.z)) z = o.z; if (!(w < o.w)) w = o.w; }
        void Max(const Vec4& o) { if (!(x > o.x)) x = o.x; if (!(y > o.y)) y = o.y; if (!(z > o.z)) z = o.z; if (!(w > o.w)) w = o.w; }
        void hkVector4_setTransformedPos(const Transform* transform, const Vec4* vector);
    };
    struct Aabb { Vec4 minimum, maximum; };
    struct Transform { Vec4 rotation[3], position; };
    extern const Transform DAT_010f3370;

    struct __declspec(align(16)) unkBox {
        float v[8];
    };
    struct unkHolder {
        int unk00, unk04, unk08, unk0c;
    };
    struct unkHelper {
        int unk00, unk04, unk08, unk0c;
        int count;
        int base;
        int scale;
        int unk1c;
        int unk20, unk24, unk28, unk2c;
        unsigned char* data;
        int stride;
        unsigned char shortIdx;
    };

    static __declspec(noinline) void FUN_009e3220(Aabb* output, const float* vertex, const Vec4* scale, const Transform* transform)
    {
        Vec4 scaled(vertex[0] * scale->x, vertex[1] * scale->y, vertex[2] * scale->z, 0.0f);
        Vec4 point;
        point.hkVector4_setTransformedPos(transform, &scaled);
        output->minimum.Min(point);
        output->maximum.Max(point);
    }

    template<class Index>
    inline const float* triangleVertex(const unkHelper& part, const Index* indices, int corner)
    {
        return reinterpret_cast<const float*>(reinterpret_cast<const char*>(part.base) + indices[corner] * part.scale);
    }

    // pdb: hkpExtendedMeshShape::calcAabbExtents | hkpExtendedMeshShape.obj | tesv_win, objopen_prop, low
    static __declspec(noinline) void FUN_009e3540(unkBox& box, unkHelper* subpart, unkHolder* factors)
    {
        Aabb* accum = reinterpret_cast<Aabb*>(&box);
        const Vec4* scaleP = reinterpret_cast<const Vec4*>(factors);
        Vec4& lo = accum->minimum;
        Vec4& hi = accum->maximum;
        lo.SetAll(3.40282e38f);
        hi.x = -lo.x;
        hi.y = -lo.y;
        hi.z = -lo.z;
        hi.w = -lo.w;

        for (int tri = 0; tri < subpart->count; ++tri) {
            const float* v0;
            const float* v1;
            const float* v2;
            if (subpart->shortIdx == 1) {
                const unsigned short* idxRow = reinterpret_cast<const unsigned short*>(subpart->data + tri * subpart->stride);
                v0 = triangleVertex(*subpart, idxRow, 0);
                v1 = triangleVertex(*subpart, idxRow, 1);
                v2 = triangleVertex(*subpart, idxRow, 2);
            } else {
                const unsigned int* idxRow = reinterpret_cast<const unsigned int*>(subpart->data + tri * subpart->stride);
                v0 = triangleVertex(*subpart, idxRow, 0);
                v1 = triangleVertex(*subpart, idxRow, 1);
                v2 = triangleVertex(*subpart, idxRow, 2);
            }
            FUN_009e3220(accum, v0, scaleP, &DAT_010f3370);
            FUN_009e3220(accum, v1, scaleP, &DAT_010f3370);
            FUN_009e3220(accum, v2, scaleP, &DAT_010f3370);
        }
    }

    void caller_of_FUN_009e3540(unkBox& box, unkHelper* subpart, unkHolder* factors)
    {
        FUN_009e3540(box, subpart, factors);
    }
}
}   // namespace f3m_009e3540
