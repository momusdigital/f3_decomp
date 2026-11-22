#include "f3_common.h"
// src/havok/common/serialize/version/hkversionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl VisitObjectList(int, int);

struct FUN_00db7a80_Class
{
    int __pad0;
    int __pad1;
    int __pad2;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void EnsureInitialized();
};

// @fnv 0x00db7a80
// pdb: hkStaticClassNameRegistry::checkIfReady | hkStaticClassNameRegistry.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void FUN_00db7a80_Class::EnsureInitialized()
{
    if (!m_iFourthElementInteger)
    {
        VisitObjectList(m_kPointB, m_iThirdValue);
        m_iFourthElementInteger = 1;
    }
}

extern "C" char str_010cf830[];

// @fnv 0x00dc0fb0
void* __cdecl FUN_00dc0fb0()
{
    return &str_010cf830;
}

struct FUN_00d86980_Class
{
    int FUN_00d86980();
};

struct FUN_00d871a0
{
    int m_00;
    int m_04;

    FUN_00d871a0(void*, int);
    bool& FUN_00d871e0(bool&);
    void* FUN_00d871f0();
    FUN_00d86980_Class* FUN_00d87370();
};

extern "C" void* __cdecl FUN_00cb1260(void*, const void*, unsigned int);

// @fnv 0x00dc0fc0
// pdb: hkVersionUtil::renameMember | hkVersionUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: oldObj, oldName, newObj, newName
void __cdecl FUN_00dc0fc0(void* a1, int a2, void* a3, int a4)
{
    FUN_00d871a0 obj1(a1, a2);
    FUN_00d871a0 obj2(a3, a4);
    bool b;
    if (obj1.FUN_00d871e0(b) && obj2.FUN_00d871e0(b))
    {
        FUN_00cb1260(obj2.FUN_00d871f0(), obj1.FUN_00d871f0(), obj2.FUN_00d87370()->FUN_00d86980());
    }
}

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() const throw();
};

class hkClassMemberDC11
{
  public:
    enum Type
    {
        TYPE_POINTER = 0x14,
        TYPE_ARRAY = 0x16,
        TYPE_STRUCT = 0x19,
        TYPE_SIMPLEARRAY = 0x1a,
        TYPE_VARIANT = 0x1c,
        TYPE_CSTRING = 0x1d,
        TYPE_STRINGPTR = 0x21
    };

    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;

    int FUN_00d86920() const throw();
    const FUN_00d46d40_s& FUN_00d86910() const throw();
};

class hkMemoryAllocatorDC12;

struct hkMemoryRouterDC12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC12* m_pStreamAllocator;
    hkMemoryAllocatorDC12& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC12& __cdecl FUN_00c85750();

void __cdecl ProcessObjectArray(void* const* ppvList, int iFlags) throw();

class hkPointerMapDC12
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkPointerMapDC12() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~hkPointerMapDC12() throw()
    {
        FUN_00a29680();
    }

    void EnsureCapacity(hkMemoryAllocatorDC12& kAlloc, int iNumElems) throw();
    void ProcessArgument(hkMemoryAllocatorDC12& kAlloc) throw();
    void FUN_00a29680() throw();
};

class hkVisitorDC12
{
  public:
    int unk00;

    hkVisitorDC12() throw()
    {
        FUN_00dc1670();
    }
    void FUN_00dc1670() throw();
    void hkStructureLayout_computeMemberOffsetsInplace(void* pvObject, hkPointerMapDC12& kDone, int iFlags) throw();
};

// @f3 0x0093e5f0 (community match, verified in this file)
struct StubPMDC12 {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00922cb0();
    void FUN_00922cf0();
};

struct StubVisitDC12 {
    int unk00;
    void FUN_009b2530();
    void FUN_009b2a50(void* pvObject, StubPMDC12& kDone);
};

// pdb: hkVersionUtil::recomputeClassMemberOffsets | hkVersionUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: classes, classVersion
extern "C" void __cdecl FUN_00dc1230(int apvList, int iFlags)
{
    void* const* ppvList = reinterpret_cast<void* const*>(apvList);
    ProcessObjectArray(ppvList, iFlags);
    StubVisitDC12 kVisitor;
    StubPMDC12 kDone;
    kVisitor.FUN_009b2530();
    kDone.FUN_00922cb0();
    for (int i = 0; ppvList[i]; i++)
        kVisitor.FUN_009b2a50(ppvList[i], kDone);
    kDone.FUN_00922cf0();
}


class hkBoolDC10
{
  public:
    hkBoolDC10(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

class FUN_00d27520
{
  public:
    void FUN_00d27520_dtor() throw();
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    char m_overflowed;
};

class FUN_00d274c0 : public FUN_00d27520
{
  public:
    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, hkBoolDC10 bMemoryIsString) throw();
    int FUN_00d27380(int offset, int whence) throw();
};

struct EntryDC10
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short m_offset;
};

class SetDC10
{
  public:
    int FUN_00d46fe0(int key) throw();
};

class SectionsDC10
{
  public:
    int FUN_00d470d0() throw();
    int hkClass_getNumMembers() throw();
    EntryDC10* FUN_00d46f20(int i) throw();
    void InvokeTarget(int i, FUN_00d27520* pkWriter) throw();
};

// Writes entries from pkSections whose key is not in pkSet to pvBuf via a FUN_00d274c0 writer.
// @fnv 0x00dc1070
// pdb: hkVersionUtil::copyDefaults | hkVersionUtil.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
void __cdecl hkVersionUtil_copyDefaults(void* apvBuffer, SetDC10* pkSet, SectionsDC10* pkSections)
{
    FUN_00d274c0 kWriter(apvBuffer, pkSections->FUN_00d470d0(), false);
    for (int i = 0; i < pkSections->hkClass_getNumMembers(); i++)
    {
        EntryDC10* pkEntry = pkSections->FUN_00d46f20(i);
        int key = pkEntry->m_key;
        if (!pkSet->FUN_00d46fe0(key))
        {
            int iOffset = pkEntry->m_offset;
            kWriter.FUN_00d27380(iOffset, 0);
            pkSections->InvokeTarget(i, &kWriter);
        }
    }
    kWriter.FUN_00d27520_dtor();
}

struct S00dc15a0_Buffer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int* indices, unsigned int size);
};

struct S00dc15a0_AudioSystem
{
    int unk00;
    int unk04;
    int unk08;
    S00dc15a0_Buffer* unk0C;
};

namespace fnvc_adapt {
extern "C" S00dc15a0_AudioSystem* __cdecl FUN_00c85750();
}

struct hkFlagsDC10
{
    int m_kStorage;
    hkFlagsDC10(int i) : m_kStorage(i)
    {}
};

namespace FUN_00e03120 {
}

namespace FUN_00dc1040 {

}
