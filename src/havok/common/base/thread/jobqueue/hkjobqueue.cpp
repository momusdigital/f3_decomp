#include "f3_common.h"
// src/havok/common/base/thread/jobqueue/hkjobqueue.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/jobqueue/hkjobqueue.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void FUN_00d043c0(void*, int);

struct Bucket
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d056d0(int);
};
struct Registry
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
    Bucket buckets[1];
};
__declspec(align(16)) struct RequestContext
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
};
struct Owner
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
    int count;
    Registry* FUN_00d04400(RequestContext*);
    void FUN_00d04420(Registry*);
    void FUN_00d04a80(int, int);
};

struct Item
{
    int data[32];
};

struct ItemPool
{
    Item* m_items;
    int m_pRayCursor;
    int m_free;
    int m_unk0c;
    int m_uiItemCount;

    void Insert(const Item& item);
    void Insert2(const Item& item);
};

struct S_00d056a0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d056a0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d056a0_Allocator* m_pStreamAllocator;
    S_00d056a0_Allocator* heap()
    {
        return m_pStreamAllocator;
    }
};

S_00d056a0_Router* FUN_00c85750();

struct S_00d056a0_Elem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};

struct D057A0Element
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
};

struct D057A0Queue
{
    D057A0Element* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void SetNodeCount(int n);
    void FUN_00d057a0(const D057A0Element& element);
};

// @fnv 0x00d057a0
// pdb: hkJobQueue::DynamicData::operator new | hkJobQueue.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkQueue<struct hkJobQueue::JobQueueEntry>::enqueue)
// pdb params: nbytes
void D057A0Queue::FUN_00d057a0(const D057A0Element& element)
{
    if (m_iNodeCount >= m_pRayCursor)
    {
        if (m_pRayCursor == 0)
            SetNodeCount(8);
        else
            SetNodeCount(m_pRayCursor * 2);
    }
    if (m_pTail == m_pRayCursor)
        m_pTail = 0;
    m_data[m_pTail++] = element;
    m_iNodeCount++;
}

namespace fnv_00d057f0 {
struct Item
{
    int data[32];
};

struct ItemPool
{
    Item* m_items;
    int m_pRayCursor;
    int m_free;
    int m_unk0c;
    int m_uiItemCount;

    void Grow(int newCapacity);
    void FUN_00d057f0(const Item& item);
};

// Grows the pool if full, then stores item at the next free slot and increments the count.
// @fnv 0x00d057f0
// pdb: hkJobQueue::addJobQueueLocked | hkJobQueue.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: data, job, priority
void ItemPool::FUN_00d057f0(const Item& item)
{
    if (m_uiItemCount >= m_pRayCursor)
    {
        if (!m_pRayCursor)
            Grow(8);
        else
            Grow(m_pRayCursor * 2);
    }
    if (!m_free)
        m_free = m_pRayCursor;
    --m_free;
    m_items[m_free] = item;
    ++m_uiItemCount;
}
}  // namespace fnv_00d057f0

struct CallTarget
{
    int FUN_00d04390(int aiValue);
};

// @fnv 0x00d043c0
int __cdecl FUN_00d043c0(CallTarget* apTarget, int aiValue)
{
    return apTarget->FUN_00d04390(aiValue);
}

void __cdecl FUN_00d043c0(int value, int flag);

// ---------------------------------------------------------------------------
// ReleasePendingCounts - releases the pending semaphore counts of one object.
//
// The object keeps a table of semaphores at offset 0x78 and the number of
// table entries that are in use at offset 0x8c.  The argument is a block of
// per entry counters that starts at offset 0x22.  Every counter is taken
// over, cleared and the semaphore of that entry is released once for every
// count that was pending.
// ---------------------------------------------------------------------------

// The semaphore object; only released through FUN_00d043c0.
struct FnvSemaphore;

// Releases a semaphore count times.
void FUN_00d043c0(FnvSemaphore* pSemaphore, int count);

void __cdecl FUN_00d043c0(int value, int flag);

struct __declspec(align(16)) D049D0LockInfo
{
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
};

extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

struct __declspec(align(16)) D04B90Object
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};

// ---------------------------------------------------------------------------
// InitHookTable
//
// A free cdecl function taking one pointer; it fills a global table of 17
// default handlers, bumps a counter member of the object to at least 2 and
// then registers two handler descriptors (array + count + two callbacks) in
// the object's dispatch table, followed by two more registration helpers.
//
// The unit file of the pack is empty, so every type used here is a stand-in:
// only the member offsets and the calling conventions matter.
// ---------------------------------------------------------------------------

typedef void(__cdecl* HookFn)(void*, void*);

struct D04A20Allocator;

struct D04A20MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D04A20Allocator* m_pStreamAllocator;

    D04A20Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" D04A20MemoryRouter& __cdecl FUN_00c85750();
}
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D04A20Operation
{
    void* m_object;
    bool m_flag;
    int m_data;
};

struct D04A20OperationArray
{
    D04A20Operation* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    D04A20Operation& AllocatePair()
    {
        D04A20Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D04A20Operation));
        return m_data[m_iElementCount++];
    }
};

extern "C" __declspec(dllimport) unsigned long __stdcall TlsSetValue(unsigned long index, void* value);

struct PoolEntry
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    PoolEntry() throw();
    void Init80(int size) throw();
};

struct PoolTable
{
    static void* operator new(unsigned int nbytes) throw()
    {
        return FUN_00c85750()->heap()->AllocateMemoryBlock(nbytes);
    }

    unsigned short m_counts[12];
    int m_i18;
    int m_i1c;
    unsigned char m_b20;
    unsigned char m_b21;
    unsigned char m_b22;
    unsigned char m_b23;
    int m_i24;
    int m_i28;
    PoolEntry m_entries[16];
    PoolEntry& operator[](int i)
    {
        return m_entries[i];
    }
    int m_i16c;
};

struct D05490Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    D05490Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

typedef int(__cdecl* DispatchHandler)(void*, void*, void*);

template <typename T> inline T* hkAllocateChunk(int n)
{
    return static_cast<T*>(FUN_00c85750()->heap()->AllocateMemoryBlock(n * sizeof(T)));
}

template <typename T> inline void hkDeallocateChunk(T* p, int n)
{
    FUN_00c85750()->heap()->ReleaseBlock(p, n * sizeof(T));
}

struct hkQueue128
{
    S_00d056a0_Elem* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void FUN_00d056d0(int n);
};

// Grows the underlying element array to at least n slots, copying existing nodes and resetting the ring indices.
// @f3 0x00a222a0 (community match, verified in this file)
extern void* DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(void* allocator);
struct S_00d056a0_Heap
{
    S_00d056a0_Elem* FUN_008f6d30(int numBytes, int tag);
    void FUN_008f6d90(S_00d056a0_Elem* p, int numBytes, int tag);
};
extern "C" void __cdecl FUN_009234e0(void* dst, const void* src, int nbytes);

// pdb: hkQueue<hkJobQueue::JobQueueEntry>::setCapacity | hkJobQueue.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: n
void hkQueue128::FUN_00d056d0(int aiMinCapacity)
{
    if (m_pRayCursor < aiMinCapacity)
    {
        if (m_pRayCursor * 2 >= aiMinCapacity)
        {
            aiMinCapacity = m_pRayCursor * 2;
        }

        S_00d056a0_Heap* heap = (S_00d056a0_Heap*)DAT_00d9b080(DAT_010f3170);
        S_00d056a0_Elem* newData = heap->FUN_008f6d30(aiMinCapacity * (int)sizeof(S_00d056a0_Elem), 0x17);

        if (m_data)
        {
            if (m_iNodeCount)
            {
                if (m_pTail <= m_pFirstNode)
                {
                    int numHead = m_pRayCursor - m_pFirstNode;
                    int numTail = m_pTail;
                    FUN_009234e0(newData, m_data + m_pFirstNode, numHead * (int)sizeof(S_00d056a0_Elem));
                    FUN_009234e0(newData + numHead, m_data, numTail * (int)sizeof(S_00d056a0_Elem));
                }
                else
                {
                    FUN_009234e0(newData, m_data + m_pFirstNode, m_iNodeCount * (int)sizeof(S_00d056a0_Elem));
                }
            }
            m_pFirstNode = 0;
            m_pTail = m_iNodeCount;
        }

        int oldCapacity = m_pRayCursor;
        if (oldCapacity) {
            S_00d056a0_Elem* oldData = m_data;
            S_00d056a0_Heap* oldHeap = (S_00d056a0_Heap*)DAT_00d9b080(DAT_010f3170);
            oldHeap->FUN_008f6d90(oldData, oldCapacity * (int)sizeof(S_00d056a0_Elem), 0x17);
        }

        m_data = newData;
        m_pRayCursor = aiMinCapacity;
    }
}


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" const char str_010c41f8[];

extern unsigned long DAT_0126835c;
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct S_00d05020_Job
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
};

struct S_00d05020_Queue
{
    S_00d05020_Job* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void FUN_00d056d0(int capacity);

    void increaseCapacity()
    {
        if (m_pRayCursor == 0)
            FUN_00d056d0(8);
        else
            FUN_00d056d0(m_pRayCursor * 2);
    }

    void enqueueInFront(const S_00d05020_Job& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
            increaseCapacity();
        if (m_pFirstNode == 0)
            m_pFirstNode = m_pRayCursor;
        --m_pFirstNode;
        m_data[m_pFirstNode] = element;
        m_iNodeCount++;
    }

    void enqueue(const S_00d05020_Job& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
            increaseCapacity();
        if (m_pTail == m_pRayCursor)
            m_pTail = 0;
        m_data[m_pTail++] = element;
        m_iNodeCount++;
    }
};

namespace fnv_00df8570 {
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern unsigned int DAT_0126835c;
extern const char str_010c41f8[];
struct S00df8570_Rec
{
    unsigned char kind;
    unsigned char option;
    unsigned char active;
    unsigned char reserved;
    short stride;
    short sentinel;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    S00df8570_Rec()
    {
        option = 3;
        sentinel = -1;
        m10 = 0;
        m18 = 0;
        active = 1;
        m30 = 0;
        m14 = 0;
        m60 = 0;
        kind = 5;
        stride = 0x70;
    }
};
}  // namespace fnv_00df8570

namespace fnv_00d04b50 {
struct QueueState
{
    void* storage;
    unsigned int capacity, front, back, size;
};
struct __declspec(align(16)) Buffer
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short unk20, ref0, ref1, ref2, ref3, ref4;
    QueueState slot0, slot1, slot2, slot3, slot4, slot5, slot6, slot7;
    QueueState slot8, slot9, slot10, slot11, slot12, slot13, slot14, slot15;
};
struct Owner
{
    Buffer* FUN_00d04400(Buffer* scratch);
    void InsertItemAndNotify(Buffer* work, void* first, unsigned int second);
    void FUN_00d04420(Buffer* work);
    void FUN_00d04b50(void* first, unsigned int second);
};
}  // namespace fnv_00d04b50

namespace fnv_00d055c0 {
struct S_00d055c0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void* p, int bytes) throw();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReleaseBlock(void* p, int bytes) throw()
    {
        vfn_08(p, bytes);
    }
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00d055c0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d055c0_Heap* m10;
    __forceinline S_00d055c0_Heap& heap()
    {
        return *m10;
    }
};
S_00d055c0_Router* FUN_00c85750() throw();

struct S_00d055c0_Arr12
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00d055c0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 12);
        m_data = 0;
        m_cap = 0x80000000;
    }
};
extern void(__stdcall* DAT_00fdf058)(void*);

}  // namespace fnv_00d055c0

namespace fnv_00d889f0 {

struct SlotAllocator
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual void vSlot10(unsigned int a, unsigned int b);
};

struct AllocHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SlotAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

}  // namespace fnv_00d889f0

extern unsigned long DAT_0126835c;

static const char kTraceFinishJob[] = "TtfinishJob";
static const char kTraceEnd[] = "Et";

struct __declspec(align(16)) DispatchJob
{
    unsigned char m_eSubtype;
    unsigned char m_type;
    unsigned short m_iElementCount;
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
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* section);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* section);
