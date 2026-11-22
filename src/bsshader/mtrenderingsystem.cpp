// bsshader/mtrenderingsystem.cpp: TaskThreadManager, AILinearTaskThread (3 functions)
#include "f3_common.h"
#include "mtrenderingsystem_decls.h"
// @fnv 0x004ea970

#pragma optimize("gty", on)
// @fnv 0x00ba3720
// pdb: MTRenderingSystem::CreateThreads | MTRenderingSystem.obj | fnv360_0822_retail, ustr, high
// pdb: MTRenderingSystem::CreateThreads | MTRenderingSystem.obj | fnv360_0822_retail, ustr, high (was: StartRenderingTaskThread)
void TaskThreadManager::MTRenderingSystem_CreateThreads()
{
    if (DAT_011f94b4)
        LaunchWorkerThread(1, DAT_01200080, FUN_00ba3190, "Rendering Task Thread 2", 0x20000);
}
#pragma optimize("", off)

#pragma optimize("gty", on)
// Ends all rendered textures, then advances the renderer state from 1 to 3 or from 3 to 0 and increments frameCount when the matching check passes.
// @fnv 0x00b6b730
// pdb: BSShaderManager::RenderDebugTexture | BSShaderManager.obj | fnv360_0822_debug, callee_sim, low
void TaskThreadManager::EndRenderingTaskThread()
{
    NiRenderer* renderer = NiRenderer::ms_pRenderer;
    BSRenderedTexture::EndAll();
    if (renderer->state == 1 && renderer->vfn_180())
        renderer->state = 3;
    if (renderer->state == 3 && renderer->vfn_184())
    {
        ++renderer->frameCount;
        renderer->state = 0;
    }
}
#pragma optimize("", off)
