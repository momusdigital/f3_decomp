#include <math.h>
#include <windows.h>
#include "f3_common.h"
// src/fallout/ai/actor_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/actor.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "Actor.h"

struct MemoryManager
{
    void* Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct bhkRagdollController
{
    void FUN_00c7d900();
    void* FUN_00c7de30(unsigned int);
};
// @fnv 0x00c7de30
// pdb: ProjectileListener::`scalar deleting destructor' | ProjectileListener.obj | fnv360_0822_retail, vtable_prefix, medium
void* bhkRagdollController::FUN_00c7de30(unsigned int flag)
{
    FUN_00c7d900();
    if ((flag & 1) && this)
    {
        g_memoryManager.Deallocate((char*)this - *(unsigned char*)((char*)this - 1));
    }
    return this;
}

extern "C" void* g_012685f8;

// @fnv 0x00c7fa60
// pdb: NiBSplineInterpolator::GetRTTI | NiBSplineInterpolator.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(objrun), high
void* __cdecl NiBSplineInterpolator_GetRTTI()
{
    return &g_012685f8;
}

extern "C" void __cdecl _delete(void*, int);
void __cdecl FUN_00cc58c0();

struct FUN_00c7fa70_Class
{
    void* __thiscall FUN_00c7fa70(int);
};

// @fnv 0x00c7fa70
// pdb: bhkUnaryAction::`scalar deleting destructor' | GlobalFunc.obj | fnv360_0822_retail, vtable_prefix, high
void* __thiscall FUN_00c7fa70_Class::FUN_00c7fa70(int flags)
{
    FUN_00cc58c0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern "C" void __cdecl FUN_0062d4b0();
extern int DAT_01084e54;

struct FUN_00cb9900_cls
{
    void __thiscall FUN_00cb9900();
};

// @fnv 0x00cb9900
void __thiscall FUN_00cb9900_cls::FUN_00cb9900()
{
    *(int*)this = (int)&DAT_01084e54;
    FUN_0062d4b0();
}

void __cdecl FUN_00cda340();
void __cdecl FUN_00cd9fe0();

struct FUN_00cda4b0_cls
{
    void __thiscall FUN_00cda4b0();
};

// @fnv 0x00cda4b0
// pdb: BSShaderBloodSplatter::ReloadShaders | BSShaderBloodSplatter.obj | fnv360_0822_debug, caller_sim, low
void __thiscall FUN_00cda4b0_cls::FUN_00cda4b0()
{
    FUN_00cda340();
    ((void(__thiscall*)(void*))FUN_00cd9fe0)(this);
}

struct FUN_00cda8d0_class
{
    void FUN_00cda340();
    void* FUN_00cda8d0();
};

// @fnv 0x00cda8d0
// pdb: hkaPose::getSyncedPoseModelSpace | hkaPose.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkaPose::getSyncedPoseLocalSpace)
void* FUN_00cda8d0_class::FUN_00cda8d0()
{
    FUN_00cda340();
    return (char*)this + 0x10;
}

struct FUN_00cdb290
{
    void __thiscall FUN_00cda690();
    void* __thiscall GetPlus4();
};
// @fnv 0x00cdb290
// pdb: hkaPose::getSyncedPoseModelSpace | hkaPose.obj | tesv_win, objrun_open, low
void* __thiscall FUN_00cdb290::GetPlus4()
{
    FUN_00cda690();
    return (char*)this + 4;
}

struct VObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, unsigned int);
};
struct Holder
{
    char pad[16];
    VObj* p;
};
Holder* _FUN_00c85750();
struct Outer
{
    int _0;
    unsigned short _4;
    void __thiscall FUN_00c7dc40();
    Outer* __thiscall FUN_00c7e970(unsigned int);
};
// @fnv 0x00c7e970
Outer* __thiscall Outer::FUN_00c7e970(unsigned int a)
{
    FUN_00c7dc40();
    if (a & 1)
    {
        Holder* h = _FUN_00c85750();
        h->p->f2(this, _4);
    }
    return this;
}

struct MyNode
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int Pred();
    char _pad0[0x18];
    MyNode* field_1c;
    char _pad1[0x80];
    MyNode** children;
    char _pad2[2];
    unsigned short count;
};
// @fnv 0x00c802d0
// pdb: bhkUtilFunctions::FindNextCollisionObject | bhkUtilFunctions.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apObj
MyNode* __cdecl FUN_00c802d0(MyNode* p)
{
    MyNode* r = p->field_1c;
    if (!r && p->Pred())
    {
        for (unsigned i = 0; i < p->count; ++i)
        {
            if (r)
                break;
            MyNode* child = p->children[i];
            if (child)
                r = FUN_00c802d0(child);
        }
    }
    return r;
}

struct MyRef
{
    virtual ~MyRef();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct Target;

struct Target18
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
    virtual void v55();
    virtual void v56();
    virtual void MethodE4(Target* p, NiPointer<MyRef>& sp);
};

struct Target
{
    char pad[0x18];
    Target18* field_18;
};

struct FUN_00c6ffc0_Class
{
    Target* FUN_00c6e0b0();
    void FUN_00c6ffc0();
};

// @f3 0x008ecaa0 (community match, verified in this file)
// pdb: bhkCharacterController::KillDisplayGeometry | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
void FUN_00c6ffc0_Class::FUN_00c6ffc0()
{
    Target* p = FUN_00c6e0b0();
    NiPointer<MyRef> sp;
    Target18* t;
    if (p && (t = p->field_18))
    {
        t->MethodE4(p, sp);
    }
    *(unsigned int*)((char*)this + 0x294) &= 0xffff7fff;
}


extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* EmptyFS;
struct FixedStr
{
    char* h;
    FixedStr(const FixedStr& o)
    {
        if (o.h != EmptyFS)
            InterlockedIncrement((long volatile*)(o.h - 8));
        h = o.h;
    }
    ~FixedStr()
    {
        if (h != EmptyFS)
            InterlockedDecrement((long volatile*)(h - 8));
    }
    bool Equals(const char*) const;
};
struct Mat3
{
    float m[9];
};
struct Pt3
{
    float x, y, z;
};
struct Xform
{
    Mat3 rot;
    Pt3 trans;
    float scale;
};
struct RNode;
struct RObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual RNode* GetAsNode();
    int _4;
    FixedStr name;
    char _c[0xc];
    RObj* parent;
    char _1c[0x18];
    Xform local;
};
struct RNode
{
    char _0[0xa0];
    RObj** children;
    unsigned short _a4;
    unsigned short count;
};
struct RKey
{
    FixedStr name;
    RObj* obj;
    RKey(const FixedStr& n) : name(n)
    {}
};
struct RElem
{
    RObj* obj;
    Xform x;
};
struct RArr
{
    int _0;
    RElem* data;
    int AppendSlot();
    void ConstructElementArray(RElem*, int);
};
struct RCtx;
RObj* __cdecl FUN_00c4b470(RCtx*, RKey*, int);

// @fnv 0x00c7bcb0
// pdb: bhkRagdollController::CopyPoseTo3DRec | bhkRagdollController.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|caller_sim), high
void __cdecl bhkRagdollController_CopyPoseTo3DRec(RCtx* ctx, RObj* obj, RArr* arr)
{
    RKey key(obj->name);
    key.obj = obj;
    if (key.name.Equals("Bip01 NonAccum"))
        key.obj = obj->parent;
    RObj* bone = FUN_00c4b470(ctx, &key, 1);
    if (bone)
    {
        RElem e;
        e.obj = bone;
        e.x = bone->local;
        int idx = arr->AppendSlot();
        arr->ConstructElementArray(&arr->data[idx], 1);
        const Xform& src = key.obj->local;
        arr->data[idx] = e;
        bone->local.rot = src.rot;
        bone->local.trans = src.trans;
    }
    RNode* node = obj->GetAsNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->count; i++)
        {
            RObj* child = node->children[i];
            if (child)
                bhkRagdollController_CopyPoseTo3DRec(ctx, child, arr);
        }
    }
}

struct NiUpdateData
{
    float m_fTime;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
};

struct NiNode : NiAVObject
{
    void Update(NiUpdateData const&);
};

struct Creature
{
    static void __cdecl SetNodeFlagsRecursive(NiAVObject*, int, bool, bool, bool);
};

void __cdecl SetFlagRecursive(int, void*);
void __cdecl bhkRagdollController_CopyPoseTo3DRec(void*, void*, void*);

inline unsigned char GetFlag6(unsigned short w)
{
    return (unsigned char)(w >> 6) & 1;
}

// @f3 0x008e7690 (community match, verified in this file)
// pdb: bhkRagdollController::CopyPoseTo3D | bhkRagdollController.obj | fnv360_0822_retail, callee_sim, low
// pdb params: apSkeleton, apPose, arPoseA, arbPrevUseVel, arePrevMotion
void __cdecl FUN_00c7d3b0(NiNode* param_1, void* param_2, void* param_3, char* param_4, unsigned int* param_5)
{
    MyNode* node = FUN_00c802d0((MyNode*)param_1);
    char flag;
    if (!node || !(*(unsigned short*)((char*)node + 0xc) & 0x20) || GetFlag6(*(unsigned short*)((char*)node + 0xc)))
    {
        flag = 0;
    }
    else
    {
        flag = 1;
    }
    *param_4 = flag;
    if (flag)
    {
        SetFlagRecursive(0, param_1);
    }
    {
        unsigned int val;
        char* n10 = *(char**)((char*)node + 0x10);
        if (n10 && *(char**)(n10 + 8))
        {
            val = *(unsigned char*)(*(char**)(n10 + 8) + 0xd8);
        }
        else
        {
            val = 7;
        }
        *param_5 = val;
    }
    if (*param_5 != 6)
    {
        Creature::SetNodeFlagsRecursive(param_1, 6, true, false, true);
    }
    if (param_1 && param_2)
    {
        bhkRagdollController_CopyPoseTo3DRec(param_1, param_2, param_3);
        NiUpdateData updateData;
        updateData.m_fTime = 0.0f;
        updateData.b0 = false;
        updateData.b1 = false;
        updateData.b2 = false;
        updateData.b3 = false;
        updateData.b4 = false;
        param_1->Update(updateData);
    }
}


struct ThreeByThreeMatrix
{
    float m[9];
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    float m_kTranslation[3];
    float m_fScale;
    NiTransform operator*(const NiTransform&) const;
};
void FUN_00c74dd0(void*, NiTransform*);

struct RagScrapMarker
{
    char* p;
    unsigned int size;
    RagScrapMarker(unsigned int count)
    {
        char** top = (char**)_FUN_00c85750();
        unsigned int size = (count * 48 + 0x7f) & ~0x7fu;
        char* old = *top;
        *top = old + size;
        p = old;
    }
    ~RagScrapMarker()
    {
        *(char**)_FUN_00c85750() = p;
    }
};

struct RagNode
{
    char pad0[0x18];
    RagNode* m_pParentNode;
    char pad1c[0x34 - 0x1c];
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
    RagNode* GetParent() const
    {
        return m_pParentNode;
    }
};
struct RagInner
{
    char pad[0x1c];
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
};
struct RagMid
{
    char pad[0x2c];
    RagInner* inner;
    RagInner* GetInner() const
    {
        return inner;
    }
};
struct FUN_00c7d630_t
{
    char pad0[0x48];
    RagMid* m_48;
    char pad4c[0x58 - 0x4c];
    RagNode* m_pkNode;
    char pad5c[4];
    ThreeByThreeMatrix m_kRot;
    void FUN_00c7d630(float);
    void FUN_00c79680();
    void FUN_00c7cb50(int);
    void FUN_00c76350(void*);
    void FUN_00c751f0(void*);
    void FUN_00c7aa60(void*);
    void FUN_00c7ba50(void*, void*, bool*);
    void FUN_00c7d030(void*);
    void FUN_00c7c870();
    void FUN_00c79a50();
};

// @f3 0x008e7b20 (community match, verified in this file)
namespace f3m_008e7b20 {
struct WorkArea { int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c; };
struct Node {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Node* m_pParentNode;
    int unk1c, unk20, unk24, unk28, unk2c, unk30;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
    Node* GetParent() const { return m_pParentNode; }
};
struct Inner {
    int unk00, unk04, unk08, unk0c;
    unsigned int count;
    unsigned int GetCount() const { return count; }
};
struct Mid {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Inner* inner;
    Inner* GetInner() const { return inner; }
};
// The per-thread stack allocator behind the TLS slot.
struct ThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* OnStackOverflow(unsigned int bytes);
    virtual void OnStackUnderflow(void* p);
    __forceinline char* Allocate(unsigned int bytes);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* current;
    int unk24;
    char* base;
    char* end;
};
// Scratch buffer of 48-byte entries taken from the thread stack allocator and returned on scope exit.
struct ScrapMarker {
    char* p;
    unsigned int size; // never read or written by this routine
    __forceinline ScrapMarker(unsigned int count);
    __forceinline ~ScrapMarker();
};
struct Controller {
    int unk000, unk004, unk008, unk00c;
    WorkArea m_kWorkArea;
    bool flag40;
    bool flag41;
    char unk42;
    bool flag43;
    int unk044;
    Mid* m_48;
    int unk04c, unk050, unk054;
    Node* m_pkNode;
    int unk05c;
    ThreeByThreeMatrix m_kRot;
    int unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac;
    char unk0b0, unk0b1, unk0b2;
    bool flagb3;
    int unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0;
    int unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0;
    int unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110;
    int unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150;
    int unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170;
    int unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190;
    int unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0;
    int unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0;
    int unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0;
    int unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210;
    int unk214, unk218;
    char unk21c, unk21d;
    bool flag21e;
    char unk21f;
    char unk220, unk221;
    bool flag222;
    bool flag223;
    int unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240;
    int unk244, unk248, unk24c, unk250;
    char unk254, unk255;
    bool flag256;
    char unk257;
    int unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274;
    int unk278, unk27c, unk280, unk284, unk288;
    char unk28c, unk28d;
    bool flag28e;
    char unk28f;
    __forceinline void Update(float);
    void bhkRagdollController_GetSGPoseLocalSpace();
    void FUN_008e5710(int);
    void FUN_008dd450(void*);
    void FUN_008dbec0(void*);
    void FUN_008e3ab0(void*);
    // Fake match: noalias stands in for this same-file callee's body, which the original compiler could see. It
    // only tells the compiler that the bool passed by address does not escape, so the loads of the count are not
    // held behind the store that clears it.
    __declspec(noalias) void FUN_008e6750(void*, void*, bool*);
    void bhkRagdollController_UpdateRagdollRigidBodies(void*);
    void FUN_008e6d70();
    void FUN_008e2480();
};
extern unsigned long DAT_010f3170;
extern char DAT_010f2c7c, DAT_010f2c88, DAT_010f2c94, DAT_010f2ca0, DAT_010f2cac, DAT_010f2cb8;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern void __cdecl FUN_008db970(void*, NiTransform*);
__forceinline char* ThreadMemory::Allocate(unsigned int bytes)
{
    char* old;
    old = current;
    if (old + bytes <= end)
    {
        current = old + bytes;
        return old;
    }
    return static_cast<char*>(OnStackOverflow(bytes));
}
__forceinline ScrapMarker::ScrapMarker(unsigned int count)
{
    ThreadMemory* memory = static_cast<ThreadMemory*>(DAT_00d9b080(DAT_010f3170));
    p = memory->Allocate((count * 48 + 0x10) & 0xfffffff0u);
}
__forceinline ScrapMarker::~ScrapMarker()
{
    ThreadMemory* memory;
    memory = static_cast<ThreadMemory*>(DAT_00d9b080(DAT_010f3170));
    memory->current = p;
    if (p == memory->base)
        memory->OnStackUnderflow(p);
}
__forceinline void Controller::Update(float)
{
    if (flag43 && !flagb3 && !flag222 && !flag21e && !flag28e)
    {
        flag43 = false;
        flag41 = false;
    }
    if (DAT_010f2c7c && flag41)
    {
        NiTransform kWorld = m_pkNode->GetParent()->m_kWorldSpaceTransform * m_pkNode->m_kLocalTransform;
        kWorld.m_kOrientation = m_kRot * kWorld.m_kOrientation;
        kWorld.m_fScale = 1.0f;
        FUN_008db970(&m_kWorkArea, &kWorld);
        if (flag40 == 0)
        {
            bhkRagdollController_GetSGPoseLocalSpace();
            FUN_008e5710(0);
            if (DAT_010f2c88 && (flag222 || flag223))
                FUN_008dd450(&m_kWorkArea);
            if (DAT_010f2c94 && flag21e)
                FUN_008dbec0(&m_kWorkArea);
            if (DAT_010f2ca0 && flagb3)
                FUN_008e3ab0(&m_kWorkArea);
        }
        unsigned int count = m_48->inner->count;
        bool bOk = false;
        ScrapMarker kScrap(count);
        bhkRagdollController_UpdateRagdollRigidBodies((DAT_010f2cb8 && flag256 && (FUN_008e6750(&m_kWorkArea, kScrap.p, &bOk), bOk)) ? kScrap.p : 0);
        FUN_008e5710(1);
        if (!flag40)
        {
            if (DAT_010f2cac && flag28e)
                FUN_008e6d70();
            FUN_008e5710(2);
            FUN_008e2480();
        }
    }
}
}

// The pack's class names its callees by their New Vegas addresses, so the body lives in a stand-in class with this
// game's callee names and is forced inline here.
// pdb: bhkRagdollController::DoRagdollAnim | bhkRagdollController.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abUpdateBones
void FUN_00c7d630_t::FUN_00c7d630(float dt)
{
    reinterpret_cast<f3m_008e7b20::Controller*>(this)->Update(dt);
}


namespace fnv_00c7d810 {
struct ThreeByThreeMatrix
{
    float m[3][3];
    ThreeByThreeMatrix operator*(ThreeByThreeMatrix const&) const;
};
struct Xform
{
    ThreeByThreeMatrix rot;
    float x, y, z, s;
};

void __cdecl FUN_00c74dd0(void*, void*);

struct XObj
{
    void FUN_00cdb3e0();
};

struct FUN_00c7d810_Cls
{
    void FUN_00c79680();
    void FUN_00c7d030(int);
    void FUN_00c7d810();
};

// @fnv 0x00c7d810
// pdb: bhkRagdollController::SyncRagdollTo3D | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
void FUN_00c7d810_Cls::FUN_00c7d810()
{
    Xform nitrans = *(Xform*)((char*)(*(void**)((char*)this + 0x58)) + 0x68);
    nitrans.rot = *(ThreeByThreeMatrix*)((char*)this + 0x60) * nitrans.rot;
    nitrans.s = 1.0f;
    FUN_00c74dd0((char*)this + 0x10, &nitrans);
    FUN_00c79680();
    int etype = *(int*)((char*)this + 0xc);
    *(int*)((char*)this + 0xc) = 1;
    FUN_00c7d030(0);
    *(int*)((char*)this + 0xc) = etype;
    XObj* p = *(XObj**)((char*)this + 0x4c);
    if (p)
        p->FUN_00cdb3e0();
}
}  // namespace fnv_00c7d810

void* __cdecl FUN_00ec7230(char*, char const*, unsigned int);

// @fnv 0x00c7f900
// pdb: BSSimpleArray<DetailedActorPathHandler::ActorAvoidanceData,1024>::_MoveItems | DetailedActorPathHandler.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_00c7f900(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;

    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(dst + i * 8, src + i * 8, 8);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(dst + i * 8, src + i * 8, 8);
    }
}

void __cdecl FUN_00d6b4b0(void*, unsigned int);

struct FUN_00cdb3e0_cls
{
    char pad[0x2c];
    void FUN_00cdb3e0();
};

// @fnv 0x00cdb3e0
void FUN_00cdb3e0_cls::FUN_00cdb3e0()
{
    FUN_00d6b4b0((char*)this + 0x18, *(unsigned int*)((char*)this + 0x2c));
}

struct S_c6a200_Info
{
    int unk00, unk04, unk08, unk0c;
};
struct S_c6a200_Ev
{
    int unk00;
    unsigned char unk04;
    int unk08;
    int unk0c;
    int unk10, unk14, unk18;
};
extern void* DAT_011afecc;
S_c6a200_Info* __cdecl GetExtraDataChecked(void* obj);
void __cdecl FUN_00c68900(void* obj, S_c6a200_Ev* ev, void* extra);
// @fnv 0x00c6a200
// pdb: bhkWorld::SetDisabled | bhkWorld.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_gap_sim) + skyrim(caller_sim), high
bool __cdecl bhkWorld_SetDisabled(void* obj, unsigned char a1, unsigned char a2, unsigned char a3)
{
    bool r = false;
    if (obj)
    {
        S_c6a200_Info* info;
        if (a3 || ((info = GetExtraDataChecked(obj)) ? (info->unk0c & 2) : 0))
        {
            S_c6a200_Ev ev;
            ev.unk04 = a2;
            r = true;
            ev.unk00 = 0;
            ev.unk08 = 0x11;
            ev.unk0c = a1;
            if (DAT_011afecc)
                FUN_00c68900(obj, &ev, DAT_011afecc);
        }
    }
    return r;
}

struct FlagController
{
    void FUN_00c7b6a0(int);
    void FUN_00c7ba10(bool);
};
// @fnv 0x00c7ba10
// pdb: bhkRagdollController::EnableRagdollFeedback | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: Projectile::HavokDetached)
// pdb params: abEnable
void FlagController::FUN_00c7ba10(bool enabled)
{
    unsigned char* state = (unsigned char*)this;
    bool target = state[0x28c] && enabled;
    if (!target && state[0x28e])
        FUN_00c7b6a0(0);
    state[0x28d] = target;
}

struct HkAllocator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Deallocate(void*, int);
};
struct HkMemHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkAllocator* allocator;
    HkAllocator* GetAllocator()
    {
        return allocator;
    }
};
HkMemHolder* GetHkMemHolder();
template <class T> inline void HkDeallocT(HkAllocator* a, T* p, int n)
{
    a->Deallocate(p, n * (int)sizeof(T));
}

struct HkElem30
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
};

template <class T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~HkArray()
    {
        HkAllocator* alloc = GetHkMemHolder()->GetAllocator();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            HkDeallocT<T>(alloc, m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FUN_00c7c030
{
    int unk00;
    HkArray<HkElem30> arr04;
    HkArray<HkElem30> arr10;
    HkArray<int> arr1C;
    int unk28;
    HkArray<int> arr2C;
    ~FUN_00c7c030();
};

// @fnv 0x00c7c030
FUN_00c7c030::~FUN_00c7c030()
{}

struct FreeIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Free(void* p, unsigned int size);
};

struct FUN_00c7d480_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void FUN_00c7d480();
};

struct ScopeGuard
{
    FUN_00c7d480_cls* owner;
// @fnv 0x00c7d480
    ScopeGuard(void* p) : owner((FUN_00c7d480_cls*)p)
    {}
    __forceinline ~ScopeGuard()
    {
        Holder* h = _FUN_00c85750();
        FreeIface* a = (FreeIface*)h->p;
        unsigned int flags = owner->m_08;
        owner->m_04 = 0;
        if (!(flags & 0x80000000))
        {
            a->Free(owner->m_00, (flags & 0x3fffffff) * 4);
        }
        owner->m_08 = 0x80000000;
        owner->m_00 = 0;
    }
};

namespace fnv_00c7d520 {
struct FreeIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Free(void* p, unsigned int size);
};

struct FUN_00c7d520_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void FUN_00c7d520();
};

struct ScopeGuard
{
    FUN_00c7d520_cls* owner;
// @fnv 0x00c7d520
    ScopeGuard(void* p) : owner((FUN_00c7d520_cls*)p)
    {}
    __forceinline ~ScopeGuard()
    {
        Holder* h = _FUN_00c85750();
        FreeIface* a = (FreeIface*)h->p;
        unsigned int flags = owner->m_08;
        owner->m_04 = 0;
        if (!(flags & 0x80000000))
        {
            a->Free(owner->m_00, (flags & 0x3fffffff) * 4);
        }
        owner->m_08 = 0x80000000;
        owner->m_00 = 0;
    }
};

}  // namespace fnv_00c7d520

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00c7d5c0_elem
{
    int unk00;
    void Release();
};

struct FUN_00c7d5c0_cls
{
    FUN_00c7d5c0_elem* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FUN_00c7d5c0();
};

// @f3 0x0097db70 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
extern int DAT_00e7d1f4;
extern int DAT_00e7d1d0;
extern int DAT_00e35eec;
extern int FUN_00dcc494;

struct L_c7d5c0_Obj {
    virtual ~L_c7d5c0_Obj();
    unsigned short flags;
    short refs;
};
struct L_c7d5c0_Entry {
    L_c7d5c0_Obj* p;
    int unk04;
    int unk08;
    int unk0c;
};
struct L_c7d5c0_Heap {
    void FUN_008f6d90(void* p, unsigned int size, int tag);
};
struct L_c7d5c0_Layout {
    int* vtbl0;
    int unk04;
    int unk08;
    int unk0c;
    int* vtbl1;
    int unk14;
    L_c7d5c0_Entry* arr;
    int len;
    unsigned int cap;
};

// pdb: hkpListShape::~hkpListShape | hkpListShape.obj | fnv360_0822_retail, call_seq, high
void FUN_00c7d5c0_cls::FUN_00c7d5c0()
{
    L_c7d5c0_Layout* self = (L_c7d5c0_Layout*)this;
    self->vtbl0 = &DAT_00e7d1f4;
    self->vtbl1 = &DAT_00e7d1d0;
    for (int i = 0; i < self->len; ++i)
    {
        L_c7d5c0_Obj* p = self->arr[i].p;
        if (p->flags != 0)
        {
            if (--p->refs == 0)
                delete p;
        }
    }
    unsigned int cap = self->cap;
    if ((cap & 0x80000000u) == 0)
    {
        struct CapacityBits516 { unsigned int count:30; unsigned int flags:2; };
        unsigned int n = reinterpret_cast<const CapacityBits516*>(&self->cap)->count;
        L_c7d5c0_Heap* h = (L_c7d5c0_Heap*)TlsGetValue(DAT_010f3170);
        h->FUN_008f6d90(self->arr, n * 16u, 0x17);
    }
    self->vtbl1 = &DAT_00e35eec;
    _ReadWriteBarrier();
    self->vtbl0 = &FUN_00dcc494;
}


extern unsigned int g_01268188;
extern unsigned int g_012685f4;
extern const char DAT_0108febc[];
extern const char DAT_010c52bc[];

struct BaseObject
{
    const char* classTable;
    unsigned int unknown04;
    unsigned int unknown08;
    BaseObject();
};

struct MiddleObject : BaseObject
{
    unsigned int initialized0c;
    MiddleObject() : initialized0c(0)
    {
        classTable = DAT_0108febc;
        ++g_01268188;
    }
    ~MiddleObject();
};

struct FUN_00c7f9e0 : MiddleObject
{
    FUN_00c7f9e0(void* context);
    void SpawnAndAttach(void* context);
};

// @fnv 0x00c7f9e0
// pdb: bhkHingeConstraint::bhkHingeConstraint | MissileProjectile.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arInfo
FUN_00c7f9e0::FUN_00c7f9e0(void* context) : MiddleObject()
{
    classTable = DAT_010c52bc;
    SpawnAndAttach(context ? (char*)context + 4 : 0);
    ++g_012685f4;
}

extern __declspec(thread) int g_iCB9810AllocTag;

struct BCB9810AllocTagScope
{
    int m_iSaved;

    BCB9810AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCB9810AllocTag;
        g_iCB9810AllocTag = aiAllocationTag;
    }
    ~BCB9810AllocTagScope()
    {
        g_iCB9810AllocTag = m_iSaved;
    }
};

struct RTTI_c9b
{
    const char* m_pcName;
    RTTI_c9b* m_pBaseRTTI;
};
extern unsigned char DAT_011f4428;

class GlobalObjectO2_00a7b610;

struct S
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
    virtual void v23();
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
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void SetMode(int iMode);
    void FUN_00561690(int);
    void FUN_005617c0(float* pf);
};

struct Cast_c9b
{
    char pad[0x10];
    S* m_10;
};

struct Ctrl_c9b
{
    Cast_c9b* FUN_00653290(GlobalObjectO2_00a7b610* pkType);
};

class Obj_c9b
{
  public:
    virtual void v00();
    virtual void v01();
    virtual RTTI_c9b* GetRTTI();
    char padCur[0x1c - 4];
    Ctrl_c9b* m_1c;
    char kad[0xa0 - 0x20];
    Obj_c9b** m_ppChildren;
    unsigned short m_usMax;
    unsigned short m_usElementCount;
};

void __cdecl ApplyCollisionEffect(Obj_c9b* pkObj, float f);

__forceinline bool IsNode_c9b(Obj_c9b* pkObj)
{
    RTTI_c9b* pkRTTI = pkObj->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == (RTTI_c9b*)&DAT_011f4428)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

// @f3 0x00915d30 (community match, verified in this file)
extern unsigned char DAT_0108f200;
extern int DAT_01092a48;
extern float DAT_01092a50;
void* __cdecl FUN_00424d50(const void* pkType, void* pkObject);
struct SF3
{
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();
    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();
    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();
    virtual void s078();
    virtual void s07c();
    virtual void s080();
    virtual void s084();
    virtual void s088();
    virtual void s08c();
    virtual void s090();
    virtual void s094();
    virtual void s098();
    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();
    virtual void s0b0();
    virtual void s0b4();
    virtual void s0b8();
    virtual void s0bc();
    virtual void s0c0();
    virtual void s0c4();
    virtual void s0c8();
    virtual void s0cc();
    virtual void s0d0();
    virtual void s0d4();
    virtual void s0d8();
    virtual void SetMode(int iMode);
    void FUN_004e6280(float* pf);
    void FUN_004e62c0(float* pf);
};
__forceinline bool IsNodeF3(Obj_c9b* pkObj)
{
    RTTI_c9b* pkRTTI = pkObj->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == (RTTI_c9b*)&DAT_0108f200)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}
// pdb: bhkBlendController::DoGetUp | bhkBlendController.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apObject, afTime
void __cdecl FUN_00c9bdf0(Obj_c9b* pkObj, float f)
{
    if (pkObj && IsNodeF3(pkObj) && pkObj->m_usElementCount > 0)
    {
        Obj_c9b* pkChild = pkObj->m_ppChildren[0];
        if (pkChild && IsNodeF3(pkChild) && pkChild->m_usElementCount > 0)
        {
            Obj_c9b* pkGrand = pkChild->m_ppChildren[0];
            if (pkGrand)
            {
                void* pkTarget = pkGrand->m_1c;
                Cast_c9b* pkCast = (Cast_c9b*)FUN_00424d50(&DAT_01092a48, pkTarget);
                if (pkCast)
                {
                    SF3* pkS = (SF3*)pkCast->m_10;
                    if (pkS)
                    {
                        pkS->SetMode(6);
                        pkS->FUN_004e6280(&DAT_01092a50);
                        pkS->FUN_004e62c0(&DAT_01092a50);
                    }
                }
            }
        }
    }
    ApplyCollisionEffect(pkObj, f);
}


void __stdcall FUN_00c7f900(char* dst, char* src, unsigned int count);
class FUN_00c7f970_cls
{
  public:
    virtual void vfn_0();
    virtual char* Alloc(unsigned int n);
    virtual void Free(char* p);
    virtual char* Realloc(char* p, unsigned int n);

    char* m_pData;
    void* unk;
    unsigned int m_uiSize;
    void FUN_00c7f970(unsigned int uiNew, unsigned int uiOld);
};

// @f3 0x0046e640 (community match, verified in this file)
struct FUN_0046e5c0_stub
{
    void FUN_0046e5c0(char* dst, char* src, unsigned int count);
};

// pdb: BSSimpleArray<PathSmootherPOVLink,1024>::_ReallocateBuffer | PathSmootherPOV.obj | fnv360_0822_retail, call_seq, low
// pdb params: aiNewSize, aiCopyCount
void FUN_00c7f970_cls::FUN_00c7f970(unsigned int uiNew, unsigned int uiOld)
{
    if (m_pData)
    {
        if (uiOld == m_uiSize)
        {
            m_pData = Realloc(m_pData, uiNew);
        }
        else
        {
            char* pNew = Alloc(uiNew);
            reinterpret_cast<FUN_0046e5c0_stub*>(this)->FUN_0046e5c0(pNew, m_pData, uiOld);
            Free(m_pData);
            m_pData = pNew;
        }
    }
    else
    {
        m_pData = Alloc(uiNew);
        m_uiSize = uiNew;
    }
}


struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b) : m_cBooleanValue((char)b)
    {}
};
struct Head
{
    hkBool a, b;
    int c;
    Head() : a(true), b(true), c(0)
    {}
};
struct hkArrayStandIn
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayStandIn() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
// @f3 0x007c2870 (community match, verified in this file)
extern int DAT_0108ec68;
extern int DAT_0108ec6c;
extern int DAT_0108ec70;

struct BooleanFloatQuery
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    int m_30;
    float m_34;
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
    void FUN_007c2870();
};

// pdb: HitData::ClearData | HitData.obj | fnv360_0822_retail, call_seq, medium
void BooleanFloatQuery::FUN_007c2870()
{
    m_14 = 0.0f;
    m_00 = 0;
    m_18 = 0.0f;
    m_04 = 0;
    m_1c = 0.0f;
    m_08 = 0;
    m_20 = 0.0f;
    m_0c = 0x49;
    m_24 = 0.0f;
    m_10 = -1;
    m_28 = 0.0f;
    m_2c = 0.0f;
    m_38 = DAT_0108ec68;
    m_3c = DAT_0108ec6c;
    m_40 = DAT_0108ec70;
    m_44 = DAT_0108ec68;
    m_48 = DAT_0108ec6c;
    m_4c = DAT_0108ec70;
    m_34 = 0.0f;
    m_5c = 0.0f;
    m_30 = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_60 = 0;
}


// FUN_00cb9650 @ 0x00cb9650, 97 bytes, __cdecl caller-pops
// flags: /MT /O2 /GS /EHsc /Gy
// Recursive child-visitor: controller fetch/set via members, virtual node
// fetch (vtable slot 3), loop over children (ptr @0xA0, count u16 @0xA6).

struct FUN_00cb9650_Node
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
    void** children;       // 0xA0
    unsigned short unkA4;  // 0xA4
    unsigned short count;  // 0xA6
};

struct FUN_00cb9650_Object
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual FUN_00cb9650_Node* vf0C();

    void* FUN_00a5c570(const void* typeInfo);
    void FUN_00a5c480(int value);
};

extern const char DAT_012683f4[];

// @fnv 0x00cb9650
// pdb: bhkForceController::RemoveForce | bhkForceController.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject
void __cdecl FUN_00cb9650(FUN_00cb9650_Object* object)
{
    if (object != 0)
    {
        void* controller = object->FUN_00a5c570(DAT_012683f4);
        if (controller != 0)
        {
            object->FUN_00a5c480((int)controller);
        }

        FUN_00cb9650_Node* node = object->vf0C();
        if (node != 0)
        {
            for (unsigned int index = 0; index < node->count; ++index)
            {
                FUN_00cb9650((FUN_00cb9650_Object*)node->children[index]);
            }
        }
    }
}

#include <xmmintrin.h>
extern "C" __declspec(align(16)) __m128 DAT_010c71b0;
struct RagController
{
    unsigned char& controlFlag()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x43);
    }
    unsigned char& activeFlag()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xb1);
    }
    unsigned char& stateFlag()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xb3);
    }
    __m128& poseA()
    {
        return *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x120);
    }
    __m128& poseB()
    {
        return *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x170);
    }
    unsigned char& dirtyA()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x130);
    }
    unsigned char& dirtyB()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x180);
    }
    void FUN_00c75580(unsigned char enabled);
};
// @f3 0x008dc2e0 (community match, verified in this file)
// pdb: bhkRagdollController::SetLookIKActive | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low
// pdb params: abActive
void RagController::FUN_00c75580(unsigned char enabled)
{
    int state;
    if (controlFlag() == 0)
    {
        if (activeFlag() != 0 && enabled != 0)
        {
            state = 1;
        }
        else
        {
            state = 0;
        }
    }
    else
    {
        state = stateFlag();
    }
    stateFlag() = (unsigned char)state;
    if (enabled == 0)
    {
        float* pa = reinterpret_cast<float*>(&poseA());
        float* pb = reinterpret_cast<float*>(&poseB());
        pa[0] = 0.0f;
        pa[1] = 0.0f;
        pa[2] = 0.0f;
        pa[3] = 1.0f;
        pb[3] = 1.0f;
        pb[0] = 0.0f;
        pb[1] = 0.0f;
        pb[2] = 0.0f;
        dirtyB() = 1;
        dirtyA() = 1;
    }
}


extern "C" double __cdecl sqrt(double x);
struct NodeC
{
    int n000;
    int n004;
    int n008;
    int n00c;
    int n010;
    int n014;
    NodeC* parent;
    int n01c;
    int n020;
    int n024;
    int n028;
    int n02c;
    int n030;
    Xform local;
    Xform world;
};
struct InnerC
{
    int i000;
    int i004;
    int i008;
    int i00c;
    int i010;
    int i014;
    int i018;
    unsigned int count;
};
struct MidC
{
    int m000;
    int m004;
    int m008;
    int m00c;
    int m010;
    int m014;
    int m018;
    int m01c;
    int m020;
    int m024;
    int m028;
    InnerC* inner;
    void FUN_00ce18f0(void*, void*);
};
struct Obj248
{
    int FUN_00ce11f0(void*, float*);
};
struct Obj250
{
    void FUN_00cc1420(void*, void*, int);
};
struct ScrapMarker
{
    char* p;
    unsigned int size;
    ScrapMarker(unsigned int count)
    {
        char** top = (char**)FUN_00c85750();
        unsigned int size = (count * 48 + 0x7f) & ~0x7fu;
        char* old = *top;
        *top = old + size;
        p = old;
    }
    ~ScrapMarker()
    {
        *(char**)FUN_00c85750() = p;
    }
};

struct Cls
{
    int u000;
    bool m_004;
    float m_008;
    int m_00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    MidC* m_048;
    int u04c;
    int u050;
    int u054;
    NodeC* m_058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int u114;
    int u118;
    int u11c;
    int u120;
    int u124;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    int u140;
    int u144;
    int u148;
    int u14c;
    int u150;
    int u154;
    int u158;
    int u15c;
    int u160;
    int u164;
    int u168;
    int u16c;
    int u170;
    int u174;
    int u178;
    int u17c;
    int u180;
    int u184;
    int u188;
    int u18c;
    int u190;
    int u194;
    int u198;
    int u19c;
    int u1a0;
    int u1a4;
    int u1a8;
    int u1ac;
    int u1b0;
    int u1b4;
    int u1b8;
    int u1bc;
    int u1c0;
    int u1c4;
    int u1c8;
    int u1cc;
    int u1d0;
    int u1d4;
    int u1d8;
    int u1dc;
    int u1e0;
    int u1e4;
    int u1e8;
    int u1ec;
    int u1f0;
    int u1f4;
    int u1f8;
    int u1fc;
    int u200;
    int u204;
    int u208;
    int u20c;
    int u210;
    int u214;
    int u218;
    int u21c;
    int u220;
    int u224;
    int u228;
    int u22c;
    int u230;
    int u234;
    int u238;
    int u23c;
    int u240;
    int u244;
    Obj248* m_248;
    int u24c;
    Obj250* m_250;
    int u254;
    int m_258;
    int u25c;
    __int64 m_260;
    __int64 m_268;
    Pt3 m_pos;
    float m_27c;
    float m_280;
    bool m_284;
    int m_288;

    void FUN_00c7ba50(void* a1, void* a2, bool* a3);
};

// @f3 0x008e6750 (community match, verified in this file)
struct Native2030Pt3{float x,y,z;};struct Native2030NodeC{unsigned unk000;unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;Native2030Pt3 trans;};
struct Native2030InnerC{unsigned unk000;unsigned unk004;unsigned unk008;unsigned unk00c;unsigned count;};struct Native2030MidC{unsigned unk000;unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;Native2030InnerC* inner;void FUN_00960f40(void*,void*);};struct Native2030Obj248{int FUN_00960820(void*,float*);};struct Native2030Obj250{void FUN_00944c30(void*,void*,int);};__int64 __cdecl FUN_0086c140();extern float DAT_00f7975c;extern float DAT_00f75448;extern DWORD DAT_010f3170;
struct Native2030Arena{virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual char* Allocate(unsigned);virtual void Release(char*);unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;char* top;unsigned unk24;char* base;char* limit;};
struct Native2030ScrapMarker{char* p;unsigned size;__forceinline Native2030ScrapMarker(unsigned count){Native2030Arena* arena=(Native2030Arena*)TlsGetValue(DAT_010f3170);unsigned size=(count*48+0x10)&~0xfu;char* old=arena->top;char* end=old+size;if(end<=arena->limit){arena->top=end;}else old=arena->Allocate(size);p=old;}~Native2030ScrapMarker(){Native2030Arena* arena=(Native2030Arena*)TlsGetValue(DAT_010f3170);arena->top=p;if(p==arena->base)arena->Release(p);}};
struct Native2030Cls
{
    int u000;
    bool m_004;
    float m_008;
    int m_00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    Native2030MidC* m_048;
    int u04c;
    int u050;
    int u054;
    Native2030NodeC* m_058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int u114;
    int u118;
    int u11c;
    int u120;
    int u124;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    int u140;
    int u144;
    int u148;
    int u14c;
    int u150;
    int u154;
    int u158;
    int u15c;
    int u160;
    int u164;
    int u168;
    int u16c;
    int u170;
    int u174;
    int u178;
    int u17c;
    int u180;
    int u184;
    int u188;
    int u18c;
    int u190;
    int u194;
    int u198;
    int u19c;
    int u1a0;
    int u1a4;
    int u1a8;
    int u1ac;
    int u1b0;
    int u1b4;
    int u1b8;
    int u1bc;
    int u1c0;
    int u1c4;
    int u1c8;
    int u1cc;
    int u1d0;
    int u1d4;
    int u1d8;
    int u1dc;
    int u1e0;
    int u1e4;
    int u1e8;
    int u1ec;
    int u1f0;
    int u1f4;
    int u1f8;
    int u1fc;
    int u200;
    int u204;
    int u208;
    int u20c;
    int u210;
    int u214;
    int u218;
    int u21c;
    int u220;
    int u224;
    int u228;
    int u22c;
    int u230;
    int u234;
    int u238;
    int u23c;
    int u240;
    int u244;
    Native2030Obj248* m_248;
    int u24c;
    Native2030Obj250* m_250;
    int u254;
    int m_258;
    int u25c;
    __int64 m_260;
    __int64 m_268;
    Native2030Pt3 m_pos;
    float m_27c;
    float m_280;
    bool m_284;
    int m_288;

    void FUN_00c7ba50(void* a1, void* a2, bool* a3);
};

// @fnv 0x00c7ba50
// pdb: bhkRagdollController::DoPoseMatching | bhkRagdollController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arWorldFromModel, apRagdollDrivePoseLS, arbUseDrivePose
void Cls::FUN_00c7ba50(void* a1, void* a2, bool* a3)
{
    Native2030Cls* self=(Native2030Cls*)this;
    Native2030Pt3* wp = &self->m_058->trans;
    float dx = self->m_pos.x - wp->x;
    float dy = self->m_pos.y - wp->y;
    float dz = self->m_pos.z - wp->z;
    float lenSq = dx * dx + dy * dy + dz * dz;
    double d = (float)sqrt((double)lenSq);
    float dist = (float)d;
    if (FUN_0086c140() - self->m_260 > self->m_268 || (self->m_284 && dist > self->m_27c) || self->m_288 != -1)
    {
        if (self->m_288 != -1)
        {
            self->m_250->FUN_00944c30(a2, self->m_048->inner, self->m_288);
            self->m_00c = 3;
            *a3 = true;
            self->m_258 = self->m_288;
            self->m_288 = -1;
        }
        else
        {
            self->m_pos = self->m_058->trans;
            Native2030InnerC* inner = self->m_048->inner;
            Native2030ScrapMarker marker(inner->count);
            self->m_048->FUN_00960f40(marker.p, a1);
            int id = self->m_248->FUN_00960820(marker.p, &self->m_008);
            if (self->m_008 < DAT_00f7975c && id != self->m_258)
            {
                self->m_258 = id;
                if (id != -1)
                {
                    Native2030Obj250* o250 = self->m_250;
                    o250->FUN_00944c30(a2, inner, id);
                    self->m_00c = 3;
                    *a3 = true;
                }
                else if (!*a3)
                {
                    self->m_00c = 0;
                    *a3 = false;
                    self->m_004 = true;
                }
            }
            else if (!*a3)
            {
                self->m_00c = 0;
                *a3 = false;
                self->m_004 = true;
            }
        }
        volatile float f = self->m_280;
        self->m_260 = FUN_0086c140();
        self->m_268 = (__int64)(f * DAT_00f75448);
    }
}


struct RagMotion
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
};
struct RagRigid
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
    virtual RagMotion* GetMotion();
};
struct RagBone
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RagRigid* rigid;
};
struct RagSkelInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int boneCount;
};
struct RagSkel
{
    int unk00;
    int unk04;
    int unk08;
    RagSkelInfo* info;
};
struct RagEntry
{
    int unk00;
    int unk04;
    void* owner;
};
struct RagSystem
{
    void FUN_00c6b320(RagEntry* entry);
};
struct RagWorld
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    RagSystem* system;
};
struct RagWorldRef
{
    int unk00;
    int unk04;
    RagWorld* world;
};
struct RagCtrl48
{
    int unk00;
    int unk04;
    RagWorldRef** worldRef;
    int unk0c;
    int unk10;
    RagEntry** entries;
    int entryCount;
    void* GetOwner()
    {
        return entries[0] ? entries[0]->owner : 0;
    }
    RagWorld* GetWorld()
    {
        RagWorldRef* wr = *worldRef;
        return wr ? wr->world : 0;
    }
    __forceinline void Reattach()
    {
        void* owner = GetOwner();
        RagWorld* w = GetWorld();
        if (!w)
            return;
        if (owner)
            return;
        RagSystem* sys = w->system;
        for (int i = 0; i < entryCount; i++)
        {
            RagEntry* e = entries[i];
            if (!e->owner)
                sys->FUN_00c6b320(e);
        }
    }
};
struct RagdollCtl
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
    char unk040;
    bool unk41;
    bool active;
    bool unk43;
    int unk044;
    RagCtrl48* ctrl48;
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
    RagBone** bones;
    int unk0a8;
    int unk0ac;
    char unk0b0;
    char unk0b1;
    bool unkb2;
    bool unkb3;
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
    __m128 vec120;
    bool unk130;
    char unk131;
    char unk132;
    char unk133;
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
    __m128 vec170;
    bool unk180;
    char unk181;
    char unk182;
    char unk183;
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
    float unk1b8;
    bool unk1bc;
    char unk1bd;
    char unk1be;
    char unk1bf;
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
    float unk1e8;
    bool unk1ec;
    char unk1ed;
    char unk1ee;
    char unk1ef;
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
    char unk21c;
    char unk21d;
    bool unk21e;
    char unk21f;
    char unk220;
    bool unk221;
    bool unk222;
    bool unk223;
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
    char unk28c;
    bool unk28d;
    char unk28e;
    bool unk28f;
    float unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    RagSkel* skel;
    int unk2a8;
    int unk2ac;
    void FUN_00c7b6a0(bool);
    void bhkRagdollController_DisableRagdollAnim(bool);
};

// @f3 0x008e6bf0 (community match, verified in this file)
namespace n8e6bf0 {
struct RMotion8e { char pad[0x14]; bool unk14; };
struct RRigid8e {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0a(); virtual void v0b(); virtual void v0c(); virtual void v0d(); virtual void v0e();
    virtual RMotion8e* GetMotion();
};
struct RBone8e { char pad[0x1c]; RRigid8e* rigid; };
struct RSkelInfo8e { char pad[0x10]; int boneCount; };
struct RSkel8e { char pad[0xc]; RSkelInfo8e* info; };
struct REntry8e { char pad[8]; void* owner; };
struct RSystem8e { void FUN_00c6b320(REntry8e* e); };
struct RWorld8e { char pad[0x310]; RSystem8e* system; };
struct RWorldRef8e { int unk00, unk04; RWorld8e* world; };
struct RCtrl8e {
    int unk00, unk04;
    RWorldRef8e** worldRef;
    int unk0c, unk10;
    REntry8e** entries;
    int entryCount;
    void* GetOwner() { return entries[0] ? entries[0]->owner : 0; }
    RWorld8e* GetWorld() { RWorldRef8e* wr = *worldRef; return wr ? wr->world : 0; }
    __forceinline void Reattach()
    {
        void* owner = GetOwner();
        RWorld8e* w = GetWorld();
        if (!w)
            return;
        if (owner)
            return;
        RSystem8e* sys = w->system;
        for (int i = 0; i < entryCount; i++)
        {
            REntry8e* e = entries[i];
            if (!e->owner)
                sys->FUN_00c6b320(e);
        }
    }
};
struct RVec48e {
    float x, y, z, w;
    __forceinline void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
}
using namespace n8e6bf0;

// pdb: bhkRagdollController::DisableRagdollAnim | bhkRagdollController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void RagdollCtl::bhkRagdollController_DisableRagdollAnim(bool b)
{
    if (active)
    {
        bool old = unk222;
        unk41 = false;
        unk43 = false;
        unk222 = false;
        if (old)
            unk223 = true;
        unk21e = false;
        unkb3 = false;
        ((RVec48e*)&vec120)->Set(0.0f, 0.0f, 0.0f, 1.0f);
        ((RVec48e*)&vec170)->Set(0.0f, 0.0f, 0.0f, 1.0f);
        unk180 = true;
        unk130 = true;
        if (unk28d)
            FUN_00c7b6a0(false);
        if (skel)
        {
            for (int i = 0; i < ((RSkel8e*)skel)->info->boneCount; i++)
            {
                RRigid8e* r = ((RBone8e**)bones)[i]->rigid;
                if (r)
                {
                    RMotion8e* m = r->GetMotion();
                    if (m)
                        m->unk14 = false;
                }
            }
        }
        unkb2 = false;
        unk1b8 = unk1e8 = 0.0f;
        unk1ec = false;
        unk1bc = false;
        unk221 = false;
        unk290 = 1.0f;
        unk228 = 0;
        unk28f = false;
        unk294 = 0;
        if (b)
            ((RCtrl8e*)ctrl48)->Reattach();
        for (int j = 0; j < 0; ++j)
        {
        }
    }
}


// @fnv 0x00c7f4a0
// pdb: hkVector4::isOk4 | hkVector4.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkVector4isOk)
static __declspec(noinline) unsigned char* FUN_00c7f4a0(unsigned char* out, const float* src, int count)
{
    int i = 0;
    if (count > 0)
    {
        do
        {
            float value = src[i];
            unsigned int bits = *(const unsigned int*)&value;
            if ((bits & 0x7f800000u) == 0x7f800000u)
            {
                *out = 0;
                return out;
            }
            ++i;
        } while (i < count);
    }
    *out = 1;
    return out;
}
unsigned char* S00c7f4a0_Call(unsigned char* out, const float* src, int count)
{
    return FUN_00c7f4a0(out, src, count);
}

struct HkFloatCheck
{
    void FUN_00c7f500(bool* pOut);
};
static inline bool IsFiniteFloat(float r)
{
    return ((*(unsigned int*)&r) & 0x7f800000) != 0x7f800000;
}

static __declspec(noinline) bool* CheckFloatsValid(const float* pData, int iCount, bool* pOut)
{
    for (int i = 0; i < iCount; i++)
        if (!IsFiniteFloat(pData[i]))
        {
            *pOut = false;
            return pOut;
        }
    *pOut = true;
    return pOut;
}
// @fnv 0x00c7f500
// pdb: hkVector4::isOk4 | hkVector4.obj | tesv_win, objrun_prop, low
void HkFloatCheck::FUN_00c7f500(bool* pOut)
{
    CheckFloatsValid((const float*)this, 4, pOut);
}

struct S_Out
{
    int unk00;
    int unk04;
};
struct S_Inner
{
    int FUN_00c85c80(int arg);
};
struct S_Val
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    unsigned char unk18;
};
struct S_Elem
{
    int unk00;
    int unk04;
    int unk08;
    S_Inner* unk0c;
};
inline void* GetOwner(S_Obj* c)
{
    return (char*)c + c->unk10;
}
inline S_Elem* GetEntity(S_Obj* c)
{
    return c->unk18 == 1 ? (S_Elem*)GetOwner(c) : 0;
}
inline S_Elem* GetPhantom(S_Obj* c)
{
    return c->unk18 == 2 ? (S_Elem*)GetOwner(c) : 0;
}
// @f3 0x008f1bf0 (community match, verified in this file)
struct S_InnerCall;
extern int DAT_010f2c30;
struct S_ElemCall
{
    int unk00;
    int unk04;
    int unk08;
    S_InnerCall* unk0c;

    S_Val** FUN_00477900(S_Out* out, void* tag);
};
struct S_InnerCall
{
    int FUN_008f9c90(int arg);
};
// pdb: bhkUtilFunctions::GetNiAVObject | bhkUtilFunctions.obj | fnv360_0822_debug, call_seq, medium
// pdb params: apCollidable
int __cdecl FUN_00c7fa90(S_Obj* p)
{
    int result = 0;
    if (S_Elem* e = GetEntity(p))
    {
        S_Out out;
        S_Val* v = *((S_ElemCall*)e)->FUN_00477900(&out, &DAT_010f2c30);
        if (v)
            result = v->unk08;
    }
    else if (S_Elem* ph = GetPhantom(p))
    {
        S_Out out;
        S_Val* v = *((S_ElemCall*)ph)->FUN_00477900(&out, &DAT_010f2c30);
        if (v)
            result = v->unk08;
        else if (ph->unk0c)
            result = ((S_InnerCall*)ph->unk0c)->FUN_008f9c90(0);
    }
    return result;
}


extern const __m128 DAT_010c71e0;
struct __declspec(align(16)) MVec4
{
    __m128 q;
    __forceinline void Rotate(const MVec4& rotation, const MVec4& position)
    {
        __m128 scalar = _mm_shuffle_ps(rotation.q, rotation.q, 255);
        __m128 factor = _mm_add_ps(DAT_010c71e0, _mm_mul_ps(scalar, scalar));
        __m128 sum = _mm_mul_ps(position.q, factor);
        __m128 product = _mm_mul_ps(rotation.q, position.q);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
        dot = _mm_add_ss(_mm_shuffle_ps(product, product, 170), dot);
        dot = _mm_shuffle_ps(dot, dot, 0);
        sum = _mm_add_ps(sum, _mm_mul_ps(dot, rotation.q));
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(rotation.q, rotation.q, 201), _mm_shuffle_ps(position.q, position.q, 210)),
            _mm_mul_ps(_mm_shuffle_ps(rotation.q, rotation.q, 210), _mm_shuffle_ps(position.q, position.q, 201)));
        sum = _mm_add_ps(sum, _mm_mul_ps(scalar, cross));
        q = _mm_add_ps(sum, sum);
    }
    __forceinline void Add(const MVec4& a)
    {
        q = _mm_add_ps(q, a.q);
    }
};
struct BoneFlags
{
    unsigned int bits;
    __forceinline BoneFlags& Set(unsigned int mask)
    {
        bits |= mask;
        return *this;
    }
    __forceinline BoneFlags& Clear(unsigned int mask)
    {
        bits &= ~mask;
        return *this;
    }
};

struct C7C2B0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct C7C2B0_Pair
{
    int a;
    int b;
};
struct C7C2B0_Array
{
    C7C2B0_Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~C7C2B0_Array()
    {
        Holder* holder = _FUN_00c85750();
        C7C2B0_Heap* heap = (C7C2B0_Heap*)holder->p;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            int cap = m_iCapacityState & 0x3fffffff;
            C7C2B0_Pair* data = m_data;
            heap->ReturnMemory(data, cap * sizeof(C7C2B0_Pair));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

extern "C" void _ReadWriteBarrier(void);
struct AllocHolderX
{
    int unk00, unk04, unk08, unk0C;
    HkAllocator* m_pAllocator;
    HkAllocator* GetAllocator()
    {
        return m_pAllocator;
    }
};
__forceinline void FreeObjX(void* p, unsigned int n)
{
    Holder* h = _FUN_00c85750();
    h->p->f2(p, n);
}
template <class T> struct HkArrX
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;
    ~HkArrX()
    {
        AllocHolderX* h = (AllocHolderX*)_FUN_00c85750();
        HkAllocator* alloc = h->GetAllocator();
        m_iElementCount = 0;
        if (!(m_capFlags & 0x80000000))
            HkDeallocT<T>(alloc, m_data, m_capFlags & 0x3fffffff);
        m_data = 0;
        m_capFlags = 0x80000000;
    }
};
struct HkRef
{
    void removeReference();
};
struct RefObj
{
    virtual void vf0();
    virtual void vf1();
    long m_iObjectReferenceCount;
};
struct RefPtr
{
    RefObj* m_p;
    void Reset()
    {
        RefObj* p = m_p;
        if (p)
        {
            if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
                p->vf1();
            m_p = 0;
        }
    }
    ~RefPtr()
    {
        RefObj* p = m_p;
        if (p)
        {
            if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
                p->vf1();
        }
    }
};
extern int DAT_0109b220;
struct FixedStr9
{
    char* m_h;
    char* GetChars()
    {
        return m_h;
    }
    ~FixedStr9()
    {
        if (m_h != (char*)DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_h - 8));
    }
};
struct PolyBase
{
    virtual void vf0(void* p);
    virtual void vf1(void* p);
    virtual void vf2(void* p);
    virtual void vf3(void* p);
};
struct PolyArr : PolyBase
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    ~PolyArr()
    {
        PolyBase* b = this;
        if (m_data)
        {
            b->vf2(m_data);
            m_data = 0;
            m_cap = 0;
            m_iElementCount = 0;
        }
    }
};
struct T48
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};
struct T32
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
};
struct T208
{
    HkRef* m_p0;
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
};
struct Arr32
{
    HkArrX<T32> m_aiIndexedValues;
    int m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};
struct X48
{
    void ClearArrays();
};
struct MapStd
{
    void FUN_00e92760(char* key, void** out);
    void FUN_00e91fd0(char* key);
};
extern MapStd DAT_011b02f0;
extern MapStd DAT_011b0300;
struct BaseC7
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual ~BaseC7()
    {}
};

struct FUN_00c7d900 : BaseC7
{
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
    HkRef* m_p48;
    X48* m_p4c;
    int m_050;
    FUN_00c7c030* m_p54;
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
    RefPtr m_84;
    FUN_00c7c030* m_p88;
    int m_08c;
    int m_090;
    HkArrX<T48> m_94;
    PolyArr m_a0;
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
    HkArrX<T208> m_22c;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    Arr32* m_p248;
    FixedStr9 m_24c;
    RefPtr m_250;
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
    FixedStr9 m_2a0;
    RefPtr m_2a4;
    ~FUN_00c7d900();
};

// @fnv 0x00c7d900
FUN_00c7d900::~FUN_00c7d900()
{
    int n = m_22c.m_iElementCount;
    for (int i = 0; i < n; ++i)
        m_22c.m_data[i].m_p0->removeReference();
    m_22c.m_iElementCount = 0;
    _ReadWriteBarrier();
    X48* pk4c = m_p4c;
    if (pk4c)
    {
        pk4c->ClearArrays();
        FreeObjX(pk4c, 0x48);
    }
    HkRef* pk48 = m_p48;
    if (pk48)
        pk48->removeReference();
    FUN_00c7c030* pk54 = m_p54;
    if (pk54)
    {
        pk54->~FUN_00c7c030();
        FreeObjX(pk54, 0x38);
    }
    FUN_00c7c030* pk88 = m_p88;
    if (pk88)
    {
        pk88->~FUN_00c7c030();
        FreeObjX(pk88, 0x38);
    }
    DAT_011b02f0.FUN_00e92760(m_24c.GetChars(), (void**)&m_250);
    if (m_250.m_p && ((int*)m_250.m_p)[1] == 2)
        DAT_011b02f0.FUN_00e91fd0(m_24c.GetChars());
    if (m_2a4.m_p && ((int*)m_2a4.m_p)[1] == 2)
        DAT_011b0300.FUN_00e91fd0(m_2a0.GetChars());
    m_2a4.Reset();
    m_250.Reset();
    Arr32* pk248 = m_p248;
    if (pk248)
    {
        pk248->~Arr32();
        FreeObjX(pk248, 0x30);
    }
}

namespace fnv_00cda110 {

struct A
{
    char pad0[0x1c];
    int count;  // 0x1c
    char pad20[4];
    void* p24;  // 0x24
    char pad28[0xc];
    int n34;  // 0x34
};
struct S
{
    A* a;       // 0x00
    void* p04;  // 0x04
    char pad08[0x14];
    int* arr1c;  // 0x1c
    char pad20[8];
    char b28;  // 0x28
    char b29;  // 0x29
    char pad2a[2];
    float* arr2c;  // 0x2c
};
}  // namespace fnv_00cda110

struct KPoint3
{
    float x, y, z;
    __declspec(noalias) KPoint3& Sub(const KPoint3& o);
};

struct KMatrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct KTransform
{
    KMatrix3 rot;
    KPoint3 trans;
    float scale;
};

struct KQuat
{
    float w, x, y, z;
    __declspec(noalias) void ToRotationMatrix(KMatrix3& m) const;
    __declspec(noalias) void FromRotationMatrix(const KMatrix3& m);
};

struct KUpdateData
{
    float fTime;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
};

struct KRigidBody
{
    __declspec(noalias) bool IsActive();
    __declspec(noalias) void GetPosition(KPoint3& p);
    __declspec(noalias) void GetRotation(KQuat& q);
};

struct KRagInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    KRigidBody* body;
    int unk14;
    float weight;
    bool IsKeyframed() const
    {
        return weight == 0.0f;
    }
};

struct KNode;

struct KObject
{
    __declspec(noalias) virtual void v00();
    __declspec(noalias) virtual void v01();
    __declspec(noalias) virtual void v02();
    __declspec(noalias) virtual KNode* GetAsNode();
    __declspec(noalias) virtual void v04();
    __declspec(noalias) virtual void v05();
    __declspec(noalias) virtual void v06();
    __declspec(noalias) virtual void v07();
    __declspec(noalias) virtual void v08();
    __declspec(noalias) virtual void v09();
    __declspec(noalias) virtual void v10();
    __declspec(noalias) virtual void v11();
    __declspec(noalias) virtual void v12();
    __declspec(noalias) virtual void v13();
    __declspec(noalias) virtual void v14();
    __declspec(noalias) virtual void v15();
    __declspec(noalias) virtual void v16();
    __declspec(noalias) virtual void v17();
    __declspec(noalias) virtual void v18();
    __declspec(noalias) virtual void v19();
    __declspec(noalias) virtual void v20();
    __declspec(noalias) virtual void v21();
    __declspec(noalias) virtual void v22();
    __declspec(noalias) virtual void v23();
    __declspec(noalias) virtual void v24();
    __declspec(noalias) virtual void v25();
    __declspec(noalias) virtual void v26();
    __declspec(noalias) virtual void v27();
    __declspec(noalias) virtual void v28();
    __declspec(noalias) virtual void v29();
    __declspec(noalias) virtual void v30();
    __declspec(noalias) virtual void v31();
    __declspec(noalias) virtual void v32();
    __declspec(noalias) virtual void v33();
    __declspec(noalias) virtual void v34();
    __declspec(noalias) virtual void v35();
    __declspec(noalias) virtual void v36();
    __declspec(noalias) virtual void v37();
    __declspec(noalias) virtual void v38();
    __declspec(noalias) virtual void v39();
    __declspec(noalias) virtual void v40();
    __declspec(noalias) virtual void v41();
    __declspec(noalias) virtual void v42();
    __declspec(noalias) virtual void v43();
    __declspec(noalias) virtual void v44();
    __declspec(noalias) virtual void v45();
    __declspec(noalias) virtual void UpdateDownward(KUpdateData& data);
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
    KTransform local;
    KTransform world;
    __declspec(noalias) void UpdateWorldLoc();
};

struct KNode : KObject
{
    int unk9c;
    KObject** children;
    unsigned short unka4;
    unsigned short childCount;
    KObject* GetAt(unsigned int i)
    {
        return i < childCount ? children[i] : 0;
    }
};

__declspec(noalias) void* FUN_00c81c50(void* node);

// @f3 0x008f3e60 (community match, verified in this file)
void* __cdecl FUN_008f3950(void* pNode);

struct KRigidBodyView
{
    bool FUN_00726810();
    void FUN_004e6030(KPoint3& p);
    void FUN_004e6070(KQuat& q);
};
struct KQuatView
{
    float w, x, y, z;
    void NiQuaternion_ToRotation(KMatrix3& m) const;
};
struct KNodeUpdateView
{
    void FUN_008330a0();
};

// pdb: bhkBlendCollisionObject::SetBipTransform | bhkBlendCollisionObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, arDelta, abZeroZ
void FUN_00c821b0(KObject* root, KPoint3* outDelta, bool update)
{
    if (!root)
        return;
    KNode* node = root->GetAsNode();
    if (!node)
        return;
    if (node->childCount <= 0)
        return;
    KObject* child0 = node->children[0];
    if (!child0)
        return;
    KNode* child = child0->GetAsNode();
    if (!child)
        return;
    if (child->childCount <= 0)
        return;
    KObject* child1 = child->children[0];
    if (!child1)
        return;
    KNode* grand = child1->GetAsNode();
    if (!grand)
        return;
    KRagInfo* info = (KRagInfo*)FUN_008f3950(child);
    if (!info)
        return;
    bool weightless = info->weight == 0.0f;
    if (grand->unk1c || weightless)
    {
        KTransform t;
        KRigidBody* body = info->body;
        if (body && ((KRigidBodyView*)body)->FUN_00726810())
        {
            KQuat q;
            ((KRigidBodyView*)body)->FUN_004e6030(t.trans);
            ((KRigidBodyView*)body)->FUN_004e6070(q);
            ((KQuatView*)&q)->NiQuaternion_ToRotation(t.rot);
        }
        else
        {
            t = grand->world;
        }
        KTransform old = node->local;
        if (update || !weightless)
            t.trans.z = old.trans.z;
        KPoint3 pos = t.trans;
        *outDelta = pos;
        outDelta->x -= node->local.trans.x;
        outDelta->y -= node->local.trans.y;
        outDelta->z -= node->local.trans.z;
        node->local.trans = pos;
        if (weightless)
            node->local.rot = t.rot;
        if (update)
        {
            ((KNodeUpdateView*)node)->FUN_008330a0();
            KUpdateData data;
            data.fTime = 0.0f;
            data.b0 = false;
            data.b1 = false;
            data.b2 = false;
            data.b3 = false;
            data.b4 = false;
            node->UpdateDownward(data);
        }
    }
}


template <class T> __forceinline void ShortFree(AudioAllocator& a, void* p, const int& cnt)
{
    a.FreeArray(p, cnt * (unsigned int)sizeof(T));
}
template <class T> __forceinline void FreeArr(AudioAllocator& a, void* p, int cnt)
{
    a.FreeArray(p, cnt * (unsigned int)sizeof(T));
}
struct StringPtr
{
    void* m_data;
    __forceinline ~StringPtr()
    {
        FUN_00cb0c00();
    }
    void FUN_00cb0c00();
};
struct Bone
{
    StringPtr m_name;
    bool m_bLockTranslation;
};
struct QsTransform
{
    float v[12];
};
struct RefObject
{
    virtual ~RefObject();
    void removeReference() throw();
};
struct LocalFrameOnBone
{
    RefObject* m_pLocalFrame;
    int m_iBoneIndex;
};
template <class T> __forceinline void GenericFree(AudioAllocator& a, T* const& p, const int& cnt)
{
    a.FreeArray(p, cnt * (unsigned int)sizeof(T));
}
template <class T> __forceinline void AlternateFree(AudioAllocator& a, void* p, const int& cnt)
{
    a.FreeArray(p, cnt * (unsigned int)sizeof(T));
}
template <class T> struct Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~Array()
    {
        AudioAllocator& alloc = *FUN_00c85750()->m_pAllocator;
        int sz = m_iElementCount;
        T* p = m_data;
        for (int i = 0; i < sz; ++i, ++p)
        {
            p->~T();
        }
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            GenericFree<T>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    }
};
template <> struct Array<LocalFrameOnBone>
{
    LocalFrameOnBone* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~Array()
    {
        AudioHolder* holder = FUN_00c85750();
        AudioAllocator& alloc = *holder->m_pAllocator;
        int sz = m_iElementCount;
        LocalFrameOnBone* const p = m_data;
        for (int i = 0; i < sz; ++i)
        {
            RefObject* obj = p[i].m_pLocalFrame;
            if (obj)
            {
                obj->removeReference();
            }
            p[i].m_pLocalFrame = 0;
        }
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            AlternateFree<LocalFrameOnBone>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    }
};
template <> struct Array<short>
{
    short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~Array()
    {
        AudioHolder* holder = FUN_00c85750();
        AudioAllocator& alloc = *holder->m_pAllocator;
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            ShortFree<short>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    }
};
template <> struct Array<QsTransform>
{
    QsTransform* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~Array()
    {
        AudioHolder* holder = FUN_00c85750();
        AudioAllocator& alloc = *holder->m_pAllocator;
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            FreeArr<QsTransform>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    }
};
struct Base
{
    virtual ~Base()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class __declspec(novtable) FUN_00c7dc40 : public Base
{
  public:
    StringPtr m_name;
    Array<short> m_kParentIndices;
    Array<Bone> m_kBones;
    Array<QsTransform> m_kReferencePose;
    Array<StringPtr> m_kBoneNames;
    Array<LocalFrameOnBone> m_kLocalFrames;
    virtual ~FUN_00c7dc40();
};
// @fnv 0x00c7dc40
FUN_00c7dc40::~FUN_00c7dc40()
{}

typedef unsigned char u8;
