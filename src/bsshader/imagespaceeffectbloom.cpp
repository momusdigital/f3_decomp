// bsshader/imagespaceeffectbloom.cpp: free functions (1 function)
#include "f3_common.h"
#include "imagespaceeffectbloom_decls.h"

// @fnv 0x00c03410
// pdb: ImageSpaceEffectSunbeams::Setup | ImageSpaceEffectSunbeams.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apManager, apParam
void BloomImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param)
{
    SetTextureArrayCount(2);
    pTextures.SetSize(3);

    ImageSpaceShaderParam* firstParam = new ImageSpaceShaderParam;
    firstParam->AllocateShaderConstants(0, 1);
    pEffectParamList.SetAt(0, firstParam);
    SetEffectParamAt(0, 1, 0);
    SetEffectAt(0, manager->GetEffect(39), firstParam, 2);

    ImageSpaceShaderParam* secondParam = new ImageSpaceShaderParam;
    secondParam->AllocateShaderConstants(0, 1);
    pEffectParamList.SetAt(1, secondParam);
    SetEffectParamAt(1, 2, 0);
    SetEffectAt(1, manager->GetEffect(57), secondParam, 0);
    secondParam->SetShaderConstantVector4(0, DAT_012023f4, DAT_012023f8, 0.0f, 0.0f);
}
