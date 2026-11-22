// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "f3_common.h"
// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Returns the smaller of the two float arguments.
// @fnv 0x00e0c260
// Returns the larger of the two float arguments.
// @fnv 0x00e0c290
// @fnv 0x00e0c2c0
// @fnv 0x00e0c2e0
// @fnv 0x00e0f6e0
// @fnv 0x00e0c310
// @fnv 0x00cc01a0
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
// Adds scaled start-to-end deltas into the weight/count bins at data's x and y indices, and sets value from start based on mode.
// @fnv 0x00e0c5e0
// Multiplies the value at index by factor, clears the matching flag, and recurses into all children.
// @fnv 0x00e0c700
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
// @fnv 0x00e0c860
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
// Appends a copy of the bytes from begin to end into m_buf at the current offset and records a block in m_arrays[b.unk18] with that offset and length.
// @fnv 0x00e0ce00
// Calls FUN_00e0c700 on first, then FUN_00e0d180 on first and second with index, limit and amount.
// @fnv 0x00e0d280
void __cdecl FUN_00cc0410(void* stream, const char* format, ...);
// Formats the item's name, max count and percentage into a buffer, then writes the values with nonzero counts to the stream.
// @fnv 0x00e0bfe0
extern "C" void __cdecl FUN_00cb1280(void* dst, int c, int n);
// Builds a 32-bit uncompressed TGA header from width and height, writes the header and pixel data to the stream, and returns true.
// @fnv 0x00e0c150
// @fnv 0x00e0c320
// Moves from node p through the tree according to the keys flags (up, down, collapse, expand) and returns the resulting node.
// @fnv 0x00e0c750
struct E0CC40Node
{
    float m_iSlotIds[16];
    double m_base;
};
E0CC40Node* __cdecl FUN_00e10820(E0CC40Node* node, double time, int axis);
// Walks down from hint (or root if hint is null or its axis value plus base is below time) via FUN_00e10820 until no child is returned, then returns the node.
// @fnv 0x00e0cc40
E0CC40Node* __cdecl FindNodeAtTime(E0CC40Node* root, E0CC40Node* hint, double time, int axis)
{
    E0CC40Node* node = hint;
    if (!node || !(node->m_iSlotIds[axis] + node->m_base >= time))
        node = root;
    while (node)
    {
        E0CC40Node* child = FUN_00e10820(node, time, axis);
        if (!child)
            break;
        node = child;
    }
    return node;
}
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
// @fnv 0x00e0ccf0
// @fnv 0x00e0cd20
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
// Collects m_count04 items via FUN_00e0ee00 into a temporary array, passes it to FUN_00e0fec0, then calls ClearItems and frees each item through the allocator.
// @fnv 0x00e10630
// @fnv 0x00e0f700
extern "C" int __cdecl FUN_00cb0fa0(int a, unsigned int b);
// @fnv 0x00e0c690
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
// @fnv 0x00e0c8e0
int __cdecl FUN_00cb0fa0(int a, int b);
// @fnv 0x00e0cbe0
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
// @fnv 0x00e0f5e0
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
// @fnv 0x00e0f880
extern unsigned int DAT_011bdea0[];
// @fnv 0x00e0c1c0
static __declspec(noinline) void FUN_00e0c1c0(unsigned int idx, int stride, unsigned int* out)
{
    unsigned int* entry = (unsigned int*)((unsigned int* volatile*)DAT_011bdea0)[idx];
    int stride4 = stride * 4;
    unsigned int* src = entry + 6;
    int shift = 0;

    do
    {
        unsigned int* dst = (unsigned int*)((unsigned char*)out + shift);
        unsigned int* p = src;
        int j = 7;

        do
        {
            unsigned int v = *p << shift;
            if (v & 0xf0000000u)
            {
                *dst = 0xff000000u;
            }
            p -= 1;
            dst = (unsigned int*)((char*)dst + stride4);
            --j;
        } while (j);

        shift += 4;
    } while (shift < 0x20);
}
struct S00e0c210_Obj
{
    int unk00;
};
static __declspec(noinline) void FUN_00e0c1c0(S00e0c210_Obj* self, int digit, int* out)
{
    int** pout = &out;
    self->unk00 = digit;
    self = (S00e0c210_Obj*)((int)self + digit);
    (*pout)[0] = self->unk00;
}
// @fnv 0x00e0c210
static __declspec(noinline) void __cdecl FUN_00e0c210(int value, S00e0c210_Obj* self, int* out)
{
    int place = 1000;
    int* cur = out;
    S00e0c210_Obj** pself = &self;
    int ten = 10;
    do
    {
        int quotient = value / place;
        int digit = quotient % ten;
        FUN_00e0c1c0(*pself, digit, cur);
        place /= 10;
        cur += 7;
    } while (place >= 1);
}
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
// @fnv 0x00e0c350
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
// @fnv 0x00e0cb80
volatile int g_in_name;
RecBox* volatile g_in_box;
void* volatile g_out;
void* volatile g_out2;
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
// @fnv 0x00e0eef0
// FUN_00e0cc90 - __thiscall member of a lookup table object.
//
// The object layout is taken from the original's disassembly:
//   +0x00  int      unk00
//   +0x04  int      unk04
//   +0x08  Entry*   m_pEntries   (8-byte entries: {unsigned key; int value;})
//   +0x10  int      unk10
//   +0x14  int      m_iFallback  (returned when no entry matches)
//
// The function walks the entries, asks hkString_strCasecmp(key & ~1, arg) about each
// key, and returns the value of the first entry the helper rejects; if the
// helper accepts every entry, the fallback at +0x14 is returned.
int __cdecl hkString_strCasecmp(unsigned int key, int arg);
// @fnv 0x00e0cc90
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
// @fnv 0x00e0d180
// @fnv 0x00e0d2c0
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
extern double DAT_0103c7c8;
extern float DAT_011bdd84;
extern double DAT_010ea718;
extern float DAT_010ea710;
static __forceinline float hkMin2(float a, float b)
{
    return a < b ? a : b;
}
static __forceinline float hkMax2(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline float clampFrameTime(float t)
{
    return (t < DAT_010ea718) ? DAT_010ea710 : t;
}
static __forceinline float addOffset(float a, float b)
{
    return a + b;
}
static __forceinline float getOffset(const AnimationTimingInfo& i)
{
    return i.m_startTimeOffset;
}
// @fnv 0x00e0dd30
void __cdecl FUN_00e0dd30(const MonNodeList& threadNodes, const AnimationTimingInfo& input,
                          const FrameInfoArrays& frameInfos, float& maxFrameTime, FloatArray& startTimes)
{
    int numThreads = threadNodes.GetLogicalSize();
    int frameEnd = input.m_iValueAt00 + input.m_iFrameCount;
    int numFrames = threadNodes[0]->m_children.GetLogicalSize();
    int numFramesToDraw = input.m_iFrameCount;
    if (frameEnd > numFrames)
    {
        numFramesToDraw = numFrames - input.m_iValueAt00;
        frameEnd = numFrames;
    }
    if (numFramesToDraw <= 0)
        return;

    int n = input.m_iFrameCount;
    {
        S_e0ce00_Router* router = FUN_00c85750();
        S_e0ce00_Alloc* heap = router->m_pStreamAllocator;
        int cap = startTimes.m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            if (n >= cap2)
                cap2 = n;
            FUN_00c908c0(heap, &startTimes, cap2, 4);
        }
        int numToFill = n - startTimes.m_iElementCount;
        float* p = startTimes.m_data + startTimes.m_iElementCount;
        for (int i = 0; i < numToFill; ++i)
            p[i] = 0.0f;
        startTimes.m_iElementCount = n;
    }

    maxFrameTime = 0.0f;
    for (int f = input.m_iValueAt00; f < frameEnd; ++f)
    {
        int idx = f - input.m_iValueAt00;
        const FrameInfo& info = frameInfos[0][f];
        int timer = info.m_uiTimer1 == 0 ? info.m_iColor : info.m_iTimer0;
        startTimes[idx] = 1e30f;
        for (int t = 0; t < numThreads; ++t)
        {
            MonNodeArray& children = threadNodes[t]->m_children[f]->m_children;
            if (children.GetLogicalSize() <= 0)
                continue;
            for (int c = 0; c < children.GetLogicalSize(); ++c)
            {
                MonNode* node = children[c];
                startTimes[idx] = hkMin2((float)node->m_dValue, startTimes[idx]);
            }
            for (int c = 0; c < children.GetLogicalSize(); ++c)
            {
                MonNode* node = children[c];
                float frameTime = (float)(node->m_uiFilterValue[timer] + node->m_dValue - startTimes[idx]);
                maxFrameTime = hkMax2(frameTime, maxFrameTime);
            }
        }
    }
    if (input.m_startTimeOffset > 0.0f)
    {
        int f = input.m_iValueAt00;
        if (frameEnd - f >= 4)
        {
            int end4 = frameEnd - 3;
            do
            {
                startTimes[f - input.m_iValueAt00] =
                    addOffset(startTimes[f - input.m_iValueAt00], input.m_startTimeOffset);
                {
                    float offset1 = input.m_startTimeOffset;
                    startTimes[(f + 1) - input.m_iValueAt00] += offset1;
                }
                startTimes[(f + 2) - input.m_iValueAt00] = input.getOffset() + startTimes[(f + 2) - input.m_iValueAt00];
                {
                    float value3 = startTimes[(f + 3) - input.m_iValueAt00];
                    startTimes[(f + 3) - input.m_iValueAt00] = input.m_startTimeOffset + value3;
                }
                f += 4;
            } while (f < end4);
        }
        if (f < frameEnd)
            do
            {
                {
                    int index4 = f - input.m_iValueAt00;
                    startTimes[index4] += input.m_startTimeOffset;
                }
                ++f;
            } while (f < frameEnd);
    }
    if (input.m_fValueAt18 > 0.0f)
    {
        maxFrameTime = input.m_fValueAt18;
        return;
    }
    if (numFramesToDraw == 1)
    {
        __declspec(align(8)) unsigned int ms = (unsigned int)(maxFrameTime / 1000.0);
        ms |= ms >> 1;
        ms |= ms >> 2;
        ms |= ms >> 4;
        ms |= ms >> 8;
        ms |= ms >> 16;
        ++ms;
        float upper = (float)(0.25 * DAT_011bdd84);
        float rounded = (float)((float)ms * 1000.0);
        float target = hkMin2(upper, rounded - DAT_011bdd84);
        maxFrameTime = (float)(target * DAT_0103c7c8 + DAT_011bdd84);
        float m = maxFrameTime;
        float r = (m < DAT_010ea718) ? DAT_010ea710 : m;
        maxFrameTime = r;
        DAT_011bdd84 = r;
    }
}
struct PixelSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    int m_14;
};
int __cdecl FUN_00e0e0c0(int a1, PixelSource* a2, int a3, void** out1, int* out2, int a6);
// @fnv 0x00e0e470
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
// @fnv 0x00e0fc50
volatile FUN_00e0d000* reportRoot;
void* volatile reportStream;
volatile float reportThreshold;

struct Se0e0c0_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
void* __cdecl AllocateWithHeader(Se0e0c0_Allocator* alloc, int numBytes);

struct Se0e0c0_Heap
{
    __forceinline Se0e0c0_Allocator& get(const void*)
    {
        return *(Se0e0c0_Allocator*)&FUN_00c85750()->heap();
    }
};

template <typename T> struct Se0e0c0_ArrayBase
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
};
template <typename T> struct Se0e0c0_Array : Se0e0c0_ArrayBase<T>
{
    __forceinline Se0e0c0_Array()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
    __forceinline ~Se0e0c0_Array()
    {
        Se0e0c0_Allocator& alloc = Se0e0c0_Heap().get(this);
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};

struct Se0e0c0_Bool
{
    char m_cBooleanValue;
    __forceinline Se0e0c0_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Se0e0c0_Dummy;
struct Se0e0c0_Pair
{
    unsigned long key;
    unsigned long val;
};
struct Se0e0c0_MapBase
{
    Se0e0c0_Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    __forceinline Se0e0c0_MapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    void EnsureCapacity(Se0e0c0_Allocator& alloc, int n);
    void ProcessArgument(Se0e0c0_Allocator& alloc);
    void FUN_00a29680();
    int get(unsigned long key, unsigned long* out) const;
    int insert(Se0e0c0_Allocator& alloc, unsigned long key, unsigned long val);
    __forceinline Se0e0c0_Dummy* GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned long)-1)
                break;
        }
        return (Se0e0c0_Dummy*)i;
    }
    __forceinline Se0e0c0_Dummy* getNext(Se0e0c0_Dummy* it) const
    {
        int i = (int)it;
        for (i += 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned long)-1)
                break;
        }
        return (Se0e0c0_Dummy*)i;
    }
    __forceinline Se0e0c0_Bool isValid(Se0e0c0_Dummy* it) const
    {
        int i = (int)it;
        return Se0e0c0_Bool(i <= m_iPairCount);
    }
};
struct Se0e0c0_PointerMap : Se0e0c0_MapBase
{
    __forceinline Se0e0c0_PointerMap()
    {
        EnsureCapacity(Se0e0c0_Heap().get(this), 0);
    }
    __forceinline ~Se0e0c0_PointerMap()
    {
        ProcessArgument(Se0e0c0_Heap().get(this));
        FUN_00a29680();
    }
};

struct Se0e0c0_FrameInfo
{
    const char* m_pHeading;
    int m_iColor;
    int m_iTimer0;
    unsigned int m_uiTimer1;
    float m_fStartTime;
    float m_fEndTime;
    int m_uiThreadId;
    int m_iTimer0Index;
    int m_iTimer1Index;
};
struct Se0e0c0_Node
{
    float m_uiFilterValue[8];
    unsigned short m_uiItemCount[8];
    Se0e0c0_ArrayBase<Se0e0c0_Node*> m_children;
    double m_dValue;
    Se0e0c0_Node* m_next;
    const char* m_name;
};
struct Se0e0c0_ColorPair
{
    const char* m_kColorName;
    unsigned int m_kDiffuseColor;
};
struct Se0e0c0_ColorTable
{
    void* vtbl;
    int m_refs;
    Se0e0c0_ArrayBase<Se0e0c0_ColorPair> m_kColorPairs;
};
struct Se0e0c0_Input
{
    int m_iValueAt00;
    int m_iFrameCount;
    int m_iValueAt08;
    int m_iValueAt0C;
    int m_iValueAt10;
    int m_iValueAt14;
    float m_fValueAt18;
    float m_fValueAt1C;
    Se0e0c0_Bool m_bValueAt20;
    Se0e0c0_ColorTable* m_pColorTable;
};
struct Se0e0c0_SampleInfo
{
    float m_fValueAt00;
};

extern const int* Se0e0c0_numbers[10];

static void __cdecl FUN_00e0c1c0(int digit, int y, int width, int* texture);

static void __cdecl FUN_00e0c210(int value, int y, int width, int* texture)
{
    int offset = 0;
    for (int divisor = 1000; divisor >= 1; divisor /= 10)
    {
        int digit = (*(volatile int*)&value / divisor) % 10;
        FUN_00e0c1c0(digit, y, *(volatile int*)&width, texture + offset);
        offset += 7;
    }
}

static void __cdecl FUN_00e0c1c0(int digit, int y, int width, int* texture)
{
    const int* number = Se0e0c0_numbers[digit];
    for (int x = 0; x < 8; x++)
    {
        for (int row = 0; row < 7; row++)
        {
            if ((number[6 - row] << (x * 4)) & 0xf0000000)
            {
                texture[row * width + x] = 0xff000000;
            }
        }
    }
}

void __cdecl FUN_00e0daf0(const Se0e0c0_FrameInfo& info, int frame,
                                 const Se0e0c0_ArrayBase<Se0e0c0_Node*>& nodes, int* texture, int height,
                                 Se0e0c0_ColorTable* colorTable, int rowStride, int width, float maxFrameTime,
                                 float startTime, Se0e0c0_PointerMap& unknownTimers);

extern float Se0e0c0_lastFrameTime;
void Se0e0c0_setSize(Se0e0c0_Array<float>& a, int n, const float& fill);
unsigned int __cdecl Se0e0c0_roundUpPow2(unsigned int v);

void __cdecl FUN_00e0dd30(const Se0e0c0_ArrayBase<Se0e0c0_Node*>& nodes, const Se0e0c0_Input& input,
                          Se0e0c0_ArrayBase<Se0e0c0_Array<Se0e0c0_FrameInfo> >& frameInfos, float& maxFrameTime,
                          Se0e0c0_Array<float>& startTimes)
{
    int numThreads = nodes.GetLogicalSize();
    int endFrame = input.m_iValueAt00 + input.m_iFrameCount;
    int available = nodes[0]->m_children.GetLogicalSize();
    int numFrames = input.m_iFrameCount;
    if (endFrame > available)
    {
        numFrames = available - input.m_iValueAt00;
        endFrame = available;
    }
    if (numFrames <= 0)
    {
        return;
    }
    float zero = 0.0f;
    Se0e0c0_setSize(startTimes, input.m_iFrameCount, zero);
    maxFrameTime = 0.0f;
    for (int f = input.m_iValueAt00; f < endFrame; f++)
    {
        int idx = f - input.m_iValueAt00;
        int timer = frameInfos[0][f].m_uiTimer1 == 0 ? frameInfos[0][f].m_iColor : frameInfos[0][f].m_iTimer0;
        startTimes[idx] = 1e30f;
        for (int t = 0; t < numThreads; t++)
        {
            const Se0e0c0_ArrayBase<Se0e0c0_Node*>& children = nodes[t]->m_children[f]->m_children;
            if (children.GetLogicalSize() > 0)
            {
                for (int i = 0; i < children.GetLogicalSize(); i++)
                {
                    float st = (float)children[i]->m_dValue;
                    startTimes[idx] = st < startTimes[idx] ? st : startTimes[idx];
                }
                for (int j = 0; j < children.GetLogicalSize(); j++)
                {
                    double end = children[j]->m_uiFilterValue[timer] + children[j]->m_dValue - startTimes[idx];
                    float e = (float)end;
                    maxFrameTime = maxFrameTime > e ? maxFrameTime : e;
                }
            }
        }
    }
    if (input.m_fValueAt1C > 0.0)
    {
        for (int f2 = input.m_iValueAt00; f2 < endFrame; f2++)
        {
            startTimes[f2 - input.m_iValueAt00] += input.m_fValueAt1C;
        }
    }
    if (input.m_fValueAt18 > 0.0)
    {
        maxFrameTime = input.m_fValueAt18;
        return;
    }
    if (numFrames == 1)
    {
        float rounded = (float)((__int64)Se0e0c0_roundUpPow2((int)(maxFrameTime / 1000.0) + 1) * 1000.0);
        float delta = rounded - Se0e0c0_lastFrameTime;
        float quarter = (float)(Se0e0c0_lastFrameTime / 4.0);
        maxFrameTime = (delta < quarter ? delta : quarter) * 0.05f + Se0e0c0_lastFrameTime;
        maxFrameTime = maxFrameTime > 16666.0f ? maxFrameTime : 16666.0f;
        Se0e0c0_lastFrameTime = maxFrameTime;
    }
}

// @fnv 0x00e0e0c0
void __cdecl FUN_00e0e0c0(const Se0e0c0_ArrayBase<Se0e0c0_Node*>& nodes, const Se0e0c0_Input& input,
                          Se0e0c0_ArrayBase<Se0e0c0_Array<Se0e0c0_FrameInfo> >& frameInfos, int*& texture, int& height,
                          Se0e0c0_SampleInfo* sampleInfo)
{
    int numThreads = nodes.GetLogicalSize();
    if (numThreads < 1)
    {
        return;
    }
    float maxFrameTime = -1.0f;
    Se0e0c0_Array<float> startTimes;
    FUN_00e0dd30(nodes, input, frameInfos, maxFrameTime, startTimes);

    int maxFrames = frameInfos[0].GetLogicalSize() - input.m_iValueAt00;
    int numFrames = input.m_iFrameCount > maxFrames ? maxFrames : input.m_iFrameCount;
    int endFrame = input.m_iValueAt00 + numFrames;
    int threadSpacing = input.m_iValueAt08 + input.m_iValueAt0C;
    int frameHeight = threadSpacing * numThreads + input.m_iValueAt10;
    int totalHeight = frameHeight * numFrames;
    int currentY = totalHeight;
    int border = (numFrames > 1) ? 32 : 0;
    int drawWidth = input.m_iValueAt14 - border;
    int numPixels = (input.m_iValueAt14 + 1) * totalHeight;

    texture = (int*)AllocateWithHeader((Se0e0c0_Allocator*)&FUN_00c85750()->heap(), numPixels * sizeof(int));
    height = totalHeight;
    FUN_00cb1280(texture, 0, numPixels * 4);
    if (sampleInfo)
    {
        sampleInfo->m_fValueAt00 = maxFrameTime;
    }

    Se0e0c0_PointerMap unknownTimers;

    for (int frame = input.m_iValueAt00; frame < endFrame; frame++)
    {
        currentY -= input.m_iValueAt10;
        if (numFrames > 1)
        {
            FUN_00e0c210(frame, currentY, input.m_iValueAt14,
                         texture + (currentY - threadSpacing) * input.m_iValueAt14);
        }
        for (int thread = 0; thread < numThreads; thread++)
        {
            currentY -= threadSpacing;
            int* row = texture + currentY * input.m_iValueAt14 + border;
            FUN_00e0daf0(frameInfos[thread][0], frame, nodes[thread]->m_children, row, input.m_iValueAt08,
                         input.m_pColorTable, input.m_iValueAt14, drawWidth, maxFrameTime,
                         startTimes[frame - input.m_iValueAt00], unknownTimers);
        }
    }

    float pixelsPerFrame = (drawWidth * 1000) / maxFrameTime;
    int startOffset = (int)(((int)input.m_fValueAt1C % 1000) * 0.001f * pixelsPerFrame);

    if (pixelsPerFrame > 5.0)
    {
        int x = border - startOffset;
        int i = 0;
        while (x < input.m_iValueAt14)
        {
            if (x >= 0)
            {
                for (int y = 0; y < totalHeight; y++)
                {
                    texture[y * input.m_iValueAt14 + x] = 0xff0000ff;
                }
            }
            i++;
            x = border - startOffset + (int)(i * pixelsPerFrame);
        }
    }

    int step = (int)((drawWidth * 16666) / maxFrameTime);
    if (step > 0)
    {
        for (int x = border - startOffset; x < input.m_iValueAt14; x += step)
        {
            if (x < 0)
                continue;
            for (int y = 0; y < totalHeight; y++)
            {
                texture[y * input.m_iValueAt14 + x] = 0xff00ff00;
                texture[y * input.m_iValueAt14 + x + 1] = 0xff00ff00;
            }
        }
    }

    if (input.m_bValueAt20)
    {
        for (Se0e0c0_Dummy* it = unknownTimers.GetFirstIterator(); unknownTimers.isValid(it);
             it = unknownTimers.getNext(it))
        {
        }
    }
}

__declspec(noinline) E0CC40Node* __cdecl FindNodeAtTime(E0CC40Node*, E0CC40Node*, double, int);

template <class T> __forceinline void copyElements(T* dst, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        dst[i] = value;
}

template <class T> struct SampleArrayBase
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline SampleArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
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
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void append(S_e0ce00_Alloc& allocator, const T& value)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(&allocator, this, sizeof(T));
        copyElements(m_data + m_iElementCount, 1, value);
        ++m_iElementCount;
    }
    __forceinline void reserveExactly(S_e0ce00_Alloc& allocator, int count)
    {
        if (capacity() < count)
            FUN_00c908c0(&allocator, this, count, sizeof(T));
    }
    __forceinline void release(S_e0ce00_Alloc& allocator)
    {
        clear();
        if ((m_iCapacityState & 0x80000000u) == 0)
            allocator.v10(m_data, capacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct SampleAllocator
{
    __forceinline S_e0ce00_Alloc& get(const void*)
    {
        return FUN_00c85750()->heap();
    }
};

template <class T> struct SampleArray : SampleArrayBase<T>
{
    __forceinline void AddBack(const T& value)
    {
        SampleArrayBase<T>::append(SampleAllocator().get(this), value);
    }
    __forceinline void reserveExactly(int count)
    {
        SampleArrayBase<T>::reserveExactly(SampleAllocator().get(this), count);
    }
    __forceinline ~SampleArray()
    {
        SampleArrayBase<T>::release(SampleAllocator().get(this));
    }
};

struct SampleNode
{
    float m_iSlotIds[8];
    unsigned short m_counts[8];
    SampleArray<SampleNode*> m_children;
    double m_base;
    SampleNode* m_parent;
    const char* m_name;
};

static __declspec(noinline) void FUN_00e0cec0(SampleNode* root, float start, float delta, int count,
                                              SampleArray<SampleNode*>& output, int axis)
{
    SampleNode* firstChild = root->m_children[0];
    SampleNode* finalChild = root->m_children.back();
    double begin = firstChild->m_base - start;
    double tick = 0.0;
    int remaining = count;
    while (remaining && begin > tick)
    {
        tick += delta;
        output.AddBack(0);
        --remaining;
    }
    double finish = finalChild->m_iSlotIds[axis] + finalChild->m_base - start;
    root->m_base = firstChild->m_base;
    root->m_iSlotIds[axis] = float(start + finish - root->m_base + 1.0);
    SampleNode* previous = 0;
    while (remaining && tick < finish)
    {
        previous = (SampleNode*)FindNodeAtTime((E0CC40Node*)root, (E0CC40Node*)previous, tick + start, axis);
        if (previous)
            output.AddBack(previous);
        tick += delta;
        --remaining;
    }
}

struct ColorMapBase
{
    void* m_entries;
    int m_iElementCount;
    int m_mod;
    void EnsureCapacity(S_e0ce00_Alloc*, int);
    int LookupBucketValue(unsigned long key, unsigned long* out) const;
    int FUN_00cb1870(S_e0ce00_Alloc*, unsigned long key, unsigned long value);
    void ProcessArgument(S_e0ce00_Alloc*);
    void FUN_00a29680();
    __forceinline ColorMapBase() : m_entries(0), m_iElementCount(0), m_mod(-1)
    {}
    __forceinline ~ColorMapBase()
    {
        FUN_00a29680();
    }
};
struct ColorMapStorage : ColorMapBase
{
    __forceinline ColorMapStorage()
    {
        EnsureCapacity(&SampleAllocator().get(this), 0);
    }
    __forceinline ~ColorMapStorage()
    {
        ProcessArgument(&SampleAllocator().get(this));
    }
    __forceinline int insert(unsigned long key, unsigned long value)
    {
        return FUN_00cb1870(&SampleAllocator().get(this), key, value);
    }
};
struct ColorMap
{
    ColorMapStorage m_map;
    __forceinline int get(const char* key, int* out) const
    {
        unsigned long value;
        if (m_map.LookupBucketValue((unsigned long)key, &value) == 0)
        {
            *out = int(value);
            return 0;
        }
        return 1;
    }
    __forceinline int insert(const char* key, int value)
    {
        return m_map.insert((unsigned long)key, (unsigned long)value);
    }
};
typedef Se0e0c0_FrameInfo TextureFrame;
struct ColorName
{
    unsigned long m_tagged;
    __forceinline operator const char*() const
    {
        return (const char*)(m_tagged & ~1u);
    }
};
struct ColorPair
{
    ColorName m_name;
    unsigned int m_kDiffuseColor;
};
struct TextureColors
{
    int unk00;
    int unk04;
    SampleArray<ColorPair> m_pairs;
    unsigned int m_uiColorValue;
};
int __cdecl hkString_strCasecmp(const char*, const char*);

static __forceinline void renderTextureColumns(const TextureFrame& info, int frame,
                                               const SampleArrayBase<SampleNode*>& trees, int* image, int rows,
                                               TextureColors& colors, int stride, int samples, float duration,
                                               float start, ColorMap& missing)
{
    ColorMap cache;
    float increment = duration / samples;
    SampleArray<SampleNode*> ticks;
    ticks.reserveExactly(samples);
    if (trees[frame]->m_children.GetLogicalSize() > 0)
    {
        ticks.clear();
        int axis = info.m_uiTimer1 == 0 ? info.m_iColor : info.m_iTimer0;
        FUN_00e0cec0(trees[frame], start, increment, samples, ticks, axis);
        int size = ticks.GetLogicalSize();
        for (int column = 0; column < size && column < samples; ++column)
        {
            int color = -1;
            if (ticks[column])
            {
                SampleNode* current = ticks[column];
                while (current)
                {
                    const char* label = current->m_name;
                    if (cache.get(label, &color) == 1)
                    {
                        if (missing.get(label, &color) != 1)
                        {
                            current = current->m_parent;
                            continue;
                        }
                        bool found = false;
                        for (int entry = 0; entry < colors.m_pairs.GetLogicalSize(); ++entry)
                        {
                            if (hkString_strCasecmp(colors.m_pairs[entry].m_name, label) == 0)
                            {
                                color = colors.m_pairs[entry].m_kDiffuseColor;
                                found = true;
                                break;
                            }
                        }
                        if (found)
                        {
                            cache.insert(label, color);
                            break;
                        }
                        else
                        {
                            missing.insert(label, color);
                            current = current->m_parent;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for (int row = 0; row < rows; ++row)
                image[row * stride + column] = color;
        }
    }
}

// @f3 0x00a8d560 (community match, verified in this file)
struct LocalMap
{
    int* m_data;
    int m_flags;
    int m_count;
    LocalMap();
    ~LocalMap();
    int get(const char* key, int* out);
    int insert(const char* key, int value);
};
struct TlsAlloc
{
    void freeMem(void* p, int bytes, int tag);
};
extern int g_tlsIndex;
__declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long index);
void __cdecl ReserveTicks(void* arr, int count, int elemSize);
struct Ticks
{
    SampleNode** m_data;
    int m_count;
    int m_cap;
    Ticks() : m_data(0), m_count(0), m_cap(0x80000000)
    {}
    ~Ticks()
    {
        if ((m_cap & 0x80000000) == 0)
        {
            int cap = m_cap & 0x3fffffff;
            TlsAlloc* alloc = (TlsAlloc*)TlsGetValue((unsigned long)g_tlsIndex);
            alloc->freeMem(m_data, cap * 4, 0x17);
        }
    }
    int GetLogicalSize() const
    {
        return m_count;
    }
    SampleNode*& operator[](int i)
    {
        return m_data[i];
    }
    void clear()
    {
        m_count = 0;
    }
    void reserveExactly(int n)
    {
        ReserveTicks(this, n, 4);
    }
};
struct ColorPairRaw
{
    const char* m_name;
    unsigned int m_color;
};
struct ColorArray
{
    ColorPairRaw* m_data;
    int m_count;
    int m_cap;
};
// pdb: drawNumber | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_dedup, low, conflict (bridge: drawStatistics)
static __declspec(noinline) void FUN_00e0daf0(const Se0e0c0_FrameInfo& info, int frame,
    const Se0e0c0_ArrayBase<Se0e0c0_Node*>& trees, int* image, int rows,
    Se0e0c0_ColorTable* colors, int stride, int samples, float duration,
    float start, Se0e0c0_PointerMap& missing)
{
    int color;
    LocalMap cache;
    float increment = duration / samples;
    Ticks ticks;
    if (samples > 0)
        ticks.reserveExactly(samples);
    if (trees[frame]->m_children.GetLogicalSize() > 0)
    {
        ticks.clear();
        int axis = info.m_uiTimer1 == 0 ? info.m_iColor : info.m_iTimer0;
        FUN_00e0cec0((SampleNode*)trees[frame], start, increment, samples, *(SampleArray<SampleNode*>*)&ticks, axis);
        int size = ticks.GetLogicalSize();
        for (int column = 0; column < size && column < samples; ++column)
        {
            color = 0xffffffff;
            if (ticks[column])
            {
                SampleNode* current = ticks[column];
                while (current)
                {
                    const char* label = current->m_name;
                    int tmp;
                    if (cache.get(label, &tmp) == 0)
                    {
                        color = tmp;
                        break;
                    }
                    int tmp2;
                    if (((LocalMap*)&missing)->get(label, &tmp2) == 0)
                    {
                        color = tmp2;
                        current = current->m_parent;
                        continue;
                    }
                    for (int entry = 0; entry < (*(ColorArray* volatile*)&colors)->m_count; ++entry)
                    {
                        ColorPairRaw& pair = (*(ColorArray* volatile*)&colors)->m_data[entry];
                        if (hkString_strCasecmp(pair.m_name, label) == 0)
                        {
                            color = (*(ColorArray* volatile*)&colors)->m_data[entry].m_color;
                            cache.insert(label, color);
                            goto fill;
                        }
                    }
                    ((LocalMap*)&missing)->insert(label, color);
                    current = current->m_parent;
                }
            }
        fill:
            for (int row = 0; row < rows; ++row)
                image[row * stride + column] = color;
        }
    }
}
volatile const Se0e0c0_FrameInfo* g_in_info;
volatile int g_in_frame;
volatile int g_in_trees;
volatile int g_in_image;
volatile int g_in_rows;
volatile int g_in_colors;
volatile int g_in_stride;
volatile int g_in_samples;
volatile float g_in_duration;
volatile float g_in_start;
volatile int g_in_missing;
void caller_of_FUN_00e0daf0()
{
    FUN_00e0daf0(*(const Se0e0c0_FrameInfo*)g_in_info, g_in_frame, *(const Se0e0c0_ArrayBase<Se0e0c0_Node*>*)g_in_trees, (int*)g_in_image, g_in_rows, (Se0e0c0_ColorTable*)g_in_colors, g_in_stride, g_in_samples, g_in_duration, g_in_start, *(Se0e0c0_PointerMap*)g_in_missing);
}

