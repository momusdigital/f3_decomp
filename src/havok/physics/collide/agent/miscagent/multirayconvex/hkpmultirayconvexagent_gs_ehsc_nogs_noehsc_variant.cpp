#include "f3_common.h"
// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void FUN_00d374f0(int a, int b, int c, int d);
void FUN_00d37860(int a, int b, int c, int d);
void FUN_00d378a0(int a, int b, int c, int d);
void FUN_00d37280(int a, int b, int c, int d);
struct S_00d37860_Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    bool m_bHit;
    S_00d37860_Base() : m_bHit(false) {}
};
struct S_00d37860_Collector : S_00d37860_Base {
    int m_iFilter;
    S_00d37860_Collector(int filter) : m_iFilter(filter) {}
    virtual void f1();
};
void FUN_00d374f0(void* b, void* a, void* c, S_00d37860_Collector* collector);
void FUN_00d37860(void* a, void* b, void* c, int filter);
struct Payload { const char* name; float value; int id; };
void FUN_00d37280(int, int, int, Payload*);
void FUN_00d378a0(int a, int b, int c, int d);
struct D376B0Allocator;
struct D376B0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D376B0Allocator* m_pStreamAllocator;

    D376B0Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D376B0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(D376B0Allocator* alloc, void* array, int numElements, int sizeElem);
class D376B0ReferencedObject {
public:
    D376B0ReferencedObject() : m_sReferenceCount(1) {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
// hkInplaceArray<hkUint16, 4> without a destructor (Havok was built without EH).
struct D376B0IndexArray {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned short m_kStorage[4];

    D376B0IndexArray() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000004) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void SetSizeAndGrow(int n)
    {
        D376B0Allocator& alloc = FUN_00c85750().heap();
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(unsigned short));
        }
        m_iElementCount = n;
    }
};
class D376B0Filter : public D376B0ReferencedObject {
public:
    D376B0Filter(void* userData) : m_ulUserData(userData) {}

    void* m_ulUserData;
};

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include <windows.h>

// hkVector4 stand-in: 4 floats (an __m128 member would add a GS cookie)
struct __declspec(align(16)) S_00d374f0_Vector4 {
    float x, y, z, w;
    __m128& q() { return reinterpret_cast<__m128&>(*this); }
    const __m128& q() const { return reinterpret_cast<const __m128&>(*this); }
};

struct __declspec(align(16)) S_00d374f0_Transform {
    S_00d374f0_Vector4 m_kColumn0;
    S_00d374f0_Vector4 m_kColumn1;
    S_00d374f0_Vector4 m_kColumn2;
    S_00d374f0_Vector4 m_vTranslation;
    void FUN_00cb22f0(const S_00d374f0_Transform& a, const S_00d374f0_Transform& b);
};

struct S_00d374f0_Bool {
    char m_cBooleanValue;
    S_00d374f0_Bool() {}
    operator bool() const { return m_cBooleanValue != 0; }
};

struct __declspec(align(16)) S_00d374f0_RayInput {
    S_00d374f0_Vector4 m_vFrom;
    S_00d374f0_Vector4 m_vTo;
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
    S_00d374f0_RayInput() : m_uiFilterInfo(0), m_pRayShapeCollectionFilter(0) {}
};

struct __declspec(align(16)) S_00d374f0_RayOutputBase {
    S_00d374f0_Vector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1c;
    S_00d374f0_RayOutputBase() { m_fHitFraction = 1.0f; m_iExtraInfo = -1; }
};

struct __declspec(align(16)) S_00d374f0_RayOutput : S_00d374f0_RayOutputBase {
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    S_00d374f0_RayOutput() { m_uiShapeKeyIndex = 0; m_uiShapeKeys[0] = 0xffffffff; }
};

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned int DAT_0126835c;
extern char DAT_010ceda8[];
extern char DAT_010c41f8[];
struct Event378 { const char* tag; unsigned time; unsigned other; };
struct Timer378 { int unused; Event378* current; int unknown; Event378* end; };
inline void timer378(const char* tag) {
    Timer378* timer = (Timer378*)TlsGetValue(DAT_0126835c);
    if (timer->current < timer->end) {
        Event378* e = timer->current;
        e->tag = tag;
        unsigned time;
        __asm {
            rdtsc
            mov dword ptr[time], eax
        }
        e->time = time;
        timer->current = e + 1;
    }
}
struct V378 { union { __m128 v; struct { float x,y,z,w; }; }; };
struct Transform378 {
    __m128 x,y,z,t;
    void __thiscall FUN_00cb22f0(void*, void*);
};
struct Segment378 { V378 from,to; };
struct Ray378 { V378 from,to; unsigned filter; unsigned userData; };
struct OutputBase378 { V378 normal; float fraction; int m_uiExtraInfo; };
struct Output378 : OutputBase378 { unsigned shapeKeys[8]; int keyIndex; };
struct Bool378 { char value; };
struct Shape378 {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual Bool378 RayCast(const Ray378&, Output378&) const;
    int field04,field08,field0c;
    Segment378* rays;
    int count;
    int field18;
    float radius;
};
struct Body378 { Shape378* shape; int other; Transform378* transform; };
struct Contact378 {
    V378 position;
    V378 normal;
    unsigned index;
    unsigned material;
    unsigned userData;
    unsigned other;
    void __thiscall FUN_00c7f640(void*, void*);
};
struct Normal378 { __m128 v; void __thiscall FUN_00c7f700(void*, void*); };
struct ContactBuffer378 { Contact378* current; int context; };
struct ContactManager378 {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual unsigned short add(Body378*, Body378*, void*, ContactBuffer378*, int, Contact378*);
    virtual void slot4();
    virtual void remove(unsigned short, int);
};
struct Agent378 {
    virtual void slot0();
    int unknown;
    ContactManager378* manager;
    unsigned short* indices;
    void __thiscall hkpMultiRayConvexAgent_processCollision(Body378*, Body378*, void*, ContactBuffer378*);
};
inline __m128 transform378(const Transform378& t, __m128 p) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p,p,0x55),t.y),_mm_mul_ps(_mm_shuffle_ps(p,p,0),t.x)),
                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p,p,0xaa),t.z),t.t));
}
// @f3 0x009c01f0 (community match, verified in this file)
namespace f3m_009c01f0 {
struct __declspec(align(16)) NativeFloat4 {
    float x, y, z, w;
    __forceinline float& operator()(int i) { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
    __forceinline const float& operator()(int i) const { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
};
struct NativeMat3 {
    NativeFloat4 m_col0, m_col1, m_col2;
    __forceinline const NativeFloat4& getColumn(int i) const { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};
struct __declspec(align(16)) NativeRot : public NativeMat3 {};
struct NativeTransform {
    NativeRot m_rotation;
    NativeFloat4 m_translation;
    __forceinline const NativeRot& getRotation() const { return m_rotation; }
    __forceinline const NativeFloat4& getTranslation() const { return m_translation; }
};
__forceinline double dmul(const float& c, float s) { return s * c; }
__forceinline void transform1(V378& out, const Transform378& xf, const V378& in) {
    const NativeTransform& xform = reinterpret_cast<const NativeTransform&>(xf);
    const NativeFloat4& b = reinterpret_cast<const NativeFloat4&>(in);
    NativeFloat4& t = reinterpret_cast<NativeFloat4&>(out);
    const NativeRot& r = xform.getRotation();
    const NativeFloat4& tr = xform.getTranslation();
    float v0 = b(0);
    float v1 = b(1);
    float v2 = b(2);
    t(0) = dmul(r(0, 0), v0) + dmul(r(0, 1), v1) + dmul(r(0, 2), v2) + tr(0);
    t(1) = dmul(r(1, 0), v0) + dmul(r(1, 1), v1) + dmul(r(1, 2), v2) + tr(1);
    t(2) = dmul(r(2, 0), v0) + dmul(r(2, 1), v1) + dmul(r(2, 2), v2) + tr(2);
    t(3) = 0;
}
}
// pdb: hkpMultiRayConvexAgent::processCollision | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Agent378::hkpMultiRayConvexAgent_processCollision(Body378* a, Body378* b, void* input, ContactBuffer378* buffer) {
    using namespace f3m_009c01f0;
    timer378(DAT_010ceda8);
    Shape378* source = a->shape;
    Shape378* target = b->shape;
    Transform378 relative;
    relative.FUN_00cb22f0(b->transform, a->transform);
    int count = source->count;
    Ray378 ray;
    ray.filter = 0;
    ray.userData = 0;
    Segment378* current = source->rays;
    for (int i = 0; i < count; ++current, ++i) {
        Output378 hit;
        transform1(ray.from, relative, current->from);
        transform1(ray.to, relative, current->to);
        hit.fraction = 1.0f;
        hit.m_uiExtraInfo = -1;
        hit.shapeKeys[0] = -1;
        hit.keyIndex = 0;
        Bool378 DidHit = target->RayCast(ray, hit);
        if (!DidHit.value) {
            unsigned short id = indices[i];
            if (id != 0xffff) {
                manager->remove(id, buffer->context);
                indices[i] = 0xffff;
            }
        } else {
            float fraction = hit.fraction;
            Contact378* contact = buffer->current;
            float inv = 1.0f - fraction;
            V378 position;
            position.x = inv*ray.from.x + fraction*ray.to.x;
            position.y = inv*ray.from.y + fraction*ray.to.y;
            position.z = inv*ray.from.z + fraction*ray.to.z;
            position.w = inv*ray.from.w + fraction*ray.to.w;
            contact->FUN_00c7f640(b->transform, &position);
            ((Normal378*)&contact->normal)->FUN_00c7f700(b->transform, &hit.normal);
            contact->normal.w = (hit.fraction - 1.0) * current->from.w + source->radius;
            if (indices[i] == 0xffff) {
                unsigned short iContactPointId = manager->add(a, b, input, buffer, 0, contact);
                indices[i] = iContactPointId;
            }
            if (indices[i] != 0xffff) {
                ++buffer->current;
                contact->index = indices[i];
            }
        }
    }
    timer378(DAT_010c41f8);
}

