#include <math.h>
// src/f3staging/f3blk_00920000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00925840 (community match, verified in this file)
namespace f3m_00925840 {

extern "C" void __stdcall FUN_008fe950(void* dest);

struct __declspec(align(16)) Vec { float x, y, z, w; };

struct ArgDb610 { void FUN_008db610(void* dst, const void* src); };

class C925840 {
public:
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    void* FUN_00925840(void* arg);
};

// pdb: bhkRigidBodyT::GetRotation | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, low
// pdb params: arRot
void* C925840::FUN_00925840(void* arg) {
    Vec v;
    FUN_008fe950(&v);
    ((ArgDb610*)arg)->FUN_008db610(&v, (unsigned char*)this + 0x20);
    return arg;
}
}   // namespace f3m_00925840

// @f3 0x00934150 (community match, verified in this file)
namespace f3m_00934150 {
// pdb: hkDataArrayNative::swizzleObjectMember | hkDataObjectNative.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: hkDataObjectNative::asReal)
// pdb params: name
namespace Convert378{extern char DAT_00e46128;struct Array{int FUN_0093d8c0();};struct __declspec(align(8)) FUN_0093d600{void*object;int index;FUN_0093d600(void*,const char*);Array*FUN_0093d790();unsigned char*FUN_0093d710(int);unsigned short*FUN_0093d6f0(int);};void __cdecl FUN_00934150(void*source,void*destination){FUN_0093d600 from(source,&DAT_00e46128);FUN_0093d600 to(destination,&DAT_00e46128);for(int i=0;i<to.FUN_0093d790()->FUN_0093d8c0();++i){unsigned short value=*from.FUN_0093d710(i);*to.FUN_0093d6f0(i)=value;}}}
}   // namespace f3m_00934150

// @f3 0x00932e10 (community match, verified in this file)
extern const char DAT_00e3b054[];
namespace f3m_00932e10 {
namespace task932e10 {
struct Array { char* data; int count; };
struct __declspec(align(8)) Info { int unk00; void* type; };
struct Size { int FUN_009b0760(); };
struct Reader { int unk00,unk04; Reader(void*,const char*); Array* FUN_0093d760(int); Info* FUN_0093d810(Info*); };
struct Cursor { char* data; Size* type; };
extern void __cdecl FUN_00932ce0(Cursor*,Cursor*,void*);
void __cdecl FUN_00932e10(void* a,void* b,void* param) {
 Reader src(a,DAT_00e3b054),dst(b,DAT_00e3b054);
 Array* x=src.FUN_0093d760(0); Array* y=dst.FUN_0093d760(0);
 Cursor left,right;
 { Info tmp;
   left.data=0;
   left.type=(Size*)src.FUN_0093d810(&tmp)->type;
   right.data=0;
   right.type=(Size*)dst.FUN_0093d810(&tmp)->type; }
 int stepA=left.type->FUN_009b0760(),stepB=right.type->FUN_009b0760();
 for (int i=0;i<x->count;i++) {left.data=x->data+stepA*i;right.data=y->data+stepB*i;FUN_00932ce0(&left,&right,param);}
}
}
}   // namespace f3m_00932e10

// @f3 0x00925110 (community match, verified in this file)
namespace f3m_00925110 {
struct Vec00925110 {
    float unk00; float unk04; float unk08; float unk0c;
    float unk10; float unk14; float unk18; float unk1c;
    float unk20; float unk24; float unk28; float unk2c;
    float unk30; float unk34; float unk38;
};
struct Matrix00925110 {
    float m00; float m01; float m02; float m03;
    float m10; float m11; float m12; float m13;
    float m20; float m21; float m22; float m23;
    float t0; float t1; float t2; float t3;
    void FUN_0096c450(Vec00925110*);
    void hkTransform_setInverse(Vec00925110*);
};
// pdb: hkTransform::setInverse | hkTransform.obj | fnv360_0822_debug, call_gap + bridge(call_gap|call_dedup) + skyrim(call_seq), high
void Matrix00925110::hkTransform_setInverse(Vec00925110* v) {
    __declspec(align(16)) float n[4];
    FUN_0096c450(v);
    n[0] = -v->unk30;
    n[1] = -v->unk34;
    n[2] = -v->unk38;
    t0 = m00 * n[0] + m10 * n[1] + m20 * n[2];
    t1 = m01 * n[0] + m11 * n[1] + m21 * n[2];
    t2 = m02 * n[0] + m12 * n[1] + m22 * n[2];
    t3 = 0.0f;
}
}   // namespace f3m_00925110

// @f3 0x0093d030 (community match, verified in this file)
extern const char DAT_00e721b0[];
extern const char DAT_00e6ce4c[];
extern const char DAT_00e6ce2c[];
extern const char DAT_00e6ce3c[];
namespace f3m_0093d030 {
struct Slot7MemberAccessor
{
    __declspec(align(8)) void* address;
    void* member;
    void FUN_0093d600(void* object,const char* name);
    bool* FUN_0093d640(bool* result);
    bool* FUN_0093d690(int index);
    float* FUN_0093d6a0(int index);
};
float __cdecl FUN_008d3240(float angle);
float __cdecl FUN_0093cc20(float angle);
void __cdecl FUN_0093d030(void* object)
{
    Slot7MemberAccessor stored;
    bool exists;
    stored.FUN_0093d600(object,DAT_00e721b0);
    if (*stored.FUN_0093d640(&exists) && !*stored.FUN_0093d690(0))
    {
        Slot7MemberAccessor cone,planeMax,planeMin;
        cone.FUN_0093d600(object,DAT_00e6ce4c);
        planeMax.FUN_0093d600(object,DAT_00e6ce2c);
        planeMin.FUN_0093d600(object,DAT_00e6ce3c);
        if (*cone.FUN_0093d640(&exists) && *planeMax.FUN_0093d640(&exists) && *planeMin.FUN_0093d640(&exists))
        {
            *stored.FUN_0093d690(0)=true;
            float converted=FUN_008d3240(*cone.FUN_0093d6a0(0));
            *cone.FUN_0093d6a0(0)=converted;
            converted=FUN_0093cc20(*planeMax.FUN_0093d6a0(0));
            *planeMax.FUN_0093d6a0(0)=converted;
            converted=FUN_0093cc20(*planeMin.FUN_0093d6a0(0));
            *planeMin.FUN_0093d6a0(0)=converted;
        }
    }
}
}   // namespace f3m_0093d030

// @f3 0x0092c520 (community match, verified in this file)
extern int DAT_010f33e8;
namespace f3m_0092c520 {

struct Target0092c520 {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;

    void FUN_00555790(int value);
    void FUN_005b3880(unsigned short value, int* result);
};

struct __declspec(align(16)) Output0092c520 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
};

struct Owner0092c520 {
    void FUN_008f8bb0(Target0092c520* target);
    void FUN_0092c060(Output0092c520* out);
    void FUN_0092c520(Target0092c520* target);
};

int __cdecl FUN_00847b50(int value);

void Owner0092c520::FUN_0092c520(Target0092c520* target)
{
    FUN_008f8bb0(target);
    int result = FUN_00847b50(DAT_010f33e8);
    unsigned int index = target->unk0A;
    if (index >= target->unk08) {
        target->FUN_00555790(target->unk0E + index);
    }
    target->FUN_005b3880(index, &result);

    Output0092c520 out;
    out.unk30 = 0.5f;
    out.unk34 = 0.1f;
    out.unk00 = 0;
    out.unk04 = 0;
    out.unk1C = 0.0f;
    out.unk18 = 0.0f;
    out.unk14 = 0.0f;
    out.unk10 = 0.0f;
    out.unk2C = 0.0f;
    out.unk28 = 0.0f;
    out.unk24 = 0.0f;
    out.unk20 = 0.0f;
    FUN_0092c060(&out);
}
}   // namespace f3m_0092c520

// @f3 0x0093c340 (community match, verified in this file)
extern const char DAT_00e3fef0[], DAT_00e3fe78[], DAT_00e67078[], DAT_00e3ff4c[];
extern const char DAT_00e3fef8[], DAT_00e3ff40[], DAT_00e38554[];
namespace f3m_0093c340 {
namespace Layout520
{
struct Context
{
    void* FUN_0093d890();
};
struct __declspec(align(8)) View
{
    void* raw;
    Context* context;
    void FUN_0093d600(const View*, const char*);
    void FUN_0093d620(void*, void*, const char*);
    const bool* FUN_0093d640(bool*);
    void* FUN_0093d650();
    int* FUN_0093d6b0(int);
    signed char* FUN_0093d700(int);
    Context* FUN_0093d790();
};
void __cdecl FUN_0093c340(const View* destination, const View* source)
{
    View sourceFormat, destinationFormat, maxBitWidth, bitWidth, preserved, total, block, offset;
    sourceFormat.FUN_0093d600(source, DAT_00e3fef0);
    destinationFormat.FUN_0093d600(destination, DAT_00e3fef0);
    total.FUN_0093d600(source, DAT_00e3fe78);
    bool present;
    if (*sourceFormat.FUN_0093d640(&present) &&
        *destinationFormat.FUN_0093d640(&present) &&
        *total.FUN_0093d640(&present))
    {

        void* destinationMeta = destinationFormat.FUN_0093d790()->FUN_0093d890();
        bitWidth.FUN_0093d620(destinationFormat.FUN_0093d650(), destinationMeta, DAT_00e67078);
        void* sourceMeta = sourceFormat.FUN_0093d790()->FUN_0093d890();
        maxBitWidth.FUN_0093d620(sourceFormat.FUN_0093d650(), sourceMeta, DAT_00e3ff4c);
        if (*bitWidth.FUN_0093d640(&present) && *maxBitWidth.FUN_0093d640(&present))
        {
            signed char* width = bitWidth.FUN_0093d700(0);
            *maxBitWidth.FUN_0093d700(0) = *width;
        }

        block.FUN_0093d600(source, DAT_00e3fef8);
        preserved.FUN_0093d620(sourceFormat.FUN_0093d650(), sourceMeta, DAT_00e3ff40);
        int width = *preserved.FUN_0093d700(0) * 4;
        int kept = *preserved.FUN_0093d700(0);
        int rest = *block.FUN_0093d6b0(0) - kept;
        int packed = (*maxBitWidth.FUN_0093d700(0) * rest + 7) / 8 + width;
        offset.FUN_0093d620(sourceFormat.FUN_0093d650(), sourceMeta, DAT_00e38554);
        int multiplier = static_cast<const int*>(offset.FUN_0093d650())[1];
        *total.FUN_0093d6b0(0) = multiplier * packed;
    }
}
}


}   // namespace f3m_0093c340

// @f3 0x009243a0 (community match, verified in this file)
#include <math.h>
extern const double DAT_00dd1fa0;
namespace f3m_009243a0 {

struct __declspec(align(16)) Vector4F3
{
    float x, y, z, w;
};

float __cdecl FUN_008d3240(float cosine);

struct QuaternionF3
{
    Vector4F3 vec;

    void FUN_009243a0(const QuaternionF3& q0, const QuaternionF3& q1, float t);
};

// pdb: hkQuaternion::setSlerp | hkQuaternion.obj | fnv360_0822_retail, caller, medium
// pdb params: q0, q1, t
void QuaternionF3::FUN_009243a0(const QuaternionF3& q0, const QuaternionF3& q1, float t)
{
    float cosTheta = q0.vec.x * q1.vec.x + q0.vec.y * q1.vec.y + q0.vec.z * q1.vec.z + q0.vec.w * q1.vec.w;
    float sign = 1.0f;
    if (cosTheta < 0.0f)
    {
        cosTheta = -cosTheta;
        sign = -1.0f;
    }
    Vector4F3 slerp;
    if (cosTheta < DAT_00dd1fa0)
    {
        float theta = FUN_008d3240(cosTheta);
        float iSinTheta = 1.0f / sqrtf(1.0f - cosTheta * cosTheta);
        float tTheta = t * theta;
        float s0 = sinf(theta - tTheta) * iSinTheta;
        slerp.x = q0.vec.x * s0;
        slerp.y = s0 * q0.vec.y;
        slerp.z = q0.vec.z * s0;
        slerp.w = s0 * q0.vec.w;
        float s1 = sinf(tTheta) * iSinTheta;
        s1 = s1 * sign;
        slerp.x += q1.vec.x * s1;
        slerp.y += s1 * q1.vec.y;
        slerp.z += q1.vec.z * s1;
        slerp.w += s1 * q1.vec.w;
    }
    else
    {
        float s0 = 1.0f - t;
        slerp.x = q0.vec.x * s0;
        slerp.y = s0 * q0.vec.y;
        slerp.z = q0.vec.z * s0;
        slerp.w = s0 * q0.vec.w;
        float s1 = t * sign;
        slerp.x += q1.vec.x * s1;
        slerp.y += s1 * q1.vec.y;
        slerp.z += q1.vec.z * s1;
        slerp.w += s1 * q1.vec.w;
    }
    float lengthSquared = slerp.x * slerp.x + slerp.y * slerp.y + slerp.z * slerp.z + slerp.w * slerp.w;
    float inverse;
    if (lengthSquared != 0.0f)
        inverse = 1.0f / sqrtf(lengthSquared);
    else
        inverse = 0.0f;
    slerp.x = inverse * slerp.x;
    slerp.y = inverse * slerp.y;
    slerp.z = inverse * slerp.z;
    slerp.w = inverse * slerp.w;
    vec.x = slerp.x;
    vec.y = slerp.y;
    vec.z = slerp.z;
    vec.w = slerp.w;
}
}   // namespace f3m_009243a0

// @f3 0x00932ce0 (community match, verified in this file)
namespace f3m_00932ce0 {
namespace f3m_00932ce0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
struct IVec4 { int x, y, z, w; };
struct Transform { Vec4 col0; Vec4 col1; Vec4 col2; IVec4 translation; };
struct Rotation { Vec4 col0; Vec4 col1; Vec4 col2; };
struct __declspec(align(16)) Quat {
    IVec4 v;
    void FUN_00924360(const Rotation* r);
};
struct Member {
    void* object;
    const char* name;
    Member(void* obj, const char* name);
    IVec4* FUN_0093d720(int index);
    const Transform* FUN_0093d740(int index);
};
}

// pdb: GASMovieClipProto::GASMovieClipProto | GFxSprite.obj | tesv_win, ustr, medium
void __cdecl FUN_00932ce0(void* oldObject, void* newObject)
{
    using namespace f3m_00932ce0;
    Member transform(oldObject, "transform");
    Member translation(newObject, "translation");
    Member rotation(newObject, "rotation");
    *translation.FUN_0093d720(0) = transform.FUN_0093d740(0)->translation;
    const Transform* t = transform.FUN_0093d740(0);
    Rotation r;
    r.col0.set(t->col0.x, t->col1.x, t->col2.x, 0.0f);
    r.col1.set(t->col0.y, t->col1.y, t->col2.y, 0.0f);
    r.col2.set(t->col0.z, t->col1.z, t->col2.z, 0.0f);
    Quat q;
    q.FUN_00924360(&r);
    *rotation.FUN_0093d720(0) = q.v;
}
}   // namespace f3m_00932ce0

// @f3 0x00928050 (community match, verified in this file)
namespace f3m_00928050 {
typedef void* (__stdcall* TlsGetValue2352)(unsigned long slot);
extern TlsGetValue2352 DAT_00d9b080;
extern unsigned long DAT_010f3170;

struct Pair2352 { int first, second; };
struct Transform2352 { int x0,x4,x8,xc,x10,x14,x18,x1c; };

struct Allocator2352
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void* Allocate(unsigned int bytes) throw();
    virtual void ReleaseStack(void* memory) throw();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    char* current;
    int unk024;
    char* end;
    char* limit;
    void FUN_008f6d90(void* memory, unsigned int bytes, int tag) throw();
};

inline Allocator2352* ThreadAllocator2352() throw()
{
    return static_cast<Allocator2352*>(DAT_00d9b080(DAT_010f3170));
}

struct Local2352
{
    Pair2352* data;
    int count;
    int capacity;
    Pair2352* local;
    __forceinline Local2352(int size) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        Allocator2352* allocator = ThreadAllocator2352();
        unsigned int bytes = (size * 8 + 0x10) & ~0xf;
        char* memory = allocator->current;
        char* next = memory + bytes;
        if (next <= allocator->limit)
        {
            allocator->current = next;
            data = reinterpret_cast<Pair2352*>(memory);
        }
        else
            data = static_cast<Pair2352*>(allocator->Allocate(bytes));
        local = data;
        capacity = size | 0x80000000;
    }
    int GetCapacity() const { return capacity & 0x3fffffff; }
    __forceinline ~Local2352() throw()
    {
        TlsGetValue2352 getThread = DAT_00d9b080;
        Pair2352* memory = local;
        Allocator2352* allocator = static_cast<Allocator2352*>(getThread(DAT_010f3170));
        allocator->current = reinterpret_cast<char*>(memory);
        if (reinterpret_cast<char*>(memory) == allocator->end)
            allocator->ReleaseStack(memory);
        int cap = capacity;
        if ((cap & 0x80000000) == 0)
        {
            int count = GetCapacity();
            Allocator2352* heap = static_cast<Allocator2352*>(getThread(DAT_010f3170));
            heap->FUN_008f6d90(data, count * 8, 0x17);
        }
    }
};

struct Sub2352
{
    int shape, unk04, unk08, unk0c, unk10, unk14;
};

struct Entity2352
{
    int unk00,unk04,unk08,unk0c;
    Sub2352 sub;
    int unk28, unk2c;
    Transform2352 transform;
};

struct Query2352
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Query(int* shapeInfo, Transform2352* transform, Local2352* array) throw();
};
struct Dispatch2352
{
    void FUN_00984c50(Pair2352* data, int count, char* filter) throw();
};
struct World2352
{
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
    Query2352* query;
    Dispatch2352* dispatch;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    void* broadphase;
    char* filter;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int pairCapacity;
};
void __cdecl FUN_0099a2d0(void* broadphase, Entity2352** entities, int count) throw();

// pdb: hkpWorldOperationUtil::addEntityBP | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_addEntityBP(World2352* world, Entity2352* entity) throw()
{
    Sub2352* sub = &entity->sub;
    if (sub->shape)
    {
        Local2352 array(world->pairCapacity);
        FUN_0099a2d0(world->broadphase, &entity, 1);
        __declspec(align(16)) Transform2352 transform = entity->transform;
        world->query->Query(&sub->unk14, &transform, &array);
        if (array.count > 0)
            world->dispatch->FUN_00984c50(array.data, array.count, world->filter ? world->filter + 8 : 0);
    }
}
}   // namespace f3m_00928050

// @f3 0x00924fe0 (community match, verified in this file)
#include <math.h>
namespace f3m_00924fe0 {

class Trn {
public:
    char unk00[0x30];
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    unsigned char* FUN_00924fe0(unsigned char* out, const Trn* other, float eps);
    __forceinline bool InTol(const Trn* other, float eps);
};

extern unsigned char* __stdcall FUN_0096c5a0(unsigned char* flagOut, const Trn* other, float eps);

bool Trn::InTol(const Trn* other, float eps)
{
    __declspec(align(16)) float d[4];
    d[0] = unk30 - other->unk30;
    d[1] = unk34 - other->unk34;
    d[2] = unk38 - other->unk38;
    d[3] = unk3c - other->unk3c;
    d[0] = fabsf(d[0]);
    d[1] = fabsf(d[1]);
    d[2] = fabsf(d[2]);
    d[3] = fabsf(d[3]);
    unsigned int mask = (d[0] <= eps ? 8u : 0u) | (d[1] <= eps ? 4u : 0u)
                      | (d[2] <= eps ? 2u : 0u) | (d[3] <= eps ? 1u : 0u);
    return (mask & 0xEu) == 0xEu;
}

// pdb: hkTransform::isApproximatelyEqual | hkTransform.obj | tesv_win, objrun, medium
unsigned char* Trn::FUN_00924fe0(unsigned char* out, const Trn* other, float eps)
{
    unsigned char flag;
    unsigned char* ok = FUN_0096c5a0(&flag, other, eps);
    bool hit = *ok != 0 && InTol(other, eps);
    *out = hit;
    return out;
}
}   // namespace f3m_00924fe0

// @f3 0x009258b0 (community match, verified in this file)
namespace f3m_009258b0 {
struct __declspec(align(16)) V4_9258b0 {
    float x, y, z, w;
};

struct Inner_9258b0 {
    void FUN_008d2a80(const void* a, void* b);
};

struct S_9258b0 {
    char pad00[8];
    char* field8;
    char pad0c[0x30 - 0xc];

    void FUN_008fea60(float* p);
    float* FUN_009258b0(float* param);
};

// pdb: bhkRigidBodyT::GetCenterOfMassInWorld | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCOM
float* S_9258b0::FUN_009258b0(float* param)
{
    FUN_008fea60(param);

    V4_9258b0 tmp;
    if (this != 0 && field8 != 0) {
        ((Inner_9258b0*)&tmp)->FUN_008d2a80(field8 + 0xe0, (char*)this + 0x30);
        param[0] -= tmp.x;
        param[1] -= tmp.y;
        param[2] -= tmp.z;
        param[3] -= tmp.w;
    }
    return param;
}
}   // namespace f3m_009258b0

// @f3 0x00939fc0 (community match, verified in this file)
extern short DAT_0105f588;
namespace f3m_00939fc0 {
namespace f3m_00939fc0 {
struct __declspec(align(16)) RgTransform { float m[12]; };
struct RgMember;
struct RgPair { int a; int b; RgPair() {} inline RgMember M(const char* name); };
struct RgEnum { void FUN_009b2360(const char* name, int* out); };
struct RgClass { RgEnum* FUN_009b05d0(const char* name); };
struct RgVariant {
    void* object;
    RgClass* klass;
    RgVariant(void* obj);
    inline RgMember M(const char* name);
};
struct RgMember {
    void* unk00;
    int unk04;
    RgMember() {}
    RgMember(void* obj, const char* name);
    RgMember(RgVariant* v, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    char* FUN_0093d690(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
    RgTransform* FUN_0093d730(int index);
    void* FUN_0093d660();
    RgMember FUN_0093d7a0(const char* name);
    RgPair FUN_0093d810();
};
inline RgMember RgPair::M(const char* name) { return RgMember(this, name); }
inline RgMember RgVariant::M(const char* name) { return RgMember(this, name); }
struct RgTracker {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void AddChunk10(void*, int, int);
    virtual void PointedBy14(void*, void*);
};
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    RgMember f(obj, "type");
    short value = 0;
    if (name)
        value = *f.FUN_0093d6e0(0);
    return value;
}
static __declspec(noinline) void FUN_00937270(void* obj, char isEnabled, char firstFrictionAxis,
                                              char numFrictionAxes, float maxFrictionTorque)
{
    if (DAT_0105f588 == -1)
        DAT_0105f588 = FUN_00936710(obj, "TYPE_ANG_FRICTION");
    {
        RgMember type(obj, "type");
        *type.FUN_0093d6e0(0) = DAT_0105f588;
    }
    {
        RgMember enabled(obj, "isEnabled");
        *enabled.FUN_0093d710(0) = isEnabled;
    }
    {
        RgMember axis(obj, "firstFrictionAxis");
        *axis.FUN_0093d710(0) = firstFrictionAxis;
    }
    {
        RgMember axes(obj, "numFrictionAxes");
        *axes.FUN_0093d710(0) = numFrictionAxes;
    }
    {
        RgMember torque(obj, "maxFrictionTorque");
        *torque.FUN_0093d6a0(0) = maxFrictionTorque;
    }
}
void* volatile g_obj_rg;
volatile char g_a_rg, g_b_rg, g_c_rg;
volatile float g_f_rg;
inline RgPair RgMotors(RgMember& atoms) { return atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810(); }
inline int RgMotor(RgMember& atoms, int i)
{
    RgMember m = atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors");
    return *m.FUN_0093d670(i);
}
inline void RgFix(RgTracker* t, const RgMember& val, const RgMember& loc)
{
    t->PointedBy14((void*)*((RgMember&)val).FUN_0093d670(0), ((RgMember&)loc).FUN_0093d660());
}
inline void RgFixAt(RgTracker* t, const RgMember& val, int i, int* where)
{
    t->PointedBy14((void*)*((RgMember&)val).FUN_0093d670(i), where);
}
void __cdecl FUN_00937470(void* obj, char isEnabled, short a, short b, const RgTransform* frame, const int* motors);
void __cdecl FUN_00939770(void* oldObject, void* newObject, RgTracker* tracker);
}

void __cdecl FUN_00939fc0(void* oldObject, void* newObject, f3m_00939fc0::RgTracker* tracker)
{
    using namespace f3m_00939fc0;
    FUN_00939770(oldObject, newObject, tracker);
    RgMember atoms(newObject, "atoms");
    RgVariant newVariant(newObject);
    RgVariant oldVariant(oldObject);
    char active;
    {
    RgTransform frame;
    {
        RgMember f(&oldVariant, "targetFrameAinB");
        frame = *f.FUN_0093d730(0);
    }
    int motors[3];
    {
        int twist, plane, cone;
        newVariant.klass->FUN_009b05d0("MotorIndex")->FUN_009b2360("MOTOR_TWIST", &twist);
        newVariant.klass->FUN_009b05d0("MotorIndex")->FUN_009b2360("MOTOR_PLANE", &plane);
        newVariant.klass->FUN_009b05d0("MotorIndex")->FUN_009b2360("MOTOR_CONE", &cone);
        {
            RgMember m(&oldVariant, "twistMotor");
            motors[twist] = *m.FUN_0093d670(0);
        }
        {
            RgMember m(&oldVariant, "planeMotor");
            motors[plane] = *m.FUN_0093d670(0);
        }
        {
            RgMember m(&oldVariant, "coneMotor");
            motors[cone] = *m.FUN_0093d670(0);
        }
    }
    {
        RgMember am(&oldVariant, "motorsActive");
        active = *am.FUN_0093d690(0);
    }
    FUN_00937470(&atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810(), active, 0x60, 0x64, &frame, motors);
    }
    if (RgMotor(atoms, 0) != 0) {
        RgFix(tracker, atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors"), atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors"));
    }
    if (RgMotor(atoms, 1) != 0) {
    {
        int* where = (int*)atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors").FUN_0093d660();
        RgFixAt(tracker, atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors"), 1, where + 1);
    }
    }
    if (RgMotor(atoms, 2) != 0) {
    {
        int* where = (int*)atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors").FUN_0093d660();
        RgFixAt(tracker, atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().M("motors"), 2, where + 2);
    }
    }
    {
        RgMember m(&oldVariant, "maxFrictionTorque");
        FUN_00937270(&atoms.FUN_0093d7a0("angFriction").FUN_0093d810(), active == 0, 0, 3, *m.FUN_0093d6a0(0));
    }
}
}   // namespace f3m_00939fc0

// @f3 0x00925480 (community match, verified in this file)
namespace f3m_00925480 {
namespace f3m_00925480 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4() {}
    __forceinline Vec4(const Vec4& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};
struct __declspec(align(16)) Mat4 {
    Vec4 c0, c1, c2, c3;
    Mat4() {}
    __forceinline Mat4(const Mat4& o) : c0(o.c0), c1(o.c1), c2(o.c2), c3(o.c3) {}
    void hkTransform_setMul(const Mat4* m, int arg);
    void FUN_00925480(int arg);
};
// pdb: hkTransform::setMulEq | hkTransform.obj | fnv360_0822_debug, objrun, medium, conflict (bridge: hkpConvexTranslateShape::castRayWithCollectorImpl)
// pdb params: b
void Mat4::FUN_00925480(int arg)
{
    Mat4 a(*this);
    Mat4 b(a);
    hkTransform_setMul(&b, arg);
}
}
}   // namespace f3m_00925480

// @f3 0x009251b0 (community match, verified in this file)
namespace f3m_009251b0 {
namespace F3Transform2282 {
struct __declspec(align(16)) Vector {
    float x, y, z, w;
    Vector() {}
    Vector(const Vector& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    Vector& operator=(const Vector& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
    void add(const Vector& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
};
struct Matrix3 {
    Vector col[3];
};
struct Transform {
    Matrix3 rotation;
    Vector translation;
    void hkTransform_setMul(const Transform&, const Transform&);
};
// pdb: hkTransform::setMul | hkTransform.obj | fnv360_0822_debug, call_gap + skyrim(call_seq), high
void Transform::hkTransform_setMul(const Transform& left, const Transform& right)
{
    Vector r[3];
    r[0].x = left.rotation.col[0].x; r[0].y = left.rotation.col[0].y; r[0].z = left.rotation.col[0].z;
    r[1] = left.rotation.col[1];
    r[2] = left.rotation.col[2];
    Vector* out=(Vector*)&rotation;
    const Vector* in=(const Vector*)&right.rotation;
    int i=3;
    do {
        float x=in[i].x, y=in[i].y, z=in[i].z;
        out[i].x = r[0].x * x + r[1].x * y + r[2].x * z;
        out[i].y = r[0].y * x + r[1].y * y + r[2].y * z;
        out[i].z = r[0].z * x + r[1].z * y + r[2].z * z;
        out[i].w = 0.0f;
    } while (--i >= 0);
    translation.add(left.translation);
}
}
}   // namespace f3m_009251b0


// @f3 0x00921990 (community match, verified in this file)
#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_00921990 {
namespace f3m_00921990 {
struct Node {unsigned unk00;int id;unsigned unk08;Node* parent;
 Node* Root(){Node* n=this;while(n->parent)n=n->parent;return n;}
};
inline int Id(Node* n){return n?n->id:-1;}
inline Node* Parent(Node* n){return n?n->parent:0;}
struct Input {float a,b,c,d,e,f,g,h;Node* first;Node* second;};
struct Entry {float a,b,c,d,e,f,g,h;Node* firstRoot;int firstId;Node* secondRoot;int secondId;int ids[3];unsigned unk3c;};
struct Array {Entry* data;int size;unsigned capacityFlags;};
void __cdecl FUN_00901f10(Array*,unsigned);
struct Object {unsigned unk00,unk04,unk08,unk0c;Array entries;void FUN_00921990(Input*);};
// pdb: hkpAllCdPointCollector::addCdPoint | hkpAllCdPointCollector.obj | tesv_win, vtable, medium
void Object::FUN_00921990(Input* source){
 Array* array=&entries;
 if(array->size==(array->capacityFlags&0x3fffffff))FUN_00901f10(array,64);
 Entry* out=array->data+array->size++;
 out->a=source->a;out->b=source->b;out->c=source->c;out->d=source->d;
 out->e=source->e;out->f=source->f;out->g=source->g;out->h=source->h;
 out->firstRoot=source->first->Root();out->firstId=source->first->id;
 out->secondRoot=source->second->Root();out->secondId=source->second->id;
 Node* n=source->second;
 out->ids[0]=Id(n);n=Parent(n); _ReadWriteBarrier();
 out->ids[1]=Id(n);n=Parent(n); _ReadWriteBarrier();
 out->ids[2]=Id(n);
}
}

}   // namespace f3m_00921990

// @f3 0x00938e60 (community match, verified in this file)
#include <math.h>
extern short DAT_0105f5cc;
extern short DAT_0105f574;
extern short DAT_0105f558;
extern char DAT_00e39ef4[];
extern char DAT_00e6d124[];
extern char DAT_00e6d12c[];
extern char DAT_00e6d134[];
extern char DAT_00e6d140[];
extern char DAT_00e6d14c[];
extern char DAT_00e38008[];
extern char DAT_00e3fe50[];
extern char DAT_00e39ee0[];
extern char DAT_00e39efc[];
extern char DAT_00e3a95c[];
extern char DAT_00e3a9cc[];
extern char DAT_00e3ff58[];
namespace f3m_00938e60 {
// FUN_00938e60: Havok version-update routine for the legacy hinge constraint data.
// Reads basisA.{perpToAxle1,perpToAxle2,pivot} and basisB.{axle,pivot} from the old object,
// builds two transforms and writes the "transforms", "2dAng" and "ballSocket" atoms.


namespace n938e60 {

inline float hkFabs(float r) { return fabsf(r); }
__forceinline float hkSqrt(float r) { return (float)sqrt(r); }
__forceinline float hkSqrtInverse(float r) { return 1.0f / hkSqrt(r); }

__declspec(align(16)) struct hkVector4
{
    float x, y, z, w;
    hkVector4() {}
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d = 0.0f) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b)
    {
        const float nx = a.y * b.z - a.z * b.y;
        const float ny = a.z * b.x - a.x * b.z;
        const float nz = a.x * b.y - a.y * b.x;
        set(nx, ny, nz);
    }
    __forceinline void mul4(const float& s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline float lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        return l2 != 0.0f ? hkSqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};

struct hkRotation
{
    hkVector4 m_col0, m_col1, m_col2;
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    __forceinline hkRotation& getRotation() { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }
};

__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;
    float a0 = hkFabs(vectorIn(0));
    float a1 = hkFabs(vectorIn(1));
    float a2 = hkFabs(vectorIn(2));
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

struct hkVariant
{
    void* object;
    void* klass;
};

struct FUN_0093d7f0
{
    void* unk00;
    void* unk04;
    FUN_0093d7f0(void* variant);
};

struct FUN_0093d600
{
    void* unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    hkVector4* FUN_0093d720(int index);
    FUN_0093d600 FUN_0093d7a0(const char* name);
    hkVariant FUN_0093d810();
    hkVariant* FUN_0093d810(hkVariant* out);
};

short __cdecl FUN_00936690(FUN_0093d600* acc);
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
void __cdecl FUN_009367e0(void* obj, const hkTransform* a, const hkTransform* b);

static __declspec(noinline) short FUN_009366b0(FUN_0093d600* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936e40(void* obj, char value)
{
    if (DAT_0105f574 == -1)
        DAT_0105f574 = FUN_00936710(obj, DAT_00e3a95c);
    {
        FUN_0093d600 type(obj, DAT_00e3ff58);
        *type.FUN_0093d6e0(0) = DAT_0105f574;
    }
    {
        FUN_0093d600 axis(obj, "freeRotationAxis");
        *axis.FUN_0093d710(0) = value;
    }
}
static __declspec(noinline) void FUN_009369f0(void* obj)
{
    if (DAT_0105f558 == -1)
        DAT_0105f558 = FUN_00936710(obj, DAT_00e3a9cc);
    FUN_0093d600 type(obj, DAT_00e3ff58);
    *type.FUN_0093d6e0(0) = DAT_0105f558;
}

}
using namespace n938e60;

void __cdecl FUN_00938e60(void* oldObj, void* newObj)
{
    FUN_0093d600 atoms(newObj, DAT_00e39ef4);
    FUN_0093d7f0 old(oldObj);
    if (DAT_0105f5cc == -1)
        DAT_0105f5cc = FUN_009366b0(&atoms);

    hkTransform tA;
    hkTransform tB;
    {
        hkVariant basis;
        { FUN_0093d600 f(&old, DAT_00e6d12c); f.FUN_0093d810(&basis); }
        hkVector4 perp2;
        hkVector4 perp1;
        { FUN_0093d600 f(&basis, DAT_00e6d140); perp1 = *f.FUN_0093d720(0); }
        { FUN_0093d600 f(&basis, DAT_00e6d134); perp2 = *f.FUN_0093d720(0); }
        hkVector4 pivot;
        { FUN_0093d600 f(&basis, DAT_00e6d14c); pivot = *f.FUN_0093d720(0); }
        hkVector4 c;
        c.setCross(perp1, perp2);
        tA.m_rotation.m_col0 = c;
        tA.m_rotation.m_col1.set(perp1.x, perp1.y, perp1.z, perp1.w);
        tA.m_rotation.m_col2.set(perp2.x, perp2.y, perp2.z, perp2.w);
        tA.getTranslation() = pivot;
    }
    {
        hkVariant basis;
        { FUN_0093d600 f(&old, DAT_00e6d124); f.FUN_0093d810(&basis); }
        hkVector4 tmp;
        { FUN_0093d600 f(&basis, DAT_00e38008); tmp = *f.FUN_0093d720(0); }
        hkVector4 axle(tmp);
        hkVector4 pivot;
        { FUN_0093d600 f(&basis, DAT_00e6d14c); pivot = *f.FUN_0093d720(0); }
        tB.getRotation().getColumn(0) = tmp;
        calculatePerpendicularVector(axle, tB.getRotation().getColumn(1));
        tB.getRotation().getColumn(1).normalize3();
        tB.getRotation().getColumn(2).setCross(tmp, tB.getRotation().getColumn(1));
        tB.getTranslation() = pivot;
    }
    FUN_009367e0(&atoms.FUN_0093d7a0(DAT_00e3fe50).FUN_0093d810(), &tA, &tB);
    FUN_00936e40(&atoms.FUN_0093d7a0(DAT_00e39ee0).FUN_0093d810(), 0);
    FUN_009369f0(&atoms.FUN_0093d7a0(DAT_00e39efc).FUN_0093d810());
}
}   // namespace f3m_00938e60

// @f3 0x0092dd80 (community match, verified in this file)
#include <math.h>
namespace f3m_0092dd80 {

namespace f3m_0092dd80 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

__forceinline float Abs(float r) { return (float)fabs(r); }

struct Listener {
    int unk00;
    int unk04;
    int unk08;
    void FUN_0090b500();
};

struct Tracker {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Listener* listener;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Vec4 position;
    void FUN_0092dd80(const Vec4* v);
};

// pdb: hkpMouseSpringAction::setMousePosition | hkpMouseSpringAction.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: mousePositionInWorld
void Tracker::FUN_0092dd80(const Vec4* v)
{
    Vec4 d;
    d.x = v->x - position.x;
    d.y = v->y - position.y;
    d.z = v->z - position.z;
    d.w = v->w - position.w;
    d.x = Abs(d.x);
    d.y = Abs(d.y);
    d.z = Abs(d.z);
    d.w = Abs(d.w);
    int mask = (d.x <= 0.001f ? 8 : 0) | (d.y <= 0.001f ? 4 : 0) | (d.z <= 0.001f ? 2 : 0) | (d.w <= 0.001f ? 1 : 0);
    if ((mask & 0xe) != 0xe && listener && listener->unk08)
        listener->FUN_0090b500();
    position.x = v->x;
    position.y = v->y;
    position.z = v->z;
    position.w = v->w;
}

}
}   // namespace f3m_0092dd80

// @f3 0x00925e70 (community match, verified in this file)
namespace f3m_00925e70 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct FUN_0082ea60;
typedef FUN_0082ea60 Body;

struct InitArgs
{
    float time;
    char flag0, flag1, flag2, flag3, flag4;
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};

struct NiPoint3
{
    float x, y, z;
};

struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

struct __declspec(align(16)) Vec4 { float x,y,z,w; Vec4& operator=(const Vec4& r){x=r.x;y=r.y;z=r.z;w=r.w;return *this;} };

struct Rot
{
    Vec4 rows[3];
    void hkRotation_set(const void* src);
};

struct HavokTransform
{
    Rot basis;
    Vec4 position;
};

extern const double DAT_00db88e8;

inline void ConvertTranslation(NiPoint3* out, const Vec4* in){out->x=(float)(in->x*DAT_00db88e8);out->y=(float)(in->y*DAT_00db88e8);out->z=(float)(in->z*DAT_00db88e8);}

struct StringHeader
{
    volatile long refs;
    unsigned int length;
};

extern StringHeader* DAT_00e207a8;

extern const char DAT_00e3225c[];

StringHeader* __cdecl FUN_008242a0(const char*);
void* __cdecl FUN_0089eb90(unsigned int);
__declspec(noalias) void __cdecl FUN_0056ac90(void*, void*);

struct FixedString
{
    StringHeader* value;
    FixedString(const char* s) : value(FUN_008242a0(s))
    {}
    ~FixedString()
    {
        if (value != DAT_00e207a8)
            InterlockedDecrement(&(value - 1)->refs);
    }
};

struct BSFadeNode
{
    static void* operator new(unsigned int n);
    static void operator delete(void* p, unsigned int size);
    unsigned int unk00;
};

void* BSFadeNode::operator new(unsigned int n){return FUN_0089eb90(n);}

struct FUN_0082ea60 : BSFadeNode
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    ThreeByThreeMatrix f34;
    NiPoint3 position;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    FUN_0082ea60(int);
    void FUN_008264c0(InitArgs&);
    void FUN_008245d0(const FixedString&);
};

struct ArgObj
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void Vdc(Body*, int);
    int f4;
    void* f8;
};

struct Owner
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    Vec4 rotation;
    Vec4 vec30;
    void FUN_008feb20(Body*);
    void FUN_00925e70(ArgObj* arg);
};

// pdb: bhkRigidBodyT::CreateDisplayGeometry | bhkRigidBodyT.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: apNode
void Owner::FUN_00925e70(ArgObj* arg)
{
    Body* body = 0;
    if (arg)
    {
        if (arg->f8 == 0)
            body = (Body*)arg;
        else
        {
            body = new Body(0);
            arg->Vdc(body, 1);
            InitArgs ia;
            ia.time = 0.0f;
            ia.flag0 = 0;
            ia.flag1 = 0;
            ia.flag2 = 0;
            ia.flag3 = 0;
            ia.flag4 = 0;
            body->FUN_008264c0(ia);
        }
    }
    else
        body = new Body(0);

    {
        FixedString nameStr(DAT_00e3225c);
        body->FUN_008245d0(nameStr);
    }
    HavokTransform hk;
    hk.basis.hkRotation_set(&rotation);
    hk.position = vec30;
    NiTransform t;
    FUN_0056ac90(&t.m_kOrientation, &hk.basis);
    ConvertTranslation(&t.m_kTranslation, &hk.position);
    body->f34 = t.m_kOrientation;
    body->position = t.m_kTranslation;
    FUN_008feb20(body);
}
}   // namespace f3m_00925e70

// @f3 0x00921660 (community match, verified in this file)
extern double DAT_00dc0ac8;
extern double DAT_00dc2d10;
namespace f3m_00921660 {
struct __declspec(align(16)) S00921660_Vec
{
    float x;
    float y;
    float z;
    float w;
    void setSub4(const S00921660_Vec& a, const S00921660_Vec& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    void setZero4() { x = y = z = w = 0.0f; }
    float dot3(const S00921660_Vec& o) const { return x * o.x + y * o.y + z * o.z; }
};

struct S00921660_Pt3
{
    float x;
    float y;
    float z;
    S00921660_Pt3(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
    float SqrLength() const { return x * x + y * y + z * z; }
};

struct S00921660_Child
{
    __declspec(noalias) void FUN_00917120(const S00921660_Vec* p, S00921660_Vec* out);
};

struct S00921660_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    short unk12;
    int unk14;
    char unk18;
    S00921660_Child* getChild() { return (S00921660_Child*)((char*)this + unk10); }
};

struct S00921660_Body
{
    S00921660_Vec unk00;
    S00921660_Vec unk10;
    float unk20;
    float unk24;
    S00921660_Shape* unk28;
};

struct S00921660_Cls
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
    float unk60;
    float hkpCharacterProxy_surfaceDistance(S00921660_Body* a, S00921660_Body* b);
};


// pdb: hkpCharacterProxy::surfaceDistance | hkpCharacterProxy.obj | fnv360_0822_debug, call_seq + skyrim(call_gap_sim), high
float S00921660_Cls::hkpCharacterProxy_surfaceDistance(S00921660_Body* a, S00921660_Body* b)
{
    S00921660_Shape* sa = a->unk28;
    float dot = a->unk10.dot3(b->unk10);
    float t = 1.0f - dot;
    float c = unk60 * unk60 * t;
    float dw = a->unk10.w - b->unk10.w;
    dw = dw * dw;

    S00921660_Vec posA;
    posA.x = posA.y = posA.z = posA.w = 0.0f;
    if (sa->unk18 == 1)
    {
        S00921660_Child* rigidBodyA = sa->getChild();
        if (rigidBodyA)
            rigidBodyA->FUN_00917120(&a->unk00, &posA);
    }

    S00921660_Vec posB;
    posB.x = posB.y = posB.z = posB.w = 0.0f;
    S00921660_Shape* sb = b->unk28;
    if (sb->unk18 == 1)
    {
        S00921660_Child* rigidBodyB = sb->getChild();
        if (rigidBodyB)
            rigidBodyB->FUN_00917120(&b->unk00, &posB);
    }

    S00921660_Vec d;
    d.x = posA.x - posB.x;
    d.y = posA.y - posB.y;
    d.z = posA.z - posB.z;
    float dist = d.dot3(d);
    float r = dist * DAT_00dc0ac8 + c * DAT_00dc2d10 + dw;
    return r;
}
}   // namespace f3m_00921660

// @f3 0x009215d0 (community match, verified in this file)
extern const float DAT_00de6e60;
extern unsigned long DAT_010f3170;
namespace f3m_009215d0 {


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index) throw();

struct ThreadMemory {
    void FUN_008f6d90(void* p, int size, int tag);
};

struct RootPoint { float x00,x04,x08,x0c,x10,x14,x18,x1c,x20,x24,x28,x2c,x30,x34,x38,x3c; };

inline ThreadMemory& GetThreadMemory() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }

struct __declspec(novtable) hkpCdPointCollector {
    float earlyOut;

    hkpCdPointCollector() { Reset(); }
    void Reset() { earlyOut = DAT_00de6e60; }
    virtual ~hkpCdPointCollector() {}
    virtual void Add() = 0;
};

struct __declspec(align(16)) Hits {
    RootPoint* data;
    int size;
    int capacity;
    int unkC;
    __declspec(align(16)) RootPoint storage[8];

    Hits() : data((RootPoint*)storage), size(0), capacity(0x80000008) {}
    ~Hits() {
        if ((capacity & 0x80000000) == 0) {
            int n = capacity & 0x3fffffff;
            unsigned long k = DAT_010f3170; ThreadMemory* m = (ThreadMemory*)TlsGetValue(k);
            m->FUN_008f6d90(data, n * sizeof(RootPoint), 0x17);
        }
    }
};

struct hkpAllCdPointCollector : hkpCdPointCollector {
    Hits hits;

    hkpAllCdPointCollector() { Reset(); }
    void Reset() { hits.size = 0; hkpCdPointCollector::Reset(); }
    virtual ~hkpAllCdPointCollector() {}
    virtual void Add();
};

struct QueryOwner {
 void FUN_0091fe80(const void* a,const void* b,hkpCdPointCollector& c) throw();
 void FUN_009215d0(const void* a,const void* b);
};

// pdb: bhkCharacterProxy::CheckSupport | bhkCharacterController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arDirection, arGround
void QueryOwner::FUN_009215d0(const void* a, const void* b) {
    hkpAllCdPointCollector c;
    FUN_0091fe80(a, b, c);
}

}   // namespace f3m_009215d0

// @f3 0x00925cd0 (community match, verified in this file)
namespace f3m_00925cd0 {
// Four-float vector of the x87 build (16-byte aligned).
struct __declspec(align(16)) V4 {
    float x, y, z, w;
    void setCross(const V4& a, const V4& b) {
        x = a.y * b.z - a.z * b.y;
        y = a.z * b.x - a.x * b.z;
        z = a.x * b.y - a.y * b.x;
        w = 0.0f;
    }
    void FUN_008d3290(const V4& a, const V4& b);
    void FUN_004e5c20();
};

class Cls {
public:
    int unk00; int unk04; void* unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    V4 m_v20;
    V4 m_q30;
    void FUN_008fe9f0(V4* a, V4* b);
    void FUN_00925cd0(V4& out, V4& in);
};

// Rotates the vector at +0x30 by the rotation `in` (x,y,z,w), adds `out`, combines `in` with the
// vector at +0x20, normalises that and hands both results to FUN_008fe9f0.
// pdb: bhkRigidBodyT::SetPosRot | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: arPos, arRot
void Cls::FUN_00925cd0(V4& out, V4& in)
{
    // Fake match: `imag` is a second name for `in`, declared before `w` and `q` and used only for
    // the dot and the cross product, and the dot reads m_q30 directly instead of through `q`.
    // Both only steer which operand of each lane product the compiler loads first (+5f and +8e).
    const V4& imag = in;
    float w = in.w;
    const V4& q = m_q30;
    float t = w * w - 0.5;
    V4 A;
    A.x = q.x * t;
    A.y = q.y * t;
    A.z = q.z * t;
    A.w = q.w * t;
    float dot = m_q30.x * imag.x + m_q30.y * imag.y + m_q30.z * imag.z;
    A.x = A.x + in.x * dot;
    A.y = A.y + in.y * dot;
    A.z = A.z + in.z * dot;
    A.w = A.w + in.w * dot;
    V4 B;
    B.setCross(imag, q);
    A.x = A.x + w * B.x;
    A.y = A.y + w * B.y;
    A.z = A.z + w * B.z;
    A.w = A.w + w * 0.0;
    B.x = A.x + A.x;
    B.y = A.y + A.y;
    B.z = A.z + A.z;
    B.w = A.w + A.w;
    B.x = B.x + out.x;
    B.y = B.y + out.y;
    B.z = B.z + out.z;
    B.w = B.w + out.w;
    A.FUN_008d3290(in, m_v20);
    A.FUN_004e5c20();
    FUN_008fe9f0(&B, &A);
}
}   // namespace f3m_00925cd0

// @f3 0x00927010 (community match, verified in this file)
namespace f3m_00927010 {
namespace n927010 {
struct Pool1884 { void* FUN_008f6d30(unsigned int,int); };
extern unsigned int DAT_010f3170;
extern Pool1884* (__stdcall* const DAT_00d9b080)(unsigned int);
struct S00cb4230_Vec4
{
    float& operator()(int a)
    {
        return reinterpret_cast<float*>(m_vComponents)[a];
    }
    const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(m_vComponents)[a];
    }
    __declspec(align(16)) float m_vComponents[4];
};
struct S00cb4230_Quat
{
    S00cb4230_Quat()
    {}
    S00cb4230_Vec4 m_vec;
};
struct InertiaTensor
{
    InertiaTensor()
    {}
    S00cb4230_Vec4 m_kColumn0;
    S00cb4230_Vec4 m_kColumn1;
    S00cb4230_Vec4 m_kColumn2;
};
struct S00cb4230_Rotation : InertiaTensor
{
    S00cb4230_Rotation()
    {}
};
struct S00cb4230_Transform
{
    S00cb4230_Transform()
    {}
    S00cb4230_Rotation m_rotation;
    S00cb4230_Vec4 m_vTranslation;
    const S00cb4230_Vec4& getTranslation() const
    {
        return m_vTranslation;
    }
};
struct S00cb4230_Swept
{
    S00cb4230_Swept()
    {}
    float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
    float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    S00cb4230_Vec4 m_vCenterOfMass0;
    S00cb4230_Vec4 m_vCenterOfMass1;
    S00cb4230_Quat m_qRotation0;
    S00cb4230_Quat m_qRotation1;
    S00cb4230_Vec4 m_vCenterOfMassLocal;
};
extern float DAT_00e35180[];
struct S00cb4230_UFloat8
{
    S00cb4230_UFloat8()
    {}
    operator float() const
    {
        return DAT_00e35180[m_uiFilterValue];
    }
    unsigned char m_uiFilterValue;
};
struct S00cb4230_MotionStateData
{
    S00cb4230_MotionStateData()
    {}
    S00cb4230_Transform& getTransform()
    {
        return m_kMotionTransform;
    }
    const S00cb4230_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
    S00cb4230_Swept& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    const S00cb4230_Swept& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    void FUN_008f8720(void* p);
    S00cb4230_Transform m_kMotionTransform;
    S00cb4230_Swept m_kSweptTransform;
    S00cb4230_Vec4 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    S00cb4230_UFloat8 m_fSurfaceFriction;
    S00cb4230_UFloat8 m_fRestitution;
    short m_uiDeactivationClass;
};
struct MotionFlag31
{
    inline MotionFlag31()
    {}
    inline MotionFlag31(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline MotionFlag31 operator==(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) == static_cast<int>(e);
    }
    inline MotionFlag31 operator!=(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) != static_cast<int>(e);
    }

  private:
    char m_cBooleanValue;
};
enum S00cb4230_MotionType
{
    S00cb4230_INVALID,
    S00cb4230_DYNAMIC,
    S00cb4230_SPHERE,
    S00cb4230_BOX,
    S00cb4230_KEYFRAMED,
    S00cb4230_FIXED = 7
};
template <typename E, typename S> struct S00cb4230_Enum
{
    S00cb4230_Enum()
    {}
    S00cb4230_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    S m_kStorage;
};
struct MotionState;
struct S00cb4230_FinishFlag
{
    S00cb4230_FinishFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
struct S00cb4230_Half
{
    S00cb4230_Half()
    {}
    void operator=(const float& f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = short(t >> 16);
    }
    short m_uiFilterValue;
};
struct S00cb4230_BaseObject
{
    S00cb4230_BaseObject()
    {}
    virtual void v00(int);
};
struct RefHeader31 : S00cb4230_BaseObject
{
    RefHeader31(S00cb4230_FinishFlag flag)
    { m_06 = 1; }
    unsigned short m_04;
    mutable short m_06;
};
struct MotionBase : RefHeader31
{
    MotionBase(S00cb4230_FinishFlag flag) : RefHeader31(flag)
    {
        if (flag.m_bFinishing)
        {
            m_fGravityFactor = 1.f;
        }
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void GetInverseScaleMatrix(InertiaTensor& out) const;
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v25(MotionState* p);
    virtual void v26();
    virtual void v27(MotionState* p);
    S00cb4230_MotionType getType() const
    {
        return m_type;
    }
    S00cb4230_MotionStateData* GetMotionState()
    {
        return &m_kMotionState;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return m_kMotionState.getTransform().getTranslation();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return m_kMotionState.getSweptTransform().m_qRotation1;
    }
    const S00cb4230_Vec4& getCenterOfMassLocal() const
    {
        return m_kMotionState.getSweptTransform().m_vCenterOfMassLocal;
    }
    float getLinearDamping()
    {
        return m_kMotionState.m_fLinearDamping;
    }
    float getAngularDamping()
    {
        return m_kMotionState.m_fAngularDamping;
    }
    void setLinearDamping(float d)
    {
        m_kMotionState.m_fLinearDamping = d;
    }
    void setAngularDamping(float d)
    {
        m_kMotionState.m_fAngularDamping = d;
    }
    S00cb4230_Enum<S00cb4230_MotionType, unsigned char> m_type;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_MotionStateData m_kMotionState;
    S00cb4230_Vec4 m_kInertiaAndMassInv;
    S00cb4230_Vec4 m_kTranslationalVelocity;
    S00cb4230_Vec4 m_kAngularVelocity;
    S00cb4230_Vec4 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    MotionState* m_118;
    short m_11c;
    S00cb4230_Half m_fGravityFactor;
    void FUN_00c905b0() { if (m_04 && --m_06 == 0) v00(1); }
    void FUN_0099d300();
    void FUN_00902180(int a, int b, int c);
    void FUN_008f8620(MotionBase* p);
    float FUN_008f8410();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        Pool1884* pool = DAT_00d9b080(DAT_010f3170);
        RefHeader31* b = static_cast<RefHeader31*>(pool->FUN_008f6d30(nbytes, 0x2e));
        b->m_04 = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct FUN_0099d2a0 : MotionBase
{
    FUN_0099d2a0() : MotionBase(S00cb4230_FinishFlag())
    {
        m_118 = 0;
    }
    FUN_0099d2a0(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct MotionState : FUN_0099d2a0
{
    MotionState() : FUN_0099d2a0()
    {}
};
struct FUN_0099e130 : MotionBase
{
    FUN_0099e130(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct S00cb4230_String
{
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
        unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
        {
            do
            {
                dst32[0] = src32[0];
                dst32[1] = src32[1];
                dst32[2] = src32[2];
                dst32[3] = src32[3];
                dst32 += 4;
                src32 += 4;
            } while (--numQuads > 0);
        }
    }
};
enum S00cb4230_Quality
{
    S00cb4230_QUALITY_FIXED = 1,
    S00cb4230_QUALITY_KEYFRAMED
};
struct S00cb4230_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    short m_ucObjectQualityType;
    int m_iFilter;
};
struct S00cb4230_Collidable
{
    const void* getShape() const
    {
        return m_pCollisionShape;
    }
    S00cb4230_Handle* getBroadPhaseHandle()
    {
        return &m_kBroadPhaseHandle;
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(m_kBroadPhaseHandle.m_ucObjectQualityType);
    }
    void setMotionState(const S00cb4230_MotionStateData* s)
    {
        m_pMotionState = s;
    }
    const void* m_pCollisionShape;
    int m_14;
    const void* m_pMotionState;
    int m_1c;
    int m_20;
    S00cb4230_Handle m_kBroadPhaseHandle;
};
struct ThisObj
{
    int m_00;
    int m_04;
    unsigned char m_08;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_Collidable m_kCollidable;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    float m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    unsigned char m_bc;
    unsigned char m_bd;
    short m_be;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    MotionState m_pMotionState;
    int m_200;
    int m_204;
    MotionBase* getMotion()
    {
        return &m_pMotionState;
    }
    MotionBase* getRigidMotion() const
    {
        return const_cast<MotionBase*>(static_cast<const MotionBase*>(&m_pMotionState));
    }
    const S00cb4230_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    S00cb4230_Collidable* getCollidableRw()
    {
        return &m_kCollidable;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(getCollidable()->getQualityType());
    }
    void setQualityType(S00cb4230_Quality type)
    {
        getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType = short(type);
    }
    void FUN_0090b280(void* a, const void* b);
};
struct Node4
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    char m_2c4;
    char m_2c5;
    char m_2c6;
    char m_2c7;
    float FUN_009022d0();
};
void __cdecl FUN_00923500(void* p, int a, int b);
template <typename T> __forceinline T* __cdecl S00cb4230_AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
void __cdecl FUN_0090c9b0(int mode, const S00cb4230_Vec4* p40, const S00cb4230_Quat* p80, float fret,
                          const InertiaTensor* out, const S00cb4230_Vec4* p90, float f0, float f1, MotionBase* motion);
void __cdecl hkSweptTransformUtil_freezeMotionState(float f, S00cb4230_MotionStateData* p);


// pdb: hkpWorldOperationUtil::replaceMotionObject | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_replaceMotionObject(ThisObj* self, S00cb4230_MotionType mode, MotionFlag31 flagA, MotionFlag31 flagB, Node4* node)
{
    if (flagA)
    {
        if (!flagB)
        {
            MotionBase* motion = self->getMotion();
            MotionState* pState = motion->m_118;
            motion->v25(pState);
            pState->m_0a = 0;
            pState->m_0c = 0;
            self->setQualityType(S00cb4230_Quality(motion->m_11c));
            S00cb4230_String::memCpy16NonEmpty(&self->m_pMotionState, pState, sizeof(MotionState) >> 4);
            FUN_00923500(S00cb4230_AddByteOffset(&self->m_pMotionState, sizeof(MotionState)), 0, 0);
            pState->FUN_00c905b0();
            self->FUN_0090b280(node, self->getCollidable()->getShape());
        }

        if (self->m_pMotionState.getType() == mode || mode == S00cb4230_DYNAMIC)
        {
        }
        else
        {
            MotionState localState;
            S00cb4230_String::memCpy16NonEmpty(&localState, &self->m_pMotionState, sizeof(MotionState) >> 4);
            InertiaTensor inertiaTensor;
            MotionBase* pMotionBase = &self->m_pMotionState;
            pMotionBase->GetInverseScaleMatrix(inertiaTensor);
            S00cb4230_MotionStateData* pStateData = localState.GetMotionState();
            float fRestitution = pStateData->m_fRestitution;
            float j = pStateData->m_fSurfaceFriction;
            FUN_0090c9b0(mode, &localState.getPosition(), &localState.getRotation(), localState.FUN_008f8410(),
                         &inertiaTensor, &localState.getCenterOfMassLocal(), j, fRestitution, &self->m_pMotionState);
            localState.FUN_008f8620(pMotionBase);
            pMotionBase->setLinearDamping(localState.getLinearDamping());
            pMotionBase->setAngularDamping(localState.getAngularDamping());
            localState.FUN_0099d300();
            goto e0;
        }
    }
    else
    {
        MotionBase* pObj;
        MotionState localState;
        S00cb4230_String::memCpy16NonEmpty(&localState, &self->m_pMotionState, sizeof(MotionState) >> 4);
        if (mode == S00cb4230_FIXED)
        {
            pObj = new (&self->m_pMotionState) FUN_0099e130(self->getPosition(), self->getRotation());
            pObj->m_kMotionState.FUN_008f8720(&localState.m_kMotionState);
            pObj->m_09 = localState.m_09;
            float c = localState.GetMotionState()->getSweptTransform().getInvDeltaTime();
            if (c != 0.0f)
            {
                hkSweptTransformUtil_freezeMotionState(node ? node->FUN_009022d0()
                                                 : 1.0f / c +
                                                       localState.GetMotionState()->getSweptTransform().getBaseTime(),
                                            &pObj->m_kMotionState);
            }
        }
        else
        {
            pObj = new (&self->m_pMotionState) FUN_0099d2a0(self->getPosition(), self->getRotation());
            localState.FUN_008f8620(pObj);
        }

        if (flagB)
        {
            MotionState* cnt = new MotionState();
            unsigned short GetAllocationSize = cnt->m_04;
            S00cb4230_String::memCpy16NonEmpty(cnt, &localState, sizeof(MotionState) >> 4);
            cnt->m_04 = GetAllocationSize;
            cnt->m_06 = 1;
            pObj->m_118 = cnt;
            pObj->m_11c = (short)self->getCollidable()->getQualityType();
            self->FUN_0090b280(node, self->getCollidable()->getShape());
        }
        else
        {
            pObj->v27(localState.m_118);
            pObj->m_11c = localState.m_11c;
        }
        self->m_90 = 0;
        self->setQualityType(mode == S00cb4230_FIXED ? S00cb4230_QUALITY_FIXED : S00cb4230_QUALITY_KEYFRAMED);
        localState.FUN_0099d300();
    }
e0:
    self->m_kCollidable.setMotionState(self->getRigidMotion()->GetMotionState());
    if ((bool)node)
    {
        self->getMotion()->FUN_00902180((unsigned char)node->m_2c5, (unsigned char)node->m_2c6,
                                       (unsigned char)node->m_2c7);
    }
}

}


}   // namespace f3m_00927010

// @f3 0x00925300 (community match, verified in this file)
namespace f3m_00925300 {
namespace N925300 {

typedef float hkReal;
struct hkRotation;

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
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
};

struct hkRotation : hkMatrix3
{
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

__forceinline void rotateInversePoints(const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkRotation unaliased;
    // Fake match: dead store to one lane of the local rotation copy before it is filled. It only steers x87
    // operand order: the loop's first dot product then multiplies this lane from memory, as the original does.
    unaliased.m_col0.z = 0.0f;
    unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setRotatedInverseDir(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline hkRotation& getRotation() { return m_rotation; }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    void FUN_00925300(const hkTransform& bTa, const hkTransform& bTc);
};

// pdb: hkTransform::setInverse | hkTransform.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkTransform::setMulInverseMul)
// pdb params: t
void hkTransform::FUN_00925300(const hkTransform& bTa, const hkTransform& bTc)
{
    rotateInversePoints(bTa.getRotation(), &bTc.getRotation().getColumn(0), 3, &getRotation().getColumn(0));
    hkVector4 h;
    h.setSub4(bTc.m_translation, bTa.m_translation);
    m_translation._setRotatedInverseDir(bTa.m_rotation, h);
}

}
}   // namespace f3m_00925300

// @f3 0x0092bbe0 (community match, verified in this file)
namespace f3m_0092bbe0 {
namespace f3m_0092bbe0 {
typedef float hkReal;
struct __declspec(align(16)) hkVector4 {
    hkReal m_quad[4];
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { m_quad[0] = v.m_quad[0]; m_quad[1] = v.m_quad[1]; m_quad[2] = v.m_quad[2]; m_quad[3] = v.m_quad[3]; }
    __forceinline void operator=(const hkVector4& v) { m_quad[0] = v.m_quad[0]; m_quad[1] = v.m_quad[1]; m_quad[2] = v.m_quad[2]; m_quad[3] = v.m_quad[3]; }
    __forceinline void mul4(hkReal s) { m_quad[0] *= s; m_quad[1] *= s; m_quad[2] *= s; m_quad[3] *= s; }
    __forceinline void setMul4(hkReal r, const hkVector4& v) { m_quad[0] = r * v.m_quad[0]; m_quad[1] = r * v.m_quad[1]; m_quad[2] = r * v.m_quad[2]; m_quad[3] = r * v.m_quad[3]; }
    __forceinline void add4(const hkVector4& a) { m_quad[0] += a.m_quad[0]; m_quad[1] += a.m_quad[1]; m_quad[2] += a.m_quad[2]; m_quad[3] += a.m_quad[3]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { m_quad[0] = a.m_quad[0] + b.m_quad[0]; m_quad[1] = a.m_quad[1] + b.m_quad[1]; m_quad[2] = a.m_quad[2] + b.m_quad[2]; m_quad[3] = a.m_quad[3] + b.m_quad[3]; }
};
struct Pool { void* FUN_0086b930(unsigned int n); };
extern Pool DAT_01090a78;
struct Inner { char pad[0x184]; float unk184; };
struct Child {
    int unk0, unk4;
    Inner* unk8;
    float FUN_0056f860();

};
struct Ref { int unk0, unk4, unk8, unkc; Child* unk10; };
struct ControllerBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetValue(float f);
    virtual void v36(); virtual void v37();
    virtual void Attach(void* host);
    int unk4;
    unsigned short flags;
    unsigned short unkA;
    float unkc, unk10, unk14, unk18;
    char pad1c[0x24];
};
struct Controller : ControllerBase {
    hkVector4 unk40;
    char pad50[0x20];
    Controller();  // FUN_0092b8d0
    static void* operator new(unsigned int n) {
        char* p = (char*)DAT_01090a78.FUN_0086b930(n);
        unsigned char o = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
        p += o;
        p[-1] = o;
        return p;
    }
    static void operator delete(void* p);
    void Configure(float value) {
        unsigned short options = flags;
        unk14 = 0.0f;
        unk18 = value;
        options &= 0xfff5;
        options |= 5;
        flags = options;
        unk10 = 0.0f;
        unkc = 1.0f;
        SetValue(-3.4028234663852886e+38f);
    }
};
struct Host { Controller* FUN_00825200(const void* type); };
}
extern char DAT_010f33dc;
extern float DAT_00f7b22c;
extern double DAT_00dbe5e0;
f3m_0092bbe0::Ref* FUN_00424fe0(f3m_0092bbe0::Host* host);

// pdb: bhkForceController::TestForce2 | bhkForceController.obj | fnv360_0822_retail, udata + bridge(call_gap|call_gap_sim), high
void bhkForceController_TestForce2(f3m_0092bbe0::Host* host, const f3m_0092bbe0::hkVector4* color, float value)
{
    using namespace f3m_0092bbe0;
    Controller* c = host->FUN_00825200(&DAT_010f33dc);
    if (!c) {
        c = new Controller();
        c->Attach(host);
    }
    Ref* r = FUN_00424fe0(host);
    hkVector4 v = *color;
    if (r && r->unk10) {
        Child* child = r->unk10;
        hkReal s = child->FUN_0056f860();
        Inner* inner = child->unk8;
        s = DAT_00f7b22c * s;
        v.mul4(s);
        hkVector4 o = *color;
        Inner*& ri = inner;
        o.setMul4((hkReal)(ri->unk184 * DAT_00dbe5e0), o);
        v.setAdd4(o, v);
    }
    c->unk40 = v;
    c->Configure(value);
}
}   // namespace f3m_0092bbe0

// @f3 0x00924ca0 (community match, verified in this file)
#include <math.h>
namespace f3m_00924ca0 {
// 0x00924ca0: hkRotation::isOrthonormal(hkReal epsilon) const of Havok 5.5.0 (hkBase, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// True when the three columns have length one within epsilon and the cross product of the first two equals the
// third within epsilon (so the matrix is a rotation without a reflection).
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers and the
// comparison mask) follow the SDK's inline maths for the x87 build. The function's own body is written from the
// game's code.

namespace f3m_00924ca0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef int hkBool32;

namespace hkMath {
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }

private:
    char m_bool;
};

class hkVector4Comparison
{
public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14,
        MASK_XYZW = 15
    };

    hkBool32 allAreSet(Mask m) const { return (m_mask & m) == m; }

private:
    int m_mask;
    friend struct hkVector4;
};

struct hkVector4
{
    __forceinline hkVector4() {}

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f);
    __forceinline void setAll3(hkReal a);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setAbs4(const hkVector4& v);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline hkVector4Comparison compareLessThanEqual4(const hkVector4& a) const;
    __forceinline hkSimdReal dot3(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared3() const;
    __forceinline hkBool32 equals3(const hkVector4& v, hkReal epsilon) const;

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::setAll3(hkReal a)
{
    x = a;
    y = a;
    z = a;
    w = a;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::setAbs4(const hkVector4& v)
{
    x = hkMath::fabs(v.x);
    y = hkMath::fabs(v.y);
    z = hkMath::fabs(v.z);
    w = hkMath::fabs(v.w);
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline hkVector4Comparison hkVector4::compareLessThanEqual4(const hkVector4& a) const
{
    hkVector4Comparison ret;
    ret.m_mask =
        ((x <= a.x) ? hkVector4Comparison::MASK_X : 0) |
        ((y <= a.y) ? hkVector4Comparison::MASK_Y : 0) |
        ((z <= a.z) ? hkVector4Comparison::MASK_Z : 0) |
        ((w <= a.w) ? hkVector4Comparison::MASK_W : 0);
    return ret;
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}

// equal within epsilon in each of the first three components
__forceinline hkBool32 hkVector4::equals3(const hkVector4& v, hkReal epsilon) const
{
    hkVector4 t;
    t.setSub4(*this, v);
    t.setAbs4(t);
    hkVector4 epsilon_v;
    epsilon_v.setAll3(epsilon);
    return t.compareLessThanEqual4(epsilon_v).allAreSet(hkVector4Comparison::MASK_XYZ);
}

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
    // isOrthonormal
    hkBool FUN_00924ca0(hkReal epsilon) const;
};

// pdb: hkRotation::isOrthonormal | hkRotation.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: epsilon
hkBool hkRotation::FUN_00924ca0(hkReal epsilon) const
{
    // the columns have length one
    hkReal dot0 = m_col0.dot3(m_col0);
    if (hkMath::fabs(dot0 - 1.0f) > epsilon)
    {
        return false;
    }

    hkReal dot1 = m_col1.dot3(m_col1);
    if (hkMath::fabs(dot1 - 1.0f) > epsilon)
    {
        return false;
    }

    hkReal dot2 = m_col2.dot3(m_col2);
    if (hkMath::fabs(dot2 - 1.0f) > epsilon)
    {
        return false;
    }

    // the first column cross the second is the third: orthogonal, and no reflection
    hkVector4 col0CrossCol1;
    col0CrossCol1.setCross(m_col0, m_col1);

    return col0CrossCol1.equals3(m_col2, epsilon);
}

}  // namespace f3m_00924ca0
}   // namespace f3m_00924ca0

// @f3 0x0092b430 (community match, verified in this file)
#include <math.h>
namespace f3m_0092b430 {
// 0x0092b430: hkpLimitedHingeConstraintData::setInWorldSpace(const hkTransform& bodyATransform,
// const hkTransform& bodyBTransform, const hkVector4& pivot, const hkVector4& axisIn) of Havok 5.5.0
// (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Builds the hinge's basis in world space (the normalized axis, a vector at right angles to it and their cross
// product) and stores the basis and the pivot in each body's local space.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, the perpendicular
// vector) follow the SDK's inline code for the x87 build; the names of the three locals and the statement
// boundaries follow the debug records of the SDK library's object. The function's own body is written from the
// game's code.

namespace f3m_0092b430 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkRotation;
struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();

    // setRotatedInverseDir
    void FUN_00477880(const hkRotation& r, const hkVector4& v);
    // setTransformedInversePos
    void FUN_008d2970(const hkTransform& t, const hkVector4& p);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize3()
{
    this->mul4(this->lengthInverse3());
}

namespace hkVector4Util {
// a vector at right angles to vectorIn: its smallest component is left out, the other two are swapped and one
// of them negated
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
}  // namespace hkVector4Util

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpConstraintData : hkReferencedObject
{
    unsigned long m_userData;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpSetLocalTransformsConstraintAtom : hkpConstraintAtom
{
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct hkpLimitedHingeConstraintData : hkpConstraintData
{
    struct Atoms
    {
        hkpSetLocalTransformsConstraintAtom m_transforms;
    };

    // setInWorldSpace
    void FUN_0092b430(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                      const hkVector4& axisIn);

    Atoms m_atoms;
};

// pdb: hkpLimitedHingeConstraintData::setInBodySpace | hkpLimitedHingeConstraintData.obj | fnv360_0721_beta, objrun, medium
// pdb params: pivotA, pivotB, axisA, axisB, axisAPerp, axisBPerp
void hkpLimitedHingeConstraintData::FUN_0092b430(const hkTransform& bodyATransform,
                                                 const hkTransform& bodyBTransform, const hkVector4& pivot,
                                                 const hkVector4& axisIn)
{
    // the hinge's basis in world space: the axis, a vector at right angles to it, and their cross product
    hkVector4 axis = axisIn; axis.normalize3();
    hkVector4 perpToAxle1;
    hkVector4 perpToAxle2;
    hkVector4Util::calculatePerpendicularVector(axis, perpToAxle1); perpToAxle1.normalize3();
    perpToAxle2.setCross(axis, perpToAxle1);

    // the basis and the pivot in body A's space
    m_atoms.m_transforms.m_transformA.getColumn(0).FUN_00477880(bodyATransform.getRotation(), axis);
    m_atoms.m_transforms.m_transformA.getColumn(1).FUN_00477880(bodyATransform.getRotation(), perpToAxle1);
    m_atoms.m_transforms.m_transformA.getColumn(2).FUN_00477880(bodyATransform.getRotation(), perpToAxle2);
    m_atoms.m_transforms.m_transformA.getTranslation().FUN_008d2970(bodyATransform, pivot);

    // and in body B's space
    m_atoms.m_transforms.m_transformB.getColumn(0).FUN_00477880(bodyBTransform.getRotation(), axis);
    m_atoms.m_transforms.m_transformB.getColumn(1).FUN_00477880(bodyBTransform.getRotation(), perpToAxle1);
    m_atoms.m_transforms.m_transformB.getColumn(2).FUN_00477880(bodyBTransform.getRotation(), perpToAxle2);
    m_atoms.m_transforms.m_transformB.getTranslation().FUN_008d2970(bodyBTransform, pivot);
}

}  // namespace f3m_0092b430
}   // namespace f3m_0092b430

// @f3 0x009310d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_009310d0 {

// 0x009310d0: reads a constraint description from a file stream (a pivot, two axes and two more vectors, 16 bytes
// each), byte-swaps them when the file is not in native order, and fills in the target: the first frame gets the
// pivot, the cross product of the two axes and the axes themselves; the last two vectors go to the second frame.
// Without a caller-supplied block a local one is set up first.

namespace f3m_009310d0 {

struct Stream;
typedef unsigned int (__cdecl* ReadFn)(Stream* s, void* buf, unsigned int size, unsigned int* compSize, unsigned int numComps);

struct Stream {
    int unk00;
    unsigned int m_pos;
    ReadFn m_read;

    __forceinline unsigned int Read(void* buf, unsigned int size)
    {
        unsigned int n = m_read(this, buf, size, 0, 0);
        m_pos += n;
        return n;
    }
};

struct Loader {
    unsigned char pad000[0x1e5];
    unsigned char m_native;
    unsigned char pad1e6[0x24c - 0x1e6];
    Stream* m_stream;
};

__forceinline void Swap32(void* p)
{
    unsigned long* q = static_cast<unsigned long*>(p);
    *q = _byteswap_ulong(*q);
}

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void Swap()
    {
        Swap32(&x);
        Swap32(&y);
        Swap32(&z);
        Swap32(&w);
    }
    // this = p x q, w = 0
    __forceinline void SetCross(const Vec4& p, const Vec4& q)
    {
        x = p.y * q.z - p.z * q.y;
        y = p.z * q.x - p.x * q.z;
        z = p.x * q.y - p.y * q.x;
        w = 0.0f;
    }
    __forceinline void Set(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
};

struct __declspec(align(16)) Header {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Header() : unk08(0), unk0c(0) {}
};

struct Block {
    Header m_header;
    Vec4 m_v0;
    Vec4 m_a;
    Vec4 m_b;
    Vec4 m_v3;
    Vec4 m_v4;
};

struct Target {
    int unk00[8];
    Vec4 m_cross;
    Vec4 m_a;
    Vec4 m_b;
    Vec4 m_v0;
    Vec4 m_v4;
    int unk70[8];
    Vec4 m_v3;
    unsigned short unka0;
    unsigned char m_dirty;
};

struct Owner {
    int unk00;
    Target* m_target;
    void FUN_008fc680(Loader* loader, Block* block);
    void FUN_009310d0(Loader* loader, Block* block);
};

void Owner::FUN_009310d0(Loader* loader, Block* block)
{
    Block local;
    if (block == 0) {
        block = &local;
        FUN_008fc680(loader, block);
    }
    Target* t = m_target;

    // five vectors straight from the stream
    loader->m_stream->Read(&block->m_v0, 0x10);
    loader->m_stream->Read(&block->m_a, 0x10);
    loader->m_stream->Read(&block->m_b, 0x10);
    loader->m_stream->Read(&block->m_v3, 0x10);
    loader->m_stream->Read(&block->m_v4, 0x10);

    // files in the other byte order are swapped word by word
    if (loader->m_native != 1) {
        block->m_v0.Swap();
        block->m_a.Swap();
        block->m_b.Swap();
        block->m_v3.Swap();
        block->m_v4.Swap();
    }

    // the third axis of the first frame
    Vec4 c;
    c.SetCross(block->m_a, block->m_b);
    const Vec4& a = block->m_a;
    const Vec4& b = block->m_b;
    t->m_v0.Set(block->m_v0);
    t->m_cross.x = c.x;
    t->m_cross.y = c.y;
    t->m_cross.z = c.z;
    t->m_cross.w = c.w;
    t->m_a.Set(a);
    t->m_b.Set(b);
    t->m_v3.Set(block->m_v3);
    t->m_v4.Set(block->m_v4);
    t->m_dirty = 0;
}

}

}   // namespace f3m_009310d0

// @f3 0x00924760 (community match, verified in this file)
#include <math.h>
namespace f3m_00924760 {

// 0x00924760: removes from a quaternion its rotation about a given axis (hkQuaternion::removeAxisComponent in Havok
// terms). The axis is rotated by the quaternion; what is left is the shortest rotation that takes the axis to the
// rotated axis: identity when they are parallel, half a turn about any perpendicular when they are opposite,
// otherwise the angle between them about their cross product.

namespace f3m_00924760 {

typedef float hkReal;

inline hkReal hkFabs(hkReal r) { return fabsf(r); }
inline hkReal hkSqrt(hkReal r) { return (hkReal)sqrt(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }

hkReal __cdecl FUN_008d3240(hkReal x);      // arc cosine, with the input clamped to [-1, 1]

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    hkReal& operator()(int i) { return (&x)[i]; }
    const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline hkReal lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 != 0.0f ? hkSqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
};

// a vector at a right angle to vectorIn: its two larger components are swapped, one negated, the smallest zeroed
__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;
    hkReal a0 = hkFabs(vectorIn(0));
    hkReal a1 = hkFabs(vectorIn(1));
    hkReal a2 = hkFabs(vectorIn(2));
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

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec(3); }
    __forceinline void setIdentity() { m_vec.set(0.0f, 0.0f, 0.0f, 1.0f); }
    void FUN_009240d0(const hkVector4& axis, hkReal angle);     // setAxisAngle
    void hkQuaternion_removeAxisComponent(const hkVector4& v);
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

// pdb: hkQuaternion::removeAxisComponent | hkQuaternion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(uconst), high
void hkQuaternion::hkQuaternion_removeAxisComponent(const hkVector4& axis)
{
    hkVector4 rotatedAxis;
    rotatedAxis.setRotatedDir(*this, axis);
    hkReal dotProd = axis.dot3(rotatedAxis);

    // parallel: nothing is left
    if ((dotProd - 1.0f) > -1e-3f)
    {
        setIdentity();
        return;
    }

    // opposite: half a turn about any perpendicular
    if ((dotProd + 1.0f) < 1e-3f)
    {
        hkVector4 perpVector;
        calculatePerpendicularVector(axis, perpVector);
        FUN_009240d0(perpVector, 3.14159265f);
        return;
    }

    {
        const hkReal rotationAngle = FUN_008d3240(dotProd);
        hkVector4 rotationAxis;
        rotationAxis.setCross(axis, rotatedAxis);
        rotationAxis.normalize3();
        FUN_009240d0(rotationAxis, rotationAngle);
    }
}

}
}   // namespace f3m_00924760

// @f3 0x00921e40 (community match, verified in this file)
namespace f3m_00921e40 {


typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

class hkVector4
{
public:
    __declspec(align(16)) hkReal x;
    hkReal y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f)
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
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void mul4(const hkVector4& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }
    __forceinline void mul4(hkReal rs)
    {
        x *= rs;
        y *= rs;
        z *= rs;
        w *= rs;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = dot3(*this);
        if (l2 != 0.0f)
        {
            return 1.0f / (hkReal)sqrt((double)l2);
        }
        return 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};

union hkIntUnion64
{
    unsigned __int64 u64;
    hkUint32 u32[2];
    hkUint16 u16[4];
};

extern const hkVector4 DAT_00f7b0c0;
static const hkReal HK_REAL_MAX = 3.40282e+38f;

__forceinline void convertToUint16(const hkVector4& in, const hkVector4& offset, const hkVector4& scale, hkIntUnion64& out)
{
    hkVector4 x;
    x.setAdd4(offset, in);
    x.setMul4(x, scale);

    hkVector4 magic = DAT_00f7b0c0;
    x.add4(magic);

    const hkUint32* i = (const hkUint32*)&x;
    out.u16[0] = hkUint16(i[0] >> 6);
    out.u16[1] = hkUint16(i[1] >> 6);
    out.u16[2] = hkUint16(i[2] >> 6);
    out.u16[3] = hkUint16(i[3] >> 6);
}

struct hkSphere
{
    hkVector4 m_pos;
    __forceinline const hkVector4& getPosition() const { return m_pos; }
};

struct CollideSpheresInput
{
    const hkSphere* m_spheres;
    int m_numSpheres;
};

typedef hkVector4 SphereCollisionOutput;

class hkSampledHeightFieldShape
{
public:
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int m_xRes;
    int m_zRes;
    hkReal m_heightCenter;
    bool m_useProjectionBasedHeight;
    hkVector4 m_intToFloatScale;
    hkVector4 m_floatToIntScale;
    hkVector4 m_floatToIntOffsetFloorCorrected;

    hkReal FUN_00922550(int x, int z) const;
    void FUN_00921e40(const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const;
};

template<class IMPL>
__forceinline void hkSampledHeightFieldShape_collideSpheres(const IMPL& hfShape, const CollideSpheresInput& input, SphereCollisionOutput* outputArray)
{
    SphereCollisionOutput* output = outputArray;
    const hkSphere* sphere = input.m_spheres;

    for (int i = input.m_numSpheres - 1; i >= 0; i--)
    {
        {
            output[0].set(0.0f, 1.0f, 0.0f, HK_REAL_MAX);
            hkVector4 pos;
            pos.setMul4(hfShape.m_floatToIntScale, sphere->getPosition());

            hkIntUnion64 out;
            convertToUint16(sphere->getPosition(), hfShape.m_floatToIntOffsetFloorCorrected, hfShape.m_floatToIntScale, out);
            int xPos = out.u16[0];
            int zPos = out.u16[2];

            if (xPos < hfShape.m_xRes - 1 && zPos < hfShape.m_zRes - 1)
            {
                hkReal subX = pos(0) - xPos;
                hkReal subZ = pos(2) - hkReal(zPos);

                hkReal height;
                hkReal h10 = hfShape.FUN_00922550(xPos + 1, zPos);
                const int px = xPos + 1;
                hkReal h01 = hfShape.FUN_00922550(xPos, zPos + 1);
                if (subX + subZ > 1.0)
                {
                    hkReal h11 = hfShape.FUN_00922550(xPos + 1, zPos + 1);
                    hkReal dx = h11 - h01;
                    hkReal dz = h11 - h10;
                    height = h10 + dz * subZ + dx * (subX - 1.0);
                    output[0](0) = -dx;
                    output[0](2) = -dz;
                }
                else
                {
                    hkReal h00 = hfShape.FUN_00922550(xPos, zPos);
                    hkReal dx = h10 - h00;
                    hkReal dz = h01 - h00;
                    height = h00 + dz * subZ + dx * subX;
                    output[0](0) = -dx;
                    output[0](2) = -dz;
                }

                output[0].mul4(hfShape.m_floatToIntScale);
                output[0].normalize3();

                hkReal dist;
                if (!hfShape.m_useProjectionBasedHeight)
                {
                    dist = (pos(1) - height) * hfShape.m_intToFloatScale(1) - sphere->m_pos(3);
                }
                else
                {
                    hkVector4 p;
                    const int pz = zPos;
                    p.set(hkReal(px), h10, hkReal(pz));
                    hkVector4 delta;
                    delta.setSub4(pos, p);
                    delta.mul4(hfShape.m_intToFloatScale);
                    dist = output[0].dot3(delta) - sphere->m_pos(3);
                }
                output[0].w = dist;
            }
        }
        output++;
        sphere++;
    }
}

// pdb: hkBSHeightFieldShape::collideSpheres | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInput, apOutputArray
void hkSampledHeightFieldShape::FUN_00921e40(const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const
{
    hkSampledHeightFieldShape_collideSpheres(*this, input, outputArray);
}
}   // namespace f3m_00921e40

// @f3 0x00937e00 (community match, verified in this file)
namespace f3m_00937e00 {
// FUN_00937e00: Havok versioning patch of the ragdoll constraint data: the old basisA/basisB (twistAxis, planeAxis)
// and angle members become the new "atoms" (rotations, twistLimit, coneLimit, planesLimit).
// The code is optimised (aligned esp frame, esi/edi live across calls, private conventions of the static helpers):
// it matches under /MT /O2 /GS /EHsc /Gy, not under the listed /Od.
namespace f3m_00937e00 {
extern const char DAT_00e39ef4[];
extern const char DAT_00e6d12c[];
extern const char DAT_00e6d124[];
extern const char DAT_00e3a5b8[];
extern const char DAT_00e6ce5c[];
extern const char DAT_00e39be4[];
extern const char DAT_00de0378[];
extern const char DAT_00e39cec[];
extern const char DAT_00e39ce0[];
extern const char DAT_00e39ca4[];
extern const char DAT_00e3a564[];
extern const char DAT_00e3a594[];
extern const char DAT_00e3a574[];
extern const char DAT_00e3a5c4[];
extern const char DAT_00e6ce0c[];
extern const char DAT_00e6ce1c[];
extern const char DAT_00e39cb0[];
extern const char DAT_00e6ce4c[];
extern const char DAT_00e6ce2c[];
extern const char DAT_00e6ce3c[];
extern const char DAT_00e39c98[];
extern const char DAT_00e3ff58[];

extern short DAT_0105f5bc;
extern short DAT_0105f580;
extern short DAT_0105f584;
extern const float DAT_00dc3b0c;
struct __declspec(align(16)) Rv4 {
    float x, y, z, w;
    __forceinline Rv4() {}
    __forceinline Rv4(const Rv4& other) { *this = other; }
    __forceinline void operator=(const Rv4& other) {
        x = other.x; y = other.y; z = other.z; w = other.w;
    }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    __forceinline void setCross(const Rv4& v1, const Rv4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
};
struct __declspec(align(16)) RvRot { Rv4 c0, c1, c2;
    __forceinline void setCols(const Rv4& a, const Rv4& b, const Rv4& c) { c0 = a; c1 = b; c2 = c; }
};
struct RvMember;
struct RvEnum { int FUN_009b2360(const char* name, int* out) const; };
struct RvInfo;
struct RvClass {
    RvEnum* FUN_009b05d0(const char* name);
    int FUN_009b0630() const;
    const RvInfo& FUN_009b0650(int index) const;
    int FUN_009b0760() const;
};
struct RvInfo {
    const char* name;
    void* unk04;
    void* unk08;
    unsigned char unk0c, unk0d;
    unsigned short unk0e, unk10, offset;
    const RvEnum& FUN_0093d8b0() const;
    const RvClass& FUN_0093d890() const;
};
struct RvPair { void* object; RvClass* klass; RvPair() {} inline RvMember M(const char* name); };
struct RvVariant {
    void* object;
    RvClass* klass;
    RvVariant(void* obj);
    inline RvMember M(const char* name);
};
struct RvMember {
    void* unk00;
    int unk04;
    RvMember() {}
    RvMember(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
    Rv4& FUN_0093d720(int index);
    RvMember FUN_0093d7a0(const char* name);
    RvPair FUN_0093d810();
    const RvInfo& FUN_0093d790() const;
};
inline RvMember RvPair::M(const char* name) { return RvMember((void*)this, name); }
inline RvMember RvVariant::M(const char* name) { return RvMember((void*)this, name); }
static __declspec(noinline) int FUN_009366b0(RvMember* acc)
{
    const RvClass* k = acc->FUN_0093d810().klass;
    const RvInfo& last = k->FUN_009b0650(k->FUN_009b0630() - 1);
    unsigned int offset = acc->FUN_0093d7a0(last.name).FUN_0093d790().offset;
    return offset + last.FUN_0093d890().FUN_009b0760();
}
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    RvMember f(obj, DAT_00e3ff58);
    int value;
    f.FUN_0093d790().FUN_0093d8b0().FUN_009b2360(name, &value);
    return (short)value;
}
static __declspec(noinline) void FUN_00937030(void* obj, char enabled, char twistAxis, char refAxis,
                                              float minAngle, float maxAngle, float tau)
{
    if (DAT_0105f580 == -1)
        DAT_0105f580 = FUN_00936710(obj, "TYPE_TWIST_LIMIT");
    { RvMember a(obj, DAT_00e3ff58); *a.FUN_0093d6e0(0) = DAT_0105f580; }
    { RvMember a(obj, "isEnabled"); *a.FUN_0093d710(0) = enabled; }
    { RvMember a(obj, DAT_00e3a5b8); *a.FUN_0093d710(0) = twistAxis; }
    { RvMember a(obj, "refAxis"); *a.FUN_0093d710(0) = refAxis; }
    { RvMember a(obj, "minAngle"); *a.FUN_0093d6a0(0) = minAngle; }
    { RvMember a(obj, "maxAngle"); *a.FUN_0093d6a0(0) = maxAngle; }
    { RvMember a(obj, DAT_00e3a5c4); *a.FUN_0093d6a0(0) = tau; }
}
static __declspec(noinline) void FUN_00937140(void* obj, char enabled, char twistAxisInA, char refAxisInB,
                                              char mode, float minAngle, float maxAngle, float tau)
{
    if (DAT_0105f584 == -1)
        DAT_0105f584 = FUN_00936710(obj, "TYPE_CONE_LIMIT");
    { RvMember a(obj, DAT_00e3ff58); *a.FUN_0093d6e0(0) = DAT_0105f584; }
    { RvMember a(obj, "isEnabled"); *a.FUN_0093d710(0) = enabled; }
    { RvMember a(obj, "twistAxisInA"); *a.FUN_0093d710(0) = twistAxisInA; }
    { RvMember a(obj, "refAxisInB"); *a.FUN_0093d710(0) = refAxisInB; }
    { RvMember a(obj, "angleMeasurementMode"); *a.FUN_0093d710(0) = mode; }
    { RvMember a(obj, "minAngle"); *a.FUN_0093d6a0(0) = minAngle; }
    { RvMember a(obj, "maxAngle"); *a.FUN_0093d6a0(0) = maxAngle; }
    { RvMember a(obj, DAT_00e3a5c4); *a.FUN_0093d6a0(0) = tau; }
}
void __cdecl FUN_00936940(const RvPair& rotations, const RvRot& a, const RvRot& b);
}

// The two unused reads of the twist axis in each block (twistY, twistZ) emit nothing. They are a guess at the source:
// without them every instruction matches except the operand order of two products in each inlined cross product
// (the original loads the plane component first in all six products: fld [plane.x]; fld st(0); fmul st(4)).
// One extra read of twist.y and twist.z, which the optimiser removes late, gives exactly that order; spelling of
// setCross, operand order, declaration order and numbering probes do not.
void __cdecl FUN_00937e00(void* oldObject, void* newObject)
{
    using namespace f3m_00937e00;
    RvMember atoms(newObject, DAT_00e39ef4);
    RvVariant oldVariant(oldObject);
    if (DAT_0105f5bc == -1)
        DAT_0105f5bc = FUN_009366b0(&atoms);
    RvRot a, b;
    {
        RvPair basis = oldVariant.M(DAT_00e6d12c).FUN_0093d810();
        const Rv4 twist = basis.M(DAT_00e3a5b8).FUN_0093d720(0);
        const Rv4 plane = basis.M(DAT_00e6ce5c).FUN_0093d720(0);
        const float twistY = twist.y;   // never used: see the note above
        const float twistZ = twist.z;
        Rv4 cross;
        cross.setCross(twist, plane);
        a.setCols(twist, plane, cross);
    }
    {
        RvPair basis = oldVariant.M(DAT_00e6d124).FUN_0093d810();
        const Rv4 twist = basis.M(DAT_00e3a5b8).FUN_0093d720(0);
        const Rv4 plane = basis.M(DAT_00e6ce5c).FUN_0093d720(0);
        const float twistY = twist.y;   // never used: see the note above
        const float twistZ = twist.z;
        Rv4 cross;
        cross.setCross(twist, plane);
        b.setCols(twist, plane, cross);
    }
    FUN_00936940(atoms.FUN_0093d7a0(DAT_00e39be4).FUN_0093d810(), a, b);
    {
    int axisTwist, axisPlanes, aligned, perpendicular;
    { RvClass* k = atoms.FUN_0093d810().klass;
      k->FUN_009b05d0(DAT_00de0378)->FUN_009b2360(DAT_00e39cec, &axisTwist); }
    { RvClass* k = atoms.FUN_0093d810().klass;
      k->FUN_009b05d0(DAT_00de0378)->FUN_009b2360(DAT_00e39ce0, &axisPlanes); }
    { RvClass* k = atoms.FUN_0093d810().M(DAT_00e39ca4).FUN_0093d810().klass;
      k->FUN_009b05d0(DAT_00e3a564)->FUN_009b2360(DAT_00e3a594, &aligned); }
    { RvClass* k = atoms.FUN_0093d810().M(DAT_00e39ca4).FUN_0093d810().klass;
      k->FUN_009b05d0(DAT_00e3a564)->FUN_009b2360(DAT_00e3a574, &perpendicular); }
    {
        RvMember tau((void*)&oldVariant, DAT_00e3a5c4);
        RvMember maxA((void*)&oldVariant, DAT_00e6ce0c);
        RvMember minA((void*)&oldVariant, DAT_00e6ce1c);
        FUN_00937030(&atoms.FUN_0093d7a0(DAT_00e39cb0).FUN_0093d810(), 1, (char)axisTwist, (char)axisPlanes,
                     *minA.FUN_0093d6a0(0), *maxA.FUN_0093d6a0(0), *tau.FUN_0093d6a0(0));
    }
    {
        RvMember tau((void*)&oldVariant, DAT_00e3a5c4);
        RvMember maxA((void*)&oldVariant, DAT_00e6ce4c);
        FUN_00937140(&atoms.FUN_0093d7a0(DAT_00e39ca4).FUN_0093d810(), 1, (char)axisTwist, (char)axisTwist,
                     (char)aligned, DAT_00dc3b0c, *maxA.FUN_0093d6a0(0), *tau.FUN_0093d6a0(0));
    }
    {
        RvMember tau((void*)&oldVariant, DAT_00e3a5c4);
        RvMember maxA((void*)&oldVariant, DAT_00e6ce2c);
        RvMember minA((void*)&oldVariant, DAT_00e6ce3c);
        FUN_00937140(&atoms.FUN_0093d7a0(DAT_00e39c98).FUN_0093d810(), 1, (char)axisTwist, (char)axisPlanes,
                     (char)perpendicular, *minA.FUN_0093d6a0(0), *maxA.FUN_0093d6a0(0), *tau.FUN_0093d6a0(0));
    }
    }
}

}   // namespace f3m_00937e00

// @f3 0x00920730 (community match, verified in this file)
#include <math.h>
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern const char DAT_00e36998[];
extern const char DAT_00e32798[];
extern const float DAT_00e32888;
namespace f3m_00920730 {

namespace f3m_00920730 {

extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
}

struct hkBool
{
    char m_bool;

    __forceinline hkBool() {}
    __forceinline hkBool(bool b)
    {
        m_bool = (char)b;
    }
    __forceinline operator bool() const
    {
        return m_bool != 0;
    }
};

static __forceinline float hkSqrt(float r)
{
    return (float)sqrt(r);
}
static __forceinline float hkSqrtInverse(float r)
{
    return 1.0f / hkSqrt(r);
}

struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(float x) : m_real(x) {}
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setAll3(float a) { x = a; y = a; z = a; w = a; }
    __forceinline float dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline float lengthSquared3() const { return (x * x) + (y * y) + z * z; }
    __forceinline float lengthInverse3() const { float l2 = lengthSquared3(); return l2 ? hkSqrtInverse(l2) : 0; }
    __forceinline void add4(const hkVector4& a) { x += a.x; y += a.y; (*this)(2) += a(2); w += a.w; }
    __forceinline void sub4(const hkVector4& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { x = (a.x + b.x); y = (a.y + b.y); z = (a.z + b.z); w = (a.w + b.w); }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, float r) { x = a.x + r * b.x; y = a.y + r * b.y; z = a.z + r * b.z; w = a.w + r * b.w; }
    __forceinline void mul4(hkSimdReal rs) { float s = rs; x *= s; y *= s; z *= s; w *= s; }
    __forceinline void addMul4(float r, const hkVector4& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};
struct hkMonitorStream
{
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

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)TlsGetValue(DAT_0116913c);
    }
    __forceinline hkBool memoryAvailable()
    {
        return m_end < m_capacityMinus16;
    }
};

static __forceinline void hkTimerBegin(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end;
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end = (char*)(h + 1);
    }
}

class hkThreadMemory
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);

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

    void FUN_008f6d90(void* p, int nbytes, int cls);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        if (current + nbytes <= m_stackEnd)
        {
            m_stackCurrent = current + nbytes;
            return current;
        }
        return onStackOverflow(nbytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackBase)
        {
            onStackUnderflow(p);
        }
    }
};

void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem);
void __cdecl FUN_00901f10(void* array, int sizeElem);

template <typename T>
class hkArray
{
  public:
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    __forceinline int getSize() const
    {
        return m_size;
    }
    __forceinline int getCapacity() const
    {
        return m_capacityAndFlags & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        m_size = n;
    }
    __forceinline T& expandOne()
    {
        if (m_size == getCapacity())
        {
            FUN_00901f10(this, sizeof(T));
        }
        return m_data[m_size++];
    }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
static __forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

template <typename T>
class hkLocalArray : public hkArray<T>
{
  public:
    __forceinline hkLocalArray(int n)
    {
        this->m_data = (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_localMemory = this->m_data;
    }
    __forceinline void destruct()
    {
        hkDeallocateStack(m_localMemory);
        this->releaseMemory();
    }

    T* m_localMemory;
};

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    float m_staticFriction;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_dynamicFriction;
    int m_priority;

    hkpSurfaceConstraintInfo& operator=(const hkpSurfaceConstraintInfo& other);
};

struct hkSurfaceConstraintInteraction
{
    unsigned char m_touched;
    unsigned char m_stopped;
    float m_surfaceTime;
    float m_penaltyDistance;
    int m_status;
};

struct hkSimplexSolverInput
{
    __forceinline hkSimplexSolverInput()
    {
        m_position.setZero4();
    }
    hkVector4 m_position;
    hkVector4 m_velocity;
    hkVector4 m_maxSurfaceVelocity;
    hkVector4 m_upVector;
    float m_deltaTime;
    float m_minDeltaTime;
    hkpSurfaceConstraintInfo* m_constraints;
    int m_numConstraints;
};

struct hkSimplexSolverOutput
{
    hkVector4 m_position;
    hkVector4 m_velocity;
    float m_deltaTime;
    hkSurfaceConstraintInteraction* m_planeInteractions;
};

void __cdecl FUN_009a5ae0(const hkSimplexSolverInput& input, hkSimplexSolverOutput& output);

struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_normal;
    void* m_rootCollidableA;
    int m_shapeKeyA;
    void* m_rootCollidableB;
    int m_shapeKeyB;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

struct hkpSurfaceInfoDeprecated
{
    hkBool m_isSupported;
    hkBool m_isSliding;
    hkVector4 m_surfaceNormal;
    hkVector4 m_surfaceVelocity;
};

class hkpAllCdPointCollector;
class hkpShapePhantom;

// hkpCharacterProxy::addMaxSlopePlane (static, FNV FUN_00cadca0)
static __declspec(noinline) bool addMaxSlopePlane(float maxSlopeCos, const hkVector4& up, int index, hkArray<hkpSurfaceConstraintInfo>& surfaceConstraintsInOut)
{
    const float surfaceVerticalComponent = surfaceConstraintsInOut[index].m_plane.dot3(up);
    if (surfaceVerticalComponent > 0.01f && surfaceVerticalComponent < maxSlopeCos)
    {
        hkpSurfaceConstraintInfo& newConstraint = surfaceConstraintsInOut.expandOne();
        newConstraint = surfaceConstraintsInOut[index];
        newConstraint.m_plane.addMul4(-surfaceVerticalComponent, up);
        newConstraint.m_plane.normalize3();
        return true;
    }
    return false;
}

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    int m_memSizeAndFlags;
};

class hkpEntityListener
{
  public:
    virtual ~hkpEntityListener();
};

class hkpPhantomListener
{
  public:
    virtual ~hkpPhantomListener();
};

class hkpCharacterProxy : public hkReferencedObject, public hkpEntityListener, public hkpPhantomListener
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void updateManifold(hkpAllCdPointCollector& startPointCollector, hkpAllCdPointCollector& castCollector);
    virtual void getSurfaceConstraintInfo(const hkpRootCdPoint& point, hkpSurfaceConstraintInfo& surface, float timeTravelled) const;

    hkVector4 m_velocity;
    hkVector4 m_oldDisplacement;
    hkpShapePhantom* m_shapePhantom;
    float m_dynamicFriction;
    float m_staticFriction;
    int unk3c;
    hkVector4 m_up;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_keepDistance;
    float m_keepContactTolerance;
    float m_contactAngleSensitivity;
    int m_userPlanes;
    float m_maxCharacterSpeedForSolver;
    float m_characterStrength;
    float m_characterMass;
    hkArray<hkpRootCdPoint> m_manifold;
    hkArray<void*> m_bodies;
    hkArray<void*> m_phantoms;
    hkArray<void*> m_listeners;
    float m_maxSlopeCosine;
    float m_penetrationRecoverySpeed;
    int m_maxCastIterations;
    bool m_refreshManifoldInCheckSupport;

    void FUN_0091fdb0(hkpAllCdPointCollector& startPointCollector);
    void FUN_0091ec20(const hkArray<hkpRootCdPoint>& manifold, hkSimplexSolverInput& input);
    void FUN_00920730(const hkVector4& direction, hkpSurfaceInfoDeprecated& ground);
};


// hkpCharacterProxy::checkSupportDeprecated (sibling of the verified 0x0091fe80, whose declarations this file reuses)
// Matches under /MT /O2 /GS /EHsc /Gy (the listed /Od /Oy- set is wrong for this function).
// STEERING SPELLINGS the match depends on. They only decide x87 operand order: no statement is dead, no local is
// unused and no branch is statically false, but the alias, the parentheses and the operator() access emit no code
// of their own.
//  - hkVector4::setAdd4 with every sum in parentheses, together with the reference alias 'velocity'
//  - hkVector4::dot3 returns float; mul4 takes hkSimdReal by value; normalize3 passes lengthInverse3() straight on
//  - hkVector4::lengthSquared3 with the x and y products in parentheses and the z product without
//  - hkVector4::add4 reads and writes the z lane through operator()(2); x, y and w use members
// Not steering, but needed: numTouching++ follows the two add4 calls, and the support threshold is 0.99f (the
// original's 8-byte literal is 0.99f widened to double, not 0.001).
// No destructors on hkLocalArray (destruct() called by hand): that is what removes the exception frame.
// pdb: hkpCharacterProxy::checkSupportDeprecated | hkpCharacterProxy.obj | fnv360_0822_retail, objrun, medium
// pdb params: direction, ground
void hkpCharacterProxy::FUN_00920730(const hkVector4& direction, hkpSurfaceInfoDeprecated& ground)
{
    hkTimerBegin(DAT_00e36998);
    hkLocalArray<hkpSurfaceConstraintInfo> constraints(m_manifold.getSize() + m_userPlanes + 10);
    constraints.setSizeUnchecked(m_manifold.getSize());
    for (int i = 0; i < m_manifold.getSize(); i++)
    {
        getSurfaceConstraintInfo(m_manifold[i], constraints[i], 0.0f);
        addMaxSlopePlane(m_maxSlopeCosine, m_up, i, constraints);
    }
    if (constraints.getCapacity() - constraints.getSize() < m_userPlanes)
    {
        constraints.reserve(constraints.getSize() + m_userPlanes);
    }
    hkLocalArray<hkSurfaceConstraintInteraction> interactions(constraints.getSize() + m_userPlanes);
    interactions.setSize(constraints.getSize() + m_userPlanes);

    hkSimplexSolverInput input;
    hkSimplexSolverOutput output;
    input.m_position.setZero4();
    input.m_constraints = constraints.begin();
    input.m_numConstraints = m_manifold.getSize();
    hkVector4& velocity = input.m_velocity;
    velocity.setAdd4(direction, m_velocity);
    input.m_deltaTime = DAT_00e32888;
    input.m_minDeltaTime = DAT_00e32888;
    input.m_upVector = m_up;
    input.m_maxSurfaceVelocity.setAll3(m_maxCharacterSpeedForSolver);
    output.m_planeInteractions = interactions.begin();
    FUN_0091ec20(m_manifold, input);
    FUN_009a5ae0(input, output);

    output.m_velocity.sub4(m_velocity);
    float projectedVelocity = output.m_velocity.dot3(direction);
    ground.m_isSupported = projectedVelocity < 0.99f;
    hkVector4 linearVelocity;
    linearVelocity.setAddMul4(output.m_velocity, direction, -projectedVelocity);
    ground.m_isSliding = linearVelocity.lengthSquared3() > 0.01f;

    ground.m_surfaceVelocity.setZero4();
    ground.m_surfaceNormal.setZero4();
    int numTouching = 0;
    for (int k = 0; k < input.m_numConstraints; k++)
    {
        if (interactions[k].m_touched && constraints[k].m_plane.dot3(direction) < -0.08f)
        {
            ground.m_surfaceNormal.add4(constraints[k].m_plane);
            ground.m_surfaceVelocity.add4(constraints[k].m_velocity);
            numTouching++;
        }
    }
    if (numTouching > 0)
    {
        ground.m_surfaceNormal.normalize3();
        ground.m_surfaceVelocity.mul4(1.0f / numTouching);
    }
    else
    {
        ground.m_isSupported = false;
    }
    hkTimerBegin(DAT_00e32798);
    interactions.destruct();
    constraints.destruct();
}
}
}   // namespace f3m_00920730

// @f3 0x00939770 (community match, verified in this file)
extern short DAT_0105f5d4;
extern short DAT_0105f588;
extern short DAT_0105f580;
extern short DAT_0105f584;
extern short DAT_0105f558;
extern short DAT_0105f590;
namespace f3m_00939770 {
typedef float hkReal;

class hkVector4
{
public:
    __declspec(align(16)) hkReal x;
    hkReal y, z, w;

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
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};

class hkRotation
{
public:
    hkVector4 m_col0, m_col1, m_col2;
};

class hkTransform
{
public:
    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkBool
{
    char m_bool;
    hkBool(bool b) { m_bool = b; }
};

struct hkClassEnum
{
    bool FUN_009b2360(const char* name, int* value) const;
};

struct hkClassMember;

struct hkClass
{
    const hkClassEnum* FUN_009b05d0(const char* name) const;
    int FUN_009b0630() const;
    const hkClassMember* FUN_009b0650(int index) const;
    int FUN_009b0760() const;
};

struct hkClassMember
{
    const char* name;
    const hkClass* memberClass;
    const hkClassEnum* reflectedEnum;
    unsigned char type;
    unsigned char subType;
    unsigned short arraySize;
    unsigned short flags;
    unsigned short offset;
    const hkClass* FUN_0093d890() const;
    const hkClassEnum* FUN_0093d8b0() const;
};

struct hkVariant
{
    void* obj;
    const hkClass* cls;
};

struct hkClassAccessor
{
    hkVariant m_variant;
    hkClassAccessor() {}
    void FUN_0093d7f0(const hkVariant& src);
    inline struct Accessor member(const char* name);
};

struct Accessor
{
    void* addr;
    const hkClassMember* member;
    void FUN_0093d600(const hkVariant& src, const char* name);
    float* FUN_0093d720(int i);
    float* FUN_0093d6a0(int i);
    short* FUN_0093d6e0(int i);
    unsigned char* FUN_0093d710(int i);
    hkBool* FUN_0093d690(int i);
    hkRotation* FUN_0093d730(int i);
    void** FUN_0093d670(int i);
    Accessor() {}
    Accessor(const hkVariant& src, const char* name) { FUN_0093d600(src, name); }
    Accessor FUN_0093d7a0(const char* name);
    hkClassAccessor FUN_0093d810();
    const hkClassMember* FUN_0093d790() const;
};

inline Accessor hkClassAccessor::member(const char* name) { return Accessor(m_variant, name); }


static __declspec(noinline) short FUN_00936710(const hkVariant& atom, const char* name)
{
    Accessor type;
    type.FUN_0093d600(atom, "type");
    int value;
    type.FUN_0093d790()->FUN_0093d8b0()->FUN_009b2360(name, &value);
    return static_cast<short>(value);
}

static __declspec(noinline) unsigned int FUN_009366b0(Accessor* atoms)
{
    const hkClass* cls = atoms->FUN_0093d810().m_variant.cls;
    const int count = cls->FUN_009b0630();
    const hkClassMember* lastMember = cls->FUN_009b0650(count - 1);
    const hkClassMember* info = atoms->FUN_0093d7a0(lastMember->name).FUN_0093d790();
    const int offset = info->offset;
    return offset + lastMember->FUN_0093d890()->FUN_009b0760();
}

static __declspec(noinline) void FUN_00937270(const hkVariant& atom, unsigned char isEnabled, unsigned char firstFrictionAxis,
                                              unsigned char numFrictionAxes, float maxFrictionTorque)
{
    if (DAT_0105f588 == -1)
        DAT_0105f588 = FUN_00936710(atom, "TYPE_ANG_FRICTION");
    Accessor field;
    field.FUN_0093d600(atom, "type");
    *field.FUN_0093d6e0(0) = DAT_0105f588;
    field.FUN_0093d600(atom, "isEnabled");
    *field.FUN_0093d710(0) = isEnabled;
    field.FUN_0093d600(atom, "firstFrictionAxis");
    *field.FUN_0093d710(0) = firstFrictionAxis;
    field.FUN_0093d600(atom, "numFrictionAxes");
    *field.FUN_0093d710(0) = numFrictionAxes;
    field.FUN_0093d600(atom, "maxFrictionTorque");
    *field.FUN_0093d6a0(0) = maxFrictionTorque;
}

static __declspec(noinline) void FUN_00937030(const hkVariant& atom, unsigned char isEnabled, unsigned char twistAxis,
                                              unsigned char refAxis, float minAngle, float maxAngle, float tau)
{
    if (DAT_0105f580 == -1)
        DAT_0105f580 = FUN_00936710(atom, "TYPE_TWIST_LIMIT");
    Accessor field;
    field.FUN_0093d600(atom, "type");
    *field.FUN_0093d6e0(0) = DAT_0105f580;
    field.FUN_0093d600(atom, "isEnabled");
    *field.FUN_0093d710(0) = isEnabled;
    field.FUN_0093d600(atom, "twistAxis");
    *field.FUN_0093d710(0) = twistAxis;
    field.FUN_0093d600(atom, "refAxis");
    *field.FUN_0093d710(0) = refAxis;
    field.FUN_0093d600(atom, "minAngle");
    *field.FUN_0093d6a0(0) = minAngle;
    field.FUN_0093d600(atom, "maxAngle");
    *field.FUN_0093d6a0(0) = maxAngle;
    field.FUN_0093d600(atom, "angularLimitsTauFactor");
    *field.FUN_0093d6a0(0) = tau;
}

static __declspec(noinline) void FUN_00937140(const hkVariant& atom, unsigned char isEnabled, unsigned char twistAxisInA,
                                              unsigned char refAxisInB, unsigned char mode, float minAngle,
                                              float maxAngle, float tau)
{
    if (DAT_0105f584 == -1)
        DAT_0105f584 = FUN_00936710(atom, "TYPE_CONE_LIMIT");
    Accessor field;
    field.FUN_0093d600(atom, "type");
    *field.FUN_0093d6e0(0) = DAT_0105f584;
    field.FUN_0093d600(atom, "isEnabled");
    *field.FUN_0093d710(0) = isEnabled;
    field.FUN_0093d600(atom, "twistAxisInA");
    *field.FUN_0093d710(0) = twistAxisInA;
    field.FUN_0093d600(atom, "refAxisInB");
    *field.FUN_0093d710(0) = refAxisInB;
    field.FUN_0093d600(atom, "angleMeasurementMode");
    *field.FUN_0093d710(0) = mode;
    field.FUN_0093d600(atom, "minAngle");
    *field.FUN_0093d6a0(0) = minAngle;
    field.FUN_0093d600(atom, "maxAngle");
    *field.FUN_0093d6a0(0) = maxAngle;
    field.FUN_0093d600(atom, "angularLimitsTauFactor");
    *field.FUN_0093d6a0(0) = tau;
}

static __declspec(noinline) void FUN_009369f0(const hkVariant& atom)
{
    if (DAT_0105f558 == -1)
        DAT_0105f558 = FUN_00936710(atom, "TYPE_BALL_SOCKET");
    Accessor field;
    field.FUN_0093d600(atom, "type");
    *field.FUN_0093d6e0(0) = DAT_0105f558;
}

void FUN_009367e0(const hkVariant& atom, const hkTransform& transformA, const hkTransform& transformB);
// The body of this writer has to be visible in this file: with only a declaration the caller schedules the
// by-value hkBool store after the twelve frame stores (100 bytes differ in the motor block).
__declspec(noinline) void FUN_00937470(const hkVariant& atom, hkBool isEnabled, short initializedOffset, short previousTargetAnglesOffset,
                                       const hkRotation& targetFrameAinB, void* const* motors)
{
    if (DAT_0105f590 == -1)
        DAT_0105f590 = FUN_00936710(atom, "TYPE_RAGDOLL_MOTOR");
    Accessor field;
    field.FUN_0093d600(atom, "type");
    *field.FUN_0093d6e0(0) = DAT_0105f590;
    field.FUN_0093d600(atom, "isEnabled");
    *field.FUN_0093d690(0) = isEnabled;
    field.FUN_0093d600(atom, "initializedOffset");
    *field.FUN_0093d6e0(0) = initializedOffset;
    field.FUN_0093d600(atom, "previousTargetAnglesOffset");
    *field.FUN_0093d6e0(0) = previousTargetAnglesOffset;
    field.FUN_0093d600(atom, "targetFrameAinB");
    *field.FUN_0093d730(0) = targetFrameAinB;
    field.FUN_0093d600(atom, "motors");
    *field.FUN_0093d670(0) = motors[0];
    field.FUN_0093d600(atom, "motors");
    *field.FUN_0093d670(1) = motors[1];
    field.FUN_0093d600(atom, "motors");
    *field.FUN_0093d670(2) = motors[2];
}

struct hkObjectUpdateTracker;

// Version patch for the ragdoll constraint data: the old basisA / basisB members become the atoms.
// LABEL (emits no code of its own, steers the stack layout only): three kinds of block scope in this function.
// Measured by removing one kind at a time: transformA/transformB at function scope 51 bytes off; the enum values
// at function scope 1222 bytes off (frame 0xf8 instead of 0x108); the three limit blocks merged 998 bytes off.
// The block around frame and motors is not needed for the match. No statement is dead, no local is unused.
void FUN_00939770(const hkVariant& oldObj, const hkVariant& newObj, hkObjectUpdateTracker& tracker)
{
    Accessor atoms;
    atoms.FUN_0093d600(newObj, "atoms");
    hkClassAccessor source;
    source.FUN_0093d7f0(oldObj);
    if (DAT_0105f5d4 == -1)
        DAT_0105f5d4 = FUN_009366b0(&atoms);

    hkVector4 pivot;
    hkVector4 twist;
    hkVector4 plane;
    hkVector4 cross;
    float* e;
    {
        hkTransform transformA;
        hkTransform transformB;
        {
            hkClassAccessor basis = source.member("basisA").FUN_0093d810();
            e = basis.member("pivot").FUN_0093d720(0);
            pivot.x = e[0];
            pivot.y = e[1];
            pivot.z = e[2];
            pivot.w = e[3];
            e = basis.member("twistAxis").FUN_0093d720(0);
            twist.x = e[0];
            twist.y = e[1];
            twist.z = e[2];
            twist.w = e[3];
            e = basis.member("planeAxis").FUN_0093d720(0);
            plane.x = e[0];
            plane.y = e[1];
            plane.z = e[2];
            plane.w = e[3];
            cross.setCross(twist, plane);
            transformA.m_rotation.m_col0 = twist;
            transformA.m_rotation.m_col1 = plane;
            transformA.m_rotation.m_col2 = cross;
            transformA.m_translation = pivot;
        }
        {
            hkClassAccessor basis = source.member("basisB").FUN_0093d810();
            e = basis.member("pivot").FUN_0093d720(0);
            pivot.x = e[0];
            pivot.y = e[1];
            pivot.z = e[2];
            pivot.w = e[3];
            e = basis.member("twistAxis").FUN_0093d720(0);
            twist.x = e[0];
            twist.y = e[1];
            twist.z = e[2];
            twist.w = e[3];
            e = basis.member("planeAxis").FUN_0093d720(0);
            plane.x = e[0];
            plane.y = e[1];
            plane.z = e[2];
            plane.w = e[3];
            cross.setCross(twist, plane);
            transformB.m_rotation.m_col0 = twist;
            transformB.m_rotation.m_col1 = plane;
            transformB.m_rotation.m_col2 = cross;
            transformB.m_translation = pivot;
        }
        FUN_009367e0(atoms.FUN_0093d7a0("transforms").FUN_0093d810().m_variant, transformA, transformB);
    }
    {
        hkRotation frame;
        frame.m_col0 = twist;
        frame.m_col1 = plane;
        frame.m_col2 = cross;
        void* motors[3];
        motors[0] = 0;
        motors[1] = 0;
        motors[2] = 0;
        FUN_00937470(atoms.FUN_0093d7a0("ragdollMotors").FUN_0093d810().m_variant, false, 0x60, 0x64, frame, motors);
    }
    FUN_00937270(atoms.FUN_0093d7a0("angFriction").FUN_0093d810().m_variant, 1, 0, 3,
                 *source.member("maxFrictionTorque").FUN_0093d6a0(0));
    {
        int axisTwist;
        int axisPlanes;
        {
            const hkClass* cls = atoms.FUN_0093d810().m_variant.cls;
            cls->FUN_009b05d0("Axis")->FUN_009b2360("AXIS_TWIST", &axisTwist);
        }
        {
            const hkClass* cls = atoms.FUN_0093d810().m_variant.cls;
            cls->FUN_009b05d0("Axis")->FUN_009b2360("AXIS_PLANES", &axisPlanes);
        }
        int aligned;
        int perpendicular;
        {
            const hkClass* cls = atoms.FUN_0093d810().member("coneLimit").FUN_0093d810().m_variant.cls;
            cls->FUN_009b05d0("MeasurementMode")->FUN_009b2360("ZERO_WHEN_VECTORS_ALIGNED", &aligned);
        }
        {
            const hkClass* cls = atoms.FUN_0093d810().member("coneLimit").FUN_0093d810().m_variant.cls;
            cls->FUN_009b05d0("MeasurementMode")->FUN_009b2360("ZERO_WHEN_VECTORS_PERPENDICULAR", &perpendicular);
        }
        {
            Accessor tau = source.member("angularLimitsTauFactor");
            Accessor maxA = source.member("twistMaxAngle");
            Accessor minA = source.member("twistMinAngle");
            FUN_00937030(atoms.FUN_0093d7a0("twistLimit").FUN_0093d810().m_variant, 1, axisTwist, axisPlanes,
                         *minA.FUN_0093d6a0(0), *maxA.FUN_0093d6a0(0), *tau.FUN_0093d6a0(0));
        }
        {
            Accessor tau = source.member("angularLimitsTauFactor");
            Accessor maxA = source.member("coneMinAngle");
            FUN_00937140(atoms.FUN_0093d7a0("coneLimit").FUN_0093d810().m_variant, 1, axisTwist, axisTwist, aligned,
                         -100.0f, *maxA.FUN_0093d6a0(0), *tau.FUN_0093d6a0(0));
        }
        {
            Accessor tau = source.member("angularLimitsTauFactor");
            Accessor maxA = source.member("planeMaxAngle");
            Accessor minA = source.member("planeMinAngle");
            FUN_00937140(atoms.FUN_0093d7a0("planesLimit").FUN_0093d810().m_variant, 1, axisTwist, axisPlanes, perpendicular,
                         *minA.FUN_0093d6a0(0), *maxA.FUN_0093d6a0(0), *tau.FUN_0093d6a0(0));
        }
    }
    FUN_009369f0(atoms.FUN_0093d7a0("ballSocket").FUN_0093d810().m_variant);
}
}   // namespace f3m_00939770

// @f3 0x00928190 (community match, verified in this file)
namespace f3m_00928190 {
namespace f3m_00928190 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
struct Q81Router {
    virtual void s00() throw(); virtual void s04() throw(); virtual void s08() throw();
    virtual void s0c() throw(); virtual void s10() throw();
    virtual void* allocateStack(int n) throw();
    virtual void releaseStack(void* p) throw();
    int r04, r08, r0c, r10, r14, r18, r1c;
    char* top;
    int r24;
    char* boundary;
    char* limit;
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
__forceinline Q81Router* Q81Mem() { return (Q81Router*)TlsGetValue(DAT_010f3170); }

template <class T> struct Q81LocalArray {
    T* data;
    int size;
    int capFlags;
    void* saved;
    __forceinline Q81LocalArray(int n) throw() {
        data = 0; size = 0; capFlags = (int)0x80000000;
        Q81Router* r = Q81Mem();
        int bytes = (n * (int)sizeof(T) + 0x10) & ~0xf;
        char* p = r->top;
        char* e = p + bytes;
        void* m;
        if (e <= r->limit) { r->top = e; m = p; }
        else m = r->allocateStack(bytes);
        data = (T*)m;
        capFlags = n | 0x80000000;
        saved = m;
    }
    __forceinline void Release() throw() {
        char* p = (char*)saved;
        Q81Router* r = Q81Mem();
        r->top = p;
        if (p == r->boundary) r->releaseStack(p);
        if (!(capFlags & 0x80000000)) {
            int cap = capFlags & 0x3fffffff;
            Q81Mem()->FUN_008f6d90(data, cap * (int)sizeof(T), 0x17);
        }
    }
};

struct __declspec(align(16)) Q81Aabb { float v[8]; };
struct Q81Pair { void* a; void* b; };

struct Q81Phantom {
    virtual void s00() throw(); virtual void s04() throw(); virtual void s08() throw(); virtual void s0c() throw();
    virtual void s10() throw(); virtual void s14() throw();
    virtual void calcAabb(Q81Aabb* out) throw();
    int r04, r08, r0c, r10, r14, r18, r1c, r20;
    int handle;
};
struct Q81BroadPhase {
    virtual void s00() throw(); virtual void s04() throw(); virtual void s08() throw(); virtual void s0c() throw();
    virtual void querySingleAabb(int* handle, Q81Aabb* aabb, Q81LocalArray<Q81Pair>* pairs) throw();
};
struct Q81Dispatcher { void FUN_00984c50(Q81Pair* pairs, int n, void* filter) throw(); };
struct Q81World {
    char p00[0x54];
    Q81BroadPhase* broadPhase;
    Q81Dispatcher* dispatcher;
    char p5c[0x14];
    char* filter;
    char p74[0x284];
    int querySize;
};
}

// pdb: hkpWorldOperationUtil::addPhantomBP | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_addPhantomBP(void* world, void* phantom)
{
    using namespace f3m_00928190;
    Q81World* w = (Q81World*)world;
    Q81Phantom* p = (Q81Phantom*)phantom;
    Q81LocalArray<Q81Pair> pairs(w->querySize);
    Q81Aabb aabb;
    p->calcAabb(&aabb);
    w->broadPhase->querySingleAabb(&p->handle, &aabb, &pairs);
    if (pairs.size) {
        void* filter = w->filter ? w->filter + 8 : 0;
        w->dispatcher->FUN_00984c50(pairs.data, pairs.size, filter);
    }
    pairs.Release();
}
}   // namespace f3m_00928190

// @f3 0x0092e3c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern int DAT_00e37244;
extern int DAT_00e3365c;
extern float DAT_0104da48;
namespace f3m_0092e3c0 {
struct QMem92e
{
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
    void* FUN_008f6d30(int bytes, int tag) throw();
};
__declspec(dllimport) QMem92e* __stdcall FUN_00d9b080(int) throw();
namespace q92e3c0 {
typedef QMem92e QMem;

struct __declspec(align(16)) QVec
{
    float x, y, z, w;
    QVec& operator=(const QVec& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct QXf
{
    QVec c0, c1, c2, t;
};
QXf* FUN_0096c400();

struct QShape
{
    int vptr;
    int unk04;
    int unk08;
    int type;
};
struct __declspec(align(16)) QSphere : QShape
{
    float radius;
    void FUN_00970f60(float r);
};
struct QCdBody
{
    QShape* shape;
    int shapeKey;
    const void* motion;
    const QCdBody* parent;
    QCdBody(QShape* s, const void* m) { shape = s; motion = m; parent = 0; shapeKey = -1; }
};
struct QInput
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
    void FUN_00921790(const QInput* src);
};
struct QCollector
{
    void* vptr;
    float earlyOut;
    int unk08;
    int unk0c;
    QVec position;
    QVec normal;
    const void* rootA;
    int keyA;
    const void* rootB;
    int keyB;
    QVec unweldedNormal;
};
typedef void (__cdecl *QFn)(const QCdBody*, const QCdBody*, const QInput*, QCollector*);
struct QAgentFuncs
{
    QFn fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct QDispatcher
{
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
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char agent2Types[32][32];
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    QAgentFuncs agentFuncs[32];
};
struct QWorld
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
    QInput* input;
    int unk70;
    QDispatcher* dispatcher;
};
struct QEntity
{
    int unk00;
    int unk04;
    QWorld* world;
    int unk0c;
    QCdBody collidable;
};
struct QArray
{
    int* data;
    int size;
    int capAndFlags;
};
class QAction
{
public:
    void* vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    const char* name;
    int unk18;
    int unk1c;
    void FUN_009ae990(QEntity* e, int userData);
};
class QMouseSpring : public QAction
{
public:
    QVec pos;
    QVec mouse;
    float damping;
    float elasticity;
    float maxRel;
    float objDamping;
    int shapeKey;
    QArray cb;
    QMouseSpring* FUN_0092e3c0(QVec* apPos, QVec* apMouse, float afDamping, float afElasticity, float afObjDamping,
                               QEntity* apEnt, QArray* apArr);
};

// pdb: hkpMouseSpringAction::hkpMouseSpringAction | hkpMouseSpringAction.obj | fnv360_0822_debug, call_seq, high
// pdb params: positionInRbLocal, mousePositionInWorld, springDamping, springElasticity, objectDamping, rb, appliedCallbacks
QMouseSpring* QMouseSpring::FUN_0092e3c0(QVec* apPos, QVec* apMouse, float afDamping, float afElasticity,
                                         float afObjDamping, QEntity* apEnt, QArray* apArr)
{
    FUN_009ae990(apEnt, 0);
    vptr = &DAT_00e37244;
    pos = *apPos;
    mouse = *apMouse;
    damping = afDamping;
    elasticity = afElasticity;
    objDamping = afObjDamping;
    *(int* volatile*)&cb.data = 0;
    *(volatile int*)&cb.size = 0;
    *(volatile int*)&cb.capAndFlags = 0x80000000;
    *(volatile float*)&maxRel = 250.0f;
    if (apArr)
    {
        if ((cb.capAndFlags & 0x3fffffff) < apArr->size)
        {
            int cap = cb.capAndFlags & 0x3fffffff;
            if ((cb.capAndFlags & 0x80000000) == 0)
            {
                QMem* m = FUN_00d9b080(DAT_010f3170);
                m->FUN_008f6d90(cb.data, cap * 4, 0x17);
            }
            QMem* m = FUN_00d9b080(DAT_010f3170);
            cb.data = (int*)m->FUN_008f6d30(apArr->size * 4, 0x17);
            cb.capAndFlags = (cb.capAndFlags & 0x40000000) | apArr->size;
        }
        int cnt = apArr->size;
        cb.size = cnt;
        int* dst = cb.data;
        int* src = apArr->data;
        for (int i = 0; i < cnt; i++)
            dst[i] = src[i];
    }
    QWorld* world = apEnt->world;
    shapeKey = -1;
    if (world)
    {
        QSphere sph;
        sph.FUN_00970f60(1.0f);
        QXf xf;
        QXf* ident = FUN_0096c400();
        xf.c0 = ident->c0;
        xf.c1 = ident->c1;
        xf.c2 = ident->c2;
        xf.t = *apMouse;
        QCdBody body(&sph, &xf);
        QDispatcher* disp = world->dispatcher;
        QFn fn = disp->agentFuncs[disp->agent2Types[sph.type][apEnt->collidable.shape->type]].fn;
        QInput in;
        in.FUN_00921790(world->input);
        QCollector coll;
        coll.vptr = &DAT_00e3365c;
        coll.normal.w = DAT_0104da48;
        coll.earlyOut = DAT_0104da48;
        coll.rootA = 0;
        fn(&body, &apEnt->collidable, &in, &coll);
        if (coll.rootA)
            shapeKey = coll.keyB;
    }
    name = "hkpMouseSpringAction";
    return this;
}
}
}   // namespace f3m_0092e3c0

// @f3 0x00930640 (community match, verified in this file)
namespace f3m_00930640 {


struct Row {
    float x, y, z, w;
    void FUN_00477880(float* a, float* b);
    void FUN_008d2970(float* a, float* b);
};

__declspec(align(16)) struct Four {
    float x, y, z, w;
};

struct unk930640 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    Row r20, r30, r40, r50, r60, r70, r80, r90;
    void FUN_00930640(float* a, float* b, float* c, float* v);
};

void unk930640::FUN_00930640(float* a, float* b, float* c, float* v)
{
    float ax = fabsf(v[0]);
    float ay = fabsf(v[1]);
    float az = fabsf(v[2]);
    int i = 0, j = 1, k = 2;
    if (ay < ax) {
        ax = ay;
        j = 0;
        i = k - 1;
    }
    if (az < ax)
        k = i;
    Four tv;
    float zero = 0.0f;
    tv.x = tv.y = tv.z = tv.w = zero;
    float* t = &tv.x;
    t[j] = v[k];
    t[k] = -v[j];
    float sum = tv.x * tv.x + tv.y * tv.y + tv.z * tv.z;
    float inv;
    if (sum != zero)
        inv = 1.0f / sqrtf(sum);
    else
        inv = zero;
    t[0] *= inv; t[1] *= inv; t[2] *= inv; t[3] *= inv;
    Four cv;
    float* cr = &cv.x;
    cr[0] = v[1] * t[2] - v[2] * t[1];
    cr[1] = v[2] * t[0] - v[0] * t[2];
    cr[2] = v[0] * t[1] - v[1] * t[0];
    cr[3] = zero;
    r20.FUN_00477880(a, v);
    r30.FUN_00477880(a, t);
    r40.FUN_00477880(a, cr);
    r50.FUN_008d2970(a, c);
    r60.FUN_00477880(b, v);
    r70.FUN_00477880(b, t);
    r80.FUN_00477880(b, cr);
    r90.FUN_008d2970(b, c);
}
}   // namespace f3m_00930640

// @f3 0x00931d40 (community match, verified in this file)
namespace f3m_00931d40 {
struct __declspec(align(16)) QVec4 {
    float x, y, z, w;
};
void FUN_00931d40(const float* pts, int count, int stride, QVec4* out)
{
    QVec4 mn;
    mn.x = pts[0]; mn.y = pts[1]; mn.z = pts[2];
    QVec4 mx;
    mx.x = mn.x; mx.y = mn.y; mx.z = mn.z; mx.w = mn.w;
    for (int i = 1; i < count; i++) {
        QVec4 v;
        const float* q = (const float*)((const char*)pts + i * stride);
        v.x = q[0]; v.y = q[1]; v.z = q[2];
        mn.x = (mn.x < v.x) ? mn.x : v.x;
        mn.y = (mn.y < v.y) ? mn.y : v.y;
        mn.z = (mn.z < v.z) ? mn.z : v.z;
        mn.w = (mn.w < v.w) ? mn.w : v.w;
        mx.x = (mx.x > v.x) ? mx.x : v.x;
        mx.y = (mx.y > v.y) ? mx.y : v.y;
        mx.z = (mx.z > v.z) ? mx.z : v.z;
        mx.w = (mx.w > v.w) ? mx.w : v.w;
    }
    out[0].x = mn.x; out[0].y = mn.y; out[0].z = mn.z; out[0].w = 0.0f;
    out[1].x = mx.x; out[1].y = mx.y; out[1].z = mx.z; out[1].w = 0.0f;
}
}   // namespace f3m_00931d40

// @f3 0x00933010 (community match, verified in this file)
namespace f3m_00933010 {
struct NodeView;

struct __declspec(align(8)) NumView
{
    int m_off;
    void* m_node;
    NumView(const void* src, const char* name);
    int& operator[](int index);
};

struct __declspec(align(8)) MemberView
{
    int m_off;
    void* m_node;
    MemberView(const void* src, const char* name);
    void*& operator[](int index);
    NodeView* GetNode();
};

struct NodeView
{
    int m_unk0;
    void* m_unk4;
    void* GetField();
};

struct __declspec(align(8)) MemberValue
{
    void* m_value;
    void* volatile m_type;
};

void FUN_932fc0(void* value, void* type, void* ctx);

// pdb: hkDataObjectNative::asObject | hkDataObjectNative.obj | fnv360_0822_debug, caller_sim + skyrim(caller_sim), high
void hkDataObjectNative_asObject(const void* a, const void* b, void* ctx)
{
    NumView t1(a, "numDeclaredMembers");
    NumView t2(b, "numDeclaredMembers");
    int n = t1[0];
    MemberView u1(a, "declaredMembers");
    MemberView u2(b, "declaredMembers");
    void* p = u1[0];
    u2[0];
    MemberValue value;
    value.m_type = u1.GetNode()->GetField();
    u2.GetNode()->GetField();
    for (int i = 0; i < n; i++)
    {
        value.m_value = static_cast<void**>(p)[i];
        FUN_932fc0(&value.m_value, &t2, ctx);
    }
}
}   // namespace f3m_00933010

// @f3 0x00933510 (community match, verified in this file)
extern const char DAT_00e3ee04;
namespace f3m_00933510 {
namespace f3m_00933510 {
struct Klass { int FUN_009b0760() const; };
struct ClassMember { const Klass* FUN_0093d890() const; };
struct Variant {
    void* object;
    const Klass* klass;
};
struct ArrayRef { char* data; int count; };
class FUN_0093d600 {
public:
    void* object;
    const void* member;
    FUN_0093d600(void* obj, const void* member);
    ArrayRef* FUN_0093d760(int index) const;
    unsigned short* FUN_0093d6e0(int index) const;
    Variant FUN_0093d810() const;
    const ClassMember* FUN_0093d790() const;
};
static __declspec(noinline) void FUN_009334b0(Variant* a, Variant* b, bool flag)
{
    FUN_0093d600 ma(a, &DAT_00e3ee04);
    FUN_0093d600 mb(b, &DAT_00e3ee04);
    *mb.FUN_0093d6e0(0) = *ma.FUN_0093d6e0(0);
    if (flag)
        *mb.FUN_0093d6e0(0) |= 0x800;
}
static __declspec(noinline) void FUN_00933510(const void* member, Variant* a, Variant* b, bool flag)
{
    FUN_0093d600 ma(a, member);
    FUN_0093d600 mb(b, member);
    int count = ma.FUN_0093d760(0)->count;
    Variant va;
    va.klass = ma.FUN_0093d810().klass;
    Variant vb;
    vb.klass = mb.FUN_0093d810().klass;
    int sizeA = ma.FUN_0093d790()->FUN_0093d890()->FUN_009b0760();
    int sizeB = mb.FUN_0093d790()->FUN_0093d890()->FUN_009b0760();
    for (int i = 0; i < count; i++) {
        va.object = ma.FUN_0093d760(0)->data + i * sizeA;
        vb.object = mb.FUN_0093d760(0)->data + i * sizeB;
        FUN_009334b0(&va, &vb, flag);
    }
}
void* volatile g_member; Variant* volatile g_a; Variant* volatile g_b; volatile bool g_flag;
void caller_of_00933510()
{
    FUN_00933510(g_member, g_a, g_b, g_flag);
}
}
}   // namespace f3m_00933510

// @f3 0x009352a0 (community match, verified in this file)
namespace f3m_009352a0 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_009352a0 {

extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct N52Heap {
    void* FUN_008f6d30(int bytes, int category) throw();
    void FUN_008f6d90(void* memory, int bytes, int category) throw();
};
void* FUN_009234e0(void* dst, const void* src, unsigned int n) throw();
struct N52Buffer {
    char* data;
    int size;
    int capacityAndFlags;
    N52Buffer() : data(0), size(0), capacityAndFlags(0x80000000) {}
    void Free() {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            N52Heap* heap = (N52Heap*)DAT_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity, 0x17);
        }
    }
};
union N52Pair { __int64 packed; struct { void* data; int size; }; };
struct N52Array { void* data; int size; int capacityAndFlags; };
struct N52Raw { void* object; const void* type; };
struct __declspec(align(8)) FUN_0093d7f0 {
    void* object;
    const void* type;
    FUN_0093d7f0() {}
    FUN_0093d7f0(const N52Raw&) throw();
    FUN_0093d7f0(void*, const void*) throw();
};
struct __declspec(align(8)) FUN_0093d600 {
    void* address;
    const void* member;
    FUN_0093d600(const FUN_0093d7f0&, const char*) throw();
    FUN_0093d7f0 FUN_0093d810() throw();
    N52Array* FUN_0093d650() throw();
    int& FUN_0093d6b0(int index) throw();
    unsigned char& FUN_0093d710(int index) throw();
    N52Pair& FUN_0093d760(int index) throw();
    void* FUN_0093d660() throw();
};
struct N52Tracker {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void AddChunk10(void*, int, int) throw();
    virtual void PointedBy14(void*, void*) throw();
};
inline void* N52Alloc(int size, int category)
{
    N52Heap* heap = (N52Heap*)DAT_00d9b080(DAT_010f3170);
    return heap->FUN_008f6d30(size, category);
}
inline int N52Int(const FUN_0093d7f0& v, const char* name)
{
    FUN_0093d600 f(v, name);
    return f.FUN_0093d6b0(0);
}
inline FUN_0093d7f0 N52Member(const FUN_0093d7f0& v, const char* name)
{
    FUN_0093d600 f(v, name);
    return f.FUN_0093d810();
}
inline int N52ArraySize(const FUN_0093d7f0& v, const char* name)
{
    FUN_0093d600 f(v, name);
    return f.FUN_0093d650()->size;
}
struct N52Descriptor { unsigned char bitWidth; unsigned char preserved; float scale; float offset; };
int FUN_00934fd0(int, const N52Descriptor&) throw();
void FUN_00935040(N52Raw*, N52Raw*, N52Tracker*) throw();
int FUN_00935c10(const FUN_0093d600&, int, N52Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935d90(const FUN_0093d600&, N52Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935c90(const FUN_0093d600&, N52Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935e10(const FUN_0093d600&, int, int, N52Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935d10(const FUN_0093d600&, N52Buffer&, int, const FUN_0093d600&) throw();

void FUN_009352a0(N52Raw* oldObject, N52Raw* newObject, N52Tracker* tracker)
{
    FUN_0093d7f0 oldVariant(*oldObject);
    FUN_0093d7f0 newVariant(*newObject);
    FUN_00935040(oldObject, newObject, tracker);
    FUN_0093d7f0 oldFormat = N52Member(oldVariant, "qFormat");
    FUN_0093d7f0 newFormat = N52Member(newVariant, "qFormat");
    FUN_0093d600 offsetField(oldFormat, "offset");
    int dimensions = offsetField.FUN_0093d650()->size;
    {
        FUN_0093d600 f(newFormat, "numD");
        f.FUN_0093d6b0(0) = dimensions;
    }
    N52Descriptor descriptor;
    N52Buffer buffer;
    int offset;
    {
        FUN_0093d600 destination(newFormat, "offsetIdx");
        FUN_0093d600 source(oldFormat, "offset");
        offset = FUN_00935c10(source, dimensions * 4, buffer, 0, destination);
    }
    {
        FUN_0093d600 destination(newFormat, "scaleIdx");
        FUN_0093d600 source(oldFormat, "scale");
        offset += FUN_00935c10(source, dimensions * 4, buffer, offset, destination);
    }
    {
        FUN_0093d600 destination(newVariant, "staticDOFsIdx");
        FUN_0093d600 source(oldVariant, "staticDOFs");
        offset += FUN_00935d90(source, buffer, offset, destination);
    }
    {
        FUN_0093d600 destination(newVariant, "staticMaskIdx");
        FUN_0093d600 source(oldVariant, "staticMask");
        offset += FUN_00935c90(source, buffer, offset, destination);
    }
    {
        FUN_0093d600 destination(newFormat, "bitWidthIdx");
        FUN_0093d600 maximum(newFormat, "maxBitWidth");
        FUN_0093d600 source(oldFormat, "bitWidth");
        offset += FUN_00935e10(source, dimensions, maximum.FUN_0093d710(0), buffer, offset, destination);
    }
    {
        FUN_0093d600 destination(newVariant, "quantizedDataIdx");
        FUN_0093d600 source(oldVariant, "quantizedData");
        FUN_00935d10(source, buffer, offset, destination);
    }
    int lastBlockSize = 0;
    int remainder;
    {
        FUN_0093d600 numberOfPoses(newVariant, "numberOfPoses");
        FUN_0093d600 blockSize(newVariant, "blockSize");
        remainder = numberOfPoses.FUN_0093d6b0(0) % blockSize.FUN_0093d6b0(0);
    }
    {
        FUN_0093d600 f(newFormat, "preserved");
        descriptor.preserved = f.FUN_0093d710(0);
    }
    {
        const char* data = buffer.data;
        FUN_0093d600 bitWidthIdx(newFormat, "bitWidthIdx");
        const char* bitWidths = data + bitWidthIdx.FUN_0093d6b0(0);
        for (unsigned int i = 0; i < (unsigned int)dimensions; ++i) {
            descriptor.bitWidth = bitWidths[i];
            lastBlockSize += FUN_00934fd0(remainder, descriptor);
        }
    }
    {
        FUN_0093d600 f(newVariant, "lastBlockSize");
        f.FUN_0093d6b0(0) = lastBlockSize;
    }
    N52Pair* output;
    {
        FUN_0093d600 f(newVariant, "dataBuffer");
        output = &f.FUN_0093d760(0);
    }
    output->size = buffer.size;
    output->data = N52Alloc(buffer.size, 0x38);
    FUN_009234e0(output->data, buffer.data, output->size);
    {
        FUN_0093d600 f(newVariant, "dataBuffer");
        N52Tracker& t = *tracker;
        t.PointedBy14(output->data, f.FUN_0093d660());
    }
    tracker->AddChunk10(output->data, output->size, 0x38);
    buffer.Free();
}

}
}   // namespace f3m_009352a0

// @f3 0x009364e0 (community match, verified in this file)
extern const char str_00e38c90;
extern const char str_00e462c8;
extern const char str_00e6e7c4;
extern float g_float_00dbf91c;
namespace f3m_009364e0 {
struct __declspec(align(8)) MemberAccessor {
    void* object;
    const void* member;
    void __thiscall FUN_0093d600(void* owner, const char* name);
    char* __thiscall FUN_0093d640(char* valid);
    signed char* __thiscall FUN_0093d700(int index);
    char* __thiscall FUN_0093d690(int index);
    float* __thiscall FUN_0093d6a0(int index);
};

void __cdecl FUN_009364e0(void* source, void* destination)
{
    MemberAccessor destinationMode;
    MemberAccessor sourceMode;
    MemberAccessor destinationValue;
    MemberAccessor sourceValue;
    char valid;

    destinationMode.FUN_0093d600(destination, &str_00e38c90);
    sourceMode.FUN_0093d600(source, &str_00e38c90);
    if (!*destinationMode.FUN_0093d640(&valid)) goto values;
    if (!*sourceMode.FUN_0093d640(&valid)) goto values;
    switch (*sourceMode.FUN_0093d700(0)) {
    case 1: case 2: case 3:
        *destinationMode.FUN_0093d700(0) = 1;
        break;
    case 4: case 5: case 6:
        *destinationMode.FUN_0093d700(0) = 2;
        break;
    case 7: case 8:
        *destinationMode.FUN_0093d700(0) = 0;
        break;
    case 9:
        *destinationMode.FUN_0093d700(0) = 3;
        break;
    }
values:
    destinationValue.FUN_0093d600(destination, &str_00e462c8);
    sourceValue.FUN_0093d600(source, &str_00e6e7c4);
    if (!*sourceValue.FUN_0093d640(&valid)) return;
    if (!*destinationValue.FUN_0093d640(&valid)) return;
    if (*sourceValue.FUN_0093d690(0) == 1) {
        *destinationValue.FUN_0093d6a0(0) = g_float_00dbf91c;
    } else {
        *destinationValue.FUN_0093d6a0(0) = 0.0f;
    }
}
}   // namespace f3m_009364e0

// @f3 0x0093cae0 (community match, verified in this file)
extern char DAT_00e37e58;
namespace f3m_0093cae0 {
namespace f3m_0093cae0 {
struct Q93Lookup {
    void* object;
    int index;
    Q93Lookup(void* obj, const char* name);
    bool* FUN_0093d640(bool* out);
    int* FUN_0093d670(int index);
};
// pdb: hkDataObjectNative::hasMember | hkDataObjectNative.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|vtable) + skyrim(caller_sim), high
static __declspec(noinline) void hkDataObjectNative_hasMember(void* object, const char* name)
{
    Q93Lookup lookup(object, name);
    bool valid;
    if (*lookup.FUN_0093d640(&valid))
        *lookup.FUN_0093d670(0) = 0;
}
void __cdecl Caller_0093cae0(int unused, void* object) { hkDataObjectNative_hasMember(object, &DAT_00e37e58); }
}
}   // namespace f3m_0093cae0

// @f3 0x009344d0 (community match, verified in this file)
namespace f3m_009344d0 {
struct Pair9344d0 {
    void* data;
    void* type;
    Pair9344d0() {}
};
struct Field9344d0 {
    void* unk00;
    int unk04;
    Pair9344d0 FUN_0093d810();
};
void __cdecl FUN_00934440(Pair9344d0* from, Pair9344d0* to, int value);
static __declspec(noinline) void FUN_009344d0(Field9344d0* a, Field9344d0* b, int value)
{
    Pair9344d0 from;
    from.data = a->FUN_0093d810().data;
    from.type = a->FUN_0093d810().type;
    Pair9344d0 to;
    to.data = b->FUN_0093d810().data;
    to.type = b->FUN_0093d810().type;
    FUN_00934440(&from, &to, value);
}
void FUN_9344d0_caller(Field9344d0* a, Field9344d0* b, int value)
{
    FUN_009344d0(a, b, value);
}
}   // namespace f3m_009344d0

// @f3 0x00935ea0 (community match, verified in this file)
namespace f3m_00935ea0 {
namespace n935ea0 {
struct Member {
    int FUN_0093dac0();
};
struct Field {
    char* data;
    int count;
    Member* FUN_0093d790();
    Field* FUN_0093d660();
};
}

static __declspec(noinline) void FUN_00935ea0(n935ea0::Field* src, n935ea0::Field* dst)
{
    int srcStride = src->FUN_0093d790()->FUN_0093dac0();
    int dstStride = dst->FUN_0093d790()->FUN_0093dac0();
    n935ea0::Field* srcArr = src->FUN_0093d660();
    n935ea0::Field* dstArr = dst->FUN_0093d660();
    char* srcData = srcArr->data;
    int count = srcArr->count;
    char* dstData = dstArr->data;
    for (int i = 0; i < count; ++i) {
        *(int*)dstData = *(int*)srcData;
        srcData += srcStride;
        dstData += dstStride;
    }
}

namespace n935ea0 {
n935ea0::Field* volatile g_src;
n935ea0::Field* volatile g_dst;
void caller_of_FUN_00935ea0()
{
    FUN_00935ea0(g_src, g_dst);
}
}
}   // namespace f3m_00935ea0

// @f3 0x009332d0 (community match, verified in this file)
extern const char g_fieldName_009332d0[];
namespace f3m_009332d0 {
namespace fn_009332d0 {
struct FieldPair {
    void* data;
    void* type;
};
struct FieldAcc {
    void* m_obj;
    int m_offset;
    FieldAcc(void* obj, const char* name);
    FieldPair GetPair();
};
typedef void (__cdecl* ConvertFn)(FieldPair*, FieldPair*, int);
void __cdecl ConvertCallback(FieldPair* a, FieldPair* b, int ctx);

static __declspec(noinline) void FUN_009332d0(
    void* source, void* destination, const char* memberName, int context, ConvertFn convert)
{
    FieldAcc oldMember(source, memberName);
    FieldAcc newMember(destination, memberName);
    FieldPair oldValue;
    oldValue.type = oldMember.GetPair().type;
    oldValue.data = oldMember.GetPair().data;
    FieldPair newValue;
    newValue.type = newMember.GetPair().type;
    newValue.data = newMember.GetPair().data;
    convert(&oldValue, &newValue, context);
}

void __cdecl RunFieldConvert(void* src, void* dst, int ctx) {
    FUN_009332d0(src, dst, g_fieldName_009332d0, ctx, ConvertCallback);
}
}
}   // namespace f3m_009332d0

// @f3 0x0093e500 (community match, verified in this file)
namespace f3m_0093e500 {
namespace n93e500 {
struct F3FieldObj;
struct F3Inner;
struct F3Functor {
    F3Inner* inner;
};
struct F3Inner {
    char pad00[0x10];
    F3FieldObj* (F3Functor::* mfn)(int);
};
struct F3FieldObj {
    int FUN_009b0490();
};
struct F3Pair {
    int key;
    F3FieldObj* field;
};

struct __declspec(align(16)) A16 { float v[4]; };

static __declspec(noinline) void FUN_0093e500(void* basev, int count, int functorv) {
    if (count > 0) {
        F3FieldObj** slot = &((F3Pair*)basev)->field;
        F3Functor* f = (F3Functor*)functorv;
        int n = count;
        do {
            if (*slot != 0) {
                *slot = (f->*(f->inner->mfn))((*slot)->FUN_009b0490());
            }
            slot = (F3FieldObj**)((char*)slot + sizeof(F3Pair));
        } while (--n != 0);
    }
}

void caller_of_FUN_0093e500(void* basev, int count, int functorv)
{
    FUN_0093e500(basev, count, functorv);
}
}
}   // namespace f3m_0093e500

// @f3 0x00935000 (community match, verified in this file)
namespace f3m_00935000 {
namespace animation_version {
enum hkResult { HK_SUCCESS = 0, HK_FAILURE = 1 };
class hkClassEnum {
public:
    hkResult FUN_009b2360(const char* name, int* value) const;
};
class hkClassMember {
public:
    const hkClassEnum& FUN_0093d8b0() const;
};
class hkClass {
public:
    const char* FUN_009b0490() const;
};
struct hkVariant {
    void* object;
    const hkClass* type;
};
class hkObjectUpdateTracker;
class FUN_0093d600 {
    void* address;
    const hkClassMember* member;
public:
    FUN_0093d600(const hkVariant& object, const char* name);
    const hkClassMember& FUN_0093d790() const;
    int& FUN_0093d6b0(int index = 0) const;
};
typedef FUN_0093d600 hkClassMemberAccessor;
class FUN_0093d7f0 {
    hkVariant object;
public:
    explicit FUN_0093d7f0(hkVariant& source);
    hkClassMemberAccessor member(const char* name) const {
        return hkClassMemberAccessor(object, name);
    }
};
typedef FUN_0093d7f0 hkClassAccessor;
int __cdecl hkString_strCmp(const char* a, const char* b);

// pdb: hkClassMember::getAttribute | hkClassMember.obj | fnv360_0822_retail, call_gap, low
// pdb params: id
static __declspec(noinline) int FUN_00935000(const hkClassAccessor& object, const char* name)
{
    hkClassMemberAccessor field = object.member("type");
    int value;
    field.FUN_0093d790().FUN_0093d8b0().FUN_009b2360(name, &value);
    return value;
}

void __cdecl updateSkeletalAnimation(hkVariant&, hkVariant& newObject, hkObjectUpdateTracker&)
{
    hkClassAccessor data(newObject);
    int& type = data.member("type").FUN_0093d6b0();
    if (hkString_strCmp(newObject.type->FUN_009b0490(), "hkInterleavedSkeletalAnimation") == 0)
    {
        hkClassAccessor current(newObject);
        type = FUN_00935000(current, "HK_INTERLEAVED_ANIMATION");
    }
    else if (hkString_strCmp(newObject.type->FUN_009b0490(), "hkDeltaCompressedSkeletalAnimation") == 0)
    {
        hkClassAccessor current(newObject);
        type = FUN_00935000(current, "HK_DELTA_COMPRESSED_ANIMATION");
    }
    else if (hkString_strCmp(newObject.type->FUN_009b0490(), "hkWaveletSkeletalAnimation") == 0)
    {
        hkClassAccessor current(newObject);
        type = FUN_00935000(current, "HK_WAVELET_COMPRESSED_ANIMATION");
    }
    else
    {
        hkClassAccessor current(newObject);
        type = FUN_00935000(current, "HK_UNKNOWN_ANIMATION");
    }
}
}
}   // namespace f3m_00935000
