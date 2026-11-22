#include <windows.h>
// src/f3staging/f3blk_00ae0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00afc480 (community match, verified in this file)
namespace f3m_00afc480 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }

    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }

    volatile long referenceCount;
};

struct RenderScale
{
    float x, y, z, w;

    __forceinline RenderScale(float xValue, float yValue, float zValue, float wValue)
        : x(xValue), y(yValue), z(zValue), w(wValue) {}
};

extern float DAT_01178188;
extern RenderScale DAT_011736d4;

class RenderPassBase
{
public:
    RenderPassBase();
    virtual ~RenderPassBase();

    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24;
    NiPointer<NiRefObject> primary;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned int unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int state;
    unsigned int unk64;
    unsigned int mode;
};

class RenderPass : public RenderPassBase
{
public:
    RenderPass(NiRefObject* first, NiRefObject* second, NiRefObject* third, NiRefObject* fourth);
    virtual ~RenderPass();

    NiPointer<NiRefObject> object6C;
    NiPointer<NiRefObject> object70;
    NiPointer<NiRefObject> object74;
    NiPointer<NiRefObject> object78;
    NiPointer<NiRefObject> object7C;
    NiPointer<NiRefObject> object80;
    NiPointer<NiRefObject> object84;
    NiPointer<NiRefObject> object88;
};

// pdb: ShadowLightShader::ShadowLightShader | ShadowLightShader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apShaderDecl, apSkinnedShaderDecl, apModelSpaceNormShaderDecl, apSplatTexturingShaderDecl
RenderPass::RenderPass(NiRefObject* first, NiRefObject* second, NiRefObject* third, NiRefObject* fourth)
{
    mode = 1;
    primary = first;
    object6C = first;
    object70 = second;
    object74 = third;
    object78 = fourth;

    NiRefObject* empty = 0;
    object80 = empty;
    object7C = empty;
    object88 = empty;
    object84 = empty;

    DAT_011736d4 = RenderScale(1.0f / DAT_01178188, 0.0f, 0.0f, 0.0f);
    state = 0;
}
}   // namespace f3m_00afc480
