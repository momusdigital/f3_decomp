#include "f3_common.h"
// src/havok/common/base/debugutil/statisticscollector/hkstatisticscollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/hkstatisticscollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_0102e388;

struct FUN_00d06f70_s
{
    int* p;
    int x;
    int y;
    void FUN_00d06f70();
};

// @fnv 0x00d06f70
// pdb: hkpMoppShapeMediator::~hkpMoppShapeMediator | hkpMoppShapeMediator.obj | fnv360_0822_retail, call_seq, high
void FUN_00d06f70_s::FUN_00d06f70()
{
    y = 0;
    p = &DAT_0102e388;
}

int __cdecl FUN_00d06f80(void* apBuffer, int aiCount);

extern "C" int __cdecl FUN_00d06f80(const char* s, int len);

struct SlotAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* ptr, unsigned int size);
};

struct AllocHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SlotAllocator* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750();
void* __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int count);

struct GrowBuf
{
    void* m_pData;
    unsigned short m_uCap;
    unsigned short m_uiObjectFlags;
};

// @f3 0x0098a9f0 (community match, verified in this file)
#include <windows.h>

extern unsigned int DAT_010f3170;

struct TlsSlotAlloc
{
    void* FUN_008f6d30(unsigned int size, int tag);
    void FUN_008f6d90(void* ptr, unsigned int size, int tag);
};

// pdb: hkSmallArrayUtil::_reserveMore | hkSmallArray.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_seq) + skyrim(call_gap), high
void __cdecl hkSmallArrayUtil__reserveMore(GrowBuf* buf, unsigned int elemSize)
{
    unsigned int newCount;
    if (buf->m_uCap != 0)
        newCount = (unsigned int)buf->m_uCap * 2;
    else
        newCount = 1;

    TlsSlotAlloc* allocator = (TlsSlotAlloc*)TlsGetValue(DAT_010f3170);
    void* newData = allocator->FUN_008f6d30(newCount * elemSize, 0x17);
    FUN_00ec44d0(newData, buf->m_pData, (unsigned int)buf->m_uCap * elemSize);

    if ((buf->m_uiObjectFlags & 0x8000u) == 0)
    {
        unsigned int oldCount = buf->m_uiObjectFlags & 0x3fffu;
        allocator = (TlsSlotAlloc*)TlsGetValue(DAT_010f3170);
        allocator->FUN_008f6d90(buf->m_pData, oldCount * elemSize, 0x17);
    }

    buf->m_pData = newData;
    buf->m_uiObjectFlags = (unsigned short)((buf->m_uiObjectFlags & 0x4000u) | newCount);
}


struct FUN_00d06d90_cls;

struct Rec
{
    int unk00;
    unsigned short m_04;
};

struct Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void* Query(Rec* a);
};

struct FUN_00d06d90_cls
{
    int unk00;
    int unk04;
    int unk08;
    Inner* m_0c;
    unsigned char m_10;

    int GetFlagsOrProcess(Rec* a);
};

namespace fnv_00d06dd0 {
struct S_00d06dd0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int vfn2c(int a, int b);
};

struct S_00d06dd0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d06dd0_Heap* unk10;
    S_00d06dd0_Heap& heap()
    {
        return *unk10;
    }
};

S_00d06dd0_Router* FUN_00c85750();

}  // namespace fnv_00d06dd0

namespace fnv_00d06e10 {

struct FUN_00d06e10_obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int v2c(int a, int b);
};

struct FUN_00d06e10_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d06e10_obj* m_10;
};

FUN_00d06e10_holder* __cdecl FUN_00c85750();

}  // namespace fnv_00d06e10

class D06F50ReferencedObject
{
  public:
    D06F50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

namespace fnv_00d06f80 {

extern void* __cdecl FUN_00c85750();

// If s is non-null, gets a Holder via FUN_00c85750 and returns holder->unk10->v11(s, len); otherwise returns len.
// @f3 0x00569bf0 (community match, verified in this file)
namespace f3m_00569bf0 {
struct Inner_569bf0 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3c(int a, int b);
};
struct Cls_00569bf0 {
    int unk00, unk04;
    Inner_569bf0* inner08;
    void FUN_00c24b70();
    void FUN_00569bf0(int a);
};
// pdb: bhkShapePhantom::GetPenetrations | DecalCaster.obj | fnv360_0822_retail, call_gap, low
// pdb params: arCollector
void Cls_00569bf0::FUN_00569bf0(int a) {
    if (this) {
        Inner_569bf0* p = inner08;
        if (p) {
            FUN_00c24b70();
            p->v3c(a, 0);
            FUN_00c24b70();
        }
    }
}
}   // namespace f3m_00569bf0

}  // namespace fnv_00d06f80

int __cdecl FUN_00d06f80(int aiB, int aiC);

// Returns one of five fixed string pointers for values 0 through 4, or a fallback pointer otherwise.
// @f3 0x005a24f0 (community match, verified in this file)
// pdb: ActorValue::GetSectionCount | ActorValue.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
const char* __cdecl ActorValue_GetSectionCount(int value)
{
    switch (value)
    {
    case 0:
        return (const char*)7;
    case 1:
        return (const char*)0x14;
    case 2:
        return (const char*)0xe;
    case 3:
        return (const char*)5;
    case 4:
        return (const char*)7;
    case 5:
        return (const char*)0x10;
    default:
        return 0;
    }
}

