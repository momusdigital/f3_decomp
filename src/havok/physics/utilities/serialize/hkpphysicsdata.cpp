#include "f3_common.h"
// src/havok/physics/utilities/serialize/hkpphysicsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpphysicsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhysicsData.h"

int __cdecl hkString_strCasecmp(int, int);

struct FUN_00d4c000
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int Method(int a);
};

// @f3 0x009d8cb0 (community match, verified in this file)
// pdb: hkpPhysicsData::findPhysicsSystemByName | hkpPhysicsData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: name
int FUN_00d4c000::Method(int a)
{
    int __cdecl FUN_00923300(int, int);
    for (int i = 0; i < m_10; i++)
    {
        int v = *reinterpret_cast<int*>(*(reinterpret_cast<char**>(m_0c) + i) + 0x38);
        if (v && !FUN_00923300(v, a))
            return m_0c[i];
    }
    return 0;
}


extern int DAT_010cf9a4;

struct FUN_00d4c220_s
{
    int* m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00d4c220_s();
};

// @fnv 0x00d4c220
// pdb: hkpPhysicsData::hkpPhysicsData | hkpPhysicsData.obj | fnv360_0822_retail, call_seq, high
FUN_00d4c220_s::FUN_00d4c220_s()
{
    m_06 = 1;
    m_00 = &DAT_010cf9a4;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0x80000000;
    m_08 = 0;
}

int __cdecl hkString_strCasecmp(int, int);

struct FUN_00d4c050_obj
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int FindMatchingEntry(int a);
};

// Scans m_10 entries, checks each entry's sub-items via hkString_strCasecmp on the masked field at offset 0x74, and returns the first matching item or 0.
// @f3 0x009d8d00 (community match, verified in this file)
int __cdecl FUN_00923300(int, int);
// pdb: hkpPhysicsData::findRigidBodyByName | hkpPhysicsData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: name
int FUN_00d4c050_obj::FindMatchingEntry(int a)
{
    for (int i = 0; i < m_10; ++i)
    {
        int* p = (int*)m_0c[i];
        for (int jItem = 0; jItem < p[3]; ++jItem)
        {
            int v = ((int*)p[2])[jItem];
            int m = *(int*)((char*)v + 0x70);
            if (m && !FUN_00923300(m, a))
                return v;
        }
    }
    return 0;
}


extern int DAT_0102f0ec;

struct hkMemoryAllocator
{
    virtual void* vfunc0() throw();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
};

class hkThreadMemory
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pMemoryAllocator;

    __forceinline void* allocateChunk(int size) throw()
    {
        return m_pMemoryAllocator->AllocateMemoryBlock(size);
    }
};

void* FUN_00c85750() throw();
void __cdecl InitializeWorld(void*) throw();
void __cdecl RunWithLocalContext(void*, void*, void*) throw();

struct FUN_00d1df70
{
    void removeReference() throw();
};

template <typename T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;
    __forceinline ReferenceCountedPointer() throw()
    {}
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
        {
            ((FUN_00d1df70*)m_pRetainedObject)->removeReference();
        }
        m_pRetainedObject = 0;
    }
};

struct BoolResult
{
    char val;
    __forceinline BoolResult() throw()
    {}
};

class hkpPhysicsSystem : public hkReferencedObject
{
  public:
    virtual void vfunc1() throw();
    virtual void vfunc2() throw();
    virtual void vfunc3() throw();
    virtual BoolResult vfunc4() throw();
};

class __declspec(align(16)) FUN_00553540
{
  public:
    void* vtable;
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
    ReferenceCountedPointer<void> m_pCollisionFilter;  // 0x58
    ReferenceCountedPointer<void> m_pConvexListCollisionFilter;  // 0x5c
    int unk60;
    int unk64;
    int unk68;
    ReferenceCountedPointer<void> m_pMemoryWatchDog;  // 0x6c
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;

    void FUN_00c90b80() throw();
    __forceinline FUN_00553540() throw()
    {
        FUN_00c90b80();
    }
    __forceinline ~FUN_00553540() throw()
    {
        vtable = &DAT_0102f0ec;
    }
};

class hkpWorld
{
  public:
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
    void* m_pDispatcher;  // 0x80
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;

    void* operator new(size_t size) throw()
    {
        void* p = ((hkThreadMemory*)FUN_00c85750())->allocateChunk(size);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    hkpWorld* FUN_00c95a80(const FUN_00553540* info, unsigned int version = 0x111d4) throw();
    __forceinline hkpWorld(const FUN_00553540* info) throw()
    {
        FUN_00c95a80(info, 0x111d4);
    }
    void FUN_00c97f80(hkpPhysicsSystem* system) throw();
    void hkpWorld_updateCollisionFilterOnWorld(int a, int b) throw();
};

struct ContactOptions
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    int m_04;
    char m_08;
    char m_09;
    char m_0a;
    char m_0b;
};

struct PhysicsDataExt : public hkpPhysicsData
{
    hkpWorld* CreateWorld(char bRegisterWithMemoryManager) throw();
};

// @f3 0x009d8b00 (community match, verified in this file)
namespace CWf3_83 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Tls83 {
    void* FUN_008f6d30(int iSize, int iFlags);
};
struct __declspec(align(16)) WCinfo83 {
    void FUN_0090a9b0() throw();
    int m_fields[0x31];
};
}
hkpWorld* PhysicsDataExt::CreateWorld(char bRegisterWithMemoryManager) throw()
{
    CWf3_83::WCinfo83 cinfo;
    cinfo.FUN_0090a9b0();
    hkpWorld* world;
    if (this->m_pWorldCinfo == 0)
    {
        CWf3_83::Tls83* tls = (CWf3_83::Tls83*)CWf3_83::DAT_00d9b080(CWf3_83::DAT_010f3170);
        void* p = tls->FUN_008f6d30(0x310, 0x2f);
        ((unsigned short*)p)[2] = 0x310;
        world = ((hkpWorld*)p)->FUN_00c95a80((const FUN_00553540*)&cinfo, 0xc544);
    }
    else
    {
        CWf3_83::Tls83* tls = (CWf3_83::Tls83*)CWf3_83::DAT_00d9b080(CWf3_83::DAT_010f3170);
        void* p = tls->FUN_008f6d30(0x310, 0x2f);
        ((unsigned short*)p)[2] = 0x310;
        world = ((hkpWorld*)p)->FUN_00c95a80((const FUN_00553540*)this->m_pWorldCinfo, 0xc544);
    }
    if (bRegisterWithMemoryManager)
    {
        InitializeWorld(*(void**)((char*)world + 0x74));
    }
    for (int i = 0; i < this->m_kPhysicsSystems.m_iElementCount; ++i)
    {
        world->FUN_00c97f80(this->m_kPhysicsSystems.m_data[i]);
        if (this->m_kPhysicsSystems.m_data[i]->vfunc4().val)
        {
            ContactOptions opts;
            opts.m_00 = 0;
            opts.m_01 = 0;
            opts.m_04 = 0;
            opts.m_08 = 1;
            opts.m_09 = 1;
            opts.m_0a = 0;
            RunWithLocalContext(&opts, this->m_kPhysicsSystems.m_data[i], world);
        }
    }
    if (this->m_pWorldCinfo && *(void**)((char*)this->m_pWorldCinfo + 0x54))
    {
        world->hkpWorld_updateCollisionFilterOnWorld(0, 1);
    }
    return world;
}


namespace fnv_00d4c8e0 {
class hkMemoryAllocatorD4C8
{
  public:
    virtual ~hkMemoryAllocatorD4C8() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4C8
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4C8* m_pStreamAllocator;
    hkMemoryAllocatorD4C8& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4C8& __cdecl FUN_00c85750();

class FUN_00dcecc0
{
  public:
    virtual ~FUN_00dcecc0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00dcecc0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00dcecc0* Destroy(unsigned int uiFlags) throw();
};

}  // namespace fnv_00d4c8e0

extern void* __cdecl FUN_00c85750(void);

struct D4C2Place
{
};
inline void* operator new(unsigned int, void* p, D4C2Place)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, D4C2Place)
{}

struct ArrayField
{
    int m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ArrayField() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct SmallType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    ArrayField m_ppData;
    void FUN_00d065e0(void);
};

struct ClientType
{
    void FUN_00c91c50(void*);
    void AddPhysicsSystem(void*);
};
struct ArrayType
{
    SmallType** m_data;
    int m_iElementCount;
    int m_cap;
};
struct HostType
{
    int m_00;
    int m_04;
    void* m_08;
    ArrayType m_0c;
    void hkpPhysicsData_populateFromWorld(ClientType*, unsigned char);
};

// Ensures m_08 is allocated, registers client and m_0c, and when value is set allocates a SmallType, calls ProcessCollisionRecords, and appends it to m_0c.
// @f3 0x009d8da0 (community match, verified in this file)
extern int DAT_010f3170;
extern int DAT_00e8014c;
__declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long);

struct TlsCtx
{
    void* FUN_008f6d30(int iSize, int iFlags);
};
struct AllocBlock
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void* FUN_0090a9b0();
};
struct ClientOps
{
    void FUN_00903020(void* pParam);
    void FUN_00904470(ArrayType* pkArray);
};
struct ItemType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    ArrayField m_ppData;
    void FUN_0098a090();
};
struct HostCallData
{
    unsigned char m_Flag;
    int m_Value;
};
void __cdecl FUN_00a4d390(HostCallData* pkData, ClientType* pkClient, ItemType* pkItem);
void __cdecl FUN_00901f10(ArrayType* pkArray, int iElementSize);

// pdb: hkpPhysicsData::populateFromWorld | hkpPhysicsData.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
void HostType::hkpPhysicsData_populateFromWorld(ClientType* client, unsigned char flag)
{
    if (m_08 == 0)
    {
        TlsCtx* tls = (TlsCtx*)TlsGetValue(DAT_010f3170);
        AllocBlock* alloc = (AllocBlock*)tls->FUN_008f6d30(0xd0, 0x15);
        alloc->m_04 = 0xd0;
        m_08 = alloc->FUN_0090a9b0();
    }

    ((ClientOps*)client)->FUN_00903020(m_08);

    ArrayType* array = &m_0c;
    ((ClientOps*)client)->FUN_00904470(array);

    if (flag != 0)
    {
        HostCallData kData;
        kData.m_Flag = 0;
        kData.m_Value = 0;

        TlsCtx* tls = (TlsCtx*)TlsGetValue(DAT_010f3170);
        ItemType* item = (ItemType*)tls->FUN_008f6d30(0x50, 0x2f);
        item->m_04 = 0x50;
        item->FUN_0098a090();

        ArrayField* pp = &item->m_ppData;
        *(void**)item = &DAT_00e8014c;
        pp->m_data = 0;
        pp->m_iElementCount = 0;
        pp->m_iCapacityState = 0x80000000;

        FUN_00a4d390(&kData, client, item);

        item->m_40 = 0;

        if (array->m_iElementCount == (array->m_cap & 0x3fffffff))
            FUN_00901f10(array, 4);
        array->m_data[array->m_iElementCount] = (SmallType*)item;
        ++array->m_iElementCount;
    }
}


extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

struct Value
{
    BoolResult FUN_00c9bff0();
};
struct Owner
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
    void FUN_00d06130(int index);
};
struct Entity
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
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
    unsigned char m_40;
    void AddShape(int value);
};
struct OwnerArg
{
    Owner* p;
};
struct ValueArg
{
    Value* p;
};
template <class T> __forceinline int findValue(T* self, Value* value)
{
    int count = ((volatile T*)self)->m_0c;
    for (int i = 0; i < count; ++i)
    {
        if (self->m_08[i] == (int*)value)
            return i;
    }
    return -1;
}
typedef int Owner::*MemberPtr;
// If value is in owner's list but not entity's, sets entity->m_40, calls entity->AddShape(value) and owner->FUN_00d06130 with the owner index.
// @fnv 0x00d4bf70
// pdb: hkpPhysicsSystem::removeRigidBody | hkpPhysicsSystem.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
static __declspec(noinline) void hkpPhysicsSystem_removeRigidBody(Owner* owner, Entity* volatile apEntity, MemberPtr valueArg)
{
    Entity* entity = apEntity;
    Value* pValue;
    memcpy(&pValue, &valueArg, 4);
    Value* value = pValue;
    int ownerIndex = findValue(owner, value);
    int entityIndex = findValue(entity, value);
    if (entityIndex == -1 && ownerIndex != -1)
    {
        entity->m_40 = entity->m_40 || value->FUN_00c9bff0().val;
        entity->AddShape((int)value);
        owner->FUN_00d06130(ownerIndex);
    }
}
Owner* volatile probeOwner;
Value* volatile probeValue;
Entity* volatile probeEntity;
void probeCaller()
{
    OwnerArg o = {probeOwner};
    ValueArg v = {probeValue};
    hkpPhysicsSystem_removeRigidBody(o.p, probeEntity, *(MemberPtr*)&v.p);
}

namespace fnv_00d4c250 {
class hkMemoryAllocatorD4C
{
  public:
    virtual ~hkMemoryAllocatorD4C();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterD4C
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD4C* m_pTemp;
    hkMemoryAllocatorD4C* m_pStreamAllocator;
    hkMemoryAllocatorD4C& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD4C* __cdecl FUN_00c85750() throw();

template <class T> class hkArrayD4C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD4C() throw()
    {
        hkMemoryAllocatorD4C& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseObjectD4C
{
  public:
    virtual ~hkBaseObjectD4C()
    {}
};

}  // namespace fnv_00d4c250
