#include "f3_common.h"
// src/havok/common/visualize/shape/hkdisplaycone.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycone.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct __declspec(align(16)) Vertex
{
    __m128 value;
};
struct Edge
{
    int polygon, end, start, adjacent;
};
template <class T> struct DynamicArray
{
    T* data;
    int size;
    unsigned int capacityAndFlags;
    DynamicArray() : data(0), size(0), capacityAndFlags(0x80000000u)
    {}
};
struct GeometryBuffers
{
    DynamicArray<Vertex> vertices;
    DynamicArray<Edge> edges;
    GeometryBuffers() : vertices(), edges()
    {}
    static void* operator new(unsigned int, void* position)
    {
        return position;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* __thiscall Allocate(unsigned int);
};
struct GlobalContext
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
extern "C" GlobalContext* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(Allocator*, DynamicArray<Edge>*, int, int);
struct ForwardArg
{
    GeometryBuffers* value;
};
struct MeshBuilder;
extern "C" void __fastcall FUN_00de54b0(MeshBuilder*, ForwardArg);
struct MeshBuilder
{
    int unk00;
    int unk04;
    GeometryBuffers* geometry;
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
    int unk58;
    int unk5c;
    Vertex initialVertex;
    int unk70, unk74, unk78, unk7c;
    volatile int segmentCount;
    void __thiscall InitializeGeometry();
};
// Allocates GeometryBuffers, calls FUN_00de54b0, appends initialVertex to vertices, and fills edges with segmentCount entries.
// @f3 0x00a6bfd0 (community match, verified in this file)
namespace na6bfd0 {
struct Block { Block* next; };
struct Bucket { Block* head; int count; };
struct PoolHeap {
    char pad[0x38];
    Bucket buckets[25];
    void* FUN_008f6800(int index, unsigned int tag);
};
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Edge12 { int polygon, end, start; };
struct Array {
    void* data;
    int size;
    unsigned int capacityAndFlags;
};
void __cdecl FUN_00901f10(Array* a, int elemSize);
void __cdecl FUN_00901e90(Array* a, int capacity, int elemSize);
struct Builder { void FUN_00a6bb60(GeometryBuffers* g); };

static __forceinline void* PoolAlloc() {
    PoolHeap* heap = (PoolHeap*)TlsGetValue(DAT_010f3170);
    Block* b = heap->buckets[3].head;
    if (b) {
        heap->buckets[3].count += -1;
        heap->buckets[3].head = b->next;
        return b;
    }
    return heap->FUN_008f6800(3, 0x27);
}
}

// pdb: hkDisplayCone::buildGeometry | hkDisplayCone.obj | fnv360_0822_retail, vtable, medium
void MeshBuilder::InitializeGeometry()
{
    using namespace na6bfd0;
    GeometryBuffers* g = new (PoolAlloc()) GeometryBuffers();
    geometry = g;
    ((Builder*)this)->FUN_00a6bb60(g);

    Array* verts = (Array*)&geometry->vertices;
    if (verts->size == (int)(verts->capacityAndFlags & 0x3fffffff))
        FUN_00901f10(verts, 0x10);
    float* dst = (float*)verts->data + verts->size++ * 4;
    const float* src = (const float*)&initialVertex;
    for (int k = 0; k < 4; k++)
        dst[k] = src[k];

    Array* edges = (Array*)&geometry->edges;
    int cap = edges->capacityAndFlags & 0x3fffffff;
    int n = segmentCount;
    if (cap < n) {
        cap *= 2;
        if (n >= cap)
            cap = n;
        FUN_00901e90(edges, cap, 0xc);
    }
    edges->size = n;

    int i;
    for (i = 0; i < segmentCount - 1; i++) {
        Edge12& e = ((Edge12*)geometry->edges.data)[i];
        e.polygon = segmentCount;
        e.end = i + 1;
        e.start = i;
    }
    Edge12& e = ((Edge12*)geometry->edges.data)[i];
    e.polygon = segmentCount;
    e.end = 0;
    e.start = i;
}


namespace fnv_00de58c0 {
struct __declspec(align(16)) S_00de58c0_V4
{
    float x, y, z, w;
};

struct S_00de58c0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};

struct S_00de58c0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00de58c0_Heap* m_pStreamAllocator;
    S_00de58c0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00de58c0_Arr
{
    S_00de58c0_V4* m_data;
    int m_iElementCount;
    int m_cap;
};

struct S_00de58c0_Local
{
    S_00de58c0_V4* m_data;
    int m_iElementCount;
    int m_cap;
    int m_pStackAllocation;
    float m_buf[1024];
};

struct S_00de58c0_Alloc;
S_00de58c0_Router* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(S_00de58c0_Alloc* a, S_00de58c0_Arr* arr, int n, int elemSize);

struct S_00de58c0_Obj
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
    int unk58;
    int unk5c;
    S_00de58c0_V4 m_60;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int m_80;
    void FUN_00de54b0(struct S_00de58c0_Local* out);
    void FUN_00de58c0(struct S_00de58c0_Arr* out, struct S_00de58c0_Alloc* alloc);
};

}  // namespace fnv_00de58c0
