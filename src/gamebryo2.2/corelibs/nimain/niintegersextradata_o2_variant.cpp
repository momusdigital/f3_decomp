#include "f3_common.h"
// src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niintegersextradata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "niintegersextradata_decls.h"

extern char const* const g_012043a4_arg1;

// @fnv 0x00a99940
// pdb: NiSpecularProperty::GetRTTI | NiSpecularProperty.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
char const* const* __cdecl NiSpecularProperty_GetRTTI()
{
    return &g_012043a4_arg1;
}

extern "C" void __cdecl NiFreeAlias(void* p);
extern int DAT_010a0c7c;
struct FUN_00a7b300_shell
{
    void __thiscall FUN_00a7b300();
};
struct FUN_00a99950_shell
{
    int vtbl;
    int f04;
    int f08;
    int f0c;
    int f10;
    void __thiscall FUN_00a99950();
};
// @fnv 0x00a99950
// pdb: NiIntegersExtraData::~NiIntegersExtraData | NiIntegersExtraData.obj | tesv_win, hash, low
void __thiscall FUN_00a99950_shell::FUN_00a99950()
{
    void* p = *(void**)((char*)this + 0x10);
    *(int*)this = (int)&DAT_010a0c7c;
    NiFreeAlias(p);
    *(int*)((char*)this + 0x10) = 0;
    ((FUN_00a7b300_shell*)this)->FUN_00a7b300();
}

extern int DAT_010a0c7c;

extern int DAT_010a0c7c;
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiExtraDataShell : NiExtraData
{
    void FUN_00a7b2e0();
};
// @fnv 0x00a99a10
// pdb: NiIntegersExtraData::CreateObject | NiIntegersExtraData.obj | fnv360_0822_retail, caller_sim, low
NiExtraData* FUN_00a99a10()
{
    NiExtraData* data = static_cast<NiExtraData*>(BSFadeNode::operator new(0x14));
    if (data)
    {
        static_cast<NiExtraDataShell*>(data)->FUN_00a7b2e0();
        data->baseData[0] = reinterpret_cast<unsigned int>(&DAT_010a0c7c);
        data->baseData[4] = 0;
        data->baseData[3] = 0;
        return data;
    }
    return 0;
}

namespace fnv_00a99a50 {
extern "C" void NiFreeAlias(void*);
void __cdecl FUN_00a7b300();
extern char DAT_010a0c7c;
struct FUN_00a99a50_shell
{
    int vtbl;
    int a;
    int b;
    int c;
    int d;
    void __thiscall FUN_00a7b300();
    FUN_00a99a50_shell* __thiscall FUN_00a99a50(int);
    void __cdecl operator delete(void* p, unsigned int);
};
// @fnv 0x00a99a50
// pdb: NiFloatsExtraData::`scalar deleting destructor' | NiFloatsExtraData.obj | fnv360_0822_retail, objrun, medium
FUN_00a99a50_shell* __thiscall FUN_00a99a50_shell::FUN_00a99a50(int flag)
{
    vtbl = (int)&DAT_010a0c7c;
    NiFreeAlias((void*)d);
    d = 0;
    FUN_00a7b300();
    if (flag & 1)
        operator delete(this, 0x14);
    return this;
}
}  // namespace fnv_00a99a50

struct Extra_00a998e0
{
    unsigned char _pad0[12];
    unsigned int m_uiSize;
    int* m_piValue;
    bool NiIntegersExtraData_IsEqual(Extra_00a998e0* pObject);
};
// @fnv 0x00a998e0
// pdb: NiIntegersExtraData::IsEqual | NiIntegersExtraData.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_open), high
bool Extra_00a998e0::NiIntegersExtraData_IsEqual(Extra_00a998e0* pObject)
{
    Extra_00a998e0* pExtra = pObject;
    unsigned int i;
    if (!pExtra)
        return false;
    if (m_uiSize != pExtra->m_uiSize)
        return false;
    if (m_piValue && !pExtra->m_piValue)
        return false;
    if (!m_piValue && pExtra->m_piValue)
        return false;
    if (m_piValue)
    {
        for (i = 0; i < m_uiSize; i++)
        {
            if (m_piValue[i] != pExtra->m_piValue[i])
                return false;
        }
    }
    return true;
}

void* __cdecl _NiMalloc(unsigned int);
struct FUN_00a99870_shell : public NiExtraData
{
    unsigned int m_uiSize;
    int* m_piValue;
    void FUN_00a7b330(void* pDest, void* pCloning);
    void __thiscall NiIntegersExtraData_CopyMembers(FUN_00a99870_shell* pDest, void* pCloning);
};
// @fnv 0x00a99870
// pdb: NiIntegersExtraData::CopyMembers | NiIntegersExtraData.obj | fnv360_0822_retail, call_dedup + bridge(call_seq|call_dedup) + skyrim(objrun_prop), high
void __thiscall FUN_00a99870_shell::NiIntegersExtraData_CopyMembers(FUN_00a99870_shell* pDest, void* pCloning)
{
    FUN_00a7b330(pDest, pCloning);
    if (m_piValue && m_uiSize > 0)
    {
        pDest->m_uiSize = m_uiSize;
        pDest->m_piValue = (int*)_NiMalloc(m_uiSize * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pDest->m_piValue[i] = m_piValue[i];
    }
    else
    {
        pDest->m_piValue = 0;
        pDest->m_uiSize = 0;
    }
}

template <class T> class NiTPrimitiveArray
{
  public:
    void* m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    inline void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else if (element)
        {
            if (!m_pBase[uiIndex])
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex])
                m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
    inline unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};

typedef NiTPrimitiveArray<char*> NiViewerStringsArray;

char* CreateDebugString(const char* pcText);
char* CreateDebugString(const char* pcPrefix, unsigned int uiValue);
char* CreateDebugString(const char* pcPrefix, int iValue);

extern const char* g_011f5f24;

struct NiIntegersExtraDataView : NiExtraData
{
    unsigned int m_uiSize;
    int* m_piValue;
    void BaseGetViewerStrings(NiViewerStringsArray* pkStrings);
    void FUN_00a99b20(NiViewerStringsArray* pkStrings);
};

// @fnv 0x00a99b20
// pdb: NiIntegersExtraData::GetViewerStrings | NiIntegersExtraData.obj | fnv360_0822_retail, vtable, medium
// pdb params: pStrings
void NiIntegersExtraDataView::FUN_00a99b20(NiViewerStringsArray* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    pkStrings->Add(CreateDebugString(g_011f5f24));
    pkStrings->Add(CreateDebugString("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
        pkStrings->Add(CreateDebugString("m_piValue[i]", m_piValue[i]));
}

class NiPSysBaseA99
{
  public:
    NiPSysBaseA99() throw();
    virtual ~NiPSysBaseA99();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04, unk08;
};

class NiPSysDerivedA99 : public NiPSysBaseA99
{
  public:
    NiPSysDerivedA99() throw()
    {
        m_pkSecond = 0;
        m_pkFirst = 0;
    }
    virtual ~NiPSysDerivedA99();

    void* m_pkFirst;
    void* m_pkSecond;
};

class NiPSysOwnerA99
{
  public:
    void CopyMemberData(NiPSysBaseA99* pkDest, void* pvProcess);
    NiPSysBaseA99* NiFloatsExtraData_CreateClone(void* pvProcess);
};

// @fnv 0x00a999b0
// pdb: NiFloatsExtraData::CreateClone | NiFloatsExtraData.obj | fnv360_0822_retail, caller_sim + bridge(vtable|objrun_prop) + skyrim(objrun_prop), high
NiPSysBaseA99* NiPSysOwnerA99::NiFloatsExtraData_CreateClone(void* pvProcess)
{
    NiPSysDerivedA99* pkClone = new NiPSysDerivedA99;
    CopyMemberData(pkClone, pvProcess);
    return pkClone;
}
