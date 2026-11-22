#include <windows.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00400000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004060b0 (community match, verified in this file)
namespace f3m_004060b0 {


struct RefCountedP8
{
    int unk00;
    volatile LONG refCount;
};

struct FUN_004060b0_Holder
{
    RefCountedP8* object;

    void FUN_004060b0();
};

// pdb: BSSimpleList<char const *>::IsEmpty | MagicItem.obj | fnv360_0721_beta, objrun, medium
void FUN_004060b0_Holder::FUN_004060b0()
{
    if (object)
        InterlockedDecrement(&object->refCount);
}
}   // namespace f3m_004060b0

// @f3 0x0041dd00 (community match, verified in this file)
namespace f3m_0041dd00 {
class TESObjectREFR;
class BSExtraData {
public:
    BSExtraData(unsigned char aType) : type(aType), next(0) {}
    virtual ~BSExtraData();
    virtual bool IsNotEqual(const BSExtraData* other) const;
    unsigned char type;
    BSExtraData* next;
};
class ExtraEnableStateParent : public BSExtraData {
public:
    ExtraEnableStateParent();
    virtual bool IsNotEqual(const BSExtraData* other) const;
    TESObjectREFR* parent;
    unsigned char oppositeState;
};
// pdb: ExtraEnableStateParent::ExtraEnableStateParent | ExtraDataObjects.obj | fnv360_0822_retail, uvref, high
ExtraEnableStateParent::ExtraEnableStateParent() : BSExtraData(0x37), parent(0), oppositeState(0)
{
}
}   // namespace f3m_0041dd00

// @f3 0x00412380 (community match, verified in this file)
namespace f3m_00412380 {

struct AeHeap
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern AeHeap DAT_01090a78;

class BSOcclusionPlane
{
public:
    virtual ~BSOcclusionPlane();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class BSExtraData
{
public:
    virtual ~BSExtraData();
    virtual bool IsNotEqual(const BSExtraData* pkCompare) const;

    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }

    unsigned char cEtype;
    BSExtraData* pNext;
};

class ExtraOcclusionPlane : public BSExtraData
{
public:
    ExtraOcclusionPlane();
    virtual ~ExtraOcclusionPlane();

    NiPointer<BSOcclusionPlane> spPlane;
};

class ExtraDataList
{
public:
    BSExtraData* BaseExtraList_GetExtraData(unsigned char type);
    void BaseExtraList_AddExtra(BSExtraData* pkExtra);
    void FUN_0040a3f0(unsigned char type);

    void FUN_00412380(BSOcclusionPlane* pkPlane);
};

// pdb: ExtraDataList::SetOcclusionPlane | ExtraDataList.obj | fnv360_0822_retail, call_gap, low
// pdb params: apPlane
void ExtraDataList::FUN_00412380(BSOcclusionPlane* pkPlane)
{
    if (pkPlane)
    {
        ExtraOcclusionPlane* pkExtra = (ExtraOcclusionPlane*)BaseExtraList_GetExtraData(0x71);
        if (pkExtra)
        {
            pkExtra->spPlane = pkPlane;
        }
        else
        {
            pkExtra = new ExtraOcclusionPlane;
            pkExtra->spPlane = pkPlane;
            BaseExtraList_AddExtra(pkExtra);
        }
    }
    else
    {
        FUN_0040a3f0(0x71);
    }
}
}   // namespace f3m_00412380

// @f3 0x00411080 (community match, verified in this file)
namespace f3m_00411080 {


class BSSpinLock
{
public:
    volatile LONG owningThread;
    volatile LONG lockCount;

    __declspec(noinline) void Lock(const char* name)
    {
        LONG threadId = GetCurrentThreadId();
        if (owningThread == threadId)
        {
            lockCount++;
            return;
        }
        unsigned int spin = 0;
        while (InterlockedCompareExchange(&owningThread, threadId, 0))
        {
            spin++;
            Sleep(spin > 10000 ? 1 : 0);
        }
        lockCount = 1;
    }
    void Unlock()
    {
        if (--lockCount == 0)
            InterlockedCompareExchange(&owningThread, 0, owningThread);
    }
};
extern BSSpinLock g_extraListLock411080;

struct MemoryHeap411080
{
    void* Allocate(unsigned int size);
    void Free(void* memory);
};
extern MemoryHeap411080 g_heap411080;

class TESRegionList
{
public:
    virtual ~TESRegionList();
};

class BSExtraData
{
public:
    virtual ~BSExtraData();
    virtual bool IsNotEqual(const BSExtraData* compare) const;
    static void* operator new(unsigned int size) { return g_heap411080.Allocate(size); }
    static void operator delete(void* memory) { g_heap411080.Free(memory); }
    unsigned char type;
    BSExtraData* next;
};

class ExtraRegionList : public BSExtraData
{
public:
    ExtraRegionList(TESRegionList* list);
    virtual ~ExtraRegionList();
    TESRegionList* regionList;
};

class ExtraDataList
{
public:
    virtual ~ExtraDataList();
    BSExtraData* head;
    unsigned char presence[0x12];

    BSExtraData* GetByType(unsigned char type) const;
    bool Remove(BSExtraData* extra, bool free);
    __declspec(noinline) BSExtraData* Add(BSExtraData* extra)
    {
        g_extraListLock411080.Lock("BaseExtraList::AddExtra()");
        switch (extra->type)
        {
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x15:
        case 0x2B:
            if (head)
                extra->next = head;
            head = extra;
            break;
        default:
            if (head)
            {
                BSExtraData* last = head;
                while (last->next)
                    last = last->next;
                last->next = extra;
            }
            else
                head = extra;
            break;
        }
        int type = extra->type;
        unsigned int index = (unsigned int)type >> 3;
        if (index < 0x12)
            presence[index] |= (unsigned char)(1 << (type % 8));
        g_extraListLock411080.Unlock();
        return extra;
    }
    void FUN_00411080(TESRegionList* list);
};
// pdb: ExtraDataList::SetRegionList | ExtraDataList.obj | fnv360_0822_retail, call_seq, low
// pdb params: apList
void ExtraDataList::FUN_00411080(TESRegionList* list)
{
    ExtraRegionList* extra = (ExtraRegionList*)GetByType(4);
    if (!list)
    {
        if (extra)
            Remove(extra, true);
        return;
    }
    if (!extra)
    {
        Add(new ExtraRegionList(list));
        return;
    }
    if (extra->regionList && extra->regionList != list)
        delete extra->regionList;
    extra->regionList = list;
}
}   // namespace f3m_00411080

// @f3 0x0040b330 (community match, verified in this file)
namespace f3m_0040b330 {


class BSSpinLock
{
public:
    volatile LONG owningThread;
    volatile LONG lockCount;

    __declspec(noinline) void Lock(const char* name)
    {
        LONG threadId = GetCurrentThreadId();
        if (owningThread == threadId)
        {
            lockCount++;
            return;
        }
        unsigned int spin = 0;
        while (InterlockedCompareExchange(&owningThread, threadId, 0))
        {
            spin++;
            Sleep(spin > 10000 ? 1 : 0);
        }
        lockCount = 1;
    }
    void Unlock()
    {
        if (--lockCount == 0)
            InterlockedCompareExchange(&owningThread, 0, owningThread);
    }
};
extern BSSpinLock g_extraListLock40b330;

struct MemoryHeap40b330
{
    void* Allocate(unsigned int size);
    void Free(void* memory);
};
extern MemoryHeap40b330 g_heap40b330;

class BSExtraData
{
public:
    virtual ~BSExtraData();
    virtual bool IsNotEqual(const BSExtraData* compare) const;
    static void* operator new(unsigned int size) { return g_heap40b330.Allocate(size); }
    static void operator delete(void* memory) { g_heap40b330.Free(memory); }
    unsigned char type;
    BSExtraData* next;
};

class ExtraCharge : public BSExtraData
{
public:
    ExtraCharge(float value);
    virtual ~ExtraCharge();
    float value;
};

class ExtraDataList
{
public:
    virtual ~ExtraDataList();
    BSExtraData* head;
    unsigned char presence[0x12];

    BSExtraData* GetByType(unsigned char type) const;
    bool Remove(BSExtraData* extra, bool free);
    __declspec(noinline) BSExtraData* Add(BSExtraData* extra)
    {
        g_extraListLock40b330.Lock("BaseExtraList::AddExtra()");
        switch (extra->type)
        {
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x15:
        case 0x2B:
            if (head)
                extra->next = head;
            head = extra;
            break;
        default:
            if (head)
            {
                BSExtraData* last = head;
                while (last->next)
                    last = last->next;
                last->next = extra;
            }
            else
                head = extra;
            break;
        }
        int type = extra->type;
        unsigned int index = (unsigned int)type >> 3;
        if (index < 0x12)
            presence[index] |= (unsigned char)(1 << (type % 8));
        g_extraListLock40b330.Unlock();
        return extra;
    }
    void FUN_0040b330(float value);
};
// pdb: ExtraDataList::SetCharge | ExtraDataList.obj | fnv360_0822_retail, call_gap, low
// pdb params: afCharge
void ExtraDataList::FUN_0040b330(float value)
{
    ExtraCharge* extra = (ExtraCharge*)GetByType(0x28);
    if (extra)
        extra->value = value;
    else
        Add(new ExtraCharge(value));
}
}   // namespace f3m_0040b330

// @f3 0x0040a620 (community match, verified in this file)
namespace f3m_0040a620 {
struct Obj {
    int unk00;
    unsigned char unk04;
};

bool __stdcall FUN_0040a620(Obj* p)
{
    bool r = true;
    if (p != 0) {
        switch (p->unk04) {
        case 1: case 2: case 4: case 12: case 15: case 16: case 17: case 21:
        case 41: case 52: case 64: case 75: case 82: case 84: case 85: case 88:
            r = false;
            break;
        default:
            break;
        }
    }
    return r;
}
}   // namespace f3m_0040a620

// @f3 0x004098a0 (community match, verified in this file)
namespace f3m_004098a0 {
namespace f3m_004098a0 {
struct QRef {
    virtual ~QRef();
    virtual void DeleteThis();
    volatile long refCount;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!InterlockedDecrement(&refCount)) DeleteThis(); }
};
struct QBase {
    unsigned char type;
    void* next;
    QBase(unsigned char t) { type = t; next = 0; }
    ~QBase() { next = 0; }
};
struct Q84 : QBase {
    int unk0c;
    NiPointer<QRef> unk10;
    int unk14;
    int unk18;
    Q84(int a, QRef* b);
    virtual ~Q84();
};
// pdb: ExtraCellCanopyShadowMask::ExtraCellCanopyShadowMask | ExtraDataCell.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aeState, apTex
Q84::Q84(int a, QRef* b) : QBase(10)
{
    unk0c = a;
    unk10 = b;
    unk18 = 0;
}
}
}   // namespace f3m_004098a0
