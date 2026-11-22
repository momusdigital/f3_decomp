#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_009a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009b04e0 (community match, verified in this file)
class hkBool {
public:
    hkBool(bool b) { m_bool = static_cast<char>(b); }
    char m_bool;
};

class hkParentedNodeU {
public:
    hkParentedNodeU* getParent() const;
    hkBool hkClass_isSuperClass(const hkParentedNodeU* node) const;
    int unk00;
    hkParentedNodeU* m_parent;
};

__declspec(noinline) hkParentedNodeU* hkParentedNodeU::getParent() const
{
    return m_parent;
}

// pdb: hkClass::isSuperClass | hkClass.obj | fnv360_0822_retail, call_dedup + bridge(call_dedup|call_dedup) + skyrim(call_gap), high
hkBool hkParentedNodeU::hkClass_isSuperClass(const hkParentedNodeU* node) const
{
    while (node)
    {
        if (node == this)
            return true;
        node = node->getParent();
    }
    return false;
}

// @f3 0x009b01b0 (community match, verified in this file)
struct CallbackRecord {
    const char* name;
    void (__cdecl* callback)(void* context);
};
class CallbackTable {
public:
    CallbackRecord* FUN_009b10f0(const char* name, int flags);
};
class CallbackRegistry {
public:
    unsigned int unk00, unk04;
    CallbackTable table;
    CallbackRecord* hkTypeInfoRegistry_finishLoadedObject(void* context, const char* name);
};
// pdb: hkTypeInfoRegistry::finishLoadedObject | hkBuiltinTypeRegistry.obj | fnv360_0721_beta, objrun + skyrim(objrun_open), high
CallbackRecord* CallbackRegistry::hkTypeInfoRegistry_finishLoadedObject(void* context, const char* name) {
    CallbackRecord* record = table.FUN_009b10f0(name, 0);
    if (record) {
        if (record->callback)
            record->callback(context);
        return record;
    }
    return 0;
}

// @f3 0x009b6e20 (community match, verified in this file)
namespace f3m_009b6e20 {
namespace f3m_009b6e20 {

void __cdecl hkpBvTreeStreamAgent_createBvTreeShapeAgent();
void __cdecl FUN_009b59a0();
void __cdecl FUN_009b70d0();
void __cdecl FUN_009b7110();
void __cdecl hkpBvTreeStreamAgent_createShapeBvAgent();
void __cdecl FUN_009ba3c0();
void __cdecl FUN_009ba1b0();
void __cdecl FUN_009b9ff0();

struct AgentFuncs {
    void (__cdecl* m_createFunc)();
    void (__cdecl* m_getPenetrationsFunc)();
    void (__cdecl* m_getClosestPointsFunc)();
    void (__cdecl* m_linearCastFunc)();
    bool m_isFlipped;
    bool m_isPredictive;
};

class CollisionDispatcher {
public:
    void FUN_00985b30(AgentFuncs& funcs, int typeA, int typeB);
};

}

using namespace f3m_009b6e20;

// pdb: hkpBvTreeStreamAgent::registerAgent | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void __cdecl FUN_009b6e20(CollisionDispatcher* dispatcher)
{
    AgentFuncs af;
    af.m_createFunc = hkpBvTreeStreamAgent_createBvTreeShapeAgent;
    af.m_getPenetrationsFunc = FUN_009b59a0;
    af.m_getClosestPointsFunc = FUN_009b70d0;
    af.m_linearCastFunc = FUN_009b7110;
    af.m_isFlipped = true;
    af.m_isPredictive = true;
    dispatcher->FUN_00985b30(af, 9, 1);

    af.m_createFunc = hkpBvTreeStreamAgent_createShapeBvAgent;
    af.m_getPenetrationsFunc = FUN_009ba3c0;
    af.m_getClosestPointsFunc = FUN_009ba1b0;
    af.m_linearCastFunc = FUN_009b9ff0;
    af.m_isFlipped = false;
    af.m_isPredictive = true;
    dispatcher->FUN_00985b30(af, 1, 9);
}
}   // namespace f3m_009b6e20

// @f3 0x009b5da0 (community match, verified in this file)
namespace f3m_009b5da0 {
namespace f3m_009b5da0 {
class Collector
{
public:
    virtual void Slot00();
    virtual void BeginObject(const char* name, int type, const void* object);
    virtual void AddChunk(const char* name, int type, const void* data, int usedBytes, int allocatedBytes);
    int unk04;
};
struct PtrArray
{
    void** m_data;
    int m_size;
    int m_capacityAndFlags;
};
void FUN_00a26d90(PtrArray* array, int arg, Collector* collector);
class BvTreeAgent
{
public:
    char pad[0x30];
    PtrArray m_sectors;
    void hkpBvTreeStreamAgent_calcContentStatistics(Collector* collector);
};
}
using namespace f3m_009b5da0;
// pdb: hkpBvTreeStreamAgent::calcContentStatistics | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|vtable), high
void BvTreeAgent::hkpBvTreeStreamAgent_calcContentStatistics(Collector* collector)
{
    collector->BeginObject("BvTreeAgt3", 8, this);
    PtrArray* arr = &m_sectors;
    if ((arr->m_capacityAndFlags & 0x80000000) == 0)
        collector->AddChunk("SectorPtrs", 8, arr->m_data, arr->m_size * 4, (arr->m_capacityAndFlags & 0x3fffffff) * 4);
    FUN_00a26d90(arr, collector->unk04, collector);
}
}   // namespace f3m_009b5da0

// @f3 0x009b1a20 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009b1a20 {
namespace f3m_009b1a20 {
struct Allocator_1a20 { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
extern "C" __declspec(dllimport) Allocator_1a20* __stdcall TlsGetValue(unsigned int);

class RefObj_1a20 {
public:
    virtual void DeleteThis(int flag) throw();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference() throw()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};

class Map_1a20 {
public:
    int getIterator() const throw();
    char* isValid(char* out, int it) throw();
    int getValue(int it) throw();
    int getNext(int it) throw();
    void ClearEntries() throw();
    void FUN_009b1160() throw();
};

class Base_1a20 {
public:
    virtual ~Base_1a20() throw() {}
    int unk04;
};

struct Array_1a20 {
    void* data;
    int size;
    int capacityAndFlags;
    ~Array_1a20() throw()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int cap = capacityAndFlags & 0x3fffffff;
            Allocator_1a20* a = TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(data, cap * 4, 0x17);
        }
    }
};
}

class FUN_009b1a20 : public f3m_009b1a20::Base_1a20 {
public:
    f3m_009b1a20::Array_1a20 arr;
    f3m_009b1a20::Map_1a20 map;
    virtual ~FUN_009b1a20() throw();
};

// pdb: hkXmlStreamParser::_extractAttributes | hkXmlStreamParser.obj | tesv_win, objopen_prop, low
FUN_009b1a20::~FUN_009b1a20() throw()
{
    char valid;
    int it = map.getIterator();
    map.isValid(&valid, it);
    while (valid) {
        ((f3m_009b1a20::RefObj_1a20*)map.getValue(it))->removeReference();
        it = map.getNext(it);
        map.isValid(&valid, it);
    }
    map.ClearEntries();
    map.FUN_009b1160();
}
}   // namespace f3m_009b1a20

// @f3 0x009aea60 (community match, verified in this file)
namespace f3m_009aea60 {
// FUN_009aea60: thiscall, /MT /O2 /GS /EHsc /Gy. If unk00 is set, release unk00 and unk04 through a cdecl
// function pointer (second release unguarded), then zero the three fields.
extern void (__cdecl* DAT_00f7b4d0)(void* p);

class HandlePair_9aea60 {
public:
    void FUN_009aea60();
    void* unk00;
    void* unk04;
    unsigned int unk08;
};

void HandlePair_9aea60::FUN_009aea60()
{
    if (unk00 != 0) {
        DAT_00f7b4d0(unk00);
        DAT_00f7b4d0(unk04);
    }
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
}
}   // namespace f3m_009aea60

// @f3 0x009ba620 (community match, verified in this file)
namespace f3m_009ba620 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

namespace f3m_009ba620 {
struct Heap_9ba620
{
    void* FUN_008f6d30(unsigned int size, int kind);
};
struct Sub_9ba620
{
    char pad[0xa0];
    float m_a0;
};
struct Owner_9ba620
{
    int unk00;
    int unk04;
    Sub_9ba620* m_08;
};
class Base_9ba620
{
public:
    virtual void vf00();
    unsigned short m_memSize;
    short m_refCount;
    int m_08;
    int m_0c, m_10;
    unsigned int m_14;
    int unk18, unk1c;
    float m_20, m_24, m_28, m_2c;
    float m_30, m_34, m_38, m_3c;
    Base_9ba620(int a);
    static void* operator new(unsigned int size)
    {
        Heap_9ba620* heap = (Heap_9ba620*)TlsGetValue(DAT_010f3170);
        void* mem = heap->FUN_008f6d30(size, 0x1f);
        ((Base_9ba620*)mem)->m_memSize = (unsigned short)size;
        return mem;
    }
};
class Derived_9ba620 : public Base_9ba620
{
public:
    virtual void vf00();
    Derived_9ba620(int a) : Base_9ba620(a) {}
};
}
using namespace f3m_009ba620;

__declspec(noinline) Base_9ba620::Base_9ba620(int a)
{
    m_08 = a;
    m_refCount = 1;
    m_14 = 0x80000000;
    m_0c = 0;
    m_10 = 0;
    m_30 = m_34 = m_38 = m_3c = 3.40282e+38F;
    m_20 = m_24 = m_28 = m_2c = 3.40282e+38F;
}

Base_9ba620* FUN_009ba620(Owner_9ba620* a, Owner_9ba620* b, int unused, int arg)
{
    if (a->m_08->m_a0 < b->m_08->m_a0)
        return new Base_9ba620(arg);
    return new Derived_9ba620(arg);
}
}   // namespace f3m_009ba620

// @f3 0x009b0100 (community match, verified in this file)
namespace f3m_009b0100 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct MemAllocator {
    void FUN_008f6d90(void* p, unsigned int bytes, int kind);
};

struct ArrRaw {
    void** data;
    int size;
    unsigned int capAndFlags;
};

struct ItemSource {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void GetItems(ArrRaw* out);
};

class FUN_009b0100_cls {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void ImageSpaceEffectInterface_Render(void* item, bool flag);
    void hkDynamicClassNameRegistry_merge(ItemSource* src);
};

// pdb: hkDynamicClassNameRegistry::merge | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FUN_009b0100_cls::hkDynamicClassNameRegistry_merge(ItemSource* src)
{
    ArrRaw arr;
    arr.data = 0;
    arr.size = 0;
    arr.capAndFlags = 0x80000000;
    src->GetItems(&arr);
    for (int i = 0; i < arr.size; i++)
        ImageSpaceEffectInterface_Render(arr.data[i], false);
    if (arr.capAndFlags & 0x80000000)
        return;
    unsigned int n = arr.capAndFlags & 0x3fffffff;
    MemAllocator* a = (MemAllocator*)TlsGetValue(DAT_010f3170);
    a->FUN_008f6d90(arr.data, n * 4, 0x17);
}
}   // namespace f3m_009b0100

// @f3 0x009afa50 (community match, verified in this file)
extern int DAT_00e7e480;
extern int DAT_00dcc494;
extern int DAT_01169374;
extern int DAT_01169378;
extern int DAT_0116937c;
extern int DAT_01169380;
extern int DAT_01169384;
extern int DAT_01169388;
extern int DAT_0116938c;
extern int DAT_01169390;
extern int DAT_01169394;
extern void* DAT_01169398;
namespace f3m_009afa50 {
// FUN_009afa50: thiscall. Drops one reference; the last one clears 8 globals and frees the module handle.
// The two vtable slots are stored from extern DAT symbols (no virtual class needed).

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* h);


struct FUN_009afa50_cls {
    int unk00;
    void FUN_009afa50();
};

void FUN_009afa50_cls::FUN_009afa50()
{
    if (--DAT_01169394 == 0) {
        *(void**)this = &DAT_00e7e480;
        DAT_01169390 = 0;
        DAT_0116938c = 0;
        DAT_01169388 = 0;
        DAT_01169384 = 0;
        DAT_01169380 = 0;
        DAT_0116937c = 0;
        DAT_01169378 = 0;
        DAT_01169374 = 0;
        FreeLibrary(DAT_01169398);
        DAT_01169398 = 0;
    } else {
        *(void**)this = &DAT_00e7e480;
    }
    *(void**)this = &DAT_00dcc494;
}
}   // namespace f3m_009afa50

// @f3 0x009b30a0 (community match, verified in this file)
extern unsigned int g_tlsIndex;
namespace f3m_009b30a0 {

// thread-local chunk allocator
class hkThreadMemory {
public:
    void FUN_008f6f90(void* p) throw();
};

// one-byte "is this index usable" result, written by the map itself
class hkBoolOut {
public:
    char m_bool;
};

// the index bitmap / entry table that lives at this+8
class SlotMap {
public:
    int FUN_009b0dc0() const throw();
    int GetEntry(int idx) throw();
    int FindNextUsedSlot(int idx) throw();
    void SetBoolFromThreshold(hkBoolOut* out, int idx) throw();
    void FUN_009b1160() throw();

    void* m_data;
    int m_unk04;
    int m_count;
};

class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};

class FUN_009b30a0 : public hkBaseObject {
public:
    virtual ~FUN_009b30a0();

    int m_unk04;
    SlotMap m_map;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();

FUN_009b30a0::~FUN_009b30a0()
{
    int idx = m_map.FUN_009b0dc0();
    hkBoolOut valid;
    m_map.SetBoolFromThreshold(&valid, idx);
    while (valid.m_bool != 0)
    {
        void* entry = reinterpret_cast<void*>(m_map.GetEntry(idx));
        hkThreadMemory* tm = static_cast<hkThreadMemory*>(TlsGetValue(g_tlsIndex));
        tm->FUN_008f6f90(entry);
        idx = m_map.FindNextUsedSlot(idx);
        m_map.SetBoolFromThreshold(&valid, idx);
    }
    m_map.FUN_009b1160();
}
}   // namespace f3m_009b30a0

// @f3 0x009affd0 (community match, verified in this file)
namespace f3m_009affd0 {
// hkDynamicClassNameRegistry_getClasses - __thiscall, one stack parameter (the array), callee pops 4.
//
// Iterates an inner iterator object living at this+0xC.  For a valid element
// the value is appended to the array, then the iterator advances and is
// re-tested.  FUN_009b0e40 takes the out-flag first and the element second,
// which is what makes the argument pushes come out in this order.

struct hkInnerIterU {
    int FUN_009b0dc0();
    void FUN_009b0e40(bool* out, int value);
    int FUN_009b0df0(int value);
    int FUN_009b0e10(int value);
};

struct hkArrayU {
    int* m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
};

void __cdecl hkArrayEnsureSizeU(void* array, int elementSize);

class hkOwnerU {
public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    hkInnerIterU m_iter;
    void hkDynamicClassNameRegistry_getClasses(hkArrayU* values);
};

// pdb: hkDynamicClassNameRegistry::getClasses | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkOwnerU::hkDynamicClassNameRegistry_getClasses(hkArrayU* values)
{
    bool hasValue;
    int iter = m_iter.FUN_009b0dc0();
    m_iter.FUN_009b0e40(&hasValue, iter);
    if (!hasValue)
        return;
    while (hasValue) {
        int value = m_iter.FUN_009b0df0(iter);
        if (values->m_size == (int)(values->m_capacityAndFlags & 0x3fffffff))
            hkArrayEnsureSizeU(values, 4);
        int* insertion = values->m_data + values->m_size;
        values->m_size = values->m_size + 1;
        *insertion = value;
        iter = m_iter.FUN_009b0e10(iter);
        m_iter.FUN_009b0e40(&hasValue, iter);
    }
}
}   // namespace f3m_009affd0

// @f3 0x009a46d0 (community match, verified in this file)
namespace f3m_009a46d0 {
struct SortObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float x;
    float y;
    float z;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_priority;
    float LengthSquared() const { return x * x + y * y + z * z; }
};

struct SortEntry {
    int unk00;
    SortObject* m_object;
    int unk08;
};

struct SortList {
    SortEntry m_entries[4];
    int m_iNumberOfEntries;
};

// pdb: hkSimplexSolverSortInfo | hkpSimplexSolver.obj | tesv_win, call_dedup, low
void FUN_009a46d0(SortList* list)
{
    for (int i = 0; i < list->m_iNumberOfEntries - 1; i++) {
        for (int j = i + 1; j < list->m_iNumberOfEntries; j++) {
            SortEntry& a = list->m_entries[i];
            SortEntry& b = list->m_entries[j];
            if (a.m_object->m_priority < b.m_object->m_priority)
                continue;
            if (a.m_object->m_priority == b.m_object->m_priority &&
                a.m_object->LengthSquared() < b.m_object->LengthSquared())
                continue;
            SortEntry t = a;
            a = b;
            b = t;
        }
    }
}
}   // namespace f3m_009a46d0

// @f3 0x009ad920 (community match, verified in this file)
extern char DAT_00e7e090;
namespace f3m_009ad920 {
namespace f3m_009ad920 {
struct Sphere {
    float x, y, z, radius;
    Sphere& operator=(const Sphere& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        radius = other.radius;
        return *this;
    }
};
struct FUN_009ad920 {
    void* vtable;
    unsigned short memoryFlags04;
    unsigned short refs06;
    unsigned userData08;
    unsigned type0c;
    int count10;
    unsigned unk14, unk18, unk1c;
    Sphere spheres[8];
    FUN_009ad920(const Sphere* source, int count);
};
// pdb: hkpMultiSphereShape::hkpMultiSphereShape | hkpMultiSphereShape.obj | tesv_win, objrun, medium
FUN_009ad920::FUN_009ad920(const Sphere* source, int count)
{
    refs06 = 1;
    userData08 = 0;
    type0c = 0x14;
    vtable = &DAT_00e7e090;
    for (int i = 0; i < count; ++i)
        spheres[i] = source[i];
    count10 = count;
}
}
}   // namespace f3m_009ad920

// @f3 0x009b19d0 (community match, verified in this file)
namespace q19d0 {
struct QFlag { char v; };
struct QTable { int FUN_009b12f0() throw(); };
extern QTable DAT_00f79370;
struct QMap { QMap(QFlag f) throw(); int unk00; };
class QRef {
public:
    virtual ~QRef() throw() {}
    unsigned short memSizeAndFlags;
    short referenceCount;
    QRef() throw() { referenceCount = 1; }
};
struct QArr {
    QTable* data;
    int size;
    int capacityAndFlags;
    QArr(QTable* d, int n) throw() : data(d), size(n), capacityAndFlags(n | 0x80000000) {}
};
}
class FUN_009b19d0 : public q19d0::QRef {
public:
    q19d0::QArr arr;
    q19d0::QMap map;
    FUN_009b19d0() throw();
    virtual ~FUN_009b19d0() throw();
};
// pdb: hkXmlStreamParser::hkXmlStreamParser | hkXmlStreamParser.obj | tesv_win, caller_sim, low
FUN_009b19d0::FUN_009b19d0() throw()
    : arr(&q19d0::DAT_00f79370, q19d0::DAT_00f79370.FUN_009b12f0()), map(q19d0::QFlag())
{
}

// @f3 0x009b2130 (community match, verified in this file)
namespace f3m_009b2130 {
struct QAlloc9b {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
__declspec(dllimport) QAlloc9b* __stdcall FUN_00d9b080(int) throw();
extern int DAT_010f3170;
void FUN_009234e0(void* dst, const void* src, int size);

static __forceinline void* Alloc(int size)
{
    QAlloc9b* a = FUN_00d9b080(DAT_010f3170);
    return a->FUN_008f6d30(size, 0x17);
}

struct QBitField {
    unsigned int* m_words;
    int m_numWords;
    int m_numBitsAndFlags;
    void FUN_009b20f0(int fill);
    void FUN_009b2130(int numBits, int fill);
};

void QBitField::FUN_009b2130(int numBits, int fill)
{
    int numWords = (numBits + 31) >> 5;
    if (numBits == 0) {
        if (m_words) {
            if (!(m_numBitsAndFlags & 0x80000000))
                {
                QAlloc9b* a = FUN_00d9b080(DAT_010f3170);
                a->FUN_008f6d90(m_words, m_numWords * 4, 0x17);
            }
            m_words = 0;
        }
    } else if (!m_words) {
        m_words = (unsigned int*)Alloc(numWords * 4);
        unsigned int v = fill ? 0xffffffff : 0;
        m_numWords = numWords;
        for (int i = 0; i < m_numWords; i++)
            m_words[i] = v;
    } else if (numWords > m_numWords) {
        unsigned int* nw = (unsigned int*)Alloc(numWords * 4);
        FUN_009234e0(nw, m_words, m_numWords * 4);
        if (m_words && !(m_numBitsAndFlags & 0x80000000))
            {
                QAlloc9b* a = FUN_00d9b080(DAT_010f3170);
                a->FUN_008f6d90(m_words, m_numWords * 4, 0x17);
            }
        m_words = nw;
        FUN_009b20f0(fill);
        unsigned int v = fill ? 0xffffffff : 0;
        for (int i = m_numWords; i < numWords; i++)
            m_words[i] = v;
    } else if (numWords < m_numWords) {
        unsigned int* nw = (unsigned int*)Alloc(numWords * 4);
        FUN_009234e0(nw, m_words, numWords * 4);
        if (m_words && !(m_numBitsAndFlags & 0x80000000))
            {
                QAlloc9b* a = FUN_00d9b080(DAT_010f3170);
                a->FUN_008f6d90(m_words, m_numWords * 4, 0x17);
            }
        m_words = nw;
    } else {
        if ((m_numBitsAndFlags & 0x7fffffff) < numBits)
            FUN_009b20f0(fill);
        m_numBitsAndFlags = (m_numBitsAndFlags & 0x80000000) | numBits;
        return;
    }
    m_numWords = numWords;
    m_numBitsAndFlags = numBits;
}
}

// @f3 0x009a5e60 (community match, verified in this file)
namespace f3m_009a5e60 {
struct Terrain_5e60 {
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
 virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
 virtual void v08(); virtual void v09(); virtual void v10();
 virtual float getH(int x, int y);
 void FUN_009a5e60(int x, int y, float fx, float fy, float* nrm, float* height, int* flag);
};
// pdb: hkpSampledHeightFieldShape::getHeightAndNormalAt | hkpSampledHeightFieldShape.obj | tesv_win, objrun, medium
void Terrain_5e60::FUN_009a5e60(int x, int y, float fx, float fy, float* nrm, float* height, int* flag)
{
 nrm[0] = 1.0f;
 nrm[1] = 1.0f;
 nrm[2] = 1.0f;
 nrm[3] = 1.0f;
 float h10 = getH(x+1, y);
 float h01 = getH(x, y+1);
 if (fx + fy > 1.0) {
  float h11 = getH(x+1, y+1);
  float dx = h11 - h01;
  float dy = h11 - h10;
  *height = h10 + dy * fy + dx * (fx - 1.0);
  nrm[0] = -dx;
  nrm[2] = -dy;
  *flag = 1;
 } else {
  float h00 = getH(x, y);
  float dx = h10 - h00;
  float dy = h01 - h00;
  *height = h00 + dy * fy + dx * fx;
  nrm[0] = -dx;
  nrm[2] = -dy;
  *flag = 0;
 }
}
}   // namespace f3m_009a5e60

// @f3 0x009b4c20 (community match, verified in this file)
namespace f3m_009b4c20 {
struct T9b4c20 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void Target(); };
// pdb: hkBvTreeAgent3::getShapeContainerFrom | hkpBvTreeAgent3.obj | fnv360_0822_retail, call_seq, medium
// pdb params: body, buffer
void __cdecl FUN_009b4c20(T9b4c20** p) { (*p)->Target(); }
}   // namespace f3m_009b4c20

// @f3 0x009a8310 (community match, verified in this file)
namespace f3m_009a8310 {
struct T9a8310 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void Target(); };
T9a8310* __cdecl FUN_009a82b0();
void __cdecl FUN_009a8310() { FUN_009a82b0()->Target(); }
}   // namespace f3m_009a8310

// @f3 0x009b4ab0 (community match, verified in this file)
namespace f3m_009b4ab0 {
struct O9b4ab0 { int a[64]; void FUN_009b4ab0(int i, int v); };
void O9b4ab0::FUN_009b4ab0(int i, int v) { a[i] = v; }
}   // namespace f3m_009b4ab0

// @f3 0x009b12f0 (community match, verified in this file)
namespace f3m_009b12f0 {
struct O009b12f0 { int FUN_009b12f0(); };
// pdb: hkXmlLexAnalyzer::hkXmlLexAnalyzer | hkXmlLexAnalyzer.obj | tesv_win, caller, medium
int O009b12f0::FUN_009b12f0() { const int* p = (const int*)this; int n = 0; while (*p) { ++p; ++n; } return n; }
}   // namespace f3m_009b12f0

// @f3 0x009b1310 (community match, verified in this file)
namespace f3m_009b1310 {
struct O009b1310 { int FUN_009b1310(); };
int O009b1310::FUN_009b1310() { const int* p = (const int*)this; int n = 0; while (*p) { ++p; ++n; } return n; }
}   // namespace f3m_009b1310

// @f3 0x009b4c30 (community match, verified in this file)
namespace f3m_009b4c30 {
struct R9b4c30 { char pad[0xc]; int type; char pad2[0x24]; int val; };
// pdb: hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries | hkpBvTreeAgent3.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: body, buffer
int __cdecl FUN_009b4c30(R9b4c30** p) { R9b4c30* o = *p; if (o->type != 0xb) return 0; return o->val; }
}   // namespace f3m_009b4c30

// @f3 0x009afea0 (community match, verified in this file)
namespace f3m_009afea0 {
struct O9afea0 { int d0; char pad[0xc]; int d10; char pad2[0xc]; unsigned short w20; char pad3[2]; int d24; O9afea0* FUN_009afea0(); };
// pdb: hkpCollidable::BoundingVolumeData::BoundingVolumeData | hkpCollidable.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
O9afea0* O9afea0::FUN_009afea0() { w20 = 0; d24 = 0; d0 = 1; d10 = 0; return this; }
}   // namespace f3m_009afea0

// @f3 0x009a19e0 (community match, verified in this file)
namespace f3m_009a19e0 {
struct T9a19e0 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual int Slot(int a, int b); };
// pdb: hkBridgeConstraintAtom_callData | hkpConstraintAtom.obj | tesv_win, objrun_open, low
int __cdecl FUN_009a19e0(T9a19e0* o, int a, int b) { return o->Slot(a, b); }
}   // namespace f3m_009a19e0

// @f3 0x009b4a90 (community match, verified in this file)
namespace f3m_009b4a90 {
struct O9b4a90 { int a[100]; O9b4a90* FUN_009b4a90(int v); };
O9b4a90* O9b4a90::FUN_009b4a90(int v) { for (int i = 0; i < 100; i++) a[i] = v; return this; }
}   // namespace f3m_009b4a90

// @f3 0x009b4ac0 (community match, verified in this file)
namespace f3m_009b4ac0 {
struct G9b4ac0 { void FUN_00a21830(int a, int b, int c, int d, int e); };
void __cdecl FUN_009b4ac0(int a, int b, G9b4ac0* g, int d) { g->FUN_00a21830(a, d, d, 0, 0); }
}   // namespace f3m_009b4ac0

// @f3 0x009af3a0 (community match, verified in this file)
namespace f3m_009af3a0 {
// pdb: hkBufferedStreamReader::Buffer::~Buffer | hkBufferedStreamReader.obj | fnv360_0822_retail, objrun, medium
namespace f3m_009af3a0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { virtual void v0(); virtual void Set(int a); }; struct O { int a0; void FUN_009af3a0(); }; void O::FUN_009af3a0() { int v = a0; T* t = (T*)DAT_00d9b080(DAT_010f3170); t->Set(v); } }
}   // namespace f3m_009af3a0

// @f3 0x009a21d0 (community match, verified in this file)
namespace f3m_009a21d0 {
struct V009a21d0 { float x, y, z, w; };
struct O009a21d0 { char pad[0x30]; float x, y, z, w; void FUN_009a21d0(V009a21d0* out); };
// pdb: hkpCapsuleShape::getCentreImpl | hkpCapsuleShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpCapsuleShape::getCollisionSpheresImpl)
// pdb params: centreOut
void O009a21d0::FUN_009a21d0(V009a21d0* out) { out->x = x; out->y = y; out->z = z; out->w = w; }
}   // namespace f3m_009a21d0

// @f3 0x009af5f0 (community match, verified in this file)
namespace f3m_009af5f0 {
void __cdecl FUN_00c03d8b(unsigned int n);
struct O9af5f0 { int a0, a4; unsigned int count; unsigned char flag; void FUN_009af5f0(); };
// pdb: hkStdioStreamWriter::close | hkStdioStreamWriter.obj | fnv360_0822_retail, objrun, medium
void O9af5f0::FUN_009af5f0() { if (count > 0 && flag) FUN_00c03d8b(count); count = 0; }
}   // namespace f3m_009af5f0

// @f3 0x009a8320 (community match, verified in this file)
namespace f3m_009a8320 {
struct S9a8320 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void Slot7(int a, float b, int c); };
S9a8320* __cdecl FUN_009a82b0();
// pdb: hkpTriSampledHeightFieldBvTreeShape::castRayImpl | hkpTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: input, output
void __stdcall FUN_009a8320(int a, float b, int c) { FUN_009a82b0()->Slot7(a, b, c); }
}   // namespace f3m_009a8320

// @f3 0x009b2080 (community match, verified in this file)
namespace f3m_009b2080 {
namespace f3m_009b2080 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void FUN_009b19d0(); }; struct T { R* FUN_008f6d30(int a, int b); }; }
// pdb: hkXmlStreamParser::advance | hkXmlStreamParser.obj | tesv_win, objopen_prop, low
void __cdecl FUN_009b2080() { f3m_009b2080::T* t = (f3m_009b2080::T*)f3m_009b2080::DAT_00d9b080(f3m_009b2080::DAT_010f3170); f3m_009b2080::R* r = t->FUN_008f6d30(0x24, 0x15); r->w = 0x24; r->FUN_009b19d0(); }
}   // namespace f3m_009b2080

// @f3 0x009ae9d0 (community match, verified in this file)
namespace f3m_009ae9d0 {
struct Sub9ae9d0 { void FUN_009316f0() throw(); };
struct Base9ae9d0 { virtual ~Base9ae9d0() {} int pad[5]; };
class FUN_009ae9d0 : public Base9ae9d0 { public: Sub9ae9d0* p; virtual ~FUN_009ae9d0(); };
// pdb: hkpUnaryAction::~hkpUnaryAction | hkpUnaryAction.obj | fnv360_0822_retail, call_seq, high
FUN_009ae9d0::~FUN_009ae9d0() { if (p) { p->FUN_009316f0(); p = 0; } }
}   // namespace f3m_009ae9d0

// @f3 0x009afc10 (community match, verified in this file)
namespace f3m_009afc10 {
namespace f3m_009afc10 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void FUN_00a28d60(int a); }; struct T { R* FUN_008f6d30(int a, int b); }; }
// pdb: hkSocketCreate | hkSocket.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(objrun), high
void __cdecl hkSocketCreate() { f3m_009afc10::T* t = (f3m_009afc10::T*)f3m_009afc10::DAT_00d9b080(f3m_009afc10::DAT_010f3170); f3m_009afc10::R* r = t->FUN_008f6d30(0x24, 0x15); r->w = 0x24; r->FUN_00a28d60(-1); }
}   // namespace f3m_009afc10

// @f3 0x009b8200 (community match, verified in this file)
namespace f3m_009b8200 {
namespace f3m_009b8200 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void FUN_009b81b0(int a); }; struct T { R* FUN_008f6d30(int a, int b); }; }
void __cdecl FUN_009b8200(int a, int b, int c, int d) { f3m_009b8200::T* t = (f3m_009b8200::T*)f3m_009b8200::DAT_00d9b080(f3m_009b8200::DAT_010f3170); f3m_009b8200::R* r = t->FUN_008f6d30(0x40, 0x1f); r->w = 0x40; r->FUN_009b81b0(d); }
}   // namespace f3m_009b8200

// @f3 0x009a8350 (community match, verified in this file)
namespace f3m_009a8350 {
struct B9a8350 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void Slot8(int a, int b, int c); };
struct A9a8350 { B9a8350* FUN_009a7e90(); };
A9a8350* __cdecl FUN_009a82b0();
// pdb: hkpTriSampledHeightFieldBvTreeShape::castRayWithCollectorImpl | hkpTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: input, cdBody, collector
int __stdcall FUN_009a8350(int a, int b, int c) { FUN_009a82b0()->FUN_009a7e90()->Slot8(a, b, c); return a; }
}   // namespace f3m_009a8350

// @f3 0x009b0c90 (community match, verified in this file)
namespace f3m_009b0c90 {
namespace f3m_009b0c90 { extern char DAT_00e7e5e8; }
struct O9b0c90 { void* vt; unsigned short w4; unsigned short w6; int a8; int ac; int a10; int a14; O9b0c90* FUN_009b0c90(int a, int b, int c); };
O9b0c90* O9b0c90::FUN_009b0c90(int a, int b, int c) { ac = a; w6 = 1; vt = &f3m_009b0c90::DAT_00e7e5e8; a10 = b; a14 = 0; a8 = c; return this; }
}   // namespace f3m_009b0c90

// @f3 0x009a8230 (community match, verified in this file)
namespace f3m_009a8230 {
namespace f3m_009a8230 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009a8230 { char pad[4]; unsigned short w; void FUN_009a7ee0(); O009a8230* FUN_009a8230(unsigned int flags); };
// pdb: hkpTriSampledHeightFieldCollection::`scalar deleting destructor' | hkpTriSampledHeightFieldCollection.obj | fnv360_0822_retail, vtable_prefix, high
O009a8230* O009a8230::FUN_009a8230(unsigned int flags) { FUN_009a7ee0(); if (flags & 1) { f3m_009a8230::T* t = (f3m_009a8230::T*)f3m_009a8230::DAT_00d9b080(f3m_009a8230::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_009a8230

// @f3 0x009a9180 (community match, verified in this file)
namespace f3m_009a9180 {
namespace f3m_009a9180 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009a9180 { char pad[4]; unsigned short w; void FUN_009a9120(); O009a9180* FUN_009a9180(unsigned int flags); };
// pdb: hkBufferedStreamWriter::`scalar deleting destructor' | hkBufferedStreamWriter.obj | fnv360_0822_retail, vtable, high
O009a9180* O009a9180::FUN_009a9180(unsigned int flags) { FUN_009a9120(); if (flags & 1) { f3m_009a9180::T* t = (f3m_009a9180::T*)f3m_009a9180::DAT_00d9b080(f3m_009a9180::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_009a9180

// @f3 0x009af440 (community match, verified in this file)
namespace f3m_009af440 {
namespace f3m_009af440 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009af440 { char pad[4]; unsigned short w; void FUN_009af400(); O009af440* FUN_009af440(unsigned int flags); };
// pdb: hkBufferedStreamReader::`scalar deleting destructor' | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high
O009af440* O009af440::FUN_009af440(unsigned int flags) { FUN_009af400(); if (flags & 1) { f3m_009af440::T* t = (f3m_009af440::T*)f3m_009af440::DAT_00d9b080(f3m_009af440::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_009af440

// @f3 0x009af5a0 (community match, verified in this file)
namespace f3m_009af5a0 {
namespace f3m_009af5a0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009af5a0 { char pad[4]; unsigned short w; void FUN_009af540(); O009af5a0* FUN_009af5a0(unsigned int flags); };
// pdb: hkStdioStreamReader::`scalar deleting destructor' | hkStdioStreamReader.obj | fnv360_0822_retail, vtable, high
O009af5a0* O009af5a0::FUN_009af5a0(unsigned int flags) { FUN_009af540(); if (flags & 1) { f3m_009af5a0::T* t = (f3m_009af5a0::T*)f3m_009af5a0::DAT_00d9b080(f3m_009af5a0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_009af5a0

// @f3 0x009af770 (community match, verified in this file)
namespace f3m_009af770 {
namespace f3m_009af770 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009af770 { char pad[4]; unsigned short w; void FUN_009af750(); O009af770* FUN_009af770(unsigned int flags); };
// pdb: hkStackTracer::CallTree::insertCallStack | hkStackTracer.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkStdioStreamWriter::`scalar deleting destructor')
// pdb params: tracer
O009af770* O009af770::FUN_009af770(unsigned int flags) { FUN_009af750(); if (flags & 1) { f3m_009af770::T* t = (f3m_009af770::T*)f3m_009af770::DAT_00d9b080(f3m_009af770::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_009af770

// @f3 0x009afab0 (community match, verified in this file)
namespace f3m_009afab0 {
namespace f3m_009afab0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009afab0 { char pad[4]; unsigned short w; void FUN_009afa50(); O009afab0* FUN_009afab0(unsigned int flags); };
// pdb: hkStackTracer::`scalar deleting destructor' | hkStackTracer.obj | fnv360_0721_beta, vtable, high
O009afab0* O009afab0::FUN_009afab0(unsigned int flags) { FUN_009afa50(); if (flags & 1) { f3m_009afab0::T* t = (f3m_009afab0::T*)f3m_009afab0::DAT_00d9b080(f3m_009afab0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_009afab0

// @f3 0x009afd30 (community match, verified in this file)
namespace f3m_009afd30 {
namespace f3m_009afd30 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009afd30 { char pad[4]; unsigned short w; void FUN_009ae9d0(); O009afd30* FUN_009afd30(unsigned int flags); };
// pdb: hkLiquidAction::`scalar deleting destructor' | hkLiquidAction.obj | fnv360_0822_retail, caller_sim, low
O009afd30* O009afd30::FUN_009afd30(unsigned int flags) { FUN_009ae9d0(); if (flags & 1) { f3m_009afd30::T* t = (f3m_009afd30::T*)f3m_009afd30::DAT_00d9b080(f3m_009afd30::DAT_010f3170); t->FUN_008f6d90(this, w, 0x29); } return this; }
}   // namespace f3m_009afd30

// @f3 0x009b1460 (community match, verified in this file)
namespace f3m_009b1460 {
namespace f3m_009b1460 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct HkArr9b {
    int* data; int size; unsigned int capFlags;
    void Push(int v) {
        if (size == (int)(capFlags & 0x3fffffff)) FUN_00901f10(this, 4);
        data[size] = v;
        size = size + 1;
    }
};
struct O9b1460 { int unk00; int unk04; HkArr9b arr; void FUN_009b1460(int v); };
void O9b1460::FUN_009b1460(int v) { arr.Push(v); }
}
}   // namespace f3m_009b1460

// @f3 0x009b4910 (community match, verified in this file)
namespace f3m_009b4910 {
namespace f3m_009b4910 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009b4910 { char pad[4]; unsigned short w; void FUN_009b31d0(); O009b4910* FUN_009b4910(unsigned int flags); };
// pdb: hkObjectCopier::`scalar deleting destructor' | hkObjectCopier.obj | fnv360_0721_beta, vtable_prefix, low
O009b4910* O009b4910::FUN_009b4910(unsigned int flags) { FUN_009b31d0(); if (flags & 1) { f3m_009b4910::T* t = (f3m_009b4910::T*)f3m_009b4910::DAT_00d9b080(f3m_009b4910::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_009b4910

// @f3 0x009afd00 (community match, verified in this file)
namespace f3m_009afd00 {
struct B_009afd00 { virtual void v0(); int pad[7]; B_009afd00(int a, int b); };
struct V4_009afd00 { float x, y, z, w; V4_009afd00() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {} };
struct FUN_009afd00 : B_009afd00 { V4_009afd00 v; FUN_009afd00(int a, int b); virtual void v0(); };
// pdb: hkLiquidAction::hkLiquidAction | hkLiquidAction.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: `anonymous namespace'::hkpTiltPreventAction::hkpTiltPreventAction)
// pdb params: entityA, userData
FUN_009afd00::FUN_009afd00(int a, int b) : B_009afd00(a, b) {}
}   // namespace f3m_009afd00

// @f3 0x009afc50 (community match, verified in this file)
namespace f3m_009afc50 {
namespace f3m_009afc50 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009afc50 { void* vt; unsigned short w; O009afc50* FUN_009afc50(unsigned int flags); };
// pdb: hkSocket::ReaderAdapter::`scalar deleting destructor' | hkSocket.obj | fnv360_0822_debug, objrun_sim, low
O009afc50* O009afc50::FUN_009afc50(unsigned int flags) { vt = &f3m_009afc50::DAT_00dcc494; if (flags & 1) { f3m_009afc50::T* t = (f3m_009afc50::T*)f3m_009afc50::DAT_00d9b080(f3m_009afc50::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_009afc50

// @f3 0x009b1160 (community match, verified in this file)
namespace f3m_009b1160 {
extern unsigned long DAT_010f3170;
struct Alloc1160 { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
extern "C" __declspec(dllimport) Alloc1160* __stdcall TlsGetValue(unsigned long);
struct Map1160 { void* data; int unk04; int cap; void FUN_009b1160(); };
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> | hkStringMap.obj | fnv360_0822_retail, call_seq, medium
void Map1160::FUN_009b1160() {
    int count = (cap + 1) * 3;
    void* d = data;
    Alloc1160* a = TlsGetValue(DAT_010f3170);
    a->FUN_008f6d90(d, count * 4, 0x17);
}
}

// @f3 0x009afec0 (community match, verified in this file)
namespace f3m_009afec0 {
struct Inner_9afec0 { virtual void v0(); virtual void v1(); };
struct Node_9afec0 { int unk00; int unk04; int unk08; int type; Inner_9afec0 inner; };
struct Holder_9afec0 { Node_9afec0* p; void FUN_009afec0(); };
void Holder_9afec0::FUN_009afec0() {
    if (p) {
        if (p->type == 10) p->inner.v1();
        if (p->type == 8) p->inner.v1();
    }
}
}   // namespace f3m_009afec0

// @f3 0x009aea00 (community match, verified in this file)
namespace f3m_009aea00 {
namespace f3m_009aea00 { struct Arr { int* data; unsigned int size; unsigned int cap; }; void __cdecl FUN_00901f10(Arr* a, int n); }
struct O9aea00 { char pad[0x18]; int f18; void hkpUnaryAction_getEntities(f3m_009aea00::Arr* a); };
// pdb: hkpUnaryAction::getEntities | hkpUnaryAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void O9aea00::hkpUnaryAction_getEntities(f3m_009aea00::Arr* a) { using namespace f3m_009aea00; if (a->size == (a->cap & 0x3fffffff)) FUN_00901f10(a, 4); a->data[a->size] = f18; a->size++; }
}   // namespace f3m_009aea00

// @f3 0x009a21f0 (community match, verified in this file)
namespace f3m_009a21f0 {
struct V8_9a21f0 { float a, b, c, d, e, f, g, h; };
struct O9a21f0 { char pad[0x20]; float f0, f1, f2, f3, f4, f5, f6, f7; void FUN_009a21f0(V8_9a21f0* out); };
// pdb: hkArrayBase<hkpAgentNnSector *>::_clearAndDeallocate | hkpWorldOperationUtil.obj | fnv360_0822_debug, objrun_open, low
// pdb params: alloc
void O9a21f0::FUN_009a21f0(V8_9a21f0* out) { out->a = f0; out->b = f1; out->c = f2; out->d = f3; out->e = f4; out->f = f5; out->g = f6; out->h = f7; }
}   // namespace f3m_009a21f0

// @f3 0x009afc90 (community match, verified in this file)
namespace f3m_009afc90 {
namespace f3m_009afc90 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O9afc90 { void* vt0; unsigned short w; char pad[2]; void* vt8; char pad2[8]; void* vt14; O9afc90* FUN_009afc90(unsigned int flags); };
O9afc90* O9afc90::FUN_009afc90(unsigned int flags) { void* v = &f3m_009afc90::DAT_00dcc494; vt14 = v; vt8 = v; vt0 = v; if (flags & 1) { f3m_009afc90::T* t = (f3m_009afc90::T*)f3m_009afc90::DAT_00d9b080(f3m_009afc90::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_009afc90

// @f3 0x009b0060 (community match, verified in this file)
namespace f3m_009b0060 {
namespace f3m_009b0060 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; struct M { void FUN_009b1160(); }; }
struct O009b0060 { void* vt; unsigned short w; char pad[6]; f3m_009b0060::M m; O009b0060* FUN_009b0060(unsigned int flags); };
// pdb: hkDynamicClassNameRegistry::`scalar deleting destructor' | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable, high
O009b0060* O009b0060::FUN_009b0060(unsigned int flags) { m.FUN_009b1160(); vt = &f3m_009b0060::DAT_00dcc494; if (flags & 1) { f3m_009b0060::T* t = (f3m_009b0060::T*)f3m_009b0060::DAT_00d9b080(f3m_009b0060::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_009b0060

// @f3 0x009b0290 (community match, verified in this file)
namespace f3m_009b0290 {
namespace f3m_009b0290 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; struct M { void FUN_009b1160(); }; }
struct O009b0290 { void* vt; unsigned short w; char pad[2]; f3m_009b0290::M m; O009b0290* FUN_009b0290(unsigned int flags); };
// pdb: hkTypeInfoRegistry::`scalar deleting destructor' | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, vtable_prefix, high
O009b0290* O009b0290::FUN_009b0290(unsigned int flags) { m.FUN_009b1160(); vt = &f3m_009b0290::DAT_00dcc494; if (flags & 1) { f3m_009b0290::T* t = (f3m_009b0290::T*)f3m_009b0290::DAT_00d9b080(f3m_009b0290::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_009b0290

// @f3 0x009b5e60 (community match, verified in this file)
namespace f3m_009b5e60 {
namespace f3m_009b5e60 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void* FUN_009b5e00(int a, int b, int c, int d); }; struct T { R* FUN_008f6d30(int a, int b); }; }
// pdb: hkpBvTreeStreamAgent::createShapeBvAgent | hkpBvTreeStreamAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(objrun), high
void* __cdecl hkpBvTreeStreamAgent_createShapeBvAgent(int a, int b, int c, int d) { f3m_009b5e60::T* t = (f3m_009b5e60::T*)f3m_009b5e60::DAT_00d9b080(f3m_009b5e60::DAT_010f3170); f3m_009b5e60::R* r = t->FUN_008f6d30(0x40, 0x1f); r->w = 0x40; return r->FUN_009b5e00(a, b, c, d); }
}   // namespace f3m_009b5e60

// @f3 0x009baee0 (community match, verified in this file)
namespace f3m_009baee0 {
namespace f3m_009baee0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void* FUN_009bae50(int a, int b, int c, int d); }; struct T { R* FUN_008f6d30(int a, int b); }; }
// pdb: hkpHeightFieldAgent::createHeightFieldBAgent | hkpHeightFieldAgent.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: bodyA, bodyB, input, mgr
void* __cdecl FUN_009baee0(int a, int b, int c, int d) { f3m_009baee0::T* t = (f3m_009baee0::T*)f3m_009baee0::DAT_00d9b080(f3m_009baee0::DAT_010f3170); f3m_009baee0::R* r = t->FUN_008f6d30(0x18, 0x1f); r->w = 0x18; return r->FUN_009bae50(a, b, c, d); }
}   // namespace f3m_009baee0

// @f3 0x009bf0c0 (community match, verified in this file)
namespace f3m_009bf0c0 {
namespace f3m_009bf0c0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void* FUN_009bf070(int a, int b, int c, int d); }; struct T { R* FUN_008f6d30(int a, int b); }; }
// pdb: hkpListAgent::createListBAgent | hkpListAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(objrun), high
void* __cdecl hkpListAgent_createListBAgent(int a, int b, int c, int d) { f3m_009bf0c0::T* t = (f3m_009bf0c0::T*)f3m_009bf0c0::DAT_00d9b080(f3m_009bf0c0::DAT_010f3170); f3m_009bf0c0::R* r = t->FUN_008f6d30(0x1c, 0x1f); r->w = 0x1c; return r->FUN_009bf070(a, b, c, d); }
}   // namespace f3m_009bf0c0

// @f3 0x009b6eb0 (community match, verified in this file)
namespace f3m_009b6eb0 {
namespace task0798 {
void hkpBvTreeStreamAgent_createBvTreeShapeAgent(); void FUN_009b59a0(); void FUN_009b70d0(); void FUN_009b7110();
void hkpBvTreeStreamAgent_createShapeBvAgent(); void FUN_009ba3c0(); void FUN_009ba1b0(); void FUN_009b9ff0();
struct AgentFunctions {
 void (*create)(); void (*getPenetrations)(); void (*getClosestPoints)(); void (*linearCast)();
 bool flipped; bool predictive;
};
struct Registry { void FUN_00985b30(AgentFunctions*, int, int); };
// pdb: hkpBvTreeStreamAgent::registerMultiRayAgent | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009b6eb0(Registry* registry) {
 AgentFunctions entry;
 entry.create=hkpBvTreeStreamAgent_createBvTreeShapeAgent;
 entry.getPenetrations=FUN_009b59a0;
 entry.getClosestPoints=FUN_009b70d0;
 entry.linearCast=FUN_009b7110;
 entry.flipped=true;
 entry.predictive=true;
 registry->FUN_00985b30(&entry,9,23);
 entry.create=hkpBvTreeStreamAgent_createShapeBvAgent;
 entry.getPenetrations=FUN_009ba3c0;
 entry.getClosestPoints=FUN_009ba1b0;
 entry.linearCast=FUN_009b9ff0;
 entry.flipped=false;
 entry.predictive=true;
 registry->FUN_00985b30(&entry,23,9);
}
}
}   // namespace f3m_009b6eb0

// @f3 0x009b7040 (community match, verified in this file)
namespace f3m_009b7040 {
namespace Task0797 {
void FUN_009b6f40();
void FUN_009b59a0();
void FUN_009b70d0();
void FUN_009b7110();
void FUN_009b6cf0();
void FUN_009ba3c0();
void FUN_009ba1b0();
void FUN_009b9ff0();
struct Conversion {
 void (*convert)(); void (*create)(); void (*copy)(); void (*destroy)();
 bool enabled; bool supported;
};
struct Registry {void FUN_00985b30(Conversion*,int,int);};
// @fnv 0x009b7040
// pdb: hkpBvTreeStreamAgent::registerConvexListAgent | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: dispatcher
void FUN_009b7040(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = FUN_009b6f40;
    conversionEntry.create = FUN_009b59a0;
    conversionEntry.copy = FUN_009b70d0;
    conversionEntry.destroy = FUN_009b7110;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 9, 21);
    conversionEntry.convert = FUN_009b6cf0;
    conversionEntry.create = (void (*)())FUN_009ba3c0;
    conversionEntry.copy = FUN_009ba1b0;
    conversionEntry.destroy = FUN_009b9ff0;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 21, 9);
}

}
}   // namespace f3m_009b7040

// @f3 0x009a1f60 (community match, verified in this file)
extern char DAT_00e7deb0;
namespace f3m_009a1f60 {
struct Tgt_9a1f60 {
    virtual void t0(); virtual void v1(const char* s, int a, void* b); virtual void t2(); virtual void t3(); virtual void t4(); virtual void t5();
    virtual int v6();
};
struct O_9a1f60 { int FUN_009a1f60(Tgt_9a1f60* t); };
// pdb: hkpSoftContactModifierConstraintAtom::collisionResponseBeginCallback | hkpConstraintAtom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: cp, inA, velA, inB, velB
int O_9a1f60::FUN_009a1f60(Tgt_9a1f60* t) {
    t->v1(&DAT_00e7deb0, 1, this);
    return t->v6();
}
}   // namespace f3m_009a1f60

// @f3 0x009bbcc0 (community match, verified in this file)
namespace f3m_009bbcc0 {
namespace task0796 {
void hkpHeightFieldAgent_staticGetPenetrations();
void hkpHeightFieldAgent_createHeightFieldAAgent();
void FUN_009bc450();
void FUN_009bc490();
void FUN_009bc4d0();
void FUN_009baee0();

void hkpHeightFieldAgent_staticGetClosestPoints();
void hkpHeightFieldAgent_staticLinearCast();
struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void FUN_00985b30(Conversion*, int, int);
};
// @fnv 0x00d2e760
// pdb: hkpHeightFieldAgent::registerAgent | hkpHeightFieldAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009bbcc0(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpHeightFieldAgent_createHeightFieldAAgent;
    conversionEntry.create = FUN_009bc450;
    conversionEntry.copy = FUN_009bc490;
    conversionEntry.destroy = FUN_009bc4d0;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 24, 25);
    conversionEntry.convert = FUN_009baee0;
    conversionEntry.create = (void (*)())hkpHeightFieldAgent_staticGetPenetrations;
    conversionEntry.copy = hkpHeightFieldAgent_staticGetClosestPoints;
    conversionEntry.destroy = hkpHeightFieldAgent_staticLinearCast;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 25, 24);
}

}
}   // namespace f3m_009bbcc0

// @f3 0x009aeaa0 (community match, verified in this file)
namespace f3m_009aeaa0 {
struct Item_9aeaa0 {
    int m_data[21];
};

extern void* (__cdecl* DAT_00f7b4cc)(unsigned int size, int kind);
extern void (__cdecl* DAT_00f7b4d0)(void* p);
void __cdecl FUN_00990430(void** arr, int lo, int hi, void* cmp);
void __cdecl FUN_009aea40(void* out, void* a, void* b);

class Sorted_9aeaa0 {
public:
    void** m_ptrs;
    Item_9aeaa0* m_items;
    int m_count;
    void FUN_009aeaa0();
};

// pdb: hkFreeList::_calcBlockFree | hkFreeList.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: block
void Sorted_9aeaa0::FUN_009aeaa0()
{
    if (m_count <= 1)
        return;
    void** tmp = (void**)DAT_00f7b4cc(m_count * 4, 0x10);
    for (int i = 0; i < m_count; ++i)
        tmp[i] = &m_ptrs[i];
    if (m_count > 1)
        FUN_00990430(tmp, 0, m_count - 1, (void*)FUN_009aea40);
    void** newPtrs = (void**)DAT_00f7b4cc(m_count * 4, 0x10);
    Item_9aeaa0* newItems = (Item_9aeaa0*)DAT_00f7b4cc(m_count * 0x54, 0x10);
    for (int i = 0; i < m_count; ++i) {
        newPtrs[i] = *(void**)tmp[i];
        int idx = ((int)tmp[i] - (int)m_ptrs) >> 2;
        newItems[i] = m_items[idx];
    }
    DAT_00f7b4d0(tmp);
    DAT_00f7b4d0(m_ptrs);
    DAT_00f7b4d0(m_items);
    m_ptrs = newPtrs;
    m_items = newItems;
}
}   // namespace f3m_009aeaa0

// @f3 0x009ba5e0 (community match, verified in this file)
namespace f3m_009ba5e0 {
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern char DAT_00e7eba4;
extern char DAT_00e7eaac;
struct Base {
    void* vt;
    unsigned short w;
    unsigned short unk6;
    int unk8;
    int unkc;
    int unk10;
    unsigned int unk14;
    __declspec(noinline) Base* FUN_009b81b0(int a);
};
Base* Base::FUN_009b81b0(int a) {
    unk8 = a;
    unk6 = 1;
    vt = &DAT_00e7eaac;
    unk14 = 0x80000000;
    unkc = 0;
    unk10 = 0;
    return this;
}
struct Heap { Base* FUN_008f6d30(int size, int kind); };
Base* __cdecl FUN_009ba5e0(int a, int b, int c, int d) {
    Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
    Base* r = heap->FUN_008f6d30(0x40, 0x1f);
    r->w = 0x40;
    r->FUN_009b81b0(d);
    r->vt = &DAT_00e7eba4;
    return r;
}
}

// @f3 0x009bf130 (community match, verified in this file)
namespace n9bf130 {
extern int DAT_010f3170;
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
struct Base {
    virtual ~Base();
    unsigned short memSize;
    short refCount;
    Base(int a, int b, int c, int d) throw();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x1f);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x1f);
    }
    char pad[0x1c - 8];
};
struct Derived : Base {
    Derived(int a, int b, int c, int d) throw() : Base(a, b, c, d) {}
    virtual ~Derived();
};
}
// pdb: hkpListAgent::createListAAgent | hkpListAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
n9bf130::Base* hkpListAgent_createListAAgent(int a, int b, int c, int d) {
    return new n9bf130::Derived(b, a, c, d);
}

// @f3 0x009b08a0 (community match, verified in this file)
namespace f3m_009b08a0 {
namespace config_constructor {
struct FUN_009b08a0 {
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
    unsigned int unk28;
    unsigned int unk2c;
    FUN_009b08a0(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7,unsigned int a8,unsigned int a9,unsigned int a10,unsigned int a11,unsigned int a12);
};
// pdb: hkClass::hkClass | hkClass.obj | tesv_win, objrun_sim, low
FUN_009b08a0::FUN_009b08a0(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7,unsigned int a8,unsigned int a9,unsigned int a10,unsigned int a11,unsigned int a12) : unk00(a1),unk04(a2),unk08(a3),unk0c(a5),unk10(a6),unk14(a7),unk18(a8),unk1c(a9),unk20(a10),unk24(a11),unk28(a12),unk2c(0) {}
}
}   // namespace f3m_009b08a0

// @f3 0x009b5b80 (community match, verified in this file)
namespace f3m_009b5b80 {
namespace collision_agent_registration_009b5b80 {
void FUN_009b59a0();
void FUN_009b59e0();
void hkpBvTreeStreamAgent_createShapeBvAgent();
void hkpBvTreeStreamAgent_createBvTreeShapeAgent();
void FUN_009b70d0();
void hkpMoppAgent_staticLinearCast();
void hkpMoppAgent_createBvBvAgent();
void FUN_009ba1b0();
void FUN_009ba3c0();
struct AgentFunctions {
    void (*create)();
    void (*penetrations)();
    void (*closestPoints)();
    void (*linearCast)();
    bool flipped;
    bool predictive;
};
struct Dispatcher { void FUN_00985b30(const AgentFunctions&,int,int); };
// pdb: hkpMoppBvTreeStreamAgent::registerAgent | hkpMoppBvTreeStreamAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void FUN_009b5b80(Dispatcher* dispatcher) {
    AgentFunctions functions;
    functions.create=hkpBvTreeStreamAgent_createBvTreeShapeAgent;
    functions.penetrations=FUN_009b59a0;
    functions.closestPoints=FUN_009b70d0;
    functions.linearCast=FUN_009b59e0;
    functions.flipped=true;functions.predictive=true;
    dispatcher->FUN_00985b30(functions,11,1);
    functions.create=hkpBvTreeStreamAgent_createShapeBvAgent;
    functions.penetrations=FUN_009ba3c0;
    functions.closestPoints=FUN_009ba1b0;
    functions.linearCast=hkpMoppAgent_staticLinearCast;
    functions.flipped=false;functions.predictive=true;
    dispatcher->FUN_00985b30(functions,1,11);
    functions.create=hkpMoppAgent_createBvBvAgent;
    functions.penetrations=FUN_009ba3c0;
    functions.closestPoints=FUN_009ba1b0;
    functions.linearCast=hkpMoppAgent_staticLinearCast;
    functions.flipped=false;functions.predictive=true;
    dispatcher->FUN_00985b30(functions,11,11);
}
}
}   // namespace f3m_009b5b80

// @f3 0x009be540 (community match, verified in this file)
namespace f3m_009be540 {
namespace collision_agent_registration_009be540 {
void FUN_009bd790();
void FUN_009bd940();
void hkpConvexListAgent_staticLinearCast();
void FUN_009bdb80();
void hkpConvexListAgent_createConvexConvexListAgent();
void hkpConvexListAgent_createConvexListConvexListAgent();
void FUN_009be820();
void FUN_009be860();
void FUN_009be8a0();
struct AgentFunctions {
    void (*create)();
    void (*penetrations)();
    void (*closestPoints)();
    void (*linearCast)();
    bool flipped;
    bool predictive;
};
struct Dispatcher { void FUN_00985b30(const AgentFunctions&,int,int); };
// pdb: hkpConvexListAgent::registerAgent | hkpConvexListAgent.obj | fnv360_0822_retail, objrun_sim + bridge(caller_sim|objrun) + skyrim(caller_sim), high
void hkpConvexListAgent_registerAgent(Dispatcher* dispatcher) {
    AgentFunctions functions;
    functions.create=FUN_009bdb80;
    functions.penetrations=FUN_009be820;
    functions.closestPoints=FUN_009be860;
    functions.linearCast=FUN_009be8a0;
    functions.flipped=true;functions.predictive=true;
    dispatcher->FUN_00985b30(functions,21,1);
    functions.create=hkpConvexListAgent_createConvexConvexListAgent;
    functions.penetrations=FUN_009bd940;
    functions.closestPoints=FUN_009bd790;
    functions.linearCast=hkpConvexListAgent_staticLinearCast;
    functions.flipped=false;functions.predictive=true;
    dispatcher->FUN_00985b30(functions,1,21);
    functions.create=hkpConvexListAgent_createConvexListConvexListAgent;
    functions.penetrations=FUN_009bd940;
    functions.closestPoints=FUN_009bd790;
    functions.linearCast=hkpConvexListAgent_staticLinearCast;
    functions.flipped=false;functions.predictive=true;
    dispatcher->FUN_00985b30(functions,21,21);
}
}
}   // namespace f3m_009be540

// @f3 0x009bbc70 (community match, verified in this file)
#include <new>
extern unsigned int DAT_010f3170;
namespace f3m_009bbc70 {
namespace symmetric_heightfield_factory {
struct CollisionBody;
struct CollisionInput;
struct ContactManager;
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct MemoryManager { void* FUN_008f6d30(int,int); };
struct hkpHeightFieldAgent {
    virtual ~hkpHeightFieldAgent() throw();
    unsigned short memorySizeAndFlags,referenceCount;
    unsigned int unk08,unk0c,unk10,unk14;
    hkpHeightFieldAgent(const CollisionBody&,const CollisionBody&,const CollisionInput&,ContactManager*) throw();
};
template<class Agent> struct hkpSymmetricAgent : Agent {
    __forceinline hkpSymmetricAgent(const CollisionBody& first,const CollisionBody& second,const CollisionInput& input,ContactManager* manager) throw() : Agent(second,first,input,manager) {}
};
// pdb: hkpHeightFieldAgent::createHeightFieldAAgent | hkpHeightFieldAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
hkpSymmetricAgent<hkpHeightFieldAgent>* hkpHeightFieldAgent_createHeightFieldAAgent(const CollisionBody& first,const CollisionBody& second,const CollisionInput& input,ContactManager* manager) {
    MemoryManager* allocator=static_cast<MemoryManager*>(DAT_00d9b080(DAT_010f3170));
    hkpSymmetricAgent<hkpHeightFieldAgent>* agent=static_cast<hkpSymmetricAgent<hkpHeightFieldAgent>*>(allocator->FUN_008f6d30(sizeof(hkpSymmetricAgent<hkpHeightFieldAgent>),31));
    agent->memorySizeAndFlags=sizeof(hkpSymmetricAgent<hkpHeightFieldAgent>);
    __assume(agent!=0);
    return ::new(agent) hkpSymmetricAgent<hkpHeightFieldAgent>(first,second,input,manager);
}
}
}   // namespace f3m_009bbc70

// @f3 0x009b2f10 (community match, verified in this file)
namespace n9b2f10 {
extern int DAT_010f3170;
struct Alloc { void* FUN_008f6d30(int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
struct Tag { char c; };
struct Map {
    char pad[0x10];
    void FUN_009b1110(Tag t);
    int FUN_009b0fb0(const char* key, const char** out);
    void FUN_009b0e60(const char* key, const char* value);
};
struct RefObj {
    unsigned short memSize;
    short refCount;
    RefObj() : refCount(1) {}
    virtual ~RefObj();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 5);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};
struct Pair { int id; const char* name; };
struct PairArray;
void __cdecl FUN_00901f10(PairArray* a, int elemSize);
struct PairArray {
    Pair* data; int size; int capAndFlags;
    void pushBack(const Pair& p) {
        if (size == (capAndFlags & 0x3fffffff))
            FUN_00901f10(this, 8);
        data[size++] = p;
    }
};
const char* __cdecl FUN_00923640(const char* s);
}
struct hkRelocationInfo {
    struct StringPool : n9b2f10::RefObj {
        n9b2f10::Map map;
        StringPool() throw() { n9b2f10::Tag t = { 0 }; map.FUN_009b1110(t); }
        virtual ~StringPool();
        const char* insert(const char* str) {
            const char* out;
            if (map.FUN_009b0fb0(str, &out) == 0)
                return out;
            const char* d = n9b2f10::FUN_00923640(str);
            map.FUN_009b0e60(d, d);
            return d;
        }
    };
};
struct FUN_009b2f10_c {
    char pad[0x24];
    n9b2f10::PairArray names;
    hkRelocationInfo::StringPool* pool;
    void FUN_009b2f10(int id, const char* name);
};
// pdb: hkRelocationInfo::addImport | hkRelocationInfo.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: off, name
void FUN_009b2f10_c::FUN_009b2f10(int id, const char* name)
{
    if (!pool) {
        pool = new hkRelocationInfo::StringPool;
    }
    const char* s = pool->insert(name);
    n9b2f10::Pair p;
    p.id = id;
    p.name = s;
    names.pushBack(p);
}

// @f3 0x009b00a0 (community match, verified in this file)
#include <new>
extern unsigned int DAT_010f3170;
extern const char str_00e79fb4[];
namespace f3m_009b00a0 {
namespace default_registry_factory {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct MemoryManager { void* FUN_008f6d30(int,int); };
struct FinishFlag { bool finishing; FinishFlag(bool value):finishing(value) {} };
struct StringMap { void* data; int count,capacity; StringMap(FinishFlag) throw(); };
struct hkReferencedObject {
    virtual ~hkReferencedObject() throw();
    unsigned short memorySizeAndFlags,referenceCount;
    __forceinline hkReferencedObject() throw() : referenceCount(1) {}
};
struct hkDynamicClassNameRegistry : hkReferencedObject {
    const char* version;
    StringMap classes;
    __forceinline hkDynamicClassNameRegistry() throw() : version(str_00e79fb4),classes(FinishFlag(false)) {}
};
struct hkDefaultClassNameRegistry : hkDynamicClassNameRegistry {
    __forceinline hkDefaultClassNameRegistry() throw() {}
};
// pdb: hkDefaultClassNameRegistry::hkDefaultClassNameRegistry | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, uvref, medium
hkDefaultClassNameRegistry* FUN_009b00a0() {
    MemoryManager* allocator=static_cast<MemoryManager*>(DAT_00d9b080(DAT_010f3170));
    unsigned int bytes=(sizeof(hkDefaultClassNameRegistry)+15)&~15u;
    hkDefaultClassNameRegistry* registry=static_cast<hkDefaultClassNameRegistry*>(allocator->FUN_008f6d30(bytes,21));
    registry->memorySizeAndFlags=static_cast<unsigned short>(bytes);
    __assume(registry!=0);
    return ::new(registry) hkDefaultClassNameRegistry;
}
}
}   // namespace f3m_009b00a0

// @f3 0x009b4980 (community match, verified in this file)
namespace f3m_009b4980 {
namespace triple_record_append {
void FUN_00901f10(void*,int);
struct Entry {
    unsigned int first,second,third;
    Entry(unsigned int a,unsigned int b,unsigned int c):first(a),second(b),third(c) {}
};
template<class T> struct Array {
    T* data;int count;unsigned int capacityAndFlags;
    void Append(const T& value) { if(count==int(capacityAndFlags&0x3fffffffu))FUN_00901f10(this,sizeof(T));data[count]=value;++count; }
};
struct Owner {
    unsigned int unk00,unk04,unk08;
    Array<Entry> values;
    void FUN_009b4980(unsigned int,unsigned int,unsigned int);
};
// pdb: hkRelocationInfo::addGlobal | hkObjectCopier.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: fromOffset, toAddr, klass, related
void Owner::FUN_009b4980(unsigned int first,unsigned int second,unsigned int third) { values.Append(Entry(first,second,third)); }
}
}   // namespace f3m_009b4980

// @f3 0x009baba0 (community match, verified in this file)
namespace f3m_009baba0 {
namespace task0902 {
struct ValueSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f_extra();
    virtual int f4();
};

struct CallBuf
{
    int unk00;
    ValueSource** unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

void __cdecl FUN_00a2b420(void* a, void* b);

// Calls f4 on the ValueSource, fills a CallBuf with the arguments and result, then passes it to FUN_00a2b420 with p2.
// @fnv 0x00d2d3e0
// pdb: hkListAgent3::updateFilter | hkpListAgent3.obj | fnv360_0822_retail, objrun, medium
// pdb params: entry, agentData, bodyA, bodyB, input, mgr, constraintOwner
void __cdecl FUN_009baba0(void* apUnused, void* p2, int aiArg0, ValueSource** apValueSource, int aiArg1,
                                 int aiArg2, int aiArg3)
{
    int r;
    r = (*apValueSource)->f4();
    CallBuf callBuf;
    callBuf.unk00 = aiArg0;
    callBuf.unk04 = apValueSource;
    callBuf.unk10 = aiArg1;
    callBuf.unk14 = aiArg2;
    callBuf.unk0c = r;
    callBuf.unk18 = aiArg3;
    FUN_00a2b420(p2, &callBuf);
}


}
}   // namespace f3m_009baba0

// @f3 0x009a8260 (community match, verified in this file)
namespace f3m_009a8260 {
namespace Task0904 {
struct BufferOwner {
 int unk00,unk04,unk08,unk0c,unk10;
 void* object;int result;int unk1c;char buffer[0x20];
 int FUN_009a8260(int,int);
};
// pdb: hkpTriSampledHeightFieldCollection::calcSizeForSpu | hkpTriSampledHeightFieldCollection.obj | fnv360_0822_retail, objrun_open, low
// pdb params: input, spuBufferSizeLeft
int BufferOwner::FUN_009a8260(int a,int limit) {
 int adjusted=limit-0x20;
 void* obj=object;
 int value=(*(int(__thiscall**)(void*,int,int))(*(unsigned char**)obj+0x18))(obj,a,adjusted);
 if(value>=0 && value<=adjusted){
  if(object==buffer){result=0;return value+0x20;}
  result=value;return 0x20;
 }
 return -1;
}
}
}   // namespace f3m_009a8260

// @f3 0x009bab20 (community match, verified in this file)
namespace f3m_009bab20 {
namespace task0995 {
struct Agent {
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void Begin(const char*);
 virtual void End();
};
void __cdecl FUN_00a26d90(int, int, Agent*);
// pdb: hkListAgent3::calcStatistics | hkpListAgent3.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkListAgent3_calcStatistics(int first, int second, int third, Agent* agent) {
 agent->Begin("hkListAgent3");
 FUN_00a26d90(second, third, agent);
 agent->End();
}
}

}   // namespace f3m_009bab20

// @f3 0x009ad610 (community match, verified in this file)
namespace n9ad610 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const FUN_00d9b080)(unsigned long);
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize);
struct Mem {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void* allocStack(int size);
    virtual void freeStack(void* p);
    char pad[0x1c];
    char* cur;
    int m24;
    char* base;
    char* end;
};
inline int* AllocStack(int n)
{
    Mem* m = (Mem*)FUN_00d9b080(DAT_010f3170);
    char* p = m->cur;
    int size = (n * 4 + 0x10) & ~0xf;
    if (m->cur + size <= m->end) {
        m->cur += size;
        return (int*)p;
    }
    return (int*)m->allocStack(size);
}
inline void FreeStack(int* p)
{
    Mem* m = (Mem*)FUN_00d9b080(DAT_010f3170);
    m->cur = (char*)p;
    if ((char*)p == m->base)
        m->freeStack(p);
}
struct Array {
    int* data;
    int size;
    int capAndFlags;
    void setSize(int n) {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, 4);
        }
        size = n;
    }
};
}
struct Keys9ad610 {
    n9ad610::Array* keys;
    int size;
    void FUN_009ad610(n9ad610::Array* counts, n9ad610::Array* out);
};
// pdb: hkUnionFind::sortByGroupId | hkUnionFind.obj | tesv_win, objrun_open, low
void Keys9ad610::FUN_009ad610(n9ad610::Array* counts, n9ad610::Array* out)
{
    out->setSize(size);
    int nb = counts->size;
    if (nb <= 0)
        return;
    int* offs = n9ad610::AllocStack(nb);
    int sum = 0;
    for (int i = 0; i < nb; ++i) {
        offs[i] = sum;
        sum += counts->data[i];
    }
    int* o = out->data;
    int* k0 = keys->data;
    for (int i = 0; i < size; ++i) {
        int k = k0[i];
        int idx = offs[k];
        offs[k] = idx + 1;
        o[idx] = i;
    }
    n9ad610::FreeStack(offs);
}

// @f3 0x009b2a80 (community match, verified in this file)
namespace f3m_009b2a80 {
namespace task9b2a80 {
struct Array;
extern void __cdecl FUN_00901e90(Array*,int,int);
struct Array { int* data; int size,capacity; void FUN_009b2a80(int,int*,int); };
// pdb: hkArrayBase<hkpSimulationIsland *>::_spliceInto | hkpSaveContactPointsUtil.obj | fnv360_0822_retail, call_dedup, low
// pdb params: alloc, index, numdel, p, numtoinsert
void Array::FUN_009b2a80(int index,int* values,int n) {
 int newSize=size+n; int tail=size-index; int cap=capacity&0x3fffffff;
 if(cap<newSize) {int target=cap*2; if(newSize>=target) target=newSize; FUN_00901e90(this,target,4);}
 int* from=data+index; int* to=data+index+n;
 for(int i=tail-1;i>=0;--i) to[i]=from[i];
 int* dest=data+index;
 for(int i=n-1;i>=0;--i) dest[i]=values[i];
 size=newSize;
}
}
}   // namespace f3m_009b2a80

// @f3 0x009b1370 (community match, verified in this file)
namespace f3m_009b1370 {
// FUN_009b1370 -- 0x009b1370, __thiscall, 4 stack params (ret 0x10)
//
// Visited-set traversal: look the node's name up in the string map, stop when it is
// already there, let the callback veto, mark it, then recurse into the field at +4 and
// into every 24-byte element of the array at +0x18.
class D481D0Class {
public:
    const char* getName() const;
};

class Struct_d86920 {
public:
    int FUN_00d86920();
};

class FUN_00d46f70_cls {
public:
    int FUN_00d46f70();
};

class FUN_00d46f80_class {
public:
    void* FUN_00d46f80(int index) const;
};

struct Provider;

class Owner {
public:
    Provider* FUN_00d86910();
};

struct hkBoolD8765 {
    char m_bool;
};

class hkStringMapD8765 {
public:
    int FindStringKey(const char* key);
    hkBoolD8765 SetBoolFromThreshold(int idx);
};

class FUN_00dbc6f0_cls_store {
public:
    void Store(void* key, int value);
};

struct Elem9b1370 {
    int unk00;
    int unk04;
};

typedef int (__cdecl* TraverseCallback9b1370)(void* context, D481D0Class* node, void* data);

class TraverseOwner9b1370 {
public:
    int FUN_009b1370(D481D0Class* node, hkStringMapD8765* map, TraverseCallback9b1370 callback, void* data);
};

int TraverseOwner9b1370::FUN_009b1370(D481D0Class* node, hkStringMapD8765* map, TraverseCallback9b1370 callback, void* data)
{
    int idx = map->FindStringKey(node->getName());
    hkBoolD8765 visited = map->SetBoolFromThreshold(idx);
    if (visited.m_bool)
        return 0;
    if (callback(this, node, data) == 1)
        return 1;
    const char* nm = node->getName();
    ((FUN_00dbc6f0_cls_store*)map)->Store((void*)nm, 1);
    if (((Struct_d86920*)node)->FUN_00d86920() != 0) {
        if (FUN_009b1370((D481D0Class*)((Struct_d86920*)node)->FUN_00d86920(), map, callback, data) == 1)
            return 1;
    }
    for (int i = 0; i < ((FUN_00d46f70_cls*)node)->FUN_00d46f70(); i++) {
        Elem9b1370* elem = (Elem9b1370*)((FUN_00d46f80_class*)node)->FUN_00d46f80(i);
        if (elem->unk04) {
            if (FUN_009b1370((D481D0Class*)((Owner*)elem)->FUN_00d86910(), map, callback, data) == 1)
                return 1;
        }
    }
    return 0;
}
}   // namespace f3m_009b1370

// @f3 0x009b77d0 (community match, verified in this file)
extern int DAT_00e7e9f8;
namespace f3m_009b77d0 {

class hkArrayHolder {
public:
    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_refCount;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void* m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
    void* FUN_009b77d0(int flag);
};

// pdb: hkpBvTreeStreamAgent::`scalar deleting destructor' | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
void* hkArrayHolder::FUN_009b77d0(int flag)
{
    m_vtable = &DAT_00e7e9f8;
    const unsigned int& cap = m_capacityAndFlags;
    if (!(cap & 0x80000000)) {
        int count = cap & 0x3fffffff;
        f3m_009b2130::QAlloc9b* alloc = f3m_009b2130::FUN_00d9b080(DAT_010f3170);
        alloc->FUN_008f6d90(m_data, count * 4, 0x17);
    }
    m_vtable = &DAT_00dcc494;
    if (flag & 1) {
        f3m_009b2130::QAlloc9b* alloc = f3m_009b2130::FUN_00d9b080(DAT_010f3170);
        alloc->FUN_008f6d90(this, m_memSizeAndFlags, 0x1f);
    }
    return this;
}
}   // namespace f3m_009b77d0

// @f3 0x009bca80 (community match, verified in this file)
struct Vec9bca80 {
    float x, y, z, w;
};

extern Vec9bca80 DAT_010f3370;

struct Item9bca80 {
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
};

void __cdecl FUN_009cc140(int a, int b, Item9bca80* item, Vec9bca80* out);

// pdb: hkConvexListAgent3::sepNormal | hkpConvexListAgent3.obj | fnv360_0822_retail, objrun + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void __cdecl hkConvexListAgent3_sepNormal(int a, int b, Item9bca80* item, Vec9bca80* out) {
    if (item->unk0b & 0x20) {
        FUN_009cc140(a, b, item, out);
        return;
    }
    out->x = DAT_010f3370.x;
    out->y = DAT_010f3370.y;
    out->z = DAT_010f3370.z;
    *(volatile float*)&out->w = DAT_010f3370.w;
    out->w = -1.70141001e38f;
}

// @f3 0x009a2050 (community match, verified in this file)
namespace f3m_009a2050 {
struct OutV2050 { float x; float y; float z; union { float w; int tag; }; };
struct Owner2050 { char pad[0x20]; char m_data[1]; void FUN_009a2050(unsigned short* indices, int count, OutV2050* out); };
void Owner2050::FUN_009a2050(unsigned short* indices, int count, OutV2050* out)
{
    int i = count - 1;
    while (i >= 0) {
        int idx = *indices++;
        float* src = (float*)&m_data[idx];
        out->x = src[0];
        out->y = src[1];
        out->z = src[2];
        out->w = src[3];
        out->tag = idx | 0x3f000000;
        out++;
        i--;
    }
}
}   // namespace f3m_009a2050

// @f3 0x009a2180 (community match, verified in this file)
namespace f3m_009a2180 {
struct Vec9a2180 {
    float x, y, z, w;
    void setAdd(const Vec9a2180& a, const Vec9a2180& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void mul(float s) { x *= s; y *= s; z *= s; w *= s; }
};

struct Owner9a2180 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec9a2180 unk20;
    Vec9a2180 unk30;
    void FUN_009a2180(Vec9a2180* out);
};

void Owner9a2180::FUN_009a2180(Vec9a2180* out) {
    out->setAdd(unk20, unk30);
    out->x *= 0.5; out->y *= 0.5; out->z *= 0.5; out->w *= 0.5;
}
}   // namespace f3m_009a2180

// @f3 0x009b6dd0 (community match, verified in this file)
namespace f3m_009b6dd0 {


extern DWORD DAT_010f3170;

class hkThreadMemory {
public:
    void* FUN_008f6d30(int nbytes, int memoryClass);
    static hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

class hkpCdBody;
class hkpCollisionInput;
class hkpContactMgr;

class hkBaseObject {
public:
    virtual ~hkBaseObject();
};

class hkReferencedObject : public hkBaseObject {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;

    void* operator new(size_t nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().FUN_008f6d30(nbytes, 0x1f));
        b->m_memSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void* p);
};

class hkpCollisionAgent : public hkReferencedObject {
public:
    int unk08;
};

class hkpBvTreeStreamAgent : public hkpCollisionAgent {
public:
    int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
};

// hkpSymmetricAgentLinearCast<hkpBvTreeStreamAgent>, constructor FUN_009b5e00
class FUN_009b5e00 : public hkpBvTreeStreamAgent {
public:
    FUN_009b5e00(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr) throw();
};

template <class AGENT>
class hkpSymmetricAgent : public FUN_009b5e00 {
public:
    hkpSymmetricAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr)
        : FUN_009b5e00(bodyB, bodyA, input, mgr) {}
    virtual void VFunc04();
};

// pdb: hkpBvTreeStreamAgent::createBvTreeShapeAgent | hkpBvTreeStreamAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
hkpCollisionAgent* __cdecl hkpBvTreeStreamAgent_createBvTreeShapeAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr)
{
    return new hkpSymmetricAgent<hkpBvTreeStreamAgent>(bodyA, bodyB, input, mgr);
}
}   // namespace f3m_009b6dd0

// @f3 0x009be380 (community match, verified in this file)
namespace f3m_009be380 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern void* DAT_010f3170;

struct Heap {
    void* AllocTagged(unsigned int bytes, int tag);   // FUN_008f6d30
};
struct Obj {
    int unk00;
    short unk04;
    Obj* Init38(int a, int b, int c, int d);   // FUN_009d1db0
    Obj* Init90(int a, int b, int c, int d);   // FUN_009bd700
    Obj* Init80(int a, int b, int c);          // FUN_00a35730
};
struct V38 { virtual void vf(); void* operator new(unsigned int, void* p) throw() { return p; } };
struct V90 { virtual void vf(); void* operator new(unsigned int, void* p) throw() { return p; } };
struct V80 { virtual void vf(); void* operator new(unsigned int, void* p) throw() { return p; } };
struct Sel {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int Classify(int a, int b, Sel* c);
};
struct Holder { int unk0; int unk4; int unk8; Sel* unkC; };
struct Node { int unk0; int unk4; int unk8; Sel* unkC; };

static __forceinline Obj* NewObj(unsigned int size)
{
    Heap* h = (Heap*)TlsGetValue((unsigned long)DAT_010f3170);
    Obj* o = (Obj*)h->AllocTagged(size, 0x1f);
    o->unk04 = (short)size;
    return o;
}

// pdb: hkpConvexListAgent::createConvexListConvexListAgent | hkpConvexListAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
Obj* hkpConvexListAgent_createConvexListConvexListAgent(int a1, int a2, Node* a3, int a4)
{
    if (a4 != 0) {
    switch (a3->unkC->Classify(a1, a2, (Sel*)a3)) {
    case 0: {
        Obj* o = NewObj(0x90);
        o->Init90(a2, a1, (int)a3, a4);
        new (o) V90;
        return o;
    }
    case 1: {
        Obj* o = NewObj(0x38);
        return o->Init38(a1, a2, (int)a3, a4);
    }
    case 2:
        switch (a3->unkC->Classify(a2, a1, (Sel*)a3)) {
        case 0: {
            Obj* o = NewObj(0x90);
            return o->Init90(a1, a2, (int)a3, a4);
        }
        case 1: {
            Obj* o = NewObj(0x38);
            o->Init38(a2, a1, (int)a3, a4);
            new (o) V38;
            return o;
        }
        case 2: {
            Obj* o = NewObj(0x80);
            o->Init80(a1, a2, a4);
            new (o) V80;
            return o;
        }
        }
    }
    return 0;
    }
    Obj* o = NewObj(0x38);
    return o->Init38(a1, a2, (int)a3, 0);
}
}   // namespace f3m_009be380

// @f3 0x009be250 (community match, verified in this file)
namespace f3m_009be250 {

extern unsigned long DAT_010f3170;

struct Alloc { void* FUN_008f6d30(unsigned int size, int tag) throw(); };

struct Base38 {
    virtual void vf0();
    unsigned short unk04;
    Base38(int a, int b, int c, int d) throw();
};
struct Der38 : Base38 {
    __forceinline Der38(int a, int b, int c, int d) throw() : Base38(a, b, c, d) {}
    virtual void vf0();
    void* operator new(unsigned int, void* p) throw() { return p; }
};
struct Base80 {
    virtual void vf0();
    unsigned short unk04;
    Base80(int a, int b, int c) throw();
};
struct Der80 : Base80 {
    __forceinline Der80(int a, int b, int c) throw() : Base80(a, b, c) {}
    virtual void vf0();
    void* operator new(unsigned int, void* p) throw() { return p; }
};
struct Obj90 {
    virtual void vf0();
    unsigned short unk04;
    Obj90(int a, int b, int c, int d) throw();
    void* operator new(unsigned int, void* p) throw() { return p; }
};

struct Dispatcher { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(int a, int b, int c); };
struct Holder { int unk00; int unk04; int unk08; Dispatcher* unk0C; };

static void* Mem(unsigned int size)
{
    Alloc* al = (Alloc*)TlsGetValue(DAT_010f3170);
    return al->FUN_008f6d30(size, 0x1f);
}

// pdb: hkpConvexListAgent::createConvexConvexListAgent | hkpConvexListAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void* hkpConvexListAgent_createConvexConvexListAgent(int a1, int a2, Holder* a3, int a4)
{
    if (a4 != 0) {
        switch (a3->unk0C->v3(a2, a1, (int)a3)) {
        case 0: {
            Obj90* o = (Obj90*)Mem(0x90);
            o->unk04 = 0x90;
            return new (o) Obj90(a1, a2, (int)a3, a4);
        }
        case 1: {
            Der38* o = (Der38*)Mem(0x38);
            o->unk04 = 0x38;
            return new (o) Der38(a2, a1, (int)a3, a4);
        }
        case 2: {
            Der80* o = (Der80*)Mem(0x80);
            o->unk04 = 0x80;
            return new (o) Der80(a1, a2, a4);
        }
        }
        return 0;
    }
    Der38* o = (Der38*)Mem(0x38);
    o->unk04 = 0x38;
    return new (o) Der38(a2, a1, (int)a3, 0);
}
}   // namespace f3m_009be250

// @f3 0x009ad510 (community match, verified in this file)
#include <windows.h>

namespace f3m_009ad510 {
extern DWORD DAT_010f3170;
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);

class hkThreadMemory {
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void* allocateStackSlow(int size);
    virtual void popStackSlow(void* p);
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    char* stackCurrent;
    int unk24;
    char* stackBase;
    char* stackEnd;

    static hkThreadMemory* get() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
    void* allocateStack(int size)
    {
        size = (size + 16) & ~15;
        char* p = stackCurrent;
        if (p + size <= stackEnd) {
            stackCurrent = p + size;
            return p;
        }
        return allocateStackSlow(size);
    }
    void popStack(void* p)
    {
        stackCurrent = (char*)p;
        if (p == stackBase)
            popStackSlow(p);
    }
};

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getCapacity() const { return m_capacityAndFlags & 0x3FFFFFFF; }
    void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n) {
            int newCap = cap * 2;
            if (n >= newCap)
                newCap = n;
            FUN_00901e90(this, newCap, sizeof(T));
        }
        m_size = n;
    }
};

struct IndexRemap
{
    int** m_ppIndices;
    int m_iIndexCount;

    void FUN_009ad510(const hkArray<int>& map, int n, hkArray<int>& values);
};

// pdb: hkUnionFind::assignGroups | hkUnionFind.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkUnionFind::reindex)
// pdb params: elementsPerGroup
void IndexRemap::FUN_009ad510(const hkArray<int>& map, int n, hkArray<int>& values)
{
    for (int i = 0; i < m_iIndexCount; i++)
        (*m_ppIndices)[i] = map.m_data[(*m_ppIndices)[i]];

    int* sums = (int*)hkThreadMemory::get()->allocateStack(n * sizeof(int));
    for (int i = 0; i < n; i++)
        sums[i] = 0;
    for (int i = 0; i < values.m_size; i++)
        sums[map.m_data[i]] += values.m_data[i];

    values.setSize(n);
    for (int i = 0; i < n; i++)
        values.m_data[i] = sums[i];

    hkThreadMemory::get()->popStack(sums);
}
}

// @f3 0x009af940 (community match, verified in this file)
#include <windows.h>

extern const char* DAT_01061240;
extern HMODULE (__stdcall* DAT_00d9b0f0)(LPCSTR);
typedef FARPROC (__stdcall* GetAddress)(HMODULE, LPCSTR);
extern GetAddress DAT_00d9b0ec;
extern HANDLE (__stdcall* DAT_00d9b258)();
extern const char DAT_00e7e46c[];
extern const char DAT_00e7e45c[];
extern const char DAT_00e7e44c[];
extern const char DAT_00e7e438[];
extern const char DAT_00e7e42c[];
extern const char DAT_00e7e410[];
extern const char DAT_00e7e3fc[];
extern const char DAT_00e7e3e4[];

struct FUN_009af940 {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    FUN_009af940();
};

// pdb: hkStackTracerWin32Data::init | hkStackTracer.obj | tesv_win, ustr, medium
FUN_009af940::FUN_009af940()
{
    if (!DAT_01169398) {
        unk06 = 1;
        unk00 = &DAT_00e7e480;
        DAT_01169398 = DAT_00d9b0f0(DAT_01061240);
        GetAddress getAddress = DAT_00d9b0ec;
        DAT_01169394 = 1;
        DAT_01169390 = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e46c);
        DAT_0116938c = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e45c);
        DAT_01169388 = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e44c);
        DAT_01169384 = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e438);
        DAT_01169380 = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e42c);
        DAT_0116937c = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e410);
        DAT_01169378 = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e3fc);
        DAT_01169374 = (int)getAddress((HMODULE)DAT_01169398, DAT_00e7e3e4);
        typedef DWORD (__stdcall* GetOptions)();
        typedef DWORD (__stdcall* SetOptions)(DWORD);
        typedef BOOL (__stdcall* Initialize)(HANDLE, const char*, BOOL);
        DWORD options = ((GetOptions)DAT_0116938c)();
        ((SetOptions)DAT_01169388)(options | 0x80000010);
        ((Initialize)DAT_01169390)(DAT_00d9b258(), 0, TRUE);
    } else {
        unk06 = 1;
        unk00 = &DAT_00e7e480;
        ++DAT_01169394;
    }
}

// @f3 0x009b20c0 (community match, verified in this file)
namespace f3m_009b20c0 {
extern unsigned long DAT_010f3170;
struct Alloc20c0 { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
extern "C" __declspec(dllimport) Alloc20c0* __stdcall TlsGetValue(unsigned long);
class FUN_009b20c0 : public f3m_009b1a20::FUN_009b1a20 {
public:
    __declspec(noinline) virtual ~FUN_009b20c0() throw();
    // pdb: hkXmlStreamParser::`scalar deleting destructor' | hkXmlStreamParser.obj | tesv_win, objrun_open, low
    static void operator delete(void* p) {
        Alloc20c0* a = TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(p, *(unsigned short*)((char*)p + 4), 0x15);
    }
};
FUN_009b20c0::~FUN_009b20c0() throw() {}
}

// @f3 0x009b0450 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009b0450 {
namespace n9b0450 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned int);
}
class hkRef9b0450 {
public:
    virtual ~hkRef9b0450() {}
    unsigned short memSize;
    short refCount;
    static void operator delete(void* p, unsigned int)
    {
        n9b0450::Alloc* a = n9b0450::FUN_00d9b080(DAT_010f3170);
        a->FUN_008f6d90(p, ((hkRef9b0450*)p)->memSize, 0x15);
    }
};
class FUN_00922cf0 { public: ~FUN_00922cf0() throw(); int unk00; };
class FUN_009b0450 : public hkRef9b0450 {
public:
    FUN_00922cf0 member;
};
void* Make9b0450() { return new FUN_009b0450; }
}   // namespace f3m_009b0450

// @f3 0x009bae50 (community match, verified in this file)
extern int DAT_00e7ec04;
namespace f3m_009bae50 {
namespace Init333{
struct Header333{void*vtable;unsigned short memory,refs;unsigned int flags;Header333(unsigned int value){refs=1;flags=value;vtable=&DAT_00e7ec04;}};
struct Array333{unsigned short*data;int size;unsigned int capacityFlags;Array333(){data=0;size=0;capacityFlags=0x80000000;}void Resize(int);};
void __cdecl FUN_00901e90(Array333*,int,int);
struct Object333{virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual int Count();};struct Source333{Object333*object;};
struct Owner333:Header333{Array333 array;Owner333(Source333*,int,int,unsigned int);};
__forceinline void Array333::Resize(int count){int old=size;if(count>old){int capacity=capacityFlags&0x3fffffff;if(capacity<count){int desired=capacity*2;if(count>=desired)desired=count;FUN_00901e90(this,desired,2);}for(int i=old;i<count;++i)data[i]=0xffff;}size=count;}
// pdb: hkpHeightFieldAgent::hkpHeightFieldAgent | hkpHeightFieldAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: A, B, input, mgr
Owner333::Owner333(Source333*source,int unused1,int unused2,unsigned int enabled):Header333(enabled){if(enabled)array.Resize(source->object->Count());}
}
}   // namespace f3m_009bae50

// @f3 0x009a83a0 (community match, verified in this file)
namespace f3m_009a83a0 {
namespace sampled_heightfield_ctor {
struct hkReferencedObject {
    virtual ~hkReferencedObject();
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    __forceinline hkReferencedObject() : referenceCount(1) {}
    __forceinline void addReference() { if(memorySizeAndFlags) ++referenceCount; }
};
struct hkpShape : hkReferencedObject {
    unsigned int userData;
    int type;
    __forceinline hkpShape(int value) : userData(0),type(value) {}
};
struct hkpSingleShapeContainer {
    virtual ~hkpSingleShapeContainer();
    hkpShape* childShape;
    __forceinline hkpSingleShapeContainer(hkpShape* child) : childShape(child) { child->addReference(); }
};
struct hkpBvTreeShape : hkpShape {
    __forceinline hkpBvTreeShape() : hkpShape(9) {}
};
struct hkpTriSampledHeightFieldBvTreeShape : hkpBvTreeShape {
    hkpSingleShapeContainer child;
    unsigned int unk18;
    bool unk1c;
    hkpTriSampledHeightFieldBvTreeShape(hkpShape*,bool);
};
// pdb: hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape | hkpTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: c, doAabbRejection
hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(hkpShape* shape,bool value) : child(shape),unk1c(value) {}
}
}   // namespace f3m_009a83a0

// @f3 0x009b1920 (community match, verified in this file)
namespace f3m_009b1920 {
namespace validated_registry_constructor {
struct hkClass;
struct FinishFlag { bool finishing; FinishFlag(bool value):finishing(value) {} };
struct StringMap { void* data; int count,capacity; StringMap(FinishFlag) throw(); };
struct hkReferencedObject {
    virtual ~hkReferencedObject() throw();
    unsigned short memorySizeAndFlags,referenceCount;
    __forceinline hkReferencedObject() throw() : referenceCount(1) {}
};
struct hkDynamicClassNameRegistry : hkReferencedObject {
    const char* version;
    StringMap classes;
    __forceinline hkDynamicClassNameRegistry() throw() : version(0),classes(FinishFlag(false)) {}
    void hkDynamicClassNameRegistry_merge(const hkClass* const*) throw();
};
struct ValidatedClassNameRegistry : hkDynamicClassNameRegistry {
    ValidatedClassNameRegistry(const hkClass* const*) throw();
};
ValidatedClassNameRegistry::ValidatedClassNameRegistry(const hkClass* const* records) throw() { if(records)hkDynamicClassNameRegistry_merge(records); }
}
}   // namespace f3m_009b1920

// @f3 0x009b2fd0 (community match, verified in this file)
namespace n9b2fd0 {
extern unsigned long DAT_010f3170;
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    __forceinline ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct E8 { int a, b; };
struct E12 { int a, b, c; };
struct Obj { virtual void Destroy(bool free) throw(); };
}
struct C9b2fd0 {
    n9b2fd0::Array<n9b2fd0::E8> a00;
    n9b2fd0::Array<n9b2fd0::E12> a0c;
    n9b2fd0::Array<n9b2fd0::E8> a18;
    n9b2fd0::Array<n9b2fd0::E8> a24;
    n9b2fd0::Obj* p30;
    ~C9b2fd0() throw();
};
// pdb: hkRelocationInfo::~hkRelocationInfo | hkRelocationInfo.obj | fnv360_0822_retail, call_gap, medium
C9b2fd0::~C9b2fd0() throw()
{
    n9b2fd0::Obj* p = p30;
    if (p)
        p->Destroy(true);
}

// @f3 0x009b5ae0 (community match, verified in this file)
#include <windows.h>
extern unsigned int DAT_010f3170;
namespace f3m_009b5ae0 {

extern "C" void _ReadWriteBarrier(void);


struct ThreadMemory009b5ae0 {
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
    int maxNumElemsOnFreeList;
    int unk38;
    int unk3c;
    void* unk40;
    int unk44;
    void FUN_008f6890(int row, void* p, int memClass);
};

struct FUN_009b5ae0 {
    virtual ~FUN_009b5ae0();
    // pdb: hkpSymmetricAgentFlipCollector::`scalar deleting destructor' | hkpMoppBvTreeStreamAgent.obj | fnv360_0721_beta, objrun_open, low
    static void operator delete(void* p) {
        ThreadMemory009b5ae0* m = (ThreadMemory009b5ae0*)TlsGetValue(DAT_010f3170);
        if (m->unk44 >= m->maxNumElemsOnFreeList) m->FUN_008f6890(1, p, 0x1f);
        else { _ReadWriteBarrier(); void* next = m->unk40; m->unk44++; *(void**)p = next; m->unk40 = p; }
    }
};

FUN_009b5ae0::~FUN_009b5ae0() {
}
}   // namespace f3m_009b5ae0

// @f3 0x009b5b30 (community match, verified in this file)
#include <windows.h>
extern unsigned int DAT_010f3170;
namespace f3m_009b5b30 {

extern "C" void _ReadWriteBarrier(void);


struct ThreadMemory009b5b30 {
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
    int maxNumElemsOnFreeList;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    void* unk48;
    int unk4c;
    void FUN_008f6890(int row, void* p, int memClass);
};

struct FUN_009b5b30 {
    virtual ~FUN_009b5b30();
    // pdb: hkpSymmetricAgentFlipBodyCollector::`scalar deleting destructor' | hkpMoppBvTreeStreamAgent.obj | fnv360_0822_retail, objrun_open, low
    static void operator delete(void* p) {
        ThreadMemory009b5b30* m = (ThreadMemory009b5b30*)TlsGetValue(DAT_010f3170);
        if (m->unk4c >= m->maxNumElemsOnFreeList) m->FUN_008f6890(2, p, 0x1f);
        else { _ReadWriteBarrier(); void* next = m->unk48; m->unk4c++; *(void**)p = next; m->unk48 = p; }
    }
};

FUN_009b5b30::~FUN_009b5b30() {
}
}   // namespace f3m_009b5b30

// @f3 0x009be780 (community match, verified in this file)
#include <windows.h>
extern unsigned int DAT_010f3170;
namespace f3m_009be780 {

extern "C" void _ReadWriteBarrier(void);


struct ThreadMemory009be780 {
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
    int maxNumElemsOnFreeList;
    int unk38;
    int unk3c;
    void* unk40;
    int unk44;
    void FUN_008f6890(int row, void* p, int memClass);
};

struct FUN_009be780 {
    virtual ~FUN_009be780();
    // pdb: hkpFlagCdBodyPairCollector::`scalar deleting destructor' | hkpConvexListAgent.obj | fnv360_0721_beta, objrun_sim, low
    static void operator delete(void* p) {
        ThreadMemory009be780* m = (ThreadMemory009be780*)TlsGetValue(DAT_010f3170);
        if (m->unk44 >= m->maxNumElemsOnFreeList) m->FUN_008f6890(1, p, 0x1f);
        else { _ReadWriteBarrier(); void* next = m->unk40; m->unk44++; *(void**)p = next; m->unk40 = p; }
    }
};

FUN_009be780::~FUN_009be780() {
}
}   // namespace f3m_009be780

// @f3 0x009a9120 (community match, verified in this file)
extern int FUN_00e7e028;
namespace f3m_009a9120 {
namespace f3m_009a9120 {
class Memory_9120;
__declspec(dllimport) Memory_9120* __stdcall FUN_00d9b080(int);

class RefObj_9120 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};
class Memory_9120 {
public:
    virtual void v00();
    virtual void Free(void* p);
};
struct Cls_9120 {
    void* vtable;
    int unk04;
    RefObj_9120* ref;
    void* buffer;
    int unk10;
    int unk14;
    bool ownsBuffer;

    void FUN_009a8f10();
    void FUN_009a9120();
};
}
using namespace f3m_009a9120;

// pdb: hkBufferedStreamWriter::~hkBufferedStreamWriter | hkBufferedStreamWriter.obj | fnv360_0822_retail, call_seq, high
void Cls_9120::FUN_009a9120()
{
    *(void**)this = &FUN_00e7e028;
    FUN_009a8f10();
    if (ref)
        ref->removeReference();
    if (ownsBuffer) {
        void* p = buffer;
        FUN_00d9b080(DAT_010f3170)->Free(p);
    }
    *(void**)this = &DAT_00dcc494;
}
}   // namespace f3m_009a9120

// @f3 0x009add30 (community match, verified in this file)
namespace f3m_009add30 {
struct VectorB9add30 { float x,y,z,w; void set(const VectorB9add30& v){x=v.x;y=v.y;z=v.z;w=v.w;} };
struct OwnerB9add30 { int unk00,unk04,unk08,unk0c; int count; int unk14,unk18,unk1c; VectorB9add30 data[1]; VectorB9add30* hkpMultiSphereShape_getCollisionSpheresImpl(VectorB9add30* out); };
// pdb: hkpMultiSphereShape::getCollisionSpheresImpl | hkpMultiSphereShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
VectorB9add30* OwnerB9add30::hkpMultiSphereShape_getCollisionSpheresImpl(VectorB9add30* out){for(int i=0;i<count;++i) out[i].set(data[i]); return out;}
}   // namespace f3m_009add30

// @f3 0x009a1c20 (community match, verified in this file)
extern float DAT_01169330; extern float DAT_01169334; extern float DAT_01169338; extern float DAT_0116933c; extern float DAT_01169340; extern float DAT_01169344; extern float DAT_01169348; extern float DAT_0116934c; extern float DAT_01169350; extern float DAT_01169354; extern float DAT_01169358; extern float DAT_0116935c; extern float DAT_01169360; extern float DAT_01169364; extern float DAT_01169368; extern float DAT_0116936c;
namespace f3m_009a1c20 {
struct V8 { float x[8]; };
// pdb: hkpSoftContactModifierConstraintAtom::collisionResponseEndCallback | hkpConstraintAtom.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpMovingSurfaceModifierConstraintAtom::collisionResponseBeginCallback)
// pdb params: cp, impulseApplied, inA, velA, inB, velB
__declspec(noinline) void __stdcall FUN_009a1c20(int a, int b, V8* src1, int c, V8* src2) {
 DAT_01169330=src1->x[0]; DAT_01169334=src1->x[1]; DAT_01169338=src1->x[2]; DAT_0116933c=src1->x[3]; DAT_01169340=src1->x[4]; DAT_01169344=src1->x[5]; DAT_01169348=src1->x[6]; DAT_0116934c=src1->x[7];
 DAT_01169350=src2->x[0]; DAT_01169354=src2->x[1]; DAT_01169358=src2->x[2]; DAT_0116935c=src2->x[3]; DAT_01169360=src2->x[4]; DAT_01169364=src2->x[5]; DAT_01169368=src2->x[6]; DAT_0116936c=src2->x[7]; }
}   // namespace f3m_009a1c20

// @f3 0x009ba960 (community match, verified in this file)
namespace f3m_009ba960 {
__declspec(dllimport) void* __stdcall FUN_00d9b080(int); extern char DAT_00e7eaac; 
struct Q9Memory { void FUN_008f6d90(void*,int,int); };
struct Q9Array { void* data; int count; int capacity; ~Q9Array() { if(!(capacity & 0x80000000)) { int n=capacity & 0x3fffffff; Q9Memory* memory=(Q9Memory*)FUN_00d9b080(DAT_010f3170); memory->FUN_008f6d90(data,n*12,0x17); } } };
struct Q9Owner { const void* table; unsigned short size; unsigned short unk06; int unk08; Q9Array array; Q9Owner* FUN_009ba960(unsigned); };
// pdb: hkpBvTreeAgent::`scalar deleting destructor' | hkpMoppAgent.obj | fnv360_0822_retail, vtable, high
Q9Owner* Q9Owner::FUN_009ba960(unsigned flags) { table=&DAT_00e7eaac; array.~Q9Array(); table=&DAT_00dcc494; if(flags&1) { Q9Memory* memory=(Q9Memory*)FUN_00d9b080(DAT_010f3170); memory->FUN_008f6d90(this,size,0x1f); } return this; }
}   // namespace f3m_009ba960

// @f3 0x009a1ee0 (community match, verified in this file)
namespace f3m_009a1ee0 {
namespace modifier_schema_info {
struct ConstraintInfo {unsigned int unk00,schemaBytes;};
struct ModifierAtom {unsigned short type,size;int FUN_009a1e80(ConstraintInfo*);int FUN_009a1ee0(ConstraintInfo*);};
// pdb: hkpConstraintOwner::subConstraintInfo | hkpWorldOperationUtil.obj | fnv360_0822_debug, callee_sim, low, conflict (skyrim: hkpModifierConstraintAtom::addModifierDataToConstraintInfo)
// pdb params: constraint, delta
int ModifierAtom::FUN_009a1ee0(ConstraintInfo* info){int callback=0;switch(type){case 23:case 25:callback=2;break;case 24:case 26:info->schemaBytes+=0x50;break;case 27:return FUN_009a1e80(info);default:break;}return callback;}
}
}   // namespace f3m_009a1ee0

// @f3 0x009ae1a0 (community match, verified in this file)
extern const int DAT_00e7e0d0;
namespace f3m_009ae1a0 {
struct Vec4AE { float x,y,z,w; };
struct FUN_009ae1a0 {
    void* unk00;
    void FUN_009ae990(int,int);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4AE v20;
    Vec4AE v30;
    Vec4AE v40;
    float f50;
    float f54;
    int unk58;
    unsigned char flag5c;
    FUN_009ae1a0(int, Vec4AE*, Vec4AE*, float, float, int);
};
// pdb: hkOrientHingedBodyAction::hkOrientHingedBodyAction | hkOrientHingedBodyAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: entityA, arHingeAxisLS, arForwardLS, afStrength, afDamping, userData
FUN_009ae1a0::FUN_009ae1a0(int a, Vec4AE* b, Vec4AE* c, float d, float e, int f) {
    FUN_009ae990(a,f);
    f50=d;
    unk00=(void*)&DAT_00e7e0d0;
    f54=e;
    flag5c=0;
    v20.x=b->x; v20.y=b->y; v20.z=b->z; v20.w=b->w;
    v30.x=c->x; v30.y=c->y; v30.z=c->z; v30.w=c->w;
    v40.x=v40.y=v40.z=v40.w=0.0f;
}
}   // namespace f3m_009ae1a0

// @f3 0x009a1680 (community match, verified in this file)
namespace f3m_009a1680 {
namespace f3m_009a1680 {
struct Mem_1680 {
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem_1680* __stdcall FUN_00d9b080(int);
struct Array_1680 {
    int* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int cap = capacityAndFlags & 0x3fffffff;
            Mem_1680* mem = FUN_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(data, cap * 4, 0x17);
        }
    }
};
struct Cls_1680 {
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    char pad08[0x10];
    Array_1680 items;
    Cls_1680* FUN_009a1680(unsigned int flags);
};
}
using namespace f3m_009a1680;

// pdb: hkaDetectRagdollPenetration::`scalar deleting destructor' | hkaDetectRagdollPenetration.obj | fnv360_0822_retail, vtable, high
Cls_1680* Cls_1680::FUN_009a1680(unsigned int flags)
{
    items.Free();
    vtable = &DAT_00dcc494;
    if (flags & 1) {
        Mem_1680* mem = FUN_00d9b080(DAT_010f3170);
        mem->FUN_008f6d90(this, memSizeAndFlags, 0x3d);
    }
    return this;
}
}   // namespace f3m_009a1680

// @f3 0x009bcfd0 (community match, verified in this file)
#include <string.h>
namespace f3m_009bcfd0 {

struct ValueBlock
{
    float f00, f04, f08, f0c, f10, f14, f18, f1c;
    int alpha, beta;
    int unknown28, unknown2c;
    int gamma, delta;
    int epsilon, zeta;
    int coefficients[12];
    ValueBlock* FUN_009bcfd0(ValueBlock* source);
};

// pdb: hkpProcessCollisionData::ToiInfo::operator= | hkpConvexListAgent3.obj | tesv_win, call_seq, medium
ValueBlock* ValueBlock::FUN_009bcfd0(ValueBlock* source)
{
    f00 = source->f00;
    f04 = source->f04;
    f08 = source->f08;
    f0c = source->f0c;
    f10 = source->f10;
    f14 = source->f14;
    f18 = source->f18;
    f1c = source->f1c;
    alpha = source->alpha;
    beta = source->beta;
    gamma = source->gamma;
    delta = source->delta;
    epsilon = source->epsilon;
    zeta = source->zeta;
    memcpy(coefficients, source->coefficients, 48);
    return this;
}
}   // namespace f3m_009bcfd0

// @f3 0x009b49d0 (community match, verified in this file)
namespace f3m_009b49d0 {
struct E { int a, b; };
struct Arr { E* data; unsigned int size; unsigned int cap; };
void __cdecl FUN_00901f10(Arr* a, int n);
struct O9b49d0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Arr arr;
    void FUN_009b49d0(int a, int b);
};
void O9b49d0::FUN_009b49d0(int a, int b)
{
    E v;
    v.a = a;
    v.b = b;
    Arr* p = &arr;
    unsigned int space = p->cap & 0x3fffffff;
    if (p->size == space)
        FUN_00901f10(p, 8);
    p->data[p->size] = v;
    p->size++;
}
}   // namespace f3m_009b49d0

// @f3 0x009a1a20 (community match, verified in this file)
namespace f3m_009a1a20 {
struct ObjectAt10 {
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
    float unk30;
    void FUN_0096cd10(float value);
};
struct Object {
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
    float unk40;
};
struct FUN_009a1a20_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int int18;
    int int1c;
    float unk20;
    float unk24;
    void FUN_009a1a20(unsigned int a1, Object* a2, unsigned int a3, Object* a4, unsigned int a5);
};
void FUN_009a1a20_cls::FUN_009a1a20(unsigned int a1, Object* a2, unsigned int a3, Object* a4, unsigned int a5)
{
    float x = unk20;
    float y = unk24;
    a2->unk40 *= x;
    ((ObjectAt10*)((char*)a2 + 0x10))->FUN_0096cd10(x);
    a4->unk40 *= y;
    ((ObjectAt10*)((char*)a4 + 0x10))->FUN_0096cd10(y);
}
}   // namespace f3m_009a1a20

// @f3 0x009b0d50 (community match, verified in this file)
namespace f3m_009b0d50 {
struct SlotEntry;

struct PtrArray {
    void** m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
};

class FUN_00db7ae0_cls {
public:
    int unk00;
    int unk04;
    int unk08;
    SlotEntry** m_slots;
    void ResetSlots();
    void hkStaticClassNameRegistry_getClasses(PtrArray* entries);
};

// pdb: hkStaticClassNameRegistry::getClasses | hkStaticClassNameRegistry.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FUN_00db7ae0_cls::hkStaticClassNameRegistry_getClasses(PtrArray* entries)
{
    ResetSlots();
    for (int i = 0; m_slots[i] != 0; ++i)
    {
        if (entries->m_size == (int)(entries->m_capacityAndFlags & 0x3fffffff))
            f3m_009affd0::hkArrayEnsureSizeU(entries, 4);
        void** insertion = entries->m_data + entries->m_size;
        entries->m_size = entries->m_size + 1;
        *insertion = m_slots[i];
    }
}
}   // namespace f3m_009b0d50

// @f3 0x009b1270 (community match, verified in this file)
struct SlotEntry;

struct GlobalObjectO2_00d472a0
{
    const char* getName() const;
};

extern GlobalObjectO2_00d472a0 g_0126cab8;
extern GlobalObjectO2_00d472a0 g_0126cae8;

int MatchSlotKey(const char* key, const char* name);

class SlotKey
{
public:
    const char* getName() const;
};

class SlotRegistry
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual int vf10(const char* name);
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c(SlotKey* key, int flag);
};

int FUN_009b1270(SlotRegistry* registry, SlotKey* key)
{
    const char* globalName = g_0126cae8.getName();
    const char* keyName = key->getName();
    if (MatchSlotKey(keyName, globalName) == 0)
        return 0;
    globalName = g_0126cab8.getName();
    keyName = key->getName();
    if (MatchSlotKey(keyName, globalName) == 0)
        return 0;
    if (registry->vf10(key->getName()) != 0)
        return 0;
    registry->vf1c(key, 0);
    return 0;
}

// @f3 0x009a30a0 (community match, verified in this file)
extern char DAT_00e7df2c;
namespace f3m_009a30a0 {
struct Vec4_9a {
    float x, y, z, w;
    Vec4_9a& operator=(const Vec4_9a& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};


class Obj9a30a0 {
public:
    void FUN_009a4660(int flags);
    Obj9a30a0* FUN_009a30a0(const Vec4_9a* a, const Vec4_9a* b, float c, int d, int e);
    void* vtable;              // 0x00
    unsigned short unk04;      // 0x04
    unsigned short unk06;      // 0x06
    unsigned int unk08;        // 0x08
    unsigned int unk0c;        // 0x0c
    float unk10, unk14, unk18, unk1c;
    float unk20, unk24, unk28, unk2c;
    float unk30, unk34, unk38, unk3c;
    float unk40, unk44, unk48, unk4c;
    int unk50;                 // 0x50
    int unk54, unk58, unk5c;
    Vec4_9a m60;               // 0x60
    Vec4_9a m70;               // 0x70
    float m80;                 // 0x80
    int m84;                   // 0x84
    int m88;                   // 0x88
};

// pdb: hkDisplayCapsule::hkDisplayCapsule | hkDisplayCapsule.obj | fnv360_0822_retail, uvref, medium
// pdb params: top, bottom, radius, numSides, numHeightSegments
Obj9a30a0* Obj9a30a0::FUN_009a30a0(const Vec4_9a* a, const Vec4_9a* b, float c, int d, int e)
{
    FUN_009a4660(8);
    m84 = d;
    vtable = &DAT_00e7df2c;
    m88 = e;
    m60 = *a;
    m70 = *b;
    m80 = c;
    return this;
}
}   // namespace f3m_009a30a0

// @f3 0x009bd4a0 (community match, verified in this file)
#include <string.h>
namespace f3m_009bd4a0 {

extern float DAT_0104da48;   // 3.402823466e+38F at 0x00de6e60

struct ValueBlock {
    void FUN_00d33330(ValueBlock* src);   // out-of-line copy at 0x009bcfd0
    float m00, m04, m08, m0c, m10, m14, m18, m1c;
    float m20;
    int m24, m28, m2c, m30, m34, m38, m3c;
    float m40, m44;
    int m48, m4c, m50, m54, m58, m5c, m60, m64, m68, m6c;
};

struct PackedRecord {
    int unk00;
    char pad04[0x300c];
    ValueBlock blk;      // 0x3010
    void* unk3080;
};

class BlockHolder {
public:
    int unk00;
    char buf[0x1008];
    int unk100c;
    ValueBlock blk;      // 0x1010
    BlockHolder* FUN_009bd4a0(PackedRecord* rec);
};

// pdb: hkpProcessCollisionOutputBackup::hkpProcessCollisionOutputBackup | hkpConvexListAgent3.obj | fnv360_0822_debug, call_gap, high
// pdb params: output
BlockHolder* BlockHolder::FUN_009bd4a0(PackedRecord* rec)
{
    ValueBlock* __restrict b = &blk;
    float& m20 = b->m20;
    m20 = DAT_0104da48;
    unk00 = rec->unk00;
    b->m44 = b->m40 = 0.0f;
    b->FUN_00d33330(&rec->blk);
    if (rec->unk3080)
        memcpy(buf, rec->unk3080, 0x1008);
    return this;
}
}   // namespace f3m_009bd4a0

// @f3 0x009ad710 (community match, verified in this file)
extern char DAT_00e7e080;
namespace f3m_009ad710 {
namespace task1526 {
struct Owner;
struct Output {
 virtual void slot0();
 virtual void slot1(void*,int,Owner*);
 virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();
 virtual void slot6();
};
struct Owner { void FUN_009ad710(Output*); };
// pdb: hkpMultiSphereShape::calcContentStatistics | hkpMultiSphereShape.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: collector, cls
void Owner::FUN_009ad710(Output* output) { output->slot1(&DAT_00e7e080,1,this); output->slot6(); }
}
}   // namespace f3m_009ad710

// @f3 0x009a7ee0 (community match, verified in this file)
namespace height_field_header_cleanup {
struct RefObject {virtual void* Destroy(unsigned int);unsigned short allocationBytes;short references;
void RemoveReference(){if(allocationBytes!=0){--references;if(references==0)Destroy(1);}}};
extern const void* DAT_00dcc494[];
extern const void* DAT_00e7dfcc[];extern const void* DAT_00e7dfa8[];extern const void* DAT_00e35eec[];
struct HeightFieldHeader {const void** vtable;unsigned short allocationBytes;short references;void* userData;unsigned int unk0C;const void** containerVtable;unsigned int unk14;RefObject* heightField;void FUN_009a7ee0();};
// pdb: hkpTriSampledHeightFieldCollection::~hkpTriSampledHeightFieldCollection | hkpTriSampledHeightFieldCollection.obj | fnv360_0822_retail, call_seq, medium
void HeightFieldHeader::FUN_009a7ee0(){RefObject* object=heightField;vtable=DAT_00e7dfcc;containerVtable=DAT_00e7dfa8;object->RemoveReference();containerVtable=DAT_00e35eec;vtable=DAT_00dcc494;}

}

// @f3 0x009b2c30 (community match, verified in this file)
namespace task1655 {
struct Node;
struct Member {unsigned unk00;void* type;Node* FUN_0093d890();};
struct Node {Node* FUN_009b04b0();int FUN_009b06a0();Member* FUN_009b06b0(int);};
struct Map {unsigned FUN_009227d0(Node*,unsigned);void FUN_00922710(Node*,unsigned);};
struct Meta {unsigned unk00,unk04,unk08,unk0c;unsigned short unk10,offset;};
struct Registry {Meta* FUN_009b06c0(const char*);};
extern Registry DAT_0116c25c;
extern const char DAT_00e73dc8[],DAT_00e3c0f0[];
// pdb: `anonymous namespace'::updateClassVersion1Inplace | hkClassUpdate.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void updateClassVersion1Inplace(Node* node,Map* visited){
 unsigned flags=visited->FUN_009227d0(node,0);
 if(!(flags&1)){
  visited->FUN_00922710(node,flags|1);
  unsigned offset=DAT_0116c25c.FUN_009b06c0(DAT_00e73dc8)->offset;
  Node* ancestor=node;
  while(ancestor->FUN_009b04b0()){
   *reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor)+offset)=0;
   ancestor=ancestor->FUN_009b04b0();
  }
  if(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ancestor)+offset)){
   unsigned countOffset=DAT_0116c25c.FUN_009b06c0(DAT_00e3c0f0)->offset;
   ++*reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor)+countOffset);
  }
  *reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor)+offset)=0;
  for(int i=0;i<node->FUN_009b06a0();++i){
   Member* member=node->FUN_009b06b0(i);
   if(member->type)updateClassVersion1Inplace(member->FUN_0093d890(),visited);
  }
  if(node->FUN_009b04b0())updateClassVersion1Inplace(node->FUN_009b04b0(),visited);
 }
}
}

// @f3 0x009bf500 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009bf500 {
struct Alloc_9bf500 { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
typedef Alloc_9bf500* (__stdcall* TlsGetValueFn_t)(unsigned int);
extern "C" __declspec(dllimport) Alloc_9bf500* __stdcall TlsGetValue(unsigned int);

class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};

namespace f3m_009bf500 {

struct hkArray_9bf500 {
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray_9bf500() throw()
    {
        if (!(m_capacityAndFlags & 0x80000000)) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            Alloc_9bf500* a = TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(m_data, cap * 4, 0x17);
        }
    }
};

class FUN_009bf500 : public hkBaseObject {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    int m_unk08;
    int m_unk0C;
    hkArray_9bf500 m_array;

    void* DeleteThis(int flag) throw();
};

// pdb: hkpListAgent::`scalar deleting destructor' | hkpListAgent.obj | fnv360_0822_retail, vtable_prefix, high
void* FUN_009bf500::DeleteThis(int flag) throw()
{
    m_array.~hkArray_9bf500();
    hkBaseObject::~hkBaseObject();
    if (flag & 1) {
        Alloc_9bf500* a = TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(this, m_memSizeAndFlags, 0x1f);
    }
    return this;
}
}
}   // namespace f3m_009bf500

// @f3 0x009b1250 (community match, verified in this file)
namespace f3m_009b1250 {
int hkString_strCmp(int, int);
static __declspec(noinline) int FUN_009b1250(int a0, int a1) { return hkString_strCmp(a0, a1) == 0; }
volatile int g_in; volatile int g_in2; volatile int g_out;
void caller_of_FUN_009b1250() { g_out = FUN_009b1250(g_in, g_in2); }
}   // namespace f3m_009b1250

// @f3 0x009a0ef0 (community match, verified in this file)
namespace f3m_009a0ef0 {
namespace task1753 {
struct __declspec(align(16)) Vec {float x,y,z,w;Vec(){x=y=z=w=0.0f;}};
struct FUN_009a0ef0 {unsigned short zero,one;Vec a,b;FUN_009a0ef0();};
// pdb: hkaDetectRagdollPenetration::BonePenetration::BonePenetration | hkaDetectRagdollPenetration.obj | fnv360_0822_retail, objrun_open, low
FUN_009a0ef0::FUN_009a0ef0():zero(0),one(1){}
}
}   // namespace f3m_009a0ef0

// @f3 0x009b7b40 (community match, verified in this file)
namespace f3m_009b7b40 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
// pdb: hkpMoppAgent::createBvBvAgent | hkpMoppAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
namespace Factory427{extern unsigned long DAT_010f3170;extern int DAT_00e7eb2c;struct Heap{void*FUN_008f6d30(unsigned int,int);};struct Priority{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;int value;};struct Entry{unsigned int unk00,unk04,unk08,unk0c;Priority*priority;};struct FUN_009b7930{void*vtable;unsigned short memory,refs;unsigned int unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;FUN_009b7930(void*)throw();static void*operator new(unsigned int size){Heap*heap=(Heap*)TlsGetValue(DAT_010f3170);FUN_009b7930*memory=(FUN_009b7930*)heap->FUN_008f6d30(size,31);memory->memory=(unsigned short)size;return memory;}};struct Derived:FUN_009b7930{Derived(void*context):FUN_009b7930(context){vtable=&DAT_00e7eb2c;}};FUN_009b7930*__cdecl hkpMoppAgent_createBvBvAgent(Entry*const*a,Entry*const*b,void*unused,void*context){if((*a)->priority->value<(*b)->priority->value)return new FUN_009b7930(context);return new Derived(context);}}
}   // namespace f3m_009b7b40

// @f3 0x009a7ea0 (community match, verified in this file)
extern const char FUN_00e7dfcc;
extern const char FUN_00e7dfa8;
namespace f3m_009a7ea0 {
struct ArgType {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
};

struct CallbackClass {
    void* unk00;
    int unk04;
    void* unk08;
    int unk0C;
    void* unk10;
    int unk14;
    void* unk18;
    int unk1C;
    float unk20;

    CallbackClass* FUN_009a7ea0(ArgType* ptr, float val);
};

void __stdcall FUN_0099f010(int arg);


// pdb: hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection | hkpTriSampledHeightFieldCollection.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: shape, radius
CallbackClass* CallbackClass::FUN_009a7ea0(ArgType* ptr, float val)
{
    CallbackClass* self = this;

    FUN_0099f010(8);

    self->unk20 = val;
    self->unk00 = const_cast<void*>(static_cast<const void*>(&FUN_00e7dfcc));
    self->unk10 = const_cast<void*>(static_cast<const void*>(&FUN_00e7dfa8));
    self->unk18 = ptr;

    if (ptr->unk04) {
        ptr->unk06 += 1;
    }

    return self;
}
}   // namespace f3m_009a7ea0

// @f3 0x009a9b30 (community match, verified in this file)
namespace f3m_009a9b30 {
namespace Metric439{struct Vector{float x,y,z,w;float LengthSquared()const{return x*x+y*y+z*z;}};struct Owner{
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
unsigned int unk28;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
unsigned int unk3c;
unsigned int unk40;
unsigned int unk44;
unsigned int unk48;
unsigned int unk4c;
unsigned int unk50;
unsigned int unk54;
unsigned int unk58;
unsigned int unk5c;
unsigned int unk60;
unsigned int unk64;
unsigned int unk68;
unsigned int unk6c;
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;
unsigned int unka8;
unsigned int unkac;
unsigned int unkb0;
unsigned int unkb4;
unsigned int unkb8;
unsigned int unkbc;
unsigned int unkc0;
unsigned int unkc4;
unsigned int unkc8;
unsigned int unkcc;
// pdb: calcVelocityForDeactivation | hkpRigidMotionUtil.obj | tesv_win, objrun_open, low
Vector first,second;};static __declspec(noinline) float FUN_009a9b30(const Owner*owner,float t){float second=owner->second.LengthSquared();float first=owner->first.LengthSquared();float result=t*t*second+first;return result;}const Owner*volatile input;volatile float factor,result;void caller_of_FUN_009a9b30(){result=FUN_009a9b30(input,factor);}}
}   // namespace f3m_009a9b30

// @f3 0x009b1330 (community match, verified in this file)
namespace f3m_009b1330 {
namespace w9b1330 {
int __cdecl hkString_strCmp(const char* a, const char* b);
struct Item { virtual void v00(); virtual void v01(); virtual void v02(); virtual const char* GetName(); };
struct ItemArray { Item** data; int count; };
// pdb: `anonymous namespace'::Reader::_getType | hkXmlTagfileReader.obj | tesv_win, caller_sim, low
static __declspec(noinline) Item* FUN_009b1330(const ItemArray& items, const char* name) {
    for (int i = items.count - 1; i >= 0; i--) {
        const char* itemName = items.data[i]->GetName();
        if (hkString_strCmp(itemName, name) == 0) return items.data[i];
    }
    return 0;
}
Item* Caller9b1330(ItemArray* items, const char* name) { return FUN_009b1330(*items, name); }
}
}   // namespace f3m_009b1330

// @f3 0x009b5d30 (community match, verified in this file)
namespace f3m_009b5d30 {
struct C9bVector {float x,y,z,w; void Set(float a,float b,float c,float d){w=d;z=c;y=b;x=a;}};
struct C9bTarget {virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual unsigned Get();};
struct C9bHandle {C9bTarget* object;};
struct C9bTask {int a;C9bHandle* handle;int unk08;unsigned result;int c;void* owner;int d;int unk1c; };
void __cdecl FUN_00a2b420(void*,C9bTask*);
struct C9bOwner {int unk00;int unk04;void* owner;int unk0c;C9bVector first,second;int task;void hkpBvTreeStreamAgent_updateShapeCollectionFilter(int,C9bHandle*,int,int);};
// pdb: hkpBvTreeStreamAgent::updateShapeCollectionFilter | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void C9bOwner::hkpBvTreeStreamAgent_updateShapeCollectionFilter(int a,C9bHandle* handle,int c,int d) {
    first.Set(0.0f,0.0f,0.0f,0.0f);
    second.Set(0.0f,0.0f,0.0f,0.0f);
    unsigned result=handle->object->Get();
    C9bTask value;
    value.a=a; value.c=c; value.handle=handle; value.owner=owner; value.result=result; value.d=d;
    FUN_00a2b420(&task,&value);
}
}   // namespace f3m_009b5d30

// @f3 0x009af400 (community match, verified in this file)
namespace f3m_009af400 {
namespace StreamCleanup2055 {
struct RefObject {
    __declspec(nothrow) virtual void Destroy(unsigned int);
    unsigned short memorySize;short refs;
    __declspec(nothrow) void RemoveReference(){if(memorySize){--refs;if(refs==0)Destroy(1);}}
};
struct Buffer {char* data;__declspec(nothrow) void FUN_009af3a0();};
struct Base {__declspec(nothrow) virtual ~Base(){}unsigned short memorySize,refs;};
struct Stream:Base {
    RefObject* reader;
    Buffer buffer;
    virtual ~Stream();
};
// pdb: hkBufferedStreamReader::~hkBufferedStreamReader | hkBufferedStreamReader.obj | fnv360_0822_retail, objrun, medium
Stream::~Stream(){reader->RemoveReference();buffer.FUN_009af3a0();}
}
}   // namespace f3m_009af400

// @f3 0x009a7f20 (community match, verified in this file)
namespace f3m_009a7f20 {
namespace HeightBounds2056 {
struct Transform;struct Bounds;
struct HeightField {
    virtual void Slot0();virtual void Slot4();virtual void Slot8();virtual void SlotC();
    virtual void Slot10();virtual void Slot14();virtual void Slot18();
    virtual void BoundsFor(const Transform*,float,Bounds*);
};
struct Owner {
    unsigned int unk00,unk04,unk08,unk0C,unk10,unk14;
    HeightField* field;unsigned int unk1C;float radius;
    void FUN_009a7f20(const Transform*,float,Bounds*);
};
__declspec(noinline) HeightField* __fastcall FUN_009a7e90(Owner* owner){return owner->field;}
// pdb: hkpTriSampledHeightFieldBvTreeShape::castRayImpl | hkpTriSampledHeightFieldBvTreeShape.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: input, output
void Owner::FUN_009a7f20(const Transform* transform,float extra,Bounds* out) {
    HeightField* source=FUN_009a7e90(this);
    float expanded=radius+extra;
    source->BoundsFor(transform,expanded,out);
}
}
}   // namespace f3m_009a7f20

// @f3 0x009ae990 (community match, verified in this file)
extern int DAT_00e7e0f4;
namespace f3m_009ae990 {
namespace Task9ae9 {
struct Ref { void FUN_009316e0(); };
struct RefObj {
    void* methods;
    unsigned short memSize;
    unsigned short refCount;
    RefObj() { refCount = 1; }
};
struct Action : RefObj {
    void* world;
    void* island;
    void* userData;
    void* name;
    Action(void* ud) : world(0), island(0), userData(ud), name(0) {}
};
struct EntityAction : Action {
    Ref* entity;
    EntityAction(Ref* p, void* a);
};
}
// pdb: hkpUnaryAction::hkpUnaryAction | hkpUnaryAction.obj | fnv360_0822_retail, call_seq, high
// pdb params: entity, userData
Task9ae9::EntityAction::EntityAction(Ref* p, void* a) : Action(a)
{
    methods = &DAT_00e7e0f4;
    entity = p;
    if (p)
        p->FUN_009316e0();
}
}   // namespace f3m_009ae990

// @f3 0x009bbed0 (community match, verified in this file)
extern int DAT_00e7ec04;
namespace f3m_009bbed0 {
namespace f3m_009bbed0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct Alloc { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };

struct Arr {
    short* data;
    int size;
    int capacityAndFlags;
    __forceinline ~Arr() throw()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int cap = capacityAndFlags & 0x3fffffff;
            Alloc* a = (Alloc*)TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(data, cap * 2, 0x17);
        }
    }
};

struct Obj {
    void* vtbl;
    unsigned short memSizeAndFlags;
    short referenceCount;
    int unk08;
    Arr arr;
    Obj* FUN_009bbed0(unsigned int flags);
};

// pdb: hkpHeightFieldAgent::`scalar deleting destructor' | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable, high
Obj* Obj::FUN_009bbed0(unsigned int flags)
{
    vtbl = &DAT_00e7ec04;
    arr.~Arr();
    vtbl = &DAT_00dcc494;
    if (flags & 1) {
        Alloc* a = (Alloc*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(this, memSizeAndFlags, 0x1f);
    }
    return this;
}
}
}   // namespace f3m_009bbed0

// @f3 0x009b1970 (community match, verified in this file)
namespace f3m_009b1970 {
namespace A302K {

struct Flag {
    char value;
};

struct Source {
    int FUN_009b0490();
};

struct Target {
    void FUN_009b0e60(int b, Source* a);
};

struct Visitor {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_009b1110(Flag flag);
    void FUN_009b1160();
};

void __cdecl FUN_009b1270();

struct Owner {
    int unk00;
    int unk04;
    int unk08;
    Target unk0c;

    void FUN_009b1370(Source* src, Visitor* visitor, void (__cdecl* callback)(), int extra);
    void FUN_009b1970(Source* src, int b);
};

}

void A302K::Owner::FUN_009b1970(Source* src, int b)
{
    if (b == 0)
        b = src->FUN_009b0490();
    unk0c.FUN_009b0e60(b, src);
    Visitor visitor;
    Flag flag;
    flag.value = 0;
    visitor.FUN_009b1110(flag);
    FUN_009b1370(src, &visitor, FUN_009b1270, 0);
    visitor.FUN_009b1160();
}
}   // namespace f3m_009b1970

// @f3 0x009a8380 (community match, verified in this file)
namespace f3m_009a8380 {
namespace f3m_009a8380 {
struct B9a8380 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void Target(int a); };
struct A9a8380 { B9a8380* FUN_009a7e90(); };
A9a8380* __cdecl FUN_009a82b0();
void __stdcall FUN_009a8380(int a) { FUN_009a82b0()->FUN_009a7e90()->Target(a); }
}
}   // namespace f3m_009a8380

// @f3 0x009b3360 (community match, verified in this file)
namespace f3m_009b3360 {
struct Pair { int a; int b; };
struct PairArray { Pair* data; int size; unsigned int capAndFlags; };
void __cdecl FUN_00901f10(PairArray* a, int elemSize);
struct Reg { char pad[0x24]; virtual void vfn00(); virtual void vfn04(); virtual void vfn08(); virtual void vfn0c(); virtual void vfn10(); virtual void vfn14(); virtual void vfn18(); virtual void vfn1c(); virtual int vfn20(); };
struct Ctx { Reg* FUN_009ee790(); void FUN_009ee740(const char* s, unsigned int n); };
extern unsigned int __cdecl FUN_009233f0(const char* s);
// pdb: saveCstring | hkObjectCopier.obj | fnv360_0822_retail, call_gap + bridge(call_gap|objrun) + skyrim(call_gap), high
static __declspec(noinline) int saveCstring(int a0, int a1, int a2, PairArray* arr, const char* name, Ctx* ctx, unsigned int id) {
    int v = ctx->FUN_009ee790()->vfn20();
    if (arr->size == (int)(arr->capAndFlags & 0x3fffffff)) FUN_00901f10(arr, 8);
    Pair* data = arr->data;
    int index = arr->size;
    data[index].a = id;
    data[index].b = v;
    arr->size = arr->size + 1;
    unsigned int n = FUN_009233f0(name) + 1;
    ctx->FUN_009ee740(name, n);
    return 0;
}
volatile int g0,g1,g2,g3,g4,g5,g6; volatile int g_out;
void caller_of_FUN_009b3360() { g_out = saveCstring(g0,g1,g2,(PairArray*)g3,(const char*)g4,(Ctx*)g5,(unsigned)g6); }
}   // namespace f3m_009b3360

// @f3 0x009aec10 (community match, verified in this file)
namespace f3m_009aec10 {
struct Str9aec10 { char* data; int len; int cap; };
int FUN_009233f0(const char* s);
void FUN_009233b0(char* dst, const char* src);
void FUN_00901e90(Str9aec10* s, int newcap, int flag);
// pdb: hkStringBuf::append | hkStringBuf.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: s, len
char* FUN_009aec10(const char* src, Str9aec10* s) {
    int n = FUN_009233f0(src) + 1;
    int cap = s->cap & 0x3fffffff;
    if (cap < n) {
        int newcap = cap * 2;
        if (n >= newcap) newcap = n;
        FUN_00901e90(s, newcap, 1);
    }
    s->len = n;
    FUN_009233b0(s->data, src);
    s->data[s->len - 1] = 0;
    for (int i = 0; i < s->len; ++i) {
        if (s->data[i] == '/') s->data[i] = '\\';
    }
    return s->data;
}
}   // namespace f3m_009aec10

// @f3 0x009be7d0 (community match, verified in this file)
#include <windows.h>
extern unsigned int DAT_010f3170;
namespace f3m_009be7d0 {
extern "C" void _ReadWriteBarrier(void);

struct ThreadMemory9be7d0 {
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
    int maxNumElemsOnFreeList;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    void* unk58;
    int unk5c;
    void FUN_008f6890(int row, void* p, int memClass);
};

struct FUN_009be7d0 {
    virtual ~FUN_009be7d0();
    // pdb: hkpSimpleClosestContactCollector::`scalar deleting destructor' | hkpConvexListAgent.obj | fnv360_0822_retail, objrun_open, low
    static void operator delete(void* p) {
        ThreadMemory9be7d0* m = (ThreadMemory9be7d0*)TlsGetValue(DAT_010f3170);
        if (m->unk5c >= m->maxNumElemsOnFreeList) m->FUN_008f6890(4, p, 0x1f);
        else { _ReadWriteBarrier(); void* next = m->unk58; m->unk5c++; *(void**)p = next; m->unk58 = p; }
    }
};

FUN_009be7d0::~FUN_009be7d0() {
}
}   // namespace f3m_009be7d0

// @f3 0x009afde0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009afde0 {
namespace n9afde0 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* DAT_00d9b080)(unsigned int);
extern void __cdecl FUN_008f90f0(void*);
struct Shape { struct Inner* inner; };
struct Inner;
struct Input { Shape* shape; int type; };
struct Vec4 { float x, y, z, w; };
struct FUN_009afd00 {
    int vtbl;
    short memSize;
    short refCount;
    unsigned unk08,unk0c,unk10,unk14,unk18,unk1c;
    float f20, f24, f28, f2c;
    FUN_009afd00(Inner* a, int b);
    static void* operator new(unsigned int size)
    {
        Alloc* al = DAT_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x29);
        ((short*)p)[2] = (short)size;
        return p;
    }
    static void* operator new(unsigned, void* block) { return block; }
    static void operator delete(void* p) { FUN_008f90f0(p); }

};
struct PendingAllocation {
    void* block;
    ~PendingAllocation() { if (block) FUN_008f90f0(block); }
};
struct Creator {
    unsigned unk00,unk04,unk08,unk0c;
    int unk10;
    unsigned unk14,unk18,unk1c;
    float f20, f24, f28, f2c;
    FUN_009afd00* FUN_009afde0(Input* a, Input* b);
};
// pdb: hkLiquidAction::clone | hkLiquidAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: newEntities, newPhantoms
FUN_009afd00* Creator::FUN_009afde0(Input* a, Input* b)
{
    if (a->type != 2)
        return 0;
    const int kindB=static_cast<const volatile int&>(b->type);
    if (kindB)
        return 0;
    {
    PendingAllocation pending={FUN_009afd00::operator new(sizeof(FUN_009afd00))};
    Shape* source=static_cast<Shape* const volatile&>(a->shape);
    int user=static_cast<const volatile int&>(unk10);
    Inner* child=static_cast<Inner* const volatile&>(source->inner);
    FUN_009afd00* obj=new (pending.block) FUN_009afd00(child, user);
    pending.block=0;
    obj->f20 = f20;
    obj->f24 = f24;
    obj->f28 = f28;
    obj->f2c = f2c;
    return obj;
    }
    return 0;
}
}

}   // namespace f3m_009afde0

// @f3 0x009a9a10 (community match, verified in this file)
namespace f3m_009a9a10 {
namespace f3m_009a9a10 {

struct Elem30 {
    int m00, m04, m08, m0c;
    int m10, m14, m18, m1c;
    int m20, m24, m28, m2c;
};

extern "C" void __cdecl FUN_0098a960(void* array, int newCapacity, int elemSize);

class Arr30 {
public:
    void FUN_009a9a10(int index, const Elem30* values, int count);
    Elem30* m_data;
    unsigned short m_size;
    unsigned short m_capacityAndFlags;
};

static __forceinline void CopyBackward(Elem30* dest, const Elem30* source, int count)
{
    for (int i = count - 1; i >= 0; --i)
        dest[i] = source[i];
}

// pdb: hkSmallArray<struct hkConstraintInternal>::insertAt | hkpWorldConstraintUtil.obj | tesv_win, call_seq, medium
void Arr30::FUN_009a9a10(int index, const Elem30* values, int count)
{
    int size = m_size;
    int newSize = size + count;
    int numToMove = size - index;
    int cap = m_capacityAndFlags & 0x3fff;
    if (cap < newSize) {
        int newCapacity = cap * 2;
        if (newSize >= newCapacity)
            newCapacity = newSize;
        FUN_0098a960(this, newCapacity, 0x30);
    }
    Elem30* dst = &m_data[index];
    Elem30* end = &m_data[index + count];
    CopyBackward(end, dst, numToMove);
    CopyBackward(&m_data[index], values, count);
    m_size = (unsigned short)newSize;
}

}

}   // namespace f3m_009a9a10

// @f3 0x009a1a90 (community match, verified in this file)
extern float DAT_01169330;
extern float DAT_01169334;
extern float DAT_01169338;
extern float DAT_0116933c;
extern float DAT_01169340;
extern float DAT_01169344;
extern float DAT_01169348;
extern float DAT_0116934c;
extern float DAT_01169350;
extern float DAT_01169354;
extern float DAT_01169358;
extern float DAT_0116935c;
extern float DAT_01169360;
extern float DAT_01169364;
extern float DAT_01169368;
extern float DAT_0116936c;
namespace f3m_009a1a90 {
namespace f3m_009a1a90 {
struct V8 { float x[8]; };
struct Obj {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float unk20;
    void FUN_009a1a90(int a, int b, int c, V8* p1, int e, V8* p2);
};
struct C4 { float r, g, b, a; };
static inline void Blend(C4& d, const C4& o, float t)
{
    float s = 1.0f - t;
    d.r = d.r * t + o.r * s;
    d.g = d.g * t + o.g * s;
    d.b = d.b * t + o.b * s;
    d.a = d.a * t + o.a * s;
}
static inline void BlendFirst(C4& d, const C4& o, float t)
{
    float s = 1.0f - t;
    d.r = d.r * t + o.r * s;
    d.g = d.g * t + o.g * s;
    float& blue = d.b;
    blue = blue * t + o.b * s;
    d.a = d.a * t + o.a * s;
}
static inline void BlendGreen(C4& d, const C4& o, float t)
{
    float s = 1.0f - t;
    d.r = d.r * t + o.r * s;
    float& green = d.g;
    green = green * t + o.g * s;
    d.b = d.b * t + o.b * s;
    d.a = d.a * t + o.a * s;
}
static inline void BlendRed(C4& d, const C4& o, float t)
{
    float s = 1.0f - t;
    volatile float& red = d.r;
    red = red * t + o.r * s;
    volatile float& green = d.g;
    green = green * t + o.g * s;
    volatile float& blue = d.b;
    blue = blue * t + o.b * s;
    volatile float& alpha = d.a;
    alpha = alpha * t + o.a * s;
}
void Obj::FUN_009a1a90(int a, int b, int c, V8* p1, int e, V8* p2)
{
    float t = unk20;
    BlendFirst(*(C4*)&p1->x[0], *(C4*)&DAT_01169330, t);
    BlendGreen(*(C4*)&p1->x[4], *(C4*)&DAT_01169340, t);
    BlendGreen(*(C4*)&p2->x[0], *(C4*)&DAT_01169350, t);
    BlendRed(*(C4*)&p2->x[4], *(C4*)&DAT_01169360, t);
}
}
}   // namespace f3m_009a1a90

// @f3 0x009b1490 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace f3m_009b1490 {
extern unsigned long DAT_010f3170;
struct Heap {
    void FUN_008f6d90(void* p, unsigned int bytes, int tag) throw();
};
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
void __cdecl FUN_00901f10(void* arr, int elemSize) throw();
int __cdecl hkString_strCmp(const char* a, const char* b) throw();

template <class T> struct Array {
    T* data;
    int count;
    int capAndFlags;
    Array() throw() : data(0), count(0), capAndFlags(0x80000000) {}
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
            h->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
    T& operator[](int i) throw() { return data[i]; }
    __forceinline void setSize(int n, const T& fill) throw() {
        int oldSize = count;
        if (oldSize < n) {
            if ((capAndFlags & 0x3fffffff) < n)
                FUN_00901e90(this, n, sizeof(T));
            for (int i = oldSize; i < n; i++)
                data[i] = fill;
        }
        count = n;
    }
    void pushBack(const T& t) throw() {
        if (count == (capAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[count] = t;
        count++;
    }
    void FUN_00929ad0(Array<T>& other) throw();
};

struct Edge {
    const char* a;
    const char* b;
 const char* getA() const { return a; }
 const char* getB() const { return b; }
};

struct EdgeSet {
    int unk00;
    int unk04;
    Array<Edge*> items;
    Edge* getEdge(int i) const { return items.data[i]; }
    int FUN_009b1490(const char* start, const char* end, Array<Edge*>* out);
};

// pdb: hkBuildSizePerName | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, caller_sim, low
int EdgeSet::FUN_009b1490(const char* start, const char* end, Array<Edge*>* out)
{
    if (hkString_strCmp(start, end) == 0)
        return 0;

    Array<int> prev;
    prev.setSize(items.count, -1);
    Array<int> others;
    Array<int> frontier;

    for (int i = 0; i < items.count; i++) {
        if (hkString_strCmp(end, getEdge(i)->getB()) == 0) {
            if (hkString_strCmp(start, getEdge(i)->getA()) == 0) {
                out->pushBack(items[i]);
                return 0;
            }
            frontier.pushBack(i);
        } else {
            others.pushBack(i);
        }
    }

    while (frontier.count != 0) {
        Array<int> next;
        for (int qi = others.count - 1; qi >= 0; qi--) {
            int cur = others[qi];
            for (int ri = 0; ri < frontier.count; ri++) {
                int r = frontier[ri];
                if (hkString_strCmp(getEdge(cur)->getB(), getEdge(r)->getA()) == 0) {
                    prev[cur] = r;
                    if (hkString_strCmp(getEdge(cur)->getA(), start) == 0) {
                        for (int idx = cur; idx != -1; idx = prev[idx])
                            out->pushBack(items[idx]);
                        return 0;
                    }
                    next.pushBack(cur);
                    others.count--;
                    others[qi] = others[others.count];
                }
            }
        }
        frontier.FUN_00929ad0(next);
    }
    return 1;
}
}

// @f3 0x009afc90 (community match, verified in this file)
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() {}
};

namespace f3m_009afc90 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;

struct Heap
{
    void FUN_008f6d90(void* p, int size, int memClass);
};
class hkReferencedObject : public ::hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class InterfaceA : public ::hkBaseObject
{
  public:
    int unk04;
    int unk08;
};
class InterfaceB : public ::hkBaseObject
{
  public:
    int unk04;
};
}

class FUN_009afc90 : public f3m_009afc90::hkReferencedObject
{
  public:
    FUN_009afc90();
    virtual ~FUN_009afc90();
    f3m_009afc90::InterfaceA m_kPartA;
    f3m_009afc90::InterfaceB m_kPartB;

    // pdb: hkSocket::`scalar deleting destructor' | hkSocket.obj | fnv360_0822_retail, vtable, high
    static void operator delete(void* p)
    {
        f3m_009afc90::Heap* heap = (f3m_009afc90::Heap*)f3m_009afc90::TlsGetValue(f3m_009afc90::DAT_010f3170);
        heap->FUN_008f6d90(p, static_cast<FUN_009afc90*>(p)->m_usMemSizeAndFlags, 0x15);
    }
};

FUN_009afc90::FUN_009afc90()
{
}

FUN_009afc90::~FUN_009afc90()
{
}

// @f3 0x009aec90 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern const char str_00dfa594[],str_00db4aa0[],str_00e7e118[],str_00e7e114[];
namespace f3m_009aec90 {
namespace path_normalization {

struct MemoryManager { void FUN_008f6d90(void*,int,int) throw(); };
__declspec(dllimport) MemoryManager* __stdcall FUN_00d9b080(unsigned int) throw();
int FUN_009233f0(const char*) throw();
void FUN_009234e0(void*,const void*,int) throw();
void FUN_009234f0(void*,const void*,int) throw();
void FUN_00901e90(void*,int,int) throw();
struct Bool {
    char value;
    Bool(bool test):value(test) {}
    operator bool() const { return value!=0; }
};
struct StringBuffer {
    char* data;int count;unsigned int capacityAndFlags;
    __forceinline void Resize(int needed) throw() {
        int capacity=capacityAndFlags&0x3fffffffu;
        if(capacity<needed) { int grown=capacity*2;if(needed>=grown)grown=needed;FUN_00901e90(this,grown,1); }
        count=needed;
    }
    __forceinline StringBuffer(const char* text) throw() : data(0),count(0),capacityAndFlags(0x80000000u) {
        if(text) { int size=FUN_009233f0(text)+1;Resize(size);FUN_009234e0(data,text,size); }
        else { Resize(1);data[0]=0; }
    }
    __forceinline void Release(int bytes) throw() {
        MemoryManager* allocator=FUN_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(data,bytes,23);
    }
    __forceinline ~StringBuffer() throw() { if((capacityAndFlags&0x80000000u)==0) Release(capacityAndFlags&0x3fffffffu); }
    Bool FUN_00923f00(const StringBuffer&,const StringBuffer&,int) throw();
    Bool FUN_00923980(const char*) const throw();
    __forceinline void Reserve(int minimum) throw() {
        const int capacity=capacityAndFlags&0x3fffffffu;
        if(capacity<minimum) { int doubled=2*capacity; int newSize=(minimum<doubled)?doubled:minimum; FUN_00901e90(this,newSize,1); }
    }
    __forceinline StringBuffer& operator=(const StringBuffer& other) throw() {
        int size=other.count;Reserve(size);count=size;FUN_009234e0(data,other.data,size);return *this;
    }
    __forceinline void RemovePrefix(int prefix) throw() {
        int characters=0x7fffffff;
        int length=count-prefix-1;if(length<characters)characters=length;
        FUN_009234f0(data,data+prefix,characters+1);data[characters]=0;Resize(characters+1);
    }
};
const char* FUN_009aec90(const char* input,StringBuffer& output) {
    StringBuffer working(input);
    Bool changed=working.FUN_00923f00(StringBuffer(str_00db4aa0),StringBuffer(str_00dfa594),1);
    changed=working.FUN_00923f00(StringBuffer(str_00e7e118),StringBuffer(str_00dfa594),1)||changed;
    if(working.FUN_00923980(str_00e7e114)) { working.RemovePrefix(2);changed=true; }
    if(changed) { output=working;return output.data; }
    return input;
}
}
}   // namespace f3m_009aec90

// @f3 0x009b1e40 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009b1e40 {

struct Source9b1e40;
struct Tail9b1e40 {unsigned unknown[3];Tail9b1e40* next;};
struct Root9b1e40 {unsigned unknown[2];Source9b1e40* tail;};
struct Heap9b1e40 {void FUN_008f6d90(void*,int,int) throw();};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Array9b1e40 {
    Root9b1e40** data;
    int size;
    int capacity;
    Array9b1e40() throw():data(0),size(0),capacity(static_cast<int>(0x80000000u)) {}
    unsigned int GetCapacity() const throw() {return static_cast<unsigned int>(capacity)&0x3fffffff;}
    bool IsOwned() const throw() {return (capacity&static_cast<int>(0x80000000u))==0;}
    ~Array9b1e40() throw() {
        if(!IsOwned())
            return;
        const int count=GetCapacity();
        Heap9b1e40* heap=static_cast<Heap9b1e40*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(data,count*4,23);
    }
};
struct Class9b1e40 {
    __declspec(nothrow) int FUN_009b0bb0(int) throw();
};
struct Registry9b1e40 {
    virtual ~Registry9b1e40() throw();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    __declspec(nothrow) virtual Class9b1e40* Lookup(void*) throw();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    __declspec(nothrow) virtual void VisitDestination(void*) throw();
    virtual void Slot10();
    virtual void Slot11();
    __declspec(nothrow) virtual void VisitSource(void*) throw();
    unsigned short memoryFlags;
    short references;
    void RemoveReference() throw() {
        if(memoryFlags) {
            --references;
            if(references==0)
                delete this;
        }
    }
};
struct S_00dbd8a0_Byte {char value;};
struct S_00dbd8a0_Mem30 {
    unsigned int fields[4];
    ~S_00dbd8a0_Mem30() throw() {FUN_009b1160();}
    __declspec(nothrow) S_00dbd8a0_Mem30(S_00dbd8a0_Byte) throw();
    __declspec(nothrow) void FUN_009b1160() throw();
    __declspec(nothrow) void* FUN_009b10f0(void*,void*) throw();
    __declspec(nothrow) void FUN_009b0e60(void*,void*) throw();
};

class hkBaseObject {
public:
    virtual ~hkBaseObject() throw() {}
};
class hkRenamedClassNameRegistry:public hkBaseObject {
public:
    unsigned int unknown;
    S_00dbd8a0_Mem30 map;
    Registry9b1e40* registry;
    __declspec(nothrow) hkRenamedClassNameRegistry(int,Registry9b1e40*) throw();
    __declspec(nothrow) void FUN_009b0e60(void*,void*) throw();
    ~hkRenamedClassNameRegistry() throw() {
        if(registry)
            registry->RemoveReference();
    }
};
struct VisitorB9b1e40:hkBaseObject {
    unsigned int unknown04,unknown08;
    S_00dbd8a0_Mem30 map;
    __declspec(nothrow) VisitorB9b1e40(bool) throw();
    __declspec(nothrow) void hkDynamicClassNameRegistry_merge(void*) throw();

};
struct Pair9b1e40 {void* name;void* target;};
struct Metadata9b1e40 {int sourceSignature,destinationSignature;unsigned unknown;void* name;unsigned unknown10;};
struct Source9b1e40 {
    Pair9b1e40* pairs;
    Metadata9b1e40* metadata;
    void* object;
    Source9b1e40* next;
};
struct Owner9b1e40 {
    __declspec(nothrow) void FUN_009b1490(int,int,Array9b1e40*) throw();
    __declspec(nothrow) Registry9b1e40* FUN_009b1ae0(int) throw();
    __declspec(nothrow) int FUN_009b1e40(Source9b1e40*,int,int) throw();
};
__declspec(nothrow) int Owner9b1e40::FUN_009b1e40(Source9b1e40* source,int from,int to) throw()
{
    Array9b1e40 roots;
    FUN_009b1490(from,to,&roots);
    S_00dbd8a0_Byte firstArgument={0};
    S_00dbd8a0_Mem30 first(firstArgument);
    S_00dbd8a0_Byte secondArgument={0};
    S_00dbd8a0_Mem30 second(secondArgument);
    Registry9b1e40* oldRegistry=FUN_009b1ae0(from);
    Registry9b1e40* newRegistry=FUN_009b1ae0(to);
    hkRenamedClassNameRegistry renames(0,newRegistry);
    VisitorB9b1e40 objects(false);
    for(Source9b1e40* entry=source;entry;entry=entry->next) {
        if(entry->object)
            objects.hkDynamicClassNameRegistry_merge(entry->object);
        Pair9b1e40* pair=entry->pairs;
        if(pair) {
            void* name=pair->name;
            if(name) do {
                renames.map.FUN_009b0e60(name,pair->target);
                ++pair;
                name=pair->name;
            } while(name);
        }
    }
    oldRegistry->VisitSource(&renames.map);
    newRegistry->VisitDestination(&objects);
    for(Source9b1e40* entry=source;entry;entry=entry->next) {
        Metadata9b1e40* metadata=entry->metadata;
        if(metadata && metadata->name) do {
            if(metadata->sourceSignature==-1) {
                Class9b1e40* type=oldRegistry->Lookup(metadata->name);
                metadata->sourceSignature=type->FUN_009b0bb0(0);
            }
            if(metadata->destinationSignature==-1) {
                void* mapped=renames.map.FUN_009b10f0(metadata->name,metadata->name);
                Class9b1e40* type=renames.registry?renames.registry->Lookup(mapped):0;
                metadata->destinationSignature=type->FUN_009b0bb0(0);
            }
            ++metadata;
        } while(metadata->name);
    }
    Source9b1e40* tail=roots.data[0]->tail;
    while(tail->next)
        tail=tail->next;
    tail->next=source;

    return 0;
}













}   // namespace f3m_009b1e40

// @f3 0x009b0360 (community match, verified in this file)
namespace Make9b0360 {
struct Member {int unk00,unk04,unk08;void FUN_00922cb0();};
struct Object {void* table;unsigned short size,refs;Member member;};
struct Allocator {Object* FUN_008f6d30(unsigned,unsigned);};
extern unsigned long DAT_010f3170;
extern int DAT_00e7e5d0;
// pdb: hkVtableClassRegistry::hkVtableClassRegistry | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, uvref, medium
Object* FUN_009b0360() {
 Allocator* allocator=static_cast<Allocator*>(TlsGetValue(DAT_010f3170));
 Object* object=allocator->FUN_008f6d30(20,21);
 object->size=20;
 object->refs=1;
 object->table=&DAT_00e7e5d0;
 object->member.FUN_00922cb0();
 return object;
}
}

// @f3 0x009a2610 (community match, verified in this file)
extern char DAT_00e7dec4;
namespace f3m_009a2610 {
namespace Init9a2610 {
struct Vec4 {float x,y,z;volatile float w;};
struct Object {void* vtable;unsigned short unk04,refs;int zero,type;float radius;int unk14,unk18,unk1c;Vec4 first,second;Object* FUN_009a2610(const Vec4*,const Vec4*,float);};
// pdb: hkpCapsuleShape::hkpCapsuleShape | hkpCapsuleShape.obj | fnv360_0822_retail, call_gap, high
// pdb params: vertexA, vertexB, radius
Object* Object::FUN_009a2610(const Vec4* a,const Vec4* b,float value){radius=value;refs=1;zero=0;type=6;vtable=&DAT_00e7dec4;first.x=a->x;first.y=a->y;first.z=a->z;first.w=a->w;second.x=b->x;second.y=b->y;second.z=b->z;second.w=b->w;first.w=value;second.w=value;return this;}
}
}   // namespace f3m_009a2610

// @f3 0x009a90b0 (community match, verified in this file)
namespace f3m_009a90b0 {
namespace Init9a90b0 {
struct Item {int unk00;unsigned short managed,refs;};struct Allocator {virtual void* allocate(int,unsigned,int);};
extern void* (__stdcall* DAT_00d9b080)(unsigned long);extern unsigned long DAT_010f3170;extern char DAT_00e7e028;
struct Object {void* volatile vtable;unsigned short unk04,refs;Item* item;void* data;int count;unsigned capacity;volatile bool flag;Object* FUN_009a90b0(Item*,unsigned);};
// pdb: hkBufferedStreamWriter::hkBufferedStreamWriter | hkBufferedStreamWriter.obj | fnv360_0822_retail, call_gap, high
// pdb params: s, bufSize
Object* Object::FUN_009a90b0(Item* value,unsigned size){refs=1;item=value;vtable=&DAT_00e7e028;flag=true;Item* current=*reinterpret_cast<Item* volatile*>(&item);if(current&&current->managed)++current->refs;Allocator* allocator=(Allocator*)DAT_00d9b080(DAT_010f3170);data=allocator->allocate(0x40,size,0x1a);capacity=size;count=0;return this;}
}




}   // namespace f3m_009a90b0

// @f3 0x009b4940 (community match, verified in this file)
namespace f3m_009b4940 {
namespace f3m_009b4940 {
struct E { int a, b; };
struct Arr { E* data; unsigned int size; unsigned int cap; };
void __cdecl FUN_00901f10(Arr* a, int n);
struct O9b4940 {
    Arr arr;
    void FUN_009b4940(int a, int b);
};

// pdb: hkClassMember::getArrayMemberSize | hkClassMember.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkRelocationInfo::addLocal)
void O9b4940::FUN_009b4940(int a, int b)
{
    E v;
    v.a = a;
    v.b = b;
    Arr* p = &arr;
    unsigned int space = p->cap & 0x3fffffff;
    if (p->size == space)
        FUN_00901f10(p, 8);
    p->data[p->size] = v;
    p->size++;
}
}
}   // namespace f3m_009b4940

// @f3 0x009b1df0 (community match, verified in this file)
namespace f3m_009b1df0 {
// Reconstruction of FUN_009b1df0 from the 71-byte extent (0x009b1df0-0x009b1e37).
// Shape: __thiscall, one stack pointer argument (ret 4), returns 0.
//   key  = other->vtable[3]()
//   node = this->FUN_009b1ae0(key)
//   temp constructed with FUN_009b1920(other) at frame base
//   node->vtable[9](&temp)
//   temp.map.FUN_009b1160()  (map sits at temp+0xc)

struct Map9b1df0 {
    void* data;
    int unk04;
    int cap;
    void FUN_009b1160();
};

class Other9b1df0 {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int unk0c();
};

class Node9b1df0;

class Visitor9b1df0 {
public:
    int unk00;
    int unk04;
    int unk08;
    Map9b1df0 map;
    int unk18;
    Visitor9b1df0* FUN_009b1920(Other9b1df0* other);
};

class Node9b1df0 {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24(Visitor9b1df0* visitor);
};

class Owner9b1df0 {
public:
    Node9b1df0* FUN_009b1ae0(int key);
    int FUN_009b1df0(Other9b1df0* other);
};

// pdb: hkXmlStreamParser::_parseQBlock | hkXmlStreamParser.obj | tesv_win, objopen_prop, low
int Owner9b1df0::FUN_009b1df0(Other9b1df0* other)
{
    Node9b1df0* node = FUN_009b1ae0(other->unk0c());
    Visitor9b1df0 visitor;
    node->unk24(visitor.FUN_009b1920(other));
    visitor.map.FUN_009b1160();
    return 0;
}
}   // namespace f3m_009b1df0

// @f3 0x009af3c0 (community match, verified in this file)
namespace f3m_009af3c0 {
// Model of FUN_009AF3C0 (56 bytes) - claim clm_75602903cad043ac9567 ✓ Another CONSTRUCTOR, and this one stores **offset ??_7hkBufferedStreamReader@@6B@** ✗✓ the same vtable-address blocker I documented yesterday on another
// entry (my own generated table becomes a new object with a placeholder address ✗ ) - but everything ELSE here is small enough to share, and its instruction ORDER carries real information ✓ 
class Base9af { public: virtual void baseVirtual0() {}              // v3: this base region must be POLYMORPHIC ✓✗→✓✓ with no virtuals this compiler appends the derived table AFTER the base subobject and shifts every later field up four bytes (my word landed at +0xA, that pointer at +0xC ✗ ) - while their build installs that vtable in slot zero of the same object whose word at +0x06 it initialises earlier ✓
                         char padTo02[0x02]; unsigned short flag6;   // v4 THE FIX ✓✗→✓✓ that base ALREADY carries a four-byte vtable slot of its own, so only TWO filler bytes land this word on +0x06 ✗ I sized the filler from the target offset again and my whole object sat four bytes high (word at +0xA, pointer at +0xC ✗ ) - the summation rule bites every time a polymorphic type is involved ✓
                         Base9af() { flag6 = 1; } };               // ORIG: 'mov word ptr [esi+6], 1' happens BEFORE this compilers vtable store in their build ✓✗→✓✓ that ordering is only reachable if the write comes from a
                                     //     subobject initialized ahead of this classes own table installation - which is exactly what base-subobject initialization does ✓ (measured last round on another constructor: base init →
                                     //     vtable store → members → body ✗✓ So I model that one-word write as an INLINE base constructor rather than as a statement in my body, where it would have come out AFTER the table store ✗ ) 
struct Sub9af { void FUN_009af360(unsigned long value); };         // what their build calls LAST: 'lea ecx,[esi+0Ch] ; push arg_4 ; call sub_9AF360' ✓✗→✓ a receiver-in-ECX routine taking ONE stack parameter, invoked on the
                                     //     embedded object at +0x0C ✗ declared WITHOUT a body so this compiler keeps it an out-of-line call exactly as theirs is ✓ (an available inline body would have expanded inside my
                                     //     constructor and added instructions their build does not have ✗ measured rule ✓ ) 
class hkBufferedStreamReader : public Base9af { public: virtual void streamVirtual0() {}   // at least one virtual with an INLINE empty body, so this compiler emits the classes own vtable symbol without leaving unresolved
                                     //     externals behind ✗✓ Their build stores that tables ADDRESS into offset zero ('mov dword ptr [esi], offset ??_7hkBufferedStreamReader@@6B@' ✓ ) - which I can only reach by letting this
                                     //     compiler generate the table, never by declaring it as data ✗ 
                         virtual void streamVirtual4() {} ;        // a second inline-empty slot; nothing in THIS function observes how many slots exist ✗ (only the tables address is written ✓ ) 
                         unsigned char* field8;                           // +0x08: a BYTE pointer, set from the FIRST parameter and re-read after that call ✓✗→✓ (a void pointer cannot be advanced by an offset in C++ ✗✓ which is itself evidence this is treated as byte-addressable memory whose +4 and +6 members are reached by byte offsets ✓ ) 
                                       //     RE-READ after that call ('mov eax,[esi+8] ; cmp word ptr [eax+4],0' ✓✗→✓✓ their build genuinely re-fetches this field instead of keeping it in a register across the call ✗ which is
                                       //     why I write a plain member assignment and read the member again rather than caching it in a local ✓ ) 
                         Sub9af sub0C;                             // +0x0C: the object that routine is called on ('lea ecx,[esi+0Ch]' ✗✓ ) declared as its own type because that callee belongs to IT, not to this class ✓ (my
                                       //     standing rule against declaring a receiver-in-ECX callee inside the class whose member I am defining ✗ ) 
                         hkBufferedStreamReader(unsigned long firstParam, unsigned long secondParam); };   // ORIG: 'retn 8' - TWO parameters cleaned by the CALLEE ✓✗→✓ a thiscall constructor; ECX is the object being
                                                  //     built and their tail returns it in EAX ('mov eax,esi ; pop esi ; retn 8' ✗ ) with no return statement of mine saying so ✓ Parameter identity: the first is stored into
                                                  //     +0x08, the second is pushed as that argument to the embedded objects routine ✓ 
// pdb: hkBufferedStreamReader::hkBufferedStreamReader | hkBufferedStreamReader.obj | fnv360_0822_retail, objrun, medium
// pdb params: s, bufSize
hkBufferedStreamReader::hkBufferedStreamReader(unsigned long firstParam, unsigned long secondParam) {   // ORIG: 'mov eax,[esp+arg_0] ; push esi ; mov esi,ecx' ✗✓ one saved register holding the object under construction
                                     // and that first parameter fetched ONCE at the very top - before even the register save ✓✗→? a fetch order this compiler chooses; my single assignment below reproduces both uses without me
                                     //     trying to force it ✗ 
    this->field8 = (unsigned char*)firstParam;                  // ORIG: mov [esi+8],eax ✗✓ one dword store of that parameter as a pointer ✓
                                       //     regions +0x06 write above happened before the table store ✗ so it cannot be written here in the body ✓ ) 
    ((struct Sub9af*)&this->sub0C)->FUN_009af360(secondParam);     // ORIG: 'lea ecx,[esi+0Ch] ; push <second parameter> ; call sub_9AF360' ✓✗→✓ called ON the embedded object at +0x0C with one stack argument ✗ which is why
                                       //     that routine is declared on Sub9af and reached through a pointer to that member rather than being a member of this class ✓ 
    if (*(unsigned short*)(this->field8 + 4) != 0) {               // ORIG: mov eax,[esi+8] ; cmp word ptr [eax+4], 0 ; jz join ✗✓ the field RE-LOADED from memory after that call, then a WORD tested against zero ✓
                                       // ✗✓ so their source read the member again (a local would have kept it live and emitted no reload ✗ ) - and what it points at has a **WORD** at +0x04 tested against zero ✓ plus another
                                       //     WORD at +0x06 incremented two instructions later ✓ so this really is sixteen-bit arithmetic on that pointed-to object, not a byte flag or a dword counter ✗ 
        *(unsigned short*)(this->field8 + 6) = (unsigned short)(*(unsigned short*)(this->field8 + 6) + 1);   // ORIG: add word ptr [eax+6], 1 ✗✓ one instruction incrementing a WORD in memory ✓
                                          // instruction directly against memory ✗ which ordinary source produces for += 1 on a sixteen-bit lvalue ✓ (a local copy plus a store-back would have emitted a load and a separate
                                          //     store instead ✗ ) 
    }                                                   
    // ORIG: the join block is simply 'mov eax,esi ; pop esi ; retn 8' ✓✗→✓ this constructor returns the object it built ✓ with both parameters released by the callee ✗ and that word increment skipped entirely when the
                                       //     +0x04 test was zero ✓ (one conditional in, one straight-line out - no else block of any kind appears in their build ✓ ) 
}                                                                          // closes the constructor - expected residue is that ONE vtable-address store: my own generated table is a new object
                                             // so the checker compares it against theirs and yields a placeholder immediate instead of their read-only-data address ✗✓ (the documented blocker for constructor entries, measured on
                                             //     another entry this week ✓ ) everything else here - the base-region word write ordering, that re-fetch after the call, and the in-place word increment - should be shared ✗→? 
}   // namespace f3m_009af3c0

// @f3 0x009babf0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern unsigned int DAT_0116913c;
namespace f3m_009babf0 {
extern const char DAT_00e7ebec[];  // "TtList3"
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace s9babf0 {
struct TimerCommand { const char* name; unsigned int ticks; unsigned int unk08; };
struct MonitorStream {
    void* unk00; char* m_end; void* unk08; char* m_capacityEnd;
    static MonitorStream& getInstance() { return *(MonitorStream*)TlsGetValue(DAT_0116913c); }
    bool memoryAvailable() const { return m_end < m_capacityEnd; }
};
inline void timerMark(const char* name)
{
    MonitorStream& s = MonitorStream::getInstance();
    if (s.memoryAvailable()) {
        TimerCommand* h = (TimerCommand*)s.m_end;
        h->name = name;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        h->ticks = ticks;
        s.m_end = (char*)(h + 1);
    }
}
struct ThreadMemory {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10();
    // Fake match: throw() on these two virtuals and on FUN_00a2b910 stands in for Havok's exception-free
    // build; without it /EHsc adds an unwind frame for the local buffer's destructor.
    virtual void* onStackOverflow(int size) throw();
    virtual void onStackUnderflow(void* p) throw();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* m_current; int unk24; char* m_base; char* m_end;
    static ThreadMemory& getInstance() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
    void* allocateStack(int size) {
        char* cur = m_current;
        if (cur + size <= m_end) { m_current = cur + size; return cur; }
        return onStackOverflow(size);
    }
    void deallocateStack(void* p) {
        m_current = (char*)p;
        if ((char*)p == m_base) onStackUnderflow(p);
    }
};
template <typename T> inline T* hkAllocateStack(int n) { return (T*)ThreadMemory::getInstance().allocateStack((n * sizeof(T) + 0x10) & ~0xf); }
template <typename T> inline void hkDeallocateStack(T* p) { ThreadMemory::getInstance().deallocateStack(p); }
template <typename T> struct LocalBuffer {
    LocalBuffer(int n) { m_p = hkAllocateStack<T>(n); }
    ~LocalBuffer() { hkDeallocateStack<T>(m_p); }
    T& operator[](int i) { return m_p[i]; }
    T* begin() { return m_p; }
    T* m_p;
};
struct ShapeContainer { virtual void c0(); };
struct Shape { virtual void s0(); int unk04, unk08, unk0c; };
struct ListShape : Shape, ShapeContainer {
    int m_disableWelding;
    void* m_childData; int m_childCount; int unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned int m_enabledChildren[8];
    unsigned int isChildEnabled(unsigned int i) const { if (i < 256) return m_enabledChildren[i >> 5] & (1 << (i & 31)); return 1; }
    int getNumChildShapes() const { return m_childCount; }
    const ShapeContainer* getContainer() const { return this; }
};
struct CdBody { const Shape* m_shape; const Shape* getShape() const { return m_shape; } };
struct ProcessInput {
    CdBody* m_bodyA; CdBody* m_bodyB;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50;
    int unk54;
};
void __cdecl FUN_00a2b910(void* a, void* b, const ProcessInput* c, const ShapeContainer* d, const unsigned int* e, void* f) throw();
}

// pdb: hkListAgent3::process | hkpListAgent3.obj | fnv360_0822_retail, ustr, medium
// pdb params: input, entry, agentData, separatingNormal, output
void* __cdecl FUN_009babf0(const s9babf0::ProcessInput& input, void* entry, void* agentData, void* sepNormal, void* output)
{
    using namespace s9babf0;
    timerMark(DAT_00e7ebec);
    const ListShape* lShape = static_cast<const ListShape*>(input.m_bodyB->getShape());
    int size = lShape->getNumChildShapes();
    LocalBuffer<unsigned int> hitList(size + 1);
    {
        int d = 0;
        for (int i = 0; i < size; i++) {
            if (lShape->isChildEnabled(i))
                hitList[d++] = i;
        }
        hitList[d] = 0xffffffff;
    }
    void* end = (char*)agentData + input.unk54;
    FUN_00a2b910(agentData, end, &input, lShape->getContainer(), hitList.begin(), output);
    timerMark("Et");
    return (char*)agentData + 0x10;
}
}   // namespace f3m_009babf0

// @f3 0x009b1ae0 (community match, verified in this file)
#include <stddef.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
extern unsigned int DAT_010f3170;
struct ClassKey770;
const ClassKey770* FUN_0093e470() throw();
int hkString_strCmp(const ClassKey770*,const ClassKey770*) throw();
inline bool SameKey770(const ClassKey770* a,const ClassKey770* b) throw() { return hkString_strCmp(a,b)==0; }
struct Memory770 {
    void* FUN_008f6d30(int,int) throw();
    void FUN_008f6d90(void*,int,int) throw();
};
inline Memory770* GetMemory770() { return static_cast<Memory770*>(TlsGetValue(DAT_010f3170)); }
struct Factory770;
struct FUN_00a29fb0_Class {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual const ClassKey770* getType() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void setFactoryType(const ClassKey770*) throw();
    virtual void slot1c() throw();
    virtual void slot20() throw();
    virtual void setFactory(Factory770*) throw();
    unsigned short memorySize, references;
    int unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48;
    FUN_00a29fb0_Class* FUN_00a29fb0(const char*,FUN_00a29fb0_Class*) throw();
};
typedef FUN_00a29fb0_Class Wrapper770;
struct Factory770 {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual const ClassKey770* getType() throw();
};
template<class T> struct Array770 {
    T* data;
    int size,capacity;
    Array770() throw():data(0),size(0),capacity(static_cast<int>(0x80000000u)) {}
    __forceinline ~Array770() throw() {
        if(!(capacity&0x80000000u)) {
            int count=capacity&0x3fffffff;
            GetMemory770()->FUN_008f6d90(data,count*sizeof(T),0x17);
        }
    }
};
// Fake match: explicit release lets the capacity survive as a separate loop-carried value.
struct FactoryArray770 {
    Factory770** data; int size,capacity;
    FactoryArray770() throw():data(0),size(0),capacity(static_cast<int>(0x80000000u)) {}
    __forceinline void Release(int retained) throw() {
        if(!(retained&0x80000000u)) {
            int count=retained&0x3fffffff;
            GetMemory770()->FUN_008f6d90(data,count*sizeof(Factory770*),0x17);
        }
    }
};
struct NullTerminatedFactoryList770 {
    Factory770* values[1];
    int FUN_009b1310() const throw();
};
extern NullTerminatedFactoryList770 DAT_00f793e0;
__declspec(noinline) static Factory770* FUN_009b1330(const FactoryArray770& factories,const ClassKey770* input) throw()
{
    const ClassKey770* key=input;
    for(int i=factories.size-1;i>=0;--i)
        if(!hkString_strCmp(factories.data[i]->getType(),key))
            return factories.data[i];
    return 0;
}
struct ClassMap770 {
    // Fake match: this annotation preserves the key copy when its dead parameter home is reused.
    __declspec(noalias) int FUN_009b0fb0(const ClassKey770*,Wrapper770**) throw();
    void* FUN_009b0f20(const ClassKey770*) throw();
    void FUN_009b0e40(unsigned char*,void*) throw();
    void FUN_009b0e60(const ClassKey770*,Wrapper770*) throw();
    Wrapper770* FUN_009b10f0(const ClassKey770*,int) throw();
    Wrapper770* Find(const ClassKey770* k) throw() { return FUN_009b10f0(k,0); }
};
struct RefAllocator770 {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual Wrapper770* create() throw();
};
extern RefAllocator770* DAT_010f3438;
struct Record770 {
    const ClassKey770* key;
    const ClassKey770* parent;
    const char** names;
};
struct ClassRegistry770 {
    int unk00,unk04,unk08,unk0c,unk10;
    ClassMap770 map;
    int FUN_009b1490(const ClassKey770*,const ClassKey770*,Array770<Record770*>*) throw();
    Wrapper770* FUN_009b1ae0(const ClassKey770*) throw();
};
Wrapper770* ClassRegistry770::FUN_009b1ae0(const ClassKey770* input) throw()
{
    const ClassKey770* key=input;
    // Fake match: explicitly share the initial output and later loop-index home.
    union { Wrapper770* result; int i; } scratch;
    {
        if(!map.FUN_009b0fb0(key,&scratch.result))
            return scratch.result;
    }
    unsigned char present;
    map.FUN_009b0e40(&present,map.FUN_009b0f20(FUN_0093e470()));
    if(!present) {
        Wrapper770* type=DAT_010f3438->create();
        if(type->memorySize) ++type->references;
        const ClassKey770* rootKey=FUN_0093e470();
        map.FUN_009b0e60(rootKey,type);
    }
    Wrapper770* wrapper=0;
    if(!hkString_strCmp(key,FUN_0093e470())) {
        // Fake match: reuse the dead parameter home for the map output.
        if(!map.FUN_009b0fb0(key,reinterpret_cast<Wrapper770**>(static_cast<void*>(&input))))
            wrapper=reinterpret_cast<Wrapper770*>(const_cast<ClassKey770*>(input));
    } else {
        Array770<Record770*> records;
        if(FUN_009b1490(key,FUN_0093e470(),&records)==1)
            return 0;
        FactoryArray770 factories;
        factories.data=DAT_00f793e0.values;
        factories.size=DAT_00f793e0.FUN_009b1310();
        int retained=factories.size|static_cast<int>(0x80000000u);
        factories.capacity=retained;
        for(scratch.i=records.size-1;scratch.i>=0;--scratch.i) {
            Wrapper770* parent=map.Find(records.data[scratch.i]->parent);
            wrapper=map.Find(records.data[scratch.i]->key);
            if(!wrapper) {
                Factory770* factory=FUN_009b1330(factories,records.data[scratch.i]->key);
                Wrapper770* created=static_cast<Wrapper770*>(GetMemory770()->FUN_008f6d30(0x4c,0x15));
                created->memorySize=0x4c;
                created=created->FUN_00a29fb0(*records.data[scratch.i]->names,parent);
                created->setFactoryType(factory->getType());
                created->setFactory(factory);
                const ClassKey770* createdKey=created->getType();
                map.FUN_009b0e60(createdKey,created);
                // Fake match: restore the capacity web at the same loop point as the target.
                retained=*(volatile int*)&factories.capacity;
                wrapper=created;
                // Fake match: retain the original loop-index reload after object creation.
                scratch.i=*(volatile int*)&scratch.i;
            }
            if(SameKey770(records.data[scratch.i]->key,key)) {
                factories.Release(retained);
                return wrapper;
            }
        }
        factories.Release(retained);
    }
    return wrapper;
}

// @f3 0x009b3800 (community match, verified in this file)
#include <windows.h>
extern void* DAT_010f3364;
extern unsigned DAT_010f3170;
extern int DAT_00e7e8b4;
extern int DAT_00e7e934;
extern const char str_00e7e8d0[];
namespace f3m_009b3800 {
namespace f3m_009b3800 {
struct DiagnosticWriter { void* vtbl; int unk04; void* p; void FUN_00923070(void*,int); void FUN_00943710(const char*); void FUN_00943a60(); };
struct Target { void FUN_009ee590(const void*,unsigned,unsigned); };
struct Writer { void FUN_009ee590(const void*,int,int); };
struct AssertMgr { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(int,unsigned,char*,const char*,int); };
struct Heap { virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void* AllocateStack(int);virtual void FreeStack(void*); int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; char* current; int unk24; char* marker; char* limit; void FUN_008f6d90(void*,int,int); };
struct Pair { unsigned lo,hi; };
}
namespace f3m_009b3800 {

struct Item {
    int f00; int f04; int f08;
    unsigned char type; unsigned char f0d; unsigned char f0e; unsigned char f0f;
    unsigned short f10; unsigned short f12;
    int getName() const { return f00; }
    int FUN_0093d900();
    int FUN_0093d8c0();
    void* FUN_0093d8b0();
    void* FUN_0093d8a0();
    int FUN_0093db00(const void* a);
};
struct StreamPosition {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int v1c(int a, int b);
    virtual int v20();
};
struct ExitObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int v1c(int a);
};
struct HObj {
    int FUN_009b2320(int a, void* b);
    int FUN_009b2360(int a, void* b);
    int FUN_009b2470(int a, void* b, void* c);
};
struct Inner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(int a, int b);
};
struct InnerHolder { int f00; int f04; int f08; int f0c; Inner* f10; };
struct Chain {
    Chain* FUN_00943710(const void* s, void* a);
    Chain* FUN_00943710();
    void FUN_00943a60();
};
struct StrBuf {
    char* data; int size; int capacity;
    void FUN_00923070(void* a, int n);
};
struct StreamObj {
    StreamPosition* FUN_009ee790();
    void FUN_009ee8d0(int a);
    void FUN_009ee890(int a);
    void FUN_009ee540(int a);
    void FUN_009ee590(const void* data, unsigned int size, unsigned int count);
    void FUN_009ee740(const void* data, unsigned int size);
    StreamObj* FUN_009b06c0(int v);
    void* FUN_00d46d40();
};
struct DescriptorList {
    int unk00; int unk04; int unk08;
    int FUN_009b0630();
    Item* FUN_009b0650(int i);
    int FUN_009b0760();
};
struct Host {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(Item* a, Item* b);
    int f04; int f08;
    unsigned char f0c; unsigned char f0d; unsigned char f0e; unsigned char f0f;
    int f10;
    StreamObj* FUN_009b06c0(int v);
    void FUN_009b34f0(StreamObj* a, Item* it);
    int hkObjectCopier_saveBody(StreamObj* p0, StreamObj* p1, StreamObj* p2, DescriptorList* p3);
};
__declspec(noinline) int __cdecl FUN_009b4900(int a, int b) { int d = a - b; return b + (d & (d >> 31)); }
int __cdecl FUN_009b32d0(DescriptorList* a, Item* it, int i, int e);

static __declspec(noinline) int FUN_009b31e0(Item* p) {
    if (p->FUN_0093d8c0()) return p->FUN_0093d8c0();
    return 1;
}



struct DiagnosticWriterOrig {
    void* vtbl;
    int unk04;
    void* p;
    void FUN_00923070(void* buf, int size);
    DiagnosticWriterOrig* FUN_00943710(const void* msg);
    void FUN_00943a60();
};
static DiagnosticWriterOrig& wch(DiagnosticWriter& w) { return *(DiagnosticWriterOrig*)&w; }

static __declspec(noinline) void FUN_009b3200(Target* obj, unsigned int type, unsigned int size, unsigned int count, void* data) {
    switch (type) {
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        count = count * (size / 4);
        size = 4;
        goto output;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 32:
    output:
        obj->FUN_009ee590(data, size, count);
        return;
    default: {
        unsigned int storage[128];
        DiagnosticWriter w;
        w.FUN_00923070(storage, sizeof(storage));
        w.FUN_00943710((const char*)str_00e7e8d0);
        ((AssertMgr*)DAT_010f3364)->v3(3, 0x747e1e03, (char*)storage, (const char*)&DAT_00e7e8b4, 0xfb);
        w.FUN_00943a60();
        return;
    }
    }
}

static __declspec(noinline) void FUN_009b3760(int count,const unsigned* data,Writer* writer,int elemSize) {
 if(elemSize==4) { writer->FUN_009ee590(data,elemSize,count); return; }
 Heap* heap=(Heap*)::TlsGetValue(DAT_010f3170);
 int bytes=(count*8+16)&~15;
 Pair* output=(Pair*)heap->current;
 if(heap->current+bytes<=heap->limit) heap->current+=bytes; else output=(Pair*)heap->AllocateStack(bytes);
 for(int i=0;i<count;++i){output[i].lo=data[i];output[i].hi=0;}
 writer->FUN_009ee590(output,elemSize,count);
 heap=(Heap*)::TlsGetValue(DAT_010f3170);heap->current=(char*)output;
 if((char*)output==heap->marker) heap->FreeStack(output);
}

template<class T> static __forceinline const T* AddOffset(const T* pointer, unsigned count) { const char* bytes = (const char*)pointer; return (const T*)(bytes + count); }
struct PointerValue { int valid; int pointer; int object; };

struct LookupResult { int value; };
struct ValueArray { int* data; int size; int capacity; };
// Iterates descriptor items, compares matching items, dispatches by type, and writes values through the supplied stream.

// pdb: hkObjectCopier::saveBody | hkObjectCopier.obj | fnv360_0822_retail, call_gap + bridge(call_gap|ustr) + skyrim(call_gap), high
int Host::hkObjectCopier_saveBody(StreamObj* apSourceStream, StreamObj* apLookupStream, StreamObj* apOutputStream, DescriptorList* apDescriptorList)
{
    int base; int index;
    StreamPosition* posInterface;
    
    
    posInterface = apOutputStream->FUN_009ee790();
    base = posInterface->v20();
    for (index = 0; index < apDescriptorList->FUN_009b0630(); index++) {
        Item* pItem = apDescriptorList->FUN_009b0650(index);
        posInterface->v1c((int)pItem->f12 + base, 0);
        if (pItem->f10 & 0x400) {
            int fl = this->f10;
            if (fl & 2) {
                this->FUN_009b34f0(apOutputStream, pItem);
                continue;
            }
            if (fl & 1) {
                FUN_009b32d0(apDescriptorList, pItem, index, (int)posInterface);
                continue;
            }
        }
        {
            Item* nb = (Item*)apLookupStream->FUN_009b06c0(pItem->getName());
            if (nb && (nb->type == pItem->type && (nb->f0d == pItem->f0d || nb->type == 0x18))) {
            const char* iSourceOffset = (const char*)AddOffset(apSourceStream,nb->f12);
            switch (pItem->type - 1) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
            case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
            case 16: case 17: {
                int cur = FUN_009b31e0(nb);
                int pObj = FUN_009b31e0(pItem);
                int v = pItem->FUN_0093d900();
                FUN_009b3200((Target*)apOutputStream, pItem->type, v / pObj, FUN_009b4900(cur,pObj), (void*)iSourceOffset);
                break;
            }
            case 29: {
                int cur = FUN_009b31e0(nb);
                int pObj = FUN_009b31e0(pItem);
                int n = FUN_009b4900(cur, pObj);
                FUN_009b3760(n, (const unsigned int*)iSourceOffset, (Writer*)apOutputStream, this->f0c);
                break;
            }
            case 23: {
                int denominator = FUN_009b31e0(nb);
                int u = FUN_009b31e0(pItem);
                int i = FUN_009b4900(denominator, u);
                void* h1 = nb->FUN_0093d8b0();
                void* h2 = pItem->FUN_0093d8b0();
                if (!h1 || !h2) break;
                int iStep;
                int v = nb->FUN_0093d900();
                iStep = v / denominator;
                if (0 >= i) break;
                int n = i;
                do {
                    int r86 = nb->FUN_0093db00(iSourceOffset);
                    int local20 = 0;
                    LookupResult lookup;
                    LookupResult* pLookupResult = &lookup;
                    int iResult = ((HObj*)h1)->FUN_009b2320(r86, pLookupResult);
                    if (iResult == 0) {
                        ((HObj*)h2)->FUN_009b2360(pLookupResult->value, &local20);
                    }
                    switch (iStep) {
                    case 1: apOutputStream->FUN_009ee540(local20); break;
                    case 2: apOutputStream->FUN_009ee890(local20); break;
                    case 4: apOutputStream->FUN_009ee8d0(local20); break;
                    }
                    iSourceOffset += iStep;
                    n--;
                } while (n != 0);
                break;
            }
            case 18: break;
            case 19: case 20: case 28: {
                int count;
                int rawCount = FUN_009b31e0(pItem);
                unsigned __int64 zero = 0;
                if (rawCount <= 0) break;
                count = rawCount;
                do {
                    apOutputStream->FUN_009ee740(&zero, (int)this->f0c);
                    count--;
                } while (count ? true : false);
                break;
            }
            case 21: case 22: case 25: case 26: {
                StreamObj* e2 = apOutputStream;
                int ptrValue = (int)iSourceOffset;
                if (pItem->type == 0x1b) {
                    unsigned __int64 leadingZero = 0;
                    e2->FUN_009ee590(&leadingZero, (int)this->f0c, 1);
                    ptrValue = ((PointerValue*)ptrValue)->object;
                } else if (!pItem->f0d) {
                    ptrValue = 0;
                } else {
                    ptrValue = ((PointerValue*)ptrValue)->pointer;
                }
                {
                    unsigned __int64 trailingZero = 0;
                    e2->FUN_009ee590(&trailingZero, (int)this->f0c, 1);
                    e2->FUN_009ee8d0(ptrValue);
                    if (pItem->type == 0x16) {
                        ptrValue |= 0xc0000000;
                        e2->FUN_009ee8d0(ptrValue);
                    }
                }
                break;
            }
            case 24: {
                void* h1 = nb->FUN_0093d8a0();
                void* h2 = pItem->FUN_0093d8a0();
                if (h1 == 0) break;
                if (!h2) break;
                int iRemaining = FUN_009b4900(FUN_009b31e0(nb), FUN_009b31e0(pItem));
                int k;
                k = 0;
                if (iRemaining <= 0) break;
                do {
                    int v = ((DescriptorList*)h1)->FUN_009b0760();
                    const char* iAccumulated = (const char*)iSourceOffset + v * k;
                    this->hkObjectCopier_saveBody((StreamObj*)iAccumulated, (StreamObj*)h1, apOutputStream, (DescriptorList*)h2);
                    k++;
                } while (k < iRemaining);
                break;
            }
            case 27: {
                unsigned __int64 zeros[2] = {0,0};
                int rawCount = FUN_009b4900(FUN_009b31e0(nb), FUN_009b31e0(pItem));
                if (0 >= rawCount) break;
                int iRemaining = rawCount;
                do {
                    apOutputStream->FUN_009ee590(zeros, (int)this->f0c, 2);
                    iRemaining--;
                } while (iRemaining != 0);
                break;
            }
            case 30: {
                int denominator = FUN_009b31e0(nb);
                int u = FUN_009b31e0(pItem);
                int i = FUN_009b4900(denominator, u);
                void* flagh1 = nb->FUN_0093d8b0();
                void* flagh2 = pItem->FUN_0093d8b0();
                int v = nb->FUN_0093d900();
                int flagq = v / denominator;
                const char* x = iSourceOffset;
                if (i <= 0) break;
                int remaining = i;
                do {
                    int r86 = nb->FUN_0093db00(x);
                    
                    ValueArray values;
                    values.data = 0; values.size = 0; values.capacity = 0x80000000;
                    int acc = 0;
                    ((HObj*)flagh1)->FUN_009b2470(r86, &values, &acc);
                    int iOrValue = 0;
                    int iValueIndex = 0;
                    while (iValueIndex < values.size) {
                        
                        int out40;
                        int* outputValue = &out40;
                        int s = ((HObj*)flagh2)->FUN_009b2360(values.data[iValueIndex], outputValue);
                        if (s == 0) iOrValue |= *outputValue;
                        else acc |= *outputValue;
                        iValueIndex++;
                    }
                    if (acc ? true : false) {
                        int pElementData = 0;
                        ((HObj*)flagh2)->FUN_009b2470(acc, &values, &pElementData);
                        iOrValue |= pElementData;
                    }
                    switch (flagq) {
                    case 1: apOutputStream->FUN_009ee540(iOrValue); break;
                    case 2: apOutputStream->FUN_009ee890(iOrValue); break;
                    case 4: apOutputStream->FUN_009ee8d0(iOrValue); break;
                    }
                    x += flagq;
                    {
                        if ((values.capacity & 0x80000000) == 0) {
                            int count=values.capacity & 0x3fffffff;
                            Heap* heap=(Heap*)::TlsGetValue(DAT_010f3170);
                            heap->FUN_008f6d90(values.data,count*4,0x17);
                        }
                    }
                    remaining--;
                } while (!!remaining);
                break;
            }
            default: {
                
                                unsigned int r[128];
                DiagnosticWriter bad;
                bad.FUN_00923070(r, 0x200);
                bad.FUN_00943710((const char*)&DAT_00e7e934);
                int iResult = ((AssertMgr*)DAT_010f3364)->v3(3, 0x641e3e03, (char*)r, (const char*)&DAT_00e7e8b4, 0x210);
                
                bad.FUN_00943a60();
                break;
            }
            }
            } else {
                                FUN_009b32d0(apDescriptorList, pItem, index, (int)posInterface);
            }
        }
    }
    {
        StreamPosition* pStream = apOutputStream->FUN_009ee790();
        pStream->v1c(apDescriptorList->FUN_009b0760() + base, 0);
    }
    return base;
}

}
}   // namespace f3m_009b3800

// @f3 0x009b3170 (community match, verified in this file)
namespace f3m_009b3170 {
// 0x009b3170 (25 B) - range check: value >= lo && value < hi (signed ints)
// pdb: `anonymous namespace'::inRange | hkObjectCopier.obj | fnv360_0822_retail, objrun_open, low
// pdb params: num, lo, hi
bool FUN_009b3170(int value, int lo, int hi)
{
    return value >= lo && value < hi;
}
}   // namespace f3m_009b3170

// @f3 0x009b3140 (community match, verified in this file)
namespace f3m_009b3140 {

extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct hkThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls);
};

class hkReferencedObject
{
    public:
        virtual ~hkReferencedObject();

        unsigned short m_memSizeAndFlags;
        short m_referenceCount;
};

class StringPool : public hkReferencedObject
{
    public:
        void FUN_009b30a0();
        StringPool* FUN_009b3140(unsigned int flags);
};

StringPool* StringPool::FUN_009b3140(unsigned int flags)
{
    FUN_009b30a0();
    if (flags & 1)
    {
        hkThreadMemory* mem = (hkThreadMemory*)DAT_00d9b080(DAT_010f3170);
        mem->FUN_008f6d90(this, m_memSizeAndFlags, 0x5);
    }
    return this;
}

}
