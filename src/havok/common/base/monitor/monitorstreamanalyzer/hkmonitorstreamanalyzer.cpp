#include "f3_common.h"
// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Returns the smaller of the two float arguments.
// @fnv 0x00e0c260
// pdb: hkMonitorStreamAnalyzer::ThreadDrawInput::computePerThreadHeightToFit | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun_open, low
// pdb params: textureHeight, numFrames, numThreads, frameGap, threadGap
float __cdecl FUN_00e0c260(float a, float b)
{
    return (a < b) ? a : b;
}

// Returns the larger of the two float arguments.
// @fnv 0x00e0c290
// pdb: hkRoundUpPow2 | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun_open, low
float MaxFloat(float a, float b)
{
    return a > b ? a : b;
}

// @fnv 0x00e0c2c0
// pdb: hkRoundUpPow2 | hkMonitorStreamAnalyzer.obj | fnv360_0822_debug, objrun_sim, low
int FUN_00e0c2c0(int aiDividend, int aiDivisor, int c, int aiSubtrahend, int aiOffset, int aiUnused)
{
    return (aiDividend / aiDivisor - aiSubtrahend) / c - aiOffset;
}

// @fnv 0x00e0c2e0
unsigned int __fastcall RoundUpToNextPowerOfTwo(unsigned int uiValue)
{
    uiValue--;
    uiValue |= uiValue >> 1;
    uiValue |= uiValue >> 2;
    uiValue |= uiValue >> 4;
    uiValue |= uiValue >> 8;
    uiValue |= uiValue >> 16;
    return ++uiValue;
}

struct FUN_00e0f6e0
{
    int a;
    int b;
    int c;
    FUN_00e0f6e0();
};

// @fnv 0x00e0f6e0
FUN_00e0f6e0::FUN_00e0f6e0()
{
    a = 0;
    b = 0;
    c = 0x80000000;
}

// hkMonitorStreamAnalyzer: m_data (an hkArray<char>) at +0x0C (New Vegas Xbox 360 PDB).
struct FUN_00e0c310_s
{
    char m_frameInfos[0xC];
    int m_dataBegin;  // +0x0C m_data.m_data
    int m_dataSize;   // +0x10 m_data.m_size
    int FUN_00e0c310();
};

// @fnv 0x00e0c310
// pdb: hkMonitorStreamAnalyzer::getStreamBegin | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun_open, low
int FUN_00e0c310_s::FUN_00e0c310()
{
    if (m_dataSize == 0)
        return 0;
    return m_dataBegin;
}

struct SubObject
{
    virtual void* unk00();
    virtual void* unk04();
    virtual void* unk08();
    virtual void* unk0c();
    virtual void __thiscall invoke(int* value, int mode);
};
struct FUN_00cc01a0_class
{
    int unk00;
    int unk04;
    SubObject* unk08;
    FUN_00cc01a0_class* __thiscall InvokeSubObject(int value);
};
// @fnv 0x00cc01a0
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, call_dedup, low
// pdb params: c
FUN_00cc01a0_class* __thiscall FUN_00cc01a0_class::InvokeSubObject(int value)
{
    unk08->invoke(&value, 1);
    return this;
}

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
// pdb: hkMonitorStreamAnalyzer::extractStringMap | hkMonitorStreamAnalyzer.obj | fnv360_0822_debug, objrun, low
// pdb params: frameStart, frameEnd, map
void Bins::Accumulate(AxisData* pAxisData, Point* start, Point* end)
{
    unsigned int x = pAxisData->xIndex;
    if (x <= 7)
    {
        weights[x] += (float)(end->x - start->x) * pAxisData->xScale;
        ++counts[x];
    }
    unsigned int y = pAxisData->yIndex;
    if (y <= 7)
    {
        weights[y] += (float)(end->y - start->y) * pAxisData->yScale;
        ++counts[y];
    }
    unsigned int mode = pAxisData->mode;
    if (mode == 0)
        value = (double)start->x * pAxisData->xScale;
    else if (mode == 1)
        value = (double)start->y * pAxisData->yScale;
}

struct Node
{
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float value6;
    float value7;
    unsigned short flag0;
    unsigned short flag1;
    unsigned short flag2;
    unsigned short flag3;
    unsigned short flag4;
    unsigned short flag5;
    unsigned short flag6;
    unsigned short flag7;
    Node** children;
    int childCount;
};
// Multiplies the value at index by factor, clears the matching flag, and recurses into all children.
// @fnv 0x00e0c700
// pdb: reduceMainTree | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkDefaultMemoryTracker::addTypeDefinition)
void __cdecl FUN_00e0c700(Node* node, int index, float factor)
{
    (&node->value0)[index] *= factor;
    (&node->flag0)[index] = 0;
    for (int i = 0; i < node->childCount; ++i)
        FUN_00e0c700(node->children[i], index, factor);
}

extern "C" int __cdecl hkString_strLen(const char* str);

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
// pdb: hkMonitorStreamAnalyzer::findMaxTimerNameIndent | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_dedup, low
// pdb params: node, recursionDepth, spacing, displayPartialTree
int __cdecl GetTreeWidth(E0C860Node* node, int depth, int indent, bool onlyExpanded)
{
    int width = hkString_strLen(node->m_name) + depth * indent + 8;
    if (!onlyExpanded || (node->m_flags & 1))
    {
        for (int i = 0; i < node->m_children.GetLogicalSize(); i++)
        {
            int childWidth = GetTreeWidth(node->m_children[i], depth + 1, indent, onlyExpanded);
            if (childWidth > width)
                width = childWidth;
        }
    }
    return width;
}

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
void __cdecl FUN_00cb1260(void* dst, const void* src, int n);

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

struct S_e0ce00
{
    S_e0ce00_Array* m_arrays;
    int unk4;
    int unk8;
    char* m_buf;
    int m_iElementCount;
    int m_iCapacityState;
    S_e0ce00_Bool AppendBlock(const char* begin, const char* end, const S_e0ce00_Block& b);
};

// Appends a copy of the bytes from begin to end into m_buf at the current offset and records a block in m_arrays[b.unk18] with that offset and length.
// @f3 0x00a8c930 (community match, verified in this file)
void __cdecl FUN_00901f10(void* arr, int elemSize);
S_e0ce00_Bool S_e0ce00::AppendBlock(const char* begin, const char* end, const S_e0ce00_Block& aBlock)
{
    int n = end - begin;
    if ((m_iCapacityState & 0x3fffffff) - m_iElementCount < n)
        return false;
    S_e0ce00_Array& arr = m_arrays[aBlock.unk18];
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        FUN_00901f10(&arr, sizeof(S_e0ce00_Block));
    S_e0ce00_Block* nb = &arr.m_data[arr.m_iElementCount++];
    *nb = aBlock;
    nb->unk1C = m_iElementCount;
    nb->unk20 = nb->unk1C + n;
    int off = m_iElementCount;
    m_iElementCount = off + n;
    FUN_00cb1260(m_buf + off, begin, n);
    return true;
}


namespace fnv_00e0d0a0 {
struct Entry
{
    void __thiscall FUN_00ddeff0(unsigned int flags);
};
struct Device
{
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void ReleaseBuffer(void* p, unsigned int bytes);
};
void* __cdecl FUN_00c85750();
struct Owner
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
    Entry** items;
    int count;
    unsigned int flags;
    void ClearItems();
};
// Calls FUN_00ddeff0(1) on each non-null item, resets count, and releases the items buffer via the device unless the high flag bit is set.
// @fnv 0x00e0d0a0
void Owner::ClearItems()
{
    int index = 0;
    int zero = 0;
    if (count > 0)
    {
        do
        {
            Entry* entry = items[index];
            if (entry != 0)
                entry->FUN_00ddeff0(1);
            ++index;
        } while (index < count);
    }
    count = zero;
    void* holder = FUN_00c85750();
    Device* device = *(Device**)((char*)holder + 0x10);
    unsigned int mask = 0x80000000;
    unsigned int value = flags;
    count = zero;
    if ((mask & value) == 0)
    {
        unsigned int bytes = (value & 0x3fffffff) * 4;
        device->ReleaseBuffer(items, bytes);
    }
    flags = mask;
    items = 0;
}
}  // namespace fnv_00e0d0a0

extern "C" void __cdecl FUN_00e0c700(void* object, int index, float amount);
// Calls FUN_00e0c700 on first, then FUN_00e0d180 on first and second with index, limit and amount.
// @f3 0x00a8d310 (community match, verified in this file)
__declspec(noinline) void __cdecl FUN_00a8c360(void* first, int index, float amount)
{
    float* pValues = (float*)first;
    pValues[index] = pValues[index] * amount;
}

extern "C" void __cdecl FUN_00a8d1f0(void* first, void* second, int index, int limit, float amount);

// pdb: hkMonitorStreamAnalyzer::mergeTreesForCombinedThreadSummary | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: mainTree, subTree, destTimerId, sourceTimerId, smoothingFactor
void __cdecl FUN_00e0d280(void* first, void* second, int index, int limit, float amount)
{
    FUN_00a8c360(first, index, amount);
    FUN_00a8d1f0(first, second, index, limit, amount);
}


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

struct E0C150TgaHeader
{
    unsigned char m_idLength;
    unsigned char m_colorMapType;
    unsigned char m_imageType;
    unsigned char m_colorMapStartLo;
    unsigned char m_colorMapStartHi;
    unsigned char m_colorMapLengthLo;
    unsigned char m_colorMapLengthHi;
    unsigned char m_colorMapDepth;
    unsigned char m_xOriginLo;
    unsigned char m_xOriginHi;
    unsigned char m_yOriginLo;
    unsigned char m_yOriginHi;
    unsigned short m_fMaxFriction;
    unsigned short m_height;
    unsigned char m_bitsPerPixel;
    unsigned char m_descriptor;
};

struct E0C150Stream
{
    int write(const void* buf, int nbytes);
};

// Builds a 32-bit uncompressed TGA header from width and height, writes the header and pixel data to the stream, and returns true.
// @fnv 0x00e0c150
// pdb: saveToTGA | hkMonitorStreamAnalyzer.obj | fnv360_0822_debug, caller_sim, medium
// pdb params: data, s, width, height
bool __cdecl WriteTgaImage(const void* pixels, E0C150Stream* stream, int width, int height)
{
    E0C150TgaHeader header;
    FUN_00cb1280(&header, 0, sizeof(header));
    header.m_imageType = 2;
    header.m_height = (unsigned short)height;
    header.m_fMaxFriction = (unsigned short)width;
    header.m_bitsPerPixel = 32;
    stream->write(&header, sizeof(header));
    stream->write(pixels, width * height * 4);
    return true;
}

class FUN_00e0c320_cls
{
  public:
        const char* m_heading;
    int m_indexOfTimer0;
    int m_indexOfTimer1;
    int m_absoluteTimeCounter;
    float m_timerFactor0;
    float m_timerFactor1;
    int m_threadId;
    int m_frameStreamStart;
    int m_frameStreamEnd;
    FUN_00e0c320_cls* InitHeading();
};

// @fnv 0x00e0c320
// pdb: hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun_prop, low
FUN_00e0c320_cls* FUN_00e0c320_cls::InitHeading()
{
        float one = 1.0f;
        // Open: the factors are stored through pointers taken first. Written as plain member stores (or as the SDK's
    // constructor initialiser list) the compiler moves both float stores ahead of the heading; 0x00a8bf60 stores them
    // in member order, so the original's form is still to be found.
    float* timerFactor0 = &m_timerFactor0;
    float* timerFactor1 = &m_timerFactor1;
    m_heading = "Unknown Heading";
    m_indexOfTimer0 = 0;
    m_indexOfTimer1 = 1;
    m_absoluteTimeCounter = 0;
    *timerFactor0 = one;
    *timerFactor1 = one;
    m_threadId = 0;
    m_frameStreamStart = 0;
    m_frameStreamEnd = 0;
    return this;
}

struct S_00e0c750_Keys
{
    bool m_vStart;
    bool m_down;
    bool m_fMinimumU;
    bool m_fMaximumU;
};

struct S_00e0c750_Node
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
    S_00e0c750_Node** m_children;
    int m_numChildren;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S_00e0c750_Node* m_parent;
    const char* m_name;
    unsigned int m_expanded : 1;
};

// Moves from node p through the tree according to the keys flags (up, down, collapse, expand) and returns the resulting node.
// @fnv 0x00e0c750
// pdb: hkMonitorStreamAnalyzer::navigateMonitors | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun, medium
// pdb params: keys, activeNodeIn
S_00e0c750_Node* __cdecl NavigateTree(const S_00e0c750_Keys* keys, S_00e0c750_Node* pNode)
{
    S_00e0c750_Node* parent;
    parent = pNode;
    if (pNode == 0)
    {
        return 0;
    }
    if (keys->m_vStart)
    {
        S_00e0c750_Node* pParent;
        pParent = pNode->m_parent;
        S_00e0c750_Node* prev = pParent->m_children[0];
        if (prev != pNode)
        {
            for (int i = 0; i < pParent->m_numChildren; ++i)
            {
                if (pParent->m_children[i] == pNode)
                {
                    prev = pParent->m_children[i - 1];
                    break;
                }
            }
            while (prev->m_numChildren > 0 && prev->m_expanded)
            {
                prev = prev->m_children[prev->m_numChildren - 1];
            }
            parent = prev;
        }
        else if (pParent->m_parent)
        {
            parent = pParent;
        }
    }
    if (keys->m_down)
    {
        S_00e0c750_Node* c;
        c = parent;
        if (parent->m_numChildren > 0 && parent->m_expanded)
        {
            parent = parent->m_children[0];
        }
        else
        {
            for (;;)
            {
                for (int i = 0; i < c->m_parent->m_numChildren; ++i)
                {
                    if (c->m_parent->m_children[i] == c)
                    {
                        if (i < c->m_parent->m_numChildren - 1)
                        {
                            parent = c->m_parent->m_children[i + 1];
                            goto done_down;
                        }
                    }
                }
                if (!c->m_parent->m_parent)
                {
                    break;
                }
                c = c->m_parent;
            }
        done_down:;
        }
    }
    if (keys->m_fMinimumU)
    {
        if (parent->m_expanded)
        {
            parent->m_expanded = 0;
        }
        else if (parent->m_parent->m_parent)
        {
            parent = parent->m_parent;
            parent->m_expanded = 0;
        }
    }
    if (keys->m_fMaximumU)
    {
        if (0 == parent->m_expanded)
        {
            parent->m_expanded = 1;
        }
        parent->m_expanded = 1;
    }
    return parent;
}

struct E0CC40Node
{
    float m_iSlotIds[16];
    double m_base;
};

E0CC40Node* __cdecl FUN_00e10820(E0CC40Node* node, double time, int axis);

// Walks down from hint (or root if hint is null or its axis value plus base is below time) via FUN_00e10820 until no child is returned, then returns the node.
// @fnv 0x00e0cc40
// pdb: getNodeAtSample | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: currentNode, lastHit, sampleTime, absoluteTimeIndex
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

struct Sink
{
    void FUN_00cb1870(void* a, int b, int c);
};

// @f3 0x00a8c190 (community match, verified in this file)
struct Sink922710
{
    void FUN_00922710(unsigned int a, unsigned int b);
};

// pdb: hkMonitorStreamAnalyzer::reset | hkMonitorStreamAnalyzer.obj | fnv360_0822_debug, objrun, medium
void __cdecl ProcessRecords(unsigned char* pRecords, unsigned char* end, Sink* sink)
{
    unsigned char* lim = *(unsigned char* volatile*)&end;
    unsigned char* p = *(unsigned char* volatile*)&pRecords;
    if (p >= lim)
        return;
    while (p < lim)
    {
        if (*(unsigned int*)p < 0xa)
        {
            p += 4;
            continue;
        }
        Sink922710* s = (Sink922710*)sink;
        s->FUN_00922710(*(unsigned int*)p, *(unsigned int*)p);
        switch (*(char*)*(unsigned int*)p)
        {
        case 'E':
        case 'S':
        case 'T':
        case 'l':
            p += 12;
            break;
        case 'L':
        {
            unsigned int w = *(unsigned int*)(p + 12);
            s->FUN_00922710(w, w);
            p += 16;
            break;
        }
        case 'M':
            p += 8;
            break;
        case 'N':
        case 'P':
        case 'p':
            p += 4;
            break;
        default:
            return;
        }
    }
}


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

void* __cdecl FUN_00e0ee00(void* apSelf, int aIndex, S_Flag aFlag);

extern "C" int __cdecl FUN_00cb0fa0(int a, unsigned int b);

struct Node_e0c8e0
{
    float values[8];
    unsigned short counts[8];
    Node_e0c8e0** children;
    int childCount;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
};

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

// Writes the node name, maximum nonzero count, and scaled values to stream, then processes each child at depth + 1.
// @f3 0x00a8c550 (community match, verified in this file)
// pdb: hkWriteRec | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap, medium
void __cdecl FUN_00e0c8e0(void* stream, Node_e0c8e0* item, int depth, float scale)
{
    if (depth != 0)
    {
        if (depth > 1)
        {
            int n = depth - 1;
            do
            {
                FUN_00cc0410(stream, "\t");
                --n;
            } while (n != 0);
        }

        unsigned short* pCounts = item->counts;
        int maxv = 0;
        int iNonZero = 0;
        if (item->counts[0] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[0] > maxv)
                maxv = (int)item->counts[0];
        }
        if (item->counts[1] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[1] > maxv)
                maxv = (int)item->counts[1];
        }
        if (item->counts[2] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[2] > maxv)
                maxv = (int)item->counts[2];
        }
        if (item->counts[3] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[3] > maxv)
                maxv = (int)item->counts[3];
        }
        if (item->counts[4] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[4] > maxv)
                maxv = (int)item->counts[4];
        }
        if (item->counts[5] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[5] > maxv)
                maxv = (int)item->counts[5];
        }
        if (item->counts[6] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[6] > maxv)
                maxv = (int)item->counts[6];
        }
        if (item->counts[7] != 0)
        {
            ++iNonZero;
            if ((int)item->counts[7] > maxv)
                maxv = (int)item->counts[7];
        }

        if (maxv <= 1)
            FUN_00cc0410(stream, "%-12s    ", item->name);
        else if (scale == 1.0f)
            FUN_00cc0410(stream, "%-12s(%i) ", item->name, maxv);
        else
            FUN_00cc0410(stream, "%-12s(%4.1f) ", item->name, scale * maxv);

        if (iNonZero > 0)
        {
            int remaining = iNonZero;
            const unsigned short* p = pCounts;
            for (int i = 0; i < 8; ++i, ++p)
            {
                int c = *p;
                if (c != 0)
                {
                    float v = item->values[i] * scale;
                    if (c < maxv)
                        v *= (float)maxv / (float)c;
                    if (--remaining)
                        FUN_00cc0410(stream, "%4.3f: ", v);
                    else
                        FUN_00cc0410(stream, "%4.3f\n", v);
                }
            }
        }
        else
            FUN_00cc0410(stream, "%4.3f\n", 0.0f);
    }

    for (int i = 0; i < item->childCount; ++i)
        FUN_00e0c8e0(stream, item->children[i], depth + 1, scale);
}


int __cdecl FUN_00cb0fa0(int a, int b);

void __cdecl FUN_00e0e470(void* array, void* name, void* owner, int argument, int flags);
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
struct Owner830
{
    void* data;
    int count;
    void FUN_00e0f5e0(void* name, int argument);
};
// Builds a TempArray830 of item pointers from count, calls FUN_00e0e470, then clears and frees each item and releases the array.
// @f3 0x00a8f000 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long idx);
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
struct ArenaB0582
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    void* unk68;
    int unk6c;
    void Free(int a, void* p, int b);
    void FreeArr(void* p, int bytes, int b);
};
struct ItemB0582 { void ClearItems(); };
struct TmpB0582
{
    void** data;
    int size;
    int capacity;
    void* local[6];
};
void __cdecl Grow0582(TmpB0582* a, int count, int size);
void* __cdecl Elem0582(void* self, int i, S_Flag f);
void __cdecl Proc0582(TmpB0582* a, void* name, void* owner, int argument, int flags);
__forceinline void FreeItem(void* p)
{
    ArenaB0582* a = (ArenaB0582*)TlsGetValue(DAT_010f3170);
    if (a->unk6c >= a->unk34)
        a->Free(6, p, 0x1b);
    else
    {
        void* head = a->unk68;
        a->unk6c++;
        *(void**)p = head;
        a->unk68 = p;
    }
}
__forceinline void FreeBuf(void* p, int bytes)
{
    ArenaB0582* a = (ArenaB0582*)TlsGetValue(DAT_010f3170);
    a->FreeArr(p, bytes, 0x17);
}
// pdb: hkMonitorStreamAnalyzer::drawThreadsToTga | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: input, outStream
void Owner830::FUN_00e0f5e0(void* name, int argument)
{
    TmpB0582 temp;
    temp.data = temp.local;
    temp.size = 0;
    temp.capacity = 0x80000006;
    int iCount = count;
    if (6 < iCount)
    {
        int newCap = iCount < 12 ? 12 : iCount;
        Grow0582(&temp, newCap, 4);
    }
    temp.size = iCount;
    for (int i = 0; i < iCount; i++)
    {
        temp.data[i] = Elem0582(this, i, S_Flag());
    }
    Proc0582(&temp, name, this, argument, 0);
    void* (__stdcall* tls)(unsigned long) = DAT_00d9b080;
    for (int j = 0; j < iCount; j++)
    {
        ItemB0582* p = (ItemB0582*)temp.data[j];
        if (p)
        {
            p->ClearItems();
            ArenaB0582* a = (ArenaB0582*)tls(DAT_010f3170);
            if (*reinterpret_cast<volatile int*>(&a->unk6c) >= a->unk34)
                a->Free(6, p, 0x1b);
            else
            {
                void* head = a->unk68;
                a->unk6c++;
                *(void**)p = head;
                a->unk68 = p;
            }
        }
    }
    if ((temp.capacity & 0x80000000u) == 0)
    {
        int n = temp.capacity & 0x3fffffff;
        ArenaB0582* a = (ArenaB0582*)tls(DAT_010f3170);
        a->FreeArr(temp.data, n * 4, 0x17);
    }
}


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

extern unsigned int DAT_011bdea0[];

extern "C" unsigned int e0c1c0_tblidx(void);
extern volatile int g_e0c1c0_stride;
extern unsigned int* volatile g_e0c1c0_out;

// @fnv 0x00e0c1c0
static __declspec(noinline) void FUN_00e0c1c0(unsigned int aiIndex, int stride, unsigned int* out)
{
    unsigned int* entry = (unsigned int*)((unsigned int* volatile*)DAT_011bdea0)[aiIndex];
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

void e0c1c0_caller(void)
{
    FUN_00e0c1c0(e0c1c0_tblidx(), g_e0c1c0_stride, g_e0c1c0_out);
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

// Computes four decimal digits from thousands through ones, passing each to FUN_00e0c1c0 and advancing out by seven integers.
// @fnv 0x00e0c210
void __cdecl FUN_00e0c210(int value, S00e0c210_Obj* self, int* out)
{
    int place = 1000;
    int* cur = out;
    S00e0c210_Obj** ppSelf = &self;
    int ten = 10;
    do
    {
        int quotient = value / place;
        int digit = quotient % ten;
        FUN_00e0c1c0(*ppSelf, digit, cur);
        place /= 10;
        cur += 7;
    } while (place >= 1);
}

union CommandWord
{
    unsigned int tag;
    const char* name;
};
struct CommandTimingEntry
{
    CommandWord command;
    unsigned int time0;
    unsigned int time1;
};
struct NamedCommand
{
    CommandWord command;
    unsigned int time0;
    unsigned int time1;
    CommandWord object;
};
struct ValueCommand
{
    CommandWord command;
    float value;
};
struct SomeMap
{
    int __thiscall LookupBucketValue(unsigned int key, const char** out);
};

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

template <typename T> __forceinline T doSwap(T val)
{
    union
    {
        T val;
        unsigned int u;
        unsigned char b[4];
    } in, out;
    in.val = val;
    out.b[0] = (unsigned char)(in.u >> 24);
    out.b[1] = (unsigned char)(in.u >> 16);
    out.b[2] = (unsigned char)(in.u >> 8);
    out.b[3] = (unsigned char)(in.u);
    return out.val;
}

template <class T> __forceinline void swapInPlace(T& val)
{
    union
    {
        T val;
        unsigned int u;
    } in;
    union
    {
        T val;
        unsigned char b[4];
    } out;
    in.val = val;
    out.b[0] = (unsigned char)(in.u >> 24);
    out.b[1] = (unsigned char)(in.u >> 16);
    out.b[2] = (unsigned char)(in.u >> 8);
    out.b[3] = (unsigned char)in.u;
    val = out.val;
}
__forceinline bool isSmallTag(CommandWord* c, unsigned int tag, hkBool swap)
{
    if (!swap)
    {
        if (tag >= 10)
            return false;
        return true;
    }
    unsigned int s = doSwap(tag);
    if (s < 10)
    {
        c->tag = s;
        return true;
    }
    return false;
}
// Walks a command buffer, resolves command and object tags to names via map, and byte-swaps timing and value fields when needed.
// @f3 0x00a8bf90 (community match, verified in this file)
// pdb: hkMonitorStreamAnalyzer::Node::setTimers | hkMonitorStreamAnalyzer.obj | fnv360_0822_debug, objrun, low
// pdb params: frameInfo, start, end
void __cdecl FUN_00e0c350(char* apBuffer, const char* end, SomeMap* map, hkBool swapBytes)
{
    if (apBuffer >= end)
        return;
loop:
    unsigned int tag = ((CommandWord*)apBuffer)->tag;
    if (!isSmallTag((CommandWord*)apBuffer, tag, swapBytes))
        goto do_command;
advance:
    apBuffer += 4;
next:
    if (apBuffer < end)
        goto loop;
    return;
do_command:
    const char* str;
    if (map->LookupBucketValue(tag, &str) != 0)
    {
        return;
    }
    ((CommandWord*)apBuffer)->name = str;

    switch (str[0])
    {
    case 'E':
    case 'S':
    case 'T':
    case 'l': {
        char* cur = apBuffer;
        apBuffer += 12;
        if (swapBytes)
        {
            swapInPlace(((CommandTimingEntry*)cur)->time0);
            swapInPlace(((CommandTimingEntry*)cur)->time1);
        }
        goto next;
    }
    case 'F':
    case 'N':
    case 'P':
    case 'p':
        goto advance;

    case 'L': {
        char* cur = apBuffer;
        apBuffer += 16;
        unsigned int key = ((NamedCommand*)cur)->object.tag;
        const char* pObjectName;
        if (map->LookupBucketValue(key, &pObjectName) == 0)
        {
            ((NamedCommand*)cur)->object.name = pObjectName;
        }
        if (swapBytes)
        {
            swapInPlace(((CommandTimingEntry*)cur)->time0);
            swapInPlace(((CommandTimingEntry*)cur)->time1);
        }
        goto next;
    }
    case 'M': {
        char* cur = apBuffer;
        apBuffer += 8;
        if (swapBytes)
        {
            swapInPlace(((ValueCommand*)cur)->value);
        }
        goto next;
    }
    default:
        return;
    }
}


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
// Searches box->unk30 for a RecEntry whose unk4c matches name.unk00, returning the first match or the first entry when flag is set and no match is found.
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
void __cdecl ext_free(int);
int __cdecl ext_init(int, const char*, int);
__declspec(noinline) AggObj* AggObj::FUN_00e0d000(int a, const char* name, int b)
{
    unk00 = ext_init(a, name, b);
    return this;
}
__declspec(noinline) void AggObj::ClearItems()
{
    ext_free(unk00);
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
void __cdecl ext_show(void*, int, int, float);
__declspec(noinline) void __cdecl FUN_00e0c8e0(void* stream, void* agg, int a, float f)
{
    ext_show(stream, ((AggObj*)agg)->unk08, a, f);
}
void __cdecl FUN_00e0d280(void* first, void* second, int index, int limit, float amount);

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

// Searches m_pEntries for a case-insensitive key match and returns its value, or m_iFallback if not found.
// @f3 0x00a8c8b0 (community match, verified in this file)
// pdb: hkMonitorStreamColorTable::findColor | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: hkxEnum::getValueOfName)
// pdb params: color
int FUN_00e0cc90_cls::FUN_00e0cc90(int key)
{
    Entry*& entries = *reinterpret_cast<Entry**>(&unk00);
    for (int index = 0; index < unk04; ++index)
    {
        Entry* entry = &entries[index];
        if (hkString_strCasecmp(entry->key, key) == 0)
            return entries[index].value;
    }
    return -1;
}


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

struct PrintArray
{
    char* data;
    int size;
    int m_iCapacity;
};

struct PrintStream
{
    int unk00;
    short unk04;
    short unk06;
    int unk08;
    void __thiscall FUN_00cc0630(PrintArray* a1);
    void __thiscall InvokeSubObject(char a1);
    void __thiscall FUN_00cc01c0(const char* a1);
    void __thiscall FUN_00cc00e0();
};

struct PrintNode
{
    float values[8];
    unsigned short counts[8];
    PrintNode** children;
    int childCount;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
    unsigned int flags;
};

struct PrintConfig
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool unk10;
    PrintNode* unk14;
    char unk18;
    char unk19;
    bool unk1a;
};

// Recursively prints a PrintNode and its children to a PrintStream, formatting values, counts, and averages with configurable spacing.
// @f3 0x00a8c9e0 (community match, verified in this file)
// 0x00a8c9e0: monitor stream analyzer, prints one node of the combined per-thread
// summary (indent, tree marker, name with the summed call count, one timing column
// per thread and per SPU, then the two averages) and recurses into the children.
// The line is built in a local character array through a local stream.
namespace cand_a8c9e0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;

struct ThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static ThreadMemory* getInstance()
    {
        return (ThreadMemory*)TlsGetValue(DAT_010f3170);
    }
};

template <class T> struct Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~Array()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            ThreadMemory::getInstance()->FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
    }
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T* begin() { return m_data; }
};

struct Ostream
{
    int unk00;
    short unk04;
    short unk06;
    int unk08;
    Ostream(Array<char>& buffer) throw();
    ~Ostream() throw();
    Ostream& operator<<(char c) throw();
    Ostream& operator<<(const char* s) throw();
    void __cdecl printf(const char* format, ...) throw();
};

}

// pdb: hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_dedup, low
// pdb params: os, node, recursionDepth, numThreads, numSpus, options
void __cdecl FUN_00e0d2c0(PrintStream* stream, PrintNode* node, int depth, const int threads, const int spus,
                          PrintConfig* apConfig) throw()
// Fake match: the empty exception specification on this definition stands in for the
// original's exceptions-off build. Without it the recursive call counts as one that may
// throw under the pack's /EHsc and the two locals' destructors get an unwind frame; the
// same file without it matches under /MT /O2 /GS /EHs-c- /Gy.
{
    using namespace cand_a8c9e0;
    Ostream& os = *(Ostream*)stream;
    Array<char> textLine;
    Ostream lineOs(textLine);
    int numFields = threads + spus;
    if (depth != 0)
    {
        if (apConfig->unk10)
        {
            lineOs << (apConfig->unk14 == node ? apConfig->unk18 : ' ');
        }
        int spacing = apConfig->unk08 * (depth - 1);
        for (int k = 0; k < spacing; ++k)
            lineOs << ' ';
        if (apConfig->unk10)
        {
            if (0 < node->childCount)
            {
                lineOs << ((node->flags & 1) ? apConfig->unk19 : apConfig->unk18);
            }
            else
            {
                lineOs << ' ';
            }
        }
        int sumCounts = 0;
        for (int i = 0; i < numFields; ++i)
            sumCounts += node->counts[i];
        lineOs.printf("%s (%i) ", node->name, sumCounts);

        float threadTotal = 0.0f;
        float spuTotal = 0.0f;
        int threadCount = 0;
        int spuCount = 0;
        for (int i = 0; i < numFields; ++i)
        {
            int extra = (depth - 1) * apConfig->unk0c + apConfig->unk04 * i - textLine.getSize() + apConfig->unk00;
            for (int k = 0; extra > k; ++k)
                lineOs << ' ';
            lineOs.printf("%-6.3f (%i)", node->values[i], node->counts[i]);
            if (i < threads)
            {
                threadTotal += node->values[i];
                threadCount += node->counts[i];
            }
            else
            {
                spuTotal += node->values[i];
                spuCount += node->counts[i];
            }
        }
        int column = numFields;
        if (threads > 1)
        {
            int extra = apConfig->unk0c * (depth - 1) + apConfig->unk04 * column - textLine.getSize() + apConfig->unk00;
            for (int k = 0; k < extra; ++k)
                lineOs << ' ';
            column += 1;
            lineOs.printf("%-6.3f (%i)", threadTotal / threads, threadCount);
        }
        if (spus > 1)
        {
            int extra = apConfig->unk0c * (depth - 1) + apConfig->unk04 * column - textLine.getSize() + apConfig->unk00;
            for (int k = 0; k < extra; ++k)
                lineOs << ' ';
            lineOs.printf("%-6.3f (%i)", spuTotal / spus, spuCount);
        }
        os << textLine.begin();
        os << '\n';
    }
    if (!apConfig->unk10 || (node->flags & 1))
    {
        for (int i = 0; i < node->childCount; ++i)
            FUN_00e0d2c0(stream, node->children[i], depth + 1, threads, spus, apConfig);
    }
}


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
// Fills startTimes with per-frame minimum node values, computes maxFrameTime, applies a start offset, and adjusts maxFrameTime for single-frame cases.
// @f3 0x00a8d760 (community match, verified in this file)
extern double DAT_00e887b8; extern float DAT_00e887b0;
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);
extern float DAT_010660c0;
// pdb: hkMonitorStreamAnalyzer::getTimerLimits | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, uconst, low
// pdb params: nodeList, input, frameInfos, maxFrameTime, startTimes
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

    int oldSize = startTimes.m_iElementCount;
    int n = input.m_iFrameCount;
    if (n > oldSize) {
        int cap = startTimes.m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = cap * 2;
            if (n >= cap2) cap2 = n;
            FUN_00901e90(&startTimes, cap2, 4);
        }
        for (int i = oldSize; i < n; ++i) startTimes[i] = 0.0f;
    }
    startTimes.m_iElementCount = n;

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
    
    if (*(const volatile float*)&input.m_startTimeOffset > 0.0f) {
        for (int f = input.m_iValueAt00; f < frameEnd; ++f)
            startTimes[f - input.m_iValueAt00] = startTimes[f - input.m_iValueAt00] + input.m_startTimeOffset;
    }
    if (input.m_fValueAt18 > 0.0f)
    {
        maxFrameTime = input.m_fValueAt18;
        return;
    }
    if (numFramesToDraw == 1)
    {
        unsigned int ms = (unsigned int)(maxFrameTime / 1000.0);
        ms |= ms >> 1;
        ms |= ms >> 2;
        ms |= ms >> 4;
        ms |= ms >> 8;
        ms |= ms >> 16;
        ++ms;
        float upper = (float)(0.25 * DAT_010660c0);
        float rounded = (float)((float)ms * 1000.0);
        float target = hkMin2(upper, rounded - DAT_010660c0);
        maxFrameTime = (float)(target * 0.05000000074505806 + DAT_010660c0);
        float m = maxFrameTime;
        float r = (m < DAT_00e887b8) ? DAT_00e887b0 : m;
        maxFrameTime = r;
        DAT_010660c0 = r;
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
// Calls FUN_00e0e0c0, passes its output buffer and q to WriteTgaImage, then calls FUN_00c856c0 with the allocator and buffer.
// @f3 0x00a8dea0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
void __cdecl FUN_00a8db20(int a1, PixelSource* a2, int a3, void** out1, int* out2, int a6);
struct HkThreadMemoryF3
{
    void FUN_008f6f90(void* p);
};

// pdb: hkMonitorStreamAnalyzer::writeStatisticsDetailsToTga | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkDeepCopier::freeDeepCopy)
// pdb params: nodeList, input, frameInfos, outStream, sampleInfo
void __cdecl FUN_00e0e470(int a1, PixelSource* apPixelSource, int a3, E0C150Stream* apStream, int a5)
{
    void* out1 = 0;
    int q = 0;
    FUN_00a8db20(a1, apPixelSource, a3, &out1, &q, a5);
    void* p = *(void* volatile*)&out1;
    if (p != 0)
    {
        WriteTgaImage(p, apStream, apPixelSource->m_14, q);
        void* mem = TlsGetValue(DAT_010f3170);
        ((HkThreadMemoryF3*)mem)->FUN_008f6f90(p);
    }
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
// Collects and sorts report nodes, then writes per-type timing stats for nodes exceeding the threshold-scaled last node value.
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

// Initializes fields, registers this in apOwner's SubList if needed, and zeroes the m_af00/m_au20 arrays and m_d40.
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
struct FUN_00e0d640_cfg
{
    int m_iBase;
    int m_iStep;
    int m_iVal;
    int unk0C;
    unsigned char m_bFlag;
    char unk11[9];
    char m_bTab;
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
int GetTreeWidth(int a, int b, int c, int d);
void FUN_00cc0410(FUN_00e0d640_buf* b, const char* fmt, ...);
FUN_00e0d640_hold* FUN_00c85750();
void FUN_00e0d2c0(FUN_00e0d640_buf* a, int b, int c, int d, int e, FUN_00e0d640_cfg* f);

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

extern float DAT_01012054;

struct S00e0e4e0_FArr
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
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
struct S00e0e4e0_Entry
{
    S00e0e4e0_Info* m_info;
    int unk04;
    int unk08;
};
struct S00e0e4e0_EntryList
{
    S00e0e4e0_Entry* m_data;
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
struct S00e0e4e0_Layout
{
    int unk00;
    int m_numPages;
    int m_width0;
    int m_width1;
    int m_extra;
    int m_height;
};

void __cdecl FUN_00e0dd30(S00e0e4e0_NodeArr& img, S00e0e4e0_Layout* lay, S00e0e4e0_EntryList* list, float* f,
                          S00e0e4e0_FArr* out);
void __cdecl FUN_00c908c0(S_e0ce00_Alloc* alloc, void* arr, int n, int elemSize);
static __forceinline void S00e0e4e0_push(S00e0e4e0_PArr* out, void* v)
{
    S_e0ce00_Alloc& a = FUN_00c85750()->heap();
    if (out->m_iElementCount == (out->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&a, out, 4);
    out->m_data[out->m_iElementCount] = v;
    out->m_iElementCount++;
}

void __cdecl FUN_00e0cec0(float value, float step, int axis, S00e0e4e0_Node* node, int n, S00e0e4e0_PArr* out);

static __declspec(noinline) int FUN_00e0da00(int row, int col, const S00e0e4e0_NodeArr& nodes, int height, float range,
                                             float value, S00e0e4e0_Info* info)
{
    float step = range / height;
    S00e0e4e0_PArr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_iCapacityState = 0x80000000;
    S_e0ce00_Alloc& a = FUN_00c85750()->heap();
    if ((arr.m_iCapacityState & 0x3fffffff) < height)
        FUN_00c908c0(&a, &arr, height, 4);
    int res = 0;
    if (nodes[row]->m_children.GetLogicalSize() > 0)
    {
        arr.m_iElementCount = 0;
        FUN_00e0cec0(value, step, info->unk0c == 0 ? info->unk04 : info->unk08, nodes[row], height, &arr);
        if (col < arr.m_iElementCount)
            res = (int)arr.m_data[col];
    }
    S_e0ce00_Alloc& a2 = FUN_00c85750()->heap();
    arr.m_iElementCount = 0;
    if ((arr.m_iCapacityState & 0x80000000) == 0)
        a2.v10(arr.m_data, (arr.m_iCapacityState & 0x3fffffff) * sizeof(void*));
    return res;
}

// Resolves a slot id at pixel coordinates by mapping to a level and row, then querying the node tree via FUN_00e0da00.
// @fnv 0x00e0e4e0
int __cdecl FUN_00e0e4e0(int x, int y, S00e0e4e0_NodeArr& img, S00e0e4e0_Layout* lay, S00e0e4e0_EntryList* list)
{
    int numLevels = img.GetLogicalSize();
    int numPages = lay->m_numPages;
    if (numLevels < 1)
        return 0;
    int border = (numPages > 1) ? 0x20 : 0;
    if (x < border || x >= lay->m_height)
        return 0;
    int w = lay->m_width1 + lay->m_width0;
    int h = lay->m_height - border;
    int stride = w * numLevels + lay->m_extra;
    int total = stride * numPages;
    if (y < 0 || y >= total)
        return 0;
    int idx = total - y - 1;
    int row = idx / stride;
    int lvl = idx % stride / w;
    float range = DAT_01012054;
    S00e0e4e0_FArr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_iCapacityState = 0x80000000;
    FUN_00e0dd30(img, lay, list, &range, &arr);
    S00e0e4e0_Node** slot = &img.m_data[lvl];
    S00e0e4e0_Info* info = list->m_data[lvl].m_info;
    int res = FUN_00e0da00(row, x - border, (*slot)->m_children, h, range, arr.m_data[row], info);
    S_e0ce00_Alloc& a = FUN_00c85750()->heap();
    arr.m_iElementCount = 0;
    if ((arr.m_iCapacityState & 0x80000000) == 0)
        a.v10(arr.m_data, (arr.m_iCapacityState & 0x3fffffff) * sizeof(float));
    return res;
}

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
struct S00e0ee00_Root
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
    S00e0ee00_Children m_children;
    S00e0ee00_Root(int a, const char* name, int b);
};

struct S00e0ee00_Analyzer : public S_e0ce00
{
    S00e0ee00_Root* __cdecl FUN_00e0ee00(int aIndex, S_e0ce00_Bool aFlag);
};
// Allocates a root, sizes its children array to the selected array's size, and fills each slot with FUN_00e0e630's result.
// @f3 0x00a8e6b0 (community match, verified in this file)
namespace f3m_00a8e6b0 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long index);
extern unsigned long DAT_010f3170;
extern const char DAT_00dfa594[];
struct FreeBlock {
    FreeBlock* next;
};
struct ThreadMemory {
    char pad00[0x68];
    FreeBlock* m_freeList6;
    int m_freeCount6;
    void* FUN_008f6800(int row, int size);
};
inline void* AllocateChunk()
{
    ThreadMemory* memory = (ThreadMemory*)DAT_00d9b080(DAT_010f3170);
    FreeBlock* first = memory->m_freeList6;
    if (first) {
        --memory->m_freeCount6;
        memory->m_freeList6 = first->next;
        return first;
    }
    return memory->FUN_008f6800(6, 0x1b);
}
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);
struct NodeArray {
    E0C860Node** m_data;
    int m_size;
    int m_capacityAndFlags;
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void reserve(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(E0C860Node*));
        }
    }
    void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    E0C860Node*& operator[](int i) { return m_data[i]; }
};
struct FUN_00a8d060 {
    int unk00[12];
    NodeArray m_children;
    int unk3C[7];
    FUN_00a8d060(int a, const char* name, int b) throw();
    static void* operator new(unsigned int size, void* where) throw() { return where; }
};
E0C860Node* __cdecl FUN_00a8e070(char* begin, char* end, S_e0ce00_Block* block, int type, S_e0ce00_Bool flag);
}

S00e0ee00_Root* __cdecl S00e0ee00_Analyzer::FUN_00e0ee00(int aIndex, S_e0ce00_Bool aFlag)
{
    f3m_00a8e6b0::FUN_00a8d060* root = new (f3m_00a8e6b0::AllocateChunk()) f3m_00a8e6b0::FUN_00a8d060(0, f3m_00a8e6b0::DAT_00dfa594, 1);
    root->m_children.setSize(m_arrays[aIndex].m_iElementCount);
    for (int i = 0; i < m_arrays[aIndex].m_iElementCount; i++) {
        S_e0ce00_Block& b = m_arrays[aIndex].m_data[i];
        char* begin = m_buf + b.unk1C;
        char* end = m_buf + b.unk20;
        E0C860Node*& slot = root->m_children[i];
        slot = f3m_00a8e6b0::FUN_00a8e070(begin, end, &b, b.unk0, aFlag);
    }
    return (S00e0ee00_Root*)root;
}


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

// Appends nulls while the first node time is ahead, then appends lookup results at successive steps before the computed end bound.
// @f3 0x00a8cee0 (community match, verified in this file)
// Fills the output array with one node per time step: nulls until the first child starts, then the node found at each step.
void __cdecl FUN_00901f10(void* array, int elemSize);
template <class T> struct FrameNodeArray
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
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& value)
    {
        if (m_iElementCount == capacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_iElementCount] = value;
        ++m_iElementCount;
    }
};
// pdb: outputStatsForFrame | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
static __declspec(noinline) void FUN_00e0cec0(float start, float step, int axis, S00e0e4e0_Node* inputNode, int count, S00e0e4e0_PArr* output)
{
    MonNode* node = reinterpret_cast<MonNode*>(inputNode);
    FrameNodeArray<MonNode*>& out = *reinterpret_cast<FrameNodeArray<MonNode*>*>(output);
    MonNode* first = ((FrameNodeArray<MonNode*>&)node->m_children)[0];
    MonNode* last = ((FrameNodeArray<MonNode*>&)node->m_children).back();
    double leading = first->m_dValue - start;
    double t = 0.0;
    int n = count;
    while (n != 0 && leading > t)
    {
        t += step;
        out.AddBack(0);
        --n;
    }
    double end = last->m_uiFilterValue[axis] + last->m_dValue - start;
    node->m_dValue = first->m_dValue;
    node->m_uiFilterValue[axis] = (float)(start + end - node->m_dValue + 1.0);
    MonNode* hint = 0;
    while (n != 0 && t < end)
    {
        hint = (MonNode*)::FindNodeAtTime((E0CC40Node*)node, (E0CC40Node*)hint, t + start, axis);
        if (hint)
            out.AddBack(hint);
        t += step;
        --n;
    }
}
// Fake match: this caller exists only so the compiler emits the two static functions above it
// (the sampler takes its count, node and output array in registers, which needs internal linkage and a caller).
int EmitCaller_00a8cee0(int row, int column, const S00e0e4e0_NodeArr& nodes, int height, float range, float value, S00e0e4e0_Info* info)
{
    return FUN_00e0da00(row, column, nodes, height, range, value, info);
}

