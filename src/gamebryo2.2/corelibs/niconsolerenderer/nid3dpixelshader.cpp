#include "f3_common.h"
//
// Compile form of nid3dpixelshader.inl: MSVC 2008 cl does not accept the
// .inl extension as a source file, so this identical unit is compiled as .cpp
// by the matcher. Content is the authored body of the .inl source of record.

// The standalone build carries the shader base chain with the real member
// names and offsets of the MSVC 2008 build: NiD3DPixelShader is 48 bytes
// and its D3D pixel shader handle lives at offset 44.

// Direct3D9 pixel shader object; referenced by pointer only.
class GeometryRelatedType;

// Forward declarations of the renderer types named by the base chain.
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;

typedef unsigned int NiUInt32;

// Base of the engine allocation tracking; empty in this build.
class NiMemObject
{
};

// Reference counted engine object.
class NiRefObject : public NiMemObject
{
  public:
    NiRefObject() : m_uiRefCount(0)
    {}

    virtual ~NiRefObject()
    {}

    virtual void DeleteThis()
    {
        delete this;
    }

  protected:
    NiUInt32 m_uiRefCount;
};

// GPU program base of the Nivid3D shader programs.
class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType
    {
        PROGRAMTYPE_INVALID,
        PROGRAMTYPE_VERTEX,
        PROGRAMTYPE_PIXEL
    };

    ProgramType GetProgramType()
    {
        return m_iProgramType;
    }

  protected:
    ProgramType m_iProgramType;
};

// Nivid3D shader program with its compiled D3D program state.
class NiD3DShaderProgram : public NiGPUProgram
{
  protected:
    char* m_pcProgramName;
    char* m_pcProfile;
    NiUInt32 m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};

// Nivid3D pixel shader program.
class NiD3DPixelShader : public NiD3DShaderProgram
{
  public:
    void SetD3DPixelShader(GeometryRelatedType* pixelShader);

  protected:
    GeometryRelatedType* m_pD3DPixelShader;
};

// @fnv 0x00BE0B20
// pdb: NiD3DPixelShader::SetShaderHandle | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, call_seq, medium
// pdb params: hShader
void NiD3DPixelShader::SetD3DPixelShader(GeometryRelatedType* const pixelShader)
{
    m_pD3DPixelShader = pixelShader;
}

struct NiD3DPixelShader;

// ---- stand-ins for identities not defined in this unit ----
struct FakeShader;
struct FakeRenderer
{
    void PurgeShader(FakeShader* shader);
};

struct FUN_00e898c0_shell : NiD3DPixelShader
{
    void FUN_00e898c0();
};

// @fnv 0x00e898c0
// pdb: NiD3DVertexShader::DestroyRendererData | NiD3DVertexShader.obj | fnv360_0721_beta, objopen_prop, low
void FUN_00e898c0_shell::FUN_00e898c0()
{
    if (m_pD3DPixelShader)
    {
        reinterpret_cast<FakeRenderer*>(m_pShaderObject)->PurgeShader(reinterpret_cast<FakeShader*>(this));
    }
}
