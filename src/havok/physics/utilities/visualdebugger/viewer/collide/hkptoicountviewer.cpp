#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d60b90
// pdb: hkpWorldViewerBase::getConsumableCommands | hkpWeldingViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: commands, numCommands
void __stdcall ClearTwoInts(int* piFirst, int* piSecond)
{
    *piFirst = 0;
    *piSecond = 0;
}

extern int g_D67960Value;

// @fnv 0x00d67960
// pdb: ShadowSceneLight::GetFrustumPlanes | ShadowLightShader.obj | fnv360_0822_debug, objrun_open, low
int __cdecl FUN_00d67960()
{
    return g_D67960Value;
}

struct Item;
struct Sink
{
    void FUN_00c9c670(Item*);
};
struct Link
{
    void FUN_00cb1fb0(Sink*);
};
struct Item
{
    int value;
    Link link;
    void FUN_00d67bc0(Sink*);
};
struct Prefix
{
    float x, y, z, w;
    float ax, ay, az, aw;
    float bx, by, bz, bw;
};
struct Derived : Prefix, Item
{
};
// @fnv 0x00d67bc0
void Item::FUN_00d67bc0(Sink* sink)
{
    sink->FUN_00c9c670(static_cast<Item*>(reinterpret_cast<Derived*>(reinterpret_cast<char*>(this) - sizeof(Prefix))));
    link.FUN_00cb1fb0(sink);
}

class PrimaryBase
{
  public:
    virtual void primary0();
    int flags;
};
class ProcessBase
{
  public:
    virtual void process0();
    virtual void process1();
    virtual void process2();
    virtual void process3();
    virtual void process4();
    virtual void process5();
    virtual void process6();
    int unk04, unk08, unk0C, unk10, unk14;
};
class WorldListener
{
  public:
    virtual void world0();
    virtual void world1();
    virtual void world2();
    int unk04;
};
class FUN_00ddccb0 : public PrimaryBase, public ProcessBase, public WorldListener
{
  public:
    FUN_00ddccb0(int);
};
class hkpContactListener
{
  public:
    virtual void contact0();
    virtual void contact1();
    virtual void contact2();
};
class hkpWorldPostSimulationListener
{
  public:
    virtual void post0();
    virtual void post1();
    virtual void post2();
};
class hkpEntityListener
{
  public:
    virtual void entity0();
    virtual void entity1();
    virtual void entity2();
    virtual void entity3();
    virtual void entity4();
    virtual void entity5();
};
struct CountArray
{
    int* data;
    int size;
    int capacity;
    CountArray() : data(0), size(0), capacity(-1)
    {}
    void EnsureCapacity(void*, int);
};
struct BSAudio
{
    int unk00, unk04, unk08, unk0C;
    void* allocator;
};
BSAudio* FUN_00c85750();
class FUN_00d67ce0 : public FUN_00ddccb0,
                     public hkpContactListener,
                     public hkpWorldPostSimulationListener,
                     public hkpEntityListener
{
  public:
    virtual void primary0();
    virtual void primary1();
    virtual void primary2();
    virtual void process0();
    virtual void process1();
    virtual void process2();
    virtual void process3();
    virtual void process4();
    virtual void process5();
    virtual void process6();
    virtual void world0();
    virtual void world1();
    virtual void world2();
    virtual void contact0();
    virtual void contact1();
    virtual void contact2();
    virtual void post0();
    virtual void post1();
    virtual void post2();
    virtual void entity0();
    virtual void entity1();
    virtual void entity2();
    virtual void entity3();
    virtual void entity4();
    virtual void entity5();
    CountArray counts;
    FUN_00d67ce0(int context);
};

// Constructs the object via FUN_00ddccb0 and initializes counts from the allocator returned by FUN_00c85750.
// @fnv 0x00d67ce0
FUN_00d67ce0::FUN_00d67ce0(int context) : FUN_00ddccb0(context)
{
    BSAudio* audio = FUN_00c85750();
    counts.EnsureCapacity(audio->allocator, 0);
}

namespace fnv_00d67d60 {
struct Heap
{
    virtual void* unused();
    virtual void* Allocate(unsigned int);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Heap* heap10;
};
extern void* FUN_00c85750();
struct hkpToiCountViewer
{
    void* vtable;
    unsigned short size;
    unsigned short unk06;
    hkpToiCountViewer* __thiscall FUN_00d67ce0(unsigned int);
};
// Allocates a 0x40-byte hkpToiCountViewer from the global heap, initializes it with arg, and returns a pointer 8 bytes into it or null.
// @fnv 0x00d67d60
void* __cdecl AllocateToiCountViewer(unsigned int arg)
{
    Global* global = (Global*)FUN_00c85750();
    hkpToiCountViewer* pViewer = (hkpToiCountViewer*)global->heap10->Allocate(0x40);
    pViewer->size = 0x40;
    pViewer = pViewer->FUN_00d67ce0(arg);
    if (pViewer)
        return (char*)pViewer + 8;
    return 0;
}
}  // namespace fnv_00d67d60

void* AllocateToiCountViewer();

struct S_00d67e10_Registry
{
    int Register(const char* name, void* (*create)());
};

extern S_00d67e10_Registry* g_00d67e10_registry;
extern int g_00d67e10_toiCounterId;

// @fnv 0x00d67e10
// pdb: hkpActiveContactPointViewer::registerViewer | hkpActiveContactPointViewer.obj | fnv360_0822_debug, udata, high
// pdb: hkpActiveContactPointViewer::registerViewer | hkpActiveContactPointViewer.obj | fnv360_0822_debug, udata, high (was: RegisterToiCounter)
void hkpActiveContactPointViewer_registerViewer()
{
    g_00d67e10_toiCounterId = g_00d67e10_registry->Register("TOI counter", AllocateToiCountViewer);
}

struct BSAudio;
__declspec(nothrow) BSAudio* FUN_00c85750();

struct AudioHeap
{
    char pad[0x10];
    void* heap;
};

struct Iface1
{
    virtual void i1();
    ~Iface1()
    {}
};
struct Iface2
{
    virtual void i2();
    ~Iface2()
    {}
};
struct Iface3
{
    virtual void i3();
    ~Iface3()
    {}
};

struct MemberBase
{
    __declspec(nothrow) ~MemberBase();
    int m[4];
};
struct Member : MemberBase
{
    __declspec(nothrow) void Release(void* heap);
    ~Member()
    {
        Release(((AudioHeap*)FUN_00c85750())->heap);
    }
};

struct ListItem;

struct ItemVisitor
{
    virtual void v0();
    virtual void v1(void* item);
};

struct ItemNode
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34,
        unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68;
    ListItem** m_items;  // +0x6c
    int m_uiItemCount;   // +0x70
};

struct FUN_00d67bf0_cls
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    ItemVisitor m_visitor;        // +0x18
    ItemNode* m_pReferencedNode;  // +0x1c

    void VisitItems();
};

// Iterates the node's items up to its count, passing each to m_visitor.v1, stopping early if the node becomes null.
// @fnv 0x00d67bf0
// pdb: hkpToiContactPointViewer::init | hkpToiContactPointViewer.obj | fnv360_0822_retail, vtable, medium
void FUN_00d67bf0_cls::VisitItems()
{
    int i = 0;
    ItemNode* node = m_pReferencedNode;
    if (node != 0)
    {
        do
        {
            if (i >= node->m_uiItemCount)
                break;
            ListItem* item = node->m_items[i];
            m_visitor.v1(item);
            node = m_pReferencedNode;
            ++i;
        } while (node != 0);
    }
}

struct SpawnedObject;

struct Entry
{
    SpawnedObject* obj;
    unsigned int unk04;
};

struct SpawnedObject
{
    unsigned int unk00;
    unsigned int unk04;
    SpawnedObject* m_08;
    void FUN_00c9c670(void* listener) throw();
    void FUN_00c91a20(void* listener) throw();
    void ClearValue(void* listener) throw();
};

struct Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Grow(SpawnedObject** out, unsigned int size);
};

struct BSAudio;
BSAudio* FUN_00c85750() throw();

void __cdecl ResizeAudioStream(void* a, void* arr, unsigned int size) throw();

struct Map
{
    Entry* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_hashModMask;

    int GetFirstIterator() const
    {
        int i = 0;
        for (; i <= m_hashModMask; ++i)
        {
            if (m_kPrimitiveElement[i].obj != (SpawnedObject*)-1)
                break;
        }
        return i;
    }

    int getNext(int it) const
    {
        int i = it + 1;
        for (; i <= m_hashModMask; ++i)
        {
            if (m_kPrimitiveElement[i].obj != (SpawnedObject*)-1)
                break;
        }
        return i;
    }

    bool isValid(int it) const
    {
        return it <= m_hashModMask;
    }

    void FUN_00cb1fb0(SpawnedObject* o) throw();
};

struct Array
{
    SpawnedObject** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void clear()
    {
        BSAudio* h = FUN_00c85750();
        Alloc* al = (Alloc*)h->allocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            al->Grow(m_data, (cap & 0x3fffffff) * 4);
        }
    }
};

class FUN_00d67e30_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    Map m_14;

    void RemoveEntriesForObject(SpawnedObject* a1);
};

// @fnv 0x00d67e30
void FUN_00d67e30_cls::RemoveEntriesForObject(SpawnedObject* a1)
{
    Array out;
    out.m_data = 0;
    out.m_iElementCount = 0;
    out.m_iCapacityState = 0x80000000;

    for (int it = m_14.GetFirstIterator(); m_14.isValid(it); it = m_14.getNext(it))
    {
        SpawnedObject* obj = m_14.m_kPrimitiveElement[it].obj;
        if (obj->m_08 == a1)
        {
            BSAudio* h = FUN_00c85750();
            if (out.m_iElementCount == (int)(out.m_iCapacityState & 0x3fffffffu))
            {
                ResizeAudioStream(h->allocator, &out, 4);
            }
            out.m_data[out.m_iElementCount] = obj;
            out.m_iElementCount++;
        }
    }

    int size = out.m_iElementCount;
    for (int iMatch = 0; iMatch < size; iMatch++)
    {
        SpawnedObject** it = &out.m_data[iMatch];
        (*it)->FUN_00c9c670((char*)this - 0x20 != 0 ? (void*)((char*)this + 0x10) : 0);
        m_14.FUN_00cb1fb0(*it);
    }

    out.clear();

    a1->FUN_00c91a20((char*)this - 0x20 != 0 ? (void*)((char*)this + 8) : 0);
    a1->ClearValue((char*)this - 0x20 != 0 ? (void*)((char*)this + 0xc) : 0);
}

#include <xmmintrin.h>

__declspec(align(16)) struct SquaredLanes
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

struct PtrMapEntryObj
{
    void FUN_00c9c670(void* arg);
};

struct PtrMapEntry
{
    PtrMapEntryObj* m_pKey;
    int m_iValue;
};

struct PtrMapStorage
{
    PtrMapEntry* m_pEntries;
    int unk04;
    int m_iArrayLength;

    void clear();
};

struct FUN_00d67da0_cls
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
    int m_i30;
    PtrMapStorage m_kStorage;

    void FUN_00d67da0(void*);
};

// Walks m_kStorage entries with a key other than -1, calls FUN_00c9c670 on each key with the address of m_i30, then calls m_kStorage.clear().
// @f3 0x009b03a0 (community match, verified in this file)
namespace f3m_009b03a0 {
struct MapBool {
    char value;
    MapBool(bool b) { value = (char)b; }
    operator bool() const { return value != 0; }
};

// Open-addressed pointer map: keys in slots 0..hashMod, values in the block after them; an empty slot is -1.
struct PointerMap {
    unsigned long* elem;
    int numElems;
    int hashMod;

    void FUN_00922710(unsigned long key, unsigned long value);

    int First() const
    {
        int i;
        for (i = 0; i <= hashMod; ++i) {
            if (elem[i] != (unsigned long)-1)
                break;
        }
        return i;
    }
    int Next(int i) const
    {
        for (i += 1; i <= hashMod; ++i) {
            if (elem[i] != (unsigned long)-1)
                break;
        }
        return i;
    }
    MapBool IsValid(int i) const { return i <= hashMod; }
    unsigned long Key(int i) const { return elem[i]; }
    unsigned long Value(int i) const { return elem[i + hashMod + 1]; }
};

struct Registry {
    void* vtable;
    unsigned short memSize;
    short refCount;
    PointerMap map;
};
}

// pdb: hkVtableClassRegistry::merge | hkVtableClassRegistry.obj | fnv360_0822_retail, caller_sim, low
// pdb params: mergeFrom
void FUN_00d67da0_cls::FUN_00d67da0(void* other)
{
    f3m_009b03a0::Registry* self = (f3m_009b03a0::Registry*)this;
    const f3m_009b03a0::Registry& from = *(const f3m_009b03a0::Registry*)other;
    int it = from.map.First();
    while (from.map.IsValid(it)) {
        self->map.FUN_00922710(from.map.Key(it), from.map.Value(it));
        it = from.map.Next(it);
    }
}


struct AudioAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* ptr, unsigned int count);
};

struct AudioCoreView
{
    int unk00;
    int unk04;
    int unk08;
    AudioAllocator* m_pThreadAllocator;
};

struct BSAudioString
{
    char* m_data;
    int m_fRestLength;
    int m_pRayCursor;
    int buffer00, buffer04, buffer08, buffer0c;
    int buffer10, buffer14, buffer18, buffer1c;
    int buffer20, buffer24, buffer28, buffer2c;
    int buffer30, buffer34, buffer38, buffer3c;
    int buffer40, buffer44, buffer48, buffer4c;
    int buffer50, buffer54, buffer58, buffer5c;
    int buffer60, buffer64, buffer68, buffer6c;
    int buffer70, buffer74, buffer78, buffer7c;

    BSAudioString();
    void Format(const char* format, ...);

    void Release()
    {
        AudioAllocator* allocator = ((AudioCoreView*)FUN_00c85750())->m_pThreadAllocator;
        m_fRestLength = 0;
        if ((m_pRayCursor & 0x80000000) == 0)
            allocator->Free(m_data, m_pRayCursor & 0x3fffffff);
    }
};

struct BSAudioValue
{
    unsigned char m_flags;
    BSAudioValue() : m_flags(1)
    {}
    BSAudioValue(const BSAudioValue& other) : m_flags(other.m_flags)
    {}
};

// FUN_00d68200: thiscall adjustor thunk (sub ecx,0x28; jmp FUN_00d68230).
// Written as multiple inheritance: the primary base is 0x28 bytes (vptr + 9 ints),
// so the secondary base sits at +0x28 and MSVC emits the this-adjusting thunk.
struct AdjPrimaryBase
{
    virtual void FUN_00d68200();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct AdjSecondaryBase
{
    virtual void FUN_00d68200();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d68200
    virtual void FUN_00d68200();
};

AdjDerived::AdjDerived()
{}

namespace fnv_00d68230 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct FUN_00d68230
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00d68230();
    virtual ~FUN_00d68230();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        unsigned int uiSize = ((FUN_00d68230*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Constructs the object, zeroing m_u04 and m_u06.
// @fnv 0x00d68230
FUN_00d68230::FUN_00d68230()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00d68230

namespace fnv_00d67c30 {
struct Holder;

extern "C" Holder* __cdecl FUN_00c85750();

struct Entry
{
    int unk00;
    unsigned int m_flags;
};

struct Item
{
    void Apply(int aValue);
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
};

}  // namespace fnv_00d67c30
