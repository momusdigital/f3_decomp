#include "f3_common.h"
// src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

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

// Copies n bytes from src into m14, then if swap is set byte-swaps the a and b fields of each record in the buffer.
// @f3 0x00a64a20 (community match, verified in this file)
extern "C" void __cdecl FUN_00901e90(void*,int,int);
struct NativeArray1355 {
 char* m_data; int m_iElementCount; int m_iCapacityState;
 int getCapacity() const {return m_iCapacityState&0x3fffffff;}
 void setData(const void* src,int n) {
  if(getCapacity()<n){int cap=2*getCapacity();FUN_00901e90(this,n<cap?cap:n,1);}
  m_iElementCount=n;
 }
};
struct NativeObj1355
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NativeArray1355 m14;

};

extern "C" void __cdecl FUN_00901e90(void* arr, int cap, int elem);

void Obj::SetData(const void* src, int n, hkBool swap)
{
    NativeObj1355* self=(NativeObj1355*)this;
    self->m14.setData(src,n);
    FUN_00cb1260(self->m14.m_data,src,n);
    NativeArray1355* arr=&self->m14;
    if (swap)
    {
        for (int i = 0; i < self->m14.m_iElementCount;)
        {
            Record* pRecord = (Record*)(arr->m_data + i);
            swap16(&pRecord->a);
            swap16(&pRecord->b);
            i += pRecord->len + 6;
        }
    }
}


namespace fnv_00ddfb40 {
struct MemoryAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void Free(void* memory, unsigned int size);
};
struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemoryAllocator* allocator;
};
extern AllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00ddfb40

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

// @f3 0x00a64bf0 (community match, verified in this file)
void __cdecl FUN_00901f10(hkArrayChar* a, int n);
namespace S_00a64bf0_ns { void __cdecl FUN_00901e90(hkArrayChar* a, int capacity, int elementSize); }

static inline void S_00a64bf0_SetSize(hkArrayChar* a, int n)
{
    int cap = a->getCapacity();
    if (cap < n)
    {
        int grown = cap * 2;
        S_00a64bf0_ns::FUN_00901e90(a, n < grown ? grown : n, 1);
    }
    a->m_iElementCount = n;
}

// pdb: hkStreamStatisticsCollector::setDataByCopying | hkStreamStatisticsCollector.obj | fnv360_0822_retail, objrun, low, conflict (bridge: _newCommand)
// pdb params: buffer, length, endianSwap
static __declspec(noinline) int* FUN_00ddf370(hkArrayChar* a, int n)
{
    int* slot;
    if (a->m_iElementCount > 0)
    {
        slot = (int*)(a->m_data + a->m_iElementCount);
    }
    else
    {
        if (a->m_iElementCount == a->getCapacity())
            FUN_00901f10(a, 1);
        slot = (int*)(a->m_data + a->m_iElementCount);
        a->m_iElementCount = a->m_iElementCount + 1;
        S_00a64bf0_SetSize(a, 0);
    }
    S_00a64bf0_SetSize(a, n + a->m_iElementCount + 6);
    return slot;
}


int* __cdecl fnv_caller(hkArrayChar* a, int n)
{
    return FUN_00ddf370(a, n);
}

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
// @f3 0x00a650f0 (community match, verified in this file)
extern const char DAT_00e86f18[];

struct NativeChildren1660 {
    MonitorNode** data;
    int size;
    int capacity;
    __declspec(noinline) void FUN_009b2b40(int idx, MonitorNode** p) { if (size < capacity) data[idx] = *p; }
};

namespace LegacyStatsStorage {
struct String {
    char* data;
    int size;
    unsigned capacity;
};
struct Strings {
    String** data;
    int size;
    unsigned capacity;
};
struct Router {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44;
    void* stringFree;
    unsigned stringCount;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64;
    void* nodeFree;
    unsigned nodeCount;
    void* FUN_008f6800(int kind, int pool);
};
struct NodeSlot {
    MonitorNode* FUN_00a8d060(MonitorNode*, const char*, int);
};
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
unsigned __cdecl FUN_009233f0(const char*);
void* __cdecl FUN_009234e0(void*, const void*, unsigned);
int __cdecl hkString_strCmp(const char*, const char*);
void __cdecl FUN_00901e90(String*, int, int);
void __cdecl FUN_00901f10(Strings*, int);
}

static __declspec(noinline) MonitorNode* FUN_00a64f60(
    const char* name, MonitorNode* parent, int first, int second,
    LegacyStatsStorage::Strings* strings)
{
    using namespace LegacyStatsStorage;
    if (!second)
        second = first;
    if (!name)
        name = "?";
    MonitorNode* result = 0;
    if (parent) {
        for (int i = 0; i < parent->children.size; ++i) {
            MonitorNode* child = parent->children.data[i];
            if (!hkString_strCmp(child->name, name)) {
                result = child;
                break;
            }
        }
    }
    if (!result) {
        if (strings && name) {
            Router* router = static_cast<Router*>(DAT_00d9b080(DAT_010f3170));
            String* text = static_cast<String*>(router->stringFree);
            if (text) {
                --router->stringCount;
                router->stringFree = *reinterpret_cast<void**>(text);
            } else {
                text = static_cast<String*>(router->FUN_008f6800(2, 0x16));
            }
            if (text) {
                text->data = 0;
                text->size = 0;
                text->capacity = 0x80000000;
                int length = FUN_009233f0(name) + 1;
                int capacity = text->capacity & 0x3fffffff;
                if (capacity < length) {
                    int grown = capacity * 2;
                    if (grown < length)
                        grown = length;
                    FUN_00901e90(text, grown, 1);
                }
                text->size = length;
                FUN_009234e0(text->data, name, length);
            }
            if (strings->size == (strings->capacity & 0x3fffffff))
                FUN_00901f10(strings, 4);
            strings->data[strings->size++] = text;
            name = strings->data[strings->size - 1]->data;
        }
        Router* router = static_cast<Router*>(DAT_00d9b080(DAT_010f3170));
        NodeSlot* storage = static_cast<NodeSlot*>(router->nodeFree);
        if (storage) {
            --router->nodeCount;
            router->nodeFree = *reinterpret_cast<void**>(storage);
        } else {
            storage = static_cast<NodeSlot*>(router->FUN_008f6800(6, 0x1b));
        }
        result = storage ? storage->FUN_00a8d060(parent, name, 1) : 0;
    }
    ++result->count0;
    ++result->count1;
    result->value0 += (float)first;
    result->value1 += (float)second;
    return result;
}

// pdb: _sumNodes | hkStreamStatisticsCollector.obj | fnv360_0822_retail, objrun, medium
// pdb params: n, stringTable
void __cdecl AggregateChildValues(MonitorNode* node, MonitorStrings* strings)
{
    if (!node || !node->children.size)
        return;
    for (int i = 0; i < node->children.size; ++i)
        AggregateChildValues(node->children.data[i], strings);
    if (node->value0 != 0.0f) {
        MonitorNode* child = FUN_00a64f60(
            DAT_00e86f18, node, (int)node->value0, (int)node->value1,
            reinterpret_cast<LegacyStatsStorage::Strings*>(strings));
        if (node->children.back() == child) {
            node->children.popBack();
            reinterpret_cast<NativeChildren1660*>(&node->children)->FUN_009b2b40(0, &child);
        }
    }
    node->value0 = 0.0f;
    node->value1 = 0.0f;
    for (int i = 0; i < node->children.size; ++i) {
        MonitorNode* child = node->children.data[i];
        node->value0 = child->value0 + node->value0;
        node->value1 = child->value1 + node->value1;
    }
}


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

int hkString_strLen(const char* s);

struct StrPacker
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkArrayChar m14;
    void FUN_00ddf5a0(const char* str);
};

// Packs a string into m14 with a 0x50 header, length, and padding when capacity allows.
// @f3 0x00a64e80 (community match, verified in this file)
void __cdecl FUN_00901f10(hkArrayChar* a, int n);
static __declspec(noinline) int* FUN_00a64bf0(hkArrayChar* a, int n)
{
    if (a->m_iElementCount == a->getCapacity())
        FUN_00901f10(a, 1);
    char* p = a->m_data + a->m_iElementCount;
    a->m_iElementCount += n;
    return (int*)p;
}
// pdb: hkStreamStatisticsCollector::addChunk | hkStreamStatisticsCollector.obj | fnv360_0822_retail, objrun, low, conflict (bridge: hkStreamStatisticsCollector::pushDir)
// pdb params: type, name, chunkAddress, usedSize, allocSize
void StrPacker::FUN_00ddf5a0(const char* str)
{
    if (((hkArrayChar*)((char*)this + 8))->getCapacity() > ((hkArrayChar*)((char*)this + 8))->m_iElementCount + 0x46)
    {
        int count = 0;
        int pad = 0;
        if (str != 0)
        {
            count = hkString_strLen(str) + 1;
            pad = count % 2;
        }
        unsigned char* out = (unsigned char*)FUN_00a64bf0((hkArrayChar*)((char*)this + 8), pad + count);
        out[0] = 0x50;
        out[1] = (unsigned char)pad + (unsigned char)count;
        *(unsigned short*)(out + 2) = 0;
        *(unsigned short*)(out + 4) = 0;
        if (count > 0)
        {
            FUN_00cb1260(out + 6, str, count);
            if (pad != 0)
                out[count + 6] = 0;
        }
    }
}


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
    unsigned char* __thiscall FUN_00ddf640();
};
// @f3 0x00a64f20 (community match, verified in this file)
namespace Native1471 {
void __cdecl FUN_00901f10(hkArrayChar*,int);
void __cdecl FUN_00901e90(hkArrayChar*,int,int);
inline void SetSize(hkArrayChar* a,int n){
 int cap=a->getCapacity();
 if(cap<n){int grown=cap*2;FUN_00901e90(a,n<grown?grown:n,1);}
 a->m_iElementCount=n;
}
static __declspec(noinline) int* FUN_00a64bf0(hkArrayChar*a,int n){
 int* slot;
 if(a->m_iElementCount>0)slot=(int*)(a->m_data+a->m_iElementCount);
 else {
 if(a->m_iElementCount==a->getCapacity())Native1471::FUN_00901f10(a,1);
 slot=(int*)(a->m_data+a->m_iElementCount);
 a->m_iElementCount=a->m_iElementCount+1;
 SetSize(a,0);
 }
 SetSize(a,n+a->m_iElementCount+6);
 return slot;
}
struct Owner{int unk00,unk04;hkArrayChar array;};
}
// pdb: hkStreamStatisticsCollector::popDir | hkStreamStatisticsCollector.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
unsigned char* FUN_00ddf640_Cls::FUN_00ddf640(){
 Native1471::Owner* self=reinterpret_cast<Native1471::Owner*>(this);
 unsigned char*out=(unsigned char*)self->array.getCapacity();
 if((int)out>self->array.m_iElementCount+0x46){
 out=(unsigned char*)Native1471::FUN_00a64bf0(&self->array,0);
 out[0]=0x70;out[1]=0;*(unsigned short*)(out+2)=0;*(unsigned short*)(out+4)=0;
 }
 return out;
}


namespace fnv_00ddf240 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00ddf240

namespace fnv_00ddfa10 {
struct SpawnHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

SpawnHolder* FUN_00c85750();

typedef void(__thiscall* VSlot8)(void* self, void* owner, int r);

}  // namespace fnv_00ddfa10

namespace fnv_00ddfab0 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00ddfab0

struct AllocIface
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
    virtual void v28();
    virtual unsigned int allocTag(int size, int tag);
};
struct MonitorStream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkArrayChar m_stream;
    void FUN_00ddf4d0(int unused, const char* name, int size, int id, int tag);
};
// Writes a record with type 0x43, name, id, and allocator result; returns early when capacity is low or both id and tag are zero.
// @fnv 0x00ddf4d0
void MonitorStream::FUN_00ddf4d0(int unused, const char* name, int size, int id, int tag)
{
    if (m_stream.getCapacity() <= m_stream.m_iElementCount + 0x46)
        return;
    if (id == 0 && tag == 0)
        return;
    int len = 0;
    int odd = 0;
    if (name)
    {
        len = hkString_strLen(name) + 1;
        odd = len % 2;
    }
    unsigned char* p = (unsigned char*)FUN_00ddf370(&m_stream, odd + len);
    p[0] = 0x43;
    p[1] = (unsigned char)(len + odd);
    *(unsigned short*)(p + 2) = (unsigned short)id;
    unsigned int r;
    if (!tag)
        r = 0;
    else
        r = ((AllocIface*)audio()->unk10)->allocTag(size, tag);
    *(unsigned short*)(p + 4) = r;
    if (len > 0)
    {
        FUN_00cb1260(p + 6, name, len);
        if (odd)
            p[len + 6] = 0;
    }
}

struct Pkt : Obj
{
    void FUN_00ddf420(const char* str, const void* a2, int a3);
};
// Writes a six-byte header and an optional null-terminated string padded to an even length; stores an allocator result in the header.
// @fnv 0x00ddf420
void Pkt::FUN_00ddf420(const char* str, const void* a2, int a3)
{
    int len = 0;
    int pad = 0;
    if (str != 0)
    {
        len = hkString_strLen(str) + 1;
        pad = len % 2;
    }
    unsigned char* out = (unsigned char*)FUN_00ddf370(&m14, len + pad);
    Record* rec = (Record*)out;
    rec->type = 0x50;
    rec->len = (unsigned char)(len + pad);
    rec->a = (unsigned short)a3;
    int v;
    if (a3 == 0)
        v = 0;
    else
        v = ((AllocIface&)audio()->heap()).allocTag((int)a2, a3);
    rec->b = (unsigned short)v;
    if (len > 0)
    {
        FUN_00cb1260(out + 6, str, len);
        if (pad != 0)
            out[len + 6] = 0;
    }
}
