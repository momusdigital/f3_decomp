// gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp: NiPSysModifier (9 functions)
#include "f3_common.h"
#include "NiCloningProcess.h"
#include "NiPSysModifier.h"
#include "NiStream.h"

// @fnv 0x00C318B0
// pdb: NiPSysModifier::LoadBinary | NiPSysModifier.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void NiPSysModifier::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    if (kStream.GetFileVersion() < NiStream::GetVersion(20, 1, 0, 1))
        kStream.LoadCStringAsFixedString(m_kName);
    else
        kStream.LoadFixedString(m_kName);

    NiStreamLoadBinary(kStream, m_uiOrder);
    kStream.ReadLinkID();
    unsigned char ucActive;
    NiStreamLoadBinary(kStream, ucActive);
    m_bActive = ucActive != 0;
}

struct FUN_00c31780_shell : public NiPSysModifier
{
    void CopyMemberData(NiPSysModifier* pkDest, NiCloningProcess& kCloning);
};
// @fnv 0x00C31780
// pdb: NiPSysModifier::CopyMembers | NiPSysModifier.obj | fnv360_0822_retail, call_seq, medium, conflict (bridge: NiPSysBombModifier::NiPSysBombModifier)
// pdb params: pkDest, kCloning
void FUN_00c31780_shell::CopyMemberData(NiPSysModifier* pkDest, NiCloningProcess& kCloning)
{
    NiObject::CopyMembers(pkDest, kCloning);
    pkDest->m_kName = m_kName;
    pkDest->m_uiOrder = m_uiOrder;
    pkDest->m_bActive = m_bActive;
}

// @fnv 0x00C317E0
// pdb: NiPSysModifier::ProcessClone | NiPSysModifier.obj | fnv360_0822_retail, vtable, high
// pdb params: kCloning
void NiPSysModifier::ProcessClone(NiCloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    NiObject* pkClone = 0;
    kCloning.m_pkCloneMap->GetAt(this, pkClone);
    NiPSysModifier* pkDest = (NiPSysModifier*)pkClone;
    kCloning.m_pkCloneMap->GetAt((NiObject*)m_pkTarget, pkClone);
    pkDest->m_pkTarget = (NiParticleSystem*)pkClone;
}

// @fnv 0x00C31650
// pdb: NiPSysModifier::LinkObject | NiPSysModifier.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void NiPSysModifier::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    kStream.GetObjectFromLinkID();
}

// @fnv 0x00c31640
// pdb: BaseProcess::SetCurrentProcedureIndex | BaseProcess.obj | fnv360_0822_retail, vtable, medium
// F3_EXE: NiPSysModifier vtable slot 39 (SetSystemPointer)
// pdb params: aiNewIndex
void NiPSysModifier::SetSystemPointer(NiParticleSystem* pkTarget)
{
    m_pkTarget = pkTarget;
}

// Compares the base object, then the name, order and active flag.
// @fnv 0x00c31830
// pdb: NiPSysModifier::IsEqual | NiPSysModifier.obj | fnv360_0822_retail, call_seq, medium
// F3_EXE: NiPSysModifier vtable slot 23 (IsEqual)
// pdb params: pkObject
bool NiPSysModifier::IsEqual(NiObject* pkObject)
{
    NiPSysModifier* pkDest = (NiPSysModifier*)pkObject;
    if (NiObject::IsEqual(pkObject) && m_kName == pkDest->m_kName && m_uiOrder == pkDest->m_uiOrder &&
        m_bActive == pkDest->m_bActive)
        return true;
    return false;
}

// @fnv 0x00c31670
// pdb: NiPSysModifier::RegisterStreamables | NiPSysModifier.obj | fnv360_0822_retail, call_seq, medium
// F3_EXE: NiPSysModifier vtable slot 21 (RegisterStreamables)
// pdb params: kStream
bool NiPSysModifier::RegisterStreamables(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    kStream.RegisterFixedString(m_kName);
    return true;
}

// @fnv 0x00c31950
// F3_EXE: NiPSysModifier vtable slot 22 (SaveBinary)
void NiPSysModifier::SaveBinary(NiStream& kStream)
{
    NiObject::SaveBinary(kStream);
    kStream.SaveFixedString(m_kName);
    NiStreamSaveBinary(kStream, m_uiOrder);
    kStream.SaveLinkID((const NiObject*)m_pkTarget);
    NiStreamSaveBinary(kStream, (unsigned char)m_bActive);
}

extern "C" char* DAT_0109b220;
extern "C" void(__stdcall* DAT_00fdf1c0)(char*);
extern "C" void(__stdcall* DAT_00fdf1c4)(char*);

struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pElement);
    __forceinline void Add(char* pElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pElement);
    }
};

struct FUN_00c319e0_cls : NiPSysModifier
{
    void FUN_00c319e0(StrArr* apViewerStrings);
};

// Appends the modifier's name, order and active flag as formatted strings to the given string array.
// @f3 0x00ab5420 (community match, verified in this file)
struct Array482 {
    void* table;char** data;unsigned short capacity,size,effective,growth;
    void FUN_00555790(unsigned int);void FUN_005b3880(unsigned int,char*&);
    __forceinline void Add(char* value) {
        unsigned int index=size;
        if(index>=capacity) FUN_00555790(index+growth);
        FUN_005b3880(index,value);
    }
};
struct Base482 { void FUN_00abcb40(StrArr*); };
struct Layout482 {
    unsigned int unk0,unk4,unk8,unkc,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58;
    const char* name; unsigned short order;
};
extern const char* DAT_0116db0c;
extern const char DAT_00e8b13c[],DAT_00e8b128[];
char* __cdecl FUN_00847b50(const char*);
char* __cdecl FUN_00847e20(const char*,const char*);
char* __cdecl FUN_00847ce0(const char*,unsigned int);
// pdb: BSPSysMultiTargetEmitterCtlr::GetViewerStrings | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void FUN_00c319e0_cls::FUN_00c319e0(StrArr* strings) {
    reinterpret_cast<Base482*>(this)->FUN_00abcb40(strings);
    Array482* array=reinterpret_cast<Array482*>(strings);
    Layout482* owner=reinterpret_cast<Layout482*>(this);
    array->Add(FUN_00847b50(DAT_0116db0c));
    array->Add(FUN_00847e20(DAT_00e8b13c,owner->name));
    array->Add(FUN_00847ce0(DAT_00e8b128,owner->order));
}


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);

namespace c318 {
extern char* DAT_0109b220;
}

class NiFixedStringC318
{
  public:
    ~NiFixedStringC318()
    {
        if (m_kHandle != c318::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

class FUN_00a5d3d0
{
  public:
    virtual ~FUN_00a5d3d0();
    long m_uiRefCount;
};

class NamedC318 : public FUN_00a5d3d0
{
  public:
    virtual ~NamedC318()
    {}

    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        FUN_00aa1460(pvMem, uiSize);
    }

    NiFixedStringC318 m_kName;
    int unk0C[3];

    NamedC318* FUN_00c31870(unsigned int uiFlags);
};

// Releases the NamedC318 object, calling its destructor and freeing memory when uiFlags has bit 0 set, then returns this.
// @fnv 0x00c31870
// pdb: NiPSysModifier::`scalar deleting destructor' | NiPSysModifier.obj | fnv360_0822_retail, objrun, high
NamedC318* NamedC318::FUN_00c31870(unsigned int uiFlags)
{
    this->NamedC318::~NamedC318();
    if (uiFlags & 1)
        NamedC318::operator delete(this, sizeof(NamedC318));
    return this;
}
