// src/f3staging/f3blk_005e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005f69c0 (community match, verified in this file)
#include <math.h>

class PointB9 {
public:
    float x, y, z;
    PointB9() {}
    PointB9(float a, float b, float c) : x(a), y(b), z(c) {}
    PointB9 operator-(const PointB9& b) const {
        return PointB9(x-b.x, y-b.y, z-b.z);
    }
    float SquaredLength() const {
        return y*y + x*x + z*z;
    }
    float InlineLength() const {
        float result = SquaredLength();
        result = (float)sqrt(result);
        return result;
    }
    float Length() const;
};
struct Point2 {
    float x, y;
    Point2(const PointB9& p) : x(p.x), y(p.y) {}
};

struct MeshRefBase {
    virtual void Slot0();
    virtual void Destroy();
    volatile long refs;
    void Release() { if (!InterlockedDecrement(&refs)) Destroy(); }
};
struct FormBase {
    virtual ~FormBase();
    unsigned unk04, unk08, formID, unk10, unk14;
};
struct ChildCell {
    virtual void* GetCell();
};
class FUN_00bb3210_cls : public FormBase, public ChildCell, public MeshRefBase {
public:
    void* FUN_00bb3210();
    void FUN_005b8960(unsigned short triangle, int edge, PointB9& first, PointB9& second);
};
class NavMeshPtr {
public:
    FUN_00bb3210_cls* object;
    NavMeshPtr() : object(0) {}
    ~NavMeshPtr() { if (object) object->Release(); }
    FUN_00bb3210_cls* operator->() const { return object; }
};
struct PathingMeshInfo {
    unsigned unk00,unk04,flags,unk0c,unk10,unk14,unk18,unk1c;
    unsigned unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned unk40,unk44,unk48,unk4c,unk50;
    FUN_00bb3210_cls* mesh;

    bool IsDisabled() const { return (flags >> 4) & 1; }
};
struct PathingMeshInfoArray;
class PathingLocation {
public:
    void* unk00;
    PointB9 position;
    PathingMeshInfo* navMeshInfo;
    PathingMeshInfoArray* navMeshes;
    void* cell;
    void* worldSpace;
    unsigned cellKey;
    unsigned short unk24;
    unsigned char unk26;
    bool FUN_005fcc10();
    bool FUN_005fc8f0(NavMeshPtr*, unsigned short*);
    PointB9 GetPosition() const { return position; }
};

class FUN_00cbadb0_Obj {
public:
    virtual ~FUN_00cbadb0_Obj() { Clear(); }
    void Clear() {
        if (pBuffer) {
            ReleaseItems(pBuffer, iSize);
            Free(pBuffer);
            pBuffer = 0;
            capacity = 0;
            iSize = 0;
        }
    }
    virtual void* Allocate(unsigned);
    virtual void Free(void*);
    NavMeshPtr* pBuffer;
    unsigned iSize, capacity;
    FUN_00cbadb0_Obj() : pBuffer(0), iSize(0), capacity(0) {}
    void ReleaseItems(void*, unsigned);
    unsigned GetSize() const { return iSize; }
    NavMeshPtr& GetAt(int i) { return pBuffer[i]; }
};
template <> class BSSimpleArray<const NavMeshInfo*,1024> {
    typedef const NavMeshInfo* T;
public:
    virtual ~BSSimpleArray() { Clear(); }
    void Clear() {
        if (pBuffer) {
            Free(pBuffer);
            pBuffer = 0;
            capacity = 0;
            iSize = 0;
        }
    }
    virtual T* Allocate(unsigned);
    virtual void Free(void*);
    virtual void MoveStorage(unsigned, unsigned);
    void FUN_00cb9ce0(unsigned newCapacity, unsigned keep);
    T* pBuffer;
    unsigned iSize, capacity;
    BSSimpleArray() : pBuffer(0), iSize(0), capacity(0) {}
    unsigned Add(const T& value) {
        if (iSize == capacity) {
            if (capacity == 0) {
                pBuffer = Allocate(4);
                capacity = 4;
            } else {
                unsigned count = capacity > 1024 ? capacity + 1024 : capacity + capacity;
                FUN_00cb9ce0(count, iSize);
                capacity = count;
            }
        }
        ++iSize;
        pBuffer[iSize-1] = value;
        return iSize-1;
    }
};

struct NavMeshSearchNode {
    FUN_00bb3210_cls* mesh;
    unsigned short triangle;
    unsigned short unk06;
    PointB9 position;
    NavMeshSearchNode(FUN_00bb3210_cls* m, unsigned short t) : mesh(m), triangle(t) {}
    PointB9 GetPosition() const { return PointB9(position.x,position.y,position.z); }
    void SetPosition(const PointB9& p) { position.x=p.x; position.y=p.y; position.z=p.z; }
};
struct NavMeshSearchLink {
    FUN_00bb3210_cls* mesh;
    unsigned short triangle;
    unsigned short unk06;
    int edge;
};
template <> class BSSimpleArray<NavMeshSearchLink,1024> {
public:
    virtual ~BSSimpleArray() { Clear(); }
    void Clear() {
        if (pBuffer) { Free(pBuffer); pBuffer=0; capacity=0; iSize=0; }
    }
    virtual NavMeshSearchLink* Allocate(unsigned);
    virtual void Free(void*);
    virtual void MoveStorage(unsigned, unsigned);
    NavMeshSearchLink* pBuffer;
    unsigned iSize, capacity;
    BSSimpleArray() : pBuffer(0), iSize(0), capacity(0) {}
};
struct FUN_00aa54a0_s;
class MemMgr5 {
public:
    FUN_00aa54a0_s* GetCtx();
};
extern MemMgr5 DAT_01090a78;

template <class T, unsigned Growth> class BSScrapArray;
template <> class BSScrapArray<NavMeshSearchNode,1024> {
public:
    void* unk00;
    NavMeshSearchNode* pBuffer;
    unsigned iSize, capacity;
    FUN_00aa54a0_s* context;
    BSScrapArray() { FUN_005d04d0(); }
    ~BSScrapArray() { FUN_005d0260(); }
    unsigned GetCapacity() { return capacity; }
    unsigned GetSize() const { return iSize; }
    unsigned InteriorCount() const { const unsigned& count=iSize; const unsigned last=count-1; return last-1; }
    NavMeshSearchNode& GetAt(int i) { return pBuffer[i]; }
    void FUN_005d04d0();
    void FUN_005d0260();
    void FUN_007ad4b0(unsigned, unsigned);
    void FUN_007acb30(NavMeshSearchNode*, NavMeshSearchNode*, unsigned);
    void Clear() { if (pBuffer) iSize = 0; }
    __forceinline void Reserve(unsigned n) {
        if (GetCapacity() < n) {
            if (iSize > n) iSize = n;
            FUN_007ad4b0(n, iSize);
            capacity = n;
        }
    }
    void Erase(unsigned start, unsigned count) {
        if (count >= iSize) Clear();
        else {
            FUN_007acb30(pBuffer+start, pBuffer+start+count, iSize-count-start);
            iSize -= count;
        }
    }
};
template <> class BSScrapArray<NavMeshSearchLink,1024> : public BSSimpleArray<NavMeshSearchLink,1024> {
public:
    FUN_00aa54a0_s* context;
    __forceinline BSScrapArray(unsigned initial) {
        context = DAT_01090a78.GetCtx();
        pBuffer = 0;
        iSize = 0;
        capacity = 0;
        Reserve(initial);
    }
    __declspec(noinline) virtual ~BSScrapArray() { Clear(); }
    virtual NavMeshSearchLink* Allocate(unsigned);
    virtual void Free(void*);
    virtual void MoveStorage(unsigned, unsigned);
    unsigned GetSize() const { return iSize; }
    NavMeshSearchLink& GetAt(int i) { return pBuffer[i]; }
    void FUN_0079e680(NavMeshSearchLink*, NavMeshSearchLink*, unsigned);
    __forceinline void Reserve(unsigned n) {
        if (!capacity) { pBuffer = Allocate(n); capacity=n; }
        else if (capacity<n) {
            if (iSize>n) iSize=n;
            MoveStorage(n,iSize); capacity=n;
        }
    }
    void Erase(unsigned start, unsigned count) {
        if (count >= iSize) { if (pBuffer) iSize=0; }
        else {
            // Keep the remainder beyond the removed span as a separate value.
            unsigned rem = iSize-count;
            FUN_0079e680(pBuffer+start,pBuffer+start+count,rem-start);
            iSize-=count;
        }
    }
};

class Holder {
public:
    void* unk00;
    unsigned unk04, unk08;
    PathingLocation start;
    PathingLocation end;
    unsigned unk5c, unk60, unk64;
    float unk68, unk6c, unk70, unk74, unk78;
    unsigned unk7c, unk80, unk84;
    float unk88, unk8c, unk90;
    unsigned unk94;
    unsigned char unk98,unk99,unk9a,unk9b,unk9c,unk9d,unk9e,unk9f;
    unsigned char unka0,unka1,unka2,unka3,unka4;
    unsigned unka8;
    unsigned char unkac;
    Holder() { FUN_00600eb0(); }
    ~Holder() { FUN_00bc49a0(); }
    void FUN_00600eb0();
    void FUN_00bc49a0();
    void FUN_005f1490(void*);
};
struct SearchMemory {
    void* unk00;
    void* unk04;
    unsigned unk08, unk0c;
};
struct SearchRecord;
struct SearchQueue {
    float threshold;
    SearchRecord* buckets[20];
    unsigned unk54, unk58, unk5c;
    bool unk60;
};
struct SearchList {
    void* unk00;
    unsigned unk04, unk08, unk0c, unk10, unk14;
};
class NavSearch {
public:
    void* unk00;
    SearchMemory memory;
    SearchRecord* hashBuckets[2039];
    unsigned entryCount;
    SearchQueue queue;
    unsigned unk2058;
    unsigned unk205c, unk2060, unk2064, unk2068, unk206c;
    unsigned unk2070, unk2074, unk2078, unk207c, unk2080;
    unsigned unk2084, unk2088;
    SearchList list;
    NavSearch() { FUN_005cc480(); }
    ~NavSearch() { FUN_005cc4f0(); }
    void FUN_005cc480();
    void FUN_005cc4f0();
    bool FUN_005cd600(Holder*, NavMeshSearchNode&, NavMeshSearchNode&,
        BSScrapArray<NavMeshSearchNode,1024>*, BSScrapArray<NavMeshSearchLink,1024>*,
        BSSimpleArray<const NavMeshInfo*,1024>*);
};

bool FUN_005f64f0(FUN_00cbadb0_Obj*);
bool FUN_005ddda0(const PointB9*,const PointB9*,const PointB9*,const PointB9*,PointB9*);
bool FUN_005dd4c0(const Point2&,const Point2&,const Point2&,const Point2&);
extern unsigned char DAT_0107492c;

// Apply the same funnel reduction to the nodes and their links.
__forceinline void EraseFunnelSpan(BSScrapArray<NavMeshSearchNode,1024>* current, BSScrapArray<NavMeshSearchLink,1024>& links, unsigned i, unsigned n) {
    unsigned s = n - i - 2;
    current->Erase(1 + i, s);
    links.Erase(i, s);
}

// pdb: Pathing::ComputeApproximatePathingDistance | Pathfind.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aStartLocation, aGoalLocation, apAvoidNodeArray, apReturnDistance, apReturnNodes
bool __cdecl FUN_005f69c0(PathingLocation* a, PathingLocation* b, void* options,
                         float* distance, BSScrapArray<NavMeshSearchNode,1024>* out) {
    FUN_00cbadb0_Obj cnt;
    FUN_005f64f0(&cnt);
    BSSimpleArray<const NavMeshInfo*,1024> infos;
    for (unsigned i=0; i<cnt.GetSize(); ++i) {
        const NavMeshInfo* a;
        a = (const NavMeshInfo*)cnt.GetAt(i)->FUN_00bb3210();
        infos.Add(a);
    }
    if (!a->FUN_005fcc10()) {
        if (distance) { PointB9 sp=a->GetPosition(); PointB9 ep=b->GetPosition(); const PointB9 d=ep-sp; *distance=d.InlineLength(); }
        if (!b->FUN_005fcc10()) return true;
        return false;
    }
    if (!b->FUN_005fcc10()) {
        if (distance) { PointB9 sp=a->GetPosition(); PointB9 ep=b->GetPosition(); sp=ep-sp; *distance=sp.InlineLength(); }
        return false;
    }
    NavMeshPtr p;
    unsigned short y;
    y = 0xffff;
    if (!a->FUN_005fc8f0(&p,&y)) {
        if (distance) { const PointB9 sp=b->GetPosition()-a->GetPosition(); float square=sp.y*sp.y + sp.x*sp.x + sp.z*sp.z; *distance=static_cast<float>(sqrt(square)); }
        return false;
    }
    NavMeshSearchNode start(p.object,(unsigned short)y);
    NavMeshPtr count;
    unsigned short j=0xffff;
    if (!b->FUN_005fc8f0(&count,&j)) {
        if (distance) { const PointB9 d=b->GetPosition()-a->GetPosition(); *distance=d.InlineLength(); }
        return false;
    }
    NavMeshSearchNode end(count.object,(unsigned short)j);
    NavSearch z;
    BSScrapArray<NavMeshSearchNode,1024> temporary;
    BSScrapArray<NavMeshSearchNode,1024>* current;
    if (out) current=out;
    else current=&temporary;
    current->Clear();
    current->Reserve(32);
    BSScrapArray<NavMeshSearchLink,1024> links(32);
    Holder firstNode;
    firstNode.FUN_005f1490(options);
    if (!z.FUN_005cd600(&firstNode,start,end,current,&links,&infos)) {
        if (distance) *distance = (b->GetPosition()-a->GetPosition()).Length();
        return false;
    }
    NavMeshSearchNode& startMesh=current->GetAt(0);
    startMesh.SetPosition(a->GetPosition());
    if (current->GetSize()>1) {
        NavMeshSearchNode& pObj=current->GetAt(current->GetSize()-1);
        pObj.SetPosition(b->GetPosition());
    }
    if (current->GetSize()>2 && (distance || out)) {
        unsigned i=0;
        if (i<current->GetSize()-2) {
          do {
            PointB9 meshes=current->GetAt(i).GetPosition();
            PointB9 path,pForm;
            links.GetAt(i).mesh->FUN_005b8960(links.GetAt(i).triangle,links.GetAt(i).edge,path,pForm);
            unsigned linkIndex;
            linkIndex = i + 1;
            unsigned n;
            n = i + 2;
            for (;n<current->GetSize();++n,++linkIndex) {
                PointB9 lastNode;
                lastNode = current->GetAt(n).GetPosition();
                PointB9 left,right,intersection;
                { NavMeshSearchLink& lk = links.GetAt(linkIndex); lk.mesh->FUN_005b8960(lk.triangle,lk.edge,left,right); }
                if (FUN_005ddda0(&left,&right,&meshes,&path,&intersection)) path=intersection;
                else path=left;
                if (FUN_005ddda0(&left,&right,&meshes,&pForm,&intersection)) pForm=intersection;
                else pForm=right;
                if (!FUN_005dd4c0(Point2(meshes),Point2(lastNode),Point2(path),Point2(pForm))) break;
            }
            if (n>i+2) {
                EraseFunnelSpan(current, links, i, n);
            }
          } while (++i<current->InteriorCount());
        }
        for (unsigned i=1;i<current->GetSize()-1;++i) {
            NavMeshSearchNode* previous=&current->GetAt(i);
            PointB9 meshes;
            meshes = current->GetAt(i-1).GetPosition();
            PointB9 left,right;
            links.GetAt(i-1).mesh->FUN_005b8960(links.GetAt(i-1).triangle,links.GetAt(i-1).edge,left,right);
            PointB9 endMesh;
            endMesh = meshes-left;
            PointB9 v;
            v = meshes-right;
            if (endMesh.SquaredLength()<v.SquaredLength()) previous->SetPosition(left);
            else previous->SetPosition(right);
        }
    }
    if (distance) {
        *distance=0;
        if (current->GetSize()>1) {
            PointB9 previous=current->GetAt(0).GetPosition();
            for (unsigned i=1;i<current->GetSize();++i) {
                PointB9 nodePoint=current->GetAt(i).GetPosition();
                float dy, dx, dz;
                dx = nodePoint.x - previous.x;
                dy = nodePoint.y - previous.y;
                dz = nodePoint.z - previous.z;
                const float square = dy * dy + dx * dx + dz * dz;
                *distance += static_cast<float>(sqrt(square));
                previous=nodePoint;
            }
        }
    }
    DAT_0107492c=0;
    return true;
}
