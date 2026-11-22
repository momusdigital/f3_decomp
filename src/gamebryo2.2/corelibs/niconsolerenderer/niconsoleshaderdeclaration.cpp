#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRenderer
{
    void* m_auiShapeKeys[0x6e8 / 4];
    unsigned int m_maxStreamEntries;
};

struct BSFadeNode
{
    static void* operator new(unsigned int);
};

extern void* DAT_010ee70c;

struct NiD3DVertexDeclaration
{
    void* m_vtbl;
    void* m_auiShapeKeys[0x2b / 4];
    void* m_pkVertexElements;
    void* m_pkD3DVertexDeclaration;
    char m_flag;
    void Construct();
    char NiD3DShaderDeclaration_Initialize(NiRenderer*, unsigned int, unsigned int);
    virtual void vfn(int);
};

// @fnv 0x00e76700
// pdb: NiXenonShaderDeclaration::Create | NiXenonShaderDeclaration.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: NiDX9ShaderDeclaration::Create)
// pdb params: pkRenderer, uiMaxStreamEntryCount, uiStreamCount
NiD3DVertexDeclaration* FUN_00e76700(NiRenderer* renderer, unsigned int maxStreamEntries, unsigned int streamCount)
{
    if (streamCount > renderer->m_maxStreamEntries)
        return 0;

    NiD3DVertexDeclaration* pkShaderDeclaration = static_cast<NiD3DVertexDeclaration*>(BSFadeNode::operator new(0x38));
    if (pkShaderDeclaration)
    {
        pkShaderDeclaration->Construct();
        *reinterpret_cast<void**>(pkShaderDeclaration) = &DAT_010ee70c;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x2c) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x30) = 0;
        *reinterpret_cast<char*>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x34) = 0;
        if (!pkShaderDeclaration->NiD3DShaderDeclaration_Initialize(renderer, maxStreamEntries, streamCount))
        {
            pkShaderDeclaration->vfn(1);
            pkShaderDeclaration = 0;
        }
    }
    else
    {
        pkShaderDeclaration = 0;
    }
    return pkShaderDeclaration;
}
