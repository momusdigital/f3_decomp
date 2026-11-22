#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodycentreofmassviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodycentreofmassviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Entries
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
    void** items;
    int count;
};
struct Owner
{
    void FUN_00d69c10(void* item);
};
struct View
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Entries* entries;
    void FUN_00d69f60();
};
// Iterates entries and calls FUN_00d69c10 on each item via the owner at this-8.
// @fnv 0x00d69f60
// pdb: hkpRigidBodyCentreOfMassViewer::init | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, vtable, medium
void View::FUN_00d69f60()
{
    if (entries)
    {
        for (int i = 0; i < entries->count; ++i)
            reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 8)->FUN_00d69c10(entries->items[i]);
    }
}

struct Target
{
    void FUN_00d69c10();
};
struct FUN_00d69fb0_cls
{
    void CallTargetMethod();
};
// Calls FUN_00d69c10 on the Target object located 0x20 bytes before this.
// @fnv 0x00d69fb0
// pdb: hkpRigidBodyCentreOfMassViewer::worldAddedCallback | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void FUN_00d69fb0_cls::CallTargetMethod()
{
    ((Target*)((char*)this - 0x20))->FUN_00d69c10();
}

template <class T> struct S_00d69fc0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
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

struct D6A140Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D6A140MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D6A140Allocator* m_pStreamAllocator;

    D6A140Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D6A140MemoryRouter& __cdecl FUN_00c85750();

class D6A140ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D6A140ReferencedObject* b =
            static_cast<D6A140ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D6A140ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

extern void* DAT_01269020;

namespace fnv_00d6a1f0 {
struct Allocator
{
    virtual void A();
    virtual void B();
    virtual void Free(void*, unsigned short);
};
struct Manager
{
    int unk00, unk04, unk08, unk0C;
    Allocator* unk10;
};
extern Manager* __cdecl FUN_00c85750();
struct Owner
{
    __declspec(noinline) virtual ~Owner();
    unsigned short unk04;
    unsigned short unk06;
    void* DestroyOwner(unsigned int flags);
};
Owner::~Owner()
{}
// Runs the Owner destructor, and if flags has bit 0 set, frees this object through the allocator obtained from FUN_00c85750 using unk04 as size; returns this.
// @fnv 0x00d6a1f0
Owner force_vtable;
}  // namespace fnv_00d6a1f0

// AttachAndDispatch: thiscall, one stack parameter (ArgOwner*).

struct SubList
{
    void** data;
    int count;
};

struct Fn_SlotObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p);
};

struct PtrItem
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
    SubList list;
};

struct ArgOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    PtrItem* m_20;
    int unk24;
    PtrItem** m_28;
    int m_2c;
    int unk30;
    PtrItem** m_34;
    int m_38;

    void Attach(void* p);
    void Detach(void* p);
};

struct FUN_00d69b20_cls
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
    Fn_SlotObj m_28;
    int m_2c;

    void AttachAndDispatch(ArgOwner* a1);
};

// Attaches and detaches this object's slots on a1, then dispatches every element of a1's three lists through m_28.v08.
// @fnv 0x00d69b20
// pdb: hkpRigidBodyCentreOfMassViewer::removeWorld | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void FUN_00d69b20_cls::AttachAndDispatch(ArgOwner* apOwner)
{
    apOwner->Attach(this != 0 ? (void*)&m_28 : 0);
    apOwner->Detach(this != 0 ? (void*)&m_2c : 0);

    for (int i = 0; i < apOwner->m_2c; ++i)
    {
        SubList* list = &apOwner->m_28[i]->list;
        for (int j = 0; j < list->count; ++j)
        {
            m_28.v08(list->data[j]);
        }
    }

    for (int i = 0; i < apOwner->m_38; ++i)
    {
        SubList* list = &apOwner->m_34[i]->list;
        for (int j = 0; j < list->count; ++j)
        {
            m_28.v08(list->data[j]);
        }
    }

    PtrItem* b = apOwner->m_20;
    if (b != 0)
    {
        for (int k = 0; k < b->list.count; ++k)
        {
            m_28.v08(b->list.data[k]);
        }
    }
}

namespace fnv_00d69fa0 {

class FUN_00d69b20_cls
{
  public:
    void FUN_00d69b20_target();
};

class FUN_00d69fa0_cls
{
  public:
    void FUN_00d69fa0();
};

// @fnv 0x00d69fa0
// pdb: hkpRigidBodyInertiaViewer::worldAddedCallback | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void FUN_00d69fa0_cls::FUN_00d69fa0()
{
    ((FUN_00d69b20_cls*)((char*)this - 0x20))->FUN_00d69b20_target();
}
}  // namespace fnv_00d69fa0

extern const char str_0102f13c[];
extern const char DAT_010ccf7c[];
extern const char DAT_010d22a8[];
extern const char DAT_010d2288[];
extern const char DAT_010d2278[];
extern const char DAT_010d225c[];
extern const char DAT_010d224c[];
struct FUN_00ddccb0
{
    void* unk00;
    FUN_00ddccb0(void* input);
};
struct FUN_00d6a040 : FUN_00ddccb0
{
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* volatile unk28;
    void* volatile unk2c;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    FUN_00d6a040(void* input);
};
// @fnv 0x00d6a040
// pdb: hkpConvexRadiusViewer::hkpConvexRadiusViewer | hkpConvexRadiusViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: contexts
FUN_00d6a040::FUN_00d6a040(void* input) : FUN_00ddccb0(input)
{
    unk28 = (void*)str_0102f13c;
    unk2c = (void*)DAT_010ccf7c;
    unk00 = (void*)DAT_010d22a8;
    unk08 = (void*)DAT_010d2288;
    unk20 = (void*)DAT_010d2278;
    unk28 = (void*)DAT_010d225c;
    unk2c = (void*)DAT_010d224c;
    unk30 = 0;
    unk34 = 0;
    unk38 = 0x80000000u;
}

extern void* DAT_01269020;

struct GlobalHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

namespace fnvc_adapt {
GlobalHolder* __cdecl FUN_00c85750();
}
extern "C" void _ReadWriteBarrier(void);

namespace fnv_00d6a0a0 {
struct Allocator
{
    virtual void Vfn00();
    virtual void Vfn04();
    virtual void Vfn08();
    virtual void Vfn0C();
    virtual void Free(void* data, unsigned int size) throw();
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* unk10;
};

namespace fnvc_adapt {
void* FUN_00c85750() throw();
}

struct Array
{
    void** data;
    int count;
    unsigned int capacity;
    ~Array() throw()
    {
        Manager* mgr = (Manager*)fnvc_adapt::FUN_00c85750();
        Allocator* alloc = mgr->unk10;
        count = 0;
        if (!(capacity & 0x80000000))
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};

struct Base28
{
    virtual ~Base28() throw()
    {}
};

struct Base2C
{
    virtual ~Base2C() throw()
    {}
};

}  // namespace fnv_00d6a0a0

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } lanes;
} __m128;

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" unsigned __int64 __rdtsc(void);

extern "C" void*(__stdcall* DAT_00fdf044)(unsigned long);

extern unsigned int DAT_0126835c;

struct MonRec
{
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};

struct MonStream
{
    int unk00;
    MonRec* cur;
    int unk08;
    MonRec* end;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
static __forceinline void monBegin(const char* tag, volatile unsigned int* stamped)
{
    MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
    MonRec* c = s->cur;
    if (c < s->end)
    {
        c->name = tag;
        _ReadWriteBarrier();
        *stamped = (unsigned int)__rdtsc();
        c->tsc = *stamped;
        s->cur = c + 1;
    }
}
static __forceinline void monEnd(const char* tag, volatile unsigned int* stamped)
{
    MonStream* s = (MonStream*)DAT_00fdf044(DAT_0126835c);
    MonRec* c = s->cur;
    if (c < s->end)
    {
        c->name = tag;
        _ReadWriteBarrier();
        *stamped = (unsigned int)__rdtsc();
        c->tsc = *stamped;
        s->cur = c + 1;
    }
}

static __forceinline __m128 makeLine(const __m128& pos, const __m128& axis, const float& s)
{
    __m128 x = _mm_load_ss(&s);
    return _mm_add_ps(pos, _mm_mul_ps(_mm_shuffle_ps(x, x, 0), axis));
}

struct Motion
{
    int m00, m04, m08, m0c;
    __m128 axisX;
    __m128 axisY;
    __m128 axisZ;
    int m40, m44, m48, m4c, m50, m54, m58, m5c;
    __m128 pos;
    float hkpMotion_getMass();
};

struct Body
{
    int unk00, unk04, unk08, unk0c;
    int idAt10;
    int unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    Motion motion;
};

struct DisplayHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void DisplayLine(const __m128& start, const __m128& end, unsigned int color, void* id, void* tag);
};

struct HandlerOwner
{
    DisplayHandler* handler;
    int b04, b08, b0c, b10;
};

struct COMViewerPart
{
    int unk00;
    Body** items;
    int count;
    void FUN_00d69d00(void* unused);
};

struct COMViewer : HandlerOwner, COMViewerPart
{
};

// For each body whose motion.hkpMotion_getMass() is nonzero, draws red, green and blue lines from its position along its three axes through the display handler.
// @f3 0x009f65f0 (community match, verified in this file)
namespace f3_center_axes {
struct __declspec(align(16)) AxisPoint {
    float lane[4];

    void AddOffset(const AxisPoint& basis, const AxisPoint& origin) {
        lane[0] = origin.lane[0] + basis.lane[0];
        lane[1] = origin.lane[1] + basis.lane[1];
        lane[2] = origin.lane[2] + basis.lane[2];
        lane[3] = origin.lane[3] + basis.lane[3];
    }
};
struct BodyMotion {
    int unk00, unk04, unk08, unk0c;
    AxisPoint right;
    AxisPoint forward;
    AxisPoint up;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    AxisPoint center;
    float FUN_008f8410();
};
struct NativeRigidBody {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc;
    BodyMotion motion;
};
struct AxisDisplay {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void DrawLine(const AxisPoint&, const AxisPoint&, unsigned int, void*);
};
struct LocalAxisLines {
    AxisPoint origin;
    AxisPoint vertical;
    AxisPoint lateral;
    AxisPoint longitudinal;
};
extern unsigned int DAT_0116913c;
extern void* DAT_01169838;

static __forceinline void Mark(const char* name) {
    MonStream* stream = static_cast<MonStream*>(TlsGetValue(DAT_0116913c));
    MonRec* entry = stream->cur;
    if (entry >= stream->end)
        return;
    entry->name = name;
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    entry->tsc = ticks;
    stream->cur = entry + 1;
}
}

// pdb: hkpRigidBodyCentreOfMassViewer::postSimulationCallback | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void COMViewerPart::FUN_00d69d00(void*)
{
    using namespace f3_center_axes;
    {

        Mark("TthkpRigidBodyCentreOfMassViewer");
    }

    for (int index = 0; index < count; ++index) {
        NativeRigidBody* body = reinterpret_cast<NativeRigidBody*>(items[index]);
        if (body->motion.FUN_008f8410() == 0.0f)
            continue;

        Mark("TtgetMassAndLines");

        LocalAxisLines lines;
        const AxisPoint& center = reinterpret_cast<NativeRigidBody*>(items[index])->motion.center;
        lines.origin.lane[0] = center.lane[0];
        lines.origin.lane[1] = center.lane[1];
        lines.origin.lane[2] = center.lane[2];
        lines.origin.lane[3] = center.lane[3];
        Body* const* current = &items[index];
        lines.lateral.AddOffset(reinterpret_cast<NativeRigidBody*>(*current)->motion.right, lines.origin);
        lines.longitudinal.AddOffset(reinterpret_cast<NativeRigidBody*>(*current)->motion.forward, lines.origin);
        lines.vertical.AddOffset(reinterpret_cast<NativeRigidBody*>(*current)->motion.up, lines.origin);

        Mark("Et");

        Mark("Ttdisplay3lines");
        COMViewer* viewer = static_cast<COMViewer*>(this);
        reinterpret_cast<AxisDisplay*>(viewer->handler)->DrawLine(lines.origin, lines.lateral, 0xffff0000u, DAT_01169838);
        reinterpret_cast<AxisDisplay*>(viewer->handler)->DrawLine(lines.origin, lines.longitudinal, 0xff008000u, DAT_01169838);
        reinterpret_cast<AxisDisplay*>(viewer->handler)->DrawLine(lines.origin, lines.vertical, 0xff0000ffu, DAT_01169838);
        Mark("Et");
    }
    Mark("Et");
}


// MSVC adjustor thunk: the primary base occupies 0x8 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00d6a1b0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d6a1b0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d6a1b0
    virtual void FUN_00d6a1b0();
};

Derived::Derived()
{}

namespace fnv_00d6a1d0 {
// sub ecx,0x2c; jmp DestroyOwner: adjustor thunk from multiple inheritance.
// PrimaryBase is vptr + 10 dwords = 0x2c bytes.
struct PrimaryBase
{
    virtual void FUN_00d6a1d0();
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
};

struct SecondaryBase
{
    virtual void FUN_00d6a1d0();
};

struct AdjDerived : PrimaryBase, SecondaryBase
{
    AdjDerived();
// @fnv 0x00d6a1d0
    virtual void FUN_00d6a1d0();
};

AdjDerived::AdjDerived()
{}
}  // namespace fnv_00d6a1d0

struct Parent;
struct FirstBase
{
    virtual Parent* FUN_00d6a1e0(unsigned int flags) = 0;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct Receiver
{
    virtual Parent* FUN_00d6a1e0(unsigned int flags) = 0;
};
struct Parent : FirstBase, Receiver
{
    Parent();
// @fnv 0x00d6a1e0
    virtual Parent* FUN_00d6a1e0(unsigned int flags);
};
Parent::Parent()
{}

#include <math.h>

struct Vec4Clamp
{
    __m128 m_vComponents;
};

// Clamps the vector in v to maxLen by scaling it down when its squared length exceeds maxLen squared.
// @f3 0x00a02ab0 (community match, verified in this file)
static __declspec(noinline) void __cdecl FUN_00d6b330(Vec4Clamp* apVec, float maxLen)
{
    float* c = (float*)&apVec->m_vComponents;
    float fLenSq = c[0] * c[0] + c[1] * c[1] + c[2] * c[2];
    float fMaxSq = maxLen * maxLen;
    if (fLenSq > fMaxSq)
    {
        float fLen = (float)sqrt((double)fLenSq);
        float invLen = 1.0f / fLen;
        float s = invLen * maxLen;
        c[0] = c[0] * s;
        c[1] = c[1] * s;
        c[2] = c[2] * s;
        c[3] = c[3] * s;
    }
}


volatile float g_clampLen;
Vec4Clamp* volatile g_clampVec;
void CallClamp_d6b330()
{
    FUN_00d6b330(g_clampVec, g_clampLen);
}

struct Callback
{
    virtual void unused();
    virtual void deliver(int entry);
};
struct RemovalEntityList
{
    int* entries;
    int count;
};
struct Record
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
    RemovalEntityList data48;
};
struct Context
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Record* special20;
    int unk24;
    Record** list28;
    int count2c;
    int unk30;
    Record** list34;
    int count38;
    void FUN_00c93820(Callback* ptr);
    void FUN_00c93920(int* ptr);
};
struct CenterOfMassRemovalDispatcher
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
    Callback callback28;
    int data2c;
    void FUN_00d69c10(Context* context);
};
// Passes callback28 and data2c to context, then calls callback28.deliver for each entry in the data48 lists of list28, list34 and special20.
// @fnv 0x00d69c10
// pdb: hkpRigidBodyCentreOfMassViewer::addWorld | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void CenterOfMassRemovalDispatcher::FUN_00d69c10(Context* context)
{
    context->FUN_00c93820(this ? &callback28 : 0);
    context->FUN_00c93920(this ? &data2c : 0);
    for (int i = 0; i < context->count2c; ++i)
    {
        RemovalEntityList* pRemovalList = &context->list28[i]->data48;
        for (int j = 0; j < pRemovalList->count; ++j)
        {
            callback28.deliver(pRemovalList->entries[j]);
        }
    }
    for (int i = 0; i < context->count38; ++i)
    {
        RemovalEntityList* pRemovalList = &context->list34[i]->data48;
        for (int j = 0; j < pRemovalList->count; ++j)
        {
            callback28.deliver(pRemovalList->entries[j]);
        }
    }
    Record* pSpecialRecord = context->special20;
    if (pSpecialRecord != 0)
    {
        for (int j = 0; j < pSpecialRecord->data48.count; ++j)
        {
            callback28.deliver(pSpecialRecord->data48.entries[j]);
        }
    }
}
