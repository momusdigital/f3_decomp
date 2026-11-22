#include "f3_common.h"
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "nitarray.inl"

struct StrArr
{
    unsigned char m_auiShapeKeys[8];
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_pAuxiliaryObject;
    unsigned short m_growth;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct FUN_00cc6540_Class
{
    unsigned char m_auiShapeKeys[4];
    void* m_pUserData;

    void FUN_00c8a560(StrArr* array);
    void FUN_00cc6540(StrArr* array);
};

char* __cdecl FUN_00a7d550(char const* name, float value);

// @fnv 0x00cc6540
// pdb: hkRagdollLimitsConstraintCinfo::GetViewerStrings | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail, strset, low
// pdb params: apStrings
void FUN_00cc6540_Class::FUN_00cc6540(StrArr* array)
{
    FUN_00c8a560(array);

    unsigned char* data = static_cast<unsigned char*>(m_pUserData);
    if (data)
    {
        char* value = FUN_00a7d550("ConeMinAngle", *reinterpret_cast<float*>(data + 0xa0));
        unsigned int index = array->m_uiItemCount;
        unsigned int size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("PlaneMinAngle", *reinterpret_cast<float*>(data + 0xb0));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("PlaneMaxAngle", *reinterpret_cast<float*>(data + 0xb4));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("TwistMinAngle", *reinterpret_cast<float*>(data + 0x88));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("TwistMaxAngle", *reinterpret_cast<float*>(data + 0x8c));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);
    }
}

namespace fnv_00cf46e0 {
struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_008;
    unsigned short m_00a;
    unsigned short m_00c;
    unsigned short m_00e;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct GlobalObjectO2_00a7b610
{
    unsigned char _pad[0x2b4];
    unsigned int m_02b4;
};

extern __declspec(thread) GlobalObjectO2_00a7b610 g_tls_object;

struct TLSGuard
{
    unsigned int saved;

    TLSGuard() : saved(g_tls_object.m_02b4)
    {
        g_tls_object.m_02b4 = 0x10;
    }

    ~TLSGuard()
    {
        g_tls_object.m_02b4 = saved;
    }
};

}  // namespace fnv_00cf46e0

struct CharPtrArr
{
    int unk00;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short unk0C;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    int FUN_00a5b4b0(char*& value);
};

// @fnv 0x00a5b4b0
// pdb: NiTArray<CombatGroup *,NiTMallocInterface<CombatGroup *> >::AddFirstEmpty | CombatManager.obj | fnv360_0822_retail, call_seq, high
// pdb params: element
int CharPtrArr::FUN_00a5b4b0(char*& value)
{
    if (value == 0)
        return -1;
    unsigned short i = 0;
    for (; i < m_usSize; i++)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = value;
            unk0C++;
            return i;
        }
    }
    unsigned int count = m_usSize;
    if (count >= m_usMaxSize)
        SetSize(m_usGrowBy + count);
    SetAt(count, value);
    return count;
}

extern __declspec(thread) int g_iC8AD40AllocTag;

struct BC8AD40AllocTagScope
{
    int m_iSaved;

    BC8AD40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC8AD40AllocTag;
        g_iC8AD40AllocTag = aiAllocationTag;
    }
    ~BC8AD40AllocTagScope()
    {
        g_iC8AD40AllocTag = m_iSaved;
    }
};

class BC8AD40StringArray
{
  public:
    virtual ~BC8AD40StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

namespace fnv_00cc31c0 {
extern __declspec(thread) int g_iCC31C0MemContext;

class CC31C0MemContext
{
  public:
    CC31C0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC31C0MemContext;
        g_iCC31C0MemContext = aiMemoryContext;
    }
    ~CC31C0MemContext()
    {
        g_iCC31C0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

extern "C" char* __cdecl FUN_00a7d330(const char* pcName);

class CC31C0StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

}  // namespace fnv_00cc31c0

struct ViewerObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void* GetType();
};
struct ViewerConstraint
{
    int unk00;
    ViewerObject* object;
    int priority;
    void* entityA;
    void* entityB;
    void FUN_00c8a560(BC8AD40StringArray* array);
};
// @f3 0x008fc920 (community match, verified in this file)
struct C8AD40ViewerObj
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* GetType();
};
const char* __cdecl bhkConstraintManager_GetTypeName(void*);
char* __cdecl FUN_00847e70(const char*, const char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
char* __cdecl FUN_00847d30(const char*, int);

// pdb: hkConstraintCinfo::GetViewerStrings | bhkConstraint.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void ViewerConstraint::FUN_00c8a560(BC8AD40StringArray* array)
{
    char* text;
    char buffer[32];
    if (object)
    {
        text = FUN_00847e70("Type", bhkConstraintManager_GetTypeName(((C8AD40ViewerObj*)object)->GetType()));
        array->Add(text);
    }
    FUN_00403230(buffer, 32, "0x%8X", entityA);
    text = FUN_00847e70("hkpEntityA", buffer);
    array->Add(text);
    FUN_00403230(buffer, 32, "0x%8X", entityB);
    text = FUN_00847e70("hkpEntityB", buffer);
    array->Add(text);
    text = FUN_00847d30("ePriority", priority);
    array->Add(text);
}


// Appends this class name to the viewer strings after the base entries, under the Havok allocation tag.

extern __declspec(thread) int g_iCC4740AllocTag;

struct BCC4740AllocTagScope
{
    int m_iSaved;

    BCC4740AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = aiAllocationTag;
    }
    ~BCC4740AllocTagScope()
    {
        g_iCC4740AllocTag = m_iSaved;
    }
};

class BCC4740StringArray
{
  public:
    virtual ~BCC4740StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

extern __declspec(thread) int g_iCC4740AllocTag;
struct CF4520AllocTagScope
{
    int saved;
    CF4520AllocTagScope(int tag)
    {
        saved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = tag;
    }
    ~CF4520AllocTagScope()
    {
        g_iCC4740AllocTag = saved;
    }
};
char* __cdecl FUN_00a7d330(const char* name);
struct CF4520Array
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char* const& item);
    unsigned int Add(char* const& item)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, item);
        return index;
    }
};

extern __declspec(thread) int g_iCCCFD0AllocTag;
struct BCCCFD0AllocTagScope
{
    int m_iSaved;

    BCCCFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCCFD0AllocTag;
        g_iCCCFD0AllocTag = aiAllocationTag;
    }
    ~BCCCFD0AllocTagScope()
    {
        g_iCCCFD0AllocTag = m_iSaved;
    }
};

class BCCCFD0StringArray
{
  public:
    virtual ~BCCCFD0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern "C" void _ReadWriteBarrier();
struct CAA010Inner
{
    virtual void OpA();
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void OpF();
    virtual void OpG();
    virtual void OpH();
    virtual void* GetHandle();
};

struct CAA010Shell
{
    virtual void Activate(int flag);
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void PassArray(struct CAA010Arr* array);
    void SetChildObject(CAA010Inner* inner);
};

struct CAA010Data
{
    int unk00;
    int unk04;
    int unk08;
    CAA010Inner* m_obj;
    int unk10;
    int unk14;
    int unk18;
    float m_f;
};

extern __declspec(thread) int g_caa010TlsTag;

struct CAA010TagScope
{
    int m_iSaved;
    CAA010TagScope(int aiAllocationTag)
    {
        m_iSaved = g_caa010TlsTag;
        g_caa010TlsTag = aiAllocationTag;
    }
    ~CAA010TagScope()
    {
        g_caa010TlsTag = m_iSaved;
    }
};

struct CAA010Arr
{
    int unk00;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    unsigned int SetAtGrow(unsigned int index, char* const& value)
    {
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, (char*&)value);
        return index;
    }
};

struct CAA010This
{
    int unk00;
    void* m_pUserData;
    void FUN_00c8a560(CAA010Arr* array);
    CAA010Inner* GetObj()
    {
        return m_pUserData ? ((CAA010Data*)m_pUserData)->m_obj : 0;
    }
    void FUN_00caa010(CAA010Arr* array);
};

// @f3 0x00948000 (community match, verified in this file)
#include <intrin.h>
extern const char DAT_00e7a8dc[],DAT_00e7a8d0[];
char* __cdecl FUN_00847dd0(const char*,float);
char* __cdecl FUN_00847b90(const char*,bool);
struct Inner948 {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void* Handle();
};
struct Shell948 {
    virtual void Destroy(int);
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Save(CAA010Arr*);
    void FUN_008fbbb0(Inner948*);
};
Shell948* __cdecl FUN_0097a820(void*);
struct Data948{int unk00,unk04,unk08,unk0C,unk10,unk14;Inner948* inner;int unk1C;float threshold;unsigned char broken; __forceinline bool IsBroken() const { return broken != 0; }};

// pdb: hkBreakableConstraintCinfo::GetViewerStrings | bhkBreakableConstraint.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void CAA010This::FUN_00caa010(CAA010Arr* array)
{
    FUN_00c8a560(array);
    {
        char* value = FUN_00847dd0(DAT_00e7a8dc, m_pUserData ? ((Data948*)m_pUserData)->threshold : 0.0f);
        array->SetAtGrow(array->m_usSize, value);
    }
    {
        char* value = FUN_00847b90(DAT_00e7a8d0, m_pUserData ? ((Data948*)m_pUserData)->IsBroken() : false);
        array->SetAtGrow(array->m_usSize, value);
    }
    Inner948* inner = m_pUserData ? ((Data948*)m_pUserData)->inner : 0;
    _ReadWriteBarrier();
    if (inner)
    {
        Shell948* shell = FUN_0097a820(inner->Handle());
        if (shell)
        {
            shell->FUN_008fbbb0(inner);
            shell->Save(array);
            shell->Destroy(1);
        }
    }
}


// @f3 0x004a3380 (community match, verified in this file)
extern const char DAT_00dc3b84[], DAT_00dc3b70[];
namespace f3m_004a3380 {
char* __cdecl FUN_00847b50(const char* name);
char* __cdecl FUN_00847d80(const char* name, unsigned int count);

struct CArr4a3380 {
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00555790(unsigned int size);
    void FUN_005b3880(unsigned int index, char* const& item);
    unsigned int Add(char* const& item) {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_00555790(index + m_usGrowBy);
        FUN_005b3880(index, item);
        return index;
    }
};

struct Holder4a3380 {
    unsigned int FUN_00402bd0(CArr4a3380* pkArray);
    unsigned int FUN_004a3380(CArr4a3380* pkArray);
};

// pdb: GameSettingCollection::GetViewerStrings | XGameSetting.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStringsA
unsigned int Holder4a3380::FUN_004a3380(CArr4a3380* pkArray)
{
    unsigned int I;
    pkArray->Add(FUN_00847b50(DAT_00dc3b84));
    I = FUN_00402bd0(pkArray);
    pkArray->Add(FUN_00847d80(DAT_00dc3b70, I));
    return I;
}
}   // namespace f3m_004a3380

