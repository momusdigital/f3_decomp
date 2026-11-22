#include <windows.h>
// src/f3staging/f3blk_00b20000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b21110 (community match, verified in this file)
namespace f3m_00b21110 {
struct Owner14;
struct Prop14 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int type;
    int IsLightingProperty() { switch(type) { case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: return 1; default: return 0; } }
    void FUN_00af43d0(Owner14*);
};
struct Obj14 {
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
    Prop14* prop;
};
struct Ptr14 { Obj14* value; operator Obj14*() const { return value; } };
struct Node14 { Node14* next; Node14* previous; Ptr14 data; };
struct List14 {
    Node14* head;
    void FUN_00abb340();
    Ptr14& GetNext(Node14*& node) { Ptr14* data = &node->data; node=node->next; return *data; }
};
struct Owner14 {
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
    List14 first;
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
    List14 second;
    void FUN_00b21110();
};
// pdb: ShadowSceneLight::RemoveAllTriShapes | ShadowSceneLight.obj | fnv360_0822_retail, call_gap, medium
void Owner14::FUN_00b21110() {
    Node14* node = first.head;
    while (node) {
        Obj14* obj = first.GetNext(node);
        if (obj) {
            Prop14* prop = obj->prop;
            if (prop) {
                int b = prop->IsLightingProperty();
                int* pb = &b;
                Prop14* match = *pb ? prop : 0;
                if (match) match->FUN_00af43d0(this);
            }
        }
    }
    first.FUN_00abb340();
    second.FUN_00abb340();
}
}   // namespace f3m_00b21110

// @f3 0x00b33320 (community match, verified in this file)
extern unsigned int DAT_0117637c;
namespace f3m_00b33320 {

typedef int (__thiscall* TVtblFn)(void*);

// The string array this function appends to. Layout matches the engine's
// NiTArray<char*> (vtable, base, u16 max size / size / esize / grow by).
class SettingArray
{
  public:
    void** m_ppVtbl;            // 0x00
    const char** m_pBase;       // 0x04
    unsigned short m_usMaxSize; // 0x08
    unsigned short m_usSize;    // 0x0a
    unsigned short m_usESize;   // 0x0c
    unsigned short m_usGrowBy;  // 0x0e

    void FUN_00555790(unsigned int uiSize);
    void FUN_005b3880(unsigned int uiIndex, const char* const& pItem);

    void Append(const char* const& pItem)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_00555790(uiIndex + m_usGrowBy);
        FUN_005b3880(uiIndex, pItem);
    }
};


const char* __cdecl FUN_00847b50(unsigned int uiValue);
const char* __cdecl FUN_00847d30(const char* pcName, int iValue);
void* __cdecl FUN_00aabd00(unsigned int uiForm);
const char* __cdecl FUN_00847e70(const char* pcName, void* pValue);
const char* __cdecl FUN_00847e20(const char* pcName, void* pValue);
const char* __cdecl FUN_00847b90(const char* pcName, int iValue);
const char* __cdecl FUN_00848420(const char* pcName, int iValue);

class FUN_00b33320_shell
{
  public:
    void** m_ppVtbl;             // 0x00
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int m_iParticleCount;        // 0x60
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    unsigned int m_uiTextureForm; // 0x90
    int unk94;
    int m_iBillboardMode;        // 0x98

    void FUN_00b2b9f0(SettingArray* pArray);
    void FUN_00b33320(SettingArray* pArray);
};

// pdb: PrecipitationShaderProperty::GetViewerStrings | PrecipitationShaderProperty.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void FUN_00b33320_shell::FUN_00b33320(SettingArray* pArray)
{
    FUN_00b2b9f0(pArray);
    pArray->Append(FUN_00847b50(DAT_0117637c));
    pArray->Append(FUN_00847d30("iParticleCount", m_iParticleCount));
    if (m_uiTextureForm)
    {
        void* pName = FUN_00aabd00(m_uiTextureForm);
        char* pValue;
        if (pName)
        {
            pValue = (char*)FUN_00847e70("base texture", pName);
            pArray->Append(pValue);
        }
        else
        {
            pName = (void*)m_uiTextureForm;
            pValue = (char*)FUN_00847e20("base texture", pName);
            pArray->Append(pValue);
        }
    }
    if (!((TVtblFn)m_ppVtbl[0xcc / 4])(this))
        pArray->Append(FUN_00847b90("clamp", 1));
    pArray->Append(FUN_00848420("billboard mode", m_iBillboardMode));
}
}   // namespace f3m_00b33320

// @f3 0x00b34130 (community match, verified in this file)
#include <math.h>
namespace ShaderDraw {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Vec3
{
    float x, y, z;
};
struct Vec4
{
    float x, y, z, w;
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
extern Vec3 DAT_01170020;
extern Vec4 DAT_01170000, DAT_01170010, DAT_0116fe40, DAT_0116fe50;
extern unsigned char DAT_0116efb4, DAT_0116f20c;
extern bool DAT_0116ef97;
extern int DAT_0116efa8;
extern const float DAT_00dc2f0c;
extern float DAT_01176388, DAT_0117638c, DAT_011763dc, DAT_011763ec, DAT_011763e0, DAT_011763f0, DAT_011763f8,
    DAT_011763fc, DAT_01176400, DAT_01176404;
struct Fog
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec3 color;
    float farDistance, nearDistance;
};
Fog* FUN_00adb920(unsigned char);
struct Geometry
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
    Vec3 position;
};
struct Bound
{
    Vec3 center;
    float radius;
    __forceinline float Radius()
    {
        return radius;
    }
};
struct MaterialValues
{
    float unk00, unk04, unk08, alpha, emissive, ambient, u, v;
};
struct Material
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual unsigned int Texture();
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
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual MaterialValues* Values();
    virtual const void* Constants();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int type;
    unsigned int FUN_00af3450();
    __forceinline float U()
    {
        return Values()->u;
    }
    __forceinline float V()
    {
        return Values()->v;
    }
};
__forceinline unsigned int IsMaterial(Material* p)
{
    if (!p)
        return 0;
    unsigned int type = p->type;
    return type == 6;
}
struct PassInfo
{
    unsigned int mode;
    int unk04, unk08;
    Material* material;
};
struct RefObject
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long count;
};
struct RefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->count) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->count);
        }
    }
};
struct RenderState
{
    void FUN_008905a0(unsigned int, unsigned int, bool);
};
RenderState* FUN_00890750();
struct Stage
{
    int unk00, unk04;
    unsigned int texture;
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
    int references;
    void FUN_0088fe30();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            FUN_0088fe30();
    }
};
struct StagePointer
{
    Stage* object;
    StagePointer(Stage* p) : object(p)
    {
        if (object)
            ++object->references;
    }
    ~StagePointer()
    {
        if (object)
            object->Release();
    }
};
struct Pass
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
    Stage** stages;
    int unk28, unk2c;
    RenderState* state;
    int unk34, unk38, unk3c, unk40;
    RefPointer pixel;
    int unk48, unk4c, unk50, unk54, unk58;
    RefPointer vertex;
    void FUN_008866f0(RefObject*);
    void FUN_00886650(RefObject*);
    __forceinline void SetState(unsigned int key, unsigned int value, bool save)
    {
        if (!state)
            state = FUN_00890750();
        state->FUN_008905a0(key, value, save);
    }
};
struct Renderer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Select(unsigned int);
};
void* FUN_00bffa60(void*, const void*, unsigned int);
struct Shader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Renderer* renderer;
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
    float constants[192];
    RefObject* normalVertex;
    RefObject* fogVertex;
    RefObject* alternateVertex;
    RefObject* alternateFogVertex;
    RefObject* normalPixel;
    RefObject* fogPixel;
    Pass* pass;
    __forceinline RefObject* Get_normalVertex() const
    {
        return normalVertex;
    }
    __forceinline RefObject* Get_fogVertex() const
    {
        return fogVertex;
    }
    __forceinline RefObject* Get_alternateVertex() const
    {
        return alternateVertex;
    }
    __forceinline RefObject* Get_alternateFogVertex() const
    {
        return alternateFogVertex;
    }
    __forceinline RefObject* Get_normalPixel() const
    {
        return normalPixel;
    }
    __forceinline RefObject* Get_fogPixel() const
    {
        return fogPixel;
    }
    void SpeedTreeLeafShader_UpdatePipelineForInstance(Geometry*, int, int, PassInfo*, int, int, Bound*);
};
// @fnv 0x00b34130
// pdb: SpeedTreeLeafShader::UpdatePipelineForInstance | SpeedTreeLeafShader.obj | fnv360_1110_retail, udata, high
void Shader::SpeedTreeLeafShader_UpdatePipelineForInstance(Geometry* geometry, int unused1, int unused2, PassInfo* info, int FlushUsageData, int unused4,
                          Bound* bound)
{
    unsigned int mode = info->mode;
    renderer->Select(mode);
    bool useFog = false;
    Fog* fog = FUN_00adb920(DAT_0116efb4);
    if (fog)
    {
        float farDistance = fog->farDistance;
        float nearDistance = fog->nearDistance;
        Vec3 camera;
        camera.x = DAT_01170020.x;
        camera.y = DAT_01170020.y;
        camera.z = DAT_01170020.z;
        float dx = geometry->position.x - camera.x;
        float dy = geometry->position.y - camera.y;
        const float& dz = geometry->position.z - camera.z;
        float distance = (float)sqrt(dy * dy + dx * dx + dz * dz);
        if (distance > farDistance || distance + bound->Radius() > farDistance)
        {
            float interval = nearDistance - farDistance;
            Vec3 color = fog->color;
            useFog = true;
            DAT_01170000 = Vec4(nearDistance, interval, 0.0f, 0.0f);
            DAT_01170010 = Vec4(color.x, color.y, color.z, 0.0f);
        }
    }
    if (DAT_0116ef97)
    {
        DAT_0116fe40 = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
        if (DAT_0116efa8 == 9)
            DAT_0116fe50 = Vec4(0.0f, DAT_00dc2f0c, 0.0f, 0.0f);
        else
            DAT_0116fe50 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    Material* material = info->material;
    int isMaterial = IsMaterial(material);
    material = isMaterial ? material : 0;
    const void* materialConstants = material->Constants();
    FUN_00bffa60(constants, materialConstants, 768);
    DAT_011763dc = material->U() * DAT_01176388;
    DAT_011763ec = material->V() * DAT_0117638c;
    DAT_011763e0 = material->Values()->ambient;
    DAT_011763f0 = material->Values()->emissive;
    DAT_011763f8 = 0.0f;
    DAT_011763fc = 0.0f;
    DAT_01176400 = 0.0f;
    DAT_01176404 = 0.0f;
    DAT_011763fc = material->Values()->alpha;
    Pass* currentPass = pass;
    Stage**& stages = currentPass->stages;
    StagePointer stage(stages[0]);
    stage.object->texture = material->Texture();
    if (DAT_0116ef97)
    {
        {
            Pass* active = pass;
            RefObject* incoming = normalVertex;
            RefObject* old = active->vertex.object;
            if (old != incoming)
            {
                if (old && InterlockedDecrement(&old->count) == 0)
                    old->DeleteThis();
                active->vertex.object = incoming;
                if (incoming)
                    InterlockedIncrement(&incoming->count);
            }
        }
        {
            Pass* active = pass;
            RefObject* incoming = normalPixel;
            RefObject* old = active->pixel.object;
            if (old != incoming)
            {
                if (old && InterlockedDecrement(&old->count) == 0)
                    old->DeleteThis();
                active->pixel.object = incoming;
                if (incoming)
                    InterlockedIncrement(&incoming->count);
            }
        }
    }
    else
    {
        unsigned int alternate = material->FUN_00af3450();
        Pass* active = pass;
        if ((unsigned short)alternate == 0)
        {
            if (useFog)
            {
                active->FUN_008866f0(Get_fogVertex());
                pass->FUN_00886650(Get_fogPixel());
            }
            else
            {
                active->FUN_008866f0(Get_normalVertex());
                pass->FUN_00886650(Get_normalPixel());
            }
        }
        else if (useFog)
        {
            active->FUN_008866f0(Get_alternateFogVertex());
            pass->FUN_00886650(Get_fogPixel());
        }
        else
        {
            active->FUN_008866f0(Get_alternateVertex());
            pass->FUN_00886650(Get_normalPixel());
        }
    }
    if (DAT_0116efa8 == 6)
    {
        pass->SetState(52, 1, true);
        pass->SetState(56, 8, true);
        pass->SetState(55, 7, true);
        pass->SetState(53, 1, true);
        pass->SetState(54, 1, true);
    }
    else
        pass->SetState(52, 0, true);
    if ((DAT_0116f20c & 1) > 0)
        pass->SetState(168, 0, true);
    else
        pass->SetState(168, 7, true);
    pass->SetState(28, 0, true);
}
}

// @f3 0x00b3b600 (community match, verified in this file)
namespace f3_0251 {
struct Memory0251 { void FUN_0086ba60(void*); };
extern Memory0251 DAT_01090a78;
struct ISRefObject
{
    virtual ~ISRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};
struct ISTexRef : ISRefObject
{
};

struct ISTexPtr
{
    ISTexRef* m_pObject;
    ISTexPtr& operator=(ISTexRef* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};
extern ISTexPtr DAT_011765d8;
extern ISTexPtr DAT_011765dc;
extern ISTexPtr DAT_011765e0;

struct ISParam
{
    virtual ~ISParam();
};
struct FUN_00b22590
{
    ~FUN_00b22590();
    static void operator delete(void* p)
    {
        DAT_01090a78.FUN_0086ba60(p);
    }
};

struct ISParamArr
{
    void* m_vt;
    ISParam** m_pBase;
    int unk08;
    int unk0c;
    void FUN_005b3880(unsigned int index, ISParam* const& item);
};
struct ISTexArr
{
    void* m_vt;
    FUN_00b22590** m_pBase;
    int unk08;
    int unk0c;
    void FUN_005b3880(unsigned int index, FUN_00b22590* const& item);
};

struct FUN_00b22630
{
    virtual ~FUN_00b22630();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ISParamArr m_params;
    ISTexArr m_textures;
};

struct FUN_00b3b600 : FUN_00b22630
{
    virtual ~FUN_00b3b600();
};

// @fnv 0x00bc0360
// pdb: ImageSpaceEffectVATSScan::~ImageSpaceEffectVATSScan | ImageSpaceEffectVATSScan.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: ImageSpaceEffectTV::~ImageSpaceEffectTV)
FUN_00b3b600::~FUN_00b3b600()
{
    DAT_011765d8 = 0;
    DAT_011765dc = 0;
    DAT_011765e0 = 0;
    if (m_params.m_pBase[0])
    {
        delete m_params.m_pBase[0];
        m_params.FUN_005b3880(0, 0);
    }
    if (m_textures.m_pBase[3])
    {
        delete m_textures.m_pBase[3];
        m_textures.FUN_005b3880(3, 0);
    }
    if (m_textures.m_pBase[4])
    {
        delete m_textures.m_pBase[4];
        m_textures.FUN_005b3880(4, 0);
    }
    if (m_textures.m_pBase[2])
    {
        delete m_textures.m_pBase[2];
        m_textures.FUN_005b3880(2, 0);
    }
}

}

// @f3 0x00b39f90 (community match, verified in this file)
namespace tint_registration_1694 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
struct RTTI { const char* name; const RTTI* base; };
extern const RTTI DAT_0108f20c;
struct FixedString { const char* text; __forceinline operator const char*() const { return text; } };
struct Texture {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual const RTTI* GetRTTI();
};
struct SourceTexture : Texture {
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
    virtual void Unknown98();
    virtual const FixedString& GetFileName();
};
__forceinline bool IsSourceTexture(const RTTI* type) {
    while(type) {
        if(type==&DAT_0108f20c) return true;
        type=type->base;
    }
    return false;
}
__forceinline SourceTexture* CastSourceTexture(Texture* texture) {
    if(!texture) return 0;
    return IsSourceTexture(texture->GetRTTI()) ? static_cast<SourceTexture*>(texture) : 0;
}
extern const char* DAT_01176558;
extern const char DAT_00ea08f4[],DAT_00ea08e4[],DAT_00ea08d4[],DAT_00ea08cc[],DAT_00ea08c4[];
void* FUN_00847b50(const char*);
void* FUN_00847dd0(const char*,float);
void* FUN_00847e70(const char*,const char*);
struct TintEffect {
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
    Texture* texture;
    unsigned int unk64;
    float tintRed,tintGreen,tintBlue,alpha;
    void FUN_00b2b9f0(NameArray*);
    void FUN_00b39f90(NameArray*);
};
// pdb: TileShaderProperty::GetViewerStrings | TileShaderProperty.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void TintEffect::FUN_00b39f90(NameArray* names) {
    FUN_00b2b9f0(names);
    void* handle=FUN_00847b50(DAT_01176558);
    names->Append(handle);
    handle=FUN_00847dd0(DAT_00ea08f4,tintRed); names->Append(handle);
    handle=FUN_00847dd0(DAT_00ea08e4,tintGreen); names->Append(handle);
    handle=FUN_00847dd0(DAT_00ea08d4,tintBlue); names->Append(handle);
    handle=FUN_00847dd0(DAT_00ea08cc,alpha); names->Append(handle);
    SourceTexture* source=CastSourceTexture(texture);
    if(source) {
        handle=FUN_00847e70(DAT_00ea08c4,source->GetFileName());
        names->Append(handle);
    }
}
}

// @f3 0x00b39190 (community match, verified in this file)
extern unsigned char DAT_00ea0718;
unsigned int FUN_00b38030();
struct Heap17 { void* FUN_0086b930(unsigned int); };
extern Heap17 DAT_01090a78;
struct Element17 { int a,b,c,d,e,f,g,h; static void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); } };
struct FUN_00b2afb0 {
    void* vtable;
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
    FUN_00b2afb0();
    ~FUN_00b2afb0();
};
struct Owner17 : FUN_00b2afb0 {
    unsigned int value58, unk5c, elementCount;
    Element17* elements;
    Owner17();
};
// pdb: BSDistantTreeShaderProperty::BSDistantTreeShaderProperty | BSDistantTreeShaderProperty.obj | fnv360_0822_retail, objrun, medium
Owner17::Owner17() {
    vtable = &DAT_00ea0718;
    value58 = 8;
    elementCount = FUN_00b38030();
    elements = new Element17[elementCount];
    unk1c = 0x17;
}

// @f3 0x00b33240 (community match, verified in this file)
namespace f3m_00b33240 {
// Stand-in declarations for FUN_00b33240.
//
// The flag the original saves/sets/restores lives at TLS offset 0x298: the
// compiler's __declspec(thread) access sequence (fs:[0x2c] + _tls_index) is
// exactly the prologue the original shows.

__declspec(thread) int s_threadFlag = 0x3b;

class ThreadFlagGuard
{
    int m_old;
public:
    ThreadFlagGuard() : m_old(s_threadFlag) { s_threadFlag = 0x29; }
    ~ThreadFlagGuard() { s_threadFlag = m_old; }
};

// Virtual base: the object's vptr at +0 belongs to the most-derived class, so
// this stand-in only has to be polymorphic; its data runs +4..+0x5f.
class SpawnBase
{
public:
    SpawnBase();
    virtual void BaseFun();
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
};

// The 0xa0-byte object the original allocates.
class FUN_00bb0d40 : public SpawnBase
{
public:
    int unk60;
    int unk64;
    float unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int* unk90;
    int unk94;
    int unk98;
    int unk9c;

    static void* operator new(unsigned int size);
    FUN_00bb0d40();
};

FUN_00bb0d40::FUN_00bb0d40()
    : unk60(0), unk68(0.0f), unk90(0), unk98(1), unk9c(0)
{
    unk1c = 0x11;
}

class SpawnOwner
{
public:
    void CloneMemberData(FUN_00bb0d40* other, int& process);
    FUN_00bb0d40* FUN_00b33240(int& process);
};

// pdb: PrecipitationShaderProperty::CreateClone | PrecipitationShaderProperty.obj | fnv360_0822_retail, objrun, low, conflict (bridge: PrecipitationShaderProperty::PrecipitationShaderProperty)
// pdb params: arCloneData
FUN_00bb0d40* SpawnOwner::FUN_00b33240(int& process)
{
    ThreadFlagGuard guard;
    FUN_00bb0d40* p = new FUN_00bb0d40();
    CloneMemberData(p, process);
    return p;
}
}   // namespace f3m_00b33240

// @f3 0x00b2f0e0 (community match, verified in this file)
class NiRenderer;
class NiD3DVertexDeclaration;
class RefObj_bacd00;

extern NiRenderer* DAT_011f9508;

// Per-thread memory context storage. The original reads/writes the dword at
// offset 0x298 of the thread-local block; stand-in fields keep that offset.
struct MemContextStorage
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294;
    int m_context;  // 0x298
};

__declspec(thread) MemContextStorage g_MemContext;

class AutoMemContext
{
  public:
    int m_old;
    AutoMemContext(int context)
    {
        m_old = g_MemContext.m_context;
        g_MemContext.m_context = context;
    }
    ~AutoMemContext()
    {
        g_MemContext.m_context = m_old;
    }
};

struct RefObj_bacd00
{
    virtual ~RefObj_bacd00();
};

class NiD3DVertexDeclaration : public RefObj_bacd00
{
  public:
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
    virtual void SetEntry(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
    virtual void v36();
    virtual void SetEntry2(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                           unsigned int f, unsigned int g, unsigned int h);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void Finish();

    static NiD3DVertexDeclaration* Create(NiRenderer* pkRenderer, unsigned int uiStream, unsigned int uiCount);
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};

class FUN_00bacd00 : public NiMemObject
{
  public:
    FUN_00bacd00(RefObj_bacd00* pkObject);

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
    virtual void V4c();
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
    virtual void Vc0(RefObj_bacd00* pkObject);
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void V11c();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void V13c();
    virtual void V140();

    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
};

// pdb: TallGrassShader::CreateShader | TallGrassShader.obj | fnv360_0822_retail, call_gap, medium
FUN_00bacd00* FUN_00b2f0e0()
{
    AutoMemContext tempMemContext(0x1c);
    NiD3DVertexDeclaration* pDeclaration = NiD3DVertexDeclaration::Create(DAT_011f9508, 5, 1);
    pDeclaration->SetEntry(0, 0, 0, 2, 0);
    pDeclaration->SetEntry(1, 3, 3, 2, 0);
    pDeclaration->SetEntry(2, 5, 4, 3, 0);
    pDeclaration->SetEntry(3, 7, 5, 1, 0);
    pDeclaration->SetEntry2(0, 4, 6, 0x80000000, 0, 5, 1, 0);
    pDeclaration->Finish();
    FUN_00bacd00* pShader = new FUN_00bacd00(pDeclaration);
    pShader->V4c();
    pShader->V13c();
    pShader->V11c();
    pShader->V140();
    pShader->Vc0(pDeclaration);
    return pShader;
}

// @f3 0x00b30b60 (community match, verified in this file)
extern int DAT_00f73220;
namespace f3m_00b30b60 {



struct RefObject
{
    virtual void vSlot00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct PairState
{
    int x;
    short a, b;
    PairState() : x(0), a(0), b(0) {}
    ~PairState();
};

struct Color
{
    float r, g, b, a;
    Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
};

class FUN_00b2afb0
{
public:
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    int m_1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    FUN_00b2afb0();
    virtual ~FUN_00b2afb0();
};

class FUN_00b30b60 : public FUN_00b2afb0
{
public:
    Color m_60;
    NiPointer<RefObject> m_70;
    PairState m_74;
    int m_7c;
    NiPointer<RefObject> m_80;
    float m_84;
    short m_88;
    int m_8c;
    FUN_00b30b60();
    virtual ~FUN_00b30b60();
};

// pdb: SkyShaderProperty::SkyShaderProperty | SkyShaderProperty.obj | fnv360_0822_retail, call_gap, medium
FUN_00b30b60::FUN_00b30b60() : m_7c(3)
{
    m_80 = 0;
    m_84 = 0.0f;
    m_8c = 8;
    m_88 = 0;
    m_60 = *(Color*)&DAT_00f73220;
    m_1c = 12;
}
}   // namespace f3m_00b30b60

// @f3 0x00b20210 (community match, verified in this file)
extern __declspec(thread) int g_tls_298;
namespace f3m_00b20210 {
namespace task1269 {
struct NiFUN_008264c0Data
{
    float time;
    bool a, b, c, d, e;
    NiFUN_008264c0Data()
    {
        time = 0;
        a = false;
        b = false;
        c = false;
        d = false;
        e = false;
    }
};
struct NiAVObject
{
    void FUN_008264c0(const NiFUN_008264c0Data&);
};
struct FUN_00b5b090 : NiAVObject
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
    FUN_00b5b090(int);
    void FUN_00b5a000(unsigned int);
    void FUN_00b5a2a0();
    ~FUN_00b5b090()
    {
        FUN_00b5a2a0();
    }
};
struct Input
{
    int unk00, unk04, unk08, unk0c;
};
struct TagGuard
{
    int old;
    TagGuard() : old(g_tls_298)
    {
        g_tls_298 = 32;
    }
    ~TagGuard()
    {
        g_tls_298 = old;
    }
};
struct Target
{
    bool FUN_00b1e2f0(int, FUN_00b5b090*);
    bool FUN_00b20210(int, int, int, int, Input*, unsigned short);
};
// @fnv 0x00b20210
bool Target::FUN_00b20210(int a, int b, int c, int aiUnused, Input* input, unsigned short flags)
{
    int value = input->unk0c;
    TagGuard tagGuard;
    FUN_00b5b090 node(0);
    node.unk058 = a;
    node.unk05c = b;
    node.unk060 = c;
    node.FUN_00b5a000(flags);
    NiFUN_008264c0Data update;
    node.FUN_008264c0(update);
    return FUN_00b1e2f0(value, &node);
}
}  // namespace task1269
}   // namespace f3m_00b20210

// @f3 0x00b36750 (community match, verified in this file)
namespace f3m_00b36750 {
// pdb: Lighting30ShaderProperty::~Lighting30ShaderProperty | Lighting30ShaderProperty.obj | fnv360_0822_retail, objrun, low
unsigned short __stdcall FUN_00b36750(int x)
{
    return 0;
}
}   // namespace f3m_00b36750

// @f3 0x00b2ab40 (community match, verified in this file)
extern unsigned char DAT_00e9ee48;
namespace f3m_00b2ab40 {

struct FUN_00b2ab40 {
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, value58;
    void FUN_00aea2f0();
    FUN_00b2ab40();
};

// pdb: SpeedTreeBillboardShaderProperty::SpeedTreeBillboardShaderProperty | SpeedTreeBillboardShaderProperty.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSShaderTextureSet::GetTextureFilename)
FUN_00b2ab40::FUN_00b2ab40() {
    FUN_00aea2f0();
    vtable = (void*)&DAT_00e9ee48;
    value58 = 1;
    unk1c = 0xa;
}
}   // namespace f3m_00b2ab40

// @f3 0x00b2a1a0 (community match, verified in this file)
extern const char* DAT_011761b8;
namespace f3m_00b2a1a0 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00b2b9f0(ViewerStrings* strings);
    void FUN_00b2a1a0(ViewerStrings* strings);
};

// pdb: ParticleShaderProperty::GetViewerStrings | ParticleShaderProperty.obj | fnv360_0822_retail, objrun, medium
// pdb params: apStrings
void Owner::FUN_00b2a1a0(ViewerStrings* strings)
{
    FUN_00b2b9f0(strings);
    strings->Add(FUN_00847b50(DAT_011761b8));
}
}   // namespace f3m_00b2a1a0

// @f3 0x00b2ac80 (community match, verified in this file)
extern const char* DAT_011761d0;
namespace f3m_00b2ac80 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00aec6a0(ViewerStrings* strings);
    void FUN_00b2ac80(ViewerStrings* strings);
};

// pdb: SpeedTreeBillboardShaderProperty::GetViewerStrings | SpeedTreeBillboardShaderProperty.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apStrings
void Owner::FUN_00b2ac80(ViewerStrings* strings)
{
    FUN_00aec6a0(strings);
    strings->Add(FUN_00847b50(DAT_011761d0));
}
}   // namespace f3m_00b2ac80

// @f3 0x00b36640 (community match, verified in this file)
extern const char* DAT_01176338;
namespace f3m_00b36640 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00af4060(ViewerStrings* strings);
    void FUN_00b36640(ViewerStrings* strings);
};

// pdb: GeometryDecalShaderProperty::GetViewerStrings | GeometryDecalShaderProperty.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apStrings
void Owner::FUN_00b36640(ViewerStrings* strings)
{
    FUN_00af4060(strings);
    strings->Add(FUN_00847b50(DAT_01176338));
}
}   // namespace f3m_00b36640

// @f3 0x00b37f90 (community match, verified in this file)
extern const char* DAT_01176530;
namespace f3m_00b37f90 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00aec6a0(ViewerStrings* strings);
    void FUN_00b37f90(ViewerStrings* strings);
};

// pdb: Lighting30ShaderProperty::GetViewerStrings | Lighting30ShaderProperty.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apStrings
void Owner::FUN_00b37f90(ViewerStrings* strings)
{
    FUN_00aec6a0(strings);
    strings->Add(FUN_00847b50(DAT_01176530));
}
}   // namespace f3m_00b37f90

// @f3 0x00b39500 (community match, verified in this file)
extern const char* DAT_0116fde4;
namespace f3m_00b39500 {
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00b2b9f0(ViewerStrings* strings);
    void FUN_00b39500(ViewerStrings* strings);
};

// pdb: BSDistantTreeShaderProperty::GetViewerStrings | BSDistantTreeShaderProperty.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apStrings
void Owner::FUN_00b39500(ViewerStrings* strings)
{
    FUN_00b2b9f0(strings);
    strings->Add(FUN_00847b50(DAT_0116fde4));
}
}   // namespace f3m_00b39500

// @f3 0x00b3b7a0 (community match, verified in this file)
namespace f3m_00b3b7a0 {
struct FUN_00b3b7a0_Base : f3_0251::FUN_00b22630
{
    void FUN_00b3b7a0();
};

struct FUN_00b22380_Callee
{
    void FUN_00b22380(bool flag);
};

// pdb: ImageSpaceEffectVATSScan::ReturnTextures | ImageSpaceEffectVATSScan.obj | fnv360_0822_retail, objopen_prop, low
void FUN_00b3b7a0_Base::FUN_00b3b7a0()
{
    f3_0251::DAT_011765dc = (f3_0251::ISTexRef*)0;
    for (int i = 0; i < 5; ++i)
    {
        f3_0251::FUN_00b22590* e = m_textures.m_pBase[i];
        if (e)
            ((FUN_00b22380_Callee*)e)->FUN_00b22380(false);
    }
}
}   // namespace f3m_00b3b7a0

// @f3 0x00b20340 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
#include <string.h>
namespace PortB20340 {
struct NiPoint3 {
    float x,y,z;
    void FUN_00468d00();
    NiPoint3* NiPoint3_UnitCross(NiPoint3*,const NiPoint3&) const;
    NiPoint3* FUN_00432b40(NiPoint3*,float) const;
    NiPoint3& FUN_00432b70(const NiPoint3&);
    float FUN_00432bd0() const;
};
struct NiBound {float x,y,z,radius;};
struct NiTransform { float rotate[3][3]; NiPoint3 m_Translate; float m_fScale; };
struct NiUpdateData {float fTime; bool pad1,pad2,pad3,pad4,pad5;};
struct NiFrustum {
 float m_fLeftBound,m_fRightBound,m_fTopBound,m_fBottomBound,m_fNearPlane,m_fFarPlane;
 bool m_bOrthographic;
 void FUN_0083bf50(unsigned char);
};
template<class T> struct NiRect {T m_fMinimumU,m_fMaximumU,m_fMinimumV,m_fMaximumV;};
struct NiRefObject {
 virtual void Destroy();
 virtual void DeleteThis();
 unsigned int m_uiRefCount;
 void IncRefCount() {InterlockedIncrement((volatile long*)&m_uiRefCount);}
 void DecRefCount() {if(!InterlockedDecrement((volatile long*)&m_uiRefCount)) DeleteThis();}
};
template<class T> struct NiPointer {
 T* m_pObject;
 inline NiPointer& operator=(T* p) {
   if(m_pObject!=p) {
     if(m_pObject) ((NiRefObject*)m_pObject)->DecRefCount();
     m_pObject=p;
     if(m_pObject) ((NiRefObject*)m_pObject)->IncRefCount();
   } return *this;
 }
};
struct NiPointerDispatch {void FUN_008e9650(NiRefObject*);};
struct ShadowExtraData {unsigned int unk00,unk04,unk08; NiPoint3 offset,extent;};
struct NiAVObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
 NiBound* m_kWorldBound;
 unsigned int propertyHead,propertyTail,propertyCount,m_uFlags;
 NiTransform m_kLocal,m_kWorld;
 ShadowExtraData* FUN_00824a50(const void*);
 void FUN_008264c0(NiUpdateData&);
};
struct NiLight : NiAVObject {
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
 struct {float r,g,b;} m_kSpec;
};
struct BSRenderedTexture;
struct BSTextureManager {
 BSRenderedTexture* FUN_00af07e0();
 void FUN_00af08b0(BSRenderedTexture*);
};
struct FUN_0083b6d0 : NiAVObject {
 float worldToCamera[4][4];
 NiFrustum m_kViewFrustum;
 float minNear,maxFarNear;
 NiRect<float> viewport;
 float lod;
 FUN_0083b6d0();
 static void* operator new(unsigned int n) {return FUN_0089eb90(n);}
 static void operator delete(void* p,unsigned int n) {FUN_0089ec10(p,n);}
 static void* FUN_0089eb90(unsigned int);
 static void FUN_0089ec10(void*,unsigned int);
 bool FUN_0083a590(const NiPoint3&,const NiPoint3&);
 void FUN_00839f90(const NiFrustum&);
 void FUN_0061dc20(const NiRect<float>&);
 bool FUN_0083a460(const NiBound&);
};
typedef FUN_0083b6d0 NiCamera;
struct NiFrustumPlanes {
 float planes[6][4]; unsigned int mask;
 void FUN_0083ecb0(const NiFrustum*,const NiTransform*);
};
struct BSShaderAccumulator {
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
 unsigned int eRenderMode;
 void FUN_00b1f2c0(void*);
};
struct ShadowAccumulator : BSShaderAccumulator {
 void SetPass(unsigned int pass) {eRenderMode=pass;}
};
struct ShadowEvents {
 void FUN_00b0d1f0(int,unsigned char*);
 void FUN_00b0d4a0(NiCamera*,int,NiAVObject*,int,int,BSShaderAccumulator*,int,unsigned char*,int);
};
extern BSTextureManager* DAT_0116ef98;
extern int DAT_0116efb0,DAT_0116efa0,DAT_0116efc8;
extern double DAT_00e112b0,DAT_00dcf568,DAT_00e9e7a8;
extern double DAT_00de73d0,DAT_00dc2df8,DAT_00dc2d10,DAT_00e00d20,DAT_00dba5c8;
extern float DAT_00dc2e08;
extern NiPoint3 DAT_00f725b0,DAT_00f72598,DAT_0108ec68;
extern NiBound DAT_0108edc8;
extern const void* DAT_0116da80;
extern ShadowEvents DAT_01175720;
float FUN_00401e20(float,float);
float FUN_0090d870(float,float);
bool FUN_00530bb0();
BSShaderAccumulator* BSShaderManager_GetNextAvailableShadowMapAccumulator();
inline void ShadowSet(NiPoint3& v,float x,float y,float z) {v.x=x;v.y=y;v.z=z;}
inline NiPoint3* ShadowCross(const NiPoint3& v,NiPoint3* r,const NiPoint3& o) {return v.NiPoint3_UnitCross(r,o);}
__forceinline NiPoint3* ShadowScale(const NiPoint3& v,NiPoint3* r,float s) {return v.FUN_00432b40(r,s);}
inline float ShadowOrderedScale(const NiAVObject* o) {_ReadWriteBarrier();return o->m_kWorld.m_fScale;}
inline float ShadowRadius(const NiBound& b) {return b.radius;}
inline void ShadowEnabled(int& result) {result=(DAT_0116efc8&0x10)>0;}
inline int ShadowEnabledValue() {int result;ShadowEnabled(result);return result;}
struct ShadowSceneCameraUpdate {
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
 float fShadowLODDimmer;
 unsigned int unkD8,unkDC,unkE0,unkE4,unkE8;
 bool bCastShadow,bCubeShadowMap; unsigned short unkEE;
 unsigned int unkF0,unkF4;
 NiPointer<NiLight> spLight;
 unsigned int unkFC; NiPoint3 point;
 NiPointer<BSRenderedTexture> spDynamicShadowMap;
 unsigned short usFrustumCull,unk112;
 unsigned int unk114;
 bool bShadowSpotlight; unsigned char unk119;unsigned short unk11A;
 float fSpotlightFOV,fSpotlightFalloff;
 unsigned int unk124;
 NiPointer<NiAVObject> spShadowScene;
 unsigned int unk12C,unk130,unk134,unk138,unk13C;
 NiPointer<NiCamera> spShadowCamera;
 NiFrustumPlanes kShadowCameraPlanes;
 float pfClipSpacePlanes[24];
 unsigned int unk208;
 NiPointer<BSShaderAccumulator> spShadowAccumulator;
 NiAVObject* GetShadowScene() const {return spShadowScene.m_pObject;}
 NiLight* GetLight() const {return spLight.m_pObject;}
 bool CastsShadow() const {return bCastShadow;}
 NiCamera* GetShadowCamera() {return spShadowCamera.m_pObject;}
 void FUN_00ae1780(BSRenderedTexture*);
 void FUN_00b20340(void*,unsigned char*);
};
// pdb: ShadowSceneLight::MTSetupFrustumDepthMap | ShadowSceneLight.obj | fnv360_0822_retail, uconst, low
// pdb params: arCuller, aiIndex
void ShadowSceneCameraUpdate::FUN_00b20340(void* unused, unsigned char* renderFlags)
{
    bool updateShadow = true;
    if (!(CastsShadow() && DAT_0116efb0 >= 3 && (unsigned char)ShadowEnabledValue()) && !bShadowSpotlight)
        updateShadow = false;

    if (!spDynamicShadowMap.m_pObject)
    {
        BSRenderedTexture* texture = DAT_0116ef98->FUN_00af07e0();
        if (!texture)
            reinterpret_cast<NiAVObject*>(spLight.m_pObject)->m_uFlags |= 1;
        FUN_00ae1780(texture);
    }

    if (updateShadow && usFrustumCull != 255 && fShadowLODDimmer > DAT_00e112b0 &&
        spDynamicShadowMap.m_pObject)
    {
        NiTransform lightTransform = GetLight()->m_kWorld;
        NiPoint3 a;
        NiPoint3 b;
        NiPoint3 c;
        NiPoint3 d;
        NiPoint3 e;
        ShadowSet(
            a,
            spShadowScene.m_pObject->m_kWorld.m_Translate.x - lightTransform.m_Translate.x,
            spShadowScene.m_pObject->m_kWorld.m_Translate.y - lightTransform.m_Translate.y,
            spShadowScene.m_pObject->m_kWorld.m_Translate.z -
                lightTransform.m_Translate.z);
        a.FUN_00468d00();
        ShadowSet(e, -DAT_00f725b0.x, -DAT_00f725b0.y, -DAT_00f725b0.z);
        ShadowCross(a, &b, e);
        if (b.x < DAT_00dcf568 && b.x > DAT_00e9e7a8 && b.y < DAT_00dcf568 && b.y > DAT_00e9e7a8 &&
            b.z < DAT_00dcf568 && b.z > DAT_00e9e7a8)
        {
            e = DAT_00f72598;
            const NiPoint3* __restrict cross = ShadowCross(a, &c, e);
            b = *cross;
        }
        memcpy(&e, ShadowCross(a, &c, b), sizeof(e));
        NiFrustum frustum;
        frustum.FUN_0083bf50(false);
        frustum.m_bOrthographic = true;
        ShadowExtraData* pExtraData =
            reinterpret_cast<ShadowExtraData*>(GetShadowScene()->FUN_00824a50(DAT_0116da80));
        float radius;
        {
            NiAVObject* __restrict scene = spShadowScene.m_pObject;
            {
                const NiPoint3* __restrict origin = &scene->m_kWorld.m_Translate;
                a = *origin;
            }
            {
                const NiPoint3* __restrict extent =
                    pExtraData ? ShadowScale(pExtraData->extent, &c, scene->m_kWorld.m_fScale) : &DAT_0108ec68;
                d = *extent;
            }
            const NiBound* bound = reinterpret_cast<NiBound*>(scene->m_kWorldBound);
            if (!bound)
                bound = &DAT_0108edc8;
            radius = FUN_0090d870(DAT_00dc2e08, FUN_00401e20(float(d.x * DAT_00de73d0),
                                                             FUN_00401e20(float(d.y * DAT_00de73d0),
                                                                          FUN_00401e20(float(d.z * DAT_00de73d0),
                                                                                       ShadowRadius(*bound)))));
        }
        NiAVObject* light = static_cast<NiAVObject*>(spLight.m_pObject);
        float distance;
        ShadowSet(c, light->m_kWorld.m_Translate.x - a.x,
                          light->m_kWorld.m_Translate.y - a.y, light->m_kWorld.m_Translate.z - a.z);
        distance = static_cast<const NiPoint3&>(c).FUN_00432bd0();
        fSpotlightFOV = float((radius / distance) * DAT_00dc2df8);
        frustum.m_fLeftBound = -radius;
        frustum.m_fBottomBound = -radius;
        frustum.m_fRightBound = radius;
        frustum.m_fTopBound = radius;
        frustum.m_fNearPlane = 1.0f;
        frustum.m_fFarPlane = static_cast<NiLight*>(light)->m_kSpec.r;
        __declspec(align(16)) NiRect<float> viewport;
        viewport.m_fMaximumV = viewport.m_fMinimumU = 0.0f;
        viewport.m_fMinimumV = viewport.m_fMaximumU = 1.0f;

        if (bCastShadow && FUN_00530bb0())
        {
            reinterpret_cast<NiPointerDispatch&>(spShadowAccumulator).FUN_008e9650(reinterpret_cast<NiRefObject*>(BSShaderManager_GetNextAvailableShadowMapAccumulator()));
            reinterpret_cast<ShadowAccumulator*>(spShadowAccumulator.m_pObject)->SetPass(7);
            if (!GetShadowCamera())
            {
                NiCamera* camera = new NiCamera;
                reinterpret_cast<NiPointerDispatch&>(spShadowCamera).FUN_008e9650(reinterpret_cast<NiRefObject*>(camera));
            }
            memcpy(&GetShadowCamera()->m_kLocal.m_Translate, &lightTransform.m_Translate,
                   sizeof(lightTransform.m_Translate));
            reinterpret_cast<NiUpdateData&>(a).fTime = 0.0f;
            reinterpret_cast<NiUpdateData&>(a).pad1 = false;
            reinterpret_cast<NiUpdateData&>(a).pad2 = false;
            reinterpret_cast<NiUpdateData&>(a).pad3 = false;
            reinterpret_cast<NiUpdateData&>(a).pad4 = false;
            reinterpret_cast<NiUpdateData&>(a).pad5 = false;
            GetShadowCamera()->FUN_008264c0(reinterpret_cast<NiUpdateData&>(a));
            memcpy(&b, &spShadowScene.m_pObject->m_kWorld.m_Translate,
                   sizeof(b));
            pExtraData = reinterpret_cast<ShadowExtraData*>(spShadowScene.m_pObject->FUN_00824a50(DAT_0116da80));
            NiPoint3 tempOffset;
            NiAVObject* __restrict scaleSource = spShadowScene.m_pObject;
            float scale = static_cast<const volatile float&>(scaleSource->m_kWorld.m_fScale);
            NiPoint3* __restrict output = &tempOffset;
            const NiPoint3* input = &pExtraData->offset;
            b.FUN_00432b70(*ShadowScale(*input, output, scale));
            ShadowScale(pExtraData->extent, &c, ShadowOrderedScale(spShadowScene.m_pObject));
            if (c.z > c.x + c.y)
            {
                c.x = float(DAT_00f725b0.x * DAT_00dc2d10);
                c.y = float(DAT_00f725b0.y * DAT_00dc2d10);
                c.z = float(DAT_00f725b0.z * DAT_00dc2d10);
                b.x = c.x + b.x;
                b.y = c.y + (*static_cast<const volatile float*>(&b.y));
                b.z = c.z + (*static_cast<const volatile float*>(&b.z));
            }
            GetShadowCamera()->FUN_0083a590(b, e);
            GetShadowCamera()->FUN_00839f90(frustum);
            GetShadowCamera()->FUN_0061dc20(viewport);
            reinterpret_cast<NiUpdateData&>(d).fTime = 0.0f;
            reinterpret_cast<NiUpdateData&>(d).pad1 = false;
            reinterpret_cast<NiUpdateData&>(d).pad2 = false;
            reinterpret_cast<NiUpdateData&>(d).pad3 = false;
            reinterpret_cast<NiUpdateData&>(d).pad4 = false;
            reinterpret_cast<NiUpdateData&>(d).pad5 = false;
            GetShadowCamera()->FUN_008264c0(reinterpret_cast<NiUpdateData&>(d));
            float nearPlane = frustum.m_fNearPlane;
            float farPlane = frustum.m_fFarPlane;
            NiAVObject* __restrict boundSource = spShadowScene.m_pObject;
            const NiBound* bound = reinterpret_cast<NiBound*>(boundSource->m_kWorldBound);
            if (!bound)
                bound = &DAT_0108edc8;
            GetShadowCamera()->FUN_0083a460(*bound);
            static_cast<NiFrustum&>(frustum) = GetShadowCamera()->m_kViewFrustum;
            frustum.m_fFarPlane = float(frustum.m_fFarPlane + DAT_00e00d20);
            if (!DAT_0116efa0)
                frustum.m_fNearPlane = float(frustum.m_fFarPlane * DAT_00dba5c8);
            kShadowCameraPlanes.FUN_0083ecb0(&frustum, &GetShadowCamera()->m_kWorld);
            frustum.m_fNearPlane = nearPlane;
            frustum.m_fFarPlane = farPlane;
            GetShadowCamera()->FUN_00839f90(frustum);
            reinterpret_cast<ShadowAccumulator*>(spShadowAccumulator.m_pObject)->FUN_00b1f2c0(this);
            DAT_01175720.FUN_00b0d4a0(spShadowCamera.m_pObject, 0, spShadowScene.m_pObject, 0, 0,
                                      spShadowAccumulator.m_pObject, 0, renderFlags + 0x11, 0);
        }
    }
    else if (spDynamicShadowMap.m_pObject)
    {
        DAT_0116ef98->FUN_00af08b0(spDynamicShadowMap.m_pObject);
        spDynamicShadowMap = 0;
        spShadowAccumulator = 0;
    }
    DAT_01175720.FUN_00b0d1f0(0, renderFlags + 0x11);
}
}

// @f3 0x00b366e0 (community match, verified in this file)
namespace f3m_00b366e0 {
namespace f3m_00b366e0 {
struct Base
{
    Base();
    virtual ~Base();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_i1c;
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
    int m_i58;
};
struct Parent
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
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void Attach(Base* child);
};
}

struct FUN_00b366e0 : f3m_00b366e0::Base
{
    FUN_00b366e0(f3m_00b366e0::Parent* parent);
    virtual ~FUN_00b366e0();
};

// pdb: Lighting30ShaderProperty::Lighting30ShaderProperty | Lighting30ShaderProperty.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: aPPLightingProp
FUN_00b366e0::FUN_00b366e0(f3m_00b366e0::Parent* parent)
{
    parent->Attach(this);
    m_i58 = 0x1d;
    m_i1c = 0xb;
}
}   // namespace f3m_00b366e0

// @f3 0x00b35f80 (community match, verified in this file)
namespace f3m_00b35f80 {
struct FUN_00b35bc0 {
 virtual ~FUN_00b35bc0();
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 FUN_00b35bc0(void*);
};
struct FUN_00b35f80 : FUN_00b35bc0 {
 virtual ~FUN_00b35f80();
 FUN_00b35f80(void*);
};
// pdb: SpeedTreeBranchShaderProperty::SpeedTreeBranchShaderProperty | SpeedTreeBranchShaderProperty.obj | fnv360_0822_retail, call_gap, low
// pdb params: apData
FUN_00b35f80::FUN_00b35f80(void* arg) : FUN_00b35bc0(arg) {
 unk58=4;
 unk1c=9;
}
}   // namespace f3m_00b35f80

// @f3 0x00b2c830 (community match, verified in this file)
extern __declspec(thread) int g_tls_298;
namespace f3m_00b2c830 {
struct AllocationGuardB2c830 {
 int old;
 AllocationGuardB2c830():old(g_tls_298){g_tls_298=0x1c;}
 ~AllocationGuardB2c830(){g_tls_298=old;}
};
struct CallerB2c830 {
 virtual void slot00();
 virtual void slot01();
 virtual void slot02();
 virtual void slot03();
 virtual void slot04();
 virtual void slot05();
 virtual void slot06();
 virtual void slot07();
 virtual void slot08();
 virtual void slot09();
 virtual void slot0a();
 virtual void slot0b();
 virtual void slot0c();
 virtual void slot0d();
 virtual void slot0e();
 virtual void slot0f();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot1a();
 virtual void slot1b();
 virtual void slot1c();
 virtual void slot1d();
 virtual void slot1e();
 virtual void slot1f();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot2a();
 virtual void slot2b();
 virtual void slot2c();
 virtual void slot2d();
 virtual void slot2e();
 virtual void slot2f();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot3a();
 virtual void slot3b();
 virtual void slot3c();
 virtual void slot3d();
 virtual void slot3e();
 virtual void slot3f();
 virtual void slot40();
 virtual void slot41();
 virtual void slot42();
 virtual void slot43();
 virtual void slot44();
 virtual void slot45();
 virtual void slot46();
 virtual void slot47();
 virtual void slot48();
 virtual void slot49();
 virtual void slot4a();
 virtual void slot4b();
 virtual void slot4c();
 virtual void slot4d();
 bool FUN_0088d360();
 bool FUN_00b2c830();
};
// pdb: TallGrassShader::Initialize | TallGrassShader.obj | fnv360_0822_retail, caller_sim, medium
bool CallerB2c830::FUN_00b2c830() {
 AllocationGuardB2c830 guard;
 bool result=FUN_0088d360();
 if(result) {slot4b();slot4d();slot4c();result=true;}
 return result;
}
}   // namespace f3m_00b2c830
