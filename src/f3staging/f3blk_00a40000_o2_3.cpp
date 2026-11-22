#include <math.h>
// src/f3staging/f3blk_00a40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a56820 (community match, verified in this file)
namespace f3m_00a56820 {
struct Vector4
{
 float x, y, z, w;
 void SetSub(const Vector4& a, const Vector4& b)
 { x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w; }
};
struct __declspec(align(16)) RayInput
{
 Vector4 from, to;
 unsigned int filterInfo, userData, flags, unknown2c;
};
struct CollisionBody;
struct Shape
{
 virtual void v00();
 virtual void v04();
 virtual void v08();
 virtual void v0c();
 virtual void CastRay(const RayInput& input,const CollisionBody& body,void* collector) const;
};
struct __declspec(align(16)) CollisionBody
{
 const Shape* shape;
 unsigned int shapeKey;
 const void* motion;
 const CollisionBody* parent;
 CollisionBody(const CollisionBody& source,const Shape* child)

 {
  parent = &source;
  motion = source.motion;
  shapeKey = 0;
  shape = child;
 }
};
struct TranslatedShape
{
 void* vtable;
 unsigned int unknown04, unknown08, unknown0c;
 unsigned int unknown10, unknown14;
 Shape* child;
 unsigned int unknown1c;
 Vector4 translation;
 void FUN_00a56820(const RayInput& input,const CollisionBody& body,void* collector) const;
};
void TranslatedShape::FUN_00a56820(const RayInput& input,const CollisionBody& body,void* collector) const
{
 RayInput localInput=input;
 localInput.from.SetSub(input.from,translation);
 localInput.to.SetSub(input.to,translation);
 CollisionBody localBody(body,child);
 child->CastRay(localInput,localBody,collector);
}
}   // namespace f3m_00a56820

// @f3 0x00a56d10 (community match, verified in this file)
extern "C" unsigned long DAT_0126835c;
namespace f3m_00a56d10 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};

static const char s_kEndTimer[] = "Et";
static inline void TimerMark(const char* name)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct __declspec(align(16)) Vec4DD
{
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    void setSub4(const Vec4DD& a, const Vec4DD& b)
    {
        m_x = a.m_x - b.m_x;
        m_y = a.m_y - b.m_y;
        m_z = a.m_z - b.m_z;
        m_w = a.m_w - b.m_w;
    }
};

struct RayInputDD60
{
    Vec4DD m_vFrom;
    Vec4DD m_vTo;
    unsigned int m_uiFilterInfo;
    void* m_pRayShapeCollectionFilter;
    int pad[2];
};

struct RayOutputDD60
{
    Vec4DD m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void changeLevel(int delta)
    {
        m_uiShapeKeyIndex += delta;
    }
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

struct ShapeDD60
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void RayCast(void* pHit, const RayInputDD60& input, RayOutputDD60& results) const;
};

struct ConvexTranslateDD60
{
    int pad[6];
    const ShapeDD60* m_pContainedShape;
    int pad1c;
    Vec4DD m_vTranslation;
    void* hkpConvexTranslateShape_castRayImpl(void* pHit, const RayInputDD60& input, RayOutputDD60& results);
};

// pdb: hkpConvexTranslateShape::castRayImpl | hkpConvexTranslateShape.obj | fnv360_0822_retail, objopen_prop + bridge(ustr_rel|vtable) + skyrim(ustr_rel), high
void* ConvexTranslateDD60::hkpConvexTranslateShape_castRayImpl(void* pHit, const RayInputDD60& input, RayOutputDD60& results)
{
    TimerMark("TtrcConvTransl");
    RayInputDD60 subInput = input;
    subInput.m_vFrom.setSub4(input.m_vFrom, m_vTranslation);
    subInput.m_vTo.setSub4(input.m_vTo, m_vTranslation);
    results.changeLevel(1);
    m_pContainedShape->RayCast(pHit, subInput, results);
    results.changeLevel(-1);
    if (*(char*)pHit)
        results.setKey(0);
    TimerMark(s_kEndTimer);
    return pHit;
}
}   // namespace f3m_00a56d10

// @f3 0x00a50cd0 (community match, verified in this file)
namespace f3m_00a50cd0 {
struct S_00cd55a0;
void FUN_00cd55a0(S_00cd55a0* p);
void __cdecl FUN_0096cd80(void* out, const void* a, const void* b);

namespace NA50CD0 {

class __declspec(align(16)) ChainVec
{
  public:
    float x, y, z, w;
    ChainVec()
    {}
    ChainVec(const ChainVec& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void operator=(const ChainVec& v)
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
    float getSimdAt(int i) const
    {
        return (&x)[i];
    }
    __forceinline void zero()
    {
        x = y = z = w = 0.0f;
    }
    __forceinline void product(const ChainVec& a, const ChainVec& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void product(float s, const ChainVec& b)
    {
        x = s * b.x;
        y = s * b.y;
        z = s * b.z;
        w = s * b.w;
    }
    __forceinline void mul(const ChainVec& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }
    __forceinline void add(const ChainVec& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void sub(const ChainVec& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline void sub4(const ChainVec& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline void setAll(float s)
    {
        x = y = z = w = s;
    }
    __forceinline void splat(const ChainVec& a)
    {
        x = a.w;
        y = a.w;
        z = a.w;
        w = a.w;
    }
    __forceinline float sum() const
    {
        return x + y + z;
    }
};

class ChainMat
{
  public:
    ChainVec c0, c1, c2;
    ChainMat()
    {}
    void operator=(const ChainMat& a)
    {
        c0 = a.c0;
        c1 = a.c1;
        c2 = a.c2;
    }
    ChainVec& col(int i)
    {
        return (&c0)[i];
    }
    const ChainVec& col(int i) const
    {
        return (&c0)[i];
    }
    float& operator()(int r, int c)
    {
        return col(c)(r);
    }
    const float& operator()(int r, int c) const
    {
        return col(c)(r);
    }
    __forceinline void zeroCached()
    {
        ChainVec v;
        v.zero();
        ChainVec& copy = v;
        c0 = copy;
        c1 = copy;
        c2 = copy;
    }
    __forceinline void transpose(const ChainMat& a)
    {
        (*this)(0, 0) = a(0, 0);
        (*this)(1, 1) = a(1, 1);
        (*this)(2, 2) = a(2, 2);
        (*this)(3, 0) = 0.0f;
        (*this)(3, 1) = 0.0f;
        (*this)(3, 2) = 0.0f;
        (*this)(1, 0) = a(0, 1);
        (*this)(0, 1) = a(1, 0);
        (*this)(2, 0) = a(0, 2);
        (*this)(0, 2) = a(2, 0);
        (*this)(2, 1) = a(1, 2);
        (*this)(1, 2) = a(2, 1);
    }
    __forceinline void product(const ChainMat& a, const ChainMat& b)
    {
        FUN_0096cd80(this, &a, &b);
    }
    __forceinline void sub(const ChainMat& a)
    {
        c0.sub4(a.c0);
        c1.sub4(a.c1);
        c2.sub4(a.c2);
    }
};

struct ChainBody
{
    unsigned type;
    unsigned deactivation;
    float gravity;
    ChainVec linearVelocity, angularVelocity, mass;
};

static inline float chainMaximum(float a, float b)
{
    return a > b ? a : b;
}

struct ProbeJac
{
    ChainVec linear;
    ChainVec angular0;
    ChainVec angular1;
    __forceinline float paired(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const
    {
        return pairedCore(a, b, q);
    }
    __forceinline float pairedCore(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const
    {
        const ProbeJac& p = *this;
        ChainVec lin;
        lin.product(p.linear, q.linear);
        ChainVec ang0;
        ang0.product(p.angular0, q.angular0);
        ChainVec ang1;
        ang1.product(p.angular1, q.angular1);
        ChainVec la;
        la.product(a.mass.getSimdAt(3), lin);
        ChainVec lb;
        lb.product(b.mass.getSimdAt(3), lin);
        ang0.mul(a.mass);
        ang1.mul(b.mass);
        la.add(lb);
        ang0.add(ang1);
        ang0.add(la);
        float result = ang0.sum();
        return result;
    }
    __forceinline float shared(const ChainBody& a, const ProbeJac& q) const
    {
        const ProbeJac& p = *this;
        ChainVec lin;
        lin.product(p.linear, q.linear);
        ChainVec angular;
        angular.product(p.angular1, q.angular0);
        ChainVec weighted;
        ChainVec mass;
        mass.setAll(a.mass.getSimdAt(3));
        weighted.product(mass, lin);
        angular.mul(a.mass);
        angular.sub(weighted);
        float result = angular.sum();
        return result;
    }
};

template <class T> __forceinline const T* offsetValue(const T* p, unsigned n)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(p) + n);
}
struct ProbeOffset
{
    unsigned offset;
    const ChainBody& body(const ChainBody* p)
    {
        return *offsetValue(p, offset);
    }
};
struct ProbeRow
{
    ChainMat lower, diag, upper;
};

} // namespace NA50CD0

using namespace NA50CD0;

// pdb: buildConstraintMatrixLuDecompositionForBallAndSocketChain | hkpChainBuildJacobian.obj | tesv_win, caller_sim, low
static __declspec(noinline) void FUN_00a50cd0(int aiRowCount, float regularizer, ProbeJac* apJacobian,
                                              ProbeOffset* offsets, const ChainBody* bodies, ProbeRow* output,
                                              int bufferSize)
{
    ChainMat matPrevious;
    matPrevious.zeroCached();
    ChainMat upper;
    upper.zeroCached();
    for (int row = 0; row < aiRowCount; ++row)
    {
        int stride = 3;
        int start = row * stride;
        ChainMat diag;
        for (int r = 0; r < 3; ++r)
        {
            for (int c = r; c < 3; ++c)
            {
                diag(c, r) = diag(r, c) = apJacobian[start + r].paired(
                    offsets[row].body(bodies), offsets[row + 1].body(bodies), apJacobian[start + c]);
            }
            float& d = diag(r, r);
            d += regularizer;
        }
        ChainMat matNext;
        matNext.zeroCached();
        if (row < aiRowCount - 1)
        {
            for (int r = 0; r < 3; ++r)
            {
                for (int c = 0; c < 3; ++c)
                {
                    matNext(r, c) =
                        apJacobian[start + r].shared(offsets[row + 1].body(bodies), apJacobian[start + stride + c]);
                }
            }
        }
        else
        {
            matNext.col(0).zero();
            matNext.col(1).zero();
            matNext.col(2).zero();
        }
        output[row].lower.transpose(matPrevious);
        ChainMat product;
        product.product(output[row].lower, upper);
        output[row].diag = diag;
        output[row].diag.sub(product);
        for (int i = 0; i < 3; ++i)
        {
            float& value = output[row].diag(i, i);
            value = chainMaximum(value, 1.1920929e-7f);
        }
        FUN_00cd55a0(reinterpret_cast<S_00cd55a0*>(&output[row].diag));
        output[row].upper.product(output[row].diag, matNext);
        matPrevious = matNext;
        upper = output[row].upper;
    }
}

volatile int probe_count;
volatile float probe_cfm;
ProbeJac* volatile probe_jac;
ProbeOffset* volatile probe_offsets;
const ChainBody* volatile probe_bodies;
ProbeRow* volatile probe_rows;
void native_entry_a50cd0()
{
    FUN_00a50cd0(probe_count, probe_cfm, probe_jac, probe_offsets, probe_bodies, probe_rows, 0);
}
}   // namespace f3m_00a50cd0

// @f3 0x00a4dfa0 (community match, verified in this file)
#include <intrin.h>
extern void* DAT_00e81ac0;
namespace f3m_00a4dfa0 {

namespace task2379 {
struct Bool {char value; Bool(bool b):value(b){} };
struct Array {void* data; int size;unsigned cap;Array():data(0),size(0),cap(0x80000000){} };

class hkReferencedObjectDCE
{
  public:
    hkReferencedObjectDCE() : m_sReferenceCount(1)
    { vtbl=(void*)0x00e81ac0; _ReadWriteBarrier(); }
    void* vtbl;

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct DCEInfo
{
    DCEInfo() : m_usUnk04(0x16), m_usUnk14(0), m_usUnk16(3)
    {}

    int unk00;
    unsigned short m_usUnk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short m_usUnk14;
    unsigned short m_usUnk16;
};

class FUN_00a4dfa0 : public hkReferencedObjectDCE
{
  public:
    FUN_00a4dfa0();

    static void* operator new(unsigned int, void* storage)
    {
        return storage;
    }
    static void operator delete(void*, void*)
    {}

    int m_iUnk08;
    int m_iUnk0C;
    int m_iUnk10;
    int m_iUnk14;
    Bool m_bUnk18;
    DCEInfo m_kInfo;
    int m_iUnk34;
    int m_iUnk38;
    int m_iUnk3C;
    int m_iUnk40;
    int m_iUnk44;
    int m_iUnk48;
    int m_iUnk4C;
    Array m_kArray50;
    Array m_kArray5C;
    Array m_kArray68;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    Array m_kArray114;
    Array m_kArray120;
    int m_iUnk12C;
    int m_iUnk130;
};

// pdb: hkpSerializedAgentNnEntry::hkpSerializedAgentNnEntry | hkpSaveContactPointsUtil.obj | fnv360_0822_retail, call_gap, low
FUN_00a4dfa0::FUN_00a4dfa0()
    : m_iUnk08(0), m_iUnk0C(0), m_iUnk10(-1), m_iUnk14(-1), m_bUnk18(false), m_iUnk34(0), m_iUnk38(0), m_iUnk3C(0),
      m_iUnk40(0), m_iUnk44(0), m_iUnk48(0), m_iUnk4C(0), m_iUnk12C(0x103), m_iUnk130(1)
{}
}
}   // namespace f3m_00a4dfa0

// @f3 0x00a4c9c0 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_010f3170;
extern char DAT_00e86a0c;
extern char DAT_00dcc494;
namespace f3m_00a4c9c0 {

namespace f3m_00a4c9c0 {
struct ThreadMemory {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
    int maxFree;
    int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    void* freeList;
    int freeCount;
    void FUN_008f6890(int size, void* p, int tag) throw();
};
extern ThreadMemory* (__stdcall* const DAT_00d9b080)(unsigned long index);
struct hkBaseObject {
    virtual ~hkBaseObject() throw() {}
};
struct hkReferencedObject : hkBaseObject {
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference() throw()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                delete this;
        }
    }
};
struct Block {
    void* next;
    ~Block() throw();
    static void operator delete(void* p) throw()
    {
        ThreadMemory* mem = DAT_00d9b080(DAT_010f3170);
        if (mem->freeCount >= mem->maxFree) {
            mem->FUN_008f6890(4, p, 5);
        } else {
            *(void**)p = (_ReadWriteBarrier(), mem->freeCount++, mem->freeList); mem->freeList = p;
        }
    }
};
struct Holder {
    void* vtable;
    int unk04;
    hkReferencedObject* object;
    Block* block;
    ~Holder() throw();
};
// pdb: hkPlatformObjectWriter::~hkPlatformObjectWriter | hkPlatformObjectWriter.obj | fnv360_0822_retail, call_seq, medium
Holder::~Holder() throw()
{
    vtable=(void*)0x00e86a0c;
    object->removeReference();
    delete block;
    vtable=&DAT_00dcc494;
}
}
}   // namespace f3m_00a4c9c0

// @f3 0x00a52bd0 (community match, verified in this file)
#include <math.h>
namespace f3m_00a52bd0 {

__declspec(align(16)) struct MoppVec4
{
    float x;
    float y;
    float z;
    float w;

    float& operator()(int i)
    {
        return (&x)[i];
    }

    const float& operator()(int i) const
    {
        return (&x)[i];
    }

    void setAll(float a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }

    void add4(const MoppVec4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }

    void setAdd4(const MoppVec4& v0, const MoppVec4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    void setSub4(const MoppVec4& v0, const MoppVec4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    void setMul4(const MoppVec4& a, const MoppVec4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }

    void mul4(float rs)
    {
        float s = float(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    void setNeg4(const MoppVec4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }

    void setAbs4(const MoppVec4& v)
    {
        x = fabsf(v.x);
        y = fabsf(v.y);
        z = fabsf(v.z);
        w = fabsf(v.w);
    }

    void setBroadcast3clobberW(const MoppVec4& v, int i)
    {
        float r = (&v.x)[i];
        x = r;
        y = r;
        z = r;
        w = r;
    }
};

struct MoppMatrix3
{
    MoppVec4 m_col0;
    MoppVec4 m_col1;
    MoppVec4 m_col2;

    const MoppVec4& getColumn(int i) const
    {
        return (&m_col0)[i];
    }
};

struct MoppRotation : public MoppMatrix3
{
};

struct MoppTransform
{
    MoppRotation m_rotation;
    MoppVec4 m_translation;

    const MoppRotation& getRotation() const
    {
        return m_rotation;
    }

    const MoppVec4& getTranslation() const
    {
        return m_translation;
    }
};

template <typename T>
class MoppPadSpu
{
public:
    __forceinline MoppPadSpu() {}
    __forceinline MoppPadSpu(T e) : m_storage(e) {}
    __forceinline void operator=(T e) { m_storage = e; }
    __forceinline T val() const { return m_storage; }
    __forceinline T operator->() const { return m_storage; }
    __forceinline operator T() const { return val(); }
private:
    T m_storage;
};

template <typename T>
struct MoppArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

struct MoppCode
{
    void* vftable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    int pad08;
    int pad0c;

    struct CodeInfo
    {
        MoppVec4 m_offset;

        float getScale() const
        {
            return m_offset(3);
        }
    };

    CodeInfo m_info;
    MoppArray<unsigned char> m_data;
    signed char m_buildType;
};

struct MoppPrimitiveInfo;

__declspec(align(16)) struct MoppObbQuery
{
    int m_xHi;
    int m_yHi;
    int m_zHi;
    int m_HiPadding;
    int m_xLo;
    int m_yLo;
    int m_zLo;
    int m_LoPadding;
    int m_offset_x;
    int m_offset_y;
    int m_offset_z;
    unsigned int m_primitiveOffset;
    int m_shift;
    unsigned int m_properties0;
};

class MoppVirtualMachine
{
public:
    MoppArray<MoppPrimitiveInfo>* m_primitives_out;
    int m_pad04;
    int m_pad08;
    int m_pad0c;

    void initQuery(MoppArray<MoppPrimitiveInfo>* primitives_out)
    {
        m_primitives_out = primitives_out;
    }

    static int toIntMin(float x)
    {
        return fnv_FloatToInt(x) - 1;
    }

    static int toIntMax(float x)
    {
        return fnv_FloatToInt(x) + 1;
    }
};

class MoppObbVirtualMachine : public MoppVirtualMachine
{
public:
    int m_xHi;
    int m_yHi;
    int m_zHi;
    int m_HiPadding;
    int m_xLo;
    int m_yLo;
    int m_zLo;
    int m_LoPadding;
    MoppPadSpu<const MoppCode*> m_code;
    MoppPadSpu<int> m_reindexingMask;

    __declspec(noinline) void FUN_00a52420(const MoppObbQuery* query, const unsigned char* PC, int chunkOffset)
    {
        if (*PC == 0 && query->m_xHi < chunkOffset)
        {
            m_primitives_out = 0;
        }
    }

    __forceinline void generateQueryFromNode(const MoppVec4& extent, const MoppTransform& BvToWorld, const float radius, MoppObbQuery& query)
    {
        const MoppRotation& rot = BvToWorld.getRotation();
        MoppVec4 e0; e0.setBroadcast3clobberW(extent, 0);
        MoppVec4 e1; e1.setBroadcast3clobberW(extent, 1);
        MoppVec4 e2; e2.setBroadcast3clobberW(extent, 2);

        MoppVec4 transformedX; transformedX.setMul4(e0, rot.getColumn(0));
        MoppVec4 transformedY; transformedY.setMul4(e1, rot.getColumn(1));
        MoppVec4 transformedZ; transformedZ.setMul4(e2, rot.getColumn(2));

        transformedX.setAbs4(transformedX);
        transformedY.setAbs4(transformedY);
        transformedZ.setAbs4(transformedZ);

        {
            MoppVec4 max; max.setAdd4(transformedX, transformedY);
            max.add4(transformedZ);

            MoppVec4 rad4; rad4.setAll(radius);
            max.add4(rad4);

            MoppVec4 min; min.setNeg4(max);

            MoppVec4 offset; offset.setSub4(BvToWorld.getTranslation(), m_code->m_info.m_offset);
            max.add4(offset);
            min.add4(offset);

            float scale = m_code->m_info.getScale();
            max.mul4(scale);
            min.mul4(scale);

            m_xLo = toIntMin(min(0));
            m_xHi = toIntMax(max(0));
            m_yLo = toIntMin(min(1));
            m_yHi = toIntMax(max(1));
            m_zLo = toIntMin(min(2));
            m_zHi = toIntMax(max(2));
        }

        query.m_xLo = m_xLo >> 16;
        query.m_xHi = (m_xHi >> 16) + 1;
        query.m_yLo = m_yLo >> 16;
        query.m_yHi = (m_yHi >> 16) + 1;
        query.m_zLo = m_zLo >> 16;
        query.m_zHi = (m_zHi >> 16) + 1;

        query.m_offset_x = 0;
        query.m_offset_y = 0;
        query.m_offset_z = 0;
        query.m_primitiveOffset = 0;
        query.m_shift = 0;
        query.m_properties0 = 0;
    }

    void FUN_00a52bd0(const MoppCode* code, const MoppTransform& BvToWorld, const MoppVec4& extent, const float radius, MoppArray<MoppPrimitiveInfo>* primitives_out);
};

// pdb: hkpMoppObbVirtualMachine::queryObb | hkpMoppObbVirtualMachine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: code, BvToWorld, extent, radius, primitives_out
void MoppObbVirtualMachine::FUN_00a52bd0(const MoppCode* code, const MoppTransform& BvToWorld, const MoppVec4& extent, const float radius, MoppArray<MoppPrimitiveInfo>* primitives_out)
{
    m_code = code;
    initQuery(primitives_out);

    MoppObbQuery query;
    generateQueryFromNode(extent, BvToWorld, radius, query);

    const unsigned char* programCounter = &m_code->m_data[0];
    m_reindexingMask = (programCounter[0] == 0x0d) ? -1 : 0;
    FUN_00a52420(&query, programCounter, 0);
}
}   // namespace f3m_00a52bd0

// @f3 0x00a5f950 (community match, verified in this file)
namespace f3m_00a5f950 {
namespace f3m_00a5f950 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct Vec4Array {
    Vec4* data;
    int size;
    int capAndFlags;
    void pushBack(const Vec4& v);
};
void __cdecl FUN_00901f10(Vec4Array* a, int elemSize);
inline void Vec4Array::pushBack(const Vec4& v)
{
    if (size == (capAndFlags & 0x3fffffff))
        FUN_00901f10(this, sizeof(Vec4));
    data[size++] = v;
}
struct Options {
    char unk00;
    bool restore;
    bool simplify;
    char unk03;
    float tolerance;
};
struct Hull {
    int unk00;
    int unk04;
    int size;
};
int __cdecl FUN_00a58a60(const void* a, const void* b);
void __cdecl FUN_00a58ce0(Vec4Array* pts, Vec4* center, Vec4* extent);
void __cdecl FUN_00a58f00(Vec4Array* pts, Vec4* center, Vec4* extent);
void __cdecl FUN_00a56e20(Vec4* data, int lo, int hi, int (__cdecl* cmp)(const void*, const void*));
void __cdecl FUN_00a59780(float tolerance, Vec4Array* pts, int* count);
void __cdecl FUN_00a5b5d0(Vec4Array* pts, float eps);
void __cdecl FUN_00a5f4b0(const Options* opts, Vec4Array* pts, int lo, int hi, Hull* hull);
void __cdecl FUN_00a5d5d0(Hull* hull, Vec4Array* pts);
void __cdecl FUN_00a59d00(Vec4Array* pts);
void __cdecl FUN_00a5bbb0(Hull* hull, int lo, int hi, const Options* opts, bool* changed);
}

// pdb: hkGeomConvexHullBuilder::buildConvexHull | hkGeomConvexHullBuilder.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_00a5f950(const f3m_00a5f950::Options* opts, const f3m_00a5f950::Vec4* points, int count,
                          f3m_00a5f950::Hull* hull, f3m_00a5f950::Vec4Array* pts)
{
    using namespace f3m_00a5f950;
    pts->size = 0;
    for (int i = 0; i < count; i++)
        pts->pushBack(points[i]);
    Vec4 extent;
    Vec4 center;
    if (opts->restore)
        FUN_00a58ce0(pts, &center, &extent);
    if (pts->size > 1)
        FUN_00a56e20(pts->data, 0, pts->size - 1, FUN_00a58a60);
    int n;
    FUN_00a59780(opts->tolerance, pts, &n);
    if (opts->simplify && n < 300)
        FUN_00a5b5d0(pts, 0.001f);
    bool changed = true;
    bool stable = false;
    while (!stable || changed) {
        stable = !changed;
        for (int j = 0; j < pts->size; j++)
            pts->data[j].w = 0.0f;
        hull->size = 0;
        FUN_00a5f4b0(opts, pts, 0, pts->size - 1, hull);
        FUN_00a5d5d0(hull, pts);
        FUN_00a59d00(pts);
        FUN_00a5bbb0(hull, 0, pts->size - 1, opts, &changed);
        FUN_00a59d00(pts);
    }
    if (opts->restore)
        FUN_00a58f00(pts, &center, &extent);
}
}   // namespace f3m_00a5f950

// @f3 0x00a55b40 (community match, verified in this file)
#include <math.h>
namespace f3m_00a55b40 {
namespace f3m_00a55b40 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void normalize3()
    {
        float len2 = x * x + y * y + z * z;
        float inv;
        if (len2 != 0.0f) inv = 1.0f / sqrtf(len2); else inv = 0.0f;
        x *= inv; y *= inv; z *= inv; w *= inv;
    }
};
}

void __cdecl FUN_00a55b40(const f3m_00a55b40::Vec4* a, const f3m_00a55b40::Vec4* b, const f3m_00a55b40::Vec4* c, f3m_00a55b40::Vec4* n)
{
    using namespace f3m_00a55b40;
    Vec4 e[2];
    e[0].x = b->x - a->x; e[0].y = b->y - a->y; e[0].z = b->z - a->z;
    e[1].x = c->x - b->x; e[1].y = c->y - b->y; e[1].z = c->z - b->z;
    n->x = e[0].y * e[1].z - e[0].z * e[1].y;
    n->y = e[0].z * e[1].x - e[0].x * e[1].z;
    n->z = e[0].x * e[1].y - e[0].y * e[1].x;
    n->w = 0.0f;
    n->normalize3();
}
}   // namespace f3m_00a55b40

// @f3 0x00a59a70 (community match, verified in this file)
#include <math.h>
extern const float DAT_00e7c758;
extern const double DAT_00db5748;
namespace f3m_00a59a70 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
__forceinline float InverseSqrt42(float value) { if(value!=0) return 1.0f/(float)sqrt(value); return 0.0f; }
struct __declspec(align(16)) Vector42 {
    float x,y,z,w;
    Vector42 operator-(const Vector42& b) const { Vector42 r; r.x=x-b.x; r.y=y-b.y; r.z=z-b.z; r.w=w-b.w; return r; }
    void Cross(const Vector42& a,const Vector42& b) {
        float ny=a.z*b.x-a.x*b.z;
        float nz=a.x*b.y-a.y*b.x;
        x=a.y*b.z-a.z*b.y;
        y=ny; z=nz; w=0;
    }
    float Dot(const Vector42& b) const { return x*b.x+y*b.y+z*b.z; }
    __forceinline float DotFinal(const Vector42& b) const { double t=(double)x*b.x; return (float)(t+y*b.y+z*b.z); }
    float LengthSquared() const { return x*x+y*y+z*z; }
    void Negate() { x=-x; y=-y; z=-z; w=DAT_00e7c758; }
    __forceinline void Normalize() {
        float length=LengthSquared();
        float scale=InverseSqrt42(length);
        float v=x*scale; x=v;
        v=y*scale; y=v;
        v=z*scale; z=v;
        w*=scale;
    }
};
struct Array42 { Vector42* data; int count,capacity; void SetSize(int); Vector42& Expand() { int old=count; SetSize(count+1); return data[old]; } };
void __cdecl FUN_00901e90(Array42*,int,int);
inline void Array42::SetSize(int size) {
    int cap=capacity&0x3fffffff;
    if(cap<size) { int newCap=2*cap; if(size>=newCap) newCap=size; FUN_00901e90(this,newCap,16); }
    count=size;
}
// pdb: hkGeomConvexHullBuilder::createBevelPlane | hkGeomConvexHullBuilder.obj | tesv_win, call_gap, low
void __cdecl FUN_00a59a70(const Vector42* direction,const Vector42* a,const Vector42* b,const Vector42* c,Array42* output) {
    Vector42& plane=output->Expand();
    Vector42 delta=*a-*b;
    plane.Cross(*direction,delta);
    delta=*c-*b;
    if(plane.Dot(delta)>1.0e-6f) plane.Negate();
    if(plane.LengthSquared()>DAT_00db5748) {
        plane.Normalize();
        plane.w=-plane.DotFinal(*a);
    } else output->SetSize(output->count-1);
}
}   // namespace f3m_00a59a70

// @f3 0x00a41080 (community match, verified in this file)
#include <math.h>
namespace f3m_00a41080 {

struct __declspec(align(16)) Sa41080_Vec4
{
    float v[4];

    float& operator()(int i) { return v[i]; }
    const float& operator()(int i) const { return v[i]; }

    void setCross(const Sa41080_Vec4& v1, const Sa41080_Vec4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        v[0] = nx;
        v[1] = ny;
        v[2] = nz;
    }
};

struct Sa41080_Pair
{
    Sa41080_Vec4 a;
    Sa41080_Vec4 b;
};

struct Sa41080_Obj
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
    float scale;
};

static __declspec(noinline) void FUN_00a41080(const Sa41080_Pair* p, const Sa41080_Vec4* s, const Sa41080_Vec4* d,
    const Sa41080_Obj* o0, const Sa41080_Obj* o1, float* outDot, float* outSum)
{
    Sa41080_Vec4 c2;
    Sa41080_Vec4 c1;
    const Sa41080_Vec4& sv = *s;
    c1.setCross(p->a, sv);
    c2.setCross(p->b, sv);
    double dy = c2(1);
    double dx = c2(0);
    double dz = c2(2);
    double ey = c1(1);
    double ex = c1(0);
    double ez = c1(2);
    float l1 = sqrtf((float)(ex * ex + ey * ey + ez * ez));
    float r1 = l1 * o0->scale;
    float l2 = sqrtf((float)(dx * dx + dy * dy + dz * dz));
    float r2 = l2 * o1->scale;
    *outSum = r2 + r1;
    *outDot = (*d)(1) * (*s)(1) + (*s)(0) * (*d)(0) + (*d)(2) * (*s)(2);
}

volatile int g_in;
volatile float g_out;
void Sa41080_caller()
{
    static Sa41080_Pair p;
    static Sa41080_Vec4 s, d;
    static Sa41080_Obj o0, o1;
    float a, b;
    FUN_00a41080(&p, &s, &d, &o0, &o1, &a, &b);
    g_out = a + b;
}
}   // namespace f3m_00a41080

// @f3 0x00a542a0 (community match, verified in this file)
extern const double DAT_00dfc230;
namespace f3m_00a542a0 {
struct VecA542 {
    __declspec(align(16)) float x;float y,z,w;
    void Zero(){x=y=z=w=0.0f;}
    void Sub(const VecA542& a,const VecA542& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
    void Mul(float s){x*=s;y*=s;z*=s;w*=s;}
    VecA542& operator=(const VecA542& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
};
struct BoundsA542 {VecA542 a,b;int first,second;BoundsA542& operator=(const BoundsA542& v){a=v.a;b=v.b;first=v.first;second=v.second;return*this;}};
struct ShapeA542 {unsigned char type;};
struct BodyA542 {int unk00;int unk04;int unk08;int unk0C;VecA542 center;ShapeA542* shape; void* Shape(){return shape;} };
struct QueryA542 {VecA542 offset;int count;float tolerance;void* cache;int flags;};
struct CastA542 {
    int unk00;int unk04;int unk08;int unk0C;BodyA542* body;float inverse;int unk18;int unk1C;
    VecA542 boundA,boundB;int boundFirst,boundSecond;
    int unk48;int unk4C;
    bool hit;unsigned char unk51;unsigned short unk52;
    float fraction;void* context;int unk5C;int unk60;void* data;int index;
    void FUN_00a53120(QueryA542*,ShapeA542*,VecA542*,int);
    void FUN_00a542a0(bool*,void*,BodyA542*,const BoundsA542*,void*);
};
// pdb: hkpMoppLongRayVirtualMachine::queryLongRay | hkpMoppLongRayVirtualMachine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: collection, code, input, rayResult
void CastA542::FUN_00a542a0(bool* output,void* user,BodyA542* object,const BoundsA542* input,void* ctx)
{
    fraction=1.0f;
    data=user;
    context=ctx;
    body=object;
    ShapeA542* shape=static_cast<ShapeA542*>(body->Shape());
    QueryA542 query;
    query.offset.Zero();
    inverse=1.0f/object->center.w;
    query.tolerance=object->center.w * DAT_00dfc230;
    VecA542 delta[2];
    delta[0].Sub(input->a,object->center);
    delta[1].Sub(input->b,object->center);
    delta[0].Mul(query.tolerance);
    delta[1].Mul(query.tolerance);
    boundA=input->a;boundB=input->b;boundFirst=input->first;boundSecond=input->second;
    hit=false;
    query.cache=0;
    query.count=0;
    query.flags=0;
    index=shape->type==13?-1:0;
    FUN_00a53120(&query,shape,delta,0);
    *output=hit;
}
}   // namespace f3m_00a542a0

// @f3 0x00a46dc0 (community match, verified in this file)
namespace f3m_00a46dc0 {
namespace S00a46dc0_ns
{
struct S00a46dc0_Entry { const char* FUN_009b0490(); };
struct S00a46dc0_Manager
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void* Lookup(const char*);
};
struct S00a46dc0_Registry { S00a46dc0_Manager* FUN_009b20b0(const char*); };
extern S00a46dc0_Registry* DAT_011693ac;
extern unsigned char DAT_0116a994;
const char* __cdecl FUN_0093e470();
int __cdecl hkString_strCmp(const char*, const char*);
struct S00a46dc0_Context
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Apply(S00a46dc0_Entry*, void*, void*);
    virtual void Slot7();
    virtual void Release(void*);
};
struct S00a46dc0_HashBase { unsigned long FUN_009227d0(unsigned long key, unsigned long def) const; };
template <class K, class V> struct S00a46dc0_Map
{
    S00a46dc0_HashBase m_map;
    V getWithDefault(K key, V def) const { return (V)m_map.FUN_009227d0((unsigned long)key, (unsigned long)def); }
};
struct S00a46dc0_Data
{
    virtual void Destroy(int);
    int f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    S00a46dc0_Map<void*, const char*> m_finish;
    int f2c, f30;
    void* m_topLevelObject;
    const char* getFinish(void* const& p) const { return m_finish.getWithDefault(p, 0); }
};
struct S00a46dc0_Ref
{
    virtual void Destroy(int);
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void removeReference() {
        if (m_memSizeAndFlags != 0) {
            --m_referenceCount;
            if (m_referenceCount == 0)
                Destroy(1);
        }
    }
};
struct S00a46dc0_Owner
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual S00a46dc0_Context* GetContext();
    virtual const char* GetName();
    int f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74;
    S00a46dc0_Data* data;
    S00a46dc0_Entry** entries;
    int count;
    void FUN_00a49aa0();
    void FUN_00a466b0(void*);
    S00a46dc0_Ref* FUN_00a46950();
    void* FUN_00a46060();
    const char* FUN_00a460a0();
    void* FUN_00a46dc0(const char*, void*);
};
void* S00a46dc0_Owner::FUN_00a46dc0(const char* expected, void* input)
{
    FUN_00a49aa0();
    if (input)
        FUN_00a466b0(input);
    void* contentsPtr;
    const char* contentsType;
    if (data)
    {
        contentsPtr = data->m_topLevelObject;
        contentsType = data->getFinish(data->m_topLevelObject);
    }
    else
    {
        if (!hkString_strCmp(FUN_0093e470(), GetName()))
        {
            S00a46dc0_Registry* registry = DAT_011693ac;
            S00a46dc0_Manager* manager = registry->FUN_009b20b0(GetName());
            if (manager)
            {
                S00a46dc0_Ref* reference = FUN_00a46950();
                S00a46dc0_Context* context = GetContext();
                for (int i = 0; i < count; ++i)
                {
                    S00a46dc0_Entry* entry = entries[i];
                    void* found = manager->Lookup(entry->FUN_009b0490());
                    if (found)
                    {
                        context->Apply(entry, found, &DAT_0116a994);
                        context->Release(found);
                    }
                }
                reference->removeReference();
                contentsPtr = data->m_topLevelObject;
                contentsType = data->getFinish(data->m_topLevelObject);
                if (data)
                    data->Destroy(1);
                data = 0;
                goto compare;
            }
        }
        contentsPtr = FUN_00a46060();
        contentsType = FUN_00a460a0();
    }
compare:
    if (expected && contentsType && hkString_strCmp(expected, contentsType))
        return 0;
    return contentsPtr;
}
}
}   // namespace f3m_00a46dc0

// @f3 0x00a58ce0 (community match, verified in this file)
namespace f3m_00a58ce0 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_00a58ce0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline float get(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d = 0.0f) {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void clear() { x = y = z = w = 0.0f; }
    __forceinline void copy(const Vec4& a) {
        x = a.x; y = a.y; z = a.z; w = a.w;
    }
    __forceinline void sub(const Vec4& a, const Vec4& b) {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
};
extern const Vec4 DAT_01092a50;
struct Bounds { Vec4 min, max; };
struct Mat3 {
    Vec4 col[3];
    __forceinline void clear() {
        Vec4 zero; zero.clear();
        col[0].copy(zero); col[1].copy(zero); col[2].copy(zero);
    }
    __forceinline void setDiagonal(float a, float b, float c) {
        clear(); col[0].x = a; col[1].y = b; col[2].z = c;
    }
    __forceinline void setRows(const Vec4& a, const Vec4& b, const Vec4& c) {
        col[0].set(a.x, b.x, c.x);
        col[1].set(a.y, b.y, c.y);
        col[2].set(a.z, b.z, c.z);
    }
    __forceinline void getRow(int i, Vec4& v) const {
        v.set((&col[0].x)[i], (&col[1].x)[i], (&col[2].x)[i]);
    }
    void FUN_0096d070(const Mat3&);
};
struct Vec4Array { Vec4* data; int size, capAndFlags; };
void __cdecl FUN_00a58b30(Vec4Array*, Bounds*);
}

// pdb: hkGeomConvexHullBuilder::convertToUnitCube | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a58ce0(f3m_00a58ce0::Vec4Array* pts, f3m_00a58ce0::Vec4* extent, f3m_00a58ce0::Vec4* center)
{
    using namespace f3m_00a58ce0;
    // Fake match: this scope permits bounds storage to be reused by the vertex temporary.
    {
        Bounds b;
        FUN_00a58b30(pts, &b);
        // Fake match: addition operand order preserves the target's x87 evaluation order.
        center->x = (float)(b.max.x + b.min.x) * 0.5;
        center->y = (float)(b.min.y + b.max.y) * 0.5;
        center->z = (float)(b.max.z + b.min.z) * 0.5;
        center->w = (float)(b.max.w + b.min.w) * 0.5;
        extent->x = b.max.x - b.min.x;
        extent->y = b.max.y - b.min.y;
        extent->z = b.max.z - b.min.z;
        extent->w = b.max.w - b.min.w;
    }
    Mat3 scale;
    scale.setDiagonal(extent->get(0) > 1.1920929e-07f ? 1.0f / extent->get(0) : 1.0f,
                      extent->get(1) > 1.1920929e-07f ? 1.0f / extent->get(1) : 1.0f,
                      extent->get(2) > 1.1920929e-07f ? 1.0f / extent->get(2) : 1.0f);
    Mat3 t;
    for (int i = 0; i < pts->size; ++i) {
        Vec4 d;
        d.sub(pts->data[i], *center);
        t.setRows(d, DAT_01092a50, DAT_01092a50);
        t.FUN_0096d070(scale);
        t.getRow(0, pts->data[i]);
    }
}
}   // namespace f3m_00a58ce0

// @f3 0x00a51e40 (community match, verified in this file)
namespace f3m_00a51e40 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
struct __declspec(align(16)) V51
{
    float x, y, z, w;
    __forceinline void product(const V51& lhs, const V51& rhs)
    {
        x = lhs.x * rhs.x; y = lhs.y * rhs.y;
        z = lhs.z * rhs.z; w = lhs.w * rhs.w;
    }
    // Fake match: separate helper and named z input select the target's x87 operand order.
    __forceinline void adjacentProduct(const V51& lhs, const V51& rhs)
    {
        x = lhs.x * rhs.x; y = lhs.y * rhs.y;
        float q = rhs.z; z = lhs.z * q; w = lhs.w * rhs.w;
    }
    __forceinline void weight(const V51& rhs)
    {
        x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w;
    }
    __forceinline void accumulate(const V51& rhs)
    {
        x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w;
    }
    __forceinline void subtract(const V51& rhs)
    {
        x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w;
    }
    __forceinline void sum(const V51& lhs, const V51& rhs)
    {
        x = lhs.x + rhs.x; y = lhs.y + rhs.y;
        z = lhs.z + rhs.z; w = lhs.w + rhs.w;
    }
    __forceinline void broadcastW(const V51& rhs)
    {
        float s = rhs.w;
        x = s; y = s; z = s; w = s;
    }
    __forceinline float sum3() const { return (x + y) + z; }
    __forceinline float sum4() const { return ((x + y) + z) + w; }
};
struct Acc51
{
    unsigned char type;
    unsigned int state;
    float factor;
    V51 linear, angular, mass;
};
struct Off51
{
    int offset;
    __forceinline const Acc51& at(const Acc51* base) const
    { return *(const Acc51*)((const char*)base + offset); }
};
struct Jac51
{
    V51 linear;
    V51 angular[2];
    __forceinline float diagonal(const Acc51& a, const Acc51& b) const
    {
        V51 left; left.product(angular[0], angular[0]);
        V51 right; right.product(angular[1], angular[1]);
        // Fake match: set-product spelling selects the first scaling multiply's operand order.
        left.product(a.mass, left); right.weight(b.mass);
        left.accumulate(right);
        V51 masses; masses.sum(a.mass, b.mass);
        left.w = masses.w;
        float value = left.sum4();
        return float(value + 1.1920928955078125e-07);
    }
    __forceinline float adjacent(const Acc51& b, const Jac51& next) const
    {
        V51 lin; lin.product(linear, next.linear);
        V51 ang; ang.adjacentProduct(angular[1], next.angular[0]);
        V51 mass; mass.broadcastW(b.mass);
        V51 scaled; scaled.product(mass, lin);
        ang.weight(b.mass);
        ang.subtract(scaled);
        return ang.sum3();
    }
};
struct Tri51 { float lower, diagonal, upper; };
__forceinline float max51(float a, float b) { return a > b ? a : b; }
// Fake match: internal linkage and the caller below expose the target's private register ABI.
// pdb: buildConstraintMatrixLuDecompositionForStiffSpringChain | hkpChainBuildJacobian.obj | tesv_win, objrun, medium
static __declspec(noinline) void FUN_00a51e40(int count, float damping, Jac51* rows, Off51* offsets, const Acc51* base, Tri51* output, int bufferSize)
{
    float previous = 0.0f;
    float upper = 0.0f;
    for (int index = 0; index < count; ++index)
    {
        float diagonal = rows[index].diagonal(offsets[index].at(base), offsets[index + 1].at(base)) + damping;
        float adjacent = 0.0f;
        if (index < count - 1)
            adjacent = rows[index].adjacent(offsets[index + 1].at(base), rows[index + 1]);
        output[index].lower = previous;
        output[index].diagonal = diagonal - previous * upper;
        float& d = output[index].diagonal;
        d = max51(d, 1.1920928955078125e-07f);
        output[index].upper = adjacent / output[index].diagonal;
        previous = adjacent;
        upper = output[index].upper;
    }
}
// Fake match: volatile inputs keep the ABI-demonstration caller from being constant-folded.
volatile int inputCount51;
volatile float inputDamping51;
Jac51* volatile inputRows51;
Off51* volatile inputOffsets51;
const Acc51* volatile inputBase51;
Tri51* volatile inputOutput51;
volatile int inputSize51;
void caller51()
{
    FUN_00a51e40(inputCount51, inputDamping51, inputRows51, inputOffsets51, inputBase51, inputOutput51, inputSize51);
}
}   // namespace f3m_00a51e40

// @f3 0x00a507b0 (community match, verified in this file)
namespace f3m_00a507b0 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace motor_a507b0 {
struct Matrix;
struct __declspec(align(16)) Vector {
    float x, y, z, w;
    __forceinline float& at(int i) { return (&x)[i]; }
    __forceinline const float& at(int i) const { return (&x)[i]; }
    __forceinline void operator=(const Vector& b) {
        x=b.x; y=b.y; z=b.z; w=b.w;
    }
    __forceinline void difference(const Vector& a, const Vector& b) {
        x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w;
    }
    __forceinline void cross(const Vector& a, const Vector& b) {
        float cx=a.at(1)*b.at(2)-a.at(2)*b.at(1);
        float cy=a.at(2)*b.at(0)-a.at(0)*b.at(2);
        float cz=a.at(0)*b.at(1)-a.at(1)*b.at(0);
        x=cx; y=cy; z=cz; w=0.0f;
    }
    __forceinline void product(const Vector& a, const Vector& b) {
        x=a.x*b.x; y=a.y*b.y; z=a.z*b.z; w=a.w*b.w;
    }
    __forceinline void multiply(const Vector& a) {
        x*=a.x; y*=a.y; z*=a.z; w*=a.w;
    }
    __forceinline void add(const Vector& a) {
        x+=a.x; y+=a.y; z+=a.z; w+=a.w;
    }
    __forceinline float sum() const { return x+y+z+w; }
    __forceinline void matrixProduct(const Matrix& m, const Vector& b);
    __forceinline void rotate(const Matrix& m, const Vector& b) { matrixProduct(m,b); }
};
struct Matrix {
    Vector c0, c1, c2;
    __forceinline const Vector& column(int c) const { return (&c0)[c]; }
    __forceinline const float& at(int r,int c) const { return column(c).at(r); }
};
__forceinline void Vector::matrixProduct(const Matrix& m,const Vector& b) {
    // Fake match: the vector snapshot reproduces the compiler's x87 operand ordering.
    Vector copy; copy=b;
    float bx=copy.at(0);
    float by=copy.at(1);
    float bz=copy.at(2);
    Vector& dest=*this;
    dest.at(0)=m.at(0,0)*bx+m.at(0,1)*by+m.at(0,2)*bz;
    dest.at(1)=m.at(1,0)*bx+m.at(1,1)*by+m.at(1,2)*bz;
    dest.at(2)=m.at(2,0)*bx+m.at(2,1)*by+m.at(2,2)*bz;
    dest.at(3)=0.0f;
}
struct Body {
    unsigned char kind, flag01;
    unsigned int state04;
    Vector velocity10, velocity20, weights30, center40;
    Matrix basis50;
};
struct Input {
    float f00,f04,f08,f0c,f10,f14,f18,f1c,f20,f24;
    const void* p28;
    const void* p2c;
    const Body* p0;
    const Body* p1;
};
struct Output { Vector linear, a, b; };
__forceinline void build(const Vector& v,const Vector& p,const Body& A,const Body& B,Output& o) {
    o.linear=v;
    Vector da,db;
    da.difference(p,A.center40);
    db.difference(p,B.center40);
    {
        Vector c;
        c.cross(da,v);
        if(A.flag01) o.a=c;
        else o.a.rotate(A.basis50,c);
    }
    {
        Vector c;
        c.cross(v,db);
        if(B.flag01) o.b=c;
        else o.b.rotate(B.basis50,c);
    }
}
__forceinline float mass(const Body& A,const Body& B,Output& o) {
    Vector aa,bb;
    aa.product(o.a,o.a);
    bb.product(o.b,o.b);
    aa.product(aa,A.weights30);
    bb.multiply(B.weights30);
    aa.add(bb);
    aa.w=B.weights30.w+A.weights30.w;
    float d=aa.sum();
    d=d+1.1920928955078125e-7;
    o.b.w=d;
    d=1.0f/d;
    o.a.w=d;
    return d;
}
}
// pdb: hk1dLinearVelocityMotorBeginJacobian | hkpMotorBuildJacobian.obj | fnv360_0822_retail, objrun, medium
// pdb params: directionOfConstraint, pivot, in, jac, statusOut
void FUN_00a507b0(const motor_a507b0::Vector& v,const motor_a507b0::Vector& p,
                  const motor_a507b0::Input& h,motor_a507b0::Output& o,float& r) {
    const motor_a507b0::Body* A=h.p0;
    const motor_a507b0::Body* B=h.p1;
    motor_a507b0::build(v,p,*A,*B,o);
    r=motor_a507b0::mass(*A,*B,o);
}
}   // namespace f3m_00a507b0

// @f3 0x00a4e900 (community match, verified in this file)
namespace f3m_00a4e900 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace A4e900 {
struct __declspec(align(16)) V {
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a,float b,float c,float d) { x=a; y=b; z=c; w=d; }
    __forceinline void operator=(const V& a) { x=a.x; y=a.y; z=a.z; w=a.w; }
    __forceinline void sub(const V& a,const V& b) { x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w; }
    __forceinline void cross(const V& a,const V& b) {
        (&x)[0]=a(1)*b(2)-a(2)*b(1);
        (&x)[1]=a(2)*b(0)-a(0)*b(2);
        (&x)[2]=a(0)*b(1)-a(1)*b(0);
        w=0.0f;
    }
    __forceinline void mul(const V& a,const V& b) { x=a.x*b.x; y=a.y*b.y; z=a.z*b.z; w=a.w*b.w; }
    __forceinline void mul(const V& b) { x*=b.x; y*=b.y; z*=b.z; w*=b.w; }
    __forceinline void add(const V& b) { x+=b.x; y+=b.y; z+=b.z; w+=b.w; }
    __forceinline float sum() const { return x+y+z+w; }
};
struct Body {
    unsigned char unk00, flag;
    int unk04,unk08,unk0c;
    V velocity,spin,inertia,position,col0,col1,col2;
};
struct Holder { int unk00; float f04; };
struct Input { V position,direction; float f20; Holder* p24; };
struct Pair {
    int unk00; float f04; int unk08,unk0c,unk10,unk14,unk18;
    float f1c,f20; int unk24,unk28,unk2c; Body* p30; Body* p34;
};
struct Entry { V linear,angularA,angularB; float f30; int unk34,unk38,unk3c; };
struct Output { Entry* cursor; };
__forceinline void rotate(V& dst,const Body& body,const V& src) {
    if (body.flag) { dst.x=src.x; dst.y=src.y; dst.z=src.z; }
    else {
        dst.x=body.col1.x*src.y+body.col0.x*src.x+body.col2.x*src.z;
        dst.y=body.col1.y*src.y+body.col0.y*src.x+body.col2.y*src.z;
        dst.z=body.col1.z*src.y+body.col0.z*src.x+body.col2.z*src.z;
    }
    dst.w=0.0f;
}
__forceinline void build(const Input& input,const Pair& pair,Output& output) {
    // Fake match: named reference at helper entry preserves cross-product operand ranking.
    const V& direction=input.direction;
    Entry* entry=output.cursor;
    float scale=pair.f20;
    const Body* a=pair.p30;
    const Body* b=pair.p34;
    entry->linear=direction;
    {
        V da; da.sub(input.position,a->position);
        V db; db.sub(input.position,b->position);
        {
            // Fake match: redundant alias preserves the original x87 operand ordering.
            const V& delta=da; V c; c.cross(delta,direction);
            rotate(entry->angularA,*a,c);
        }
        {
            // Fake match: redundant alias preserves the original x87 operand ordering.
            const V& delta=db; V c; c.cross(direction,delta);
            rotate(entry->angularB,*b,c);
        }
    }
    {
        V va; va.mul(entry->angularA,entry->angularA);
        V vb; vb.mul(entry->angularB,entry->angularB);
        va.mul(a->inertia);
        vb.mul(b->inertia);
        va.add(vb);
        va.w=a->inertia.w+b->inertia.w;
        float denom=va.sum();
        denom=(float)(denom+1.1920928955078125e-7);
        entry->angularB.w=denom;
        entry->angularA.w=scale/denom;
    }
    entry->linear.w=input.p24->f04*pair.f1c;
}
}
// pdb: hk1dLinearFrictionBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: hk1dLinearBilateralConstraintBuildJacobian)
// pdb params: info, in, out
void __cdecl FUN_00a4e900(const A4e900::Input& input,const A4e900::Pair& pair,A4e900::Output& output) {
    A4e900::build(input,pair,output);
    A4e900::Entry* entry=output.cursor;
    output.cursor=entry+1;
    entry->f30=input.f20*pair.f04;
    entry->linear.x=(float)(entry->linear.x+1.1920928955078125e-7);
    *(unsigned char*)entry=8;
}
}   // namespace f3m_00a4e900

// @f3 0x00a41f60 (community match, verified in this file)
namespace f3m_00a41f60 {
// Havok, x87 build of the math library: closest point of a GSK query between two convex shapes.
// The transform of B relative to A is built, the GSK solver gives the separating normal in A space (distance in w),
// the normal is rotated into world space, and the closest point is chosen from the solver's simplex and brought into
// B space. Stand-in types; unknown fields are named by offset.
// The function is static (file-local) in the original: under /O2 it receives wTb, wTa and normalOut in eax, esi and
// edi, so it is written as a static noinline function with one ordinary caller that makes the compiler emit it.

namespace xqa41f60 {

// FPU build: a scalar wrapped in a class, passed by const reference
class hkSimdReal
{
public:
    __forceinline hkSimdReal(float x) : m_real(x) {}
    __forceinline float getReal() const { return m_real; }

    float m_real;
};
typedef const hkSimdReal& hkSimdRealParameter;

struct hkQuadReal { float v[4]; };
class hkRotation;
class hkTransform;

class __declspec(align(16)) hkVector4
{
public:
    hkQuadReal m_quad;

    __forceinline void operator=(const hkVector4& o)
    {
        m_quad.v[0] = o.m_quad.v[0];
        m_quad.v[1] = o.m_quad.v[1];
        m_quad.v[2] = o.m_quad.v[2];
        m_quad.v[3] = o.m_quad.v[3];
    }
    __forceinline float& operator()(int i) { return m_quad.v[i]; }
    __forceinline const float& operator()(int i) const { return m_quad.v[i]; }

    // this += r * a
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        float r = rs.getReal();
        m_quad.v[0] += r * a.m_quad.v[0];
        m_quad.v[1] += r * a.m_quad.v[1];
        m_quad.v[2] += r * a.m_quad.v[2];
        m_quad.v[3] += r * a.m_quad.v[3];
    }
    // this -= r * a
    __forceinline void subMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        float r = rs.getReal();
        m_quad.v[0] -= r * a.m_quad.v[0];
        m_quad.v[1] -= r * a.m_quad.v[1];
        m_quad.v[2] -= r * a.m_quad.v[2];
        m_quad.v[3] -= r * a.m_quad.v[3];
    }

    // this = r * b
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& b);
    // this = inverse(a) * b, b a position
    __forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
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

class hkRotation : public hkMatrix3 {};

class hkTransform
{
public:
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    // this = inverse(a) * b
    void FUN_00925300(const hkTransform& a, const hkTransform& b);
};

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    const float t0 = r(0,0)*b0 + r(0,1)*b1 + r(0,2)*b2;
    m_quad.v[0] = t0;
    const float t1 = r(1,0)*b0 + r(1,1)*b1 + r(1,2)*b2;
    m_quad.v[1] = t1;
    const float t2 = r(2,0)*b0 + r(2,1)*b1 + r(2,2)*b2;
    m_quad.v[2] = t2;
    m_quad.v[3] = 0;
}

__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& a, const hkVector4& b)
{
    const float v0 = b(0) - a.getTranslation()(0);
    const float v1 = b(1) - a.getTranslation()(1);
    const float v2 = b(2) - a.getTranslation()(2);
    const hkRotation& r = a.getRotation();
    m_quad.v[0] = r(0,0)*v0 + r(1,0)*v1 + r(2,0)*v2;
    m_quad.v[1] = r(0,1)*v0 + r(1,1)*v1 + r(2,1)*v2;
    m_quad.v[2] = r(0,2)*v0 + r(1,2)*v1 + r(2,2)*v2;
    m_quad.v[3] = 0;
}

struct hkpConvexShape
{
    void* vtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float m_radius;
};

// GSK solver state: dimension of the simplex on each shape, the simplex vertices, the closest point on A
struct hkpGsk
{
    int m_dimA;
    int m_dimB;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    hkVector4 m_verticesA[4];
    hkVector4 unk60[4];
    hkVector4 m_verticesBinA[4];
    hkVector4 unke0[4];
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    hkVector4 m_closestPointA;

    // runs the solver; separating normal in A space, distance in w
    void hkpGsk_getClosestFeature(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb,
                      hkVector4& separatingNormalOut);
};

// pdb: hk4dGskCalcSeparatingNormal | hkpContinuousGsk.obj | tesv_win, caller_sim, low
static __declspec(noinline) void FUN_00a41f60(const hkTransform* wTb, const hkTransform* wTa, hkVector4* normalOut,
                                              const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, hkpGsk* gsk,
                                              hkVector4* pointOut)
{
    hkTransform aTb;
    aTb.FUN_00925300(*wTa, *wTb);

    hkVector4 separatingNormal;
    gsk->hkpGsk_getClosestFeature(shapeA, shapeB, aTb, separatingNormal);

    normalOut->_setRotatedDir(wTa->getRotation(), separatingNormal);

    const float distance = separatingNormal(3);
    hkVector4 pointInA;
    if (gsk->m_dimA == 1)
    {
        pointInA = gsk->m_verticesA[0];
    }
    else if (gsk->m_dimB == 1)
    {
        pointInA = gsk->m_verticesBinA[0];
        pointInA.addMul4(distance, separatingNormal);
    }
    else
    {
        pointInA = gsk->m_closestPointA;
    }
    pointInA.subMul4(distance, separatingNormal);
    pointOut->_setTransformedInversePos(aTb, pointInA);
    (*normalOut)(3) = distance - shapeA->m_radius - shapeB->m_radius;
}

volatile hkTransform* g_wTb;
volatile hkTransform* g_wTa;
volatile hkVector4* g_normalOut;
volatile hkpConvexShape* g_shapeA;
volatile hkpConvexShape* g_shapeB;
volatile hkpGsk* g_gsk;
volatile hkVector4* g_pointOut;

void caller_of_FUN_00a41f60()
{
    FUN_00a41f60((hkTransform*)g_wTb, (hkTransform*)g_wTa, (hkVector4*)g_normalOut, (hkpConvexShape*)g_shapeA,
                 (hkpConvexShape*)g_shapeB, (hkpGsk*)g_gsk, (hkVector4*)g_pointOut);
}

}
}   // namespace f3m_00a41f60

// @f3 0x00a58460 (community match, verified in this file)
#include <math.h>
namespace f3m_00a58460 {
namespace f3m_00a58460 {

typedef float Real;

__forceinline Real mathSqrt(Real r) { return sqrtf(r); }
__forceinline Real mathSqrtInverse(Real r) { return 1.0f / mathSqrt(r); }
__forceinline Real mathFabs(Real r) { return fabsf(r); }
struct SimdReal
{
    Real m_real;
    __forceinline SimdReal() {}
    __forceinline SimdReal(Real x) { m_real = x; }
    __forceinline operator Real() const { return m_real; }
};

struct __declspec(align(16)) Vec4
{
    Real x;
    Real y;
    Real z;
    Real w;

    __forceinline Real& operator()(int i) { return (&x)[i]; }
    __forceinline const Real& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(Real a, Real b, Real c, Real d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    __forceinline void setSub4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void mul4(const SimdReal& rs)
    {
        x *= rs;
        y *= rs;
        z *= rs;
        w *= rs;
    }

    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const Real nx = v1(1) * v2(2) - v1(2) * v2(1);
        const Real ny = v1(2) * v2(0) - v1(0) * v2(2);
        const Real nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    __forceinline SimdReal dot3(const Vec4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

    __forceinline Real lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }

    __forceinline SimdReal lengthInverse3() const
    {
        Real l2 = (x * x) + (y * y) + (z * z);
        return l2 ? mathSqrtInverse(l2) : 0;
    }

    __forceinline void normalize3()
    {
        this->mul4(this->lengthInverse3());
    }
};

struct Config
{
    int unk00;
    int unk04;
    Real minLengthSquared;
    int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Real tolerance;
};

__forceinline Real pseudoAngle(Real cosA, Real sinA, Real tolerance)
{
    const Real eps = 1e-6f;
    Real angle;
    if (mathFabs(sinA) < eps && mathFabs(cosA) < 1e-7f)
    {
        if (cosA < 0.0f)
            angle = 4.0f;
        else
            angle = 0.0f;
    }
    else if (mathFabs(cosA) < mathFabs(sinA))
    {
        angle = 2.0f - cosA / sinA;
        angle = ((sinA < -eps) ? 4.0f : 0.0f) + angle;
    }
    else
    {
        angle = sinA / cosA;
        if (cosA < -1.0f + eps && mathFabs(sinA) < eps)
            angle = 4.0f;
        else
            angle = ((cosA < -eps) ? 4.0f : 0.0f) + angle;
        if (mathFabs(angle) < tolerance)
            angle = 0.0f;
        else
            angle = angle + ((cosA > eps && mathFabs(sinA) < 1e-7f) ? 8.0f : 0.0f);
    }
    if (angle < -tolerance)
        angle = angle + 8.0f;
    if (angle > 8.0f)
        angle = 0.0f;
    return angle;
}

// pdb: hkGeomConvexHullBuilder::getAngleBetweenVertexAndPlane | hkGeomConvexHullBuilder.obj | tesv_win, uconst, low
Real __cdecl FUN_00a58460(const Config* config, const Vec4& a, const Vec4& normal, const Vec4& b, const Vec4& c)
{
    Vec4 dir;
    dir.setSub4(a, b);
    if (dir.lengthSquared3() < config->minLengthSquared)
        return 0.0f;
    dir.normalize3();
    Real sinA = -normal.dot3(dir);

    Vec4 edge;
    edge.setSub4(b, c);
    Vec4 perp;
    perp.setCross(edge, normal);
    perp.normalize3();
    Real cosA = perp.dot3(dir);

    if (cosA * cosA + sinA * sinA < config->minLengthSquared)
        return 1.70141e+38f;
    return pseudoAngle(cosA, sinA, config->tolerance);
}

}
}   // namespace f3m_00a58460

// @f3 0x00a58180 (community match, verified in this file)
#include <math.h>
#include <float.h>
namespace f3m_00a58180 {

namespace ScalarMath
{
    inline float Root(float n) { return sqrtf(n); }
    inline float InverseRoot(float n) { return 1.0f / Root(n); }
    inline float Magnitude(float n) { return fabsf(n); }
}

struct __declspec(align(16)) Vector
{
    float x, y, z, w;
    __forceinline void Set(float xx, float yy, float zz, float ww)
    {
        x = xx;
        y = yy;
        z = zz;
        w = ww;
    }
    __forceinline void Subtract(const Vector& lhs, const Vector& rhs)
    {
        x = lhs.x - rhs.x;
        y = lhs.y - rhs.y;
        z = lhs.z - rhs.z;
        w = lhs.w - rhs.w;
    }
    __forceinline void Cross(const Vector& lhs, const Vector& rhs)
    {
        const float xx = lhs.y * rhs.z - lhs.z * rhs.y;
        const float yy = lhs.z * rhs.x - lhs.x * rhs.z;
        const float zz = lhs.x * rhs.y - lhs.y * rhs.x;
        Set(xx, yy, zz, 0.0f);
    }
    __forceinline float Dot(const Vector& rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    __forceinline float LengthSq() const { return Dot(*this); }
    __forceinline float InverseLength() const
    {
        float lenSq = x*x + y*y + z*z;
        return lenSq ? ScalarMath::InverseRoot(lenSq) : 0;
    }
    __forceinline void Scale(float s)
    {
        
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void Normalize()
    {
        Scale(InverseLength());
    }
};

// pdb: hkGeomConvexHullBuilder::getPlaneEquationZaxis | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a58180(const Vector& a, const Vector& b, Vector& out)
{
    Vector d;
    d.Set(a.x-b.x, a.y-b.y, a.z-b.z, 0.0f);
    if (ScalarMath::Magnitude(a.x - b.x) < 1e-6f && ScalarMath::Magnitude(a.y - b.y) < 1e-6f)
    {
        out.w = out.w;
        Vector axis;
        axis.Set(1.0f, 0.0f, 0.0f, 0.0f);
        out.Cross(d, axis);
        out.Normalize();
    }
    else
    {
        Vector axis;
        axis.Set(0.0f, 1.0f, 0.0f, 0.0f);
        d.Normalize();
        out.Cross(d, axis);
        if (out.LengthSq() < FLT_EPSILON)
        {
            Vector fallback;
            fallback.Set(0.0f, 0.0f, 1.0f, 0.0f);
            out.Cross(d, fallback);
        }
        out.Normalize();
    }
}
}   // namespace f3m_00a58180

// @f3 0x00a4ebf0 (community match, verified in this file)
namespace f3m_00a4ebf0 {
namespace qa4ebf0 {

// Havok FPU vector, matrix and velocity accumulator as this function uses them.
struct __declspec(align(16)) Vector4
{
    float x, y, z, w;
    inline float& operator()(int i) { return (&x)[i]; }
    inline const float& operator()(int i) const { return (&x)[i]; }
};

struct Matrix3
{
    Vector4 col0, col1, col2;
    inline const Vector4& getColumn(int i) const { return (&col0)[i]; }
    inline const float& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct VelocityAccumulator
{
    unsigned char type;
    unsigned char matrixIsIdentity;
    unsigned char unk02;
    unsigned char unk03;
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
    Vector4 invMasses;
    Vector4 centerOfMass;
    Matrix3 coreFromWorld;
};

struct ConstraintQueryIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float rhsFactor;
    float virtMassFactor;
    int unk24;
    int unk28;
    int unk2c;
    VelocityAccumulator* bodyA;
    VelocityAccumulator* bodyB;
};

struct LinearBilateralInfo
{
    Vector4 pivotA;
    Vector4 pivotB;
    Vector4 constrainedDof;
};

struct Lin2AngJacobian
{
    Vector4 linear;
    Vector4 angularA;
    Vector4 angularB;
};

struct ConstraintQueryOut
{
    Lin2AngJacobian* jacobians;
};

__forceinline void setRotatedDir(Vector4& dst, const Matrix3& m, const Vector4& b)
{
    const float v0 = b(0);
    const float v1 = b(1);
    const float v2 = b(2);
    dst.x = m(0, 0) * v0 + m(0, 1) * v1 + m(0, 2) * v2;
    dst.y = m(1, 0) * v0 + m(1, 1) * v1 + m(1, 2) * v2;
    dst.z = m(2, 0) * v0 + m(2, 1) * v1 + m(2, 2) * v2;
}

__forceinline void setMul4(Vector4& dst, const Vector4& a, const Vector4& b)
{
    dst.x = a.x * b.x;
    dst.y = a.y * b.y;
    dst.z = a.z * b.z;
    dst.w = a.w * b.w;
}

__forceinline float dotf(const Vector4& a, const Vector4& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

// pdb: hk1dLinearBilateralConstraintBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: info, in, out
void FUN_00a4ebf0(const LinearBilateralInfo& in, const ConstraintQueryIn& info, ConstraintQueryOut& out)
{
    Lin2AngJacobian* jac = out.jacobians;
    jac->linear.x = jac->linear.x;
    float tau = info.virtMassFactor;
    const VelocityAccumulator* A = info.bodyA;
    const VelocityAccumulator* B = info.bodyB;
    float rhsScale = info.rhsFactor;
    jac->linear.x = in.constrainedDof.x;
    jac->linear.w = jac->linear.w;
    jac->linear.y = in.constrainedDof.y;
    jac->linear.z = in.constrainedDof.z;
    jac->linear.w = in.constrainedDof.w;
    Vector4 rA;
    rA.x = in.pivotA.x - A->centerOfMass.x;
    rA.y = in.pivotA.y - A->centerOfMass.y;
    rA.z = in.pivotA.z - A->centerOfMass.z;
    Vector4 rB;
    rB.x = in.pivotA.x - B->centerOfMass.x;
    rB.y = in.pivotA.y - B->centerOfMass.y;
    rB.z = in.pivotA.z - B->centerOfMass.z;
    {
        Vector4 t;
        t.x = rA.y * in.constrainedDof.z - rA.z * in.constrainedDof.y;
        t.y = rA.z * in.constrainedDof.x - rA.x * in.constrainedDof.z;
        t.z = rA.x * in.constrainedDof.y - rA.y * in.constrainedDof.x;
        if (A->matrixIsIdentity)
        {
            jac->angularA.x = t.x;
            jac->angularA.y = t.y;
            jac->angularA.z = t.z;
        }
        else
        {
            setRotatedDir(jac->angularA, A->coreFromWorld, t);
        }
        jac->angularA.w = 0.0f;
    }
    {
        Vector4 t;
        t.x = in.constrainedDof.y * rB.z - in.constrainedDof.z * rB.y;
        t.y = in.constrainedDof.z * rB.x - in.constrainedDof.x * rB.z;
        t.z = in.constrainedDof.x * rB.y - in.constrainedDof.y * rB.x;
        if (B->matrixIsIdentity)
        {
            jac->angularB.x = t.x;
            jac->angularB.y = t.y;
            jac->angularB.z = t.z;
        }
        else
        {
            setRotatedDir(jac->angularB, B->coreFromWorld, t);
        }
        jac->angularB.w = 0.0f;
    }
    Vector4 sA;
    setMul4(sA, jac->angularA, jac->angularA);
    Vector4 sB;
    setMul4(sB, jac->angularB, jac->angularB);
    sA.x = A->invMasses.x * sA.x;
    sA.y = A->invMasses.y * sA.y;
    sA.z = A->invMasses.z * sA.z;
    sB.x = B->invMasses.x * sB.x;
    sB.y = B->invMasses.y * sB.y;
    sB.z = B->invMasses.z * sB.z;
    sA.x = sB.x + sA.x;
    sA.y = sB.y + sA.y;
    sA.z = sB.z + sA.z;
    sA.w = B->invMasses.w + A->invMasses.w;
    float s = sA.y + sA.x + sA.z + sA.w;
    s = s + 1.1920928955078125e-07;
    jac->angularB.w = s;
    jac->angularA.w = tau / s;
    rB.x = in.pivotA.x - in.pivotA.x;
    rB.y = in.pivotA.y - in.pivotA.y;
    rB.z = in.pivotA.z - in.pivotA.z;
    // Only the first product is parenthesised: that puts the x product first in the sum, as in the original
    // (a guess at the source; the plain or fully parenthesised dot computes the y product first).
    float rhs = (rB.x * in.constrainedDof.x) + rB.y * in.constrainedDof.y + rB.z * in.constrainedDof.z;
    jac->linear.w = rhs * rhsScale;
    jac++;
    Lin2AngJacobian* j = jac - 1;
    Vector4 d;
    d.x = in.pivotB.x - in.pivotA.x;
    d.y = in.pivotB.y - in.pivotA.y;
    d.z = in.pivotB.z - in.pivotA.z;
    float rhs2 = dotf(d, in.constrainedDof);
    j->linear.w = rhs2 * info.rhsFactor;
    j->linear.x = j->linear.x + 1.1920928955078125e-07;
    *(unsigned char*)&j->linear.x = 5;
    out.jacobians = jac;
}
}
}   // namespace f3m_00a4ebf0

// @f3 0x00a413c0 (community match, verified in this file)
extern const double DAT_00dc8080;
namespace f3m_00a413c0 {
// Havok 5.5 hk4dGskCalcPointVelocityAssumingAngularVelError (hkpContinuousGsk.cpp, static). Layouts from the Havok 5.5 headers.
namespace f3h_00a413c0 {

typedef float hkReal;
typedef float hkTime;

struct hkSimdReal
{
    hkReal m_real;
    __forceinline hkSimdReal() {}
    __forceinline hkSimdReal(hkReal x) { m_real = x; }
    __forceinline operator hkReal() const { return m_real; }
};

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkReal rt)
    {
        hkReal t = hkReal(rt);
        hkReal s = 1.0f - t;
        hkVector4& d = *this;
        d(0) = s * v0(0) + t * v1(0);
        d(1) = s * v0(1) + t * v1(1);
        d(2) = s * v0(2) + t * v1(2);
        d(3) = s * v0(3) + t * v1(3);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
};

class hkTransform
{
public:
    hkVector4 m_rotation[3];
    hkVector4 m_translation;
};

class hkSweptTransform
{
public:
    __forceinline hkReal getInterpolationValue(hkTime t) const
    {
        hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
        return dt;
    }
    __forceinline hkTime getBaseTime() const { return m_centerOfMass0(3); }
    __forceinline hkReal getInvDeltaTime() const { return m_centerOfMass1(3); }

    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkVector4 m_rotation0;
    hkVector4 m_rotation1;
    hkVector4 m_centerOfMassLocal;
};

class hkMotionState
{
public:
    __forceinline const hkSweptTransform& getSweptTransform() const { return m_sweptTransform; }

    hkTransform m_transform;
    hkSweptTransform m_sweptTransform;
    hkVector4 m_deltaAngle;
    hkReal m_objectRadius;
    hkReal m_linearDamping;
    hkReal m_angularDamping;
};

// Static in the original: under /O2 it receives separatingNormal, deltaAngles, separatingPoint and msB in edx, ecx,
// edi and esi, so it is written as a static noinline function with one ordinary caller that makes the compiler emit it.
// pdb: hk4dGskCalcPointVelocityAssumingAngularVelError | hkpContinuousGsk.obj | fnv360_0822_debug, objrun_prop, low
static __declspec(noinline) hkReal FUN_00a413c0(const hkMotionState* msA, const hkMotionState* msB,
                           const hkVector4& separatingPoint, const hkVector4& separatingNormal,
                           const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t)
{
    hkVector4 linVel;
    linVel.setNeg4(linearTimInfo);
    hkReal separatingVelocity = separatingNormal.dot3(linVel);
    {
        const hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_centerOfMass0, msA->getSweptTransform().m_centerOfMass1, relT);
        // Guess at the source: an unused direct read of a local vector's x lane. It emits nothing, but it puts the
        // x product first in the angVel dot product below and keeps the second body's interpolation in the original's
        // operand order (any local vector's x lane, anywhere in this block, does the same).
        (void)linVel.x;
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        const hkReal angVel = arm.dot3(separatingNormal);
        if (angVel <= 0.0f) { separatingVelocity += angVel * DAT_00dc8080; } else { separatingVelocity += angVel / DAT_00dc8080; }
    }
    {
        const hkSweptTransform& st = msB->getSweptTransform();
        const hkReal relT = st.getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(st.m_centerOfMass0, st.m_centerOfMass1, relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        const hkSimdReal angVel = separatingNormal.dot3(arm);
        if (angVel >= 0.0f) { separatingVelocity -= angVel * DAT_00dc8080; } else { separatingVelocity -= angVel / DAT_00dc8080; }
    }
    return separatingVelocity;
}

// One of the file's callers (the real ones are the 4D GSK step functions in the same file).
float hk4dGskCallerStandIn(const hkMotionState* msA, const hkMotionState* msB, const hkVector4* points,
                           const hkVector4& normal, const hkVector4& lin, const hkVector4* deltaAngles, hkTime t)
{
    return FUN_00a413c0(msA, msB, points[0], normal, lin, deltaAngles, t)
         + FUN_00a413c0(msA, msB, points[1], normal, lin, deltaAngles, t);
}

} // namespace f3h_00a413c0
}   // namespace f3m_00a413c0

// @f3 0x00a41610 (community match, verified in this file)
namespace f3m_00a41610 {
// Havok, x87 build of the math library: set up the working frames of a two-body query at an interpolated time.
// Both bodies' transforms are interpolated, the transform of B relative to A is built, and the query's points and
// directions are brought into the frames the solver uses. Stand-in types; unknown fields are named by offset.

struct hkQuadReal { float v[4]; };
class hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    hkQuadReal m_quad;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& o)
    {
        m_quad.v[0] = o.m_quad.v[0];
        m_quad.v[1] = o.m_quad.v[1];
        m_quad.v[2] = o.m_quad.v[2];
        m_quad.v[3] = o.m_quad.v[3];
    }
    __forceinline void operator=(const hkVector4& o)
    {
        m_quad.v[0] = o.m_quad.v[0];
        m_quad.v[1] = o.m_quad.v[1];
        m_quad.v[2] = o.m_quad.v[2];
        m_quad.v[3] = o.m_quad.v[3];
    }
    __forceinline float& operator()(int i) { return m_quad.v[i]; }
    __forceinline const float& operator()(int i) const { return m_quad.v[i]; }

    // this = transpose(r) * b; b may be this, so its components are read first
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);

    // out-of-line transforms of one vector by a transform
    void hkVector4_setRotatedDir(void* transform, void* v);
    void hkVector4_setTransformedPos(void* transform, void* v);
    void FUN_00477880(void* transform, void* v);
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

class hkRotation : public hkMatrix3 {};

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    m_quad.v[0] = r(0,0)*b0 + r(1,0)*b1 + r(2,0)*b2;
    m_quad.v[1] = r(0,1)*b0 + r(1,1)*b1 + r(2,1)*b2;
    m_quad.v[2] = r(0,2)*b0 + r(1,2)*b1 + r(2,2)*b2;
    m_quad.v[3] = 0;
}

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    // this = inverse(a) * b
    void FUN_00925300(void* a, void* b);
};

// time information of the step: unk00 is the time, unk08 scales the caller's factor
struct StepInfo
{
    float unk00;
    float unk04;
    float unk08;
};

struct QueryInput
{
    char* unk00;            // body A: swept transform at +0x40, a vector at +0x80
    char* unk04;            // body B, same layout
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    float unk14;
    unsigned unk18;
    unsigned unk1c;
    hkVector4 unk20;
    hkVector4 unk30;
    StepInfo* unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    hkVector4 unk50;
    hkVector4 unk60[2];
};

struct QueryFrames
{
    hkTransform first;      // body A at the interpolated time
    hkTransform second;     // body B at the interpolated time
    hkTransform relative;   // B relative to A
    hkVector4 unkc0;
    hkVector4 unkd0;
    hkVector4 unke0;
    hkVector4 unkf0[2];
    hkVector4 unk110;
    hkVector4 unk120;
};

// interpolates a swept transform at a time
void hkSweptTransformUtil_lerp2Ha(char* swept, float time, float step, void* transformOut);

// rotates numVectors directions by the inverse of t; the rotation is copied first because the output may overlap it
static __forceinline void rotateInversePoints(const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkRotation unaligned = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setRotatedInverseDir(unaligned, vectorsIn[i]);
    }
    while (--i >= 0);
}

// pdb: hk4dGskCollideInitMatrices | hkpContinuousGsk.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: input, Rt, out
void FUN_00a41610(QueryInput* a, float f, QueryFrames* out)
{
    StepInfo* b = a->unk40;
    float t = b->unk08 * f;
    hkSweptTransformUtil_lerp2Ha(a->unk00 + 0x40, b->unk00, t, out);
    hkSweptTransformUtil_lerp2Ha(a->unk04 + 0x40, b->unk00, t, &out->second);
    hkTransform* m = &out->relative;
    m->FUN_00925300(out, &out->second);
    out->unkc0.hkVector4_setRotatedDir(m, &a->unk20);
    out->unkd0.hkVector4_setTransformedPos(m, &a->unk30);
    out->unkc0(3) = -a->unk14;
    out->unk110 = *(hkVector4*)(a->unk00 + 0x80);
    rotateInversePoints(out->first.m_rotation, a->unk60, 2, out->unkf0);
    out->unk120.hkVector4_setTransformedPos(m, a->unk04 + 0x80);
    out->unke0.FUN_00477880(out, &a->unk50);
}
}   // namespace f3m_00a41610

// @f3 0x00a4e410 (community match, verified in this file)
namespace f3m_00a4e410 {
namespace f3m_00a4e410 {

struct Matrix;

__forceinline float SumComponents(float first, float second, float third) {
    return first + second + third;
}

struct __declspec(align(16)) Vector4 {
    float x, y, z, w;

    __forceinline void Set(const Vector4& v) {
        x = v.x; y = v.y; z = v.z; w = v.w;
    }
    __forceinline void SetNegated(const Vector4& v) {
        x = -v.x; y = -v.y; z = -v.z; w = -v.w;
    }
    __forceinline void SetProduct(const Vector4& a, const Vector4& b) {
        x = a.x * b.x; y = a.y * b.y;
        z = a.z * b.z; w = a.w * b.w;
    }
    __forceinline void Multiply(const Vector4& v) {
        x *= v.x; y *= v.y; z *= v.z; w *= v.w;
    }
    __forceinline void Add(const Vector4& v) {
        x += v.x; y += v.y; z += v.z; w += v.w;
    }
    __forceinline float Sum3() const {
        return SumComponents(x, y, z);
    }
    __forceinline void SetRotated(const Matrix& matrix, const Vector4& v);
};

struct Matrix {
    Vector4 column0, column1, column2;
};

__forceinline void Vector4::SetRotated(const Matrix& matrix, const Vector4& v) {
    float vx = v.x, vy = v.y, vz = v.z;
    x = matrix.column0.x * vx + matrix.column1.x * vy + matrix.column2.x * vz;
    y = matrix.column0.y * vx + matrix.column1.y * vy + matrix.column2.y * vz;
    z = matrix.column0.z * vx + matrix.column1.z * vy + matrix.column2.z * vz;
    w = 0.0f;
}

struct Body {
    unsigned char unk00, identityRotation, unk02, unk03;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    Vector4 inverseInertia;
    unsigned int unk40, unk44, unk48, unk4c;
    Matrix rotation;
};

struct Input {
    Vector4 vector0;
    Vector4 direction;
    Vector4 vector20;
};

struct Context {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18;
    float velocityScale;
    float responseScale;
    unsigned int unk24, unk28, unk2c;
    Body* bodyA;
    Body* bodyB;
};

struct Output {
    Vector4 angularA;
    Vector4 angularB;
};

// pdb: hk1dAngularBilateralConstraintBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0721_beta, objrun_prop, medium
// pdb params: info, in, out
void __cdecl FUN_00a4e410(const Input* input, const Context* context, Output** cursor) {
    Output* output = *cursor;
    float responseScale = context->responseScale;
    Body* bodyA = context->bodyA;
    Body* bodyB = context->bodyB;

    if (bodyA->identityRotation)
        output->angularA.Set(input->direction);
    else
        output->angularA.SetRotated(bodyA->rotation, input->direction);

    if (bodyB->identityRotation)
        output->angularB.SetNegated(input->direction);
    else {
        Vector4 negative;
        negative.SetNegated(input->direction);
        output->angularB.SetRotated(bodyB->rotation, negative);
    }

    const Vector4& v0 = input->vector0;
    const Vector4& v2 = input->vector20;
    Vector4 weightedA, weightedB;
    weightedA.SetProduct(output->angularA, output->angularA);
    weightedB.SetProduct(output->angularB, output->angularB);
    weightedA.Multiply(bodyA->inverseInertia);
    weightedB.Multiply(bodyB->inverseInertia);
    weightedA.Add(weightedB);
    float sum = weightedA.Sum3();
    const double bias = 1.1920928955078125e-7;
    sum = static_cast<float>(sum + bias);
    output->angularA.w = responseScale / sum;

    float dot = v0.x * v2.x + v0.y * v2.y + v0.z * v2.z;
    double velocity = -dot * context->velocityScale;
    *cursor = output + 1;
    output->angularB.w = velocity;
    output->angularA.x = static_cast<float>(output->angularA.x + bias);
    reinterpret_cast<unsigned char*>(output)[0] = 0x0b;
}

}
}   // namespace f3m_00a4e410

// @f3 0x00a4ef60 (community match, verified in this file)
namespace f3m_00a4ef60 {
// Same as v1 with the query-in layout corrected so bodyA/bodyB sit at 0x30/0x34.
__declspec(align(16)) struct Vec4 {
    float x, y, z, w;

    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }

    void operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void set(float a, float b, float c, float d = 0.0f) { x = a; y = b; z = c; w = d; }
    void setW(const Vec4& v) { w = v.w; }
    void add4(const Vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    void setAdd4(const Vec4& v0, const Vec4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    void setSub4(const Vec4& v0, const Vec4& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    void mul4(const Vec4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    void setMul4(const Vec4& a, const Vec4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }

    void setCross(const Vec4& v1, const Vec4& v2) {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    float horizontalAdd4() const { return x + y + z + w; }

    void setMul3(const struct Mat3& r, const Vec4& v);
    void setRotatedDir(const struct Rotation& r, const Vec4& v);
};

struct Mat3 {
    Vec4 col0;
    Vec4 col1;
    Vec4 col2;
    float operator()(int r, int c) const { return (&col0)[c](r); }
};

struct Rotation : public Mat3 {
};

__forceinline void Vec4::setMul3(const Mat3& r, const Vec4& v) {
    float v0 = v(0);
    float v1 = v(1);
    float v2 = v(2);
    Vec4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0.0f;
}

__forceinline void Vec4::setRotatedDir(const Rotation& r, const Vec4& v) {
    setMul3(r, v);
}

template <typename T>
struct PadSlot {
    T storage;
    operator T() const { return storage; }
    T val() const { return storage; }
};

struct BodyAccumulator {
    unsigned char type;
    unsigned char context;
    unsigned short unk02;
    unsigned int deactivationClass;
    float gravityFactor;
    int unk0c;
    Vec4 linearVel;
    Vec4 angularVel;
    Vec4 invMasses;
    Vec4 centerOfMass;
    Rotation coreFromWorld;

    const Vec4& getCenterOfMassInWorld() const { return centerOfMass; }
    const Rotation& getCoreFromWorldMatrix() const { return coreFromWorld; }
};

struct QueryStepInfo {
    PadSlot<float> substepDeltaTime;
    PadSlot<float> microStepDeltaTime;
    PadSlot<float> substepInvDeltaTime;
    PadSlot<float> frameDeltaTime;
    PadSlot<float> frameInvDeltaTime;
    PadSlot<float> invNumSteps;
    PadSlot<float> invNumStepsTimesMicroSteps;
    PadSlot<float> rhsFactor;
    PadSlot<float> virtMassFactor;
    int unk24;
    int unk28;
    int unk2c;
};

struct ConstraintQueryIn : public QueryStepInfo {
    PadSlot<const BodyAccumulator*> bodyA;
    PadSlot<const BodyAccumulator*> bodyB;
};

struct LinearBilateralConstraintInfo {
    Vec4 pivotA;
    Vec4 pivotB;
    Vec4 constrainedDofW;
};

struct Lin2AngJacobian {
    Vec4 linear0;
    Vec4 angular0;
    Vec4 angular1;

    void setRHS(float r) { linear0(3) = r; }
    void setInvJacDiag(float d) { angular0(3) = d; }
    void setUserValue(float u) { angular1(3) = u; }

    __forceinline float getDiag(const BodyAccumulator& mA, const BodyAccumulator& mB) const {
        const Lin2AngJacobian* jac = this;
        Vec4 ang0; ang0.setMul4(jac->angular0, jac->angular0);
        Vec4 ang1; ang1.setMul4(jac->angular1, jac->angular1);

        ang0.mul4(mA.invMasses);
        ang1.mul4(mB.invMasses);
        ang0.add4(ang1);

        Vec4 sm; sm.setAdd4(mA.invMasses, mB.invMasses);
        ang0.setW(sm);
        float dot = ang0.horizontalAdd4();
        return dot + 1.1920929e-7f;
    }
};

__forceinline void buildLinearBegin(
    const BodyAccumulator* opaA,
    const BodyAccumulator* opaB,
    const Vec4& position,
    const Vec4& direction,
    float invJacFactor,
    Lin2AngJacobian& jac)
{
    jac.linear0 = direction;
    Vec4 massCenterRelative0; massCenterRelative0.setSub4(position, opaA->getCenterOfMassInWorld());
    Vec4 massCenterRelative1; massCenterRelative1.setSub4(position, opaB->getCenterOfMassInWorld());

    Vec4 cross0; cross0.setCross(massCenterRelative0, direction);
    if (opaA->context != 0) {
        jac.angular0 = cross0;
    } else {
        jac.angular0.setRotatedDir(opaA->getCoreFromWorldMatrix(), cross0);
    }

    Vec4 cross1; cross1.setCross(direction, massCenterRelative1);
    if (opaB->context != 0) {
        jac.angular1 = cross1;
    } else {
        jac.angular1.setRotatedDir(opaB->getCoreFromWorldMatrix(), cross1);
    }

    float a = jac.getDiag(*opaA, *opaB);
    jac.setUserValue(a);
    jac.setInvJacDiag(invJacFactor / a);
}

__forceinline void buildLinearEnd(Lin2AngJacobian& jac, float rhs, float rhsFactor) {
    jac.setRHS(rhs * rhsFactor);
}

__forceinline void flushJacobian() {}

// pdb: hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema_inline | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
static __declspec(noinline) void hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema_inline(
    const LinearBilateralConstraintInfo& info,
    const ConstraintQueryIn& in,
    Lin2AngJacobian& jac,
    float customRhs)
{
    const BodyAccumulator* accuA = in.bodyA;
    const BodyAccumulator* accuB = in.bodyB;
    buildLinearBegin(accuA, accuB, info.pivotA, info.constrainedDofW, in.virtMassFactor, jac);
    buildLinearEnd(jac, customRhs, in.rhsFactor);
    flushJacobian();
}

const LinearBilateralConstraintInfo* volatile inputInfo_a4ef60;
const ConstraintQueryIn* volatile inputQuery_a4ef60;
Lin2AngJacobian* volatile outputJacobian_a4ef60;
volatile float inputRhs_a4ef60;

void caller_of_a4ef60()
{
    hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema_inline(*inputInfo_a4ef60, *inputQuery_a4ef60,
                 *outputJacobian_a4ef60, inputRhs_a4ef60);
}
}   // namespace f3m_00a4ef60

// @f3 0x00a4f510 (community match, verified in this file)
namespace f3m_00a4f510 {

__declspec(align(16)) struct Vec4_a4f510
{
    float x;
    float y;
    float z;
    float w;

    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const Vec4_a4f510& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    __forceinline void setW(const Vec4_a4f510& v)
    {
        w = v.w;
    }

    __forceinline void add4(const Vec4_a4f510& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }

    __forceinline void setAdd4(const Vec4_a4f510& v0, const Vec4_a4f510& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setSub4(const Vec4_a4f510& v0, const Vec4_a4f510& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void mul4(const Vec4_a4f510& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }

    __forceinline void setMul4(const Vec4_a4f510& a, const Vec4_a4f510& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }

    __forceinline void setCross(const Vec4_a4f510& v1, const Vec4_a4f510& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    __forceinline float horizontalAdd4() const
    {
        return x + y + z + w;
    }

    __forceinline void _setMul3(const struct Mat3_a4f510& r, const Vec4_a4f510& v);
    __forceinline void _setRotatedDir(const struct Mat3_a4f510& r, const Vec4_a4f510& v);
};

struct Mat3_a4f510
{
    Vec4_a4f510 m_col0;
    Vec4_a4f510 m_col1;
    Vec4_a4f510 m_col2;

    __forceinline Vec4_a4f510& getColumn(int x) { return (&m_col0)[x]; }
    __forceinline const Vec4_a4f510& getColumn(int x) const { return (&m_col0)[x]; }

    __forceinline float& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};

__forceinline void Vec4_a4f510::_setMul3(const Mat3_a4f510& r, const Vec4_a4f510& v)
{
    float v0 = v(0);
    float v1 = v(1);
    float v2 = v(2);
    Vec4_a4f510& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline void Vec4_a4f510::_setRotatedDir(const Mat3_a4f510& r, const Vec4_a4f510& v)
{
    _setMul3(r, v);
}

template <typename T>
struct PadSpu_a4f510
{
    T m_storage;
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return val(); }
};

struct VelAcc_a4f510
{
    unsigned char m_type;
    unsigned char m_context;
    unsigned short m_pad02;
    unsigned int m_deactivationClass;
    float m_gravityFactor;
    int m_pad0c;
    Vec4_a4f510 m_linearVel;
    Vec4_a4f510 m_angularVel;
    Vec4_a4f510 m_invMasses;
    Vec4_a4f510 m_scratch0;
    Mat3_a4f510 m_scratch123;

    __forceinline const Vec4_a4f510& getCenterOfMassInWorld() const { return m_scratch0; }
    __forceinline const Mat3_a4f510& getCoreFromWorldMatrix() const { return m_scratch123; }
};

struct QueryIn_a4f510
{
    PadSpu_a4f510<float> m_substepDeltaTime;
    PadSpu_a4f510<float> m_microStepDeltaTime;
    PadSpu_a4f510<float> m_substepInvDeltaTime;
    PadSpu_a4f510<float> m_frameDeltaTime;
    PadSpu_a4f510<float> m_frameInvDeltaTime;
    PadSpu_a4f510<float> m_invNumSteps;
    PadSpu_a4f510<float> m_invNumStepsTimesMicroSteps;
    PadSpu_a4f510<float> m_rhsFactor;
    PadSpu_a4f510<float> m_virtMassFactor;
    PadSpu_a4f510<float> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
    PadSpu_a4f510<const VelAcc_a4f510*> m_bodyA;
    PadSpu_a4f510<const VelAcc_a4f510*> m_bodyB;
};

struct Jacobian_a4f510
{
    Vec4_a4f510 m_linear0;
    Vec4_a4f510 m_angular[2];

    __forceinline void setRHS(float val) { m_linear0(3) = val; }
    __forceinline void setInvJacDiag(float val) { m_angular[0](3) = val; }
    __forceinline void setUserValue(float val) { m_angular[1](3) = val; }

    __forceinline float getDiag(const VelAcc_a4f510& mA, const VelAcc_a4f510& mB) const
    {
        const Jacobian_a4f510* jac = this;
        Vec4_a4f510 ang0; ang0.setMul4(jac->m_angular[0], jac->m_angular[0]);
        Vec4_a4f510 ang1; ang1.setMul4(jac->m_angular[1], jac->m_angular[1]);

        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);

        Vec4_a4f510 sm; sm.setAdd4(mA.m_invMasses, mB.m_invMasses);
        ang0.setW(sm);
        float dot = ang0.horizontalAdd4();

        return float(dot + double(1.1920929e-07f));
    }
};

struct BilateralInfo_a4f510
{
    Vec4_a4f510 m_pivotA;
    Vec4_a4f510 m_pivotB;
    Vec4_a4f510 m_constrainedDofW;
};

static __forceinline void buildLinearBegin_a4f510(
    const VelAcc_a4f510* opaA,
    const VelAcc_a4f510* opaB,
    const Vec4_a4f510& position,
    const Vec4_a4f510& direction,
    float invJacFactor,
    Jacobian_a4f510& jac)
{
    jac.m_linear0 = direction;

    Vec4_a4f510 massCenterRelative0; massCenterRelative0.setSub4(position, opaA->getCenterOfMassInWorld());
    Vec4_a4f510 massCenterRelative1; massCenterRelative1.setSub4(position, opaB->getCenterOfMassInWorld());

    Vec4_a4f510 cross0; cross0.setCross(massCenterRelative0, direction);
    if (opaA->m_context)
        jac.m_angular[0] = cross0;
    else
        jac.m_angular[0]._setRotatedDir(opaA->getCoreFromWorldMatrix(), cross0);

    Vec4_a4f510 cross1; cross1.setCross(direction, massCenterRelative1);
    if (opaB->m_context)
        jac.m_angular[1] = cross1;
    else
        jac.m_angular[1]._setRotatedDir(opaB->getCoreFromWorldMatrix(), cross1);

    float a = jac.getDiag(*opaA, *opaB);
    jac.setUserValue(a);
    jac.setInvJacDiag(invJacFactor / a);
}

static __forceinline void buildLinearEnd_a4f510(Jacobian_a4f510& jac, float rhs, float rhsFactor)
{
    jac.setRHS(rhs * rhsFactor);
}

static __forceinline void buildJacobianInline_a4f510(
    const BilateralInfo_a4f510& info,
    const QueryIn_a4f510& in,
    Jacobian_a4f510& jac,
    float customRhs)
{
    const VelAcc_a4f510* accuA = in.m_bodyA;
    const VelAcc_a4f510* accuB = in.m_bodyB;
    buildLinearBegin_a4f510(accuA, accuB, info.m_pivotA, info.m_constrainedDofW, in.m_virtMassFactor, jac);
    buildLinearEnd_a4f510(jac, customRhs, in.m_rhsFactor);
}

// pdb: hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun + bridge(call_gap|call_seq) + skyrim(call_gap), high
void __cdecl hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(
    const BilateralInfo_a4f510& info,
    const QueryIn_a4f510& in,
    Jacobian_a4f510& jac,
    float customRhs)
{
    buildJacobianInline_a4f510(info, in, jac, customRhs);
}
}   // namespace f3m_00a4f510

// @f3 0x00a55c80 (community match, verified in this file)
#include <math.h>
namespace f3m_00a55c80 {

struct __declspec(align(16)) QVec4a55 {
    float x;
    float y;
    float z;
    float w;
};

void __cdecl FUN_00a55b40(const QVec4a55* a, const QVec4a55* b, const QVec4a55* c, QVec4a55* out);
float __cdecl FUN_00954db0(float a, float b);

static __forceinline float QDot(const QVec4a55& a, const QVec4a55& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static __forceinline void QCross(QVec4a55& r, const QVec4a55& a, const QVec4a55& b)
{
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
}

static __forceinline float QAtan2(float a, float b)
{
    return FUN_00954db0(a, b);
}

// pdb: hkpMeshWeldingUtility::calcAngleFromVertices | hkpMeshWeldingUtility.obj | tesv_win, call_seq, medium
float __cdecl FUN_00a55c80(QVec4a55* p, float* outA, float* outB)
{
    QVec4a55 n;
    QVec4a55 m;
    QVec4a55* q = &p[1];
    FUN_00a55b40(p, q, &p[2], &n);
    FUN_00a55b40(q, p, &p[3], &m);
    QVec4a55 d;
    d.x = q->x - p->x;
    d.y = q->y - p->y;
    d.z = q->z - p->z;
    float lenSq = d.x * d.x + d.y * d.y + d.z * d.z;
    float inv;
    if (lenSq != 0.0f)
        inv = 1.0f / (float)sqrt(lenSq);
    else
        inv = 0.0f;
    d.x *= inv;
    d.y *= inv;
    d.z *= inv;
    QVec4a55 c;
    QCross(c, d, n);
    *outA = m.x * c.x + c.y * m.y + c.z * m.z;
    *outB = QDot(m, n);
    return QAtan2(*outA, *outB);
}
}   // namespace f3m_00a55c80

// @f3 0x00a56240 (community match, verified in this file)
namespace f3m_00a56240 {
class BoolResult
{
public:
    BoolResult() {}
    BoolResult(bool b) : m_bool(static_cast<char>(b)) {}
    operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

class Vector4
{
public:
    __forceinline void set(float a, float b, float c, float d = 0.0f);
    __forceinline void setSub4(const Vector4& a, const Vector4& b);
    __forceinline void setCross(const Vector4& a, const Vector4& b);
    __forceinline float dot3(const Vector4& a) const;
    __forceinline float& operator()(int i);
    __forceinline const float& operator()(int i) const;

private:
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

inline float& Vector4::operator()(int i)
{
    return (&x)[i];
}

inline const float& Vector4::operator()(int i) const
{
    return (&x)[i];
}

inline void Vector4::set(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

inline void Vector4::setSub4(const Vector4& v0, const Vector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

inline void Vector4::setCross(const Vector4& v1, const Vector4& v2)
{
    const float nx = v1(1) * v2(2) - v1(2) * v2(1);
    const float ny = v1(2) * v2(0) - v1(0) * v2(2);
    const float nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

inline float Vector4::dot3(const Vector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

BoolResult __cdecl FUN_00a56240(
    float& t,
    float& u,
    float& v,
    const Vector4& pos,
    const Vector4& dir,
    const Vector4& a,
    const Vector4& b,
    const Vector4& c,
    BoolResult perform_culling)
{
    Vector4 edge1;
    Vector4 edge2;
    edge1.setSub4(b, a);
    edge2.setSub4(c, a);

    Vector4 pvec;
    pvec.setCross(dir, edge2);

    float det = edge1.dot3(pvec);

    if (perform_culling)
    {
        if (det < 1e-4f)
        {
            return false;
        }
    }
    else
    {
        if (det > -1e-4f && det < 1e-4f)
        {
            return false;
        }
    }

    float inv_det = 1.0f / det;

    Vector4 tvec;
    tvec.setSub4(pos, a);

    u = tvec.dot3(pvec);
    if (u < 0.0f || u > det)
    {
        return false;
    }

    Vector4 qvec;
    qvec.setCross(tvec, edge1);

    v = dir.dot3(qvec);
    if (v < 0.0f || u + v > det)
    {
        return false;
    }

    t = edge2.dot3(qvec);
    t *= inv_det;
    u *= inv_det;
    v *= inv_det;

    return true;
}
}   // namespace f3m_00a56240

// @f3 0x00a56c10 (community match, verified in this file)
namespace f3m_00a56c10 {
// FUN_00a56c10 (0x00a56c10, 249 bytes), Havok-style shape AABB helper.
//
// __thiscall: this in ecx, 3 stack arguments (callee pops 0xc).
//   this       : object with a shape pointer at +0x18 and an hkVector4 at +0x20
//   arg1 (+8)  : const rotation, three 16-byte columns (only .x/.y/.z are read)
//   arg2 (+0xc): float margin
//   arg3 (+0x10): AABB, min at +0x00 and max at +0x10 (x/y/z touched, w too)
//
// 1. forward to shape->vtable[7] (rotation, margin, out)
// 2. translation = rotation * this.offset   (w = 0)
// 3. add the translation to both AABB corners, w + 0.0f included.

namespace f3m_00a56c10 {

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct Rotation
{
    Vec4 col0;   // +0x00
    Vec4 col1;   // +0x10
    Vec4 col2;   // +0x20
};

struct Aabb
{
    Vec4 m_min;  // +0x00
    Vec4 m_max;  // +0x10
};

struct Shape
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c(const Rotation& rotation, float margin, Aabb& out);
};

struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Shape* m_shape;    // +0x18
    Vec4 m_offset;     // +0x20

    void FUN_00a56c10(const Rotation& rotation, float margin, Aabb& out);
};

void Obj::FUN_00a56c10(const Rotation& rotation, float margin, Aabb& out)
{
    m_shape->slot1c(rotation, margin, out);

    const float bx = m_offset.x;
    const float by = m_offset.y;
    const float bz = m_offset.z;

    Vec4 translation;
    translation.x = rotation.col0.x * bx + rotation.col1.x * by + rotation.col2.x * bz;
    translation.y = rotation.col0.y * bx + rotation.col1.y * by + rotation.col2.y * bz;
    translation.z = rotation.col0.z * bx + rotation.col1.z * by + rotation.col2.z * bz;
    translation.w = 0.0f;

    out.m_min.x += translation.x;
    out.m_min.y += translation.y;
    out.m_min.z += translation.z;
    out.m_min.w += translation.w;
    out.m_max.x += translation.x;
    out.m_max.y += translation.y;
    out.m_max.z += translation.z;
    out.m_max.w += translation.w;
}

}
}   // namespace f3m_00a56c10

// @f3 0x00a56e20 (community match, verified in this file)
namespace f3m_00a56e20 {
namespace f3m_00a56e20 {
struct hkBool
{
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    hkVector4() {}
    hkVector4(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    hkVector4& operator=(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
typedef hkBool (__cdecl *CompareFn)(const hkVector4&, const hkVector4&);
// pdb: hkAlgorithm::quickSortRecursive<class hkVector4,class hkBool (__cdecl*)(class hkVector4 &,class hkVector4 &)> | hkGeomConvexHullBuilder.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_00a56e20(hkVector4* arr, int lo, int hi, CompareFn cmp)
{
    hkVector4 pivot;
    int i;
    int j;
    for (;;)
    {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do
        {
            while (cmp(arr[i], pivot))
                ++i;
            while (cmp(pivot, arr[j]))
                --j;
            if (j >= i)
            {
                if (j != i)
                {
                    hkVector4* pj = arr + j;
                    hkVector4* pi = arr + i;
                    hkVector4 t = *pj;
                    *pj = *pi;
                    *pi = t;
                }
                --j;
                ++i;
            }
        } while (i <= j);
        if (lo < j)
            FUN_00a56e20(arr, lo, j, cmp);
        if (i >= hi)
            return;
        lo = i;
    }
}
}
}   // namespace f3m_00a56e20

// @f3 0x00a57050 (community match, verified in this file)
namespace f3m_00a57050 {

// Havok's plane-equation utility, built without SIMD: three plane equations (normal, distance) are intersected by
// Cramer's rule. The vector and matrix members below are the x87 forms of the library's inline math functions.
namespace n00a57050 {
typedef float hkReal;
struct __declspec(align(16)) hkVector4 {
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
    hkReal& operator()(int i) { return (&x)[i]; }
    const hkReal& operator()(int i) const { return (&x)[i]; }
    void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f) { x = a; y = b; z = c; w = d; }
    void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz);
    }
    hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    void mul4(hkReal rs)
    {
        hkReal s = hkReal(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
};
// Three column vectors.
struct hkMatrix3 {
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    __forceinline void multiplyVector(const hkVector4& v, hkVector4& resultOut) const
    {
        hkReal v0 = v(0);
        hkReal v1 = v(1);
        hkReal v2 = v(2);
        const hkMatrix3& t = *this;
        resultOut(0) = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2;
        resultOut(1) = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2;
        resultOut(2) = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2;
        resultOut(3) = 0;
    }
};
struct hkArray {
    hkVector4* m_data;
    int m_size;
    int m_capacityAndFlags;
    const hkVector4& operator[](int i) const { return m_data[i]; }
};
// The intersection point and the three plane indices it came from.
struct Vertex {
    hkVector4 location;
    int a;
    int b;
    int c;
};
template <typename T> inline void swap(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}
}

int __cdecl FUN_00a57050(const n00a57050::hkArray& planes, int i, int j, int k, n00a57050::Vertex& out)
{
    using namespace n00a57050;
    // The columns are bound to references first and the planes are indexed in place: this is what gives each
    // product of the cross products the operand that the original loads first.
    hkMatrix3 m;
    hkVector4& c0 = m.getColumn(0);
    hkVector4& c1 = m.getColumn(1);
    hkVector4& c2 = m.getColumn(2);
    c0.setCross(planes[j], planes[k]);
    c1.setCross(planes[k], planes[i]);
    c2.setCross(planes[i], planes[j]);
    hkReal determinant = planes[i].dot3(c0);
    if (fabsf(determinant) < 1.1920929e-07f)
        return 1;
    hkVector4 d; d.set(-planes[i](3), -planes[j](3), -planes[k](3));
    m.multiplyVector(d, out.location);
    out.location.mul4(1.0f / determinant);
    out.a = i;
    out.b = j;
    out.c = k;
    if (i > j)
        swap(out.a, out.b);
    return 0;
}
}   // namespace f3m_00a57050

// @f3 0x00a57690 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a57690 {
struct __declspec(align(16)) Vec4_00a57690
{
    float x, y, z, w;
    Vec4_00a57690& operator=(const Vec4_00a57690& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};

struct Tri_00a57690
{
    Vec4_00a57690 plane;
    int v0, v1, v2;
};

struct Edge_00a57690
{
    int a, b;
    Tri_00a57690* tri;
    Vec4_00a57690 plane;
};

struct MemMgr_00a57690;
extern MemMgr_00a57690* (__stdcall* DAT_00d9b080)(unsigned long);

struct MemMgr_00a57690
{
    void FUN_008f6d90(void*, int, int);
};

void __cdecl FUN_00901f10(void*, int);
char* __cdecl FUN_00a57480(char*, Vec4_00a57690*, void*, int, int, Tri_00a57690*, void*);
void __cdecl FUN_00a56fa0(void*, int, int, int, Vec4_00a57690*);

template <class T> struct Arr_00a57690
{
    T* data;
    int size;
    int capacity;

    __forceinline int findEdge(const Edge_00a57690& e) const
    {
        int i = 0;
        for (; i < size; i++)
        {
            const T& o = data[i];
            if ((o.a == e.a && o.b == e.b) || (o.b == e.a && o.a == e.b))
                return i;
        }
        return -1;
    }

    __forceinline void AddBack(const T& v)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size++] = v;
    }

    __forceinline void pushBackPlain(const T& v)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size++] = v;
    }

    __forceinline int getCapacity() const { return capacity & 0x3fffffff; }
    static __forceinline void release(T*& p, int count)
    {
        MemMgr_00a57690* m = DAT_00d9b080(DAT_010f3170);
        m->FUN_008f6d90(p, count * sizeof(T), 0x17);
    }
    __forceinline void clearAndFree()
    {
        if ((capacity & 0x80000000) == 0)
            release(data, getCapacity());
    }
};

typedef Arr_00a57690<Edge_00a57690> EdgeArr_00a57690;
typedef Arr_00a57690<Tri_00a57690> TriArr_00a57690;
typedef Arr_00a57690<Vec4_00a57690> PlaneArr_00a57690;

void __cdecl FUN_00a57690(Edge_00a57690* edge, PlaneArr_00a57690* vertices, EdgeArr_00a57690* visited,
                          PlaneArr_00a57690* planes)
{
    if (visited->findEdge(*edge) != -1)
        return;
    visited->AddBack(*edge);

    TriArr_00a57690 neighbours;
    neighbours.data = 0;
    neighbours.size = 0;
    neighbours.capacity = 0x80000000;
    char flag;
    if (*FUN_00a57480(&flag, &edge->plane, vertices, edge->a, edge->b, edge->tri, &neighbours))
    {
        planes->pushBackPlain(neighbours.data[0].plane);

        for (int i = 0; i < neighbours.size; i++)
        {
            Edge_00a57690 e1;
            e1.a = neighbours.data[i].v0;
            e1.b = neighbours.data[i].v2;
            e1.tri = &neighbours.data[i];
            FUN_00a56fa0(vertices, e1.tri->v0, e1.tri->v2, e1.tri->v1, &e1.plane);
            FUN_00a57690(&e1, vertices, visited, planes);

            Edge_00a57690 e2;
            e2.a = neighbours.data[i].v1;
            e2.b = neighbours.data[i].v2;
            e2.tri = &neighbours.data[i];
            FUN_00a56fa0(vertices, e2.tri->v1, e2.tri->v2, e2.tri->v0, &e2.plane);
            FUN_00a57690(&e2, vertices, visited, planes);
        }
    }
    neighbours.clearAndFree();
}
}   // namespace f3m_00a57690

// @f3 0x00a58f00 (community match, verified in this file)
namespace f3m_00a58f00 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_00a58f00 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline float get(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d = 0.0f) {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void clear() { x = y = z = w = 0.0f; }
    __forceinline void copy(const Vec4& a) {
        x = a.x; y = a.y; z = a.z; w = a.w;
    }
    __forceinline Vec4& operator+=(const Vec4& o) {
        x += o.x; y += o.y; z += o.z; w += o.w;
        return *this;
    }
};
extern const Vec4 DAT_01092a50;
struct Mat3 {
    Vec4 col[3];
    __forceinline void clear() {
        Vec4 zero; zero.clear();
        col[0].copy(zero); col[1].copy(zero); col[2].copy(zero);
    }
    __forceinline void setDiagonal(float a, float b, float c) {
        clear(); col[0].x = a; col[1].y = b; col[2].z = c;
    }
    __forceinline void setRows(const Vec4& a, const Vec4& b, const Vec4& c) {
        col[0].set(a.x, b.x, c.x);
        col[1].set(a.y, b.y, c.y);
        col[2].set(a.z, b.z, c.z);
    }
    __forceinline void getRow(int i, Vec4& v) const {
        v.set((&col[0].x)[i], (&col[1].x)[i], (&col[2].x)[i]);
    }
    void FUN_0096d070(const Mat3&);
};
struct Vec4Array { Vec4* data; int size, capAndFlags; };
}

// pdb: hkGeomConvexHullBuilder::convertFromUnitCube | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a58f00(f3m_00a58f00::Vec4Array* pts, f3m_00a58f00::Vec4* extent, f3m_00a58f00::Vec4* offset)
{
    using namespace f3m_00a58f00;
    Mat3 scale;
    scale.setDiagonal(extent->get(0), extent->get(1), extent->get(2));
    for (int i = 0; i < pts->size; ++i) {
        Mat3 t;
        t.setRows(pts->data[i], DAT_01092a50, DAT_01092a50);
        t.FUN_0096d070(scale);
        t.getRow(0, pts->data[i]);
        pts->data[i] += *offset;
    }
}
}   // namespace f3m_00a58f00

// @f3 0x00a59540 (community match, verified in this file)
extern const double DAT_00e01a58;
namespace f3m_00a59540 {
struct __declspec(align(16)) Vec4_a59540 {
 float x,y,z,w;
 void setSub(const Vec4_a59540& a,const Vec4_a59540& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;}
 float dot3(const Vec4_a59540& a) const {return x*a.x+y*a.y+z*a.z;}
};
struct Edge_a59540 {unsigned short index; unsigned short other; unsigned int flags;};
struct Input_a59540 {Vec4_a59540* vertices; Edge_a59540* edges; int count;};
struct Output_a59540 {Edge_a59540* left; Edge_a59540* right; int state; int edge; float distance;};
extern void __cdecl FUN_00a58180(Vec4_a59540*,Vec4_a59540*,const Vec4_a59540*);
// pdb: hkGeomConvexHullBuilder::getCommonTangent | hkGeomConvexHullBuilder.obj | tesv_win, call_gap, low
void __cdecl FUN_00a59540(Input_a59540* a,Input_a59540* b,Output_a59540* output,Vec4_a59540* direction)
{
 Vec4_a59540* base=a->vertices;
 output->left=a->edges;
 output->right=b->edges;
 output->state=0;
 output->edge=-1;
 output->distance=0.0f;
 Vec4_a59540* vertexA=&base[output->left->index];
 Vec4_a59540* vertexB=&base[output->right->index];
 FUN_00a58180(vertexA,vertexB,direction);
 // Fake match: five scratch re-reads of the loop-bound count in the pass-loop
 // preheader steer the front-end symbol numbering so the inlined second-loop dot
 // product keeps its x term first (the first loop keeps its y term first).  They
 // are dead: no instruction is emitted for them (481/481 bytes match).
 int scratch0=a->count; int scratch1=a->count; int scratch2=a->count;
 int scratch3=a->count; int scratch4=a->count;
 (void)scratch0;(void)scratch1;(void)scratch2;(void)scratch3;(void)scratch4;
 int na=a->count;int nb=b->count;int total=2*(na+nb);
 for(int pass=0;pass<total;++pass) {
  bool changed=false;
  for(int i=a->count-1;i>=0;--i) {
   Edge_a59540* e=&a->edges[i];
   Vec4_a59540* candidate=&base[e->index];
   Vec4_a59540 d;
   d.setSub(*candidate,*vertexA);
   float dot=direction->dot3(d);
   if(dot>DAT_00e01a58) {
    output->left=e;
    vertexA=candidate;
    FUN_00a58180(vertexA,vertexB,direction);
    changed=true;
   }
  }
  for(int i=b->count-1;i>=0;--i) {
   Edge_a59540* e=&b->edges[i];
   Vec4_a59540* candidate=&base[e->index];
   Vec4_a59540 d;
   d.setSub(*candidate,*vertexB);
   float dot=d.dot3(*direction);
   if(dot>DAT_00e01a58) {
    output->right=e;
    vertexB=candidate;
    FUN_00a58180(vertexA,vertexB,direction);
    changed=true;
   }
  }
  if(!changed) break;
  FUN_00a58180(vertexA,vertexB,direction);
 }
}
}   // namespace f3m_00a59540

// @f3 0x00a59c90 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern const char str_00e86c18[];
namespace f3m_00a59c90 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
namespace c_00a59c90 {
struct Heap {
    char* FUN_008f6f60(int size, int memClass);
    void FUN_008f6f90(void* p);
};
struct Entry { int unk00; unsigned short unk04; unsigned short pad; };
struct Array { int unk00; Entry* data; int size; };
void __cdecl FUN_009232a0(char* buf, const char* fmt, ...);
// pdb: hkGeomConvexHullBuilder::draw | hkGeomConvexHullBuilder.obj | tesv_win, caller_sim, low
void __cdecl FUN_00a59c90(const Array* arr)
{
    __declspec(align(16)) char* buf;
    Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
    buf = heap->FUN_008f6f60(0x80, 0x16);
    for (int i = 0; i < arr->size; i++)
        FUN_009232a0(buf, str_00e86c18, i, arr->data[i].unk04);
    heap = (Heap*)DAT_00d9b080(DAT_010f3170);
    heap->FUN_008f6f90(buf);
}
}
}   // namespace f3m_00a59c90

// @f3 0x00a5d940 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a5d940 {
struct __declspec(align(16)) QueryVector
{
 float x, y, z, w;
};
struct TemporaryContact
{
 QueryVector normal, position;
};
struct ContactArray
{
 TemporaryContact* data;
 int size;
 int capacity;
 ContactArray()
 {
  data = 0;
  size = 0;
  capacity = 0x80000000;
 }
};
struct QueryAllocator
{
 void FUN_008f6d90(void* data,int bytes,int memoryClass);
};
extern QueryAllocator* (__stdcall* const DAT_00d9b080)(unsigned long);
void __cdecl FUN_00a5c3d0(unsigned char* result,const void* inputA,const void* inputB,
 const void* inputC,QueryVector* scratch,void* output,const void* context,ContactArray* contacts);
// pdb: hkGeomConvexHullBuilder::buildPlaneEquations | hkGeomConvexHullBuilder.obj | tesv_win, caller_sim, low
void* __cdecl FUN_00a5d940(void* output,const void* inputA,const void* inputB,
 const void* inputC,const void* context)
{
 ContactArray contacts;
 QueryVector scratch;
 unsigned char result;
 FUN_00a5c3d0(&result,inputA,inputB,inputC,&scratch,output,context,&contacts);
 if ((contacts.capacity & 0x80000000) == 0)
 {
  int capacity = contacts.capacity & 0x3fffffff;
  QueryAllocator* allocator = DAT_00d9b080(DAT_010f3170);
  allocator->FUN_008f6d90(contacts.data,capacity*sizeof(TemporaryContact),0x17);
 }
 return output;
}
}   // namespace f3m_00a5d940

// @f3 0x00a59780 (community match, verified in this file)
namespace f3m_00a59780 {
typedef float hkReal;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal lengthSquared3() const { return dot3(*this); }
};

void __cdecl FUN_00901e90(void* array, int capacity, int elemSize);

struct hkVector4Array
{
    hkVector4* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline void setSize(int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int grown = capacity * 2;
            int newCapacity = (n < grown) ? grown : n;
            FUN_00901e90(this, newCapacity, sizeof(hkVector4));
        }
        m_size = n;
    }
};

// Remove vertices that lie within the tolerance of an earlier one. The array is sorted along x, so only
// the vertices already kept whose x is within 0.01 of the current one need to be compared.
// pdb: hkGeomConvexHullBuilder::weldXsortedVertices | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a59780(hkReal tolerance, hkVector4Array* vertices, int* numVerticesOut)
{
    hkVector4* cur = vertices->m_data;
    int remaining = vertices->m_size - 1;
    hkVector4* out = vertices->m_data;
    if (remaining >= 0)
    {
        hkVector4* last = out - 1;
        while (remaining >= 0)
        {
            hkVector4* lim = last;
            bool duplicate = false;
            for (; lim >= vertices->m_data; lim--)
            {
                if (lim->x < cur->x - (double)0.01f)
                    break;
                hkVector4 diff;
                diff.setSub4(*lim, *cur);
                hkReal distSq = diff.lengthSquared3();
                if (distSq < tolerance)
                {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate)
            {
                hkVector4* dst = out;
                out++;
                last++;
                *dst = *cur;
            }
            else
            {
                // Skip the following vertices that duplicate the same kept vertex.
                for (int t = remaining - 1; t >= 0; t--)
                {
                    hkVector4 diff;
                    diff.setSub4(*lim, cur[1]);
                    hkReal distSq = diff.lengthSquared3();
                    if (!(distSq < tolerance))
                        break;
                    cur++;
                    remaining--;
                }
            }
            cur++;
            remaining--;
        }
    }
    *numVerticesOut = (int)(out - vertices->m_data);
    int count = *numVerticesOut;
    vertices->setSize(count);
}
}   // namespace f3m_00a59780

// @f3 0x00a4f7f0 (community match, verified in this file)
namespace f3m_00a4f7f0 {
namespace f3m_00a4f7f0 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

const hkReal HK_REAL_EPSILON = 1.192092896e-07f;

extern hkReal hkTransformIdentity[];

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

class hkMatrix3;
class hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) { x = a; y = b; z = c; w = d; }
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void setSubZW(const hkVector4& v0, const hkVector4& v1) { z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void setSubYZW(const hkVector4& v0, const hkVector4& v1) { y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void mul4(const hkVector4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal horizontalAdd4() const { return x + y + z + w; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v) { _setMul3(r, v); }

class hkTransform
{
public:
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline static const hkTransform& getIdentity() { return reinterpret_cast<const hkTransform&>(hkTransformIdentity); }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkpVelocityAccumulator
{
public:
    hkUint8 m_type;
    bool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
    __forceinline const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
    hkVector4 m_scratch0;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;
};

class hkpConstraintQueryIn
{
public:
    hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime;
    hkPadSpu<hkReal> m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime;
    hkPadSpu<hkReal> m_frameInvDeltaTime;
    hkPadSpu<hkReal> m_invNumSteps;
    hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor;
    hkPadSpu<hkReal> m_virtMassFactor;
    hkPadSpu<hkReal> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
};

class hkp1Lin2AngJacobian
{
public:
    hkVector4 m_linear0;
    hkVector4 m_angular[2];

    __forceinline hkReal getDiag(const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB) const
    {
        hkVector4 ang0; ang0.setMul4(m_angular[0], m_angular[0]);
        hkVector4 ang1; ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);
        ang0(3) = mB.m_invMasses(3) + mA.m_invMasses(3);
        hkReal x = ang0.horizontalAdd4();
        return x;
    }
};


struct BilateralInfo
{
    hkVector4 m_pivotA;
    hkVector4 m_pivotB;
    hkVector4 m_constrainedDofW;
    hkReal m_f30;
    hkReal m_f34;
};

struct BilateralSchema
{
    hkp1Lin2AngJacobian m_jac;
    hkReal m_f30;
    hkReal m_f34;
    hkReal unk38;
    hkReal unk3c;
    __forceinline void setF(hkReal a, hkReal b) { m_f30 = a; m_f34 = b; }
};

struct QueryOut
{
    BilateralSchema* m_jac;
};

__forceinline void setRotatedDirF(hkVector4& o, const hkRotation& r, const hkVector4& v) { o._setRotatedDir(r, v); }
static __forceinline hkReal buildJacobian(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& dir,
    const hkpConstraintQueryIn& in, const hkpVelocityAccumulator* mA, const hkpVelocityAccumulator* mB, hkp1Lin2AngJacobian& jac, hkReal rhsFactor)
{
    jac.m_linear0 = dir;
    hkVector4 rA; rA.setSub4(pivotA, mA->getCenterOfMassInWorld());
    hkVector4 rB; rB.setSub4(pivotB, mB->getCenterOfMassInWorld());
    hkVector4 c0; c0.setCross(rA, dir);
    if (mA->m_matrixIsIdentity) { jac.m_angular[0] = c0; }
    else { jac.m_angular[0]._setRotatedDir(mA->getCoreFromWorldMatrix(), c0); }
    hkVector4 c1; c1.setCross(dir, rB);
    if (mB->m_matrixIsIdentity) { jac.m_angular[1] = c1; }
    else { setRotatedDirF(jac.m_angular[1], mB->getCoreFromWorldMatrix(), c1); }
    hkReal diag = jac.getDiag(*mA, *mB) + HK_REAL_EPSILON;
    jac.m_angular[1](3) = diag;
    jac.m_angular[0](3) = 1.0f / diag;
    hkVector4 diff; diff.setSub4(pivotB, pivotA);
    return diff.dot3(dir) * rhsFactor;
}

// pdb: hk1dLinearBilateralConstraintUserTauBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: info, in, out
void __cdecl FUN_00a4f7f0(const BilateralInfo& info, const hkpConstraintQueryIn& in, QueryOut& out)
{
    const hkpVelocityAccumulator* mA = in.m_bodyA;
    hkReal rhsFactor = in.m_rhsFactor;
    const hkpVelocityAccumulator* mB = in.m_bodyB;
    BilateralSchema* sch = out.m_jac;
    hkReal rhs = buildJacobian(info.m_pivotA, info.m_pivotB, info.m_constrainedDofW, in, mA, mB, sch->m_jac, rhsFactor);
    BilateralSchema* j = sch;
    sch++;
    j->m_jac.m_linear0(3) = rhs;
    j->setF(info.m_f30, info.m_f34);
    j->m_jac.m_linear0.x = j->m_jac.m_linear0.x + 1.1920928955078125e-07;
    *(char*)&j->m_jac.m_linear0 = 6;
    out.m_jac = sch;
}

}
}   // namespace f3m_00a4f7f0

// @f3 0x00a59e30 (community match, verified in this file)
#include <math.h>
namespace f3m_00a59e30 {

typedef float hkReal;

// The maths library's vector, FPU build: named lanes, operator() for indexed access.
struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    hkReal& operator()(int i) { return ((hkReal*)this)[i]; }
    const hkReal& operator()(int i) const { return ((const hkReal*)this)[i]; }

    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    // The cross product, once per call site: the three sites differ in how the result is stored and in one lane read.
    __forceinline void setCrossA(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        x = nx; y = ny; z = nz; w = 0.0f;
    }
    __forceinline void setB(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setCrossB(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        setB(nx, ny, nz, 0.0f);
    }
    __forceinline void setCrossC(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1.z * v2(1);
        const hkReal ny = v1.z * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        x = nx; y = ny; z = nz; w = 0.0f;
    }
    __forceinline hkReal lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        hkReal inv;
        if (l2 != 0.0f) {
            hkReal len = sqrtf(l2);
            inv = 1.0f / len;
        } else {
            inv = 0.0f;
        }
        return inv;
    }
    __forceinline void mul4(hkReal s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void add4(const hkVector4& a) { x += a.x; (*this)(1) += a.y; z += a.z; w += a.w; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
};


struct Entry
{
    unsigned short* index;
    float value;
};

struct EntryArray
{
    Entry* data;
    int count;
};

struct Body
{
    float unk00;
    float unk04;
    float unk08;
    float radius;
};

float FUN_00a58460(Body* body, hkVector4* point, hkVector4* axis, hkVector4* from, hkVector4* to);
int FUN_00a58ad0(const void* a, const void* b);
void FUN_00a600a0(Entry* data, int first, int last, int (*compare)(const void*, const void*));

// Builds a segment through one point of the set, perpendicular to the edge p0-p1 and to an axis chosen from the
// angle, scores every entry against it and sorts the entries by that score.
// pdb: hkGeomConvexHullBuilder::calculateNewNeighbours | hkGeomConvexHullBuilder.obj | tesv_win, call_gap, low
void FUN_00a59e30(hkVector4* points, Body* body, float angle, hkVector4* dir, unsigned short* index,
                  hkVector4* p0, hkVector4* p1, EntryArray* entries)
{
    float t = body->radius;
    hkVector4* origin = &points[*index];
    hkVector4 axis(*dir);
    hkVector4 d;
    d.setSub4(*p0, *p1);

    if (!(angle < t) && !(angle > 8.0 - t)) {
        if (fabs(angle - 4.0f) < t) {
            axis.setCrossA(d, axis);
            axis.normalize3();
        }
    } else {
        axis.setCrossB(axis, d);
        axis.mul4(axis.lengthInverse3());
    }

    d.setCrossC(axis, d);
    d.add4(*origin);

    hkVector4 from;
    hkVector4 to;
    if (origin == p0) {
        from = d;
    } else {
        from = *origin;
    }
    if (origin == p0) {
        to = *origin;
    } else {
        to = d;
    }

    for (int i = 0; i < entries->count; i++) {
        Entry* e = &entries->data[i];
        e->value = FUN_00a58460(body, &points[*e->index], &axis, &from, &to);
    }
    if (entries->count > 1) {
        FUN_00a600a0(entries->data, 0, entries->count - 1, FUN_00a58ad0);
    }
}
}   // namespace f3m_00a59e30

// @f3 0x00a54d90 (community match, verified in this file)
namespace f3m_00a54d90 {
namespace f3m_00a54d90 {

struct __declspec(align(16)) S00a54d90_Vector4
{
    float x, y, z, w;
};

struct __declspec(align(16)) S00a54d90_ShapeBuffer
{
    S00a54d90_Vector4 m_storage[32];
};

struct S00a54d90_ConvexShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float getSupport(const S00a54d90_Vector4& direction) const;
};

struct S00a54d90_Container
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const S00a54d90_ConvexShape* getChildShape(unsigned int key, S00a54d90_ShapeBuffer& buffer) const;
};

struct S00a54d90_ChildInfo
{
    unsigned int m_key;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
};

struct S00a54d90_Projector
{
    int m_unk00;
    int m_unk04;
    const S00a54d90_Container* m_container;
    void hkpMoppShapeMediator_findExtents(const S00a54d90_Vector4& direction, int unused, const S00a54d90_ChildInfo* children, int numChildren,
                      float* minOut, float* maxOut) const;
};

// pdb: hkpMoppShapeMediator::findExtents | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S00a54d90_Projector::hkpMoppShapeMediator_findExtents(const S00a54d90_Vector4& direction, int unused, const S00a54d90_ChildInfo* children, int numChildren,
                                       float* minOut, float* maxOut) const
{
    S00a54d90_ShapeBuffer buffer;
    float lo, hi;

    unsigned int key = children[0].m_key;
    const S00a54d90_ConvexShape* shape = m_container->getChildShape(key, buffer);
    if (shape)
    {
        hi = shape->getSupport(direction);
        S00a54d90_Vector4 negDir;
        negDir.x = -direction.x;
        negDir.y = -direction.y;
        negDir.z = -direction.z;
        negDir.w = -direction.w;
        lo = -shape->getSupport(negDir);
    }
    else
    {
        lo = 0.0f;
        hi = 0.0f;
    }

    float minVal = lo;
    float maxVal = hi;

    for (int i = 1; i < numChildren; i++)
    {
        key = children[i].m_key;
        shape = m_container->getChildShape(key, buffer);
        if (shape)
        {
            hi = shape->getSupport(direction);
            S00a54d90_Vector4 negDir;
            negDir.x = -direction.x;
            negDir.y = -direction.y;
            negDir.z = -direction.z;
            negDir.w = -direction.w;
            lo = -shape->getSupport(negDir);
        }
        else
        {
            lo = 0.0f;
            hi = 0.0f;
        }
        if (lo < minVal) minVal = lo;
        if (hi > maxVal) maxVal = hi;
    }

    *minOut = minVal;
    *maxOut = maxVal;
}

}
}   // namespace f3m_00a54d90

// @f3 0x00a45660 (community match, verified in this file)
namespace f3m_00a45660 {

namespace f3m_00a45660 {

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct Transform
{
    Vec4 m_rotation[3];
    Vec4 m_translation;
};

struct Aabb
{
    Vec4 m_min;
    Vec4 m_max;
};

struct OutVec4 : Vec4
{
    void hkVector4_setTransformedPos(const Transform& t, const Vec4& v);
};

static __forceinline float Min2(const float& a, const float& b) { return a < b ? a : b; }
static __forceinline float Max2(const float& a, const float& b) { return a > b ? a : b; }

// pdb: meshShape_addToAabb | hkpMeshShape.obj | tesv_win, objrun_prop, low
static __declspec(noinline) void FUN_00a45660(const Vec4& halfExtents, const Vec4& dir, const Transform& t, Aabb& box)
{
    Vec4 p;
    p.x = halfExtents.x * dir.x;
    p.y = halfExtents.y * dir.y;
    p.z = halfExtents.z * dir.z;
    p.w = 0.0f;
    OutVec4 v;
    v.hkVector4_setTransformedPos(t, p);
    box.m_min.x = Min2(box.m_min.x, v.x);
    box.m_min.y = Min2(box.m_min.y, v.y);
    box.m_min.z = Min2(box.m_min.z, v.z);
    box.m_min.w = Min2(box.m_min.w, v.w);
    box.m_max.x = Max2(box.m_max.x, v.x);
    box.m_max.y = Max2(box.m_max.y, v.y);
    box.m_max.z = Max2(box.m_max.z, v.z);
    box.m_max.w = Max2(box.m_max.w, v.w);
}

Vec4* volatile g_he;
Vec4* volatile g_dir;
Transform* volatile g_t;
Aabb* volatile g_box;

void caller_of_a45660()
{
    FUN_00a45660(*g_he, *g_dir, *g_t, *g_box);
}

}
}   // namespace f3m_00a45660

// @f3 0x00a4f230 (community match, verified in this file)
namespace f3m_00a4f230 {
namespace f3m_00a4f230 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

const hkReal HK_REAL_EPSILON = 1.192092896e-07f;

extern hkReal hkTransformIdentity[];

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

class hkMatrix3;
class hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) { x = a; y = b; z = c; w = d; }
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void mul4(const hkVector4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal horizontalAdd4() const { return x + y + z + w; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v) { _setMul3(r, v); }

class hkTransform
{
public:
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline static const hkTransform& getIdentity() { return reinterpret_cast<const hkTransform&>(hkTransformIdentity); }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkpVelocityAccumulator
{
public:
    hkUint8 m_type;
    bool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
    __forceinline const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
    hkVector4 m_scratch0;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;
};

class hkpConstraintQueryIn
{
public:
    hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime;
    hkPadSpu<hkReal> m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime;
    hkPadSpu<hkReal> m_frameInvDeltaTime;
    hkPadSpu<hkReal> m_invNumSteps;
    hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor;
    hkPadSpu<hkReal> m_virtMassFactor;
    hkPadSpu<hkReal> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
};

class hkp1Lin2AngJacobian
{
public:
    hkVector4 m_linear0;
    hkVector4 m_angular[2];

    __forceinline hkReal getDiag(const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB) const
    {
        hkVector4 ang0; ang0.setMul4(m_angular[0], m_angular[0]);
        hkVector4 ang1; ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);
        ang0(3) = mB.m_invMasses(3) + mA.m_invMasses(3);
        return ang0.horizontalAdd4();
    }
};


__forceinline void setRotatedDirF(hkVector4& o, const hkRotation& r, const hkVector4& v) { o._setRotatedDir(r, v); }
static __forceinline void crossF(hkVector4& o, const hkVector4& a, const hkVector4& b) { o.setCross(a, b); }
static __forceinline void hk1dLinearBilateralBuildJacobian(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& dir,
    const hkpConstraintQueryIn& in, const hkpVelocityAccumulator* mA, const hkpVelocityAccumulator* mB, hkp1Lin2AngJacobian& jac)
{
    const hkReal virtMassFactor = in.m_virtMassFactor;
    jac.m_linear0 = dir;
    hkVector4 rA; rA.setSub4(pivotA, mA->getCenterOfMassInWorld());
    hkVector4 rB; rB.setSub4(pivotB, mB->getCenterOfMassInWorld());
    hkVector4 c0; c0.setCross(rA, dir);
    if (mA->m_matrixIsIdentity) { jac.m_angular[0] = c0; }
    else { setRotatedDirF(jac.m_angular[0], mA->getCoreFromWorldMatrix(), c0); }
    hkVector4 c1; crossF(c1, dir, rB);
    if (mB->m_matrixIsIdentity) { jac.m_angular[1] = c1; }
    else { setRotatedDirF(jac.m_angular[1], mB->getCoreFromWorldMatrix(), c1); }
    hkReal diag = jac.getDiag(*mA, *mB) + HK_REAL_EPSILON;
    jac.m_angular[1](3) = diag;
    const hkReal invDiag = virtMassFactor / diag;
    jac.m_angular[0](3) = invDiag;
}

struct BilateralInfo
{
    hkVector4 m_pivotA;
    hkVector4 m_pivotB;
    hkVector4 m_constrainedDofW;
};

struct QueryOut
{
    hkp1Lin2AngJacobian* m_jac;
};

void __cdecl FUN_00a4f230(const BilateralInfo& info, const hkpConstraintQueryIn& in, QueryOut& out, hkReal customRhs)
{
    hkp1Lin2AngJacobian* jac = out.m_jac;
    const hkpVelocityAccumulator* mA = in.m_bodyA;
    const hkpVelocityAccumulator* mB = in.m_bodyB;
    hk1dLinearBilateralBuildJacobian(info.m_pivotA, info.m_pivotA, info.m_constrainedDofW, in, mA, mB, *jac);
    jac->m_linear0(3) = in.m_rhsFactor * customRhs;
    jac->m_linear0.x = jac->m_linear0.x + 1.1920928955078125e-07;
    *(unsigned char*)&jac->m_linear0.x = 5;
    out.m_jac = jac + 1;
}

}
}   // namespace f3m_00a4f230

// @f3 0x00a59030 (community match, verified in this file)
#include <math.h>
namespace f3m_00a59030 {
namespace geom59030 {
struct Result {
    char value;
    __forceinline Result(bool v) : value((char)v) {}
};
inline float Root(float v) { return sqrtf(v); }
inline float InverseRoot(float v) { return 1.0f / Root(v); }
struct __declspec(align(16)) Vector {
    float x,y,z,w;
    __forceinline void Sub(const Vector& a,const Vector& b) {
        x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w;
    }
    __forceinline float Dot(const Vector& a) const { return x*a.x+y*a.y+z*a.z; }
    __forceinline float Squared() const { return Dot(*this); }
    __forceinline float InverseLength() const {
        float v=x*x+y*y+z*z;
        return v ? InverseRoot(v) : 0;
    }
    __forceinline void Scale(float v) { x*=v; y*=v; z*=v; w*=v; }
    __forceinline void Normalize() { Scale(InverseLength()); }
};
struct Index { unsigned short index,next,prev,flags; };
struct IndexArray {
    Index* values; int count,capacity;
    __forceinline Index& operator[](int i) const { return values[i]; }
    __forceinline Index* Data() const { return values; }
    __forceinline int Size() const { return count; }
    __forceinline void Append(const Index& value);
};
void FUN_00901f10(IndexArray*,int);
__forceinline void IndexArray::Append(const Index& value) {
    if(count==(capacity&0x3fffffff)) FUN_00901f10(this,sizeof(Index));
    values[count++]=value;
}
struct Hull {
    Vector* vertices;
    IndexArray indices;
    void Initialize(int a,int b);
};
float FUN_00401e20(float,float);

// pdb: hkGeomConvexHullBuilder::isSingleLine | hkGeomConvexHullBuilder.obj | tesv_win, call_gap, low
Result __cdecl FUN_00a59030(float tolerance,Hull& a,Hull& b,Hull& edges) {
    Vector* vertices=a.vertices;
    if(a.indices.Size()>=3 || b.indices.Size()>=3) return false;
    IndexArray& firstIndices=a.indices;
    {
        int high,third,fourth=0;
        int low;
        int count=3;
        if(a.indices.Size()==2) {
            high=firstIndices.Data()[firstIndices[0].next].index;
            low=firstIndices[0].index;
            if(high<low) { int t=low; low=high; high=t; }
            third=b.indices[0].index;
            if(b.indices.Size()==2) {
                fourth=b.indices.Data()[b.indices[0].next].index;
                if(fourth<third) { int t=fourth; fourth=third; third=t; }
                count=4;
            }
        } else if(b.indices.Size()==2) {
            low=firstIndices[0].index;
            high=b.indices.Data()[b.indices[0].next].index;
            third=b.indices[0].index;
            if(high<low) { int t=low; low=high; high=t; }
        } else {
            edges.Initialize(firstIndices[0].index,b.indices[0].index);
            return true;
        }
        Vector dirB,dirA,dirC,difference;
        dirA.Sub(vertices[high],vertices[low]);
        float lenA=dirA.Squared();
        dirB.Sub(vertices[third],vertices[high]);
        float lenB=dirB.Squared();
        dirC.Sub(vertices[low],vertices[third]);
        float lenC=dirC.y*dirC.y+dirC.x*dirC.x+dirC.z*dirC.z;
        dirA.Normalize();
        dirB.Normalize();
        difference.Sub(dirB,dirA);
        if(difference.Squared()<tolerance) {
            if(count==4) {
                Vector dirD,diffD;
                dirD.Sub(vertices[fourth],vertices[high]);
                float lenD=dirD.Squared();
                dirD.Normalize();
                diffD.Sub(dirB,dirD);
                if(!(diffD.Squared()<tolerance)) return false;
                if(lenD>lenB) {
                    third=fourth;
                    dirC.Sub(vertices[low],vertices[fourth]);
                    lenC=dirC.Squared();
                }
            }
            float longest=FUN_00401e20(lenA,FUN_00401e20(lenB,lenC));
            if(lenA==longest) edges.Initialize(low,high);
            else if(lenB==longest) edges.Initialize(high,third);
            else if(lenC==longest) edges.Initialize(third,low);
            return true;
        }
        return false;
    }
}
}
}   // namespace f3m_00a59030

// @f3 0x00a4fe70 (community match, verified in this file)
namespace f3m_00a4fe70 {


namespace f3m_00a4fe70 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

const hkReal HK_REAL_EPSILON = 1.192092896e-07f;

namespace hkMath
{
    inline hkReal sqrt(hkReal r) { return ::sqrtf(r); }
}

extern hkReal hkTransformIdentity[];

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

class hkMatrix3;
class hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v) { (*this)(0) = v(0); (*this)(1) = v(1); (*this)(2) = v(2); (*this)(3) = v(3); }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) { x = a; y = b; z = c; w = d; }
    __forceinline void add4(const hkVector4& v) { (*this)(0) += v(0); (*this)(1) += v(1); (*this)(2) += v(2); (*this)(3) += v(3); }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void mul4(const hkVector4& a) { (*this)(0) *= a(0); (*this)(1) *= a(1); (*this)(2) *= a(2); (*this)(3) *= a(3); }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { (*this)(0) = a(0) * b(0); (*this)(1) = a(1) * b(1); (*this)(2) = a(2) * b(2); (*this)(3) = a(3) * b(3); }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal horizontalAdd4() const { return x + y + z + w; }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkReal t)
    {
        hkReal s = 1.0f - t;
        hkVector4& d = *this;
        d(0) = s * v0(0) + t * v1(0);
        d(1) = s * v0(1) + t * v1(1);
        d(2) = s * v0(2) + t * v1(2);
        d(3) = s * v0(3) + t * v1(3);
    }
    __forceinline hkReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkReal length3() const { return hkMath::sqrt(lengthSquared3()); }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v) { _setMul3(r, v); }

class hkTransform
{
public:
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline static const hkTransform& getIdentity() { return reinterpret_cast<const hkTransform&>(hkTransformIdentity); }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkpVelocityAccumulator
{
public:
    hkUint8 m_type;
    bool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
    __forceinline const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
    hkVector4 m_scratch0;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;
};

class hkpConstraintQueryIn
{
public:
    hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime;
    hkPadSpu<hkReal> m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime;
    hkPadSpu<hkReal> m_frameInvDeltaTime;
    hkPadSpu<hkReal> m_invNumSteps;
    hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor;
    hkPadSpu<hkReal> m_virtMassFactor;
    hkPadSpu<hkReal> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
};

class hkp1Lin2AngJacobian
{
public:
    hkVector4 m_linear0;
    hkVector4 m_angular[2];

    __forceinline hkReal getDiag(const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB) const
    {
        hkVector4 ang0; ang0.setMul4(m_angular[0], m_angular[0]);
        hkVector4 ang1; ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);
        hkVector4 lin; lin.setAdd4(mB.m_invMasses, mA.m_invMasses);
        ang0(3) = lin(3);
        hkReal x = ang0.horizontalAdd4();
        return x;
    }
};


__forceinline void setRotatedDirF(hkVector4& o, const hkRotation& r, const hkVector4& v) { o._setRotatedDir(r, v); }
static __forceinline void crossF(hkVector4& o, const hkVector4& a, const hkVector4& b) { o.setCross(a, b); }
static __forceinline hkReal dotF(const hkVector4& a, const hkVector4& b) { return a.dot3(b); }
static __forceinline hkReal diagF(const hkp1Lin2AngJacobian& j, const hkpVelocityAccumulator& a, const hkpVelocityAccumulator& b) { return j.getDiag(a, b); }
static __forceinline void hk1dLinearBilateralBuildJacobian(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& dir,
    const hkpConstraintQueryIn& in, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, hkp1Lin2AngJacobian& jac)
{
    const hkReal virtMassFactor = in.m_virtMassFactor.val();
    const hkReal rhsFactor = in.m_rhsFactor.val();
    jac.m_linear0 = dir;
    hkVector4 rA; rA.setSub4(pivotA, mA.getCenterOfMassInWorld());
    hkVector4 rB; rB.setSub4(pivotB, mB.getCenterOfMassInWorld());
    hkVector4 diff; diff.setSub4(pivotB, pivotA);
    hkVector4 c0; crossF(c0, rA, dir);
    if (mA.m_matrixIsIdentity) { jac.m_angular[0] = c0; }
    else { jac.m_angular[0]._setMul3(mA.getCoreFromWorldMatrix(), c0); }
    hkVector4 c1; crossF(c1, dir, rB);
    if (mB.m_matrixIsIdentity) { jac.m_angular[1] = c1; }
    else { setRotatedDirF(jac.m_angular[1], mB.getCoreFromWorldMatrix(), c1); }
    hkReal diag = diagF(jac, mA, mB) + HK_REAL_EPSILON;
    jac.m_angular[1](3) = diag;
    jac.m_angular[0](3) = virtMassFactor / diag;
    hkReal rhs = dotF(dir, diff);
    jac.m_linear0(3) = rhs * rhsFactor;
}

extern "C" void __cdecl FUN_009f8d90(const hkVector4& posA, const hkVector4& posB, const hkpConstraintQueryIn& in, hkp1Lin2AngJacobian* jac);

// pdb: hkStabilizedBallSocketConstraintBuildJacobian_noSchema | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: posA, posB, maxAllowedErrorDistance, in, jac
extern "C" void __cdecl FUN_00a4fe70(const hkVector4& posA, const hkVector4& posB, hkReal maxVelocity, const hkpConstraintQueryIn& in, hkp1Lin2AngJacobian* jac)
{
    const hkpVelocityAccumulator* mA = in.m_bodyA;
    const hkpVelocityAccumulator* mB = in.m_bodyB;
    const hkpVelocityAccumulator& bodyA = *mA;
    const hkpVelocityAccumulator& bodyB = *mB;
    FUN_009f8d90(posA, posB, in, jac);

    hkVector4 error; error.set(jac[0].m_linear0(3), jac[1].m_linear0(3), jac[2].m_linear0(3));
    hkReal len = error.length3();
    hkReal limit = maxVelocity * in.m_rhsFactor;
    if (len > limit)
    {
        hkReal fraction = hkMath::sqrt(hkMath::sqrt(limit / len));
        hkVector4 p1; p1.setInterpolate4(bodyA.getCenterOfMassInWorld(), posA, fraction);
        hkVector4 p2; p2.setInterpolate4(bodyB.getCenterOfMassInWorld(), posB, fraction);
        const hkVector4* dir = &hkTransform::getIdentity().getColumn(0);
        hkp1Lin2AngJacobian* j = jac;
        for (int i = 0; i < 3; i++)
        {
            hk1dLinearBilateralBuildJacobian(p1, p2, *dir, in, bodyA, bodyB, *j);
            dir++;
            j++;
        }
        jac[0].m_linear0(3) = error(0) * fraction;
        jac[1].m_linear0(3) = error(1) * fraction;
        jac[2].m_linear0(3) = error(2) * fraction;
    }
}

}
}   // namespace f3m_00a4fe70

// @f3 0x00a4e670 (community match, verified in this file)
namespace f3m_00a4e670 {
namespace S00a4e670_ns {

typedef float hkReal;
typedef hkReal hkSimdReal;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkMatrix3;
class hkRotation;

class hkVector4
{
    public:
        __forceinline hkVector4() { }
        __forceinline void operator= ( const hkVector4& v );
        __forceinline void setNeg4(const hkVector4& v);
        __forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
        __forceinline void mul4(const hkVector4& a);
        __forceinline void add4(const hkVector4& a);
        __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
        __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
        __forceinline hkSimdReal horizontalAdd3() const;
        __forceinline hkReal& operator() (int i);
        __forceinline const hkReal& operator() (int i) const;
    private:
        __declspec(align(16)) hkReal x;
        hkReal y;
        hkReal z;
        hkReal w;
};

class hkMatrix3
{
    public:
        __forceinline hkReal& operator() (int row, int col);
        __forceinline const hkReal& operator() (int row, int col) const;
        __forceinline hkVector4& getColumn(int i);
        __forceinline const hkVector4& getColumn(int i) const;
    protected:
        hkVector4 m_col0;
        hkVector4 m_col1;
        hkVector4 m_col2;
};

class hkRotation : public hkMatrix3
{
};

inline hkReal& hkVector4::operator() (int i)
{
    return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
    return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
    x = -v.x;
    y = -v.y;
    z = -v.z;
    w = -v.w;
}
inline void hkVector4::setMul4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x * v1.x;
    y = v0.y * v1.y;
    z = v0.z * v1.z;
    w = v0.w * v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
    x *= a.x;
    y *= a.y;
    z *= a.z;
    w *= a.w;
}
inline void hkVector4::add4(const hkVector4& a)
{
    x += a.x;
    y += a.y;
    z += a.z;
    w += a.w;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
    return x + y + z;
}

inline hkVector4& hkMatrix3::getColumn(int i)
{
    return (&m_col0)[i];
}
inline const hkVector4& hkMatrix3::getColumn(int i) const
{
    return (&m_col0)[i];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
    return getColumn(c)(r);
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
    return getColumn(c)(r);
}

inline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    const hkReal v0 = v(0);
    const hkReal v1 = v(1);
    const hkReal v2 = v(2);
    (*this)(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
    (*this)(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
    (*this)(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
    (*this)(3) = 0;
}
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}

struct S00a4e670_Accum
{
    unsigned char m_type;
    unsigned char m_matrixIsIdentity;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
    hkVector4 m_invMasses;   // +0x30
    hkVector4 m_unk40;
    hkRotation m_rotation;   // +0x50
};

struct S00a4e670_Weight
{
    float unk00;
    float m_value;
};

struct S00a4e670_In
{
    const hkVector4* m_axes;
    const S00a4e670_Weight* m_weights;
    float m_scale;
    int m_numAxes;
};

struct S00a4e670_Info
{
    int unk00;
    float m_tau;
    float m_damping;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S00a4e670_Accum* m_bodyA;
    S00a4e670_Accum* m_bodyB;
};

struct S00a4e670_Schema
{
    hkVector4 m_angular0;
    hkVector4 m_angular1;
    float m_scale;
    float unk24;
    float unk28;
    float unk2c;
};

__forceinline void setRotatedDirF(hkVector4& o, const hkRotation& r, const hkVector4& v) { o._setRotatedDir(r, v); }
static __forceinline void buildAxis(const hkVector4* axis, const S00a4e670_Weight* wt, const S00a4e670_In* in, const S00a4e670_Info* info, S00a4e670_Schema* s)
{
    const S00a4e670_Accum* mA = info->m_bodyA;
    const S00a4e670_Accum* mB = info->m_bodyB;
    if (mA->m_matrixIsIdentity)
    {
        s->m_angular0 = *axis;
    }
    else
    {
        s->m_angular0._setMul3(mA->m_rotation, *axis);
    }
    if (mB->m_matrixIsIdentity)
    {
        s->m_angular1.setNeg4(*axis);
    }
    else
    {
        hkVector4 neg;
        neg.setNeg4(*axis);
        setRotatedDirF(s->m_angular1, mB->m_rotation, neg);
    }
    hkVector4 tmpA;
    tmpA.setMul4(s->m_angular0, s->m_angular0);
    hkVector4 tmpBs[1];
    tmpBs[0].setMul4(s->m_angular1, s->m_angular1);
    tmpA.mul4(mA->m_invMasses);
    tmpBs[0].mul4(mB->m_invMasses);
    tmpA.add4(tmpBs[0]);
    const hkReal sum = tmpA.horizontalAdd3();
    const hkReal diag = hkReal(sum + 1.1920928955078125e-07);
    s->m_angular0(3) = 1.0f / diag;
    const hkReal weightedDamping = wt->m_value * info->m_damping;
    s->m_angular1(3) = weightedDamping;
    s->m_scale = in->m_scale * info->m_tau;
    s->m_angular0(0) = hkReal(s->m_angular0(0) + 1.1920928955078125e-07);
    *(unsigned char*)s = 0xd;
}
}

using namespace S00a4e670_ns;

// pdb: hk1dAngularFrictionBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: info, in, out
void __cdecl FUN_00a4e670(const S00a4e670_In* in, const S00a4e670_Info* info, S00a4e670_Schema** schemaOut)
{
    S00a4e670_Schema* s = *schemaOut;
    const hkVector4* axis = in->m_axes;
    const S00a4e670_Weight* wt = in->m_weights;
    const S00a4e670_Info* info2 = info;
    for (int i = in->m_numAxes - 1; i >= 0; i--)
    {
        buildAxis(axis, wt, in, info2, s);
        s++;
        axis++;
        wt++;
    }
    *schemaOut = s;
}
}   // namespace f3m_00a4e670

// @f3 0x00a4fb30 (community match, verified in this file)
namespace f3m_00a4fb30 {
namespace f3m_00a4fb30 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

const hkReal HK_REAL_EPSILON = 1.192092896e-07f;


template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

class hkMatrix3;
class hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) { x = a; y = b; z = c; w = d; }
    __forceinline void add4(const hkVector4& v) { (*this)(0) += v(0); (*this)(1) += v(1); (*this)(2) += v(2); (*this)(3) += v(3); }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void mul4(const hkVector4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal horizontalAdd4() const { return x + y + z + w; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v) { _setMul3(r, v); }

class hkpVelocityAccumulator
{
public:
    hkUint8 m_type;
    bool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
    __forceinline const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
    hkVector4 m_scratch0;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;
};

class hkpConstraintQueryIn
{
public:
    hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime;
    hkPadSpu<hkReal> m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime;
    hkPadSpu<hkReal> m_frameInvDeltaTime;
    hkPadSpu<hkReal> m_invNumSteps;
    hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor;
    hkPadSpu<hkReal> m_virtMassFactor;
    hkPadSpu<hkReal> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
};

class hkp1Lin2AngJacobian
{
public:
    hkVector4 m_linear0;
    hkVector4 m_angular[2];

    __forceinline hkReal getDiag(const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB) const
    {
        hkVector4 ang0; ang0.setMul4(m_angular[0], m_angular[0]);
        hkVector4 ang1; ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);
        hkVector4 lin; lin.setAdd4(mB.m_invMasses, mA.m_invMasses);
        ang0(3) = lin(3);
        hkReal x = ang0.horizontalAdd4();
        return x;
    }
};


static __forceinline hkReal dotF(const hkVector4& a, const hkVector4& b) { return a.dot3(b); }
static __forceinline void hk1dLinearBilateralBuildJacobian(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& dir,
    const hkpConstraintQueryIn& in, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, hkp1Lin2AngJacobian& jac)
{
    const hkReal virtMassFactor = in.m_virtMassFactor.val();
    const hkReal rhsFactor = in.m_rhsFactor.val();
    jac.m_linear0 = dir;
    hkVector4 rA; rA.setSub4(pivotA, mA.getCenterOfMassInWorld());
    hkVector4 rB; rB.setSub4(pivotB, mB.getCenterOfMassInWorld());
    hkVector4 c0; c0.setCross(rA, dir);
    if (mA.m_matrixIsIdentity) { jac.m_angular[0] = c0; }
    else { jac.m_angular[0]._setRotatedDir(mA.getCoreFromWorldMatrix(), c0); }
    hkVector4 c1; c1.setCross(dir, rB);
    if (mB.m_matrixIsIdentity) { jac.m_angular[1] = c1; }
    else { jac.m_angular[1]._setMul3(mB.getCoreFromWorldMatrix(), c1); }
    hkReal diag = jac.getDiag(mA, mB) + HK_REAL_EPSILON;
    jac.m_angular[1](3) = diag;
    jac.m_angular[0](3) = virtMassFactor / diag;
    hkVector4 diff; diff.setSub4(pivotB, pivotA);
    hkReal rhs = dotF(dir, diff);
    jac.m_linear0(3) = rhs * rhsFactor;
}

struct BilateralInfo
{
    hkVector4 m_pivotA;
    hkVector4 m_pivotB;
    hkVector4 m_constrainedDofW;
    hkReal m_f30;
    hkReal m_f34;
};

struct BilateralSchema
{
    hkp1Lin2AngJacobian m_jac;
    hkReal m_f30;
    hkReal m_f34;
    int unk38;
    int unk3c;
};

struct QueryOut
{
    BilateralSchema* m_jac;
};

// pdb: hk1dLinearLimitBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: info, in, out
void __cdecl FUN_00a4fb30(const BilateralInfo& info, const hkpConstraintQueryIn& in, QueryOut& out)
{
    BilateralSchema* sch = out.m_jac;
    const hkpVelocityAccumulator* mA = in.m_bodyA;
    const hkpVelocityAccumulator* mB = in.m_bodyB;
    const hkpVelocityAccumulator& bodyA = *mA;
    const hkpVelocityAccumulator& bodyB = *mB;
    hk1dLinearBilateralBuildJacobian(info.m_pivotA, info.m_pivotB, info.m_constrainedDofW, in, bodyA, bodyB, sch->m_jac);
    hkReal negTau = -in.m_rhsFactor;
    out.m_jac = sch + 1;
    hkReal f34 = info.m_f34;
    hkReal f30 = info.m_f30;
    sch->m_f30 = f30 * negTau;
    sch->m_f34 = negTau * f34;
    sch->m_jac.m_linear0.x += 1.1920928955078125e-07;
    *reinterpret_cast<unsigned char*>(sch) = 7;
}

}
}   // namespace f3m_00a4fb30

// @f3 0x00a40940 (community match, verified in this file)
namespace f3m_00a40940 {
namespace gsk_agent {

typedef unsigned char Byte;
typedef unsigned short VertexId;

struct __declspec(align(16)) Vector {
    float x, y, z, w;

    void operator=(const Vector& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    void negate3() {
        x = -x;
        y = -y;
        z = -z;
    }
};

struct Transform { Vector c0, c1, c2, translation; };

__forceinline void transformPoints(const Transform& transform, const Vector* src, int count, Vector* dst)
{
    const Vector c0 = transform.c0;
    const Vector c1 = transform.c1;
    const Vector c2 = transform.c2;
    const Vector offset = transform.translation;
    const float c0X = c0.x;
    const float c1X = c1.x;
    const float c2X = c2.x;
    const float offsetX = offset.x;
    int i = count - 1;
    do {
        const Vector& in = src[i];
        Vector& point = dst[i];
        const float x = in.x;
        const float y = in.y;
        const float z = in.z;
        point.x = x * c0X + y * c1X + z * c2X + offsetX;
        point.y = x * c0.y + y * c1.y + z * c2.y + offset.y;
        point.z = x * c0.z + y * c1.z + z * c2.z + offset.z;
        point.w = 0.0f;
    } while (--i >= 0);
}

struct Shape {
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
    virtual void v30();
    virtual void convertVerticesImpl(const VertexId*, int, Vector*) const;
    __forceinline void convertVertexIdsToVertices(const VertexId* ids, int n, Vector* out) const {
        convertVerticesImpl(ids, n, out);
    }
    virtual int weldContactPointImpl(VertexId*, Byte&, Vector&, const Transform&, const Shape*,
                                 const Transform&, Vector&) const;

    __forceinline int weldContactPoint(VertexId* ids, Byte& count, Vector& pos, const Transform& transform,
                                       const Shape* other, const Transform& otherTransform, Vector& normal) const {
        return weldContactPointImpl(ids, count, pos, transform, other, otherTransform, normal);
    }

    unsigned short memorySize, references;
    unsigned int userData;
    int type;
    float radius;
    unsigned short weldingInfo;
    Byte weldingType;
};

struct Body {
    const Shape* shape;
    unsigned int shapeKey;
    const Transform* transform;
    const Transform& getTransform() const { return *transform; }
};

struct Quality { float keepContact, create4dContact, createContact; };
struct CollisionInput {
    void* dispatcher;
    float tolerance;
    int field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c;
    const Quality* quality;
    int field64;
    Byte contactHandling;
};
struct Cache {
    VertexId vertices[4];
    Byte dimA, dimB;
};
struct AgentData {
    VertexId vertices[4];
    Byte dimA, dimB, maxDim, flags;
};
struct AgentEntry;
struct Contact {
    Vector position, normal;
    unsigned int id;
};
struct Potential {
    Contact* contact;
    AgentEntry* entry;
    AgentData* data;
};
struct PotentialContacts {
    Potential* nextPotential;
    Contact** nextRepresentative;
};
struct Output {
    Contact* next;
    void* owner;
    int field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c;
    int field60, field64, field68, field6c, field70, field74, field78, field7c;
    Contact contacts[256];
    PotentialContacts* potential;
};
struct Manager {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual unsigned short addContactImpl(const Body*, const Body*, const CollisionInput*,
                                      Output*, Cache*, Contact*);
    __forceinline unsigned short addContact(const Body* a, const Body* b, const CollisionInput* in,
                                            Output* out, Cache* cache, Contact* point) {
        return addContactImpl(a, b, in, out, cache, point);
    }
    virtual int reserve(int);
};
struct Input {
    const Body* bodyA;
    const Body* bodyB;
    const CollisionInput* collision;
    Manager* manager;
    Transform aTb;
};
struct Feature {
    Byte dimA, dimB;
    unsigned short id;
    Byte vertices[4];
};
struct Manifold {
    Byte verticesA, verticesB, count, flags;
    Feature features[4];
};
struct GskInput {
    const Transform* aTb;
    const Transform* wTa;
    const Shape* shapeA;
    const Shape* shapeB;
    float tolerance;
};
struct Work {
    Vector points[16];
    Vector normal;
    float radiusA, radiusB, tolerance, maxDistanceSquared;
};

int FUN_00a345e0(const GskInput*, Cache*, Vector*, Vector*);
void FUN_00a36820(Manifold*, Manager*, void*);
Byte FUN_00a366a0(Manifold*, const Cache*);
void FUN_00a38200(Manifold*, const Work*, int, Output*, Manager*);
int FUN_00a3a420(Manifold*, const Body*, const Body*, const CollisionInput*, Output*,
                 Cache*, Contact*, Contact*, Manager*, int);
void FUN_00a381a0(Manifold*, int);

inline int addPoint(Manifold* manifold, const Body* a, const Body* b, const CollisionInput* in,
                    Output* out, Cache* cache, Contact* point, Contact* points, Manager* mgr, int handling) {
    return FUN_00a3a420(manifold, a, b, in, out, cache, point, points, mgr, handling);
}

__forceinline void initWork(const Manifold& manifold, const Vector& weldedNormal, const Body& bodyA,
                            const Body& bodyB, float tolerance, Work& work)
{
    work.tolerance = tolerance;
    const Shape* shapeA = bodyA.shape;
    const Shape* shapeB = bodyB.shape;
    work.radiusA = shapeA->radius;
    work.radiusB = shapeB->radius;
    float sum = work.radiusA + work.tolerance + work.radiusB;
    work.maxDistanceSquared = sum * sum;
    work.normal = weldedNormal;
    if (!manifold.count)
        return;
    {
        const VertexId* ids = reinterpret_cast<const VertexId*>(&manifold.features[manifold.count]);
        shapeA->convertVertexIdsToVertices(ids, manifold.verticesA, work.points);
        transformPoints(bodyA.getTransform(), work.points, manifold.verticesA, work.points);
        Vector* pointsB = work.points + manifold.verticesA;
        shapeB->convertVertexIdsToVertices(ids + manifold.verticesA, manifold.verticesB, pointsB);
        transformPoints(bodyB.getTransform(), pointsB, manifold.verticesB, pointsB);
    }
}

// pdb: hkGskAgentUtil_processCollisionNoTim | hkpGskAgentUtil.obj | fnv360_0822_retail, caller + bridge(call_gap|caller) + skyrim(call_gap), high
void __cdecl hkGskAgentUtil_processCollisionNoTim(const Input* input, AgentEntry* entry, AgentData* agentData,
                          Cache* cache, Manifold* manifold, Vector* separatingNormal, Output* output)
{
    GskInput gsk;
    Vector pointOnB;
    gsk.shapeA = input->bodyA->shape;
    gsk.shapeB = input->bodyB->shape;
    gsk.aTb = &input->aTb;
    gsk.wTa = &input->bodyA->getTransform();
    gsk.tolerance = input->collision->tolerance;
    agentData->flags &= ~0x10;
    if (FUN_00a345e0(&gsk, cache, separatingNormal, &pointOnB) == 1) {
        if (manifold->count)
            FUN_00a36820(manifold, input->manager, output->owner);
        return;
    }

    Vector weldedNormal = *separatingNormal;
    int weld;
    if (gsk.shapeB->type == 4) {
        weld = gsk.shapeB->weldContactPoint(cache->vertices + cache->dimA, cache->dimB,
                pointOnB, input->bodyB->getTransform(), gsk.shapeA, input->bodyA->getTransform(), weldedNormal);
    } else {
        if (gsk.shapeA->type != 4 || gsk.shapeA->weldingType == 6)
            goto afterWeld;
        weldedNormal.negate3();
        weld = gsk.shapeA->weldContactPoint(cache->vertices, cache->dimA, pointOnB,
                input->bodyA->getTransform(), gsk.shapeB, input->bodyB->getTransform(), weldedNormal);
        weldedNormal.negate3();
    }
    if (weld == 0) {
        FUN_00a36820(manifold, input->manager, output->owner);
        return;
    }
    if (weld == 1)
        agentData->flags |= 0x10;

afterWeld:
    int closest = FUN_00a366a0(manifold, cache);
    Contact* resultPoints = output->next;
    Byte countByte = manifold->count;
    int count = countByte;
    if (count > closest) {
        Work work;
        initWork(*manifold, weldedNormal, *input->bodyA, *input->bodyB, input->collision->tolerance, work);
        FUN_00a38200(manifold, &work, closest, output, input->manager);
    }
    Contact* point = output->next;
    point->position = pointOnB;
    point->normal = weldedNormal;
    if (closest) {
        point->id = manifold->features[0].id;
        ++output->next;
        goto representative;
    }
    {
        int dimensions = cache->dimB + cache->dimA;
        const CollisionInput* ci = input->collision;
        const Quality* quality = ci->quality;
        float limit = dimensions == 4 ? quality->create4dContact : quality->createContact;
        if (!(separatingNormal->w < limit))
            goto representative;
        int handling = ci->contactHandling != 0;
        int result = addPoint(manifold, input->bodyA, input->bodyB, input->collision, output,
                              cache, point, resultPoints, input->manager, handling);
        if (result == 4) {
            if (point->id != 0xffff) {
                ++output->next;
                goto representative;
            }
            if (output->potential && entry) {
                if (input->manager->reserve(1))
                    goto removePoint;
                Potential* p = output->potential->nextPotential++;
                p->entry = entry;
                p->contact = point;
                p->data = agentData;
            } else {
                unsigned int id = input->manager->addContact(input->bodyA, input->bodyB,
                                              input->collision, output, cache, point);
                point->id = id;
                if (id == 0xffff)
                    goto removePoint;
                manifold->features[0].id = static_cast<unsigned short>(id);
            }
            ++output->next;
            goto representative;
removePoint:
            FUN_00a381a0(manifold, 0);
            goto restorePoint;
        }
        if (result == 5) {
restorePoint:
            point = resultPoints;
            goto representative;
        }
        if (result == 6) {
            --output->next;
            point = resultPoints;
            goto representative;
        }
        point = resultPoints + result;
    }
representative:
    if (output->potential && point < output->next) {
        *output->potential->nextRepresentative = point;
        ++output->potential->nextRepresentative;
    }
}
}

}   // namespace f3m_00a40940

// @f3 0x00a53120 (community match, verified in this file)
namespace f3m_00a53120 {
// FUN_00a53120 = Havok 5.5.0 hkpMoppLongRayVirtualMachine::queryRayOnTree (hkpInternal.lib,
// hkpMoppLongRayVirtualMachine.obj; the stock release object is byte-exact against the game): the recursive MOPP
// byte-code interpreter of the long-ray query. Reconstructed (the .cpp is not shipped) from the hybrid object's line
// records 152-552 and locals, the debug_multithreaded out-of-line copies of addHit (lines 59-111) and read24, the pdb
// layouts and the SDK's verbatim inline bodies; cut with hktrim.py.
namespace f3m_00a53120 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
class hkClass;
typedef int hkBool32;

class hkBool
{
	public:
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
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

class hkStreamWriter;

class hkOstream : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		~hkOstream();
		hkOstream& operator<< (const char* s);
	protected:
		hkStreamWriter*	m_writer;
};

class hkError : public hkReferencedObject, public hkSingleton<hkError>
{
	public:
		enum Message
		{
			MESSAGE_REPORT,
			MESSAGE_WARNING,
			MESSAGE_ASSERT,
			MESSAGE_ERROR
		};
		virtual int message(Message m, int id, const char* description, const char* file, int line) = 0;
		virtual void setEnabled( int id, hkBool enabled ) = 0;
		virtual hkBool isEnabled( int id ) = 0;
		virtual void enableAll() = 0;
		virtual void sectionBegin(int id, const char* sectionName) {}
		virtual void sectionEnd() {}
};

class hkErrStream : public hkOstream
{
	public:
		hkErrStream( void* buf, int bufSize );
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
		__forceinline const_iterator begin() const;
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

template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}

typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void mul4b(hkSimdRealParameter a);
		__forceinline void mul4e(hkSimdRealParameter a);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
        __declspec(align(16)) hkReal components[4];
};

inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return components[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return components[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	components[0] = v.components[0];
	components[1] = v.components[1];
	components[2] = v.components[2];
	components[3] = v.components[3];
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	components[0] = a;
	components[1] = b;
	components[2] = c;
	components[3] = d;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	components[0] = v0.components[0] + v1.components[0];
	components[1] = v0.components[1] + v1.components[1];
	components[2] = v0.components[2] + v1.components[2];
	components[3] = v0.components[3] + v1.components[3];
}

inline void hkVector4::sub4(const hkVector4& v)
{
	components[0] -= v.components[0];
	components[1] -= v.components[1];
	components[2] -= v.components[2];
	components[3] -= v.components[3];
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	components[0] = v0.components[0] - v1.components[0];
	components[1] = v0.components[1] - v1.components[1];
	components[2] = v0.components[2] - v1.components[2];
	components[3] = v0.components[3] - v1.components[3];
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	components[0] *= s;
	components[1] *= s;
	components[2] *= s;
	components[3] *= s;
}

inline void hkVector4::mul4b(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	components[0] *= s;
	components[1] *= s;
	components[2] *= s;
	{ hkReal& w = components[3]; w *= s; }
}

inline void hkVector4::mul4e(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	hkReal* c = components;
	c[0] *= s;
	c[1] *= s;
	c[2] *= s;
	c[3] *= s;
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

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

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
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
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

hkBool hkpShape::castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const
{
	return castRayImpl( input, output );
}

struct hkpShapeRayCastCollectorOutput
{
	                class MustEndWithSemiColon;
	hkVector4 m_normal;
	hkReal m_hitFraction;
	int m_extraInfo;
	int m_unknown18;
	int m_unknown1c;
};

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
	public:
		enum { MAX_HIERARCHY_DEPTH = 8 };
	public:
		                class MustEndWithSemiColon;
		__forceinline void changeLevel(int delta);
		__forceinline void setKey(hkpShapeKey key);
	public:
		hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
	private:
		int m_shapeKeyIndex;
};

void hkpShapeRayCastOutput::changeLevel(int delta)
{
	;
	m_shapeKeyIndex += delta;
}

inline void hkpShapeRayCastOutput::setKey(hkpShapeKey key)
{
	m_shapeKeys[m_shapeKeyIndex] = key;
}

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

hkpCdBody::hkpCdBody( const hkpCdBody* parent )
{
	m_parent = parent;
	m_motion = parent->m_motion;
}

void hkpCdBody::setShape( const hkpShape* shape, hkpShapeKey key )
{
	m_shape = shape;
	m_shapeKey = key;
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

class hkpRayShapeCollectionFilter;

struct hkpShapeRayCastInput
{
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};

class hkpRayHitCollector
{
	public:
		virtual void addRayHit( const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInfo ) = 0;
		virtual ~hkpRayHitCollector() { }
	public:
		hkReal m_earlyOutHitFraction;
};

class hkpRayShapeCollectionFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool isCollisionEnabled( const hkpShapeRayCastInput& aInput, const hkpShape& bShape, const hkpShapeContainer& hContainer, hkpShapeKey bKey ) const = 0;
		virtual ~hkpRayShapeCollectionFilter() { }
};

class hkpMoppCode : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum
		{
			MIN_PROPERTY_VALUE = 0,
			MAX_PROPERTY_VALUE = 0xffffffff
		};
		enum
		{
			MAX_PRIMITIVE_PROPERTIES = 1
		};
		enum BuildType
		{
			BUILT_WITH_CHUNK_SUBDIVISION,
			BUILT_WITHOUT_CHUNK_SUBDIVISION,
		};
		struct CodeInfo
		{
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkVector4 m_offset;
		};
	public:
		virtual ~hkpMoppCode() {}
		void calcStatistics( hkStatisticsCollector* collector ) const;
	public:
		struct CodeInfo m_info;
		hkArray<hkUint8> m_data;
		hkEnum<BuildType, hkInt8> m_buildType;
};

enum hkpMoppCommands
{
	HK_MOPP_RETURN = 0,
	HK_MOPP_SCALE1, HK_MOPP_SCALE2, HK_MOPP_SCALE3, HK_MOPP_SCALE4,
	HK_MOPP_JUMP8, HK_MOPP_JUMP16, HK_MOPP_JUMP24, HK_MOPP_JUMP32,
	HK_MOPP_TERM_REOFFSET8, HK_MOPP_TERM_REOFFSET16, HK_MOPP_TERM_REOFFSET32,
	HK_MOPP_JUMP_CHUNK, HK_MOPP_DATA_OFFSET,
	HK_MOPP_SPLIT_X = 0x10, HK_MOPP_SPLIT_Y, HK_MOPP_SPLIT_Z,
	HK_MOPP_SPLIT_YZ, HK_MOPP_SPLIT_YMZ, HK_MOPP_SPLIT_XZ, HK_MOPP_SPLIT_XMZ, HK_MOPP_SPLIT_XY, HK_MOPP_SPLIT_XMY,
	HK_MOPP_SPLIT_XYZ, HK_MOPP_SPLIT_XYMZ, HK_MOPP_SPLIT_XMYZ, HK_MOPP_SPLIT_XMYMZ,
	HK_MOPP_SINGLE_SPLIT_X = 0x20, HK_MOPP_SINGLE_SPLIT_Y, HK_MOPP_SINGLE_SPLIT_Z,
	HK_MOPP_SPLIT_JUMP_X, HK_MOPP_SPLIT_JUMP_Y, HK_MOPP_SPLIT_JUMP_Z,
	HK_MOPP_DOUBLE_CUT_X, HK_MOPP_DOUBLE_CUT_Y, HK_MOPP_DOUBLE_CUT_Z,
	HK_MOPP_DOUBLE_CUT24_X, HK_MOPP_DOUBLE_CUT24_Y, HK_MOPP_DOUBLE_CUT24_Z,
	HK_MOPP_TERM4_0 = 0x30, HK_MOPP_TERM4_1, HK_MOPP_TERM4_2, HK_MOPP_TERM4_3, HK_MOPP_TERM4_4, HK_MOPP_TERM4_5,
	HK_MOPP_TERM4_6, HK_MOPP_TERM4_7, HK_MOPP_TERM4_8, HK_MOPP_TERM4_9, HK_MOPP_TERM4_A, HK_MOPP_TERM4_B,
	HK_MOPP_TERM4_C, HK_MOPP_TERM4_D, HK_MOPP_TERM4_E, HK_MOPP_TERM4_F, HK_MOPP_TERM4_10, HK_MOPP_TERM4_11,
	HK_MOPP_TERM4_12, HK_MOPP_TERM4_13, HK_MOPP_TERM4_14, HK_MOPP_TERM4_15, HK_MOPP_TERM4_16, HK_MOPP_TERM4_17,
	HK_MOPP_TERM4_18, HK_MOPP_TERM4_19, HK_MOPP_TERM4_1A, HK_MOPP_TERM4_1B, HK_MOPP_TERM4_1C, HK_MOPP_TERM4_1D,
	HK_MOPP_TERM4_1E, HK_MOPP_TERM4_1F,
	HK_MOPP_TERM8, HK_MOPP_TERM16, HK_MOPP_TERM24, HK_MOPP_TERM32,
	HK_MOPP_NTERM8, HK_MOPP_NTERM16, HK_MOPP_NTERM24, HK_MOPP_NTERM32,
	HK_MOPP_PROPERTY8_0 = 0x60, HK_MOPP_PROPERTY8_1, HK_MOPP_PROPERTY8_2, HK_MOPP_PROPERTY8_3,
	HK_MOPP_PROPERTY16_0, HK_MOPP_PROPERTY16_1, HK_MOPP_PROPERTY16_2, HK_MOPP_PROPERTY16_3,
	HK_MOPP_PROPERTY32_0, HK_MOPP_PROPERTY32_1, HK_MOPP_PROPERTY32_2, HK_MOPP_PROPERTY32_3
};

struct hkpMoppPrimitiveInfo;

class hkpMoppVirtualMachine
{
	public:
		                class MustEndWithSemiColon;
	protected:
		static inline int __cdecl read24( const unsigned char* PC );
	public:
		hkArray<hkpMoppPrimitiveInfo>* m_primitives_out;
		int padding[3];
};

inline int readMoppU16(const unsigned char* p)
{
    return (int(p[0]) << 8) + p[1];
}

inline int __cdecl hkpMoppVirtualMachine::read24( const unsigned char* PC )
{
	return (int(PC[0]) << 16) + readMoppU16(PC + 1);
}

class hkpMoppLongRayVirtualMachine : public hkpMoppVirtualMachine
{
	public:
		                class MustEndWithSemiColon;
		struct QueryInt
		{
			hkVector4 m_FtoBoffset;
			int m_shift;
			float m_FtoBScale;
			unsigned int m_primitiveOffset;
			unsigned int m_properties[hkpMoppCode::MAX_PRIMITIVE_PROPERTIES];
		};
		struct QueryFloat
		{
			hkVector4 m_rayEnds[2];
		};
	protected:
		void FUN_00a53120( const QueryInt* query, const unsigned char* PC, QueryFloat* const fQuery, int chunkId );
		__forceinline void addHit( unsigned int key, const unsigned int properties[hkpMoppCode::MAX_PRIMITIVE_PROPERTIES] );
		__forceinline hkVector4 interpolatedRayPoint(hkReal fraction) const;
	public:
		const hkpMoppCode* m_code;
		float m_ItoFScale;
		hkpShapeRayCastInput m_ray;
		hkBool m_hitFound;
		float m_earlyOutHitFraction;
		hkpShapeRayCastOutput* m_rayResultPtr;
		hkpRayHitCollector* m_collector;
		const hkpCdBody* m_body;
		const hkpShapeContainer* m_collection;
		int m_reindexingMask;
};

extern "C" hkBool HK_flyingcolors_mopp;
extern "C" bool processFlyingColors( int );

__forceinline hkVector4 hkpMoppLongRayVirtualMachine::interpolatedRayPoint(hkReal fraction) const
{
    hkVector4 point;
    point.setInterpolate4(m_ray.m_from, m_ray.m_to, fraction);
    return point;
}
__forceinline void hkpMoppLongRayVirtualMachine::addHit( unsigned int key, const unsigned int properties[hkpMoppCode::MAX_PRIMITIVE_PROPERTIES] )
{
	hkpShapeContainer::ShapeBuffer shapeBuffer;
	const hkpShape* childShape = m_collection->getChildShape( key, shapeBuffer );
	if ( m_ray.m_rayShapeCollectionFilter )
	{
		if ( !m_ray.m_rayShapeCollectionFilter->isCollisionEnabled( m_ray, *childShape, *m_collection, key ) )
		{
			return;
		}
	}
	if ( m_rayResultPtr )
	{
		m_rayResultPtr->changeLevel( 1 );
		hkBool hitFound = childShape->castRay( m_ray, *m_rayResultPtr );
		m_rayResultPtr->changeLevel( -1 );
		if ( hitFound )
		{
			m_hitFound = hitFound;
			m_earlyOutHitFraction = m_rayResultPtr->m_hitFraction;
			m_rayResultPtr->setKey( key );
		}
	}
	else
	{
		hkpCdBody childBody( m_body );
		childBody.setShape( childShape, key );
		childShape->castRayWithCollector( m_ray, childBody, *m_collector );
		m_earlyOutHitFraction = m_collector->m_earlyOutHitFraction;
	}
}

// pdb: hkpMoppLongRayVirtualMachine::queryRayOnTree | hkpMoppLongRayVirtualMachine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: query, PC, fQuery, chunkOffset
void hkpMoppLongRayVirtualMachine::FUN_00a53120( const QueryInt* query, const unsigned char* PC, QueryFloat* const fQuery, int chunkId )
{
	QueryInt scaledQuery;
	if ( !HK_flyingcolors_mopp )
	{
		HK_flyingcolors_mopp = processFlyingColors( 4 );
		if ( !HK_flyingcolors_mopp )
		{
			return;
		}
	}
	while ( 1 )
	{
		hkpMoppCommands command = hkpMoppCommands( *PC );
		int tdir = 999;
		hkReal foffseth;
		hkReal foffsetl;
		hkReal positionl;
		hkReal positionh;
		int offsetLB;
		int offsetRB;
		int offsetl;
		int offseth;
		switch ( command )
		{
			case HK_MOPP_SPLIT_YZ:    foffseth = PC[1] * 2;       foffsetl = PC[2] * 2;       positionl = fQuery->m_rayEnds[0](1) + fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](1) + fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_YMZ:   foffseth = PC[1] * 2 - 255; foffsetl = PC[2] * 2 - 255; positionl = fQuery->m_rayEnds[0](1) - fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](1) - fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_XZ:    foffseth = PC[1] * 2;       foffsetl = PC[2] * 2;       positionl = fQuery->m_rayEnds[0](0) + fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](0) + fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_XMZ:   foffseth = PC[1] * 2 - 255; foffsetl = PC[2] * 2 - 255; positionl = fQuery->m_rayEnds[0](0) - fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](0) - fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_XY:    foffseth = PC[1] * 2;       foffsetl = PC[2] * 2;       positionl = fQuery->m_rayEnds[0](0) + fQuery->m_rayEnds[0](1); positionh = fQuery->m_rayEnds[1](0) + fQuery->m_rayEnds[1](1); goto do_compareN4;
			case HK_MOPP_SPLIT_XMY:   foffseth = PC[1] * 2 - 255; foffsetl = PC[2] * 2 - 255; positionl = fQuery->m_rayEnds[0](0) - fQuery->m_rayEnds[0](1); positionh = fQuery->m_rayEnds[1](0) - fQuery->m_rayEnds[1](1); goto do_compareN4;
			case HK_MOPP_SPLIT_XYZ:   foffseth = PC[1] * 3;       foffsetl = PC[2] * 3;       positionl = fQuery->m_rayEnds[0](0) + fQuery->m_rayEnds[0](1) + fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](0) + fQuery->m_rayEnds[1](1) + fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_XYMZ:  foffseth = PC[1] * 3 - 255; foffsetl = PC[2] * 3 - 255; positionl = fQuery->m_rayEnds[0](0) + fQuery->m_rayEnds[0](1) - fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](0) + fQuery->m_rayEnds[1](1) - fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_XMYZ:  foffseth = PC[1] * 3 - 255; foffsetl = PC[2] * 3 - 255; positionl = fQuery->m_rayEnds[0](0) - fQuery->m_rayEnds[0](1) + fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](0) - fQuery->m_rayEnds[1](1) + fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SPLIT_XMYMZ: foffseth = PC[1] * 3 - 510; foffsetl = PC[2] * 3 - 510; positionl = fQuery->m_rayEnds[0](0) - fQuery->m_rayEnds[0](1) - fQuery->m_rayEnds[0](2); positionh = fQuery->m_rayEnds[1](0) - fQuery->m_rayEnds[1](1) - fQuery->m_rayEnds[1](2); goto do_compareN4;
			case HK_MOPP_SINGLE_SPLIT_X:
			case HK_MOPP_SINGLE_SPLIT_Y:
			case HK_MOPP_SINGLE_SPLIT_Z:
				tdir = command - HK_MOPP_SINGLE_SPLIT_X;
				foffsetl = PC[1];
				foffseth = foffsetl + 1.0;
				positionl = ( &fQuery->m_rayEnds[0](0) )[tdir];
				positionh = ( &fQuery->m_rayEnds[1](0) )[tdir];
				PC += 3;
				offsetLB = 0;
				offsetRB = PC[-1];
				goto do_compare;
			case HK_MOPP_SPLIT_JUMP_X:
			case HK_MOPP_SPLIT_JUMP_Y:
			case HK_MOPP_SPLIT_JUMP_Z:
				tdir = command - HK_MOPP_SPLIT_JUMP_X;
				foffseth = PC[1];
				foffsetl = PC[2];
				positionl = ( &fQuery->m_rayEnds[0](0) )[tdir];
				positionh = ( &fQuery->m_rayEnds[1](0) )[tdir];
				offsetLB = ( PC[3] << 8 ) + PC[4];
				PC += 7;
				offsetRB = ( PC[-2] << 8 ) + PC[-1];
				goto do_compare;
			case HK_MOPP_SPLIT_X:
			case HK_MOPP_SPLIT_Y:
			case HK_MOPP_SPLIT_Z:
				tdir = command - HK_MOPP_SPLIT_X;
				foffseth = PC[1];
				foffsetl = PC[2];
				positionl = ( &fQuery->m_rayEnds[0](0) )[tdir];
				positionh = ( &fQuery->m_rayEnds[1](0) )[tdir];
do_compareN4:
				PC += 4;
				offsetLB = 0;
				offsetRB = PC[-1];
do_compare:
				if ( positionh < foffsetl && positionl < foffsetl )
				{
					PC += offsetLB;
					continue;
				}
				PC += offsetRB;
				if ( positionl > foffseth && positionh > foffseth )
				{
					continue;
				}
				{
					const hkReal la = positionl - foffseth;
					const hkReal ha = positionl - foffsetl;
					const hkReal lb = positionh - foffseth;
					const hkReal hb = positionh - foffsetl;
					QueryFloat leftFloat;
					leftFloat.m_rayEnds[0] = fQuery->m_rayEnds[0];
					leftFloat.m_rayEnds[1] = fQuery->m_rayEnds[1];
					if ( la < lb )
					{
						if ( la * lb < 0.0 )
						{
							const hkReal ratio = la / ( la - lb );
							leftFloat.m_rayEnds[1].setInterpolate4( fQuery->m_rayEnds[0], fQuery->m_rayEnds[1], ratio );
						}
						FUN_00a53120( query, PC - offsetRB + offsetLB, &leftFloat, chunkId );
						if ( ha * hb < 0.0 )
						{
							const hkReal ratio = ha / ( ha - hb );
							fQuery->m_rayEnds[0].setInterpolate4( fQuery->m_rayEnds[0], fQuery->m_rayEnds[1], ratio );
						}
						if ( m_earlyOutHitFraction < 1.0 )
						{
							hkReal fraction = m_earlyOutHitFraction;
							hkVector4 hitpoint;
							hitpoint.setInterpolate4( m_ray.m_from, m_ray.m_to, fraction );
							fQuery->m_rayEnds[1].setSub4( hitpoint, m_code->m_info.m_offset );
							fQuery->m_rayEnds[1].mul4( query->m_FtoBScale );
							fQuery->m_rayEnds[1].sub4( query->m_FtoBoffset );
							if ( tdir < 3 && ( &fQuery->m_rayEnds[1](0) )[tdir] < foffsetl )
							{
								return;
							}
						}
						continue;
					}
					else
					{
						if ( ha * hb < 0.0 )
						{
							const hkReal ratio = ha / ( ha - hb );
							leftFloat.m_rayEnds[1].setInterpolate4( fQuery->m_rayEnds[0], fQuery->m_rayEnds[1], ratio );
						}
						FUN_00a53120( query, PC, &leftFloat, chunkId );
						if ( la * lb < 0.0 )
						{
							const hkReal ratio = la / ( la - lb );
							fQuery->m_rayEnds[0].setInterpolate4( fQuery->m_rayEnds[0], fQuery->m_rayEnds[1], ratio );
						}
						if ( m_earlyOutHitFraction < 1.0 )
						{
							hkReal fraction = m_earlyOutHitFraction;
							hkVector4 hitpoint = interpolatedRayPoint(fraction);
							fQuery->m_rayEnds[1].setSub4( hitpoint, m_code->m_info.m_offset );
							fQuery->m_rayEnds[1].mul4( query->m_FtoBScale );
							fQuery->m_rayEnds[1].sub4( query->m_FtoBoffset );
							if ( tdir < 3 && ( &fQuery->m_rayEnds[1](0) )[tdir] > foffseth )
							{
								return;
							}
						}
						PC = PC - offsetRB + offsetLB;
						continue;
					}
				}
			case HK_MOPP_DOUBLE_CUT24_X:
			case HK_MOPP_DOUBLE_CUT24_Y:
			case HK_MOPP_DOUBLE_CUT24_Z:
				tdir = command - HK_MOPP_DOUBLE_CUT24_X;
				foffsetl = read24( PC + 1 ) * m_ItoFScale;
				foffseth = read24( PC + 4 ) * m_ItoFScale;
				foffsetl *= query->m_FtoBScale;
				foffseth *= query->m_FtoBScale;
				foffsetl -= query->m_FtoBoffset(tdir);
				foffseth -= query->m_FtoBoffset(tdir);
				PC += 7;
				goto doCut;
			case HK_MOPP_DOUBLE_CUT_X:
			case HK_MOPP_DOUBLE_CUT_Y:
			case HK_MOPP_DOUBLE_CUT_Z:
				tdir = command - HK_MOPP_DOUBLE_CUT_X;
				foffsetl = PC[1];
				foffseth = PC[2];
				PC += 3;
doCut:
				{
					positionl = fQuery->m_rayEnds[0](tdir);
					positionh = fQuery->m_rayEnds[1](tdir);
					int sign;
					if ( positionl < positionh )
					{
						if ( positionh < foffsetl || positionl > foffseth )
						{
							goto end_of_function;
						}
						sign = 0;
					}
					else
					{
						if ( positionl < foffsetl || positionh > foffseth )
						{
							goto end_of_function;
						}
						sign = 1;
					}
					hkVector4 rayStartPoint = fQuery->m_rayEnds[0];
					hkVector4 rayEndPoint = fQuery->m_rayEnds[1];
					{
						const hkReal R0 = positionl - foffseth;
						const hkReal R1 = positionh - foffseth;
						if ( R0 * R1 < 0.0 )
						{
							const hkReal ratio = R0 / ( R0 - R1 );
							fQuery->m_rayEnds[1 - sign].setInterpolate4( rayStartPoint, rayEndPoint, ratio );
						}
					}
					{
						const hkReal L0 = positionl - foffsetl;
						const hkReal L1 = positionh - foffsetl;
						if ( L0 * L1 < 0.0 )
						{
							const hkReal ratio = L0 / ( L0 - L1 );
							fQuery->m_rayEnds[sign].setInterpolate4( rayStartPoint, rayEndPoint, ratio );
						}
					}
				}
				continue;
			case HK_MOPP_JUMP8:  offsetl = PC[1]; PC += 2; PC += offsetl; continue;
			case HK_MOPP_JUMP16: offseth = PC[1]; offsetl = PC[2]; PC += 3; PC += ( offseth << 8 ) + offsetl; continue;
			case HK_MOPP_JUMP24: { offseth = PC[1]; const unsigned int offsetm = PC[2]; offsetl = PC[3]; PC += 4; PC += ( offseth << 16 ) + ( offsetm << 8 ) + offsetl; } continue;
			case HK_MOPP_JUMP_CHUNK:
				{
					chunkId = ( PC[1] << 8 ) | PC[2];
					const unsigned char* jumpAddress = m_code->m_data.begin() + chunkId * 512;
					PC = jumpAddress;
				}
				continue;
			case HK_MOPP_DATA_OFFSET:
				PC += 5;
				continue;
			case HK_MOPP_SCALE1:
			case HK_MOPP_SCALE2:
			case HK_MOPP_SCALE3:
			case HK_MOPP_SCALE4:
				{
					const unsigned int shift = command;
					hkVector4 extraOffset; extraOffset.set( PC[1], PC[2], PC[3], 0.0f );
					hkReal f = hkReal( 1 << shift );
					fQuery->m_rayEnds[0].sub4( extraOffset );
					fQuery->m_rayEnds[1].sub4( extraOffset );
					fQuery->m_rayEnds[0].mul4b( f );
					fQuery->m_rayEnds[1].mul4e( f );
					scaledQuery.m_FtoBoffset.setAdd4( query->m_FtoBoffset, extraOffset );
					scaledQuery.m_FtoBoffset.mul4( f );
					scaledQuery.m_shift = query->m_shift + shift;
					scaledQuery.m_FtoBScale = query->m_FtoBScale * f;
					for ( int p = 0; p < hkpMoppCode::MAX_PRIMITIVE_PROPERTIES; p++ )
					{
						scaledQuery.m_properties[p] = query->m_properties[p];
					}
					scaledQuery.m_primitiveOffset = query->m_primitiveOffset;
					query = &scaledQuery;
					PC += 4;
				}
				continue;
			case HK_MOPP_RETURN: goto end_of_function;
			case HK_MOPP_TERM8:  offsetl = PC[1]; goto add_Terminal;
			case HK_MOPP_TERM16: offseth = PC[1]; offseth <<= 8; offsetl = PC[2]; offsetl += offseth; goto add_Terminal;
			case HK_MOPP_TERM24: offsetl = PC[1]; offsetl <<= 16; offseth = PC[2]; offseth <<= 8; offseth += PC[3]; offsetl += offseth; goto add_Terminal;
			case HK_MOPP_TERM32: offsetl = PC[1]; offsetl <<= 24; offseth = PC[2]; offseth <<= 16; offsetl += offseth; offseth = PC[3]; offsetl += PC[4]; offseth <<= 8; offsetl += offseth; goto add_Terminal;
			case HK_MOPP_TERM4_0:  case HK_MOPP_TERM4_1:  case HK_MOPP_TERM4_2:  case HK_MOPP_TERM4_3:
			case HK_MOPP_TERM4_4:  case HK_MOPP_TERM4_5:  case HK_MOPP_TERM4_6:  case HK_MOPP_TERM4_7:
			case HK_MOPP_TERM4_8:  case HK_MOPP_TERM4_9:  case HK_MOPP_TERM4_A:  case HK_MOPP_TERM4_B:
			case HK_MOPP_TERM4_C:  case HK_MOPP_TERM4_D:  case HK_MOPP_TERM4_E:  case HK_MOPP_TERM4_F:
			case HK_MOPP_TERM4_10: case HK_MOPP_TERM4_11: case HK_MOPP_TERM4_12: case HK_MOPP_TERM4_13:
			case HK_MOPP_TERM4_14: case HK_MOPP_TERM4_15: case HK_MOPP_TERM4_16: case HK_MOPP_TERM4_17:
			case HK_MOPP_TERM4_18: case HK_MOPP_TERM4_19: case HK_MOPP_TERM4_1A: case HK_MOPP_TERM4_1B:
			case HK_MOPP_TERM4_1C: case HK_MOPP_TERM4_1D: case HK_MOPP_TERM4_1E: case HK_MOPP_TERM4_1F:
				offsetl = command - HK_MOPP_TERM4_0;
add_Terminal:
				{
					offsetl += query->m_primitiveOffset;
					unsigned int keyRemap = ( ( chunkId << 8 ) & m_reindexingMask ) | offsetl;
					addHit( keyRemap, query->m_properties );
				}
				goto end_of_function;
			case HK_MOPP_TERM_REOFFSET8:  { const unsigned int offset = PC[1]; if ( query != &scaledQuery ) { scaledQuery = *query; query = &scaledQuery; } scaledQuery.m_primitiveOffset += offset; PC += 2; } continue;
			case HK_MOPP_TERM_REOFFSET16: { const unsigned int offset = ( PC[1] << 8 ) + PC[2]; if ( query != &scaledQuery ) { scaledQuery = *query; query = &scaledQuery; } scaledQuery.m_primitiveOffset += offset; PC += 3; } continue;
			case HK_MOPP_TERM_REOFFSET32: { const unsigned int offset = ( PC[1] << 24 ) + ( PC[2] << 16 ) + ( PC[3] << 8 ) + PC[4]; if ( query != &scaledQuery ) { scaledQuery = *query; query = &scaledQuery; } scaledQuery.m_primitiveOffset = offset; PC += 5; } continue;
			case HK_MOPP_PROPERTY8_0: case HK_MOPP_PROPERTY8_1: case HK_MOPP_PROPERTY8_2: case HK_MOPP_PROPERTY8_3: { unsigned int property; unsigned int value; property = *PC - HK_MOPP_PROPERTY8_0; value = PC[1]; PC += 2; scaledQuery.m_properties[property] = value; propertyCopy: const unsigned int v = scaledQuery.m_properties[0]; if ( query != &scaledQuery ) { scaledQuery = *query; query = &scaledQuery; } scaledQuery.m_properties[0] = v; } continue;
			case HK_MOPP_PROPERTY16_0: case HK_MOPP_PROPERTY16_1: case HK_MOPP_PROPERTY16_2: case HK_MOPP_PROPERTY16_3: { const unsigned int property = *PC - HK_MOPP_PROPERTY16_0; const unsigned int value = ( PC[1] << 8 ) + PC[2]; scaledQuery.m_properties[property] = value; PC += 3; } goto propertyCopy;
			case HK_MOPP_PROPERTY32_0: case HK_MOPP_PROPERTY32_1: case HK_MOPP_PROPERTY32_2: case HK_MOPP_PROPERTY32_3: { const unsigned int property = *PC - HK_MOPP_PROPERTY32_0; const unsigned int value = ( PC[1] << 24 ) + ( PC[2] << 16 ) + ( PC[3] << 8 ) + PC[4]; scaledQuery.m_properties[property] = value; PC += 5; } goto propertyCopy;
			default:
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf,sizeof(assertBuf)); ostr << "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n"; hkError::getInstance().message(hkError::MESSAGE_ERROR, 0x1298fedd, assertBuf, ".\\Collide\\Mopp\\Machine\\hkpMoppLongRayVirtualMachine.cpp", 546); } else;
		}
	}
end_of_function:
	return;
}
}
}   // namespace f3m_00a53120
