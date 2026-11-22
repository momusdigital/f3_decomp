// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer_ehsc_noehsc_full_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHs-c- /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Bins
{
    float weights[8];
    unsigned short counts[8];
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    double value;
    void Accumulate(struct AxisData* data, struct Point* start, struct Point* end);
};
struct AxisData
{
    int unk00;
    unsigned int xIndex;
    unsigned int yIndex;
    unsigned int mode;
    float xScale;
    float yScale;
};
struct Point
{
    int unk00;
    unsigned int x;
    unsigned int y;
};

struct E0C860Node;

struct E0C860NodeArray
{
    E0C860Node** m_data;
    int m_iElementCount;

    E0C860Node*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct E0C860Node
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
    E0C860NodeArray m_children;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    const char* m_name;
    int m_flags;
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_e0ce00_Alloc;
struct S_e0ce00_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_e0ce00_Alloc* m_pStreamAllocator;
    S_e0ce00_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_e0ce00_Router* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(S_e0ce00_Alloc* alloc, void* arr, int elemSize);

struct S_e0ce00_Block
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
    S_e0ce00_Block();
};

struct S_e0ce00_Array
{
    S_e0ce00_Block* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S_e0ce00_Block& AllocatePair(S_e0ce00_Alloc& alloc)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(S_e0ce00_Block));
        new (m_data + m_iElementCount) S_e0ce00_Block;
        return m_data[m_iElementCount++];
    }
};

struct S_e0ce00_Bool
{
    char m_cBooleanValue;
    S_e0ce00_Bool(bool b)
    {
        m_cBooleanValue = b;
    }
};

namespace fnv_00e0d0a0 {
struct Entry
{
    void __thiscall FUN_00ddeff0(unsigned int flags);
};
void* __cdecl FUN_00c85750();
}  // namespace fnv_00e0d0a0

namespace fnv_00e0f800 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
};

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkMemoryAllocator* unk14;
    hkMemoryAllocator& heap()
    {
        return *unk14;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* arr, int capacity, int elemSize);

extern float DAT_011bdd84;

struct hkArrayChar
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayChar()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(&alloc, this, n < cap ? cap : n, 1);
        }
    }
};

}  // namespace fnv_00e0f800

void __cdecl FUN_00cc0410(void* stream, const char* format, ...);

extern "C" void __cdecl FUN_00cb1280(void* dst, int c, int n);

struct E0CC40Node
{
    float m_iSlotIds[16];
    double m_base;
};

// FUN_00e0ccf0 - a member function of the class that owns the spawned-entry array.
// The class layout is reconstructed from the code: +0x00 m_entries (SpawnedEntry*),
struct SpawnedEntry
{
    int unk00;
    int unk04;
    int unk08;
};

// Proxy used to force MSVC 2008 to materialise the element address in a register
// (base + byte offset) instead of folding it into the store's addressing mode.
struct EntryRef
{
    SpawnedEntry* p;
    void operator=(int value)
    {
        p->unk04 = value;
    }
};

struct S_e0ce00_Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* apItem, int aSize);
    virtual void v0c();
    virtual void v10(void* apData, unsigned int aBytes);
};

struct S_Flag
{
    char b;
    __forceinline S_Flag()
    {
        b = 0;
    }
    __forceinline S_Flag(const S_Flag& o)
    {
        b = o.b;
    }
};

extern "C" int __cdecl FUN_00cb0fa0(int a, unsigned int b);

struct __declspec(align(64)) LineBuf_e0c8e0
{
    int c00;
    int c01;
    int c02;
    int c03;
    int c04;
    int c05;
    int c06;
    int c07;
    int c08;
    int c09;
    int d00;
    int d01;
    int d02;
    int d03;
    int d04;
    int d05;
    int d06;
    int d07;
    int d08;
    int d09;
    int e00;
    int e01;
    int e02;
    int e03;
    int e04;
    int e05;
    int e06;
    int e07;
    int e08;
    int e09;
    int f00;
    int f01;
    int f02;
    int f03;
    int f04;
    int f05;
    int f06;
    int f07;
    int f08;
    int f09;
    int g00;
    int g01;
    int g02;
    int g03;
    int g04;
    int g05;
    int g06;
    int g07;
    int g08;
    int g09;
};

int __cdecl FUN_00cb0fa0(int a, int b);

void __cdecl FUN_00c908c0(S_e0ce00_Alloc* alloc, void* array, int count, int size);
struct TempArray830
{
    void** data;
    int size;
    int capacity;
    void* local[6];
    TempArray830() : data(local), size(0), capacity(0x80000006)
    {}
    void reserve(int count)
    {
        S_e0ce00_Alloc& heap = FUN_00c85750()->heap();
        int cap = capacity & 0x3fffffff;
        if (cap < count)
        {
            int newCap = cap * 2;
            if (count >= newCap)
                newCap = count;
            FUN_00c908c0(&heap, this, newCap, 4);
        }
    }
    void release()
    {
        S_e0ce00_Alloc& heap = FUN_00c85750()->heap();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.v10(data, (capacity & 0x3fffffff) * 4);
    }
};
void __cdecl FUN_00c908c0(S_e0ce00_Alloc* alloc, void* array, int count, int size);

struct FUN_00e0d000;
struct FUN_00e0d000Array
{
    FUN_00e0d000* data;
    int size;
    int capacity;
    FUN_00e0d000Array() : data(0), size(0), capacity(0x80000000)
    {}
    FUN_00e0d000& AllocatePair();
};
struct FUN_00e0d000
{
    float values[8];
    unsigned short counts[8];
    FUN_00e0d000** children;
    int childCount;
    int childCapacity;
    int unk3c;
    int unk40;
    int unk44;
    FUN_00e0d000* linked;
    const char* name;
    int flags;
    int unk54;
    FUN_00e0d000() : children(0), childCount(0), childCapacity(0x80000000)
    {}
    FUN_00e0d000(int, const char*, int);
    __forceinline void accumulate(const FUN_00e0d000& src)
    {
        for (int i = 0; i < 8; ++i)
        {
            values[i] += src.values[i];
            counts[i] += src.counts[i];
        }
    }
};
struct FUN_00e0d000Heap
{
    virtual void unused();
    virtual void* allocate(int);
};
struct FUN_00e0d000Router : S_e0ce00_Router
{
    FUN_00e0d000Heap* statsHeap;
    __forceinline FUN_00e0d000Heap& heapForStats()
    {
        return *statsHeap;
    }
};
struct FUN_00e0d000Total : FUN_00e0d000
{
    FUN_00e0d000Array linkedFUN_00e0d000;
    FUN_00e0d000Array childFUN_00e0d000;
    FUN_00e0d000Total() : FUN_00e0d000(0, 0, 0)
    {}
};
int __cdecl FUN_00cb0fa0(const char*, const char*);
void __cdecl FUN_00c908c0(FUN_00e0d000Heap*, FUN_00e0d000Array*, int, int);

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

extern int __cdecl FUN_00cb0fa0(const char* a, const char* b);
struct RecEntry
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
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* unk4c;
};
struct RecBox
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
    int unk24;
    int unk28;
    int unk2c;
    RecEntry** unk30;
    int unk34;
};
struct NameArg
{
    const char* unk00;
};
// @fnv 0x00e0cb80
volatile int g_in_name;
RecBox* volatile g_in_box;
void* volatile g_out;
void* volatile g_out2;

namespace fnv_00e0d100 {
struct NameArg
{
    const char* value;
};
struct BoolArg
{
    bool value;
};
struct CreateHeap
{
    virtual void unused();
    virtual void* allocate(int size);
};
struct CreateRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CreateHeap* heap;
    __forceinline CreateHeap& getHeap()
    {
        return *heap;
    }
};
}  // namespace fnv_00e0d100

struct DumpRouter
{
    int a, b, c, d, e;
    S_e0ce00_Alloc* allocator;
    S_e0ce00_Alloc& heap()
    {
        return *allocator;
    }
};
void __cdecl FUN_00c908c0(S_e0ce00_Alloc*, void*, int, int);
void __cdecl FUN_00cc0410(void*, const char*, ...);
struct FUN_00e108b0
{
    char* data;
    int size;
    int capacity;
    FUN_00e108b0();
    void reserve(S_e0ce00_Alloc& a, int n)
    {
        if ((capacity & 0x3fffffff) < n)
        {
            int c = (capacity & 0x3fffffff) * 2;
            if (c <= n)
                c = n;
            FUN_00c908c0(&a, this, c, 1);
        }
    }
    void reserve(int n)
    {
        reserve(((DumpRouter*)FUN_00c85750())->heap(), n);
        size = n;
    }
    void append(char c)
    {
        DumpRouter* r = (DumpRouter*)FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream((S_e0ce00_Alloc*)r->allocator, this, 1);
        data[size++] = c;
    }
    void clearAndFree(S_e0ce00_Alloc& a)
    {
        if ((capacity & 0x80000000u) == 0)
            a.v10(data, capacity & 0x3fffffff);
    }
    void clearAndFree()
    {
        S_e0ce00_Alloc& a = *((DumpRouter*)FUN_00c85750())->allocator;
        size = 0;
        clearAndFree(a);
    }
};

namespace fnv_00e0fec0 {
struct TimerObj;
struct TimerArray
{
    TimerObj** m_data;
    int m_iElementCount;
};
struct TimerObj
{
    float m_uiFilterValue;
    float value04;
    float value08;
    float value0c;
    float value10;
    float value14;
    float value18;
    float value1c;
    unsigned short counts[8];
    TimerArray m_children;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* m_name;
};
typedef TimerObj ThreadObj;
struct AggObj
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
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    AggObj* FUN_00e0d000(int a, const char* name, int b);
    void ClearItems();
};
int __cdecl ext_init(int, const char*, int);
__declspec(noinline) AggObj* AggObj::FUN_00e0d000(int a, const char* name, int b)
{
    unk00 = ext_init(a, name, b);
    return this;
}
struct Alloc2
{
    virtual void v00();
    virtual void* alloc(int size);
    virtual void free1(void* p, int size);
    virtual void v0c();
    virtual void free2(void* p, int bytes);
};
int __cdecl FUN_00cb0fa0(const char*, const char*);

void __cdecl FUN_00c908c0(Alloc2* alloc, void* arr, int count, int elemSize);
extern "C" void __cdecl FUN_00cb1280(void* dst, int c, int n);

struct TypeMap
{
    int unk00;
    int m_iElementCount;
    int unk08;
    void FUN_00d87790(S_Flag flag);
    int FUN_00d87410();
    void SetBoolFromThreshold(char* valid, int iterator);
    void* FUN_00d87440(int iterator);
    int FindNextUsedSlot(int iterator);
    void FreeBuffer();
};
struct TypeItem
{
    float values[8];
    unsigned short counts[8];
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
    int unk50;
    int unk54;
    AggObj* entries;
    int size;
    int capacity;
    AggObj* other;
    int otherSize;
    int otherCapacity;
    void FUN_00e10930();
};
void __cdecl FUN_00e0f880(void* node, TypeMap* map);
int __cdecl FUN_00e10740(const TypeItem*, const TypeItem*);
void __cdecl FUN_00e10760(TypeItem** data, int lo, int hi, int(__cdecl* compare)(const TypeItem*, const TypeItem*));

}  // namespace fnv_00e0fec0

struct FUN_00e0cc90_cls
{
    int unk00;
    int unk04;
    struct Entry
    {
        unsigned int key;
        int value;
    };
    Entry* m_pEntries;  // +0x08
    int m_iArrayLength;       // +0x0c
    int unk10;
    int m_iFallback;  // +0x14
    int FUN_00e0cc90(int arg);
};

struct S00e0d180_Node;

struct S00e0d180_Array
{

    S00e0d180_Node** m_data;

    int m_iElementCount;

    int m_iCapacityState;

    S00e0d180_Node*& operator[](int i)
    {
        return m_data[i];
    }
};

struct S00e0d180_Node
{

    float values[8];

    unsigned short counts[8];

    S00e0d180_Array children;

    double accumulatedValue;

    S00e0d180_Node* linked;

    const char* name;

    int flags;

    int unk54;

    void* operator new(unsigned int size)
    {

        return reinterpret_cast<FUN_00e0d000Heap&>(FUN_00c85750()->heap()).allocate(size);
    }

    S00e0d180_Node(S00e0d180_Node* parent, const char* name, int flags);
};

struct MonNode;
struct MonNodeArray
{
    MonNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    MonNode*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct MonNode
{
    float m_uiFilterValue[8];
    unsigned short m_uiItemCount[8];
    MonNodeArray m_children;
    int unk3c;
    double m_dValue;
};
struct MonNodeList
{
    MonNode** m_data;
    int m_iElementCount;
    MonNode*& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct AnimationTimingInfo
{
    int m_iValueAt00;
    int m_iFrameCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_fValueAt18;
    float m_startTimeOffset;
    float getOffset() const
    {
        return m_startTimeOffset;
    }
};
struct FrameInfo
{
    const char* m_pHeading;
    int m_iColor;
    int m_iTimer0;
    int m_uiTimer1;
    float m_fStartTime;
    float m_fEndTime;
    int m_uiThreadId;
    int m_iTimer0Index;
    int m_iTimer1Index;
};
struct FrameInfoArray
{
    FrameInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const FrameInfo& operator[](int i) const
    {
        return m_data[i];
    }
};
struct FrameInfoArrays
{
    FrameInfoArray* m_data;
    int m_iElementCount;
    const FrameInfoArray& operator[](int i) const
    {
        return m_data[i];
    }
};
struct FloatArray
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    float& operator[](int i)
    {
        float* p = m_data;
        return p[i];
    }
};

extern float DAT_011bdd84;
extern double DAT_010ea718;
extern float DAT_010ea710;
static __forceinline float clampFrameTime(float t)
{
    return (t < DAT_010ea718) ? DAT_010ea710 : t;
}

static __forceinline float getOffset(const AnimationTimingInfo& i)
{
    return i.m_startTimeOffset;
}

struct ReportFlag
{
    char b;
    ReportFlag() : b(0)
    {}
};
struct ReportResult
{
    char b;
};
struct ReportNode : FUN_00e0d000Total
{
    void FUN_00e10930();
};
struct ReportMap
{
    void* data;
    int size;
    int mask;
    int flags;
    void FUN_00d87790(ReportFlag);
    int FUN_00d87410();
    ReportNode* FUN_00d87440(int);
    int FindNextUsedSlot(int);
    void SetBoolFromThreshold(ReportResult*, int);
    bool valid(int i)
    {
        ReportResult b;
        SetBoolFromThreshold(&b, i);
        return b.b != 0;
    }
    void FreeBuffer();
};
struct ReportHeap
{
    virtual void v00();
    virtual void v04();
    virtual void freeNode(void*, int);
    virtual void v0c();
    virtual void freeBuffer(void*, int);
};
struct ReportRouter
{
    int unk00, unk04, unk08;
    ReportHeap* tempHeap;
    ReportHeap* mapHeap;
    ReportHeap* nodeHeap;
    ReportHeap& temp()
    {
        return *tempHeap;
    }
    ReportHeap& stats()
    {
        return *nodeHeap;
    }
};
void __cdecl FUN_00c908c0(ReportHeap*, void*, int, int);
struct ReportArray
{
    ReportNode** data;
    int size;
    int capacity;
    ReportArray() : data(0), size(0), capacity(0x80000000)
    {}
    void reserve(int n)
    {
        ReportHeap& heap = reinterpret_cast<ReportRouter*>(FUN_00c85750())->temp();
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            int next = cap * 2;
            if (n >= next)
                next = n;
            FUN_00c908c0(&heap, this, next, 4);
        }
    }
    void release()
    {
        ReportHeap& heap = reinterpret_cast<ReportRouter*>(FUN_00c85750())->temp();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.freeBuffer(data, (capacity & 0x3fffffff) * 4);
    }
};
bool __cdecl FUN_00e10740(ReportNode*, ReportNode*);
void __cdecl FUN_00e10760(ReportNode**, int, int, bool(__cdecl*)(ReportNode*, ReportNode*));
void __cdecl FUN_00e0f880(FUN_00e0d000*, ReportMap*);
// @fnv 0x00e0fc50
volatile FUN_00e0d000* reportRoot;
void* volatile reportStream;
volatile float reportThreshold;

namespace fnv_00e0d000 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_i10;
    AudioAllocator* m_pAllocator;
};

extern "C" void _ReadWriteBarrier(void);
AudioHolder* __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(int aiHeap, void* apList, int aiGrow);

struct FUN_00e0d000_cls;

struct SubList
{
    void** m_ppItems;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct OwnerNode
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
    int unk24;
    int unk28;
    int unk2c;
    SubList m_kNode;
};

struct FUN_00e0d000_cls
{
    float m_af00[8];
    unsigned short m_au20[8];
    int m_i30;
    int m_i34;
    unsigned int m_u38;
    int unk3c;
    double m_d40;
    OwnerNode* m_pSharedOwner;
    int m_i4c;
    int m_i50;
    int m_i54;

    FUN_00e0d000_cls* FUN_00e0d000(OwnerNode* apOwner, int aiA, int aiB);
};

// @fnv 0x00e0d000
FUN_00e0d000_cls* FUN_00e0d000_cls::FUN_00e0d000(OwnerNode* apOwner, int aiA, int aiB)
{
    m_i30 = 0;
    m_i34 = 0;
    m_u38 = 0x80000000u;
    m_pSharedOwner = apOwner;
    m_i4c = aiA;
    m_i50 = 0;
    m_i54 = aiB;
    if (apOwner != 0)
    {
        SubList* list = &apOwner->m_kNode;
        AudioHolder* holder = FUN_00c85750();
        if (list->m_iArrayLength == (int)(list->m_uCapFlags & 0x3fffffffu))
        {
            ResizeAudioStream(holder->m_i10, list, 4);
        }
        void** slot = list->m_ppItems + list->m_iArrayLength;
        _ReadWriteBarrier();
        *slot = this;
        list->m_iArrayLength++;
    }
    for (int i = 0; i < 8; i++)
    {
        m_af00[i] = 0.0f;
        m_au20[i] = 0;
    }
    m_d40 = 0.0;
    return this;
}
}  // namespace fnv_00e0d000

namespace fnv_00e0d640 {
struct FUN_00e0d640_buf
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pData;
    int m_iLen;
    int m_uiObjectFlags;
    void Destroy();
    void Init(char** pp);
    void PutChar(int c);
    void Assign(char* p);
};
struct FUN_00e0d640_alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int n);
};
struct FUN_00e0d640_hold
{
    int u0;
    int u1;
    int u2;
    int u3;
    FUN_00e0d640_alloc* m_pAllocationContext;
};
void FUN_00cc0410(FUN_00e0d640_buf* b, const char* fmt, ...);
FUN_00e0d640_hold* FUN_00c85750();

}  // namespace fnv_00e0d640

struct StatsValue
{
    int value;
    StatsValue(int v) : value(v)
    {}
};

__forceinline int asLocal(const volatile int& v)
{
    return v;
}

namespace fnv_00e0d980 {
inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}
struct S_e0d980_Heap
{
    int unk0;
};
struct S_e0d980_Holder
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_e0d980_Heap* unk10;
    S_e0d980_Heap& heap()
    {
        return *unk10;
    }
};
S_e0d980_Holder* FUN_00c85750() throw();
void ResizeAudioStream(S_e0d980_Heap& h, void* arr, int elemSize) throw();

struct S_e0d980_Str
{
    int unk0;
    S_e0d980_Str(int a) throw();
    S_e0d980_Str(const S_e0d980_Str& o) throw();
    ~S_e0d980_Str() throw();
};
struct S_e0d980_Item
{
    S_e0d980_Str name;
    int value;
    S_e0d980_Item(int a) throw() : name(a)
    {}
    S_e0d980_Item(const S_e0d980_Item& o) throw() : name(o.name)
    {
        value = o.value;
    }
};
struct S_e0d980_Arr
{
    S_e0d980_Item* data;
    int size;
    unsigned int cap;
    void push(const S_e0d980_Item& it)
    {
        S_e0d980_Holder* r = FUN_00c85750();
        if (size == (int)(cap & 0x3fffffff))
            ResizeAudioStream(r->heap(), this, 8);
        S_e0d980_Item* p = data + size;
        if (p)
            new (p) S_e0d980_Item(it);
        size++;
    }
};
}  // namespace fnv_00e0d980

struct S00e0e4e0_PArr
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00e0e4e0_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S00e0e4e0_Node;
struct S00e0e4e0_NodeArr
{
    S00e0e4e0_Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S00e0e4e0_Node*& operator[](int i)
    {
        return m_data[i];
    }
    S00e0e4e0_Node* const& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct S00e0e4e0_Node
{
    float m_iSlotIds[8];
    unsigned short m_counts[8];
    S00e0e4e0_NodeArr m_children;
};

void __cdecl FUN_00c908c0(S_e0ce00_Alloc* alloc, void* arr, int n, int elemSize);
static __forceinline void S00e0e4e0_push(S00e0e4e0_PArr* out, void* v)
{
    S_e0ce00_Alloc& a = FUN_00c85750()->heap();
    if (out->m_iElementCount == (out->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&a, out, 4);
    out->m_data[out->m_iElementCount] = v;
    out->m_iElementCount++;
}

__declspec(noinline) int __cdecl FUN_00e0da00(int row, int col, const S00e0e4e0_NodeArr& nodes, int height, float range,
                                             float value, S00e0e4e0_Info* info);

__declspec(nothrow) S_e0ce00_Router* __cdecl FUN_00c85750();
__declspec(nothrow) void __cdecl ResizeAudioStream(S_e0ce00_Alloc*, void*, int);
__declspec(nothrow) void __cdecl FUN_00c908c0(S_e0ce00_Alloc*, void*, int, int);
__declspec(nothrow) int __cdecl FUN_00cb0fa0(const char*, const char*);
struct StatsHeap
{
    virtual ~StatsHeap();
    virtual void* allocate(int bytes) = 0;
};
struct StatsRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    StatsHeap* heap;
    __forceinline StatsHeap& getHeap()
    {
        return *heap;
    }
};
__forceinline StatsHeap& statsHeap()
{
    return *reinterpret_cast<StatsRouter*>(FUN_00c85750())->heap;
}
namespace StatHeap {
StatsRouter* FUN_00c85750();
}
struct BoolArg
{
    char b;
    __forceinline BoolArg(bool v)
    {
        b = v;
    }
};
enum S0e630_NodeType
{
    S0e630_TIMER,
    S0e630_DIR,
    S0e630_SINGLE
};
struct Record
{
    const char* name;
    unsigned int x;
    unsigned int y;
};
struct RecordArray
{
    Record* data;
    int size;
    int capacity;
    Record local[16];
    __forceinline __declspec(nothrow) RecordArray() : data(local), size(0), capacity(0x80000010)
    {}
    __forceinline __declspec(nothrow) ~RecordArray()
    {
        release();
    }
    __forceinline void push(const Record& r)
    {
        S_e0ce00_Alloc& heap = FUN_00c85750()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, 12);
        new (data + size) Record(r);
        ++size;
    }
    __forceinline void resize(int count)
    {
        S_e0ce00_Alloc& heap = FUN_00c85750()->heap();
        int cap = capacity & 0x3fffffff;
        if (cap < count)
        {
            int newCap = cap * 2;
            if (count >= newCap)
                newCap = count;
            FUN_00c908c0(&heap, this, newCap, 12);
        }
        size = count;
    }
    __forceinline __declspec(nothrow) void release()
    {
        S_e0ce00_Alloc& heap = FUN_00c85750()->heap();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.v10(data, (capacity & 0x3fffffff) * 12);
        data = 0;
        capacity = 0x80000000;
    }
};

struct S00e0ee00_Children
{
    E0C860Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    E0C860Node*& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void SetSize(int n)
    {
        S_e0ce00_Alloc& alloc = FUN_00c85750()->heap();
        int capacity = m_iCapacityState & 0x3fffffff;
        if (capacity < n)
        {
            int grown = capacity * 2;
            if (n >= grown)
                grown = n;
            FUN_00c908c0(&alloc, this, grown, 4);
        }
        m_iElementCount = n;
    }
};

namespace fnv_00e0f710 {
inline void* __cdecl operator new(unsigned int, void* w) throw()
{
    return w;
}
struct S_00e0f710_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size) throw();
};

struct S_00e0f710_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e0f710_Heap* m_pStreamAllocator;
    S_00e0f710_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00e0f710_Router* __cdecl FUN_00c85750() throw();
int __cdecl FUN_00c908c0(S_00e0f710_Heap& heap, void* arr, int newCap, int elemSize);

struct S_00e0f710_Elem
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    S_00e0f710_Elem() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    __forceinline void ClearAndRelease()
    {
        S_00e0f710_Heap& h2 = FUN_00c85750()->heap();
        unsigned int c = m_cap;
        m_iElementCount = 0;
        if ((c & 0x80000000) == 0)
        {
            h2.Free(m_data, (c & 0x3fffffff) * 36);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
};

}  // namespace fnv_00e0f710

namespace fnv_00e10930 {

struct S_00e0c85750_Object
{
    virtual void FUN_00e0c85750_0();
    virtual void FUN_00e0c85750_1();
    virtual void FUN_00e0c85750_2();
    virtual void FUN_00e0c85750_3();
    virtual void FUN_00e0c85750_4(void*, int);
};

struct S_00c85750_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00e0c85750_Object* unk14;
};

S_00c85750_Result* FUN_00c85750();

}  // namespace fnv_00e10930

__declspec(noinline) E0CC40Node* __cdecl FindNodeAtTime(E0CC40Node*, E0CC40Node*, double, int);

template <class T> __forceinline void copyFrameTicks(T* dst, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        dst[i] = value;
}

template <class T> struct FrameTickArrayBase
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void append(S_e0ce00_Alloc& allocator, const T& value)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(&allocator, this, sizeof(T));
        copyFrameTicks(m_data + m_iElementCount, 1, value);
        ++m_iElementCount;
    }
};

struct FrameTickAllocator
{
    __forceinline S_e0ce00_Alloc& get(const void*)
    {
        return FUN_00c85750()->heap();
    }
};

template <class T> struct FrameTickArray : FrameTickArrayBase<T>
{
    __forceinline void AddBack(const T& value)
    {
        FrameTickArrayBase<T>::append(FrameTickAllocator().get(this), value);
    }
};

#pragma optimize("", on)

namespace NodeTickSupport {

template <class T> struct NodeTickArrayBase
{
    T* data;
    int size;
    int flags;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
    __forceinline T& back()
    {
        return data[size - 1];
    }
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int capacity() const
    {
        return flags & 0x3fffffff;
    }
    __forceinline void clear()
    {
        size = 0;
    }
};
template <class T> struct NodeTickArray : NodeTickArrayBase<T>
{
    __forceinline NodeTickArray()
    {
        data = 0;
        size = 0;
        flags = 0x80000000;
    }
    __forceinline void reserveExactly(int count)
    {
        S_e0ce00_Alloc& alloc = FUN_00c85750()->heap();
        if (capacity() < count)
            FUN_00c908c0(&alloc, this, count, sizeof(T));
    }
    __forceinline ~NodeTickArray()
    {
        S_e0ce00_Alloc& alloc = FUN_00c85750()->heap();
        clear();
        if ((flags & 0x80000000u) == 0)
            alloc.v10(data, capacity() * sizeof(T));
        data = 0;
        flags = 0x80000000;
    }
};

}

// @f3 0x00a8d480 (community match, verified in this file)
extern unsigned long g_tlsSlot_00a8d480;
namespace f3m_00a8d480 {
extern void* (__stdcall * const g_tlsGet_00a8d480)(unsigned long);

namespace fn_00a8d480 {
void ReserveArray(void* array, int count, int elemSize);
void GrowArray(void* array, int elemSize);

template <class T>
struct FrameNodeArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline T& back() { return m_data[m_iElementCount - 1]; }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int capacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& value) {
        if (m_iElementCount == capacity())
            GrowArray(this, sizeof(T));
        m_data[m_iElementCount] = value;
        ++m_iElementCount;
    }
};

struct StreamNode {
    float m_filterValues[8];
    unsigned short m_itemCounts[8];
    FrameNodeArray<StreamNode*> m_children;
    int m_flags3c;
    double m_timeValue;
};

struct StreamNodeList {
    StreamNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    StreamNode*& operator[](int i) { return m_data[i]; }
    StreamNode* const& operator[](int i) const { return m_data[i]; }
    int GetLogicalSize() const { return m_iElementCount; }
};

struct StreamInfo {
    int m_kind;
    int m_primaryAxis;
    int m_altAxis;
    int m_useAltAxis;
};

struct StreamEntry {
    StreamInfo* m_info;
    int m_color;
    int m_flags;
};

struct StreamEntryList {
    StreamEntry* m_data;
};

struct StreamLayout {
    int m_mode;
    int m_numPages;
    int m_width0;
    int m_width1;
    int m_extra;
    int m_height;
};

StreamNode* __cdecl FindStreamNodeAtTime(StreamNode* root, StreamNode* hint, double time, int axis);

static __declspec(noinline) void SampleStreamNodes(
    float start, float step, int axis, StreamNode* node, int count, FrameNodeArray<StreamNode*>* out)
{
    StreamNode* first = node->m_children[0];
    StreamNode* last = node->m_children.back();
    double leading = first->m_timeValue - start;
    double t = 0.0;
    int n = count;
    while (n != 0 && leading > t) {
        t += step;
        out->AddBack(0);
        --n;
    }
    double end = last->m_filterValues[axis] + last->m_timeValue - start;
    node->m_timeValue = first->m_timeValue;
    node->m_filterValues[axis] = (float)(start + end - node->m_timeValue + 1.0);
    StreamNode* hint = 0;
    while (n != 0 && t < end) {
        hint = FindStreamNodeAtTime(node, hint, t + start, axis);
        if (hint)
            out->AddBack(hint);
        t += step;
        --n;
    }
}

struct ThreadMemory {
    void DeallocateChunk(void* p, int nbytes, int cls);
    static __forceinline ThreadMemory& getInstance() {
        return *static_cast<ThreadMemory*>(g_tlsGet_00a8d480(g_tlsSlot_00a8d480));
    }
};

template <typename T>
struct TempArray {
    enum { CAPACITY_MASK = int(0x3FFFFFFF), DONT_DEALLOCATE_FLAG = int(0x80000000) };
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline TempArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    __forceinline ~TempArray() { releaseMemory(); }
    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & static_cast<int>(CAPACITY_MASK); }
    __forceinline void clear() { m_size = 0; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void reserve(int n) {
        if (getCapacity() < n)
            ReserveArray(this, n, sizeof(T));
    }
    __forceinline void releaseMemory() {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
            int n = getCapacity();
            ThreadMemory& mem = ThreadMemory::getInstance();
            mem.DeallocateChunk(m_data, n * sizeof(T), 0x17);
        }
    }
};

// pdb: getNodeSampledAtTick | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_seq, medium
static __declspec(noinline) int __cdecl FUN_00a8d480(
    StreamInfo* info, int row, int col, const StreamNodeList& nodes, int height, float range, float value)
{
    float step = range / height;
    TempArray<StreamNode*> samples;
    samples.reserve(height);
    StreamNode* result = 0;
    if (nodes[row]->m_children.GetLogicalSize() > 0) {
        samples.clear();
        int axis = info->m_useAltAxis == 0 ? info->m_primaryAxis : info->m_altAxis;
        SampleStreamNodes(value, step, axis, nodes[row], height,
                          reinterpret_cast<FrameNodeArray<StreamNode*>*>(&samples));
        if (col < samples.getSize())
            result = samples[col];
    }
    return (int)result;
}

void __cdecl ComputeStreamRanges(
    StreamNodeList& roots, StreamLayout* layout, StreamEntryList* entries, float* visibleRange, TempArray<float>* startTimes);

int __cdecl PickSampleAtScreenPos(
    int x, int y, StreamNodeList& roots, StreamLayout* layout, StreamEntryList* entries)
{
    const int streams = roots.GetLogicalSize();
    const int pages = layout->m_numPages;
    if (streams < 1)
        return 0;
    const int legend = pages > 1 ? 32 : 0;
    if (x < legend || x >= layout->m_height)
        return 0;
    const int visibleWidth = layout->m_height - legend;
    const int lineWidth = layout->m_width0 + layout->m_width1;
    const int pageWidth = streams * lineWidth + layout->m_extra;
    const int total = pageWidth * pages;
    if (y < 0 || y >= total)
        return 0;
    const int inverted = total - y - 1;
    const int page = inverted / pageWidth;
    const int stream = (inverted % pageWidth) / lineWidth;
    float visibleRange;
    TempArray<float> startTimes;
    ComputeStreamRanges(roots, layout, entries, &visibleRange, &startTimes);
    StreamNode*& selectedRoot = roots[stream];
    StreamInfo* selectedInfo = entries->m_data[stream].m_info;
    return FUN_00a8d480(
        selectedInfo, page, x - legend,
        reinterpret_cast<StreamNodeList&>(selectedRoot->m_children),
        visibleWidth, visibleRange, startTimes[page]);
}
}
}   // namespace f3m_00a8d480
