#include "f3_common.h"
#include "bsrenderstate_packet_decls.h"
// @fnv 0x00b6b790
// pdb: BSRenderedTexture::StopOffscreen | BSRenderedTexture.obj | fnv360_0822_retail, call_gap, medium
void BSRenderedTexture::EndAllAndResetRendererState()
{
    NiRenderer* renderer = NiRenderer::ms_pRenderer;
    EndAll();
    if (renderer->state == 2 && renderer->vfn_180())
        renderer->state = 0;
}
// @fnv 0x00b97fa0
// pdb: BSRenderState::SetAlphaBlendEnable | BSRenderState_Xenon.obj | fnv360_1110_retail, call_seq, medium
// pdb params: abEnabled, aeLock
void BSRenderStateManager::SetDepthBufferEnabled(bool enable, BSRENDERSTATE_LOCK lock)
{
    unsigned int index = DAT_011ffa9c;
    if (DAT_011ff9d8[index] == 0)
        g_pkRenderer->device->SetRenderState(27, enable, 0, 0);
    DAT_011ff9d8[index] += lock;
}
// @fnv 0x00b98380
// pdb: BSRenderState::SetColorWriteEnable | BSRenderState_Xenon.obj | fnv360_0822_retail, call_gap, medium
// pdb params: auiMask, aeLock
void BSRenderStateManager::SetColorWriteMask(unsigned int mask, BSRENDERSTATE_LOCK lock)
{
    unsigned int index = DAT_011ffcd0;
    if (DAT_011ff9d8[index] == 0)
        g_pkRenderer->device->SetRenderState(168, mask, 0, 0);
    DAT_011ff9d8[index] += lock;
}
