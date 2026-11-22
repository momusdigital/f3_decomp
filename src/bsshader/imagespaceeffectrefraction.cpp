// bsshader/imagespaceeffectrefraction.cpp: free functions (4 functions)
#include "f3_common.h"
#include "imagespaceeffectrefraction_decls.h"

// @fnv 0x00bd9420
// pdb: ImageSpaceEffectRefraction::Setup | ImageSpaceEffectRefraction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apManager, apParam
void RefractionImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam*)
{
    SetTextureArrayCount(1);
    pTextures.SetSize(3);
    ImageSpaceShaderParam* shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 1);
    WaterTintRecord waterTint = g_waterTintRecords[0];
    shaderParam->SetShaderConstantVector4(0, waterTint.r, waterTint.g, waterTint.b, waterTint.a);
    pEffectParamList.SetAt(0, shaderParam);
    SetTextureArrayAt(0, 1, 2, 0, 0);
    SetEffectAt(0, manager->pEffectList.m_pBase[41], shaderParam, 0);
}

// @f3 0x00b5b5a0 (community match, verified in this file)
// pdb: ImageSpaceEffectRefraction::GetNormalsTexture | ImageSpaceEffectRefraction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: abCreate
BSRenderedTexture* RefractionImageSpaceEffect::GetRefractionTexture(bool create)
{
    if (!m_kRefractionTexture.GetTexture() && create)
    {
        DAT_011bf400 = 0;
        m_kRefractionTexture.FUN_00ba37a0(
            DAT_011f91a8->CreateRenderTargetTexture(NiRenderer::ms_pRenderer, 0x1e, 0, 0, 0));
        DAT_011bf400 = 1;
    }
    return m_kRefractionTexture.FUN_00ba3770();
}


// @fnv 0x00bd93d0
// pdb: ImageSpaceEffectRefraction::ImageSpaceEffectRefraction | ImageSpaceEffectRefraction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
RefractionImageSpaceEffect::RefractionImageSpaceEffect()
{
    ImageSpaceTexture& texture = m_kRefractionTexture;
    *(void** volatile*)&m_ppVirtualMethodTable = DAT_010bc560;
    texture.m_bTextureFlag1 = false;
    texture.m_bTextureFlag2 = false;
    texture.m_bTextureFlag3 = false;
    texture.pTexture = 0;
    texture.m_eTextureFilterMode = 0;
    texture.m_eClampMode = 0;
}

struct X
{
    void FUN_00bd9160();
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00bd9160, then deallocates this via g_memoryManager if flag has bit 1 set, and returns this.
// @fnv 0x00bd9400
// pdb: ExtraReflectorRefs::`scalar deleting destructor' | ExtraDataList.obj | fnv360_0822_retail, vtable, medium
void* X::ReleaseIfFlagged(unsigned int flag)
{
    FUN_00bd9160();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
