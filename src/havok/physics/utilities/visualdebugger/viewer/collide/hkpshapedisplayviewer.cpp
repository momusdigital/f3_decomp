#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d65970_stub
{
    void FUN_00d65970(int);
};
struct FUN_00d65f70_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00d65f70();
};
// If m_1c is set, iterates its count at offset 0x70 and calls FUN_00d65970 on each entry from the array at 0x6c.
// @fnv 0x00d65f70
// pdb: hkpShapeDisplayViewer::init | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
void FUN_00d65f70_class::FUN_00d65f70()
{
    if (m_1c)
    {
        for (int i = 0; i < *(int*)(m_1c + 0x70); ++i)
            ((FUN_00d65970_stub*)((char*)this - 8))->FUN_00d65970(*(*(int**)(m_1c + 0x6c) + i));
    }
}

struct S_00c6d840_Pair
{
    int m_kPointA;
    int m_kPointB;
    S_00c6d840_Pair(int a, int b) : m_kPointA(a), m_kPointB(b)
    {}
};

struct S_00c6d840_Entry
{
    int m_key;
    int unk04;
    S_00c6d840_Pair m_uiFilterValue;
};

struct S_00c6d840
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
    int unk6C;
    int unk70;
    S_00c6d840_Entry* m_entries;
    int m_uiItemCount;
    S_00c6d840_Pair FindEntry(int key);
    S_00c6d840_Pair FindEntry(int key, int unused);
};

// @f3 0x00477900 (community match, verified in this file)
// pdb: bhkWorldObject::GetProperty | bhkWorldObject.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSPointerHandleManagerInterface<class Projectile,class HandleManager>::GetHandle)
// pdb params: apObj, aiKey
S_00c6d840_Pair S_00c6d840::FindEntry(int key)
{
    for (int i = 0; i < m_uiItemCount; i++)
    {
        if (m_entries[i].m_key == key)
        {
            return m_entries[i].m_uiFilterValue;
        }
    }
    return S_00c6d840_Pair(0, 0);
}


struct FUN_00cb1a60_t
{
    void ResetEntries();
};

struct FUN_00d653e0_cls
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
    FUN_00cb1a60_t sub54;
    void FUN_00d653e0();
};

// @fnv 0x00d653e0
// pdb: hkpShapeDisplayViewer::clearCache | hkpShapeDisplayViewer.obj | fnv360_0822_retail, objrun_sim, low
void FUN_00d653e0_cls::FUN_00d653e0()
{
    sub54.ResetEntries();
}

struct FUN_00d655e0_Item
{
    int key;
};
struct FUN_00d655e0_class
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
    FUN_00d655e0_Item** items30;
    int count34;
    int FindItemIndex(int key);
};
// Scans the items array for an entry whose key equals key and returns its index, or -1 if none matches.
// @fnv 0x00d655e0
// pdb: hkpShapeDisplayViewer::findWorld | hkpShapeDisplayViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: world
int FUN_00d655e0_class::FindItemIndex(int key)
{
    for (int i = 0; i < count34; ++i)
        if (items30[i]->key == key)
            return i;
    return -1;
}

struct Allocator
{
    virtual void reserved();
    virtual void* allocate(unsigned int);
};
struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FUN_00d657d0_class
{
    FUN_00d657d0_class* FUN_00d657d0(int);
};
// Allocates a 0x74-byte object from the audio allocator, initializes it with context, and returns a pointer 8 bytes into it, or null on failure.
// @fnv 0x00d65910
void* __cdecl FUN_00d65910(void* context)
{
    BSAudio* audio = (BSAudio*)FUN_00c85750();
    FUN_00d657d0_class* result = (FUN_00d657d0_class*)audio->allocator->allocate(0x74);
    *(unsigned short*)((char*)result + 4) = 0x74;
    result = result->FUN_00d657d0((int)context);
    if (result)
        return (char*)result + 8;
    return 0;
}

struct FUN_00dd9380_class
{
    void* FUN_00dd9380(const char*, void*);
};
struct hkProcessFactory : FUN_00dd9380_class
{
};
struct GlobalObjectO2_00d472a0
{
};
extern hkProcessFactory* FUN_00dd9380;
extern GlobalObjectO2_00d472a0 g_01268f2c;
extern void* __cdecl FUN_00d65910(void*);

// @fnv 0x00d65950
// pdb: hkpMousePickingViewer::registerViewer | hkpMousePickingViewer.obj | fnv360_0822_debug, udata, high
// pdb: hkpMousePickingViewer::registerViewer | hkpMousePickingViewer.obj | fnv360_0822_debug, udata, high (was: RegisterShapesProcess)
void hkpMousePickingViewer_registerViewer()
{
    void* process = FUN_00dd9380->FUN_00dd9380("Shapes", (void*)&FUN_00d65910);
    *(void**)((char*)&g_01268f2c + 0xB4) = process;
}

struct Target
{
    void FUN_00d65970();
};
struct Adjustor
{
    void FUN_00d65fb0();
};
// @fnv 0x00d65fb0
// pdb: hkpShapeDisplayViewer::worldAddedCallback | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void Adjustor::FUN_00d65fb0()
{
    ((Target*)((char*)this - 0x20))->FUN_00d65970();
}

extern int g_D661D0Value;

// @fnv 0x00d661d0
// pdb: NiGeometryData::GetGroup | NiGeometryData.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: NiDX92DBufferData::IsTriShape)
int __cdecl FUN_00d661d0()
{
    return g_D661D0Value;
}

struct FUN_00d652a0_cls
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10(int a, int b) = 0;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void FUN_00d652a0(int arg);
};

// @fnv 0x00d652a0
// pdb: hkpShapeDisplayViewer::synchronizeTransforms | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void FUN_00d652a0_cls::FUN_00d652a0(int arg)
{
    v10(m_18, arg);
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize) throw();
};

struct BSAudio;

struct OwnerObject
{
    int FindItemIndex(int);
    void FUN_00d65fc0(int);
};

struct FUN_00d66160_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00d66160(int arg);
};

// Calls FindItemIndex on the owner object at this-0x20 and, if the result is non-negative, passes it to FUN_00d65fc0.
// @fnv 0x00d66160
// pdb: hkpShapeDisplayViewer::worldRemovedCallback | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void FUN_00d66160_cls::FUN_00d66160(int arg)
{
    OwnerObject* pOwner = (OwnerObject*)((char*)this - 0x20);
    int result = pOwner->FindItemIndex(arg);
    if (result >= 0)
    {
        pOwner->FUN_00d65fc0(result);
    }
}

struct D66180PropertyValue
{
    void* m_ptr;
    int m_extra;

    D66180PropertyValue()
    {}
};

struct D66180Property
{
    unsigned int m_key;
    int m_uiAlignmentPadding;
    int m_value0;
    int m_value1;
};

struct D66180Entity
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
    int unk6C;
    int unk70;
    int unk74;
    D66180Property* m_kProperties;
    int m_iPropertyCount;

    D66180PropertyValue getProperty(unsigned int key, void* lockCheck = 0) const;
};

// Scans the entity's property array for key 0x1134 and returns that property's pointer, or a pointer to unk10 if not found.
// @f3 0x009f3010 (community match, verified in this file)
struct FUN_00477900_stub
{
    D66180PropertyValue FUN_00477900(unsigned int key);
};

// pdb: hkpShapeDisplayViewer::getId | hkpShapeDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: entity
void* __cdecl GetProperty1134(D66180Entity* entity)
{
    int count = *(int*)((char*)entity + 0x78);
    int i = 0;
    if (count > 0)
    {
        D66180Property* p = *(D66180Property**)((char*)entity + 0x74);
        do
        {
            if (p->m_key == 0x1134)
                return ((FUN_00477900_stub*)entity)->FUN_00477900(0x1134).m_ptr;
            i++;
            p++;
        } while (i < count);
    }
    return &entity->unk10;
}


struct SpawnAlloc
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAlloc* m_pAllocator;
};

struct SpawnSub
{
    virtual void v00();
    virtual void v04(void* p);
};

struct SpawnList
{
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct SpawnOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* m_20;
    int unk24;
    char** m_28;
    int m_2c;
    int unk30;
    char** m_34;
    int m_38;

    void FUN_00c93820(void* p);
    void FUN_00c93920(void* p);
};

struct SpawnSublist
{
    void** m_data;
    int m_uiItemCount;
};

void __cdecl ResizeAudioStream(void* allocator, void* list, unsigned int elemSize);

struct PendingNode
{
    SpawnOwner* m_pSharedOwner;
    int m_04;
    int m_08;
    unsigned int m_0c;

    PendingNode()
    {
        m_04 = 0;
        m_08 = 0;
        m_0c = 0x80000000u;
    }
    void* operator new(unsigned int size) throw()
    {
        AllocHolder* holder = (AllocHolder*)FUN_00c85750();
        SpawnAlloc* alloc = holder->m_pAllocator;
        return alloc->Alloc(size);
    }
};

template <class T> inline void hkArrayConstruct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

struct FUN_00d64650_cls
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
    SpawnSub m_28;
    int m_2c;
    SpawnList m_30;

    void FUN_00d64650(SpawnOwner* a1);
};

// @f3 0x009f1190 (community match, verified in this file)
extern "C" void* DAT_010f3170;
extern "C" void* (__stdcall* DAT_00d9b080)(void*);
struct PoolD64650 { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44; void* free48; int count4c; void* FUN_008f6800(int sizeClass, int type); };
inline void* operator new(unsigned int, PoolD64650* pool) throw()
{
    void* r = pool->free48;
    if (r) { --pool->count4c; pool->free48 = *(void**)r; return r; }
    return pool->FUN_008f6800(2, 0x35);
}
struct SpawnOwnerD64650 { void FUN_00903ae0(void*); void FUN_00903be0(void*); };
extern "C" void __cdecl FUN_00901f10(SpawnList*, int);
// pdb: hkpSweptTransformDisplayViewer::addWorld | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void FUN_00d64650_cls::FUN_00d64650(SpawnOwner* owner)
{
    ((SpawnOwnerD64650*)owner)->FUN_00903ae0(this ? (char*)this + 0x28 : 0);
    ((SpawnOwnerD64650*)owner)->FUN_00903be0(this ? (char*)this + 0x2c : 0);
    PoolD64650* pool = (PoolD64650*)DAT_00d9b080(DAT_010f3170);
    PendingNode* node = ::new (pool) PendingNode();
    node->m_pSharedOwner = owner;
    SpawnList* list = &m_30;
    if (list->m_uiItemCount == (list->m_capBits & 0x3fffffff))
        FUN_00901f10(list, 4);
    list->m_data[list->m_uiItemCount++] = node;
    for (int i = 0; i < owner->m_2c; ++i)
    {
        SpawnSublist* sub = (SpawnSublist*)((char*)owner->m_28[i] + 0x48);
        for (int j = 0; j < sub->m_uiItemCount; ++j)
            m_28.v04(sub->m_data[j]);
    }
    for (int i = 0; i < owner->m_38; ++i)
    {
        SpawnSublist* sub = (SpawnSublist*)((char*)owner->m_34[i] + 0x48);
        for (int j = 0; j < sub->m_uiItemCount; ++j)
            m_28.v04(sub->m_data[j]);
    }
    SpawnSublist* sub = (SpawnSublist*)((char*)owner->m_20 + 0x48);
    for (int j = 0; j < sub->m_uiItemCount; ++j)
        m_28.v04(sub->m_data[j]);
}


extern int DAT_01268fe0;
struct D65610Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* a, void* b, int c);
};
struct D65610Prim
{
    virtual void p00();
    D65610Obj* m_pEntryObject;
    int unk08, unk0c, unk10, unk14;
};
struct D65610Sec
{
    virtual void FUN_00d65610(D66180Entity* e);
};
struct D65610Self : D65610Prim, D65610Sec
{
    void FUN_00d65610(D66180Entity* e);
};

// Calls v10 on the stored object with the entity's offset 0xf0 pointer, the result of GetProperty1134(e), and DAT_01268fe0.
// @f3 0x009f2580 (community match, verified in this file)
extern int DAT_01269cd8;
// pdb: hkpShapeDisplayViewer::inactiveEntityMovedCallback | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: entity
void D65610Self::FUN_00d65610(D66180Entity* pEntity)
{
    D65610Obj* obj = m_pEntryObject;
    char* p = (char*)pEntity;
    obj->v10(p + 0xe0, GetProperty1134(pEntity), DAT_01269cd8);
}


struct ShapeList
{
    struct ShapeItem** data;
    int count;
};

struct ShapeItem
{
    virtual void v00()
    {}
    virtual void* GetDesc()
    {
        return 0;
    }
};

struct ShapeSub
{
    int m_00;
    int m_04;
    int m_08;
    void EnsureCapacity(int value, int zero);
};

extern char DAT_0102f13c[];
extern char DAT_010ccf7c[];
extern char DAT_010d1b04[];
extern char DAT_010d1ae4[];
extern char DAT_010d1ad4[];
extern char DAT_010d1ab8[];
extern char DAT_010d1aa8[];
extern int DAT_01268fe8;
extern int DAT_01268fe4;

void* __cdecl FUN_00c85750();
int __cdecl FUN_00cb0fa0(const char* name, void* obj);

struct FUN_00d657d0_cls
{
    void* m_vptr00;
    int unk04;
    void* m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_vptr20;
    int unk24;
    void* m_vptr28;
    void* m_vptr2c;
    int m_30;
    int m_34;
    unsigned int m_38;
    ShapeSub m_3c;
    ShapeSub m_48;
    ShapeSub m_54;
    unsigned char m_60;
    unsigned char m_61;
    unsigned char m_62;
    unsigned char m_63;
    unsigned char m_64;
    unsigned char m_65;
    unsigned char m_66;
    float m_68;
    int m_6c;
    int m_70;

    void FUN_00ddccb0(ShapeList* a1);
    FUN_00d657d0_cls* FUN_00d657d0(ShapeList* a1);
};

// Initializes vtables, ShapeSub members, and flags, then searches a1 for a ShapeDisplayViewerOptions item to set m_60.
// @fnv 0x00d657d0
FUN_00d657d0_cls* FUN_00d657d0_cls::FUN_00d657d0(ShapeList* apShapes)
{
    int i;
    FUN_00ddccb0(apShapes);
    *(void* volatile*)&m_vptr28 = (void*)DAT_0102f13c;
    *(void* volatile*)&m_vptr2c = (void*)DAT_010ccf7c;
    m_vptr00 = (void*)DAT_010d1b04;
    m_vptr08 = (void*)DAT_010d1ae4;
    m_vptr20 = (void*)DAT_010d1ad4;
    *(void* volatile*)&m_vptr28 = (void*)DAT_010d1ab8;
    *(void* volatile*)&m_vptr2c = (void*)DAT_010d1aa8;
    *(int volatile*)&m_30 = 0;
    *(int volatile*)&m_34 = 0;
    m_38 = 0x80000000;
    ShapeSub* pShapeSub1 = &m_3c;
    pShapeSub1->m_00 = 0;
    pShapeSub1->m_04 = 0;
    pShapeSub1->m_08 = -1;
    {
        void* h1 = FUN_00c85750();
        int val1 = ((int*)h1)[4];
        pShapeSub1->EnsureCapacity(val1, 0);
    }
    ShapeSub* pShapeSub2 = &m_48;
    pShapeSub2->m_00 = 0;
    pShapeSub2->m_04 = 0;
    pShapeSub2->m_08 = -1;
    {
        void* h2 = FUN_00c85750();
        int val2 = ((int*)h2)[4];
        pShapeSub2->EnsureCapacity(val2, 0);
    }
    ShapeSub* pShapeSub3 = &m_54;
    pShapeSub3->m_00 = 0;
    pShapeSub3->m_04 = 0;
    pShapeSub3->m_08 = -1;
    {
        void* h3 = FUN_00c85750();
        int val3 = ((int*)h3)[4];
        pShapeSub3->EnsureCapacity(val3, 0);
    }

    FUN_00d657d0_cls* __restrict self = this;
    *(unsigned char volatile*)&self->m_60 = 1;
    *(unsigned char volatile*)&self->m_61 = 0;
    *(unsigned char volatile*)&self->m_62 = 0;
    *(unsigned char volatile*)&self->m_63 = 1;
    *(unsigned char volatile*)&self->m_64 = 1;
    *(unsigned char volatile*)&self->m_65 = 1;
    *(unsigned char volatile*)&self->m_66 = 0;
    *(float volatile*)&self->m_68 = -1.0f;
    *(int volatile*)&self->m_6c = DAT_01268fe8;
    m_70 = DAT_01268fe4;
    int count = apShapes->count;
    for (i = 0; i < count; ++i)
    {
        ShapeItem* item = apShapes->data[i];
        void* desc = item->GetDesc();
        if (FUN_00cb0fa0("ShapeDisplayViewerOptions", desc) == 0)
            goto found;
    }
    return this;
found: {
    char* o = (char*)apShapes->data[i];
    m_60 = ((o != 0) ? o - 8 : (char*)0)[0x58];
}
    return this;
}

struct Mem_d65f
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
    virtual void deallocateChunk(void* p, int nbytes) throw();
    virtual void v0C();
    virtual void deallocate(void* p, int nbytes) throw();
};

struct Holder_d65f
{
    int unk00, unk04, unk08, unk0C;
    Mem_d65f* m_pMemoryAllocator;
    Mem_d65f& heap()
    {
        return *m_pMemoryAllocator;
    }
};

struct Router_d65f
{
    static Holder_d65f& __cdecl FUN_00c85750() throw();
};
inline Mem_d65f& getMemory_d65f()
{
    return *Router_d65f::FUN_00c85750().m_pMemoryAllocator;
}

inline void memCpy4_d65f(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d65f
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~hkArray_d65f() throw()
    {
        Mem_d65f& mem = Router_d65f::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            mem.deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d65f(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Listener_d65f;
struct Watch2_d65f
{
    virtual void w00();
};

struct Agent_d65f
{
    void FUN_00c917a0(Listener_d65f* listener);
    void ClearValue(Watch2_d65f* watch);
};

struct Node_d65f
{
    Agent_d65f* m_pCollisionAgent;
    hkArray_d65f<int> m_items;
    static void operator delete(void* p) throw()
    {
        Router_d65f::FUN_00c85750().heap().deallocateChunk(p, sizeof(Node_d65f));
    }
};

struct Base_d65f
{
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
};

struct Listener_d65f
{
    virtual void l00();
};

struct Phantom_d65f : Base_d65f, Listener_d65f, Watch2_d65f
{
    hkArray_d65f<Node_d65f*> m_kNodeCollection;
    void FUN_00d65750(int index);
    void FUN_00d65fc0(int index);
};

// Calls FUN_00c917a0 and ClearValue on the node's collision agent with this, calls FUN_00d65750, then deletes the node and removes it from m_kNodeCollection.
// @fnv 0x00d65fc0
void Phantom_d65f::FUN_00d65fc0(int index)
{
    m_kNodeCollection[index]->m_pCollisionAgent->FUN_00c917a0(this);
    m_kNodeCollection[index]->m_pCollisionAgent->ClearValue(this);
    FUN_00d65750(index);
    delete m_kNodeCollection[index];
    m_kNodeCollection.removeAt(index);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
struct TtShapeDisplayBase : FUN_00d652a0_cls
{
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
};

struct TtShapeDisplayOuter;

struct TtTlsRecord
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int m_spare;
};

struct TtTlsData
{
    int unk00;
    TtTlsRecord* m_cur;
    int unk08;
    TtTlsRecord* m_kRayEnd;
};

extern unsigned int g_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct TtShapeDisplayInner
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
    bool m_flag34;

    TtShapeDisplayOuter* GetOuter();
    void FUN_00d65520(int arg);
};

struct TtShapeDisplayOuter : TtShapeDisplayBase, TtShapeDisplayInner
{
};

__forceinline TtShapeDisplayOuter* TtShapeDisplayInner::GetOuter()
{
    return (TtShapeDisplayOuter*)((char*)this - 0x2c);
}

static void __forceinline TtPushEvent(const char* name)
{
    TtTlsData* data = (TtTlsData*)TlsGetValue(g_0126835c);
    TtTlsRecord* rec = data->m_cur;
    if (rec < data->m_kRayEnd)
    {
        rec->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        rec->m_uiCommandId = t;
        data->m_cur = rec + 1;
    }
}

// Pushes a TthkpShapeDisplayViewer event, returns early if m_flag34 is false, otherwise calls GetOuter()->v10 with m_18 and arg, then pushes an Et event.
// @fnv 0x00d65520
// pdb: hkpShapeDisplayViewer::postSimulationCallback | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void TtShapeDisplayInner::FUN_00d65520(int arg)
{
    TtPushEvent("TthkpShapeDisplayViewer");
    if (!m_flag34)
    {
        TtPushEvent("Et");
        return;
    }
    GetOuter()->v10(GetOuter()->m_18, arg);
    TtPushEvent("Et");
}

// sub ecx,8; jmp FUN_00d661f0: adjustor thunk from multiple inheritance.
struct PrimaryBase
{
    virtual void FUN_00d661f0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d661f0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d661f0
    virtual void FUN_00d661f0();
};

Derived::Derived()
{}

namespace fnv_00d66210 {
// sub ecx,0x2c; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by sizeof(PrimaryBase) = 0x2c.
struct PrimaryBase
{
    virtual void FUN_00d66210();
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
};

struct SecondaryBase
{
    virtual void FUN_00d66210();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66210
    virtual void FUN_00d66210();
};

Derived::Derived()
{}
}  // namespace fnv_00d66210

namespace fnv_00d66220 {
struct S_00d66220_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00d66220_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d66220_Allocator* unk10;
    S_00d66220_Allocator* heap()
    {
        return unk10;
    }
};
S_00d66220_Router* FUN_00c85750();

struct S_00d66220_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~S_00d66220_RefObject();
    static void operator delete(void* p, unsigned int)
    {
        S_00d66220_RefObject* o = static_cast<S_00d66220_RefObject*>(p);
        FUN_00c85750()->heap()->ReleaseBlock(p, o->m_usMemSizeAndFlags);
    }
};

}  // namespace fnv_00d66220

struct OutVec
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
};

struct Visitor
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(OutVec* out, const void* item, int g);
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
};

struct S8
{
    unsigned __int64 value;
    void* getPtr() const
    {
        return (void*)(unsigned int)value;
    }
};

struct Entry16
{
    int m_type;
    int unk04;
    void* m_p8;
    int m_iThirdValue;
};

struct SubObj
{
    void SweepTransform(float f, OutVec* out);
};

struct Item
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
    int unk6C;
    int unk70;
    int unk74;
    Entry16* m_entries;
    int m_entryCount;
    bool hasProperty(int key) const
    {
        for (int i = 0; i < m_entryCount; ++i)
        {
            if (m_entries[i].m_type == key)
                return true;
        }
        return false;
    }
    S8 getProperty(int key) const
    {
        int n = m_entryCount;
        for (int i = 0; i < n; ++i)
        {
            if (m_entries[i].m_type == key)
            {
                return *(const S8*)&m_entries[i].m_p8;
            }
        }
        S8 s = {0};
        return s;
    }
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
    SubObj m_e0;
};

struct ItemList
{
    Item** m_items;
    int m_uiItemCount;
};

struct Group
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
    ItemList m_kNode;
};

struct Node
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
    Group** m_28;
    int m_2c;
    float FUN_00c91020();
};

class S00d653f0_Obj
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
    float m_68;
    void FUN_00d653f0(Visitor* a1, Node* a2);
};

// Calls a1->v04 with each item's SweepTransform result and property pointer, using m_68 (or a2->FUN_00c91020() if m_68 is not positive), between v18 and v19.
// @f3 0x009f2350 (community match, verified in this file)
// The pack's Item carries three more dwords than this image's item, and the
// float->vec sweep sub-object sits at 0xd0 here. ItemFix restates the image layout.
struct CpuObject
{
    float FUN_00c91020();
};

struct ItemFix
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    Entry16* m_entries;
    int m_entryCount;
    int unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    SubObj m_e0;
    bool hasProperty(int key) const
    {
        for (int i = 0; i < m_entryCount; ++i)
        {
            if (m_entries[i].m_type == key)
                return true;
        }
        return false;
    }
    S8 getProperty(int key) const
    {
        int n = m_entryCount;
        for (int i = 0; i < n; ++i)
        {
            if (m_entries[i].m_type == key)
                return *(const S8*)&m_entries[i].m_p8;
        }
        S8 s = {0};
        return s;
    }
};

// pdb: hkpShapeDisplayViewer::synchronizeTransforms | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: displayHandler, world
void S00d653f0_Obj::FUN_00d653f0(Visitor* apVisitor, Node* apNode)
{
    float f = (m_68 > 0.0f) ? m_68 : ((CpuObject*)apNode)->FUN_00c91020();
    apVisitor->v16();
    int i = 0;
    if (apNode->m_2c > 0)
    {
        do
        {
            ItemList* pItemList = &apNode->m_28[i]->m_kNode;
            int j = 0;
            if (pItemList->m_uiItemCount > 0)
            {
                do
                {
                    ItemFix* pItem = (ItemFix*)pItemList->m_items[j];

                    const void* p =
                        pItem->hasProperty(0x1134) ? pItem->getProperty(0x1134).getPtr() : (char*)pItem + 0x10;
                    __declspec(align(16)) OutVec sweptTransform;
                    pItem->m_e0.SweepTransform(f, &sweptTransform);
                    apVisitor->v04(&sweptTransform, p, DAT_01268fe0);
                    ++j;
                } while (j < pItemList->m_uiItemCount);
            }
            ++i;
        } while (i < apNode->m_2c);
    }
    apVisitor->v17();
}


namespace fnv_00d65750 {
struct ArrayStruct
{
    void** m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};

struct Entry
{
    int m_00;
    ArrayStruct m_aiIndexedValues;
};

struct Listener
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void FUN_v5(void* a, void* b, int c);
};

struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* volatile m_10;
};

extern void* g_01268fe0;
Singleton* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void* a, ArrayStruct* arr, int sz, int elem);

struct Shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    Listener* m_pListener;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    Entry** m_pTable;
    void FUN_00d65750(int index);
};

// Invokes m_pListener->FUN_v5 for each item in m_pTable[index]->m_aiIndexedValues, then resets the array count to 0.
// @fnv 0x00d65750
void Shell::FUN_00d65750(int index)
{
    Entry* entry = m_pTable[index];
    for (int i = 0; i < entry->m_aiIndexedValues.m_iArrayLength; i++)
    {
        int nItem = (int)entry->m_aiIndexedValues.m_pData[i];
        m_pListener->FUN_v5(entry->m_aiIndexedValues.m_pData[i], g_01268fe0, *(int*)nItem);
    }
    ArrayStruct* arr = &entry->m_aiIndexedValues;
    Singleton* holder = FUN_00c85750();
    void* pContext = holder->m_10;
    int iCapacity = arr->m_iCapacity & 0x3fffffff;
    if (iCapacity < 0)
    {
        FUN_00c908c0(pContext, arr, (iCapacity * 2) > 0 ? iCapacity * 2 : 0, 4);
    }
    arr->m_iArrayLength = 0;
}
}  // namespace fnv_00d65750

// Remove a displayed entity and its cached display geometry.
extern "C" void _ReadWriteBarrier();
// The voice object that receives the finished sample.
struct AudioVoiceHost
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int iKey, int iGlobal, int iResult);
};
// The channel that owns a playback buffer.
struct AudioChannel
{
    void FUN_00cb1fb0(int iResult);
};
// The playback buffer itself.
struct AudioBuffer
{
    int LookupHashEntry(int iResult, int iUnused);
    void FUN_00cb1870(AudioAllocator* pAlloc, int iResult, int iCount);
    void FUN_00cb1fb0(int iResult);
};
// One list of played items.
struct AudioItemList
{
    int unk00;
    int* m_pItems;
    int m_iArrayLength;

    __forceinline int find(int key) const
    {
        int count = m_iArrayLength;
        for (int i = 0; i < count; ++i)
        {
            if (m_pItems[i] == key)
                return i;
        }
        return -1;
    }
    __forceinline void removeAt(int i)
    {
        --m_iArrayLength;
        if (m_iArrayLength != i)
        {
            memCpy4_d65f(m_pItems + i, m_pItems + m_iArrayLength, sizeof(int));
        }
    }
};
// The sound that is being played.
struct AudioParam
{
    int unk00;
    int unk04;
    int m_i08;
    int unk0c;
    int m_i10;
    int unk14;
    int unk18;
    int unk1c;
};
// The flag the helper is given: it is a single byte but the helper reads it
// as a whole word.
// The sub object this method belongs to.
struct AudioNodeSub
{
    int unk00;
    int unk04;
    AudioItemList** m_pItemLists;
    int unk0c;
    int unk10;
    AudioChannel m_channel;
    int unk18;
    int unk1c;
    AudioBuffer m_buffer;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char m_bPlayed;

    void FUN_00d65640(AudioParam* pParam);
};
struct DisplayPrimary
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_override10;
    int m_override14;
    AudioVoiceHost* m_display;
    int unk1c;
    int unk20;
    int unk24;
};
struct DisplayOuter : DisplayPrimary, AudioNodeSub
{
};
static DisplayOuter* GetDisplayOuter(AudioNodeSub* p)
{
    return (DisplayOuter*)((char*)p - sizeof(DisplayPrimary));
}
extern int DAT_01268fe0;
void* __cdecl GetProperty1134(D66180Entity* e);
// Module local helper: it is called from exactly one place, so the compiler
// hands it the sound in EAX and keeps the two other arguments on the stack.
// Resolves a display result for pParam, notifies the voice host, adjusts the audio buffer, and removes the matching item from the item list.
// @f3 0x009f25b0 (community match, verified in this file)
namespace Native933 {
struct Count {
    int value;
    operator int() const { return value; }
    void operator--() { --value; }
};
struct List {
    int unk00;
    int* data;
    Count count;
    int Find(int key) const {
        int n = count;
        for (int i = 0; i < n; ++i)
            if (data[i] == key)
                return i;
        return -1;
    }
    void Remove(int i) {
        --count;
        int n = count;
        _ReadWriteBarrier();
        data[i] = data[n];
    }
};
struct Finder {
    int FUN_009f2550(int key);
};
struct Map {
    int FUN_009227d0(int key, int defaultValue);
    void FUN_00922710(int key, int count);
    void FUN_00922d30(int key);
};
int __cdecl FUN_009f3010(AudioParam* param);
extern int DAT_011697fc;
}

// pdb: hkpShapeDisplayViewer::entityRemovedCallback | hkpShapeDisplayViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: entity
void AudioNodeSub::FUN_00d65640(AudioParam* pParam)
{
    using namespace Native933;
    void* propPtr = reinterpret_cast<FUN_00477900_stub*>(pParam)->FUN_00477900(0x1135).m_ptr;
    if (!propPtr && !pParam->m_i10)
        return;
    int index = reinterpret_cast<Finder*>(GetDisplayOuter(this))->FUN_009f2550(pParam->m_i08);
    if (index < 0)
        return;
    List* list = reinterpret_cast<List*>(m_pItemLists[index]);
    int value = propPtr ? (int)propPtr : pParam->m_i10;
    int key = FUN_009f3010(pParam);
    GetDisplayOuter(this)->m_display->v14(key, DAT_011697fc, value);
    if (m_bPlayed) {
        Map* counts = reinterpret_cast<Map*>(&m_buffer);
        int count = counts->FUN_009227d0(value, 0) - 1;
        if (count == 0) {
            reinterpret_cast<Map*>(&m_channel)->FUN_00922d30(value);
            counts->FUN_00922d30(value);
        } else {
            counts->FUN_00922710(value, count);
        }
    }
    int i = list->Find(key);
    if (i >= 0) {
        list->Remove(i);
    }
}


struct S_00d65970_Heap
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};

struct S_00d65970_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d65970_Heap* unk10;
    S_00d65970_Heap& heap()
    {
        return *unk10;
    }
};

struct S_00d65970_Item;

inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}

struct S_00d65970_ItemArray
{
    S_00d65970_Item** data;
    int size;
    int capacityAndFlags;
};

struct S_00d65970_Elem
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
    S_00d65970_ItemArray items;
};

struct S_00d65970_B28;
struct S_00d65970_B2c;

struct S_00d65970_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00d65970_Elem* unk20;
    int unk24;
    S_00d65970_Elem** unk28;
    int unk2c;
    int unk30;
    S_00d65970_Elem** unk34;
    int unk38;
    void FUN_00c93820(S_00d65970_B28* l);
    void FUN_00c93920(S_00d65970_B2c* l);
};

struct S_00d65970_Node
{
    S_00d65970_Arg* arg;
    S_00d65970_ItemArray arr;
    S_00d65970_Node()
    {
        arr.data = 0;
        arr.size = 0;
        arr.capacityAndFlags = 0x80000000;
    }
};

struct S_00d65970_NodeArray
{
    S_00d65970_Node** data;
    int size;
    int capacityAndFlags;
};

void ResizeAudioStream(S_00d65970_Heap* heap, void* arr, int elemSize);

struct S_00d65970_Base0
{
    virtual void vfn0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};

struct S_00d65970_B28
{
    virtual void vfn0();
    virtual void vfn1(S_00d65970_Item* item);
};

struct S_00d65970_B2c
{
    int unk00;
};

struct S_00d65970_Obj : S_00d65970_Base0, S_00d65970_B28, S_00d65970_B2c
{
    S_00d65970_NodeArray nodes;
    void FUN_00d65970(S_00d65970_Arg* arg);
};

// Creates a node from arg, appends it to the nodes array, and calls vfn1 on all items in arg's element arrays.
// @f3 0x009f2870 (community match, verified in this file)
struct Slot7RegistrationView
{
    void FUN_00903ae0(S_00d65970_B28* listener);
    void FUN_00903be0(S_00d65970_B2c* listener);
};
struct Slot7HavokFreeCell
{
    Slot7HavokFreeCell* next;
};
struct Slot7HavokThreadMemory
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
    Slot7HavokFreeCell* freeHead;
    int freeCount;
    void* FUN_008f6800(int a, int b);
};
void __cdecl FUN_00901f10(void* arr, int n);

// pdb: hkpShapeDisplayViewer::addWorld | hkpShapeDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void S_00d65970_Obj::FUN_00d65970(S_00d65970_Arg* arg)
{
    reinterpret_cast<Slot7RegistrationView*>(arg)->FUN_00903ae0(this);
    reinterpret_cast<Slot7RegistrationView*>(arg)->FUN_00903be0(this);
    Slot7HavokThreadMemory* tm = (Slot7HavokThreadMemory*)TlsGetValue((unsigned long)DAT_010f3170);
    void* mem;
    Slot7HavokFreeCell* cell = tm->freeHead;
    if (cell)
    {
        tm->freeCount--;
        tm->freeHead = cell->next;
        mem = cell;
    }
    else
    {
        mem = tm->FUN_008f6800(2, 0x35);
    }
    S_00d65970_Node* node = new (mem) S_00d65970_Node;
    node->arg = arg;
    S_00d65970_NodeArray& arr = nodes;
    if (arr.size == (arr.capacityAndFlags & 0x3fffffff))
        FUN_00901f10(&arr, 4);
    arr.data[arr.size] = node;
    arr.size++;
    for (int i = 0; i < arg->unk2c; i++)
    {
        S_00d65970_ItemArray& items = arg->unk28[i]->items;
        for (int j = 0; j < items.size; j++)
            vfn1(items.data[j]);
    }
    for (int i = 0; i < arg->unk38; i++)
    {
        S_00d65970_ItemArray& items = arg->unk34[i]->items;
        for (int j = 0; j < items.size; j++)
            vfn1(items.data[j]);
    }
    S_00d65970_Elem* e = arg->unk20;
    if (e)
    {
        for (int j = 0; j < e->items.size; j++)
            vfn1(e->items.data[j]);
    }
}

