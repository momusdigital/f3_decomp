#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiD3DPixelShader
{
    void* __thiscall DestroyPixelShader(unsigned int flags);
};

extern "C" void __cdecl FUN_00e89970();
extern void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

// @fnv 0x00be0af0
// pdb: NiBackToFrontAccumulator::`scalar deleting destructor' | NiBackToFrontAccumulator.obj | tesv_win, vtable_prefix, medium
void* __thiscall NiD3DPixelShader::DestroyPixelShader(unsigned int flags)
{
    NiD3DPixelShader* p = this;
    FUN_00e89970();
    if (flags & 1)
        __Dummy_00b6fef0(p, 0x30);
    return p;
}

struct COMUnknownInterface;

struct NiD3DVertexShader
{
    void FUN_00be0bd0(COMUnknownInterface* hDecl);
};

// @fnv 0x00be0bd0
// pdb: BSPlayerDistanceCheckController::SetCallback | BSPlayerDistanceCheckController.obj | fnv360_0822_retail, call_gap, low
// pdb params: apfnCallback
void NiD3DVertexShader::FUN_00be0bd0(COMUnknownInterface* hDecl)
{
    *(COMUnknownInterface**)((char*)this + 0x38) = hDecl;
}

namespace fnv_00be0bf0 {
struct NiD3DVertexShader
{
    void FUN_00be0bf0(bool bSoftwareVP);
};

// @fnv 0x00be0bf0
void NiD3DVertexShader::FUN_00be0bf0(bool bSoftwareVP)
{
    *(bool*)((char*)this + 0x2c) = bSoftwareVP;
}
}  // namespace fnv_00be0bf0

extern void(__cdecl* DAT_fdf3f0)();

// @fnv 0x00ee6e2e
// pdb: D3DXGetVertexShaderProfile | d3dx9shader.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: D3DXVec3TransformNormal)
// pdb params: pDevice
void __cdecl FUN_00ee6e2e()
{
    return DAT_fdf3f0();
}

struct NiD3DShaderProgramCreator;
struct NiD3DShaderProgram
{
    void __thiscall FUN_00eea540(NiD3DShaderProgramCreator* pkCreator);
};

// @fnv 0x00eea540
void __thiscall NiD3DShaderProgram::FUN_00eea540(NiD3DShaderProgramCreator* pkCreator)
{
    *reinterpret_cast<unsigned int*>(this + 0x1c) = reinterpret_cast<unsigned int>(pkCreator);
}

extern "C" void __cdecl operator delete(void*, unsigned int);
void __cdecl FUN_00e89b70();

struct FUN_00be0b70_shell
{
    void* __thiscall FUN_00be0b70(unsigned int flags);
};

// Calls FUN_00e89b70, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00be0b70
// pdb: NiD3DPixelShader::`scalar deleting destructor' | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0721_beta, objopen_prop, low
void* __thiscall FUN_00be0b70_shell::FUN_00be0b70(unsigned int flags)
{
    FUN_00e89b70();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

extern "C" void __cdecl operator delete(void*, unsigned int);

struct NiD3DHLSLPixelShader : NiD3DPixelShader
{
    void __thiscall FUN_00e96c90();
    void* __thiscall FUN_00e95cd0(unsigned int flags);
};

// Calls FUN_00e96c90, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00e95cd0
void* __thiscall NiD3DHLSLPixelShader::FUN_00e95cd0(unsigned int flags)
{
    FUN_00e96c90();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

namespace fnv_00be0ab0 {
struct NiD3DShaderProgram
{
    char _pad[0x14];
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    void __thiscall SetShaderCode(unsigned int uiSize, void* pvCode);
};

// @fnv 0x00be0ab0
void __thiscall NiD3DShaderProgram::SetShaderCode(unsigned int uiSize, void* pvCode)
{
    m_uiProgramCodeSize = uiSize;
    m_pProgramCode = pvCode;
}
}  // namespace fnv_00be0ab0

void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFreeAlias(void*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int strlen(const char*);
struct FUN_00e95cf0_Holder
{
    void FUN_00e95cf0(const char* pcEntryPoint);
};
// Frees the stored string at offset 0x30 and replaces it with a newly allocated copy of pcEntryPoint, or null if empty.
// @fnv 0x00e95cf0
// pdb: NiD3DHLSLVertexShader::SetEntryPoint | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0721_beta, objrun_open, low, conflict (bridge: NiD3DHLSLPixelShader::SetEntryPoint)
// pdb params: pcEntryPoint
void FUN_00e95cf0_Holder::FUN_00e95cf0(const char* pcEntryPoint)
{
    char* pcNewEntryPoint;
    unsigned int uiLen;
    if (*(char**)((char*)this + 0x30) != pcEntryPoint)
    {
        NiFreeAlias(*(char**)((char*)this + 0x30));
        if (pcEntryPoint && pcEntryPoint[0] != 0)
        {
            uiLen = strlen(pcEntryPoint) + 1;
            pcNewEntryPoint = (char*)NiMalloc(uiLen);
            strcpy_s(pcNewEntryPoint, uiLen, pcEntryPoint);
            *(char**)((char*)this + 0x30) = pcNewEntryPoint;
        }
        else
        {
            *(char**)((char*)this + 0x30) = 0;
        }
    }
}

void* _NiMalloc(unsigned int);
void _NiFreeAlias(void*);
struct FUN_00e95d60_shell
{
    void __thiscall FUN_00e95d60(const char* pcShaderTarget);
};
// Frees the stored shader target string and replaces it with a newly allocated copy of pcShaderTarget, unless it is null, empty, or already stored.
// @fnv 0x00e95d60
// pdb: NiD3DHLSLPixelShader::SetShaderTarget | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: pcShaderTarget
void __thiscall FUN_00e95d60_shell::FUN_00e95d60(const char* pcShaderTarget)
{
    char* pcNewShaderTarget;
    unsigned int uiLen;
    if (*(const char**)((char*)this + 0x34) == pcShaderTarget)
        return;
    _NiFreeAlias(*(void**)((char*)this + 0x34));
    if (!pcShaderTarget)
        return;
    if (*pcShaderTarget == 0)
        return;
    uiLen = (unsigned int)strlen(pcShaderTarget) + 1;
    pcNewShaderTarget = (char*)_NiMalloc(uiLen);
    strcpy_s(pcNewShaderTarget, uiLen, pcShaderTarget);
    *(char**)((char*)this + 0x34) = pcNewShaderTarget;
}

struct ID3DXConstantTable
{
    virtual void __stdcall QueryInterface();
    virtual void __stdcall AddRef();
    virtual void __stdcall Release();
};
struct HlslPixelShaderStandIn
{
    char _pad[0x38];
    ID3DXConstantTable* m_pShaderConstantTable;
    void __thiscall AssignTable(ID3DXConstantTable* pkTable);
};
// Releases the current table and stores pkTable, calling AddRef on it when it differs from the stored one.
// @fnv 0x00e95dc0
// pdb: CWindEngine::GetNumWindMatrices | SpeedTreeRT.obj | fnv360_0822_debug, objopen_prop, low, conflict (bridge: NiD3DHLSLPixelShader::SetConstantTable)
void __thiscall HlslPixelShaderStandIn::AssignTable(ID3DXConstantTable* pkTable)
{
    if (m_pShaderConstantTable != pkTable)
    {
        if (m_pShaderConstantTable)
            m_pShaderConstantTable->Release();
        m_pShaderConstantTable = pkTable;
        if (pkTable)
            pkTable->AddRef();
    }
}

struct NiD3DHLSLVertexShader
{
    void __thiscall FUN_00e971d0();
    void* __thiscall DestroyVertexShader(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00e95e00
// pdb: NiBSplineTransformInterpolator::`scalar deleting destructor' | NiBSplineTransformInterpolator.obj | fnv360_0822_retail, objrun, medium
void* __thiscall NiD3DHLSLVertexShader::DestroyVertexShader(unsigned int flags)
{
    FUN_00e971d0();
    if (flags & 1)
        _delete(this, 0x48);
    return this;
}

namespace fnv_00e95e20 {
void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFreeAlias(void*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
struct NiD3DHLSLVertexShader
{
    char _pad[0x3c];
    char* m_pcShaderEntryPoint;
    void __thiscall FUN_00e95e20(const char* pcEntryPoint);
};
// Replaces the stored entry-point string with a copy of pcEntryPoint, freeing the old one and clearing it when the input is null or empty.
// @fnv 0x00e95e20
// pdb: NiD3DHLSLPixelShader::SetEntryPoint | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: NiD3DHLSLVertexShader::SetEntryPoint)
// pdb params: pcEntryPoint
void __thiscall NiD3DHLSLVertexShader::FUN_00e95e20(const char* pcEntryPoint)
{
    char* pcNewEntryPoint;
    unsigned int uiLen;
    if (m_pcShaderEntryPoint != pcEntryPoint)
    {
        _NiFreeAlias(m_pcShaderEntryPoint);
        if (pcEntryPoint && *pcEntryPoint)
        {
            uiLen = strlen(pcEntryPoint);
            pcNewEntryPoint = (char*)_NiMalloc(uiLen + 1);
            _strcpy_s(pcNewEntryPoint, uiLen + 1, pcEntryPoint);
            m_pcShaderEntryPoint = pcNewEntryPoint;
        }
        else
        {
            m_pcShaderEntryPoint = 0;
        }
    }
}
}  // namespace fnv_00e95e20

namespace fnv_00e95e80 {
void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFreeAlias(void*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
struct NiD3DHLSLVertexShader
{
    char _pad[0x40];
    char* m_pcShaderProfile;
    void __thiscall FUN_00e95e80(const char* pcShaderTarget);
};
// Frees the stored shader target string and, if a non-empty target is given, allocates and copies it into the field.
// @fnv 0x00e95e80
// pdb: NiD3DHLSLVertexShader::SetShaderTarget | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pcShaderTarget
void __thiscall NiD3DHLSLVertexShader::FUN_00e95e80(const char* pcShaderTarget)
{
    if (m_pcShaderProfile != pcShaderTarget)
    {
        _NiFreeAlias(m_pcShaderProfile);
        if (pcShaderTarget && pcShaderTarget[0] != 0)
        {
            char* pcNewShaderTarget;
            unsigned int uiLen;
            uiLen = strlen(pcShaderTarget) + 1;
            pcNewShaderTarget = (char*)_NiMalloc(uiLen);
            _strcpy_s(pcNewShaderTarget, uiLen, pcShaderTarget);
            m_pcShaderProfile = pcNewShaderTarget;
        }
    }
}
}  // namespace fnv_00e95e80

namespace fnv_00e95ef0 {
struct ID3DXConstantTable
{
    virtual int __stdcall QueryInterface();
    virtual int __stdcall AddRef();
    virtual int __stdcall Release();
};
struct NiD3DHLSLVertexShader : NiD3DVertexShader
{
    void __thiscall SetShaderTable(ID3DXConstantTable* pkTable);
};
// Replaces the COM-style table pointer at offset 0x44, releasing the old one and AddRef-ing the new one when it differs.
// @fnv 0x00e95ef0
void NiD3DHLSLVertexShader::SetShaderTable(ID3DXConstantTable* pkTable)
{
    ID3DXConstantTable* pkOld = *(ID3DXConstantTable**)((char*)this + 0x44);
    if (pkOld != pkTable)
    {
        if (pkOld)
            pkOld->Release();
        *(ID3DXConstantTable**)((char*)this + 0x44) = pkTable;
        if (pkTable)
            pkTable->AddRef();
    }
}
}  // namespace fnv_00e95ef0

struct ID3DXBuffer
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void* __stdcall GetBufferPointer();
    virtual unsigned long __stdcall GetBufferSize();
};
extern "C" long __stdcall D3DXCompileShader(const char* pSrcData, unsigned int SrcDataLen, const void* pDefines,
                                            void* pInclude, const char* pFunctionName, const char* pProfile,
                                            unsigned long Flags, ID3DXBuffer** ppShader, ID3DXBuffer** ppErrorMsgs,
                                            ID3DXConstantTable** ppConstantTable);
int __cdecl FUN_00aa0020(int, bool, const char*, ...);
int __cdecl strcpy_s(char*, unsigned int, char*);
void NiFree(void*);
void* _memmove(void*, const void*, unsigned int);
extern unsigned int DAT_0126fa24;
inline void NiMemcpy(void* pvDest, const void* pvSrc, unsigned int ItemUpdateArray)
{
    _memmove(pvDest, pvSrc, ItemUpdateArray);
}

struct NiD3DShaderProgramCreatorHLSL
{
    void* m_vtbl;
    unsigned int m_uiCompileFlags;
    bool CompileShaderFromMemory(const void* pvBuffer, unsigned int uiBufferSize, const char* pcEntryPoint,
                                 const char* pcShaderTarget, void*& pvCode, unsigned int& uiCodeSize,
                                 ID3DXConstantTable*& pkConstantTable, bool bRecoverable);
};

// Compiles HLSL from a memory buffer via D3DXCompileShader, copies the resulting code into pvCode/uiCodeSize, and logs errors on failure.
// @fnv 0x00e964a0
// pdb: NiD3DShaderProgramCreatorHLSL::LoadShaderCodeFromBuffer | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, ustr, medium
// pdb params: pvBuffer, uiBufferSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize, pkConstantTable, bRecoverable
bool NiD3DShaderProgramCreatorHLSL::CompileShaderFromMemory(const void* apSourceData, unsigned int auiSourceSize,
                                                            const char* pcEntryPoint, const char* pcShaderTarget,
                                                            void*& pvCode, unsigned int& uiCodeSize,
                                                            ID3DXConstantTable*& pkConstantTable, bool bRecoverable)
{
    pvCode = 0;
    uiCodeSize = 0;
    if (apSourceData == 0 || auiSourceSize == 0)
    {
        FUN_00aa0020(1, bRecoverable, "Invalid shader buffer\n");
        return false;
    }

    ID3DXBuffer* pkErrors;
    ID3DXBuffer* pkCode;
    long m_kResult = D3DXCompileShader((const char*)apSourceData, auiSourceSize, 0, 0, pcEntryPoint, pcShaderTarget,
                                       m_uiCompileFlags | DAT_0126fa24, &pkCode, &pkErrors, &pkConstantTable);
    if (m_kResult < 0)
    {
        char* pcErrorText = 0;
        if (pkErrors)
        {
            void* pvErrorData = pkErrors->GetBufferPointer();
            if (pvErrorData)
            {
                unsigned int uiLen = pkErrors->GetBufferSize();
                pcErrorText = (char*)_NiMalloc(uiLen);
                strcpy_s(pcErrorText, uiLen, (char*)pvErrorData);
                FUN_00aa0020(1, bRecoverable, "Failed to assemble shader %s from memory\nError: %s\n", pcEntryPoint,
                             pcErrorText);
            }
            pkErrors->Release();
        }
        else
        {
            FUN_00aa0020(1, bRecoverable, "Failed to assemble shader %s from memory\nError: NONE REPORTED\n",
                         pcEntryPoint);
        }
        NiFree(pcErrorText);
        if (pkCode)
            pkCode->Release();
        return false;
    }

    uiCodeSize = pkCode->GetBufferSize();
    pvCode = _NiMalloc(uiCodeSize);
    NiMemcpy(pvCode, pkCode->GetBufferPointer(), uiCodeSize);
    pkCode->Release();
    if (pkErrors)
        pkErrors->Release();
    return true;
}

extern "C" int __cdecl strcmp(const char* psz1, const char* psz2);
void __cdecl _NiFree(void*);
int __cdecl _strcpy_s(char* str, unsigned int numberOfElements, const char* source);

void _NiFree(void*);
int _strcpy_s(char*, unsigned int, const char*);

struct FUN_00be0920_shell
{
    void* m_vtbl;
    unsigned int m_uiValue1;
    unsigned int m_uiType;
    char* m_pcName;
    void __thiscall FUN_00be0920(const char* pszName);
};

// Stores a copy of pszName in m_pcName, reallocating the buffer when the new name is longer, or frees it when the name is empty.
// @fnv 0x00be0920
// pdb: NiD3DShaderProgram::SetName | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pszName
void FUN_00be0920_shell::FUN_00be0920(const char* pszName)
{
    if (!pszName || strcmp(pszName, "") == 0)
    {
        _NiFree(m_pcName);
        m_pcName = 0;
    }
    else
    {
        unsigned int uiNewLen = strlen(pszName) + 1;

        if (m_pcName)
        {
            if (strlen(m_pcName) < uiNewLen)
            {
                _NiFree(m_pcName);
                m_pcName = 0;
            }
        }

        if (!m_pcName)
            m_pcName = static_cast<char*>(_NiMalloc(uiNewLen));

        _strcpy_s(m_pcName, uiNewLen, pszName);
    }
}

struct FUN_00be0ba0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int unk30;

    void __thiscall FUN_00be0ba0(unsigned int value);
};

// @fnv 0x00be0ba0
// pdb: NiD3DHLSLPixelShader::GetRTTI | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0721_beta, objrun_open, low, conflict (bridge: NiD3DVertexShader::GetRTTI)
void __thiscall FUN_00be0ba0_Class::FUN_00be0ba0(unsigned int value)
{
    unk30 = value;
}

struct IUnk_e95
{
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct Shader_e95
{
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void* GetCode();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShader(void* p);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void SetShaderInterface(IUnk_e95* p);
};

long __stdcall FUN_00ee6e40(void* pvCode, IUnk_e95** ppTable);

struct FUN_00e95c40_cls
{
    void* FUN_00e988d0(void* pvCode);
    bool AttachShaderFromCode(Shader_e95* pkShader);
};

// @fnv 0x00e95c40
// pdb: NiD3DShaderProgramCreatorHLSL::RecreatePixelShader | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkPixelShader
bool FUN_00e95c40_cls::AttachShaderFromCode(Shader_e95* pkShader)
{
    void* pvCode = pkShader->GetCode();
    if (!pvCode)
        return false;
    void* pvShader = FUN_00e988d0(pvCode);
    if (!pvShader)
        return false;
    pkShader->SetShader(pvShader);
    IUnk_e95* pkTable;
    if (FUN_00ee6e40(pvCode, &pkTable) >= 0)
        pkShader->SetShaderInterface(pkTable);
    if (pkTable)
        pkTable->Release();
    return true;
}

int __cdecl FUN_00aa0020(int, bool, const char*, ...);

struct NiD3DRenderer;
extern NiD3DRenderer* g_pkD3DRenderer;
extern void* g_pkD3DDevice;
extern "C" const char* __stdcall D3DXGetPixelShaderProfile(void* pDevice);

class HLSLCreator;

class NiD3DShaderProgramBase
{
  public:
    NiD3DShaderProgramBase(NiD3DRenderer* pkRenderer, int iType) throw();
    virtual void DeleteThis(bool b);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class NiD3DPixelShaderStandIn : public NiD3DShaderProgramBase
{
  public:
    NiD3DPixelShaderStandIn(NiD3DRenderer* pkRenderer) throw() : NiD3DShaderProgramBase(pkRenderer, 0)
    {
        m_bIsInitialized = false;
        m_uiPassCount = 0;
        m_uiProgramCodeSize = 0;
        m_pProgramCode = 0;
    }
    bool m_bIsInitialized;
    unsigned int m_uiPassCount;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
};

class NiD3DHLSLPixelShaderStandIn : public NiD3DPixelShaderStandIn
{
  public:
    NiD3DHLSLPixelShaderStandIn(NiD3DRenderer* pkRenderer) throw() : NiD3DPixelShaderStandIn(pkRenderer)
    {
        m_pcShaderEntryPoint = 0;
        m_pcShaderProfile = 0;
        m_pShaderConstantTable = 0;
    }
    static void* operator new(unsigned int uiSize);
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
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(HLSLCreator* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetPassCount(unsigned int ItemUpdateArray);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetSoftwareVertexProcessing(unsigned int b);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v43();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v45();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);
    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

class HLSLCreator : public NiD3DShaderProgramCreatorHLSL
{
  public:
    void* CreatePixelShaderHandle(void* pvCode, void* phShader, unsigned int auiGroupKey, void* pvUnused,
                                  unsigned int uiUnused, unsigned int uiSoftware);
    NiD3DHLSLPixelShaderStandIn* FUN_00e967d0(const void* pvBuffer, unsigned int uiBufferSize, const char* pcShaderName,
                                              const char* pcEntryPoint, const char* pcShaderTarget, void* pvHandle,
                                              unsigned int auiGroupKey, unsigned int bSoftwareVP, bool bRecoverable);
};

// Compiles the shader source, creates the pixel shader handle, fills a new NiD3DHLSLPixelShaderStandIn with it and returns it, or returns 0 on failure.
// @fnv 0x00e967d0
// pdb: NiD3DShaderProgramCreatorHLSL::CreateVertexShaderFromBuffer | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pvBuffer, uiBufferSize, pcShaderName, pcEntryPoint, pcShaderTarget, hDecl, uiUsage, bSoftwareVP, bRecoverable
NiD3DHLSLPixelShaderStandIn* HLSLCreator::FUN_00e967d0(const void* pvBuffer, unsigned int uiBufferSize,
                                                       const char* pcShaderName, const char* pcEntryPoint,
                                                       const char* pcShaderTarget, void* pvHandle,
                                                       unsigned int auiGroupKey, unsigned int bSoftwareVP,
                                                       bool bRecoverable)
{
    NiD3DHLSLPixelShaderStandIn* pkShader = new NiD3DHLSLPixelShaderStandIn(g_pkD3DRenderer);
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;

    if (pcEntryPoint == 0)
        pcEntryPoint = "main";
    if (pcShaderTarget == 0)
        pcShaderTarget = D3DXGetPixelShaderProfile(g_pkD3DDevice);

    if (!CompileShaderFromMemory(pvBuffer, uiBufferSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize,
                                 pkConstantTable, bRecoverable))
    {
        pkShader->DeleteThis(true);
        return 0;
    }

    void* hShader = CreatePixelShaderHandle(pvCode, &pvHandle, auiGroupKey, 0, 0, bSoftwareVP);
    if (hShader == 0)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        pkShader->DeleteThis(true);
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->SetShaderProgramFile(0);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    pkShader->SetPassCount(auiGroupKey);
    pkShader->SetSoftwareVertexProcessing(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget);
    pkShader->SetShaderInterface(pkConstantTable);

    if (pkConstantTable)
        pkConstantTable->Release();

    return pkShader;
}

struct MatResult
{
    bool m_ok;
    MatResult()
    {}
};

bool __cdecl NiShaderFindFile(const char* pcFile, char* pcPath, unsigned int uiLen);
extern "C" long __stdcall D3DXCompileShaderFromFileA(const char* pSrcFile, const void* pDefines, void* pInclude,
                                                     const char* pFunctionName, const char* pProfile,
                                                     unsigned long Flags, ID3DXBuffer** ppShader,
                                                     ID3DXBuffer** ppErrorMsgs, ID3DXConstantTable** ppConstantTable);

struct HLSLFileCreator : NiD3DShaderProgramCreatorHLSL
{
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, ID3DXConstantTable*& pkConstantTable,
                               bool bRecoverable);
};

// Finds the shader file, compiles it with D3DXCompileShaderFromFileA, copies the compiled code into pvCode and reports errors on failure.
// @fnv 0x00e962a0
// pdb: NiD3DShaderProgramCreatorHLSL::LoadShaderCodeFromFile | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, ustr, medium
// pdb params: pcFileName, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize, pkConstantTable, bRecoverable
bool HLSLFileCreator::CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint,
                                            const char* pcShaderTarget, void*& pvCode, unsigned int& uiCodeSize,
                                            ID3DXConstantTable*& pkConstantTable, bool bRecoverable)
{
    pvCode = 0;
    uiCodeSize = 0;

    if (!pcFileName || pcFileName[0] == '\0')
    {
        FUN_00aa0020(1, bRecoverable, "Invalid shader file name\n");
        return false;
    }

    char acPath[260];
    if (!NiShaderFindFile(pcFileName, acPath, 260))
    {
        FUN_00aa0020(1, bRecoverable, "Failed to find shader program file %s\n", pcFileName);
        return false;
    }

    ID3DXBuffer* pkErrors;
    ID3DXBuffer* pkShader;
    long hr = D3DXCompileShaderFromFileA(acPath, 0, 0, pcEntryPoint, pcShaderTarget, m_uiCompileFlags | DAT_0126fa24,
                                         &pkShader, &pkErrors, &pkConstantTable);
    if (hr < 0)
    {
        char* pcError = 0;
        if (pkErrors)
        {
            void* pvError = pkErrors->GetBufferPointer();
            if (pvError)
            {
                unsigned int uiLen = pkErrors->GetBufferSize();
                pcError = (char*)NiMalloc(uiLen);
                strcpy_s(pcError, uiLen, (char*)pvError);
                FUN_00aa0020(1, bRecoverable, "Failed to compile shader %s in file %s\nError: %s\n", pcEntryPoint,
                             pcFileName, pcError);
            }
            pkErrors->Release();
        }
        else
        {
            FUN_00aa0020(1, bRecoverable, "Failed to compile shader %s in file %s\nError: NONE REPORTED\n",
                         pcEntryPoint, pcFileName);
        }
        NiFree(pcError);
        if (pkShader)
            pkShader->Release();
        return false;
    }

    uiCodeSize = pkShader->GetBufferSize();
    pvCode = NiMalloc(uiCodeSize);
    NiMemcpy(pvCode, pkShader->GetBufferPointer(), uiCodeSize);
    pkShader->Release();
    if (pkErrors)
        pkErrors->Release();
    return true;
}

struct FnvCpu_FUN_00be0aa0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int value;
    int FUN_00be0aa0();
};
// @fnv 0x00be0aa0
// pdb: LockFreeMap<MobileObject *,NiPointer<LipTask> >::GetCount | LipSyncBackgroundManager.obj | fnv360_0822_retail, vtable, low
int FnvCpu_FUN_00be0aa0_CpuObject::FUN_00be0aa0()
{
    return value;
}

// 0x00be0be0  mov al,[ecx+0x2c]; ret
struct C00be0be0
{
    char pad00[0x2c];
    unsigned char m2c;
    unsigned char FUN_00be0be0();
};

// @fnv 0x00be0be0
// pdb: NiFile::operator bool | NiFile.obj | fnv360_0822_retail, objrun, medium
unsigned char C00be0be0::FUN_00be0be0()
{
    return m2c;
}

struct FnvCpu_FUN_00e09630_CpuObject
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
    int value;
    int FUN_00e09630();
};
// @fnv 0x00e09630
// pdb: NiD3DHLSLVertexShader::GetRTTI | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, objrun_open, low
int FnvCpu_FUN_00e09630_CpuObject::FUN_00e09630()
{
    return value;
}

struct FUN_00e587a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    int FUN_00e587a0();
};

// @fnv 0x00e587a0
// pdb: hkpMultiSphereShape::getNumCollisionSpheresImpl | hkpMultiSphereShape.obj | fnv360_0822_retail, objrun_open, low
int __thiscall FUN_00e587a0_Class::FUN_00e587a0()
{
    return this->unk10;
}

struct FUN_00e95d50_StandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned int unk34;

    unsigned int __thiscall FUN_00e95d50();
};

// @fnv 0x00e95d50
// pdb: hkpConvexListShape::getNumChildShapes | hkpConvexListShape.obj | fnv360_0822_retail, objrun_sim, low
unsigned int FUN_00e95d50_StandIn::FUN_00e95d50()
{
    return unk34;
}

struct FnvCpu_FUN_00e95ee0_CpuObject
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
    int value;
    int FUN_00e95ee0();
};
// @fnv 0x00e95ee0
// pdb: NiD3DHLSLPixelShader::GetConstantTable | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0721_beta, objrun_open, low
int FnvCpu_FUN_00e95ee0_CpuObject::FUN_00e95ee0()
{
    return value;
}

extern "C" void* g_0126fa28;
extern "C" void* g_0126fa2c;
void* __cdecl FUN_00aa1070(unsigned int uiSize);
void __cdecl FUN_00ec44d0(void* pvDest, const void* pvSrc, unsigned int ItemUpdateArray);

struct HLSLCreator_b10814
{
    int unk00;
    void* __thiscall CreateVertexShaderChecked(void* pvCode, void* phShader, unsigned int auiGroupKey, void* pvUnused1,
                                               unsigned int uiUnused2, unsigned int uiSoftwareVP);
    NiD3DHLSLPixelShaderStandIn* FUN_00e95f20(void* pvBuffer, unsigned int uiCodeSize, const char* pcShaderName,
                                              const char* pcEntryPoint, const char* pcShaderTarget, const char* pcName,
                                              unsigned int auiGroupKey, unsigned int bSoftwareVP, bool bRecoverable);
};

// @fnv 0x00e95f20
// pdb: NiD3DShaderProgramCreatorHLSL::CreateVertexShaderFromD3DXBuffer | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkBuffer, uiBufferSize, pcShaderName, pcEntryPoint, pcShaderTarget, hDecl, uiUsage, bSoftwareVP, bRecoverable
NiD3DHLSLPixelShaderStandIn* HLSLCreator_b10814::FUN_00e95f20(void* pvBuffer, unsigned int uiCodeSize,
                                                              const char* pcShaderName, const char* pcEntryPoint,
                                                              const char* pcShaderTarget, const char* pcName,
                                                              unsigned int auiPassCount, unsigned int bSoftwareVP,
                                                              bool bRecoverable)
{
    NiD3DHLSLPixelShaderStandIn* pkShader = new NiD3DHLSLPixelShaderStandIn((NiD3DRenderer*)g_0126fa2c);
    if (pkShader == 0)
    {
        return 0;
    }

    ID3DXConstantTable* pkConstantTable = 0;
    if (FUN_00ee6e40(((ID3DXBuffer*)pvBuffer)->GetBufferPointer(), (IUnk_e95**)&pkConstantTable) < 0)
    {
        return 0;
    }

    if (pcEntryPoint == 0)
    {
        pcEntryPoint = "main";
    }
    if (pcShaderTarget == 0)
    {
        pcShaderTarget = reinterpret_cast<const char*(__stdcall*)(void*)>(&FUN_00ee6e2e)(g_0126fa28);
    }

    void* pvHandle = this->CreateVertexShaderChecked(((ID3DXBuffer*)pvBuffer)->GetBufferPointer(), (void*)&pcName,
                                                     auiPassCount, 0, 0, bSoftwareVP);
    if (pvHandle == 0)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        pkShader->DeleteThis(true);
        return 0;
    }

    void* pvCode = FUN_00aa1070(uiCodeSize);
    unsigned int uiSize = ((ID3DXBuffer*)pvBuffer)->GetBufferSize();
    void* pBytecodeData = ((ID3DXBuffer*)pvBuffer)->GetBufferPointer();
    FUN_00ec44d0(pvCode, pBytecodeData, uiSize);

    pkShader->SetName(pcShaderName);
    pkShader->SetShaderProgramFile(0);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator((HLSLCreator*)this);
    pkShader->SetD3DPixelShader(pvHandle);
    pkShader->SetPassCount(auiPassCount);
    pkShader->SetSoftwareVertexProcessing(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget);
    pkShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable != 0)
    {
        pkConstantTable->Release();
    }
    return pkShader;
}

struct NiMemObject
{
    static void* operator new(unsigned int uiSize);
};
extern void* DAT_0126fa2c;
extern void* DAT_0126fa28;
extern void* DAT_010f10f4;
const char* __stdcall FUN_00ee6e28(void* pkDevice);

struct HLSLPixelShader96 : NiMemObject
{
    virtual void DeleteThis(bool bFree);
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
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);

    void FUN_00e897d0(void* pkRenderer, int eType) throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* m_pD3DPixelShader;
    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

// the vtable at 0x010f10f4 has no symbol, so the inlined constructor stores it by hand
struct HLSLPixelShaderCtor96 : NiMemObject
{
    HLSLPixelShaderCtor96(void* pkRenderer) throw()
    {
        ((HLSLPixelShader96*)this)->FUN_00e897d0(pkRenderer, 2);
        ((HLSLPixelShader96*)this)->m_pD3DPixelShader = 0;
        *(void**)this = &DAT_010f10f4;
        ((HLSLPixelShader96*)this)->m_pcShaderEntryPoint = 0;
        ((HLSLPixelShader96*)this)->m_pcShaderProfile = 0;
        ((HLSLPixelShader96*)this)->m_pShaderConstantTable = 0;
    }
    int m_kNextStreamField[15];
};

struct PixelShaderCreatorHLSL : NiD3DShaderProgramCreatorHLSL
{
    void* FUN_00e988d0(void* pvCode);
    HLSLPixelShader96* FUN_00e96b10(const void* pvBuffer, unsigned int uiBufferSize, const char* pcShaderName,
                                    const char* pcEntryPoint, const char* pcShaderTarget, bool bRecoverable);
};

// @fnv 0x00e96b10
// pdb: NiD3DShaderProgramCreatorHLSL::CreatePixelShaderFromBuffer | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pvBuffer, uiBufferSize, pcShaderName, pcEntryPoint, pcShaderTarget, bRecoverable
HLSLPixelShader96* PixelShaderCreatorHLSL::FUN_00e96b10(const void* pvSourceBuffer, unsigned int uiSourceSize,
                                                        const char* pcShaderName, const char* pcEntryPoint,
                                                        const char* pcShaderTarget, bool bRecoverable)
{
    HLSLPixelShader96* pkPixelShader = (HLSLPixelShader96*)new HLSLPixelShaderCtor96(DAT_0126fa2c);
    if (!pkPixelShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;
    if (!pcEntryPoint)
        pcEntryPoint = "main";
    if (!pcShaderTarget)
        pcShaderTarget = FUN_00ee6e28(DAT_0126fa28);

    if (!CompileShaderFromMemory(pvSourceBuffer, uiSourceSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize,
                                 pkConstantTable, bRecoverable))
    {
        pkPixelShader->DeleteThis(true);
        return 0;
    }

    void* hShader = FUN_00e988d0(pvCode);
    if (!hShader)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreatePixelShader call on %s\n", pcShaderName);
        pkPixelShader->DeleteThis(true);
        return 0;
    }

    pkPixelShader->SetName(pcShaderName);
    pkPixelShader->SetShaderProgramFile(0);
    pkPixelShader->SetProgramCode(uiCodeSize, pvCode);
    pkPixelShader->SetCreator(this);
    pkPixelShader->SetD3DPixelShader(hShader);
    pkPixelShader->SetEntryPoint(pcEntryPoint);
    pkPixelShader->SetPixelShaderTarget(pcShaderTarget);
    pkPixelShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable)
        pkConstantTable->Release();
    return pkPixelShader;
}

struct SolverVector
{
    void* data;
    int size;
    int capacity;
    int rows;
    int columns;
    int FUN_00cc0760();
    SolverVector* FUN_00e58e80(SolverVector* out, SolverVector* other);
    void CopyFrom(SolverVector* other);
    void InitArray(int rows, int columns);
    void FUN_00c7b0f0();
};
__declspec(noalias) void FUN_00e58960(SolverVector*, float*, SolverVector*);
__declspec(noalias) void FUN_00e58900(SolverVector*, SolverVector*, float*, SolverVector*);

struct ConstTableE95
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class ShaderSrcE95
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0A();
    virtual void vfn_0B();
    virtual void vfn_0C();
    virtual void vfn_0D();
    virtual void vfn_0E();
    virtual void vfn_0F();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void* GetCode();
    virtual void vfn_1A();
    virtual void vfn_1B();
    virtual void vfn_1C();
    virtual void vfn_1D();
    virtual void vfn_1E();
    virtual unsigned int GetCodeSize();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void SetD3DPixelShader(void* pvHandle);
    virtual unsigned int GetShaderVersion();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2A();
    virtual void vfn_2B();
    virtual void vfn_2C();
    virtual void vfn_2D();
    virtual void SetShaderInterface(ConstTableE95* pkTable);
};

long __stdcall FUN_00ee6e40(void* pvCode, ConstTableE95** ppkTable);

class ShaderMgrE95
{
  public:
    void* CreateVertexShaderChecked(void* pvCode, unsigned int* puiVersion, unsigned int uiCodeSize, void* pvDecl,
                                    unsigned int uiFlags, unsigned int uiUsage);
    bool FUN_00e95ba0(ShaderSrcE95* pkShader);
};

// Creates a shader handle from pkShader's code and version, stores it and an optional interface, and returns success.
// @fnv 0x00e95ba0
// pdb: NiD3DShaderProgramCreatorHLSL::RecreateVertexShader | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkVertexShader
bool ShaderMgrE95::FUN_00e95ba0(ShaderSrcE95* pkShader)
{
    void* pvCode = pkShader->GetCode();
    if (!pvCode)
        return false;

    unsigned int uiVersion = pkShader->GetShaderVersion();
    void* pvHandle = CreateVertexShaderChecked(pvCode, &uiVersion, pkShader->GetCodeSize(), 0, 0, 0);
    if (!pvHandle)
        return false;

    pkShader->SetD3DPixelShader(pvHandle);

    ConstTableE95* pkTable;
    if (FUN_00ee6e40(pvCode, &pkTable) >= 0)
        pkShader->SetShaderInterface(pkTable);
    if (pkTable)
        pkTable->Release();
    return true;
}

struct S00e96610_CT
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
const char* __stdcall FUN_00ee6e2e(void* pDevice);

int __cdecl FUN_00aa0020(int, bool, const char*, ...);

struct S00e96610_Creator;
struct ShaderTargetName
{
    const char* value;
    ShaderTargetName(const char* name) : value(name)
    {}
};
inline void S00e96610_DefaultTarget(const char*& pcTarget)
{
    if (!pcTarget)
        pcTarget = FUN_00ee6e2e(DAT_0126fa28);
}

struct S00e96610_VSBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    S00e96610_VSBase(void* pkRenderer, void* hDecl) throw();
    virtual ~S00e96610_VSBase();
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
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void HasMaster(const char* pcFileName);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(S00e96610_Creator* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShaderUsage(unsigned int uiUsage);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetSoftwareVP(unsigned int bSoftwareVP);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v43();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v45();
    virtual void SetShaderInterface(S00e96610_CT* pkTable);
};

struct S00e96610_VSMid : S00e96610_VSBase
{
    bool m_b2C;
    int m_i30;
    int m_i34;
    int m_i38;
    S00e96610_VSMid(void* pkRenderer) : S00e96610_VSBase(pkRenderer, 0), m_b2C(false), m_i30(0), m_i34(0), m_i38(0)
    {}
};

struct S00e96610_VS : S00e96610_VSMid
{
    int m_i3C;
    int m_i40;
    int m_i44;
    S00e96610_VS(void* pkRenderer) : S00e96610_VSMid(pkRenderer)
    {
        m_i3C = 0;
        m_i40 = 0;
        m_i44 = 0;
    }
    virtual ~S00e96610_VS();
    static void* operator new(unsigned int);
};

struct S00e96610_Creator
{
    void* m_vtbl;
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, S00e96610_CT*& pkConstantTable,
                               bool bRecoverable);
    void* CreateVertexShaderChecked(void* pvCode, void** phDecl, unsigned int uiUsage, void* pvUnused,
                                    unsigned int uiUnused1, unsigned int bSoftwareVP);
    S00e96610_VS* FUN_00e96610(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                               ShaderTargetName pcShaderTarget, void* hDecl, unsigned int uiUsage,
                               unsigned int bSoftwareVP, bool bRecoverable);
};

// Compiles a vertex shader from pcFileName and creates a D3D vertex shader, returning a configured S00e96610_VS or null on failure.
// @f3 0x008974f0 (community match, verified in this file)
const char* __stdcall FUN_00c20850(void* pDevice);

S00e96610_VS::~S00e96610_VS()
{
}

// pdb: NiD3DShaderProgramCreatorHLSL::CreateVertexShaderFromFile | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pcFileName, pcShaderName, pcEntryPoint, pcShaderTarget, hDecl, uiUsage, bSoftwareVP, bRecoverable
S00e96610_VS* S00e96610_Creator::FUN_00e96610(const char* pcFileName, const char* pcShaderName,
                                              const char* pcEntryPoint, ShaderTargetName pcShaderTarget, void* hDecl,
                                              unsigned int uiUsage, unsigned int bSoftwareVP, bool bRecoverable)
{
    S00e96610_VS* pkShader = new S00e96610_VS(DAT_0126fa2c);
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    S00e96610_CT* pkConstantTable = 0;

    if (!pcEntryPoint)
        pcEntryPoint = "main";

    if (!pcShaderTarget.value)
        *(const char* volatile*)&pcShaderTarget.value = FUN_00c20850(DAT_0126fa28);

    if (!CompileShaderFromFile(pcFileName, pcEntryPoint, pcShaderTarget.value, pvCode, uiCodeSize, pkConstantTable,
                               bRecoverable))
    {
        delete pkShader;
        return 0;
    }

    void* hShader = CreateVertexShaderChecked(pvCode, &hDecl, uiUsage, 0, 0, bSoftwareVP);
    if (!hShader)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        delete pkShader;
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->HasMaster(pcFileName);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    pkShader->SetShaderUsage(uiUsage);
    pkShader->SetSoftwareVP(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget.value);
    pkShader->SetShaderInterface(pkConstantTable);

    if (pkConstantTable)
        pkConstantTable->Release();

    return pkShader;
}


struct ShaderArgs
{
    const char* pcFileName;
    const char* pcShaderName;
};
class ShaderProgram96 : public NiMemObject
{
  public:
    ShaderProgram96(void* pkRenderer, int eType) throw();
    virtual ~ShaderProgram96();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class PixelShader96 : public ShaderProgram96
{
  public:
    PixelShader96(void* pkRenderer) throw() : ShaderProgram96(pkRenderer, 2)
    {
        m_pD3DPixelShader = 0;
    }
    virtual ~PixelShader96();
    void* m_pD3DPixelShader;
};

class HLSLPixelShaderObj : public PixelShader96
{
  public:
    HLSLPixelShaderObj(void* pkRenderer) throw() : PixelShader96(pkRenderer)
    {
        m_pcShaderEntryPoint = 0;
        m_pcShaderProfile = 0;
        m_pShaderConstantTable = 0;
    }
    virtual ~HLSLPixelShaderObj();
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
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);

    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

struct HLSLFileShaderCreator : NiD3DShaderProgramCreatorHLSL
{
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, ID3DXConstantTable*& pkConstantTable,
                               bool bRecoverable);
    void* FUN_00e988d0(void* pvCode);
    HLSLPixelShaderObj* FUN_00e96990(ShaderArgs args, const char* pcEntryPoint, const char* pcShaderTarget,
                                     bool bRecoverable);
};

// Creates an HLSLPixelShaderObj by compiling a shader file and configuring the new object with the compiled code and metadata.
// @f3 0x00897870 (community match, verified in this file)
// pdb: NiD3DShaderProgramCreatorHLSL::CreatePixelShaderFromFile | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pcFileName, pcShaderName, pcEntryPoint, pcShaderTarget, bRecoverable
HLSLPixelShaderObj* HLSLFileShaderCreator::FUN_00e96990(ShaderArgs args, const char* pcEntryPoint,
                                                        const char* pcShaderTarget, bool bRecoverable)
{
    HLSLPixelShaderObj* pkPixelShader = new HLSLPixelShaderObj(DAT_0126fa2c);
    if (!pkPixelShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;

    if (!pcEntryPoint)
        pcEntryPoint = "main";
    if (!pcShaderTarget)
        pcShaderTarget = FUN_00ee6e28(DAT_0126fa28);

    if (!CompileShaderFromFile(*reinterpret_cast<const char* volatile*>(&args.pcFileName), pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize, pkConstantTable,
                               bRecoverable))
    {
        delete pkPixelShader;
        return 0;
    }
    void* hShader = FUN_00e988d0(pvCode);
    if (!hShader)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreatePixelShader call on %s\n", args.pcShaderName);
        delete pkPixelShader;
        return 0;
    }
    pkPixelShader->SetName(args.pcShaderName);
    pkPixelShader->SetShaderProgramFile(args.pcFileName);
    pkPixelShader->SetProgramCode(uiCodeSize, pvCode);
    pkPixelShader->SetCreator(this);
    pkPixelShader->SetD3DPixelShader(hShader);
    pkPixelShader->SetEntryPoint(pcEntryPoint);
    pkPixelShader->SetPixelShaderTarget(pcShaderTarget);
    pkPixelShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable)
        pkConstantTable->Release();
    return pkPixelShader;
}


struct Dummy_00cc0760
{
    int unk00, unk04, unk08;
    int rows;
    int FUN_00cc0760();
};
// @fnv 0x00cc0760
// pdb: hkpMalleableConstraintData::getWrappedConstraintData | hkpMalleableConstraintData.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkpRagdollConstraintData::getMotorsActive)
int Dummy_00cc0760::FUN_00cc0760()
{
    return rows;
}

extern "C" long __stdcall D3DXGetShaderConstantTable(const unsigned long*, ID3DXConstantTable**);

struct BufferPixelShaderCreator : HLSLFileShaderCreator
{
    HLSLPixelShaderObj* FUN_00e96100(ID3DXBuffer* code, unsigned int codeSize, const char* name, const char* entryPoint,
                                     const char* target, bool recoverable);
};

// @fnv 0x00e96100
// pdb: NiD3DShaderProgramCreatorHLSL::CreatePixelShaderFromD3DXBuffer | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkBuffer, uiBufferSize, pcShaderName, pcEntryPoint, pcShaderTarget, bRecoverable
HLSLPixelShaderObj* BufferPixelShaderCreator::FUN_00e96100(ID3DXBuffer* code, unsigned int codeSize, const char* name,
                                                           const char* entryPoint, const char* target, bool recoverable)
{
    HLSLPixelShaderObj* shader = new HLSLPixelShaderObj(DAT_0126fa2c);
    if (!shader)
        return 0;

    ID3DXConstantTable* constants = 0;
    if (D3DXGetShaderConstantTable((const unsigned long*)code->GetBufferPointer(), &constants) < 0)
        return 0;

    if (!entryPoint)
        entryPoint = "main";
    if (!target)
        target = FUN_00ee6e28(DAT_0126fa28);

    void* handle = FUN_00e988d0(code->GetBufferPointer());
    if (!handle)
    {
        FUN_00aa0020(1, recoverable, "Failed CreatePixelShader call on %s\n", name);
        delete shader;
        return 0;
    }

    void* copy = NiMalloc(codeSize);
    NiMemcpy(copy, code->GetBufferPointer(), code->GetBufferSize());

    shader->SetName(name);
    shader->SetShaderProgramFile(0);
    shader->SetProgramCode(codeSize, copy);
    shader->SetCreator(this);
    shader->SetD3DPixelShader(handle);
    shader->SetEntryPoint(entryPoint);
    shader->SetPixelShaderTarget(target);
    shader->SetShaderInterface(constants);
    if (constants)
        constants->Release();
    return shader;
}

// @f3twin 0x00a48480 of 0x0042ba00
struct F3Twin_00a48480 : public FnvCpu_FUN_00be0aa0_CpuObject { int F3_FUN_00a48480() ; };
int F3Twin_00a48480::F3_FUN_00a48480() 
{
    return value;
}

// @f3twin 0x00a484a0 of 0x00896dc0
struct F3Twin_00a484a0 : public FnvCpu_FUN_00e95ee0_CpuObject { int F3_FUN_00a484a0() ; };
int F3Twin_00a484a0::F3_FUN_00a484a0() 
{
    return value;
}

// @f3twin 0x00a54fe0 of 0x0042ba00
struct F3Twin_00a54fe0 : public FnvCpu_FUN_00be0aa0_CpuObject { int hkpMoppCachedShapeMediator_getNumPrimitives() ; };
// pdb: hkpMoppCachedShapeMediator::getNumPrimitives | hkpMoppCachedShapeMediator.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int F3Twin_00a54fe0::hkpMoppCachedShapeMediator_getNumPrimitives() 
{
    return value;
}
