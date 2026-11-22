#include <string.h>
#include <windows.h>
// src/f3staging/f3blk_005e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005f1350 (community match, verified in this file)
#include <new>
namespace f3m_005f1350 {
extern int DAT_00e02090;struct Element5f13 {int* unk00;int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; void FUN_005fc3f0();Element5f13(){FUN_005fc3f0();unk00=&DAT_00e02090;}~Element5f13();};
// pdb: BSSimpleArray<PathingCoverLocation,1024>::_MoveItems | Pathfind.obj | fnv360_0822_retail, call_gap, low
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_005f1350(Element5f13* buffer,unsigned count){for(unsigned i=0;i<count;++i)new(buffer+i) Element5f13;}
}   // namespace f3m_005f1350

// @f3 0x005ecfe0 (community match, verified in this file)
#include <new>
namespace f3m_005ecfe0 {

struct FUN_006100c0 {
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
    FUN_006100c0(void* a1, void* a2);
};

struct Pool {
    void* vtbl;
    void* data;
    int count;
    int cap;
    int FUN_005eb230();
    int FUN_005e5350();
};

struct Owner {
    int unk00;
    int unk04;
    Pool pool08;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Pool pool30;
    int FUN_005ecfe0(void* a1, void* a2);
};

int Owner::FUN_005ecfe0(void* a1, void* a2) {
    unsigned int index = pool08.FUN_005eb230();
    FUN_006100c0* elem = &((FUN_006100c0*)pool08.data)[index];
    new (elem) FUN_006100c0(a1, a2);
    if (a2) {
        int v = *(int*)((char*)a2 + 0xC);
        Pool* pool = &pool30;
        int idx = pool->FUN_005e5350();
        ((int*)pool->data)[idx] = v;
    }
    return index;
}
}   // namespace f3m_005ecfe0

// @f3 0x005e0120 (community match, verified in this file)
namespace f3m_005e0120 {
// FUN_005e0120: BSScrapArray<NavMeshObstacleEdge*>::~BSScrapArray()
namespace f3m_005e0120 {

struct NavMeshObstacleEdge;

template <class T>
class BSSimpleArray
{
public:
    virtual ~BSSimpleArray();
    virtual void FUN_slot1();
    virtual void FUN_slot2(void* apPtr);
    virtual void FUN_slot3();
    T* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
};

template <class T>
class FUN_005e0120 : public BSSimpleArray<T>
{
public:
    virtual ~FUN_005e0120();
    virtual void FUN_slot2(void* apPtr);
    void* m_pAllocator;
};

template <class T>
BSSimpleArray<T>::~BSSimpleArray()
{
    if (pBuffer) { ((BSSimpleArray<T>*)this)->FUN_slot2(pBuffer); pBuffer = 0; uiAllocSize = 0; uiSize = 0; }
}

// pdb: BSScrapArray<NavMeshObstacleEdge *,1024>::~BSScrapArray<NavMeshObstacleEdge *,1024> | NavMeshObstacleCutter.obj | fnv360_0822_debug, call_seq, low
template <class T>
FUN_005e0120<T>::~FUN_005e0120()
{
    BSSimpleArray<T>* pBase = this;
    if (pBuffer) { pBase->FUN_slot2(pBuffer); pBuffer = 0; uiAllocSize = 0; uiSize = 0; }
}

template class FUN_005e0120<NavMeshObstacleEdge*>;

}
}   // namespace f3m_005e0120

// @f3 0x005ec000 (community match, verified in this file)
#include <new>
namespace f3m_005ec000 {

struct Elem5ec {
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
    Elem5ec(int a, int b);
};

struct Arr5ec {
    void* unk00;
    Elem5ec* data;
    unsigned int used;
    unsigned int cap;
    int Add();
};

struct Cls5ec {
    int unk00;
    int unk04;
    Arr5ec arr;
    int FUN_005ec000(int a, int b);
};

// pdb: PathingSolution::AddVirtualPathingNode | PathBuilder.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: aLocation, apNavMeshInfo
int Cls5ec::FUN_005ec000(int a, int b) {
    unsigned int idx = arr.Add();
    Elem5ec* p = (Elem5ec*)((char*)arr.data + idx * 0x30);
    new (p) Elem5ec(a, b);
    return idx;
}
}   // namespace f3m_005ec000

// @f3 0x005ff110 (community match, verified in this file)
namespace f3m_005ff110 {
class MemoryManager { public: void Deallocate(void* p); };
extern MemoryManager g_memoryManager;

class PathingLOSGridCell;

template <class T, unsigned int Growth> class BSSimpleArray;

template <> class BSSimpleArray<PathingLOSGridCell*, 1024>
{
public:
    virtual ~BSSimpleArray()
    {
        if (m_pBuffer)
        {
            BSSimpleArray* pSelf = this;
            pSelf->Deallocate(m_pBuffer);
            m_pBuffer = 0;
            m_uiCapacity = 0;
            m_uiSize = 0;
        }
    }
    PathingLOSGridCell*& GetAt(int index) { return m_pBuffer[index]; }
    unsigned int GetSize() { return m_uiSize; }
    virtual PathingLOSGridCell** Allocate(unsigned int count);
    virtual void Deallocate(void* p);
    virtual void Reallocate(unsigned int count);
    PathingLOSGridCell** m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    unsigned int m_uiExtra;
};

template <> class BSSimpleArray<char, 1024>
{
public:
    virtual ~BSSimpleArray()
    {
        if (m_pBuffer)
        {
            BSSimpleArray* pSelf = this;
            pSelf->Deallocate(m_pBuffer);
            m_pBuffer = 0;
            m_uiCapacity = 0;
            m_uiSize = 0;
        }
    }
    virtual char* Allocate(unsigned int count);
    virtual void Deallocate(void* p);
    virtual void Reallocate(unsigned int count);
    char* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    unsigned int m_uiExtra;
};

class PathingLOSGridCell
{
public:
    char unk00;
    BSSimpleArray<char, 1024> m_chars;
    int unk14;
    int unk18;
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};

class CellOwner
{
public:
    BSSimpleArray<PathingLOSGridCell*, 1024> m_cells;
    ~CellOwner();
};

// pdb: PathingLOSGrid::~PathingLOSGrid | PathingLOSGridMap.obj | fnv360_0822_retail, call_seq, medium
CellOwner::~CellOwner()
{
    for (unsigned int i = 0; i < m_cells.GetSize(); i++)
    {
        PathingLOSGridCell* pCell = m_cells.GetAt(i);
        if (pCell)
            delete pCell;
    }
}
}   // namespace f3m_005ff110

// @f3 0x005fbea0 (community match, verified in this file)
extern float DAT_00e02188;
namespace f3m_005fbea0 {
namespace f3m_005fbea0 {
struct Point {
    float x, y, z;
    Point() {}
    Point(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Point operator-(const Point& rhs) const { return Point(x - rhs.x, y - rhs.y, z - rhs.z); }
    float Squared() const { return x * x + y * y + z * z; }
    float Dot(const Point& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
};
struct Record {
    Point start, end;
    float radius, strength;
    int kind;
    float FUN_005fbea0(Point* point) const;
};
// pdb: PathingAvoidNode::GetCostForPoint | PathingAvoidNode.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arPoint
float Record::FUN_005fbea0(Point* point) const
{
    float radiusSquared = radius * radius;
    float distance = DAT_00e02188;
    switch (kind) {
    case 0:
    case 2: {
        Point offset = start - *point;
        distance = offset.Squared();
        break;
    }
    case 1: {
        Point direction = end - start;
        Point offset = *point - start;
        float length = direction.Squared();
        float projection = direction.Dot(offset);
        if (projection < 0 || length < projection)
            distance = DAT_00e02188;
        else
            distance = offset.Squared() - projection * projection / length;
        break;
    }
    }
    if (distance < radiusSquared)
        return (1 - distance / radiusSquared) * strength;
    return 0;
}
}
}   // namespace f3m_005fbea0
