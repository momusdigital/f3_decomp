#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00a60000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a6a750 (community match, verified in this file)
extern float DAT_00dbea4c;
struct Vector417 { float x, y, z, w; };
struct Matrix417 { Vector417 columns[3]; };
struct Display417 {
    void FUN_00a8f6c0(const Vector417* origin, const Matrix417* frame,
        float scale, unsigned int color, int id);
};
struct Owner417 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    Vector417 first;
    Vector417 second;
    Matrix417 firstFrame;
    Matrix417 secondFrame;
    Display417 display;
    void FUN_00a6a750(int id);
};
// pdb: hkpConstraintDrawer::drawPivots | hkpConstraintDrawer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: id, tag
void Owner417::FUN_00a6a750(int id) {
    display.FUN_00a8f6c0(&first, &firstFrame, DAT_00dbea4c, 0xffff0000, id);
    display.FUN_00a8f6c0(&second, &secondFrame, DAT_00dbea4c, 0xffffffff, id);
}

// @f3 0x00a632e0 (community match, verified in this file)
namespace f3m_00a632e0 {
struct Pair_b0065 { unsigned int key; unsigned int value; };

struct Sub_b0065 {
    void FUN_009ee8f0(int a);
    void FUN_009ee560(int a);
    void FUN_009ee930(int a, int b);
};

struct Holder_b0065 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    Sub_b0065* m_sub;
    unsigned int unk018;
    unsigned int unk01C;
    Pair_b0065* m_items;
    int m_count;
    int FUN_00a632e0(int id);
};

// pdb: hkInspectProcess::removeTopLevelObject | hkInspectProcess.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: ptr
int Holder_b0065::FUN_00a632e0(int id) {
    m_sub->FUN_009ee8f0(9);
    m_sub->FUN_009ee560(0x22);
    m_sub->FUN_009ee930(id, 0);
    int i = 0;
    int count = m_count;
    if (count > 0) {
        Pair_b0065* p = m_items;
        do {
            if (p->key == (unsigned int)id) {
                (*(volatile int*)&m_count)--;
                int c = *(volatile int*)&m_count;
                Pair_b0065* it = *(Pair_b0065* volatile*)&m_items;
                it[i] = it[c];
                break;
            }
            ++p;
            ++i;
        } while (i < count);
    }
    return 9;
}
}   // namespace f3m_00a632e0

// @f3 0x00a6b0c0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a6b0c0 {
struct Vector4 { float x, y, z, w; };
struct Cell { int a, b, c; };

template<class T>
struct Array {
    T* data;
    int size;
    int capFlags;
    Array() : data(0), size(0), capFlags(0x80000000) {}
};

struct MemCtx {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c,
        unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c;
    void* head;
    int count;
    void* FUN_008f6800(int a, int b);
};

extern "C" unsigned long (__stdcall* const DAT_00fdf044)(unsigned long);

void __cdecl FUN_00901f10(void* arr, int elemSize);

struct Grid {
    Array<Vector4> verts;
    Array<Cell> tris;

    static void* operator new(unsigned int) throw()
    {
        MemCtx* ctx = (MemCtx*)DAT_00fdf044(DAT_010f3170);
        void* n = ctx->head;
        if (n) {
            ctx->count--;
            ctx->head = *(void**)n;
        } else {
            n = ctx->FUN_008f6800(3, 0x27);
        }
        return n;
    }
};

struct Cls {
    int unk00, unk04;
    Grid* m8;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c,
        unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c,
        unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c,
        unk70, unk74, unk78, unk7c;
    Vector4 v80;
    int unk90, unk94, unk98;
    int n9c;

    void FUN_00a6ada0(Grid* g);
    void FUN_00a6b0c0();
};

// pdb: hkDisplaySemiCircle::buildGeometry | hkDisplaySemiCircle.obj | fnv360_0822_retail, vtable, medium
void Cls::FUN_00a6b0c0()
{
    Grid* g = new Grid;
    m8 = g;
    FUN_00a6ada0(g);

    Grid* arr = m8;
    if (arr->verts.size == (arr->verts.capFlags & 0x3fffffff))
        FUN_00901f10(&arr->verts, 0x10);

    Vector4* v = arr->verts.data + arr->verts.size;
    arr->verts.size += 1;
    v->x = v80.x;
    v->y = v80.y;
    v->z = v80.z;
    v->w = v80.w;

    int last = m8->verts.size - 1;
    int i = 0;
    int off = 0;
    if (n9c > 0) {
        do {
            Cell* c = (Cell*)((char*)m8->tris.data + off);
            c->a = last;
            c->b = i + 1;
            c->c = i;
            off += 12;
            i++;
        } while (i < n9c);
    }
}
}   // namespace f3m_00a6b0c0

// @f3 0x00a741b0 (community match, verified in this file)
namespace f3m_00a741b0 {
// hkpDisableEntityCollisionFilter_addEntityToFilter - EntityShape::AddActor(Actor*)
// this+0x30 : listener object (address only)
// this+0x34 : hkArray<Actor*>  { data, size, capacityAndFlags }

struct SmallBool
{
    bool m_bVal;
    SmallBool(bool abVal) : m_bVal(abVal) {}
};

struct ActorRef;

struct ListenerArray
{
    void** m_data;                // +0x00
    unsigned short m_usSize;      // +0x04
    unsigned short m_usMaxSize;   // +0x06
    void** m_data2;               // +0x08
    unsigned short m_usSize2;     // +0x0c
    unsigned short m_usMaxSize2;  // +0x0e

    int IndexOf(void* apItem) const
    {
        for (int i = 0; i < m_usSize; ++i)
            if (m_data[i] == apItem)
                return i;
        return -1;
    }
};

struct ActorRef
{
    char m_unk00[0xcc];
    void* m_pListenerList;   // +0xcc

    ListenerArray* FUN_00a70a70();
    void FUN_0090b880(void* apListener);
};

extern "C" void FUN_00901f10(void* apArray, int aiElemSize);

struct ActorEntryArray
{
    void** m_data;              // +0x00
    int m_iSize;                // +0x04
    int m_iCapacityAndFlags;    // +0x08

    void PushBack(void* apItem)
    {
        if (m_iSize == (m_iCapacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        m_data[m_iSize] = apItem;
        ++m_iSize;
    }
};

struct EntityShape
{
    char m_unk00[0x30];
    int m_kListener;              // +0x30
    ActorEntryArray m_kActorEntries;  // +0x34

    SmallBool hkpDisableEntityCollisionFilter_addEntityToFilter(ActorRef* apActor);
};

// pdb: hkpDisableEntityCollisionFilter::addEntityToFilter | hkpDisableEntityCollisionFilter.obj | fnv360_0822_retail, caller_sim + skyrim(objrun_prop), high
SmallBool EntityShape::hkpDisableEntityCollisionFilter_addEntityToFilter(ActorRef* apActor)
{
    if (!apActor)
        return false;

    for (int i = 0; i < m_kActorEntries.m_iSize; ++i)
    {
        if (m_kActorEntries.m_data[i] == apActor)
            return false;
    }

    m_kActorEntries.PushBack(apActor);

    {
        int* pListener = &m_kListener;
        if (apActor->FUN_00a70a70()->IndexOf(pListener) < 0)
        {
            apActor->FUN_0090b880(pListener);
            return true;
        }
    }

    return true;
}
}   // namespace f3m_00a741b0

// @f3 0x00a62030 (community match, verified in this file)
extern float DAT_00dbea4c;
namespace f3m_00a62030 {


extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

struct Vec62 { float x, y, z; };

struct Renderer62 {
    void FUN_009ee8f0(int a);
    void FUN_009ee560(int a);
    void FUN_009ee8b0(int a);
    void FUN_009ee740(int a, int b);
    void FUN_009ee8d0(int a);
    void FUN_009ee950(float a);
    unsigned char* FUN_009ee770(int* p);
};

struct Other62 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    int unk018;
    int unk01C;
    void FUN_00908a00();
};

struct Owner62 {
    unsigned int unk000;
    Renderer62* m_renderer;
    Other62* m_other;
    bool FUN_00a62030(int id, const Vec62* v, int a3, int a4);
};

int __cdecl FUN_009233f0(int a);

// pdb: hkServerDebugDisplayHandler::display3dText | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: text, pos, color, id, tag
bool Owner62::FUN_00a62030(int id, const Vec62* v, int a3, int a4)
{
    m_other->FUN_00908a00();
    if (m_renderer != 0) {
        int k = *(volatile int*)&id;
        int raw = FUN_009233f0(k);
        int n = raw < 0xffff ? raw : 0xffff;
        m_renderer->FUN_009ee8f0(n + 0x17);
        m_renderer->FUN_009ee560(0x11);
        m_renderer->FUN_009ee8b0(n);
        m_renderer->FUN_009ee740(k, n);
        m_renderer->FUN_009ee8d0(a3);
        m_renderer->FUN_009ee8d0(a4);
        m_renderer->FUN_009ee950(v->x);
        m_renderer->FUN_009ee950(v->y);
        m_renderer->FUN_009ee950(v->z);
    }
    bool ok = m_renderer != 0 && *m_renderer->FUN_009ee770(&id) != 0;
    Other62* o = m_other;
    o->unk018 = -1;
    o->unk01C = -1;
    LeaveCriticalSection(o);
    return !ok;
}
}   // namespace f3m_00a62030

// @f3 0x00a67020 (community match, verified in this file)
namespace f3m_00a67020 {
struct BoxVector1557
{
    float x;
    float y;
    float z;
    float w;
    void Set(float newX, float newY, float newZ)
    {
        x = newX;
        y = newY;
        z = newZ;
        w = 0.0f;
    }
};

struct BoxEdgeArray1557
{
    BoxVector1557* data00;
    int size04;
    int capacityAndFlags08;
};
extern void FUN_00901e90(BoxEdgeArray1557* array, int capacity, int elementSize);

class BoxShape1557
{
public:
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
    unsigned int unk58;
    unsigned int unk5c;
    BoxVector1557 minimum60;
    BoxVector1557 maximum70;
    void FUN_00a67020(BoxEdgeArray1557* output);
};

// pdb: hkDisplayAABB::getWireframeGeometry | hkDisplayAABB.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void BoxShape1557::FUN_00a67020(BoxEdgeArray1557* output)
{
    int capacity = output->capacityAndFlags08 & 0x3fffffff;
    if (capacity < 24)
    {
        int doubled = capacity + capacity;
        FUN_00901e90(output, doubled > 24 ? doubled : 24, sizeof(BoxVector1557));
    }
    output->size04 = 24;
    output->data00[0].Set(minimum60.x, minimum60.y, minimum60.z);
    output->data00[1].Set(minimum60.x, maximum70.y, minimum60.z);
    output->data00[2].Set(minimum60.x, minimum60.y, minimum60.z);
    output->data00[3].Set(minimum60.x, minimum60.y, maximum70.z);
    output->data00[4].Set(minimum60.x, minimum60.y, minimum60.z);
    output->data00[5].Set(maximum70.x, minimum60.y, minimum60.z);
    output->data00[6].Set(maximum70.x, maximum70.y, maximum70.z);
    output->data00[7].Set(maximum70.x, maximum70.y, minimum60.z);
    output->data00[8].Set(maximum70.x, maximum70.y, maximum70.z);
    output->data00[9].Set(minimum60.x, maximum70.y, maximum70.z);
    output->data00[10].Set(maximum70.x, maximum70.y, maximum70.z);
    output->data00[11].Set(maximum70.x, minimum60.y, maximum70.z);
    output->data00[12].Set(minimum60.x, maximum70.y, minimum60.z);
    output->data00[13].Set(maximum70.x, maximum70.y, minimum60.z);
    output->data00[14].Set(minimum60.x, maximum70.y, minimum60.z);
    output->data00[15].Set(minimum60.x, maximum70.y, maximum70.z);
    output->data00[16].Set(maximum70.x, maximum70.y, minimum60.z);
    output->data00[17].Set(maximum70.x, minimum60.y, minimum60.z);
    output->data00[18].Set(minimum60.x, maximum70.y, maximum70.z);
    output->data00[19].Set(minimum60.x, minimum60.y, maximum70.z);
    output->data00[20].Set(minimum60.x, minimum60.y, maximum70.z);
    output->data00[21].Set(maximum70.x, minimum60.y, maximum70.z);
    output->data00[22].Set(maximum70.x, minimum60.y, maximum70.z);
    output->data00[23].Set(maximum70.x, minimum60.y, minimum60.z);
}
}   // namespace f3m_00a67020

// @f3 0x00a67460 (community match, verified in this file)
#include <new>
namespace f3m_00a67460 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern void FUN_00901e90(void* array, int capacity, int elementSize);

struct GeometryPool1558
{
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
    void* freeList50;
    int freeCount54;
    void* FUN_008f6800(int units, int category);
};

template<class T> struct GeometryArray1558
{
    T* data00;
    int size04;
    int capacityAndFlags08;
    GeometryArray1558() : data00(0), size04(0), capacityAndFlags08(0x80000000) {}
    __forceinline T& ExpandOne()
    {
        int oldSize = size04;
        int newSize = oldSize + 1;
        int capacity = capacityAndFlags08 & 0x3fffffff;
        if (capacity < newSize)
        {
            int doubled = capacity + capacity;
            FUN_00901e90(this, newSize < doubled ? doubled : newSize, sizeof(T));
        }
        size04 = newSize;
        return data00[oldSize];
    }
};

struct GeometryVector1558
{
    float x;
    float y;
    float z;
    float w;
    void Set(float newX, float newY, float newZ)
    {
        x = newX;
        y = newY;
        z = newZ;
        w = 0.0f;
    }
};

struct GeometryTriangle1558
{
    int a;
    int b;
    int c;
    void Set(int first, int second, int third) { a = first; b = second; c = third; }
};

struct DisplayGeometry1558
{
    GeometryArray1558<GeometryVector1558> vertices00;
    GeometryArray1558<GeometryTriangle1558> triangles0c;
    static void* operator new(size_t)
    {
        GeometryPool1558* pool = static_cast<GeometryPool1558*>(TlsGetValue(::DAT_010f3170));
        void* result = pool->freeList50;
        if (result)
        {
            --pool->freeCount54;
            pool->freeList50 = *static_cast<void**>(result);
            return result;
        }
        return pool->FUN_008f6800(3, 0x27);
    }
};

class BoxShape1558
{
public:
    unsigned int unk00;
    unsigned int unk04;
    DisplayGeometry1558* geometry08;
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
    unsigned int unk58;
    unsigned int unk5c;
    GeometryVector1558 minimum60;
    GeometryVector1558 maximum70;
    void FUN_00a67460();
};

// pdb: hkDisplayAABB::buildGeometry | hkDisplayAABB.obj | fnv360_0822_retail, vtable, medium
void BoxShape1558::FUN_00a67460()
{
    geometry08 = new DisplayGeometry1558;
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(minimum60.x, minimum60.y, minimum60.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(minimum60.x, minimum60.y, maximum70.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(maximum70.x, minimum60.y, maximum70.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(maximum70.x, minimum60.y, minimum60.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(minimum60.x, maximum70.y, minimum60.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(minimum60.x, maximum70.y, maximum70.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(maximum70.x, maximum70.y, maximum70.z);
    }
    {
        GeometryVector1558& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(maximum70.x, maximum70.y, minimum60.z);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(0, 3, 1);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(1, 3, 2);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(2, 6, 5);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(5, 1, 2);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(5, 6, 4);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(4, 6, 7);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(7, 3, 0);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(0, 4, 7);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(0, 1, 4);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(4, 1, 5);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(2, 3, 6);
    }
    {
        GeometryTriangle1558& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(6, 3, 7);
    }
}
}   // namespace f3m_00a67460

// @f3 0x00a67f80 (community match, verified in this file)
#include <new>
namespace f3m_00a67f80 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern void FUN_00901e90(void* array, int capacity, int elementSize);

struct GeometryPool1560
{
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
    void* freeList50;
    int freeCount54;
    void* FUN_008f6800(int units, int category);
};

template<class T> struct GeometryArray1560
{
    T* data00;
    int size04;
    int capacityAndFlags08;
    GeometryArray1560() : data00(0), size04(0), capacityAndFlags08(0x80000000) {}
    __forceinline T& At(int index) { return data00[index]; }
    __forceinline const T& At(int index) const { return data00[index]; }
    __forceinline T& ExpandOne()
    {
        int oldSize = size04;
        int newSize = oldSize + 1;
        int capacity = capacityAndFlags08 & 0x3fffffff;
        if (capacity < newSize)
        {
            int doubled = capacity + capacity;
            FUN_00901e90(this, newSize < doubled ? doubled : newSize, sizeof(T));
        }
        size04 = newSize;
        return data00[oldSize];
    }
};

struct GeometryTransform1560;
struct GeometryVector1560
{
    float x;
    float y;
    float z;
    float w;
    void Set(float newX, float newY, float newZ)
    {
        x = newX;
        y = newY;
        z = newZ;
        w = 0.0f;
    }
    void hkVector4_setTransformedPos(const GeometryTransform1560* transform, const GeometryVector1560* source);
};

struct GeometryTransform1560
{
    GeometryVector1560 columns[4];
};

struct GeometryTriangle1560
{
    int a;
    int b;
    int c;
    void Set(int first, int second, int third) { a = first; b = second; c = third; }
};

struct DisplayGeometry1560
{
    GeometryArray1560<GeometryVector1560> vertices00;
    GeometryArray1560<GeometryTriangle1560> triangles0c;
    static void* operator new(size_t)
    {
        GeometryPool1560* pool = static_cast<GeometryPool1560*>(TlsGetValue(DAT_010f3170));
        void* result = pool->freeList50;
        if (result)
        {
            --pool->freeCount54;
            pool->freeList50 = *static_cast<void**>(result);
            return result;
        }
        return pool->FUN_008f6800(3, 0x27);
    }
};

class BoxShape1560
{
public:
    unsigned int unk00;
    unsigned int unk04;
    DisplayGeometry1560* geometry08;
    unsigned int unk0c;
    GeometryTransform1560 transform10;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    GeometryVector1560 halfExtents60;
    GeometryVector1560 maximum70;
    void FUN_00a67f80();
};

// pdb: hkDisplayBox::buildGeometry | hkDisplayBox.obj | fnv360_0822_retail, vtable, medium
void BoxShape1560::FUN_00a67f80()
{
    geometry08 = new DisplayGeometry1560;
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(-halfExtents60.x, halfExtents60.y, halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(halfExtents60.x, halfExtents60.y, halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(halfExtents60.x, -halfExtents60.y, halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(-halfExtents60.x, -halfExtents60.y, halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(-halfExtents60.x, halfExtents60.y, -halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(halfExtents60.x, halfExtents60.y, -halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(halfExtents60.x, -halfExtents60.y, -halfExtents60.z);
    }
    {
        GeometryVector1560& vertex = geometry08->vertices00.ExpandOne();
        vertex.Set(-halfExtents60.x, -halfExtents60.y, -halfExtents60.z);
    }
    for (int i = 0; i < geometry08->vertices00.size04; ++i)
    {
        geometry08->vertices00.At(i).hkVector4_setTransformedPos(&transform10, &geometry08->vertices00.At(i));
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(3, 2, 1);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(3, 1, 0);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(6, 7, 4);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(6, 4, 5);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(4, 7, 3);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(4, 3, 0);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(2, 6, 5);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(2, 5, 1);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(7, 6, 2);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(7, 2, 3);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(1, 5, 4);
    }
    {
        GeometryTriangle1560& triangle = geometry08->triangles0c.ExpandOne();
        triangle.Set(1, 4, 0);
    }
}
}   // namespace f3m_00a67f80

// @f3 0x00a70950 (community match, verified in this file)
namespace f3m_00a70950 {
namespace f3m_00a70950 {

struct ListenerArray
{
    void** m_data;
    unsigned short m_usSize;
    unsigned short m_usMaxSize;

    int IndexOf(void* apItem) const
    {
        for (int i = 0; i < m_usSize; ++i)
            if (m_data[i] == apItem)
                return i;
        return -1;
    }
};

struct ActorRef
{
    ListenerArray* FUN_00a70a70();
    void FUN_0090b960(void* apListener);
};

struct PairEntry
{
    ActorRef* first;
    ActorRef* second;
};

struct ShapeBase
{
    virtual ~ShapeBase();
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
};

struct ShapeListener
{
    virtual void Notify();
};

struct PairArray
{
    PairEntry* m_data;
    int m_iSize;
    int m_iCapacityAndFlags;

    int Find(ActorRef* a, ActorRef* b) const
    {
        for (int i = 0; i < m_iSize; ++i)
            if (m_data[i].first == a && m_data[i].second == b)
                return i;
        return -1;
    }

    void RemoveAt(int i)
    {
        --m_iSize;
        m_data[i] = m_data[m_iSize];
    }
};

struct PairShape : ShapeBase, ShapeListener
{
    PairArray m_kPairs;

    void FUN_00a70950(ActorRef* a, ActorRef* b);
};

// pdb: hkpCharacterProxy::entityRemovedCallback | hkpCharacterProxy.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: entity
void PairShape::FUN_00a70950(ActorRef* a, ActorRef* b)
{
    ActorRef* hi;
    ActorRef* lo;
    if (a > b) {
        hi = a;
        lo = b;
    } else {
        hi = b;
        lo = a;
    }
    int idx = m_kPairs.Find(hi, lo);
    if (idx < 0)
        return;
    m_kPairs.RemoveAt(idx);

    ListenerArray* la = a->FUN_00a70a70();
    if (la->IndexOf(static_cast<ShapeListener*>(this)) >= 0)
        a->FUN_0090b960(static_cast<ShapeListener*>(this));
    ListenerArray* lb = b->FUN_00a70a70();
    if (lb->IndexOf(static_cast<ShapeListener*>(this)) >= 0)
        b->FUN_0090b960(static_cast<ShapeListener*>(this));
}
}
}   // namespace f3m_00a70950

// @f3 0x00a7cd60 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a7cd60 {



struct Cd60Elem {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short unk20;
};

struct Cd60List {
    Cd60Elem** data;
    unsigned int count;
    unsigned int capBits;
};

struct Cd60Inner {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    Cd60List list;
};

struct Cd60C {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    Cd60Inner* inner;
};

struct Cd60Src {
    unsigned int unk00;
    unsigned short w04;
};

struct Cd60Ctx {
    unsigned int unk00;
    Cd60C* c;
    unsigned int unk08, unk0C;
    unsigned short w10;
};

struct Cd60Sub {
    unsigned int unk00, unk04, unk08;
    unsigned int m0C;
    unsigned int m10;
    unsigned int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    Cd60Elem** elems;
    int count;
    unsigned int flags;
};

struct Cd60Alloc {
    void FUN_008f6d90(Cd60Elem** p, unsigned int size, int tag);
};

void __cdecl FUN_00901f10(Cd60List* list, int n);

struct Cd60Owner {
    unsigned short unk00;
    unsigned short w02;
    unsigned int unk04;
    Cd60Sub* sub;
    unsigned int unk0C;
    unsigned short w10;

    int FUN_00a7cd60(Cd60Src* a1, Cd60Ctx* a2);
};

// pdb: hkpBroadPhaseJob::popJobTask | hkpDynamicsJobs.obj | tesv_win, objopen_prop, low
int Cd60Owner::FUN_00a7cd60(Cd60Src* a1, Cd60Ctx* a2)
{
    Cd60Sub* sub = this->sub;
    if (sub != 0) {
        int n = sub->count;
        if (n != 0) {
            sub->m0C += n;
            sub->m10 += n;
            this->w02 = a1->w04;
            this->w10 = (unsigned short)n;
            Cd60List* list = &a2->c->inner->list;
            for (int i = 0; i < n; ++i) {
                Cd60Elem* e = sub->elems[i];
                e->unk20 = (unsigned short)list->count;
                if (list->count == (list->capBits & 0x3fffffff))
                    FUN_00901f10(list, 4);
                list->data[list->count] = e;
                list->count++;
            }
            if ((sub->flags & 0x80000000u) == 0) {
                unsigned int cnt = sub->flags & 0x3fffffff;
                Cd60Alloc* al = (Cd60Alloc*)TlsGetValue(DAT_010f3170);
                al->FUN_008f6d90(sub->elems, cnt * 4, 0x17);
            }
            sub->elems = 0;
            sub->count = 0;
            sub->flags = (sub->flags & 0xc0000000) | 0x80000000;
            return 1;
        }
    }
    unsigned short w = this->w10;
    if (w > 1) {
        w = (unsigned short)(w - 1);
        this->w10 = w;
        this->w02 += 1;
        a2->w10 = 1;
        return 1;
    }
    return 0;
}
}   // namespace f3m_00a7cd60

// @f3 0x00a64b10 (community match, verified in this file)
namespace f3m_00a64b10 {


extern DWORD DAT_010f3170;

struct Thing417 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Tls417 {
    unsigned int FUN_008f6d30(unsigned int a, unsigned int b);
};

struct Other417 {
    void FUN_00922cb0();
};

inline int Pos417(int x) { return x > 0 ? x : 0; }
void __cdecl FUN_00901e90(Thing417* t, unsigned int v, int one);

struct Prim417 {
    virtual void vp();
    unsigned short unk04;
    unsigned short unk06;
    Prim417() { unk06 = 1; }
};

struct Sub417 {
    virtual void vs();
    unsigned int unk04;
};

struct FUN_00a64b10 : Prim417, Sub417 {
    virtual void vd();
    Thing417 thing;
    Other417 other;
    FUN_00a64b10(unsigned int a);
};

// pdb: hkStreamStatisticsCollector::hkStreamStatisticsCollector | hkStreamStatisticsCollector.obj | fnv360_0822_retail, call_seq, medium
// pdb params: vtblReg, memSize
FUN_00a64b10::FUN_00a64b10(unsigned int a)
{
    Thing417* p = &thing;
    Tls417* tls = (Tls417*)TlsGetValue(DAT_010f3170);
    p->unk00 = tls->FUN_008f6d30(a, 0x17);
    p->unk04 = a;
    p->unk08 = a;
    other.FUN_00922cb0();
    unsigned int v = p->unk08 & 0x3fffffff;
    if ((int)v < 0) {
        FUN_00901e90(p, (int)(v * 2) > 0 ? v * 2 : 0, 1);
    }
    p->unk04 = 0;
}
}   // namespace f3m_00a64b10

// @f3 0x00a630b0 (community match, verified in this file)
namespace f3m_00a630b0 {
namespace task1345 {
class Bool {char value;public:operator bool() const {return value!=0;}};
struct Item {Bool FUN_009b0780() const;};
struct Pred {virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual const Item* Get(const void*) const;};
struct Context {
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
Pred* registry;};
struct Archive {void FUN_009ee8f0(unsigned);void FUN_009ee560(unsigned char);void FUN_009ee930(unsigned __int64);};
struct Owner {int unk00,unk04,unk08,unk0c,unk10;Archive* archive;int unk18,unk1c,unk20,unk24,unk28;Context* context;int FUN_00a630b0(void*,const Item*);};
// pdb: hkInspectProcess::addTopLevelObject | hkInspectProcess.obj | fnv360_0822_retail, call_seq, medium
// pdb params: ptr, klass, tag
int Owner::FUN_00a630b0(void* object,const Item* info){
 archive->FUN_009ee8f0(17);
 const Item* actual=info;
 if(context->registry && info->FUN_009b0780()) {
 actual=context->registry->Get(object);
 if(!actual)actual=info;
 }
 archive->FUN_009ee560(33);
 archive->FUN_009ee930(reinterpret_cast<unsigned>(object));
 archive->FUN_009ee930(reinterpret_cast<unsigned>(actual));
 return 17;
}
}
}   // namespace f3m_00a630b0

// @f3 0x00a631e0 (community match, verified in this file)
namespace f3m_00a631e0 {
extern "C" void _ReadWriteBarrier(void);

struct Class417;

struct Member417 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int FUN_0093dac0();
    Class417* FUN_0093d890();
};

struct Class417 {
    Member417* FUN_009b0650(unsigned short w);
};

struct Path417 {
    const unsigned short* unk00;
};

// pdb: _FindMemberItem | hkInspectProcess.obj | fnv360_0822_retail, call_gap, medium
static __declspec(noinline) char* FUN_00a631e0(Member417* member, char* data, const Path417* path, int type, int aiIndex)
{
    const Path417** val;
    val = &path;
    const Path417* k;
    k = *(const Path417* volatile*)val;
    char* tmp = data;
    for (;;) {
        switch (type - 1) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        case 8: case 9: case 10: case 11: case 12:
        case 23: case 29: case 30:
            return tmp;
        case 13: case 14: case 15: case 16: case 17: {
            char* pp;
            pp = tmp + 16 * (*(k->unk00 + 1 + aiIndex));
            type = 12;
            ++aiIndex;
            tmp = pp;
            _ReadWriteBarrier();
            continue;
        }
        case 21: case 25: {
            char* pp;
            int pthv = (*(1 + aiIndex + k->unk00));
            pp = *(char**)tmp + member->FUN_0093dac0() * pthv;
            type = member->unk0D;
            aiIndex += 1;
            _ReadWriteBarrier();
            tmp = pp;
            continue;
        }
        case 24: {
            if (member == 0)
                return 0;
            Class417* v;
            if (0 == member->unk04)
                return 0;
            v = member->FUN_0093d890();
            if (v == 0)
                return 0;
            unsigned short w = k->unk00[aiIndex + 1];
            member = v->FUN_009b0650(w);
            int off = member->unk12;
            type = member->unk0C;
            aiIndex += 1;
            tmp += off;
            _ReadWriteBarrier();
            continue;
        }
        case 19:
            return 0;
        default:
            return 0;
        }
    }
}

volatile Member417* g_member;
volatile char* g_data;
volatile Path417* g_path;
volatile int g_type;
volatile int g_aiIndex;

char* caller_00a631e0(void)
{
    return FUN_00a631e0((Member417*)g_member, (char*)g_data, (const Path417*)g_path, g_type, g_aiIndex);
}
}   // namespace f3m_00a631e0

// @f3 0x00a70700 (community match, verified in this file)
#include <windows.h>
extern int FUN_00e81d3c, FUN_00e81d30, FUN_00e81d1c, FUN_00e81d10, FUN_00e81d04, FUN_00e81cec;
extern int FUN_00dcc494, FUN_00e32018, FUN_00e32030, FUN_00e32044, FUN_00e32024, FUN_00dcd094;
extern unsigned int DAT_010f3170;
namespace f3m_00a70700 {
extern "C" unsigned long (__stdcall* const DAT_00fdf044)(unsigned long);
namespace attempt {
struct Alloc { void FUN_008f6d90(void*, int, int); };
struct ListenerArray {
    void** data;
    unsigned short size, capacity;
    int Find(void* p) { for (int i=0; i<size; ++i) if (data[i]==p) return i; return -1; }
};
struct Actor { ListenerArray* FUN_00a70a70(); void FUN_0090b960(void*); };
struct Pair { Actor* first; Actor* second; ListenerArray* getFirst() { return first->FUN_00a70a70(); } ListenerArray* getSecond() { return second->FUN_00a70a70(); } };
struct Shape {
    void *v0; int unk04; void *v8,*vc,*v10,*v14;
    int unk18,unk1c,unk20,unk24,unk28,unk2c;
    void* v30; Pair* data; int size, capacity;
    void FUN_00a70700();
};
void Shape::FUN_00a70700() {
    v0=&FUN_00e81d3c; v8=&FUN_00e81d30; vc=&FUN_00e81d1c; v10=&FUN_00e81d10; v14=&FUN_00e81d04; v30=&FUN_00e81cec;
    for (int i=0; i<size; ++i) {
        int offset=i*8;
        if (((Pair*)((char*)data+offset))->getFirst()->Find(&v30)>=0)
            ((Pair*)((char*)data+offset))->first->FUN_0090b960(&v30);
        if (((Pair*)((char*)data+offset))->getSecond()->Find(&v30)>=0)
            ((Pair*)((char*)data+offset))->second->FUN_0090b960(&v30);
    }
    if (!(capacity & 0x80000000)) {
        int n=capacity & 0x3fffffff;
        Alloc* a=(Alloc*)DAT_00fdf044(DAT_010f3170);
        a->FUN_008f6d90(data,n*8,0x17);
    }
    *(void* volatile*)&v30=&FUN_00dcd094; *(void* volatile*)&v14=&FUN_00e32024; *(void* volatile*)&v10=&FUN_00e32044; *(void* volatile*)&vc=&FUN_00e32030; *(void* volatile*)&v8=&FUN_00e32018; *(void* volatile*)&v0=&FUN_00dcc494;
}
}
}   // namespace f3m_00a70700

// @f3 0x00a64c90 (community match, verified in this file)
struct Svc419 {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual int Slot15(int v);
};
extern Svc419* DAT_010f3400;

int __cdecl FUN_009233f0(const char* s);
void* __cdecl FUN_009234e0(void* dst, const void* src, unsigned int n);
struct Array419 {unsigned char* data;int size;int flags;int capacity(){return flags&0x3fffffff;}};
void __cdecl FUN_00901f10(Array419*,int);
void __cdecl FUN_00901e90(Array419*,int,int);
static __declspec(noinline) unsigned char* FUN_00a64bf0(Array419* stream,int extra){
 unsigned char* result;
 if(stream->size>0)result=stream->data+stream->size;
 else {
  if(stream->size==stream->capacity())FUN_00901f10(stream,1);
  result=stream->data+stream->size;
  stream->size++;
  if(stream->capacity()<0){int n=stream->capacity()*2;FUN_00901e90(stream,n>0?n:0,1);}
  stream->size=0;
 }
 int total=stream->size+extra+6;
 if(stream->capacity()<total){int n=stream->capacity()*2;FUN_00901e90(stream,total>=n?total:n,1);}
 stream->size=total;return result;
}

struct Stream419 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    void FUN_00a64c90(const char* a1, unsigned int a2, unsigned char a3, unsigned int a4, int a5);
};

// pdb: _newCommand | hkStreamStatisticsCollector.obj | fnv360_0822_retail, objrun, low, conflict (bridge: hkStreamStatisticsCollector::addChunk)
void Stream419::FUN_00a64c90(const char* a1, unsigned int a2, unsigned char a3, unsigned int a4, int a5) {
    int masked = (int)(unk10 & 0x3fffffff);
    if (masked <= unk0C + 0x46) return;
    if ((unk20 & a2) == 0) return;
    int len = 0;
    if (a4 == 0 && a5 == 0) return;
    int pad = 0;
    if (a1 != 0) {
        len = FUN_009233f0(a1) + 1;
        pad = len % 2;
    }
    Array419* stream = (Array419*)&unk08;
    int total = pad + len;
    unsigned char* p = FUN_00a64bf0(stream,total);
    p[0] = 0x43;
    p[1] = (unsigned char)(len + pad);
    *(unsigned short*)(p + 2) = (unsigned short)a4;
    int v;
    if (!a5) v=0; else v = DAT_010f3400->Slot15(a5);
    *(unsigned short*)(p + 4) = (unsigned short)v;
    if (len <= 0) return;
    FUN_009234e0(p + 6, a1, len);
    if (pad != 0) p[len + 6] = 0;
    return;
}

// @f3 0x00a6afc0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a6afc0 {
class VectorHeap { public: void FUN_008f6d90(void* memory, int bytes, int category); };
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct ScalarVector4
{
    float x, y, z, w;
    void operator=(const ScalarVector4& source)
    {
        x = source.x;
        y = source.y;
        z = source.z;
        w = source.w;
    }
};
struct ScalarVectorArray
{
    ScalarVector4* data;
    int size;
    unsigned int capacityAndFlags;
};
void __cdecl FUN_00901e90(ScalarVectorArray* array, int capacity, int stride);
class GeometryEdges
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
    int count;
    void FUN_00a6ada0(ScalarVectorArray* vertices);
    void FUN_00a6afc0(ScalarVectorArray* destination);
};
// pdb: hkDisplaySemiCircle::getWireframeGeometry | hkDisplaySemiCircle.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void GeometryEdges::FUN_00a6afc0(ScalarVectorArray* destination)
{
    ScalarVectorArray temporary = {0, 0, 0x80000000u};
    FUN_00a6ada0(&temporary);
    int required = count * 2;
    int capacity = destination->capacityAndFlags & 0x3fffffff;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00901e90(destination, newCapacity, 16);
    }
    destination->size = required;
    int output = 0;
    for (int index = 0; index < count; ++index)
    {
        destination->data[output] = temporary.data[index];
        ++output;
        destination->data[output] = temporary.data[index + 1];
        ++output;
    }
    if ((temporary.capacityAndFlags & 0x80000000u) == 0)
    {
        unsigned int maskedCapacity = temporary.capacityAndFlags & 0x3fffffff;
        VectorHeap* heap = (VectorHeap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(temporary.data, maskedCapacity * 16, 0x17);
    }
}
}   // namespace f3m_00a6afc0

// @f3 0x00a774b0 (community match, verified in this file)
extern const char str_00e87e1c[];
extern const char str_00e87e14[];
extern const char str_00e87e08[];
namespace f3m_00a774b0 {
namespace f3m_00a774b0 {

struct StatisticsCollector
{
    virtual void v00();
    virtual void beginObject(const char* name, int type, const void* object);
    virtual void addChunk(const char* name, int type, const void* data, int usedBytes, int allocatedBytes);
    virtual void addChildObject(const char* name, int type, const void* object);
    virtual void v10();
    virtual void v14();
    virtual void endObject();
};

struct IntArray
{
    int* m_data;
    int m_size;
    int m_capacityAndFlags;
};

inline void addArray(StatisticsCollector* collector, const char* name, int type, const IntArray& array)
{
    if (!(array.m_capacityAndFlags & 0x80000000))
        collector->addChunk(name, type, array.m_data, array.m_size * sizeof(int), (array.m_capacityAndFlags & 0x3fffffff) * sizeof(int));
}

struct StatisticsData
{
    int unk00;
    int unk04;
    IntArray m_array08;
    IntArray m_array14;
    IntArray m_array20;
};

struct StatisticsOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    StatisticsData* m_data;
    void* m_child;
    void FUN_00a774b0(StatisticsCollector* collector);
};

// pdb: hkpConvexPieceMeshShape::calcContentStatistics | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: collector, cls
void StatisticsOwner::FUN_00a774b0(StatisticsCollector* collector)
{
    collector->beginObject(str_00e87e1c, 1, this);
    addArray(collector, str_00e87e14, 1, m_data->m_array14);
    addArray(collector, str_00e87e14, 1, m_data->m_array20);
    addArray(collector, str_00e87e14, 1, m_data->m_array08);
    collector->addChildObject(str_00e87e08, 1, m_child);
    collector->endObject();
}
}
}   // namespace f3m_00a774b0

// @f3 0x00a76110 (community match, verified in this file)
namespace f3m_00a76110 {
struct PoolA { void FUN_008f6d90(void* p, unsigned int size, int tag); void* FUN_008f6d30(unsigned int size, int tag); };
struct Vec4A { float x, y, z, w; Vec4A& operator=(const Vec4A& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct ArrA { Vec4A* data; int size; unsigned int flags; };
struct SrcA {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4A* data;
    int size;
    void FUN_00a76110(ArrA* dst);
};
void SrcA::FUN_00a76110(ArrA* dst)
{
    unsigned int cap = dst->flags & 0x3fffffff;
    if ((int)cap < size) {
        if ((dst->flags & 0x80000000u) == 0) {
            PoolA* p = (PoolA*)TlsGetValue(DAT_010f3170);
            p->FUN_008f6d90(dst->data, cap * 16, 0x17);
        }
        PoolA* p2 = (PoolA*)TlsGetValue(DAT_010f3170);
        dst->data = (Vec4A*)p2->FUN_008f6d30(size * 16, 0x17);
        dst->flags = (dst->flags & 0x40000000) | size;
    }
    int n = size;
    dst->size = n;
    Vec4A* s = data;
    Vec4A* d = dst->data;
    for (int i = 0; i < n; ++i)
        d[i] = s[i];
}

}   // namespace f3m_00a76110

// @f3 0x00a7fc60 (community match, verified in this file)
namespace f3m_00a7fc60 {
namespace GroupSetup2210 {
struct Vector {
    float x,y,z,w;
    void Copy(const Vector& v) {x=v.x; y=v.y; z=v.z; w=v.w;}
};
struct Group {
    Vector third, first, second;
    unsigned state, unk34, unk38, unk3C;
    void Set(const Vector& a, const Vector& b, const Vector& c) {
        first.Copy(a); second.Copy(b); third.Copy(c); state=0;
    }
};
struct Owner {
    unsigned unk00,unk04,type,status,unk10,unk14,unk18,unk1C;
    Group groups[4];
    void FUN_00a994b0();
    void FUN_00a7fc60(const Vector*,const Vector*,const Vector*);
};
// pdb: hkpWingedEdge::init | hkpConvexPenetrationUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkWingedEdge::init)
// pdb params: AinA, BinB, simplex
void Owner::FUN_00a7fc60(const Vector* a,const Vector* b,const Vector* c) {
    type=4;
    groups[0].Set(a[0],b[0],c[0]);
    groups[1].Set(a[1],b[1],c[1]);
    groups[2].Set(a[2],b[2],c[2]);
    groups[3].Set(a[3],b[3],c[3]);
    FUN_00a994b0();
    status=0;
}
}
}   // namespace f3m_00a7fc60

// @f3 0x00a76b30 (community match, verified in this file)
namespace f3m_00a76b30 {
struct Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual int vf4(int a);
};

struct Info {
    int unk00;
    int unk04;
    int unk08;
    int type0c;
    Obj m10;
};

struct Node {
    Info* info;
    int data4;
    int unk08;
    Node* next;
    int unk10;
    int unk14;
    int unk18;
    int value1c;
    __forceinline int RootFilterInfo() {
        Node* root = this;
        while (root->next)
            root = root->next;
        return root->value1c;
    }
};

struct Table {
    __forceinline unsigned TypeMask(unsigned type) const {
        return reinterpret_cast<const unsigned*>(this)[0x44 + type];
    }
};

Obj* __cdecl FUN_009b4c20(Node* n);

struct FilterResult {
    bool allowed;
    FilterResult(bool value) : allowed(value) {}
};
struct Sub {
    FilterResult FUN_00a76800(int filterA, int filterB);
};
struct Owner {
    FilterResult FUN_00a76b30(Table** dispatcher, Node* initial, int unusedBody, Obj* container, int shapeKey);
};
// pdb: hkpGroupFilter::isCollisionEnabled | hkpGroupFilter.obj | fnv360_0822_retail, vtable, high
// pdb params: input, a, b, bContainer, bKey
FilterResult Owner::FUN_00a76b30(Table** dispatcher, Node* initial, int, Obj* container, int shapeKey)
{
    int filterB = container->vf4(shapeKey);
    int filterA;
    Node* parent = initial->next;
    if (!parent) {
        filterA = initial->RootFilterInfo();
        goto compare;
    } else {
        const Table* table = *dispatcher;
        Node* child = initial;
        do {
            unsigned typeMask = table->TypeMask(parent->info->type0c);
            if (typeMask & 0x100) {
                Info* shape = parent->info;
                const int key = child->data4;
                filterA = shape->m10.vf4(key);
                goto compare;
            }
            if (typeMask & 0x200) {
                Obj* collection = FUN_009b4c20(parent);
                const int key = child->data4;
                filterA = collection->vf4(key);
                goto compare;
            }
            if (typeMask & 0x100000) {
                filterA = initial->RootFilterInfo();
                goto compare;
            }
            if (typeMask & 0x200000)
                return FilterResult(true);
            child = parent;
            parent = parent->next;
        } while (parent);
        filterA = child->value1c;
    }
compare:
    Sub* compareOwner = reinterpret_cast<Sub*>(reinterpret_cast<char*>(this) - 0xc);
    return compareOwner->FUN_00a76800(filterA, filterB);
}
}   // namespace f3m_00a76b30

// @f3 0x00a6f6f0 (community match, verified in this file)
namespace na6f6f0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
extern unsigned long DAT_010f3170;
struct FreeNode { FreeNode* next; };
struct FreeList {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) throw() { ++count; b->next = head; head = b; }
};
struct ThreadMemory {
    char pad[0x34];
    int limit;
    char pad38[0x18];
    FreeList row3;
    char pad58[0x40];
    FreeList row12;
    void FUN_008f6890(int row, void* p, int tag) throw();
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
inline ThreadMemory* Mem() throw() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray {
    T* data;
    int size;
    int capAndFlags;
    __forceinline ~hkArray() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Mem()->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct Leaf {
    char data[0x60];
    static void operator delete(void* p) throw() {
        ThreadMemory* pool = Mem();
        FreeList* bucket = &pool->row12;
        if (*(volatile int*)&bucket->count >= pool->limit)
            pool->FUN_008f6890(12, p, 0x1f);
        else
            bucket->Push((FreeNode*)p);
    }
};
}
class FUN_00a6f6f0 {
public:
    na6f6f0::hkArray<na6f6f0::Leaf*> m_leaves;
    na6f6f0::hkArray<FUN_00a6f6f0*> m_children;
    ~FUN_00a6f6f0() throw();
    static __forceinline void Free(void* p) throw() {
        na6f6f0::ThreadMemory* pool = na6f6f0::Mem();
        na6f6f0::FreeList* bucket = &pool->row3;
        if (*(volatile int*)&bucket->count >= pool->limit)
            pool->FUN_008f6890(3, p, 0xd);
        else
            bucket->Push((na6f6f0::FreeNode*)p);
    }
};
// pdb: hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo | hkpSerializedAgentNnEntry.obj | fnv360_0822_retail, call_dedup, low
FUN_00a6f6f0::~FUN_00a6f6f0() throw()
{
    bool locked = ((unsigned)m_leaves.capAndFlags >> 30) & 1;
    if (!locked) {
        for (int i = 0; i < m_leaves.size; i++) {
            na6f6f0::Leaf* leaf = m_leaves.data[i];
            if (leaf)
                delete leaf;
        }
        for (int i = 0; i < m_children.size; i++) {
            FUN_00a6f6f0* child = m_children.data[i];
            if (child) {
                child->~FUN_00a6f6f0();
                Free(child);
            }
        }
    }
}

// @f3 0x00a6aa20 (community match, verified in this file)
namespace f3m_00a6aa20 {
namespace na6aa20 {
struct Vec4 {
    float v[4];
    __forceinline Vec4& operator=(const Vec4& o) { for (int k = 0; k < 4; k++) v[k] = o.v[k]; return *this; }
};
struct Rot {
    Vec4 c[3];
    __forceinline Rot& operator=(const Rot& o) { c[0] = o.c[0]; c[1] = o.c[1]; c[2] = o.c[2]; return *this; }
};
struct Transform {
    Rot rot;
    Vec4 trans;
    void FUN_008fda60(const Transform* t);
};
struct Body { char p00[0xe0]; Transform transform; };
struct Pair { char p00[0x14]; Body* bodyA; Body* bodyB; };
}
struct Ca6aa20 {
    char p00[0x20];
    na6aa20::Vec4 transB;
    na6aa20::Vec4 transA;
    char p40[0x20];
    na6aa20::Rot rotB;
    na6aa20::Rot rotA;
    void FUN_00a6aa20(na6aa20::Pair* pair, na6aa20::Transform* a, na6aa20::Transform* b);
};
// pdb: hkpConstraintDrawer::updateCommonParameters | hkpConstraintDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, refLocalToWorld, attLocalToWorld
void Ca6aa20::FUN_00a6aa20(na6aa20::Pair* pair, na6aa20::Transform* a, na6aa20::Transform* b)
{
    na6aa20::Body* bodyA = pair->bodyA;
    na6aa20::Body* bodyB = pair->bodyB;
    a->FUN_008fda60(&bodyB->transform);
    b->FUN_008fda60(&bodyA->transform);
    rotA = a->rot;
    rotB = b->rot;
    transA = a->trans;
    transB = b->trans;
}
}   // namespace f3m_00a6aa20

// @f3 0x00a703b0 (community match, verified in this file)
namespace wa703b0 {
extern unsigned long DAT_010f3170;
struct Mem {
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
inline Mem* GetMem() throw() { return (Mem*)TlsGetValue(DAT_010f3170); }

class RefObj {
public:
    virtual ~RefObj() throw() {}
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference() throw()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                delete this;
        }
    }
};

template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() throw()
    {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            GetMem()->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};

struct Entry12 { int a; int b; RefObj* obj; };
struct Entry8 { int a; int b; };

struct FUN_00a703b0 : RefObj {
    Array<Entry12> entries;
    Array<Entry8> pairs;
    Array<RefObj*> objects;
    virtual ~FUN_00a703b0() throw();
};

// pdb: hkpPoweredChainMapper::~hkpPoweredChainMapper | hkpPoweredChainMapper.obj | fnv360_0822_retail, call_seq, high
FUN_00a703b0::~FUN_00a703b0() throw()
{
    for (int i = 0; i < entries.size; i++) {
        if (entries.data[i].obj)
            entries.data[i].obj->removeReference();
    }
    for (int i = 0; i < objects.size; i++)
        objects.data[i]->removeReference();
}
}

// @f3 0x00a64d70 (community match, verified in this file)
namespace f3m_00a64d70 {
namespace f3m_00a64d70 {
struct Me;
struct Timer {
    unsigned int unk00;
    unsigned short id;
};
struct TimerSet {
    int unk00; int unk04; int unk08;
    int FUN_009227d0(Timer* t, int flag);
    void FUN_00922710(Timer* t, int flag);
};
struct Client {
    virtual void v0();
    virtual void Attach(Me* stream);
};
struct First {
    virtual void f0();
    int unk04;
};
struct Me {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void Flush();
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
    TimerSet timers;
    unsigned int unk20;
    void FUN_00a64d70(const char* name, unsigned int mask, Timer* timer);
};
struct Outer : First, Me {};
}

// pdb: hkStreamStatisticsCollector::_startObject | hkStreamStatisticsCollector.obj | fnv360_0822_retail, objrun, medium
// pdb params: name, object, size
void f3m_00a64d70::Me::FUN_00a64d70(const char* name, unsigned int mask, Timer* timer)
{
    int masked = (int)(unk10 & 0x3fffffff);
    if (masked <= unk0C + 0x46)
        return;
    if (!timer)
        return;
    if (timers.FUN_009227d0(timer, 0))
        return;
    timers.FUN_00922710(timer, 1);
    unsigned int id = timer->id & 0x7fff;
    if ((unk20 & mask) == 0)
        id = 0;
    int len = 0;
    int pad = 0;
    if (name != 0) {
        len = FUN_009233f0(name) + 1;
        pad = len % 2;
    }
    Array419* stream = (Array419*)&unk08;
    int total = pad + len;
    unsigned char* p = FUN_00a64bf0(stream, total);
    p[0] = 0x50;
    p[1] = (unsigned char)len + (unsigned char)pad;
    *(unsigned short*)(p + 2) = (unsigned short)id;
    int v;
    if (!id) v = 0; else v = DAT_010f3400->Slot15(id);
    *(unsigned short*)(p + 4) = (unsigned short)v;
    if (len > 0) {
        FUN_009234e0(p + 6, name, len);
        if (pad != 0)
            p[len + 6] = 0;
    }
    ((Client*)timer)->Attach((Outer*)((char*)this - 8));
    Flush();
}
}   // namespace f3m_00a64d70

// @f3 0x00a62320 (community match, verified in this file)
namespace f3m_00a62320 {
struct A62320Obj {
    unsigned int unk00;
    unsigned short unk04;

    void FUN_00a622e0();
    A62320Obj* FUN_00a62320(unsigned char flag);
};

struct A62320Pool {
    void FUN_008f6d90(A62320Obj* obj, int value, int category);
};

// pdb: hkServerDebugDisplayHandler::`scalar deleting destructor' | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, vtable, medium
A62320Obj* A62320Obj::FUN_00a62320(unsigned char flag)
{
    FUN_00a622e0();

    if ((flag & 1) != 0) {
        void* tls = f3m_00a67460::TlsGetValue(DAT_010f3170);
        unsigned short value = unk04;
        reinterpret_cast<A62320Pool*>(tls)->FUN_008f6d90(this, value, 0x35);
    }

    return this;
}
}   // namespace f3m_00a62320

// @f3 0x00a61590 (community match, verified in this file)
#include <windows.h>
extern unsigned int DAT_010f3170;
namespace f3m_00a61590 {

extern "C" unsigned long (__stdcall* const DAT_00fdf044)(unsigned long);

void FUN_00a61170();

struct Context_a61590 {
    void FUN_008f6d90(void* ptr, unsigned int size, unsigned int category);
};

struct Class_a61590 {
    int unk00;
    unsigned short unk04;

    int FUN_00a61590(unsigned char flag);
};

// pdb: hkProcessFactory::`scalar deleting destructor' | hkProcessFactory.obj | fnv360_0822_retail, vtable, high
int Class_a61590::FUN_00a61590(unsigned char flag) {
    FUN_00a61170();
    if (flag & 1) {
        void* tlsCtx = (void*)DAT_00fdf044(DAT_010f3170);
        ((Context_a61590*)tlsCtx)->FUN_008f6d90(this, unk04, 0x35);
    }
    return (int)this;
}
}   // namespace f3m_00a61590

// @f3 0x00a76280 (community match, verified in this file)
namespace f3m_00a76280 {
void __stdcall FUN_00a76280(unsigned char* data, int unused)
{
    *data = 0;
}
}   // namespace f3m_00a76280

// @f3 0x00a60f80 (community match, verified in this file)
namespace f3m_00a60f80 {
struct SlotEntry;
int MatchSlotKey(void* key, SlotEntry* entry);
struct Slot60 { void* key; unsigned int unk04, unk08, unk0C, unk10; };
struct Other60 {
    unsigned int unk000, unk004, unk008, unk00C, unk010, unk014;
    int unk018;
    int unk01C;
    void FUN_00908a00();
};
struct Owner60 {
    unsigned int unk00, unk04, unk08;
    Slot60* slots;
    int count;
    unsigned int unk14;
    Other60* other;
    int FUN_00a60f80(SlotEntry* entry);
};
// pdb: hkProcessFactory::getProcessId | hkProcessFactory.obj | fnv360_0822_retail, call_seq, medium
// pdb params: name
int Owner60::FUN_00a60f80(SlotEntry* entry)
{
    other->FUN_00908a00();
    int i = 0;
    for (; i < count; ++i) {
        void* key = slots[i].key;
        if (MatchSlotKey(key, entry) == 0) {
            Other60* o = other;
            o->unk018 = -1;
            o->unk01C = -1;
            LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(o));
            return i;
        }
    }
    Other60* o = other;
    o->unk018 = -1;
    o->unk01C = -1;
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(o));
    return -1;
}
}   // namespace f3m_00a60f80

// @f3 0x00a64ac0 (community match, verified in this file)
namespace f3m_00a64ac0 {
struct FUN_00cb1a60_t {
    void ResetEntries();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct FUN_00a64ac0_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FUN_00cb1a60_t sub1c;
    unsigned int unk28;
    void FUN_00a64ac0(int value);
};
// pdb: hkStreamStatisticsCollector::beginSnapshot | hkStreamStatisticsCollector.obj | fnv360_0822_retail, call_seq, medium
// pdb params: statisticClasses
void FUN_00a64ac0_cls::FUN_00a64ac0(int value)
{
    sub1c.ResetEntries();
    unk28 = value;
}
}   // namespace f3m_00a64ac0

// @f3 0x00a63c00 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a63c00 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct Mem417 {
    void FUN_008f6d90(void* p, unsigned int bytes, int tag);
};

struct AdjDerived417 {
    void* vptr;
    unsigned short unk04;
    unsigned short unk06;
    void FUN_00a633f0();
    AdjDerived417* FUN_00a63c00(int flags);
};

// pdb: hkInspectProcess::`scalar deleting destructor' | hkInspectProcess.obj | fnv360_0822_retail, vtable, medium
AdjDerived417* AdjDerived417::FUN_00a63c00(int flags) {
    FUN_00a633f0();
    if (flags & 1) {
        Mem417* mem = (Mem417*)TlsGetValue(DAT_010f3170);
        mem->FUN_008f6d90(this, unk04, 0x35);
    }
    return this;
}
}   // namespace f3m_00a63c00

// @f3 0x00a797b0 (community match, verified in this file)
namespace f3m_00a797b0 {
namespace f3m_00a797b0 {
struct Vec4 { float x,y,z,w; void Clear() { x=y=z=w=0.0f; } };
struct State { Vec4 original[3], filtered[3], otherOriginal[3], otherFiltered[3]; };
// pdb: hkPoweredChain_DisableMotorInMatrixRow_NextConstraint | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_open, low
// pdb params: motorsState, mtxNextOffdiag
void FUN_00a797b0(const unsigned char* flags, State* state) {
    if (!*flags) return;
    if (*flags & 3) { state->filtered[0].Clear(); state->otherFiltered[0].Clear(); }
    if (*flags & 12) { state->filtered[1].Clear(); state->otherFiltered[1].Clear(); }
    if (*flags & 48) { state->filtered[2].Clear(); state->otherFiltered[2].Clear(); }
}
}
}   // namespace f3m_00a797b0

// @f3 0x00a63060 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a63060 {
namespace f3m_00a63060 {
struct Heap { void FUN_008f6d90(void* memory,unsigned int bytes,int tag) throw(); };
extern __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned int index);
struct FUN_00a63060 {
    virtual ~FUN_00a63060() throw();
    unsigned short allocationSize,unk06;
    // pdb: hkDisplaySerializeIStream::`scalar deleting destructor' | hkDisplaySerializeIStream.obj | fnv360_0822_retail, vtable, medium
    static void operator delete(void* memory) throw(){
        Heap* heap=FUN_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(memory,((FUN_00a63060*)memory)->allocationSize,13);
    }
};
void emit_deleting_destructor(){ FUN_00a63060 instance; }
}
}   // namespace f3m_00a63060

// @f3 0x00a63eb0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a63eb0 {

extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct MemCtx {
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};

struct Obj {
    void* vtbl;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void* FUN_00a63c30(int arg);
};

// pdb: hkStatisticsProcess::create | hkStatisticsProcess.obj | fnv360_0822_retail, objrun, medium
// pdb params: contexts
void* __cdecl FUN_00a63eb0(int arg1) {
    MemCtx* ctx = (MemCtx*)DAT_00d9b080(DAT_010f3170);
    Obj* obj = (Obj*)ctx->FUN_008f6d30(0x44, 0x35);
    obj->memSizeAndFlags = 0x44;
    void* r = obj->FUN_00a63c30(arg1);
    if (r)
        return (char*)r + 8;
    return 0;
}
}   // namespace f3m_00a63eb0

// @f3 0x00a77800 (community match, verified in this file)
namespace f3m_00a77800 {
namespace f3m_00a77800 {
extern void __cdecl FUN_00901f10(void*, int);
template<class T> struct hkArray {
    T* data;
    int size;
    int capacity;
    void pushBack(const T& value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        ++size;
    }
};
struct hkReferencedObject {
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void addReference() { if (memSizeAndFlags != 0) ++referenceCount; }
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    hkArray<hkReferencedObject*> objects;
    void FUN_00a77800(hkReferencedObject* object);
};
void Owner::FUN_00a77800(hkReferencedObject* object)
{
    object->addReference();
    objects.pushBack(object);
}
}
}   // namespace f3m_00a77800

// @f3 0x00a6b5a0 (community match, verified in this file)
extern void* const DAT_00e87080[];
namespace f3m_00a6b5a0 {
namespace f3m_00a6b5a0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void setZero4() { x = y = z = w = 0.0f; }
};
struct Matrix3 {
    Vec4 col0, col1, col2;
    void setZero() { col0.setZero4(); col1.setZero4(); col2.setZero4(); }
};
struct Base {
    void* const* vptr;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    Base(int type);
};
struct Constraint : Base {
    Matrix3 basis;
    Vec4 pivot;
    Constraint();
};
// pdb: hkDisplayPlane::hkDisplayPlane | hkDisplayPlane.obj | fnv360_0822_retail, objrun_prop, medium
Constraint::Constraint() : Base(7)
{
    vptr = DAT_00e87080;
    pivot.setZero4();
    basis.setZero();
}
}
}   // namespace f3m_00a6b5a0

// @f3 0x00a732b0 (community match, verified in this file)
namespace f3m_00a732b0 {
struct FUN_00a732b0_Obj {
    void (*unk00)();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Vector417 first;
    Vector417 second;
    float unk40;
    float unk44;

    FUN_00a732b0_Obj* FUN_00a732b0(void* a, const Vector417* b,
        const Vector417* c, float d, float e);
};

extern void FUN_00e83a7c();
void __stdcall FUN_009ae990(void* a, int b);

// pdb: hkpReorientAction::hkpReorientAction | hkpReorientAction.obj | fnv360_0822_retail, call_seq, high
// pdb params: body, rotationAxis, upAxis, strength, damping
FUN_00a732b0_Obj* __thiscall FUN_00a732b0_Obj::FUN_00a732b0(
    void* a, const Vector417* b, const Vector417* c, float d, float e)
{
    FUN_009ae990(a, 0);

    unk00 = &FUN_00e83a7c;

    first.x = b->x;
    first.y = b->y;
    first.z = b->z;
    first.w = b->w;

    second.x = c->x;
    second.y = c->y;
    second.z = c->z;
    second.w = c->w;

    unk40 = d;
    unk44 = e;

    return this;
}
}   // namespace f3m_00a732b0

// @f3 0x00a60dd0 (community match, verified in this file)
namespace f3m_00a60dd0 {
namespace f3m_00a60dd0 {
struct hkBaseObject { virtual ~hkBaseObject() throw() {} };
struct hkReferencedObject : hkBaseObject {
    unsigned short memSizeAndFlags;
    short referenceCount;
    void addReference() throw() { if (memSizeAndFlags != 0) ++referenceCount; }
    void removeReference() throw()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                delete this;
        }
    }
};
struct Owner {
    void* vtable;
    int unk04;
    hkReferencedObject* shape;
    void FUN_00a60dd0(hkReferencedObject* newShape);
};
// pdb: hkIArchive::setStreamReader | hkIArchive.obj | fnv360_0822_retail, objrun, medium
// pdb params: newBuf
void Owner::FUN_00a60dd0(hkReferencedObject* newShape)
{
    newShape->addReference();
    shape->removeReference();
    shape = newShape;
}
}
}   // namespace f3m_00a60dd0

// @f3 0x00a65510 (community match, verified in this file)
namespace f3m_00a65510 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);   // TlsGetValue
struct FreeNode { FreeNode* next; };
struct FreeList {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) throw() { ++count; b->next = head; head = b; }
};
struct ThreadMemory {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int limit;
    int unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    FreeList row6;
    void FUN_008f6890(int row, void* p, int tag) throw();
};
inline ThreadMemory* Mem() throw() { return (ThreadMemory*)DAT_00d9b080(DAT_010f3170); }
struct Object {
    void FUN_00a8d0f0();   // destructor body
    Object* FUN_00a65510(unsigned int flags);
    static __forceinline void Free(void* p) throw()
    {
        if (p) {
            ThreadMemory* pool = Mem();
            FreeList* bucket = &pool->row6;
            if (*(volatile int*)&bucket->count >= pool->limit)
                pool->FUN_008f6890(6, p, 0x1b);
            else
                bucket->Push((FreeNode*)p);
        }
    }
};
}

// pdb: hkMonitorStreamAnalyzer::Node::`scalar deleting destructor' | hkStreamStatisticsCollector.obj | fnv360_0822_retail, call_seq, medium
f3m_00a65510::Object* f3m_00a65510::Object::FUN_00a65510(unsigned int flags)
{
    FUN_00a8d0f0();
    if (flags & 1)
        Free(this);
    return this;
}

// @f3 0x00a70830 (community match, verified in this file)
namespace f3m_00a70830 {
extern "C" void __cdecl FUN_00901f10(void* apArray, int aiElemSize);

struct ListenerArray
{
    void** m_data;
    unsigned short m_usSize;
    unsigned short m_usMaxSize;
    void** m_data2;
    unsigned short m_usSize2;
    unsigned short m_usMaxSize2;

    int IndexOf(void* apItem) const
    {
        for (int i = 0; i < m_usSize; ++i)
            if (m_data[i] == apItem)
                return i;
        return -1;
    }
};

struct ActorRef
{
    char m_unk00[0xcc];
    void* m_pListenerList;

    ListenerArray* FUN_00a70a70();
    void FUN_0090b880(void* apListener);
};

struct ActorPair
{
    void* m_pFirst;
    void* m_pSecond;
};

struct PairArray
{
    ActorPair* m_pData;
    int m_iSize;
    int m_iCapFlags;
};

struct ShapePairHost
{
    char m_unk00[0x30];
    int m_kListener;
    PairArray m_kPairs;

    void FUN_00a70830(ActorRef* apA, ActorRef* apB);
};

void ShapePairHost::FUN_00a70830(ActorRef* apA, ActorRef* apB)
{
    void* hi;
    void* lo;
    if (apA > apB)
    {
        hi = apA;
        lo = apB;
    }
    else
    {
        hi = apB;
        lo = apA;
    }

    PairArray* arr = &m_kPairs;
    int i = 0;
    if (arr->m_iSize > 0)
    {
        ActorPair* it = arr->m_pData;
        do
        {
            if (it->m_pFirst == hi && it->m_pSecond == lo)
            {
                if (i > 0)
                    return;
                break;
            }
            ++i;
            ++it;
        } while (i < arr->m_iSize);
    }

    if (arr->m_iSize == (arr->m_iCapFlags & 0x3fffffff))
        FUN_00901f10(arr, 8);

    ActorPair* data = arr->m_pData;
    int n = arr->m_iSize;
    data[n].m_pFirst = hi;
    data[n].m_pSecond = lo;
    ++arr->m_iSize;

    void* pListener = this ? &m_kListener : 0;
    if (apA->FUN_00a70a70()->IndexOf(pListener) < 0)
        apA->FUN_0090b880(this ? &m_kListener : 0);

    void* pListener2 = this ? &m_kListener : 0;
    if (apB->FUN_00a70a70()->IndexOf(pListener2) < 0)
        apB->FUN_0090b880(this ? &m_kListener : 0);
}
}   // namespace f3m_00a70830

// @f3 0x00a622e0 (community match, verified in this file)
namespace f3m_00a622e0 {
namespace f3m_00a622e0 {
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};
class hkBaseD60B {
public:
    virtual ~hkBaseD60B() {}
    int unk04;
};
class ReferencedObject : public hkBaseObject {
public:
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
struct Member { void FUN_00908ab0(int flag) throw(); };
}
class FUN_00a622e0 : public f3m_00a622e0::ReferencedObject, public f3m_00a622e0::hkBaseD60B {
public:
    f3m_00a622e0::Member* member;
    ~FUN_00a622e0();
};

// pdb: hkServerDebugDisplayHandler::~hkServerDebugDisplayHandler | hkServerDebugDisplayHandler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
FUN_00a622e0::~FUN_00a622e0()
{
    if (member)
        member->FUN_00908ab0(1);
}
}   // namespace f3m_00a622e0

// @f3 0x00a7df30 (community match, verified in this file)
namespace f3m_00a7df30 {
struct RefObj00a7df30 {
    virtual ~RefObj00a7df30();
    unsigned short w04;
    short refs;
};

struct Holder00a7df30 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    RefObj00a7df30* ptr1C;
    void FUN_00a7df30(RefObj00a7df30* p);
};

void Holder00a7df30::FUN_00a7df30(RefObj00a7df30* p) {
    if (p && p->w04 != 0) {
        p->refs++;
    }
    RefObj00a7df30* old = ptr1C;
    if (old && old->w04 != 0) {
        if (--old->refs == 0) {
            delete old;
        }
    }
    ptr1C = p;
}
}   // namespace f3m_00a7df30

// @f3 0x00a628d0 (community match, verified in this file)
namespace f3m_00a628d0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a628d0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a628d0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009ee850();
    D00a628d0* FUN_00a628d0(unsigned int flags);
};
// pdb: hkDisplaySerializeOStream::`scalar deleting destructor' | hkDisplaySerializeOStream.obj | fnv360_0822_retail, vtable, medium
D00a628d0* D00a628d0::FUN_00a628d0(unsigned int flags)
{
    FUN_009ee850();
    if (flags & 1) {
        D00a628d0Heap* heap = (D00a628d0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0xd);
    }
    return this;
}
}

// @f3 0x00a644e0 (community match, verified in this file)
namespace f3m_00a644e0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a644e0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a644e0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a63e10();
    D00a644e0* FUN_00a644e0(unsigned int flags);
};
// pdb: hkStatisticsProcess::`scalar deleting destructor' | hkStatisticsProcess.obj | fnv360_0822_retail, vtable, medium
D00a644e0* D00a644e0::FUN_00a644e0(unsigned int flags)
{
    FUN_00a63e10();
    if (flags & 1) {
        D00a644e0Heap* heap = (D00a644e0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x00a64810 (community match, verified in this file)
namespace f3m_00a64810 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a64810Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a64810 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a64750();
    D00a64810* FUN_00a64810(unsigned int flags);
};
// pdb: hkDebugDisplayProcess::`scalar deleting destructor' | hkDebugDisplayProcess.obj | fnv360_0822_retail, vtable, medium
D00a64810* D00a64810::FUN_00a64810(unsigned int flags)
{
    FUN_00a64750();
    if (flags & 1) {
        D00a64810Heap* heap = (D00a64810Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x00a649a0 (community match, verified in this file)
namespace f3m_00a649a0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a649a0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a649a0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a64860();
    D00a649a0* FUN_00a649a0(unsigned int flags);
};
// pdb: hkpWorldViewerBase::`scalar deleting destructor' | hkpWorldViewerBase.obj | fnv360_0822_retail, vtable, medium
D00a649a0* D00a649a0::FUN_00a649a0(unsigned int flags)
{
    FUN_00a64860();
    if (flags & 1) {
        D00a649a0Heap* heap = (D00a649a0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x00a65570 (community match, verified in this file)
namespace f3m_00a65570 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a65570Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a65570 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a64b90();
    D00a65570* FUN_00a65570(unsigned int flags);
};
// pdb: hkStreamStatisticsCollector::`scalar deleting destructor' | hkStreamStatisticsCollector.obj | fnv360_0822_retail, vtable_prefix, high
D00a65570* D00a65570::FUN_00a65570(unsigned int flags)
{
    FUN_00a64b90();
    if (flags & 1) {
        D00a65570Heap* heap = (D00a65570Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}

// @f3 0x00a66e90 (community match, verified in this file)
namespace f3m_00a66e90 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a66e90Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
extern void* DAT_00dcc494[];
struct D00a66e90 {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    D00a66e90* FUN_00a66e90(unsigned int flags);
};
// pdb: hkpShapeDisplayBuilder::`scalar deleting destructor' | hkpShapeDisplayBuilder.obj | fnv360_0822_debug, objrun_open, low
D00a66e90* D00a66e90::FUN_00a66e90(unsigned int flags)
{
    vtable = DAT_00dcc494;
    if (flags & 1) {
        D00a66e90Heap* heap = (D00a66e90Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x00a6b9a0 (community match, verified in this file)
namespace f3m_00a6b9a0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a6b9a0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a6b9a0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a28830();
    D00a6b9a0* FUN_00a6b9a0(unsigned int flags);
};
// pdb: hkDisplaySphere::`scalar deleting destructor' | hkDisplaySphere.obj | fnv360_0822_retail, vtable, medium
D00a6b9a0* D00a6b9a0::FUN_00a6b9a0(unsigned int flags)
{
    FUN_00a28830();
    if (flags & 1) {
        D00a6b9a0Heap* heap = (D00a6b9a0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 8);
    }
    return this;
}
}

// @f3 0x00a70a70 (community match, verified in this file)
namespace f3m_00a70a70 {
struct ThreadMemory {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44;
    void* freeList;
    int freeCount;
    void* FUN_008f6800(int row, int size) throw();
};
extern "C" __declspec(dllimport) ThreadMemory* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;
struct ListenerArray {
    void** m_data;
    unsigned short m_usSize;
    unsigned short m_usMaxSize;
    ListenerArray() : m_data(0), m_usSize(0), m_usMaxSize(0x8000) {}
};
struct ListenerLists {
    ListenerArray first;
    ListenerArray second;
    static void* operator new(unsigned int) throw()
    {
        ThreadMemory* mem = FUN_00d9b080(DAT_010f3170);
        void* p = mem->freeList;
        if (p) {
            mem->freeCount--;
            mem->freeList = *(void**)p;
        } else {
            p = mem->FUN_008f6800(2, 4);
        }
        return p;
    }
};
struct ActorRef {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8;
    ListenerLists* m_pListenerList;
    ListenerArray* FUN_00a70a70();
};
// pdb: hkpEntity::getEntityListeners | hkpDisableEntityCollisionFilter.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpWorldObject::getProperty)
ListenerArray* ActorRef::FUN_00a70a70()
{
    if (!m_pListenerList)
        m_pListenerList = new ListenerLists;
    return &m_pListenerList->second;
}
}

// @f3 0x00a61d20 (community match, verified in this file)
namespace f3m_00a61d20 {
namespace f3m_00a61d20 {
extern "C" __declspec(dllimport) void __stdcall FUN_00d9b0a0(void* cs);
struct hkBool {
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
};
struct CriticalSection {
    int cs[6];
    int owner;
    int recursion;
    void FUN_00908a00();
    void leave() { owner = -1; recursion = -1; FUN_00d9b0a0(this); }
};
struct World {
    void FUN_009ee8f0(int value);
    void FUN_009ee560(int value);
    void FUN_00a623a0(int value);
    void FUN_009ee8d0(int value);
    hkBool FUN_009ee770();
};
struct Setup {
    int unk00;
    World* world;
    CriticalSection* lock;
    int FUN_00a61d20(int a, int b, int c);
};
// pdb: hkServerDebugDisplayHandler::displayGeometry | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: hkServerDebugDisplayHandler::displayLine)
// pdb params: geometries, color, id, tag
int Setup::FUN_00a61d20(int a, int b, int c)
{
    lock->FUN_00908a00();
    if (world) {
        world->FUN_009ee8f0(0x15);
        world->FUN_009ee560(7);
        world->FUN_00a623a0(a);
        world->FUN_009ee8f0(b);
        world->FUN_009ee8d0(c);
    }
    bool ok = world && world->FUN_009ee770();
    lock->leave();
    return ok ? 0 : 1;
}
}
}   // namespace f3m_00a61d20

// @f3 0x00a6ac00 (community match, verified in this file)
namespace f3m_00a6ac00 {
namespace f3m_00a6ac00 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct Constraint {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    Vec4 pivotB;
    Vec4 axisB;
    Vec4 pivotA;
    float minLimit, maxLimit, tau;
    int type;
    void FUN_00a6ac00(float tau, float minLimit, float maxLimit, int type, const Vec4& pivotA, const Vec4& pivotB, const Vec4& axisB);
};
// pdb: hkDisplaySemiCircle::setParameters | hkDisplaySemiCircle.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: radius, thetaMin, thetaMax, numSegments, center, normal, startPerp
void Constraint::FUN_00a6ac00(float t, float lo, float hi, int k, const Vec4& a, const Vec4& b, const Vec4& c)
{
    pivotA = a;
    pivotB = b;
    axisB = c;
    type = k;
    minLimit = lo;
    maxLimit = hi;
    tau = t;
}
}
}   // namespace f3m_00a6ac00

// @f3 0x00a6f330 (community match, verified in this file)
#include <new>
namespace f3m_00a6f330 {
namespace f3m_00a6f330 {
struct P00a6f330Flag { int m_finishing; };
struct FUN_009a1c00 {
    int unk00;
    FUN_009a1c00(P00a6f330Flag flag) throw();
};
// pdb: finishLoadedObjecthkpSimpleContactConstraintAtom | hkpConstraintSolverReflections.obj | tesv_win, objrun_prop, low
void FUN_00a6f330(void* p)
{
    P00a6f330Flag flag;
    flag.m_finishing = 1;
    new (p) FUN_009a1c00(flag);
}
}
}   // namespace f3m_00a6f330

// @f3 0x00a7e220 (community match, verified in this file)
namespace f3m_00a7e220 {
namespace f3m_00a7e220 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct Contact { Vec4 position; Vec4 normal; Vec4 extra; };
struct Collector {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    Vec4* normals;
    Vec4* extras;
    Vec4* positions;
    int count;
    void FUN_00a7e220(const Contact& contact);
};
// pdb: hkpConvexPenetrationUtil::addPointToSimplex | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, objrun, medium
// pdb params: p
void Collector::FUN_00a7e220(const Contact& contact)
{
    int i = count;
    positions[i] = contact.position;
    normals[i] = contact.normal;
    extras[i] = contact.extra;
    count = i + 1;
}
}
}   // namespace f3m_00a7e220

// @f3 0x00a63780 (community match, verified in this file)
namespace f3m_00a63780 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F00a63780Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F00a63780Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F00a63780Base8 { int unk[10]; };
struct FUN_00a63380 : F00a63780Base0, F00a63780Base8 {
    FUN_00a63380(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F00a63780Heap* heap = (F00a63780Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F00a63780Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkInspectProcess::create | hkInspectProcess.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: contexts
F00a63780Base8* FUN_00a63780(void* arg)
{
    return new FUN_00a63380(arg);
}
}

// @f3 0x00a60c60 (community match, verified in this file)
#include <windows.h>
extern unsigned int DAT_010f3170;
namespace f3m_00a60c60 {


struct Object60c60 {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
};

struct Pool60c60 {
    Object60c60* FUN_008f6d30(int a, int b);
};

// pdb: hkSystemClockcreate | hkSystemClock.obj | fnv360_0822_retail, uvref, medium
void __cdecl FUN_00a60c60()
{
    Pool60c60* pool = static_cast<Pool60c60*>(
        TlsGetValue(DAT_010f3170));
    Object60c60* object = pool->FUN_008f6d30(8, 0x15);
    object->unk04 = 8;
    object->unk06 = 1;
    object->unk00 = 0xe86c28;
}
}   // namespace f3m_00a60c60

// @f3 0x00a77010 (community match, verified in this file)
namespace f3m_00a77010 {
namespace f3m_00a77010 {
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};
class __declspec(novtable) ReferencedObject : public hkBaseObject {
public:
    unsigned short memSizeAndFlags;
    short referenceCount;
    __declspec(nothrow) void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                delete this;
        }
    }
};
class __declspec(novtable) ShapeBase : public ReferencedObject {
public:
    int unk08;
    int type;
};
class Interface {
public:
    virtual ~Interface() {}
    int unk14;
};
}
class FUN_00a77010 : public f3m_00a77010::ShapeBase, public f3m_00a77010::Interface {
public:
    virtual ~FUN_00a77010();
    f3m_00a77010::ReferencedObject* first;
    f3m_00a77010::ReferencedObject* second;
};

// pdb: hkpConvexPieceMeshShape::~hkpConvexPieceMeshShape | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, call_seq, medium
FUN_00a77010::~FUN_00a77010()
{
    second->removeReference();
    first->removeReference();
}
}   // namespace f3m_00a77010

// @f3 0x00a686c0 (community match, verified in this file)
namespace f3m_00a686c0 {
struct FUN_00a686c0_Class;

extern void FUN_00e80a58();
extern void FUN_00e86f9c();
extern void FUN_00e86f7c();
extern void FUN_00e86f6c();
extern void FUN_00e86f5c();

struct FUN_00a686c0_Class {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* volatile unk28;
    void* unk2C;

    void __thiscall FUN_00a648d0(int value);
    FUN_00a686c0_Class* __thiscall FUN_00a686c0(int first, int second);
};

// pdb: hkpContactPointViewer::hkpContactPointViewer | hkpContactPointViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: contexts, color
FUN_00a686c0_Class* __thiscall FUN_00a686c0_Class::FUN_00a686c0(int first, int second) {
    this->FUN_00a648d0(first);

    this->unk28 = (void*)&FUN_00e80a58;
    this->unk00 = (void*)&FUN_00e86f9c;
    this->unk08 = (void*)&FUN_00e86f7c;
    this->unk20 = (void*)&FUN_00e86f6c;
    this->unk28 = (void*)&FUN_00e86f5c;
    this->unk2C = (void*)second;

    return this;
}
}   // namespace f3m_00a686c0

// @f3 0x00a67b10 (community match, verified in this file)
namespace f3m_00a67b10 {
extern void __stdcall FUN_009a4660(int a);

struct A67B10Object {
    int unk00;
    int unk04;
    int unk08;

    int* FUN_00a67b10(int value);
};

// pdb: hkDisplayConvex::hkDisplayConvex | hkDisplayConvex.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: geom
int* A67B10Object::FUN_00a67b10(int value)
{
    FUN_009a4660(6);
    unk08 = value;
    unk00 = 0x00e86f44;
    return reinterpret_cast<int*>(this);
}
}   // namespace f3m_00a67b10

// @f3 0x00a646d0 (community match, verified in this file)
namespace f3m_00a646d0 {
struct DispatchTarget {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Dispatch(void* value);
};

struct DispatchView {
    void FUN_00a646d0(void* value);
};

// pdb: hkDebugDisplayProcess::sendMemStatsDump | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: data, length
void DispatchView::FUN_00a646d0(void* value) {
    DispatchTarget* target = *reinterpret_cast<DispatchTarget**>(
        reinterpret_cast<char*>(this) - 8);
    target->Dispatch(value);
}
}   // namespace f3m_00a646d0

// @f3 0x00a6f530 (community match, verified in this file)
namespace f3m_00a6f530 {
struct FUN_00d50c90;
struct BridgeAtom {
    unsigned unk00, unk04;
    FUN_00d50c90* constraint;
    void FUN_00d21ce0(FUN_00d50c90* value);
};
void __cdecl FUN_00a6f530(BridgeAtom* atom) {
    if (atom)
        atom->FUN_00d21ce0(atom->constraint);
}
}   // namespace f3m_00a6f530

// @f3 0x00a63350 (community match, verified in this file)
namespace f3m_00a63350 {
struct FUN_00a63350_Owner {
    void FUN_00a630b0(unsigned int a, unsigned int b);
    void FUN_00a632e0(unsigned int a);
};

// pdb: myTrackedObjectCallback | hkInspectProcess.obj | fnv360_0822_retail, caller_sim, medium
void __cdecl FUN_00a63350(unsigned int a, unsigned int b, char flag,
                          FUN_00a63350_Owner* owner) {
    if (flag != 0) {
        owner->FUN_00a630b0(a, b);
    } else {
        owner->FUN_00a632e0(a);
    }
}
}   // namespace f3m_00a63350

// @f3 0x00a64550 (community match, verified in this file)
extern unsigned int DAT_0116c49c;
namespace f3m_00a64550 {
extern "C" void _ReadWriteBarrier();
struct Target00a64550;
typedef void (__thiscall *Dispatch00a64550)(Target00a64550*, unsigned int, unsigned int, unsigned int, unsigned int);
struct Table00a64550 {
    Dispatch00a64550 slot0;
    Dispatch00a64550 slot1;
    Dispatch00a64550 slot2;
    Dispatch00a64550 slot3;
    Dispatch00a64550 slot4;
    Dispatch00a64550 slot5;
    Dispatch00a64550 slot6;
    Dispatch00a64550 slot7;
    Dispatch00a64550 slot8;
    Dispatch00a64550 slot9;
    Dispatch00a64550 slot10;
    Dispatch00a64550 slot11;
    Dispatch00a64550 slot12;
    Dispatch00a64550 dispatch;
};
struct Target00a64550 { Table00a64550* volatile table; };
struct View00a64550 {
    void FUN_00a64550(unsigned int a, unsigned int b, unsigned int c, unsigned int setting);
};
// pdb: hkDebugDisplayProcess::displayGeometry | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: geometries, transform, color, id, tag
void View00a64550::FUN_00a64550(unsigned int a, unsigned int b, unsigned int c, unsigned int setting) {
    Target00a64550* target = *reinterpret_cast<Target00a64550**>(reinterpret_cast<char*>(this) - 8);
    Table00a64550* table = target->table;
    static_cast<volatile unsigned int&>(setting) = DAT_0116c49c;
    _ReadWriteBarrier();
    table->dispatch(target, a, b, c, setting);
}
}   // namespace f3m_00a64550

// @f3 0x00a64690 (community match, verified in this file)
extern unsigned DAT_0116c49c;
namespace f3m_00a64690 {
extern "C" void _ReadWriteBarrier();

struct TargetA64690;
typedef void (__thiscall *ForwardA64690)(TargetA64690*, void*, void*, unsigned);
struct TableA64690 {
    ForwardA64690 slot0;
    ForwardA64690 slot1;
    ForwardA64690 slot2;
    ForwardA64690 slot3;
    ForwardA64690 slot4;
    ForwardA64690 slot5;
    ForwardA64690 slot6;
    ForwardA64690 slot7;
    ForwardA64690 slot8;
    ForwardA64690 slot9;
    ForwardA64690 forward;
};
struct TargetA64690 {
    const TableA64690* volatile table;
};
struct RelayA64690 {
    unsigned member;
    void FUN_00a64690(void* first, void* second, unsigned last);
};
struct HostA64690 {
    TargetA64690* target;
    unsigned unk04;
    RelayA64690 relay;
};
// pdb: hkDebugDisplayProcess::displayText | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: text, color, id, tag
void RelayA64690::FUN_00a64690(void* first, void* second, unsigned last) {
    HostA64690* host = reinterpret_cast<HostA64690*>(reinterpret_cast<char*>(this) - offsetof(HostA64690, relay));
    TargetA64690* target = host->target;
    const TableA64690* table = target->table;
    static_cast<volatile unsigned&>(last) = DAT_0116c49c;
    _ReadWriteBarrier();
    table->forward(target, first, second, last);
}
}   // namespace f3m_00a64690

// @f3 0x00a64af0 (community match, verified in this file)
namespace f3m_00a64af0 {
struct Member00a64af0 {
    void FUN_00922680();
};
struct State00a64af0 {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int value;
    unsigned int unk18;
    Member00a64af0 member;
    void FUN_00a64af0();
};
// pdb: hkStreamStatisticsCollector::reset | hkStreamStatisticsCollector.obj | fnv360_0822_retail, call_seq, medium
void State00a64af0::FUN_00a64af0() {
    member.FUN_00922680();
    value = 0;
}
}   // namespace f3m_00a64af0

// @f3 0x00a66fa0 (community match, verified in this file)
namespace f3m_00a66fa0 {
namespace f3m_00a66fa0 {
struct Vector4 { float x, y, z, w; };
struct FUN_009a4660 {
    virtual void v00();
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
    FUN_009a4660(int);
};
class FUN_00a66fa0 : public FUN_009a4660 {
public:
    virtual ~FUN_00a66fa0();
    Vector4 unk60;
    Vector4 unk70;
    FUN_00a66fa0(const Vector4* a, const Vector4* b);
};
// pdb: hkDisplayAABB::hkDisplayAABB | hkDisplayAABB.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: min, max
FUN_00a66fa0::FUN_00a66fa0(const Vector4* a, const Vector4* b) : FUN_009a4660(3)
{
    unk60 = *a;
    unk70 = *b;
}
}
}   // namespace f3m_00a66fa0

// @f3 0x00a601b0 (community match, verified in this file)
namespace f3m_00a601b0 {
struct hkThreadMemory {
    void FUN_008f6d90(void* p, int size, int cls) throw();
    void* FUN_008f6d30(int size, int cls) throw();
};
typedef hkThreadMemory* (__stdcall* AllocFn)(int);
extern AllocFn FUN_00d9b080;
extern int DAT_010f3170;
struct Elem8 { int a; int b; };
template <class T> inline void hkCopy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}
struct hkArray8 {
    Elem8* data;
    int size;
    int capacityAndFlags;
    hkArray8& FUN_00a601b0(const hkArray8& o);
};
hkArray8& hkArray8::FUN_00a601b0(const hkArray8& o)
{
    int cap = capacityAndFlags & 0x3fffffff;
    if (cap < o.size) {
        AllocFn mem = FUN_00d9b080;
        if (!(capacityAndFlags & 0x80000000)) {
            hkThreadMemory* m = mem(DAT_010f3170);
            m->FUN_008f6d90(data, cap * sizeof(Elem8), 0x17);
        }
        hkThreadMemory* m2 = mem(DAT_010f3170);
        data = (Elem8*)m2->FUN_008f6d30(o.size * sizeof(Elem8), 0x17);
        capacityAndFlags = o.size | (capacityAndFlags & 0x40000000);
    }
    size = o.size;
    hkCopy(data, o.data, size);
    return *this;
}
}

// @f3 0x00a646e0 (community match, verified in this file)
namespace f3m_00a646e0 {
// FUN_00a646e0: 10-byte thiscall virtual tail-call thunk.
// Golden: mov ecx,[ecx-8]; mov eax,[ecx]; mov edx,[eax+0x3c]; jmp edx
// `this` is a sub-object at +8 of an enclosing; the enclosing's offset 0 holds a
// pointer to an owner object. Load it, then virtual-tail-call the owner's 16th
// vtable slot (offset 0x3c; no virtual destructor, so slot 0 = first virtual).

struct V6e0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};
void V6e0::v0() {}
void V6e0::v1() {}
void V6e0::v2() {}
void V6e0::v7() {}
void V6e0::v8() {}
void V6e0::v10() {}
void V6e0::v14() {}
void V6e0::v15() {}

struct Sub6e0 {
    int unk00;              // offset 0 of Sub (== this)
    void FUN_00a646e0();
};

struct Enc6e0 {
    V6e0* unk00;           // offset 0 of Enc (== this-8)
    int unk04;             // offset 4
    Sub6e0 sub08;          // offset 8
};

FNV_STATIC_ASSERT(offsetof(Sub6e0, unk00) == 0x00);
FNV_STATIC_ASSERT(offsetof(Enc6e0, unk00) == 0x00);
FNV_STATIC_ASSERT(offsetof(Enc6e0, unk04) == 0x04);
FNV_STATIC_ASSERT(offsetof(Enc6e0, sub08) == 0x08);

// pdb: hkDebugDisplayProcess::holdImmediate | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
void Sub6e0::FUN_00a646e0()
{
    // &this->unk00 is (int*)this; two ints back is this-8 == the enclosing.
    Enc6e0* e = (Enc6e0*)((int*)&this->unk00 - 2);
    e->unk00->v15();
}
}   // namespace f3m_00a646e0

// @f3 0x00a61220 (community match, verified in this file)
namespace f3m_00a61220 {
extern "C" unsigned long (__stdcall* const DAT_00fdf044)(unsigned long);

struct Alloc61220 {
    void* __thiscall FUN_008f6d30(int size, int flags);
};

struct Obj61220 {
    void __thiscall FUN_00a610a0();
};

// pdb: hkProcessFactorycreate | hkProcessFactory.obj | fnv360_0822_retail, objrun_open, low
void FUN_00a61220()
{
    Alloc61220* allocator = (Alloc61220*)DAT_00fdf044(DAT_010f3170);
    Obj61220* obj = (Obj61220*)allocator->FUN_008f6d30(0x1c, 0x35);
    *(short*)((char*)obj + 4) = 0x1c;
    obj->FUN_00a610a0();
}
}   // namespace f3m_00a61220

// @f3 0x00a61c30 (community match, verified in this file)
#include <windows.h>
namespace f3m_00a61c30 {
namespace fnv_00dd99d0 {
struct DD99D0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD99D0OStream
{
    void FUN_009ee8f0(unsigned int value);
    void FUN_009ee560(unsigned int value);
    void FUN_00a623a0(const void* v);
    void FUN_009ee950(float value);
    void FUN_009ee8b0(int value);
    void FUN_009ee740(const char* data, int length);
    DD99D0Bool FUN_009ee770();
};

struct DD99D0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    int owner, recursion;
    void FUN_00908a00();
    void leave()
    {
        owner = -1; recursion = -1;
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

extern "C" int __cdecl FUN_009233f0(const char* str);

struct DD99D0DisplayHandler
{
    int unk00;
    DD99D0OStream* m_pDisplayStream;
    DD99D0CriticalSection* m_pSynchronizationLock;

    int FUN_00a61c30(const void* a, const void* b, const void* c, float x, float y, float z, const char* text);
};

// Writes a display command with three vectors, three floats, and a text string to m_pDisplayStream under m_pSynchronizationLock.
// @fnv 0x00dd99d0
// pdb: hkServerDebugDisplayHandler::updateCamera | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: from, to, up, nearPlane, farPlane, fov, name
int DD99D0DisplayHandler::FUN_00a61c30(const void* apVector1, const void* apVector2, const void* apVector3,
                                              float x, float y, float z, const char* text)
{
    m_pSynchronizationLock->FUN_00908a00();
    if (m_pDisplayStream)
    {
        int length = FUN_009233f0(text);
        m_pDisplayStream->FUN_009ee8f0(length + 0x33);
        m_pDisplayStream->FUN_009ee560(0xd);
        m_pDisplayStream->FUN_00a623a0(apVector1);
        m_pDisplayStream->FUN_00a623a0(apVector2);
        m_pDisplayStream->FUN_00a623a0(apVector3);
        m_pDisplayStream->FUN_009ee950(x);
        m_pDisplayStream->FUN_009ee950(y);
        m_pDisplayStream->FUN_009ee950(z);
        m_pDisplayStream->FUN_009ee8b0(length);
        m_pDisplayStream->FUN_009ee740(text, length);
    }
    bool ok = m_pDisplayStream && m_pDisplayStream->FUN_009ee770();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}
}

}   // namespace f3m_00a61c30

// @f3 0x00a64570 (community match, verified in this file)
namespace f3m_00a64570 {
extern char DAT_0116c49c[];

struct Target_a64570 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual int Call30(int a, int b, int c);
};

struct S_a64570 {
    int FUN_00a64570(int a, int b, int c);
};

// variant d: the thunk returns the callee's result
// pdb: hkDebugDisplayProcess::displayGeometry | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: geometries, color, id, tag
int S_a64570::FUN_00a64570(int a, int b, int c)
{
    Target_a64570* target = *(Target_a64570**)((char*)this - 8);
    return target->Call30(a, b, *(int*)DAT_0116c49c);
}
}   // namespace f3m_00a64570

// @f3 0x00a76370 (community match, verified in this file)
extern float DAT_00e19cbc;
namespace f3m_00a76370 {
namespace task2919 {

class RefObjectE483 {
public:
    RefObjectE483() { m_sReferenceCount = 1; }
    virtual ~RefObjectE483();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

struct Kind {
 unsigned char value;
 Kind& operator=(unsigned char v) { value=v; return *this; }
};
class TypedObjectE483 : public RefObjectE483 {
public:
    TypedObjectE483() { m_type = 0; }
    Kind m_type;
};

struct Scalar { float value; Scalar& operator=(float v) { value=v; return *this; } };
class Owner : public TypedObjectE483 {
public:
    Owner(int a, int b);
    virtual ~Owner();
    Scalar m_fCoefficientA;
    Scalar m_fB;
    int m_iB;
    int m_iA;
};
// Constructor: stores a and b in m_iA and m_iB, sets m_fCoefficientA to -1e6, m_fB from DAT_00e19cbc and m_type to 4.
// @fnv 0x00e48390
// pdb: hkpCallbackConstraintMotor::hkpCallbackConstraintMotor | hkpCallbackConstraintMotor.obj | tesv_win, objrun_open, low
Owner::Owner(int a, int b)
{
    m_iA = a;
    m_fCoefficientA = -1e6f;
    double coefficientB = DAT_00e19cbc;
    m_type = 4;
    m_fB = coefficientB;
    m_iB = b;
}


}
}   // namespace f3m_00a76370

// @f3 0x00a763b0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a763b0 {
namespace f3m_763b0 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct AllocObject {
    int unk00;
    unsigned short unk04;
    void __thiscall FUN_00a763e0(void* value);
};
struct TlsContext {
    AllocObject* __thiscall FUN_008f6d30(int size, int category);
};
struct Owner {
    void __thiscall FUN_00a763b0();
};
// pdb: hkpCallbackConstraintMotor::clone | hkpCallbackConstraintMotor.obj | tesv_win, vtable, medium
void __thiscall Owner::FUN_00a763b0() {
    Owner* owner = this;
    TlsContext* context = (TlsContext*)DAT_00d9b080(DAT_010f3170);
    AllocObject* object = context->FUN_008f6d30(0x28, 0x2c);
    object->unk04 = 0x28;
    object->FUN_00a763e0(owner);
}
}
}   // namespace f3m_00a763b0

// @f3 0x00a60e10 (community match, verified in this file)
namespace f3m_00a60e10 {
extern void FUN_00e86c40();
struct FUN_00a60e10_Other {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
};
struct FUN_00a60e10 {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned char unk0C;
    FUN_00a60e10(FUN_00a60e10_Other* other, unsigned char flag);
};
// pdb: hkIArchive::hkIArchive | hkIArchive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: sb, bs
FUN_00a60e10::FUN_00a60e10(FUN_00a60e10_Other* other, unsigned char flag)
{
    unk06 = 1;
    unk00 = (void*)&FUN_00e86c40;
    unk08 = (unsigned int)other;
    unk0C = flag;
    if (other->unk04 != 0)
        ++other->unk06;
}
}   // namespace f3m_00a60e10

// @f3 0x00a71730 (community match, verified in this file)
extern int DAT_00e87b68;
namespace f3m_00a71730 {
struct Sub71730 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void __thiscall hkpBridgeConstraintAtom_init(int value);
};
struct Obj71730 {
    void* vtbl;
    short unk04;
    short word06;
    int unk08;
    Sub71730 sub;
    Obj71730* __thiscall FUN_00a71730(int unused);
};
// pdb: hkpPoweredChainData::hkpPoweredChainData | hkpPoweredChainData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: f
Obj71730* __thiscall Obj71730::FUN_00a71730(int unused)
{
    (void)unused;
    Sub71730* s = &sub;
    word06 = 1;
    vtbl = (void*)&DAT_00e87b68;
    s->hkpBridgeConstraintAtom_init(s->unk08);
    s->hkpBridgeConstraintAtom_init((int)this);
    return this;
}
}   // namespace f3m_00a71730

// @f3 0x00a76aa0 (community match, verified in this file)
extern int DAT_00e84fdc;
extern int DAT_00e84fd0;
extern int DAT_00e84fbc;
extern int DAT_00e84fb0;
extern int DAT_00e84fa4;
namespace f3m_00a76aa0 {
struct Obj76aa0 {
    void* v0;
    int unk04;
    void* v8;
    void* vc;
    void* v10;
    void* v14;
    void __thiscall FUN_00a76aa0();
    void __thiscall FUN_008d34a0();
};
void __thiscall Obj76aa0::FUN_00a76aa0()
{
    v0 = (void*)&DAT_00e84fdc;
    v8 = (void*)&DAT_00e84fd0;
    vc = (void*)&DAT_00e84fbc;
    v10 = (void*)&DAT_00e84fb0;
    v14 = (void*)&DAT_00e84fa4;
    FUN_008d34a0();
}
}   // namespace f3m_00a76aa0

// @f3 0x00a60e80 (community match, verified in this file)
extern int _UNK_010d7c80;
extern int DAT_00dcc494;
namespace f3m_00a60e80 {
struct Other60e80 {
    virtual void release(int value);
    unsigned short unk04;
    short unk06;
};
struct Owner60e80 {
    void* vtbl;
    int unk04;
    Other60e80* other;
    void __thiscall FUN_00a60e80();
};
// pdb: hkIArchive::hkIArchive | hkIArchive.obj | fnv360_0822_retail, objrun, low
// pdb params: mem, memSize, byteswap
void __thiscall Owner60e80::FUN_00a60e80()
{
    Other60e80* other = this->other;
    vtbl = (void*)&_UNK_010d7c80;
    if (other != 0 && other->unk04 != 0) {
        other->unk06 -= 1;
        if (other->unk06 == 0)
            other->release(1);
    }
    vtbl = (void*)&DAT_00dcc494;
}
}   // namespace f3m_00a60e80

// @f3 0x00a6b470 (community match, verified in this file)
namespace f3m_00a6b470 {
struct A6B470StandIn {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    float unk98;
    float unk9C;

    void FUN_00a6b470(float* a, float* b, float* c, float* d);
};

// pdb: hkDisplayPlane::setParameters | hkDisplayPlane.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: normal, perpToNormal, center, extent
void A6B470StandIn::FUN_00a6b470(float* a, float* b, float* c, float* d)
{
    unk60 = a[0];
    unk64 = a[1];
    unk68 = a[2];
    unk6C = a[3];

    unk70 = c[0];
    unk74 = c[1];
    unk78 = c[2];
    unk7C = c[3];

    unk80 = b[0];
    unk84 = b[1];
    unk88 = b[2];
    unk8C = b[3];

    unk90 = d[0];
    unk94 = d[1];
    unk98 = d[2];
    unk9C = d[3];
}
}   // namespace f3m_00a6b470

// @f3 0x00a6bb10 (community match, verified in this file)
namespace f3m_00a6bb10 {
namespace f3_2933 {
struct FUN_009a4660 {
 virtual ~FUN_009a4660();
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
 unsigned int unk58;
 unsigned int unk5c;
 FUN_009a4660(int);
};
struct Quaternion { float x,y,z,w; };
struct FUN_00a6bb10 : FUN_009a4660 {
 Quaternion first,second;
 unsigned int flags;
 float value84,value88;
 FUN_00a6bb10();
 virtual ~FUN_00a6bb10();
};
// pdb: hkDisplayCone::hkDisplayCone | hkDisplayCone.obj | fnv360_0822_retail, objrun, medium
FUN_00a6bb10::FUN_00a6bb10():FUN_009a4660(4),value84(0.0f),value88(0.0f){
 flags=0;
 first.x=first.y=first.z=first.w=0.0f;
 second.x=second.y=second.z=second.w=0.0f;
}
}
}   // namespace f3m_00a6bb10

// @f3 0x00a6ad30 (community match, verified in this file)
namespace f3m_00a6ad30 {
namespace task2931 {
struct FUN_009a4660 { FUN_009a4660(int); virtual void slot00();
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
};
struct Vector { float x,y,z; Vector():x(0.0f),y(0.0f),z(0.0f) {} };
struct Owner : FUN_009a4660 {
 virtual void slot00();
 float f60,f64,f68,f6C,f70,f74,f78,f7C,f80,f84,f88,f8C;
 float f90,f94,f98;
 int unk9C;
 Owner();
};
// pdb: hkDisplaySemiCircle::hkDisplaySemiCircle | hkDisplaySemiCircle.obj | fnv360_0822_retail, objrun, medium
Owner::Owner():FUN_009a4660(5) {
 f90=0.0f;f94=0.0f;f98=0.0f;
 unk9C=0;
 f60=f64=f68=f6C=0.0f;
 f70=f74=f78=f7C=f80=f84=f88=f8C=0.0f;
}
}
}   // namespace f3m_00a6ad30

// @f3 0x00a7def0 (community match, verified in this file)
extern int DAT_00e87e30;
extern int DAT_00dcc494;
namespace f3m_00a7def0 {
namespace f3m_00a7def0 {
struct RefObj {
    virtual ~RefObj();
    unsigned short memSize;
    short refs;
    void RemoveReference() {
        if (memSize) {
            --refs;
            if (refs == 0)
                delete this;
        }
    }
};
struct Member { int unk00, unk04, unk08, unk0c; void FUN_009b1160(); };
struct Obj {
    void* table;
    unsigned short memSize;
    short refs;
    int unk08;
    Member member;
    RefObj* child;
    void FUN_00a7def0();
};
void Obj::FUN_00a7def0()
{
    table = &DAT_00e87e30;
    if (child)
        child->RemoveReference();
    member.FUN_009b1160();
    table = &DAT_00dcc494;
}
}
}   // namespace f3m_00a7def0

// @f3 0x00a74870 (community match, verified in this file)
extern int DAT_00e84950;
extern int DAT_00dcc494;
namespace f3m_00a74870 {
namespace f3m_00a74870 {
struct RefObj {
    virtual ~RefObj();
    unsigned short memSize;
    short refs;
    void RemoveReference() {
        if (memSize) {
            --refs;
            if (refs == 0)
                delete this;
        }
    }
};
struct Obj {
    void* table;
    unsigned short memSize;
    short refs;
    int unk08, unk0c, unk10, unk14;
    RefObj* child;
    void FUN_00a74870();
};
// pdb: hkpPointToPathConstraintData::~hkpPointToPathConstraintData | hkpPointToPathConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void Obj::FUN_00a74870()
{
    table = &DAT_00e84950;
    if (child)
        child->RemoveReference();
    table = &DAT_00dcc494;
}
}
}   // namespace f3m_00a74870

// @f3 0x00a745b0 (community match, verified in this file)
namespace f3m_00a745b0 {
namespace f3m_00a745b0 {
struct RefObj {
    virtual ~RefObj();
    unsigned short memSize;
    short refs;
    void AddReference() { if (memSize) ++refs; }
    void RemoveReference() {
        if (memSize) {
            --refs;
            if (refs == 0)
                delete this;
        }
    }
};
struct Obj {
    void* table;
    unsigned short memSize;
    short refs;
    int unk08, unk0c, unk10, unk14;
    RefObj* child;
    void FUN_00a745b0(RefObj* o);
};
// pdb: hkpPointToPathConstraintData::~hkpPointToPathConstraintData | hkpPointToPathConstraintData.obj | fnv360_0822_debug, objopen_prop, low
void Obj::FUN_00a745b0(RefObj* o)
{
    if (o)
        o->AddReference();
    if (child)
        child->RemoveReference();
    child = o;
}
}
}   // namespace f3m_00a745b0

// @f3 0x00a6a700 (community match, verified in this file)
namespace f3m_00a6a700 {
struct FUN_00a8f450 {
    int unk00;
    FUN_00a8f450();
};
struct FUN_00a6a700 {
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    int count;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    FUN_00a8f450 member;
    FUN_00a6a700();
};
// pdb: hkpConstraintDrawer::hkpConstraintDrawer | hkpConstraintDrawer.obj | fnv360_0822_retail, caller, medium
FUN_00a6a700::FUN_00a6a700()
{
    c = 0.5f;
    count = 0x18;
    b = 3.0f;
    a = 5.0f;
    d = 1.5f;
    f = e = 2.0f;
}
}   // namespace f3m_00a6a700

// @f3 0x00a64630 (community match, verified in this file)
namespace f3m_00a64630 {
extern char DAT_0116c49c[];

class C00a64630 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* v7(void*, void*, void*);
};

class C00a64630Outer {
public:
    void* FUN_00a64630(void* a, void* b, void* c);
};

// pdb: hkDebugDisplayProcess::displayPoint | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: position, color, id, tag
void* C00a64630Outer::FUN_00a64630(void* a, void* b, void* c) {
    C00a64630* obj = *(C00a64630**)((char*)this - 8);
    return obj->v7(a, b, *(void**)DAT_0116c49c);
}
}   // namespace f3m_00a64630

// @f3 0x00a66f60 (community match, verified in this file)
namespace f3m_00a66f60 {
struct Float4_66f60 { float x, y, z, w; };
struct Obj66f60 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    Float4_66f60 firstVec;
    Float4_66f60 secondVec;
    void __thiscall FUN_00a66f60(Float4_66f60* first, Float4_66f60* second);
};
// pdb: hkDisplayAABB::setExtents | hkDisplayAABB.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: min, max
void __thiscall Obj66f60::FUN_00a66f60(Float4_66f60* first, Float4_66f60* second)
{
    firstVec.x = first->x;
    firstVec.y = first->y;
    firstVec.z = first->z;
    firstVec.w = first->w;
    secondVec.x = second->x;
    secondVec.y = second->y;
    secondVec.z = second->z;
    secondVec.w = second->w;
}
}   // namespace f3m_00a66f60

// @f3 0x00a74260 (community match, verified in this file)
namespace f3m_00a74260 {
extern void FUN_00e7bf10();
extern void FUN_00e83d8c();
extern void FUN_00e83d80();
extern void FUN_00e83d6c();
extern void FUN_00e83d60();
extern void FUN_00e83d54();
extern void FUN_00e83d44();

struct Obj74260 {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int pad18;
    int pad1c;
    int pad20;
    int pad24;
    int pad28;
    int pad2c;
    volatile int f30;
    int f34;
    void FUN_00943410();
    Obj74260* FUN_00a74260(int param);
};

Obj74260* Obj74260::FUN_00a74260(int param)
{
    FUN_00943410();
    f30 = (int)&FUN_00e7bf10;
    f00 = (int)&FUN_00e83d8c;
    f08 = (int)&FUN_00e83d80;
    f0c = (int)&FUN_00e83d6c;
    f10 = (int)&FUN_00e83d60;
    f14 = (int)&FUN_00e83d54;
    f30 = (int)&FUN_00e83d44;
    f34 = param;
    if (param && *(short*)(param + 4))
        *(short*)(param + 6) += 1;
    return this;
}
}   // namespace f3m_00a74260

// @f3 0x00a61b20 (community match, verified in this file)
namespace f3m_00a61b20 {
struct OtherA61 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    int unk018;
    int unk01C;
    void FUN_00908a00();
};

struct RendererA61 {
    void FUN_009ee8f0(int value);
    void FUN_009ee560(int value);
    void FUN_009ee8b0(int value);
    void FUN_009ee740(int value, int value2);
    void FUN_009ee8d0(int value);
    void FUN_00a623b0(int value);
    void FUN_009ee930(int value, int value2);
    unsigned char* FUN_009ee770(int* value);
};

struct OwnerA61 {
    unsigned int unk000;
    RendererA61* m_renderer;
    OtherA61* m_other;

    bool __thiscall FUN_00a61b20(int value1, int value2, int value3);
};

bool __thiscall OwnerA61::FUN_00a61b20(int value1, int value2, int value3)
{
    m_other->FUN_00908a00();

    if (m_renderer != 0) {
        m_renderer->FUN_009ee8f0(0x29);
        m_renderer->FUN_009ee560(2);
        m_renderer->FUN_00a623b0(value1);
        m_renderer->FUN_009ee930(value2, 0);
        m_renderer->FUN_009ee8d0(value3);
    }

    bool result;
    if (m_renderer != 0) {
        unsigned char* state = m_renderer->FUN_009ee770(&value1);
        if (*state != 0) {
            result = true;
            goto finished;
        }
    }

    result = false;

finished:
    OtherA61* other = m_other;
    other->unk018 = -1;
    other->unk01C = -1;
    f3m_00a62030::LeaveCriticalSection(other);

    return !result;
}
}   // namespace f3m_00a61b20

// @f3 0x00a70c70 (community match, verified in this file)
extern char DAT_00e87b30;
namespace f3m_00a70c70 {
extern "C" void _ReadWriteBarrier();

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Allocator00a70c70 { void FUN_008f6d90(void* data, unsigned int bytes, unsigned int category); };
struct State00a70c70 {
    void* table;
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    void* data;
    unsigned int count;
    int capacityFlags;
    void FUN_00a70c70();
};
// pdb: hkpStiffSpringChainData::~hkpStiffSpringChainData | hkpStiffSpringChainData.obj | fnv360_0822_retail, call_seq, high
void State00a70c70::FUN_00a70c70() {
    table = &DAT_00e87b30;
    _ReadWriteBarrier();
    if ((capacityFlags & 0x80000000u) == 0) {
        unsigned int capacity = capacityFlags & 0x3fffffff;
        Allocator00a70c70* allocator = static_cast<Allocator00a70c70*>(TlsGetValue(DAT_010f3170));
        allocator->FUN_008f6d90(data, capacity * 48, 0x17);
    }
    table = &DAT_00dcc494;
}

}   // namespace f3m_00a70c70

// @f3 0x00a60ec0 (community match, verified in this file)
extern char DAT_00e86c40;
namespace f3m_00a60ec0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Allocator00a60ec0 { void* FUN_008f6d30(unsigned int, unsigned int); };
struct Created00a60ec0 { unsigned int unk00; unsigned short size, refs; Created00a60ec0* FUN_00a84f70(void*, void*, int); };
struct State00a60ec0 {
    void* table;
    unsigned short unk04, refs;
    Created00a60ec0* created;
    unsigned char flag;
    State00a60ec0* FUN_00a60ec0(void* first, void* second, unsigned char value);
};
// pdb: hkIArchive::~hkIArchive | hkIArchive.obj | fnv360_0822_retail, objrun, medium
State00a60ec0* State00a60ec0::FUN_00a60ec0(void* first, void* second, unsigned char value) {
    refs = 1;
    table = &DAT_00e86c40;
    flag = value;
    Allocator00a60ec0* allocator = static_cast<Allocator00a60ec0*>(TlsGetValue(DAT_010f3170));
    Created00a60ec0* object = static_cast<Created00a60ec0*>(allocator->FUN_008f6d30(0x1c, 0x1a));
    object->size = 0x1c;
    created = object->FUN_00a84f70(first, second, 2);
    return this;
}

}   // namespace f3m_00a60ec0

// @f3 0x00a67de0 (community match, verified in this file)
namespace f3m_00a67de0 {
namespace f3m_00a67de0 {
struct Bounds7de0 {
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
    float fMin[4];
    void FUN_008fda60(int a_iId);
};

struct Shape7de0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Bounds7de0 kBounds;

    void FUN_00a67de0(const float* a_pValues, int a_iId);
};

// pdb: hkDisplayBox::setParameters | hkDisplayBox.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: halfExtents, t
void Shape7de0::FUN_00a67de0(const float* a_pValues, int a_iId) {
    kBounds.fMin[0] = a_pValues[0];
    kBounds.fMin[1] = a_pValues[1];
    kBounds.fMin[2] = a_pValues[2];
    kBounds.fMin[3] = a_pValues[3];
    kBounds.FUN_008fda60(a_iId);
}
}
}   // namespace f3m_00a67de0

// @f3 0x00a76290 (community match, verified in this file)
namespace f3m_00a76290 {
void __stdcall FUN_00a76290(void* p, int x)
{
    *(char*)p = 0;
}
}   // namespace f3m_00a76290

// @f3 0x00a70c30 (community match, verified in this file)
extern void* FUN_00e87b30;
namespace f3m_00a70c30 {

struct SubRecord_a70c30 {
    int u00;
    int u04;
    void* p08;

    void hkpBridgeConstraintAtom_init(void* pValue);
};

struct FUN_00a70c30 {
    void** m_ppVftable;
    unsigned short m_reserved04;
    unsigned short m_usReadyFlag;
    unsigned char m_reserved08[4];
    SubRecord_a70c30 m_sub;
    int m_i18;
    int m_i1C;
    unsigned int m_ui20;

    FUN_00a70c30(int completionFlag);
};

// pdb: hkpStiffSpringChainData::hkpStiffSpringChainData | hkpStiffSpringChainData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: f
FUN_00a70c30::FUN_00a70c30(int completionFlag)
{
    SubRecord_a70c30* pSub = &m_sub;

    m_usReadyFlag = 1;
    m_ppVftable = &FUN_00e87b30;
    pSub->hkpBridgeConstraintAtom_init(pSub->p08);

    int iZero = 0;
    m_i18 = iZero;
    m_i1C = iZero;
    m_ui20 = 0x80000000;

    pSub->hkpBridgeConstraintAtom_init(this);
}
}   // namespace f3m_00a70c30

// @f3 0x00a742c0 (community match, verified in this file)
namespace f3m_00a742c0 {
struct FUN_00a742c0_Ref {
    virtual int vf00(int value);
    unsigned short unk04;
    short unk06;
};

extern void FUN_00e7bf10();
extern void FUN_00e83d8c();
extern void FUN_00e83d80();
extern void FUN_00e83d6c();
extern void FUN_00e83d60();
extern void FUN_00e83d54();
extern void FUN_00e83d44();

struct ObjA742c0 {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int pad18;
    int pad1c;
    int pad20;
    int pad24;
    int pad28;
    int pad2c;
    int f30;
    FUN_00a742c0_Ref* f34;

    void FUN_008d34a0();
    void FUN_00a742c0();
};

// pdb: hkpConstrainedSystemFilter::~hkpConstrainedSystemFilter | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, call_seq, high
void ObjA742c0::FUN_00a742c0()
{
    FUN_00a742c0_Ref* ref = f34;

    f00 = (int)&FUN_00e83d8c;
    f08 = (int)&FUN_00e83d80;
    f0c = (int)&FUN_00e83d6c;
    f10 = (int)&FUN_00e83d60;
    f14 = (int)&FUN_00e83d54;
    f30 = (int)&FUN_00e83d44;

    if (ref != 0 && ref->unk04 != 0) {
        --ref->unk06;
        unsigned short count = ref->unk06;
        if (count == 0)
            ref->vf00(1);
    }

    f30 = (int)&FUN_00e7bf10;
    ((f3m_00a76aa0::Obj76aa0*)this)->FUN_008d34a0();
}
}   // namespace f3m_00a742c0

// @f3 0x00a66ed0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern int DAT_00dcc494;
namespace f3m_00a66ed0 {
namespace f3m_00a66ed0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct Obj {
    void* vptr;
    unsigned short memSize;
    unsigned short refs;
    void* data;
    int size;
    int capFlags;
    Obj* FUN_00a66ed0(unsigned int flags);
};
// pdb: hkpUserConvexRadiusBuilder::`scalar deleting destructor' | hkpConvexRadiusBuilder.obj | fnv360_0822_retail, vtable, medium
Obj* Obj::FUN_00a66ed0(unsigned int flags) {
    if ((capFlags & 0x80000000) == 0) {
        int cap = capFlags & 0x3fffffff;
        Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
        h->FUN_008f6d90(data, cap * 8, 0x17);
    }
    vptr = &DAT_00dcc494;
    if (flags & 1) {
        Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
        h->FUN_008f6d90(this, memSize, 0x15);
    }
    return this;
}
}
}   // namespace f3m_00a66ed0

// @f3 0x00a72c30 (community match, verified in this file)
extern char DAT_00e87bc8;
extern char DAT_00e87bc0;
namespace f3m_00a72c30 {
namespace f3m_00a72c30 {
struct Serializer {
    virtual void v00();
    virtual void v04(const char* name, int one, void* obj);
    virtual void v08(const char* name, int one, void* data, int sizeBytes, int capBytes);
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
};
struct Obj {
    int unk00, unk04, unk08, unk0c;
    void* data10;
    int size14;
    int capFlags18;
    void FUN_00a72c30(Serializer* s);
};
void Obj::FUN_00a72c30(Serializer* s) {
    s->v04(&DAT_00e87bc8, 1, this);
    if ((capFlags18 & 0x80000000) == 0) {
        struct BF { unsigned int cap : 30; unsigned int flg : 2; };
        int cap = ((BF*)&capFlags18)->cap;
        s->v08(&DAT_00e87bc0, 1, data10, size14 << 5, cap * 32);
    }
    s->v18();
}
}
}   // namespace f3m_00a72c30

// @f3 0x00a760c0 (community match, verified in this file)
extern int g_target_00da0a40;
namespace f3m_00a760c0 {

namespace f3m_00a760c0 {
struct Base {
    void* m_vft;
    unsigned short m_memSize;
    unsigned short m_refCount;
    __forceinline Base() : m_refCount(1) {}
};

struct Vec4 {
    float x, y, z, w;
    __forceinline void set(float a, float b, float c, float d = 0.0f) {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Arr {
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline Arr() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
};

struct VftInit : Base {
    __forceinline VftInit() { m_vft = &g_target_00da0a40; }
};

struct FUN_00a760c0 : VftInit {
    float m_f08;
    unsigned char m_b0c;
    unsigned char m_pad0d[3];
    Vec4 m_v10;
    Arr m_arr20;
    Arr m_arr2c;
    FUN_00a760c0();
};

// pdb: hkpLinearParametricCurve::hkpLinearParametricCurve | hkpLinearParametricCurve.obj | fnv360_0822_retail, objrun_open, low
FUN_00a760c0::FUN_00a760c0() : m_f08(0.01f), m_b0c(0) {
    m_v10.set(0.0f, 1.0f, 0.0f, 0.0f);
}
}
}   // namespace f3m_00a760c0

// @f3 0x00a712e0 (community match, verified in this file)
extern int DAT_01268d94;
namespace f3m_00a712e0 {

namespace f3m_00a712e0 {
struct Base {
    void* m_vft;
    unsigned short m_memSize;
    unsigned short m_refCount;
    int m_u08;
    int m_u0c;
    __forceinline Base() : m_refCount(1), m_u08(0) {}
};

struct VftInit : Base {
    __forceinline VftInit() { m_vft = &DAT_01268d94; }
};

struct Vec4 {
    float x, y, z, w;
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
};

struct FUN_00a712e0 : VftInit {
    unsigned short m_w10;
    unsigned short m_pad12[7];
    Vec4 m_v20;
    Vec4 m_v30;
    unsigned short m_w40;
    unsigned short m_pad42[7];
    Vec4 m_v50;
    Vec4 m_v60;
    float m_f70;
    float m_f74;
    FUN_00a712e0();
};

FUN_00a712e0::FUN_00a712e0() : m_w10(3), m_w40(0x14) {
    m_v20.setZero4();
    m_v30.setZero4();
    m_v50.setZero4();
    m_v60.setZero4();
    m_f70 = 0.0f;
    m_f74 = 1.0f;
}
}
}   // namespace f3m_00a712e0

// @f3 0x00a70640 (community match, verified in this file)
namespace f3m_00a70640 {
namespace f3m_00a70640 {
struct ShapeListener;
struct ActorRef {
    void FUN_0090b960(ShapeListener* listener);
};
struct PairEntry {
    ActorRef* first;
    ActorRef* second;
};
struct PairArray {
    PairEntry* arr;
    int count;
    int cap;
    __forceinline void RemoveAt(int i) {
        --count;
        arr[i] = arr[count];
    }
};
struct ShapeListener {
    int vft;
    PairArray pairs;
    void FUN_00a70640(ActorRef* actor);
};
void ShapeListener::FUN_00a70640(ActorRef* actor) {
    int i = 0;
    while (i < pairs.count) {
        if (pairs.arr[i].first == actor || pairs.arr[i].second == actor) {
            pairs.RemoveAt(i);
        } else {
            ++i;
        }
    }
    void* base = (void*)((char*)this - 0x30);
    actor->FUN_0090b960(base != 0 ? this : 0);
}
}
}   // namespace f3m_00a70640

// @f3 0x00a711c0 (community match, verified in this file)
namespace f3m_00a711c0 {
struct __declspec(align(16)) Rotation {
    volatile float xx,xy,xz,xw;
    volatile float yx,yy,yz,yw;
    volatile float zx,zy,zz,zw;
    __forceinline Rotation() {}
    __forceinline void SetIdentity() {
        xx=0.0f; xy=0.0f; xz=0.0f; xw=0.0f;
        yx=0.0f; yy=0.0f; yz=0.0f; yw=0.0f;
        zx=0.0f; zy=0.0f; zz=0.0f; zw=0.0f;
        xx=1.0f; yy=1.0f; zz=1.0f;
    }
};
struct LocalRotations {
    unsigned short type;
    Rotation a,b;
    __forceinline LocalRotations():type(4) {}
};
struct Angular3D {
    unsigned short type;
    unsigned char firstAxis,numAxes;
    __forceinline Angular3D():type(13) {}
};
struct Atoms { LocalRotations local; Angular3D angular; __forceinline Atoms():local(),angular() { local.a.SetIdentity(); local.b.SetIdentity(); angular.firstAxis=0; angular.numAxes=3; } };
class hkpConstraintData {
public:
    virtual ~hkpConstraintData() {}
    unsigned short memorySizeAndFlags;
    unsigned short references;
    unsigned int userData;
    __forceinline hkpConstraintData():references(1),userData(0) {}
};
class hkpRotationalConstraintData:public hkpConstraintData {
public:
    Atoms atoms;
    hkpRotationalConstraintData();
};
// pdb: hkpRotationalConstraintData::setInBodySpace | hkpRotationalConstraintData.obj | tesv_win, objopen_prop, low
hkpRotationalConstraintData::hkpRotationalConstraintData() {}
}   // namespace f3m_00a711c0

// @f3 0x00a715a0 (community match, verified in this file)
namespace append15a0 {
struct Vector4 {
    float x,y,z,w;
    __forceinline Vector4() {}
    __forceinline Vector4(const Vector4& v):x(v.x),y(v.y),z(v.z),w(v.w) {}
    __forceinline Vector4& operator=(const Vector4& v) { x=v.x; y=v.y; z=v.z; w=v.w; return *this; }
};
extern const Vector4 DAT_00f7b120;
struct RefObject {
    void* vtable;
    unsigned short memorySizeAndFlags,references;
    __forceinline void AddReference() { if (memorySizeAndFlags) ++references; }
};
struct Ref {
    RefObject* object;
    __forceinline void Set(RefObject* value) { object=value; value->AddReference(); }
};
struct __declspec(align(16)) Entry {
    Vector4 a,b,c,rotation;
    Ref first,second,third;
    unsigned char state;
    __forceinline void Set(const Vector4& va,const Vector4& vb,const Vector4& vc,RefObject* x,RefObject* y,RefObject* z) {
        a=va; b=vb; c=vc; first.Set(x); second.Set(y); third.Set(z); state=0; rotation=DAT_00f7b120;
    }
};
struct Array { Entry* data; int size; int capacityAndFlags; __forceinline Entry& ExpandOne(); };
void __cdecl FUN_00901f10(Array*,int);
__forceinline Entry& Array::ExpandOne() {
    if (size==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(Entry));
    return data[size++];
}
struct Owner {
    int unk00,unk04,unk08,unk0c,unk10,unk14;
    Array entries;
    void hkpPoweredChainData_addConstraintInfoInBodySpace(const Vector4& a,const Vector4& b,const Vector4& c,RefObject* x,RefObject* y,RefObject* z);
};
// pdb: hkpPoweredChainData::addConstraintInfoInBodySpace | hkpPoweredChainData.obj | fnv360_0822_retail, caller + skyrim(call_seq), high
void Owner::hkpPoweredChainData_addConstraintInfoInBodySpace(const Vector4& a,const Vector4& b,const Vector4& c,RefObject* x,RefObject* y,RefObject* z) {
    entries.ExpandOne().Set(a,b,c,x,y,z);
}
}

// @f3 0x00a691f0 (community match, verified in this file)
#include <new>
namespace f3m_00a691f0 {
struct Block { Block* next; };
struct Bucket { Block* head; int count; };
struct hkThreadMemory {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Bucket buckets[25];
    void* FUN_008f6800(int index, int tag) throw();
    void* FUN_008f6d30(int size, int cls) throw();
};
}
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
namespace f3m_00a691f0 {
extern unsigned long DAT_010f3170;
inline void* PoolAlloc(int index, int tag)
{
    hkThreadMemory* m = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
    Block* b = m->buckets[index].head;
    if (b) {
        m->buckets[index].count += -1;
        m->buckets[index].head = b->next;
        return b;
    }
    return m->FUN_008f6800(index, tag);
}
template <class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    hkArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
void __cdecl FUN_00901f10(void* arr, int elemSize);
template <class T> inline void PushBack(hkArray<T>& a, const T& e)
{
    if (a.size == (a.capacityAndFlags & 0x3fffffff))
        FUN_00901f10(&a, sizeof(T));
    a.data[a.size] = e;
    a.size += 1;
}
struct Data {
    hkArray<int> first;
    hkArray<int> second;
};
struct Obj {
    void* vtable;
    unsigned short memSize;
    short refs;
    Obj(Data* d) throw();
};
struct Owner {
    int unk00, unk04, unk08;
    Obj* obj;
    Obj* FUN_00a691f0(hkArray<Obj*>& out);
};
Obj* Owner::FUN_00a691f0(hkArray<Obj*>& out)
{
    if (!obj) {
        void* p = PoolAlloc(3, 0x27);
        Data* d = p ? new (p) Data : 0;
        hkThreadMemory* m2 = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
        Obj* o = (Obj*)m2->FUN_008f6d30(0x60, 8);
        o->memSize = 0x60;
        obj = new (o) Obj(d);
        PushBack(out, obj);
    }
    return obj;
}
}

// @f3 0x00a67d60 (community match, verified in this file)
namespace f3m_00a67d60 {
extern char off_00e80ec4;                 // value stored at +0x00

struct Vec4 { union { int i[4]; float f[4]; }; };    // same 16 bytes seen as ints, then as floats

struct Dst67 {                            // +00 slot, +60..+6c the copied vector
    void** slot0;                         // 0x00
    int pad[23];                          // 0x04 - 0x5c
    Vec4 data;                            // 0x60

    void FUN_009a4660(int mode);          // thiscall member: callee cleans the argument
    Dst67* FUN_00a67d60(Vec4* src);       // thiscall, one stack param (ret 4), returns the object
};

Dst67* Dst67::FUN_00a67d60(Vec4* src) {
    FUN_009a4660(2);
    slot0 = (void**)&off_00e80ec4;

    data.i[0] = src->i[0];
    data.i[1] = src->i[1];
    data.i[2] = src->i[2];
    data.i[3] = src->i[3];

    data.f[0] = src->f[0];
    data.f[1] = src->f[1];
    data.f[2] = src->f[2];
    data.f[3] = src->f[3];

    return this;
}
}   // namespace f3m_00a67d60

// @f3 0x00a65700 (community match, verified in this file)
namespace f3m_00a65700 {
extern char off_00e86f34;                                  // the handler/vtable object ORIG stores at +0x00
extern void* (__stdcall * const DAT_00d9b080)(unsigned long);

struct Obj657 {                       // +00 handler, +04/+06 words, +08/+0C zeroed, +10 flag
    void** handler;
    unsigned short size16;
    unsigned short flag16;
    int f8;
    int fC;
    int f10;

    Obj657* FUN_008f6d30(unsigned int a, unsigned int b);  // thiscall member returning the object
};

// pdb: hkpUserShapeDisplayBuildercreate | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, uvref, medium
Obj657* __cdecl FUN_00a65700(void) {
    Obj657* p = (Obj657*)DAT_00d9b080(DAT_010f3170);
    Obj657* q = p->FUN_008f6d30(0x14, 0x15);

    unsigned short* w4 = &q->size16;   *w4 = 0x14;
    unsigned short* w6 = &q->flag16;   *w6 = 1;
    q->handler = (void**)&off_00e86f34;

    Obj657** qq = &q;
    int* z = &(*qq)->f8;   *z = 0;   z[1] = 0;
    q->f10 = (int)0x80000000;

    return q;
}




}   // namespace f3m_00a65700

// @f3 0x00a66ff0 (community match, verified in this file)
extern char off_00e80c2c;
namespace f3m_00a66ff0 {

struct Dst66 {                            // +00 slot, floats at +0x60 .. +0x7c
    void** slot0;                         // 0x00
    int pad[23];                          // 0x04 - 0x5c
    float f60, f64, f68, f6c;             // 0x60 - 0x6c
    float f70, f74, f78, f7c;             // 0x70 - 0x7c

    void FUN_009a4660(int mode);          // thiscall member: callee cleans the argument
    Dst66* FUN_00a66ff0();                // thiscall, returns the object (ret)
};

// pdb: hkDisplayAABB::hkDisplayAABB | hkDisplayAABB.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
Dst66* Dst66::FUN_00a66ff0() {
    FUN_009a4660(3);

    float z = 0.0f;
    Dst66* s = this;
    Dst66** sp = &s;                     // escaped object pointer: orders the slot store against the float stores
    (*sp)->slot0 = (void**)&off_00e80c2c;

    f6c = z; f68 = z; f64 = z; f60 = z;
    f7c = z; f78 = z; f74 = z; f70 = z;

    return this;
}

}   // namespace f3m_00a66ff0

// @f3 0x00a67db0 (community match, verified in this file)
extern char off_00e80ec4;
namespace f3m_00a67db0 {

struct DstDB0 {                           // +00 slot, floats at +0x60 .. +0x6c
    void** slot0;                         // 0x00
    int pad[23];                          // 0x04 - 0x5c
    float f60, f64, f68, f6c;             // 0x60 - 0x6c

    void FUN_009a4660(int mode);          // thiscall member: callee cleans the argument
    DstDB0* FUN_00a67db0();              // thiscall, returns the object (ret)
};

DstDB0* DstDB0::FUN_00a67db0() {
    FUN_009a4660(2);

    float z = 0.0f;
    DstDB0* s = this;
    DstDB0** sp = &s;                     // escaped object pointer: pins the slot store above the float stores
    (*sp)->slot0 = (void**)&off_00e80ec4;

    f6c = z; f68 = z; f64 = z; f60 = z;

    return this;
}
}   // namespace f3m_00a67db0

// @f3 0x00a64860 (community match, verified in this file)
extern char DAT_00e86eb8, DAT_00e86e98, DAT_00e86e88, DAT_00e86e78, DAT_00e808e0;
extern int DAT_00dcc494;
namespace f3m_00a64860 {
extern "C" void _ReadWriteBarrier();
struct Ref00a64860 { virtual void Destroy(unsigned int); unsigned short size; short refs; void FUN_00954670(void*); void RemoveReference(){if(size && --refs==0)Destroy(1);} };
struct State00a64860 {
    void* table0; unsigned int unk04; void* table8;
    unsigned int unk0c,unk10,unk14,unk18,unk1c;
    void* table20;
    Ref00a64860* reference;
    void FUN_00a64860();
};
// pdb: hkpWorldViewerBase::~hkpWorldViewerBase | hkpWorldViewerBase.obj | fnv360_0822_retail, call_seq, medium
void State00a64860::FUN_00a64860() {
    table0 = &DAT_00e86eb8;
    table8 = &DAT_00e86e98;
    table20 = &DAT_00e86e88;
    if (reference) {
        reference->FUN_00954670(&table20);
        reference->RemoveReference();
        reference = 0;
    }
    table20 = &DAT_00e86e78;
    table8 = &DAT_00e808e0;
    _ReadWriteBarrier();
    table0 = &DAT_00dcc494;
}
}   // namespace f3m_00a64860

// @f3 0x00a7dfc0 (community match, verified in this file)
extern char off_00e7e550;
extern char off_00e87e30;
namespace f3m_00a7dfc0 {

struct Sub7D {
    void FUN_009b1110(int value);         // thiscall member of the sub-object at +0xc, one stack arg (callee cleans)
};

struct A7D {
    unsigned char raw[0x20];              // +0 slot, +6 word, +8 dword, +0xc sub-object, +0x1c pointer

    A7D* FUN_00a7dfc0(unsigned char* p);  // thiscall, one stack param (ret 4)
};

A7D* A7D::FUN_00a7dfc0(unsigned char* p) {
    union Loc { unsigned char b; int i; } loc;   // ORIG: mov byte ptr [esp+4],0 then mov eax,[esp+4]
    loc.b = 0;

    *(unsigned short*)(raw + 6) = 1;
    *(int*)raw = (int)&off_00e7e550;
    *(int*)(raw + 8) = 0;
    ((Sub7D*)(raw + 0xc))->FUN_009b1110(loc.i);

    int pv = (int)p;                      // ORIG reads the parameter before the second slot store
    *(int*)raw = (int)&off_00e87e30;
    *(int*)(raw + 0x1c) = pv;

    if (p != 0 && *(unsigned short*)(p + 4) != 0) {
        *(unsigned short*)(p + 6) = *(unsigned short*)(p + 6) + 1;   // add word ptr [eax + 6], 1
    }

    return this;                          // ORIG: mov eax,esi ; pop esi ; pop ecx ; ret 4
}
}   // namespace f3m_00a7dfc0

// @f3 0x00a72b10 (community match, verified in this file)
extern const char DAT_00e87bb4[],DAT_00e87ba8[],DAT_00dbf198[],DAT_00e87b9c[];
namespace f3m_00a72b10 {

struct Archive
{
    virtual void vf00();
    virtual void vf04(const char* name, int version, void* obj);
    virtual void vf08(const char* name, int version, void* data, unsigned count, unsigned capacity);
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
};

__forceinline void SaveArray(Archive* ar,const char* name,void* data,unsigned count,unsigned capacity,unsigned stride){ar->vf08(name,1,data,count*stride,capacity*stride);}

class StorageMesh
{
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void* unk18;
    int unk1c;
    unsigned int unk20;
    void* unk24;
    int unk28;
    unsigned int unk2c;
    void* unk30;
    int unk34;
    unsigned int unk38;

    void hkpSimpleMeshShape_calcContentStatistics(Archive* ar);
};

// pdb: hkpSimpleMeshShape::calcContentStatistics | hkpSimpleMeshShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void StorageMesh::hkpSimpleMeshShape_calcContentStatistics(Archive* ar)
{
    ar->vf04(DAT_00e87bb4, 1, this);
    if (!(unk20 & 0x80000000))
        SaveArray(ar,DAT_00e87ba8,unk18,unk1c,unk20 & 0x3fffffff,16);
    if (!(unk2c & 0x80000000))
        SaveArray(ar,DAT_00dbf198,unk24,unk28,unk2c & 0x3fffffff,16);
    if (!(unk38 & 0x80000000))
        ar->vf08(DAT_00e87b9c, 1, unk30, unk34, unk38 & 0x3fffffff);
    ar->vf18();
}
}   // namespace f3m_00a72b10

// @f3 0x00a633f0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern int DAT_010ccfa0;
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_00a633f0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier();

class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};

void __cdecl FUN_00a63350();

struct Item_a633f0 {
    int key;
    int value;
};

struct Object_a633f0 {
    virtual void vf00(int value);

    unsigned short unk04;
    short unk06;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    Item_a633f0* items24;
    int count28;

    void FUN_009533c0(void* callback);
    void removeRef() {
        if (unk04 != 0) {
            if (--unk06 == 0) {
                vf00(1);
            }
        }
    }
};

struct Pool_a633f0 {
    void FUN_008f6d90(void* array, int size, int category);
};

struct Class_a633f0 : public hkBaseObject {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* array20;
    int unk24;
    int count28;
    Object_a633f0* object2C;

    void FUN_00a632e0(int id);
    void FUN_00a633f0();
};

// pdb: hkInspectProcess::~hkInspectProcess | hkInspectProcess.obj | fnv360_0822_retail, call_seq, medium
void Class_a633f0::FUN_00a633f0() {
    Object_a633f0* object = object2C;
    *(int*)this = 0xe86dac;
    unk08 = 0xe86d8c;

    if (object != 0) {
        for (int index = 0; index < object->count28; ++index) {
            FUN_00a632e0(object->items24[index].key);
        }

        object2C->FUN_009533c0((void*)&FUN_00a63350);
        object2C->removeRef();
    }

    if ((count28 & 0x80000000u) == 0) {
        int size = count28 & 0x3FFFFFFF;
        Pool_a633f0* pool = (Pool_a633f0*)TlsGetValue(DAT_010f3170);
        pool->FUN_008f6d90(array20, size * 8, 0x17);
    }

    unk08 = (int)&DAT_010ccfa0;
    _ReadWriteBarrier();
    hkBaseObject::~hkBaseObject();
}
}   // namespace f3m_00a633f0

// @f3 0x00a610a0 (community match, verified in this file)
#include <windows.h>

extern unsigned int DAT_010f3170;
extern const char DAT_00e86c50[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION) throw();
extern "C" __declspec(dllimport) int __stdcall InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION, unsigned long) throw();
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

namespace f3m_00a610a0 {

struct MemCtx {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    void* head;
    int count;
    void* FUN_008f6800(int a, int b);
};

struct Node {
    CRITICAL_SECTION cs;
    __int64 time;
    int period;
    Node* next;
    Node* prev;
    void FUN_00908a00();
    static void* operator new(unsigned int) throw()
    {
        MemCtx* ctx = (MemCtx*)TlsGetValue(DAT_010f3170);
        void* n = ctx->head;
        if (n) {
            ctx->count--;
            ctx->head = *(void**)n;
        } else {
            n = ctx->FUN_008f6800(4, 0x15);
        }
        return n;
    }
};

extern Node DAT_011692e8;

struct Outer {
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    int unk08;
    void* data;
    int count;
    unsigned int capFlags;
    Node* child;
    Outer* FUN_00a610a0();
};

// pdb: hkProcessFactory::hkProcessFactory | hkProcessFactory.obj | fnv360_0822_retail, objopen_prop, low
Outer* Outer::FUN_00a610a0()
{
    referenceCount = 1;
    vtable = (void*)DAT_00e86c50;
    _ReadWriteBarrier();
    unk08 = 0;
    data = 0;
    count = 0;
    capFlags = 0x80000000;
    Node* t = new Node;
    if (t != 0) {
        t->period = 2000;
        t->next = 0;
        t->prev = 0;
        DAT_011692e8.FUN_00908a00();
        t->prev = DAT_011692e8.prev;
        Node* tail = t->prev;
        if (tail != 0)
            tail->next = t;
        t->next = &DAT_011692e8;
        DAT_011692e8.prev = t;
        DAT_011692e8.time = -1;
        LeaveCriticalSection(&DAT_011692e8.cs);
        InitializeCriticalSectionAndSpinCount(&t->cs, 0x7d0);
        t->time = -1;
        child = t;
    } else {
        child = 0;
    }
    return this;
}

}

// @f3 0x00a72a30 (community match, verified in this file)
#include <new>
namespace f3m_00a72a30 {
extern void FUN_00e35ff4();
namespace Triangle85 {
struct Vector {float x,y,z,w; Vector(){} Vector(float value){w=value;z=value;y=value;x=value;}};
struct Header {
 void (*table)(); unsigned short reserved,refs; unsigned user,kind; float radius;unsigned short material;unsigned char flags,extra;
 Header(volatile float r,unsigned short m,unsigned f):radius(r),material(m){refs=1;user=0;kind=4;table=FUN_00e35ff4;flags=f;}
};
struct Shape:Header {
 unsigned unk18,unk1c;Vector a,b,c,tail;
 Shape(float r,unsigned short m,unsigned f):Header(r,m,f),tail(0.0f){extra=0;}
};
}

class C00a72a30
{
public:
    void FUN_00a72a30(int index, void* output);
};

// pdb: hkpSimpleMeshShape::getChildShape | hkpSimpleMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: key, buffer
void C00a72a30::FUN_00a72a30(int index, void* output)
{
    int i = index;
    void* obj = output;

    obj = new(output) Triangle85::Shape(*(float*)((char*)this+0x2c),*(unsigned short*)((char*)*(int**)((char*)this+0x14)+(i<<4)+0xc),*(unsigned char*)((char*)this+0x30));

    int* p14 = *(int* volatile*)((char*)this + 0x14);
    int* p8 = *(int**)((char*)this + 8);
    int* src = (int*)((char*)p14 + (i << 4));
    int* data = (int*)((char*)p8 + (*src << 4));

    *(float*)((char*)obj + 0x20) = *(float*)data;
    *(float*)((char*)obj + 0x24) = *(float*)(data + 1);
    *(float*)((char*)obj + 0x28) = *(float*)(data + 2);
    *(float*)((char*)obj + 0x2c) = *(float*)(data + 3);

    p14 = *(int* volatile*)((char*)this + 0x14);
    p8 = *(int**)((char*)this + 8);
    src = (int*)((char*)p14 + (i << 4) + 4);
    data = (int*)((char*)p8 + (*src << 4));

    *(float*)((char*)obj + 0x30) = *(float*)data;
    *(float*)((char*)obj + 0x34) = *(float*)(data + 1);
    *(float*)((char*)obj + 0x38) = *(float*)(data + 2);
    *(float*)((char*)obj + 0x3c) = *(float*)(data + 3);

    p14 = *(int* volatile*)((char*)this + 0x14);
    p8 = *(int**)((char*)this + 8);
    src = (int*)((char*)p14 + (i << 4) + 8);
    data = (int*)((char*)p8 + (*src << 4));

    *(float*)((char*)obj + 0x40) = *(float*)data;
    *(float*)((char*)obj + 0x44) = *(float*)(data + 1);
    *(float*)((char*)obj + 0x48) = *(float*)(data + 2);
    *(float*)((char*)obj + 0x4c) = *(float*)(data + 3);
}
}   // namespace f3m_00a72a30

// @f3 0x00a72650 (community match, verified in this file)
extern int DAT_01268df4;
namespace f3m_00a72650 {
struct hkVector4
{
    float x, y, z, w;
    void setZero4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
    float& operator()(int i)
    {
        return (&x)[i];
    }
};

struct hkTransform
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;

    void setIdentity()
    {
        m_col0.setZero4();
        m_col1.setZero4();
        m_col2.setZero4();
        m_col0(0) = 1.0f;
        m_col1(1) = 1.0f;
        m_col2(2) = 1.0f;
        m_translation.x = m_translation.y = m_translation.z = m_translation.w = 0.0f;
    }
};

struct C00a72650
{
    void* unk00;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    short unk10;
    short unk12;
    int unk14;
    int unk18;
    int unk1c;
    hkTransform m_transformA;
    hkTransform m_transformB;
    short unkA0;
    unsigned char unkA2;

    C00a72650* FUN_00a72650();
};


C00a72650* C00a72650::FUN_00a72650()
{
    unk06 = 1;
    unk00 = &DAT_01268df4;
    *(volatile int*)&unk08 = 0;
    *(volatile short*)&unk10 = 2;
    *(volatile short*)&unkA0 = 7;
    m_transformA.setIdentity();
    m_transformB.setIdentity();
    unkA2 = 0;
    return this;
}
}   // namespace f3m_00a72650

// @f3 0x00a60990 (community match, verified in this file)
namespace f3m_00a60990 {
namespace f3m_00a60990 {

struct QBool60
{
    char m_bool;
    QBool60() {}
    QBool60(bool b) { m_bool = (char)b; }
    QBool60& operator=(bool b) { m_bool = (char)b; return *this; }
    operator bool() const { return m_bool != 0; }
};

struct QEdge60
{
    unsigned short m_vertex;
    unsigned short m_twin;
    unsigned short m_next;
    unsigned short m_mark;
};

struct QMesh60
{
    int unk00;
    QEdge60* m_edges;
    int m_numEdges;

    void FUN_00a60890(QEdge60* edges);
    QBool60 FUN_00a60990();
};

// pdb: hkGeomHull::isValidTopology | hkGeomHull.obj | tesv_win, objrun_open, low
QBool60 QMesh60::FUN_00a60990()
{
    QBool60 result = true;
    int n = m_numEdges;
    QEdge60* e = m_edges;
    int i;
    for (i = 0; i < n; i++) {
        int t = e[i].m_twin;
        bool valid = t >= 0 && t < n;
        result = result && valid && e[t].m_twin == i;
    }
    for (i = 0; i < n; i++) {
        const QEdge60* ed = m_edges + i;
        result = result && e[e[ed->m_twin].m_next].m_vertex == ed->m_vertex;
    }
    if (n > 2) {
        for (i = 0; i < n; i++) {
            result = result && i == e[e[e[i].m_next].m_next].m_next;
        }
    }
    for (i = 0; i < m_numEdges; i++)
        m_edges[i].m_mark = 0;
    FUN_00a60890(m_edges);
    for (i = 0; i < m_numEdges; i++)
        result = result && m_edges[i].m_mark == 1;
    return result;
}
}
}   // namespace f3m_00a60990

// @f3 0x00a62560 (community match, verified in this file)
namespace f3m_00a62560 {
namespace InitA62560 {
struct Flag {char value;Flag(bool v):value(v){}Flag(const Flag& other):value(other.value){}};
struct Item {virtual void destroy(int);short managed,refs;Item* FUN_009a90b0(void*,unsigned);};
struct Allocator {Item* FUN_008f6d30(unsigned,int);};extern void* (__stdcall* DAT_00d9b080)(unsigned long);extern unsigned long DAT_010f3170;extern char DAT_00e86d58;
struct Object {void* vtable;int unk04;Item* item;void FUN_009ee7e0(Item*,Flag);Object* FUN_00a62560(void*);};
// pdb: hkDisplaySerializeOStream::hkDisplaySerializeOStream | hkDisplaySerializeOStream.obj | fnv360_0822_retail, call_gap, medium
// pdb params: writer
Object* Object::FUN_00a62560(void* source){Allocator* allocator=(Allocator*)DAT_00d9b080(DAT_010f3170);Item* created=allocator->FUN_008f6d30(0x1c,0x1a);created->managed=0x1c;created=created->FUN_009a90b0(source,0x2000);FUN_009ee7e0(created,Flag(false));vtable=&DAT_00e86d58;Item* current=item;if(current->managed&&--current->refs==0)current->destroy(1);return this;}
}

}   // namespace f3m_00a62560

// @f3 0x00a762d0 (community match, verified in this file)
namespace f3m_00a762d0 {
namespace Copy308 {
struct Heap {void FUN_008f6d90(void*,unsigned,int);void* FUN_008f6d30(unsigned,int);};extern Heap* (__stdcall* DAT_00d9b080)(unsigned);extern unsigned DAT_010f3170;
struct Array {int* data;int count;unsigned capacity;};struct Owner {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28;Array array;};
struct Object {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;Owner* owner;void hkpConstraintChainInstanceAction_getEntities(Array*);};
// pdb: hkpConstraintChainInstanceAction::getEntities | hkpConstraintChainInstanceAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Object::hkpConstraintChainInstanceAction_getEntities(Array* out){Array* source=&owner->array;int capacity=out->capacity&0x3fffffff;if(capacity<source->count){if(!(out->capacity&0x80000000)){Heap* heap=(Heap*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(out->data,capacity*4,0x17);}Heap* heap=(Heap*)TlsGetValue(DAT_010f3170);out->data=(int*)heap->FUN_008f6d30(source->count*4,0x17);out->capacity=(out->capacity&0x40000000)|source->count;}int count=source->count;out->count=count;int* dest=out->data;int* src=source->data;for(int i=0;i<count;++i)dest[i]=src[i];}
}


}   // namespace f3m_00a762d0

// @f3 0x00a74790 (community match, verified in this file)
namespace c4_00a74790 {

extern void* DAT_00e84950[];

struct Vector4
{
    float x, y, z, w;

    float& operator()(int i)
    {
        return (&x)[i];
    }

    void setZero4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};

struct Matrix3
{
    Vector4 m_col0;
    Vector4 m_col1;
    Vector4 m_col2;

    void setZero()
    {
        m_col0.setZero4();
        m_col1.setZero4();
        m_col2.setZero4();
    }

    float& operator()(int row, int col)
    {
        return (&m_col0)[col](row);
    }

    void setIdentity()
    {
        setZero();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};

struct Transform
{
    Matrix3 m_rotation;
    Vector4 m_translation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_translation.x = m_translation.y = m_translation.z = m_translation.w = 0.0f;
    }
};

struct ConstraintBase
{
    void** m_vptr;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;

    ConstraintBase()
    {
        m_vptr = DAT_00e84950;
        m_06 = 1;
        m_08 = 0;
    }
};

struct Atom
{
    unsigned short m_type;
    Atom(unsigned short type) : m_type(type) {}
};

struct ConstraintData;

struct BridgeAtom : Atom
{
    unsigned short m_pad02;
    int m_04;
    int m_08;
    BridgeAtom() : Atom(1) {}
    void hkpBridgeConstraintAtom_init(ConstraintData* data);
};

struct ConstraintData : ConstraintBase
{
    BridgeAtom m_bridge;
    void* m_child;
    float m_1c;
    bool m_20;
    int m_24;
    int m_28;
    int m_2c;
    Transform m_transformA;
    Transform m_transformB;
};

struct NiDynamicEffect_GetRTTI : ConstraintData
{
    NiDynamicEffect_GetRTTI();
};

// pdb: hkpPointToPathConstraintData::hkpPointToPathConstraintData | hkpPointToPathConstraintData.obj | fnv360_0721_beta, caller_sim, medium
NiDynamicEffect_GetRTTI::NiDynamicEffect_GetRTTI()
{
    m_child = 0;
    m_1c = 0.0f;
    m_20 = true;
    m_transformA.setIdentity();
    m_transformB.setIdentity();
    m_bridge.hkpBridgeConstraintAtom_init(this);
}

}

// @f3 0x00a6baa0 (community match, verified in this file)
namespace f3m_00a6baa0 {
namespace Small515 {
struct FUN_009a4660 {virtual ~FUN_009a4660(); int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; FUN_009a4660(int);};
struct Vector {float x,y,z,w;};
struct FUN_00a6baa0:FUN_009a4660 {Vector first,second;int flags;float value84,value88;virtual ~FUN_00a6baa0();FUN_00a6baa0(float,float,int,const Vector&,const Vector&);};
// pdb: hkDisplayCone::hkDisplayCone | hkDisplayCone.obj | fnv360_0822_retail, objrun, medium
// pdb params: coneAngle, coneHeight, numSegments, coneAxis, startPos
FUN_00a6baa0::FUN_00a6baa0(float a,float b,int n,const Vector& p,const Vector& q):FUN_009a4660(4),first(q),second(p),flags(n),value84(a),value88(b){}
}
}   // namespace f3m_00a6baa0

// @f3 0x00a64b90 (community match, verified in this file)
#include <windows.h>
namespace match656 {
extern void* DAT_00e86f08;extern void* DAT_00e86ee8;extern void* DAT_00e86ec8;extern void* DAT_00dcc494;
extern DWORD DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(DWORD);
struct Heap{void FUN_008f6d90(void*,unsigned,int);};
struct Other{void FUN_00922cf0();};
struct Owner {void* table;unsigned short size,refs;void* secondaryTable;unsigned secondaryState;char* data;int count;int capacity;Other other;void FUN_00a64b90();};
// pdb: hkStreamStatisticsCollector::~hkStreamStatisticsCollector | hkStreamStatisticsCollector.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_00a64b90(){
 table=&DAT_00e86f08;secondaryTable=&DAT_00e86ee8;
 other.FUN_00922cf0();
 if((capacity&0x80000000)==0){unsigned bytes=capacity&0x3fffffff;Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(data,bytes,0x17);}
 secondaryTable=&DAT_00e86ec8;secondaryState=0;table=&DAT_00dcc494;
}
}

// @f3 0x00a752b0 (community match, verified in this file)
namespace f3m_00a752b0 {
namespace Fa752b0 {
int __cdecl FUN_00954d20(float value);
struct Vec4 {
 float x,y,z,w;
 __forceinline void setInterpolate4(const Vec4& a,const Vec4& b,float f) {
  float g=1.0f-f;
  x=a.x*g+b.x*f;
  y=a.y*g+b.y*f;
  z=a.z*g+b.z*f;
  w=a.w*g+b.w*f;
 }
 void Set(const Vec4& a){x=a.x;y=a.y;z=a.z;w=a.w;}
};
struct Curve
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4* keys;
    int count;
    void FUN_00a752b0(float t, Vec4* out);
};
// pdb: hkpLinearParametricCurve::getPoint | hkpLinearParametricCurve.obj | tesv_win, objopen_prop, low
void Curve::FUN_00a752b0(float t, Vec4* out)
{
    int i = t < 0.0f ? 0 : FUN_00954d20(t);
    int j = i + 1;
    if (j < count) {
        float f = t - i;
        out->setInterpolate4(keys[i],keys[j],f);
    }
    else {
        const Vec4& a = keys[i];
        out->Set(a);
    }
}
}



}   // namespace f3m_00a752b0

// @f3 0x00a71760 (community match, verified in this file)
extern unsigned DAT_010f3170;
extern int DAT_00e87b68,DAT_00dcc494;
namespace f3m_00a71760 {

namespace Cleanup709 {
extern void* (__stdcall * const DAT_00d9b080)(unsigned);
struct Heap { void FUN_008f6d90(void*,unsigned,int); };
struct Ref {
 virtual ~Ref();
 unsigned short managed; short refs;
 void Release() { if(managed) { --refs; if(!refs) delete this; } }
};
struct RefPtr { Ref* p; operator bool() const { return p != 0; } Ref* operator->() const { return p; } };
struct Record {
 unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 unsigned unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 RefPtr references[3];
 unsigned unk4c;
};
struct Owner {
 void* table;
 unsigned short unk04,unk06;
 unsigned unk08,unk0c,unk10,unk14;
 Record* data;
 int count;
 unsigned capacity;
 void FUN_00a71760();
};
// pdb: hkpPoweredChainData::~hkpPoweredChainData | hkpPoweredChainData.obj | fnv360_0822_retail, call_seq, high
void Owner::FUN_00a71760() {
 table=&DAT_00e87b68;
 for(int i=0;i<count;++i) {
  for(int j=0;j<3;++j) {
   if(data[i].references[j]) data[i].references[j]->Release();
  }
 }
 if(!(capacity & 0x80000000u)) {
  unsigned cap=capacity & 0x3fffffff;
  Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);
  heap->FUN_008f6d90(data,cap*sizeof(Record),0x17);
 }
 table=&DAT_00dcc494;
}
}

}   // namespace f3m_00a71760

// @f3 0x00a60890 (community match, verified in this file)
namespace c4_00a60890 {

extern unsigned long DAT_010f3170;

struct ThreadMemory
{
    void FUN_008f6d90(void* data, int bytes, int category);
};
extern ThreadMemory* (__stdcall* DAT_00d9b080)(unsigned long index);
void __cdecl FUN_00901f10(void* array, int elementSize) throw();

struct Edge
{
    unsigned short unk00;
    unsigned short twin;
    unsigned short next;
    unsigned short visited;
};

struct EdgeStack
{
    Edge** data;
    int size;
    unsigned capacityAndFlags;
    Edge* storage[1024];

    EdgeStack()
    {
        data = storage;
        size = 0;
        capacityAndFlags = 0x80000400;
    }
    ~EdgeStack()
    {
        if ((capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemory* memory = DAT_00d9b080(DAT_010f3170);
            memory->FUN_008f6d90(data, capacity * sizeof(Edge*), 0x17);
        }
    }
    void pushBack(Edge* edge)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(Edge*));
        data[size] = edge;
        ++size;
    }
};

struct Mesh
{
    int unk00;
    Edge* edges;
    void FUN_00a60890(Edge* start);
};

// pdb: hkGeomHull::visitAllNextAndMirrorEdges | hkGeomHull.obj | tesv_win, objrun_open, low
void Mesh::FUN_00a60890(Edge* start)
{
    Edge* base = edges;
    EdgeStack stack;
    stack.pushBack(start);
    while (stack.size)
    {
        Edge* edge = stack.data[stack.size - 1];
        --stack.size;
        Edge* current = edge;
        do
        {
            current = &base[current->next];
            current->visited = 1;
        } while (current != edge);
        current = edge;
        do
        {
            current = &base[current->next];
            Edge* twin = &base[current->twin];
            if (!twin->visited)
                stack.pushBack(twin);
        } while (current != edge);
    }
}

}

// @f3 0x00a61520 (community match, verified in this file)
namespace f3m_00a61520 {
namespace f3m_00a61520 {
extern void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);
void __cdecl FUN_009234e0(void* destination, const void* source, unsigned int count);

struct ArrayA61 {
    char* data00;
    int size04;
    int capacityAndFlags08;
    __forceinline ArrayA61() : data00(0), size04(0), capacityAndFlags08(0x80000000) {}
    __forceinline char* ExpandBy(int count) {
        int oldSize = size04;
        int newSize = oldSize + count;
        int capacity = capacityAndFlags08 & 0x3fffffff;
        if (capacity < newSize) {
            int doubled = capacity + capacity;
            FUN_00901e90(this, newSize < doubled ? doubled : newSize, 1);
        }
        char* result = data00 + oldSize;
        size04 = newSize;
        return result;
    }
};

struct HolderA61 {
    ArrayA61 array00;
    int extraC;
    int extra10;
    HolderA61* FUN_00a61520(const HolderA61* source);
};

HolderA61* HolderA61::FUN_00a61520(const HolderA61* source) {
    array00.data00 = 0;
    array00.size04 = 0;
    array00.capacityAndFlags08 = 0x80000000;
    char* dst = array00.ExpandBy(source->array00.size04);
    FUN_009234e0(dst, source->array00.data00, source->array00.size04);
    extraC = source->extraC;
    extra10 = source->extra10;
    return this;
}
}
}   // namespace f3m_00a61520

// @f3 0x00a67b30 (community match, verified in this file)
namespace f3m_00a67b30 {
namespace EdgeLines904 {
struct Vec4 {
 float x,y,z,w;
 Vec4& operator=(const Vec4& v) { x=v.x; y=v.y; z=v.z; w=v.w; return *this; }
};
void __cdecl FUN_00901f10(void*,int);
template<class T> struct Array {
 T* data; int size; int capacity;
 void pushBack(const T& v) {
  if(size==(capacity&0x3fffffff)) FUN_00901f10(this,sizeof(T));
  data[size++]=v;
 }
};
struct Triangle {int a,b,c;};
struct Geometry {Array<Vec4> vertices;Array<Triangle> triangles;};
struct Builder {
 unsigned unk00,unk04; Geometry* geometry;
 void FUN_00a67b30(Array<Vec4>& out);
};
// pdb: hkDisplayConvex::getWireframeGeometry | hkDisplayConvex.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void Builder::FUN_00a67b30(Array<Vec4>& out) {
 if(geometry) {
  for(int i=geometry->triangles.size-1;i>=0;--i) {
   Triangle tri;
   tri.a=geometry->triangles.data[i].a;
   tri.b=geometry->triangles.data[i].b;
   tri.c=geometry->triangles.data[i].c;
   out.pushBack(geometry->vertices.data[tri.a]);
   out.pushBack(geometry->vertices.data[tri.b]);
   out.pushBack(geometry->vertices.data[tri.a]);
   out.pushBack(geometry->vertices.data[tri.c]);
   out.pushBack(geometry->vertices.data[tri.b]);
   out.pushBack(geometry->vertices.data[tri.c]);
  }
 }
}
}
}   // namespace f3m_00a67b30

// @f3 0x00a68fc0 (community match, verified in this file)
namespace MatchA68FC0 {
struct Coord{float value; operator float()const{return value;}};
struct PVec { Coord x; float y; Coord z; float w; };
struct QVec { Coord x; float y; float z; float w; };
inline float Dot3(const PVec& a,const QVec& b){return a.x*b.x+a.y*b.y+a.z*b.z;}
struct Heap { void FUN_008f6d90(void* data,int bytes,int category); };
extern unsigned long DAT_010f3170;
extern Heap* (__stdcall* const DAT_00d9b080)(unsigned long);
extern const float DAT_00e87060;
struct Array {
 PVec* data; int size; unsigned capacity;
 Array():data(0),size(0),capacity(0x80000000){}
 void Clear(){unsigned cap=capacity;if(!(cap&0x80000000u)){int n=capacity&0x3fffffff;Heap* heap=DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(data,n*sizeof(PVec),0x17);}}
};
struct Array2 {
 QVec* data; int size; unsigned capacity;
 Array2():data(0),size(0),capacity(0x80000000){}
 void Clear(){unsigned cap=capacity;if(!(cap&0x80000000u)){int n=capacity&0x3fffffff;Heap* heap=DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(data,n*sizeof(QVec),0x17);}}
};
struct Shape { const Array* FUN_009e7930(); void FUN_009e8020(Array2* points); };
// pdb: _addBoundingPlanes | hkpConvexRadiusBuilder.obj | fnv360_0822_debug, objrun, low, conflict (bridge: _getPlaneToSurfaceDistance)
static __declspec(noinline) float FUN_00a68fc0(Shape* shape) {
 const Array* planes=shape->FUN_009e7930();
 Array2 points;
 shape->FUN_009e8020(&points);
 float best=DAT_00e87060;
 int count=planes->size;
 for(int i=0;i<points.size;++i) {
  for(int j=0;j<count;++j) {
   float distance=Dot3(planes->data[j],points.data[i]);
   distance+=planes->data[j].w;
   if(distance>best)best=distance;
  }
 }
 points.Clear();
 return best;
}
float MaximumPlaneDistance(Shape* shape) {return FUN_00a68fc0(shape);}
}

// @f3 0x00a6f800 (community match, verified in this file)
namespace na6f800 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
extern unsigned long DAT_010f3170;
struct ThreadMemory {
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
inline ThreadMemory* Mem() throw() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray {
    T* data;
    int size;
    int capAndFlags;
    ~hkArray() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Mem()->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct Elem20 { int v[8]; };
struct RefObj { void FUN_009316f0() throw(); };
}
class hkBaseObject {
public:
    virtual ~hkBaseObject() throw() {}
};
class hkReferencedObject : public hkBaseObject {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};
class FUN_00a6f800 : public hkReferencedObject {
public:
    na6f800::RefObj* m_08;
    na6f800::RefObj* m_0c;
    int unk10[16];
    na6f800::hkArray<char> m_50;
    na6f800::hkArray<na6f800::Elem20> m_5c;
    na6f800::hkArray<char> m_68;
    int unk74[32];
    FUN_00a6f6f0 m_f4;
    virtual ~FUN_00a6f800() throw();
};
// pdb: hkpSerializedAgentNnEntry::~hkpSerializedAgentNnEntry | hkpSerializedAgentNnEntry.obj | fnv360_0822_retail, call_seq, high
FUN_00a6f800::~FUN_00a6f800() throw()
{
    if (m_08)
        m_08->FUN_009316f0();
    if (m_0c)
        m_0c->FUN_009316f0();
}

// @f3 0x00a61250 (community match, verified in this file)
#include <new>
#include <windows.h>

namespace NamedRecords61250 {

struct ThreadMemory {
    void* FUN_008f6d30(int bytes, int category) throw();
    void FUN_008f6d90(void* data, int bytes, int category) throw();
};

extern unsigned long DAT_010f3170;

static __forceinline ThreadMemory* Memory() throw() {
    return static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
}

int __cdecl hkString_strCmp(const char* first, const char* second) throw();
int __cdecl FUN_009233f0(const char* string) throw();
void* __cdecl FUN_009234e0(void* destination, const void* source, unsigned int count) throw();
void __cdecl FUN_00901e90(void* array, int capacity, int stride) throw();

template<class T> static __forceinline void CopyConstruct(T* destination, const T* source, int count) throw() {
    for (int i = 0; i < count; ++i) {
        new (destination + i) T(source[i]);
    }
}
template<class T> static __forceinline void Construct(T* destination, int count) throw() {
    for (int i = 0; i < count; ++i)
        new (destination + i) T;
}
template<class T> static __forceinline void Destruct(T* elements, int count) throw() {
    for (int i = 0; i < count; ++i)
        elements[i].~T();
}

template<class T> struct Array {
    T* data;
    int size;
    int capacityFlags;

    __forceinline int Capacity() const throw() { return capacityFlags & 0x3fffffff; }
    // Fake match: noinline preserves the original swap call while exposing its real non-escaping body.
    __declspec(noinline) void FUN_00a82280(Array* other) throw() {
        T* savedData = data;
        int savedSize = size;
        int savedCapacity = capacityFlags;
        data = other->data;
        size = other->size;
        capacityFlags = other->capacityFlags;
        other->data = savedData;
        other->size = savedSize;
        other->capacityFlags = savedCapacity;
    }

    __forceinline ~Array() throw() {
        Destruct(data, size);
        if (!(capacityFlags & 0x80000000u))
            Memory()->FUN_008f6d90(data, Capacity() * sizeof(T), 0x17);
    }

    __forceinline void ReserveStorage(int capacity) throw() {
        int oldCapacity = Capacity();
        if (oldCapacity < capacity) {
            int doubled = oldCapacity * 2;
            FUN_00901e90(this, capacity >= doubled ? capacity : doubled, sizeof(T));
        }
    }

    __forceinline void Reserve(int required) throw() {
        int capacity = Capacity();
        if (required > capacity) {
            int doubled = capacity * 2;
            int newCapacity = required >= doubled ? required : doubled;
            int oldSize = size;
            Array old = {0, 0, static_cast<int>(0x80000000u)};
            old.FUN_00a82280(this);
            ReserveStorage(newCapacity);
            CopyConstruct(data, old.data, oldSize);
            size = oldSize;
        }
    }

    __forceinline void SetSize(int newSize) throw() {
        int oldSize = size;
        if (newSize < oldSize) {
            for (int i = newSize; i < oldSize; ++i)
                data[i].~T();
        } else {
            Reserve(newSize);
            T* storage = data;
            for (int i = oldSize; i < newSize; ++i)
                new (storage + i) T();
        }
        size = newSize;
    }

    __forceinline T& ExpandOne() throw() {
        int index = size;
        SetSize(index + 1);
        return data[index];
    }
};

struct Record {
    Array<char> key;
    void* value;
    int id;

    __forceinline Record() throw() {
        char* storage = static_cast<char*>(Memory()->FUN_008f6d30(1, 0x17));
        key.size = 1;
        key.capacityFlags = 1;
        key.data = storage;
        *storage = 0;
    }
    void FUN_00a61520(const Record* source) throw();
    __forceinline Record(const Record& source) throw() { FUN_00a61520(&source); }

    __forceinline void SetKey(const char* source) throw() {
        if (source && *source) {
            int length = FUN_009233f0(source);
            key.ReserveStorage(length + 1);
            key.size = length + 1;
            FUN_009234e0(key.data, source, length + 1);
        } else {
            key.ReserveStorage(1);
            key.size = 1;
            key.data[0] = 0;
        }
    }
};

struct Lock {
    void FUN_00908a00() throw();
    __forceinline void Leave() throw() {
        *(unsigned int*)((char*)this + 0x18) = 0xffffffffu;
        *(unsigned int*)((char*)this + 0x1C) = 0xffffffffu;
        LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(this));
    }
};

struct Registry {
    unsigned int unk00;
    unsigned int unk04;
    int nextId;
    Array<Record> records;
    Lock* lock;
    int FUN_00a61250(const char* name, void* value) throw();
};

// pdb: hkProcessFactory::registerProcess | hkProcessFactory.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpWorld::hkpWorld)
// pdb params: viewerName, creationFunction
int Registry::FUN_00a61250(const char* name, void* value) throw() {
    lock->FUN_00908a00();
    Record* record = 0;
    int i = 0;
    for (; i < records.size; ++i) {
        const char* key = records.data[i].key.data;

        if (hkString_strCmp(key, name) == 0) {
            record = &records.data[i];
            break;
        }
    }
    if (!record) {
        record = &records.ExpandOne();
        record->SetKey(name);
        record->value = value;
        record->id = nextId++;
    }
    lock->Leave();
    return record->id;
}
}

// @f3 0x00a61050 (community match, verified in this file)
#include <windows.h>
namespace f3m_00a61050 {

namespace anon_00a61050 {} using namespace anon_00a61050; namespace anon_00a61050 {
struct SlotEntry;
struct Slot60 { void* key; unsigned int unk04, unk08, unk0C, unk10; };
struct Other60 {
    unsigned int unk000, unk004, unk008, unk00C, unk010, unk014;
    int unk018;
    int unk01C;
    void FUN_00908a00();
};
struct Owner60 {
    unsigned int unk00, unk04, unk08;
    Slot60* slots;
    int count;
    unsigned int unk14;
    Other60* other;
    int FUN_00a60f80(SlotEntry* entry);
    int FUN_00a61000(int idx, int param);
    int FUN_00a61050(SlotEntry* entry, int param);
};
}

// pdb: hkProcessFactory::createProcess | hkProcessFactory.obj | fnv360_0822_debug, caller_sim, low
// pdb params: processName, contexts
int Owner60::FUN_00a61050(SlotEntry* entry, int param) {
    Other60* edi = other;
    edi->FUN_00908a00();
    int eax = FUN_00a60f80(entry);
    int esi;
    if (eax < 0) {
        esi = 0;
    } else {
        esi = FUN_00a61000(eax, param);
    }
    int m1 = -1;
    edi->unk018 = m1;
    edi->unk01C = m1;
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(edi));
    return esi;
}
}   // namespace f3m_00a61050

// @f3 0x00a71350 (community match, verified in this file)
namespace f3m_00a71350 {
namespace f3w_a71350 {
struct hkVector4 {
    float lanes[4];
    float& operator()(int i) { return lanes[i]; }
    const float& operator()(int i) const { return lanes[i]; }
    void set(float a, float b, float c, float d) { lanes[0] = a; lanes[1] = b; lanes[2] = c; lanes[3] = d; }
    void setCross(const hkVector4& v1, const hkVector4& v2) {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    void addMul4(float rs, const hkVector4& v) {
        float r = rs;
        lanes[0] += r * v.lanes[0];
        lanes[1] += r * v.lanes[1];
        lanes[2] += r * v.lanes[2];
        lanes[3] += r * v.lanes[3];
    }
    void subMul4(float rs, const hkVector4& v) {
        float r = rs;
        lanes[0] -= r * v.lanes[0];
        lanes[1] -= r * v.lanes[1];
        lanes[2] -= r * v.lanes[2];
        lanes[3] -= r * v.lanes[3];
    }
    void add4(const hkVector4& v) {
        lanes[0] += v.lanes[0];
        lanes[1] += v.lanes[1];
        lanes[2] += v.lanes[2];
        lanes[3] += v.lanes[3];
    }
    void setNeg4(const hkVector4& v) {
        lanes[0] = -v.lanes[0];
        lanes[1] = -v.lanes[1];
        lanes[2] = -v.lanes[2];
        lanes[3] = -v.lanes[3];
    }
    float dot4(const hkVector4& v) const {
        float r = lanes[0] * v.lanes[0] + lanes[1] * v.lanes[1] + lanes[2] * v.lanes[2] + lanes[3] * v.lanes[3];
        return r;
    }
};
struct hkQuaternion {
    hkVector4 m_vec;
};
}
using namespace f3w_a71350;

struct QuaternionView { const hkQuaternion* value; };
// pdb: estimateAngleToLs | hkpPoweredChainData.obj | fnv360_0822_retail, objrun_prop, medium
static __declspec(noinline) void FUN_00a71350(QuaternionView fromPtr, const hkQuaternion& to, hkVector4& angleOut)
{
    angleOut.setCross(fromPtr.value->m_vec, to.m_vec);
    angleOut.addMul4(to.m_vec.lanes[3], fromPtr.value->m_vec);
    angleOut.subMul4(fromPtr.value->m_vec.lanes[3], to.m_vec);
    angleOut.add4(angleOut);
    if (to.m_vec.dot4(fromPtr.value->m_vec) < 0.0f)
        angleOut.setNeg4(angleOut);
}

void estimate_angle_caller_a71350(const hkQuaternion& from, const hkQuaternion& to, hkVector4& out)
{
    QuaternionView view = { &from };
    FUN_00a71350(view, to, out);
}
}   // namespace f3m_00a71350

// @f3 0x00a76f80 (community match, verified in this file)
namespace f3m_00a76f80 {
// pdb: hkpConvexPieceMeshShape::vertexIsSet | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: stream, key
bool* __stdcall FUN_00a76f80(bool* pbResult, const int* bits, unsigned int bitIndex)
{
    unsigned int wordIndex = bitIndex / 31;
    unsigned int bitWithinWord = bitIndex % 31;
    unsigned int mask = 1u << bitWithinWord;
    *pbResult = (bits[bits[0] + wordIndex + 1] & mask) != 0;
    return pbResult;
}
}   // namespace f3m_00a76f80

// @f3 0x00a76fc0 (community match, verified in this file)
extern int DAT_00e852b8;
namespace f3m_00a76fc0 {
namespace f3m_00a76fc0c {

extern void __stdcall FUN_0099f010(int a);

struct Addr04 {
    int unk00;
    unsigned short memSizeAndFlags;   // +4
    short referenceCount;             // +6
};

struct Target {
    int vtbl00;      // +0x00
    int unk04;       // +0x04
    int unk08;       // +0x08
    int unk0C;       // +0x0c
    int vtbl10;      // +0x10
    int unk14;       // +0x14
    Addr04* first;   // +0x18
    Addr04* second;  // +0x1c
    float unk20;     // +0x20

    Target* __thiscall FUN_00a76fc0(Addr04* second, Addr04* first, float f);
};

// pdb: hkpConvexPieceMeshShape::hkpConvexPieceMeshShape | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: inputMesh, convexPieceStream, radius
Target* __thiscall Target::FUN_00a76fc0(Addr04* second, Addr04* first, float f)
{
    FUN_0099f010(8);
    unk20 = f;
    this->first = first;
    vtbl00 = (int)&DAT_00e852b8;
    vtbl10 = 0xe85294;
    this->second = second;
    if (this->second->memSizeAndFlags != 0)
        ++this->second->referenceCount;
    if (this->first->memSizeAndFlags != 0)
        ++this->first->referenceCount;
    return this;
}
}
}   // namespace f3m_00a76fc0

// @f3 0x00a7e010 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a7e010 {
// FUN_00a7e010 - deleting-dtor style wrapper in a Havok ref-counted object.
// 48-byte function: call the base reset, then (flags & 1) free the memory through
// the thread-local allocator, return this (thiscall, ret 4).
extern void* (__stdcall *DAT_00d9b080)(unsigned long);

struct Heap {
    void FUN_008f6d90(void* block, unsigned int size, int tag);
};

struct Obj {
    void* table;
    unsigned short memSize;
    short refs;
    int unk08;
    void FUN_00a7def0();
    Obj* FUN_00a7e010(int flags);
};

Obj* Obj::FUN_00a7e010(int flags)
{
    FUN_00a7def0();
    if (flags & 1) {
        Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSize, 0x15);
    }
    return this;
}
}   // namespace f3m_00a7e010

// @f3 0x00a71520 (community match, verified in this file)
namespace f3m_00a71520 {
// Candidate 2 for 0x00a71520 (claim clm_6c9fbc88aa6f40788ae6)
// void __cdecl FUN_00a71520(void* pOwner, unsigned int uiOffset, unsigned int uiBit)
//
// 59 bytes, three stack arguments, ret without a byte count, so __cdecl. The entry reads the dword at
// pOwner+0x0c and then the dword at +0x1c of that, which is an element index; the dword at pOwner+0x28 is
// an array whose +0x1c holds an element base. The index becomes esi * 3 shifted left by 4, which is * 48,
// so elements are 48 bytes. The target is that base plus the index times 48, kept in ESI, and the second
// argument is held in EBP and used as an index into it at both the read and the write, which is why the
// entry pushes EBP at all: cand1 folded the offset into the pointer arithmetic and so lost the register,
// coming out four bytes short with add esi, [esp+0x10] and two accesses of [esi] instead.
// The third argument selects a two-bit field: doubled into CL, 3 is shifted into that position and
// inverted, and the byte is read, masked and written back. What marks this as a field clear rather than a
// field store is the second shift: the entry also does xor al,al / shl al,cl and ors that in, so the source
// ORs a literal zero into the field position. A literal zero survives the shift because the count is a
// runtime value in CL, which this compiler will not fold, and that is why the redundant or survives too.
// pdb: hk1dAngularVelocityMotorCommitJacobianInMotorInfo | hkpPoweredChainData.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: hkpPoweredChainData::enableMotor)
void __cdecl FUN_00a71520(void* pOwner, unsigned int uiOffset, unsigned int uiBit)
{
    unsigned int uiIndex = *(unsigned int*)(*(unsigned int*)((char*)pOwner + 0x0c) + 0x1c);
    unsigned char* pBase = *(unsigned char**)(*(unsigned int*)((char*)pOwner + 0x28) + 0x1c) + uiIndex * 48;

    unsigned int uiShift = uiBit * 2;
    unsigned char ucMask = (unsigned char)(3u << uiShift);
    unsigned char ucValue = (unsigned char)(0u << uiShift);

    pBase[uiOffset] = (unsigned char)((pBase[uiOffset] & ~ucMask) | ucValue);
}
}   // namespace f3m_00a71520

// @f3 0x00a70b40 (community match, verified in this file)
namespace f3m_00a70b40 {
namespace na70b40 {
struct SizeOut {
    unsigned int bytes;
    unsigned int count;
};
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* data;
    unsigned int count;
    void FUN_00a70b40(bool on, SizeOut* out);
};
// pdb: hkpStiffSpringChainData::getRuntimeInfo | hkpStiffSpringChainData.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: wantRuntime, infoOut
void Owner::FUN_00a70b40(bool on, SizeOut* out)
{
    if (on) {
        unsigned int n = count;
        out->count = n;
        out->bytes = n * 8;
    } else {
        out->count = 0;
        out->bytes = 0;
    }
}
}
}   // namespace f3m_00a70b40

// @f3 0x00a71080 (community match, verified in this file)
namespace f3m_00a71080 {
namespace na71080 {
struct Part {
    void hkRotation_set(void* p);
};
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Part part20;
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
    Part part50;
    void FUN_00a71080(void* a, void* b);
};
// pdb: hkpRotationalConstraintData::setInWorldSpace | hkpRotationalConstraintData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: bodyARotation, bodyBRotation
void Owner::FUN_00a71080(void* a, void* b)
{
    part20.hkRotation_set(a);
    part50.hkRotation_set(b);
}
}
}   // namespace f3m_00a71080

// @f3 0x00a70b70 (community match, verified in this file)
namespace f3m_00a70b70 {
namespace f3m_00a70b70 {

struct Keyframe
{
    float first[4];
    float second[4];
    float time;
    float unk24, unk28, unk2c;
};

struct DynArray
{
    Keyframe* data;
    int count;
    int capacityFlags;
};

void __cdecl FUN_00901f10(DynArray* array, unsigned int elementSize);

struct Track
{
    char unk00[0x18];
    DynArray keys;

    void FUN_00a70b70(const float first[4], const float second[4], float time);
};

// pdb: hkpStiffSpringChainData::addConstraintInfoInBodySpace | hkpStiffSpringChainData.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pivotInA, pivotInB, springLength
void Track::FUN_00a70b70(const float first[4], const float second[4], float time)
{
    DynArray& arr = keys;
    if (arr.count == (arr.capacityFlags & 0x3fffffff))
        FUN_00901f10(&arr, sizeof(Keyframe));
    Keyframe& k = arr.data[arr.count++];
    int i;
    for (i = 0; i < 4; ++i) k.first[i] = first[i];
    for (i = 0; i < 4; ++i) k.second[i] = second[i];
    k.time = time;
}

}
}   // namespace f3m_00a70b70

// @f3 0x00a71050 (community match, verified in this file)
#include <windows.h>
namespace f3m_00a71050 {

namespace f3m_00a71050 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Allocator00a71050 { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct State00a71050 {
    void* volatile table;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08, unk0c, unk10, unk14;
    void* data;
    unsigned int count;
    int capacityFlags;
    void FUN_00a70c70();
    void __thiscall hkRotation_set(unsigned int a);
    State00a71050* FUN_00a71050(unsigned int flags);
    void __stdcall FUN_00a71080(unsigned int a);
};
// pdb: hkpStiffSpringChainData::`scalar deleting destructor' | hkpStiffSpringChainData.obj | fnv360_0822_retail, vtable_prefix, high
State00a71050* State00a71050::FUN_00a71050(unsigned int flags)
{
    FUN_00a70c70();
    if (flags & 1) {
        Allocator00a71050* allocator = (Allocator00a71050*)DAT_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(this, unk04, 0x2c);
    }
    return this;
}
}
}   // namespace f3m_00a71050

// @f3 0x00a71500 (community match, verified in this file)
namespace f3m_00a71500 {
struct S00a71500_Out {
    int size;
    int u04;
};
struct S00a71500_Node {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int count;
    void FUN_00a71500(int unused, S00a71500_Out* out);
};

// pdb: hkpPoweredChainData::getRuntimeInfo | hkpPoweredChainData.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: wantRuntime, infoOut
void S00a71500_Node::FUN_00a71500(int unused, S00a71500_Out* out)
{
    int n = count;
    int a = n * 6;
    out->u04 = a;
    out->size = ((n + 3) & ~3) + (a + n * 2) * 8;
}
}   // namespace f3m_00a71500

// @f3 0x00a72140 (community match, verified in this file)
namespace f3m_00a72140 {
struct W614Dtor {
    unsigned int unk00;
    unsigned short unk04;
    __declspec(noinline) void FUN_00a71760();
    void* FUN_00a72140(unsigned int flags);
};
// pdb: hkpPoweredChainData::`scalar deleting destructor' | hkpPoweredChainData.obj | fnv360_0822_retail, vtable_prefix, high
void* W614Dtor::FUN_00a72140(unsigned int flags) {
    FUN_00a71760();
    if (flags & 1) {
        na6f6f0::ThreadMemory* h = na6f6f0::Mem();
        h->FUN_008f6d90(this, unk04, 0x2c);
    }
    return this;
}
}   // namespace f3m_00a72140

// @f3 0x00a60f10 (community match, verified in this file)
namespace f3m_00a60f10 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct Obj {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a60e80();
    Obj* FUN_00a60f10(unsigned int flags);
};
// pdb: hkIArchive::`scalar deleting destructor' | hkIArchive.obj | fnv360_0822_retail, vtable, high
Obj* Obj::FUN_00a60f10(unsigned int flags)
{
    FUN_00a60e80();
    if (flags & 1) {
        Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x1a);
    }
    return this;
}
}

// @f3 0x00a63c30 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a63c30 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern char DAT_00e808e0, DAT_00e86de8, DAT_00e86dc8, DAT_00e7a244, DAT_00dcc494, DAT_00e7e644, DAT_0116cec0;
extern const double FUN_00db8c48;
unsigned __int64 __cdecl FUN_009ee530() throw();
struct Heap {
    void* FUN_008f6d30(int bytes,int memoryClass) throw();
    void FUN_008f6d90(void* p,int bytes,int memoryClass) throw();
};
__forceinline Heap* GetHeap() { return (Heap*)TlsGetValue(DAT_010f3170); }
struct PtrArray {
    void** m_data; int m_size; unsigned int m_capacity;
    int getCapacity() const { return m_capacity & 0x3fffffff; }
    void Init() { m_data = 0; m_size = 0; m_capacity = 0x80000000; }
    __forceinline PtrArray& operator=(const PtrArray& a) {
        if (getCapacity() < a.m_size) {
            if ((m_capacity & 0x80000000) == 0) GetHeap()->FUN_008f6d90(m_data, getCapacity() * 4, 23);
            m_data = (void**)GetHeap()->FUN_008f6d30(a.m_size * 4, 23);
            m_capacity = (m_capacity & 0x40000000) | a.m_size;
        }
        int n = a.m_size;
        void** dst = m_data;
        m_size = n;
        void** src = a.m_data;
        for (int i = 0; i < n; ++i) dst[i] = src[i];
        return *this;
    }
};

struct Array { void* m_data; int m_size; unsigned int m_capacity; void Init() { m_data = 0; m_size = 0; m_capacity = 0x80000000; } };
struct Sub { void* unk00; int unk04,unk08,unk0c; void FUN_00a8bf60() throw(); };
struct Resource { void FUN_00943db0(int) throw(); };
struct Context {
    void* vtable; int unk04; Resource* resource; int unk0c; int ownsResource;
    Sub sub; float scale, weight; int unk2c, unk30, unk34;
    void FUN_00943bb0(Array*, int) throw();
    void Cleanup() throw() {
        vtable = &DAT_00e7a244;
        if (!ownsResource && resource) resource->FUN_00943db0(1);
        vtable = &DAT_00dcc494;
    }
};
struct Name { int unk00; void FUN_009b2540(void*) throw(); Name(void* p) throw() { FUN_009b2540(p); } };
struct Array24 { void* data; int size; unsigned int capacity; };
void __cdecl FUN_00a8bb00(Context*, Name*, int, int, Sub*, void*, Array24*) throw();
__forceinline void Free24(Array24* array) {
    if ((array->capacity & 0x80000000) == 0) {
        int n = array->capacity & 0x3fffffff;
        Heap* mem = GetHeap();
        mem->FUN_008f6d90(array->data, n * 24, 23);
    }
}
struct RefObj { void* vtbl; unsigned short memSizeAndFlags; short referenceCount; RefObj() { referenceCount = 1; } };
struct Base2 { void* vtbl2; unsigned char flag; Base2() { vtbl2 = &DAT_00e808e0; flag = 1; } };
class FUN_00a63c30 : public RefObj, public Base2 {
public:
    int unk10, unk14, unk18, unk1c;
    PtrArray first; Array second; Array third;
    FUN_00a63c30(PtrArray* source);
};
// pdb: hkStatisticsProcess::hkStatisticsProcess | hkStatisticsProcess.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: contexts
FUN_00a63c30::FUN_00a63c30(PtrArray* source) {
    vtbl = &DAT_00e86de8;
    vtbl2 = &DAT_00e86dc8;
    first.Init();
    Array* s = &second;
    s->Init();
    third.Init();
    {
        Array24 array;
        Context ctx;
        ctx.sub.FUN_00a8bf60();
        ctx.sub.unk00 = 0; ctx.sub.unk0c = 0; ctx.sub.unk04 = 0; ctx.sub.unk08 = 1;
        ctx.scale = (float)(FUN_00db8c48 / (double)FUN_009ee530());
        ctx.weight = 1.0f;
        array.data = 0; array.size = 0; array.capacity = 0x80000000;
        ctx.FUN_00943bb0(s, 1);
        FUN_00a8bb00(&ctx, &Name(&DAT_00e7e644), 1, 0, &ctx.sub, &DAT_0116cec0, &array);
        ctx.Cleanup();
        Free24(&array);
    }
    first = *source;
}
}

// @f3 0x00a60f40 (community match, verified in this file)
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(struct _RTL_CRITICAL_SECTION*);
namespace f3m_00a60f40 {
struct Lock {
    int cs00; int cs04; int cs08; int cs0c; int cs10; int cs14;
    int owner;
    int count;
    void FUN_00908a00();
    void Leave() { owner = -1; count = -1; LeaveCriticalSection((_RTL_CRITICAL_SECTION*)this); }
};
struct Entry { int value; int unk04; int unk08; int unk0c; int unk10; };
struct Obj {
    int unk00; int unk04; int unk08;
    Entry* entries;
    int unk10; int unk14;
    Lock* lock;
    int FUN_00a60f40(int index);
};
// pdb: hkProcessFactory::getProcessName | hkProcessFactory.obj | fnv360_0822_retail, call_seq, medium
// pdb params: id
int Obj::FUN_00a60f40(int index) {
    lock->FUN_00908a00();
    int value = entries[index].value;
    lock->Leave();
    return value;
}
}

// @f3 0x00a7e040 (community match, verified in this file)
namespace f3m_00a7e040 {
namespace f3m_00a7e040 {
struct Obj {
    void FUN_00a7e040();
};
// pdb: hkpConvexPenetrationUtil::codeBegin | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, objrun_open, low
void Obj::FUN_00a7e040()
{
}
}
}   // namespace f3m_00a7e040
