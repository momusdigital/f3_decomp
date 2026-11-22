#include "f3_common.h"
#include "niconsolefragmentshader_decls.h"
// @f3 0x008839d0 (community match, verified in this file)
extern unsigned int DAT_0106e5a4;
extern unsigned int DAT_0106e5a0;
struct S00409A80 { void __thiscall FUN_00409a80(const char*); };
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);

void ShaderCache::BindGPUProgram()
{
    if (count != 0)
    {
        do
        {
            PoolAllocatorBase<unsigned int>::LinkedListEntry* node = head;
            head = node->next;
            if (head)
                head->prev = 0;
            else
                tail = 0;

            ShaderEntry* entry = (ShaderEntry*)node->data;

            node->data = 0;

            ((S00409A80*)&DAT_0106e5a0)->FUN_00409a80(0);

            node->prev = 0;
            node->next = PoolAllocatorBase<unsigned int>::ms_pFreeList;
            PoolAllocatorBase<unsigned int>::ms_pFreeList = node;

            if (--DAT_0106e5a4 == 0)
            {
                const long previousOwner = *(volatile long*)&DAT_0106e5a0;
                InterlockedCompareExchange((long volatile*)&DAT_0106e5a0, 0, previousOwner);
            }

            --count;
            ShaderData* data = *(ShaderData* volatile*)&entry->data;

                typedef void(__stdcall * SetFunction)(Device*, unsigned int, unsigned int);
            Device* targetDevice = device;
            unsigned int handle = data->handle;
            ((SetFunction)targetDevice->vtable[53])(targetDevice, handle, 0);
            data->active = false;
        } while (count != 0);
    }
    current = initial;
}


struct NiD3DShader
{
    bool Initialize(void);
};

struct FUN_00e8d230_shell : NiD3DShader
{
    char EnsureInitialized(int arg);
};

// @fnv 0x00e8d230
char FUN_00e8d230_shell::EnsureInitialized(int arg)
{
    if (*(reinterpret_cast<unsigned char*>(this) + 0x10))
        return 1;
    char result = Initialize() ? 1 : 0;
    return result;
}

struct NodePoolView
{
    void* __thiscall AddHead(void);
};

struct NiTPointerListBase_00e8b5f0
{
    void* m_pFirstNode;
    void* m_pTail;
    unsigned int m_uiItemCount;
    void* __thiscall InsertHead(void* arg);
};

// Allocates a node from the pool at this+8, links it before the current head, updates the tail when the list was empty, increments the count and returns the node.
// @fnv 0x00e8b5f0
// pdb: NiTPointerListBase<NiTPointerAllocator<unsigned int>,unsigned int>::AddHead | HackingMenu.obj | fnv360_0822_retail, call_gap, low
// pdb params: element
void* __thiscall NiTPointerListBase_00e8b5f0::InsertHead(void* arg)
{
    NodePoolView* pool = (NodePoolView*)((char*)this + 8);
    void* node = pool->AddHead();
    void* next = *(void**)((char*)arg + 0);
    *(void**)((char*)node + 8) = next;
    *(void**)((char*)node + 4) = 0;
    *(void**)node = this->m_pFirstNode;
    if (this->m_pFirstNode)
    {
        *(void**)((char*)this->m_pFirstNode + 4) = node;
        ++this->m_uiItemCount;
        this->m_pFirstNode = node;
        return node;
    }
    ++this->m_uiItemCount;
    this->m_pTail = node;
    this->m_pFirstNode = node;
    return node;
}

void __cdecl FUN_00e81470();
// @fnv 0x00e8d340
// pdb: bhkBallAndSocketConstraint::LoadBinary | bhkBallAndSocketConstraint.obj | fnv360_0721_beta, objrun_open, low
// pdb params: arStream
void __cdecl FUN_00e8d340()
{
    return FUN_00e81470();
}

struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
};

struct NiD3DVertexDeclaration
{
    static NiD3DVertexDeclaration* __cdecl Create(NiRenderer*, unsigned int, unsigned int);
};

struct NiConsoleShaderDeclaration_shellEx
{
    NiD3DVertexDeclaration* __thiscall FUN_00e8d410(unsigned int a, unsigned int b);
};

// @fnv 0x00e8d410
// pdb: NiXenonFragmentShader::CreateShaderDeclaration | NiXenonFragmentShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: uiMaxStreamEntryCount, uiStreamCount
NiD3DVertexDeclaration* __thiscall NiConsoleShaderDeclaration_shellEx::FUN_00e8d410(unsigned int a, unsigned int b)
{
    NiD3DVertexDeclaration* p = NiD3DVertexDeclaration::Create(NiRenderer::ms_pRenderer, a, b);
    void** vtable = *(void***)this;
    void* fn = vtable[0x30];
    ((void(__thiscall*)(NiConsoleShaderDeclaration_shellEx*, NiD3DVertexDeclaration*))fn)(this, p);
    return p;
}

typedef void(__cdecl* DAT_0126f738_fn_t)(void*, void*, unsigned int, unsigned int, unsigned int);
extern DAT_0126f738_fn_t DAT_0126f738[];
// Calls the function pointer at DAT_0126f738 indexed by the int at a1+0x134, passing a1+0xF4, a1+0x118, a2, a3 and a4.
// @fnv 0x00e8d3d0
void __cdecl DispatchByIndex(void* a1, unsigned int auiArg2, unsigned int auiArg3, unsigned int auiArg4)
{
    DAT_0126f738[*(int*)((char*)a1 + 0x134)]((char*)a1 + 0xF4, (char*)a1 + 0x118, auiArg2, auiArg3, auiArg4);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiRefObject;
struct BSShaderBloodSplatter
{
    void FUN_00b80600(NiRefObject*);
};
extern BSShaderBloodSplatter* DAT_0126f74c;
int __fastcall FUN_00b79950(char*, int, NiRefObject*);
struct FUN_00e8d5f0_Param
{
    char _0[8];
    int m8;
};
// Rejects a1 >= 1 or a null DAT_0126f74c; for a2->m8 of 0 calls FUN_00b79950, for 2 calls FUN_00b80600, and returns true.
// @fnv 0x00e8d5f0
bool __stdcall ProcessShaderParam(unsigned int a1, FUN_00e8d5f0_Param* pParam, void* pUnused)
{
    if (a1 >= 1)
        return false;
    BSShaderBloodSplatter* p = DAT_0126f74c;
    if (!p)
        return false;
    switch (pParam->m8)
    {
    case 0:
        FUN_00b79950((char*)p, (int)pParam, (NiRefObject*)pParam);
        break;
    case 2:
        p->FUN_00b80600((NiRefObject*)pParam);
        return true;
    }
    return true;
}

struct FUN_00e8d3a0_sub
{
    unsigned char Query(unsigned int id, unsigned int* out, unsigned char* flag);
};

struct FUN_00e8d3a0_cls
{
    char unk00[0x10];
    FUN_00e8d3a0_sub* m_10;
    unsigned char QueryFlagB();
};

// Calls Query on m_10 for id 0xb, then returns flag masked with 0xFF when Query succeeds, else 0.
// @f3 0x008863c0 (community match, verified in this file)
struct SubQuery
{
    bool __thiscall FUN_0088e740(unsigned int id, unsigned int* value, unsigned char* flag);
};

unsigned char FUN_00e8d3a0_cls::QueryFlagB()
{
    unsigned int value = 0;
    unsigned int flag;
    *(unsigned char*)&flag = 0;
    char mask = ((SubQuery*)m_10)->FUN_0088e740(0xb, &value, (unsigned char*)&flag) != 0 ? -1 : 0;
    return (unsigned char)(mask & flag);
}


struct S_00e8d590_Obj
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int m64;
    void FUN_00e80190(void);
};
void __cdecl FUN_00e804d0(S_00e8d590_Obj** out);
// @fnv 0x00e8d590
// pdb: SpeedTreeBranchShader::LoadStagesAndPasses | SpeedTreeBranchShader_Preset.obj | fnv360_0721_beta, objrun_prop, low
bool __stdcall FUN_00e8d590(int* out)
{
    S_00e8d590_Obj* obj = 0;
    if (DAT_0126f74c == 0)
    {
        FUN_00e804d0(&obj);
        DAT_0126f74c = (BSShaderBloodSplatter*)obj;
        *out = 0;
        if (obj)
        {
            S_00e8d590_Obj* p = obj;
            p->m64--;
            if (p->m64 == 0)
                p->FUN_00e80190();
        }
        return true;
    }
    return false;
}

struct Inner_e8db90
{
    Inner_e8db90();
    void* __thiscall FUN_00ee8a10(unsigned int a);
};

struct SubObj_e8db90
{
    virtual void unk00();
    Inner_e8db90 m_inner;
    SubObj_e8db90() : m_inner()
    {}
};

struct FieldsMid_e8db90
{
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned char m_27;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    FieldsMid_e8db90()
    {
        m_24 = 0;
        m_25 = 0;
        m_28 = 0;
        m_2c = 0;
        m_30 = 0;
        m_34 = 0;
        m_38 = 0;
    }
};

void __cdecl FUN_00e811d0();
// @fnv 0x00e8d2e0
// pdb: bhkCharacterProxy::IsEqual | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, high
// pdb params: apObject
void __cdecl FUN_00e8d2e0()
{
    FUN_00e811d0();
}

extern int __cdecl PrepareShaderAndStreams();

// @fnv 0x00e8d2f0
// pdb: bhkOrientHingedBodyAction::CopyMembers | bhkOrientHingedBodyAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apDest, arCloneData
int __cdecl FUN_00e8d2f0()
{
    return PrepareShaderAndStreams();
}

extern "C" void __cdecl FUN_00a8f3f0();
// @fnv 0x00e8d300
// pdb: bhkRagdollTemplate::CopyMembers | bhkRagdollTemplate.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pDest, arCloneData
void __cdecl FUN_00e8d300()
{
    FUN_00a8f3f0();
}

__declspec(noreturn) void __cdecl FUN_00e805f0();

// @fnv 0x00e8d310
void __cdecl FUN_00e8d310()
{
    FUN_00e805f0();
}

void __cdecl FUN_00e80580();
// @fnv 0x00e8d320
void __cdecl FUN_00e8d320()
{
    FUN_00e80580();
}

void __cdecl FUN_00e80590();

// @fnv 0x00e8d330
void __cdecl FUN_00e8d330()
{
    FUN_00e80590();
}

struct NiD3DShaderConstantMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    NiD3DShaderConstantMap(void* pkRenderer, int eType) throw();
    static void* operator new(unsigned int uiSize);
};

struct NiD3DPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiD3DShaderConstantMap* m_spFirstShaderConstantMap;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    NiD3DShaderConstantMap* m_spSecondShaderConstantMap;
    void SetPixelConstantMap(NiD3DShaderConstantMap* pkMap);
    void SetVertexConstantMap(NiD3DShaderConstantMap* pkMap);
};

extern NiD3DPass* g_pD3DPass;
extern void* g_pD3DRenderer;

// Returns the pass's vertex or pixel constant map for shader type 0, creating and registering it if absent.
// @fnv 0x00e8dca0
// pdb: NiXenonFragmentShader::CreateShaderConstantMap | NiXenonFragmentShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: uiPassId, uiProgramId
NiD3DShaderConstantMap* __stdcall GetOrCreateShaderConstantMap(unsigned int auiShaderType, int eMapType)
{
    if (auiShaderType >= 1)
        return 0;
    NiD3DPass* pkPass = g_pD3DPass;
    if (!pkPass)
        return 0;
    NiD3DShaderConstantMap* pkMap = 0;
    if (eMapType == 0)
    {
        pkMap = pkPass->m_spSecondShaderConstantMap;
        if (!pkMap)
        {
            pkMap = new NiD3DShaderConstantMap(g_pD3DRenderer, 0);
            pkPass->SetVertexConstantMap(pkMap);
        }
    }
    else if (eMapType == 1)
    {
        pkMap = pkPass->m_spFirstShaderConstantMap;
        if (!pkMap)
        {
            pkMap = new NiD3DShaderConstantMap(g_pD3DRenderer, 2);
            pkPass->SetPixelConstantMap(pkMap);
        }
    }
    return pkMap;
}

// Object cached in BSShaderBloodSplatter+0x30; receives SetNodeValue / RemoveNodeByKey as this.
struct BloodMap
{
    void SetNodeValue(unsigned int a, int b, int c);
    void RemoveNodeByKey(unsigned int a);
};

// Pointer returned by FUN_00e7f7c0; dword table at offset 0x20 indexed by param.
struct BloodArrView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m20[64];
};

// View of BSShaderBloodSplatter for this function.
struct BloodSplatterView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    BloodMap* unk30;
    BloodArrView* FUN_00e7f7c0(void);
    void FUN_00b71a10(unsigned int a, int b, int c);
};

BloodMap* __stdcall FUN_00e7f5d0(void);

// Sets blood splatter node values and passes indexed array values to the view; returns false for an unsupported type or missing view.
// @fnv 0x00e8d450
// pdb: NiXenonFragmentShader::SetAlphaOverride | NiXenonFragmentShader.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: NiD3DDefaultShader::OpenNewPass)
// pdb params: uiPassId, bAlphaBlend, bUsePreviousSrcBlendMode, eSrcBlendMode, bUsePreviousDestBlendMode, eDestBlendMode
bool __stdcall SetBloodSplatter(unsigned int auiShaderType, bool abEnabled, bool bParam3, int aiIndex, bool bParam5,
                                int aiSecondIndex)
{
    if (auiShaderType >= 1)
        return false;

    BloodSplatterView* pkSplat = (BloodSplatterView*)DAT_0126f74c;
    if (!pkSplat)
        return false;

    if (abEnabled)
    {
        if (!pkSplat->unk30)
            pkSplat->unk30 = FUN_00e7f5d0();
        pkSplat->unk30->SetNodeValue(0x1b, 1, 1);

        BloodArrView* pkArr = pkSplat->FUN_00e7f7c0();

        if (!bParam3)
        {
            pkSplat->FUN_00b71a10(0x13, pkArr->m20[aiIndex], 0);
        }
        else
        {
            BloodMap* pkBloodMap = pkSplat->unk30;
            if (pkBloodMap)
                pkBloodMap->RemoveNodeByKey(0x13);
        }

        if (!bParam5)
        {
            pkSplat->FUN_00b71a10(0x14, pkArr->m20[aiSecondIndex], 0);
        }
        else
        {
            BloodMap* pkBloodMap = pkSplat->unk30;
            if (pkBloodMap)
                pkBloodMap->RemoveNodeByKey(0x14);
        }
    }
    else
    {
        if (!pkSplat->unk30)
            pkSplat->unk30 = FUN_00e7f5d0();
        pkSplat->unk30->SetNodeValue(0x1b, 0, 1);
    }

    return true;
}

void operator delete(void* pvObject, unsigned int uiSize);

class ShaderConstantEntryE8D
{
  public:
    void Destroy();
    unsigned int m_uiPosition;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiValue1;
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
    unsigned short m_usRegisterInfo;
    unsigned short unk5e;
    int m_iRefCount;
};

__forceinline void SetFlagBitsE8D(ShaderConstantEntryE8D* pkE, unsigned int uiClear, unsigned int uiSet)
{
    pkE->m_uiValue1 &= uiClear;
    pkE->m_uiValue1 |= uiSet;
}

__forceinline void ReleaseEntryE8D(ShaderConstantEntryE8D* pkEntry)
{
    if (pkEntry)
    {
        ShaderConstantEntryE8D* pkTemp = pkEntry;
        --pkTemp->m_iRefCount;
        if (pkTemp->m_iRefCount == 0)
            pkTemp->Destroy();
    }
}

class ShaderConstantMapE8D
{
  public:
    int AddEntry(void* pvList, ShaderConstantEntryE8D* pkEntry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* m_pvEntries;
    unsigned int m_uiStreamIndex;
};
extern ShaderConstantMapE8D* g_pkConstantMapE8D;

void __cdecl CreateEntryE8D(ShaderConstantEntryE8D** ppkEntry);
bool __cdecl LookupPredefinedE8D(const char* pcName, unsigned int* puiType);
bool __cdecl LookupObjectE8D(const char* pcName, unsigned int* puiType);

// Creates and adds an entry, then sets its fields according to predefined or object lookup results.
// @fnv 0x00e8d630
bool __stdcall AddShaderConstant(unsigned int uiFlags, unsigned int* puiIndex, const char* pcName,
                                 unsigned int uiUnused3, unsigned int uiExtra)
{
    if (uiFlags >= 1)
        return false;

    ShaderConstantMapE8D* pkMap = g_pkConstantMapE8D;
    if (!pkMap)
        return false;

    ShaderConstantEntryE8D* pkEntry = 0;
    CreateEntryE8D(&pkEntry);
    if (pkMap->AddEntry(pkMap->m_pvEntries, pkEntry))
    {
        ReleaseEntryE8D(pkEntry);
        return false;
    }
    *puiIndex = pkMap->m_uiStreamIndex - 1;

    unsigned int uiConstantType = 0;
    if (LookupPredefinedE8D(pcName, &uiConstantType))
    {
        switch (uiConstantType)
        {
        case 0:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x200000);
            break;
        case 1:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x300000);
            break;
        case 2:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x400000);
            break;
        case 3:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x500000);
            break;
        case 4:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x600000);
            break;
        case 5:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x700000);
            break;
        case 6:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x800000);
            break;
        case 7:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x900000);
            break;
        case 8:
            SetFlagBitsE8D(pkEntry, 0xf00fffff, uiExtra | 0x1000000);
            break;
        case 9:
            SetFlagBitsE8D(pkEntry, 0xf00fffff, uiExtra | 0x2000000);
            break;
        default:
            ReleaseEntryE8D(pkEntry);
            return false;
        }
    }
    else if (LookupObjectE8D(pcName, &uiConstantType))
    {
        unsigned short usRegisterType = 0;
        switch (uiConstantType)
        {
        case 0:
            usRegisterType = 0x700;
            break;
        case 1:
            usRegisterType = 0x600;
            break;
        case 2:
            usRegisterType = 0x500;
            break;
        case 3:
            usRegisterType = 0x800;
            break;
        }
        pkEntry->m_usRegisterInfo = (usRegisterType & 0xff00) | uiExtra;
    }
    ReleaseEntryE8D(pkEntry);
    return true;
}

struct ShaderConstantList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    void** entries;
};

struct ShaderGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* property;
};

struct ShaderBaseView
{
    void FUN_00a8f3e0(void*, void*, void*, ShaderGeometry*, void*, void*, void*);
};

struct ShaderView : ShaderBaseView
{
    void BindShaderInput(void*, void*, void*);
    void FUN_00e8dc30(void*, void*, void*, ShaderGeometry*, void*, void*, void*);
};

// Iterates the global list, calls BindShaderInput for nonnull entries, then invokes the base class routine.
// @fnv 0x00e8dc30
// pdb: NiFragmentShaderInstanceDescriptor::`scalar deleting destructor' | NiXenonFragmentShader.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void ShaderView::FUN_00e8dc30(void* a, void* b, void* c, ShaderGeometry* geometry, void* e, void* f, void* g)
{
    ShaderConstantList* pConstantList = reinterpret_cast<ShaderConstantList*>(DAT_0126f74c);
    if (pConstantList)
    {
        for (unsigned int i = 0; i < pConstantList->count; ++i)
        {
            void* entry = pConstantList->entries[i];
            if (entry)
                BindShaderInput(entry, geometry->property, e);
        }
    }
    ShaderBaseView::FUN_00a8f3e0(a, b, c, geometry, e, f, g);
}

struct BinaryDataRecord
{
    unsigned int field00;
    unsigned short format;
    unsigned short field06;
    void* data;
};
struct StreamSet
{
    BinaryDataRecord* position;
    BinaryDataRecord* normal;
    BinaryDataRecord* color;
    BinaryDataRecord* weights;
    BinaryDataRecord* indices;
    BinaryDataRecord* tangent;
    BinaryDataRecord* binormal;
    BinaryDataRecord* extra;
    BinaryDataRecord* texcoords[1];
};
struct SkinData
{
    unsigned int field00, field04;
    unsigned short field08, count;
};
struct Geometry
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18, field1c;
    StreamSet* streams;
    unsigned short field24, streamCount;
    unsigned int field28;
    SkinData* skin;
    BinaryDataRecord* GetElementAt(unsigned int);
};
struct TextureProperty
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned char active;
    unsigned int field0a0;
    unsigned int field0a4;
    unsigned int field0a8;
    unsigned int field0ac;
    unsigned int field0b0;
    unsigned int field0b4;
    unsigned int field0b8;
    unsigned int field0bc;
    unsigned int field0c0;
    unsigned int field0c4;
    unsigned int field0c8;
    unsigned int field0cc;
    unsigned int field0d0;
    unsigned int field0d4;
    unsigned int field0d8;
    unsigned int field0dc;
    unsigned int field0e0;
    unsigned int field0e4;
    unsigned int field0e8;
    unsigned int field0ec;
    unsigned int field0f0;
    unsigned int field0f4;
    unsigned int field0f8;
    unsigned int field0fc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    void* data;
    unsigned int format;
    unsigned int dimension;
};
struct PropertyNode
{
    PropertyNode* next;
    TextureProperty* data;
};
struct PropertyState
{
    unsigned int field00, field04, field08, field0c;
    PropertyNode* first;
    PropertyNode* second;
    TextureProperty* primary;
    TextureProperty* secondary;
    __forceinline TextureProperty* Find(PropertyNode* node, unsigned int index, unsigned int found)
    {
        while (node)
        {
            TextureProperty* texture = node->data;
            node = node->next;
            if (texture && texture->active == 1 && (unsigned short)found++ == (unsigned short)index)
                return texture;
        }
        return 0;
    }
};
struct BeamTextureState
{
    void SetStageValue(unsigned int, unsigned int, bool);
};
struct Descriptor
{
    unsigned int field00, field04;
    void* data;
    unsigned int selector;
    BeamTextureState* state;
    unsigned int field14, field18, field1c, field20, field24, field28, field2c;
    unsigned int field30, field34, field38, field3c, field40, field44, field48, field4c;
    unsigned int field50, field54, field58;
    unsigned short property;
    unsigned int FUN_00e7ddf0();
    bool QueryFlagB();
    void ApplyPairToState(unsigned int);
    void FUN_00e7def0(unsigned int);
};
struct ShaderHost
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18;
    void BindShaderInput(Descriptor* descriptor, Geometry* geometry, PropertyState* properties);
};
static __forceinline BinaryDataRecord* LookupStream(Geometry* geometry, unsigned int selector)
{
    unsigned int category = selector & 0x0f000000;
    if (category == 0)
    {
        switch (selector & 0x00f00000)
        {
        case 0x200000:
            return geometry->streams->position;
        case 0x300000:
            return geometry->streams->normal;
        case 0x400000:
            return geometry->streams->color;
        case 0x500000:
            return geometry->streams->weights;
        case 0x600000:
            return geometry->streams->indices;
        case 0x700000:
            return geometry->streams->tangent;
        case 0x800000:
            return geometry->streams->binormal;
        case 0x900000:
            return geometry->streams->extra;
        }
    }
    else if (category == 0x01000000)
    {
        if ((unsigned short)selector < (unsigned int)(geometry->streamCount - 8))
            return geometry->streams->texcoords[(unsigned short)selector];
    }
    else if (category == 0x02000000)
    {
        SkinData* skin = geometry->skin;
        unsigned int slot = (unsigned short)selector;
        if (skin && slot < skin->count)
            return geometry->GetElementAt(slot);
    }
    return 0;
}

// Resolves a descriptor's property or stream selector into data, dimension, and format, then applies them to the descriptor's state.
// @f3 0x00886b00 (community match, verified in this file)
namespace task1920 {
void __cdecl FUN_00886420(void*,unsigned int,bool,unsigned int);
struct BinaryDataRecord
{
    unsigned int field00;
    unsigned short format;
    unsigned short field06;
    void* data;
};
struct StreamSet
{
    BinaryDataRecord* position;
    BinaryDataRecord* normal;
    BinaryDataRecord* color;
    BinaryDataRecord* weights;
    BinaryDataRecord* indices;
    BinaryDataRecord* tangent;
    BinaryDataRecord* binormal;
    BinaryDataRecord* extra;
    BinaryDataRecord* texcoords[1];
};
struct SkinData
{
    unsigned int field00, field04;
    unsigned short field08, count;
};
struct Geometry
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18, field1c;
    StreamSet* streams;
    unsigned short field24, streamCount;
    unsigned int field28;
    SkinData* skin;
    BinaryDataRecord* FUN_008865c0(unsigned int);
};
struct TextureProperty
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned char active;
    unsigned int field0a0;
    unsigned int field0a4;
    unsigned int field0a8;
    unsigned int field0ac;
    unsigned int field0b0;
    unsigned int field0b4;
    unsigned int field0b8;
    unsigned int field0bc;
    unsigned int field0c0;
    unsigned int field0c4;
    unsigned int field0c8;
    unsigned int field0cc;
    unsigned int field0d0;
    unsigned int field0d4;
    unsigned int field0d8;
    unsigned int field0dc;
    unsigned int field0e0;
    unsigned int field0e4;
    unsigned int field0e8;
    unsigned int field0ec;
    unsigned int field0f0;
    unsigned int field0f4;
    unsigned int field0f8;
    unsigned int field0fc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    void* data;
    unsigned int format;
    unsigned int dimension;
};
struct PropertyNode
{
    PropertyNode* next;
    TextureProperty* data;
};
struct PropertyState
{
    unsigned int field00, field04, field08, field0c;
    PropertyNode* first;
    PropertyNode* second;
    TextureProperty* primary;
    TextureProperty* secondary;
    __forceinline TextureProperty* Find(PropertyNode* node, unsigned int index, unsigned int found)
    {
        while (node)
        {
            TextureProperty* texture = node->data;
            node = node->next;
            if (texture && texture->active == 1 && (unsigned short)found++ == (unsigned short)index)
                return texture;
        }
        return 0;
    }
};
struct BeamTextureState
{
    void FUN_0088e690(unsigned int, unsigned int, bool);
};
struct Descriptor
{
    unsigned int field00, field04;
    void* data;
    unsigned int selector;
    BeamTextureState* state;
    unsigned int field14, field18, field1c, field20, field24, field28, field2c;
    unsigned int field30, field34, field38, field3c, field40, field44, field48, field4c;
    unsigned int field50, field54, field58;
    unsigned short property;
    unsigned int FUN_00886380();
    bool FUN_008863c0();
    void FUN_0088f050(unsigned int);
    void FUN_0088f0b0(unsigned int);
};
struct HostView
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18;
    void BindShaderInput(Descriptor* descriptor, Geometry* geometry, PropertyState* properties);
};
static __forceinline BinaryDataRecord* LookupStream(Geometry* geometry, unsigned int selector)
{
    unsigned int category = selector & 0x0f000000;
    if (category == 0)
    {
        switch (selector & 0x00f00000)
        {
        case 0x200000:
            return geometry->streams->position;
        case 0x300000:
            return geometry->streams->normal;
        case 0x400000:
            return geometry->streams->color;
        case 0x500000:
            return geometry->streams->weights;
        case 0x600000:
            return geometry->streams->indices;
        case 0x700000:
            return geometry->streams->tangent;
        case 0x800000:
            return geometry->streams->binormal;
        case 0x900000:
            return geometry->streams->extra;
        }
    }
    else if (category == 0x01000000)
    {
        if ((unsigned short)selector < (unsigned int)(geometry->streamCount - 8))
            return geometry->streams->texcoords[(unsigned short)selector];
    }
    else if (category == 0x02000000)
    {
        SkinData* skin = geometry->skin;
        unsigned int slot = (unsigned short)selector;
        if (skin && slot < skin->count)
            return geometry->FUN_008865c0(slot);
    }
    return 0;
}

}
void ShaderHost::BindShaderInput(Descriptor* descriptorInput, Geometry* geometryInput, PropertyState* propertiesInput)
{
    using namespace task1920;
    task1920::Descriptor* descriptor = reinterpret_cast<task1920::Descriptor*>(descriptorInput);
    task1920::Geometry* geometry = reinterpret_cast<task1920::Geometry*>(geometryInput);
    task1920::PropertyState* properties = reinterpret_cast<task1920::PropertyState*>(propertiesInput);
    task1920::HostView* self = reinterpret_cast<task1920::HostView*>(this);
    unsigned short property = descriptor->property;
    unsigned int selector = descriptor->selector;
    void* data = 0;
    unsigned int dimension = 0;
    unsigned int format = 0;
    if (!property)
    {
        if (selector)
        {
            task1920::BinaryDataRecord* stream = task1920::LookupStream(geometry, selector);
            if (stream)
            {
                unsigned int packed = stream->format;
                data = stream->data;
                dimension = (packed >> 12) & 3;
                format = (packed >> 8) & 15;
                if ((selector & 0xf0000000) == 0x10000000)
                {
                    unsigned int value = *reinterpret_cast<const unsigned char*>(&stream->format);
                    value |= descriptor->FUN_00886380() & 0xffff0000;
                    bool flag = descriptor->FUN_008863c0();
                    descriptor->state->FUN_0088e690(11, value, flag);
                }
            }
        }
    }
    else
    {
        unsigned int found = 0;
        if (!properties)
            goto finish;
        unsigned short index = property & 0xff;
        task1920::TextureProperty* texture = 0;
        switch (property >> 8)
        {
        case 5:
            texture = properties->primary;
            goto check;
        case 6:
            texture = properties->Find(properties->second, index, found);
            break;
        case 7:
            texture = properties->Find(properties->first, index, found);
            break;
        case 8:
            texture = properties->secondary;
        check:
            if (!texture || !texture->active)
                goto finish;
            break;
        }
        if (texture)
        {
            data = texture->data;
            dimension = texture->dimension;
            format = texture->format;
            if ((selector & 0xf0000000) == 0x10000000)
                task1920::FUN_00886420(texture, (unsigned int)descriptor, descriptor->FUN_008863c0(), self->field18);
        }
    }
finish:
    descriptor->data = data;
    descriptor->FUN_0088f050(dimension);
    descriptor->FUN_0088f0b0(format);
}

