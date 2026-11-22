// src/f3staging/f3blk_008a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008ab100 (community match, verified in this file)
#include <string.h>

int __cdecl sprintf(char* pBuffer, const char* pFormat, ...);

struct A8b110Allocator
{
    void* FUN_00aa3e40(unsigned int uSize);
};

extern A8b110Allocator DAT_011f6238;

// pdb: NiControllerSequence::GetViewerString | NiControllerSequence.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPrefix, aeState
void* __cdecl FUN_008ab100(const char* pcText, unsigned int uType)
{
    void* pBuffer = DAT_011f6238.FUN_00aa3e40((unsigned int)strlen(pcText) + 0x20);
    const char* pszType = 0;
    switch (uType)
    {
    case 0:
        pszType = "INACTIVE";
        break;
    case 1:
        pszType = "ANIMATING";
        break;
    case 2:
        pszType = "EASEIN";
        break;
    case 3:
        pszType = "EASEOUT";
        break;
    case 4:
        pszType = "TRANSSOURCE";
        break;
    case 5:
        pszType = "TRANSDEST";
        break;
    case 6:
        pszType = "MORPHSOURCE";
        break;
    default:
        break;
    }
    sprintf((char*)pBuffer, "%s = %s", pcText, pszType);
    return pBuffer;
}

// @f3 0x008bf920 (community match, verified in this file)
extern const void* DAT_01092750;
namespace f3m_008bf920 {
namespace fo3_8bf920 {
struct StrArr
{
    unsigned int unk00; unsigned int unk04;
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short unk0c;
    unsigned short m_uiGrowSize;

    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};


char* __cdecl FUN_00847b50(char*);
char* __cdecl FUN_00847d80(char const*, unsigned int);

struct FUN_00a457d0_shell
{
    unsigned int unk00; unsigned int unk04;
    unsigned int m_uiNumUOffsetKeys;
    unsigned int unk0c; unsigned int unk10;
    unsigned int m_uiNumVOffsetKeys;
    unsigned int unk18; unsigned int unk1c;
    unsigned int m_uiNumUTilingKeys;
    unsigned int unk24; unsigned int unk28;
    unsigned int m_uiNumVTilingKeys;

    void FUN_00825b40(StrArr*);
    void FUN_008bf920(StrArr*);
};

// @fnv 0x00a457d0
// pdb: NiUVData::GetViewerStrings | NiUVData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pStrings
void FUN_00a457d0_shell::FUN_008bf920(StrArr* apViewerStrings)
{
    char* pString;
    unsigned int nIndex;

    FUN_00825b40(apViewerStrings);

    pString = FUN_00847b50(const_cast<char*>(static_cast<const char*>(DAT_01092750)));
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->FUN_00555790(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->FUN_005b3880(nIndex, pString);

    pString = FUN_00847d80("m_uiNumUOffsetKeys", m_uiNumUOffsetKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->FUN_00555790(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->FUN_005b3880(nIndex, pString);

    pString = FUN_00847d80("m_uiNumUTilingKeys", m_uiNumUTilingKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->FUN_00555790(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->FUN_005b3880(nIndex, pString);

    pString = FUN_00847d80("m_uiNumVOffsetKeys", m_uiNumVOffsetKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->FUN_00555790(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->FUN_005b3880(nIndex, pString);

    pString = FUN_00847d80("m_uiNumVTilingKeys", m_uiNumVTilingKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->FUN_00555790(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->FUN_005b3880(nIndex, pString);
}

}
}   // namespace f3m_008bf920

// @f3 0x008ab1a0 (community match, verified in this file)
namespace f3m_008ab1a0 {
namespace f3m_008ab1a0 { extern unsigned char DAT_00e2d338; }
struct O8ab1a0 { int a0, a4, a8; unsigned char c; unsigned char d; O8ab1a0* FUN_008ab1a0(); };
// pdb: NiControllerSequence::InterpArrayItem::InterpArrayItem | NiControllerSequence.obj | tesv_win, hash, low
O8ab1a0* O8ab1a0::FUN_008ab1a0() { a0 = 0; a4 = 0; a8 = 0; c = f3m_008ab1a0::DAT_00e2d338; d = 0xff; return this; }
}   // namespace f3m_008ab1a0

// @f3 0x008a0810 (community match, verified in this file)
namespace f3m_008a0810 {
namespace f3m_008a0810 { extern unsigned char DAT_01091e99; void __cdecl FUN_0089f7c0(); void __cdecl FUN_0089ec60(); }
// pdb: NiSystemSDM::Init | NiSystemSDM.obj | fnv360_0822_debug, udata + bridge(call_seq|call_seq) + skyrim(hash), high
void __cdecl NiSystemSDM_Init() { using namespace f3m_008a0810; if (!DAT_01091e99) { DAT_01091e99 = 1; FUN_0089f7c0(); FUN_0089ec60(); } }
}   // namespace f3m_008a0810

// @f3 0x008a0830 (community match, verified in this file)
namespace f3m_008a0830 {
namespace f3m_008a0830 { extern unsigned char DAT_01091e99; void __cdecl FUN_0089ecc0(); void __cdecl FUN_00c24b70(); }
// pdb: NiSystemSDM::Shutdown | NiSystemSDM.obj | fnv360_0822_retail, udata + bridge(call_seq|call_seq) + skyrim(udata), high
void __cdecl NiSystemSDM_Shutdown() { using namespace f3m_008a0830; if (DAT_01091e99) { DAT_01091e99 = 0; FUN_0089ecc0(); FUN_00c24b70(); } }
}   // namespace f3m_008a0830

// @f3 0x008a86b0 (community match, verified in this file)
namespace f3m_008a86b0 {
int __cdecl FUN_0089eb00(int a, int b);
// pdb: NiTStringTemplateMap<NiTMap<char const *,NiPointer<BSFaceGenModelMap::Entry> >,NiPointer<BSFaceGenModelMap::Entry> >::IsKeysEqual | BSFaceGenManager.obj | fnv360_0822_retail, vtable, high
// pdb params: pcKey1, pcKey2
int __stdcall FUN_008a86b0(int a, int b) { return FUN_0089eb00(a, b) == 0; }
}   // namespace f3m_008a86b0

// @f3 0x008a8440 (community match, verified in this file)
namespace f3m_008a8440 {
namespace f3m_008a8440 { extern int DAT_01091ef0; void __cdecl FUN_008a7b60(); void __cdecl FUN_008a8130(); void __cdecl FUN_0089f820(void (__cdecl* a)(), void (__cdecl* b)()); }
struct O8a8440 { O8a8440* FUN_008a8440(); };
// pdb: NiAnimationSDM::NiAnimationSDM | NiAnimationSDM.obj | fnv360_0822_retail, caller_sim, low
O8a8440* O8a8440::FUN_008a8440() { using namespace f3m_008a8440; if (DAT_01091ef0++ == 0) FUN_0089f820(FUN_008a7b60, FUN_008a8130); return this; }
}   // namespace f3m_008a8440

// @f3 0x008bf080 (community match, verified in this file)
extern const char* DAT_01092748;
namespace f3m_008bf080 {
namespace register_name_008bf080 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008d13b0(NameArray*);
    void FUN_008bf080(NameArray*);
};
// pdb: NiVisController::GetViewerStrings | NiVisController.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pkStrings
void Object::FUN_008bf080(NameArray* names) {
    FUN_008d13b0(names);
    void* value=FUN_00847b50(DAT_01092748);
    names->Append(value);
}
}

}   // namespace f3m_008bf080

// @f3 0x008bb3b0 (community match, verified in this file)
extern const char* DAT_010926b4;
namespace f3m_008bb3b0 {
namespace register_name_008bb3b0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008b20a0(NameArray*);
    void FUN_008bb3b0(NameArray*);
};
// pdb: NiBlendTransformInterpolator::GetViewerStrings | NiBlendTransformInterpolator.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_008bb3b0(NameArray* names) {
    FUN_008b20a0(names);
    void* value=FUN_00847b50(DAT_010926b4);
    names->Append(value);
}
}

}   // namespace f3m_008bb3b0

// @f3 0x008b96b0 (community match, verified in this file)
extern const char* DAT_01092698;
namespace f3m_008b96b0 {
namespace register_name_008b96b0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008b6de0(NameArray*);
    void FUN_008b96b0(NameArray*);
};
// pdb: NiPathInterpolator::GetViewerStrings | NiPathInterpolator.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_008b96b0(NameArray* names) {
    FUN_008b6de0(names);
    void* value=FUN_00847b50(DAT_01092698);
    names->Append(value);
}
}

}   // namespace f3m_008b96b0

// @f3 0x008b6de0 (community match, verified in this file)
extern const char* DAT_01091f98;
namespace f3m_008b6de0 {
namespace register_name_008b6de0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008d0d30(NameArray*);
    void FUN_008b6de0(NameArray*);
};
// pdb: NiKeyBasedInterpolator::GetViewerStrings | NiKeyBasedInterpolator.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkStrings
void Object::FUN_008b6de0(NameArray* names) {
    FUN_008d0d30(names);
    void* value=FUN_00847b50(DAT_01091f98);
    names->Append(value);
}
}

}   // namespace f3m_008b6de0

// @f3 0x008bd0d0 (community match, verified in this file)
extern const char* DAT_01092708;
namespace f3m_008bd0d0 {
namespace register_name_008bd0d0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008d1230(NameArray*);
    void FUN_008bd0d0(NameArray*);
};
// pdb: BSFrustumFOVController::GetViewerStrings | BSFrustumFOVController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_008bd0d0(NameArray* names) {
    FUN_008d1230(names);
    void* value=FUN_00847b50(DAT_01092708);
    names->Append(value);
}
}

}   // namespace f3m_008bd0d0

// @f3 0x008b0870 (community match, verified in this file)
extern const char* DAT_01091f44;
namespace f3m_008b0870 {
namespace register_name_008b0870 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008b2830(NameArray*);
    void FUN_008b0870(NameArray*);
};
// pdb: NiTransformController::GetViewerStrings | NiTransformController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_008b0870(NameArray* names) {
    FUN_008b2830(names);
    void* value=FUN_00847b50(DAT_01091f44);
    names->Append(value);
}
}

}   // namespace f3m_008b0870

// @f3 0x008ac8c0 (community match, verified in this file)
namespace f3m_008ac8c0 {
namespace task0728 {
struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_008ac8c0(unsigned int idx, NiRefStubB5652** a2);
};

// Stores a NiRefStubB5652 pointer at index idx in m_04, updating m_0a, m_0c and reference counts as needed.
// @fnv 0x00a32940
// pdb: NiTArray<NiPointer<NiInterpController>,NiTNewInterface<NiPointer<NiInterpController> > >::SetAt | NiControllerSequence.obj | fnv360_0822_retail, callee_sim, low
// pdb params: uiIndex, element
void FUN_00a32940_cls::FUN_008ac8c0(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((unsigned int)*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((unsigned int)*apNewStub != key.m_00)
        {
            if ((unsigned int)m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((unsigned int)m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

}
}   // namespace f3m_008ac8c0

// @f3 0x008aa4f0 (community match, verified in this file)
extern const char* DAT_01091f0c;
extern const char DAT_00e2cfa4[];
namespace f3m_008aa4f0 {
namespace viewer_008aa4f0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847ce0(const char*,unsigned short);
struct Object {
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
    unsigned short value;
    void FUN_008a8570(NameArray*);
    void FUN_008aa4f0(NameArray*);
};
// pdb: NiMultiTargetTransformController::GetViewerStrings | NiMultiTargetTransformController.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void Object::FUN_008aa4f0(NameArray* names) {
    FUN_008a8570(names);
    void* handle=FUN_00847b50(DAT_01091f0c);
    names->Append(handle);
    handle=FUN_00847ce0(DAT_00e2cfa4,value);
    names->Append(handle);
}
}
}   // namespace f3m_008aa4f0

// @f3 0x008a8640 (community match, verified in this file)
extern int DAT_00e2cdac,DAT_00e2cd8c,DAT_00e2cd6c;
namespace f3m_008a8640 {
namespace Task0835 {
void __cdecl FUN_0089e890(void*);
void __fastcall FUN_006bd950(void*);
struct Node {Node* m_pkNext; void* m_pvVal;};
struct Table {
 int* m_ppVirtualMethodTable;
 unsigned int m_uiHashSize;
 Node** m_ppkHashTable;
 unsigned int unk0c;
 unsigned char m_bOwnsNodes;
 void FUN_008a8640();
};
// @fnv 0x00a2e460
// pdb: NiTStringTemplateMap<NiTPointerMap<char const *,NiControllerSequence *>,NiControllerSequence *>::~NiTStringTemplateMap<NiTPointerMap<char const *,NiControllerSequence *>,NiControllerSequence *> | NiControllerManager.obj | fnv360_0721_beta, call_seq, low, conflict (skyrim: BSTScatterTableBase<struct BSTScatterTableTraits<class BSFixedStringCI,class NiControllerSequence *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<class BSFixedStringCI>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<class BSFixedStringCI,class NiControllerSequence *,struct BSTScatterTableDefaultKVStorage> >,8> >::~BSTScatterTableBase<struct BSTScatterTableTraits<class BSFixedStringCI,class NiControllerSequence *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<class BSFixedStringCI>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<class BSFixedStringCI,class NiControllerSequence *,struct BSTScatterTableDefaultKVStorage> >,8> >)
void Table::FUN_008a8640()
{
    m_ppVirtualMethodTable = &DAT_00e2cdac;
    if (m_bOwnsNodes != 0)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            Node* node = m_ppkHashTable[i];
            while (node != 0)
            {
                Node* cur = node;
                void* val = cur->m_pvVal;
                node = cur->m_pkNext;
                FUN_0089e890(val);
            }
        }
    }
    m_ppVirtualMethodTable = &DAT_00e2cd8c;
    FUN_006bd950(this);
    m_ppVirtualMethodTable = &DAT_00e2cd6c;
    FUN_006bd950(this);
    FUN_0089e890(m_ppkHashTable);
}

}
}   // namespace f3m_008a8640

// @f3 0x008b4040 (community match, verified in this file)
extern char DAT_00e2d674;
namespace f3m_008b4040 {
namespace task1176 {
void* __cdecl FUN_0089eb90(unsigned int size) throw();

struct FUN_008a8490
{
    void* vtable;
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
    FUN_008a8490() throw();
};

struct TreadInterpolator : FUN_008a8490
{
    unsigned int unk34;
    unsigned short unk38;
    unsigned short unk3a;
    unsigned int unk3c;
    unsigned short unk40;
    unsigned short unk42;

    static void* operator new(unsigned int size) throw()
    {
        return FUN_0089eb90(size);
    }
    TreadInterpolator() throw()
    {
        vtable = &DAT_00e2d674;
        unk34 = 0;
        unk38 = 0;
        unk3c = 0;
        unk40 = 0;
    }
};

struct TreadController
{
    TreadInterpolator* __thiscall BSMultiTargetTreadTransfController_CreateClone(unsigned int index);
    void __thiscall FUN_008a8470(TreadInterpolator* interp, unsigned int index);
};

// @fnv 0x00a35a10
// pdb: BSMultiTargetTreadTransfController::CreateClone | BSMultiTargetTreadTransfController.obj | fnv360_0822_retail, caller_sim + bridge(vtable|caller_sim) + skyrim(caller_sim), high
TreadInterpolator* TreadController::BSMultiTargetTreadTransfController_CreateClone(unsigned int index)
{
    TreadInterpolator* interp = new TreadInterpolator;
    FUN_008a8470(interp, index);
    return interp;
}
}

}   // namespace f3m_008b4040

// @f3 0x008bb750 (community match, verified in this file)
struct Class8bb750 {
    int unk00;
    const Class8bb750* parent;
    bool isSuperClass(const Class8bb750* other) const {
        const Class8bb750* c = other;
        while (c) {
            if (c == this) return true;
            c = c->parent;
        }
        return false;
    }
};

extern Class8bb750 DAT_01091f90;

struct Obj8bb750 {
    virtual void vf00();
    virtual void vf04();
    virtual const Class8bb750* vf08();
    void FUN_008b6690(float value);
};

struct Data8bb750 {
    int unk00, unk04, unk08;
    float unk0c;
};

struct Owner8bb750 {
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
    Data8bb750* unk3c;
    void FUN_008bb750(Obj8bb750* object, int unused);
};

static inline Obj8bb750* Cast8bb750(Obj8bb750* o) {
    if (!o) return 0;
    return DAT_01091f90.isSuperClass(o->vf08()) ? o : 0;
}

// pdb: NiFloatExtraDataController::SynchronizePoseInterpolator | NiFloatExtraDataController.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pkInterp, usIndex
void Owner8bb750::FUN_008bb750(Obj8bb750* object, int unused) {
    Cast8bb750(object)->FUN_008b6690(unk3c->unk0c);
}

// @f3 0x008b9700 (community match, verified in this file)
namespace f3m_008b9700 {
struct Vec3_9700 { float x, y, z; };
struct Vec4_9700 { float r, g, b, a; };
}
extern f3m_008b9700::Vec4_9700 DAT_01092a08;
extern const f3m_008b9700::Vec3_9700 FUN_00f7933c;
namespace f3m_008b9700 {
void* __cdecl FUN_0089eb90(unsigned int size);

class FUN_008b6bf0 {
public:
    FUN_008b6bf0() throw();
    virtual ~FUN_008b6bf0();
    int unk04;
    int unk08;
};
class Obj_9700 : public FUN_008b6bf0 {
public:
    short unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;
    float unk28;
    float unk2C;
    short unk30;
    float unk34;
    int unk38;
    Vec4_9700 color;
    Vec3_9700 point;
    float unk58;

    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p);
    __forceinline Obj_9700() throw()
        : unk18(0), unk1C(0), color(DAT_01092a08), point(FUN_00f7933c)
    {
        unk28 = 0.0f;
        unk2C = 0.0f;
        unk34 = 0.0f;
        unk24 = -1.0f;
        unk10 = 0;
        unk58 = -3.402823466e+38F;
        unk14 = 0;
        unk38 = 1;
        unk30 = 0;
        unk20 = 0;
        unk0C = 3;
    }
    virtual ~Obj_9700();
};
struct Owner_9700 {
    void FUN_008b9450(Obj_9700* obj, int arg);
    Obj_9700* FUN_008b9700(int arg);
};
}
using namespace f3m_008b9700;

// pdb: NiPathInterpolator::CreateClone | NiPathInterpolator.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: kCloning
Obj_9700* Owner_9700::FUN_008b9700(int arg)
{
    Obj_9700* obj = new Obj_9700();
    FUN_008b9450(obj, arg);
    return obj;
}

// @f3 0x008b05a0 (community match, verified in this file)
struct V3 { float x, y, z; };

class ThreeByThreeMatrix
{
public:
    float m_afEntry[9];
};

struct V4
{
    float x, y, z, w;
    void FromRotationMatrix(const ThreeByThreeMatrix& kMat);
};

struct LcRTTI
{
    unsigned int unk00;
    LcRTTI* unk04;
};

extern LcRTTI DAT_011f3e50;

struct TransformObj
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30;
    ThreeByThreeMatrix m_kRotate;
    V3 m_kTranslate;
    float m_fScale;
};

struct ApplyArgs
{
    V3 m_kTranslate;
    V4 m_kQuat;
    float m_fScale;
};

struct TargetObj
{
    virtual void vf00();
    virtual void vf04();
    virtual LcRTTI* GetRTTI();
    void Apply(ApplyArgs kArgs);
};

struct C_8b05a0
{
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28;
    TransformObj* unk2c;

    void FUN_008b05a0(TargetObj* pTarget, int unkArg);
};

// pdb: NiTransformController::SynchronizePoseInterpolator | NiTransformController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkInterp, usIndex
void C_8b05a0::FUN_008b05a0(TargetObj* pTarget, int unkArg)
{
    TargetObj* pSel;
    if (!pTarget)
    {
        pSel = 0;
    }
    else
    {
        bool bFound = false;
        LcRTTI* pRTTI = pTarget->GetRTTI();
        while (pRTTI)
        {
            if (pRTTI == &DAT_011f3e50)
            {
                bFound = true;
                goto done;
            }
            pRTTI = pRTTI->unk04;
        }
        bFound = false;
    done:
        pSel = bFound ? pTarget : 0;
    }

    TransformObj* pT = this->unk2c;
    V4 kQuat;
    kQuat.FromRotationMatrix(pT->m_kRotate);
    ApplyArgs kArgs;
    kArgs.m_kTranslate = pT->m_kTranslate;
    kArgs.m_kQuat = kQuat;
    kArgs.m_fScale = pT->m_fScale;
    pSel->Apply(kArgs);
}

// @f3 0x008b9600 (community match, verified in this file)
#include <float.h>

struct NiQuaternion
{
    float x, y, z, w;
};

class NiPoint3
{
public:
    float x, y, z;
};

extern NiQuaternion g_kInvalidQuat;
extern const NiPoint3 g_kA495F0InvalidPoint;

template <class T> class NiPathPtr
{
public:
    T* m_pObject;
    NiPathPtr(T* pObject = 0) : m_pObject(pObject) {}
};

class NiMemObject
{
public:
    static void* operator new(unsigned int uSize);
};

class NiKeyBasedInterpolator : public NiMemObject
{
public:
    NiKeyBasedInterpolator();
    virtual ~NiKeyBasedInterpolator();

    unsigned int m_uiUnk04;
    unsigned int m_uiUnk08;
};

class NiPathInterpolator : public NiKeyBasedInterpolator
{
public:
    __forceinline NiPathInterpolator() throw()
    {
        m_kUnk3C = g_kInvalidQuat;
        m_kUnk4C = g_kA495F0InvalidPoint;
        m_fUnk28 = 0.0f;
        m_fUnk2C = 0.0f;
        m_uiUnk10 = 0;
        m_fUnk34 = 0.0f;
        m_uiUnk14 = 0;
        m_usUnk30 = 0;
        m_fUnk24 = -1.0f;
        m_pkUnk20 = 0;
        m_fUnk58 = -FLT_MAX;
        m_uiUnk38 = 1;
        m_usUnk0C = 3;
    }

    unsigned short  m_usUnk0C;
    unsigned int    m_uiUnk10;
    unsigned int    m_uiUnk14;
    NiPathPtr<void> m_spUnk18;
    NiPathPtr<void> m_spUnk1C;
    void*           m_pkUnk20;
    float           m_fUnk24;
    float           m_fUnk28;
    float           m_fUnk2C;
    unsigned short  m_usUnk30;
    float           m_fUnk34;
    unsigned int    m_uiUnk38;
    NiQuaternion    m_kUnk3C;
    NiPoint3        m_kUnk4C;
    float           m_fUnk58;
};

// pdb: NiPathInterpolator::CreateObject | NiPathInterpolator.obj | fnv360_0822_retail, objrun, medium
NiPathInterpolator* FUN_008b9600()
{
    return new NiPathInterpolator;
}

// @f3 0x008b4dc0 (community match, verified in this file)
namespace f3m_008b4dc0 {
struct Inner
{
    unsigned int unk00;
    unsigned int unk04;
    volatile unsigned short value08;
};
struct Owner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34;
    Inner* inner38;
    unsigned short NiGeomMorpherController_GetInterpolatorCount() const;
};
// pdb: NiGeomMorpherController::GetInterpolatorCount | NiGeomMorpherController.obj | fnv360_0822_retail, objrun + bridge(vtable|objrun) + skyrim(objrun_open), high
unsigned short Owner::NiGeomMorpherController_GetInterpolatorCount() const
{
    return inner38 ? inner38->value08 : static_cast<unsigned short>(0);
}


}   // namespace f3m_008b4dc0

// @f3 0x008be9e0 (community match, verified in this file)
extern int DAT_00e2e65c;
namespace f3m_008be9e0 {
struct ResetB_008be9e0 { int* vtable; void FUN_00825830(); void FUN_008be9e0(); };
// pdb: BSAnimNote::~BSAnimNote | BSAnimNote.obj | fnv360_0822_retail, objrun_prop, low
void ResetB_008be9e0::FUN_008be9e0() { vtable = &DAT_00e2e65c; FUN_00825830(); }
}   // namespace f3m_008be9e0

// @f3 0x008b6c10 (community match, verified in this file)
extern int FUN_00e2d9b4;
namespace f3m_008b6c10 {
namespace Dtor_008b6c10
{

struct Owner
{
    void FUN_008d0ca0();
    void FUN_008b6c10();
};

// pdb: NiKeyBasedInterpolator::~NiKeyBasedInterpolator | NiKeyBasedInterpolator.obj | fnv360_0822_retail, call_seq, high
void Owner::FUN_008b6c10()
{
    *(int*)this = (int)&FUN_00e2d9b4;
    FUN_008d0ca0();
}
}
}   // namespace f3m_008b6c10

// @f3 0x008bd140 (community match, verified in this file)
extern int FUN_00e2e36c;
namespace f3m_008bd140 {
namespace Dtor_008bd140
{

struct Owner
{
    void FUN_008b1190();
    void FUN_008bd140();
};

// pdb: BSBlendTreadTransfInterpolator::~BSBlendTreadTransfInterpolator | BSBlendTreadTransfInterpolator.obj | fnv360_0822_retail, objrun_prop, medium
void Owner::FUN_008bd140()
{
    *(int*)this = (int)&FUN_00e2e36c;
    FUN_008b1190();
}
}
}   // namespace f3m_008bd140

// @f3 0x008b7b50 (community match, verified in this file)
namespace f3m_008b7b50 {
// pdb: NiPSysEmitterCtlr::GetInterpolatorCount | NiPSysEmitterCtlr.obj | fnv360_0721_beta, vtable, medium
unsigned short __cdecl FUN_008b7b50()
{
    return 2;
}
}   // namespace f3m_008b7b50

// @f3 0x008a9230 (community match, verified in this file)
#include <string.h>
#include <new>
void* __cdecl NiMalloc(unsigned int size);
struct FUN_00a414f0_NiTPrimitiveArray
{
    int unk00, unk04, unk08, unk0c;
    FUN_00a414f0_NiTPrimitiveArray() throw();
    static void* operator new(unsigned int n) throw() { return DAT_011f6238.FUN_00aa3e40(n); }
};
struct Base106
{
    void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    Base106();
};
namespace w8a9230 {
extern void* DAT_00e2cdd4[];
extern void* DAT_00e2ce90[];
extern void* DAT_00e2cd6c[];
extern void* DAT_00e2ce98[];
struct TArray
{
    void* vtable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    TArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        vtable = DAT_00e2ce90;
    }
};
struct TList
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    TList() { m_pkHead = 0; m_pkTail = 0; m_uiCount = 0; }
};
struct List3
{
    int a, b, c;
    List3() { a = 0; b = 0; c = 0; }
};
struct TMapBase
{
    void* vtable;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    TMapBase(unsigned int uiHashSize)
    {
        vtable = DAT_00e2cd6c;
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        m_ppkHashTable = (void**)NiMalloc(sizeof(void*) * uiHashSize);
        memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
    }
};
struct TStringMap : TMapBase
{
    bool m_bCopy;
    TStringMap(unsigned int uiHashSize, bool bCopy) : TMapBase(uiHashSize)
    {
        m_bCopy = bCopy;
        vtable = DAT_00e2ce98;
    }
};
}
namespace w8a9230 { struct Mid : Base106 { Mid() { vtable = DAT_00e2cdd4; } }; }
class FUN_008a9230 : public w8a9230::Mid
{
public:
    w8a9230::TArray m_kArray;
    w8a9230::TList m_kList;
    w8a9230::TStringMap m_kMap;
    FUN_00a414f0_NiTPrimitiveArray* m_pkExtra;
    bool m_bFlag;
    w8a9230::List3 m_kList2;
    int unk78;
    FUN_008a9230();
};
// pdb: NiControllerManager::NiControllerManager | NiControllerManager.obj | fnv360_0822_retail, caller_sim, medium
FUN_008a9230::FUN_008a9230()
    : m_kArray(0, 10), m_kMap(37, false), m_bFlag(false), unk78(0)
{
    m_pkExtra = new FUN_00a414f0_NiTPrimitiveArray;
}
