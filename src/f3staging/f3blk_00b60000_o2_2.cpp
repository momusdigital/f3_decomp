#include <windows.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00b60000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b6cc10 (community match, verified in this file)
namespace f3m_00b6cc10 {


struct RefObj {
    virtual void v0();
    virtual void v1();
    volatile LONG rc;
};
struct RPtr {
    RefObj* p;
    RPtr& operator=(RefObj* o) {
        RefObj* old = p;
        if (old != o) {
            if (old && !InterlockedDecrement(&old->rc)) old->v1();
            p = o;
            if (p) InterlockedIncrement(&p->rc);
        }
        return *this;
    }
};
struct Cfg {
    void FUN_008905a0(int a, int b, int c);
};
struct TmpObj {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int rc;
    void FUN_0088fe30();
    void DecRef() { if (--rc == 0) FUN_0088fe30(); }
};
struct Tmp {
    TmpObj* p;
    Tmp() : p(0) {}
    ~Tmp() { if (p) p->DecRef(); }
};
struct A {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    int f14;
    unsigned f18;
    int unk1C; int unk20; int unk24; int unk28; int unk2C;
    Cfg* f30;
    int unk34; int unk38; int unk3C; int unk40;
    RPtr f44;
    int unk48; int unk4C; int unk50; int unk54; int unk58;
    RPtr f5c;
    int unk60;
    int rc;
    void FUN_00888d30(int a, TmpObj* b);
    void FUN_00888c10();
};
struct APtr {
    A* p;
    APtr() : p(0) {}
    ~APtr() { if (p && --p->rc == 0) p->FUN_00888c10(); }
    APtr& operator=(A* const& o) {
        if (p != o) {
            if (p && --p->rc == 0) p->FUN_00888c10();
            p = o;
            if (p) ++p->rc;
        }
        return *this;
    }
};
void FUN_0088ff50(TmpObj** out);
void FUN_00b62c70(TmpObj* t, int a, int b, int c, int d);
Cfg* FUN_00890750();
extern A* DAT_011746b0;
extern A* DAT_011746b4;
extern RefObj* DAT_01173b80;
extern RefObj* DAT_01173880;
extern RefObj* DAT_01173bd8;
extern int DAT_01173338;
extern int DAT_01172758;
extern int DAT_0117333c;
extern int DAT_0117275c;

static void Set(A* a, int x, int y)
{
    if (!a->f30) a->f30 = FUN_00890750();
    a->f30->FUN_008905a0(x, y, 1);
}

// pdb: ShadowLightShader::PresetFogPasses_1x | ShadowLightShader_Preset_1x.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: ShadowLightShader::PresetAmbientPasses_1x)
void FUN_00b6cc10()
{
    APtr a;
    Tmp tmp;
    a = DAT_011746b0;
    unsigned n0 = a.p->f18;
    if (n0 < 2) {
        FUN_0088ff50(&tmp.p);
        FUN_00b62c70(tmp.p, 0, 1, 2, 1);
        a.p->FUN_00888d30(a.p->f14, tmp.p);
        FUN_0088ff50(&tmp.p);
        FUN_00b62c70(tmp.p, 1, 1, 2, 1);
        a.p->FUN_00888d30(a.p->f14, tmp.p);
    }
    a.p->f5c = DAT_01173b80;
    a.p->f44 = DAT_01173880;
    Set(a.p, 0x1b, 1); Set(a.p, 0x13, 5); Set(a.p, 0x14, 6); Set(a.p, 0xf, 0);
    Set(a.p, 7, 1); Set(a.p, 0x17, 3); Set(a.p, 0xe, 0);
    DAT_01173338 = 0;
    DAT_01172758 = 0;
    a = DAT_011746b4;
    if (a.p->f18 < 2) {
        FUN_0088ff50(&tmp.p);
        FUN_00b62c70(tmp.p, 0, 1, 2, 1);
        a.p->FUN_00888d30(a.p->f14, tmp.p);
        FUN_0088ff50(&tmp.p);
        FUN_00b62c70(tmp.p, 1, 1, 2, 1);
        a.p->FUN_00888d30(a.p->f14, tmp.p);
    }
    a.p->f5c = DAT_01173bd8;
    a.p->f44 = DAT_01173880;
    Set(a.p, 0x1b, 1); Set(a.p, 0x13, 5); Set(a.p, 0x14, 6); Set(a.p, 0xf, 0);
    Set(a.p, 7, 1); Set(a.p, 0x17, 3); Set(a.p, 0xe, 0);
    DAT_0117333c = 0;
    DAT_0117275c = 0;
}
}   // namespace f3m_00b6cc10

// @f3 0x00b6d010 (community match, verified in this file)
namespace f3m_00b6d010 {



struct RefObj {
    virtual void v0();
    virtual void Destroy();
    LONG refs;
    void IncRef() { InterlockedIncrement(&refs); }
    void DecRef() { if (!InterlockedDecrement(&refs)) Destroy(); }
};

struct OpsT {
    void FUN_008905a0(int a, int b, int c);
    void FUN_008905a0(int a, float b, int c);
};
extern OpsT* FUN_00890750x();

struct StateS {
    int unk00, unk04, unk08, unk0c, unk10;
    int unk14;
    unsigned unk18;
    int unk1c, unk20, unk24, unk28, unk2c;
    OpsT* unk30;
    int unk34, unk38, unk3c, unk40;
    RefObj* unk44;
    int unk48, unk4c, unk50, unk54, unk58;
    RefObj* unk5c;
    int unk60;
    int refs64;
    void FUN_00888d30(int a, void* b);
    void Destroy();
};

struct LocalT { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int refs60; void Free(); };
void FUN_0088ff50(LocalT** out);
void FUN_00b62c70(LocalT* a, int b, int c, int d, int e);

extern StateS* g_s0; extern StateS* g_s1; extern StateS* g_s2; extern StateS* g_s3; extern StateS* g_s4;
extern RefObj* g_tA; extern RefObj* g_tB; extern RefObj* g_tC;
extern int g_a0, g_a1, g_a2, g_a3, g_a4, g_b0, g_b1, g_b2, g_b3, g_b4;
extern float g_f;

static __forceinline void DecL(LocalT* q) { if (--q->refs60 == 0) q->Free(); }
struct LocRef {
    LocalT* p;
    LocRef() : p(0) {}
    ~LocRef() { if (p) DecL(p); }
};

struct StateRef {
    StateS* p;
    StateRef() : p(0) {}
    ~StateRef() { if (p && --p->refs64 == 0) p->Destroy(); }
    __forceinline void operator=(StateS*& g) {
        if (p != g) { if (p && --p->refs64 == 0) p->Destroy(); p = g; if (p) p->refs64++; }
    }
};

static __forceinline void SetT5c(StateS* s, RefObj* n) {
    RefObj* o = s->unk5c;
    if (o != n) { if (o) o->DecRef(); s->unk5c = n; if (n) n->IncRef(); }
}
static __forceinline void SetT44(StateS* s, RefObj* n) {
    RefObj* o = s->unk44;
    if (o != n) { if (o) o->DecRef(); s->unk44 = n; if (n) n->IncRef(); }
}
static __forceinline OpsT* GetOps(StateS* s) {
    if (!s->unk30) s->unk30 = FUN_00890750x();
    return s->unk30;
}
static __forceinline void Op(StateS* s, int a, int b, int c) { GetOps(s)->FUN_008905a0(a, b, c); }
static __forceinline void Ops6(StateS* s, int f, int u) {
    Op(s, 0x1b, 0, 1); Op(s, 0xf, f, 1); Op(s, 7, 1, 1); Op(s, 0x17, 4, 1); Op(s, 0xe, 1, 1); Op(s, 0xa8, 0, 1);
}

void FUN_00b6d010()
{
    StateRef s;
    LocRef loc;
    s = g_s0;
    StateS* p = s.p;
    SetT5c(p, g_tA); SetT44(p, g_tC);
    Ops6(p, 0, 0);
    g_a0 = 0; g_b0 = 0;
    s = g_s1; p = s.p;
    SetT5c(p, g_tA); SetT44(p, g_tC);
    FUN_0088ff50(&loc.p); FUN_00b62c70(loc.p, 0, 1, 2, 1); p->FUN_00888d30(p->unk14, loc.p);
    Ops6(p, 1, 0);
    g_a1 = 0; g_b1 = 0;
    s = g_s2; p = s.p;
    SetT5c(p, g_tB); SetT44(p, g_tC);
    Ops6(p, 0, 0);
    g_a2 = 0x800; g_b2 = 0;
    s = g_s3; p = s.p;
    if (p->unk18 < 1) { FUN_0088ff50(&loc.p); FUN_00b62c70(loc.p, 0, 1, 2, 1); p->FUN_00888d30(p->unk14, loc.p); }
    SetT5c(p, g_tA); SetT44(p, g_tC);
    Ops6(p, 1, 0);
    { float f = g_f; GetOps(p); p->unk30->FUN_008905a0(0xc3, *(int*)&f, 1); }
    g_a3 = 0; g_b3 = 0;
    s = g_s4; p = s.p;
    if (p->unk18 < 1) { FUN_0088ff50(&loc.p); FUN_00b62c70(loc.p, 0, 1, 2, 1); p->FUN_00888d30(p->unk14, loc.p); }
    SetT5c(p, g_tB); SetT44(p, g_tC);
    Ops6(p, 1, 0);
    { float f = g_f; GetOps(p); p->unk30->FUN_008905a0(0xc3, *(int*)&f, 1); }
    g_a4 = 0x800; g_b4 = 0;
}
}   // namespace f3m_00b6d010

// @f3 0x00b6b8c0 (community match, verified in this file)
namespace f3m_00b6b8c0 {

template <class T> class F3Task210Pointer
{
  public:
    T* m_pObject;
    F3Task210Pointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    F3Task210Pointer(const F3Task210Pointer<T>& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~F3Task210Pointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    F3Task210Pointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    F3Task210Pointer<T>& operator=(const F3Task210Pointer<T>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(T* object) const
    {
        return m_pObject == object;
    }
    bool operator==(const F3Task210Pointer<T>& other) const
    {
        return m_pObject == other.m_pObject;
    }
    bool operator!=(const F3Task210Pointer<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};
namespace fo3_b6b8c0 {
struct StageReturn
{
    int unk00;
    long unk04;
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
    int refs;
    void __thiscall FUN_0088fe30();
    __forceinline void IncRefCount()
    {
        ++refs;
    }
    __forceinline void DecRefCount()
    {
        --refs;
        if (refs == 0)
            FUN_0088fe30();
    }
};
void __cdecl FUN_0088ff50(StageReturn*&);
typedef F3Task210Pointer<StageReturn> StagePtr;
int __cdecl FUN_00b62c70(void* a, int b, int c, int d, int e);
struct RendObj;
struct StageSub
{
    void __thiscall FUN_008905a0(int a, int b, int c);
};
void* __cdecl FUN_00890750();
struct RendVtbl
{
    void* f0;
    void(__thiscall* release)(RendObj*);
};
typedef long(__stdcall* ImpFn)(volatile long*);
struct RendObj
{
    RendVtbl* vtbl;
    long unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* f14;
    int f18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    StageSub* f30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RendObj* f44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RendObj* f5c;
    int unk60;
    int refs;
    __forceinline void SetPixelShader(RendObj* replacement, ImpFn decrement)
    {
        RendObj* old = f5c;
        if (old != replacement)
        {
            if (old && !decrement(&old->unk04))
                old->vtbl->release(old);
            f5c = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->unk04);
        }
    }
    __forceinline void SetVertexShader(RendObj* replacement, ImpFn decrement)
    {
        RendObj* old = f44;
        if (old != replacement)
        {
            if (old && !decrement(&old->unk04))
                old->vtbl->release(old);
            f44 = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->unk04);
        }
    }
    void FUN_00888c10();
    __forceinline void IncRefCount()
    {
        ++refs;
    }
    __forceinline void DecRefCount()
    {
        if (--refs == 0)
            FUN_00888c10();
    }
    __forceinline unsigned int GetStageCount() const
    {
        return f18;
    }
    __forceinline void SetState(int state, int value, int enabled)
    {
        if (!f30)
            f30 = (StageSub*)FUN_00890750();
        f30->FUN_008905a0(state, value, enabled);
    }
};

struct RendObj2
{
    void __thiscall FUN_00888d30(void* a, void* b);
    void __thiscall FUN_00888c10();
    void __thiscall FUN_00b80600(RendObj* a);
    void __thiscall FUN_00b79950(RendObj* a);
};
typedef F3Task210Pointer<RendObj> SPtr;
struct PassObj : RendObj
{
    __forceinline void DecRefCount()
    {
        int& r = refs;
        if (--r == 0)
            FUN_00888c10();
    }
};
typedef F3Task210Pointer<PassObj> PassPtr;

extern SPtr DAT_011746c0;
extern SPtr DAT_011746c4;
extern SPtr DAT_011746c8;
extern SPtr DAT_011746cc;
extern RendObj* DAT_01173b4c;
extern RendObj* DAT_01173b50;
extern RendObj* DAT_01173b88;
extern RendObj* DAT_01173b8c;
extern RendObj* DAT_01173840;
extern RendObj* DAT_01173844;
extern int DAT_01173348, DAT_01172768, DAT_01171b88;
extern int DAT_0117334c, DAT_0117276c, DAT_01171b8c;
extern int DAT_01173350, DAT_01172770, DAT_01171b90;
extern int DAT_01173354, DAT_01172774, DAT_01171b94;

// Configures four global render objects by adding a stage if needed, setting pixel/vertex shaders, render states, and associated global values.
// @fnv 0x00be9920
// pdb: ShadowLightShader::PresetFogPasses_1x | ShadowLightShader_Preset_1x.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void __cdecl FUN_00b6b8c0()
{
    SPtr pRendObj;
    StagePtr stage;
    pRendObj = DAT_011746c0;
    if (pRendObj->GetStageCount() < 1)
    {
        FUN_0088ff50(stage.m_pObject);
        FUN_00b62c70(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->FUN_00888d30(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_01173b4c, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_01173840, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_01173348 = 768;
    DAT_01172768 = 0;
    DAT_01171b88 = 0x300;

    pRendObj = DAT_011746c4;
    if (pRendObj->GetStageCount() < 1)
    {
        FUN_0088ff50(stage.m_pObject);
        FUN_00b62c70(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->FUN_00888d30(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_01173b50, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_01173844, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_0117334c = 768;
    DAT_0117276c = 0;
    DAT_01171b8c = 0x300;

    pRendObj = DAT_011746c8;
    if (pRendObj->GetStageCount() < 1)
    {
        FUN_0088ff50(stage.m_pObject);
        FUN_00b62c70(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->FUN_00888d30(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_01173b88, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_01173840, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_01173350 = 2816;
    DAT_01172770 = 0;
    DAT_01171b90 = 0x300;

    pRendObj = DAT_011746cc;
    if (pRendObj->GetStageCount() < 1)
    {
        FUN_0088ff50(stage.m_pObject);
        FUN_00b62c70(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->FUN_00888d30(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_01173b8c, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_01173844, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_01173354 = 2816;
    DAT_01172774 = 0;
    DAT_01171b94 = 0x300;
}
}
}   // namespace f3m_00b6b8c0

// @f3 0x00b6af40 (community match, verified in this file)
namespace f3m_00b6af40 {

namespace fo3_b6af40 {
struct GraphicsResource
{
    virtual void UnknownMethod();
    virtual void ReleaseSelf();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseSelf();
    }
};
struct GraphicsManager
{
    void FUN_008905a0(unsigned int setting, unsigned int mode, unsigned int enabled);
};
struct RefSlot
{
    GraphicsResource* m_pObject;
    RefSlot& operator=(GraphicsResource* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct GraphicsSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int device14;
    unsigned int version18;
    unsigned int GetVersion() const
    {
        return version18;
    }
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    GraphicsManager* manager30;
    unsigned int unk34, unk38, unk3c, unk40;
    RefSlot material44;
    unsigned int unk48, unk4c, unk50, unk54, unk58;
    RefSlot material5c;
    unsigned int unk60;
    unsigned int strongCount64;
    void FUN_00888d30(unsigned int device, unsigned int value);
    void FUN_00888c10();
};
struct TemporaryResource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int strongCount60;
    void FUN_0088fe30();
    void DecRefCount()
    {
        if (--strongCount60 == 0)
            FUN_0088fe30();
    }
};
struct ScopedSystem
{
    GraphicsSystem* ptr;
    ScopedSystem() : ptr(0)
    {}
    explicit ScopedSystem(GraphicsSystem* p) : ptr(p)
    {
        if (ptr)
            ++ptr->strongCount64;
    }
    ~ScopedSystem()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00888c10();
    }
    void reset(GraphicsSystem* p)
    {
        if (p != ptr)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    void resetFromGlobal(GraphicsSystem* const& p)
    {
        if (ptr != p)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
};
struct ScopedTemporary
{
    TemporaryResource* ptr;
    ScopedTemporary() : ptr(0)
    {}
    ~ScopedTemporary()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};

void __cdecl FUN_0088ff50(ScopedTemporary*);
void __cdecl FUN_00b62c70(TemporaryResource*,unsigned int,unsigned int,unsigned int,unsigned int);
GraphicsManager* __cdecl FUN_00890750();
extern GraphicsSystem* DAT_01174688;
extern GraphicsSystem* DAT_0117468c;
extern GraphicsSystem* DAT_01174690;
extern GraphicsSystem* DAT_01174694;
extern GraphicsResource* DAT_01173b54;
extern GraphicsResource* DAT_01173bc8;
extern GraphicsResource* DAT_01173848;
extern GraphicsResource* DAT_0117384c;
extern unsigned int DAT_01173310;
extern unsigned int DAT_01173314;
extern unsigned int DAT_01173318;
extern unsigned int DAT_0117331c;
extern unsigned int DAT_01172730;
extern unsigned int DAT_01172734;
extern unsigned int DAT_01172738;
extern unsigned int DAT_0117273c;
extern unsigned int DAT_01170f70;
extern unsigned int DAT_01170f74;
extern unsigned int DAT_01170f78;
extern unsigned int DAT_01170f7c;

// @fnv 0x00be8fb0
void __cdecl FUN_00b6af40()
{
    ScopedSystem system;
    ScopedTemporary temporary;

    system.resetFromGlobal(DAT_01174688);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 3, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173b54;
    system->material44 = DAT_01173848;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(14, 0, 1);
    DAT_01173310 = 1028;
    DAT_01172730 = 36;
    DAT_01170f70 = 4;

    system.resetFromGlobal(DAT_0117468c);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 3, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173b54;
    system->material44 = DAT_0117384c;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(14, 0, 1);
    DAT_01173314 = 1028;
    DAT_01172734 = 36;
    DAT_01170f74 = 4;

    system.resetFromGlobal(DAT_01174690);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 3, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173bc8;
    system->material44 = DAT_01173848;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(14, 0, 1);
    DAT_01173318 = 3076;
    DAT_01172738 = 36;
    DAT_01170f78 = 4;

    system.resetFromGlobal(DAT_01174694);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 3, 1, 2, 1);
        system->FUN_00888d30(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173bc8;
    system->material44 = DAT_0117384c;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(14, 0, 1);
    DAT_0117331c = 3076;
    DAT_0117273c = 36;
    DAT_01170f7c = 4;
}

}
}   // namespace f3m_00b6af40

// @f3 0x00b693a0 (community match, verified in this file)
namespace f3m_00b693a0 {

namespace fo3_b693a0 {
struct GraphicsResource
{
    virtual void UnknownMethod();
    virtual void ReleaseSelf();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseSelf();
    }
};
struct GraphicsManager
{
    void FUN_008905a0(unsigned int setting, unsigned int mode, unsigned int enabled);
};
struct RefSlot
{
    GraphicsResource* m_pObject;
    RefSlot& operator=(GraphicsResource* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct GraphicsSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int device14;
    unsigned int version18;
    unsigned int GetVersion() const
    {
        return version18;
    }
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    GraphicsManager* manager30;
    unsigned int unk34, unk38, unk3c, unk40;
    RefSlot material44;
    unsigned int unk48, unk4c, unk50, unk54, unk58;
    RefSlot material5c;
    unsigned int unk60;
    unsigned int strongCount64;
    void FUN_00888d30(unsigned int device, unsigned int value);
    void FUN_00888c10();
};
struct TemporaryResource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int strongCount60;
    void FUN_0088fe30();
    void DecRefCount()
    {
        if (--strongCount60 == 0)
            FUN_0088fe30();
    }
};
struct ScopedSystem
{
    GraphicsSystem* ptr;
    ScopedSystem() : ptr(0)
    {}
    explicit ScopedSystem(GraphicsSystem* p) : ptr(p)
    {
        if (ptr)
            ++ptr->strongCount64;
    }
    ~ScopedSystem()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00888c10();
    }
    void reset(GraphicsSystem* p)
    {
        if (p != ptr)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    void resetFromGlobal(GraphicsSystem* const& p)
    {
        if (ptr != p)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
};
struct ScopedTemporary
{
    TemporaryResource* ptr;
    ScopedTemporary() : ptr(0)
    {}
    ~ScopedTemporary()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};

void __cdecl FUN_0088ff50(ScopedTemporary*);
void __cdecl FUN_00b62c70(TemporaryResource*,unsigned int,unsigned int,unsigned int,unsigned int);
GraphicsManager* __cdecl FUN_00890750();
extern GraphicsSystem* DAT_01173f68;
extern GraphicsSystem* DAT_01173f6c;
extern GraphicsResource* DAT_01173b48;
extern GraphicsResource* DAT_0117383c;
extern GraphicsResource* DAT_01173bc4;
extern unsigned int DAT_0116f324;
extern unsigned int DAT_0116f328;
extern unsigned int DAT_0116f2fc;
extern unsigned int DAT_01172bf0, DAT_01172010, DAT_01172bf4, DAT_01172014;

// Configures two graphics systems: sets materials and manager entries, and for version < 4 creates and registers four temporary resources per system.
// @fnv 0x00be7420
// pdb: ShadowLightShader::PresetZOnlyPasses_1x | ShadowLightShader_Preset_1x.obj | fnv360_0822_retail, objrun_prop, low
void __cdecl FUN_00b693a0()
{
    ScopedSystem system;
    ScopedTemporary temporary;
    system.reset(DAT_01173f68);

    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);

        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 3, 2, 1);
        temporary.ptr->unk08 = DAT_0116f324;
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);

        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 3, 2, 1);
        temporary.ptr->unk08 = DAT_0116f328;
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);

        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 3, 1, 2, 1);
        temporary.ptr->unk08 = DAT_0116f2fc;
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_01173b48;
    system->material44 = DAT_0117383c;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(14, 1, 1);
    DAT_01172bf0 = 128;
    DAT_01172010 = 12;

    system.resetFromGlobal(DAT_01173f6c);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 3, 2, 1);
        temporary.ptr->unk08 = DAT_0116f324;
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 3, 2, 1);
        temporary.ptr->unk08 = DAT_0116f328;
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 3, 1, 2, 1);
        temporary.ptr->unk08 = DAT_0116f2fc;
        system->FUN_00888d30(system->device14, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_01173bc4;
    system->material44 = DAT_0117383c;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(14, 1, 1);
    DAT_01172bf4 = 0x880;
    DAT_01172014 = 12;
}

}
}   // namespace f3m_00b693a0
