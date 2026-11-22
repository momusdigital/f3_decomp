#include "f3_common.h"
// src/havok/common/visualize/hkvisualdebugger.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkvisualdebugger.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cd12b0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    unsigned int* m_10;
    int m_14;
    void RemovePair(int);
    void FUN_00cd12b0();
};

// Scans the entries from the last index down to 0 and calls RemovePair for each entry whose first word is zero.
// @f3 0x00953520 (community match, verified in this file)
void FUN_00cd12b0_cls::FUN_00cd12b0() {
    for (int index = (int)m_10 - 1; index >= 0; --index)
        if (!((unsigned int*)m_iThirdValue)[index * 2])
            RemovePair(index);
}


struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
    BSFadeNode();
    ~BSFadeNode();
};
struct FUN_00ccf890_t : BSFadeNode
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00ccf890_t();
    ~FUN_00ccf890_t();
};
// Allocates and constructs a FUN_00ccf890_t object and returns it as a BSFadeNode pointer.
// @fnv 0x00ccf890
// pdb: bhkConvexListShape::CreateClone | bhkConvexListShape.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: bhkConvexListShape::CreateObject)
// pdb params: arCloneData
BSFadeNode* FUN_00ccf890()
{
    return new FUN_00ccf890_t;
}

class hkVisualDebugger;

struct hkVisualDebugger
{
    unsigned int m_iWordAt00;
    unsigned short m_iWordAt04;

    void FUN_00cd1970();
    hkVisualDebugger* FUN_00cd1e40(unsigned int flags);
};

struct hkErrorCD0D
{
    virtual ~hkErrorCD0D();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorCD0D* DAT_01268360;

struct hkSocketCD0D
{
    virtual ~hkSocketCD0D();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int listen(int iPort);
};
extern hkSocketCD0D*(__cdecl* DAT_011b3df0)();

struct hkOstreamCD0D
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamCD0D& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamCD0D& WriteInt(int iValue) throw();
};

struct FUN_00cb1600 : hkOstreamCD0D
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};

struct hkVisualDebuggerCD0D : hkVisualDebugger
{
    hkSocketCD0D* m_pkServer;
    void CreateServer(int iListenPort);
};

// Creates the debugger's socket server if absent, listens on iListenPort, and reports the outcome via DAT_01268360->message.
// @f3 0x00952f70 (community match, verified in this file)
// pdb: hkVisualDebugger::serve | hkVisualDebugger.obj | fnv360_0822_retail, ustr, medium
// pdb params: listenPort
void hkVisualDebuggerCD0D::CreateServer(int iListenPort)
{
    DAT_01268360->BeginSection(0x1293ade8, "Serving");
    if (!m_pkServer)
    {
        m_pkServer = DAT_011b3df0();
        if (m_pkServer)
        {
            m_pkServer->listen(iListenPort);
            unsigned int auiReportBuf[0x80];
            FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
            kReportStream.FUN_00cc01c0("Server created and will poll for new client(s) on port ")
                .WriteInt(iListenPort)
                .FUN_00cc01c0(" every frame");
            DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 107);
            kReportStream.FUN_00cc00e0();
        }
        else
        {
            unsigned int auiReportBuf[0x80];
            FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
            kReportStream.FUN_00cc01c0(
                "Server could not be created, please check that you platform supports sockets with the hkBase library");
            DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 111);
            kReportStream.FUN_00cc00e0();
        }
    }
    else
    {
        unsigned int auiReportBuf[0x80];
        FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
        kReportStream.FUN_00cc01c0(
            "Server has already been created, only one server allowed per visual debugger instance");
        DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 116);
        kReportStream.FUN_00cc00e0();
    }
    DAT_01268360->EndSection();
}


class hkStateCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool isActive();
};

class hkTargetCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void activate();
};

class hkControllerCD0E
{
  public:
    void hkOArchive_write32u(int mode);
    void hkOArchive_write8u(unsigned int flags);
    void hkOArchive_writeFloat32(float t);
    hkTargetCD0E* FUN_00d60800();
};

class hkItemCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStateCD0E m_uiContentCount;
    int unk10;
    int unk14;
    hkControllerCD0E* m_controller;
};

struct hkEntryCD0E
{
    int m_key;
    hkItemCD0E* m_item;
};

class hkOwnerCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkEntryCD0E* m_entries;

    void hkVisualDebugger_writeStep(int i, float t);
};

// @f3 0x009530f0 (community match, verified in this file)
class NativeOwner1480
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkEntryCD0E* m_entries;

};

struct hkCtrlStub
{
    void FUN_009ee8f0(int mode);
    void FUN_009ee560(unsigned int flags);
    void hkOArchive_writeFloat32(float t);
    hkTargetCD0E* FUN_009ee790();
};

// pdb: hkVisualDebugger::writeStep | hkVisualDebugger.obj | fnv360_0822_retail, call_seq, high
// pdb params: i, t
// pdb: hkVisualDebugger::writeStep | hkVisualDebugger.obj | fnv360_0822_retail, call_seq, high (was: ActivateEntry)
void hkOwnerCD0E::hkVisualDebugger_writeStep(int aiIndex, float t)
{
    hkEntryCD0E& e = reinterpret_cast<NativeOwner1480*>(this)->m_entries[aiIndex];
    if (e.m_item->m_uiContentCount.isActive())
    {
        hkCtrlStub* c = reinterpret_cast<hkCtrlStub*>(e.m_item->m_controller);
        c->FUN_009ee8f0(5);
        c->FUN_009ee560(0);
        c->hkOArchive_writeFloat32(t);
        c->FUN_009ee790()->activate();
    }
}


template <class T> class hkArrayCD11
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            m_data[iIndex] = m_data[m_iElementCount];
    }
};

class hkpEntityCD11;

class hkpEntityTrackerCD11
{
  public:
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
    hkArrayCD11<hkpEntityCD11*> m_kActorEntries;
    hkArrayCD11<void*> m_entityData;

    void FUN_00cd1140(hkpEntityCD11* pkEntity);
};

// Finds pkEntity in the entity array and, if present, removes it and the matching entry from m_entityData.
// @f3 0x009533c0 (community match, verified in this file)
namespace Task1561 {struct View {int padding[12];hkArrayCD11<hkpEntityCD11*> entries;hkArrayCD11<void*> details;};}
// pdb: hkVisualDebugger::removeTrackedObjectCallback | hkVisualDebugger.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: callback
void hkpEntityTrackerCD11::FUN_00cd1140(hkpEntityCD11* entity){
 Task1561::View* self=(Task1561::View*)this;
 int i=self->entries.indexOf(entity);
 if(i>=0){
  self->entries.m_iElementCount--;
  self->entries.m_data[i]=self->entries.m_data[self->entries.m_iElementCount];
  self->details.m_iElementCount--;
  self->details.m_data[i]=self->details.m_data[self->details.m_iElementCount];
 }
}


namespace fnv_00cd11a0 {
struct hkErrorCD11
{
    virtual ~hkErrorCD11();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorCD11* DAT_01268360;

struct hkSocketCD11
{
    virtual ~hkSocketCD11();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int listen(int iPort);
};
extern hkSocketCD11*(__cdecl* DAT_011b3df0)();

struct hkOstreamCD11
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamCD11& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamCD11& WriteInt(int iValue) throw();
};

struct FUN_00cb1600 : hkOstreamCD11
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};

}  // namespace fnv_00cd11a0

struct FUN_00cd12e0_element
{
    unsigned int value;
    void FUN_00cb0a60();
    void FUN_00cb0c10();
};
struct FUN_00cd12e0_array
{
    FUN_00cd12e0_element* data;
    unsigned int size;
    unsigned int capacityFlags;
};
struct FUN_00cd12e0_router
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    void* heap;
};
FUN_00cd12e0_router* FUN_00c85750();
void __cdecl ResizeAudioStream(void*, FUN_00cd12e0_array*, int);

namespace fnv_00cd1330 {
void* FUN_00c85750();
void ResizeAudioStream(void*, void*, int);

struct Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T& AllocatePair()
    {
        void* heap = ((Router*)FUN_00c85750())->m_10;
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ResizeAudioStream(heap, this, sizeof(T));
        }
        return m_data[m_iElementCount++];
    }

    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBool
{
  public:
    inline hkBool()
    {}
    inline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }

  private:
    char m_cBooleanValue;
};

typedef void (*CallbackFn)(int, int, hkBool, int, void*);

}  // namespace fnv_00cd1330

template <int SIZE> __forceinline void memCpyOneAlignedXcd13c0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXcd13c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXcd13c0 {
extern "C" hkMemoryRouterXcd13c0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXcd13c0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXcd13c0& router = hkRouterXcd13c0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXcd13c0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkMemoryAllocatorCD17;

struct hkMemoryRouterCD17
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCD17* m_pStreamAllocator;
    hkMemoryAllocatorCD17& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterCD17& __cdecl FUN_00c85750() throw();
}

class hkMemoryAllocatorC19
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterC19
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC19* m_pTemp;
    hkMemoryAllocatorC19* m_pStreamAllocator;
    hkMemoryAllocatorC19& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterC19& __cdecl GetMemoryRouterC19() throw();

template <typename T> __forceinline void DestructC19(T* pArr, int n) throw()
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}

template <typename T> struct hkArrayC19
{
    __forceinline ~hkArrayC19() throw()
    {
        hkMemoryAllocatorC19& kAlloc = GetMemoryRouterC19().heap();
        DestructC19(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void clear() throw()
    {
        DestructC19(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkStringPtrC19
{
  public:
    ~hkStringPtrC19() throw();
    const char* m_pcText;
};

class hkReferencedObjectC19
{
  public:
    virtual ~hkReferencedObjectC19() throw()
    {}
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkVisualDebuggerC19;
class hkProcessContextC19
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void SetOwnerPointer(hkVisualDebuggerC19* pkOwner) throw();
};

struct hkVisualDebuggerClientC19
{
    void* m_pSocket;
    void* m_pProcessHandler;
};
struct hkVisualDebuggerTrackedObjectC19
{
    void* m_ptr;
    void* m_class;
    unsigned int m_ucOperationType;
};

class FUN_00cd1970 : public hkReferencedObjectC19
{
  public:
    virtual ~FUN_00cd1970() throw();
    void shutdown() throw();

    void* m_pServer;
    unsigned int unk0c;
    hkArrayC19<hkVisualDebuggerClientC19> m_kClients;
    hkArrayC19<hkProcessContextC19*> m_kProcessContexts;
    hkArrayC19<hkVisualDebuggerTrackedObjectC19> m_kTrackedObjects;
    hkArrayC19<void*> m_kTrackCallbacks;
    hkArrayC19<void*> m_kTrackCallbackHandles;
    hkReferencedObjectC19* m_pReferencedObject;
    hkArrayC19<hkStringPtrC19> m_defaultViewers;
};

// Destroys the visual debugger server by shutting it down, detaching process contexts, clearing default viewers, and releasing the referenced object.
// @fnv 0x00cd1970
FUN_00cd1970::~FUN_00cd1970() throw()
{
    shutdown();
    for (int i = 0; i < m_kProcessContexts.GetLogicalSize(); i++)
    {
        m_kProcessContexts[i]->SetOwnerPointer(0);
    }
    m_defaultViewers.clear();
    if (m_pReferencedObject)
    {
        m_pReferencedObject->removeReference();
    }
}

class hkMemoryAllocatorCD1
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCD1
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorCD1* m_pTemp;
    hkMemoryAllocatorCD1* m_pStreamAllocator;
    hkMemoryAllocatorCD1& temp()
    {
        return *m_pTemp;
    }
};
hkMemoryRouterCD1& __cdecl GetMemoryRouterCD1() throw();

class hkOstreamCD1
{
  public:
    hkOstreamCD1(void* pvBuffer, int iSize) throw();
    ~hkOstreamCD1() throw();
    hkOstreamCD1& operator<<(const char* pcString) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};

class hkStringBufCD1
{
  public:
    hkStringBufCD1() throw();
    __forceinline ~hkStringBufCD1() throw()
    {
        hkMemoryAllocatorCD1& kAlloc = GetMemoryRouterCD1().temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
    }
    hkStringBufCD1& operator=(const char* pcString) throw();
    hkStringBufCD1& operator+=(const char* pcString) throw();
    hkStringBufCD1& appendJoin(const char* a, const char* b = 0, const char* c = 0, const char* d = 0,
                               const char* e = 0, const char* f = 0) throw();
    const char* cString() const
    {
        return m_data;
    }
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[32];
};

class hkBoolCD1
{
  public:
    hkBoolCD1(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkStreamWriterCD1
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkBoolCD1 IsStreamValid() const throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkProcessHandlerCD1
{
  public:
    virtual void v00();
    virtual void v04();
    virtual int getProcessId(const char* pcName) throw();
    virtual void v0c();
    virtual void v10();
    virtual void selectProcess(int aiAllocationTag) throw();
};
class hkServerProcessHandlerCD1
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkProcessHandlerCD1 m_kProcessHandler;
    int getProcessId(const char* pcName) throw()
    {
        return m_kProcessHandler.getProcessId(pcName);
    }
    void selectProcess(int aiAllocationTag) throw()
    {
        m_kProcessHandler.selectProcess(aiAllocationTag);
    }
};

struct hkVisualDebuggerClientCD1
{
    void* m_pSocket;
    hkServerProcessHandlerCD1* m_pProcessHandler;
};

struct hkStringPtrCD1
{
    const char* cString() const
    {
        return reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(m_pcText) & ~1);
    }
    const char* m_pcText;
};

template <typename T> struct hkArrayCD1
{
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkVisualDebuggerCD1
{
  public:
    virtual void v00();
    void CaptureSimulationState(const char* pcCaptureFilename) throw();
    void AddClient(void* pkSocket, void* pkReader, hkStreamWriterCD1* pkWriter) throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int unk08;
    unsigned int unk0c;
    hkArrayCD1<hkVisualDebuggerClientCD1> m_kClients;
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
    hkArrayCD1<hkStringPtrCD1> m_defaultViewers;
};

// Opens a file writer for pcCaptureFilename, adds it as a client, selects default viewers, and logs the capture status via g_pkErrorCD1.
// @f3 0x00953e70 (community match, verified in this file)
namespace f3m_00953e70 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
struct Heap953 { void* FUN_008f6d30(int,int); void FUN_008f6d90(void*,int,int); };
void __cdecl FUN_00901e90(void*,int,int);
int __cdecl FUN_009233f0(const char*);
void __cdecl FUN_009234e0(void*,const void*,int);
struct String953 {
    char* data;
    int size, capacity;
    String953();
    String953(const char*);
    ~String953();
    void setLen(int n) {
        int cap = capacity & 0x3fffffff;
        if (cap < n) {
            int grow = cap * 2;
            FUN_00901e90(this, n < grow ? grow : n, 1);
        }
        size = n;
    }
    void assign(const char*);
    String953& operator=(const char*);
    String953& FUN_00923830(const String953&);
    String953& FUN_00923890(const char*);
    String953 FUN_00923bb0(const String953&) const;
};
struct Stream953 {
    unsigned int a, b, c;
    Stream953(void* p, int n) { FUN_00923070(p, n); }
    void FUN_00923070(void*, int);
    Stream953& FUN_00943710(const char*);
    void FUN_00943a60();
};
struct Error953 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Message(int, int, const char*, const char*, int);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Begin(int, const char*);
    virtual void End();
};
struct Bool953 { char v; };
struct Writer953 {
    virtual void Destroy(int);
    virtual void v04();
    virtual void v08();
    virtual Bool953 Valid();
    unsigned short flags;
    short refs;
    void release() {
        if (flags) {
            if (--refs == 0) Destroy(1);
        }
    }
};
struct FS953 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Writer953* Open(const char*);
};
struct Handler953 {
    virtual void v00();
    virtual void v04();
    virtual int Id(const char*);
    virtual void v0c();
    virtual void v10();
    virtual void Select(int);
};
struct Process953 { unsigned int a, b; Handler953 handler; };
struct Client953 { void* socket; Process953* process; };

__forceinline String953::String953() {
    Heap953* heap = static_cast<Heap953*>(DAT_00d9b080(DAT_010f3170));
    data = static_cast<char*>(heap->FUN_008f6d30(1, 0x17));
    capacity = size = 1;
    data[0] = 0;
}
__forceinline String953::String953(const char* s) {
    data = 0;
    size = 0;
    capacity = 0x80000000;
    assign(s);
}
__forceinline String953::~String953() {
    if ((capacity & 0x80000000) == 0) {
        int n = capacity & 0x3fffffff;
        Heap953* heap = static_cast<Heap953*>(DAT_00d9b080(DAT_010f3170));
        heap->FUN_008f6d90(data, n, 0x17);
    }
}
__forceinline void String953::assign(const char* s) {
    int n = FUN_009233f0(s) + 1;
    int cap = capacity & 0x3fffffff;
    if (cap < n) {
        int grow = cap * 2;
        FUN_00901e90(this, n < grow ? grow : n, 1);
    }
    size = n;
    FUN_009234e0(data, s, n);
}
__forceinline String953& String953::operator=(const char* s) {
    int len = FUN_009233f0(s);
    setLen(len + 1);
    FUN_009234e0(data, s, len + 1);
    return *this;
}
__forceinline void join953(String953& out, const char* prefix, String953* const& name) {
    out.FUN_00923830(String953(prefix).FUN_00923bb0(*name));
}

struct Self953 {
    void* vtbl;
    unsigned short flags;
    short refs;
    unsigned int unk08;
    Client953* clients;
    int count;
    int cap;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    String953** viewers;
    int viewerCount;
    int viewerCapacity;
    void FUN_00953680(void*, void*, Writer953*);
};
namespace G953 {
extern Error953* DAT_010f3364;
extern FS953* DAT_010f3368;
extern const char DAT_00e7bee4[], DAT_00dfa640[], DAT_00e7bec4[], DAT_00e7bb74[], DAT_00e7bea0[], DAT_00dc0cd8[], DAT_00dfa6f0[], DAT_00e7be7c[], DAT_00e7be6c[];
}
}

// pdb: hkVisualDebugger::capture | hkVisualDebugger.obj | fnv360_0822_retail, ustr, medium
// pdb params: captureFilename
void hkVisualDebuggerCD1::CaptureSimulationState(const char* filename) throw() {
    using namespace f3m_00953e70;
    Self953* self = reinterpret_cast<Self953*>(this);
    G953::DAT_010f3364->Begin(0x1293ade7, G953::DAT_00e7bee4);
    Writer953* w = G953::DAT_010f3368->Open(filename);
    if (w && w->Valid().v) {
        {
            unsigned int reportBuf[128];
            Stream953 ostr(reportBuf, sizeof(reportBuf));
            ostr.FUN_00943710(G953::DAT_00e7bec4).FUN_00943710(filename).FUN_00943710(G953::DAT_00dfa640);
            G953::DAT_010f3364->Message(0, -1, reinterpret_cast<const char*>(reportBuf), G953::DAT_00e7bb74, 129);
            ostr.FUN_00943a60();
        }
        self->FUN_00953680(0, 0, w);
        w->release();
        Client953& client = self->clients[self->count - 1];
        String953 names;
        names = G953::DAT_00e7bea0;
        for (int i = 0; i < self->viewerCount; i++) {
            const char* text = self->viewers[i]->data;
            int id = client.process->handler.Id(text);
            if (id >= 0) {
                join953(names, G953::DAT_00dc0cd8, self->viewers[i]);
                client.process->handler.Select(id);
            }
        }
        names.FUN_00923890(G953::DAT_00dfa6f0);
        {
            unsigned int reportBuf[128];
            Stream953 ostr(reportBuf, sizeof(reportBuf));
            ostr.FUN_00943710(names.data);
            G953::DAT_010f3364->Message(0, -1, reinterpret_cast<const char*>(reportBuf), G953::DAT_00e7bb74, 151);
            ostr.FUN_00943a60();
        }
    } else {
        unsigned int reportBuf[128];
        Stream953 ostr(reportBuf, sizeof(reportBuf));
        ostr.FUN_00943710(G953::DAT_00e7be6c).FUN_00943710(filename).FUN_00943710(G953::DAT_00e7be7c);
        G953::DAT_010f3364->Message(0, -1, reinterpret_cast<const char*>(reportBuf), G953::DAT_00e7bb74, 155);
        ostr.FUN_00943a60();
    }
    G953::DAT_010f3364->End();
}


struct hkReferencedObject_cd0e
{
    void removeReference();
};

struct Pair_cd0e
{
    hkReferencedObject_cd0e* m_kPointA;
    hkReferencedObject_cd0e* m_kPointB;
};

inline void memCpy4_cd0e(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_cd0e
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_cd0e(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Owner_cd0e
{
    int unk00, unk04, unk08, unk0C;
    hkArray_cd0e<Pair_cd0e> m_pairs;
    void RemovePair(int index);
};

// Releases both nonnull references in the indexed pair, then removes that array entry.
// @fnv 0x00cd0e60
void Owner_cd0e::RemovePair(int index)
{
    Pair_cd0e& pair = m_pairs[index];
    if (pair.m_kPointB)
        pair.m_kPointB->removeReference();
    if (pair.m_kPointA)
        pair.m_kPointA->removeReference();
    m_pairs.removeAt(index);
}

struct hkBool836
{
    bool value;
    hkBool836(bool b) : value(b)
    {}
    hkBool836(const hkBool836& b) : value(b.value)
    {}
};
struct Tracked836
{
    void* object;
    const void* pClassInfo;
    unsigned long tag;
};
typedef void(__cdecl* Callback836)(void*, const void*, hkBool836, unsigned long, void*);

inline void memCpy4_836(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray836
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_836(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Debugger836
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    hkArray836<Tracked836> m_tracked;
    hkArray836<Callback836> m_kCallbackFunctions;
    hkArray836<void*> m_callbackData;
    void UntrackObject(void* object);
};

// Removes object from m_tracked and invokes each callback in m_kCallbackFunctions with a false hkBool836 flag.
// @f3 0x00953330 (community match, verified in this file)
typedef void (__cdecl *F3Callback)(void*,unsigned long,hkBool836,void*);
struct TrackedStd836
{
    void* object;
    unsigned long tag;
};
struct DebuggerStd836
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    hkArray836<TrackedStd836> m_tracked;
    hkArray836<F3Callback> m_kCallbackFunctions;
    hkArray836<void*> m_callbackData;
};
// pdb: hkVisualDebugger::removeTrackedObject | hkVisualDebugger.obj | fnv360_0822_retail, call_seq, medium
// pdb params: obj
void Debugger836::UntrackObject(void* object)
{
    DebuggerStd836* self = reinterpret_cast<DebuggerStd836*>(this);
    int i=0;
    if(self->m_tracked.GetLogicalSize()<=0) return;
    TrackedStd836* cursor=self->m_tracked.m_data;
    for (; i < self->m_tracked.GetLogicalSize(); i++,cursor++)
    {
        if (cursor->object == object)
        {
            (*(volatile int*)&self->m_tracked.m_iElementCount)--;
            int last=self->m_tracked.m_iElementCount;
            self->m_tracked[i] = self->m_tracked[last];
            for (int j = 0; j < self->m_kCallbackFunctions.GetLogicalSize(); j++)
                self->m_kCallbackFunctions[j](object, 0, hkBool836(false), self->m_callbackData[j]);
            return;
        }
    }
}


struct Heap_cd14
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int nbytes) throw();
};
struct Router_cd14
{
    int unk00, unk04, unk08, unk0C;
    Heap_cd14* m_pStreamAllocator;
    Heap_cd14& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_cd14& __cdecl FUN_00c85750() throw();
};
void __cdecl FUN_00c908c0(Heap_cd14* heap, void* array, int numElements, int sizeOfElement) throw();

template <class T> struct hkArray_cd14
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& AllocatePair() throw()
    {
        Heap_cd14& heap = Router_cd14::FUN_00c85750().heap();
        int n = m_iElementCount;
        int newSize = n + 1;
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < newSize)
        {
            int cap2 = 2 * cap;
            FUN_00c908c0(&heap, this, newSize < cap2 ? cap2 : newSize, sizeof(T));
        }
        m_iElementCount++;
        return m_data[n];
    }
};

struct Viewer_cd14
{
    virtual void v00();
    virtual void v04();
    virtual int GetValueForType(int type);
    virtual void v0C();
    virtual void enable(int id);
};

struct Process_cd14
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    Viewer_cd14 m_viewer;
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
    static void* operator new(unsigned int nbytes) throw()
    {
        Process_cd14* p = (Process_cd14*)Router_cd14::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Process_cd14* FUN_00d60f30(void* owner, void* a, void* b) throw();
    void VisitEntryNames() throw();
};

struct Entry_cd14
{
    const char* m_name;
    Process_cd14* m_process;
};

struct Server_cd14
{
    int unk00, unk04, unk08, unk0C;
    hkArray_cd14<Entry_cd14> m_entries;
    int m_pOwnerObject;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int* m_types;
    int m_numTypes;
    void hkVisualDebugger_writeStep(int i, float t);
    void AddEntry(const char* name, void* a, void* b);
};

// Allocates a new entry in m_entries, initializes its process with owner and parameters, enables matching viewer types, and activates the entry.
// @f3 0x00953680 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
void __cdecl FUN_009ef2c0(void* apCompilerInfo);
void __cdecl FUN_00901e90(void* apArray, int aiCapacity, int aiElementSize);
struct HeapCd14F3
{
    void* Allocate(unsigned int bytes, unsigned int tag);
};
struct ViewerCd14F3
{
    virtual void v00();
    virtual void v04();
    virtual int GetValueForType(int type);
    virtual void v0C();
    virtual void enable(int id);
};
struct ProcessCd14F3
{
    void* vtable;
    unsigned short m_usMemSize;
    short m_sRefCount;
    ViewerCd14F3 m_viewer;
    ProcessCd14F3* FUN_009eef30(void* apOwner, void* a, void* apCompilerInfo);
    void FUN_009eeee0();
};
struct EntryCd14F3
{
    const char* m_name;
    ProcessCd14F3* m_process;
};
struct EntryArrayCd14F3
{
    EntryCd14F3* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct ServerCd14F3
{
    int unk00;
    int unk04;
    int unk08;
    EntryArrayCd14F3 m_entries;
    int m_pOwnerObject;
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    int** m_types;
    int m_numTypes;
    void FUN_009530f0(int aiIndex, float afTime);
};
// pdb: hkVisualDebugger::createClient | hkVisualDebugger.obj | fnv360_0822_retail, call_seq, medium
// pdb params: socket, reader, writer
void Server_cd14::AddEntry(const char* name, void* a, void* apCompilerInfo)
{
    ServerCd14F3* self = (ServerCd14F3*)this;
    if (apCompilerInfo)
        FUN_009ef2c0(apCompilerInfo);
    EntryArrayCd14F3& arr = self->m_entries;
    int n = arr.m_iElementCount;
    int need = n + 1;
    int cap = arr.m_iCapacityState & 0x3fffffff;
    if (cap < need)
    {
        int grow = cap * 2;
        FUN_00901e90(&arr, need < grow ? grow : need, sizeof(EntryCd14F3));
    }
    arr.m_iElementCount = need;
    EntryCd14F3& e = arr.m_data[n];
    e.m_name = name;
    HeapCd14F3* heap = (HeapCd14F3*)TlsGetValue(DAT_010f3170);
    ProcessCd14F3* p = (ProcessCd14F3*)heap->Allocate(0x50, 0x35);
    p->m_usMemSize = 0x50;
    e.m_process = p->FUN_009eef30(&self->m_pOwnerObject, a, apCompilerInfo);
    e.m_process->FUN_009eeee0();
    for (int i = 0; i < self->m_numTypes; i++)
    {
        int type = *self->m_types[i];
        int id = e.m_process->m_viewer.GetValueForType(type);
        if (id >= 0)
            e.m_process->m_viewer.enable(id);
    }
    self->FUN_009530f0(self->m_entries.m_iElementCount - 1, 0.0f);
}


unsigned __int64 __cdecl FUN_00d60570();

struct hkStopwatchCD15
{
    unsigned __int64 m_uiStartTicks;
    unsigned __int64 m_uiTotalElapsedTicks;
    unsigned __int64 m_uiSplitStartTicks;
    unsigned __int64 m_uiSplitElapsedTicks;
    bool m_bIsRunning;
    int m_iStopCount;

    void start()
    {
        m_bIsRunning = true;
        m_uiStartTicks = FUN_00d60570();
        m_uiSplitStartTicks = m_uiStartTicks;
    }
    void stop()
    {
        if (m_bIsRunning)
        {
            m_bIsRunning = false;
            unsigned __int64 ticks_now = FUN_00d60570();
            m_uiTotalElapsedTicks += ticks_now - m_uiStartTicks;
            m_uiSplitElapsedTicks += ticks_now - m_uiSplitStartTicks;
            ++m_iStopCount;
        }
    }
};

struct hkProcessContextCD15
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
    virtual char* v28();
};

struct hkVisualDebuggerCD15
{
    int unk00;
    int unk04;
    hkProcessContextCD15* m_iValueAtOffset0C;
    bool m_shutdown;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    bool m_bTimingFrame;
    hkStopwatchCD15 m_kFrameTimer;

    void AddEntry(char* a, char* b, char* c);
    void FUN_00cd1520();
};

// Stops the timer, reports a message and client data when available, then restarts the timer if frame timing is enabled.
// @f3 0x00953760 (community match, verified in this file)
unsigned __int64 __cdecl FUN_009ee520();
struct Timer488 {
    unsigned __int64 started,elapsed,previous,total;
    bool active;unsigned int count;
    __forceinline void Stop() {
        if(active) {active=false;unsigned __int64 now=FUN_009ee520();elapsed+=now-started;total+=now-previous;++count;}
    }
    __forceinline void Start() {active=true;started=FUN_009ee520();previous=started;}
};
struct Server488 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual char* Client();
};
struct Stream488 {
    unsigned int unk00,unk04,unk08;
    Stream488(char* data,int bytes){FUN_00923070(data,bytes);}
    void FUN_00923070(char*,int);void FUN_00943710(const char*);void FUN_00943a60();
};
struct Logger488 {
    virtual void slot00();virtual void slot04();virtual void slot08();
    virtual void Message(int,int,const char*,const char*,int);
};
namespace Globals488 { extern Logger488* DAT_010f3364;extern const char DAT_00e7bd30[],DAT_00e7bb74[]; }
struct Layout488 {
    unsigned int unk00,unk04;Server488* server;
    unsigned int unkc,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
    unsigned int unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48;
    unsigned int unk4c,unk50,unk54;
    bool timing;unsigned int unk5c;Timer488 timer;
    void FUN_00953680(char*,char*,char*);
};
// pdb: hkVisualDebugger::pollForNewClients | hkVisualDebugger.obj | fnv360_0822_retail, vtable, medium
void hkVisualDebuggerCD15::FUN_00cd1520() {
    Layout488* owner=reinterpret_cast<Layout488*>(this);
    if(owner->timing) owner->timer.Stop();
    if(owner->server) {
        char* client=owner->server->Client();
        if(client) {
            int buffer[128];
            Stream488 stream(reinterpret_cast<char*>(buffer),sizeof(buffer));
            stream.FUN_00943710(Globals488::DAT_00e7bd30);
            Globals488::DAT_010f3364->Message(0,-1,reinterpret_cast<char*>(buffer),Globals488::DAT_00e7bb74,0xe4);
            stream.FUN_00943a60();
            owner->FUN_00953680(client,client+8,client+0x14);
        }
    }
    if(owner->timing) owner->timer.Start();
}


class hkMemoryAllocatorC17
{
  public:
    virtual void v00() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> __forceinline T* _bufAlloc(int& n) throw()
    {
        int iNumBytes = n * sizeof(T);
        void* p = AllocateBufferWithSize(iNumBytes);
        n = iNumBytes / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <typename T> __forceinline void _bufFree(void* p, int n) throw()
    {
        ReturnMemory(p, n * sizeof(T));
    }
};
struct hkMemoryRouterC17
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC17* m_pTemp;
    hkMemoryAllocatorC17* m_pStreamAllocator;
    hkMemoryAllocatorC17& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterC17& __cdecl GetMemoryRouterC17() throw();

template <class T> __forceinline void copyC17(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> class hkArrayC17
{
  public:
    hkArrayC17() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayC17() throw();
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
    __forceinline void _copyFromArray(hkMemoryAllocatorC17& alloc, const hkArrayC17& a) throw()
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                alloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyC17(m_data, a.m_data, m_iElementCount);
    }
    __forceinline hkArrayC17& operator=(const hkArrayC17& a) throw()
    {
        _copyFromArray(GetMemoryRouterC17().heap(), a);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkOstreamC17
{
  public:
    hkOstreamC17(void* pvBuffer, int iSize) throw();
    ~hkOstreamC17() throw();
    hkOstreamC17& operator<<(const char* pcString) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};
class hkErrorC17
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorC17* g_pkErrorC17;

class hkReferencedObjectC17
{
  public:
    hkReferencedObjectC17() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectC17() throw();
    void RetainReference() const;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00cd1780;
class hkProcessContextC17
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void SetOwnerPointer(FUN_00cd1780* pkOwner) throw();
};
class hkVtableClassRegistryC17 : public hkReferencedObjectC17
{
};
struct hkVisualDebuggerClientC17
{
    void* m_pSocket;
    void* m_pProcessHandler;
};
struct hkVisualDebuggerTrackedObjectC17
{
    void* m_ptr;
    void* m_class;
    unsigned int m_ucOperationType;
};
struct hkStringPtrC17
{
    ~hkStringPtrC17() throw();
    const char* m_pcText;
};
class hkStopwatchC17
{
  public:
    hkStopwatchC17(const char* pcName = 0) : m_name(pcName)
    {
        reset();
    }
    void reset()
    {
        m_uiStartTicks = 0;
        m_uiTotalElapsedTicks = 0;
        m_uiSplitStartTicks = 0;
        m_uiSplitElapsedTicks = 0;
        m_bIsRunning = false;
        m_iStopCount = 0;
    }
    unsigned __int64 m_uiStartTicks;
    unsigned __int64 m_uiTotalElapsedTicks;
    unsigned __int64 m_uiSplitStartTicks;
    unsigned __int64 m_uiSplitElapsedTicks;
    bool m_bIsRunning;
    int m_iStopCount;
    const char* m_name;
};

void __cdecl hkVisualDebuggerInitFactoryC17() throw();

class FUN_00cd1780 : public hkReferencedObjectC17
{
  public:
    FUN_00cd1780(const hkArrayC17<hkProcessContextC17*>& kContexts, const hkVtableClassRegistryC17* pkClassReg) throw();
    virtual ~FUN_00cd1780() throw();
    void addDefaultProcess(const char* pcName) throw();

    void* m_pServer;
    bool m_bTimingFrame;
    hkArrayC17<hkVisualDebuggerClientC17> m_kClients;
    hkArrayC17<hkProcessContextC17*> m_kProcessContexts;
    hkArrayC17<hkVisualDebuggerTrackedObjectC17> m_kTrackedObjects;
    hkArrayC17<void*> m_kTrackCallbacks;
    hkArrayC17<void*> m_kTrackCallbackHandles;
    const hkVtableClassRegistryC17* m_pReferencedObject;
    hkArrayC17<hkStringPtrC17> m_defaultViewers;
    bool m_overrideFrameTimeIfZero;
    hkStopwatchC17 m_kFrameTimer;
};

// @f3 0x00953a90 (community match, verified in this file)
// 0x00953a90 - hkVisualDebugger's constructor.
//
// The unit's FUN_00cd1780 keeps the later engine's member order: a bool directly after m_pServer,
// which puts the first hkArray at +0x10. This build has no such bool: the arrays start at +0x0c,
// the class registry is at +0x48, m_defaultViewers at +0x4c and the bool at +0x58 (the stopwatch
// is at +0x60 either way). The class is left exactly as the unit declares it; the members are
// written through the separately named view below, which has this build's order.
//
// Two things in here exist only because the declared class and the real layout disagree, and
// both go away once the class declaration drops m_bTimingFrame:
//  - the init list copy-initialises each declared array member (and the stopwatch) from itself.
//    That compiles to nothing, where the default constructors would write the three array words
//    at the declared (shifted) offsets; one of those, the word at +0x58, survives as an extra
//    store because the view only overwrites one byte of it.
//  - m_pServer and m_kClients are grouped in a head sub-object so that their four stores go
//    through one interior pointer, like the stores of the other arrays.

__forceinline f3m_00953e70::Heap953* GetThreadMemory953a90() throw()
{
    return static_cast<f3m_00953e70::Heap953*>(f3m_00953e70::DAT_00d9b080(f3m_00953e70::DAT_010f3170));
}

template <class T> __forceinline void InitArray953a90(hkArrayC17<T>& rkArray) throw()
{
    rkArray.m_data = 0;
    rkArray.m_iElementCount = 0;
    rkArray.m_iCapacityState = 0x80000000;
}

struct hkVisualDebuggerHead953a90
{
    __forceinline void Init() throw()
    {
        m_pServer = 0;
        InitArray953a90(m_kClients);
    }
    void* m_pServer;
    hkArrayC17<hkVisualDebuggerClientC17> m_kClients;
};

struct hkVisualDebuggerView953a90
{
    void* m_pVtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkVisualDebuggerHead953a90 m_kHead;
    hkArrayC17<hkProcessContextC17*> m_kProcessContexts;
    hkArrayC17<hkVisualDebuggerTrackedObjectC17> m_kTrackedObjects;
    hkArrayC17<void*> m_kTrackCallbacks;
    hkArrayC17<void*> m_kTrackCallbackHandles;
    const hkVtableClassRegistryC17* m_pReferencedObject;
    hkArrayC17<hkStringPtrC17> m_defaultViewers;
    bool m_overrideFrameTimeIfZero;
    hkStopwatchC17 m_kFrameTimer;
};

// pdb: hkVisualDebugger::hkVisualDebugger | hkVisualDebugger.obj | fnv360_0822_retail, ustr, medium
// pdb params: contexts, reg
FUN_00cd1780::FUN_00cd1780(const hkArrayC17<hkProcessContextC17*>& kContexts,
                           const hkVtableClassRegistryC17* pkClassReg) throw()
    : m_kClients(m_kClients), m_kProcessContexts(m_kProcessContexts), m_kTrackedObjects(m_kTrackedObjects),
      m_kTrackCallbacks(m_kTrackCallbacks), m_kTrackCallbackHandles(m_kTrackCallbackHandles),
      m_defaultViewers(m_defaultViewers), m_kFrameTimer(m_kFrameTimer)
{
    hkVisualDebuggerView953a90* pkSelf = (hkVisualDebuggerView953a90*)this;
    pkSelf->m_kHead.Init();
    InitArray953a90(pkSelf->m_kProcessContexts);
    InitArray953a90(pkSelf->m_kTrackedObjects);
    InitArray953a90(pkSelf->m_kTrackCallbacks);
    InitArray953a90(pkSelf->m_kTrackCallbackHandles);
    pkSelf->m_pReferencedObject = pkClassReg;
    InitArray953a90(pkSelf->m_defaultViewers);
    pkSelf->m_overrideFrameTimeIfZero = false;
    m_kFrameTimer.m_name = "Frame Timer";
    m_kFrameTimer.reset();

    // m_kProcessContexts = kContexts, with the thread-memory router read separately in each arm.
    if (pkSelf->m_kProcessContexts.getCapacity() < kContexts.GetLogicalSize())
    {
        if ((pkSelf->m_kProcessContexts.m_iCapacityState & 0x80000000) == 0)
            GetThreadMemory953a90()->FUN_008f6d90(pkSelf->m_kProcessContexts.m_data,
                                                  pkSelf->m_kProcessContexts.getCapacity() * sizeof(hkProcessContextC17*), 0x17);
        f3m_00953e70::Heap953* pThreadMemory = GetThreadMemory953a90();
        pkSelf->m_kProcessContexts.m_data = static_cast<hkProcessContextC17**>(
            pThreadMemory->FUN_008f6d30(kContexts.GetLogicalSize() * sizeof(hkProcessContextC17*), 0x17));
        pkSelf->m_kProcessContexts.m_iCapacityState =
            (pkSelf->m_kProcessContexts.m_iCapacityState & 0x40000000) | kContexts.GetLogicalSize();
    }
    int iNumContexts = kContexts.GetLogicalSize();
    pkSelf->m_kProcessContexts.m_iElementCount = iNumContexts;
    {
        hkProcessContextC17** pDst = pkSelf->m_kProcessContexts.m_data;
        hkProcessContextC17* const* pSrc = kContexts.m_data;
        if (iNumContexts > 0)
        {
            for (int i = 0; i < iNumContexts; i++)
                pDst[i] = pSrc[i];
        }
    }

    for (int i = 0; i < pkSelf->m_kProcessContexts.GetLogicalSize(); i++)
        pkSelf->m_kProcessContexts[i]->SetOwnerPointer(this);

    g_pkErrorC17->BeginSection(0x1293adef, "Visual Debugger");
    {
        unsigned int reportBuf[128];
        hkOstreamC17 ostr(reportBuf, sizeof(reportBuf));
        ostr << "VDB Server instance has been created";
        g_pkErrorC17->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 0x27);
    }
    hkVisualDebuggerInitFactoryC17();
    addDefaultProcess("Debug Display");
    addDefaultProcess("Swept Transforms");
    addDefaultProcess("MousePicking");
    if (pkSelf->m_pReferencedObject)
    {
        // The base's addReference, inlined: flags test, then bump.
        hkReferencedObjectC17* pReferencedObject =
            const_cast<hkReferencedObjectC17*>(static_cast<const hkReferencedObjectC17*>(pkSelf->m_pReferencedObject));
        if (pReferencedObject->m_usMemSizeAndFlags != 0)
            ++pReferencedObject->m_sReferenceCount;
    }
    g_pkErrorC17->EndSection();
}


namespace fnv_00cd1610 {
struct ErrorService
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03(int category, int severity, const char* message, const char* filename, int line);
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07(unsigned int key, const char* tag);
    virtual void V08();
};
extern "C" ErrorService* DAT_01268360;
}  // namespace fnv_00cd1610
