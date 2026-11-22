// fallout/interface/fovatseffectmanager.cpp: ShadowLightData, EffectSetting (3 functions)
#include "f3_common.h"
extern unsigned __int64 selected_target_masks[43];

#include "fovatseffectmanager_targets.h"

// Stores targetMask at selected_target_masks[selectedIndex] and sets or clears the selectedIndex bit in each of the 43 mask words according to targetMask.
// @fnv 0x00c82870
// pdb: bhkCollisionFilter::SetMultiLayerCollision | bhkCollisionFilter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeA, uiLayerBits
void ShadowLightData::SetTargetMaskForSelection(unsigned int selectedIndex, unsigned __int64 ullTargetMask)
{
    unsigned __int64 ullSelectedBit = ((unsigned __int64)1) << selectedIndex;
    selected_target_masks[selectedIndex] = ullTargetMask;

    unsigned __int64 ullTestBit = 1;
    unsigned int byteOffset = 0;
    do
    {
        unsigned __int64* pullMaskWord = (unsigned __int64*)((unsigned char*)selected_target_masks + byteOffset);
        if (ullTargetMask & ullTestBit)
            *pullMaskWord |= ullSelectedBit;
        else
            *pullMaskWord &= ~ullSelectedBit;
        ullTestBit <<= 1;
        byteOffset += 8;
    } while (byteOffset < 0x158);
}

#pragma optimize("", off)
#include "fovatseffectmanager_perks.h"

#include "fovatseffectmanager_effects.h"

// Initializes the EffectSetting data fields to defaults, reads two game-setting floats, and sets the form type to 0x10.
// @fnv 0x00407020
EffectSetting::EffectSetting()
{
    data.iFlags = 0;
    data.m_fBaseCost = 0.0f;
    data.m_pAssociatedForm = 0;
    data.m_iAssociatedActorValue = -1;
    data.m_iAssociatedSkill = -1;
    data.m_iResistanceActorValue = -1;
    data.m_sCounterEffectCount = 0;
    data.apTargetLight = 0;
    data.m_pEffectShader = 0;
    data.m_pEnchantEffectShader = 0;
    data.fSpeed = 1.0f;
    data.m_pCastSound = 0;
    data.m_pBoltSound = 0;
    data.m_pContactSound = 0;
    data.m_pAreaEffectSound = 0;
    data.m_fEnchantmentFactor = ((SettingT_GameSettingCollection_&)g_011c36c0).Float()->f;
    data.m_fBarterFactor = ((SettingT_GameSettingCollection_&)g_011c37e8).Float()->f;
    data.m_eEffectTypeItem = 0;
    m_iActorValue = 0;
    m_iEffectID = 0;
    m_pEffectSettingCallback = 0;
    m_pPredicateData = 0;
    SetFormType((ENUM_FORM_ID)0x10);
}

// @fnv 0x007f7610
ShadowLightData::ShadowLightData() : m_spTargetObject(0)
{
    pShaderParams = new ImageSpaceShaderParam;
    pShaderParams->AllocateShaderConstants(0, 0);
    pShaderParams->m_bTextureFlags[1] = false;
    pShaderParams->m_bTextureFlags[2] = false;
    pShaderParams->m_eShaderFilterMode = (NiTexturingProperty__FilterMode)1;
    m_spTargetObject = 0;
    state.enabled = false;
    point3 = DAT_011f4980;
    effectEnabled = false;
    intensity = ((SettingT_GameSettingCollection_&)g_011db25c).Float()->f;
    radius = ((SettingT_GameSettingCollection_&)g_011db238).Float()->f;
    duration = ((SettingT_GameSettingCollection_&)g_011db200).Float()->f;
}
