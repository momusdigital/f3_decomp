#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_009a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009b5e00 (community match, verified in this file)
namespace f3m_009b5e00 {
namespace f3m_009b5e00 {
struct Vec4_5e00 {
    float x, y, z, w;
    void setZero4() { x = y = z = w = 0.0f; }
};
struct Array_5e00 {
    void* data;
    int size;
    int capacityAndFlags;
    Array_5e00() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
struct Key_5e00 {
    int value;
};
void __cdecl FUN_00a2a560(Array_5e00* arr) throw();
class Base_5e00 {
public:
    virtual ~Base_5e00() throw();
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    Base_5e00(int ud) : userData(ud) { referenceCount = 1; }
};
class FUN_009b5e00 : public Base_5e00 {
public:
    Key_5e00 key;
    Vec4_5e00 a;
    Vec4_5e00 b;
    Array_5e00 arr;
    FUN_009b5e00(int p1, int p2, const Key_5e00& k, int userData);
    virtual ~FUN_009b5e00() throw();
};
}
using namespace f3m_009b5e00;

// pdb: hkpBvTreeStreamAgent::hkpBvTreeStreamAgent | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, mgr
FUN_009b5e00::FUN_009b5e00(int p1, int p2, const Key_5e00& k, int userData) : Base_5e00(userData)
{
    key = k;
    a.setZero4();
    b.setZero4();
    FUN_00a2a560(&arr);
}
}   // namespace f3m_009b5e00

// @f3 0x009a7f50 (community match, verified in this file)
#include <new>
namespace f3m_009a7f50 {
namespace HeightTriangles2051 {
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    void Set(float a,float b,float c,float d){x=a;y=b;z=c;w=d;}
    void Zero(){x=y=z=w=0;}
    void Scale(const Vector4& v){const float* values=(const float*)&v;x*=values[0];y*=values[1];z*=values[2];w*=values[3];}
    Vector4& operator=(const Vector4& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
};
struct RefBase {
    virtual ~RefBase();
    unsigned short memorySize,refs;
    unsigned int userData,type;
    RefBase():refs(1),userData(0),type(4){}
};
struct Triangle:RefBase {
    float radius;unsigned short welding;unsigned char weldingType,extruded;
    unsigned int unk18,unk1C;
    Vector4 a,b,c,extrusion;
    Triangle(float r):radius(r),welding(0),weldingType(6){extrusion.Zero();extruded=0;}
    virtual ~Triangle();
};
struct HeightInterface {
    virtual void Slot00();virtual void Slot04();virtual void Slot08();virtual void Slot0C();
    virtual void Slot10();virtual void Slot14();virtual void Slot18();virtual void Slot1C();
    virtual void Slot20();virtual void Slot24();virtual void Slot28();
    virtual float Height(int,int)const;
};
struct HeightField:HeightInterface {
    unsigned int unk04,unk08,unk0C,unk10,unk14,unk18,unk1C;
    Vector4 scale;
};
struct Root {
    unsigned int unk00,unk04,unk08,unk0C,unk10,unk14;
    const HeightField* heightField;

};
__declspec(noinline) const HeightField* __fastcall FUN_009a7e90(const Root* owner){return owner->heightField;}
struct Container {
    unsigned int unk00,unk04,unk08,unk0C;
    float radius;
    const Triangle* FUN_009a7f50(unsigned int,void*)const;
};
const Triangle* Container::FUN_009a7f50(unsigned int key,void* buffer)const {
    const Root* owner=reinterpret_cast<const Root*>(reinterpret_cast<const char*>(this)-16);
    const HeightField* field=FUN_009a7e90(owner);
    int x=(key>>1)&0x7fff;
    int z=key>>16;
    Triangle* result=new(buffer)Triangle(radius);
    Vector4 a,b,c,d;
    a.Set((float)x+0.0,field->Height(x,z),(float)z+0.0,0.0f);
    a.Scale(field->scale);
    b.Set((float)x+0.0,field->Height(x,z+1),(float)z+1.0,0.0f);
    b.Scale(field->scale);
    c.Set((float)x+1.0,field->Height(x+1,z),(float)z+0.0,0.0f);
    c.Scale(field->scale);
    d.Set((float)x+1.0,field->Height(x+1,z+1),(float)z+1.0,0.0f);
    d.Scale(field->scale);
    if(!(key&1)){result->a=a;result->b=b;result->c=c;}
    else {result->a=d;result->b=c;result->c=b;}
    return result;
}
}
}   // namespace f3m_009a7f50

// @f3 0x009a5fa0 (community match, verified in this file)
namespace f3m_009a5fa0 {
namespace Height2088 {
struct __declspec(align(16)) Quad {
    float x,y,z,w;
    Quad(){}
    void Set(float a,float b,float c,float d=0.0f){x=a;y=b;z=c;w=d;}
    void Mul(const Quad& a){x*=a.x;y*=a.y;z*=a.z;w*=a.w;}
    Quad& operator=(const Quad& a){x=a.x;y=a.y;z=a.z;w=a.w;return *this;}
    void SetMul(float r,const Quad& a){x=r*a.x;y=r*a.y;z=r*a.z;w=r*a.w;}
};
struct Info {Quad scale;int xResolution,zResolution;float minHeight,maxHeight;unsigned char projection;};
struct Shape {
    virtual ~Shape(){};virtual void v04();
    unsigned short memoryFlags;short references;unsigned int userData,type;
    Shape(unsigned int t):references(1),userData(0),type(t){}
};
__declspec(nothrow) float __cdecl FUN_00a09ce0();
struct Height:Shape {
    int xResolution,zResolution;float center;unsigned char projection,unk1D,unk1E,unk1F;
    Quad scale,inverse,offset,extents;
    virtual ~Height();Height(const Info&);
};
// pdb: hkBSHeightFieldShape::hkBSHeightFieldShape | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkpSampledHeightFieldShape::hkpSampledHeightFieldShape)
// pdb params: arInfo
Height::Height(const Info& ci):Shape(14){
    xResolution=ci.xResolution;zResolution=ci.zResolution;projection=ci.projection;
    extents.Set(ci.xResolution-1.0f,ci.maxHeight-ci.minHeight,ci.zResolution-1.0f);
    extents.Mul(ci.scale);
    if(ci.minHeight>ci.maxHeight){center=-1.0f;extents.y=-1.0f;}
    else center=(ci.maxHeight+ci.minHeight)*0.5*ci.scale.y;
    scale=ci.scale;
    inverse.Set(1.0f/ci.scale.x,1.0f/ci.scale.y,1.0f/ci.scale.z);
    Quad corrected;corrected.SetMul(FUN_00a09ce0(),scale);corrected.y=0.0f;offset=corrected;
}
}
}   // namespace f3m_009a5fa0

// @f3 0x009a47c0 (community match, verified in this file)
namespace f3m_009a47c0 {
namespace f3_009a47c0 {
struct __declspec(align(16)) Vec47 {
    float x;
    float y;
    float z;
    float w;
};

struct Plane47 {
    Vec47 normal;
    Vec47 point;
};

struct hkBool47 {
    char m_bool;
    hkBool47(bool value) { m_bool = value ? 1 : 0; }
};

// pdb: hkSimplexSolverSolveTest1d | hkpSimplexSolver.obj | tesv_win, call_dedup, low
static __declspec(noinline) hkBool47 FUN_009a47c0(const Plane47& plane, const Vec47& velocity)
{
    Vec47 relative;
    relative.x = velocity.x - plane.point.x;
    relative.y = velocity.y - plane.point.y;
    relative.z = velocity.z - plane.point.z;
    float planeVelocity = plane.normal.x * relative.x + plane.normal.y * relative.y + plane.normal.z * relative.z;
    if (planeVelocity >= -0.001f)
        return false;
    return true;
}

bool UsePlane47(const Plane47* plane, const Vec47* velocity)
{
    hkBool47 used = FUN_009a47c0(*plane, *velocity);
    return used.m_bool != 0;
}
}
}   // namespace f3m_009a47c0

// @f3 0x009a79b0 (community match, verified in this file)
namespace f3m_009a79b0 {
namespace f3m_009a79b0 {
struct __declspec(align(16)) Vec {
    float x, y, z, w;
    __forceinline void SetRotated(const struct Rot& r, const Vec& b);
};
struct Rot;
struct Input {
    Vec dir;
    Vec other;
};
struct Rot {
    Vec c0, c1, c2;
};
__forceinline void Vec::SetRotated(const Rot& r, const Vec& b) {
    float bx = b.x;
    float by = b.y;
    float bz = b.z;
    x = r.c1.x * by + r.c0.x * bx + r.c2.x * bz;
    y = r.c1.y * by + r.c0.y * bx + r.c2.y * bz;
    z = r.c1.z * by + r.c0.z * bx + r.c2.z * bz;
    w = 0.0f;
}
struct Body {
    int unk00;
    int unk04;
    Rot* rot;
};
struct Target {
    virtual void vf00(Body* body, Input* in);
};
struct Wrapper {
    int unk00;
    int unk04;
    Target* target;
    void RotateNormalHitCollector_addRayHit(Body* body, Input* in);
};
// pdb: `anonymous namespace'::RotateNormalHitCollector::addRayHit | hkpSampledHeightFieldShape.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Wrapper::RotateNormalHitCollector_addRayHit(Body* body, Input* in) {
    Input local = *in;
    local.dir.SetRotated(*body->rot, in->dir);
    target->vf00(body, &local);
}
}
}   // namespace f3m_009a79b0

// @f3 0x009a1000 (community match, verified in this file)
#include <windows.h>
extern unsigned long DAT_010f3170;
extern float DAT_0104da48;
extern float DAT_0104e148;
namespace f3m_009a1000 {

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

namespace N9a1000 {


struct hkThreadMemory
{
    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    void deallocateChunk(void* p, int nbytes, int cl) throw();
};

template <class T>
__forceinline void hkDeallocateChunk(T* p, int n, int cl)
{
    hkThreadMemory::getInstance().deallocateChunk(p, n * sizeof(T), cl);
}

void __cdecl hkArray_reserve(void* arr, int n, int sizeElem) throw();

template <class T>
struct hkArrayBase
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArrayBase() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void reserve(int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArray_reserve(this, newSize, sizeof(T));
        }
    }
    __declspec(noalias) void swap(hkArrayBase& other) throw();
};

template <class T>
struct hkArray : hkArrayBase<T>
{
    __forceinline ~hkArray()
    {
        if ((this->m_capacityAndFlags & 0x80000000) == 0)
        {
            int n = this->getCapacity();
            hkThreadMemory::getInstance().deallocateChunk(this->m_data, n * sizeof(T), 0x17);
        }
    }
};

template <class T>
__forceinline void constructWithArray(T* dst, int n, const T* src)
{
    for (int i = 0; i < n; ++i)
        new (dst + i) T(src[i]);
}

template <class T>
struct hkObjectArray
{
    hkArray<T> m_array;

    __forceinline void reserve(int n, int size)
    {
        if (n > m_array.getCapacity())
        {
            int cap2 = 2 * m_array.getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayBase<T> tmp;
            tmp.swap(m_array);
            m_array.reserve(newSize);
            constructWithArray(m_array.m_data, size, tmp.m_data);
            m_array.m_size = size;
            int c = tmp.m_capacityAndFlags;
            if ((c & 0x80000000) == 0)
                hkThreadMemory::getInstance().deallocateChunk(tmp.m_data, (c & 0x3fffffff) * sizeof(T), 0x17);
        }
    }
    __forceinline void pushBack(const T& e)
    {
        int size = m_array.m_size;
        if (size == m_array.getCapacity())
            reserve(size ? 2 * size : 1, size);
        T* p = m_array.m_data + size;
        m_array.m_size = size + 1;
        new (p) T(e);
    }
};

} // namespace N9a1000


struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setAll(float f)
    {
        x = f;
        y = f;
        z = f;
        w = f;
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
};

class hkBool
{
  public:
    char m_bool;
    hkBool() {}
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
    hkBool isValid() const throw();
    __forceinline void includePoint(const hkVector4& p)
    {
        m_min.setMin4(m_min, p);
        m_max.setMax4(m_max, p);
    }
};

struct BoxEntry
{
    hkVector4 m_kPoint;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
};

struct BoxSet
{
    int unk00, unk04, unk08, unk0c;
    BoxEntry* m_boxes;
    int unk14, unk18;
    int* m_flags;
    const hkVector4& hkaPose_calculateBoneModelSpace(int idx) throw();
    __forceinline const hkVector4& GetBoxVector(int idx)
    {
        if (!(m_flags[idx] & 2))
            return m_boxes[idx].m_kPoint;
        return hkaPose_calculateBoneModelSpace(idx);
    }
};

struct IndexInfo
{
    int unk00;
    short* m_idx;
};

struct PairRecord
{
    short m_kPointA;
    short m_kPointB;
    int unk04, unk08, unk0c;
    hkVector4 m_p0;
    hkVector4 m_p1;
    PairRecord() throw();
};

struct AabbSink
{
    void hkpAabbPhantom_setAabb(const hkAabb& aabb) throw();
};

struct PairTester
{
    virtual void v00();
    virtual hkBool test(AabbSink* sink, const hkVector4& a, const hkVector4& b, hkVector4& p0, hkVector4& p1) throw();
};

void __cdecl CollectReachableNodes(IndexInfo* info, short idx, N9a1000::hkArray<short>* list) throw();

struct PairFinder
{
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    IndexInfo* m_info;
    PairTester* m_tester;
    AabbSink* m_sink;
    int m_uiItemCount;
    N9a1000::hkArray<int> m_aiIndexedValues;
    bool m_flag;
    hkBool FUN_009a1000(BoxSet* boxes, N9a1000::hkObjectArray<PairRecord>* out);
};

// pdb: hkaDetectRagdollPenetration::detectPenetration | hkaDetectRagdollPenetration.obj | tesv_win, objrun, medium
hkBool PairFinder::FUN_009a1000(BoxSet* boxes, N9a1000::hkObjectArray<PairRecord>* out)
{
    out->m_array.m_size = 0;
    if (!m_flag)
    {
        {
            hkAabb aabb;
            aabb.m_min.setAll(DAT_0104da48);
            aabb.m_max.setAll(DAT_0104e148);
            for (short i = 1; i < m_uiItemCount; i++)
            {
                short idx = m_info->m_idx[i];
                if (m_aiIndexedValues.m_data[idx])
                {
                    hkVector4 a;
                    a = boxes->GetBoxVector(idx);
                    hkVector4 b;
                    b = boxes->GetBoxVector(i);
                    aabb.includePoint(a);
                    aabb.includePoint(b);
                }
            }
            if (aabb.isValid())
                m_sink->hkpAabbPhantom_setAabb(aabb);
        }
        hkVector4 a, b, p0, p1;
        for (short i = 1; i < m_uiItemCount; i++)
        {
            short idx = m_info->m_idx[i];
            if (m_aiIndexedValues.m_data[idx])
            {
                a = boxes->GetBoxVector(idx);
                b = boxes->GetBoxVector(i);
                hkBool res = m_tester->test(m_sink, a, b, p0, p1);
                if (res)
                {
                    PairRecord rec;
                    rec.m_p0 = p0;
                    rec.m_kPointA = idx;
                    rec.m_kPointB = i;
                    rec.m_p1 = p1;
                    out->pushBack(rec);
                }
            }
        }
    }
    for (int k = 0; k < m_aiIndexedValues.m_size; k++)
        m_aiIndexedValues.m_data[k] = 0;
    if (out->m_array.m_size == 0)
    {
        m_flag = true;
        return false;
    }
    for (int j = 0; j < out->m_array.m_size; j++)
    {
        short c = out->m_array.m_data[j].m_kPointA;
        if (m_aiIndexedValues.m_data[c] != 2)
            m_aiIndexedValues.m_data[c] = 1;
        N9a1000::hkArray<short> list;
        CollectReachableNodes(m_info, c, &list);
        for (int k = 0; k < list.m_size; k++)
        {
            short p = list.m_data[k];
            if (m_aiIndexedValues.m_data[p] != 2)
                m_aiIndexedValues.m_data[p] = 2;
        }
    }
    return true;
}
}   // namespace f3m_009a1000

// @f3 0x009b7580 (community match, verified in this file)
namespace f3m_009b7580 {
namespace W06_2354 {
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    void NegateXYZ() {x=-x;y=-y;z=-z;}
    void SetAll(float v) {x=v;y=v;z=v;w=v;}
    void AddScaled(const Vec4& scale,const Vec4& b) {
        x += scale.x*b.x; y += scale.y*b.y; z += scale.z*b.z; w += scale.w*b.w;
    }
    void SetNegated3(const Vec4& b) {x=-b.x;y=-b.y;z=-b.z;w=b.w;}
};
struct Vertex {Vec4 pointA,pointB; int unknown20,unknown24,unknown28,unknown2c;};
struct Nibbles {unsigned char low:4;unsigned char high:4;};
struct Simplex {
    Vertex* cursor;
    int unknown04,unknown08,unknown0c;
    Vertex vertices[256];
    int unknown3010,unknown3014,unknown3018,unknown301c;
    Vec4 normal;
    float distance;
    int unknown3034,unknown3038,unknown303c;
    unsigned short ids[4];
    unsigned char dimensionA,dimensionB;
    Nibbles nibbles;
};
struct AgentBase {void FUN_009d1460(int,int,int,Simplex*);};
struct Agent:AgentBase {void FUN_009b7580(int,int,int,Simplex*);};
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::processCollision | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Agent::FUN_009b7580(int a,int b,int c,Simplex* out) {
    Vertex* vertex=out->cursor;
    float oldDistance=out->distance;
    AgentBase::FUN_009d1460(b,a,c,out);
    for(;vertex<out->cursor;++vertex) {
        Vec4 multiplier; multiplier.SetAll(vertex->pointB.w);
        vertex->pointA.AddScaled(multiplier,vertex->pointB);
        vertex->pointB.SetNegated3(vertex->pointB);
    }
    if(oldDistance!=out->distance) {
        out->normal.NegateXYZ();
        unsigned char low=out->nibbles.low;
        out->nibbles.low=out->nibbles.high;
        out->nibbles.high=low;
        unsigned char dim=out->dimensionA;
        out->dimensionA=out->dimensionB;
        out->dimensionB=dim;
        int last=out->dimensionA+out->dimensionB-1;
        unsigned short id=out->ids[0];
        out->ids[0]=out->ids[last];out->ids[last]=id;
        if((out->dimensionA & out->dimensionB)==2) {
            id=out->ids[1];out->ids[1]=out->ids[2];out->ids[2]=id;
        }
    }
}
}
}   // namespace f3m_009b7580

// @f3 0x009beb30 (community match, verified in this file)
namespace f3m_009beb30 {
extern "C" void _ReadWriteBarrier();
struct __declspec(align(16)) Vector2358
{
    float x, y, z, w;
    __forceinline void BroadcastW(const Vector2358& other)
    {
        float value = other.w; x = value; y = value; z = value; w = value;
    }
    __forceinline void NegateXYZ(const Vector2358& other)
    {
        x = -other.x; y = -other.y; z = -other.z;
    }
    __forceinline void AddScaled(const Vector2358& factor, const Vector2358& other)
    {
        x += factor.x * other.x;
        y += factor.y * other.y;
        z += factor.z * other.z;
        w += factor.w * other.w;
    }
    __forceinline void Negate3(const Vector2358& other)
    {
        x = -other.x;
        y = -other.y;
        z = -other.z;
        w = 1.0f * other.w;
    }
};
struct Vertex2358
{
    Vector2358 pointA, pointB;
    int unk20, unk24, unk28, unk2c;
};
struct Nibbles2358
{
    unsigned char low : 4;
    unsigned char high : 4;
};
struct Simplex2358
{
    Vertex2358* end;
    int unk04, unk08, unk0c;
    Vertex2358 vertices[256];
    int unk3010, unk3014, unk3018, unk301c;
    Vector2358 normal;
    float distance;
    int unk3034, unk3038, unk303c;
    unsigned short ids[4];
    unsigned char dimensionA, dimensionB;
    Nibbles2358 nibbles;
};
struct AgentBase2358
{
    void FUN_009bdcf0(int a, int b, int context, Simplex2358* simplex);
};
struct Agent2358 : AgentBase2358
{
    void FUN_009beb30(int a, int b, int context, Simplex2358* simplex);
};

// pdb: hkpSymmetricAgentLinearCast<hkpConvexListAgent>::processCollision | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix, high
// pdb params: bodyA, bodyB, input, result
void Agent2358::FUN_009beb30(int a, int b, int context, Simplex2358* simplex)
{
    Vertex2358* vertex = simplex->end;
    float oldDistance = simplex->distance;
    AgentBase2358::FUN_009bdcf0(b, a, context, simplex);
    for (; vertex < simplex->end; ++vertex)
    {
        Vector2358 factor;
        factor.BroadcastW(vertex->pointB);
        vertex->pointA.AddScaled(factor, vertex->pointB);
        vertex->pointB.Negate3(vertex->pointB);
    }
    if (oldDistance != simplex->distance)
    {
        Vector2358 normal;
        normal.x = -simplex->normal.x; simplex->normal.x = normal.x;
        normal.y = -simplex->normal.y; simplex->normal.y = normal.y;
        normal.z = -simplex->normal.z; simplex->normal.z = normal.z;
        _ReadWriteBarrier();
        unsigned char low = simplex->nibbles.low;
        simplex->nibbles.low = simplex->nibbles.high;
        simplex->nibbles.high = low;
        unsigned char dimension = simplex->dimensionA;
        simplex->dimensionA = simplex->dimensionB;
        simplex->dimensionB = dimension;
        int last = simplex->dimensionA + simplex->dimensionB - 1;
        unsigned short id = simplex->ids[0];
        simplex->ids[0] = simplex->ids[last];
        simplex->ids[last] = id;
        if ((simplex->dimensionA & simplex->dimensionB) == 2)
        {
            id = simplex->ids[1];
            simplex->ids[1] = simplex->ids[2];
            simplex->ids[2] = id;
        }
    }
}
}   // namespace f3m_009beb30

// @f3 0x009bada0 (community match, verified in this file)
namespace f3m_009bada0 {
struct ScratchBlock;
struct ScratchOwner { void AddEntry(ScratchBlock* block, int a, int b); };
void FUN_00da6fd0(void* p);

// pdb: hkpCollectionAgent3::registerAgent3 | hkpCollectionAgent3.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void FUN_009bada0(ScratchOwner* owner)
{
    __declspec(align(16)) struct
    {
        int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
        int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
        char unk30; char unk31; char unk32; char unk33;
        int unk34; int unk38; int unk3C;
    } f;
    f.unk30 = 0;
    f.unk31 = 0;
    f.unk32 = 0;
    f.unk18 = 0;
    f.unk1C = 0;
    f.unk20 = 0;
    f.unk24 = 0;
    f.unk28 = 0;
    FUN_00da6fd0(&f.unk00);
    owner->AddEntry((ScratchBlock*)&f.unk00, -1, 10);
}
}   // namespace f3m_009bada0

// @f3 0x009bc4d0 (community match, verified in this file)
extern float FUN_00de6e60;
namespace f3m_009bc4d0 {
struct __declspec(align(16)) F3Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct F3CastInput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    F3Vec4 m_dir;
    F3Vec4 m_extra;
};

struct F3CollectorBase {
    virtual void addHit();
    float m_earlyOutDistance;
    F3CollectorBase() : m_earlyOutDistance(FUN_00de6e60) {}
};
struct F3FlipCollector : F3CollectorBase {
    virtual void addHit();
    F3Vec4 m_vec;
    int m_body;
    F3FlipCollector(const F3Vec4& dir, int body) : m_vec(dir), m_body(body) {}
};

void __cdecl hkpHeightFieldAgent_staticLinearCast(void* a1, void* a2, void* a3, void* a4, void* a5);

// pdb: hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticLinearCast | hkpHeightFieldAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void __cdecl FUN_009bc4d0(void* a1, void* a2, F3CastInput* input, int a4, int a5)
{
    F3CastInput copiedInput;

    copiedInput = *input;
    copiedInput.m_dir.x = -input->m_dir.x;
    copiedInput.m_dir.y = -input->m_dir.y;
    copiedInput.m_dir.z = -input->m_dir.z;
    copiedInput.m_dir.w = -input->m_dir.w;

    F3FlipCollector firstCollector(input->m_dir, a4);

    if (a5 != 0)
    {
        F3FlipCollector secondCollector(input->m_dir, a5);
        hkpHeightFieldAgent_staticLinearCast(a2, a1, &copiedInput, &firstCollector, &secondCollector);
    }
    else
    {
        hkpHeightFieldAgent_staticLinearCast(a2, a1, &copiedInput, &firstCollector, 0);
    }
}
}   // namespace f3m_009bc4d0

// @f3 0x009b7110 (community match, verified in this file)
extern char F3SymAgentFlipCastVt;
namespace f3m_009b7110 {
// Wrapper around hkpBvTreeAgent_staticLinearCast (void(void*,void*,void*,void*,void*)): copies a 112-byte cast input,
// conjugate-flips the 4 floats at +0x50 of the copy, and builds two 0x30-byte "flip cast collector"
// objects (pointer at +0, HK_REAL_MAX at +4, the same 4 floats at +0x10, a body at +0x20).

struct F3Vec4
{
    float x;
    float y;
    float z;
    float w;
};

// Stand-in for the collector's vtable/type object (0xe7e9c8) the original stores into the first field;
// the address is bound from the original instruction by the checker.

FNV_ALIGN(16) struct F3FlipCollector
{
    void* m_unk00;
    float m_earlyOutDistance;
    int m_unk08;
    int m_unk0c;
    F3Vec4 m_vec;
    int m_body;
};

struct F3CastInput
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    F3Vec4 m_dir;   // 0x50
    int unk60; int unk64; int unk68; int unk6c;
};

void hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);

// pdb: hkpSymmetricAgentLinearCast<class hkpBvTreeAgent>::staticLinearCast | hkpBvTreeStreamAgent.obj | tesv_win, caller_sim, low
void FUN_009b7110(void* a1, void* a2, F3CastInput* p, int a4, int a5)
{
    F3CastInput in = *p;
    in.m_dir.x = -p->m_dir.x;
    in.m_dir.y = -p->m_dir.y;
    in.m_dir.z = -p->m_dir.z;
    in.m_dir.w = -p->m_dir.w;

    F3FlipCollector b;
    F3FlipCollector a;
    a.m_earlyOutDistance = 3.40282e38f;
    a.m_unk00 = &F3SymAgentFlipCastVt;
    a.m_vec = p->m_dir;
    a.m_body = a4;

    if (a5)
    {
        b.m_earlyOutDistance = 3.40282e38f;
        b.m_unk00 = &F3SymAgentFlipCastVt;
        b.m_vec = p->m_dir;
        b.m_body = a5;
        hkpBvTreeAgent_staticLinearCast(a2, a1, &in, &a, &b);
    }
    else
    {
        hkpBvTreeAgent_staticLinearCast(a2, a1, &in, &a, 0);
    }
}
}   // namespace f3m_009b7110

// @f3 0x009bd090 (community match, verified in this file)
namespace f3m_009bd090 {
struct __declspec(align(16)) HK_Stage_t { union { int i[16]; float f[16]; }; HK_Stage_t(const int* src) { for (int k = 0; k < 16; k++) i[k] = src[k]; } };
class HK_ASSERT_OBJECT_SIZE_OK_FUNC_t {
public:
  int m_00;
  int m_04;
  int m_08;
  int m_0c;
  float m_10;
  float m_14;
  float m_18;
  float m_1c;
  float m_20;
  float m_24;
  float m_28;
  float m_2c;
  float m_30;
  float m_34;
  float m_38;
  float m_3c;
  float m_40;
  float m_44;
  float m_48;
  float m_4c;
  HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& FUN_009bd090(const HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& a);
};
// pdb: hkpListShape::hkpListShape | hkpListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkpAgent3Input::hkpAgent3Input)
// pdb params: shapeArray, numShapes, ref
HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& HK_ASSERT_OBJECT_SIZE_OK_FUNC_t::FUN_009bd090(const HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& a)
{
  m_00 = a.m_00;
  m_04 = a.m_04;
  m_08 = a.m_08;
  m_0c = a.m_0c;
  HK_Stage_t s((const int*)&a.m_10);
  m_10 = s.f[0];
  m_14 = s.f[1];
  m_18 = s.f[2];
  m_1c = s.f[3];
  m_20 = s.f[4];
  m_24 = s.f[5];
  m_28 = s.f[6];
  m_2c = s.f[7];
  m_30 = s.f[8];
  m_34 = s.f[9];
  m_38 = s.f[10];
  m_3c = s.f[11];
  m_40 = s.f[12];
  m_44 = s.f[13];
  m_48 = s.f[14];
  m_4c = s.f[15];
  return *this;
}
}   // namespace f3m_009bd090

// @f3 0x009be8a0 (community match, verified in this file)
namespace f3m_009be8a0 {
// pdb: hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticLinearCast | hkpConvexListAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector, startCollector
namespace Task9be8{struct Vector{__declspec(align(16)) float x;float y,z,w;};struct Transform{Vector v00,v10,v20,v30,v40,v50,v60;};extern float DAT_00de6e60;extern int DAT_00e7e9c8;struct Query{void*methods;float tolerance;int unk08;int unk0c;Vector position;void*target;int unk24;int unk28;int unk2c;Query(const Vector&v,void*p):methods(&DAT_00e7e9c8),tolerance(DAT_00de6e60),position(v),target(p){}};void __cdecl hkpConvexListAgent_staticLinearCast(void*,void*,Transform*,Query*,Query*);void __cdecl FUN_009be8a0(void*a,void*b,const Transform*source,void*first,void*second){Transform inverse=*source;inverse.v50.x=-source->v50.x;inverse.v50.y=-source->v50.y;inverse.v50.z=-source->v50.z;inverse.v50.w=-source->v50.w;Query left(source->v50,first);if(second){Query right(source->v50,second);hkpConvexListAgent_staticLinearCast(b,a,&inverse,&left,&right);}else hkpConvexListAgent_staticLinearCast(b,a,&inverse,&left,0);}}
}   // namespace f3m_009be8a0

// @f3 0x009be680 (community match, verified in this file)
extern float DAT_00de6e60;extern int DAT_00e7e9c8;
namespace f3m_009be680 {
namespace Forward409{
struct Vec{float x,y,z,w;};struct __declspec(align(16)) Input{Vec a,b,c,d,e,vector,g;};
struct __declspec(align(16)) Shape{void*vtable;float radius;unsigned int unk08,unk0c;Vec vector;void*object;__forceinline Shape(const Vec&v,void*o){vtable=&DAT_00e7e9c8;radius=DAT_00de6e60;vector=v;object=o;}};
void __cdecl FUN_009d1840(void*,void*,Input*,Shape*,Shape*);
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast | hkpConvexListAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void __cdecl FUN_009be680(void*a,void*b,Input*input,void*object,void*optional){Input copy=*input;copy.vector.x=-input->vector.x;copy.vector.y=-input->vector.y;copy.vector.z=-input->vector.z;copy.vector.w=-input->vector.w;Shape first(input->vector,object);if(optional){Shape second(input->vector,optional);FUN_009d1840(b,a,&copy,&first,&second);}else FUN_009d1840(b,a,&copy,&first,0);}
}





}   // namespace f3m_009be680

// @f3 0x009baa10 (community match, verified in this file)
extern float DAT_00de6e60;
namespace f3m_009baa10 {
namespace task2840 {
struct __declspec(align(16)) V { float x, y, z, w; };
struct Body {
    V a, b, c, d, e;
    V v;
    V g;
};
struct Collector {
    virtual void v00();
    float tol;
    Collector() : tol(DAT_00de6e60) {}
};
struct Filter : Collector {
    V v;
    void* p;
    Filter(const V& a, void* b) : v(a), p(b) {}
};
}
struct Agent2840 {
    void FUN_009ba6b0(int a, int b, const task2840::Body* body, task2840::Filter* f1, task2840::Filter* f2);
    void FUN_009baa10(int a, int b, const task2840::Body* body, void* p1, void* p2);
};
// pdb: hkpSymmetricAgent<hkpMoppAgent>::linearCast | hkpMoppAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void Agent2840::FUN_009baa10(int a, int b, const task2840::Body* body, void* p1, void* p2)
{
    task2840::Body c = *body;
    c.v.x = -body->v.x;
    c.v.y = -body->v.y;
    c.v.z = -body->v.z;
    c.v.w = -body->v.w;
    task2840::Filter f1(body->v, p1);
    if (p2) {
        task2840::Filter f2(body->v, p2);
        FUN_009ba6b0(b, a, &c, &f1, &f2);
    } else {
        FUN_009ba6b0(b, a, &c, &f1, 0);
    }
}
}   // namespace f3m_009baa10

// @f3 0x009b76e0 (community match, verified in this file)
extern float DAT_00de6e60;
namespace f3m_009b76e0 {
namespace n9b76e0 {
struct __declspec(align(16)) V { float x, y, z, w; };
struct Body {
    V a, b, c, d, e;
    V v;
    V g;
};
struct Collector {
    virtual void v00();
    float tol;
    Collector() : tol(DAT_00de6e60) {}
};
struct Filter : Collector {
    V v;
    void* p;
    Filter(const V& a, void* b) : v(a), p(b) {}
};
}
struct C9b76e0 {
    void FUN_009b5c80(int a, int b, const n9b76e0::Body* body, n9b76e0::Filter* f1, n9b76e0::Filter* f2);
    void FUN_009b76e0(int a, int b, const n9b76e0::Body* body, void* p1, void* p2);
};
// pdb: hkpSymmetricAgent<hkpBvTreeStreamAgent>::linearCast | hkpBvTreeStreamAgent.obj | fnv360_0721_beta, vtable, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void C9b76e0::FUN_009b76e0(int a, int b, const n9b76e0::Body* body, void* p1, void* p2)
{
    n9b76e0::Body c = *body;
    c.v.x = -body->v.x;
    c.v.y = -body->v.y;
    c.v.z = -body->v.z;
    c.v.w = -body->v.w;
    n9b76e0::Filter f1(body->v, p1);
    if (p2) {
        n9b76e0::Filter f2(body->v, p2);
        FUN_009b5c80(b, a, &c, &f1, &f2);
    } else {
        FUN_009b5c80(b, a, &c, &f1, 0);
    }
}
}   // namespace f3m_009b76e0

// @f3 0x009bc5d0 (community match, verified in this file)
namespace f3m_009bc5d0 {
namespace Flip9bc5d0 {
struct __declspec(align(16)) Scalar { float value; Scalar(float v):value(v){} operator float() const { return value; } };
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    void AddMul4(const float& r,const Vec4& v) { x+=r*v.x; y+=r*v.y; z+=r*v.z; w+=r*v.w; }
    void Neg3() { x=-x;y=-y;z=-z; }
    void SetNeg3(const Vec4& v) { x=-v.x;y=-v.y;z=-v.z;w=v.w; }
    Scalar GetW() const {return Scalar(w);}
};
struct Contact {
    Vec4 position;
    Vec4 normal;
    unsigned properties20,properties24,properties28,properties2c;
    void Flip(){position.AddMul4(normal.GetW(),normal);normal.SetNeg3(normal);}
};
struct Output {
    Contact* end;
    unsigned field04,field08,field0c,field10,field14,field18,field1c;
    Contact contacts[256];
    Vec4 axis;
    float distance,field3034,field3038,field303c;
    unsigned short keys[4];
    unsigned char countA,countB;
    struct {unsigned char low:4; unsigned char high:4;} flags;
};
struct S009bc5d0_Agent { void hkpHeightFieldAgent_processCollision(void*,void*,void*,Output*); void FUN_009bc5d0(void* first,void* second,void* context,Output* output); };
// pdb: hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::processCollision | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void S009bc5d0_Agent::FUN_009bc5d0(void* first,void* second,void* context,Output* output) {
    Contact* begin=output->end;
    float oldDistance=output->distance;
    hkpHeightFieldAgent_processCollision(second,first,context,output);
    for(;begin<output->end;++begin) {
        begin->Flip();
    }
    if(oldDistance!=output->distance) {
        output->axis.Neg3();
        unsigned char high=output->flags.high;
        unsigned char low=output->flags.low;
        output->flags.low=high;
        output->flags.high=low;
        unsigned char temp=output->countA;
        output->countA=output->countB;
        output->countB=temp;
        unsigned last=output->countB+output->countA-1;
        unsigned short key=output->keys[0];
        output->keys[0]=output->keys[last];
        output->keys[last]=key;
        if((output->countA&output->countB)==2) {
            key=output->keys[1];output->keys[1]=output->keys[2];output->keys[2]=key;
        }
    }
}
}
}   // namespace f3m_009bc5d0

// @f3 0x009ba7e0 (community match, verified in this file)
namespace f3m_009ba7e0 {
namespace S009ba7e0 {

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;

    void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
};

struct hkTransform
{
    hkVector4 col0;
    hkVector4 col1;
    hkVector4 col2;
    hkVector4 translation;
    void FUN_00925300(const hkTransform* a, const hkTransform* b);
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

struct hkShape
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void getAabb(const hkTransform& t, float tolerance, hkAabb& out);
};

struct S009ba7e0_Body
{
    hkShape* shape;
    unsigned int unk04;
    const hkTransform* transform;
};

struct S009ba7e0_Input
{
    float unk00;
    float tolerance;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    hkVector4 vec50;
};

struct S009ba7e0_Rot : hkVector4
{
    void FUN_00477880(const hkTransform* t, const hkVector4* v);
};

// pdb: hkpBvTreeAgent::calcAabbLinearCast | hkpBvTreeAgent.obj | fnv360_0822_retail, call_seq, medium
// pdb params: bodyA, bodyB, input, aabbOut
void __cdecl FUN_009ba7e0(const S009ba7e0_Body* a, const S009ba7e0_Body* b, const S009ba7e0_Input* input, hkAabb* out)
{
    hkTransform composed;
    composed.FUN_00925300(b->transform, a->transform);
    a->shape->getAabb(composed, input->tolerance, *out);

    S009ba7e0_Rot dir;
    dir.FUN_00477880(b->transform, &input->vec50);

    hkVector4 neg;
    neg.x = 0.0f < dir.x ? 0.0f : dir.x;
    neg.y = 0.0f < dir.y ? 0.0f : dir.y;
    neg.z = 0.0f < dir.z ? 0.0f : dir.z;
    neg.w = 0.0f < dir.w ? 0.0f : dir.w;
    hkVector4 pos;
    pos.x = 0.0f > dir.x ? 0.0f : dir.x;
    pos.y = 0.0f > dir.y ? 0.0f : dir.y;
    pos.z = 0.0f > dir.z ? 0.0f : dir.z;
    pos.w = 0.0f > dir.w ? 0.0f : dir.w;
    hkAabb& aabb = *out;
    aabb.m_min.add4(neg);
    aabb.m_max.add4(pos);
}

}
}   // namespace f3m_009ba7e0

// @f3 0x009a1cc0 (community match, verified in this file)
namespace f3m_009a1cc0 {
__declspec(align(16)) struct hkVector4_9a1cc0
{
    float x, y, z, w;
    float dot3(const hkVector4_9a1cc0& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    void setMul4(float r, const hkVector4_9a1cc0& a)
    {
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    void sub4(const hkVector4_9a1cc0& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    void add4(const hkVector4_9a1cc0& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    void subMul4(float r, const hkVector4_9a1cc0& a)
    {
        hkVector4_9a1cc0 tmp;
        tmp.setMul4(r, a);
        sub4(tmp);
    }
};
struct hkContactPoint_9a1cc0
{
    hkVector4_9a1cc0 m_position;
    hkVector4_9a1cc0 m_separatingNormal;
};
struct hkpMovingSurfaceModifier_9a1cc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4_9a1cc0 m_velocity;
    void FUN_009a1cc0(const hkContactPoint_9a1cc0& cp, void* a, void* b, void* c, hkVector4_9a1cc0& velOut);
};
// pdb: hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseBeginCallback | hkpConstraintAtom.obj | tesv_win, objrun_sim, low
void hkpMovingSurfaceModifier_9a1cc0::FUN_009a1cc0(const hkContactPoint_9a1cc0& cp, void* a, void* b, void* c, hkVector4_9a1cc0& velOut)
{
    hkVector4_9a1cc0 vel = m_velocity;
    vel.subMul4(vel.dot3(cp.m_separatingNormal), vel);
    velOut.add4(vel);
}
}   // namespace f3m_009a1cc0

// @f3 0x009a1f90 (community match, verified in this file)
namespace f3m_009a1f90 {
namespace f3m_009a1f90 {

struct __declspec(align(16)) hkVector4 {
    float x;
    float y;
    float z;
    float w;
    void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    float dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    void setInt24W(int value) { reinterpret_cast<unsigned int*>(this)[3] = (unsigned int)value | 0x3f000000; }
};

struct LineSegment {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_start;
    hkVector4 m_end;
    void FUN_009a1f90(const hkVector4& direction, hkVector4& supportOut);
};

void LineSegment::FUN_009a1f90(const hkVector4& direction, hkVector4& supportOut)
{
    hkVector4 diff;
    diff.setSub4(m_end, m_start);
    float d = direction.dot3(diff);
    int index;
    if (d < 0.0f) {
        supportOut = m_start;
        index = 0;
    } else {
        supportOut = m_end;
        index = 0x10;
    }
    supportOut.setInt24W(index);
}

}
}   // namespace f3m_009a1f90

// @f3 0x009bbd50 (community match, verified in this file)
namespace f3m_009bbd50 {
namespace f3m_009bbd50 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    void setAddMul4(float r, const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x * r;
        y = a.y + b.y * r;
        z = a.z + b.z * r;
        w = a.w + b.w * r;
    }
    void addMul4(const hkVector4& a, float r)
    {
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
};

static __forceinline void setRotatedDir(hkVector4& out, const hkRotation& r, const hkVector4& v)
{
    const float b0 = v.x;
    const float b1 = v.y;
    const float b2 = v.z;
    out.x = r.m_col0.x * b0 + r.m_col1.x * b1 + r.m_col2.x * b2;
    out.y = r.m_col0.y * b0 + r.m_col1.y * b1 + r.m_col2.y * b2;
    out.z = r.m_col0.z * b0 + r.m_col1.z * b1 + r.m_col2.z * b2;
    out.w = 0.0f;
}

static __forceinline float min2(float a, float b)
{
    return a < b ? a : b;
}

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const hkTransform* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpShapeRayCastOutput
{
    hkVector4 m_normal;
    float m_hitFraction;
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpCdPoint
{
    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;

    hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}
};

class hkpCdPointCollector
{
public:
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& event);
    float m_earlyOutDistance;
};

struct RayToCdPointCollector
{
    void* m_vtable;
    float m_earlyOutHitFraction;
    int unk08;
    int unk0c;
    hkVector4 m_from;
    float m_radius;
    int unk24;
    int unk28;
    int unk2c;
    hkVector4 m_path;
    const hkpCdBody* m_castBody;
    hkpCdPointCollector* m_collector;

    void hkHeightFieldRayForwardingCollector_addRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastOutput& hitInfo);
};

// pdb: hkHeightFieldRayForwardingCollector::addRayHit | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void RayToCdPointCollector::hkHeightFieldRayForwardingCollector_addRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastOutput& hitInfo)
{
    hkpCdPoint event(*m_castBody, cdBody);
    event.m_contact.m_position.setAddMul4(hitInfo.m_hitFraction, m_from, m_path);
    setRotatedDir(event.m_contact.m_separatingNormal, cdBody.m_motion->m_rotation, hitInfo.m_normal);
    event.m_contact.m_position.addMul4(event.m_contact.m_separatingNormal, -m_radius);
    event.m_contact.m_separatingNormal.w = hitInfo.m_hitFraction;
    m_collector->addCdPoint(event);
    m_earlyOutHitFraction = min2(m_collector->m_earlyOutDistance, m_earlyOutHitFraction);
}

}
}   // namespace f3m_009bbd50

// @f3 0x009b7ce0 (community match, verified in this file)
namespace f3m_009b7ce0 {
namespace f3m_009b7ce0 {

struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(const float& x) { m_real = x; }
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkQuadReal
{
    float v[4];
};

struct __declspec(align(16)) hkVector4
{
    hkQuadReal m_quad;

    __forceinline hkSimdReal getSimdAt(int i) const { hkQuadReal q; q.v[i] = m_quad.v[i]; return q.v[i]; }
    __forceinline void addMul4(hkSimdReal r, const hkVector4& a)
    {
        m_quad.v[0] += r * a.m_quad.v[0];
        m_quad.v[1] += r * a.m_quad.v[1];
        m_quad.v[2] += r * a.m_quad.v[2];
        m_quad.v[3] += r * a.m_quad.v[3];
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_quad.v[0] = -v.m_quad.v[0];
        m_quad.v[1] = -v.m_quad.v[1];
        m_quad.v[2] = -v.m_quad.v[2];
        m_quad.v[3] = v.m_quad.v[3];
    }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkSimdReal getDistanceSimdReal() const { return m_separatingNormal.getSimdAt(3); }
    __forceinline void flip()
    {
        m_position.addMul4(getDistanceSimdReal(), m_separatingNormal);
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};

struct __declspec(align(16)) hkpProcessCdPoint
{
    hkContactPoint m_contact;
    unsigned int m_contactPointId;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};

struct hkpGskCache
{
    unsigned short m_vertices[4];
    unsigned char m_dimA;
    unsigned char m_dimB;
    unsigned char m_maxDimA : 4;
    unsigned char m_maxDimB : 4;
    unsigned char unk0b;

    __forceinline void flip()
    {
        unsigned char t = m_maxDimA;
        m_maxDimA = m_maxDimB;
        m_maxDimB = t;
        unsigned char t2 = m_dimA;
        m_dimA = m_dimB;
        m_dimB = t2;
        int n = m_dimA + m_dimB - 1;
        unsigned short v0 = m_vertices[0];
        m_vertices[0] = m_vertices[n];
        m_vertices[n] = v0;
        if ((m_dimA & m_dimB) == 2)
        {
            unsigned short v1 = m_vertices[1];
            m_vertices[1] = m_vertices[2];
            m_vertices[2] = v1;
        }
    }
};

struct __declspec(align(16)) hkpToiInfo
{
    hkContactPoint m_contact;
    float m_time;
    float m_seperatingVelocity;
    unsigned int unk08;
    unsigned int unk0c;
    hkpGskCache m_gskCache;

    __forceinline void flip()
    {
        m_contact.m_separatingNormal.m_quad.v[0] = -m_contact.m_separatingNormal.m_quad.v[0];
        m_contact.m_separatingNormal.m_quad.v[1] = -m_contact.m_separatingNormal.m_quad.v[1];
        m_contact.m_separatingNormal.m_quad.v[2] = -m_contact.m_separatingNormal.m_quad.v[2];
        m_gskCache.flip();
    }
};

struct __declspec(align(16)) hkpProcessCollisionOutput
{
    hkpProcessCdPoint* m_firstFreeContactPoint;
    hkpProcessCdPoint m_contactPoints[256];
    hkpToiInfo m_toi;
};

}

using namespace f3m_009b7ce0;

struct hkpSymmetricAgentStandIn9b7
{
    void hkpBvTreeAgent_processCollision(const void* bodyA, const void* bodyB, const void* input, hkpProcessCollisionOutput* result);
    void FUN_009b7ce0(const void* bodyA, const void* bodyB, const void* input, hkpProcessCollisionOutput* result);
};

// pdb: hkpSymmetricAgentLinearCast<hkpMoppAgent>::processCollision | hkpMoppAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void hkpSymmetricAgentStandIn9b7::FUN_009b7ce0(const void* bodyA, const void* bodyB, const void* input,
                                            hkpProcessCollisionOutput* result)
{
    hkpProcessCdPoint* p = result->m_firstFreeContactPoint;
    float toi = result->m_toi.m_time;
    hkpBvTreeAgent_processCollision(bodyB, bodyA, input, result);
    for (; p < result->m_firstFreeContactPoint; p++)
    {
        p->m_contact.flip();
    }
    if (toi != result->m_toi.m_time)
    {
        result->m_toi.flip();
    }
}
}   // namespace f3m_009b7ce0

// @f3 0x009a83f0 (community match, verified in this file)
namespace f3m_009a83f0 {
struct Vec9 { float x,y,z,w; __forceinline unsigned bits(int i) const { return *(const unsigned*)((const char*)this+i*4); }
 __forceinline void setAdd(const Vec9& a,const Vec9& b) { x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w; }
 __forceinline void setMul(const Vec9& a,const Vec9& b) { x=a.x*b.x;y=a.y*b.y;z=a.z*b.z;w=a.w*b.w; }
 __forceinline void setMin(const Vec9& a,const Vec9& b) { x=a.x<b.x?a.x:b.x; y=a.y<b.y?a.y:b.y;z=a.z<b.z?a.z:b.z;w=a.w<b.w?a.w:b.w; }
 __forceinline void setMax(const Vec9& a,const Vec9& b) { x=a.x>b.x?a.x:b.x; y=a.y>b.y?a.y:b.y;z=a.z>b.z?a.z:b.z;w=a.w>b.w?a.w:b.w; }
};
extern Vec9 DAT_010610b0, DAT_01092a50;
struct __declspec(align(16)) Aabb9 { Vec9 lo,hi; };
struct Out4 { unsigned short x,y,z,w; };
struct Height9 {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void v28(); virtual float height(int x,int z) const;
 int unk04,unk08,unk0c; unsigned nx,nz; int unk18,unk1c,unk20; float unk24; int unk28,unk2c;
 Vec9 scale,offset,limit;
 float scaledHeight(int x,int z) const { float raw=height(x,z); return unk24*raw; }
};
struct Collection9 { int unk00,unk04,unk08,unk0c,unk10,unk14; Height9* hf; int unk1c; float radius;
 __declspec(noinline) Height9* FUN_009a7e90() const;
};
struct Tree9 { int unk00,unk04,unk08,unk0c,unk10; Collection9* child; int unk18; bool m_bCheckHeightFieldBounds;
 __declspec(noinline) Collection9* FUN_009a82b0() const;
 unsigned FUN_009a83f0(const Aabb9& in, unsigned* hits,int maxNumKeys) const;
};
Collection9* Tree9::FUN_009a82b0() const { return child; }
unsigned Tree9::FUN_009a83f0(const Aabb9& in, unsigned* hits,int maxNumKeys) const {
 const Height9* hf=FUN_009a82b0()->FUN_009a7e90();
 float positive=FUN_009a82b0()->radius;
 float negative=-FUN_009a82b0()->radius;
 Aabb9 aabb;
 aabb.hi.x=in.hi.x+positive; aabb.hi.y=in.hi.y+positive; aabb.hi.z=in.hi.z+positive;
 aabb.lo.x=in.lo.x+negative; aabb.lo.y=in.lo.y+negative; aabb.lo.z=in.lo.z+negative;
 __declspec(align(16)) Vec9 cell;
 Out4 out;
 cell.setAdd(aabb.lo,hf->offset);
 cell.setMul(hf->scale,cell);
 cell.setMin(cell,hf->limit);
 cell.setMax(cell,DAT_01092a50);
 cell.setAdd(cell,DAT_010610b0);
 out.x=(unsigned short)(cell.bits(0)>>7);
 out.z=(unsigned short)(cell.bits(2)>>7);
 unsigned minX=out.x;
 unsigned minZ=out.z;
 cell.setAdd(aabb.hi,hf->offset);
 cell.setMul(hf->scale,cell);
 cell.setMin(cell,hf->limit);
 cell.setMax(cell,DAT_01092a50);
 cell.setAdd(cell,DAT_010610b0);
 out.x=(unsigned short)(cell.bits(0)>>7);
 out.z=(unsigned short)(cell.bits(2)>>7);
 unsigned maxX=out.x;
 unsigned maxZ=out.z;
 if(minX>=hf->nx-1 && maxX>=hf->nx-1) return 0;
 if(minZ>=hf->nz-1 && maxZ>=hf->nz-1) return 0;
 if(minX>=hf->nx-1) minX=0;
 if(minZ>=hf->nz-1) minZ=0;
 if(maxX>=hf->nx-1) maxX=hf->nx-2;
 if(maxZ>=hf->nz-1) maxZ=hf->nz-2;
 int numHits=0;
    if (m_bCheckHeightFieldBounds)
    {
        bool allBelow = true;
        bool allAbove = true;
        unsigned x, z;

        for (x = minX; x <= maxX; x++)
        {
            for (z = minZ; z <= maxZ; z++)
            {
                unsigned int key = (x << 1) + (z << 16);
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key;
                }
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key | 1;
                }
                if (allBelow || allAbove)
                {
                    float height = hf->scaledHeight(x, z);
                    if (aabb.lo.y < height)
                    {
                        allBelow = false;
                    }
                    if (height < aabb.hi.y)
                    {
                        allAbove = false;
                    }
                }
            }
        }

        if (allBelow || allAbove)
        {
            for (x = minX; x <= maxX + 1; x++)
            {
                float height = hf->scaledHeight(x, maxZ + 1);
                if (aabb.lo.y < height)
                {
                    allBelow = false;
                }
                if (height < aabb.hi.y)
                {
                    allAbove = false;
                }
            }
            for (z = minZ; z <= maxZ + 1; z++)
            {
                float height = hf->scaledHeight(maxX + 1, z);
                if (aabb.lo.y < height)
                {
                    allBelow = false;
                }
                if (height < aabb.hi.y)
                {
                    allAbove = false;
                }
            }
            if (allBelow || allAbove)
            {
                return 0;
            }
        }
    }
    else
    {
        for (unsigned x = minX; x <= maxX; x++)
        {
            for (unsigned z = minZ; z <= maxZ; z++)
            {
                unsigned int key = (x << 1) + (z << 16);
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key;
                    if (numHits < maxNumKeys)
                    {
                        hits[numHits++] = key | 1;
                    }
                }
            }
        }
    }
    return numHits;
}
}   // namespace f3m_009a83f0

// @f3 0x009b7380 (community match, verified in this file)
namespace f3m_009b7380 {
namespace f3m_009b7380 {
// Scalar wrapper: the scale reaches addMul4 by const reference and is stored once per entry.
struct SimdReal {
    float m_real;
    SimdReal(float r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void addMul4(const SimdReal& r, const Vec4& a)
    {
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    void setNeg3(const Vec4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
};
struct ContactPoint {
    Vec4 m_position;
    Vec4 m_separatingNormal;   // fourth lane is the distance
    SimdReal getDistanceSimdReal() const { return SimdReal(m_separatingNormal.w); }
};
struct RootCdPoint {
    ContactPoint m_contact;
    int m_rootA, m_rootB, m_keyA, m_keyB;
};
struct Collector {
    RootCdPoint* end;
    int unk04, unk08, unk0c;
    RootCdPoint vertices[256];
    int unk3010, unk3014, unk3018, unk301c;
    float unk3020, unk3024, unk3028, unk302c, unk3030;
    int unk3034, unk3038, unk303c;
    unsigned short ids[4];
    unsigned char unk3048, unk3049;
    unsigned char nibLo : 4;
    unsigned char nibHi : 4;
};
struct Agent {
    void hkpBvTreeStreamAgent_processCollision(int a, int b, int c, Collector* o);
    void FUN_009b7380(int p1, int p2, int p3, Collector* o);
};
}

// Runs hkpBvTreeStreamAgent_processCollision with the first two arguments exchanged, then turns every entry it added
// (and, when the stored result changed, the collector's own direction and index data) around.
// pdb: hkpSymmetricAgentLinearCast<hkpBvTreeStreamAgent>::processCollision | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void f3m_009b7380::Agent::FUN_009b7380(int p1, int p2, int p3, f3m_009b7380::Collector* o)
{
    using namespace f3m_009b7380;
    RootCdPoint* e = o->end;
    // Fake match: the saved float passes through one lane of an aligned vector local. The vector
    // itself disappears; it only makes the compiler align the frame (and esp,-16 at +3).
    Vec4 savedv; savedv.x = o->unk3030;
    float saved = savedv.x;
    hkpBvTreeStreamAgent_processCollision(p2, p1, p3, o);
    for (; e < o->end; e++) {
        ContactPoint& cp = e->m_contact;
        cp.m_position.addMul4(cp.getDistanceSimdReal(), cp.m_separatingNormal);
        cp.m_separatingNormal.setNeg3(cp.m_separatingNormal);
    }
    if (saved != o->unk3030) {
        float* v = &o->unk3020;
        v[0] = -v[0];
        v[1] = -v[1];
        v[2] = -v[2];
        unsigned char t4 = o->nibLo;
        o->nibLo = o->nibHi;
        o->nibHi = t4;
        unsigned char c = o->unk3048;
        o->unk3048 = o->unk3049;
        o->unk3049 = c;
        int n = o->unk3048 + o->unk3049 - 1;
        unsigned short t = o->ids[0];
        unsigned short* arr = &o->ids[0];
        arr[0] = arr[n];
        arr[n] = t;
        if ((o->unk3048 & o->unk3049) == 2) {
            unsigned short w = o->ids[1];
            o->ids[1] = o->ids[2];
            o->ids[2] = w;
        }
    }
}
}   // namespace f3m_009b7380

// @f3 0x009bf2b0 (community match, verified in this file)
namespace f3m_009bf2b0 {
// Symmetric collision agent wrapper: runs the wrapped agent with the two bodies exchanged, then flips
// every contact point it added and, when the time of impact changed, the stored impact data.
namespace N9bf2b0 {
// Fake match: the 16-byte alignment on this scalar wrapper only asks for the aligned frame
// (push ebp, and esp -16); the value itself lives in a 4-byte slot.
struct __declspec(align(16)) SimdReal {
    float r;
    SimdReal(const float& f) : r(f) {}
    operator float() const { return r; }
};
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    SimdReal getSimdAt(int i) const { return (&x)[i]; }
    void addMul4(const SimdReal& rhs, const Vector4& a) {
        float r = rhs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    void setNeg3(const Vector4& v) {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
};
struct ProcessPoint {
    Vector4 m_position;
    Vector4 m_normal;       // w is the distance
    int m_id;
    int unk24;
    int unk28;
    int unk2C;
};
struct DimNibbles {
    unsigned char m_low : 4;
    unsigned char m_high : 4;
};
struct ProcessOutput {
    ProcessPoint* m_firstFree;
    int unk04;
    int unk08;
    int unk0C;
    ProcessPoint m_points[256];
    Vector4 m_toiPosition;
    Vector4 m_toiNormal;
    float m_toiTime;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_dimA;
    unsigned char m_dimB;
    DimNibbles m_dims;
};
struct SymmetricAgent {
    void hkpListAgent_processCollision(int bodyA, int bodyB, int input, ProcessOutput* result);
    void FUN_009bf2b0(int bodyA, int bodyB, int input, ProcessOutput* result);
};
}
using namespace N9bf2b0;

// pdb: hkpSymmetricAgentLinearCast<hkpListAgent>::processCollision | hkpListAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, result
void SymmetricAgent::FUN_009bf2b0(int bodyA, int bodyB, int input, ProcessOutput* result) {
    ProcessPoint* pp = result->m_firstFree;
    float oldTime = result->m_toiTime;
    hkpListAgent_processCollision(bodyB, bodyA, input, result);
    for (; pp < result->m_firstFree; pp++) {
        pp->m_position.addMul4(pp->m_normal.getSimdAt(3), pp->m_normal);
        pp->m_normal.setNeg3(pp->m_normal);
    }
    if (oldTime != result->m_toiTime) {
        {
            Vector4& n = result->m_toiNormal;
            n.setNeg3(n);
        }
        {
            unsigned char t = result->m_dims.m_low;
            result->m_dims.m_low = result->m_dims.m_high;
            result->m_dims.m_high = t;
        }
        {
            unsigned char t = result->m_dimA;
            result->m_dimA = result->m_dimB;
            result->m_dimB = t;
        }
        int last = result->m_dimA + result->m_dimB - 1;
        unsigned short t0 = result->m_ids[0];
        result->m_ids[0] = result->m_ids[last];
        result->m_ids[last] = t0;
        if ((result->m_dimA & result->m_dimB) == 2) {
            unsigned short t1 = result->m_ids[1];
            result->m_ids[1] = result->m_ids[2];
            result->m_ids[2] = t1;
        }
    }
}
}   // namespace f3m_009bf2b0

// @f3 0x009bfd60 (community match, verified in this file)
extern unsigned long DAT_0116913c;
namespace f3m_009bfd60 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
typedef float hkReal;

struct hkMonitorStreamCommand { const char* m_commandAndMonitor; unsigned int m_time0; unsigned int m_time1; };
struct hkMonitorStream {
    char* m_start; char* m_end; char* m_capacity; char* m_capacityMinus16;
    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    bool memoryAvailable() { return m_end < m_capacityMinus16; }
    char* getEnd() { return m_end; }
    void setEnd(char* e) { m_end = e; }
};
static __forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable()) {
        hkMonitorStreamCommand* h = (hkMonitorStreamCommand*)stream.getEnd();
        h->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_time0 = ticks;
        stream.setEnd((char*)(h + 1));
    }
}

class hkTransform;
class __declspec(align(16)) hkVector4 {
public:
    hkReal x, y, z, w;
    hkReal& operator()(int i) { return (&x)[i]; }
    hkReal operator()(int i) const { return (&x)[i]; }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};
class hkRotation {
public:
    hkVector4 m_col0, m_col1, m_col2;
    hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    hkReal operator()(int r, int c) const { return getColumn(c)(r); }
};
class hkTransform {
public:
    hkRotation m_rotation;
    hkVector4 m_translation;
    const hkRotation& getRotation() const { return m_rotation; }
    const hkVector4& getTranslation() const { return m_translation; }
    const hkVector4& getColumn(int i) const { return (&m_rotation.m_col0)[i]; }
    hkReal operator()(int r, int c) const { return getColumn(c)(r); }
    void setMulInverseMul(const hkTransform& a, const hkTransform& b);
};
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    this->x = t.getRotation()(0,0)*v0 + t.getRotation()(0,1)*v1 + t.getRotation()(0,2)*v2 + t.getTranslation()(0);
    this->y = t.getRotation()(1,0)*v0 + t.getRotation()(1,1)*v1 + t.getRotation()(1,2)*v2 + t.getTranslation()(1);
    this->z = t.getRotation()(2,0)*v0 + t.getRotation()(2,1)*v1 + t.getRotation()(2,2)*v2 + t.getTranslation()(2);
    this->w = 0;
}

struct hkBool { char m_bool; operator bool() const { return m_bool != 0; } };
struct hkpShapeRayCastInput {
    hkVector4 m_from, m_to;
    unsigned int m_filterInfo;
    const void* m_rayShapeCollectionFilter;
    hkpShapeRayCastInput() : m_filterInfo(0), m_rayShapeCollectionFilter(0) {}
};
struct hkpShapeRayCastCollectorOutput {
    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
    int m_pad0, m_pad1;
    hkpShapeRayCastCollectorOutput() { m_hitFraction = 1.0f; m_extraInfo = -1; }
};
struct hkpShapeRayCastOutput : hkpShapeRayCastCollectorOutput {
    unsigned int m_shapeKeys[8];
    int m_shapeKeyIndex;
    hkpShapeRayCastOutput() { m_shapeKeyIndex = 0; m_shapeKeys[0] = 0xffffffff; }
};
struct hkpShape {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual hkBool castRay(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
};
struct hkpMultiRayShape {
    struct Ray { hkVector4 m_start, m_end; };
    int m_unk00, m_unk04, m_unk08, m_unk0c;
    Ray* m_rays; int m_numRays;
};
struct hkpCdBody { const void* m_shape; unsigned int m_shapeKey; const hkTransform* m_motion; const hkpCdBody* m_parent;
    const void* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *m_motion; } };
struct hkpCollisionInput;
struct hkpCdBodyPairCollector {
    virtual ~hkpCdBodyPairCollector();
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
    hkBool m_earlyOut;
    hkBool getEarlyOut() const { return m_earlyOut; }
};

// pdb: hkpMultiRayConvexAgent::staticGetPenetrations | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkpMultiRayConvexAgent_staticGetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector)
{
    hkTimerCommand("TtmultiRay-cnvx-getPen");
    const hkpMultiRayShape* msA = static_cast<const hkpMultiRayShape*>(bodyA.getShape());
    const hkpShape* convexB = static_cast<const hkpShape*>(bodyB.getShape());

    hkTransform bTa;
    bTa.setMulInverseMul(bodyB.getTransform(), bodyA.getTransform());

    int nRays = msA->m_numRays;
    const hkpMultiRayShape::Ray* rayA = msA->m_rays;
    hkpShapeRayCastInput rayInput;
    hkpShapeRayCastOutput rayResults;
    while (nRays-- && !collector.getEarlyOut())
    {
        rayInput.m_from._setTransformedPos(bTa, rayA->m_start);
        rayInput.m_to._setTransformedPos(bTa, rayA->m_end);
        hkBool hit = convexB->castRay(rayInput, rayResults);
        if (hit)
        {
            collector.addCdBodyPair(bodyA, bodyB);
        }
        rayA++;
    }
    hkTimerCommand("Et");
}
}   // namespace f3m_009bfd60

// @f3 0x009ada30 (community match, verified in this file)
namespace f3m_009ada30 {
struct Scalar9ada30 {

    float value;

    Scalar9ada30(float v) : value(v) {}

    operator float() const { return value; }

};



struct __declspec(align(16)) Vec9ada30 {

    float x, y, z, w;

    __forceinline void setAll(float v) { x=v; y=v; z=v; w=v; }

    __forceinline void setSub(const Vec9ada30& a, const Vec9ada30& b) {

        x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w;

    }

    __forceinline void setAdd(const volatile Vec9ada30& a, const Vec9ada30& b) {

        x=a.x+b.x; y=a.y+b.y; z=a.z+b.z; w=a.w+b.w;

    }

    __forceinline void setMin(const Vec9ada30& a, const Vec9ada30& b) {

        x=a.x<b.x ? a.x:b.x; y=a.y<b.y ? a.y:b.y;

        z=a.z<b.z ? a.z:b.z; w=a.w<b.w ? a.w:b.w;

    }

    __forceinline void setMax(const Vec9ada30& a, const Vec9ada30& b) {

        x=a.x>b.x ? a.x:b.x; y=a.y>b.y ? a.y:b.y;

        z=a.z>b.z ? a.z:b.z; w=a.w>b.w ? a.w:b.w;

    }

};



__forceinline void transformCenter(Vec9ada30& out, const Vec9ada30& v,

    const Vec9ada30& c0, const Vec9ada30& c1, const Vec9ada30& c2, const Vec9ada30& translation) {

    Scalar9ada30 x(v.x), y(v.y), z(v.z);

    out.x = (x*c0.x + y*c1.x) + z*c2.x + translation.x;

    out.y = (x*c0.y + y*c1.y) + z*c2.y + translation.y;

    out.z = (x*c0.z + y*c1.z) + z*c2.z + translation.z;

    out.w = 0.0f;

}



struct Transform9ada30 { Vec9ada30 c0,c1,c2,translation; };

struct Aabb9ada30 { Vec9ada30 minimum, maximum; };

struct MultiSphere9ada30 {

    int unk00, unk04, unk08, unk0c;

    int count;

    int unk14, unk18, unk1c;

    Vec9ada30 spheres[8];

    void hkpMultiSphereShape_getAabbImpl(const Transform9ada30& transform, float tolerance, Aabb9ada30& out) const;

};



// pdb: hkpMultiSphereShape::getAabbImpl | hkpMultiSphereShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void MultiSphere9ada30::hkpMultiSphereShape_getAabbImpl(const Transform9ada30& transform, float tolerance, Aabb9ada30& out) const {

    Vec9ada30 centers[8];

    int remaining;

    {

        Vec9ada30 c1;

        Vec9ada30 c0 = transform.c0;

        c1 = transform.c1;

        Vec9ada30 c2 = transform.c2;

        Vec9ada30 translation = transform.translation;

        remaining = count;

        int i = remaining-1;

        do {

            transformCenter(centers[i], spheres[i], c0, c1, c2, translation);

        } while (--i>=0);

    }

    Vec9ada30 minimum, maximum;

    minimum.setAll(3.40282e38f);

    maximum.setAll(-3.40282e38f);

    const Vec9ada30* src = spheres;

    const Vec9ada30* center = centers;

    if (remaining>0) {

        do {

            Vec9ada30 radius;

            radius.setAll(src->w);

            Vec9ada30 lower, upper;

            lower.setSub(*center, radius);

            upper.setAdd(*center, radius);

            minimum.setMin(minimum, lower);

            maximum.setMax(maximum, upper);

            ++src;

            ++center;

        } while (--remaining);

    }

    Vec9ada30 margin;

    margin.setAll(tolerance);

    out.minimum.setSub(minimum, margin);

    out.maximum.setAdd(maximum, margin);

}

}   // namespace f3m_009ada30

// @f3 0x009a9660 (community match, verified in this file)
namespace f3m_009a9660 {
// 0x009a9660: hkpWorldConstraintUtil::addConstraint(hkpWorld*, hkpConstraintInstance*) of Havok 5.5.0
// (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Fills a hkConstraintInternal for the instance, inserts it into the master entity's sorted list, makes room for
// its runtime data in the master's runtime buffer and appends the instance to the slave entity.
// Class, member and function names and the member offsets follow the Havok 5.5.0 SDK headers; the declarations
// below are cut down to what this function touches, and the body is written from the game's code.
namespace f3m_009a9660 {

typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

struct hkBool
{
    hkBool() {}
    hkBool(bool b) : m_bool(b) {}
    operator bool() const { return m_bool != 0; }
    char m_bool;
};

template <class ENUM, class TYPE> struct hkEnum
{
    operator ENUM() const { return (ENUM)m_storage; }
    TYPE m_storage;
};

struct hkArrayUtil
{
    // grows the array to at least iNumElem elements
    static void __cdecl FUN_00901e90(void* pvArray, int iNumElem, int iSizeElem);
    // grows the array for one more element
    static void __cdecl FUN_00901f10(void* pvArray, int iSizeElem);
};
// moves iNumBytes bytes, overlapping ranges allowed
void __cdecl FUN_009234f0(void* pvDst, const void* pvSrc, int iNumBytes);

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T* begin() { return m_data; }
    void reserve(int n)
    {
        if (getCapacity() < n)
            hkArrayUtil::FUN_00901e90(this, n, sizeof(T));
    }
    void setSizeUnchecked(int n) { m_size = n; }
    void pushBack(const T& t)
    {
        if (m_size == getCapacity())
            hkArrayUtil::FUN_00901f10(this, sizeof(T));
        m_data[m_size++] = t;
    }
};

template <class T> struct hkSmallArray
{
    T* m_data;
    hkUint16 m_size;
    hkUint16 m_capacityAndFlags;

    hkUint16 getSize() const { return m_size; }
    hkUint16 getCapacity() const { return m_capacityAndFlags & 0x3fff; }
    T& operator[](int i) { return m_data[i]; }
    // inserts t before element i
    void FUN_009a9b10(int i, const T& t);
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};
struct hkpModifierConstraintAtom : hkpConstraintAtom
{
    char m_pad02[0xe];
    hkUint16 m_modifierAtomSize;
};

struct hkpConstraintInstance;
struct hkpConstraintRuntime;

struct hkpConstraintData
{
    struct ConstraintInfo
    {
        int m_maxSizeOfSchema;
        int m_sizeOfSchemas;
        int m_numSolverResults;
        int m_numSolverElemTemps;
        hkpConstraintAtom* m_atoms;
        int m_sizeOfAllAtoms;
    };
    struct RuntimeInfo
    {
        int m_sizeOfExternalRuntime;
        int m_numSolverResults;
    };

    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void getRuntimeInfo(hkBool wantExternalRuntime, RuntimeInfo& infoOut);
    virtual void Unk06();
    virtual void addInstance(hkpConstraintInstance* pkConstraint, hkpConstraintRuntime* pkRuntime, int iSizeOfRuntime);
    virtual void Unk08();
    virtual hkBool isBuildJacobianCallbackRequired();
    virtual void Unk10();
    virtual void getConstraintInfo(ConstraintInfo& infoOut);
};

enum ConstraintPriority
{
    PRIORITY_INVALID
};

// adds the modifier atoms' sizes to cinfo and returns their callback request bits
hkUint8 __cdecl FUN_009a1f20(hkpModifierConstraintAtom* pkModifier, hkpConstraintData::ConstraintInfo& cinfo);

struct hkpWorld;
struct hkpEntity;

struct hkpSimulationIsland
{
    char m_pad00[0x1c];
    int m_numConstraints;

    // hkpConstraintOwner's bookkeeping of a new constraint's sizes (hkpConstraintOwner_addConstraintInfo in the project's names)
    void FUN_00929b70(hkpConstraintInstance* pkConstraint, const hkpConstraintData::ConstraintInfo& cinfo);
};

__declspec(align(16)) struct hkConstraintInternal
{
    hkpConstraintInstance* m_constraint;
    hkpEntity* m_entities[2];
    hkpConstraintAtom* m_atoms;
    hkUint16 m_atomsSize;
    hkUint8 m_callbackRequest;
    hkEnum<ConstraintPriority, hkUint8> m_priority;
    hkUint16 m_sizeOfSchemas;
    hkUint16 m_numSolverResults;
    hkUint16 m_numSolverElemTemps;
    hkUint8 m_whoIsMaster;
    hkBool m_isNormalType;
    hkpConstraintRuntime* m_runtime;
    hkUint16 m_runtimeSize;
    hkUint16 m_slaveIndex;
};

struct hkpEntity
{
    char m_pad00[8];
    hkpWorld* m_world;
    char m_pad0c[0x8c];
    hkSmallArray<hkConstraintInternal> m_constraintsMaster;
    hkArray<hkpConstraintInstance*> m_constraintsSlave;
    hkArray<hkUint8> m_constraintRuntime;
    hkpSimulationIsland* m_simulationIsland;
    char m_padbc[4];
    hkUint32 m_uid;
    char m_padc4[0x14];
    hkUint8 m_motionType;

    hkBool isFixed() const { return m_motionType == 7; }
    hkUint32 getUid() const { return m_uid; }
    hkpSimulationIsland* getSimulationIsland() const { return m_simulationIsland; }
    hkpWorld* getWorld() const { return m_world; }
};

struct hkpConstraintInstance
{
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual int getType();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    hkpSimulationIsland* m_owner;
    hkpConstraintData* m_data;
    hkpModifierConstraintAtom* m_constraintModifiers;
    hkpEntity* m_entities[2];
    hkEnum<ConstraintPriority, hkUint8> m_priority;
    hkBool m_wantRuntime;
    char m_pad1e[0xa];
    hkConstraintInternal* m_internal;

    void addReference()
    {
        if (m_memSizeAndFlags != 0)
            ++m_referenceCount;
    }
};

// merges the simulation islands of the two entities
void __cdecl FUN_00928630(hkpWorld* pkWorld, hkpEntity* pkEntityA, hkpEntity* pkEntityB);

// pdb: hkpWorldConstraintUtil::addConstraint | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap_sim), high
void __cdecl hkpWorldConstraintUtil_addConstraint(hkpWorld* world, hkpConstraintInstance* constraint)
{
    constraint->addReference();

    hkpConstraintData::ConstraintInfo info;
    constraint->m_data->getConstraintInfo(info);

    hkConstraintInternal ci;
    ci.m_constraint = constraint;
    ci.m_entities[0] = constraint->m_entities[0];
    ci.m_entities[1] = constraint->m_entities[1];
    if (constraint->m_constraintModifiers)
    {
        ci.m_atoms = constraint->m_constraintModifiers;
        ci.m_atomsSize = constraint->m_constraintModifiers->m_modifierAtomSize;
    }
    else
    {
        ci.m_atoms = info.m_atoms;
        ci.m_atomsSize = (hkUint16)info.m_sizeOfAllAtoms;
    }
    ci.m_priority = constraint->m_priority;

    // two moving entities of different islands: the constraint joins the islands
    if (!ci.m_entities[0]->isFixed() && !ci.m_entities[1]->isFixed() &&
        ci.m_entities[0]->getSimulationIsland() != ci.m_entities[1]->getSimulationIsland())
    {
        FUN_00928630(ci.m_entities[0]->getWorld(), ci.m_entities[0], ci.m_entities[1]);
    }

    // the first entity is the master unless it is fixed
    ci.m_whoIsMaster = ci.m_entities[0]->isFixed();
    hkpEntity* masterEntity = ci.m_entities[ci.m_whoIsMaster];
    constraint->m_owner = masterEntity->getSimulationIsland();
    constraint->m_owner->m_numConstraints++;

    int atomType = ci.m_atoms->m_type;
    ci.m_isNormalType = true;
    ci.m_callbackRequest = 0;
    if (atomType == 1)
    {
        ci.m_callbackRequest = 2;
        if (constraint->m_data->isBuildJacobianCallbackRequired())
            ci.m_callbackRequest |= 4;
        ci.m_isNormalType = constraint->getType() == 0;
    }
    else if (atomType == 0x14)
    {
        ci.m_callbackRequest = 2;
    }
    if (constraint->m_constraintModifiers)
        ci.m_callbackRequest |= FUN_009a1f20(constraint->m_constraintModifiers, info);

    ci.m_numSolverResults = 0;
    ci.m_numSolverElemTemps = 0;
    ci.m_sizeOfSchemas = 0;
    constraint->m_internal = &ci;
    constraint->m_owner->FUN_00929b70(constraint, info);

    // the master's list is sorted by priority, then by the uids of the two entities
    hkSmallArray<hkConstraintInternal>& masters = masterEntity->m_constraintsMaster;
    hkUint16 numMasters = masters.getSize();
    int insertPos;
    for (insertPos = 0; insertPos < numMasters; insertPos++)
    {
        hkConstraintInternal& cur = masters[insertPos];
        if (cur.m_priority > ci.m_priority)
            break;
        if (cur.m_priority == ci.m_priority)
        {
            hkUint32 curUid = cur.m_entities[0]->getUid();
            hkUint32 newUid = ci.m_entities[0]->getUid();
            if (curUid > newUid)
                break;
            if (curUid == newUid)
            {
                if (cur.m_entities[1]->getUid() > ci.m_entities[1]->getUid())
                    break;
            }
        }
    }

    // the insert moves the entries behind insertPos, or all of them when the list has to grow:
    // every moved entry's instance gets its new address
    int firstChanged = numMasters < masters.getCapacity() ? insertPos : 0;
    masters.FUN_009a9b10(insertPos, ci);
    for (int i = firstChanged; i < masters.getSize(); i++)
    {
        hkConstraintInternal* moved = &masters[i];
        moved->m_constraint->m_internal = moved;
    }

    // room for the instance's runtime data in the master's buffer, at the same position as in the list
    hkConstraintInternal* internal = constraint->m_internal;
    {
        hkpConstraintData::RuntimeInfo rinfo;
        internal->m_constraint->m_data->getRuntimeInfo(constraint->m_wantRuntime, rinfo);
        rinfo.m_sizeOfExternalRuntime = (rinfo.m_sizeOfExternalRuntime + 15) & ~15;
        internal->m_runtimeSize = (hkUint16)rinfo.m_sizeOfExternalRuntime;

        if (rinfo.m_sizeOfExternalRuntime)
        {
            hkArray<hkUint8>& runtimes = masterEntity->m_constraintRuntime;
            hkUint8* oldStart = runtimes.begin();
            int oldSize = runtimes.getSize();
            runtimes.reserve(oldSize + rinfo.m_sizeOfExternalRuntime);
            runtimes.setSizeUnchecked(oldSize + rinfo.m_sizeOfExternalRuntime);
            hkUint8* position = runtimes.begin();
            int offset = (int)(position - oldStart);

            // entries before the new one: only the buffer's address may have changed
            int i;
            for (i = 0; i < insertPos; i++)
            {
                hkConstraintInternal* c = &masters[i];
                if (c->m_runtime)
                {
                    c->m_runtime = (hkpConstraintRuntime*)((hkUint8*)c->m_runtime + offset);
                    position = (hkUint8*)c->m_runtime + c->m_runtimeSize;
                }
            }

            // the rest of the buffer moves up by the new entry's size
            int restLen = runtimes.getSize() - internal->m_runtimeSize - (int)(position - runtimes.begin());
            FUN_009234f0(position + internal->m_runtimeSize, position, restLen);
            internal->m_runtime = (hkpConstraintRuntime*)position;
            offset += internal->m_runtimeSize;

            for (i++; i < masters.getSize(); i++)
            {
                hkConstraintInternal* c = &masters[i];
                c->m_runtime = c->m_runtime ? (hkpConstraintRuntime*)((hkUint8*)c->m_runtime + offset) : 0;
            }
        }
        else
        {
            internal->m_runtime = 0;
        }
    }

    internal->m_constraint->m_data->addInstance(constraint, internal->m_runtime, internal->m_runtimeSize);

    hkpEntity* slaveEntity = internal->m_entities[1 - internal->m_whoIsMaster];
    internal->m_slaveIndex = (hkUint16)slaveEntity->m_constraintsSlave.getSize();
    slaveEntity->m_constraintsSlave.pushBack(constraint);
}
}  // namespace f3m_009a9660
}   // namespace f3m_009a9660

// @f3 0x009bb7d0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
namespace f3m_009bb7d0 {
// Sphere-list against height field: cast every sphere of shape A through shape B (Havok 5.5).
// Self-contained: every type it needs is declared in its own namespace, nothing is taken from
// the namespaces of other functions in this file.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace N9bb7d0 {

typedef float Real;
typedef unsigned int UInt32;
typedef unsigned int Key;


class Rotation;

class __declspec(align(16)) Vec4
{
	public:
		__forceinline void rotInvDir( const Rotation& r, const Vec4& b );

		Real x;
		Real y;
		Real z;
		Real w;
};

class Rotation
{
	public:
		Vec4 m_col0;
		Vec4 m_col1;
		Vec4 m_col2;
};

class Transform
{
	public:
		__forceinline Transform() {}
		__forceinline const Rotation& getRotation() const { return m_rotation; }
		__forceinline const Vec4& getTranslation() const { return m_translation; }
		void FUN_00925300( const Transform& a, const Transform& b );
	protected:
		Rotation m_rotation;
		Vec4 m_translation;
};

inline void Vec4::rotInvDir( const Rotation& r, const Vec4& b )
{
	Real v0 = b.x;
	Real v1 = b.y;
	Real v2 = b.z;
	x = r.m_col0.x * v0 + r.m_col0.y * v1 + r.m_col0.z * v2;
	y = r.m_col1.x * v0 + r.m_col1.y * v1 + r.m_col1.z * v2;
	z = r.m_col2.x * v0 + r.m_col2.y * v1 + r.m_col2.z * v2;
	w = 0;
}

class ThreadMemory
{
	public:
		virtual void v00();
		virtual void v04();
		virtual void v08();
		virtual void v0c();
		virtual void v10();
		virtual void* onStackOverflow( int numBytes );
		virtual void onStackUnderflow( void* p );

		static __forceinline ThreadMemory& getInstance() { return *static_cast<ThreadMemory*>( TlsGetValue( DAT_010f3170 ) ); }
		__forceinline void* allocateStack( int numBytes )
		{
			char* current = m_stackCurrent;
			char* next = current + numBytes;
			if ( next <= m_stackEnd )
			{
				m_stackCurrent = next;
				return current;
			}
			return onStackOverflow( numBytes );
		}
		__forceinline void deallocateStack( void* p )
		{
			m_stackCurrent = static_cast<char*>( p );
			if ( p == m_stackBase )
			{
				onStackUnderflow( p );
			}
		}

		int m_unk04;
		int m_unk08;
		int m_unk0c;
		int m_unk10;
		int m_unk14;
		int m_unk18;
		int m_unk1c;
		char* m_stackCurrent;
		char* m_stackPrev;
		char* m_stackBase;
		char* m_stackEnd;
};

template <typename T>
__forceinline T* __cdecl allocStack( int n )
{
	return static_cast<T*>( ThreadMemory::getInstance().allocateStack( ( n * sizeof( T ) + 16 ) & ~15 ) );
}

template <typename T>
__forceinline void __cdecl freeStack( T* p )
{
	ThreadMemory::getInstance().deallocateStack( p );
}

class Monitor
{
	public:
		static __forceinline Monitor& getInstance() { return *static_cast<Monitor*>( TlsGetValue( DAT_0116913c ) ); }
		__forceinline char* getEnd() { return m_end; }
		__forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
		__forceinline void setEnd( char* ptr ) { m_end = ptr; }

		char* m_start;
		char* m_end;
		char* m_capacity;
		char* m_capacityMinus16;

		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct TimerCommand : public Command
		{
			UInt32 m_time0;
			UInt32 m_time1;
			__forceinline void setTime()
			{
				UInt32 ticks;
				__asm {
					rdtsc
					mov dword ptr[ticks], eax
				}
				m_time0 = ticks;
			}
		};
		struct TimerBeginListCommand : public TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};

class Shape;

class CdBody
{
	public:
		__forceinline const Transform& getTransform() const { return *static_cast<const Transform*>( m_motion ); }
		__forceinline const Shape* getShape() const { return m_shape; }

		const Shape* m_shape;
		Key m_shapeKey;
		const void* m_motion;
		const CdBody* m_parent;
};

struct Input9bb7d0
{
    int  unk00;
    Real m_f04;
    int  unk08[0x12];
    Vec4 m_vec50;
    Real m_f60;
};

struct Vec9bb7d0
{
    Real x;
    Real y;
    Real z;
    Real w;
    __forceinline void operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};

class Shape9bb7d0A
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual int v24() const;
    virtual const Vec4* v28(Vec4* buffer) const;
};

class Shape9bb7d0B
{
public:
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
    virtual void v28(Vec9bb7d0& info, const CdBody& body, void* collector) const;
};

struct SphereInfo9bb7d0
{
    Vec9bb7d0 m_pos;
    Vec9bb7d0 m_vel;
    int  m_unk20;
    int  m_unk24;
    int  m_unk28;
    int  m_unk2c;
    Real m_radius;
    Real m_tolerance;
    int  m_unk38;
    int  m_unk3c;
};

struct SphereCollector9bb7d0
{
    virtual void collect(const Vec9bb7d0& pos, const void* shape, const Vec9bb7d0& dir);
    Real m_tolerance;
    int  m_unk08;
    int  m_unk0c;
    Vec9bb7d0 m_pos;
    Real m_radius;
    int  m_unk24;
    int  m_unk28;
    int  m_unk2c;
    Vec9bb7d0 m_dir;
    const CdBody* m_bodyA;
    void* m_param4;
    int  m_unk48;
    int  m_unk4c;
};

void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(const CdBody& bodyA, const CdBody& bodyB, const Input9bb7d0& input, void* collector);

static __forceinline void xformPos9bb7d0(Vec9bb7d0& out, const Transform& t, const Vec4& v)
{
    const Rotation& r = t.getRotation();
    const Vec4& tr = t.getTranslation();
    Real v0 = v.x;
    Real v1 = v.y;
    Real v2 = v.z;
    out.x = r.m_col0.x * v0 + r.m_col1.x * v1 + r.m_col2.x * v2 + tr.x;
    out.y = r.m_col0.y * v0 + r.m_col1.y * v1 + r.m_col2.y * v2 + tr.y;
    out.z = r.m_col0.z * v0 + r.m_col1.z * v1 + r.m_col2.z * v2 + tr.z;
    out.w = 0.0f;
}

// pdb: hkpHeightFieldAgent::staticLinearCast | hkpHeightFieldAgent.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpHeightFieldAgent_staticLinearCast(const CdBody& bodyA, const CdBody& bodyB, const Input9bb7d0& input,
                          void* param4, void* param5)
{
    {
        Monitor& mStream = Monitor::getInstance();
        if ( mStream.memoryAvailable() )
        {
            Monitor::TimerBeginListCommand* h = reinterpret_cast<Monitor::TimerBeginListCommand*>( mStream.getEnd() );
            h->m_commandAndMonitor = "LtHeightField";
            h->m_nameOfFirstSplit = "StClosestPoints";
            h->setTime();
            mStream.setEnd( (char*)( h + 1 ) );
        }
    }

    if ( param5 )
    {
        hkpHeightFieldAgent_staticGetClosestPoints( bodyA, bodyB, input, param5 );
    }

    {
        Monitor& mStream = Monitor::getInstance();
        if ( mStream.memoryAvailable() )
        {
            Monitor::TimerCommand* h = reinterpret_cast<Monitor::TimerCommand*>( mStream.getEnd() );
            h->m_commandAndMonitor = "StGetSpheres";
            h->setTime();
            mStream.setEnd( (char*)( h + 1 ) );
        }
    }

    const Shape9bb7d0A* bvA = reinterpret_cast<const Shape9bb7d0A*>( bodyA.getShape() );
    const Shape9bb7d0B* bvB = reinterpret_cast<const Shape9bb7d0B*>( bodyB.getShape() );

    Transform aTb;
    aTb.FUN_00925300( bodyB.getTransform(), bodyA.getTransform() );

    const int numSpheres = bvA->v24();

    Vec4* spheres = allocStack<Vec4>( numSpheres );

    Vec4 dir;
    dir.rotInvDir( bodyB.getTransform().getRotation(), input.m_vec50 );

    const Vec4* verts = bvA->v28( spheres );

    {
        Monitor& mStream = Monitor::getInstance();
        if ( mStream.memoryAvailable() )
        {
            Monitor::TimerCommand* h = reinterpret_cast<Monitor::TimerCommand*>( mStream.getEnd() );
            h->m_commandAndMonitor = "StCastSpheres";
            h->setTime();
            mStream.setEnd( (char*)( h + 1 ) );
        }
    }

    {
    SphereInfo9bb7d0 info;
    info.m_tolerance = input.m_f60;
    info.m_unk20 = 0;
    info.m_unk24 = 0;

    SphereCollector9bb7d0 collector;
    collector.m_tolerance = 1.0f;
    collector.m_dir = *(const Vec9bb7d0*)&input.m_vec50;
    collector.m_bodyA = &bodyA;
    collector.m_param4 = param4;

    if ( numSpheres > 0 )
    {
        int remaining = numSpheres;
        do
        {
            xformPos9bb7d0( info.m_pos, aTb, *verts );
            info.m_radius = verts->w;
            info.m_vel.x = dir.x + info.m_pos.x;
            info.m_vel.y = info.m_pos.y + dir.y;
            info.m_vel.z = info.m_pos.z + dir.z;
            info.m_vel.w = info.m_pos.w + dir.w;
            xformPos9bb7d0( collector.m_pos, bodyA.getTransform(), *verts );
            collector.m_radius = verts->w;
            bvB->v28( info.m_pos, bodyB, &collector );
            verts++;
        } while ( --remaining );
    }
    }

    freeStack( spheres );

    {
        Monitor& mStream = Monitor::getInstance();
        if ( mStream.memoryAvailable() )
        {
            Monitor::TimerCommand* h = reinterpret_cast<Monitor::TimerCommand*>( mStream.getEnd() );
            h->m_commandAndMonitor = "lt";
            h->setTime();
            mStream.setEnd( (char*)( h + 1 ) );
        }
    }
}

} // namespace N9bb7d0
}   // namespace f3m_009bb7d0

// @f3 0x009a2230 (community match, verified in this file)
#include <math.h>
namespace f3m_009a2230 {
// 0x009a2230: hkpCapsuleShape::closestInfLineSegInfLineSeg(const hkVector4& A, const hkVector4& dA,
// const hkVector4& B, const hkVector4& dB, hkReal& distSquared, hkReal& t, hkReal& u, hkVector4& p, hkVector4& q)
// of Havok 5.5.0 (hkpCollide, a static member, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The closest points of two infinite lines A + t * dA and B + u * dB: t from the 2x2 system of the dot products
// (zero when the lines are nearly parallel, i.e. the determinant is within a relative epsilon), u from t, then
// the two points, their difference and its squared length.
// Class and member names follow the Havok 5.5.0 SDK headers; the vector helpers (setSub4, dot3, addMul4,
// lengthSquared3, the assignment) and hkMath::fabs follow the SDK's inline code for the x87 build. The locals,
// their names and the statement order are those of the SDK's unoptimized library object of this function.

namespace f3m_009a2230 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath {
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared3() const;

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x += r * a.x;
    y += r * a.y;
    z += r * a.z;
    w += r * a.w;
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}

struct hkpCapsuleShape
{
    static void __cdecl FUN_009a2230(const hkVector4& A, const hkVector4& dA, const hkVector4& B,
                                     const hkVector4& dB, hkReal& distSquared, hkReal& t, hkReal& u, hkVector4& p,
                                     hkVector4& q);
};

void __cdecl hkpCapsuleShape::FUN_009a2230(const hkVector4& A, const hkVector4& dA, const hkVector4& B,
                                           const hkVector4& dB, hkReal& distSquared, hkReal& t, hkReal& u,
                                           hkVector4& p, hkVector4& q)
{
    hkVector4 d12;
    d12.setSub4(B, A);
    hkReal R = dA.dot3(dB);

    hkReal S1 = dA.dot3(d12);
    hkReal S2 = dB.dot3(d12);

    hkReal D1 = dA.dot3(dA);
    hkReal D2 = dB.dot3(dB);

    // the determinant of the 2x2 system, and the threshold below which the lines count as parallel
    hkReal denom = D1 * D2 - R * R;
    hkReal eps = (R * R + hkMath::fabs(D1 * D2)) * 9.5367431640625e-07f;

    if (hkMath::fabs(denom) > eps)
    {
        t = (S1 * D2 - S2 * R) / denom;
    }
    else
    {
        t = 0.0f;
    }

    u = (t * R - S2) / D2;

    hkVector4 a;
    a = A; a.addMul4(t, dA);
    hkVector4 b;
    b = B; b.addMul4(u, dB);
    hkVector4 diff;
    diff.setSub4(a, b);

    p = a;
    q = b;

    distSquared = diff.lengthSquared3();
}

}  // namespace f3m_009a2230
}   // namespace f3m_009a2230

// @f3 0x009bf990 (community match, verified in this file)
namespace f3m_009bf990 {
// 0x009bf990: hkpMultiRayConvexAgent::staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, a static member,
// compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Casts each ray of the multi-ray shape A against the convex shape B (in B's space) and reports every hit to the
// collector as a contact point in world space, its distance measured along the ray from the ray's end. A timer
// brackets it.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names. The clock read in hkMonitorStream::TimerCommand::setTime is the SDK's own
// two-instruction block, the one the kit accepts.
namespace f3m_009bf990 {

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
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline hkInplaceArray(const hkInplaceArray<T,N>& a);
		__forceinline ~hkInplaceArray(){}
		hkArray<T>& operator= (const hkArray<T>& a);
		hkArray<T>& operator= (const hkInplaceArray<T,N>& a);
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		inline hkBool wasReallocated() const;
		inline int stillInplaceUsingMask() const;
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
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
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
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
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
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
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
class hkMonitorStream
{
	public:
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		void __cdecl reset();
		void __cdecl resize( int newSize );
	public:
		__forceinline char* __cdecl getStart() { return m_start.val(); }
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* __cdecl getCapacity() { return m_capacity.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline int __cdecl getCurrentMonitorDataSize()
		{
			return (int)(m_end.val() - m_start.val());
		}
		__forceinline void* __cdecl expandby( int size ) { char* h = m_end.val(); char* newEnd = h + size; m_end = newEnd; return h; }
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
		__forceinline hkBool __cdecl isBufferAllocatedOnTheHeap() { return m_isBufferAllocatedOnTheHeap; }
		void __cdecl setStaticBuffer( char* buffer, int bufferSize );
	public:
		static void __cdecl init();
		void __cdecl quit();
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};
void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
}
class hkMotionState;
class hkAabb;
class hkSphere;
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
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
hkBool hkpShape::castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const
{
	return castRayImpl( input, output );
}
struct hkpShapeRayCastCollectorOutput
{
	inline hkpShapeRayCastCollectorOutput();
	inline hkBool hasHit() const;
	inline void reset();
	hkVector4 m_normal;
	hkReal m_hitFraction;
	int m_extraInfo;
	int m_pad[2];
};
void hkpShapeRayCastCollectorOutput::reset( )
{
	m_hitFraction = 1.0f;
	m_extraInfo = -1;
}
hkpShapeRayCastCollectorOutput::hkpShapeRayCastCollectorOutput()
{
	reset();
}
struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
	public:
		enum { MAX_HIERARCHY_DEPTH = 8 };
	public:
		__forceinline hkpShapeRayCastOutput();
		__forceinline void changeLevel(int delta);
		__forceinline void setKey(hkpShapeKey key);
		__forceinline void reset();
	private:
		__forceinline void _reset();
	public:
		hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
	private:
		int m_shapeKeyIndex;
};
void hkpShapeRayCastOutput::_reset()
{
	m_shapeKeyIndex = 0;
	m_shapeKeys[0] = 0xffffffff;
}
hkpShapeRayCastOutput::hkpShapeRayCastOutput()
{
	_reset();
}
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
const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
class hkpCollisionDispatcher;
class hkpConstraintOwner;
class hkpContactMgr;
struct hkpCdPoint
{
	hkpCdPoint( const hkpCdBody& a, const hkpCdBody& b ) : m_cdBodyA(a), m_cdBodyB(b) {}
	hkContactPoint m_contact;
	const hkpCdBody& m_cdBodyA;
	const hkpCdBody& m_cdBodyB;
};
class hkpCdPointCollector
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCdPointCollector), HK_MEMORY_CLASS_AGENT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkpCdPointCollector();
		inline virtual ~hkpCdPointCollector();
		virtual void addCdPoint( const hkpCdPoint& point ) = 0;
		inline void reset();
		inline hkReal getEarlyOutDistance( ) const;
	protected:
		hkReal m_earlyOutDistance;
};
struct hkpCollisionInput;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpLinearCastCollisionInput;
class hkpCdBodyPairCollector;
class hkpCollisionAgent : public hkReferencedObject
{
	public:
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner ) {}
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
		virtual void removePoint( hkContactPointId idToRemove );
		virtual void commitPotential( hkContactPointId newId );
		virtual void createZombie( hkContactPointId idTobecomeZombie );
	protected:
		inline virtual ~hkpCollisionAgent();
		inline hkpCollisionAgent( hkpContactMgr* contactMgr );
	protected:
		hkpContactMgr* m_contactMgr;
	public:
		inline hkpContactMgr* getContactMgr();
};
class hkpIterativeLinearCastAgent : public hkpCollisionAgent
{
	public:
		hkpIterativeLinearCastAgent(hkpContactMgr* contactMgr): hkpCollisionAgent(contactMgr){}
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		static void __cdecl staticLinearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		__forceinline ~hkpIterativeLinearCastAgent(){}
};
class hkpMultiRayConvexAgent : public hkpIterativeLinearCastAgent
{
    public:
        static void __cdecl registerAgent(hkpCollisionDispatcher* dispatcher);
        virtual inline void processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		static void __cdecl staticGetPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, class hkpCdPointCollector& collector  );
		static void __cdecl hkpMultiRayConvexAgent_staticGetClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, class hkpCdPointCollector& collector  );
		virtual void cleanup( hkpConstraintOwner& constraintOwner );
	protected:
		hkpMultiRayConvexAgent(const  hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
        static hkpCollisionAgent* __cdecl createMultiRayConvexAgent( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr);
		static hkpCollisionAgent* __cdecl createConvexMultiRayAgent( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr);
	protected:
		struct ContactPointInfo
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMultiRayConvexAgent::ContactPointInfo), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkContactPointId m_contactPointId;
		};
		hkInplaceArray<ContactPointInfo,4> m_contactInfo;
};
class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline int getNumCollisionSpheres( )  const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
	public:
		hkpSphereRepShape( hkpShapeType type ) : hkpShape( type ) {}
		hkpSphereRepShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_SPHERE_REP; }
};
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		inline void setRadius(hkReal radius);
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline hkpConvexShape::WeldResult weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
																	hkVector4& contactPointWs, const hkTransform* thisObjTransform,
																	const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		__forceinline void getCentre( hkVector4& centreOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		inline hkpConvexShape( hkpShapeType type, hkReal radius );
		hkReal m_radius;
	public:
		hkpConvexShape( hkFinishLoadedObjectFlag flag ) : hkpSphereRepShape(flag) { m_type = HK_SHAPE_CONVEX; }
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
 		void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out  ) const;
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
class hkpRayShapeCollectionFilter;
struct hkpShapeRayCastInput
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShapeRayCastInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline hkpShapeRayCastInput();
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};
inline hkpShapeRayCastInput::hkpShapeRayCastInput()
:	m_filterInfo(0),
	m_rayShapeCollectionFilter( 0 )
{
}
// pdb: hkpMultiRayConvexAgent::staticGetClosestPoints | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void __cdecl hkpMultiRayConvexAgent::hkpMultiRayConvexAgent_staticGetClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector )
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "T" "t" "multiRay-cvx"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	const hkpMultiRayShape* msA = static_cast<const hkpMultiRayShape*>(bodyA.getShape());
	const hkpConvexShape* convexB = static_cast<const hkpConvexShape*>(bodyB.getShape());
	hkTransform bTa; bTa.setMulInverseMul( bodyB.getTransform(), bodyA.getTransform() );
	const hkArray<hkpMultiRayShape::Ray>& RaysA = msA->getRays();
	int nRays = RaysA.getSize();
	const hkpMultiRayShape::Ray* rayA = RaysA.begin();
	hkpCdPoint event( bodyA, bodyB );
	hkpShapeRayCastInput rayInput;
	for (int i = 0; i < nRays; i++)
	{
		hkpShapeRayCastOutput rayResults;
		rayInput.m_from._setTransformedPos( bTa, rayA->m_start );
		rayInput.m_to._setTransformedPos( bTa, rayA->m_end );
		hkBool rayHit = convexB->castRay( rayInput, rayResults );
		if ( rayHit )
		{
			const hkVector4& normal = rayResults.m_normal;
			const hkReal dist = rayResults.m_hitFraction;
			hkVector4 hitpoint; hitpoint.setInterpolate4( rayInput.m_from, rayInput.m_to, dist );
			event.m_contact.getPosition()._setTransformedPos( bodyB.getTransform(), hitpoint );
			event.m_contact.getSeparatingNormal()._setRotatedDir( bodyB.getTransform().getRotation(), normal );
			event.m_contact.setDistance( ( dist - 1.0f ) * rayA->m_start(3) + msA->getRayPenetrationDistance() );
			collector.addCdPoint( event );
		}
		rayA++;
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
}

}  // namespace f3m_009bf990
}   // namespace f3m_009bf990

// @f3 0x009b7950 (community match, verified in this file)
#include <windows.h>
namespace f3m_009b7950 {

// 0x009b7950: linear cast of body A against a MOPP tree body B (hkpMoppAgent::staticLinearCast in Havok terms).
// The box of A is taken in B's space, swept along the cast path, and handed to the tree's box-cast machine.

namespace MoppLinearCast9B7950 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern DWORD DAT_0116913c;      // TLS slot of the per-thread monitor stream

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

// a scalar as the vector functions take it
class hkSimdReal
{
public:
    __forceinline hkSimdReal(hkReal r) : m_real(r) {}
    __forceinline operator hkReal() const { return m_real; }

    hkReal m_real;
};

struct hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    __forceinline void setAll(const hkSimdReal& a)
    {
        hkReal r = a;
        x = r;
        y = r;
        z = r;
        w = r;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void mul4(hkReal s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    // this = a + t * (b - a), as a weighted sum
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, hkReal t)
    {
        hkReal s = 1.0f - t;
        x = t * b.x + s * a.x;
        y = s * a.y + t * b.y;
        z = t * b.z + s * a.z;
        w = t * b.w + s * a.w;
    }
    // this = r^-1 * b
    void FUN_00477880(const hkRotation& r, const hkVector4& b);

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
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    // this = a^-1 * b
    void FUN_00925300(const hkTransform& a, const hkTransform& b);
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline const hkpShape* getShape() const { return m_shape; }
};

struct hkpLinearCastCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;
    int unk08[18];
    hkVector4 m_path;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpCdPointCollector;

class hkpMoppAabbCastVirtualMachine
{
public:
    struct hkpAabbCastInput
    {
        hkVector4 m_from;
        hkVector4 m_to;
        hkVector4 m_extents;
        const hkpLinearCastCollisionInput* m_collisionInput;
        const hkpCdBody* m_castBody;
        const hkpCdBody* m_moppBody;
    };

    // aabbCast
    void FUN_00a2e7f0(const hkpAabbCastInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector);

    int unk00[4];
    const void* m_code;
    hkReal m_itoFScale;
    int unk18;
    hkReal m_earlyOutFraction;
    hkReal m_refEarlyOutFraction;
    hkpCdPointCollector* m_castCollector;
    hkpCdPointCollector* m_startPointCollector;
    const hkpAabbCastInput* m_input;
    int unk30;
};

// pdb: hkpMoppAgent::staticLinearCast | hkpMoppAgent.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpMoppAgent_staticLinearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtMopp";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpMoppAabbCastVirtualMachine machine;
    hkpMoppAabbCastVirtualMachine::hkpAabbCastInput ai;
    {
        // the box of A in the space of B, the tree
        hkTransform bTa;
        bTa.FUN_00925300(bodyB.getTransform(), bodyA.getTransform());
        hkAabb aabb;
        bodyA.getShape()->getAabb(bTa, input.getTolerance(), aabb);

        // the cast path in the space of B
        hkVector4 pathB;
        pathB.FUN_00477880(bodyB.getTransform().getRotation(), input.m_path);
        const hkReal pathY = pathB.y;

        // sweep the centre of the box along the path; the extents are half the box
        ai.m_castBody = &bodyA;
        ai.m_moppBody = &bodyB;
        ai.m_from.setInterpolate4(aabb.m_min, aabb.m_max, 0.5f);
        ai.m_to.x = ai.m_from.x + pathB.x;
        ai.m_to.y = ai.m_from.y + pathY;
        ai.m_to.z = ai.m_from.z + pathB.z;
        ai.m_to.w = ai.m_from.w + pathB.w;
        ai.m_extents.setSub4(aabb.m_max, aabb.m_min);
        ai.m_extents.mul4(0.5f);
        ai.m_collisionInput = &input;

        // widen the box by the tolerance
        hkVector4 tol4;
        tol4.setAll(input.m_tolerance);
        ai.m_extents.add4(tol4);
    }
    machine.FUN_00a2e7f0(ai, collector, startCollector);

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009b7950

// @f3 0x009baf20 (community match, verified in this file)
#include <windows.h>
namespace f3m_009baf20 {

// 0x009baf20: do the collision spheres of body A touch the height field of body B
// (hkpHeightFieldAgent::staticGetPenetrations in Havok terms). The spheres are moved into the height field's space,
// collided against it in one call, and the pair is reported as soon as one sphere is found below the surface.

namespace HeightFieldPenetrations9BAF20 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern DWORD DAT_0116913c;      // TLS slot of the per-thread monitor stream
extern DWORD DAT_010f3170;      // TLS slot of the per-thread memory manager

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
    struct TimerBeginListCommand : public TimerCommand
    {
        const char* m_nameOfFirstSplit;
    };
};

// per-thread memory manager with a stack for short-lived buffers
class hkThreadMemory
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void* onStackOverflow(int numBytes);
    virtual void onStackUnderflow(void* p);

    static __forceinline hkThreadMemory& getInstance() { return *static_cast<hkThreadMemory*>(TlsGetValue(DAT_010f3170)); }

    __forceinline void* allocateStack(int numBytes)
    {
        char* current = m_stackCurrent;
        char* next = current + numBytes;
        if (next <= m_stackEnd)
        {
            m_stackCurrent = next;
            return current;
        }
        return onStackOverflow(numBytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = static_cast<char*>(p);
        if (p == m_stackBase)
        {
            onStackUnderflow(p);
        }
    }

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    char* m_stackPrev;
    char* m_stackBase;
    char* m_stackEnd;
};

template <typename T>
__forceinline T* hkAllocateStack(int n)
{
    return static_cast<T*>(hkThreadMemory::getInstance().allocateStack((n * sizeof(T) + 16) & ~15));
}

template <typename T>
__forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkTransform
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;

    // this = a^-1 * b
    void FUN_00925300(const hkTransform& a, const hkTransform& b);
};

// centre in x, y, z and radius in w
class hkSphere
{
public:
    hkVector4 m_pos;
};

// moves spheres by a transform (from a copy, so the output may overlap it); the radius is carried over
__forceinline void transformSpheres(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased;
    unaliased.m_col0 = t.m_col0;
    unaliased.m_col1 = t.m_col1;
    unaliased.m_col2 = t.m_col2;
    unaliased.m_translation = t.m_translation;
    int i = numVectors - 1;
    do
    {
        hkVector4 v;
        hkReal v0 = vectorsIn[i].x;
        hkReal v1 = vectorsIn[i].y;
        hkReal v2 = vectorsIn[i].z;
        v.x = unaliased.m_col0.x * v0 + unaliased.m_col1.x * v1 + unaliased.m_col2.x * v2 + unaliased.m_translation.x;
        v.y = unaliased.m_col0.y * v0 + unaliased.m_col1.y * v1 + unaliased.m_col2.y * v2 + unaliased.m_translation.y;
        v.z = unaliased.m_col0.z * v0 + unaliased.m_col1.z * v1 + unaliased.m_col2.z * v2 + unaliased.m_translation.z;
        v.w = vectorsIn[i].w;
        vectorsOut[i] = v;
    } while (--i >= 0);
}

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
};

class hkpSphereRepShape : public hkpShape
{
public:
    virtual int getNumCollisionSpheres() const;
    virtual const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) const;
};

class hkpHeightFieldShape : public hkpShape
{
public:
    struct CollideSpheresInput
    {
        const hkSphere* m_spheres;
        int m_numSpheres;
        hkReal m_tolerance;
    };
    // normal in x, y, z and distance in w
    typedef hkVector4 SphereCollisionOutput;

    virtual void collideSpheres(const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const;
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline const hkpShape* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpCdBodyPairCollector
{
public:
    virtual void vf00();
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};

// pdb: hkpHeightFieldAgent::staticGetPenetrations | hkpHeightFieldAgent.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpHeightFieldAgent_staticGetPenetrations(const hkpCdBody& csBody, const hkpCdBody& hfBody, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "LtHeightField";
            h->m_nameOfFirstSplit = "StGetSpheres";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    const hkpSphereRepShape* csShape = static_cast<const hkpSphereRepShape*>(csBody.getShape());
    const hkpHeightFieldShape* hfShape = static_cast<const hkpHeightFieldShape*>(hfBody.getShape());

    hkTransform bTa;
    bTa.FUN_00925300(hfBody.getTransform(), csBody.getTransform());

    const int numSpheres = csShape->getNumCollisionSpheres();
    hkSphere* sphereBuffer = hkAllocateStack<hkSphere>(numSpheres);

    // the spheres of A, moved into the space of the height field
    {
        const hkSphere* spheres = csShape->getCollisionSpheres(sphereBuffer);
        transformSpheres(bTa, &spheres->m_pos, numSpheres, &sphereBuffer->m_pos);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "StCollide";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpHeightFieldShape::SphereCollisionOutput* out0 = hkAllocateStack<hkpHeightFieldShape::SphereCollisionOutput>(numSpheres);
    {
        hkpHeightFieldShape::CollideSpheresInput in0;
        in0.m_spheres = &sphereBuffer[0];
        in0.m_numSpheres = numSpheres;
        in0.m_tolerance = input.getTolerance();

        hfShape->collideSpheres(in0, out0);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "StExamine";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    // a negative distance means the sphere is below the surface
    {
        hkpHeightFieldShape::SphereCollisionOutput* outP = out0;
        for (int i = numSpheres - 1; i >= 0; i--)
        {
            if (outP[0](3) < 0.0f)
            {
                collector.addCdBodyPair(csBody, hfBody);
                break;
            }
            outP++;
        }
    }

    hkDeallocateStack(out0);
    hkDeallocateStack(sphereBuffer);

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "lt";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009baf20

// @f3 0x009bf5c0 (community match, verified in this file)
#include <windows.h>
namespace f3m_009bf5c0 {

// 0x009bf5c0: closest points between a multi-ray shape (body A) and a convex shape (body B)
// (hkpMultiRayConvexAgent::getClosestPoints in Havok terms). Each ray is moved into B's space and cast against B;
// a hit becomes a contact point at the hit position, with the ray's remaining length as the distance.

namespace MultiRayConvex9BF5C0 {

typedef float hkReal;
typedef unsigned int hkUint32;
typedef unsigned int hkpShapeKey;

extern DWORD DAT_0116913c;      // TLS slot of the per-thread monitor stream

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};


class hkBool
{
public:
    __forceinline operator bool() const { return m_bool != 0; }

    char m_bool;
};

struct hkRotation;
struct hkTransform;

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    // this = r * b
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& b);
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);

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
    // this = a^-1 * b
    void FUN_00925300(const hkTransform& a, const hkTransform& b);
};

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

struct hkpShapeRayCastInput
{
    __forceinline hkpShapeRayCastInput()
    {
        m_filterInfo = 0;
        m_rayShapeCollectionFilter = 0;
    }

    hkVector4 m_from;
    hkVector4 m_to;
    hkUint32 m_filterInfo;
    const void* m_rayShapeCollectionFilter;
};

struct hkpShapeRayCastCollectorOutput
{
    __forceinline void reset()
    {
        m_hitFraction = 1.0f;
        m_extraInfo = -1;
    }

    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
    hkUint32 m_pad[2];
};

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
    __forceinline hkpShapeRayCastOutput() { reset(); }
    __forceinline void reset()
    {
        hkpShapeRayCastCollectorOutput::reset();
        m_shapeKeyIndex = 0;
        m_shapeKeys[0] = 0xffffffff;
    }

    hkpShapeKey m_shapeKeys[8];
    int m_shapeKeyIndex;
};

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual hkBool castRay(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;

    int m_memSizeAndFlags;
    void* m_userData;
    int m_type;
};

class hkpMultiRayShape : public hkpShape
{
public:
    // the length of a ray is kept in m_start(3)
    struct Ray
    {
        hkVector4 m_start;
        hkVector4 m_end;
    };

    Ray* m_rays;
    int m_numRays;
    int m_raysCapacityAndFlags;
    hkReal m_rayPenetrationDistance;
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    hkpShapeKey m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline const hkpShape* getShape() const { return m_shape; }
};

struct hkContactPoint
{
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& point);
};

struct hkpCollisionInput;

class hkpMultiRayConvexAgent
{
public:
    void hkpMultiRayConvexAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector);
};

// pdb: hkpMultiRayConvexAgent::getClosestPoints | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpMultiRayConvexAgent::hkpMultiRayConvexAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtmultiRay-cvx";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    const hkpMultiRayShape* msA = static_cast<const hkpMultiRayShape*>(bodyA.getShape());
    const hkpShape* convexB = bodyB.getShape();

    hkTransform bTa;
    bTa.FUN_00925300(bodyB.getTransform(), bodyA.getTransform());

    const hkpMultiRayShape::Ray* rayA = msA->m_rays;
    const int numRays = msA->m_numRays;

    hkpCdPoint event(bodyA, bodyB);
    hkpShapeRayCastInput rayInput;
    for (int i = 0; i < numRays; i++)
    {
        hkpShapeRayCastOutput rayResults;

        // the ray in the space of B
        rayInput.m_from._setTransformedPos(bTa, rayA->m_start);
        rayInput.m_to._setTransformedPos(bTa, rayA->m_end);

        hkBool rayHit = convexB->castRay(rayInput, rayResults);
        if (rayHit)
        {
            // where the ray hit, in the space of B
            hkVector4 hitpoint;
            const hkReal t = rayResults.m_hitFraction;
            const hkReal s = 1.0f - t;
            hitpoint.x = s * rayInput.m_from.x + t * rayInput.m_to.x;
            hitpoint.y = s * rayInput.m_from.y + t * rayInput.m_to.y;
            hitpoint.z = s * rayInput.m_from.z + t * rayInput.m_to.z;
            hitpoint.w = s * rayInput.m_from.w + t * rayInput.m_to.w;

            event.m_contact.m_position._setTransformedPos(bodyB.getTransform(), hitpoint);
            event.m_contact.m_separatingNormal._setRotatedDir(bodyB.getTransform().getRotation(), rayResults.m_normal);
            event.m_contact.setDistance((rayResults.m_hitFraction - 1.0) * rayA->m_start(3) + msA->m_rayPenetrationDistance);

            collector.addCdPoint(event);
        }
        rayA++;
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009bf5c0

// @f3 0x009a7a80 (community match, verified in this file)
#include <math.h>
namespace f3m_009a7a80 {

// 0x009a7a80: the world-space box of an oriented box given by its transform, half extents and centre, grown by a
// radius (hkAabbUtil::calcAabb in Havok terms).

namespace CalcAabb9A7A80 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
}

struct hkTransform;

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
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);

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

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

void __cdecl FUN_009a7a80(const hkTransform& localToWorld, const hkVector4& halfExtents, const hkVector4& center, hkReal extraRadius, hkAabb& aabbOut)
{
    hkVector4 he0;
    he0.setBroadcast(halfExtents, 0);
    hkVector4 he1;
    he1.setBroadcast(halfExtents, 1);
    hkVector4 he2;
    he2.setBroadcast(halfExtents, 2);

    // the box's half extents along each world axis
    hkVector4 c0;
    c0.setMul4(he0, localToWorld.getColumn(0));
    hkVector4 c1;
    c1.setMul4(he1, localToWorld.getColumn(1));
    hkVector4 c2;
    c2.setMul4(he2, localToWorld.getColumn(2));

    c0.setAbs4(c0);
    c1.setAbs4(c1);
    c2.setAbs4(c2);

    hkVector4 extra;
    extra.setAll(extraRadius);
    c2.add4(extra);

    hkVector4 max;
    max.setAdd4(c1, c0);
    max.add4(c2);

    hkVector4 min;
    min.setNeg4(max);

    hkVector4 centerWs;
    centerWs._setTransformedPos(localToWorld, center);
    max.add4(centerWs);
    min.add4(centerWs);

    aabbOut.m_max = max;
    aabbOut.m_min = min;
}

}
}   // namespace f3m_009a7a80

// @f3 0x009bb290 (community match, verified in this file)
namespace f3m_009bb290 {
// 0x009bb290: hkpHeightFieldAgent::staticGetClosestPoints(const hkpCdBody& csBody, const hkpCdBody& hfBody,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Closest points between a shape made of spheres and a height field: the spheres are taken from the shape, moved
// into the height field's space, collided with the height field, and every sphere whose distance is within the
// collision tolerance gives one point (position and normal in world space, distance) to the collector. Timed with
// the SDK's monitor-stream timers (HeightField: bTA, getSpheres, transform, collide, examine).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. Its only assembly is the SDK's own
// two-instruction clock read in hkMonitorStream::TimerCommand::setTime (the project's accepted timer block; the
// plain __rdtsc() form does not give the original's code). The function body follows the SDK's unoptimized (hybrid)
// library object of this function statement by statement, and built with the SDK's headers it reproduces both that
// object and the release object. Only the function itself carries the packet's name; its callees keep the SDK's
// names.
namespace f3m_009bb290 {

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
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
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
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
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
__forceinline void hkVector4::setW(const hkVector4& v)
{
	w = v.w;
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
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
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
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
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
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
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkMonitorStream
{
	public:
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		void __cdecl reset();
		void __cdecl resize( int newSize );
	public:
		__forceinline char* __cdecl getStart() { return m_start.val(); }
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* __cdecl getCapacity() { return m_capacity.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline int __cdecl getCurrentMonitorDataSize()
		{
			return (int)(m_end.val() - m_start.val());
		}
		__forceinline void* __cdecl expandby( int size ) { char* h = m_end.val(); char* newEnd = h + size; m_end = newEnd; return h; }
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
		__forceinline hkBool __cdecl isBufferAllocatedOnTheHeap() { return m_isBufferAllocatedOnTheHeap; }
		void __cdecl setStaticBuffer( char* buffer, int bufferSize );
	public:
		static void __cdecl init();
		void __cdecl quit();
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};
void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
}
class hkMotionState;
class hkAabb;
class hkSphere
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSphere();
		inline hkSphere(const hkVector4& pt, hkReal radius);
		inline hkReal getRadius() const;
		inline void setRadius(hkReal newRadius);
		inline const hkVector4& getPosition() const;
		inline const hkVector4& getPositionAndRadius() const;
		inline hkVector4& getPositionAndRadius();
		inline void setPosition(const hkVector4& newPos);
		inline void setPositionAndRadius( const hkVector4& newPos );
	protected:
		hkVector4 m_pos;
};
inline hkReal hkSphere::getRadius() const
{
	return m_pos(3);
}
inline const hkVector4& hkSphere::getPosition() const
{
	return m_pos;
}
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
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
const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
class hkpConstraintOwner;
class hkpContactMgr;
struct hkpCdPoint
{
	hkpCdPoint( const hkpCdBody& a, const hkpCdBody& b ) : m_cdBodyA(a), m_cdBodyB(b) {}
	hkContactPoint m_contact;
	const hkpCdBody& m_cdBodyA;
	const hkpCdBody& m_cdBodyB;
};
class hkpCdPointCollector
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCdPointCollector), HK_MEMORY_CLASS_AGENT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkpCdPointCollector();
		inline virtual ~hkpCdPointCollector();
		virtual void addCdPoint( const hkpCdPoint& point ) = 0;
		inline void reset();
		inline hkReal getEarlyOutDistance( ) const;
	protected:
		hkReal m_earlyOutDistance;
};
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpLinearCastCollisionInput;
class hkpCdBodyPairCollector;
class hkpCollisionAgent : public hkReferencedObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_AGENT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_AGENT); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner ) {}
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
		virtual void removePoint( hkContactPointId idToRemove );
		virtual void commitPotential( hkContactPointId newId );
		virtual void createZombie( hkContactPointId idTobecomeZombie );
	protected:
		inline virtual ~hkpCollisionAgent();
		inline hkpCollisionAgent( hkpContactMgr* contactMgr );
	protected:
		hkpContactMgr* m_contactMgr;
	public:
		inline hkpContactMgr* getContactMgr();
};
class hkpHeightFieldAgent : public hkpCollisionAgent
{
	public:
		static void __cdecl registerAgent(hkpCollisionDispatcher* dispatcher);
        virtual inline void processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
		virtual void getPenetrations(const  hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		static void __cdecl staticGetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector);
		static void __cdecl hkpHeightFieldAgent_staticGetClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, class hkpCdPointCollector& collector  );
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		static void __cdecl staticLinearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		virtual void cleanup( hkpConstraintOwner& constraintOwner );
	protected:
		hkpHeightFieldAgent(const hkpCdBody& A,const  hkpCdBody& B,const  hkpCollisionInput& input, hkpContactMgr* mgr);
		~hkpHeightFieldAgent(){}
	protected:
		static hkpCollisionAgent* __cdecl createHeightFieldAAgent( const hkpCdBody& A, const hkpCdBody& B, const hkpCollisionInput& input, hkpContactMgr* mgr );
		static hkpCollisionAgent* __cdecl createHeightFieldBAgent( const hkpCdBody& A, const hkpCdBody& B, const hkpCollisionInput& input, hkpContactMgr* mgr );
		hkArray<hkContactPointId> m_contactPointId;
};
namespace hkVector4Util
{
__forceinline void __cdecl transformSpheres( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::transformSpheres( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	;
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		hkVector4 v;
		v._setTransformedPos( unaliased, vectorsIn[i] );
		v.setW(vectorsIn[i]);
		vectorsOut[i] = v;
	} while( --i >= 0 );
}
class hkpRayShapeCollectionFilter;
struct hkpShapeRayCastInput
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShapeRayCastInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline hkpShapeRayCastInput();
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};
class hkpHeightFieldShape: public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct CollideSpheresInput
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpHeightFieldShape::CollideSpheresInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			class hkSphere* m_spheres;
			int		  m_numSpheres;
			hkReal	  m_tolerance;
		};
		typedef hkVector4 SphereCollisionOutput;
		virtual void collideSpheres( const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const = 0;
		struct hkpSphereCastInput: public hkpShapeRayCastInput
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpHeightFieldShape::hkpSphereCastInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkReal m_radius;
			hkReal m_maxExtraPenetration;
		};
		virtual void castSphere( const hkpSphereCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
	public:
		hkpHeightFieldShape( hkpShapeType type ) : hkpShape( type ) {}
	public:
		hkpHeightFieldShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_HEIGHT_FIELD; }
};
class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline int getNumCollisionSpheres( )  const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
	public:
		hkpSphereRepShape( hkpShapeType type ) : hkpShape( type ) {}
		hkpSphereRepShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_SPHERE_REP; }
};
int hkpSphereRepShape::getNumCollisionSpheres( )  const
{
	return this->getNumCollisionSpheresImpl(  );
}
const hkSphere* hkpSphereRepShape::getCollisionSpheres( hkSphere* sphereBuffer ) const
{
	return this->getCollisionSpheresImpl( sphereBuffer );
}
// pdb: hkpHeightFieldAgent::staticGetClosestPoints | hkpHeightFieldAgent.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkpHeightFieldAgent::hkpHeightFieldAgent_staticGetClosestPoints( const hkpCdBody& csBody, const hkpCdBody& hfBody, const hkpCollisionInput& input, hkpCdPointCollector& collector )
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "L" "t" "HeightField"; h->m_nameOfFirstSplit = "S" "t" "bTA"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	const hkpSphereRepShape* csShape = static_cast<const hkpSphereRepShape*>(csBody.getShape());
	const hkpHeightFieldShape* hfShape = static_cast<const hkpHeightFieldShape*>(hfBody.getShape());
	hkTransform bTa; bTa.setMulInverseMul( hfBody.getTransform(), csBody.getTransform() );
	const int numSpheres = csShape->getNumCollisionSpheres();
	hkSphere* sphereBuffer = hkAllocateStack<hkSphere>(numSpheres);
	{
		{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "getSpheres"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
		const hkSphere* spheres = csShape->getCollisionSpheres( sphereBuffer );
		{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "transform"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
		hkVector4Util::transformSpheres( bTa, &spheres[0].getPosition(), numSpheres, reinterpret_cast<hkVector4*>(sphereBuffer) );
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "collide"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	hkVector4* out2 = hkAllocateStack<hkVector4>(numSpheres);
	{
		hkpHeightFieldShape::CollideSpheresInput in2; in2.m_spheres = sphereBuffer;
		in2.m_numSpheres = numSpheres;
		in2.m_tolerance = input.getTolerance();
		hfShape->collideSpheres( in2, out2 );
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "examine"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{
		hkVector4* outP = out2;
		hkSphere* sphereP = sphereBuffer;
		hkReal tolerance = input.getTolerance();
		for (int i = numSpheres-1; i >= 0; i--)
		{
			if ( (*outP)(3) <= tolerance )
			{
				hkVector4 position; hkpCdPoint point( csBody, hfBody );
				position.setAddMul4( sphereP->getPosition(), *outP, -sphereP->getRadius() - (*outP)(3) );
				point.m_contact.getPosition()._setTransformedPos( hfBody.getTransform(), position );
				point.m_contact.getSeparatingNormal()._setRotatedDir( hfBody.getTransform().getRotation(), *outP );
				point.m_contact.setDistance( (*outP)(3) );
				collector.addCdPoint( point );
			}
			sphereP++;
			outP++;
		}
	}
	hkDeallocateStack( out2 );
	hkDeallocateStack( sphereBuffer );
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "l" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
}

}  // namespace f3m_009bb290
}   // namespace f3m_009bb290

// @f3 0x009a09c0 (community match, verified in this file)
namespace f3m_009a09c0 {
// 0x009a09c0: hkpTriangleShape::castRayImpl(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const
// of Havok 5.5.0 (hkpCollide, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Casts a ray against the triangle: the plane through the three vertices, the two end points' signed distances,
// the hit point, the three edge tests with a small tolerance; on a hit it writes the hit fraction, the normal
// (flipped to face the ray's start) and an invalid shape key, inside the "rcTriangle" timer.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The clock read in hkMonitorStream::TimerCommand::setTime() is
// the SDK's own code and exactly the kit's accepted two-instruction timer block (compiler_tips.md, "Timer slot still
// off"); the plain __rdtsc() form does not reproduce the release object. The function body follows the SDK's
// unoptimized (hybrid) library object statement by statement and reproduces the release object. Only the function
// carries the packet's name.
namespace f3m_009a09c0 {

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
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
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
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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
class hkMonitorStream
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		void __cdecl reset();
		void __cdecl resize( int newSize );
	public:
		__forceinline char* __cdecl getStart() { return m_start.val(); }
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* __cdecl getCapacity() { return m_capacity.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline int __cdecl getCurrentMonitorDataSize()
		{
			return (int)(m_end.val() - m_start.val());
		}
		__forceinline void* __cdecl expandby( int size ) { char* h = m_end.val(); char* newEnd = h + size; m_end = newEnd; return h; }
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
		__forceinline hkBool __cdecl isBufferAllocatedOnTheHeap() { return m_isBufferAllocatedOnTheHeap; }
		void __cdecl setStaticBuffer( char* buffer, int bufferSize );
	public:
		static void __cdecl init();
		void __cdecl quit();
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::Command), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::AddValueCommand), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::TimerCommand), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::TimerBeginListCommand), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			const char* m_nameOfFirstSplit;
		};
};
void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
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
struct hkpShapeRayCastCollectorOutput
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShapeRayCastCollectorOutput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	inline hkpShapeRayCastCollectorOutput();
	inline hkBool hasHit() const;
	inline void reset();
	hkVector4 m_normal;
	hkReal m_hitFraction;
	int m_extraInfo;
	int m_pad[2];
};
struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
	public:
		enum { MAX_HIERARCHY_DEPTH = 8 };
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShapeRayCastOutput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkpShapeRayCastOutput();
		__forceinline void changeLevel(int delta);
		__forceinline void setKey(hkpShapeKey key);
		__forceinline void reset();
	private:
		__forceinline void _reset();
	public:
		hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
	private:
		int m_shapeKeyIndex;
};
inline void hkpShapeRayCastOutput::setKey(hkpShapeKey key)
{
	m_shapeKeys[m_shapeKeyIndex] = key;
}
class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline int getNumCollisionSpheres( )  const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
	public:
		hkpSphereRepShape( hkpShapeType type ) : hkpShape( type ) {}
		hkpSphereRepShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_SPHERE_REP; }
};
extern hkReal hkConvexShapeDefaultRadius;
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		inline void setRadius(hkReal radius);
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline hkpConvexShape::WeldResult weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
																	hkVector4& contactPointWs, const hkTransform* thisObjTransform,
																	const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		__forceinline void getCentre( hkVector4& centreOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		inline hkpConvexShape( hkpShapeType type, hkReal radius );
		hkReal m_radius;
	public:
		hkpConvexShape( hkFinishLoadedObjectFlag flag ) : hkpSphereRepShape(flag) { m_type = HK_SHAPE_CONVEX; }
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
class hkpTriangleShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		__forceinline hkpTriangleShape( hkReal radius = hkConvexShapeDefaultRadius, hkUint16 weldingInfo = 0, hkpWeldingUtility::WeldingType type = hkpWeldingUtility::WELDING_TYPE_NONE);
		__forceinline hkpTriangleShape(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal radius = hkConvexShapeDefaultRadius );
		__forceinline const hkVector4* getVertices() const;
		__forceinline hkVector4& getVertex(int i);
		__forceinline const hkVector4& getVertex(int i) const;
		__forceinline void setVertex(int i, const hkVector4& vertex);
		__forceinline hkUint16 getWeldingInfo() const;
		__forceinline void setWeldingInfo( hkUint16 info );
		__forceinline hkpWeldingUtility::WeldingType getWeldingType() const;
		__forceinline void setWeldingType( hkpWeldingUtility::WeldingType type );
		__forceinline bool isExtruded() const;
		__forceinline const hkVector4& getExtrusion() const;
		__forceinline void setExtrusion( const hkVector4& extrusion );
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool hkpTriangleShape_castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		static void __cdecl registerGetAabbFunction( ShapeFuncs& sf );
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkUint16 m_weldingInfo;
		hkEnum<hkpWeldingUtility::WeldingType, hkUint8> m_weldingType;
		hkUint8 m_isExtruded;
		hkVector4 m_vertexA;
		hkVector4 m_vertexB;
		hkVector4 m_vertexC;
		hkVector4 m_extrusion;
	public:
		void setType() { m_type = HK_SHAPE_TRIANGLE; }
		hkpTriangleShape( hkFinishLoadedObjectFlag flag ) : hkpConvexShape( flag ) { m_type = HK_SHAPE_TRIANGLE; }
};
const hkVector4& hkpTriangleShape::getVertex(int i) const
{
	;
	return (&m_vertexA)[i];
}
class hkpRayShapeCollectionFilter;
struct hkpShapeRayCastInput
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShapeRayCastInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline hkpShapeRayCastInput();
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};
// pdb: hkpTriangleShape::castRayImpl | hkpTriangleShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
hkBool hkpTriangleShape::hkpTriangleShape_castRayImpl(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const
{
	const hkpTriangleShape* thisObj = this;
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "T" "t" "rcTriangle"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	const hkVector4& vert0 = thisObj->getVertex(0);
	const hkVector4& vert1 = thisObj->getVertex(1);
	const hkVector4& vert2 = thisObj->getVertex(2);
	hkVector4 v10; v10.setSub4(vert1, vert0);
	hkVector4 v20; v20.setSub4(vert2, vert0);
	hkVector4 triangleNormal; triangleNormal.setCross(v10, v20);
	const hkReal dist = vert0.dot3(triangleNormal);
	hkReal dist_a = triangleNormal.dot3(input.m_from);
	dist_a -= dist;
	hkReal dist_b = triangleNormal.dot3(input.m_to);
	dist_b -= dist;
	if ( dist_a * dist_b >= 0.0f )
	{
		if ( dist_a != 0.0f || dist_b == 0.0f )
		{
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return false;
		}
	}
	const hkReal proj_length = dist_a - dist_b;
	const hkReal distance = dist_a / proj_length;
	if ( distance < results.m_hitFraction )
	{
		hkReal edge_tolerance = triangleNormal.lengthSquared3();
		edge_tolerance *= -0.0001f;
		hkVector4 point; point.setInterpolate4( input.m_from, input.m_to, distance );
		{
			hkVector4 v0p; v0p.setSub4( vert0, point );
			hkVector4 v1p; v1p.setSub4( vert1, point );
			hkVector4 cp0; cp0.setCross( v0p, v1p );
			if ( cp0.dot3(triangleNormal) >= edge_tolerance )
			{
				hkVector4 v2p; v2p.setSub4( vert2, point );
				hkVector4 cp1; cp1.setCross( v1p, v2p );
				if ( cp1.dot3(triangleNormal) >= edge_tolerance )
				{
					hkVector4 cp2; cp2.setCross( v2p, v0p );
					if ( cp2.dot3(triangleNormal) >= edge_tolerance )
					{
						results.m_hitFraction = distance;
						if ( dist_a > 0.0f )
						{
							results.m_normal = triangleNormal;
						}
						else
						{
							results.m_normal.setNeg4( triangleNormal );
						}
						results.m_normal.normalize3();
						results.setKey( 0xffffffff );
						{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
						return true;
					}
				}
			}
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	return false;
}

}  // namespace f3m_009a09c0
}   // namespace f3m_009a09c0

// @f3 0x009abb20 (community match, verified in this file)
namespace f3m_009abb20 {
// 0x009abb20: hkRigidMotionUtilApplyForcesAndBuildAccumulators(const hkStepInfo& info, hkpMotion*const* motions,
// int numMotions, int motionOffset, hkpVelocityAccumulator* accumulatorsOut) of Havok 5.5.0 (hkpDynamics, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// For each motion it applies the linear and angular damping to the velocities and fills one velocity accumulator
// by motion type: box inertia (the core-from-world matrix from the rotation, the inverse inertia and mass, the
// angular velocity in core space), sphere inertia and character (identity matrix; a character accumulator ignores
// gravity), fixed (setFixed) and keyframed (zero inverse masses); the centre of mass comes from the swept
// transform at the step's start time. It returns the accumulator pointer past the last motion.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The function body follows the SDK's unoptimized (hybrid)
// library object statement by statement and reproduces the release object. Only the function carries the
// packet's name.
namespace f3m_009abb20 {

typedef float  hkReal;
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

extern const hkReal hkUFloat8_intToReal[256];
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
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
namespace hkMath
{
template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
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
class hkQuaternion
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQuaternion), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkSweptTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
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
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
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
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
hkTime hkSweptTransform::getBaseTime() const
{
	return hkTime(m_centerOfMass0(3));
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}
hkReal hkSweptTransform::getInterpolationValue( hkTime t ) const
{
	;
	hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
	;
	;
	return dt;
}
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMotionState), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
hkTransform& hkMotionState::getTransform()
{
	return m_transform;
}
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}
hkSweptTransform& hkMotionState::getSweptTransform()
{
	return m_sweptTransform;
}
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_MOTION)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_MOTION); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_MOTION)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_MOTION); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkStepInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkStepInfo), HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
class hkpBoxMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpBoxMotion(const hkVector4& position, const hkQuaternion& rotation);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void setMass(hkReal m);
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	public:
		hkpBoxMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
namespace hkSweptTransformUtil
{
__forceinline void __cdecl calcCenterOfMassAt( const hkMotionState& ms, hkTime t, hkVector4& centerOut );
}
void __cdecl hkSweptTransformUtil::calcCenterOfMassAt( const hkMotionState& ms, hkTime t, hkVector4& centerOut )
{
	hkReal iv = ms.getSweptTransform().getInterpolationValue( t );
	centerOut.setInterpolate4( ms.getSweptTransform().m_centerOfMass0, ms.getSweptTransform().m_centerOfMass1, iv );
}

hkpVelocityAccumulator* hkRigidMotionUtilApplyForcesAndBuildAccumulators(const hkStepInfo&				info,
																			hkpMotion*const*					motions,
																			int								numMotions,
																			int								motionOffset,
																			hkpVelocityAccumulator*			accumulatorsOut);
// pdb: hkRigidMotionUtilApplyForcesAndBuildAccumulators | hkpRigidMotionUtil.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
hkpVelocityAccumulator* hkRigidMotionUtilApplyForcesAndBuildAccumulators( const hkStepInfo& info, hkpMotion*const* motions, int numMotions, int motionOffset, hkpVelocityAccumulator* accumulatorsOut )
{
	for ( int i = numMotions-1; i >= 0; motions++, accumulatorsOut++, i-- )
	{
		hkpMotion* motion = reinterpret_cast<hkpMotion*>( reinterpret_cast<char*>( *motions ) + motionOffset );
		switch ( motion->m_type )
		{
			case hkpMotion::MOTION_INVALID:
			{
			}
			case hkpMotion::MOTION_BOX_INERTIA:
			case hkpMotion::MOTION_STABILIZED_BOX_INERTIA:
			case hkpMotion::MOTION_THIN_BOX_INERTIA:
			{
				const hkReal one = 1.0f;
				const hkReal deltaTime = info.m_deltaTime;
				motion->m_linearVelocity.mul4( hkMath::max2( 0.0f, one - deltaTime * motion->m_motionState.m_linearDamping ) );
				motion->m_angularVelocity.mul4( hkMath::max2( 0.0f, one - deltaTime * motion->m_motionState.m_angularDamping ) );
				hkpVelocityAccumulator* accumulator = accumulatorsOut;
				accumulator->getCoreFromWorldMatrix().setTranspose( motion->m_motionState.getTransform().getRotation() );
				accumulator->m_type = hkpVelocityAccumulator::HK_RIGID_BODY;
				const hkpBoxMotion* bm = static_cast<const hkpBoxMotion*>( motion );
				accumulator->m_invMasses = bm->m_inertiaAndMassInv;
				accumulator->m_linearVel = motion->m_linearVelocity;
				hkMotionState& ms = motion->m_motionState;
				hkSweptTransformUtil::calcCenterOfMassAt( ms, info.m_startTime, accumulator->getCenterOfMassInWorld() );
				accumulator->m_angularVel._setRotatedDir( accumulator->getCoreFromWorldMatrix(), motion->m_angularVelocity );
				accumulator->m_matrixIsIdentity = false;
				accumulator->m_deactivationClass = motion->m_motionState.m_deactivationClass;
				break;
			}
			case hkpMotion::MOTION_CHARACTER:
			{
				accumulatorsOut->m_type = hkpVelocityAccumulator::HK_NO_GRAVITY_RIGID_BODY;
				goto buildRigidBodyAccumulator;
			}
			case hkpMotion::MOTION_SPHERE_INERTIA:
			case hkpMotion::MOTION_STABILIZED_SPHERE_INERTIA:
			{
				accumulatorsOut->m_type = hkpVelocityAccumulator::HK_RIGID_BODY;
buildRigidBodyAccumulator:
				const hkReal one = 1.0f;
				const hkReal deltaTime = info.m_deltaTime;
				motion->m_linearVelocity.mul4( hkMath::max2( 0.0f, one - deltaTime * motion->m_motionState.m_linearDamping ) );
				motion->m_angularVelocity.mul4( hkMath::max2( 0.0f, one - deltaTime * motion->m_motionState.m_angularDamping ) );
				hkpVelocityAccumulator* accumulator = accumulatorsOut;
				accumulator->m_invMasses = motion->m_inertiaAndMassInv;
				const hkMotionState& ms = motion->m_motionState;
				hkSweptTransformUtil::calcCenterOfMassAt( ms, info.m_startTime, accumulator->getCenterOfMassInWorld() );
				accumulator->m_angularVel = motion->m_angularVelocity;
				accumulator->m_linearVel = motion->m_linearVelocity;
				accumulator->getCoreFromWorldMatrix().setIdentity();
				accumulator->m_matrixIsIdentity = true;
				accumulator->m_deactivationClass = motion->m_motionState.m_deactivationClass;
				break;
			}
			case hkpMotion::MOTION_FIXED:
			{
				hkpVelocityAccumulator* accumulator = accumulatorsOut;
				accumulator->setFixed();
				break;
			}
			case hkpMotion::MOTION_KEYFRAMED:
			{
				hkpVelocityAccumulator* accumulator = accumulatorsOut;
				accumulator->m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
				accumulator->m_invMasses.setZero4();
				accumulator->getCenterOfMassInWorld() = motion->m_motionState.getSweptTransform().m_centerOfMass1;
				accumulator->m_angularVel = motion->m_angularVelocity;
				accumulator->m_linearVel = motion->m_linearVelocity;
				accumulator->getCoreFromWorldMatrix().setIdentity();
				accumulator->m_matrixIsIdentity = true;
				break;
			}
			default:
			{
			}
		}
	}
	return accumulatorsOut;
}

}  // namespace f3m_009abb20
}   // namespace f3m_009abb20

// @f3 0x009a52d0 (community match, verified in this file)
#include <math.h>
extern volatile int g_sink_009a52d0;
namespace f3m_009a52d0 {

namespace f3m_009a52d0 {
typedef float hkReal;

class hkMatrix3;
__declspec(align(16)) class hkVector4
{
public:
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz);
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& b);
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void setAbs4(const hkVector4& v)
    {
        x = (hkReal)fabs(v.x);
        y = (hkReal)fabs(v.y);
        z = (hkReal)fabs(v.z);
        w = (hkReal)fabs(v.w);
    }
    __forceinline int compareLessThan4(const hkVector4& a) const
    {
        return ((x < a.x) ? 8 : 0) | ((y < a.y) ? 4 : 0) | ((z < a.z) ? 2 : 0) | ((w < a.w) ? 1 : 0);
    }
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};

class hkMatrix3
{
public:
    hkVector4 m_col0, m_col1, m_col2;
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    hkReal m_staticFriction;
    hkReal m_extraUpStaticFriction;
    hkReal m_extraDownStaticFriction;
    hkReal m_dynamicFriction;
    int m_priority;
};

struct hkpSurfaceConstraintInteraction
{
    int unk00;
    int unk04;
    int unk08;
    int m_touched;
};

struct hkpSimplexSolverInput
{
    hkVector4 m_position;
    hkVector4 m_velocity;
    hkVector4 m_maxSurfaceVelocity;
    hkVector4 m_upVector;
    hkReal m_deltaTime;
    hkReal m_minDeltaTime;
    const hkpSurfaceConstraintInfo* m_constraints;
    int m_numConstraints;
};

struct hkpSimplexSolverOutput
{
    hkVector4 m_position;
    hkVector4 m_velocity;
    hkReal m_deltaTime;
    hkpSurfaceConstraintInteraction* m_planeInteractions;
};

struct SupportPlane
{
    int m_index;
    const hkpSurfaceConstraintInfo* m_constraint;
    hkpSurfaceConstraintInteraction* m_interaction;
};

struct SimplexSolverInfo
{
    SupportPlane m_supportPlanes[4];
    int m_numSupportPlanes;
    hkReal m_currentTime;
    const hkpSimplexSolverInput* m_input;
    hkpSimplexSolverOutput* m_output;
};

void __cdecl FUN_009a46d0(void* info);
void __cdecl Opaque_009a52d0();

static __declspec(noinline) void FUN_009a4d00(SimplexSolverInfo* info, const hkpSurfaceConstraintInfo* sci0,
    const hkpSurfaceConstraintInfo* sci1, const hkVector4* velocityIn, hkVector4* velocityOut)
{
    velocityOut->w = 0.0f;
    Opaque_009a52d0();
    g_sink_009a52d0 = (int)(sci0->m_staticFriction + sci1->m_staticFriction + velocityIn->x) + info->m_numSupportPlanes;
}

// pdb: hkSimplexSolverSolve3d | hkpSimplexSolver.obj | tesv_win, call_dedup, low
static __declspec(noinline) void FUN_009a52d0(SimplexSolverInfo* info, const hkpSurfaceConstraintInfo* sci0,
    const hkpSurfaceConstraintInfo* sci1, const hkpSurfaceConstraintInfo* sci2, int allowResort,
    const hkVector4* velocityIn, hkVector4* velocityOut)
{

    const hkVector4& p0 = sci0->m_plane;
    const hkVector4& p1 = sci1->m_plane;
    const hkVector4& p2 = sci2->m_plane;
    const hkReal eps = 1.1920928955078125e-07f;

    hkVector4 pointDir;
    bool solved = false;
    {
        hkMatrix3 m;
        m.getColumn(0).setCross(sci1->m_plane, sci2->m_plane);
        m.getColumn(1).setCross(sci2->m_plane, sci0->m_plane);
        m.getColumn(2).setCross(sci0->m_plane, sci1->m_plane);

        const hkVector4& c0 = m.m_col0;
        hkReal det = p0.x * m.m_col0.x + p0.y * m.m_col0.y + p0.z * c0.z;
        hkReal tst = (hkReal)fabs(det);
        if (!(tst < eps))
        {
            {
                hkVector4 t;
                t.set(p0.dot3(sci0->m_velocity), p1.dot3(sci1->m_velocity), p2.dot3(sci2->m_velocity));
                pointDir._setMul3(m, t);
            }
            pointDir.mul4(1.0f / det);

            hkVector4 absPointDir;
            absPointDir.setAbs4(pointDir);
            int mask = info->m_input->m_maxSurfaceVelocity.compareLessThan4(absPointDir);
            if ((mask & 0xe) == 0)
            {
                solved = true;
            }
        }
    }
    if (!solved)
    {
        if (allowResort)
        {
            FUN_009a46d0((void*)info);
            sci0 = info->m_supportPlanes[0].m_constraint;
            sci1 = info->m_supportPlanes[1].m_constraint;
            sci2 = info->m_supportPlanes[2].m_constraint;
        }

        info->m_output->m_planeInteractions[sci0 - info->m_input->m_constraints].m_touched = 1;
        info->m_output->m_planeInteractions[sci1 - info->m_input->m_constraints].m_touched = 1;
        info->m_output->m_planeInteractions[sci2 - info->m_input->m_constraints].m_touched = 1;

        int oldNum = info->m_numSupportPlanes;
        FUN_009a4d00(info, sci0, sci1, velocityIn, velocityOut);
        if (oldNum == info->m_numSupportPlanes)
        {
            FUN_009a4d00(info, sci0, sci2, velocityOut, velocityOut);
        }
        if (oldNum == info->m_numSupportPlanes)
        {
            FUN_009a4d00(info, sci1, sci2, velocityOut, velocityOut);
        }
    }
    else
    {
        *velocityOut = pointDir;
    }
}

SimplexSolverInfo* volatile g_info;
const hkpSurfaceConstraintInfo* volatile g_sci0;
const hkpSurfaceConstraintInfo* volatile g_sci1;
const hkpSurfaceConstraintInfo* volatile g_sci2;
volatile int g_allowResort;
const hkVector4* volatile g_velocityIn;
hkVector4* volatile g_velocityOut;

void f3m_009a52d0_call()
{
    FUN_009a52d0(g_info, g_sci0, g_sci1, g_sci2, g_allowResort, g_velocityIn, g_velocityOut);
}
}
}   // namespace f3m_009a52d0

// @f3 0x009ad740 (community match, verified in this file)
namespace f3m_009ad740 {
namespace f3m_009ad740 {
struct __declspec(align(16)) V4 {
    float x, y, z, w;
    void Mul(float k) { float* v = &x; v[0] *= k; for (int i = 1; i < 4; i++) v[i] *= k; }
    void Lerp(const V4& a, const V4& b, float t) { float s = 1.0f - t; x = s * a.x + b.x * t; y = s * a.y + b.y * t; z = s * a.z + b.z * t; w = s * a.w + b.w * t; }
    V4 operator-(const V4& o) const { V4 r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; r.w = w - o.w; return r; }
    V4 operator+(const V4& o) const { V4 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; r.w = w + o.w; return r; }
    V4 operator*(float k) const { V4 r; r.x = x * k; r.y = y * k; r.z = z * k; r.w = w * k; return r; }
};
struct Pair {
    V4 a;
    V4 b;
};
struct Picker {
    V4 out;
    float best;
    int index;
    int pad18;
    int pad1c;
    int slots[8];
    int slot;
};
}
using namespace f3m_009ad740;
// pdb: getBestHit | hkpMultiSphereShape.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
static __declspec(noinline) int getBestHit(Picker* self, const V4* points, const float* values, const int* indices, int count, const Pair* ref)
{
    float t = self->best;
    int found = -1;
    for (int i = 0; i < count; i++) {
        if (values[i] < t) {
            found = i;
            t = values[i];
        }
    }
    if (found != -1) {
        self->slots[self->slot] = -1;
        int idx = indices[found];
        self->best = t;
        V4 db = ref->b - points[idx];
        V4 da = ref->a - points[idx];
        self->out.Lerp(da, db, t);
        float k = 1.0f / points[idx].w;
        self->index = idx;
        V4& o = self->out;
        o.Mul(k);
        return found;
    }
    return -1;
}

volatile int v_i; Picker* volatile v_p; const V4* volatile v_v; const float* volatile v_f; const int* volatile v_n; const Pair* volatile v_r;
int probe_call() { return getBestHit(v_p, v_v, v_f, v_n, v_i, v_r); }
}   // namespace f3m_009ad740

// @f3 0x009b4c50 (community match, verified in this file)
namespace f3m_009b4c50 {
// 0x009b4c50: hkBvTreeAgent3::calcAabbAndQueryTree(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkTransform& bTa,
// const hkVector4& linearTimInfo, const hkpProcessCollisionInput& input, hkAabb* cachedAabb, hkpShapeKey* hitListOut,
// int hitListCapacity) of Havok 5.5.0 (hkpInternal, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Computes body A's AABB in body B's space (with continuous physics: an epsilon from both motions' second-order
// errors, clipped to a sphere around A's centre of mass, expanded along the time-of-impact path), returns -1 while
// the cached AABB still contains it, otherwise widens it with a look-ahead, caches it, queries B's bounding-volume
// tree, lets the filter handle a full hit list, sorts the hits and terminates the list.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The function body follows the SDK's unoptimized (hybrid)
// library object statement by statement and reproduces the release object. Only the function carries the
// packet's name.
namespace f3m_009b4c50 {

typedef float  hkReal;
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
namespace hkMath
{
template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
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
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
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
inline hkVector4Comparison hkVector4::compareLessThanEqual4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<=a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<=a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<=a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<=a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
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
inline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(1,0)*v1 + r(2,0)*v2;
		t(1) = r(0,1)*v0 + r(1,1)*v1 + r(2,1)*v2;
		t(2) = r(0,2)*v0 + r(1,2)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0) - t(0,3);
		hkReal v1 = v(1) - t(1,3);
		hkReal v2 = v(2) - t(2,3);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(1,0)*v1 + t(2,0)*v2;
		d(1) = t(0,1)*v0 + t(1,1)*v1 + t(2,1)*v2;
		d(2) = t(0,2)*v0 + t(1,2)*v1 + t(2,2)*v2;
		d(3) = 0.0f;
	}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}
class hkAabb
{
	public:
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
hkBool hkAabb::contains(const hkAabb& other) const
{
	hkVector4Comparison mincomp = m_min.compareLessThanEqual4(other.m_min);
	hkVector4Comparison maxcomp = other.m_max.compareLessThanEqual4(m_max);
	hkVector4Comparison both; both.setAnd( mincomp, maxcomp );
	return both.allAreSet(hkVector4Comparison::MASK_XYZ) != 0;
}
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
void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}
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
const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}
const hkMotionState* hkpCdBody::getMotionState() const
{
	return static_cast<const hkMotionState*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
struct hkpCollisionQualityInfo
{
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
	hkReal calcMinSeparation( hkReal currentDistance ) const
	{
		return m_minSeparation;
	}
};
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
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
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
class hkpBvTreeShape: public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpBvTreeShape( hkpShapeType type );
		virtual void queryObb( const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance, hkArray< hkpShapeKey >& hits ) const = 0;
		virtual void queryAabb( const hkAabb& aabb, hkArray<hkpShapeKey>& hits ) const = 0;
		virtual hkUint32 queryAabb( const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys ) const = 0;
		virtual const hkpShapeContainer* getContainer() const = 0;
	public:
		hkpBvTreeShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_BV_TREE; }
};
class hkpShapeCollectionFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB  ) const = 0;
		virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB ) const = 0;
		virtual int numShapeKeyHitsLimitBreached( const hkpCollisionInput& input,
															const hkpCdBody& bodyA, const hkpCdBody& bodyB,
															const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb,
															hkpShapeKey* shapeKeysInOut,
															int shapeKeysCapacity) const = 0;
		virtual ~hkpShapeCollectionFilter() { }
};
namespace hkAlgorithm
{
template<typename T>
	class less
	{
		public:
			__forceinline hkBool operator() ( const T& a, const T& b )
			{
				return ( a < b );
			}
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
namespace hkBvTreeAgent3 
{
int				__cdecl hkBvTreeAgent3_calcAabbAndQueryTree( const hkpCdBody& bodyA,	const hkpCdBody& bodyB, const hkTransform& bTa,
													const hkVector4& linearTimInfo, const hkpProcessCollisionInput& input,
													hkAabb* cachedAabb, hkpShapeKey* hitListOut, int hitListCapacity );
}
// pdb: hkBvTreeAgent3::calcAabbAndQueryTree | hkpBvTreeAgent3.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
int hkBvTreeAgent3::hkBvTreeAgent3_calcAabbAndQueryTree( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkTransform& bTa, const hkVector4& linearTimInfo, const hkpProcessCollisionInput& input, hkAabb* cachedAabb, hkpShapeKey* hitListOut, int hitListCapacity )
{
	hkAabb aabb;
	{
		const hkMotionState* msA = bodyA.getMotionState();
		const hkMotionState* msB = bodyB.getMotionState();
		hkVector4 timInfo; timInfo._setRotatedInverseDir( bodyB.getTransform().getRotation(), linearTimInfo );
		hkVector4 aabbExtents;
		if ( input.m_collisionQualityInfo->m_useContinuousPhysics )
		{
			const hkReal secOrdErrA = ( msA->m_deltaAngle(3) + msB->m_deltaAngle(3) ) * msA->m_objectRadius;
			const hkReal secOrdErrB = msB->m_deltaAngle(3) * msB->m_deltaAngle(3) * msB->m_objectRadius;
			const hkReal checkEpsilon = input.getTolerance() * 0.5f + ( secOrdErrA + secOrdErrB );
			bodyA.getShape()->getAabb( bTa, checkEpsilon, aabb );
			hkVector4 massCenterAinB;
			{
				hkVector4 radius4; radius4.setAll( msA->m_objectRadius + input.getTolerance() * 0.5f + secOrdErrB );
				massCenterAinB._setTransformedInversePos( bodyB.getTransform(), msA->getSweptTransform().m_centerOfMass1 );
				hkVector4 maxR; maxR.setAdd4( massCenterAinB, radius4 );
				hkVector4 minR; minR.setSub4( massCenterAinB, radius4 );
				aabb.m_min.setMax4( aabb.m_min, minR );
				aabb.m_max.setMin4( aabb.m_max, maxR );
			}
			aabbExtents.setSub4( aabb.m_max, aabb.m_min );
			{
				if ( msB->m_deltaAngle(3) > 0.0f )
				{
					hkVector4 relPos; relPos.setSub4( massCenterAinB, msB->getSweptTransform().m_centerOfMassLocal );
					hkVector4 offsetOut; offsetOut.setCross( relPos, msB->m_deltaAngle );
					hkReal f = input.m_stepInfo.m_deltaTime * msB->getSweptTransform().getInvDeltaTime();
					timInfo.addMul4( f, offsetOut );
				}
				hkVector4 zero; zero.setZero4();
				hkVector4 minPath; minPath.setMin4( zero, timInfo );
				hkVector4 maxPath; maxPath.setMax4( zero, timInfo );
				aabb.m_min.add4( minPath );
				aabb.m_max.add4( maxPath );
			}
		}
		else
		{
			const hkReal checkEpsilon = input.getTolerance() * 0.5f;
			bodyA.getShape()->getAabb( bTa, checkEpsilon, aabb );
			aabbExtents.setSub4( aabb.m_max, aabb.m_min );
		}
		if ( cachedAabb )
		{
			if ( cachedAabb->contains( aabb ) )
			{
				return -1;
			}
			hkVector4 zero; zero.setZero4();
			hkVector4 minPath; minPath.setMin4( zero, timInfo );
			hkVector4 maxPath; maxPath.setMax4( zero, timInfo );
			hkVector4 expand4; expand4.setAll( input.getTolerance() * 0.5f );
			aabb.m_min.sub4( expand4 );
			aabb.m_max.add4( expand4 );
			const hkReal maxExpand = 0.4f;
			const hkReal framesLookAhead = -2.0f;
			hkVector4 minExtentPath; minExtentPath.setMul4( framesLookAhead, maxPath );
			hkVector4 maxExtentPath; maxExtentPath.setMul4( framesLookAhead, minPath );
			hkVector4 maxExpand4; maxExpand4.setMul4( maxExpand, aabbExtents );
			maxExtentPath.setMin4( maxExtentPath, maxExpand4 );
			hkVector4 minExpand4; minExpand4.setNeg4( maxExpand4 );
			minExtentPath.setMax4( minExtentPath, minExpand4 );
			aabb.m_min.add4( minExtentPath );
			aabb.m_max.add4( maxExtentPath );
			*cachedAabb = aabb;
		}
	}
	int numHits;
	{
		const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>( bodyB.getShape() );
		numHits = bvB->queryAabb( aabb, hitListOut, hitListCapacity );
	}
	if ( numHits > 256 )
	{
	}
	if ( numHits >= hitListCapacity )
	{
		const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>( bodyB.getShape() );
		numHits = input.m_filter->numShapeKeyHitsLimitBreached( input, bodyA, bodyB, bvB, aabb, hitListOut, hitListCapacity );
		numHits = hkMath::min2( numHits, hitListCapacity - 1 );
	}
	hkAlgorithm::quickSort( hitListOut, numHits );
	hitListOut[numHits] = 0xffffffff;
	return numHits;
}

}  // namespace f3m_009b4c50
}   // namespace f3m_009b4c50

// @f3 0x009a28f0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
namespace f3m_009a28f0 {
// 0x009a28f0: MATCH under /MT /O2 /GS /EHsc /Gy; extent 1928.
// Final subtraction stores y/z through operator(), x/w directly; fixes the final length load order.
// Added a one-float hkSimdReal class for interpolation and inverse-length/mul4.
// All scalar objects carry values used in arithmetic. No new assembly or dead code.
// The original best_v10 timer's two-instruction assembly is preserved unchanged.
// Lineage: builds on the stored draft chk_05255953fa194451a81b (another contributor): class layouts, the three
// callee stand-ins and the timer stand-ins are that draft's. Changed here: inline normalizeWithLength3 returning the
// length; plain locals where the draft aliased ipT to t, flatDirLengthSquared3 to u and ptHeight to
// infInfDistSquared; member-direct setSub4, mul4, dot3 and operator=; dir copy-initialised from dA; three single-use
// scalars written inline; the two scope blocks around res and p/q removed.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);


namespace N009a28f0 {

typedef float hkReal;

__forceinline hkReal sqrtInverse(hkReal r)
{
    hkReal s = sqrtf(r);
    return 1.0f / s;
}

struct hkSimdReal
{
    hkReal value;
    __forceinline hkSimdReal(hkReal v) : value(v) {}
    __forceinline operator hkReal() const { return value; }
};

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline hkReal& operator()(int i) { return m_quad[i]; }
    __forceinline const hkReal& operator()(int i) const { return m_quad[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }
    __forceinline void setZero4() { operator()(0) = operator()(1) = operator()(2) = operator()(3) = 0.0f; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] - b.m_quad[0];
        m_quad[1] = a.m_quad[1] - b.m_quad[1];
        m_quad[2] = a.m_quad[2] - b.m_quad[2];
        m_quad[3] = a.m_quad[3] - b.m_quad[3];
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        operator()(0) = a(0) + b(0) * r;
        operator()(1) = a(1) + b(1) * r;
        operator()(2) = a(2) + b(2) * r;
        operator()(3) = a(3) + b(3) * r;
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return m_quad[0] * a.m_quad[0] + m_quad[1] * a.m_quad[1] + m_quad[2] * a.m_quad[2]; }
    __forceinline hkReal lengthSquared3() const { return operator()(0) * operator()(0) + operator()(1) * operator()(1) + operator()(2) * operator()(2); }
    __forceinline hkSimdReal lengthInverse3() const
    {
        const hkReal& y = m_quad[1];
        const hkReal& x = m_quad[0];
        const hkReal& z = m_quad[2];
        hkReal l2 = x * x + y * y + z * z;
        return (l2 != 0.0f) ? sqrtInverse(l2) : 0.0f;
    }
    __forceinline void mul4(const hkSimdReal& rs)
    {
        hkReal s = rs;
        m_quad[0] *= s;
        m_quad[1] *= s;
        m_quad[2] *= s;
        m_quad[3] *= s;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline hkReal length3() const { return sqrtf(operator()(0) * operator()(0) + operator()(1) * operator()(1) + operator()(2) * operator()(2)); }
    __forceinline hkReal normalizeWithLength3()
    {
        hkReal len = length3();
        mul4(1.0f / len);
        return len;
    }
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, hkSimdReal tt)
    {
        hkReal t = tt;
        hkSimdReal s = 1.0f - t;
        (*this)(0) = s * a(0) + t * b(0);
        (*this)(1) = s * a(1) + t * b(1);
        (*this)(2) = s * a(2) + t * b(2);
        (*this)(3) = s * a(3) + t * b(3);
    }
};

struct hkBool
{
    char m_bool;
    __forceinline hkBool(bool b) { m_bool = (char)b; }
    __forceinline operator bool() const { return m_bool != 0; }
};

struct TimerCommand
{
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_time0 = ticks;
    }
};

struct hkMonitorStream
{
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
};

__forceinline void timerCommand(const char* name)
{
    hkMonitorStream& mStream = *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c));
    if (mStream.m_end < mStream.m_capacityMinus16)
    {
        TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.m_end);
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end = (char*)(h + 1);
    }
}

__forceinline hkBool finishRay(bool hit)
{
    hkBool status(hit);
    timerCommand("Et");
    return status;
}

struct __declspec(align(16)) hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    unsigned int m_filterInfo;
    const void* m_rayShapeCollectionFilter;
    __forceinline hkpShapeRayCastInput() : m_filterInfo(0), m_rayShapeCollectionFilter(0) {}
};

struct __declspec(align(16)) hkpShapeRayCastCollectorOutput
{
    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
};

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
    unsigned int m_shapeKeys[8];
    int m_shapeKeyIndex;
    __forceinline void setKey(unsigned int key) { m_shapeKeys[m_shapeKeyIndex] = key; }
};

void __cdecl FUN_009a24d0(const hkVector4& a, const hkVector4& b, const hkVector4& b2, hkVector4& pt);
void __cdecl FUN_009a2230(const hkVector4& a, const hkVector4& dA, const hkVector4& b, const hkVector4& dB,
                          hkReal& distSquared, hkReal& t, hkReal& u, hkVector4& p, hkVector4& q);
hkBool __cdecl hkpSphereUtil_castRayUtil(hkReal radius, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results);

class hkReferencedObjectView
{
public:
    virtual void v00();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

class hkpShapeBase : public hkReferencedObjectView
{
public:
    unsigned int m_userData;
    unsigned int m_type;
};

class hkpConvexShape : public hkpShapeBase
{
public:
    hkReal m_radius;
};

class hkpCapsuleShape : public hkpConvexShape
{
public:
    enum { HIT_CAP0 = 0, HIT_CAP1 = 1, HIT_BODY = 2 };
    hkVector4 m_vertices[2];

    __forceinline const hkVector4* getVertices() const { return m_vertices; }
    __forceinline const hkVector4& getVertex(int i) const { return getVertices()[i]; }
    hkBool hkpCapsuleShape_castRayImpl(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
};

__declspec(noinline) void __cdecl FUN_009a24d0(
    const hkVector4& point, const hkVector4& pointA, const hkVector4& pointB, hkVector4& closest)
{
    hkVector4 fromQuery;
    fromQuery(0) = pointA(0) - point(0);
    fromQuery(1) = pointA(1) - point(1);
    fromQuery(2) = pointA(2) - point(2);

    hkVector4 axis;
    axis.setSub4(pointB, pointA);
    const hkReal lengthSquared = axis(2) * axis(2) + (axis(0) * axis(0) + axis(1) * axis(1));
    const hkReal amount = -(axis(0) * fromQuery(0) + axis(1) * fromQuery(1) + axis(2) * fromQuery(2));
    if (amount <= 0.0f)
    {
        closest = pointA;
        return;
    }
    if (lengthSquared <= amount)
    {
        closest = pointB;
        return;
    }
    closest.setAddMul4(pointA, axis, amount / lengthSquared);
}

__declspec(noinline) void __cdecl FUN_009a2230(
    const hkVector4& originA, const hkVector4& directionA, const hkVector4& originB, const hkVector4& directionB,
    hkReal& separationSquared, hkReal& t, hkReal& u, hkVector4& closestA, hkVector4& closestB)
{
    hkVector4 delta;
    delta(0) = originB(0) - originA(0);
    delta(1) = originB(1) - originA(1);
    delta(2) = originB(2) - originA(2);
    const hkReal alongBoth = directionB(0) * directionA(0) + directionA(1) * directionB(1) + directionA(2) * directionB(2);
    const hkReal offsetAlongB = directionB(2) * delta(2) + (directionB(0) * delta(0) + delta(1) * directionB(1));
    const hkReal lengthA2 = directionA(1) * directionA(1) + directionA(0) * directionA(0) + directionA(2) * directionA(2);
    const hkReal lengthB2 = directionB(1) * directionB(1) + directionB(0) * directionB(0) + directionB(2) * directionB(2);
    const hkReal denominator = lengthB2 * lengthA2 - alongBoth * alongBoth;
    const hkReal lengthsProduct = lengthB2 * lengthA2;
    const hkReal tolerance = (alongBoth * alongBoth + fabsf(lengthsProduct)) * 9.5367431640625e-7f;
    if (tolerance < fabsf(denominator))
    {
        const hkReal offsetAlongA = delta(2) * directionA(2) + (delta(1) * directionA(1) + delta(0) * directionA(0));
        t = (offsetAlongA * lengthB2 - offsetAlongB * alongBoth) / denominator;
    }
    else
    {
        t = 0.0f;
    }
    u = (alongBoth * t - offsetAlongB) / lengthB2;

    hkVector4 first;
    hkVector4 second;
    first.setAddMul4(originA, directionA, t);
    second.setAddMul4(originB, directionB, u);
    const hkReal sx = first(0) - second(0);
    const hkReal sy = first(1) - second(1);
    const hkReal sz = first(2) - second(2);
    closestA = first;
    closestB = second;
    separationSquared = sy * sy + sx * sx + sz * sz;
}

}  // namespace N009a28f0

using namespace N009a28f0;

// pdb: hkpCapsuleShape::castRayImpl | hkpCapsuleShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
hkBool N009a28f0::hkpCapsuleShape::hkpCapsuleShape_castRayImpl(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const
{
    timerCommand("TtrcCapsule");
    {
        hkVector4 res;
        FUN_009a24d0(input.m_from, getVertex(0), getVertex(1), res);
        hkVector4 join;
        join.setSub4(input.m_from, res);
        if (join.lengthSquared3() < m_radius * m_radius)
        {
            goto returnFalse;
        }
        hkReal infInfDistSquared = 3.40282e+38f;
        hkVector4 dA;
        dA.setSub4(input.m_to, input.m_from);
        hkVector4 dB;
        dB.setSub4(getVertex(1), getVertex(0));
        hkReal t;
        hkReal u;
        hkVector4 p;
        hkVector4 q;
        FUN_009a2230(input.m_from, dA, getVertex(0), dB, infInfDistSquared, t, u, p, q);
        if (infInfDistSquared > m_radius * m_radius)
        {
            goto returnFalse;
        }
        hkVector4 axis;
        axis = dB;
        hkReal axisLength;
        hkReal ipT;
        const hkReal axisLengthSqrd = axis.lengthSquared3();
        if (axisLengthSqrd > 1.192092896e-07f)
        {
            axisLength = axis.normalizeWithLength3();
        }
        else
        {
            axisLength = 0.0f;
            axis.setZero4();
        }
        hkVector4 dir = dA;
        hkReal component = dir.dot3(axis);
        hkVector4 flatDir;
        flatDir.setAddMul4(dir, axis, -component);
        hkReal flatDirLengthSquared3 = flatDir.lengthSquared3();
        if (flatDirLengthSquared3 != 0.0f)
        {
            hkReal d = (m_radius * m_radius - infInfDistSquared) / flatDirLengthSquared3;
            ipT = t - sqrtf(d);
        }
        else
        {
            ipT = -1.0f;
        }
        if (ipT >= results.m_hitFraction)
        {
            goto returnFalse;
        }
        hkReal pointAProj = getVertex(0).dot3(axis);
        hkVector4 intersectPt;
        intersectPt.setInterpolate4(input.m_from, input.m_to, ipT);
        hkReal ptHeight = intersectPt.dot3(axis) - pointAProj;
        if (ipT >= 0.0f && ptHeight > 0.0f && axisLength > ptHeight)
        {
            hkVector4 projPtOnAxis;
            projPtOnAxis.setInterpolate4(getVertex(0), getVertex(1), ptHeight / axisLength);
            hkVector4 normal;
            normal.setSub4(intersectPt, projPtOnAxis);
            normal.normalize3();
            results.m_normal = normal;
            results.m_hitFraction = ipT;
            results.m_extraInfo = HIT_BODY;
            results.setKey(0xffffffff);
            return finishRay(true);
        }
        hkReal projParam = input.m_from.dot3(axis) - pointAProj;
        hkVector4 fromPtProjAxis;
        fromPtProjAxis.setInterpolate4(getVertex(0), getVertex(1), projParam / axisLength);
        hkVector4 axisToRayStart;
        axisToRayStart.m_quad[0] = input.m_from.m_quad[0] - fromPtProjAxis.m_quad[0];
        axisToRayStart(1) = input.m_from.m_quad[1] - fromPtProjAxis.m_quad[1];
        axisToRayStart(2) = input.m_from.m_quad[2] - fromPtProjAxis.m_quad[2];
        axisToRayStart.m_quad[3] = input.m_from.m_quad[3] - fromPtProjAxis.m_quad[3];
        if (ipT < 0.0f && axisToRayStart.lengthSquared3() > m_radius * m_radius)
        {
            goto returnFalse;
        }
        hkpShapeRayCastInput subInput;
        const int extra = (ptHeight <= 0.0f) ? HIT_CAP0 : HIT_CAP1;
        subInput.m_from.setSub4(input.m_from, getVertex(extra));
        subInput.m_to.setSub4(input.m_to, getVertex(extra));
        if (hkpSphereUtil_castRayUtil(m_radius, subInput, results))
        {
            results.m_extraInfo = extra;
            return finishRay(true);
        }
        return finishRay(false);
    }
returnFalse:
    return finishRay(false);
}
}   // namespace f3m_009a28f0

// @f3 0x009ae220 (community match, verified in this file)
extern const float hkUFloat8_intToReal[256];
namespace f3m_009ae220 {
// 0x009ae220: hinged-body reorientation wrapper.
// Reconstructed wrapper uses recovered Havok SDK declarations from shared checkpoint
// chk_8893f179c8db41529802, previously validated for 0x00a73380, with real float[4] lanes.
// It keeps the enabled flag, independent desired reference and stored signed angle.
// MakeCorrectiveImpulse returns the live impulse value; its call-bound lifetime gives
// the native stack reuse after the projection stage ends.
namespace recovered_009ae220 {

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
		__declspec(align(16)) hkReal m_lane[4];
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
	return m_lane[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return m_lane[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	m_lane[0] = v.m_lane[0];
	m_lane[1] = v.m_lane[1];
	m_lane[2] = v.m_lane[2];
	m_lane[3] = v.m_lane[3];
}
inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	m_lane[0] = a;
	m_lane[1] = b;
	m_lane[2] = c;
	m_lane[3] = d;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	m_lane[0] = v0.m_lane[0] + v1.m_lane[0];
	m_lane[1] = v0.m_lane[1] + v1.m_lane[1];
	m_lane[2] = v0.m_lane[2] + v1.m_lane[2];
	m_lane[3] = v0.m_lane[3] + v1.m_lane[3];
}
inline void hkVector4::sub4(const hkVector4& v)
{
	m_lane[0] -= v.m_lane[0];
	m_lane[1] -= v.m_lane[1];
	m_lane[2] -= v.m_lane[2];
	m_lane[3] -= v.m_lane[3];
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	m_lane[0] *= s;
	m_lane[1] *= s;
	m_lane[2] *= s;
	m_lane[3] *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	m_lane[0] = r * a.m_lane[0];
	m_lane[1] = r * a.m_lane[1];
	m_lane[2] = r * a.m_lane[2];
	m_lane[3] = r * a.m_lane[3];
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	m_lane[0] += r * a.m_lane[0];
	m_lane[1] += r * a.m_lane[1];
	m_lane[2] += r * a.m_lane[2];
	m_lane[3] += r * a.m_lane[3];
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
	m_lane[0] = hkMath::fabs(v.m_lane[0]);
	m_lane[1] = hkMath::fabs(v.m_lane[1]);
	m_lane[2] = hkMath::fabs(v.m_lane[2]);
	m_lane[3] = hkMath::fabs(v.m_lane[3]);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (m_lane[0] * a.m_lane[0]) + ( m_lane[1] * a.m_lane[1] ) + ( m_lane[2] * a.m_lane[2] );
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (m_lane[0]*m_lane[0]) + (m_lane[1]*m_lane[1]) + (m_lane[2]*m_lane[2]);
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

// The wrapper uses independent desired/reference axes and stores its signed angle.
float __cdecl FUN_008d3240(float);
struct HingedBodyAction {
 unsigned int unk000, unk004, unk008, unk00c, unk010, unk014;
 hkpRigidBody* body;
 unsigned int unk01c;
 hkVector4 localAxis, localReference, desiredReference;
 float correctionGain, dampingGain, signedAngle;
 unsigned char enabled;
 void FUN_009ae220(const hkStepInfo& stepInfo);
};
static __forceinline hkVector4 MakeCorrectiveImpulse(float gain, const hkVector4& axis, const hkVector4& damping) {
 hkVector4 result;
 result.setMul4(gain, axis);
 result.sub4(damping);
 return result;
}
void HingedBodyAction::FUN_009ae220(const hkStepInfo& stepInfo) {
 if (!enabled) return;
 hkpRigidBody* rb = body;
 hkVector4 bodyReference; bodyReference.setRotatedDir(rb->getRotation(), localReference);
 hkVector4 bodyAxis; bodyAxis.setRotatedDir(rb->getRotation(), localAxis);
 hkVector4 projectedReference = desiredReference;
 const hkReal distance = projectedReference.dot3(bodyAxis);
 projectedReference.addMul4(-distance, bodyAxis);
 projectedReference.normalize3();
 signedAngle = FUN_008d3240(projectedReference.dot3(bodyReference));
 hkVector4 calculatedAxis; calculatedAxis.setCross(bodyReference, projectedReference);
 const hkReal crossComponent = calculatedAxis(calculatedAxis.getMajorAxis());
 const hkReal axisComponent = bodyAxis(bodyAxis.getMajorAxis());
 if (hkMath::isNegative(crossComponent) != hkMath::isNegative(axisComponent)) signedAngle = -signedAngle;
 hkVector4 damping; damping.setMul4(dampingGain * stepInfo.m_invDeltaTime, rb->getAngularVelocity());
 rb->applyAngularImpulse(MakeCorrectiveImpulse(correctionGain * signedAngle * stepInfo.m_invDeltaTime, bodyAxis, damping));
}
} // namespace recovered_009ae220
}   // namespace f3m_009ae220

// @f3 0x009a1da0 (community match, verified in this file)
namespace f3m_009a1da0 {
namespace f3m_009a1da0 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline float dot3(const hkVector4& v) const { return x * v.x + y * v.y + z * v.z; }
    __forceinline void setMul4(float s, const hkVector4& v) { float t = s; x = t * v.x; y = t * v.y; z = t * v.z; w = t * v.w; }
    __forceinline void sub4(const hkVector4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
};

struct Input1da0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_normal;
};

struct Owner1da0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_vec;
    void FUN_009a1da0(const Input1da0& input, int a2, int a3, int a4, int a5, hkVector4& out);
};

// pdb: hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseEndCallback | hkpConstraintAtom.obj | tesv_win, objrun_sim, low
void Owner1da0::FUN_009a1da0(const Input1da0& input, int a2, int a3, int a4, int a5, hkVector4& out)
{
    hkVector4 v = m_vec;
    float d = input.m_normal.dot3(v);
    hkVector4 t;
    t.setMul4(d, v);
    v.sub4(t);
    out.sub4(v);
}

}
}   // namespace f3m_009a1da0

// @f3 0x009a4660 (community match, verified in this file)
namespace f3m_009a4660 {
namespace c_009a4660 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetZero4() { x = y = z = w = 0.0f; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix3 {
    Vec4 col0, col1, col2;
    float& operator()(int r, int c) { return (&(&col0)[c].x)[r]; }
    void SetZero() { Vec4 z; z.SetZero4(); col0 = z; col1 = z; col2 = z; }
    void SetIdentity() { SetZero(); (*this)(0, 0) = 1.0f; (*this)(1, 1) = 1.0f; (*this)(2, 2) = 1.0f; }
};
struct RefObject {
    RefObject() { referenceCount = 1; }
    virtual void v00();
    unsigned short memSizeAndFlags;
    short referenceCount;
};
struct Obj : RefObject {
    Obj(void* p);
    virtual void v00();
    int unk08;
    int unk0c;
    Matrix3 rot;
    Vec4 vec;
    void* unk50;
};
Obj::Obj(void* p)
{
    unk08 = 0;
    unk50 = p;
    rot.SetIdentity();
    vec.SetZero4();
}
}
}   // namespace f3m_009a4660

// @f3 0x009afd60 (community match, verified in this file)
namespace f3m_009afd60 {
namespace f3m_009afd60 {

struct __declspec(align(16)) Vec_009afd60
{
    float x, y, z, w;
    Vec_009afd60() {}
    Vec_009afd60(const Vec_009afd60& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};

struct Arg_009afd60
{
    float unk00;
    float unk04;
    float unk08;
};

struct Iface_009afd60
{
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void v54(float t, void* a, const Vec_009afd60& v);
};

struct Owner_009afd60
{
    void FUN_0090b500();
};

struct Self_009afd60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Owner_009afd60* unk18;
    int unk1c;
    int unk20;
    void FUN_009afd60(const Arg_009afd60& p);
};

// pdb: hkLiquidAction::applyAction | hkLiquidAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: stepInfo
void Self_009afd60::FUN_009afd60(const Arg_009afd60& p)
{
    Owner_009afd60* o = unk18;
    Vec_009afd60 v = *(Vec_009afd60*)((char*)o + 0x110);
    float t = p.unk08;
    o->FUN_0090b500();
    ((Iface_009afd60*)((char*)o + 0xd0))->v54(t, &unk20, v);
}
}
}   // namespace f3m_009afd60

// @f3 0x009b7210 (community match, verified in this file)
namespace f3m_009b7210 {
namespace f3m_009b7210 {

struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(const float& x) { m_real = x; }
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkQuadReal
{
    float v[4];
};

struct __declspec(align(16)) hkVector4
{
    hkQuadReal m_quad;

    __forceinline hkSimdReal getSimdAt(int i) const { hkQuadReal q; q.v[i] = m_quad.v[i]; return q.v[i]; }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdReal r)
    {
        m_quad.v[0] = a.m_quad.v[0] + r * b.m_quad.v[0];
        m_quad.v[1] = a.m_quad.v[1] + r * b.m_quad.v[1];
        m_quad.v[2] = a.m_quad.v[2] + r * b.m_quad.v[2];
        m_quad.v[3] = a.m_quad.v[3] + r * b.m_quad.v[3];
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_quad.v[0] = -v.m_quad.v[0];
        m_quad.v[1] = -v.m_quad.v[1];
        m_quad.v[2] = -v.m_quad.v[2];
        m_quad.v[3] = v.m_quad.v[3];
    }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkSimdReal getDistanceSimdReal() const { return m_separatingNormal.getSimdAt(3); }
    void FUN_009b7210(const hkContactPoint& src);
};

void hkContactPoint::FUN_009b7210(const hkContactPoint& src)
{
    m_position.setAddMul4(src.m_position, src.m_separatingNormal, src.getDistanceSimdReal());
    m_separatingNormal.setNeg3(src.m_separatingNormal);
}
}
}   // namespace f3m_009b7210

// @f3 0x009b7840 (community match, verified in this file)
namespace f3m_009b7840 {
extern float DAT_00de6e60;
extern unsigned int DAT_00e7e9c8;

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Big70
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
    Vec4 v;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct Arg5
{
    void* p00;
    float f04;
    int unk08;
    int unk0c;
    Vec4 v;
    int last;
};

struct Owner
{
    void FUN_009d1750(int, int, Big70*, Arg5*, Arg5*);
    void FUN_009b7840(int a0, int a1, Big70* p, int a3, void* a4);
};

// pdb: hkpSymmetricAgent<hkpShapeCollectionAgent>::linearCast | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void Owner::FUN_009b7840(int a0, int a1, Big70* p, int a3, void* a4)
{
    Big70 copy = *p;
    copy.v.x = -p->v.x;
    copy.v.y = -p->v.y;
    copy.v.z = -p->v.z;
    copy.v.w = -p->v.w;
    Arg5 a;
    a.p00 = &DAT_00e7e9c8;
    a.f04 = DAT_00de6e60;
    a.v = p->v;
    a.last = a3;
    if (a4)
    {
        Arg5 b;
        b.p00 = &DAT_00e7e9c8;
        b.f04 = DAT_00de6e60;
        b.v = p->v;
        b.last = (int)a4;
        FUN_009d1750(a1, a0, &copy, &a, &b);
    }
    else
    {
        FUN_009d1750(a1, a0, &copy, &a, 0);
    }
}
}   // namespace f3m_009b7840

// @f3 0x009bc7b0 (community match, verified in this file)
namespace f3m_009bc7b0 {
namespace f3m_009bc7b0 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
};

struct hkpCdBody;

struct hkpLinearCastCollisionInput
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    hkVector4 m_path;
    int unk60; int unk64; int unk68; int unk6c;
};

struct hkpCdPointCollector
{
    float m_earlyOutDistance;
    __forceinline hkpCdPointCollector() { m_earlyOutDistance = 3.40282e+38f; }
    virtual void addCdPoint(const void* point);
};

struct hkpSymmetricAgentFlipCastCollector : public hkpCdPointCollector
{
    hkVector4 m_path;
    hkpCdPointCollector& m_collector;
    __forceinline hkpSymmetricAgentFlipCastCollector(const hkVector4& path, hkpCdPointCollector& collector)
        : m_path(path), m_collector(collector) {}
    virtual void addCdPoint(const void* point);
};

struct hkpAgentBase
{
    void FUN_009bbc00(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

struct hkpSymmetricAgent : public hkpAgentBase
{
    void FUN_009bc7b0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

// pdb: hkpSymmetricAgent<hkpHeightFieldAgent>::linearCast | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void hkpSymmetricAgent::FUN_009bc7b0(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                     const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector,
                                     hkpCdPointCollector* startCollector)
{
    hkpLinearCastCollisionInput flippedInput = input;
    flippedInput.m_path.setNeg4(input.m_path);
    hkpSymmetricAgentFlipCastCollector flippedCollector(input.m_path, collector);
    if (startCollector)
    {
        hkpSymmetricAgentFlipCastCollector flippedStartCollector(input.m_path, *startCollector);
        FUN_009bbc00(bodyB, bodyA, flippedInput, flippedCollector, &flippedStartCollector);
    }
    else
    {
        FUN_009bbc00(bodyB, bodyA, flippedInput, flippedCollector, 0);
    }
}
}
}   // namespace f3m_009bc7b0

// @f3 0x009bcad0 (community match, verified in this file)
#include <string.h>
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern const void* const DAT_00e7ed28[];
namespace f3m_009bcad0 {
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);

struct MonitorEntry9bcad0 {
    const char* name;
    unsigned int time;
    int unk08;
    const char* detail;
};
struct Monitor9bcad0 {
    int unk00;
    MonitorEntry9bcad0* current;
    int unk08;
    MonitorEntry9bcad0* end;
};

class StackAllocator9bcad0 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void* AllocateStack(int aiSize);
    virtual void DeallocateStack(void* apMem);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* m_cur;
    int unk24;
    char* m_base;
    char* m_end;
};

struct __declspec(align(16)) Vector9bcad0 {
    float x;
    float y;
    float z;
    float w;
};

struct Transform9bcad0 {
    Vector9bcad0 m_rotation0;
    Vector9bcad0 m_rotation1;
    Vector9bcad0 m_rotation2;
    Vector9bcad0 m_translation;
    void FUN_00925300(void* apA, void* apB);
};

struct Shape9bcad0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int childCount;
};

struct Body9bcad0 {
    Shape9bcad0* shape;
    int unk04;
    void* transform;
    Body9bcad0* parent;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    float radius;
};

struct Input9bcad0 {
    int unk00;
    float tolerance;
};

struct Output9bcad0;
class Manager9bcad0 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void f20(void* apOwner, void* apTransform);
};

struct Context9bcad0 {
    Body9bcad0* bodyA;
    Body9bcad0* bodyB;
    Input9bcad0* input;
    Manager9bcad0* manager;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int extra50;
    int extra54;
    int unk58;
    int unk5C;
    int extra60;
    int extra64;
    int extra68;
    int extra6C;
};

struct Cache9bcad0 {
    int first;
    int second;
    unsigned int state;
};

struct StateRecord9bcad0 {
    union {
        struct {
            short countdown;
            unsigned char count;
            unsigned char unk03;
        };
        int packed;
    };
    Cache9bcad0 cache;
};

struct Agent9bcad0 {
    int unk00;
    int unk04;
    short unk08;
    unsigned char unk0A;
    unsigned char flags;
    StateRecord9bcad0 state;
};

struct CollisionResult9bcad0 {
    int unk00;
    int unk04;
    int unk08;
    float distance;
};

struct ContactPoint9bcad0 {
    float position[4];
    float normal[4];
};

struct ContactBlock9bcad0 {
    ContactPoint9bcad0 points[128];
    int unk1000;
    int unk1004;
};

struct OutCache9bcad0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float time;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    Vector9bcad0 transform0;
    Vector9bcad0 transform1;
    Vector9bcad0 transform2;
    void FUN_009bcfd0(OutCache9bcad0* apOther);
    void assign(OutCache9bcad0& arOther) { FUN_009bcfd0(&arOther); }
};

struct Output9bcad0 {
    int count;
    void* owner;
    int unk08;
    int unk0C;
    ContactPoint9bcad0 points[384];
    OutCache9bcad0 cache;
    ContactBlock9bcad0* savedContacts;
};

struct Temporary9bcad0 {
    int count;
    ContactBlock9bcad0 owner;
    int unk100C;
    OutCache9bcad0 cache;
    Temporary9bcad0(Output9bcad0* apOutput);
    void FUN_009bd1a0(Body9bcad0* apA, Body9bcad0* apB, Output9bcad0* apOutput, Manager9bcad0* apManager);
};

struct ProbeInput9bcad0 {
    Transform9bcad0* relative;
    void* world;
    Shape9bcad0* a;
    Shape9bcad0* b;
    float tolerance;
};

struct Collector9bcad0 {
    const void* vtable;
    short unk04;
    short capacity;
    int mode;
    Manager9bcad0* manager;
    bool hit;
};

struct ProcessInput9bcad0 {
    int unk00;
    int unk04;
    int unk08;
    Manager9bcad0* manager;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int extra50;
    int extra54;
    int unk58;
    int unk5C;
    int extra60;
    int extra64;
    int extra68;
    int extra6C;
    void FUN_009bd090(Context9bcad0* apContext);
};

int __cdecl FUN_00a345e0(ProbeInput9bcad0* apInput, Agent9bcad0* apAgent, CollisionResult9bcad0* apResult, Vector9bcad0* apSeparating);
void __cdecl FUN_00a2b5b0(Cache9bcad0* apCache, int a, Manager9bcad0* apManager, void* apOwner);
void* __cdecl FUN_009cc270(ProcessInput9bcad0* apInput, int aiStream, Agent9bcad0* apAgent, CollisionResult9bcad0* apResult, Output9bcad0* apOutput);
void __cdecl FUN_009cc070(int aiStream, Agent9bcad0* apAgent, Manager9bcad0* apManager, void* apOwner);
void __cdecl FUN_00a2a560(Cache9bcad0* apCache);
void __cdecl FUN_00a2b910(Cache9bcad0* apCache, int a, Context9bcad0* apContext, int* apSub, int* apKeys, Output9bcad0* apOutput);

// pdb: hkConvexListAgent3::process | hkpConvexListAgent3.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void* __cdecl hkConvexListAgent3_process(Context9bcad0* context, int stream, Agent9bcad0* agent, CollisionResult9bcad0* collisionOutput, Output9bcad0* output)
{
    // Fake match: grouping otherwise independent locals fixes their stack-slot ordering and reuse.
    struct Scratch
    {
        volatile unsigned int stamp;
        union
        {
            Shape9bcad0* shape;
            volatile unsigned int stamp;
        } shapeEnd;
        float radius;

        union
        {
            void* result;
            Monitor9bcad0* monitor;
        } outcome;
    } scratch;

    {
        Monitor9bcad0* monitor = (Monitor9bcad0*)DAT_00d9b080(DAT_0116913c);
        MonitorEntry9bcad0* entry = monitor->current;
        if (entry < monitor->end)
        {
            entry->name = "LtCvxLst";
            entry->detail = "StTim";
            _ReadWriteBarrier();
            scratch.stamp = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            entry->time = scratch.stamp;
            monitor->current = (MonitorEntry9bcad0*)((char*)entry + 16);
        }
    }
    scratch.shapeEnd.shape = context->bodyB->shape;
    Temporary9bcad0 temporary(output);

    Vector9bcad0 separating;
    // Fake match: these unions explicitly reproduce compiler reuse of disjoint local lifetimes.
    union
    {
        Transform9bcad0 relative;
        ProcessInput9bcad0 process;
    } phase;
    union
    {
        ProbeInput9bcad0 probe;
        Collector9bcad0 collector;
    } arguments;
    if (agent->flags & 0x20)
        goto processStream;
    for (;;)
    {
        {
            scratch.outcome.monitor = (Monitor9bcad0*)DAT_00d9b080(DAT_0116913c);
            MonitorEntry9bcad0* entry = scratch.outcome.monitor->current;
            if (entry < scratch.outcome.monitor->end)
            {
                entry->name = "StStream";
                _ReadWriteBarrier();
                scratch.stamp = (unsigned int)__rdtsc();
                _ReadWriteBarrier();
                entry->time = scratch.stamp;
                scratch.outcome.monitor->current = (MonitorEntry9bcad0*)((char*)entry + 12);
            }
            if (agent->state.countdown-- >= 0)
                goto fallback;
            agent->state.countdown = 25;
            {
                phase.relative.FUN_00925300(context->bodyA->transform, context->bodyB->transform);

                arguments.probe.a = context->bodyA->shape;
                arguments.probe.b = context->bodyB->shape;
                arguments.probe.relative = &phase.relative;
                arguments.probe.world = context->bodyA->transform;
                arguments.probe.tolerance = context->input->tolerance;

                if (!FUN_00a345e0(&arguments.probe, agent, collisionOutput, &separating))
                    goto fallback;
            }
            FUN_00a2b5b0(&agent->state.cache, context->input->unk00, context->manager, output->owner);
            agent->flags |= 0x20;
            agent->state.packed = 0;
            temporary.FUN_009bd1a0(context->bodyA, context->bodyB, output, context->manager);
        }
    processStream: {
        arguments.collector.manager = context->manager;
        arguments.collector.capacity = 1;
        arguments.collector.mode = 2;
        arguments.collector.vtable = DAT_00e7ed28;
        arguments.collector.hit = false;

        phase.process.FUN_009bd090(context);
        phase.process.extra50 = context->extra50;
        phase.process.extra54 = context->extra54;
        phase.process.extra60 = context->extra60;
        phase.process.extra64 = context->extra64;
        phase.process.extra68 = context->extra68;
        phase.process.extra6C = context->extra6C;
        phase.process.manager = (Manager9bcad0*)&arguments.collector;
        scratch.outcome.result = FUN_009cc270(&phase.process, stream, agent, collisionOutput, output);
        phase.process.manager = arguments.collector.manager;
        if (!arguments.collector.hit)
        {
            if (!agent->state.count || (agent->flags & 0x40))
                goto finished;
            Body9bcad0* body = context->bodyB;
            while (body->parent)
                body = body->parent;
            float radiusB = body->radius;
            body = context->bodyA;
            while (body->parent)
                body = body->parent;
            scratch.radius = body->radius;
            // Fake match: the identity multiply forces one store after the minimum selection.
            scratch.radius = (scratch.radius < radiusB) ? scratch.radius * 1.0f : radiusB;
            float twice = scratch.radius * 2.0f;
            if (!(collisionOutput->distance < -twice))
                goto finished;
        }
        Manager9bcad0* manager = context->manager;
        if (output->cache.time != temporary.cache.time)
        {
            manager->f20(output->owner, &output->cache.transform0);
            output->cache.assign(temporary.cache);
        }
        output->count = temporary.count;
        if (output->savedContacts)
            memmove(output->savedContacts, &temporary.owner, 0x1008);
        FUN_009cc070(stream, agent, context->manager, output->owner);
        agent->flags &= 0xdf;
        StateRecord9bcad0* state = &agent->state;
        // Fake match: retain the constructor-style null guard on this interior address.
        if (state)
        {
            state->cache.first = 0;
            state->cache.second = 0;
            state->cache.state = 0x80000000;
        }
        FUN_00a2a560(&agent->state.cache);
        agent->state.countdown = 25;
    }
    }
fallback:
    collisionOutput->distance = -1.701410009187828e+38f;
    {
        int count = scratch.shapeEnd.shape->childCount;
        StackAllocator9bcad0* allocator = (StackAllocator9bcad0*)DAT_00d9b080(DAT_010f3170);
        int size = (count * 4 + 0x14) & ~0xf;
        int* keys = (int*)allocator->m_cur;
        char* next = (char*)keys + size;
        if (next <= allocator->m_end)
            allocator->m_cur = next;
        else
            keys = (int*)allocator->AllocateStack(size);
        for (int i = 0; i < count; ++i)
            keys[i] = i;
        keys[count] = -1;
        FUN_00a2b910(&agent->state.cache, 0, context, &scratch.shapeEnd.shape->unk14, keys, output);
        allocator = (StackAllocator9bcad0*)DAT_00d9b080(DAT_010f3170);
        allocator->m_cur = (char*)keys;
        if ((char*)keys == allocator->m_base)
            allocator->DeallocateStack(keys);
        scratch.outcome.result = &agent->state.cache + 1;
    }
finished:
    agent->flags |= 0x40;
    Monitor9bcad0* monitor = (Monitor9bcad0*)DAT_00d9b080(DAT_0116913c);
    MonitorEntry9bcad0* entry;
    entry = monitor->current;
    if (entry < monitor->end)
    {
        entry->name = "lt";
        _ReadWriteBarrier();
        scratch.shapeEnd.stamp = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        entry->time = scratch.shapeEnd.stamp;
        monitor->current = (MonitorEntry9bcad0*)((char*)entry + 12);
    }
    return (void*)(((unsigned int)scratch.outcome.result + 15) & ~15);
}
}   // namespace f3m_009bcad0

// @f3 0x009bea40 (community match, verified in this file)
namespace f3m_009bea40 {
namespace f3m_009bea40 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
};

struct hkpCdBody;

struct hkpLinearCastCollisionInput
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    hkVector4 m_path;
    int unk60; int unk64; int unk68; int unk6c;
};

struct hkpCdPointCollector
{
    float m_earlyOutDistance;
    __forceinline hkpCdPointCollector() { m_earlyOutDistance = 3.40282e+38f; }
    virtual void addCdPoint(const void* point);
};

struct hkpSymmetricAgentFlipCastCollector : public hkpCdPointCollector
{
    hkVector4 m_path;
    hkpCdPointCollector& m_collector;
    __forceinline hkpSymmetricAgentFlipCastCollector(const hkVector4& path, hkpCdPointCollector& collector)
        : m_path(path), m_collector(collector) {}
    virtual void addCdPoint(const void* point);
};

struct hkpAgentBase
{
    void FUN_009bdb50(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

struct hkpSymmetricAgent : public hkpAgentBase
{
    void FUN_009bea40(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

// pdb: hkpSymmetricAgent<hkpConvexListAgent>::linearCast | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void hkpSymmetricAgent::FUN_009bea40(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                     const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector,
                                     hkpCdPointCollector* startCollector)
{
    hkpLinearCastCollisionInput flippedInput = input;
    flippedInput.m_path.setNeg4(input.m_path);
    hkpSymmetricAgentFlipCastCollector flippedCollector(input.m_path, collector);
    if (startCollector)
    {
        hkpSymmetricAgentFlipCastCollector flippedStartCollector(input.m_path, *startCollector);
        FUN_009bdb50(bodyB, bodyA, flippedInput, flippedCollector, &flippedStartCollector);
    }
    else
    {
        FUN_009bdb50(bodyB, bodyA, flippedInput, flippedCollector, 0);
    }
}
}
}   // namespace f3m_009bea40

// @f3 0x009bf410 (community match, verified in this file)
namespace f3m_009bf410 {
namespace f3m_009bf410 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
};

struct hkpCdBody;

struct hkpLinearCastCollisionInput
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    hkVector4 m_path;
    int unk60; int unk64; int unk68; int unk6c;
};

struct hkpCdPointCollector
{
    float m_earlyOutDistance;
    __forceinline hkpCdPointCollector() { m_earlyOutDistance = 3.40282e+38f; }
    virtual void addCdPoint(const void* point);
};

struct hkpSymmetricAgentFlipCastCollector : public hkpCdPointCollector
{
    hkVector4 m_path;
    hkpCdPointCollector& m_collector;
    __forceinline hkpSymmetricAgentFlipCastCollector(const hkVector4& path, hkpCdPointCollector& collector)
        : m_path(path), m_collector(collector) {}
    virtual void addCdPoint(const void* point);
};

struct hkpAgentBase
{
    void FUN_009bf020(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

struct hkpSymmetricAgent : public hkpAgentBase
{
    void FUN_009bf410(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

// pdb: hkpSymmetricAgent<hkpListAgent>::linearCast | hkpListAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void hkpSymmetricAgent::FUN_009bf410(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                     const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector,
                                     hkpCdPointCollector* startCollector)
{
    hkpLinearCastCollisionInput flippedInput = input;
    flippedInput.m_path.setNeg4(input.m_path);
    hkpSymmetricAgentFlipCastCollector flippedCollector(input.m_path, collector);
    if (startCollector)
    {
        hkpSymmetricAgentFlipCastCollector flippedStartCollector(input.m_path, *startCollector);
        FUN_009bf020(bodyB, bodyA, flippedInput, flippedCollector, &flippedStartCollector);
    }
    else
    {
        FUN_009bf020(bodyB, bodyA, flippedInput, flippedCollector, 0);
    }
}
}
}   // namespace f3m_009bf410

// @f3 0x009b81b0 (community match, verified in this file)
namespace f3m_009b81b0 {
class hkpContactMgr;

namespace bvt55
{
    class BaseObject
    {
    public:
        virtual ~BaseObject() {}
    };

    class RefObject : public BaseObject
    {
    public:
        RefObject() : m_referenceCount(1) {}
        unsigned short m_memSizeAndFlags;
        short m_referenceCount;
    };

    class CollisionAgent : public RefObject
    {
    public:
        CollisionAgent(hkpContactMgr* mgr) { m_contactMgr = mgr; }
        virtual ~CollisionAgent() {}
        hkpContactMgr* m_contactMgr;
    };

    template <class T>
    struct Array
    {
        Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
        T* m_data;
        int m_size;
        int m_capacityAndFlags;
    };

    struct __declspec(align(16)) Vector4
    {
        float x, y, z, w;
        void setAll(float a) { x = a; y = a; z = a; w = a; }
    };

    struct Aabb
    {
        Vector4 m_min;
        Vector4 m_max;
    };

    struct EntryInfo
    {
        unsigned int m_key;
        int m_userInfo;
        CollisionAgent* m_collisionAgent;
    };
}

class hkpBvTreeAgent : public bvt55::CollisionAgent
{
public:
    hkpBvTreeAgent(hkpContactMgr* mgr);
    ~hkpBvTreeAgent() {}

    bvt55::Array<bvt55::EntryInfo> m_collisionPartners;
    bvt55::Aabb m_cachedAabb;
};

// pdb: hkpBvTreeAgent::hkpBvTreeAgent | hkpBvTreeAgent.obj | fnv360_0822_debug, objrun_sim, medium
// pdb params: mgr
hkpBvTreeAgent::hkpBvTreeAgent(hkpContactMgr* mgr)
    : bvt55::CollisionAgent(mgr)
{
    m_cachedAabb.m_max.setAll(3.40282e+38f); m_cachedAabb.m_min.setAll(3.40282e+38f);
}
}   // namespace f3m_009b81b0

// @f3 0x009a60f0 (community match, verified in this file)
namespace f3m_009a60f0 {
namespace f3m_009a60f0 {
typedef float hkReal;
struct __declspec(align(16)) hkVector4 {
    hkReal x, y, z, w;
    __forceinline void setMul4(hkReal r, const hkVector4& v) { x = r * v.x; y = r * v.y; z = r * v.z; w = r * v.w; }
};
struct hkTransform;
struct hkAabb;
struct hkAabbUtil {
    static void __cdecl FUN_009a7a80(const hkTransform& localToWorld, const hkVector4& halfExtents, const hkVector4& center, hkReal tolerance, hkAabb& aabbOut);
};
namespace hkMath {
    template <typename T> __forceinline T min2(T a, T b) { return a < b ? a : b; }
    template <typename T> __forceinline T max2(T a, T b) { return a > b ? a : b; }
}
class hkpShapeBase {
public:
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
    virtual hkReal getHeightAt(int x, int z) const;
    int unk04;
    int m_userData;
    int m_type;
    int m_xRes;
    int m_zRes;
    hkReal m_heightCenter;
    int unk1c;
};
class hkpSampledHeightFieldShape : public hkpShapeBase {
public:
    hkVector4 m_intToFloatScale;
    hkVector4 m_floatToIntScale;
    hkVector4 m_floatToIntOffsetFloorCorrected;
    hkVector4 m_extents;
    void FUN_009a60f0(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
};
// pdb: hkpSampledHeightFieldShape::getAabbImpl | hkpSampledHeightFieldShape.obj | tesv_win, objrun, medium
void hkpSampledHeightFieldShape::FUN_009a60f0(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    hkReal minHeight = getHeightAt(0, 0);
    hkReal maxHeight = minHeight;
    if (m_extents.y < 0.0f) {
        hkpSampledHeightFieldShape* shape = const_cast<hkpSampledHeightFieldShape*>(this);
        for (int i = 0; i < m_xRes; i++) {
            for (int j = 0; j < m_zRes; j++) {
                hkReal z = getHeightAt(i, j);
                minHeight = hkMath::min2(minHeight, z);
                maxHeight = hkMath::max2(maxHeight, z);
            }
        }
        minHeight *= m_intToFloatScale.y;
        maxHeight *= m_intToFloatScale.y;
        hkReal oldMin = minHeight;
        minHeight = hkMath::min2(minHeight, maxHeight);
        maxHeight = hkMath::max2(oldMin, maxHeight);
        shape->m_heightCenter = (maxHeight + minHeight) * 0.5f;
        shape->m_extents.y = maxHeight - minHeight;
    }
    hkVector4 center;
    center.setMul4(0.5f, m_extents);
    hkVector4 halfExtents = center;
    center.y = m_heightCenter;
    hkAabbUtil::FUN_009a7a80(localToWorld, halfExtents, center, tolerance, out);
}
}
}   // namespace f3m_009a60f0
