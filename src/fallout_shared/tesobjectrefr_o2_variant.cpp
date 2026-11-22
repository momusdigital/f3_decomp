#include "f3_common.h"
// src/fallout_shared/tesobjectrefr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectrefr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectrefr_decls.h"

struct FUN_00c9c240_holder
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00c9c240();
    void FUN_00c9d600();
};

// @fnv 0x00c9d600
// pdb: bhkEntity::Deactivate | bhkEntity.obj | fnv360_0822_retail, call_gap_sim, low
void FUN_00c9c240_holder::FUN_00c9d600()
{
    if (this && m8)
        ((FUN_00c9c240_holder*)m8)->FUN_00c9c240();
}

extern int DAT_0126810c;
extern int DAT_01268238;
extern const void* DAT_01030394;
extern const void* DAT_0103078c;
struct bhkRefObject
{
    void* vtbl;
    int f4;
    int f8;
    int fc;
    int f10;
    unsigned char f14;
    bhkRefObject* Initialize();
};

struct ProjectileListener
{
    void* vfptr;
    int m4;
    int m8;
    void FUN_00c876a0();
};
// @fnv 0x00c876a0
// pdb: bhkSerializable::Kill | bhkSerializable.obj | fnv360_0822_retail, vtable, medium
void ProjectileListener::FUN_00c876a0()
{
    typedef void(__thiscall * Fn)(void*, int);
    if (m8 != 0)
        ((Fn)(*(void***)this)[0x8c / 4])(this, 0);
    ((Fn)(*(void***)this)[0xa4 / 4])(this, 1);
}

struct hkReferencedObject
{
    void removeReference();
};
void FUN_00c876a0();

struct CallRet
{
    void hkpWorld_updateCollisionFilterOnEntity(void* a, int b, int c);
};
struct Holder00c9d5d0
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual CallRet* GetRet();
    void* unk4;
    void* unk8;
    void FUN_00c9d5d0();
};
// @fnv 0x00c9d5d0
// pdb: bhkEntity::UpdateCFilter | bhkEntity.obj | fnv360_0822_retail, caller_sim, medium
void Holder00c9d5d0::FUN_00c9d5d0()
{
    CallRet* p = GetRet();
    if (p)
        p->hkpWorld_updateCollisionFilterOnEntity(unk8, 0, 1);
}

extern int DAT_01268238;
struct FUN_00c876a0_holder
{
    virtual ~FUN_00c876a0_holder();
    void FUN_00c876a0();
};
struct FUN_00c9f3b0 : FUN_00c876a0_holder
{
    virtual ~FUN_00c9f3b0();
};
// @fnv 0x00c9f3b0
FUN_00c9f3b0::~FUN_00c9f3b0()
{
    FUN_00c876a0();
    --DAT_01268238;
}

struct WorldHolder
{
    void hkpWorld_updateCollisionFilterOnPhantom(void* a, int b);
};
struct PhantomBase
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
};
struct bhkAabbPhantom : PhantomBase
{
    virtual WorldHolder* GetWorld();
    int m4;
    void* m8;
    void FUN_00c9f460();
};
// @fnv 0x00c9f460
// pdb: bhkPhantom::UpdateCFilter | bhkPhantom.obj | fnv360_0822_retail, caller_sim, medium
void bhkAabbPhantom::FUN_00c9f460()
{
    WorldHolder* w = GetWorld();
    if (w)
        w->hkpWorld_updateCollisionFilterOnPhantom(m8, 1);
}

extern float DAT_010c72bc;
struct InnerS
{
    char pad[16];
    float f10;
};
struct MyObj
{
    char pad[8];
    InnerS* p8;
    void __thiscall FUN_00c84e20(void* a);
};
struct OutS
{
    int i0;
    float f4;
};
// @fnv 0x00c9fb70
// pdb: bhkConvexShape::CopyCinfo | bhkConvexShape.obj | fnv360_0822_retail, call_seq + bridge(hash|call_seq) + skyrim(objrun), high
void __fastcall bhkConvexShape_CopyCinfo(MyObj* _this, int, OutS* _out)
{
    _this->FUN_00c84e20(_out);
    if (_this && _this->p8)
    {
        volatile float v = _this->p8->f10;
        _out->f4 = v;
        return;
    }
    volatile float u = DAT_010c72bc;
    _out->f4 = u;
}

struct ArgB
{
    char _0[16];
    float f10;
};
struct RetV
{
    char _0[4];
    float f4;
};
struct bhkSphereShape
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual RetV* Target(char* p);
    void __thiscall bhkShape_CopyMembers(void* a, ArgB* b);
    void __thiscall FUN_00ca0740(void* a, ArgB* b);
};

struct MM
{
    void Deallocate(void* p);
    void FUN_00cb2ff0();
    void* FUN_00cb30a0(unsigned int);
};
extern MM _g_memoryManager;
// @fnv 0x00cb30a0
// pdb: bhkRagdollController::`scalar deleting destructor' | bhkRagdollController.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: Projectile::UpdateInstant)
void* MM::FUN_00cb30a0(unsigned int f)
{
    FUN_00cb2ff0();
    if (f & 1)
    {
        if (this)
        {
            char* b = (char*)this - *(unsigned char*)((char*)this - 1);
            _g_memoryManager.Deallocate(b);
        }
    }
    return this;
}

namespace fnv_00cb3860 {
extern int DAT_010302bc;
extern int DAT_01030394;
extern int DAT_010c879c;
extern int DAT_0126810c;
extern unsigned int DAT_012681bc;
extern int DAT_012681fc;
extern int DAT_012683c0;
struct bhkRefObject
{
    void* m0;
    void* m4;
    void* m8;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    bhkRefObject* Initialize();
};
extern const void* vftable_bhkLiquidAction;
struct FUN_00cb3860 : public bhkRefObject
{
    FUN_00cb3860();
};
// @fnv 0x00cb3860
// pdb: bhkRigidBodyT::bhkRigidBodyT | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, high
FUN_00cb3860::FUN_00cb3860()
{
    Initialize();
    m0 = &DAT_01030394;
    m10 = 0;
    mC = 0;
    ++DAT_0126810c;
    m0 = &DAT_010302bc;
    ++DAT_012681fc;
    m0 = &vftable_bhkLiquidAction;
    m14 = 0;
    m18 = 0;
    ++DAT_012681bc;
    m10 = 0;
    m0 = &DAT_010c879c;
    ++DAT_012683c0;
}
}  // namespace fnv_00cb3860

extern int DAT_012681fc;

extern int DAT_01268250;
struct FUN_0056e780_Class
{
    virtual ~FUN_0056e780_Class();
    void FUN_00ca0540();
};
struct FUN_00c9fb00 : FUN_0056e780_Class
{
    virtual ~FUN_00c9fb00();
};
// @fnv 0x00c9fb00
// pdb: bhkConvexShape::~bhkConvexShape | bhkConvexShape.obj | fnv360_0822_retail, call_seq, high
FUN_00c9fb00::~FUN_00c9fb00()
{
    FUN_00c876a0();
    --DAT_01268250;
}

extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_0126825c;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

extern int DAT_01030864;
extern int DAT_01268244;

struct S_00cb79d0_Base
{
    void* vtbl;
    char pad[8];
    int f0c;
    int f10;
    unsigned char f14;

    S_00cb79d0_Base();
};

struct Object_00c9f5a0 : S_00cb79d0_Base, A51BF0Base
{
    Object_00c9f5a0() : S_00cb79d0_Base()
    {
        vtbl = (void*)&DAT_01030394;
        f0c = 0;
        f10 = 0;
        ++DAT_0126810c;
        vtbl = (void*)&DAT_0103078c;
        ++DAT_01268238;
        vtbl = (void*)&DAT_01030864;
        ++DAT_01268244;
        f14 = 0;
    }
};

// @f3 0x0090dfd0 (community match, verified in this file)
// pdb: bhkAabbPhantom::CreateObject | bhkAabbPhantom.obj | fnv360_0822_retail, objrun, medium
void* FUN_00c9f5a0()
{
    return new Object_00c9f5a0;
}


struct FUN_00c877b0
{
    virtual ~FUN_00c877b0();
};

struct FUN_00c84c50 : FUN_00c877b0
{
    virtual ~FUN_00c84c50();
};

void FUN_00c876a0();
extern int DAT_012680f8;

// @fnv 0x00c84c50
// pdb: bhkShape::~bhkShape | bhkShape.obj | fnv360_0822_retail, call_seq, high
FUN_00c84c50::~FUN_00c84c50()
{
    FUN_00c876a0();
    --DAT_012680f8;
}

extern int DAT_0126810c;

extern __declspec(thread) unsigned int g_havokThreadMode;

struct CollisionResult
{
    unsigned short kind;
    unsigned short enabled;
    struct CollisionRecord* record;
    unsigned int data08;
    unsigned int data0c;
    unsigned int state;
};
struct CollisionValue
{
    unsigned int data00;
    unsigned int data04;
    CollisionRecord* record;
};
struct CollisionRecord
{
    unsigned int data00;
    unsigned int data04;
    struct CollisionHandler* handler;
};
struct CollisionHandler
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
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
    virtual CollisionValue* Find(int target);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual bool IsAllowed(int target);
};
struct ScopedMode
{
    unsigned int oldValue;
    ScopedMode() : oldValue(g_havokThreadMode)
    {
        g_havokThreadMode = 0x10;
    }
    ~ScopedMode()
    {
        g_havokThreadMode = oldValue;
    }
};

struct NiRTTI
{
    const char* m_pcName;
};

struct NiObject
{
    virtual void v00();
    virtual void v01();
    virtual const NiRTTI* GetRTTI();
};

template <class T> struct NiTMallocInterface
{
};

template <class T, class A> struct NiTPrimitiveArray
{
    void* vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int Add(T element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > DebugStrArray;

struct hkShapeStub
{
    void* vtbl;
    int unk04;
    NiObject* userData;
};

struct hkCdBodyStub
{
    hkShapeStub* m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct hkObjHead
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkWorldObjStub : hkObjHead, hkCdBodyStub
{
};

struct DebugHelper_c849b0
{
    int value;
    DebugHelper_c849b0(int v) : value(v)
    {}
    void Fill(DebugStrArray* arr);
};

extern __declspec(thread) int tlsHeapContext;

struct HeapContextGuard
{
    int saved;
    HeapContextGuard(int ctx)
    {
        saved = tlsHeapContext;
        tlsHeapContext = ctx;
    }
    ~HeapContextGuard()
    {
        tlsHeapContext = saved;
    }
};

char* MakeDebugHeader(const char* name);
char* MakeDebugLine(const char* label, const char* value);
int SprintfS(char* buf, int size, const char* fmt, ...);
extern const char* g_debugHeaderName;

struct bhkBase_c878c0
{
    void* vtbl;
    int unk04;
    hkWorldObjStub* m_pObject;
    hkCdBodyStub* GetBody()
    {
        return m_pObject;
    }
    void BaseDebugInfo(DebugStrArray* arr);
};

struct bhkWorldObject_c86190 : bhkBase_c878c0
{
    void FUN_00c86190(DebugStrArray* arr);
};

// @f3 0x008f9fc0 (community match, verified in this file)
static __forceinline hkCdBodyStub* BodyOf(bhkBase_c878c0* o)
{
    return o ? o->GetBody() : 0;
}

// pdb: bhkWorldObject::GetViewerStrings | bhkWorldObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: apStrings
void bhkWorldObject_c86190::FUN_00c86190(DebugStrArray* arr)
{
    BaseDebugInfo(arr);
    arr->Add(MakeDebugHeader(g_debugHeaderName));
    hkCdBodyStub* b = BodyOf(this);
    DebugHelper_c849b0 helper(b ? b->unk1C : 0);
    helper.Fill(arr);
    hkCdBodyStub* body = BodyOf(this);
    if (body)
    {
        hkShapeStub* shape = body->m_pCollisionShape;
        if (shape)
        {
            NiObject* niShape = shape->userData;
            if (niShape)
            {
                char buf[0x80];
                SprintfS(buf, 0x80, "%s: 0x%8X", niShape->GetRTTI()->m_pcName, niShape);
                arr->Add(MakeDebugLine("Shape", buf));
            }
        }
    }
}


extern int DAT_012681b0;

class FUN_00c8bed0_base_cls
{
  public:
    virtual void unk00();
    ~FUN_00c8bed0_base_cls();
    int unk04;
};

class bhkTransformShape : public FUN_00c8bed0_base_cls // src: F3_EXE vtable 0x00dfcfd4 (old: FUN_00c8bed0_cls)
{
  public:
    virtual ~bhkTransformShape();
    void unk08();
};

// @fnv 0x00c8bed0
// pdb: bhkTransformShape::~bhkTransformShape | bhkTransformShape.obj | fnv360_0822_retail, call_seq, medium
bhkTransformShape::~bhkTransformShape()
{
    this->unk08();
    DAT_012681b0--;
}

struct FUN_00c9eb30 : FUN_00c9f3b0
{
    virtual ~FUN_00c9eb30();
};

namespace fnv_00c9eec0 {
struct FUN_00c9eb30 : FUN_00c876a0_holder
{
    virtual ~FUN_00c9eb30();
};

}  // namespace fnv_00c9eec0

struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
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
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;

void* __cdecl FUN_00aa13e0(unsigned int size);
void FUN_00c876f0();
void FUN_00c87700();

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

inline void* operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}

struct S_00c9f1e0_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct S_00c9f1e0_Elem
{
    S_00c9f1e0_Shape* shape;
};
struct S_00c9f1e0_Base1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c9f1e0_Base2
{
    S_00c9f1e0_Shape* shape;
};
struct S_00c9f1e0_Range
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int begin;
    int end;
};
struct S_00c9f1e0_World;
typedef void(__cdecl* S_00c9f1e0_Fn)(S_00c9f1e0_Base2*, S_00c9f1e0_Elem*, S_00c9f1e0_World*, S_00c9f1e0_Range*);
struct S_00c9f1e0_Entry
{
    S_00c9f1e0_Fn fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_00c9f1e0_Disp
{
    unsigned char types[77][32];
    int unk9a0;
    int unk9a4;
    S_00c9f1e0_Entry funcs[32];
};
struct S_00c9f1e0_World
{
    S_00c9f1e0_Disp* disp;
};
struct S_00c9f1e0_Holder
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
    S_00c9f1e0_World* world;
};
struct S_00c9f1e0_Ctx : S_00c9f1e0_Base1, S_00c9f1e0_Base2
{
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00c9f1e0_Elem** items;
    int count;
};
struct S_00c9f1e0_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual S_00c9f1e0_Holder* GetWorld();
    int unk04;
    S_00c9f1e0_Ctx* ctx;
    void FUN_00c9f1e0(S_00c9f1e0_Range* r);
};
// @f3 0x0090e6c0 (community match, verified in this file)
struct R9_Holder
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
    S_00c9f1e0_World* world;
};
struct R9_Ctx : S_00c9f1e0_Base1, S_00c9f1e0_Base2
{
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00c9f1e0_Elem** items;
    int count;
};
struct R9_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual R9_Holder* GetWorld();
    int unk04;
    R9_Ctx* ctx;
};
// pdb: bhkSimpleShapePhantom::GetFixedClosestPoints | bhkSimpleShapePhantom.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: arCollector
void S_00c9f1e0_Obj::FUN_00c9f1e0(S_00c9f1e0_Range* r)
{
    R9_Holder* h = ((R9_Obj*)this)->GetWorld();
    S_00c9f1e0_World* w = h->world;
    S_00c9f1e0_Disp* d = w->disp;
    R9_Ctx* c = ((R9_Obj*)this)->ctx;
    S_00c9f1e0_Base2* b;
    if (c)
        b = c;
    else
        b = 0;
    for (int i = c->count - 1; i >= 0; --i)
    {
        if (r->end == r->begin)
            break;
        S_00c9f1e0_Elem** slot = &c->items[i];
        unsigned char t = d->types[b->shape->type + 13][(*slot)->shape->type];
        d->funcs[t].fn(b, *slot, w, r);
    }
}


extern __declspec(thread) int g_iC9F270MemContext;

class C9F270MemContext
{
  public:
    C9F270MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iC9F270MemContext;
        g_iC9F270MemContext = aiMemoryContext;
    }
    ~C9F270MemContext()
    {
        g_iC9F270MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

extern "C" char* __cdecl FUN_00a7d330(const char* pcName);

class C9F270StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

__declspec(thread) int tlsMode = 0x3b;
struct ReleaseObject
{
    void DestroyObject(int value);
};
struct FUN_00c9f320_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00c9f320();
};
struct TlsGuard
{
    int previous;
    TlsGuard()
    {
        previous = tlsMode;
        tlsMode = 0x10;
    }
    ~TlsGuard()
    {
        tlsMode = previous;
    }
};
// @f3 0x006ba760 (community match, verified in this file)
extern int DAT_00e0c1e4;

struct View6ba760
{
    void* unk00;
    int unk04;
    ReleaseObject* unk08;
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
    char unk70;
    char unk71;
    void FUN_006a2740();
};

struct Guard6ba760
{
    View6ba760* self;
    Guard6ba760(View6ba760* s): self(s) { s->unk00 = &DAT_00e0c1e4; }
    ~Guard6ba760()
    {
        self->FUN_006a2740();
    }
};

// pdb: SummonCreatureEffect::`scalar deleting destructor' | SummonCreatureEffect.obj | fnv360_0822_retail, caller_sim, low
void FUN_00c9f320_object::FUN_00c9f320()
{
    View6ba760* view = reinterpret_cast<View6ba760*>(this);
    Guard6ba760 scope(view);
    if (view->unk71)
    {
        ReleaseObject* object = view->unk08;
        if (object)
        {
            object->DestroyObject(1);
        }
    }
}


struct PhysicsAction
{
    bool __thiscall FUN_00c68cb0(void* owner);
};
struct LinkedObject
{
    PhysicsAction* GetAction() const
    {
        return *reinterpret_cast<PhysicsAction* const*>(reinterpret_cast<const char*>(this) + 0x350);
    }
};

void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
struct ProjectileCreator
{
    void __thiscall FUN_00c85900(Object_00c9f5a0* projectile, int mode);
    Object_00c9f5a0* __thiscall FUN_00c9f640(int mode);
};
// @f3 0x0090e070 (community match, verified in this file)
extern int DAT_010f3194;
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
extern int DAT_010f3294;

struct ObjectFO3 : S_00cb79d0_Base, A51BF0Base
{
    ObjectFO3() : S_00cb79d0_Base()
    {
        vtbl = (void*)&DAT_01030394;
        f0c = 0;
        f10 = 0;
        ++DAT_0126810c;
        vtbl = (void*)&DAT_0103078c;
        ++DAT_01268238;
        vtbl = (void*)&DAT_01030864;
        ++DAT_010f3294;
        f14 = 0;
    }
};

struct PcFO3
{
    void FUN_008f9990(Object_00c9f5a0* projectile, int mode);
};

// pdb: bhkAabbPhantom::CreateClone | bhkAabbPhantom.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
Object_00c9f5a0* ProjectileCreator::FUN_00c9f640(int mode)
{
    DAT_00d9b09c(&DAT_010f3194);
    ObjectFO3* projectile = new ObjectFO3;
    ((PcFO3*)this)->FUN_008f9990((Object_00c9f5a0*)projectile, mode);
    DAT_00d9b0a0(&DAT_010f3194);
    return (Object_00c9f5a0*)projectile;
}


struct TLSBlock
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
    int value;
};
__declspec(thread) TLSBlock g_tls;
struct ThreadFlagGuard
{
    int previous;
    ThreadFlagGuard()
    {
        previous = g_tls.value;
        g_tls.value = 16;
    }
    ~ThreadFlagGuard()
    {
        g_tls.value = previous;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* Allocate(unsigned int);
};
struct Pool
{
    int unk0, unk4, unk8, unkc;
    Allocator* allocator;
};
extern "C" Pool* __cdecl FUN_00c85750();
struct FUN_00cf2cb0
{
    int unk0;
    unsigned short length;
    static void* operator new(unsigned int count)
    {
        Pool* pool = FUN_00c85750();
        FUN_00cf2cb0* p = (FUN_00cf2cb0*)pool->allocator->Allocate(224);
        p->length = 224;
        return p;
    }
    static void operator delete(void*);
    FUN_00cf2cb0(void* contents, int tag);
};
extern "C" void __fastcall FUN_00c905b0(FUN_00cf2cb0*);

extern __declspec(thread) int g_iC9F970AllocTag;

struct BC9F970AllocTagScope
{
    int m_iSaved;

    BC9F970AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC9F970AllocTag;
        g_iC9F970AllocTag = aiAllocationTag;
    }
    ~BC9F970AllocTagScope()
    {
        g_iC9F970AllocTag = m_iSaved;
    }
};

class BC9F970StringArray
{
  public:
    virtual ~BC9F970StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

struct MemContextTLS
{
    int unk2b4;
};
extern __declspec(thread) MemContextTLS g_memContextTLS;

struct MemContextGuard
{
    int iOld;
    MemContextGuard()
    {
        iOld = g_memContextTLS.unk2b4;
        g_memContextTLS.unk2b4 = 0x10;
    }
    ~MemContextGuard()
    {
        g_memContextTLS.unk2b4 = iOld;
    }
};

struct ViewerStringArray
{
    char** m_pBase;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};

struct ViewerRTTI
{
    const char* m_pcName;
};
extern ViewerRTTI g_01268254;

char* CreateDebugString(const char* pcText);
char* CreateDebugString(const char* pcPrefix, float fValue);

extern float DAT_010c72bc;

struct SphereHkShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float fRadius;
};

struct SphereShapeBase
{
    void* vtbl;
    int unk04;
    void BaseGetViewerStrings(ViewerStringArray* apViewerStrings);
};

struct SphereShape : SphereShapeBase
{
    SphereHkShape* pHkShape;
    float GetRadius()
    {
        return (this && pHkShape) ? pHkShape->fRadius : DAT_010c72bc;
    }
    void FUN_00c9fc50(ViewerStringArray* apViewerStrings);
};

// @f3 0x0090c5a0 (community match, verified in this file)
extern double FUN_00db88e8;
// pdb: bhkConvexShape::GetViewerStrings | bhkConvexShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apStrings
void SphereShape::FUN_00c9fc50(ViewerStringArray* apViewerStrings)
{
    BaseGetViewerStrings(apViewerStrings);
    apViewerStrings->Add(CreateDebugString(g_01268254.m_pcName));
    apViewerStrings->Add(CreateDebugString("Radius", GetRadius() * FUN_00db88e8));
}


extern int DAT_0126825c;

struct SphereScalingMethod : bhkSphereShape
{
    void __thiscall FUN_00c9fea0(void* first, ArgB* second);
};
// @f3 0x009125b0 (community match, verified in this file)
struct SphereScaleFieldsF3
{
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    float m_20, m_24, m_28, m_2c;
};
// pdb: bhkNiTriStripsShape::CopyMembers | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apDest, arCloneData
void SphereScalingMethod::FUN_00c9fea0(void* first, ArgB* second)
{
    char flag;
    SphereScaleFieldsF3* result = reinterpret_cast<SphereScaleFieldsF3*>(Target(&flag));
    if (result)
    {
        float scale = second->f10;
        volatile float& initial = result->m_20;
        result->m_20 = initial * scale;
        result->m_24 *= scale;
        result->m_28 *= scale;
        result->m_2c *= scale;
    }
    bhkShape_CopyMembers(first, second);
}


struct Tls_ca0090
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) Tls_ca0090 g_tls_ca0090;

extern float DAT_010c72bc;
extern char DAT_011f6238;

struct TlsGuard_ca0090
{
    unsigned int m_saved;
    TlsGuard_ca0090()
    {
        m_saved = g_tls_ca0090.m_2b4;
        g_tls_ca0090.m_2b4 = 0x10;
    }
    ~TlsGuard_ca0090()
    {
        g_tls_ca0090.m_2b4 = m_saved;
    }
};

namespace fnv_00ca0410 {
extern __declspec(thread) int g_tlsMemContext;

struct MemContextGuard
{
    int iOld;
    MemContextGuard(int iNew)
    {
        iOld = g_tlsMemContext;
        g_tlsMemContext = iNew;
    }
    ~MemContextGuard()
    {
        g_tlsMemContext = iOld;
    }
};

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    void Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};

}  // namespace fnv_00ca0410

class CA0540Base
{
  public:
    virtual ~CA0540Base();

    void Shutdown();
};

class FUN_00ca0540 : public CA0540Base
{
  public:
    virtual ~FUN_00ca0540();

    static unsigned int ms_uiInstances;
};

// @fnv 0x00ca0540
// pdb: bhkSimpleShapePhantom::~bhkSimpleShapePhantom | bhkSimpleShapePhantom.obj | fnv360_0822_retail, call_seq, high
FUN_00ca0540::~FUN_00ca0540()
{
    Shutdown();
    --ms_uiInstances;
}

extern __declspec(thread) int g_iCA05B0AllocTag;

struct BCA05B0AllocTagScope
{
    int m_iSaved;

    BCA05B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA05B0AllocTag;
        g_iCA05B0AllocTag = aiAllocationTag;
    }
    ~BCA05B0AllocTagScope()
    {
        g_iCA05B0AllocTag = m_iSaved;
    }
};

class BCA05B0StringArray
{
  public:
    virtual ~BCA05B0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

extern int DAT_01268280;

class FUN_00ca0660_base
{
  public:
    virtual void unk00();
    ~FUN_00ca0660_base();
    int unk04;
};

class FUN_00ca0660 : public FUN_00ca0660_base
{
  public:
    virtual ~FUN_00ca0660();
    void unk08();
};

// @fnv 0x00ca0660
// pdb: bhkSphereShape::~bhkSphereShape | bhkSphereShape.obj | fnv360_0822_retail, call_seq, high
FUN_00ca0660::~FUN_00ca0660()
{
    this->unk08();
    DAT_01268280--;
}

class CA0840Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern __declspec(thread) int g_iCA0840MemContext;
extern float DAT_010c72bc;
extern CA0840Heap g_memoryManager;

class CA0840MemContext
{
  public:
    CA0840MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCA0840MemContext;
        g_iCA0840MemContext = aiMemoryContext;
    }
    ~CA0840MemContext()
    {
        g_iCA0840MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

class CA0840Output
{
  public:
    CA0840Output() : m_pkTarget(0), m_fValue(DAT_010c72bc)
    {}

    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    void* m_pkTarget;
    float m_fValue;
};

class CAACF0Base
{
  public:
    virtual ~CAACF0Base();

    void Shutdown();
};

class FUN_00caacf0 : public CAACF0Base
{
  public:
    virtual ~FUN_00caacf0();

    static unsigned int ms_uiInstances;
};

// @fnv 0x00caacf0
// pdb: WeaponObject::Kill | WeaponObject.obj | tesv_win, objopen_prop, low
FUN_00caacf0::~FUN_00caacf0()
{
    Shutdown();
    --ms_uiInstances;
}

extern int DAT_012683c8;

// @fnv 0x00cb3060
// pdb: bhkSpringAction::GetRTTI | bhkSpringAction.obj | fnv360_0822_retail, objrun_open, low
void* FUN_00cb3060()
{
    return &DAT_012683c8;
}

namespace fnv_00cb3a40 {
void FUN_00c876f0();
void FUN_00c87700() throw();
extern __declspec(thread) int threadMode;
struct MemoryAllocator
{
    void* FUN_00aa3e40(unsigned int bytes);
};
extern MemoryAllocator DAT_011f6238;
struct FUN_00cb3860
{
    FUN_00cb3860();
    static __forceinline unsigned char* align(unsigned char* memory)
    {
        unsigned char mod = (unsigned char)(unsigned int)memory;
        mod &= 15;
        unsigned char offset = 16;
        offset -= mod;
        memory += offset;
        memory[-1] = offset;
        return memory;
    }
    static void* operator new(unsigned int)
    {
        return align((unsigned char*)DAT_011f6238.FUN_00aa3e40(0x50));
    }
};
struct ThreadRouterScope
{
    int previousMode;
    ThreadRouterScope() : previousMode(threadMode)
    {
        threadMode = 16;
    }
    ~ThreadRouterScope() throw()
    {
        FUN_00c87700();
        threadMode = previousMode;
    }
};
}  // namespace fnv_00cb3a40

class CC2350Base
{
  public:
    virtual ~CC2350Base();
};

extern int g_iCC2350Count;

class bhkCachingShapePhantom : public CC2350Base // src: F3_EXE vtable 0x00e3314c (old: FUN_00cc2350)
{
  public:
    void Release();

    virtual ~bhkCachingShapePhantom();
};

// @fnv 0x00cc2350
// pdb: bhkCachingShapePhantom::~bhkCachingShapePhantom | bhkCachingShapePhantom.obj | fnv360_0822_retail, caller_sim, high
bhkCachingShapePhantom::~bhkCachingShapePhantom()
{
    Release();
    --g_iCC2350Count;
}

extern int DAT_0126869c;

struct FUN_00ccdbc0 : FUN_00c9fb00
{
    void FUN_00c876a0();
    virtual ~FUN_00ccdbc0();
};

// @fnv 0x00ccdbc0
FUN_00ccdbc0::~FUN_00ccdbc0()
{
    FUN_00c876a0();
    --DAT_0126869c;
}

class CCE900Base
{
  public:
    virtual ~CCE900Base();
};

extern int g_iCCE900Count;

class FUN_00cce900 : public CCE900Base
{
  public:
    void Release();

    virtual ~FUN_00cce900();
};

// @fnv 0x00cce900
// pdb: bhkConvexVerticesShape::~bhkConvexVerticesShape | bhkConvexVerticesShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00cce900::~FUN_00cce900()
{
    Release();
    --g_iCCE900Count;
}

extern int DAT_012686c0;

class bhkConvexTransformShape : public FUN_00c9fb00 // src: F3_EXE vtable 0x00e7b8b4 (old: FUN_00ccf740_cls)
{
  public:
    virtual ~bhkConvexTransformShape();
    void FUN_00c876a0();
};

// @fnv 0x00ccf740
bhkConvexTransformShape::~bhkConvexTransformShape()
{
    FUN_00c876a0();
    --DAT_012686c0;
}

class NiObjectC9E
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int uiSize);

    virtual ~NiObjectC9E();
};

class NiControllerC9E : public NiObjectC9E
{
  public:
    NiControllerC9E();

    static NiObjectC9E* FUN_00c9ef30();

    unsigned int m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

// @fnv 0x00c9ef30
NiObjectC9E* NiControllerC9E::FUN_00c9ef30()
{
    return new NiControllerC9E;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct HkFlags_c6b
{
    int m_iFlags;
    HkFlags_c6b(int i) : m_iFlags(i)
    {}
};

struct S_00c85c10_pair
{
    int unk00;
    int unk04;
};

struct S_00c85c10_flag
{
    int unk00;
    S_00c85c10_flag() : unk00(0)
    {}
};

struct S_00c85c10_entry
{
    int* value;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_00c85c10_data
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
    S_00c85c10_entry* entries;
    int count;

    void FUN_00cd2a50(int* result, int* value);
    void AddEntry(int* value, int* result, S_00c85c10_flag flag);
};

struct S_00c85c10
{
    void* unk00;
    void* unk04;
    S_00c85c10_data* unk08;

    void FUN_00c85c10(int* result, int* value);
};

// @f3 0x008f9c30 (community match, verified in this file)
extern int DAT_0108edc0;

struct FUN_008e96a0_Obj
{
    int unk00;
    bool FUN_008e96a0(int* value);
};
struct FUN_009317a0_Obj
{
    int unk00;
    void FUN_009317a0(int* result, int* value);
};
struct FUN_00931740_Obj
{
    int unk00;
    void hkpWorldObject_addProperty(int* value, int* result, S_00c85c10_flag flag);
};

// pdb: bhkWorldObject::SetAVObject | bhkWorldObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, aiKey
void S_00c85c10::FUN_00c85c10(int* result, int* value)
{
    S_00c85c10_pair local;

    if (value == 0)
    {
        value = &DAT_0108edc0;
    }

    if (reinterpret_cast<FUN_008e96a0_Obj*>(this)->FUN_008e96a0(value))
    {
        if (this != 0 && unk08 != 0)
        {
            reinterpret_cast<FUN_009317a0_Obj*>(unk08)->FUN_009317a0(&local.unk00, value);
        }
    }

    if (result != 0)
    {
        S_00c85c10_flag flag;
        if (this != 0 && unk08 != 0)
        {
            reinterpret_cast<FUN_00931740_Obj*>(unk08)->hkpWorldObject_addProperty(value, result, flag);
        }
    }
}


struct ActionC68bf0
{
    bool FUN_00c68bf0(void* owner);
};
struct LinkedObjectC9d590
{
    ActionC68bf0* GetAction() const
    {
        return *reinterpret_cast<ActionC68bf0* const*>(reinterpret_cast<const char*>(this) + 0x350);
    }
};

struct ActionOwnerC9d590
{
    virtual void slot0(), slot1(), slot2(), slot3(), slot4(), slot5(), slot6(), slot7();
    virtual void slot8(), slot9(), slot10(), slot11(), slot12(), slot13(), slot14(), slot15();
    virtual void slot16(), slot17(), slot18(), slot19(), slot20(), slot21(), slot22(), slot23();
    virtual void slot24(), slot25(), slot26(), slot27(), slot28(), slot29(), slot30(), slot31();
    virtual void slot32(), slot33(), slot34(), slot35(), slot36();
    virtual LinkedObjectC9d590* ResolveLinkedObject();
    int unk4;
    void* handle;
    bool FUN_00c9d590();
};

// @f3 0x008f8280 (community match, verified in this file)
namespace Task1423 {

struct Collider { bool FUN_008d8f60(void*); };

struct Body {

    unsigned int unk00;

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

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;

    unsigned int unk44;

    unsigned int unk48;

    unsigned int unk4c;

    unsigned int unk50;

    unsigned int unk54;

    unsigned int unk58;

    unsigned int unk5c;

    unsigned int unk60;

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

    unsigned int unkac;

    unsigned int unkb0;

    unsigned int unkb4;

    unsigned int unkb8;

    unsigned int unkbc;

    unsigned int unkc0;

    unsigned int unkc4;

    unsigned int unkc8;

    unsigned int unkcc;

    unsigned int unkd0;

    unsigned int unkd4;

    unsigned int unkd8;

    unsigned int unkdc;

    unsigned int unke0;

    unsigned int unke4;

    unsigned int unke8;

    unsigned int unkec;

    unsigned int unkf0;

    unsigned int unkf4;

    unsigned int unkf8;

    unsigned int unkfc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    unsigned int unk13c;

    unsigned int unk140;

    unsigned int unk144;

    unsigned int unk148;

    unsigned int unk14c;

    unsigned int unk150;

    unsigned int unk154;

    unsigned int unk158;

    unsigned int unk15c;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16c;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17c;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18c;

    unsigned int unk190;

    unsigned int unk194;

    unsigned int unk198;

    unsigned int unk19c;

    unsigned int unk1a0;

    unsigned int unk1a4;

    unsigned int unk1a8;

    unsigned int unk1ac;

    unsigned int unk1b0;

    unsigned int unk1b4;

    unsigned int unk1b8;

    unsigned int unk1bc;

    unsigned int unk1c0;

    unsigned int unk1c4;

    unsigned int unk1c8;

    unsigned int unk1cc;

    unsigned int unk1d0;

    unsigned int unk1d4;

    unsigned int unk1d8;

    unsigned int unk1dc;

    unsigned int unk1e0;

    unsigned int unk1e4;

    unsigned int unk1e8;

    unsigned int unk1ec;

    unsigned int unk1f0;

    unsigned int unk1f4;

    unsigned int unk1f8;

    unsigned int unk1fc;

    unsigned int unk200;

    unsigned int unk204;

    unsigned int unk208;

    unsigned int unk20c;

    unsigned int unk210;

    unsigned int unk214;

    unsigned int unk218;

    unsigned int unk21c;

    unsigned int unk220;

    unsigned int unk224;

    unsigned int unk228;

    unsigned int unk22c;

    unsigned int unk230;

    unsigned int unk234;

    unsigned int unk238;

    unsigned int unk23c;

    unsigned int unk240;

    unsigned int unk244;

    unsigned int unk248;

    unsigned int unk24c;

    unsigned int unk250;

    unsigned int unk254;

    unsigned int unk258;

    unsigned int unk25c;

    unsigned int unk260;

    unsigned int unk264;

    unsigned int unk268;

    unsigned int unk26c;

    unsigned int unk270;

    unsigned int unk274;

    unsigned int unk278;

    unsigned int unk27c;

    unsigned int unk280;

    unsigned int unk284;

    unsigned int unk288;

    unsigned int unk28c;

    unsigned int unk290;

    unsigned int unk294;

    unsigned int unk298;

    unsigned int unk29c;

    unsigned int unk2a0;

    unsigned int unk2a4;

    unsigned int unk2a8;

    unsigned int unk2ac;

    unsigned int unk2b0;

    unsigned int unk2b4;

    unsigned int unk2b8;

    unsigned int unk2bc;

    unsigned int unk2c0;

    unsigned int unk2c4;

    unsigned int unk2c8;

    unsigned int unk2cc;

    unsigned int unk2d0;

    unsigned int unk2d4;

    unsigned int unk2d8;

    unsigned int unk2dc;

    unsigned int unk2e0;

    unsigned int unk2e4;

    unsigned int unk2e8;

    unsigned int unk2ec;

    unsigned int unk2f0;

    unsigned int unk2f4;

    unsigned int unk2f8;

    unsigned int unk2fc;

    unsigned int unk300;

    unsigned int unk304;

    unsigned int unk308;

    unsigned int unk30c;

    Collider* collider310;
    Collider* GetAction() const {return *reinterpret_cast<Collider* const*>(reinterpret_cast<const char*>(this)+0x310);}

};

struct Query {

    virtual void Unknown00();

    virtual void Unknown04();

    virtual void Unknown08();

    virtual void Unknown0c();

    virtual void Unknown10();

    virtual void Unknown14();

    virtual void Unknown18();

    virtual void Unknown1c();

    virtual void Unknown20();

    virtual void Unknown24();

    virtual void Unknown28();

    virtual void Unknown2c();

    virtual void Unknown30();

    virtual void Unknown34();

    virtual void Unknown38();

    virtual void Unknown3c();

    virtual void Unknown40();

    virtual void Unknown44();

    virtual void Unknown48();

    virtual void Unknown4c();

    virtual void Unknown50();

    virtual void Unknown54();

    virtual void Unknown58();

    virtual void Unknown5c();

    virtual void Unknown60();

    virtual void Unknown64();

    virtual void Unknown68();

    virtual void Unknown6c();

    virtual void Unknown70();

    virtual void Unknown74();

    virtual void Unknown78();

    virtual void Unknown7c();

    virtual void Unknown80();

    virtual void Unknown84();

    virtual void Unknown88();

    virtual void Unknown8c();

    virtual void Unknown90();

    virtual void Unknown94();

    virtual Body* GetBody();

    unsigned int unk04;

    void* token08;

    bool FUN_008f8280();

};

bool Query::FUN_008f8280() {

    bool result=false;

    Body* body=GetBody();

    Collider* collider=body ? body->GetAction() : 0;

    if(collider) result=collider->FUN_008d8f60(token08);

    return result;

}

}

// pdb: bhkAction::Remove | bhkAction.obj | fnv360_0822_retail, vtable, medium
bool ActionOwnerC9d590::FUN_00c9d590(){return reinterpret_cast<Task1423::Query*>(this)->FUN_008f8280();}


struct ObjectCA06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ObjectCA06();
};
// @fnv 0x00ca06d0
ObjectCA06* __cdecl FUN_00ca06d0()
{
    return new ObjectCA06;
}

extern int DAT_012686d0;

struct FUN_00cd2de0 : FUN_00c84c50
{
    virtual ~FUN_00cd2de0();
    void FUN_00c876a0();
};
// @fnv 0x00cd2de0
// pdb: bhkShapeCollection::~bhkShapeCollection | bhkShapeCollection.obj | fnv360_0822_retail, call_seq, medium
FUN_00cd2de0::~FUN_00cd2de0()
{
    FUN_00c876a0();
    --DAT_012686d0;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct LoadStream
{
    int unk00;
    unsigned int version;
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
    unsigned char unk1e4;
    unsigned char endian;
    void Prepare();
};
struct LoadedData
{
    unsigned int flags;
    int unk04;
    int unk08;
    void* data;
    int count;
    int capacity;
};
struct ReleaseAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, unsigned int);
};
struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ReleaseAllocator* m_pStreamAllocator;
    ReleaseAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct LoadObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void* GetHavokClass();
    virtual void v43();
    virtual void v44();
    virtual LoadedData* GetHavokData(int* piSize);
    void LoadBase(LoadStream*);
    void FUN_00c85f20(LoadStream*);
};
void SwapHavokObjectEndian(LoadedData* pkData, void* pkClass, void** ppkArrayData);
// @f3 0x008f9cf0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

namespace f3m_008f9cf0 {
struct Heap_8f9cf0
{
    void FUN_008f6d90(void* p, unsigned int size, int tag);
};
struct Arr_8f9cf0
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline void clearAndDeallocate()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            Heap_8f9cf0* heap = (Heap_8f9cf0*)DAT_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(m_data, capacity * 8, 0x17);
        }
        m_data = 0;
        m_size = 0;
        m_capacityAndFlags = (m_capacityAndFlags & 0xc0000000) | 0x80000000;
    }
};
}

// pdb: bhkWorldObject::LoadBinary | bhkWorldObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void LoadObject::FUN_00c85f20(LoadStream* stream)
{
    stream->Prepare();
    LoadBase(stream);
    int iSize;
    LoadedData* data = GetHavokData(&iSize);
    if (stream->endian != 1) {
        void* cls = GetHavokClass();
        SwapHavokObjectEndian(data, cls, &data->data);
    }
    if (data)
        ((f3m_008f9cf0::Arr_8f9cf0*)&data->data)->clearAndDeallocate();
    if (stream->endian != 1)
        data->flags = _byteswap_ulong(data->flags);
    if (stream->version < 9 && (data->flags & 0x20))
        data->flags = (data->flags & ~0x20) | 0x8000;
    unsigned int kind = data->flags & 0x7f;
    if (kind == 8 || kind == 0x1d)
        data->flags &= ~0x4000;
}


struct ThreadState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int tag;
};
extern __declspec(thread) ThreadState tlsState;
struct TagScope
{
    unsigned int old;
    TagScope(unsigned int tag)
    {
        old = tlsState.tag;
        tlsState.tag = tag;
    }
    ~TagScope()
    {
        tlsState.tag = old;
    }
};

struct FreeAllocator : Allocator
{
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
};
struct RefLink
{
    unsigned int unk00, unk04;
    RefLink* ref;
};
struct Pair8
{
    int a, b;
};
template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(FreeAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void ClearAndRelease(Pool* pool)
    {
        _clearAndDeallocate(*static_cast<FreeAllocator*>(pool->allocator));
    }
};
struct Info
{
    unsigned int value;
    RefLink* link;
    unsigned int unk08;
    hkArr<Pair8> arr;
};
struct Stream86060
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void WriteRef(void*);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned char mode;
};
struct Obj86060
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void Release(void*);
    virtual int Kind();
    virtual void vac();
    virtual void vb0();
    virtual Info* GetInfo(void**);
    void bhkSerializable_SaveBinary(Stream86060&);
    void FUN_00c86060(Stream86060&);
};
// @f3 0x008f9de0 (community match, verified in this file)
struct FreeAllocStubF5
{
    void FUN_008f6d90(void* p, unsigned int size, int tag);
};

extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_009793e0(Info*, int, hkArr<Pair8>*);

struct Serializer8f8060
{
    void FUN_008f8060(Stream86060& stream);
};

inline RefLink* LinkedRef(Info* info)
{
    if (!info)
        return 0;
    RefLink* link = info->link;
    if (!link)
        return 0;
    return link->ref;
}

inline void DeallocPairs(hkArr<Pair8>* arr, int n)
{
    FreeAllocStubF5* alloc = (FreeAllocStubF5*)DAT_00d9b080(DAT_010f3170);
    alloc->FUN_008f6d90(arr->m_data, n * sizeof(Pair8), 0x17);
}

__forceinline void ClearAndFree(hkArr<Pair8>* arr)
{
    if ((arr->m_iCapacityState & 0x80000000) == 0)
        DeallocPairs(arr, arr->getCapacity());
    arr->m_data = 0;
    arr->m_iElementCount = 0;
    arr->m_iCapacityState = (arr->m_iCapacityState & 0xc0000000) | 0x80000000;
}

// pdb: bhkWorldObject::SaveBinary | bhkWorldObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Obj86060::FUN_00c86060(Stream86060& stream)
{
    void* handle;
    Info* info = GetInfo(&handle);
    if (stream.mode != 1)
    {
        int kind = Kind();
        FUN_009793e0(info, kind, &info->arr);
        info->value = _byteswap_ulong(info->value);
    }
    ClearAndFree(&info->arr);
    RefLink* ref = (info && info->link) ? info->link->ref : 0;
    stream.WriteRef(ref);
    ((Serializer8f8060*)this)->FUN_008f8060(stream);
    Release(handle);
}


extern int DAT_01268244;

struct Arg
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1e4;
    unsigned char m1e5;
};

struct Rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    volatile unsigned int m20;
    volatile unsigned int m24;
    volatile unsigned int m28;
    volatile unsigned int m2c;
    volatile unsigned int m30;
    volatile unsigned int m34;
    volatile unsigned int m38;
    volatile unsigned int m3c;
};

struct FUN_00c9f700_cls
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual Rec* GetRec(Arg** pp);
    void FUN_00c85f20(Arg* a);
    void FUN_00c9f700(Arg* volatile a);
};

// @f3 0x0090e130 (community match, verified in this file)
struct FUN_00c9f700_stand
{
    void FUN_008f9cf0(Arg* a);
};
// pdb: bhkAabbPhantom::LoadBinary | bhkAabbPhantom.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: bhkAabbPhantom::SaveBinary)
// pdb params: arStream
void FUN_00c9f700_cls::FUN_00c9f700(Arg* volatile a)
{
    Arg* p = a;
    ((FUN_00c9f700_stand*)this)->FUN_008f9cf0(p);
    Rec* r = GetRec((Arg**)&a);
    if (r == 0)
    {
        return;
    }
    if (p->m1e5 != 1)
    {
        r->m30 = _byteswap_ulong(r->m30);
        r->m34 = _byteswap_ulong(r->m34);
        r->m38 = _byteswap_ulong(r->m38);
        r->m3c = _byteswap_ulong(r->m3c);
        r->m20 = _byteswap_ulong(r->m20);
        r->m24 = _byteswap_ulong(r->m24);
        r->m28 = _byteswap_ulong(r->m28);
        r->m2c = _byteswap_ulong(r->m2c);
    }
}


// Save: on big-endian streams, byte-swap the Havok object's two vectors in place around the base save.

struct C9F770Vector
{
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long w;
};

inline void C9F770Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}

inline void C9F770SwapVector(C9F770Vector& kVector)
{
    C9F770Swap(kVector.x);
    C9F770Swap(kVector.y);
    C9F770Swap(kVector.z);
    C9F770Swap(kVector.w);
}

struct C9F770HavokData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C9F770Vector m_kPivotA;
    C9F770Vector m_kPivotB;
};

class C9F770Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
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
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char m_ucEndian;
};

class C9F770Constraint
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual C9F770HavokData* GetHavokData(bool* pbOwned);

    void SaveBaseBinary(C9F770Stream& kStream);
    void FUN_00c9f770(C9F770Stream& kStream);
};

// @f3 0x0090e1b0 (community match, verified in this file)
// pdb: bhkAabbPhantom::SaveBinary | bhkAabbPhantom.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void C9F770Constraint::FUN_00c9f770(C9F770Stream& kStream)
{
    bool bIsValid;
    C9F770HavokData* pkData = GetHavokData(&bIsValid);
    if (pkData && kStream.m_ucEndian != 1)
    {
        C9F770SwapVector(pkData->m_kPivotB);
        C9F770SwapVector(pkData->m_kPivotA);
    }
    SaveBaseBinary(kStream);
    if (pkData && kStream.m_ucEndian != 1)
    {
        C9F770SwapVector(pkData->m_kPivotB);
        C9F770SwapVector(pkData->m_kPivotA);
    }
}


struct Arg_00c9fbc0
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    unsigned char unk1e4;
    unsigned char unk1e5;
};

struct Rec_00c9fbc0
{
    int unk0;
    unsigned int unk4;
};

struct Cls_00c9fbc0
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual Rec_00c9fbc0* GetRec(Arg_00c9fbc0*& a);
    void FUN_00c84d00(Arg_00c9fbc0* a);
    void FUN_00c9fbc0(Arg_00c9fbc0* a1);
};

// @f3 0x0090c4f0 (community match, verified in this file)
struct Cls_00c9fbc0F3
{
    void FUN_008f7490(Arg_00c9fbc0* a);
};
// pdb: bhkConvexShape::LoadBinary | bhkConvexShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Cls_00c9fbc0::FUN_00c9fbc0(Arg_00c9fbc0* a1)
{
    Arg_00c9fbc0* volatile* pa = &a1;
    Arg_00c9fbc0* a = *pa;
    ((Cls_00c9fbc0F3*)this)->FUN_008f7490(a);
    if (a->unk1e5 != 1)
    {
        Rec_00c9fbc0* r = GetRec(a1);
        if (r)
        {
            unsigned int* p = &r->unk4;
            *p = _byteswap_ulong(*p);
        }
    }
}


struct C9FC00Stream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
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
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char m_ucEndian;
};

struct C9FC00Data
{
    int unk00;
    unsigned long m_ulValue;
};

class C9FC00Object
{
  public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual C9FC00Data* GetData(bool* pbValid);

    void SaveBinaryBase(C9FC00Stream& kStream);
    void FUN_00c9fc00(C9FC00Stream& kStream);
};

// @fnv 0x00c9fc00
void C9FC00Object::FUN_00c9fc00(C9FC00Stream& kStream)
{
    bool bValid;
    C9FC00Data* pkData = GetData(&bValid);
    if (kStream.m_ucEndian != 1)
        pkData->m_ulValue = _byteswap_ulong(pkData->m_ulValue);
    SaveBinaryBase(kStream);
    if (kStream.m_ucEndian != 1)
        pkData->m_ulValue = _byteswap_ulong(pkData->m_ulValue);
}

struct FUN_00c9ff00_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00c9ff00_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(void* pp);
    void FUN_00c9fbc0(FUN_00c9ff00_arg* a);
    void FUN_00c9ff00(FUN_00c9ff00_arg* a1);
};

// @f3 0x009142c0 (community match, verified in this file)
// pdb: bhkBoxShape::LoadBinary | bhkBoxShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_00c9ff00_cls::FUN_00c9ff00(FUN_00c9ff00_arg* volatile a1)
{
    FUN_00c9ff00_arg* obj = a1;
    FUN_00c9fbc0(obj);
    if (obj->m_1e5 != 1)
    {
        volatile unsigned int* p = vGet((void*)&a1);
        if (p)
        {
            p[4] = _byteswap_ulong(p[4]);
            p[5] = _byteswap_ulong(p[5]);
            p[6] = _byteswap_ulong(p[6]);
            p[7] = _byteswap_ulong(p[7]);
        }
    }
}


struct FUN_00c9ff50_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
};

struct FUN_00c9ff50_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void FUN_00c9fc00(FUN_00c9ff50_arg* a);
    void FUN_00c9ff50(FUN_00c9ff50_arg* a1);
};

// @f3 0x00914320 (community match, verified in this file)
// pdb: bhkBoxShape::SaveBinary | bhkBoxShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_00c9ff50_cls::FUN_00c9ff50(FUN_00c9ff50_arg* a1)
{
    unsigned int tmp;
    if (a1->unk1E4 != 1)
    {
        volatile unsigned int* p = vGet((unsigned char*)&tmp);
        if (p)
        {
            p[4] = _byteswap_ulong(p[4]);
            p[5] = _byteswap_ulong(p[5]);
            p[6] = _byteswap_ulong(p[6]);
            p[7] = _byteswap_ulong(p[7]);
        }
    }
    FUN_00c9fc00(a1);
    if (a1->unk1E4 != 1)
    {
        volatile unsigned int* p = vGet((unsigned char*)&tmp);
        if (p)
        {
            p[4] = _byteswap_ulong(p[4]);
            p[5] = _byteswap_ulong(p[5]);
            p[6] = _byteswap_ulong(p[6]);
            p[7] = _byteswap_ulong(p[7]);
        }
    }
}


struct FUN_0094dbb0
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_0094dbb0();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

extern int DAT_012682cc;

struct FUN_00ca4da0 : FUN_00c84c50
{
    virtual ~FUN_00ca4da0();
    void FUN_00c876a0();
};

// @fnv 0x00ca4da0
// pdb: bhkBvTreeShape::~bhkBvTreeShape | bhkBvTreeShape.obj | fnv360_0822_retail, call_seq, high
FUN_00ca4da0::~FUN_00ca4da0()
{
    FUN_00c876a0();
    DAT_012682cc--;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern int DAT_012681bc;
extern int DAT_012683c0;

struct NiStream;
struct CloningProcess;

struct NiRefObjectBase
{
    virtual ~NiRefObjectBase();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiObjectBase : NiRefObjectBase
{
    virtual const NiRTTI* GetRTTI();
    virtual void* IsNiNode();
    virtual void* IsFadeNode();
    virtual void* IsMultiBoundNode();
    virtual void* IsGeometry();
    virtual void* IsTriBasedGeometry();
    virtual void* IsTriStrips();
    virtual void* IsTriShape();
    virtual void* IsSegmentedTriShape();
    virtual void* IsResizableTriShape();
    virtual void* IsParticles();
    virtual void* IsLines();
    virtual void* IsLimitedHingeConstraint();
    virtual void* IsRigidBody();
    virtual void* IsCollisionObject();
    virtual NiObjectBase* MakeClone(CloningProcess* pkCloning);
    virtual void LoadBinary(NiStream* pkStream);
    virtual void LinkObject(NiStream* pkStream);
    virtual bool RegisterStreamables(NiStream* pkStream);
    virtual void SaveBinary(NiStream* pkStream);
    virtual bool IsEqual(NiObjectBase* pkObject);
    virtual void GetViewerStrings(void* pkStrings);
    virtual void AddViewerStrings(void* pkStrings);
    virtual void ProcessClone(CloningProcess* pkCloning);
    virtual void PostLinkObject(NiStream* pkStream);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual unsigned int GetBlockAllocationSize();
    virtual void* GetGroup();
    virtual void SetGroup(void* pkGroup);
    virtual void* IsNiControllerManager();
    virtual void PrepareForSave();
    virtual void Unknown33();
};

struct hkpShapeStandIn
{
    void* vfptr;
    int m_usMemSizeAndFlags;
    NiObjectBase* m_ulUserData;
};

struct hkpCollidableStandIn
{
    hkpShapeStandIn* m_pCollisionShape;
    const hkpShapeStandIn* getShape() const
    {
        return m_pCollisionShape;
    }
};

struct hkpWorldObjectStandIn : hkReferencedObject
{
    void FUN_00c90510();
    void* unk00;
    int m_usMemSizeAndFlags;
    void* m_pOwningWorld;
    void* m_ulUserData;
    hkpCollidableStandIn m_kCollidable;
};

struct bhkRefObjectBase : NiObjectBase
{
    virtual void SetHavokObject(hkpWorldObjectStandIn* pkObject);
    hkpWorldObjectStandIn* m_pkHavokObject;
    bhkRefObjectBase();
};

struct WorldObjectPair
{
    int unk00;
    int unk04;
    WorldObjectPair() : unk00(0), unk04(0)
    {}
};

struct bhkWorldObjectBase : bhkRefObjectBase
{
    virtual void SetHavokObject(hkpWorldObjectStandIn* pkObject);
    WorldObjectPair unk0C;
    bhkWorldObjectBase()
    {
        ++DAT_0126810c;
    }
    void FUN_00a29680();
    NiObjectBase* GetShape()
    {
        hkpWorldObjectStandIn* pkObject = m_pkHavokObject;
        if (pkObject)
        {
            FUN_00a29680();
            const hkpCollidableStandIn* pkCollidable = &pkObject->m_kCollidable;
            FUN_00a29680();
            if (pkCollidable)
            {
                const hkpShapeStandIn* pkShape = pkCollidable->getShape();
                if (pkShape)
                    return pkShape->m_ulUserData;
            }
        }
        return 0;
    }
};

struct bhkEntityBase : bhkWorldObjectBase
{
    bhkEntityBase()
    {
        ++DAT_012681fc;
    }
};

struct bhkRigidBodyBase : bhkEntityBase
{
    int unk14;
    int unk18;
    bhkRigidBodyBase()
    {
        unk14 = 0;
        unk18 = 0;
        ++DAT_012681bc;
    }
    ~bhkRigidBodyBase();
};

struct FUN_00cb38c0 : bhkRigidBodyBase
{
    FUN_00cb38c0(bhkRigidBodyBase* pkSource);
    virtual ~FUN_00cb38c0();
};

// @f3 0x009260d0 (community match, verified in this file)
extern int DAT_010f33b0;
struct RefAt9316e0 { void FUN_009316e0(); };
// pdb: bhkRigidBodyT::bhkRigidBodyT | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: apBody
FUN_00cb38c0::FUN_00cb38c0(bhkRigidBodyBase* source)
{
    ++DAT_010f33b0;
    hkpWorldObjectStandIn* object=source->m_pkHavokObject;
    reinterpret_cast<RefAt9316e0*>(object)->FUN_009316e0();
    hkpWorldObjectStandIn* shapeObject=source->m_pkHavokObject;
    hkpCollidableStandIn* collidable=shapeObject ? &shapeObject->m_kCollidable : 0;
    hkpShapeStandIn* shape=collidable ? collidable->m_pCollisionShape : 0;
    NiObjectBase* shapeWrapper=shape ? shape->m_ulUserData : 0;
    if(shapeWrapper) shapeWrapper->IncRefCount();
    source->SetHavokObject(0);
    bhkWorldObjectBase::SetHavokObject(object);
    shapeWrapper->DecRefCount();
    object->removeReference();
}


struct FUN_00cbe9f0_Target;
struct S00cbe9f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00cbe9f0_Target* m18;
    unsigned char m1c;

    void FUN_00c9f050(const void* a);
    void FUN_00c85c10(int a, int b);
    void FUN_00cbe9f0(int a1, FUN_00cbe9f0_Target* a2);
};

// @f3 0x00931ca0 (community match, verified in this file)
namespace task1476 {
struct Owner { int FUN_008f9c90(int); };
struct Helpers { void FUN_0090e600(const void*); void FUN_008f9c30(int,int); };
}
// pdb: bhkCollisionBox::Init | bhkCollisionBox.obj | fnv360_0721_beta, objrun, medium
// pdb params: arInfo, apCharController
void S00cbe9f0_cls::FUN_00cbe9f0(int a1, FUN_00cbe9f0_Target* a2) {
 m1c=0;
 ((task1476::Helpers*)this)->FUN_0090e600((const void*)a1);
 m18=a2;
 if(a2) {
  task1476::Owner* owner=*(task1476::Owner**)((char*)a2+0x424);
  ((task1476::Helpers*)this)->FUN_008f9c30(owner ? owner->FUN_008f9c90(0) : 0,0);
 }
}


extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
struct FUN_00c9d4f0_obj
{
    unsigned char unk00[0x1e5];
    unsigned char m_1e5;
};

struct FUN_00c9d4f0_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual unsigned char* vGet(unsigned char* pp);
    void FUN_00c85f20(FUN_00c9d4f0_obj* p);
    void FUN_00c9d4f0(FUN_00c9d4f0_obj* p);
};

// @f3 0x0090acd0 (community match, verified in this file)
// pdb: bhkEntity::LoadBinary | bhkEntity.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream
void FUN_00c9d4f0_cls::FUN_00c9d4f0(FUN_00c9d4f0_obj* p)
{
    FUN_00c85f20(p);
    if (p->m_1e5 != 1)
    {
        unsigned char flag;
        unsigned char* b = vGet(&flag);
        if (b)
            *(unsigned short*)(b + 0x1a) = _byteswap_ushort(*(unsigned short*)(b + 0x1a));
    }
}


struct FUN_00c9d530_arg
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char m1E4;
};
struct FUN_00c9d530_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual unsigned char* GetRef(unsigned char* flag);
    void FUN_00c86060(FUN_00c9d530_arg* a);
    void FUN_00c9d530(FUN_00c9d530_arg* a1);
};

// @f3 0x0090ad10 (community match, verified in this file)
// pdb: bhkEntity::SaveBinary | bhkEntity.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_00c9d530_cls::FUN_00c9d530(FUN_00c9d530_arg* a1)
{
    FUN_00c9d530_arg* a = *(FUN_00c9d530_arg* volatile*)&a1;
    if (a->m1E4 != 1)
    {
        unsigned char* r = GetRef((unsigned char*)&a1);
        if (r != 0)
        {
            unsigned short* p = (unsigned short*)(r + 0x1a);
            *p = _byteswap_ushort(*p);
        }
    }
    FUN_00c86060(a);
    if (a->m1E4 != 1)
    {
        unsigned char* r = GetRef((unsigned char*)&a1);
        if (r != 0)
        {
            unsigned short* p = (unsigned short*)(r + 0x1a);
            *p = _byteswap_ushort(*p);
        }
    }
}


#include <stdio.h>
extern __declspec(thread) int allocationContext;
struct AllocationScope
{
    int old;
    AllocationScope() : old(allocationContext)
    {
        allocationContext = 16;
    }
    ~AllocationScope()
    {
        allocationContext = old;
    }
};
struct StringArray
{
    void* vfptr;
    char** data;
    unsigned short capacity, size, used, growth;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growth);
        SetAt(index, value);
    }
};
char* __cdecl FUN_00a7d330(const char*);
struct Body
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
    void* island;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char motionType;
    bool* FUN_00c9bff0(bool*);
};
struct Object
{
    void* vfptr;
    int unk04;
    Body* body;
    void FUN_00c86190(StringArray*);
    bool IsActive()
    {
        bool active;
        if (!this || !body)
            return false;
        return *body->FUN_00c9bff0(&active) != 0;
    }
    bool IsFixed()
    {
        if (!this || !body)
            return false;
        return body->motionType == 5;
    }
    void* GetIsland()
    {
        return this && body ? body->island : 0;
    }
    void FUN_00c9d6b0(StringArray* strings);
};
// @f3 0x0090adf0 (community match, verified in this file)
extern char DAT_00e220d8, DAT_00e3480c, DAT_00e33af0, DAT_00e35980;
extern int DAT_010f3244;
extern "C" void __stdcall FUN_008f9fc0(StringArray*);
extern "C" char* __cdecl FUN_00847b50(int);
extern "C" char* __cdecl FUN_00847b90(const char*,unsigned char);
extern "C" char* __cdecl FUN_00847e70(const char*,const char*);
extern "C" int __cdecl FUN_00403230(char*,unsigned int,const char*,...);
struct BodyIsActiveProxy { bool* FUN_0090b0e0(bool*); };
// pdb: bhkEntity::GetViewerStrings | bhkEntity.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Object::FUN_00c9d6b0(StringArray* strings)
{
  FUN_008f9fc0(strings);
  char* str = FUN_00847b50(DAT_010f3244);
  strings->Add(str);
  unsigned char flag;
  str = FUN_00847b90(&DAT_00e220d8,
      ((this && body) ? (unsigned char)(*((BodyIsActiveProxy*)body)->FUN_0090b0e0((bool*)&flag) != 0) : (unsigned char)0));
  strings->Add(str);
  str = FUN_00847b90(&DAT_00e3480c,
      ((this && body) ? (unsigned char)(*((unsigned char*)body + 0xd8) == 7) : (unsigned char)0));
  strings->Add(str);
  void* island = (this && body) ? *(void**)((char*)body+0xb8) : 0;
  char buffer[64];
  FUN_00403230(buffer,64,&DAT_00e33af0,island);
  str = FUN_00847e70(&DAT_00e35980,buffer);
  strings->Add(str);
}


struct S_00ca09e0_Inner
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
};
struct S_00ca09e0_Shape
{
    void AssignFixedString(char** s);
};
struct S_00ca09e0_Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(S_00ca09e0_Shape* s, int f);
};
char* __cdecl FUN_00a5b690(const char* s);
extern char* _EmptyFS;
struct S_00ca09e0_Str
{
    char* p;
    S_00ca09e0_Str(const char* s)
    {
        p = FUN_00a5b690(s);
    }
    ~S_00ca09e0_Str()
    {
        if (p != _EmptyFS)
            InterlockedDecrement((long*)(p - 8));
    }
};
struct S_00ca09e0_Obj
{
    int unk0;
    int unk4;
    S_00ca09e0_Inner* unk8;
    void __thiscall bhkSphereShape_BuildDisplayGeometry(S_00ca09e0_Target* a);
};
// @f3 0x0090ebc0 (community match, verified in this file)
extern float DAT_00f7a690;
extern double DAT_00db88e8;
extern char* DAT_00e207a8;
char* __cdecl FUN_008242a0(const char*);
S_00ca09e0_Shape* __cdecl BSTestObjects_CreateSphere(float, int, int, int);

namespace f3_sphere_display {
struct ShapeName {
    char* value;
    explicit ShapeName(const char* text) : value(FUN_008242a0(text)) {}
    ~ShapeName() {
        if (value != DAT_00e207a8)
            InterlockedDecrement(reinterpret_cast<volatile long*>(value - 8));
    }
};

struct SphereSource {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3c();
    virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4c();
    virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5c();
    virtual void slot60(); virtual void slot64(); virtual void slot68(); virtual void slot6c();
    virtual void slot70(); virtual void slot74(); virtual void slot78(); virtual void slot7c();
    virtual void slot80(); virtual void slot84(); virtual void slot88(); virtual void slot8c();
    virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9c();
    virtual void slota0(); virtual void slota4(); virtual void slota8(); virtual void slotac();
    virtual void slotb0(); virtual void slotb4(); virtual void slotb8(); virtual void slotbc();
    virtual void slotc0(); virtual void slotc4(); virtual void slotc8(); virtual void slotcc();
    virtual void slotd0(); virtual void slotd4();
    virtual void ApplyGeometry(S_00ca09e0_Shape*);
};
}

// pdb: bhkSphereShape::BuildDisplayGeometry | bhkSphereShape.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|vtable), high
void S_00ca09e0_Obj::bhkSphereShape_BuildDisplayGeometry(S_00ca09e0_Target* target)
{
    using namespace f3_sphere_display;
    float radius;
    if (this == 0 || unk8 == 0)
        radius = DAT_00f7a690;
    else
        radius = unk8->unk10;
    const float scaledRadius = static_cast<float>(radius * DAT_00db88e8);
    S_00ca09e0_Shape* geometry = BSTestObjects_CreateSphere(scaledRadius, 10, 10, 0);
    if (!geometry)
        return;

    reinterpret_cast<SphereSource*>(this)->ApplyGeometry(geometry);
    {
        ShapeName name("bhkSphereShape");
        geometry->AssignFixedString(&name.value);
    }
    target->v55(geometry, 1);
}


extern __declspec(thread) int DAT_012722b4;

struct S00ca0900_Guard
{
    int previous;
    S00ca0900_Guard()
    {
        previous = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00ca0900_Guard()
    {
        DAT_012722b4 = previous;
    }
};

struct S00ca0900_Arg
{
    int unk00;
    float unk04;
};

struct S00ca0900_Shape
{
    unsigned int unk00;
    unsigned short m_usMemSizeAndFlags;
    static void* operator new(unsigned int size)
    {
        Pool* pool = FUN_00c85750();
        S00ca0900_Shape* p = (S00ca0900_Shape*)pool->allocator->Allocate(0x20);
        p->m_usMemSizeAndFlags = 0x20;
        return p;
    }
    static void operator delete(void*);
    S00ca0900_Shape(float radius);
};

extern "C" void __fastcall FUN_00c905b0(FUN_00cf2cb0*);

struct S00ca0900_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void SetShape(S00ca0900_Shape* shape);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void Finish(S00ca0900_Arg* arg);
    void FUN_00ca0900(S00ca0900_Arg* arg);
};

// @f3 0x0090eca0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct S00ca0900_Pool
{
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};
struct FUN_00970f60
{
    unsigned int unk00;
    unsigned short m_usMemSizeAndFlags;
    static void* operator new(unsigned int size)
    {
        S00ca0900_Pool* pool = (S00ca0900_Pool*)DAT_00d9b080(DAT_010f3170);
        FUN_00970f60* p = (FUN_00970f60*)pool->FUN_008f6d30(0x20, 0x27);
        p->m_usMemSizeAndFlags = 0x20;
        return p;
    }
    FUN_00970f60(float radius);
};
struct S00ca0900_Raw
{
    void** vtbl;
    unsigned short flags;
    short refs;
};
typedef void (__thiscall* S00ca0900_Del)(void* self, unsigned int flags);
// pdb: bhkSphereShape::Init | bhkSphereShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void S00ca0900_cls::FUN_00ca0900(S00ca0900_Arg* arg)
{
    if (arg)
    {
        S00ca0900_Shape* shape = (S00ca0900_Shape*)new FUN_00970f60(arg->unk04);
        SetShape(shape);
        S00ca0900_Raw* raw = (S00ca0900_Raw*)shape;
        if (raw->flags != 0)
        {
            if (--raw->refs == 0)
                ((S00ca0900_Del)raw->vtbl[0])(raw, 1);
        }
        Finish(arg);
    }
}


namespace fnv_00cb3b20 {
extern __declspec(thread) unsigned int tlsMode;
extern void* DAT_012683c8;
void* FUN_00a7d330(void*);
struct OutputList
{
    void* field_00;
    void* field_04;
    unsigned short capacity_08, count_0a, field_0c, growth_0e;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, void**);
    void append(void* value)
    {
        unsigned int index = count_0a;
        if (index >= capacity_08)
            FUN_0096ad30(index + growth_0e);
        FUN_0096ae90(index, &value);
    }
};
struct ModeScope
{
    unsigned int saved;
    ModeScope() : saved(tlsMode)
    {
        tlsMode = 16;
    }
    ~ModeScope()
    {
        tlsMode = saved;
    }
};
struct Target
{
    enum
    {
        RotationOffset = 0x20,
        PositionOffset = 0x30
    };
    void FUN_00c8f870(OutputList*);
    void FUN_00cb3b20(OutputList*);
};
}  // namespace fnv_00cb3b20

struct B00c9fde0
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    B00c9fde0();
};
// @fnv 0x00c9fe30
// pdb: bhkSphereShape::CreateClone | bhkSphereShape.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: bhkSphereShape::CreateObject)
// pdb params: arCloneData
B00c9fde0* __cdecl FUN_00c9fe30()
{
    return new B00c9fde0;
}

struct S00cb39d0_S_00aa3e40
{
    void* __thiscall FUN_00aa3e40(int size);
};

struct S00cb39d0_S_00cb3860
{
    S00cb39d0_S_00cb3860();
};

void* __cdecl operator new(unsigned int size, S00cb39d0_S_00aa3e40& manager, unsigned int allocationSize)
{
    unsigned char* ptr = static_cast<unsigned char*>(manager.FUN_00aa3e40(allocationSize));
    unsigned int address = reinterpret_cast<unsigned int>(ptr);
    unsigned char alignment = static_cast<unsigned char>(0x10 - (address & 0x0f));
    ptr += alignment;
    ptr[-1] = alignment;
    return ptr;
}

void __cdecl operator delete(void* ptr, S00cb39d0_S_00aa3e40& manager, unsigned int allocationSize)
{}

// @fnv 0x00cb39d0
// pdb: bhkRigidBodyT::CreateObject | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium, conflict (skyrim: bhkRigidBodyT::GetTransform)
void __cdecl FUN_00cb39d0(void* arg0, void* arg1, void* arg2, void* arg3)
{
    new (*(S00cb39d0_S_00aa3e40*)&DAT_011f6238, 0x50) S00cb39d0_S_00cb3860();
}

struct ShapeViewerFields
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int collisionFlags;

    unsigned int Layer() const
    {
        return collisionFlags & 0x1f;
    }
    void FUN_00c851c0(BCA05B0StringArray* output);
};
