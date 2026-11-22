// havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp: QhkVector4, BigSolver, BoundsMesh, TriangleChecker and more (32 functions)
#include "f3_common.h"
#include "fnv_asm_helpers.h"
// SSE_DECLARATIONS_DEFER_TO_SDK
// src/havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/mesh/hkgpmesh.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Deallocate(void*);

void __cdecl ProcessEntries();
void __cdecl FUN_00e23a10();

struct Subobject { virtual void Release(unsigned int flags); };
struct FUN_00e114c0_Class {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; Subobject* unkE4;
    void ReleaseSubobject();
};
// Releases the subobject held in unkE4 with flag 1 if present, then clears the pointer.
// @f3 0x005870e0 (community match, verified in this file)
// pdb: BSFaceGenAnimationData::ClearExpressionTarget | BSFaceGenAnimationData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void FUN_00e114c0_Class::ReleaseSubobject() {
    if (unk0c)
        ((Subobject*)unk0c)->Release(1);
    unk0c = 0;
}


struct __declspec(align(16)) S_00e120e0_Vec
{
    float x;
    float y;
    float z;
    float w;
    float x2;
    float y2;
    float z2;
    float w2;
};
struct S_00e120e0_Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00e120e0_Vec GetData();
};
struct S_00e120e0_Collector
{
    float m_fValue;
    int m_iFilter;
    S_00e120e0_Shape* m_pShape;
    bool m_bHit;
    bool m_bFlag;
    S_00e120e0_Collector(float fValue, int iFilter, S_00e120e0_Shape* pShape, bool bFlag)
        { m_fValue = fValue; m_iFilter = iFilter; m_bHit = false; m_pShape = pShape; m_bFlag = bFlag; }
    virtual void Add();
};
void __cdecl FUN_00d1d570(void* pWorld, const S_00e120e0_Vec& kData, S_00e120e0_Collector* pCollector);

struct E122D0Face {
    E122D0Face* m_next;
    int unk04;
    int m_kVertices[3];
};

struct E122D0Edge {
    E122D0Face* m_face;
    int m_uiEdgeIndex;

    E122D0Edge() {}
    E122D0Edge(E122D0Face* face, int index) : m_face(face), m_uiEdgeIndex(index) {}
};

struct Allocator { virtual void v00(); virtual void* allocate(int); virtual void v08(); virtual void v0c(); __declspec(nothrow) virtual void freeBlock(void*,int); };
struct Router {int unk00,unk04,unk08,unk0c; Allocator* heap; Allocator& getHeap() {return *heap;} };
__declspec(nothrow) Router& __cdecl FUN_00c85750();
struct FourFloatVector {float x,y,z,w;};
struct VectorArray {FourFloatVector* data; int size; int capacity;
 VectorArray():data(0),size(0),capacity(0x80000000) {}
 void release(Allocator& heap) {size=0; if(!(capacity&0x80000000)) heap.freeBlock(data,(capacity&0x3fffffff)*16);}
 
};
struct Options {unsigned int unk00,unk04; unsigned char flag08,flag09,flag0a,flag0b; unsigned int unk0c; __declspec(nothrow) void FUN_00d74d40();};
struct FUN_00d76ca0 {__declspec(nothrow) virtual ~FUN_00d76ca0(); unsigned short memorySize,referenceCount; int unk08,unk0c,unk10;
 __declspec(nothrow) FUN_00d76ca0();
 static void* allocate(Allocator& heap,unsigned int bytes) { void* memory=heap.allocate(bytes); ((FUN_00d76ca0*)memory)->memorySize=(unsigned short)bytes; return memory;}
 static void* operator new(unsigned int bytes) {return allocate(FUN_00c85750().getHeap(),bytes);}
 __declspec(nothrow) void FUN_00d771c0(FourFloatVector*,int,const Options&);
 __declspec(nothrow) int FUN_00d74e10();
};

void __cdecl __debugbreak();
struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
    void FUN_00cb1600(char*, unsigned int);
    CharBuffer* FUN_00cc01c0(const char*);
    CharBuffer* WriteInt(int);
    void FUN_00cc00e0();
};
struct ErrorReporter
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual int Report(int, unsigned int, const char*, const char*, int);
};
extern ErrorReporter* DAT_01268360;

extern int DAT_01268370;

struct ArrayHeader {
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ArrayHeader() throw()
        : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {
    }
};

namespace fnv_00e22520 {
struct hkErrorE {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};
extern hkErrorE* DAT_01268360;

}  // namespace fnv_00e22520

struct S_00e22580_Item {
    int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    float m_3c;
};
struct S_00e22580_Tri {
    int unk0;
    int unk4;
    S_00e22580_Item* m_items[3];
};
struct S_00e22580_Wrap {
    S_00e22580_Tri* m_tri;
    S_00e22580_Wrap(S_00e22580_Tri* t) : m_tri(t) {}
    virtual void Dummy();
};

struct StateBlock {
    int unk00;
    int unk04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    unsigned short m_uMode : 3;
    unsigned short m_bFlag : 1;
    unsigned short m_uItemCount : 12;
    unsigned short m_u22;

    StateBlock& FUN_00e23080(const StateBlock& arSource);
};

// @fnv 0x00e23080
StateBlock& StateBlock::FUN_00e23080(const StateBlock& arSource)
{
    m_i08 = arSource.m_i08;
    m_i0c = arSource.m_i0c;
    m_i10 = arSource.m_i10;
    m_i14 = arSource.m_i14;
    m_i18 = arSource.m_i18;
    m_i1c = arSource.m_i1c;
    m_uMode = arSource.m_uMode;
    m_bFlag = arSource.m_bFlag;
    m_uItemCount = arSource.m_uItemCount;
    m_u22 = arSource.m_u22;
    return *this;
}

namespace fnv_00e234e0 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct FUN_00e234e0_cls {
    void** m_ppItems;
    int m_iArrayLength;
    int unk08;
    int m_i0c;
    int m_i10;
    void FreeAllItems();
};

}  // namespace fnv_00e234e0

namespace fnv_00e23670 {
struct S_e23670_Alloc {
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct S_e23670_Router {
    int unk0; int unk4; int unk8; int unkC;
    S_e23670_Alloc* m_pStreamAllocator;
    S_e23670_Alloc& heap() { return *m_pStreamAllocator; }
};
S_e23670_Router* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(S_e23670_Alloc* alloc, void* arr, int elemSize);

struct S_e23670_Elem {
    S_e23670_Elem* m_next;
    int unk4; int unk8; int unkC; int unk10;
};
struct S_e23670_Block {
    S_e23670_Elem m_pElements[32];
    S_e23670_Elem* m_free;
    int m_iAllocatedCount;
};
struct S_e23670 {
    S_e23670_Block** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_e23670_Block* FUN_00e23670();
};

// Allocates a block from the heap, links its 32 elements into a free list, grows m_data if full, stores the block and swaps it with the first slot.
// @fnv 0x00e23670
S_e23670_Block* S_e23670::FUN_00e23670()
{
    S_e23670_Alloc& heap = FUN_00c85750()->heap();
    S_e23670_Elem* next = 0;
    S_e23670_Block* b = (S_e23670_Block*)heap.AllocateMemoryBlock(sizeof(S_e23670_Block));
    S_e23670_Elem* e;
    for (int i = 31; i >= 0; i--) {
        e = &b->m_pElements[i];
        e->m_next = next;
        next = e;
    }
    b->m_iAllocatedCount = 0;
    b->m_free = e;
    S_e23670_Alloc& alloc = FUN_00c85750()->heap();
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, this, sizeof(S_e23670_Block*));
    S_e23670_Block** p = m_data + m_iElementCount;
    for (int k = 0; k < 1; k++)
        p[k] = b;
    m_iElementCount++;
    if (m_iElementCount > 1) {
        S_e23670_Block* tmp = m_data[0];
        m_data[0] = m_data[m_iElementCount - 1];
        m_data[m_iElementCount - 1] = tmp;
    }
    return b;
}
}  // namespace fnv_00e23670

namespace fnv_00e23860 {
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct BSAudio {
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap() { return *unk10; }
};

BSAudio* FUN_00c85750();

inline void freeBlock(void* p)
{
    FUN_00c85750()->heap().ReleaseBlock(p, 0xa08);
}

struct hkArrayPtr {
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void clear() { m_iElementCount = 0; }
    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(void*));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    void FreeAllBlocks();
};

}  // namespace fnv_00e23860

namespace fnv_00e239c0 {
struct EntryHandler
{
    virtual void First();
    virtual void Second();
    virtual void Process(void* entry, unsigned int size);
};
struct EntryHandlerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryHandler* handler;
};
EntryHandlerRecord* __cdecl FUN_00c85750();

struct EntryListNode
{
    void** entries;
    int count;
    int unk08;
    int unk0c;
    int unk10;
    void ProcessEntries();
};
// Calls Process on each entry's handler with size 0x288, then resets count, unk0c and unk10 to zero.
// @fnv 0x00e239c0
void EntryListNode::ProcessEntries()
{
    int i = 0;
    while (i < count)
    {
        void* entry = entries[i];
        EntryHandlerRecord* context = FUN_00c85750();
        context->handler->Process(entry, 0x288);
        ++i;
    }
    count = 0;
    unk0c = 0;
    unk10 = 0;
}
}  // namespace fnv_00e239c0

namespace fnv_00e23a60 {
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct BSAudio {
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
};

BSAudio* FUN_00c85750();

struct hkArrayPtr {
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    hkArrayPtr& Assign(const hkArrayPtr& a);
};

}  // namespace fnv_00e23a60

namespace fnv_00e23c70 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiBytes) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct PtrArrayBase {
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayBase() throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_ppData, (uCapacity & 0x3fffffff) * 4);
        m_uCapacity = 0x80000000;
        m_ppData = 0;
    }
};

struct FUN_00e23c70 : PtrArrayBase {
    ~FUN_00e23c70() throw();
};

// Frees each element of the array through the audio allocator, then resets the element count to zero.
// @fnv 0x00e23c70
FUN_00e23c70::~FUN_00e23c70() throw()
{
    for (int i = 0; i < m_iArrayLength; i++) {
        void* pItem = m_ppData[i];
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(pItem, 0x388);
    }
    m_iArrayLength = 0;
}
}  // namespace fnv_00e23c70

namespace fnv_00e23d70 {
struct S_00e23d70_Heap {
    virtual void f0();
    virtual void f1();
    virtual void ReleaseBlock(void* p, int nbytes);
    virtual void f3();
    virtual void ReturnMemory(void* p, int nbytes);
};

struct S_00e23d70_Router {
    int unk0; int unk4; int unk8; int unkC;
    S_00e23d70_Heap* m_pStreamAllocator;
    S_00e23d70_Heap& heap() { return *m_pStreamAllocator; }
};
S_00e23d70_Router* FUN_00c85750();

struct S_00e23d70_Array {
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(S_00e23d70_Heap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(void*));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    void FUN_00e23d70();
};

// @fnv 0x00e23d70
void S_00e23d70_Array::FUN_00e23d70()
{
    for (int i = 0; i < m_iElementCount; i++) {
        void* block = m_data[i];
        FUN_00c85750()->heap().ReleaseBlock(block, 0x488);
    }
    m_iElementCount = 0;
    _clearAndDeallocate(FUN_00c85750()->heap());
}
}  // namespace fnv_00e23d70

struct Node
{
    Node* next;
    Node* previous;
    Node* FUN_00e22ec0(Node* source);
};
struct Manager {};

namespace fnv_00e247c0 {
struct Node {
    Node* f0;
    Node* volatile f4;
    int f8;
    int fC;
    unsigned int f10;
};

struct Pool {
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    Node* f280;
    int f284;
};

struct Manager {
    Pool* f0;
};

struct SelfCls {
    Manager* field00;
    int field04;
    int field08;
    Node* field0C;
    unsigned int field10;

    Pool* FUN_00e23670();
    Node* FUN_00e247c0(Node* src);
};

// Takes a node from the pool (or a fresh one), copies f8/fC/f10 from src, clears f4, links it at the head of the list via field0C, and returns it.
// @fnv 0x00e247c0
Node* SelfCls::FUN_00e247c0(Node* apSource) {
    Pool* p;
    if (this->field04 == 0 || this->field00->f0->f280 == 0)
        p = this->FUN_00e23670();
    else
        p = this->field00->f0;

    Node* n = p->f280;
    Node* nx = n->f0;
    p->f284++;
    p->f280 = nx;

    n->f8 = apSource->f8;
    n->fC = apSource->fC;
    n->f10 = (n->f10 & ~1u) | (apSource->f10 & 1u);
    n->f10 = (apSource->f10 & ~1u) | (n->f10 & 1u);
    n->f4 = 0;
    n->f0 = this->field0C;
    if (this->field0C)
        this->field0C->f4 = n;
    this->field10++;
    this->field0C = n;
    return n;
}
}  // namespace fnv_00e247c0

namespace fnv_00e24f70 {
struct CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00e24f70

struct S_00e25f00_Alloc {
    virtual ~S_00e25f00_Alloc();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void* AllocateBufferWithSize(int& n);
    virtual void ReturnMemory(void* p, int n);
};
struct S_00e25f00_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e25f00_Alloc* m_pStreamAllocator;
    S_00e25f00_Alloc& heap() { return *m_pStreamAllocator; }
    static S_00e25f00_Router& GetMonitorStream();
};

template <typename T>
struct S_00e25f00_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~S_00e25f00_Array() throw() { _clearAndDeallocate(S_00e25f00_Router::GetMonitorStream().heap()); }

    static __forceinline void destruct(T* p, int n) throw()
    {
        for (int i = 0; i < n; i++)
            p[i].~T();
    }
    __forceinline void clear() throw()
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(S_00e25f00_Alloc& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct S_00e25f00_Elem {
    int unk0;
    int unk4;
    int unk8;
};

struct S_00e25f00 {
    S_00e25f00_Array<S_00e25f00_Array<S_00e25f00_Elem> > m_arrays;
    int unkC;
    S_00e25f00* FUN_00e25f00(unsigned int flags);
};

// @fnv 0x00e25f00
S_00e25f00* S_00e25f00::FUN_00e25f00(unsigned int flags)
{
    m_arrays._clearAndDeallocate(S_00e25f00_Router::GetMonitorStream().heap());
    if (flags & 1)
        S_00e25f00_Router::GetMonitorStream().heap().ReleaseBlock(this, sizeof(S_00e25f00));
    return this;
}

// ---------------------------------------------------------------------------
// hkgpMesh::IConvexOverlap - accessor for the hull the overlap was built for.
//
// The object is the Havok side of a convex hull overlap query.  It starts with
// its virtual table, keeps the list of hull vertices at offset 0x14 and the
// hkgpConvexHull the overlap belongs to at offset 0xe4.  The function simply
// hands that hull back to the caller.
// ---------------------------------------------------------------------------

// The hull the overlap was built from (defined in the game side code).
struct hkgpConvexHull;

struct hkgpMesh_IConvexOverlap {
    void** vftable;                 // 0x00
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* pVertexList;              // 0x14  linked list of the hull vertices
    int unk18;                      // 0x18  number of vertices of the hull
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* pVertexList2;             // 0x2c
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    hkgpConvexHull* pConvexHull;    // 0xe4  the hull this overlap belongs to

    hkgpConvexHull* hkpRagdollConstraintData_getPlaneMotor();
};

// @fnv 0x00e114a0
// pdb: hkpRagdollConstraintData::getPlaneMotor | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
hkgpConvexHull* hkgpMesh_IConvexOverlap::hkpRagdollConstraintData_getPlaneMotor()
{
    return pConvexHull;
}

struct DataBlock_00e118e0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char data;
};

struct Inputs_00e118e0
{
    unsigned int unk00;
    unsigned int unk04;
    DataBlock_00e118e0* first;
    DataBlock_00e118e0* second;
    DataBlock_00e118e0* third;
};

struct FUN_00e118e0_class
{
    void __thiscall FUN_00e11710(void*, void*, void*, void*, void*);
    void __thiscall FUN_00e118e0(const volatile Inputs_00e118e0*, void*, void*);
};

// Passes the data pointers of the first, second and third input blocks to FUN_00e11710 along with argument2 and argument3.
// @fnv 0x00e118e0
void FUN_00e118e0_class::FUN_00e118e0(
    const volatile Inputs_00e118e0* inputs, void* argument2, void* argument3)
{
    DataBlock_00e118e0* third = inputs->third;
    DataBlock_00e118e0* second = inputs->second;
    DataBlock_00e118e0* first = inputs->first;
    FUN_00e11710(&first->data, &second->data,
        &third->data, argument2, argument3);
}

struct E12160Vertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vContactPosition[4];
};

struct E12160Triangle {
    int unk00;
    int unk04;
    E12160Vertex* m_kVertices[3];
};

struct ListNode {
    ListNode* m_pNext;
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
    int m_i34;
};

// Walks the linked list from m_pHead and replaces every node's m_i34 equal to oldValue with newValue.
// @f3 0x00736dc0 (community match, verified in this file)
namespace f3m_00736dc0 {
struct S_736dc0_Rec
{
    int m_iValue;
    int unk04;
};

struct S_736dc0_Node
{
    S_736dc0_Rec* m_pRec;
    S_736dc0_Node* m_pNext;
};

struct FUN_736dc0_cls
{
    int unk00[0x254 / 4];
    S_736dc0_Node* m_pList0;
    S_736dc0_Node* m_pList1;

    S_736dc0_Rec* FUN_00736dc0(int oldValue, int newValue);
};

// pdb: HighProcess::GetDetectionState | HighProcess.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apActor, abWhichList
S_736dc0_Rec* FUN_736dc0_cls::FUN_00736dc0(int oldValue, int newValue)
{
    S_736dc0_Rec* found = 0;
    S_736dc0_Node* rec = (newValue == 0) ? m_pList0 : m_pList1;
    while (rec)
    {
        S_736dc0_Rec* node = rec->m_pRec;
        if (node == 0)
            break;
        if (found)
            break;
        if (node->m_iValue == oldValue)
            found = node;
        rec = rec->m_pNext;
    }
    return found;
}
}   // namespace f3m_00736dc0


typedef unsigned int hkUint32;

struct S_00e13910_Triangle {
    int m_unk00;
    int m_unk04;
    void* m_kVertices[3];
    hkUint32 m_ppLinks[3];
};

struct S_00e13910_Edge {
    S_00e13910_Triangle* m_pkTriangle;
    hkUint32 m_uiEdgeIndex;

    S_00e13910_Edge() : m_pkTriangle(0), m_uiEdgeIndex(0) {}
    S_00e13910_Edge(S_00e13910_Triangle* t, hkUint32 i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    S_00e13910_Edge(hkUint32 l) {
        m_uiEdgeIndex = l & 3u;
        m_pkTriangle = (S_00e13910_Triangle*)(l & ~3u);
    }

    __forceinline bool isValid() const {
        return m_pkTriangle != 0;
    }

    __forceinline S_00e13910_Edge next() const {
        return S_00e13910_Edge(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3);
    }

    __forceinline S_00e13910_Edge prev() const {
        return S_00e13910_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3);
    }

    __forceinline S_00e13910_Edge link() const {
        hkUint32 l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        return S_00e13910_Edge(l);
    }

    __forceinline void*& start() const {
        return m_pkTriangle->m_kVertices[m_uiEdgeIndex];
    }

    __forceinline void*& apex() const {
        return prev().start();
    }

    __forceinline void bind(const S_00e13910_Edge& other) const {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.m_uiEdgeIndex + (hkUint32)other.m_pkTriangle;
        if (other.m_pkTriangle) {
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = m_uiEdgeIndex + (hkUint32)m_pkTriangle;
        }
    }

    static __forceinline S_00e13910_Edge null() {
        static S_00e13910_Edge n(0, 0);
        return n;
    }
};

namespace fnv_00e14fa0 {
struct ListNode {
    ListNode* m_pNext;
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
    int m_iKey;
};

}  // namespace fnv_00e14fa0

// CreateTriangle (0x00e19cf0, 101 bytes)
//
//   push ebp / mov ebp,esp / and esp,-16 / sub esp,0x54
//   push ebx / push esi / push edi
//   mov  edi, ecx
//   lea  eax, [esp+0x10]          ; the 16-byte aligned local HullTriangle
//   push eax
//   lea  ecx, [edi+0x20]          ; the pool at this+0x20
//   call 0xe241a0                 ; pool->FUN_00e241a0(&local)
//   ...
//   mov  [esi+0x30], 0xffffffff   ; t->m_30 = -1
//   mov  [esi+0x14], eax          ; t->m_14 = 0   (eax = the zero register)
//   mov  [esi+0x18], eax          ; t->m_18 = 0
//   mov  [esi+0x1c], eax          ; t->m_1C = 0
//   mov  eax, [ebp+8]
//   push 1
//   mov  [esi+0x10], edx          ; t->m_10 = c
//   ...
//   call 0xe11710                 ; FUN_00e11710(a->pos,b->pos,c->pos,&t->m_20,1)
//
// The three zero stores go through a VOLATILE POINTER (not a volatile cast of
// the member): that is what keeps the zero register (xor eax,eax) and the
// `push 1` of the last argument in the original's positions - a plain or
// cast-volatile store lets MSVC hoist the constant push above the stores and
// lets the -1 store sink down to the call.

struct __declspec(align(16)) HullPlane {
    float v[4];
};

struct HullVertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float pos[4];
};

struct __declspec(align(16)) HullTriangle {
    int unk00;
    int unk04;
    HullVertex* m_08;
    HullVertex* m_0C;
    HullVertex* m_10;
    int m_14;
    int m_18;
    int m_1C;
    HullPlane m_20;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

extern "C" double __cdecl sqrt(double);
extern int DAT_010eb000;

class E21CE0Ostream {
public:
    E21CE0Ostream(void* buf, int bufSize);
    E21CE0Ostream& operator<<(const char* str);
    // hkOstream destructor body (Havok was built without EH): called explicitly
    void destroy();

    int unk00;
    int unk04;
    int unk08;
};

struct VecData;
struct Components { int x,y,z,w; void copy(const VecData* from); };
struct VecData { int unk00,unk04,unk08,unk0c,x,y,z,w; };
struct Triple { Components first,second,third; };
int __cdecl FUN_00deab10(void*,const Triple*);

struct FUN_00e22970_Item {
    int m_data[12];
};

struct FUN_00e22970_Cls {
    FUN_00e22970_Item* m_pItems;
    int m_uiItemCount;
    int m_pRayCursor;

    void AppendItems(void* apArg1, const FUN_00e22970_Item* apSrc, int aCount);
};

void __cdecl FUN_00c908c0(void* apArg1, FUN_00e22970_Cls* apThis, int aCapacity, int aElemSize);

struct FUN_00e229f0_cls {
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;

    void AppendInts(int a1, int* a2, int a3);
};

void __cdecl FUN_00c908c0(int a1, void* self, int newCap, int elemSize);

// Grows the buffer if needed, copies a3 ints from a2 to the end, and updates the count.
// @fnv 0x00e229f0
void FUN_00e229f0_cls::AppendInts(int a1, int* pSource, int iCount)
{
    int newSize = m_uiItemCount + iCount;
    unsigned int cap = m_capBits & 0x3fffffffu;
    if ((int)cap < newSize) {
        int newCap = (int)(cap + cap);
        if (newSize >= newCap) newCap = newSize;
        FUN_00c908c0(a1, this, newCap, 4);
    }
    int* dst = m_data + m_uiItemCount;
    if (iCount > 0) {
        int delta = (int)pSource - (int)dst;
        int n = iCount;
        do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n != 0);
    }
    m_uiItemCount = newSize;
}

extern unsigned int DAT_01267e30;
extern float DAT_0104da48;
extern unsigned int DAT_0126ebf0;
extern unsigned int DAT_0126ebe8;
extern unsigned int DAT_0126ebec;

struct PoolNode;

struct PoolNode
{
    PoolNode* m_00;
    PoolNode* m_04;

    PoolNode* FUN_00e22f20(void* value);
};

struct FreeCtx
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    PoolNode* m_a00;
    int m_a04;
};

struct Holder
{
    FreeCtx* m_00;
};

FreeCtx* __cdecl FUN_00e23530(void);

extern "C" void _ReadWriteBarrier(void);

struct E24850Element {
    E24850Element* m_next;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct E24850Block {
    E24850Element m_elements[32];
    E24850Element* m_firstFree;
    int m_iAllocatedCount;

    void* allocate()
    {
        E24850Element* e = m_firstFree;
        m_firstFree = e->m_next;
        m_iAllocatedCount++;
        return e;
    }
};

struct E24850Node {
    E24850Node* m_next;
    E24850Node* m_pSecondNode;

    static void* operator new(unsigned int, void* p) { return p; }
    E24850Node(void* data);
};

struct E24850List {
    E24850Block** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    E24850Node* m_pFirstNode;
    int m_iNodeCount;

    E24850Block* addBlock();
    E24850Node* FUN_00e24850(void* data);
};

// @fnv 0x00e24850
E24850Node* E24850List::FUN_00e24850(void* data)
{
    E24850Block* block;
    if (m_iBlockCount == 0 || (block = m_kBlocks[0])->m_firstFree == 0)
        block = addBlock();
    E24850Node* node = new (block->allocate()) E24850Node(data);
    node->m_pSecondNode = 0;
    node->m_next = m_pFirstNode;
    if (m_pFirstNode)
        m_pFirstNode->m_pSecondNode = node;
    m_iNodeCount++;
    m_pFirstNode = node;
    return node;
}

// Text writer: format an integer into a scratch buffer and write it to the stream.

int __cdecl CC0280Format(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);

class CC0280Stream {
public:
    virtual void Unk_00();
    virtual int Write(const void* pvData, int iSize);
};

// File-static helper (reconstructed separately); MSVC passes its arguments in registers.
static __declspec(noinline) void CC0280WriteString(CC0280Stream* pkStream, const char* pcText)
{
    int iLen = 0;
    while (pcText[iLen])
        iLen++;
    pkStream->Write(&iLen, 4);
    if (iLen > 0)
        pkStream->Write(pcText, iLen);
}

class CC0280Writer {
public:
    int unk00;
    int unk04;
    CC0280Stream* m_pDataStream;

    CC0280Writer& WriteInt(int iValue);
};

// Formats iValue as a decimal string into a stack buffer and writes it to the stream via CC0280WriteString, returning *this.
// @fnv 0x00cc0280
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, call_seq, high
// pdb params: i
CC0280Writer& CC0280Writer::WriteInt(int iValue)
{
    // Word-typed scratch buffer (this Havok code was built without /GS, so no cookie on the stack buffer).
    unsigned int auiBuffer[0x2728 / 4];
    char* pcBuffer = (char*)auiBuffer;
    CC0280Format(pcBuffer, sizeof(auiBuffer), "%i", iValue);
    CC0280WriteString(m_pDataStream, pcBuffer);
    return *this;
}

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

struct BSAudio;
namespace fnvc_adapt { BSAudio* __cdecl FUN_00c85750(); }

extern int DAT_010eb000;
extern int DAT_010eaf50;
extern int DAT_0102e388;

namespace fnv_00e21e00 {

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt { AudioHolder* __cdecl FUN_00c85750() throw(); }

}  // namespace fnv_00e21e00

namespace fnv_00e22d80 {
extern int DAT_010cd664;

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt { AudioHolder* __cdecl FUN_00c85750() throw(); }

}  // namespace fnv_00e22d80

namespace fnv_00e23710 {
struct S_00e23710_Heap {
    virtual void slot0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00e23710_Router {
    int unk00; int unk04; int unk08; int unk0c;
    S_00e23710_Heap* m_pStreamAllocator;
    S_00e23710_Heap& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt { S_00e23710_Router* FUN_00c85750(); }
void ResizeAudioStream(S_00e23710_Heap& heap, void* arr, int elemSize);

struct S_00e23710_Elem {
    S_00e23710_Elem* next;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
};
struct S_00e23710_Block {
    S_00e23710_Elem elems[32];
    S_00e23710_Elem* freeList;
    int used;
};

struct S_00e23710_Array {
    S_00e23710_Block** m_data;
    int m_iElementCount;
    int m_cap;
    S_00e23710_Block* FUN_00e23710();
};

// Allocates a block from the heap, links its 32 elements into a free list, grows the array if full, stores the block and returns it.
// @fnv 0x00e23710
S_00e23710_Block* S_00e23710_Array::FUN_00e23710()
{
    S_00e23710_Heap& heap = fnvc_adapt::FUN_00c85750()->heap();
    S_00e23710_Elem* prev = 0;
    S_00e23710_Block* block = (S_00e23710_Block*)heap.AllocateMemoryBlock(sizeof(S_00e23710_Block));
    for (int i = 31; i >= 0; i--) {
        S_00e23710_Elem* e = &block->elems[i];
        e->next = prev;
        prev = e;
    }
    block->used = 0;
    block->freeList = prev;

    S_00e23710_Router* r = fnvc_adapt::FUN_00c85750();
    if (m_iElementCount == (m_cap & 0x3fffffff))
        ResizeAudioStream(r->heap(), this, 4);
    S_00e23710_Block** p = m_data + m_iElementCount;
    for (int k = 0; k < 1; k++) p[k] = block;
    m_iElementCount++;
    if (m_iElementCount > 1) {
        S_00e23710_Block* t = m_data[0];
        m_data[0] = m_data[m_iElementCount - 1];
        m_data[m_iElementCount - 1] = t;
    }
    return block;
}
}  // namespace fnv_00e23710

namespace fnv_00e23af0 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeSized(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt { AudioHolder* __cdecl FUN_00c85750() throw(); }

struct FUN_00e23af0_cls {
    void* m_pData;
    unsigned int m_uCount;
    unsigned int m_uiObjectFlags;

    FUN_00e23af0_cls* ClearAndFree(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00e23af0

namespace fnv_00e23b50 {
extern "C" void* DAT_010eaf50;
extern "C" void* DAT_0102e388;

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt { AudioHolder* __cdecl FUN_00c85750() throw(); }

struct SpawnedSub {
    void** m_ppItems;
    int m_iArrayLength;
    int unk08;
    int m_i0c;
    int m_i10;
    int unk14;

    void FreeAllItems();
    void FreeAllBlocks();
};

struct FUN_00e234e0_cls {
    void** m_ppItems;
    int m_iArrayLength;
    int unk08;
    int m_i0c;
    int m_i10;
    int unk14;

    void FreeAllItems();
    void FreeAllBlocks();
};

struct SpawnedObject {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    FUN_00e234e0_cls m_sub08;
    SpawnedSub m_sub20;

    SpawnedObject* DestroySpawnedObject(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Resets the vtable, tears down both sub-objects, and if acFlags has bit 0 set, frees this object through the audio allocator.
// @fnv 0x00e23b50
SpawnedObject* SpawnedObject::DestroySpawnedObject(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010eaf50;
    m_sub20.FreeAllItems();
    m_sub20.FreeAllBlocks();
    m_sub08.FreeAllItems();
    m_sub08.FreeAllBlocks();
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1) {
        AudioHolder* pHolder = fnvc_adapt::FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00e23b50

namespace fnv_00e23cf0 {
struct FixedAllocator {
    virtual void v00();
    virtual void v04();
    virtual void FreeBlock(void* p, unsigned int size);
    virtual void v0C();
    virtual void FreeArray(void* p, unsigned int size);
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FixedAllocator* m_pAllocator;
};

namespace fnvc_adapt { AllocHolder* FUN_00c85750(); }

struct FUN_00e23cf0_cls {
    void** m_pItems;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ClearAndFreeItems();
};

// Frees each item in m_pItems via the allocator, resets the count, frees the item array, and clears the capacity and pointer.
// @fnv 0x00e23cf0
void FUN_00e23cf0_cls::ClearAndFreeItems()
{
    int i = 0;
    if (i < m_iArrayLength) {
        do {
            void* item = m_pItems[i];
            AllocHolder* holder = fnvc_adapt::FUN_00c85750();
            holder->m_pAllocator->FreeBlock(item, 0x288);
            i++;
        } while (i < m_iArrayLength);
    }

    m_iArrayLength = 0;
    AllocHolder* holder = fnvc_adapt::FUN_00c85750();
    FixedAllocator* alloc = holder->m_pAllocator;
    unsigned int cap = m_uCapBits;
    m_iArrayLength = 0;
    if ((cap & 0x80000000u) == 0) {
        alloc->FreeArray(m_pItems, (cap & 0x3fffffffu) * 4);
    }
    m_uCapBits = 0x80000000u;
    m_pItems = 0;
}
}  // namespace fnv_00e23cf0

namespace fnv_00e24760 {
struct SpawnedAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};

namespace fnvc_adapt { AllocHolder* FUN_00c85750(); }

}  // namespace fnv_00e24760

namespace fnv_00e27df0 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize);
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

namespace fnvc_adapt { AudioHolder* __cdecl FUN_00c85750() throw(); }
extern int DAT_010eb0e0;
extern int DAT_010eb088;
extern int DAT_0102e388;

}  // namespace fnv_00e27df0

// Havok ray/plane-triangle cast step: intersect the cast ray with the triangle's plane, test the hit point
// against the triangle, and keep the closest hit fraction.
#ifndef _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; } __m128;
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ps(const float* p);
#endif
#ifndef _INCLUDED_MM2
extern "C" void _mm_store_ps(float* p, __m128 a);
#endif
#ifndef _INCLUDED_MM2
extern "C" void _mm_store_ss(float* p, __m128 a);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_mul_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
#endif

extern __m128 DAT_010c7160;    // constant vector (zero)

typedef __m128 SimdReal;
static inline float ToReal(SimdReal v) { float f; _mm_store_ss(&f, v); return f; }

struct __declspec(align(16)) Vec4f {
    float v[4];
    __m128 Get() const { return _mm_load_ps(v); }
    void Set(__m128 q) { _mm_store_ps(v, q); }
};
struct TriVertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4f m_vContactPosition;
};
struct CastTri {
    int unk00;
    int unk04;
    TriVertex* m_kVertices[3];
    const Vec4f& GetVertex(int i) const { return m_kVertices[i]->m_vContactPosition; }
    int unk14;
    int unk18;
    int unk1c;
    Vec4f m_kTriangleNormal;
};

static inline SimdReal Dot3(__m128 a, __m128 b)
{
    const __m128 m = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
}

void __cdecl FUN_00cbeb70(void* v, int count, void* p);

typedef unsigned int BufferAddress138;

struct __declspec(align(16)) S_Vec {
    float v[4];
};

namespace fnv_00e11a60 {
struct ListNode;

void __stdcall FUN_00e11910(ListNode* apNode);

struct ListNode {
    ListNode* m_pNext;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_kVector;
};

}  // namespace fnv_00e11a60

struct E11B00Vector4 {
    __m128 m_vComponents;

    void mul4(const E11B00Vector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
};

__declspec(align(16)) struct S_00e12260_Vector4
{
    float x;
    float y;
    float z;
    float w;
    S_00e12260_Vector4() {}
    void operator=(const S_00e12260_Vector4& v)
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v);
    }
};

struct S_00e12260_Aabb
{
    S_00e12260_Vector4 m_kMinimumCorner;
    S_00e12260_Vector4 m_kMaximumCorner;
};

struct S_00e12260_CollectorBase
{
    int m_uiItemCount;
    S_00e12260_CollectorBase() {}
    virtual void AddHit(int hit);
};
struct S_00e12260_Collector : S_00e12260_CollectorBase
{
    S_00e12260_Vector4 m_verts[3];
    S_00e12260_Collector(const S_00e12260_Vector4& a, const S_00e12260_Vector4& b, const S_00e12260_Vector4& c)
    {
        m_uiItemCount = 0;
        m_verts[0] = a;
        m_verts[1] = b;
        m_verts[2] = c;
    }
    virtual void AddHit(int hit);
};

void FUN_00cbeb70(const S_00e12260_Vector4* verts, int numVerts, S_00e12260_Aabb& aabbOut);
void FUN_00d1d570(void* tree, const S_00e12260_Aabb& aabb, S_00e12260_Collector* collector);

namespace fnv_00e12640 {
struct E12640Allocator;

struct E12640MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E12640Allocator* m_pStreamAllocator;

    E12640Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" E12640MemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(E12640Allocator* alloc, void* array, int numElements, int sizeElem);

struct E12640Vector4 {
    __m128 m_vComponents;

    void operator=(const E12640Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct E12640VectorArray {
    E12640Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void GrowArrayCapacity(E12640Allocator& alloc, int n)
    {
        const int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(E12640Vector4));
        }
    }

    E12640Vector4* _expandBy(E12640Allocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
};

}  // namespace fnv_00e12640

namespace fnv_00e136c0 {
// FUN_00e136c0 (134 bytes) - Fallout: New Vegas
//
// The function sums a per-node 3x4 float matrix product over a linked list:
//
//   float FUN_00e136c0_cls::FUN_00e136c0()
//   {
//       float sum = 0.0f;
//       if (this->FUN_00e12920())          // list sanity check
//       {
//           for (ListNode* n = this->m_2c; n; n = n->m_00)
//           {
//               Triple t;                  // 3 x 16 bytes = one 3x4 matrix
//               OutVec  out;
//               t.r0 = n->m_08->m_10;      // three 16-byte vector loads
//               t.r1 = n->m_0c->m_10;
//               t.r2 = n->m_10->m_10;
//               __m128* r = t.FUN_00cd51c0((__m128*)&out);   // matrix * vector
//               float v;
//               _mm_store_ss(&v, *r);
//               sum = sum + v;
//           }
//           sum = (float)(sum / DAT_01034208);   // 1/6.0f
//       }
//       return sum;
//   }
//
// the for-header) makes MSVC 2008 rank the statements the way the original does.
// With `for`, the leaves of the later statements (the two pointer loads
// `mov ecx,[esi+0xc]` / `mov edx,[esi+0x10]`) are hoisted ABOVE the first
// 16-byte store, and the `lea` of the address-taken out-parameter lands BEFORE
// the second 16-byte store - exactly the original's layout. The `do { } while`
// form keeps every store adjacent to its value load and does not match.
//
// The `Triple` matrix and the `OutVec` out-parameter are address-taken locals,
// so the frame layout (0x4c), the aligned prologue and the x87 tail all fall
// out of the source shape.



// A holder object: the three per-node values live in the member at +0x10.
struct VecHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_10;
};

// The 3x4 float matrix that is filled in and then handed to FUN_00cd51c0 as
// `this` (0x30 bytes: three 16-byte rows).
__declspec(align(16)) struct Triple
{
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

    __m128* FUN_00cd51c0(__m128* out);
};

// The 16-byte out-parameter passed on the stack to FUN_00cd51c0.
__declspec(align(16)) struct OutVec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

// One node of the list hanging off this->m_2c.
struct ListNode
{
    ListNode* m_00;          // next
    unsigned int unk04;
    VecHolder* m_08;
    VecHolder* m_0c;
    VecHolder* m_10;
};

}  // namespace fnv_00e136c0

typedef unsigned int HullU32;
struct HullTriAN
{
    HullTriAN* m_next;
    HullTriAN* m_pSecondNode;
    void* m_kVertices[3];
    HullU32 m_ppLinks[3];
};
struct HullEdgeAN
{
    HullTriAN* m_pkTriangle;
    HullU32 m_uiEdgeIndex;
    __forceinline HullEdgeAN(HullU32 l)
    {
        m_uiEdgeIndex = l & 3u;
        m_pkTriangle = (HullTriAN*)(l & ~3u);
    }
    __forceinline bool isValid() const { return m_pkTriangle != 0; }
};
struct HullTriListAN
{
    int unk00;
    int unk04;
    int unk08;
    HullTriAN* m_uiBufferCapacity;
    int m_iAllocatedCount;
    void release(HullTriAN* t);
    __forceinline void remove(HullTriAN* t)
    {
        HullTriAN* n = t->m_next;
        HullTriAN* p = t->m_pSecondNode;
        if (n) n->m_pSecondNode = p;
        if (p) p->m_next = n;
        else m_uiBufferCapacity = n;
        m_iAllocatedCount--;
        release(t);
    }
};

namespace fnv_00e157f0 {
extern float DAT_01267e30;

}  // namespace fnv_00e157f0

namespace fnv_00e191a0 {
extern __m128 DAT_01267e30;

struct SpawnedObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_v10;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    __m128 m_v30;
};

__declspec(align(16)) struct PendingBlockB {
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
    int m_40;
    int m_44;
};

struct Sub08B_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SpawnedObject* PushFront(PendingBlockB* out);
};

struct FUN_00e191a0_cls {
    unsigned int unk00;
    unsigned int unk04;
    Sub08B_cls m_08;
    void FUN_00e18ed0(void* a, unsigned int b, unsigned int c, SpawnedObject* d, int e);
    void* FUN_00e191a0(void* a1, unsigned int a2, unsigned int a3, const __m128* a4, int a5);
};

// @fnv 0x00e191a0
void* FUN_00e191a0_cls::FUN_00e191a0(void* pResult, unsigned int a2, unsigned int a3, const __m128* a4, int a5) {
    PendingBlockB tmp;
    tmp.m_40 = -1;
    tmp.m_44 = -1;
    SpawnedObject* p = m_08.PushFront(&tmp);
    p->m_v30 = DAT_01267e30;
    p->m_v10 = *a4;
    FUN_00e18ed0(pResult, *(volatile unsigned int*)&a2, *(volatile unsigned int*)&a3, p, a5);
    return pResult;
}
}  // namespace fnv_00e191a0

static __forceinline __m128 Dot3(__m128 product)
{
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
}

struct __declspec(align(16)) Float4 {
    float x;
    float y;
    float z;
    float w;
};

struct PoolItemAB {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct PoolBlockAB {
    PoolItemAB m_items[32];
    int unka00;
    int m_iAllocatedCount;
};
struct BlockAllocAB {
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};
template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src) { for (int i = 0; i < SIZE / 4; i++) ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i]; }
template <class T> struct ArrAB {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};
struct FUN_00e22f90_cls {
    ArrAB<PoolBlockAB*> m_kBlocks;
    void FUN_00e22f90(PoolItemAB* item);
};
// @fnv 0x00e22f90
void FUN_00e22f90_cls::FUN_00e22f90(PoolItemAB* item)
{
    if (item)
    {
        for (int i = 0; i < m_kBlocks.GetLogicalSize(); i++)
        {
            if (item >= m_kBlocks[i]->m_items && item <= &m_kBlocks[i]->m_items[31])
            {
                if (--m_kBlocks[i]->m_iAllocatedCount == 0)
                {
                    PoolBlockAB* pBlock = m_kBlocks[i];
                    ((BlockAllocAB&)FUN_00c85750().getHeap()).ReleaseBlock(pBlock, sizeof(PoolBlockAB));
                    m_kBlocks.removeAt(i);
                }
                return;
            }
        }
        {
            unsigned int buf[128];
            CharBuffer ostr;
            ostr.FUN_00cb1600((char*)buf, sizeof(buf));
            ostr.FUN_00cc01c0("Item does not belong to the pool allocator");
            if (DAT_01268360->Report(3, 0x90355365, (char*)buf, "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Common/Internal/GeometryProcessing/hkGeometryProcessing.inl", 0xaf))
                __debugbreak();
            ostr.FUN_00cc00e0();
        }
    }
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif

struct TriangleNode {
    TriangleNode* m_next;
    TriangleNode* m_pSecondNode;
};

struct TrianglePool {
    int unk00;
    int unk04;
    int unk08;
    TriangleNode* m_pFirstNode;
    int m_uiItemCount;

    void FUN_00e22f90(void* p);
    __forceinline void remove(TriangleNode* t) {
        TriangleNode* next = t->m_next;
        TriangleNode* prev = t->m_pSecondNode;
        if (next) next->m_pSecondNode = prev;
        if (prev) prev->m_next = next;
        else m_pFirstNode = next;
        m_uiItemCount--;
        FUN_00e22f90(t);
    }
};

static __forceinline void bind(S_00e13910_Edge a, S_00e13910_Edge b) {
    if (b.isValid()) {
        S_00e13910_Edge temp = a;
        a = b;
        b = temp;
    }
    if (a.isValid()) {
        a.bind(b);
    }
}

struct EdgeMesh {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TrianglePool m_uiTriangleCount;

    bool UnbindEdgePair(S_00e13910_Edge a, S_00e13910_Edge b);
};

class hkMemoryAllocatorE15 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterE15 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE15* m_pStreamAllocator;
};
hkMemoryRouterE15* __cdecl GetMemoryRouterE15() throw();
void __cdecl ReserveMoreE15(hkMemoryAllocatorE15* pkHeap, void* pkArray, int iElemSize);
template <typename T>
inline void ConstructWithCopyE15(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T> struct hkArrayE15 {
    hkArrayE15() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~hkArrayE15()
    {
        hkMemoryRouterE15* pkRouter = GetMemoryRouterE15();
        hkMemoryAllocatorE15* pkHeap = pkRouter->m_pStreamAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            pkHeap->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    void AddBack(const T& kItem)
    {
        hkMemoryRouterE15* pkRouter = GetMemoryRouterE15();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ReserveMoreE15(pkRouter->m_pStreamAllocator, this, sizeof(T));
        ConstructWithCopyE15(m_data + m_iElementCount, 1, kItem);
        m_iElementCount++;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct __declspec(align(16)) hkVector4E15 {
    float x;
    float y;
    float z;
    float w;
};

namespace fnv_00e15ab0 {
struct MeshFaceList {
    int unk00, unk04, unk08;
    S_00e13910_Triangle* tail;
    int count;
    void FUN_00e22f90(S_00e13910_Triangle* face);
    __forceinline void remove(S_00e13910_Triangle* face) {
        S_00e13910_Triangle* previous = (S_00e13910_Triangle*)face->m_unk00;
        S_00e13910_Triangle* next = (S_00e13910_Triangle*)face->m_unk04;
        if (previous) previous->m_unk04 = (int)next;
        if (next) next->m_unk00 = (int)previous;
        else tail = previous;
        --count;
        FUN_00e22f90(face);
    }
};
struct EdgeMesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MeshFaceList faces;
    void FUN_00e11910(S_00e13910_Triangle*);
    void RemoveEdge(S_00e13910_Edge edge, bool notify);
};
}  // namespace fnv_00e15ab0

struct hkVector4 {
    __m128 v;
};

struct __declspec(align(16)) S_00e11a90_Vec {
    int x;
    int y;
    int z;
    int w;
};

__declspec(nothrow) void ReleaseSubobject();

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128 a);
#endif

struct HullFloodTriangle {
    HullFloodTriangle* m_next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_vis;
};
inline void* operator new(unsigned int, void* storage) { return storage; }
struct HullFloodEdge {
    HullFloodTriangle* m_node;
    int m_k;
    HullFloodEdge(HullFloodTriangle* node,int k):m_node(node),m_k(k) {}
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
struct HullFloodStack {
    HullFloodEdge* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    void release(Allocator& heap);
    void AddBack(const HullFloodEdge& edge);
};
inline void HullFloodStack::release(Allocator& heap) {
    m_iElementCount = 0;
    if (!(m_cap & 0x80000000)) heap.freeBlock(m_data, (m_cap & 0x3fffffff) * 8);
}
inline void HullFloodStack::AddBack(const HullFloodEdge& edge) {
    Router& mgr = FUN_00c85750();
    if (m_iElementCount == (int)(m_cap & 0x3fffffff)) ResizeAudioStream(mgr.heap, this, sizeof(HullFloodEdge));
    ::new (static_cast<void*>(m_data + m_iElementCount)) HullFloodEdge(edge);
    m_iElementCount++;
}

struct Vertex {
    Vertex* m_next;
    Vertex* m_pSecondNode;
};

struct Triangle {
    Triangle* m_next;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

static inline int nextIndex(int i) { return (9 >> (i << 1)) & 3; }

struct Edge {
    Triangle* m_pkTriangle;
    int m_uiEdgeIndex;

    Edge(Triangle* triangle, int index) : m_pkTriangle(triangle), m_uiEdgeIndex(index) {}
    unsigned int uid() const { return (unsigned int)m_pkTriangle + m_uiEdgeIndex; }
    bool isNaked() const { return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & ~3u) == 0; }
    Vertex* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    Vertex* end() const { return m_pkTriangle->m_kVertices[nextIndex(m_uiEdgeIndex)]; }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};

void __cdecl ResizeAudioStream(void*, void*, int);

template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    void ClearAndRelease()
    {
        Allocator& heap = FUN_00c85750().getHeap();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) heap.freeBlock(m_data, (cap & 0x3fffffff) * sizeof(T));
    }
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void AddBack(const T& t)
    {
        Router& router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) ResizeAudioStream(router.heap, this, sizeof(T));
        m_data[m_iElementCount] = t;
        m_iElementCount++;
    }
};

struct VertexList {
    int unk00;
    int unk04;
    int unk08;
    Vertex* m_pFirstNode;
    int m_uiItemCount;

    void FUN_00e22f90(Vertex* vertex);
    void remove(Vertex* vertex)
    {
        Vertex* next = vertex->m_next;
        Vertex* prev = vertex->m_pSecondNode;
        if (next) next->m_pSecondNode = prev;
        if (prev) prev->m_next = next;
        else m_pFirstNode = next;
        --m_uiItemCount;
        FUN_00e22f90(vertex);
    }
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float *p);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps1(float f);
#endif

extern float DAT_0106c2e0;

struct S_00e14160_Vec {
    float x, y, z, w;
    __m128& quad() { return reinterpret_cast<__m128&>(*this); }
    const __m128& quad() const { return reinterpret_cast<const __m128&>(*this); }
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setzero_ps(void);
#endif

struct E142Vec {
    float x, y, z, w;
};

struct __declspec(align(16)) E142Vector4 {
    float x, y, z, w;
    __m128& quad() { return *(__m128*)this; }
    const __m128& quad() const { return *(const __m128*)this; }
    void operator=(const E142Vector4& v) { quad() = v.quad(); }
    __m128 dot3(const E142Vec& v) const
    {
        __m128 prod = _mm_mul_ps(quad(), *(const __m128*)&v);
        return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    }
};

struct E142Hull {
    const E142Vec* FUN_00d75600();
};

void __cdecl FUN_00de9650(const E142Vector4* in, E142Vector4* out);

struct E142Obj {
    E142Hull* hkpRagdollConstraintData_getPlaneMotor();
    float FUN_00e14160(const E142Vector4& dir, float bound);
    float FUN_00e142d0(E142Vector4& out);
};

static inline float E142ToReal(__m128 v) { float f; _mm_store_ss(&f, v); return f; }

// Runs seven rounds of a refining 4x4 grid search, evaluating FUN_00e14160 per sample and keeping the sample with the smallest result in out; returns that result.
// @fnv 0x00e142d0
float E142Obj::FUN_00e142d0(E142Vector4& out)
{
    E142Vec V = *hkpRagdollConstraintData_getPlaneMotor()->FUN_00d75600();
    float lo[2];
    float hi[2];
    lo[0] = 0.0f;
    lo[1] = 0.0f;
    hi[0] = 1.0f;
    hi[1] = 1.0f;
    __m128 zero = _mm_setzero_ps();
    float best;
    int n = 7;
    do
    {
        float w = (float)((hi[0] - lo[0]) * 0.25);
        float h = (float)(w * 0.5);
        float d = hi[0] - lo[0];
        int bestIdx[2];
        bestIdx[0] = 0;
        bestIdx[1] = 0;
        best = DAT_0104da48;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                E142Vector4 P;
                P.quad() = zero;
                P.x = (float)(j * 0.25 * d + lo[0] + h);
                P.y = (float)(i * 0.25 * d + lo[1] + h);
                E142Vector4 Q;
                FUN_00de9650(&P, &Q);
                __m128 t = _mm_sub_ss(DAT_010c7160, Q.dot3(V));
                Q.w = E142ToReal(t);
                float r = FUN_00e14160(Q, best);
                if (r < best)
                {
                    best = r;
                    out = Q;
                    bestIdx[0] = j;
                    bestIdx[1] = i;
                }
            }
        }
        lo[0] += bestIdx[0] * 0.25 * d;
        lo[1] += bestIdx[1] * 0.25 * d;
        hi[0] = w + lo[0];
    } while (--n);
    return best;
}

struct E14a90Node {
    E14a90Node* m_next;
    E14a90Node* m_pSecondNode;
    E14a90Node* m_v0;
    E14a90Node* m_v1;
    E14a90Node* m_v2;
    int uNewnk;
    int uTmpnk;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float m_mark;
};

struct E14a90List {
    int unk;
    int unkCur;
    int unkValue;
    E14a90Node* m_pFirstNode;
    int m_uiItemCount;

    void FUN_00e22f90(E14a90Node* node);
    __forceinline void remove(E14a90Node* node)
    {
        E14a90Node* next = node->m_next;
        E14a90Node* prev = node->m_pSecondNode;
        if (next)
            next->m_pSecondNode = prev;
        if (prev)
            prev->m_next = next;
        else
            m_pFirstNode = next;
        m_uiItemCount--;
        FUN_00e22f90(node);
    }
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif

extern float DAT_01012054;

void __cdecl ResizeAudioStream(void* alloc, void* sizePtr, int elemSize) throw();

typedef S_00e13910_Edge PairItem;

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

struct E153F0Vector4
{
    __m128 m_vComponents;

    E153F0Vector4& operator=(const E153F0Vector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

template <class T>
__forceinline void E153F0ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

struct E153F0Points
{
    E153F0Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E153F0Points() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void reserve(int n)
    {
        Allocator& alloc = FUN_00c85750().getHeap();
        int cap = getCapacity();
        if (cap < n)
        {
            int newCap = 2 * cap;
            FUN_00c908c0((int)&alloc, this, n < newCap ? newCap : n, sizeof(E153F0Vector4));
        }
    }
    void AddBack(const E153F0Vector4& t)
    {
        Allocator& alloc = FUN_00c85750().getHeap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(E153F0Vector4));
        E153F0ConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void ClearAndRelease(Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.freeBlock(m_data, getCapacity() * sizeof(E153F0Vector4));
    }
};

struct E153F0Vertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    E153F0Vector4 m_vContactPosition;
};

struct E153F0Edge
{
    E122D0Face* m_face;
    int m_uiEdgeIndex;

    static int next(int i) { return (9 >> (i << 1)) & 3; }
    const E153F0Vector4& start() const { return ((E153F0Vertex*)m_face->m_kVertices[m_uiEdgeIndex])->m_vContactPosition; }
    const E153F0Vector4& end() const { return ((E153F0Vertex*)m_face->m_kVertices[next(m_uiEdgeIndex)])->m_vContactPosition; }
};

struct __declspec(align(16)) VecE21F {
    float x, y, z, w;
};

struct __declspec(align(16)) AabbE21F {
    VecE21F m_kMinimumCorner;
    VecE21F m_kMaximumCorner;
};

void __cdecl FUN_00cbeb70(const VecE21F* pElementBuffer, int iNumPoints, AabbE21F& kAabbOut);

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128 a);
#endif

struct TriAreaGreater {
    int unk00;
    static __forceinline __m128 area(const CastTri* t)
    {
        const Vec4f& a = t->GetVertex(0);
        const Vec4f& b = t->GetVertex(1);
        const Vec4f& c = t->GetVertex(2);
        const __m128 e1 = _mm_sub_ps(b.Get(), a.Get());
        const __m128 e2 = _mm_sub_ps(c.Get(), a.Get());
        const __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xc9), _mm_shuffle_ps(e2, e2, 0xd2)),
            _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xc9), _mm_shuffle_ps(e1, e1, 0xd2)));
        return _mm_sqrt_ss(Dot3(cross, cross));
    }
    __forceinline bool operator()(const CastTri* a, const CastTri* b) const
    {
        return ToReal(area(a)) > ToReal(area(b));
    }
};

struct MemAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};

struct BSAudio {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemAllocator* m_pAllocator;
};

// 12-byte slot; flags word: element count in low 30 bits, bit 31 = no buffer.
struct FUN_00e25ba0_Slot {
    void* m_pData;
    int m_unk04;
    int m_flags;
};

struct FUN_00e25ba0_Table {
    FUN_00e25ba0_Slot* m_pSlots;
    int m_uiItemCount;
    int m_cap;
    int m_unk0C;
};

extern "C" void __cdecl FUN_00c908c0(MemAllocator* alloc, FUN_00e25ba0_Table* table, int newCap, int elemSize);

namespace fnv_00e27450 {
struct Vertex { int unk00; int unk04; int m_uiX; int m_uiY; };
struct VKey { int m_k; VKey(const Vertex* v) : m_k((v->m_uiX << 15) + v->m_uiY) {} };
struct Triangle { int unk00; int unk04; Vertex* m_v[3]; };
struct EdgeEntry { Vertex* m_kPointA; Vertex* m_kPointB; int m_uiFilterValue; };
__forceinline void copyEntry(void* dst, const void* src)
{
    int i = 0;
    do { static_cast<int*>(dst)[i] = static_cast<const int*>(src)[i]; } while (++i < 3);
}
struct EdgeBucket {
    EdgeEntry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int indexOf(Vertex* a, Vertex* b) const
    {
        int endIdx = -1;
        if (endIdx < 0) endIdx = m_iElementCount;
        for (int i = 0; i < endIdx; ++i) if (m_data[i].m_kPointA == a && m_data[i].m_kPointB == b) return i;
        return -1;
    }
    __forceinline EdgeEntry* get(Vertex* a, Vertex* b)
    {
        int i = indexOf(a, b);
        return i == -1 ? 0 : &m_data[i];
    }
    __forceinline void remove(Vertex* a, Vertex* b)
    {
        int i = indexOf(a, b);
        --m_iElementCount;
        if (m_iElementCount != i) copyEntry(&m_data[i], &m_data[m_iElementCount]);
    }
};
__forceinline unsigned edgeHash(const Vertex* a, const Vertex* b)
{
    return ((a->m_uiX << 15) + a->m_uiY) * 0x3442a5 ^ ((b->m_uiX << 15) + b->m_uiY) * 0x1958e9;
}
__forceinline unsigned edgeHash2(const Vertex* a, const Vertex* b)
{
    VKey ka(a); VKey kb(b); return ka.m_k * 0x3442a5 ^ kb.m_k * 0x1958e9;
}
struct EdgeMap {
    EdgeBucket* m_buckets; unsigned m_numBuckets; int unk08; int m_uiItemCount;
    __forceinline EdgeEntry* get(Vertex* a, Vertex* b) { return m_buckets[edgeHash(a,b)%m_numBuckets].get(a,b); }
    __forceinline void remove(Vertex* a, Vertex* b)
    {
        unsigned h = edgeHash2(a,b) % m_numBuckets;
        --m_uiItemCount;
        EdgeBucket* bucket = m_buckets + h;
        if (bucket->indexOf(a,b) >= 0) bucket->remove(a,b);
    }
};

}  // namespace fnv_00e27450

namespace fnv_00e126c0 {
void __cdecl FUN_00c908c0(Allocator* alloc, void* arr, int numElem, int sizeElem) throw();

struct hkVector4 {
    __m128 m_vComponents;
    void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
};

template <class T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    __forceinline T* _expandBy(Allocator& alloc, int n)
    {
        int oldSize = m_iElementCount;
        int newSize = oldSize + n;
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < newSize)
        {
            int cap2 = cap + cap;
            FUN_00c908c0(&alloc, this, newSize < cap2 ? cap2 : newSize, sizeof(T));
        }
        m_iElementCount += n;
        return m_data + oldSize;
    }
    __forceinline T* expandBy(int n) { return _expandBy(FUN_00c85750().getHeap(), n); }
};

struct HashEntryTable {
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    HashEntryTable() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1) { reserve(FUN_00c85750().getHeap(), 0); }
    ~HashEntryTable() throw();
    int GetLogicalSize() const { return m_iCapacityFlags & 0x7fffffff; }
    void reserve(Allocator& alloc, int n) throw();
    void insert(Allocator& alloc, const void* key, int val) throw();
    int FindValueForKey(const void* key, int def) const throw();
    void ClearAndRelease(Allocator& alloc) throw();
};

struct PointerKeyIntegerMap {
    HashEntryTable m_map;

    void reserve(int n) { m_map.reserve(FUN_00c85750().getHeap(), n); }
    void insert(const void* key, int val) { m_map.insert(FUN_00c85750().getHeap(), key, val); }
    int FindValueForKey(const void* key, int def) const { return m_map.FindValueForKey(key, def); }
    int GetLogicalSize() const { return m_map.GetLogicalSize(); }
    ~PointerKeyIntegerMap() { m_map.ClearAndRelease(FUN_00c85750().getHeap()); }
};

}  // namespace fnv_00e126c0

struct __declspec(align(16)) Vec4F {
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

struct __declspec(align(16)) Mat3Diffs {
    Vec4F m_d0;
    Vec4F m_d1;
    Vec4F m_d2;
    __forceinline Mat3Diffs(__m128 a, __m128 b, __m128 c) { _mm_store_ps(&m_d0.m_uiX, a); _mm_store_ps(&m_d1.m_uiX, b); _mm_store_ps(&m_d2.m_uiX, c); }
    __m128* FUN_00cd51c0(Vec4F* out);
};

// FUN_00e144d0 : thiscall, float x, __m128* a, __m128* out, int count
// Clamped-distance accumulation with a dot3 weighted correction.

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif

struct __declspec(align(16)) Float4Bits
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_min_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_max_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps(float, float, float, float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float, float, float, float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
#ifndef _INCLUDED_MM2
#endif
extern const float DAT_01011d78;
void __cdecl ResizeAudioStream(void*, void*, int) throw();

struct __declspec(align(16)) CellVec {
    float x, y, z, w;
    __m128& quad() { return reinterpret_cast<__m128&>(*this); }
    const __m128& quad() const { return reinterpret_cast<const __m128&>(*this); }
};
struct BuildInput { FourFloatVector* data; int count, stride; };
struct BuildOptions {
    int unk00, unk04, unk08, unk0c;
    BuildOptions* FUN_00d74d40() throw();
};
namespace CellBuild {
struct FUN_00d76ca0 {
    int vptr;
    unsigned short memorySize, referenceCount;
    int unk08, unk0c, unk10;
    FUN_00d76ca0() throw();
    ~FUN_00d76ca0() throw() { FUN_00d76940(); }
    void FUN_00d76940() throw();
    int FUN_00d77200(const BuildInput&, const BuildOptions*) throw();
    bool FUN_00d76100(const CellVec&, int, float) throw();
};
}
template<class T> static __forceinline void CellConstruct(T* p,int n,const T& value) throw() { for(int i=0;i<n;++i) p[i].quad()=value.quad(); }
template<class T> struct CellArray {
    T* data; int size, capacity;
    CellArray() throw() : data(0), size(0), capacity(0x80000000) {}
    __forceinline T& expand() throw() {
        Router& router = FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router.heap, this, sizeof(T));
        return data[size++];
    }
    __forceinline void push(const T& value) throw() {
        Router& router = FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router.heap, this, sizeof(T));
        T* p = data + size;
        if (p) new(p) T(value);
        ++size;
    }
    __forceinline void pushVector(const T& value) throw() {
        Router& router = FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router.heap, this, sizeof(T));
        T* p = data + size;
        CellConstruct(p,1,value);
        ++size;
    }
    __forceinline void release() throw() {
        Allocator& heap = FUN_00c85750().getHeap();
        int cap = capacity;
        size = 0;
        if (!(cap & 0x80000000)) heap.freeBlock(data, (cap & 0x3fffffff)*sizeof(T));
        data = 0; capacity = 0x80000000;
    }
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float* p);
#endif

extern float DAT_01016248;

namespace fnv_00e22480 {
extern float DAT_01011d78;
extern float DAT_01012068;

__declspec(align(16)) struct Vec4Packet {
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

}  // namespace fnv_00e22480

struct LocVertex
{
    int unk00;
    int unk04;
    int m_uiX;
    int m_uiY;
};

struct LocTriangle
{
    LocTriangle* m_next;
    LocTriangle* m_pSecondNode;
    LocVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct LocEdge
{
    LocTriangle* m_pkTriangle;
    int m_uiEdgeIndex;
    LocEdge() {}
    LocEdge(const LocEdge& o) { m_pkTriangle = o.m_pkTriangle; m_uiEdgeIndex = o.m_uiEdgeIndex; }
    LocEdge(LocTriangle* t, int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    static int next(int i) { return (9 >> (i << 1)) & 3; }
    static int prev(int i) { return (18 >> (i << 1)) & 3; }
    LocEdge nextEdge() const { return LocEdge(m_pkTriangle, next(m_uiEdgeIndex)); }
    LocEdge prevEdge() const { return LocEdge(m_pkTriangle, prev(m_uiEdgeIndex)); }
    LocEdge link() const
    {
        const unsigned int l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        LocEdge e; e.m_uiEdgeIndex = l & 3; e.m_pkTriangle = (LocTriangle*)(l & ~3u); return e;
    }
    LocVertex* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    LocVertex* end() const { return m_pkTriangle->m_kVertices[next(m_uiEdgeIndex)]; }
};

struct LocResult
{
    int m_type;
    LocEdge m_kEdge;
    LocResult() {}
    LocResult(int type, const LocEdge& e) : m_type(type), m_kEdge(e.m_pkTriangle, e.m_uiEdgeIndex) {}
};

#include <math.h>
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128,__m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
extern __m128 DAT_010ec7f0;
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ps1(const float*);
#endif
#ifndef _INCLUDED_MM2
#endif
extern const float DAT_010141cc;
extern const float DAT_0104da4c=1.1920928955078125e-7f;
struct EVec {
    float x,y,z,w;
    const __m128& quad() const {return reinterpret_cast<const __m128&>(*this);}
    __m128 dot(const EVec& a) const {__m128 v=_mm_mul_ps(quad(),a.quad());return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa),_mm_add_ss(_mm_shuffle_ps(v,v,0x55),v));}
    char* FUN_00c7f520(char* out, float tolerance);
};
struct ELocalVec {union {EVec scalar; __m128 simd;}; ELocalVec(const EVec& v) {scalar=v;}};
struct EArray {EVec* data; int size; unsigned int capacity;};
struct EAppend {
 EArray* owner; EVec* dest;
 EAppend(EArray* a):owner(a),dest(a->data+a->size) {}
 ~EAppend() {++owner->size;}
 operator EVec&() {return *dest;}
};
void __cdecl ResizeAudioStream(void*,void*,int);

struct S_00e21e30_Alloc {
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00e21e30_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00e21e30_Alloc* m_pStreamAllocator;
    static S_00e21e30_Router& FUN_00c85750();
    S_00e21e30_Alloc& heap() { return *m_pStreamAllocator; }
};

struct FUN_00e21e30 {
    int unk4;
    FUN_00e21e30();
// Empty virtual destructor of the FUN_00e21e30 class.
// @fnv 0x00e21e30
    virtual ~FUN_00e21e30() {}
    void operator delete(void* p, unsigned int nbytes) {
        S_00e21e30_Router::FUN_00c85750().heap().ReleaseBlock(p, static_cast<int>(nbytes));
    }
};

extern "C" void __cdecl Deallocate(void*);

struct FUN_00e22500_cls {
    int unk04;
    virtual ~FUN_00e22500_cls() {}

    FUN_00e22500_cls* FUN_00e22500(unsigned char acFlags);
};

namespace fnv_00e22db0 {
struct S_00e22db0_Iface {
    virtual void unk00();
    virtual void unk04();
    virtual void release(void* p, unsigned short size);
};
struct S_00e22db0_Service {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e22db0_Iface* unk10;
};
namespace fnvc_adapt { S_00e22db0_Service* __cdecl FUN_00c85750(); }

struct FUN_00e22db0 {
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
    FUN_00e22db0();
// Empty virtual destructor for the FUN_00e22db0 class.
// @fnv 0x00e22db0
    virtual ~FUN_00e22db0() {}
    static void operator delete(void* p, unsigned int size)
    {
        S_00e22db0_Service* sv = fnvc_adapt::FUN_00c85750();
        sv->unk10->release(p, 0x60);
    }
};

}  // namespace fnv_00e22db0

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps1(float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128);
#endif

typedef float hkReal;


struct VectorComponentValue {
    __m128 m_vValue;

    __forceinline VectorComponentValue(__m128 r) : m_vValue(r) {}
    __forceinline operator hkReal() const { hkReal r; _mm_store_ss(&r, m_vValue); return r; }
};

__forceinline VectorComponentValue operator-(const VectorComponentValue& r) { return _mm_sub_ss(DAT_010c7160, r.m_vValue); }

struct CheckVector {
    __m128 m_vComponents;

    __forceinline void operator=(const CheckVector& v) { m_vComponents = v.m_vComponents; }
    __forceinline hkReal& operator()(int i) { return m_vComponents.m128_f32[i]; }
    __forceinline void setSub4(const CheckVector& a, const CheckVector& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkReal s) { __m128 scale = _mm_load_ss(&s); m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), m_vComponents); }
    __forceinline void setCross(const CheckVector& v1, const CheckVector& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline VectorComponentValue dot3(const CheckVector& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline VectorComponentValue lengthSquared3() const { return dot3(*this); }
    __forceinline VectorComponentValue length3() const { return _mm_sqrt_ss(lengthSquared3().m_vValue); }
};

class TriangleChecker {
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    bool m_degenerate;
    hkReal m_minEdgeLengthSquared;
    hkReal m_fMinTriangleAreaSquared;

    void FUN_00e114f0(const CheckVector& a, const CheckVector& b, const CheckVector& c);
    void FUN_00e11500(const CheckVector& a, const CheckVector& b);
    bool FUN_00e11710(const CheckVector& a, const CheckVector& b, const CheckVector& c, CheckVector& planeOut, bool report);
};

__declspec(noinline) void TriangleChecker::FUN_00e114f0(const CheckVector& a, const CheckVector& b, const CheckVector& c)
{
    m_degenerate = true;
}

__declspec(noinline) void TriangleChecker::FUN_00e11500(const CheckVector& a, const CheckVector& b)
{
    m_degenerate = true;
}

// Validates triangle edges and area against tolerance thresholds, computes and normalizes the plane, and reports degenerate cases.
// @fnv 0x00e11710
bool TriangleChecker::FUN_00e11710(const CheckVector& a, const CheckVector& b, const CheckVector& c, CheckVector& planeOut, bool report)
{
    const hkReal tolerance = m_minEdgeLengthSquared;
    bool ok = true;

    CheckVector ab; ab.setSub4(b, a);
    if (report && ab.lengthSquared3() <= tolerance)
    {
        FUN_00e11500(a, b);
        ok = false;
    }

    CheckVector ac; ac.setSub4(c, a);
    if (report && ac.lengthSquared3() <= tolerance)
    {
        FUN_00e11500(a, c);
        ok = false;
    }

    CheckVector cb; cb.setSub4(c, b);
    if (report && cb.lengthSquared3() <= tolerance)
    {
        FUN_00e11500(c, b);
        ok = false;
    }

    planeOut.setCross(ab, ac);
    const hkReal len = planeOut.length3();
    planeOut(3) = len;
    if (report && len < m_fMinTriangleAreaSquared)
    {
        FUN_00e114f0(a, b, c);
        ok = false;
    }

    planeOut.mul4(1.0f / planeOut(3));
    planeOut(3) = -planeOut.dot3(a);
    return ok;
}

struct S00e124d0_Obj {
    unsigned int m_h0;
    unsigned int m_h4;
    unsigned int m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct S00e124d0_Entry {
    S00e124d0_Obj* m_obj;
    int m_iIndex;
};

template <unsigned int ELEMENTSIZE>
inline void S00e124d0_memCpyOne(void* dst, const void* src) {
    const int* s = static_cast<const int*>(src);
    int* d = static_cast<int*>(dst);
    unsigned int i = 0;
    do {
        d[i] = s[i];
        ++i;
    } while (i < ELEMENTSIZE / sizeof(int));
}

template <typename T>
inline void S00e124d0_destruct(T* p, int n) {
    for (int k = 0; k < n; ++k) {
        p[k].~T();
    }
}

struct S00e124d0_Table {
    S00e124d0_Entry* m_data;
    int m_uiItemCount;

    inline void removeAt(int index) {
        S00e124d0_destruct(m_data + index, 1);
        m_uiItemCount--;
        if (m_uiItemCount != index) {
            S00e124d0_memCpyOne<sizeof(S00e124d0_Entry)>(m_data + index, m_data + m_uiItemCount);
        }
    }
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_min_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_max_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps1(float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float,float,float,float);
#endif

struct __declspec(align(16)) BoundsCopy { float x,y,z,w; };
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
#endif
#ifndef _INCLUDED_MM2
#endif


struct BoundNode {
    BoundNode* m_next;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_vec;
};

extern const float DAT_01011d78;
extern const float DAT_01012068;
extern float DAT_01012054;

struct BoundFace {
    BoundFace* next; int unk04; BoundNode* points[3];
    int unk14,unk18,unk1c; __m128 plane;
};
struct BoundsMesh {
    int unk00;
    int unk04, unk08, unk0c, unk10;
    BoundNode* m_14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    BoundFace* faces;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int m_e4;
    int unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    unsigned char badGeometry,unk101,unk102,unk103;
    float edgeThreshold,areaThreshold;
    __declspec(noinline) bool FUN_00e11710(const __m128*,const __m128*,const __m128*,__m128*,bool);
    __declspec(noinline) bool FUN_00e11910(BoundFace*);


    void FUN_00e11ca0(__m128*);
    __declspec(noinline) void ResetNodeVectors();
    void FUN_00e11b00(__m128* p);
    void BuildHull();
    float FUN_00e13fa0(__m128* a1, __m128* a2, float a3);
};


static __forceinline float scalarLength(__m128 v) {
    __m128 q=_mm_mul_ps(v,v);
    __m128 d=_mm_add_ss(_mm_shuffle_ps(q,q,0xaa),_mm_add_ss(_mm_shuffle_ps(q,q,0x55),q));
    float f; _mm_store_ss(&f,d);return f;
}
bool BoundsMesh::FUN_00e11710(const __m128* a,const __m128* b,const __m128* c,__m128* out,bool check) {
    float threshold=edgeThreshold;
    bool valid=true;
    __m128 u=_mm_sub_ps(*b,*a);
    if(check && scalarLength(u)<threshold) {badGeometry=1;valid=false;}
    __m128 v=_mm_sub_ps(*c,*a);
    if(check && scalarLength(v)<threshold) {badGeometry=1;valid=false;}
    __m128 w=_mm_sub_ps(*c,*b);
    if(check && scalarLength(w)<threshold) {badGeometry=1;valid=false;}
    __m128 cross=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0xd2),_mm_shuffle_ps(u,u,0xc9)),_mm_mul_ps(_mm_shuffle_ps(v,v,0xc9),_mm_shuffle_ps(u,u,0xd2)));
    *out=cross;
    __m128 q=_mm_mul_ps(cross,cross);
    __m128 d=_mm_add_ss(_mm_shuffle_ps(q,q,0xaa),_mm_add_ss(_mm_shuffle_ps(q,q,0x55),q));
    d=_mm_sqrt_ss(d);
    float len;_mm_store_ss(&len,d);
    out->m128_f32[3]=len;
    if(check && areaThreshold>len) {badGeometry=1;valid=false;}
    float inv=1.0f/out->m128_f32[3];
    *out=_mm_mul_ps(_mm_set_ps1(inv),*out);
    __m128 product=_mm_mul_ps(*a,*out);
    __m128 dot=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product));
    __m128 neg=_mm_sub_ss(DAT_010c7160,dot);
    _mm_store_ss(&out->m128_f32[3],neg);
    return valid;
}

typedef S_00e13910_Triangle NakedFace;
typedef S_00e13910_Edge NakedEdgeRef;

void __cdecl ResizeAudioStream(void*, void*, int);
static inline void copyEdge(void*, const void*, int);

struct NakedArray
{
    NakedEdgeRef* data;
    int size;
    int cap;
    void reserve(Allocator& heap, int capacity)
    {
        if ((int)(cap & 0x3fffffff) < capacity)
        {
            int n = (int)(cap & 0x3fffffff)*2;
            if (n <= capacity) n = capacity;
            FUN_00c908c0(&heap, (FUN_00e22970_Cls*)this, n, 8);
        }
    }
    void clear() { size=0; }
    void deallocate(Allocator& heap)
    {
        if (!(cap & 0x80000000))
            heap.freeBlock(data, (cap & 0x3fffffff)*8);
    }
    void release(Allocator& heap) { clear(); deallocate(heap); }
    void removeAt(int index)
    {
        --size;
        if (size != index) copyEdge(data + index, data + size, sizeof(NakedEdgeRef));
    }
    void append(const NakedEdgeRef& edge)
    {
        Allocator& heap = FUN_00c85750().getHeap();
        if (size == (int)(cap & 0x3fffffff))
            ResizeAudioStream(&heap, this, 8);
        new (data + size) NakedEdgeRef(edge);
        ++size;
    }
};

static inline void copyEdge(void* destination, const void* source, int bytes)
{
    int i = 0;
    do { *(int*)((char*)destination+i) = *(const int*)((const char*)source+i); i+=4; } while (i<bytes);
}

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

struct hkMemoryAllocator {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void v08();
    virtual void v0c();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int numBytes) throw();
};
struct NineIntegerRecord {
    char* m_stackCurrent;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* heap;
    hkMemoryAllocator& getHeap() { return *heap; }
};
namespace hkRouter { __declspec(nothrow) NineIntegerRecord& __cdecl FUN_00c85750() throw(); }
__declspec(nothrow) void __cdecl ResizeAudioStream(void*,void*,int) throw();
template<class T> struct HullArray {
 T* data; int size; int capacityAndFlags;
 __declspec(nothrow) __forceinline HullArray():data(0),size(0),capacityAndFlags(0x80000000) {}
 __declspec(nothrow) __forceinline ~HullArray() {
  hkMemoryAllocator& heap=hkRouter::FUN_00c85750().getHeap();
  size=0;
  if((capacityAndFlags&0x80000000u)==0) heap.ReleaseBlock(data,(capacityAndFlags&0x3fffffff)*sizeof(T));
 }
 __forceinline void AddBack(const T& value) {
  NineIntegerRecord& router=hkRouter::FUN_00c85750();
  if(size==(capacityAndFlags&0x3fffffff)) ResizeAudioStream(router.heap,this,sizeof(T));
  data[size]=value; ++size;
 }
 __forceinline int indexOf(T value) const {
  for(int i=0;i<size;++i) if(data[i]==value) return i;
  return -1;
 }
};
template<class T> struct HullLocalArray : HullArray<T> {
 T* localMemory;
 __declspec(nothrow) __forceinline HullLocalArray(int capacity) {
  NineIntegerRecord& router=hkRouter::FUN_00c85750();
  T* memory=static_cast<T*>(static_cast<void*>(router.m_stackCurrent));
  router.m_stackCurrent+=((capacity*sizeof(T)+127)&~127);
  this->data=memory;
  this->capacityAndFlags=capacity|0x80000000;
  localMemory=memory;
 }
 __declspec(nothrow) __forceinline ~HullLocalArray() {
  if(!wasReallocated()) this->size=0; deallocateStack(localMemory);
 }
 __forceinline bool wasReallocated() const { return localMemory!=this->data; }
 static __forceinline void deallocateStack(void* p) { hkRouter::FUN_00c85750().m_stackCurrent=static_cast<char*>(p);
 }
};
struct HullDescriptor {
 enum Kind { TRIANGLE=1,EDGE=2,VERTEX=3 };
 int kind;
 S_00e13910_Edge edge;
};

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ps1(const float*);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128,__m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128);
#endif
extern double DAT_01011588, DAT_01016408;
void __cdecl ResizeAudioStream(Allocator*,void*,int);
struct ZPlane {
    bool* FUN_00c7f520(bool*,float);
}
;
template<class T> struct ZArray {
    T* data;
    int size;
    unsigned capacity;
    ZArray():data(0),size(0),capacity(0x80000000) {
    }
    void append(const T& item) {
        Allocator& a=FUN_00c85750().getHeap();
        if(size==(capacity&0x3fffffff)) ResizeAudioStream(&a,this,sizeof(T));
        new(data+size) T(item);
        ++size;
    }
    void release() {
        Allocator& a=FUN_00c85750().getHeap();
        size=0;
        if(!(capacity&0x80000000)) a.freeBlock(data,(capacity&0x3fffffff)*sizeof(T));
        data=0;
        capacity=0x80000000;
    }
}
;
struct ZNode {
    ZNode* next;
    int unk04;
    TriVertex* unk08;
    TriVertex* unk0c;
    TriVertex* unk10;
    int unk14,unk18,unk1c;
    ZPlane unk20;
    int unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40;
}
;
template<> void ZArray<ZNode*>::append(ZNode* const& item) {
    Allocator& a=FUN_00c85750().getHeap();
    if(size==(capacity&0x3fffffff)) ResizeAudioStream(&a,this,4);
    data[size++]=item;
}

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
template <typename T>
struct E1D960Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    E1D960Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~E1D960Array() throw()
    {
        Allocator& alloc = FUN_00c85750().getHeap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.freeBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int indexOf(const T& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; i++)
            if (m_data[i] == t) return i;
        return -1;
    }
    void AddBack(const T& t) throw()
    {
        Allocator& alloc = FUN_00c85750().getHeap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(T));
        E153F0ConstructWithCopy(m_data + m_iElementCount, 1, t);
        ++m_iElementCount;
    }
};
struct E1D960Body {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    E12160Triangle* m_pTriangle;
};
struct E1D960Pair {
    E1D960Body* a;
    E1D960Body* b;
};
struct QueryBase {
    virtual ~QueryBase() throw() {}
};
struct QueryCtx : QueryBase {
    E1D960Array<E1D960Pair>* arr;
    QueryCtx(E1D960Array<E1D960Pair>* a) throw() : arr(a) {}
};
__declspec(nothrow) bool __cdecl TriangleHasVertexAtPoint(const E12160Triangle* triangle, const float* point);

struct Piece {
    virtual void destroy(unsigned int);
    hkgpConvexHull* hkpRagdollConstraintData_getPlaneMotor();
};
template<class T> struct Array360 {
    T* data;
    int size;
    int capacity;
    Array360() : data(0), size(0), capacity(0x80000000) {}
    T& operator[](int i) { return data[i]; }
    int GetLogicalSize() const { return size; }
};
typedef Array360<Piece*> Pieces;
void __cdecl ResizeAudioStream(void*, void*, int);

extern int DAT_01268370;
extern float DAT_0104da48;
extern float DAT_0104e148;
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float* p);
#endif

struct S00e24650_Vtx {
    unsigned int unk00;
    unsigned int unk04;
    int m_uiX;
    int m_uiY;
};

struct S00e24650_Tri {
    unsigned int unk00;
    unsigned int unk04;
    S00e24650_Vtx* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct S00e24650_Edge {
    S00e24650_Tri* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
    S00e24650_Edge() {}
    S00e24650_Edge(S00e24650_Tri* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    S00e24650_Edge(unsigned int tagged) {m_pkTriangle=(S00e24650_Tri*)tagged; m_uiEdgeIndex=(unsigned int)m_pkTriangle&3; m_pkTriangle=(S00e24650_Tri*)((unsigned int)m_pkTriangle&~3u);}
    S00e24650_Edge(const S00e24650_Edge& o) { m_pkTriangle=o.m_pkTriangle; m_uiEdgeIndex=o.m_uiEdgeIndex; }
    S00e24650_Edge next() const { S00e24650_Edge r(*this); r.m_uiEdgeIndex=(9 >> (r.m_uiEdgeIndex << 1)) & 3; return r; }
    S00e24650_Edge prev() const { return S00e24650_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    S00e24650_Edge link() const { return S00e24650_Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]); }
    bool isNaked() const { return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & 0xfffffffcu) == 0; }
    S00e24650_Vtx* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    S00e24650_Vtx* end() const { return m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex<<1))&3]; }
};

struct S_00e248b0_Tri {
    int unk00;
    int unk04;
    int v[3];
    unsigned int link[3];
};

static __forceinline int S_00e248b0_next(int e) { return (9 >> (e * 2)) & 3; }

struct S_00e248b0_Edge {
    S_00e248b0_Tri* tri;
    int e;
    S_00e248b0_Edge() {}
    S_00e248b0_Edge(S_00e248b0_Tri* t, int i) : tri(t), e(i) {}
    bool isNaked() const { return (tri->link[e] & ~3u) == 0; }
    S_00e248b0_Edge link() const { unsigned int l = tri->link[e]; S_00e248b0_Edge r; r.e = l & 3; r.tri = (S_00e248b0_Tri*)(l & ~3u); return r; }
    S_00e248b0_Edge next() const { return S_00e248b0_Edge(tri, S_00e248b0_next(e)); }
    int start() const { return tri->v[e]; }
    int end() const { return tri->v[S_00e248b0_next(e)]; }
    unsigned int uid() const { return (unsigned int)tri + e; }
};

struct S_00e248b0_Elem {
    S_00e248b0_Tri* tri;
    int e;
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

struct S_00e248b0_Heap {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void v0C();
    virtual void ReturnMemory(void* p, int n);
};

static __forceinline S_00e248b0_Heap* S_00e248b0_heap(Router& r)
{
    return (S_00e248b0_Heap*)r.heap;
}

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

struct S_00e248b0_Arr {
    S_00e248b0_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    S_00e248b0_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000) {}
    static void* operator new(unsigned int size) { return S_00e248b0_heap(FUN_00c85750())->AllocateMemoryBlock(size); }
};

template <typename V> struct TriBase {
    int m_unk00;
    int m_unk04;
    V m_vtx[3];
    __forceinline V& vtx(int i) { return m_vtx[i]; }
};
typedef TriBase<void*> Tri;

template <typename SELF, typename T> struct EdgeBase {
    EdgeBase() {}
    EdgeBase(T* t, hkUint32 i) : m_tri(t), m_idx(i) {}
    static __forceinline const SELF& none() { static const SELF e(0, 0); return e; }
    __forceinline void*& from() const { return m_tri->vtx(m_idx); }
    T* m_tri;
    hkUint32 m_idx;
};
struct EdgeT : EdgeBase<EdgeT, Tri> {
    EdgeT() {}
    EdgeT(Tri* t, hkUint32 i) : EdgeBase<EdgeT, Tri>(t, i) {}
    EdgeT(const EdgeT& o) : EdgeBase<EdgeT, Tri>(o.m_tri, o.m_idx) {}
};

struct Bool8 {
    char m_kPointB;
    Bool8(bool b) { m_kPointB = (char)b; }
    operator bool() const { return m_kPointB != 0; }
};
struct KindT { int v; Bool8 operator==(int o) const { return v == o; } };
struct Where {
    enum { IN_FACE = 0, ON_EDGE = 1, AT_VERTEX = 2 };
    KindT m_kind;
    EdgeT m_usTrailingValue;
};

struct GateE10 { char value; GateE10() {} GateE10(bool b):value(b) {} operator bool() const { return value != 0; } };
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128,__m128);
extern "C" __m128 _mm_andnot_ps(__m128,__m128);

struct Vec4E10 {
    float x, y, z, w;
    __m128& quad() { return *(__m128*)this; }
    const __m128& quad() const { return *(const __m128*)this; }
    __forceinline float squared() const {
        __m128 q = _mm_mul_ps(quad(),quad());
        __m128 y = _mm_shuffle_ps(q,q,0x55);
        __m128 a = _mm_add_ss(y,q);
        __m128 z = _mm_shuffle_ps(q,q,0xaa);
        float value; _mm_store_ss(&value,_mm_add_ss(z,a)); return value;
    }
    __forceinline void scale(float value) { quad()=_mm_mul_ps(_mm_set_ps1(value),quad()); }
    __forceinline int unitNonzero() {
        float sq=squared();
        if(sq!=0.0f) { float r=sqrtf(sq); r=1.0f/r; scale(r); return 0; }
        return 1;
    }
    GateE10 FUN_00c7f520(float c) const;
    __forceinline Vec4E10& fastUnit(__m128 cZero, __m128 cThree, __m128 cHalf) {
        __m128 vec = quad();
        __m128 sq = _mm_mul_ps(vec, vec);
        __m128 s1 = _mm_shuffle_ps(sq, sq, 0x55);
        __m128 a1 = _mm_add_ss(s1, sq);
        __m128 s2 = _mm_shuffle_ps(sq, sq, 0xaa);
        __m128 len = _mm_add_ss(s2, a1);
        __m128 r = _mm_rsqrt_ss(len);
        __m128 eq = _mm_cmpeq_ss(len, cZero);
        __m128 scale = _mm_andnot_ps(eq, _mm_mul_ss(_mm_mul_ss(cHalf, r), _mm_sub_ss(cThree, _mm_mul_ss(_mm_mul_ss(len, r), r))));
        quad() = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), vec);
        return *this;
    }
};
extern const float DAT_010141cc = 0.0001f;
extern float DAT_01016248;
float __cdecl ClampedAcos(float);

struct ByteFlag { char data; ByteFlag() {} ByteFlag(bool x):data(x) {} operator bool() const {return data!=0;} ByteFlag& operator=(bool x){data=x;return *this;} };
struct hkVec4 {
    __m128 m_vComponents;
    hkVec4() {}
    hkVec4(const hkVec4& o) : m_vComponents(o.m_vComponents) {}
    __forceinline void operator=(const hkVec4& o) { m_vComponents = o.m_vComponents; }
    void setMul4(__m128 r, const hkVec4& a) { m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents); }
    void addMul4(__m128 r, const hkVec4& a) { m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents), m_vComponents); }
    __forceinline void add4(const hkVec4& a) { m_vComponents = _mm_add_ps(a.m_vComponents, m_vComponents); }
    void mul4(__m128 r) { m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents); }
    __m128 getSimd0() const { return m_vComponents; }
    __m128 getSimd1() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55); }
    __m128 getSimd2() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa); }
    __m128 getSimdAt(int i) const {
        switch(i) {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents,m_vComponents,0x55);
        case 2: return _mm_shuffle_ps(m_vComponents,m_vComponents,0xaa);
        default: return _mm_shuffle_ps(m_vComponents,m_vComponents,0xff);
        }
    }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};
template<class T> struct ListLinks { T* next; T* prev; };
struct MeshVertex : ListLinks<MeshVertex> {
    hkVec4 m_vContactPosition;
    hkVec4 m_vHitNormal;
};
struct FaceLinks { int unk00, unk04; };
template<class V> struct FaceBase : FaceLinks {
    V m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline V& vertex(int i) { return m_kVertices[i]; }
    __forceinline V vertex(int i) const { return m_kVertices[i]; }
};
struct MeshTriangle : FaceBase<MeshVertex*> {
    hkVec4 m_kTriangleNormal;
    __forceinline hkVec4& position(int i) { return vertex(i)->m_vContactPosition; }
    __forceinline const hkVec4& position(int i) const { return vertex(i)->m_vContactPosition; }
};
struct MeshLocation {
    unsigned int m_tri;
    unsigned int m_uiEdgeIndex;
    static __forceinline const MeshLocation& none() {
        if ((DAT_0126ebf0 & 1) == 0) {
            DAT_0126ebf0 |= 1;
            DAT_0126ebe8 = 0;
            DAT_0126ebec = 0;
        }
        return *(const MeshLocation*)&DAT_0126ebe8;
    }
    MeshLocation() {}
    MeshLocation(unsigned int t, unsigned int i) : m_tri(t), m_uiEdgeIndex(i) {}
};
struct MeshHit {
    int m_type;
    MeshLocation m_loc;
    MeshHit() : m_type(0), m_loc(MeshLocation::none()) {}
    MeshHit(int ty, MeshLocation l) : m_type(ty), m_loc(l) {}
};
struct MeshResult {
    hkVec4 m_dir;
    hkVec4 m_vHitNormal;
    hkVec4 m_bary;
    hkVec4 m_kPoint;
    float m_fHitFraction;
    ByteFlag m_kHitFlags;
    MeshHit m_bHasHit;
    MeshResult();
    __forceinline MeshResult& operator=(const MeshResult& o)
    {
        m_dir = o.m_dir;
        m_vHitNormal = o.m_vHitNormal;
        m_bary = o.m_bary;
        m_kPoint = o.m_kPoint;
        m_fHitFraction = o.m_fHitFraction;
        m_kHitFlags = o.m_kHitFlags;
        m_bHasHit = o.m_bHasHit;
        return *this;
    }
};
struct MeshPoint { unsigned int x, y, z, w; };
extern const void* DAT_010eadc8;
struct __declspec(align(16)) ClosestQuery {
    const void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    MeshPoint m_kPoint;
    float m_fHitFraction;
    int unk24;
    int unk28;
    int unk2c;
    hkVec4 m_closest;
    hkVec4 m_bary;
    MeshTriangle* m_tri;
    ClosestQuery(const MeshPoint& p) : m_kPoint(p), m_fHitFraction(3.40282e+38f)
    {
        m_vtbl = &DAT_010eadc8;
        m_tri = 0;
        m_closest = *(hkVec4*)&DAT_01267e30;
    }
};

extern "C" __m128 _mm_load_ss(const float* p);
static __forceinline __m128 Splat(__m128 v) { return _mm_shuffle_ps(v, v, 0); }

static __forceinline void SetMul4(__m128& d, __m128 r, const __m128& a) { d = _mm_mul_ps(Splat(r), a); }
static __forceinline void AddMul4(__m128& d, __m128 r, const __m128& a) { d = _mm_add_ps(_mm_mul_ps(Splat(r), a), d); }

extern "C" __m128 _mm_set_ss(float);

extern float DAT_0106c2e0;
void __stdcall FUN_00c7f640(int arg, void* p);

struct Ex_Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_10;
};

struct Ex_Node {
    Ex_Node* m_00;
    int unk04;
    Ex_Holder* m_08;
    Ex_Holder* m_0c;
    Ex_Holder* m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
};

struct Ex_Scratch {
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
    char m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    void FUN_00e22ca0();
};

struct __declspec(align(16)) LocalVec {
__m128 value;
LocalVec() {}
__forceinline void set(__m128 a,__m128 b) { value=_mm_add_ps(a,b); }
__forceinline void add(__m128 a) { value=_mm_add_ps(a,value); }
__forceinline void mul(__m128 a) { value=_mm_mul_ps(value,a); }

};
struct Ex_Target {
    void FUN_00e13210(LocalVec* a, Ex_Scratch* b);
};

struct LocalOwner {
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
    Ex_Node* m_2c;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC;
    int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; int unkE4; int unkE8; int unkEC;
    int unkF0; int unkF4; int unkF8; int unkFC;
    unsigned char unk100;
    unsigned char m_101;
    void RemoveTriangle(Ex_Node* n);
    void FUN_00e15020(int key, int arg2, unsigned int arg3, unsigned char flag);
};

// For each node with m_30 == key, averages its three vertex vectors, applies FUN_00c7f640, runs FUN_00e13210, and removes the node if m_44 == flag.
// @fnv 0x00e15020
void LocalOwner::FUN_00e15020(int key, int arg2, unsigned int arg3, unsigned char flag) {
    Ex_Node* node = m_2c;
    if (node != 0) {
        Ex_Node* next;
        do {
            next = node->m_00;
            if (node->m_30 == key) {
                LocalVec a;
                a.set(node->m_0c->m_10, node->m_08->m_10);
                
                 __m128 t = _mm_set_ss(0.3333333432674408f);
__m128 K = _mm_shuffle_ps(t,t,0);
                a.add(node->m_10->m_10);
                a.mul(K);
                FUN_00c7f640(arg2, &a);
                Ex_Scratch obj;
                obj.FUN_00e22ca0();
                ((Ex_Target*)(*(volatile unsigned int*)&arg3))->FUN_00e13210(&a, &obj);
                if ((int)obj.m_44 == (int)flag) {
                    RemoveTriangle(node);
                }
            }
            node = next;
        } while (node != 0);
    }
    m_101 = 0;
}

struct E17Mem
{
    virtual void v00();
    virtual void* allocate(int size);
    virtual void deallocate(void* p, int size);
    virtual void v0c();
    virtual void freeBlock(void* p, int size);
};

__forceinline E17Mem& e17Heap() { return *(E17Mem*)&FUN_00c85750().getHeap(); }

void __cdecl ResizeAudioStream(E17Mem* alloc, void* array, int elemSize);

struct E17Face
{
    E17Face* m_next;
    int unk04;
    int m_kVertices[3];
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_iMaterialIndex;
};

struct E17Edge
{
    E17Face* m_face;
    int m_uiEdgeIndex;

    E17Edge(E17Face* face, int index) : m_face(face), m_uiEdgeIndex(index) {}
    static int next(int i) { return (9 >> (i << 1)) & 3; }
    int start() const { return m_face->m_kVertices[m_uiEdgeIndex]; }
    int end() const { return m_face->m_kVertices[next(m_uiEdgeIndex)]; }
};

template <class T>
__forceinline void e17Construct(T* p, const T& t) { new (p) T(t); }
template <class T>
__forceinline void e17Construct(T** p, T* const& t) { *p = t; }

template<unsigned Bytes> __forceinline void e17CopyWords(void* dest,const void* src)
{
    unsigned word=0;
    do {
        static_cast<unsigned*>(dest)[word]=static_cast<const unsigned*>(src)[word];
        ++word;
    } while(word<Bytes/sizeof(unsigned));
}
template<class T> __forceinline void e17Destroy(T* p,int count) {
    for(int item=0;item<count;++item) p[item].~T();
}
template <class T>
struct E17Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E17Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~E17Array()
    {
        E17Mem& heap = e17Heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.freeBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    T& back() { return m_data[m_iElementCount - 1]; }
    void AddBack(const T& t)
    {
        E17Mem& heap = e17Heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
        e17Construct(m_data + m_iElementCount, t);
        m_iElementCount++;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            e17CopyWords<sizeof(T)>(m_data+index,m_data+m_iElementCount);
    }
    void FUN_00e22640(E17Mem* heap, const T* data, int n);
    void append(const T* data, int n) { FUN_00e22640(&e17Heap(), data, n); }

    static void* operator new(unsigned int size) { return e17Heap().allocate(size); }
    static void operator delete(void* p) { e17Heap().deallocate(p, sizeof(E17Array)); }
};

typedef E17Array<E17Edge> E17Loop;

struct E17LoopList
{
    E17Loop** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AppendInts(E17Mem* heap, E17Loop* const* data, int n);
    void append(E17Loop* const* data, int n) { AppendInts(&e17Heap(), data, n); }
};

struct SplitFace : S_00e13910_Triangle {
    __forceinline void*& vertex(int i) { return m_kVertices[i]; }
    __forceinline hkUint32& link(int i) { return m_ppLinks[i]; }
    __forceinline void corners(void* const& a, void* const& b, void* const& c) {
        m_kVertices[0] = a; m_kVertices[1] = b; m_kVertices[2] = c;
    }
};
struct SplitEdge;
template<class E, class T> struct SplitCore {
    T* m_pkTriangle;
    hkUint32 m_uiEdgeIndex;
    __forceinline SplitCore() {}
    __forceinline SplitCore(T* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline SplitCore(const hkUint32& packed) { unpack(packed, m_pkTriangle, m_uiEdgeIndex); }
    static __forceinline void unpack(hkUint32 packed, T*& tri, hkUint32& idx) {
        idx = packed & 3; packed &= ~3u; tri = (T*)packed;
    }
    __forceinline E next() const { return E(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline E prev() const { return E(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline E link() const { return E(m_pkTriangle->link(m_uiEdgeIndex)); }
    __forceinline bool isValid() const { return m_pkTriangle != 0; }
    __forceinline void*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline void*& end() const { return m_pkTriangle->vertex((9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline void*& apex() const { return m_pkTriangle->vertex((0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline void bind(const E& other) const {
        m_pkTriangle->link(m_uiEdgeIndex) = (hkUint32)other.m_pkTriangle + other.m_uiEdgeIndex;
        if (other.m_pkTriangle) other.m_pkTriangle->link(other.m_uiEdgeIndex) = (hkUint32)m_pkTriangle + m_uiEdgeIndex;
    }
    static __forceinline const E& null() { static const E e(0, 0); return e; }
};
struct SplitEdge : SplitCore<SplitEdge, SplitFace> {
    typedef SplitCore<SplitEdge, SplitFace> Base;
    __forceinline SplitEdge(SplitFace* t, unsigned i) : Base(t, i) {}
    __forceinline SplitEdge(const hkUint32& packed) : Base(packed) {}
    __forceinline SplitEdge(const SplitEdge& other) : Base(other.m_pkTriangle, other.m_uiEdgeIndex) {}
};

namespace fnv_00e1b820 {
struct VertexCopy;

struct Bits4 { unsigned a,b,c,d; };
struct __declspec(align(16)) PositionBits:Bits4 {};
struct VertexCopy;
struct TriangleCopy;
template<class T> struct ListLinks {
    T* next; T* prev;
    ListLinks() {}
    ListLinks(const ListLinks&) {}
};
struct VertexCopy:ListLinks<VertexCopy> {
    PositionBits position,normal,data;
    int refs,tag;
    __forceinline VertexCopy(const VertexCopy& v):ListLinks<VertexCopy>(v),position(v.position),normal(v.normal),data(v.data),refs(v.refs),tag(v.tag) {}
};
struct TriangleCopy:ListLinks<TriangleCopy> {
    VertexCopy* vertices[3]; unsigned links[3];
    PositionBits plane;
    int part,planeId,material,tag; unsigned leaf;
    __forceinline VertexCopy*& vertex(int i) {return vertices[i];}
    __forceinline VertexCopy* vertex(int i) const {return vertices[i];}
    __forceinline unsigned& link(int i) {return links[i];}
};
template<class T> struct CopyPool {
    struct Block {T entries[32];T* free;int used;};
    Block** blocks; int size,capacity;
    T* head; int count; unsigned uid;
    Block* FUN_00e23530();
    __forceinline T* allocateRaw() {
        Block* block=(size && blocks[0]->free)?blocks[0]:FUN_00e23530();
        T* free=block->free;
        block->free=free->next;
        ++block->used;
        return free;
    }
    __forceinline T* clone(const T& value) {
        T* item=new (allocateRaw()) T(value);
        item->prev=0;
        item->next=head;
        if(head)head->prev=item;
        head=item;
        ++count;
        return item;
    }
};
struct PartsMap {
    int data,size,mask;
    __forceinline PartsMap():data(0),size(0),mask(-1) {reserve(0);}
    void EnsureCapacity(Allocator*,int);
    unsigned long LookupHashEntry(unsigned long,unsigned long) const;
    int FUN_00cb1870(Allocator*,unsigned long,unsigned long);
    void ProcessArgument(Allocator*);
    void FUN_00a29680();
    static void* operator new(unsigned n,Allocator* heap){return heap->allocate(n);}
    __forceinline void reserve(int n){EnsureCapacity(&FUN_00c85750().getHeap(),n);}
    __forceinline unsigned long lookup(unsigned long k)const{return LookupHashEntry(k,0);}
    __forceinline void insert(unsigned long k,unsigned long v){FUN_00cb1870(&FUN_00c85750().getHeap(),k,v);}
    __forceinline void record(Allocator& a,unsigned long k,unsigned long v){FUN_00cb1870(&a,k,v);}
};
template<class T> struct PartArray {
    T* data; int size,capacity;
    PartArray():data(0),size(0),capacity(0x80000000){}
    __forceinline T& operator[](int i){return data[i];}
    __forceinline void reserve(Allocator& heap,int n){
        int c=capacity&0x3fffffff;
        if(c<n){int twice=c+c;if(n<twice)n=twice;FUN_00c908c0((int)&heap,this,n,sizeof(T));}
    }
    __forceinline T* expand(Allocator& heap,int n){int old=size;reserve(heap,old+n);T* out=data+old;size+=n;return out;}
};

}  // namespace fnv_00e1b820

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
void __cdecl ResizeAudioStream(void*, void*, int) throw();

struct CutVec {
    __m128 q;
    __forceinline __m128& quad() {return q;}
    __forceinline const __m128& quad() const {return q;}
    __forceinline float& component(int i) {return q.m128_f32[i];}
    __forceinline const float& component(int i) const {return q.m128_f32[i];}
};
template<class T> struct CutLinks {
    T* next;
    T* prev;
    CutLinks() {}
    CutLinks(const CutLinks&) {}
};
struct CutVertex : CutLinks<CutVertex> {
    CutVec position,attribute,distance;
    int tag40,tag44;
    CutVertex():tag40(-1),tag44(-1) {}
    __forceinline int compare(const CutVertex& other) const {
        for(int axis=0;axis<3;++axis) {
            if(position.component(axis)<other.position.component(axis)) return -1;
            if(position.component(axis)>other.position.component(axis)) return 1;
        }
        return 0;
    }
    static __forceinline bool ordered(const CutVertex* first,const CutVertex* second) {
        const int order=first->compare(*second);
        if(order<0) return true;
        if(order>0) return false;
        return true;
    }
    typedef CutVertex Data;
};
struct CutTriangle;
template<class T> struct CutTopology : CutLinks<T> {
    CutVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline CutVertex*& vertex(int i) {return m_kVertices[i];}
    __forceinline unsigned int& link(int i) {return m_ppLinks[i];}
};
struct CutWords {unsigned int x,y,z,w;};
struct __declspec(align(16)) CutPlaneBits : CutWords {};
struct CutTriangle : CutTopology<CutTriangle> {
    CutPlaneBits normal;
    int side, unk34, unk38, unk3c, unk40;
    typedef CutTriangle Data;
};
static __forceinline unsigned long cutPack(void* tri,unsigned int index) {
    return reinterpret_cast<const unsigned long&>(tri)+(unsigned long)index;
}
template<class T> static __forceinline void cutUnpack(unsigned long bits,T*& tri,unsigned int& index) {
    index=bits&3;
    bits&=~3u;
    tri=reinterpret_cast<T*&>(bits);
}
struct CutEdge;
template<class E,class T> struct CutEdgeBase {
    T* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
    __forceinline CutEdgeBase(T* face,unsigned int index):m_pkTriangle(face),m_uiEdgeIndex(index) {}
    __forceinline CutEdgeBase(const unsigned int& packed) {
        cutUnpack(packed,m_pkTriangle,m_uiEdgeIndex);
    }
    __forceinline T* triangle() const {return m_pkTriangle;}
    __forceinline bool isValid() const {return m_pkTriangle!=0;}
    __forceinline E next() const {return E(m_pkTriangle,(9>>(m_uiEdgeIndex<<1))&3);}
    __forceinline E prev() const {return E(m_pkTriangle,(18>>(m_uiEdgeIndex<<1))&3);}
    __forceinline E link() const {return E(m_pkTriangle->link(m_uiEdgeIndex));}
    __forceinline CutVertex*& start() const {return m_pkTriangle->vertex(m_uiEdgeIndex);}
    __forceinline CutVertex*& end() const {return m_pkTriangle->vertex((9>>(m_uiEdgeIndex<<1))&3);}
    __forceinline bool master() const {return CutVertex::ordered(start(),end()) || !link().isValid();}
    __forceinline void unbind() const {
        if(link().isValid()) {
            E other=link();
            other.m_pkTriangle->link(other.m_uiEdgeIndex)=0;
        }
        m_pkTriangle->link(m_uiEdgeIndex)=0;
    }
    __forceinline void bind(const CutEdgeBase& other) const {
        m_pkTriangle->link(m_uiEdgeIndex)=cutPack(other.m_pkTriangle,other.m_uiEdgeIndex);
        if(other.m_pkTriangle) other.m_pkTriangle->link(other.m_uiEdgeIndex)=cutPack(m_pkTriangle,m_uiEdgeIndex);
    }
};
struct CutEdge:CutEdgeBase<CutEdge,CutTriangle> {
    typedef CutEdgeBase<CutEdge,CutTriangle> Base;
    __forceinline CutEdge(CutTriangle* t,unsigned int i):Base(t,i) {}
    __forceinline CutEdge(const unsigned int& packed):Base(packed) {}
    __forceinline CutEdge(const CutEdge& e):Base(e.m_pkTriangle,e.m_uiEdgeIndex) {}
};
struct CutBlock {
    PoolItemAB items[32];
    PoolItemAB* free;
    int used;
};
struct CutFreeList {
    CutBlock** blocks;
    int numBlocks;
    int capacity;
    CutBlock* FUN_00e23530();
};
template<class T> struct CutPool : CutFreeList {
    T* head;
    int count;
    void FUN_00e22f90(T*);
    __forceinline void remove(T* node) {
        T* next=(T*)node->next;
        T* prev=(T*)node->prev;
        if(next) next->prev=prev;
        if(prev) prev->next=next;
        else head=next;
        --count;
        FUN_00e22f90(node);
    }
    __forceinline T* allocate(const typename T::Data& source) {
        CutBlock* block;
        if (numBlocks && blocks[0]->free) block = blocks[0];
        else block = FUN_00e23530();
        T* node=(T*)block->free;
        block->free=(PoolItemAB*)node->next;
        ++block->used;
        new (node) T(source);
        node->prev=0;
        node->next=head;
        if(head) head->prev=node;
        ++count;
        head=node;
        return node;
    }
};
template<> __forceinline CutTriangle* CutPool<CutTriangle>::allocate(const CutTriangle& source) {
    CutBlock* block;
    if(numBlocks && blocks[0]->free) block=blocks[0];
    else block=FUN_00e23530();
    CutTriangle* node=(CutTriangle*)block->free;
    block->free=(PoolItemAB*)node->next;
    ++block->used;
    new (node) CutTriangle(source);
    node->prev=0;
    node->next=head;
    if(head) head->prev=node;
    ++count;
    head=node;
    return node;
}

namespace N {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    struct { float x, y, z, w; };
} __m128;
extern "C" {
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, int);
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*, __m128);
}
}

extern __m128 DAT_010c7160;

struct S00e22640_Pair { int lo; int hi; };
void __cdecl FUN_00c908c0(void* allocator, void* self, int newCap, int elemSize);
template <typename T>
struct S00e22640_hkArray {
    T* m_data; int m_iElementCount; int m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(void* alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    static __forceinline void constructWithArray(T* t, int n, const T* tcopy)
    {
        for (int i = 0; i < n; ++i) {
            new (t + i) T(tcopy[i]);
        }
    }
    __forceinline void append(void* alloc, const T* a, int numElems)
    {
        int newsize = m_iElementCount + numElems;
        if (newsize > getCapacity()) {
            reserve(alloc, newsize);
        }
        constructWithArray(m_data + m_iElementCount, numElems, a);
        m_iElementCount = newsize;
    }
};
struct S00e22640_Arr : S00e22640_hkArray<S00e22640_Pair> {
    void FUN_00e22640(void* allocator, const S00e22640_Pair* src, int n);
};
// Appends n elements from src to the array using the allocator.
// @fnv 0x00e22640
void S00e22640_Arr::FUN_00e22640(void* allocator, const S00e22640_Pair* src, int aiCount)
{
    append(allocator, src, aiCount);
}

__forceinline int delayValue(int value,int) {return value;}
__forceinline int delayValue(int value) {_ReadWriteBarrier();return value;}

struct Face;
struct LayerVertex {
    int unk00, unk04;
    int unk08, unk0c;
    __forceinline int compare(const LayerVertex& b) const {
        if (unk08 < b.unk08) return -1;
        if (unk08 > b.unk08) return 1;
        if (unk0c < b.unk0c) return -1;
        if (unk0c > b.unk0c) return 1;
        return 0;
    }
    static __forceinline bool ordered(const LayerVertex* a, const LayerVertex* b) {
        int cmp=a->compare(*b);
        if(cmp < 0) return true;
        if(cmp > 0) return false;
        return true;
    }
};
struct Face {
    Face* m_next;
    int unk04;
    LayerVertex* m_kVertices[3];
    unsigned int m_kEdges[3];
    struct { unsigned short marks:3; unsigned short root:1; unsigned short region:12; } bits;
    unsigned short unk22;
    __forceinline LayerVertex*& vertex(int i) { return m_kVertices[i]; }
    __forceinline unsigned int& link(int i) { return m_kEdges[i]; }
};
template<class E, class T> struct LayerCore {
    T* m_face;
    unsigned int m_uiEdgeIndex;
    __forceinline LayerCore() {}
    __forceinline LayerCore(T* t, unsigned i):m_face(t),m_uiEdgeIndex(i){}
    __forceinline LayerCore(const unsigned int& id) { unpack(id,m_face,m_uiEdgeIndex); }
    static __forceinline void unpack(unsigned id,T*& t,unsigned& i) {
        i=id & 3; id &= ~3u; t=(T*)id;
    }
    __forceinline E next() const { return E(m_face,(9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline E link() const { return E(m_face->link(m_uiEdgeIndex)); }
    __forceinline T* triangle() const { return m_face; }
    __forceinline LayerVertex*& start() const { return m_face->vertex(m_uiEdgeIndex); }
    __forceinline LayerVertex*& end() const { return m_face->vertex((9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline bool valid() const { return m_face!=0; }
    __forceinline bool unlinked() const { return !link().valid(); }
    __forceinline bool isMaster() const { return LayerVertex::ordered(start(),end()) || unlinked(); }
    __forceinline E canonical() const {
        if(isMaster()) return E(m_face,m_uiEdgeIndex);
        else return link();
    }
};
struct LayerEdge : LayerCore<LayerEdge,Face> {
    typedef LayerCore<LayerEdge,Face> Base;
    __forceinline LayerEdge() {}
    __forceinline LayerEdge(Face* f,unsigned i):Base(f,i){}
    __forceinline LayerEdge(const unsigned int& id):Base(id){}
    __forceinline LayerEdge(const LayerEdge& b):Base(b.m_face,b.m_uiEdgeIndex){}
    __forceinline bool constrained() const {
        LayerEdge c=canonical();
        return (_ReadWriteBarrier(),0) != (c.m_face->bits.marks & (1 << (unsigned char)c.m_uiEdgeIndex));
    }
};
struct QueryResult { int unk00; LayerEdge m_kEdge; };
template <typename T>
struct EdgeArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }
    void clear() { m_iElementCount = 0; }

    void AddBack(const T& val) throw() {
        Router& router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(router.heap, this, sizeof(T));
        }
        new (&m_data[m_iElementCount]) T(val);
        m_iElementCount++;
    }
};

template <typename T, int N>
struct InplaceEdgeArray : public EdgeArray<T> {
    T m_kStorage[N];

    InplaceEdgeArray() throw() {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000 | N;
    }

    ~InplaceEdgeArray() throw() {
        Allocator& heap = FUN_00c85750().getHeap();
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0) {
            heap.freeBlock(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};

struct Mesh {
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
    Face* m_faces;
    int unk38;
    int unk3c;
    InplaceEdgeArray<LayerEdge,64> m_kEdges;

    QueryResult* LocatePoint(QueryResult* res, int unk1, int unk2) throw();
    int FUN_00e24b70();
};

void __cdecl ResizeAudioStream(void*, void*, int);
typedef unsigned long S00e25cd0_Ulong;
template<class T> static __forceinline void S00e25cd0_constructWithCopy(T* t, int n, const T& tcopy) {
    for(int i=0; i<n; ++i) {
        t[i] = tcopy;
    }
}
template<class T> struct S00e25cd0_Array {
    T* m_data; int m_iElementCount; int m_iCapacityState;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline int indexOf(const T& t, int startIdx=0, int endIdx=-1) const {
        if(endIdx < 0) endIdx = m_iElementCount;
        for(int i=startIdx; i<endIdx; ++i) {
            if(m_data[i] == t) return i;
        }
        return -1;
    }
    __forceinline T& AllocatePair() {
        Router& router = FUN_00c85750();
        if(m_iElementCount == (m_iCapacityState & 0x3fffffff)) ResizeAudioStream(router.heap, this, sizeof(T));
        for(int i=0; i<1; ++i) new(m_data+m_iElementCount+i) T;
        return m_data[m_iElementCount++];
    }
    __forceinline void AddBack(const T& t) {
        Router& router = FUN_00c85750();
        if(m_iElementCount == (m_iCapacityState & 0x3fffffff)) ResizeAudioStream(router.heap, this, sizeof(T));
        S00e25cd0_constructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
struct S00e25cd0_EdgeData : S00e25cd0_Array<S00e25cd0_Ulong> {
    S00e25cd0_Ulong m_inline[4];
    __forceinline S00e25cd0_EdgeData() { m_data=m_inline; m_iElementCount=0; m_iCapacityState=0x80000004; }
    __forceinline void appendOrReplace(const S00e25cd0_Array<S00e25cd0_Ulong>& data) {
        for(int i=0; i<data.GetLogicalSize(); ++i) {
            if(indexOf(data[i]) == -1) AddBack(data[i]);
        }
    }
};
struct S00e25cd0_Vertex {
    int unk00, unk04;
    int m_uiX, m_uiY;
    __forceinline S00e25cd0_Ulong pack() const { return (m_uiX << 15) + m_uiY; }
};
struct S00e25cd0_Triangle {
    int unk00, unk04;
    S00e25cd0_Vertex* m_kVertices[3];
    __forceinline S00e25cd0_Vertex*& vertex(unsigned i) { return m_kVertices[i]; }
};
struct S00e25cd0_Edge {
    S00e25cd0_Triangle* m_pkTriangle;
    unsigned m_uiEdgeIndex;
    static __forceinline unsigned ip1mod3(unsigned i) { return (0x09 >> (i << 1)) & 3; }
    __forceinline S00e25cd0_Vertex*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline S00e25cd0_Vertex*& end() const { return m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)); }
};
template<class A, class B> static __forceinline S00e25cd0_Ulong S00e25cd0_makeHash(A a, B b) {
    const S00e25cd0_Ulong va = *(const S00e25cd0_Ulong*)&a;
    const S00e25cd0_Ulong vb = *(const S00e25cd0_Ulong*)&b;
    return (va*3424933) ^ (vb*1661161);
}
struct S00e25cd0_Box {
    S00e25cd0_Vertex* m_kVertices[2];
    S00e25cd0_EdgeData* m_data;
    __forceinline S00e25cd0_Box() { m_kVertices[0]=m_kVertices[1]=0; m_data=0; }
    __forceinline S00e25cd0_Box(const S00e25cd0_Edge& edge) : m_data(0) {
        m_kVertices[0] = edge.start();
        m_kVertices[1] = edge.end();
    }
    __forceinline S00e25cd0_Ulong getHash() const { const S00e25cd0_Vertex* a = m_kVertices[0]; const S00e25cd0_Vertex* b = m_kVertices[1]; return S00e25cd0_makeHash(a->pack(), b->pack()); }
    __forceinline bool operator==(const S00e25cd0_Box& other) const { return m_kVertices[0]==other.m_kVertices[0] && m_kVertices[1]==other.m_kVertices[1]; }
};
struct S00e25cd0_Table {
    S00e25cd0_Array<S00e25cd0_Array<S00e25cd0_Box> > m_buckets;
    int m_numItems;
    __forceinline S00e25cd0_Array<S00e25cd0_Box>& lookupBucket(int hash) { return m_buckets[((unsigned)hash) % m_buckets.GetLogicalSize()]; }
    __forceinline S00e25cd0_Box* find(int hash, const S00e25cd0_Box& value) {
        S00e25cd0_Array<S00e25cd0_Box>& values = lookupBucket(hash);
        const int index = values.indexOf(value);
        if(index == -1) return 0;
        else return &values[index];
    }
    __forceinline S00e25cd0_Box* insert(int hash, const S00e25cd0_Box& value) {
        ++m_numItems;
        S00e25cd0_Array<S00e25cd0_Box>& values = lookupBucket(hash);
        values.AllocatePair() = value;
        return &values[values.GetLogicalSize()-1];
    }
    __forceinline S00e25cd0_Box* find(const S00e25cd0_Box& value) { return find((int)value.getHash(), value); }
    __forceinline S00e25cd0_Box* insert(const S00e25cd0_Box& value) { return insert((int)value.getHash(), value); }
};
struct S00e25cd0_Pool
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    S00e25cd0_EdgeData* m_380;
    int m_384;
};
struct S00e25cd0_PoolAlloc {
    S00e25cd0_Pool** data; int count; int cap;
    S00e25cd0_Pool* FUN_00e235d0();
    __forceinline S00e25cd0_EdgeData* allocate() {
        S00e25cd0_Pool* b;
        if(count == 0 || (b=data[0])->m_380 == 0) b=FUN_00e235d0();
        S00e25cd0_EdgeData* node=b->m_380;
        b->m_380 = (S00e25cd0_EdgeData*)node->m_data;
        ++b->m_384;
        return new(node) S00e25cd0_EdgeData;
    }
};

namespace fnv_00e275d0 {
struct FUN_00e25f00_cls { void FUN_00e25f00(int a); };
struct AllocOps { virtual void v0(); virtual void v1(); virtual void Free(void* p, int sz); };
struct Iface { virtual void s0(); virtual void s1(); virtual void s2(); virtual void Do(); };
struct Vert { int unk0,unk4,x,y; unsigned constrained:1,data:31; Vert() {} };
struct TriE275 : TriBase<Vert*> {
 unsigned int m_ppLinks[3]; unsigned short edges:3,root:1,region:12; unsigned short sets;
 __forceinline Vert*& vertex(int i) { return m_vtx[i]; }
__forceinline void corners(Vert* const& a,Vert* const& b,Vert* const& c) {m_vtx[0]=a;m_vtx[1]=b;m_vtx[2]=c;}
TriE275() {} __declspec(noinline) TriE275& FUN_00e23080(const TriE275& value);};
struct VBlock { Vert items[32]; Vert* free; int used; };
struct VPool { VBlock** blocks; int count,capacity; Vert* head; int numUsed,uid;
 VBlock* FUN_00e23670();
 __declspec(noinline) Vert* FUN_00e247c0(const Vert& k=Vert()); };
struct TBlock { TriE275 items[32]; TriE275* free; int used; };
struct TPool {
    TBlock** blocks; int count,capacity; TriE275* head; int numUsed,uid;
    TBlock* FUN_00e23710(); __declspec(noinline) TriE275* FUN_00e24850(const TriE275& k=TriE275());
};
__declspec(noinline) TriE275& TriE275::FUN_00e23080(const TriE275& value) {
 m_vtx[0]=value.m_vtx[0];m_vtx[1]=value.m_vtx[1];m_vtx[2]=value.m_vtx[2];
 m_ppLinks[0]=value.m_ppLinks[0];m_ppLinks[1]=value.m_ppLinks[1];m_ppLinks[2]=value.m_ppLinks[2];
 edges=value.edges;root=value.root;region=value.region;sets=value.sets;return *this;
}
__declspec(noinline) Vert* VPool::FUN_00e247c0(const Vert& value) {
 VBlock* block;
 if(count && blocks[0]->free) block=blocks[0]; else block=FUN_00e23670();
 Vert* item=block->free;block->free=(Vert*)item->unk0;++block->used;
 item->x=value.x;item->y=value.y;item->constrained=value.constrained;item->data=value.data;
 item->unk4=0;item->unk0=(int)head;if(head)head->unk4=(int)item;head=item;++numUsed;
 return item;
}
__declspec(noinline) TriE275* TPool::FUN_00e24850(const TriE275& value) {
 TBlock* block;
 if(count && blocks[0]->free) block=blocks[0]; else block=FUN_00e23710();
 TriE275* item=block->free;block->free=(TriE275*)item->m_unk00;++block->used;
 item->FUN_00e23080(value);
 item->m_unk04=0;item->m_unk00=(int)head;if(head)head->m_unk04=(int)item;head=item;++numUsed;
 return item;
}
struct MeshBoundaryEdge { TriE275* face; unsigned int index; MeshBoundaryEdge(TriE275* t,unsigned int i):face(t),index(i){}unsigned int uid() const {return (unsigned int)face+index;} unsigned int& link() const {return face->m_ppLinks[index];}void bind(MeshBoundaryEdge other) const {link()=other.uid();other.link()=uid();}};
struct EdgeWorkStack { S_00e13910_Edge* data; int size,capacity; S_00e13910_Edge storage[64]; };
struct Mesh {
    int unk0, unk4;
    Iface m_08;
    int unk0c;
    VPool m_10;
    TPool m_28;
    EdgeWorkStack m_aiEntries;
    FUN_00e25f00_cls* m_24c;
    int** m_250;
    int m_254;
    int unk258;
    TriE275* grid[256];
static __forceinline int gridCell(int horizontal,int vertical) {
 horizontal >>= 11; vertical >>= 11; return (vertical<<4)+horizontal;
}
__forceinline void indexFace(TriE275* face) {
 const int horizontal=(face->vertex(0)->x+face->vertex(1)->x+face->vertex(2)->x)/3;
 const int vertical=(face->vertex(0)->y+face->vertex(1)->y+face->vertex(2)->y)/3;
 grid[gridCell(horizontal,vertical)]=face;
 face->root=1;
}
__forceinline TriE275* createFace(Vert* a,Vert* b,Vert* c) {
  TriE275* result=m_28.FUN_00e24850();
 result->corners(a,b,c);
 result->edges=0; result->region=0; result->root=0; result->sets=0;
 indexFace(result); return result;
}
__forceinline Vert* createCorner(int x,int y,int constrained) {
  Vert* p=m_10.FUN_00e247c0();
 p->x=x; p->y=y; p->constrained=constrained; p->data=0; p->data=~p->data; return p;
}
    void FUN_00e275d0(bool build);
};
// Calls m_08.Do, clears the grid, frees m_24c and the m_250 blocks, and when build is set creates two root triangles over a 0x7fff square.
// @fnv 0x00e275d0
void Mesh::FUN_00e275d0(bool abBuildRoots)
{
    m_08.Do();
    for (int i=0;i<256;i++) grid[i]=0;
    if (m_24c) {
        AllocOps* pAllocOps = (AllocOps*)FUN_00c85750().heap;
        m_24c->FUN_00e25f00(0);
        pAllocOps->Free(m_24c, 0x10);
        m_24c = 0;
    }
    for (int i = 0; i < m_254; i++) {
        int* p = m_250[i];
        Router& r = FUN_00c85750();
        AllocOps* pAllocOps = (AllocOps*)r.heap;
        pAllocOps->Free(p, 0x388);
    }
    m_254 = 0;
    if (abBuildRoots) {
Vert* v0=createCorner(0,0,0); Vert* v1=createCorner(0,0x7fff,0);
 Vert* v2=createCorner(0x7fff,0,0); Vert* v3=createCorner(0x7fff,0x7fff,0);
 TriE275* t1=createFace(v0,v2,v3); TriE275* t2=createFace(v0,v3,v1);
t1->m_ppLinks[0]=t1->m_ppLinks[1]=t1->m_ppLinks[2]=0;t2->m_ppLinks[0]=t2->m_ppLinks[1]=t2->m_ppLinks[2]=0;MeshBoundaryEdge(t1,2).bind(MeshBoundaryEdge(t2,0));
    }
}
}  // namespace fnv_00e275d0

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
struct __declspec(align(16)) BoundVec { union { __m128 q; float f[4]; }; };
extern "C" __m128 _mm_set_ps(float w, float z, float y, float x);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern float DAT_0104e148;
extern const float DAT_01011d78;
extern double DAT_01011588;
extern double DAT_01029790;
struct BigConst { Float4 v[4]; };
extern BigConst DAT_0126a3e0;

namespace fnv_00e12890 {
// FUN_00e12890: collect the linked list at this+0x2c into an output vector,
// marking nodes when a flag byte is set, then sort the collected pointers.

struct FUN_00e12890_Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

FUN_00e12890_Holder* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void* allocator, void* list, int count, int elemSize);

}  // namespace fnv_00e12890

namespace fnv_00e15830 {
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }

struct S_00e15830_Heap {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00e15830_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e15830_Heap* m_pStreamAllocator;
    S_00e15830_Heap& heap() throw() { return *m_pStreamAllocator; }
};

S_00e15830_Router& FUN_00c85750() throw();
void ResizeAudioStream(S_00e15830_Heap& alloc, void* array, int elemSize) throw();

template <typename T>
struct S_00e15830_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00e15830_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00e15830_Array() throw() { _clearAndDeallocate(FUN_00c85750().heap()); }

    int getCapacity() const throw() { return m_iCapacityState & 0x3fffffff; }
    int GetLogicalSize() const throw() { return m_iElementCount; }
    void clear() throw() { m_iElementCount = 0; }
    T& back() throw() { return m_data[m_iElementCount - 1]; }
    void popBack() throw() { m_iElementCount--; }

    void _pushBack(S_00e15830_Heap& alloc, const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
    void AddBack(const T& t) throw() { _pushBack(FUN_00c85750().heap(), t); }

    void _clearAndDeallocate(S_00e15830_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct S_00e15830_Node {
    S_00e15830_Node* m_next;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_iValueAt0x30;
    int unk34;
    int m_iMaterialIndex;
};

struct S_00e15830_Edge {
    S_00e15830_Node* m_node;
    int m_uiEdgeIndex;
    S_00e15830_Edge(S_00e15830_Node* n, int i) throw() : m_node(n), m_uiEdgeIndex(i) {}
    unsigned int link() const throw() { return m_node->m_ppLinks[m_uiEdgeIndex]; }
    S_00e15830_Edge linked() const throw() { return S_00e15830_Edge((S_00e15830_Node*)(link() & ~3u), link() & 3); }
    bool sameMaterial() const throw()
    {
        unsigned int l = link();
        return (l & ~3u) == 0 || m_node->m_iMaterialIndex == ((S_00e15830_Node*)(l & ~3u))->m_iMaterialIndex;
    }
};

}  // namespace fnv_00e15830

typedef float QhkReal;
typedef unsigned char QhkUint8;
typedef unsigned short QhkUint16;
typedef unsigned int QhkUint32;
typedef unsigned long __w64 QhkUlong;
enum QhkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 Qhk_size_t;class QhkFinishLoadedObjectFlag
{
public:
QhkFinishLoadedObjectFlag():m_bFinishing(0){}
int m_bFinishing;
};
class QhkBool
{
public:
typedef char CompileTimeTrueType;inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
template<typename TYPE>
class QhkPadSpu
{
public:
__forceinline QhkPadSpu(){}
private:
TYPE m_kStorage;};
template<typename T>struct QhkSizeOfTypeOrVoid{enum{val=sizeof(T)};};
class Qmemrouter;
namespace Qr{Qmemrouter&__cdecl FUN_00c85750() throw();}
void __cdecl ResizeAudioStream(void*,void*,int) throw();
class Qmemalloc
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t,void*p){return p;}
virtual ~Qmemalloc();
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;
virtual void*AllocateBufferWithSize(int&reqNumBytesInOut);
virtual void ReturnMemory(void*p,int numBytes);template<typename TYPE>
inline void _bufFree(void*p,int numElem)
{
const int SIZE_ELEM=QhkSizeOfTypeOrVoid<TYPE>::val;
ReturnMemory(p,numElem*SIZE_ELEM);
}
public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct QhkStackMemory
{
public:
__forceinline QhkStackMemory();protected:
QhkPadSpu<void*>m_next;
QhkPadSpu<void*>m_kRayStart;
QhkPadSpu<void*>m_kRayEnd;};
class Qmemrouter
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t,void*p){return p;}
typedef Qmemalloc Allocator;
static Qmemrouter&__cdecl GetMonitorStream(){return Qr::FUN_00c85750();}inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
QhkStackMemory m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;
Allocator*m_pDebugAllocator;};
class QhkBaseObject
{
public:
static const struct QhkInternalClassMember Members[];
__forceinline virtual ~QhkBaseObject(){}
public:
__forceinline QhkBaseObject(){}
};
class QhkReferencedObject:public QhkBaseObject
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;QhkReferencedObject*b=static_cast<QhkReferencedObject*>(Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<QhkUint16>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
QhkUint16 m_usMemSizeAndFlags;
public:
QhkReferencedObject(class QhkFinishLoadedObjectFlag flag){}
};template<bool N>struct QhkTraitBool{typedef QhkTraitBool<N>type;enum{result=N};};
typedef QhkTraitBool<true>QhkTypeIsPod;
template<typename T>
struct QhkIsPodType:public QhkTraitBool<(sizeof(*static_cast<T*>(0)==*static_cast<const QhkTypeIsPod*>(0))==sizeof(QhkBool::CompileTimeTrueType))>{};
class QhkArrayUtil
{
public:
template<typename T>static __forceinline void construct(T*t,int n,QhkTypeIsPod);
template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,QhkTypeIsPod);
template<typename T>static __forceinline void destruct(T*t,int n,QhkTypeIsPod);
static void __cdecl GrowArray(Qmemalloc&a,void*array,int sizeElem){ResizeAudioStream(&a,array,sizeElem);}};template<typename T>
__forceinline void QhkArrayUtil::constructWithCopy(T*t,int n,const T&tcopy,QhkTypeIsPod)
{
for(int i=0;i<n;++i)
{
t[i]=tcopy;
}
}
template<typename T>
__forceinline void QhkArrayUtil::destruct(T*t,int n,QhkTypeIsPod)
{
}
struct QhkContainerHeapAllocator
{
Qmemalloc&get(const void*){return Qmemrouter::GetMonitorStream().heap();}
};
template<typename T>
class QhkArrayBase
{
public:
typedef QhkArrayBase<T>ThisType;
__forceinline QhkArrayBase();
protected:
__forceinline QhkArrayBase(const QhkArrayBase&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline ~QhkArrayBase();
__forceinline T&operator[](int i);
__forceinline int GetLogicalSize()const;
__forceinline int getCapacity()const;
__forceinline void clear();
__forceinline void _clearAndDeallocate(Qmemalloc&alloc);
__forceinline void _pushBack(Qmemalloc&alloc,const T&e);
protected:
__forceinline QhkArrayBase<T>&copyFromArray(Qmemalloc&,const QhkArrayBase<T>&src,QhkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class QhkStatisticsCollector;
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
QhkArrayBase(QhkFinishLoadedObjectFlag f){}
};
template<typename T,typename Allocator=QhkContainerHeapAllocator>
class QhkArray:public QhkArrayBase<T>
{
public:
typedef Allocator AllocatorType;
__forceinline QhkArray():QhkArrayBase<T>(){}
__forceinline ~QhkArray();protected:
__forceinline QhkArray(const QhkArray&a);
public:
__forceinline QhkArray&operator=(const QhkArrayBase<T>&a);
__forceinline void ClearAndRelease(){QhkArrayBase<T>::_clearAndDeallocate(AllocatorType().get(this));}
__forceinline void AddBack(const T&e){QhkArrayBase<T>::_pushBack(AllocatorType().get(this),e);}
};
template<typename T>
__forceinline T&QhkArrayBase<T>::operator[](int i)
{
;
return m_data[i];
}
template<typename T>
__forceinline int QhkArrayBase<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
__forceinline int QhkArrayBase<T>::getCapacity()const
{
return(m_iCapacityState&static_cast<int>(CAPACITY_MASK));
}
template<typename T>
__forceinline void QhkArrayBase<T>::clear()
{
QhkArrayUtil::destruct(m_data,m_iElementCount,typename QhkIsPodType<T>::type());
m_iElementCount=0;
}
template<typename T>
__forceinline QhkArrayBase<T>::QhkArrayBase()
:m_data(0),
m_iElementCount(0),
m_iCapacityState(DONT_DEALLOCATE_FLAG)
{
}
template<typename T>
__forceinline QhkArrayBase<T>::~QhkArrayBase()
{
;
;
}
template<typename T>
__forceinline void QhkArrayBase<T>::_clearAndDeallocate(Qmemalloc&alloc)
{
clear();
if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0)
{
alloc._bufFree<T>(m_data,getCapacity());
}
m_data=0;
m_iCapacityState=DONT_DEALLOCATE_FLAG;
}
template<typename T>
__forceinline void QhkArrayBase<T>::_pushBack(Qmemalloc&alloc,const T&t)
{
if(m_iElementCount==getCapacity())
{
;
QhkArrayUtil::GrowArray(alloc,this,sizeof(T));
}
QhkArrayUtil::constructWithCopy(m_data+m_iElementCount,1,t,typename QhkIsPodType<T>::type());
m_iElementCount++;}
template<typename T,typename Allocator>
__forceinline QhkArray<T,Allocator>::~QhkArray()
{
ClearAndRelease();
}
typedef __m128 QhkQuadReal;
class QhkSimdReal
{
public:
QhkSimdReal(const QhkQuadReal&x)
:m_vValue(x)
{
}
QhkSimdReal(QhkReal x)
{
m_vValue=_mm_load_ss(&x);
}
operator QhkReal()const
{
QhkReal s;
_mm_store_ss(&s,m_vValue);
return s;
}
__forceinline QhkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
private:
QhkQuadReal m_vValue;};
typedef const QhkSimdReal&QhkSimdRealParameter;namespace QhkMath
{
inline QhkReal __cdecl sqrt(QhkReal r){return::sqrtf(r);}
inline QhkReal __cdecl fabs(QhkReal r){return::fabsf(r);}
}
class QhkVector4
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
QhkBool::CompileTimeTrueType operator==(const QhkTypeIsPod&)const;
__forceinline void operator=(const QhkVector4&v);
__forceinline void setInt24W(int value);
__forceinline void add4(const QhkVector4&a);
__forceinline void setSub4(const QhkVector4&a,const QhkVector4&b);
__forceinline void mul4(QhkSimdRealParameter a);
__forceinline void setAddMul4(const QhkVector4&a,const QhkVector4&b,QhkSimdRealParameter r);
__forceinline void setMin4(const QhkVector4&a,const QhkVector4&b);
__forceinline void setMax4(const QhkVector4&a,const QhkVector4&b);
__forceinline QhkSimdReal dot3(const QhkVector4&a)const;
__forceinline QhkSimdReal lengthSquared3()const;
__forceinline QhkResult normalize3IfNotZero();
__forceinline QhkReal&operator()(int i);
__forceinline const QhkReal&operator()(int i)const;
QhkBool FUN_00c7f520(QhkReal eps=1e-4f)const throw();
private:
QhkQuadReal m_vComponents;
public:
operator QhkQuadReal()const
{
return m_vComponents;
}
};class QhkMatrix3
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline QhkVector4&getColumn(int i);
QhkSimdReal FUN_00cd51c0() throw();
protected:
QhkVector4 m_kColumn0;
QhkVector4 m_kColumn1;
QhkVector4 m_kColumn2;};inline void QhkVector4::operator=(const QhkVector4&v)
{
m_vComponents=v.m_vComponents;
}
void QhkVector4::setInt24W(int value)
{
(reinterpret_cast<QhkUint32*>(this))[3]=value |=0x3f000000;
}
inline void QhkVector4::setSub4(const QhkVector4&v0,const QhkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void QhkVector4::mul4(QhkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline QhkSimdReal QhkVector4::dot3(const QhkVector4&a)const
{
QhkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
QhkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline QhkSimdReal QhkVector4::lengthSquared3()const
{
return this->dot3(*this);
}
inline QhkReal&QhkVector4::operator()(int a)
{
return reinterpret_cast<QhkReal*>(&m_vComponents)[a];
}
inline const QhkReal&QhkVector4::operator()(int a)const
{
return reinterpret_cast<const QhkReal*>(&m_vComponents)[a];
}
class QhkAabb
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
QhkVector4 m_kMinimumCorner;
QhkVector4 m_kMaximumCorner;};
struct QhkGeometryProcessing
{
template<typename T,const int N,typename ALLOCATOR=QhkContainerHeapAllocator>
struct DynamicMemoryAllocator
{
struct Item
{
QhkUint8 m_data[sizeof(T)];
};
struct Pool
{
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Pool));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
Item m_items[N];
Item*m_free;
int m_uiBufferCapacity;
};
inline DynamicMemoryAllocator(){}
inline ~DynamicMemoryAllocator();
__forceinline T*allocate(){return(new(allocateItem())T());}
__forceinline T*allocate(const T&value){return(new(allocateItem())T(value));}
inline void release(T*item);
__forceinline bool needRelease()const{return(false);}
__forceinline void clear();
private:
inline Item*allocateItem();
inline Pool*GetOrCreatePool();
inline void releasePool(Pool*pool)const;
DynamicMemoryAllocator(const DynamicMemoryAllocator&){}
void operator=(const DynamicMemoryAllocator&){}
private:
QhkArray<Pool*,ALLOCATOR>m_pools;
};
static __forceinline QhkReal tetrahedronVolume6(const QhkVector4&a,const QhkVector4&b,const QhkVector4&c,const QhkVector4&d);};__forceinline QhkReal QhkGeometryProcessing::tetrahedronVolume6(const QhkVector4&a,const QhkVector4&b,const QhkVector4&c,const QhkVector4&d)
{
QhkMatrix3 m;
m.getColumn(0).setSub4(b,a);
m.getColumn(1).setSub4(c,a);
m.getColumn(2).setSub4(d,a);
return(m.FUN_00cd51c0());
}
class QhkgpTopology
{
public:
static __forceinline QhkUlong uid2ulong(void*t,QhkUint32 i){return(*(const QhkUlong*)&t)+(QhkUlong)i;}
template<typename T>
static __forceinline void ulong2uid(QhkUlong uid,T*&t,QhkUint32&i){i=(QhkUint32)(uid&3);uid&=~3;t=*(T**)&uid;}
typedef QhkUlong Uid;template<typename T>
static __forceinline void unpackUid(Uid uid,T*&t,QhkUint32&i){ulong2uid(uid,t,i);}
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER=VERTEX*>
struct Edge
{
public:
typedef VERTEX tVertex;
typedef VERTEX_MEMBER tMVertex;
typedef TRIANGLE tTriangle;
protected:
static __forceinline unsigned ip1mod3(unsigned i);
static __forceinline unsigned ip2mod3(unsigned i);
public:
__forceinline static const EDGE&null(){static const EDGE e(0,0);return(e);}
public:
__forceinline Edge(){}
__forceinline Edge(tTriangle*t,unsigned i):m_pkTriangle(t),m_uiEdgeIndex(i){}
__forceinline Edge(const Uid&id){unpackUid(id,m_pkTriangle,m_uiEdgeIndex);}
__forceinline EDGE next()const{return(EDGE(m_pkTriangle,ip1mod3(m_uiEdgeIndex)));}
__forceinline EDGE prev()const{return(EDGE(m_pkTriangle,ip2mod3(m_uiEdgeIndex)));}
__forceinline EDGE link()const{return(EDGE(m_pkTriangle->link(m_uiEdgeIndex)));}
__forceinline EDGE turnCcw()const{return(link().next());}
__forceinline EDGE turnCw()const{return(prev().link());}
__forceinline EDGE nextCw()const{return(link().prev());}
__forceinline EDGE nextCcw()const{return(link().next());}
__forceinline EDGE prevCw()const{return(prev().link());}
__forceinline EDGE prevCcw()const{return(next().link());}
__forceinline EDGE master()const{if(isMaster())return(EDGE(m_pkTriangle,m_uiEdgeIndex));else return(link());}
__forceinline TRIANGLE*triangle()const{return(m_pkTriangle);}
__forceinline int index()const{return((int)m_uiEdgeIndex);}
__forceinline Uid uid()const{return packUid(m_pkTriangle,m_uiEdgeIndex);}
__forceinline tMVertex&start()const{return(m_pkTriangle->vertex(m_uiEdgeIndex));}
__forceinline tMVertex&end()const{return(m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)));}
__forceinline tMVertex&apex()const{return(m_pkTriangle->vertex(ip2mod3(m_uiEdgeIndex)));}
__forceinline EDGE self()const{return(EDGE(m_pkTriangle,m_uiEdgeIndex));}
__forceinline bool isValid()const{return(triangle()!=0);}
__forceinline bool isMaster()const{return(tVertex::isOrdered(start(),end())||isNaked());}
__forceinline bool isNaked()const{return(!link().isValid());}
__forceinline bool isBound()const{return(!isNaked());}
__forceinline bool canBind(const Edge&edge)const{return((!edge.isValid())||((start()==edge.end())&&(end()==edge.start())));}
__forceinline bool tryBind(const Edge&edge)const{const bool cb(canBind(edge));if(cb)bind(edge);return(cb);}
__forceinline void bind(const Edge&edge)const;
__forceinline void bindSides()const;
__forceinline void unbind()const;
__forceinline EDGE flip()const;
template<typename FNC>
__forceinline void applyFan(FNC&fnc)const;
__forceinline bool operator==(const EDGE&e)const{return(uid()==e.uid());}
__forceinline bool operator!=(const EDGE&e)const{return(uid()!=e.uid());}
protected:
tTriangle*m_pkTriangle;
QhkUint32 m_uiEdgeIndex;
};};
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER>
__forceinline unsigned QhkgpTopology::Edge<EDGE,VERTEX,TRIANGLE,VERTEX_MEMBER>::ip1mod3(unsigned i)
{
;
return((0x09>>(i<<1))&3);
}
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER>
__forceinline unsigned QhkgpTopology::Edge<EDGE,VERTEX,TRIANGLE,VERTEX_MEMBER>::ip2mod3(unsigned i)
{
;
return((0x12>>(i<<1))&3);
}
struct QhkgpAbstractMeshDefinitions
{
typedef QhkgpTopology::Uid Uid;
template<typename T,typename BASE,typename ALLOCATOR=QhkGeometryProcessing::DynamicMemoryAllocator<T,32>>
struct List
{
struct Item:BASE
{
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Item));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__forceinline T*next()const{return(m_next);}
__forceinline T*&next(){return(m_next);}
__forceinline T*prev()const{return(m_pSecondNode);}
__forceinline T*&prev(){return(m_pSecondNode);}
public:
Item():BASE(){}
Item&operator=(const Item&){return(*this);}
protected:
Item(const Item&other):BASE(other){}
private:
T*m_next;
T*m_pSecondNode;
};
List():m_uiBufferCapacity(0),m_iAllocatedCount(0){}
inline ~List();
inline void reset();
inline T*allocate(const T&value=T());
inline void release(T*item);
inline void moveUp(T*item);
inline void moveDown(T*item);
__forceinline T*getFirst()const{return(m_uiBufferCapacity);}
__forceinline T*getLast()const{T*t=getFirst();if(t){while(t->next())t=t->next();}return(t);}
__forceinline int GetLogicalSize()const{return(m_iAllocatedCount);}
private:
List(const List&){}
void operator=(const List&){}
private:
ALLOCATOR m_pThreadAllocator;
T*m_uiBufferCapacity;
int m_iAllocatedCount;
QhkUint32 m_uiUniqueId;
};
template<typename VERTEX,typename BASE>
struct Vertex:List<VERTEX,BASE>::Item
{
typedef typename List<VERTEX,BASE>::Item tBase;
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Vertex));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static __forceinline bool isOrdered(const VERTEX*a,const VERTEX*b)
{
const int c((*a).compare(*b));
;
if(c<0)return(true);
if(c>0)return(false);
return(true);
}
};
template<typename TRIANGLE,typename BASE,typename VERTEX>
struct Triangle:List<TRIANGLE,BASE>::Item
{
typedef typename List<TRIANGLE,BASE>::Item tBase;
typedef const VERTEX&vParm;
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Triangle));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__forceinline void setVertices(vParm a,vParm b,vParm c){m_kVertices[0]=a;m_kVertices[1]=b;m_kVertices[2]=c;}
__forceinline bool hasReferences()const{return(0!=((link(0)|link(1)|link(2))>>2));}
__forceinline VERTEX vertex(int i)const{return(m_kVertices[i]);}
__forceinline VERTEX&vertex(int i){return(m_kVertices[i]);}
__forceinline Uid link(int i)const{return(m_ppLinks[i]);}
__forceinline Uid&link(int i){return(m_ppLinks[i]);}
private:
VERTEX m_kVertices[3];
Uid m_ppLinks[3];
};};
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename ALLOCATOR=QhkContainerHeapAllocator>
class QhkgpAbstractMesh:public QhkReferencedObject
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;QhkReferencedObject*b=static_cast<QhkReferencedObject*>(Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<QhkUint16>(nbytes);;return b;}typedef QhkGeometryProcessing::DynamicMemoryAllocator<VERTEX,32,ALLOCATOR>VertexPoolAllocator;
typedef QhkGeometryProcessing::DynamicMemoryAllocator<TRIANGLE,32,ALLOCATOR>TrianglePoolAllocator;
typedef QhkgpAbstractMeshDefinitions::List<VERTEX,typename VERTEX::tBase,VertexPoolAllocator>VertexList;
typedef QhkgpAbstractMeshDefinitions::List<TRIANGLE,typename VERTEX::tBase,TrianglePoolAllocator>TriangleList;
VertexList m_kVertices;
TriangleList m_uiTriangleCount;};struct QhkgpMeshBase
{
struct NoFieldStruct{};
struct PlaceholderType{};
struct Vertex:QhkgpAbstractMeshDefinitions::Vertex<Vertex,NoFieldStruct>
{
QhkVector4 m_vContactPosition;
QhkVector4 m_vHitNormal;
QhkVector4 m_data;
int m_refs;
int m_ucOperationType;
__forceinline int compare(const Vertex&v)const{for(int i=0;i<3;i++){if(m_vContactPosition(i)<v.m_vContactPosition(i))return-1;if(m_vContactPosition(i)>v.m_vContactPosition(i))return 1;}return 0;}
};
struct Triangle:QhkgpAbstractMeshDefinitions::Triangle<Triangle,PlaceholderType,Vertex*>
{
QhkVector4 m_kTriangleNormal;
int m_iTriangleIndex;
int m_iTriangleValueAtOffset0x38;
int m_iMaterialIndex;
int m_ucOperationType;
QhkUint32 m_uiTriangleFlags;
};
struct Edge:QhkgpTopology::Edge<Edge,Vertex,Triangle,Vertex*>
{
Edge(){}
Edge(Triangle*t,unsigned i):QhkgpTopology::Edge<Edge,Vertex,Triangle,Vertex*>(t,i){}
Edge(const QhkgpTopology::Uid&id):QhkgpTopology::Edge<Edge,Vertex,Triangle,Vertex*>(id){}
};};
class QhkgpMesh:public QhkgpAbstractMesh<QhkgpMeshBase::Edge,QhkgpMeshBase::Vertex,QhkgpMeshBase::Triangle,QhkContainerHeapAllocator>
{
public:
struct IConvexOverlap
{
struct IConvexShape
{
virtual ~IConvexShape(){}
virtual int getMaxIndex()const{return 0;}
virtual void GetSupportPoint(const QhkVector4&d,QhkVector4&sv)const=0;
virtual QhkAabb GetAxisAlignedBounds()const=0;
};
};
struct LineShape:IConvexOverlap::IConvexShape
{
LineShape(const QhkVector4&a,const QhkVector4&b):m_kPointA(a),m_kPointB(b){m_kPointA.setInt24W(0);m_kPointB.setInt24W(1);}
virtual void GetSupportPoint(const QhkVector4&d,QhkVector4&sv)const{sv=(d.dot3(m_kPointA)>d.dot3(m_kPointB))? m_kPointA:m_kPointB;}
virtual QhkAabb GetAxisAlignedBounds()const{QhkAabb r;r.m_kMinimumCorner=m_kPointA;r.m_kMinimumCorner.setMin4(m_kPointA,m_kPointB);r.m_kMaximumCorner.setMax4(m_kPointA,m_kPointB);return r;}
QhkVector4 m_kPointA;
QhkVector4 m_kPointB;
};
QhkReal FUN_00e144d0(QhkReal d,const QhkVector4&p,QhkVector4&out,int mode)const throw();
bool TestShapeHit(IConvexOverlap::IConvexShape*s,QhkReal r,bool b)const throw();
void FUN_00e175b0(QhkReal offset,QhkArray<QhkVector4>&edgesOut)const;
};

namespace fnv_00e1a7a0 {
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }

struct S_00e1a7a0_Heap {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00e1a7a0_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e1a7a0_Heap* m_pStreamAllocator;
    S_00e1a7a0_Heap& heap() throw() { return *m_pStreamAllocator; }
};

S_00e1a7a0_Router& FUN_00c85750() throw();
void ResizeAudioStream(S_00e1a7a0_Heap& alloc, void* array, int elemSize) throw();

template <typename T>
struct S_00e1a7a0_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~S_00e1a7a0_Array() throw() { _clearAndDeallocate(FUN_00c85750().heap()); }

    int getCapacity() const throw() { return m_iCapacityState & 0x3fffffff; }
    int GetLogicalSize() const throw() { return m_iElementCount; }
    T& operator[](int i) throw() { return m_data[i]; }

    void _pushBack(S_00e1a7a0_Heap& alloc, const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
    void AddBack(const T& t) throw() { _pushBack(FUN_00c85750().heap(), t); }

    void _clearAndDeallocate(S_00e1a7a0_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <typename T, int N>
struct S_00e1a7a0_InplaceArray : S_00e1a7a0_Array<T> {
    T m_kStorage[N];
    S_00e1a7a0_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

struct S_00e1a7a0_Vec4 {
    int x;
    int y;
    int z;
    int w;
};

struct S_00e1a7a0_VertexData {
    S_00e1a7a0_Vec4 m_kPointA;
    S_00e1a7a0_Vec4 m_kPointB;
    S_00e1a7a0_Vec4 m_iThirdValue;
    int m_numRefs;
    int m_ucOperationType;
    S_00e1a7a0_VertexData& operator=(const S_00e1a7a0_VertexData& o) throw()
    {
        m_kPointA = o.m_kPointA;
        m_kPointB = o.m_kPointB;
        m_iThirdValue = o.m_iThirdValue;
        m_numRefs = o.m_numRefs;
        m_ucOperationType = o.m_ucOperationType;
        return *this;
    }
};

struct S_00e1a7a0_Vertex {
    S_00e1a7a0_Vertex* m_next;
    S_00e1a7a0_Vertex* m_pSecondNode;
    int unk8;
    int unkC;
    S_00e1a7a0_VertexData m_data;
    int unk48;
    int unk4C;
};

struct S_00e1a7a0_Triangle {
    S_00e1a7a0_Triangle* m_next;
    S_00e1a7a0_Triangle* m_pSecondNode;
    S_00e1a7a0_Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct S_00e1a7a0_Edge {
    S_00e1a7a0_Triangle* m_pkTriangle;
    int m_uiEdgeIndex;
    S_00e1a7a0_Edge() throw() {}
    S_00e1a7a0_Edge(S_00e1a7a0_Triangle* t, int i) throw() : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    unsigned int uid() const throw() { return (unsigned int)m_pkTriangle + m_uiEdgeIndex; }
    bool isValid() const throw() { return m_pkTriangle != 0; }
    S_00e1a7a0_Vertex*& start() const throw() { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    S_00e1a7a0_Edge next() const throw() { return S_00e1a7a0_Edge(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3); }
    S_00e1a7a0_Edge prev() const throw() { return S_00e1a7a0_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    S_00e1a7a0_Edge link() const throw()
    {
        unsigned int l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        S_00e1a7a0_Edge e;
        e.m_uiEdgeIndex = l & 3;
        e.m_pkTriangle = (S_00e1a7a0_Triangle*)(l & ~3u);
        return e;
    }
};

struct S_00e1a7a0_Block {
    S_00e1a7a0_Vertex m_items[32];
    S_00e1a7a0_Vertex* m_free;
    int m_iAllocatedCount;
};

struct S_00e1a7a0_VertexList {
    S_00e1a7a0_Array<S_00e1a7a0_Block*> m_kBlocks;
    S_00e1a7a0_Vertex* m_uiBufferCapacity;
    int m_iAllocatedCount;

    S_00e1a7a0_Block* FUN_00e23530() throw();

    S_00e1a7a0_Vertex* allocate() throw()
    {
        S_00e1a7a0_Block* b;
        if (m_kBlocks.m_iElementCount == 0 || m_kBlocks.m_data[0]->m_free == 0)
            b = FUN_00e23530();
        else
            b = m_kBlocks.m_data[0];
        S_00e1a7a0_Vertex* it = b->m_free;
        b->m_free = it->m_next;
        b->m_iAllocatedCount++;
        return it;
    }
    S_00e1a7a0_Vertex* append(const S_00e1a7a0_VertexData& d) throw()
    {
        S_00e1a7a0_Vertex* it = allocate();
        it->m_data = d;
        it->m_pSecondNode = 0;
        it->m_next = m_uiBufferCapacity;
        if (m_uiBufferCapacity)
            m_uiBufferCapacity->m_pSecondNode = it;
        m_iAllocatedCount++;
        m_uiBufferCapacity = it;
        return it;
    }
};

struct S_00e1a7a0_Error {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};
extern S_00e1a7a0_Error* DAT_01268360;

}  // namespace fnv_00e1a7a0

extern "C" __m128 _mm_load_ss(const float*); 
extern "C" __m128 _mm_sub_ps(__m128,__m128);
extern "C" __m128 _mm_set_ps1(float);
// hkVector4 stand-in: four floats, SIMD access through a reinterpret cast
struct __declspec(align(16)) S_e1ce10_Vec4 {
    float x, y, z, w;
    __m128& q() { return *reinterpret_cast<__m128*>(this); }
    const __m128& q() const { return *reinterpret_cast<const __m128*>(this); }
    __forceinline void SetAllComponents(float a) { q() = _mm_set_ps1(a); }
    __forceinline void setSub4(const S_e1ce10_Vec4& a, const S_e1ce10_Vec4& b) { q() = _mm_sub_ps(a.q(), b.q()); }
    __forceinline void setAdd4(const S_e1ce10_Vec4& a, const S_e1ce10_Vec4& b) { q() = _mm_add_ps(a.q(), b.q()); }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    void FUN_00c7f640(const struct S_e1ce10_Transform& transform, const S_e1ce10_Vec4& p) throw();
};
struct S_e1ce10_Bool {
    char m_cBooleanValue;
    S_e1ce10_Bool() {}
    operator bool() const { return m_cBooleanValue != 0; }
};
struct S_e1ce10_Aabb {
    S_e1ce10_Vec4 m_kMinimumCorner;
    S_e1ce10_Vec4 m_kMaximumCorner;
};
// memory router / heap
void __cdecl FUN_00c908c0(void* alloc, void* arr, int numElem, int sizeElem) throw(); // GrowArrayCapacity
void __cdecl ResizeAudioStream(void* alloc, void* arr, int sizeElem) throw(); // GrowArray
struct S_e1ce10_Pod {};
struct S_e1ce10_Class {};
template <class T> struct S_e1ce10_IsPod { typedef S_e1ce10_Class type; };
template <class T> struct S_e1ce10_IsPod<T*> { typedef S_e1ce10_Pod type; };
struct S_e1ce10_ArrayUtil {
    template <class T> static __forceinline void construct(T* t, int n, S_e1ce10_Pod) throw() {}
    template <class T> static __forceinline void construct(T* t, int n, S_e1ce10_Class) throw()
    {
        for (int i = 0; i < n; ++i)
            ::new (reinterpret_cast<void*>(t + i)) T;
    }
    template <class T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, S_e1ce10_Pod) throw()
    {
        for (int i = 0; i < n; ++i)
            t[i] = tcopy;
    }
    template <class T> static __forceinline void destruct(T* t, int n, S_e1ce10_Pod) throw() {}
    template <class T> static __forceinline void destruct(T* t, int n, S_e1ce10_Class) throw()
    {
        for (int i = 0; i < n; ++i)
            static_cast<T*>(t)[i].~T();
    }
};
template <class T> struct S_e1ce10_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_e1ce10_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000) {}
    __forceinline ~S_e1ce10_Array() throw() { _clearAndDeallocate(FUN_00c85750().getHeap()); }
    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    __forceinline void clear() throw()
    {
        S_e1ce10_ArrayUtil::destruct(m_data, m_iElementCount, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(Allocator& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.freeBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = (int)0x80000000;
    }
    __forceinline void GrowArrayCapacity(Allocator& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_e1ce10_ArrayUtil::destruct(m_data + n, m_iElementCount - n, typename S_e1ce10_IsPod<T>::type());
        S_e1ce10_ArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount = n;
    }
    __forceinline void _setSize(Allocator& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_e1ce10_ArrayUtil::destruct(m_data + n, m_iElementCount - n, typename S_e1ce10_IsPod<T>::type());
        S_e1ce10_ArrayUtil::constructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw() { _setSize(FUN_00c85750().getHeap(), n); }
    __forceinline void SetSizeAndGrow(int n, const T& fill) throw() { _setSize(FUN_00c85750().getHeap(), n, fill); }
    __forceinline T& _expandOne(Allocator& alloc) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        S_e1ce10_ArrayUtil::construct(m_data + m_iElementCount, 1, typename S_e1ce10_IsPod<T>::type());
        return m_data[m_iElementCount++];
    }
    __forceinline T& AllocatePair() throw() { return _expandOne(FUN_00c85750().getHeap()); }
    __forceinline void _pushBack(Allocator& alloc, const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        S_e1ce10_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount++;
    }
    __forceinline void AddBack(const T& t) throw() { _pushBack(FUN_00c85750().getHeap(), t); }
    __forceinline int indexOf(const T& t, int startIdx = 0, int endIdx = -1) const throw()
    {
        if (endIdx < 0)
            endIdx = m_iElementCount;
        for (int i = startIdx; i < endIdx; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
// geometry input
struct S_e1ce10_Transform {
    S_e1ce10_Vec4 m_qRotation0;
};
// mesh elements (pool items: next/prev links, then the value)
template <class T> struct S_e1ce10_Item {
    T* m_next;
    T* m_pSecondNode;
    S_e1ce10_Item() {}
    S_e1ce10_Item(const S_e1ce10_Item&) {}
    S_e1ce10_Item& operator=(const S_e1ce10_Item&) { return *this; }
};
struct S_e1ce10_Triangle;
struct S_e1ce10_Vertex : S_e1ce10_Item<S_e1ce10_Vertex> {
    S_e1ce10_Vec4 m_vContactPosition;
    S_e1ce10_Vec4 m_20;
    S_e1ce10_Vec4 m_30;
    int m_40;
    int m_44;
    S_e1ce10_Vertex() : m_40(-1), m_44(-1) {}
};
struct S_e1ce10_TriangleBase : S_e1ce10_Item<S_e1ce10_Triangle> {
    S_e1ce10_Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3]; // triangle pointer + edge index
    __forceinline void setVertices(S_e1ce10_Vertex* const& a, S_e1ce10_Vertex* const& b, S_e1ce10_Vertex* const& c) { m_kVertices[0] = a; m_kVertices[1] = b; m_kVertices[2] = c; }
    __forceinline S_e1ce10_Vertex*& vertex(int i) { return m_kVertices[i]; }
    __forceinline unsigned int& link(int i) { return m_ppLinks[i]; }
};
struct S_e1ce10_Triangle : S_e1ce10_TriangleBase {
    S_e1ce10_Vec4 m_kTriangleNormal;
    int m_iMaterialIndex;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    S_e1ce10_Triangle() {}
};
// fixed-size pool blocks (0x50-byte slots)
struct S_e1ce10_PoolBase {
    void* FUN_00e23530() throw(); // allocate a new block
    void FUN_00e22f90(void* item) throw();   // release an item
};
template <class T> struct S_e1ce10_PoolItem { unsigned char m_data[sizeof(T)]; };
template <class T> struct S_e1ce10_Block {
    S_e1ce10_PoolItem<T> m_items[32];
    S_e1ce10_PoolItem<T>* m_free;
    int m_uiBufferCapacity;
};
template <class T> struct S_e1ce10_PoolAllocator : S_e1ce10_PoolBase {
    S_e1ce10_Block<T>** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    __forceinline S_e1ce10_PoolItem<T>* allocateItem() throw()
    {
        S_e1ce10_Block<T>* pool = (m_iBlockCount && m_kBlocks[0]->m_free) ? m_kBlocks[0] : (S_e1ce10_Block<T>*)FUN_00e23530();
        S_e1ce10_PoolItem<T>* item = pool->m_free;
        pool->m_free = *(S_e1ce10_PoolItem<T>**)item;
        ++pool->m_uiBufferCapacity;
        return item;
    }
    __forceinline T* allocate(const T& value) throw() { return new (allocateItem()) T(value); }
};
template <class T> struct S_e1ce10_List {
    S_e1ce10_PoolAllocator<T> m_pThreadAllocator;
    T* m_pFirstNode;
    int m_uiItemCount;
    __forceinline T* allocate(const T& value = T()) throw()
    {
        T* item = m_pThreadAllocator.allocate(value);
        item->m_pSecondNode = 0;
        item->m_next = m_pFirstNode;
        if (m_pFirstNode)
            m_pFirstNode->m_pSecondNode = item;
        m_pFirstNode = item;
        m_uiItemCount++;
        return item;
    }
    __forceinline void release(T* item) throw()
    {
        T* next = item->m_next;
        T* prev = item->m_pSecondNode;
        if (next)
            next->m_pSecondNode = prev;
        if (prev)
            prev->m_next = next;
        else
            m_pFirstNode = next;
        m_uiItemCount--;
        m_pThreadAllocator.FUN_00e22f90(item);
    }
};
// edge hash
__forceinline unsigned long S_e1ce10_uid2ulong(void* t, unsigned int i) { return (*(const unsigned long*)&t) + (unsigned long)i; }
__forceinline unsigned long S_e1ce10_packUid(void* t, unsigned int i) { return S_e1ce10_uid2ulong(t, i); }
template <class T> __forceinline void S_e1ce10_ulong2uid(unsigned long uid, T*& t, unsigned int& i) { i = (unsigned int)(uid & 3); uid &= ~3; t = *(T**)&uid; }
template <class T> __forceinline void S_e1ce10_unpackUid(unsigned long uid, T*& t, unsigned int& i) { S_e1ce10_ulong2uid(uid, t, i); }
struct S_e1ce10_Link {
    S_e1ce10_Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
    __forceinline S_e1ce10_Link(S_e1ce10_Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    static __forceinline const S_e1ce10_Link& null()
    {
        static const S_e1ce10_Link s_null(0, 0);
        return s_null;
    }
    __forceinline unsigned long uid() const { return S_e1ce10_packUid(m_pkTriangle, m_uiEdgeIndex); }
    __forceinline S_e1ce10_Triangle* triangle() const { return m_pkTriangle; }
    __forceinline bool isValid() const { return triangle() != 0; }
    __forceinline void bind(const S_e1ce10_Link& edge) const;
    __forceinline S_e1ce10_Link(const unsigned int& id) { S_e1ce10_unpackUid(id, m_pkTriangle, m_uiEdgeIndex); }
    __forceinline S_e1ce10_Link link() const;
    __forceinline bool isNaked() const { return !link().isValid(); }
    __forceinline void unbind() const;
};
__forceinline void S_e1ce10_Link::bind(const S_e1ce10_Link& edge) const
{
    m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
    if (edge.isValid())
        edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
}
__forceinline S_e1ce10_Link S_e1ce10_Link::link() const { return S_e1ce10_Link(m_pkTriangle->link(m_uiEdgeIndex)); }
__forceinline void S_e1ce10_Link::unbind() const
{
    if (!isNaked()) {
        S_e1ce10_Link l = link();
        l.m_pkTriangle->link(l.m_uiEdgeIndex) = 0;
    }
    m_pkTriangle->link(m_uiEdgeIndex) = 0;
}
template <typename T> __forceinline void S_e1ce10_swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S_e1ce10_Edge {
    S_e1ce10_Vertex* m_kPointA;
    S_e1ce10_Vertex* m_kPointB;
    S_e1ce10_Link m_kEdge;
    int m_uiItemCount;
    S_e1ce10_Edge() : m_kPointA(0), m_kPointB(0), m_kEdge(0, 0), m_uiItemCount(0) {}
    S_e1ce10_Edge(S_e1ce10_Vertex* a, S_e1ce10_Vertex* b) : m_kPointA(a), m_kPointB(b), m_kEdge(0, 0) { m_uiItemCount = 0; }
    static __forceinline int hashOf(const S_e1ce10_Edge& e)
    {
        int a = (int)e.m_kPointA;
        int b = (int)e.m_kPointB;
        if (a > b) S_e1ce10_swap(a, b);
        return ((a * 45564901) ^ (b * 95564881)) % 5564887;
    }
    __forceinline int hash() const
    {
        return hashOf(*this);
    }
    __forceinline bool operator==(const S_e1ce10_Edge& e) const
    {
        return (e.m_kPointA == m_kPointA && e.m_kPointB == m_kPointB) || (e.m_kPointA == m_kPointB && e.m_kPointB == m_kPointA);
    }
};
struct S_e1ce10_EdgeHash {
    S_e1ce10_Array< S_e1ce10_Array<S_e1ce10_Edge> > m_buckets;
    int m_numItems;
    S_e1ce10_EdgeHash() throw() : m_numItems(0) {}
    __forceinline ~S_e1ce10_EdgeHash() throw() {}
    __forceinline void clear() throw() { m_buckets.clear(); m_numItems = 0; }
    __forceinline void setBucketsCount(int size) throw()
    {
        clear();
        m_buckets.SetSizeAndGrow(size);
        for (int i = 0; i < size; ++i)
            m_buckets[i].clear();
    }
    __forceinline S_e1ce10_Array<S_e1ce10_Edge>& lookupBucket(int hash) throw()
    {
        const unsigned idx = ((unsigned)hash) % m_buckets.GetLogicalSize();
        return m_buckets[idx];
    }
    __forceinline S_e1ce10_Edge* find(int hash, const S_e1ce10_Edge& value) throw()
    {
        S_e1ce10_Array<S_e1ce10_Edge>& values = lookupBucket(hash);
        const int index = values.indexOf(value);
        if (index == -1)
            return 0;
        else
            return &values[index];
    }
    __forceinline S_e1ce10_Edge* insert(int hash, const S_e1ce10_Edge& value) throw()
    {
        ++m_numItems;
        S_e1ce10_Array<S_e1ce10_Edge>& values = lookupBucket(hash);
        values.AllocatePair() = value;
        return &values[values.GetLogicalSize() - 1];
    }
};
// broadphase tree used to weld vertices
struct S_e1ce10_TreeNodes {
    int unk00;
    ~S_e1ce10_TreeNodes() throw(); // ClearBuffers
};
struct S_e1ce10_Tree {
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_e1ce10_TreeNodes m_1c;
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
    S_e1ce10_Tree() throw(); // FUN_00d9c110
    virtual void v00() throw();
    ~S_e1ce10_Tree() throw() { FUN_00d9be30(); }
    void FUN_00d9be30() throw();
    void FUN_00d9d110(const S_e1ce10_Aabb& aabb, S_e1ce10_Vertex* item) throw(); // insert
};
struct S_e1ce10_Collector {
    virtual void v00() throw();
    S_e1ce10_Vec4 m_vContactPosition;
    float m_radiusSquared;
    S_e1ce10_Vertex* m_closest;
    S_e1ce10_Collector(const S_e1ce10_Vec4& p, float radius) throw()
        : m_vContactPosition(p), m_radiusSquared(radius * radius), m_closest(0) {}
};
void __cdecl FUN_00d1d570(S_e1ce10_Tree* tree, const S_e1ce10_Aabb* aabb, S_e1ce10_Collector* collector) throw();
// report stream / error
struct S_e1ce10_Ostream {
    int unk00;
    int unk04;
    int unk08;
    S_e1ce10_Ostream(void* buf, int size) throw();   // FUN_00cb1600
    ~S_e1ce10_Ostream() throw();                      // FUN_00cc00e0
    S_e1ce10_Ostream& operator<<(const char* s) throw(); // FUN_00cc01c0
    S_e1ce10_Ostream& operator<<(int i) throw();         // WriteInt
};
template <class T> struct S_e1ce10_PadSpu {
    T m_kStorage;
    T val() const { return m_kStorage; }
    T operator->() const { return m_kStorage; }
};

extern "C" void _ReadBarrier();


extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmpeq_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_set_ps1(float a);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_rsqrt_ss(__m128 a);
extern "C" __m128 _mm_set_ss(float a);
extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);
extern "C" __m128 _mm_setzero_ps(void);

struct __declspec(align(16)) LocalVec4 {
    union { struct { float x,y,z,w; }; __m128 quad; }; LocalVec4& operator=(const LocalVec4& b) {quad=b.quad;return *this;}
};

struct CapVertex {
    int unk00; int unk04; int unk08; int unk0c;
    LocalVec4 position;
    int unk20; int unk24; int unk28; int unk2c;
    float weight;
};

struct SubArr {
    void *m_pData;
    int m_iArrayLength;
    int m_iCap;
};

struct GridTag {};
template<class Payload> struct GridLinks:Payload {int next,prev;__forceinline GridLinks(){} __forceinline GridLinks(const GridLinks& b):Payload(b){} __forceinline GridLinks& operator=(const GridLinks&){return *this;}};
struct GridCore:GridLinks<GridTag> {};
struct RecPoint : GridCore {
int x,y;unsigned long constraint:1; unsigned long data:31;
};

extern float DAT_01012054;
extern const float DAT_01012068;
extern double DAT_01011588;

struct SubObj10 {
    int unk_00_000;     int unk_00_004;     int unk_00_008;     int unk_00_00c;     int unk_00_010;     int unk_00_014;
    void ProcessEntries();
    void ClearAndFreeItems();
};
struct Int3;
struct SubObj28 {
    int unk_00_000;
    int unk_00_004;
    int unk_00_008;
    void *m_0chead;
    int unk_10_010;
    int unk_10_014;
    void FUN_00e23a10();
    void FUN_00e23d70();
    Int3 FUN_00e27ea0(int a, int b, int flag, void *tmp, int z);
};
struct Obj470 {
    SubArr m_aiIndexedValues;
    void FUN_00e23c70();
};
struct PartsMap {
    int data,size,mask;
    __forceinline PartsMap():data(0),size(0),mask(-1) {reserve(0);}
    void EnsureCapacity(Allocator*,int);
    unsigned long LookupHashEntry(unsigned long,unsigned long) const;
    int FUN_00cb1870(Allocator*,unsigned long,unsigned long);
    void ProcessArgument(Allocator*);
    void FUN_00a29680();
    void FUN_00cb1fb0(int);
    __forceinline void reserve(int n) {EnsureCapacity(&FUN_00c85750().getHeap(),n);}
};
struct NormalWords { int a,b,c,d; };
struct RecPayload {
    int m_08;
    int m_0c;
    int m_10;
    int m_14[3];
    NormalWords m_20;
    int m_30;
    int m_34; int m_38; int m_3c; int m_40;
};
struct __declspec(align(16)) PooledRec {
    void *m_00;
    int m_04;
    RecPayload p;
};
struct Out26010 { int m_00; int m_04; int m_08; };
struct Int2 {
    Int2() {}
    int m_00;
    int m_04;
};
struct Int3 {
    int m_00;
    int m_04;
    int m_08;
};
extern int DAT_010eb0e0;
extern int DAT_010eb088;
extern int DAT_0102e388;
struct CapMatrix { LocalVec4 rows[4]; int FUN_00de8c50(const CapMatrix&,float); };
struct BigObj {
    void *m_vtbl;
    short m_04;
    short m_ref06;
    void *m_vtbl2;
    short m_0c;
    short m_ref0e;
    SubObj10 m_10;
    SubObj28 m_28;
    SubArr m_40arr;
    struct InlineEdge { int face; int index; };
    InlineEdge m_buf[64];
    int m_24c;
    Obj470 m_250;
    int unk_25c_25c;     int unk_25c_260;     int unk_25c_264;     int unk_25c_268;     int unk_25c_26c;     int unk_25c_270;
    int unk_25c_274;     int unk_25c_278;     int unk_25c_27c;     int unk_25c_280;     int unk_25c_284;     int unk_25c_288;
    int unk_25c_28c;     int unk_25c_290;     int unk_25c_294;     int unk_25c_298;     int unk_25c_29c;     int unk_25c_2a0;
    int unk_25c_2a4;     int unk_25c_2a8;     int unk_25c_2ac;     int unk_25c_2b0;     int unk_25c_2b4;     int unk_25c_2b8;
    int unk_25c_2bc;     int unk_25c_2c0;     int unk_25c_2c4;     int unk_25c_2c8;     int unk_25c_2cc;     int unk_25c_2d0;
    int unk_25c_2d4;     int unk_25c_2d8;     int unk_25c_2dc;     int unk_25c_2e0;     int unk_25c_2e4;     int unk_25c_2e8;
    int unk_25c_2ec;     int unk_25c_2f0;     int unk_25c_2f4;     int unk_25c_2f8;     int unk_25c_2fc;     int unk_25c_300;
    int unk_25c_304;     int unk_25c_308;     int unk_25c_30c;     int unk_25c_310;     int unk_25c_314;     int unk_25c_318;
    int unk_25c_31c;     int unk_25c_320;     int unk_25c_324;     int unk_25c_328;     int unk_25c_32c;     int unk_25c_330;
    int unk_25c_334;     int unk_25c_338;     int unk_25c_33c;     int unk_25c_340;     int unk_25c_344;     int unk_25c_348;
    int unk_25c_34c;     int unk_25c_350;     int unk_25c_354;     int unk_25c_358;     int unk_25c_35c;     int unk_25c_360;
    int unk_25c_364;     int unk_25c_368;     int unk_25c_36c;     int unk_25c_370;     int unk_25c_374;     int unk_25c_378;
    int unk_25c_37c;     int unk_25c_380;     int unk_25c_384;     int unk_25c_388;     int unk_25c_38c;     int unk_25c_390;
    int unk_25c_394;     int unk_25c_398;     int unk_25c_39c;     int unk_25c_3a0;     int unk_25c_3a4;     int unk_25c_3a8;
    int unk_25c_3ac;     int unk_25c_3b0;     int unk_25c_3b4;     int unk_25c_3b8;     int unk_25c_3bc;     int unk_25c_3c0;
    int unk_25c_3c4;     int unk_25c_3c8;     int unk_25c_3cc;     int unk_25c_3d0;     int unk_25c_3d4;     int unk_25c_3d8;
    int unk_25c_3dc;     int unk_25c_3e0;     int unk_25c_3e4;     int unk_25c_3e8;     int unk_25c_3ec;     int unk_25c_3f0;
    int unk_25c_3f4;     int unk_25c_3f8;     int unk_25c_3fc;     int unk_25c_400;     int unk_25c_404;     int unk_25c_408;
    int unk_25c_40c;     int unk_25c_410;     int unk_25c_414;     int unk_25c_418;     int unk_25c_41c;     int unk_25c_420;
    int unk_25c_424;     int unk_25c_428;     int unk_25c_42c;     int unk_25c_430;     int unk_25c_434;     int unk_25c_438;
    int unk_25c_43c;     int unk_25c_440;     int unk_25c_444;     int unk_25c_448;     int unk_25c_44c;     int unk_25c_450;
    int unk_25c_454;     int unk_25c_458;     int unk_25c_45c;     int unk_25c_460;     int unk_25c_464;     int unk_25c_468;
    int unk_25c_46c;     int unk_25c_470;     int unk_25c_474;     int unk_25c_478;     int unk_25c_47c;     int unk_25c_480;
    int unk_25c_484;     int unk_25c_488;     int unk_25c_48c;     int unk_25c_490;     int unk_25c_494;     int unk_25c_498;
    int unk_25c_49c;     int unk_25c_4a0;     int unk_25c_4a4;     int unk_25c_4a8;     int unk_25c_4ac;     int unk_25c_4b0;
    int unk_25c_4b4;     int unk_25c_4b8;     int unk_25c_4bc;     int unk_25c_4c0;     int unk_25c_4c4;     int unk_25c_4c8;
    int unk_25c_4cc;     int unk_25c_4d0;     int unk_25c_4d4;     int unk_25c_4d8;     int unk_25c_4dc;     int unk_25c_4e0;
    int unk_25c_4e4;     int unk_25c_4e8;     int unk_25c_4ec;     int unk_25c_4f0;     int unk_25c_4f4;     int unk_25c_4f8;
    int unk_25c_4fc;     int unk_25c_500;     int unk_25c_504;     int unk_25c_508;     int unk_25c_50c;     int unk_25c_510;
    int unk_25c_514;     int unk_25c_518;     int unk_25c_51c;     int unk_25c_520;     int unk_25c_524;     int unk_25c_528;
    int unk_25c_52c;     int unk_25c_530;     int unk_25c_534;     int unk_25c_538;     int unk_25c_53c;     int unk_25c_540;
    int unk_25c_544;     int unk_25c_548;     int unk_25c_54c;     int unk_25c_550;     int unk_25c_554;     int unk_25c_558;
    int unk_25c_55c;     int unk_25c_560;     int unk_25c_564;     int unk_25c_568;     int unk_25c_56c;     int unk_25c_570;
    int unk_25c_574;     int unk_25c_578;     int unk_25c_57c;     int unk_25c_580;     int unk_25c_584;     int unk_25c_588;
    int unk_25c_58c;     int unk_25c_590;     int unk_25c_594;     int unk_25c_598;     int unk_25c_59c;     int unk_25c_5a0;
    int unk_25c_5a4;     int unk_25c_5a8;     int unk_25c_5ac;     int unk_25c_5b0;     int unk_25c_5b4;     int unk_25c_5b8;
    int unk_25c_5bc;     int unk_25c_5c0;     int unk_25c_5c4;     int unk_25c_5c8;     int unk_25c_5cc;     int unk_25c_5d0;
    int unk_25c_5d4;     int unk_25c_5d8;     int unk_25c_5dc;     int unk_25c_5e0;     int unk_25c_5e4;     int unk_25c_5e8;
    int unk_25c_5ec;     int unk_25c_5f0;     int unk_25c_5f4;     int unk_25c_5f8;     int unk_25c_5fc;     int unk_25c_600;
    int unk_25c_604;     int unk_25c_608;     int unk_25c_60c;     int unk_25c_610;     int unk_25c_614;     int unk_25c_618;
    int unk_25c_61c;     int unk_25c_620;     int unk_25c_624;     int unk_25c_628;     int unk_25c_62c;     int unk_25c_630;
    int unk_25c_634;     int unk_25c_638;     int unk_25c_63c;     int unk_25c_640;     int unk_25c_644;     int unk_25c_648;
    int unk_25c_64c;     int unk_25c_650;     int unk_25c_654;     int unk_25c_658;
    int m_iValueBeforeForwardMatrix;
    CapMatrix forward;
    CapMatrix inverse;

    __forceinline RecPoint transformPoint(const LocalVec4& input) const {
                            __m128 n3 = input.quad;
                            __m128 r = _mm_mul_ps(_mm_shuffle_ps(n3, n3, 0x55), _mm_load_ps((float *)&inverse.rows[1]));
                            r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(n3, n3, 0), _mm_load_ps((float *)&inverse.rows[0])));
                            r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(n3, n3, 0xaa), _mm_load_ps((float *)&inverse.rows[2])));
                            r = _mm_add_ps(r, _mm_load_ps((float *)&inverse.rows[3]));
                            LocalVec4 ptr;
                            _mm_store_ps((float *)&ptr, r);
                            RecPoint vb;
                            long pool = m_iValueBeforeForwardMatrix;
                            long zz;
                            zz = 0x7fff - pool;
                            int s;
                            s = (int)(ptr.x < 0.0f ? ptr.x - 0.5 : ptr.x + 0.5);
                            vb.x = s < pool ? pool : (s > zz ? zz : s);
                            int i;
                            i = (int)(ptr.y < 0.0f ? ptr.y - 0.5 : ptr.y + 0.5);
                            vb.y = i < pool ? pool : (i > zz ? zz : i);

return vb;
}
    Int3 LocatePoint(int a, int b);
    Int2 FUN_00e24aa0(int a, int b, int c, int d);
    void FUN_00e24b70();
    void FUN_00e27b50(const LocalVec4& a,const LocalVec4& b,float f,bool n);
    void FUN_00e275d0(int n);
    Out26010 FUN_00e26010(int a, int b, int c, int d, int e, int f);
    Int3 FUN_00e27ea0(int a, int b, int flag, void *tmp, int z);
};

struct TriNode {
    TriNode *m_next;
    int m_04;
    // Three vertices followed by three tagged adjacency links.
    TriNode *m_aiIndexedValues[6];
    unsigned int m_flags;
    int unk24; int unk28; int unk2c;
    union {
        int m_30i;
        float m_30f;
    };
};

SubArr *__cdecl FUN_00e248b0(TriNode *node, int idx);

struct BoundaryEdge {
    TriNode *face; int index;
    BoundaryEdge() {}
    BoundaryEdge(TriNode *f, int e) : face(f), index(e) {}
    BoundaryEdge(int packed) { index=packed & 3; face=(TriNode*)(packed & ~3); }
    int packed() const { return (int)face + index; }
    CapVertex *vertex() const { return (CapVertex*)face->m_aiIndexedValues[index]; }
    BoundaryEdge next() const { return BoundaryEdge(face, (9 >> (index * 2)) & 3); }
    BoundaryEdge previous() const { return BoundaryEdge(face, (0x12 >> (index * 2)) & 3); }
    BoundaryEdge link() const { return BoundaryEdge((int)face->m_aiIndexedValues[3 + index]); }
    bool valid() const { return face != 0; }
    void bind(const BoundaryEdge& other) const {
        face->m_aiIndexedValues[3 + index] = (TriNode*)other.packed();
        if (other.face) other.face->m_aiIndexedValues[3 + other.index] = (TriNode*)packed();
    }
};

struct BuildStatus { int code; BuildStatus() {} BuildStatus(int value) : code(value) {} };

__declspec(noinline) void BigObj::FUN_00e27b50(const LocalVec4& a,const LocalVec4& b,float f,bool n) {
    m_iValueBeforeForwardMatrix=n?1:0;
    float span=float(32767-2*m_iValueBeforeForwardMatrix);
    float sn=(float)sin(f);
    float cs=(float)cos(f);
    float sx=(b.x-a.x)/span;
    float sy=(b.y-a.y)/span;
    forward.rows[0].quad=_mm_setr_ps(1.0f,0.0f,0.0f,0.0f);
    forward.rows[1].quad=_mm_setr_ps(0.0f,1.0f,0.0f,0.0f);
    forward.rows[2].quad=_mm_setr_ps(0.0f,0.0f,1.0f,0.0f);
    forward.rows[3].quad=_mm_setr_ps(0.0f,0.0f,0.0f,1.0f);
    forward.rows[0].x=cs*sx;
    forward.rows[1].x=sn*sy;
    forward.rows[3].x=a.x;
    forward.rows[0].y=-sn*sx;
    forward.rows[1].y=cs*sy;
    forward.rows[3].y=a.y;
    inverse.FUN_00de8c50(forward,0.0f);
    FUN_00e275d0(1);
}

extern "C" __m128 _mm_setr_ps(float,float,float,float);
template<class T> __forceinline void fillRange(T* output,int count,const T& value)throw(){for(int index=0;index<count;++index)output[index]=value;}
template<class T> __forceinline void copyConstructRange(T* output,int count,const T& value)throw(){for(int index=0;index<count;++index)new(output+index) T(value);}
extern "C" __m128 _mm_set_ps(float,float,float,float);
void __cdecl ResizeAudioStream(Allocator&,void*,int) throw();
void __cdecl FUN_00c908c0(Allocator&,void*,int,int) throw();
template<class T> __forceinline void destroyRange(T* p,int n) throw() {
 for(int i=0;i<n;++i) {p[i].~T();}
}
template<class T> __forceinline void constructRange(T* p,int n) throw() {
 for(int i=0;i<n;++i) {new(p+i) T;}
}
template<class T> struct MeshArray {
 T* data; int size; int capacity;
 MeshArray(T* p,int n,int c)throw():data(p),size(n),capacity(c){}
 MeshArray() throw():data(0),size(0),capacity(0x80000000){}
 __forceinline void clear() throw() { destroyRange(data,size);size=0; }
 __forceinline void release(Allocator& heap) throw() { clear(); if(!(capacity&0x80000000)) heap.freeBlock(data,(capacity&0x3fffffff)*sizeof(T)); data=0; capacity=0x80000000; }
 __forceinline ~MeshArray() throw(){release(FUN_00c85750().getHeap());}
 __forceinline void reserve(Allocator& heap,int count) throw() {
  int cap=capacity&0x3fffffff;
  if(cap<count) {int grown=2*cap; if(count>=grown)grown=count; FUN_00c908c0(heap,this,grown,sizeof(T));}
 }
 __forceinline void resize(int count) throw() {
  reserve(FUN_00c85750().getHeap(),count);
  int removeCount=size-count;
  T* begin=data+count;
  destroyRange(begin,removeCount);
  int addCount=count-size;
  begin=data+size;
  constructRange(begin,addCount);
  size=count;
 }
 __forceinline void resize(int count,const T& value) throw() {
  reserve(FUN_00c85750().getHeap(),count);
  fillRange(data+size,count-size,value);
  size=count;
 }
 __forceinline void push(const T& value) throw() {
  Allocator& heap=FUN_00c85750().getHeap();
  if(size==(capacity&0x3fffffff)) ResizeAudioStream(heap,this,sizeof(T));
  new(data+size) T(value); ++size;
 }
};
struct __declspec(align(16)) MeshVec {float x,y,z,w;};
struct MeshLink {unsigned int value; MeshLink(){} MeshLink(unsigned int v):value(v){} operator unsigned int()const{return value;} };
struct MeshFace;
struct MeshFaceChain {MeshFace* next;MeshFace* prev;MeshFaceChain(){} MeshFaceChain(const MeshFaceChain&){} MeshFaceChain& operator=(const MeshFaceChain&){return *this;} };
struct MeshFace:MeshFaceChain {
 MeshVertex* vertices[3];MeshLink links[3];MeshVec plane;int material,group,tag,unk3c,unk40;
 __forceinline MeshVertex*& corner(int n) {return vertices[n];}

};
template<class E> struct MeshEdgeCore {
 MeshFace* face;int index;
 MeshEdgeCore(){}
 MeshEdgeCore(MeshFace* f,int n):face(f),index(n){}
 MeshEdgeCore(unsigned int packed):face((MeshFace*)(packed&~3u)),index(packed&3u){}
 bool valid()const {return face!=0;}
 MeshVertex*& start()const {return face->corner(index);}
 MeshVertex*& end()const {return face->corner((9>>(index*2))&3);}
};
struct MeshEdge:MeshEdgeCore<MeshEdge> {
 MeshEdge(){}
 MeshEdge(MeshFace* f,int n):MeshEdgeCore<MeshEdge>(f,n){}
 MeshEdge(unsigned int p):MeshEdgeCore<MeshEdge>(p){}
 MeshEdge(const MeshEdge& e):MeshEdgeCore<MeshEdge>(e.face,e.index){}
};

template<> __forceinline void destroyRange<int>(int*,int)throw(){}
template<> __forceinline void constructRange<int>(int*,int)throw(){}
template<> __forceinline void destroyRange<MeshVec>(MeshVec*,int)throw(){}
template<> __forceinline void constructRange<MeshVec>(MeshVec*,int)throw(){}
template<> __forceinline void destroyRange<MeshEdge*>(MeshEdge**,int)throw(){}
template<> __forceinline void constructRange<MeshEdge*>(MeshEdge**,int)throw(){}

template<class T,int N> struct MeshInplaceArray: MeshArray<T> {
 T storage[N];
 MeshInplaceArray() throw():MeshArray<T>(storage,0,0x80000000|N) {}
};
struct GridVertex {int unk00,unk04,x,y; unsigned int encoded;};
struct GridFace {GridFace* next;int unk04;GridVertex* vertices[3];int unk14,unk18,unk1c; unsigned int flags;};
struct GridResult {int status;GridFace* face;int side;};
struct EdgeRange {void* data;int count;int stride;};
struct ReferenceBase {virtual void identity();unsigned short allocationSize,referenceCount;
 ReferenceBase() throw():referenceCount(1){}
 __forceinline ~ReferenceBase() throw(){}
};
struct GridPool {
 void* data;int count;int capacity;GridFace* head;int used;int unk14;
 GridPool() throw():data(0),count(0),capacity(0x80000000),head(0),used(0){}
 void clearVertices() throw(); void freeVertices() throw();
 void clearFaces() throw(); void freeFaces() throw();
};
struct GridInner : ReferenceBase {
 GridPool vertices;GridPool faces;
 __forceinline ~GridInner() throw(){ faces.clearFaces();faces.freeFaces();vertices.clearVertices();vertices.freeVertices(); }
};
struct GridAux {void* data;int size;int capacity;
 GridAux() throw():data(0),size(0),capacity(0x80000000){}
 void cleanup() throw();
 __forceinline ~GridAux() throw(){cleanup();}
};
struct __declspec(align(16)) Triangulation : ReferenceBase {
 GridInner mesh;
 MeshInplaceArray<MeshEdge,64> pending;
 int unk24c;
 GridAux auxiliary;
int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0; int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0; int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc; int unk400; int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420; int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c; int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c; int unk480; int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c; int unk4a0; int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc; int unk4c0; int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc; int unk4e0; int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc; int unk500; int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c; int unk520; int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c; int unk540; int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c; int unk560; int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c; int unk580; int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c; int unk5a0; int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc; int unk5c0; int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc; int unk5e0; int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc; int unk600; int unk604; int unk608; int unk60c; int unk610; int unk614; int unk618; int unk61c; int unk620; int unk624; int unk628; int unk62c; int unk630; int unk634; int unk638; int unk63c; int unk640; int unk644; int unk648; int unk64c; int unk650; int unk654; int unk658;
 int border;
int unk660; int unk664; int unk668; int unk66c; int unk670; int unk674; int unk678; int unk67c; int unk680; int unk684; int unk688; int unk68c; int unk690; int unk694; int unk698; int unk69c;
 MeshVec axisX,axisY,axisZ,translation;
 __forceinline Triangulation(const MeshVec& lower,const MeshVec& upper,float tolerance) throw() {
  unk24c=0;
  initialize(lower,upper,tolerance,1);
 }
 void initialize(const MeshVec&,const MeshVec&,float,int) throw();
 void project(const EdgeRange&,const MeshVec&,int,int) throw();
 GridResult find(int,int) throw();
 GridResult insert(int,int,int,GridResult*,int) throw();
 GridResult constrain(int,int,int,int,int,MeshArray<MeshEdge*>*) throw();
 int componentCount() throw();
 void triangulate() throw();
 void finish(int) throw();
 __forceinline ~Triangulation() throw(){finish(1);}
 __forceinline void transform(const MeshVec& input,MeshVec& result) const {
  const __m128& v=*(const __m128*)&input;
  __m128 xy=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),*(const __m128*)&axisY),_mm_mul_ps(_mm_shuffle_ps(v,v,0),*(const __m128*)&axisX));
  __m128 xyz=_mm_add_ps(xy,_mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),*(const __m128*)&axisZ));
  _mm_store_ps(&result.x,_mm_add_ps(xyz,*(const __m128*)&translation));
 }

};
struct RebuildPoolBlock {MeshFace objects[32];MeshFace* freeHead;int used;};
struct RebuildPool {
 RebuildPoolBlock** blocks;int count;int capacity;MeshFace* head;int used;
 RebuildPoolBlock* newBlock() throw();
 __forceinline MeshFace* add(const MeshFace& value) throw() {
  RebuildPoolBlock* block;
  if(!count || !(block=*blocks)->freeHead) block=newBlock();
  MeshFace* result=block->freeHead;
  block->freeHead=result->next;++block->used;
  copyConstructRange(result,1,value);
 result->prev=0;result->next=head;
  if(head)head->prev=result;
  ++used;head=result;return result;
 }
};

namespace fnv_00e23530 {
#include <windows.h>


struct DynamicMemoryAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct PoolHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DynamicMemoryAllocator* m_pAllocator;
};

PoolHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(DynamicMemoryAllocator* apAllocator, void* apVector, unsigned int auiElemSize);

struct FUN_00e23530_cls {
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;

    void* FUN_00e23530();
};

// Allocates a 0xa08-byte block of 32 chained slots, appends it to m_ppData, swaps it with entry 0 when there are several blocks, and returns it.
// @fnv 0x00e23530
void* FUN_00e23530_cls::FUN_00e23530()
{
    PoolHolder* pHolder = FUN_00c85750();
    DynamicMemoryAllocator* pAllocator = pHolder->m_pAllocator;
    void* pPrev = 0;
    char* pBlock = (char*)pAllocator->Alloc(0xa08);

    int iCounter = 0x1f;
    char* pCur = pBlock + 0x9b0;
    char* pHead;
    do {
        *(void**)pCur = pPrev;
        pHead = pCur;
        pPrev = pCur;
        iCounter--;
        pCur -= 0x50;
    } while (iCounter >= 0);

    *(int*)(pBlock + 0xa04) = 0;
    *(char**)(pBlock + 0xa00) = pHead;

    PoolHolder* pHolder2 = FUN_00c85750();
    if (m_iArrayLength == (int)(m_uCapFlags & 0x3fffffffu)) {
        ResizeAudioStream(pHolder2->m_pAllocator, this, 4);
    }

    void** pSlot = &m_ppData[m_iArrayLength];
    *pSlot = pBlock;
    if (pSlot == 0) { return 0; }
    m_iArrayLength++;
    if (m_iArrayLength > 1) {
        void* pFirst = m_ppData[0];
        m_ppData[0] = m_ppData[m_iArrayLength - 1];
        m_ppData[m_iArrayLength - 1] = pFirst;
    }
    return pBlock;
}
}  // namespace fnv_00e23530

namespace fnv_00e235d0 {
#include <windows.h>


struct DynamicMemoryAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct PoolHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DynamicMemoryAllocator* m_pAllocator;
};

PoolHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(DynamicMemoryAllocator* apAllocator, void* apVector, unsigned int auiElemSize);

struct FUN_00e235d0_cls {
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;

    void* FUN_00e235d0();
};

// Allocates a 0x388-byte block of 32 chained slots, appends it to m_ppData, swaps it with entry 0 when there are several blocks, and returns it.
// @fnv 0x00e235d0
void* FUN_00e235d0_cls::FUN_00e235d0()
{
    PoolHolder* pHolder = FUN_00c85750();
    DynamicMemoryAllocator* pAllocator = pHolder->m_pAllocator;
    void* pPrev = 0;
    char* pBlock = (char*)pAllocator->Alloc(0x388);

    int iCounter = 0x1f;
    char* pCur = pBlock + 0x364;
    char* pHead;
    do {
        *(void**)pCur = pPrev;
        pHead = pCur;
        pPrev = pCur;
        iCounter--;
        pCur -= 0x1c;
    } while (iCounter >= 0);

    *(int*)(pBlock + 0x384) = 0;
    *(char**)(pBlock + 0x380) = pHead;

    PoolHolder* pHolder2 = FUN_00c85750();
    if (m_iArrayLength == (int)(m_uCapFlags & 0x3fffffffu)) {
        ResizeAudioStream(pHolder2->m_pAllocator, this, 4);
    }

    void** pSlot = m_ppData + m_iArrayLength;
    for (int k = 0; k < 1; k++) pSlot[k] = pBlock;
    m_iArrayLength++;
    if (m_iArrayLength > 1) {
        void* pFirst = m_ppData[0];
        m_ppData[0] = m_ppData[m_iArrayLength - 1];
        m_ppData[m_iArrayLength - 1] = pFirst;
    }
    return pBlock;
}
}  // namespace fnv_00e235d0

namespace fnv_00e237b0 {
inline void* __cdecl operator new(unsigned int, void* where) { return where; }
struct FUN_00e237b0_Allocation {
    void* unk00; void* unk04; void* unk08; void* unk0c; void* allocator;
};
struct FUN_00e237b0_List {
    void** data;
    unsigned int size;
    unsigned int capacityAndFlags;
};
extern "C" FUN_00e237b0_Allocation* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(void*, FUN_00e237b0_List*, unsigned int);
}  // namespace fnv_00e237b0

namespace fnv_00e23800 {
extern "C" void __cdecl Deallocate(void*);
extern void* __cdecl FUN_00c85750();

struct FUN_00e23800_Vtbl {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
};

extern FUN_00e23800_Vtbl DAT_010cd664;

struct Holder {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void v4(void* a, int b);
};

}  // namespace fnv_00e23800

namespace fnv_00e23a10 {
struct E23A10Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct E23A10MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E23A10Allocator* m_pStreamAllocator;

    E23A10Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" E23A10MemoryRouter& __cdecl FUN_00c85750();

struct E23A10Element {
    E23A10Element* m_next;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct E23A10Block {
    E23A10Element m_elements[32];
    E23A10Element* m_firstFree;
    int m_iAllocatedCount;
};

struct E23A10List {
    E23A10Block** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    void* m_pFirstNode;
    int m_iNodeCount;

    void FUN_00e23a10();
};

// Releases all E23A10Block allocations from the heap and resets the block count, first node pointer, and node count to zero.
// @fnv 0x00e23a10
void E23A10List::FUN_00e23a10()
{
    for (int i = 0; i < m_iBlockCount; i++) {
        E23A10Block* block = m_kBlocks[i];
        FUN_00c85750().heap().ReleaseBlock(block, sizeof(E23A10Block));
    }
    m_iBlockCount = 0;
    m_pFirstNode = 0;
    m_iNodeCount = 0;
}
}  // namespace fnv_00e23a10

namespace fnv_00e24de0 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct SpawnedBase {
    unsigned short m_uSize;
    unsigned short m_u06;
    virtual ~SpawnedBase() throw() {}
};

struct SpawnedSubA {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void Release1();
    void Release2();
};

struct SpawnedSubB {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void Release1();
    void Release2();
};

struct SpawnedObject : SpawnedBase {
    SpawnedSubA m_subA;
    SpawnedSubB m_subB;

    virtual ~SpawnedObject() throw() {
        m_subB.Release1();
        m_subB.Release2();
        m_subA.Release1();
        m_subA.Release2();
    }

    SpawnedObject* FUN_00e24de0(unsigned char acFlags) throw();
};

// Destroys the SpawnedObject, and if acFlags has bit 0 set, frees its memory via the AudioHolder's AudioAllocator.
// @fnv 0x00e24de0
SpawnedObject* SpawnedObject::FUN_00e24de0(unsigned char acFlags) throw()
{
    this->SpawnedObject::~SpawnedObject();
    if (acFlags & 1) {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00e24de0

struct Point61 {
    int unk00, unk04, x, y;
    __forceinline int order(const Point61& b) const {
        if (x < b.x) return -1;
        if (x > b.x) return 1;
        if (y < b.y) return -1;
        if (y > b.y) return 1;
        return 0;
    }
    static __forceinline bool before(const Point61* a, const Point61* b) {
        int c = a->order(*b);
        if (c < 0) return true;
        if (c > 0) return false;
        return true;
    }
};
template<class P,class T> struct FaceCore61 {
  T* next;T* previous;P* vertices[3]; unsigned int links[3];
  __forceinline P*& vertex(int i){return vertices[i];}
  __forceinline unsigned int& link(int i){return links[i];}
};
struct Face61 : FaceCore61<Point61,Face61> {
 unsigned short constraints:3; unsigned short root:1;unsigned short region:12;unsigned short sets;
};
template<class E,class V,class T> struct Topology61 {
    T* face;
    unsigned int index;
    __forceinline Topology61() {}
    __forceinline Topology61(T* t,unsigned i):face(t),index(i) {}
    __forceinline Topology61(const unsigned long& value) { unpack(value,face,index); }
    static __forceinline void unpack(unsigned long value,T*& t,unsigned& i) {
        i=value&3; value&=~3u; t=(T*)value;
    }
    __forceinline E next() const { return E(face,(9>>(index<<1))&3); }
    __forceinline E prev() const { return E(face,(0x12>>(index<<1))&3); }
    __forceinline E linked() const { return E((unsigned long)face->link(index)); }
    __forceinline bool valid() const { return face!=0; }
    __forceinline bool unbound() const { return !linked().valid(); }
    __forceinline bool primary() const { return V::before(start(),end()) || unbound(); }
    __forceinline E canonical() const { if(primary()) return E(face,index); else return linked(); }
    __forceinline V*& start() const { return face->vertex(index); }
    __forceinline V*& end() const { return face->vertex((9>>(index<<1))&3); }
    __forceinline V*& apex() const { return face->vertex((0x12>>(index<<1))&3); }
    __forceinline void bind(const Topology61& other) const {
        face->link(index)=(unsigned long)other.face+other.index;
        if(other.valid()) other.face->link(other.index)=(unsigned long)face+index;
    }
    __forceinline E exchange() const {
        E peer=linked();
        E a=prev();
        E b=peer.prev();
        start()=b.start();
        peer.start()=a.start();
        peer.bind(a.linked());
        bind(b.linked());
        a.bind(b);
        return prev();
    }
};
static __forceinline int orientation61(int ax,int ay,int bx,int by,int cx,int cy) {
    bx-=ax;by-=ay;cx-=ax;cy-=ay;
    return -(by*cx-bx*cy);
}
static __forceinline int orientation61(const Point61* a,const Point61* b,const Point61* c) {
    return orientation61(a->x,a->y,b->x,b->y,c->x,c->y);
}
struct Edge61:Topology61<Edge61,Point61,Face61> {
    typedef Topology61<Edge61,Point61,Face61> Base;
    __forceinline Edge61() {}
    __forceinline Edge61(Face61* t,unsigned i):Base(t,i) {}
    __forceinline Edge61(unsigned long value):Base(value) {}
    __forceinline Edge61(const Edge61& e):Base(e.face,e.index) {}
    __forceinline void operator=(const Edge61& e) { face=e.face;index=e.index; }
    __forceinline bool constrained() const {const Base& e=canonical(); return 0!=(e.face->constraints & (1<<e.index));}
    __forceinline void clear() const {
        const Base& e=canonical();
        e.face->constraints &= ~(1<<e.index);
    }
    __forceinline void set() const {
        const Base& e=canonical();
        const int bits=e.face->constraints;
        e.face->constraints=bits | (1<<e.index);
    }
    __forceinline int take() const {
        int result=constrained()!=0;
        if(result) clear();
        return result;
    }
    __forceinline int flippable() const {
        if(!unbound() && !constrained()) {
            Edge61 peer=linked();Edge61 a=prev();Edge61 b=peer.prev();Point61* own=start();return orientation61(a.start(),own,b.start())>0 && orientation61(b.start(),peer.start(),a.start())>0;
        }
        return 0;
    }
    __forceinline Edge61 flip() const {
        const int a=prev().take();
        const int b=linked().prev().take();
        Edge61 result=exchange();
        if(a) result.linked().next().set();
        if(b) result.next().set();
        return result;
    }
};

struct PointSol {
    int unk00, unk04;
    int x, y;
    __forceinline int compare(const PointSol& b) const {
        if(x<b.x) return -1;
        if(x>b.x) return 1;
        if(y<b.y) return -1;
        if(y>b.y) return 1;
        return 0;
    }
};
struct FaceSol {
    int unk00, unk04;
    PointSol* vertices[3];
    unsigned int links[3];
    unsigned short flags:3;
    __forceinline PointSol*& vertex(int i) { return vertices[i]; }
    __forceinline unsigned int& link(int i) { return links[i]; }
};
static __forceinline bool orderedSol(const PointSol* a,const PointSol* b) { const int c=a->compare(*b); if(c<0) return true; if(c>0) return false; return true; }
struct S00e25570_CBool {
    char m_cBooleanValue;
    __forceinline S00e25570_CBool(int b) : m_cBooleanValue((char)b) {}
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};
struct EdgeSol;
template<class D> struct EdgeBaseSol {
    FaceSol* face;
    unsigned int index;
    EdgeBaseSol() {}
    EdgeBaseSol(FaceSol* f,unsigned int i):face(f),index(i){}
    static __forceinline void decode(unsigned int p,FaceSol*& f,unsigned int& i) { i=p&3; p&=~3u; f=(FaceSol*)p; }
    EdgeBaseSol(const unsigned int& p) { decode(p,face,index); }
    __forceinline D next() const { return D(face,(9>>(2*index))&3); }
    __forceinline D prev() const { return D(face,(0x12>>(2*index))&3); }
    __forceinline D link() const { return D(face->link(index)); }
    __forceinline PointSol*& start() const { return face->vertex(index); }
    __forceinline PointSol*& end() const { return face->vertex((9>>(2*index))&3); }
    __forceinline PointSol*& apex() const { return face->vertex((0x12>>(2*index))&3); }
    __forceinline bool valid() const { return face!=0; }
    __forceinline bool boundary() const { return !link().valid(); }
    __forceinline bool master() const { return orderedSol(start(),end()) || boundary(); }
    __forceinline D primary() const {
        if(master()) return D(face,index);
        return link();
    }
    __forceinline void bind(const D& b) const {
        face->link(index)=(unsigned int)b.face+b.index;
        if(b.face) b.face->link(b.index)=(unsigned int)face+index;
    }
    __forceinline D rotateDiagonal() const {
        D other=link(), before=prev(), across=other.prev();
        start()=across.start();
        other.start()=before.start();
        other.bind(before.link());
        bind(across.link());
        before.bind(across);
        return prev();
    }
};
static __forceinline int orientXY(int ox,int oy,int ax,int ay,int bx,int by) {
    ax-=ox;ay-=oy;bx-=ox;by-=oy;
    return -(ay*bx-ax*by);
}
static __forceinline int orientSol(const PointSol* o,const PointSol* a,const PointSol* b) {
    return orientXY(o->x,o->y,a->x,a->y,b->x,b->y);
}
struct EdgeSol:EdgeBaseSol<EdgeSol> {
    typedef EdgeBaseSol<EdgeSol> Base;
    EdgeSol() {}
    EdgeSol(FaceSol* f,unsigned int i):Base(f,i){}
    EdgeSol(unsigned int p):Base(p){}
    EdgeSol(const EdgeSol& e):Base(e.face,e.index){}
    __forceinline void operator=(const EdgeSol& e) { face=e.face; index=e.index; }
    __forceinline bool flagged() const {
        const EdgeSol& p=primary();
        const int x=p.face->flags & (1u<<p.index); const int r=x; return !(0==(r));
    }
    __forceinline bool flaggedNew() const {
        const EdgeSol& p=primary();
        const int x=p.face->flags & (1u<<p.index); const int& r=x; return (char)r!=0;
    }
    __forceinline bool flaggedV() const {
        EdgeSol p=primary();
        return S00e25570_CBool(((volatile FaceSol*)p.face)->flags & (1<<p.index));
    }
    __forceinline void setFlag() const {
        const EdgeSol& p=primary();
        int old=p.face->flags;
        p.face->flags=old|(1<<p.index);
    }
    __forceinline void clearFlag() const {
        const EdgeSol& p=primary();
        int old=p.face->flags;
        p.face->flags=old&~(1<<p.index);
    }
    __forceinline int takeFlag() const {
        int result=flaggedNew();
        if(result) clearFlag();
        return result;
    }
    __forceinline bool masterOf(PointSol* a,PointSol* b) const { return orderedSol(a,b) || boundary(); }
    __forceinline EdgeSol primaryOf(PointSol* a,PointSol* b) const {
        if(masterOf(a,b)) return EdgeSol(face,index);
        return link();
    }
    __forceinline int takeFlagV() const {
        PointSol* b=end(); PointSol* a=start();
        int result;
        { EdgeSol p=primaryOf(a,b); result=S00e25570_CBool(((volatile FaceSol*)p.face)->flags & (1<<p.index)); }
        if(result) { EdgeSol p=primaryOf(a,b); int old=p.face->flags; p.face->flags=old&~(1<<p.index); }
        return result;
    }
    __forceinline int takeFlagW() const {
        PointSol* b=end(); PointSol* a=start();
        int result;
        { EdgeSol p=primaryOf(a,b); result=S00e25570_CBool(((volatile FaceSol*)p.face)->flags & (1<<p.index)); }
        if(result) { EdgeSol p=primaryOf(start(),b); int old=p.face->flags; p.face->flags=old&~(1<<p.index); }
        return result;
    }
    __forceinline int takeFlagOld() const {
        int result=flaggedV();
        if(result) clearFlag();
        return result;
    }
    __forceinline int flippable() const {
        if(boundary()||flagged()) return 0;
        EdgeSol other=link(), before=prev(), across=other.prev();
        return orientSol(before.start(),start(),across.start())>0 &&
               orientSol(across.start(),other.start(),before.start())>0;
    }
    __forceinline EdgeSol flip() const {
        int first=prev().takeFlagV();
        int second=link().prev().takeFlag();
        EdgeSol result=rotateDiagonal();
        if(first) result.link().next().setFlag();
        if(second) result.next().setFlag();
        return result;
    }
};
struct StackSol {
    EdgeSol* data;
    int size,cap;
    __forceinline EdgeSol& back() { return data[size-1]; }
    __forceinline void popBack() { --size; }
    __forceinline void push(const EdgeSol& value) {
        Router& r=FUN_00c85750();
        if(size==(cap&0x3fffffff)) ResizeAudioStream(r.heap,this,8);
        new(data+size) EdgeSol(value);
        ++size;
    }
};

namespace fnv_00e27400 {

struct FUN_00e27400_interface {
    virtual void FUN_00e27400_virtual_0();
    virtual void FUN_00e27400_virtual_1();
    virtual void FUN_00e27400_virtual_2(void* value, int flag);
};

struct FUN_00e27400_holder : FUN_00e27400_interface {
    int unk004;
    int unk008;
    int unk00c;
    FUN_00e27400_interface* unk010;
};

extern FUN_00e27400_holder* FUN_00c85750();

}  // namespace fnv_00e27400

void __cdecl __debugbreak();

struct Tri14
{
    Tri14* m_next;
    int unk04;
    void* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct Edge14
{
    Tri14* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    __forceinline void bind(Edge14 other) const {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = (unsigned int)other.m_pkTriangle + other.m_uiEdgeIndex;
        if (other.m_pkTriangle) {
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = m_uiEdgeIndex + (unsigned int)m_pkTriangle;
        }
    }
};

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_sub_ps(__m128,__m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern __m128 DAT_010ec7f0;
extern const float DAT_01011d78;
extern void* DAT_010eaf00[];
extern void* DAT_010cd664[];

struct __declspec(align(16)) ClipScalar160 {
    __m128 quad;
    __forceinline ClipScalar160() {}
    __forceinline ClipScalar160(__m128 v):quad(v) {}
    __forceinline operator __m128() const {return quad;}
    __forceinline float getReal() const {float f;_mm_store_ss(&f,quad);return f;}
};
struct __declspec(align(16)) ClipVertex160 {
    union { __m128 value; struct {float x,y,z,w;}; };
    __forceinline ClipVertex160() {}
    __forceinline __m128 get() const {return value;}
    __forceinline void set(__m128 v) {value=v;}
    void FUN_00c7f640(const void*,const ClipVertex160*);
};
struct ClipTriangle160 {
    ClipVertex160 vertices[3];
    __forceinline ClipTriangle160() {}
    __forceinline ClipTriangle160(const ClipVertex160& a,const ClipVertex160& b,const ClipVertex160& c) {
        vertices[0].set(a.get()); vertices[1].set(b.get()); vertices[2].set(c.get());
    }
};

template<class T> struct ClipBufferBase {
    T* data; int count; unsigned int capacity;
    __forceinline ClipBufferBase():data(0),count(0),capacity(0x80000000u) {}
    __forceinline T& operator[](int i) {return data[i];}
    __forceinline int size() const {return count;}
    void AppendItems(Allocator*,const ClipTriangle160*,int);
};
template<class T> struct Buffer:ClipBufferBase<T> {};

extern void __cdecl ResizeAudioStream(Allocator*,void*,int);
extern void __cdecl FUN_00cbeb70(const ClipTriangle160*,int,ClipVertex160*);
extern void __cdecl FUN_00d1d570(void*,const ClipVertex160*,void*);
extern int __cdecl FUN_00deab10(const ClipTriangle160*,const ClipVertex160*);
struct CollisionVertex {int unk00,unk04,unk08,unk0c;ClipVertex160 point;};
struct CollisionTriangle {
    int unk00,unk04;CollisionVertex* a;CollisionVertex* b;CollisionVertex* c;
    int unk14,unk18,unk1c;ClipVertex160 plane;
};
struct ContactList {
    void** vtable; CollisionTriangle** data; int count; unsigned int capacity;
    __forceinline ContactList():vtable(DAT_010eaf00),data(0),count(0),capacity(0x80000000u) {}
};

extern "C" __m128 _mm_load_ps1(float const* p);

struct __declspec(align(16)) S_00e16e50_Vec { float x, y, z, w; };

struct S_00e16e50_Array {
    S_00e16e50_Vec* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(Allocator& a, int n) {
        int cap = m_cap & 0x3fffffff;
        if (cap < n) {
            int c2 = cap * 2;
            FUN_00c908c0((int)&a, this, (n < c2) ? c2 : n, 16);
        }
    }
    __forceinline void ClearAndRelease(Allocator& a) {
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            a.freeBlock(m_data, (m_cap & 0x3fffffff) * 16);
    }
};
struct S_00e16e50_Local : S_00e16e50_Array {
    S_00e16e50_Vec buf[32];
    S_00e16e50_Local() { m_data = buf; m_iElementCount = 0; m_cap = 0x80000020; }
};

extern double DAT_01011588;

static __forceinline float realSqrt(float x) { return (float)sqrt((double)x); }
static __forceinline float copyReal(const float& x) { return x; }


extern "C" {
__m128 _mm_sub_ps(__m128 a, __m128 b);
__m128 _mm_load_ss(const float* p);
__m128 _mm_sqrt_ss(__m128 a);
__m128 _mm_move_ss(__m128 a, __m128 b);
__m128 _mm_set_ss(float);
}
struct DistanceScalar {
    union {__m128 value; float lanes[4];};
    DistanceScalar() {}
    DistanceScalar(__m128 v):value(v) {}
    operator const __m128&() const { return value; }
    DistanceScalar& operator=(float f) { value=_mm_load_ss(&f); return *this; }
};
struct Bits4 { unsigned a,b,c,d; };
struct __declspec(align(16)) PositionBits:Bits4 { __m128 get() const {return reinterpret_cast<const __m128&>(*this);} };
typedef PositionBits SplitPoint;
struct SplitVertex:ListLinks<SplitVertex> { int unk08,unk0c; SplitPoint position; };
struct PartSplitFace:ListLinks<PartSplitFace> { SplitVertex* vertices[3]; int links[3]; SplitPoint m_20; int m_30;
    const SplitPoint& point(int i) const { return vertices[i]->position; }
};
struct SplitPair { int first, second; };
struct SplitPairs { SplitPair* data; int size; int capacity; SplitPairs():data(0),size(0),capacity(0x80000000) {} };
struct PartSplitEdge { PartSplitFace* triangle; unsigned int index; PartSplitEdge(PartSplitFace* t, unsigned int i):triangle(t),index(i) {}  __forceinline PartSplitEdge prev() const { return PartSplitEdge(triangle,(0x12>>(index*2))&3); } };
__forceinline void splitCopy(Components& out,const SplitVertex* v) {
    out = *reinterpret_cast<const Components*>(&v->position);
}
extern "C" int __cdecl FUN_00deab10(const SplitPoint*,const SplitPoint*);
__forceinline void setMagnitude(volatile float& out,float value) { out=(float)fabs((double)value); }

struct EdgeByte {char value;EdgeByte(int b):value((char)b) {} __forceinline operator bool() const {return value!=0;}};

extern "C" void _ReadWriteBarrier();



struct EdgeFlag {int value;EdgeFlag(int b):value(b) {} __forceinline operator bool() const {return value!=0;}};

struct ConstraintPoint {

    int x,y;

    ConstraintPoint() {}

    ConstraintPoint(int X,int Y):x(X),y(Y) {}

    __forceinline int compare(const ConstraintPoint& b) const {

        if(x<b.x) return -1;

        if(x>b.x) return 1;

        if(y<b.y) return -1;

        if(y>b.y) return 1;

        return 0;

    }

    __forceinline ConstraintPoint operator-(const ConstraintPoint& b) const { return ConstraintPoint(x-b.x,y-b.y); }

    __forceinline int cross(const ConstraintPoint& b) const { return x*b.y-y*b.x; }

};

struct ConstraintVertex {

    int unk00, unk04;

    ConstraintPoint pos;

    __forceinline int isEqual(int x,int y) const {return pos.x==x && pos.y==y;}

};

typedef S_00e13910_Triangle ConstraintTriangle;

struct ConstraintFace : ConstraintTriangle {

    unsigned short constraints : 3;

    unsigned short visited : 1;

    unsigned short remaining : 12;

};

__forceinline int orient(const ConstraintVertex*,const ConstraintVertex*,const ConstraintVertex*);

struct ConstraintEdge;
template<class E> struct ConstraintEdgeCore {

__forceinline ConstraintEdgeCore() {}
__forceinline ConstraintEdgeCore(ConstraintTriangle* t,unsigned i):m_pkTriangle(t),m_uiEdgeIndex(i) {}
__forceinline ConstraintEdgeCore(const unsigned long& word) {unpack(word,m_pkTriangle,m_uiEdgeIndex);}
static __forceinline void unpack(unsigned long word,ConstraintTriangle*& t,unsigned& index) {index=word&3;word&=~3ul;t=*(ConstraintTriangle**)&word;}

ConstraintTriangle* m_pkTriangle;
unsigned m_uiEdgeIndex;
__forceinline ConstraintVertex* const& end() const {return (ConstraintVertex* const&)m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex<<1))&3];}
__forceinline ConstraintVertex* const& apex() const {return (ConstraintVertex* const&)m_pkTriangle->m_kVertices[(18>>(m_uiEdgeIndex<<1))&3];}
__forceinline void turnLeft() {unsigned link=m_pkTriangle->m_ppLinks[m_uiEdgeIndex];m_uiEdgeIndex=(9>>((link&3)<<1))&3;m_pkTriangle=(ConstraintTriangle*)(link&~3u);}
__forceinline void turnRight() {unsigned index=(18>>(m_uiEdgeIndex<<1))&3;unsigned link=m_pkTriangle->m_ppLinks[index];m_uiEdgeIndex=link&3;m_pkTriangle=(ConstraintTriangle*)(link&~3u);}
__forceinline bool isValid() const { return m_pkTriangle!=0; }
__forceinline E next() const { return E(m_pkTriangle,(9>>(m_uiEdgeIndex<<1))&3); }
__forceinline E prev() const { return E(m_pkTriangle,(0x12>>(m_uiEdgeIndex<<1))&3); }
__forceinline E link() const { return E(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]); }
__forceinline void*& start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
__forceinline ConstraintVertex* const& vertex() const { return (ConstraintVertex* const&)start(); }
__forceinline unsigned rawLink() const {return m_pkTriangle->m_ppLinks[m_uiEdgeIndex];}
__forceinline void bindPacked(unsigned packed) const {

        unsigned index=packed&3u;

        ConstraintTriangle* other=(ConstraintTriangle*)(packed&~3u);

        m_pkTriangle->m_ppLinks[m_uiEdgeIndex]=(unsigned)other+index;

        if(other) other->m_ppLinks[index]=(unsigned)m_pkTriangle+m_uiEdgeIndex;

    }
__forceinline void bind(const ConstraintEdgeCore& other) const {

        m_pkTriangle->m_ppLinks[m_uiEdgeIndex]=other.m_uiEdgeIndex+(unsigned)other.m_pkTriangle;

        if(other.m_pkTriangle) other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex]=m_uiEdgeIndex+(unsigned)m_pkTriangle;

    }
__forceinline bool master() const {ConstraintVertex* b=end();ConstraintVertex* a=vertex();return a->pos.compare(b->pos)<=0 || !link().isValid();}
__forceinline E canonical() const {if(master())return E(m_pkTriangle,m_uiEdgeIndex);return link();}
__forceinline EdgeByte constrainedB() const {const E& e=canonical();const int c=((ConstraintFace*)e.m_pkTriangle)->constraints;return c & (1 << e.m_uiEdgeIndex);}
__forceinline bool constrained() const {const E e(canonical());return 0!=(((ConstraintFace*)e.m_pkTriangle)->constraints & (1 << e.m_uiEdgeIndex));}
__forceinline EdgeByte constrainedByte() const {

        const E& e=canonical();

        return ((ConstraintFace*)e.m_pkTriangle)->constraints & (1 << e.m_uiEdgeIndex);

    }
__forceinline void setConstraint() const {

        const E& e=canonical();

        ((ConstraintFace*)e.m_pkTriangle)->constraints |= 1 << e.m_uiEdgeIndex;

    }
__forceinline void clearConstraint() const {

        const E& e=canonical();

        ((ConstraintFace*)e.m_pkTriangle)->constraints &= ~(1 << e.m_uiEdgeIndex);

    }
__forceinline E flipBase() const {

        const ConstraintEdgeCore other=link();

        const ConstraintEdgeCore back=prev();

        const ConstraintEdgeCore acrossConstraint=other.prev();

        start()=acrossConstraint.start();

        other.start()=back.start();

        other.bind(back.link());

        bind(acrossConstraint.link());

        back.bind(acrossConstraint);

        return prev();

    }
};
struct ConstraintEdge : ConstraintEdgeCore<ConstraintEdge> {
__forceinline ConstraintEdge() {}
void operator=(const ConstraintEdge& e) {unsigned* d=reinterpret_cast<unsigned*>(this);const unsigned* q=reinterpret_cast<const unsigned*>(&e);d[0]=q[0];d[1]=q[1];}
__forceinline ConstraintEdge(const ConstraintEdge& e):ConstraintEdgeCore<ConstraintEdge>(e.m_pkTriangle,e.m_uiEdgeIndex) {}
__forceinline ConstraintEdge(ConstraintTriangle* t,unsigned i):ConstraintEdgeCore<ConstraintEdge>(t,i) {}
__forceinline ConstraintEdge(unsigned long l):ConstraintEdgeCore<ConstraintEdge>(l) {}
__forceinline int canFlip() const {

        if(!link().isValid() || constrained()) return 0;

const ConstraintEdge opposite=link();

const ConstraintEdge before=prev();

const ConstraintEdge acrossConstraint=opposite.prev();

        return orient(before.vertex(),vertex(),acrossConstraint.vertex())>0 && orient(acrossConstraint.vertex(),opposite.vertex(),before.vertex())>0;

    }
__forceinline int takeConstraint() const {

        int had=constrained();

        if(had) clearConstraint();

        return had;

    }
__forceinline ConstraintEdge flip() const {

        int first=prev().takeConstraint();

        int second=link().prev().takeConstraint();

        ConstraintEdge result=flipBase();

        if(first) result.link().next().setConstraint();

        if(second) result.next().setConstraint();

        return result;

    }
};

__forceinline int orientRaw(int ax,int ay,int bx,int by,int cx,int cy) {

    bx-=ax; by-=ay; cx-=ax; cy-=ay;

    return -(by*cx-bx*cy);

}

__forceinline int orient(const ConstraintVertex* a,const ConstraintVertex* b,int x,int y) {

    return orientRaw(a->pos.x,a->pos.y,b->pos.x,b->pos.y,x,y);

}

__forceinline int orient(const ConstraintVertex* a,const ConstraintVertex* b,const ConstraintVertex* c) {

    return orientRaw(a->pos.x,a->pos.y,b->pos.x,b->pos.y,c->pos.x,c->pos.y);

}

struct ConstraintResult {

    int status;

    ConstraintEdge edge;

    __forceinline ConstraintResult() {}

    __forceinline ConstraintResult(int s,const ConstraintEdge& e):status(s),edge(e) {}

    __forceinline ConstraintResult* assign(int s,const ConstraintEdge& e) {status=s;edge=ConstraintEdge(e);return this;}

    __forceinline ConstraintResult* assignSpecial(int s,const ConstraintEdge& e) {status=s;edge=ConstraintEdge(e);return this;}

__forceinline ConstraintResult* assignFailure(int s,const ConstraintEdge& e) {ConstraintEdge t(e);status=s;edge=ConstraintEdge(t);return this;}

    ConstraintResult* FUN_00e22c80(unsigned, ConstraintEdge*);

};

void __cdecl ResizeAudioStream(void*,void*,int);

struct ConstraintEdges {

    ConstraintEdge* data;

    int size;

    int capacity;

    __forceinline void push(const ConstraintEdge& edge) {

        Allocator& heap=FUN_00c85750().getHeap();

        if(size==(capacity&0x3fffffff)) ResizeAudioStream(&heap,this,8);

        new(data+size) ConstraintEdge(edge);

        ++size;

    }

};

struct ConstraintIntArray {

    int* data;

    int size;

    int capacity;

};

struct ConstraintData : ConstraintIntArray { int inlineData[4]; };

struct ConstraintDataBlock {

    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;

    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;

    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;

    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;

    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;

    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;

    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;

    int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;

    int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;

    int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;

    int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;

    int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;

    int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;

    int unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc;

    int unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc;

    int unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc;

    int unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c;

    int unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c;

    int unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c;

    int unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c;

    int unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c;

    int unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc;

    int unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc;

    int unk2e0,unk2e4,unk2e8,unk2ec,unk2f0,unk2f4,unk2f8,unk2fc;

    int unk300,unk304,unk308,unk30c,unk310,unk314,unk318,unk31c;

    int unk320,unk324,unk328,unk32c,unk330,unk334,unk338,unk33c;

    int unk340,unk344,unk348,unk34c,unk350,unk354,unk358,unk35c;

    int unk360,unk364,unk368,unk36c,unk370,unk374,unk378,unk37c;

    ConstraintData* freeHead;

    int used;

};

struct ConstraintDataPool {

    ConstraintDataBlock** blocks;

    int size,capacity;

    ConstraintDataBlock* FUN_00e235d0();

    __forceinline ConstraintData* allocate() {

        ConstraintDataBlock* b;

        if(!size || !blocks[0]->freeHead) b=FUN_00e235d0();

        else b=blocks[0];

        ConstraintData* p=b->freeHead;

        ++b->used;

        b->freeHead=*(ConstraintData**)p;

        p->data=p->inlineData;

        p->size=0;

        p->capacity=0x80000004;

        return p;

    }

};

struct ConstraintHashEntry {

    ConstraintVertex* a;

    ConstraintVertex* b;

    ConstraintData* data;

    ConstraintHashEntry():a(0),b(0),data(0) {}

};

struct ConstraintHashBucket {ConstraintHashEntry* data;int size,capacity;};

struct ConstraintHash {ConstraintHashBucket* buckets;unsigned bucketCount;int unk08;int size;};



struct ConstraintMesh {

    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;

    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;

    ConstraintEdges edges;

    int unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;

    int unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c;

    int unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac;

    int unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc;

    int unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec;

    int unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c;

    int unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c;

    int unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c;

    int unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c;

    int unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c;

    int unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac;

    int unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc;

    int unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec;

    int unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c;

    int unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c;

    int unk230,unk234,unk238,unk23c,unk240,unk244,unk248;

    ConstraintHash* links;

    ConstraintDataPool attachments;

    ConstraintTriangle* cells[256];

    ConstraintResult LocatePoint(int,int);

    void FUN_00e25cd0(ConstraintEdge*,const int*);

    void FUN_00e25570();

    void FUN_00e25ba0();

    ConstraintEdge FUN_00e24650(ConstraintEdge,ConstraintVertex*,ConstraintVertex*);

    __forceinline void cache(ConstraintTriangle* t) {

        int row=(((ConstraintVertex*)t->m_kVertices[0])->pos.y+((ConstraintVertex*)t->m_kVertices[1])->pos.y+((ConstraintVertex*)t->m_kVertices[2])->pos.y)/3>>11;

        int col=(((ConstraintVertex*)t->m_kVertices[0])->pos.x+((ConstraintVertex*)t->m_kVertices[1])->pos.x+((ConstraintVertex*)t->m_kVertices[2])->pos.x)/3>>11;

        cells[(row<<4)+col]=t;

        ((ConstraintFace*)t)->visited=1;

    }

    __forceinline ConstraintEdge optimize(const ConstraintEdge& edge) {

        ConstraintVertex* a=edge.vertex();

        ConstraintVertex* b=edge.end();

        edges.push(edge.next());

        edges.push(edge.prev());

        if(edge.link().isValid()) {

            edges.push(edge.link().next());

            edges.push(edge.link().prev());

        }

        FUN_00e25570();

        ConstraintEdge result=FUN_00e24650(edge,a,b);return result;

    }

    __forceinline void optimizeInto(ConstraintEdge& edge) {

        ConstraintVertex* a=edge.vertex();

        ConstraintVertex* b=edge.end();

        edges.push(edge.next());

        edges.push(edge.prev());

        if(edge.link().isValid()) {

            edges.push(edge.link().next());

            edges.push(edge.link().prev());

        }

        FUN_00e25570();

        edge=FUN_00e24650(edge,a,b);

    }

    ConstraintResult* FUN_00e26010(ConstraintResult* out,int x0,int y0,int x1,int y1,bool optimizeEdge,const int* data);

};

struct __declspec(align(16)) S_00e27c90_V {
    float x, y, z, w;
};

struct __declspec(align(16)) S_00e27c90_Q {
    float x, y, z, w;
    void FUN_00cd9d10(int angle, const S_00e27c90_V* axis);
};

extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" void _ReadWriteBarrier();
extern int DAT_010eb088;
extern int DAT_010eb0e0;
extern "C" __m128 _mm_setr_ps(float,float,float,float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_setzero_ps();

struct __declspec(align(16)) OptVec4 {
    float x, y, z, w;
__forceinline OptVec4& operator=(const OptVec4& o) {_mm_store_ps(&x,o.q());return *this;}
    __forceinline const __m128 &q() const { return *(const __m128 *)this; }
};


__declspec(nothrow) __declspec(nothrow) void __cdecl ResizeAudioStream(Allocator *ctx, void *arr, int eltSize) throw();
__declspec(nothrow) void __cdecl FUN_00de9650(OptVec4 *pt, void *elem) throw();

extern double DAT_01015a40;



extern float DAT_0104da48;

float __cdecl ClampedAcos(float x);

struct SubArrInt {
    int *m_pData;
    int m_iArrayLength;
    int m_iCap;
    __forceinline void append(const int &value) throw();
};

struct ParameterHandle;
struct Param {
    int m_00;
    int m_04;
    int m_08;
};

struct TEnt;
struct BoundaryEntry;
struct NodeRes {
    BoundaryEntry *m_00;
    int m_04;
    __declspec(nothrow) void ClearAndFree(int arg) throw();
};
__declspec(nothrow) NodeRes *__cdecl FUN_00e248b0(void *node, int idx) throw();

struct ObjB {
    char enabled; char field_01; char field_02; char field_03;
    float tolerance;
    char flag08; char flag09; char flag0a; char flag0b; char flag0c; char flag0d;
    void FUN_00d74d40();
};
struct View {
    void *m_pData;
    int m_iArrayLength;
    int stride;
};
struct Pair {
    int a; int b;
    Pair() {}
    Pair(int aa,int bb) : a(aa),b(bb) {}
    static void *operator new(unsigned int,void *p) throw() {return p;}
};
struct PairArrRaw {
    Pair *m_pData; int m_iArrayLength; int m_iCap;
    __forceinline void append(const Pair& value) throw() {
        Allocator& heap=FUN_00c85750().getHeap();
        if(m_iArrayLength==(m_iCap&0x3fffffff)) ResizeAudioStream(&heap,this,8);
        new(m_pData+m_iArrayLength) Pair(value);
        ++m_iArrayLength;
    }
};
struct HoleQuery { int status; Pair edge; };
struct BoundaryEntry {
    Pair edge;
    int field08; int field0c; int field10; int field14;
    int field18; int field1c; int field20; int field24;
    int field28; int field2c; int field30; int field34; int field38; int field3c;
};
struct SolverPool {
    void *data; int size; int capacity; void *head; int count; int unknown;
    __declspec(nothrow) SolverPool() throw() : data(0),size(0),capacity(0x80000000),head(0),count(0) {}
    __declspec(nothrow) void ProcessEntries() throw();
    __declspec(nothrow) void ClearAndFreeItems() throw();
    __declspec(nothrow) void FUN_00e23a10() throw();
    __declspec(nothrow) void FUN_00e23d70() throw();
};
struct SolverMesh {
    void *vtable;
    short memorySize; short references;
    SolverPool vertices; SolverPool triangles;
    __declspec(nothrow) SolverMesh() throw() : vtable(&DAT_010eb088), references(1) {}
    __declspec(nothrow) __forceinline ~SolverMesh() throw() {
        vtable=&DAT_010eb088;
        triangles.FUN_00e23a10(); triangles.FUN_00e23d70();
        vertices.ProcessEntries(); vertices.ClearAndFreeItems();
    }
};
struct SolverTail {
    void *data; int size; int capacity;
    __declspec(nothrow) SolverTail() throw() {}
    __declspec(nothrow) void FUN_00e23c70() throw();
};
struct SolverRef {
    SolverRef() throw() : vtable(&DAT_010eb0e0), references(1) {}
    void *vtable;
    short memorySize; short references;
};
struct __declspec(align(16)) BigSolver : SolverRef {
    SolverMesh mesh;
    PairArrRaw m_40arr;
    Pair localPairs[64];
    struct EdgeMap *edgeMap;
    SolverTail tail;
    int field_25c; int field_260; int field_264; int field_268;
    int field_26c; int field_270; int field_274; int field_278;
    int field_27c; int field_280; int field_284; int field_288;
    int field_28c; int field_290; int field_294; int field_298;
    int field_29c; int field_2a0; int field_2a4; int field_2a8;
    int field_2ac; int field_2b0; int field_2b4; int field_2b8;
    int field_2bc; int field_2c0; int field_2c4; int field_2c8;
    int field_2cc; int field_2d0; int field_2d4; int field_2d8;
    int field_2dc; int field_2e0; int field_2e4; int field_2e8;
    int field_2ec; int field_2f0; int field_2f4; int field_2f8;
    int field_2fc; int field_300; int field_304; int field_308;
    int field_30c; int field_310; int field_314; int field_318;
    int field_31c; int field_320; int field_324; int field_328;
    int field_32c; int field_330; int field_334; int field_338;
    int field_33c; int field_340; int field_344; int field_348;
    int field_34c; int field_350; int field_354; int field_358;
    int field_35c; int field_360; int field_364; int field_368;
    int field_36c; int field_370; int field_374; int field_378;
    int field_37c; int field_380; int field_384; int field_388;
    int field_38c; int field_390; int field_394; int field_398;
    int field_39c; int field_3a0; int field_3a4; int field_3a8;
    int field_3ac; int field_3b0; int field_3b4; int field_3b8;
    int field_3bc; int field_3c0; int field_3c4; int field_3c8;
    int field_3cc; int field_3d0; int field_3d4; int field_3d8;
    int field_3dc; int field_3e0; int field_3e4; int field_3e8;
    int field_3ec; int field_3f0; int field_3f4; int field_3f8;
    int field_3fc; int field_400; int field_404; int field_408;
    int field_40c; int field_410; int field_414; int field_418;
    int field_41c; int field_420; int field_424; int field_428;
    int field_42c; int field_430; int field_434; int field_438;
    int field_43c; int field_440; int field_444; int field_448;
    int field_44c; int field_450; int field_454; int field_458;
    int field_45c; int field_460; int field_464; int field_468;
    int field_46c; int field_470; int field_474; int field_478;
    int field_47c; int field_480; int field_484; int field_488;
    int field_48c; int field_490; int field_494; int field_498;
    int field_49c; int field_4a0; int field_4a4; int field_4a8;
    int field_4ac; int field_4b0; int field_4b4; int field_4b8;
    int field_4bc; int field_4c0; int field_4c4; int field_4c8;
    int field_4cc; int field_4d0; int field_4d4; int field_4d8;
    int field_4dc; int field_4e0; int field_4e4; int field_4e8;
    int field_4ec; int field_4f0; int field_4f4; int field_4f8;
    int field_4fc; int field_500; int field_504; int field_508;
    int field_50c; int field_510; int field_514; int field_518;
    int field_51c; int field_520; int field_524; int field_528;
    int field_52c; int field_530; int field_534; int field_538;
    int field_53c; int field_540; int field_544; int field_548;
    int field_54c; int field_550; int field_554; int field_558;
    int field_55c; int field_560; int field_564; int field_568;
    int field_56c; int field_570; int field_574; int field_578;
    int field_57c; int field_580; int field_584; int field_588;
    int field_58c; int field_590; int field_594; int field_598;
    int field_59c; int field_5a0; int field_5a4; int field_5a8;
    int field_5ac; int field_5b0; int field_5b4; int field_5b8;
    int field_5bc; int field_5c0; int field_5c4; int field_5c8;
    int field_5cc; int field_5d0; int field_5d4; int field_5d8;
    int field_5dc; int field_5e0; int field_5e4; int field_5e8;
    int field_5ec; int field_5f0; int field_5f4; int field_5f8;
    int field_5fc; int field_600; int field_604; int field_608;
    int field_60c; int field_610; int field_614; int field_618;
    int field_61c; int field_620; int field_624; int field_628;
    int field_62c; int field_630; int field_634; int field_638;
    int field_63c; int field_640; int field_644; int field_648;
    int field_64c; int field_650; int field_654; int field_658;
    int baseVal;
    int field_660; int field_664; int field_668; int field_66c;
    int field_670; int field_674; int field_678; int field_67c;
    int field_680; int field_684; int field_688; int field_68c;
    int field_690; int field_694; int field_698; int field_69c;
    OptVec4 col0; OptVec4 col1; OptVec4 col2; OptVec4 col3;
    __declspec(nothrow) HoleQuery FUN_00e27ea0(int cx, int cy, int one, HoleQuery *input, int zero) throw();
    __declspec(nothrow) HoleQuery FUN_00e26010(int cxB, int cyB, int cxA, int cyA, int one, void *intArr) throw();
    __declspec(nothrow) void FUN_00e27b50(void *a, void *b, float c, int d) throw();
    __declspec(nothrow) void FUN_00e27c90(void *a, void *b, int c, int d) throw();
    __declspec(nothrow) HoleQuery LocatePoint(int cx, int cy) throw();
    __declspec(nothrow) int FUN_00e24b70() throw();
    __declspec(nothrow) void FUN_00e24fa0() throw();
    __declspec(nothrow) __declspec(noinline) int CheckLinks() throw();
    __declspec(nothrow) __declspec(noinline) void *LookupPairResult(void *pair) throw();
    __declspec(nothrow) void FUN_00e275d0(int) throw();
    __forceinline OptVec4 projectWorld(const OptVec4&) const;
    __forceinline TEnt quantizeWorld(const OptVec4&) const;
    __forceinline TEnt transformWorld(const OptVec4&) const;
__forceinline void initializeMap() throw() {edgeMap=0;}
    __declspec(nothrow) __forceinline BigSolver() throw();
    __declspec(nothrow) __forceinline ~BigSolver() throw() {
        vtable=&DAT_010eb0e0;
        FUN_00e275d0(1);
        tail.FUN_00e23c70();
        Allocator& ctx=FUN_00c85750().getHeap();
        int cap=m_40arr.m_iCap;
        m_40arr.m_iArrayLength=0;
        if((cap&0x80000000)==0) ctx.freeBlock(m_40arr.m_pData,(cap&0x3fffffff)*8);
        m_40arr.m_pData=0; m_40arr.m_iCap=0x80000000;
    }
};

static __forceinline void SetV(OptVec4 &v, float a, float b, float c, float d)
{
    _mm_store_ps(&v.x, _mm_setr_ps(a, b, c, d));
}
    __declspec(nothrow) BigSolver::BigSolver() throw() {
        m_40arr.m_pData=localPairs; m_40arr.m_iArrayLength=0; m_40arr.m_iCap=0x80000040; tail.data=0; tail.size=0; tail.capacity=0x80000000;
                OptVec4 lo; OptVec4 adjx;
                SetV(lo, DAT_01012054, DAT_01012054, 0.0f, 0.0f);
                SetV(adjx, 1.0f, 1.0f, 0.0f, 0.0f);
initializeMap();
                FUN_00e27b50(&lo, &adjx, 0.0f, 1);
    }template <class T> struct HArr {
    T *m_pData; int m_iArrayLength; int m_iCap;
    __forceinline HArr() throw() : m_pData(0), m_iArrayLength(0), m_iCap((int)0x80000000) {}
    __forceinline ~HArr() throw()
    {
        Router *svc = ((Router*)&FUN_00c85750());
        Allocator *ctx = svc->heap;
        int cap = m_iCap;
        m_iArrayLength = 0;
        if ((cap & 0x80000000) == 0)
            ctx->freeBlock(m_pData, (cap & 0x3fffffff) * sizeof(T));
        m_pData = 0;
        m_iCap = (int)0x80000000;
    }
};
struct PairArr : HArr<Pair> {
    __forceinline void append(const Pair& value) throw() {
        Allocator& heap=FUN_00c85750().getHeap();
        if(m_iArrayLength==(m_iCap&0x3fffffff)) ResizeAudioStream(&heap,this,8);
        new(m_pData+m_iArrayLength) Pair(value);
        ++m_iArrayLength;
    }
};

__forceinline void SubArrInt::append(const int &value) throw()
{
    Router *svc = ((Router*)&FUN_00c85750());
    if (m_iArrayLength == (m_iCap & 0x3fffffff))
        ResizeAudioStream(svc->heap, this, 4);
    m_pData[m_iArrayLength] = value;
    m_iArrayLength += 1;
}
struct ObjA {
    void *vtable;
    unsigned short memorySize; unsigned short referenceCount; int field_008; int field_00c; int field_010;
    __declspec(nothrow) void FUN_00d76ca0() throw();
    __forceinline ObjA() throw() { FUN_00d76ca0(); }
    __forceinline ~ObjA() throw() { FUN_00d76940(); }
    __declspec(nothrow) void FUN_00d76d90(void *out) throw();
    __declspec(nothrow) void FUN_00d76940();
    __declspec(nothrow) int FUN_00d74e10();
    __declspec(nothrow) void FUN_00d77200(View *view, ObjB *obj);
    __declspec(nothrow) void FUN_00e124d0(void *arr) throw();
    __declspec(nothrow) void RemoveTriangle(void *item) throw();
};

struct TEnt {__forceinline int compareClear(const TEnt& v)const{const int bx=v.m_08;const int ax=m_08;if(ax<bx)return -1;if(ax>bx)return 1;const int by=v.m_0c;const int ay=m_0c;if(ay<by)return -1;if(ay>by)return 1;return 0;}__forceinline int compare(const TEnt& v)const{if(m_08<v.m_08)return -1;if(m_08>v.m_08)return 1;if(m_0c<v.m_0c)return -1;if(m_0c>v.m_0c)return 1;return 0;}static __forceinline bool ordered(const TEnt* a,const TEnt* b){int c=a->compare(*b);if(c<0)return true;if(c>0)return false;return true;}
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned int marker : 1;
    unsigned int userIndex : 31;
};
struct FlagValue56 {unsigned int value; __forceinline FlagValue56(int bits):value(bits) {} __forceinline operator int() const {return value!=0;} };
struct LowFlags56 {unsigned int value;__forceinline LowFlags56(unsigned int x):value(x){}};
static __forceinline unsigned int operator&(const LowFlags56& a,const unsigned int& b){unsigned int result=a.value;result&=b;return result;}
struct Flags56 {unsigned short bits; __forceinline LowFlags56 get() const {LowFlags56 x(bits);x.value&=7;return x;}};
struct BoundingVolumeNode {
    BoundingVolumeNode *m_00;
    int unk_04;
    TEnt *m_08[3];
    int m_14[3];
    union {
        unsigned short m_20;
        Flags56 word56;
        struct { unsigned short flags:3; unsigned short otherFlags:13; };
    };
    short unk_22;
    int field_024; int field_028; int field_02c;
};


struct VertexRecord {
    VertexRecord *next; VertexRecord *previous;
    int unknown08; int unknown0c;
    OptVec4 position;
};
struct BNode {
    __forceinline int& edgeLink(int i) {return m_14[i];}
    __forceinline void setCorners(const int& a,const int& b,const int& c) {vertices[0]=a;vertices[1]=b;vertices[2]=c;}

    __forceinline int& corner(int i) {return vertices[i];}
    BNode *next; BNode *previous;
    int vertices[3];
    int m_14[3];
    OptVec4 plane;
    int m_30; int unk_34; int m_38; int field_3c;
    int field_40; int field_44; int field_48; int field_4c;
};

struct ObjASub8 {
    void *data; int size; int capacity; void *head; int count; int unknown;
    __declspec(nothrow) void FUN_00e22f90(void *node) throw();
    __forceinline void removeVertex(struct VertexRecord *v) throw();
};

__declspec(nothrow) void __cdecl FUN_00e11710(void *a, void *b, void *c, void *d, int e) throw();

static __forceinline int CompareVerts(const TEnt *a, const TEnt *b)
{
    if (a->m_08 < b->m_08) return -1;
    if (a->m_08 > b->m_08) return 1;
    if (a->m_0c < b->m_0c) return -1;
    if (a->m_0c > b->m_0c) return 1;
    return 0;
}
struct HBool { char m_cBooleanValue; __forceinline HBool(bool b) { m_cBooleanValue = (char)b; } __forceinline operator bool() const { return m_cBooleanValue != 0; } };

struct SavedFlag56 {unsigned int state; __forceinline SavedFlag56(const FlagValue56& x):state((char)x.value!=0) {} __forceinline operator int() const {return state;}};
static __forceinline unsigned long packEdgeUid(void* triangle,unsigned int index) {return *(const unsigned long*)&triangle+(unsigned long)index;}
template<class T,class I> static __forceinline void unpackEdgeUid(const unsigned long& value,T*& triangle,I& index) {unsigned long packed=value;index=I(packed&3);packed&=~3;triangle=*(T**)&packed;}
static __forceinline bool clearOrdered(const TEnt* a,const TEnt* b){return a->compareClear(*b)<=0;}
struct TEdge {
    BoundingVolumeNode *t; int i;
    __forceinline TEdge() {}
    __forceinline TEdge(BoundingVolumeNode *tt, int ii) : t(tt), i(ii) {}
    __forceinline TEnt *&start() const { return t->m_08[i]; }
    __forceinline TEnt *&end() const { return t->m_08[(9 >> (i << 1)) & 3]; }
    __forceinline TEdge next() const { TEdge r;r.t=t;r.i=(9>>(i*2))&3;return r; }
    __forceinline TEdge prev() const { TEdge r;r.t=t;r.i=(18>>(i*2))&3;return r; }
    __forceinline TEdge link() const { TEdge e;unpackEdgeUid(t->m_14[i],e.t,e.i);return e; }
    __forceinline bool hasLink() const { return (t->m_14[i] & ~3) != 0; }
    __forceinline bool isMaster() const { return TEnt::ordered(start(),end()) || !hasLink(); }
    __forceinline TEdge master() const { if (isMaster()) return *this; return link(); }
    __forceinline bool isConstrained() const {TEdge m=master();return 0!=(m.t->flags & (1<<m.i));}
__forceinline int take() const {const int r=isConstrained();if(r)clearConstrained();return r;}
    __forceinline HBool hb() const { TEdge m = master(); return (m.t->flags & (1 << m.i)) != 0; }
    __forceinline void setConstrained() const { TEdge m = master(); m.t->flags = m.t->m_20 | (1 << m.i); }
    __forceinline void clearConstrained() const { TEdge m = master(); m.t->flags &= ~(1 << m.i); }__forceinline bool clearIsMaster()const{return clearOrdered(start(),end()) || !hasLink();}__forceinline TEdge masterClear()const{if(clearIsMaster())return *this;return link();}__forceinline void clearSpecial()const{TEdge m=masterClear();m.t->flags &= ~(1<<m.i);}
    __forceinline void bind(const TEdge &o) const
    {
        t->m_14[i] = packEdgeUid(o.t,o.i);
        if (o.t) o.t->m_14[o.i] = packEdgeUid(t,i);
    }
};

struct TEdgeB {
    BNode *t; int i;
    __forceinline TEdgeB(BNode *tt, int ii) : t(tt), i(ii) {}
    __forceinline int start() const { return t->vertices[i]; }
    __forceinline int end() const { return t->vertices[(9 >> (i << 1)) & 3]; }
};
struct EdgeMapEntry { TEnt *start; TEnt *end; void *value; };
struct EdgeMapBucket { EdgeMapEntry *m_pData; int m_iArrayLength; int m_iCap; };
struct EdgeMap { EdgeMapBucket *buckets; unsigned int numBuckets; };

enum { VerifySolverSize = 1 / (sizeof(BigSolver)==0x6e0 ) };
enum { VerifyBoundarySize = 1 / (sizeof(BoundaryEntry)==0x40 ) };
enum { VerifyOptionsSize = 1 / (sizeof(ObjB)==0x10 ) };
enum { VerifyViewSize = 1 / (sizeof(View)==0x0c ) };
enum { VerifyVertexSize = 1 / (sizeof(VertexRecord)==0x20 ) };
enum { VerifyTriangleSize = 1 / (sizeof(BNode)==0x50 ) };


static __forceinline void buildGrid(HArr<OptVec4>& arr,OptVec4& akGridVector) throw() {
    int i = 0;

    _mm_store_ps(&akGridVector.x, _mm_setzero_ps());
    for (; i < 8; i++) {
        OptVec4 pt;
        _mm_store_ps(&pt.x, _mm_load_ps(&akGridVector.x));
        pt.y = (float)(i / DAT_01015a40);
        for (int sv = 0; sv < 8; sv++) {
            pt.x = (float)(sv / DAT_01015a40);
            Router *svc = ((Router*)&FUN_00c85750());
            if (arr.m_iArrayLength == (arr.m_iCap & 0x3fffffff))
                ResizeAudioStream(svc->heap, &arr, 0x10);
            OptVec4 *elem = &((OptVec4*)arr.m_pData)[arr.m_iArrayLength];
            arr.m_iArrayLength++;
            FUN_00de9650(&pt, elem);
        }
    }
}

struct ParameterHandle {Param* value; __forceinline Param* operator->() const {return value;} __forceinline operator Param*() const {return value;} };

namespace PointBoundsIntrinsics {
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_set_ps1(float value);
}
extern float DAT_0104e148;

struct PointBoundsOutput {
    void* value;
    __forceinline PointBoundsOutput(void* address) : value(address) {}
};

struct Point2I { int unk00, unk04; int x,y; };

struct WalkTriangle {
    WalkTriangle* nextNode;
    int unk04;
    Point2I* vertices[3];
    unsigned links[3];
    __forceinline Point2I*& vertex(int i) { return vertices[i]; }
};
template<class T> struct WalkEdgeBase {
    T* m_pkTriangle;
    unsigned m_uiEdgeIndex;
    WalkEdgeBase() {}
    WalkEdgeBase(T* t,unsigned i):m_pkTriangle(t),m_uiEdgeIndex(i) {}
};
struct WalkEdge:WalkEdgeBase<WalkTriangle> {
    WalkEdge() {}
    WalkEdge(WalkTriangle* t,unsigned i):WalkEdgeBase<WalkTriangle>(t,i) {}
    WalkEdge(const WalkEdge& e):WalkEdgeBase<WalkTriangle>(e.m_pkTriangle,e.m_uiEdgeIndex) {}
    WalkEdge(unsigned packed) { m_uiEdgeIndex=packed&3u; m_pkTriangle=(WalkTriangle*)(packed&~3u); }
    __forceinline Point2I*& end() const { return m_pkTriangle->vertex((9>>(2*m_uiEdgeIndex))&3); }
    __forceinline WalkEdge next() const { return WalkEdge(m_pkTriangle,(9>>(2*m_uiEdgeIndex))&3); }
    __forceinline WalkEdge prev() const { return WalkEdge(m_pkTriangle,(18>>(2*m_uiEdgeIndex))&3); }
    __forceinline WalkEdge link() const { return WalkEdge(m_pkTriangle->links[m_uiEdgeIndex]); }
    __forceinline Point2I*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
};

struct WalkHit {
    int kind;
    WalkEdge edge;
    WalkHit(int k,const WalkEdge& e):kind(k),edge(e) {}
};
extern char DAT_010eafd4[],DAT_010eaf60[];

extern "C" double __cdecl fabs(double);

struct __declspec(align(16)) Vec4A {
    float x, y, z, w;
    const char* FUN_00c7f520(void* a, float c);
    __forceinline Vec4A& set(const Vec4A& v) {
        _mm_store_ps(&x, _mm_load_ps(&v.x));
        return *this;
    }
};
typedef Vec4A Plane;
struct PTri {
    int unk00;
    int unk04;
    void* m_08;
    void* m_0C;
    void* m_10;
    unsigned int m_ppLinks[3];
    Plane m_kTriangleNormal;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
};
struct PEdge {
    PTri* tri;
    int index;
    PEdge(PTri* t, int i) : tri(t), index(i) {}
};
struct PtrArr {
    PTri** data;
    int size;
    unsigned int cap;
};
struct EdgeArr {
    PEdge* data;
    int size;
    unsigned int cap;
};
struct VecArr {
    Vec4A* data;
    int size;
    unsigned int cap;
    void AddBack(const Vec4A& v);
};
struct TriPtrArr {
    PTri** data;
    int size;
    unsigned int cap;
    void AddBack(PTri* t);
};
__forceinline void VecArr::AddBack(const Vec4A& v)
{
    Router& r = FUN_00c85750();
    if (size == (int)(cap & 0x3fffffff))
        ::ResizeAudioStream(r.heap, this, 16);
    data[size].set(v);
    size++;
}
__forceinline void TriPtrArr::AddBack(PTri* t)
{
    Router& r = FUN_00c85750();
    if (size == (int)(cap & 0x3fffffff))
        ::ResizeAudioStream(r.heap, this, 4);
    PTri** dst = data + size;
    __assume(dst != 0);
    *dst = t;
    size++;
}


static __forceinline void PushEdge(EdgeArr& arr, const PEdge& e)
{
    Router& r = FUN_00c85750();
    if (arr.size == (int)(arr.cap & 0x3fffffff))
        ::ResizeAudioStream(r.heap, &arr, 8);
    PEdge* dst = arr.data + arr.size;
    if (dst) {
        *dst = e;
    }
    arr.size++;
}
static __forceinline void FreeEdgeArr(EdgeArr& arr, int elem)
{
    Router& r = FUN_00c85750();
    Allocator* ao = r.heap;
    int cap = (int)arr.cap;
    arr.size = 0;
    if ((cap & 0x80000000u) == 0)
        ao->freeBlock(arr.data, (cap & 0x3fffffff) * elem);
    arr.data = 0;
    arr.cap = 0x80000000;
}
static __forceinline void FreePtrArr(PtrArr& arr, int elem)
{
    Router& r = FUN_00c85750();
    Allocator* ao = r.heap;
    int cap = (int)arr.cap;
    arr.size = 0;
    if ((cap & 0x80000000u) == 0)
        ao->freeBlock(arr.data, (cap & 0x3fffffff) * elem);
    arr.data = 0;
    arr.cap = 0x80000000;
}
static __forceinline float HSum3(__m128 m)
{
    __m128 sh = _mm_shuffle_ps(m, m, 0x55);
    __m128 sh2 = _mm_shuffle_ps(m, m, 0xaa);
    __m128 sum = _mm_add_ss(sh, m);
    __m128 tot = _mm_add_ss(sh2, sum);
    float out;
    _mm_store_ss(&out, tot);
    return out;
}

struct E13B00This {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28;
    PTri* m_2C;
    int m_30;
    int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8;
    VecArr m_CC;
    TriPtrArr m_D8;
    void FUN_00e12890(PtrArr* arr, int flag);
    int FUN_00e13b00(float a1, float a2, bool a3);
};

// Flood-fills groups of linked triangles whose plane dot is at least a1 and w difference at most a2, storing group planes in m_CC and seed triangles in m_D8.
// @fnv 0x00e13b00
int E13B00This::FUN_00e13b00(float afMinDot, float afMaxWDiff, bool a3)
{
    m_CC.size = 0;
    m_D8.size = 0;
    if (!m_30)
        return 0;
    PtrArr nxt;
    nxt.data = 0;
    nxt.size = 0;
    nxt.cap = 0x80000000;
    FUN_00e12890(&nxt, 1);
    EdgeArr arrB;
    arrB.data = 0;
    arrB.size = 0;
    arrB.cap = 0x80000000;
    int i = 0;
    if (nxt.size > 0) {
        do {
            PTri* tri = nxt.data[i];
            if (tri->unk34 < 0) {
                bool c;
                const char* ptot = tri->m_kTriangleNormal.FUN_00c7f520(&c, DAT_010141cc);
                if (ptot[0]) {
                    Vec4A dot;
                    dot = tri->m_kTriangleNormal;
                    tri->unk34 = m_CC.size;
                    arrB.size = 0;
                    PushEdge(arrB, PEdge(tri, 0));
                    PushEdge(arrB, PEdge(tri, 1));
                    PushEdge(arrB, PEdge(tri, 2));
                    m_CC.AddBack(dot);
                    m_D8.AddBack(tri);
                    while (arrB.size != 0) {
                        PEdge ed = arrB.data[arrB.size - 1];
                        unsigned int V = ed.tri->m_ppLinks[ed.index];
                        int tmp = (int)(V & 3);
                        PTri* pNextTri = (PTri*)(V & ~3u);
                        arrB.size--;
                        if (!pNextTri)
                            continue;
                        if (pNextTri->unk34 != -1)
                            continue;
                        if (a3) {
                            if (pNextTri->unk38 != tri->unk38)
                                continue;
                        }
                        __m128 pm = _mm_mul_ps(_mm_load_ps(&pNextTri->m_kTriangleNormal.x), *(const __m128*)&dot);
                        __m128 psh = _mm_shuffle_ps(pm, pm, 0x55);
                        __m128 psum = _mm_add_ss(psh, pm);
                        __m128 secondShuffle = _mm_shuffle_ps(pm, pm, 0xaa);
                        __m128 linked = _mm_add_ss(secondShuffle, psum);
                        float link;
                        _mm_store_ss(&link, linked);
                        if (!(link >= afMinDot))
                            continue;
                        float cnt = dot.w - pNextTri->m_kTriangleNormal.w;
                        cnt = (float)fabs(cnt);
                        if (!(cnt <= afMaxWDiff))
                            continue;
                        pNextTri->unk34 = tri->unk34;
                        int arrA = (9 >> (tmp + tmp)) & 3;
                        PushEdge(arrB, PEdge(pNextTri, arrA));
                        int linkIdx = (0x12 >> (tmp + tmp)) & 3;
                        PushEdge(arrB, PEdge(pNextTri, linkIdx));
                    }
                }
            }
            i++;
        } while (i < nxt.size);
    }
    int result = m_CC.size;
    FreeEdgeArr(arrB, 8);
    FreePtrArr(nxt, 4);
    return result;
}

extern "C" void _WriteBarrier();
extern "C" double __cdecl fabs(double);
__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);


struct __declspec(align(16)) CollapsePosition {
    float x,y,z,w;
    void operator=(const CollapsePosition& v) { reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v); }
    __m128 quad() const { return reinterpret_cast<const __m128&>(*this); }
    void set(__m128 v) { reinterpret_cast<__m128&>(*this) = v; }
};
namespace CollapseThreshold {static float DAT_0104da4c=1.1920928955078125e-7f;}
struct CollapseVertex {
    int unk00,unk04,unk08,unk0c;
    CollapsePosition position;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;
    int mark;
};
struct CollapseTriangle {
    CollapseTriangle* next;
    CollapseTriangle* prev;
    CollapseVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};
struct CollapseEdgeFields { CollapseTriangle* m_pkTriangle; unsigned int m_uiEdgeIndex; };
struct CollapseEdge : CollapseEdgeFields {
    CollapseEdge() {}
    CollapseEdge(CollapseTriangle* t,unsigned int i) {m_pkTriangle=t; m_uiEdgeIndex=i;}
    CollapseEdge(unsigned int packed) {m_uiEdgeIndex=packed&3; m_pkTriangle=(CollapseTriangle*)(packed&~3u);}
    __forceinline bool isValid() const {return m_pkTriangle!=0;}
    __forceinline CollapseEdge next() const {return CollapseEdge(m_pkTriangle,(9>>(m_uiEdgeIndex*2))&3);}
    __forceinline CollapseEdge prev() const {return CollapseEdge(m_pkTriangle,(18>>(m_uiEdgeIndex*2))&3);}
    __forceinline CollapseEdge link() const {return CollapseEdge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);}
    __forceinline const CollapsePosition& endPosition() const {return m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex*2))&3]->position;}
    __forceinline CollapseVertex*& end() const {return m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex*2))&3];}
    __forceinline CollapseVertex*& start() const {return m_pkTriangle->m_kVertices[m_uiEdgeIndex];}
};
__forceinline CollapseVertex* collapseVertex(void* p) {return (CollapseVertex*)p;}
__forceinline float triangleArea(CollapseTriangle* n) {
    __m128 a = collapseVertex(n->m_kVertices[0])->position.quad();
    __m128 e1 = _mm_sub_ps(collapseVertex(n->m_kVertices[1])->position.quad(), a);
    __m128 e2 = _mm_sub_ps(collapseVertex(n->m_kVertices[2])->position.quad(), a);
    __m128 c = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(e2,e2,0xd2), _mm_shuffle_ps(e1,e1,0xc9)),
        _mm_mul_ps(_mm_shuffle_ps(e2,e2,0xc9), _mm_shuffle_ps(e1,e1,0xd2)));
    __m128 sq = _mm_mul_ps(c,c);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(sq,sq,0xaa),_mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq));
    float r; _mm_store_ss(&r,_mm_sqrt_ss(d)); return r;
}
struct E17F40Hull;
struct CollapseContext {
    E17F40Hull* mesh;
    CollapsePosition target;
    float minDot,oldAreaSum,newAreaSum;
    CollapseContext(E17F40Hull* owner,const CollapsePosition& position):mesh(owner),target(position),minDot(1.0f),oldAreaSum(0.0f),newAreaSum(0.0f) {}
    __forceinline void operator()(CollapseEdge cursor);
};
struct __declspec(align(16)) CollapseStats {float minDot,oldAreaSum,newAreaSum;};
struct CollapseEdgeArray {
    CollapseEdge* data;
    int size, capacity;
    struct Slot {CollapseTriangle* triangle; unsigned int index;};
    Slot storage[16];
    __forceinline CollapseEdgeArray() throw(): data(reinterpret_cast<CollapseEdge*>(storage)),size(0),capacity(0x80000010) {}
    __forceinline void append(const CollapseEdge& e) throw() {
        Allocator& heap=FUN_00c85750().getHeap();
        if (size == (capacity & 0x3fffffff)) ResizeAudioStream(&heap,this,8);
        new(data+size) CollapseEdge(e); ++size;
    }
    __forceinline void operator()(const CollapseEdge& e) throw() {append(e);}
    __forceinline ~CollapseEdgeArray() throw() {
        Allocator& heap=FUN_00c85750().getHeap();
        size=0;
        if (!(capacity & 0x80000000)) heap.freeBlock(data,(capacity & 0x3fffffff)*8);
        data=0; capacity=0x80000000;
    }
};
struct E17F40Hull {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28;
    CollapseTriangle* faces;
    int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    bool error; float minLengthSquared, minArea;
    __declspec(nothrow) void FUN_00e14a90();
    __declspec(nothrow) void ReleaseSubobject();
    __declspec(nothrow) void FUN_00e11da0(int);
    __declspec(nothrow) void RemoveEdge(CollapseEdge,bool);
    __declspec(noinline) __declspec(nothrow) void FUN_00e11500(const CollapsePosition*,const CollapsePosition*);
    __declspec(noinline) __declspec(nothrow) void FUN_00e114f0(const CollapsePosition*,const CollapsePosition*,const CollapsePosition*);
    __declspec(noinline) __declspec(nothrow) bool FUN_00e11710(const CollapsePosition*,const CollapsePosition*,const CollapsePosition*,CollapsePosition*,bool);
    __declspec(noinline) __declspec(nothrow) bool FUN_00e118e0(const volatile CollapseTriangle*,CollapsePosition*,bool);
    void FUN_00e17f40(float* options);
};
void E17F40Hull::FUN_00e11500(const CollapsePosition*,const CollapsePosition*) {error=true;}
void E17F40Hull::FUN_00e114f0(const CollapsePosition*,const CollapsePosition*,const CollapsePosition*) {error=true;}
bool E17F40Hull::FUN_00e11710(const CollapsePosition* a,const CollapsePosition* b,const CollapsePosition* c,CollapsePosition* out,bool check) {
    float tolerance = minLengthSquared;
    bool valid=true;
    __m128 ab = _mm_sub_ps(b->quad(),a->quad());
    if(check && ToReal(Dot3(ab,ab)) <= tolerance) {FUN_00e11500(a,b);valid=false;}
    __m128 ac = _mm_sub_ps(c->quad(),a->quad());
    if(check && ToReal(Dot3(ac,ac)) <= tolerance) {FUN_00e11500(a,c);valid=false;}
    __m128 bc = _mm_sub_ps(c->quad(),b->quad());
    if(check && ToReal(Dot3(bc,bc)) <= tolerance) {FUN_00e11500(c,b);valid=false;}
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(ac,ac,0xd2),_mm_shuffle_ps(ab,ab,0xc9)),_mm_mul_ps(_mm_shuffle_ps(ac,ac,0xc9),_mm_shuffle_ps(ab,ab,0xd2)));
    out->set(cross);
    float length = ToReal(_mm_sqrt_ss(Dot3(cross,cross)));
    out->w=length;
    if (check && length < minArea) {FUN_00e114f0(a,b,c);valid=false;}
    out->set(_mm_mul_ps(_mm_set_ps1(1.0f/out->w),out->quad()));
    out->w=ToReal(_mm_sub_ss(DAT_010c7160,Dot3(a->quad(),out->quad())));
    return valid;
}
bool E17F40Hull::FUN_00e118e0(const volatile CollapseTriangle* face,CollapsePosition* out,bool check) {
    return FUN_00e11710(&collapseVertex(face->m_kVertices[0])->position,&collapseVertex(face->m_kVertices[1])->position,&collapseVertex(face->m_kVertices[2])->position,out,check);
}
__forceinline void CollapseContext::operator()(CollapseEdge cursor) {
                    oldAreaSum += triangleArea(cursor.m_pkTriangle);
                    CollapsePosition oldPlane;
                    mesh->FUN_00e118e0(cursor.m_pkTriangle,&oldPlane,true);
                    CollapsePosition savedPosition=collapseVertex(cursor.start())->position;
                    collapseVertex(cursor.start())->position=target;
                    float newArea=triangleArea(cursor.m_pkTriangle);
                    CollapsePosition newPlane;
                    mesh->FUN_00e118e0(cursor.m_pkTriangle,&newPlane,true);
                    collapseVertex(cursor.start())->position=savedPosition;
                    if(CollapseThreshold::DAT_0104da4c < newArea) {
                        float dot=ToReal(Dot3(oldPlane.quad(),newPlane.quad()));
                        minDot = minDot < dot ? minDot : dot;
                        newAreaSum += newArea;
                    }
}

#include <math.h>

namespace MeshTransformE27 {

extern "C" ::__m128 _mm_setr_ps(float x, float y, float z, float w);

extern double DAT_01029790;
extern float DAT_01011d78;

struct hkVector4 {
    ::__m128 m_vComponents;
    void set(float x, float y, float z, float w) { m_vComponents = (_mm_setr_ps)(x, y, z, w); }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};

struct hkMatrix4 {
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    float& operator()(int r, int c) { return (&m_kColumn0)[c](r); }
    void setIdentity();
};

extern hkVector4 DAT_0126a3e0;
extern hkVector4 DAT_0126a3f0;
extern hkVector4 DAT_0126a400;
extern hkVector4 DAT_0126a410;

inline void hkMatrix4::setIdentity()
{
    m_kColumn0.m_vComponents = DAT_0126a3e0.m_vComponents;
    m_kColumn1.m_vComponents = DAT_0126a3f0.m_vComponents;
    m_kColumn2.m_vComponents = DAT_0126a400.m_vComponents;
    m_kColumn3.m_vComponents = DAT_0126a410.m_vComponents;
}

struct TwoComponentVector {
    float x;
    float y;
};

struct Sub6a0 {
    void FUN_00de8c50(const hkMatrix4* pkTransform, float fTime);
};

struct Obj27b50 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    int unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c;
    int unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc, unk2c0, unk2c4, unk2c8, unk2cc;
    int unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c;
    int unk330, unk334, unk338, unk33c, unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c, unk380, unk384, unk388, unk38c;
    int unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec;
    int unk3f0, unk3f4, unk3f8, unk3fc, unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c, unk440, unk444, unk448, unk44c;
    int unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac;
    int unk4b0, unk4b4, unk4b8, unk4bc, unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc, unk500, unk504, unk508, unk50c;
    int unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c;
    int unk570, unk574, unk578, unk57c, unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc, unk5c0, unk5c4, unk5c8, unk5cc;
    int unk5d0, unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c, unk620, unk624, unk628, unk62c;
    int unk630, unk634, unk638, unk63c, unk640, unk644, unk648, unk64c, unk650, unk654, unk658;
    int m_iFlipped;
    hkMatrix4 m_kTransform;
    Sub6a0 m_kSub;

    void FUN_00e27b50(const TwoComponentVector* pkFrom, const TwoComponentVector* pkTo, float fAngleDifference, bool bFlip);
    void FUN_00e275d0(int i);
};

// @fnv 0x00e27b50
void Obj27b50::FUN_00e27b50(const TwoComponentVector* pkFrom, const TwoComponentVector* pkTo, float fAngleDifference, bool bFlip)
{
    m_iFlipped = bFlip != false;
    float fScale = (float)(DAT_01029790 - m_iFlipped * 2.0);
    float fSin = sin(fAngleDifference);
    float fCos = cos(fAngleDifference);

    hkVector4 kScale;
    kScale.set((pkTo->x - pkFrom->x) / fScale, (pkTo->y - pkFrom->y) / fScale, DAT_01011d78, DAT_01011d78);

    m_kTransform.setIdentity();

    m_kTransform(0, 0) = kScale(0) * fCos;
    m_kTransform(0, 1) = kScale(1) * fSin;
    m_kTransform(0, 3) = pkFrom->x;
    m_kTransform(1, 0) = -fSin * kScale(0);
    m_kTransform(1, 1) = kScale(1) * fCos;
    m_kTransform(1, 3) = pkFrom->y;

    m_kSub.FUN_00de8c50(&m_kTransform, 0.0f);
    FUN_00e275d0(1);
}


}
