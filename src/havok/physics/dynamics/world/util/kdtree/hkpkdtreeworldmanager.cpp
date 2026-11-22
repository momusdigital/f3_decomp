#include "f3_common.h"
// src/havok/physics/dynamics/world/util/kdtree/hkpkdtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/kdtree/hkpkdtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00c917a0_shell
{
    void FUN_00c917a0(void*);
};

struct FUN_00c917f0_shell
{
    void FUN_00c917f0(void*);
};

struct FUN_00d97850_shell
{
    void ClearBuffers();
};

void* __cdecl _D1A0E0GetMemoryRouter();

extern int DAT_010cd278;
extern int DAT_010cd25c;
extern int DAT_010cd244;
extern int _DAT_0102e388;
extern int DAT_0104e3d0;
extern int $SG5957;

struct FUN_00d0a4f0
{
    void* m_ppVirtualMethodTable;  // +0x00
    char pad[0x0c];  // +0x04..0x0f
    void* m_ptr10;   // +0x10
    void* m_ptr14;   // +0x14
    void* m_ptr18;   // +0x18
    void* m_ptr1c;   // +0x1c
    ~FUN_00d0a4f0();
};

// @fnv 0x00d0a4f0
FUN_00d0a4f0::~FUN_00d0a4f0()
{
    *(int*)this = (int)&DAT_010cd278;
    *(int*)((char*)this + 0x14) = (int)&DAT_010cd25c;
    *(int*)((char*)this + 0x18) = (int)&DAT_010cd244;

    ((FUN_00c917a0_shell*)*(void**)((char*)this + 0x1c))->FUN_00c917a0((char*)this + 0x14);
    ((FUN_00c917f0_shell*)*(void**)((char*)this + 0x1c))->FUN_00c917f0((char*)this + 0x18);

    void* p = *(void**)((char*)this + 0x10);
    if (p)
    {
        ((FUN_00d97850_shell*)p)->ClearBuffers();
        void* router = _D1A0E0GetMemoryRouter();
        void* mgr = *(void**)((char*)router + 0x10);
        void** vtbl = *(void***)mgr;
        void(__thiscall * fn)(void*, void*, int) = *(void(__thiscall**)(void*, void*, int))(vtbl + 2);
        fn(mgr, p, 0x50);
    }

    *(int*)this = (int)&_DAT_0102e388;
    *(int*)((char*)this + 0x18) = (int)&DAT_0104e3d0;
    *(int*)((char*)this + 0x14) = (int)&$SG5957;
}

template <typename T> inline void D0A6A0_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = t;
    }
}

struct D0A6A0_Entity;

struct D0A6A0_Collidable
{
    int unk00;
};

struct D0A6A0_Entity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0A6A0_Collidable m_kCollidable;
};

struct D0A6A0_Allocator;
void FUN_00c908c0(D0A6A0_Allocator& alloc, void* arr, int numElem, int sizeElem);

struct D0A6A0_CollidableArray
{
    D0A6A0_Collidable** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(D0A6A0_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, 4);
        }
    }
    void pushBackUnchecked(D0A6A0_Collidable* c)
    {
        D0A6A0_constructWithCopy<D0A6A0_Collidable*>(m_data + m_iElementCount, 1, c);
        m_iElementCount++;
    }
};

struct D0A6A0_Allocator;

struct D0A6A0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0A6A0_Allocator* m_pStreamAllocator;

    D0A6A0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

D0A6A0_Router& FUN_00c85750();

namespace fnv_00d0adc0 {
class hkMemoryAllocatorD0A
{
  public:
    virtual ~hkMemoryAllocatorD0A() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD0A
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD0A* m_pStreamAllocator;

    hkMemoryAllocatorD0A& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD0A& __cdecl FUN_00c85750() throw();

class hkObjD0AD : public FUN_00d0a4f0
{
  public:
    hkObjD0AD* FUN_00d0adc0(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObjD0AD*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

}  // namespace fnv_00d0adc0

namespace fnv_00d9d800 {
struct BSAudioVtbl
{
    virtual void unk00();
    virtual int unk04(int size);
};

struct BSAudio
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    BSAudioVtbl* unk10;
};

BSAudio* __cdecl FUN_00c85750();

}  // namespace fnv_00d9d800

struct hkResultD0A3
{
    int m_pClassEnum;
    hkResultD0A3()
    {}
};

struct hkBase0D0A3
{
    int unk00[4];
};
struct hkBaseBD0A3
{
    int unk00;
};
struct hkBaseAD0A3
{
    int unk00;
};

class hkPhantomD0A3 : public hkBase0D0A3, public hkBaseBD0A3, public hkBaseAD0A3
{
};

struct hkInputD0A3
{
    int unk00[4];
    int m_10;
};

class hkCollectorD0A3
{
  public:
    hkCollectorD0A3(hkInputD0A3* input, hkPhantomD0A3* phantom, int filter)
    {
        m_iFilter = filter;
        m_bHasHit = 0;
        m_pRayCastInput = input;
        m_kPointA = phantom;
        m_kPointB = phantom;
    }
    virtual void AddHit(void* hit);

    hkInputD0A3* m_pRayCastInput;
    hkBaseAD0A3* m_kPointA;
    hkBaseBD0A3* m_kPointB;
    int m_iFilter;
    int m_bHasHit;
};

hkResultD0A3 __cdecl FUN_00d98ca0(void* world, hkInputD0A3* input, int* inputBody, hkCollectorD0A3* collector);

struct __declspec(align(16)) hkVector4D0A4
{
    float x, y, z, w;
};

struct hkBoolD0A4
{
    hkBoolD0A4()
    {}
    char m_cBooleanValue;
};

struct __declspec(align(16)) RayCastOutputD0A4
{
    RayCastOutputD0A4()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = -1;
        m_uiShapeKeyIndex = 0;
        m_pRootCollidable = 0;
    }
    hkVector4D0A4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1c;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;
    const void* m_pRootCollidable;
};

struct QueryFilterD0A4
{
    int m_iFilter;
};
struct CdBodyD0A4
{
    int m_kCollisionBody;
};
struct QueryOwnerD0A4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct QueryD0A4 : QueryOwnerD0A4, CdBodyD0A4, QueryFilterD0A4
{
};

struct RayInputD0A4
{
    hkVector4D0A4 m_vFrom;
    hkVector4D0A4 m_vTo;
};

class RayCollectorD0A4
{
  public:
    RayCollectorD0A4(const RayInputD0A4* pkInput, QueryD0A4* pkQuery, int iUser, RayCastOutputD0A4* pkOutput)
    {
        m_pkInput = pkInput;
        m_iUser = iUser;
        m_pkFilter = pkQuery;
        m_pkBody = pkQuery;
        m_pkOutput = pkOutput;
    }
    virtual void CollectRayHit();
    const RayInputD0A4* m_pkInput;
    QueryFilterD0A4* m_pkFilter;
    CdBodyD0A4* m_pkBody;
    RayCastOutputD0A4* m_pkOutput;
    int m_iUser;
};

hkBoolD0A4 __cdecl FUN_00d98ca0(void* pkShape, const RayInputD0A4* pkInput, const hkVector4D0A4* pkTo,
                                RayCollectorD0A4* pkCollector);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
struct D0AHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void bufDealloc(void* p, int bytes);
};
struct D0ARouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D0AHeap* m_pStreamAllocator;
};
namespace fnvc_adapt {
D0ARouter* __cdecl FUN_00c85750();
}

class hkReferencedObjectD0A
{
  public:
    hkReferencedObjectD0A() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD0A() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d0a2d0;

class hkpActionD0A : public hkReferencedObjectD0A
{
  public:
    hkpActionD0A() throw() : m_pCurrentSimulationIsland(0), m_ulUserData(0)
    {}
    virtual ~hkpActionD0A() throw();

    FUN_00d0a2d0* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
};

class hkpEntityListenerD0A
{
  public:
    virtual ~hkpEntityListenerD0A() throw();
};

class WorldD0A;

class hkpPhantomListenerD0A
{
  public:
    virtual ~hkpPhantomListenerD0A() throw();
};

class WorldHolderD0A
{
  public:
    WorldHolderD0A(WorldD0A* pkWorld) throw() : m_pkWorld(pkWorld)
    {}

    WorldD0A* m_pkWorld;
};

class WorldD0A
{
  public:
    void FUN_00c93820(hkpEntityListenerD0A* pkListener);
    void FUN_00c93860(hkpPhantomListenerD0A* pkListener);
};

class FUN_00d0a2d0 : public WorldD0A
{
};

namespace fnv_00d0a560 {
struct Iface_d0a560A
{
    virtual void slot0();
    virtual int slot1(int n);
    virtual void slot2(void* p, int n);
};

struct BSAudio
{
    Iface_d0a560A& heap()
    {
        return *unk10;
    }
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Iface_d0a560A* unk10;
};

namespace fnvc_adapt {
BSAudio* __cdecl FUN_00c85750(void);
}

struct FUN_00d9e000_Obj
{
    int unk00;
    int unk04;
    int FUN_00d9e000();
};

struct __declspec(align(16)) S00d0a560_Scratch
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct __declspec(align(16)) S00d0a560_S30
{
    int unk00;
    char unk04;
    char unk05;
    short unk06;
    int unk08;
    int unk0C;
};

struct __declspec(align(16)) S00d0a560_Frame
{
    int unk10;
    int unk14;
    volatile unsigned int tk;
    FUN_00d9e000_Obj l1c;
    FUN_00d9e000_Obj s24;
    S00d0a560_S30 s30;
    S00d0a560_Scratch s44;
    S00d0a560_Scratch s50;
};

extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

void __cdecl GetAudioPair(void* out, int n);
void __cdecl FreeBufferPair(void* out, int n);

}  // namespace fnv_00d0a560

// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void FUN_00d0ada0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d0ada0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0ada0
    virtual void FUN_00d0ada0();
};

Derived::Derived()
{}

struct ThunkPrim
{
    virtual void FUN_00d0adb0();
    int p04;
    int p08;
    int p0C;
    int p10;
    int p14;
};

struct ThunkSec
{
    virtual void FUN_00d0adb0();
};

struct ThunkOwner : ThunkPrim, ThunkSec
{
// @fnv 0x00d0adb0
    virtual void FUN_00d0adb0();
};

static ThunkOwner g_thunk;

struct __declspec(align(16)) FourFloatVector
{
    float x, y, z, w;
};

struct Allocator
{
    __forceinline Allocator* same()
    {
        return this;
    }
    virtual void ReportDiagnostic();
    virtual void* allocate(int bytes);
    virtual void freeBlock(void* block, int bytes);
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* block, int bytes);
    int* allocArray(int& bytes, int n)
    {
        return static_cast<int*>(allocateBuffer(bytes = n * 4));
    }
    void freeArray(int*& data, int& cap)
    {
        if ((cap & 0x80000000) == 0)
            freeBuffer(data, (cap & 0x3fffffff) * 4);
    }
};
struct Router
{
    int field00, field04, field08;
    Allocator* stack;
    Allocator* heap;
};
__forceinline Router* getRouter()
{
    return reinterpret_cast<Router*>(&::FUN_00c85750());
}
struct TreeInfo
{
    int count;
    unsigned char mode, enabled;
    short field06;
    int field08, field0c;
    FourFloatVector minimum, maximum;
    void FUN_00d976d0();
};
struct Tree
{
    void* nodes;
    int field04, field08, field0c;
    int* indices;
    int size, extra, root;
    int total() const
    {
        return extra + size;
    }
    void ClearBuffers();
    Tree* Init(TreeInfo*);
};
struct Scratch
{
    void* first;
    void* second;
};
void __cdecl GetAudioPair(Scratch*, int);
void __cdecl FreeBufferPair(Scratch*, int);
struct IntBuffer
{
    int* data;
    int capacity;
    void allocate(int count)
    {
        int bytes = count * 4;
        data = static_cast<int*>(getRouter()->stack->allocateBuffer(bytes));
        capacity = bytes / 4;
        if (capacity == 0)
            capacity = 0x80000000;
    }
    void release()
    {
        Allocator* allocator = getRouter()->stack;
        if (capacity >= 0)
            allocator->freeBuffer(data, (capacity & 0x3fffffff) * 4);
    }
};
__forceinline int* AllocateBufferWithSize(int& bytes, int n)
{
    return static_cast<int*>(getRouter()->stack->allocArray(bytes, n));
}
