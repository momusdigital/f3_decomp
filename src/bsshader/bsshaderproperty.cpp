// bsshader/bsshaderproperty.cpp: ShaderPassEntry, ShaderPassList, NiShadeProperty, ShaderPropertyRecord (22 functions)
#include "f3_common.h"
#include "bsshaderproperty_decls.h"

// Initializes the shader property with geometry, pass, first-pass flag, light count, and copies the given lights into a newly allocated array.
// @fnv 0x00ba8ec0
// pdb: BSShaderProperty::RenderPass::RenderPass | BSShaderProperty.obj | fnv360_0822_retail, call_seq, medium, conflict (skyrim: BSLightingShaderMaterialBase::GetTextures)
// pdb params: apGeometry, ausPassEnum, abFirstPass, ausNumLights, apSceneLight
BSShaderProperty::ShaderPassEntry::ShaderPassEntry(NiGeometry* geometry, unsigned short passEnum, bool firstPass,
                                                   unsigned char numLights, ShadowSceneLight* light0, ...)
{
    m_pShaderGeometry = geometry;
    m_usShaderPassType = passEnum;
    m_ucLightCount = numLights;
    m_ucLightCapacity = 0;
    m_bIsBest = firstPass;
    m_bRendered = false;
    m_ppShadowSceneLights = 0;
    m_ucLightIndex = 0;
    if (numLights > 0)
    {
        m_ppShadowSceneLights = reinterpret_cast<ShadowSceneLight**>(new BSShaderPropertyLightSlot[numLights]);
        m_ucLightCapacity = numLights;
        ShadowSceneLight** lights = &light0;
        for (int i = 0; i < numLights; ++i)
            m_ppShadowSceneLights[i] = lights[i];
    }
    m_ucPassIndex = 0;
}

// @fnv 0x00ba9ee0
// pdb: BSShaderProperty::RenderPassArray::Add | BSShaderProperty.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apGeometry, ausPassEnum, abFirstPass, ausNumLights, apSceneLight, apSceneLight1, apSceneLight2, apSceneLight3
void BSShaderProperty::ShaderPassList::Add(NiGeometry* geometry, unsigned short passEnum, bool firstPass,
                                           unsigned char numLights, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                           ShadowSceneLight* light2, ShadowSceneLight* light3)
{
    if (iSize >= m_kRenderPasses.m_usESize)
    {
        m_kRenderPasses.Add(
            new ShaderPassEntry(geometry, passEnum, firstPass, numLights, light0, light1, light2, light3));
    }
    else
    {
        ShaderPassEntry* pass = m_kRenderPasses.m_pBase[iSize];
        pass->BSShaderProperty_RenderPass_SetLights(numLights, light0, light1, light2, light3);
        pass->SetFirstPass(firstPass);
        pass->SetGeometry(geometry);
        pass->SetPassEnum(passEnum);
        pass->m_bRendered = false;
        pass->m_ucLightIndex = 0;
        pass->m_ucPassIndex = 0;
    }
    ++iSize;
}

struct FUN_00ba8ab0_shell : public BSShaderProperty
{
    void FUN_00ba8ab0(float);
};

// Resets the int at offset 0x38 when the stored float at 0x28 crosses the 1.0 threshold, then stores afAlpha at 0x28.
// @fnv 0x00ba8ab0
// pdb: BSShaderProperty::SetAlpha | BSShaderProperty.obj | fnv360_0822_retail, call_gap, medium
// pdb params: afAlpha
void FUN_00ba8ab0_shell::FUN_00ba8ab0(float afAlpha)
{
    if ((*(float*)((char*)this + 0x28) >= 1.0f && afAlpha < 1.0f) ||
        (*(float*)((char*)this + 0x28) < 1.0f && afAlpha >= 1.0f))
    {
        *(int*)((char*)this + 0x38) = 0;
    }
    *(float*)((char*)this + 0x28) = afAlpha;
}

// Resets the count at offset 4, frees the light pointer at offset 0xC if set, and clears the byte at offset 0xB.
// @fnv 0x00ba8cd0
// pdb: BSShaderProperty::RenderPass::~RenderPass | BSShaderProperty.obj | fnv360_0822_retail, call_gap, low
void __fastcall FUN_00ba8cd0(char* pThis)
{
    *(unsigned short*)(pThis + 4) = 0;
    void* pLights = *(void**)(pThis + 0xC);
    if (pLights)
    {
        g_memoryManager.Deallocate(pLights);
        *(void**)(pThis + 0xC) = 0;
    }
    *(unsigned char*)(pThis + 0xB) = 0;
}

struct FUN_00baa000_shell : public BSShaderProperty
{
    void FUN_00baa000();
};

void __fastcall FUN_00ba9520(void* pThis);

// Clears the int at offset 0x38, then for each pointer at offsets 0x3c-0x54 calls FUN_00ba9520, deallocates it via g_memoryManager and nulls it.
// @fnv 0x00baa000
// pdb: BSShaderProperty::FreeRenderPasses | BSShaderProperty.obj | fnv360_0822_retail, call_dedup, medium
void FUN_00baa000_shell::FUN_00baa000()
{
    char* self = reinterpret_cast<char*>(this);
    *reinterpret_cast<int*>(self + 0x38) = 0;

    void* p = *reinterpret_cast<void**>(self + 0x3c);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x3c) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x40);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x40) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x48);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x48) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x4c);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x4c) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x44);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x44) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x50);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x50) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x54);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x54) = 0;
    }
}

extern const char g_01200464_arg1[];
// @fnv 0x00a81450
// pdb: NiLight::GetRTTI | NiLight.obj | fnv360_1110_retail, objrun + bridge(vtable|objrun) + skyrim(objrun_open), high
const char* __cdecl NiLight_GetRTTI()
{
    return g_01200464_arg1;
}

struct BSSP_stub4;
struct NiObject_stub
{
    void FUN_00a81430(BSSP_stub4*, int);
};
struct BSSP_stub4 : NiObject_stub
{
    int a[8];
    unsigned int m_f0, m_f1;
    float m_fAlpha, m_fFade;
    int b[2];
    int m_iLast;
    int c[7];
    int m_iShader;
    float m_fFogDepth;
};
// @fnv 0x00ba8b10
// pdb: BSShaderProperty::CopyMembers | BSShaderProperty.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: pDest, arCloneData
void __fastcall FUN_00ba8b10(BSSP_stub4* self, int, BSSP_stub4* dst, int arg)
{
    self->FUN_00a81430(dst, arg);
    dst->m_f0 = self->m_f0;
    dst->m_f1 = self->m_f1;
    dst->m_fAlpha = self->m_fAlpha;
    dst->m_fFade = self->m_fFade;
    dst->m_iLast = 0;
    dst->m_iShader = self->m_iShader;
    dst->m_fFogDepth = self->m_fFogDepth;
}

extern bool DAT_0120045c;
// @fnv 0x00ba8b60
// pdb: Script::SetProcessScripts | TESScript.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abProcessScripts
void __cdecl FUN_00ba8b60(bool v)
{
    DAT_0120045c = v;
}

extern bool DAT_0120045d;
// @fnv 0x00ba8b70
// pdb: BSShaderProperty::PreviousTransform::ToggleConsole | BSShaderProperty.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSLightingShaderMaterialBase::QDefault)
void __cdecl ToggleGlobalFlag()
{
    DAT_0120045d = !DAT_0120045d;
}

struct NiObjectNET_stub
{
    void FUN_00a5c6a0(int);
};
struct BSSP_stub : NiObjectNET_stub
{
    int a[8];
    unsigned int m_flags;
    int b[14];
    float m_depth;
};
// @fnv 0x00ba8be0
// pdb: BSShaderProperty::PostLinkObject | BSShaderProperty.obj | fnv360_0822_retail, call_seq, medium
// pdb params: kStream
void __fastcall FUN_00ba8be0(BSSP_stub* self, int, int arg)
{
    self->FUN_00a5c6a0(arg);
    if ((self->m_flags & 0x4000000) > 0)
        self->m_depth = 1.0f;
}

struct AllocElem
{
    int v;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
struct BSSP_stub2
{
    int a[3];
    AllocElem* m_p;
};
// Allocates an array of n AllocElem objects and stores its pointer in self->m_p.
// @fnv 0x00ba8c00
// pdb: BSShaderProperty::RenderPass::AllocateLightArray | BSShaderProperty.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aucNumLights
void __fastcall AllocateElemArray(BSSP_stub2* self, int, unsigned char n)
{
    self->m_p = new AllocElem[n];
}

struct FUN_00ba8c30_shell2
{
    int a[3];
    void* m_p;
    void FUN_00ba8c30();
};
// @fnv 0x00ba8c30
// pdb: BSShaderProperty::RenderPass::FreeLightArray | BSShaderProperty.obj | fnv360_0822_retail, call_gap, medium
void __fastcall FUN_00ba8c30(FUN_00ba8c30_shell2* self, int)
{
    if (self->m_p)
    {
        g_memoryManager.Deallocate(self->m_p);
        self->m_p = 0;
    }
}

extern const char g_011fa018_arg1[];
// @fnv 0x00ba8eb0
// pdb: NiDX9AdditionalDepthStencilBufferData::GetRTTI | NiDX92DBufferData.obj | tesv_win, udata, high
const char* __cdecl NiDX9AdditionalDepthStencilBufferData_GetRTTI()
{
    return g_011fa018_arg1;
}

void __fastcall DestroyFogProperty(void*);
void __cdecl _delete(void*, unsigned int);
struct NiShadeProperty
{
    void* Destroy(unsigned int);
};
// Calls DestroyFogProperty on this, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a81460
// pdb: NiShadeProperty::`vector deleting destructor' | NiShadeProperty.obj | tesv_win, objrun_open, low
void* NiShadeProperty::Destroy(unsigned int flags)
{
    DestroyFogProperty(this);
    if (flags & 1)
        _delete(this, 0x20);
    return this;
}

extern __declspec(thread) int g_iB97550AllocTag;

struct BB97550AllocTagScope
{
    int m_iSaved;

    BB97550AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iB97550AllocTag;
        g_iB97550AllocTag = aiAllocationTag;
    }
    ~BB97550AllocTagScope()
    {
        g_iB97550AllocTag = m_iSaved;
    }
};

struct S_00ba8c50_Slot
{
    ShadowSceneLight* light;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

// Grows the light array to numLights if needed, then stores numLights and copies the variadic ShadowSceneLight pointers into it.
// @fnv 0x00ba8c50
// pdb: BSShaderProperty::RenderPass::SetLights | BSShaderProperty.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
void __cdecl BSShaderProperty::ShaderPassEntry::BSShaderProperty_RenderPass_SetLights(unsigned char numLights, ShadowSceneLight*, ...)
{
    ShadowSceneLight** args = (ShadowSceneLight**)((unsigned int*)&numLights + 1);

    if (numLights > m_ucLightCapacity)
    {
        if (m_ppShadowSceneLights != 0)
        {
            delete[] reinterpret_cast<S_00ba8c50_Slot*>(m_ppShadowSceneLights);
            m_ppShadowSceneLights = 0;
        }
        m_ppShadowSceneLights = reinterpret_cast<ShadowSceneLight**>(new S_00ba8c50_Slot[numLights]);
        m_ucLightCapacity = numLights;
    }
    m_ucLightCount = numLights;
    if (numLights > 0)
    {
        int count = numLights;
        for (int i = 0; i < count; ++i)
        {
            m_ppShadowSceneLights[i] = args[i];
        }
    }
}

struct FUN_00ba8e50_base
{
    void InitBase();
};

struct FUN_00ba8e50_cls : FUN_00ba8e50_base
{
    int m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    volatile unsigned short m_18;
    volatile int m_1c;
    volatile int m_20;
    volatile int m_24;
    volatile float m_28;
    volatile float m_2c;
    volatile float m_30;
    float m_34;
    volatile int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int unk54;
    int m_58;
    float m_5c;

    FUN_00ba8e50_cls* FUN_00ba8e50();
};

// Initializes the object: calls InitBase, sets the vtable pointer, and zeroes or defaults the member fields, returning this.
// @f3 0x00b2afb0 (community match, verified in this file)
extern int DAT_00e9ef88;
// pdb: BSShaderProperty::BSShaderProperty | BSShaderProperty.obj | fnv360_0822_retail, call_seq, medium
FUN_00ba8e50_cls* FUN_00ba8e50_cls::FUN_00ba8e50()
{
    InitBase();
    m_1c = -1;
    m_18 = 1;
    *(volatile int*)&m_vptr00 = (int)&DAT_00e9ef88;
    m_20 = 0;
    m_24 = 0;
    m_28 = 1.0f;
    m_2c = 1.0f;
    m_38 = 0;
    m_30 = 1.0f;
    m_3c = 0;
    m_40 = 0;
    m_5c = 0.0f;
    m_48 = 0;
    m_4c = 0;
    m_34 = 0.0f;
    m_44 = 0;
    m_50 = 0;
    m_58 = 0;
    return this;
}


class FUN_00ba8b80
{
  public:
    virtual ~FUN_00ba8b80();
    ShadowSceneLight** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    FUN_00ba8b80(unsigned int maxSize, unsigned short growBy);
};

// @fnv 0x00ba8b80
// pdb: NiTArray<BSShaderProperty::RenderPass *,NiTNewInterface<BSShaderProperty::RenderPass *> >::NiTArray<BSShaderProperty::RenderPass *,NiTNewInterface<BSShaderProperty::RenderPass *> > | BSShaderProperty.obj | fnv360_0822_retail, call_gap, medium
// pdb params: uiMaxSize, uiGrowBy
FUN_00ba8b80::FUN_00ba8b80(unsigned int maxSize, unsigned short growBy)
{
    unsigned short n = (unsigned short)maxSize;
    m_usMaxSize = n;
    m_usGrowBy = growBy;
    m_usSize = 0;
    m_usESize = 0;
    if (n > 0)
    {
        m_pBase = (ShadowSceneLight**)new BSShaderPropertyLightSlot[m_usMaxSize];
    }
    else
    {
        m_pBase = 0;
    }
}

// Resizes the array to newSize: clears and shrinks entries above the new size, reallocates the base buffer, copies existing entries and zero-fills the rest.
// @fnv 0x00ba8d30
// pdb: NiTArray<TESObjectREFR *,NiTNewInterface<TESObjectREFR *> >::SetSize | GarbageCollector.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiMaxSize
void NiTArray<BSShaderProperty::ShaderPassEntry*, NiTNewInterface<BSShaderProperty::ShaderPassEntry*> >::FUN_00ba8d30(
    unsigned int newSize)
{
    if (newSize != m_usMaxSize)
    {
        if (newSize < m_usSize)
        {
            for (unsigned short i = (unsigned short)newSize; i < m_usSize; ++i)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize += 0xffff;
                }
            }
            m_usSize = (unsigned short)newSize;
        }
        BSShaderProperty::ShaderPassEntry** oldBase = m_pBase;
        m_usMaxSize = (unsigned short)newSize;
        if (newSize > 0)
        {
            m_pBase = (BSShaderProperty::ShaderPassEntry**)new BSShaderPropertyLightSlot[m_usMaxSize];
            for (unsigned short i = 0; i < m_usSize; ++i)
                m_pBase[i] = oldBase[i];
            for (unsigned short i = m_usSize; i < m_usMaxSize; ++i)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        g_memoryManager.Deallocate(oldBase);
    }
}

struct FUN_00ba8d00_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;

    void FUN_00ba8d00(bool enable);
};
// Sets or clears bit 0x10 in unk20, zeroing unk38 when the bit's state changes.
// @fnv 0x00ba8d00
// pdb: BSShaderProperty::SetMotionBlurred | BSShaderProperty.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abIsMotionBlurred
void FUN_00ba8d00_cls::FUN_00ba8d00(bool enable)
{
    if (enable)
    {
        unsigned int f = 0x10;
        if (!(*reinterpret_cast<const unsigned char*>(&unk20) & f))
            unk38 = 0;
        unk20 |= f;
    }
    else
    {
        if (*reinterpret_cast<const unsigned char*>(&unk20) & 0x10)
            unk38 = 0;
        unk20 &= ~0x10;
    }
}

struct SettingArray
{
    unsigned int metadata;
    int* values;
    unsigned short capacity;
    unsigned short count;
    unsigned short activeCount;
    unsigned short growBy;
    void __thiscall FUN_0096ad30(unsigned int newSize);
    void __thiscall FUN_0096ae90(unsigned int index, int* value);
    void AddTextValue(int* value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void AddNumericValue(int value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value != 0)
                ++activeCount;
        }
        else if (value != 0)
        {
            if (values[index] == 0)
                ++activeCount;
        }
        else if (values[index] != 0)
        {
            --activeCount;
        }
        values[index] = value;
    }
    __forceinline void AddFinal(int value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value != 0)
                ++activeCount;
        }
        else if (value != 0)
        {
            if (values[index] == 0)
                ++activeCount;
        }
        else if (values[index] != 0)
        {
            --activeCount;
        }
        values[index] = value;
    }
};
struct ShaderFlagEntry
{
    unsigned int unknown00;
    unsigned short type;
    unsigned char unknown06;
    unsigned char secondary;
};
struct ShaderFlagList
{
    unsigned int unknown00;
    ShaderFlagEntry** entries;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int count;
};
struct ShaderPropertyRecord
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14, unknown18, unknown1c;
    unsigned int flags[2];
    float alpha;
    float fade;
    float specular;
    int unknown34;
    int material;
    ShaderFlagList* flagsList;
    int unknown40, unknown44, unknown48, unknown4c;
    int unknown50, unknown54;
    int shaderType;
    float depth;
    void WriteToSettingArray(SettingArray* output);
};
// Serializes shader flags, alpha, fade, depth, specular, shader type, material, and flag list entries into a SettingArray via text and numeric tokens.
// @f3 0x00b2b9f0 (community match, verified in this file)
struct BaseWriter
{
    void FUN_008608e0(SettingArray*);
};
extern const char UNK_00e9f440[];
extern const char UNK_00e9f438[];
extern const char UNK_00e9f42c[];
extern const char UNK_00e9f41c[];
extern const char UNK_00e9f410[];
extern const char UNK_00e9f404[];
extern const char UNK_00e9f3fc[];
extern const char UNK_00e9f3e8[];
extern const char UNK_00e9f3d8[];
extern const char UNK_00e9f3cc[];
extern const char UNK_00e9f3c4[];
extern const char UNK_00e9f3b8[];
extern const char UNK_00e9f3a4[];
extern const char UNK_00e9f38c[];
extern const char UNK_00e9f380[];
extern const char UNK_00e9f374[];
extern const char UNK_00e9f364[];
extern const char UNK_00e9f34c[];
extern const char UNK_00e9f344[];
extern const char UNK_00e9f334[];
extern const char UNK_00e9f31c[];
extern const char UNK_00e9f300[];
extern const char UNK_00e9f2f0[];
extern const char UNK_00e9f2e0[];
extern const char UNK_00e9f2cc[];
extern const char UNK_00e9f2b8[];
extern const char UNK_00e9f2b0[];
extern const char UNK_00e9f2a0[];
extern const char UNK_00e9f28c[];
extern const char UNK_00e9f278[];
extern const char UNK_00e9f26c[];
extern const char UNK_00e9f25c[];
extern const char UNK_00e9f24c[];
extern const char UNK_00e9f23c[];
extern const char UNK_00e9f22c[];
extern const char UNK_00e9f224[];
extern const char UNK_00e9f214[];
extern const char UNK_00e9f204[];
extern const char UNK_00e9f1f8[];
extern const char UNK_00e9f1dc[];
extern const char UNK_00e9f1d0[];
extern const char UNK_00e9f1c4[];
extern const char UNK_00e9f1b4[];
extern const char UNK_00e9f1a4[];
extern const char UNK_00e9f198[];
extern const char UNK_00e9f18c[];
extern const char UNK_00e9f178[];
extern const char UNK_00e9f164[];
extern const char UNK_00e9f158[];
extern const char UNK_00e9f148[];
extern const char UNK_00e9f134[];
extern const char UNK_00e9f124[];
extern const char UNK_00e9f110[];
extern const char UNK_00e9f104[];
extern const char UNK_00e9f0e4[];
extern const char UNK_00e9f0dc[];
extern const char UNK_00e9f0d0[];
extern const char UNK_00e9f0c4[];
extern const char UNK_00e9f0b4[];
extern const char UNK_00e9f0a4[];
extern const char UNK_00e9f08c[];
extern const char UNK_00e9f070[];
extern const char UNK_00e9f05c[];
extern const char UNK_00e9f054[];
extern const char UNK_00e9f04c[];
extern const char* DAT_011761e4;
extern int __cdecl FUN_00847b50(const char*);
extern int __cdecl FUN_00847b90(const char*, int);
extern int __cdecl FUN_00847dd0(const char*, float);
extern int __cdecl FUN_00847d30(const char*, int);
extern unsigned int __cdecl FUN_00847d80(const char*, unsigned int);
extern int __cdecl FUN_00847e70(const char*, const char*);
extern const char* __cdecl FUN_00ad5de0(unsigned int);
// pdb: BSShaderProperty::GetViewerStrings | BSShaderProperty.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void ShaderPropertyRecord::WriteToSettingArray(SettingArray* output)
{
    ((BaseWriter*)this)->FUN_008608e0(output);
    union
    {
        int token;
        float scalar;
    } formatted;
    formatted.token = FUN_00847b50(DAT_011761e4);
    output->AddTextValue(&formatted.token);
    const char* flagNames[55] = {
        UNK_00e9f440, UNK_00e9f438, UNK_00e9f42c, UNK_00e9f41c, UNK_00e9f410, UNK_00e9f404, UNK_00e9f3fc, UNK_00e9f3e8,
        UNK_00e9f3d8, UNK_00e9f3cc, UNK_00e9f3c4, UNK_00e9f3b8, UNK_00e9f3a4, UNK_00e9f38c, UNK_00e9f380, UNK_00e9f374,
        UNK_00e9f364, UNK_00e9f34c, UNK_00e9f344, UNK_00e9f334, UNK_00e9f31c, UNK_00e9f300, UNK_00e9f2f0, UNK_00e9f2e0,
        UNK_00e9f2cc, UNK_00e9f2b8, UNK_00e9f2b0, UNK_00e9f2a0, UNK_00e9f28c, UNK_00e9f278, UNK_00e9f26c, UNK_00e9f25c,
        UNK_00e9f24c, UNK_00e9f23c, UNK_00e9f22c, UNK_00e9f224, UNK_00e9f214, UNK_00e9f204, UNK_00e9f1f8, UNK_00e9f1dc,
        UNK_00e9f1d0, UNK_00e9f1c4, UNK_00e9f1b4, UNK_00e9f1a4, UNK_00e9f198, UNK_00e9f18c, UNK_00e9f178, UNK_00e9f164,
        UNK_00e9f158, UNK_00e9f148, UNK_00e9f134, UNK_00e9f124, UNK_00e9f110, UNK_00e9f104, UNK_00e9f0e4};
    unsigned int i = 0;
    for (; i < 55; ++i)
    {
        if ((flags[i >> 5] & (1u << (i & 31))) > 0 && flagNames[i] != 0)
        {
            formatted.token = FUN_00847b90(flagNames[i], 1);
            output->AddTextValue(&formatted.token);
        }
    }
    if (alpha < 1.0f)
    {
        formatted.token = FUN_00847dd0(UNK_00e9f0dc, alpha);
        output->AddTextValue(&formatted.token);
    }
    if (fade < 1.0f)
    {
        formatted.token = FUN_00847dd0(UNK_00e9f0d0, fade);
        output->AddTextValue(&formatted.token);
    }
    if (depth > 0.0f)
    {
        formatted.token = FUN_00847dd0(UNK_00e9f0c4, depth);
        output->AddTextValue(&formatted.token);
    }
    if ((flags[0] & 0x80u) > 0)
    {
        formatted.scalar = specular;
        formatted.token = FUN_00847dd0(UNK_00e9f0b4, formatted.scalar);
        output->AddTextValue(&formatted.token);
    }
    int numericToken = FUN_00847d30(UNK_00e9f0a4, shaderType);
    output->AddNumericValue(numericToken);
    numericToken = FUN_00847d30(UNK_00e9f08c, material);
    output->AddNumericValue(numericToken);
    if (!flagsList)
    {
        formatted.token = FUN_00847b50(UNK_00e9f070);
        output->AddTextValue(&formatted.token);
        return;
    }
    unsigned int count = flagsList->count;
    formatted.token = FUN_00847d80(UNK_00e9f05c, count);
    output->AddTextValue(&formatted.token);
    for (unsigned int index = 0; index < count; ++index)
    {
        ShaderFlagEntry* entry = flagsList->entries[index];
        unsigned short type = entry->type;
        if (type < 0x2f7)
        {
            const unsigned int code = type;
            if (entry->secondary)
            {
                output->AddFinal(FUN_00847e70(UNK_00e9f054, FUN_00ad5de0((unsigned int)entry->type)));
            }
            else
            {
                output->AddFinal(FUN_00847e70(UNK_00e9f04c, FUN_00ad5de0((unsigned int)entry->type)));
            }
        }
    }
}


struct FUN_00ba8e20
{
    void* m_p;
    FUN_00ba8e20();
    virtual ~FUN_00ba8e20();
    // pdb: NiTArray<TESObjectREFR *,NiTNewInterface<TESObjectREFR *> >::`scalar deleting destructor' | GarbageCollector.obj | fnv360_0822_retail, vtable, medium
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// Default constructor for FUN_00ba8e20; performs no initialization.
// @fnv 0x00ba8e20
FUN_00ba8e20::FUN_00ba8e20()
{}
FUN_00ba8e20::~FUN_00ba8e20()
{
    g_memoryManager.Deallocate(m_p);
}

namespace fnv_00bb73f0 {
struct FUN_00ba8ab0_shell : public BSShaderProperty
{
    void FUN_00ba8ab0(float);
};

struct FUN_00ba9820_shell : public BSShaderProperty
{
    void CreateSpawnedObjectIfMissing(int);
};

struct FUN_00ba95e0_shell : public BSShaderProperty
{
    void FUN_00ba95e0(int);
};

struct FUN_00bb73f0_shell
{
    void* vtable;
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
    float m_fAlpha;
    int unk30;
    int unk34;
    unsigned int m_uiPass;
    BSShaderProperty::ShaderPassList* m_pRenderPassArray3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    BSShaderProperty::ShaderPassList* m_pRenderPassArray54;

    BSShaderProperty::ShaderPassList* FUN_00bb73f0(int geometry, unsigned int arg2, int arg3, unsigned int arg4,
                                                   int arg5, int arg6);
};

// Computes a pass key from arg2 and arg4, sets alpha and light index, and returns the appropriate render pass list for the given geometry.
// @fnv 0x00bb73f0
// pdb: BSDistantTreeShaderProperty::GetRenderPasses | BSDistantTreeShaderProperty.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apGeom, aiEnabledPasses, asCount, auiRenderMode, apAccumulator, abUpdateList
BSShaderProperty::ShaderPassList* FUN_00bb73f0_shell::FUN_00bb73f0(int geometry, unsigned int arg2, int aiUnused,
                                                                   unsigned int arg4, int aiUnused2, int aiUnused3)
{
    int* shaderSlot = (int*)((char*)geometry + 0x9c);
    float alpha;
    unsigned int pass = (arg4 << 8) | arg2;
    if (arg4 == 7)
        return 0;

    if (shaderSlot)
    {
        int shader = shaderSlot[2];
        if (shader)
            alpha = *(float*)((char*)shader + 0x3c) * m_fAlpha;
        else
            alpha = m_fAlpha;
        ((FUN_00ba8ab0_shell*)this)->FUN_00ba8ab0(alpha);
    }

    if (arg4 == 0xf)
    {
        ((FUN_00ba9820_shell*)this)->CreateSpawnedObjectIfMissing(1);
        if (m_pRenderPassArray54->iSize == 0)
        {
            m_pRenderPassArray54->Add((NiGeometry*)geometry, 0x237, true, 0, 0, 0, 0, 0);
            m_pRenderPassArray54->m_kRenderPasses.m_pBase[0]->m_ucLightIndex = 0;
        }
        return m_pRenderPassArray54;
    }

    if (m_uiPass != pass)
    {
        ((FUN_00ba95e0_shell*)this)->FUN_00ba95e0(1);
        m_pRenderPassArray3c->iSize = 0;
        m_pRenderPassArray3c->Add((NiGeometry*)geometry, 0x236, true, 0, 0, 0, 0, 0);
        m_pRenderPassArray3c->m_kRenderPasses.m_pBase[0]->m_ucLightIndex = 0xa;
        m_uiPass = pass;
    }
    return m_pRenderPassArray3c;
}
}  // namespace fnv_00bb73f0
