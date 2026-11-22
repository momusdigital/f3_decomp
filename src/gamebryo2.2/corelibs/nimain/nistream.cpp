// gamebryo2.2/corelibs/nimain/nistream.cpp: NiStream, NiStreamImpl, ThisObj, Receiver and more (59 functions)
#include "nistream_cpp_decls.h"
#include "NiGlobalStringTable.h"

// @fnv 0x00A634E0
// pdb: NiStream::GetGroupFromID | NiStream.obj | fnv360_0822_retail, call_seq, high
// pdb params: uiID
NiObjectGroup* NiStream::GetObjectGroup(unsigned int groupID)
{
    return m_kGroups.m_pBase[groupID];
}

// @fnv 0x00A63430
// pdb: NiStream::GetObjectFromLinkID | NiStream.obj | fnv360_0822_retail, call_seq, high
NiObject* NiStream::GetLoadedObject()
{
    unsigned int linkIndex = m_uiLinkIndex;
    m_uiLinkIndex = linkIndex + 1;
    unsigned int linkID = m_kLinkIDs.m_pBase[linkIndex];
    if (linkID == 0xFFFFFFFF)
        return 0;
    return m_kObjects.m_pBase[linkID].m_pObject;
}

// @fnv 0x00A64700
// pdb: NiStream::SetNumberOfLinkIDs | NiStream.obj | fnv360_0822_retail, caller, high
// pdb params: uiLinks
void NiStream::SetLinkIDCount(unsigned int numberOfLinkIDs)
{
    NiStreamLinkIDSet& linkIDBlocks = (NiStreamLinkIDSet&)m_kLinkIDBlocks;
    if (linkIDBlocks.m_uiUsed == linkIDBlocks.m_uiAlloced)
    {
        unsigned int allocationCount = linkIDBlocks.m_uiAlloced;
        if (allocationCount > 0)
            allocationCount *= 2;
        else
            allocationCount = 1;
        linkIDBlocks.Realloc(allocationCount);
    }
    linkIDBlocks.m_pBase[linkIDBlocks.m_uiUsed] = numberOfLinkIDs;
    ++linkIDBlocks.m_uiUsed;
}

// @fnv 0x00A635B0
// pdb: NiStream::RegisterObjects | NiStream.obj | fnv360_0822_retail, vtable, high
void NiStream::RegisterObjects()
{
    for (unsigned int index = 0; index < m_kTopObjects.m_uiSize; ++index)
    {
        NiObject* pkObject = m_kTopObjects.m_pBase[index].m_pObject;
        pkObject->RegisterStreamables(*this);
    }
}

// @fnv 0x00A63380
// pdb: NiStream::Save | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: pkOstr
bool NiStream::Save(NiBinaryStream* stream)
{
    m_pkOstr = stream;
    typedef bool(__thiscall * SaveFunction)(NiStream*);
    bool result = ((SaveFunction*)m_ppVirtualMethodTable)[16](this);
    m_pkOstr = 0;
    return result;
}

// @fnv 0x00A633D0
// pdb: TESEffectShader::StopParticleShader | TESEffectShader.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BGSProcedureFleeExecState::SetFleeSucceeded)
// pdb params: apTargetObject, apProp
void NiStream::GetTexture(const char* textureName, NiPointer<NiTexture>& texture)
{
    fnv_NiStreamGetTexture(textureName, texture);
}

// @fnv 0x00A636F0
// pdb: NiStream::SetFilePath | NiStream.obj | fnv360_0822_retail, call_gap, high
// pdb params: pcFilePath
void NiStream::SetStreamPath(const char* path)
{
    if (path != 0 && path[0] != '\0')
    {
        char* destination = m_acFilePath;
        fnv_CopyFilePath(destination, 0x104, path, 0x103);
        fnv_StandardizeFilePath(destination);
    }
    else
    {
        m_acFilePath[0] = '\0';
    }
}

// @fnv 0x00A63330
// pdb: NiStream::Load | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: pkIstr
bool NiStream::Load(NiBinaryStream* stream)
{
    typedef bool(__thiscall * StreamReadyFunction)(NiBinaryStream*);
    if (!((StreamReadyFunction*)stream->m_ppVirtualMethodTable)[1](stream))
    {
        m_pkIstr = 0;
        return false;
    }
    m_pkIstr = stream;
    bool result = ((NiStreamVirtualView*)this)->Load();
    m_pkIstr = 0;
    return result;
}

// @fnv 0x00A644F0
// pdb: NiStream::RemoveAllObjects | NiStream.obj | fnv360_0822_retail, call_gap, high
void NiStream::ClearTopLevelObjects()
{
    fnv_EnterCriticalSection(&fnv_NiStreamCriticalSection);
    ((NiStreamTopObjects&)m_kTopObjects).RemoveAll();
    ((NiStreamFixedStrings&)m_kFixedStrings).RemoveAll();
    for (unsigned int index = 0; index < m_kObjectSizes.m_uiSize; ++index)
        m_kObjectSizes.m_pBase[index] = 0;
    m_kObjectSizes.m_uiSize = 0;
    m_kObjectSizes.m_uiESize = 0;
    fnv_LeaveCriticalSection(&fnv_NiStreamCriticalSection);
}

// @fnv 0x00A64920
// pdb: NiStream::RegisterPostProcessFunction | NiStream.obj | fnv360_0822_retail, call_seq, high
// pdb params: pfnFunc
void NiStream::RegisterPostProcess(NiStreamPostProcess function)
{
    DAT_011f4788->AddPostProcess(function);
}

// @fnv 0x00A64900
// pdb: NiStream::RegisterLoader | NiStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pcName, pfnFunc
int NiStream::RegisterObjectLoader(const char* name, NiObject*(__cdecl* loader)())
{
    DAT_011f4784->SetAt(name, (NiShader*)loader);
    return 0;
}

// @fnv 0x00A636B0
// pdb: NiStream::GetNextSearchPath | NiStream.obj | fnv360_0822_retail, call_gap, high
// pdb params: pcPath, uiStringLen
bool NiStream::GetLastLoadedFilePath(char* buffer, unsigned int size)
{
    if (DAT_011f4780)
    {
        fnv_CopyFilePath(buffer, 0x104, m_acFilePath, 0x103);
        DAT_011f4780 = false;
        return true;
    }
    return false;
}

// @fnv 0x00A632F0
// pdb: NiStream::Load | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: pcBuffer, iBufferSize
bool NiStream::Load(char* buffer, int size)
{
    NiStreamMemoryBuffer stream;
    stream.FUN_00aa2fb0(buffer, size);
    typedef bool(__thiscall * NiStreamLoadFunction)(NiStream*, NiBinaryStream*);
    bool result = ((NiStreamLoadFunction*)m_ppVirtualMethodTable)[1](this, &stream);
    stream.NiMemStreamDestructor();
    return result;
}

// @fnv 0x00A635E0
// pdb: NiStream::Save | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: pcBuffer, iBufferSize
bool NiStream::Save(char*& buffer, int& size)
{
    NiStreamMemoryBuffer stream;
    stream.FUN_00aa2ff0();
    typedef bool(__thiscall * SaveFunction)(NiStream*, NiBinaryStream*);
    bool result = ((SaveFunction*)m_ppVirtualMethodTable)[4](this, &stream);
    size = stream.m_uiLogicalSize;
    buffer = stream.NiMemStream_Str();
    stream.NiMemStreamDestructor();
    return result;
}

// @fnv 0x00A64620
// pdb: NiStream::ResolveLinkID | NiStream.obj | fnv360_0822_retail, call_seq, medium
NiObject* NiStream::DeserializeObject()
{
    unsigned int linkID;
    NiStreamReadUInt(m_pkIstr, linkID);
    if (linkID == 0xFFFFFFFF)
        return 0;
    return m_kObjects.m_pBase[linkID].m_pObject;
}

// @fnv 0x00A64550
// pdb: NiStream::ChangeObject | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: pkNewObject
void NiStream::ChangeObject(NiObject* object)
{
    NiObject* pointer = object;
    if (object)
        object->IncRefCount();
    ((NiStreamTopObjects&)m_kObjects)
        .FUN_00cc1a10(m_uiLoad, reinterpret_cast<const NiPointer<NiObject>&>(pointer));
    if (object)
        object->DecRefCount();
}

// @fnv 0x00A63D80
// pdb: NiStream::SaveTopLevelObjects | NiStream.obj | fnv360_0822_retail, vtable, high
void NiStream::SaveTopLevelObjects()
{
    unsigned int count = m_kTopObjects.m_uiSize;
    NiStreamWriteUInt(m_pkOstr, count);
    for (unsigned int index = 0; index < count; ++index)
    {
        typedef void(__thiscall * SaveLinkIDFunction)(NiStream*, const NiObject*);
        ((SaveLinkIDFunction*)m_ppVirtualMethodTable)[12](this, m_kTopObjects.m_pBase[index].m_pObject);
    }
}

// @fnv 0x00A66370
// pdb: NiStream::InsertObject | NiStream.obj | fnv360_0822_retail, call_gap, high
// pdb params: pkObject
void NiStream::InsertObject(NiObject* object)
{
    NiObject* pointer = object;
    if (object)
        object->IncRefCount();
    NiStreamTopObjects& objects = (NiStreamTopObjects&)m_kTopObjects;
    unsigned int index = objects.m_uiSize;
    if (index >= objects.m_uiMaxSize)
        objects.FUN_00a64fe0(index + objects.m_uiGrowBy);
    objects.FUN_00cc1a10(index, reinterpret_cast<const NiPointer<NiObject>&>(pointer));
    if (object)
        object->DecRefCount();
}

extern __declspec(thread) unsigned int t_uiMemContextC68;

class AutoMemContextC68
{
  public:
    AutoMemContextC68(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = t_uiMemContextC68;
        t_uiMemContextC68 = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextC68()
    {
        t_uiMemContextC68 = m_uiPrevious;
    }
    unsigned int m_uiPrevious;
};

class hkBoolC68
{
  public:
    hkBoolC68(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkMemoryAllocatorC68
{
  public:
    virtual ~hkMemoryAllocatorC68();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
};

class hkMallocAllocatorC68 : public hkMemoryAllocatorC68
{
  public:
    hkMallocAllocatorC68()
    {}
    virtual ~hkMallocAllocatorC68();
};

struct hkStackMemoryC68
{
    char* m_pcCur;
    char* m_pcStart;
    char* m_pcEnd;
};

struct hkMemoryRouterC68
{
    hkStackMemoryC68 m_kStack;
    hkMemoryAllocatorC68* m_pkTemp;
    hkMemoryAllocatorC68* m_pkHeap;
    hkMemoryAllocatorC68* m_pkDebug;
    hkMemoryAllocatorC68* m_pkSolver;
    hkMemoryAllocatorC68& heap()
    {
        return *m_pkHeap;
    }
};
hkMemoryRouterC68* __cdecl GetMemoryRouterC68();

class hkMemorySystemC68
{
  public:
    struct FrameInfo
    {
        FrameInfo();
        int m_iSolverBufferSize;
        int m_iLargeBlockSize;
    };
    class Flags
    {
      public:
        Flags(int iFlags) : m_iFlags(iFlags)
        {}
        Flags(const Flags& kOther) : m_iFlags(kOther.m_iFlags)
        {}
        int m_iFlags;
    };
    virtual ~hkMemorySystemC68();
    virtual hkMemoryRouterC68* CreateMemoryRouter(const FrameInfo& kInfo, Flags kFlags);
    static void __cdecl ReplaceInstance(hkMemorySystemC68* pkSystem);
};

class hkFreeListMemorySystemC68 : public hkMemorySystemC68
{
  public:
    void* operator new(unsigned int, void* pvWhere)
    {
        return pvWhere;
    }
    void operator delete(void*, void*)
    {}
    hkFreeListMemorySystemC68();
    void setAllocator(hkMemoryAllocatorC68* pkAllocator);
};

typedef void(__cdecl* hkErrorReportFunctionC68)(const char* pcMessage, void* pvObject);
class hkBaseSystemC68
{
  public:
    static hkBoolC68 isInitialized()
    {
        return s_bInitialized;
    }
    static int __cdecl init(hkMemoryRouterC68* pkRouter, hkErrorReportFunctionC68 pfnErrorReport,
                            void* pvErrorReportObject);
    static bool s_bInitialized;
};

class hkReferencedObjectC68
{
  public:
    void* operator new(unsigned int uiBytes)
    {
        hkReferencedObjectC68* b =
            static_cast<hkReferencedObjectC68*>(GetMemoryRouterC68()->heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    void operator delete(void* p, unsigned int)
    {
        hkReferencedObjectC68* b = static_cast<hkReferencedObjectC68*>(p);
        GetMemoryRouterC68()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
    virtual ~hkReferencedObjectC68();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpContactListenerC68
{
  public:
    virtual void ProcessContactEvent(void* pvEvent);
};
class hkpEntityListenerC68
{
  public:
    virtual void EntityAddedCallback(void* pvEntity);
};
class hkpPhantomListenerC68
{
  public:
    virtual void PhantomAddedCallback(void* pvPhantom);
};
class hkpWorldDeletionListenerC68
{
  public:
    virtual void WorldDeletedCallback(void* pvWorld);
};

class bhkWorldListenerBaseC68 : public hkReferencedObjectC68,
                                public hkpContactListenerC68,
                                public hkpEntityListenerC68,
                                public hkpPhantomListenerC68,
                                public hkpWorldDeletionListenerC68
{
  public:
    bhkWorldListenerBaseC68();
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};

class bhkWorldListenerC68 : public bhkWorldListenerBaseC68
{
  public:
    bhkWorldListenerC68()
    {}
};

struct MemoryManagerC68
{
    void* Allocate(unsigned int uiSize);
    void Deallocate(void* pvMem);
};
extern MemoryManagerC68 g_kMemoryManagerC68;

class bhkSingletonC68
{
  public:
    void* operator new(unsigned int uiSize)
    {
        return g_kMemoryManagerC68.Allocate(uiSize);
    }
    void operator delete(void* pvMem)
    {
        g_kMemoryManagerC68.Deallocate(pvMem);
    }
    bhkSingletonC68();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

class NiObject;
typedef NiObject*(__cdecl* CreateFunctionC68)();

extern hkMemorySystemC68* g_pkMemorySystemC68;
inline hkMemorySystemC68& GetMemorySystemC68()
{
    return *g_pkMemorySystemC68;
}

// Initializes the Havok physics system, sets up memory router and stack, registers Havok object loaders, and creates the world listener and singleton.
// @f3 0x008d5000 (community match, verified in this file)
int __cdecl FUN_0082b9e0(const char*,NiObject* (__cdecl*)());
typedef void* (__cdecl *AlignedAllocFn)(unsigned int, int);
typedef void (__cdecl *AlignedFreeFn)(void*);
extern AlignedAllocFn DAT_00f7b4cc;
extern AlignedFreeFn DAT_00f7b4d0;
extern "C" void* __cdecl FUN_008d3ad0(unsigned int, int);
extern "C" void __cdecl FUN_008d36a0(void*);
struct SettingValueOld { unsigned int value, unk04, unk08; };
extern SettingValueOld DAT_010f2a90, DAT_010f2a9c, DAT_010f2aa8;
extern SettingValueOld DAT_010f2ab4, DAT_010f2ac0, DAT_010f2acc;
struct PhysicsSettingsOld { unsigned int a,b,c,d,e,f; };
extern PhysicsSettingsOld DAT_01169108;
extern bool DAT_010f3408;
extern unsigned int DAT_010f3170;
extern char DAT_01092a60[0x60000];
extern "C" __declspec(dllimport) void* __stdcall DAT_00d9b080(unsigned long);
struct FUN_008d3500 {
    virtual void Destroy(unsigned int);
    unsigned int unk004, unk008, unk00c;
    int references;
    unsigned int unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030;
    unsigned int unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050;
    unsigned int unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070;
    unsigned int unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090;
    unsigned int unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0;
    unsigned int unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0;
    unsigned int unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0;
    unsigned int unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110;
    unsigned int unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    unsigned int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150;
    unsigned int unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170;
    unsigned int unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190;
    unsigned int unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0;
    unsigned int unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0;
    unsigned int unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0;
    unsigned int unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210;
    unsigned int unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230;
    unsigned int unk234, unk238, unk23c, unk240, unk244, unk248, unk24c, unk250;
    unsigned int unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270;
    unsigned int unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290;
    unsigned int unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0;
    unsigned int unk2b4, unk2b8, unk2bc, unk2c0, unk2c4, unk2c8, unk2cc, unk2d0;
    unsigned int unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0;
    unsigned int unk2f4, unk2f8, unk2fc, unk300, unk304, unk308, unk30c, unk310;
    unsigned int unk314, unk318, unk31c, unk320, unk324, unk328, unk32c, unk330;
    unsigned int unk334, unk338, unk33c, unk340, unk344, unk348, unk34c, unk350;
    unsigned int unk354, unk358, unk35c, unk360, unk364, unk368, unk36c, unk370;
    unsigned int unk374, unk378, unk37c, unk380, unk384, unk388, unk38c, unk390;
    unsigned int unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0;
    unsigned int unk3b4, unk3b8, unk3bc, unk3c0, unk3c4, unk3c8, unk3cc, unk3d0;
    unsigned int unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0;
    unsigned int unk3f4, unk3f8, unk3fc, unk400, unk404, unk408, unk40c, unk410;
    unsigned int unk414, unk418, unk41c, unk420, unk424, unk428, unk42c, unk430;
    unsigned int unk434, unk438, unk43c, unk440, unk444, unk448, unk44c, unk450;
    unsigned int unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470;
    unsigned int unk474, unk478, unk47c, unk480, unk484, unk488, unk48c, unk490;
    unsigned int unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0;
    unsigned int unk4b4, unk4b8, unk4bc, unk4c0, unk4c4, unk4c8, unk4cc, unk4d0;
    unsigned int unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec, unk4f0;
    unsigned int unk4f4, unk4f8, unk4fc, unk500, unk504, unk508, unk50c, unk510;
    unsigned int unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530;
    unsigned int unk534, unk538, unk53c, unk540, unk544, unk548, unk54c, unk550;
    unsigned int unk554, unk558, unk55c, unk560, unk564, unk568, unk56c, unk570;
    unsigned int unk574, unk578, unk57c, unk580, unk584, unk588, unk58c, unk590;
    unsigned int unk594, unk598, unk59c, unk5a0, unk5a4, unk5a8, unk5ac, unk5b0;
    unsigned int unk5b4, unk5b8, unk5bc, unk5c0, unk5c4, unk5c8, unk5cc, unk5d0;
    unsigned int unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec, unk5f0;
    unsigned int unk5f4, unk5f8, unk5fc, unk600, unk604, unk608, unk60c, unk610;
    unsigned int unk614, unk618, unk61c, unk620, unk624, unk628, unk62c, unk630;
    unsigned int unk634, unk638, unk63c, unk640, unk644, unk648, unk64c, unk650;
    unsigned int unk654, unk658, unk65c, unk660, unk664, unk668, unk66c, unk670;
    unsigned int unk674, unk678, unk67c, unk680, unk684, unk688, unk68c, unk690;
    unsigned int unk694, unk698, unk69c, unk6a0, unk6a4, unk6a8, unk6ac, unk6b0;
    unsigned int unk6b4, unk6b8, unk6bc, unk6c0, unk6c4, unk6c8, unk6cc, unk6d0;
    unsigned int unk6d4, unk6d8, unk6dc, unk6e0, unk6e4, unk6e8, unk6ec, unk6f0;
    unsigned int unk6f4, unk6f8, unk6fc, unk700, unk704, unk708, unk70c, unk710;
    unsigned int unk714, unk718, unk71c, unk720, unk724, unk728, unk72c, unk730;
    unsigned int unk734, unk738, unk73c, unk740, unk744, unk748, unk74c, unk750;
    unsigned int unk754, unk758, unk75c, unk760, unk764, unk768, unk76c, unk770;
    unsigned int unk774, unk778, unk77c, unk780, unk784, unk788, unk78c, unk790;
    unsigned int unk794, unk798, unk79c, unk7a0, unk7a4, unk7a8, unk7ac, unk7b0;
    unsigned int unk7b4, unk7b8, unk7bc, unk7c0, unk7c4, unk7c8, unk7cc, unk7d0;
    unsigned int unk7d4, unk7d8, unk7dc, unk7e0, unk7e4, unk7e8, unk7ec, unk7f0;
    unsigned int unk7f4, unk7f8, unk7fc, unk800, unk804, unk808, unk80c, unk810;
    unsigned int unk814, unk818, unk81c, unk820, unk824, unk828, unk82c, unk830;
    unsigned int unk834, unk838, unk83c, unk840, unk844, unk848, unk84c, unk850;
    unsigned int unk854, unk858, unk85c, unk860, unk864, unk868, unk86c, unk870;
    unsigned int unk874, unk878, unk87c, unk880, unk884, unk888, unk88c, unk890;
    unsigned int unk894, unk898, unk89c, unk8a0, unk8a4, unk8a8, unk8ac, unk8b0;
    unsigned int unk8b4, unk8b8, unk8bc, unk8c0, unk8c4, unk8c8, unk8cc, unk8d0;
    unsigned int unk8d4, unk8d8, unk8dc, unk8e0, unk8e4, unk8e8, unk8ec, unk8f0;
    unsigned int unk8f4, unk8f8, unk8fc, unk900, unk904, unk908, unk90c, unk910;
    unsigned int unk914, unk918, unk91c, unk920, unk924, unk928, unk92c, unk930;
    unsigned int unk934, unk938, unk93c, unk940, unk944, unk948, unk94c, unk950;
    unsigned int unk954, unk958, unk95c, unk960, unk964, unk968, unk96c, unk970;
    unsigned int unk974, unk978, unk97c, unk980, unk984, unk988, unk98c, unk990;
    unsigned int unk994, unk998, unk99c, unk9a0, unk9a4, unk9a8, unk9ac, unk9b0;
    unsigned int unk9b4, unk9b8, unk9bc, unk9c0, unk9c4, unk9c8, unk9cc, unk9d0;
    unsigned int unk9d4, unk9d8, unk9dc, unk9e0, unk9e4, unk9e8, unk9ec, unk9f0;
    unsigned int unk9f4, unk9f8, unk9fc, unka00, unka04, unka08, unka0c, unka10;
    unsigned int unka14, unka18, unka1c, unka20, unka24;
    FUN_008d3500();
    static void* operator new(unsigned int size) { return DAT_00f7b4cc(size,16); }
    static void operator delete(void* p) { DAT_00f7b4d0(p); }
};
struct FUN_008f6a50 {
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    unsigned int unk320, unk324, unk328, unk32c;
    FUN_008f6a50(FUN_008d3500*,int);
    void FUN_008f67e0();
    static void* operator new(unsigned int size) { return DAT_00f7b4cc(size,16); }
    static void operator delete(void* p) { DAT_00f7b4d0(p); }
};
extern "C" void __cdecl FUN_006d4010(const char*,void*);
extern "C" void __cdecl FUN_0092eaa0(FUN_008d3500*,FUN_008f6a50*,void (__cdecl*)(const char*,void*),void*);
struct ThreadMemoryOld {
    virtual void Slot0();
    virtual void Slot4();
    virtual void SetStack(char*,int);
    void* FUN_008f6d30(unsigned int,int);
    void FUN_008f6de0(void*);
};
extern "C" void __cdecl FUN_008f4500();
extern unsigned int DAT_00e321cc, DAT_00e321c0, DAT_00e321ac, DAT_00e321a0, DAT_00e32194;
struct FUN_00943410 {
    unsigned int* vtable;
    unsigned short memorySize;
    short references;
    unsigned int* contactVtable;
    unsigned int* entityVtable;
    unsigned int* phantomVtable;
    unsigned int* worldVtable;
    unsigned int unk18,unk1c,unk20,unk24,unk28,unk2c;
    FUN_00943410();
};
struct PhysicsListenerOld : FUN_00943410 {
    PhysicsListenerOld() {
        vtable=&DAT_00e321cc;
        contactVtable=&DAT_00e321c0;
        entityVtable=&DAT_00e321ac;
        phantomVtable=&DAT_00e321a0;
        worldVtable=&DAT_00e32194;
    }
    static void* operator new(unsigned int size) {
        ThreadMemoryOld* memory=static_cast<ThreadMemoryOld*>(DAT_00d9b080(DAT_010f3170));
        FUN_00943410* block=static_cast<FUN_00943410*>(memory->FUN_008f6d30(size,39));
        block->memorySize=static_cast<unsigned short>(size);
        return block;
    }
    static void operator delete(void* p) {
        static_cast<ThreadMemoryOld*>(DAT_00d9b080(DAT_010f3170))->FUN_008f6de0(p);
    }
};
extern PhysicsListenerOld* DAT_010f2a68;
extern "C" NiObject* __cdecl FUN_00914160();
extern const char DAT_00e32644[];
extern "C" NiObject* __cdecl FUN_009523a0();
extern const char DAT_00e32630[];
extern "C" NiObject* __cdecl FUN_009520e0();
extern const char DAT_00e3261c[];
extern "C" NiObject* __cdecl FUN_00951750();
extern const char DAT_00e32604[];
extern "C" NiObject* __cdecl FUN_009509f0();
extern const char DAT_00e325ec[];
extern "C" NiObject* __cdecl FUN_00950290();
extern const char DAT_00e325d8[];
extern "C" NiObject* __cdecl FUN_0094ee20();
extern const char DAT_00e325bc[];
extern "C" NiObject* __cdecl FUN_0094f1b0();
extern const char DAT_00e325a4[];
extern "C" NiObject* __cdecl FUN_00929f30();
extern const char DAT_00e32590[];
extern "C" NiObject* __cdecl FUN_00912430();
extern const char DAT_00e32580[];
extern "C" NiObject* __cdecl FUN_00912430();
extern const char DAT_00e3256c[];
extern "C" NiObject* __cdecl FUN_00911230();
extern const char DAT_00e32550[];
extern "C" NiObject* __cdecl FUN_0090f0a0();
extern const char DAT_00e32538[];
extern "C" NiObject* __cdecl FUN_0094e680();
extern const char DAT_00e32528[];
extern "C" NiObject* __cdecl FUN_0090ea60();
extern const char DAT_00e32518[];
extern "C" NiObject* __cdecl FUN_0094dfa0();
extern const char DAT_00e32504[];
extern "C" NiObject* __cdecl FUN_0094d550();
extern const char DAT_00e324f0[];
extern "C" NiObject* __cdecl FUN_008fdb40();
extern const char DAT_00e324dc[];
extern "C" NiObject* __cdecl FUN_0091d0c0();
extern const char DAT_00e324cc[];
extern "C" NiObject* __cdecl FUN_008fcaf0();
extern const char DAT_00e324bc[];
extern "C" NiObject* __cdecl FUN_0094cea0();
extern const char DAT_00e324a0[];
extern "C" NiObject* __cdecl FUN_0094c670();
extern const char DAT_00e32480[];
extern "C" NiObject* __cdecl FUN_00930eb0();
extern const char DAT_00e3246c[];
extern "C" NiObject* __cdecl FUN_0094be90();
extern const char DAT_00e32450[];
extern "C" NiObject* __cdecl FUN_0094b8c0();
extern const char DAT_00e3243c[];
extern "C" NiObject* __cdecl FUN_0091c190();
extern const char DAT_00e32420[];
extern "C" NiObject* __cdecl FUN_0094b000();
extern const char DAT_00e32408[];
extern "C" NiObject* __cdecl FUN_00949aa0();
extern const char DAT_00e323f0[];
extern "C" NiObject* __cdecl FUN_00949280();
extern const char DAT_00e323d4[];
extern "C" NiObject* __cdecl FUN_00948c60();
extern const char DAT_00e323b8[];
extern "C" NiObject* __cdecl FUN_00948240();
extern const char DAT_00e323a4[];
extern "C" NiObject* __cdecl FUN_00947a60();
extern const char DAT_00e3238c[];
extern "C" NiObject* __cdecl FUN_0091b910();
extern const char DAT_00e32374[];
extern "C" NiObject* __cdecl FUN_00947410();
extern const char DAT_00e3235c[];
extern "C" NiObject* __cdecl FUN_00946d30();
extern const char DAT_00e32348[];
extern "C" NiObject* __cdecl FUN_0092f610();
extern const char DAT_00e32338[];
extern "C" NiObject* __cdecl FUN_008f8dd0();
extern const char DAT_00e32320[];
extern "C" NiObject* __cdecl FUN_00946650();
extern const char DAT_00e32310[];
extern "C" NiObject* __cdecl FUN_0092c0c0();
extern const char DAT_00e322f4[];
extern "C" NiObject* __cdecl FUN_00945f10();
extern const char DAT_00e322e4[];
extern "C" NiObject* __cdecl FUN_0090dfd0();
extern const char DAT_00e322d4[];
extern "C" NiObject* __cdecl FUN_008d1f60();
extern const char DAT_00e31988[];
extern "C" NiObject* __cdecl FUN_008f9520();
extern const char DAT_00e322c0[];
extern "C" NiObject* __cdecl FUN_00929d60();
extern const char DAT_00e322a8[];
extern "C" NiObject* __cdecl FUN_008f33c0();
extern const char DAT_00e32290[];
extern "C" NiObject* __cdecl FUN_00914d40();
extern const char DAT_00e3227c[];
extern "C" NiObject* __cdecl FUN_00900790();
extern const char DAT_00e3226c[];
extern "C" NiObject* __cdecl FUN_009261e0();
extern const char DAT_00e3225c[];
extern "C" NiObject* __cdecl FUN_0090e500();
extern const char DAT_00e32244[];
extern "C" NiObject* __cdecl FUN_009458c0();
extern const char DAT_00e3222c[];
extern "C" NiObject* __cdecl FUN_00945530();
extern const char DAT_00e3221c[];
extern "C" NiObject* __cdecl FUN_0092db30();
extern const char DAT_00e32208[];
extern "C" NiObject* __cdecl FUN_0092d520();
extern const char DAT_00e321f0[];
extern "C" NiObject* __cdecl FUN_00944990();
extern const char DAT_00e321e0[];

// pdb: bhkWorld::InitSystem | bhkWorld.obj | fnv360_0822_retail, ustr, high
// pdb: bhkWorld::InitSystem | bhkWorld.obj | fnv360_0822_retail, ustr, high (was: InitHavokPhysics)
void bhkWorld_InitSystem() {
    DAT_01169108.a=DAT_010f2a90.value;
    DAT_01169108.b=DAT_010f2a9c.value;
    DAT_01169108.c=DAT_010f2aa8.value;
    DAT_01169108.d=DAT_010f2ab4.value;
    DAT_01169108.e=DAT_010f2ac0.value;
    DAT_01169108.f=DAT_010f2acc.value;
    bool needsInit=!hkBoolC68(DAT_010f3408);
    if (needsInit) {
        DAT_00f7b4cc=FUN_008d3ad0;
        DAT_00f7b4d0=FUN_008d36a0;
        FUN_008d3500* allocator=new FUN_008d3500;
        FUN_008f6a50* secondary=new FUN_008f6a50(allocator,16);
        FUN_0092eaa0(allocator,secondary,FUN_006d4010,0);
        if (--allocator->references==0) allocator->Destroy(1);
        secondary->FUN_008f67e0();
        char* stack=DAT_01092a60;
        int size=sizeof(DAT_01092a60);
        int misalign=(int)stack&15;
        if (misalign) {
            int adjustment=16-misalign;
            stack+=adjustment;
            size-=adjustment;
        }
        static_cast<ThreadMemoryOld*>(DAT_00d9b080(DAT_010f3170))->SetStack(stack,size);
        FUN_008f4500();
        DAT_010f2a68=new PhysicsListenerOld;
        FUN_0082b9e0(DAT_00e32644,FUN_00914160);
        FUN_0082b9e0(DAT_00e32630,FUN_009523a0);
        FUN_0082b9e0(DAT_00e3261c,FUN_009520e0);
        FUN_0082b9e0(DAT_00e32604,FUN_00951750);
        FUN_0082b9e0(DAT_00e325ec,FUN_009509f0);
        FUN_0082b9e0(DAT_00e325d8,FUN_00950290);
        FUN_0082b9e0(DAT_00e325bc,FUN_0094ee20);
        FUN_0082b9e0(DAT_00e325a4,FUN_0094f1b0);
        FUN_0082b9e0(DAT_00e32590,FUN_00929f30);
        FUN_0082b9e0(DAT_00e32580,FUN_00912430);
        FUN_0082b9e0(DAT_00e3256c,FUN_00912430);
        FUN_0082b9e0(DAT_00e32550,FUN_00911230);
        FUN_0082b9e0(DAT_00e32538,FUN_0090f0a0);
        FUN_0082b9e0(DAT_00e32528,FUN_0094e680);
        FUN_0082b9e0(DAT_00e32518,FUN_0090ea60);
        FUN_0082b9e0(DAT_00e32504,FUN_0094dfa0);
        FUN_0082b9e0(DAT_00e324f0,FUN_0094d550);
        FUN_0082b9e0(DAT_00e324dc,FUN_008fdb40);
        FUN_0082b9e0(DAT_00e324cc,FUN_0091d0c0);
        FUN_0082b9e0(DAT_00e324bc,FUN_008fcaf0);
        FUN_0082b9e0(DAT_00e324a0,FUN_0094cea0);
        FUN_0082b9e0(DAT_00e32480,FUN_0094c670);
        FUN_0082b9e0(DAT_00e3246c,FUN_00930eb0);
        FUN_0082b9e0(DAT_00e32450,FUN_0094be90);
        FUN_0082b9e0(DAT_00e3243c,FUN_0094b8c0);
        FUN_0082b9e0(DAT_00e32420,FUN_0091c190);
        FUN_0082b9e0(DAT_00e32408,FUN_0094b000);
        FUN_0082b9e0(DAT_00e323f0,FUN_00949aa0);
        FUN_0082b9e0(DAT_00e323d4,FUN_00949280);
        FUN_0082b9e0(DAT_00e323b8,FUN_00948c60);
        FUN_0082b9e0(DAT_00e323a4,FUN_00948240);
        FUN_0082b9e0(DAT_00e3238c,FUN_00947a60);
        FUN_0082b9e0(DAT_00e32374,FUN_0091b910);
        FUN_0082b9e0(DAT_00e3235c,FUN_00947410);
        FUN_0082b9e0(DAT_00e32348,FUN_00946d30);
        FUN_0082b9e0(DAT_00e32338,FUN_0092f610);
        FUN_0082b9e0(DAT_00e32320,FUN_008f8dd0);
        FUN_0082b9e0(DAT_00e32310,FUN_00946650);
        FUN_0082b9e0(DAT_00e322f4,FUN_0092c0c0);
        FUN_0082b9e0(DAT_00e322e4,FUN_00945f10);
        FUN_0082b9e0(DAT_00e322d4,FUN_0090dfd0);
        FUN_0082b9e0(DAT_00e31988,FUN_008d1f60);
        FUN_0082b9e0(DAT_00e322c0,FUN_008f9520);
        FUN_0082b9e0(DAT_00e322a8,FUN_00929d60);
        FUN_0082b9e0(DAT_00e32290,FUN_008f33c0);
        FUN_0082b9e0(DAT_00e3227c,FUN_00914d40);
        FUN_0082b9e0(DAT_00e3226c,FUN_00900790);
        FUN_0082b9e0(DAT_00e3225c,FUN_009261e0);
        FUN_0082b9e0(DAT_00e32244,FUN_0090e500);
        FUN_0082b9e0(DAT_00e3222c,FUN_009458c0);
        FUN_0082b9e0(DAT_00e3221c,FUN_00945530);
        FUN_0082b9e0(DAT_00e32208,FUN_0092db30);
        FUN_0082b9e0(DAT_00e321f0,FUN_0092d520);
        FUN_0082b9e0(DAT_00e321e0,FUN_00944990);
    }
}


extern int(__stdcall* DAT_00fdf1c4)(void*);
extern char* EmptyFS;
extern char* DAT_011f3ec0;
extern char* DAT_011f3ec4;

// @fnv 0x00a42230
// pdb: NiActorManager::_SDMShutdown | NiActorManager.obj | fnv360_0822_retail, call_seq, medium
void __cdecl ClearGlobalStrings()
{
    char* old = DAT_011f3ec0;
    int(__stdcall * pfn)(void*) = DAT_00fdf1c4;
    if (old)
    {
        DAT_011f3ec0 = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            pfn((void*)(old - 8));
    }
    old = DAT_011f3ec4;
    if (old)
    {
        DAT_011f3ec4 = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            pfn((void*)(old - 8));
    }
}

struct S_00a48070_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    char m_acFileName[0x104];  // src: FNV360_PDB +0xE0 (old: m_acInputFilePath)
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    unsigned int m_uiLastError;  // src: FNV360_PDB +0x3B8 (old: m_uiNativeThreadId)
    char m_acLastErrorMessage[0x104];  // src: FNV360_PDB +0x3BC (old: m_acSecondPathBuffer)
    char m_acLastPath[0x104];
    void FUN_00a66150();
    void FUN_00a65300();
    bool OpenFile(const char* p);
};

struct S_00a48070_Ref
{
    virtual void unk0();
    virtual void DeleteThis();
    int m_uiRefCount;
};
void GetGPUProgram(S_00a48070_Obj* obj, int a, S_00a48070_Ref** b, void* c);
// Initializes obj, releases and clears p3 when OpenFile returns false, otherwise calls GetGPUProgram, then finalizes obj.
// @fnv 0x00a48070
// pdb: NiSequence::CreateFromKFFile | NiSequence.obj | fnv360_0721_beta, call_seq, high
// pdb params: pcSequenceFile, uiIndex, aspSequence, pcSequenceName
void CreateOrReleaseRef(const char* apPath, int p2, S_00a48070_Ref** ppRef, void* p4)
{
    S_00a48070_Obj obj;
    obj.FUN_00a66150();
    if (!obj.OpenFile(apPath))
    {
        S_00a48070_Ref* pOldRef = *ppRef;
        if (pOldRef)
        {
            if (InterlockedDecrement((long*)&pOldRef->m_uiRefCount) == 0)
                pOldRef->DeleteThis();
            *ppRef = 0;
        }
    }
    else
    {
        GetGPUProgram(&obj, p2, ppRef, p4);
    }
    obj.FUN_00a65300();
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
void __fastcall _Call_a5d3a0(void*);
extern int DAT_010984ec;
struct Obj
{
    void* vtable;
    int f04;
    int f08;
    int f0C;
    int f10;
    unsigned char f14;
};
// @fnv 0x00a48110
void* FUN_00a48110()
{
    Obj* p = (Obj*)BSFadeNode::operator new(0x18);
    if (p)
    {
        _Call_a5d3a0(p);
        p->f08 = 0;
        p->f0C = 0;
        p->f10 = 0;
        p->f14 = 0;
        p->vtable = &DAT_010984ec;
        return p;
    }
    return 0;
}

void __cdecl FUN_00a61c50(NiObject* pkObject, void* pvArg);

// @fnv 0x00a633b0
// pdb: NiStream::SetTexture | NiStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkTexture
void __stdcall FUN_00a633b0(const NiObject* pkObject)
{
    FUN_00a61c50((NiObject*)pkObject, 0);
}

namespace fnv_00a633f0 {
extern int EmptyFS;

struct FUN_00a633f0_shell
{
    char _pad[0x238];
    int m_aiIndexedValues;
    char _pad2[4];
    unsigned int m_uiItemCount;

    int FindIndex(int* pVal);
};

// @fnv 0x00a633f0
// pdb: NiStream::GetStringID | NiStream.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSFixedString::operator!)
// pdb params: kString
int FUN_00a633f0_shell::FindIndex(int* pVal)
{
    int v = *pVal;
    if (v == EmptyFS)
        return -1;

    int i = 0;
    if (m_uiItemCount > 0)
    {
        int* p = (int*)m_aiIndexedValues;
        while (i < m_uiItemCount)
        {
            if (v == *p)
                return i;
            ++p;
            ++i;
        }
    }
    return -1;
}
}  // namespace fnv_00a633f0

struct FUN_00a63460_shell : public NiStream
{
    unsigned int NiStream_GetNumberOfLinkIDs();
};

// @fnv 0x00a63460
// pdb: NiStream::GetNumberOfLinkIDs | NiStream.obj | fnv360_0822_retail, call_seq + bridge(hash|call_seq) + skyrim(call_seq), high
unsigned int FUN_00a63460_shell::NiStream_GetNumberOfLinkIDs()
{
    unsigned int idx = m_uiLinkBlockIndex++;
    return m_kLinkIDBlocks.m_pBase[idx];
}

struct ShaderBufferRecord;
template <class T> struct NiTStringPointerMap
{
    bool GetAt(const char*, T&);
};

struct FUN_00a63480_holder
{
    char pad[0x274];
    NiTStringPointerMap<ShaderBufferRecord*> map;
};

// @fnv 0x00a63480
// pdb: NiStream::GetLinkIDFromObject | NiStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
unsigned int __fastcall NiStream_GetLinkIDFromObject(FUN_00a63480_holder* self, int, const char* name)
{
    if (!name)
        return 0xffffffff;
    unsigned int id = 0xffffffff;
    self->map.GetAt(name, (ShaderBufferRecord*&)id);
    return id;
}

namespace fnv_00a634b0 {
struct ShaderBufferRecord;
struct NiTStringPointerMap
{
    bool GetAt(const char*, void(__cdecl*&)());
};
extern NiTStringPointerMap* DAT_011f4784;
// Looks up a function pointer in DAT_011f4784 by name and calls it, returning the result or 0 if not found.
// @fnv 0x00a634b0
// pdb: NiStream::CreateObjectByRTTI | NiStream.obj | fnv360_0822_retail, udata, medium, conflict (skyrim: )
// pdb params: pcRTTI
void* InvokeNamedFunction(const char* name)
{
    void*(__cdecl * fn)();
    if (!DAT_011f4784->GetAt(name, (void(__cdecl*&)())fn))
        return 0;
    return fn();
}
}  // namespace fnv_00a634b0

// Searches the array at pThis+0xcc for val and returns its index, or 0 if not found.
// @fnv 0x00a634f0
// pdb: NiPoint3::SaveBinary | BSDecalPVExtraData.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: NiColorA::SaveBinary)
// pdb params: stream, pkValues, uiNumValues
unsigned int __fastcall FUN_00a634f0(char* pThis, int, int aiValue)
{
    unsigned int count = *(unsigned short*)(pThis + 0xd2);
    for (unsigned int i = 0; i < count; ++i)
    {
        if (aiValue == ((int*)*(void**)(pThis + 0xcc))[i])
            return i;
    }
    return 0;
}

namespace fnv_00a63520 {
struct NiTMapBase
{
    bool RemoveAt(const char*);
};

extern void* DAT_011f4784;

// @fnv 0x00a63520
// pdb: Interface::AddToEnterStack | Interface.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiID, abForceRemoval
void __cdecl FUN_00a63520(const char* apKey)
{
    NiTMapBase* map = reinterpret_cast<NiTMapBase*>(DAT_011f4784);
    map->RemoveAt(apKey);
}
}  // namespace fnv_00a63520

namespace fnv_00a63540 {
template <class T> struct S_00a63540_Array
{
    void* vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    T RemoveAt(unsigned int uiIndex)
    {
        if (uiIndex >= m_usSize)
            return T(0);
        T element = m_pBase[uiIndex];
        m_pBase[uiIndex] = T(0);
        if (element != T(0))
            m_usESize--;
        if (uiIndex == (unsigned short)(m_usSize - 1))
            m_usSize--;
        return element;
    }
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};
typedef void (*S_00a63540_PostProcess)(void*);
extern S_00a63540_Array<S_00a63540_PostProcess>* DAT_011f4788;
// Removes the given post-process callback from the global post-process array by finding and removing the matching entry.
// @fnv 0x00a63540
// pdb: NiStream::UnregisterPostProcessFunction | NiStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pfnFunc
void RemovePostProcess(S_00a63540_PostProcess apPostProcess)
{
    for (unsigned int ui = 0; ui < DAT_011f4788->GetSize(); ui++)
    {
        if (DAT_011f4788->GetAt(ui) == apPostProcess)
        {
            DAT_011f4788->RemoveAt(ui);
            break;
        }
    }
}
}  // namespace fnv_00a63540

extern "C" int __cdecl strcpy_s(char* destination, unsigned int size, const char* source);
extern "C" char* __cdecl strtok_s(char* text, const char* delimiters, char** context);
extern long __cdecl FUN_00eca6d3(const char* text);

// Copies text into a 16-byte buffer, splits it on '.' with strtok_s, and packs each token's FUN_00eca6d3 value into a 32-bit integer.
// @fnv 0x00a63630
// pdb: NiStream::GetVersionFromString | NiStream.obj | fnv360_0822_retail, call_gap, medium
// pdb params: pcVersionString
unsigned int __cdecl FUN_00a63630(const char* text)
{
    char buffer[16];
    char* context;

    strcpy_s(buffer, 16, text);
    int shift = 24;
    unsigned int value = 0;
    char* token = strtok_s(buffer, ".", &context);
    while (token)
    {
        value |= (unsigned int)(FUN_00eca6d3(token) << shift);
        shift -= 8;
        token = strtok_s(0, ".", &context);
    }
    return value;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

namespace a637 {
extern char* DAT_0109b220;
}

class NiFixedStringA637
{
  public:
    NiFixedStringA637& operator=(const NiFixedStringA637& kString) throw()
    {
        if (m_kHandle != kString.m_kHandle)
        {
            char* kHandle = kString.m_kHandle;
            if (kHandle != a637::DAT_0109b220)
                InterlockedIncrement((long volatile*)(kHandle - 8));
            if (m_kHandle != a637::DAT_0109b220)
                InterlockedDecrement((long volatile*)(m_kHandle - 8));
            m_kHandle = kHandle;
        }
        return *this;
    }
    NiFixedStringA637(char* kHandle) throw() : m_kHandle(kHandle)
    {}
    ~NiFixedStringA637() throw()
    {
        if (m_kHandle != a637::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }
    bool operator==(const NiFixedStringA637& k) const throw()
    {
        return m_kHandle == k.m_kHandle;
    }
    bool operator!=(const NiFixedStringA637& k) const throw()
    {
        return m_kHandle != k.m_kHandle;
    }
    char* m_kHandle;
};

template <class T> class NiTLargeArrayA637
{
  public:
    virtual ~NiTLargeArrayA637();
    void FUN_00a63730(unsigned int uiIndex, const T& element) throw();

    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
};

// Stores element at uiIndex in m_pBase, growing m_uiSize if needed and adjusting m_uiESize when the slot's emptiness changes.
// @fnv 0x00a63730
// pdb: NiTLargeArray<NiFixedString,NiTNewInterface<NiFixedString> >::SetAt | NiStream.obj | fnv360_0822_retail, call_seq, high
// pdb params: uiIndex, element
template <class T> void NiTLargeArrayA637<T>::FUN_00a63730(unsigned int uiIndex, const T& element) throw()
{
    if (uiIndex >= m_uiSize)
    {
        m_uiSize = uiIndex + 1;
        if (element != T(a637::DAT_0109b220))
            m_uiESize++;
    }
    else
    {
        if (element != T(a637::DAT_0109b220))
        {
            if (m_pBase[uiIndex] == T(a637::DAT_0109b220))
                m_uiESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != T(a637::DAT_0109b220))
                m_uiESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

template class NiTLargeArrayA637<NiFixedStringA637>;

void NiFree(void* p);

struct S_00a63910_Item
{
    S_00a63910_Item* m_pkNext;
    char* m_key;
    void* m_val;
};

struct S_00a63910_MapBase
{
    unsigned int m_uiHashSize;
    S_00a63910_Item** m_ppkHashTable;
    unsigned int m_uiCount;

    virtual ~S_00a63910_MapBase() throw()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    void RemoveAll();
};

struct S_00a63910_Map : S_00a63910_MapBase
{
    virtual ~S_00a63910_Map() throw()
    {
        RemoveAll();
    }
};

struct FUN_00a63910 : S_00a63910_Map
{
    bool m_bCopy;

    virtual ~FUN_00a63910() throw();
};

// Frees the m_key strings of all hash table items when m_bCopy is set, then defers to the base class destructor.
// @fnv 0x00a63910
// pdb: NiTStringTemplateMap<NiTPointerMap<char const *,NiD3DPixelShader *>,NiD3DPixelShader *>::~NiTStringTemplateMap<NiTPointerMap<char const *,NiD3DPixelShader *>,NiD3DPixelShader *> | NiD3DShaderProgramFactory.obj | fnv360_0721_beta, objrun_open, low
FUN_00a63910::~FUN_00a63910() throw()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            S_00a63910_Item* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                S_00a63910_Item* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                NiFree(pkSave->m_key);
            }
        }
    }
}

#include <string.h>
struct S_00a63be0_File
{
    virtual ~S_00a63be0_File();
    virtual bool IsGood();
    static S_00a63be0_File* GetFile(const char* name, int mode, unsigned int bufSize);
};
void FUN_00aa2a00(char* path);
struct S_00a63be0_Stream
{
    virtual ~S_00a63be0_Stream();
    virtual bool LoadFile(S_00a63be0_File* f);
    int unk4;
    int unk8;
    int unkC;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    char m_acFileName[0x104];  // src: FNV360_PDB +0xE0 (old: m_acInputFilePath)
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    unsigned int m_uiLastError;  // src: FNV360_PDB +0x3B8 (old: m_uiNativeThreadId)
    char m_acLastErrorMessage[0x104];  // src: FNV360_PDB +0x3BC (old: m_acSecondPathBuffer)
    char m_acLastPath[0x104];
    bool OpenFile(const char* name);
};
// Copies name into m_acFileName, calls FUN_00aa2a00, attempts to get a file, and calls LoadFile if it is good.
// @fnv 0x00a63be0
// pdb: NiStream::Load | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: pcFileName
bool S_00a63be0_Stream::OpenFile(const char* apFilePath)
{
    strcpy_s(m_acFileName, 0x104, apFilePath);
    FUN_00aa2a00(m_acFileName);
    if (m_acFileName && m_acFileName[0])
    {
        strncpy_s(m_acLastPath, 0x104, m_acFileName, 0x103);
        FUN_00aa2a00(m_acLastPath);
    }
    else
    {
        m_acLastPath[0] = 0;
    }
    S_00a63be0_File* f = S_00a63be0_File::GetFile(m_acFileName, 0, 0x8000);
    if (f && f->IsGood())
    {
        bool b = LoadFile(f);
        delete f;
        return b;
    }
    delete f;
    m_uiLastError = 1;
    strcpy_s(m_acLastErrorMessage, 0x104, "Cannot open file.");
    return false;
}

struct Holder
{
    char _0[0xA0];
    void** m_pBase;
    unsigned short m_usExtra;
    unsigned short m_usElementCount;
};
struct Arg
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Holder* f3();
    char _4[0x2C];
    unsigned int m_flags;
};
struct ThisObj
{
    void SetFlagsRecursively(Arg* p);
};
// Clears bit 0x10, sets mask 0xE in m_flags, then recurses on each non-null element in the f3() holder.
// @fnv 0x00a63cb0
// pdb: NiStream::SetSelectiveUpdateFlagsTTTFRecursive | NiStream.obj | fnv360_0721_beta, caller, medium
// pdb params: pkAVObject
void ThisObj::SetFlagsRecursively(Arg* apArg)
{
    apArg->m_flags = (apArg->m_flags & ~0x10) | 0xE;
    Holder* h = apArg->f3();
    if (h)
    {
        for (unsigned int i = 0; i < h->m_usElementCount; ++i)
        {
            Arg* child = (Arg*)h->m_pBase[i];
            if (child)
                SetFlagsRecursively(child);
        }
    }
}

struct Link
{
    int unk00;
    Link* unk04;
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4280;
struct Item
{
    virtual void* First();
    virtual void* Second();
    virtual Link* Query();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct Receiver
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    Item** unk1f0;
    int unk1f4;
    unsigned int count;
    void SetFlagsRecursively(Item* item);
    void __thiscall FUN_00a63d10();
};
// Iterates the Item array and calls SetFlagsRecursively on items whose Query() chain reaches g_011f4280 and whose unk18 is zero.
// @fnv 0x00a63d10
// pdb: NiStream::SetSelectiveUpdateFlagsForOldVersions | NiStream.obj | fnv360_0822_retail, call_gap, medium
void __thiscall Receiver::FUN_00a63d10()
{
    if (unk0d8 >= 0x401000cU)
        return;
    unsigned int index = 0;
    if (count <= 0)
        return;
    do
    {
        Item* item = unk1f0[index];
        if (item)
        {
            Link* value = item->Query();
            if (value)
            {
                do
                {
                    if (value == (Link*)&g_011f4280)
                    {
                        if (item->unk18 == 0)
                            SetFlagsRecursively(item);
                        break;
                    }
                    value = value->unk04;
                } while (value);
            }
        }
        ++index;
    } while (index < count);
}

namespace sa63df0 {

class BinaryStream
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int GetPosition();

    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int (*m_pfnRead)(BinaryStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

template <class T> inline void BinaryStreamLoad(BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline void StreamLoadBinary(BinaryStream& kStream, T& kValue)
{
    BinaryStreamLoad(kStream, &kValue, 1);
}

struct Loader
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    unsigned int m_uiSkipCount;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    BinaryStream* m_pDataStream;

    int NiStream_PreSaveObjectSizeTable();
};

// Reads m_uiSkipCount binary values from m_pDataStream and returns the stream position captured before the reads.
// @fnv 0x00a63df0
// pdb: NiStream::PreSaveObjectSizeTable | NiStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int Loader::NiStream_PreSaveObjectSizeTable()
{
    int iPosition = m_pDataStream->GetPosition();
    int iSkipped = 0;
    for (unsigned int i = 0; i < m_uiSkipCount; i++)
        StreamLoadBinary(*m_pDataStream, iSkipped);
    return iPosition;
}

}

class NiBinaryStreamA63E
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStreamA63E* pThis, const void* pvBuffer,
                                                   unsigned int uiBytes, unsigned int* puiComponentSizes,
                                                   unsigned int uiNumComponents);

    virtual ~NiBinaryStreamA63E();
    virtual bool operator!();
    virtual void Seek(int iNumBytes);
    virtual unsigned int GetPosition() const;

    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NIBINARYSTREAM_WRITEFN m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

template <class T> inline void NiStreamSaveBinaryA63E(NiBinaryStreamA63E& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, uiSize, &uiSize);
}

class NiStreamA63E
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204;
    unsigned int* m_puiLinkIDs;
    unsigned int unk20C;
    unsigned int m_uiLinkCount;
    int unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C;
    NiBinaryStreamA63E* m_pkOstr;  // src: FNV360_PDB +0x250 (old: m_pBackingStream)

    bool NiStream_SaveObjectSizeTable(unsigned int uiStartPos);
};

// Seeks the backing stream back to uiStartPos and writes each link ID from m_puiLinkIDs to the stream.
// @fnv 0x00a63e60
// pdb: NiStream::SaveObjectSizeTable | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb params: uiStartOffset
// pdb: NiStream::SaveObjectSizeTable | NiStream.obj | fnv360_0822_retail, vtable, high (was: SaveLinkIDs)
bool NiStreamA63E::NiStream_SaveObjectSizeTable(unsigned int uiStartPos)
{
    unsigned int uiDelta = m_pkOstr->GetPosition() - uiStartPos;
    m_pkOstr->Seek(-(int)uiDelta);
    for (unsigned int i = 0; i < m_uiLinkCount; i++)
    {
        unsigned int uiLinkID = m_puiLinkIDs[i];
        NiStreamSaveBinaryA63E(*m_pkOstr, uiLinkID);
    }
    return true;
}

namespace fnv_00a63ee0 {
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
struct FUN_00a63ee0_shell : public NiStream
{
    void NiStream_SaveFixedStringTable();
};

extern char* _EmptyFS;

struct BinStream_a63ee0
{
    void* m_pVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(BinStream_a63ee0* pThis, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 1;
        return BinaryWrite(pvBuffer, uiBytes, &uiSize, 1);
    }
};

template <class T> inline void SaveBinary_a63ee0(BinStream_a63ee0& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

inline unsigned int GetSize_a63ee0(const char* self)
{
    return *(const unsigned int*)(self + 0x240);
}

// Writes the string array size, max length, and each string's length and data to the binary stream at offset 0x250.
// @fnv 0x00a63ee0
// pdb: NiStream::SaveFixedStringTable | NiStream.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_gap) + skyrim(call_seq), high
void FUN_00a63ee0_shell::NiStream_SaveFixedStringTable()
{
    char* self = (char*)this;
    SaveBinary_a63ee0(**(BinStream_a63ee0**)(self + 0x250), GetSize_a63ee0(self));

    unsigned int stMaxLength = 0;
    for (unsigned short us = 0; us < *(unsigned int*)(self + 0x240); us++)
    {
        char* kString = (*(char***)(self + 0x238))[us];
        if (kString != _EmptyFS)
        {
            unsigned int stLength = ((unsigned int*)kString)[-1];
            if (stLength > stMaxLength)
                stMaxLength = stLength;
        }
    }
    unsigned int uiMaxLength = stMaxLength;
    SaveBinary_a63ee0(**(BinStream_a63ee0**)(self + 0x250), uiMaxLength);

    for (unsigned short us = 0; us < *(unsigned int*)(self + 0x240); us++)
    {
        char*& kString = (*(char***)(self + 0x238))[us];
        unsigned int stLength = (kString == _EmptyFS) ? 0 : ((unsigned int*)kString)[-1];
        unsigned int uiLength = stLength;
        const char* pcString = kString;
        SaveBinary_a63ee0(**(BinStream_a63ee0**)(self + 0x250), uiLength);
        (*(BinStream_a63ee0**)(self + 0x250))->Write(pcString, uiLength);
    }
}
}  // namespace fnv_00a63ee0

namespace fnv_00a640b0 {
int strcpy_s(char* dest, unsigned int size, const char* src);
void _fnv_CopyFilePath(char* dest, unsigned int destSize, const char* src, unsigned int count);
void _fnv_StandardizeFilePath(char* path);

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY = 1
    };
    virtual ~NiFile();
    virtual operator bool();
    static NiFile* GetFile(const char* name, OpenMode mode, unsigned int bufferSize);
};

class NiStreamLoadStandIn
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool Load(NiFile* file);

    char pad004[0xdc];
    char m_acFileName[0x104];  // src: FNV360_PDB +0xE0 (old: m_acInputFilePath)
    char pad1e4[0x2dc];
    char m_acPath[0x104];

    bool NiStream_Save(const char* name);
};

// Copies and standardizes the input file path, opens it read-only via NiFile::GetFile, and delegates to Load if the file is valid.
// @fnv 0x00a640b0
// pdb: NiStream::Save | NiStream.obj | fnv360_0822_retail, objrun + bridge(vtable|caller_sim) + skyrim(vtable), high
bool NiStreamLoadStandIn::NiStream_Save(const char* name)
{
    strcpy_s(m_acFileName, 0x104, name);
    _fnv_StandardizeFilePath(m_acFileName);
    if (m_acFileName && m_acFileName[0])
    {
        _fnv_CopyFilePath(m_acPath, 0x104, m_acFileName, 0x103);
        _fnv_StandardizeFilePath(m_acPath);
    }
    else
    {
        m_acPath[0] = 0;
    }
    NiFile* file = NiFile::GetFile(m_acFileName, NiFile::READ_ONLY, 0x8000);
    if (file)
    {
        if (*file)
        {
            bool result = Load(file);
            delete file;
            return result;
        }
        delete file;
    }
    return false;
}
}  // namespace fnv_00a640b0

struct NiStreamW
{
    int unk00;
    unsigned int m_04;
    int unk08;
    void* m_0C;
};

typedef unsigned int(__cdecl* StreamWriteFn)(NiStreamW* s, const void* buf, unsigned int size, unsigned int* pCount,
                                             unsigned int flag);

struct FUN_00a64160_cls
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    NiStreamW* m_250;
    void NiStream_SaveCString(const char* str);
};

static __forceinline void S_Save(NiStreamW* o, const void* v, unsigned int n, unsigned int elem)
{
    unsigned int sz = elem;
    o->m_04 += ((StreamWriteFn)o->m_0C)(o, v, n, &sz, 1);
}

// Writes the length of str and, if non-zero, the string bytes to m_250 via S_Save.
// @fnv 0x00a64160
// pdb: NiStream::SaveCString | NiStream.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_00a64160_cls::NiStream_SaveCString(const char* apString)
{
    unsigned int len;
    if (apString != 0)
        len = (unsigned int)strlen(apString);
    else
        len = 0;
    S_Save(m_250, &len, 4, 4);
    if (len > 0)
        S_Save(m_250, apString, len, 1);
}

typedef unsigned int(__cdecl* StreamWriteFn)(NiStreamW* s, const void* buf, unsigned int size, unsigned int* pCount,
                                             unsigned int flag);

extern void* DAT_0109b220;
extern unsigned int DAT_0109bc30;

struct FUN_00a641f0_cls
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    NiStreamW* m_250;
    unsigned int GetObjectLinkId(void* p);
    void NiStream_SaveFixedString(void* a1);
};

// Writes four bytes: DAT_0109bc30 if the argument's first pointer matches DAT_0109b220, otherwise its object link ID.
// @fnv 0x00a641f0
// pdb: NiStream::SaveFixedString | NiStream.obj | fnv360_0822_retail, call_seq, high
// pdb params: kString
// pdb: NiStream::SaveFixedString | NiStream.obj | fnv360_0822_retail, call_seq, high (was: WriteObjectLink)
void FUN_00a641f0_cls::NiStream_SaveFixedString(void* apObject)
{
    unsigned int id;
    if (*(void**)apObject == DAT_0109b220)
    {
        NiStreamW* s = m_250;
        StreamWriteFn fn = (StreamWriteFn)s->m_0C;
        *(unsigned int*)&apObject = 4;
        s->m_04 += fn(s, &DAT_0109bc30, 4, (unsigned int*)&apObject, 1);
    }
    else
    {
        id = GetObjectLinkId(apObject);
        NiStreamW* s = m_250;
        StreamWriteFn fn = (StreamWriteFn)s->m_0C;
        *(unsigned int*)&apObject = 4;
        s->m_04 += fn(s, &id, 4, (unsigned int*)&apObject, 1);
    }
}

struct NiStreamLoader
{
    unsigned int unk00;
    unsigned int m_uiPos;
    typedef unsigned int(__cdecl* ReadProcRef)(NiStreamLoader*, unsigned char*, unsigned int, const unsigned int&,
                                               unsigned int);
    ReadProcRef m_pfnRead;
};
struct U32Array
{
    unsigned int* m_pData;
    unsigned int m_uiCapacity;
    unsigned int m_uiCount;
    void Reserve(unsigned int newCapacity);
};
class FUN_00a645b0_cls
{
  public:
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    NiStreamLoader* m_pStreamLoader;
    unsigned int unk0250;
    U32Array m_ppData;
    void NiStream_ReadLinkID();
};

// Reads a 4-byte value from m_pStreamLoader, grows m_ppData if full, and appends the value to m_ppData.
// @fnv 0x00a645b0
// pdb: NiStream::ReadLinkID | NiStream.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_00a645b0_cls::NiStream_ReadLinkID()
{
    unsigned int value;
    NiStreamLoader* loader = m_pStreamLoader;
    loader->m_uiPos += ((NiStreamLoader::ReadProcRef)(loader->m_pfnRead))(loader, (unsigned char*)&value, 4u, 4u, 1u);
    unsigned int uiCapacity = m_ppData.m_uiCapacity;
    U32Array* arr = &m_ppData;
    if (arr->m_uiCount == uiCapacity)
    {
        arr->Reserve(uiCapacity > 0 ? uiCapacity * 2 : 1);
    }
    arr->m_pData[arr->m_uiCount] = value;
    arr->m_uiCount++;
}

struct S_00a64670_Ctx;

typedef int(__cdecl* S_00a64670_Callback)(S_00a64670_Ctx*, int*, int, int*, int);

struct S_00a64670_Ctx
{
    int unk00;
    int unk04;
    S_00a64670_Callback unk08;
};

struct S_00a64670_Array
{
    unsigned int* data;
    unsigned int capacity;
    unsigned int count;

    void FUN_00a311e0(unsigned int);
};

struct S_00a64670_B0
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
};

struct S_00a64670_B1
{
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
};

struct S_00a64670_B2
{
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
};

struct S_00a64670_B3
{
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
};

struct S_00a64670_B4
{
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
};

struct S_00a64670_B5
{
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
};

struct S_00a64670_B6
{
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
};

struct S_00a64670_B7
{
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
};

struct S_00a64670_B8
{
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
};

struct S_00a64670_Base : S_00a64670_B0,
                         S_00a64670_B1,
                         S_00a64670_B2,
                         S_00a64670_B3,
                         S_00a64670_B4,
                         S_00a64670_B5,
                         S_00a64670_B6,
                         S_00a64670_B7,
                         S_00a64670_B8
{
    int unk240;
    int unk244;
    int unk248;
};

struct S_00a64670_Foo : S_00a64670_Base
{
    S_00a64670_Ctx* unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    S_00a64670_Array unk264;

    void NiStream_ReadLinkID();
    void NiStream_ReadMultipleLinkIDs();
};

inline void ReadStreamCount(S_00a64670_Ctx* ctx, int* output, int size)
{
    ctx->unk04 += ctx->unk08(ctx, output, size, &size, 1);
}
// Reads a count, appends it to the array, then calls NiStream_ReadLinkID once per count.
// @fnv 0x00a64670
// pdb: NiStream::ReadMultipleLinkIDs | NiStream.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void S_00a64670_Foo::NiStream_ReadMultipleLinkIDs()
{
    unsigned int count;
    S_00a64670_Ctx* ctx = unk24c;
    ReadStreamCount(ctx, (int*)&count, 4);
    S_00a64670_Array& array = unk264;
    if (array.count == array.capacity)
        array.FUN_00a311e0(array.capacity > 0 ? array.capacity * 2 : 1);
    array.data[array.count] = count;
    ++array.count;
    unsigned int limit = *(volatile unsigned int*)&count;
    unsigned int i = 0;
    if (limit > 0)
        do
        {
            NiStream_ReadLinkID();
            limit = *(volatile unsigned int*)&count;
            ++i;
        } while (i < limit);
}

struct BinaryInput
{
    unsigned int flags, position;
    unsigned int(__cdecl* read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* buffer, unsigned int amount)
    {
        unsigned int size = amount;
        unsigned int result = read(this, buffer, amount, &size, 1);
        position += result;
        return result;
    }
};
struct LinkArray
{
    unsigned int flags;
    unsigned int* data;
    unsigned int capacity;
    unsigned int size;
    unsigned int count;
    void FUN_00864280(unsigned int);
    void SetAt(unsigned int index, const unsigned int& value)
    {
        if (index >= size)
        {
            size = index + 1;
            if (value)
                ++count;
        }
        else if (value)
        {
            if (!data[index])
                ++count;
        }
        else if (data[index])
            --count;
        data[index] = value;
    }
};
struct LinkLoader
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int linkCount;
    unsigned int unk1fc;
    unsigned int unk200;
    LinkArray links;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    BinaryInput* input;
    bool NiStream_LoadObjectSizeTable();
};
// Reads linkCount 4-byte values from input into the links array and returns true.
// @fnv 0x00a64740
// pdb: NiStream::LoadObjectSizeTable | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb: NiStream::LoadObjectSizeTable | NiStream.obj | fnv360_0822_retail, vtable, high (was: ReadLinks)
bool LinkLoader::NiStream_LoadObjectSizeTable()
{
    links.FUN_00864280(linkCount);
    for (unsigned int index = 0; index < linkCount; ++index)
    {
        unsigned int value = 0;
        input->Read(&value, 4);
        links.SetAt(index, value);
    }
    return true;
}

namespace fnv_00a647f0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiObjectGroup : public NiMemObject
{
    void* Allocate(unsigned int);
    void DecRefCount();
    void SetSize(unsigned int);
    unsigned int GetSize();
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    void* pvContextData;
    void* m_pBeforeRefCount;
    unsigned int m_uiRefCount;
};
typedef char _sizecheck_NiObjectGroup[sizeof(NiObjectGroup) == 16 ? 1 : -1];
struct FUN_00a647f0_shell : public NiStream
{
    void LoadGroups();
};

struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct NiTPrimitiveArray_int___
{
    void SetAt(unsigned int, int&);
};
struct QGroupCtor
{
    NiObjectGroup* FUN_00a8a620(unsigned int);
};
struct QBinStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(QBinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline unsigned int QLoadB(QBinStream& binstream, T& value)
{
    unsigned int uiComponentSize = sizeof(T);
    return binstream.BinaryRead(&value, sizeof(T), &uiComponentSize, 1);
}
struct QGroupArray
{
    void* vtbl;
    NiObjectGroup** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int uiIndex, NiObjectGroup* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else
        {
            if (element)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
};
// Reads the group count from the stream, resizes the group array, and allocates NiObjectGroup instances for each group.
// @fnv 0x00a647f0
// pdb: NiStream::LoadObjectGroups | NiStream.obj | fnv360_0822_retail, caller, medium
void FUN_00a647f0_shell::LoadGroups()
{
    unsigned int uiNumGroups;
    QLoadB(*(QBinStream*)m_pkIstr, uiNumGroups);
    uiNumGroups++;
    ((NiTPrimitiveArray_ImageSpaceTexture___*)&m_kGroups)->SetSize(uiNumGroups);
    {
        int iNull = 0;
        ((NiTPrimitiveArray_int___*)&m_kGroups)->SetAt(0, iNull);
    }
    for (unsigned int uiRenderPassIndex = 1; uiRenderPassIndex < uiNumGroups; uiRenderPassIndex++)
    {
        unsigned int uiSize;
        QLoadB(*(QBinStream*)m_pkIstr, uiSize);
        void* pvMem = BSFadeNode::operator new(sizeof(NiObjectGroup));
        NiObjectGroup* pkGroup = pvMem ? ((QGroupCtor*)pvMem)->FUN_00a8a620(uiSize) : 0;
        ((QGroupArray*)&m_kGroups)->SetAt(uiRenderPassIndex, pkGroup);
    }
}
}  // namespace fnv_00a647f0

extern "C" unsigned int __cdecl strlen(const char* pcStr);

struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
    void NiBinaryStream_PutS(const char* pcLine);
};

extern unsigned int g_uiNifMaxVersion_011a9b0c;
extern unsigned int g_uiNifMaxUserVersion_011a9b10;

struct NiStreamImpl
{
    void* m_vtbl;
    unsigned int m_uiBSVersion;
    char m_acCreator[0x40];
    char m_acExportInfo1[0x40];
    char m_acExportInfo2[0x40];
    char pad0c8[0x1e4 - 0xc8];
    bool m_bLittleEndian;
    char pad1e5[0x1f8 - 0x1e5];
    unsigned int m_uiNumObjects;
    char pad1fc[0x250 - 0x1fc];
    NiBinaryStreamStandIn* m_pkOstr;  // src: FNV360_PDB +0x250 (old: m_pBackingStream)

    void NiStream_SaveHeader();
};

// Writes the NIF header (version, endianness, object count, and optional creator/export info) to the backing stream.
// @fnv 0x00a64940
// pdb: NiStream::SaveHeader | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb: NiStream::SaveHeader | NiStream.obj | fnv360_0822_retail, vtable, high (was: WriteHeader)
void NiStreamImpl::NiStream_SaveHeader()
{
    m_pkOstr->SetEndianSwap(false);
    m_pkOstr->NiBinaryStream_PutS("Gamebryo File Format, Version 20.2.0.7\n");
    m_pkOstr->Write(&g_uiNifMaxVersion_011a9b0c);
    m_pkOstr->Write(&m_bLittleEndian);
    m_pkOstr->Write(&g_uiNifMaxUserVersion_011a9b10);
    {
        unsigned int uiObjects = m_uiNumObjects;
        m_pkOstr->Write(&uiObjects);
    }
    if (g_uiNifMaxUserVersion_011a9b10)
    {
        m_pkOstr->Write(&m_uiBSVersion);
        unsigned char ucLength = (unsigned char)(strlen(m_acCreator) + 1);
        m_pkOstr->Write(&ucLength);
        m_pkOstr->Write(m_acCreator, ucLength);
        ucLength = (unsigned char)(strlen(m_acExportInfo1) + 1);
        m_pkOstr->Write(&ucLength);
        m_pkOstr->Write(m_acExportInfo1, ucLength);
        ucLength = (unsigned char)(strlen(m_acExportInfo2) + 1);
        m_pkOstr->Write(&ucLength);
        m_pkOstr->Write(m_acExportInfo2, ucLength);
    }
    m_pkOstr->SetEndianSwap(m_bLittleEndian ^ true);
}

namespace fnv_00a64b80 {
class ImageSpaceTexture
{
  public:
    unsigned int m_uiValueBeforeCount;
};

template <class T> class NiTMallocInterface
{
};

template <class T, class TAlloc> class NiTArray
{
  public:
    virtual ~NiTArray();

    void SetSize(unsigned int uiMaxSize);
    __declspec(noinline) void SetAt(unsigned int pos, const T& value);

    unsigned int GetSize() const
    {
        return m_usSize;
    }

    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Find(const T& element) const
    {
        for (unsigned int i = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] == element)
                return i;
        }
        return 0;
    }

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T, class TAlloc> __declspec(noinline) void NiTArray<T, TAlloc>::SetAt(unsigned int pos, const T& value)
{
    if (pos >= m_usSize)
    {
        m_usSize = (unsigned short)(pos + 1);
        if (value)
            ++m_usESize;
    }
    else if (value)
    {
        if (!m_pBase[pos])
            ++m_usESize;
    }
    else
    {
        if (m_pBase[pos])
            --m_usESize;
    }
    m_pBase[pos] = value;
}

class ImageSpaceShaderParam
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18();
    virtual void Vf1c();
    virtual void Vf20();
    virtual void Vf24();
    virtual void Vf28();
    virtual void Vf2c();
    virtual void Vf30();
    virtual void Vf34();
    virtual void Vf38();
    virtual void Vf3c();
    virtual void Vf40();
    virtual void Vf44();
    virtual void Vf48();
    virtual void Vf4c();
    virtual void Vf50();
    virtual void Vf54();
    virtual void Vf58();
    virtual void Vf5c();
    virtual void Vf60();
    virtual void Vf64();
    virtual void Vf68();
    virtual void Vf6c();
    virtual void Vf70();
    virtual void Vf74();
    virtual void Vf78();
    virtual unsigned int GetCount();
    virtual ImageSpaceTexture* GetTexture();
};

class ImageSpaceShaderW
{
  public:
    void NiStream_UpdateObjectGroups();
    unsigned int FindTexture(ImageSpaceTexture* pkTexture) const
    {
        for (unsigned int k = 0; k < m_kTextureSwapList.m_usSize; k++)
        {
            if (pkTexture == m_kTextureSwapList.m_pBase[k])
                return k;
        }
        return 0;
    }

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > m_kTextureSwapList;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    ImageSpaceShaderParam** m_ppParams;
    unsigned int m_uiParamMax;
    unsigned int m_uiParamCount;
};

// Rebuilds m_kTextureSwapList from shader params and accumulates GetCount into each texture's m_uiValueBeforeCount.
// @fnv 0x00a64b80
// pdb: NiStream::UpdateObjectGroups | NiStream.obj | fnv360_0822_retail, call_seq, high
// pdb: NiStream::UpdateObjectGroups | NiStream.obj | fnv360_0822_retail, call_seq, high (was: UpdateTextureSwapList)
void ImageSpaceShaderW::NiStream_UpdateObjectGroups()
{
    m_kTextureSwapList.SetSize(1);
    m_kTextureSwapList.SetAt(0, 0);

    for (unsigned int i = 0; i < m_uiParamCount; i++)
    {
        ImageSpaceShaderParam* pkParam = m_ppParams[i];
        if (pkParam)
        {
            ImageSpaceTexture* pkTexture = pkParam->GetTexture();
            if (pkTexture)
            {
                if (FindTexture(pkTexture) != 0)
                    continue;
                m_kTextureSwapList.Add(pkTexture);
                pkTexture->m_uiValueBeforeCount = 0;
            }
        }
    }

    for (unsigned int j = 0; j < m_uiParamCount; j++)
    {
        ImageSpaceShaderParam* pkParam = m_ppParams[j];
        if (pkParam)
        {
            ImageSpaceTexture* pkTexture = pkParam->GetTexture();
            if (pkTexture)
            {
                unsigned int uiElapsedMilliseconds = pkTexture->m_uiValueBeforeCount;
                pkTexture->m_uiValueBeforeCount = uiElapsedMilliseconds + pkParam->GetCount();
            }
        }
    }
}
}  // namespace fnv_00a64b80

extern int _fnv_NiStreamCriticalSection;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct StreamHack : NiStream
{
    void Clear();
};
// Locks the critical section, removes all top objects, zeroes four fields, and unlocks the section.
// @fnv 0x00a64ca0
// pdb: NiStream::FreeLoadData | NiStream.obj | fnv360_0822_retail, call_seq, high
void StreamHack::Clear()
{
    EnterCriticalSection(&_fnv_NiStreamCriticalSection);
    ((NiStreamTopObjects*)&m_kObjects)->RemoveAll();
    m_kLinkIDs.m_uiUsed = 0;
    m_kLinkIDBlocks.m_uiUsed = 0;
    m_uiLinkIndex = 0;
    m_uiLinkBlockIndex = 0;
    LeaveCriticalSection(&_fnv_NiStreamCriticalSection);
}

struct FUN_00a64ce0_shell : public NiStream
{
    void NiStream_LoadCString(char**);
};

void* __cdecl _NiMalloc(size_t);

struct LocalBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(LocalBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    void Read(void* pvBuffer, unsigned int uiBytes, unsigned int uiComponentSize)
    {
        unsigned int uiSize = uiComponentSize;
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, &uiSize, 1);
        m_uiStreamFlags += uiBytesRead;
    }
};

// Reads a length-prefixed null-terminated string from the stream into pcString, allocating memory when the length is positive.
// @fnv 0x00a64ce0
// pdb: NiStream::LoadCString | NiStream.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_00a64ce0_shell::NiStream_LoadCString(char** ppString)
{
    int iStringLength;
    ((LocalBinaryStream*)m_pkIstr)->Read(&iStringLength, 4, 4);
    if (iStringLength > 0)
    {
        *ppString = (char*)_NiMalloc(iStringLength + 1);
        ((LocalBinaryStream*)m_pkIstr)->Read(*ppString, iStringLength, 1);
        (*ppString)[iStringLength] = 0;
    }
    else
    {
        *ppString = 0;
    }
}

// ---------------------------------------------------------------------------
// NiStream_LoadRTTIString - read a length-prefixed block out of a NiStream.
//
// The function is a member of the game's stream object; the low level buffer
// it works on sits at +0x24c.  The buffer keeps its read cursor at +0x04 and
// the low level read routine at +0x08.  The read routine takes
// (buffer, destination, byte count, &size, flags); "size" selects the kind of
// value that is read (4 = a four byte value, 1 = a raw block) and is handed
// back to the caller.
//
// The two reads are made through the same buffer pointer, which is reloaded
// from the stream object before the second read.
// ---------------------------------------------------------------------------

class FnvStreamBuffer;
typedef unsigned int(__cdecl* FnvReadFn)(FnvStreamBuffer* self, void* destination, unsigned int bytes,
                                         const unsigned int* size, unsigned int flags);

// The low level buffer the stream hands out at +0x24c.
class FnvStreamBuffer
{
  public:
    unsigned int unk00;         // +0x00
    unsigned int m_uiPosition;  // +0x04  read cursor
    FnvReadFn m_pfnRead;        // +0x08
};

// The game's stream object.
class FnvNiStream
{
  public:
    void* vtbl;                        // +0x000
    unsigned int unk004;               // +0x004
    unsigned int unk008;               // +0x008
    unsigned int unk00C;               // +0x00C
    unsigned int unk010;               // +0x010
    unsigned int unk014;               // +0x014
    unsigned int unk018;               // +0x018
    unsigned int unk01C;               // +0x01C
    unsigned int unk020;               // +0x020
    unsigned int unk024;               // +0x024
    unsigned int unk028;               // +0x028
    unsigned int unk02C;               // +0x02C
    unsigned int unk030;               // +0x030
    unsigned int unk034;               // +0x034
    unsigned int unk038;               // +0x038
    unsigned int unk03C;               // +0x03C
    unsigned int unk040;               // +0x040
    unsigned int unk044;               // +0x044
    unsigned int unk048;               // +0x048
    unsigned int unk04C;               // +0x04C
    unsigned int unk050;               // +0x050
    unsigned int unk054;               // +0x054
    unsigned int unk058;               // +0x058
    unsigned int unk05C;               // +0x05C
    unsigned int unk060;               // +0x060
    unsigned int unk064;               // +0x064
    unsigned int unk068;               // +0x068
    unsigned int unk06C;               // +0x06C
    unsigned int unk070;               // +0x070
    unsigned int unk074;               // +0x074
    unsigned int unk078;               // +0x078
    unsigned int unk07C;               // +0x07C
    unsigned int unk080;               // +0x080
    unsigned int unk084;               // +0x084
    unsigned int unk088;               // +0x088
    unsigned int unk08C;               // +0x08C
    unsigned int unk090;               // +0x090
    unsigned int unk094;               // +0x094
    unsigned int unk098;               // +0x098
    unsigned int unk09C;               // +0x09C
    unsigned int unk0A0;               // +0x0A0
    unsigned int unk0A4;               // +0x0A4
    unsigned int unk0A8;               // +0x0A8
    unsigned int unk0AC;               // +0x0AC
    unsigned int unk0B0;               // +0x0B0
    unsigned int unk0B4;               // +0x0B4
    unsigned int unk0B8;               // +0x0B8
    unsigned int unk0BC;               // +0x0BC
    unsigned int unk0C0;               // +0x0C0
    unsigned int unk0C4;               // +0x0C4
    unsigned int unk0C8;               // +0x0C8
    unsigned int unk0CC;               // +0x0CC
    unsigned int unk0D0;               // +0x0D0
    unsigned int unk0D4;               // +0x0D4
    unsigned int unk0D8;               // +0x0D8
    unsigned int unk0DC;               // +0x0DC
    unsigned int unk0E0;               // +0x0E0
    unsigned int unk0E4;               // +0x0E4
    unsigned int unk0E8;               // +0x0E8
    unsigned int unk0EC;               // +0x0EC
    unsigned int unk0F0;               // +0x0F0
    unsigned int unk0F4;               // +0x0F4
    unsigned int unk0F8;               // +0x0F8
    unsigned int unk0FC;               // +0x0FC
    unsigned int unk100;               // +0x100
    unsigned int unk104;               // +0x104
    unsigned int unk108;               // +0x108
    unsigned int unk10C;               // +0x10C
    unsigned int unk110;               // +0x110
    unsigned int unk114;               // +0x114
    unsigned int unk118;               // +0x118
    unsigned int unk11C;               // +0x11C
    unsigned int unk120;               // +0x120
    unsigned int unk124;               // +0x124
    unsigned int unk128;               // +0x128
    unsigned int unk12C;               // +0x12C
    unsigned int unk130;               // +0x130
    unsigned int unk134;               // +0x134
    unsigned int unk138;               // +0x138
    unsigned int unk13C;               // +0x13C
    unsigned int unk140;               // +0x140
    unsigned int unk144;               // +0x144
    unsigned int unk148;               // +0x148
    unsigned int unk14C;               // +0x14C
    unsigned int unk150;               // +0x150
    unsigned int unk154;               // +0x154
    unsigned int unk158;               // +0x158
    unsigned int unk15C;               // +0x15C
    unsigned int unk160;               // +0x160
    unsigned int unk164;               // +0x164
    unsigned int unk168;               // +0x168
    unsigned int unk16C;               // +0x16C
    unsigned int unk170;               // +0x170
    unsigned int unk174;               // +0x174
    unsigned int unk178;               // +0x178
    unsigned int unk17C;               // +0x17C
    unsigned int unk180;               // +0x180
    unsigned int unk184;               // +0x184
    unsigned int unk188;               // +0x188
    unsigned int unk18C;               // +0x18C
    unsigned int unk190;               // +0x190
    unsigned int unk194;               // +0x194
    unsigned int unk198;               // +0x198
    unsigned int unk19C;               // +0x19C
    unsigned int unk1A0;               // +0x1A0
    unsigned int unk1A4;               // +0x1A4
    unsigned int unk1A8;               // +0x1A8
    unsigned int unk1AC;               // +0x1AC
    unsigned int unk1B0;               // +0x1B0
    unsigned int unk1B4;               // +0x1B4
    unsigned int unk1B8;               // +0x1B8
    unsigned int unk1BC;               // +0x1BC
    unsigned int unk1C0;               // +0x1C0
    unsigned int unk1C4;               // +0x1C4
    unsigned int unk1C8;               // +0x1C8
    unsigned int unk1CC;               // +0x1CC
    unsigned int unk1D0;               // +0x1D0
    unsigned int unk1D4;               // +0x1D4
    unsigned int unk1D8;               // +0x1D8
    unsigned int unk1DC;               // +0x1DC
    unsigned int unk1E0;               // +0x1E0
    unsigned int unk1E4;               // +0x1E4
    unsigned int unk1E8;               // +0x1E8
    unsigned int unk1EC;               // +0x1EC
    unsigned int unk1F0;               // +0x1F0
    unsigned int unk1F4;               // +0x1F4
    unsigned int unk1F8;               // +0x1F8
    unsigned int unk1FC;               // +0x1FC
    unsigned int unk200;               // +0x200
    unsigned int unk204;               // +0x204
    unsigned int unk208;               // +0x208
    unsigned int unk20C;               // +0x20C
    unsigned int unk210;               // +0x210
    unsigned int unk214;               // +0x214
    unsigned int unk218;               // +0x218
    unsigned int unk21C;               // +0x21C
    unsigned int unk220;               // +0x220
    unsigned int unk224;               // +0x224
    unsigned int unk228;               // +0x228
    unsigned int unk22C;               // +0x22C
    unsigned int unk230;               // +0x230
    unsigned int unk234;               // +0x234
    unsigned int unk238;               // +0x238
    unsigned int unk23C;               // +0x23C
    unsigned int unk240;               // +0x240
    unsigned int unk244;               // +0x244
    unsigned int unk248;               // +0x248
    FnvStreamBuffer* m_pBinaryStream;  // +0x24c
    void NiStream_LoadRTTIString(unsigned int param);
};

// @fnv 0x00a64d80
// pdb: NiStream::LoadRTTIString | NiStream.obj | fnv360_0822_retail, call_gap + bridge(hash|call_gap) + skyrim(call_seq), high
void FnvNiStream::NiStream_LoadRTTIString(unsigned int param)
{
    unsigned int count;
    FnvStreamBuffer* s = m_pBinaryStream;
    {
        // the kind of the value that is read; it dies right after the read
        unsigned int size = 4;
        s->m_uiPosition += s->m_pfnRead(s, &count, 4, &size, 1);
    }
    s = m_pBinaryStream;
    {
        // the raw block that follows the length
        unsigned int size = 1;
        s->m_uiPosition += s->m_pfnRead(s, reinterpret_cast<void*>(param), count, &size, 1);
    }
    reinterpret_cast<unsigned char*>(count)[param] = 0;
}

typedef char*(__cdecl* StrMakeFn)(char* p);
class StreamIO;
typedef int(__cdecl* StreamReadFn)(StreamIO* self, void* dst, unsigned int size, unsigned int* count, int flag);

class StreamIO
{
  public:
    unsigned int unk00;
    unsigned int m_bytes;
    StreamReadFn m_read;
};

static __forceinline unsigned int BinaryRead(StreamIO* s, void* pvBuffer, unsigned int uiTotalBytes,
                                             unsigned int* puiComponentSizes, unsigned int uiNumComponents = 1)
{
    unsigned int res = s->m_read(s, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    s->m_bytes += res;
    return res;
}

static __forceinline void ReadStream(StreamIO* s, unsigned int& val)
{
    unsigned int comp = sizeof(unsigned int);
    BinaryRead(s, &val, sizeof(unsigned int), &comp, 1);
}

static __forceinline void ReadStream(StreamIO* s, char* buf, unsigned int bytes)
{
    unsigned int comp = 1;
    BinaryRead(s, buf, bytes, &comp, 1);
}

char* __cdecl FUN_00a5b690(char* p);
char* __cdecl FUN_00aa1070(unsigned int size);
void __cdecl FUN_00aa10f0(char* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

class Cls_a64ea0
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    unsigned int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    unsigned int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    unsigned int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    unsigned int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    unsigned int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    unsigned int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    unsigned int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    unsigned int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    unsigned int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    unsigned int unk240, unk244, unk248;
    StreamIO* m_stream;
    void NiStream_LoadCStringAsFixedString(char** target);
};

// Reads a length-prefixed string into *target, using allocated storage for lengths >= 0x400 and a stack buffer for positive smaller lengths.
// @fnv 0x00a64ea0
// pdb: NiStream::LoadCStringAsFixedString | NiStream.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(call_gap), high
void Cls_a64ea0::NiStream_LoadCStringAsFixedString(char** apString)
{
    unsigned int len;
    char buf[0x400];
    ReadStream(m_stream, len);
    if ((int)len >= 0x400)
    {
        char* tmp = FUN_00aa1070(len + 1);
        ReadStream(m_stream, tmp, len);
        tmp[len] = 0;
        char* old = *apString;
        if (old != tmp)
        {
            *apString = FUN_00a5b690(tmp);
            if (old != DAT_0109b220)
                InterlockedDecrement((long volatile*)(old - 8));
        }
        FUN_00aa10f0(tmp);
    }
    else if ((int)len > 0)
    {
        ReadStream(m_stream, buf, len);
        buf[len] = 0;
        char* old = *apString;
        if (old != buf)
        {
            *apString = FUN_00a5b690(buf);
            if (old != DAT_0109b220)
                InterlockedDecrement((long volatile*)(old - 8));
        }
    }
    else
    {
        char* old = *apString;
        if (old != 0)
        {
            *apString = FUN_00a5b690(0);
            if (old != DAT_0109b220)
                InterlockedDecrement((long volatile*)(old - 8));
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

void* __cdecl FUN_00c1d790(unsigned int);
void __cdecl ReleaseObjectArray(void*);

struct S_00a64fe0_RefObject
{
    virtual ~S_00a64fe0_RefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct S_00a64fe0_Ptr
{
    S_00a64fe0_RefObject* m_pObject;

    S_00a64fe0_Ptr(S_00a64fe0_RefObject* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~S_00a64fe0_Ptr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    bool operator!=(S_00a64fe0_RefObject* pObject) const
    {
        return m_pObject != pObject;
    }
    bool operator!=(const S_00a64fe0_Ptr& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }

    S_00a64fe0_Ptr& operator=(S_00a64fe0_RefObject* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    S_00a64fe0_Ptr& operator=(const S_00a64fe0_Ptr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct S_00a64fe0_LargeArray
{
    virtual ~S_00a64fe0_LargeArray();
    S_00a64fe0_Ptr* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiESize;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;

    void FUN_00a64fe0(unsigned int uiMaxSize);
};

// Resizes the large array to uiMaxSize, copying existing elements, zeroing new slots, and freeing the old buffer.
// @fnv 0x00a64fe0
// pdb: NiTLargeArray<NiPointer<NiObject>,NiTNewInterface<NiPointer<NiObject> > >::SetSize | BSStream.obj | fnv360_0822_retail, call_seq, high
// pdb params: uiMaxSize
void S_00a64fe0_LargeArray::FUN_00a64fe0(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_uiMaxSize)
    {
        return;
    }

    unsigned int i;
    if (uiMaxSize < m_uiESize)
    {
        for (i = uiMaxSize; i < m_uiESize; i++)
        {
            if (m_pBase[i] != S_00a64fe0_Ptr(0))
            {
                m_pBase[i] = 0;
                m_uiSize--;
            }
        }
        m_uiESize = uiMaxSize;
    }

    S_00a64fe0_Ptr* pSaveBase = m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (m_uiMaxSize > 0)
    {
        m_pBase = (S_00a64fe0_Ptr*)FUN_00c1d790(m_uiMaxSize);
        for (i = 0; i < m_uiESize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }
        for (i = m_uiESize; i < m_uiMaxSize; i++)
        {
            m_pBase[i] = 0;
        }
    }
    else
    {
        m_pBase = 0;
    }
    ReleaseObjectArray(pSaveBase);
}

extern int DAT_0109bdcc, DAT_0109bd54, DAT_0109bc64, DAT_0109bd4c, DAT_0109bd98, DAT_01081fc8, DAT_0109bc3c;
void __cdecl ReleaseObjectArray(void*);
void _NiFreeAlias(void*);
void FUN_00a644a0(void*);
struct VObj
{
    virtual void* Del(int);
};
struct Map
{
    void RemoveAll();
    void* vt;
    char pad[4];
    void* a;
};
struct FUN_00a65300_holder
{
    void* vt;
    char p0[0xc4];
    void* vt_c8;
    void* c_cc;
    char p1[0x11c];
    void* vt_1ec;
    void* a1f0;
    char p2[0x10];
    void* vt_204;
    void* a208;
    char p3[0x10];
    void* vt_21c;
    void* a220;
    char p4[0x10];
    void* vt_234;
    void* a238;
    char p5[0x10];
    VObj* istr;
    VObj* ostr;
    void* l254;
    char p6[0x0c];
    void* l264;
    char p7[0x0c];
    Map map;
    char p8[0x24];
    VObj* bg;
    void ClearTopLevelObjects();
};
// Calls Del(1) on three members, clears top-level objects and the map, and passes stored pointers to cleanup routines.
// @fnv 0x00a65300
// pdb: NiStream::~NiStream | NiStream.obj | fnv360_0822_retail, caller, high
void __fastcall FUN_00a65300(FUN_00a65300_holder* s)
{
    s->vt = &DAT_0109bdcc;
    if (s->istr)
        s->istr->Del(1);
    if (s->ostr)
        s->ostr->Del(1);
    s->ClearTopLevelObjects();
    if (s->bg)
        s->bg->Del(1);
    Map* m = &s->map;
    m->vt = &DAT_0109bd54;
    m->RemoveAll();
    m->vt = &DAT_0109bc64;
    m->RemoveAll();
    _NiFreeAlias(m->a);
    _NiFreeAlias(s->l264);
    _NiFreeAlias(s->l254);
    s->vt_234 = &DAT_0109bd4c;
    FUN_00a644a0(s->a238);
    s->vt_21c = &DAT_0109bd98;
    ReleaseObjectArray(s->a220);
    s->vt_204 = &DAT_01081fc8;
    _NiFreeAlias(s->a208);
    s->vt_1ec = &DAT_0109bd98;
    ReleaseObjectArray(s->a1f0);
    s->vt_c8 = &DAT_0109bc3c;
    _NiFreeAlias(s->c_cc);
}

namespace fnv_00a65400 {
extern "C" char* __cdecl strstr(const char* pStr, const char* pSub);
extern "C" int __cdecl strcpy_s(char* pDest, unsigned int uiSize, const char* pSrc);
int __cdecl FUN_00404d80(char* pDest, unsigned int uiSize, const char* pSrc);

struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    template <class T> unsigned int Read(T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pValue, sizeof(T), &uiSize, 1);
    }
    unsigned int ReadLine(char* pcBuffer, unsigned int uiMaxBytes);
};

bool __cdecl FUN_00aa1d40();
extern unsigned int g_uiNifMinVersion_011a9b08;
extern unsigned int g_uiNifMaxVersion_011a9b0c;
extern unsigned int g_uiNifMinUserVersion_011f478c;
extern unsigned int g_uiNifMaxUserVersion_011a9b10;

struct NiTopObjects
{
    void FUN_00a64fe0(unsigned int uiSize);
};

struct NiStreamImpl;
void __cdecl FUN_00a643b0(NiStreamImpl& kStream, unsigned char& ucValue);
void __cdecl FUN_00a26df0(NiStreamImpl& kStream, unsigned int& uiValue);
void __cdecl FUN_00a471d0(NiStreamImpl& kStream, char* pcString, unsigned int uiLength);

struct NiStreamImpl
{
    void* m_vtbl;
    unsigned int m_uiBSVersion;
    char m_acCreator[0x40];
    char m_acExportInfo1[0x40];
    char m_acExportInfo2[0x40];
    char pad0c8[0xd8 - 0xc8];
    unsigned int m_uiNifFileVersion;  // src: FNV360_PDB +0xD8 (old: m_uiNifVersion)
    unsigned int m_uiNifFileUserDefinedVersion;  // src: FNV360_PDB +0xDC (old: StreamFileInfo)
    char pad0e0[0x1e5 - 0xe0];
    unsigned char m_ucEndian;
    char pad1e6[0x1ec - 0x1e6];
    NiTopObjects m_kTopObjects;  // src: FNV360_PDB +0x21C (old: m_kTopLevelObjects)
    char pad1ed[0x24c - 0x1ed];
    NiBinaryStreamStandIn* m_pkIstr;  // src: FNV360_PDB +0x24C (old: m_pUnderlyingStream)
    char pad250[0x3b8 - 0x250];
    unsigned int m_uiLastError;  // src: FNV360_PDB +0x3B8 (old: m_uiNativeThreadId)
    char m_acLastErrorMessage[0x104];  // src: FNV360_PDB +0x3BC (old: m_acSecondPathBuffer)

    bool NiStream_LoadHeader();
};

// Reads and validates the NIF file header from m_pkIstr, storing version, endian, and object count, returning false on any validation failure.
// @fnv 0x00a65400
// pdb: NiStream::LoadHeader | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb: NiStream::LoadHeader | NiStream.obj | fnv360_0822_retail, vtable, high (was: ReadNifHeader)
bool NiStreamImpl::NiStream_LoadHeader()
{
    char acBuffer[0x80];
    m_pkIstr->ReadLine(acBuffer, 0x80);
    if (!strstr(acBuffer, "File Format"))
    {
        m_uiLastError = 2;
        strcpy_s(m_acLastErrorMessage, 0x104, "Not a NIF file");
        return false;
    }
    m_pkIstr->SetEndianSwap(false);
    m_pkIstr->Read(&m_uiNifFileVersion);
    if (m_uiNifFileVersion < g_uiNifMinVersion_011a9b08)
    {
        m_uiLastError = 3;
        strcpy_s(m_acLastErrorMessage, 0x104, "NIF version is too old.");
        return false;
    }
    if (m_uiNifFileVersion > g_uiNifMaxVersion_011a9b0c)
    {
        m_uiLastError = 4;
        strcpy_s(m_acLastErrorMessage, 0x104, "Unknown NIF version.");
        return false;
    }
    m_ucEndian = 1;
    if (m_uiNifFileVersion >= 0x14000003)
        FUN_00a643b0(*this, m_ucEndian);
    if (m_ucEndian != 1 && FUN_00aa1d40())
    {
        m_uiLastError = 6;
        FUN_00404d80(m_acLastErrorMessage, 0x104, "Endian mismatch.");
        return false;
    }
    if (m_uiNifFileVersion >= 0xa000108)
    {
        FUN_00a26df0(*this, m_uiNifFileUserDefinedVersion);
        if (m_uiNifFileVersion == 0xa000165)
            m_uiNifFileUserDefinedVersion = 1;
    }
    if (m_uiNifFileUserDefinedVersion < g_uiNifMinUserVersion_011f478c)
    {
        m_uiLastError = 3;
        strcpy_s(m_acLastErrorMessage, 0x104, "NIF user defined version is too old.");
        return false;
    }
    if (m_uiNifFileUserDefinedVersion > g_uiNifMaxUserVersion_011a9b10)
    {
        m_uiLastError = 4;
        FUN_00404d80(m_acLastErrorMessage, 0x104, "Unknown NIF user defined version.");
        return false;
    }
    unsigned int uiObjects;
    FUN_00a26df0(*this, uiObjects);
    m_kTopObjects.FUN_00a64fe0(uiObjects);
    m_uiBSVersion = 0;
    if (m_uiNifFileVersion > 0xa000100 && (m_uiNifFileVersion <= 0xa000108 || m_uiNifFileUserDefinedVersion))
    {
        if (m_uiNifFileVersion > 0xa000101)
        {
            FUN_00a26df0(*this, m_uiBSVersion);
            if (m_uiNifFileVersion == 0xa000102)
                m_uiNifFileVersion = 0xa000101;
        }
        unsigned char ucLength;
        FUN_00a643b0(*this, ucLength);
        FUN_00a471d0(*this, m_acCreator, ucLength);
        FUN_00a643b0(*this, ucLength);
        FUN_00a471d0(*this, m_acExportInfo1, ucLength);
        FUN_00a643b0(*this, ucLength);
        FUN_00a471d0(*this, m_acExportInfo2, ucLength);
        if (m_uiBSVersion < 0x15)
        {
            m_uiLastError = 3;
            FUN_00404d80(m_acLastErrorMessage, 0x104, "NIF BSversion is too old");
            return false;
        }
    }
    m_pkIstr->SetEndianSwap(m_ucEndian != 1);
    return true;
}
}  // namespace fnv_00a65400

namespace fnv_00a65720 {
class ReadObject
{
  public:
    virtual ~ReadObject();
    virtual void DeleteThis();
    long referenceCount;
    void AddReference()
    {
        InterlockedIncrement(&referenceCount);
    }
    void RemoveReference()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }
};
struct ObjectReference
{
    ReadObject* object;
    ObjectReference(ReadObject* p) : object(p)
    {
        if (object)
            object->AddReference();
    }
};
struct ReadStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dst, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        unsigned int consumed = read(this, dst, bytes, sizes, n);
        position += consumed;
    }
};
template <class T> inline void LoadValue(ReadStream* stream, T& value)
{
    unsigned int componentSize = sizeof(T);
    stream->Read(&value, sizeof(T), &componentSize, 1);
}
struct ObjectReferenceArray
{
    void* vtable;
    ObjectReference* data;
    unsigned int maximum, size, effective, growBy;
    void FUN_00a64fe0(unsigned int);
    void FUN_00cc1a10(unsigned int, const ObjectReference&);
};
class ObjectLoadStream
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    ReadObject** objects;
    unsigned int unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218;
    ObjectReferenceArray topObjects;
    unsigned int unk234, unk238, unk23c, unk240, unk244, unk248;
    ReadStream* input;
    void NiStream_LoadTopLevelObjects();
    ReadObject* GetLoadedObject(unsigned int id)
    {
        return id == 0xffffffff ? 0 : objects[id];
    }
};
// Reads a count and object IDs from input, populates topObjects with ObjectReference entries, and removes references from loaded objects.
// @fnv 0x00a65720
// pdb: NiStream::LoadTopLevelObjects | NiStream.obj | fnv360_0822_retail, vtable, high
// pdb: NiStream::LoadTopLevelObjects | NiStream.obj | fnv360_0822_retail, vtable, high (was: LoadTopObjects)
void ObjectLoadStream::NiStream_LoadTopLevelObjects()
{
    unsigned int count;
    LoadValue(input, count);
    topObjects.FUN_00a64fe0(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int id;
        LoadValue(input, id);
        ReadObject* object = GetLoadedObject(id);
        topObjects.FUN_00cc1a10(i, ObjectReference(object));
        if (object)
            object->RemoveReference();
    }
}
}  // namespace fnv_00a65720

namespace fnv_00a65800 {
extern "C" int __cdecl strcmp(const char* pA, const char* pB);
extern "C" int __cdecl strcpy_s(char* pDest, unsigned int uiSize, const char* pSrc);
extern "C" int __cdecl strcat_s(char* pDest, unsigned int uiSize, const char* pSrc);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

__declspec(nothrow) void* __cdecl FUN_00aa1070(unsigned int uiSize);
__declspec(nothrow) void __cdecl FUN_00aa10f0(void* pvMem);

struct NiBinaryStreamRt
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamRt* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    template <class T> unsigned int Read(T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Read(T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};

struct NiObjectRt
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};
typedef NiObjectRt*(__cdecl* CreateFunction)();

template <class T> struct NiPointerRt
{
    T* m_pObject;
    NiPointerRt(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            InterlockedIncrement(&m_pObject->m_uiRefCount);
    }
    ~NiPointerRt()
    {
        if (m_pObject)
        {
            if (InterlockedDecrement(&m_pObject->m_uiRefCount) == 0)
                m_pObject->DeleteThis();
        }
    }
    operator T*() const
    {
        return m_pObject;
    }
};

struct NiObjectArrayRt
{
    void* m_vtbl;
    NiPointerRt<NiObjectRt>* m_pBase;
    unsigned int m_uiSize;
    unsigned int GetSize() const
    {
        return m_uiSize;
    }
    __declspec(noinline) __declspec(nothrow) void FUN_00cc1a10(unsigned int uiIndex,
                                                               const NiPointerRt<NiObjectRt>& spRetainedObject)
    {
        m_pBase[uiIndex] = spRetainedObject;
    }
};

struct LoaderMap
{
    __declspec(nothrow) bool FUN_00a53c30(const char* pcKey, CreateFunction& pfnValue);
};
extern LoaderMap* g_pkLoaders_011f4784;

struct NiStreamRt
{
    void* m_vtbl;
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
    int unk0c4, unk0c8, unk0cc, unk0d0, unk0d4;
    unsigned int m_uiNifFileVersion;  // src: FNV360_PDB +0xD8 (old: m_uiNifVersion)
    int unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8;
    int unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118;
    int unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138;
    int unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158;
    int unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178;
    int unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198;
    int unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8;
    int unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8;
    int unk1dc, unk1e0, unk1e4, unk1e8;
    NiObjectArrayRt m_kObjects;  // src: FNV360_PDB +0x1EC (old: m_kThirdFollowingStreamField)
    int unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214;
    int unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234;
    int unk238, unk23c, unk240, unk244, unk248;
    NiBinaryStreamRt* m_pkIstr;  // src: FNV360_PDB +0x24C (old: m_pUnderlyingStream)
    int unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c;
    int unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c;
    int unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac;
    int unk2b0, unk2b4, unk2b8, unk2bc, unk2c0, unk2c4, unk2c8, unk2cc;
    int unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec;
    int unk2f0, unk2f4, unk2f8, unk2fc, unk300, unk304, unk308, unk30c;
    int unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c;
    int unk330, unk334, unk338, unk33c, unk340, unk344, unk348, unk34c;
    int unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c;
    int unk370, unk374, unk378, unk37c, unk380, unk384, unk388, unk38c;
    int unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac;
    int unk3b0, unk3b4;
    unsigned int m_uiLastError;  // src: FNV360_PDB +0x3B8 (old: m_uiNativeThreadId)
    char m_acLastErrorMessage[0x104];  // src: FNV360_PDB +0x3BC (old: m_acSecondPathBuffer)

    bool LoadRTTIAndObjects();
};

// Reads RTTI class names and object indices from m_pkIstr, resolves create functions, and instantiates objects into m_kObjects.
// @fnv 0x00a65800
bool NiStreamRt::LoadRTTIAndObjects()
{
    unsigned short usNumRTTI;
    m_pkIstr->Read(&usNumRTTI);
    CreateFunction* ppkCreate = (CreateFunction*)FUN_00aa1070(usNumRTTI * sizeof(CreateFunction));
    for (unsigned int i = 0; i < usNumRTTI; i++)
    {
        char acClassName[256];
        unsigned int uiLength;
        m_pkIstr->Read(&uiLength);
        m_pkIstr->Read(acClassName, uiLength);
        acClassName[uiLength] = 0;
        if (m_uiNifFileVersion < 0x14010001 && strcmp(acClassName, "NiControllerManager") == 0)
        {
            m_uiLastError = 3;
            strcpy_s(m_acLastErrorMessage, 0x104, "Older files may not contain animation data. Reexport required.");
            return false;
        }
        if (!g_pkLoaders_011f4784->FUN_00a53c30(acClassName, ppkCreate[i]))
        {
            m_uiLastError = 5;
            strcpy_s(m_acLastErrorMessage, 0x104, acClassName);
            strcat_s(m_acLastErrorMessage, 0x104, ": cannot find create function.");
            ppkCreate[i] = 0;
        }
        if (acClassName[0] == 'b' && acClassName[1] == 'h' && strcmp(acClassName, "bhkConvexListShape") == 0)
            ppkCreate[i] = 0;
    }
    for (unsigned int j = 0; j < m_kObjects.GetSize(); j++)
    {
        bool bFailed = false;
        unsigned short usIndex;
        m_pkIstr->Read(&usIndex);
        if (m_uiNifFileVersion >= 0x14020005 && (usIndex & 0x8000))
        {
            usIndex &= 0x7fff;
            bFailed = true;
        }
        bool bCreate = ppkCreate[usIndex] != 0;
        if (bCreate)
            bCreate = true;
        if (!bCreate)
        {
            if (!bFailed)
            {
                FUN_00aa10f0(ppkCreate);
                return false;
            }
            m_kObjects.FUN_00cc1a10(j, 0);
        }
        else
        {
            NiPointerRt<NiObjectRt> spRetainedObject = ppkCreate[usIndex]();
            m_kObjects.FUN_00cc1a10(j, spRetainedObject);
        }
    }
    FUN_00aa10f0(ppkCreate);
    return true;
}
}  // namespace fnv_00a65800

namespace fnv_00a65b00 {
void* __cdecl FUN_00aa1070(unsigned int size) throw();
void __cdecl FUN_00aa10f0(void* apMemory) throw();
const char* __cdecl FUN_00a5b690(const char* buf) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*) throw();
extern const char* DAT_0109b220;

class NiBinaryStream
{
  public:
    virtual ~NiBinaryStream();
    virtual operator bool() const = 0;
    virtual void Seek(int iOffset, int iWhence) = 0;

    typedef unsigned int (*ReadFn)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents) throw();
    typedef unsigned int (*WriteFn)(NiBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                    unsigned int* puiComponentSizes, unsigned int uiNumComponents) throw();

    unsigned int m_uiStreamFlags;
    ReadFn m_pfnRead;
    WriteFn m_pfnWrite;

    __forceinline unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                                          unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> __forceinline void NiStreamLoad(NiBinaryStream& kStream, T& value)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiComponentSize, 1);
}

__forceinline void NiStreamLoad(NiBinaryStream& kStream, char* pcBuffer, unsigned int uiTotalBytes)
{
    unsigned int uiComponentSize = 1;
    kStream.BinaryRead(pcBuffer, uiTotalBytes, &uiComponentSize, 1);
}

class NiFixedString
{
  public:
    const char* m_kHandle;

    __forceinline NiFixedString() throw()
    {}
    __forceinline NiFixedString(const char* pcString) throw()
    {
        if (pcString)
            m_kHandle = FUN_00a5b690(pcString);
        else
            m_kHandle = DAT_0109b220;
    }

    __forceinline ~NiFixedString() throw()
    {
        if (m_kHandle != DAT_0109b220)
        {
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
        }
    }
};

class FixedStringTable
{
  public:
    void FUN_00a65140(unsigned int uiSize) throw();
    __declspec(noinline) void FUN_00a63730(unsigned int uiIndex, const NiFixedString& kString) throw()
    {
        const char* h = kString.m_kHandle;
        if (h != DAT_0109b220)
            unk10++;
    }
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class StreamEx
{
  public:
    bool LoadFixedStrings();

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    FixedStringTable m_kFixedStringTable;
    NiBinaryStream* m_spIStream;
};

// Reads a count and string lengths from m_spIStream, allocates a buffer, loads each string into m_kFixedStringTable via FUN_00a63730, and frees the buffer.
// @fnv 0x00a65b00
// pdb: NiStream::LoadFixedStringTable | NiStream.obj | fnv360_0822_retail, call_gap, medium
bool StreamEx::LoadFixedStrings()
{
    unsigned int ItemUpdateArray;
    NiStreamLoad(*m_spIStream, ItemUpdateArray);
    m_kFixedStringTable.FUN_00a65140(ItemUpdateArray);

    unsigned int uiMaxLen;
    NiStreamLoad(*m_spIStream, uiMaxLen);
    char* pcBuffer = (char*)FUN_00aa1070(uiMaxLen + 1);

    for (unsigned short ui = 0; ui < ItemUpdateArray; ui++)
    {
        unsigned int uiLen = 0;
        NiStreamLoad(*m_spIStream, uiLen);
        NiStreamLoad(*m_spIStream, pcBuffer, uiLen);
        pcBuffer[uiLen] = '\0';
        NiFixedString kString;
        if (pcBuffer == 0)
            kString.m_kHandle = DAT_0109b220;
        else
            kString.m_kHandle = FUN_00a5b690(pcBuffer);
        m_kFixedStringTable.FUN_00a63730(ui, kString);
    }

    FUN_00aa10f0(pcBuffer);
    return true;
}
}  // namespace fnv_00a65b00

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkCriticalSection);

struct NiStreamLs;

struct NiObjectLs
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
    virtual void LoadBinary(NiStreamLs& kStream);
    virtual void LinkObject(NiStreamLs& kStream);
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void PostLinkObject(NiStreamLs& kStream);
};

struct NiBinaryStreamLs
{
    virtual void v00();
    virtual void v01();
    virtual void Seek(int iOffset);
    virtual unsigned int GetPosition();
};

struct NiSemaphoreLs
{
    void FUN_00aa3040();
};

typedef void(__cdecl* PostProcessFunction)(NiStreamLs& kStream, NiObjectLs* pkObject);
struct PostProcessArray
{
    void* m_vtbl;
    PostProcessFunction* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
extern PostProcessArray* g_pkPostProcessFunctions_011f4788;
extern char g_kCleanupCriticalSection_011f4800[];

struct NiObjectArrayLs
{
    void* m_vtbl;
    NiObjectLs** m_pBase;
    unsigned int m_uiSize;
    void FUN_00a64250();
};

struct NiStreamLs
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
    virtual bool LoadHeader();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void LoadTopLevelObjects();
    virtual void v19();
    virtual bool LoadObject();
    virtual void v21();
    virtual void v22();
    virtual bool LoadObjectSizeTable();

    char pad004[0xd8 - 4];
    unsigned int m_uiNifFileVersion;  // src: FNV360_PDB +0xD8 (old: m_uiNifVersion)
    char pad0dc[0x1ec - 0xdc];
    NiObjectArrayLs m_kObjects;  // src: FNV360_PDB +0x1EC (old: m_kThirdFollowingStreamField)
    char pad1f8[0x208 - 0x1f8];
    unsigned int* m_puiObjectSizes;
    char pad20c[0x220 - 0x20c];
    NiObjectLs** m_ppkTopObjects;
    int unk224;
    unsigned int m_uiTopObjects;
    char pad22c[0x24c - 0x22c];
    NiBinaryStreamLs* m_pkIstr;  // src: FNV360_PDB +0x24C (old: m_pUnderlyingStream)
    char pad250[0x25c - 0x250];
    int unk25c;
    int unk260;
    int pad264[2];
    int unk26c;
    int unk270;
    char pad274[0x28c - 0x274];
    int m_eBackgroundLoadStatus;  // src: FNV360_PDB +0x28C (old: m_eStreamThreadStatus)
    int pad290;
    unsigned int m_uiLoad;  // src: FNV360_PDB +0x294 (old: StreamThreadContext)
    unsigned int m_uiLink;  // src: FNV360_PDB +0x298 (old: m_uiBackgroundLoadState)
    unsigned int m_uiPostLink;  // src: FNV360_PDB +0x29C (old: BackgroundLoadThreadInfo)
    NiSemaphoreLs* m_pkSemaphore;

    void FUN_00a644f0();
    bool LoadRTTIAndObjects();
    bool LoadFixedStrings();
    void LoadGroups();
    void Clear();
    void FUN_00a63d10();
    bool NiStream_LoadStream();
};

// Loads a NIF stream by reading the header, objects, and top-level links, then runs post-process functions and cleans up.
// @fnv 0x00a65c60
// pdb: NiStream::LoadStream | NiStream.obj | fnv360_0822_retail, call_gap + bridge(vtable|call_gap) + skyrim(vtable), high
bool NiStreamLs::NiStream_LoadStream()
{
    if (!LoadHeader())
        return false;
    m_uiPostLink = 0;
    m_uiLink = 0;
    m_uiLoad = 0;
    FUN_00a644f0();
    bool bRTTI = m_uiNifFileVersion >= 0x05000001;
    if (bRTTI && !LoadRTTIAndObjects())
        return false;
    if (m_uiNifFileVersion >= 0x14020005 && !LoadObjectSizeTable())
        return false;
    if (m_uiNifFileVersion >= 0x14010001 && !LoadFixedStrings())
        return false;
    if (m_uiNifFileVersion >= 0x05000006)
        LoadGroups();

    unsigned int uiObjects = m_kObjects.m_uiSize;
    for (; m_uiLoad < uiObjects; m_uiLoad++)
    {
        if (m_eBackgroundLoadStatus == 2)
            goto abort;
        if (m_eBackgroundLoadStatus == 3)
        {
            m_eBackgroundLoadStatus = 4;
            m_pkSemaphore->FUN_00aa3040();
        }
        if (bRTTI)
        {
            NiObjectLs* pkObject = m_kObjects.m_pBase[m_uiLoad];
            if (pkObject)
            {
                pkObject->LoadBinary(*this);
            }
            else
            {
                m_pkIstr->GetPosition();
                m_pkIstr->Seek(m_puiObjectSizes[m_uiLoad]);
            }
        }
        else if (!LoadObject())
        {
            Clear();
            return false;
        }
    }
    LoadTopLevelObjects();
    for (; m_uiLink < uiObjects; m_uiLink++)
    {
        if (m_eBackgroundLoadStatus == 3)
        {
            m_eBackgroundLoadStatus = 4;
            m_pkSemaphore->FUN_00aa3040();
        }
        NiObjectLs* pkObject = m_kObjects.m_pBase[m_uiLink];
        if (pkObject)
            pkObject->LinkObject(*this);
    }
    for (; m_uiPostLink < uiObjects; m_uiPostLink++)
    {
        if (m_eBackgroundLoadStatus == 3)
        {
            m_eBackgroundLoadStatus = 4;
            m_pkSemaphore->FUN_00aa3040();
        }
        NiObjectLs* pkObject = m_kObjects.m_pBase[m_uiPostLink];
        if (pkObject)
            pkObject->PostLinkObject(*this);
    }
    if (m_eBackgroundLoadStatus == 2)
        goto abort;
    if (m_eBackgroundLoadStatus == 3)
    {
        m_eBackgroundLoadStatus = 4;
        m_pkSemaphore->FUN_00aa3040();
    }
    if (g_pkPostProcessFunctions_011f4788->m_usESize > 0)
    {
        for (unsigned int i = 0; i < m_uiTopObjects; i++)
        {
            NiObjectLs* pkObject = m_ppkTopObjects[i];
            if (pkObject)
            {
                for (unsigned int j = 0; j < g_pkPostProcessFunctions_011f4788->m_usSize; j++)
                {
                    PostProcessFunction pfnFunc = g_pkPostProcessFunctions_011f4788->m_pBase[j];
                    if (pfnFunc)
                        pfnFunc(*this, pkObject);
                }
            }
        }
    }
    if (m_eBackgroundLoadStatus == 2)
    {
    abort:
        EnterCriticalSection(g_kCleanupCriticalSection_011f4800);
        m_kObjects.FUN_00a64250();
        unk25c = 0;
        unk26c = 0;
        unk260 = 0;
        unk270 = 0;
        LeaveCriticalSection(g_kCleanupCriticalSection_011f4800);
        return false;
    }
    FUN_00a63d10();
    EnterCriticalSection(g_kCleanupCriticalSection_011f4800);
    m_kObjects.FUN_00a64250();
    unk25c = 0;
    unk26c = 0;
    unk260 = 0;
    unk270 = 0;
    LeaveCriticalSection(g_kCleanupCriticalSection_011f4800);
    return true;
}

namespace fnv_00a65f80 {
extern char* DAT_0109b220;

struct S_00a65f80_FixedString
{
    char* m_kHandle;
    static void IncRefCount(char* h)
    {
        if (h != DAT_0109b220)
            InterlockedIncrement((long*)(h - 8));
    }
    static void DecRefCount(char* h)
    {
        if (h != DAT_0109b220)
            InterlockedDecrement((long*)(h - 8));
    }
    S_00a65f80_FixedString()
    {
        m_kHandle = DAT_0109b220;
    }
    ~S_00a65f80_FixedString()
    {
        DecRefCount(m_kHandle);
    }
    bool operator==(const S_00a65f80_FixedString& s) const
    {
        return m_kHandle == s.m_kHandle;
    }
    S_00a65f80_FixedString& operator=(const S_00a65f80_FixedString& s)
    {
        if (m_kHandle != s.m_kHandle)
        {
            char* h = s.m_kHandle;
            IncRefCount(h);
            DecRefCount(m_kHandle);
            m_kHandle = h;
        }
        return *this;
    }
};

struct S_00a65f80_Array
{
    virtual ~S_00a65f80_Array();
    S_00a65f80_FixedString* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void FUN_00a65140(unsigned int uiMaxSize);
    void FUN_00a63730(unsigned int uiIndex, const S_00a65f80_FixedString& element);
    unsigned int FUN_00a65f80(const S_00a65f80_FixedString& element);
};

// @fnv 0x00a65f80
// pdb: NiTLargeArray<NiFixedString,NiTNewInterface<NiFixedString> >::AddFirstEmpty | NiStream.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: element
unsigned int S_00a65f80_Array::FUN_00a65f80(const S_00a65f80_FixedString& element)
{
    if (element == S_00a65f80_FixedString())
        return 0xffffffff;
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        if (m_pBase[i] == S_00a65f80_FixedString())
        {
            m_pBase[i] = element;
            m_uiESize++;
            return i;
        }
    }
    unsigned int uiIndex = m_uiSize;
    if (uiIndex >= m_uiMaxSize)
        FUN_00a65140(uiIndex + m_uiGrowBy);
    FUN_00a63730(uiIndex, element);
    return uiIndex;
}
}  // namespace fnv_00a65f80

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00a66030_obj
{
    void DestroyMap();
};
// Calls the object's cleanup method and, when the low bit of flags is set, deallocates the object through g_memoryManager, then returns the object pointer.
// @fnv 0x00a66030
// pdb: NiTStringTemplateMap<NiTMap<char const *,Setting *>,Setting *>::`scalar deleting destructor' | EffectItem.obj | fnv360_0822_retail, vtable, high
FUN_00a66030_obj* __fastcall FUN_00a66030(FUN_00a66030_obj* apThis, int, unsigned int flags)
{
    apThis->DestroyMap();
    if (flags & 1)
        g_memoryManager.Deallocate(apThis);
    return apThis;
}

extern MemoryManager g_memoryManager;
struct FUN_00a66050_obj
{
    void FUN_00a63910();
};
// Calls FUN_00a63910 and deallocates self through g_memoryManager when flags bit 0 is set.
// @fnv 0x00a66050
FUN_00a66050_obj* __fastcall FUN_00a66050(FUN_00a66050_obj* apObject, int, unsigned int flags)
{
    apObject->FUN_00a63910();
    if (flags & 1)
        g_memoryManager.Deallocate(apObject);
    return apObject;
}

namespace fnv_00a66070 {
void __cdecl FUN_00a644a0(void*);
struct DeallocHolder
{
    void _DeallocateAlias(void*);
};
extern DeallocHolder g_memoryManager;
extern int DAT_0109bd4c;
struct Holder66070
{
    void* vf;
    void* mem;
    void* FUN_00a66070(unsigned int);
};
// Saves mem, sets vf to DAT_0109bd4c, calls FUN_00a644a0 with the saved pointer, and conditionally calls _DeallocateAlias on this.
// @fnv 0x00a66070
// pdb: NiTArray<BGSCameraPath *,NiTMallocInterface<BGSCameraPath *> >::`scalar deleting destructor' | BGSCameraPathManager.obj | fnv360_0822_retail, vtable, medium
void* Holder66070::FUN_00a66070(unsigned int flags)
{
    void* tmp = mem;
    vf = (void*)&DAT_0109bd4c;
    FUN_00a644a0(tmp);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00a66070

namespace fnv_00a660a0 {
extern "C" void* fnv_zlib_memset(void* dst, int c, int n);
void* __cdecl NiMalloc(unsigned int uiSize);

class A660A0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern A660A0Heap g_memoryManager;

class A660A0Object
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);
};

class A660A0MapBase : public A660A0Object
{
  public:
    __forceinline A660A0MapBase(unsigned int uiHashSize) throw()
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = static_cast<void**>(NiMalloc(uiSize));
        fnv_zlib_memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
        m_bValueAt0C = false;
    }
    virtual ~A660A0MapBase();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    bool m_bValueAt0C;
};

class A660A0Map : public A660A0MapBase
{
  public:
    __forceinline A660A0Map() throw() : A660A0MapBase(59)
    {}
    virtual ~A660A0Map();
};

template <class T> class A660A0Array : public A660A0Object
{
  public:
    A660A0Array(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = static_cast<T*>(NiMalloc(sizeof(T) * m_usMaxSize));
        else
            m_pBase = 0;
    }
    virtual ~A660A0Array();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class NiUnionBV : public A660A0Array<void*>
{
  public:
    NiUnionBV() throw() : A660A0Array<void*>(0, 3)
    {}
    virtual ~NiUnionBV();
};

extern A660A0Map* DAT_011f4784;
extern NiUnionBV* DAT_011f4788;
extern bool DAT_011f4780;

// Allocates a global A660A0Map and NiUnionBV, and sets the DAT_011f4780 flag to true.
// @fnv 0x00a660a0
// pdb: NiStream::_SDMInit | NiStream.obj | fnv360_0822_retail, call_gap + bridge(uvref|call_dedup) + skyrim(uvref), high
void __cdecl NiStream__SDMInit()
{
    DAT_011f4784 = new A660A0Map;
    DAT_011f4788 = new NiUnionBV;
    DAT_011f4780 = true;
}
}  // namespace fnv_00a660a0

extern int DAT_0109bc64;
extern int DAT_0109bd54;
extern int DAT_0109bdcc;
extern bool DAT_011f4780;
void* __cdecl _NiMalloc(unsigned int uiSize);
void* __cdecl _fnv_zlib_memset(void* pDst, int iValue, unsigned int uiSize);

struct VPtr_a66150
{
    const void* m_pVtbl;
    VPtr_a66150(const void* pVtbl) : m_pVtbl(pVtbl)
    {}
};

struct StreamHeader_a66150
{
    unsigned int m_uiFormatVersion;
    char m_acAuthor[64];
    char m_acProcessScript[64];
    char m_acExportScript[64];
    StreamHeader_a66150()
    {
        m_uiFormatVersion = 0x22;
        m_acAuthor[0] = 0;
        m_acProcessScript[0] = 0;
        m_acExportScript[0] = 0;
    }
};

struct SmallArray_a66150 : VPtr_a66150
{
    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    SmallArray_a66150(const void* pVtbl, unsigned int uiMaxSize, unsigned int uiGrowBy) : VPtr_a66150(0)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usGrowBy == 0)
            m_usGrowBy = 1;
        if (m_usMaxSize > 0)
            m_pBase = (void**)_NiMalloc(sizeof(void*) * m_usMaxSize);
        else
            m_pBase = 0;
        m_pVtbl = pVtbl;
    }
};

struct LargeArray_a66150 : VPtr_a66150
{
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    LargeArray_a66150(const void* pVtbl, unsigned int uiMaxSize, unsigned int uiGrowBy) : VPtr_a66150(0)
    {
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiGrowBy == 0)
            m_uiGrowBy = 1;
        if (m_uiMaxSize > 0)
            m_pBase = (void**)_NiMalloc(sizeof(void*) * m_uiMaxSize);
        else
            m_pBase = 0;
        m_pVtbl = pVtbl;
    }
};

struct Set_a66150
{
    unsigned int* m_pBase;
    unsigned int m_uiAlloced;  // src: FNV360_PDB +0x4 (old: m_uiElementCount)
    unsigned int m_uiUsed;  // src: FNV360_PDB +0x8 (old: m_uiAllocatedCapacity)
    Set_a66150(unsigned int uiInitialSize)
    {
        if (uiInitialSize > 0)
            m_pBase = (unsigned int*)_NiMalloc(sizeof(unsigned int) * uiInitialSize);
        else
            m_pBase = 0;
        m_uiAlloced = uiInitialSize;
        m_uiUsed = 0;
    }
};

struct MapBase_a66150 : VPtr_a66150
{
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    MapBase_a66150(unsigned int uiHashSize) : VPtr_a66150(&DAT_0109bc64)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)_NiMalloc(uiSize);
        _fnv_zlib_memset(m_ppkHashTable, 0, sizeof(void*) * m_uiHashSize);
    }
};

struct Map_a66150 : MapBase_a66150
{
    Map_a66150(unsigned int uiHashSize) : MapBase_a66150(uiHashSize)
    {
        m_pVtbl = &DAT_0109bd54;
    }
};

struct Affinity_a66150
{
    unsigned int m_uiIdealProcessor;
    unsigned int m_uiProcessorAffinityMask;
    Affinity_a66150() : m_uiIdealProcessor(0xffffffff), m_uiProcessorAffinityMask(0xffffffff)
    {}
};

struct ErrorInfo_a66150
{
    unsigned int m_uiLastError;  // src: FNV360_PDB +0x3B8 (old: m_uiNativeThreadId)
    char m_acLastErrorMessage[260];  // src: FNV360_PDB +0x3BC (old: m_acSecondPathBuffer)
    ErrorInfo_a66150()
    {
        m_uiLastError = 0;
        m_acLastErrorMessage[0] = 0;
    }
};

struct FUN_00a66150 : VPtr_a66150
{
    StreamHeader_a66150 m_BSStreamHeader;                   // +0x04  // src: FNV360_PDB +0x4 (old: m_kHeader)
    SmallArray_a66150 m_kGroups;               // +0xc8  // src: FNV360_PDB +0xC8 (old: m_kObjectGroups)
    unsigned int m_uiNifFileVersion;                     // +0xd8  // src: FNV360_PDB +0xD8 (old: m_uiNifVersion)
    unsigned int m_uiNifFileUserDefinedVersion;                     // +0xdc  // src: FNV360_PDB +0xDC (old: StreamFileInfo)
    char m_acFileName[260];                     // +0xe0  // src: FNV360_PDB +0xE0 (old: m_acInputFilePath)
    bool m_bSaveLittleEndian;                         // +0x1e4  // src: FNV360_PDB +0x1E4 (old: m_bFirstStreamFlag)
    bool m_bSourceIsLittleEndian;                        // +0x1e5  // src: FNV360_PDB +0x1E5 (old: m_bSecondStreamFlag)
    unsigned int m_uiUnk1E8;                         // +0x1e8
    LargeArray_a66150 m_kObjects;  // +0x1ec  // src: FNV360_PDB +0x1EC (old: m_kThirdFollowingStreamField)
    LargeArray_a66150 m_kObjectSizes;     // +0x204  // src: FNV360_PDB +0x204 (old: ObjectSerializationStream)
    LargeArray_a66150 m_kTopObjects;            // +0x21c  // src: FNV360_PDB +0x21C (old: m_kTopLevelObjects)
    LargeArray_a66150 m_kFixedStrings;                // +0x234  // src: FNV360_PDB +0x234 (old: m_kStringTable)
    void* m_pkIstr;                       // +0x24c  // src: FNV360_PDB +0x24C (old: m_pUnderlyingStream)
    void* m_pkOstr;                          // +0x250  // src: FNV360_PDB +0x250 (old: m_pBackingStream)
    Set_a66150 m_kLinkIDs;        // +0x254  // src: FNV360_PDB +0x254 (old: m_kSecondFollowingStreamField)
    unsigned int m_uiLinkIndex;                  // +0x260  // src: FNV360_PDB +0x260 (old: StreamObjectIndex)
    Set_a66150 m_kLinkIDBlocks;              // +0x264  // src: FNV360_PDB +0x264 (old: m_kSecondUnsignedIntSet)
    unsigned int m_uiLinkBlockIndex;               // +0x270  // src: FNV360_PDB +0x270 (old: m_uiObjectIndexCount)
    Map_a66150 m_kRegisterMap;                  // +0x274  // src: FNV360_PDB +0x274 (old: m_kObjectToIndexMap)
    unsigned short m_usNiAVObjectFlags;                // +0x284  // src: FNV360_PDB +0x284 (old: m_usAVObjectFlags)
    unsigned short m_usNiTimeControllerFlags;          // +0x286  // src: FNV360_PDB +0x286 (old: m_usTimeControllerFlags)
    unsigned short m_usNiPropertyFlags;                // +0x288  // src: FNV360_PDB +0x288 (old: m_usPropertyFlags)
    unsigned int m_eBackgroundLoadStatus;              // +0x28c  // src: FNV360_PDB +0x28C (old: m_eStreamThreadStatus)
    bool m_bBackgroundLoadExitStatus;                            // +0x290  // src: FNV360_PDB +0x290 (old: m_bThreadActive)
    unsigned int m_uiUnk294;
    unsigned int m_uiUnk298;
    unsigned int m_uiUnk29C;
    void* m_pkThread;               // +0x2a0  // src: FNV360_PDB +0x2A0 (old: m_pBackgroundLoadThread)
    void* m_pkBGLoadProc;                    // +0x2a4  // src: FNV360_PDB +0x2A4 (old: BackgroundLoadTask)
    unsigned int m_ePriority;              // +0x2a8  // src: FNV360_PDB +0x2A8 (old: m_eThreadPriority)
    Affinity_a66150 m_kAffinity;  // +0x2ac  // src: FNV360_PDB +0x2AC (old: m_kBackgroundLoadSemaphore)
    char m_acLastLoadedRTTI[260];                      // +0x2b4  // src: FNV360_PDB +0x2B4 (old: m_acLoadPath)
    ErrorInfo_a66150 m_kError;                   // +0x3b8
    FUN_00a66150();
};

// Initializes the NifStream object, its stream arrays, maps, thread state, and error fields.
// @f3 0x0082cf30 (community match, verified in this file)
extern int DAT_00e2113c;
extern int DAT_00e213a4;
extern int DAT_00e10604;
extern int DAT_00e211f8;
extern int FUN_00f72bd4;
extern int FUN_00f72bd8;

// pdb: NiStream::NiStream | NiStream.obj | fnv360_0822_retail, call_seq, high
FUN_00a66150::FUN_00a66150()
    : VPtr_a66150(&DAT_0109bdcc), m_kGroups(&DAT_00e2113c, 0, 1),
      m_kObjects(&DAT_00e213a4, 0, 1024), m_kObjectSizes(&DAT_00e10604, 0, 1),
      m_kTopObjects(&DAT_00e213a4, 0, 1), m_kFixedStrings(&DAT_00e211f8, 0, 128), m_kLinkIDs(0),
      m_kLinkIDBlocks(0), m_kRegisterMap(37), m_pkThread(0), m_pkBGLoadProc(0),
      m_ePriority(2)
{
    m_pkIstr = 0;
    m_pkOstr = 0;
    m_uiNifFileVersion = FUN_00f72bd4;
    m_uiNifFileUserDefinedVersion = FUN_00f72bd8;
    m_bSaveLittleEndian = true;
    m_bSourceIsLittleEndian = true;
    m_acFileName[0] = 0;
    m_uiLinkIndex = 0;
    m_uiLinkBlockIndex = 0;
    DAT_011f4780 = true;
    m_eBackgroundLoadStatus = 0;
    m_kError.m_uiLastError = 0;
    m_kError.m_acLastErrorMessage[0] = 0;
}


extern MemoryManager g_memoryManager;
struct FUN_00a66350_obj
{
    void _NiStreamDtorAlias();
};
// Calls the NiStream destructor alias and deallocates the object via g_memoryManager when the low bit of flags is set.
// @fnv 0x00a66350
// pdb: SettingT<GameSettingCollection>::`scalar deleting destructor' | EffectItem.obj | fnv360_0822_retail, vtable, high
FUN_00a66350_obj* __fastcall NiStreamDtor(FUN_00a66350_obj* apStream, int, unsigned int flags)
{
    apStream->_NiStreamDtorAlias();
    if (flags & 1)
        g_memoryManager.Deallocate(apStream);
    return apStream;
}

class RefCountedObj
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    long m_iObjectReferenceCount;
};

struct FUN_00a53c30_cls
{
    bool FUN_00a53c30(RefCountedObj* key, RefCountedObj** out);
};

struct UnsignedIntValue
{
    unsigned int value;
};
struct FUN_00b57ea0_cls
{
    void InsertOrUpdate(RefCountedObj* key, UnsignedIntValue value);
};

struct FUN_00a64fe0_cls
{
    void FUN_00a64fe0(unsigned int count);
};

struct FUN_00cc1a10_cls
{
    void FUN_00cc1a10(unsigned int index, RefCountedObj** item);
};

struct ObjArray
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int m_14;
};

struct StreamMatch
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    ObjArray objects;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    FUN_00a53c30_cls linkMap;

    bool AddObject(RefCountedObj* object);
};

// Adds object to linkMap and objects array, incrementing its reference count, then decrements it and returns true.
// @fnv 0x00a663e0
// pdb: NiStream::RegisterSaveObject | NiStream.obj | fnv360_0822_retail, call_dedup, high
// pdb params: pkObject
bool StreamMatch::AddObject(RefCountedObj* object)
{
    RefCountedObj* obj = object;
    FUN_00a53c30_cls* map = &linkMap;
    if (map->FUN_00a53c30(obj, &object))
    {
        return false;
    }
    UnsignedIntValue count = {objects.unk0c};
    ((FUN_00b57ea0_cls*)map)->InsertOrUpdate(obj, count);
    object = obj;
    if (obj != 0)
    {
        InterlockedIncrement(&obj->m_iObjectReferenceCount);
    }
    unsigned int index = objects.unk0c;
    ObjArray* arr = &objects;
    if (index >= arr->m_08)
    {
        ((FUN_00a64fe0_cls*)arr)->FUN_00a64fe0(arr->m_14 + index);
    }
    ((FUN_00cc1a10_cls*)arr)->FUN_00cc1a10(index, &object);
    if (obj != 0)
    {
        long rc = InterlockedDecrement(&obj->m_iObjectReferenceCount);
        if (rc == 0)
        {
            obj->vfn_04();
        }
    }
    return true;
}

extern char* _EmptyFS;

struct S_00a66480_Str
{
    char* handle;
};

struct S_00a66480_Array
{
    void* vtable;
    char** data;
    unsigned int capacity;
    unsigned int size;
    int FUN_00a65f80(const S_00a66480_Str& str);
};

struct S_00a66480
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    S_00a66480_Array names;

    int Find(const S_00a66480_Str& str)
    {
        if (str.handle != _EmptyFS)
        {
            for (unsigned int i = 0; i < names.size; i++)
            {
                if (str.handle == names.data[i])
                    return i;
            }
        }
        return -1;
    }
    bool NiStream_RegisterFixedString(const S_00a66480_Str& str);
};

// Adds str to names if Find(str) returns -1, then returns true.
// @fnv 0x00a66480
// pdb: NiStream::RegisterFixedString | NiStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
bool S_00a66480::NiStream_RegisterFixedString(const S_00a66480_Str& str)
{
    if (Find(str) == -1)
        names.FUN_00a65f80(str);
    return true;
}

namespace fnv_00a664e0 {
struct NiObject
{
    virtual void v00();
    virtual void destroy();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void load(void*);
    long refCount;
};
struct NiPointer
{
    NiObject* object;
};
struct NiStreamTopObjects
{
    unsigned int unk00, unk04, capacity, size, unk10, growBy;
    void FUN_00a64fe0(unsigned int);
    void FUN_00cc1a10(unsigned int, const NiPointer&);
    void Add(const NiPointer& object)
    {
        unsigned int index = size;
        if (index >= capacity)
            FUN_00a64fe0(index + growBy);
        FUN_00cc1a10(index, object);
    }
};
class NiShader;
template <class K, class V> class NiTPointerMap
{
};
template <class K, class V> class NiTStringTemplateMap
{
  public:
    bool GetAt(const char*, NiObject*(__cdecl*& factory)());
};
extern NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*>* DAT_011f4784;
struct NiStreamLoader
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    NiStreamTopObjects topObjects;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int error;
    char errorMessage[260];
    void NiStream_LoadRTTIString(char*);
    bool NiStream_LoadObject();
};
// Looks up a class factory by name, creates and ref-counts a NiObject, adds it to topObjects, and calls load on it.
// @fnv 0x00a664e0
// pdb: NiStream::LoadObject | NiStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
bool NiStreamLoader::NiStream_LoadObject()
{
    char className[256];
    union Creation
    {
        NiObject*(__cdecl* factory)();
        NiPointer instance;
    } creation;
    NiStream_LoadRTTIString(className);
    if (!DAT_011f4784->GetAt(className, creation.factory))
    {
        error = 5;
        strcpy_s(errorMessage, 260, className);
        strcat_s(errorMessage, 260, ": cannot find create function.");
        return false;
    }
    NiObject* pCreatedObject = creation.factory();
    creation.instance.object = pCreatedObject;
    if (pCreatedObject)
        InterlockedIncrement(&pCreatedObject->refCount);
    topObjects.Add(creation.instance);
    if (pCreatedObject && !InterlockedDecrement(&pCreatedObject->refCount))
        pCreatedObject->destroy();
    pCreatedObject->load(this);
    return true;
}
}  // namespace fnv_00a664e0

namespace fnv_00a665f0 {
void* __cdecl FUN_00ec61c0(void* pvDest, int iValue, unsigned int uiSize);
void* __cdecl FUN_00aa1070(unsigned int uiSize);
void __cdecl FUN_00aa10f0(void* pvMem);

struct RtNiRTTI
{
    const char* m_pcName;
    const RtNiRTTI* m_pBaseRTTI;
};

struct RtObject
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual bool IsCloned() const;
    virtual const RtNiRTTI* GetStreamableRTTI() const;
};

struct RtBinaryStream
{
    virtual void v00();
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(RtBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int(__cdecl* m_pfnWrite)(RtBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
};

struct RtMapItem
{
    RtMapItem* m_pkNext;
    const char* m_key;
    unsigned short m_val;
};

class RtMapBase
{
  public:
    RtMapBase(unsigned int uiHashSize)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(RtMapItem*) * m_uiHashSize;
        m_ppkHashTable = (RtMapItem**)FUN_00aa1070(uiSize);
        FUN_00ec61c0(m_ppkHashTable, 0, m_uiHashSize * sizeof(RtMapItem*));
    }
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;

    unsigned int GetCount() const
    {
        return m_uiCount;
    }
    RtMapItem* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void GetNext(RtMapItem*& pos, const char*& key, unsigned short& val) const
    {
        RtMapItem* pkItem = pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }
    bool GetAt(const char* key, unsigned short& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        RtMapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    bool LookupValue(const char* key, unsigned short& val) const;
    void FUN_00a643e0(const char* key, unsigned short val);
    void FUN_00a63910();

    unsigned int m_uiHashSize;
    RtMapItem** m_ppkHashTable;
    unsigned int m_uiCount;
};

class RtStringTmpl : public RtMapBase
{
  public:
    RtStringTmpl(unsigned int uiHashSize, bool bCopy) : RtMapBase(uiHashSize)
    {
        m_bCopy = bCopy;
    }
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
    bool m_bCopy;
};

class RtStringMap : public RtStringTmpl
{
  public:
    RtStringMap(unsigned int uiHashSize = 37, bool bCopy = false) : RtStringTmpl(uiHashSize, bCopy)
    {}
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
};

struct RtStream
{
    void* m_vtbl;
    char pad004[0x1f0 - 4];
    RtObject** m_ppkObjects;
    unsigned int m_uiMaxObjects;
    unsigned int m_uiNumObjects;
    char pad1fc[0x250 - 0x1fc];
    RtBinaryStream* m_pkOstr;  // src: FNV360_PDB +0x250 (old: m_pBackingStream)

    void NiStream_SaveCString(const char* pcString);
    void NiStream_SaveRTTI();
};

// Writes the RTTI name table and per-object RTTI IDs (with clone flag) to the backing stream.
// @fnv 0x00a665f0
// pdb: NiStream::SaveRTTI | NiStream.obj | fnv360_0822_retail, call_seq, high
// pdb: NiStream::SaveRTTI | NiStream.obj | fnv360_0822_retail, call_seq, high (was: WriteRTTIHeader)
void RtStream::NiStream_SaveRTTI()
{
    RtStringMap kRTTIMap;
    unsigned int i;
    for (i = 0; i < m_uiNumObjects; i++)
    {
        const char* pcName = m_ppkObjects[i]->GetStreamableRTTI()->m_pcName;
        unsigned short usID;
        if (!kRTTIMap.LookupValue(pcName, usID))
            kRTTIMap.FUN_00a643e0(pcName, (unsigned short)kRTTIMap.GetCount());
    }

    unsigned short usNumRTTI = (unsigned short)kRTTIMap.GetCount();
    const char** ppcRTTINames = (const char**)FUN_00aa1070(usNumRTTI * sizeof(const char*));
    RtMapItem* pkPos = kRTTIMap.GetFirstPos();
    while (pkPos)
    {
        const char* pcName;
        unsigned short usID;
        kRTTIMap.GetNext(pkPos, pcName, usID);
        ppcRTTINames[usID] = pcName;
    }

    m_pkOstr->Write(&usNumRTTI);
    for (i = 0; i < usNumRTTI; i++)
        NiStream_SaveCString(ppcRTTINames[i]);
    FUN_00aa10f0(ppcRTTINames);

    for (i = 0; i < m_uiNumObjects; i++)
    {
        RtObject* pkObject = m_ppkObjects[i];
        unsigned short usID;
        kRTTIMap.GetAt(pkObject->GetStreamableRTTI()->m_pcName, usID);
        if (pkObject->IsCloned())
            usID |= 0x8000;
        m_pkOstr->Write(&usID);
    }

    kRTTIMap.FUN_00a63910();
}
}  // namespace fnv_00a665f0

namespace fnv_00a66850 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00a66850_shell : public NiStream
{
    bool NiStream_SaveStream();
};

class TESForm;
template <class T> class NiTMallocInterface;

template <class T, class TAlloc> class NiTLargeArray
{
  public:
    void* m_vtbl;
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiSize)
        {
            m_uiSize = uiIndex + 1;
            if (element != T(0))
                m_uiESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_uiESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
};
typedef NiTLargeArray<TESForm*, NiTMallocInterface<TESForm*> > SizeArray;

struct NiStreamTopObjects
{
    void RemoveAll();
};
struct NiTMapBaseStub
{
    void RemoveAll();
};

struct VBinStream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned int GetPosition();
};

struct VObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void SaveBinary(void* kStream);
};

struct VStream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void SaveHeader();
    virtual void v15();
    virtual void v16();
    virtual void RegisterSaveObjects();
    virtual void v18();
    virtual void SaveTopLevelObjects();
    virtual void v20();
    virtual unsigned int GetStartingOffset();
    virtual void BackPatch(unsigned int);
    void NiStream_SaveRTTI();
    void NiStream_SaveFixedStringTable();
    void NiStream_UpdateObjectGroups();
    void WriteData();
};

// Registers save objects, writes the header and each object's binary data, records per-object sizes, then back-patches and clears the object lists.
// @fnv 0x00a66850
// pdb: NiStream::SaveStream | NiStream.obj | fnv360_0822_retail, call_gap + bridge(vtable|call_dedup) + skyrim(vtable), high
bool FUN_00a66850_shell::NiStream_SaveStream()
{
    VStream* pkThis = (VStream*)this;
    pkThis->RegisterSaveObjects();
    SizeArray& kObjectSizes = *(SizeArray*)&m_kObjectSizes;
    kObjectSizes.SetSize(m_kObjects.m_uiSize);
    pkThis->SaveHeader();
    pkThis->NiStream_SaveRTTI();
    unsigned int uiStartingOffset = pkThis->GetStartingOffset();
    pkThis->NiStream_SaveFixedStringTable();
    pkThis->NiStream_UpdateObjectGroups();
    pkThis->WriteData();
    for (unsigned int i = 0; i < m_kObjects.m_uiSize; i++)
    {
        VObject* pkObject = (VObject*)m_kObjects.m_pBase[i].m_pObject;
        unsigned int uiStartInBytes = ((VBinStream*)m_pkOstr)->GetPosition();
        pkObject->SaveBinary(this);
        unsigned int uiSizeInBytes = ((VBinStream*)m_pkOstr)->GetPosition() - uiStartInBytes;
        kObjectSizes.SetAt(i, (TESForm*)uiSizeInBytes);
    }
    pkThis->SaveTopLevelObjects();
    pkThis->BackPatch(uiStartingOffset);
    ((NiStreamTopObjects*)&m_kObjects)->RemoveAll();
    ((NiTMapBaseStub*)&m_kRegisterMap)->RemoveAll();
    return true;
}
}  // namespace fnv_00a66850

namespace fnv_00aa2d30 {
extern int DAT_010a256c;

void NiFreeAlias(void*);

struct NiBinaryStream
{
    virtual ~NiBinaryStream();
};

struct NiMemStream : NiBinaryStream
{
    unsigned int unk04;
    void* unk08;
    void* unk0C;
    char* m_pBuffer;  // src: FNV360_PDB +0x10 (old: m_pBinaryStream)
    unsigned int m_uiPos;  // src: FNV360_PDB +0x14
    unsigned int m_uiEnd;  // src: FNV360_PDB +0x18
    unsigned int m_uiAllocSize;  // src: FNV360_PDB +0x1C
    bool m_bUserMemory;  // src: FNV360_PDB +0x20 (old: m_bSome)
    bool m_bFreeze;  // src: FNV360_PDB +0x21 (old: m_bSome2)
    void NiMemStreamDestructor();
};

// Sets the vtable pointer, frees the buffer at offset 0x10 if the flags at 0x20 and 0x21 are clear, and calls the NiBinaryStream destructor.
// @fnv 0x00aa2d30
// pdb: NiMemStream::~NiMemStream | NiMemStream.obj | fnv360_0822_retail, call_seq, medium
void NiMemStream::NiMemStreamDestructor()
{
    *(void**)this = &DAT_010a256c;
    if (!m_bUserMemory && !m_bFreeze)
        NiFreeAlias(m_pBuffer);
    NiBinaryStream::~NiBinaryStream();
}
}  // namespace fnv_00aa2d30

namespace fnv_00c68050 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};
typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

extern "C"
{
    __declspec(dllimport) void __stdcall EnterCriticalSection(LPCRITICAL_SECTION);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION);
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
}

struct NineIntegerRecord;

struct Flag
{
    int m_flag;
    Flag(int f = 1) : m_flag(f)
    {}
    Flag(const Flag& other) : m_flag(other.m_flag)
    {}
};

struct hkMemoryAllocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
};

struct NineIntegerRecord
{
    void* m_stackStart;
    void* m_stackCurrent;
    void* m_stackEnd;
    char _pad_0c[4];
    hkMemoryAllocator* m_pThreadAllocator;
    char _pad_14[16];
};

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

struct MemContextScope
{
    int oldContext;
    MemContextScope(int newContext)
    {
        oldContext = g_tlsData.memContext;
        g_tlsData.memContext = newContext;
    }
    ~MemContextScope()
    {
        g_tlsData.memContext = oldContext;
    }
};

}  // namespace fnv_00c68050

#include <xmmintrin.h>
// ---------------------------------------------------------------------------
// Stand-ins for the game's objects.
//
//  The original is the constructor of `bhkWorldCinfo`, a class that derives
//  from `hkpWorldCinfo`; both keep a type-table pointer in their first dword
//  and the derived one overwrites the base's with its own.
//
//  The float constants live in .rdata in the game, so they are modelled as
//  `const` objects of this translation unit: that is what lets cl 15.00.30729.01
//  prove that a store through `this` cannot alias them, and therefore hoist
//  their loads to the top of the constructor (exactly like the original).
// ---------------------------------------------------------------------------

union FNV_const_bits
{
    unsigned int u;
    float f;
};

static const FNV_const_bits FNV_k_01011d78 = {0x00000000u};  // 0.0f
static const FNV_const_bits FNV_k_011afed4 = {0xC2C43334u};
static const FNV_const_bits FNV_k_0101e2bc = {0x3DCCCCCDu};  // 0.1f
static const FNV_const_bits FNV_k_0104da48 = {0x7F7FFFEEu};
static const FNV_const_bits FNV_k_unused = {0x00000000u};

struct Thing
{
    int unk00;
    int unk04;
    int m_iValue;
};

struct Stream
{
    void NiStream_GetNumberOfLinkIDs();
    Thing* FUN_00a63430();
};

struct FirstPart
{
    int m_i00;
};

struct ObjBase
{
    int m_i00;
};

struct Derived : FirstPart, ObjBase
{
    int m_i08;
    int m_iFirst;
    int m_iSecond;
};

struct FUN_00c89860_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual ObjBase* Resolve(int* apOut);

    void FUN_00c87670(Stream* apStream);
    void FUN_00c89860(Stream* apStream);
};

// Reads two Thing values from apStream, resolves a Derived object, and stores the values into m_iFirst and m_iSecond before calling FUN_00c87670.
// @f3 0x008fbe70 (community match, verified in this file)
struct StreamF3
{
    void FUN_0082a2b0();
    Thing* FUN_0082a280();
};
struct FUN_00c89860_clsF3
{
    void FUN_008f7ec0(Stream* apStream);
};
// pdb: bhkConstraint::RegisterStreamables | bhkConstraint.obj | fnv360_0822_debug, objrun, low, conflict (bridge: bhkConstraint::LinkObject)
// pdb params: arStream
void FUN_00c89860_cls::FUN_00c89860(Stream* apStream)
{
    ((StreamF3*)apStream)->FUN_0082a2b0();
    Thing* pFirst = ((StreamF3*)apStream)->FUN_0082a280();
    Thing* pSecond = ((StreamF3*)apStream)->FUN_0082a280();

    int iOut;
    Derived* pObject = static_cast<Derived*>(Resolve(&iOut));

    if (pObject != 0 && pFirst != 0)
    {
        pObject->m_iFirst = pFirst->m_iValue;
        pObject->m_iSecond = (pSecond != 0) ? pSecond->m_iValue : 0;
    }

    ((FUN_00c89860_clsF3*)this)->FUN_008f7ec0(apStream);
}


struct S_00ca76b0_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    long m_rc;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    void FreeBuffer();
};

struct S_00ca76b0_Elem
{
    S_00ca76b0_Obj* p;
    int x;
    S_00ca76b0_Elem()
    {
        p = 0;
        x = 0;
    }
    ~S_00ca76b0_Elem()
    {
        if (p && !InterlockedDecrement(&p->m_rc))
            p->vfn_04();
    }
    S_00ca76b0_Elem& operator=(const S_00ca76b0_Elem& o)
    {
        if (p != o.p)
        {
            if (p && !InterlockedDecrement(&p->m_rc))
                p->vfn_04();
            p = o.p;
            if (p)
                InterlockedIncrement(&p->m_rc);
        }
        x = o.x;
        return *this;
    }
};

struct S_00ca76b0_Arr
{
    int unk00;
    S_00ca76b0_Elem* m_pBase;
    unsigned int m_uiMax;
    unsigned int m_uiSize;
    int unk10;
    unsigned int m_uiGrow;
    void Resize(unsigned int n);
    __declspec(noinline) void FUN_00ca49a0(unsigned int idx, const S_00ca76b0_Elem& v)
    {
        if (idx >= m_uiSize)
            m_uiSize = idx + 1;
        m_pBase[idx] = v;
    }
    void Add(const S_00ca76b0_Elem& v)
    {
        unsigned int n = m_uiSize;
        if (n >= m_uiMax)
            Resize(m_uiGrow + n);
        FUN_00ca49a0(n, v);
    }
};

struct S_00ca76b0_Holder
{
    int unk00;
    int unk04;
    S_00ca76b0_Arr arr;
};

struct S_00ca76b0_Stream
{
    int unk00;
    unsigned int unk04;
    unsigned int NiStream_GetNumberOfLinkIDs();
    S_00ca76b0_Obj* FUN_00a63430();
};

struct S_00ca76b0_Cls
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual S_00ca76b0_Holder* vfn_b4(char* flag);
    void FUN_00c84cc0(S_00ca76b0_Stream* s);
    void FUN_00ca76b0(S_00ca76b0_Stream* s);
};

// Reads a count and objects from s, conditionally prepares the holder array, fills entries, and calls FUN_00c84cc0.
// @f3 0x00912f50 (community match, verified in this file)
// pdb: bhkNiTriStripsShape::LinkObject | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: bhkRigidBody::LinkObject)
// pdb params: arStream
void S_00ca76b0_Cls::FUN_00ca76b0(S_00ca76b0_Stream* apStream)
{
    char flag;
    S_00ca76b0_Holder* h = vfn_b4(&flag);
    if (h)
    {
        unsigned int count = apStream->NiStream_GetNumberOfLinkIDs();
        if (apStream->unk04 < 2)
        {
            S_00ca76b0_Arr* arr = &h->arr;
            arr->Resize(count);
            for (unsigned int i = 0; i < count; i++)
            {
                const S_00ca76b0_Elem tmp;
                arr->Add(tmp);
            }
        }
        for (unsigned int i = 0; i < count; i++)
        {
            S_00ca76b0_Obj* o = apStream->FUN_00a63430();
            o->FreeBuffer();
            S_00ca76b0_Obj*& slot = h->arr.m_pBase[i].p;
            S_00ca76b0_Obj* old = slot;
            if (old != o)
            {
                if (old && !InterlockedDecrement(&old->m_rc))
                    old->vfn_04();
                slot = o;
                if (o)
                    InterlockedIncrement(&o->m_rc);
            }
        }
    }
    FUN_00c84cc0(apStream);
}


extern __declspec(thread) unsigned int g_uiHeapContext;

struct HeapContextGuard
{
    unsigned int m_uiOld;
    HeapContextGuard(unsigned int uiNew)
    {
        m_uiOld = g_uiHeapContext;
        g_uiHeapContext = uiNew;
    }
    ~HeapContextGuard()
    {
        g_uiHeapContext = m_uiOld;
    }
};

namespace fnv_00a64df0 {
#include <windows.h>

extern const char* DAT_0109b220;
const char* __cdecl FUN_00a5b690(const char* text);

class NiFixedString
{
  public:
    const char* m_data;

    NiFixedString& operator=(const char* text)
    {
        if (m_data != text)
        {
            const char* previous = m_data;
            m_data = FUN_00a5b690(text);
            if (previous != DAT_0109b220)
                InterlockedDecrement(reinterpret_cast<volatile LONG*>(const_cast<char*>(previous) - 8));
        }
        return *this;
    }

    NiFixedString& operator=(const NiFixedString& other)
    {
        if (m_data != other.m_data)
        {
            const char* replacement = other.m_data;
            if (replacement != DAT_0109b220)
                InterlockedIncrement(reinterpret_cast<volatile LONG*>(const_cast<char*>(replacement) - 8));
            if (m_data != DAT_0109b220)
                InterlockedDecrement(reinterpret_cast<volatile LONG*>(const_cast<char*>(m_data) - 8));
            m_data = replacement;
        }
        return *this;
    }
};

struct BinaryStream
{
    unsigned int unk00;
    unsigned int bytesRead;
    unsigned int(__cdecl* read)(BinaryStream*, void*, unsigned int, const unsigned int*, unsigned int);

    void Read(void* buffer, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        bytesRead += read(this, buffer, bytes, &componentSize, 1);
    }
};

class NiObject;
class FUN_00a64df0_Stream
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual unsigned int vfn_2c(const NiObject* object);
    void SaveLinkID(const NiObject* object);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    NiFixedString* strings;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    BinaryStream* input;
    void __thiscall NiStream_LoadFixedString(NiFixedString& result);
};

// @fnv 0x00a64df0
// pdb: NiStream::LoadFixedString | NiStream.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(call_gap), high
void FUN_00a64df0_Stream::NiStream_LoadFixedString(NiFixedString& result)
{
    unsigned int id;
    input->Read(&id, 4);
    if (id == 0xffffffffu)
        result = static_cast<const char*>(0);
    else
        result = strings[id];
}
}  // namespace fnv_00a64df0

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section);

struct S_00c68150_Lock
{
    void* m_debugInfo;
    long m_lLockCount;
    long m_recursionCount;
    void* m_owningThread;
    void* m_lockSemaphore;
    unsigned long m_spinCount;
    ~S_00c68150_Lock()
    {
        DeleteCriticalSection(this);
    }
};

struct S_00c68150_Elem
{
    int unk00;
    int unk04;
    int unk08;
    ~S_00c68150_Elem();
};

struct FUN_00c68150
{
    S_00c68150_Lock m_lock;
    S_00c68150_Elem m_entries[16];
    ~FUN_00c68150();
};

// Destroys the object, releasing the critical section and the 16-entry array via the member destructors.
// @f3 0x008d39d0 (community match, verified in this file)
FUN_00c68150::~FUN_00c68150()
{
}


// Stores object at index, extends m_uiSize to index + 1 when needed, and adjusts m_uiESize based on the slot and object.
// @fnv 0x00cc1a10
// pdb: NiRefObject::IncRefCount | ExtraDataCell.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: NiTLargeArray<class NiPointer<class NiObject>,class NiTNewInterface<class NiPointer<class NiObject> > >::SetAt)
void NiStreamTopObjects::FUN_00cc1a10(unsigned int index, const NiPointer<NiObject>& object)
{
    if (index >= m_uiSize)
    {
        m_uiSize = index + 1;
        if (object != NiPointer<NiObject>(0))
            ++m_uiESize;
    }
    else
    {
        if (object != NiPointer<NiObject>(0))
        {
            if (m_pBase[index] == NiPointer<NiObject>(0))
                ++m_uiESize;
        }
        else
        {
            if (m_pBase[index] != NiPointer<NiObject>(0))
                --m_uiESize;
        }
    }
    m_pBase[index] = object;
}
