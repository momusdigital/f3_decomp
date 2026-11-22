#include "f3_common.h"
// src/havok/common/serialize/data/dict/hkdataobjectdict.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/dict/hkdataobjectdict.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dc6ff0_Stream
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void call(void*, unsigned char)
    {}
};

struct FUN_00dc7070_target
{
    virtual void FUN_00dc7070_v0() = 0;
    virtual void FUN_00dc7070_v1() = 0;
    virtual void FUN_00dc7070_v2() = 0;
    virtual void FUN_00dc7070_v3() = 0;
    virtual void FUN_00dc7070_v4() = 0;
    virtual void FUN_00dc7070_v5() = 0;
    virtual void FUN_00dc7070_v6() = 0;
    virtual void FUN_00dc7070_v7() = 0;
    virtual void* FUN_00dc7070_v8(int) = 0;
};

struct FUN_00dc7070_holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7070_target* m_20;
};

struct FUN_00dc7070_class
{
    void* m_00;
    int m_04;
    void* m_08;
    FUN_00dc7070_holder* m_0c;
    int m_10;

    void* FUN_00dc7070(int a);
};

// @f3 0x005515c0 (community match, verified in this file)
// pdb: TESFaction::GetTrackCrime | Actor.obj | fnv360_0822_debug, call_gap_sim, low
void* FUN_00dc7070_class::FUN_00dc7070(int aiOffset)
{
    *(int*)((char*)this + 0x44) += aiOffset;
    void* (__thiscall* fn)(FUN_00dc7070_class*, int) = (void* (__thiscall*)(FUN_00dc7070_class*, int))((*(void***)this)[18]);
    return fn(this, 0x80000000);
}


typedef void(__thiscall* FUN_00dc7090_call)(void*, int, int);

struct FUN_00dc7220_VirtualBase
{
// @fnv 0x00dc7220
    virtual void FUN_00dc7220_v00()
    {}
    virtual void FUN_00dc7220_v01()
    {}
    virtual void FUN_00dc7220_v02()
    {}
    virtual void FUN_00dc7220_v03()
    {}
    virtual void FUN_00dc7220_v04()
    {}
    virtual void FUN_00dc7220_v05()
    {}
    virtual void FUN_00dc7220_v06()
    {}
    virtual void FUN_00dc7220_v07()
    {}
    virtual void FUN_00dc7220_v08()
    {}
    virtual void FUN_00dc7220_v09()
    {}
    virtual void FUN_00dc7220_v10()
    {}
    virtual void FUN_00dc7220_v11()
    {}
    virtual void FUN_00dc7220_v12()
    {}
    virtual void FUN_00dc7220_v13()
    {}
    virtual void FUN_00dc7220_v14()
    {}
    virtual void FUN_00dc7220_v15()
    {}
    virtual void FUN_00dc7220_v16()
    {}
    virtual void FUN_00dc7220_v17()
    {}
    virtual void FUN_00dc7220_v18()
    {}
    virtual void FUN_00dc7220_v19()
    {}
    virtual void FUN_00dc7220_v20()
    {}
};

struct FUN_00dc7220_Virtual : FUN_00dc7220_VirtualBase
{
    virtual void FUN_00dc7220_virtual(int, int)
    {}
};

struct Receiver
{
    void FUN_009ba760(void* pArg);
};

struct FUN_00dc72a0_data
{
    char m_00[0x2c];
    void* m_2c;
};

struct FUN_00dc72a0_class
{
    char m_00[8];
    FUN_00dc72a0_data* m_08;

    void* __thiscall ForwardToReceiver(Receiver* m_pReceiver);
};

// @f3 0x006d82b0 (community match, verified in this file)
namespace task1642 {
struct Layout {unsigned unk00,unk04,unk08,unk0c,unk10,state;};
struct Heap {void* FUN_0086ba60(Receiver*);};extern Heap DAT_01090a78;
}
// pdb: TESSaveLoadGame::DestroyBuffer | TESSaveLoadGame.obj | fnv360_0822_retail, call_gap, low
// pdb params: apBuffer
void* FUN_00dc72a0_class::ForwardToReceiver(Receiver* argument){
 void* result=task1642::DAT_01090a78.FUN_0086ba60(argument);
 reinterpret_cast<task1642::Layout*>(this)->state=0;
 return result;
}


namespace fnv_00dc72c0 {
struct Receiver
{
    void FUN_009ba760(void* pArg);
};

}  // namespace fnv_00dc72c0

struct FUN_00dc9a20_Allocator
{
    virtual void FUN_00dc9a20_0() = 0;
    virtual void FUN_00dc9a20_1() = 0;
    virtual void FUN_00dc9a20_Deallocate(void* object, unsigned short size) = 0;
};

struct FUN_00dc9a20_Router
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    FUN_00dc9a20_Allocator* m_pThreadAllocator;
};

FUN_00dc9a20_Router* _D1A0E0GetMemoryRouter();

namespace fnv_00dc9b20 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* alloc, void* ptr, int size, int align);

struct VecArrayImplementation
{
    void FUN_00dc9b20(int n);
};

}  // namespace fnv_00dc9b20

namespace fnv_00dc9b60 {
struct VecArrayImplementation
{
    void* m_data;         // +0x0
    int m_iElementCount;           // +0x4
    int m_pRayCursor;       // +0x8
    int m_flags;          // +0xc
    void* m_p0;           // +0x10
    void* m_p4;           // +0x14
    int m_iElementIndex;  // +0x18
    void Resize(int count);
};

void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* allocator, void* array, int size, int align);

}  // namespace fnv_00dc9b60

namespace fnv_00dc9cd0 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* alloc, void* arr, int count, int flag);

}  // namespace fnv_00dc9cd0

namespace fnv_00dc9d70 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* allocator, void* array, int newCap, int elemSize);

}  // namespace fnv_00dc9d70

namespace fnv_00dca4e0 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* router, void* array, int count, int size);

}  // namespace fnv_00dca4e0

namespace fnv_00dca720 {
struct FUN_00dca720_Manager
{
    virtual void FUN_00dca720_Dummy0();
    virtual void FUN_00dca720_Dummy1();
    virtual void Free(void* p, unsigned short size);
};

struct FUN_00dca720_Router
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    FUN_00dca720_Manager* m_manager;
};

extern FUN_00dca720_Router* __cdecl _D1A0E0GetMemoryRouter();

}  // namespace fnv_00dca720

namespace fnv_00dcb0e0 {
struct FUN_00dcb0e0_Object
{
    void* vtable;
    unsigned short m_iElementCount;
    unsigned short m_flag;
    unsigned int m_zero;
    void* m_pOwnerObject;
    void* m_arg;
};

struct FUN_00dcb0e0_Allocator
{
    // Virtual destructor for the allocator stand-in; does nothing.
// @fnv 0x00dcb0e0
    virtual ~FUN_00dcb0e0_Allocator()
    {}
    virtual FUN_00dcb0e0_Object* FUN_00dcb0e0_alloc(unsigned int size);
};

struct FUN_00dcb0e0_Router
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    FUN_00dcb0e0_Allocator* m_10;
};

extern FUN_00dcb0e0_Router* __cdecl _D1A0E0GetMemoryRouter();

}  // namespace fnv_00dcb0e0

struct FUN_00dcb3a0_Element
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual int f22(int value)
    {
        return value;
    }
};

struct FUN_00dcb6f0_Object
{
// @fnv 0x00dcb6f0
    virtual void FUN_00dcb6f0_0()
    {}
    virtual void FUN_00dcb6f0_1()
    {}
    virtual void FUN_00dcb6f0_2()
    {}
    virtual void FUN_00dcb6f0_3()
    {}
    virtual void FUN_00dcb6f0_4()
    {}
    virtual void FUN_00dcb6f0_5()
    {}
    virtual void FUN_00dcb6f0_6()
    {}
    virtual void FUN_00dcb6f0_7()
    {}
    virtual void FUN_00dcb6f0_8()
    {}
    virtual void FUN_00dcb6f0_9()
    {}
    virtual void FUN_00dcb6f0_10()
    {}
    virtual void FUN_00dcb6f0_11(int, int)
    {}
};

struct FUN_00dcb790_Element;

struct FUN_00dcb790_Pair
{
    void* m_iWordAt00;
    FUN_00dcb790_Element* m_iWordAt04;
};

struct FUN_00dcb790_Element
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9(int a, int b)
    {}
};

struct FUN_00dcb5d0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb790_Pair* m_iThirdValue;

    __declspec(noinline) int __thiscall FUN_00dcb5d0(int a)
    {
        return 0;
    }
};

namespace fnv_00dcb960 {
struct FUN_00d1a0e0_vtable
{
    void* m_00;
    void* m_04;
    void(__thiscall* m_08)(void* self, void* object, unsigned short size);
};

struct FUN_00d1a0e0_memory
{
    FUN_00d1a0e0_vtable* m_ppVirtualMethodTable;
};

struct FUN_00d1a0e0_router
{
    unsigned char m_00[0x10];
    FUN_00d1a0e0_memory* m_10;
};

extern FUN_00d1a0e0_router* __cdecl _D1A0E0GetMemoryRouter();

}  // namespace fnv_00dcb960

namespace fnv_00dcbf90 {

struct FUN_00dcbf90_router
{
    virtual void FUN_00dcbf90_router_0();
    virtual void FUN_00dcbf90_router_1();
    virtual void FUN_00dcbf90_router_2(void* object, unsigned short size);
};

struct FUN_00dcbf90_manager
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    FUN_00dcbf90_router* m_10;
};

FUN_00dcbf90_manager* _D1A0E0GetMemoryRouter();

}  // namespace fnv_00dcbf90

struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    CpuInterface* target;
    void FUN_00dc89e0();
};

namespace fnv_00dc89f0 {
struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    CpuInterface* target;
    void FUN_00dc89f0();
};
}  // namespace fnv_00dc89f0

struct FUN_00dc9b10_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void FUN_00dc9b10();
};

// @fnv 0x00dc9b10
// pdb: hkpShapeDisplayBuilder::resetCurrentRawGeometry | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, objrun, medium
void FUN_00dc9b10_cls::FUN_00dc9b10()
{
    m_10 = 0;
}

namespace fnv_00dcac10 {
struct CpuScalar
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuScalar* value;
    int FUN_00dcac10();
};
}  // namespace fnv_00dcac10

struct hkAllocatorDC76
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC76
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    hkAllocatorDC76* m_pkHeap;
    hkAllocatorDC76& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDC76* __cdecl FUN_00c85750() throw();
extern "C" char* __cdecl FUN_00cb1410(const char* pcStr) throw();

template <typename T> struct hkArrayDC76
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDC76() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayDC76() throw()
    {
        hkAllocatorDC76& kAlloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class FUN_00d47a80_class
{
  public:
    void* GetValue(const void* pvKey, int iDefault) throw();
    void FUN_00d874d0(const char* pcKey, const void* pvValue) throw();
};

class hkDataClassImplDC76;
class hkDataObjectImplDC76;
class hkDataArrayImplDC76;

class hkDataClassImplDC76
{
  public:
    void FUN_00dc9470(const char* pcName) throw();
};

class hkDataObjectImplDC76
{
  public:
    void FUN_00dc90f0(const char* pcName) throw();
};

class hkDataArrayImplDC76
{
  public:
    void FUN_00dc8ea0(const char* pcName) throw();
};

class hkDataWorldImplDC76
{
  public:
    int m_00[0x13];
    FUN_00d47a80_class m_stringPool;

    void CollectShapes(const void* pvClass, int iRecurse, int iUnk,
                       hkArrayDC76<hkDataObjectImplDC76*>& kObjectsOut) throw();
    void FUN_00dc9180(hkDataClassImplDC76* pkClass, int iRecurse,
                      hkArrayDC76<hkDataArrayImplDC76*>& kArraysOut) throw();

    const char* InternString(const char* pcStr)
    {
        if (pcStr)
        {
            const char* pcPooled = (const char*)m_stringPool.GetValue(pcStr, 0);
            if (pcPooled == 0)
            {
                pcPooled = FUN_00cb1410(pcStr);
                m_stringPool.FUN_00d874d0(pcPooled, pcPooled);
            }
            return pcPooled;
        }
        return 0;
    }
    void GetObjectsOfClass(const void* pvClass, hkArrayDC76<hkDataObjectImplDC76*>& kObjectsOut)
    {
        kObjectsOut.clear();
        CollectShapes(pvClass, 1, 0, kObjectsOut);
    }
};

namespace fnv_00dc8030 {
struct FUN_00dc8030_Allocator
{
    virtual void slot0();
    virtual void* Allocate(unsigned int bytes);
};
struct FUN_00dc8030_Memory
{
    int unk00, unk04, unk08, unk0c;
    FUN_00dc8030_Allocator* allocator;
};
extern "C" FUN_00dc8030_Memory* __cdecl FUN_00c85750();
}  // namespace fnv_00dc8030

namespace fnv_00dc80c0 {
struct hkReferencedObject
{
    void RetainReference();
    void removeReference() throw();
};

struct SkRefPtr
{
    hkReferencedObject* m_pRetainedObject;
    SkRefPtr()
    {}
    SkRefPtr(const SkRefPtr& rp)
    {
        if (rp.m_pRetainedObject)
        {
            rp.m_pRetainedObject->RetainReference();
        }
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~SkRefPtr()
    {
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = 0;
    }
};

struct SkAllocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
};

struct BSAudio
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    SkAllocator* m_pStreamAllocator;

    SkAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

BSAudio* FUN_00c85750();
extern "C" char* FUN_00cb1410(const char* str) throw();

struct FUN_00d47a80_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* GetValue(void* key, int def) throw();
    void FUN_00d874d0(const char* key, int value) throw();
};

struct SkShared
{
    virtual void Release(int flags);
    unsigned short m_iElementCount;
    unsigned short m_flags;
    int m_iObjectReferenceCount;
};

struct SkOwner;

struct SkItem
{
    void* vtbl;
    unsigned short m_iElementCount;
    unsigned short m_flags;
    int m_iObjectReferenceCount;
    int unk0c;
    int unk10;
    int unk14;
    SkShared* m_pSharedObject;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    static SkItem* Allocate(int size)
    {
        SkItem* p = (SkItem*)FUN_00c85750()->heap().AllocateMemoryBlock(size);
        p->m_iElementCount = (unsigned short)size;
        return p;
    }
    SkItem* FUN_00dcabb0(SkOwner* owner, int a, int b);
    void FUN_00dc9f20(const char* name, int a, const SkRefPtr& ref, int b) throw();
};

struct SkStore
{
    FUN_00d47a80_class m_map;
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
    FUN_00d47a80_class m_ppNames;

    void hkPackfileWriter_notDuplicateMetaData(SkItem* item);
    SkRefPtr* FUN_00dc8d70(SkRefPtr* out, void* key) throw();

    char* Intern(char* str)
    {
        return str ? Lookup(str) : 0;
    }

    char* Lookup(char* str)
    {
        char* name = (char*)m_ppNames.GetValue(str, 0);
        if (!name)
        {
            name = FUN_00cb1410(str);
            m_ppNames.FUN_00d874d0(name, (int)name);
        }
        return name;
    }
};

struct SkEntry
{
    char* name;
    int unk04;
    int unk08;
    void* key;
};

struct SkDesc
{
    int unk00;
    int unk04;
    void* shared;
    SkEntry* entries;
    int count;
};

struct SkOwner
{
    int unk00;
    int unk04;
    SkStore* m_store;

    SkItem* CreateItem(SkDesc* desc);
};

}  // namespace fnv_00dc80c0

namespace fnv_00dc88c0 {
struct hkAllocatorDC88
{
    virtual void V0();
    virtual void V1();
    virtual void ReleaseBlock(void* p, int iNumBytes);
};

struct hkMemoryRouterDC88
{
    char m_acUnk00[0x10];
    hkAllocatorDC88* m_pkHeap;
    hkAllocatorDC88& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDC88* __cdecl FUN_00c85750();

void FUN_00cb13c0(int iString);

struct hkDataRefCountedDC88
{
    virtual ~hkDataRefCountedDC88();
    int m_iUnk04;
    int m_iArrayLength;
    void removeReference()
    {
        if (--m_iArrayLength == 0)
            delete this;
    }
};

}  // namespace fnv_00dc88c0

namespace fnv_00dc8d20 {
extern "C" char* __cdecl FUN_00cb1410(const char* s) throw();

struct FUN_00d47a80_class
{
    void* GetValue(void* a, int b);
};

struct FUN_00d874d0_s : public FUN_00d47a80_class
{
    void FUN_00d874d0(const char* key, int value);
};

struct hkPooledStringDC8D
{
    const char* m_kStringBuffer;
    hkPooledStringDC8D()
    {}
};

struct hkObjDC8D
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
    FUN_00d874d0_s m_kNodePool;

    hkPooledStringDC8D GetPooledString(const char* name);
};

// Looks up name in the string pool, inserting it via FUN_00cb1410 if absent, and returns a pooled string holding the result (or null when name is null).
// @fnv 0x00dc8d20
hkPooledStringDC8D hkObjDC8D::GetPooledString(const char* name)
{
    hkPooledStringDC8D result;
    if (name)
    {
        char* s = (char*)m_kNodePool.GetValue((void*)name, 0);
        if (!s)
        {
            s = FUN_00cb1410(name);
            m_kNodePool.FUN_00d874d0(s, (int)s);
        }
        result.m_kStringBuffer = s;
    }
    else
    {
        result.m_kStringBuffer = 0;
    }
    return result;
}
}  // namespace fnv_00dc8d20

int __stdcall LookupWithDefault(void* key);

struct hkMapPairDC90
{
    int key;
    int val;
};

struct FUN_00cb18f0_t
{
    hkMapPairDC90* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FindSlot(int key);
    int RemoveEntry(int it);
};

struct hkLinkDC90
{
    int m_uiFilterValue;
    int m_next;
};

class hkMultiMapDC90
{
  public:
    hkLinkDC90* m_ppLinks;
    int unk04;
    int unk08;
    FUN_00cb18f0_t m_pHashFunction;
    int m_kFreeListEntries;

    void RemoveKey(int key);
};

// Looks up key in the map, unlinks its entry, and moves the entry's chain to the front of the free list.
// @f3 0x00a2a110 (community match, verified in this file)
// pdb: hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *>::removeKey | hkDataObjectDict.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: key
void hkMultiMapDC90::RemoveKey(int key)
{
    FUN_00cb18f0_t& hash = m_pHashFunction;
    int it = hash.FindSlot(key);
    int first = ((int*)hash.m_kPrimitiveElement)[hash.m_iPairCount + it + 1];
    hash.RemoveEntry(it);
    if (first != -1)
    {
        int last = first;
        while (m_ppLinks[last].m_next != -1)
            last = m_ppLinks[last].m_next;
        m_ppLinks[last].m_next = m_kFreeListEntries;
        m_kFreeListEntries = first;
    }
}


namespace fnv_00dc96a0 {
class hkMemoryAllocatorDC96
{
  public:
    virtual ~hkMemoryAllocatorDC96() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC96
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC96* m_pStreamAllocator;
    hkMemoryAllocatorDC96& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC96& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayDC96
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDC96& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseDC96
{
  public:
    virtual ~hkBaseDC96() throw()
    {}
};

}  // namespace fnv_00dc96a0

extern "C" char* __cdecl FUN_00cb1410(const char* pcString);

struct hkResultDC98
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDC98()
    {}
};

struct hkHalfDC99
{
    short m_uiFilterValue;
    operator float() const
    {
        int t = m_uiFilterValue << 16;
        return *reinterpret_cast<float*>(&t);
    }
};

struct hkResultDC99
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDC99()
    {}
};

// Looks up the entry for iKey with type 3 and stores kValue into that entry's float field.
// @f3 0x006e04c0 (community match, verified in this file)
namespace f3m_006e04c0 {
class FUN_00aff950_shell
{
public:
    unsigned int FUN_00aa1810(void* pvBuffer, unsigned int uiSize);
};

namespace f3m_006e04c0 {

class hkEntryDC99Block
{
public:
    int FUN_006d6cd0();
};

int FUN_006cd6a0(int nStream, void* pvValue, int nType);

struct hkObjDC99Fields
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_uiIndex;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
    unsigned char m_18;
    unsigned char m_19;
    unsigned char m_1a;
    unsigned char m_1b;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char m_1f;
    int m_20;

    void FUN_006e04c0(int iKey);
};

// pdb: BGSLoadFormBuffer::LoadHeader | BGSLoadFormBuffer.obj | fnv360_0822_retail, call_gap, low
// pdb params: apFile
void hkObjDC99Fields::FUN_006e04c0(int iKey)
{
    hkEntryDC99Block* pKey = (hkEntryDC99Block*)&m_14;

    ((FUN_00aff950_shell*)iKey)->FUN_00aa1810(pKey, 9);
    m_uiIndex = pKey->FUN_006d6cd0();
    FUN_006cd6a0(iKey, &m_20, m_1b >> 6);
}

}
}   // namespace f3m_006e04c0


struct hkMemberInfoDC99
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_type;
};

struct hkResultDC99C
{
    hkMemberInfoDC99* m_item;
    int m_uiEdgeIndex;
    hkResultDC99C()
    {}
};

class hkBaseDC9A
{
  public:
    hkBaseDC9A() : m_06(0), m_08(0)
    {}
    virtual ~hkBaseDC9A() throw();

    unsigned short m_04;
    unsigned short m_06;
    int m_08;
};

template <class T> class hkArrayDC9A
{
  public:
    hkArrayDC9A() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

namespace fnv_00dc9c20 {
struct FnvAllocator;
struct FnvMemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FnvAllocator* m_pStreamAllocator;
};
FnvMemoryRouter* __cdecl FUN_00c85750();
struct FnvEntry
{
    int m_iOwnerObjectOffset;
    struct FnvRefCounted* m_object;
};
struct FnvEntries
{
    FnvEntry* m_data;
    int m_iElementCount;
    int m_pRayCursor;
};
void __cdecl ResizeAudioStream(FnvAllocator*, FnvEntries*, unsigned int);
struct FnvRefCounted
{
    int unk00;
    int unk04;
    int m_refs;
};
FnvRefCounted* __cdecl FUN_00dc7de0(void* context, void* key, int flags);
}  // namespace fnv_00dc9c20

extern "C" void __movsd(unsigned long* pDst, const unsigned long* pSrc, unsigned int ItemUpdateArray);

class hkMemoryAllocatorDC9D;

struct hkMemoryRouterDC9D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9D* m_pStreamAllocator;

    hkMemoryAllocatorDC9D& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDC9D {
extern "C" hkMemoryRouterDC9D& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDC9D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

inline void memCpy4DC9D(void* pvDst, const void* pvSrc, unsigned int iNumWords)
{
    __movsd((unsigned long*)pvDst, (const unsigned long*)pvSrc, iNumWords);
}

template <class T> class hkArrayDC9D
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDC9D& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void _setSizeZero(hkMemoryAllocatorDC9D& kAlloc, int n)
    {
        reserve(kAlloc, n);
        int iNumToFill = n - m_iElementCount;
        T* pDst = m_data + m_iElementCount;
        if (iNumToFill > 0)
        {
            pDst[0].m_kPointA = 0;
            pDst[0].m_kPointB = 0;
            memCpy4DC9D(pDst + 1, pDst, ((iNumToFill - 1) * sizeof(T) + 3) >> 2);
        }
        m_iElementCount = n;
    }
    __forceinline void setSizeZero(int n)
    {
        _setSizeZero(hkRouterDC9D::FUN_00c85750().heap(), n);
    }
};

class hkMemoryAllocatorDC9F
{
  public:
    virtual ~hkMemoryAllocatorDC9F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC9F
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC9F* m_pStreamAllocator;
    hkMemoryAllocatorDC9F& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDC9F {
extern "C" hkMemoryRouterDC9F& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDC9F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDC9F& kAlloc = hkRouterDC9F::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkRefObjDC9F
{
  public:
    virtual ~hkRefObjDC9F() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkBufferDC9F : public hkRefObjDC9F
{
  public:
    int unk08;
    hkArrayDC9F<void*> m_data;

    virtual ~hkBufferDC9F() throw()
    {
        m_data.ClearAndRelease();
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDC9F::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkBufferDC9F*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDC9F* FUN_00dc9fd0(unsigned int uiFlags) throw();
};

class hkRefDCA0
{
  public:
    virtual ~hkRefDCA0();
    int unk04;
    int m_iObjectReferenceCount;

    void addRef()
    {
        ++m_iObjectReferenceCount;
    }
    void release()
    {
        if (--m_iObjectReferenceCount == 0)
            delete this;
    }
};

namespace fnv_00dca0f0 {
class hkMemoryAllocatorDCA0
{
  public:
    virtual ~hkMemoryAllocatorDCA0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDCA0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA0* m_pStreamAllocator;
    hkMemoryAllocatorDCA0& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCA0& __cdecl FUN_00c85750();

template <class T> __forceinline void destructDCA0(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayDCA0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayDCA0() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructDCA0(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorDCA0& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkDataRefCountedDCA0
{
  public:
    virtual ~hkDataRefCountedDCA0() throw()
    {}
    int m_usAllocationSize;
    int m_iReferenceCount;

    void removeReference() throw()
    {
        if (--m_iReferenceCount == 0)
            delete this;
    }
};

}  // namespace fnv_00dca0f0

namespace fnv_00dca190 {

struct FUN_00dca190_Virtual
{
    virtual void v00()
    {}
    virtual void v04()
    {}
    virtual void v08(void* object, int value)
    {}
};

void* __cdecl FUN_00c85750(void);

}  // namespace fnv_00dca190

namespace fnv_00dca210 {
class hkMemoryAllocatorDCA2;

struct hkMemoryRouterDCA2
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA2* m_pTemp;
    hkMemoryAllocatorDCA2* m_pStreamAllocator;
    hkMemoryAllocatorDCA2& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDCA2& __cdecl FUN_00c85750() throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA2& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T> class hkArrayDCA2
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA2& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

class hkObjDCA2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArrayDCA2<char> m_data;

    void AssignFromBuffer(const void* src, int n);
};

}  // namespace fnv_00dca210

struct hkEntryDCA2
{
    int m_kPointA;
    int m_kPointB;
};

class hkObjDCA2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkEntryDCA2* m_entries;

    void FUN_00dca2d0(int i, hkEntryDCA2 e);
};

class hkMemoryAllocatorDCA3;

struct hkMemoryRouterDCA3
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA3* m_pTemp;
    hkMemoryAllocatorDCA3* m_pStreamAllocator;
    hkMemoryAllocatorDCA3& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDCA3 {
extern "C" hkMemoryRouterDCA3& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA3& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayDCA3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA3& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterDCA3::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

struct hkBoolDCA3
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

namespace fnv_00dca360 {
class hkMemoryAllocatorDCA3;

struct hkMemoryRouterDCA3
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA3* m_pStreamAllocator;
    hkMemoryAllocatorDCA3& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCA3& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA3& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayDCA3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void reserve(hkMemoryAllocatorDCA3& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

}  // namespace fnv_00dca360

namespace fnv_00dca3c0 {
class hkMemoryAllocatorDCA4;

struct hkMemoryRouterDCA4
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA4* m_pStreamAllocator;
    hkMemoryAllocatorDCA4& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCA4& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA4& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayDCA4
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void reserve(hkMemoryAllocatorDCA4& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

}  // namespace fnv_00dca3c0

class hkMemoryAllocatorDCA4;

struct hkMemoryRouterDCA4
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA4* m_pTemp;
    hkMemoryAllocatorDCA4* m_pStreamAllocator;
    hkMemoryAllocatorDCA4& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDCA4 {
extern "C" hkMemoryRouterDCA4& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA4& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayDCA4
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA4& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterDCA4::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

namespace fnv_00dca5f0 {
struct C85750Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};
C85750Router* FUN_00c85750();
void __cdecl FUN_00c908c0(void* allocator, void* array, int newCapacity, int itemSize);
void __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int bytes);
}  // namespace fnv_00dca5f0

void __cdecl FUN_00cb13c0(int iString);
extern "C" char* __cdecl FUN_00cb1410(const char* pcString);

class hkMemoryAllocatorDCA6
{
  public:
    virtual ~hkMemoryAllocatorDCA6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCA6
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA6* m_pStreamAllocator;
    hkMemoryAllocatorDCA6& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA6 {
extern "C" hkMemoryRouterDCA6& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDCA6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDCA6& kAlloc = hkRouterDCA6::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkRefObjDCA6
{
  public:
    virtual ~hkRefObjDCA6() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

void __cdecl FUN_00cb13c0(int p) throw();

class hkMemoryAllocatorDCA7
{
  public:
    virtual ~hkMemoryAllocatorDCA7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCA7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA7* m_pStreamAllocator;
    hkMemoryAllocatorDCA7& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA7 {
extern "C" hkMemoryRouterDCA7& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDCA7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDCA7& kAlloc = hkRouterDCA7::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkRefObjDCA7
{
  public:
    virtual ~hkRefObjDCA7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkBufferDCA7 : public hkRefObjDCA7
{
  public:
    int unk08;
    hkArrayDCA7<char> m_data;

    virtual ~hkBufferDCA7() throw()
    {
        m_data.ClearAndRelease();
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDCA7::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkBufferDCA7*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDCA7* FUN_00dca750(unsigned int uiFlags) throw();
};

class hkMemoryAllocatorDCB7
{
  public:
    virtual ~hkMemoryAllocatorDCB7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCB7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCB7* m_pStreamAllocator;
    hkMemoryAllocatorDCB7& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCB7 {
extern "C" hkMemoryRouterDCB7& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDCB7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDCB7& kAlloc = hkRouterDCB7::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkRefObjDCB7
{
  public:
    virtual ~hkRefObjDCB7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkBufferDCB7 : public hkRefObjDCB7
{
  public:
    int unk08;
    hkArrayDCB7<__int64> m_data;

    virtual ~hkBufferDCB7() throw()
    {
        m_data.ClearAndRelease();
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDCB7::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkBufferDCB7*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDCB7* FUN_00dca7b0(unsigned int uiFlags) throw();
};

template <class T> class hkArrayDCAB
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDCAB() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkTypeRegistryDCAB
{
  public:
    void FUN_00dc8d70(void* pvHandleOut, int iType) throw();
};

struct hkTypeHandleDCAB
{
    int m_iOwnerObjectOffset;

    hkTypeHandleDCAB(hkTypeRegistryDCAB* pkRegistry, int iType)
    {
        pkRegistry->FUN_00dc8d70(this, iType);
    }
};

struct hkTypeOwnerDCAB
{
    int unk00;
    int unk04;
    hkTypeRegistryDCAB* m_registry;
};

class hkReferencedObjectDCAB
{
  public:
    hkReferencedObjectDCAB() : m_ulUserData(0)
    {
        m_sReferenceCount = 0;
    }
    virtual ~hkReferencedObjectDCAB() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_ulUserData;
};

class FUN_00dcabb0 : public hkReferencedObjectDCAB
{
  public:
    hkTypeOwnerDCAB* m_pOwnerObject;
    hkTypeHandleDCAB m_handle;
    int m_flags;
    int m_uiItemCount;
    hkArrayDCAB<int> m_entries;
    hkArrayDCAB<int> m_ppNames;
    hkArrayDCAB<int> m_iSlotIds;

    FUN_00dcabb0(hkTypeOwnerDCAB* pkOwner, int iType, int iFlags) throw();
    virtual ~FUN_00dcabb0() throw();
};

// Initializes the object with the owner, a type handle built from the owner's registry and type, the flags, and a zeroed field.
// @fnv 0x00dcabb0
FUN_00dcabb0::FUN_00dcabb0(hkTypeOwnerDCAB* pkOwner, int iType, int iFlags) throw()
    : m_pOwnerObject(pkOwner), m_handle(pkOwner->m_registry, iType), m_flags(iFlags), m_uiItemCount(0)
{}

namespace fnv_00dcac20 {
class FUN_00d47a80_class
{
  public:
    void* GetValue(void* pvObject, int iFlags);
    void* lookup(void* pvObject)
    {
        return pvObject ? GetValue(pvObject, 0) : 0;
    }
};

struct hkClassRefDCAC
{
    int unk00;
    int unk04;
    void* m_object;
};

struct hkEntryDCAC
{
    int m_key;
    hkClassRefDCAC* m_ref;
    int unk08;
    int unk0C;
    int m_uiFilterValue;
    int m_flags;
};

struct hkTrackerDCAC
{
    int unk00;
    int unk04;
    FUN_00d47a80_class* m_registry;
};

struct hkEntryOutDCAC;

class hkEntryTableDCAC
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkTrackerDCAC* m_pTracker;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    hkEntryDCAC* m_entries;

    void FUN_00dcac20(int iIndex, hkEntryOutDCAC& kOut);
};

struct hkEntryOutDCAC
{
    int m_key;
    hkEntryTableDCAC* m_table;
    int m_uiFilterValue;
    void* m_object;
    int m_flags;
};

}  // namespace fnv_00dcac20

namespace fnv_00dcad10 {
extern "C" void* FUN_00cb1410(const char* str);

struct MapTarget
{
    void* GetValue(const char* key, int zero);
    void FUN_00d874d0(void* key, void* val);
};

struct InnerContext
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
    MapTarget map;

    __forceinline void* Intern(const char* name)
    {
        if (name)
        {
            void* key = map.GetValue(name, 0);
            if (!key)
            {
                key = FUN_00cb1410(name);
                map.FUN_00d874d0(key, key);
            }
            return key;
        }
        return 0;
    }
};

}  // namespace fnv_00dcad10

namespace fnv_00dcae30 {
class FUN_00d47a80_class
{
  public:
    void* GetValue(void* pvObject, int iFlags);
    void* lookup(void* pvObject)
    {
        return pvObject ? GetValue(pvObject, 0) : 0;
    }
};

struct hkClassRefDCAE
{
    int unk00;
    int unk04;
    void* m_object;
};

struct hkEntryDCAE
{
    int m_key;
    hkClassRefDCAE* m_ref;
    int unk08;
    int unk0C;
    int m_uiFilterValue;
    int m_flags;
};

struct hkTrackerDCAE
{
    int unk00;
    int unk04;
    FUN_00d47a80_class* m_registry;
};

struct hkEntryOutDCAE;

class hkEntryTableDCAE
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual int getBaseIndex() const throw();

    int unk04;
    int unk08;
    hkTrackerDCAE* m_pTracker;
    int unk10;
    int unk14;
    const hkEntryTableDCAE* m_next;
    int unk1C;
    int unk20;
    int unk24;
    hkEntryDCAE* m_entries;
    int m_iEntryCount;

    void LookupEntry(int iKey, hkEntryOutDCAE& kOut) const;
};

struct hkEntryOutDCAE
{
    int m_key;
    const hkEntryTableDCAE* m_table;
    int m_uiFilterValue;
    void* m_object;
    int m_flags;
};

}  // namespace fnv_00dcae30

class hkAccessorDCB3
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual int getInt(int obj) throw();
};

struct hkMemberDCB3
{
    const char* m_name;
    hkAccessorDCB3* m_accessor;
};

class hkImplDCB3
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB3* m_members;

    int FUN_00dcb2b0(int iName) throw();
};

class hkObjDCB3
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB3* m_pClassImpl;
    int m_10;

    int GetMemberInt(int iName, int iUnused) throw();
};

// Looks up the member index by name in the implementation and returns the accessor's int value for m_10.
// @f3 0x00424580 (community match, verified in this file)
struct AccessorService {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Read(int value);
};
struct AccessorManager {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    AccessorService* service;
};
extern AccessorManager* DAT_0106ca70;
class NativeObj1420 {
public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int value;
    void FUN_00aa5a60(int first, int second);
};
// pdb: QueuedReplacementKFList::Cancel | ModelLoader.obj | fnv360_0822_retail, vtable, medium
// pdb params: aePreviousState, apTaskOwner
int hkObjDCB3::GetMemberInt(int first, int second) throw() {
    NativeObj1420* self=(NativeObj1420*)this;
    self->FUN_00aa5a60(first, second);
    return DAT_0106ca70->service->Read(self->value);
}


struct hkValueDCB4
{
    int m_00;
    int m_04;
    hkValueDCB4()
    {}
};

struct FUN_00dcb6c0_Target
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void FUN_00dcb650(int a, int b)
    {}
};

class hkObjectDCB8
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual int V19(int iOwner, int iArg0, int iArg1);
};

struct hkEntryDCB8
{
    int m_key;
    hkObjectDCB8* m_object;
};

struct hkTableDCB8
{
    int m_00;
    int m_04;
    int m_08;
    hkEntryDCB8* m_entries;

    int FUN_00dcb5d0(int iKey);
};

class hkOwnerDCB8
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB8* m_table;
    int m_10;

    int DispatchToEntryObject(int iKey, int iArg0, int iArg1);
};

// Looks up iKey in m_table and forwards iArg0/iArg1 to the entry object's V19 with m_10 as owner.
// @f3 0x008f69e0 (community match, verified in this file)
struct hkBlockHeaderK {
    int unk00;
    int m_size;
    int unk08;
    int unk0C;
};

struct hkOwnerViewDCB8 {
    virtual void V0();
    virtual void V1();
    virtual int V2(int iArg0, int iArg1, hkBlockHeaderK* pBlock, int iBlockSize, int iFlags);
};

// pdb: hkStatisticsCollector::getAllocatedSize | hkStatisticsCollector.obj | fnv360_0822_retail, call_dedup, low
// pdb params: p, size
int hkOwnerDCB8::DispatchToEntryObject(int iArg0, int iArg1, int iData)
{
    hkBlockHeaderK* pBlock = reinterpret_cast<hkBlockHeaderK*>(iData) - 1;
    return ((hkOwnerViewDCB8*)this)->V2(iArg0, iArg1, pBlock, pBlock->m_size + sizeof(hkBlockHeaderK), 0);
}


struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};

struct hkEntryDCB
{
    int m_key;
    int m_04;
    int m_uiFilterValue;
    int m_0c;
};

class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDCB* m_entries;

    hkResultDCB FUN_00dcba40(int iKey, int iType) throw();
    int FUN_00dcbc20(int iKey) throw();
};

// @f3 0x004ccb70 (community match, verified in this file)
namespace f3m_004ccb70 {
namespace f3m_004ccb70 {

struct Local50 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int index18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    int offset3c;
    int unk40, unk44, unk48, unk4c;
};

struct Table28 {
    int unk00, unk04, unk08, unk0c;
    char** rows10;
};

struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Table28* table28;

    bool FUN_004cb4f0(Local50* out, void* arg, int zero);
    char FUN_004ccb70(void* arg);
};

// pdb: TESObjectLAND::IsNormalSet | TESLand.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: TESObjectLAND::GetGeometry)
// pdb params: coord
char Owner::FUN_004ccb70(void* arg)
{
    Local50 local;
    if (!FUN_004cb4f0(&local, arg, 0))
        return 0;
    return table28->rows10[local.index18][local.offset3c];
}

}
}   // namespace f3m_004ccb70


namespace fnv_00dcbca0 {
struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};

struct hkEntryDCB
{
    int m_key;
    int m_04;
    int m_uiFilterValue;
    int m_0c;
};

class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDCB* m_entries;

    hkResultDCB FUN_00dcba40(int iKey, int iType) throw();
    int FUN_00dcbca0(int iKey) throw();
};

}  // namespace fnv_00dcbca0

namespace fnv_00dcbd10 {
struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};

struct hkEntryDCB
{
    int m_key;
    int m_04;
    float m_uiFilterValue;
    int m_0c;
};

class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDCB* m_entries;

    hkResultDCB FUN_00dcba40(int iKey, int iType) throw();
    float BSStripPSysData_GetPointLastUpdateTime(int iKey) throw();
};

}  // namespace fnv_00dcbd10

namespace fnv_00dcbfc0 {
class hkReferencedObject
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void removeReference();
};

struct hkAllocatorDCBF
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDCBF
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    hkAllocatorDCBF* m_pkHeap;
    hkAllocatorDCBF& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDCBF* __cdecl FUN_00c85750() throw();

template <typename T> struct hkRefPtrDCBF
{
    T* m_pRetainedObject;
    __forceinline ~hkRefPtrDCBF() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

template <typename T> __forceinline void destructDCBF(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <typename T> struct hkArrayDCBF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~hkArrayDCBF() throw()
    {
        hkAllocatorDCBF& kAlloc = FUN_00c85750()->heap();
        destructDCBF(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct EntryDCBF
{
    int m_00;
    hkRefPtrDCBF<hkReferencedObject> m_object;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

template <typename T> struct hkSharedPtrDCBF
{
    T* m_pRetainedObject;
    __forceinline ~hkSharedPtrDCBF() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->release();
        m_pRetainedObject = 0;
    }
};

class RefCountedDCBF
{
  public:
    virtual ~RefCountedDCBF() throw();
    int m_04;
    int m_iObjectReferenceCount;
    void release()
    {
        if (--m_iObjectReferenceCount == 0)
            delete this;
    }
};

class hkReferencedObjectDCBF
{
  public:
    virtual ~hkReferencedObjectDCBF() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00dcbfc0 : public hkReferencedObjectDCBF
{
  public:
    int m_08;
    int m_0c;
    hkRefPtrDCBF<hkReferencedObject> m_pOwnerObject;
    int m_14;
    hkSharedPtrDCBF<RefCountedDCBF> m_pSharedObject;
    hkArrayDCBF<int> m_auiHeaderValues;
    hkArrayDCBF<EntryDCBF> m_entriesA;
    hkArrayDCBF<EntryDCBF> m_entriesB;

    void ClearEntries() throw();
    virtual ~FUN_00dcbfc0() throw();
};

// @fnv 0x00dcbfc0
FUN_00dcbfc0::~FUN_00dcbfc0() throw()
{
    ClearEntries();
}
}  // namespace fnv_00dcbfc0

namespace fnv_00dcc100 {
class hkMemoryAllocatorDCC1
{
  public:
    virtual ~hkMemoryAllocatorDCC1() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCC1
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCC1* m_pStreamAllocator;
    hkMemoryAllocatorDCC1& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCC1& __cdecl FUN_00c85750();

class FUN_00dcbfc0
{
  public:
    virtual ~FUN_00dcbfc0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00dcbfc0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00dcbfc0* DestroyAndFree(unsigned int uiFlags) throw();
};

}  // namespace fnv_00dcc100

char* __cdecl StrDup7320(const char* pcString);

struct StringMap7320
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct Registry7320
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
    StringMap7320 m_kNodePool;

    void Rename(const char* pcOldName, const char* pcNewName);
    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDup7320(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct Memory7DE0
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct Context7DE0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Memory7DE0* m_pkMemory;
};
Context7DE0* GetContext7DE0();

struct Shape7DE0
{
    Shape7DE0() throw() : m_usFlags(0), m_iRefCount(0)
    {}
    virtual ~Shape7DE0();
    static __forceinline void* operator new(unsigned int nbytes) throw()
    {
        Context7DE0* pkContext = GetContext7DE0();
        Shape7DE0* pkShape = static_cast<Shape7DE0*>(pkContext->m_pkMemory->allocateChunk(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void AddRef()
    {
        m_iRefCount++;
    }
    unsigned short m_usMemSize;
    unsigned short m_usFlags;
    int m_iRefCount;
};
struct Container7DE0
{
    Container7DE0() throw() : m_usFlags(0), m_iArrayLength(0)
    {}
    virtual ~Container7DE0();
    unsigned short m_usSize;
    unsigned short m_usFlags;
    int m_iArrayLength;
    void* m_pkOwnerManager;
    void AddOwner(void* pkOwner)
    {
        m_iArrayLength++;
        m_pkOwnerManager = pkOwner;
    }
};
struct Wrapper7DE0 : public Shape7DE0
{
    __forceinline Wrapper7DE0(Shape7DE0* pkChild, int iData) throw() : m_pkChild(pkChild)
    {
        int one = 1;
        m_iData = iData;
        pkChild->m_iRefCount += one;
        m_kContainer.m_iArrayLength += one;
        m_kContainer.m_pkOwnerManager = this;
    }
    Container7DE0 m_kContainer;
    int unk1C;
    Shape7DE0* m_pkChild;
    volatile int m_iData;
};

class hkObjDC82
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void setTarget(void* target);
};

hkObjDC82* __cdecl FUN_00dc7de0(unsigned int flags, void* type, void* owner);

class hkMemoryAllocatorDC8C
{
  public:
    virtual ~hkMemoryAllocatorDC8C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC8C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC8C* m_pStreamAllocator;

    hkMemoryAllocatorDC8C& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDC8C {
extern "C" hkMemoryRouterDC8C& __cdecl FUN_00c85750() throw();
}

class hkBaseObjDC8C
{
  public:
    virtual ~hkBaseObjDC8C() throw()
    {}
};

class hkRefObjDC8C : public hkBaseObjDC8C
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~hkRefObjDC8C() throw()
    {}

    static void operator delete(void* p)
    {
        hkRouterDC8C::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkRefObjDC8C*>(p)->m_usMemSizeAndFlags);
    }
};

class hkSharedDC8C
{
  public:
    virtual void deleteThis(int flags) throw();
    int unk04;
    int m_uiItemCount;

    void release() throw()
    {
        if (--m_uiItemCount == 0)
            deleteThis(1);
    }
};

class hkMemberDC8C : public hkBaseObjDC8C
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class hkObjDC8C : public hkRefObjDC8C
{
  public:
    int unk08;
    hkMemberDC8C m_kMemberDescriptor;
    hkSharedDC8C* m_pSharedObject;

    virtual ~hkObjDC8C() throw()
    {
        m_pSharedObject->release();
    }

    hkObjDC8C* FUN_00dc8cd0(unsigned int flags);
};

// Calls the hkObjDC8C destructor and, when the low bit of flags is set, frees the object via operator delete, then returns this.
// @f3 0x0097e300 (community match, verified in this file)
extern int DAT_0126908c;
extern int _DAT_0102e388;
extern int vtable_hkBaseDC8C;
extern unsigned int DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct hkSharedRef300
{
    unsigned short m_usFlags;
    short m_usItemCount;

    virtual void deleteThis(int flags);
};

class hkAllocator300
{
  public:
    void FUN_008f6d90(void* block, unsigned int size, unsigned int tag);
};

// hkObjDC8C seen with its real member layout: a one-pointer member descriptor at +0x10 and the shared object at +0x14
struct hkObjLayout300
{
    void* m_pVtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08;
    int unk0C;
    void* m_pMemberVtbl;
    hkSharedRef300* m_pSharedObject;
};

// pdb: hkpTransformShape::`scalar deleting destructor' | hkpTransformShape.obj | fnv360_0822_retail, objrun_open, low
hkObjDC8C* hkObjDC8C::FUN_00dc8cd0(unsigned int flags)
{
    hkObjLayout300* self = reinterpret_cast<hkObjLayout300*>(this);
    hkSharedRef300* pShared = self->m_pSharedObject;
    self->m_pMemberVtbl = &DAT_0126908c;
    if (pShared->m_usFlags != 0)
    {
        if (--pShared->m_usItemCount == 0)
            pShared->deleteThis(1);
    }
    self->m_pMemberVtbl = &vtable_hkBaseDC8C;
    self->m_pVtbl = &_DAT_0102e388;
    if (flags & 1)
    {
        hkAllocator300* alloc = (hkAllocator300*)TlsGetValue(DAT_010f3170);
        alloc->FUN_008f6d90(this, m_usMemSizeAndFlags, 0x27);
    }
    return this;
}


char* __cdecl FUN_00cb1410(const char* pcString);

struct StringMapDC8F20
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void remove(const char* pcKey);
    void insert(const char* pcKey, void* pvValue);

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_flags;
};

struct NameRegistryDC8F20
{
    StringMapDC8F20 m_iSlotIds;
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
    StringMapDC8F20 m_kNodePool;
    StringMapDC8F20 m_entries;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = FUN_00cb1410(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
    void FUN_00dc8f20(const char* pcOldName, const char* pcNewName);
};

void __cdecl ReleaseDataValues(void* type, __int64* value, int count);

class hkMemoryAllocatorDC92;

struct hkMemoryRouterDC92
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC92* m_pStreamAllocator;
};

namespace hkRouterDC92 {
extern "C" hkMemoryRouterDC92& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolDC92
{
    char m_cBooleanValue;
    hkBoolDC92()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyDC92(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayDC92
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterDC92& router = hkRouterDC92::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyDC92<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

class hkMapDC92
{
  public:
    int FUN_00d87410();
    char* SetBoolFromThreshold(char* out, int it);
    bool isValid(int it)
    {
        char valid;
        SetBoolFromThreshold(&valid, it);
        return valid != 0;
    }
    int FUN_00d87440(int it);
    int FindNextUsedSlot(int it);

    void FUN_00dc9240(hkArrayDC92<int>& out);
};

template <typename T> struct hkArrayDC9
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct OwnerDC9;
template <class T> struct MultiMapDC9
{
    struct Entry
    {
        T m_kValue;
        int m_iNext;
    };
    int Find(OwnerDC9* pkOwner);
    Entry* m_pkEntryArray;
};

char* __cdecl StrDup9570(const char* pcString);

struct StringMap9570
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct Registry9570
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
    StringMap9570 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDup9570(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct PooledName9570
{
    PooledName9570(const char* pcName)
    {
        m_pcName = pcName;
    }
    const char* m_pcName;
};

class hkMemoryAllocatorDC9E;

struct hkMemoryRouterDC9E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9E* m_pStreamAllocator;

    hkMemoryAllocatorDC9E& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDC9E {
extern "C" hkMemoryRouterDC9E& __cdecl FUN_00c85750() throw();
}

class hkMapDC9E
{
  public:
    unsigned long LookupHashEntry(unsigned long key, unsigned long def);
    void FUN_00cb1870(hkMemoryAllocatorDC9E& alloc, unsigned long key, unsigned long val);
    int unk00[2];
};

struct KeyDC9E
{
    unsigned long m_iOwnerObjectOffset;
};

struct EntryDC9E
{
    unsigned long m_iOwnerObjectOffset;
    unsigned long m_next;
};

class OwnerDC9E
{
  public:
    EntryDC9E* m_pEntries;
    int unk04[2];
    hkMapDC9E m_kFormatEntries;

    int AllocateSlot();
    void FUN_00dc9ec0(unsigned long key, const KeyDC9E* pkVal);
};

// Looks up an existing entry for key, allocates a slot, links the new entry to the old one, and stores the slot index in m_kFormatEntries.
// @f3 0x00a480b0 (community match, verified in this file)
struct OwnerStub_00a2a180
{
    int FUN_00a2a180();
};

struct MapStub_00922710
{
    void FUN_00922710(unsigned long key, unsigned long val);
};

void OwnerDC9E::FUN_00dc9ec0(unsigned long key, const KeyDC9E* pkVal)
{
    unsigned long uiOldIndex = m_kFormatEntries.LookupHashEntry(key, (unsigned long)-1);
    int iNewIndex = reinterpret_cast<OwnerStub_00a2a180*>(this)->FUN_00a2a180();
    EntryDC9E& kEntry = m_pEntries[iNewIndex];
    kEntry.m_iOwnerObjectOffset = pkVal->m_iOwnerObjectOffset;
    kEntry.m_next = uiOldIndex;
    reinterpret_cast<MapStub_00922710*>(&m_kFormatEntries)->FUN_00922710(key, iNewIndex);
}


extern "C" void _ReadWriteBarrier(void);

class hkMemoryAllocatorDCA5;

struct hkMemoryRouterDCA5
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA5* m_pTemp;
    hkMemoryAllocatorDCA5* m_pStreamAllocator;
    hkMemoryAllocatorDCA5& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterDCA5& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA5& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayDCA5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA5& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(fnvc_adapt::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

struct Find
{
    char* SetBoolFromThreshold(char*, int);
};

struct DCAAObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* GetIteratorKey();
};
struct DCAAMapEntry
{
    DCAAObject* value;
    int next;
};
struct DCAAMap
{
    DCAAMapEntry* entries;
    int __thiscall LookupWithDefault(void* key);
    void __thiscall FUN_00dcb4b0(void* key, int index);
    void __thiscall FUN_00dc9ec0(void* key, DCAAObject** value);
};
struct DCAAOwner
{
    int unk00, unk04, unk08, unk0c;
    DCAAMap table;
    void __thiscall FUN_00dcaaf0(void* volatile key, DCAAObject* object);
};
// If key is non-null, removes a matching entry; if GetIteratorKey returns non-null, inserts the object under that key.
// @f3 0x00a480f0 (community match, verified in this file)
struct DCAAObjectF3
{
    void* m_pKey;
};
struct DCAAMapEntryF3
{
    DCAAObjectF3* value;
    int next;
};
struct DCAAMapF3
{
    DCAAMapEntryF3* entries;
    int __thiscall FUN_00a47f40(void* key);
    void __thiscall FUN_00a2a1d0(void* key, int index);
    void __thiscall FUN_00a480b0(void* key, DCAAObject** value);
};
struct DCAAOwnerF3
{
    int unk00, unk04, unk08;
    DCAAMapF3 table;
};
void __thiscall DCAAOwner::FUN_00dcaaf0(void* volatile key, DCAAObject* object)
{
    DCAAObjectF3* pObject = *(DCAAObjectF3* volatile*)&object;
    void* k = pObject->m_pKey;
    if (k)
    {
        DCAAMapF3& table = ((DCAAOwnerF3*)this)->table;
        int index = table.FUN_00a47f40(k);
        while (index != -1)
        {
            if (table.entries[index].value == pObject)
            {
                if (*(void**)&key == k)
                    return;
                table.FUN_00a2a1d0(k, index);
                break;
            }
            index = table.entries[index].next;
        }
    }
    k = key;
    if (k)
        ((DCAAOwnerF3*)this)->table.FUN_00a480b0(k, &object);
    pObject->m_pKey = k;
}


char* __cdecl StrDupDCAC(const char* pcString);

struct hkBoolDCAC
{
    hkBoolDCAC(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

struct StringMapDCAC
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct RegistryDCAC
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
    StringMapDCAC m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupDCAC(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

char* __cdecl StrDupADA0(const char* pcString);

struct StringMapADA0
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct RegistryADA0
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
    StringMapADA0 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupADA0(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct RegistryHolderADA0
{
    int unk00;
    int unk04;
    RegistryADA0* m_pkRegistry;
};

struct MemberADA0
{
    const char* m_pcName;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

class ClassADA0
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int GetNumDeclaredOffset() const;
    virtual void v1c();
    virtual void v20();
    virtual int GetMemberBase() const;
    int FUN_00dcada0(const char* pcName) const;

    int unk04;
    int unk08;
    RegistryHolderADA0* m_pkHolder;
    int unk10;
    int unk14;
    const ClassADA0* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    MemberADA0* m_pkMembers;
    int m_iNumMembers;
};

// Searches the class hierarchy for a member by name and returns its computed index, or -1 if not found.
// @f3 0x006f8e30 (community match, verified in this file)
struct Node_006f8e30 { int unk00, unk04, unk08, unk0c, unk10, unk14; Node_006f8e30* parent; };
struct Holder_006f8e30 {
    virtual void h000();
    virtual void h004();
    virtual void h008();
    virtual void h00c();
    virtual void h010();
    virtual void h014();
    virtual void h018();
    virtual void h01c();
    virtual void h020();
    virtual void h024();
    virtual void h028();
    virtual void h02c();
    virtual void h030();
    virtual void h034();
    virtual void h038();
    virtual void h03c();
    virtual void h040();
    virtual void h044();
    virtual void h048();
    virtual void h04c();
    virtual void h050();
    virtual void h054();
    virtual void h058();
    virtual void h05c();
    virtual void h060();
    virtual void h064();
    virtual void h068();
    virtual void h06c();
    virtual void h070();
    virtual void h074();
    virtual void h078();
    virtual void h07c();
    virtual void h080();
    virtual void h084();
    virtual void h088();
    virtual void h08c();
    virtual void h090();
    virtual void h094();
    virtual void h098();
    virtual void h09c();
    virtual void h0a0();
    virtual void h0a4();
    virtual void h0a8();
    virtual void h0ac();
    virtual void h0b0();
    virtual void h0b4();
    virtual void h0b8();
    virtual void h0bc();
    virtual void h0c0();
    virtual void h0c4();
    virtual void h0c8();
    virtual void h0cc();
    virtual void h0d0();
    virtual void h0d4();
    virtual void h0d8();
    virtual void h0dc();
    virtual void h0e0();
    virtual void h0e4();
    virtual void h0e8();
    virtual void h0ec();
    virtual void h0f0();
    virtual void h0f4();
    virtual void h0f8();
    virtual void h0fc();
    virtual void h100();
    virtual void h104();
    virtual void h108();
    virtual void h10c();
    virtual void h110();
    virtual void h114();
    virtual void h118();
    virtual void h11c();
    virtual void h120();
    virtual void h124();
    virtual void h128();
    virtual void h12c();
    virtual void h130();
    virtual void h134();
    virtual void h138();
    virtual void h13c();
    virtual void h140();
    virtual void h144();
    virtual void h148();
    virtual void h14c();
    virtual void h150();
    virtual void h154();
    virtual void h158();
    virtual void h15c();
    virtual void h160();
    virtual void h164();
    virtual void h168();
    virtual void h16c();
    virtual void h170();
    virtual void h174();
    virtual void h178();
    virtual void h17c();
    virtual void h180();
    virtual void h184();
    virtual void h188();
    virtual void h18c();
    virtual Node_006f8e30* Lookup(int key);
    virtual void h194();
    virtual void h198();
    virtual void h19c();
    virtual void h1a0();
    virtual void h1a4();
    virtual void h1a8();
    virtual void h1ac();
    virtual void h1b0();
    virtual void h1b4();
    virtual void h1b8();
    virtual void h1bc();
    virtual void h1c0();
    virtual void h1c4();
    virtual void h1c8();
    virtual void h1cc();
    virtual void h1d0();
    virtual void h1d4();
    virtual void h1d8();
    virtual void h1dc();
    virtual void h1e0();
    virtual void h1e4();
    virtual void h1e8();
    virtual void h1ec();
    virtual void h1f0();
    virtual void h1f4();
    virtual void h1f8();
    virtual void h1fc();
    virtual void h200();
    virtual void h204();
    virtual void h208();
    virtual void h20c();
    virtual void h210();
    virtual void h214();
    virtual void h218();
    virtual void h21c();
    virtual void h220();
    virtual void h224();
    virtual void h228();
    virtual void h22c();
    virtual void h230();
    virtual void h234();
    virtual void h238();
    virtual void h23c();
    virtual void h240();
    virtual void h244();
    virtual void h248();
    virtual void h24c();
    virtual void h250();
    virtual void h254();
    virtual void h258();
    virtual void h25c();
    virtual void h260();
    virtual void h264();
    virtual void h268();
    virtual void h26c();
    virtual void h270();
    virtual void h274();
    virtual void h278();
    virtual void h27c();
    virtual void h280();
    virtual void h284();
    virtual void h288();
    virtual void h28c();
    virtual void h290();
    virtual void h294();
    virtual void h298();
    virtual void h29c();
    virtual void h2a0();
    virtual void h2a4();
    virtual void h2a8();
    virtual void h2ac();
    virtual void h2b0();
    virtual void h2b4();
    virtual void h2b8();
    virtual void h2bc();
    virtual void h2c0();
    virtual void h2c4();
    virtual void h2c8();
    virtual void h2cc();
    virtual void h2d0();
    virtual void h2d4();
    virtual void h2d8();
    virtual void h2dc();
    virtual void h2e0();
    virtual void h2e4();
    virtual void h2e8();
    virtual void h2ec();
    virtual void h2f0();
    virtual void h2f4();
    virtual void h2f8();
    virtual void h2fc();
    virtual void h300();
    virtual void h304();
    virtual void h308();
    virtual void h30c();
    virtual void h310();
    virtual void h314();
    virtual void h318();
    virtual void h31c();
    virtual void h320();
    virtual void h324();
    virtual void h328();
    virtual void h32c();
    virtual void h330();
    virtual void h334();
    virtual void h338();
    virtual void h33c();
    virtual void h340();
    virtual void h344();
    virtual void h348();
    virtual void h34c();
    virtual void h350();
    virtual void h354();
    virtual void h358();
    virtual void h35c();
    virtual void h360();
    virtual void h364();
    virtual void h368();
    virtual void h36c();
    virtual void h370();
    virtual void h374();
    virtual void h378();
    virtual void h37c();
    virtual void h380();
    virtual void h384();
    virtual void h388();
    virtual void h38c();
    virtual void h390();
    virtual void h394();
    virtual void h398();
    virtual void h39c();
    virtual void h3a0();
    virtual void h3a4();
    virtual void h3a8();
    virtual void h3ac();
    virtual void h3b0();
    virtual void h3b4();
    virtual void h3b8();
    virtual void h3bc();
    virtual void h3c0();
    virtual void h3c4();
    virtual void h3c8();
    virtual void h3cc();
    virtual void h3d0();
    virtual void h3d4();
    virtual void h3d8();
    virtual void h3dc();
    virtual void h3e0();
    virtual void h3e4();
    virtual void h3e8();
    virtual void h3ec();
    virtual void h3f0();
    virtual void h3f4();
    virtual void h3f8();
    virtual void h3fc();
    virtual void h400();
    virtual void h404();
    virtual void h408();
    virtual void h40c();
    virtual void h410();
    virtual void h414();
    virtual void h418();
    virtual void h41c();
    virtual void h420();
    virtual void h424();
    virtual void h428();
    virtual void h42c();
    virtual void h430();
    virtual void h434();
    virtual void h438();
    virtual void h43c();
    virtual void h440();
    virtual void h444();
    virtual void h448();
    virtual void h44c();
    virtual void h450();
    virtual void h454();
    virtual void h458();
    virtual void h45c();
    virtual void h460();
    virtual void h464();
    virtual void h468();
    virtual void h46c();
    virtual void h470();
    virtual void h474();
    virtual void h478();
    virtual void h47c();
    virtual void h480();
    virtual void h484();
    virtual void h488();
    virtual void h48c();
    virtual void h490();
    virtual void h494();
    virtual void h498();
    virtual void h49c();
    virtual void h4a0();
    virtual void h4a4();
    virtual void h4a8();
    virtual void h4ac();
    virtual void h4b0();
    virtual void h4b4();
    virtual void h4b8();
    virtual void h4bc();
    virtual void h4c0();
    virtual void h4c4();
    virtual void h4c8();
    virtual void h4cc();
    virtual void h4d0();
    virtual void h4d4();
    virtual void h4d8();
    virtual void h4dc();
    virtual void h4e0();
    virtual void h4e4();
    virtual void h4e8();
    virtual void h4ec();
    virtual void h4f0();
    virtual void h4f4();
    virtual void h4f8();
    virtual void h4fc();
    virtual void h500();
    virtual void h504();
    virtual void h508();
    virtual void h50c();
    virtual void h510();
    virtual void h514();
    virtual void h518();
    virtual void h51c();
    virtual void h520();
    virtual void h524();
    virtual void h528();
    virtual void h52c();
    virtual void h530();
    virtual void h534();
    virtual void h538();
    virtual void h53c();
    virtual void h540();
    virtual void h544();
    virtual void h548();
    virtual void h54c();
    virtual void h550();
    virtual void h554();
    virtual void h558();
    virtual void h55c();
    virtual void h560();
    virtual void h564();
    virtual void h568();
    virtual void h56c();
    virtual void h570();
    virtual void h574();
    virtual void h578();
    virtual void h57c();
    virtual void h580();
    virtual void h584();
    virtual void h588();
    virtual void h58c();
    virtual void h590();
    virtual void h594();
    virtual void h598();
    virtual void h59c();
    virtual void h5a0();
    virtual void h5a4();
    virtual void h5a8();
    virtual void h5ac();
    virtual void h5b0();
    virtual void h5b4();
    virtual void h5b8();
    virtual void h5bc();
    virtual void h5c0();
    virtual void h5c4();
    virtual void h5c8();
    virtual void h5cc();
    virtual void h5d0();
    virtual void h5d4();
    virtual void h5d8();
    virtual void h5dc();
    virtual void h5e0();
    virtual void h5e4();
    virtual void h5e8();
    virtual void h5ec();
    virtual void h5f0();
    virtual void h5f4();
    virtual void h5f8();
    virtual void h5fc();
    virtual void h600();
    virtual void h604();
    virtual void h608();
    virtual void h60c();
    virtual void h610();
    virtual void h614();
    virtual void h618();
    virtual void h61c();
    virtual void h620();
    virtual void h624();
    virtual void h628();
    virtual void h62c();
    virtual void h630();
    virtual void h634();
    virtual void h638();
    virtual void h63c();
    virtual void h640();
    virtual void h644();
    virtual void h648();
    virtual void h64c();
    virtual void h650();
    virtual void h654();
    virtual void h658();
    virtual void h65c();
    virtual void h660();
    virtual void h664();
    virtual void h668();
    virtual void h66c();
    virtual void h670();
    virtual void h674();
    virtual void h678();
    virtual void h67c();
    virtual void h680();
    virtual void h684();
    virtual void h688();
    virtual void h68c();
    virtual void h690();
    virtual void h694();
    virtual void h698();
    virtual void h69c();
    virtual void h6a0();
    virtual void h6a4();
    virtual void h6a8();
    virtual void h6ac();
    virtual void h6b0();
    virtual void h6b4();
    virtual void h6b8();
    virtual void h6bc();
    virtual void h6c0();
    virtual void h6c4();
    virtual Node_006f8e30* GetSlot(int index);
};
struct Self_006f8e30 {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Node_006f8e30* GetRoot() const;
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual int GetKey() const;
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
    Holder_006f8e30* m_pkHolder;
};

// pdb: Actor::GetDamageLocation | Actor.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apNode
int ClassADA0::FUN_00dcada0(const char* pcName) const
{
    const Self_006f8e30* self = (const Self_006f8e30*)this;
    Node_006f8e30* node = (Node_006f8e30*)pcName;
    if (node && self->m_pkHolder) {
        Node_006f8e30* root = self->GetRoot();
        Node_006f8e30* top = self->m_pkHolder->Lookup(self->GetKey());
        do {
            if (node == root)
                break;
            if (node->parent == top)
                return 14;
            for (int i = 0; i < 15; ++i) {
                if (self->m_pkHolder->GetSlot(i) == node)
                    return i;
            }
            node = node->parent;
        } while (node);
    }
    return -1;
}


char* __cdecl StrDupB2B0(const char* pcString);

struct StringMapB2B0
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct RegistryB2B0
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
    StringMapB2B0 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupB2B0(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct HeapDCB990
{
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p, int nbytes) throw();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct RouterDCB990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HeapDCB990* m_pkHeap;
};
RouterDCB990* GetRouterDCB990() throw();
struct ReferencedDCB990
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
template <class T> struct RefPtrDCB990
{
    ~RefPtrDCB990() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(T* e) throw()
    {
        if (e)
            e->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};
template <class T> __forceinline void DestructDCB990(T* t, int n) throw()
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <class T> struct ArrayDCB990
{
    __forceinline void clear() throw()
    {
        DestructDCB990(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease() throw()
    {
        RouterDCB990* pkRouter = GetRouterDCB990();
        HeapDCB990& kHeap = *pkRouter->m_pkHeap;
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct EntryDCB990
{
    int unk00;
    RefPtrDCB990<ReferencedDCB990> m_spShape;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct PairDCB990
{
    int m_iA;
    int m_iB;
};
struct ObjectDCB990
{
    __forceinline ~ObjectDCB990() throw()
    {
        m_kPairs.ClearAndRelease();
    }
    static void operator delete(void* p, unsigned int nbytes) throw()
    {
        RouterDCB990* pkRouter = GetRouterDCB990();
        pkRouter->m_pkHeap->ReleaseBlock(p, (int)nbytes);
    }
    int unk00;
    ArrayDCB990<PairDCB990> m_kPairs;
};
extern ReferencedDCB990 g_kDefaultDCB990;
struct ContainerDCB990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    RefPtrDCB990<ReferencedDCB990> m_spDefault;
    int unk14;
    int unk18;
    ArrayDCB990<ObjectDCB990*> m_kThirdFollowingStreamField;
    ArrayDCB990<EntryDCB990> m_kEntries;
    void ClearEntries();
};

// Clears m_kEntries, deletes each ObjectDCB990 in m_kThirdFollowingStreamField, and resets m_spDefault to g_kDefaultDCB990.
// @fnv 0x00dcb990
void ContainerDCB990::ClearEntries()
{
    m_kEntries.clear();
    for (int i = 0; i < m_kThirdFollowingStreamField.m_iElementCount; i++)
        delete m_kThirdFollowingStreamField.m_data[i];
    m_kThirdFollowingStreamField.m_iElementCount = 0;
    m_spDefault = &g_kDefaultDCB990;
}

template <typename T> struct hkArrayDC7
{
    hkArrayDC7() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayDC7()
    {
        hkAllocatorDC76& kAlloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct StringMapDC7
{
    void* GetValue(const char* pcKey, void* pvDefault) const;
    void FUN_00d874d0(const char* pcKey, void* pvValue) throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct hkDataObjectDictDC7;
struct hkDataArrayDictDC7;
struct hkDataClassDictDC7;

struct RegistryDC7
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
    StringMapDC7 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.GetValue(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = FUN_00cb1410(pcName);
            m_kNodePool.FUN_00d874d0(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
    void CollectShapes(const char* pcName, int iRecurse, int iFlags,
                       hkArrayDC7<hkDataObjectDictDC7*>& kObjectsOut) throw();
    void FUN_00dc9180(hkDataClassDictDC7* pkClass, int iRecurse, hkArrayDC7<hkDataArrayDictDC7*>& kArraysOut) throw();
};

struct ObjectMemberDC7
{
    const char* m_name;
    unsigned int m_type;
    unsigned int m_value0;
    unsigned int m_value1;
};
struct hkDataObjectDictDC7
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkArrayDC7<ObjectMemberDC7> m_members;
};

struct ArrayMemberDC7
{
    const char* m_name;
    unsigned int m_uiFilterValue;
};
struct hkDataArrayDictDC7
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    hkArrayDC7<ArrayMemberDC7> m_members;
};

struct ClassMemberDC7
{
    const char* m_name;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};
struct hkDataClassDictDC7
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
    hkArrayDC7<ClassMemberDC7> m_memberDecls;
    int findMemberDecl(const char* pcName) const throw()
    {
        for (int i = m_memberDecls.m_iElementCount - 1; i >= 0; i--)
        {
            if (m_memberDecls.m_data[i].m_name == pcName)
                return i;
        }
        return -1;
    }
};

extern int DAT_010d6ee4;

struct Mem_dc7c
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int nbytes) throw();
};
struct Router_dc7c
{
    int unk00, unk04, unk08, unk0C;
    Mem_dc7c* m_pStreamAllocator;
    Mem_dc7c& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_dc7c& __cdecl FUN_00c85750() throw();
};

struct RefCounted_dc7c
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_flags;
    int m_sReferenceCount;
    void RetainReference()
    {
        ++m_sReferenceCount;
    }
};

struct Node_dc7c : RefCounted_dc7c
{
    RefCounted_dc7c* m_parent;
    void* volatile m_data;
    int m_iElementCount;
    int m_iCapacityState;
    static void* operator new(unsigned int nbytes) throw()
    {
        Node_dc7c* p = (Node_dc7c*)Router_dc7c::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Node_dc7c(RefCounted_dc7c* parent) throw()
    {
        m_flags = 0;
        m_sReferenceCount = 0;
        m_vtbl = &DAT_010d6ee4;
        if (parent)
            parent->RetainReference();
        m_parent = parent;
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    const char* getName()
    {
        return ((const char*(__thiscall*)(Node_dc7c*))((void**)m_vtbl)[2])(this);
    }
};

struct Alloc_dc8d
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

class RefObj_dc8d
{
  public:
    virtual ~RefObj_dc8d();
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

extern RefObj_dc8d DAT_011b7c00;
extern int DAT_010d6da0;

struct StringPtr_dc8d
{
    const char* m_kStringBuffer;
};

class DataType_dc8d : public RefObj_dc8d
{
  public:
    const char* m_name;
};

struct Map_dc8d
{
    void* GetValue(const char* name, const void* value) throw();
    void FUN_00d874d0(const char* name, void* value) throw();
};

struct RegistryLayout_dc8d
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
    Map_dc8d m_map;
};

struct RegistryImpl_dc8d
{
    StringPtr_dc8d* GetPooledString(StringPtr_dc8d* out, const char* name) throw();
};

struct Registry_dc8d
{
    void* FUN_00dc8d70(void* pvHandleOut, int iType) throw();
};

// For a nonzero type-name pointer, looks up or creates a registry entry and stores it in pvHandleOut.
// @fnv 0x00dc8d70
void* Registry_dc8d::FUN_00dc8d70(void* pvDataTypeOut, int pcTypeName) throw()
{
    RegistryLayout_dc8d* registry = reinterpret_cast<RegistryLayout_dc8d*>(this);
    RegistryImpl_dc8d* impl = reinterpret_cast<RegistryImpl_dc8d*>(this);

    *(void**)pvDataTypeOut = 0;
    DAT_011b7c00.FUN_00c90510();
    if (*(void**)pvDataTypeOut != 0)
        reinterpret_cast<RefObj_dc8d*>(*(void**)pvDataTypeOut)->FUN_00c905b0();

    *(void**)pvDataTypeOut = &DAT_011b7c00;

    if (pcTypeName != 0)
    {
        const char* name = reinterpret_cast<const char*>(pcTypeName);
        void* found = registry->m_map.GetValue(name, 0);

        if (found == 0)
        {
            hkMemoryRouterDC76* router = FUN_00c85750();
            Alloc_dc8d* allocator = *reinterpret_cast<Alloc_dc8d**>(reinterpret_cast<char*>(router) + 0x10);

            DataType_dc8d* dataType = reinterpret_cast<DataType_dc8d*>(allocator->AllocateMemoryBlock(12));

            StringPtr_dc8d local;
            dataType->m_usMemSizeAndFlags = 12;
            StringPtr_dc8d* result = impl->GetPooledString(&local, name);

            dataType->m_sReferenceCount = 1;
            *reinterpret_cast<void**>(dataType) = &DAT_010d6da0;

            const char* typeName = result->m_kStringBuffer;
            dataType->m_name = typeName;
            registry->m_map.FUN_00d874d0(typeName, dataType);
            found = dataType;
        }

        RefObj_dc8d* object = reinterpret_cast<RefObj_dc8d*>(found);
        object->FUN_00c90510();
        if (*(void**)pvDataTypeOut != 0)
            reinterpret_cast<RefObj_dc8d*>(*(void**)pvDataTypeOut)->FUN_00c905b0();
        *(void**)pvDataTypeOut = found;
        return pvDataTypeOut;
    }

    return pvDataTypeOut;
}

struct hkRefObj_dc8e
{
    virtual void deleteThis(int flags);
    int unk04;
    int m_sReferenceCount;
    void removeReference()
    {
        if (--m_sReferenceCount == 0)
            deleteThis(1);
    }
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}
void __cdecl ResizeAudioStream(hkAllocatorDC76* alloc, void* array, int sizeOfElement);

template <class T> struct hkArray_dc91
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        hkMemoryRouterDC76* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pkHeap, this, sizeof(T));
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};

typedef unsigned int hkUint32;
typedef unsigned __int64 hkUint64;

class hkReferencedObject
{
  public:
    void removeReference();
};

template <class T> struct hkRefPtrT
{
    T* m_pRetainedObject;
    __forceinline ~hkRefPtrT()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct MemberInfoDC
{
    const char* m_name;
    hkRefPtrT<hkReferencedObject> m_pOwnerObject;
    int m_type;
    int m_tuple;
    int m_class;
    int m_uiFormID;
};

__forceinline void memCpyDC(void* dst, const void* src, int nbytes)
{
    char* d = static_cast<char*>(dst);
    const char* s = static_cast<const char*>(src);
    for (int i = 0; i < nbytes; i += 8)
    {
        *reinterpret_cast<hkUint64*>(d + i) = *reinterpret_cast<const hkUint64*>(s + i);
    }
}

template <class T> __forceinline void destructDC(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <class T> struct hkArrDC
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void removeAtAndCopy(int index)
    {
        destructDC(m_data + index, 1);
        m_iElementCount--;
        memCpyDC(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
    }
};

class ClassDictDC
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ClassDictDC* m_parent;
    int unk1C;
    int unk20;
    int unk24;
    hkArrDC<MemberInfoDC> m_members;

    MemberInfoDC* FindEntry(const char* name);
    __forceinline int FindMemberIndex(const char* name) const
    {
        for (int i = m_members.m_iElementCount - 1; i >= 0; --i)
        {
            if (m_members.m_data[i].m_name == name)
                return i;
        }
        return -1;
    }
    int FUN_00dc9470(const char* name);
};

void __cdecl FUN_00cb1260(void*, void const*, int);

namespace fnv_00dc9f20 {
struct RefObjX
{
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
};
extern RefObjX DAT_011b7c00;

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct RefPtrX
{
    RefObjX* m_pRetainedObject;
    RefPtrX() throw()
    {}
    RefPtrX(const RefPtrX& o) throw()
    {
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    __forceinline void set(const RefPtrX& o) throw()
    {
        DAT_011b7c00.FUN_00c90510();
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        DAT_011b7c00.FUN_00c905b0();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~RefPtrX() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
};

struct PairX
{
    union
    {
        int x;
        volatile int init;
    };
    int y;
};
struct KeyX
{
    int v;
};
struct InfoX
{
    PairX m_08;
    int m_10;
    int m_14;
};
struct EntryX
{
    EntryX(const EntryX& o) throw() : m_key(o.m_key), m_ref(o.m_ref)
    {
        m_info.m_08 = o.m_info.m_08;
        m_info.m_10 = o.m_info.m_10;
        m_info.m_14 = o.m_info.m_14;
    }

    KeyX m_key;
    RefPtrX m_ref;
    InfoX m_info;
    __forceinline EntryX() throw()
    {
        m_info.m_08.init = 0;
        m_info.m_08.x = 0;
        m_info.m_08.y = 0;
    }
};

template <class T> struct ArrayX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void AddBack(const T& e) throw()
    {
        hkMemoryRouterDC76* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pkHeap, this, sizeof(T));
        new (m_data + m_iElementCount) T(e);
        m_iElementCount++;
    }
};

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

}  // namespace fnv_00dc9f20

struct Mem_dca4
{
    virtual void v00();
};
struct Holder_dca4
{
    int unk00, unk04, unk08, unk0C;
    Mem_dca4* m_pMemoryAllocator;
    Mem_dca4& heap()
    {
        return *m_pMemoryAllocator;
    }
};
struct Router_dca4
{
    static Holder_dca4& __cdecl FUN_00c85750() throw();
};
void __cdecl FUN_00c908c0(Mem_dca4* mem, void* array, int numElements, int sizeOfElement);

template <class T> struct hkArray_dca4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(int n)
    {
        Mem_dca4& mem = Router_dca4::FUN_00c85750().heap();
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&mem, this, newSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

extern char DAT_010d73fc;

struct S00dcaeb0_Node
{
    virtual void* v0() = 0;
    virtual void* v1() = 0;
    virtual void* v2() = 0;
    virtual void* v3() = 0;
    virtual void* v4() = 0;
    virtual void* v5() = 0;
    virtual void* v6() = 0;
    virtual void* v7() = 0;
    virtual void* v8() = 0;
    virtual int v9() = 0;

    void* n04;
    int n08;
    void* n0c;
    void* n10;
    void* n14;
    S00dcaeb0_Node* n18;
    void* n1c;
    void* n20;
    void* n24;
    char* n28;
    int n2c;
};

struct DcaeRefPtr
{
    S00dcaeb0_Node* m_pRetainedObject;
    __forceinline DcaeRefPtr(S00dcaeb0_Node* e)
    {
        if (e)
            e->n08++;
        m_pRetainedObject = e;
    }
    S00dcaeb0_Node* operator->() const
    {
        return m_pRetainedObject;
    }
};

struct DcaeBase
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    void* m8;
    __forceinline DcaeBase()
    {
        m6 = 0;
        m8 = 0;
    }
};

struct DcaeBase2 : DcaeBase
{
    __forceinline DcaeBase2()
    {
        m0 = &DAT_010d73fc;
    }
};

struct DcaeArray
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
    __forceinline DcaeArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

namespace fnv_00dcbcd0 {

}  // namespace fnv_00dcbcd0

struct hkBool_dcca
{
    char m_cBooleanValue;
    hkBool_dcca(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Format_dcca
{
    int m_uiFilterValue;
    Format_dcca(int v) : m_uiFilterValue(v)
    {}
};

char* __cdecl FUN_00cb1410(const char*);
struct Crux53_StringMap
{
    void* GetValue(const char*, int);
    void* FUN_00d874d0(void*, void*);
};
struct Crux53_MapBody
{
    int a00, a04, a08, a0c, a10, a14, a18, a1c, a20, a24, a28, a2c, a30, a34, a38, a3c, a40, a44, a48;
    Crux53_StringMap map4c;
    void* InternString(const char* key)
    {
        if (key)
        {
            void* value = map4c.GetValue(key, 0);
            if (!value)
            {
                value = FUN_00cb1410(key);
                map4c.FUN_00d874d0(value, value);
            }
            return value;
        }
        return 0;
    }
};

void ResizeAudioStream(void* mem, void* arr, int elemSize) throw();

struct FUN_00d479e0_class
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;

    void* GetValue(const void* key, const void* defVal) throw();
    void FUN_00d87820(const void* key) throw();
};

struct Node
{
    virtual ~Node() throw();
    virtual void unkSlot1() throw();
    virtual void* GetTarget() throw();
    int unk04;
    int m_iObjectReferenceCount;

    void ClearEntries() throw();

    void Release() throw()
    {
        if (--m_iObjectReferenceCount == 0)
        {
            delete this;
        }
    }
};

struct MultimapEntry
{
    Node* val;
    int next;
};

struct Multimap
{
    MultimapEntry* m_entries;
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

    int LookupWithDefault(void* key) throw();
    void FUN_00dcb4b0(void* key, int index) throw();
    void FUN_00dc8fe0(void* key, Node* const& node) throw()
    {
        for (int it = LookupWithDefault(key); it != -1; it = m_entries[it].next)
        {
            if (m_entries[it].val == node)
            {
                FUN_00dcb4b0(key, it);
                return;
            }
        }
    }
    void RemoveKey(void* key) throw();
};

struct hkMemory
{
    virtual void unk0() throw();
    virtual void unk1() throw();
    virtual void unk2() throw();
    virtual void unk3() throw();
    virtual void deallocate(void* p, int nbytes) throw();
};

struct hkThreadMemory
{
    void* m_aiEntries;
    int unk04;
    int unk08;
    int unk0c;
    hkMemory* m_pMemoryAllocator;

    static hkThreadMemory* GetMonitorStream() throw()
    {
        return (hkThreadMemory*)::FUN_00c85750();
    }
};

inline void hkDeallocateStack(void* p) throw()
{
    hkThreadMemory::GetMonitorStream()->m_aiEntries = p;
}

template <typename T> struct StackAllocatedArray : public hkArrayDC76<T>
{
    T* m_pStackAllocation;

    StackAllocatedArray(int capacity) throw()
    {
        hkThreadMemory* tm = hkThreadMemory::GetMonitorStream();
        void* stack = tm->m_aiEntries;
        tm->m_aiEntries = (char*)stack + capacity * sizeof(T);
        m_data = (T*)stack;
        m_pStackAllocation = (T*)stack;
        m_iCapacityState = 0x80000000 | capacity;
    }

    ~StackAllocatedArray() throw()
    {
        if (m_pStackAllocation == m_data)
        {
            m_iElementCount = 0;
        }
        hkDeallocateStack(m_pStackAllocation);
    }

    void AddBack(T val) throw()
    {
        hkThreadMemory* tm = hkThreadMemory::GetMonitorStream();
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ResizeAudioStream(tm->m_pMemoryAllocator, this, sizeof(T));
        }
        m_data[m_iElementCount++] = val;
    }
};

// Partial RTTI-established hierarchy; unknown base state is named by offset.
struct hkDataRefCounted
{
    void* vtable;
    int unk04;
    int referenceCount;
};
struct hkDataClassDict;
struct hkDataMemberInfo
{
    const char* name;
    hkDataRefCounted* referencedClass;
    int unk08;
    int unk0c;
    int type;
    int unk14;
};
union hkDataValue
{
    __int64 integer;
    float real;
    hkDataRefCounted* object;
    char* string;
    void* allocation;
};
struct hkDataClassDict
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkDataClassDict* parent;
    int unk1c;
    int unk20;
    int unk24;
    hkDataMemberInfo* members;
    int count;
    hkDataMemberInfo* FindEntry(const char* name);
};
void __cdecl ReleaseDataValues(int type, hkDataValue* values, int count);
template <class T> struct HavokElementArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void clear()
    {
        for (int i = 0; i < m_iElementCount; ++i)
            m_data[i].~T();
        m_iElementCount = 0;
    }
};
template <class T> struct hkArray : HavokElementArray<T>
{
};

class hkMemoryAllocatorDCA
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDCA
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorDCA* m_pTemp;
    hkMemoryAllocatorDCA* m_pStreamAllocator;
    hkMemoryAllocatorDCA& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterDCA& __cdecl GetMemoryRouterDCA() throw();
struct hkArrayUtilDCA
{
    static void __cdecl GrowArray(hkMemoryAllocatorDCA& kAlloc, void* apvArray, int iSizeElem) throw();
};

template <typename T> struct hkArrayDCA
{
    hkArrayDCA() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayDCA() throw()
    {
        hkMemoryAllocatorDCA& kAlloc = GetMemoryRouterDCA().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void AddBack(const T& t) throw()
    {
        hkMemoryAllocatorDCA& kAlloc = GetMemoryRouterDCA().heap();
        if (m_iElementCount == getCapacity())
            hkArrayUtilDCA::GrowArray(kAlloc, this, sizeof(T));
        m_data[m_iElementCount] = t;
        m_iElementCount++;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackDCA(int n)
{
    hkMemoryRouterDCA& kRouter = GetMemoryRouterDCA();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackDCA(T* p)
{
    GetMemoryRouterDCA().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayDCA : public hkArrayDCA<T>
{
    __forceinline hkLocalArrayDCA(int n) throw()
    {
        T* pLocal = hkAllocateStackDCA<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayDCA() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackDCA(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

class hkOstreamDCA
{
  public:
    hkOstreamDCA(void* pvBuffer, int iSize) throw();
    ~hkOstreamDCA() throw();
    hkOstreamDCA& operator<<(const char* pcString) throw();
    hkOstreamDCA& operator<<(int i) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};

class hkDataClassImplDCA
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const char* getName() const throw();
};

class hkDataObjectImplDCA
{
  public:
    virtual ~hkDataObjectImplDCA() throw();
    virtual void v04();
    virtual hkDataClassImplDCA* GetVariantValue() const throw();
    void removeReference() throw()
    {
        if (--m_uiItemCount == 0)
            delete this;
    }
    void clearMembers() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_iReferenceCount;
    int m_uiItemCount;
};

struct hkPointerMapDCA
{
    int FindValueForKey(const void* pvKey, int iDefault) const throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

template <typename K, typename V> class hkSerializeMultiMapDCA
{
  public:
    int getFirstIndex(K k) const throw();
    int GetNextChainIndex(int i) const
    {
        return m_kChainValues[i].m_next;
    }
    V getValue(int i) const
    {
        return m_kChainValues[i].m_uiFilterValue;
    }
    void RemoveValuesForKey(K k) throw();
    struct Value
    {
        V m_uiFilterValue;
        int m_next;
    };
    hkArrayDCA<Value> m_kChainValues;
    hkPointerMapDCA m_pHashFunction;
};

namespace fnv_00dc95d0 {
// FUN_00dc95d0: string-table lookup + registered-entry scan.

struct FUN_00d874d0_s
{
    void FUN_00d874d0(char const* name, int value);
};

struct FUN_00d479e0_class : FUN_00d874d0_s
{
    void* GetValue(void const* key, void const* fallback);
};

extern "C" void* FUN_00cb1410(void const* key);

}  // namespace fnv_00dc95d0

namespace fnv_00dc9640 {
struct FUN_00d47a80_class
{
    void* GetValue(void* key, int def);
    void FUN_00d874d0(const char* key, int value);
};

extern "C" char* __cdecl FUN_00cb1410(const char* s);

struct hkWorldDC96
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
    FUN_00d47a80_class m_pStringFunctions;
};

struct hkHolderDC96
{
    int unk00;
    int unk04;
    hkWorldDC96* m_pOwningWorld;
};

struct hkOwnerDC96
{
    int unk00;
    int unk04;
    int unk08;
    hkHolderDC96* m_holder;
};

class hkNameDC96;

struct hkNameRefDC96
{
    hkNameDC96* m_pOwnerObject;
    char* m_name;
};

class hkNameDC96
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkOwnerDC96* m_pOwnerObject;

    hkNameRefDC96 FUN_00dc9640(const char* name);
};

}  // namespace fnv_00dc9640

namespace fnv_00dc9d10 {
extern "C" void* __cdecl fnv_zlib_memset(void* pvDest, int iValue, unsigned int iCount);
extern "C" void _ReadWriteBarrier(void);

class hkMemoryAllocatorDC9D;

struct hkMemoryRouterDC9D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC9D* m_pStreamAllocator;
    hkMemoryAllocatorDC9D& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC9D& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocatorDC9D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayDC9D
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDC9D& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const T& fill)
    {
        reserve(FUN_00c85750().heap(), n);
        int iNumToFill = n - m_iElementCount;
        T* pDst = m_data + m_iElementCount;
        _ReadWriteBarrier();
        if (iNumToFill > 0)
            fnv_zlib_memset(pDst, fill, iNumToFill);
        m_iElementCount = n;
    }
};

}  // namespace fnv_00dc9d10

namespace fnv_00dcb890 {
extern int DAT_010d73fc;
void* FUN_00c85750();
}  // namespace fnv_00dcb890

void ResizeAudioStream(void* allocator, void* array, int elementSize);
struct TypeInfo
{
    virtual void slot00();
    virtual void slot04();
    virtual const char* name();
};
struct ReferencedObject
{
    virtual void destroy(int flags);
    virtual void slot04();
    virtual TypeInfo* type();
    short allocationSize;
    short externalReferences;
    int references;
    void FUN_00dc90a0();
    void FUN_00c905b0();
    void release()
    {
        if (--references == 0)
            destroy(1);
    }
};
struct PointerArray
{
    ReferencedObject** data;
    int size;
    int capacity;
    PointerArray() : data(0), size(0), capacity(0x80000000)
    {}
    void push(ReferencedObject* value)
    {
        hkMemoryRouterDC76* router = FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router->m_pkHeap, this, 4);
        data[size++] = value;
    }
    void clearStorage(bool reset = true)
    {
        hkMemoryRouterDC76* router = FUN_00c85750();
        hkAllocatorDC76* heap = router->m_pkHeap;
        size = 0;
        if (!(capacity & 0x80000000))
            heap->ReturnMemory(data, (capacity & 0x3fffffff) * 4);
        if (reset)
        {
            data = 0;
            capacity = 0x80000000;
        }
    }
};
struct LocalPointerArray : PointerArray
{
    char* original;
    LocalPointerArray(int count)
    {
        hkMemoryRouterDC76* router = FUN_00c85750();
        char* storage = (char*)router->m_p00;
        router->m_p00 = storage + count * 4;
        data = (ReferencedObject**)storage;
        capacity = count | 0x80000000;
        original = storage;
    }
    void finish(bool reset = true)
    {
        char* storage = original;
        if (storage == (char*)data)
            size = 0;
        FUN_00c85750()->m_p00 = storage;
        clearStorage(reset);
    }
};
struct ChainEntry
{
    ReferencedObject* object;
    int next;
};
struct ChainArray
{
    ChainEntry* data;
    int size;
    int capacity;
    int LookupWithDefault(ReferencedObject* p);
    void RemoveKey(ReferencedObject* p);
    void clearStorage(bool reset = true)
    {
        hkMemoryRouterDC76* router = FUN_00c85750();
        hkAllocatorDC76* heap = router->m_pkHeap;
        size = 0;
        if (!(capacity & 0x80000000))
            heap->ReturnMemory(data, (capacity & 0x3fffffff) * 8);
        if (reset)
        {
            data = 0;
            capacity = 0x80000000;
        }
    }
};
void FUN_00cb13c0(ReferencedObject* object);

struct VarObject : public Shape7DE0
{
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void SetValue(int);
};
struct VarDef
{
    int m_00;
    int m_04;
    int m_iInfo;
};
struct VarRecord
{
    int m_00;
    VarDef* m_pkDef;
    int m_08;
    int m_0c;
    int m_iFlags;
    int m_iInitial;
};
struct VarEntry
{
    int m_iKey;
    int m_04;
    VarObject* m_pPointer;
    int m_0c;
    VarEntry() : m_iKey(0)
    {}
};
template <typename T> __forceinline void hkConstructDefault(T* p, int n)
{
    for (int i = 0; i < n; i++)
        ::new (p + i) T();
}
template <typename T> struct VarArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& AllocatePair()
    {
        hkAllocatorDC76& a = FUN_00c85750()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&a, this, sizeof(T));
        hkConstructDefault(m_data + m_iElementCount, 1);
        return m_data[m_iElementCount++];
    }
};
struct VarResult
{
    VarRecord* m_pkRecord;
    int m_iIndex;
    VarResult()
    {}
    VarResult(VarRecord* r, int i) : m_pkRecord(r), m_iIndex(i)
    {}
};

struct S00dcbd40_Destination;

struct S00dcbd40_Id
{
    S00dcbd40_Destination* dictionary;
    int id;
};

struct S00dcbd40_Info
{

    int unk00;

    int unk04;

    int unk08;

    int unk0C;

    int flags;
};

struct S00dcbd40_Shared
{

    int unk00;

    int unk04;

    int references;
};

struct S00dcbd40_Pair
{

    S00dcbd40_Shared* object;

    int value;
};

struct S00dcbd40_Entry
{

    int key;

    int unk04;

    S00dcbd40_Pair data;

    S00dcbd40_Entry() : key(0)
    {}
};

struct S00dcbd40_Result
{

    S00dcbd40_Info* info;

    int index;

    S00dcbd40_Result()
    {}

    S00dcbd40_Result(S00dcbd40_Info* p, int i) : info(p), index(i)
    {}
};

struct S00dcbd40_Handle
{

    int v;

    S00dcbd40_Handle(int x) : v(x)
    {}
};

struct S00dcbd40_Array
{

    S00dcbd40_Entry* data;

    int size;

    int capacityAndFlags;

    S00dcbd40_Entry& operator[](int i)
    {
        return data[i];
    }
};

struct S00dcbd40_ClassInfo
{

    S00dcbd40_Info* FindEntry(S00dcbd40_Handle key) throw();
};

void __cdecl ResizeAudioStream(hkAllocatorDC76*, S00dcbd40_Array*, int) throw();

void __cdecl ReleaseDataValues(int, S00dcbd40_Pair*, int) throw();

struct S00dcbd40_Destination
{

    int unk00;

    int unk04;

    int unk08;

    S00dcbd40_ClassInfo* pClassInfo;

    S00dcbd40_Array entries;

    S00dcbd40_Result __thiscall FUN_00dc9710(S00dcbd40_Handle ref, int flags) throw();

    S00dcbd40_Result __thiscall FUN_00dcba40(S00dcbd40_Handle key, int flags) throw();

    void __thiscall FUN_00dcbd40(int target, S00dcbd40_Id* id) throw();
};

void __cdecl ResizeAudioStream(void* allocator, void* array, int stride);
void __cdecl ReleaseDataValues(int type, void* target, int count);

// @f3 0x007911d0 (community match, verified in this file)
// Adapted from shared f3decomp checkpoint chk_188067dc1091416f9dbe, attributed by the service to another contributor.
struct PR_Ref;

struct RttiDCAC
{
    const char* m_pcName;
    const RttiDCAC* m_pkBaseRTTI;
};

extern const RttiDCAC DAT_010787c4;

struct PR_Obj
{
    virtual void v00();
    virtual void v04();
    virtual const RttiDCAC* GetRTTI() const;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
    int unk14;
    int unk18;
    PR_Ref* m_1c;
    int unk20;
    int unk24;
    char m_28;
};

static __forceinline bool IsKindOfDCAC(const RttiDCAC* pkRTTI, const PR_Obj* pkObject)
{
    if (!pkObject)
        return false;
    for (const RttiDCAC* p = pkObject->GetRTTI(); p; p = p->m_pkBaseRTTI)
    {
        if (p == pkRTTI)
            return true;
    }
    return false;
}

struct ListDCAC
{
    PR_Obj* node;
    ListDCAC* next;
    bool IsEmpty() const { return next == 0 && node == 0; }
};

struct PR_Mgr
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
    ListDCAC list;
    PR_Obj* FUN_007911d0(PR_Ref* pkClass);
};

// pdb: ProcessLists::FindActiveShaderHitEffect | ProcessLists.obj | fnv360_0822_retail, objrun, medium
// pdb params: apEffectTarget
PR_Obj* PR_Mgr::FUN_007911d0(PR_Ref* pkClass)
{
    float fBest = 3.4028234663852886e+38f;
    PR_Obj* result = 0;
    if (!list.IsEmpty())
    {
        for (ListDCAC* p = &list; p != 0; p = p->next)
        {
            PR_Obj* node = p->node;
            if (IsKindOfDCAC(&DAT_010787c4, node) && node->m_1c == pkClass && node->m_10 < fBest && !node->m_28)
            {
                result = node;
                fBest = node->m_10;
            }
        }
    }
    return result;
}
