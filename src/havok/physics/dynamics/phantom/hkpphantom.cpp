#include "f3_common.h"
// src/havok/physics/dynamics/phantom/hkpphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhantom.h"

class hkListenerD07B;

template <class T>
class hkArrayD07B {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
};

class FUN_00d07bd0_cls;

class hkListenerD07B {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3(FUN_00d07bd0_cls* pkObject);
};

class FUN_00d07bd0_cls {
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
    hkArrayD07B<hkListenerD07B*> m_kListeners;

    void FUN_00d07af0();
    void NotifyListeners();
};

class hkMemoryAllocatorD07E {
public:
    virtual ~hkMemoryAllocatorD07E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T>
    void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD07E {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD07E* m_pStreamAllocator;
    hkMemoryAllocatorD07E& heap() { return *m_pStreamAllocator; }
};
extern "C" hkMemoryRouterD07E& __cdecl FUN_00c85750();

template <class T>
__forceinline void destructD07E(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T>
class hkArrayD07E {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    ~hkArrayD07E() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructD07E(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorD07E& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};


#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct __declspec(intrin_type) __declspec(align(16)) __m128 {
    float x, y, z, w;
};

struct __declspec(align(16)) hkQuadD07950 {
    hkReal x, y, z, w;
};

inline void MemCopyD07A90(void* pvDst, const void* pvSrc, int nbytes)
{
    char* pcDst = static_cast<char*>(pvDst);
    const char* pcSrc = static_cast<const char*>(pvSrc);
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<unsigned int*>(pcDst + i) = *reinterpret_cast<const unsigned int*>(pcSrc + i);
}
template <class T> struct ArrayD07A90 {
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        MemCopyD07A90(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

inline void MemCopyD07AF0(void* pvDst, const void* pvSrc, int nbytes)
{
    char* pcDst = static_cast<char*>(pvDst);
    const char* pcSrc = static_cast<const char*>(pvSrc);
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<unsigned int*>(pcDst + i) = *reinterpret_cast<const unsigned int*>(pcSrc + i);
}
template <class T> struct ArrayD07AF0 {
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        MemCopyD07AF0(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct LS_cls;
struct hkArr {
    void** m_data;
    int m_iElementCount;
    int m_pRayCursor;
    void** operator[](int i) { return m_data + i; }
};
struct Fun_cls {
    void* m_unk[38];
    hkArr m_lsn;
    void __thiscall FUN_00d07b50();
    void __thiscall FUN_00d07af0();
};
struct LS_cls {
    virtual void vf0a();
    virtual void vf0b();
    virtual void phantomRemoved(Fun_cls* phantom);
};

// Iterates the m_lsn array in reverse, calling phantomRemoved on each non-null entry, then calls FUN_00d07af0.
// @f3 0x00989820 (community match, verified in this file)
namespace Task1503 { struct View { int padding[35]; hkArr listeners; }; }
static __declspec(noinline) void FUN_00989760(hkArr* arr) {
 for(int i=arr->m_iElementCount-1;i>=0;--i) {
  if(arr->m_data[i]==0) {
   arr->m_iElementCount--;
   for(int j=i;j<arr->m_iElementCount;++j) arr->m_data[j]=arr->m_data[j+1];
  }
 }
}
// pdb: hkpPhantom::firePhantomRemoved | hkpPhantom.obj | tesv_win, call_gap, low
void Fun_cls::FUN_00d07b50() {
 for(int i=((Task1503::View*)this)->listeners.m_iElementCount-1;i>=0;--i) {
  void** slot=&((Task1503::View*)this)->listeners.m_data[i];
  if(((Task1503::View*)this)->listeners.m_data[i]) {
   LS_cls* listener=(LS_cls*)*slot;
   listener->phantomRemoved(this);
  }
 }
 FUN_00989760(&((Task1503::View*)this)->listeners);
}


template <class T> struct ArrRef {
    T* m_data;
    int m_iElementCount;
    T& operator[](int i) { return m_data[i]; }
    int GetLogicalSize() const { return m_iElementCount; }
};

template <int SIZE>
__forceinline void memCpyOneAlignedXd07da0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd07da0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd07da0 {
    extern "C" hkMemoryRouterXd07da0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T>
class hkArrayXd07da0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXd07da0& router = hkRouterXd07da0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd07da0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

template <int SIZE>
__forceinline void memCpyOneAlignedXd07de0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd07de0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd07de0 {
    extern "C" hkMemoryRouterXd07de0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T>
class hkArrayXd07de0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXd07de0& router = hkRouterXd07de0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd07de0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkMemoryAllocatorD07 {
public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct hkMemoryRouterD07 {
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorD07* m_pTemp;
    hkMemoryAllocatorD07* m_pStreamAllocator;
    hkMemoryAllocatorD07& heap() { return *m_pStreamAllocator; }
};
hkMemoryRouterD07& __cdecl GetMemoryRouterD07() throw();

template <typename T> struct hkArrayD07 {
    hkArrayD07() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~hkArrayD07() throw()
    {
        hkMemoryAllocatorD07& kAlloc = GetMemoryRouterD07().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const { return m_iElementCount; }
    T* begin() { return m_data; }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackD07(int n)
{
    hkMemoryRouterD07& kRouter = GetMemoryRouterD07();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackD07(T* p)
{
    GetMemoryRouterD07().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayD07 : public hkArrayD07<T> {
    __forceinline hkLocalArrayD07(int n) throw()
    {
        T* pLocal = hkAllocateStackD07<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayD07() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackD07(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

struct hkAabbD07;
class hkpBroadPhaseHandleD07;
class hkpPhantomD07;
struct hkpBroadPhaseHandlePairD07 {
    hkpBroadPhaseHandleD07* m_kPointA;
    hkpBroadPhaseHandleD07* m_kPointB;
};

class hkpBroadPhaseD07 {
public:
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
    virtual void UpdateAabbs(hkpBroadPhaseHandleD07* pkObjects[], const hkAabbD07* pkAabbs, int iNumObjects,
                             hkArrayD07<hkpBroadPhaseHandlePairD07>& kAddedPairs, hkArrayD07<hkpBroadPhaseHandlePairD07>& kRemovedPairs) throw();
    void lock() throw() { if (m_pWorldLock) lockImplementation(); }
    void unlock() throw() { if (m_pWorldLock) unlockImplementation(); }
    void lockImplementation() throw();
    void unlockImplementation() throw();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_pWorldLock;
};

class hkpCollidableCollidableFilterD07 {
public:
    virtual void v00();
};
class hkpCollisionFilterD07 {
public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpCollidableCollidableFilterD07 m_kCollidableFilter;
};

class hkpTypedBroadPhaseDispatcherD07 {
public:
    static void __cdecl SortPairs(hkArrayD07<hkpBroadPhaseHandlePairD07>& kNewPairs, hkArrayD07<hkpBroadPhaseHandlePairD07>& kDelPairs) throw();
    void DispatchCollisionPairs(hkpBroadPhaseHandlePairD07* pkPairs, int iNumPairs) throw();
    void DispatchNewPairs(hkpBroadPhaseHandlePairD07* pkPairs, int iNumPairs, const hkpCollidableCollidableFilterD07* pkFilter) throw();
};

class hkpKdTreeManagerD07 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void setDirty(int aiDirtyFlags) throw();
};

struct hkWorldOperationD07 {
    enum Type { UPDATE_PHANTOM_BP = 0x11 };
    struct TypeTag {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType)) {}
        unsigned char m_type;
    };
    struct PhantomBroadphaseUpdate : public TypeTag {
        PhantomBroadphaseUpdate() : TypeTag(UPDATE_PHANTOM_BP) {}
        hkpPhantomD07* m_pPhantom;
        const hkAabbD07* m_kBounds;
    };
};

class hkpWorldD07 {
public:
    bool areCriticalOperationsLockedForPhantoms() const { return m_iCriticalOperationsLockCountForPhantoms + m_iCriticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() { m_iCriticalOperationsLockCount--; }
    __forceinline void attemptToExecutePendingOperations()
    {
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                ExecutePendingOperationQueues();
        }
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unlockCriticalOperations();
        attemptToExecutePendingOperations();
    }
    const hkpCollidableCollidableFilterD07* getCollisionFilter() const
    {
        return m_pCollisionFilter ? &m_pCollisionFilter->m_kCollidableFilter : 0;
    }
    void AddWorldOperation(const hkWorldOperationD07::TypeTag& kOperation) throw();
    void ExecutePendingOperations() throw();
    void ExecutePendingOperationQueues() throw();

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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    hkpBroadPhaseD07* m_pJobSemaphore;
    hkpKdTreeManagerD07* m_pKdTreeManager;
    unsigned int unk60;
    hkpTypedBroadPhaseDispatcherD07* m_pBroadPhaseDispatcher;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    hkpCollisionFilterD07* m_pCollisionFilter;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    int m_iBroadPhaseNumObjects;
};

class hkpPhantomD07 {
public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldD07* m_pOwningWorld;
    unsigned int m_ulUserData;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    hkpBroadPhaseHandleD07* getBroadPhaseHandle() { return reinterpret_cast<hkpBroadPhaseHandleD07*>(&m_kBroadPhaseHandle); }
    unsigned int m_kBroadPhaseHandle;
};

class hkpAabbPhantomD07 : public hkpPhantomD07 {
public:
    void hkpPhantom_updateBroadPhase(const hkAabbD07& kNewAabb) throw();
    void updateOverlaps() throw();
    void setAabbData(const hkAabbD07& kNewAabb) throw();
};

// Updates the phantom's AABB in the broad phase, dispatches collision pair changes, and marks the KD-tree dirty if the world owns one.
// @f3 0x00989c00 (community match, verified in this file)
#include <windows.h>

extern DWORD DAT_010f3170;

class hkThreadMemoryF3 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* allocateStackSlow(int nbytes);
    virtual void deallocateStackSlow(void* p);
    void deallocateChunk(void* p, int nbytes, int cls);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCur;
    int unk24;
    char* m_stackBase;
    char* m_stackEnd;

    static hkThreadMemoryF3& getInstance() { return *(hkThreadMemoryF3*)TlsGetValue(DAT_010f3170); }

    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 0x10) & ~0xf;
        char* cur = m_stackCur;
        char* next = cur + nbytes;
        if (next <= m_stackEnd) {
            m_stackCur = next;
            return cur;
        }
        return allocateStackSlow(nbytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCur = (char*)p;
        if (p == m_stackBase)
            deallocateStackSlow(p);
    }
};

__forceinline void hkDeallocateStackF3(void* p)
{
    hkThreadMemoryF3& mem = hkThreadMemoryF3::getInstance();
    mem.deallocateStack(p);
}
template <typename T> __forceinline void hkDeallocateChunkF3(T* p, int n, int cls)
{
    hkThreadMemoryF3& mem = hkThreadMemoryF3::getInstance();
    mem.deallocateChunk(p, n * sizeof(T), cls);
}

template <typename T> struct hkArrayF3 {
    hkArrayF3() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~hkArrayF3()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            {
            int n = m_capacityAndFlags & 0x3fffffff;
            hkThreadMemoryF3& mem = hkThreadMemoryF3::getInstance();
            mem.deallocateChunk(m_data, n * sizeof(T), 0x17);
        }
    }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T> struct hkLocalArrayF3 : public hkArrayF3<T> {
    __forceinline hkLocalArrayF3(int n)
    {
        this->m_data = (T*)hkThreadMemoryF3::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | 0x80000000;
        m_localMemory = this->m_data;
    }
    __forceinline ~hkLocalArrayF3()
    {
        hkDeallocateStackF3(m_localMemory);
    }
    T* m_localMemory;
};

struct PairArrF3 : hkLocalArrayF3<hkpBroadPhaseHandlePairD07> { PairArrF3(int n) : hkLocalArrayF3<hkpBroadPhaseHandlePairD07>(n) {} };

class hkpBroadPhaseF3 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24();
    virtual void updateAabbs(hkpBroadPhaseHandleD07* objs[], const hkAabbD07* aabbs, int n,
                             hkArrayF3<hkpBroadPhaseHandlePairD07>& added, hkArrayF3<hkpBroadPhaseHandlePairD07>& removed);
    void lock() { if (m_multiThreadLock) lockImplementation(); }
    void unlock() { if (m_multiThreadLock) unlockImplementation(); }
    void lockImplementation();
    void unlockImplementation();
    int unk04;
    int unk08;
    int unk0c;
    void* m_multiThreadLock;
};

struct FilterF3 { virtual void v00(); };
struct CollisionFilterF3 {
    virtual void v00();
    int unk04;
    FilterF3 m_filter;
};

class hkpTypedBroadPhaseDispatcherF3 {
public:
    static void __cdecl removeDuplicates(hkArrayF3<hkpBroadPhaseHandlePairD07>& newPairs, hkArrayF3<hkpBroadPhaseHandlePairD07>& delPairs);
    void removePairs(hkpBroadPhaseHandlePairD07* pairs, int n);
    void addPairs(hkpBroadPhaseHandlePairD07* pairs, int n, const FilterF3* filter);
};

struct hkWorldOperationF3 {
    unsigned char m_type;
    void* m_phantom;
    const hkAabbD07* m_aabb;
};

class hkpWorldF3 {
public:
    void queueOperation(const hkWorldOperationF3& op);
    void internal_executePendingOperations();
    bool areCriticalOperationsLockedForPhantoms() const { return m_criticalOperationsLockCountForPhantoms + m_criticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_criticalOperationsLockCount++; }
    void unlockAndAttemptToExecutePendingOperations()
    {
        m_criticalOperationsLockCount--;
        if (m_criticalOperationsLockCount == 0 && !m_blockExecutingPendingOperations && m_pendingOperationsCount)
            internal_executePendingOperations();
    }

    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50;
    hkpBroadPhaseF3* m_broadPhase;
    hkpTypedBroadPhaseDispatcherF3* m_broadPhaseDispatcher;
    int unk5c; int unk60; int unk64; int unk68; int unk6c;
    CollisionFilterF3* m_collisionFilter;
    int unk74; int unk78; int unk7c;
    int m_pendingOperationsCount;
    int m_criticalOperationsLockCount;
    int m_criticalOperationsLockCountForPhantoms;
    bool m_blockExecutingPendingOperations;
    int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8;
    int m_broadPhaseUpdateSize;
};

struct OverlapArrF3 {
    void** m_data;
    int m_size;
    int m_capacityAndFlags;
};

// pdb: hkpPhantom::removeNullOverlapListeners | hkpPhantom.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_gap_sim), high
static __declspec(noinline) void hkpPhantom_removeNullOverlapListeners(OverlapArrF3* arr)
{
    for (int i = arr->m_size - 1; i >= 0; --i) {
        if (arr->m_data[i] == 0) {
            arr->m_size--;
            for (int j = i; j < arr->m_size; ++j)
                arr->m_data[j] = arr->m_data[j + 1];
        }
    }
}

struct AabbPhantomViewF3 {
    void* vtbl;
    int unk04;
    hkpWorldF3* m_world;
    int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    int m_broadPhaseHandle;
    int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    OverlapArrF3 m_overlappingCollidables;
};

// pdb: hkpPhantom::updateBroadPhase | hkpPhantom.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap_sim), high
void hkpAabbPhantomD07::hkpPhantom_updateBroadPhase(const hkAabbD07& newAabb)
{
    AabbPhantomViewF3* self = reinterpret_cast<AabbPhantomViewF3*>(this);
    if (self->m_world) {
        if (self->m_world->areCriticalOperationsLockedForPhantoms()) {
            hkWorldOperationF3 op;
            op.m_type = 0x11;
            op.m_phantom = this;
            op.m_aabb = &newAabb;
            self->m_world->queueOperation(op);
            return;
        }
        self->m_world->lockCriticalOperations();
        hkLocalArrayF3<hkpBroadPhaseHandlePairD07> newPairs(self->m_world->m_broadPhaseUpdateSize);
        hkLocalArrayF3<hkpBroadPhaseHandlePairD07> delPairs(self->m_world->m_broadPhaseUpdateSize);
        hkpBroadPhaseHandleD07* thisObj = (hkpBroadPhaseHandleD07*)&self->m_broadPhaseHandle;
        self->m_world->m_broadPhase->lock();
        self->m_world->m_broadPhase->updateAabbs(&thisObj, &newAabb, 1, newPairs, delPairs);
        if (newPairs.m_size != 0 || delPairs.m_size != 0) {
            hkpTypedBroadPhaseDispatcherF3::removeDuplicates(newPairs, delPairs);
            self->m_world->m_broadPhaseDispatcher->removePairs(delPairs.m_data, delPairs.m_size);
            self->m_world->m_broadPhaseDispatcher->addPairs(newPairs.m_data, newPairs.m_size,
                self->m_world->m_collisionFilter ? &self->m_world->m_collisionFilter->m_filter : 0);
            hkpPhantom_removeNullOverlapListeners(&self->m_overlappingCollidables);
        }
        self->m_world->m_broadPhase->unlock();
        self->m_world->unlockAndAttemptToExecutePendingOperations();
    }
}


struct S00d08130_Arr {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void ClearAndRelease(hkMemoryAllocatorD07E& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<void*>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
