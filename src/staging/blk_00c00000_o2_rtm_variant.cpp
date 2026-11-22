// src/staging/blk_00c00000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00c00000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00c00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void __cdecl FUN_00c03270();
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern int(__stdcall* DAT_00fdf1c0)(void*);
struct RefObject
{
    virtual void Unused0();
    virtual void DeleteThis();
    int m_iObjectReferenceCount;

    void DecRefCount(int(__stdcall* pfnDec)(void*))
    {
        if (pfnDec(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_iObjectReferenceCount);
    }
};
extern "C" void __cdecl FUN_00b4f510();
extern "C" void __cdecl _delete(void*, unsigned int);
extern "C" void __cdecl _delete(void*, unsigned int);
void __cdecl UpdateFlagHolders(int);
struct BeamStage
{
    char pad00[8];
    void* m_p08;
    char pad0c[0x54];
    int m_iObjectReferenceCount;
};
struct StageReturn : BeamStage
{
    void __thiscall ReturnToPool();
};
struct NiD3DPass : StageReturn
{
    bool __thiscall ApplyRenderStateChanges(bool);
};
struct StageReturnPtr
{
    NiD3DPass* m_pObject;

    StageReturnPtr() : m_pObject(0)
    {}

    void operator=(NiD3DPass* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_iObjectReferenceCount == 0)
                    m_pObject->ReturnToPool();
            }

            m_pObject = pObject;

            if (m_pObject)
                ++m_pObject->m_iObjectReferenceCount;
        }
    }

    ~StageReturnPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_iObjectReferenceCount == 0)
                m_pObject->ReturnToPool();
        }
    }
};
struct FnvObj;
struct FnvObj
{
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual void vt10();
    virtual void vt14();
    virtual void vt18();
    virtual void vt1c();
    virtual void vt20();
    virtual void vt24();
    virtual void vt28();
    virtual void vt2c();
    virtual void vt30();
    virtual void vt34();
    virtual void vt38();
    virtual void vt3c();
    virtual void vt40();
    virtual void vt44();
    virtual void vt48();
    virtual void vt4c();
    virtual void vt50();
    virtual void vt54();
    virtual void vt58();
    virtual void vt5c();
    virtual void vt60();
    virtual void vt64();
    virtual void vt68();
    virtual void vt6c();
    virtual void vt70();
    virtual void vt74();
    virtual void vt78();
    virtual void vt7c();
    virtual void vt80();
    virtual void vt84();
    virtual void vt88();
    virtual void vt8c();
    virtual unsigned int vt90(int);
};
extern unsigned int DAT_011a9bd0;
extern unsigned int DAT_011a9bd4;
extern unsigned int DAT_011a9bd8;
extern unsigned int DAT_011a9bdc;
extern unsigned int DAT_011fa2d0;
extern unsigned int DAT_011fa2d4;
extern unsigned int DAT_011fa2d8;
extern unsigned int DAT_011fa2dc;
void UpdateFlagHolders(unsigned int uiIndex);
struct Base03270
{
    ~Base03270();
};
struct Obj03270
{
    virtual void Release(int flags);
};
struct Holder03270
{
    Obj03270* m_iWordAt00;
    Obj03270* m_iWordAt04;
};
struct Table03270
{
    void SetAt(unsigned int index, Obj03270*& value);
    unsigned int m_u00;
};
struct Ptr03270
{
    Obj03270* m_p;
    Ptr03270()
    {}
    ~Ptr03270()
    {}
};
struct Sub03270
{
    ~Sub03270();
};
struct FUN_00c03270 : Base03270
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Table03270 m_18;
    Holder03270* m_1c;
    unsigned int unk20[14];
    Sub03270 m_58;

    ~FUN_00c03270();
};
class FUN_00c036f0_sub28;
class FUN_00c036f0_sub5c;
class FUN_00c036f0_sub28
{
  public:
    void FUN_00ba3aa0(int aiMode, FUN_00c036f0_sub5c** appRef);
};
class FUN_00c036f0_sub5c
{
  public:
    void FUN_00ba3840(int aiValue);
};
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct ShaderObj
{
    virtual void Unused0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};
// FUN_00c03d70 : copies a member into a global and returns.
//   mov eax,[ecx+0x5c] / mov [0x126f74c],eax / ret 4
// FUN_00c043f0: thiscall, one stack arg, two guarded virtual calls on this->m_30 / this->m_34.
struct B4630X;
struct B4630Y;
struct B4630G;
struct B4630X
{
    void* unk00_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    const char* m_20;
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
    int m_68;
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
    struct B4630Y* m_b8;
};
struct B4630Y
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
    int m_34;
};
struct B4630G
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
    void* m_44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* m_5c;
};
struct B4630Obj
{
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78(void* a0, void* a1, int a2, int a3, int a4, int a5, int a6, void* a7, const char* a8, int a9,
                     int a10);
};
class FUN_00c043f0_cls
{
  public:
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
    struct B4630Obj* m_30;
    struct B4630Obj* m_34;
    void __thiscall FUN_00c043f0(int a1);
};
class MemoryManagerC046
{
  public:
    void Deallocate(void* pvMem);
};
extern MemoryManagerC046 g_kMemoryManagerC046;
class ImageSpaceTextureC046
{
  public:
    ~ImageSpaceTextureC046();

    static void operator delete(void* pvMem)
    {
        g_kMemoryManagerC046.Deallocate(pvMem);
    }
};
template <class T> class C04620PrimitiveArray
{
  public:
    virtual ~C04620PrimitiveArray();

    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void SetAt(unsigned int uiIndex, const T& element);

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
struct FUN_00ba4080_class
{
    void FUN_00ba4080();
    FUN_00ba4080_class()
    {
        FUN_00ba4080();
    }
    ~FUN_00ba4080_class();
};
struct FourFloats
{
    float x, y, z, w;
    FourFloats() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}
    FourFloats(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct TailC049C0
{
    unsigned int flags;
    TailC049C0() : flags(0)
    {}
    ~TailC049C0();
};
extern "C" void __cdecl FUN_00ba4080();
// Constructor-like method: base call, vtable store, field init, flag bit.
// CopyOwnerValuesToItems candidate
struct TexStage
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int unk10[20];
    int m_iObjectReferenceCount;  // 0x60
    void ReturnToPool();
    void DecRef()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};
struct TexStagePtr
{
    TexStage* m_p;
    TexStagePtr() : m_p(0)
    {}
    ~TexStagePtr()
    {
        if (m_p)
            m_p->DecRef();
    }
};
struct RefTex
{
    virtual void v00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct RenderStateGroup
{
    static RenderStateGroup* __cdecl GetFree();
    void SetRenderState(int state, int value, bool save);
};
struct ShaderPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RenderStateGroup* m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RefTex* m_44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RefTex* m_5c;
    int unk60;
    int m_iObjectReferenceCount;  // 0x64

    static void __cdecl CreateStage(TexStagePtr* out);
    void SetStage(unsigned int idx, TexStage* stage);
    void Destroy();

    RenderStateGroup* GetRSG()
    {
        if (m_30 == 0)
            m_30 = RenderStateGroup::GetFree();
        return m_30;
    }
};
void __cdecl SetupStage(TexStage* stage, unsigned int idx, int a, int b, int c);
extern int DAT_011f9534;
struct ShaderPassPtr
{
    ShaderPass* m_p;
    ShaderPassPtr() : m_p(0)
    {}
    ~ShaderPassPtr()
    {
        if (m_p)
        {
            if (--m_p->m_iObjectReferenceCount == 0)
                m_p->Destroy();
        }
    }
    void operator=(const ShaderPassPtr& sp)
    {
        if (m_p != sp.m_p)
        {
            if (m_p)
            {
                if (--m_p->m_iObjectReferenceCount == 0)
                    m_p->Destroy();
            }
            m_p = sp.m_p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }
    ShaderPass* operator->() const
    {
        return m_p;
    }
};
static __forceinline void AssignTex(RefTex*& dst, RefTex* src)
{
    RefTex* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->m_iObjectReferenceCount);
    }
}
static __forceinline void SetupStages(ShaderPassPtr& spRenderPass, TexStagePtr& spStage)
{
    unsigned int n = spRenderPass->m_18;
    if (n < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 0, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
}
static __forceinline void SetupRenderStates(ShaderPassPtr& spRenderPass)
{
    spRenderPass->GetRSG()->SetRenderState(0x1b, 0, true);
    spRenderPass->GetRSG()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRSG()->SetRenderState(7, 1, true);
    spRenderPass->GetRSG()->SetRenderState(0x17, 4, true);
    spRenderPass->GetRSG()->SetRenderState(0xe, 1, true);
}
struct RefHandle
{
    RefObject* object;
    explicit RefHandle(RefObject* ptr = 0) : object(ptr)
    {}
    ~RefHandle()
    {
        if (object != 0)
            object->DecRefCount(DAT_00fdf1c4);
    }
    operator RefObject*() const
    {
        return object;
    }
};
RefObject* __cdecl FUN_00c163a0(unsigned int index);
class C1A3B0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
struct C1A3B0Point3
{
    float x;
    float y;
    float z;
};
class C1A3B0Bound
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<C1A3B0Heap&>(g_memoryManager).Allocate(uiSize);
    }

    C1A3B0Bound& operator=(const C1A3B0Bound& kBound)
    {
        m_kCenter = kBound.m_kCenter;
        m_fBoundRadius = kBound.m_fBoundRadius;
        return *this;
    }

    const C1A3B0Point3& GetNavMeshData() const
    {
        return m_kCenter;
    }
    float GetRadius() const
    {
        return m_fBoundRadius;
    }
    void SetCenterAndRadius(const C1A3B0Point3& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }

    C1A3B0Point3 m_kCenter;
    float m_fBoundRadius;
};
struct C1A550Point3
{
    float x;
    float y;
    float z;
};
class C1A550Bound
{
  public:
    const C1A550Point3& GetNavMeshData() const
    {
        return m_kCenter;
    }
    float GetRadius() const
    {
        return m_fBoundRadius;
    }
    void SetCenterAndRadius(const C1A550Point3& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }

    C1A550Point3 m_kCenter;
    float m_fBoundRadius;
};
extern long g_liveObjectCount;
struct CountedObjectBase
{
    virtual ~CountedObjectBase();
    int m_iRefCount;

    CountedObjectBase()
    {
        m_iRefCount = 0;
        InterlockedIncrement((volatile long*)&g_liveObjectCount);
    }
};
struct RefTex111
{
    virtual void Unused0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct ElemObj
{
    void __thiscall SetNodeValue(int a, int b, int c);
};
ElemObj* __cdecl FUN_00e7f5d0();
void __cdecl AssignStageFromPool(StageReturn*& p);
struct RefPtr
{
    RefTex111* m_pObject;
};
static __forceinline void AssignRef(RefTex111*& dst, RefTex111* src)
{
    RefTex111* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->m_iObjectReferenceCount);
    }
}
struct StagePtr
{
    StageReturn* m_pObject;
    StagePtr() : m_pObject(0)
    {}
    static __forceinline void Release(StageReturn* p)
    {
        --p->m_iObjectReferenceCount;
        if (p->m_iObjectReferenceCount == 0)
            p->ReturnToPool();
    }
    ~StagePtr()
    {
        if (m_pObject)
            Release(m_pObject);
    }
};
struct ClusterObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int GetCount() const
    {
        return m_18;
    }
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    ElemObj* m_30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    RefPtr m_44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    RefPtr m_5c;
    unsigned int unk60;
    int m_64;
    void __thiscall FUN_00e802b0(int idx, StageReturn* s);
    void __thiscall FUN_00e80190();
};
struct ClusterPtr
{
    ClusterObj* m_pObject;
    ClusterPtr() : m_pObject(0)
    {}
    ClusterObj* operator->()
    {
        return m_pObject;
    }
    void operator=(ClusterObj* const& p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_64 == 0)
                    m_pObject->FUN_00e80190();
            }
            m_pObject = p;
            if (m_pObject)
                ++m_pObject->m_64;
        }
    }
    ~ClusterPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_64 == 0)
                m_pObject->FUN_00e80190();
        }
    }
};
extern ClusterObj* DAT_01202230;
extern int DAT_011f9534;
struct FUN_00c0d200_class
{
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
    RefTex111* m_ac;
    RefTex111* m_b0;
    RefTex111* m_b4;
    RefTex111* m_b8;
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
    RefTex111* m_110;
    RefTex111* m_114;
    RefTex111* m_118;
    RefTex111* m_11c;
    RefTex111* m_120;
    RefTex111* m_124;
    RefTex111* m_128;
    RefTex111* m_12c;
    void InitClusterStages();
};
void __cdecl ConfigureBeamStage(FUN_00c0d200_class* self, int a, int b, int c, int d);
static __forceinline void SetupFourStages(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 4)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(0, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 1, 1, 2, 1);
        pass->SetStage(1, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 2, 1, 2, 1);
        pass->SetStage(2, stage.m_p);
        ShaderPass::CreateStage(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        SetupStage(stage.m_p, 3, 3, 0, 1);
        pass->SetStage(3, stage.m_p);
    }
}
extern int DAT_011f950c;
extern int DAT_011f9534;
extern int DAT_011f9538;
static __forceinline void SetupC16400Stages1(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 1)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
static __forceinline void SetupC16400Stages2(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 2)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
static __forceinline void SetupC16400Stages4(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 4)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 1, 3, 2, 1);
        stage.m_p->m_08 = DAT_011f9534;
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 2, 3, 2, 1);
        stage.m_p->m_08 = DAT_011f9538;
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 3, 1, 2, 1);
        stage.m_p->m_08 = DAT_011f950c;
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObjectF42
{
  public:
    virtual ~NiRefObjectF42();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerF42
{
  public:
    NiPointerF42(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerF42()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    NiPointerF42& operator=(const NiPointerF42& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    bool operator==(const NiPointerF42& ptr) const
    {
        return m_pObject == ptr.m_pObject;
    }

    T* m_pObject;
};
template <class T> class NiTArrayF42
{
  public:
    virtual ~NiTArrayF42();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element);

    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int AddFirstEmpty(const T& element);
};
struct FNVSampler
{
    void __thiscall SetNodeValue(int attribute, int mode, int enabled);
};
struct FNVFace
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

    void __thiscall FUN_00e7ecd0();
    void DecRef()
    {
        if (--unk060 == 0)
            FUN_00e7ecd0();
    }
};
struct FNVCubeSurface
{

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0c;

    unsigned int unk10;

    void* m_currentFace;

    unsigned int m_faceCount;

    unsigned int unk1c;

    unsigned int unk20;

    unsigned int unk24;

    unsigned int unk28;

    unsigned int unk2c;

    FNVSampler* m_sampler;

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;

    RefObject* m_colorTarget;

    unsigned int unk48;

    unsigned int unk4c;

    unsigned int unk50;

    unsigned int unk54;

    unsigned int unk58;

    RefObject* m_depthTarget;

    unsigned int unk60;

    unsigned int m_iObjectReferenceCount;

    unsigned int GetNumberOfFaces() const
    {
        return m_faceCount;
    }
    void __thiscall FUN_00e80190();

    void __thiscall FUN_00e802b0(void* currentFace, FNVFace* replacement);
};
extern unsigned int DAT_011fd1f0, DAT_011fd208, DAT_011fd220, DAT_011fd238, DAT_011fd250;
extern unsigned int DAT_011fc610, DAT_011fc628, DAT_011fc638, DAT_011fc640, DAT_011fc650, DAT_011fc658, DAT_011fc668,
    DAT_011fc670;
extern void __cdecl AssignStageFromPool(FNVFace** destination);
extern void __cdecl ConfigureBeamStage(FNVFace* target, int face, int enabled, int channel, int layer);
struct FNVFaceRef
{

    FNVFace* face;

    FNVFaceRef() : face(0)
    {}

    ~FNVFaceRef()
    {

        if (face)
            face->DecRef();
    }
};
struct FNVCubeRef
{

    FNVCubeSurface* surface;

    FNVCubeRef() : surface(0)
    {}

    ~FNVCubeRef()
    {
        if (surface && --surface->m_iObjectReferenceCount == 0)
            surface->FUN_00e80190();
    }

    void operator=(FNVCubeSurface* const& next)
    {

        if (surface == next)
            return;

        if (surface && --surface->m_iObjectReferenceCount == 0)
            surface->FUN_00e80190();

        surface = next;

        if (surface)
            ++surface->m_iObjectReferenceCount;
    }
};
static __forceinline void AssignTarget(RefObject*& dst, RefObject* src)
{
    RefObject* old = dst;
    if (old != src)
    {
        if (old && InterlockedDecrement((volatile long*)&old->m_iObjectReferenceCount) == 0)
            old->DeleteThis();
        dst = src;
        if (src)
            InterlockedIncrement((volatile long*)&src->m_iObjectReferenceCount);
    }
}
struct Point374
{
    float x, y, z;
    Point374& operator*=(float factor)
    {
        x = factor * x;
        y = factor * y;
        z = factor * z;
        return *this;
    }
};
struct Color374
{
    float r, g, b, a;
    Color374(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
extern "C" void __cdecl FUN_00b4f510();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
struct ConstantEntryStandin
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned flags;
};
class RefObjectStandin
{
  public:
    virtual ~RefObjectStandin();
    virtual void DeleteThis();
    long m_uiRefCount;
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
class NiD3DShaderConstantMap : public RefObjectStandin
{
  public:
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80(ConstantEntryStandin*);
    virtual void v84(ConstantEntryStandin*);
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
    static void* operator new(unsigned);
    static void operator delete(void*);
    NiD3DShaderConstantMap(void*, int);
};
template <class T> class PointerStandin
{
  public:
    T* m_pObject;
    PointerStandin<T>& operator=(T* object)
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
struct State
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
    PointerStandin<NiD3DShaderConstantMap> pixel;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    PointerStandin<NiD3DShaderConstantMap> vertex;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int refs;
    void DestroyState();
};
struct StatePtr
{
    State* p;
    StatePtr() : p(0)
    {}
    ~StatePtr()
    {
        if (p && --p->refs == 0)
            p->DestroyState();
    }
    StatePtr& operator=(const StatePtr& other)
    {
        if (p != other.p)
        {
            if (p && --p->refs == 0)
                p->DestroyState();
            p = other.p;
            if (p)
                ++p->refs;
        }
        return *this;
    }
};
extern StatePtr DAT_01200ec0[112];
struct P440Light;
struct P440Pass;
struct P440Camera;
struct P440Renderer;
struct P440Material;
struct P440Geometry;
struct P440List;
struct P440Extra;
struct P440LightFlags;
struct P440Position
{
    float x, y, z, r;
};
struct P440Vector
{
    float x, y, z;
    float FUN_00457990();
};
struct P440LightFlags
{
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
    unsigned int flags;
};
struct P440Light
{
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
    float alpha;
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
    bool special;
    char unked;
    short unkee;
    unsigned int unkf0;
    unsigned int unkf4;
    P440LightFlags* settings;
};
struct P440Pass
{
    unsigned int unk00;
    unsigned short shader;
    unsigned char blend;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char count;
    unsigned char capacity;
    unsigned char unk0b;
    P440Light** lights;
    void FUN_00ba8c30();
    void AllocateElemArray(unsigned char);
};
struct P440List
{
    unsigned int unk00;
    P440Pass** passes;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int count;
    void FUN_00ba9ee0(P440Geometry*, unsigned int, bool, unsigned char, P440Light*, P440Light*, P440Light*, P440Light*);
};
struct P440Material
{
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
    int skinned;
};
struct P440PropertyState
{
    P440LightFlags* flags;
    unsigned int unk04;
    P440Light* fade;
};
struct P440Geometry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    P440Position* position;
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
    P440PropertyState properties;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    P440Material* material;
    unsigned int unkbc;
};
struct P440Camera
{
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
    P440Light* defaultLight;
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
    float scale;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned char mode;
    char unk121;
    short unk122;
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
    P440Light* depthLight;
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
    P440Vector position;
    P440Vector GetPosition() const
    {
        return position;
    }
    const P440Vector& GetPositionRef() const
    {
        return position;
    }
};
struct P440Renderer
{
    unsigned int unk00;
    unsigned int unk04;
    P440Camera* active;
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
    int mode;
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
    float scale;
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
    P440Camera* camera;
    const P440Vector& GetCameraPosition() const
    {
        return camera->position;
    }
};
struct P440Extra
{
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
    int enabled;
};
struct P440Shader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags;
    unsigned int flags2;
    float alpha;
    float opacity;
    unsigned int unk30;
    float distance;
    unsigned int cacheKey;
    P440List* passes;
    P440List* depthPasses;
    P440List* normalPasses;
    P440List* shadowPasses;
    unsigned int unk4c;
    unsigned int unk50;
    P440List* specialPasses;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    bool dirty;
    char unk75;
    short unk76;
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
    int* materialFlags;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    P440Extra* extra;
    __declspec(noinline) bool FUN_004a2020(int index)
    {
        unsigned int word = (unsigned int)index >> 5;
        unsigned int bit = (unsigned int)index % 32;
        return ((word == 0 ? flags : flags2) & (1u << bit)) > 0;
    }
    void FUN_00441130(int, bool);
    void EnsureNewObj(int);
    void EnsureBa9740Obj(int);
    void EnsureAllocated(int);
    void CreateSpawnedObjectIfMissing(int);
    void FUN_00ba95e0(int);
    void FUN_00ba8ab0(float);
    void SortShadowSceneLights(P440Position*);
    P440Light* FUN_00b70590(void**);
    P440Light* FUN_00b70680(void**);
    P440Light* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void**);
    P440Light* FUN_00b70700(void**);
    P440List* GetPasses(P440Geometry*, unsigned int, int, unsigned int, P440Renderer*, int);
};
extern float DAT_011f9458, DAT_011f9460, DAT_011f9468, DAT_011f946c;
extern unsigned int DAT_011a9bd0;
extern unsigned int DAT_011a9bd4;
extern unsigned int DAT_011a9bd8;
extern unsigned int DAT_011a9bdc;
extern unsigned int DAT_011fa2d0;
extern unsigned int DAT_011fa2d4;
extern unsigned int DAT_011fa2d8;
extern unsigned int DAT_011fa2dc;
struct S00c03c80_entry;
struct S00c03c80_item
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual int Get94();
    virtual int Get98();
};
struct S00c03c80_entry
{
    S00c03c80_item* __thiscall FUN_00ba3780();
};
struct S00c04f50_P3
{
    float x;
    float y;
    float z;

    S00c04f50_P3& operator=(const S00c04f50_P3& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        return *this;
    }
};
template <class T> inline T S00c04f50_Max(T a, T b)
{
    return (a > b) ? a : b;
}
struct ZeroFour
{
    float m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    __forceinline ZeroFour() : m_kPointA(0.0f), m_kPointB(0.0f), m_iThirdValue(0.0f), m_iFourthElementInteger(0.0f)
    {}
};
namespace ShaderSelection {
extern void* DAT_01200ec0;
}
extern ClusterObj* DAT_01202230;
extern "C" void __cdecl FUN_00e804d0(void* pSlot);
namespace ShaderBias {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    int references;
    void FUN_00e7ecd0();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            FUN_00e7ecd0();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void FUN_00e802b0(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* const& GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern RefObject *DAT_011fdfcc, *DAT_011fdc70;
extern unsigned int DAT_011fd7e0, DAT_011fcc00;
extern RefObject *DAT_011fdfd0, *DAT_011fdc70;
extern unsigned int DAT_011fd7e4, DAT_011fcc04;
extern RefObject *DAT_011fdfd4, *DAT_011fdc74;
extern unsigned int DAT_011fd7f8, DAT_011fcc18;
extern RefObject *DAT_011fdfd8, *DAT_011fdc74;
extern unsigned int DAT_011fd7fc, DAT_011fcc1c;
extern RefObject *DAT_011fdfdc, *DAT_011fdc70;
extern unsigned int DAT_011fd810, DAT_011fcc30;
extern RefObject *DAT_011fdfe0, *DAT_011fdc70;
extern unsigned int DAT_011fd814, DAT_011fcc34;
extern RefObject *DAT_011fdfe4, *DAT_011fdc74;
extern unsigned int DAT_011fd828, DAT_011fcc48;
extern RefObject *DAT_011fdfe8, *DAT_011fdc74;
extern unsigned int DAT_011fd82c, DAT_011fcc4c;
}
struct __declspec(novtable) ISBaseA
{
    virtual ~ISBaseA();
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
    void FUN_00be2200();
    void FUN_00be0870();
    ISBaseA()
    {
        FUN_00be2200();
    }
};
struct __declspec(novtable) ISBaseB
{
    virtual ~ISBaseB();
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
    void FUN_00ba4080();
    ISBaseB()
    {
        FUN_00ba4080();
    }
};
struct ISRefObj
{
    int unk00;
};
struct ISPtr
{
    ISRefObj* m_p;
    ISPtr() : m_p(0)
    {}
    ~ISPtr();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObjectC1D
{
  public:
    virtual ~NiRefObjectC1D();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerC1D
{
  public:
    NiPointerC1D(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC1D()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerC1D& operator=(const NiPointerC1D& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(const NiPointerC1D& ptr) const
    {
        return m_pObject == ptr.m_pObject;
    }
    bool operator!=(const NiPointerC1D& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }

    T* m_pObject;
};
template <class T> class NiTObjectArrayC1D
{
  public:
    virtual ~NiTObjectArrayC1D();
    void Set(unsigned int uiIndex, const T& element);

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class NiAVObjectC1D : public NiRefObjectC1D
{
};
template class NiTObjectArrayC1D<NiPointerC1D<NiAVObjectC1D> >;
struct RefPass04120 : NiD3DPass
{
    void DecRefCount()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};
struct Pass04120
{
    RefPass04120* m_pObject;
    Pass04120() : m_pObject(0)
    {}
    ~Pass04120()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
struct Shader04120
{
    int unk00, unk04, unk08, unk0c, unk10;
    void* m_kTextureStages;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    ElemObj* m_uiContentCount;
    int unk34, unk38, unk3c, unk40;
    NiRefObject* m_property;
    int unk48, unk4c, unk50, unk54, unk58;
    NiRefObject* m_texture;

    void FUN_00e802b0(void*, NiD3DPass*);
    void SetRenderState(int a, int b, int c)
    {
        if (!m_uiContentCount)
            m_uiContentCount = FUN_00e7f5d0();
        m_uiContentCount->SetNodeValue(a, b, c);
    }
    void SetTexture(NiRefObject* p)
    {
        if (m_texture != p)
        {
            if (m_texture)
                m_texture->DecRefCount();
            m_texture = p;
            if (m_texture)
                m_texture->IncRefCount();
        }
    }
    void SetProperty(NiRefObject* p)
    {
        if (m_property != p)
        {
            if (m_property)
                m_property->DecRefCount();
            m_property = p;
            if (m_property)
                m_property->IncRefCount();
        }
    }
};
void __cdecl FUN_00e804d0(void*);
void __cdecl AssignStageFromPool(Pass04120*);
void __cdecl ConfigureBeamStage(NiD3DPass*, unsigned int, int, int, int);

extern int DAT_011fab34;
extern int DAT_011fab5c;
extern int DAT_011fab60;
extern int DAT_011fab88;
extern int DAT_011fab8c;
extern int DAT_011fabb4;
extern int DAT_011fabb8;
extern int DAT_011fabe0;
extern int DAT_011fac3c;
extern int DAT_011fac5c;
extern int DAT_011fac60;
extern int DAT_011fac80;
extern int DAT_011fac84;
extern int DAT_011faca4;
extern int DAT_011faca8;
extern int DAT_011facc8;
extern int DAT_011faccc;
extern int DAT_011fad00;
extern int DAT_011fad08;
extern int DAT_011fad30;
extern int DAT_011fad38;
extern int DAT_011fad5c;
extern int DAT_011fad64;
extern int DAT_011fad88;
extern int DAT_011fada8;
extern int DAT_011fadbc;
extern int DAT_011fadd8;
extern int DAT_011fadec;
extern int DAT_011fae48;
extern int DAT_011fae5c;
extern int DAT_011fae60;
extern int DAT_011fae74;
extern int DAT_011fb1a4;
extern int DAT_011fb1b0;
extern int DAT_011fb714;
extern int DAT_011fb73c;
extern int DAT_011fb740;
extern int DAT_011fb768;
extern int DAT_011fb76c;
extern int DAT_011fb794;
extern int DAT_011fb798;
extern int DAT_011fb7c0;
extern int DAT_011fb81c;
extern int DAT_011fb83c;
extern int DAT_011fb840;
extern int DAT_011fb860;
extern int DAT_011fb864;
extern int DAT_011fb884;
extern int DAT_011fb888;
extern int DAT_011fb8a8;
extern int DAT_011fb8ac;
extern int DAT_011fb8e0;
extern int DAT_011fb8e8;
extern int DAT_011fb910;
extern int DAT_011fb918;
extern int DAT_011fb93c;
extern int DAT_011fb944;
extern int DAT_011fb968;
extern int DAT_011fb988;
extern int DAT_011fb99c;
extern int DAT_011fb9b8;
extern int DAT_011fb9cc;
extern int DAT_011fba28;
extern int DAT_011fba3c;
extern int DAT_011fba40;
extern int DAT_011fba54;
extern int DAT_011fbd84;
extern int DAT_011fbd90;
extern int DAT_011fc2f4;
extern int DAT_011fc31c;
extern int DAT_011fc320;
extern int DAT_011fc348;
extern int DAT_011fc34c;
extern int DAT_011fc374;
extern int DAT_011fc378;
extern int DAT_011fc3a0;
extern int DAT_011fc3fc;
extern int DAT_011fc41c;
extern int DAT_011fc420;
extern int DAT_011fc440;
extern int DAT_011fc444;
extern int DAT_011fc464;
extern int DAT_011fc468;
extern int DAT_011fc488;
extern int DAT_011fc48c;
extern int DAT_011fc4c0;
extern int DAT_011fc4c8;
extern int DAT_011fc4f0;
extern int DAT_011fc4f8;
extern int DAT_011fc51c;
extern int DAT_011fc524;
extern int DAT_011fc548;
extern int DAT_011fc568;
extern int DAT_011fc57c;
extern int DAT_011fc598;
extern int DAT_011fc5ac;
extern int DAT_011fc608;
extern int DAT_011fc61c;
extern int DAT_011fc620;
extern int DAT_011fc634;
extern int DAT_011fc64c;
extern int DAT_011fc664;
extern int DAT_011fc67c;
extern int DAT_011fc964;
extern int DAT_011fc970;
extern int DAT_011fced4;
extern int DAT_011fcefc;
extern int DAT_011fcf00;
extern int DAT_011fcf28;
extern int DAT_011fcf2c;
extern int DAT_011fcf54;
extern int DAT_011fcf58;
extern int DAT_011fcf80;
extern int DAT_011fcfdc;
extern int DAT_011fcffc;
extern int DAT_011fd000;
extern int DAT_011fd020;
extern int DAT_011fd024;
extern int DAT_011fd044;
extern int DAT_011fd048;
extern int DAT_011fd068;
extern int DAT_011fd06c;
extern int DAT_011fd0a0;
extern int DAT_011fd0a8;
extern int DAT_011fd0d0;
extern int DAT_011fd0d8;
extern int DAT_011fd0fc;
extern int DAT_011fd104;
extern int DAT_011fd128;
extern int DAT_011fd148;
extern int DAT_011fd15c;
extern int DAT_011fd178;
extern int DAT_011fd18c;
extern int DAT_011fd1e8;
extern int DAT_011fd1fc;
extern int DAT_011fd200;
extern int DAT_011fd214;
extern int DAT_011fd218;
extern int DAT_011fd22c;
extern int DAT_011fd230;
extern int DAT_011fd244;
extern int DAT_011fd248;
extern int DAT_011fd25c;
extern int DAT_011fd544;
extern int DAT_011fd550;
extern RefTex* DAT_011fdb08;
extern RefTex* DAT_011fdb1c;
extern RefTex* DAT_011fdb34;
extern RefTex* DAT_011fdb40;
extern RefTex* DAT_011fdb4c;
extern RefTex* DAT_011fdb58;
extern RefTex* DAT_011fdb64;
extern RefTex* DAT_011fdb70;
extern RefTex* DAT_011fdb9c;
extern RefTex* DAT_011fdba4;
extern RefTex* DAT_011fdbac;
extern RefTex* DAT_011fdbb4;
extern ShaderPassPtr DAT_01202378;
extern ShaderPassPtr DAT_0120237c;
extern ShaderPassPtr DAT_01202380;
extern ShaderPassPtr DAT_01202384;
extern ShaderPassPtr DAT_01202388;
extern ShaderPassPtr DAT_0120238c;
extern ShaderPassPtr DAT_01202390;
extern ShaderPassPtr DAT_01202394;
extern ShaderPassPtr DAT_01202398;
extern ShaderPassPtr DAT_0120239c;
extern ShaderPassPtr DAT_012023a0;
extern ShaderPassPtr DAT_012023a4;
extern ShaderPassPtr DAT_012023a8;
extern ShaderPassPtr DAT_012023ac;
extern ShaderPassPtr DAT_012023b0;
extern ShaderPassPtr DAT_012023b4;
extern ShaderPassPtr DAT_012023b8;
extern ShaderPassPtr DAT_012023bc;
extern ShaderPassPtr DAT_012023c0;
extern ShaderPassPtr DAT_012023c4;
struct ShaderHandle
{
    RefTex* value;
};
struct PassMethods : ShaderPass
{
    void SetPixelShader(ShaderHandle);
    void SetVertexShader(RefTex*);
    void SetBlend(int source, int destination, bool save);
};
struct LocalPassPtr
{
    ShaderPass* m_p;
    LocalPassPtr()
    {
        *reinterpret_cast<ShaderPass* volatile*>(&m_p) = 0;
        m_p = 0;
    }
    void operator=(const ShaderPassPtr& sp)
    {
        if (m_p != sp.m_p)
        {
            if (m_p)
            {
                if (--m_p->m_iObjectReferenceCount == 0)
                    m_p->Destroy();
            }
            m_p = sp.m_p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }
    ~LocalPassPtr()
    {
        if (m_p && --m_p->m_iObjectReferenceCount == 0)
            m_p->Destroy();
    }
    ShaderPass* operator->() const
    {
        return m_p;
    }
    operator ShaderPassPtr&()
    {
        return reinterpret_cast<ShaderPassPtr&>(*this);
    }
};
struct C17510Shader
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
    RefTex* m_b4;
    RefTex* m_b8;
    RefTex* m_bc;
    RefTex* m_c0;
    RefTex* m_c4;
    RefTex* m_c8;
    RefTex* m_cc;
    RefTex* m_d0;
    RefTex* m_d4;
    RefTex* m_d8;
    RefTex* m_dc;
    RefTex* m_e0;
    RefTex* m_e4;
    RefTex* m_e8;
    RefTex* m_ec;
    RefTex* m_f0;
    RefTex* m_f4;
    RefTex* m_f8;
    RefTex* m_fc;
    RefTex* m_100;
    void FUN_00c17510();
};

// @fnv 0x00c17510
// pdb: SpeedTreeBranchShader::PresetPasses_2x | SpeedTreeBranchShader_Preset.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void C17510Shader::FUN_00c17510()
{
    LocalPassPtr spRenderPass;
    TexStagePtr spStage;

    // Shader pass 0.
    spRenderPass = DAT_01202378;
    unsigned int count0 = spRenderPass->m_18;
    if (count0 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_b4);
    AssignTex(spRenderPass->m_44, DAT_011fdb9c);
    SetupRenderStates(spRenderPass);
    DAT_011fcffc = DAT_011fcfdc;
    DAT_011fc41c = DAT_011fc3fc;
    DAT_011fb83c = DAT_011fb81c;
    DAT_011fac5c = DAT_011fac3c;

    // Shader pass 1.
    spRenderPass = DAT_0120237c;
    if (spRenderPass->m_18 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_b8);
    AssignTex(spRenderPass->m_44, DAT_011fdba4);
    SetupRenderStates(spRenderPass);
    DAT_011fd020 = DAT_011fd000;
    DAT_011fc440 = DAT_011fc420;
    DAT_011fb860 = DAT_011fb840;
    DAT_011fac80 = DAT_011fac60;

    // Shader pass 2.
    spRenderPass = DAT_01202380;
    if (spRenderPass->m_18 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_bc);
    AssignTex(spRenderPass->m_44, DAT_011fdbac);
    SetupRenderStates(spRenderPass);
    DAT_011fd044 = DAT_011fd024;
    DAT_011fc464 = DAT_011fc444;
    DAT_011fb884 = DAT_011fb864;
    DAT_011faca4 = DAT_011fac84;

    // Shader pass 3.
    spRenderPass = DAT_01202384;
    if (spRenderPass->m_18 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_c0);
    AssignTex(spRenderPass->m_44, DAT_011fdbb4);
    SetupRenderStates(spRenderPass);
    DAT_011fd068 = DAT_011fd048;
    DAT_011fc488 = DAT_011fc468;
    DAT_011fb8a8 = DAT_011fb888;
    DAT_011facc8 = DAT_011faca8;

    // Shader pass 4.
    spRenderPass = DAT_01202388;
    unsigned int count4 = spRenderPass->m_18;
    if (count4 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_c4);
    AssignTex(spRenderPass->m_44, DAT_011fdb08);
    SetupRenderStates(spRenderPass);
    DAT_011fd0a0 = DAT_011fd06c;
    DAT_011fc4c0 = DAT_011fc48c;
    DAT_011fb8e0 = DAT_011fb8ac;
    DAT_011fad00 = DAT_011faccc;

    // Shader pass 5.
    spRenderPass = DAT_0120238c;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_c8);
    AssignTex(spRenderPass->m_44, DAT_011fdb1c);
    SetupRenderStates(spRenderPass);
    DAT_011fd0d0 = DAT_011fd0a8;
    DAT_011fc4f0 = DAT_011fc4c8;
    DAT_011fb910 = DAT_011fb8e8;
    DAT_011fad30 = DAT_011fad08;

    // Shader pass 6.
    spRenderPass = DAT_01202390;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_cc);
    AssignTex(spRenderPass->m_44, DAT_011fdb34);
    SetupRenderStates(spRenderPass);
    DAT_011fd0fc = DAT_011fd0d8;
    DAT_011fc51c = DAT_011fc4f8;
    DAT_011fb93c = DAT_011fb918;
    DAT_011fad5c = DAT_011fad38;

    // Shader pass 7.
    spRenderPass = DAT_01202394;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_d0);
    AssignTex(spRenderPass->m_44, DAT_011fdb40);
    SetupRenderStates(spRenderPass);
    DAT_011fd128 = DAT_011fd104;
    DAT_011fc548 = DAT_011fc524;
    DAT_011fb968 = DAT_011fb944;
    DAT_011fad88 = DAT_011fad64;

    // Shader pass 8.
    spRenderPass = DAT_01202398;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_d4);
    AssignTex(spRenderPass->m_44, DAT_011fdb4c);
    SetupRenderStates(spRenderPass);
    DAT_011fcefc = DAT_011fced4;
    DAT_011fc31c = DAT_011fc2f4;
    DAT_011fb73c = DAT_011fb714;
    DAT_011fab5c = DAT_011fab34;

    // Shader pass 9.
    spRenderPass = DAT_0120239c;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_d8);
    AssignTex(spRenderPass->m_44, DAT_011fdb58);
    SetupRenderStates(spRenderPass);
    DAT_011fcf28 = DAT_011fcf00;
    DAT_011fc348 = DAT_011fc320;
    DAT_011fb768 = DAT_011fb740;
    DAT_011fab88 = DAT_011fab60;

    // Shader pass 10.
    spRenderPass = DAT_012023a0;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_dc);
    AssignTex(spRenderPass->m_44, DAT_011fdb64);
    SetupRenderStates(spRenderPass);
    DAT_011fcf54 = DAT_011fcf2c;
    DAT_011fc374 = DAT_011fc34c;
    DAT_011fb794 = DAT_011fb76c;
    DAT_011fabb4 = DAT_011fab8c;

    // Shader pass 11.
    spRenderPass = DAT_012023a4;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_e0);
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(DAT_011fdb70);
    SetupRenderStates(spRenderPass);
    DAT_011fcf80 = DAT_011fcf58;
    DAT_011fc3a0 = DAT_011fc378;
    DAT_011fb7c0 = DAT_011fb798;
    DAT_011fabe0 = DAT_011fabb8;

    // Shader pass 12.
    spRenderPass = DAT_012023a8;
    if (spRenderPass->m_18 < 4)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_e4};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(93)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd15c = DAT_011fd148;
    DAT_011fc57c = DAT_011fc568;
    DAT_011fb99c = DAT_011fb988;
    DAT_011fadbc = DAT_011fada8;

    // Shader pass 13.
    spRenderPass = DAT_012023ac;
    if (spRenderPass->m_18 < 4)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_e8};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(94)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd18c = DAT_011fd178;
    DAT_011fc5ac = DAT_011fc598;
    DAT_011fb9cc = DAT_011fb9b8;
    DAT_011fadec = DAT_011fadd8;

    // Shader pass 14.
    spRenderPass = DAT_012023b0;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_ec};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(95)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd1fc = DAT_011fd1e8;
    DAT_011fc61c = DAT_011fc608;
    DAT_011fba3c = DAT_011fba28;
    DAT_011fae5c = DAT_011fae48;

    // Shader pass 15.
    spRenderPass = DAT_012023b4;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_f0};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(97)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd214 = DAT_011fd200;
    DAT_011fc634 = DAT_011fc620;
    DAT_011fba54 = DAT_011fba40;
    DAT_011fae74 = DAT_011fae60;

    // Shader pass 16.
    spRenderPass = DAT_012023b8;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_f4};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(99)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd22c = DAT_011fd218;
    DAT_011fc64c = DAT_011fc638;

    // Shader pass 17.
    spRenderPass = DAT_012023bc;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_f8};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(101)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd244 = DAT_011fd230;
    DAT_011fc664 = DAT_011fc650;

    // Shader pass 18.
    spRenderPass = DAT_012023c0;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_fc};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(103)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd25c = DAT_011fd248;
    DAT_011fc67c = DAT_011fc668;

    // Shader pass 19.
    spRenderPass = DAT_012023c4;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 0, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_100};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(FUN_00c163a0(200)));
    spRenderPass->GetRSG()->SetRenderState(0x1b, 1, true);
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(9, 1, false);
    spRenderPass->GetRSG()->SetRenderState(15, 0, true);
    spRenderPass->GetRSG()->SetRenderState(7, 1, true);
    spRenderPass->GetRSG()->SetRenderState(23, 4, true);
    spRenderPass->GetRSG()->SetRenderState(14, 0, true);
    DAT_011fd550 = DAT_011fd544;
    DAT_011fc970 = DAT_011fc964;
    DAT_011fbd90 = DAT_011fbd84;
    DAT_011fb1b0 = DAT_011fb1a4;
}
