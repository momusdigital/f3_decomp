#include "f3_common.h"
// src/havok/common/visualize/process/hkinspectprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkinspectprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ddb2f0
// pdb: hkInspectProcess::getConsumableCommands | hkInspectProcess.obj | fnv360_0822_retail, vtable, medium
// pdb params: commands, numCommands
void __stdcall GetPunctuationChars(char** apOutString, int* apiLength)
{
    *apOutString = "!\"#$%";
    *apiLength = 5;
}

struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd4;

struct hkInspectProcess;

struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd4;

class hkRefObjDDB6
{
  public:
    virtual ~hkRefObjDDB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjDDB6() throw()
    {
        m_sReferenceCount = 1;
    }
};

class hkListenerDDB6
{
  public:
    virtual void onEvent() = 0;
    bool m_enabled;
    hkListenerDDB6() throw() : m_enabled(true)
    {}
};

class hkSourceDDB6
{
  public:
    int unk00;
    void* m_target;

    void FUN_00c90510() throw();
    void FUN_00cd13c0(void(__cdecl* callback)(void*), void* userData) throw();
};

struct hkSourceListDDB6
{
    hkSourceDDB6** m_data;
    int m_iElementCount;
};

template <typename T> struct hkArrayDDB6
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayDDB6() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00ddb600 : public hkRefObjDDB6, public hkListenerDDB6
{
  public:
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkArrayDDB6<void*> m_items;
    hkSourceDDB6* m_pObservedSource;

    FUN_00ddb600(const hkSourceListDDB6& sources) throw();
    virtual ~FUN_00ddb600() throw();
    virtual void onEvent();
};

// @f3 0x00a63380 (community match, verified in this file)
void __cdecl FUN_00a63350(void* userData);

struct hkSourceStandInDDB6
{
    int unk00;
    void* m_target;
    void FUN_009535d0(void(__cdecl* callback)(void*), void* userData) throw();
};

// pdb: hkInspectProcess::hkInspectProcess | hkInspectProcess.obj | fnv360_0822_retail, objrun, medium
// pdb params: contexts
FUN_00ddb600::FUN_00ddb600(const hkSourceListDDB6& sources) throw()
{
    m_pObservedSource = sources.m_iElementCount > 0 ? (hkSourceDDB6*)sources.m_data[0]->m_target : 0;
    if (m_pObservedSource)
    {
        hkRefObjDDB6* observed = (hkRefObjDDB6*)m_pObservedSource;
        if (observed->m_usMemSizeAndFlags != 0)
        {
            observed->m_sReferenceCount++;
        }
        ((hkSourceStandInDDB6*)m_pObservedSource)->FUN_009535d0(FUN_00a63350, this);
    }
}


namespace fnv_00ddb670 {
class hkMemoryAllocatorDDB6
{
  public:
    virtual ~hkMemoryAllocatorDDB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDDB6
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDDB6* m_pStreamAllocator;
    hkMemoryAllocatorDDB6& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDDB6& __cdecl FUN_00c85750();

template <class T> __forceinline void destructDDB6(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayDDB6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayDDB6() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructDDB6(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorDDB6& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void removeReference() throw();
};

class hkProcessDDB6
{
  public:
    virtual ~hkProcessDDB6() throw()
    {}
};

}  // namespace fnv_00ddb670

struct FnvCpu_FUN_00ddb710_CpuBlock;
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00ddb710_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00ddb710_CpuBlock* FUN_00ddb600(unsigned int value);
};

void* __cdecl FUN_00c85750();

class hkClass;
class hkStatisticsCollector;
class hkBool
{
    char value;

  public:
    operator bool() const
    {
        return value != 0;
    }
};
class hkClass
{
  public:
    hkBool GetLastNodeFlag() const;
};
class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector*, const hkClass*) const;
    unsigned short memSizeAndFlags;
    short referenceCount;
};
class hkVtableClassRegistry : public hkReferencedObject
{
  public:
    virtual void RegisterVtable(const void*, const hkClass*);
    virtual const hkClass* GetClassFromVirtualInstance(const void*) const;
};
class ProcessContext
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    hkVtableClassRegistry* registry;
};
class hkOArchive
{
  public:
    void hkOArchive_write32u(unsigned int);
    void hkOArchive_write8u(unsigned char);
    void hkOArchive_write64u(unsigned __int64);
};
struct hkInspectProcess
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkOArchive* archive;
    int unk18, unk1c, unk20, unk24, unk28;
    ProcessContext* context;
    int WriteObjectHeader(void*, const hkClass*, unsigned int);
};
// Writes a 25-byte object header to the archive, resolving the actual class via the vtable registry when available.
// @fnv 0x00ddb310
int hkInspectProcess::WriteObjectHeader(void* object, const hkClass* pClassInfo, unsigned int flags)
{
    archive->hkOArchive_write32u(25);
    const hkClass* pActualClass = pClassInfo;
    if (context->registry && pClassInfo->GetLastNodeFlag())
    {
        pActualClass = context->registry->GetClassFromVirtualInstance(object);
        if (!pActualClass)
            pActualClass = pClassInfo;
    }
    archive->hkOArchive_write8u(33);
    archive->hkOArchive_write64u(reinterpret_cast<unsigned int>(object));
    archive->hkOArchive_write64u(reinterpret_cast<unsigned int>(pActualClass));
    archive->hkOArchive_write64u(flags);
    return 25;
}

struct LayoutRulesDDB3
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126cae8;

class FUN_00d605d0_Class
{
  public:
    void hkOArchive_write32u(int iCommand);
    void hkOArchive_write8u(unsigned int uiValue);
    void hkOArchive_write64u(const GlobalObjectO2_00d472a0* pkClass, int iFlags);
};

struct TrackedObjectDDB3
{
    void* m_pvObject;
    int m_iType;
    int m_iFlags;
};

template <class T> struct hkArrayDDB3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

struct TrackedListDDB3
{
    int unk00[10];
    hkArrayDDB3<TrackedObjectDDB3> m_kTrackedObjects;
};

class ProcessBaseDDB3
{
  public:
    virtual void vfn_00();
    int unk04;
};

class ListenerDDB3
{
  public:
    virtual void WriteTrackedObjects();
};

class InspectProcessDDB3 : public ProcessBaseDDB3, public ListenerDDB3
{
  public:
    int unk0C;
    int unk10;
    FUN_00d605d0_Class* m_pDataStream;
    int unk18, unk1C, unk20, unk24, unk28;
    TrackedListDDB3* m_pkTracked;

    void WriteObjectHeader(void* pvObject, int iType, int iFlags);
    virtual void WriteTrackedObjects();
};

// Writes layout rules and each tracked object entry to m_pDataStream via hkOArchive_write32u, hkOArchive_write8u, hkOArchive_write64u, and WriteObjectHeader.
// @f3 0x00a63130 (community match, verified in this file)
namespace f3m_00a63130 {
struct ProcessHeaderWriter
{
    void WriteObjectHeader(void* pvObject, int iType);
};

extern const LayoutRulesDDB3 DAT_01061524;

struct Entry8DDB3
{
    void* m_pvObject;
    int m_iType;
};

struct TrackedListCast
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
    hkArrayDDB3<Entry8DDB3> m_kTrackedObjects;
};

}

// pdb: hkInspectProcess::init | hkInspectProcess.obj | fnv360_0822_retail, vtable, medium
void InspectProcessDDB3::WriteTrackedObjects()
{
    if (!m_pkTracked)
        return;
    m_pDataStream->hkOArchive_write32u(0xd);
    m_pDataStream->hkOArchive_write8u(0x20);
    m_pDataStream->hkOArchive_write64u(&g_0126cae8, 0);
    m_pDataStream->hkOArchive_write8u(f3m_00a63130::DAT_01061524.m_ucBytesInPointer);
    m_pDataStream->hkOArchive_write8u(f3m_00a63130::DAT_01061524.m_bLittleEndian);
    m_pDataStream->hkOArchive_write8u(f3m_00a63130::DAT_01061524.m_bReusePaddingOptimization);
    m_pDataStream->hkOArchive_write8u(f3m_00a63130::DAT_01061524.m_bEmptyBaseClassOptimization);
    hkArrayDDB3<f3m_00a63130::Entry8DDB3>& kObjects = ((f3m_00a63130::TrackedListCast*)m_pkTracked)->m_kTrackedObjects;
    for (int i = 0; i < kObjects.GetLogicalSize(); i++)
    {
        f3m_00a63130::Entry8DDB3& kEntry = kObjects[i];
        reinterpret_cast<f3m_00a63130::ProcessHeaderWriter*>(static_cast<ProcessBaseDDB3*>(this))->WriteObjectHeader(kEntry.m_pvObject, kEntry.m_iType);
    }
}


namespace fnv_00ddb550 {
class FUN_00d605d0_Class
{
  public:
    void hkOArchive_write32u(int iFlags);
    void hkOArchive_write8u(unsigned int uiFlags);
    void hkOArchive_write64u(int iKey, int iValue);
};

template <typename T> struct hkArrayDDB5
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            unsigned int* src = reinterpret_cast<unsigned int*>(m_data + m_iElementCount);
            unsigned int* dst = reinterpret_cast<unsigned int*>(m_data + index);
            int k = 0;
            do
            {
                dst[k] = src[k];
            } while (++k < (int)(sizeof(T) / 4));
        }
    }
};

}  // namespace fnv_00ddb550

struct hkMemoryAllocatorQ
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorQ* m_pStreamAllocator;
    hkMemoryAllocatorQ& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(hkMemoryAllocatorQ* alloc, void* array, int sizeElem) throw();

template <typename T> struct hkArrQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrQ() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrQ()
    {
        ClearAndRelease();
    }

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    void _clearAndDeallocate(hkMemoryAllocatorQ& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void ClearAndRelease()
    {
        _clearAndDeallocate(static_cast<hkMemoryRouterQ*>(FUN_00c85750())->heap());
    }

    void _pushBack(hkMemoryAllocatorQ& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        T* p = m_data + m_iElementCount;
        m_iElementCount++;
        *p = t;
    }
    void AddBack(const T& t)
    {
        _pushBack(static_cast<hkMemoryRouterQ*>(FUN_00c85750())->heap(), t);
    }
};

class hkBoolQ
{
  public:
    char m_cBooleanValue;
    hkBoolQ(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkClassQ
{
    hkBoolQ hasVtable() const throw();
};

struct hkVtableClassRegistryQ
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual const hkClassQ* GetClassFromVirtualInstance(const void* obj) const throw();
};

struct hkInspectContextQ
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
    hkVtableClassRegistryQ* m_vtableRegistry;
};

struct hkLayoutRulesQ
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

extern hkLayoutRulesQ DAT_010d6ae8;

struct hkStructureLayoutQ
{
    hkLayoutRulesQ m_kLayoutRules;
    hkStructureLayoutQ(const hkLayoutRulesQ& rules) throw();
};

struct hkArrayStreamWriterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkArrayStreamWriterQ(hkArrQ<char>* arr, int ownerShip) throw();
    ~hkArrayStreamWriterQ() throw();
};

struct hkObjectPatchQ
{
    int unk00;
    int unk04;
    const void* m_object;
    int unk0C;
    const hkClassQ* m_class;
    int unk14;
};

struct hkWrittenObjectQ
{
    const void* m_object;
    const hkClassQ* m_class;
};

struct hkDisplayOStreamQ
{
    void hkOArchive_write32u(int size) throw();
    void hkOArchive_write8u(unsigned int cmd) throw();
    void FUN_00d607b0(const char* data, int size) throw();
};

int __cdecl FUN_00e0bd40(hkArrayStreamWriterQ* writer, hkStructureLayoutQ* layout, const void* object, int flags,
                         const void* original, const hkClassQ* pClassInfo, hkArrQ<hkObjectPatchQ>* patches) throw();

struct hkInspectProcessQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkDisplayOStreamQ* m_pDisplayStream;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    hkInspectContextQ* m_iValueAtOffset0C;

    // Calls FUN_00ddb770 with the given object, class, true, and written array.
// @fnv 0x00ddb770
    __forceinline int sendRecursiveQ(const void* apObject, const hkClassQ* apClass,
                                     hkArrQ<hkWrittenObjectQ>* apWrittenObjects) throw()
    {
        return FUN_00ddb770(apObject, apClass, true, apWrittenObjects);
    }
    int FUN_00ddb770(const void* object, const hkClassQ* pClassInfo, hkBoolQ recurse,
                     hkArrQ<hkWrittenObjectQ>* written) throw();
};

int hkInspectProcessQ::FUN_00ddb770(const void* object, const hkClassQ* pClassInfo, hkBoolQ recurse,
                                    hkArrQ<hkWrittenObjectQ>* written) throw()
{
    hkStructureLayoutQ layout(DAT_010d6ae8);
    hkArrQ<hkObjectPatchQ> patches;

    const hkClassQ* realClass = pClassInfo;
    if (m_iValueAtOffset0C->m_vtableRegistry && pClassInfo->hasVtable())
    {
        realClass = m_iValueAtOffset0C->m_vtableRegistry->GetClassFromVirtualInstance(object);
        if (!realClass)
        {
            realClass = pClassInfo;
        }
    }

    if (recurse)
    {
        int i;
        for (i = 0; i < written->GetLogicalSize(); i++)
        {
            if ((*written)[i].m_object == object)
            {
                break;
            }
        }
        if (i < written->GetLogicalSize())
        {
            return 0;
        }
        hkWrittenObjectQ w;
        w.m_object = object;
        w.m_class = realClass;
        written->AddBack(w);
    }

    hkArrQ<char> buffer;
    hkArrayStreamWriterQ writer(&buffer, 1);
    int size = FUN_00e0bd40(&writer, &layout, object, 0, object, realClass, &patches);
    if (size != buffer.GetLogicalSize() || size < 1)
    {
        return -1;
    }

    int total = size + 1;
    m_pDisplayStream->hkOArchive_write32u(total);
    m_pDisplayStream->hkOArchive_write8u(0x24);
    m_pDisplayStream->FUN_00d607b0(buffer.m_data, buffer.GetLogicalSize());
    if (recurse)
    {
        for (int i = 0; i < patches.GetLogicalSize(); i++)
        {
            const void* obj = patches[i].m_object;
            const hkClassQ* cls = patches[i].m_class;
            total += sendRecursiveQ(obj, cls, written);
        }
    }
    return total;
}

// sub ecx,8; jmp FUN_00ddbed0 == MSVC adjustor thunk for a secondary base vtable slot.
struct PrimaryBase
{
    virtual void FUN_00ddbec0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddbec0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ddbec0
    virtual void FUN_00ddbec0();
};

Derived::Derived()
{}

namespace fnv_00ddb450 {
struct hkClass;
struct hkClassMember
{
    const char* unk00;
    const hkClass* unk04;
    const void* unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    int __thiscall GetTagValue() const;
    const hkClass* __thiscall FUN_00d86910() const;
};
struct hkClass
{
    const hkClassMember& __thiscall FUN_00d46f20(int i) const;
};

}  // namespace fnv_00ddb450
