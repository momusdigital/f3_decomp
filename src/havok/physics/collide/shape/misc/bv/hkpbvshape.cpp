#include "f3_common.h"
// src/havok/physics/collide/shape/misc/bv/hkpbvshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/bv/hkpbvshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBvShape.h"

extern int DAT_010c6fd0;

struct FUN_00c9d970_shape
{
    virtual void method0() = 0;
    virtual void method1() = 0;
    virtual void method2() = 0;
    virtual void method3() = 0;
    virtual void method4() = 0;
    virtual void method5() = 0;
    virtual void method6() = 0;
    virtual void method7(int, float, void*) = 0;
};

struct FUN_00c9d970_class
{
    unsigned char padding[0x10];
    FUN_00c9d970_shape* shape;

    void hkpBvShape_getAabbImpl(int, float, void*);
};

// @fnv 0x00c9d970
// pdb: hkpBvShape::getAabbImpl | hkpBvShape.obj | fnv360_0822_retail, objrun, high
// pdb params: localToWorld, tolerance, out
// pdb: hkpBvShape::getAabbImpl | hkpBvShape.obj | fnv360_0822_retail, objrun, high (was: DispatchShapeMethod7)
void FUN_00c9d970_class::hkpBvShape_getAabbImpl(int value, float currentTime, void* queryFilter)
{
    shape->method7(value, currentTime, queryFilter);
}

// @fnv 0x00c9d8b0
// pdb: std::basic_streambuf<char,std::char_traits<char> >::_Lock | algs.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: std::basic_streambuf<char,struct std::char_traits<char> >::overflow)
int __stdcall FUN_00c9d8b0(int a1)
{
    return -1;
}

struct hkpBvShapeContainerView : hkpBvShape
{
    hkpSingleShapeContainer* FUN_00c9d920();
};

// @fnv 0x00c9d920
// pdb: NonActorMagicTarget::GetActiveEffectList | NonActorMagicTarget.obj | fnv360_0822_retail, vtable, medium
hkpSingleShapeContainer* hkpBvShapeContainerView::FUN_00c9d920()
{
    return &m_pContainedShape;
}

extern int DAT_010c6fd0;

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010c7024[];
extern const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Rs_c9d9e0_Cmd
{
    const char* m_name;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct Rs_c9d9e0_Stream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_cap;

    __forceinline void timer(const char* name)
    {
        if (m_kRayEnd < m_cap)
        {
            Rs_c9d9e0_Cmd* c = reinterpret_cast<Rs_c9d9e0_Cmd*>(m_kRayEnd);
            c->m_name = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            c->m_uiStartTicks = t;
            m_kRayEnd = reinterpret_cast<char*>(c + 1);
        }
    }
};

struct Rs_c9d9e0_Input
{
    int unk00[16];
    int m_iValueAtOffset04;
};

struct Rs_c9d9e0_Shape
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual char* V20(char* r, int a, Rs_c9d9e0_Input* o);
};

struct Rs_c9d9e0_Self
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Rs_c9d9e0_Shape* m_pChildAtom;
    char* FUN_00c9d9e0(char* ret, int a, Rs_c9d9e0_Input* o);
};

// Wraps m_pChildAtom->V20 in timer records and a counter increment/decrement on o; zeroes o->unk00[counter + 8] afterwards if *ret is nonzero; returns ret.
// @fnv 0x00c9d9e0
// pdb: hkpBvShape::castRayImpl | hkpBvShape.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: input, results
char* Rs_c9d9e0_Self::FUN_00c9d9e0(char* ret, int a, Rs_c9d9e0_Input* o)
{
    static_cast<Rs_c9d9e0_Stream*>(TlsGetValue(DAT_0126835c))->timer(str_010c7024);
    o->m_iValueAtOffset04++;
    m_pChildAtom->V20(ret, a, o);
    o->m_iValueAtOffset04--;
    if (*ret)
        o->unk00[o->m_iValueAtOffset04 + 8] = 0;
    static_cast<Rs_c9d9e0_Stream*>(TlsGetValue(DAT_0126835c))->timer(str_010c41f8);
    return ret;
}

extern unsigned long DAT_0126835c;
struct hkMonitorCommand_c9da80
{
    const char* m_pName;
    unsigned int m_uiEventId;
    unsigned int m_uiPad;
};
struct hkMonitorStream_c9da80
{
    int unk00;
    hkMonitorCommand_c9da80* m_pCurrent;
    int unk08;
    hkMonitorCommand_c9da80* m_pRecordEnd;
};
static inline void TimerCommand_c9da80(const char* pName)
{
    hkMonitorStream_c9da80* pkStream = (hkMonitorStream_c9da80*)TlsGetValue(DAT_0126835c);
    hkMonitorCommand_c9da80* pkCommand = pkStream->m_pCurrent;
    if (pkCommand < pkStream->m_pRecordEnd)
    {
        pkCommand->m_pName = pName;
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        pkCommand->m_uiEventId = uiTicks;
        pkStream->m_pCurrent = pkCommand + 1;
    }
}
struct hkpShape_c9da80;
struct hkpCdBody_c9da80
{
    const hkpShape_c9da80* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody_c9da80* m_parent;
};
struct hkpShape_c9da80
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
    virtual void castRayWithCollector(const void* pkInput, const hkpCdBody_c9da80& kBody, void* pkCollector) const;
};
struct ParentBody_c9da80
{
    int unk00;
    int unk04;
    const void* m_pMotionState;
};
struct FUN_00c9da80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const hkpShape_c9da80* m_pChildShape;
    void FUN_00c9da80(const void* pkInput, const hkpCdBody_c9da80& kParent, void* pkCollector) const;
};
// Builds a temporary hkpCdBody wrapping m_pChildShape with kParent as parent and forwards the ray cast to the child shape's castRayWithCollector.
// @f3 0x00916070 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(__rdtsc,_ReadWriteBarrier)
namespace Native1441 {
extern unsigned long DAT_0116913c;
struct hkMonitorCommand_c9da80
{
    const char* m_pName;
    unsigned int m_uiEventId;
    unsigned int m_uiPad;
};
struct hkMonitorStream_c9da80
{
    int unk00;
    hkMonitorCommand_c9da80* m_pCurrent;
    int unk08;
    hkMonitorCommand_c9da80* m_pRecordEnd;
};
static inline void TimerCommand_c9da80(const char* pName)
{
    hkMonitorStream_c9da80* pkStream = (hkMonitorStream_c9da80*)TlsGetValue(DAT_0116913c);
    hkMonitorCommand_c9da80* pkCommand = pkStream->m_pCurrent;
    if (pkCommand < pkStream->m_pRecordEnd)
    {
        pkCommand->m_pName = pName;
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        pkCommand->m_uiEventId = uiTicks;
        pkStream->m_pCurrent = pkCommand + 1;
    }
}
struct hkpShape_c9da80;
struct hkpCdBody_c9da80
{
    const hkpShape_c9da80* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody_c9da80* m_parent;
};
struct hkpShape_c9da80
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void castRayWithCollector(const void* pkInput, const hkpCdBody_c9da80& kBody, void* pkCollector) const;
};
struct ParentBody_c9da80
{
    int unk00;
    int unk04;
    const void* m_pMotionState;
};
struct FUN_00c9da80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const hkpShape_c9da80* m_pChildShape;
    void FUN_00c9da80(const void* pkInput, const hkpCdBody_c9da80& kParent, void* pkCollector) const;
};
// Builds a temporary hkpCdBody wrapping m_pChildShape with kParent as parent and forwards the ray cast to the child shape's castRayWithCollector.
// @fnv 0x00c9da80
__forceinline void FUN_00c9da80_cls::FUN_00c9da80(const void* pkInput, const hkpCdBody_c9da80& kParent, void* pkCollector) const
{
    TimerCommand_c9da80("TtrcBvShape");
    hkpCdBody_c9da80 kBody;
    kBody.m_parent = &kParent;
    kBody.m_pMotionState = kParent.m_pMotionState;
    kBody.m_pCollisionShape = m_pChildShape;
    kBody.m_uiCollisionShapeKey = 0;
    m_pChildShape->castRayWithCollector(pkInput, kBody, pkCollector);
    TimerCommand_c9da80("Et");
}


}
// pdb: hkpBvShape::castRayWithCollectorImpl | hkpBvShape.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: input, cdBody, collector
void FUN_00c9da80_cls::FUN_00c9da80(const void* input,const hkpCdBody_c9da80& parent,void* collector)const{reinterpret_cast<const Native1441::FUN_00c9da80_cls*>(this)->FUN_00c9da80(input,reinterpret_cast<const Native1441::hkpCdBody_c9da80&>(parent),collector);}


extern int DAT_0102e388;

struct BvShapeReleaseView : hkpBvShape
{
    void FUN_00c9d930();
};

// Releases the held shape reference and the contained shape (if non-null), rewriting the object's two vtable pointers to fixed addresses around the calls.
// @f3 0x00979e90 (community match, verified in this file)
struct FUN_009316f0_cls
{
    void FUN_009316f0();
};
struct C9D930View
{
    int vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_009316f0_cls* unk18;
    FUN_009316f0_cls* unk1c;
};
// pdb: hkpBinaryAction::~hkpBinaryAction | hkpBinaryAction.obj | fnv360_0822_retail, call_seq, high
void BvShapeReleaseView::FUN_00c9d930()
{
    C9D930View* self = (C9D930View*)this;
    self->vtbl = 0xe7ce74;
    if (self->unk18)
    {
        self->unk18->FUN_009316f0();
        self->unk18 = 0;
    }
    if (self->unk1c)
    {
        self->unk1c->FUN_009316f0();
        self->unk1c = 0;
    }
    self->vtbl = (int)&DAT_0102e388;
}

