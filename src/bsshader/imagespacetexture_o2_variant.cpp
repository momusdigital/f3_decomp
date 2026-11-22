#include "f3_common.h"
// src/bsshader/imagespacetexture_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/imagespacetexture.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "imagespacetexture_decls.h"

struct FUN_00ba3770_struct
{
    int __thiscall FUN_00ba3770();
};

// @fnv 0x00ba3770
// pdb: ImageSpaceTexture::GetRenderedTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_gap, medium
int __thiscall FUN_00ba3770_struct::FUN_00ba3770()
{
    if (reinterpret_cast<char*>(this)[1])
        return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4);
    return 0;
}

struct Tex00ba37f0
{
    virtual void F0();
    virtual void F1();
    long m_Ref;
    void IncRefCount()
    {
        InterlockedIncrement(&m_Ref);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_Ref) == 0)
            F1();
    }
};
struct Holder00ba37f0
{
    bool b0;
    bool b1;
    Tex00ba37f0* pTileTexture;
    void __thiscall FUN_00ba37f0(Tex00ba37f0* apTex);
};
// @fnv 0x00ba37f0
// pdb: ImageSpaceTexture::SetTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apTex
void __thiscall Holder00ba37f0::FUN_00ba37f0(Tex00ba37f0* apTex)
{
    if (pTileTexture != apTex)
    {
        if (pTileTexture)
            pTileTexture->DecRefCount();
        pTileTexture = apTex;
        if (apTex)
            apTex->IncRefCount();
    }
    b1 = 0;
}

struct BeamStage
{
    char _0[8];
    void* m_8;
    void ApplyPairToState(unsigned int);
    void FUN_00e7def0(unsigned int);
};
struct TextureReceiver
{
    TextureReceiver* FUN_004bc320(int);
};
struct UnkBA38F0
{
    unsigned char m_iWordAt00;
    bool m_cByteAtOffset1;
    unsigned char m_auiShapeKeys[2];
    UnkBA38F0* volatile m_iWordAt04;
    unsigned int m_8;
    unsigned int m_C;
    void FUN_00ba38f0(BeamStage*);
};
// @fnv 0x00ba38f0
void UnkBA38F0::FUN_00ba38f0(BeamStage* pkStage)
{
    UnkBA38F0* pThis = this;
    pkStage->ApplyPairToState(pThis->m_C);
    pkStage->FUN_00e7def0(pThis->m_8);
    if (pThis->m_cByteAtOffset1)
    {
        pkStage->m_8 = ((TextureReceiver*)pThis->m_iWordAt04)->FUN_004bc320(0);
    }
    else
    {
        pThis = pThis->m_iWordAt04;
        pkStage->m_8 = pThis;
    }
}

struct R_00ba39a0
{
    virtual void f0();
    virtual void f1();
    long m_rc;
};
struct H_00ba39a0
{
    bool b0;
    bool b1;
    bool b2;
    R_00ba39a0* p;
    int i1;
    int i2;
    void FUN_00ba39a0();
};
// @fnv 0x00ba39a0
// pdb: ImageSpaceTexture::ReturnRenderedTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_seq, medium
void H_00ba39a0::FUN_00ba39a0()
{
    if (!b2)
        return;
    b2 = false;
    DAT_011f91a8->AddRenderedTexture(b1 ? (BSRenderedTexture*)p : 0);
    R_00ba39a0* tex = p;
    if (tex)
    {
        if (InterlockedDecrement(&tex->m_rc) == 0)
            tex->f1();
        p = 0;
    }
    b1 = false;
    i1 = 0;
    i2 = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
struct RefBase
{
    virtual void vf0();
    virtual void vf1();
    long m_iObjectReferenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            vf1();
    }
};
struct OwnerStandIn
{
    unsigned char unk0;
    unsigned char flag;
    unsigned char pad[2];
    RefBase* ptr;
    void FUN_00ba37a0(RefBase* p);
};
// @fnv 0x00ba37a0
// pdb: ImageSpaceTexture::SetTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRendTex
void OwnerStandIn::FUN_00ba37a0(RefBase* p)
{
    if (ptr != p)
    {
        if (ptr)
            ptr->DecRefCount();
        ptr = p;
        if (ptr)
            ptr->IncRefCount();
    }
    flag = 1;
}

struct RefObj
{
    virtual void F0();
    virtual void F1();
    long m_ref;
};

struct Holder
{
    char _0;
    unsigned char _1;
    char _pad[2];
    RefObj* _4;
    int _8;
    int _c;
    void __thiscall FUN_00ba38b0();
};

// @fnv 0x00ba38b0
// pdb: ImageSpaceTexture::ClearTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_seq, medium
void __thiscall Holder::FUN_00ba38b0()
{
    RefObj* tmp = _4;
    if (tmp)
    {
        if (InterlockedDecrement(&tmp->m_ref) == 0)
            tmp->F1();
        _4 = 0;
    }
    _1 = 0;
    _8 = 0;
    _c = 0;
}

struct NiRenderer;

extern NiRenderer* DAT_011f9508;

struct TexMgr00ba3840
{
    Tex00ba37f0* CreateRenderTargetTexture(NiRenderer*, int, unsigned int, void*, unsigned int);
};

struct H_00ba3840
{
    char _0;
    bool b1;
    bool b2;
    char _pad;
    Tex00ba37f0* pTileTexture;
    void FUN_00ba3840(int arg);
};

// @fnv 0x00ba3840
// pdb: ImageSpaceTexture::BorrowRenderedTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: ImageSpaceEffect::SetTexture)
// pdb params: aeType
void H_00ba3840::FUN_00ba3840(int arg)
{
    Tex00ba37f0* pNew = ((TexMgr00ba3840*)DAT_011f91a8)->CreateRenderTargetTexture(DAT_011f9508, arg, 0, 0, 0);
    if (pTileTexture != pNew)
    {
        if (pTileTexture)
            pTileTexture->DecRefCount();
        pTileTexture = pNew;
        if (pTileTexture)
            pTileTexture->IncRefCount();
    }
    b1 = true;
    b2 = true;
}

struct FUN_00ba2590_struct
{
    void FUN_00ba2590();
};
struct ISTex
{
    void* GetTexture();
    void CreateRenderTargetTexture(unsigned int);
};
struct FUN_00ba26f0_struct
{
    char _0[0x58];
    ISTex a;
    char _70[0x8];
    ISTex b;
    char _88[0x8];
    ISTex c;
    char _a0[0x8];
    ISTex d;
    void FUN_00ba26f0();
};
// @fnv 0x00ba26f0
// pdb: ImageSpaceEffectWaterFFT::InitializeUtilityBuffers | ImageSpaceEffectWaterFFT.obj | fnv360_0822_retail, call_dedup, low
void FUN_00ba26f0_struct::FUN_00ba26f0()
{
    if (!((ISTex*)((char*)this + 0x88))->GetTexture())
        ((ISTex*)((char*)this + 0x88))->CreateRenderTargetTexture(0xd);
    if (!((ISTex*)((char*)this + 0x78))->GetTexture())
        ((ISTex*)((char*)this + 0x78))->CreateRenderTargetTexture(0xe);
    if (!((ISTex*)((char*)this + 0x58))->GetTexture())
        ((ISTex*)((char*)this + 0x58))->CreateRenderTargetTexture(0xf);
    if (!((ISTex*)((char*)this + 0x68))->GetTexture())
        ((ISTex*)((char*)this + 0x68))->CreateRenderTargetTexture(0x10);
    ((FUN_00ba2590_struct*)this)->FUN_00ba2590();
}

struct FUN_00ba3780_struct
{
    unsigned char unk0;
    bool flag;
    unsigned char pad[2];
    TextureReceiver* ptr;
    TextureReceiver* FUN_00ba3780();
};

// @fnv 0x00ba3780
// pdb: ImageSpaceTexture::GetTexture | ImageSpaceTexture.obj | fnv360_0822_retail, call_seq, medium
TextureReceiver* FUN_00ba3780_struct::FUN_00ba3780()
{
    if (flag)
        return ptr->FUN_004bc320(0);
    return ptr;
}

class BA3760Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;

    void FUN_00ba3760(int iValue);
};

// @fnv 0x00ba3760
// pdb: NonActorMagicCaster::SetCurrentSpell | NonActorMagicCaster.obj | fnv360_0822_retail, vtable, medium
// pdb params: apCurrentSpell
void BA3760Object::FUN_00ba3760(int iValue)
{
    m_iValue = iValue;
}

struct RefObj3940
{
    virtual void vf0();
    virtual void vf1();
    long m_ref;
    void AcquireReference()
    {
        InterlockedIncrement(&m_ref);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            vf1();
    }
};

struct FUN_00ba3940_cls
{
    unsigned char unk00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char unk03;
    RefObj3940* m_04;
    unsigned int m_08;
    FUN_00ba3940_cls* FUN_00ba3940(FUN_00ba3940_cls* src);
};

// @fnv 0x00ba3940
// pdb: ImageSpaceTexture::operator= | ImageSpaceTexture.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aTex
FUN_00ba3940_cls* FUN_00ba3940_cls::FUN_00ba3940(FUN_00ba3940_cls* src)
{
    *(volatile unsigned char*)&m_01 = src->m_01;
    *(volatile unsigned char*)&m_02 = src->m_02;
    RefObj3940* old = *(RefObj3940* volatile*)&m_04;
    if (old != src->m_04)
    {
        if (old != 0)
        {
            old->DecRef();
        }
        m_04 = src->m_04;
        if (m_04 != 0)
        {
            m_04->AcquireReference();
        }
    }
    m_08 = src->m_08;
    src->m_02 = 0;
    return this;
}

extern __declspec(thread) unsigned int g_tlsAllocTag;

struct TLSTagGuard
{
    unsigned int uiOld;
    TLSTagGuard(unsigned int uiTag)
    {
        uiOld = g_tlsAllocTag;
        g_tlsAllocTag = uiTag;
    }
    ~TLSTagGuard()
    {
        g_tlsAllocTag = uiOld;
    }
};

struct ISTexture
{
    bool b0;
    bool b1;
    bool b2;
    void* pTileTexture;
    int i8;
    int iC;
    ISTexture() : b0(false), b1(false), b2(false), pTileTexture(0), i8(0), iC(0)
    {}
    ~ISTexture();
    void SetTexture(NiTexture* apTex);
    void SetRenderedTexture(BSRenderedTexture* apTex);
};

struct TexObj
{
    void FUN_00b8a790(int mode, float a, float b, float c, float d);
};
struct WorkObj
{
    virtual void V0();
    virtual void Vf1(int a, int b, TexObj* tex, int c);
    void SetAccumulatorAt(int idx, void* p, int z);
};
struct ElemHeader
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
};
struct ElemObj
{
    ElemHeader header;
    WorkObj work_6c;
};
struct StagePtrs
{
    WorkObj* p0;
    WorkObj* p1;
    WorkObj* p2;
    WorkObj* p3;
    WorkObj* p4;
    WorkObj* p5;
    WorkObj* p6;
};
struct TexPtrs
{
    TexObj* t0;
    TexObj* t1;
    TexObj* t2;
    TexObj* t3;
    TexObj* t4;
    TexObj* t5;
    TexObj* t6;
};
struct M2C
{
    void* p0;
    void* p1;
};
struct Sub10
{
    int f0;
    int f4;
    int f8;
    int fc;
};
struct HolderX
{
    bool b0;
    bool b1;
    bool b2;
    void* p;
    int i1;
    int i2;
    HolderX() : b0(0), b1(0), b2(0), p(0), i1(0), i2(0)
    {}
    ~HolderX();
    void FUN_00ba3840(int arg);
    void FUN_00ba3940(HolderX* other);
    void* FUN_00ba3780();
    void FUN_00ba39a0();
};
extern int DAT_01200050;
extern float DAT_0120004c;
extern unsigned char DAT_01200058;
extern float DAT_0101e570;

struct Owner
{
    virtual void W0();
    virtual void W1();
    virtual void W2();
    virtual void W3();
    virtual void W4();
    virtual void W5();
    virtual void W6();
    virtual bool W7(int arg);
    unsigned char f4;
    bool flag;
    unsigned char f6;
    unsigned char f7;
    int unk8;
    StagePtrs* m_iThirdValue;
    int unk10;
    int unk14;
    int unk18;
    TexPtrs* m_1c;
    int unk20;
    int unk24;
    int unk28;
    M2C* m_2c;
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
    Sub10 s58;
    Sub10 s68;
    Sub10 s78;
    Sub10 s88;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    float m_b0;
    float m_b4;
    bool m_b8;
    void FUN_00ba26f0();
    void FUN_00ba2760(int a1, int a2, int a3, int a4);
};

static __forceinline WorkObj* ToWork(WorkObj* p)
{
    ElemObj* e = p ? (ElemObj*)((ElemHeader*)p - 1) : 0;
    return e ? &e->work_6c : 0;
}

// @f3 0x00b0c180 (community match, verified in this file)
namespace f3m_00b0c180 { struct OwnerShim { void FUN_00b0c110(); }; }
static __forceinline WorkObj* WorkRef(WorkObj* const& p)


{


    ElemObj* e = p ? (ElemObj*)((ElemHeader*)p - 1) : 0;


    return e ? &e->work_6c : 0;


}


// pdb: ImageSpaceEffectWaterFFT::Render | ImageSpaceEffectWaterFFT.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apGeometry, apRenderer, apParam, abEndFrame
void Owner::FUN_00ba2760(int a1, int a2, int a3, int a4)





{





    if (!m_b8)





        reinterpret_cast<f3m_00b0c180::OwnerShim*>(this)->FUN_00b0c110();





    int count = DAT_01200050;





    int a2v = a2;





    int i;





    if (flag)





        flag = W7(a3);





    HolderX d;





    HolderX b;





    HolderX a;





    d.FUN_00ba3840(7);





    a.FUN_00ba3840(7);





    b.FUN_00ba3840(7);





    HolderX c;





    WorkObj* w = WorkRef(m_iThirdValue->p0);





    TexObj* tex = m_1c->t0;





    tex->FUN_00b8a790(0, m_b0, 0.0f, 0.0f, 0.0f);





    w->SetAccumulatorAt(0, &d, 0);





    w->SetAccumulatorAt(1, &s68, 0);





    w->SetAccumulatorAt(2, &s58, 0);





    w->Vf1(a1, a2v, tex, 1);





    w = WorkRef(m_iThirdValue->p3);





    tex = m_1c->t3;





    w->SetAccumulatorAt(0, &a, 0);





    w->SetAccumulatorAt(1, &s88, 0);





    w->SetAccumulatorAt(2, &d, 0);





    w->Vf1(a1, a2v, tex, 1);





    c.FUN_00ba3940(&b);





    b.FUN_00ba3940(&a);





    a.FUN_00ba3940(&c);





    w = WorkRef(m_iThirdValue->p1);





    tex = m_1c->t1;





    for (i = 0; i < count; i++)





    {





        m_b4 = (float)(i * 0.0625 + 0.03125);





        tex->FUN_00b8a790(1, m_b4, DAT_0101e570, 0.0f, 0.0f);





        w->SetAccumulatorAt(0, &a, 0);





        w->SetAccumulatorAt(1, &s78, 0);





        w->SetAccumulatorAt(2, &b, 0);





        w->Vf1(a1, a2v, tex, 1);





        c.FUN_00ba3940(&b);





        b.FUN_00ba3940(&a);





        a.FUN_00ba3940(&c);





    }





    w = WorkRef(m_iThirdValue->p4);





    tex = m_1c->t4;





    w->SetAccumulatorAt(0, &a, 0);





    w->SetAccumulatorAt(1, &s88, 0);





    w->SetAccumulatorAt(2, &b, 0);





    w->Vf1(a1, a2v, tex, 1);





    c.FUN_00ba3940(&b);





    b.FUN_00ba3940(&a);





    a.FUN_00ba3940(&c);





    w = WorkRef(m_iThirdValue->p2);





    tex = m_1c->t2;





    for (i = 0; i < count; i++)





    {





        m_b4 = (float)(i * 0.0625 + 0.03125);





        tex->FUN_00b8a790(1, m_b4, DAT_0101e570, 0.0f, 0.0f);





        if (i == count - 1)





            w->SetAccumulatorAt(0, m_2c->p1, 0);





        else





            w->SetAccumulatorAt(0, &a, 0);





        w->SetAccumulatorAt(1, &s78, 0);





        w->SetAccumulatorAt(2, &b, 0);





        w->Vf1(a1, a2v, tex, 1);





        if (i != count - 1)





        {





            c.FUN_00ba3940(&b);





            b.FUN_00ba3940(&a);





            a.FUN_00ba3940(&c);





        }





    }





    if (DAT_01200058)





    {





        w = WorkRef(m_iThirdValue->p5);





        tex = m_1c->t5;





        tex->FUN_00b8a790(2, DAT_0120004c, DAT_0101e570, 0.0f, 0.0f);





        w->SetAccumulatorAt(0, m_2c->p0, 0);





        w->SetAccumulatorAt(1, m_2c->p1, 0);





        w->Vf1(a1, a2v, tex, 1);





    }





    else





    {





        w = WorkRef(m_iThirdValue->p6);





        tex = m_1c->t6;





        w->SetAccumulatorAt(0, m_2c->p0, 0);





        w->SetAccumulatorAt(1, m_2c->p1, 0);





        w->Vf1(a1, a2v, tex, 1);





    }





    if (d.FUN_00ba3780())





        d.FUN_00ba39a0();





    if (a.FUN_00ba3780())





        a.FUN_00ba39a0();





    if (b.FUN_00ba3780())





        b.FUN_00ba39a0();





}


struct TextureAllocationManagerB63
{
    void* FUN_00aa3e40(unsigned int bytes);
};
extern TextureAllocationManagerB63 DAT_011f6238;
inline void* operator new(unsigned int bytes)
{
    return DAT_011f6238.FUN_00aa3e40(bytes);
}

struct RenderedGetterB63D
{
    int FUN_00ba3770();
};
struct TextureNodeB63D
{
    int unk00;
    int unk04;
    OwnerStandIn* texture;
};
struct ReturnManagerB63D
{
    void FUN_00b6da10(unsigned int);
};
struct TextureOwnerB63D
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
    TextureNodeB63D* node;
    void FUN_00b63d10();
};

// @fnv 0x00b63d10
// pdb: ImageSpaceShaderVolumetricFog::ReturnVolumetricFogTexture | BSShaderAccumulator.obj | fnv360_0822_retail, caller_sim, medium
void TextureOwnerB63D::FUN_00b63d10()
{
    TextureNodeB63D* current = node;
    if (!node->texture)
        return;
    if (!reinterpret_cast<RenderedGetterB63D*>(current->texture)->FUN_00ba3770())
        return;
    ReturnManagerB63D* manager = reinterpret_cast<ReturnManagerB63D*>(DAT_011f91a8);
    OwnerStandIn** slot = &node->texture;
    int rendered = reinterpret_cast<RenderedGetterB63D*>(*slot)->FUN_00ba3770();
    manager->FUN_00b6da10(rendered);
    node->texture->FUN_00ba37a0(0);
}
