#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpSweptTransformDisplayViewer
{
    int FindEntryIndex(int);
    void RemoveWorldData(int);
    void FUN_00d64950(int a);
};

// Calls FindEntryIndex on the viewer at this-0x20 with a; if the returned index is non-negative, calls RemoveWorldData with it.
// @fnv 0x00d64950
// pdb: hkpSweptTransformDisplayViewer::worldRemovedCallback | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void hkpSweptTransformDisplayViewer::FUN_00d64950(int a)
{
    hkpSweptTransformDisplayViewer* p = (hkpSweptTransformDisplayViewer*)((char*)this - 0x20);
    int r = p->FindEntryIndex(a);
    if (r >= 0)
        p->RemoveWorldData(r);
}

extern "C" void FUN_00d64650();
// @fnv 0x00d647f0
// pdb: hkpSweptTransformDisplayViewer::worldAddedCallback | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void __fastcall FUN_00d647f0(void* self)
{
    ((void(__thiscall*)(void*))FUN_00d64650)((char*)self - 0x20);
}

extern "C" int g_ptr_0x1268fd0;

// @fnv 0x00d64970
// pdb: BGSMoviePlayer::GetScreenHeight | BGSMoviePlayer.obj | fnv360_0822_retail, objrun, medium
int __cdecl FUN_00d64970()
{
    return g_ptr_0x1268fd0;
}

struct D63FF0Entry
{
    void* m_key;
};

struct D63FF0Container
{
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
    D63FF0Entry** m_entries;
    int m_iNumberOfEntries;

    int FindEntryIndex(void* key) const;
};

// Scans m_entries for an entry whose m_key equals key and returns its index, or -1 if none matches.
// @fnv 0x00d63ff0
// pdb: hkpSweptTransformDisplayViewer::findWorld | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, objrun, low, conflict (bridge: hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment)
// pdb params: world
int D63FF0Container::FindEntryIndex(void* key) const
{
    for (int i = 0; i < m_iNumberOfEntries; i++)
    {
        if (m_entries[i]->m_key == key)
            return i;
    }
    return -1;
}

struct SweptList
{
    int unk00;
    void** m_04;
    int m_08;
};

struct SweptArg
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
};

struct SweptVObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(void* p, int g, int z);
};

class SweptTransformItem
{
  public:
    int unk00;
    int unk04;
    SweptList** m_08;

    void FUN_00d64120(SweptArg* a1);
};

extern "C" int g_ptr_0x1268fd0;

// @f3 0x009f0b60 (community match, verified in this file)
extern int DAT_011697ec;

// pdb: hkpSweptTransformDisplayViewer::entityRemovedCallback | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: entity
void SweptTransformItem::FUN_00d64120(SweptArg* a1)
{
    if (*(int*)&a1->m_10 == 0)
    {
        return;
    }
    hkpSweptTransformDisplayViewer* viewer = (hkpSweptTransformDisplayViewer*)((char*)this - 0x28);
    int iIndex = viewer->FindEntryIndex(a1->m_08);
    if (iIndex < 0)
    {
        return;
    }
    SweptList* list = this->m_08[iIndex];
    void* key = (void*)&a1->m_11;
    SweptVObj* pVObj = *(SweptVObj**)((char*)this - 0x10);
    pVObj->v5(key, DAT_011697ec, 0);

    int i = 0;
    int iCount = list->m_08;
    if (iCount > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == key)
            {
                if (i >= 0)
                {
                    (*(volatile int*)&list->m_08)--;
                    int last = *(volatile int*)&list->m_08;
                    list->m_04[i] = list->m_04[last];
                }
                break;
            }
            ++i;
            ++p;
        } while (i < iCount);
    }

    void* key2 = (void*)&a1->m_12;
    int g2 = DAT_011697ec;
    pVObj = *(SweptVObj**)((char*)this - 0x10);
    pVObj->v5(key2, g2, 0);

    i = 0;
    iCount = list->m_08;
    if (iCount > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == key2)
            {
                if (i >= 0)
                {
                    (*(volatile int*)&list->m_08)--;
                    int last = *(volatile int*)&list->m_08;
                    list->m_04[i] = list->m_04[last];
                }
                break;
            }
            ++i;
            ++p;
        } while (i < iCount);
    }
}


struct FUN_00d647b0_Pool
{
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
    int* m_items;
    int m_uiItemCount;
};

struct FUN_00d647b0_Listener
{
    int unk00;
};

typedef void(__thiscall* FUN_00d647b0_Handler)(FUN_00d647b0_Listener* self, int item);

struct FUN_00d647b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d647b0_Pool* m_kNodePool;

    void NotifyItems();
};

// @fnv 0x00d647b0
// pdb: hkpSweptTransformDisplayViewer::init | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
void FUN_00d647b0_cls::NotifyItems()
{
    if (m_kNodePool != 0)
    {
        int i = 0;
        if (m_kNodePool->m_uiItemCount > i)
        {
            FUN_00d647b0_Listener* listener = (FUN_00d647b0_Listener*)((char*)this - 8);
            do
            {
                ((FUN_00d647b0_Handler)FUN_00d64650)(listener, m_kNodePool->m_items[i]);
                i++;
            } while (i < m_kNodePool->m_uiItemCount);
        }
    }
}

struct SweptHeap
{
    virtual ~SweptHeap();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void* AllocateBufferWithSize(int& n);
    virtual void ReturnMemory(void* p, int n);
};

struct SweptRouter
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    SweptHeap* m_pStreamAllocator;
    SweptHeap& heap()
    {
        return *m_pStreamAllocator;
    }
};

__declspec(nothrow) SweptRouter& __cdecl FUN_00c85750();

template <int SIZE> __forceinline void SweptMemCpyOne(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}

template <typename T> struct SweptArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~SweptArray() throw()
    {
        _clearAndDeallocate(FUN_00c85750().heap());
    }

    __forceinline void clear() throw()
    {
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(SweptHeap& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            SweptMemCpyOne<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct SweptEntityListener
{
    virtual void EntityAddedCallback(void* entity);
};
struct SweptPostSimListener
{
    virtual void postSimulationCallback(void* world);
};

struct SweptWorld
{
    void AddEntityListener(SweptEntityListener* listener);
    void AddPostSimulationListener(SweptPostSimListener* listener);
};

struct SweptWorldData
{
    SweptWorld* m_pOwningWorld;
    SweptArray<unsigned long> m_kEntityIDs;

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
};

struct SweptViewerBase
{
    virtual ~SweptViewerBase();
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24;
};

struct SweptViewer : SweptViewerBase, SweptEntityListener, SweptPostSimListener
{
    SweptArray<SweptWorldData*> m_kWorldDataList;

    void ClearSweptEntry(int index);
    void RemoveWorldData(int index);
};

// Unregisters this viewer from the world at index, calls ClearSweptEntry, deletes the world data and removes it from the array.
// @fnv 0x00d64800
void SweptViewer::RemoveWorldData(int index)
{
    m_kWorldDataList[index]->m_pOwningWorld->AddEntityListener(this);
    m_kWorldDataList[index]->m_pOwningWorld->AddPostSimulationListener(this);
    ClearSweptEntry(index);
    delete m_kWorldDataList[index];
    m_kWorldDataList.removeAt(index);
}

namespace fnv_00d648c0 {
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
extern int DAT_010d1918, DAT_010d18f8, DAT_010d18e8, DAT_010d18cc, DAT_010d18bc, DAT_010ccf7c;
struct AudioArray
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
    void Reset()
    {
        m_pData = 0;
        m_uCapBits = 0x80000000u;
    }
};
struct SweptViewer
{
    int m_vptr00, unk04, m_vptr08, unk0c, unk10, unk14, unk18, unk1c, m_vptr20, m_vptr24, m_vptr28, m_vptr2c;
    AudioArray m_ppData;
    void RemoveWorldData(int);
    void FUN_00ddcc60_tail();
    void Destroy();
};
}  // namespace fnv_00d648c0

#include <xmmintrin.h>
struct __declspec(align(16)) D64020Vector4
{
    float m_f[4];
};

struct __declspec(align(16)) D64020Rotation
{
    D64020Vector4 m_kColumn0;
    D64020Vector4 m_kColumn1;
    D64020Vector4 m_kColumn2;

    void set(const D64020Vector4& quat);
};

struct __declspec(align(16)) D64020Transform
{
    D64020Rotation m_rotation;
    D64020Vector4 m_vTranslation;
};

// sub ecx,8; jmp FUN_00d649c0 == MSVC adjustor thunk for the secondary base's override.
struct PrimaryBase
{
    virtual void FUN_00d64980();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d64980();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d64980
    virtual void FUN_00d64980();
};

Derived::Derived()
{}

struct S_00d649c0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d649c0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d649c0_Heap* m_pStreamAllocator;
    __forceinline S_00d649c0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct FUN_00d649c0
{
    virtual ~FUN_00d649c0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d649c0();
    static void operator delete(void* p, unsigned int)
    {
        FUN_00d649c0* b = static_cast<FUN_00d649c0*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00d649c0
FUN_00d649c0::FUN_00d649c0()
{}
