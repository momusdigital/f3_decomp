#include "f3_common.h"
// src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct VirtualBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void Dispatch();
};
struct FUN_00ddf020_Class
{
    void __thiscall FUN_00ddf020();
};
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
};
struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* arr, int capacity, int elemSize);
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int n);
struct hkArrayChar
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void setData(const void* src, int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(&alloc, this, n < cap ? cap : n, 1);
        }
        m_iElementCount = n;
    }
};
union Swap16
{
    unsigned short u;
    unsigned char b[2];
};
inline void swap16(unsigned short* p)
{
    Swap16 in, out;
    in.u = *p;
    out.b[0] = in.b[1];
    out.b[1] = in.b[0];
    *p = out.u;
}
struct Record
{
    unsigned char type;
    unsigned char len;
    unsigned short a;
    unsigned short b;
};
struct hkBool
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct Obj
{
    int pad[5];
    hkArrayChar m14;
    void SetData(const void* src, int n, hkBool swap);
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
static int* FUN_00ddf370(hkArrayChar* a, int n);
int* __cdecl fnv_caller(hkArrayChar* a, int n);
inline void* operator new(size_t, void* p)
{
    return p;
}
struct MonitorNode;
struct MonitorChildren
{
    MonitorNode** data;
    int size;
    int capacity;
    void Search(void* heap, int index, MonitorNode** value, int count);
    __declspec(noinline) void CallWithFlag(void* heap, int index, MonitorNode** value)
    {
        Search(heap, index, value, 1);
    }
    MonitorNode*& back()
    {
        return data[size - 1];
    }
    void popBack()
    {
        --size;
    }
};
struct MonitorNode
{
    float value0, value1;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short count0, count1;
    int unk24, unk28, unk2c;
    MonitorChildren children;
    int unk3c, unk40, unk44, unk48;
    const char* name;
    int unk50, unk54;
    MonitorNode(MonitorNode* parent, const char* label, int type);
};
struct MonitorString
{
    unsigned int tagged;
    void FUN_00cb0b80(const char* s);
    void FUN_00cb0bd0(const MonitorString& s);
    void FUN_00cb0c00();
};
struct MonitorStrings
{
    MonitorString* data;
    int size;
    int capacity;
};
struct NodeAllocator
{
    virtual ~NodeAllocator();
    virtual void* allocate(int bytes);
};
extern "C" int __cdecl FUN_00cb0fa0(const char* a, const char* b);
static __declspec(noinline) MonitorNode* FUN_00ddf070(const char* name, MonitorStrings* strings, MonitorNode* parent,
                                                      int first, int second)
{
    if (!name)
        name = "?";
    if (!second)
        second = first;
    MonitorNode* node = 0;
    for (int i = 0; parent && i < parent->children.size; ++i)
    {
        if (!FUN_00cb0fa0(parent->children.data[i]->name, name))
        {
            node = parent->children.data[i];
            break;
        }
    }
    if (!node)
    {
        if (strings && name)
        {
            MonitorString text;
            text.FUN_00cb0b80(name);
            void* heap = audio()->unk10;
            if (strings->size == (strings->capacity & 0x3fffffff))
                ResizeAudioStream(heap, strings, 4);
            if (&strings->data[strings->size])
                strings->data[strings->size].FUN_00cb0bd0(text);
            ++strings->size;
            text.FUN_00cb0c00();
            name = (const char*)(strings->data[strings->size - 1].tagged & ~1u);
        }
        NodeAllocator* allocator = (NodeAllocator*)audio()->unk10;
        void* storage = allocator->allocate(sizeof(MonitorNode));
        node = storage ? new (storage) MonitorNode(parent, name, 1) : 0;
    }
    ++node->count0;
    node->value0 += (float)first;
    ++node->count1;
    node->value1 += (float)second;
    return node;
}
void __cdecl AggregateChildValues(MonitorNode* node, MonitorStrings* strings);
class hkMemoryAllocatorDDF9
{
  public:
    virtual ~hkMemoryAllocatorDDF9() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDDF9
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDDF9* m_pStreamAllocator;
    hkMemoryAllocatorDDF9& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDDF9 {
extern "C" hkMemoryRouterDDF9& __cdecl FUN_00c85750() throw();
}
template <class T> class hkArrayDDF9
{
  public:
    hkArrayDDF9() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayDDF9()
    {
        _clearAndDeallocate(hkRouterDDF9::FUN_00c85750().heap());
    }
    void _clearAndDeallocate(hkMemoryAllocatorDDF9& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class ObjDDF9
{
  public:
    ~ObjDDF9() throw()
    {
        ClearItems();
    }
    void ClearItems() throw();
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterDDF9::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
};
void __stdcall FUN_00ddf740(hkArrayDDF9<ObjDDF9*>& kArray, int iParam) throw();
void __stdcall ClearAllItems(int iUnused0, int iUnused1);
extern int DAT_010d8040;
struct SubBase
{
    void FUN_00d06f50(int a1);
};
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* v0C(int* pValue);
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AudioAllocator* m_pAllocator;
};
inline AudioHolder* holderGet()
{
    return (AudioHolder*)FUN_00c85750();
}
struct SpawnedHandle
{
    void* m_ptr;
    int m_uiFilterValue;
    unsigned int m_flags;
    SpawnedHandle()
    {}
    SpawnedHandle(void* p, int v, unsigned int f) : m_ptr(p), m_uiFilterValue(v), m_flags(f)
    {}
    void EnsureCapacity(void* allocator, int zero);
    int getCap() const
    {
        return (int)(m_flags & 0x3fffffff);
    }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorDDF9& alloc = hkRouterDDF9::FUN_00c85750().heap();
        if (getCap() < n)
        {
            int cap = 2 * getCap();
            FUN_00c908c0((hkMemoryAllocator*)&alloc, this, n < cap ? cap : n, 1);
        }
        m_uiFilterValue = n;
    }
};
struct FUN_00ddf170_cls
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedHandle m_14;
    SpawnedHandle m_20;

    FUN_00ddf170_cls* FUN_00ddf170(int a1, int a2);
};
int hkString_strLen(const char* s);
struct StrPacker
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkArrayChar m14;
    void FUN_00ddf5a0(const char* str);
};
struct S_00ddeff0_Heap
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int nbytes);
};
struct S_00ddeff0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddeff0_Heap* m_pStreamAllocator;
    static S_00ddeff0_Router* FUN_00c85750();
    S_00ddeff0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct FUN_00ddeff0
{
    int unk4;
    FUN_00ddeff0();
    virtual ~FUN_00ddeff0();
    void operator delete(void* p, unsigned int nbytes)
    {
        if (p)
            S_00ddeff0_Router::FUN_00c85750()->heap().ReleaseBlock(p, nbytes);
    }
    int unk8;
    int unkC;
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
};
struct FUN_00ddf640_Cls : Obj
{
    unsigned char* FUN_00ddf640();
};

struct MonitorHeap
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct MonitorTreeNode
{
    void ClearItems();
};

extern char DAT_01063cbc;

template <class T> __forceinline void constructRange(T* p, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        p[i] = value;
}

struct MonitorNodeArray
{
    MonitorNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    MonitorNodeArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~MonitorNodeArray()
    {
        hkMemoryAllocator& alloc = audio()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            ((MonitorHeap&)alloc).ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(MonitorNode*));
    }
    MonitorNode*& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }
    void pushBackPlacement(MonitorNode* const& e)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, 4);
        MonitorNode** p = m_data + m_iElementCount;
        constructRange(p, 1, e);
        m_iElementCount++;
    }
    void AddBack(MonitorNode* const& e)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, 4);
        m_data[m_iElementCount++] = e;
    }
};

struct MonitorTreeBuilder : Obj
{
    void FUN_00ddf740(MonitorNodeArray* roots, MonitorStrings* strings);
};

// @f3 0x00a651b0 (community match, verified in this file)
namespace na651b0 {
struct Block { Block* next; };
struct Bucket { Block* head; int count; };
struct ThreadMem {
    char pad[0x34];
    int maxFree;
    Bucket buckets[25];
    void* FUN_008f6800(int index, int tag);
    void FUN_008f6890(int index, void* p, int tag);
    void FUN_008f6d90(void* p, int nbytes, int tag);
};
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
static __forceinline ThreadMem* Mem() { return (ThreadMem*)TlsGetValue(DAT_010f3170); }
void __cdecl FUN_00901f10(void* arr, int elemSize);

struct FUN_00a8d060 {
    float value0, value1;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short count0, count1;
    int unk24, unk28, unk2c;
    FUN_00a8d060** childData;
    int childSize;
    int childCap;
    int unk3c, unk40, unk44, unk48;
    const char* name;
    int unk50, unk54;
    FUN_00a8d060(FUN_00a8d060* parent, const char* label, int type);
    static void* operator new(unsigned int size);
};
typedef FUN_00a8d060 Node;
struct NodeOps { void FUN_00a8d0f0(); };
struct Builder {
    int unk00, unk04, unk08, unk0c;
    char* m_data;
    int m_size;
};
void __cdecl FUN_00a650f0(Node* node, MonitorStrings* strings);

struct NodeStack {
    Node** m_data;
    int m_size;
    int m_cap;
    NodeStack() : m_data(0), m_size(0), m_cap(0x80000000) {}
    ~NodeStack()
    {
        if (!(m_cap & 0x80000000)) {
            int n = m_cap & 0x3fffffff;
            Mem()->FUN_008f6d90(m_data, n * sizeof(Node*), 0x17);
        }
    }
    Node*& back() { return m_data[m_size - 1]; }
    void push(Node* const& e)
    {
        if (m_size == (m_cap & 0x3fffffff))
            FUN_00901f10(this, 4);
        m_data[m_size] = e;
        m_size++;
    }
};

static __forceinline void* NodeAlloc()
{
    ThreadMem* mem = Mem();
    Block* b = mem->buckets[6].head;
    if (b) {
        mem->buckets[6].count += -1;
        mem->buckets[6].head = b->next;
        return b;
    }
    return mem->FUN_008f6800(6, 0x1b);
}
inline void* FUN_00a8d060::operator new(unsigned int)
{
    return NodeAlloc();
}
static __forceinline void NodeFree(void* p)
{
    ThreadMem* mem = Mem();
    Bucket* bk = &mem->buckets[6];
    if (bk->count >= mem->maxFree)
        mem->FUN_008f6890(6, p, 0x1b);
    else {
        mem->buckets[6].count++;
        ((Block*)p)->next = mem->buckets[6].head;
        mem->buckets[6].head = (Block*)p;
    }
}

struct Str {
    char* m_data;
    int m_size;
    int m_cap;
};
struct StrArray {
    Str** m_data;
    int m_size;
    int m_cap;
};
extern "C" int __cdecl hkString_strCmp(const char* a, const char* b);
extern "C" int __cdecl FUN_009233f0(const char* s);
extern "C" void __cdecl FUN_009234e0(char* dst, const char* src, int n);
extern "C" void __cdecl FUN_00901e90(void* arr, int capacity, int elemSize);
static __forceinline void* StrAlloc()
{
    ThreadMem* mem = Mem();
    Block* b = mem->buckets[2].head;
    if (b) {
        mem->buckets[2].count += -1;
        mem->buckets[2].head = b->next;
    } else
        b = (Block*)mem->FUN_008f6800(2, 0x16);
    return b;
}
static __declspec(noinline) Node* FUN_00a64f60(const char* name, Node* parent, int first, int second, StrArray* strings)
{
    if (!second)
        second = first;
    if (!name)
        name = "?";
    Node* node;
    if (parent) {
        for (int i = 0; i < parent->childSize; ++i) {
            Node** child = &parent->childData[i];
            if (!hkString_strCmp((*child)->name, name)) {
                node = parent->childData[i];
                if (node)
                    goto found;
                break;
            }
        }
    }
    if (name && strings) {
        Str* s = (Str*)StrAlloc();
        if (s) {
            s->m_data = 0;
            s->m_size = 0;
            s->m_cap = 0x80000000;
            int n = FUN_009233f0(name) + 1;
            int cap = s->m_cap & 0x3fffffff;
            if (cap < n) {
                cap *= 2;
                if (n >= cap)
                    cap = n;
                FUN_00901e90(s, cap, 1);
            }
            s->m_size = n;
            FUN_009234e0(s->m_data, name, n);
        } else
            s = 0;
        if (strings->m_size == (strings->m_cap & 0x3fffffff))
            FUN_00901f10(strings, 4);
        strings->m_data[strings->m_size] = s;
        strings->m_size++;
        name = strings->m_data[strings->m_size - 1]->m_data;
    }
    node = new Node(parent, name, 1);
found:
    node->value0 += (float)first;
    ++node->count0;
    ++node->count1;
    node->value1 += (float)second;
    return node;
}
}

// pdb: hkStreamStatisticsCollector::makeTree | hkStreamStatisticsCollector.obj | fnv360_0822_retail, call_seq, medium
// pdb params: m_nodesOut, stringTable
void MonitorTreeBuilder::FUN_00ddf740(MonitorNodeArray* roots, MonitorStrings* strings)
{
    using namespace na651b0;
    NodeStack stack;
    Node* top;
    if (roots->m_iElementCount > 0) {
        top = (Node*)roots->m_data[0];
        while (roots->m_iElementCount > 1) {
            Node* p = (Node*)roots->m_data[roots->m_iElementCount - 1];
            if (p) {
                ((NodeOps*)p)->FUN_00a8d0f0();
                NodeFree(p);
            }
            roots->m_iElementCount--;
        }
    } else {
        top = new Node(0, "/", 1);
        if (roots->m_iElementCount == (roots->m_iCapacityState & 0x3fffffff))
            FUN_00901f10(roots, 4);
        roots->m_data[roots->m_iElementCount] = (MonitorNode*)top;
        roots->m_iElementCount++;
    }
    stack.push(top);
    Builder* b = (Builder*)this;
    for (int off = 0; off < b->m_size;) {
        const Record* rec = (const Record*)(b->m_data + off);
        const char* name = rec->len > 0 ? (const char*)rec + 6 : 0;
        int step = rec->len + 6;
        switch (rec->type) {
        case 'p':
            stack.m_size--;
            break;
        case 'P': {
            Node* parent = stack.back();
            Node* child = FUN_00a64f60(name, parent, rec->a, rec->b, (StrArray*)strings);
            stack.push(child);
            break;
        }
        case 'C':
            FUN_00a64f60(name, stack.back(), rec->a, rec->b, (StrArray*)strings);
            break;
        default:
            return;
        }
        off += step;
    }
    FUN_00a650f0(top, strings);
}

