#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodyinertiaviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodyinertiaviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_01268ffc;

struct InnerArray {
    void** data;
    int count;
};

struct SubObject {
    char pad[0x48];
    InnerArray arr;
};

struct Arg {
    char pad00[0x20];
    SubObject* m_20;
    char pad24[4];
    SubObject** m_28;
    int m_2c;
    char pad30[4];
    SubObject** m_34;
    int m_38;

    void FUN_00c93820(void* p);
    void FUN_00c93920(void* p);
};

struct Field28 {
    virtual void vfunc0();
    virtual void vfunc1(void* item);
};

struct FUN_00d67020_class {
    char pad00[0x28];
    Field28 field28;
    int field2c;

    void VisitSubObjects(Arg* arg);
};

// @fnv 0x00d67020
// pdb: hkpRigidBodyInertiaViewer::addWorld | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void FUN_00d67020_class::VisitSubObjects(Arg* arg) {
    arg->FUN_00c93820(this ? &field28 : 0);
    arg->FUN_00c93920(this ? &field2c : 0);

    for (int i = 0; i < arg->m_2c; ++i) {
        InnerArray* arr = &arg->m_28[i]->arr;
        for (int j = 0; j < arr->count; ++j) {
            field28.vfunc1(arr->data[j]);
        }
    }

    for (int i = 0; i < arg->m_38; ++i) {
        InnerArray* arr = &arg->m_34[i]->arr;
        for (int j = 0; j < arr->count; ++j) {
            field28.vfunc1(arr->data[j]);
        }
    }

    SubObject* pSubObject = arg->m_20;
    if (pSubObject) {
        InnerArray* arr = &pSubObject->arr;
        for (int i = 0; i < arr->count; ++i) {
            field28.vfunc1(arr->data[i]);
        }
    }
}

struct Handler { void VisitSubObjects(int); };
struct Collection {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68;
    int* items;
    int count;
};
struct Owner {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    Collection* collection;
    void __thiscall ProcessCollectionItems();
};
// Iterates the collection's items and passes each to VisitSubObjects on the Handler at this-8, if the collection exists.
// @fnv 0x00d67110
// pdb: hkpRigidBodyInertiaViewer::init | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, vtable, medium
void __thiscall Owner::ProcessCollectionItems() {
    if (collection != 0) {
        int n = collection->count;
        int i = 0;
        if (0 < n) {
            do {
                ((Handler*)((char*)this - 8))->VisitSubObjects(collection->items[i]);
                i = i + 1;
            } while (i < n);
        }
    }
}

struct Prefix32 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
};
struct SecondaryBase {
    void FUN_00d67160();
};
struct CompleteObject : Prefix32, SecondaryBase {
    void VisitSubObjects();
};
// Adjusts this to the enclosing CompleteObject and calls its VisitSubObjects method.
// @fnv 0x00d67160
// pdb: hkpRigidBodyCentreOfMassViewer::worldRemovedCallback | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void SecondaryBase::FUN_00d67160() {
    CompleteObject* pCompleteObject = reinterpret_cast<CompleteObject*>(reinterpret_cast<char*>(this) - sizeof(Prefix32));
    pCompleteObject->VisitSubObjects();
}

struct S_00d67170_Array {
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int indexOf(void* const& t, int startIdx = 0, int endIdx = -1) const
    {
        if (endIdx < 0)
            endIdx = m_iElementCount;
        for (int i = startIdx; i < endIdx; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }

};

extern int DAT_01268ffc;

struct FUN_00d66f30_inner {
    virtual void v00();
    virtual void v04();
    virtual void v08(int aiValue);
};

struct FUN_00d66f30_list {
    int* m_piValues;
    int m_iArrayLength;
};

struct FUN_00d66f30_item {
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
    FUN_00d66f30_list m_kList;
};

struct FUN_00d66f30_params {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d66f30_item* m_pExtra;
    int unk24;
    FUN_00d66f30_item** m_ppItems;
    int m_iItemCount;
    int unk30;
    FUN_00d66f30_item** m_ppItems2;
    int m_iItemCount2;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;

    void FUN_00c917a0(void* apTarget);
    void ClearValue(void* apTarget);
};

struct FUN_00d66f30_cls {
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
    FUN_00d66f30_inner m_kInner;
    int m_iN;

    void FUN_00d66f30(FUN_00d66f30_params* apParams);
};

// @fnv 0x00d66f30
// pdb: hkpRigidBodyInertiaViewer::removeWorld | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void FUN_00d66f30_cls::FUN_00d66f30(FUN_00d66f30_params* apParams)
{
    apParams->FUN_00c917a0(this != 0 ? &m_kInner : 0);
    apParams->ClearValue(this != 0 ? &m_iN : 0);

    for (int i = 0; i < apParams->m_iItemCount; i++) {
        FUN_00d66f30_list* pList = &apParams->m_ppItems[i]->m_kList;
        for (int j = 0; j < pList->m_iArrayLength; j++) {
            m_kInner.v08(pList->m_piValues[j]);
        }
    }

    for (int i = 0; i < apParams->m_iItemCount2; i++) {
        FUN_00d66f30_list* pList = &apParams->m_ppItems2[i]->m_kList;
        for (int j = 0; j < pList->m_iArrayLength; j++) {
            m_kInner.v08(pList->m_piValues[j]);
        }
    }

    FUN_00d66f30_item* pExtra = apParams->m_pExtra;
    if (pExtra != 0) {
        for (int k = 0; k < pExtra->m_kList.m_iArrayLength; k++) {
            m_kInner.v08(pExtra->m_kList.m_piValues[k]);
        }
    }
}

struct Outer {
    void __thiscall FUN_00d66f30(void* arg);
};

struct TargetClass {
    void __thiscall FUN_00d67150(void* arg);
};

// @fnv 0x00d67150
// pdb: hkpPhantomDisplayViewer::worldAddedCallback | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void TargetClass::FUN_00d67150(void* arg) {
    ((Outer*)((char*)this - 0x20))->FUN_00d66f30(arg);
}

class D671F0ListenerA {
public:
    virtual void unk00();
};

class D671F0ListenerB {
public:
    virtual void unk00();
};

struct D671F0ListenerArray {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D671F0ListenerArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

class D671F0Island {
public:
    void addListener(D671F0ListenerA* listener);
};

struct D671F0World {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    D671F0Island** m_islands;
    int m_iIslandCount;
};

class D671F0BaseA {
public:
    virtual void unk00();

    int unk04;
};

class D671F0BaseB {
public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D671F0BaseC {
public:
    virtual void unk00();
};

class D671F0Base : public D671F0BaseA, public D671F0BaseB, public D671F0BaseC {
public:
    D671F0Base(void* info);

    D671F0World* m_pOwningWorld;
};

class FUN_00d671f0 : public D671F0Base, public D671F0ListenerA, public D671F0ListenerB {
public:
    FUN_00d671f0(void* info);

    D671F0ListenerArray m_arrayA;
    D671F0ListenerArray m_arrayB;
};

// Constructor that forwards info to the D671F0Base base constructor and initializes the two listener arrays.
// @fnv 0x00d671f0
// pdb: hkpRigidBodyInertiaViewer::hkpRigidBodyInertiaViewer | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
FUN_00d671f0::FUN_00d671f0(void* info) : D671F0Base(info)
{
}

struct D67880Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D67880MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D67880Allocator* m_pStreamAllocator;

    D67880Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D67880MemoryRouter& __cdecl FUN_00c85750();

class D67880ReferencedObject {
public:
    static void* operator new(unsigned int nbytes)
    {
        D67880ReferencedObject* b = static_cast<D67880ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D67880ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);
template <typename T> inline void D671B0ConstructWithCopy(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <typename T>
struct D671B0Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& val)
    {
        D67880MemoryRouter& router = FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        D671B0ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }
};

struct Heap_d672 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct Router_d672 {
    int unk00, unk04, unk08, unk0C;
    Heap_d672* m_pStreamAllocator;
    Heap_d672& heap() { return *m_pStreamAllocator; }
    static Router_d672& __cdecl FUN_00c85750() throw();
};

template <class T> __forceinline void destructArray_d672(T* p, int n)
{
    for (int i = 0; i < n; i++)
        p[i].~T();
}

template <class T> struct hkArray_d672 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void ClearAndRelease() throw()
    {
        Heap_d672& heap = Router_d672::FUN_00c85750().heap();
        destructArray_d672(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <class T> struct hkPodArray_d672 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void ClearAndRelease() throw()
    {
        Heap_d672& heap = Router_d672::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace fnv_00d67930 {
struct S_00d67930_Heap {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d67930_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d67930_Heap* m_pStreamAllocator;
    __forceinline S_00d67930_Heap& heap() { return *m_pStreamAllocator; }
};

S_00d67930_Router& __cdecl FUN_00c85750();

struct FUN_00d67930 {
    virtual ~FUN_00d67930() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d67930();
    static void operator delete(void* p, unsigned int)
    {
        FUN_00d67930* b = static_cast<FUN_00d67930*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Default constructor with an empty body for a type with a virtual destructor, m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00d67930
FUN_00d67930::FUN_00d67930() {}
}  // namespace fnv_00d67930

#include <math.h>
#include <xmmintrin.h>
#include <windows.h>
extern unsigned long DAT_0126835c;
extern char DAT_010c41f8[], DAT_010d1d8c[];
struct ProfileEvent {
    const char* name;
    unsigned int timestamp;
    unsigned int reserved;
};
struct ProfileStream {
    int unk00;
    ProfileEvent* current;
    ProfileEvent* start;
    ProfileEvent* end;
};
inline void recordEvent(const char* name) {
    ProfileStream* stream = static_cast<ProfileStream*>(TlsGetValue(DAT_0126835c));
    ProfileEvent* event = stream->current;
    if (event < stream->end) {
        event->name = name;
        unsigned int tick;
        __asm {
            rdtsc
            mov dword ptr[tick], eax
        }
        event->timestamp = tick;
        stream->current = event + 1;
    }
}
struct __declspec(align(16)) Vec {
    float x,y,z,w;
    Vec() {}
    __forceinline __m128 get() const { return _mm_load_ps(&x); }
    __forceinline void set(__m128 value) { _mm_store_ps(&x,value); }
    __forceinline void set(float a, float b, float c, float d) { set(_mm_setr_ps(a,b,c,d)); }
    __forceinline Vec(float a, float b, float c, float d) { set(_mm_setr_ps(a,b,c,d)); }
    __forceinline Vec(const Vec& other) { set(other.get()); }
    __forceinline Vec& operator=(const Vec& other) { set(other.get()); return *this; }
    void FUN_00c7f700(const struct Transform* transform, const Vec* value);
};
struct Transform {
    Vec x,y,z,translation;
    Transform() {}
    __forceinline Transform(const Transform& other) {
        __m128 a=other.x.get(), b=other.y.get(), c=other.z.get(), d=other.translation.get();
        x.set(a); y.set(b); z.set(c); translation.set(d);
    }
};
struct __declspec(align(16)) Inertia {
    float xx, xy, xz, xw;
    float yx, yy, yz, yw;
    float zx, zy, zz, zw;
    Inertia() {}
};
struct MotionHeader {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void getInertia(Inertia* out);
    int unk04, unk08, unk0c;
};
struct Motion : MotionHeader {
    Transform transform;
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
    Vec centerOfMass;
    float hkpMotion_getMass();
};
struct Body {
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Motion motion;
    __forceinline Motion* getRigidMotion() { return &motion; }
    __forceinline const Motion* getRigidMotionC() const { return &motion; }
    __forceinline float GetMassValue() { return getRigidMotion()->hkpMotion_getMass(); }
    __forceinline void GetInverseScaleMatrix(Inertia& m) { getRigidMotion()->getInertia(&m); }
    __forceinline const Transform& getTransform() const { return motion.transform; }
    __forceinline const Vec& getCenterOfMassLocal() const { return motion.centerOfMass; }
};
struct ShapeVec4 { float x, y, z, w; };
struct ShapeTransform { ShapeVec4 x, y, z, translation; };
struct Shape {
    virtual void destroy(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    int unk0c;
    ShapeTransform transform;
    int type;
    int unk54, unk58, unk5c;
    ShapeVec4 halfExtents;
    void FUN_00de1fc0();
    void FUN_00de2010(const Vec* dimensions, const Transform* transform);
};
void __cdecl FUN_00c908c0(void* allocator, void* array, int capacity, int elementSize);
struct FreeAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReleaseBlock(void* p, int bytes);
};
__forceinline FreeAllocator& heapGet() { return reinterpret_cast<FreeAllocator&>(FUN_00c85750().heap()); }
template<class T> struct LocalArray {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline void reserve(int n) { reserveWith(heapGet(),n); }
    __forceinline void reserveWith(FreeAllocator& allocator, int n) {
        const int capacity = getCapacity();
        if (capacity < n) {
            int twice = capacity * 2;
            int next = n < twice ? twice : n;
            FUN_00c908c0(&allocator, this, next, sizeof(T));
        }
    }
};
inline void destroyShapes(Shape* begin, int count) {
    for (int k=0; k<count; ++k) begin[k].destroy(0);
}
inline void createShapes(Shape* begin, int count) {
    for (int k=0; k<count; ++k) {
        Shape* at = begin+k;
        if (at) at->FUN_00de1fc0();
    }
}
struct ShapeArray : LocalArray<Shape> {
    __forceinline void resize(int n) {
        reserve(n);
        destroyShapes(data+n, count-n);
        createShapes(data+count, n-count);
        count=n;
    }
};
struct Renderer {
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
    virtual void v34();
    virtual void display(LocalArray<Shape*>* shapes, unsigned int color, int id, int tag);
};
struct ViewerPart {
    virtual void v00();
    Body** bodies;
    int bodyCount;
    int bodyCapacity;
    ShapeArray shapes;
    void FUN_00d67340(float unused);
};
struct ViewerPrefix {
    virtual void v00();
    Renderer* renderer;
    int unk04, unk08, unk0c, unk10;
};
struct Viewer : ViewerPrefix, ViewerPart {};
// @f3 0x009f4270 (community match, verified in this file)
#include <new>
extern unsigned long DAT_010f3170;
void FUN_00901e90(void*, int, int);
extern char DAT_00e32798[], DAT_00e80f40[];
extern char DAT_00e80f58[], DAT_00e80f4c[];
extern int DAT_01169818;
namespace n9f4270 {
class hkDisplayGeometry {
public:
    virtual ~hkDisplayGeometry() throw();
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    int unk0c;
    ShapeTransform transform;
    int type;
    int unk54, unk58, unk5c;
    __declspec(nothrow) hkDisplayGeometry(const hkDisplayGeometry&) throw();
};

struct RigidMotion : MotionHeader {
    Transform transform;
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
    Vec centerOfMass;
    float FUN_008f8410();
};
struct BoxVec4 {float x,y,z,w;};
struct BoxTransform {BoxVec4 x,y,z,translation;};
struct DisplayShape {
    virtual void destroy(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    int unk0c;
    BoxTransform transform;
    int type;
    int unk54, unk58, unk5c;
    BoxVec4 halfExtents;
    void FUN_00a67db0();
    void FUN_00a67de0(const Vec* dimensions, const Transform* transform);
};
struct RigidBody {
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    RigidMotion motion;
    __forceinline RigidMotion* getRigidMotion() { return &motion; }
    __forceinline const RigidMotion* getRigidMotionC() const { return &motion; }
    __forceinline float GetMassValue() { return getRigidMotion()->FUN_008f8410(); }
    __forceinline void GetInverseScaleMatrix(Inertia& m) { getRigidMotion()->getInertia(&m); }
    __forceinline const Transform& getTransform() const { return motion.transform; }
    __forceinline const Vec& getCenterOfMassLocal() const { return motion.centerOfMass; }
};
struct DebugRenderer {
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
    virtual void display(LocalArray<DisplayShape*>* shapes, unsigned int color, int tag);
};
struct ScalarVec {
    __declspec(align(16)) float x;
    float y,z,w;
    ScalarVec() {}
    __forceinline ScalarVec(const ScalarVec& o) { x=o.x;y=o.y;z=o.z;w=o.w; }
    __forceinline ScalarVec& operator=(const ScalarVec& o) { x=o.x;y=o.y;z=o.z;w=o.w;return *this; }
    __forceinline void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
    __forceinline void add(const ScalarVec& b) {x+=b.x;y+=b.y;z+=b.z;w+=b.w;}
    void hkVector4_setRotatedDir(const Transform* rotation, const Vec* v);
};
struct ScalarTransform {
    ScalarVec x,y,z,translation;
    __forceinline ScalarTransform(const ScalarTransform& o) {
        ScalarVec a=o.x,b=o.y,c=o.z,d=o.translation;
        x=a;y=b;z=c;translation=d;
    }
};
struct ViewerAllocator { void FUN_008f6d90(void*, int, int); };
struct BoxArray {
    DisplayShape* data; int count; int capacityAndFlags;
    int getCapacity() const {return capacityAndFlags&0x3fffffff;}
    void FUN_00a82280(BoxArray* source);
};
struct ScalarExtents {
    float x,y,z,w;
    __declspec(nothrow) ScalarExtents(const ScalarExtents& a) throw() {x=a.x;y=a.y;z=a.z;w=a.w;}
};
class hkDisplayBox : public hkDisplayGeometry {
public:
    ScalarExtents halfExtents;
    virtual ~hkDisplayBox() throw();
    __declspec(nothrow) hkDisplayBox(const hkDisplayBox& a) throw() : hkDisplayGeometry(a),halfExtents(a.halfExtents) {}
};

struct DisplayShape;

__declspec(noinline) void BoxArray::FUN_00a82280(BoxArray* other) {
    DisplayShape* p=data; data=other->data; other->data=p;
    int n=count; count=other->count; other->count=n;
    int c=capacityAndFlags; capacityAndFlags=other->capacityAndFlags; other->capacityAndFlags=c;
}
inline void destroyShapes(DisplayShape* begin, int count) {
    for (int k=0; k<count; ++k) begin[k].destroy(0);
}
__forceinline void releaseViewerStorage(BoxArray& a) {
    if ((a.capacityAndFlags & 0x80000000)==0) {
        ViewerAllocator* heap=static_cast<ViewerAllocator*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(a.data,(a.capacityAndFlags&0x3fffffff)*sizeof(DisplayShape),0x17);
    }
}
__forceinline void resizeViewerShapes(BoxArray& a, int n) {
    int oldCount=a.count;
    if(n<oldCount) { for(int k=n;k<oldCount;++k) a.data[k].destroy(0); }
    else {
        int capacity=a.getCapacity();
        if(n>capacity) {
            int next=n<capacity*2?capacity*2:n;
            BoxArray old;
            old.data=0;old.count=0;old.capacityAndFlags=0x80000000;
            old.FUN_00a82280(&a);
            capacity=a.getCapacity();
            if(capacity<next) FUN_00901e90(&a,next<capacity*2?capacity*2:next,sizeof(DisplayShape));
            DisplayShape* destination=a.data;
            for(int k=0;k<oldCount;++k) {
                hkDisplayBox* p=reinterpret_cast<hkDisplayBox*>(destination+k);
                new(p) hkDisplayBox(*reinterpret_cast<const hkDisplayBox*>(old.data+k));
            }
            a.count=oldCount;
            destroyShapes(old.data,old.count);
            releaseViewerStorage(old);
        }
        DisplayShape* destination=a.data;
        for(int k=oldCount;k<n;++k) { DisplayShape* p=destination+k; if(p) p->FUN_00a67db0(); }
    }
    a.count=n;
}
__forceinline void reservePointers(LocalArray<DisplayShape*>& array, int request) {
    int capacity=array.capacityAndFlags&0x3fffffff;
    if(capacity<request) {
        int twice=capacity*2;
        int next=request<twice?twice:request;
        FUN_00901e90(&array,next,sizeof(DisplayShape*));
    }
}
}

// pdb: hkpRigidBodyInertiaViewer::postSimulationCallback | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void ViewerPart::FUN_00d67340(float unused) {
    recordEvent(DAT_00e80f58);
    recordEvent(DAT_00e80f4c);
    n9f4270::resizeViewerShapes(reinterpret_cast<n9f4270::BoxArray&>(shapes),bodyCount);
    int used = 0;
    for (int i = 0; i < bodyCount; ++i) {
        float mass = reinterpret_cast<n9f4270::RigidBody*>(bodies[i])->GetMassValue();
        if (mass != 0.0f) {
            Inertia inertia;
            reinterpret_cast<n9f4270::RigidBody*>(bodies[i])->motion.getInertia(&inertia);
            float betaSqrd = float((inertia.xx - inertia.yy + inertia.zz) / mass * 6.0);
            float beta; if (betaSqrd < 0.0f) beta=0.0f; else beta=sqrtf(betaSqrd);
            float gammaSqrd = float(inertia.xx / mass * 12.0 - betaSqrd);
            float gamma; if (gammaSqrd < 0.0f) gamma=0.0f; else gamma=sqrtf(gammaSqrd);
            float alphaSqrd = float(inertia.zz / mass * 12.0 - betaSqrd);
            float alpha; if (alphaSqrd < 0.0f) alpha=0.0f; else alpha=sqrtf(alphaSqrd);
            const float scale = 1.01f;
            n9f4270::ScalarVec dimensions;
            dimensions.set(alpha * scale * 0.5, beta * scale * 0.5, gamma * scale * 0.5, 0.0f);
            n9f4270::ScalarTransform transform(*reinterpret_cast<const n9f4270::ScalarTransform*>(&reinterpret_cast<n9f4270::RigidBody*>(bodies[i])->motion.transform));
            n9f4270::ScalarVec rotated;
            {
                n9f4270::ScalarVec center(*reinterpret_cast<const n9f4270::ScalarVec*>(&reinterpret_cast<n9f4270::RigidBody*>(bodies[i])->motion.centerOfMass));
                rotated.hkVector4_setRotatedDir(reinterpret_cast<const Transform*>(&transform), reinterpret_cast<const Vec*>(&center));
            }
            rotated.add(transform.translation);
            transform.translation = rotated;
            reinterpret_cast<n9f4270::BoxArray&>(shapes).data[used++].FUN_00a67de0(reinterpret_cast<const Vec*>(&dimensions), reinterpret_cast<const Transform*>(&transform));
        }
    }
    recordEvent(DAT_00e32798);
    recordEvent(DAT_00e80f40);
    n9f4270::resizeViewerShapes(reinterpret_cast<n9f4270::BoxArray&>(shapes),used);
    LocalArray<n9f4270::DisplayShape*> pointers;
    pointers.data = 0;
    pointers.count = 0;
    pointers.capacityAndFlags = 0x80000000;
    int count = reinterpret_cast<n9f4270::BoxArray&>(shapes).count;
    n9f4270::reservePointers(pointers,count);
    pointers.count = count;
    for (int j = reinterpret_cast<n9f4270::BoxArray&>(shapes).count - 1; j >= 0; --j)
        pointers.data[j] = &reinterpret_cast<n9f4270::BoxArray&>(shapes).data[j];
    reinterpret_cast<n9f4270::DebugRenderer*>(static_cast<Viewer*>(this)->renderer)->display(&pointers, 0xffff00ff, DAT_01169818);
    recordEvent(DAT_00e32798);
    recordEvent(DAT_00e32798);
    if ((pointers.capacityAndFlags & 0x80000000)==0) {
        int capacity=pointers.capacityAndFlags&0x3fffffff;
        n9f4270::ViewerAllocator* heap=static_cast<n9f4270::ViewerAllocator*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(pointers.data,capacity*sizeof(n9f4270::DisplayShape*),0x17);
    }
}
