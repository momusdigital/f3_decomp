#include "f3_common.h"
// src/staging/blk_00d20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void* __cdecl fopen(const char*, const char*);

struct FUN_00d2be30
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void SetFile(const char* a, const char* b);
};

// @fnv 0x00d2be30
// pdb: hkStdioStreamWriter::open | hkStdioStreamWriter.obj | fnv360_0822_retail, caller_sim, low
// pdb params: nameIn, mode
void FUN_00d2be30::SetFile(const char* acPath, const char* acMode)
{
    m_8 = fopen(acPath, acMode);
}

extern "C" void __stdcall FUN_00d2f980(int);
extern int DAT_010ce930;

struct FUN_00d2f220_class
{
    int* p;
    int __thiscall InitializeWithGlobal(int a);
};

// @fnv 0x00d2f220
// pdb: NiTriBasedGeom::NiTriBasedGeom | NiTriBasedGeom.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: pkModelData
int __thiscall FUN_00d2f220_class::InitializeWithGlobal(int aiValue)
{
    FUN_00d2f980(aiValue);
    p = &DAT_010ce930;
    return (int)this;
}

extern "C" void __cdecl FUN_00d36b70();
extern "C" void __cdecl FUN_00d34790();
extern "C" void __cdecl QueryClosestPoints();
extern "C" void __cdecl FUN_00d34810();

// Fills the four function pointers at p[0..3] and sets the bytes at offsets 0x10 and 0x11 to 0 and 1.
// @fnv 0x00d36bb0
// pdb: hkpListAgent::initAgentFuncInverse | hkpListAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: af
void __cdecl FUN_00d36bb0(void** p)
{
    p[0] = (void*)&FUN_00d36b70;
    p[1] = (void*)&FUN_00d34790;
    p[2] = (void*)&QueryClosestPoints;
    p[3] = (void*)&FUN_00d34810;
    ((char*)p)[0x10] = 0;
    ((char*)p)[0x11] = 1;
}

extern "C" void __cdecl FUN_00d36be0();
extern "C" void __cdecl FUN_00d43dc0();
extern "C" void __cdecl hkpShapeCollectionAgent_staticGetClosestPoints();
extern "C" void __cdecl FUN_00d43b90();

// Writes four function pointers into the object at offsets 0, 4, 8 and 12, then sets the bytes at offsets 16 and 17 to 1.
// @fnv 0x00d36c30
// pdb: hkpListAgent::initAgentFunc | hkpListAgent.obj | fnv360_0822_retail, objrun + bridge(hash|objrun) + skyrim(hash), high
void __cdecl hkpListAgent_initAgentFunc(void* apObject)
{
    *(void**)apObject = &FUN_00d36be0;
    *(void**)((char*)apObject + 4) = &FUN_00d43dc0;
    *(void**)((char*)apObject + 8) = &hkpShapeCollectionAgent_staticGetClosestPoints;
    *(void**)((char*)apObject + 12) = &FUN_00d43b90;
    *(unsigned char*)((char*)apObject + 16) = 1;
    *(unsigned char*)((char*)apObject + 17) = 1;
}

void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();

// Fills the first four pointer slots of p with function addresses and clears the two bytes at offsets 0x10 and 0x11.
// @fnv 0x00d3dbe0
// pdb: hkpSphereTriangleAgent::initAgentFunc | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: af
void __cdecl FUN_00d3dbe0(void* apObject)
{
    ((void**)apObject)[0] = (void*)&CreateRetObj;
    ((void**)apObject)[1] = (void*)&FUN_00d3d3e0;
    ((void**)apObject)[2] = (void*)&FUN_00d3d8c0;
    ((void**)apObject)[3] = (void*)&FUN_00daf8e0;
    ((unsigned char*)apObject)[0x10] = 0;
    ((unsigned char*)apObject)[0x11] = 0;
}

void __cdecl CreateTargetAgent(void);
void __cdecl QueryD3DCollector(void);
void __cdecl FUN_00d3e110(void);
void __cdecl FUN_00d3ac80(void);

// Fills the first four pointer slots of p with four function pointers and sets the bytes at offsets 0x10 and 0x11 to 1 and 0.
// @fnv 0x00d3dc10
// pdb: hkpSphereTriangleAgent::initAgentFuncInverse | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: af
void FUN_00d3dc10(void* apObject)
{
    ((void**)apObject)[0] = (void*)CreateTargetAgent;
    ((void**)apObject)[1] = (void*)QueryD3DCollector;
    ((void**)apObject)[2] = (void*)FUN_00d3e110;
    ((void**)apObject)[3] = (void*)FUN_00d3ac80;
    ((unsigned char*)apObject)[0x10] = 1;
    ((unsigned char*)apObject)[0x11] = 0;
}

namespace fnv_00d3fce0 {
extern "C" void __cdecl FUN_00d3f620();
extern "C" void __cdecl FUN_00d3f6a0();
extern "C" void __cdecl FUN_00d3fb20();
extern "C" void __cdecl FUN_00daf8e0();

// Stores four function pointers (FUN_00d3f620, FUN_00d3f6a0, FUN_00d3fb20, FUN_00daf8e0) into the first four slots of the object at p.
// @fnv 0x00d3fce0
void __cdecl FUN_00d3fce0(void* apObject)
{
    void** a = (void**)apObject;
    a[0] = (void*)FUN_00d3f620;
    a[1] = (void*)FUN_00d3f6a0;
    a[2] = (void*)FUN_00d3fb20;
    a[3] = (void*)FUN_00daf8e0;
}
}  // namespace fnv_00d3fce0

struct FUN_00db0920 {
    void Init();
};

// @fnv 0x00d3fdf0
// pdb: hkBoxBoxAgent3::create | hkpBoxBoxAgent3.obj | fnv360_0822_retail, caller_sim, high
// pdb params: input, entry, agentData
// pdb: hkBoxBoxAgent3::create | hkpBoxBoxAgent3.obj | fnv360_0822_retail, caller_sim, high (was: InitAndGetOffset)
void* __cdecl hkBoxBoxAgent3_create(void* apUnused1, void* apUnused2, void* apObject)
{
    if (apObject)
        ((FUN_00db0920*)apObject)->Init();
    return (char*)apObject + 0x40;
}

struct CollisionAgentFunctionTable {
    void* a;
    void* b;
    void* c;
    void* d;
    char e;
    char f;
};
struct Agent {
    void FUN_00cfbbe0(CollisionAgentFunctionTable*, int, int);
};
void __cdecl FUN_00d2e970();
void __cdecl FUN_00d2e9b0();
void __cdecl FUN_00d2daf0();
void __cdecl hkpBvTreeAgent_staticGetPenetrations();
void __cdecl FUN_00d31110();
void __cdecl FUN_00d2f0d0();
void __cdecl CreateAgentForBodyPair();
// @f3 0x009ba720 (community match, verified in this file)
void __cdecl FUN_009ba5e0();
void __cdecl FUN_009b59a0();
void __cdecl FUN_009b70d0();
void __cdecl FUN_009b7110();
void __cdecl FUN_009b8200();
void __cdecl FUN_009ba3c0();
void __cdecl FUN_009ba1b0();
void __cdecl FUN_009b9ff0();
void __cdecl FUN_009ba620();

// pdb: hkpBvTreeAgent::registerAgent | hkpBvTreeAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void __cdecl FUN_00d2dc70(Agent* pAgent)
{
    CollisionAgentFunctionTable f;
    f.a = (void*)&FUN_009ba5e0;
    f.b = (void*)&FUN_009b59a0;
    f.c = (void*)&FUN_009b70d0;
    f.d = (void*)&FUN_009b7110;
    f.e = 1;
    f.f = 1;
    pAgent->FUN_00cfbbe0(&f, 9, -1);
    f.a = (void*)&FUN_009b8200;
    f.b = (void*)&FUN_009ba3c0;
    f.c = (void*)&FUN_009ba1b0;
    f.d = (void*)&FUN_009b9ff0;
    f.e = 0;
    f.f = 1;
    pAgent->FUN_00cfbbe0(&f, -1, 9);
    f.a = (void*)&FUN_009ba620;
    f.b = (void*)&FUN_009ba3c0;
    f.c = (void*)&FUN_009ba1b0;
    f.d = (void*)&FUN_009b9ff0;
    f.e = 0;
    f.f = 1;
    pAgent->FUN_00cfbbe0(&f, 9, 9);
}


// @f3 0x009a91b0 (community match, verified in this file)
// pdb: hkpWorldConstraintUtil::updateFatherOfMovedAtom | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: instance, oldAtom, updatedAtom, updatedSizeOfAtom
// pdb: hkpWorldConstraintUtil::updateFatherOfMovedAtom | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_seq, high (was: ReplaceEntry)
void hkpWorldConstraintUtil_updateFatherOfMovedAtom(int pList, int pOldEntry, int pNewEntry, unsigned short usValue)
{
    int iVar1 = *(int*)(pList + 0x10);
    int pCached = *(int*)(pList + 0x28);
    if (iVar1 == 0)
    {
        if (pCached != 0)
        {
            *(int*)(pCached + 0xc) = pNewEntry;
            *(unsigned short*)(pCached + 0x10) = usValue;
        }
        return;
    }
    if (iVar1 == pOldEntry)
    {
        *(int*)(pList + 0x10) = pNewEntry;
        if (pCached != 0)
        {
            *(int*)(pCached + 0xc) = pNewEntry;
            *(unsigned short*)(pCached + 0x10) = usValue;
        }
        return;
    }
    int pCur = *(int*)(iVar1 + 0x14);
    while (pCur != pOldEntry)
    {
        iVar1 = pCur;
        pCur = *(int*)(pCur + 0x14);
    }
    *(int*)(iVar1 + 0x14) = pNewEntry;
    *(unsigned short*)(iVar1 + 0x12) = usValue;
}


struct FUN_00d27f50_Obj {
    void __thiscall Insert(int a, int b, int c);
    void __thiscall FUN_00d27f50(int param_1, int param_2);
};

// @fnv 0x00d27f50
void __thiscall FUN_00d27f50_Obj::FUN_00d27f50(int aFirst, int aSecond) {
    this->Insert(aFirst, aSecond, 1);
}

struct FUN_00d27f70 {
    int** m_ppIndices;
    int m_iIndexCount;

    FUN_00d27f70(int** indices, int numIndices);
};

// Stores the index array and its count, then fills the array with -1.
// @fnv 0x00d27f70
// pdb: hkUnionFind::hkUnionFind | hkUnionFind.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: parents, numnode
FUN_00d27f70::FUN_00d27f70(int** indices, int numIndices)
{
    m_ppIndices = indices;
    m_iIndexCount = numIndices;
    for (int i = 0; i < numIndices; i++)
        (*m_ppIndices)[i] = -1;
}

struct D28030FixedArray {
    int* m_data;
    int m_iElementCount;

    int& operator[](int i) { return m_data[i]; }
};

struct D28030UnionFind {
    D28030FixedArray& m_pParentArray;

    __forceinline int _findRootOfNode(int i)
    {
        int root = i;
        while (m_pParentArray[root] >= 0)
            root = m_pParentArray[root];
        while (m_pParentArray[i] >= 0) {
            int j = m_pParentArray[i];
            m_pParentArray[i] = root;
            i = j;
        }
        return i;
    }

    void Union(int i, int j);
};

// @f3 0x009ad2b0 (community match, verified in this file)
// pdb: hkUnionFind::addEdge | hkUnionFind.obj | tesv_win, callee_sim, low
void D28030UnionFind::Union(int aiNodeA, int aiNodeB)
{
    if (aiNodeA > aiNodeB) {
        int iTemp = aiNodeA;
        aiNodeA = aiNodeB;
        aiNodeB = iTemp;
    }

    int iRootA = _findRootOfNode(aiNodeA);
    int iRootB = _findRootOfNode(aiNodeB);

    if (iRootA != iRootB) {
        int iSizeA = m_pParentArray[iRootA];
        if (iRootA < iRootB) {
            m_pParentArray[iRootA] += m_pParentArray[iRootB];
            m_pParentArray[iRootB] = iRootA;
        } else {
            m_pParentArray[iRootB] += iSizeA;
            m_pParentArray[iRootA] = iRootB;
        }
    }
}


struct LinkedIndexArray { int** entries; int count; void FUN_00d280e0(); };
// For each non-negative entry, follows the chain of indices in entries until a negative value is reached, then advances to the next entry.
// @fnv 0x00d280e0
// pdb: hkUnionFind::findRootOfNode | hkUnionFind.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkUnionFind::collapseTree)
// pdb params: i
void LinkedIndexArray::FUN_00d280e0(){
int* values=*entries; int* current=*entries; int* end=current+count;while(current!=end){if(*current>=0){while(values[*current]>=0){*current=values[*current];values=*entries;}}++current;}
}

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct IndexBuffer { int* data; int size; unsigned capacityFlags; };
struct IndexStorage { int* data; };
struct AllocationManager { int unk00; int unk04; int unk08; int unk0C; void* allocator; };
AllocationManager* __cdecl FUN_00c85750();
struct IndexRemapper { IndexStorage* entries; int length; void FUN_00d280e0(); void RemapIndices(IndexBuffer*); };
// @f3 0x009ad3a0 (community match, verified in this file)
struct IndexRemapperF3 { void FUN_009ad360(); };
void __cdecl FUN_00901f10(IndexBuffer* apArray, int aiElementSize);
// pdb: hkUnionFind::assignGroups | hkUnionFind.obj | tesv_win, call_gap_sim, low
void IndexRemapper::RemapIndices(IndexBuffer* output) {
 ((IndexRemapperF3*)this)->FUN_009ad360(); int nextIndex=0;
 for(int i=0;i<length;++i) {
  int* values=entries->data; int value=values[i];
  if(value<0) {
   value=-value;
   if(output->size == (output->capacityFlags & 0x3fffffffU)) FUN_00901f10(output,4);
   output->data[output->size] = value;
   ++output->size; entries->data[i]=nextIndex++;
  } else { values[i]=values[value]; }
 }
}


struct hkMemAllocStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& sizeInOut);
    virtual void ReturnMemory(void* p, int size);

    int* bufAllocInts(int& n)
    {
        int s = n * 4;
        void* p = AllocateBufferWithSize(s);
        n = s / 4;
        return (int*)p;
    }
};

struct hkMemCtxStub
{
    int unk00;
    int unk04;
    int unk08;
    hkMemAllocStub* alloc;
    void* mem;

    hkMemAllocStub& temp() { return *alloc; }
    void* heap() { return mem; }
};

void ArrayReserveImpl(void* mem, void* arr, int numElem, int elemSize);

struct IntArrayStub
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void reserveWith(void* mem, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            ArrayReserveImpl(mem, this, n < cap2 ? cap2 : n, 4);
        }
    }
    void setSizeWith(void* mem, int n)
    {
        reserveWith(mem, n);
        m_iElementCount = n;
    }
};

namespace fnv_00d2f240 {
struct D2F240Allocator {
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D2F240MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2F240Allocator* m_pStreamAllocator;

    D2F240Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D2F240MemoryRouter& __cdecl FUN_00c85750();

class D2F240Agent {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    D2F240Agent(void* pvMgr) throw();
    virtual ~D2F240Agent();

    static void* operator new(unsigned int uiSize) {
        void* p = FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        static_cast<D2F240Agent*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

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
};

class D2F240SymmetricAgent : public D2F240Agent {
public:
    D2F240SymmetricAgent(void* pvMgr) : D2F240Agent(pvMgr) {}
    virtual ~D2F240SymmetricAgent();
};

}  // namespace fnv_00d2f240

typedef void (__cdecl *D2F2C0Func)();

struct D2F2C0AgentFuncs {
    D2F2C0Func m_pCreateFunc;
    D2F2C0Func m_pQueryPenetrationsFunc;
    D2F2C0Func m_getClosestPointsFunc;
    D2F2C0Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

class D2F2C0Dispatcher {
public:
    void registerCollisionAgent(D2F2C0AgentFuncs& f, int typeA, int typeB);
};

void __cdecl FUN_00d2e970();
void __cdecl FUN_00d2e9b0();
void __cdecl FUN_00d2daf0();
void __cdecl hkpBvTreeAgent_staticGetPenetrations();
void __cdecl FUN_00d31110();
void __cdecl FUN_00d2f0d0();
void __cdecl CreateAgentForBodyPair();

// Registers three collision agent function tables with the dispatcher for type pairs (10,-1), (-1,10) and (10,10).
// @f3 0x009b7bc0 (community match, verified in this file)
void __cdecl FUN_009ba5e0();
void __cdecl FUN_009b59a0();
void __cdecl FUN_009b70d0();
void __cdecl FUN_009b59e0();
void __cdecl FUN_009b8200();
void __cdecl FUN_009ba3c0();
void __cdecl FUN_009ba1b0();
void __cdecl hkpMoppAgent_staticLinearCast();
void __cdecl hkpMoppAgent_createBvBvAgent();

// pdb: hkpMoppAgent::registerAgent | hkpMoppAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void __cdecl FUN_00d2f2c0(D2F2C0Dispatcher* dispatcher)
{
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = FUN_009ba5e0;
        f.m_pQueryPenetrationsFunc = FUN_009b59a0;
        f.m_getClosestPointsFunc = FUN_009b70d0;
        f.m_pLinearCastFunc = FUN_009b59e0;
        f.m_bIsFlipped = true;
        f.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(f, 11, -1);
    }
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = FUN_009b8200;
        f.m_pQueryPenetrationsFunc = FUN_009ba3c0;
        f.m_getClosestPointsFunc = FUN_009ba1b0;
        f.m_pLinearCastFunc = hkpMoppAgent_staticLinearCast;
        f.m_bIsFlipped = false;
        f.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(f, -1, 11);
    }
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = hkpMoppAgent_createBvBvAgent;
        f.m_pQueryPenetrationsFunc = FUN_009ba3c0;
        f.m_getClosestPointsFunc = FUN_009ba1b0;
        f.m_pLinearCastFunc = hkpMoppAgent_staticLinearCast;
        f.m_bIsFlipped = false;
        f.m_bIsPredictive = true;
        dispatcher->registerCollisionAgent(f, 11, 11);
    }
}


struct CallTarget_00d2f760 { int FUN_00d2f760(int, int, int, int); };
struct SearchObject {
    int FUN_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2f3d0
// pdb: hkpSymmetricAgentLinearCast<hkpMoppAgent>::updateShapeCollectionFilter | hkpMoppAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, constraintOwner
int SearchObject::FUN_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiResult = (unsigned int)((CallTarget_00d2f760*)this)->FUN_00d2f760((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)uiResult;
}

namespace fnv_00d2f430 {
struct FnvCpu_FUN_00d2f430_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d2f430_CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d2f430_CpuAllocator* allocator;
};
FnvCpu_FUN_00d2f430_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d2f430

struct FnvCpu_FUN_00d31730_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d31730_CpuObject {
    void FUN_00d315d0(void*, void*, unsigned int, FnvCpu_FUN_00d31730_CpuCallData*);
    void FUN_00d31730(void*, void*, unsigned int, unsigned int);
};
// Builds a call data struct from the arguments and DAT globals, then forwards it to FUN_00d315d0 with second and first swapped.
// @fnv 0x00d31730
// pdb: hkpSymmetricAgentLinearCast<hkpMoppAgent>::getClosestPoints | hkpMoppAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void FnvCpu_FUN_00d31730_CpuObject::FUN_00d31730(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d31730_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d315d0(second, first, third, &data);
}

namespace fnv_00d327e0 {
extern int DAT_0102e388;

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d327e0_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    void* m_pData;
    int m_10;
    int m_uiItemCount;

    FUN_00d327e0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00d327e0

extern "C" void __cdecl InitBlockPool(void* p);
extern int DAT_010ced34;

struct FUN_00d36b20_Class {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    FUN_00d36b20_Class* __thiscall FUN_00d36b20(int param1, int param2, int* param3, int param4);
};

// @fnv 0x00d36b20
// pdb: hkpListAgent::hkpListAgent | hkpListAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: bodyA, bodyB, input, contactMgr
FUN_00d36b20_Class* FUN_00d36b20_Class::FUN_00d36b20(int aiUnused1, int aiUnused2, int* piValue, int aiValue) {
    this->unk06 = 1;
    this->unk08 = aiValue;
    this->unk00 = &DAT_010ced34;

    int* data = &this->unk10;
    data[0] = 0;
    data[1] = 0;
    data[2] = 0x80000000;

    this->unk0C = *piValue;
    InitBlockPool(data);
    return this;
}

namespace fnv_00d36be0 {
// FUN_00d36be0 : cdecl factory. Allocates a 0x1c byte block through the global
// allocator holder, stamps the 16-bit size at +4, runs the out-of-line block
// initializer with the arguments in a2, a1, a3, a4 order, stores the vtable
// pointer and returns the block.

extern "C" char DAT_010ced70[];

struct FUN_00d36be0_cls
{
    void* unk00;
    unsigned short m_04;
    void __thiscall FUN_00d36b20(int a, int b, int c, int d);
};

struct Allocator
{
    virtual void* v0();
    virtual void* v1(unsigned int nSize);
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pAllocator;
};

extern "C" Holder* __cdecl FUN_00c85750();

// @fnv 0x00d36be0
void* __cdecl FUN_00d36be0(int a1, int a2, int a3, int a4)
{
    Holder* pHolder = FUN_00c85750();
    Allocator* pAlloc = pHolder->m_pAllocator;
    FUN_00d36be0_cls* pBlock = (FUN_00d36be0_cls*)pAlloc->v1(0x1c);
    pBlock->m_04 = 0x1c;
    pBlock->FUN_00d36b20(a2, a1, a3, a4);
    pBlock->unk00 = DAT_010ced70;
    return pBlock;
}
}  // namespace fnv_00d36be0

struct FUN_00d36cc0_Obj {
    void __thiscall hkpListAgent_updateShapeCollectionFilter(int a1, int a2, int a3, int a4);
    void __thiscall FUN_00d36cc0(int param_1, int param_2, int param_3, int param_4);
};

// @fnv 0x00d36cc0
// pdb: hkpSymmetricAgentLinearCast<class hkpListAgent>::updateShapeCollectionFilter | hkpListAgent.obj | tesv_win, caller_sim, low
void __thiscall FUN_00d36cc0_Obj::FUN_00d36cc0(int param_1, int param_2, int param_3, int param_4) {
    this->hkpListAgent_updateShapeCollectionFilter(param_2, param_1, param_3, param_4);
}

struct FnvCpu_FUN_00d36ce0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d36ce0_CpuObject {
    void FUN_00d36940(void*, void*, unsigned int, FnvCpu_FUN_00d36ce0_CpuCallData*);
    void FUN_00d36ce0(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data struct from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first and third to FUN_00d36940.
// @fnv 0x00d36ce0
// pdb: hkpSymmetricAgentLinearCast<hkpListAgent>::getClosestPoints | hkpListAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector
void FnvCpu_FUN_00d36ce0_CpuObject::FUN_00d36ce0(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d36ce0_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d36940(second, first, third, &data);
}

namespace fnv_00d36f50 {
struct FUN_00d36f50_Obj;

struct FUN_00d36f50_Obj
{
    void* unk00;
    unsigned short unk04;
    int unk08;
    int unk0C;
    void* unk10;
    int unk14;
    int unk18;

    FUN_00d36f50_Obj* __thiscall FUN_00d36f50(unsigned char flag);
};

extern int DAT_0102e388;
void* __cdecl FUN_00c85750();

}  // namespace fnv_00d36f50

extern float DAT_0104da48;

class D37B90Collector {
public:
    D37B90Collector(int iFilter) : m_fEarlyOutDistance(DAT_0104da48), m_iFilter(iFilter) {}
    virtual void AddCdPoint(const void* pkEvent);

    float m_fEarlyOutDistance;
    int m_iFilter;
};

class D37B90Agent {
public:
    void FUN_00d37010(void* pkA, void* pkB, void* pkInput, D37B90Collector* pkCollector);
    void FUN_00d37b90(void* pkA, void* pkB, void* pkInput, int iFilter);
};

// Constructs a D37B90Collector with iFilter and runs FUN_00d37010 with pkB, pkA, pkInput and the collector.
// @fnv 0x00d37b90
// pdb: hkpSymmetricAgentLinearCast<hkpMultiRayConvexAgent>::getClosestPoints | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void D37B90Agent::FUN_00d37b90(void* pkA, void* pkB, void* pkInput, int iFilter)
{
    D37B90Collector kCollector(iFilter);
    FUN_00d37010(pkB, pkA, pkInput, &kCollector);
}

namespace fnv_00d37da0 {
struct S_00d37da0_Allocator {
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00d37da0_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d37da0_Allocator* m_pStreamAllocator;
    S_00d37da0_Allocator& heap() { return *m_pStreamAllocator; }
};

S_00d37da0_Router* FUN_00c85750();

struct S_00d37da0_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d37da0_RefObj() { m_sReferenceCount = 1; }
    virtual ~S_00d37da0_RefObj() throw() {}
    void* operator new(unsigned int nbytes)
    {
        S_00d37da0_RefObj* b = static_cast<S_00d37da0_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*) {}
};

struct S_00d37da0_Agent : S_00d37da0_RefObj {
    void* m_pContactManager;
    S_00d37da0_Agent(void* mgr) : m_pContactManager(mgr) {}
    virtual void getPenetrations();
};

struct S_00d37da0_CdBody {
    char* m_pCollisionShape;
};

struct S_00d37da0_Plane {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

void FUN_00cd7160(const void* verts, S_00d37da0_Plane* out) throw();

struct S_00d37da0_TriAgent : S_00d37da0_Agent {
    S_00d37da0_Plane m_kTriangleNormal;
    unsigned short m_ids[8];
    virtual void getPenetrations();
    __forceinline S_00d37da0_TriAgent(const S_00d37da0_CdBody& bodyA, void* mgr) : S_00d37da0_Agent(mgr)
    {
        for (int i = 0; i < 8; i++)
            m_ids[i] = 0xffff;
        FUN_00cd7160(bodyA.m_pCollisionShape + 0x20, &m_kTriangleNormal);
    }
};

}  // namespace fnv_00d37da0

void __cdecl ReleaseHandles(int a1, int a2, int a3, int a4);

// @fnv 0x00d39130
// pdb: hkCapsuleTriangleAgent3::destroy | hkpCapsuleTriangleAgent3.obj | tesv_win, objrun, medium
void __cdecl FUN_00d39130(int a1, int a2, int a3, int a4, int a5)
{
    ReleaseHandles(a1, a2, a3, a4);
}

namespace fnv_00d398c0 {
extern "C" void* __cdecl FUN_00c85750();
extern "C" void __cdecl ComputeInverseLengths(const void*, void*);

}  // namespace fnv_00d398c0

namespace fnv_00d3b380 {

struct FUN_00d3b380_object
{
    unsigned int* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short unk10;
};

struct FUN_00d3b380_allocator
{
    virtual void Unused()
    {
    }

    virtual FUN_00d3b380_object* Allocate(unsigned int size);
};

struct FUN_00d3b380_singleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d3b380_allocator* unk10;
};

extern "C" FUN_00d3b380_singleton* __cdecl FUN_00c85750();

}  // namespace fnv_00d3b380

struct FnvCpu_FUN_00d3f480_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d3f480_CpuObject {
    void FUN_00d3e850(void*, void*, unsigned int, FnvCpu_FUN_00d3f480_CpuCallData*);
    void FUN_00d3f480(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data record from the fourth argument, a global float and a global byte, then forwards it with the other arguments to FUN_00d3e850.
// @fnv 0x00d3f480
// pdb: hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::getClosestPoints | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void FnvCpu_FUN_00d3f480_CpuObject::FUN_00d3f480(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d3f480_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d3e850(second, first, third, &data);
}

extern float DAT_0104da48;

struct S_00d3f4c0_Obj {
    virtual void vfn0();
    float unk04;
    int unk08;
    S_00d3f4c0_Obj(int a) : unk04(DAT_0104da48), unk08(a) {}
};

void* __cdecl FUN_00d3ebe0(void* a, void* b, void* c, S_00d3f4c0_Obj* o);

// Constructs an S_00d3f4c0_Obj from d and DAT_0104da48, then calls FUN_00d3ebe0 with b, a, c and the object.
// @fnv 0x00d3f4c0
// pdb: hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::staticGetClosestPoints | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void* __cdecl FUN_00d3f4c0(void* a, void* b, void* c, int iValue)
{
    S_00d3f4c0_Obj obj(iValue);
    return FUN_00d3ebe0(b, a, c, &obj);
}

namespace fnv_00d3f620 {
struct S_00d3f620_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00d3f620_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00d3f620_Alloc* unk10;
    S_00d3f620_Alloc& heap() { return *unk10; }
};
S_00d3f620_Router* FUN_00c85750() throw();
struct S_00d3f620_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d3f620_RefObj() throw() { m_sReferenceCount = 1; }
    virtual ~S_00d3f620_RefObj() throw();
    void* operator new(unsigned int n) {
        S_00d3f620_RefObj* b = static_cast<S_00d3f620_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
};
struct S_00d3f620_Mid : S_00d3f620_RefObj {
    int unk08;
    S_00d3f620_Mid(int a) throw() { unk08 = a; }
};
struct S_00d3f620_Obj : S_00d3f620_Mid {
    unsigned short unk0c;
    S_00d3f620_Obj(int a) throw() : S_00d3f620_Mid(a) { unk0c = 0xffff; }
    virtual ~S_00d3f620_Obj() throw();
};
// Allocates and constructs an S_00d3f620_Obj with a4, returning the new object.
// @fnv 0x00d3f620
S_00d3f620_Obj* __cdecl FUN_00d3f620(int a1, int a2, int a3, int aiValue) {
    return new S_00d3f620_Obj(aiValue);
}
}  // namespace fnv_00d3f620

void __cdecl FUN_00d3fce0(CollisionAgentFunctionTable*);
// @fnv 0x00d3fd00
// pdb: hkpGskfAgent::registerAgent | hkpGskfAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void __cdecl FUN_00d3fd00(Agent* agent) {
    CollisionAgentFunctionTable funcs;
    funcs.e = 0;
    funcs.f = 0;
    FUN_00d3fce0(&funcs);
    agent->FUN_00cfbbe0(&funcs, 1, 1);
}

struct FUN_00d3fd60_cls_Entry { unsigned short m_key; unsigned short m_uiFilterValue; };

struct FUN_00d3fd60_cls
{
    unsigned char m_unk00;
    unsigned char m_unk01;
    FUN_00d3fd60_cls_Entry m_entries[7];
    unsigned short m_key7;
    unsigned char m_unk32;
    unsigned char m_uiItemCount;
    void __thiscall RemoveEntry(int index);
};

struct FUN_00d3fd60_cls_Ref
{
    unsigned char m_unk00;
    unsigned char m_unk01;
    unsigned char m_iObjectReferenceCount;
};

// @fnv 0x00d3fd60
// pdb: hkBoxBoxAgent3::removePoint | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: entry, agentData, idToRemove
void* __cdecl RemoveEntryByKey(FUN_00d3fd60_cls_Ref* ref, FUN_00d3fd60_cls* table, unsigned short key)
{
    int count = table->m_uiItemCount;
    if (count > 0)
    {
        int i = 0;
        FUN_00d3fd60_cls_Entry* e = (FUN_00d3fd60_cls_Entry*)((char*)table + 2);
        do
        {
            if (e->m_key == key)
            {
                table->RemoveEntry(i);
                ref->m_iObjectReferenceCount--;
                return ref;
            }
            i++;
            e++;
        } while (i < count);
        return (void*)i;
    }
    return 0;
}

struct FUN_00d3fda0_entry {
    unsigned short key00;
    unsigned short val02;
};

struct FUN_00d3fda0_table {
    unsigned short unk00;
    FUN_00d3fda0_entry entries[7];
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char count;
};

// @fnv 0x00d3fda0
// pdb: hkBoxBoxAgent3::commitPotential | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, idToCommit
// pdb: hkBoxBoxAgent3::commitPotential | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun, high (was: FindOrClaimEntry)
int __cdecl hkBoxBoxAgent3_commitPotential(int unused, FUN_00d3fda0_table* table, unsigned short value) {
    int i = 0;
    int n = table->count;
    if (n > 0) {
        FUN_00d3fda0_entry* e = &table->entries[0];
        do {
            if (e->key00 == 0xffff) {
                table->entries[i].key00 = value;
                goto found;
            }
            ++i;
            ++e;
        } while (i < n);
    }
found:
    return i;
}

struct D3FE10Agent {
    unsigned short m_flags;
    unsigned short m_iOwnerObjectOffset;
};

struct D3FE10Entry {
    D3FE10Agent m_pAgents[8];
    unsigned char unk20;
    unsigned char m_numAgents;
    unsigned short unk22;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct D3FE10Header {
    unsigned short unk00;
    unsigned char m_iNumberOfEntries;
};

class D3FE10Manager {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void ResetAgent(unsigned short id, void* pkInfo);
};

// @fnv 0x00d3fe10
// pdb: hkBoxBoxAgent3::cleanup | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, mgr, constraintOwner
// pdb: hkBoxBoxAgent3::cleanup | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun, high (was: ResetEntryAgents)
D3FE10Entry* __cdecl hkBoxBoxAgent3_cleanup(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, void* pkInfo)
{
    for (int i = 0; i < pkEntry->m_numAgents; i++) {
        unsigned short id = pkEntry->m_pAgents[i].m_iOwnerObjectOffset;
        if (id != 0xffff)
            pkManager->ResetAgent(id, pkInfo);
    }
    pkEntry->m_numAgents = 0;
    pkHeader->m_iNumberOfEntries = 0;
    return pkEntry + 1;
}

template <class T> class hkArrayD27 {
public:
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

extern int DAT_010ce81c;
struct SpawnedBuf { void* m_iWordAt00; unsigned char m_iWordAt04; int m_8; };
struct Wrapper {
    void hkpMultiRayConvexAgent_getPenetrations(int,int,int,SpawnedBuf*);
    void FUN_00d37bd0(int a,int b,int c,int d);
};
// Builds a SpawnedBuf pointing at DAT_010ce81c with the given value and passes it to hkpMultiRayConvexAgent_getPenetrations along with b, a and c.
// @fnv 0x00d37bd0
// pdb: hkpSymmetricAgentLinearCast<hkpMultiRayConvexAgent>::getPenetrations | hkpMultiRayConvexAgent.obj | fnv360_0822_debug, objrun, high
// pdb params: bodyA, bodyB, input, collector
void Wrapper::FUN_00d37bd0(int a,int b,int c,int d) {
    SpawnedBuf s;
    s.m_8=d; s.m_iWordAt04=0; s.m_iWordAt00=&DAT_010ce81c;
    hkpMultiRayConvexAgent_getPenetrations(b,a,c,&s);
}

typedef void (*CallbackD3D)();

void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void FUN_00d3e110();
void FUN_00d3ac80();

struct AgentFuncsD3D {
    AgentFuncsD3D() : m_bA(false), m_bB(false) {}

    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};

static __declspec(noinline) void InitFuncsB(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateRetObj;
    pkFuncs->m_pfnB = FUN_00d3d3e0;
    pkFuncs->m_pfnC = FUN_00d3d8c0;
    pkFuncs->m_pfnD = FUN_00daf8e0;
    pkFuncs->m_bA = false;
    pkFuncs->m_bB = false;
}

static __declspec(noinline) void InitFuncsA(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateTargetAgent;
    pkFuncs->m_pfnB = QueryD3DCollector;
    pkFuncs->m_pfnC = FUN_00d3e110;
    pkFuncs->m_pfnD = FUN_00d3ac80;
    pkFuncs->m_bA = true;
    pkFuncs->m_bB = false;
}

void (*g_apfnInitD3D[2])(AgentFuncsD3D*) = { InitFuncsA, InitFuncsB };

struct D27690_Atom {
    unsigned short m_type;
};

struct D27690_ConstraintInfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct D27690_Modifier {
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_usModifierAtomSize;
    unsigned short m_childResult;
    D27690_Atom* m_pChildAtom;

    void FUN_00d22090(D27690_ConstraintInfo* info, unsigned char* flags);
};

struct D27690_Entity {
    int unk000; int unk004; int unk008; int unk00C;
    int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C;
    int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C;
    int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C;
    int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C;
    int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC;
    int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC;
    unsigned short unk0D0;
    unsigned char unkD2;
};

struct D27690_Internal {
    void* m_pHavokConstraint;
    int unk04;
    int unk08;
    D27690_Atom* m_kBridgeAtoms;
    unsigned short m_childResult;
    unsigned short unk12;
    unsigned short m_stats;
};

struct D27690_Instance {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D27690_Modifier* m_pConstraintModifier;
    D27690_Entity* m_pEntityA;
    D27690_Entity* m_pEntityB;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    D27690_Internal* m_pConstraintInternal;
};

struct D27690_Owner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void checkReadOnly();

    int unk04;
    int unk08;
    int m_iElementCount;

    void hkpConstraintOwner_subConstraintInfo(void* unk, D27690_ConstraintInfo* info);
};

// Removes the modifier of the given type from the instance's chain, updates internal child result and stats, then frees the modifier.
// @f3 0x009a9400 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct FO3_ConstraintAtom {
    int FUN_009a1ee0(D27690_ConstraintInfo* info);
};

struct FO3_ConstraintOwner {
    void FUN_00929b20(void* unk, D27690_ConstraintInfo* info);
};

struct FO3_ThreadMemory {
    void FUN_008f6d90(void* p, int nbytes, int memClass);
};

// pdb: hkpWorldConstraintUtil::removeAndDeleteModifier | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpWorldConstraintUtil_removeAndDeleteModifier(D27690_Instance* instance, D27690_Owner* owner, unsigned int modifierType)
{
    owner->checkReadOnly();

    D27690_Modifier* curr = instance->m_pConstraintModifier;
    if (curr == 0)
        return;

    D27690_Internal* internal = reinterpret_cast<D27690_Internal*>(instance->unk28);

    if (curr->m_type == modifierType)
    {
        D27690_Atom* child = curr->m_pChildAtom;
        if (internal)
        {
            internal->m_kBridgeAtoms = child;
            internal->m_childResult = curr->m_childResult;
        }
        instance->m_pConstraintModifier = (child->m_type >= 0x17) ? reinterpret_cast<D27690_Modifier*>(child) : 0;
    }
    else
    {
        D27690_Modifier* prev = curr;
        for (D27690_Atom* child = curr->m_pChildAtom; child->m_type >= 0x17; child = curr->m_pChildAtom)
        {
            curr = reinterpret_cast<D27690_Modifier*>(child);
            if (curr->m_type == modifierType)
            {
                prev->m_pChildAtom = curr->m_pChildAtom;
                prev->m_childResult = curr->m_childResult;
                goto FOUND;
            }
            prev = curr;
        }
        return;
    }

FOUND:
    if (internal)
    {
        D27690_ConstraintInfo info;
        info.unk00 = 0;
        info.unk04 = 0;
        info.unk08 = 0;
        info.unk0C = 0;

        reinterpret_cast<FO3_ConstraintAtom*>(curr)->FUN_009a1ee0(&info);
        reinterpret_cast<FO3_ConstraintOwner*>(owner)->FUN_00929b20(internal->m_pHavokConstraint, &info);
    }

    void* threadMem = DAT_00d9b080(DAT_010f3170);
    reinterpret_cast<FO3_ThreadMemory*>(threadMem)->FUN_008f6d90(curr, curr->m_usModifierAtomSize, 44);
}


struct Base {
    int unk4;
    char m_8;
    Base(int a, int b);
    virtual void v0();
};
struct FUN_00d21930 : Base {
    FUN_00d21930(int a, int b);
    virtual void v0();
};
// Constructs the object by forwarding a and b to the Base constructor and setting m_8 to 6.
// @f3 0x0099e130 (community match, verified in this file)
extern int DAT_012698ec;
FUN_00d21930::FUN_00d21930(int a, int b) : Base(a, b)
{
    *(int*)this = (int)&DAT_012698ec;
    m_8 = 7;
}


struct FUN_00d219e0_node
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d219e0_node* unk0C;
};
struct FUN_00d219e0_cls
{
    int unk00;
    unsigned char unk04;
    FUN_00d219e0_node* unk08;
    int unk0C;
    FUN_00d219e0_node* unk10;
    int unk14;
    void __thiscall SetLists(FUN_00d219e0_node* a, FUN_00d219e0_node* b);
};
// Walks both linked lists to their tails, stores each tail and the head's unk04 in the object, and sets unk04 to 1.
// @fnv 0x00d219e0
void __thiscall FUN_00d219e0_cls::SetLists(FUN_00d219e0_node* pFirstList, FUN_00d219e0_node* pSecondList)
{
    FUN_00d219e0_node* pTail = pFirstList;
    while (pTail->unk0C)
        pTail = pTail->unk0C;
    unk08 = pTail;
    unk0C = pFirstList->unk04;
    pTail = pSecondList;
    while (pTail->unk0C)
        pTail = pTail->unk0C;
    unk10 = pTail;
    unk14 = pSecondList->unk04;
    unk04 = 1;
}

extern int DAT_0101e594;
struct VtblStub_0101e594 { void* m_ppVirtualMethodTable; };
extern "C" void __cdecl FUN_00401030(VtblStub_0101e594*);
struct FUN_00d26210
{
    void* m_ppVirtualMethodTable;
    FUN_00d26210(char construct);
};
// @fnv 0x00d26210
FUN_00d26210::FUN_00d26210(char construct)
{
    m_ppVirtualMethodTable = &DAT_0101e594;
    if (construct & 1)
        FUN_00401030((VtblStub_0101e594*)this);
}

struct PairEntry
{
	void* m_pCollisionAgent;
	unsigned int m_link0;
	unsigned int m_link1;
	int m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};

struct PairNode
{
	int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
	int m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
	int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
	int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
	int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c;
	int m_a0, m_a4, m_a8;
	PairEntry* m_entries;
	unsigned short m_iNumberOfEntries;
	unsigned short m_pRayCursor;
};

// Scans both nodes' entry arrays for an entry whose XOR-linked node equals the other node and returns that entry's value, else 0.
// @f3 0x009a9370 (community match, verified in this file)
struct FindNodeStandIn
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
	PairEntry* m_entries;
	unsigned short m_iNumberOfEntries;
};
// pdb: hkpWorldConstraintUtil::getConstraint | hkpWorldConstraintUtil.obj | fnv360_0822_retail, objrun_open, low
// pdb params: entityA, entityB
void* __cdecl FindSharedEntryValue(PairNode* pNodeA, PairNode* pNodeB)
{
	PairNode* pNodePair[2];
	pNodePair[0] = pNodeA;
	pNodePair[1] = pNodeB;
	for (int i = 0; i < 2; i++)
	{
		FindNodeStandIn* self = (FindNodeStandIn*)pNodePair[i];
		PairNode* other = pNodePair[1 - i];
		for (int j = 0; j < self->m_iNumberOfEntries; j++)
		{
			PairEntry* e = &self->m_entries[j];
			if ((PairNode*)(e->m_link1 ^ e->m_link0 ^ (unsigned int)self) == other)
			{
				return self->m_entries[j].m_pCollisionAgent;
			}
		}
	}
	return 0;
}


struct FUN_00d277f0_node
{
    unsigned short unk00;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00d277f0_node* unk14;
};
struct FUN_00d277f0_arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d277f0_node* unk10;
};
// Walks the linked list from a->unk10 while node unk00 is at least 0x17 and returns the last node visited.
// @fnv 0x00d277f0
// pdb: hkpWorldConstraintUtil::findLastModifier | hkpWorldConstraintUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: instance
FUN_00d277f0_node* __cdecl FUN_00d277f0(FUN_00d277f0_arg* a)
{
    FUN_00d277f0_node* p = a->unk10;
    if (!p) {
        return p;
    }
    FUN_00d277f0_node* n = p->unk14;
    if (n->unk00 < 0x17) {
        return p;
    }
    do {
        p = n;
        n = n->unk14;
    } while (n->unk00 >= 0x17);
    return p;
}

struct FnvCpu_FUN_00d2c7d0_CpuInterface {
    virtual void Invoke(int value);
};
// @fnv 0x00d2c7d0
void __cdecl FUN_00d2c7d0(FnvCpu_FUN_00d2c7d0_CpuInterface* object)
{
    object->Invoke(0);
}

class FUN_00d2c7e0 {
public:
    virtual ~FUN_00d2c7e0();
    FUN_00d2c7e0(int count);
};
class ObjD2C840 : public FUN_00d2c7e0 {
public:
    virtual ~ObjD2C840();
    ObjD2C840(int count) : FUN_00d2c7e0(count) {}
    static void* operator new(unsigned int, void* p) throw() { return p; }
    static void operator delete(void*, void*) throw() {}
};

struct SubA { void FUN_00d87910(); };
struct SubB { void Create(int a, int b); };
struct C_d2cda0 {
    int m_iWordAt00;
    int unk04;
    SubA a8;
    int unk0C, unk10, unk14;
    int m_18;
    int unk1C;
    char m_20;
    char pad21[3];
    SubB b24;
    int m_28;
    int m_2c;
    C_d2cda0* FUN_00d2cda0();
};
// @f3 0x00941f60 (community match, verified in this file)
struct SubA_fix { void FUN_00984a70(); };

// pdb: hkCpuJobThreadPool::WorkerThreadData::WorkerThreadData | hkCpuJobThreadPool.obj | tesv_win, caller_sim, low
C_d2cda0* C_d2cda0::FUN_00d2cda0() {
    reinterpret_cast<SubA_fix*>(&a8)->FUN_00984a70();
    reinterpret_cast<SubB*>(&m_20)->Create(0, 1);
    m_28 = 0;
    m_2c = 0;
    *reinterpret_cast<unsigned char*>(&unk1C) = 0;
    m_18 = -1;
    m_iWordAt00 = 0;
    return this;
}


struct FnvCpu_FUN_00d329b0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d329b0_CpuObject {
    void hkpHeightFieldAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d329b0_CpuCallData*);
    void DispatchWithBound(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data record from the fourth argument, DAT_0104da48 and DAT_010ce7fc, then forwards it to hkpHeightFieldAgent_getClosestPoints with the first two arguments swapped.
// @fnv 0x00d329b0
// pdb: hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::getClosestPoints | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void FnvCpu_FUN_00d329b0_CpuObject::DispatchWithBound(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d329b0_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpHeightFieldAgent_getClosestPoints(second, first, third, &data);
}

// @fnv 0x00d32ac0
// pdb: hkConvexListAgent3::getAgent1nTrack | hkpConvexListAgent3.obj | fnv360_0822_retail, call_seq, high
// pdb params: entry, data
int __cdecl FUN_00d32ac0(int param_1, int param_2)
{
    return param_2 + 0x10;
}

// @fnv 0x00d32ad0
// pdb: hkConvexListAgent3::getAgent1nTrack | hkpConvexListAgent3.obj | fnv360_0822_retail, call_seq, high
// pdb params: entry, data
void* __cdecl FUN_00d32ad0(int unused, char* p) {
    return p + 16;
}

extern int DAT_010ce81c;
void __cdecl FUN_00d33b90(int b, int a, int c, SpawnedBuf* buffer);
// Initializes a SpawnedBuf with zero, a global pointer and d, then calls FUN_00d33b90 with b, a, c and the buffer.
// @fnv 0x00d34930
// pdb: hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticGetPenetrations | hkpConvexListAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl InitSpawnedBuffer(int a, int b, int c, int d)
{
    SpawnedBuf buffer;
    buffer.m_iWordAt04 = 0;
    buffer.m_iWordAt00 = &DAT_010ce81c;
    buffer.m_8 = d;
    FUN_00d33b90(b, a, c, &buffer);
}

struct FUN_00d34aa0_Obj {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();

    void __thiscall hkpConvexListAgent_updateShapeCollectionFilter(int a, int b, int c, int d);
    virtual void __thiscall FUN_00d34aa0(int a, int b, int c, int d);
};
// @fnv 0x00d34aa0
// pdb: hkpSymmetricAgentLinearCast<class hkpConvexListAgent>::updateShapeCollectionFilter | hkpConvexListAgent.obj | tesv_win, vtable_prefix, medium
void __thiscall FUN_00d34aa0_Obj::FUN_00d34aa0(int param_1, int param_2, int param_3, int param_4)
{
    hkpConvexListAgent_updateShapeCollectionFilter(param_2, param_1, param_3, param_4);
}

struct FnvCpu_FUN_00d34b00_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d34b00_CpuObject {
    void hkpConvexListAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d34b00_CpuCallData*);
    void DispatchCpuCall(void*, void*, unsigned int, unsigned int);
};
// @fnv 0x00d34b00
// pdb: hkpSymmetricAgentLinearCast<hkpConvexListAgent>::getClosestPoints | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix, high
// pdb params: bodyA, bodyB, input, collector
void FnvCpu_FUN_00d34b00_CpuObject::DispatchCpuCall(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d34b00_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpConvexListAgent_getClosestPoints(second, first, third, &data);
}

// Scans the first three entries of table for key and, if found, replaces it with 0xffff and returns.
// @fnv 0x00d39030
// pdb: hkCapsuleTriangleAgent3::removePoint | hkpCapsuleTriangleAgent3.obj | fnv360_0822_retail, objrun_open, low
// pdb params: entry, agentData, idToRemove
void RemoveKeyFromTable(int, unsigned short* table, unsigned short key)
{
    for (int i = 0; i < 3; ++i) {
        if (table[i] == key) {
            table[i] = 0xffff;
            return;
        }
    }
}

// Scans the first three slots for the 0xffff empty marker and writes value into the first free one, then returns.
// @fnv 0x00d39060
// pdb: hkCapsuleTriangleAgent3::commitPotential | hkpCapsuleTriangleAgent3.obj | fnv360_0822_retail, objrun_open, low
// pdb params: entry, agentData, idToCommit
void __cdecl InsertIntoSlotArray(void* unused, unsigned short* slots, unsigned short value) {
    for (int i = 0; i < 3; ++i) {
        if (slots[i] == 0xffff) {
            slots[i] = value;
            return;
        }
    }
}

typedef void (*CallbackD3D)();
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void FUN_00d3e110();
void FUN_00d3ac80();
struct FUN_00d390a0_Leaf {
    char unk00[0x20];
};
struct FUN_00d390a0_Mid {
    FUN_00d390a0_Leaf* m_pLeafNode;
};
struct FUN_00d390a0_Owner {
    int unk00;
    FUN_00d390a0_Mid* m_mid;
};
struct FUN_00d390a0_Flags {
    char unk00;
    char unk01;
    unsigned char unk02;
};
struct FUN_00d390a0_Out {
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
void __cdecl ComputeInverseLengths(void* a, void* b);
// @fnv 0x00d390a0
// pdb: hkCapsuleTriangleAgent3::create | hkpCapsuleTriangleAgent3.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: input, entry, agentData
char* __cdecl InitOutputDefaults(FUN_00d390a0_Owner* owner, FUN_00d390a0_Flags* flags, FUN_00d390a0_Out* out) {
    FUN_00d390a0_Leaf* leaf = owner->m_mid->m_pLeafNode;
    flags->unk02 = 0;
    out->unk00 = 0xffff;
    out->unk02 = 0xffff;
    out->unk04 = 0xffff;
    ComputeInverseLengths((char*)leaf + 0x20, &out->unk08);
    return (char*)out + 0x20;
}

struct D390Callback {
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(unsigned int key, void* context);
};

struct D390HandleTable {
    unsigned short handles[3];
    unsigned short state06;
    unsigned short state08;
    unsigned short state0a;
    unsigned short state0c;
    unsigned short state0e;
    unsigned short state10;
    unsigned short state12;
    unsigned short state14;
    unsigned short state16;
    unsigned short state18;
    unsigned short state1a;
    unsigned short state1c;
    unsigned short state1e;
    unsigned short state20;
};

// Calls callback->method14 for each non-0xffff handle in handles, marks them 0xffff, and returns &handles->state20.
// @fnv 0x00d390e0
// pdb: hkCapsuleTriangleAgent3::cleanup | hkpCapsuleTriangleAgent3.obj | fnv360_0822_retail, objrun_open, low
// pdb params: entry, agentData, mgr, constraintOwner
unsigned short* __cdecl ReleaseHandles(void* unused, D390HandleTable* handles, D390Callback* callback, void* context)
{
    for (int index = 0; index < 3; ++index) {
        unsigned int handle = handles->handles[index];
        if ((unsigned short)handle != 0xffff) {
            callback->method14(handle, context);
            handles->handles[index] = 0xffff;
        }
    }
    return &handles->state20;
}

struct D3FD30Funcs {
    D3FD30Funcs() : m_bA(false), m_bB(false) {}
    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};
void __cdecl FUN_00d3fce0(D3FD30Funcs* pkFuncs);

extern int DAT_0102e388;

struct Foo00d24660 {
    void FUN_00d24660();
};

// @fnv 0x00d24660
// pdb: BGSPickupPutdownSounds::~BGSPickupPutdownSounds | BGSPickupPutdownSounds.obj | fnv360_0822_retail, call_gap, low
void Foo00d24660::FUN_00d24660()
{
    *(int*)this = (int)&DAT_0102e388;
}

class hkMemoryAllocatorD262 {
public:
    virtual ~hkMemoryAllocatorD262() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD262 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD262* m_pStreamAllocator;
    hkMemoryAllocatorD262& heap() { return *m_pStreamAllocator; }
};

namespace hkRouterD262 {
    extern "C" hkMemoryRouterD262& __cdecl FUN_00c85750() throw();
}

class FUN_00d496d0 {
public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00d24660() throw();

    static void operator delete(void* p) throw()
    {
        hkRouterD262::FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d496d0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d496d0* FUN_00d262e0(unsigned int uiFlags) throw();
};

void hkAgent1nMachine_InvalidateTim(void*, void*);

// @fnv 0x00d2d460
// pdb: hkBvTreeAgent3::invalidateTim | hkpBvTreeAgent3.obj | tesv_win, objrun_sim, low
void FUN_00d2d460(int, void* b, void* c)
{
    hkAgent1nMachine_InvalidateTim(b, c);
}

extern unsigned char DAT_011b4284;

extern unsigned char DAT_011b4284;

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern "C" void __cdecl hkpShapeCollectionAgent_staticGetClosestPoints();

struct D347D0Query {
    const unsigned char* descriptor;
    float bound;
    unsigned int filter;
};

// Builds a D347D0Query from DAT_010ce7fc, DAT_0104da48 and filter, then calls hkpShapeCollectionAgent_staticGetClosestPoints with b, a, c and the query.
// @fnv 0x00d347d0
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints | hkpConvexListAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: bodyA, bodyB, input, collector
void __cdecl QueryClosestPoints(void* a, void* b, void* c, unsigned int filter)
{
    D347D0Query query = { &DAT_010ce7fc, DAT_0104da48, filter };
    typedef void (__cdecl *Dispatch)(void*, void*, void*, D347D0Query*);
    ((Dispatch)hkpShapeCollectionAgent_staticGetClosestPoints)(b, a, c, &query);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct D34970Context {
    void* pointer;
    float maxDistance;
    int option;
};
extern "C" void __cdecl FUN_00d339d0(int first, int second, int third, D34970Context* context);
// Builds a D34970Context from DAT_010ce7fc, DAT_0104da48, and arg3, then calls FUN_00d339d0 with arg1, arg0, arg2, and the context.
// @fnv 0x00d34970
// pdb: hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticGetClosestPoints | hkpConvexListAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d34970(int arg0, int arg1, int arg2, int aiOption) {
    D34970Context context;
    context.pointer = &DAT_010ce7fc;
    context.maxDistance = DAT_0104da48;
    context.option = aiOption;
    FUN_00d339d0(arg1, arg0, arg2, &context);
}

extern int DAT_010ce81c;

struct D34ac0Struct {
    void* e;
    unsigned char f;
    void* g;
};

struct FUN_00d33c80_class {
    void hkpConvexListAgent_getPenetrations(void* a, void* b, void* c, void* d);
    void FUN_00d34ac0(void* a, void* b, void* c, void* d);
};

// Builds a local struct holding &DAT_010ce81c, 0 and d, then calls hkpConvexListAgent_getPenetrations with b, a, c and a pointer to the struct.
// @fnv 0x00d34ac0
// pdb: hkpSymmetricAgentLinearCast<hkpConvexListAgent>::getPenetrations | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix, high
// pdb params: bodyA, bodyB, input, collector
void FUN_00d33c80_class::FUN_00d34ac0(void* a, void* b, void* c, void* d)
{
    D34ac0Struct s;
    s.g = d;
    s.f = 0;
    s.e = &DAT_010ce81c;
    hkpConvexListAgent_getPenetrations(b, a, c, &s);
}

extern void __cdecl FUN_00cd7160(void* src, void* dst);

// Allocates a 0x20-byte object, sets its header fields and vtable pointer, and passes *a2 + 0x20 and its m10 block to FUN_00cd7160.
// @f3 0x009c2a70 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern int DAT_00e7f064;
void __cdecl FUN_0096fd30(void* src, void* dst);
namespace f3m_009c2a70 {
struct RetObjHeapF3
{
    void* Allocate(unsigned int bytes, unsigned int tag);
};
struct RetObjF3
{
    void* vtbl;
    unsigned short f04;
    unsigned short f06;
    int f08;
    unsigned short f0c;
    unsigned short f0e;
    unsigned short f10;
    unsigned short f12;
    int m14;
};
}
// pdb: hkpCapsuleTriangleAgent::createCapsuleTriangleAgent | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun_open, low
// pdb params: bodyA, bodyB, input, mgr
void* __cdecl CreateRetObj(int a1, char** a2, int a3, int aiValue)
{
    f3m_009c2a70::RetObjHeapF3* heap = (f3m_009c2a70::RetObjHeapF3*)DAT_00d9b080(DAT_010f3170);
    f3m_009c2a70::RetObjF3* mgr = (f3m_009c2a70::RetObjF3*)heap->Allocate(0x28, 0x1f);
    mgr->f0c = 0xffff;
    mgr->f0e = 0xffff;
    mgr->f10 = 0xffff;
    mgr->f08 = aiValue;
    mgr->f04 = 0x28;
    mgr->f06 = 1;
    mgr->vtbl = (void*)&DAT_00e7f064;
    FUN_0096fd30(*a2 + 0x20, &mgr->m14);
    return mgr;
}


struct D3E270_obj;
struct D3E270_alloc {
    virtual void v00();
    virtual D3E270_obj* alloc(int size);
};
struct D3E270_obj {
    D3E270_alloc* vt;
    unsigned short f04;
    unsigned short f06;
    int f08;
    unsigned short f0c;
};

#include <xmmintrin.h>

namespace sd21cc0 {

}

struct __declspec(align(16)) Vector4D22DC0 {
    float x;
    float y;
    float z;
    float w;
    void setZero4() { *reinterpret_cast<__m128*>(this) = _mm_setzero_ps(); }
    void operator=(const Vector4D22DC0& kOther) { *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&kOther); }
};
struct RotationD22DC0 {
    Vector4D22DC0 m_kColumn0;
    Vector4D22DC0 m_kColumn1;
    Vector4D22DC0 m_kColumn2;
    float& operator()(int iRow, int iCol) { return reinterpret_cast<float*>(&m_kColumn0 + iCol)[iRow]; }
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct TransformD22DC0 {
    RotationD22DC0 m_rotation;
    Vector4D22DC0 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
struct ReferencedD22DC0 {
    ReferencedD22DC0() throw() { m_sReferenceCount = 1; }
    virtual ~ReferencedD22DC0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeD22DC0 : public ReferencedD22DC0 {
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType) { m_kMotionTransform.setIdentity(); }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    TransformD22DC0 m_kMotionTransform;
    int m_type;
};

struct E48 { int a[12]; };
extern "C" void __cdecl FUN_00d06c30(void* self, int newCap, int elemSize);
extern "C" void __cdecl CopyMemoryBackward(void* dst, const void* src, int size);

struct hkSmallArrayE {
    E48* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void reserve(int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00d06c30(this, newSize, sizeof(E48));
        }
    }
    void Insert(int i, const E48* a, int numtoinsert);
};

// Inserts numtoinsert elements from a at index i, moving existing elements back and updating the size.
// @fnv 0x00d27ec0
void hkSmallArrayE::Insert(int iIndex, const E48* apElements, int numtoinsert)
{
    const int newsize = m_iElementCount + numtoinsert;
    const int numtomove = m_iElementCount - iIndex;
    if (newsize > getCapacity()) reserve(newsize);
    CopyMemoryBackward(m_data + iIndex + numtoinsert, m_data + iIndex, numtomove * sizeof(E48));
    CopyMemoryBackward(m_data + iIndex, apElements, numtoinsert * sizeof(E48));
    m_iElementCount = (unsigned short)newsize;
}

struct S00d281b0_Alloc {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <typename T>
    __forceinline void _bufFree(T* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

struct S00d281b0_Router {
    unsigned int unk00, unk04, unk08;
    S00d281b0_Alloc* allocator;
    S00d281b0_Alloc& heap() { return *allocator; }
};

struct S00d281b0_IntArray {
    int* data;
    int count;
};

struct S00d281b0_Target {
    S00d281b0_IntArray* indices;
    int count;
    int hkUnionFind_moveBiggestGroupToIndexZero(S00d281b0_IntArray* values);
};

// Finds the index of the largest value in values, swaps it with the first element, and remaps this->indices through the swap permutation.
// @f3 0x009ad420 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct FUN_00d9b_bump
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* AllocSlow(unsigned int bytes);
    virtual void FreeSlow(void* p);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* cur;
    int unk24;
    char* start;
    char* end;
};

// pdb: hkUnionFind::moveBiggestGroupToIndexZero | hkUnionFind.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: elementsPerGroup
// pdb: hkUnionFind::moveBiggestGroupToIndexZero | hkUnionFind.obj | fnv360_0822_retail, call_gap_sim, high (was: MoveLargestToFirst)
int S00d281b0_Target::hkUnionFind_moveBiggestGroupToIndexZero(S00d281b0_IntArray* values)
{
    int largest = 0;
    int size = values->count;
    int max = values->data[0];
    for (int i = 1; i < size; ++i) {
        if (values->data[i] > max) {
            max = values->data[i];
            largest = i;
        }
    }
    if (!largest) return 0;

    int* mapping;
    FUN_00d9b_bump* a = (FUN_00d9b_bump*)DAT_00d9b080(DAT_010f3170);
    unsigned int bytes = ((unsigned int)size * 4 + 0x10) & 0xfffffff0;
    char* p = a->cur;
    char* nxt = p + bytes;
    if ((unsigned int)nxt <= (unsigned int)a->end) {
        a->cur = nxt;
    } else {
        p = (char*)a->AllocSlow(bytes);
    }
    mapping = (int*)p;
    for (int i = 0; i < size; ++i) mapping[i] = i;
    mapping[0] = largest;
    mapping[largest] = 0;

    int first = values->data[0];
    int other = values->data[largest];
    values->data[largest] = first;
    values->data[0] = other;

    for (int i = 0; i < this->count; ++i) {
        int& r = this->indices->data[i];
        r = mapping[r];
    }
    FUN_00d9b_bump* b = (FUN_00d9b_bump*)DAT_00d9b080(DAT_010f3170);
    b->cur = (char*)mapping;
    if ((char*)mapping == b->start)
        b->FreeSlow(mapping);
    return largest;
}


extern __declspec(thread) unsigned int t_uiMemContextB110;
inline unsigned int GetMemContextB110()
{
    return t_uiMemContextB110;
}
inline void SetMemContextB110(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextB110 = m_uiGeometryShaderFlags;
}
class AutoMemContextB110 {
public:
    AutoMemContextB110(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextB110();
        SetMemContextB110(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextB110() { SetMemContextB110(m_uiPrevious); }
    unsigned int m_uiPrevious;
};



struct hkVector4B110 {
    inline hkVector4B110& operator=(const hkVector4B110& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __m128 m_vComponents;
};

class hkMemoryAllocatorB110 {
public:
    virtual ~hkMemoryAllocatorB110();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterB110 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorB110& heap() { return *m_pStreamAllocator; }
    hkMemoryAllocatorB110* m_pStreamAllocator;
};

hkMemoryRouterB110* __cdecl GetMemoryRouterB110();

class hkReferencedObjectB110 {
public:
    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectB110* b = static_cast<hkReferencedObjectB110*>(GetMemoryRouterB110()->heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkReferencedObjectB110* b = static_cast<hkReferencedObjectB110*>(p);
        GetMemoryRouterB110()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
    virtual ~hkReferencedObjectB110();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct ShapeB110;
struct BodyB110 {
    ShapeB110* getShape() const { return m_pCollisionShape; }
    ShapeB110* m_pCollisionShape;
};
struct InputB110 {
    BodyB110* m_kCollisionBody;
    int m_type;
};

class AgentB110 : public hkReferencedObjectB110 {
public:
    AgentB110(ShapeB110* pShape, const hkVector4B110& kA, const hkVector4B110& kB, float fA, float fB, void* pUser);
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
    hkVector4B110 m_offset;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};

class AgentFactoryB110 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAgentData;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4B110 m_kA;
    hkVector4B110 m_kB;
    hkVector4B110 m_offset;
    float m_fCoefficientA;
    float m_fB;

    AgentB110* FUN_00d2b110(const InputB110* pA, const InputB110* pB);
};

// Creates an AgentB110 from pA's collision body shape when pA is type 2 and pB is type 0, otherwise returns null.
// @f3 0x009ae850 (community match, verified in this file)
struct BodyB110ShapeRef {
    ShapeB110* const& getShape() const { return m_pCollisionShape; }
    ShapeB110* m_pCollisionShape;
};
struct S00d2b110_Pool
{
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};
struct FUN_009ae1a0
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    static void* operator new(unsigned int size)
    {
        S00d2b110_Pool* pool = (S00d2b110_Pool*)DAT_00d9b080(DAT_010f3170);
        FUN_009ae1a0* p = (FUN_009ae1a0*)pool->FUN_008f6d30(0x60, 0x29);
        p->m_usMemSizeAndFlags = 0x60;
        return p;
    }
    FUN_009ae1a0(ShapeB110* pShape, const hkVector4B110& kA, const hkVector4B110& kB, float fA, float fB, void* pUser);
};
// pdb: hkOrientHingedBodyAction::clone | hkOrientHingedBodyAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: newEntities, newPhantoms
AgentB110* AgentFactoryB110::FUN_00d2b110(const InputB110* apInputA, const InputB110* apInputB)
{
    if (apInputA->m_type != 2)
        return 0;
    int typeB = apInputB->m_type;
    if (typeB != 0)
        return 0;
    AgentB110* pAgent = (AgentB110*)new FUN_009ae1a0(((BodyB110ShapeRef*)apInputA->m_kCollisionBody)->getShape(), m_kA, m_kB, m_fCoefficientA, m_fB, m_pAgentData);
    float* src = (float*)&m_offset;
    float* dst = (float*)&pAgent->m_offset;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    return pAgent;
}


extern __declspec(thread) unsigned int t_uiMemContextD2C9;

inline unsigned int GetMemContextD2C9()
{
    return t_uiMemContextD2C9;
}

inline void SetMemContextD2C9(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextD2C9 = m_uiGeometryShaderFlags;
}

class AutoMemContextD2C9 {
public:
    AutoMemContextD2C9(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextD2C9();
        SetMemContextD2C9(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextD2C9() { SetMemContextD2C9(m_uiPrevious); }
    unsigned int m_uiPrevious;
};

struct hkMemoryAllocatorD2C9 {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterD2C9 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD2C9* m_pStreamAllocator;

    hkMemoryAllocatorD2C9& heap() { return *m_pStreamAllocator; }
};

struct RouterD2C9 {
    static hkMemoryRouterD2C9& __cdecl FUN_00c85750() throw();
};

struct __declspec(align(16)) hkVector4D2C9 {
    __m128 m_vComponents;
    inline hkVector4D2C9& operator=(const hkVector4D2C9& v) { m_vComponents = v.m_vComponents; return *this; }
};

class hkReferencedObjectD2C9 {
public:
    virtual ~hkReferencedObjectD2C9();

    void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectD2C9* b = static_cast<hkReferencedObjectD2C9*>(RouterD2C9::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    void operator delete(void* p, unsigned int nbytes)
    {
        RouterD2C9::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct RequestD2C9 {
    int* m_pName;
    int m_iKind;
    int GetName() const { return *m_pName; }
    int* GetNamePtr() const { return m_pName; }
};

extern float DAT_0104da48;
extern int DAT_010ce80c;
extern __m128 DAT_010c44d0;
struct Vec { int x, y, z, w; };
struct Src {
    int u[20];
    Vec v;
    int t0, t1, t2, t3;
};
struct Q {
    int* vt;
    float d;
    int p1, p2;
    Vec v;
    int x;
    int t1, t2, t3;
};
void __cdecl FUN_00d2f0d0();
typedef void (__cdecl *Fn)(int, int, Src*, Q*, Q*);
// XORs c->v with DAT_010c44d0 into a copy of c, builds one or two Q structs from c->v, d and e, and calls FUN_00d2f0d0 with b, a, the copy and the Qs.
// @f3 0x009b59e0 (community match, verified in this file)
// pdb: hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticLinearCast | hkpMoppBvTreeStreamAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void __cdecl FUN_00d2daf0(int a, int b, Src* apSrc, int d, int e)
{
    __declspec(align(16)) Src copy = *apSrc;
    *(float*)&copy.v.x = -*(float*)&apSrc->v.x;
    *(float*)&copy.v.y = -*(float*)&apSrc->v.y;
    *(float*)&copy.v.z = -*(float*)&apSrc->v.z;
    *(float*)&copy.v.w = -*(float*)&apSrc->v.w;
    Q qa;
    qa.d = DAT_0104da48;
    qa.vt = &DAT_010ce80c;
    qa.v = apSrc->v;
    qa.x = d;
    if (e) {
        Q qb;
        qb.vt = &DAT_010ce80c;
        qb.d = DAT_0104da48;
        qb.v = apSrc->v;
        qb.x = e;
        ((Fn)FUN_00d2f0d0)(b, a, &copy, &qa, &qb);
    } else {
        ((Fn)FUN_00d2f0d0)(b, a, &copy, &qa, 0);
    }
}


struct CallbackState {
    const int* m_pIntegerValue;
    char m_cFlag;
    int m_iValue;
};
struct Holder {
    void FUN_00d315f0(int a, int b, int c, CallbackState* s);
    void FUN_00d2f3f0(int a, int b, int c, int d);
};
// Fills a CallbackState with d, a zero flag, and a pointer to DAT_010ce81c, then calls FUN_00d315f0 with b, a, c, and the state.
// @fnv 0x00d2f3f0
// pdb: hkpSymmetricAgentLinearCast<hkpMoppAgent>::getPenetrations | hkpMoppAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void Holder::FUN_00d2f3f0(int a, int b, int c, int aiValue)
{
    CallbackState s;
    s.m_iValue = aiValue;
    s.m_cFlag = 0;
    s.m_pIntegerValue = (const int*)&DAT_010ce81c;
    FUN_00d315f0(b, a, c, &s);
}

extern "C" void _ReadWriteBarrier();
struct ShapeD2F630 {
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct CdBodyD2F630 {
    ShapeD2F630* m_pCollisionShape;
};
struct InputD2F630;
struct CollectorD2F630;
typedef void (__cdecl *AgentFuncD2F630)(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector);
struct AgentFuncsD2F630 {
    AgentFuncD2F630 m_pQueryPenetrationsFunc;
    void* m_func04;
    void* m_func08;
    void* m_func0C;
    void* m_func10;
};
struct DispatcherD2F630 {
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
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agentTypes[32][32];
    unsigned char m_agentTypesPred[32][32];
    AgentFuncsD2F630 m_agentFuncs[32];
};
struct InputD2F630 {
    DispatcherD2F630* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_createPredictive;
};

struct FUN_00d32970_Collector {
    void* vtable;
    unsigned char flag;
    unsigned int value;
};

struct FUN_00d32970_Agent {
    void FUN_00d32150(void* a, void* b, void* c, FUN_00d32970_Collector* collector);
    void FUN_00d32970(void* a1, void* a2, void* a3, unsigned int a4);
};

// Initialises a Collector with a4 and passes it to FUN_00d32150 with a2, a1 and a3.
// @fnv 0x00d32970
// pdb: hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::getPenetrations | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void FUN_00d32970_Agent::FUN_00d32970(void* a1, void* a2, void* a3, unsigned int uiValue)
{
    FUN_00d32970_Collector collector;
    collector.value = uiValue;
    collector.flag = 0;
    collector.vtable = &DAT_010ce81c;
    FUN_00d32150(a2, a1, a3, &collector);
}

namespace fnv_00d329f0 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d329 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

}  // namespace fnv_00d329f0

namespace fnv_00d34810 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl FUN_00d43b90(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// XORs the input vector with DAT_010c44d0, builds a Record_d2e9 with the key and a4, and calls FUN_00d43b90 with an optional second record for a5.
// @fnv 0x00d34810
void __cdecl FUN_00d34810(int a2, int a1, const Input_d2e9* input, int aiValue, int aiOptionalValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        FUN_00d43b90(a1, a2, &local, &rec, &rec2);
    } else {
        FUN_00d43b90(a1, a2, &local, &rec, 0);
    }
}
}  // namespace fnv_00d34810

namespace fnv_00d349b0 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

}  // namespace fnv_00d349b0

namespace fnv_00d34b40 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d34b {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

}  // namespace fnv_00d34b40

extern "C" __m128 DAT_010c4c00;
extern "C" void _ReadWriteBarrier(void);

class hkVector4 {
public:
    __m128 m_vComponents;

    __forceinline hkVector4 getSimdAt3() const {
        hkVector4 r;
        r.m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
    __forceinline void addMul4(const hkVector4& a, const hkVector4& b) {
        m_vComponents = _mm_add_ps(_mm_mul_ps(a.m_vComponents, b.m_vComponents), m_vComponents);
    }
    __forceinline static void setNeg4(hkVector4& dst, const hkVector4& a, const __m128& neg) {
        dst.m_vComponents = _mm_xor_ps(a.m_vComponents, neg);
    }
};

struct Point {
    hkVector4 m_pos;
    hkVector4 m_vHitNormal;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    __forceinline void flip() {
        m_pos.addMul4(m_vHitNormal.getSimdAt3(), m_vHitNormal);
        hkVector4::setNeg4(m_vHitNormal, m_vHitNormal, DAT_010c4c00);
    }
};

extern "C" void __cdecl hkAgent1nMachine_InvalidateTim(int, int);
// Forwards a2 and a3 to hkAgent1nMachine_InvalidateTim, ignoring a1.
// @fnv 0x00d34d60
// pdb: hkpCollectionCollectionAgent3::invalidateTim | hkpCollectionCollectionAgent3.obj | tesv_win, objrun, medium
void __cdecl ForwardCall(int aUnused, int a2, int a3)
{
    hkAgent1nMachine_InvalidateTim(a2, a3);
}

struct D36B70_Heap
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct FUN_00d36b20
{
    void* unk00;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    static __forceinline void* operator new(unsigned int size) throw()
    {
        AllocationManager* manager = FUN_00c85750();
        FUN_00d36b20* object = static_cast<FUN_00d36b20*>(static_cast<D36B70_Heap*>(manager->allocator)->AllocateMemoryBlock(size));
        object->m_usMemSizeAndFlags = (unsigned short)size;
        return object;
    }
    FUN_00d36b20(int param1, int param2, int* param3, int param4) throw();
};
// Allocates a FUN_00d36b20 object via the custom heap operator new and forwards the four constructor arguments to it.
// @fnv 0x00d36b70
FUN_00d36b20* FUN_00d36b70(int param1, int param2, int* param3, int param4)
{
    return new FUN_00d36b20(param1, param2, param3, param4);
}

namespace fnv_00d2dc10 {
struct D2DC10Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D2DC10MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2DC10Allocator* m_pStreamAllocator;

    D2DC10Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D2DC10MemoryRouter& __cdecl FUN_00c85750();

class D2DC10BaseObject {
public:
    virtual ~D2DC10BaseObject() {}
};

class FUN_00d2dc10 : public D2DC10BaseObject {
// Default constructor for a D2DC10 base object, inheriting from D2DC10BaseObject with no initialization.
// @fnv 0x00d2dc10
public:
    FUN_00d2dc10() {}
    virtual ~FUN_00d2dc10() {}

    static void* operator new(unsigned int, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void operator delete(void* p, unsigned int nbytes) { FUN_00c85750().heap().ReleaseBlock(p, nbytes); }

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

}  // namespace fnv_00d2dc10

namespace fnv_00d37d30 {
struct D37D30Allocator {
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void vfunc03();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D37D30MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D37D30Allocator* m_pStreamAllocator;

    D37D30Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D37D30MemoryRouter& __cdecl FUN_00c85750();

class D37D30ReferencedObject {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~D37D30ReferencedObject() throw() {}
};

template <class T>
class D37D30Array {
public:
    enum { CAPACITY_MASK = 0x3fffffff };
    static const unsigned int DONT_DEALLOCATE_FLAG = 0x80000000;

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~D37D30Array() throw() {
        D37D30Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & CAPACITY_MASK) * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
};

class FUN_00d37d30 : public D37D30ReferencedObject {
public:
    int unk08;
    D37D30Array<unsigned short> m_ppIndices;

    FUN_00d37d30();

    static void operator delete(void* p) {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<D37D30ReferencedObject*>(p)->m_usMemSizeAndFlags);
    }
};

}  // namespace fnv_00d37d30

#include <xmmintrin.h>
namespace fnv_00d22260 {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float f[4]; };
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

struct D22260_Math {
    __m128 v;
    void rotate(const float* rows, const D22260_Math& input) {
        __m128 x = _mm_shuffle_ps(input.v,input.v,0);
        __m128 ax = _mm_mul_ps(_mm_load_ps(rows),x);
        __m128 y = _mm_shuffle_ps(input.v,input.v,0x55);
        __m128 ay = _mm_mul_ps(_mm_load_ps(rows+4),y);
        __m128 z = _mm_shuffle_ps(input.v,input.v,0xaa);
        __m128 az = _mm_mul_ps(_mm_load_ps(rows+8),z);
        v = _mm_add_ps(_mm_add_ps(ax,ay),az);
    }
    void cross(const D22260_Math& a, const D22260_Math& b) {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(a.v,a.v,0xc9), _mm_shuffle_ps(b.v,b.v,0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(a.v,a.v,0xd2), _mm_shuffle_ps(b.v,b.v,0xc9));
        v = _mm_sub_ps(positive,negative);
    }
    void add(const D22260_Math& a) { v = _mm_add_ps(v,a.v); }
};

}  // namespace fnv_00d22260

// FUN_00d24650 - __stdcall function, callee pops 4 bytes (1 stack parameter)
// @fnv 0x00d24650
// pdb: hkDisplayCylinder::getWireframeGeometry | hkDisplayCylinder.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void __stdcall FUN_00d24650(int _param) {
}

class hkpCdBody;
class CollisionAgentContext;

// Explicit layout of the audited collector objects; table objects stay external.
struct hkpCdBodyPairCollector {
    const void* unk00;
    unsigned char unk04;
};
struct hkpSymmetricAgentFlipBodyCollector : hkpCdBodyPairCollector {
    hkpCdBodyPairCollector* unk08;
};
class hkpListAgent {
public:
    void FUN_00d36b00(const hkpCdBody&, const hkpCdBody&,
                     const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
template<class Agent> class hkpSymmetricAgent : public Agent {
public:
    void FUN_00d36d20(const hkpCdBody&, const hkpCdBody&,
                     const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
// Swaps the two hkpCdBody arguments and forwards them to hkpListAgent::FUN_00d36b00 via a hkpSymmetricAgentFlipBodyCollector.
// @fnv 0x00d36d20
// pdb: hkpSymmetricAgentLinearCast<hkpListAgent>::getPenetrations | hkpListAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector
template<> void hkpSymmetricAgent<hkpListAgent>::FUN_00d36d20(
    const hkpCdBody& a, const hkpCdBody& b,
    const CollisionAgentContext& input, hkpCdBodyPairCollector& output)
{
    hkpSymmetricAgentFlipBodyCollector collector;
    collector.unk08 = &output;
    collector.unk04 = 0;
    collector.unk00 = &DAT_010ce81c;
    hkpListAgent::FUN_00d36b00(b, a, input, collector);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);

extern volatile float DAT_01012054;

struct Body11
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
};

class __declspec(align(16)) FUN_00d01a60
{
public:
    Body11 m_kCollisionBody;
    float m_unk2C;
    FUN_00d01a60();
};

struct __declspec(align(16)) V4q
{
    int m0;
    int m1;
    int m2;
    int m3;
};

struct A1Rec
{
    void* unk00;
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
    V4q unk70;
};

struct BroadPhaseHandle
{
    int unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
    int unk1C;
    __forceinline void SetOwnerPointer(void* owner)
    {
        unk19 = (unsigned char)((unsigned int)owner - (unsigned int)this);
    }
};
struct __declspec(align(16)) ZT
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned short unk12;
    BroadPhaseHandle handle;
    __forceinline ZT()
    {
        unk00 = 0;
        unk08 = 0;
        unk0C = 0;
        unk04 = -1;
        unk10 = 0;
        handle.unk14 = 0;
        handle.unk18 = 0;
        handle.unk1C = 0;
        handle.unk1A = 0xff;
        handle.unk19 = 0x7f;
    }
};

struct CollidableBuffer
{
    ZT z;
    FUN_00d01a60 o40;
    __forceinline CollidableBuffer()
    {
        o40.m_unk2C = DAT_01012054;
        z.handle.SetOwnerPointer(&z);
        z.unk11 = 0;
        z.unk12 = 0;
    }
};

struct __declspec(align(16)) O1T
{
    void* FUN_00d33260(A1Rec* a1);
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
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
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

struct __declspec(align(16)) CF56Obj
{
    void* FUN_00cf5640(int* c, int b, void* a);
    void* unk00;
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
};

class FUN_00cf5640
{
public:
    FUN_00cf5640(int* name, int count, void* extra);
    virtual ~FUN_00cf5640();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int r18_00;
    int r18_04;
    int r18_08;
};

__declspec(noinline) void __cdecl hkpListAgent_initAgentFunc(void* apObject);

__declspec(noinline) void __cdecl FUN_00d36bb0(CollisionAgentFunctionTable* f)
{
    f->a = (void*)(void (__cdecl*)())&FUN_00d36b70;
    f->b = (void*)&FUN_00d34790;
    f->c = (void*)(void (__cdecl*)())&QueryClosestPoints;
    f->d = (void*)&FUN_00d34810;
    f->e = 0;
    f->f = 1;
}

// Fills a function table via hkpListAgent_initAgentFunc and passes it to agent->FUN_00cfbbe0 with (9, -1), then refills via FUN_00d36bb0 and passes it with (-1, 9).
// @f3 0x009bf1b0 (community match, verified in this file)
// pdb: hkpListAgent::registerAgent | hkpListAgent.obj | fnv360_0822_retail, objrun + bridge(caller_sim|objrun) + skyrim(caller_sim), high
void __cdecl hkpListAgent_registerAgent(void* apAgent)
{
    CollisionAgentFunctionTable funcs;
    CollisionAgentFunctionTable* table = &funcs;

    funcs.e = 0;
    funcs.f = 0;
    hkpListAgent_initAgentFunc(table);

    Agent* agent = (Agent*)apAgent;
    agent->FUN_00cfbbe0(table, 10, -1);

    funcs.e = 0;
    funcs.f = 0;
    FUN_00d36bb0(table);

    agent->FUN_00cfbbe0(table, -1, 10);
}

// @f3 0x009b7f40 (community match, verified in this file)
namespace f3m_009b7f40 {
// 0x009b7f40: hkpBvTreeAgent::defaultAgentCreate of Havok 5.5.0 (hkpCollide, hkpBvTreeAgent.cpp): the agent for the
// pair comes from the collision dispatcher's table (hkpCollisionDispatcher::getNewCollisionAgent and
// getCollisionAgentCreationFunction, inline in hkpCollisionDispatcher.inl; their asserts are compiled out). The
// declarations are the SDK's (hkpBvTreeAgent.h, hkpCollisionDispatcher.h, hkpCollisionInput.h, hkpCdBody.h,
// hkpShape.h), cut down to what the function reads; the class carries the packet's name for the member.
namespace f3m_009b7f40 {

typedef float hkReal;
typedef int hkpShapeType;

class hkpCollisionAgent;
class hkpContactMgr;
class hkpContactMgrFactory;
struct hkpCollisionInput;

class hkReferencedObject
{
	public:
		virtual ~hkReferencedObject();

		unsigned short m_memSizeAndFlags;
		short m_referenceCount;
};

class hkpShape : public hkReferencedObject
{
	public:
		hkpShapeType getType() const { return m_type; }

		unsigned long m_userData;
		hkpShapeType m_type;
};

class hkpCdBody
{
	public:
		const hkpShape* getShape() const { return m_shape; }

		const hkpShape* m_shape;
		unsigned int m_shapeKey;
		const void* m_motion;
		const hkpCdBody* m_parent;
};

class hkpCollisionDispatcher : public hkReferencedObject
{
	public:
		enum IsAgentPredictive { IS_NOT_PREDICTIVE = 0, IS_PREDICTIVE = 1 };

		typedef hkpCollisionAgent* (__cdecl *CreateFunc)( const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& env, hkpContactMgr* mgr );

		struct AgentFuncs
		{
			CreateFunc m_createFunc;
			void* m_getPenetrationsFunc;
			void* m_getClosestPointsFunc;
			void* m_linearCastFunc;
			bool m_isFlipped;
			bool m_isPredictive;
		};

		CreateFunc getCollisionAgentCreationFunction( hkpShapeType typeA, hkpShapeType typeB, IsAgentPredictive predictive ) const
		{
			int idx = ( predictive ? m_agent2TypesPred : m_agent2Types )[typeA][typeB];
			return m_agent2Func[idx].m_createFunc;
		}

		inline hkpCollisionAgent* getNewCollisionAgent( const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& environment, hkpContactMgr* mgr ) const;

		CreateFunc m_defaultCollisionAgent;
		hkpContactMgrFactory* m_contactMgrFactory[8][8];
		__declspec(align(16)) unsigned int m_hasAlternateType[32];
		int m_numAgent2Types;
		__declspec(align(16)) unsigned char m_agent2Types[32][32];
		unsigned char m_agent2TypesPred[32][32];
		AgentFuncs m_agent2Func[64];
};

struct hkpCollisionInput
{
	hkpCollisionDispatcher* m_dispatcher;
	hkReal m_tolerance;
	const void* m_filter;
	const void* m_convexListFilter;
	int m_createPredictiveAgents;
};

hkpCollisionAgent* hkpCollisionDispatcher::getNewCollisionAgent( const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& environment, hkpContactMgr* mgr ) const
{
	const hkpShapeType typeA = collA.getShape()->getType();
	const hkpShapeType typeB = collB.getShape()->getType();

	hkpCollisionDispatcher::IsAgentPredictive predictive = static_cast<hkpCollisionDispatcher::IsAgentPredictive>( environment.m_createPredictiveAgents );
	CreateFunc f = getCollisionAgentCreationFunction( typeA, typeB, predictive );

	return f( collA, collB, environment, mgr );
}

class hkpBvTreeAgent
{
	public:
		static hkpCollisionAgent* __cdecl FUN_009b7f40( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
};

// pdb: hkpBvTreeAgent::defaultAgentCreate | hkpBvTreeAgent.obj | tesv_win, objrun, medium
hkpCollisionAgent* __cdecl hkpBvTreeAgent::FUN_009b7f40( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr )
{
	return input.m_dispatcher->getNewCollisionAgent( bodyA, bodyB, input, mgr );
}

}
}   // namespace f3m_009b7f40

// @f3 0x009b7ef0 (community match, verified in this file)
namespace f3m_009b7ef0 {
struct S009b7ef0_Target {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void Update(float a, float b, int c);
};
struct S009b7ef0_Entry {
    int unk00;
    int unk04;
    S009b7ef0_Target* m_pTarget;
};
template <class T> struct S009b7ef0_Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    T* begin() const { return m_data; }
    T* end() const { return m_data + m_size; }
    int getSize() const { return m_size; }
    T& operator[](int i) { return m_data[i]; }
};
struct S009b7ef0_Owner {
    int unk00;
    int unk04;
    int unk08;
    S009b7ef0_Array<S009b7ef0_Entry> m_entries;
    void hkpBvTreeAgent_warpTime(float a, float b, int c);
};
// pdb: hkpBvTreeAgent::warpTime | hkpBvTreeAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S009b7ef0_Owner::hkpBvTreeAgent_warpTime(float a, float b, int c)
{
    S009b7ef0_Entry* p = m_entries.begin();
    S009b7ef0_Entry* pEnd = m_entries.end();
    for (; p != pEnd; ++p) {
        if (p->m_pTarget)
            p->m_pTarget->Update(a, b, c);
    }
}
}   // namespace f3m_009b7ef0
