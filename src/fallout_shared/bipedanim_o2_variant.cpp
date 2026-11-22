#include "f3_common.h"
// src/fallout_shared/bipedanim_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bipedanim.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bipedanim_decls.h"

extern int EmptyFS;
struct NiShader
{
    const NiFixedString& GetFilename() const;
};
struct Holder
{
    bool NiObjectNET_InsertExtraData(NiTexture* pkTex);
    bool NiObjectNET_AddExtraData(const NiFixedString& kName, NiTexture* pkTex);
};
// @fnv 0x00a5bc40
// pdb: NiObjectNET::AddExtraData | NiObjectNET.obj | fnv360_0822_debug, objrun + bridge(call_gap|caller) + skyrim(caller_sim), high
bool Holder::NiObjectNET_AddExtraData(const NiFixedString& kName, NiTexture* pkTex)
{
    if ((int)kName.data == EmptyFS)
        return false;
    if (!pkTex)
        return false;
    if (((NiShader*)pkTex)->GetFilename().data == (const char*)EmptyFS)
    {
        ((NiAVObject*)pkTex)->SetName(kName);
    }
    else
    {
        if (kName.data != ((NiShader*)pkTex)->GetFilename().data)
            return false;
    }
    return NiObjectNET_InsertExtraData(pkTex);
}

struct FUN_00b553d0_PropertyLayout
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
    NiPoint3 value;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int count;
};

struct FUN_00b553d0_NodeLayout
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
    NiAVObject** children;
    unsigned short unkA4;
    unsigned short childCount;
};

// @fnv 0x00b553d0
// pdb: BSShaderManager::SetEmittanceRecurse | BSShaderManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, aColor
void __cdecl FUN_00b553d0(NiGeometry* pObject, NiPoint3* pValue)
{
    if (pObject == 0)
        return;

    if (pObject->IsGeometry() != 0)
    {
        NiProperty* pFirst = pObject->GetProperty(2);
        NiProperty* pSecond = pObject->GetProperty(3);

        if (pFirst != 0 && pSecond != 0)
        {
            FUN_00b553d0_PropertyLayout* pFirstLayout = (FUN_00b553d0_PropertyLayout*)pFirst;
            FUN_00b553d0_PropertyLayout* pSecondLayout = (FUN_00b553d0_PropertyLayout*)pSecond;

            if ((pSecondLayout->unk20 & 0x20000000u) <= 0)
                return;

            pFirstLayout->value = *pValue;
            ++pFirstLayout->count;
        }
        return;
    }

    NiNode* pNode = pObject->IsSceneNode();
    if (pNode == 0)
        return;

    FUN_00b553d0_NodeLayout* pNodeLayout = (FUN_00b553d0_NodeLayout*)pNode;

    unsigned int count = pNodeLayout->childCount;
    for (unsigned int i = 0; i < count; ++i)
    {
        NiAVObject* pChild = pNodeLayout->children[i];
        if (pChild != 0)
            FUN_00b553d0((NiGeometry*)pChild, pValue);
    }
}

struct NiStub10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class NiController
{
  public:
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual NiStub10* GetTarget();
};

struct SceneNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SceneNode* m_parent;
    NiController* m_controller;
    SceneNode* GetParent() const
    {
        return m_parent;
    }
};

class NiGlobalStringTable
{
  public:
    static char* AddString(const char* s);
};

struct BackpackName
{
    char* m_data;
    BackpackName(const char* s)
    {
        m_data = NiGlobalStringTable::AddString(s);
    }
    ~BackpackName();
};
